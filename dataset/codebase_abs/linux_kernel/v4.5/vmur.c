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
F_10 ( L_10 ,
V_45 , V_46 -> V_47 . V_48 . V_49 , V_46 -> V_47 . V_48 . V_50 ,
V_46 -> V_47 . V_48 . V_37 ) ;
if ( ! V_45 ) {
F_10 ( L_11 ) ;
return;
}
V_4 = F_18 ( & V_3 -> V_14 ) ;
F_41 ( ! V_4 ) ;
if ( F_42 ( V_46 ) )
V_4 -> V_51 = F_43 ( V_46 ) ;
else if ( V_46 -> V_47 . V_48 . V_50 == ( V_52 | V_53 ) )
V_4 -> V_51 = 0 ;
else
V_4 -> V_51 = - V_54 ;
F_44 ( V_4 -> V_43 ) ;
}
static T_3 F_45 ( struct V_55 * V_14 ,
struct V_56 * V_57 , char * V_58 )
{
struct V_1 * V_4 ;
int V_41 ;
V_4 = F_15 ( F_46 ( V_14 ) ) ;
if ( ! V_4 )
return - V_59 ;
V_41 = sprintf ( V_58 , L_12 , V_4 -> V_6 ) ;
F_22 ( V_4 ) ;
return V_41 ;
}
static int F_47 ( struct V_55 * V_14 )
{
return F_48 ( V_14 , & V_60 ) ;
}
static void F_49 ( struct V_55 * V_14 )
{
F_50 ( V_14 , & V_60 ) ;
}
static int F_51 ( struct V_1 * V_4 )
{
static struct V_61 V_62 ;
int V_63 ;
V_62 . V_64 = V_4 -> V_9 . V_16 ;
V_62 . V_65 = sizeof( struct V_61 ) ;
V_63 = V_61 ( & V_62 ) ;
switch ( V_63 ) {
case 0 :
return - V_66 ;
case 2 :
return V_62 . V_67 ;
case 3 :
return - V_59 ;
default:
return - V_54 ;
}
}
static struct V_68 * F_52 ( struct V_1 * V_4 )
{
struct V_68 * V_69 ;
V_69 = F_2 ( sizeof( struct V_68 ) , V_5 ) ;
if ( ! V_69 )
return NULL ;
V_69 -> V_4 = V_4 ;
F_10 ( L_13 , V_4 , V_69 ,
V_69 -> V_70 ) ;
return V_69 ;
}
static void F_53 ( struct V_68 * V_69 )
{
F_10 ( L_14 , V_69 , V_69 -> V_4 ) ;
F_12 ( V_69 ) ;
}
static T_3 F_54 ( struct V_1 * V_4 , const char T_2 * V_71 ,
T_4 V_37 , T_4 V_6 , T_5 * V_72 )
{
struct V_22 * V_23 ;
int V_41 ;
V_23 = F_28 ( V_71 , V_37 / V_6 , V_6 ) ;
if ( F_42 ( V_23 ) )
return F_43 ( V_23 ) ;
V_41 = F_32 ( V_4 , V_23 ) ;
if ( V_41 )
goto V_73;
if ( V_4 -> V_51 ) {
V_41 = V_4 -> V_51 ;
goto V_73;
}
* V_72 += V_37 ;
V_41 = V_37 ;
V_73:
F_27 ( V_23 ) ;
return V_41 ;
}
static T_3 F_55 ( struct V_74 * V_74 , const char T_2 * V_71 ,
T_4 V_37 , T_5 * V_72 )
{
struct V_68 * V_69 = V_74 -> V_75 ;
F_10 ( L_15 , V_37 ) ;
if ( V_37 == 0 )
return 0 ;
if ( V_37 % V_69 -> V_70 )
return - V_76 ;
if ( V_37 > V_69 -> V_70 * V_77 )
V_37 = V_69 -> V_70 * V_77 ;
return F_54 ( V_69 -> V_4 , V_71 , V_37 , V_69 -> V_70 , V_72 ) ;
}
static int F_56 ( int V_16 , int V_78 )
{
int V_63 ;
V_63 = F_57 ( V_78 , V_16 , 0x28 ) ;
switch ( V_63 ) {
case 0 :
return 0 ;
case 2 :
return - V_79 ;
case 3 :
return - V_80 ;
default:
return - V_54 ;
}
}
static int F_58 ( int V_16 , char * V_58 )
{
int V_63 ;
V_63 = F_57 ( ( unsigned long ) V_58 , V_16 , 0x00 ) ;
switch ( V_63 ) {
case 0 :
return 0 ;
case 1 :
return - V_80 ;
case 2 :
return - V_79 ;
default:
return - V_54 ;
}
}
static T_3 F_59 ( struct V_74 * V_74 , char T_2 * V_27 , T_4 V_37 ,
T_5 * V_81 )
{
T_4 V_82 , V_83 , V_84 ;
char * V_58 ;
int V_41 ;
T_1 V_6 ;
struct V_1 * V_4 ;
V_4 = ( (struct V_68 * ) V_74 -> V_75 ) -> V_4 ;
V_6 = ( (struct V_68 * ) V_74 -> V_75 ) -> V_85 ;
V_41 = F_56 ( V_4 -> V_9 . V_16 , * V_81 / V_86 + 1 ) ;
if ( V_41 == - V_80 )
return 0 ;
if ( V_41 )
return V_41 ;
V_82 = F_60 ( ( T_4 ) V_86 , V_37 ) ;
V_58 = ( char * ) F_61 ( V_5 | V_31 ) ;
if ( ! V_58 )
return - V_32 ;
V_83 = 0 ;
V_84 = ( T_4 ) ( * V_81 % V_86 ) ;
do {
V_41 = F_58 ( V_4 -> V_9 . V_16 , V_58 ) ;
if ( V_41 == - V_80 ) {
break;
}
if ( V_41 )
goto V_87;
if ( V_6 && ( V_83 == 0 ) && ( * V_81 < V_86 ) )
* ( ( T_1 * ) & V_58 [ V_88 ] ) = V_6 ;
V_82 = F_60 ( V_37 - V_83 , V_86 - V_84 ) ;
if ( F_62 ( V_27 + V_83 , V_58 + V_84 , V_82 ) ) {
V_41 = - V_39 ;
goto V_87;
}
V_84 = 0 ;
V_83 += V_82 ;
} while ( V_83 != V_37 );
* V_81 += V_83 ;
V_41 = V_83 ;
V_87:
F_63 ( ( unsigned long ) V_58 ) ;
return V_41 ;
}
static T_3 F_64 ( struct V_74 * V_74 , char T_2 * V_27 , T_4 V_37 ,
T_5 * V_81 )
{
struct V_1 * V_4 ;
int V_41 ;
F_10 ( L_16 , V_37 , ( unsigned long ) * V_81 ) ;
if ( V_37 == 0 )
return 0 ;
V_4 = ( (struct V_68 * ) V_74 -> V_75 ) -> V_4 ;
V_41 = F_34 ( & V_4 -> V_10 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_59 ( V_74 , V_27 , V_37 , V_81 ) ;
F_39 ( & V_4 -> V_10 ) ;
return V_41 ;
}
static int F_65 ( struct V_89 * V_58 , int V_90 )
{
int V_63 ;
V_63 = F_57 ( ( unsigned long ) V_58 , V_90 , 0xfff ) ;
switch ( V_63 ) {
case 0 :
return 0 ;
default:
return - V_80 ;
}
}
static int F_66 ( struct V_1 * V_4 )
{
struct V_89 * V_91 ;
char * V_58 ;
int V_41 ;
V_91 = F_30 ( sizeof( * V_91 ) , V_5 | V_31 ) ;
if ( ! V_91 )
return - V_32 ;
V_41 = F_65 ( V_91 , 0 ) ;
if ( V_41 )
goto V_92;
if ( V_91 -> V_93 & ( V_94 | V_95 ) ) {
V_41 = - V_96 ;
goto V_92;
}
V_58 = ( char * ) F_61 ( V_5 | V_31 ) ;
if ( ! V_58 ) {
V_41 = - V_32 ;
goto V_92;
}
V_41 = F_58 ( V_4 -> V_9 . V_16 , V_58 ) ;
if ( ( V_41 != 0 ) && ( V_41 != - V_80 ) )
goto V_97;
V_41 = F_65 ( V_91 , 0 ) ;
if ( V_41 )
goto V_97;
if ( ! ( V_91 -> V_93 & V_98 ) ) {
V_41 = - V_99 ;
goto V_97;
}
V_41 = 0 ;
V_97:
F_63 ( ( unsigned long ) V_58 ) ;
V_92:
F_12 ( V_91 ) ;
return V_41 ;
}
static int F_67 ( struct V_1 * V_4 )
{
switch ( V_4 -> V_100 ) {
case V_101 :
return 0 ;
case V_102 :
return F_66 ( V_4 ) ;
default:
return - V_66 ;
}
}
static int F_68 ( struct V_1 * V_4 )
{
struct V_89 * V_91 ;
int V_41 ;
V_91 = F_30 ( sizeof( * V_91 ) , V_5 | V_31 ) ;
if ( ! V_91 )
return - V_32 ;
V_41 = F_65 ( V_91 , 0 ) ;
if ( V_41 )
goto V_103;
if ( V_91 -> V_93 & V_104 )
V_41 = 0 ;
else
V_41 = V_91 -> V_105 ;
V_103:
F_12 ( V_91 ) ;
return V_41 ;
}
static int F_69 ( struct V_1 * V_4 )
{
switch ( V_4 -> V_100 ) {
case V_101 :
return 0 ;
case V_102 :
return F_68 ( V_4 ) ;
default:
return - V_66 ;
}
}
static int F_70 ( struct V_106 * V_106 , struct V_74 * V_74 )
{
T_1 V_16 ;
struct V_1 * V_4 ;
struct V_68 * V_69 ;
unsigned short V_107 ;
int V_41 ;
V_107 = V_74 -> V_108 & V_109 ;
if ( V_107 == V_110 )
return - V_111 ;
V_16 = F_71 ( F_72 ( V_74 ) -> V_112 ) ;
V_4 = F_20 ( V_16 ) ;
if ( ! V_4 ) {
V_41 = - V_113 ;
goto V_44;
}
F_73 ( & V_4 -> V_12 ) ;
while ( V_4 -> V_19 ) {
F_74 ( & V_4 -> V_12 ) ;
if ( V_74 -> V_108 & V_114 ) {
V_41 = - V_21 ;
goto V_115;
}
if ( F_75 ( V_4 -> V_11 , V_4 -> V_19 == 0 ) ) {
V_41 = - V_116 ;
goto V_115;
}
F_73 ( & V_4 -> V_12 ) ;
}
V_4 -> V_19 ++ ;
F_74 ( & V_4 -> V_12 ) ;
F_10 ( L_17 ) ;
if ( ( ( V_107 == V_117 ) && ( V_4 -> V_100 != V_102 ) ) ||
( ( V_107 == V_118 ) && ( V_4 -> V_100 != V_101 ) ) ) {
F_10 ( L_18 , V_4 -> V_100 ) ;
V_41 = - V_111 ;
goto V_119;
}
V_41 = F_67 ( V_4 ) ;
if ( V_41 )
goto V_119;
V_69 = F_52 ( V_4 ) ;
if ( ! V_69 ) {
V_41 = - V_32 ;
goto V_119;
}
V_69 -> V_70 = V_4 -> V_6 ;
V_41 = F_69 ( V_4 ) ;
if ( V_41 < 0 )
goto V_120;
V_69 -> V_85 = V_41 ;
V_74 -> V_75 = V_69 ;
return 0 ;
V_120:
F_53 ( V_69 ) ;
V_119:
F_73 ( & V_4 -> V_12 ) ;
V_4 -> V_19 -- ;
F_74 ( & V_4 -> V_12 ) ;
V_115:
F_22 ( V_4 ) ;
V_44:
return V_41 ;
}
static int F_76 ( struct V_106 * V_106 , struct V_74 * V_74 )
{
struct V_68 * V_69 = V_74 -> V_75 ;
F_10 ( L_19 ) ;
F_73 ( & V_69 -> V_4 -> V_12 ) ;
V_69 -> V_4 -> V_19 -- ;
F_74 ( & V_69 -> V_4 -> V_12 ) ;
F_77 ( & V_69 -> V_4 -> V_11 ) ;
F_22 ( V_69 -> V_4 ) ;
F_53 ( V_69 ) ;
return 0 ;
}
static T_5 F_78 ( struct V_74 * V_74 , T_5 V_121 , int V_122 )
{
if ( ( V_74 -> V_108 & V_109 ) != V_117 )
return - V_123 ;
if ( V_121 % V_86 )
return - V_123 ;
return F_79 ( V_74 , V_121 , V_122 ) ;
}
static int F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_41 ;
F_10 ( L_20 , V_3 ) ;
F_81 ( & V_124 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_41 = - V_32 ;
goto V_119;
}
V_41 = F_47 ( & V_3 -> V_14 ) ;
if ( V_41 ) {
V_41 = - V_32 ;
goto V_125;
}
V_3 -> V_126 = F_40 ;
V_4 -> V_100 = F_51 ( V_4 ) ;
if ( V_4 -> V_100 < 0 ) {
V_41 = V_4 -> V_100 ;
goto V_127;
}
if ( ( V_4 -> V_100 != V_102 ) && ( V_4 -> V_100 != V_101 ) ) {
V_41 = - V_66 ;
goto V_127;
}
F_35 ( F_17 ( V_3 ) ) ;
F_82 ( & V_3 -> V_14 , V_4 ) ;
F_37 ( F_17 ( V_3 ) ) ;
F_39 ( & V_124 ) ;
return 0 ;
V_127:
F_49 ( & V_3 -> V_14 ) ;
V_125:
F_22 ( V_4 ) ;
V_119:
F_39 ( & V_124 ) ;
return V_41 ;
}
static int F_83 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_128 , V_129 , V_41 ;
char V_130 [ 16 ] ;
F_10 ( L_21 , V_3 ) ;
F_81 ( & V_124 ) ;
V_4 = F_15 ( V_3 ) ;
if ( ! V_4 ) {
V_41 = - V_59 ;
goto V_119;
}
if ( V_4 -> V_131 ) {
V_41 = - V_21 ;
goto V_125;
}
V_128 = V_4 -> V_9 . V_16 ;
V_129 = F_84 ( V_132 ) ;
V_4 -> V_131 = F_85 () ;
if ( ! V_4 -> V_131 ) {
V_41 = - V_32 ;
goto V_125;
}
V_4 -> V_131 -> V_133 = & V_134 ;
V_4 -> V_131 -> V_14 = F_86 ( V_129 , V_128 ) ;
V_4 -> V_131 -> V_135 = V_134 . V_135 ;
V_41 = F_87 ( V_4 -> V_131 , V_4 -> V_131 -> V_14 , 1 ) ;
if ( V_41 )
goto V_136;
if ( V_4 -> V_3 -> V_7 . V_137 == V_138 ) {
if ( V_4 -> V_100 == V_102 )
sprintf ( V_130 , L_22 , F_26 ( & V_3 -> V_14 ) ) ;
if ( V_4 -> V_100 == V_101 )
sprintf ( V_130 , L_23 , F_26 ( & V_3 -> V_14 ) ) ;
} else if ( V_4 -> V_3 -> V_7 . V_137 == V_139 ) {
sprintf ( V_130 , L_24 , F_26 ( & V_3 -> V_14 ) ) ;
} else {
V_41 = - V_66 ;
goto V_136;
}
V_4 -> V_55 = F_88 ( V_140 , & V_3 -> V_14 ,
V_4 -> V_131 -> V_14 , NULL , L_25 , V_130 ) ;
if ( F_42 ( V_4 -> V_55 ) ) {
V_41 = F_43 ( V_4 -> V_55 ) ;
F_10 ( L_26 , V_41 ) ;
goto V_136;
}
F_22 ( V_4 ) ;
F_39 ( & V_124 ) ;
return 0 ;
V_136:
F_89 ( V_4 -> V_131 ) ;
V_4 -> V_131 = NULL ;
V_125:
F_22 ( V_4 ) ;
V_119:
F_39 ( & V_124 ) ;
return V_41 ;
}
static int F_90 ( struct V_2 * V_3 , int V_141 )
{
struct V_1 * V_4 ;
int V_41 ;
F_10 ( L_27 , V_3 ) ;
V_4 = F_15 ( V_3 ) ;
if ( ! V_4 )
return - V_59 ;
if ( ! V_4 -> V_131 ) {
V_41 = - V_21 ;
goto V_125;
}
if ( ! V_141 && ( F_91 ( & V_4 -> V_13 ) > 2 ) ) {
F_10 ( L_28 ) ;
V_41 = - V_21 ;
goto V_125;
}
F_92 ( V_140 , V_4 -> V_131 -> V_14 ) ;
F_89 ( V_4 -> V_131 ) ;
V_4 -> V_131 = NULL ;
V_41 = 0 ;
V_125:
F_22 ( V_4 ) ;
return V_41 ;
}
static int F_93 ( struct V_2 * V_3 )
{
int V_41 ;
F_81 ( & V_124 ) ;
V_41 = F_90 ( V_3 , 0 ) ;
F_39 ( & V_124 ) ;
return V_41 ;
}
static void F_94 ( struct V_2 * V_3 )
{
unsigned long V_15 ;
F_10 ( L_29 ) ;
F_81 ( & V_124 ) ;
if ( V_3 -> V_142 )
F_90 ( V_3 , 1 ) ;
F_49 ( & V_3 -> V_14 ) ;
F_16 ( F_17 ( V_3 ) , V_15 ) ;
F_22 ( F_18 ( & V_3 -> V_14 ) ) ;
F_82 ( & V_3 -> V_14 , NULL ) ;
F_19 ( F_17 ( V_3 ) , V_15 ) ;
F_39 ( & V_124 ) ;
}
static int T_6 F_95 ( void )
{
int V_41 ;
T_7 V_14 ;
if ( ! V_143 ) {
F_25 ( L_30 ,
V_20 ) ;
return - V_59 ;
}
V_144 = F_96 ( L_31 , 4 , 1 , 4 * sizeof( long ) ) ;
if ( ! V_144 )
return - V_32 ;
V_41 = F_97 ( V_144 , & V_145 ) ;
if ( V_41 )
goto V_146;
F_98 ( V_144 , 6 ) ;
V_140 = F_99 ( V_147 , L_31 ) ;
if ( F_42 ( V_140 ) ) {
V_41 = F_43 ( V_140 ) ;
goto V_146;
}
V_41 = F_100 ( & V_18 ) ;
if ( V_41 )
goto V_148;
V_41 = F_101 ( & V_14 , 0 , V_149 , L_31 ) ;
if ( V_41 ) {
F_25 ( L_32
L_33 , V_41 ) ;
goto V_150;
}
V_132 = F_86 ( F_84 ( V_14 ) , 0 ) ;
F_102 ( L_34 , V_20 ) ;
return 0 ;
V_150:
F_103 ( & V_18 ) ;
V_148:
F_104 ( V_140 ) ;
V_146:
F_105 ( V_144 ) ;
return V_41 ;
}
static void T_8 F_106 ( void )
{
F_107 ( V_132 , V_149 ) ;
F_103 ( & V_18 ) ;
F_104 ( V_140 ) ;
F_105 ( V_144 ) ;
F_102 ( L_35 , V_20 ) ;
}
