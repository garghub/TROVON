static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_5 -> V_9 = F_2 ( V_3 << V_10 ) ;
if ( NULL == V_5 -> V_9 ) {
F_3 ( 1 , L_1 , V_3 ) ;
return - V_11 ;
}
F_3 ( 1 , L_2 ,
( unsigned long ) V_5 -> V_9 ,
V_3 << V_10 ) ;
memset ( V_5 -> V_9 , 0 , V_3 << V_10 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_12 = F_4 ( V_5 -> V_3 * sizeof( * V_5 -> V_12 ) ) ;
if ( NULL == V_5 -> V_12 )
goto V_13;
F_5 ( V_5 -> V_12 , V_5 -> V_3 ) ;
for ( V_8 = 0 ; V_8 < V_5 -> V_3 ; V_8 ++ ) {
V_7 = F_6 ( V_5 -> V_9 + V_8 * V_14 ) ;
if ( NULL == V_7 )
goto V_15;
F_7 ( & V_5 -> V_12 [ V_8 ] , V_7 , V_14 , 0 ) ;
}
return 0 ;
V_15:
F_8 ( V_5 -> V_12 ) ;
V_5 -> V_12 = NULL ;
V_13:
F_8 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
return - V_11 ;
}
static int F_9 ( struct V_1 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_5 ;
V_5 -> V_17 = F_10 ( & V_16 -> V_18 -> V_16 , V_5 -> V_12 ,
V_5 -> V_3 , V_19 ) ;
if ( 0 == V_5 -> V_17 ) {
F_11 ( L_3 , V_20 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_5 ;
if ( ! V_5 -> V_17 )
return 0 ;
F_13 ( & V_16 -> V_18 -> V_16 , V_5 -> V_12 , V_5 -> V_17 , V_19 ) ;
V_5 -> V_17 = 0 ;
return 0 ;
}
static int F_14 ( struct V_4 * V_5 )
{
F_8 ( V_5 -> V_12 ) ;
V_5 -> V_12 = NULL ;
F_8 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_21 * V_16 = V_2 -> V_16 ;
const struct V_22 * V_23 =
& V_24 [ V_25 ] ;
T_1 V_26 = 0 ;
F_16 ( V_2 -> V_16 , 0 , 0 ) ;
F_17 ( V_27 ,
V_28 | V_29 ) ;
F_18 ( V_2 -> V_16 , V_23 , V_5 -> V_30 ,
V_5 -> V_31 . V_32 ) ;
F_19 ( V_33 , V_5 -> V_30 ) ;
F_19 ( V_34 , V_35 ) ;
F_20 ( & V_2 -> V_36 , 0 ) ;
V_26 = F_21 ( V_37 ) ;
F_19 ( V_37 , V_26 | V_38 | V_39 |
V_40 ) ;
F_19 ( V_41 , V_42 | V_43 |
V_44 | V_45 ) ;
F_19 ( V_46 , ~ 0 ) ;
F_22 ( V_47 , V_2 -> V_16 -> V_48 | V_49 ) ;
V_26 = F_21 ( V_27 ) ;
F_22 ( V_27 , V_26 |
( V_28 | V_29 ) ) ;
F_23 ( 100 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_21 * V_16 = V_2 -> V_16 ;
F_17 ( V_27 ,
V_28 | V_29 ) ;
F_17 ( V_47 , V_49 ) ;
F_17 ( V_41 , V_50 | V_51 |
V_52 | V_53 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_54 ,
T_1 V_55 )
{
struct V_21 * V_16 = V_2 -> V_16 ;
if ( 0 == ( V_54 & V_55 ) )
return;
F_19 ( V_46 , V_54 ) ;
if ( V_56 > 1 || ( V_54 & V_55 & ~ 0xff ) )
F_26 ( V_16 -> V_57 , L_4 , V_58 ,
F_27 ( V_58 ) , V_54 , V_55 ) ;
if ( V_54 & V_50 ) {
F_11 ( L_5 , V_16 -> V_57 ) ;
F_17 ( V_27 ,
V_28 | V_29 ) ;
F_28 ( V_16 ,
& V_24 [ V_25 ] ) ;
}
if ( V_54 & V_51 ) {
F_11 ( L_6 , V_16 -> V_57 ) ;
F_19 ( V_34 , V_35 ) ;
return;
}
if ( V_54 & V_53 ) {
F_20 ( & V_2 -> V_36 , F_21 ( V_59 ) ) ;
F_29 ( V_2 -> V_60 ) ;
}
}
static T_2 F_30 ( int V_61 , void * V_62 )
{
struct V_1 * V_2 = V_62 ;
struct V_21 * V_16 = V_2 -> V_16 ;
T_1 V_54 , V_63 ;
T_1 V_64 , V_65 ;
int V_66 , V_67 = 0 ;
V_64 = F_21 ( V_46 ) ;
V_65 = F_21 ( V_41 ) ;
V_54 = F_21 ( V_68 ) ;
for ( V_66 = 0 ; V_66 < 1 ; V_66 ++ ) {
V_54 = F_21 ( V_68 ) ;
if ( 0 == V_54 ) {
V_54 = F_21 ( V_68 ) ;
V_64 = F_21 ( V_46 ) ;
V_65 = F_21 ( V_41 ) ;
if ( V_54 ) {
V_67 = 1 ;
F_19 ( V_68 , V_54 ) ;
F_25 ( V_2 , V_64 ,
V_65 ) ;
break;
} else {
goto V_69;
}
}
V_67 = 1 ;
F_19 ( V_68 , V_54 ) ;
F_25 ( V_2 , V_64 , V_65 ) ;
}
V_63 = F_21 ( V_68 ) ;
if ( V_67 )
F_19 ( V_68 , V_63 ) ;
V_69:
return F_31 ( V_67 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_70 * V_31 = & V_2 -> V_5 -> V_31 ;
F_33 ( ! V_2 -> V_71 ) ;
F_3 ( 2 , L_7 ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 -> V_5 ) ;
F_34 ( V_2 -> V_18 , V_31 -> V_72 , V_31 -> V_73 , V_31 -> V_32 ) ;
F_35 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_2 -> V_71 = 0 ;
return 0 ;
}
static int F_36 ( struct V_74 * V_60 )
{
struct V_1 * V_2 = F_37 ( V_60 ) ;
struct V_75 * V_76 = V_60 -> V_76 ;
int V_77 ;
unsigned int V_30 = 0 ;
if ( ! V_2 ) {
F_38 ( L_8 ) ;
return - V_78 ;
}
V_77 = F_39 ( V_76 , 0 ,
V_79 ) ;
if ( V_77 < 0 )
goto V_80;
V_2 -> V_60 = V_60 ;
V_76 -> V_81 = V_82 ;
if ( V_24 [ V_25 ] . V_83 !=
V_84 ) {
V_30 = V_24 [ V_25 ] . V_83 / 3 ;
V_30 &= ~ 7 ;
if ( V_30 > V_85 )
V_30 = V_85 ;
V_76 -> V_81 . V_86 = V_30 ;
V_76 -> V_81 . V_87 = V_30 ;
}
return 0 ;
V_80:
F_3 ( 1 , L_9 ) ;
return V_77 ;
}
static int F_40 ( struct V_74 * V_60 )
{
return 0 ;
}
static int F_41 ( struct V_74 * V_60 ,
struct V_88 * V_89 )
{
struct V_1 * V_2 = F_37 ( V_60 ) ;
struct V_4 * V_5 ;
int V_90 ;
if ( V_60 -> V_76 -> V_91 ) {
F_32 ( V_2 ) ;
V_60 -> V_76 -> V_91 = NULL ;
}
V_2 -> V_92 = F_42 ( V_89 ) ;
V_2 -> V_93 = F_43 ( V_89 ) ;
V_2 -> V_71 = V_2 -> V_92 * F_43 ( V_89 ) ;
F_33 ( ! V_2 -> V_71 ) ;
F_33 ( V_2 -> V_93 & ( V_2 -> V_93 - 1 ) ) ;
V_5 = F_44 ( sizeof( * V_5 ) , V_94 ) ;
if ( NULL == V_5 )
return - V_11 ;
if ( V_2 -> V_92 > V_85 )
V_2 -> V_92 = V_85 ;
V_5 -> V_30 = V_2 -> V_92 ;
V_2 -> V_5 = V_5 ;
V_90 = F_1 ( V_2 ,
( F_45 ( V_2 -> V_71 ) >> V_10 ) ) ;
if ( V_90 < 0 )
goto error;
V_90 = F_9 ( V_2 ) ;
if ( V_90 < 0 )
goto error;
V_90 = F_46 ( V_2 -> V_18 , & V_5 -> V_31 , V_5 -> V_12 ,
V_2 -> V_92 , V_2 -> V_93 , 1 ) ;
if ( V_90 < 0 ) {
F_47 ( L_10 ) ;
goto error;
}
V_5 -> V_31 . V_95 [ 0 ] = F_48 ( V_96 | V_97 | V_98 ) ;
V_5 -> V_31 . V_95 [ 1 ] = F_48 ( V_5 -> V_31 . V_32 ) ;
V_5 -> V_31 . V_95 [ 2 ] = F_48 ( 0 ) ;
V_60 -> V_76 -> V_91 = V_2 -> V_5 -> V_9 ;
V_60 -> V_76 -> V_99 = V_2 -> V_71 ;
V_60 -> V_76 -> V_100 = 0 ;
return 0 ;
error:
V_2 -> V_5 = NULL ;
F_35 ( V_5 ) ;
return V_90 ;
}
static int F_49 ( struct V_74 * V_60 )
{
struct V_1 * V_2 = F_37 ( V_60 ) ;
if ( V_60 -> V_76 -> V_91 ) {
F_32 ( V_2 ) ;
V_60 -> V_76 -> V_91 = NULL ;
}
return 0 ;
}
static int F_50 ( struct V_74 * V_60 )
{
return 0 ;
}
static int F_51 ( struct V_74 * V_60 ,
int V_101 )
{
struct V_1 * V_2 = F_37 ( V_60 ) ;
int V_77 = 0 ;
F_52 ( & V_2 -> V_102 ) ;
switch ( V_101 ) {
case V_103 :
V_77 = F_15 ( V_2 ) ;
break;
case V_104 :
V_77 = F_24 ( V_2 ) ;
break;
default:
V_77 = - V_105 ;
break;
}
F_53 ( & V_2 -> V_102 ) ;
return V_77 ;
}
static T_3 F_54 ( struct V_74
* V_60 )
{
struct V_1 * V_2 = F_37 ( V_60 ) ;
struct V_75 * V_76 = V_60 -> V_76 ;
T_4 V_36 ;
V_36 = F_55 ( & V_2 -> V_36 ) ;
return V_76 -> V_92 * ( V_36 & ( V_76 -> V_106 - 1 ) ) ;
}
static struct V_6 * F_56 ( struct V_74 * V_60 ,
unsigned long V_107 )
{
void * V_108 = V_60 -> V_76 -> V_91 + V_107 ;
return F_6 ( V_108 ) ;
}
static int F_57 ( struct V_1 * V_2 , int V_109 ,
char * V_57 )
{
struct V_110 * V_111 ;
int V_77 ;
V_77 = F_58 ( V_2 -> V_112 , V_57 , V_109 , 0 , 1 , & V_111 ) ;
if ( V_77 < 0 ) {
F_47 ( L_11 , V_20 ) ;
return V_77 ;
}
V_111 -> V_113 = V_2 ;
V_111 -> V_114 = 0 ;
strcpy ( V_111 -> V_57 , V_57 ) ;
F_59 ( V_111 , V_115 , & V_116 ) ;
return 0 ;
}
static int F_60 ( struct V_21 * V_16 )
{
struct V_117 * V_112 ;
struct V_1 * V_2 ;
int V_77 ;
if ( V_118 >= V_119 ) {
F_47 ( L_12 , V_20 ) ;
return - V_78 ;
}
if ( ! V_120 [ V_118 ] ) {
++ V_118 ;
F_47 ( L_13 , V_20 ) ;
return - V_121 ;
}
V_77 = F_61 ( & V_16 -> V_18 -> V_16 , V_122 [ V_118 ] , V_123 [ V_118 ] ,
V_124 ,
sizeof( struct V_1 ) , & V_112 ) ;
if ( V_77 < 0 ) {
F_47 ( L_14 ,
V_20 ) ;
return V_77 ;
}
strcpy ( V_112 -> V_125 , L_15 ) ;
V_2 = V_112 -> V_113 ;
F_62 ( & V_2 -> V_102 ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_112 = V_112 ;
V_2 -> V_18 = V_16 -> V_18 ;
V_2 -> V_126 = F_63 ( V_16 -> V_18 , 0 ) ;
V_2 -> V_61 = V_16 -> V_18 -> V_61 ;
V_77 = F_64 ( V_16 -> V_18 -> V_61 , F_30 ,
V_127 , V_2 -> V_16 -> V_57 , V_2 ) ;
if ( V_77 < 0 ) {
F_38 ( L_16 , V_2 -> V_16 -> V_57 ,
V_16 -> V_18 -> V_61 ) ;
goto error;
}
V_77 = F_57 ( V_2 , 0 , L_17 ) ;
if ( V_77 < 0 ) {
F_47 ( L_18 ,
V_20 ) ;
goto error;
}
strcpy ( V_112 -> V_128 , L_15 ) ;
sprintf ( V_112 -> V_129 , L_19 , V_2 -> V_16 -> V_57 ,
V_2 -> V_126 , V_2 -> V_61 ) ;
strcpy ( V_112 -> V_130 , L_20 ) ;
F_47 ( L_21 , V_112 -> V_125 ,
V_118 ) ;
V_77 = F_65 ( V_112 ) ;
if ( V_77 < 0 ) {
F_47 ( L_22 ,
V_20 ) ;
goto error;
}
V_16 -> V_112 = V_112 ;
V_118 ++ ;
return 0 ;
error:
F_66 ( V_112 ) ;
return V_77 ;
}
static int F_67 ( struct V_109 * V_16 , void * V_131 )
{
struct V_132 * V_133 = F_68 ( V_16 ) ;
struct V_21 * V_134 = F_69 ( V_133 ) ;
F_66 ( V_134 -> V_112 ) ;
return 0 ;
}
static void F_70 ( void )
{
struct V_135 * V_136 = F_71 ( L_15 , & V_137 ) ;
int V_90 ;
V_90 = F_72 ( V_136 , NULL , NULL , F_67 ) ;
if ( V_90 )
F_38 ( L_23 , V_20 ) ;
}
static int F_73 ( struct V_109 * V_16 , void * V_131 )
{
struct V_132 * V_133 = F_68 ( V_16 ) ;
struct V_21 * V_134 = F_69 ( V_133 ) ;
F_60 ( V_134 ) ;
return 0 ;
}
static int F_74 ( void )
{
struct V_135 * V_136 = F_71 ( L_15 , & V_137 ) ;
return F_72 ( V_136 , NULL , NULL , F_73 ) ;
}
