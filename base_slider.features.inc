<?php
/**
 * @file
 * base_slider.features.inc
 */

/**
 * Implements hook_views_api().
 */
function base_slider_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function base_slider_image_default_styles() {
  $styles = array();

  // Exported image style: front_feature_image.
  $styles['front_feature_image'] = array(
    'name' => 'front_feature_image',
    'effects' => array(
      8 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '780',
          'height' => '400',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function base_slider_node_info() {
  $items = array(
    'front_feature' => array(
      'name' => t('Front Feature'),
      'base' => 'node_content',
      'description' => t('This is content is for the front slider.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
