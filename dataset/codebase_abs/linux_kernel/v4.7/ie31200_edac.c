static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned char V_4 ;
F_2 ( V_2 , V_5 + 1 , & V_4 ) ;
if ( V_4 & V_6 ) {
F_3 ( 0 , L_1 ) ;
V_3 = 1 ;
} else {
F_3 ( 0 , L_2 ) ;
V_3 = 2 ;
}
if ( V_4 & V_7 )
F_3 ( 0 , L_3 ) ;
else
F_3 ( 0 , L_4 ) ;
return V_3 ;
}
static bool F_4 ( struct V_1 * V_2 )
{
unsigned char V_8 ;
F_2 ( V_2 , V_5 + 3 , & V_8 ) ;
if ( V_8 & V_9 )
return false ;
return true ;
}
static int F_5 ( T_1 log )
{
return ( ( log & V_10 ) >>
V_11 ) ;
}
static void F_6 ( struct V_12 * V_13 )
{
F_7 ( F_8 ( V_13 -> V_2 ) , V_14 ,
V_15 , V_15 ) ;
}
static void F_9 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 = V_13 -> V_20 ;
V_2 = F_8 ( V_13 -> V_2 ) ;
F_10 ( V_2 , V_14 , & V_17 -> V_21 ) ;
if ( ! ( V_17 -> V_21 & V_15 ) )
return;
V_17 -> V_22 [ 0 ] = F_11 ( V_19 -> V_23 ) ;
if ( V_24 == 2 )
V_17 -> V_22 [ 1 ] = F_11 ( V_19 -> V_25 ) ;
F_10 ( V_2 , V_14 , & V_17 -> V_26 ) ;
if ( ( V_17 -> V_21 ^ V_17 -> V_26 ) & V_15 ) {
V_17 -> V_22 [ 0 ] = F_11 ( V_19 -> V_23 ) ;
if ( V_24 == 2 )
V_17 -> V_22 [ 1 ] =
F_11 ( V_19 -> V_25 ) ;
}
F_6 ( V_13 ) ;
}
static void F_12 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
int V_27 ;
T_1 log ;
if ( ! ( V_17 -> V_21 & V_15 ) )
return;
if ( ( V_17 -> V_21 ^ V_17 -> V_26 ) & V_15 ) {
F_13 ( V_28 , V_13 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 , L_5 , L_6 ) ;
V_17 -> V_21 = V_17 -> V_26 ;
}
for ( V_27 = 0 ; V_27 < V_24 ; V_27 ++ ) {
log = V_17 -> V_22 [ V_27 ] ;
if ( log & V_29 ) {
F_13 ( V_28 , V_13 , 1 ,
0 , 0 , 0 ,
F_5 ( log ) ,
V_27 , - 1 ,
L_7 , L_6 ) ;
} else if ( log & V_30 ) {
F_13 ( V_31 , V_13 , 1 ,
0 , 0 ,
F_14 ( log ) ,
F_5 ( log ) ,
V_27 , - 1 ,
L_8 , L_6 ) ;
}
}
}
static void F_15 ( struct V_12 * V_13 )
{
struct V_16 V_17 ;
F_3 ( 1 , L_9 , V_13 -> V_32 ) ;
F_9 ( V_13 , & V_17 ) ;
F_12 ( V_13 , & V_17 ) ;
}
static void T_2 * F_16 ( struct V_1 * V_2 )
{
union {
T_1 V_33 ;
struct {
T_3 V_34 ;
T_3 V_35 ;
};
} V_36 ;
void T_2 * V_37 ;
F_17 ( V_2 , V_38 , & V_36 . V_34 ) ;
F_17 ( V_2 , V_39 , & V_36 . V_35 ) ;
V_36 . V_33 &= V_40 ;
if ( V_36 . V_33 != ( V_41 ) V_36 . V_33 ) {
F_18 ( V_42 , L_10 ,
( unsigned long long ) V_36 . V_33 ) ;
return NULL ;
}
V_37 = F_19 ( V_36 . V_33 , V_43 ) ;
if ( ! V_37 )
F_18 ( V_42 , L_11 ,
( unsigned long long ) V_36 . V_33 ) ;
return V_37 ;
}
static void F_20 ( struct V_44 * V_45 , T_3 V_46 ,
int V_47 )
{
V_45 -> V_48 = ( V_46 >> ( V_47 << 4 ) ) & V_49 ;
V_45 -> V_50 = ( V_46 & ( V_51 << ( V_47 << 4 ) ) ) ? 1 : 0 ;
V_45 -> V_52 = ( ( V_46 & ( V_53 << ( V_47 << 4 ) ) ) >>
( V_54 + ( V_47 << 4 ) ) ) ;
}
static void F_21 ( struct V_44 * V_45 , T_3 V_46 ,
int V_47 )
{
V_45 -> V_48 = ( V_46 >> ( V_47 << 3 ) ) & V_49 ;
V_45 -> V_50 = ( V_46 & ( V_55 << V_47 ) ) ? 1 : 0 ;
V_45 -> V_52 = ( V_46 & ( V_56 << V_47 ) ) ? 1 : 0 ;
}
static void F_22 ( struct V_44 * V_45 , T_3 V_46 , int V_47 ,
bool V_57 )
{
if ( V_57 )
F_20 ( V_45 , V_46 , V_47 ) ;
else
F_21 ( V_45 , V_46 , V_47 ) ;
}
static int F_23 ( struct V_1 * V_2 , int V_58 )
{
int V_59 , V_60 , V_61 ;
struct V_12 * V_13 = NULL ;
struct V_62 V_63 [ 2 ] ;
struct V_44 V_64 [ V_65 ] [ V_66 ] ;
void T_2 * V_37 ;
struct V_18 * V_19 ;
T_3 V_46 , V_67 ;
bool V_57 = ( V_2 -> V_68 == V_69 ) ;
F_3 ( 0 , L_12 ) ;
if ( ! F_4 ( V_2 ) ) {
F_18 ( V_70 , L_13 ) ;
return - V_71 ;
}
V_24 = F_1 ( V_2 ) ;
V_63 [ 0 ] . type = V_72 ;
V_63 [ 0 ] . V_48 = V_73 ;
V_63 [ 0 ] . V_74 = true ;
V_63 [ 1 ] . type = V_75 ;
V_63 [ 1 ] . V_48 = V_24 ;
V_63 [ 1 ] . V_74 = false ;
V_13 = F_24 ( 0 , F_25 ( V_63 ) , V_63 ,
sizeof( struct V_18 ) ) ;
if ( ! V_13 )
return - V_76 ;
V_37 = F_16 ( V_2 ) ;
if ( ! V_37 ) {
V_61 = - V_71 ;
goto V_77;
}
F_3 ( 3 , L_14 ) ;
V_13 -> V_2 = & V_2 -> V_78 ;
if ( V_57 )
V_13 -> V_79 = V_80 ;
else
V_13 -> V_79 = V_81 ;
V_13 -> V_82 = V_83 ;
V_13 -> V_84 = V_83 ;
V_13 -> V_85 = V_86 ;
V_13 -> V_87 = V_88 ;
V_13 -> V_89 = V_90 [ V_58 ] . V_89 ;
V_13 -> V_91 = F_26 ( V_2 ) ;
V_13 -> V_92 = F_15 ;
V_13 -> V_93 = NULL ;
V_19 = V_13 -> V_20 ;
V_19 -> V_37 = V_37 ;
if ( V_57 ) {
V_19 -> V_23 = V_37 + V_94 ;
V_19 -> V_25 = V_37 + V_95 ;
V_67 = V_96 ;
} else {
V_19 -> V_23 = V_37 + V_97 ;
V_19 -> V_25 = V_37 + V_98 ;
V_67 = V_99 ;
}
for ( V_59 = 0 ; V_59 < V_65 ; V_59 ++ ) {
V_46 = F_27 ( V_37 + V_67 +
( V_59 * 4 ) ) ;
F_3 ( 0 , L_15 , V_46 ) ;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
F_22 ( & V_64 [ V_59 ] [ V_60 ] , V_46 , V_60 ,
V_57 ) ;
F_3 ( 0 , L_16 ,
V_64 [ V_59 ] [ V_60 ] . V_48 ,
V_64 [ V_59 ] [ V_60 ] . V_50 ,
V_64 [ V_59 ] [ V_60 ] . V_52 ) ;
}
}
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
for ( V_60 = 0 ; V_60 < V_65 ; V_60 ++ ) {
struct V_64 * V_100 ;
unsigned long V_101 ;
V_101 = F_28 ( V_64 [ V_60 ] [ V_59 ] . V_48 , V_57 ) ;
if ( V_101 == 0 )
continue;
if ( V_64 [ V_60 ] [ V_59 ] . V_50 ) {
V_101 = V_101 / 2 ;
V_100 = F_29 ( V_13 -> V_63 , V_13 -> V_102 ,
V_13 -> V_103 , ( V_59 * 2 ) + 1 ,
V_60 , 0 ) ;
V_100 -> V_101 = V_101 ;
F_3 ( 0 , L_17 , V_101 ) ;
V_100 -> V_104 = 8 ;
if ( V_57 )
V_100 -> V_105 = V_106 ;
else
V_100 -> V_105 = V_107 ;
V_100 -> V_108 = V_109 ;
V_100 -> V_110 = V_111 ;
}
V_100 = F_29 ( V_13 -> V_63 , V_13 -> V_102 ,
V_13 -> V_103 , V_59 * 2 , V_60 , 0 ) ;
V_100 -> V_101 = V_101 ;
F_3 ( 0 , L_17 , V_101 ) ;
V_100 -> V_104 = 8 ;
if ( V_57 )
V_100 -> V_105 = V_106 ;
else
V_100 -> V_105 = V_107 ;
V_100 -> V_108 = V_109 ;
V_100 -> V_110 = V_111 ;
}
}
F_6 ( V_13 ) ;
if ( F_30 ( V_13 ) ) {
F_3 ( 3 , L_18 ) ;
V_61 = - V_71 ;
goto V_112;
}
F_3 ( 3 , L_19 ) ;
return 0 ;
V_112:
F_31 ( V_37 ) ;
V_77:
F_32 ( V_13 ) ;
return V_61 ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_113 * V_114 )
{
F_3 ( 0 , L_12 ) ;
if ( F_34 ( V_2 ) < 0 )
return - V_115 ;
return F_23 ( V_2 , V_114 -> V_116 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_18 * V_19 ;
F_3 ( 0 , L_20 ) ;
V_13 = F_36 ( & V_2 -> V_78 ) ;
if ( ! V_13 )
return;
V_19 = V_13 -> V_20 ;
F_31 ( V_19 -> V_37 ) ;
F_32 ( V_13 ) ;
}
static int T_4 F_37 ( void )
{
F_3 ( 3 , L_12 ) ;
F_38 () ;
return F_39 ( & V_117 ) ;
}
static void T_5 F_40 ( void )
{
F_3 ( 3 , L_12 ) ;
F_41 ( & V_117 ) ;
}
