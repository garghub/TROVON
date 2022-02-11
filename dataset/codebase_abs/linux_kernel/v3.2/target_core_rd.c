static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 ;
V_4 = F_2 ( sizeof( struct V_4 ) , V_5 ) ;
if ( ! V_4 ) {
F_3 ( L_1 ) ;
return - V_6 ;
}
V_4 -> V_7 = V_3 ;
V_2 -> V_8 = V_4 ;
F_4 ( L_2
L_3 , V_2 -> V_9 ,
V_10 , V_11 ) ;
F_4 ( L_4
L_5 , V_2 -> V_9 ,
V_4 -> V_7 , V_12 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_8 ;
F_4 ( L_6
L_7 , V_2 -> V_9 , V_4 -> V_7 ) ;
F_6 ( V_4 ) ;
V_2 -> V_8 = NULL ;
}
static void F_7 ( struct V_13 * V_13 )
{
T_1 V_14 , V_15 , V_16 = 0 , V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
if ( ! V_13 -> V_24 || ! V_13 -> V_25 )
return;
V_19 = V_13 -> V_24 ;
for ( V_14 = 0 ; V_14 < V_13 -> V_25 ; V_14 ++ ) {
V_23 = V_19 [ V_14 ] . V_19 ;
V_17 = V_19 [ V_14 ] . V_26 ;
for ( V_15 = 0 ; V_15 < V_17 ; V_15 ++ ) {
V_21 = F_8 ( & V_23 [ V_15 ] ) ;
if ( V_21 ) {
F_9 ( V_21 ) ;
V_16 ++ ;
}
}
F_6 ( V_23 ) ;
}
F_4 ( L_8
L_9 ,
V_13 -> V_4 -> V_7 , V_13 -> V_27 , V_16 ,
V_13 -> V_25 , ( unsigned long ) V_16 * V_28 ) ;
F_6 ( V_19 ) ;
V_13 -> V_24 = NULL ;
V_13 -> V_25 = 0 ;
}
static int F_10 ( struct V_13 * V_13 )
{
T_1 V_14 = 0 , V_15 , V_29 = 0 , V_17 , V_30 , V_31 ;
T_1 V_32 = ( V_33 /
sizeof( struct V_22 ) ) ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
if ( V_13 -> V_34 <= 0 ) {
F_3 ( L_10 ,
V_13 -> V_34 ) ;
return - V_35 ;
}
V_31 = V_13 -> V_34 ;
V_30 = ( V_31 / V_32 ) + 1 ;
V_19 = F_2 ( V_30 * sizeof( struct V_18 ) , V_5 ) ;
if ( ! V_19 ) {
F_3 ( L_11
L_12 ) ;
return - V_6 ;
}
V_13 -> V_24 = V_19 ;
V_13 -> V_25 = V_30 ;
while ( V_31 ) {
V_17 = ( V_31 > V_32 ) ?
V_32 : V_31 ;
V_23 = F_2 ( V_17 * sizeof( struct V_22 ) ,
V_5 ) ;
if ( ! V_23 ) {
F_3 ( L_13
L_14 ) ;
return - V_6 ;
}
F_11 ( V_23 , V_17 ) ;
V_19 [ V_14 ] . V_19 = V_23 ;
V_19 [ V_14 ] . V_26 = V_17 ;
V_19 [ V_14 ] . V_36 = V_29 ;
V_19 [ V_14 ++ ] . V_37 = ( V_29 + V_17 )
- 1 ;
for ( V_15 = 0 ; V_15 < V_17 ; V_15 ++ ) {
V_21 = F_12 ( V_5 , 0 ) ;
if ( ! V_21 ) {
F_3 ( L_15
L_16 ) ;
return - V_6 ;
}
F_13 ( & V_23 [ V_15 ] , V_21 ) ;
V_23 [ V_15 ] . V_38 = V_28 ;
}
V_29 += V_17 ;
V_31 -= V_17 ;
}
F_4 ( L_17
L_18 , V_13 -> V_4 -> V_7 ,
V_13 -> V_27 , V_13 -> V_34 ,
V_13 -> V_25 ) ;
return 0 ;
}
static void * F_14 (
struct V_1 * V_2 ,
const char * V_39 ,
int V_40 )
{
struct V_13 * V_13 ;
struct V_4 * V_4 = V_2 -> V_8 ;
V_13 = F_2 ( sizeof( struct V_13 ) , V_5 ) ;
if ( ! V_13 ) {
F_3 ( L_19 ) ;
return NULL ;
}
V_13 -> V_4 = V_4 ;
V_13 -> V_40 = V_40 ;
return V_13 ;
}
static void * F_15 ( struct V_1 * V_2 , const char * V_39 )
{
return F_14 ( V_2 , V_39 , 0 ) ;
}
static struct V_41 * F_16 (
struct V_1 * V_2 ,
struct V_42 * V_43 ,
void * V_44 ,
int V_40 )
{
struct V_41 * V_45 ;
struct V_46 V_47 ;
struct V_13 * V_13 = V_44 ;
struct V_4 * V_4 = V_2 -> V_8 ;
int V_48 = 0 , V_49 ;
char V_50 [ 16 ] , V_51 [ 4 ] ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_49 = F_10 ( V_13 ) ;
if ( V_49 < 0 )
goto V_52;
snprintf ( V_50 , 16 , L_20 , ( V_13 -> V_40 ) ? L_21 : L_22 ) ;
snprintf ( V_51 , 4 , L_23 , ( V_13 -> V_40 ) ? V_53 :
V_54 ) ;
V_47 . V_55 . V_56 = V_57 ;
V_47 . V_55 . V_58 = V_12 ;
V_47 . V_55 . V_59 = V_12 ;
V_47 . V_60 = V_61 ;
V_47 . V_62 = V_63 ;
V_45 = F_17 ( V_2 ,
& V_64 , V_43 , V_48 , V_13 ,
& V_47 , V_50 , V_51 ) ;
if ( ! V_45 )
goto V_52;
V_13 -> V_27 = V_4 -> V_65 ++ ;
V_13 -> V_66 = V_45 -> V_62 ;
F_4 ( L_24
L_25 ,
V_4 -> V_7 , ( ! V_13 -> V_40 ) ? L_26 :
L_27 , V_13 -> V_27 , V_13 -> V_34 ,
V_13 -> V_25 ,
( unsigned long ) ( V_13 -> V_34 * V_28 ) ) ;
return V_45 ;
V_52:
F_7 ( V_13 ) ;
return F_18 ( V_49 ) ;
}
static struct V_41 * F_19 (
struct V_1 * V_2 ,
struct V_42 * V_43 ,
void * V_44 )
{
return F_16 ( V_2 , V_43 , V_44 , 0 ) ;
}
static void F_20 ( void * V_44 )
{
struct V_13 * V_13 = V_44 ;
F_7 ( V_13 ) ;
F_6 ( V_13 ) ;
}
static inline struct V_67 * F_21 ( struct V_68 * V_69 )
{
return F_22 ( V_69 , struct V_67 , V_70 ) ;
}
static struct V_68 *
F_23 ( unsigned char * V_71 )
{
struct V_67 * V_72 ;
V_72 = F_2 ( sizeof( struct V_67 ) , V_5 ) ;
if ( ! V_72 ) {
F_3 ( L_28 ) ;
return NULL ;
}
return & V_72 -> V_70 ;
}
static struct V_18 * F_24 ( struct V_13 * V_13 , T_1 V_20 )
{
T_1 V_14 ;
struct V_18 * V_19 ;
for ( V_14 = 0 ; V_14 < V_13 -> V_25 ; V_14 ++ ) {
V_19 = & V_13 -> V_24 [ V_14 ] ;
if ( ( V_19 -> V_36 <= V_20 ) &&
( V_19 -> V_37 >= V_20 ) )
return V_19 ;
}
F_3 ( L_29 ,
V_20 ) ;
return NULL ;
}
static int F_25 ( struct V_67 * V_73 , T_1 V_74 )
{
struct V_68 * V_69 = & V_73 -> V_70 ;
struct V_13 * V_45 = V_73 -> V_70 . V_75 -> V_43 -> V_76 ;
struct V_18 * V_77 ;
struct V_22 * V_78 ;
struct V_79 V_80 ;
T_1 V_81 = V_73 -> V_81 ;
T_1 V_82 ;
V_77 = F_24 ( V_45 , V_73 -> V_83 ) ;
if ( ! V_77 )
return - V_35 ;
V_78 = & V_77 -> V_19 [ V_73 -> V_83 - V_77 -> V_36 ] ;
F_4 ( L_30 ,
V_45 -> V_27 , V_74 ? L_31 : L_32 ,
V_69 -> V_84 , V_73 -> V_85 , V_73 -> V_83 ,
V_81 ) ;
V_82 = V_28 - V_81 ;
F_26 ( & V_80 , V_69 -> V_86 , V_69 -> V_87 ,
V_74 ? V_88 : V_89 ) ;
while ( V_73 -> V_85 ) {
T_1 V_90 ;
void * V_91 ;
F_27 ( & V_80 ) ;
V_90 = F_28 ( ( T_1 ) V_80 . V_38 , V_82 ) ;
V_80 . V_92 = V_90 ;
V_91 = F_29 ( V_78 ) + V_81 ;
if ( V_74 )
memcpy ( V_80 . V_93 , V_91 , V_90 ) ;
else
memcpy ( V_91 , V_80 . V_93 , V_90 ) ;
V_73 -> V_85 -= V_90 ;
if ( ! V_73 -> V_85 )
continue;
V_82 -= V_90 ;
if ( V_82 ) {
V_81 += V_90 ;
continue;
}
V_73 -> V_83 ++ ;
V_81 = 0 ;
V_82 = V_28 ;
if ( V_73 -> V_83 <= V_77 -> V_37 ) {
V_78 ++ ;
continue;
}
V_77 = F_24 ( V_45 , V_73 -> V_83 ) ;
if ( ! V_77 ) {
F_30 ( & V_80 ) ;
return - V_35 ;
}
V_78 = V_77 -> V_19 ;
}
F_30 ( & V_80 ) ;
return 0 ;
}
static int F_31 ( struct V_68 * V_69 )
{
struct V_41 * V_45 = V_69 -> V_75 -> V_43 ;
struct V_67 * V_73 = F_21 ( V_69 ) ;
T_2 V_94 ;
int V_49 ;
V_94 = V_69 -> V_84 * V_45 -> V_95 -> V_96 . V_97 ;
V_73 -> V_81 = F_32 ( V_94 , V_28 ) ;
V_73 -> V_83 = V_94 ;
V_73 -> V_85 = V_69 -> V_98 ;
V_49 = F_25 ( V_73 , V_69 -> V_99 == V_100 ) ;
if ( V_49 != 0 )
return V_49 ;
V_69 -> V_101 = V_102 ;
F_33 ( V_69 , 1 ) ;
return 0 ;
}
static void F_34 ( struct V_68 * V_69 )
{
F_6 ( F_21 ( V_69 ) ) ;
}
static T_3 F_35 (
struct V_1 * V_2 ,
struct V_42 * V_43 ,
const char * V_20 ,
T_3 V_103 )
{
struct V_13 * V_13 = V_43 -> V_104 ;
char * V_105 , * V_106 , * V_107 ;
T_4 args [ V_108 ] ;
int V_49 = 0 , V_109 , V_110 ;
V_107 = F_36 ( V_20 , V_5 ) ;
if ( ! V_107 )
return - V_6 ;
V_105 = V_107 ;
while ( ( V_106 = F_37 ( & V_107 , L_33 ) ) != NULL ) {
if ( ! * V_106 )
continue;
V_110 = F_38 ( V_106 , V_111 , args ) ;
switch ( V_110 ) {
case V_112 :
F_39 ( args , & V_109 ) ;
V_13 -> V_34 = V_109 ;
F_4 ( L_34
L_35 , V_13 -> V_34 ) ;
V_13 -> V_113 |= V_114 ;
break;
default:
break;
}
}
F_6 ( V_105 ) ;
return ( ! V_49 ) ? V_103 : V_49 ;
}
static T_3 F_40 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_13 * V_13 = V_43 -> V_104 ;
if ( ! ( V_13 -> V_113 & V_114 ) ) {
F_4 ( L_36 ) ;
return - V_35 ;
}
return 0 ;
}
static T_3 F_41 (
struct V_1 * V_2 ,
struct V_42 * V_43 ,
char * V_115 )
{
struct V_13 * V_13 = V_43 -> V_104 ;
T_3 V_116 = sprintf ( V_115 , L_37 ,
V_13 -> V_27 , ( V_13 -> V_40 ) ?
L_38 : L_39 ) ;
V_116 += sprintf ( V_115 + V_116 , L_40
L_41 , V_13 -> V_34 ,
V_28 , V_13 -> V_25 ) ;
return V_116 ;
}
static T_1 F_42 ( struct V_41 * V_45 )
{
return V_117 ;
}
static T_1 F_43 ( struct V_41 * V_45 )
{
return V_118 ;
}
static T_5 F_44 ( struct V_41 * V_45 )
{
struct V_13 * V_13 = V_45 -> V_76 ;
unsigned long long V_119 = ( ( V_13 -> V_34 * V_28 ) /
V_45 -> V_95 -> V_96 . V_97 ) - 1 ;
return V_119 ;
}
int T_6 F_45 ( void )
{
int V_49 ;
V_49 = F_46 ( & V_64 ) ;
if ( V_49 < 0 ) {
return V_49 ;
}
return 0 ;
}
void F_47 ( void )
{
F_48 ( & V_64 ) ;
}
