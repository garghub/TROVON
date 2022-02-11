static int F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
F_2 ( V_2 , V_4 + 8 , & V_3 ) ;
if ( V_3 & 0x20 ) {
F_3 ( L_1 ) ;
return 1 ;
} else {
F_3 ( L_2 ) ;
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
V_2 = F_7 ( V_13 -> V_14 ) ;
F_8 ( V_2 , V_15 , V_16 ,
V_16 ) ;
}
static void F_9 ( struct V_12 * V_13 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 = V_13 -> V_21 ;
void T_2 * V_22 = V_20 -> V_22 ;
V_2 = F_7 ( V_13 -> V_14 ) ;
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
F_6 ( V_13 ) ;
}
static void F_12 ( struct V_12 * V_13 ,
struct V_17 * V_18 )
{
int V_7 ;
T_1 log ;
if ( ! ( V_18 -> V_23 & V_16 ) )
return;
if ( ( V_18 -> V_23 ^ V_18 -> V_28 ) & V_16 ) {
F_13 ( V_29 , V_13 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 , L_3 , L_4 , NULL ) ;
V_18 -> V_23 = V_18 -> V_28 ;
}
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ ) {
log = V_18 -> V_24 [ V_7 ] ;
if ( log & V_30 ) {
F_13 ( V_29 , V_13 ,
0 , 0 , 0 ,
F_5 ( V_7 , log ) ,
- 1 , - 1 ,
L_5 , L_4 , NULL ) ;
} else if ( log & V_31 ) {
F_13 ( V_29 , V_13 ,
0 , 0 , F_4 ( log ) ,
F_5 ( V_7 , log ) ,
- 1 , - 1 ,
L_5 , L_4 , NULL ) ;
}
}
}
static void F_14 ( struct V_12 * V_13 )
{
struct V_17 V_18 ;
F_15 ( L_6 , V_13 -> V_32 , V_33 ) ;
F_9 ( V_13 , & V_18 ) ;
F_12 ( V_13 , & V_18 ) ;
}
void T_2 * F_16 ( struct V_1 * V_2 )
{
union {
T_1 V_34 ;
struct {
T_3 V_35 ;
T_3 V_36 ;
};
} V_37 ;
void T_2 * V_22 ;
F_17 ( V_2 , V_38 , & V_37 . V_35 ) ;
F_17 ( V_2 , V_39 , & V_37 . V_36 ) ;
V_37 . V_34 &= V_40 ;
if ( V_37 . V_34 != ( V_41 ) V_37 . V_34 ) {
F_18 ( V_42
L_7 ,
( unsigned long long ) V_37 . V_34 ) ;
return NULL ;
}
V_22 = F_19 ( V_37 . V_34 , V_43 ) ;
if ( ! V_22 )
F_18 ( V_42 L_8 ,
( unsigned long long ) V_37 . V_34 ) ;
return V_22 ;
}
static void F_20 ( void T_2 * V_22 ,
T_4 V_44 [ V_45 ] [ V_11 ] )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_11 ; V_46 ++ ) {
V_44 [ 0 ] [ V_46 ] = F_21 ( V_22 + V_47 + 2 * V_46 ) & V_48 ;
V_44 [ 1 ] [ V_46 ] = F_21 ( V_22 + V_49 + 2 * V_46 ) & V_48 ;
}
}
static bool F_22 ( struct V_1 * V_2 ,
T_4 V_44 [ V_45 ] [ V_11 ] )
{
T_4 V_50 ;
F_10 ( V_2 , V_51 , & V_50 ) ;
V_50 &= V_52 ;
return V_44 [ V_45 - 1 ] [ V_11 - 1 ] == V_50 ;
}
static unsigned long F_23 (
T_4 V_44 [ V_45 ] [ V_11 ] , bool V_53 ,
int V_7 , int V_8 )
{
int V_54 ;
V_54 = V_44 [ V_7 ] [ V_8 ] ;
if ( V_8 > 0 )
V_54 -= V_44 [ V_7 ] [ V_8 - 1 ] ;
if ( V_53 && ( V_7 == 1 ) &&
V_44 [ V_7 ] [ V_8 ] == V_44 [ V_7 ] [ V_11 - 1 ] )
V_54 -= V_44 [ 0 ] [ V_11 - 1 ] ;
V_54 <<= ( V_55 - V_56 ) ;
return V_54 ;
}
static int F_24 ( struct V_1 * V_2 , int V_57 )
{
int V_58 ;
int V_46 , V_59 ;
struct V_12 * V_13 = NULL ;
struct V_60 V_61 [ 2 ] ;
T_4 V_44 [ V_45 ] [ V_11 ] ;
bool V_53 ;
void T_2 * V_22 ;
struct V_19 * V_20 ;
F_3 ( L_9 , V_33 ) ;
V_22 = F_16 ( V_2 ) ;
if ( ! V_22 )
return - V_62 ;
F_20 ( V_22 , V_44 ) ;
V_26 = F_1 ( V_2 ) ;
V_61 [ 0 ] . type = V_63 ;
V_61 [ 0 ] . V_64 = V_65 ;
V_61 [ 0 ] . V_66 = true ;
V_61 [ 1 ] . type = V_67 ;
V_61 [ 1 ] . V_64 = V_26 ;
V_61 [ 1 ] . V_66 = false ;
V_13 = F_25 ( 0 , F_26 ( V_61 ) , V_61 ,
sizeof( struct V_19 ) ) ;
if ( ! V_13 )
return - V_68 ;
F_27 ( L_10 , V_33 ) ;
V_13 -> V_14 = & V_2 -> V_14 ;
V_13 -> V_69 = V_70 ;
V_13 -> V_71 = V_72 ;
V_13 -> V_73 = V_72 ;
V_13 -> V_74 = V_75 ;
V_13 -> V_76 = V_77 ;
V_13 -> V_78 = V_79 [ V_57 ] . V_78 ;
V_13 -> V_80 = F_28 ( V_2 ) ;
V_13 -> V_81 = F_14 ;
V_13 -> V_82 = NULL ;
V_20 = V_13 -> V_21 ;
V_20 -> V_22 = V_22 ;
V_53 = F_22 ( V_2 , V_44 ) ;
for ( V_46 = 0 ; V_46 < V_13 -> V_83 ; V_46 ++ ) {
unsigned long V_84 ;
struct V_85 * V_86 = & V_13 -> V_87 [ V_46 ] ;
V_84 = F_23 ( V_44 , V_53 ,
V_46 / V_11 ,
V_46 % V_11 ) ;
if ( V_84 == 0 )
continue;
for ( V_59 = 0 ; V_59 < V_26 ; V_59 ++ ) {
struct V_88 * V_89 = V_86 -> V_90 [ V_59 ] . V_89 ;
V_89 -> V_84 = V_84 / V_26 ;
V_89 -> V_91 = V_84 << V_56 ;
V_89 -> V_92 = V_93 ;
V_89 -> V_94 = V_95 ;
V_89 -> V_96 = V_97 ;
}
}
F_6 ( V_13 ) ;
V_58 = - V_62 ;
if ( F_29 ( V_13 ) ) {
F_27 ( L_11 , V_33 ) ;
goto V_98;
}
F_27 ( L_12 , V_33 ) ;
return 0 ;
V_98:
F_30 ( V_22 ) ;
if ( V_13 )
F_31 ( V_13 ) ;
return V_58 ;
}
static int T_5 F_32 ( struct V_1 * V_2 ,
const struct V_99 * V_100 )
{
int V_58 ;
F_3 ( L_9 , V_33 ) ;
if ( F_33 ( V_2 ) < 0 )
return - V_101 ;
V_58 = F_24 ( V_2 , V_100 -> V_102 ) ;
if ( ! V_103 )
V_103 = F_34 ( V_2 ) ;
return V_58 ;
}
static void T_6 F_35 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_19 * V_20 ;
F_3 ( L_13 , V_33 ) ;
V_13 = F_36 ( & V_2 -> V_14 ) ;
if ( ! V_13 )
return;
V_20 = V_13 -> V_21 ;
F_30 ( V_20 -> V_22 ) ;
F_31 ( V_13 ) ;
}
static int T_7 F_37 ( void )
{
int V_104 ;
F_27 ( L_9 , V_33 ) ;
F_38 () ;
V_104 = F_39 ( & V_105 ) ;
if ( V_104 < 0 )
goto V_106;
if ( ! V_103 ) {
V_107 = 0 ;
V_103 = F_40 ( V_108 ,
V_109 , NULL ) ;
if ( ! V_103 ) {
F_3 ( L_14 ) ;
V_104 = - V_62 ;
goto V_110;
}
V_104 = F_32 ( V_103 , V_111 ) ;
if ( V_104 < 0 ) {
F_3 ( L_15 ) ;
V_104 = - V_62 ;
goto V_110;
}
}
return 0 ;
V_110:
F_41 ( & V_105 ) ;
V_106:
if ( V_103 )
F_42 ( V_103 ) ;
return V_104 ;
}
static void T_8 F_43 ( void )
{
F_27 ( L_9 , V_33 ) ;
F_41 ( & V_105 ) ;
if ( ! V_107 ) {
F_35 ( V_103 ) ;
F_42 ( V_103 ) ;
}
}
