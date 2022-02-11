static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! F_2 ( V_2 , V_5 ) )
return;
F_3 ( & V_6 ) ;
F_4 (smbdev, &psmouse_smbus_list, node) {
if ( V_4 -> V_7 )
continue;
if ( V_4 -> V_8 )
continue;
F_5 ( V_4 -> V_9 ,
L_1 ) ;
F_6 ( V_4 -> V_9 -> V_10 . V_11 ) ;
}
F_7 ( & V_6 ) ;
}
static void F_8 ( struct V_12 * V_8 )
{
struct V_3 * V_4 , * V_13 ;
F_3 ( & V_6 ) ;
F_9 (smbdev, tmp, &psmouse_smbus_list, node) {
if ( V_4 -> V_8 != V_8 )
continue;
F_10 ( V_8 -> V_14 . V_15 ) ;
V_8 -> V_14 . V_15 = NULL ;
if ( ! V_4 -> V_7 ) {
F_5 ( V_4 -> V_9 ,
L_2 ,
F_11 ( & V_4 -> V_8 -> V_14 ) ) ;
V_4 -> V_7 = true ;
F_6 ( V_4 -> V_9 -> V_10 . V_11 ) ;
} else {
F_12 ( & V_4 -> V_16 ) ;
F_10 ( V_4 ) ;
}
}
F_7 ( & V_6 ) ;
}
static int F_13 ( struct V_17 * V_18 ,
unsigned long V_19 , void * V_20 )
{
struct V_21 * V_14 = V_20 ;
switch ( V_19 ) {
case V_22 :
if ( V_14 -> type == & V_23 )
F_1 ( F_14 ( V_14 ) ) ;
break;
case V_24 :
if ( V_14 -> type == & V_25 )
F_8 ( F_15 ( V_14 ) ) ;
break;
}
return 0 ;
}
static T_1 F_16 ( struct V_9 * V_9 )
{
return V_26 ;
}
static int F_17 ( struct V_9 * V_9 )
{
F_18 ( V_9 ) ;
return 0 ;
}
static void F_19 ( struct V_27 * V_28 )
{
struct V_29 * V_30 =
F_20 ( V_28 , struct V_29 , V_28 ) ;
F_21 ( & V_30 -> V_8 -> V_14 , L_3 ) ;
F_22 ( V_30 -> V_8 ) ;
F_10 ( V_30 ) ;
}
static void F_23 ( struct V_12 * V_8 )
{
struct V_29 * V_30 ;
V_30 = F_24 ( sizeof( * V_30 ) , V_31 ) ;
if ( V_30 ) {
F_25 ( & V_30 -> V_28 , F_19 ) ;
V_30 -> V_8 = V_8 ;
F_26 ( & V_30 -> V_28 ) ;
}
}
static void F_27 ( struct V_9 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_32 ;
F_3 ( & V_6 ) ;
if ( V_4 -> V_7 ) {
F_12 ( & V_4 -> V_16 ) ;
F_10 ( V_4 ) ;
} else {
V_4 -> V_7 = true ;
F_5 ( V_4 -> V_9 ,
L_4 ,
F_11 ( & V_4 -> V_8 -> V_14 ) ) ;
F_23 ( V_4 -> V_8 ) ;
}
F_7 ( & V_6 ) ;
V_9 -> V_32 = NULL ;
}
static int F_28 ( struct V_21 * V_14 , void * V_20 )
{
struct V_3 * V_4 = V_20 ;
unsigned short V_33 [] = { V_4 -> V_34 . V_35 , V_36 } ;
struct V_1 * V_2 ;
V_2 = F_29 ( V_14 ) ;
if ( ! V_2 )
return 0 ;
if ( ! F_2 ( V_2 , V_5 ) )
return 0 ;
V_4 -> V_8 = F_30 ( V_2 , & V_4 -> V_34 ,
V_33 , NULL ) ;
if ( ! V_4 -> V_8 )
return 0 ;
return 1 ;
}
void F_31 ( struct V_9 * V_9 )
{
struct V_3 * V_4 , * V_13 ;
F_3 ( & V_6 ) ;
F_9 (smbdev, tmp, &psmouse_smbus_list, node) {
if ( V_9 == V_4 -> V_9 ) {
F_12 ( & V_4 -> V_16 ) ;
F_10 ( V_4 ) ;
}
}
F_7 ( & V_6 ) ;
}
int F_32 ( struct V_9 * V_9 ,
const struct V_37 * V_34 ,
const void * V_38 , T_2 V_39 ,
bool V_40 )
{
struct V_3 * V_4 ;
int error ;
V_4 = F_24 ( sizeof( * V_4 ) , V_31 ) ;
if ( ! V_4 )
return - V_41 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_34 = * V_34 ;
V_4 -> V_34 . V_15 = F_33 ( V_38 , V_39 , V_31 ) ;
if ( ! V_4 -> V_34 . V_15 ) {
F_10 ( V_4 ) ;
return - V_41 ;
}
V_9 -> V_32 = V_4 ;
V_9 -> V_42 = F_16 ;
V_9 -> V_43 = F_17 ;
V_9 -> V_44 = F_17 ;
V_9 -> V_45 = F_27 ;
V_9 -> V_46 = 0 ;
F_18 ( V_9 ) ;
F_3 ( & V_6 ) ;
F_34 ( & V_4 -> V_16 , & V_47 ) ;
F_7 ( & V_6 ) ;
error = F_35 ( V_4 , F_28 ) ;
if ( V_4 -> V_8 ) {
return 0 ;
}
F_10 ( V_4 -> V_34 . V_15 ) ;
V_4 -> V_34 . V_15 = NULL ;
if ( error < 0 || ! V_40 ) {
F_3 ( & V_6 ) ;
F_12 ( & V_4 -> V_16 ) ;
F_7 ( & V_6 ) ;
F_10 ( V_4 ) ;
}
return error < 0 ? error : - V_48 ;
}
int T_3 F_36 ( void )
{
int error ;
error = F_37 ( & V_49 , & V_50 ) ;
if ( error ) {
F_38 ( L_5 , error ) ;
return error ;
}
return 0 ;
}
void F_39 ( void )
{
F_40 ( & V_49 , & V_50 ) ;
F_41 () ;
}
