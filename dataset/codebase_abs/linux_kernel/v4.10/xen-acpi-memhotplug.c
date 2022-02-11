static int F_1 ( int V_1 , struct V_2 * V_3 )
{
int V_4 ;
struct V_5 V_6 ;
V_6 . V_7 = V_8 ;
V_6 . V_9 . V_10 . V_11 = V_3 -> V_12 >> V_13 ;
V_6 . V_9 . V_10 . V_14 = ( V_3 -> V_12 + V_3 -> V_15 ) >> V_13 ;
V_6 . V_9 . V_10 . V_1 = V_1 ;
V_4 = F_2 ( & V_6 ) ;
if ( V_4 )
F_3 ( V_16 L_1
L_2 ,
( unsigned long ) V_3 -> V_12 ,
( unsigned long ) ( V_3 -> V_12 + V_3 -> V_15 ) ,
V_1 , V_4 ) ;
return V_4 ;
}
static int F_4 ( struct V_17 * V_18 )
{
int V_1 , V_19 ;
int V_20 = 0 ;
struct V_2 * V_3 ;
if ( ! V_18 )
return - V_21 ;
V_1 = F_5 ( V_18 -> V_22 -> V_23 ) ;
if ( V_1 < 0 )
return V_1 ;
F_6 (info, &mem_device->res_list, list) {
if ( V_3 -> V_24 ) {
V_20 ++ ;
continue;
}
if ( ! V_3 -> V_15 )
continue;
V_19 = F_1 ( V_1 , V_3 ) ;
if ( V_19 )
continue;
V_3 -> V_24 = 1 ;
V_20 ++ ;
}
if ( ! V_20 )
return - V_25 ;
return 0 ;
}
static T_1
F_7 ( struct V_26 * V_27 , void * V_28 )
{
struct V_17 * V_18 = V_28 ;
struct V_29 V_30 ;
struct V_2 * V_3 , * V_31 ;
T_1 V_32 ;
V_32 = F_8 ( V_27 , & V_30 ) ;
if ( F_9 ( V_32 ) ||
( V_30 . V_33 != V_34 ) )
return V_35 ;
F_6 (info, &mem_device->res_list, list) {
if ( ( V_3 -> V_36 == V_30 . V_3 . V_37 . V_36 ) &&
( V_3 -> V_38 == V_30 . V_3 . V_37 . V_38 ) &&
( V_3 -> V_12 + V_3 -> V_15 == V_30 . V_39 . V_40 ) ) {
V_3 -> V_15 += V_30 . V_39 . V_41 ;
return V_35 ;
}
}
V_31 = F_10 ( sizeof( struct V_2 ) , V_42 ) ;
if ( ! V_31 )
return V_43 ;
F_11 ( & V_31 -> V_44 ) ;
V_31 -> V_36 = V_30 . V_3 . V_37 . V_36 ;
V_31 -> V_38 = V_30 . V_3 . V_37 . V_38 ;
V_31 -> V_12 = V_30 . V_39 . V_40 ;
V_31 -> V_15 = V_30 . V_39 . V_41 ;
F_12 ( & V_31 -> V_44 , & V_18 -> V_45 ) ;
return V_35 ;
}
static int
F_13 ( struct V_17 * V_18 )
{
T_1 V_32 ;
struct V_2 * V_3 , * V_46 ;
if ( ! F_14 ( & V_18 -> V_45 ) )
return 0 ;
V_32 = F_15 ( V_18 -> V_22 -> V_23 ,
V_47 , F_7 , V_18 ) ;
if ( F_9 ( V_32 ) ) {
F_16 (info, n, &mem_device->res_list, list)
F_17 ( V_3 ) ;
F_11 ( & V_18 -> V_45 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_18 ( T_2 V_23 ,
struct V_17 * * V_18 )
{
struct V_48 * V_22 = NULL ;
int V_19 = 0 ;
F_19 () ;
F_20 ( V_23 , & V_22 ) ;
if ( F_21 ( V_22 ) )
goto V_49;
V_19 = F_22 ( V_23 ) ;
if ( V_19 ) {
F_23 ( V_16 L_3 ) ;
V_19 = - V_21 ;
goto V_50;
}
V_22 = NULL ;
F_20 ( V_23 , & V_22 ) ;
if ( ! F_21 ( V_22 ) ) {
F_23 ( V_16 L_4 ) ;
V_19 = - V_21 ;
goto V_50;
}
V_49:
* V_18 = F_24 ( V_22 ) ;
if ( ! ( * V_18 ) ) {
F_3 ( V_16 L_5 ) ;
V_19 = - V_25 ;
goto V_50;
}
V_50:
F_25 () ;
return V_19 ;
}
static int F_26 ( struct V_17 * V_18 )
{
unsigned long long V_51 ;
if ( F_9 ( F_27 ( V_18 -> V_22 -> V_23 ,
L_6 , NULL , & V_51 ) ) )
return - V_25 ;
if ( ! ( ( V_51 & V_52 )
&& ( V_51 & V_53 )
&& ( V_51 & V_54 ) ) )
return - V_25 ;
return 0 ;
}
static int F_28 ( struct V_17 * V_18 )
{
F_29 ( V_16 L_7 ) ;
return - V_55 ;
}
static void F_30 ( T_2 V_23 , T_3 V_56 , void * V_57 )
{
struct V_17 * V_18 ;
struct V_48 * V_22 ;
T_3 V_58 = V_59 ;
switch ( V_56 ) {
case V_60 :
F_31 ( ( V_61 ,
L_8 ) ) ;
case V_62 :
if ( V_56 == V_62 )
F_31 ( ( V_61 ,
L_9 ) ) ;
if ( F_18 ( V_23 , & V_18 ) ) {
F_3 ( V_16 L_10 ) ;
break;
}
V_58 = V_63 ;
break;
case V_64 :
F_31 ( ( V_61 ,
L_11 ) ) ;
F_19 () ;
if ( F_20 ( V_23 , & V_22 ) ) {
F_25 () ;
F_3 ( V_16 L_12 ) ;
break;
}
V_18 = F_24 ( V_22 ) ;
if ( ! V_18 ) {
F_25 () ;
F_3 ( V_16 L_13 ) ;
break;
}
F_28 ( V_18 ) ;
F_25 () ;
break;
default:
F_31 ( ( V_61 ,
L_14 , V_56 ) ) ;
return;
}
( void ) F_32 ( V_23 , V_56 , V_58 , NULL ) ;
return;
}
static int F_33 ( struct V_48 * V_22 )
{
int V_19 ;
struct V_17 * V_18 = NULL ;
if ( ! V_22 )
return - V_21 ;
V_18 = F_10 ( sizeof( struct V_17 ) , V_42 ) ;
if ( ! V_18 )
return - V_65 ;
F_11 ( & V_18 -> V_45 ) ;
V_18 -> V_22 = V_22 ;
sprintf ( F_34 ( V_22 ) , L_15 , V_66 ) ;
sprintf ( F_35 ( V_22 ) , L_15 , V_67 ) ;
V_22 -> V_68 = V_18 ;
V_19 = F_13 ( V_18 ) ;
if ( V_19 ) {
F_17 ( V_18 ) ;
return V_19 ;
}
if ( ! V_69 )
return 0 ;
if ( ! F_26 ( V_18 ) )
V_19 = F_4 ( V_18 ) ;
return V_19 ;
}
static int F_36 ( struct V_48 * V_22 )
{
struct V_17 * V_18 = NULL ;
if ( ! V_22 || ! F_24 ( V_22 ) )
return - V_21 ;
V_18 = F_24 ( V_22 ) ;
F_17 ( V_18 ) ;
return 0 ;
}
static T_1 F_37 ( T_2 V_23 )
{
char * V_70 ;
T_1 V_32 ;
struct V_71 * V_3 ;
V_32 = F_38 ( V_23 , & V_3 ) ;
if ( F_9 ( V_32 ) )
return V_32 ;
if ( ! ( V_3 -> V_72 & V_73 ) ) {
F_17 ( V_3 ) ;
return V_43 ;
}
V_70 = V_3 -> V_70 . string ;
if ( ( V_70 == NULL ) ||
( strcmp ( V_70 , V_74 ) ) )
V_32 = V_43 ;
F_17 ( V_3 ) ;
return V_32 ;
}
static T_1
F_39 ( T_2 V_23 ,
T_3 V_75 , void * V_76 , void * * V_77 )
{
T_1 V_32 ;
V_32 = F_37 ( V_23 ) ;
if ( F_9 ( V_32 ) )
return V_35 ;
V_32 = F_40 ( V_23 , V_78 ,
F_30 , NULL ) ;
return V_35 ;
}
static T_1
F_41 ( T_2 V_23 ,
T_3 V_75 , void * V_76 , void * * V_77 )
{
T_1 V_32 ;
V_32 = F_37 ( V_23 ) ;
if ( F_9 ( V_32 ) )
return V_35 ;
V_32 = F_42 ( V_23 ,
V_78 ,
F_30 ) ;
return V_35 ;
}
static int T_4 F_43 ( void )
{
int V_19 ;
T_1 V_32 ;
if ( ! F_44 () )
return - V_25 ;
F_45 () ;
V_19 = F_46 ( & V_79 ) ;
if ( V_19 < 0 ) {
F_47 () ;
return - V_25 ;
}
V_32 = F_48 ( V_80 , V_81 ,
V_82 ,
F_39 ,
NULL , NULL , NULL ) ;
if ( F_9 ( V_32 ) ) {
F_23 ( V_16 L_16 ) ;
F_49 ( & V_79 ) ;
F_47 () ;
return - V_25 ;
}
V_69 = true ;
return 0 ;
}
static void T_5 F_50 ( void )
{
T_1 V_32 ;
if ( ! F_44 () )
return;
V_32 = F_48 ( V_80 , V_81 ,
V_82 ,
F_41 ,
NULL , NULL , NULL ) ;
if ( F_9 ( V_32 ) )
F_23 ( V_16 L_16 ) ;
F_49 ( & V_79 ) ;
F_47 () ;
return;
}
