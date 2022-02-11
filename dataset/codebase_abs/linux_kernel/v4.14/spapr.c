static int F_1 ( int V_1 , int V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return - V_6 ;
F_3 ( & V_4 -> V_7 ) ;
V_4 -> V_1 = V_1 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_8 = F_2 ( V_4 -> V_2 , V_9 ) ;
F_4 ( & V_4 -> V_10 , & V_11 ) ;
F_5 ( L_1 , V_4 -> V_1 ,
V_4 -> V_1 + V_4 -> V_2 - 1 ) ;
return 0 ;
}
static int F_6 ( struct V_3 * V_4 )
{
int V_12 ;
V_12 = F_7 ( V_4 -> V_8 , V_4 -> V_2 ) ;
if ( V_12 != V_4 -> V_2 ) {
F_8 ( V_12 , V_4 -> V_8 ) ;
V_12 += V_4 -> V_1 ;
} else {
V_12 = - V_6 ;
}
return V_12 ;
}
static int F_9 ( void )
{
struct V_3 * V_4 ;
unsigned long V_13 ;
int V_12 = - V_14 ;
F_10 (xibm, &xive_irq_bitmaps, list) {
F_11 ( & V_4 -> V_7 , V_13 ) ;
V_12 = F_6 ( V_4 ) ;
F_12 ( & V_4 -> V_7 , V_13 ) ;
if ( V_12 >= 0 )
break;
}
return V_12 ;
}
static void F_13 ( int V_12 )
{
unsigned long V_13 ;
struct V_3 * V_4 ;
F_10 (xibm, &xive_irq_bitmaps, list) {
if ( ( V_12 >= V_4 -> V_1 ) && ( V_12 < V_4 -> V_1 + V_4 -> V_2 ) ) {
F_11 ( & V_4 -> V_7 , V_13 ) ;
F_14 ( V_12 - V_4 -> V_1 , V_4 -> V_8 ) ;
F_12 ( & V_4 -> V_7 , V_13 ) ;
break;
}
}
}
static long F_15 ( unsigned long V_13 ,
unsigned long V_15 ,
unsigned long * V_16 ,
unsigned long * V_17 ,
unsigned long * V_18 ,
unsigned long * V_19 )
{
unsigned long V_20 [ V_21 ] ;
long V_22 ;
V_22 = F_16 ( V_23 , V_20 , V_13 , V_15 ) ;
if ( V_22 ) {
F_17 ( L_2 , V_15 , V_22 ) ;
return V_22 ;
}
* V_16 = V_20 [ 0 ] ;
* V_17 = V_20 [ 1 ] ;
* V_18 = V_20 [ 2 ] ;
* V_19 = V_20 [ 3 ] ;
F_18 ( L_3 ,
V_20 [ 0 ] , V_20 [ 1 ] , V_20 [ 2 ] , V_20 [ 3 ] ) ;
return 0 ;
}
static long F_19 ( unsigned long V_13 ,
unsigned long V_15 ,
unsigned long V_24 ,
unsigned long V_25 ,
unsigned long V_26 )
{
long V_22 ;
F_18 ( L_4 ,
V_13 , V_15 , V_24 , V_25 , V_26 ) ;
V_22 = F_20 ( V_27 , V_13 , V_15 ,
V_24 , V_25 , V_26 ) ;
if ( V_22 ) {
F_17 ( L_5 ,
V_15 , V_24 , V_25 , V_22 ) ;
return V_22 ;
}
return 0 ;
}
static long F_21 ( unsigned long V_13 ,
unsigned long V_24 ,
unsigned long V_28 ,
unsigned long * V_29 ,
unsigned long * V_30 )
{
unsigned long V_20 [ V_21 ] ;
long V_22 ;
V_22 = F_16 ( V_31 , V_20 , V_13 , V_24 , V_28 ) ;
if ( V_22 ) {
F_17 ( L_6 ,
V_24 , V_28 , V_22 ) ;
return V_22 ;
}
* V_29 = V_20 [ 0 ] ;
* V_30 = V_20 [ 1 ] ;
F_18 ( L_7 ,
V_20 [ 0 ] , V_20 [ 1 ] ) ;
return 0 ;
}
static long F_22 ( unsigned long V_13 ,
unsigned long V_24 ,
unsigned long V_28 ,
unsigned long V_32 ,
unsigned long V_33 )
{
long V_22 ;
F_18 ( L_8 ,
V_13 , V_24 , V_28 , V_32 , V_33 ) ;
V_22 = F_20 ( V_34 , V_13 , V_24 ,
V_28 , V_32 , V_33 ) ;
if ( V_22 ) {
F_17 ( L_9 ,
V_24 , V_28 , V_32 , V_22 ) ;
return V_22 ;
}
return 0 ;
}
static long F_23 ( unsigned long V_13 , unsigned long V_15 )
{
long V_22 ;
V_22 = F_20 ( V_35 , V_13 , V_15 ) ;
if ( V_22 ) {
F_17 ( L_10 , V_15 , V_22 ) ;
return V_22 ;
}
return 0 ;
}
static long F_24 ( unsigned long V_13 ,
unsigned long V_15 ,
unsigned long V_36 ,
unsigned long V_37 ,
unsigned long * V_38 )
{
unsigned long V_20 [ V_21 ] ;
long V_22 ;
F_18 ( L_11 ,
V_13 , V_15 , V_36 , V_37 ) ;
V_22 = F_16 ( V_39 , V_20 , V_13 , V_15 , V_36 , V_37 ) ;
if ( V_22 ) {
F_17 ( L_12 ,
V_15 , V_36 , V_22 ) ;
return V_22 ;
}
* V_38 = V_20 [ 0 ] ;
return 0 ;
}
static T_1 F_25 ( T_2 V_15 , T_2 V_36 , T_1 V_40 , bool V_41 )
{
unsigned long V_42 ;
long V_22 ;
V_22 = F_24 ( V_41 ? V_43 : 0 ,
V_15 , V_36 , V_40 , & V_42 ) ;
if ( V_22 )
return - 1 ;
return V_41 ? 0 : V_42 ;
}
static int F_26 ( T_2 V_44 , struct V_45 * V_40 )
{
long V_22 ;
unsigned long V_13 ;
unsigned long V_17 ;
unsigned long V_18 ;
unsigned long V_19 ;
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
V_22 = F_15 ( 0 , V_44 , & V_13 , & V_17 , & V_18 ,
& V_19 ) ;
if ( V_22 )
return - V_46 ;
if ( V_13 & V_47 )
V_40 -> V_13 |= V_48 ;
if ( V_13 & V_49 )
V_40 -> V_13 |= V_50 ;
if ( V_13 & V_51 )
V_40 -> V_13 |= V_52 ;
V_40 -> V_17 = V_17 ;
V_40 -> V_19 = V_19 ;
V_40 -> V_18 = V_18 ;
V_40 -> V_53 = V_54 ;
V_40 -> V_55 = F_27 ( V_40 -> V_17 , 1u << V_40 -> V_19 ) ;
if ( ! V_40 -> V_55 ) {
F_17 ( L_13 , V_44 ) ;
return - V_6 ;
}
V_40 -> V_44 = V_44 ;
if ( V_13 & V_56 ) {
V_40 -> V_57 = V_40 -> V_55 ;
return 0 ;
}
V_40 -> V_57 = F_27 ( V_40 -> V_18 , 1u << V_40 -> V_19 ) ;
if ( ! V_40 -> V_57 ) {
F_17 ( L_14 , V_44 ) ;
return - V_6 ;
}
return 0 ;
}
static int F_28 ( T_2 V_44 , T_2 V_24 , T_3 V_25 , T_2 V_26 )
{
long V_22 ;
V_22 = F_19 ( V_58 , V_44 , V_24 ,
V_25 , V_26 ) ;
return V_22 == 0 ? 0 : - V_59 ;
}
static int F_29 ( T_2 V_24 , struct V_60 * V_61 , T_3 V_25 ,
T_4 * V_32 , T_2 V_62 )
{
T_5 V_22 = 0 ;
unsigned long V_29 ;
unsigned long V_30 ;
T_1 V_13 , V_63 ;
if ( V_62 ) {
if ( F_30 ( ! V_32 ) )
return - V_46 ;
V_63 = F_31 ( V_32 ) ;
} else {
V_63 = 0 ;
}
V_61 -> V_64 = V_62 ? ( ( 1u << ( V_62 - 2 ) ) - 1 ) : 0 ;
V_61 -> V_65 = 0 ;
V_61 -> V_66 = 0 ;
V_22 = F_21 ( 0 , V_24 , V_25 , & V_29 , & V_30 ) ;
if ( V_22 ) {
F_17 ( L_15 , V_22 , V_25 ) ;
V_22 = - V_67 ;
goto V_68;
}
V_61 -> V_69 = V_29 ;
V_13 = V_70 ;
V_22 = F_22 ( V_13 , V_24 , V_25 , V_63 , V_62 ) ;
if ( V_22 ) {
F_17 ( L_16 , V_22 , V_25 ) ;
V_22 = - V_67 ;
} else {
V_61 -> V_32 = V_32 ;
}
V_68:
return V_22 ;
}
static int F_32 ( unsigned int V_71 , struct V_72 * V_73 ,
T_3 V_25 )
{
struct V_60 * V_61 = & V_73 -> V_74 [ V_25 ] ;
T_4 * V_32 ;
V_32 = F_33 ( V_71 , V_75 ) ;
if ( F_34 ( V_32 ) )
return F_35 ( V_32 ) ;
return F_29 ( V_71 , V_61 , V_25 , V_32 ,
V_75 ) ;
}
static void F_36 ( unsigned int V_71 , struct V_72 * V_73 ,
T_3 V_25 )
{
struct V_60 * V_61 = & V_73 -> V_74 [ V_25 ] ;
unsigned int V_76 ;
long V_22 ;
V_22 = F_22 ( 0 , V_71 , V_25 , 0 , 0 ) ;
if ( V_22 )
F_17 ( L_17 , V_22 , V_25 ) ;
V_76 = F_37 ( V_75 ) ;
F_38 ( ( unsigned long ) V_61 -> V_32 , V_76 ) ;
V_61 -> V_32 = NULL ;
}
static bool F_39 ( struct V_77 * V_78 )
{
return 1 ;
}
static int F_40 ( unsigned int V_71 , struct V_72 * V_73 )
{
int V_12 = F_9 () ;
if ( V_12 < 0 ) {
F_17 ( L_18 , V_71 ) ;
return - V_59 ;
}
V_73 -> V_79 = V_12 ;
return 0 ;
}
static void F_41 ( unsigned int V_71 , struct V_72 * V_73 )
{
if ( ! V_73 -> V_79 )
return;
F_13 ( V_73 -> V_79 ) ;
V_73 -> V_79 = 0 ;
}
static void F_42 ( void )
{
long V_22 ;
V_22 = F_20 ( V_80 , 0 ) ;
if ( V_22 )
F_17 ( L_19 , V_22 ) ;
}
static void F_43 ( struct V_72 * V_73 )
{
T_3 V_81 , V_82 ;
T_6 V_83 ;
V_83 = F_44 ( F_45 ( V_84 + V_85 ) ) ;
F_46 () ;
V_82 = V_83 & 0xff ;
V_81 = V_83 >> 8 ;
if ( V_81 & V_86 ) {
if ( V_82 == 0xff )
return;
V_73 -> V_87 |= 1 << V_82 ;
if ( V_82 >= V_73 -> V_82 )
F_17 ( L_20 ,
F_47 () , V_82 , V_73 -> V_82 ) ;
V_73 -> V_82 = V_82 ;
}
}
static void F_48 ( T_2 V_44 )
{
;
}
static void F_49 ( unsigned int V_71 , struct V_72 * V_73 )
{
F_50 ( L_21 ,
F_51 ( V_84 + V_88 + V_89 ) ,
F_51 ( V_84 + V_88 + V_90 ) ,
F_51 ( V_84 + V_88 + V_91 ) ) ;
}
static void F_52 ( unsigned int V_71 , struct V_72 * V_73 )
{
;
}
static void F_53 ( T_2 V_44 )
{
F_23 ( 0 , V_44 ) ;
}
static bool F_54 ( T_3 * V_92 )
{
struct V_77 * V_93 ;
const T_4 * V_94 ;
T_2 V_95 ;
int V_25 , V_96 ;
V_93 = F_55 ( L_22 ) ;
if ( ! V_93 ) {
F_17 ( L_23 ) ;
return false ;
}
V_94 = F_56 ( V_93 , L_24 , & V_95 ) ;
if ( ! V_94 ) {
F_17 ( L_25 ) ;
return false ;
}
if ( V_95 % ( 2 * sizeof( T_2 ) ) != 0 ) {
F_17 ( L_26 ) ;
return false ;
}
V_96 = 0xFF ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ ) {
int V_97 = 0 ;
int V_98 ;
for ( V_98 = 0 ; V_98 < V_95 / ( 2 * sizeof( T_2 ) ) ; V_98 ++ ) {
int V_1 = F_57 ( V_94 [ 2 * V_98 ] ) ;
int V_99 = F_57 ( V_94 [ 2 * V_98 + 1 ] ) ;
if ( V_25 >= V_1 && V_25 < V_1 + V_99 )
V_97 ++ ;
}
if ( ! V_97 )
V_96 = V_25 ;
}
if ( V_96 == 0xFF ) {
F_17 ( L_27 ) ;
return false ;
}
* V_92 = V_96 ;
return true ;
}
bool T_7 F_58 ( void )
{
struct V_77 * V_100 ;
struct V_101 V_102 ;
void T_8 * V_103 ;
struct V_104 * V_105 ;
T_3 V_92 ;
T_2 V_106 ;
T_2 V_95 ;
const T_4 * V_94 ;
int V_98 ;
if ( V_107 )
return false ;
F_18 ( L_28 , V_108 ) ;
V_100 = F_59 ( NULL , NULL , L_29 ) ;
if ( ! V_100 ) {
F_18 ( L_30 ) ;
return false ;
}
F_18 ( L_31 , V_100 -> V_109 ) ;
if ( F_60 ( V_100 , 1 , & V_102 ) ) {
F_17 ( L_32 ) ;
return false ;
}
V_103 = F_27 ( V_102 . V_110 , F_61 ( & V_102 ) ) ;
if ( ! V_103 ) {
F_17 ( L_33 ) ;
return false ;
}
if ( ! F_54 ( & V_92 ) )
return false ;
V_94 = F_56 ( V_100 , L_34 , & V_95 ) ;
if ( ! V_94 ) {
F_17 ( L_35 ) ;
return false ;
}
if ( V_95 % ( 2 * sizeof( T_2 ) ) != 0 ) {
F_17 ( L_36 ) ;
return false ;
}
for ( V_98 = 0 ; V_98 < V_95 / ( 2 * sizeof( T_2 ) ) ; V_98 ++ , V_94 += 2 )
F_1 ( F_57 ( V_94 [ 0 ] ) ,
F_57 ( V_94 [ 1 ] ) ) ;
F_62 (np, L_37 , prop, reg, val) {
V_75 = V_106 ;
if ( V_106 == V_111 )
break;
}
if ( ! F_63 ( & V_112 , V_103 , V_88 , V_92 ) )
return false ;
F_5 ( L_38 , 1 << ( V_75 - 10 ) ) ;
return true ;
}
