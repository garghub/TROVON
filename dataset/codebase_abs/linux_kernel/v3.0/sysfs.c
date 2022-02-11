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
static int F_38 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
if ( F_22 ( V_2 ) )
V_35 = F_39 ( & V_2 -> V_36 , & V_56 ) ;
return V_35 ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_36 , & V_56 ) ;
}
static T_1 F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_57 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_58 , L_11 , V_57 -> V_59 ) ;
}
static T_1 F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_60 )
{
T_1 V_61 ;
struct V_6 * V_57 = F_2 ( V_2 ) ;
unsigned V_62 ;
V_61 = sscanf ( V_5 , L_11 , & V_62 ) ;
if ( V_61 != 1 )
V_61 = - V_13 ;
else if ( V_62 == 0 )
V_61 = F_44 ( V_57 ) ;
else
V_61 = F_45 ( V_57 ) ;
return V_61 < 0 ? V_61 : V_60 ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_35 = 0 ;
F_4 ( V_7 ) ;
if ( V_7 -> V_42 != V_63 ) {
F_5 ( V_7 , - 1 ) ;
V_35 = F_47 ( V_7 ) ;
}
if ( V_35 == 0 )
V_35 = V_10 ;
F_6 ( V_7 ) ;
return V_35 ;
}
static T_4 F_48 ( struct V_64 * V_36 ,
struct V_65 * V_66 , int V_67 )
{
struct V_1 * V_2 = F_49 ( V_36 , struct V_1 , V_36 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_66 == & V_68 . V_4 ) {
if ( V_7 -> V_69 == NULL )
return 0 ;
} else if ( V_66 == & V_70 . V_4 ) {
if ( V_7 -> V_71 == NULL )
return 0 ;
} else if ( V_66 == & V_72 . V_4 ) {
if ( V_7 -> V_73 == NULL )
return 0 ;
}
return V_66 -> V_74 ;
}
static T_1
F_50 ( struct V_75 * V_76 , struct V_64 * V_36 ,
struct V_77 * V_4 ,
char * V_5 , T_5 V_78 , T_2 V_10 )
{
struct V_1 * V_2 = F_49 ( V_36 , struct V_1 , V_36 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_79 = V_10 ;
T_2 V_80 , V_67 ;
int V_81 ;
void * V_82 ;
for ( V_81 = - 1 ; V_81 < V_7 -> V_26 . V_83 &&
V_79 > 0 ; ++ V_81 ) {
if ( V_81 < 0 ) {
V_82 = & V_7 -> V_26 ;
V_80 = sizeof( struct V_84 ) ;
} else {
V_82 = V_7 -> V_85 [ V_81 ] ;
V_80 = F_51 ( V_7 -> V_11 [ V_81 ] . V_86 .
V_87 ) ;
}
if ( V_78 < V_80 ) {
V_67 = F_52 ( V_79 , V_80 - ( T_2 ) V_78 ) ;
memcpy ( V_5 , V_82 + V_78 , V_67 ) ;
V_79 -= V_67 ;
V_5 += V_67 ;
V_78 = 0 ;
} else {
V_78 -= V_80 ;
}
}
return V_10 - V_79 ;
}
int F_53 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
int V_88 ;
V_88 = F_54 ( V_2 , & V_89 ) ;
if ( V_88 )
goto error;
V_88 = F_21 ( V_2 ) ;
if ( V_88 )
goto error;
V_88 = F_38 ( V_2 ) ;
if ( V_88 )
goto error;
return V_88 ;
error:
F_55 ( V_7 ) ;
return V_88 ;
}
void F_55 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
F_40 ( V_2 ) ;
F_24 ( V_2 ) ;
F_56 ( V_2 , & V_89 ) ;
}
static T_1 F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_90 * V_91 ;
char * string ;
V_91 = F_58 ( V_2 ) ;
string = V_91 -> V_92 -> string ;
F_59 () ;
if ( ! string )
return 0 ;
return sprintf ( V_5 , L_1 , string ) ;
}
static T_1 F_60 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_90 * V_91 ;
struct V_6 * V_7 ;
struct V_93 * V_94 ;
V_91 = F_58 ( V_2 ) ;
V_7 = F_61 ( V_91 ) ;
V_94 = V_91 -> V_92 ;
return sprintf ( V_5 , L_14
L_15 ,
F_12 ( V_7 -> V_26 . V_95 ) ,
F_12 ( V_7 -> V_26 . V_96 ) ,
F_12 ( V_7 -> V_26 . V_97 ) ,
V_7 -> V_26 . V_32 ,
V_7 -> V_26 . V_98 ,
V_7 -> V_26 . V_99 ,
V_94 -> V_86 . V_100 ,
V_94 -> V_86 . V_101 ,
V_94 -> V_86 . V_102 ) ;
}
static T_1 F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_90 * V_91 ;
struct V_6 * V_7 ;
int V_103 ;
V_91 = F_58 ( V_2 ) ;
V_7 = F_61 ( V_91 ) ;
F_4 ( V_7 ) ;
if ( ! V_91 -> V_2 . V_104 ||
F_63 ( V_91 -> V_2 . V_104 ) -> V_105 )
V_103 = sprintf ( V_5 , L_11 , 1 ) ;
else
V_103 = sprintf ( V_5 , L_11 , 0 ) ;
F_6 ( V_7 ) ;
return V_103 ;
}
static T_4 F_64 ( struct V_64 * V_36 ,
struct V_65 * V_66 , int V_67 )
{
struct V_1 * V_2 = F_49 ( V_36 , struct V_1 , V_36 ) ;
struct V_90 * V_91 = F_58 ( V_2 ) ;
if ( V_91 -> V_106 == NULL )
return 0 ;
return V_66 -> V_74 ;
}
void F_65 ( struct V_90 * V_91 )
{
struct V_6 * V_7 = F_61 ( V_91 ) ;
struct V_93 * V_94 = V_91 -> V_92 ;
if ( V_91 -> V_107 || V_91 -> V_108 )
return;
if ( ! V_94 -> string && ! ( V_7 -> V_28 & V_109 ) )
V_94 -> string = F_66 ( V_7 , V_94 -> V_86 . V_110 ) ;
if ( V_94 -> string && F_67 ( & V_91 -> V_2 , & V_111 ) )
;
V_91 -> V_107 = 1 ;
}
void F_68 ( struct V_90 * V_91 )
{
if ( ! V_91 -> V_107 )
return;
F_69 ( & V_91 -> V_2 , & V_111 ) ;
V_91 -> V_107 = 0 ;
}
