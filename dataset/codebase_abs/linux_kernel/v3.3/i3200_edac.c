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
F_13 ( V_13 , L_3 ) ;
V_18 -> V_23 = V_18 -> V_28 ;
}
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ ) {
log = V_18 -> V_24 [ V_7 ] ;
if ( log & V_29 ) {
F_14 ( V_13 , 0 , 0 ,
F_5 ( V_7 , log ) ,
L_4 ) ;
} else if ( log & V_30 ) {
F_15 ( V_13 , 0 , 0 ,
F_4 ( log ) ,
F_5 ( V_7 , log ) , 0 ,
L_5 ) ;
}
}
}
static void F_16 ( struct V_12 * V_13 )
{
struct V_17 V_18 ;
F_17 ( L_6 , V_13 -> V_31 , V_32 ) ;
F_9 ( V_13 , & V_18 ) ;
F_12 ( V_13 , & V_18 ) ;
}
void T_2 * F_18 ( struct V_1 * V_2 )
{
union {
T_1 V_33 ;
struct {
T_3 V_34 ;
T_3 V_35 ;
};
} V_36 ;
void T_2 * V_22 ;
F_19 ( V_2 , V_37 , & V_36 . V_34 ) ;
F_19 ( V_2 , V_38 , & V_36 . V_35 ) ;
V_36 . V_33 &= V_39 ;
if ( V_36 . V_33 != ( V_40 ) V_36 . V_33 ) {
F_20 ( V_41
L_7 ,
( unsigned long long ) V_36 . V_33 ) ;
return NULL ;
}
V_22 = F_21 ( V_36 . V_33 , V_42 ) ;
if ( ! V_22 )
F_20 ( V_41 L_8 ,
( unsigned long long ) V_36 . V_33 ) ;
return V_22 ;
}
static void F_22 ( void T_2 * V_22 ,
T_4 V_43 [ V_44 ] [ V_11 ] )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_11 ; V_45 ++ ) {
V_43 [ 0 ] [ V_45 ] = F_23 ( V_22 + V_46 + 2 * V_45 ) & V_47 ;
V_43 [ 1 ] [ V_45 ] = F_23 ( V_22 + V_48 + 2 * V_45 ) & V_47 ;
}
}
static bool F_24 ( struct V_1 * V_2 ,
T_4 V_43 [ V_44 ] [ V_11 ] )
{
T_4 V_49 ;
F_10 ( V_2 , V_50 , & V_49 ) ;
V_49 &= V_51 ;
return V_43 [ V_44 - 1 ] [ V_11 - 1 ] == V_49 ;
}
static unsigned long F_25 (
T_4 V_43 [ V_44 ] [ V_11 ] , bool V_52 ,
int V_7 , int V_8 )
{
int V_53 ;
V_53 = V_43 [ V_7 ] [ V_8 ] ;
if ( V_8 > 0 )
V_53 -= V_43 [ V_7 ] [ V_8 - 1 ] ;
if ( V_52 && ( V_7 == 1 ) &&
V_43 [ V_7 ] [ V_8 ] == V_43 [ V_7 ] [ V_11 - 1 ] )
V_53 -= V_43 [ 0 ] [ V_11 - 1 ] ;
V_53 <<= ( V_54 - V_55 ) ;
return V_53 ;
}
static int F_26 ( struct V_1 * V_2 , int V_56 )
{
int V_57 ;
int V_45 ;
struct V_12 * V_13 = NULL ;
unsigned long V_58 ;
T_4 V_43 [ V_44 ] [ V_11 ] ;
bool V_52 ;
void T_2 * V_22 ;
struct V_19 * V_20 ;
F_3 ( L_9 , V_32 ) ;
V_22 = F_18 ( V_2 ) ;
if ( ! V_22 )
return - V_59 ;
F_22 ( V_22 , V_43 ) ;
V_26 = F_1 ( V_2 ) ;
V_13 = F_27 ( sizeof( struct V_19 ) , V_60 ,
V_26 , 0 ) ;
if ( ! V_13 )
return - V_61 ;
F_28 ( L_10 , V_32 ) ;
V_13 -> V_14 = & V_2 -> V_14 ;
V_13 -> V_62 = V_63 ;
V_13 -> V_64 = V_65 ;
V_13 -> V_66 = V_65 ;
V_13 -> V_67 = V_68 ;
V_13 -> V_69 = V_70 ;
V_13 -> V_71 = V_72 [ V_56 ] . V_71 ;
V_13 -> V_73 = F_29 ( V_2 ) ;
V_13 -> V_74 = F_16 ;
V_13 -> V_75 = NULL ;
V_20 = V_13 -> V_21 ;
V_20 -> V_22 = V_22 ;
V_52 = F_24 ( V_2 , V_43 ) ;
V_58 = - 1UL ;
for ( V_45 = 0 ; V_45 < V_13 -> V_76 ; V_45 ++ ) {
unsigned long V_77 ;
struct V_78 * V_79 = & V_13 -> V_80 [ V_45 ] ;
V_77 = F_25 ( V_43 , V_52 ,
V_45 / V_11 ,
V_45 % V_11 ) ;
if ( V_77 == 0 ) {
V_79 -> V_81 = V_82 ;
continue;
}
V_79 -> V_83 = V_58 + 1 ;
V_58 += V_77 ;
V_79 -> V_58 = V_58 ;
V_79 -> V_77 = V_77 ;
V_79 -> V_84 = V_77 << V_55 ;
V_79 -> V_81 = V_85 ;
V_79 -> V_86 = V_87 ;
V_79 -> V_88 = V_89 ;
}
F_6 ( V_13 ) ;
V_57 = - V_59 ;
if ( F_30 ( V_13 ) ) {
F_28 ( L_11 , V_32 ) ;
goto V_90;
}
F_28 ( L_12 , V_32 ) ;
return 0 ;
V_90:
F_31 ( V_22 ) ;
if ( V_13 )
F_32 ( V_13 ) ;
return V_57 ;
}
static int T_5 F_33 ( struct V_1 * V_2 ,
const struct V_91 * V_92 )
{
int V_57 ;
F_3 ( L_9 , V_32 ) ;
if ( F_34 ( V_2 ) < 0 )
return - V_93 ;
V_57 = F_26 ( V_2 , V_92 -> V_94 ) ;
if ( ! V_95 )
V_95 = F_35 ( V_2 ) ;
return V_57 ;
}
static void T_6 F_36 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_19 * V_20 ;
F_3 ( L_13 , V_32 ) ;
V_13 = F_37 ( & V_2 -> V_14 ) ;
if ( ! V_13 )
return;
V_20 = V_13 -> V_21 ;
F_31 ( V_20 -> V_22 ) ;
F_32 ( V_13 ) ;
}
static int T_7 F_38 ( void )
{
int V_96 ;
F_28 ( L_9 , V_32 ) ;
F_39 () ;
V_96 = F_40 ( & V_97 ) ;
if ( V_96 < 0 )
goto V_98;
if ( ! V_95 ) {
V_99 = 0 ;
V_95 = F_41 ( V_100 ,
V_101 , NULL ) ;
if ( ! V_95 ) {
F_3 ( L_14 ) ;
V_96 = - V_59 ;
goto V_102;
}
V_96 = F_33 ( V_95 , V_103 ) ;
if ( V_96 < 0 ) {
F_3 ( L_15 ) ;
V_96 = - V_59 ;
goto V_102;
}
}
return 0 ;
V_102:
F_42 ( & V_97 ) ;
V_98:
if ( V_95 )
F_43 ( V_95 ) ;
return V_96 ;
}
static void T_8 F_44 ( void )
{
F_28 ( L_9 , V_32 ) ;
F_42 ( & V_97 ) ;
if ( ! V_99 ) {
F_36 ( V_95 ) ;
F_43 ( V_95 ) ;
}
}
