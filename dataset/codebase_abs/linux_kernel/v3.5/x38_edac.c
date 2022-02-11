static int F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
F_2 ( V_2 , V_4 + 8 , & V_3 ) ;
if ( V_3 & 0x20 ) {
F_3 ( L_1 ) ;
V_5 = 1 ;
} else {
F_3 ( L_2 ) ;
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
V_2 = F_7 ( V_11 -> V_12 ) ;
F_8 ( V_2 , V_13 , V_14 ,
V_14 ) ;
}
static T_1 F_9 ( const void T_2 * V_15 )
{
return F_10 ( V_15 ) | ( ( ( T_1 ) F_10 ( V_15 + 4 ) ) << 32 ) ;
}
static void F_11 ( struct V_10 * V_11 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 ;
void T_2 * V_18 = V_11 -> V_19 ;
V_2 = F_7 ( V_11 -> V_12 ) ;
F_12 ( V_2 , V_13 , & V_17 -> V_20 ) ;
if ( ! ( V_17 -> V_20 & V_14 ) )
return;
V_17 -> V_21 [ 0 ] = F_9 ( V_18 + V_22 ) ;
if ( V_5 == 2 )
V_17 -> V_21 [ 1 ] = F_9 ( V_18 + V_23 ) ;
F_12 ( V_2 , V_13 , & V_17 -> V_24 ) ;
if ( ( V_17 -> V_20 ^ V_17 -> V_24 ) & V_14 ) {
V_17 -> V_21 [ 0 ] = F_9 ( V_18 + V_22 ) ;
if ( V_5 == 2 )
V_17 -> V_21 [ 1 ] =
F_9 ( V_18 + V_23 ) ;
}
F_6 ( V_11 ) ;
}
static void F_13 ( struct V_10 * V_11 ,
struct V_16 * V_17 )
{
int V_7 ;
T_1 log ;
if ( ! ( V_17 -> V_20 & V_14 ) )
return;
if ( ( V_17 -> V_20 ^ V_17 -> V_24 ) & V_14 ) {
F_14 ( V_25 , V_11 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
L_3 , L_4 , NULL ) ;
V_17 -> V_20 = V_17 -> V_24 ;
}
for ( V_7 = 0 ; V_7 < V_5 ; V_7 ++ ) {
log = V_17 -> V_21 [ V_7 ] ;
if ( log & V_26 ) {
F_14 ( V_25 , V_11 ,
0 , 0 , 0 ,
F_5 ( V_7 , log ) ,
- 1 , - 1 ,
L_5 , L_4 , NULL ) ;
} else if ( log & V_27 ) {
F_14 ( V_28 , V_11 ,
0 , 0 , F_4 ( log ) ,
F_5 ( V_7 , log ) ,
- 1 , - 1 ,
L_6 , L_4 , NULL ) ;
}
}
}
static void F_15 ( struct V_10 * V_11 )
{
struct V_16 V_17 ;
F_16 ( L_7 , V_11 -> V_29 , V_30 ) ;
F_11 ( V_11 , & V_17 ) ;
F_13 ( V_11 , & V_17 ) ;
}
void T_2 * F_17 ( struct V_1 * V_2 )
{
union {
T_1 V_31 ;
struct {
T_3 V_32 ;
T_3 V_33 ;
};
} V_34 ;
void T_2 * V_18 ;
F_18 ( V_2 , V_35 , & V_34 . V_32 ) ;
F_19 ( V_2 , V_35 , V_34 . V_32 | 0x1 ) ;
F_18 ( V_2 , V_36 , & V_34 . V_33 ) ;
V_34 . V_31 &= V_37 ;
if ( V_34 . V_31 != ( V_38 ) V_34 . V_31 ) {
F_20 ( V_39
L_8 ,
( unsigned long long ) V_34 . V_31 ) ;
return NULL ;
}
V_18 = F_21 ( V_34 . V_31 , V_40 ) ;
if ( ! V_18 )
F_20 ( V_39 L_9 ,
( unsigned long long ) V_34 . V_31 ) ;
return V_18 ;
}
static void F_22 ( void T_2 * V_18 ,
T_4 V_41 [ V_42 ] [ V_9 ] )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_9 ; V_43 ++ ) {
V_41 [ 0 ] [ V_43 ] = F_23 ( V_18 + V_44 + 2 * V_43 ) & V_45 ;
V_41 [ 1 ] [ V_43 ] = F_23 ( V_18 + V_46 + 2 * V_43 ) & V_45 ;
}
}
static bool F_24 ( struct V_1 * V_2 ,
T_4 V_41 [ V_42 ] [ V_9 ] )
{
T_4 V_47 ;
F_12 ( V_2 , V_48 , & V_47 ) ;
V_47 &= V_49 ;
return V_41 [ V_42 - 1 ] [ V_9 - 1 ] == V_47 ;
}
static unsigned long F_25 (
T_4 V_41 [ V_42 ] [ V_9 ] ,
bool V_50 , int V_7 , int V_51 )
{
int V_52 ;
V_52 = V_41 [ V_7 ] [ V_51 ] ;
if ( V_51 > 0 )
V_52 -= V_41 [ V_7 ] [ V_51 - 1 ] ;
if ( V_50 && ( V_7 == 1 ) && V_41 [ V_7 ] [ V_51 ] ==
V_41 [ V_7 ] [ V_9 - 1 ] ) {
V_52 -= V_41 [ 0 ] [ V_9 - 1 ] ;
}
V_52 <<= ( V_53 - V_54 ) ;
return V_52 ;
}
static int F_26 ( struct V_1 * V_2 , int V_55 )
{
int V_56 ;
int V_43 , V_57 ;
struct V_10 * V_11 = NULL ;
struct V_58 V_59 [ 2 ] ;
T_4 V_41 [ V_42 ] [ V_9 ] ;
bool V_50 ;
void T_2 * V_18 ;
F_3 ( L_10 , V_30 ) ;
V_18 = F_17 ( V_2 ) ;
if ( ! V_18 )
return - V_60 ;
F_22 ( V_18 , V_41 ) ;
F_1 ( V_2 ) ;
V_59 [ 0 ] . type = V_61 ;
V_59 [ 0 ] . V_62 = V_63 ;
V_59 [ 0 ] . V_64 = true ;
V_59 [ 1 ] . type = V_65 ;
V_59 [ 1 ] . V_62 = V_5 ;
V_59 [ 1 ] . V_64 = false ;
V_11 = F_27 ( 0 , F_28 ( V_59 ) , V_59 , 0 ) ;
if ( ! V_11 )
return - V_66 ;
F_29 ( L_11 , V_30 ) ;
V_11 -> V_12 = & V_2 -> V_12 ;
V_11 -> V_67 = V_68 ;
V_11 -> V_69 = V_70 ;
V_11 -> V_71 = V_70 ;
V_11 -> V_72 = V_73 ;
V_11 -> V_74 = V_75 ;
V_11 -> V_76 = V_77 [ V_55 ] . V_76 ;
V_11 -> V_78 = F_30 ( V_2 ) ;
V_11 -> V_79 = F_15 ;
V_11 -> V_80 = NULL ;
V_11 -> V_19 = V_18 ;
V_50 = F_24 ( V_2 , V_41 ) ;
for ( V_43 = 0 ; V_43 < V_11 -> V_81 ; V_43 ++ ) {
unsigned long V_82 ;
struct V_83 * V_84 = & V_11 -> V_85 [ V_43 ] ;
V_82 = F_25 ( V_41 , V_50 ,
V_43 / V_9 ,
V_43 % V_9 ) ;
if ( V_82 == 0 )
continue;
for ( V_57 = 0 ; V_57 < V_5 ; V_57 ++ ) {
struct V_86 * V_87 = V_84 -> V_88 [ V_57 ] . V_87 ;
V_87 -> V_82 = V_82 / V_5 ;
V_87 -> V_89 = V_82 << V_54 ;
V_87 -> V_90 = V_91 ;
V_87 -> V_92 = V_93 ;
V_87 -> V_94 = V_95 ;
}
}
F_6 ( V_11 ) ;
V_56 = - V_60 ;
if ( F_31 ( V_11 ) ) {
F_29 ( L_12 , V_30 ) ;
goto V_96;
}
F_29 ( L_13 , V_30 ) ;
return 0 ;
V_96:
F_32 ( V_18 ) ;
if ( V_11 )
F_33 ( V_11 ) ;
return V_56 ;
}
static int T_5 F_34 ( struct V_1 * V_2 ,
const struct V_97 * V_98 )
{
int V_56 ;
F_3 ( L_10 , V_30 ) ;
if ( F_35 ( V_2 ) < 0 )
return - V_99 ;
V_56 = F_26 ( V_2 , V_98 -> V_100 ) ;
if ( ! V_101 )
V_101 = F_36 ( V_2 ) ;
return V_56 ;
}
static void T_6 F_37 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_3 ( L_14 , V_30 ) ;
V_11 = F_38 ( & V_2 -> V_12 ) ;
if ( ! V_11 )
return;
F_32 ( V_11 -> V_19 ) ;
F_33 ( V_11 ) ;
}
static int T_7 F_39 ( void )
{
int V_102 ;
F_29 ( L_10 , V_30 ) ;
F_40 () ;
V_102 = F_41 ( & V_103 ) ;
if ( V_102 < 0 )
goto V_104;
if ( ! V_101 ) {
V_105 = 0 ;
V_101 = F_42 ( V_106 ,
V_107 , NULL ) ;
if ( ! V_101 ) {
F_3 ( L_15 ) ;
V_102 = - V_60 ;
goto V_108;
}
V_102 = F_34 ( V_101 , V_109 ) ;
if ( V_102 < 0 ) {
F_3 ( L_16 ) ;
V_102 = - V_60 ;
goto V_108;
}
}
return 0 ;
V_108:
F_43 ( & V_103 ) ;
V_104:
if ( V_101 )
F_44 ( V_101 ) ;
return V_102 ;
}
static void T_8 F_45 ( void )
{
F_29 ( L_10 , V_30 ) ;
F_43 ( & V_103 ) ;
if ( ! V_105 ) {
F_37 ( V_101 ) ;
F_44 ( V_101 ) ;
}
}
