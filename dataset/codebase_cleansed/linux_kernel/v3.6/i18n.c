char *msg_get(enum msg_index_t index)
{
char *ch;
ch = speakup_msgs[index];
return ch;
}
static char *next_specifier(char *input)
{
int found = 0;
char *next_percent = input;
while ((next_percent != NULL) && !found) {
next_percent = strchr(next_percent, '%');
if (next_percent != NULL) {
while ((next_percent[0] == '%')
&& (next_percent[1] == '%'))
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
static int compare_specifiers(char **input1, char **input2)
{
int same = 0;
char *end1 = find_specifier_end(*input1);
char *end2 = find_specifier_end(*input2);
size_t length1 = end1 - *input1;
size_t length2 = end2 - *input2;
if ((length1 == length2) && !memcmp(*input1, *input2, length1))
same = 1;
*input1 = end1;
*input2 = end2;
return same;
}
static int fmt_validate(char *template, char *user)
{
int valid = 1;
int still_comparing = 1;
char *template_ptr = template;
char *user_ptr = user;
while (still_comparing && valid) {
template_ptr = next_specifier(template_ptr);
user_ptr = next_specifier(user_ptr);
if (template_ptr && user_ptr) {
valid = compare_specifiers(&template_ptr, &user_ptr);
} else {
still_comparing = 0;
if (template_ptr || user_ptr)
valid = 0;
}
}
return valid;
}
ssize_t msg_set(enum msg_index_t index, char *text, size_t length)
{
int rc = 0;
char *newstr = NULL;
unsigned long flags;
if ((index >= MSG_FIRST_INDEX) && (index < MSG_LAST_INDEX)) {
newstr = kmalloc(length + 1, GFP_KERNEL);
if (newstr) {
memcpy(newstr, text, length);
newstr[length] = '\0';
if ((index >= MSG_FORMATTED_START
&& index <= MSG_FORMATTED_END)
&& !fmt_validate(speakup_default_msgs[index],
newstr)) {
return -EINVAL;
}
spk_lock(flags);
if (speakup_msgs[index] != speakup_default_msgs[index])
kfree(speakup_msgs[index]);
speakup_msgs[index] = newstr;
spk_unlock(flags);
} else {
rc = -ENOMEM;
}
} else {
rc = -EINVAL;
}
return rc;
}
struct msg_group_t *find_msg_group(const char *group_name)
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
void reset_msg_group(struct msg_group_t *group)
{
unsigned long flags;
enum msg_index_t i;
spk_lock(flags);
for (i = group->start; i <= group->end; i++) {
if (speakup_msgs[i] != speakup_default_msgs[i])
kfree(speakup_msgs[i]);
speakup_msgs[i] = speakup_default_msgs[i];
}
spk_unlock(flags);
}
void initialize_msgs(void)
{
memcpy(speakup_msgs, speakup_default_msgs,
sizeof(speakup_default_msgs));
}
void free_user_msgs(void)
{
enum msg_index_t index;
unsigned long flags;
spk_lock(flags);
for (index = MSG_FIRST_INDEX; index < MSG_LAST_INDEX; index++) {
if (speakup_msgs[index] != speakup_default_msgs[index]) {
kfree(speakup_msgs[index]);
speakup_msgs[index] = speakup_default_msgs[index];
}
}
spk_unlock(flags);
}
