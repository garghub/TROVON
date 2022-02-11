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
static int F_54 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
if ( F_27 ( V_2 ) ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_10 = F_55 ( & V_2 -> V_41 , & V_66 ) ;
if ( V_7 -> V_67 == 1 )
V_10 = F_55 ( & V_2 -> V_41 ,
& V_68 ) ;
if ( V_7 -> V_69 == 1 )
V_10 = F_55 ( & V_2 -> V_41 ,
& V_70 ) ;
}
return V_10 ;
}
static void F_56 ( struct V_1 * V_2 )
{
F_57 ( & V_2 -> V_41 , & V_68 ) ;
F_57 ( & V_2 -> V_41 , & V_66 ) ;
}
static T_1 F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_71 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_72 , L_16 , V_71 -> V_73 ) ;
}
static T_1 F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 ,
T_2 V_74 )
{
T_1 V_75 ;
struct V_6 * V_71 = F_2 ( V_2 ) ;
unsigned V_31 ;
V_75 = sscanf ( V_5 , L_16 , & V_31 ) ;
if ( V_75 != 1 )
V_75 = - V_14 ;
else if ( V_31 == 0 )
V_75 = F_60 ( V_71 ) ;
else
V_75 = F_61 ( V_71 ) ;
return V_75 < 0 ? V_75 : V_74 ;
}
static T_1 F_62 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 = 0 ;
F_3 ( V_7 ) ;
if ( V_7 -> V_33 != V_76 ) {
F_8 ( V_7 , - 1 ) ;
V_10 = F_63 ( V_7 ) ;
}
if ( V_10 == 0 )
V_10 = V_11 ;
F_5 ( V_7 ) ;
return V_10 ;
}
static T_5 F_64 ( struct V_77 * V_41 ,
struct V_78 * V_79 , int V_80 )
{
struct V_1 * V_2 = F_65 ( V_41 , struct V_1 , V_41 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_79 == & V_81 . V_4 ) {
if ( V_7 -> V_82 == NULL )
return 0 ;
} else if ( V_79 == & V_83 . V_4 ) {
if ( V_7 -> V_84 == NULL )
return 0 ;
} else if ( V_79 == & V_85 . V_4 ) {
if ( V_7 -> V_86 == NULL )
return 0 ;
}
return V_79 -> V_87 ;
}
static T_1
F_66 ( struct V_88 * V_89 , struct V_77 * V_41 ,
struct V_90 * V_4 ,
char * V_5 , T_6 V_91 , T_2 V_11 )
{
struct V_1 * V_2 = F_65 ( V_41 , struct V_1 , V_41 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_92 = V_11 ;
T_2 V_93 , V_80 ;
int V_94 ;
void * V_95 ;
F_3 ( V_7 ) ;
for ( V_94 = - 1 ; V_94 < V_7 -> V_27 . V_96 &&
V_92 > 0 ; ++ V_94 ) {
if ( V_94 < 0 ) {
V_95 = & V_7 -> V_27 ;
V_93 = sizeof( struct V_97 ) ;
} else {
V_95 = V_7 -> V_98 [ V_94 ] ;
V_93 = F_67 ( V_7 -> V_12 [ V_94 ] . V_99 .
V_100 ) ;
}
if ( V_91 < V_93 ) {
V_80 = F_68 ( V_92 , V_93 - ( T_2 ) V_91 ) ;
memcpy ( V_5 , V_95 + V_91 , V_80 ) ;
V_92 -= V_80 ;
V_5 += V_80 ;
V_91 = 0 ;
} else {
V_91 -= V_93 ;
}
}
F_5 ( V_7 ) ;
return V_11 - V_92 ;
}
int F_69 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
int V_101 ;
V_101 = F_70 ( V_2 , & V_102 ) ;
if ( V_101 )
goto error;
V_101 = F_26 ( V_2 ) ;
if ( V_101 )
goto error;
V_101 = F_54 ( V_2 ) ;
if ( V_101 )
goto error;
return V_101 ;
error:
F_71 ( V_7 ) ;
return V_101 ;
}
void F_71 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
F_56 ( V_2 ) ;
F_29 ( V_2 ) ;
F_72 ( V_2 , & V_102 ) ;
}
static T_1 F_73 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_103 * V_104 ;
char * string ;
V_104 = F_74 ( V_2 ) ;
string = F_75 ( V_104 -> V_105 -> string ) ;
if ( ! string )
return 0 ;
return sprintf ( V_5 , L_2 , string ) ;
}
static T_1 F_76 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_103 * V_104 ;
struct V_6 * V_7 ;
struct V_106 * V_107 ;
V_104 = F_74 ( V_2 ) ;
V_7 = F_77 ( V_104 ) ;
V_107 = F_75 ( V_104 -> V_105 ) ;
return sprintf ( V_5 , L_21
L_22 ,
F_14 ( V_7 -> V_27 . V_108 ) ,
F_14 ( V_7 -> V_27 . V_109 ) ,
F_14 ( V_7 -> V_27 . V_110 ) ,
V_7 -> V_27 . V_38 ,
V_7 -> V_27 . V_111 ,
V_7 -> V_27 . V_112 ,
V_107 -> V_99 . V_113 ,
V_107 -> V_99 . V_114 ,
V_107 -> V_99 . V_115 ,
V_107 -> V_99 . V_116 ) ;
}
static T_1 F_78 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_117 ;
F_79 ( V_2 ) ;
V_117 = ( ! V_2 -> V_118 || F_80 ( V_2 -> V_118 ) -> V_119 ) ;
F_81 ( V_2 ) ;
return sprintf ( V_5 , L_16 , V_117 ) ;
}
static T_1 F_82 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_103 * V_104 = F_74 ( V_2 ) ;
return sprintf ( V_5 , L_16 , V_104 -> V_73 ) ;
}
static T_1 F_83 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_11 )
{
struct V_103 * V_104 = F_74 ( V_2 ) ;
bool V_31 ;
if ( F_45 ( V_5 , & V_31 ) != 0 )
return - V_14 ;
if ( V_31 )
F_84 ( V_104 ) ;
else
F_85 ( V_104 ) ;
return V_11 ;
}
static T_5 F_86 ( struct V_77 * V_41 ,
struct V_78 * V_79 , int V_80 )
{
struct V_1 * V_2 = F_65 ( V_41 , struct V_1 , V_41 ) ;
struct V_103 * V_104 = F_74 ( V_2 ) ;
if ( V_104 -> V_120 == NULL )
return 0 ;
return V_79 -> V_87 ;
}
void F_87 ( struct V_103 * V_104 )
{
struct V_6 * V_7 = F_77 ( V_104 ) ;
struct V_106 * V_107 = V_104 -> V_105 ;
if ( V_104 -> V_121 || V_104 -> V_122 )
return;
if ( ! V_107 -> string && ! ( V_7 -> V_29 & V_123 ) )
V_107 -> string = F_88 ( V_7 , V_107 -> V_99 . V_124 ) ;
if ( V_107 -> string && F_89 ( & V_104 -> V_2 , & V_125 ) )
;
V_104 -> V_121 = 1 ;
}
void F_90 ( struct V_103 * V_104 )
{
if ( ! V_104 -> V_121 )
return;
F_91 ( & V_104 -> V_2 , & V_125 ) ;
V_104 -> V_121 = 0 ;
}
