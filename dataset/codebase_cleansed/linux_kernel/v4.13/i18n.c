char *spk_msg_get(enum msg_index_t index)
{
return speakup_msgs[index];
}
static char *next_specifier(char *input)
{
int found = 0;
char *next_percent = input;
while (next_percent && !found) {
next_percent = strchr(next_percent, '%');
if (next_percent) {
while (next_percent[0] == '%' &&
next_percent[1] == '%')
next_percent += 2;
if (*next_percent == '%')
found = 1;
else if (*next_percent == '\0')
next_percent = NULL;
}
}
return next_percent;
}
static char *skip_flags(char *input)
{
while ((*input != '\0') && strchr(" 0+-#", *input))
input++;
return input;
}
static char *skip_width(char *input)
{
while (isdigit(*input))
input++;
if (*input == '.') {
input++;
while (isdigit(*input))
input++;
}
return input;
}
static char *skip_conversion(char *input)
{
if ((input[0] == 'l') && (input[1] == 'd'))
input += 2;
else if ((*input != '\0') && strchr("cdsx", *input))
input++;
return input;
}
static char *find_specifier_end(char *input)
{
input++;
input = skip_flags(input);
input = skip_width(input);
input = skip_conversion(input);
return input;
}
static bool compare_specifiers(char **input1, char **input2)
{
bool same = false;
char *end1 = find_specifier_end(*input1);
char *end2 = find_specifier_end(*input2);
size_t length1 = end1 - *input1;
size_t length2 = end2 - *input2;
if ((length1 == length2) && !memcmp(*input1, *input2, length1))
same = true;
*input1 = end1;
*input2 = end2;
return same;
}
static bool fmt_validate(char *template, char *user)
{
bool valid = true;
bool still_comparing = true;
char *template_ptr = template;
char *user_ptr = user;
while (still_comparing && valid) {
template_ptr = next_specifier(template_ptr);
user_ptr = next_specifier(user_ptr);
if (template_ptr && user_ptr) {
valid = compare_specifiers(&template_ptr, &user_ptr);
} else {
still_comparing = false;
if (template_ptr || user_ptr)
valid = false;
}
}
return valid;
}
ssize_t spk_msg_set(enum msg_index_t index, char *text, size_t length)
{
char *newstr = NULL;
unsigned long flags;
if ((index < MSG_FIRST_INDEX) || (index >= MSG_LAST_INDEX))
return -EINVAL;
newstr = kmalloc(length + 1, GFP_KERNEL);
if (!newstr)
return -ENOMEM;
memcpy(newstr, text, length);
newstr[length] = '\0';
if (index >= MSG_FORMATTED_START &&
index <= MSG_FORMATTED_END &&
!fmt_validate(speakup_default_msgs[index], newstr)) {
kfree(newstr);
return -EINVAL;
}
spin_lock_irqsave(&speakup_info.spinlock, flags);
if (speakup_msgs[index] != speakup_default_msgs[index])
kfree(speakup_msgs[index]);
speakup_msgs[index] = newstr;
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
return 0;
}
struct msg_group_t *spk_find_msg_group(const char *group_name)
{
struct msg_group_t *group = NULL;
int i;
for (i = 0; i < num_groups; i++) {
if (!strcmp(all_groups[i].name, group_name)) {
group = &all_groups[i];
break;
}
}
return group;
}
void spk_reset_msg_group(struct msg_group_t *group)
{
unsigned long flags;
enum msg_index_t i;
spin_lock_irqsave(&speakup_info.spinlock, flags);
for (i = group->start; i <= group->end; i++) {
if (speakup_msgs[i] != speakup_default_msgs[i])
kfree(speakup_msgs[i]);
speakup_msgs[i] = speakup_default_msgs[i];
}
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
}
void spk_initialize_msgs(void)
{
memcpy(speakup_msgs, speakup_default_msgs,
sizeof(speakup_default_msgs));
}
void spk_free_user_msgs(void)
{
enum msg_index_t index;
unsigned long flags;
spin_lock_irqsave(&speakup_info.spinlock, flags);
for (index = MSG_FIRST_INDEX; index < MSG_LAST_INDEX; index++) {
if (speakup_msgs[index] != speakup_default_msgs[index]) {
kfree(speakup_msgs[index]);
speakup_msgs[index] = speakup_default_msgs[index];
}
}
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
}
