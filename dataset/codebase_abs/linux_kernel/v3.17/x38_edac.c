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
static void F_9 ( struct V_10 * V_11 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 ;
void T_2 * V_16 = V_11 -> V_17 ;
V_2 = F_7 ( V_11 -> V_2 ) ;
F_10 ( V_2 , V_12 , & V_15 -> V_18 ) ;
if ( ! ( V_15 -> V_18 & V_13 ) )
return;
V_15 -> V_19 [ 0 ] = F_11 ( V_16 + V_20 ) ;
if ( V_5 == 2 )
V_15 -> V_19 [ 1 ] = F_11 ( V_16 + V_21 ) ;
F_10 ( V_2 , V_12 , & V_15 -> V_22 ) ;
if ( ( V_15 -> V_18 ^ V_15 -> V_22 ) & V_13 ) {
V_15 -> V_19 [ 0 ] = F_11 ( V_16 + V_20 ) ;
if ( V_5 == 2 )
V_15 -> V_19 [ 1 ] =
F_11 ( V_16 + V_21 ) ;
}
F_6 ( V_11 ) ;
}
static void F_12 ( struct V_10 * V_11 ,
struct V_14 * V_15 )
{
int V_7 ;
T_1 log ;
if ( ! ( V_15 -> V_18 & V_13 ) )
return;
if ( ( V_15 -> V_18 ^ V_15 -> V_22 ) & V_13 ) {
F_13 ( V_23 , V_11 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 ,
L_3 , L_4 ) ;
V_15 -> V_18 = V_15 -> V_22 ;
}
for ( V_7 = 0 ; V_7 < V_5 ; V_7 ++ ) {
log = V_15 -> V_19 [ V_7 ] ;
if ( log & V_24 ) {
F_13 ( V_23 , V_11 , 1 ,
0 , 0 , 0 ,
F_5 ( V_7 , log ) ,
- 1 , - 1 ,
L_5 , L_4 ) ;
} else if ( log & V_25 ) {
F_13 ( V_26 , V_11 , 1 ,
0 , 0 , F_4 ( log ) ,
F_5 ( V_7 , log ) ,
- 1 , - 1 ,
L_6 , L_4 ) ;
}
}
}
static void F_14 ( struct V_10 * V_11 )
{
struct V_14 V_15 ;
F_3 ( 1 , L_7 , V_11 -> V_27 ) ;
F_9 ( V_11 , & V_15 ) ;
F_12 ( V_11 , & V_15 ) ;
}
static void T_2 * F_15 ( struct V_1 * V_2 )
{
union {
T_1 V_28 ;
struct {
T_3 V_29 ;
T_3 V_30 ;
};
} V_31 ;
void T_2 * V_16 ;
F_16 ( V_2 , V_32 , & V_31 . V_29 ) ;
F_17 ( V_2 , V_32 , V_31 . V_29 | 0x1 ) ;
F_16 ( V_2 , V_33 , & V_31 . V_30 ) ;
V_31 . V_28 &= V_34 ;
if ( V_31 . V_28 != ( V_35 ) V_31 . V_28 ) {
F_18 ( V_36
L_8 ,
( unsigned long long ) V_31 . V_28 ) ;
return NULL ;
}
V_16 = F_19 ( V_31 . V_28 , V_37 ) ;
if ( ! V_16 )
F_18 ( V_36 L_9 ,
( unsigned long long ) V_31 . V_28 ) ;
return V_16 ;
}
static void F_20 ( void T_2 * V_16 ,
T_4 V_38 [ V_39 ] [ V_9 ] )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_9 ; V_40 ++ ) {
V_38 [ 0 ] [ V_40 ] = F_21 ( V_16 + V_41 + 2 * V_40 ) & V_42 ;
V_38 [ 1 ] [ V_40 ] = F_21 ( V_16 + V_43 + 2 * V_40 ) & V_42 ;
}
}
static bool F_22 ( struct V_1 * V_2 ,
T_4 V_38 [ V_39 ] [ V_9 ] )
{
T_4 V_44 ;
F_10 ( V_2 , V_45 , & V_44 ) ;
V_44 &= V_46 ;
return V_38 [ V_39 - 1 ] [ V_9 - 1 ] == V_44 ;
}
static unsigned long F_23 (
T_4 V_38 [ V_39 ] [ V_9 ] ,
bool V_47 , int V_7 , int V_48 )
{
int V_49 ;
V_49 = V_38 [ V_7 ] [ V_48 ] ;
if ( V_48 > 0 )
V_49 -= V_38 [ V_7 ] [ V_48 - 1 ] ;
if ( V_47 && ( V_7 == 1 ) && V_38 [ V_7 ] [ V_48 ] ==
V_38 [ V_7 ] [ V_9 - 1 ] ) {
V_49 -= V_38 [ 0 ] [ V_9 - 1 ] ;
}
V_49 <<= ( V_50 - V_51 ) ;
return V_49 ;
}
static int F_24 ( struct V_1 * V_2 , int V_52 )
{
int V_53 ;
int V_40 , V_54 ;
struct V_10 * V_11 = NULL ;
struct V_55 V_56 [ 2 ] ;
T_4 V_38 [ V_39 ] [ V_9 ] ;
bool V_47 ;
void T_2 * V_16 ;
F_3 ( 0 , L_10 ) ;
V_16 = F_15 ( V_2 ) ;
if ( ! V_16 )
return - V_57 ;
F_20 ( V_16 , V_38 ) ;
F_1 ( V_2 ) ;
V_56 [ 0 ] . type = V_58 ;
V_56 [ 0 ] . V_59 = V_60 ;
V_56 [ 0 ] . V_61 = true ;
V_56 [ 1 ] . type = V_62 ;
V_56 [ 1 ] . V_59 = V_5 ;
V_56 [ 1 ] . V_61 = false ;
V_11 = F_25 ( 0 , F_26 ( V_56 ) , V_56 , 0 ) ;
if ( ! V_11 )
return - V_63 ;
F_3 ( 3 , L_11 ) ;
V_11 -> V_2 = & V_2 -> V_64 ;
V_11 -> V_65 = V_66 ;
V_11 -> V_67 = V_68 ;
V_11 -> V_69 = V_68 ;
V_11 -> V_70 = V_71 ;
V_11 -> V_72 = V_73 ;
V_11 -> V_74 = V_75 [ V_52 ] . V_74 ;
V_11 -> V_76 = F_27 ( V_2 ) ;
V_11 -> V_77 = F_14 ;
V_11 -> V_78 = NULL ;
V_11 -> V_17 = V_16 ;
V_47 = F_22 ( V_2 , V_38 ) ;
for ( V_40 = 0 ; V_40 < V_11 -> V_79 ; V_40 ++ ) {
unsigned long V_80 ;
struct V_81 * V_82 = V_11 -> V_83 [ V_40 ] ;
V_80 = F_23 ( V_38 , V_47 ,
V_40 / V_9 ,
V_40 % V_9 ) ;
if ( V_80 == 0 )
continue;
for ( V_54 = 0 ; V_54 < V_5 ; V_54 ++ ) {
struct V_84 * V_85 = V_82 -> V_86 [ V_54 ] -> V_85 ;
V_85 -> V_80 = V_80 / V_5 ;
V_85 -> V_87 = V_80 << V_51 ;
V_85 -> V_88 = V_89 ;
V_85 -> V_90 = V_91 ;
V_85 -> V_92 = V_93 ;
}
}
F_6 ( V_11 ) ;
V_53 = - V_57 ;
if ( F_28 ( V_11 ) ) {
F_3 ( 3 , L_12 ) ;
goto V_94;
}
F_3 ( 3 , L_13 ) ;
return 0 ;
V_94:
F_29 ( V_16 ) ;
if ( V_11 )
F_30 ( V_11 ) ;
return V_53 ;
}
static int F_31 ( struct V_1 * V_2 , const struct V_95 * V_96 )
{
int V_53 ;
F_3 ( 0 , L_10 ) ;
if ( F_32 ( V_2 ) < 0 )
return - V_97 ;
V_53 = F_24 ( V_2 , V_96 -> V_98 ) ;
if ( ! V_99 )
V_99 = F_33 ( V_2 ) ;
return V_53 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_3 ( 0 , L_14 ) ;
V_11 = F_35 ( & V_2 -> V_64 ) ;
if ( ! V_11 )
return;
F_29 ( V_11 -> V_17 ) ;
F_30 ( V_11 ) ;
}
static int T_5 F_36 ( void )
{
int V_100 ;
F_3 ( 3 , L_10 ) ;
F_37 () ;
V_100 = F_38 ( & V_101 ) ;
if ( V_100 < 0 )
goto V_102;
if ( ! V_99 ) {
V_103 = 0 ;
V_99 = F_39 ( V_104 ,
V_105 , NULL ) ;
if ( ! V_99 ) {
F_3 ( 0 , L_15 ) ;
V_100 = - V_57 ;
goto V_106;
}
V_100 = F_31 ( V_99 , V_107 ) ;
if ( V_100 < 0 ) {
F_3 ( 0 , L_16 ) ;
V_100 = - V_57 ;
goto V_106;
}
}
return 0 ;
V_106:
F_40 ( & V_101 ) ;
V_102:
if ( V_99 )
F_41 ( V_99 ) ;
return V_100 ;
}
static void T_6 F_42 ( void )
{
F_3 ( 3 , L_10 ) ;
F_40 ( & V_101 ) ;
if ( ! V_103 ) {
F_34 ( V_99 ) ;
F_41 ( V_99 ) ;
}
}
