static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_1 V_10 ;
V_7 = F_2 ( V_2 ) ;
V_10 = F_3 ( V_7 ) ;
if ( V_10 < 0 )
return - V_11 ;
V_9 = V_7 -> V_9 ;
if ( V_9 )
V_10 = sprintf ( V_5 , L_1 , F_4 ( V_7 , V_9 ) ) ;
F_5 ( V_7 ) ;
return V_10 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_1 V_10 ;
V_7 = F_2 ( V_2 ) ;
V_10 = F_3 ( V_7 ) ;
if ( V_10 < 0 )
return - V_11 ;
V_9 = V_7 -> V_9 ;
if ( V_9 && V_9 -> string )
V_10 = sprintf ( V_5 , L_2 , V_9 -> string ) ;
F_5 ( V_7 ) ;
return V_10 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_13 , V_14 , V_10 ;
if ( sscanf ( V_5 , L_3 , & V_13 ) != 1 || V_13 < - 1 || V_13 > 255 )
return - V_15 ;
V_10 = F_3 ( V_7 ) ;
if ( V_10 < 0 )
return - V_11 ;
V_14 = F_8 ( V_7 , V_13 ) ;
F_5 ( V_7 ) ;
return ( V_14 < 0 ) ? V_14 : V_12 ;
}
static T_1 F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
char * V_16 ;
V_7 = F_2 ( V_2 ) ;
switch ( V_7 -> V_16 ) {
case V_17 :
V_16 = L_4 ;
break;
case V_18 :
case V_19 :
V_16 = L_5 ;
break;
case V_20 :
V_16 = L_6 ;
break;
case V_21 :
V_16 = L_6 ;
break;
case V_22 :
V_16 = L_7 ;
break;
case V_23 :
V_16 = L_8 ;
break;
default:
V_16 = L_9 ;
}
return sprintf ( V_5 , L_2 , V_16 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , V_7 -> V_24 -> V_25 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , V_7 -> V_26 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_27 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
T_3 V_28 ;
V_7 = F_2 ( V_2 ) ;
V_28 = F_14 ( V_7 -> V_29 . V_28 ) ;
return sprintf ( V_5 , L_11 , V_28 >> 8 , V_28 & 0xff ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , V_7 -> V_30 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_12 , V_7 -> V_31 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , ! ! ( V_7 -> V_31 & V_32 ) ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_33 , V_10 ;
if ( sscanf ( V_5 , L_3 , & V_33 ) != 1 || V_33 < 0 || V_33 > 1 )
return - V_15 ;
V_10 = F_3 ( V_7 ) ;
if ( V_10 < 0 )
return - V_11 ;
if ( V_33 )
V_7 -> V_31 |= V_32 ;
else
V_7 -> V_31 &= ~ V_32 ;
F_5 ( V_7 ) ;
return V_12 ;
}
static T_1 F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , F_20 ( & V_7 -> V_34 ) ) ;
}
static T_1 F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
char * V_35 ;
V_7 = F_2 ( V_2 ) ;
switch ( V_7 -> V_36 ) {
case V_37 :
V_35 = L_13 ;
break;
case V_38 :
V_35 = L_14 ;
break;
default:
V_35 = L_9 ;
}
return sprintf ( V_5 , L_2 , V_35 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
if ( F_23 ( F_2 ( V_2 ) ) )
return sprintf ( V_5 , L_2 , L_15 ) ;
return sprintf ( V_5 , L_2 , L_16 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , V_7 -> V_39 ) ;
}
static T_1 F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_14 , V_10 ;
if ( V_7 -> V_29 . V_40 == V_41 )
return - V_42 ;
if ( sscanf ( V_5 , L_3 , & V_14 ) != 1 )
return - V_15 ;
V_10 = F_3 ( V_7 ) ;
if ( V_10 < 0 )
return - V_11 ;
V_7 -> V_39 = ! ! V_14 ;
F_5 ( V_7 ) ;
return V_12 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
if ( F_27 ( V_2 ) ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_29 . V_40 != V_41 )
V_10 = F_28 ( & V_2 -> V_43 ,
& V_44 . V_4 ,
V_45 ) ;
}
return V_10 ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_43 ,
& V_44 . V_4 ,
V_45 ) ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_17 ,
F_32 ( V_46 - V_7 -> V_47 ) ) ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_48 ;
if ( V_7 -> V_35 != V_49 )
V_48 = F_32 ( V_46 + V_7 -> V_50 ) ;
else
V_48 = F_32 ( V_7 -> V_50 ) ;
return sprintf ( V_5 , L_17 , V_48 ) ;
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_10 , V_2 -> V_51 . V_52 / 1000 ) ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 ,
T_2 V_12 )
{
int V_14 ;
if ( sscanf ( V_5 , L_3 , & V_14 ) != 1 || V_14 >= V_53 / 1000 ||
V_14 <= - V_53 / 1000 )
return - V_15 ;
F_36 ( V_2 , V_14 * 1000 ) ;
return V_12 ;
}
static void F_37 ( void )
{
static int V_54 ;
if ( ! V_54 ) {
V_54 = 1 ;
F_38 ( V_55 L_18
L_19 ) ;
}
}
static T_1 F_39 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_56 = V_57 ;
F_37 () ;
if ( V_7 -> V_35 != V_49 && ! V_7 -> V_2 . V_51 . V_58 )
V_56 = V_59 ;
return sprintf ( V_5 , L_2 , V_56 ) ;
}
static T_1 F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_60 = V_12 ;
char * V_61 ;
int V_10 = V_12 ;
int V_62 ;
F_37 () ;
V_61 = memchr ( V_5 , '\n' , V_12 ) ;
if ( V_61 )
V_60 = V_61 - V_5 ;
V_62 = F_3 ( V_7 ) ;
if ( V_62 < 0 )
return - V_11 ;
if ( V_60 == sizeof V_59 - 1 &&
strncmp ( V_5 , V_59 , V_60 ) == 0 )
F_41 ( V_7 ) ;
else if ( V_60 == sizeof V_57 - 1 &&
strncmp ( V_5 , V_57 , V_60 ) == 0 )
F_42 ( V_7 ) ;
else
V_10 = - V_15 ;
F_5 ( V_7 ) ;
return V_10 ;
}
static T_1 F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_56 ;
if ( V_7 -> V_63 == 1 )
V_56 = L_20 ;
else
V_56 = L_21 ;
return sprintf ( V_5 , L_2 , V_56 ) ;
}
static T_1 F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
bool V_14 ;
int V_64 ;
V_64 = F_3 ( V_7 ) ;
if ( V_64 < 0 )
return - V_11 ;
V_64 = F_45 ( V_5 , & V_14 ) ;
if ( ! V_64 ) {
V_7 -> V_63 = V_14 ;
V_64 = F_46 ( V_7 , V_14 ) ;
}
F_5 ( V_7 ) ;
if ( ! V_64 )
return V_12 ;
return V_64 ;
}
static T_1 F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , V_7 -> V_65 . V_66 ) ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_66 ;
if ( F_49 ( V_5 , 0 , & V_66 ) )
return - V_15 ;
V_7 -> V_65 . V_66 = V_66 ;
return V_12 ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , V_7 -> V_65 . V_67 ) ;
}
static T_1 F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_4 V_67 ;
if ( F_52 ( V_5 , 0 , & V_67 ) || V_67 > 15 )
return - V_15 ;
V_7 -> V_65 . V_67 = V_67 ;
return V_12 ;
}
static T_1 F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_56 ;
int V_10 ;
V_10 = F_3 ( V_7 ) ;
if ( V_10 < 0 )
return - V_11 ;
if ( V_7 -> V_68 )
V_56 = L_20 ;
else
V_56 = L_21 ;
F_5 ( V_7 ) ;
return sprintf ( V_5 , L_2 , V_56 ) ;
}
static T_1 F_54 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_56 ;
int V_10 ;
V_10 = F_3 ( V_7 ) ;
if ( V_10 < 0 )
return - V_11 ;
if ( V_7 -> V_69 )
V_56 = L_20 ;
else
V_56 = L_21 ;
F_5 ( V_7 ) ;
return sprintf ( V_5 , L_2 , V_56 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
if ( F_27 ( V_2 ) ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_10 = F_56 ( & V_2 -> V_43 , & V_70 ) ;
if ( V_7 -> V_71 == 1 )
V_10 = F_56 ( & V_2 -> V_43 ,
& V_72 ) ;
if ( V_7 -> V_16 == V_22 &&
V_7 -> V_73 == 1 )
V_10 = F_56 ( & V_2 -> V_43 ,
& V_74 ) ;
}
return V_10 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_58 ( & V_2 -> V_43 , & V_72 ) ;
F_58 ( & V_2 -> V_43 , & V_70 ) ;
}
static T_1 F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_75 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_76 , L_17 , V_75 -> V_77 ) ;
}
static T_1 F_60 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 ,
T_2 V_78 )
{
T_1 V_79 ;
struct V_6 * V_75 = F_2 ( V_2 ) ;
unsigned V_33 ;
V_79 = sscanf ( V_5 , L_17 , & V_33 ) ;
if ( V_79 != 1 )
V_79 = - V_15 ;
else if ( V_33 == 0 )
V_79 = F_61 ( V_75 ) ;
else
V_79 = F_62 ( V_75 ) ;
return V_79 < 0 ? V_79 : V_78 ;
}
static T_1 F_63 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 = 0 ;
F_64 ( V_7 ) ;
if ( V_7 -> V_35 != V_80 ) {
F_8 ( V_7 , - 1 ) ;
V_10 = F_65 ( V_7 ) ;
}
if ( V_10 == 0 )
V_10 = V_12 ;
F_5 ( V_7 ) ;
return V_10 ;
}
static T_5 F_66 ( struct V_81 * V_43 ,
struct V_82 * V_83 , int V_84 )
{
struct V_1 * V_2 = F_67 ( V_43 , struct V_1 , V_43 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_83 == & V_85 . V_4 ) {
if ( V_7 -> V_86 == NULL )
return 0 ;
} else if ( V_83 == & V_87 . V_4 ) {
if ( V_7 -> V_88 == NULL )
return 0 ;
} else if ( V_83 == & V_89 . V_4 ) {
if ( V_7 -> V_90 == NULL )
return 0 ;
}
return V_83 -> V_91 ;
}
static T_1
F_68 ( struct V_92 * V_93 , struct V_81 * V_43 ,
struct V_94 * V_4 ,
char * V_5 , T_6 V_95 , T_2 V_12 )
{
struct V_1 * V_2 = F_67 ( V_43 , struct V_1 , V_43 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_96 = V_12 ;
T_2 V_97 , V_84 ;
int V_98 ;
void * V_99 ;
for ( V_98 = - 1 ; V_98 < V_7 -> V_29 . V_100 &&
V_96 > 0 ; ++ V_98 ) {
if ( V_98 < 0 ) {
V_99 = & V_7 -> V_29 ;
V_97 = sizeof( struct V_101 ) ;
} else {
V_99 = V_7 -> V_102 [ V_98 ] ;
V_97 = F_69 ( V_7 -> V_13 [ V_98 ] . V_103 .
V_104 ) ;
}
if ( V_95 < V_97 ) {
V_84 = F_70 ( V_96 , V_97 - ( T_2 ) V_95 ) ;
memcpy ( V_5 , V_99 + V_95 , V_84 ) ;
V_96 -= V_84 ;
V_5 += V_84 ;
V_95 = 0 ;
} else {
V_95 -= V_97 ;
}
}
return V_12 - V_96 ;
}
int F_71 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
int V_105 ;
V_105 = F_72 ( V_2 , & V_106 ) ;
if ( V_105 )
goto error;
V_105 = F_26 ( V_2 ) ;
if ( V_105 )
goto error;
V_105 = F_55 ( V_2 ) ;
if ( V_105 )
goto error;
return V_105 ;
error:
F_73 ( V_7 ) ;
return V_105 ;
}
void F_73 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
F_57 ( V_2 ) ;
F_29 ( V_2 ) ;
F_74 ( V_2 , & V_106 ) ;
}
static T_1 F_75 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_107 * V_108 ;
char * string ;
V_108 = F_76 ( V_2 ) ;
string = F_77 ( V_108 -> V_109 -> string ) ;
if ( ! string )
return 0 ;
return sprintf ( V_5 , L_2 , string ) ;
}
static T_1 F_78 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_107 * V_108 ;
struct V_6 * V_7 ;
struct V_110 * V_111 ;
V_108 = F_76 ( V_2 ) ;
V_7 = F_79 ( V_108 ) ;
V_111 = F_77 ( V_108 -> V_109 ) ;
return sprintf ( V_5 , L_22
L_23 ,
F_14 ( V_7 -> V_29 . V_112 ) ,
F_14 ( V_7 -> V_29 . V_113 ) ,
F_14 ( V_7 -> V_29 . V_114 ) ,
V_7 -> V_29 . V_40 ,
V_7 -> V_29 . V_115 ,
V_7 -> V_29 . V_116 ,
V_111 -> V_103 . V_117 ,
V_111 -> V_103 . V_118 ,
V_111 -> V_103 . V_119 ,
V_111 -> V_103 . V_120 ) ;
}
static T_1 F_80 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_121 ;
V_121 = F_81 ( V_2 ) ;
if ( V_121 < 0 )
return - V_11 ;
V_121 = ( ! V_2 -> V_122 || F_82 ( V_2 -> V_122 ) -> V_123 ) ;
F_83 ( V_2 ) ;
return sprintf ( V_5 , L_17 , V_121 ) ;
}
static T_1 F_84 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_107 * V_108 = F_76 ( V_2 ) ;
return sprintf ( V_5 , L_17 , V_108 -> V_77 ) ;
}
static T_1 F_85 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_107 * V_108 = F_76 ( V_2 ) ;
bool V_33 ;
if ( F_45 ( V_5 , & V_33 ) != 0 )
return - V_15 ;
if ( V_33 )
F_86 ( V_108 ) ;
else
F_87 ( V_108 ) ;
return V_12 ;
}
static T_5 F_88 ( struct V_81 * V_43 ,
struct V_82 * V_83 , int V_84 )
{
struct V_1 * V_2 = F_67 ( V_43 , struct V_1 , V_43 ) ;
struct V_107 * V_108 = F_76 ( V_2 ) ;
if ( V_108 -> V_124 == NULL )
return 0 ;
return V_83 -> V_91 ;
}
void F_89 ( struct V_107 * V_108 )
{
struct V_6 * V_7 = F_79 ( V_108 ) ;
struct V_110 * V_111 = V_108 -> V_109 ;
if ( V_108 -> V_125 || V_108 -> V_126 )
return;
if ( ! V_111 -> string && ! ( V_7 -> V_31 & V_127 ) )
V_111 -> string = F_90 ( V_7 , V_111 -> V_103 . V_128 ) ;
if ( V_111 -> string && F_91 ( & V_108 -> V_2 , & V_129 ) )
;
V_108 -> V_125 = 1 ;
}
void F_92 ( struct V_107 * V_108 )
{
if ( ! V_108 -> V_125 )
return;
F_93 ( & V_108 -> V_2 , & V_129 ) ;
V_108 -> V_125 = 0 ;
}
