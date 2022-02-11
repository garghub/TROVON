static T_1
F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
struct V_6 V_7 ;
struct V_8 * V_9 , * V_10 ;
T_1 V_11 ;
V_11 = F_2 ( V_2 , & V_7 ) ;
if ( F_3 ( V_11 ) ||
( V_7 . V_12 != V_13 ) )
return V_14 ;
F_4 (info, &mem_device->res_list, list) {
if ( ( V_9 -> V_15 == V_7 . V_9 . V_16 . V_15 ) &&
( V_9 -> V_17 == V_7 . V_9 . V_16 . V_17 ) &&
( V_9 -> V_18 + V_9 -> V_19 == V_7 . V_20 ) ) {
V_9 -> V_19 += V_7 . V_21 ;
return V_14 ;
}
}
V_10 = F_5 ( sizeof( struct V_8 ) , V_22 ) ;
if ( ! V_10 )
return V_23 ;
F_6 ( & V_10 -> V_24 ) ;
V_10 -> V_15 = V_7 . V_9 . V_16 . V_15 ;
V_10 -> V_17 = V_7 . V_9 . V_16 . V_17 ;
V_10 -> V_18 = V_7 . V_20 ;
V_10 -> V_19 = V_7 . V_21 ;
F_7 ( & V_10 -> V_24 , & V_5 -> V_25 ) ;
return V_14 ;
}
static int
F_8 ( struct V_4 * V_5 )
{
T_1 V_11 ;
struct V_8 * V_9 , * V_26 ;
if ( ! F_9 ( & V_5 -> V_25 ) )
return 0 ;
V_11 = F_10 ( V_5 -> V_27 -> V_28 , V_29 ,
F_1 , V_5 ) ;
if ( F_3 ( V_11 ) ) {
F_11 (info, n, &mem_device->res_list, list)
F_12 ( V_9 ) ;
F_6 ( & V_5 -> V_25 ) ;
return - V_30 ;
}
return 0 ;
}
static int
F_13 ( T_2 V_28 ,
struct V_4 * * V_5 )
{
T_1 V_11 ;
T_2 V_31 ;
struct V_32 * V_27 = NULL ;
struct V_32 * V_33 = NULL ;
int V_34 ;
if ( ! F_14 ( V_28 , & V_27 ) && V_27 )
goto V_35;
V_11 = F_15 ( V_28 , & V_31 ) ;
if ( F_3 ( V_11 ) ) {
F_16 ( ( V_36 , V_11 , L_1 ) ) ;
return - V_30 ;
}
V_34 = F_14 ( V_31 , & V_33 ) ;
if ( V_34 ) {
F_17 (KERN_WARNING PREFIX L_2 ) ;
return - V_30 ;
}
V_34 = F_18 ( & V_27 , V_33 , V_28 , V_37 ) ;
if ( V_34 ) {
F_17 (KERN_WARNING PREFIX L_3 ) ;
return - V_30 ;
}
V_35:
* V_5 = F_19 ( V_27 ) ;
if ( ! ( * V_5 ) ) {
F_17 ( V_38 L_4 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
unsigned long long V_40 ;
if ( F_3 ( F_21 ( V_5 -> V_27 -> V_28 , L_5 ,
NULL , & V_40 ) ) )
return - V_39 ;
if ( ! ( ( V_40 & V_41 )
&& ( V_40 & V_42 )
&& ( V_40 & V_43 ) ) )
return - V_39 ;
return 0 ;
}
static int F_22 ( struct V_4 * V_5 )
{
int V_34 , V_44 = 0 ;
struct V_8 * V_9 ;
int V_45 ;
V_34 = F_8 ( V_5 ) ;
if ( V_34 ) {
F_17 (KERN_ERR PREFIX L_6 ) ;
V_5 -> V_46 = V_47 ;
return V_34 ;
}
V_45 = F_23 ( V_5 -> V_27 -> V_28 ) ;
F_4 (info, &mem_device->res_list, list) {
if ( V_9 -> V_48 ) {
V_44 ++ ;
continue;
}
if ( ! V_9 -> V_19 )
continue;
if ( V_45 < 0 )
V_45 = F_24 ( V_9 -> V_18 ) ;
V_34 = F_25 ( V_45 , V_9 -> V_18 , V_9 -> V_19 ) ;
if ( V_34 )
continue;
V_9 -> V_48 = 1 ;
V_44 ++ ;
}
if ( ! V_44 ) {
F_17 (KERN_ERR PREFIX L_7 ) ;
V_5 -> V_46 = V_47 ;
return - V_30 ;
}
return 0 ;
}
static int F_26 ( struct V_4 * V_5 )
{
T_1 V_11 ;
struct V_49 V_50 ;
union V_51 V_52 ;
unsigned long long V_40 ;
V_50 . V_53 = 1 ;
V_50 . V_54 = & V_52 ;
V_52 . type = V_55 ;
V_52 . integer . V_56 = 1 ;
V_11 = F_27 ( V_5 -> V_27 -> V_28 ,
L_8 , & V_50 , NULL ) ;
if ( F_3 ( V_11 ) ) {
F_16 ( ( V_36 , V_11 , L_9 ) ) ;
return - V_39 ;
}
V_11 = F_21 ( V_5 -> V_27 -> V_28 , L_5 ,
NULL , & V_40 ) ;
if ( F_3 ( V_11 ) )
return - V_39 ;
if ( V_40 & V_42 )
return - V_30 ;
return 0 ;
}
static int F_28 ( struct V_4 * V_5 )
{
int V_34 ;
struct V_8 * V_9 , * V_26 ;
F_11 (info, n, &mem_device->res_list, list) {
if ( V_9 -> V_48 ) {
V_34 = F_29 ( V_9 -> V_18 , V_9 -> V_19 ) ;
if ( V_34 )
return V_34 ;
}
F_12 ( V_9 ) ;
}
V_34 = F_26 ( V_5 ) ;
if ( V_34 ) {
V_5 -> V_46 = V_47 ;
return V_34 ;
}
V_5 -> V_46 = V_57 ;
return V_34 ;
}
static void F_30 ( T_2 V_28 , T_3 V_58 , void * V_59 )
{
struct V_4 * V_5 ;
struct V_32 * V_27 ;
switch ( V_58 ) {
case V_60 :
F_31 ( ( V_61 ,
L_10 ) ) ;
case V_62 :
if ( V_58 == V_62 )
F_31 ( ( V_61 ,
L_11 ) ) ;
if ( F_13 ( V_28 , & V_5 ) ) {
F_17 (KERN_ERR PREFIX L_12 ) ;
return;
}
if ( ! F_20 ( V_5 ) ) {
if ( F_22 ( V_5 ) )
F_17 (KERN_ERR PREFIX
L_13 ) ;
}
break;
case V_63 :
F_31 ( ( V_61 ,
L_14 ) ) ;
if ( F_14 ( V_28 , & V_27 ) ) {
F_17 (KERN_ERR PREFIX L_15 ) ;
break;
}
V_5 = F_19 ( V_27 ) ;
if ( ! V_5 ) {
F_17 (KERN_ERR PREFIX L_16 ) ;
break;
}
if ( F_28 ( V_5 ) )
F_17 (KERN_ERR PREFIX
L_17 ) ;
break;
default:
F_31 ( ( V_61 ,
L_18 , V_58 ) ) ;
break;
}
return;
}
static int F_32 ( struct V_32 * V_27 )
{
int V_34 ;
struct V_4 * V_5 = NULL ;
if ( ! V_27 )
return - V_30 ;
V_5 = F_5 ( sizeof( struct V_4 ) , V_22 ) ;
if ( ! V_5 )
return - V_64 ;
F_6 ( & V_5 -> V_25 ) ;
V_5 -> V_27 = V_27 ;
sprintf ( F_33 ( V_27 ) , L_19 , V_65 ) ;
sprintf ( F_34 ( V_27 ) , L_19 , V_66 ) ;
V_27 -> V_67 = V_5 ;
V_34 = F_8 ( V_5 ) ;
if ( V_34 ) {
F_12 ( V_5 ) ;
return V_34 ;
}
V_5 -> V_46 = V_68 ;
F_17 ( V_69 L_20 , F_33 ( V_27 ) ) ;
if ( ! V_70 )
return 0 ;
if ( ! F_20 ( V_5 ) ) {
V_34 = F_22 ( V_5 ) ;
if ( V_34 )
F_17 (KERN_ERR PREFIX
L_21 ) ;
}
return V_34 ;
}
static int F_35 ( struct V_32 * V_27 , int type )
{
struct V_4 * V_5 = NULL ;
if ( ! V_27 || ! F_19 ( V_27 ) )
return - V_30 ;
V_5 = F_19 ( V_27 ) ;
F_12 ( V_5 ) ;
return 0 ;
}
static T_1 F_36 ( T_2 V_28 )
{
char * V_71 ;
T_1 V_11 ;
struct V_72 * V_9 ;
V_11 = F_37 ( V_28 , & V_9 ) ;
if ( F_3 ( V_11 ) )
return V_11 ;
if ( ! ( V_9 -> V_73 & V_74 ) ) {
F_12 ( V_9 ) ;
return V_23 ;
}
V_71 = V_9 -> V_71 . string ;
if ( ( V_71 == NULL ) ||
( strcmp ( V_71 , V_75 ) ) )
V_11 = V_23 ;
F_12 ( V_9 ) ;
return V_11 ;
}
static T_1
F_38 ( T_2 V_28 ,
T_3 V_76 , void * V_77 , void * * V_78 )
{
T_1 V_11 ;
V_11 = F_36 ( V_28 ) ;
if ( F_3 ( V_11 ) )
return V_14 ;
V_11 = F_39 ( V_28 , V_79 ,
F_30 , NULL ) ;
return V_14 ;
}
static T_1
F_40 ( T_2 V_28 ,
T_3 V_76 , void * V_77 , void * * V_78 )
{
T_1 V_11 ;
V_11 = F_36 ( V_28 ) ;
if ( F_3 ( V_11 ) )
return V_14 ;
V_11 = F_41 ( V_28 ,
V_79 ,
F_30 ) ;
return V_14 ;
}
static int T_4 F_42 ( void )
{
int V_34 ;
T_1 V_11 ;
V_34 = F_43 ( & V_80 ) ;
if ( V_34 < 0 )
return - V_39 ;
V_11 = F_44 ( V_81 , V_82 ,
V_83 ,
F_38 , NULL ,
NULL , NULL ) ;
if ( F_3 ( V_11 ) ) {
F_16 ( ( V_36 , V_11 , L_22 ) ) ;
F_45 ( & V_80 ) ;
return - V_39 ;
}
V_70 = 1 ;
return 0 ;
}
static void T_5 F_46 ( void )
{
T_1 V_11 ;
V_11 = F_44 ( V_81 , V_82 ,
V_83 ,
F_40 , NULL ,
NULL , NULL ) ;
if ( F_3 ( V_11 ) )
F_16 ( ( V_36 , V_11 , L_22 ) ) ;
F_45 ( & V_80 ) ;
return;
}
