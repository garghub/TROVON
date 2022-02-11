static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( V_3 == NULL )
return NULL ;
V_4 = F_2 ( V_3 -> V_5 -> V_6 ) ;
if ( V_4 == NULL ) {
F_3 ( & V_3 -> V_3 , L_1 ) ;
return NULL ;
}
if ( V_3 -> V_7 >= V_8 ) {
F_3 ( & V_3 -> V_3 ,
L_2 ,
V_3 -> V_5 -> V_9 , V_3 -> V_7 , V_8 - 1 ) ;
return NULL ;
}
return V_4 ;
}
static void F_4 ( struct V_1 * V_4 ,
T_1 T_2 * V_10 , T_3 V_11 )
{
unsigned long V_12 ;
F_5 ( & V_4 -> V_13 , V_12 ) ;
F_6 ( F_7 ( V_10 ) & ( ~ V_11 ) , V_10 ) ;
F_8 ( & V_4 -> V_13 , V_12 ) ;
}
static void F_9 ( struct V_1 * V_4 ,
T_1 T_2 * V_10 , T_3 V_11 )
{
unsigned long V_12 ;
F_5 ( & V_4 -> V_13 , V_12 ) ;
F_6 ( F_7 ( V_10 ) | V_11 , V_10 ) ;
F_8 ( & V_4 -> V_13 , V_12 ) ;
}
static void F_10 ( struct V_1 * V_4 )
{
F_11 ( V_4 -> V_14 -> V_15 -> V_16 , ( void * ) V_4 ) ;
F_12 ( V_4 -> V_14 -> V_15 , V_4 -> V_14 -> V_17 ) ;
F_12 ( V_4 -> V_14 -> V_15 , V_4 -> V_14 -> V_18 ) ;
F_13 ( V_4 -> V_14 -> V_15 , V_19 ) ;
F_13 ( V_4 -> V_14 -> V_15 , V_20 ) ;
F_13 ( V_4 -> V_14 -> V_15 , V_21 ) ;
F_13 ( V_4 -> V_14 -> V_15 , V_22 ) ;
F_13 ( V_4 -> V_14 -> V_15 , V_23 ) ;
F_14 ( V_4 -> V_14 -> V_15 ) ;
F_15 ( V_4 -> V_14 -> V_15 ) ;
}
static void F_16 ( struct V_1 * V_4 ,
int V_24 )
{
F_9 ( V_4 ,
& V_4 -> V_14 -> V_17 -> V_25 [ V_24 ] ,
V_26 | V_27 ) ;
}
static void F_17 ( struct V_1 * V_4 ,
int V_24 )
{
F_4 ( V_4 ,
& V_4 -> V_14 -> V_17 -> V_25 [ V_24 ] ,
V_26 | V_27 ) ;
}
static T_4 F_18 ( struct V_28 * V_28 )
{
T_4 V_29 ;
if ( ! V_28 )
return - V_30 ;
V_29 = V_28 -> V_31 ( V_28 -> V_32 ) ;
return V_29 ;
}
static T_4 F_19 ( int V_16 , void * V_33 )
{
struct V_1 * V_4 = (struct V_1 * ) V_33 ;
struct V_28 * V_28 ;
T_4 V_29 ;
T_3 V_34 ;
int V_35 ;
V_34 = F_7 ( & V_4 -> V_14 -> V_17 -> V_36 ) ;
if ( ! ( V_34 & V_37 ) )
return V_38 ;
F_20 () ;
for ( V_35 = 0 ; V_35 < V_8 ; V_35 ++ ) {
if ( ! ( V_34 & ( ( V_39 | V_40 ) << ( 2 * V_35 ) ) ) )
continue;
V_28 = F_21 ( V_4 -> V_41 [ V_35 ] . V_16 ) ;
V_29 = F_18 ( V_28 ) ;
if ( V_29 == - V_30 ) {
F_3 ( & V_4 -> V_14 -> V_15 -> V_3 ,
L_3 ,
V_4 -> V_42 , V_35 ) ;
F_17 ( V_4 , V_35 ) ;
}
}
F_22 () ;
return V_43 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_28 * V_28 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_44 ;
if ( F_24 ( & V_4 -> V_45 ) )
return - V_46 ;
if ( V_4 -> V_41 [ V_3 -> V_7 ] . V_16 == NULL ) {
F_25 ( & V_4 -> V_45 ) ;
return - V_44 ;
}
F_17 ( V_4 , V_3 -> V_7 ) ;
V_28 = V_4 -> V_41 [ V_3 -> V_7 ] . V_16 ;
F_26 ( V_4 -> V_41 [ V_3 -> V_7 ] . V_16 , NULL ) ;
F_27 () ;
F_28 ( V_28 ) ;
F_25 ( & V_4 -> V_45 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 ,
T_4 (* V_31)( void * ) , void * V_32 )
{
int V_47 = 0 ;
struct V_28 * V_28 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_44 ;
if ( F_24 ( & V_4 -> V_45 ) )
return - V_46 ;
if ( V_4 -> V_41 [ V_3 -> V_7 ] . V_16 != NULL ) {
F_30 ( & V_3 -> V_3 ,
L_4 ,
V_3 -> V_5 -> V_9 ,
V_3 -> V_7 ) ;
V_47 = - V_44 ;
goto V_48;
}
V_28 = F_31 ( sizeof( struct V_28 ) , V_49 ) ;
if ( V_28 == NULL ) {
F_30 ( & V_3 -> V_3 ,
L_5 ,
V_3 -> V_5 -> V_9 , V_3 -> V_7 ) ;
V_47 = - V_50 ;
goto V_48;
}
V_28 -> V_31 = V_31 ;
V_28 -> V_32 = V_32 ;
V_28 -> V_51 = V_3 ;
F_32 ( V_4 -> V_41 [ V_3 -> V_7 ] . V_16 , V_28 ) ;
F_16 ( V_4 , V_3 -> V_7 ) ;
V_48:
F_25 ( & V_4 -> V_45 ) ;
return V_47 ;
}
static int F_33 ( struct V_1 * V_4 )
{
int V_35 ;
int V_47 ;
T_5 V_52 ;
unsigned short V_53 ;
if ( F_34 ( V_4 -> V_14 -> V_15 ) < 0 )
return - V_30 ;
V_47 = F_35 ( V_4 -> V_14 -> V_15 , V_19 ,
L_6 ) ;
if ( V_47 ) {
F_30 ( & V_4 -> V_14 -> V_15 -> V_3 ,
L_7 ,
V_4 -> V_14 -> V_15 -> V_5 -> V_42 ,
V_4 -> V_14 -> V_15 -> V_54 ) ;
goto V_55;
}
V_47 = F_35 ( V_4 -> V_14 -> V_15 ,
V_20 ,
L_8 ) ;
if ( V_47 ) {
F_30 ( & V_4 -> V_14 -> V_15 -> V_3 ,
L_9 ,
V_4 -> V_14 -> V_15 -> V_5 -> V_42 ,
V_4 -> V_14 -> V_15 -> V_54 ) ;
goto V_56;
}
V_47 = F_35 ( V_4 -> V_14 -> V_15 , V_22 ,
L_10 ) ;
if ( V_47 ) {
F_30 ( & V_4 -> V_14 -> V_15 -> V_3 ,
L_11 ,
V_4 -> V_14 -> V_15 -> V_5 -> V_42 ,
V_4 -> V_14 -> V_15 -> V_54 ) ;
goto V_57;
}
V_47 = F_35 ( V_4 -> V_14 -> V_15 , V_21 ,
L_12 ) ;
if ( V_47 ) {
F_30 ( & V_4 -> V_14 -> V_15 -> V_3 ,
L_13 ,
V_4 -> V_14 -> V_15 -> V_5 -> V_42 ,
V_4 -> V_14 -> V_15 -> V_54 ) ;
goto V_58;
}
V_4 -> V_14 -> V_17 =
F_36 ( F_37 ( V_4 -> V_14 -> V_15 ,
V_19 ) ,
V_59 ) ;
F_38 ( & V_4 -> V_13 ) ;
V_52 = F_37 ( V_4 -> V_14 -> V_15 ,
V_20 ) ;
V_4 -> V_60 [ V_61 ] = V_52 + V_62 ;
V_4 -> V_60 [ V_63 ] = V_52 + V_64 ;
V_4 -> V_60 [ V_65 ] =
V_52 + V_66 ;
V_4 -> V_60 [ V_67 ] =
F_37 ( V_4 -> V_14 -> V_15 ,
V_22 ) ;
V_4 -> V_60 [ V_68 ] =
F_37 ( V_4 -> V_14 -> V_15 ,
V_21 ) ;
V_53 = 0 ;
for ( V_35 = 0 ; V_35 < V_8 ; V_35 ++ )
F_39 ( V_53 , & V_4 -> V_14 -> V_17 -> V_25 [ V_35 ] ) ;
V_47 = F_40 ( V_4 -> V_14 -> V_15 -> V_16 ,
F_19 , V_69 ,
V_70 , ( void * ) V_4 ) ;
if ( V_47 ) {
F_30 ( & V_4 -> V_14 -> V_15 -> V_3 ,
L_14 ,
V_4 -> V_14 -> V_15 -> V_5 -> V_42 ,
V_4 -> V_14 -> V_15 -> V_54 ) ;
goto V_57;
}
return 0 ;
V_58:
F_13 ( V_4 -> V_14 -> V_15 , V_22 ) ;
V_57:
F_13 ( V_4 -> V_14 -> V_15 , V_20 ) ;
V_56:
F_13 ( V_4 -> V_14 -> V_15 , V_19 ) ;
V_55:
F_14 ( V_4 -> V_14 -> V_15 ) ;
return V_47 ;
}
static int F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 T_2 * V_10 ;
if ( ! V_4 )
return - V_30 ;
V_10 = & V_4 -> V_14 -> V_17 -> V_25 [ V_3 -> V_7 ] ;
return ( F_7 ( V_10 ) & V_71 ) ? 32 : 8 ;
}
static int F_42 ( struct V_2 * V_3 , int V_72 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 T_2 * V_10 ;
if ( ! V_4 )
return - V_30 ;
V_10 = & V_4 -> V_14 -> V_17 -> V_25 [ V_3 -> V_7 ] ;
switch ( V_72 ) {
case 8 :
F_4 ( V_4 , V_10 , V_71 ) ;
break;
case 32 :
F_9 ( V_4 , V_10 , V_71 ) ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 T_2 * V_10 ;
T_3 V_11 ;
if ( ! V_4 )
return - V_30 ;
V_10 = & V_4 -> V_14 -> V_17 -> V_36 ;
V_11 = V_73 [ V_3 -> V_7 ] ;
return ( F_7 ( V_10 ) & V_11 ) ? 1 : 0 ;
}
static int F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 T_2 * V_10 ;
T_3 V_11 ;
if ( ! V_4 )
return - V_30 ;
V_10 = & V_4 -> V_14 -> V_17 -> V_36 ;
V_11 = V_74 [ V_3 -> V_7 ] ;
return ( F_7 ( V_10 ) & V_11 ) ? 1 : 0 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 T_2 * V_10 ;
T_3 V_11 ;
if ( ! V_4 )
return - V_30 ;
V_10 = & V_4 -> V_14 -> V_17 -> V_36 ;
V_11 = V_74 [ V_3 -> V_7 ] ;
F_6 ( V_11 , V_10 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_4 )
{
F_10 ( V_4 ) ;
F_28 ( V_4 -> V_41 ) ;
}
static int F_47 ( struct V_1 * V_4 )
{
int V_47 ;
V_4 -> V_41 = F_31 (
V_8 * sizeof( struct V_75 ) , V_49 ) ;
if ( V_4 -> V_41 == NULL )
return - V_50 ;
V_47 = F_33 ( V_4 ) ;
if ( V_47 ) {
F_28 ( V_4 -> V_41 ) ;
V_4 -> V_41 = NULL ;
return V_47 ;
}
F_48 ( & V_4 -> V_45 ) ;
return 0 ;
}
static void F_49 ( struct V_2 * V_3 )
{
F_28 ( V_3 ) ;
}
static int F_50 ( struct V_1 * V_4 , int V_35 )
{
enum V_76 V_77 ;
struct V_2 * V_3 =
F_31 ( sizeof( struct V_2 ) , V_49 ) ;
if ( ! V_3 )
return - V_50 ;
V_3 -> V_7 = V_35 ;
V_3 -> V_5 = V_4 -> V_14 -> V_78 ;
V_3 -> V_79 = F_49 ;
for ( V_77 = 0 ; V_77 < V_80 ; V_77 ++ ) {
V_3 -> V_81 [ V_77 ] . V_82 =
V_4 -> V_60 [ V_77 ]
+ V_83 [ V_77 ] * V_35 ;
V_3 -> V_81 [ V_77 ] . V_84 = V_85 [ V_77 ] ;
}
return F_51 ( V_3 ) ;
}
static int F_52 ( struct V_86 * V_15 ,
const struct V_87 * V_88 )
{
int V_29 , V_35 ;
struct V_1 * V_4 ;
T_6 V_89 ;
V_4 = F_31 ( sizeof( struct V_1 ) , V_49 ) ;
if ( ! V_4 )
return - V_50 ;
V_4 -> V_14 = F_31 ( sizeof( struct V_90 ) , V_49 ) ;
if ( ! V_4 -> V_14 ) {
V_29 = - V_50 ;
goto V_91;
}
F_53 ( V_15 ) ;
V_29 = F_35 ( V_15 , V_23 ,
V_70 L_15 ) ;
if ( V_29 ) {
F_30 ( & V_15 -> V_3 , L_16 ) ;
V_29 = - V_92 ;
goto V_93;
}
V_4 -> V_14 -> V_18 = F_36 (
F_37 ( V_15 , V_23 ) ,
F_54 ( V_15 , V_23 ) ) ;
if ( ! V_4 -> V_14 -> V_18 ) {
F_30 ( & V_15 -> V_3 , L_17 ) ;
V_29 = - V_94 ;
goto V_95;
}
V_89 = F_55 ( V_4 -> V_14 -> V_18 + V_96 ) ;
V_89 |= 1 << V_97 ;
F_56 ( V_89 , V_4 -> V_14 -> V_18 + V_96 ) ;
V_89 = F_55 ( V_4 -> V_14 -> V_18 + V_98 ) ;
V_89 |= 1 << V_97 ;
F_56 ( V_89 , V_4 -> V_14 -> V_18 + V_98 ) ;
V_4 -> V_14 -> V_15 = V_15 ;
V_4 -> V_14 -> V_99 = (struct V_87 * ) V_88 ;
V_29 = F_47 ( V_4 ) ;
if ( V_29 ) {
F_30 ( & V_15 -> V_3 , L_18 ) ;
V_29 = - V_30 ;
goto V_100;
}
V_4 -> V_14 -> V_78 = F_57 ( & V_15 -> V_3 ,
V_8 ,
& V_101 ) ;
if ( ! V_4 -> V_14 -> V_78 ) {
F_30 ( & V_15 -> V_3 ,
L_19 ) ;
V_29 = - V_94 ;
goto V_102;
}
V_4 -> V_42 = V_4 -> V_14 -> V_78 -> V_9 ;
F_58 ( & V_15 -> V_3 , V_4 ) ;
for ( V_35 = 0 ; V_35 < V_8 ; V_35 ++ )
F_50 ( V_4 , V_35 ) ;
return 0 ;
V_102:
F_46 ( V_4 ) ;
V_100:
F_59 ( V_4 -> V_14 -> V_18 ) ;
V_95:
F_13 ( V_15 , V_23 ) ;
V_93:
F_15 ( V_15 ) ;
F_28 ( V_4 -> V_14 ) ;
V_91:
F_28 ( V_4 ) ;
return V_29 ;
}
static void F_60 ( struct V_1 * V_4 )
{
F_61 ( V_4 -> V_14 -> V_78 ) ;
F_46 ( V_4 ) ;
F_28 ( V_4 -> V_14 ) ;
F_28 ( V_4 ) ;
}
static void F_62 ( struct V_86 * V_3 )
{
struct V_1 * V_4 = F_63 ( V_3 ) ;
F_60 ( V_4 ) ;
}
