static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_6 = V_3 -> V_7 . V_8 ;
F_3 ( V_3 , & V_4 -> V_9 ) ;
F_4 ( & V_4 -> V_10 ) ;
F_5 ( & V_4 -> V_11 ) ;
F_6 ( & V_4 -> V_12 ) ;
F_7 ( & V_4 -> V_13 , 1 ) ;
V_4 -> V_3 = V_3 ;
F_8 ( & V_3 -> V_14 ) ;
return V_4 ;
}
static void F_9 ( struct V_1 * V_4 )
{
F_10 ( L_1 , V_4 ) ;
if ( V_4 -> V_3 )
F_11 ( & V_4 -> V_3 -> V_14 ) ;
F_12 ( V_4 ) ;
}
static void F_13 ( struct V_1 * V_4 )
{
F_14 ( & V_4 -> V_13 ) ;
}
static struct V_1 * F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_15 ;
F_16 ( F_17 ( V_3 ) , V_15 ) ;
V_4 = F_18 ( & V_3 -> V_14 ) ;
if ( V_4 )
F_13 ( V_4 ) ;
F_19 ( F_17 ( V_3 ) , V_15 ) ;
return V_4 ;
}
static struct V_1 * F_20 ( T_1 V_16 )
{
char V_17 [ 16 ] ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
sprintf ( V_17 , L_2 , V_16 ) ;
V_3 = F_21 ( & V_18 , V_17 ) ;
if ( ! V_3 )
return NULL ;
V_4 = F_15 ( V_3 ) ;
F_11 ( & V_3 -> V_14 ) ;
return V_4 ;
}
static void F_22 ( struct V_1 * V_4 )
{
if ( F_23 ( & V_4 -> V_13 ) )
F_9 ( V_4 ) ;
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_18 ( & V_3 -> V_14 ) ;
F_10 ( L_3 , V_3 ) ;
if ( V_4 -> V_19 ) {
F_25 ( L_4
L_5 , F_26 ( & V_3 -> V_14 ) , V_20 ) ;
return - V_21 ;
}
return 0 ;
}
static void F_27 ( struct V_22 * V_23 )
{
struct V_22 * V_24 = V_23 ;
while ( V_24 -> V_25 ) {
F_12 ( ( void * ) ( V_26 ) V_24 -> V_25 ) ;
V_24 ++ ;
}
F_12 ( V_23 ) ;
}
static struct V_22 * F_28 ( const char T_2 * V_27 , int V_28 ,
int V_6 )
{
struct V_22 * V_23 ;
void * V_29 ;
int V_30 ;
F_10 ( L_6 , V_27 , V_28 , V_6 ) ;
V_23 = F_2 ( ( V_28 + 1 ) * sizeof( struct V_22 ) ,
V_5 | V_31 ) ;
if ( ! V_23 )
return F_29 ( - V_32 ) ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ ) {
V_23 [ V_30 ] . V_33 = V_34 ;
V_23 [ V_30 ] . V_15 = V_35 | V_36 ;
V_23 [ V_30 ] . V_37 = V_6 ;
V_29 = F_30 ( V_6 , V_5 | V_31 ) ;
if ( ! V_29 ) {
F_27 ( V_23 ) ;
return F_29 ( - V_32 ) ;
}
V_23 [ V_30 ] . V_25 = ( V_38 ) ( V_26 ) V_29 ;
if ( F_31 ( V_29 , V_27 , V_6 ) ) {
F_27 ( V_23 ) ;
return F_29 ( - V_39 ) ;
}
V_27 += V_6 ;
}
V_23 [ V_30 ] . V_33 = V_40 ;
return V_23 ;
}
static int F_32 ( struct V_1 * V_4 , struct V_22 * V_23 )
{
int V_41 ;
struct V_2 * V_3 = V_4 -> V_3 ;
F_33 ( V_42 ) ;
F_10 ( L_7 , V_23 ) ;
V_41 = F_34 ( & V_4 -> V_10 ) ;
if ( V_41 )
return V_41 ;
V_4 -> V_43 = & V_42 ;
F_35 ( F_17 ( V_3 ) ) ;
V_41 = F_36 ( V_3 , V_23 , 1 , 0 , 0 ) ;
F_37 ( F_17 ( V_3 ) ) ;
F_10 ( L_8 , V_41 ) ;
if ( V_41 )
goto V_44;
F_38 ( & V_42 ) ;
F_10 ( L_9 ) ;
V_41 = 0 ;
V_44:
F_39 ( & V_4 -> V_10 ) ;
return V_41 ;
}
static void F_40 ( struct V_2 * V_3 , unsigned long V_45 ,
struct V_46 * V_46 )
{
struct V_1 * V_4 ;
F_41 ( F_42 () ) . V_47 [ V_48 ] ++ ;
F_10 ( L_10 ,
V_45 , V_46 -> V_49 . V_50 . V_51 , V_46 -> V_49 . V_50 . V_52 ,
V_46 -> V_49 . V_50 . V_37 ) ;
if ( ! V_45 ) {
F_10 ( L_11 ) ;
return;
}
V_4 = F_18 ( & V_3 -> V_14 ) ;
F_43 ( ! V_4 ) ;
if ( F_44 ( V_46 ) )
V_4 -> V_53 = F_45 ( V_46 ) ;
else if ( V_46 -> V_49 . V_50 . V_52 == ( V_54 | V_55 ) )
V_4 -> V_53 = 0 ;
else
V_4 -> V_53 = - V_56 ;
F_46 ( V_4 -> V_43 ) ;
}
static T_3 F_47 ( struct V_57 * V_14 ,
struct V_58 * V_59 , char * V_60 )
{
struct V_1 * V_4 ;
int V_41 ;
V_4 = F_15 ( F_48 ( V_14 ) ) ;
if ( ! V_4 )
return - V_61 ;
V_41 = sprintf ( V_60 , L_12 , V_4 -> V_6 ) ;
F_22 ( V_4 ) ;
return V_41 ;
}
static int F_49 ( struct V_57 * V_14 )
{
return F_50 ( V_14 , & V_62 ) ;
}
static void F_51 ( struct V_57 * V_14 )
{
F_52 ( V_14 , & V_62 ) ;
}
static int F_53 ( struct V_1 * V_4 )
{
static struct V_63 V_64 ;
int V_65 ;
V_64 . V_66 = V_4 -> V_9 . V_16 ;
V_64 . V_67 = sizeof( struct V_63 ) ;
V_65 = V_63 ( & V_64 ) ;
switch ( V_65 ) {
case 0 :
return - V_68 ;
case 2 :
return V_64 . V_69 ;
case 3 :
return - V_61 ;
default:
return - V_56 ;
}
}
static struct V_70 * F_54 ( struct V_1 * V_4 )
{
struct V_70 * V_71 ;
V_71 = F_2 ( sizeof( struct V_70 ) , V_5 ) ;
if ( ! V_71 )
return NULL ;
V_71 -> V_4 = V_4 ;
F_10 ( L_13 , V_4 , V_71 ,
V_71 -> V_72 ) ;
return V_71 ;
}
static void F_55 ( struct V_70 * V_71 )
{
F_10 ( L_14 , V_71 , V_71 -> V_4 ) ;
F_12 ( V_71 ) ;
}
static T_3 F_56 ( struct V_1 * V_4 , const char T_2 * V_73 ,
T_4 V_37 , T_4 V_6 , T_5 * V_74 )
{
struct V_22 * V_23 ;
int V_41 ;
V_23 = F_28 ( V_73 , V_37 / V_6 , V_6 ) ;
if ( F_44 ( V_23 ) )
return F_45 ( V_23 ) ;
V_41 = F_32 ( V_4 , V_23 ) ;
if ( V_41 )
goto V_75;
if ( V_4 -> V_53 ) {
V_41 = V_4 -> V_53 ;
goto V_75;
}
* V_74 += V_37 ;
V_41 = V_37 ;
V_75:
F_27 ( V_23 ) ;
return V_41 ;
}
static T_3 F_57 ( struct V_76 * V_76 , const char T_2 * V_73 ,
T_4 V_37 , T_5 * V_74 )
{
struct V_70 * V_71 = V_76 -> V_77 ;
F_10 ( L_15 , V_37 ) ;
if ( V_37 == 0 )
return 0 ;
if ( V_37 % V_71 -> V_72 )
return - V_78 ;
if ( V_37 > V_71 -> V_72 * V_79 )
V_37 = V_71 -> V_72 * V_79 ;
return F_56 ( V_71 -> V_4 , V_73 , V_37 , V_71 -> V_72 , V_74 ) ;
}
static int F_58 ( int V_16 , int V_80 )
{
int V_65 ;
V_65 = F_59 ( V_80 , V_16 , 0x28 ) ;
switch ( V_65 ) {
case 0 :
return 0 ;
case 2 :
return - V_81 ;
case 3 :
return - V_82 ;
default:
return - V_56 ;
}
}
static int F_60 ( int V_16 , char * V_60 )
{
int V_65 ;
V_65 = F_59 ( ( unsigned long ) V_60 , V_16 , 0x00 ) ;
switch ( V_65 ) {
case 0 :
return 0 ;
case 1 :
return - V_82 ;
case 2 :
return - V_81 ;
default:
return - V_56 ;
}
}
static T_3 F_61 ( struct V_76 * V_76 , char T_2 * V_27 , T_4 V_37 ,
T_5 * V_83 )
{
T_4 V_84 , V_85 , V_86 ;
char * V_60 ;
int V_41 ;
T_1 V_6 ;
struct V_1 * V_4 ;
V_4 = ( (struct V_70 * ) V_76 -> V_77 ) -> V_4 ;
V_6 = ( (struct V_70 * ) V_76 -> V_77 ) -> V_87 ;
V_41 = F_58 ( V_4 -> V_9 . V_16 , * V_83 / V_88 + 1 ) ;
if ( V_41 == - V_82 )
return 0 ;
if ( V_41 )
return V_41 ;
V_84 = F_62 ( ( T_4 ) V_88 , V_37 ) ;
V_60 = ( char * ) F_63 ( V_5 | V_31 ) ;
if ( ! V_60 )
return - V_32 ;
V_85 = 0 ;
V_86 = ( T_4 ) ( * V_83 % V_88 ) ;
do {
V_41 = F_60 ( V_4 -> V_9 . V_16 , V_60 ) ;
if ( V_41 == - V_82 ) {
break;
}
if ( V_41 )
goto V_89;
if ( V_6 && ( V_85 == 0 ) && ( * V_83 < V_88 ) )
* ( ( T_1 * ) & V_60 [ V_90 ] ) = V_6 ;
V_84 = F_62 ( V_37 - V_85 , V_88 - V_86 ) ;
if ( F_64 ( V_27 + V_85 , V_60 + V_86 , V_84 ) ) {
V_41 = - V_39 ;
goto V_89;
}
V_86 = 0 ;
V_85 += V_84 ;
} while ( V_85 != V_37 );
* V_83 += V_85 ;
V_41 = V_85 ;
V_89:
F_65 ( ( unsigned long ) V_60 ) ;
return V_41 ;
}
static T_3 F_66 ( struct V_76 * V_76 , char T_2 * V_27 , T_4 V_37 ,
T_5 * V_83 )
{
struct V_1 * V_4 ;
int V_41 ;
F_10 ( L_16 , V_37 , ( unsigned long ) * V_83 ) ;
if ( V_37 == 0 )
return 0 ;
V_4 = ( (struct V_70 * ) V_76 -> V_77 ) -> V_4 ;
V_41 = F_34 ( & V_4 -> V_10 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_61 ( V_76 , V_27 , V_37 , V_83 ) ;
F_39 ( & V_4 -> V_10 ) ;
return V_41 ;
}
static int F_67 ( struct V_91 * V_60 , int V_92 )
{
int V_65 ;
V_65 = F_59 ( ( unsigned long ) V_60 , V_92 , 0xfff ) ;
switch ( V_65 ) {
case 0 :
return 0 ;
default:
return - V_82 ;
}
}
static int F_68 ( struct V_1 * V_4 )
{
struct V_91 * V_93 ;
char * V_60 ;
int V_41 ;
V_93 = F_30 ( sizeof( * V_93 ) , V_5 | V_31 ) ;
if ( ! V_93 )
return - V_32 ;
V_41 = F_67 ( V_93 , 0 ) ;
if ( V_41 )
goto V_94;
if ( V_93 -> V_95 & ( V_96 | V_97 ) ) {
V_41 = - V_98 ;
goto V_94;
}
V_60 = ( char * ) F_63 ( V_5 | V_31 ) ;
if ( ! V_60 ) {
V_41 = - V_32 ;
goto V_94;
}
V_41 = F_60 ( V_4 -> V_9 . V_16 , V_60 ) ;
if ( ( V_41 != 0 ) && ( V_41 != - V_82 ) )
goto V_99;
V_41 = F_67 ( V_93 , 0 ) ;
if ( V_41 )
goto V_99;
if ( ! ( V_93 -> V_95 & V_100 ) ) {
V_41 = - V_101 ;
goto V_99;
}
V_41 = 0 ;
V_99:
F_65 ( ( unsigned long ) V_60 ) ;
V_94:
F_12 ( V_93 ) ;
return V_41 ;
}
static int F_69 ( struct V_1 * V_4 )
{
switch ( V_4 -> V_102 ) {
case V_103 :
return 0 ;
case V_104 :
return F_68 ( V_4 ) ;
default:
return - V_68 ;
}
}
static int F_70 ( struct V_1 * V_4 )
{
struct V_91 * V_93 ;
int V_41 ;
V_93 = F_30 ( sizeof( * V_93 ) , V_5 | V_31 ) ;
if ( ! V_93 )
return - V_32 ;
V_41 = F_67 ( V_93 , 0 ) ;
if ( V_41 )
goto V_105;
if ( V_93 -> V_95 & V_106 )
V_41 = 0 ;
else
V_41 = V_93 -> V_107 ;
V_105:
F_12 ( V_93 ) ;
return V_41 ;
}
static int F_71 ( struct V_1 * V_4 )
{
switch ( V_4 -> V_102 ) {
case V_103 :
return 0 ;
case V_104 :
return F_70 ( V_4 ) ;
default:
return - V_68 ;
}
}
static int F_72 ( struct V_108 * V_108 , struct V_76 * V_76 )
{
T_1 V_16 ;
struct V_1 * V_4 ;
struct V_70 * V_71 ;
unsigned short V_109 ;
int V_41 ;
V_109 = V_76 -> V_110 & V_111 ;
if ( V_109 == V_112 )
return - V_113 ;
V_16 = F_73 ( V_76 -> V_114 -> V_115 -> V_116 ) ;
V_4 = F_20 ( V_16 ) ;
if ( ! V_4 ) {
V_41 = - V_117 ;
goto V_44;
}
F_74 ( & V_4 -> V_12 ) ;
while ( V_4 -> V_19 ) {
F_75 ( & V_4 -> V_12 ) ;
if ( V_76 -> V_110 & V_118 ) {
V_41 = - V_21 ;
goto V_119;
}
if ( F_76 ( V_4 -> V_11 , V_4 -> V_19 == 0 ) ) {
V_41 = - V_120 ;
goto V_119;
}
F_74 ( & V_4 -> V_12 ) ;
}
V_4 -> V_19 ++ ;
F_75 ( & V_4 -> V_12 ) ;
F_10 ( L_17 ) ;
if ( ( ( V_109 == V_121 ) && ( V_4 -> V_102 != V_104 ) ) ||
( ( V_109 == V_122 ) && ( V_4 -> V_102 != V_103 ) ) ) {
F_10 ( L_18 , V_4 -> V_102 ) ;
V_41 = - V_113 ;
goto V_123;
}
V_41 = F_69 ( V_4 ) ;
if ( V_41 )
goto V_123;
V_71 = F_54 ( V_4 ) ;
if ( ! V_71 ) {
V_41 = - V_32 ;
goto V_123;
}
V_71 -> V_72 = V_4 -> V_6 ;
V_41 = F_71 ( V_4 ) ;
if ( V_41 < 0 )
goto V_124;
V_71 -> V_87 = V_41 ;
V_76 -> V_77 = V_71 ;
return 0 ;
V_124:
F_55 ( V_71 ) ;
V_123:
F_74 ( & V_4 -> V_12 ) ;
V_4 -> V_19 -- ;
F_75 ( & V_4 -> V_12 ) ;
V_119:
F_22 ( V_4 ) ;
V_44:
return V_41 ;
}
static int F_77 ( struct V_108 * V_108 , struct V_76 * V_76 )
{
struct V_70 * V_71 = V_76 -> V_77 ;
F_10 ( L_19 ) ;
F_74 ( & V_71 -> V_4 -> V_12 ) ;
V_71 -> V_4 -> V_19 -- ;
F_75 ( & V_71 -> V_4 -> V_12 ) ;
F_78 ( & V_71 -> V_4 -> V_11 ) ;
F_22 ( V_71 -> V_4 ) ;
F_55 ( V_71 ) ;
return 0 ;
}
static T_5 F_79 ( struct V_76 * V_76 , T_5 V_125 , int V_126 )
{
T_5 V_127 ;
if ( ( V_76 -> V_110 & V_111 ) != V_121 )
return - V_128 ;
if ( V_125 % V_88 )
return - V_128 ;
switch ( V_126 ) {
case 0 :
V_127 = V_125 ;
break;
case 1 :
V_127 = V_76 -> V_129 + V_125 ;
break;
default:
return - V_78 ;
}
V_76 -> V_129 = V_127 ;
return V_127 ;
}
static int F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_41 ;
F_10 ( L_20 , V_3 ) ;
F_81 ( & V_130 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_41 = - V_32 ;
goto V_123;
}
V_41 = F_49 ( & V_3 -> V_14 ) ;
if ( V_41 ) {
V_41 = - V_32 ;
goto V_131;
}
V_3 -> V_132 = F_40 ;
V_4 -> V_102 = F_53 ( V_4 ) ;
if ( V_4 -> V_102 < 0 ) {
V_41 = V_4 -> V_102 ;
goto V_133;
}
if ( ( V_4 -> V_102 != V_104 ) && ( V_4 -> V_102 != V_103 ) ) {
V_41 = - V_68 ;
goto V_133;
}
F_35 ( F_17 ( V_3 ) ) ;
F_82 ( & V_3 -> V_14 , V_4 ) ;
F_37 ( F_17 ( V_3 ) ) ;
F_39 ( & V_130 ) ;
return 0 ;
V_133:
F_51 ( & V_3 -> V_14 ) ;
V_131:
F_22 ( V_4 ) ;
V_123:
F_39 ( & V_130 ) ;
return V_41 ;
}
static int F_83 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_134 , V_135 , V_41 ;
char V_136 [ 16 ] ;
F_10 ( L_21 , V_3 ) ;
F_81 ( & V_130 ) ;
V_4 = F_15 ( V_3 ) ;
if ( ! V_4 ) {
V_41 = - V_61 ;
goto V_123;
}
if ( V_4 -> V_137 ) {
V_41 = - V_21 ;
goto V_131;
}
V_134 = V_4 -> V_9 . V_16 ;
V_135 = F_84 ( V_138 ) ;
V_4 -> V_137 = F_85 () ;
if ( ! V_4 -> V_137 ) {
V_41 = - V_32 ;
goto V_131;
}
F_86 ( V_4 -> V_137 , & V_139 ) ;
V_4 -> V_137 -> V_14 = F_87 ( V_135 , V_134 ) ;
V_4 -> V_137 -> V_140 = V_139 . V_140 ;
V_41 = F_88 ( V_4 -> V_137 , V_4 -> V_137 -> V_14 , 1 ) ;
if ( V_41 )
goto V_141;
if ( V_4 -> V_3 -> V_7 . V_142 == V_143 ) {
if ( V_4 -> V_102 == V_104 )
sprintf ( V_136 , L_22 , F_26 ( & V_3 -> V_14 ) ) ;
if ( V_4 -> V_102 == V_103 )
sprintf ( V_136 , L_23 , F_26 ( & V_3 -> V_14 ) ) ;
} else if ( V_4 -> V_3 -> V_7 . V_142 == V_144 ) {
sprintf ( V_136 , L_24 , F_26 ( & V_3 -> V_14 ) ) ;
} else {
V_41 = - V_68 ;
goto V_141;
}
V_4 -> V_57 = F_89 ( V_145 , NULL , V_4 -> V_137 -> V_14 ,
NULL , L_25 , V_136 ) ;
if ( F_44 ( V_4 -> V_57 ) ) {
V_41 = F_45 ( V_4 -> V_57 ) ;
F_10 ( L_26 , V_41 ) ;
goto V_141;
}
F_22 ( V_4 ) ;
F_39 ( & V_130 ) ;
return 0 ;
V_141:
F_90 ( V_4 -> V_137 ) ;
V_4 -> V_137 = NULL ;
V_131:
F_22 ( V_4 ) ;
V_123:
F_39 ( & V_130 ) ;
return V_41 ;
}
static int F_91 ( struct V_2 * V_3 , int V_146 )
{
struct V_1 * V_4 ;
int V_41 ;
F_10 ( L_27 , V_3 ) ;
V_4 = F_15 ( V_3 ) ;
if ( ! V_4 )
return - V_61 ;
if ( ! V_4 -> V_137 ) {
V_41 = - V_21 ;
goto V_131;
}
if ( ! V_146 && ( F_92 ( & V_4 -> V_13 ) > 2 ) ) {
F_10 ( L_28 ) ;
V_41 = - V_21 ;
goto V_131;
}
F_93 ( V_145 , V_4 -> V_137 -> V_14 ) ;
F_90 ( V_4 -> V_137 ) ;
V_4 -> V_137 = NULL ;
V_41 = 0 ;
V_131:
F_22 ( V_4 ) ;
return V_41 ;
}
static int F_94 ( struct V_2 * V_3 )
{
int V_41 ;
F_81 ( & V_130 ) ;
V_41 = F_91 ( V_3 , 0 ) ;
F_39 ( & V_130 ) ;
return V_41 ;
}
static void F_95 ( struct V_2 * V_3 )
{
unsigned long V_15 ;
F_10 ( L_29 ) ;
F_81 ( & V_130 ) ;
if ( V_3 -> V_147 )
F_91 ( V_3 , 1 ) ;
F_51 ( & V_3 -> V_14 ) ;
F_16 ( F_17 ( V_3 ) , V_15 ) ;
F_22 ( F_18 ( & V_3 -> V_14 ) ) ;
F_82 ( & V_3 -> V_14 , NULL ) ;
F_19 ( F_17 ( V_3 ) , V_15 ) ;
F_39 ( & V_130 ) ;
}
static int T_6 F_96 ( void )
{
int V_41 ;
T_7 V_14 ;
if ( ! V_148 ) {
F_25 ( L_30 ,
V_20 ) ;
return - V_61 ;
}
V_149 = F_97 ( L_31 , 4 , 1 , 4 * sizeof( long ) ) ;
if ( ! V_149 )
return - V_32 ;
V_41 = F_98 ( V_149 , & V_150 ) ;
if ( V_41 )
goto V_151;
F_99 ( V_149 , 6 ) ;
V_145 = F_100 ( V_152 , L_31 ) ;
if ( F_44 ( V_145 ) ) {
V_41 = F_45 ( V_145 ) ;
goto V_151;
}
V_41 = F_101 ( & V_18 ) ;
if ( V_41 )
goto V_153;
V_41 = F_102 ( & V_14 , 0 , V_154 , L_31 ) ;
if ( V_41 ) {
F_25 ( L_32
L_33 , V_41 ) ;
goto V_155;
}
V_138 = F_87 ( F_84 ( V_14 ) , 0 ) ;
F_103 ( L_34 , V_20 ) ;
return 0 ;
V_155:
F_104 ( & V_18 ) ;
V_153:
F_105 ( V_145 ) ;
V_151:
F_106 ( V_149 ) ;
return V_41 ;
}
static void T_8 F_107 ( void )
{
F_108 ( V_138 , V_154 ) ;
F_104 ( & V_18 ) ;
F_105 ( V_145 ) ;
F_106 ( V_149 ) ;
F_103 ( L_35 , V_20 ) ;
}
