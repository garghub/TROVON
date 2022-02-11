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
struct V_16 * V_17 = V_2 -> V_17 ;
return sprintf ( V_5 , L_2 , F_10 ( V_17 ) ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
char * V_18 ;
V_7 = F_2 ( V_2 ) ;
switch ( V_7 -> V_18 ) {
case V_19 :
V_18 = L_4 ;
break;
case V_20 :
case V_21 :
V_18 = L_5 ;
break;
case V_22 :
V_18 = L_6 ;
break;
case V_23 :
V_18 = L_6 ;
break;
case V_24 :
V_18 = L_7 ;
break;
case V_25 :
V_18 = L_8 ;
break;
default:
V_18 = L_9 ;
}
return sprintf ( V_5 , L_2 , V_18 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , V_7 -> V_26 -> V_27 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , V_7 -> V_28 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_29 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
T_3 V_30 ;
V_7 = F_2 ( V_2 ) ;
V_30 = F_16 ( V_7 -> V_31 . V_30 ) ;
return sprintf ( V_5 , L_11 , V_30 >> 8 , V_30 & 0xff ) ;
}
static T_1 F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , V_7 -> V_32 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_12 , V_7 -> V_33 ) ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , ! ! ( V_7 -> V_33 & V_34 ) ) ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_35 , V_10 ;
if ( sscanf ( V_5 , L_3 , & V_35 ) != 1 || V_35 < 0 || V_35 > 1 )
return - V_15 ;
V_10 = F_3 ( V_7 ) ;
if ( V_10 < 0 )
return - V_11 ;
if ( V_35 )
V_7 -> V_33 |= V_34 ;
else
V_7 -> V_33 &= ~ V_34 ;
F_5 ( V_7 ) ;
return V_12 ;
}
static T_1 F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , F_22 ( & V_7 -> V_36 ) ) ;
}
static T_1 F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
char * V_37 ;
V_7 = F_2 ( V_2 ) ;
switch ( V_7 -> V_38 ) {
case V_39 :
V_37 = L_13 ;
break;
case V_40 :
V_37 = L_14 ;
break;
default:
V_37 = L_9 ;
}
return sprintf ( V_5 , L_2 , V_37 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
if ( F_25 ( F_2 ( V_2 ) ) )
return sprintf ( V_5 , L_2 , L_15 ) ;
return sprintf ( V_5 , L_2 , L_16 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , V_7 -> V_41 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_14 , V_10 ;
if ( V_7 -> V_31 . V_42 == V_43 )
return - V_44 ;
if ( sscanf ( V_5 , L_3 , & V_14 ) != 1 )
return - V_15 ;
V_10 = F_3 ( V_7 ) ;
if ( V_10 < 0 )
return - V_11 ;
V_7 -> V_41 = ! ! V_14 ;
F_5 ( V_7 ) ;
return V_12 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
if ( F_29 ( V_2 ) ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_31 . V_42 != V_43 )
V_10 = F_30 ( & V_2 -> V_45 ,
& V_46 . V_4 ,
V_47 ) ;
}
return V_10 ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_45 ,
& V_46 . V_4 ,
V_47 ) ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_17 ,
F_34 ( V_48 - V_7 -> V_49 ) ) ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_50 ;
if ( V_7 -> V_37 != V_51 )
V_50 = F_34 ( V_48 + V_7 -> V_52 ) ;
else
V_50 = F_34 ( V_7 -> V_52 ) ;
return sprintf ( V_5 , L_17 , V_50 ) ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_10 , V_2 -> V_53 . V_54 / 1000 ) ;
}
static T_1 F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 ,
T_2 V_12 )
{
int V_14 ;
if ( sscanf ( V_5 , L_3 , & V_14 ) != 1 || V_14 >= V_55 / 1000 ||
V_14 <= - V_55 / 1000 )
return - V_15 ;
F_38 ( V_2 , V_14 * 1000 ) ;
return V_12 ;
}
static void F_39 ( void )
{
static int V_56 ;
if ( ! V_56 ) {
V_56 = 1 ;
F_40 ( V_57 L_18
L_19 ) ;
}
}
static T_1 F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_58 = V_59 ;
F_39 () ;
if ( V_7 -> V_37 != V_51 && ! V_7 -> V_2 . V_53 . V_60 )
V_58 = V_61 ;
return sprintf ( V_5 , L_2 , V_58 ) ;
}
static T_1 F_42 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_62 = V_12 ;
char * V_63 ;
int V_10 = V_12 ;
int V_64 ;
F_39 () ;
V_63 = memchr ( V_5 , '\n' , V_12 ) ;
if ( V_63 )
V_62 = V_63 - V_5 ;
V_64 = F_3 ( V_7 ) ;
if ( V_64 < 0 )
return - V_11 ;
if ( V_62 == sizeof V_61 - 1 &&
strncmp ( V_5 , V_61 , V_62 ) == 0 )
F_43 ( V_7 ) ;
else if ( V_62 == sizeof V_59 - 1 &&
strncmp ( V_5 , V_59 , V_62 ) == 0 )
F_44 ( V_7 ) ;
else
V_10 = - V_15 ;
F_5 ( V_7 ) ;
return V_10 ;
}
static T_1 F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_58 ;
if ( V_7 -> V_65 == 1 )
V_58 = L_20 ;
else
V_58 = L_21 ;
return sprintf ( V_5 , L_2 , V_58 ) ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
bool V_14 ;
int V_66 ;
V_66 = F_3 ( V_7 ) ;
if ( V_66 < 0 )
return - V_11 ;
V_66 = F_47 ( V_5 , & V_14 ) ;
if ( ! V_66 ) {
V_7 -> V_65 = V_14 ;
V_66 = F_48 ( V_7 , V_14 ) ;
}
F_5 ( V_7 ) ;
if ( ! V_66 )
return V_12 ;
return V_66 ;
}
static T_1 F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , V_7 -> V_67 . V_68 ) ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_3 V_68 ;
if ( F_51 ( V_5 , 0 , & V_68 ) )
return - V_15 ;
V_7 -> V_67 . V_68 = V_68 ;
return V_12 ;
}
static T_1 F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , V_7 -> V_67 . V_69 ) ;
}
static T_1 F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_4 V_69 ;
if ( F_54 ( V_5 , 0 , & V_69 ) || V_69 > 15 )
return - V_15 ;
V_7 -> V_67 . V_69 = V_69 ;
return V_12 ;
}
static T_1 F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_58 ;
int V_10 ;
V_10 = F_3 ( V_7 ) ;
if ( V_10 < 0 )
return - V_11 ;
if ( V_7 -> V_70 )
V_58 = L_20 ;
else
V_58 = L_21 ;
F_5 ( V_7 ) ;
return sprintf ( V_5 , L_2 , V_58 ) ;
}
static T_1 F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_58 ;
int V_10 ;
V_10 = F_3 ( V_7 ) ;
if ( V_10 < 0 )
return - V_11 ;
if ( V_7 -> V_71 )
V_58 = L_20 ;
else
V_58 = L_21 ;
F_5 ( V_7 ) ;
return sprintf ( V_5 , L_2 , V_58 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
if ( F_29 ( V_2 ) ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_10 = F_58 ( & V_2 -> V_45 , & V_72 ) ;
if ( V_7 -> V_73 == 1 )
V_10 = F_58 ( & V_2 -> V_45 ,
& V_74 ) ;
if ( V_7 -> V_18 == V_24 &&
V_7 -> V_75 == 1 )
V_10 = F_58 ( & V_2 -> V_45 ,
& V_76 ) ;
}
return V_10 ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_60 ( & V_2 -> V_45 , & V_74 ) ;
F_60 ( & V_2 -> V_45 , & V_72 ) ;
}
static T_1 F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_77 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_78 , L_17 , V_77 -> V_79 ) ;
}
static T_1 F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 ,
T_2 V_80 )
{
T_1 V_81 ;
struct V_6 * V_77 = F_2 ( V_2 ) ;
unsigned V_35 ;
V_81 = sscanf ( V_5 , L_17 , & V_35 ) ;
if ( V_81 != 1 )
V_81 = - V_15 ;
else if ( V_35 == 0 )
V_81 = F_63 ( V_77 ) ;
else
V_81 = F_64 ( V_77 ) ;
return V_81 < 0 ? V_81 : V_80 ;
}
static T_1 F_65 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 = 0 ;
F_66 ( V_7 ) ;
if ( V_7 -> V_37 != V_82 ) {
F_8 ( V_7 , - 1 ) ;
V_10 = F_67 ( V_7 ) ;
}
if ( V_10 == 0 )
V_10 = V_12 ;
F_5 ( V_7 ) ;
return V_10 ;
}
static T_5 F_68 ( struct V_83 * V_45 ,
struct V_84 * V_85 , int V_86 )
{
struct V_1 * V_2 = F_69 ( V_45 , struct V_1 , V_45 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_85 == & V_87 . V_4 ) {
if ( V_7 -> V_88 == NULL )
return 0 ;
} else if ( V_85 == & V_89 . V_4 ) {
if ( V_7 -> V_90 == NULL )
return 0 ;
} else if ( V_85 == & V_91 . V_4 ) {
if ( V_7 -> V_92 == NULL )
return 0 ;
}
return V_85 -> V_93 ;
}
static T_1
F_70 ( struct V_94 * V_95 , struct V_83 * V_45 ,
struct V_96 * V_4 ,
char * V_5 , T_6 V_97 , T_2 V_12 )
{
struct V_1 * V_2 = F_69 ( V_45 , struct V_1 , V_45 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_98 = V_12 ;
T_2 V_99 , V_86 ;
int V_100 ;
void * V_101 ;
for ( V_100 = - 1 ; V_100 < V_7 -> V_31 . V_102 &&
V_98 > 0 ; ++ V_100 ) {
if ( V_100 < 0 ) {
V_101 = & V_7 -> V_31 ;
V_99 = sizeof( struct V_103 ) ;
} else {
V_101 = V_7 -> V_104 [ V_100 ] ;
V_99 = F_71 ( V_7 -> V_13 [ V_100 ] . V_105 .
V_106 ) ;
}
if ( V_97 < V_99 ) {
V_86 = F_72 ( V_98 , V_99 - ( T_2 ) V_97 ) ;
memcpy ( V_5 , V_101 + V_97 , V_86 ) ;
V_98 -= V_86 ;
V_5 += V_86 ;
V_97 = 0 ;
} else {
V_97 -= V_99 ;
}
}
return V_12 - V_98 ;
}
int F_73 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
int V_107 ;
V_107 = F_74 ( V_2 , & V_108 ) ;
if ( V_107 )
goto error;
V_107 = F_28 ( V_2 ) ;
if ( V_107 )
goto error;
V_107 = F_57 ( V_2 ) ;
if ( V_107 )
goto error;
return V_107 ;
error:
F_75 ( V_7 ) ;
return V_107 ;
}
void F_75 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
F_59 ( V_2 ) ;
F_31 ( V_2 ) ;
F_76 ( V_2 , & V_108 ) ;
}
static T_1 F_77 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_109 * V_110 ;
char * string ;
V_110 = F_78 ( V_2 ) ;
string = F_79 ( V_110 -> V_111 -> string ) ;
if ( ! string )
return 0 ;
return sprintf ( V_5 , L_2 , string ) ;
}
static T_1 F_80 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_109 * V_110 ;
struct V_6 * V_7 ;
struct V_112 * V_113 ;
V_110 = F_78 ( V_2 ) ;
V_7 = F_81 ( V_110 ) ;
V_113 = F_79 ( V_110 -> V_111 ) ;
return sprintf ( V_5 , L_22
L_23 ,
F_16 ( V_7 -> V_31 . V_114 ) ,
F_16 ( V_7 -> V_31 . V_115 ) ,
F_16 ( V_7 -> V_31 . V_116 ) ,
V_7 -> V_31 . V_42 ,
V_7 -> V_31 . V_117 ,
V_7 -> V_31 . V_118 ,
V_113 -> V_105 . V_119 ,
V_113 -> V_105 . V_120 ,
V_113 -> V_105 . V_121 ,
V_113 -> V_105 . V_122 ) ;
}
static T_1 F_82 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_123 ;
V_123 = F_83 ( V_2 ) ;
if ( V_123 < 0 )
return - V_11 ;
V_123 = ( ! V_2 -> V_124 || F_84 ( V_2 -> V_124 ) -> V_125 ) ;
F_85 ( V_2 ) ;
return sprintf ( V_5 , L_17 , V_123 ) ;
}
static T_1 F_86 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_109 * V_110 = F_78 ( V_2 ) ;
return sprintf ( V_5 , L_17 , V_110 -> V_79 ) ;
}
static T_1 F_87 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_12 )
{
struct V_109 * V_110 = F_78 ( V_2 ) ;
bool V_35 ;
if ( F_47 ( V_5 , & V_35 ) != 0 )
return - V_15 ;
if ( V_35 )
F_88 ( V_110 ) ;
else
F_89 ( V_110 ) ;
return V_12 ;
}
static T_5 F_90 ( struct V_83 * V_45 ,
struct V_84 * V_85 , int V_86 )
{
struct V_1 * V_2 = F_69 ( V_45 , struct V_1 , V_45 ) ;
struct V_109 * V_110 = F_78 ( V_2 ) ;
if ( V_110 -> V_126 == NULL )
return 0 ;
return V_85 -> V_93 ;
}
void F_91 ( struct V_109 * V_110 )
{
struct V_6 * V_7 = F_81 ( V_110 ) ;
struct V_112 * V_113 = V_110 -> V_111 ;
if ( V_110 -> V_127 || V_110 -> V_128 )
return;
if ( ! V_113 -> string && ! ( V_7 -> V_33 & V_129 ) )
V_113 -> string = F_92 ( V_7 , V_113 -> V_105 . V_130 ) ;
if ( V_113 -> string && F_93 ( & V_110 -> V_2 , & V_131 ) )
;
V_110 -> V_127 = 1 ;
}
void F_94 ( struct V_109 * V_110 )
{
if ( ! V_110 -> V_127 )
return;
F_95 ( & V_110 -> V_2 , & V_131 ) ;
V_110 -> V_127 = 0 ;
}
