static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_1 V_10 = 0 ;
V_7 = F_2 ( V_2 ) ;
F_3 ( V_7 ) ;
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
T_1 V_10 = 0 ;
V_7 = F_2 ( V_2 ) ;
F_3 ( V_7 ) ;
V_9 = V_7 -> V_9 ;
if ( V_9 && V_9 -> string )
V_10 = sprintf ( V_5 , L_2 , V_9 -> string ) ;
F_5 ( V_7 ) ;
return V_10 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_12 , V_13 ;
if ( sscanf ( V_5 , L_3 , & V_12 ) != 1 || V_12 < - 1 || V_12 > 255 )
return - V_14 ;
F_3 ( V_7 ) ;
V_13 = F_8 ( V_7 , V_12 ) ;
F_5 ( V_7 ) ;
return ( V_13 < 0 ) ? V_13 : V_11 ;
}
static T_1 F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
char * V_15 ;
V_7 = F_2 ( V_2 ) ;
switch ( V_7 -> V_15 ) {
case V_16 :
V_15 = L_4 ;
break;
case V_17 :
case V_18 :
V_15 = L_5 ;
break;
case V_19 :
V_15 = L_6 ;
break;
case V_20 :
V_15 = L_6 ;
break;
case V_21 :
V_15 = L_7 ;
break;
default:
V_15 = L_8 ;
}
return sprintf ( V_5 , L_2 , V_15 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_9 , V_7 -> V_22 -> V_23 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_9 , V_7 -> V_24 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_25 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
T_3 V_26 ;
V_7 = F_2 ( V_2 ) ;
V_26 = F_14 ( V_7 -> V_27 . V_26 ) ;
return sprintf ( V_5 , L_10 , V_26 >> 8 , V_26 & 0xff ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_9 , V_7 -> V_28 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_11 , V_7 -> V_29 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_9 , ! ! ( V_7 -> V_29 & V_30 ) ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_31 ;
if ( sscanf ( V_5 , L_3 , & V_31 ) != 1 || V_31 < 0 || V_31 > 1 )
return - V_14 ;
F_3 ( V_7 ) ;
if ( V_31 )
V_7 -> V_29 |= V_30 ;
else
V_7 -> V_29 &= ~ V_30 ;
F_5 ( V_7 ) ;
return V_11 ;
}
static T_1 F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_9 , F_20 ( & V_7 -> V_32 ) ) ;
}
static T_1 F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
char * V_33 ;
V_7 = F_2 ( V_2 ) ;
switch ( V_7 -> V_34 ) {
case V_35 :
V_33 = L_12 ;
break;
case V_36 :
V_33 = L_13 ;
break;
default:
V_33 = L_8 ;
}
return sprintf ( V_5 , L_2 , V_33 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
if ( F_23 ( F_2 ( V_2 ) ) )
return sprintf ( V_5 , L_2 , L_14 ) ;
return sprintf ( V_5 , L_2 , L_15 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_9 , V_7 -> V_37 ) ;
}
static T_1 F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_7 -> V_27 . V_38 == V_39 )
return - V_40 ;
if ( sscanf ( V_5 , L_3 , & V_13 ) != 1 )
return - V_14 ;
F_3 ( V_7 ) ;
V_7 -> V_37 = ! ! V_13 ;
F_5 ( V_7 ) ;
return V_11 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
if ( F_27 ( V_2 ) ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_27 . V_38 != V_39 )
V_10 = F_28 ( & V_2 -> V_41 ,
& V_42 . V_4 ,
V_43 ) ;
}
return V_10 ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_41 ,
& V_42 . V_4 ,
V_43 ) ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_16 ,
F_32 ( V_44 - V_7 -> V_45 ) ) ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_46 ;
if ( V_7 -> V_33 != V_47 )
V_46 = F_32 ( V_44 + V_7 -> V_48 ) ;
else
V_46 = F_32 ( V_7 -> V_48 ) ;
return sprintf ( V_5 , L_16 , V_46 ) ;
}
static T_1 F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_9 , V_2 -> V_49 . V_50 / 1000 ) ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 ,
T_2 V_11 )
{
int V_13 ;
if ( sscanf ( V_5 , L_3 , & V_13 ) != 1 || V_13 >= V_51 / 1000 ||
V_13 <= - V_51 / 1000 )
return - V_14 ;
F_36 ( V_2 , V_13 * 1000 ) ;
return V_11 ;
}
static void F_37 ( void )
{
static int V_52 ;
if ( ! V_52 ) {
V_52 = 1 ;
F_38 ( V_53 L_17
L_18 ) ;
}
}
static T_1 F_39 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_54 = V_55 ;
F_37 () ;
if ( V_7 -> V_33 != V_47 && ! V_7 -> V_2 . V_49 . V_56 )
V_54 = V_57 ;
return sprintf ( V_5 , L_2 , V_54 ) ;
}
static T_1 F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_58 = V_11 ;
char * V_59 ;
int V_10 = V_11 ;
F_37 () ;
V_59 = memchr ( V_5 , '\n' , V_11 ) ;
if ( V_59 )
V_58 = V_59 - V_5 ;
F_3 ( V_7 ) ;
if ( V_58 == sizeof V_57 - 1 &&
strncmp ( V_5 , V_57 , V_58 ) == 0 )
F_41 ( V_7 ) ;
else if ( V_58 == sizeof V_55 - 1 &&
strncmp ( V_5 , V_55 , V_58 ) == 0 )
F_42 ( V_7 ) ;
else
V_10 = - V_14 ;
F_5 ( V_7 ) ;
return V_10 ;
}
static T_1 F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_54 ;
if ( V_7 -> V_60 == 1 )
V_54 = L_19 ;
else
V_54 = L_20 ;
return sprintf ( V_5 , L_2 , V_54 ) ;
}
static T_1 F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
bool V_13 ;
int V_61 ;
F_3 ( V_7 ) ;
V_61 = F_45 ( V_5 , & V_13 ) ;
if ( ! V_61 ) {
V_7 -> V_60 = V_13 ;
V_61 = F_46 ( V_7 , V_13 ) ;
}
F_5 ( V_7 ) ;
if ( ! V_61 )
return V_11 ;
return V_61 ;
}
static T_1 F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_9 , V_7 -> V_62 . V_63 ) ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_63 ;
if ( F_49 ( V_5 , 0 , & V_63 ) )
return - V_14 ;
V_7 -> V_62 . V_63 = V_63 ;
return V_11 ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_9 , V_7 -> V_62 . V_64 ) ;
}
static T_1 F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_4 V_64 ;
if ( F_52 ( V_5 , 0 , & V_64 ) || V_64 > 15 )
return - V_14 ;
V_7 -> V_62 . V_64 = V_64 ;
return V_11 ;
}
static T_1 F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_54 ;
F_3 ( V_7 ) ;
if ( V_7 -> V_65 )
V_54 = L_19 ;
else
V_54 = L_20 ;
F_5 ( V_7 ) ;
return sprintf ( V_5 , L_2 , V_54 ) ;
}
static T_1 F_54 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_54 ;
F_3 ( V_7 ) ;
if ( V_7 -> V_66 )
V_54 = L_19 ;
else
V_54 = L_20 ;
F_5 ( V_7 ) ;
return sprintf ( V_5 , L_2 , V_54 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
if ( F_27 ( V_2 ) ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_10 = F_56 ( & V_2 -> V_41 , & V_67 ) ;
if ( V_7 -> V_68 == 1 )
V_10 = F_56 ( & V_2 -> V_41 ,
& V_69 ) ;
if ( V_7 -> V_15 == V_21 &&
V_7 -> V_70 == 1 )
V_10 = F_56 ( & V_2 -> V_41 ,
& V_71 ) ;
}
return V_10 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_58 ( & V_2 -> V_41 , & V_69 ) ;
F_58 ( & V_2 -> V_41 , & V_67 ) ;
}
static T_1 F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_72 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_73 , L_16 , V_72 -> V_74 ) ;
}
static T_1 F_60 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 ,
T_2 V_75 )
{
T_1 V_76 ;
struct V_6 * V_72 = F_2 ( V_2 ) ;
unsigned V_31 ;
V_76 = sscanf ( V_5 , L_16 , & V_31 ) ;
if ( V_76 != 1 )
V_76 = - V_14 ;
else if ( V_31 == 0 )
V_76 = F_61 ( V_72 ) ;
else
V_76 = F_62 ( V_72 ) ;
return V_76 < 0 ? V_76 : V_75 ;
}
static T_1 F_63 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 = 0 ;
F_3 ( V_7 ) ;
if ( V_7 -> V_33 != V_77 ) {
F_8 ( V_7 , - 1 ) ;
V_10 = F_64 ( V_7 ) ;
}
if ( V_10 == 0 )
V_10 = V_11 ;
F_5 ( V_7 ) ;
return V_10 ;
}
static T_5 F_65 ( struct V_78 * V_41 ,
struct V_79 * V_80 , int V_81 )
{
struct V_1 * V_2 = F_66 ( V_41 , struct V_1 , V_41 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_80 == & V_82 . V_4 ) {
if ( V_7 -> V_83 == NULL )
return 0 ;
} else if ( V_80 == & V_84 . V_4 ) {
if ( V_7 -> V_85 == NULL )
return 0 ;
} else if ( V_80 == & V_86 . V_4 ) {
if ( V_7 -> V_87 == NULL )
return 0 ;
}
return V_80 -> V_88 ;
}
static T_1
F_67 ( struct V_89 * V_90 , struct V_78 * V_41 ,
struct V_91 * V_4 ,
char * V_5 , T_6 V_92 , T_2 V_11 )
{
struct V_1 * V_2 = F_66 ( V_41 , struct V_1 , V_41 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_93 = V_11 ;
T_2 V_94 , V_81 ;
int V_95 ;
void * V_96 ;
F_3 ( V_7 ) ;
for ( V_95 = - 1 ; V_95 < V_7 -> V_27 . V_97 &&
V_93 > 0 ; ++ V_95 ) {
if ( V_95 < 0 ) {
V_96 = & V_7 -> V_27 ;
V_94 = sizeof( struct V_98 ) ;
} else {
V_96 = V_7 -> V_99 [ V_95 ] ;
V_94 = F_68 ( V_7 -> V_12 [ V_95 ] . V_100 .
V_101 ) ;
}
if ( V_92 < V_94 ) {
V_81 = F_69 ( V_93 , V_94 - ( T_2 ) V_92 ) ;
memcpy ( V_5 , V_96 + V_92 , V_81 ) ;
V_93 -= V_81 ;
V_5 += V_81 ;
V_92 = 0 ;
} else {
V_92 -= V_94 ;
}
}
F_5 ( V_7 ) ;
return V_11 - V_93 ;
}
int F_70 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
int V_102 ;
V_102 = F_71 ( V_2 , & V_103 ) ;
if ( V_102 )
goto error;
V_102 = F_26 ( V_2 ) ;
if ( V_102 )
goto error;
V_102 = F_55 ( V_2 ) ;
if ( V_102 )
goto error;
return V_102 ;
error:
F_72 ( V_7 ) ;
return V_102 ;
}
void F_72 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
F_57 ( V_2 ) ;
F_29 ( V_2 ) ;
F_73 ( V_2 , & V_103 ) ;
}
static T_1 F_74 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_104 * V_105 ;
char * string ;
V_105 = F_75 ( V_2 ) ;
string = F_76 ( V_105 -> V_106 -> string ) ;
if ( ! string )
return 0 ;
return sprintf ( V_5 , L_2 , string ) ;
}
static T_1 F_77 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_104 * V_105 ;
struct V_6 * V_7 ;
struct V_107 * V_108 ;
V_105 = F_75 ( V_2 ) ;
V_7 = F_78 ( V_105 ) ;
V_108 = F_76 ( V_105 -> V_106 ) ;
return sprintf ( V_5 , L_21
L_22 ,
F_14 ( V_7 -> V_27 . V_109 ) ,
F_14 ( V_7 -> V_27 . V_110 ) ,
F_14 ( V_7 -> V_27 . V_111 ) ,
V_7 -> V_27 . V_38 ,
V_7 -> V_27 . V_112 ,
V_7 -> V_27 . V_113 ,
V_108 -> V_100 . V_114 ,
V_108 -> V_100 . V_115 ,
V_108 -> V_100 . V_116 ,
V_108 -> V_100 . V_117 ) ;
}
static T_1 F_79 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_118 ;
F_80 ( V_2 ) ;
V_118 = ( ! V_2 -> V_119 || F_81 ( V_2 -> V_119 ) -> V_120 ) ;
F_82 ( V_2 ) ;
return sprintf ( V_5 , L_16 , V_118 ) ;
}
static T_1 F_83 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_104 * V_105 = F_75 ( V_2 ) ;
return sprintf ( V_5 , L_16 , V_105 -> V_74 ) ;
}
static T_1 F_84 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_11 )
{
struct V_104 * V_105 = F_75 ( V_2 ) ;
bool V_31 ;
if ( F_45 ( V_5 , & V_31 ) != 0 )
return - V_14 ;
if ( V_31 )
F_85 ( V_105 ) ;
else
F_86 ( V_105 ) ;
return V_11 ;
}
static T_5 F_87 ( struct V_78 * V_41 ,
struct V_79 * V_80 , int V_81 )
{
struct V_1 * V_2 = F_66 ( V_41 , struct V_1 , V_41 ) ;
struct V_104 * V_105 = F_75 ( V_2 ) ;
if ( V_105 -> V_121 == NULL )
return 0 ;
return V_80 -> V_88 ;
}
void F_88 ( struct V_104 * V_105 )
{
struct V_6 * V_7 = F_78 ( V_105 ) ;
struct V_107 * V_108 = V_105 -> V_106 ;
if ( V_105 -> V_122 || V_105 -> V_123 )
return;
if ( ! V_108 -> string && ! ( V_7 -> V_29 & V_124 ) )
V_108 -> string = F_89 ( V_7 , V_108 -> V_100 . V_125 ) ;
if ( V_108 -> string && F_90 ( & V_105 -> V_2 , & V_126 ) )
;
V_105 -> V_122 = 1 ;
}
void F_91 ( struct V_104 * V_105 )
{
if ( ! V_105 -> V_122 )
return;
F_92 ( & V_105 -> V_2 , & V_126 ) ;
V_105 -> V_122 = 0 ;
}
