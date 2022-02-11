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
char V_17 [ 8 ] ;
V_5 = F_6 ( V_15 , F_7 ( V_15 , 0 ) ,
V_18 ,
V_19 | V_20 |
V_21 , 0 , 0 , V_17 , 8 ,
V_22 ) ;
if ( V_5 < 0 ) {
F_8 ( V_10 , L_1 ,
V_5 ) ;
return - V_23 ;
}
V_16 = V_17 [ 4 ] ;
if ( V_16 < 0 || V_16 > 3 ) {
F_8 ( V_10 ,
L_2 ,
V_17 [ 4 ] ) ;
return - V_23 ;
}
return V_16 ;
}
static enum V_2 F_9 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_3 ( V_4 , struct V_6 , V_8 ) ;
return V_7 -> V_16 ;
}
static void F_10 ( struct V_3 * V_4 ,
enum V_2 V_16 )
{
struct V_6 * V_7 = F_3 ( V_4 , struct V_6 , V_8 ) ;
V_7 -> V_16 = V_16 ;
F_11 ( & V_7 -> V_24 ) ;
}
static void F_12 ( struct V_25 * V_24 )
{
int V_5 ;
struct V_6 * V_7 = F_3 ( V_24 , struct V_6 , V_24 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
if ( V_7 -> V_26 )
return;
V_10 = V_7 -> V_8 . V_10 -> V_11 ;
V_13 = F_4 ( V_10 -> V_11 ) ;
V_15 = F_5 ( V_13 ) ;
V_5 = F_6 ( V_15 , F_13 ( V_15 , 0 ) ,
V_27 ,
V_28 | V_20 |
V_21 , V_7 -> V_16 , 0 ,
NULL , 0 , V_22 ) ;
if ( V_5 != 0 )
F_8 ( V_10 , L_3 ,
V_5 ) ;
}
static void F_14 ( struct V_25 * V_24 )
{
int V_5 ;
struct V_6 * V_7 = F_3 ( V_24 , struct V_6 , V_24 ) ;
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_29 ;
if ( V_7 -> V_26 )
return;
V_10 = V_7 -> V_8 . V_10 -> V_11 ;
V_13 = F_4 ( V_10 -> V_11 ) ;
V_15 = F_5 ( V_13 ) ;
if ( V_7 -> V_16 > 0 )
V_29 = V_30 ;
else
V_29 = V_31 ;
V_5 = F_6 ( V_15 , F_13 ( V_15 , 0 ) ,
V_32 ,
V_28 | V_20 |
V_21 , V_29 , 0 , NULL , 0 ,
V_22 ) ;
if ( V_5 != 0 )
F_8 ( V_10 , L_4 ,
V_5 ) ;
}
static T_1 F_15 ( struct V_9 * V_10 ,
struct V_33 * V_34 , char * V_35 )
{
int V_5 ;
struct V_12 * V_13 = F_4 ( V_10 -> V_11 ) ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
const char * V_36 ;
char V_17 [ 8 ] ;
V_5 = F_6 ( V_15 , F_7 ( V_15 , 0 ) ,
V_37 ,
V_19 | V_20 |
V_21 , 0 , 0 , V_17 , 2 ,
V_22 ) ;
if ( V_5 < 0 ) {
F_8 ( V_10 , L_5 ,
V_5 ) ;
return - V_23 ;
}
switch ( V_17 [ 0 ] ) {
case V_38 :
V_36 = L_6 ;
break;
case V_39 :
V_36 = L_7 ;
break;
default:
F_8 ( V_10 , L_8 ,
V_17 [ 0 ] ) ;
return - V_23 ;
}
return snprintf ( V_35 , V_40 , L_9 , V_36 ) ;
}
static T_1 F_16 ( struct V_9 * V_10 ,
struct V_33 * V_34 ,
const char * V_35 , T_2 V_41 )
{
int V_5 ;
struct V_12 * V_13 = F_4 ( V_10 -> V_11 ) ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
T_3 V_29 ;
if ( strncmp ( V_35 , L_7 , 2 ) == 0 )
V_29 = V_39 ;
else if ( strncmp ( V_35 , L_6 , 2 ) == 0 )
V_29 = V_38 ;
else
return - V_42 ;
V_5 = F_6 ( V_15 , F_13 ( V_15 , 0 ) ,
V_32 ,
V_28 | V_20 |
V_21 , V_29 , 0 , NULL , 0 ,
V_22 ) ;
if ( V_5 != 0 ) {
F_8 ( V_10 , L_10 ) ;
return V_5 ;
}
return V_41 ;
}
static T_1 F_17 ( struct V_9 * V_10 ,
struct V_33 * V_34 ,
char * V_35 )
{
int V_5 ;
struct V_12 * V_13 = F_4 ( V_10 -> V_11 ) ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
int V_43 ;
char V_17 [ 8 ] ;
V_5 = F_6 ( V_15 , F_7 ( V_15 , 0 ) ,
V_18 ,
V_19 | V_20 |
V_21 , 0 , 0 , V_17 , 8 ,
V_22 ) ;
if ( V_5 < 0 ) {
F_8 ( V_10 , L_1 ,
V_5 ) ;
return - V_23 ;
}
V_43 = V_17 [ 7 ] ;
if ( V_43 < 1 || V_43 > 3 ) {
F_8 ( V_10 , L_11 ,
V_17 [ 7 ] ) ;
return - V_23 ;
}
return snprintf ( V_35 , V_40 , L_12 , V_43 ) ;
}
static T_1 F_18 ( struct V_9 * V_10 ,
struct V_33 * V_34 ,
const char * V_35 , T_2 V_41 )
{
int V_5 ;
struct V_12 * V_13 = F_4 ( V_10 -> V_11 ) ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
int V_44 ;
if ( F_19 ( V_35 , 10 , & V_44 ) )
return - V_42 ;
if ( V_44 < 1 || V_44 > 3 )
return - V_42 ;
V_5 = F_6 ( V_15 , F_13 ( V_15 , 0 ) ,
V_45 ,
V_28 | V_20 |
V_21 , V_44 , 0 , NULL , 0 ,
V_22 ) ;
if ( V_5 != 0 ) {
F_8 ( V_10 , L_13 ,
V_5 ) ;
return V_5 ;
}
return V_41 ;
}
static int F_20 ( struct V_46 * V_10 )
{
int V_5 ;
struct V_47 * V_48 = F_21 ( V_10 ) ;
T_2 V_49 ;
char * V_50 ;
V_48 -> V_51 = F_22 ( sizeof( struct V_6 ) , V_52 ) ;
if ( ! V_48 -> V_51 ) {
V_5 = - V_53 ;
goto V_54;
}
V_49 =
strlen ( F_23 ( & V_10 -> V_10 ) ) + sizeof( V_55 ) ;
V_50 = F_22 ( V_49 , V_52 ) ;
if ( ! V_50 ) {
V_5 = - V_53 ;
goto V_56;
}
snprintf ( V_50 , V_49 , L_14 V_55 ,
F_23 ( & V_10 -> V_10 ) ) ;
V_48 -> V_51 -> V_26 = false ;
V_48 -> V_51 -> V_8 . V_50 = V_50 ;
V_48 -> V_51 -> V_8 . V_57 = 3 ;
V_48 -> V_51 -> V_8 . V_58 = F_10 ;
V_48 -> V_51 -> V_8 . V_59 = F_2 ;
F_24 ( & V_48 -> V_51 -> V_24 , F_12 ) ;
V_5 = F_25 ( & V_10 -> V_10 , & V_48 -> V_51 -> V_8 ) ;
if ( V_5 != 0 )
goto V_60;
return 0 ;
V_60:
F_26 ( V_48 -> V_51 -> V_8 . V_50 ) ;
V_56:
F_26 ( V_48 -> V_51 ) ;
V_48 -> V_51 = NULL ;
V_54:
return V_5 ;
}
static int F_27 ( struct V_46 * V_10 )
{
int V_5 ;
struct V_47 * V_48 = F_21 ( V_10 ) ;
struct V_61 * V_62 ;
T_2 V_49 ;
char * V_50 ;
V_62 = F_22 ( sizeof( struct V_61 ) , V_52 ) ;
if ( ! V_62 ) {
V_5 = - V_53 ;
goto V_63;
}
V_48 -> V_62 = V_62 ;
V_49 = strlen ( F_23 ( & V_10 -> V_10 ) ) + sizeof( V_64 ) ;
V_50 = F_22 ( V_49 , V_52 ) ;
if ( ! V_50 ) {
V_5 = - V_53 ;
goto V_65;
}
snprintf ( V_50 , V_49 , L_14 V_64 ,
F_23 ( & V_10 -> V_10 ) ) ;
V_62 -> V_66 . V_26 = false ;
V_62 -> V_66 . V_8 . V_50 = V_50 ;
V_62 -> V_66 . V_8 . V_57 = 1 ;
V_62 -> V_66 . V_8 . V_58 = F_10 ;
V_62 -> V_66 . V_8 . V_59 = F_9 ;
F_24 ( & V_62 -> V_66 . V_24 , F_14 ) ;
V_62 -> V_66 . V_16 = 0 ;
V_5 = F_25 ( & V_10 -> V_10 , & V_62 -> V_66 . V_8 ) ;
if ( V_5 != 0 )
goto V_67;
V_5 = F_28 ( & V_10 -> V_10 . V_68 , & V_69 ) ;
if ( V_5 != 0 )
goto V_70;
return 0 ;
V_70:
V_62 -> V_66 . V_26 = true ;
F_29 ( & V_62 -> V_66 . V_8 ) ;
F_30 ( & V_62 -> V_66 . V_24 ) ;
V_67:
F_26 ( V_62 -> V_66 . V_8 . V_50 ) ;
V_65:
F_26 ( V_62 ) ;
V_63:
V_48 -> V_62 = NULL ;
return V_5 ;
}
static void F_31 ( struct V_46 * V_10 )
{
struct V_47 * V_48 = F_21 ( V_10 ) ;
if ( V_48 -> V_51 ) {
V_48 -> V_51 -> V_26 = true ;
F_29 ( & V_48 -> V_51 -> V_8 ) ;
F_30 ( & V_48 -> V_51 -> V_24 ) ;
F_26 ( V_48 -> V_51 -> V_8 . V_50 ) ;
F_26 ( V_48 -> V_51 ) ;
}
}
static void F_32 ( struct V_46 * V_10 )
{
struct V_47 * V_48 = F_21 ( V_10 ) ;
struct V_61 * V_62 = V_48 -> V_62 ;
if ( V_62 ) {
F_33 ( & V_10 -> V_10 . V_68 , & V_69 ) ;
V_62 -> V_66 . V_26 = true ;
F_29 ( & V_62 -> V_66 . V_8 ) ;
F_30 ( & V_62 -> V_66 . V_24 ) ;
F_26 ( V_62 -> V_66 . V_8 . V_50 ) ;
F_26 ( V_62 ) ;
}
}
static int F_34 ( struct V_46 * V_10 , const struct V_71 * V_72 )
{
int V_5 ;
unsigned long V_73 = V_72 -> V_74 ;
struct V_47 * V_48 ;
struct V_12 * V_13 = F_4 ( V_10 -> V_10 . V_11 ) ;
V_48 = F_35 ( & V_10 -> V_10 , sizeof( struct V_47 ) ,
V_52 ) ;
if ( V_48 == NULL )
return - V_53 ;
V_48 -> V_73 = V_73 ;
F_36 ( V_10 , V_48 ) ;
V_5 = F_37 ( V_10 ) ;
if ( V_5 != 0 ) {
F_38 ( V_10 , L_15 ) ;
return V_5 ;
}
V_5 = F_39 ( V_10 , V_75 ) ;
if ( V_5 != 0 ) {
F_38 ( V_10 , L_16 ) ;
return V_5 ;
}
if ( V_13 -> V_76 -> V_77 . V_78 == 0 ) {
if ( V_73 & V_79 ) {
V_5 = F_27 ( V_10 ) ;
if ( V_5 != 0 )
F_40 ( V_10 , L_17 ) ;
}
if ( V_73 & V_80 ) {
V_5 = F_20 ( V_10 ) ;
if ( V_5 != 0 )
F_40 ( V_10 , L_18 ) ;
}
}
return 0 ;
}
static void F_41 ( struct V_46 * V_10 )
{
F_32 ( V_10 ) ;
F_31 ( V_10 ) ;
F_42 ( V_10 ) ;
}
static int F_43 ( struct V_46 * V_10 , struct V_81 * V_82 ,
struct V_83 * V_1 , T_4 V_29 )
{
struct V_47 * V_48 = F_21 ( V_10 ) ;
if ( ! V_48 -> V_62 )
return 0 ;
switch ( V_1 -> V_84 & V_85 ) {
case V_86 :
V_48 -> V_62 -> V_66 . V_16 = 1 ;
break;
case V_87 :
V_48 -> V_62 -> V_66 . V_16 = 0 ;
break;
default:
break;
}
return 0 ;
}
static int F_44 ( struct V_46 * V_10 ,
struct V_88 * V_89 ,
struct V_81 * V_82 ,
struct V_83 * V_1 , unsigned long * * V_90 ,
int * V_91 )
{
int V_92 ;
if ( ( V_1 -> V_84 & V_93 ) != V_94 )
return 0 ;
V_92 = F_1 ( V_1 -> V_84 & V_85 ) ;
if ( V_92 != 0 ) {
F_45 ( V_89 , V_1 , V_90 , V_91 , V_95 ,
V_96 [ V_92 - 1 ] ) ;
return 1 ;
}
if ( ( V_1 -> V_84 & V_85 ) >= V_97 &&
( V_1 -> V_84 & V_85 ) <= V_98 ) {
switch ( V_1 -> V_84 & V_85 ) {
case V_86 :
F_45 ( V_89 , V_1 , V_90 , V_91 , V_95 ,
V_99 [ 0 ] ) ;
return 1 ;
case V_87 :
F_45 ( V_89 , V_1 , V_90 , V_91 , V_95 ,
V_99 [ 1 ] ) ;
return 1 ;
case V_100 :
F_45 ( V_89 , V_1 , V_90 , V_91 , V_95 ,
V_101 [ 0 ] ) ;
return 1 ;
case V_102 :
F_45 ( V_89 , V_1 , V_90 , V_91 , V_95 ,
V_101 [ 1 ] ) ;
return 1 ;
case V_103 :
F_45 ( V_89 , V_1 , V_90 , V_91 , V_95 ,
V_101 [ 2 ] ) ;
return 1 ;
default:
return - 1 ;
}
}
return 0 ;
}
