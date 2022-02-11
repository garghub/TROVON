static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_7 * V_7 ;
V_7 = F_4 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
return - V_9 ;
V_7 -> V_10 = V_6 ;
V_5 -> V_11 = V_7 ;
F_5 ( L_1
L_2 , V_5 -> V_12 ,
V_13 , V_14 ) ;
return 0 ;
}
static void F_6 ( struct V_4 * V_5 )
{
struct V_7 * V_7 = V_5 -> V_11 ;
F_5 ( L_3
L_4 , V_5 -> V_12 , V_7 -> V_10 ) ;
F_7 ( V_7 ) ;
V_5 -> V_11 = NULL ;
}
static T_1 F_8 ( struct V_1 * V_1 , struct V_15 * V_16 ,
T_1 V_17 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
T_1 V_22 , V_23 , V_24 = 0 , V_25 ;
for ( V_22 = 0 ; V_22 < V_17 ; V_22 ++ ) {
V_21 = V_16 [ V_22 ] . V_16 ;
V_25 = V_16 [ V_22 ] . V_26 ;
for ( V_23 = 0 ; V_23 < V_25 ; V_23 ++ ) {
V_19 = F_9 ( & V_21 [ V_23 ] ) ;
if ( V_19 ) {
F_10 ( V_19 ) ;
V_24 ++ ;
}
}
F_7 ( V_21 ) ;
}
F_7 ( V_16 ) ;
return V_24 ;
}
static void F_11 ( struct V_1 * V_1 )
{
T_1 V_24 ;
if ( ! V_1 -> V_27 || ! V_1 -> V_17 )
return;
V_24 = F_8 ( V_1 , V_1 -> V_27 ,
V_1 -> V_17 ) ;
F_5 ( L_5
L_6 ,
V_1 -> V_7 -> V_10 , V_1 -> V_28 , V_24 ,
V_1 -> V_17 , ( unsigned long ) V_24 * V_29 ) ;
V_1 -> V_27 = NULL ;
V_1 -> V_17 = 0 ;
}
static int F_12 ( struct V_1 * V_1 , struct V_15 * V_16 ,
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
if ( V_25 < V_30 )
V_36 = 1 ;
V_21 = F_13 ( V_25 + V_36 , sizeof( * V_21 ) ,
V_8 ) ;
if ( ! V_21 )
return - V_9 ;
F_14 ( V_21 , V_25 + V_36 ) ;
if ( V_22 > 0 ) {
F_15 ( V_16 [ V_22 - 1 ] . V_16 ,
V_33 + 1 , V_21 ) ;
}
V_16 [ V_22 ] . V_16 = V_21 ;
V_16 [ V_22 ] . V_26 = V_25 ;
V_16 [ V_22 ] . V_37 = V_32 ;
V_16 [ V_22 ++ ] . V_38 = ( V_32 + V_25 )
- 1 ;
for ( V_23 = 0 ; V_23 < V_25 ; V_23 ++ ) {
V_19 = F_16 ( V_8 , 0 ) ;
if ( ! V_19 ) {
F_17 ( L_7
L_8 ) ;
return - V_9 ;
}
F_18 ( & V_21 [ V_23 ] , V_19 ) ;
V_21 [ V_23 ] . V_39 = V_29 ;
V_35 = F_19 ( V_19 ) ;
memset ( V_35 , V_31 , V_29 ) ;
F_20 ( V_19 ) ;
}
V_32 += V_25 ;
V_30 -= V_25 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_15 * V_16 ;
T_1 V_40 , V_30 ;
T_1 V_33 = ( V_34 /
sizeof( struct V_20 ) ) ;
int V_41 ;
if ( V_1 -> V_42 <= 0 ) {
F_17 ( L_9 ,
V_1 -> V_42 ) ;
return - V_43 ;
}
if ( V_1 -> V_44 & V_45 )
return 0 ;
V_30 = V_1 -> V_42 ;
V_40 = ( V_30 / V_33 ) + 1 ;
V_16 = F_13 ( V_40 , sizeof( * V_16 ) , V_8 ) ;
if ( ! V_16 )
return - V_9 ;
V_1 -> V_27 = V_16 ;
V_1 -> V_17 = V_40 ;
V_41 = F_12 ( V_1 , V_16 , V_30 , 0x00 ) ;
if ( V_41 )
return V_41 ;
F_5 ( L_10
L_11 , V_1 -> V_7 -> V_10 ,
V_1 -> V_28 , V_1 -> V_42 ,
V_1 -> V_17 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_1 )
{
T_1 V_24 ;
if ( ! V_1 -> V_46 || ! V_1 -> V_47 )
return;
V_24 = F_8 ( V_1 , V_1 -> V_46 ,
V_1 -> V_47 ) ;
F_5 ( L_12
L_6 ,
V_1 -> V_7 -> V_10 , V_1 -> V_28 , V_24 ,
V_1 -> V_17 , ( unsigned long ) V_24 * V_29 ) ;
V_1 -> V_46 = NULL ;
V_1 -> V_47 = 0 ;
}
static int F_23 ( struct V_1 * V_1 , int V_48 , int V_49 )
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
V_16 = F_13 ( V_40 , sizeof( * V_16 ) , V_8 ) ;
if ( ! V_16 )
return - V_9 ;
V_1 -> V_46 = V_16 ;
V_1 -> V_47 = V_40 ;
V_41 = F_12 ( V_1 , V_16 , V_30 , 0xff ) ;
if ( V_41 )
return V_41 ;
F_5 ( L_13
L_11 , V_1 -> V_7 -> V_10 ,
V_1 -> V_28 , V_30 , V_1 -> V_47 ) ;
return 0 ;
}
static struct V_2 * F_24 ( struct V_4 * V_5 , const char * V_50 )
{
struct V_1 * V_1 ;
struct V_7 * V_7 = V_5 -> V_11 ;
V_1 = F_4 ( sizeof( * V_1 ) , V_8 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_7 = V_7 ;
return & V_1 -> V_3 ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_3 -> V_4 -> V_11 ;
int V_51 ;
if ( ! ( V_1 -> V_44 & V_52 ) ) {
F_5 ( L_14 ) ;
return - V_43 ;
}
V_51 = F_21 ( V_1 ) ;
if ( V_51 < 0 )
goto V_53;
V_3 -> V_54 . V_55 = V_56 ;
V_3 -> V_54 . V_57 = V_58 ;
V_3 -> V_54 . V_59 = V_60 ;
V_3 -> V_54 . V_61 = 1 ;
V_1 -> V_28 = V_7 -> V_62 ++ ;
F_5 ( L_15
L_16 ,
V_7 -> V_10 , V_1 -> V_28 , V_1 -> V_42 ,
V_1 -> V_17 ,
( unsigned long ) ( V_1 -> V_42 * V_29 ) ) ;
return 0 ;
V_53:
F_11 ( V_1 ) ;
return V_51 ;
}
static void F_26 ( struct V_63 * V_35 )
{
struct V_2 * V_3 = F_2 ( V_35 , struct V_2 , V_63 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_7 ( V_1 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_11 ( V_1 ) ;
F_28 ( & V_3 -> V_63 , F_26 ) ;
}
static struct V_15 * F_29 ( struct V_1 * V_1 , T_1 V_18 )
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
F_17 ( L_17 ,
V_18 ) ;
return NULL ;
}
static struct V_15 * F_30 ( struct V_1 * V_1 , T_1 V_18 )
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
F_17 ( L_18 ,
V_18 ) ;
return NULL ;
}
static T_2 F_31 ( struct V_64 * V_65 , bool V_66 )
{
struct V_2 * V_67 = V_65 -> V_67 ;
struct V_1 * V_3 = F_1 ( V_67 ) ;
struct V_15 * V_68 ;
struct V_20 * V_69 ;
T_1 V_70 = V_65 -> V_71 / V_67 -> V_54 . V_49 ;
T_1 V_72 , V_73 ;
T_1 T_3 V_74 ;
T_4 V_75 ;
T_2 V_41 = 0 ;
V_75 = V_65 -> V_76 * V_67 -> V_48 ;
V_72 = F_32 ( V_75 , V_29 ) ;
V_73 = V_75 ;
V_68 = F_30 ( V_3 , V_73 ) ;
if ( ! V_68 )
return V_77 ;
V_69 = & V_68 -> V_16 [ V_73 -
V_68 -> V_37 ] ;
if ( V_67 -> V_54 . V_78 ) {
if ( V_66 )
V_41 = F_33 ( V_65 , V_65 -> V_76 , V_70 , 0 ,
V_69 , V_72 ) ;
else
V_41 = F_33 ( V_65 , V_65 -> V_76 , V_70 , 0 ,
V_65 -> V_79 , 0 ) ;
}
if ( ! V_41 )
F_34 ( V_65 , V_70 , V_66 , V_69 , V_72 ) ;
return V_41 ;
}
static T_2
F_35 ( struct V_64 * V_65 , struct V_20 * V_80 , T_1 V_81 ,
enum V_82 V_83 )
{
struct V_2 * V_67 = V_65 -> V_67 ;
struct V_1 * V_3 = F_1 ( V_67 ) ;
struct V_15 * V_84 ;
struct V_20 * V_85 ;
struct V_86 V_87 ;
T_1 V_88 ;
T_1 V_89 ;
T_1 V_90 ;
T_1 V_91 ;
T_4 V_75 ;
T_2 V_41 ;
if ( V_3 -> V_44 & V_45 ) {
F_36 ( V_65 , V_92 ) ;
return 0 ;
}
V_75 = V_65 -> V_76 * V_67 -> V_54 . V_49 ;
V_88 = F_32 ( V_75 , V_29 ) ;
V_90 = V_75 ;
V_89 = V_65 -> V_71 ;
V_84 = F_29 ( V_3 , V_90 ) ;
if ( ! V_84 )
return V_77 ;
V_85 = & V_84 -> V_16 [ V_90 - V_84 -> V_37 ] ;
F_5 ( L_19 ,
V_3 -> V_28 ,
V_83 == V_93 ? L_20 : L_21 ,
V_65 -> V_76 , V_89 , V_90 , V_88 ) ;
if ( V_65 -> V_94 && V_67 -> V_54 . V_95 &&
V_83 == V_96 ) {
V_41 = F_31 ( V_65 , false ) ;
if ( V_41 )
return V_41 ;
}
V_91 = V_29 - V_88 ;
F_37 ( & V_87 , V_80 , V_81 ,
V_83 == V_93 ?
V_97 : V_98 ) ;
while ( V_89 ) {
T_1 V_99 ;
void * V_100 ;
F_38 ( & V_87 ) ;
if ( ! ( T_1 ) V_87 . V_39 ) {
F_5 ( L_22 ,
V_3 -> V_28 , V_87 . V_101 , V_87 . V_39 ) ;
F_39 ( & V_87 ) ;
return V_102 ;
}
V_99 = F_40 ( ( T_1 ) V_87 . V_39 , V_91 ) ;
if ( V_99 > V_89 ) {
F_5 ( L_23
L_24 , V_3 -> V_28 ,
V_90 , V_88 , V_89 ) ;
V_99 = V_89 ;
}
V_87 . V_103 = V_99 ;
V_100 = F_41 ( V_85 ) + V_88 ;
if ( V_83 == V_93 )
memcpy ( V_87 . V_101 , V_100 , V_99 ) ;
else
memcpy ( V_100 , V_87 . V_101 , V_99 ) ;
V_89 -= V_99 ;
if ( ! V_89 )
continue;
V_91 -= V_99 ;
if ( V_91 ) {
V_88 += V_99 ;
continue;
}
V_90 ++ ;
V_88 = 0 ;
V_91 = V_29 ;
if ( V_90 <= V_84 -> V_38 ) {
V_85 ++ ;
continue;
}
V_84 = F_29 ( V_3 , V_90 ) ;
if ( ! V_84 ) {
F_39 ( & V_87 ) ;
return V_77 ;
}
V_85 = V_84 -> V_16 ;
}
F_39 ( & V_87 ) ;
if ( V_65 -> V_94 && V_67 -> V_54 . V_95 &&
V_83 == V_93 ) {
V_41 = F_31 ( V_65 , true ) ;
if ( V_41 )
return V_41 ;
}
F_36 ( V_65 , V_92 ) ;
return 0 ;
}
static T_5 F_42 ( struct V_2 * V_3 ,
const char * V_18 , T_5 V_104 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
char * V_105 , * V_106 , * V_107 ;
T_6 args [ V_108 ] ;
int V_51 = 0 , V_109 , V_110 ;
V_107 = F_43 ( V_18 , V_8 ) ;
if ( ! V_107 )
return - V_9 ;
V_105 = V_107 ;
while ( ( V_106 = F_44 ( & V_107 , L_25 ) ) != NULL ) {
if ( ! * V_106 )
continue;
V_110 = F_45 ( V_106 , V_111 , args ) ;
switch ( V_110 ) {
case V_112 :
F_46 ( args , & V_109 ) ;
V_1 -> V_42 = V_109 ;
F_5 ( L_26
L_27 , V_1 -> V_42 ) ;
V_1 -> V_44 |= V_52 ;
break;
case V_113 :
F_46 ( args , & V_109 ) ;
if ( V_109 != 1 )
break;
F_5 ( L_28 , V_109 ) ;
V_1 -> V_44 |= V_45 ;
break;
default:
break;
}
}
F_7 ( V_105 ) ;
return ( ! V_51 ) ? V_104 : V_51 ;
}
static T_5 F_47 ( struct V_2 * V_3 , char * V_114 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_5 V_115 = sprintf ( V_114 , L_29 ,
V_1 -> V_28 ) ;
V_115 += sprintf ( V_114 + V_115 , L_30
L_31 , V_1 -> V_42 ,
V_29 , V_1 -> V_17 ,
! ! ( V_1 -> V_44 & V_45 ) ) ;
return V_115 ;
}
static T_7 F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long long V_116 = ( ( V_1 -> V_42 * V_29 ) /
V_3 -> V_54 . V_49 ) - 1 ;
return V_116 ;
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_3 -> V_54 . V_95 )
return 0 ;
return F_23 ( V_1 , V_3 -> V_48 ,
V_3 -> V_54 . V_49 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_22 ( V_1 ) ;
}
static T_2
F_51 ( struct V_64 * V_65 )
{
return F_52 ( V_65 , & V_117 ) ;
}
int T_8 F_53 ( void )
{
return F_54 ( & V_118 ) ;
}
void F_55 ( void )
{
F_56 ( & V_118 ) ;
}
