static int F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
F_2 ( V_2 , V_4 + 8 , & V_3 ) ;
if ( V_3 & 0x20 ) {
F_3 ( 0 , L_1 ) ;
V_5 = 1 ;
} else {
F_3 ( 0 , L_2 ) ;
V_5 = 2 ;
}
return V_5 ;
}
static unsigned long F_4 ( T_1 log )
{
return ( log & V_6 ) >> 16 ;
}
static int F_5 ( int V_7 , T_1 log )
{
return ( ( log & V_8 ) >> 27 ) |
( V_7 * V_9 ) ;
}
static void F_6 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( V_11 -> V_2 ) ;
F_8 ( V_2 , V_12 , V_13 ,
V_13 ) ;
}
static T_1 F_9 ( const void T_2 * V_14 )
{
return F_10 ( V_14 ) | ( ( ( T_1 ) F_10 ( V_14 + 4 ) ) << 32 ) ;
}
static void F_11 ( struct V_10 * V_11 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 ;
void T_2 * V_17 = V_11 -> V_18 ;
V_2 = F_7 ( V_11 -> V_2 ) ;
F_12 ( V_2 , V_12 , & V_16 -> V_19 ) ;
if ( ! ( V_16 -> V_19 & V_13 ) )
return;
V_16 -> V_20 [ 0 ] = F_9 ( V_17 + V_21 ) ;
if ( V_5 == 2 )
V_16 -> V_20 [ 1 ] = F_9 ( V_17 + V_22 ) ;
F_12 ( V_2 , V_12 , & V_16 -> V_23 ) ;
if ( ( V_16 -> V_19 ^ V_16 -> V_23 ) & V_13 ) {
V_16 -> V_20 [ 0 ] = F_9 ( V_17 + V_21 ) ;
if ( V_5 == 2 )
V_16 -> V_20 [ 1 ] =
F_9 ( V_17 + V_22 ) ;
}
F_6 ( V_11 ) ;
}
static void F_13 ( struct V_10 * V_11 ,
struct V_15 * V_16 )
{
int V_7 ;
T_1 log ;
if ( ! ( V_16 -> V_19 & V_13 ) )
return;
if ( ( V_16 -> V_19 ^ V_16 -> V_23 ) & V_13 ) {
F_14 ( V_24 , V_11 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
L_3 , L_4 ) ;
V_16 -> V_19 = V_16 -> V_23 ;
}
for ( V_7 = 0 ; V_7 < V_5 ; V_7 ++ ) {
log = V_16 -> V_20 [ V_7 ] ;
if ( log & V_25 ) {
F_14 ( V_24 , V_11 , 1 ,
0 , 0 , 0 ,
F_5 ( V_7 , log ) ,
- 1 , - 1 ,
L_5 , L_4 ) ;
} else if ( log & V_26 ) {
F_14 ( V_27 , V_11 , 1 ,
0 , 0 , F_4 ( log ) ,
F_5 ( V_7 , log ) ,
- 1 , - 1 ,
L_6 , L_4 ) ;
}
}
}
static void F_15 ( struct V_10 * V_11 )
{
struct V_15 V_16 ;
F_3 ( 1 , L_7 , V_11 -> V_28 ) ;
F_11 ( V_11 , & V_16 ) ;
F_13 ( V_11 , & V_16 ) ;
}
static void T_2 * F_16 ( struct V_1 * V_2 )
{
union {
T_1 V_29 ;
struct {
T_3 V_30 ;
T_3 V_31 ;
};
} V_32 ;
void T_2 * V_17 ;
F_17 ( V_2 , V_33 , & V_32 . V_30 ) ;
F_18 ( V_2 , V_33 , V_32 . V_30 | 0x1 ) ;
F_17 ( V_2 , V_34 , & V_32 . V_31 ) ;
V_32 . V_29 &= V_35 ;
if ( V_32 . V_29 != ( V_36 ) V_32 . V_29 ) {
F_19 ( V_37
L_8 ,
( unsigned long long ) V_32 . V_29 ) ;
return NULL ;
}
V_17 = F_20 ( V_32 . V_29 , V_38 ) ;
if ( ! V_17 )
F_19 ( V_37 L_9 ,
( unsigned long long ) V_32 . V_29 ) ;
return V_17 ;
}
static void F_21 ( void T_2 * V_17 ,
T_4 V_39 [ V_40 ] [ V_9 ] )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_9 ; V_41 ++ ) {
V_39 [ 0 ] [ V_41 ] = F_22 ( V_17 + V_42 + 2 * V_41 ) & V_43 ;
V_39 [ 1 ] [ V_41 ] = F_22 ( V_17 + V_44 + 2 * V_41 ) & V_43 ;
}
}
static bool F_23 ( struct V_1 * V_2 ,
T_4 V_39 [ V_40 ] [ V_9 ] )
{
T_4 V_45 ;
F_12 ( V_2 , V_46 , & V_45 ) ;
V_45 &= V_47 ;
return V_39 [ V_40 - 1 ] [ V_9 - 1 ] == V_45 ;
}
static unsigned long F_24 (
T_4 V_39 [ V_40 ] [ V_9 ] ,
bool V_48 , int V_7 , int V_49 )
{
int V_50 ;
V_50 = V_39 [ V_7 ] [ V_49 ] ;
if ( V_49 > 0 )
V_50 -= V_39 [ V_7 ] [ V_49 - 1 ] ;
if ( V_48 && ( V_7 == 1 ) && V_39 [ V_7 ] [ V_49 ] ==
V_39 [ V_7 ] [ V_9 - 1 ] ) {
V_50 -= V_39 [ 0 ] [ V_9 - 1 ] ;
}
V_50 <<= ( V_51 - V_52 ) ;
return V_50 ;
}
static int F_25 ( struct V_1 * V_2 , int V_53 )
{
int V_54 ;
int V_41 , V_55 ;
struct V_10 * V_11 = NULL ;
struct V_56 V_57 [ 2 ] ;
T_4 V_39 [ V_40 ] [ V_9 ] ;
bool V_48 ;
void T_2 * V_17 ;
F_3 ( 0 , L_10 ) ;
V_17 = F_16 ( V_2 ) ;
if ( ! V_17 )
return - V_58 ;
F_21 ( V_17 , V_39 ) ;
F_1 ( V_2 ) ;
V_57 [ 0 ] . type = V_59 ;
V_57 [ 0 ] . V_60 = V_61 ;
V_57 [ 0 ] . V_62 = true ;
V_57 [ 1 ] . type = V_63 ;
V_57 [ 1 ] . V_60 = V_5 ;
V_57 [ 1 ] . V_62 = false ;
V_11 = F_26 ( 0 , F_27 ( V_57 ) , V_57 , 0 ) ;
if ( ! V_11 )
return - V_64 ;
F_3 ( 3 , L_11 ) ;
V_11 -> V_2 = & V_2 -> V_65 ;
V_11 -> V_66 = V_67 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_70 = V_69 ;
V_11 -> V_71 = V_72 ;
V_11 -> V_73 = V_74 ;
V_11 -> V_75 = V_76 [ V_53 ] . V_75 ;
V_11 -> V_77 = F_28 ( V_2 ) ;
V_11 -> V_78 = F_15 ;
V_11 -> V_79 = NULL ;
V_11 -> V_18 = V_17 ;
V_48 = F_23 ( V_2 , V_39 ) ;
for ( V_41 = 0 ; V_41 < V_11 -> V_80 ; V_41 ++ ) {
unsigned long V_81 ;
struct V_82 * V_83 = V_11 -> V_84 [ V_41 ] ;
V_81 = F_24 ( V_39 , V_48 ,
V_41 / V_9 ,
V_41 % V_9 ) ;
if ( V_81 == 0 )
continue;
for ( V_55 = 0 ; V_55 < V_5 ; V_55 ++ ) {
struct V_85 * V_86 = V_83 -> V_87 [ V_55 ] -> V_86 ;
V_86 -> V_81 = V_81 / V_5 ;
V_86 -> V_88 = V_81 << V_52 ;
V_86 -> V_89 = V_90 ;
V_86 -> V_91 = V_92 ;
V_86 -> V_93 = V_94 ;
}
}
F_6 ( V_11 ) ;
V_54 = - V_58 ;
if ( F_29 ( V_11 ) ) {
F_3 ( 3 , L_12 ) ;
goto V_95;
}
F_3 ( 3 , L_13 ) ;
return 0 ;
V_95:
F_30 ( V_17 ) ;
if ( V_11 )
F_31 ( V_11 ) ;
return V_54 ;
}
static int F_32 ( struct V_1 * V_2 , const struct V_96 * V_97 )
{
int V_54 ;
F_3 ( 0 , L_10 ) ;
if ( F_33 ( V_2 ) < 0 )
return - V_98 ;
V_54 = F_25 ( V_2 , V_97 -> V_99 ) ;
if ( ! V_100 )
V_100 = F_34 ( V_2 ) ;
return V_54 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_3 ( 0 , L_14 ) ;
V_11 = F_36 ( & V_2 -> V_65 ) ;
if ( ! V_11 )
return;
F_30 ( V_11 -> V_18 ) ;
F_31 ( V_11 ) ;
}
static int T_5 F_37 ( void )
{
int V_101 ;
F_3 ( 3 , L_10 ) ;
F_38 () ;
V_101 = F_39 ( & V_102 ) ;
if ( V_101 < 0 )
goto V_103;
if ( ! V_100 ) {
V_104 = 0 ;
V_100 = F_40 ( V_105 ,
V_106 , NULL ) ;
if ( ! V_100 ) {
F_3 ( 0 , L_15 ) ;
V_101 = - V_58 ;
goto V_107;
}
V_101 = F_32 ( V_100 , V_108 ) ;
if ( V_101 < 0 ) {
F_3 ( 0 , L_16 ) ;
V_101 = - V_58 ;
goto V_107;
}
}
return 0 ;
V_107:
F_41 ( & V_102 ) ;
V_103:
if ( V_100 )
F_42 ( V_100 ) ;
return V_101 ;
}
static void T_6 F_43 ( void )
{
F_3 ( 3 , L_10 ) ;
F_41 ( & V_102 ) ;
if ( ! V_104 ) {
F_35 ( V_100 ) ;
F_42 ( V_100 ) ;
}
}
