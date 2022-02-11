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
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_8 ;
F_4 ( L_4
L_5 , V_2 -> V_9 , V_4 -> V_7 ) ;
F_6 ( V_4 ) ;
V_2 -> V_8 = NULL ;
}
static void F_7 ( struct V_12 * V_12 )
{
T_1 V_13 , V_14 , V_15 = 0 , V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
if ( ! V_12 -> V_23 || ! V_12 -> V_24 )
return;
V_18 = V_12 -> V_23 ;
for ( V_13 = 0 ; V_13 < V_12 -> V_24 ; V_13 ++ ) {
V_22 = V_18 [ V_13 ] . V_18 ;
V_16 = V_18 [ V_13 ] . V_25 ;
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
V_20 = F_8 ( & V_22 [ V_14 ] ) ;
if ( V_20 ) {
F_9 ( V_20 ) ;
V_15 ++ ;
}
}
F_6 ( V_22 ) ;
}
F_4 ( L_6
L_7 ,
V_12 -> V_4 -> V_7 , V_12 -> V_26 , V_15 ,
V_12 -> V_24 , ( unsigned long ) V_15 * V_27 ) ;
F_6 ( V_18 ) ;
V_12 -> V_23 = NULL ;
V_12 -> V_24 = 0 ;
}
static int F_10 ( struct V_12 * V_12 )
{
T_1 V_13 = 0 , V_14 , V_28 = 0 , V_16 , V_29 , V_30 ;
T_1 V_31 = ( V_32 /
sizeof( struct V_21 ) ) ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
if ( V_12 -> V_33 <= 0 ) {
F_3 ( L_8 ,
V_12 -> V_33 ) ;
return - V_34 ;
}
V_30 = V_12 -> V_33 ;
V_29 = ( V_30 / V_31 ) + 1 ;
V_18 = F_2 ( V_29 * sizeof( struct V_17 ) , V_5 ) ;
if ( ! V_18 ) {
F_3 ( L_9
L_10 ) ;
return - V_6 ;
}
V_12 -> V_23 = V_18 ;
V_12 -> V_24 = V_29 ;
while ( V_30 ) {
V_16 = ( V_30 > V_31 ) ?
V_31 : V_30 ;
V_22 = F_2 ( V_16 * sizeof( struct V_21 ) ,
V_5 ) ;
if ( ! V_22 ) {
F_3 ( L_11
L_12 ) ;
return - V_6 ;
}
F_11 ( V_22 , V_16 ) ;
V_18 [ V_13 ] . V_18 = V_22 ;
V_18 [ V_13 ] . V_25 = V_16 ;
V_18 [ V_13 ] . V_35 = V_28 ;
V_18 [ V_13 ++ ] . V_36 = ( V_28 + V_16 )
- 1 ;
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
V_20 = F_12 ( V_5 , 0 ) ;
if ( ! V_20 ) {
F_3 ( L_13
L_14 ) ;
return - V_6 ;
}
F_13 ( & V_22 [ V_14 ] , V_20 ) ;
V_22 [ V_14 ] . V_37 = V_27 ;
}
V_28 += V_16 ;
V_30 -= V_16 ;
}
F_4 ( L_15
L_16 , V_12 -> V_4 -> V_7 ,
V_12 -> V_26 , V_12 -> V_33 ,
V_12 -> V_24 ) ;
return 0 ;
}
static void * F_14 ( struct V_1 * V_2 , const char * V_38 )
{
struct V_12 * V_12 ;
struct V_4 * V_4 = V_2 -> V_8 ;
V_12 = F_2 ( sizeof( struct V_12 ) , V_5 ) ;
if ( ! V_12 ) {
F_3 ( L_17 ) ;
return NULL ;
}
V_12 -> V_4 = V_4 ;
return V_12 ;
}
static struct V_39 * F_15 ( struct V_1 * V_2 ,
struct V_40 * V_41 , void * V_42 )
{
struct V_39 * V_43 ;
struct V_44 V_45 ;
struct V_12 * V_12 = V_42 ;
struct V_4 * V_4 = V_2 -> V_8 ;
int V_46 = 0 , V_47 ;
char V_48 [ 16 ] , V_49 [ 4 ] ;
memset ( & V_45 , 0 , sizeof( struct V_44 ) ) ;
V_47 = F_10 ( V_12 ) ;
if ( V_47 < 0 )
goto V_50;
snprintf ( V_48 , 16 , L_18 ) ;
snprintf ( V_49 , 4 , L_19 , V_51 ) ;
V_45 . V_52 . V_53 = V_54 ;
V_45 . V_52 . V_55 = V_56 ;
V_45 . V_52 . V_57 = V_56 ;
V_45 . V_58 = V_59 ;
V_45 . V_60 = V_61 ;
V_43 = F_16 ( V_2 ,
& V_62 , V_41 , V_46 , V_12 ,
& V_45 , V_48 , V_49 ) ;
if ( ! V_43 )
goto V_50;
V_12 -> V_26 = V_4 -> V_63 ++ ;
F_4 ( L_20
L_21 ,
V_4 -> V_7 , V_12 -> V_26 , V_12 -> V_33 ,
V_12 -> V_24 ,
( unsigned long ) ( V_12 -> V_33 * V_27 ) ) ;
return V_43 ;
V_50:
F_7 ( V_12 ) ;
return F_17 ( V_47 ) ;
}
static void F_18 ( void * V_42 )
{
struct V_12 * V_12 = V_42 ;
F_7 ( V_12 ) ;
F_6 ( V_12 ) ;
}
static struct V_17 * F_19 ( struct V_12 * V_12 , T_1 V_19 )
{
T_1 V_13 ;
struct V_17 * V_18 ;
for ( V_13 = 0 ; V_13 < V_12 -> V_24 ; V_13 ++ ) {
V_18 = & V_12 -> V_23 [ V_13 ] ;
if ( ( V_18 -> V_35 <= V_19 ) &&
( V_18 -> V_36 >= V_19 ) )
return V_18 ;
}
F_3 ( L_22 ,
V_19 ) ;
return NULL ;
}
static int F_20 ( struct V_64 * V_65 )
{
struct V_21 * V_66 = V_65 -> V_67 ;
T_1 V_68 = V_65 -> V_69 ;
enum V_70 V_71 = V_65 -> V_71 ;
struct V_39 * V_41 = V_65 -> V_41 ;
struct V_12 * V_43 = V_41 -> V_72 ;
struct V_17 * V_73 ;
struct V_21 * V_74 ;
struct V_75 V_76 ;
T_1 V_77 ;
T_1 V_78 ;
T_1 V_79 ;
T_1 V_80 ;
T_2 V_81 ;
V_81 = V_65 -> V_82 * V_41 -> V_83 -> V_84 . V_85 ;
V_77 = F_21 ( V_81 , V_27 ) ;
V_79 = V_81 ;
V_78 = V_65 -> V_86 ;
V_73 = F_19 ( V_43 , V_79 ) ;
if ( ! V_73 )
return - V_34 ;
V_74 = & V_73 -> V_18 [ V_79 - V_73 -> V_35 ] ;
F_4 ( L_23 ,
V_43 -> V_26 ,
V_71 == V_87 ? L_24 : L_25 ,
V_65 -> V_82 , V_78 , V_79 , V_77 ) ;
V_80 = V_27 - V_77 ;
F_22 ( & V_76 , V_66 , V_68 ,
V_71 == V_87 ?
V_88 : V_89 ) ;
while ( V_78 ) {
T_1 V_90 ;
void * V_91 ;
F_23 ( & V_76 ) ;
V_90 = F_24 ( ( T_1 ) V_76 . V_37 , V_80 ) ;
V_76 . V_92 = V_90 ;
V_91 = F_25 ( V_74 ) + V_77 ;
if ( V_71 == V_87 )
memcpy ( V_76 . V_93 , V_91 , V_90 ) ;
else
memcpy ( V_91 , V_76 . V_93 , V_90 ) ;
V_78 -= V_90 ;
if ( ! V_78 )
continue;
V_80 -= V_90 ;
if ( V_80 ) {
V_77 += V_90 ;
continue;
}
V_79 ++ ;
V_77 = 0 ;
V_80 = V_27 ;
if ( V_79 <= V_73 -> V_36 ) {
V_74 ++ ;
continue;
}
V_73 = F_19 ( V_43 , V_79 ) ;
if ( ! V_73 ) {
F_26 ( & V_76 ) ;
return - V_34 ;
}
V_74 = V_73 -> V_18 ;
}
F_26 ( & V_76 ) ;
F_27 ( V_65 , V_94 ) ;
return 0 ;
}
static T_3 F_28 (
struct V_1 * V_2 ,
struct V_40 * V_41 ,
const char * V_19 ,
T_3 V_95 )
{
struct V_12 * V_12 = V_41 -> V_96 ;
char * V_97 , * V_98 , * V_99 ;
T_4 args [ V_100 ] ;
int V_47 = 0 , V_101 , V_102 ;
V_99 = F_29 ( V_19 , V_5 ) ;
if ( ! V_99 )
return - V_6 ;
V_97 = V_99 ;
while ( ( V_98 = F_30 ( & V_99 , L_26 ) ) != NULL ) {
if ( ! * V_98 )
continue;
V_102 = F_31 ( V_98 , V_103 , args ) ;
switch ( V_102 ) {
case V_104 :
F_32 ( args , & V_101 ) ;
V_12 -> V_33 = V_101 ;
F_4 ( L_27
L_28 , V_12 -> V_33 ) ;
V_12 -> V_105 |= V_106 ;
break;
default:
break;
}
}
F_6 ( V_97 ) ;
return ( ! V_47 ) ? V_95 : V_47 ;
}
static T_3 F_33 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_12 * V_12 = V_41 -> V_96 ;
if ( ! ( V_12 -> V_105 & V_106 ) ) {
F_4 ( L_29 ) ;
return - V_34 ;
}
return 0 ;
}
static T_3 F_34 (
struct V_1 * V_2 ,
struct V_40 * V_41 ,
char * V_107 )
{
struct V_12 * V_12 = V_41 -> V_96 ;
T_3 V_108 = sprintf ( V_107 , L_30 ,
V_12 -> V_26 ) ;
V_108 += sprintf ( V_107 + V_108 , L_31
L_32 , V_12 -> V_33 ,
V_27 , V_12 -> V_24 ) ;
return V_108 ;
}
static T_1 F_35 ( struct V_39 * V_43 )
{
return V_109 ;
}
static T_1 F_36 ( struct V_39 * V_43 )
{
return V_110 ;
}
static T_5 F_37 ( struct V_39 * V_43 )
{
struct V_12 * V_12 = V_43 -> V_72 ;
unsigned long long V_111 = ( ( V_12 -> V_33 * V_27 ) /
V_43 -> V_83 -> V_84 . V_85 ) - 1 ;
return V_111 ;
}
static int F_38 ( struct V_64 * V_65 )
{
return F_39 ( V_65 , & V_112 ) ;
}
int T_6 F_40 ( void )
{
int V_47 ;
V_47 = F_41 ( & V_62 ) ;
if ( V_47 < 0 ) {
return V_47 ;
}
return 0 ;
}
void F_42 ( void )
{
F_43 ( & V_62 ) ;
}
