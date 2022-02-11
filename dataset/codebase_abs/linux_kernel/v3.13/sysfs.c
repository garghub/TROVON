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
static int F_53 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
if ( F_27 ( V_2 ) ) {
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_10 = F_54 ( & V_2 -> V_41 , & V_65 ) ;
if ( V_7 -> V_66 == 1 )
V_10 = F_54 ( & V_2 -> V_41 ,
& V_67 ) ;
}
return V_10 ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_56 ( & V_2 -> V_41 , & V_67 ) ;
F_56 ( & V_2 -> V_41 , & V_65 ) ;
}
static T_1 F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_68 = F_2 ( V_2 ) ;
return snprintf ( V_5 , V_69 , L_16 , V_68 -> V_70 ) ;
}
static T_1 F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 ,
T_2 V_71 )
{
T_1 V_72 ;
struct V_6 * V_68 = F_2 ( V_2 ) ;
unsigned V_31 ;
V_72 = sscanf ( V_5 , L_16 , & V_31 ) ;
if ( V_72 != 1 )
V_72 = - V_14 ;
else if ( V_31 == 0 )
V_72 = F_59 ( V_68 ) ;
else
V_72 = F_60 ( V_68 ) ;
return V_72 < 0 ? V_72 : V_71 ;
}
static T_1 F_61 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 = 0 ;
F_3 ( V_7 ) ;
if ( V_7 -> V_33 != V_73 ) {
F_8 ( V_7 , - 1 ) ;
V_10 = F_62 ( V_7 ) ;
}
if ( V_10 == 0 )
V_10 = V_11 ;
F_5 ( V_7 ) ;
return V_10 ;
}
static T_5 F_63 ( struct V_74 * V_41 ,
struct V_75 * V_76 , int V_77 )
{
struct V_1 * V_2 = F_64 ( V_41 , struct V_1 , V_41 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_76 == & V_78 . V_4 ) {
if ( V_7 -> V_79 == NULL )
return 0 ;
} else if ( V_76 == & V_80 . V_4 ) {
if ( V_7 -> V_81 == NULL )
return 0 ;
} else if ( V_76 == & V_82 . V_4 ) {
if ( V_7 -> V_83 == NULL )
return 0 ;
}
return V_76 -> V_84 ;
}
static T_1
F_65 ( struct V_85 * V_86 , struct V_74 * V_41 ,
struct V_87 * V_4 ,
char * V_5 , T_6 V_88 , T_2 V_11 )
{
struct V_1 * V_2 = F_64 ( V_41 , struct V_1 , V_41 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_89 = V_11 ;
T_2 V_90 , V_77 ;
int V_91 ;
void * V_92 ;
F_3 ( V_7 ) ;
for ( V_91 = - 1 ; V_91 < V_7 -> V_27 . V_93 &&
V_89 > 0 ; ++ V_91 ) {
if ( V_91 < 0 ) {
V_92 = & V_7 -> V_27 ;
V_90 = sizeof( struct V_94 ) ;
} else {
V_92 = V_7 -> V_95 [ V_91 ] ;
V_90 = F_66 ( V_7 -> V_12 [ V_91 ] . V_96 .
V_97 ) ;
}
if ( V_88 < V_90 ) {
V_77 = F_67 ( V_89 , V_90 - ( T_2 ) V_88 ) ;
memcpy ( V_5 , V_92 + V_88 , V_77 ) ;
V_89 -= V_77 ;
V_5 += V_77 ;
V_88 = 0 ;
} else {
V_88 -= V_90 ;
}
}
F_5 ( V_7 ) ;
return V_11 - V_89 ;
}
int F_68 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
int V_98 ;
V_98 = F_69 ( V_2 , & V_99 ) ;
if ( V_98 )
goto error;
V_98 = F_26 ( V_2 ) ;
if ( V_98 )
goto error;
V_98 = F_53 ( V_2 ) ;
if ( V_98 )
goto error;
return V_98 ;
error:
F_70 ( V_7 ) ;
return V_98 ;
}
void F_70 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
F_55 ( V_2 ) ;
F_29 ( V_2 ) ;
F_71 ( V_2 , & V_99 ) ;
}
static T_1 F_72 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_100 * V_101 ;
char * string ;
V_101 = F_73 ( V_2 ) ;
string = F_74 ( V_101 -> V_102 -> string ) ;
if ( ! string )
return 0 ;
return sprintf ( V_5 , L_2 , string ) ;
}
static T_1 F_75 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_100 * V_101 ;
struct V_6 * V_7 ;
struct V_103 * V_104 ;
V_101 = F_73 ( V_2 ) ;
V_7 = F_76 ( V_101 ) ;
V_104 = F_74 ( V_101 -> V_102 ) ;
return sprintf ( V_5 , L_21
L_22 ,
F_14 ( V_7 -> V_27 . V_105 ) ,
F_14 ( V_7 -> V_27 . V_106 ) ,
F_14 ( V_7 -> V_27 . V_107 ) ,
V_7 -> V_27 . V_38 ,
V_7 -> V_27 . V_108 ,
V_7 -> V_27 . V_109 ,
V_104 -> V_96 . V_110 ,
V_104 -> V_96 . V_111 ,
V_104 -> V_96 . V_112 ,
V_104 -> V_96 . V_113 ) ;
}
static T_1 F_77 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_114 ;
F_78 ( V_2 ) ;
V_114 = ( ! V_2 -> V_115 || F_79 ( V_2 -> V_115 ) -> V_116 ) ;
F_80 ( V_2 ) ;
return sprintf ( V_5 , L_16 , V_114 ) ;
}
static T_5 F_81 ( struct V_74 * V_41 ,
struct V_75 * V_76 , int V_77 )
{
struct V_1 * V_2 = F_64 ( V_41 , struct V_1 , V_41 ) ;
struct V_100 * V_101 = F_73 ( V_2 ) ;
if ( V_101 -> V_117 == NULL )
return 0 ;
return V_76 -> V_84 ;
}
void F_82 ( struct V_100 * V_101 )
{
struct V_6 * V_7 = F_76 ( V_101 ) ;
struct V_103 * V_104 = V_101 -> V_102 ;
if ( V_101 -> V_118 || V_101 -> V_119 )
return;
if ( ! V_104 -> string && ! ( V_7 -> V_29 & V_120 ) )
V_104 -> string = F_83 ( V_7 , V_104 -> V_96 . V_121 ) ;
if ( V_104 -> string && F_84 ( & V_101 -> V_2 , & V_122 ) )
;
V_101 -> V_118 = 1 ;
}
void F_85 ( struct V_100 * V_101 )
{
if ( ! V_101 -> V_118 )
return;
F_86 ( & V_101 -> V_2 , & V_122 ) ;
V_101 -> V_118 = 0 ;
}
