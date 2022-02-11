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
F_14 ( V_11 , L_3 ) ;
V_17 -> V_20 = V_17 -> V_24 ;
}
for ( V_7 = 0 ; V_7 < V_5 ; V_7 ++ ) {
log = V_17 -> V_21 [ V_7 ] ;
if ( log & V_25 ) {
F_15 ( V_11 , 0 , 0 ,
F_5 ( V_7 , log ) , L_4 ) ;
} else if ( log & V_26 ) {
F_16 ( V_11 , 0 , 0 ,
F_4 ( log ) ,
F_5 ( V_7 , log ) , 0 , L_5 ) ;
}
}
}
static void F_17 ( struct V_10 * V_11 )
{
struct V_16 V_17 ;
F_18 ( L_6 , V_11 -> V_27 , V_28 ) ;
F_11 ( V_11 , & V_17 ) ;
F_13 ( V_11 , & V_17 ) ;
}
void T_2 * F_19 ( struct V_1 * V_2 )
{
union {
T_1 V_29 ;
struct {
T_3 V_30 ;
T_3 V_31 ;
};
} V_32 ;
void T_2 * V_18 ;
F_20 ( V_2 , V_33 , & V_32 . V_30 ) ;
F_21 ( V_2 , V_33 , V_32 . V_30 | 0x1 ) ;
F_20 ( V_2 , V_34 , & V_32 . V_31 ) ;
V_32 . V_29 &= V_35 ;
if ( V_32 . V_29 != ( V_36 ) V_32 . V_29 ) {
F_22 ( V_37
L_7 ,
( unsigned long long ) V_32 . V_29 ) ;
return NULL ;
}
V_18 = F_23 ( V_32 . V_29 , V_38 ) ;
if ( ! V_18 )
F_22 ( V_37 L_8 ,
( unsigned long long ) V_32 . V_29 ) ;
return V_18 ;
}
static void F_24 ( void T_2 * V_18 ,
T_4 V_39 [ V_40 ] [ V_9 ] )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_9 ; V_41 ++ ) {
V_39 [ 0 ] [ V_41 ] = F_25 ( V_18 + V_42 + 2 * V_41 ) & V_43 ;
V_39 [ 1 ] [ V_41 ] = F_25 ( V_18 + V_44 + 2 * V_41 ) & V_43 ;
}
}
static bool F_26 ( struct V_1 * V_2 ,
T_4 V_39 [ V_40 ] [ V_9 ] )
{
T_4 V_45 ;
F_12 ( V_2 , V_46 , & V_45 ) ;
V_45 &= V_47 ;
return V_39 [ V_40 - 1 ] [ V_9 - 1 ] == V_45 ;
}
static unsigned long F_27 (
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
static int F_28 ( struct V_1 * V_2 , int V_53 )
{
int V_54 ;
int V_41 ;
struct V_10 * V_11 = NULL ;
unsigned long V_55 ;
T_4 V_39 [ V_40 ] [ V_9 ] ;
bool V_48 ;
void T_2 * V_18 ;
F_3 ( L_9 , V_28 ) ;
V_18 = F_19 ( V_2 ) ;
if ( ! V_18 )
return - V_56 ;
F_24 ( V_18 , V_39 ) ;
F_1 ( V_2 ) ;
V_11 = F_29 ( 0 , V_57 , V_5 , 0 ) ;
if ( ! V_11 )
return - V_58 ;
F_30 ( L_10 , V_28 ) ;
V_11 -> V_12 = & V_2 -> V_12 ;
V_11 -> V_59 = V_60 ;
V_11 -> V_61 = V_62 ;
V_11 -> V_63 = V_62 ;
V_11 -> V_64 = V_65 ;
V_11 -> V_66 = V_67 ;
V_11 -> V_68 = V_69 [ V_53 ] . V_68 ;
V_11 -> V_70 = F_31 ( V_2 ) ;
V_11 -> V_71 = F_17 ;
V_11 -> V_72 = NULL ;
V_11 -> V_19 = V_18 ;
V_48 = F_26 ( V_2 , V_39 ) ;
V_55 = - 1UL ;
for ( V_41 = 0 ; V_41 < V_11 -> V_73 ; V_41 ++ ) {
unsigned long V_74 ;
struct V_75 * V_76 = & V_11 -> V_77 [ V_41 ] ;
V_74 = F_27 ( V_39 , V_48 ,
V_41 / V_9 ,
V_41 % V_9 ) ;
if ( V_74 == 0 ) {
V_76 -> V_78 = V_79 ;
continue;
}
V_76 -> V_80 = V_55 + 1 ;
V_55 += V_74 ;
V_76 -> V_55 = V_55 ;
V_76 -> V_74 = V_74 ;
V_76 -> V_81 = V_74 << V_52 ;
V_76 -> V_78 = V_82 ;
V_76 -> V_83 = V_84 ;
V_76 -> V_85 = V_86 ;
}
F_6 ( V_11 ) ;
V_54 = - V_56 ;
if ( F_32 ( V_11 ) ) {
F_30 ( L_11 , V_28 ) ;
goto V_87;
}
F_30 ( L_12 , V_28 ) ;
return 0 ;
V_87:
F_33 ( V_18 ) ;
if ( V_11 )
F_34 ( V_11 ) ;
return V_54 ;
}
static int T_5 F_35 ( struct V_1 * V_2 ,
const struct V_88 * V_89 )
{
int V_54 ;
F_3 ( L_9 , V_28 ) ;
if ( F_36 ( V_2 ) < 0 )
return - V_90 ;
V_54 = F_28 ( V_2 , V_89 -> V_91 ) ;
if ( ! V_92 )
V_92 = F_37 ( V_2 ) ;
return V_54 ;
}
static void T_6 F_38 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_3 ( L_13 , V_28 ) ;
V_11 = F_39 ( & V_2 -> V_12 ) ;
if ( ! V_11 )
return;
F_33 ( V_11 -> V_19 ) ;
F_34 ( V_11 ) ;
}
static int T_7 F_40 ( void )
{
int V_93 ;
F_30 ( L_9 , V_28 ) ;
F_41 () ;
V_93 = F_42 ( & V_94 ) ;
if ( V_93 < 0 )
goto V_95;
if ( ! V_92 ) {
V_96 = 0 ;
V_92 = F_43 ( V_97 ,
V_98 , NULL ) ;
if ( ! V_92 ) {
F_3 ( L_14 ) ;
V_93 = - V_56 ;
goto V_99;
}
V_93 = F_35 ( V_92 , V_100 ) ;
if ( V_93 < 0 ) {
F_3 ( L_15 ) ;
V_93 = - V_56 ;
goto V_99;
}
}
return 0 ;
V_99:
F_44 ( & V_94 ) ;
V_95:
if ( V_92 )
F_45 ( V_92 ) ;
return V_93 ;
}
static void T_8 F_46 ( void )
{
F_30 ( L_9 , V_28 ) ;
F_44 ( & V_94 ) ;
if ( ! V_96 ) {
F_38 ( V_92 ) ;
F_45 ( V_92 ) ;
}
}
