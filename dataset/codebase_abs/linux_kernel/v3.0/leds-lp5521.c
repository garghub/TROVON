static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_4 ,
V_7 [ V_6 -> V_8 - 1 ] ) ;
}
static inline struct V_4 * F_4 ( struct V_1 * V_9 )
{
return F_2 ( V_9 , struct V_4 ,
V_10 [ V_9 -> V_8 ] ) ;
}
static inline int F_5 ( struct V_11 * V_12 , T_1 V_13 , T_1 V_14 )
{
return F_6 ( V_12 , V_13 , V_14 ) ;
}
static int F_7 ( struct V_11 * V_12 , T_1 V_13 , T_1 * V_15 )
{
T_2 V_16 ;
V_16 = F_8 ( V_12 , V_13 ) ;
if ( V_16 < 0 )
return - V_17 ;
* V_15 = V_16 ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 , T_1 V_18 )
{
struct V_4 * V_19 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
int V_16 ;
T_1 V_20 ;
if ( V_18 == V_21 )
return 0 ;
if ( V_18 == V_22 )
V_18 = V_23 ;
V_16 = F_7 ( V_12 , V_24 , & V_20 ) ;
V_20 &= ~ ( V_6 -> V_25 ) ;
V_18 &= V_6 -> V_25 ;
V_20 |= V_18 ;
V_16 |= F_5 ( V_12 , V_24 , V_20 ) ;
return V_16 ;
}
static int F_10 ( struct V_5 * V_26 , const T_1 * V_27 )
{
struct V_4 * V_19 = F_3 ( V_26 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
int V_16 ;
int V_28 ;
T_1 V_18 ;
V_16 = F_9 ( V_26 , V_23 ) ;
F_11 ( 1000 , 2000 ) ;
V_16 |= F_7 ( V_12 , V_24 , & V_18 ) ;
F_5 ( V_12 , V_24 , V_23 ) ;
F_11 ( 1000 , 2000 ) ;
F_5 ( V_12 , V_24 , V_21 ) ;
F_11 ( 1000 , 2000 ) ;
V_28 = V_29 + V_26 -> V_30 * V_31 ;
F_12 ( V_12 ,
V_28 ,
V_31 ,
V_27 ) ;
V_16 |= F_5 ( V_12 , V_24 , V_18 ) ;
return V_16 ;
}
static int F_13 ( struct V_4 * V_19 , int V_9 , T_1 V_32 )
{
return F_5 ( V_19 -> V_12 ,
V_33 + V_19 -> V_10 [ V_9 ] . V_34 ,
V_32 ) ;
}
static void F_14 ( struct V_4 * V_19 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < F_15 ( V_19 -> V_7 ) ; V_35 ++ ) {
V_19 -> V_7 [ V_35 ] . V_8 = V_35 + 1 ;
V_19 -> V_7 [ V_35 ] . V_25 = V_36 >> ( V_35 * 2 ) ;
V_19 -> V_7 [ V_35 ] . V_30 = V_35 ;
}
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_4 * V_19 = F_17 ( V_12 ) ;
int V_16 ;
F_14 ( V_19 ) ;
V_16 = F_5 ( V_12 , V_24 , 0x3F ) ;
V_16 |= F_5 ( V_12 , V_37 ,
V_38 | V_39 | V_40 ) ;
V_16 |= F_5 ( V_12 , V_41 , 0 ) ;
V_16 |= F_5 ( V_12 , V_42 , 0 ) ;
V_16 |= F_5 ( V_12 , V_43 , 0 ) ;
V_16 |= F_5 ( V_12 , V_44 ,
V_45 | V_46 |
V_47 ) ;
F_11 ( 1000 , 2000 ) ;
return V_16 ;
}
static int F_18 ( struct V_4 * V_19 , char * V_15 )
{
int V_16 ;
T_1 V_48 ;
V_16 = F_7 ( V_19 -> V_12 , V_49 , & V_48 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_19 -> V_50 && V_19 -> V_50 -> V_51 == V_52 )
if ( ( V_48 & V_53 ) == 0 )
return - V_17 ;
return 0 ;
}
static void F_19 ( struct V_2 * V_3 ,
enum V_54 V_55 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
V_9 -> V_55 = ( T_1 ) V_55 ;
F_20 ( & V_9 -> V_56 ) ;
}
static void F_21 ( struct V_57 * V_58 )
{
struct V_1 * V_9 = F_2 ( V_58 ,
struct V_1 ,
V_56 ) ;
struct V_4 * V_19 = F_4 ( V_9 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
F_22 ( & V_19 -> V_59 ) ;
F_5 ( V_12 , V_60 + V_9 -> V_34 ,
V_9 -> V_55 ) ;
F_23 ( & V_19 -> V_59 ) ;
}
static int F_24 ( struct V_11 * V_12 )
{
int V_16 ;
T_1 V_15 ;
V_16 = F_5 ( V_12 , V_44 ,
V_45 | V_46 ) ;
if ( V_16 )
return V_16 ;
F_11 ( 1000 , 2000 ) ;
V_16 = F_7 ( V_12 , V_44 , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 != ( V_45 | V_46 ) )
return - V_61 ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 , T_1 V_18 )
{
int V_16 = 0 ;
if ( V_18 == V_6 -> V_18 && V_18 != V_62 )
return 0 ;
if ( V_18 == V_62 ) {
V_16 = F_9 ( V_6 , V_62 ) ;
} else if ( V_18 == V_21 ) {
F_9 ( V_6 , V_22 ) ;
F_9 ( V_6 , V_21 ) ;
} else if ( V_18 == V_22 ) {
F_9 ( V_6 , V_22 ) ;
}
V_6 -> V_18 = V_18 ;
return V_16 ;
}
static int F_26 ( struct V_5 * V_6 ,
const char * V_15 , T_3 V_63 )
{
struct V_4 * V_19 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
int V_16 , V_64 , V_65 = 0 , V_35 = 0 ;
char V_66 [ 3 ] ;
unsigned V_67 ;
T_1 V_27 [ V_68 ] = { 0 } ;
while ( ( V_65 < V_63 - 1 ) && ( V_35 < V_68 ) ) {
V_16 = sscanf ( V_15 + V_65 , L_1 , V_66 , & V_64 ) ;
if ( V_16 != 2 )
goto V_69;
V_16 = sscanf ( V_66 , L_2 , & V_67 ) ;
if ( V_16 != 1 )
goto V_69;
V_27 [ V_35 ] = ( T_1 ) V_67 ;
V_65 += V_64 ;
V_35 ++ ;
}
if ( V_35 % 2 )
goto V_69;
F_22 ( & V_19 -> V_59 ) ;
if ( V_6 -> V_18 == V_21 )
V_16 = F_10 ( V_6 , V_27 ) ;
else
V_16 = - V_70 ;
F_23 ( & V_19 -> V_59 ) ;
if ( V_16 ) {
F_27 ( & V_12 -> V_71 , L_3 ) ;
return V_16 ;
}
return V_63 ;
V_69:
F_27 ( & V_12 -> V_71 , L_4 ) ;
return - V_70 ;
}
static T_4 F_28 ( struct V_72 * V_71 ,
struct V_73 * V_74 ,
const char * V_15 , T_3 V_63 , int V_75 )
{
struct V_11 * V_12 = F_29 ( V_71 ) ;
struct V_4 * V_19 = F_17 ( V_12 ) ;
return F_26 ( & V_19 -> V_7 [ V_75 - 1 ] , V_15 , V_63 ) ;
}
static T_4 F_30 ( struct V_72 * V_71 ,
struct V_73 * V_74 ,
char * V_15 , int V_75 )
{
struct V_11 * V_12 = F_29 ( V_71 ) ;
struct V_4 * V_19 = F_17 ( V_12 ) ;
switch ( V_19 -> V_7 [ V_75 - 1 ] . V_18 ) {
case V_62 :
return sprintf ( V_15 , L_5 ) ;
case V_21 :
return sprintf ( V_15 , L_6 ) ;
case V_22 :
return sprintf ( V_15 , L_7 ) ;
default:
return sprintf ( V_15 , L_7 ) ;
}
}
static T_4 F_31 ( struct V_72 * V_71 ,
struct V_73 * V_74 ,
const char * V_15 , T_3 V_63 , int V_75 )
{
struct V_11 * V_12 = F_29 ( V_71 ) ;
struct V_4 * V_19 = F_17 ( V_12 ) ;
struct V_5 * V_6 = & V_19 -> V_7 [ V_75 - 1 ] ;
F_22 ( & V_19 -> V_59 ) ;
if ( ! strncmp ( V_15 , L_8 , 3 ) )
F_25 ( V_6 , V_62 ) ;
else if ( ! strncmp ( V_15 , L_9 , 4 ) )
F_25 ( V_6 , V_21 ) ;
else if ( ! strncmp ( V_15 , L_10 , 8 ) )
F_25 ( V_6 , V_22 ) ;
F_23 ( & V_19 -> V_59 ) ;
return V_63 ;
}
static T_4 F_32 ( struct V_72 * V_71 ,
struct V_73 * V_74 ,
char * V_15 )
{
struct V_2 * V_76 = F_33 ( V_71 ) ;
struct V_1 * V_9 = F_1 ( V_76 ) ;
return sprintf ( V_15 , L_11 , V_9 -> V_77 ) ;
}
static T_4 F_34 ( struct V_72 * V_71 ,
struct V_73 * V_74 ,
char * V_15 )
{
struct V_2 * V_76 = F_33 ( V_71 ) ;
struct V_1 * V_9 = F_1 ( V_76 ) ;
return sprintf ( V_15 , L_11 , V_9 -> V_78 ) ;
}
static T_4 F_35 ( struct V_72 * V_71 ,
struct V_73 * V_74 ,
const char * V_15 , T_3 V_63 )
{
struct V_2 * V_76 = F_33 ( V_71 ) ;
struct V_1 * V_9 = F_1 ( V_76 ) ;
struct V_4 * V_19 = F_4 ( V_9 ) ;
T_4 V_16 ;
unsigned long V_32 ;
if ( F_36 ( V_15 , 0 , & V_32 ) )
return - V_70 ;
if ( V_32 > V_9 -> V_77 )
return - V_70 ;
F_22 ( & V_19 -> V_59 ) ;
V_16 = F_13 ( V_19 , V_9 -> V_8 , V_32 ) ;
F_23 ( & V_19 -> V_59 ) ;
if ( V_16 < 0 )
return V_16 ;
V_9 -> V_78 = ( T_1 ) V_32 ;
return V_63 ;
}
static T_4 F_37 ( struct V_72 * V_71 ,
struct V_73 * V_74 ,
char * V_15 )
{
struct V_11 * V_12 = F_29 ( V_71 ) ;
struct V_4 * V_19 = F_17 ( V_12 ) ;
int V_16 ;
F_22 ( & V_19 -> V_59 ) ;
V_16 = F_18 ( V_19 , V_15 ) ;
F_23 ( & V_19 -> V_59 ) ;
return sprintf ( V_15 , L_12 , V_16 ? L_13 : L_14 ) ;
}
static int F_38 ( struct V_11 * V_12 )
{
struct V_72 * V_71 = & V_12 -> V_71 ;
return F_39 ( & V_71 -> V_79 , & V_80 ) ;
}
static void F_40 ( struct V_11 * V_12 )
{
struct V_4 * V_19 = F_17 ( V_12 ) ;
struct V_72 * V_71 = & V_12 -> V_71 ;
int V_35 ;
F_41 ( & V_71 -> V_79 , & V_80 ) ;
for ( V_35 = 0 ; V_35 < V_19 -> V_81 ; V_35 ++ )
F_41 ( & V_19 -> V_10 [ V_35 ] . V_3 . V_71 -> V_79 ,
& V_82 ) ;
}
static int T_5 F_42 ( struct V_1 * V_9 ,
struct V_11 * V_12 ,
int V_83 , struct V_84 * V_50 )
{
struct V_72 * V_71 = & V_12 -> V_71 ;
char V_85 [ 32 ] ;
int V_86 ;
if ( V_83 >= V_87 )
return - V_70 ;
if ( V_50 -> V_88 [ V_83 ] . V_78 == 0 )
return 0 ;
V_9 -> V_78 = V_50 -> V_88 [ V_83 ] . V_78 ;
V_9 -> V_77 = V_50 -> V_88 [ V_83 ] . V_77 ;
V_9 -> V_34 = V_50 -> V_88 [ V_83 ] . V_34 ;
if ( V_9 -> V_34 >= V_87 ) {
F_27 ( V_71 , L_15 ,
V_87 - 1 ) ;
return - V_70 ;
}
snprintf ( V_85 , sizeof( V_85 ) , L_16 ,
V_50 -> V_89 ? : V_12 -> V_85 , V_83 ) ;
V_9 -> V_3 . V_90 = F_19 ;
V_9 -> V_3 . V_85 = V_85 ;
V_86 = F_43 ( V_71 , & V_9 -> V_3 ) ;
if ( V_86 < 0 ) {
F_27 ( V_71 , L_17 , V_83 ) ;
return V_86 ;
}
V_86 = F_39 ( & V_9 -> V_3 . V_71 -> V_79 ,
& V_82 ) ;
if ( V_86 < 0 ) {
F_27 ( V_71 , L_18 ) ;
F_44 ( & V_9 -> V_3 ) ;
return V_86 ;
}
return 0 ;
}
static int T_5 F_45 ( struct V_11 * V_12 ,
const struct V_91 * V_8 )
{
struct V_4 * V_19 ;
struct V_84 * V_50 ;
int V_16 , V_35 , V_9 ;
V_19 = F_46 ( sizeof( * V_19 ) , V_92 ) ;
if ( ! V_19 )
return - V_93 ;
F_47 ( V_12 , V_19 ) ;
V_19 -> V_12 = V_12 ;
V_50 = V_12 -> V_71 . V_94 ;
if ( ! V_50 ) {
F_27 ( & V_12 -> V_71 , L_19 ) ;
V_16 = - V_70 ;
goto V_95;
}
F_48 ( & V_19 -> V_59 ) ;
V_19 -> V_50 = V_50 ;
if ( V_50 -> V_96 ) {
V_16 = V_50 -> V_96 () ;
if ( V_16 < 0 )
goto V_95;
}
if ( V_50 -> V_97 ) {
V_50 -> V_97 ( 0 ) ;
F_11 ( 1000 , 2000 ) ;
V_50 -> V_97 ( 1 ) ;
F_11 ( 1000 , 2000 ) ;
}
F_5 ( V_12 , V_98 , 0xff ) ;
F_11 ( 10000 , 20000 ) ;
V_16 = F_24 ( V_12 ) ;
if ( V_16 ) {
F_27 ( & V_12 -> V_71 , L_20 ) ;
goto V_99;
}
F_49 ( & V_12 -> V_71 , L_21 , V_8 -> V_85 ) ;
V_16 = F_16 ( V_12 ) ;
if ( V_16 < 0 ) {
F_27 ( & V_12 -> V_71 , L_22 ) ;
goto V_99;
}
V_19 -> V_100 = V_50 -> V_100 ;
V_19 -> V_81 = 0 ;
V_9 = 0 ;
for ( V_35 = 0 ; V_35 < V_50 -> V_100 ; V_35 ++ ) {
if ( V_50 -> V_88 [ V_35 ] . V_78 == 0 )
continue;
V_16 = F_42 ( & V_19 -> V_10 [ V_9 ] , V_12 , V_35 , V_50 ) ;
if ( V_16 ) {
F_27 ( & V_12 -> V_71 , L_23 ) ;
goto V_101;
}
V_19 -> V_81 ++ ;
V_19 -> V_10 [ V_9 ] . V_8 = V_9 ;
F_13 ( V_19 , V_9 ,
V_19 -> V_10 [ V_9 ] . V_78 ) ;
F_50 ( & ( V_19 -> V_10 [ V_9 ] . V_56 ) ,
F_21 ) ;
V_9 ++ ;
}
V_16 = F_38 ( V_12 ) ;
if ( V_16 ) {
F_27 ( & V_12 -> V_71 , L_24 ) ;
goto V_101;
}
return V_16 ;
V_101:
for ( V_35 = 0 ; V_35 < V_19 -> V_81 ; V_35 ++ ) {
F_44 ( & V_19 -> V_10 [ V_35 ] . V_3 ) ;
F_51 ( & V_19 -> V_10 [ V_35 ] . V_56 ) ;
}
V_99:
if ( V_50 -> V_97 )
V_50 -> V_97 ( 0 ) ;
if ( V_50 -> V_102 )
V_50 -> V_102 () ;
V_95:
F_52 ( V_19 ) ;
return V_16 ;
}
static int F_53 ( struct V_11 * V_12 )
{
struct V_4 * V_19 = F_17 ( V_12 ) ;
int V_35 ;
F_40 ( V_12 ) ;
for ( V_35 = 0 ; V_35 < V_19 -> V_81 ; V_35 ++ ) {
F_44 ( & V_19 -> V_10 [ V_35 ] . V_3 ) ;
F_51 ( & V_19 -> V_10 [ V_35 ] . V_56 ) ;
}
if ( V_19 -> V_50 -> V_97 )
V_19 -> V_50 -> V_97 ( 0 ) ;
if ( V_19 -> V_50 -> V_102 )
V_19 -> V_50 -> V_102 () ;
F_52 ( V_19 ) ;
return 0 ;
}
static int T_6 F_54 ( void )
{
int V_16 ;
V_16 = F_55 ( & V_103 ) ;
if ( V_16 < 0 )
F_56 ( V_104 L_25 ) ;
return V_16 ;
}
static void T_7 F_57 ( void )
{
F_58 ( & V_103 ) ;
}
