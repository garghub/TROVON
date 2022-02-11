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
V_35 = ( V_39 -> V_47 & V_50 ) >> 2 ;
V_36 = ( V_39 -> V_47 & V_51 ) ;
if ( V_35 != V_34 -> V_52 ) {
F_4 ( L_16
L_17 , V_34 -> V_52 ,
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
if ( ( V_39 -> V_53 != V_34 -> V_54 ) ||
( V_39 -> V_55 != V_34 -> V_56 ) ) {
F_4 ( L_20
L_21 ,
V_39 -> V_53 , V_39 -> V_55 ) ;
F_15 ( V_12 , V_45 ,
V_46 ) ;
return - 1 ;
}
if ( memcmp ( V_39 -> V_57 , V_34 -> V_57 , 6 ) != 0 ) {
F_4 ( L_22
L_23 ) ;
F_15 ( V_12 , V_45 ,
V_46 ) ;
return - 1 ;
}
if ( V_39 -> V_58 != V_34 -> V_59 ) {
F_4 ( L_24
L_25 , V_39 -> V_58 ) ;
F_15 ( V_12 , V_45 ,
V_46 ) ;
return - 1 ;
}
if ( V_37 > V_60 ) {
F_4 ( L_26
L_27 ,
V_60 ) ;
return - 1 ;
}
return 0 ;
}
static int F_16 (
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
struct V_61 * V_62 = NULL ;
struct V_22 * V_23 ;
V_34 -> V_63 = 0 ;
F_17 (param, &conn->param_list->param_list, p_list) {
if ( ! strncmp ( V_62 -> V_64 , V_65 , 11 ) ) {
if ( ! F_18 ( V_62 ) ) {
F_4 ( L_28
L_29 ) ;
F_15 ( V_12 , V_45 ,
V_66 ) ;
return - 1 ;
}
if ( ! strncmp ( V_62 -> V_67 , V_68 , 9 ) )
return 0 ;
}
if ( ! strncmp ( V_62 -> V_64 , V_69 , 13 ) ) {
if ( ! F_18 ( V_62 ) ) {
if ( ! V_34 -> V_70 )
continue;
F_4 ( L_30
L_29 ) ;
F_15 ( V_12 , V_45 ,
V_66 ) ;
return - 1 ;
}
if ( ! V_34 -> V_70 ) {
V_23 = V_12 -> V_17 -> V_26 -> V_22 ;
if ( ! V_23 ) {
F_4 ( L_31
L_32 ) ;
F_15 ( V_12 ,
V_45 ,
V_71 ) ;
return - 1 ;
}
if ( strcmp ( V_62 -> V_67 ,
V_23 -> V_72 ) ) {
F_4 ( L_33
L_34
L_35 ,
V_62 -> V_67 ) ;
F_15 ( V_12 ,
V_45 ,
V_71 ) ;
return - 1 ;
}
}
}
}
return 0 ;
}
static int F_19 ( struct V_11 * V_12 , struct V_33 * V_34 )
{
T_1 V_73 = 0 ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_74 * V_75 ;
V_75 = (struct V_74 * ) V_34 -> V_76 ;
V_75 -> V_42 = V_77 ;
F_20 ( V_75 -> V_41 , V_34 -> V_78 ) ;
memcpy ( V_75 -> V_57 , V_34 -> V_57 , 6 ) ;
V_75 -> V_79 = F_21 ( V_34 -> V_79 ) ;
V_75 -> V_58 = F_22 ( V_34 -> V_59 ) ;
V_75 -> V_80 = F_22 ( V_12 -> V_81 ++ ) ;
V_75 -> V_82 = F_22 ( V_12 -> V_17 -> V_83 ) ;
V_75 -> V_84 = F_22 ( V_12 -> V_17 -> V_85 ) ;
F_23 ( L_36
L_37
L_38 , V_75 -> V_47 , F_24 ( V_75 -> V_58 ) ,
F_24 ( V_75 -> V_82 ) , F_24 ( V_75 -> V_84 ) ,
F_24 ( V_75 -> V_80 ) , V_34 -> V_78 ) ;
V_73 = ( ( - V_34 -> V_78 ) & 3 ) ;
if ( F_25 (
V_12 ,
V_34 -> V_76 ,
V_34 -> V_86 ,
V_34 -> V_78 + V_73 ) < 0 )
return - 1 ;
V_34 -> V_78 = 0 ;
V_75 -> V_79 = F_26 ( V_75 -> V_79 ) ;
V_75 -> V_58 = F_27 ( V_75 -> V_58 ) ;
V_75 -> V_80 = F_27 ( V_75 -> V_80 ) ;
F_28 ( & V_17 -> V_87 ) ;
V_75 -> V_82 = F_27 ( V_17 -> V_83 ) ;
V_75 -> V_84 = F_27 ( V_17 -> V_85 ) ;
F_29 ( & V_17 -> V_87 ) ;
return 0 ;
}
static int F_30 ( struct V_11 * V_12 , struct V_33 * V_34 )
{
T_1 V_73 = 0 , V_37 ;
struct V_38 * V_39 ;
if ( F_31 ( V_12 , V_34 -> V_40 , V_88 ) < 0 )
return - 1 ;
V_39 = (struct V_38 * ) V_34 -> V_40 ;
V_37 = F_14 ( V_39 -> V_41 ) ;
V_39 -> V_79 = F_26 ( V_39 -> V_79 ) ;
V_39 -> V_58 = F_27 ( V_39 -> V_58 ) ;
V_39 -> V_89 = F_26 ( V_39 -> V_89 ) ;
V_39 -> V_90 = F_27 ( V_39 -> V_90 ) ;
V_39 -> V_91 = F_27 ( V_39 -> V_91 ) ;
F_23 ( L_39
L_40 ,
V_39 -> V_47 , V_39 -> V_58 , V_39 -> V_90 ,
V_39 -> V_91 , V_39 -> V_89 , V_37 ) ;
if ( F_13 ( V_12 , V_34 ) < 0 )
return - 1 ;
V_73 = ( ( - V_37 ) & 3 ) ;
memset ( V_34 -> V_92 , 0 , V_60 ) ;
if ( F_31 (
V_12 ,
V_34 -> V_92 ,
V_37 + V_73 ) < 0 )
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
T_1 V_73 = 0 , V_37 ;
struct V_38 * V_39 ;
V_39 = (struct V_38 * ) V_34 -> V_40 ;
V_37 = F_14 ( V_39 -> V_41 ) ;
F_23 ( L_39
L_41 ,
V_39 -> V_47 , V_39 -> V_58 , V_39 -> V_90 ,
V_39 -> V_91 , V_37 ) ;
if ( F_13 ( V_12 , V_34 ) < 0 )
return - 1 ;
V_73 = ( ( - V_37 ) & 3 ) ;
if ( F_31 (
V_12 ,
V_34 -> V_92 ,
V_37 + V_73 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_34 (
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
if ( V_34 -> V_93 )
return 0 ;
V_34 -> V_93 = 1 ;
if ( ! V_34 -> V_79 )
return F_35 ( V_12 ) ;
else
return F_36 ( V_12 , V_34 -> V_89 ,
V_34 -> V_94 ) ;
}
static int F_37 (
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
int V_95 ;
T_1 V_37 ;
struct V_61 * V_62 ;
struct V_38 * V_39 ;
struct V_74 * V_75 ;
V_39 = (struct V_38 * ) V_34 -> V_40 ;
V_75 = (struct V_74 * ) V_34 -> V_76 ;
V_37 = F_14 ( V_39 -> V_41 ) ;
V_62 = F_38 ( V_96 , V_12 -> V_97 ) ;
if ( ! V_62 )
return - 1 ;
V_95 = F_5 (
V_12 ,
V_34 -> V_92 ,
V_34 -> V_86 ,
V_37 ,
& V_34 -> V_78 ,
V_62 -> V_67 ) ;
switch ( V_95 ) {
case 0 :
F_23 ( L_42
L_43 ) ;
break;
case 1 :
F_23 ( L_44
L_45 ) ;
V_34 -> V_98 = 1 ;
if ( ( V_39 -> V_47 & V_99 ) &&
( V_39 -> V_47 & V_49 ) ) {
V_75 -> V_47 |= ( V_99 |
V_49 ) ;
V_34 -> V_52 = 1 ;
}
return F_34 (
V_12 , V_34 ) ;
case 2 :
F_4 ( L_46
L_47 ) ;
F_15 ( V_12 , V_45 ,
V_100 ) ;
return - 1 ;
default:
F_4 ( L_48
L_49 , V_95 ) ;
F_15 ( V_12 , V_101 ,
V_102 ) ;
return - 1 ;
}
return 0 ;
}
static int F_39 (
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
int V_103 ;
T_1 V_37 ;
struct V_61 * V_62 ;
struct V_38 * V_39 ;
struct V_74 * V_75 ;
V_39 = (struct V_38 * ) V_34 -> V_40 ;
V_75 = (struct V_74 * ) V_34 -> V_76 ;
V_37 = F_14 ( V_39 -> V_41 ) ;
V_62 = F_38 ( V_96 , V_12 -> V_97 ) ;
if ( ! V_62 )
return - 1 ;
V_103 = F_40 (
V_104 | V_105 ,
V_106 | V_107 ,
V_34 -> V_92 ,
V_37 ,
V_12 -> V_97 ) ;
if ( V_103 < 0 )
return - 1 ;
if ( V_103 > 0 ) {
if ( V_34 -> V_98 ) {
F_4 ( L_50
L_51
L_52 , V_62 -> V_67 ) ;
F_15 ( V_12 , V_45 ,
V_46 ) ;
return - 1 ;
}
goto V_108;
}
if ( V_34 -> V_63 )
if ( F_16 ( V_12 , V_34 ) < 0 )
return - 1 ;
V_103 = F_41 (
V_104 | V_105 ,
V_109 ,
V_34 -> V_86 ,
& V_34 -> V_78 ,
V_12 -> V_97 ) ;
if ( V_103 < 0 )
return - 1 ;
if ( ! F_42 ( V_12 -> V_97 ) ) {
if ( F_43 ( F_44 ( V_12 ) ) -> V_110 &&
! strncmp ( V_62 -> V_67 , V_31 , 4 ) ) {
F_4 ( L_53
L_54
L_55 ) ;
F_15 ( V_12 , V_45 ,
V_100 ) ;
return - 1 ;
}
if ( F_43 ( F_44 ( V_12 ) ) -> V_110 &&
! V_34 -> V_98 )
return 0 ;
if ( strncmp ( V_62 -> V_67 , V_31 , 4 ) && ! V_34 -> V_98 )
return 0 ;
if ( ( V_39 -> V_47 & V_99 ) &&
( V_39 -> V_47 & V_49 ) ) {
V_75 -> V_47 |= V_99 |
V_49 ;
V_34 -> V_52 = 1 ;
}
}
return 0 ;
V_108:
return F_37 ( V_12 , V_34 ) ;
}
static int F_45 ( struct V_11 * V_12 , struct V_33 * V_34 )
{
int V_103 ;
T_1 V_37 ;
struct V_38 * V_39 ;
struct V_74 * V_75 ;
V_39 = (struct V_38 * ) V_34 -> V_40 ;
V_75 = (struct V_74 * ) V_34 -> V_76 ;
V_37 = F_14 ( V_39 -> V_41 ) ;
V_103 = F_40 (
V_111 | V_105 ,
V_106 | V_107 ,
V_34 -> V_92 ,
V_37 ,
V_12 -> V_97 ) ;
if ( V_103 < 0 )
return - 1 ;
if ( V_34 -> V_63 )
if ( F_16 ( V_12 , V_34 ) < 0 )
return - 1 ;
if ( F_34 ( V_12 , V_34 ) < 0 )
return - 1 ;
V_103 = F_41 (
V_111 | V_105 ,
V_109 ,
V_34 -> V_86 ,
& V_34 -> V_78 ,
V_12 -> V_97 ) ;
if ( V_103 < 0 )
return - 1 ;
if ( ! V_34 -> V_98 &&
F_43 ( F_44 ( V_12 ) ) -> V_110 ) {
F_4 ( L_56
L_57
L_58 ) ;
F_15 ( V_12 , V_45 ,
V_100 ) ;
return - 1 ;
}
if ( ! F_42 ( V_12 -> V_97 ) )
if ( ( V_39 -> V_47 & V_112 ) &&
( V_39 -> V_47 & V_49 ) )
V_75 -> V_47 |= V_112 |
V_49 ;
return 0 ;
}
static int F_46 ( struct V_11 * V_12 , struct V_33 * V_34 )
{
int V_113 = 0 ;
struct V_38 * V_39 ;
struct V_74 * V_75 ;
V_39 = (struct V_38 * ) V_34 -> V_40 ;
V_75 = (struct V_74 * ) V_34 -> V_76 ;
while ( 1 ) {
if ( ++ V_113 > V_114 ) {
F_4 ( L_59 ) ;
F_15 ( V_12 , V_101 ,
V_102 ) ;
return - 1 ;
}
switch ( ( V_39 -> V_47 & V_50 ) >> 2 ) {
case 0 :
V_75 -> V_47 |= ( 0 & V_50 ) ;
if ( F_39 ( V_12 , V_34 ) < 0 )
return - 1 ;
break;
case 1 :
V_75 -> V_47 |= V_115 ;
if ( F_45 ( V_12 , V_34 ) < 0 )
return - 1 ;
if ( V_75 -> V_47 & V_49 ) {
V_34 -> V_79 = V_12 -> V_17 -> V_79 ;
if ( F_19 ( V_12 ,
V_34 ) < 0 )
return - 1 ;
return 0 ;
}
break;
default:
F_4 ( L_60
L_61 ,
( V_39 -> V_47 & V_50 )
>> 2 ) ;
break;
}
if ( F_32 ( V_12 , V_34 ) < 0 )
return - 1 ;
if ( V_75 -> V_47 & V_49 ) {
V_75 -> V_47 &= ~ V_49 ;
V_75 -> V_47 &= ~ V_51 ;
}
}
return 0 ;
}
static void F_47 (
char * V_116 )
{
char * V_117 ;
T_1 V_118 = strlen ( V_116 ) , V_3 ;
for ( V_3 = 0 ; V_3 < V_118 ; V_3 ++ ) {
V_117 = & V_116 [ V_3 ] ;
if ( ! isupper ( * V_117 ) )
continue;
* V_117 = tolower ( * V_117 ) ;
}
}
static int F_48 (
struct V_119 * V_120 ,
struct V_11 * V_12 ,
struct V_33 * V_34 )
{
char * V_121 = NULL , * V_122 = NULL , * V_123 = NULL ;
char * V_124 , * V_125 = NULL , * V_126 = NULL , * V_127 , * V_67 ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_128 * V_129 ;
struct V_38 * V_39 ;
T_1 V_37 ;
int V_130 = 0 , V_103 = 0 ;
V_39 = (struct V_38 * ) V_34 -> V_40 ;
V_37 = F_14 ( V_39 -> V_41 ) ;
V_34 -> V_63 = 1 ;
V_34 -> V_70 = ( ! V_39 -> V_79 ) ? 1 : 0 ;
V_34 -> V_52 =
( V_39 -> V_47 & V_50 ) >> 2 ;
V_34 -> V_56 = V_39 -> V_55 ;
V_34 -> V_54 = V_39 -> V_53 ;
memcpy ( V_34 -> V_57 , V_39 -> V_57 , 6 ) ;
V_34 -> V_131 = V_39 -> V_90 ;
V_34 -> V_59 = V_39 -> V_58 ;
V_34 -> V_94 = V_39 -> V_91 ;
V_34 -> V_89 = V_39 -> V_89 ;
V_34 -> V_79 = V_39 -> V_79 ;
if ( F_33 ( V_12 , V_34 ) < 0 )
return - 1 ;
V_124 = F_49 ( V_37 + 1 , V_132 ) ;
if ( ! V_124 ) {
F_4 ( L_62 ) ;
return - 1 ;
}
memcpy ( V_124 , V_34 -> V_92 , V_37 ) ;
V_124 [ V_37 ] = '\0' ;
V_125 = V_124 ;
V_126 = ( V_125 + V_37 ) ;
while ( V_125 < V_126 ) {
if ( F_50 ( V_125 , & V_127 , & V_67 ) < 0 ) {
V_103 = - 1 ;
goto V_133;
}
if ( ! strncmp ( V_127 , L_63 , 13 ) )
V_121 = V_67 ;
else if ( ! strncmp ( V_127 , L_64 , 11 ) )
V_122 = V_67 ;
else if ( ! strncmp ( V_127 , L_65 , 10 ) )
V_123 = V_67 ;
V_125 += strlen ( V_127 ) + strlen ( V_67 ) + 2 ;
}
if ( ! V_121 ) {
F_4 ( L_30
L_29 ) ;
F_15 ( V_12 , V_45 ,
V_66 ) ;
V_103 = - 1 ;
goto V_133;
}
F_47 ( V_121 ) ;
if ( ! V_122 ) {
if ( ! V_34 -> V_70 )
goto V_134;
F_4 ( L_28
L_29 ) ;
F_15 ( V_12 , V_45 ,
V_66 ) ;
V_103 = - 1 ;
goto V_133;
}
V_130 = strncmp ( V_122 , V_68 , 9 ) ;
if ( ! V_130 ) {
V_12 -> V_135 = V_27 -> V_136 ;
if ( ! V_34 -> V_70 )
goto V_134;
V_17 -> V_24 -> V_25 = 1 ;
if ( F_51 ( V_12 ) < 0 ) {
F_4 ( L_66 ) ;
V_103 = - 1 ;
goto V_133;
}
if ( F_52 ( V_120 , V_12 -> V_135 ) < 0 ) {
F_15 ( V_12 , V_101 ,
V_137 ) ;
V_103 = - 1 ;
goto V_133;
}
V_103 = 0 ;
goto V_133;
}
V_134:
if ( ! V_123 ) {
F_4 ( L_67
L_68
L_69 ) ;
F_15 ( V_12 , V_45 ,
V_66 ) ;
V_103 = - 1 ;
goto V_133;
}
V_129 = F_53 ( V_123 ) ;
if ( ! V_129 ) {
F_4 ( L_70
L_71 , V_123 ) ;
F_15 ( V_12 , V_101 ,
V_137 ) ;
V_103 = - 1 ;
goto V_133;
}
F_23 ( L_72 , V_129 -> V_129 ) ;
V_12 -> V_135 = F_54 ( V_129 , V_120 ) ;
if ( ! V_12 -> V_135 ) {
F_4 ( L_73
L_74 , V_129 -> V_129 ) ;
F_55 ( V_129 ) ;
F_15 ( V_12 , V_101 ,
V_137 ) ;
V_103 = - 1 ;
goto V_133;
}
F_23 ( L_75 , V_12 -> V_135 -> V_138 ) ;
if ( F_51 ( V_12 ) < 0 ) {
F_4 ( L_66 ) ;
V_103 = - 1 ;
goto V_133;
}
if ( F_52 ( V_120 , V_12 -> V_135 ) < 0 ) {
F_55 ( V_129 ) ;
F_15 ( V_12 , V_101 ,
V_137 ) ;
V_103 = - 1 ;
V_12 -> V_135 = NULL ;
goto V_133;
}
if ( ! V_34 -> V_70 ) {
V_103 = 0 ;
goto V_133;
}
V_17 -> V_24 -> V_25 = 0 ;
V_17 -> V_26 -> V_22 = F_56 (
& V_12 -> V_135 -> V_139 , V_121 ) ;
if ( ! V_17 -> V_26 -> V_22 ) {
F_4 ( L_76
L_77 ,
V_121 , V_12 -> V_135 -> V_138 ) ;
F_15 ( V_12 , V_45 ,
V_140 ) ;
V_103 = - 1 ;
goto V_133;
}
V_103 = 0 ;
V_133:
F_12 ( V_124 ) ;
return V_103 ;
}
struct V_33 * F_57 (
struct V_119 * V_120 ,
struct V_11 * V_12 ,
char * V_141 )
{
struct V_33 * V_34 ;
V_34 = F_49 ( sizeof( struct V_33 ) , V_132 ) ;
if ( ! V_34 ) {
F_4 ( L_78 ) ;
F_15 ( V_12 , V_101 ,
V_142 ) ;
return NULL ;
}
V_34 -> V_40 = F_58 ( V_141 , V_88 , V_132 ) ;
if ( ! V_34 -> V_40 ) {
F_4 ( L_79 ) ;
F_15 ( V_12 , V_101 ,
V_142 ) ;
goto V_133;
}
V_34 -> V_92 = F_49 ( V_60 , V_132 ) ;
if ( ! V_34 -> V_92 ) {
F_4 ( L_80 ) ;
F_15 ( V_12 , V_101 ,
V_142 ) ;
goto V_133;
}
if ( F_48 ( V_120 , V_12 , V_34 ) < 0 ) {
F_4 ( L_81 ) ;
goto V_133;
}
return V_34 ;
V_133:
F_12 ( V_34 -> V_40 ) ;
F_12 ( V_34 -> V_92 ) ;
F_12 ( V_34 ) ;
return NULL ;
}
int F_59 (
struct V_33 * V_34 ,
struct V_11 * V_12 )
{
int V_103 = - 1 ;
V_34 -> V_76 = F_49 ( V_88 , V_132 ) ;
if ( ! V_34 -> V_76 ) {
F_4 ( L_82
L_83 ) ;
F_15 ( V_12 , V_101 ,
V_142 ) ;
V_103 = - 1 ;
goto V_133;
}
V_34 -> V_86 = F_49 ( V_60 , V_132 ) ;
if ( ! V_34 -> V_86 ) {
F_4 ( L_82
L_84 ) ;
F_15 ( V_12 , V_101 ,
V_142 ) ;
V_103 = - 1 ;
goto V_133;
}
V_103 = F_46 ( V_12 , V_34 ) ;
V_133:
if ( V_103 != 0 )
F_11 ( V_12 ) ;
F_60 ( V_34 , V_12 ) ;
return V_103 ;
}
void F_60 (
struct V_33 * V_34 ,
struct V_11 * V_12 )
{
F_12 ( V_34 -> V_40 ) ;
F_12 ( V_34 -> V_76 ) ;
F_12 ( V_34 -> V_92 ) ;
F_12 ( V_34 -> V_86 ) ;
F_12 ( V_34 ) ;
}
