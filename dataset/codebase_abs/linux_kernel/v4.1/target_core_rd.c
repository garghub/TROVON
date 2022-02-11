static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_7 * V_7 ;
V_7 = F_4 ( sizeof( struct V_7 ) , V_8 ) ;
if ( ! V_7 ) {
F_5 ( L_1 ) ;
return - V_9 ;
}
V_7 -> V_10 = V_6 ;
V_5 -> V_11 = V_7 ;
F_6 ( L_2
L_3 , V_5 -> V_12 ,
V_13 , V_14 ) ;
return 0 ;
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_7 * V_7 = V_5 -> V_11 ;
F_6 ( L_4
L_5 , V_5 -> V_12 , V_7 -> V_10 ) ;
F_8 ( V_7 ) ;
V_5 -> V_11 = NULL ;
}
static T_1 F_9 ( struct V_1 * V_1 , struct V_15 * V_16 ,
T_1 V_17 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
T_1 V_22 , V_23 , V_24 = 0 , V_25 ;
for ( V_22 = 0 ; V_22 < V_17 ; V_22 ++ ) {
V_21 = V_16 [ V_22 ] . V_16 ;
V_25 = V_16 [ V_22 ] . V_26 ;
for ( V_23 = 0 ; V_23 < V_25 ; V_23 ++ ) {
V_19 = F_10 ( & V_21 [ V_23 ] ) ;
if ( V_19 ) {
F_11 ( V_19 ) ;
V_24 ++ ;
}
}
F_8 ( V_21 ) ;
}
F_8 ( V_16 ) ;
return V_24 ;
}
static void F_12 ( struct V_1 * V_1 )
{
T_1 V_24 ;
if ( ! V_1 -> V_27 || ! V_1 -> V_17 )
return;
V_24 = F_9 ( V_1 , V_1 -> V_27 ,
V_1 -> V_17 ) ;
F_6 ( L_6
L_7 ,
V_1 -> V_7 -> V_10 , V_1 -> V_28 , V_24 ,
V_1 -> V_17 , ( unsigned long ) V_24 * V_29 ) ;
V_1 -> V_27 = NULL ;
V_1 -> V_17 = 0 ;
}
static int F_13 ( struct V_1 * V_1 , struct V_15 * V_16 ,
T_1 V_30 , unsigned char V_31 )
{
T_1 V_22 = 0 , V_23 , V_32 = 0 , V_25 ;
T_1 V_33 = ( V_34 /
sizeof( struct V_20 ) ) ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
unsigned char * V_35 ;
while ( V_30 ) {
unsigned int V_36 = 0 ;
V_25 = ( V_30 > V_33 ) ?
V_33 : V_30 ;
#ifdef F_14
if ( V_25 < V_30 )
V_36 = 1 ;
#endif
V_21 = F_15 ( V_25 + V_36 , sizeof( * V_21 ) ,
V_8 ) ;
if ( ! V_21 ) {
F_5 ( L_8
L_9 ) ;
return - V_9 ;
}
F_16 ( V_21 , V_25 + V_36 ) ;
#ifdef F_14
if ( V_22 > 0 ) {
F_17 ( V_16 [ V_22 - 1 ] . V_16 ,
V_33 + 1 , V_21 ) ;
}
#endif
V_16 [ V_22 ] . V_16 = V_21 ;
V_16 [ V_22 ] . V_26 = V_25 ;
V_16 [ V_22 ] . V_37 = V_32 ;
V_16 [ V_22 ++ ] . V_38 = ( V_32 + V_25 )
- 1 ;
for ( V_23 = 0 ; V_23 < V_25 ; V_23 ++ ) {
V_19 = F_18 ( V_8 , 0 ) ;
if ( ! V_19 ) {
F_5 ( L_10
L_11 ) ;
return - V_9 ;
}
F_19 ( & V_21 [ V_23 ] , V_19 ) ;
V_21 [ V_23 ] . V_39 = V_29 ;
V_35 = F_20 ( V_19 ) ;
memset ( V_35 , V_31 , V_29 ) ;
F_21 ( V_19 ) ;
}
V_32 += V_25 ;
V_30 -= V_25 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_1 )
{
struct V_15 * V_16 ;
T_1 V_40 , V_30 ;
T_1 V_33 = ( V_34 /
sizeof( struct V_20 ) ) ;
int V_41 ;
if ( V_1 -> V_42 <= 0 ) {
F_5 ( L_12 ,
V_1 -> V_42 ) ;
return - V_43 ;
}
if ( V_1 -> V_44 & V_45 )
return 0 ;
V_30 = V_1 -> V_42 ;
V_40 = ( V_30 / V_33 ) + 1 ;
V_16 = F_4 ( V_40 * sizeof( struct V_15 ) , V_8 ) ;
if ( ! V_16 ) {
F_5 ( L_13
L_14 ) ;
return - V_9 ;
}
V_1 -> V_27 = V_16 ;
V_1 -> V_17 = V_40 ;
V_41 = F_13 ( V_1 , V_16 , V_30 , 0x00 ) ;
if ( V_41 )
return V_41 ;
F_6 ( L_15
L_16 , V_1 -> V_7 -> V_10 ,
V_1 -> V_28 , V_1 -> V_42 ,
V_1 -> V_17 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_1 )
{
T_1 V_24 ;
if ( ! V_1 -> V_46 || ! V_1 -> V_47 )
return;
V_24 = F_9 ( V_1 , V_1 -> V_46 ,
V_1 -> V_47 ) ;
F_6 ( L_17
L_7 ,
V_1 -> V_7 -> V_10 , V_1 -> V_28 , V_24 ,
V_1 -> V_17 , ( unsigned long ) V_24 * V_29 ) ;
V_1 -> V_46 = NULL ;
V_1 -> V_47 = 0 ;
}
static int F_24 ( struct V_1 * V_1 , int V_48 , int V_49 )
{
struct V_15 * V_16 ;
T_1 V_30 , V_40 ;
T_1 V_33 = ( V_34 /
sizeof( struct V_20 ) ) ;
int V_41 ;
if ( V_1 -> V_44 & V_45 )
return 0 ;
V_30 = ( V_1 -> V_42 * V_48 / V_49 ) + 1 ;
V_40 = ( V_30 / V_33 ) + 1 ;
V_16 = F_4 ( V_40 * sizeof( struct V_15 ) , V_8 ) ;
if ( ! V_16 ) {
F_5 ( L_18
L_14 ) ;
return - V_9 ;
}
V_1 -> V_46 = V_16 ;
V_1 -> V_47 = V_40 ;
V_41 = F_13 ( V_1 , V_16 , V_30 , 0xff ) ;
if ( V_41 )
return V_41 ;
F_6 ( L_19
L_16 , V_1 -> V_7 -> V_10 ,
V_1 -> V_28 , V_30 , V_1 -> V_47 ) ;
return 0 ;
}
static struct V_2 * F_25 ( struct V_4 * V_5 , const char * V_50 )
{
struct V_1 * V_1 ;
struct V_7 * V_7 = V_5 -> V_11 ;
V_1 = F_4 ( sizeof( struct V_1 ) , V_8 ) ;
if ( ! V_1 ) {
F_5 ( L_20 ) ;
return NULL ;
}
V_1 -> V_7 = V_7 ;
return & V_1 -> V_3 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_3 -> V_4 -> V_11 ;
int V_51 ;
if ( ! ( V_1 -> V_44 & V_52 ) ) {
F_6 ( L_21 ) ;
return - V_43 ;
}
V_51 = F_22 ( V_1 ) ;
if ( V_51 < 0 )
goto V_53;
V_3 -> V_54 . V_55 = V_56 ;
V_3 -> V_54 . V_57 = V_58 ;
V_3 -> V_54 . V_59 = V_60 ;
V_1 -> V_28 = V_7 -> V_61 ++ ;
F_6 ( L_22
L_23 ,
V_7 -> V_10 , V_1 -> V_28 , V_1 -> V_42 ,
V_1 -> V_17 ,
( unsigned long ) ( V_1 -> V_42 * V_29 ) ) ;
return 0 ;
V_53:
F_12 ( V_1 ) ;
return V_51 ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_12 ( V_1 ) ;
F_8 ( V_1 ) ;
}
static struct V_15 * F_28 ( struct V_1 * V_1 , T_1 V_18 )
{
struct V_15 * V_16 ;
T_1 V_22 , V_25 = ( V_34 /
sizeof( struct V_20 ) ) ;
V_22 = V_18 / V_25 ;
if ( V_22 < V_1 -> V_17 ) {
V_16 = & V_1 -> V_27 [ V_22 ] ;
if ( ( V_16 -> V_37 <= V_18 ) &&
( V_16 -> V_38 >= V_18 ) )
return V_16 ;
}
F_5 ( L_24 ,
V_18 ) ;
return NULL ;
}
static struct V_15 * F_29 ( struct V_1 * V_1 , T_1 V_18 )
{
struct V_15 * V_16 ;
T_1 V_22 , V_25 = ( V_34 /
sizeof( struct V_20 ) ) ;
V_22 = V_18 / V_25 ;
if ( V_22 < V_1 -> V_47 ) {
V_16 = & V_1 -> V_46 [ V_22 ] ;
if ( ( V_16 -> V_37 <= V_18 ) &&
( V_16 -> V_38 >= V_18 ) )
return V_16 ;
}
F_5 ( L_25 ,
V_18 ) ;
return NULL ;
}
static T_2 F_30 ( struct V_62 * V_63 , T_3 T_3 )
{
struct V_2 * V_64 = V_63 -> V_64 ;
struct V_1 * V_3 = F_1 ( V_64 ) ;
struct V_15 * V_65 ;
bool V_66 = false ;
struct V_20 * V_67 ;
T_1 V_68 = V_63 -> V_69 / V_64 -> V_54 . V_49 ;
T_1 V_70 , V_71 ;
T_1 T_4 V_72 ;
T_5 V_73 ;
T_2 V_41 = V_74 ;
V_73 = V_63 -> V_75 * V_64 -> V_48 ;
V_70 = F_31 ( V_73 , V_29 ) ;
V_71 = V_73 ;
V_65 = F_29 ( V_3 , V_71 ) ;
if ( ! V_65 )
return V_74 ;
V_67 = & V_65 -> V_16 [ V_71 -
V_65 -> V_37 ] ;
#ifndef F_14
T_4 = F_32 ( V_70 + V_68 * V_64 -> V_48 ,
V_29 ) ;
if ( V_65 -> V_38 < V_71 + T_4 - 1 ) {
int V_22 ;
V_67 = F_15 ( T_4 , sizeof( * V_67 ) , V_8 ) ;
if ( ! V_67 )
return V_74 ;
V_66 = true ;
F_16 ( V_67 , T_4 ) ;
for ( V_22 = 0 ; V_22 < T_4 ; V_22 ++ ) {
if ( V_71 + V_22 > V_65 -> V_38 ) {
V_65 = F_29 ( V_3 ,
V_71 + V_22 ) ;
if ( ! V_65 ) {
F_8 ( V_67 ) ;
return V_41 ;
}
F_33 ( & V_67 [ V_22 - 1 ] ) ;
}
V_67 [ V_22 ] = V_65 -> V_16 [ V_71 + V_22 -
V_65 -> V_37 ] ;
}
}
#endif
V_41 = T_3 ( V_63 , V_63 -> V_75 , V_68 , 0 , V_67 , V_70 ) ;
if ( V_66 )
F_8 ( V_67 ) ;
return V_41 ;
}
static T_2
F_34 ( struct V_62 * V_63 , struct V_20 * V_76 , T_1 V_77 ,
enum V_78 V_79 )
{
struct V_2 * V_64 = V_63 -> V_64 ;
struct V_1 * V_3 = F_1 ( V_64 ) ;
struct V_15 * V_80 ;
struct V_20 * V_81 ;
struct V_82 V_83 ;
T_1 V_84 ;
T_1 V_85 ;
T_1 V_86 ;
T_1 V_87 ;
T_5 V_73 ;
T_2 V_41 ;
if ( V_3 -> V_44 & V_45 ) {
F_35 ( V_63 , V_88 ) ;
return 0 ;
}
V_73 = V_63 -> V_75 * V_64 -> V_54 . V_49 ;
V_84 = F_31 ( V_73 , V_29 ) ;
V_86 = V_73 ;
V_85 = V_63 -> V_69 ;
V_80 = F_28 ( V_3 , V_86 ) ;
if ( ! V_80 )
return V_74 ;
V_81 = & V_80 -> V_16 [ V_86 - V_80 -> V_37 ] ;
F_6 ( L_26 ,
V_3 -> V_28 ,
V_79 == V_89 ? L_27 : L_28 ,
V_63 -> V_75 , V_85 , V_86 , V_84 ) ;
if ( V_63 -> V_90 && V_64 -> V_54 . V_91 &&
V_79 == V_92 ) {
V_41 = F_30 ( V_63 , V_93 ) ;
if ( V_41 )
return V_41 ;
}
V_87 = V_29 - V_84 ;
F_36 ( & V_83 , V_76 , V_77 ,
V_79 == V_89 ?
V_94 : V_95 ) ;
while ( V_85 ) {
T_1 V_96 ;
void * V_97 ;
F_37 ( & V_83 ) ;
if ( ! ( T_1 ) V_83 . V_39 ) {
F_6 ( L_29 ,
V_3 -> V_28 , V_83 . V_98 , V_83 . V_39 ) ;
F_38 ( & V_83 ) ;
return V_99 ;
}
V_96 = F_39 ( ( T_1 ) V_83 . V_39 , V_87 ) ;
if ( V_96 > V_85 ) {
F_6 ( L_30
L_31 , V_3 -> V_28 ,
V_86 , V_84 , V_85 ) ;
V_96 = V_85 ;
}
V_83 . V_100 = V_96 ;
V_97 = F_40 ( V_81 ) + V_84 ;
if ( V_79 == V_89 )
memcpy ( V_83 . V_98 , V_97 , V_96 ) ;
else
memcpy ( V_97 , V_83 . V_98 , V_96 ) ;
V_85 -= V_96 ;
if ( ! V_85 )
continue;
V_87 -= V_96 ;
if ( V_87 ) {
V_84 += V_96 ;
continue;
}
V_86 ++ ;
V_84 = 0 ;
V_87 = V_29 ;
if ( V_86 <= V_80 -> V_38 ) {
V_81 ++ ;
continue;
}
V_80 = F_28 ( V_3 , V_86 ) ;
if ( ! V_80 ) {
F_38 ( & V_83 ) ;
return V_74 ;
}
V_81 = V_80 -> V_16 ;
}
F_38 ( & V_83 ) ;
if ( V_63 -> V_90 && V_64 -> V_54 . V_91 &&
V_79 == V_89 ) {
V_41 = F_30 ( V_63 , V_101 ) ;
if ( V_41 )
return V_41 ;
}
F_35 ( V_63 , V_88 ) ;
return 0 ;
}
static T_6 F_41 ( struct V_2 * V_3 ,
const char * V_18 , T_6 V_102 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
char * V_103 , * V_104 , * V_105 ;
T_7 args [ V_106 ] ;
int V_51 = 0 , V_107 , V_108 ;
V_105 = F_42 ( V_18 , V_8 ) ;
if ( ! V_105 )
return - V_9 ;
V_103 = V_105 ;
while ( ( V_104 = F_43 ( & V_105 , L_32 ) ) != NULL ) {
if ( ! * V_104 )
continue;
V_108 = F_44 ( V_104 , V_109 , args ) ;
switch ( V_108 ) {
case V_110 :
F_45 ( args , & V_107 ) ;
V_1 -> V_42 = V_107 ;
F_6 ( L_33
L_34 , V_1 -> V_42 ) ;
V_1 -> V_44 |= V_52 ;
break;
case V_111 :
F_45 ( args , & V_107 ) ;
if ( V_107 != 1 )
break;
F_6 ( L_35 , V_107 ) ;
V_1 -> V_44 |= V_45 ;
break;
default:
break;
}
}
F_8 ( V_103 ) ;
return ( ! V_51 ) ? V_102 : V_51 ;
}
static T_6 F_46 ( struct V_2 * V_3 , char * V_112 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_6 V_113 = sprintf ( V_112 , L_36 ,
V_1 -> V_28 ) ;
V_113 += sprintf ( V_112 + V_113 , L_37
L_38 , V_1 -> V_42 ,
V_29 , V_1 -> V_17 ,
! ! ( V_1 -> V_44 & V_45 ) ) ;
return V_113 ;
}
static T_8 F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long long V_114 = ( ( V_1 -> V_42 * V_29 ) /
V_3 -> V_54 . V_49 ) - 1 ;
return V_114 ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_3 -> V_54 . V_91 )
return 0 ;
return F_24 ( V_1 , V_3 -> V_48 ,
V_3 -> V_54 . V_49 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_23 ( V_1 ) ;
}
static T_2
F_50 ( struct V_62 * V_63 )
{
return F_51 ( V_63 , & V_115 ) ;
}
int T_9 F_52 ( void )
{
struct V_116 * V_117 = & V_118 . V_119 ;
int V_51 ;
F_53 ( & V_118 ) ;
V_117 -> V_120 . V_121 = V_122 ;
V_51 = F_54 ( & V_118 ) ;
if ( V_51 < 0 ) {
return V_51 ;
}
return 0 ;
}
void F_55 ( void )
{
F_56 ( & V_118 ) ;
}
