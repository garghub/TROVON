static inline T_1 F_1 ( const volatile void T_2 * V_1 )
{
const volatile T_3 T_2 * V_2 = V_1 ;
T_3 V_3 , V_4 ;
V_3 = F_2 ( V_2 ) ;
V_4 = F_2 ( V_2 + 1 ) ;
return V_3 + ( ( V_5 ) V_4 << 32 ) ;
}
static int F_3 ( struct V_6 * V_7 )
{
unsigned char V_8 ;
F_4 ( V_7 , V_9 + 8 , & V_8 ) ;
if ( V_8 & 0x20 ) {
F_5 ( L_1 ) ;
return 1 ;
} else {
F_5 ( L_2 ) ;
return 2 ;
}
}
static unsigned long F_6 ( V_5 log )
{
return ( log & V_10 ) >>
V_11 ;
}
static int F_7 ( int V_12 , V_5 log )
{
V_5 V_13 = ( ( log & V_14 ) >>
V_15 ) ;
return V_13 | ( V_12 * V_16 ) ;
}
static void F_8 ( struct V_17 * V_18 )
{
struct V_6 * V_7 ;
V_7 = F_9 ( V_18 -> V_19 ) ;
F_10 ( V_7 , V_20 , V_21 ,
V_21 ) ;
}
static void F_11 ( struct V_17 * V_18 ,
struct V_22 * V_23 )
{
struct V_6 * V_7 ;
struct V_24 * V_25 = V_18 -> V_26 ;
void T_2 * V_27 = V_25 -> V_27 ;
V_7 = F_9 ( V_18 -> V_19 ) ;
F_12 ( V_7 , V_20 , & V_23 -> V_28 ) ;
if ( ! ( V_23 -> V_28 & V_21 ) )
return;
V_23 -> V_29 [ 0 ] = F_1 ( V_27 + V_30 ) ;
if ( V_31 == 2 )
V_23 -> V_29 [ 1 ] = F_1 ( V_27 + V_32 ) ;
F_12 ( V_7 , V_20 , & V_23 -> V_33 ) ;
if ( ( V_23 -> V_28 ^ V_23 -> V_33 ) & V_21 ) {
V_23 -> V_29 [ 0 ] = F_1 ( V_27 + V_30 ) ;
if ( V_31 == 2 )
V_23 -> V_29 [ 1 ] = F_1 ( V_27 + V_32 ) ;
}
F_8 ( V_18 ) ;
}
static void F_13 ( struct V_17 * V_18 ,
struct V_22 * V_23 )
{
int V_12 ;
V_5 log ;
if ( ! ( V_23 -> V_28 & V_21 ) )
return;
if ( ( V_23 -> V_28 ^ V_23 -> V_33 ) & V_21 ) {
F_14 ( V_18 , L_3 ) ;
V_23 -> V_28 = V_23 -> V_33 ;
}
for ( V_12 = 0 ; V_12 < V_31 ; V_12 ++ ) {
log = V_23 -> V_29 [ V_12 ] ;
if ( log & V_34 ) {
F_15 ( V_18 , 0 , 0 ,
F_7 ( V_12 , log ) ,
L_4 ) ;
} else if ( log & V_35 ) {
F_16 ( V_18 , 0 , 0 ,
F_6 ( log ) ,
F_7 ( V_12 , log ) , 0 ,
L_5 ) ;
}
}
}
static void F_17 ( struct V_17 * V_18 )
{
struct V_22 V_23 ;
F_18 ( L_6 , V_18 -> V_36 , V_37 ) ;
F_11 ( V_18 , & V_23 ) ;
F_13 ( V_18 , & V_23 ) ;
}
void T_2 * F_19 ( struct V_6 * V_7 )
{
union {
V_5 V_38 ;
struct {
T_3 V_39 ;
T_3 V_40 ;
};
} V_41 ;
void T_2 * V_27 ;
F_20 ( V_7 , V_42 , & V_41 . V_39 ) ;
F_20 ( V_7 , V_43 , & V_41 . V_40 ) ;
V_41 . V_38 &= V_44 ;
if ( V_41 . V_38 != ( V_45 ) V_41 . V_38 ) {
F_21 ( V_46
L_7 ,
( unsigned long long ) V_41 . V_38 ) ;
return NULL ;
}
V_27 = F_22 ( V_41 . V_38 , V_47 ) ;
if ( ! V_27 )
F_21 ( V_46 L_8 ,
( unsigned long long ) V_41 . V_38 ) ;
return V_27 ;
}
static void F_23 ( void T_2 * V_27 ,
T_4 V_48 [ V_49 ] [ V_16 ] )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_16 ; V_50 ++ ) {
V_48 [ 0 ] [ V_50 ] = F_24 ( V_27 + V_51 + 2 * V_50 ) & V_52 ;
V_48 [ 1 ] [ V_50 ] = F_24 ( V_27 + V_53 + 2 * V_50 ) & V_52 ;
}
}
static bool F_25 ( struct V_6 * V_7 ,
T_4 V_48 [ V_49 ] [ V_16 ] )
{
T_4 V_54 ;
F_12 ( V_7 , V_55 , & V_54 ) ;
V_54 &= V_56 ;
return V_48 [ V_49 - 1 ] [ V_16 - 1 ] == V_54 ;
}
static unsigned long F_26 (
T_4 V_48 [ V_49 ] [ V_16 ] , bool V_57 ,
int V_12 , int V_13 )
{
int V_58 ;
V_58 = V_48 [ V_12 ] [ V_13 ] ;
if ( V_13 > 0 )
V_58 -= V_48 [ V_12 ] [ V_13 - 1 ] ;
if ( V_57 && ( V_12 == 1 ) &&
V_48 [ V_12 ] [ V_13 ] == V_48 [ V_12 ] [ V_16 - 1 ] )
V_58 -= V_48 [ 0 ] [ V_16 - 1 ] ;
V_58 <<= ( V_59 - V_60 ) ;
return V_58 ;
}
static int F_27 ( struct V_6 * V_7 , int V_61 )
{
int V_62 ;
int V_50 ;
struct V_17 * V_18 = NULL ;
unsigned long V_63 ;
T_4 V_48 [ V_49 ] [ V_16 ] ;
bool V_57 ;
void T_2 * V_27 ;
struct V_24 * V_25 ;
F_5 ( L_9 , V_37 ) ;
V_27 = F_19 ( V_7 ) ;
if ( ! V_27 )
return - V_64 ;
F_23 ( V_27 , V_48 ) ;
V_31 = F_3 ( V_7 ) ;
V_18 = F_28 ( sizeof( struct V_24 ) , V_65 ,
V_31 , 0 ) ;
if ( ! V_18 )
return - V_66 ;
F_29 ( L_10 , V_37 ) ;
V_18 -> V_19 = & V_7 -> V_19 ;
V_18 -> V_67 = V_68 ;
V_18 -> V_69 = V_70 ;
V_18 -> V_71 = V_70 ;
V_18 -> V_72 = V_73 ;
V_18 -> V_74 = V_75 ;
V_18 -> V_76 = V_77 [ V_61 ] . V_76 ;
V_18 -> V_78 = F_30 ( V_7 ) ;
V_18 -> V_79 = F_17 ;
V_18 -> V_80 = NULL ;
V_25 = V_18 -> V_26 ;
V_25 -> V_27 = V_27 ;
V_57 = F_25 ( V_7 , V_48 ) ;
V_63 = - 1UL ;
for ( V_50 = 0 ; V_50 < V_18 -> V_81 ; V_50 ++ ) {
unsigned long V_82 ;
struct V_83 * V_84 = & V_18 -> V_85 [ V_50 ] ;
V_82 = F_26 ( V_48 , V_57 ,
V_50 / V_16 ,
V_50 % V_16 ) ;
if ( V_82 == 0 ) {
V_84 -> V_86 = V_87 ;
continue;
}
V_84 -> V_88 = V_63 + 1 ;
V_63 += V_82 ;
V_84 -> V_63 = V_63 ;
V_84 -> V_82 = V_82 ;
V_84 -> V_89 = V_82 << V_60 ;
V_84 -> V_86 = V_90 ;
V_84 -> V_91 = V_92 ;
V_84 -> V_93 = V_94 ;
}
F_8 ( V_18 ) ;
V_62 = - V_64 ;
if ( F_31 ( V_18 ) ) {
F_29 ( L_11 , V_37 ) ;
goto V_95;
}
F_29 ( L_12 , V_37 ) ;
return 0 ;
V_95:
F_32 ( V_27 ) ;
if ( V_18 )
F_33 ( V_18 ) ;
return V_62 ;
}
static int T_5 F_34 ( struct V_6 * V_7 ,
const struct V_96 * V_97 )
{
int V_62 ;
F_5 ( L_9 , V_37 ) ;
if ( F_35 ( V_7 ) < 0 )
return - V_98 ;
V_62 = F_27 ( V_7 , V_97 -> V_99 ) ;
if ( ! V_100 )
V_100 = F_36 ( V_7 ) ;
return V_62 ;
}
static void T_6 F_37 ( struct V_6 * V_7 )
{
struct V_17 * V_18 ;
struct V_24 * V_25 ;
F_5 ( L_13 , V_37 ) ;
V_18 = F_38 ( & V_7 -> V_19 ) ;
if ( ! V_18 )
return;
V_25 = V_18 -> V_26 ;
F_32 ( V_25 -> V_27 ) ;
F_33 ( V_18 ) ;
}
static int T_7 F_39 ( void )
{
int V_101 ;
F_29 ( L_9 , V_37 ) ;
F_40 () ;
V_101 = F_41 ( & V_102 ) ;
if ( V_101 < 0 )
goto V_103;
if ( ! V_100 ) {
V_104 = 0 ;
V_100 = F_42 ( V_105 ,
V_106 , NULL ) ;
if ( ! V_100 ) {
F_5 ( L_14 ) ;
V_101 = - V_64 ;
goto V_107;
}
V_101 = F_34 ( V_100 , V_108 ) ;
if ( V_101 < 0 ) {
F_5 ( L_15 ) ;
V_101 = - V_64 ;
goto V_107;
}
}
return 0 ;
V_107:
F_43 ( & V_102 ) ;
V_103:
if ( V_100 )
F_44 ( V_100 ) ;
return V_101 ;
}
static void T_8 F_45 ( void )
{
F_29 ( L_9 , V_37 ) ;
F_43 ( & V_102 ) ;
if ( ! V_104 ) {
F_37 ( V_100 ) ;
F_44 ( V_100 ) ;
}
}
