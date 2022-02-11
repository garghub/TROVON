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
static int F_14 ( T_2 V_28 ,
struct V_4 * * V_5 )
{
struct V_31 * V_27 = NULL ;
int V_32 = 0 ;
F_15 () ;
F_16 ( V_28 , & V_27 ) ;
if ( V_27 )
goto V_33;
V_32 = F_17 ( V_28 ) ;
if ( V_32 ) {
F_18 ( V_28 , L_1 ) ;
V_32 = - V_30 ;
goto V_34;
}
V_32 = F_16 ( V_28 , & V_27 ) ;
if ( V_32 ) {
F_18 ( V_28 , L_2 ) ;
V_32 = - V_30 ;
goto V_34;
}
V_33:
* V_5 = F_19 ( V_27 ) ;
if ( ! ( * V_5 ) ) {
F_20 ( & V_27 -> V_35 , L_3 ) ;
V_32 = - V_36 ;
goto V_34;
}
V_34:
F_21 () ;
return V_32 ;
}
static int F_22 ( struct V_4 * V_5 )
{
unsigned long long V_37 ;
if ( F_3 ( F_23 ( V_5 -> V_27 -> V_28 , L_4 ,
NULL , & V_37 ) ) )
return - V_36 ;
if ( ! ( ( V_37 & V_38 )
&& ( V_37 & V_39 )
&& ( V_37 & V_40 ) ) )
return - V_36 ;
return 0 ;
}
static int F_24 ( struct V_4 * V_5 )
{
int V_32 , V_41 = 0 ;
struct V_8 * V_9 ;
int V_42 ;
V_42 = F_25 ( V_5 -> V_27 -> V_28 ) ;
F_4 (info, &mem_device->res_list, list) {
if ( V_9 -> V_43 ) {
V_41 ++ ;
continue;
}
if ( ! V_9 -> V_19 )
continue;
if ( V_42 < 0 )
V_42 = F_26 ( V_9 -> V_18 ) ;
V_32 = F_27 ( V_42 , V_9 -> V_18 , V_9 -> V_19 ) ;
if ( V_32 && V_32 != - V_44 ) {
V_9 -> V_45 = 1 ;
continue;
}
if ( ! V_32 )
V_9 -> V_43 = 1 ;
V_41 ++ ;
}
if ( ! V_41 ) {
F_20 ( & V_5 -> V_27 -> V_35 , L_5 ) ;
V_5 -> V_46 = V_47 ;
return - V_30 ;
}
return 0 ;
}
static int F_28 ( struct V_4 * V_5 )
{
int V_32 = 0 , V_48 ;
struct V_8 * V_9 , * V_26 ;
V_48 = F_25 ( V_5 -> V_27 -> V_28 ) ;
F_9 (info, n, &mem_device->res_list, list) {
if ( V_9 -> V_45 )
continue;
if ( ! V_9 -> V_43 )
return - V_49 ;
if ( V_48 < 0 )
V_48 = F_26 ( V_9 -> V_18 ) ;
V_32 = F_29 ( V_48 , V_9 -> V_18 , V_9 -> V_19 ) ;
if ( V_32 )
return V_32 ;
F_30 ( & V_9 -> V_24 ) ;
F_10 ( V_9 ) ;
}
return V_32 ;
}
static void F_31 ( T_2 V_28 , T_3 V_50 , void * V_51 )
{
struct V_4 * V_5 ;
struct V_31 * V_27 ;
struct V_52 * V_53 = NULL ;
T_3 V_54 = V_55 ;
T_1 V_11 ;
switch ( V_50 ) {
case V_56 :
F_32 ( ( V_57 ,
L_6 ) ) ;
case V_58 :
if ( V_50 == V_58 )
F_32 ( ( V_57 ,
L_7 ) ) ;
if ( F_14 ( V_28 , & V_5 ) ) {
F_33 ( V_28 , L_8 ) ;
break;
}
V_54 = V_59 ;
break;
case V_60 :
F_32 ( ( V_57 ,
L_9 ) ) ;
V_11 = V_23 ;
F_15 () ;
if ( F_16 ( V_28 , & V_27 ) ) {
F_33 ( V_28 , L_10 ) ;
goto V_61;
}
V_5 = F_19 ( V_27 ) ;
if ( ! V_5 ) {
F_33 ( V_28 , L_11 ) ;
goto V_61;
}
V_53 = F_34 ( sizeof( * V_53 ) , V_22 ) ;
if ( ! V_53 ) {
F_35 ( V_62 L_12 ) ;
goto V_61;
}
F_36 ( & V_27 -> V_35 ) ;
V_53 -> V_27 = V_27 ;
V_53 -> V_50 = V_60 ;
V_11 = F_37 ( V_63 ,
V_53 ) ;
if ( F_3 ( V_11 ) ) {
F_38 ( & V_27 -> V_35 ) ;
F_10 ( V_53 ) ;
}
V_61:
F_21 () ;
if ( F_39 ( V_11 ) )
return;
default:
F_32 ( ( V_57 ,
L_13 , V_50 ) ) ;
return;
}
( void ) F_40 ( V_28 , V_50 , V_54 , NULL ) ;
}
static void F_41 ( struct V_4 * V_5 )
{
if ( ! V_5 )
return;
F_8 ( V_5 ) ;
F_10 ( V_5 ) ;
}
static int F_42 ( struct V_31 * V_27 )
{
int V_32 ;
struct V_4 * V_5 = NULL ;
if ( ! V_27 )
return - V_30 ;
V_5 = F_5 ( sizeof( struct V_4 ) , V_22 ) ;
if ( ! V_5 )
return - V_64 ;
F_6 ( & V_5 -> V_25 ) ;
V_5 -> V_27 = V_27 ;
sprintf ( F_43 ( V_27 ) , L_14 , V_65 ) ;
sprintf ( F_44 ( V_27 ) , L_14 , V_66 ) ;
V_27 -> V_67 = V_5 ;
V_32 = F_11 ( V_5 ) ;
if ( V_32 ) {
F_10 ( V_5 ) ;
return V_32 ;
}
V_5 -> V_46 = V_68 ;
F_45 ( L_15 , F_43 ( V_27 ) ) ;
if ( ! F_22 ( V_5 ) ) {
V_32 = F_24 ( V_5 ) ;
if ( V_32 ) {
F_20 ( & V_27 -> V_35 ,
L_16 ) ;
F_41 ( V_5 ) ;
}
}
return V_32 ;
}
static int F_46 ( struct V_31 * V_27 )
{
struct V_4 * V_5 = NULL ;
int V_32 ;
if ( ! V_27 || ! F_19 ( V_27 ) )
return - V_30 ;
V_5 = F_19 ( V_27 ) ;
V_32 = F_28 ( V_5 ) ;
if ( V_32 )
return V_32 ;
F_41 ( V_5 ) ;
return 0 ;
}
static T_1 F_47 ( T_2 V_28 )
{
char * V_69 ;
T_1 V_11 ;
struct V_70 * V_9 ;
V_11 = F_48 ( V_28 , & V_9 ) ;
if ( F_3 ( V_11 ) )
return V_11 ;
if ( ! ( V_9 -> V_71 & V_72 ) ) {
F_10 ( V_9 ) ;
return V_23 ;
}
V_69 = V_9 -> V_69 . string ;
if ( ( V_69 == NULL ) ||
( strcmp ( V_69 , V_73 ) ) )
V_11 = V_23 ;
F_10 ( V_9 ) ;
return V_11 ;
}
static T_1
F_49 ( T_2 V_28 ,
T_3 V_74 , void * V_75 , void * * V_76 )
{
T_1 V_11 ;
V_11 = F_47 ( V_28 ) ;
if ( F_3 ( V_11 ) )
return V_14 ;
V_11 = F_50 ( V_28 , V_77 ,
F_31 , NULL ) ;
return V_14 ;
}
static T_1
F_51 ( T_2 V_28 ,
T_3 V_74 , void * V_75 , void * * V_76 )
{
T_1 V_11 ;
V_11 = F_47 ( V_28 ) ;
if ( F_3 ( V_11 ) )
return V_14 ;
V_11 = F_52 ( V_28 ,
V_77 ,
F_31 ) ;
return V_14 ;
}
static int T_4 F_53 ( void )
{
int V_32 ;
T_1 V_11 ;
V_32 = F_54 ( & V_78 ) ;
if ( V_32 < 0 )
return - V_36 ;
V_11 = F_55 ( V_79 , V_80 ,
V_81 ,
F_49 , NULL ,
NULL , NULL ) ;
if ( F_3 ( V_11 ) ) {
F_56 ( ( V_82 , V_11 , L_17 ) ) ;
F_57 ( & V_78 ) ;
return - V_36 ;
}
return 0 ;
}
static void T_5 F_58 ( void )
{
T_1 V_11 ;
V_11 = F_55 ( V_79 , V_80 ,
V_81 ,
F_51 , NULL ,
NULL , NULL ) ;
if ( F_3 ( V_11 ) )
F_56 ( ( V_82 , V_11 , L_17 ) ) ;
F_57 ( & V_78 ) ;
return;
}
