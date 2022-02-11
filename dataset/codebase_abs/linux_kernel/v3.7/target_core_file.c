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
if ( V_14 -> V_34 & V_35 ) {
F_4 ( L_10 ) ;
V_27 &= ~ V_33 ;
}
V_24 = F_9 ( V_14 -> V_36 , V_27 , 0600 ) ;
if ( F_10 ( V_24 ) ) {
F_3 ( L_11 , V_14 -> V_36 ) ;
V_28 = F_11 ( V_24 ) ;
goto V_37;
}
V_14 -> V_38 = V_24 ;
V_25 = V_24 -> V_39 -> V_40 ;
if ( F_12 ( V_25 -> V_41 ) ) {
struct V_42 * V_43 ;
unsigned long long V_44 ;
V_43 = F_13 ( V_25 -> V_45 ) ;
V_23 = & V_21 . V_23 ;
V_23 -> V_46 = F_14 ( V_25 -> V_45 ) ;
V_23 -> V_47 = F_15 ( V_43 ) ;
V_23 -> V_48 = F_16 ( V_43 ) ;
V_14 -> V_49 = F_14 ( V_25 -> V_45 ) ;
V_44 = ( F_17 ( V_24 -> V_39 -> V_40 ) -
V_14 -> V_49 ) ;
F_4 ( L_12
L_13 ,
V_44 , F_18 ( V_44 , V_14 -> V_49 ) ,
V_14 -> V_49 ) ;
} else {
if ( ! ( V_14 -> V_34 & V_50 ) ) {
F_3 ( L_14
L_15
L_16 ) ;
goto V_37;
}
V_23 = & V_21 . V_23 ;
V_23 -> V_46 = V_51 ;
V_23 -> V_47 = V_12 ;
V_23 -> V_48 = V_12 ;
V_14 -> V_49 = V_51 ;
}
V_21 . V_52 = V_53 ;
V_21 . V_54 = V_55 ;
V_19 = F_19 ( V_2 , & V_56 ,
V_17 , V_26 , V_14 ,
& V_21 , L_17 , V_10 ) ;
if ( ! V_19 )
goto V_37;
if ( V_14 -> V_34 & V_35 ) {
F_4 ( L_18
L_19 ) ;
V_19 -> V_57 -> V_58 . V_59 = 1 ;
}
V_14 -> V_60 = V_4 -> V_61 ++ ;
V_14 -> V_62 = V_19 -> V_54 ;
F_4 ( L_20
L_21 , V_4 -> V_7 , V_14 -> V_60 ,
V_14 -> V_36 , V_14 -> V_63 ) ;
return V_19 ;
V_37:
if ( V_14 -> V_38 ) {
F_20 ( V_14 -> V_38 , NULL ) ;
V_14 -> V_38 = NULL ;
}
return F_21 ( V_28 ) ;
}
static void F_22 ( void * V_18 )
{
struct V_14 * V_14 = V_18 ;
if ( V_14 -> V_38 ) {
F_20 ( V_14 -> V_38 , NULL ) ;
V_14 -> V_38 = NULL ;
}
F_6 ( V_14 ) ;
}
static int F_23 ( struct V_64 * V_65 , struct V_66 * V_67 ,
T_1 V_68 )
{
struct V_15 * V_17 = V_65 -> V_17 ;
struct V_14 * V_19 = V_17 -> V_69 ;
struct V_24 * V_70 = V_19 -> V_38 ;
struct V_66 * V_71 ;
struct V_72 * V_73 ;
T_2 V_74 ;
T_3 V_75 = ( V_65 -> V_76 *
V_17 -> V_57 -> V_58 . V_77 ) ;
int V_28 = 0 , V_78 ;
V_73 = F_2 ( sizeof( struct V_72 ) * V_68 , V_5 ) ;
if ( ! V_73 ) {
F_3 ( L_22 ) ;
return - V_6 ;
}
F_24 (sgl, sg, sgl_nents, i) {
V_73 [ V_78 ] . V_79 = V_71 -> V_80 ;
V_73 [ V_78 ] . V_81 = F_25 ( V_71 ) ;
}
V_74 = F_26 () ;
F_27 ( F_28 () ) ;
V_28 = F_29 ( V_70 , & V_73 [ 0 ] , V_68 , & V_75 ) ;
F_27 ( V_74 ) ;
F_6 ( V_73 ) ;
if ( F_12 ( V_70 -> V_82 -> V_83 -> V_41 ) ) {
if ( V_28 < 0 || V_28 != V_65 -> V_84 ) {
F_3 ( L_23
L_24 , V_28 ,
( int ) V_65 -> V_84 ) ;
return ( V_28 < 0 ? V_28 : - V_29 ) ;
}
} else {
if ( V_28 < 0 ) {
F_3 ( L_25
L_26 , V_28 ) ;
return V_28 ;
}
}
return 1 ;
}
static int F_30 ( struct V_64 * V_65 , struct V_66 * V_67 ,
T_1 V_68 )
{
struct V_15 * V_17 = V_65 -> V_17 ;
struct V_14 * V_19 = V_17 -> V_69 ;
struct V_24 * V_70 = V_19 -> V_38 ;
struct V_66 * V_71 ;
struct V_72 * V_73 ;
T_2 V_74 ;
T_3 V_75 = ( V_65 -> V_76 *
V_17 -> V_57 -> V_58 . V_77 ) ;
int V_28 , V_78 = 0 ;
V_73 = F_2 ( sizeof( struct V_72 ) * V_68 , V_5 ) ;
if ( ! V_73 ) {
F_3 ( L_27 ) ;
return - V_6 ;
}
F_24 (sgl, sg, sgl_nents, i) {
V_73 [ V_78 ] . V_79 = V_71 -> V_80 ;
V_73 [ V_78 ] . V_81 = F_25 ( V_71 ) ;
}
V_74 = F_26 () ;
F_27 ( F_28 () ) ;
V_28 = F_31 ( V_70 , & V_73 [ 0 ] , V_68 , & V_75 ) ;
F_27 ( V_74 ) ;
F_6 ( V_73 ) ;
if ( V_28 < 0 || V_28 != V_65 -> V_84 ) {
F_3 ( L_28 , V_28 ) ;
return ( V_28 < 0 ? V_28 : - V_29 ) ;
}
return 1 ;
}
static int F_32 ( struct V_64 * V_65 )
{
struct V_15 * V_19 = V_65 -> V_17 ;
struct V_14 * V_14 = V_19 -> V_69 ;
int V_85 = ( V_65 -> V_86 [ 1 ] & 0x2 ) ;
T_3 V_87 , V_88 ;
int V_28 ;
if ( V_85 )
F_33 ( V_65 , V_89 ) ;
if ( V_65 -> V_76 == 0 && V_65 -> V_84 == 0 ) {
V_87 = 0 ;
V_88 = V_90 ;
} else {
V_87 = V_65 -> V_76 * V_19 -> V_57 -> V_58 . V_77 ;
if ( V_65 -> V_84 )
V_88 = V_87 + V_65 -> V_84 ;
else
V_88 = V_90 ;
}
V_28 = F_34 ( V_14 -> V_38 , V_87 , V_88 , 1 ) ;
if ( V_28 != 0 )
F_3 ( L_29 , V_28 ) ;
if ( V_85 )
return 0 ;
if ( V_28 ) {
V_65 -> V_91 = V_92 ;
F_33 ( V_65 , V_93 ) ;
} else {
F_33 ( V_65 , V_89 ) ;
}
return 0 ;
}
static int F_35 ( struct V_64 * V_65 )
{
struct V_66 * V_67 = V_65 -> V_94 ;
T_1 V_68 = V_65 -> V_95 ;
enum V_96 V_97 = V_65 -> V_97 ;
struct V_15 * V_19 = V_65 -> V_17 ;
int V_28 = 0 ;
if ( V_97 == V_98 ) {
V_28 = F_23 ( V_65 , V_67 , V_68 ) ;
} else {
V_28 = F_30 ( V_65 , V_67 , V_68 ) ;
if ( V_28 > 0 &&
V_19 -> V_57 -> V_58 . V_99 > 0 &&
( V_65 -> V_100 & V_101 ) ) {
struct V_14 * V_14 = V_19 -> V_69 ;
T_3 V_87 = V_65 -> V_76 *
V_19 -> V_57 -> V_58 . V_77 ;
T_3 V_88 = V_87 + V_65 -> V_84 ;
F_34 ( V_14 -> V_38 , V_87 , V_88 , 1 ) ;
}
}
if ( V_28 < 0 ) {
V_65 -> V_91 = V_92 ;
return V_28 ;
}
if ( V_28 )
F_33 ( V_65 , V_89 ) ;
return 0 ;
}
static T_4 F_36 (
struct V_1 * V_2 ,
struct V_16 * V_17 ,
const char * V_102 , T_4 V_103 )
{
struct V_14 * V_14 = V_17 -> V_104 ;
char * V_105 , * V_106 , * V_107 , * V_108 ;
T_5 args [ V_109 ] ;
int V_28 = 0 , V_110 , V_111 ;
V_108 = F_37 ( V_102 , V_5 ) ;
if ( ! V_108 )
return - V_6 ;
V_105 = V_108 ;
while ( ( V_106 = F_38 ( & V_108 , L_30 ) ) != NULL ) {
if ( ! * V_106 )
continue;
V_111 = F_39 ( V_106 , V_112 , args ) ;
switch ( V_111 ) {
case V_113 :
if ( F_40 ( V_14 -> V_36 , & args [ 0 ] ,
V_114 ) == 0 ) {
V_28 = - V_29 ;
break;
}
F_4 ( L_31 ,
V_14 -> V_36 ) ;
V_14 -> V_34 |= V_115 ;
break;
case V_116 :
V_107 = F_41 ( & args [ 0 ] ) ;
if ( ! V_107 ) {
V_28 = - V_6 ;
break;
}
V_28 = F_42 ( V_107 , 0 , & V_14 -> V_63 ) ;
F_6 ( V_107 ) ;
if ( V_28 < 0 ) {
F_3 ( L_32
L_33 ) ;
goto V_117;
}
F_4 ( L_34
L_35 , V_14 -> V_63 ) ;
V_14 -> V_34 |= V_50 ;
break;
case V_118 :
F_43 ( args , & V_110 ) ;
if ( V_110 != 1 ) {
F_3 ( L_36 , V_110 ) ;
V_28 = - V_29 ;
goto V_117;
}
F_4 ( L_37
L_38 ) ;
V_14 -> V_34 |= V_35 ;
break;
default:
break;
}
}
V_117:
F_6 ( V_105 ) ;
return ( ! V_28 ) ? V_103 : V_28 ;
}
static T_4 F_44 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_14 * V_14 = V_17 -> V_104 ;
if ( ! ( V_14 -> V_34 & V_115 ) ) {
F_3 ( L_39 ) ;
return - V_29 ;
}
return 0 ;
}
static T_4 F_45 (
struct V_1 * V_2 ,
struct V_16 * V_17 ,
char * V_119 )
{
struct V_14 * V_14 = V_17 -> V_104 ;
T_4 V_120 = 0 ;
V_120 = sprintf ( V_119 + V_120 , L_40 , V_14 -> V_60 ) ;
V_120 += sprintf ( V_119 + V_120 , L_41 ,
V_14 -> V_36 , V_14 -> V_63 ,
( V_14 -> V_34 & V_35 ) ?
L_42 : L_43 ) ;
return V_120 ;
}
static T_1 F_46 ( struct V_15 * V_19 )
{
return V_121 ;
}
static T_1 F_47 ( struct V_15 * V_19 )
{
return V_122 ;
}
static T_6 F_48 ( struct V_15 * V_19 )
{
struct V_14 * V_14 = V_19 -> V_69 ;
struct V_24 * V_123 = V_14 -> V_38 ;
struct V_25 * V_78 = V_123 -> V_39 -> V_40 ;
unsigned long long V_44 ;
if ( F_12 ( V_78 -> V_41 ) )
V_44 = ( F_17 ( V_78 ) - V_14 -> V_49 ) ;
else
V_44 = V_14 -> V_63 ;
return F_18 ( V_44 , V_19 -> V_57 -> V_58 . V_77 ) ;
}
static int F_49 ( struct V_64 * V_65 )
{
return F_50 ( V_65 , & V_124 ) ;
}
static int T_7 F_51 ( void )
{
return F_52 ( & V_56 ) ;
}
static void F_53 ( void )
{
F_54 ( & V_56 ) ;
}
