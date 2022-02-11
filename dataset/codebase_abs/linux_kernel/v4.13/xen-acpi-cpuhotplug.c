static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
unsigned long long V_4 ;
union V_5 V_6 = { 0 } ;
struct V_7 V_8 = { sizeof( union V_5 ) , & V_6 } ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( ! strcmp ( F_3 ( V_2 ) , V_11 ) ) {
V_3 = F_4 ( V_10 -> V_12 , NULL , NULL , & V_8 ) ;
if ( F_5 ( V_3 ) ) {
F_6 ( V_13 L_1 ) ;
return - V_14 ;
}
V_10 -> V_15 = V_6 . V_16 . V_17 ;
} else {
V_3 = F_7 ( V_10 -> V_12 , V_18 ,
NULL , & V_4 ) ;
if ( F_5 ( V_3 ) ) {
F_6 ( V_13 L_2 ) ;
return - V_14 ;
}
V_10 -> V_15 = V_4 ;
}
V_10 -> V_19 = F_8 ( V_10 -> V_15 ) ;
if ( F_9 ( V_10 -> V_19 ) )
if ( F_5 ( F_10 ( V_10 ) ) ) {
F_6 ( V_13 L_3 ,
V_10 -> V_15 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_20 ;
struct V_9 * V_10 ;
if ( ! V_2 )
return - V_21 ;
V_10 = F_12 ( sizeof( struct V_9 ) , V_22 ) ;
if ( ! V_10 )
return - V_23 ;
V_10 -> V_12 = V_2 -> V_12 ;
strcpy ( F_13 ( V_2 ) , V_24 ) ;
strcpy ( F_14 ( V_2 ) , V_25 ) ;
V_2 -> V_26 = V_10 ;
V_20 = F_1 ( V_2 ) ;
if ( V_20 )
F_6 ( V_13 L_4 ) ;
return V_20 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( ! V_2 )
return - V_21 ;
V_10 = F_2 ( V_2 ) ;
if ( ! V_10 )
return - V_21 ;
F_16 ( V_10 ) ;
return 0 ;
}
static int F_17 ( T_2 V_12 )
{
T_1 V_3 ;
unsigned long long V_27 = 0 ;
V_3 = F_7 ( V_12 , L_5 , NULL , & V_27 ) ;
if ( F_18 ( V_3 ) && ( V_27 & V_28 ) )
return 1 ;
if ( V_3 == V_29 )
F_19 ( V_13 L_6 ) ;
else
F_19 ( V_13 L_7 ) ;
return 0 ;
}
static int F_20 ( T_2 V_12 )
{
struct V_7 V_8 = { V_30 , NULL } ;
union V_5 * V_31 ;
struct V_32 * V_33 ;
int V_34 ;
if ( F_5 ( F_4 ( V_12 , L_8 , NULL , & V_8 ) ) )
return - V_21 ;
if ( ! V_8 . V_35 || ! V_8 . V_36 )
return - V_21 ;
V_31 = V_8 . V_36 ;
if ( V_31 -> type != V_37 ||
V_31 -> V_8 . V_35 < sizeof( * V_33 ) ) {
F_16 ( V_8 . V_36 ) ;
return - V_21 ;
}
V_33 = (struct V_32 * ) V_31 -> V_8 . V_36 ;
if ( V_33 -> V_38 . type != V_39 ||
! ( V_33 -> V_40 & V_41 ) ) {
F_16 ( V_8 . V_36 ) ;
return - V_21 ;
}
V_34 = ( V_42 ) V_33 -> V_19 ;
F_16 ( V_8 . V_36 ) ;
V_8 . V_35 = V_30 ;
V_8 . V_36 = NULL ;
return V_34 ;
}
static int F_21 ( struct V_9 * V_10 )
{
int V_43 , V_34 , V_44 ;
struct V_45 V_46 ;
V_34 = F_20 ( V_10 -> V_12 ) ;
if ( V_34 < 0 ) {
F_6 ( V_13 L_9 ,
V_10 -> V_15 ) ;
return - V_14 ;
}
V_44 = F_22 ( V_10 -> V_12 ) ;
if ( V_44 < 0 ) {
F_6 ( V_13 L_10 ,
V_10 -> V_15 ) ;
return V_44 ;
}
V_46 . V_47 = V_48 ;
V_46 . V_49 . V_50 . V_34 = V_34 ;
V_46 . V_49 . V_50 . V_15 = V_10 -> V_15 ;
V_46 . V_49 . V_50 . V_44 = V_44 ;
V_43 = F_23 ( & V_46 ) ;
if ( V_43 < 0 )
F_6 ( V_13 L_11 ,
V_10 -> V_15 ) ;
return V_43 ;
}
static T_1 F_10 ( struct V_9 * V_10 )
{
if ( ! F_17 ( V_10 -> V_12 ) )
return V_51 ;
V_10 -> V_19 = F_21 ( V_10 ) ;
if ( F_9 ( V_10 -> V_19 ) )
return V_51 ;
F_24 () ;
return V_52 ;
}
static int F_25 ( struct V_1 * V_2 )
{
F_26 ( V_13 L_12 ) ;
return - V_53 ;
}
static void F_27 ( T_2 V_12 ,
T_3 V_54 , void * V_55 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 = NULL ;
T_3 V_56 = V_57 ;
int V_58 ;
F_28 () ;
switch ( V_54 ) {
case V_59 :
case V_60 :
F_29 ( ( V_61 ,
L_13 ,
( V_54 == V_59 ) ?
L_14 : L_15 ) ) ;
if ( ! F_17 ( V_12 ) )
break;
F_30 ( V_12 , & V_2 ) ;
if ( F_31 ( V_2 ) )
break;
V_58 = F_32 ( V_12 ) ;
if ( V_58 ) {
F_6 ( V_13 L_16 ) ;
break;
}
V_2 = NULL ;
F_30 ( V_12 , & V_2 ) ;
if ( ! F_31 ( V_2 ) ) {
F_6 ( V_13 L_17 ) ;
break;
}
V_56 = V_62 ;
break;
case V_63 :
F_29 ( ( V_61 ,
L_18 ) ) ;
if ( F_30 ( V_12 , & V_2 ) ) {
F_6 ( V_13 L_19 ) ;
break;
}
V_10 = F_2 ( V_2 ) ;
if ( ! V_10 ) {
F_6 ( V_13 L_20 ) ;
break;
}
F_25 ( V_2 ) ;
break;
default:
F_29 ( ( V_61 ,
L_21 , V_54 ) ) ;
goto V_64;
}
( void ) F_33 ( V_12 , V_54 , V_56 , NULL ) ;
V_64:
F_34 () ;
}
static T_1 F_35 ( T_2 V_12 )
{
struct V_65 * V_66 ;
char * V_67 ;
T_1 V_3 ;
V_3 = F_36 ( V_12 , & V_66 ) ;
if ( F_5 ( V_3 ) )
return V_3 ;
if ( V_66 -> type == V_68 ) {
F_16 ( V_66 ) ;
return V_52 ;
}
if ( ! ( V_66 -> V_69 & V_70 ) ) {
F_16 ( V_66 ) ;
return V_51 ;
}
V_67 = V_66 -> V_71 . string ;
if ( ( V_67 == NULL ) || strcmp ( V_67 , V_72 ) ) {
F_16 ( V_66 ) ;
return V_51 ;
}
F_16 ( V_66 ) ;
return V_52 ;
}
static T_1
F_37 ( T_2 V_12 ,
T_3 V_73 , void * V_74 , void * * V_75 )
{
T_1 V_3 ;
int * V_76 = V_74 ;
V_3 = F_35 ( V_12 ) ;
if ( F_5 ( V_3 ) )
return V_52 ;
switch ( * V_76 ) {
case V_77 :
F_38 ( V_12 ,
V_78 ,
F_27 ,
NULL ) ;
break;
case V_79 :
F_39 ( V_12 ,
V_78 ,
F_27 ) ;
break;
default:
break;
}
return V_80 ;
}
static
void F_40 ( void )
{
int V_76 = V_77 ;
F_41 ( V_81 ,
V_82 ,
V_83 ,
F_37 , NULL , & V_76 , NULL ) ;
}
static
void F_42 ( void )
{
int V_76 = V_79 ;
F_41 ( V_81 ,
V_82 ,
V_83 ,
F_37 , NULL , & V_76 , NULL ) ;
}
static int T_4 F_43 ( void )
{
int V_58 = 0 ;
if ( ! F_44 () )
return - V_14 ;
F_45 () ;
V_58 = F_46 ( & V_84 ) ;
if ( V_58 < 0 ) {
F_47 () ;
return V_58 ;
}
F_40 () ;
return 0 ;
}
static void T_5 F_48 ( void )
{
if ( ! F_44 () )
return;
F_42 () ;
F_49 ( & V_84 ) ;
F_47 () ;
return;
}
