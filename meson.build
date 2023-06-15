project('leaky', 'c',
  version : '0.1',
  default_options : [
    'warning_level=3',
    'b_sanitize=address,undefined'])

test(
  'leaky-test',
  executable(
    'leaky',
    'leaky.c',
    dependencies: dependency('criterion')))
