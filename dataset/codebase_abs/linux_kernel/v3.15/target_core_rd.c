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
V_25 = ( V_30 > V_33 ) ?
V_33 : V_30 ;
V_21 = F_4 ( V_25 * sizeof( struct V_20 ) ,
V_8 ) ;
if ( ! V_21 ) {
F_5 ( L_8
L_9 ) ;
return - V_9 ;
}
F_14 ( V_21 , V_25 ) ;
V_16 [ V_22 ] . V_16 = V_21 ;
V_16 [ V_22 ] . V_26 = V_25 ;
V_16 [ V_22 ] . V_36 = V_32 ;
V_16 [ V_22 ++ ] . V_37 = ( V_32 + V_25 )
- 1 ;
for ( V_23 = 0 ; V_23 < V_25 ; V_23 ++ ) {
V_19 = F_15 ( V_8 , 0 ) ;
if ( ! V_19 ) {
F_5 ( L_10
L_11 ) ;
return - V_9 ;
}
F_16 ( & V_21 [ V_23 ] , V_19 ) ;
V_21 [ V_23 ] . V_38 = V_29 ;
V_35 = F_17 ( V_19 ) ;
memset ( V_35 , V_31 , V_29 ) ;
F_18 ( V_19 ) ;
}
V_32 += V_25 ;
V_30 -= V_25 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
struct V_15 * V_16 ;
T_1 V_39 , V_30 ;
T_1 V_33 = ( V_34 /
sizeof( struct V_20 ) ) ;
int V_40 ;
if ( V_1 -> V_41 <= 0 ) {
F_5 ( L_12 ,
V_1 -> V_41 ) ;
return - V_42 ;
}
if ( V_1 -> V_43 & V_44 )
return 0 ;
V_30 = V_1 -> V_41 ;
V_39 = ( V_30 / V_33 ) + 1 ;
V_16 = F_4 ( V_39 * sizeof( struct V_15 ) , V_8 ) ;
if ( ! V_16 ) {
F_5 ( L_13
L_14 ) ;
return - V_9 ;
}
V_1 -> V_27 = V_16 ;
V_1 -> V_17 = V_39 ;
V_40 = F_13 ( V_1 , V_16 , V_30 , 0x00 ) ;
if ( V_40 )
return V_40 ;
F_6 ( L_15
L_16 , V_1 -> V_7 -> V_10 ,
V_1 -> V_28 , V_1 -> V_41 ,
V_1 -> V_17 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_1 )
{
T_1 V_24 ;
if ( ! V_1 -> V_45 || ! V_1 -> V_46 )
return;
V_24 = F_9 ( V_1 , V_1 -> V_45 ,
V_1 -> V_46 ) ;
F_6 ( L_17
L_7 ,
V_1 -> V_7 -> V_10 , V_1 -> V_28 , V_24 ,
V_1 -> V_17 , ( unsigned long ) V_24 * V_29 ) ;
V_1 -> V_45 = NULL ;
V_1 -> V_46 = 0 ;
}
static int F_21 ( struct V_1 * V_1 , int V_47 , int V_48 )
{
struct V_15 * V_16 ;
T_1 V_30 , V_39 ;
T_1 V_33 = ( V_34 /
sizeof( struct V_20 ) ) ;
int V_40 ;
if ( V_1 -> V_43 & V_44 )
return 0 ;
V_30 = ( V_1 -> V_41 * V_47 / V_48 ) + 1 ;
V_39 = ( V_30 / V_33 ) + 1 ;
V_16 = F_4 ( V_39 * sizeof( struct V_15 ) , V_8 ) ;
if ( ! V_16 ) {
F_5 ( L_18
L_14 ) ;
return - V_9 ;
}
V_1 -> V_45 = V_16 ;
V_1 -> V_46 = V_39 ;
V_40 = F_13 ( V_1 , V_16 , V_30 , 0xff ) ;
if ( V_40 )
return V_40 ;
F_6 ( L_19
L_16 , V_1 -> V_7 -> V_10 ,
V_1 -> V_28 , V_30 , V_1 -> V_46 ) ;
return 0 ;
}
static struct V_2 * F_22 ( struct V_4 * V_5 , const char * V_49 )
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
static int F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_3 -> V_4 -> V_11 ;
int V_50 ;
if ( ! ( V_1 -> V_43 & V_51 ) ) {
F_6 ( L_21 ) ;
return - V_42 ;
}
V_50 = F_19 ( V_1 ) ;
if ( V_50 < 0 )
goto V_52;
V_3 -> V_53 . V_54 = V_55 ;
V_3 -> V_53 . V_56 = V_57 ;
V_3 -> V_53 . V_58 = V_59 ;
V_1 -> V_28 = V_7 -> V_60 ++ ;
F_6 ( L_22
L_23 ,
V_7 -> V_10 , V_1 -> V_28 , V_1 -> V_41 ,
V_1 -> V_17 ,
( unsigned long ) ( V_1 -> V_41 * V_29 ) ) ;
return 0 ;
V_52:
F_12 ( V_1 ) ;
return V_50 ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_12 ( V_1 ) ;
F_8 ( V_1 ) ;
}
static struct V_15 * F_25 ( struct V_1 * V_1 , T_1 V_18 )
{
struct V_15 * V_16 ;
T_1 V_22 , V_25 = ( V_34 /
sizeof( struct V_20 ) ) ;
V_22 = V_18 / V_25 ;
if ( V_22 < V_1 -> V_17 ) {
V_16 = & V_1 -> V_27 [ V_22 ] ;
if ( ( V_16 -> V_36 <= V_18 ) &&
( V_16 -> V_37 >= V_18 ) )
return V_16 ;
}
F_5 ( L_24 ,
V_18 ) ;
return NULL ;
}
static struct V_15 * F_26 ( struct V_1 * V_1 , T_1 V_18 )
{
struct V_15 * V_16 ;
T_1 V_22 , V_25 = ( V_34 /
sizeof( struct V_20 ) ) ;
V_22 = V_18 / V_25 ;
if ( V_22 < V_1 -> V_46 ) {
V_16 = & V_1 -> V_45 [ V_22 ] ;
if ( ( V_16 -> V_36 <= V_18 ) &&
( V_16 -> V_37 >= V_18 ) )
return V_16 ;
}
F_5 ( L_25 ,
V_18 ) ;
return NULL ;
}
static T_2
F_27 ( struct V_61 * V_62 , struct V_20 * V_63 , T_1 V_64 ,
enum V_65 V_66 )
{
struct V_2 * V_67 = V_62 -> V_67 ;
struct V_1 * V_3 = F_1 ( V_67 ) ;
struct V_15 * V_68 ;
struct V_20 * V_69 ;
struct V_70 V_71 ;
T_1 V_72 ;
T_1 V_73 ;
T_1 V_74 ;
T_1 V_75 ;
T_3 V_76 ;
T_2 V_40 ;
if ( V_3 -> V_43 & V_44 ) {
F_28 ( V_62 , V_77 ) ;
return 0 ;
}
V_76 = V_62 -> V_78 * V_67 -> V_53 . V_48 ;
V_72 = F_29 ( V_76 , V_29 ) ;
V_74 = V_76 ;
V_73 = V_62 -> V_79 ;
V_68 = F_25 ( V_3 , V_74 ) ;
if ( ! V_68 )
return V_80 ;
V_69 = & V_68 -> V_16 [ V_74 - V_68 -> V_36 ] ;
F_6 ( L_26 ,
V_3 -> V_28 ,
V_66 == V_81 ? L_27 : L_28 ,
V_62 -> V_78 , V_73 , V_74 , V_72 ) ;
if ( V_62 -> V_82 && V_66 == V_83 ) {
struct V_15 * V_84 ;
struct V_20 * V_85 ;
T_1 V_86 = V_62 -> V_79 / V_67 -> V_53 . V_48 ;
T_1 V_87 , V_88 ;
V_76 = V_62 -> V_78 * V_67 -> V_47 ;
V_87 = F_29 ( V_76 , V_29 ) ;
V_88 = V_76 ;
V_84 = F_26 ( V_3 , V_88 ) ;
if ( ! V_84 )
return V_80 ;
V_85 = & V_84 -> V_16 [ V_88 - V_84 -> V_36 ] ;
V_40 = F_30 ( V_62 , V_62 -> V_78 , V_86 , 0 ,
V_85 , V_87 ) ;
if ( V_40 )
return V_40 ;
}
V_75 = V_29 - V_72 ;
F_31 ( & V_71 , V_63 , V_64 ,
V_66 == V_81 ?
V_89 : V_90 ) ;
while ( V_73 ) {
T_1 V_91 ;
void * V_92 ;
F_32 ( & V_71 ) ;
if ( ! ( T_1 ) V_71 . V_38 ) {
F_6 ( L_29 ,
V_3 -> V_28 , V_71 . V_93 , V_71 . V_38 ) ;
F_33 ( & V_71 ) ;
return V_94 ;
}
V_91 = F_34 ( ( T_1 ) V_71 . V_38 , V_75 ) ;
if ( V_91 > V_73 ) {
F_6 ( L_30
L_31 , V_3 -> V_28 ,
V_74 , V_72 , V_73 ) ;
V_91 = V_73 ;
}
V_71 . V_95 = V_91 ;
V_92 = F_35 ( V_69 ) + V_72 ;
if ( V_66 == V_81 )
memcpy ( V_71 . V_93 , V_92 , V_91 ) ;
else
memcpy ( V_92 , V_71 . V_93 , V_91 ) ;
V_73 -= V_91 ;
if ( ! V_73 )
continue;
V_75 -= V_91 ;
if ( V_75 ) {
V_72 += V_91 ;
continue;
}
V_74 ++ ;
V_72 = 0 ;
V_75 = V_29 ;
if ( V_74 <= V_68 -> V_37 ) {
V_69 ++ ;
continue;
}
V_68 = F_25 ( V_3 , V_74 ) ;
if ( ! V_68 ) {
F_33 ( & V_71 ) ;
return V_80 ;
}
V_69 = V_68 -> V_16 ;
}
F_33 ( & V_71 ) ;
if ( V_62 -> V_82 && V_66 == V_81 ) {
struct V_15 * V_84 ;
struct V_20 * V_85 ;
T_1 V_86 = V_62 -> V_79 / V_67 -> V_53 . V_48 ;
T_1 V_87 , V_88 ;
V_76 = V_62 -> V_78 * V_67 -> V_47 ;
V_87 = F_29 ( V_76 , V_29 ) ;
V_88 = V_76 ;
V_84 = F_26 ( V_3 , V_88 ) ;
if ( ! V_84 )
return V_80 ;
V_85 = & V_84 -> V_16 [ V_88 - V_84 -> V_36 ] ;
V_40 = F_36 ( V_62 , V_62 -> V_78 , V_86 , 0 ,
V_85 , V_87 ) ;
if ( V_40 )
return V_40 ;
}
F_28 ( V_62 , V_77 ) ;
return 0 ;
}
static T_4 F_37 ( struct V_2 * V_3 ,
const char * V_18 , T_4 V_96 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
char * V_97 , * V_98 , * V_99 ;
T_5 args [ V_100 ] ;
int V_50 = 0 , V_101 , V_102 ;
V_99 = F_38 ( V_18 , V_8 ) ;
if ( ! V_99 )
return - V_9 ;
V_97 = V_99 ;
while ( ( V_98 = F_39 ( & V_99 , L_32 ) ) != NULL ) {
if ( ! * V_98 )
continue;
V_102 = F_40 ( V_98 , V_103 , args ) ;
switch ( V_102 ) {
case V_104 :
F_41 ( args , & V_101 ) ;
V_1 -> V_41 = V_101 ;
F_6 ( L_33
L_34 , V_1 -> V_41 ) ;
V_1 -> V_43 |= V_51 ;
break;
case V_105 :
F_41 ( args , & V_101 ) ;
if ( V_101 != 1 )
break;
F_6 ( L_35 , V_101 ) ;
V_1 -> V_43 |= V_44 ;
break;
default:
break;
}
}
F_8 ( V_97 ) ;
return ( ! V_50 ) ? V_96 : V_50 ;
}
static T_4 F_42 ( struct V_2 * V_3 , char * V_106 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_4 V_107 = sprintf ( V_106 , L_36 ,
V_1 -> V_28 ) ;
V_107 += sprintf ( V_106 + V_107 , L_37
L_38 , V_1 -> V_41 ,
V_29 , V_1 -> V_17 ,
! ! ( V_1 -> V_43 & V_44 ) ) ;
return V_107 ;
}
static T_6 F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long long V_108 = ( ( V_1 -> V_41 * V_29 ) /
V_3 -> V_53 . V_48 ) - 1 ;
return V_108 ;
}
static int F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_3 -> V_53 . V_109 )
return 0 ;
return F_21 ( V_1 , V_3 -> V_47 ,
V_3 -> V_53 . V_48 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_20 ( V_1 ) ;
}
static T_2
F_46 ( struct V_61 * V_62 )
{
return F_47 ( V_62 , & V_110 ) ;
}
int T_7 F_48 ( void )
{
int V_50 ;
V_50 = F_49 ( & V_111 ) ;
if ( V_50 < 0 ) {
return V_50 ;
}
return 0 ;
}
void F_50 ( void )
{
F_51 ( & V_111 ) ;
}
