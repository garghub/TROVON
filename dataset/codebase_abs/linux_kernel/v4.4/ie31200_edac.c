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
static int F_5 ( int V_10 , T_1 log )
{
int V_11 = ( ( log & V_12 ) >>
V_13 ) ;
return V_11 | ( V_10 * V_14 ) ;
}
static void F_6 ( struct V_15 * V_16 )
{
F_7 ( F_8 ( V_16 -> V_2 ) , V_17 ,
V_18 , V_18 ) ;
}
static void F_9 ( struct V_15 * V_16 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 = V_16 -> V_23 ;
void T_2 * V_24 = V_22 -> V_24 ;
V_2 = F_8 ( V_16 -> V_2 ) ;
F_10 ( V_2 , V_17 , & V_20 -> V_25 ) ;
if ( ! ( V_20 -> V_25 & V_18 ) )
return;
V_20 -> V_26 [ 0 ] = F_11 ( V_24 + V_27 ) ;
if ( V_28 == 2 )
V_20 -> V_26 [ 1 ] = F_11 ( V_24 + V_29 ) ;
F_10 ( V_2 , V_17 , & V_20 -> V_30 ) ;
if ( ( V_20 -> V_25 ^ V_20 -> V_30 ) & V_18 ) {
V_20 -> V_26 [ 0 ] = F_11 ( V_24 + V_27 ) ;
if ( V_28 == 2 )
V_20 -> V_26 [ 1 ] =
F_11 ( V_24 + V_29 ) ;
}
F_6 ( V_16 ) ;
}
static void F_12 ( struct V_15 * V_16 ,
struct V_19 * V_20 )
{
int V_10 ;
T_1 log ;
if ( ! ( V_20 -> V_25 & V_18 ) )
return;
if ( ( V_20 -> V_25 ^ V_20 -> V_30 ) & V_18 ) {
F_13 ( V_31 , V_16 , 1 , 0 , 0 , 0 ,
- 1 , - 1 , - 1 , L_5 , L_6 ) ;
V_20 -> V_25 = V_20 -> V_30 ;
}
for ( V_10 = 0 ; V_10 < V_28 ; V_10 ++ ) {
log = V_20 -> V_26 [ V_10 ] ;
if ( log & V_32 ) {
F_13 ( V_31 , V_16 , 1 ,
0 , 0 , 0 ,
F_5 ( V_10 , log ) ,
V_10 , - 1 ,
L_7 , L_6 ) ;
} else if ( log & V_33 ) {
F_13 ( V_34 , V_16 , 1 ,
0 , 0 ,
F_14 ( log ) ,
F_5 ( V_10 , log ) ,
V_10 , - 1 ,
L_8 , L_6 ) ;
}
}
}
static void F_15 ( struct V_15 * V_16 )
{
struct V_19 V_20 ;
F_3 ( 1 , L_9 , V_16 -> V_35 ) ;
F_9 ( V_16 , & V_20 ) ;
F_12 ( V_16 , & V_20 ) ;
}
static void T_2 * F_16 ( struct V_1 * V_2 )
{
union {
T_1 V_36 ;
struct {
T_3 V_37 ;
T_3 V_38 ;
};
} V_39 ;
void T_2 * V_24 ;
F_17 ( V_2 , V_40 , & V_39 . V_37 ) ;
F_17 ( V_2 , V_41 , & V_39 . V_38 ) ;
V_39 . V_36 &= V_42 ;
if ( V_39 . V_36 != ( V_43 ) V_39 . V_36 ) {
F_18 ( V_44 , L_10 ,
( unsigned long long ) V_39 . V_36 ) ;
return NULL ;
}
V_24 = F_19 ( V_39 . V_36 , V_45 ) ;
if ( ! V_24 )
F_18 ( V_44 , L_11 ,
( unsigned long long ) V_39 . V_36 ) ;
return V_24 ;
}
static int F_20 ( struct V_1 * V_2 , int V_46 )
{
int V_47 , V_48 , V_49 ;
struct V_15 * V_16 = NULL ;
struct V_50 V_51 [ 2 ] ;
struct V_52 V_53 [ V_54 ] [ V_55 ] ;
void T_2 * V_24 ;
struct V_21 * V_22 ;
T_3 V_56 ;
F_3 ( 0 , L_12 ) ;
if ( ! F_4 ( V_2 ) ) {
F_18 ( V_57 , L_13 ) ;
return - V_58 ;
}
V_28 = F_1 ( V_2 ) ;
V_51 [ 0 ] . type = V_59 ;
V_51 [ 0 ] . V_60 = V_61 ;
V_51 [ 0 ] . V_62 = true ;
V_51 [ 1 ] . type = V_63 ;
V_51 [ 1 ] . V_60 = V_28 ;
V_51 [ 1 ] . V_62 = false ;
V_16 = F_21 ( 0 , F_22 ( V_51 ) , V_51 ,
sizeof( struct V_21 ) ) ;
if ( ! V_16 )
return - V_64 ;
V_24 = F_16 ( V_2 ) ;
if ( ! V_24 ) {
V_49 = - V_58 ;
goto V_65;
}
F_3 ( 3 , L_14 ) ;
V_16 -> V_2 = & V_2 -> V_66 ;
V_16 -> V_67 = V_68 ;
V_16 -> V_69 = V_70 ;
V_16 -> V_71 = V_70 ;
V_16 -> V_72 = V_73 ;
V_16 -> V_74 = V_75 ;
V_16 -> V_76 = V_77 [ V_46 ] . V_76 ;
V_16 -> V_78 = F_23 ( V_2 ) ;
V_16 -> V_79 = F_15 ;
V_16 -> V_80 = NULL ;
V_22 = V_16 -> V_23 ;
V_22 -> V_24 = V_24 ;
for ( V_47 = 0 ; V_47 < V_54 ; V_47 ++ ) {
V_56 = F_24 ( V_24 + V_81 +
( V_47 * 4 ) ) ;
F_3 ( 0 , L_15 , V_56 ) ;
for ( V_48 = 0 ; V_48 < V_55 ; V_48 ++ ) {
V_53 [ V_47 ] [ V_48 ] . V_60 = ( V_56 >> ( V_48 * 8 ) ) &
V_82 ;
V_53 [ V_47 ] [ V_48 ] . V_83 = ( V_56 &
( V_84 << V_48 ) ) ? 1 : 0 ;
V_53 [ V_47 ] [ V_48 ] . V_85 = ( V_56 &
( V_86 << V_48 ) ) ? 1 : 0 ;
F_3 ( 0 , L_16 ,
V_53 [ V_47 ] [ V_48 ] . V_60 ,
V_53 [ V_47 ] [ V_48 ] . V_83 ,
V_53 [ V_47 ] [ V_48 ] . V_85 ) ;
}
}
for ( V_47 = 0 ; V_47 < V_55 ; V_47 ++ ) {
for ( V_48 = 0 ; V_48 < V_54 ; V_48 ++ ) {
struct V_53 * V_87 ;
unsigned long V_88 ;
V_88 = F_25 ( V_53 [ V_48 ] [ V_47 ] . V_60 ) ;
if ( V_88 == 0 )
continue;
if ( V_53 [ V_48 ] [ V_47 ] . V_83 ) {
V_88 = V_88 / 2 ;
V_87 = F_26 ( V_16 -> V_51 , V_16 -> V_89 ,
V_16 -> V_90 , ( V_47 * 2 ) + 1 ,
V_48 , 0 ) ;
V_87 -> V_88 = V_88 ;
F_3 ( 0 , L_17 , V_88 ) ;
V_87 -> V_91 = 8 ;
V_87 -> V_92 = V_93 ;
V_87 -> V_94 = V_95 ;
V_87 -> V_96 = V_97 ;
}
V_87 = F_26 ( V_16 -> V_51 , V_16 -> V_89 ,
V_16 -> V_90 , V_47 * 2 , V_48 , 0 ) ;
V_87 -> V_88 = V_88 ;
F_3 ( 0 , L_17 , V_88 ) ;
V_87 -> V_91 = 8 ;
V_87 -> V_92 = V_93 ;
V_87 -> V_94 = V_95 ;
V_87 -> V_96 = V_97 ;
}
}
F_6 ( V_16 ) ;
if ( F_27 ( V_16 ) ) {
F_3 ( 3 , L_18 ) ;
V_49 = - V_58 ;
goto V_98;
}
F_3 ( 3 , L_19 ) ;
return 0 ;
V_98:
F_28 ( V_24 ) ;
V_65:
F_29 ( V_16 ) ;
return V_49 ;
}
static int F_30 ( struct V_1 * V_2 ,
const struct V_99 * V_100 )
{
F_3 ( 0 , L_12 ) ;
if ( F_31 ( V_2 ) < 0 )
return - V_101 ;
return F_20 ( V_2 , V_100 -> V_102 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_21 * V_22 ;
F_3 ( 0 , L_20 ) ;
V_16 = F_33 ( & V_2 -> V_66 ) ;
if ( ! V_16 )
return;
V_22 = V_16 -> V_23 ;
F_28 ( V_22 -> V_24 ) ;
F_29 ( V_16 ) ;
}
static int T_4 F_34 ( void )
{
F_3 ( 3 , L_12 ) ;
F_35 () ;
return F_36 ( & V_103 ) ;
}
static void T_5 F_37 ( void )
{
F_3 ( 3 , L_12 ) ;
F_38 ( & V_103 ) ;
}
