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
F_13 ( V_29 , V_14 , 1 ,
0 , 0 , F_4 ( log ) ,
F_5 ( V_8 , log ) ,
- 1 , - 1 ,
L_7 , L_6 ) ;
}
}
}
static void F_14 ( struct V_13 * V_14 )
{
struct V_17 V_18 ;
F_3 ( 1 , L_8 , V_14 -> V_32 ) ;
F_9 ( V_14 , & V_18 ) ;
F_12 ( V_14 , & V_18 ) ;
}
static void T_2 * F_15 ( struct V_1 * V_2 )
{
union {
T_1 V_33 ;
struct {
T_3 V_34 ;
T_3 V_35 ;
};
} V_36 ;
void T_2 * V_22 ;
F_16 ( V_2 , V_37 , & V_36 . V_34 ) ;
F_16 ( V_2 , V_38 , & V_36 . V_35 ) ;
V_36 . V_33 &= V_39 ;
if ( V_36 . V_33 != ( V_40 ) V_36 . V_33 ) {
F_17 ( V_41
L_9 ,
( unsigned long long ) V_36 . V_33 ) ;
return NULL ;
}
V_22 = F_18 ( V_36 . V_33 , V_42 ) ;
if ( ! V_22 )
F_17 ( V_41 L_10 ,
( unsigned long long ) V_36 . V_33 ) ;
return V_22 ;
}
static void F_19 ( void T_2 * V_22 ,
T_4 V_43 [ V_44 ] [ V_12 ] )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_12 ; V_45 ++ ) {
V_43 [ 0 ] [ V_45 ] = F_20 ( V_22 + V_46 + 2 * V_45 ) & V_47 ;
V_43 [ 1 ] [ V_45 ] = F_20 ( V_22 + V_48 + 2 * V_45 ) & V_47 ;
F_3 ( 0 , L_11 , V_45 , V_43 [ 0 ] [ V_45 ] , V_45 , V_43 [ 1 ] [ V_45 ] ) ;
}
}
static bool F_21 ( struct V_1 * V_2 ,
T_4 V_43 [ V_44 ] [ V_12 ] )
{
T_4 V_49 ;
F_10 ( V_2 , V_50 , & V_49 ) ;
V_49 &= V_51 ;
return V_43 [ V_44 - 1 ] [ V_12 - 1 ] == V_49 ;
}
static unsigned long F_22 (
T_4 V_43 [ V_44 ] [ V_12 ] , bool V_52 ,
int V_8 , int V_9 )
{
int V_53 ;
V_53 = V_43 [ V_8 ] [ V_9 ] ;
if ( ! V_53 )
return 0 ;
if ( V_9 > 0 )
V_53 -= V_43 [ V_8 ] [ V_9 - 1 ] ;
if ( V_52 && ( V_8 == 1 ) &&
V_43 [ V_8 ] [ V_9 ] == V_43 [ V_8 ] [ V_12 - 1 ] )
V_53 -= V_43 [ 0 ] [ V_12 - 1 ] ;
V_53 <<= ( V_54 - V_55 ) ;
return V_53 ;
}
static int F_23 ( struct V_1 * V_2 , int V_56 )
{
int V_57 ;
int V_45 , V_58 ;
struct V_13 * V_14 = NULL ;
struct V_59 V_60 [ 2 ] ;
T_4 V_43 [ V_44 ] [ V_12 ] ;
bool V_52 ;
void T_2 * V_22 ;
struct V_19 * V_20 ;
F_3 ( 0 , L_12 ) ;
V_22 = F_15 ( V_2 ) ;
if ( ! V_22 )
return - V_61 ;
F_19 ( V_22 , V_43 ) ;
V_26 = F_1 ( V_2 ) ;
V_60 [ 0 ] . type = V_62 ;
V_60 [ 0 ] . V_63 = V_64 ;
V_60 [ 0 ] . V_65 = true ;
V_60 [ 1 ] . type = V_66 ;
V_60 [ 1 ] . V_63 = V_26 ;
V_60 [ 1 ] . V_65 = false ;
V_14 = F_24 ( 0 , F_25 ( V_60 ) , V_60 ,
sizeof( struct V_19 ) ) ;
if ( ! V_14 )
return - V_67 ;
F_3 ( 3 , L_13 ) ;
V_14 -> V_2 = & V_2 -> V_68 ;
V_14 -> V_69 = V_70 ;
V_14 -> V_71 = V_72 ;
V_14 -> V_73 = V_72 ;
V_14 -> V_74 = V_75 ;
V_14 -> V_76 = V_77 ;
V_14 -> V_78 = V_79 [ V_56 ] . V_78 ;
V_14 -> V_80 = F_26 ( V_2 ) ;
V_14 -> V_81 = F_14 ;
V_14 -> V_82 = NULL ;
V_20 = V_14 -> V_21 ;
V_20 -> V_22 = V_22 ;
V_52 = F_21 ( V_2 , V_43 ) ;
for ( V_45 = 0 ; V_45 < V_64 ; V_45 ++ ) {
unsigned long V_83 ;
for ( V_58 = 0 ; V_58 < V_26 ; V_58 ++ ) {
struct V_84 * V_85 = F_27 ( V_14 -> V_60 , V_14 -> V_86 ,
V_14 -> V_87 , V_45 , V_58 , 0 ) ;
V_83 = F_22 ( V_43 , V_52 , V_58 , V_45 ) ;
if ( V_83 == 0 )
continue;
F_3 ( 0 , L_14 , V_45 , V_58 ,
V_52 ? L_15 : L_6 , F_28 ( V_83 ) ) ;
V_85 -> V_83 = V_83 ;
V_85 -> V_88 = V_83 << V_55 ;
V_85 -> V_89 = V_90 ;
V_85 -> V_91 = V_92 ;
V_85 -> V_93 = V_94 ;
}
}
F_6 ( V_14 ) ;
V_57 = - V_61 ;
if ( F_29 ( V_14 ) ) {
F_3 ( 3 , L_16 ) ;
goto V_95;
}
F_3 ( 3 , L_17 ) ;
return 0 ;
V_95:
F_30 ( V_22 ) ;
if ( V_14 )
F_31 ( V_14 ) ;
return V_57 ;
}
static int F_32 ( struct V_1 * V_2 , const struct V_96 * V_97 )
{
int V_57 ;
F_3 ( 0 , L_12 ) ;
if ( F_33 ( V_2 ) < 0 )
return - V_98 ;
V_57 = F_23 ( V_2 , V_97 -> V_99 ) ;
if ( ! V_100 )
V_100 = F_34 ( V_2 ) ;
return V_57 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
struct V_19 * V_20 ;
F_3 ( 0 , L_18 ) ;
V_14 = F_36 ( & V_2 -> V_68 ) ;
if ( ! V_14 )
return;
V_20 = V_14 -> V_21 ;
F_30 ( V_20 -> V_22 ) ;
F_31 ( V_14 ) ;
F_37 ( V_2 ) ;
}
static int T_5 F_38 ( void )
{
int V_101 ;
F_3 ( 3 , L_12 ) ;
F_39 () ;
V_101 = F_40 ( & V_102 ) ;
if ( V_101 < 0 )
goto V_103;
if ( ! V_100 ) {
V_104 = 0 ;
V_100 = F_41 ( V_105 ,
V_106 , NULL ) ;
if ( ! V_100 ) {
F_3 ( 0 , L_19 ) ;
V_101 = - V_61 ;
goto V_107;
}
V_101 = F_32 ( V_100 , V_108 ) ;
if ( V_101 < 0 ) {
F_3 ( 0 , L_20 ) ;
V_101 = - V_61 ;
goto V_107;
}
}
return 0 ;
V_107:
F_42 ( & V_102 ) ;
V_103:
if ( V_100 )
F_43 ( V_100 ) ;
return V_101 ;
}
static void T_6 F_44 ( void )
{
F_3 ( 3 , L_12 ) ;
F_42 ( & V_102 ) ;
if ( ! V_104 ) {
F_35 ( V_100 ) ;
F_43 ( V_100 ) ;
}
}
