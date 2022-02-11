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
if ( ! V_17 -> V_24 -> V_25 ) {
V_23 = V_12 -> V_17 -> V_26 -> V_22 ;
if ( ! V_23 ) {
F_4 ( L_4
L_5 ) ;
return - 1 ;
}
V_21 = F_6 ( V_23 , struct V_20 ,
V_22 ) ;
if ( ! V_21 ) {
F_4 ( L_6
L_5 ) ;
return - 1 ;
}
V_19 = F_7 ( V_21 ) ;
} else {
V_19 = & V_27 -> V_28 . V_29 ;
}
if ( strstr ( L_7 , V_15 ) )
strcpy ( V_12 -> V_17 -> V_30 , L_7 ) ;
else
strcpy ( V_12 -> V_17 -> V_30 , V_31 ) ;
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
F_12 ( V_12 -> V_32 ) ;
}
int F_13 (
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
int V_35 , V_36 ;
T_1 V_37 ;
struct V_38 * V_39 ;
V_39 = (struct V_38 * ) V_34 -> V_40 ;
V_37 = F_14 ( V_39 -> V_41 ) ;
switch ( V_39 -> V_42 & V_43 ) {
case V_44 :
break;
default:
F_4 ( L_13 ,
V_39 -> V_42 & V_43 ) ;
F_15 ( V_12 , V_45 ,
V_46 ) ;
return - 1 ;
}
if ( ( V_39 -> V_47 & V_48 ) &&
( V_39 -> V_47 & V_49 ) ) {
F_4 ( L_14
L_15 ) ;
F_15 ( V_12 , V_45 ,
V_46 ) ;
return - 1 ;
}
V_35 = F_16 ( V_39 -> V_47 ) ;
V_36 = F_17 ( V_39 -> V_47 ) ;
if ( V_35 != V_34 -> V_50 ) {
F_4 ( L_16
L_17 , V_34 -> V_50 ,
V_35 ) ;
F_15 ( V_12 , V_45 ,
V_46 ) ;
return - 1 ;
}
if ( ( V_36 == 2 ) || ( V_35 >= 2 ) ||
( ( V_39 -> V_47 & V_49 ) &&
( V_36 <= V_35 ) ) ) {
F_4 ( L_18
L_19 , V_35 ,
V_36 , ( V_39 -> V_47 & V_49 ) ) ;
F_15 ( V_12 , V_45 ,
V_46 ) ;
return - 1 ;
}
if ( ( V_39 -> V_51 != V_34 -> V_52 ) ||
( V_39 -> V_53 != V_34 -> V_54 ) ) {
F_4 ( L_20
L_21 ,
V_39 -> V_51 , V_39 -> V_53 ) ;
F_15 ( V_12 , V_45 ,
V_46 ) ;
return - 1 ;
}
if ( memcmp ( V_39 -> V_55 , V_34 -> V_55 , 6 ) != 0 ) {
F_4 ( L_22
L_23 ) ;
F_15 ( V_12 , V_45 ,
V_46 ) ;
return - 1 ;
}
if ( V_39 -> V_56 != V_34 -> V_57 ) {
F_4 ( L_24
L_25 , V_39 -> V_56 ) ;
F_15 ( V_12 , V_45 ,
V_46 ) ;
return - 1 ;
}
if ( V_37 > V_58 ) {
F_4 ( L_26
L_27 ,
V_58 ) ;
return - 1 ;
}
return 0 ;
}
static int F_18 (
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
struct V_59 * V_60 = NULL ;
struct V_22 * V_23 ;
V_34 -> V_61 = 0 ;
F_19 (param, &conn->param_list->param_list, p_list) {
if ( ! strncmp ( V_60 -> V_62 , V_63 , 11 ) ) {
if ( ! F_20 ( V_60 ) ) {
F_4 ( L_28
L_29 ) ;
F_15 ( V_12 , V_45 ,
V_64 ) ;
return - 1 ;
}
if ( ! strncmp ( V_60 -> V_65 , V_66 , 9 ) )
return 0 ;
}
if ( ! strncmp ( V_60 -> V_62 , V_67 , 13 ) ) {
if ( ! F_20 ( V_60 ) ) {
if ( ! V_34 -> V_68 )
continue;
F_4 ( L_30
L_29 ) ;
F_15 ( V_12 , V_45 ,
V_64 ) ;
return - 1 ;
}
if ( ! V_34 -> V_68 ) {
V_23 = V_12 -> V_17 -> V_26 -> V_22 ;
if ( ! V_23 ) {
F_4 ( L_31
L_32 ) ;
F_15 ( V_12 ,
V_45 ,
V_69 ) ;
return - 1 ;
}
if ( strcmp ( V_60 -> V_65 ,
V_23 -> V_70 ) ) {
F_4 ( L_33
L_34
L_35 ,
V_60 -> V_65 ) ;
F_15 ( V_12 ,
V_45 ,
V_69 ) ;
return - 1 ;
}
}
}
}
return 0 ;
}
static int F_21 ( struct V_11 * V_12 , struct V_33 * V_34 )
{
T_1 V_71 = 0 ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_72 * V_73 ;
V_73 = (struct V_72 * ) V_34 -> V_74 ;
V_73 -> V_42 = V_75 ;
F_22 ( V_73 -> V_41 , V_34 -> V_76 ) ;
memcpy ( V_73 -> V_55 , V_34 -> V_55 , 6 ) ;
V_73 -> V_77 = F_23 ( V_34 -> V_77 ) ;
V_73 -> V_56 = V_34 -> V_57 ;
V_73 -> V_78 = F_24 ( V_12 -> V_79 ++ ) ;
V_73 -> V_80 = F_24 ( V_12 -> V_17 -> V_81 ) ;
V_73 -> V_82 = F_24 ( V_12 -> V_17 -> V_83 ) ;
F_25 ( L_36
L_37
L_38 , V_73 -> V_47 , ( V_84 T_1 ) V_73 -> V_56 ,
F_26 ( V_73 -> V_80 ) , F_26 ( V_73 -> V_82 ) ,
F_26 ( V_73 -> V_78 ) , V_34 -> V_76 ) ;
V_71 = ( ( - V_34 -> V_76 ) & 3 ) ;
if ( V_12 -> V_85 -> V_86 ( V_12 , V_34 ,
V_34 -> V_76 + V_71 ) < 0 )
return - 1 ;
V_34 -> V_76 = 0 ;
F_27 ( & V_17 -> V_87 ) ;
V_73 -> V_80 = F_24 ( V_17 -> V_81 ) ;
V_73 -> V_82 = F_24 ( V_17 -> V_83 ) ;
F_28 ( & V_17 -> V_87 ) ;
return 0 ;
}
static int F_29 ( struct V_11 * V_12 , struct V_33 * V_34 )
{
if ( F_21 ( V_12 , V_34 ) < 0 )
return - 1 ;
if ( V_12 -> V_85 -> V_88 ( V_12 , V_34 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_30 (
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
if ( V_34 -> V_89 )
return 0 ;
V_34 -> V_89 = 1 ;
if ( ! V_34 -> V_77 )
return F_31 ( V_12 ) ;
else
return F_32 ( V_12 , V_34 -> V_90 ,
V_34 -> V_91 ) ;
}
static int F_33 (
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
int V_92 ;
T_1 V_37 ;
struct V_59 * V_60 ;
struct V_38 * V_39 ;
struct V_72 * V_73 ;
V_39 = (struct V_38 * ) V_34 -> V_40 ;
V_73 = (struct V_72 * ) V_34 -> V_74 ;
V_37 = F_14 ( V_39 -> V_41 ) ;
V_60 = F_34 ( V_93 , V_12 -> V_94 ) ;
if ( ! V_60 )
return - 1 ;
V_92 = F_5 (
V_12 ,
V_34 -> V_95 ,
V_34 -> V_96 ,
V_37 ,
& V_34 -> V_76 ,
V_60 -> V_65 ) ;
switch ( V_92 ) {
case 0 :
F_25 ( L_39
L_40 ) ;
break;
case 1 :
F_25 ( L_41
L_42 ) ;
V_34 -> V_97 = 1 ;
if ( ( V_39 -> V_47 & V_98 ) &&
( V_39 -> V_47 & V_49 ) ) {
V_73 -> V_47 |= ( V_98 |
V_49 ) ;
V_34 -> V_50 = 1 ;
}
return F_30 (
V_12 , V_34 ) ;
case 2 :
F_4 ( L_43
L_44 ) ;
F_15 ( V_12 , V_45 ,
V_99 ) ;
return - 1 ;
default:
F_4 ( L_45
L_46 , V_92 ) ;
F_15 ( V_12 , V_100 ,
V_101 ) ;
return - 1 ;
}
return 0 ;
}
static int F_35 (
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
int V_102 ;
T_1 V_37 ;
struct V_59 * V_60 ;
struct V_38 * V_39 ;
struct V_72 * V_73 ;
V_39 = (struct V_38 * ) V_34 -> V_40 ;
V_73 = (struct V_72 * ) V_34 -> V_74 ;
V_37 = F_14 ( V_39 -> V_41 ) ;
V_60 = F_34 ( V_93 , V_12 -> V_94 ) ;
if ( ! V_60 )
return - 1 ;
V_102 = F_36 (
V_103 | V_104 ,
V_105 | V_106 ,
V_34 -> V_95 ,
V_37 ,
V_12 ) ;
if ( V_102 < 0 )
return - 1 ;
if ( V_102 > 0 ) {
if ( V_34 -> V_97 ) {
F_4 ( L_47
L_48
L_49 , V_60 -> V_65 ) ;
F_15 ( V_12 , V_45 ,
V_46 ) ;
return - 1 ;
}
goto V_107;
}
if ( V_34 -> V_61 )
if ( F_18 ( V_12 , V_34 ) < 0 )
return - 1 ;
V_102 = F_37 (
V_103 | V_104 ,
V_108 ,
V_34 -> V_96 ,
& V_34 -> V_76 ,
V_12 -> V_94 ) ;
if ( V_102 < 0 )
return - 1 ;
if ( ! F_38 ( V_12 -> V_94 ) ) {
if ( F_39 ( F_40 ( V_12 ) ) -> V_109 &&
! strncmp ( V_60 -> V_65 , V_31 , 4 ) ) {
F_4 ( L_50
L_51
L_52 ) ;
F_15 ( V_12 , V_45 ,
V_99 ) ;
return - 1 ;
}
if ( F_39 ( F_40 ( V_12 ) ) -> V_109 &&
! V_34 -> V_97 )
return 0 ;
if ( strncmp ( V_60 -> V_65 , V_31 , 4 ) && ! V_34 -> V_97 )
return 0 ;
if ( ( V_39 -> V_47 & V_98 ) &&
( V_39 -> V_47 & V_49 ) ) {
V_73 -> V_47 |= V_98 |
V_49 ;
V_34 -> V_50 = 1 ;
}
}
return 0 ;
V_107:
return F_33 ( V_12 , V_34 ) ;
}
static int F_41 ( struct V_11 * V_12 , struct V_33 * V_34 )
{
int V_102 ;
T_1 V_37 ;
struct V_38 * V_39 ;
struct V_72 * V_73 ;
V_39 = (struct V_38 * ) V_34 -> V_40 ;
V_73 = (struct V_72 * ) V_34 -> V_74 ;
V_37 = F_14 ( V_39 -> V_41 ) ;
V_102 = F_36 (
V_110 | V_104 ,
V_105 | V_106 ,
V_34 -> V_95 ,
V_37 ,
V_12 ) ;
if ( V_102 < 0 ) {
F_15 ( V_12 , V_45 ,
V_46 ) ;
return - 1 ;
}
if ( V_34 -> V_61 )
if ( F_18 ( V_12 , V_34 ) < 0 )
return - 1 ;
if ( F_30 ( V_12 , V_34 ) < 0 )
return - 1 ;
V_102 = F_37 (
V_110 | V_104 ,
V_108 ,
V_34 -> V_96 ,
& V_34 -> V_76 ,
V_12 -> V_94 ) ;
if ( V_102 < 0 ) {
F_15 ( V_12 , V_45 ,
V_46 ) ;
return - 1 ;
}
if ( ! V_34 -> V_97 &&
F_39 ( F_40 ( V_12 ) ) -> V_109 ) {
F_4 ( L_53
L_54
L_55 ) ;
F_15 ( V_12 , V_45 ,
V_99 ) ;
return - 1 ;
}
if ( ! F_38 ( V_12 -> V_94 ) )
if ( ( V_39 -> V_47 & V_111 ) &&
( V_39 -> V_47 & V_49 ) )
V_73 -> V_47 |= V_111 |
V_49 ;
return 0 ;
}
static int F_42 ( struct V_11 * V_12 , struct V_33 * V_34 )
{
int V_112 = 0 ;
struct V_38 * V_39 ;
struct V_72 * V_73 ;
V_39 = (struct V_38 * ) V_34 -> V_40 ;
V_73 = (struct V_72 * ) V_34 -> V_74 ;
while ( 1 ) {
if ( ++ V_112 > V_113 ) {
F_4 ( L_56 ) ;
F_15 ( V_12 , V_100 ,
V_101 ) ;
return - 1 ;
}
switch ( F_16 ( V_39 -> V_47 ) ) {
case 0 :
V_73 -> V_47 &= ~ V_114 ;
if ( F_35 ( V_12 , V_34 ) < 0 )
return - 1 ;
break;
case 1 :
V_73 -> V_47 |= V_115 ;
if ( F_41 ( V_12 , V_34 ) < 0 )
return - 1 ;
if ( V_73 -> V_47 & V_49 ) {
V_34 -> V_77 = V_12 -> V_17 -> V_77 ;
V_34 -> V_116 = 1 ;
if ( F_21 ( V_12 ,
V_34 ) < 0 )
return - 1 ;
return 0 ;
}
break;
default:
F_4 ( L_57
L_58 ,
F_16 ( V_39 -> V_47 ) ) ;
break;
}
if ( F_29 ( V_12 , V_34 ) < 0 )
return - 1 ;
if ( V_73 -> V_47 & V_49 ) {
V_73 -> V_47 &= ~ V_49 ;
V_73 -> V_47 &= ~ V_117 ;
}
}
return 0 ;
}
static void F_43 (
char * V_118 )
{
char * V_119 ;
T_1 V_120 = strlen ( V_118 ) , V_3 ;
for ( V_3 = 0 ; V_3 < V_120 ; V_3 ++ ) {
V_119 = & V_118 [ V_3 ] ;
if ( ! isupper ( * V_119 ) )
continue;
* V_119 = tolower ( * V_119 ) ;
}
}
int F_44 (
struct V_121 * V_122 ,
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
char * V_123 = NULL , * V_124 = NULL , * V_125 = NULL ;
char * V_126 , * V_127 = NULL , * V_128 = NULL , * V_129 , * V_65 ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_130 * V_131 ;
struct V_38 * V_39 ;
T_1 V_37 ;
int V_132 = 0 , V_102 = 0 ;
V_39 = (struct V_38 * ) V_34 -> V_40 ;
V_37 = F_14 ( V_39 -> V_41 ) ;
V_126 = F_45 ( V_37 + 1 , V_133 ) ;
if ( ! V_126 ) {
F_4 ( L_59 ) ;
return - 1 ;
}
memcpy ( V_126 , V_34 -> V_95 , V_37 ) ;
V_126 [ V_37 ] = '\0' ;
V_127 = V_126 ;
V_128 = ( V_127 + V_37 ) ;
while ( V_127 < V_128 ) {
if ( F_46 ( V_127 , & V_129 , & V_65 ) < 0 ) {
V_102 = - 1 ;
goto V_134;
}
if ( ! strncmp ( V_129 , L_60 , 13 ) )
V_123 = V_65 ;
else if ( ! strncmp ( V_129 , L_61 , 11 ) )
V_124 = V_65 ;
else if ( ! strncmp ( V_129 , L_62 , 10 ) )
V_125 = V_65 ;
V_127 += strlen ( V_129 ) + strlen ( V_65 ) + 2 ;
}
if ( ! V_123 ) {
F_4 ( L_30
L_29 ) ;
F_15 ( V_12 , V_45 ,
V_64 ) ;
V_102 = - 1 ;
goto V_134;
}
F_43 ( V_123 ) ;
if ( ! V_124 ) {
if ( ! V_34 -> V_68 )
goto V_135;
F_4 ( L_28
L_29 ) ;
F_15 ( V_12 , V_45 ,
V_64 ) ;
V_102 = - 1 ;
goto V_134;
}
V_132 = strncmp ( V_124 , V_66 , 9 ) ;
if ( ! V_132 ) {
V_12 -> V_136 = V_27 -> V_137 ;
if ( ! V_34 -> V_68 )
goto V_135;
V_17 -> V_24 -> V_25 = 1 ;
if ( F_47 ( V_12 ) < 0 ) {
F_4 ( L_63 ) ;
V_102 = - 1 ;
goto V_134;
}
if ( F_48 ( V_122 , V_12 -> V_136 ) < 0 ) {
F_15 ( V_12 , V_100 ,
V_138 ) ;
V_102 = - 1 ;
goto V_134;
}
V_102 = 0 ;
goto V_134;
}
V_135:
if ( ! V_125 ) {
F_4 ( L_64
L_65
L_66 ) ;
F_15 ( V_12 , V_45 ,
V_64 ) ;
V_102 = - 1 ;
goto V_134;
}
V_131 = F_49 ( V_125 ) ;
if ( ! V_131 ) {
F_4 ( L_67
L_68 , V_125 ) ;
F_15 ( V_12 , V_100 ,
V_138 ) ;
V_102 = - 1 ;
goto V_134;
}
F_25 ( L_69 , V_131 -> V_131 ) ;
V_12 -> V_136 = F_50 ( V_131 , V_122 ) ;
if ( ! V_12 -> V_136 ) {
F_4 ( L_70
L_71 , V_131 -> V_131 ) ;
F_51 ( V_131 ) ;
F_15 ( V_12 , V_100 ,
V_138 ) ;
V_102 = - 1 ;
goto V_134;
}
F_25 ( L_72 , V_12 -> V_136 -> V_139 ) ;
if ( F_47 ( V_12 ) < 0 ) {
F_4 ( L_63 ) ;
V_102 = - 1 ;
goto V_134;
}
if ( F_48 ( V_122 , V_12 -> V_136 ) < 0 ) {
F_51 ( V_131 ) ;
F_15 ( V_12 , V_100 ,
V_138 ) ;
V_102 = - 1 ;
V_12 -> V_136 = NULL ;
goto V_134;
}
if ( ! V_34 -> V_68 ) {
V_102 = 0 ;
goto V_134;
}
V_17 -> V_24 -> V_25 = 0 ;
V_17 -> V_26 -> V_22 = F_52 (
& V_12 -> V_136 -> V_140 , V_123 ) ;
if ( ! V_17 -> V_26 -> V_22 ) {
F_4 ( L_73
L_74 ,
V_123 , V_12 -> V_136 -> V_139 ) ;
F_15 ( V_12 , V_45 ,
V_141 ) ;
V_102 = - 1 ;
goto V_134;
}
V_102 = 0 ;
V_134:
F_12 ( V_126 ) ;
return V_102 ;
}
int F_53 (
struct V_33 * V_34 ,
struct V_11 * V_12 )
{
int V_102 ;
V_102 = F_42 ( V_12 , V_34 ) ;
if ( V_102 != 0 )
F_11 ( V_12 ) ;
F_54 ( V_12 ) ;
return V_102 ;
}
void F_54 ( struct V_11 * V_12 )
{
struct V_33 * V_34 = V_12 -> V_142 ;
if ( ! V_34 )
return;
F_12 ( V_34 -> V_95 ) ;
F_12 ( V_34 -> V_96 ) ;
F_12 ( V_34 ) ;
V_12 -> V_142 = NULL ;
}
