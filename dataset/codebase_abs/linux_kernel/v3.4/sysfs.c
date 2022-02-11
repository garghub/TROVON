static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_2 ( V_2 ) ;
V_9 = V_7 -> V_9 ;
if ( ( ! V_9 ) || ( ! V_9 -> string ) )
return 0 ;
return sprintf ( V_5 , L_1 , V_9 -> string ) ;
}
static T_1
F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_11 , V_12 ;
if ( sscanf ( V_5 , L_2 , & V_11 ) != 1 || V_11 < - 1 || V_11 > 255 )
return - V_13 ;
F_4 ( V_7 ) ;
V_12 = F_5 ( V_7 , V_11 ) ;
F_6 ( V_7 ) ;
return ( V_12 < 0 ) ? V_12 : V_10 ;
}
static T_1
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
char * V_14 ;
V_7 = F_2 ( V_2 ) ;
switch ( V_7 -> V_14 ) {
case V_15 :
V_14 = L_3 ;
break;
case V_16 :
case V_17 :
V_14 = L_4 ;
break;
case V_18 :
V_14 = L_5 ;
break;
case V_19 :
V_14 = L_5 ;
break;
case V_20 :
V_14 = L_6 ;
break;
default:
V_14 = L_7 ;
}
return sprintf ( V_5 , L_1 , V_14 ) ;
}
static T_1
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_8 , V_7 -> V_21 -> V_22 ) ;
}
static T_1
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_8 , V_7 -> V_23 ) ;
}
static T_1
F_10 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_24 ) ;
}
static T_1
F_11 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
T_3 V_25 ;
V_7 = F_2 ( V_2 ) ;
V_25 = F_12 ( V_7 -> V_26 . V_25 ) ;
return sprintf ( V_5 , L_9 , V_25 >> 8 , V_25 & 0xff ) ;
}
static T_1
F_13 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_8 , V_7 -> V_27 ) ;
}
static T_1
F_14 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_10 , V_7 -> V_28 ) ;
}
static T_1
F_15 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_8 , ! ! ( V_7 -> V_28 & V_29 ) ) ;
}
static T_1
F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_11 ;
if ( sscanf ( V_5 , L_2 , & V_11 ) != 1 || V_11 < 0 || V_11 > 1 )
return - V_13 ;
F_4 ( V_7 ) ;
if ( V_11 )
V_7 -> V_28 |= V_29 ;
else
V_7 -> V_28 &= ~ V_29 ;
F_6 ( V_7 ) ;
return V_10 ;
}
static T_1
F_17 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_8 , F_18 ( & V_7 -> V_30 ) ) ;
}
static T_1
F_19 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
char * V_31 ;
V_7 = F_2 ( V_2 ) ;
switch ( V_7 -> V_32 ) {
case V_33 :
V_31 = L_11 ;
break;
case V_34 :
V_31 = L_12 ;
break;
default:
V_31 = L_7 ;
}
return sprintf ( V_5 , L_1 , V_31 ) ;
}
static T_1
F_20 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_8 , V_7 -> V_35 ) ;
}
static T_1
F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_12 ;
if ( V_7 -> V_26 . V_36 == V_37 )
return - V_38 ;
if ( sscanf ( V_5 , L_2 , & V_12 ) != 1 )
return - V_13 ;
F_4 ( V_7 ) ;
V_7 -> V_35 = ! ! V_12 ;
F_6 ( V_7 ) ;
return V_10 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_39 = 0 ;
if ( F_23 ( V_2 ) ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_26 . V_36 != V_37 )
V_39 = F_24 ( & V_2 -> V_40 ,
& V_41 . V_4 ,
V_42 ) ;
}
return V_39 ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_40 ,
& V_41 . V_4 ,
V_42 ) ;
}
static T_1
F_27 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_13 ,
F_28 ( V_43 - V_7 -> V_44 ) ) ;
}
static T_1
F_29 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_45 ;
if ( V_7 -> V_31 != V_46 )
V_45 = F_28 ( V_43 + V_7 -> V_47 ) ;
else
V_45 = F_28 ( V_7 -> V_47 ) ;
return sprintf ( V_5 , L_13 , V_45 ) ;
}
static T_1
F_30 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_8 , V_2 -> V_48 . V_49 / 1000 ) ;
}
static T_1
F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
int V_12 ;
if ( sscanf ( V_5 , L_2 , & V_12 ) != 1 || V_12 >= V_50 / 1000 ||
V_12 <= - V_50 / 1000 )
return - V_13 ;
F_32 ( V_2 , V_12 * 1000 ) ;
return V_10 ;
}
static void F_33 ( void ) {
static int V_51 ;
if ( ! V_51 ) {
V_51 = 1 ;
F_34 ( V_52 L_14
L_15 ) ;
}
}
static T_1
F_35 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_53 = V_54 ;
F_33 () ;
if ( V_7 -> V_31 != V_46 && ! V_7 -> V_2 . V_48 . V_55 )
V_53 = V_56 ;
return sprintf ( V_5 , L_1 , V_53 ) ;
}
static T_1
F_36 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_57 = V_10 ;
char * V_58 ;
int V_39 = V_10 ;
F_33 () ;
V_58 = memchr ( V_5 , '\n' , V_10 ) ;
if ( V_58 )
V_57 = V_58 - V_5 ;
F_4 ( V_7 ) ;
if ( V_57 == sizeof V_56 - 1 &&
strncmp ( V_5 , V_56 , V_57 ) == 0 )
F_37 ( V_7 ) ;
else if ( V_57 == sizeof V_54 - 1 &&
strncmp ( V_5 , V_54 , V_57 ) == 0 )
F_38 ( V_7 ) ;
else
V_39 = - V_13 ;
F_6 ( V_7 ) ;
return V_39 ;
}
static T_1
F_39 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_53 ;
if ( V_7 -> V_59 == 1 )
V_53 = L_16 ;
else
V_53 = L_17 ;
return sprintf ( V_5 , L_1 , V_53 ) ;
}
static T_1
F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
bool V_12 ;
int V_60 ;
F_4 ( V_7 ) ;
V_60 = F_41 ( V_5 , & V_12 ) ;
if ( ! V_60 )
V_60 = F_42 ( V_7 , V_12 ) ;
F_6 ( V_7 ) ;
if ( ! V_60 )
return V_10 ;
return V_60 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_39 = 0 ;
if ( F_23 ( V_2 ) ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_39 = F_44 ( & V_2 -> V_40 , & V_61 ) ;
if ( V_7 -> V_62 == 1 )
V_39 = F_44 ( & V_2 -> V_40 ,
& V_63 ) ;
}
return V_39 ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_46 ( & V_2 -> V_40 , & V_63 ) ;
F_46 ( & V_2 -> V_40 , & V_61 ) ;
}
static T_1 F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_64 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_65 , L_13 , V_64 -> V_66 ) ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_67 )
{
T_1 V_68 ;
struct V_6 * V_64 = F_2 ( V_2 ) ;
unsigned V_69 ;
V_68 = sscanf ( V_5 , L_13 , & V_69 ) ;
if ( V_68 != 1 )
V_68 = - V_13 ;
else if ( V_69 == 0 )
V_68 = F_49 ( V_64 ) ;
else
V_68 = F_50 ( V_64 ) ;
return V_68 < 0 ? V_68 : V_67 ;
}
static T_1 F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_39 = 0 ;
F_4 ( V_7 ) ;
if ( V_7 -> V_31 != V_70 ) {
F_5 ( V_7 , - 1 ) ;
V_39 = F_52 ( V_7 ) ;
}
if ( V_39 == 0 )
V_39 = V_10 ;
F_6 ( V_7 ) ;
return V_39 ;
}
static T_4 F_53 ( struct V_71 * V_40 ,
struct V_72 * V_73 , int V_74 )
{
struct V_1 * V_2 = F_54 ( V_40 , struct V_1 , V_40 ) ;
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
F_55 ( struct V_82 * V_83 , struct V_71 * V_40 ,
struct V_84 * V_4 ,
char * V_5 , T_5 V_85 , T_2 V_10 )
{
struct V_1 * V_2 = F_54 ( V_40 , struct V_1 , V_40 ) ;
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
V_87 = F_56 ( V_7 -> V_11 [ V_88 ] . V_93 .
V_94 ) ;
}
if ( V_85 < V_87 ) {
V_74 = F_57 ( V_86 , V_87 - ( T_2 ) V_85 ) ;
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
int F_58 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
int V_95 ;
V_95 = F_59 ( V_2 , & V_96 ) ;
if ( V_95 )
goto error;
V_95 = F_22 ( V_2 ) ;
if ( V_95 )
goto error;
V_95 = F_43 ( V_2 ) ;
if ( V_95 )
goto error;
return V_95 ;
error:
F_60 ( V_7 ) ;
return V_95 ;
}
void F_60 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
F_45 ( V_2 ) ;
F_25 ( V_2 ) ;
F_61 ( V_2 , & V_96 ) ;
}
static T_1 F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_97 * V_98 ;
char * string ;
V_98 = F_63 ( V_2 ) ;
string = V_98 -> V_99 -> string ;
F_64 () ;
if ( ! string )
return 0 ;
return sprintf ( V_5 , L_1 , string ) ;
}
static T_1 F_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_97 * V_98 ;
struct V_6 * V_7 ;
struct V_100 * V_101 ;
V_98 = F_63 ( V_2 ) ;
V_7 = F_66 ( V_98 ) ;
V_101 = V_98 -> V_99 ;
return sprintf ( V_5 , L_18
L_19 ,
F_12 ( V_7 -> V_26 . V_102 ) ,
F_12 ( V_7 -> V_26 . V_103 ) ,
F_12 ( V_7 -> V_26 . V_104 ) ,
V_7 -> V_26 . V_36 ,
V_7 -> V_26 . V_105 ,
V_7 -> V_26 . V_106 ,
V_101 -> V_93 . V_107 ,
V_101 -> V_93 . V_108 ,
V_101 -> V_93 . V_109 ) ;
}
static T_1 F_67 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_97 * V_98 ;
struct V_6 * V_7 ;
int V_60 ;
V_98 = F_63 ( V_2 ) ;
V_7 = F_66 ( V_98 ) ;
F_4 ( V_7 ) ;
if ( ! V_98 -> V_2 . V_110 ||
F_68 ( V_98 -> V_2 . V_110 ) -> V_111 )
V_60 = sprintf ( V_5 , L_13 , 1 ) ;
else
V_60 = sprintf ( V_5 , L_13 , 0 ) ;
F_6 ( V_7 ) ;
return V_60 ;
}
static T_4 F_69 ( struct V_71 * V_40 ,
struct V_72 * V_73 , int V_74 )
{
struct V_1 * V_2 = F_54 ( V_40 , struct V_1 , V_40 ) ;
struct V_97 * V_98 = F_63 ( V_2 ) ;
if ( V_98 -> V_112 == NULL )
return 0 ;
return V_73 -> V_81 ;
}
void F_70 ( struct V_97 * V_98 )
{
struct V_6 * V_7 = F_66 ( V_98 ) ;
struct V_100 * V_101 = V_98 -> V_99 ;
if ( V_98 -> V_113 || V_98 -> V_114 )
return;
if ( ! V_101 -> string && ! ( V_7 -> V_28 & V_115 ) )
V_101 -> string = F_71 ( V_7 , V_101 -> V_93 . V_116 ) ;
if ( V_101 -> string && F_72 ( & V_98 -> V_2 , & V_117 ) )
;
V_98 -> V_113 = 1 ;
}
void F_73 ( struct V_97 * V_98 )
{
if ( ! V_98 -> V_113 )
return;
F_74 ( & V_98 -> V_2 , & V_117 ) ;
V_98 -> V_113 = 0 ;
}
