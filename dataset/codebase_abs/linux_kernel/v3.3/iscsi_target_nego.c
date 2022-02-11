void F_1 ( char * V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ )
if ( V_1 [ V_3 ] == '\0' )
V_1 [ V_3 ] = ';' ;
}
int F_2 ( char * V_1 )
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
static int F_13 (
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
int V_35 , V_36 , V_37 , V_38 ;
T_1 V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
V_41 = (struct V_40 * ) V_34 -> V_44 ;
V_43 = (struct V_42 * ) V_34 -> V_45 ;
V_39 = F_14 ( V_41 -> V_46 ) ;
switch ( V_41 -> V_47 & V_48 ) {
case V_49 :
break;
default:
F_4 ( L_13 ,
V_41 -> V_47 & V_48 ) ;
F_15 ( V_12 , V_50 ,
V_51 ) ;
return - 1 ;
}
if ( ( V_41 -> V_52 & V_53 ) &&
( V_41 -> V_52 & V_54 ) ) {
F_4 ( L_14
L_15 ) ;
F_15 ( V_12 , V_50 ,
V_51 ) ;
return - 1 ;
}
V_35 = ( V_41 -> V_52 & V_55 ) >> 2 ;
V_37 = ( V_43 -> V_52 & V_55 ) >> 2 ;
V_36 = ( V_41 -> V_52 & V_56 ) ;
V_38 = ( V_43 -> V_52 & V_56 ) ;
if ( V_35 != V_34 -> V_57 ) {
F_4 ( L_16
L_17 , V_34 -> V_57 ,
V_35 ) ;
F_15 ( V_12 , V_50 ,
V_51 ) ;
return - 1 ;
}
if ( ( V_36 == 2 ) || ( V_35 >= 2 ) ||
( ( V_41 -> V_52 & V_54 ) &&
( V_36 <= V_35 ) ) ) {
F_4 ( L_18
L_19 , V_35 ,
V_36 , ( V_41 -> V_52 & V_54 ) ) ;
F_15 ( V_12 , V_50 ,
V_51 ) ;
return - 1 ;
}
if ( ( V_41 -> V_58 != V_34 -> V_59 ) ||
( V_41 -> V_60 != V_34 -> V_61 ) ) {
F_4 ( L_20
L_21 ,
V_41 -> V_58 , V_41 -> V_60 ) ;
F_15 ( V_12 , V_50 ,
V_51 ) ;
return - 1 ;
}
if ( memcmp ( V_41 -> V_62 , V_34 -> V_62 , 6 ) != 0 ) {
F_4 ( L_22
L_23 ) ;
F_15 ( V_12 , V_50 ,
V_51 ) ;
return - 1 ;
}
if ( V_41 -> V_63 != V_34 -> V_64 ) {
F_4 ( L_24
L_25 , V_41 -> V_63 ) ;
F_15 ( V_12 , V_50 ,
V_51 ) ;
return - 1 ;
}
if ( V_39 > V_65 ) {
F_4 ( L_26
L_27 ,
V_65 ) ;
return - 1 ;
}
return 0 ;
}
static int F_16 (
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
struct V_66 * V_67 = NULL ;
struct V_22 * V_23 ;
V_34 -> V_68 = 0 ;
F_17 (param, &conn->param_list->param_list, p_list) {
if ( ! strncmp ( V_67 -> V_69 , V_70 , 11 ) ) {
if ( ! F_18 ( V_67 ) ) {
F_4 ( L_28
L_29 ) ;
F_15 ( V_12 , V_50 ,
V_71 ) ;
return - 1 ;
}
if ( ! strncmp ( V_67 -> V_72 , V_73 , 9 ) )
return 0 ;
}
if ( ! strncmp ( V_67 -> V_69 , V_74 , 13 ) ) {
if ( ! F_18 ( V_67 ) ) {
if ( ! V_34 -> V_75 )
continue;
F_4 ( L_30
L_29 ) ;
F_15 ( V_12 , V_50 ,
V_71 ) ;
return - 1 ;
}
if ( ! V_34 -> V_75 ) {
V_23 = V_12 -> V_17 -> V_26 -> V_22 ;
if ( ! V_23 ) {
F_4 ( L_31
L_32 ) ;
F_15 ( V_12 ,
V_50 ,
V_76 ) ;
return - 1 ;
}
if ( strcmp ( V_67 -> V_72 ,
V_23 -> V_77 ) ) {
F_4 ( L_33
L_34
L_35 ,
V_67 -> V_72 ) ;
F_15 ( V_12 ,
V_50 ,
V_76 ) ;
return - 1 ;
}
}
}
}
return 0 ;
}
static int F_19 ( struct V_11 * V_12 , struct V_33 * V_34 )
{
T_1 V_78 = 0 ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_42 * V_43 ;
V_43 = (struct V_42 * ) V_34 -> V_45 ;
V_43 -> V_47 = V_79 ;
F_20 ( V_43 -> V_46 , V_34 -> V_80 ) ;
memcpy ( V_43 -> V_62 , V_34 -> V_62 , 6 ) ;
V_43 -> V_81 = F_21 ( V_34 -> V_81 ) ;
V_43 -> V_63 = F_22 ( V_34 -> V_64 ) ;
V_43 -> V_82 = F_22 ( V_12 -> V_83 ++ ) ;
V_43 -> V_84 = F_22 ( V_12 -> V_17 -> V_85 ) ;
V_43 -> V_86 = F_22 ( V_12 -> V_17 -> V_87 ) ;
F_23 ( L_36
L_37
L_38 , V_43 -> V_52 , F_24 ( V_43 -> V_63 ) ,
F_24 ( V_43 -> V_84 ) , F_24 ( V_43 -> V_86 ) ,
F_24 ( V_43 -> V_82 ) , V_34 -> V_80 ) ;
V_78 = ( ( - V_34 -> V_80 ) & 3 ) ;
if ( F_25 (
V_12 ,
V_34 -> V_45 ,
V_34 -> V_88 ,
V_34 -> V_80 + V_78 ) < 0 )
return - 1 ;
V_34 -> V_80 = 0 ;
V_43 -> V_81 = F_26 ( V_43 -> V_81 ) ;
V_43 -> V_63 = F_27 ( V_43 -> V_63 ) ;
V_43 -> V_82 = F_27 ( V_43 -> V_82 ) ;
F_28 ( & V_17 -> V_89 ) ;
V_43 -> V_84 = F_27 ( V_17 -> V_85 ) ;
V_43 -> V_86 = F_27 ( V_17 -> V_87 ) ;
F_29 ( & V_17 -> V_89 ) ;
return 0 ;
}
static int F_30 ( struct V_11 * V_12 , struct V_33 * V_34 )
{
T_1 V_78 = 0 , V_39 ;
struct V_40 * V_41 ;
if ( F_31 ( V_12 , V_34 -> V_44 , V_90 ) < 0 )
return - 1 ;
V_41 = (struct V_40 * ) V_34 -> V_44 ;
V_39 = F_14 ( V_41 -> V_46 ) ;
V_41 -> V_81 = F_26 ( V_41 -> V_81 ) ;
V_41 -> V_63 = F_27 ( V_41 -> V_63 ) ;
V_41 -> V_91 = F_26 ( V_41 -> V_91 ) ;
V_41 -> V_92 = F_27 ( V_41 -> V_92 ) ;
V_41 -> V_93 = F_27 ( V_41 -> V_93 ) ;
F_23 ( L_39
L_40 ,
V_41 -> V_52 , V_41 -> V_63 , V_41 -> V_92 ,
V_41 -> V_93 , V_41 -> V_91 , V_39 ) ;
if ( F_13 ( V_12 , V_34 ) < 0 )
return - 1 ;
V_78 = ( ( - V_39 ) & 3 ) ;
memset ( V_34 -> V_94 , 0 , V_65 ) ;
if ( F_31 (
V_12 ,
V_34 -> V_94 ,
V_39 + V_78 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_32 ( struct V_11 * V_12 , struct V_33 * V_34 )
{
if ( F_19 ( V_12 , V_34 ) < 0 )
return - 1 ;
if ( F_30 ( V_12 , V_34 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_33 (
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
T_1 V_78 = 0 , V_39 ;
struct V_40 * V_41 ;
V_41 = (struct V_40 * ) V_34 -> V_44 ;
V_39 = F_14 ( V_41 -> V_46 ) ;
F_23 ( L_39
L_41 ,
V_41 -> V_52 , V_41 -> V_63 , V_41 -> V_92 ,
V_41 -> V_93 , V_39 ) ;
if ( F_13 ( V_12 , V_34 ) < 0 )
return - 1 ;
V_78 = ( ( - V_39 ) & 3 ) ;
if ( F_31 (
V_12 ,
V_34 -> V_94 ,
V_39 + V_78 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_34 (
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
if ( V_34 -> V_95 )
return 0 ;
V_34 -> V_95 = 1 ;
if ( ! V_34 -> V_81 )
return F_35 ( V_12 ) ;
else
return F_36 ( V_12 , V_34 -> V_91 ,
V_34 -> V_96 ) ;
}
static int F_37 (
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
int V_97 ;
T_1 V_39 ;
struct V_66 * V_67 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
V_41 = (struct V_40 * ) V_34 -> V_44 ;
V_43 = (struct V_42 * ) V_34 -> V_45 ;
V_39 = F_14 ( V_41 -> V_46 ) ;
V_67 = F_38 ( V_98 , V_12 -> V_99 ) ;
if ( ! V_67 )
return - 1 ;
V_97 = F_5 (
V_12 ,
V_34 -> V_94 ,
V_34 -> V_88 ,
V_39 ,
& V_34 -> V_80 ,
V_67 -> V_72 ) ;
switch ( V_97 ) {
case 0 :
F_23 ( L_42
L_43 ) ;
break;
case 1 :
F_23 ( L_44
L_45 ) ;
V_34 -> V_100 = 1 ;
if ( ( V_41 -> V_52 & V_101 ) &&
( V_41 -> V_52 & V_54 ) ) {
V_43 -> V_52 |= ( V_101 |
V_54 ) ;
V_34 -> V_57 = 1 ;
}
return F_34 (
V_12 , V_34 ) ;
case 2 :
F_4 ( L_46
L_47 ) ;
F_15 ( V_12 , V_50 ,
V_102 ) ;
return - 1 ;
default:
F_4 ( L_48
L_49 , V_97 ) ;
F_15 ( V_12 , V_103 ,
V_104 ) ;
return - 1 ;
}
return 0 ;
}
static int F_39 (
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
int V_105 ;
T_1 V_39 ;
struct V_66 * V_67 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
V_41 = (struct V_40 * ) V_34 -> V_44 ;
V_43 = (struct V_42 * ) V_34 -> V_45 ;
V_39 = F_14 ( V_41 -> V_46 ) ;
V_67 = F_38 ( V_98 , V_12 -> V_99 ) ;
if ( ! V_67 )
return - 1 ;
V_105 = F_40 (
V_106 | V_107 ,
V_108 | V_109 ,
V_34 -> V_94 ,
V_39 ,
V_12 -> V_99 ) ;
if ( V_105 < 0 )
return - 1 ;
if ( V_105 > 0 ) {
if ( V_34 -> V_100 ) {
F_4 ( L_50
L_51
L_52 , V_67 -> V_72 ) ;
F_15 ( V_12 , V_50 ,
V_51 ) ;
return - 1 ;
}
goto V_110;
}
if ( V_34 -> V_68 )
if ( F_16 ( V_12 , V_34 ) < 0 )
return - 1 ;
V_105 = F_41 (
V_106 | V_107 ,
V_111 ,
V_34 -> V_88 ,
& V_34 -> V_80 ,
V_12 -> V_99 ) ;
if ( V_105 < 0 )
return - 1 ;
if ( ! F_42 ( V_12 -> V_99 ) ) {
if ( F_43 ( F_44 ( V_12 ) ) -> V_112 &&
! strncmp ( V_67 -> V_72 , V_31 , 4 ) ) {
F_4 ( L_53
L_54
L_55 ) ;
F_15 ( V_12 , V_50 ,
V_102 ) ;
return - 1 ;
}
if ( F_43 ( F_44 ( V_12 ) ) -> V_112 &&
! V_34 -> V_100 )
return 0 ;
if ( strncmp ( V_67 -> V_72 , V_31 , 4 ) && ! V_34 -> V_100 )
return 0 ;
if ( ( V_41 -> V_52 & V_101 ) &&
( V_41 -> V_52 & V_54 ) ) {
V_43 -> V_52 |= V_101 |
V_54 ;
V_34 -> V_57 = 1 ;
}
}
return 0 ;
V_110:
return F_37 ( V_12 , V_34 ) ;
}
static int F_45 ( struct V_11 * V_12 , struct V_33 * V_34 )
{
int V_105 ;
T_1 V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
V_41 = (struct V_40 * ) V_34 -> V_44 ;
V_43 = (struct V_42 * ) V_34 -> V_45 ;
V_39 = F_14 ( V_41 -> V_46 ) ;
V_105 = F_40 (
V_113 | V_107 ,
V_108 | V_109 ,
V_34 -> V_94 ,
V_39 ,
V_12 -> V_99 ) ;
if ( V_105 < 0 )
return - 1 ;
if ( V_34 -> V_68 )
if ( F_16 ( V_12 , V_34 ) < 0 )
return - 1 ;
if ( F_34 ( V_12 , V_34 ) < 0 )
return - 1 ;
V_105 = F_41 (
V_113 | V_107 ,
V_111 ,
V_34 -> V_88 ,
& V_34 -> V_80 ,
V_12 -> V_99 ) ;
if ( V_105 < 0 )
return - 1 ;
if ( ! V_34 -> V_100 &&
F_43 ( F_44 ( V_12 ) ) -> V_112 ) {
F_4 ( L_56
L_57
L_58 ) ;
F_15 ( V_12 , V_50 ,
V_102 ) ;
return - 1 ;
}
if ( ! F_42 ( V_12 -> V_99 ) )
if ( ( V_41 -> V_52 & V_114 ) &&
( V_41 -> V_52 & V_54 ) )
V_43 -> V_52 |= V_114 |
V_54 ;
return 0 ;
}
static int F_46 ( struct V_11 * V_12 , struct V_33 * V_34 )
{
int V_115 = 0 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
V_41 = (struct V_40 * ) V_34 -> V_44 ;
V_43 = (struct V_42 * ) V_34 -> V_45 ;
while ( 1 ) {
if ( ++ V_115 > V_116 ) {
F_4 ( L_59 ) ;
F_15 ( V_12 , V_103 ,
V_104 ) ;
return - 1 ;
}
switch ( ( V_41 -> V_52 & V_55 ) >> 2 ) {
case 0 :
V_43 -> V_52 |= ( 0 & V_55 ) ;
if ( F_39 ( V_12 , V_34 ) < 0 )
return - 1 ;
break;
case 1 :
V_43 -> V_52 |= V_117 ;
if ( F_45 ( V_12 , V_34 ) < 0 )
return - 1 ;
if ( V_43 -> V_52 & V_54 ) {
V_34 -> V_81 = V_12 -> V_17 -> V_81 ;
if ( F_19 ( V_12 ,
V_34 ) < 0 )
return - 1 ;
return 0 ;
}
break;
default:
F_4 ( L_60
L_61 ,
( V_41 -> V_52 & V_55 )
>> 2 ) ;
break;
}
if ( F_32 ( V_12 , V_34 ) < 0 )
return - 1 ;
if ( V_43 -> V_52 & V_54 ) {
V_43 -> V_52 &= ~ V_54 ;
V_43 -> V_52 &= ~ V_56 ;
}
}
return 0 ;
}
static void F_47 (
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
static int F_48 (
struct V_121 * V_122 ,
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
char * V_123 = NULL , * V_124 = NULL , * V_125 = NULL ;
char * V_126 , * V_127 = NULL , * V_128 = NULL , * V_129 , * V_72 ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_130 * V_131 ;
struct V_40 * V_41 ;
struct V_132 * V_43 ;
T_1 V_39 ;
int V_133 = 0 , V_105 = 0 ;
V_41 = (struct V_40 * ) V_34 -> V_44 ;
V_43 = (struct V_132 * ) V_34 -> V_45 ;
V_39 = F_14 ( V_41 -> V_46 ) ;
V_34 -> V_68 = 1 ;
V_34 -> V_75 = ( ! V_41 -> V_81 ) ? 1 : 0 ;
V_34 -> V_57 =
( V_41 -> V_52 & V_55 ) >> 2 ;
V_34 -> V_61 = V_41 -> V_60 ;
V_34 -> V_59 = V_41 -> V_58 ;
memcpy ( V_34 -> V_62 , V_41 -> V_62 , 6 ) ;
V_34 -> V_134 = V_41 -> V_92 ;
V_34 -> V_64 = V_41 -> V_63 ;
V_34 -> V_96 = V_41 -> V_93 ;
V_34 -> V_91 = V_41 -> V_91 ;
V_34 -> V_81 = V_41 -> V_81 ;
if ( F_33 ( V_12 , V_34 ) < 0 )
return - 1 ;
V_126 = F_49 ( V_39 + 1 , V_135 ) ;
if ( ! V_126 ) {
F_4 ( L_62 ) ;
return - 1 ;
}
memcpy ( V_126 , V_34 -> V_94 , V_39 ) ;
V_126 [ V_39 ] = '\0' ;
V_127 = V_126 ;
V_128 = ( V_127 + V_39 ) ;
while ( V_127 < V_128 ) {
if ( F_50 ( V_127 , & V_129 , & V_72 ) < 0 ) {
V_105 = - 1 ;
goto V_136;
}
if ( ! strncmp ( V_129 , L_63 , 13 ) )
V_123 = V_72 ;
else if ( ! strncmp ( V_129 , L_64 , 11 ) )
V_124 = V_72 ;
else if ( ! strncmp ( V_129 , L_65 , 10 ) )
V_125 = V_72 ;
V_127 += strlen ( V_129 ) + strlen ( V_72 ) + 2 ;
}
if ( ! V_123 ) {
F_4 ( L_30
L_29 ) ;
F_15 ( V_12 , V_50 ,
V_71 ) ;
V_105 = - 1 ;
goto V_136;
}
F_47 ( V_123 ) ;
if ( ! V_124 ) {
if ( ! V_34 -> V_75 )
goto V_137;
F_4 ( L_28
L_29 ) ;
F_15 ( V_12 , V_50 ,
V_71 ) ;
V_105 = - 1 ;
goto V_136;
}
V_133 = strncmp ( V_124 , V_73 , 9 ) ;
if ( ! V_133 ) {
V_12 -> V_138 = V_27 -> V_139 ;
if ( ! V_34 -> V_75 )
goto V_137;
V_17 -> V_24 -> V_25 = 1 ;
if ( F_51 ( V_12 ) < 0 ) {
F_4 ( L_66 ) ;
V_105 = - 1 ;
goto V_136;
}
if ( F_52 ( V_122 , V_12 -> V_138 ) < 0 ) {
F_15 ( V_12 , V_103 ,
V_140 ) ;
V_105 = - 1 ;
goto V_136;
}
V_105 = 0 ;
goto V_136;
}
V_137:
if ( ! V_125 ) {
F_4 ( L_67
L_68
L_69 ) ;
F_15 ( V_12 , V_50 ,
V_71 ) ;
V_105 = - 1 ;
goto V_136;
}
V_131 = F_53 ( V_125 ) ;
if ( ! V_131 ) {
F_4 ( L_70
L_71 , V_125 ) ;
F_15 ( V_12 , V_103 ,
V_140 ) ;
V_105 = - 1 ;
goto V_136;
}
F_23 ( L_72 , V_131 -> V_131 ) ;
V_12 -> V_138 = F_54 ( V_131 , V_122 ) ;
if ( ! V_12 -> V_138 ) {
F_4 ( L_73
L_74 , V_131 -> V_131 ) ;
F_55 ( V_131 ) ;
F_15 ( V_12 , V_103 ,
V_140 ) ;
V_105 = - 1 ;
goto V_136;
}
F_23 ( L_75 , V_12 -> V_138 -> V_141 ) ;
if ( F_51 ( V_12 ) < 0 ) {
F_4 ( L_66 ) ;
V_105 = - 1 ;
goto V_136;
}
if ( F_52 ( V_122 , V_12 -> V_138 ) < 0 ) {
F_55 ( V_131 ) ;
F_15 ( V_12 , V_103 ,
V_140 ) ;
V_105 = - 1 ;
V_12 -> V_138 = NULL ;
goto V_136;
}
if ( ! V_34 -> V_75 ) {
V_105 = 0 ;
goto V_136;
}
V_17 -> V_24 -> V_25 = 0 ;
V_17 -> V_26 -> V_22 = F_56 (
& V_12 -> V_138 -> V_142 , V_123 ) ;
if ( ! V_17 -> V_26 -> V_22 ) {
F_4 ( L_76
L_77 ,
V_123 , V_12 -> V_138 -> V_141 ) ;
F_15 ( V_12 , V_50 ,
V_143 ) ;
V_105 = - 1 ;
goto V_136;
}
V_105 = 0 ;
V_136:
F_12 ( V_126 ) ;
return V_105 ;
}
struct V_33 * F_57 (
struct V_121 * V_122 ,
struct V_11 * V_12 ,
char * V_144 )
{
struct V_33 * V_34 ;
V_34 = F_49 ( sizeof( struct V_33 ) , V_135 ) ;
if ( ! V_34 ) {
F_4 ( L_78 ) ;
F_15 ( V_12 , V_103 ,
V_145 ) ;
return NULL ;
}
V_34 -> V_44 = F_58 ( V_144 , V_90 , V_135 ) ;
if ( ! V_34 -> V_44 ) {
F_4 ( L_79 ) ;
F_15 ( V_12 , V_103 ,
V_145 ) ;
goto V_136;
}
V_34 -> V_94 = F_49 ( V_65 , V_135 ) ;
if ( ! V_34 -> V_94 ) {
F_4 ( L_80 ) ;
F_15 ( V_12 , V_103 ,
V_145 ) ;
goto V_136;
}
if ( F_48 ( V_122 , V_12 , V_34 ) < 0 ) {
F_4 ( L_81 ) ;
goto V_136;
}
return V_34 ;
V_136:
F_12 ( V_34 -> V_44 ) ;
F_12 ( V_34 -> V_94 ) ;
F_12 ( V_34 ) ;
return NULL ;
}
int F_59 (
struct V_33 * V_34 ,
struct V_11 * V_12 )
{
int V_105 = - 1 ;
V_34 -> V_45 = F_49 ( V_90 , V_135 ) ;
if ( ! V_34 -> V_45 ) {
F_4 ( L_82
L_83 ) ;
F_15 ( V_12 , V_103 ,
V_145 ) ;
V_105 = - 1 ;
goto V_136;
}
V_34 -> V_88 = F_49 ( V_65 , V_135 ) ;
if ( ! V_34 -> V_88 ) {
F_4 ( L_82
L_84 ) ;
F_15 ( V_12 , V_103 ,
V_145 ) ;
V_105 = - 1 ;
goto V_136;
}
V_105 = F_46 ( V_12 , V_34 ) ;
V_136:
if ( V_105 != 0 )
F_11 ( V_12 ) ;
F_60 ( V_34 , V_12 ) ;
return V_105 ;
}
void F_60 (
struct V_33 * V_34 ,
struct V_11 * V_12 )
{
F_12 ( V_34 -> V_44 ) ;
F_12 ( V_34 -> V_45 ) ;
F_12 ( V_34 -> V_94 ) ;
F_12 ( V_34 -> V_88 ) ;
F_12 ( V_34 ) ;
}
