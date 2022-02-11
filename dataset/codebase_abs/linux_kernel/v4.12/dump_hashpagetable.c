static int F_1 ( struct V_1 * V_2 , int V_3 , char V_4 [] )
{
static const char V_5 [] = L_1 ;
const char * V_6 = V_5 ;
while ( V_3 > 9 && V_6 [ 1 ] ) {
V_3 -= 10 ;
V_6 ++ ;
}
F_2 ( V_2 -> V_7 , L_2 , V_4 , 1 << V_3 , * V_6 ) ;
return V_3 ;
}
static void F_3 ( struct V_1 * V_2 , const struct V_8
* V_9 , T_1 V_10 , int V_11 )
{
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ , V_9 ++ ) {
const char * V_4 = NULL ;
T_1 V_13 ;
if ( V_9 -> V_14 == 0 )
continue;
if ( V_9 -> V_15 ) {
V_13 = V_10 & V_9 -> V_13 ;
if ( V_9 -> V_16 )
V_13 = V_13 >> V_9 -> V_16 ;
F_2 ( V_2 -> V_7 , L_3 , V_9 -> V_17 , V_13 ) ;
} else {
if ( ( V_10 & V_9 -> V_14 ) == V_9 -> V_13 )
V_4 = V_9 -> V_17 ;
else
V_4 = V_9 -> V_18 ;
if ( V_4 )
F_2 ( V_2 -> V_7 , L_4 , V_4 ) ;
}
}
}
static void F_4 ( struct V_1 * V_2 , unsigned long V_19 , T_1 V_20 , T_1 V_21 ,
unsigned long V_22 , int V_23 , int V_24 , unsigned long V_25 )
{
int V_26 ;
while ( V_19 >= V_2 -> V_27 [ 1 ] . V_28 ) {
V_2 -> V_27 ++ ;
F_2 ( V_2 -> V_7 , L_5 , V_2 -> V_27 -> V_29 ) ;
}
F_2 ( V_2 -> V_7 , L_6 , V_19 ) ;
F_2 ( V_2 -> V_7 , L_7 , F_5 ( V_20 ) ) ;
F_3 ( V_2 , V_30 , V_20 , F_6 ( V_30 ) ) ;
F_2 ( V_2 -> V_7 , L_8 , V_22 ) ;
F_3 ( V_2 , V_31 , V_21 , F_6 ( V_31 ) ) ;
F_1 ( V_2 , V_23 , L_9 ) ;
V_26 = F_1 ( V_2 , V_24 , L_10 ) ;
if ( V_26 != 2 )
F_2 ( V_2 -> V_7 , L_11 , V_25 ) ;
F_7 ( V_2 -> V_7 , L_12 ) ;
}
static int F_8 ( unsigned long V_19 , int V_32 , bool V_33 , T_1 * V_20 , T_1
* V_21 )
{
struct V_34 * V_35 ;
unsigned long V_36 , V_37 , V_38 , V_39 , V_40 , V_41 ;
int V_12 , V_42 = V_43 ;
unsigned long V_16 = V_44 [ V_32 ] . V_16 ;
V_37 = F_9 ( V_19 , V_42 ) ;
V_38 = F_10 ( V_19 , V_37 , V_42 ) ;
V_36 = F_11 ( V_38 , V_16 , V_42 ) ;
V_40 = F_12 ( V_38 , V_32 , V_42 ) ;
if ( ! V_33 )
V_36 = ~ V_36 ;
V_39 = ( V_36 & V_45 ) * V_46 ;
for ( V_12 = 0 ; V_12 < V_46 ; V_12 ++ ) {
V_35 = V_47 + V_39 ;
V_41 = F_13 ( V_35 -> V_20 ) ;
if ( F_14 ( V_41 , V_40 ) && ( V_41 & V_48 ) ) {
* V_20 = F_13 ( V_35 -> V_20 ) ;
* V_21 = F_13 ( V_35 -> V_21 ) ;
return 0 ;
}
++ V_39 ;
}
return - 1 ;
}
static int F_15 ( unsigned long V_19 , int V_32 , bool V_33 , T_1 * V_20 , T_1 * V_21 )
{
struct V_34 V_49 [ 4 ] ;
unsigned long V_37 , V_38 , V_36 , V_39 , V_40 ;
int V_12 , V_50 , V_42 = V_43 ;
long V_51 = 0 ;
unsigned long V_16 = V_44 [ V_32 ] . V_16 ;
V_37 = F_9 ( V_19 , V_42 ) ;
V_38 = F_10 ( V_19 , V_37 , V_42 ) ;
V_36 = F_11 ( V_38 , V_16 , V_42 ) ;
V_40 = F_12 ( V_38 , V_32 , V_42 ) ;
if ( ! V_33 )
V_36 = ~ V_36 ;
V_39 = ( ( V_36 & V_45 ) * V_46 ) & ~ 0x7UL ;
for ( V_12 = 0 ; V_12 < V_46 ; V_12 += 4 , V_39 += 4 ) {
V_51 = F_16 ( 0 , V_39 , ( void * ) V_49 ) ;
if ( V_51 != V_52 )
continue;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
if ( F_14 ( V_49 [ V_50 ] . V_20 , V_40 ) &&
( V_49 [ V_50 ] . V_20 & V_48 ) ) {
* V_20 = V_49 [ V_50 ] . V_20 ;
* V_21 = V_49 [ V_50 ] . V_21 ;
return 0 ;
}
}
}
return - 1 ;
}
static void F_17 ( int V_23 , unsigned long V_21 , unsigned long * V_22 , int * V_24 ,
unsigned long * V_53 )
{
struct V_54 V_55 ;
unsigned long V_56 , V_14 , V_25 ;
int V_57 = - 2 , V_58 = 0 , V_16 ;
V_56 = ( V_21 & V_59 ) >> V_60 ;
V_25 = V_56 & 0xff ;
V_55 = V_44 [ V_23 ] ;
while ( V_58 < V_61 ) {
V_57 = V_55 . V_57 [ V_58 ] ;
if ( ( V_57 != - 1 ) && ( V_44 [ V_58 ] . V_16 ) ) {
V_16 = V_44 [ V_58 ] . V_16 - V_60 ;
V_14 = ( 0x1 << ( V_16 ) ) - 1 ;
if ( ( V_25 & V_14 ) == V_57 ) {
* V_24 = F_18 ( V_58 ) ;
* V_53 = V_25 & V_14 ;
* V_22 = V_56 >> V_16 ;
return;
}
}
V_58 ++ ;
}
}
static int F_19 ( unsigned long V_19 , int V_32 , bool V_33 , T_1 * V_20 ,
T_1 * V_21 )
{
#ifdef F_20
if ( F_21 ( V_62 ) )
return F_15 ( V_19 , V_32 , V_33 , V_20 , V_21 ) ;
#endif
return F_8 ( V_19 , V_32 , V_33 , V_20 , V_21 ) ;
}
static unsigned long F_22 ( struct V_1 * V_2 , unsigned long V_19 , int V_32 )
{
unsigned long V_63 ;
T_1 V_20 = 0 , V_21 = 0 ;
unsigned long V_22 , V_53 ;
int V_64 = 0 , V_65 = 0 ;
if ( V_19 <= V_66 )
return - 1 ;
V_63 = F_19 ( V_19 , V_32 , true , & V_20 , & V_21 ) ;
if ( V_63 == - 1 )
V_63 = F_19 ( V_19 , V_32 , true , & V_20 , & V_21 ) ;
if ( V_63 == - 1 )
return - 1 ;
V_64 = F_18 ( V_32 ) ;
if ( ( V_20 & V_67 ) == V_67 ) {
F_17 ( V_32 , V_21 , & V_22 , & V_65 , & V_53 ) ;
} else {
V_65 = 12 ;
V_22 = ( V_21 & V_59 ) >> V_60 ;
V_53 = - 1 ;
}
if ( V_65 == - 1 )
return - 1 ;
F_4 ( V_2 , V_19 , V_20 , V_21 , V_22 , V_64 , V_65 , V_53 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , T_2 * V_68 , unsigned long V_69 )
{
T_3 * V_10 = F_24 ( V_68 , 0 ) ;
unsigned long V_70 , V_71 , V_32 ;
int V_12 , V_72 ;
for ( V_12 = 0 ; V_12 < V_73 ; V_12 ++ , V_10 ++ ) {
V_70 = V_69 + V_12 * V_74 ;
V_71 = F_25 ( * V_10 ) ;
if ( V_70 < V_75 )
V_32 = V_76 ;
else
V_32 = V_77 ;
#ifdef F_26
if ( ( ( V_71 & V_78 ) == V_78 ) ||
( ( V_71 & V_79 ) == V_79 ) )
V_32 = V_77 ;
#endif
V_72 = F_22 ( V_2 , V_70 , V_32 ) ;
if ( ( ( V_71 & V_80 ) != V_80 )
&& ( V_72 != - 1 ) ) {
F_2 ( V_2 -> V_7 , L_13
L_14 ,
V_70 , V_71 ) ;
}
}
}
static void F_27 ( struct V_1 * V_2 , T_4 * V_81 , unsigned long V_69 )
{
T_2 * V_68 = F_28 ( V_81 , 0 ) ;
unsigned long V_70 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_82 ; V_12 ++ , V_68 ++ ) {
V_70 = V_69 + V_12 * V_83 ;
if ( ! F_29 ( * V_68 ) )
F_23 ( V_2 , V_68 , V_70 ) ;
}
}
static void F_30 ( struct V_1 * V_2 , T_5 * V_84 , unsigned long V_69 )
{
T_4 * V_81 = F_31 ( V_84 , 0 ) ;
unsigned long V_70 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_85 ; V_12 ++ , V_81 ++ ) {
V_70 = V_69 + V_12 * V_86 ;
if ( ! F_32 ( * V_81 ) )
F_27 ( V_2 , V_81 , V_70 ) ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
T_5 * V_84 = F_34 ( 0UL ) ;
unsigned int V_12 ;
unsigned long V_70 ;
for ( V_12 = 0 ; V_12 < V_87 ; V_12 ++ , V_84 ++ ) {
V_70 = V_88 + V_12 * V_89 ;
if ( ! F_35 ( * V_84 ) )
F_30 ( V_2 , V_84 , V_70 ) ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
unsigned long V_70 ;
unsigned long V_32 = 1 << V_44 [ V_90 ] . V_16 ;
for ( V_70 = V_66 ; V_70 < V_66 +
F_37 () ; V_70 += V_32 )
F_22 ( V_2 , V_70 , V_90 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
#ifdef F_39
struct V_91 * V_92 = V_93 ;
while ( V_92 -> V_94 ) {
F_22 ( V_2 , V_92 -> V_95 , V_96 ) ;
V_92 = V_92 -> V_94 ;
}
F_7 ( V_2 -> V_7 , L_15 ) ;
#endif
}
static void F_40 ( void )
{
V_97 [ 0 ] . V_28 = V_66 ;
V_97 [ 1 ] . V_28 = V_98 ;
V_97 [ 2 ] . V_28 = V_75 ;
V_97 [ 3 ] . V_28 = V_99 ;
V_97 [ 4 ] . V_28 = V_100 ;
V_97 [ 5 ] . V_28 = V_101 ;
V_97 [ 6 ] . V_28 = V_102 ;
V_97 [ 7 ] . V_28 = V_103 ;
V_97 [ 8 ] . V_28 = V_104 ;
#ifdef F_41
V_97 [ 9 ] . V_28 = V_105 ;
#else
V_97 [ 9 ] . V_28 = V_106 ;
#endif
}
static int F_42 ( struct V_107 * V_108 , void * V_20 )
{
struct V_1 V_2 = {
. V_7 = V_108 ,
. V_28 = V_66 ,
. V_27 = V_97 ,
} ;
F_36 ( & V_2 ) ;
F_33 ( & V_2 ) ;
F_38 ( & V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_44 ( V_110 , F_42 , NULL ) ;
}
static int F_45 ( void )
{
struct V_111 * V_112 ;
if ( ! F_46 () ) {
F_40 () ;
V_112 = F_47 ( L_16 ,
0400 , NULL , NULL , & V_113 ) ;
return V_112 ? 0 : - V_114 ;
}
return 0 ;
}
