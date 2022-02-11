static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_2 ( V_2 ) ;
V_9 = V_7 -> V_9 ;
if ( ! V_9 )
return 0 ;
return sprintf ( V_5 , L_1 , F_3 ( V_7 , V_9 ) ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_2 ( V_2 ) ;
V_9 = V_7 -> V_9 ;
if ( ( ! V_9 ) || ( ! V_9 -> string ) )
return 0 ;
return sprintf ( V_5 , L_2 , V_9 -> string ) ;
}
static T_1
F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_11 , V_12 ;
if ( sscanf ( V_5 , L_3 , & V_11 ) != 1 || V_11 < - 1 || V_11 > 255 )
return - V_13 ;
F_6 ( V_7 ) ;
V_12 = F_7 ( V_7 , V_11 ) ;
F_8 ( V_7 ) ;
return ( V_12 < 0 ) ? V_12 : V_10 ;
}
static T_1
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
char * V_14 ;
V_7 = F_2 ( V_2 ) ;
switch ( V_7 -> V_14 ) {
case V_15 :
V_14 = L_4 ;
break;
case V_16 :
case V_17 :
V_14 = L_5 ;
break;
case V_18 :
V_14 = L_6 ;
break;
case V_19 :
V_14 = L_6 ;
break;
case V_20 :
V_14 = L_7 ;
break;
default:
V_14 = L_8 ;
}
return sprintf ( V_5 , L_2 , V_14 ) ;
}
static T_1
F_10 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_9 , V_7 -> V_21 -> V_22 ) ;
}
static T_1
F_11 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_9 , V_7 -> V_23 ) ;
}
static T_1
F_12 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_24 ) ;
}
static T_1
F_13 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
T_3 V_25 ;
V_7 = F_2 ( V_2 ) ;
V_25 = F_14 ( V_7 -> V_26 . V_25 ) ;
return sprintf ( V_5 , L_10 , V_25 >> 8 , V_25 & 0xff ) ;
}
static T_1
F_15 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_9 , V_7 -> V_27 ) ;
}
static T_1
F_16 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_11 , V_7 -> V_28 ) ;
}
static T_1
F_17 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_9 , ! ! ( V_7 -> V_28 & V_29 ) ) ;
}
static T_1
F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_30 ;
if ( sscanf ( V_5 , L_3 , & V_30 ) != 1 || V_30 < 0 || V_30 > 1 )
return - V_13 ;
F_6 ( V_7 ) ;
if ( V_30 )
V_7 -> V_28 |= V_29 ;
else
V_7 -> V_28 &= ~ V_29 ;
F_8 ( V_7 ) ;
return V_10 ;
}
static T_1
F_19 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_9 , F_20 ( & V_7 -> V_31 ) ) ;
}
static T_1
F_21 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
char * V_32 ;
V_7 = F_2 ( V_2 ) ;
switch ( V_7 -> V_33 ) {
case V_34 :
V_32 = L_12 ;
break;
case V_35 :
V_32 = L_13 ;
break;
default:
V_32 = L_8 ;
}
return sprintf ( V_5 , L_2 , V_32 ) ;
}
static T_1
F_22 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
if ( F_23 ( F_2 ( V_2 ) ) )
return sprintf ( V_5 , L_2 , L_14 ) ;
return sprintf ( V_5 , L_2 , L_15 ) ;
}
static T_1
F_24 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_9 , V_7 -> V_36 ) ;
}
static T_1
F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_12 ;
if ( V_7 -> V_26 . V_37 == V_38 )
return - V_39 ;
if ( sscanf ( V_5 , L_3 , & V_12 ) != 1 )
return - V_13 ;
F_6 ( V_7 ) ;
V_7 -> V_36 = ! ! V_12 ;
F_8 ( V_7 ) ;
return V_10 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_40 = 0 ;
if ( F_27 ( V_2 ) ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_26 . V_37 != V_38 )
V_40 = F_28 ( & V_2 -> V_41 ,
& V_42 . V_4 ,
V_43 ) ;
}
return V_40 ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_41 ,
& V_42 . V_4 ,
V_43 ) ;
}
static T_1
F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_16 ,
F_32 ( V_44 - V_7 -> V_45 ) ) ;
}
static T_1
F_33 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_46 ;
if ( V_7 -> V_32 != V_47 )
V_46 = F_32 ( V_44 + V_7 -> V_48 ) ;
else
V_46 = F_32 ( V_7 -> V_48 ) ;
return sprintf ( V_5 , L_16 , V_46 ) ;
}
static T_1
F_34 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_9 , V_2 -> V_49 . V_50 / 1000 ) ;
}
static T_1
F_35 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
int V_12 ;
if ( sscanf ( V_5 , L_3 , & V_12 ) != 1 || V_12 >= V_51 / 1000 ||
V_12 <= - V_51 / 1000 )
return - V_13 ;
F_36 ( V_2 , V_12 * 1000 ) ;
return V_10 ;
}
static void F_37 ( void ) {
static int V_52 ;
if ( ! V_52 ) {
V_52 = 1 ;
F_38 ( V_53 L_17
L_18 ) ;
}
}
static T_1
F_39 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_54 = V_55 ;
F_37 () ;
if ( V_7 -> V_32 != V_47 && ! V_7 -> V_2 . V_49 . V_56 )
V_54 = V_57 ;
return sprintf ( V_5 , L_2 , V_54 ) ;
}
static T_1
F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_58 = V_10 ;
char * V_59 ;
int V_40 = V_10 ;
F_37 () ;
V_59 = memchr ( V_5 , '\n' , V_10 ) ;
if ( V_59 )
V_58 = V_59 - V_5 ;
F_6 ( V_7 ) ;
if ( V_58 == sizeof V_57 - 1 &&
strncmp ( V_5 , V_57 , V_58 ) == 0 )
F_41 ( V_7 ) ;
else if ( V_58 == sizeof V_55 - 1 &&
strncmp ( V_5 , V_55 , V_58 ) == 0 )
F_42 ( V_7 ) ;
else
V_40 = - V_13 ;
F_8 ( V_7 ) ;
return V_40 ;
}
static T_1
F_43 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_54 ;
if ( V_7 -> V_60 == 1 )
V_54 = L_19 ;
else
V_54 = L_20 ;
return sprintf ( V_5 , L_2 , V_54 ) ;
}
static T_1
F_44 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
bool V_12 ;
int V_61 ;
F_6 ( V_7 ) ;
V_61 = F_45 ( V_5 , & V_12 ) ;
if ( ! V_61 )
V_61 = F_46 ( V_7 , V_12 ) ;
F_8 ( V_7 ) ;
if ( ! V_61 )
return V_10 ;
return V_61 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_40 = 0 ;
if ( F_27 ( V_2 ) ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_40 = F_48 ( & V_2 -> V_41 , & V_62 ) ;
if ( V_7 -> V_63 == 1 )
V_40 = F_48 ( & V_2 -> V_41 ,
& V_64 ) ;
}
return V_40 ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_50 ( & V_2 -> V_41 , & V_64 ) ;
F_50 ( & V_2 -> V_41 , & V_62 ) ;
}
static T_1 F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_65 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_66 , L_16 , V_65 -> V_67 ) ;
}
static T_1 F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_68 )
{
T_1 V_69 ;
struct V_6 * V_65 = F_2 ( V_2 ) ;
unsigned V_30 ;
V_69 = sscanf ( V_5 , L_16 , & V_30 ) ;
if ( V_69 != 1 )
V_69 = - V_13 ;
else if ( V_30 == 0 )
V_69 = F_53 ( V_65 ) ;
else
V_69 = F_54 ( V_65 ) ;
return V_69 < 0 ? V_69 : V_68 ;
}
static T_1 F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_40 = 0 ;
F_6 ( V_7 ) ;
if ( V_7 -> V_32 != V_70 ) {
F_7 ( V_7 , - 1 ) ;
V_40 = F_56 ( V_7 ) ;
}
if ( V_40 == 0 )
V_40 = V_10 ;
F_8 ( V_7 ) ;
return V_40 ;
}
static T_4 F_57 ( struct V_71 * V_41 ,
struct V_72 * V_73 , int V_74 )
{
struct V_1 * V_2 = F_58 ( V_41 , struct V_1 , V_41 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_73 == & V_75 . V_4 ) {
if ( V_7 -> V_76 == NULL )
return 0 ;
} else if ( V_73 == & V_77 . V_4 ) {
if ( V_7 -> V_78 == NULL )
return 0 ;
} else if ( V_73 == & V_79 . V_4 ) {
if ( V_7 -> V_80 == NULL )
return 0 ;
}
return V_73 -> V_81 ;
}
static T_1
F_59 ( struct V_82 * V_83 , struct V_71 * V_41 ,
struct V_84 * V_4 ,
char * V_5 , T_5 V_85 , T_2 V_10 )
{
struct V_1 * V_2 = F_58 ( V_41 , struct V_1 , V_41 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_86 = V_10 ;
T_2 V_87 , V_74 ;
int V_88 ;
void * V_89 ;
for ( V_88 = - 1 ; V_88 < V_7 -> V_26 . V_90 &&
V_86 > 0 ; ++ V_88 ) {
if ( V_88 < 0 ) {
V_89 = & V_7 -> V_26 ;
V_87 = sizeof( struct V_91 ) ;
} else {
V_89 = V_7 -> V_92 [ V_88 ] ;
V_87 = F_60 ( V_7 -> V_11 [ V_88 ] . V_93 .
V_94 ) ;
}
if ( V_85 < V_87 ) {
V_74 = F_61 ( V_86 , V_87 - ( T_2 ) V_85 ) ;
memcpy ( V_5 , V_89 + V_85 , V_74 ) ;
V_86 -= V_74 ;
V_5 += V_74 ;
V_85 = 0 ;
} else {
V_85 -= V_87 ;
}
}
return V_10 - V_86 ;
}
int F_62 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
int V_95 ;
V_95 = F_63 ( V_2 , & V_96 ) ;
if ( V_95 )
goto error;
V_95 = F_26 ( V_2 ) ;
if ( V_95 )
goto error;
V_95 = F_47 ( V_2 ) ;
if ( V_95 )
goto error;
return V_95 ;
error:
F_64 ( V_7 ) ;
return V_95 ;
}
void F_64 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
F_49 ( V_2 ) ;
F_29 ( V_2 ) ;
F_65 ( V_2 , & V_96 ) ;
}
static T_1 F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_97 * V_98 ;
char * string ;
V_98 = F_67 ( V_2 ) ;
string = V_98 -> V_99 -> string ;
F_68 () ;
if ( ! string )
return 0 ;
return sprintf ( V_5 , L_2 , string ) ;
}
static T_1 F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_97 * V_98 ;
struct V_6 * V_7 ;
struct V_100 * V_101 ;
V_98 = F_67 ( V_2 ) ;
V_7 = F_70 ( V_98 ) ;
V_101 = V_98 -> V_99 ;
return sprintf ( V_5 , L_21
L_22 ,
F_14 ( V_7 -> V_26 . V_102 ) ,
F_14 ( V_7 -> V_26 . V_103 ) ,
F_14 ( V_7 -> V_26 . V_104 ) ,
V_7 -> V_26 . V_37 ,
V_7 -> V_26 . V_105 ,
V_7 -> V_26 . V_106 ,
V_101 -> V_93 . V_107 ,
V_101 -> V_93 . V_108 ,
V_101 -> V_93 . V_109 ,
V_101 -> V_93 . V_110 ) ;
}
static T_1 F_71 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_97 * V_98 ;
struct V_6 * V_7 ;
int V_61 ;
V_98 = F_67 ( V_2 ) ;
V_7 = F_70 ( V_98 ) ;
F_6 ( V_7 ) ;
if ( ! V_98 -> V_2 . V_111 ||
F_72 ( V_98 -> V_2 . V_111 ) -> V_112 )
V_61 = sprintf ( V_5 , L_16 , 1 ) ;
else
V_61 = sprintf ( V_5 , L_16 , 0 ) ;
F_8 ( V_7 ) ;
return V_61 ;
}
static T_4 F_73 ( struct V_71 * V_41 ,
struct V_72 * V_73 , int V_74 )
{
struct V_1 * V_2 = F_58 ( V_41 , struct V_1 , V_41 ) ;
struct V_97 * V_98 = F_67 ( V_2 ) ;
if ( V_98 -> V_113 == NULL )
return 0 ;
return V_73 -> V_81 ;
}
void F_74 ( struct V_97 * V_98 )
{
struct V_6 * V_7 = F_70 ( V_98 ) ;
struct V_100 * V_101 = V_98 -> V_99 ;
if ( V_98 -> V_114 || V_98 -> V_115 )
return;
if ( ! V_101 -> string && ! ( V_7 -> V_28 & V_116 ) )
V_101 -> string = F_75 ( V_7 , V_101 -> V_93 . V_117 ) ;
if ( V_101 -> string && F_76 ( & V_98 -> V_2 , & V_118 ) )
;
V_98 -> V_114 = 1 ;
}
void F_77 ( struct V_97 * V_98 )
{
if ( ! V_98 -> V_114 )
return;
F_78 ( & V_98 -> V_2 , & V_118 ) ;
V_98 -> V_114 = 0 ;
}
