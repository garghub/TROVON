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
static int F_25 ( struct V_67 * V_73 )
{
struct V_68 * V_69 = & V_73 -> V_70 ;
struct V_13 * V_45 = V_73 -> V_70 . V_43 -> V_74 ;
struct V_18 * V_75 ;
struct V_22 * V_76 , * V_77 ;
void * V_78 , * V_79 ;
T_1 V_14 = 0 , V_15 = 0 , V_80 = 0 , V_81 = 0 ;
T_1 V_38 , V_82 = 0 , V_83 ;
T_1 V_84 = V_73 -> V_84 ;
V_75 = F_24 ( V_45 , V_73 -> V_85 ) ;
if ( ! V_75 )
return - V_35 ;
V_83 = ( V_75 -> V_37 - V_73 -> V_85 ) ;
V_76 = V_69 -> V_86 ;
V_77 = & V_75 -> V_19 [ V_73 -> V_85 - V_75 -> V_36 ] ;
F_4 ( L_30
L_31 , V_45 -> V_27 , V_69 -> V_87 , V_73 -> V_88 ,
V_73 -> V_85 , V_73 -> V_84 ) ;
V_81 = V_84 ;
while ( V_73 -> V_88 ) {
if ( ( V_76 [ V_14 ] . V_38 - V_80 ) <
( V_77 [ V_15 ] . V_38 - V_81 ) ) {
V_38 = ( V_76 [ V_14 ] . V_38 - V_80 ) ;
F_4 ( L_32
L_33 , V_14 ,
& V_76 [ V_14 ] , V_76 [ V_14 ] . V_38 , V_76 [ V_14 ] . V_89 , V_15 ,
V_77 [ V_15 ] . V_38 ) ;
F_4 ( L_34
L_35 , V_38 , V_80 ,
V_81 ) ;
if ( V_38 > V_73 -> V_88 )
V_38 = V_73 -> V_88 ;
V_78 = F_26 ( & V_76 [ V_14 ++ ] ) + V_80 ;
F_27 ( ! V_78 ) ;
V_79 = F_26 ( & V_77 [ V_15 ] ) + V_81 ;
F_27 ( ! V_79 ) ;
V_80 = 0 ;
V_81 = V_38 ;
V_82 = 0 ;
} else {
V_38 = ( V_77 [ V_15 ] . V_38 - V_81 ) ;
F_4 ( L_36
L_33 , V_14 ,
& V_76 [ V_14 ] , V_76 [ V_14 ] . V_38 , V_76 [ V_14 ] . V_89 ,
V_15 , V_77 [ V_15 ] . V_38 ) ;
F_4 ( L_37
L_35 , V_38 , V_80 ,
V_81 ) ;
if ( V_38 > V_73 -> V_88 )
V_38 = V_73 -> V_88 ;
V_78 = F_26 ( & V_76 [ V_14 ] ) + V_80 ;
F_27 ( ! V_78 ) ;
if ( V_76 [ V_14 ] . V_38 == V_38 ) {
V_14 ++ ;
V_80 = 0 ;
} else
V_80 = V_38 ;
V_79 = F_26 ( & V_77 [ V_15 ++ ] ) + V_81 ;
F_27 ( ! V_79 ) ;
V_81 = 0 ;
V_82 = 1 ;
}
memcpy ( V_78 , V_79 , V_38 ) ;
F_4 ( L_38
L_39 , V_73 -> V_85 ,
( V_73 -> V_88 - V_38 ) , V_38 , V_14 , V_15 ) ;
V_73 -> V_88 -= V_38 ;
if ( ! V_73 -> V_88 )
return 0 ;
if ( ! V_82 )
continue;
if ( ++ V_73 -> V_85 <= V_75 -> V_37 ) {
F_4 ( L_40 ,
V_73 -> V_85 ) ;
continue;
}
F_4 ( L_41 ,
V_73 -> V_85 ) ;
V_75 = F_24 ( V_45 , V_73 -> V_85 ) ;
if ( ! V_75 )
return - V_35 ;
V_77 = & V_75 -> V_19 [ V_15 = 0 ] ;
}
return 0 ;
}
static int F_28 ( struct V_67 * V_73 )
{
struct V_68 * V_69 = & V_73 -> V_70 ;
struct V_13 * V_45 = V_73 -> V_70 . V_43 -> V_74 ;
struct V_18 * V_75 ;
struct V_22 * V_76 , * V_77 ;
void * V_78 , * V_79 ;
T_1 V_14 = 0 , V_15 = 0 , V_80 = 0 , V_81 = 0 ;
T_1 V_38 , V_82 = 0 , V_83 ;
T_1 V_84 = V_73 -> V_84 ;
V_75 = F_24 ( V_45 , V_73 -> V_85 ) ;
if ( ! V_75 )
return - V_35 ;
V_83 = ( V_75 -> V_37 - V_73 -> V_85 ) ;
V_76 = & V_75 -> V_19 [ V_73 -> V_85 - V_75 -> V_36 ] ;
V_77 = V_69 -> V_86 ;
F_4 ( L_42
L_43 , V_45 -> V_27 , V_69 -> V_87 , V_73 -> V_88 ,
V_73 -> V_85 , V_73 -> V_84 ) ;
V_80 = V_84 ;
while ( V_73 -> V_88 ) {
if ( ( V_77 [ V_14 ] . V_38 - V_81 ) <
( V_76 [ V_15 ] . V_38 - V_80 ) ) {
V_38 = ( V_77 [ V_14 ] . V_38 - V_81 ) ;
F_4 ( L_44
L_45 , V_14 ,
& V_77 [ V_14 ] , V_77 [ V_14 ] . V_38 , V_77 [ V_14 ] . V_89 ,
V_15 , V_76 [ V_15 ] . V_38 ) ;
F_4 ( L_46
L_47 , V_38 , V_81 ,
V_80 ) ;
if ( V_38 > V_73 -> V_88 )
V_38 = V_73 -> V_88 ;
V_79 = F_26 ( & V_77 [ V_14 ++ ] ) + V_81 ;
F_27 ( ! V_79 ) ;
V_78 = F_26 ( & V_76 [ V_15 ] ) + V_80 ;
F_27 ( ! V_78 ) ;
V_81 = 0 ;
V_80 = V_38 ;
V_82 = 0 ;
} else {
V_38 = ( V_76 [ V_15 ] . V_38 - V_80 ) ;
F_4 ( L_48
L_45 , V_14 ,
& V_77 [ V_14 ] , V_77 [ V_14 ] . V_38 , V_77 [ V_14 ] . V_89 ,
V_15 , V_76 [ V_15 ] . V_38 ) ;
F_4 ( L_49
L_47 , V_38 , V_81 ,
V_80 ) ;
if ( V_38 > V_73 -> V_88 )
V_38 = V_73 -> V_88 ;
V_79 = F_26 ( & V_77 [ V_14 ] ) + V_81 ;
F_27 ( ! V_79 ) ;
if ( V_77 [ V_14 ] . V_38 == V_38 ) {
V_14 ++ ;
V_81 = 0 ;
} else
V_81 = V_38 ;
V_78 = F_26 ( & V_76 [ V_15 ++ ] ) + V_80 ;
F_27 ( ! V_78 ) ;
V_80 = 0 ;
V_82 = 1 ;
}
memcpy ( V_78 , V_79 , V_38 ) ;
F_4 ( L_38
L_39 , V_73 -> V_85 ,
( V_73 -> V_88 - V_38 ) , V_38 , V_14 , V_15 ) ;
V_73 -> V_88 -= V_38 ;
if ( ! V_73 -> V_88 )
return 0 ;
if ( ! V_82 )
continue;
if ( ++ V_73 -> V_85 <= V_75 -> V_37 ) {
F_4 ( L_40 ,
V_73 -> V_85 ) ;
continue;
}
F_4 ( L_41 ,
V_73 -> V_85 ) ;
V_75 = F_24 ( V_45 , V_73 -> V_85 ) ;
if ( ! V_75 )
return - V_35 ;
V_76 = & V_75 -> V_19 [ V_15 = 0 ] ;
}
return 0 ;
}
static int F_29 ( struct V_68 * V_69 )
{
struct V_41 * V_45 = V_69 -> V_43 ;
struct V_67 * V_73 = F_21 ( V_69 ) ;
unsigned long long V_90 ;
int V_49 ;
V_73 -> V_85 = ( V_69 -> V_87 * V_45 -> V_91 -> V_92 . V_93 ) / V_28 ;
V_90 = V_69 -> V_87 ;
V_73 -> V_84 = ( F_30 ( V_90 ,
( V_28 / V_45 -> V_91 -> V_92 . V_93 ) ) ) *
V_45 -> V_91 -> V_92 . V_93 ;
V_73 -> V_88 = V_69 -> V_94 ;
if ( V_69 -> V_95 == V_96 )
V_49 = F_25 ( V_73 ) ;
else
V_49 = F_28 ( V_73 ) ;
if ( V_49 != 0 )
return V_49 ;
V_69 -> V_97 = V_98 ;
F_31 ( V_69 , 1 ) ;
return V_99 ;
}
static void F_32 ( struct V_68 * V_69 )
{
F_6 ( F_21 ( V_69 ) ) ;
}
static T_2 F_33 (
struct V_1 * V_2 ,
struct V_42 * V_43 ,
const char * V_20 ,
T_2 V_100 )
{
struct V_13 * V_13 = V_43 -> V_101 ;
char * V_102 , * V_103 , * V_104 ;
T_3 args [ V_105 ] ;
int V_49 = 0 , V_106 , V_107 ;
V_104 = F_34 ( V_20 , V_5 ) ;
if ( ! V_104 )
return - V_6 ;
V_102 = V_104 ;
while ( ( V_103 = F_35 ( & V_104 , L_50 ) ) != NULL ) {
if ( ! * V_103 )
continue;
V_107 = F_36 ( V_103 , V_108 , args ) ;
switch ( V_107 ) {
case V_109 :
F_37 ( args , & V_106 ) ;
V_13 -> V_34 = V_106 ;
F_4 ( L_51
L_52 , V_13 -> V_34 ) ;
V_13 -> V_110 |= V_111 ;
break;
default:
break;
}
}
F_6 ( V_102 ) ;
return ( ! V_49 ) ? V_100 : V_49 ;
}
static T_2 F_38 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_13 * V_13 = V_43 -> V_101 ;
if ( ! ( V_13 -> V_110 & V_111 ) ) {
F_4 ( L_53 ) ;
return - V_35 ;
}
return 0 ;
}
static T_2 F_39 (
struct V_1 * V_2 ,
struct V_42 * V_43 ,
char * V_112 )
{
struct V_13 * V_13 = V_43 -> V_101 ;
T_2 V_113 = sprintf ( V_112 , L_54 ,
V_13 -> V_27 , ( V_13 -> V_40 ) ?
L_55 : L_56 ) ;
V_113 += sprintf ( V_112 + V_113 , L_57
L_58 , V_13 -> V_34 ,
V_28 , V_13 -> V_25 ) ;
return V_113 ;
}
static unsigned char * F_40 ( struct V_68 * V_69 )
{
struct V_67 * V_73 = F_21 ( V_69 ) ;
return V_73 -> V_114 ;
}
static T_1 F_41 ( struct V_41 * V_45 )
{
return V_115 ;
}
static T_1 F_42 ( struct V_41 * V_45 )
{
return V_116 ;
}
static T_4 F_43 ( struct V_41 * V_45 )
{
struct V_13 * V_13 = V_45 -> V_74 ;
unsigned long long V_117 = ( ( V_13 -> V_34 * V_28 ) /
V_45 -> V_91 -> V_92 . V_93 ) - 1 ;
return V_117 ;
}
int T_5 F_44 ( void )
{
int V_49 ;
V_49 = F_45 ( & V_64 ) ;
if ( V_49 < 0 ) {
return V_49 ;
}
return 0 ;
}
void F_46 ( void )
{
F_47 ( & V_64 ) ;
}
