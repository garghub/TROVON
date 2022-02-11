static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned char V_4 ;
F_2 ( V_2 , V_5 + 8 , & V_4 ) ;
if ( V_4 & 0x20 ) {
F_3 ( 0 , L_1 ) ;
V_3 = 1 ;
} else {
F_3 ( 0 , L_2 ) ;
V_3 = 2 ;
}
if ( V_4 & 0x10 )
F_3 ( 0 , L_3 ) ;
else
F_3 ( 0 , L_4 ) ;
return V_3 ;
}
static unsigned long F_4 ( T_1 log )
{
return ( log & V_6 ) >>
V_7 ;
}
static int F_5 ( int V_8 , T_1 log )
{
T_1 V_9 = ( ( log & V_10 ) >>
V_11 ) ;
return V_9 | ( V_8 * V_12 ) ;
}
static void F_6 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( V_14 -> V_2 ) ;
F_8 ( V_2 , V_15 , V_16 ,
V_16 ) ;
}
static void F_9 ( struct V_13 * V_14 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 = V_14 -> V_21 ;
void T_2 * V_22 = V_20 -> V_22 ;
V_2 = F_7 ( V_14 -> V_2 ) ;
F_10 ( V_2 , V_15 , & V_18 -> V_23 ) ;
if ( ! ( V_18 -> V_23 & V_16 ) )
return;
V_18 -> V_24 [ 0 ] = F_11 ( V_22 + V_25 ) ;
if ( V_26 == 2 )
V_18 -> V_24 [ 1 ] = F_11 ( V_22 + V_27 ) ;
F_10 ( V_2 , V_15 , & V_18 -> V_28 ) ;
if ( ( V_18 -> V_23 ^ V_18 -> V_28 ) & V_16 ) {
V_18 -> V_24 [ 0 ] = F_11 ( V_22 + V_25 ) ;
if ( V_26 == 2 )
V_18 -> V_24 [ 1 ] = F_11 ( V_22 + V_27 ) ;
}
F_6 ( V_14 ) ;
}
static void F_12 ( struct V_13 * V_14 ,
struct V_17 * V_18 )
{
int V_8 ;
T_1 log ;
if ( ! ( V_18 -> V_23 & V_16 ) )
return;
if ( ( V_18 -> V_23 ^ V_18 -> V_28 ) & V_16 ) {
F_13 ( V_29 , V_14 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 , L_5 , L_6 ) ;
V_18 -> V_23 = V_18 -> V_28 ;
}
for ( V_8 = 0 ; V_8 < V_26 ; V_8 ++ ) {
log = V_18 -> V_24 [ V_8 ] ;
if ( log & V_30 ) {
F_13 ( V_29 , V_14 , 1 ,
0 , 0 , 0 ,
F_5 ( V_8 , log ) ,
- 1 , - 1 ,
L_7 , L_6 ) ;
} else if ( log & V_31 ) {
F_13 ( V_32 , V_14 , 1 ,
0 , 0 , F_4 ( log ) ,
F_5 ( V_8 , log ) ,
- 1 , - 1 ,
L_8 , L_6 ) ;
}
}
}
static void F_14 ( struct V_13 * V_14 )
{
struct V_17 V_18 ;
F_3 ( 1 , L_9 , V_14 -> V_33 ) ;
F_9 ( V_14 , & V_18 ) ;
F_12 ( V_14 , & V_18 ) ;
}
static void T_2 * F_15 ( struct V_1 * V_2 )
{
union {
T_1 V_34 ;
struct {
T_3 V_35 ;
T_3 V_36 ;
};
} V_37 ;
void T_2 * V_22 ;
F_16 ( V_2 , V_38 , & V_37 . V_35 ) ;
F_16 ( V_2 , V_39 , & V_37 . V_36 ) ;
V_37 . V_34 &= V_40 ;
if ( V_37 . V_34 != ( V_41 ) V_37 . V_34 ) {
F_17 ( V_42
L_10 ,
( unsigned long long ) V_37 . V_34 ) ;
return NULL ;
}
V_22 = F_18 ( V_37 . V_34 , V_43 ) ;
if ( ! V_22 )
F_17 ( V_42 L_11 ,
( unsigned long long ) V_37 . V_34 ) ;
return V_22 ;
}
static void F_19 ( void T_2 * V_22 ,
T_4 V_44 [ V_45 ] [ V_12 ] )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_12 ; V_46 ++ ) {
V_44 [ 0 ] [ V_46 ] = F_20 ( V_22 + V_47 + 2 * V_46 ) & V_48 ;
V_44 [ 1 ] [ V_46 ] = F_20 ( V_22 + V_49 + 2 * V_46 ) & V_48 ;
F_3 ( 0 , L_12 , V_46 , V_44 [ 0 ] [ V_46 ] , V_46 , V_44 [ 1 ] [ V_46 ] ) ;
}
}
static bool F_21 ( struct V_1 * V_2 ,
T_4 V_44 [ V_45 ] [ V_12 ] )
{
T_4 V_50 ;
F_10 ( V_2 , V_51 , & V_50 ) ;
V_50 &= V_52 ;
return V_44 [ V_45 - 1 ] [ V_12 - 1 ] == V_50 ;
}
static unsigned long F_22 (
T_4 V_44 [ V_45 ] [ V_12 ] , bool V_53 ,
int V_8 , int V_9 )
{
int V_54 ;
V_54 = V_44 [ V_8 ] [ V_9 ] ;
if ( ! V_54 )
return 0 ;
if ( V_9 > 0 )
V_54 -= V_44 [ V_8 ] [ V_9 - 1 ] ;
if ( V_53 && ( V_8 == 1 ) &&
V_44 [ V_8 ] [ V_9 ] == V_44 [ V_8 ] [ V_12 - 1 ] )
V_54 -= V_44 [ 0 ] [ V_12 - 1 ] ;
V_54 <<= ( V_55 - V_56 ) ;
return V_54 ;
}
static int F_23 ( struct V_1 * V_2 , int V_57 )
{
int V_58 ;
int V_46 , V_59 ;
struct V_13 * V_14 = NULL ;
struct V_60 V_61 [ 2 ] ;
T_4 V_44 [ V_45 ] [ V_12 ] ;
bool V_53 ;
void T_2 * V_22 ;
struct V_19 * V_20 ;
F_3 ( 0 , L_13 ) ;
V_22 = F_15 ( V_2 ) ;
if ( ! V_22 )
return - V_62 ;
F_19 ( V_22 , V_44 ) ;
V_26 = F_1 ( V_2 ) ;
V_61 [ 0 ] . type = V_63 ;
V_61 [ 0 ] . V_64 = V_65 ;
V_61 [ 0 ] . V_66 = true ;
V_61 [ 1 ] . type = V_67 ;
V_61 [ 1 ] . V_64 = V_26 ;
V_61 [ 1 ] . V_66 = false ;
V_14 = F_24 ( 0 , F_25 ( V_61 ) , V_61 ,
sizeof( struct V_19 ) ) ;
if ( ! V_14 )
return - V_68 ;
F_3 ( 3 , L_14 ) ;
V_14 -> V_2 = & V_2 -> V_69 ;
V_14 -> V_70 = V_71 ;
V_14 -> V_72 = V_73 ;
V_14 -> V_74 = V_73 ;
V_14 -> V_75 = V_76 ;
V_14 -> V_77 = V_78 ;
V_14 -> V_79 = V_80 [ V_57 ] . V_79 ;
V_14 -> V_81 = F_26 ( V_2 ) ;
V_14 -> V_82 = F_14 ;
V_14 -> V_83 = NULL ;
V_20 = V_14 -> V_21 ;
V_20 -> V_22 = V_22 ;
V_53 = F_21 ( V_2 , V_44 ) ;
for ( V_46 = 0 ; V_46 < V_65 ; V_46 ++ ) {
unsigned long V_84 ;
for ( V_59 = 0 ; V_59 < V_26 ; V_59 ++ ) {
struct V_85 * V_86 = F_27 ( V_14 -> V_61 , V_14 -> V_87 ,
V_14 -> V_88 , V_46 , V_59 , 0 ) ;
V_84 = F_22 ( V_44 , V_53 , V_59 , V_46 ) ;
if ( V_84 == 0 )
continue;
F_3 ( 0 , L_15 , V_46 , V_59 ,
V_53 ? L_16 : L_6 , F_28 ( V_84 ) ) ;
V_86 -> V_84 = V_84 ;
V_86 -> V_89 = V_84 << V_56 ;
V_86 -> V_90 = V_91 ;
V_86 -> V_92 = V_93 ;
V_86 -> V_94 = V_95 ;
}
}
F_6 ( V_14 ) ;
V_58 = - V_62 ;
if ( F_29 ( V_14 ) ) {
F_3 ( 3 , L_17 ) ;
goto V_96;
}
F_3 ( 3 , L_18 ) ;
return 0 ;
V_96:
F_30 ( V_22 ) ;
if ( V_14 )
F_31 ( V_14 ) ;
return V_58 ;
}
static int F_32 ( struct V_1 * V_2 , const struct V_97 * V_98 )
{
int V_58 ;
F_3 ( 0 , L_13 ) ;
if ( F_33 ( V_2 ) < 0 )
return - V_99 ;
V_58 = F_23 ( V_2 , V_98 -> V_100 ) ;
if ( ! V_101 )
V_101 = F_34 ( V_2 ) ;
return V_58 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
struct V_19 * V_20 ;
F_3 ( 0 , L_19 ) ;
V_14 = F_36 ( & V_2 -> V_69 ) ;
if ( ! V_14 )
return;
V_20 = V_14 -> V_21 ;
F_30 ( V_20 -> V_22 ) ;
F_31 ( V_14 ) ;
F_37 ( V_2 ) ;
}
static int T_5 F_38 ( void )
{
int V_102 ;
F_3 ( 3 , L_13 ) ;
F_39 () ;
V_102 = F_40 ( & V_103 ) ;
if ( V_102 < 0 )
goto V_104;
if ( ! V_101 ) {
V_105 = 0 ;
V_101 = F_41 ( V_106 ,
V_107 , NULL ) ;
if ( ! V_101 ) {
F_3 ( 0 , L_20 ) ;
V_102 = - V_62 ;
goto V_108;
}
V_102 = F_32 ( V_101 , V_109 ) ;
if ( V_102 < 0 ) {
F_3 ( 0 , L_21 ) ;
V_102 = - V_62 ;
goto V_108;
}
}
return 0 ;
V_108:
F_42 ( & V_103 ) ;
V_104:
if ( V_101 )
F_43 ( V_101 ) ;
return V_102 ;
}
static void T_6 F_44 ( void )
{
F_3 ( 3 , L_13 ) ;
F_42 ( & V_103 ) ;
if ( ! V_105 ) {
F_35 ( V_101 ) ;
F_43 ( V_101 ) ;
}
}
