void F_1 ( char * V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ )
if ( V_1 [ V_3 ] == '\0' )
V_1 [ V_3 ] = ';' ;
}
static int F_2 ( char * V_1 )
{
int V_3 = 0 ;
while ( V_1 [ V_3 ] != '\0' ) {
if ( V_1 [ V_3 ] == ';' )
return V_3 ;
V_3 ++ ;
}
return - 1 ;
}
int F_3 (
const char * V_4 ,
const char * V_5 ,
unsigned int V_6 ,
char * V_7 ,
unsigned char * type )
{
char * V_8 ;
int V_2 ;
if ( ! V_4 || ! V_5 || ! V_7 || ! type )
return - 1 ;
V_8 = strstr ( V_4 , V_5 ) ;
if ( ! V_8 )
return - 1 ;
V_8 = strstr ( V_8 , L_1 ) ;
if ( ! V_8 )
return - 1 ;
V_8 += 1 ;
if ( * V_8 == '0' && ( * ( V_8 + 1 ) == 'x' || * ( V_8 + 1 ) == 'X' ) ) {
V_8 += 2 ;
* type = V_9 ;
} else
* type = V_10 ;
V_2 = F_2 ( V_8 ) ;
if ( V_2 < 0 )
return - 1 ;
if ( V_2 > V_6 ) {
F_4 ( L_2
L_3 , V_2 , V_6 ) ;
return - 1 ;
}
memcpy ( V_7 , V_8 , V_2 ) ;
V_7 [ V_2 ] = '\0' ;
return 0 ;
}
static T_1 F_5 (
struct V_11 * V_12 ,
char * V_4 ,
char * V_7 ,
int V_13 ,
int * V_14 ,
unsigned char * V_15 )
{
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
if ( ! V_17 -> V_26 -> V_27 ) {
V_25 = V_12 -> V_17 -> V_28 -> V_24 ;
if ( ! V_25 ) {
F_4 ( L_4
L_5 ) ;
return - 1 ;
}
V_21 = F_6 ( V_25 , struct V_20 ,
V_24 ) ;
if ( ! V_21 ) {
F_4 ( L_6
L_5 ) ;
return - 1 ;
}
if ( V_25 -> V_29 ) {
V_23 = F_6 ( V_25 -> V_30 ,
struct V_22 , V_31 ) ;
V_19 = & V_23 -> V_32 ;
} else {
V_21 = F_6 ( V_25 , struct V_20 ,
V_24 ) ;
V_19 = F_7 ( V_21 ) ;
}
} else {
V_19 = & V_33 -> V_34 . V_35 ;
}
if ( strstr ( L_7 , V_15 ) )
strcpy ( V_12 -> V_17 -> V_36 , L_7 ) ;
else
strcpy ( V_12 -> V_17 -> V_36 , V_37 ) ;
if ( strstr ( L_8 , V_15 ) )
return 1 ;
#ifdef F_8
else if ( strstr ( L_9 , V_15 ) )
return F_9 ( V_12 , V_19 , V_4 , V_7 ,
& V_13 , V_14 ) ;
#endif
else if ( strstr ( L_7 , V_15 ) )
return F_10 ( V_12 , V_19 , V_4 , V_7 ,
& V_13 , V_14 ) ;
else if ( strstr ( L_10 , V_15 ) )
return 2 ;
else if ( strstr ( L_11 , V_15 ) )
return 2 ;
else if ( strstr ( L_12 , V_15 ) )
return 2 ;
else
return 2 ;
}
static void F_11 ( struct V_11 * V_12 )
{
F_12 ( V_12 -> V_38 ) ;
}
int F_13 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
int V_41 , V_42 ;
T_1 V_43 ;
struct V_44 * V_45 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_43 = F_14 ( V_45 -> V_47 ) ;
switch ( V_45 -> V_48 & V_49 ) {
case V_50 :
break;
default:
F_4 ( L_13 ,
V_45 -> V_48 & V_49 ) ;
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( ( V_45 -> V_53 & V_54 ) &&
( V_45 -> V_53 & V_55 ) ) {
F_4 ( L_14
L_15 ) ;
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
V_41 = F_16 ( V_45 -> V_53 ) ;
V_42 = F_17 ( V_45 -> V_53 ) ;
if ( V_41 != V_40 -> V_56 ) {
F_4 ( L_16
L_17 , V_40 -> V_56 ,
V_41 ) ;
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( ( V_42 == 2 ) || ( V_41 >= 2 ) ||
( ( V_45 -> V_53 & V_55 ) &&
( V_42 <= V_41 ) ) ) {
F_4 ( L_18
L_19 , V_41 ,
V_42 , ( V_45 -> V_53 & V_55 ) ) ;
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( ( V_45 -> V_57 != V_40 -> V_58 ) ||
( V_45 -> V_59 != V_40 -> V_60 ) ) {
F_4 ( L_20
L_21 ,
V_45 -> V_57 , V_45 -> V_59 ) ;
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( memcmp ( V_45 -> V_61 , V_40 -> V_61 , 6 ) != 0 ) {
F_4 ( L_22
L_23 ) ;
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( V_45 -> V_62 != V_40 -> V_63 ) {
F_4 ( L_24
L_25 , V_45 -> V_62 ) ;
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( V_43 > V_64 ) {
F_4 ( L_26
L_27 ,
V_64 ) ;
return - 1 ;
}
return 0 ;
}
static int F_18 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
struct V_65 * V_66 = NULL ;
struct V_24 * V_25 ;
V_40 -> V_67 = 0 ;
F_19 (param, &conn->param_list->param_list, p_list) {
if ( ! strncmp ( V_66 -> V_68 , V_69 , 11 ) ) {
if ( ! F_20 ( V_66 ) ) {
F_4 ( L_28
L_29 ) ;
F_15 ( V_12 , V_51 ,
V_70 ) ;
return - 1 ;
}
if ( ! strncmp ( V_66 -> V_71 , V_72 , 9 ) )
return 0 ;
}
if ( ! strncmp ( V_66 -> V_68 , V_73 , 13 ) ) {
if ( ! F_20 ( V_66 ) ) {
if ( ! V_40 -> V_74 )
continue;
F_4 ( L_30
L_29 ) ;
F_15 ( V_12 , V_51 ,
V_70 ) ;
return - 1 ;
}
if ( ! V_40 -> V_74 ) {
V_25 = V_12 -> V_17 -> V_28 -> V_24 ;
if ( ! V_25 ) {
F_4 ( L_31
L_32 ) ;
F_15 ( V_12 ,
V_51 ,
V_75 ) ;
return - 1 ;
}
if ( strcmp ( V_66 -> V_71 ,
V_25 -> V_76 ) ) {
F_4 ( L_33
L_34
L_35 ,
V_66 -> V_71 ) ;
F_15 ( V_12 ,
V_51 ,
V_75 ) ;
return - 1 ;
}
}
}
}
return 0 ;
}
static int F_21 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
T_1 V_77 = 0 ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_78 * V_79 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
V_79 -> V_48 = V_81 ;
F_22 ( V_79 -> V_47 , V_40 -> V_82 ) ;
memcpy ( V_79 -> V_61 , V_40 -> V_61 , 6 ) ;
V_79 -> V_83 = F_23 ( V_40 -> V_83 ) ;
V_79 -> V_62 = V_40 -> V_63 ;
V_79 -> V_84 = F_24 ( V_12 -> V_85 ++ ) ;
V_79 -> V_86 = F_24 ( V_12 -> V_17 -> V_87 ) ;
V_79 -> V_88 = F_24 ( V_12 -> V_17 -> V_89 ) ;
F_25 ( L_36
L_37
L_38 , V_79 -> V_53 , ( V_90 T_1 ) V_79 -> V_62 ,
F_26 ( V_79 -> V_86 ) , F_26 ( V_79 -> V_88 ) ,
F_26 ( V_79 -> V_84 ) , V_40 -> V_82 ) ;
V_77 = ( ( - V_40 -> V_82 ) & 3 ) ;
if ( V_12 -> V_91 -> V_92 ( V_12 , V_40 ,
V_40 -> V_82 + V_77 ) < 0 )
return - 1 ;
V_40 -> V_82 = 0 ;
F_27 ( & V_17 -> V_93 ) ;
V_79 -> V_86 = F_24 ( V_17 -> V_87 ) ;
V_79 -> V_88 = F_24 ( V_17 -> V_89 ) ;
F_28 ( & V_17 -> V_93 ) ;
return 0 ;
}
static int F_29 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
if ( F_21 ( V_12 , V_40 ) < 0 )
return - 1 ;
if ( V_12 -> V_91 -> V_94 ( V_12 , V_40 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_30 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
if ( V_40 -> V_95 )
return 0 ;
V_40 -> V_95 = 1 ;
if ( ! V_40 -> V_83 )
return F_31 ( V_12 ) ;
else
return F_32 ( V_12 , V_40 -> V_96 ,
V_40 -> V_97 ) ;
}
static int F_33 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
int V_98 ;
T_1 V_43 ;
struct V_65 * V_66 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
V_43 = F_14 ( V_45 -> V_47 ) ;
V_66 = F_34 ( V_99 , V_12 -> V_100 ) ;
if ( ! V_66 )
return - 1 ;
V_98 = F_5 (
V_12 ,
V_40 -> V_101 ,
V_40 -> V_102 ,
V_43 ,
& V_40 -> V_82 ,
V_66 -> V_71 ) ;
switch ( V_98 ) {
case 0 :
F_25 ( L_39
L_40 ) ;
break;
case 1 :
F_25 ( L_41
L_42 ) ;
V_40 -> V_103 = 1 ;
if ( ( V_45 -> V_53 & V_104 ) &&
( V_45 -> V_53 & V_55 ) ) {
V_79 -> V_53 |= ( V_104 |
V_55 ) ;
V_40 -> V_56 = 1 ;
}
return F_30 (
V_12 , V_40 ) ;
case 2 :
F_4 ( L_43
L_44 ) ;
F_15 ( V_12 , V_51 ,
V_105 ) ;
return - 1 ;
default:
F_4 ( L_45
L_46 , V_98 ) ;
F_15 ( V_12 , V_106 ,
V_107 ) ;
return - 1 ;
}
return 0 ;
}
static int F_35 (
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
int V_108 ;
T_1 V_43 ;
struct V_65 * V_66 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
V_43 = F_14 ( V_45 -> V_47 ) ;
V_66 = F_34 ( V_99 , V_12 -> V_100 ) ;
if ( ! V_66 )
return - 1 ;
V_108 = F_36 (
V_109 | V_110 ,
V_111 | V_112 ,
V_40 -> V_101 ,
V_43 ,
V_12 ) ;
if ( V_108 < 0 )
return - 1 ;
if ( V_108 > 0 ) {
if ( V_40 -> V_103 ) {
F_4 ( L_47
L_48
L_49 , V_66 -> V_71 ) ;
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
goto V_113;
}
if ( V_40 -> V_67 )
if ( F_18 ( V_12 , V_40 ) < 0 )
return - 1 ;
V_108 = F_37 (
V_109 | V_110 ,
V_114 ,
V_40 -> V_102 ,
& V_40 -> V_82 ,
V_12 -> V_100 ) ;
if ( V_108 < 0 )
return - 1 ;
if ( ! F_38 ( V_12 -> V_100 ) ) {
if ( F_39 ( F_40 ( V_12 ) ) -> V_115 &&
! strncmp ( V_66 -> V_71 , V_37 , 4 ) ) {
F_4 ( L_50
L_51
L_52 ) ;
F_15 ( V_12 , V_51 ,
V_105 ) ;
return - 1 ;
}
if ( F_39 ( F_40 ( V_12 ) ) -> V_115 &&
! V_40 -> V_103 )
return 0 ;
if ( strncmp ( V_66 -> V_71 , V_37 , 4 ) && ! V_40 -> V_103 )
return 0 ;
if ( ( V_45 -> V_53 & V_104 ) &&
( V_45 -> V_53 & V_55 ) ) {
V_79 -> V_53 |= V_104 |
V_55 ;
V_40 -> V_56 = 1 ;
}
}
return 0 ;
V_113:
return F_33 ( V_12 , V_40 ) ;
}
static int F_41 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
int V_108 ;
T_1 V_43 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
V_43 = F_14 ( V_45 -> V_47 ) ;
V_108 = F_36 (
V_116 | V_110 ,
V_111 | V_112 ,
V_40 -> V_101 ,
V_43 ,
V_12 ) ;
if ( V_108 < 0 ) {
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( V_40 -> V_67 )
if ( F_18 ( V_12 , V_40 ) < 0 )
return - 1 ;
if ( F_30 ( V_12 , V_40 ) < 0 )
return - 1 ;
V_108 = F_37 (
V_116 | V_110 ,
V_114 ,
V_40 -> V_102 ,
& V_40 -> V_82 ,
V_12 -> V_100 ) ;
if ( V_108 < 0 ) {
F_15 ( V_12 , V_51 ,
V_52 ) ;
return - 1 ;
}
if ( ! V_40 -> V_103 &&
F_39 ( F_40 ( V_12 ) ) -> V_115 ) {
F_4 ( L_53
L_54
L_55 ) ;
F_15 ( V_12 , V_51 ,
V_105 ) ;
return - 1 ;
}
if ( ! F_38 ( V_12 -> V_100 ) )
if ( ( V_45 -> V_53 & V_117 ) &&
( V_45 -> V_53 & V_55 ) )
V_79 -> V_53 |= V_117 |
V_55 ;
return 0 ;
}
static int F_42 ( struct V_11 * V_12 , struct V_39 * V_40 )
{
int V_118 = 0 ;
struct V_44 * V_45 ;
struct V_78 * V_79 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_79 = (struct V_78 * ) V_40 -> V_80 ;
while ( 1 ) {
if ( ++ V_118 > V_119 ) {
F_4 ( L_56 ) ;
F_15 ( V_12 , V_106 ,
V_107 ) ;
return - 1 ;
}
switch ( F_16 ( V_45 -> V_53 ) ) {
case 0 :
V_79 -> V_53 &= ~ V_120 ;
if ( F_35 ( V_12 , V_40 ) < 0 )
return - 1 ;
break;
case 1 :
V_79 -> V_53 |= V_121 ;
if ( F_41 ( V_12 , V_40 ) < 0 )
return - 1 ;
if ( V_79 -> V_53 & V_55 ) {
V_40 -> V_83 = V_12 -> V_17 -> V_83 ;
V_40 -> V_122 = 1 ;
if ( F_21 ( V_12 ,
V_40 ) < 0 )
return - 1 ;
return 0 ;
}
break;
default:
F_4 ( L_57
L_58 ,
F_16 ( V_45 -> V_53 ) ) ;
break;
}
if ( F_29 ( V_12 , V_40 ) < 0 )
return - 1 ;
if ( V_79 -> V_53 & V_55 ) {
V_79 -> V_53 &= ~ V_55 ;
V_79 -> V_53 &= ~ V_123 ;
}
}
return 0 ;
}
static void F_43 (
char * V_124 )
{
char * V_125 ;
T_1 V_126 = strlen ( V_124 ) , V_3 ;
for ( V_3 = 0 ; V_3 < V_126 ; V_3 ++ ) {
V_125 = & V_124 [ V_3 ] ;
if ( ! isupper ( * V_125 ) )
continue;
* V_125 = tolower ( * V_125 ) ;
}
}
int F_44 (
struct V_127 * V_128 ,
struct V_11 * V_12 ,
struct V_39 * V_40 )
{
char * V_129 = NULL , * V_130 = NULL , * V_131 = NULL ;
char * V_132 , * V_133 = NULL , * V_134 = NULL , * V_135 , * V_71 ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_136 * V_137 ;
struct V_44 * V_45 ;
T_1 V_43 ;
int V_138 = 0 , V_108 = 0 ;
V_45 = (struct V_44 * ) V_40 -> V_46 ;
V_43 = F_14 ( V_45 -> V_47 ) ;
V_132 = F_45 ( V_43 + 1 , V_139 ) ;
if ( ! V_132 ) {
F_4 ( L_59 ) ;
return - 1 ;
}
memcpy ( V_132 , V_40 -> V_101 , V_43 ) ;
V_132 [ V_43 ] = '\0' ;
V_133 = V_132 ;
V_134 = ( V_133 + V_43 ) ;
while ( V_133 < V_134 ) {
if ( F_46 ( V_133 , & V_135 , & V_71 ) < 0 ) {
V_108 = - 1 ;
goto V_140;
}
if ( ! strncmp ( V_135 , L_60 , 13 ) )
V_129 = V_71 ;
else if ( ! strncmp ( V_135 , L_61 , 11 ) )
V_130 = V_71 ;
else if ( ! strncmp ( V_135 , L_62 , 10 ) )
V_131 = V_71 ;
V_133 += strlen ( V_135 ) + strlen ( V_71 ) + 2 ;
}
if ( ! V_129 ) {
F_4 ( L_30
L_29 ) ;
F_15 ( V_12 , V_51 ,
V_70 ) ;
V_108 = - 1 ;
goto V_140;
}
F_43 ( V_129 ) ;
if ( ! V_130 ) {
if ( ! V_40 -> V_74 )
goto V_141;
F_4 ( L_28
L_29 ) ;
F_15 ( V_12 , V_51 ,
V_70 ) ;
V_108 = - 1 ;
goto V_140;
}
V_138 = strncmp ( V_130 , V_72 , 9 ) ;
if ( ! V_138 ) {
V_12 -> V_142 = V_33 -> V_143 ;
if ( ! V_40 -> V_74 )
goto V_141;
V_17 -> V_26 -> V_27 = 1 ;
if ( F_47 ( V_12 ) < 0 ) {
F_4 ( L_63 ) ;
V_108 = - 1 ;
goto V_140;
}
if ( F_48 ( V_128 , V_12 -> V_142 ) < 0 ) {
F_15 ( V_12 , V_106 ,
V_144 ) ;
V_108 = - 1 ;
goto V_140;
}
V_108 = 0 ;
goto V_140;
}
V_141:
if ( ! V_131 ) {
F_4 ( L_64
L_65
L_66 ) ;
F_15 ( V_12 , V_51 ,
V_70 ) ;
V_108 = - 1 ;
goto V_140;
}
V_137 = F_49 ( V_131 ) ;
if ( ! V_137 ) {
F_4 ( L_67
L_68 , V_131 ) ;
F_15 ( V_12 , V_106 ,
V_144 ) ;
V_108 = - 1 ;
goto V_140;
}
F_25 ( L_69 , V_137 -> V_137 ) ;
V_12 -> V_142 = F_50 ( V_137 , V_128 ) ;
if ( ! V_12 -> V_142 ) {
F_4 ( L_70
L_71 , V_137 -> V_137 ) ;
F_51 ( V_137 ) ;
F_15 ( V_12 , V_106 ,
V_144 ) ;
V_108 = - 1 ;
goto V_140;
}
F_25 ( L_72 , V_12 -> V_142 -> V_145 ) ;
if ( F_47 ( V_12 ) < 0 ) {
F_4 ( L_63 ) ;
V_108 = - 1 ;
goto V_140;
}
if ( F_48 ( V_128 , V_12 -> V_142 ) < 0 ) {
F_51 ( V_137 ) ;
F_15 ( V_12 , V_106 ,
V_144 ) ;
V_108 = - 1 ;
V_12 -> V_142 = NULL ;
goto V_140;
}
if ( ! V_40 -> V_74 ) {
V_108 = 0 ;
goto V_140;
}
V_17 -> V_26 -> V_27 = 0 ;
V_17 -> V_28 -> V_24 = F_52 (
& V_12 -> V_142 -> V_31 , V_129 ) ;
if ( ! V_17 -> V_28 -> V_24 ) {
F_4 ( L_73
L_74 ,
V_129 , V_12 -> V_142 -> V_145 ) ;
F_15 ( V_12 , V_51 ,
V_146 ) ;
V_108 = - 1 ;
goto V_140;
}
V_108 = 0 ;
V_140:
F_12 ( V_132 ) ;
return V_108 ;
}
int F_53 (
struct V_39 * V_40 ,
struct V_11 * V_12 )
{
int V_108 ;
V_108 = F_42 ( V_12 , V_40 ) ;
if ( V_108 != 0 )
F_11 ( V_12 ) ;
F_54 ( V_12 ) ;
return V_108 ;
}
void F_54 ( struct V_11 * V_12 )
{
struct V_39 * V_40 = V_12 -> V_147 ;
if ( ! V_40 )
return;
F_12 ( V_40 -> V_101 ) ;
F_12 ( V_40 -> V_102 ) ;
F_12 ( V_40 ) ;
V_12 -> V_147 = NULL ;
}
