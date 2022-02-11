static int F_1 ( unsigned int V_1 )
{
if ( V_1 >= 0xd0 && V_1 <= 0xdf )
return V_1 - 0xd0 + 1 ;
if ( V_1 >= 0xe8 && V_1 <= 0xe9 )
return V_1 - 0xe8 + 17 ;
return 0 ;
}
static enum V_2 F_2 ( struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_3 ( V_4 , struct V_6 , V_8 ) ;
struct V_9 * V_10 = V_7 -> V_8 . V_10 -> V_11 ;
struct V_12 * V_13 = F_4 ( V_10 -> V_11 ) ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
int V_16 ;
char * V_17 ;
V_17 = F_6 ( 8 , V_18 ) ;
if ( ! V_17 )
return - V_19 ;
V_5 = F_7 ( V_15 , F_8 ( V_15 , 0 ) ,
V_20 ,
V_21 | V_22 |
V_23 , 0 , 0 , V_17 , 8 ,
V_24 ) ;
if ( V_5 < 5 ) {
F_9 ( V_10 , L_1 ,
V_5 ) ;
V_5 = - V_25 ;
goto V_26;
}
V_16 = V_17 [ 4 ] ;
if ( V_16 < 0 || V_16 > 3 ) {
F_9 ( V_10 ,
L_2 ,
V_17 [ 4 ] ) ;
V_5 = - V_25 ;
goto V_26;
}
V_5 = V_16 ;
V_26:
F_10 ( V_17 ) ;
return V_5 ;
}
static enum V_2 F_11 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_3 ( V_4 , struct V_6 , V_8 ) ;
return V_7 -> V_16 ;
}
static void F_12 ( struct V_3 * V_4 ,
enum V_2 V_16 )
{
struct V_6 * V_7 = F_3 ( V_4 , struct V_6 , V_8 ) ;
V_7 -> V_16 = V_16 ;
F_13 ( & V_7 -> V_27 ) ;
}
static void F_14 ( struct V_28 * V_27 )
{
int V_5 ;
struct V_6 * V_7 = F_3 ( V_27 , struct V_6 , V_27 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
if ( V_7 -> V_29 )
return;
V_10 = V_7 -> V_8 . V_10 -> V_11 ;
V_13 = F_4 ( V_10 -> V_11 ) ;
V_15 = F_5 ( V_13 ) ;
V_5 = F_7 ( V_15 , F_15 ( V_15 , 0 ) ,
V_30 ,
V_31 | V_22 |
V_23 , V_7 -> V_16 , 0 ,
NULL , 0 , V_24 ) ;
if ( V_5 != 0 )
F_9 ( V_10 , L_3 ,
V_5 ) ;
}
static void F_16 ( struct V_28 * V_27 )
{
int V_5 ;
struct V_6 * V_7 = F_3 ( V_27 , struct V_6 , V_27 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_32 ;
if ( V_7 -> V_29 )
return;
V_10 = V_7 -> V_8 . V_10 -> V_11 ;
V_13 = F_4 ( V_10 -> V_11 ) ;
V_15 = F_5 ( V_13 ) ;
if ( V_7 -> V_16 > 0 )
V_32 = V_33 ;
else
V_32 = V_34 ;
V_5 = F_7 ( V_15 , F_15 ( V_15 , 0 ) ,
V_35 ,
V_31 | V_22 |
V_23 , V_32 , 0 , NULL , 0 ,
V_24 ) ;
if ( V_5 != 0 )
F_9 ( V_10 , L_4 ,
V_5 ) ;
}
static T_1 F_17 ( struct V_9 * V_10 ,
struct V_36 * V_37 , char * V_38 )
{
int V_5 ;
struct V_12 * V_13 = F_4 ( V_10 -> V_11 ) ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
const char * V_39 ;
char * V_17 ;
V_17 = F_6 ( 2 , V_18 ) ;
if ( ! V_17 )
return - V_19 ;
V_5 = F_7 ( V_15 , F_8 ( V_15 , 0 ) ,
V_40 ,
V_21 | V_22 |
V_23 , 0 , 0 , V_17 , 2 ,
V_24 ) ;
if ( V_5 < 1 ) {
F_9 ( V_10 , L_5 ,
V_5 ) ;
V_5 = - V_25 ;
goto V_26;
}
switch ( V_17 [ 0 ] ) {
case V_41 :
V_39 = L_6 ;
break;
case V_42 :
V_39 = L_7 ;
break;
default:
F_9 ( V_10 , L_8 ,
V_17 [ 0 ] ) ;
V_5 = - V_25 ;
goto V_26;
}
V_5 = snprintf ( V_38 , V_43 , L_9 , V_39 ) ;
V_26:
F_10 ( V_17 ) ;
return V_5 ;
}
static T_1 F_18 ( struct V_9 * V_10 ,
struct V_36 * V_37 ,
const char * V_38 , T_2 V_44 )
{
int V_5 ;
struct V_12 * V_13 = F_4 ( V_10 -> V_11 ) ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
T_3 V_32 ;
if ( strncmp ( V_38 , L_7 , 2 ) == 0 )
V_32 = V_42 ;
else if ( strncmp ( V_38 , L_6 , 2 ) == 0 )
V_32 = V_41 ;
else
return - V_45 ;
V_5 = F_7 ( V_15 , F_15 ( V_15 , 0 ) ,
V_35 ,
V_31 | V_22 |
V_23 , V_32 , 0 , NULL , 0 ,
V_24 ) ;
if ( V_5 != 0 ) {
F_9 ( V_10 , L_10 ) ;
return V_5 ;
}
return V_44 ;
}
static T_1 F_19 ( struct V_9 * V_10 ,
struct V_36 * V_37 ,
char * V_38 )
{
int V_5 ;
struct V_12 * V_13 = F_4 ( V_10 -> V_11 ) ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
int V_46 ;
char * V_17 ;
V_17 = F_6 ( 8 , V_18 ) ;
if ( ! V_17 )
return - V_19 ;
V_5 = F_7 ( V_15 , F_8 ( V_15 , 0 ) ,
V_20 ,
V_21 | V_22 |
V_23 , 0 , 0 , V_17 , 8 ,
V_24 ) ;
if ( V_5 < 8 ) {
F_9 ( V_10 , L_1 ,
V_5 ) ;
V_5 = - V_25 ;
goto V_26;
}
V_46 = V_17 [ 7 ] ;
if ( V_46 < 1 || V_46 > 3 ) {
F_9 ( V_10 , L_11 ,
V_17 [ 7 ] ) ;
V_5 = - V_25 ;
goto V_26;
}
V_5 = snprintf ( V_38 , V_43 , L_12 , V_46 ) ;
V_26:
F_10 ( V_17 ) ;
return V_5 ;
}
static T_1 F_20 ( struct V_9 * V_10 ,
struct V_36 * V_37 ,
const char * V_38 , T_2 V_44 )
{
int V_5 ;
struct V_12 * V_13 = F_4 ( V_10 -> V_11 ) ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
int V_47 ;
if ( F_21 ( V_38 , 10 , & V_47 ) )
return - V_45 ;
if ( V_47 < 1 || V_47 > 3 )
return - V_45 ;
V_5 = F_7 ( V_15 , F_15 ( V_15 , 0 ) ,
V_48 ,
V_31 | V_22 |
V_23 , V_47 , 0 , NULL , 0 ,
V_24 ) ;
if ( V_5 != 0 ) {
F_9 ( V_10 , L_13 ,
V_5 ) ;
return V_5 ;
}
return V_44 ;
}
static int F_22 ( struct V_49 * V_10 )
{
int V_5 ;
struct V_50 * V_51 = F_23 ( V_10 ) ;
T_2 V_52 ;
char * V_53 ;
V_51 -> V_54 = F_24 ( sizeof( struct V_6 ) , V_18 ) ;
if ( ! V_51 -> V_54 ) {
V_5 = - V_19 ;
goto V_55;
}
V_52 =
strlen ( F_25 ( & V_10 -> V_10 ) ) + sizeof( V_56 ) ;
V_53 = F_24 ( V_52 , V_18 ) ;
if ( ! V_53 ) {
V_5 = - V_19 ;
goto V_57;
}
snprintf ( V_53 , V_52 , L_14 V_56 ,
F_25 ( & V_10 -> V_10 ) ) ;
V_51 -> V_54 -> V_29 = false ;
V_51 -> V_54 -> V_8 . V_53 = V_53 ;
V_51 -> V_54 -> V_8 . V_58 = 3 ;
V_51 -> V_54 -> V_8 . V_59 = F_12 ;
V_51 -> V_54 -> V_8 . V_60 = F_2 ;
F_26 ( & V_51 -> V_54 -> V_27 , F_14 ) ;
V_5 = F_27 ( & V_10 -> V_10 , & V_51 -> V_54 -> V_8 ) ;
if ( V_5 != 0 )
goto V_61;
return 0 ;
V_61:
F_10 ( V_51 -> V_54 -> V_8 . V_53 ) ;
V_57:
F_10 ( V_51 -> V_54 ) ;
V_51 -> V_54 = NULL ;
V_55:
return V_5 ;
}
static int F_28 ( struct V_49 * V_10 )
{
int V_5 ;
struct V_50 * V_51 = F_23 ( V_10 ) ;
struct V_62 * V_63 ;
T_2 V_52 ;
char * V_53 ;
V_63 = F_24 ( sizeof( struct V_62 ) , V_18 ) ;
if ( ! V_63 ) {
V_5 = - V_19 ;
goto V_64;
}
V_51 -> V_63 = V_63 ;
V_52 = strlen ( F_25 ( & V_10 -> V_10 ) ) + sizeof( V_65 ) ;
V_53 = F_24 ( V_52 , V_18 ) ;
if ( ! V_53 ) {
V_5 = - V_19 ;
goto V_66;
}
snprintf ( V_53 , V_52 , L_14 V_65 ,
F_25 ( & V_10 -> V_10 ) ) ;
V_63 -> V_67 . V_29 = false ;
V_63 -> V_67 . V_8 . V_53 = V_53 ;
V_63 -> V_67 . V_8 . V_58 = 1 ;
V_63 -> V_67 . V_8 . V_59 = F_12 ;
V_63 -> V_67 . V_8 . V_60 = F_11 ;
F_26 ( & V_63 -> V_67 . V_27 , F_16 ) ;
V_63 -> V_67 . V_16 = 0 ;
V_5 = F_27 ( & V_10 -> V_10 , & V_63 -> V_67 . V_8 ) ;
if ( V_5 != 0 )
goto V_68;
V_5 = F_29 ( & V_10 -> V_10 . V_69 , & V_70 ) ;
if ( V_5 != 0 )
goto V_71;
return 0 ;
V_71:
V_63 -> V_67 . V_29 = true ;
F_30 ( & V_63 -> V_67 . V_8 ) ;
F_31 ( & V_63 -> V_67 . V_27 ) ;
V_68:
F_10 ( V_63 -> V_67 . V_8 . V_53 ) ;
V_66:
F_10 ( V_63 ) ;
V_64:
V_51 -> V_63 = NULL ;
return V_5 ;
}
static void F_32 ( struct V_49 * V_10 )
{
struct V_50 * V_51 = F_23 ( V_10 ) ;
if ( V_51 -> V_54 ) {
V_51 -> V_54 -> V_29 = true ;
F_30 ( & V_51 -> V_54 -> V_8 ) ;
F_31 ( & V_51 -> V_54 -> V_27 ) ;
F_10 ( V_51 -> V_54 -> V_8 . V_53 ) ;
F_10 ( V_51 -> V_54 ) ;
}
}
static void F_33 ( struct V_49 * V_10 )
{
struct V_50 * V_51 = F_23 ( V_10 ) ;
struct V_62 * V_63 = V_51 -> V_63 ;
if ( V_63 ) {
F_34 ( & V_10 -> V_10 . V_69 , & V_70 ) ;
V_63 -> V_67 . V_29 = true ;
F_30 ( & V_63 -> V_67 . V_8 ) ;
F_31 ( & V_63 -> V_67 . V_27 ) ;
F_10 ( V_63 -> V_67 . V_8 . V_53 ) ;
F_10 ( V_63 ) ;
}
}
static int F_35 ( struct V_49 * V_10 , const struct V_72 * V_73 )
{
int V_5 ;
unsigned long V_74 = V_73 -> V_75 ;
struct V_50 * V_51 ;
struct V_12 * V_13 = F_4 ( V_10 -> V_10 . V_11 ) ;
V_51 = F_36 ( & V_10 -> V_10 , sizeof( struct V_50 ) ,
V_18 ) ;
if ( V_51 == NULL )
return - V_19 ;
V_51 -> V_74 = V_74 ;
F_37 ( V_10 , V_51 ) ;
V_5 = F_38 ( V_10 ) ;
if ( V_5 != 0 ) {
F_39 ( V_10 , L_15 ) ;
return V_5 ;
}
V_5 = F_40 ( V_10 , V_76 ) ;
if ( V_5 != 0 ) {
F_39 ( V_10 , L_16 ) ;
return V_5 ;
}
if ( V_13 -> V_77 -> V_78 . V_79 == 0 ) {
if ( V_74 & V_80 ) {
V_5 = F_28 ( V_10 ) ;
if ( V_5 != 0 )
F_41 ( V_10 , L_17 ) ;
}
if ( V_74 & V_81 ) {
V_5 = F_22 ( V_10 ) ;
if ( V_5 != 0 )
F_41 ( V_10 , L_18 ) ;
}
}
return 0 ;
}
static void F_42 ( struct V_49 * V_10 )
{
F_33 ( V_10 ) ;
F_32 ( V_10 ) ;
F_43 ( V_10 ) ;
}
static int F_44 ( struct V_49 * V_10 , struct V_82 * V_83 ,
struct V_84 * V_1 , T_4 V_32 )
{
struct V_50 * V_51 = F_23 ( V_10 ) ;
if ( ! V_51 -> V_63 )
return 0 ;
switch ( V_1 -> V_85 & V_86 ) {
case V_87 :
V_51 -> V_63 -> V_67 . V_16 = 1 ;
break;
case V_88 :
V_51 -> V_63 -> V_67 . V_16 = 0 ;
break;
default:
break;
}
return 0 ;
}
static int F_45 ( struct V_49 * V_10 ,
struct V_89 * V_90 ,
struct V_82 * V_83 ,
struct V_84 * V_1 , unsigned long * * V_91 ,
int * V_92 )
{
int V_93 ;
if ( ( V_1 -> V_85 & V_94 ) != V_95 )
return 0 ;
V_93 = F_1 ( V_1 -> V_85 & V_86 ) ;
if ( V_93 != 0 ) {
F_46 ( V_90 , V_1 , V_91 , V_92 , V_96 ,
V_97 [ V_93 - 1 ] ) ;
return 1 ;
}
if ( ( V_1 -> V_85 & V_86 ) >= V_98 &&
( V_1 -> V_85 & V_86 ) <= V_99 ) {
switch ( V_1 -> V_85 & V_86 ) {
case V_87 :
F_46 ( V_90 , V_1 , V_91 , V_92 , V_96 ,
V_100 [ 0 ] ) ;
return 1 ;
case V_88 :
F_46 ( V_90 , V_1 , V_91 , V_92 , V_96 ,
V_100 [ 1 ] ) ;
return 1 ;
case V_101 :
F_46 ( V_90 , V_1 , V_91 , V_92 , V_96 ,
V_102 [ 0 ] ) ;
return 1 ;
case V_103 :
F_46 ( V_90 , V_1 , V_91 , V_92 , V_96 ,
V_102 [ 1 ] ) ;
return 1 ;
case V_104 :
F_46 ( V_90 , V_1 , V_91 , V_92 , V_96 ,
V_102 [ 2 ] ) ;
return 1 ;
default:
return - 1 ;
}
}
return 0 ;
}
static T_5 * F_47 ( struct V_49 * V_105 , T_5 * V_106 ,
unsigned int * V_107 )
{
struct V_12 * V_108 = F_4 ( V_105 -> V_10 . V_11 ) ;
if ( V_108 -> V_77 -> V_78 . V_79 == 1 ) {
switch ( V_105 -> V_109 ) {
case V_110 :
if ( * V_107 >= 172 && V_106 [ 75 ] == 0x15 && V_106 [ 77 ] == 0x16
&& V_106 [ 78 ] == 0xff && V_106 [ 79 ] == 0x0f ) {
F_48 ( V_105 , L_19 ) ;
V_106 [ 77 ] = 0x26 ;
}
break;
}
}
return V_106 ;
}
