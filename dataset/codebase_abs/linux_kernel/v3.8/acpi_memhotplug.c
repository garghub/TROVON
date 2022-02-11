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
static void
F_8 ( struct V_4 * V_5 )
{
struct V_8 * V_9 , * V_26 ;
F_9 (info, n, &mem_device->res_list, list)
F_10 ( V_9 ) ;
F_6 ( & V_5 -> V_25 ) ;
}
static int
F_11 ( struct V_4 * V_5 )
{
T_1 V_11 ;
if ( ! F_12 ( & V_5 -> V_25 ) )
return 0 ;
V_11 = F_13 ( V_5 -> V_27 -> V_28 , V_29 ,
F_1 , V_5 ) ;
if ( F_3 ( V_11 ) ) {
F_8 ( V_5 ) ;
return - V_30 ;
}
return 0 ;
}
static int
F_14 ( T_2 V_28 ,
struct V_4 * * V_5 )
{
T_1 V_11 ;
T_2 V_31 ;
struct V_32 * V_27 = NULL ;
struct V_32 * V_33 = NULL ;
int V_34 ;
if ( ! F_15 ( V_28 , & V_27 ) && V_27 )
goto V_35;
V_11 = F_16 ( V_28 , & V_31 ) ;
if ( F_3 ( V_11 ) ) {
F_17 ( ( V_36 , V_11 , L_1 ) ) ;
return - V_30 ;
}
V_34 = F_15 ( V_31 , & V_33 ) ;
if ( V_34 ) {
F_18 ( V_31 , L_2 ) ;
return - V_30 ;
}
V_34 = F_19 ( & V_27 , V_33 , V_28 , V_37 ) ;
if ( V_34 ) {
F_18 ( V_28 , L_3 ) ;
return - V_30 ;
}
V_35:
* V_5 = F_20 ( V_27 ) ;
if ( ! ( * V_5 ) ) {
F_21 ( & V_27 -> V_38 , L_4 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_22 ( struct V_4 * V_5 )
{
unsigned long long V_40 ;
if ( F_3 ( F_23 ( V_5 -> V_27 -> V_28 , L_5 ,
NULL , & V_40 ) ) )
return - V_39 ;
if ( ! ( ( V_40 & V_41 )
&& ( V_40 & V_42 )
&& ( V_40 & V_43 ) ) )
return - V_39 ;
return 0 ;
}
static int F_24 ( struct V_4 * V_5 )
{
int V_34 , V_44 = 0 ;
struct V_8 * V_9 ;
int V_45 ;
V_45 = F_25 ( V_5 -> V_27 -> V_28 ) ;
F_4 (info, &mem_device->res_list, list) {
if ( V_9 -> V_46 ) {
V_44 ++ ;
continue;
}
if ( ! V_9 -> V_19 )
continue;
if ( V_45 < 0 )
V_45 = F_26 ( V_9 -> V_18 ) ;
V_34 = F_27 ( V_45 , V_9 -> V_18 , V_9 -> V_19 ) ;
if ( V_34 && V_34 != - V_47 ) {
V_9 -> V_48 = 1 ;
continue;
}
if ( ! V_34 )
V_9 -> V_46 = 1 ;
V_44 ++ ;
}
if ( ! V_44 ) {
F_21 ( & V_5 -> V_27 -> V_38 , L_6 ) ;
V_5 -> V_49 = V_50 ;
return - V_30 ;
}
return 0 ;
}
static int F_28 ( struct V_4 * V_5 )
{
int V_34 = 0 ;
struct V_8 * V_9 , * V_26 ;
F_9 (info, n, &mem_device->res_list, list) {
if ( V_9 -> V_48 )
continue;
if ( ! V_9 -> V_46 )
return - V_51 ;
V_34 = F_29 ( V_9 -> V_18 , V_9 -> V_19 ) ;
if ( V_34 )
return V_34 ;
F_30 ( & V_9 -> V_24 ) ;
F_10 ( V_9 ) ;
}
return V_34 ;
}
static void F_31 ( T_2 V_28 , T_3 V_52 , void * V_53 )
{
struct V_4 * V_5 ;
struct V_32 * V_27 ;
struct V_54 * V_55 = NULL ;
T_3 V_56 = V_57 ;
switch ( V_52 ) {
case V_58 :
F_32 ( ( V_59 ,
L_7 ) ) ;
case V_60 :
if ( V_52 == V_60 )
F_32 ( ( V_59 ,
L_8 ) ) ;
if ( F_14 ( V_28 , & V_5 ) ) {
F_33 ( V_28 , L_9 ) ;
break;
}
V_56 = V_61 ;
break;
case V_62 :
F_32 ( ( V_59 ,
L_10 ) ) ;
if ( F_15 ( V_28 , & V_27 ) ) {
F_33 ( V_28 , L_11 ) ;
break;
}
V_5 = F_20 ( V_27 ) ;
if ( ! V_5 ) {
F_33 ( V_28 , L_12 ) ;
break;
}
V_55 = F_34 ( sizeof( * V_55 ) , V_22 ) ;
if ( ! V_55 ) {
F_35 ( V_63 L_13 ) ;
break;
}
V_55 -> V_28 = V_28 ;
V_55 -> V_52 = V_62 ;
F_36 ( V_64 ,
( void * ) V_55 ) ;
return;
default:
F_32 ( ( V_59 ,
L_14 , V_52 ) ) ;
return;
}
( void ) F_37 ( V_28 , V_52 , V_56 , NULL ) ;
return;
}
static void F_38 ( struct V_4 * V_5 )
{
if ( ! V_5 )
return;
F_8 ( V_5 ) ;
F_10 ( V_5 ) ;
}
static int F_39 ( struct V_32 * V_27 )
{
int V_34 ;
struct V_4 * V_5 = NULL ;
if ( ! V_27 )
return - V_30 ;
V_5 = F_5 ( sizeof( struct V_4 ) , V_22 ) ;
if ( ! V_5 )
return - V_65 ;
F_6 ( & V_5 -> V_25 ) ;
V_5 -> V_27 = V_27 ;
sprintf ( F_40 ( V_27 ) , L_15 , V_66 ) ;
sprintf ( F_41 ( V_27 ) , L_15 , V_67 ) ;
V_27 -> V_68 = V_5 ;
V_34 = F_11 ( V_5 ) ;
if ( V_34 ) {
F_10 ( V_5 ) ;
return V_34 ;
}
V_5 -> V_49 = V_69 ;
F_42 ( L_16 , F_40 ( V_27 ) ) ;
if ( ! F_22 ( V_5 ) ) {
V_34 = F_24 ( V_5 ) ;
if ( V_34 ) {
F_21 ( & V_27 -> V_38 ,
L_17 ) ;
F_38 ( V_5 ) ;
}
}
return V_34 ;
}
static int F_43 ( struct V_32 * V_27 , int type )
{
struct V_4 * V_5 = NULL ;
int V_34 ;
if ( ! V_27 || ! F_20 ( V_27 ) )
return - V_30 ;
V_5 = F_20 ( V_27 ) ;
V_34 = F_28 ( V_5 ) ;
if ( V_34 )
return V_34 ;
F_38 ( V_5 ) ;
return 0 ;
}
static T_1 F_44 ( T_2 V_28 )
{
char * V_70 ;
T_1 V_11 ;
struct V_71 * V_9 ;
V_11 = F_45 ( V_28 , & V_9 ) ;
if ( F_3 ( V_11 ) )
return V_11 ;
if ( ! ( V_9 -> V_72 & V_73 ) ) {
F_10 ( V_9 ) ;
return V_23 ;
}
V_70 = V_9 -> V_70 . string ;
if ( ( V_70 == NULL ) ||
( strcmp ( V_70 , V_74 ) ) )
V_11 = V_23 ;
F_10 ( V_9 ) ;
return V_11 ;
}
static T_1
F_46 ( T_2 V_28 ,
T_3 V_75 , void * V_76 , void * * V_77 )
{
T_1 V_11 ;
V_11 = F_44 ( V_28 ) ;
if ( F_3 ( V_11 ) )
return V_14 ;
V_11 = F_47 ( V_28 , V_78 ,
F_31 , NULL ) ;
return V_14 ;
}
static T_1
F_48 ( T_2 V_28 ,
T_3 V_75 , void * V_76 , void * * V_77 )
{
T_1 V_11 ;
V_11 = F_44 ( V_28 ) ;
if ( F_3 ( V_11 ) )
return V_14 ;
V_11 = F_49 ( V_28 ,
V_78 ,
F_31 ) ;
return V_14 ;
}
static int T_4 F_50 ( void )
{
int V_34 ;
T_1 V_11 ;
V_34 = F_51 ( & V_79 ) ;
if ( V_34 < 0 )
return - V_39 ;
V_11 = F_52 ( V_80 , V_81 ,
V_82 ,
F_46 , NULL ,
NULL , NULL ) ;
if ( F_3 ( V_11 ) ) {
F_17 ( ( V_36 , V_11 , L_18 ) ) ;
F_53 ( & V_79 ) ;
return - V_39 ;
}
return 0 ;
}
static void T_5 F_54 ( void )
{
T_1 V_11 ;
V_11 = F_52 ( V_80 , V_81 ,
V_82 ,
F_48 , NULL ,
NULL , NULL ) ;
if ( F_3 ( V_11 ) )
F_17 ( ( V_36 , V_11 , L_18 ) ) ;
F_53 ( & V_79 ) ;
return;
}
