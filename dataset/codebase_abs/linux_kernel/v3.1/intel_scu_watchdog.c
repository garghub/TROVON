static void F_1 ( void )
{
if ( V_1 ) {
F_2 (KERN_CRIT PFX L_1 ) ;
F_3 () ;
F_2 (KERN_CRIT PFX L_2 ) ;
}
else {
F_2 (KERN_CRIT PFX L_3 ) ;
F_2 (KERN_CRIT PFX
L_4 ) ;
}
}
static int F_4 ( int V_2 )
{
if ( ( V_2 < V_3 ) ||
( V_2 > V_4 - V_5 ) ) {
F_5 ( L_5 ,
V_2 , V_3 , V_4 - V_5 ) ;
return - V_6 ;
}
return 0 ;
}
static int F_6 ( int V_7 , int V_8 )
{
T_1 * V_9 ;
T_2 V_10 [ 16 ] = { '\0' } ;
int V_11 = 0 ;
V_9 = ( T_1 * ) & V_10 ;
V_9 [ 0 ] = V_7 ;
V_9 [ 1 ] = V_8 ;
V_11 = F_7 (
V_12 ,
0 ,
V_9 ,
2 ,
NULL ,
0 ) ;
if ( V_11 != 0 )
F_8 ( L_6 , V_11 ) ;
return V_11 ;
}
static T_3 F_9 ( int V_13 , void * V_14 )
{
int V_15 ;
V_15 = F_10 ( V_16 . V_17 ) ;
F_5 ( L_7 , V_15 ) ;
if ( V_15 != 0 )
return V_18 ;
if ( V_16 . V_19 == 0 ) {
F_5 ( L_8 ) ;
return V_20 ;
}
F_11 ( 0x00000002 , V_16 . V_21 ) ;
F_11 ( V_16 . V_8 ,
V_16 . V_22 ) ;
F_11 ( 0x00000003 , V_16 . V_21 ) ;
return V_20 ;
}
static int F_12 ( void )
{
F_10 ( V_16 . V_23 ) ;
F_11 ( 0x00000002 , V_16 . V_21 ) ;
F_11 ( V_16 . V_7 ,
V_16 . V_22 ) ;
F_11 ( 0x00000003 , V_16 . V_21 ) ;
return 0 ;
}
static int F_13 ( void )
{
F_11 ( 0 , V_16 . V_21 ) ;
return 0 ;
}
static int F_14 ( T_1 V_24 )
{
int V_11 ;
int V_25 ;
T_1 V_26 ;
T_1 V_27 ;
T_1 V_28 ;
V_16 . V_5 = V_24 ;
V_16 . V_8 =
V_29 * V_16 . V_30 -> V_31 ;
V_16 . V_7 =
( V_16 . V_5 - V_29 )
* V_16 . V_30 -> V_31 ;
F_5 ( L_9 ,
V_16 . V_30 -> V_31 ) ;
F_5 ( L_10 ,
V_16 . V_5 ) ;
F_5 ( L_11 ,
V_29 ) ;
F_5 ( L_12 ,
V_16 . V_8 ) ;
F_5 ( L_13 ,
V_16 . V_7 ) ;
V_16 . V_8 =
V_16 . V_8 / V_32 ;
V_16 . V_7 =
V_16 . V_7 / V_32 ;
F_11 ( 0x00000002 , V_16 . V_21 ) ;
V_11 = F_6 ( V_16 . V_7 ,
V_16 . V_8 ) ;
if ( V_11 != 0 ) {
F_13 () ;
return V_11 ;
}
V_25 = 0 ;
V_26 = V_16 . V_7 & 0xFFFF0000 ;
do {
F_13 () ;
if ( V_33 < V_25 ++ ) {
F_8 ( L_14 ) ;
return - V_34 ;
}
F_11 ( V_16 . V_7 ,
V_16 . V_22 ) ;
V_27 = F_10 ( V_16 . V_22 ) ;
V_27 = V_27 & 0xFFFF0000 ;
F_11 ( 0x00000003 , V_16 . V_21 ) ;
V_28 = F_10 ( V_16 . V_22 ) ;
V_28 = V_28 & 0xFFFF0000 ;
} while ( V_26 != V_28 );
V_16 . V_19 = 1 ;
return 0 ;
}
static int F_15 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
if ( F_16 ( 0 , & V_16 . V_37 ) )
return - V_38 ;
if ( V_16 . V_39 )
return - V_40 ;
return F_17 ( V_35 , V_36 ) ;
}
static int F_18 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
if ( ! F_19 ( 0 , & V_16 . V_37 ) ) {
F_5 ( L_15 ) ;
return - V_41 ;
}
if ( ! V_16 . V_19 ) {
F_5 ( L_16 ) ;
return 0 ;
}
F_2 (KERN_CRIT PFX
L_17 ) ;
V_16 . V_39 = 1 ;
F_12 () ;
F_1 () ;
return 0 ;
}
static T_4 F_20 ( struct V_36 * V_36 ,
char const * V_42 ,
T_5 V_43 ,
T_6 * V_44 )
{
if ( V_16 . V_19 )
F_12 () ;
else
F_14 ( V_16 . V_5 ) ;
return V_43 ;
}
static long F_21 ( struct V_36 * V_36 ,
unsigned int V_45 ,
unsigned long V_46 )
{
void T_7 * V_47 = ( void T_7 * ) V_46 ;
T_1 T_7 * V_48 = V_47 ;
T_1 V_2 ;
static const struct V_49 V_50 = {
. V_51 = V_52
| V_53 ,
. V_54 = 0 ,
. V_55 = L_18
} ;
switch ( V_45 ) {
case V_56 :
return F_22 ( V_47 ,
& V_50 ,
sizeof( V_50 ) ) ? - V_57 : 0 ;
case V_58 :
case V_59 :
return F_23 ( 0 , V_48 ) ;
case V_60 :
F_12 () ;
return 0 ;
case V_61 :
if ( F_24 ( V_2 , V_48 ) )
return - V_57 ;
if ( F_4 ( V_2 ) )
return - V_6 ;
if ( F_14 ( V_2 ) )
return - V_6 ;
return 0 ;
case V_62 :
return F_23 ( V_16 . V_7 , V_48 ) ;
default:
return - V_41 ;
}
}
static int F_25 ( struct V_63 * V_64 ,
unsigned long V_65 ,
void * V_66 )
{
if ( V_65 == V_67 || V_65 == V_68 )
F_13 () ;
return V_69 ;
}
static int T_8 F_26 ( void )
{
int V_70 ;
T_1 T_9 * V_71 ;
if ( ! F_27 () )
return - V_34 ;
if ( ( V_5 < V_3 ) ||
( V_5 > V_4 - V_3 ) ) {
F_8 ( L_19
L_20 ,
V_5 , V_3 , V_4 - V_3 ) ;
return - V_6 ;
}
if ( F_4 ( V_29 ) )
return - V_6 ;
V_16 . V_30 = F_28 ( V_72 - 1 ) ;
if ( V_16 . V_30 == NULL ) {
F_5 ( L_21 ) ;
return - V_34 ;
}
if ( V_16 . V_30 -> V_73 == 0 ) {
F_5 ( L_22 ,
V_72 ) ;
return - V_34 ;
}
if ( V_16 . V_30 -> V_13 == 0 ) {
F_5 ( L_23 ,
V_72 ) ;
return - V_34 ;
}
V_71 = F_29 ( V_16 . V_30 -> V_73 ,
20 ) ;
if ( V_71 == NULL ) {
F_5 ( L_24 ) ;
return - V_74 ;
}
V_16 . V_22 = V_71 ++ ;
V_16 . V_75 = V_71 ++ ;
V_16 . V_21 = V_71 ++ ;
V_16 . V_23 = V_71 ++ ;
V_16 . V_17 = V_71 ++ ;
V_16 . V_5 = V_5 ;
V_16 . V_8 =
V_29 * V_16 . V_30 -> V_31 ;
V_16 . V_7 =
( V_16 . V_5 - V_29 )
* V_16 . V_30 -> V_31 ;
V_16 . V_76 . V_77 =
F_25 ;
V_70 = F_30 ( & V_16 . V_76 ) ;
if ( V_70 ) {
F_8 ( L_25 , V_70 ) ;
goto V_78;
}
V_16 . V_79 . V_80 = V_81 ;
V_16 . V_79 . V_82 = L_26 ;
V_16 . V_79 . V_83 = & V_84 ;
V_70 = F_31 ( & V_16 . V_79 ) ;
if ( V_70 ) {
F_8 ( L_27 ,
V_81 , V_70 ) ;
goto V_85;
}
V_70 = F_32 ( ( unsigned int ) V_16 . V_30 -> V_13 ,
F_9 ,
V_86 , L_26 ,
& V_16 . V_22 ) ;
if ( V_70 ) {
F_8 ( L_28 , V_70 ) ;
goto V_87;
}
F_13 () ;
return 0 ;
V_87:
F_33 ( & V_16 . V_79 ) ;
V_85:
F_34 ( & V_16 . V_76 ) ;
V_78:
F_13 () ;
F_35 ( V_16 . V_22 ) ;
return V_70 ;
}
static void T_10 F_36 ( void )
{
F_33 ( & V_16 . V_79 ) ;
F_34 ( & V_16 . V_76 ) ;
F_11 ( 0x00000002 , V_16 . V_21 ) ;
F_35 ( V_16 . V_22 ) ;
}
