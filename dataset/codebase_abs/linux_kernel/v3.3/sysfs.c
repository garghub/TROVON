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
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_8 , V_7 -> V_31 ) ;
}
static T_1
F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_12 ;
if ( V_7 -> V_26 . V_32 == V_33 )
return - V_34 ;
if ( sscanf ( V_5 , L_2 , & V_12 ) != 1 )
return - V_13 ;
F_4 ( V_7 ) ;
V_7 -> V_31 = ! ! V_12 ;
F_6 ( V_7 ) ;
return V_10 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
if ( F_22 ( V_2 ) ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_26 . V_32 != V_33 )
V_35 = F_23 ( & V_2 -> V_36 ,
& V_37 . V_4 ,
V_38 ) ;
}
return V_35 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_25 ( & V_2 -> V_36 ,
& V_37 . V_4 ,
V_38 ) ;
}
static T_1
F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_11 ,
F_27 ( V_39 - V_7 -> V_40 ) ) ;
}
static T_1
F_28 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_41 ;
if ( V_7 -> V_42 != V_43 )
V_41 = F_27 ( V_39 + V_7 -> V_44 ) ;
else
V_41 = F_27 ( V_7 -> V_44 ) ;
return sprintf ( V_5 , L_11 , V_41 ) ;
}
static T_1
F_29 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_8 , V_2 -> V_45 . V_46 / 1000 ) ;
}
static T_1
F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
int V_12 ;
if ( sscanf ( V_5 , L_2 , & V_12 ) != 1 || V_12 >= V_47 / 1000 ||
V_12 <= - V_47 / 1000 )
return - V_13 ;
F_31 ( V_2 , V_12 * 1000 ) ;
return V_10 ;
}
static void F_32 ( void ) {
static int V_48 ;
if ( ! V_48 ) {
V_48 = 1 ;
F_33 ( V_49 L_12
L_13 ) ;
}
}
static T_1
F_34 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_50 = V_51 ;
F_32 () ;
if ( V_7 -> V_42 != V_43 && ! V_7 -> V_2 . V_45 . V_52 )
V_50 = V_53 ;
return sprintf ( V_5 , L_1 , V_50 ) ;
}
static T_1
F_35 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_54 = V_10 ;
char * V_55 ;
int V_35 = V_10 ;
F_32 () ;
V_55 = memchr ( V_5 , '\n' , V_10 ) ;
if ( V_55 )
V_54 = V_55 - V_5 ;
F_4 ( V_7 ) ;
if ( V_54 == sizeof V_53 - 1 &&
strncmp ( V_5 , V_53 , V_54 ) == 0 )
F_36 ( V_7 ) ;
else if ( V_54 == sizeof V_51 - 1 &&
strncmp ( V_5 , V_51 , V_54 ) == 0 )
F_37 ( V_7 ) ;
else
V_35 = - V_13 ;
F_6 ( V_7 ) ;
return V_35 ;
}
static T_1
F_38 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_50 ;
if ( V_7 -> V_56 == 1 )
V_50 = L_14 ;
else
V_50 = L_15 ;
return sprintf ( V_5 , L_1 , V_50 ) ;
}
static T_1
F_39 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
bool V_12 ;
int V_57 ;
F_4 ( V_7 ) ;
V_57 = F_40 ( V_5 , & V_12 ) ;
if ( ! V_57 )
V_57 = F_41 ( V_7 , V_12 ) ;
F_6 ( V_7 ) ;
if ( ! V_57 )
return V_10 ;
return V_57 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
if ( F_22 ( V_2 ) ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_35 = F_43 ( & V_2 -> V_36 , & V_58 ) ;
if ( V_7 -> V_59 == 1 )
V_35 = F_43 ( & V_2 -> V_36 ,
& V_60 ) ;
}
return V_35 ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_45 ( & V_2 -> V_36 , & V_60 ) ;
F_45 ( & V_2 -> V_36 , & V_58 ) ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_61 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_62 , L_11 , V_61 -> V_63 ) ;
}
static T_1 F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_64 )
{
T_1 V_65 ;
struct V_6 * V_61 = F_2 ( V_2 ) ;
unsigned V_66 ;
V_65 = sscanf ( V_5 , L_11 , & V_66 ) ;
if ( V_65 != 1 )
V_65 = - V_13 ;
else if ( V_66 == 0 )
V_65 = F_48 ( V_61 ) ;
else
V_65 = F_49 ( V_61 ) ;
return V_65 < 0 ? V_65 : V_64 ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_35 = 0 ;
F_4 ( V_7 ) ;
if ( V_7 -> V_42 != V_67 ) {
F_5 ( V_7 , - 1 ) ;
V_35 = F_51 ( V_7 ) ;
}
if ( V_35 == 0 )
V_35 = V_10 ;
F_6 ( V_7 ) ;
return V_35 ;
}
static T_4 F_52 ( struct V_68 * V_36 ,
struct V_69 * V_70 , int V_71 )
{
struct V_1 * V_2 = F_53 ( V_36 , struct V_1 , V_36 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_70 == & V_72 . V_4 ) {
if ( V_7 -> V_73 == NULL )
return 0 ;
} else if ( V_70 == & V_74 . V_4 ) {
if ( V_7 -> V_75 == NULL )
return 0 ;
} else if ( V_70 == & V_76 . V_4 ) {
if ( V_7 -> V_77 == NULL )
return 0 ;
}
return V_70 -> V_78 ;
}
static T_1
F_54 ( struct V_79 * V_80 , struct V_68 * V_36 ,
struct V_81 * V_4 ,
char * V_5 , T_5 V_82 , T_2 V_10 )
{
struct V_1 * V_2 = F_53 ( V_36 , struct V_1 , V_36 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_83 = V_10 ;
T_2 V_84 , V_71 ;
int V_85 ;
void * V_86 ;
for ( V_85 = - 1 ; V_85 < V_7 -> V_26 . V_87 &&
V_83 > 0 ; ++ V_85 ) {
if ( V_85 < 0 ) {
V_86 = & V_7 -> V_26 ;
V_84 = sizeof( struct V_88 ) ;
} else {
V_86 = V_7 -> V_89 [ V_85 ] ;
V_84 = F_55 ( V_7 -> V_11 [ V_85 ] . V_90 .
V_91 ) ;
}
if ( V_82 < V_84 ) {
V_71 = F_56 ( V_83 , V_84 - ( T_2 ) V_82 ) ;
memcpy ( V_5 , V_86 + V_82 , V_71 ) ;
V_83 -= V_71 ;
V_5 += V_71 ;
V_82 = 0 ;
} else {
V_82 -= V_84 ;
}
}
return V_10 - V_83 ;
}
int F_57 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
int V_92 ;
V_92 = F_58 ( V_2 , & V_93 ) ;
if ( V_92 )
goto error;
V_92 = F_21 ( V_2 ) ;
if ( V_92 )
goto error;
V_92 = F_42 ( V_2 ) ;
if ( V_92 )
goto error;
return V_92 ;
error:
F_59 ( V_7 ) ;
return V_92 ;
}
void F_59 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
F_44 ( V_2 ) ;
F_24 ( V_2 ) ;
F_60 ( V_2 , & V_93 ) ;
}
static T_1 F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_94 * V_95 ;
char * string ;
V_95 = F_62 ( V_2 ) ;
string = V_95 -> V_96 -> string ;
F_63 () ;
if ( ! string )
return 0 ;
return sprintf ( V_5 , L_1 , string ) ;
}
static T_1 F_64 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_94 * V_95 ;
struct V_6 * V_7 ;
struct V_97 * V_98 ;
V_95 = F_62 ( V_2 ) ;
V_7 = F_65 ( V_95 ) ;
V_98 = V_95 -> V_96 ;
return sprintf ( V_5 , L_16
L_17 ,
F_12 ( V_7 -> V_26 . V_99 ) ,
F_12 ( V_7 -> V_26 . V_100 ) ,
F_12 ( V_7 -> V_26 . V_101 ) ,
V_7 -> V_26 . V_32 ,
V_7 -> V_26 . V_102 ,
V_7 -> V_26 . V_103 ,
V_98 -> V_90 . V_104 ,
V_98 -> V_90 . V_105 ,
V_98 -> V_90 . V_106 ) ;
}
static T_1 F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_94 * V_95 ;
struct V_6 * V_7 ;
int V_57 ;
V_95 = F_62 ( V_2 ) ;
V_7 = F_65 ( V_95 ) ;
F_4 ( V_7 ) ;
if ( ! V_95 -> V_2 . V_107 ||
F_67 ( V_95 -> V_2 . V_107 ) -> V_108 )
V_57 = sprintf ( V_5 , L_11 , 1 ) ;
else
V_57 = sprintf ( V_5 , L_11 , 0 ) ;
F_6 ( V_7 ) ;
return V_57 ;
}
static T_4 F_68 ( struct V_68 * V_36 ,
struct V_69 * V_70 , int V_71 )
{
struct V_1 * V_2 = F_53 ( V_36 , struct V_1 , V_36 ) ;
struct V_94 * V_95 = F_62 ( V_2 ) ;
if ( V_95 -> V_109 == NULL )
return 0 ;
return V_70 -> V_78 ;
}
void F_69 ( struct V_94 * V_95 )
{
struct V_6 * V_7 = F_65 ( V_95 ) ;
struct V_97 * V_98 = V_95 -> V_96 ;
if ( V_95 -> V_110 || V_95 -> V_111 )
return;
if ( ! V_98 -> string && ! ( V_7 -> V_28 & V_112 ) )
V_98 -> string = F_70 ( V_7 , V_98 -> V_90 . V_113 ) ;
if ( V_98 -> string && F_71 ( & V_95 -> V_2 , & V_114 ) )
;
V_95 -> V_110 = 1 ;
}
void F_72 ( struct V_94 * V_95 )
{
if ( ! V_95 -> V_110 )
return;
F_73 ( & V_95 -> V_2 , & V_114 ) ;
V_95 -> V_110 = 0 ;
}
