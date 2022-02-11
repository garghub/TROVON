static void F_1 ( void )
{
if ( V_1 ) {
F_2 ( L_1 ) ;
F_3 () ;
F_2 ( L_2 ) ;
}
else {
F_2 ( L_3 ) ;
F_2 ( L_4 ) ;
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
V_16 . V_5 = V_24 ;
V_16 . V_8 =
V_28 * V_16 . V_29 -> V_30 ;
V_16 . V_7 =
( V_16 . V_5 - V_28 )
* V_16 . V_29 -> V_30 ;
F_5 ( L_9 ,
V_16 . V_29 -> V_30 ) ;
F_5 ( L_10 ,
V_16 . V_5 ) ;
F_5 ( L_11 , V_28 ) ;
F_5 ( L_12 ,
V_16 . V_8 ) ;
F_5 ( L_13 ,
V_16 . V_7 ) ;
V_16 . V_8 =
V_16 . V_8 / V_31 ;
V_16 . V_7 =
V_16 . V_7 / V_31 ;
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
if ( V_32 < V_25 ++ ) {
F_8 ( L_14 ) ;
return - V_33 ;
}
F_11 ( V_16 . V_7 ,
V_16 . V_22 ) ;
F_10 ( V_16 . V_22 ) ;
F_11 ( 0x00000003 , V_16 . V_21 ) ;
V_27 = F_10 ( V_16 . V_22 ) ;
V_27 = V_27 & 0xFFFF0000 ;
} while ( V_26 != V_27 );
V_16 . V_19 = 1 ;
return 0 ;
}
static int F_15 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
if ( F_16 ( 0 , & V_16 . V_36 ) )
return - V_37 ;
if ( V_16 . V_38 )
return - V_39 ;
return F_17 ( V_34 , V_35 ) ;
}
static int F_18 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
if ( ! F_19 ( 0 , & V_16 . V_36 ) ) {
F_5 ( L_15 ) ;
return - V_40 ;
}
if ( ! V_16 . V_19 ) {
F_5 ( L_16 ) ;
return 0 ;
}
F_2 ( L_17 ) ;
V_16 . V_38 = 1 ;
F_12 () ;
F_1 () ;
return 0 ;
}
static T_4 F_20 ( struct V_35 * V_35 ,
char const * V_41 ,
T_5 V_42 ,
T_6 * V_43 )
{
if ( V_16 . V_19 )
F_12 () ;
else
F_14 ( V_16 . V_5 ) ;
return V_42 ;
}
static long F_21 ( struct V_35 * V_35 ,
unsigned int V_44 ,
unsigned long V_45 )
{
void T_7 * V_46 = ( void T_7 * ) V_45 ;
T_1 T_7 * V_47 = V_46 ;
T_1 V_2 ;
static const struct V_48 V_49 = {
. V_50 = V_51
| V_52 ,
. V_53 = 0 ,
. V_54 = L_18
} ;
switch ( V_44 ) {
case V_55 :
return F_22 ( V_46 ,
& V_49 ,
sizeof( V_49 ) ) ? - V_56 : 0 ;
case V_57 :
case V_58 :
return F_23 ( 0 , V_47 ) ;
case V_59 :
F_12 () ;
return 0 ;
case V_60 :
if ( F_24 ( V_2 , V_47 ) )
return - V_56 ;
if ( F_4 ( V_2 ) )
return - V_6 ;
if ( F_14 ( V_2 ) )
return - V_6 ;
return 0 ;
case V_61 :
return F_23 ( V_16 . V_7 , V_47 ) ;
default:
return - V_40 ;
}
}
static int F_25 ( struct V_62 * V_63 ,
unsigned long V_64 ,
void * V_65 )
{
if ( V_64 == V_66 || V_64 == V_67 )
F_13 () ;
return V_68 ;
}
static int T_8 F_26 ( void )
{
int V_69 ;
T_1 T_9 * V_70 ;
if ( ! F_27 () )
return - V_33 ;
if ( ( V_5 < V_3 ) ||
( V_5 > V_4 - V_3 ) ) {
F_8 ( L_19 ,
V_5 , V_3 , V_4 - V_3 ) ;
return - V_6 ;
}
if ( F_4 ( V_28 ) )
return - V_6 ;
V_16 . V_29 = F_28 ( V_71 - 1 ) ;
if ( V_16 . V_29 == NULL ) {
F_5 ( L_20 ) ;
return - V_33 ;
}
if ( V_16 . V_29 -> V_72 == 0 ) {
F_5 ( L_21 ,
V_71 ) ;
return - V_33 ;
}
if ( V_16 . V_29 -> V_13 == 0 ) {
F_5 ( L_22 , V_71 ) ;
return - V_33 ;
}
V_70 = F_29 ( V_16 . V_29 -> V_72 ,
20 ) ;
if ( V_70 == NULL ) {
F_5 ( L_23 ) ;
return - V_73 ;
}
V_16 . V_22 = V_70 ++ ;
V_16 . V_74 = V_70 ++ ;
V_16 . V_21 = V_70 ++ ;
V_16 . V_23 = V_70 ++ ;
V_16 . V_17 = V_70 ++ ;
V_16 . V_5 = V_5 ;
V_16 . V_8 =
V_28 * V_16 . V_29 -> V_30 ;
V_16 . V_7 =
( V_16 . V_5 - V_28 )
* V_16 . V_29 -> V_30 ;
V_16 . V_75 . V_76 =
F_25 ;
V_69 = F_30 ( & V_16 . V_75 ) ;
if ( V_69 ) {
F_8 ( L_24 , V_69 ) ;
goto V_77;
}
V_16 . V_78 . V_79 = V_80 ;
V_16 . V_78 . V_81 = L_25 ;
V_16 . V_78 . V_82 = & V_83 ;
V_69 = F_31 ( & V_16 . V_78 ) ;
if ( V_69 ) {
F_8 ( L_26 ,
V_80 , V_69 ) ;
goto V_84;
}
V_69 = F_32 ( ( unsigned int ) V_16 . V_29 -> V_13 ,
F_9 ,
V_85 , L_25 ,
& V_16 . V_22 ) ;
if ( V_69 ) {
F_8 ( L_27 , V_69 ) ;
goto V_86;
}
F_13 () ;
return 0 ;
V_86:
F_33 ( & V_16 . V_78 ) ;
V_84:
F_34 ( & V_16 . V_75 ) ;
V_77:
F_13 () ;
F_35 ( V_16 . V_22 ) ;
return V_69 ;
}
static void T_10 F_36 ( void )
{
F_33 ( & V_16 . V_78 ) ;
F_34 ( & V_16 . V_75 ) ;
F_11 ( 0x00000002 , V_16 . V_21 ) ;
F_35 ( V_16 . V_22 ) ;
}
