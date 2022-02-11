static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
unsigned long long V_4 ;
union V_5 V_6 = { 0 } ;
struct V_7 V_8 = { sizeof( union V_5 ) , & V_6 } ;
struct V_9 * V_10 ;
V_10 = F_2 ( V_2 ) ;
if ( ! V_10 ) {
F_3 ( V_11 L_1 ) ;
return - V_12 ;
}
if ( ! strcmp ( F_4 ( V_2 ) , V_13 ) ) {
V_3 = F_5 ( V_10 -> V_14 , NULL , NULL , & V_8 ) ;
if ( F_6 ( V_3 ) ) {
F_3 ( V_11 L_2 ) ;
return - V_15 ;
}
V_10 -> V_16 = V_6 . V_17 . V_18 ;
} else {
V_3 = F_7 ( V_10 -> V_14 , V_19 ,
NULL , & V_4 ) ;
if ( F_6 ( V_3 ) ) {
F_3 ( V_11 L_3 ) ;
return - V_15 ;
}
V_10 -> V_16 = V_4 ;
}
V_10 -> V_20 = F_8 ( V_10 -> V_16 ) ;
if ( ( int ) V_10 -> V_20 < 0 )
if ( F_6 ( F_9 ( V_10 ) ) ) {
F_3 ( V_11 L_4 ,
V_10 -> V_16 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_21 ;
struct V_9 * V_10 ;
if ( ! V_2 )
return - V_12 ;
V_10 = F_11 ( sizeof( struct V_9 ) , V_22 ) ;
if ( ! V_10 )
return - V_23 ;
V_10 -> V_14 = V_2 -> V_14 ;
strcpy ( F_12 ( V_2 ) , V_24 ) ;
strcpy ( F_13 ( V_2 ) , V_25 ) ;
V_2 -> V_26 = V_10 ;
V_21 = F_1 ( V_2 ) ;
if ( V_21 )
F_3 ( V_11 L_5 ) ;
return V_21 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( ! V_2 )
return - V_12 ;
V_10 = F_2 ( V_2 ) ;
if ( ! V_10 )
return - V_12 ;
F_15 ( V_10 ) ;
return 0 ;
}
static int F_16 ( T_2 V_14 )
{
T_1 V_3 ;
unsigned long long V_27 = 0 ;
V_3 = F_7 ( V_14 , L_6 , NULL , & V_27 ) ;
if ( F_17 ( V_3 ) && ( V_27 & V_28 ) )
return 1 ;
if ( V_3 == V_29 )
F_18 ( V_11 L_7 ) ;
else
F_18 ( V_11 L_8 ) ;
return 0 ;
}
static int F_19 ( T_2 V_14 )
{
struct V_7 V_8 = { V_30 , NULL } ;
union V_5 * V_31 ;
struct V_32 * V_33 ;
int V_34 ;
if ( F_6 ( F_5 ( V_14 , L_9 , NULL , & V_8 ) ) )
return - V_12 ;
if ( ! V_8 . V_35 || ! V_8 . V_36 )
return - V_12 ;
V_31 = V_8 . V_36 ;
if ( V_31 -> type != V_37 ||
V_31 -> V_8 . V_35 < sizeof( * V_33 ) ) {
F_15 ( V_8 . V_36 ) ;
return - V_12 ;
}
V_33 = (struct V_32 * ) V_31 -> V_8 . V_36 ;
if ( V_33 -> V_38 . type != V_39 ||
! ( V_33 -> V_40 & V_41 ) ) {
F_15 ( V_8 . V_36 ) ;
return - V_12 ;
}
V_34 = ( V_42 ) V_33 -> V_20 ;
F_15 ( V_8 . V_36 ) ;
V_8 . V_35 = V_30 ;
V_8 . V_36 = NULL ;
return V_34 ;
}
static int F_20 ( struct V_9 * V_10 )
{
int V_43 , V_34 , V_44 ;
struct V_45 V_46 ;
V_34 = F_19 ( V_10 -> V_14 ) ;
if ( V_34 < 0 ) {
F_3 ( V_11 L_10 ,
V_10 -> V_16 ) ;
return - V_15 ;
}
V_44 = F_21 ( V_10 -> V_14 ) ;
if ( V_44 < 0 ) {
F_3 ( V_11 L_11 ,
V_10 -> V_16 ) ;
return V_44 ;
}
V_46 . V_47 = V_48 ;
V_46 . V_49 . V_50 . V_34 = V_34 ;
V_46 . V_49 . V_50 . V_16 = V_10 -> V_16 ;
V_46 . V_49 . V_50 . V_44 = V_44 ;
V_43 = F_22 ( & V_46 ) ;
if ( V_43 < 0 )
F_3 ( V_11 L_12 ,
V_10 -> V_16 ) ;
return V_43 ;
}
static T_1 F_9 ( struct V_9 * V_10 )
{
if ( ! F_16 ( V_10 -> V_14 ) )
return V_51 ;
V_10 -> V_20 = F_20 ( V_10 ) ;
if ( ( int ) V_10 -> V_20 < 0 )
return V_51 ;
F_23 () ;
return V_52 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_25 ( V_11 L_13 ) ;
return - V_53 ;
}
static void F_26 ( T_2 V_14 ,
T_3 V_54 , void * V_55 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 = NULL ;
T_3 V_56 = V_57 ;
int V_58 ;
F_27 () ;
switch ( V_54 ) {
case V_59 :
case V_60 :
F_28 ( ( V_61 ,
L_14 ,
( V_54 == V_59 ) ?
L_15 : L_16 ) ) ;
if ( ! F_16 ( V_14 ) )
break;
F_29 ( V_14 , & V_2 ) ;
if ( F_30 ( V_2 ) )
break;
V_58 = F_31 ( V_14 ) ;
if ( V_58 ) {
F_3 ( V_11 L_17 ) ;
break;
}
V_2 = NULL ;
F_29 ( V_14 , & V_2 ) ;
if ( ! F_30 ( V_2 ) ) {
F_3 ( V_11 L_18 ) ;
break;
}
V_56 = V_62 ;
break;
case V_63 :
F_28 ( ( V_61 ,
L_19 ) ) ;
if ( F_29 ( V_14 , & V_2 ) ) {
F_3 ( V_11 L_20 ) ;
break;
}
V_10 = F_2 ( V_2 ) ;
if ( ! V_10 ) {
F_3 ( V_11 L_21 ) ;
break;
}
F_24 ( V_2 ) ;
break;
default:
F_28 ( ( V_61 ,
L_22 , V_54 ) ) ;
goto V_64;
}
( void ) F_32 ( V_14 , V_54 , V_56 , NULL ) ;
V_64:
F_33 () ;
}
static T_1 F_34 ( T_2 V_14 )
{
struct V_65 * V_66 ;
char * V_67 ;
T_1 V_3 ;
V_3 = F_35 ( V_14 , & V_66 ) ;
if ( F_6 ( V_3 ) )
return V_3 ;
if ( V_66 -> type == V_68 ) {
F_15 ( V_66 ) ;
return V_52 ;
}
if ( ! ( V_66 -> V_69 & V_70 ) ) {
F_15 ( V_66 ) ;
return V_51 ;
}
V_67 = V_66 -> V_71 . string ;
if ( ( V_67 == NULL ) || strcmp ( V_67 , V_72 ) ) {
F_15 ( V_66 ) ;
return V_51 ;
}
F_15 ( V_66 ) ;
return V_52 ;
}
static T_1
F_36 ( T_2 V_14 ,
T_3 V_73 , void * V_74 , void * * V_75 )
{
T_1 V_3 ;
int * V_76 = V_74 ;
V_3 = F_34 ( V_14 ) ;
if ( F_6 ( V_3 ) )
return V_52 ;
switch ( * V_76 ) {
case V_77 :
F_37 ( V_14 ,
V_78 ,
F_26 ,
NULL ) ;
break;
case V_79 :
F_38 ( V_14 ,
V_78 ,
F_26 ) ;
break;
default:
break;
}
return V_80 ;
}
static
void F_39 ( void )
{
int V_76 = V_77 ;
F_40 ( V_81 ,
V_82 ,
V_83 ,
F_36 , NULL , & V_76 , NULL ) ;
}
static
void F_41 ( void )
{
int V_76 = V_79 ;
F_40 ( V_81 ,
V_82 ,
V_83 ,
F_36 , NULL , & V_76 , NULL ) ;
}
static int T_4 F_42 ( void )
{
int V_58 = 0 ;
if ( ! F_43 () )
return - V_15 ;
F_44 () ;
V_58 = F_45 ( & V_84 ) ;
if ( V_58 < 0 ) {
F_46 () ;
return V_58 ;
}
F_39 () ;
return 0 ;
}
static void T_5 F_47 ( void )
{
if ( ! F_43 () )
return;
F_41 () ;
F_48 ( & V_84 ) ;
F_46 () ;
return;
}
