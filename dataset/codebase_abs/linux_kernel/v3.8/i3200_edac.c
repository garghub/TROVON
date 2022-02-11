static int F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
F_2 ( V_2 , V_4 + 8 , & V_3 ) ;
if ( V_3 & 0x20 ) {
F_3 ( 0 , L_1 ) ;
return 1 ;
} else {
F_3 ( 0 , L_2 ) ;
return 2 ;
}
}
static unsigned long F_4 ( T_1 log )
{
return ( log & V_5 ) >>
V_6 ;
}
static int F_5 ( int V_7 , T_1 log )
{
T_1 V_8 = ( ( log & V_9 ) >>
V_10 ) ;
return V_8 | ( V_7 * V_11 ) ;
}
static void F_6 ( struct V_12 * V_13 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( V_13 -> V_2 ) ;
F_8 ( V_2 , V_14 , V_15 ,
V_15 ) ;
}
static void F_9 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 = V_13 -> V_20 ;
void T_2 * V_21 = V_19 -> V_21 ;
V_2 = F_7 ( V_13 -> V_2 ) ;
F_10 ( V_2 , V_14 , & V_17 -> V_22 ) ;
if ( ! ( V_17 -> V_22 & V_15 ) )
return;
V_17 -> V_23 [ 0 ] = F_11 ( V_21 + V_24 ) ;
if ( V_25 == 2 )
V_17 -> V_23 [ 1 ] = F_11 ( V_21 + V_26 ) ;
F_10 ( V_2 , V_14 , & V_17 -> V_27 ) ;
if ( ( V_17 -> V_22 ^ V_17 -> V_27 ) & V_15 ) {
V_17 -> V_23 [ 0 ] = F_11 ( V_21 + V_24 ) ;
if ( V_25 == 2 )
V_17 -> V_23 [ 1 ] = F_11 ( V_21 + V_26 ) ;
}
F_6 ( V_13 ) ;
}
static void F_12 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
int V_7 ;
T_1 log ;
if ( ! ( V_17 -> V_22 & V_15 ) )
return;
if ( ( V_17 -> V_22 ^ V_17 -> V_27 ) & V_15 ) {
F_13 ( V_28 , V_13 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 , L_3 , L_4 ) ;
V_17 -> V_22 = V_17 -> V_27 ;
}
for ( V_7 = 0 ; V_7 < V_25 ; V_7 ++ ) {
log = V_17 -> V_23 [ V_7 ] ;
if ( log & V_29 ) {
F_13 ( V_28 , V_13 , 1 ,
0 , 0 , 0 ,
F_5 ( V_7 , log ) ,
- 1 , - 1 ,
L_5 , L_4 ) ;
} else if ( log & V_30 ) {
F_13 ( V_28 , V_13 , 1 ,
0 , 0 , F_4 ( log ) ,
F_5 ( V_7 , log ) ,
- 1 , - 1 ,
L_5 , L_4 ) ;
}
}
}
static void F_14 ( struct V_12 * V_13 )
{
struct V_16 V_17 ;
F_3 ( 1 , L_6 , V_13 -> V_31 ) ;
F_9 ( V_13 , & V_17 ) ;
F_12 ( V_13 , & V_17 ) ;
}
void T_2 * F_15 ( struct V_1 * V_2 )
{
union {
T_1 V_32 ;
struct {
T_3 V_33 ;
T_3 V_34 ;
};
} V_35 ;
void T_2 * V_21 ;
F_16 ( V_2 , V_36 , & V_35 . V_33 ) ;
F_16 ( V_2 , V_37 , & V_35 . V_34 ) ;
V_35 . V_32 &= V_38 ;
if ( V_35 . V_32 != ( V_39 ) V_35 . V_32 ) {
F_17 ( V_40
L_7 ,
( unsigned long long ) V_35 . V_32 ) ;
return NULL ;
}
V_21 = F_18 ( V_35 . V_32 , V_41 ) ;
if ( ! V_21 )
F_17 ( V_40 L_8 ,
( unsigned long long ) V_35 . V_32 ) ;
return V_21 ;
}
static void F_19 ( void T_2 * V_21 ,
T_4 V_42 [ V_43 ] [ V_11 ] )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_11 ; V_44 ++ ) {
V_42 [ 0 ] [ V_44 ] = F_20 ( V_21 + V_45 + 2 * V_44 ) & V_46 ;
V_42 [ 1 ] [ V_44 ] = F_20 ( V_21 + V_47 + 2 * V_44 ) & V_46 ;
}
}
static bool F_21 ( struct V_1 * V_2 ,
T_4 V_42 [ V_43 ] [ V_11 ] )
{
T_4 V_48 ;
F_10 ( V_2 , V_49 , & V_48 ) ;
V_48 &= V_50 ;
return V_42 [ V_43 - 1 ] [ V_11 - 1 ] == V_48 ;
}
static unsigned long F_22 (
T_4 V_42 [ V_43 ] [ V_11 ] , bool V_51 ,
int V_7 , int V_8 )
{
int V_52 ;
V_52 = V_42 [ V_7 ] [ V_8 ] ;
if ( V_8 > 0 )
V_52 -= V_42 [ V_7 ] [ V_8 - 1 ] ;
if ( V_51 && ( V_7 == 1 ) &&
V_42 [ V_7 ] [ V_8 ] == V_42 [ V_7 ] [ V_11 - 1 ] )
V_52 -= V_42 [ 0 ] [ V_11 - 1 ] ;
V_52 <<= ( V_53 - V_54 ) ;
return V_52 ;
}
static int F_23 ( struct V_1 * V_2 , int V_55 )
{
int V_56 ;
int V_44 , V_57 ;
struct V_12 * V_13 = NULL ;
struct V_58 V_59 [ 2 ] ;
T_4 V_42 [ V_43 ] [ V_11 ] ;
bool V_51 ;
void T_2 * V_21 ;
struct V_18 * V_19 ;
F_3 ( 0 , L_9 ) ;
V_21 = F_15 ( V_2 ) ;
if ( ! V_21 )
return - V_60 ;
F_19 ( V_21 , V_42 ) ;
V_25 = F_1 ( V_2 ) ;
V_59 [ 0 ] . type = V_61 ;
V_59 [ 0 ] . V_62 = V_63 ;
V_59 [ 0 ] . V_64 = true ;
V_59 [ 1 ] . type = V_65 ;
V_59 [ 1 ] . V_62 = V_25 ;
V_59 [ 1 ] . V_64 = false ;
V_13 = F_24 ( 0 , F_25 ( V_59 ) , V_59 ,
sizeof( struct V_18 ) ) ;
if ( ! V_13 )
return - V_66 ;
F_3 ( 3 , L_10 ) ;
V_13 -> V_2 = & V_2 -> V_67 ;
V_13 -> V_68 = V_69 ;
V_13 -> V_70 = V_71 ;
V_13 -> V_72 = V_71 ;
V_13 -> V_73 = V_74 ;
V_13 -> V_75 = V_76 ;
V_13 -> V_77 = V_78 [ V_55 ] . V_77 ;
V_13 -> V_79 = F_26 ( V_2 ) ;
V_13 -> V_80 = F_14 ;
V_13 -> V_81 = NULL ;
V_19 = V_13 -> V_20 ;
V_19 -> V_21 = V_21 ;
V_51 = F_21 ( V_2 , V_42 ) ;
for ( V_44 = 0 ; V_44 < V_13 -> V_82 ; V_44 ++ ) {
unsigned long V_83 ;
struct V_84 * V_85 = V_13 -> V_86 [ V_44 ] ;
V_83 = F_22 ( V_42 , V_51 ,
V_44 / V_11 ,
V_44 % V_11 ) ;
if ( V_83 == 0 )
continue;
for ( V_57 = 0 ; V_57 < V_25 ; V_57 ++ ) {
struct V_87 * V_88 = V_85 -> V_89 [ V_57 ] -> V_88 ;
V_88 -> V_83 = V_83 ;
V_88 -> V_90 = V_83 << V_54 ;
V_88 -> V_91 = V_92 ;
V_88 -> V_93 = V_94 ;
V_88 -> V_95 = V_96 ;
}
}
F_6 ( V_13 ) ;
V_56 = - V_60 ;
if ( F_27 ( V_13 ) ) {
F_3 ( 3 , L_11 ) ;
goto V_97;
}
F_3 ( 3 , L_12 ) ;
return 0 ;
V_97:
F_28 ( V_21 ) ;
if ( V_13 )
F_29 ( V_13 ) ;
return V_56 ;
}
static int F_30 ( struct V_1 * V_2 , const struct V_98 * V_99 )
{
int V_56 ;
F_3 ( 0 , L_9 ) ;
if ( F_31 ( V_2 ) < 0 )
return - V_100 ;
V_56 = F_23 ( V_2 , V_99 -> V_101 ) ;
if ( ! V_102 )
V_102 = F_32 ( V_2 ) ;
return V_56 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_18 * V_19 ;
F_3 ( 0 , L_13 ) ;
V_13 = F_34 ( & V_2 -> V_67 ) ;
if ( ! V_13 )
return;
V_19 = V_13 -> V_20 ;
F_28 ( V_19 -> V_21 ) ;
F_29 ( V_13 ) ;
}
static int T_5 F_35 ( void )
{
int V_103 ;
F_3 ( 3 , L_9 ) ;
F_36 () ;
V_103 = F_37 ( & V_104 ) ;
if ( V_103 < 0 )
goto V_105;
if ( ! V_102 ) {
V_106 = 0 ;
V_102 = F_38 ( V_107 ,
V_108 , NULL ) ;
if ( ! V_102 ) {
F_3 ( 0 , L_14 ) ;
V_103 = - V_60 ;
goto V_109;
}
V_103 = F_30 ( V_102 , V_110 ) ;
if ( V_103 < 0 ) {
F_3 ( 0 , L_15 ) ;
V_103 = - V_60 ;
goto V_109;
}
}
return 0 ;
V_109:
F_39 ( & V_104 ) ;
V_105:
if ( V_102 )
F_40 ( V_102 ) ;
return V_103 ;
}
static void T_6 F_41 ( void )
{
F_3 ( 3 , L_9 ) ;
F_39 ( & V_104 ) ;
if ( ! V_106 ) {
F_33 ( V_102 ) ;
F_40 ( V_102 ) ;
}
}
