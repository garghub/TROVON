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
L_3 , V_2 -> V_9 , V_10 ,
V_11 ) ;
F_4 ( L_4
L_5 ,
V_2 -> V_9 , V_4 -> V_7 , V_12 ) ;
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
static void * F_7 ( struct V_1 * V_2 , const char * V_13 )
{
struct V_14 * V_14 ;
struct V_4 * V_4 = V_2 -> V_8 ;
V_14 = F_2 ( sizeof( struct V_14 ) , V_5 ) ;
if ( ! V_14 ) {
F_3 ( L_8 ) ;
return NULL ;
}
V_14 -> V_4 = V_4 ;
F_4 ( L_9 , V_13 ) ;
return V_14 ;
}
static struct V_15 * F_8 (
struct V_1 * V_2 ,
struct V_16 * V_17 ,
void * V_18 )
{
struct V_15 * V_19 ;
struct V_20 V_21 ;
struct V_22 * V_23 ;
struct V_14 * V_14 = V_18 ;
struct V_4 * V_4 = V_2 -> V_8 ;
struct V_24 * V_24 ;
struct V_25 * V_25 = NULL ;
int V_26 = 0 , V_27 , V_28 = - V_29 ;
memset ( & V_21 , 0 , sizeof( struct V_20 ) ) ;
V_27 = V_30 | V_31 | V_32 | V_33 ;
V_24 = F_9 ( V_14 -> V_34 , V_27 , 0600 ) ;
if ( F_10 ( V_24 ) ) {
F_3 ( L_10 , V_14 -> V_34 ) ;
V_28 = F_11 ( V_24 ) ;
goto V_35;
}
V_14 -> V_36 = V_24 ;
V_25 = V_24 -> V_37 -> V_38 ;
if ( F_12 ( V_25 -> V_39 ) ) {
struct V_40 * V_41 ;
unsigned long long V_42 ;
V_41 = F_13 ( V_25 -> V_43 ) ;
V_23 = & V_21 . V_23 ;
V_23 -> V_44 = F_14 ( V_25 -> V_43 ) ;
V_23 -> V_45 = F_15 ( V_41 ) ;
V_23 -> V_46 = F_16 ( V_41 ) ;
V_14 -> V_47 = F_14 ( V_25 -> V_43 ) ;
V_42 = ( F_17 ( V_24 -> V_37 -> V_38 ) -
V_14 -> V_47 ) ;
F_4 ( L_11
L_12 ,
V_42 , F_18 ( V_42 , V_14 -> V_47 ) ,
V_14 -> V_47 ) ;
} else {
if ( ! ( V_14 -> V_48 & V_49 ) ) {
F_3 ( L_13
L_14
L_15 ) ;
goto V_35;
}
V_23 = & V_21 . V_23 ;
V_23 -> V_44 = V_50 ;
V_23 -> V_45 = V_12 ;
V_23 -> V_46 = V_12 ;
V_14 -> V_47 = V_50 ;
}
V_21 . V_51 = V_52 ;
V_21 . V_53 = V_54 ;
V_19 = F_19 ( V_2 , & V_55 ,
V_17 , V_26 , V_14 ,
& V_21 , L_16 , V_10 ) ;
if ( ! V_19 )
goto V_35;
V_14 -> V_56 = V_4 -> V_57 ++ ;
V_14 -> V_58 = V_19 -> V_53 ;
F_4 ( L_17
L_18 , V_4 -> V_7 , V_14 -> V_56 ,
V_14 -> V_34 , V_14 -> V_59 ) ;
return V_19 ;
V_35:
if ( V_14 -> V_36 ) {
F_20 ( V_14 -> V_36 , NULL ) ;
V_14 -> V_36 = NULL ;
}
return F_21 ( V_28 ) ;
}
static void F_22 ( void * V_18 )
{
struct V_14 * V_14 = V_18 ;
if ( V_14 -> V_36 ) {
F_20 ( V_14 -> V_36 , NULL ) ;
V_14 -> V_36 = NULL ;
}
F_6 ( V_14 ) ;
}
static int F_23 ( struct V_60 * V_61 , struct V_62 * V_63 ,
T_1 V_64 )
{
struct V_15 * V_17 = V_61 -> V_17 ;
struct V_14 * V_19 = V_17 -> V_65 ;
struct V_24 * V_66 = V_19 -> V_36 ;
struct V_62 * V_67 ;
struct V_68 * V_69 ;
T_2 V_70 ;
T_3 V_71 = ( V_61 -> V_72 *
V_17 -> V_73 -> V_74 . V_75 ) ;
int V_28 = 0 , V_76 ;
V_69 = F_2 ( sizeof( struct V_68 ) * V_64 , V_5 ) ;
if ( ! V_69 ) {
F_3 ( L_19 ) ;
return - V_6 ;
}
F_24 (sgl, sg, sgl_nents, i) {
V_69 [ V_76 ] . V_77 = V_67 -> V_78 ;
V_69 [ V_76 ] . V_79 = F_25 ( V_67 ) ;
}
V_70 = F_26 () ;
F_27 ( F_28 () ) ;
V_28 = F_29 ( V_66 , & V_69 [ 0 ] , V_64 , & V_71 ) ;
F_27 ( V_70 ) ;
F_6 ( V_69 ) ;
if ( F_12 ( V_66 -> V_80 -> V_81 -> V_39 ) ) {
if ( V_28 < 0 || V_28 != V_61 -> V_82 ) {
F_3 ( L_20
L_21 , V_28 ,
( int ) V_61 -> V_82 ) ;
return ( V_28 < 0 ? V_28 : - V_29 ) ;
}
} else {
if ( V_28 < 0 ) {
F_3 ( L_22
L_23 , V_28 ) ;
return V_28 ;
}
}
return 1 ;
}
static int F_30 ( struct V_60 * V_61 , struct V_62 * V_63 ,
T_1 V_64 )
{
struct V_15 * V_17 = V_61 -> V_17 ;
struct V_14 * V_19 = V_17 -> V_65 ;
struct V_24 * V_66 = V_19 -> V_36 ;
struct V_62 * V_67 ;
struct V_68 * V_69 ;
T_2 V_70 ;
T_3 V_71 = ( V_61 -> V_72 *
V_17 -> V_73 -> V_74 . V_75 ) ;
int V_28 , V_76 = 0 ;
V_69 = F_2 ( sizeof( struct V_68 ) * V_64 , V_5 ) ;
if ( ! V_69 ) {
F_3 ( L_24 ) ;
return - V_6 ;
}
F_24 (sgl, sg, sgl_nents, i) {
V_69 [ V_76 ] . V_77 = V_67 -> V_78 ;
V_69 [ V_76 ] . V_79 = F_25 ( V_67 ) ;
}
V_70 = F_26 () ;
F_27 ( F_28 () ) ;
V_28 = F_31 ( V_66 , & V_69 [ 0 ] , V_64 , & V_71 ) ;
F_27 ( V_70 ) ;
F_6 ( V_69 ) ;
if ( V_28 < 0 || V_28 != V_61 -> V_82 ) {
F_3 ( L_25 , V_28 ) ;
return ( V_28 < 0 ? V_28 : - V_29 ) ;
}
return 1 ;
}
static int F_32 ( struct V_60 * V_61 )
{
struct V_15 * V_19 = V_61 -> V_17 ;
struct V_14 * V_14 = V_19 -> V_65 ;
int V_83 = ( V_61 -> V_84 [ 1 ] & 0x2 ) ;
T_3 V_85 , V_86 ;
int V_28 ;
if ( V_83 )
F_33 ( V_61 , V_87 ) ;
if ( V_61 -> V_72 == 0 && V_61 -> V_82 == 0 ) {
V_85 = 0 ;
V_86 = V_88 ;
} else {
V_85 = V_61 -> V_72 * V_19 -> V_73 -> V_74 . V_75 ;
if ( V_61 -> V_82 )
V_86 = V_85 + V_61 -> V_82 ;
else
V_86 = V_88 ;
}
V_28 = F_34 ( V_14 -> V_36 , V_85 , V_86 , 1 ) ;
if ( V_28 != 0 )
F_3 ( L_26 , V_28 ) ;
if ( V_83 )
return 0 ;
if ( V_28 ) {
V_61 -> V_89 = V_90 ;
F_33 ( V_61 , V_91 ) ;
} else {
F_33 ( V_61 , V_87 ) ;
}
return 0 ;
}
static int F_35 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_92 ;
T_1 V_64 = V_61 -> V_93 ;
enum V_94 V_95 = V_61 -> V_95 ;
struct V_15 * V_19 = V_61 -> V_17 ;
int V_28 = 0 ;
if ( V_95 == V_96 ) {
V_28 = F_23 ( V_61 , V_63 , V_64 ) ;
} else {
V_28 = F_30 ( V_61 , V_63 , V_64 ) ;
if ( V_28 > 0 &&
V_19 -> V_73 -> V_74 . V_97 > 0 &&
( V_61 -> V_98 & V_99 ) ) {
struct V_14 * V_14 = V_19 -> V_65 ;
T_3 V_85 = V_61 -> V_72 *
V_19 -> V_73 -> V_74 . V_75 ;
T_3 V_86 = V_85 + V_61 -> V_82 ;
F_34 ( V_14 -> V_36 , V_85 , V_86 , 1 ) ;
}
}
if ( V_28 < 0 ) {
V_61 -> V_89 = V_90 ;
return V_28 ;
}
if ( V_28 )
F_33 ( V_61 , V_87 ) ;
return 0 ;
}
static T_4 F_36 (
struct V_1 * V_2 ,
struct V_16 * V_17 ,
const char * V_100 , T_4 V_101 )
{
struct V_14 * V_14 = V_17 -> V_102 ;
char * V_103 , * V_104 , * V_105 , * V_106 ;
T_5 args [ V_107 ] ;
int V_28 = 0 , V_108 ;
V_106 = F_37 ( V_100 , V_5 ) ;
if ( ! V_106 )
return - V_6 ;
V_103 = V_106 ;
while ( ( V_104 = F_38 ( & V_106 , L_27 ) ) != NULL ) {
if ( ! * V_104 )
continue;
V_108 = F_39 ( V_104 , V_109 , args ) ;
switch ( V_108 ) {
case V_110 :
if ( F_40 ( V_14 -> V_34 , & args [ 0 ] ,
V_111 ) == 0 ) {
V_28 = - V_29 ;
break;
}
F_4 ( L_28 ,
V_14 -> V_34 ) ;
V_14 -> V_48 |= V_112 ;
break;
case V_113 :
V_105 = F_41 ( & args [ 0 ] ) ;
if ( ! V_105 ) {
V_28 = - V_6 ;
break;
}
V_28 = F_42 ( V_105 , 0 , & V_14 -> V_59 ) ;
F_6 ( V_105 ) ;
if ( V_28 < 0 ) {
F_3 ( L_29
L_30 ) ;
goto V_114;
}
F_4 ( L_31
L_32 , V_14 -> V_59 ) ;
V_14 -> V_48 |= V_49 ;
break;
default:
break;
}
}
V_114:
F_6 ( V_103 ) ;
return ( ! V_28 ) ? V_101 : V_28 ;
}
static T_4 F_43 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_14 * V_14 = V_17 -> V_102 ;
if ( ! ( V_14 -> V_48 & V_112 ) ) {
F_3 ( L_33 ) ;
return - V_29 ;
}
return 0 ;
}
static T_4 F_44 (
struct V_1 * V_2 ,
struct V_16 * V_17 ,
char * V_115 )
{
struct V_14 * V_14 = V_17 -> V_102 ;
T_4 V_116 = 0 ;
V_116 = sprintf ( V_115 + V_116 , L_34 , V_14 -> V_56 ) ;
V_116 += sprintf ( V_115 + V_116 , L_35 ,
V_14 -> V_34 , V_14 -> V_59 ) ;
return V_116 ;
}
static T_1 F_45 ( struct V_15 * V_19 )
{
return V_117 ;
}
static T_1 F_46 ( struct V_15 * V_19 )
{
return V_118 ;
}
static T_6 F_47 ( struct V_15 * V_19 )
{
struct V_14 * V_14 = V_19 -> V_65 ;
struct V_24 * V_119 = V_14 -> V_36 ;
struct V_25 * V_76 = V_119 -> V_37 -> V_38 ;
unsigned long long V_42 ;
if ( F_12 ( V_76 -> V_39 ) )
V_42 = ( F_17 ( V_76 ) - V_14 -> V_47 ) ;
else
V_42 = V_14 -> V_59 ;
return F_18 ( V_42 , V_19 -> V_73 -> V_74 . V_75 ) ;
}
static int F_48 ( struct V_60 * V_61 )
{
return F_49 ( V_61 , & V_120 ) ;
}
static int T_7 F_50 ( void )
{
return F_51 ( & V_55 ) ;
}
static void F_52 ( void )
{
F_53 ( & V_55 ) ;
}
