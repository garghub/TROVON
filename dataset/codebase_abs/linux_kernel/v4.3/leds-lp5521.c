static inline void F_1 ( void )
{
F_2 ( 200 , 300 ) ;
}
static inline void F_3 ( void )
{
F_2 ( 500 , 600 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_3 = V_3 ;
F_5 ( V_2 -> V_4 , V_5 + V_2 -> V_6 ,
V_3 ) ;
}
static void F_6 ( struct V_7 * V_4 )
{
enum V_8 V_9 = V_4 -> V_10 ;
T_1 V_11 [] = {
[ V_12 ] = V_13 ,
[ V_14 ] = V_15 ,
[ V_16 ] = V_17 ,
} ;
T_1 V_18 [] = {
[ V_12 ] = V_19 ,
[ V_14 ] = V_20 ,
[ V_16 ] = V_21 ,
} ;
F_7 ( V_4 , V_22 , V_11 [ V_9 ] , V_18 [ V_9 ] ) ;
F_1 () ;
}
static void F_8 ( struct V_7 * V_4 )
{
F_5 ( V_4 , V_22 , 0 ) ;
F_1 () ;
}
static void F_9 ( struct V_7 * V_4 )
{
enum V_8 V_9 = V_4 -> V_10 ;
T_1 V_11 [] = {
[ V_12 ] = V_13 ,
[ V_14 ] = V_15 ,
[ V_16 ] = V_17 ,
} ;
F_7 ( V_4 , V_22 , V_11 [ V_9 ] , 0 ) ;
F_1 () ;
}
static void F_10 ( struct V_7 * V_4 , bool V_23 )
{
int V_24 ;
T_1 V_25 ;
T_1 V_26 ;
if ( ! V_23 ) {
F_9 ( V_4 ) ;
F_5 ( V_4 , V_22 , V_27 ) ;
F_1 () ;
return;
}
V_24 = F_11 ( V_4 , V_22 , & V_25 ) ;
if ( V_24 )
return;
V_24 = F_11 ( V_4 , V_28 , & V_26 ) ;
if ( V_24 )
return;
if ( F_12 ( V_25 ) ) {
V_25 = ( V_25 & ~ V_13 ) | V_29 ;
V_26 = ( V_26 & ~ V_30 ) | V_29 ;
}
if ( F_13 ( V_25 ) ) {
V_25 = ( V_25 & ~ V_15 ) | V_31 ;
V_26 = ( V_26 & ~ V_32 ) | V_31 ;
}
if ( F_14 ( V_25 ) ) {
V_25 = ( V_25 & ~ V_17 ) | V_33 ;
V_26 = ( V_26 & ~ V_34 ) | V_33 ;
}
F_5 ( V_4 , V_22 , V_25 ) ;
F_1 () ;
F_7 ( V_4 , V_28 , V_35 , V_26 ) ;
F_3 () ;
}
static int F_15 ( struct V_7 * V_4 ,
const T_1 * V_36 , T_2 V_37 )
{
enum V_8 V_9 = V_4 -> V_10 ;
T_1 V_38 [ V_39 ] = { 0 } ;
T_1 V_40 [] = {
[ V_12 ] = V_41 ,
[ V_14 ] = V_42 ,
[ V_16 ] = V_43 ,
} ;
unsigned V_44 ;
char V_45 [ 3 ] ;
int V_46 ;
int V_24 ;
int V_47 = 0 ;
int V_48 = 0 ;
while ( ( V_47 < V_37 - 1 ) && ( V_48 < V_39 ) ) {
V_24 = sscanf ( V_36 + V_47 , L_1 , V_45 , & V_46 ) ;
if ( V_24 != 1 )
goto V_49;
V_24 = sscanf ( V_45 , L_2 , & V_44 ) ;
if ( V_24 != 1 )
goto V_49;
V_38 [ V_48 ] = ( T_1 ) V_44 ;
V_47 += V_46 ;
V_48 ++ ;
}
if ( V_48 % 2 )
goto V_49;
for ( V_48 = 0 ; V_48 < V_39 ; V_48 ++ ) {
V_24 = F_5 ( V_4 , V_40 [ V_9 ] + V_48 , V_38 [ V_48 ] ) ;
if ( V_24 )
return - V_50 ;
}
return V_37 ;
V_49:
F_16 ( & V_4 -> V_51 -> V_52 , L_3 ) ;
return - V_50 ;
}
static void F_17 ( struct V_7 * V_4 )
{
const struct V_53 * V_54 = V_4 -> V_54 ;
if ( V_54 -> V_37 > V_39 ) {
F_16 ( & V_4 -> V_51 -> V_52 , L_4 ,
V_54 -> V_37 ) ;
return;
}
F_6 ( V_4 ) ;
F_15 ( V_4 , V_54 -> V_36 , V_54 -> V_37 ) ;
}
static int F_18 ( struct V_7 * V_4 )
{
int V_24 ;
T_1 V_18 ;
V_24 = F_11 ( V_4 , V_55 , & V_18 ) ;
if ( V_24 ) {
F_16 ( & V_4 -> V_51 -> V_52 , L_5 ) ;
return V_24 ;
}
if ( V_18 != V_56 ) {
F_16 ( & V_4 -> V_51 -> V_52 ,
L_6 ,
V_56 , V_18 ) ;
V_24 = - V_50 ;
return V_24 ;
}
F_2 ( 10000 , 20000 ) ;
V_24 = F_5 ( V_4 , V_22 , V_27 ) ;
V_18 = V_57 ;
if ( ! F_19 ( V_4 ) )
V_18 |= V_58 ;
V_24 = F_5 ( V_4 , V_59 , V_18 ) ;
if ( V_24 )
return V_24 ;
F_5 ( V_4 , V_60 , 0 ) ;
F_5 ( V_4 , V_61 , 0 ) ;
F_5 ( V_4 , V_62 , 0 ) ;
V_24 = F_5 ( V_4 , V_28 , V_63 ) ;
if ( V_24 )
return V_24 ;
F_3 () ;
return 0 ;
}
static int F_20 ( struct V_7 * V_4 , char * V_64 )
{
struct V_65 * V_66 = V_4 -> V_66 ;
int V_24 ;
T_1 V_67 ;
V_24 = F_11 ( V_4 , V_68 , & V_67 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_66 -> V_69 != V_70 )
return 0 ;
if ( ( V_67 & V_71 ) == 0 )
return - V_72 ;
return 0 ;
}
static void F_21 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_22 ( V_74 , struct V_1 ,
V_75 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
F_23 ( & V_4 -> V_76 ) ;
F_5 ( V_4 , V_77 + V_2 -> V_6 ,
V_2 -> V_78 ) ;
F_24 ( & V_4 -> V_76 ) ;
}
static T_3 F_25 ( struct V_79 * V_52 ,
struct V_80 * V_81 ,
char * V_64 , int V_82 )
{
struct V_1 * V_2 = F_26 ( F_27 ( V_52 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
enum V_83 V_25 = V_4 -> V_84 [ V_82 - 1 ] . V_25 ;
switch ( V_25 ) {
case V_85 :
return sprintf ( V_64 , L_7 ) ;
case V_86 :
return sprintf ( V_64 , L_8 ) ;
case V_87 :
default:
return sprintf ( V_64 , L_9 ) ;
}
}
static T_3 F_28 ( struct V_79 * V_52 ,
struct V_80 * V_81 ,
const char * V_64 , T_2 V_88 , int V_82 )
{
struct V_1 * V_2 = F_26 ( F_27 ( V_52 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
struct V_89 * V_90 = & V_4 -> V_84 [ V_82 - 1 ] ;
F_23 ( & V_4 -> V_76 ) ;
V_4 -> V_10 = V_82 ;
if ( ! strncmp ( V_64 , L_10 , 3 ) ) {
F_10 ( V_4 , true ) ;
V_90 -> V_25 = V_85 ;
} else if ( ! strncmp ( V_64 , L_11 , 4 ) ) {
F_9 ( V_4 ) ;
F_6 ( V_4 ) ;
V_90 -> V_25 = V_86 ;
} else if ( ! strncmp ( V_64 , L_12 , 8 ) ) {
F_9 ( V_4 ) ;
V_90 -> V_25 = V_87 ;
}
F_24 ( & V_4 -> V_76 ) ;
return V_88 ;
}
static T_3 F_29 ( struct V_79 * V_52 ,
struct V_80 * V_81 ,
const char * V_64 , T_2 V_88 , int V_82 )
{
struct V_1 * V_2 = F_26 ( F_27 ( V_52 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_24 ;
F_23 ( & V_4 -> V_76 ) ;
V_4 -> V_10 = V_82 ;
F_6 ( V_4 ) ;
V_24 = F_15 ( V_4 , V_64 , V_88 ) ;
F_24 ( & V_4 -> V_76 ) ;
return V_24 ;
}
static T_3 F_30 ( struct V_79 * V_52 ,
struct V_80 * V_81 ,
char * V_64 )
{
struct V_1 * V_2 = F_26 ( F_27 ( V_52 ) ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_24 ;
F_23 ( & V_4 -> V_76 ) ;
V_24 = F_20 ( V_4 , V_64 ) ;
F_24 ( & V_4 -> V_76 ) ;
return F_31 ( V_64 , V_91 , L_13 , V_24 ? L_14 : L_15 ) ;
}
static int F_32 ( struct V_92 * V_93 ,
const struct V_94 * V_95 )
{
int V_24 ;
struct V_7 * V_4 ;
struct V_1 * V_2 ;
struct V_65 * V_66 = F_33 ( & V_93 -> V_52 ) ;
struct V_96 * V_97 = V_93 -> V_52 . V_98 ;
if ( ! V_66 ) {
if ( V_97 ) {
V_66 = F_34 ( & V_93 -> V_52 , V_97 ) ;
if ( F_35 ( V_66 ) )
return F_36 ( V_66 ) ;
} else {
F_16 ( & V_93 -> V_52 , L_16 ) ;
return - V_50 ;
}
}
V_4 = F_37 ( & V_93 -> V_52 , sizeof( * V_4 ) , V_99 ) ;
if ( ! V_4 )
return - V_100 ;
V_2 = F_37 ( & V_93 -> V_52 ,
sizeof( * V_2 ) * V_66 -> V_101 , V_99 ) ;
if ( ! V_2 )
return - V_100 ;
V_4 -> V_51 = V_93 ;
V_4 -> V_66 = V_66 ;
V_4 -> V_102 = & V_103 ;
F_38 ( & V_4 -> V_76 ) ;
F_39 ( V_93 , V_2 ) ;
V_24 = F_40 ( V_4 ) ;
if ( V_24 )
goto V_104;
F_41 ( & V_93 -> V_52 , L_17 , V_95 -> V_105 ) ;
V_24 = F_42 ( V_2 , V_4 ) ;
if ( V_24 )
goto V_106;
V_24 = F_43 ( V_4 ) ;
if ( V_24 ) {
F_16 ( & V_93 -> V_52 , L_18 ) ;
goto V_107;
}
return 0 ;
V_107:
F_44 ( V_2 , V_4 ) ;
V_106:
F_45 ( V_4 ) ;
V_104:
return V_24 ;
}
static int F_46 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_26 ( V_93 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
F_8 ( V_4 ) ;
F_47 ( V_4 ) ;
F_44 ( V_2 , V_4 ) ;
F_45 ( V_4 ) ;
return 0 ;
}
