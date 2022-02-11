static bool F_1 ( const char * V_1 )
{
return ! ! strstr ( V_1 , L_1 ) ;
}
static bool F_2 ( const char * V_1 )
{
return ( ! ! strstr ( V_1 , L_2 ) && ! strstr ( V_1 , L_1 ) ) ;
}
static int F_3 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
unsigned int V_6 )
{
unsigned long long V_7 , div ;
int V_8 = 0 ;
T_1 V_9 , V_10 ;
div = ( unsigned long long ) F_4 ( V_3 -> V_11 ) ;
F_5 ( div , V_6 ) ;
V_7 = div ;
while ( div > V_3 -> V_12 ) {
V_8 ++ ;
div = V_7 ;
F_5 ( div , ( V_8 + 1 ) ) ;
}
V_7 = div ;
if ( V_8 > V_13 ) {
F_6 ( V_3 -> V_14 , L_3 ) ;
return - V_15 ;
}
F_7 ( V_3 -> V_16 , V_17 , & V_9 ) ;
if ( V_9 & V_18 )
return - V_19 ;
F_7 ( V_3 -> V_16 , V_20 , & V_10 ) ;
if ( ! ( V_10 & V_21 ) )
F_8 ( V_3 -> V_11 ) ;
F_9 ( V_3 -> V_16 , V_22 , V_8 ) ;
F_9 ( V_3 -> V_16 , V_23 , V_7 - 1 ) ;
F_10 ( V_3 -> V_16 , V_20 , V_24 , V_24 ) ;
if ( F_1 ( V_5 -> V_1 ) )
F_10 ( V_3 -> V_16 , V_25 , V_26 ,
0x2 << V_27 ) ;
else
F_10 ( V_3 -> V_16 , V_25 , V_28 ,
0x2 << V_29 ) ;
F_10 ( V_3 -> V_16 , V_30 , V_31 , V_31 ) ;
F_10 ( V_3 -> V_16 , V_20 , V_21 , V_21 ) ;
return 0 ;
}
static void F_11 ( struct V_2 * V_3 )
{
T_1 V_9 , V_10 ;
F_7 ( V_3 -> V_16 , V_17 , & V_9 ) ;
if ( V_9 & V_18 )
return;
F_7 ( V_3 -> V_16 , V_20 , & V_10 ) ;
if ( V_10 & V_21 )
F_12 ( V_3 -> V_11 ) ;
F_10 ( V_3 -> V_16 , V_20 , V_24 , 0 ) ;
F_10 ( V_3 -> V_16 , V_20 , V_21 , 0 ) ;
F_9 ( V_3 -> V_16 , V_22 , 0 ) ;
F_9 ( V_3 -> V_16 , V_23 , 0 ) ;
F_10 ( V_3 -> V_16 , V_30 , V_31 , V_31 ) ;
}
static T_2 F_13 ( struct V_32 * V_14 ,
struct V_33 * V_34 ,
const char * V_35 , T_3 V_36 )
{
struct V_4 * V_5 = F_14 ( V_14 ) ;
struct V_2 * V_3 = F_15 ( V_5 ) ;
unsigned int V_37 ;
int V_38 ;
V_38 = F_16 ( V_35 , 10 , & V_37 ) ;
if ( V_38 )
return V_38 ;
if ( V_37 == 0 ) {
F_11 ( V_3 ) ;
} else {
V_38 = F_3 ( V_3 , V_5 , V_37 ) ;
if ( V_38 )
return V_38 ;
}
return V_36 ;
}
static T_2 F_17 ( struct V_32 * V_14 ,
struct V_33 * V_34 , char * V_35 )
{
struct V_4 * V_5 = F_14 ( V_14 ) ;
struct V_2 * V_3 = F_15 ( V_5 ) ;
T_1 V_39 , V_40 , V_10 ;
unsigned long long V_37 = 0 ;
F_7 ( V_3 -> V_16 , V_20 , & V_10 ) ;
F_7 ( V_3 -> V_16 , V_22 , & V_39 ) ;
F_7 ( V_3 -> V_16 , V_23 , & V_40 ) ;
if ( V_10 & V_21 ) {
V_37 = ( unsigned long long ) F_4 ( V_3 -> V_11 ) ;
F_5 ( V_37 , V_39 + 1 ) ;
F_5 ( V_37 , V_40 + 1 ) ;
}
return sprintf ( V_35 , L_4 , ( unsigned int ) V_37 ) ;
}
static T_2 F_18 ( struct V_32 * V_14 ,
struct V_33 * V_34 ,
char * V_35 )
{
struct V_2 * V_3 = F_19 ( V_14 ) ;
struct V_4 * V_5 = F_14 ( V_14 ) ;
T_1 V_41 ;
F_7 ( V_3 -> V_16 , V_25 , & V_41 ) ;
if ( F_1 ( V_5 -> V_1 ) )
V_41 = ( V_41 & V_26 ) >> V_27 ;
else
V_41 = ( V_41 & V_28 ) >> V_29 ;
return snprintf ( V_35 , V_42 , L_5 , V_43 [ V_41 ] ) ;
}
static T_2 F_20 ( struct V_32 * V_14 ,
struct V_33 * V_34 ,
const char * V_35 , T_3 V_36 )
{
struct V_2 * V_3 = F_19 ( V_14 ) ;
struct V_4 * V_5 = F_14 ( V_14 ) ;
T_1 V_44 , V_45 , V_46 ;
int V_47 ;
if ( F_1 ( V_5 -> V_1 ) ) {
V_44 = V_26 ;
V_45 = V_27 ;
V_46 = V_48 ;
} else {
V_44 = V_28 ;
V_45 = V_29 ;
V_46 = V_49 ;
}
for ( V_47 = 0 ; V_47 <= V_46 ; V_47 ++ ) {
if ( ! strncmp ( V_43 [ V_47 ] , V_35 ,
strlen ( V_43 [ V_47 ] ) ) ) {
F_10 ( V_3 -> V_16 , V_25 , V_44 ,
V_47 << V_45 ) ;
F_10 ( V_3 -> V_16 , V_30 ,
V_31 , V_31 ) ;
return V_36 ;
}
}
return - V_15 ;
}
static T_2 F_21 ( struct V_32 * V_14 ,
struct V_33 * V_34 ,
char * V_35 )
{
struct V_4 * V_5 = F_14 ( V_14 ) ;
unsigned int V_47 , V_46 ;
T_3 V_36 = 0 ;
if ( F_1 ( V_5 -> V_1 ) )
V_46 = V_48 ;
else
V_46 = V_49 ;
for ( V_47 = 0 ; V_47 <= V_46 ; V_47 ++ )
V_36 += F_22 ( V_35 + V_36 , V_42 - V_36 ,
L_6 , V_43 [ V_47 ] ) ;
V_35 [ V_36 - 1 ] = '\n' ;
return V_36 ;
}
static int F_23 ( struct V_2 * V_3 )
{
int V_38 ;
const char * const * V_50 = V_3 -> V_51 ;
while ( V_50 && * V_50 ) {
struct V_4 * V_5 ;
bool V_52 = F_2 ( * V_50 ) ;
bool V_53 = F_1 ( * V_50 ) ;
if ( V_53 && ! V_3 -> V_54 ) {
V_50 ++ ;
continue;
}
V_5 = F_24 ( V_3 -> V_14 , L_7 , * V_50 ) ;
if ( ! V_5 )
return - V_55 ;
V_5 -> V_14 . V_56 = V_3 -> V_14 -> V_56 ;
V_5 -> V_57 = & V_58 ;
if ( V_52 || V_53 )
V_5 -> V_14 . V_59 = V_60 ;
F_25 ( V_5 , V_3 ) ;
V_38 = F_26 ( V_3 -> V_14 , V_5 ) ;
if ( V_38 )
return V_38 ;
V_50 ++ ;
}
return 0 ;
}
static int F_27 ( struct V_61 * V_62 ,
struct V_63 const * V_64 ,
int * V_65 , int * V_66 , long V_44 )
{
struct V_2 * V_3 = F_28 ( V_62 ) ;
T_1 V_67 ;
switch ( V_44 ) {
case V_68 :
F_7 ( V_3 -> V_16 , V_69 , & V_67 ) ;
* V_65 = V_67 ;
return V_70 ;
case V_71 :
F_7 ( V_3 -> V_16 , V_20 , & V_67 ) ;
* V_65 = ( V_67 & V_21 ) ? 1 : 0 ;
return V_70 ;
case V_72 :
F_7 ( V_3 -> V_16 , V_73 , & V_67 ) ;
V_67 &= V_74 ;
* V_65 = 1 ;
* V_66 = 0 ;
if ( V_67 == 3 )
* V_66 = 2 ;
return V_75 ;
}
return - V_15 ;
}
static int F_29 ( struct V_61 * V_62 ,
struct V_63 const * V_64 ,
int V_65 , int V_66 , long V_44 )
{
struct V_2 * V_3 = F_28 ( V_62 ) ;
T_1 V_67 ;
switch ( V_44 ) {
case V_68 :
return F_9 ( V_3 -> V_16 , V_69 , V_65 ) ;
case V_72 :
return - V_15 ;
case V_71 :
if ( V_65 ) {
F_7 ( V_3 -> V_16 , V_20 , & V_67 ) ;
if ( ! ( V_67 & V_21 ) )
F_8 ( V_3 -> V_11 ) ;
F_10 ( V_3 -> V_16 , V_20 , V_21 ,
V_21 ) ;
} else {
F_7 ( V_3 -> V_16 , V_20 , & V_67 ) ;
F_10 ( V_3 -> V_16 , V_20 , V_21 ,
0 ) ;
if ( V_67 & V_21 )
F_12 ( V_3 -> V_11 ) ;
}
return 0 ;
}
return - V_15 ;
}
static int F_30 ( struct V_61 * V_62 ,
struct V_4 * V_5 )
{
struct V_2 * V_3 = F_28 ( V_62 ) ;
const char * const * V_50 = V_3 -> V_76 ;
unsigned int V_47 = 0 ;
if ( ! F_31 ( V_5 ) )
return - V_15 ;
while ( V_50 && * V_50 ) {
if ( ! strncmp ( V_5 -> V_1 , * V_50 , strlen ( V_5 -> V_1 ) ) ) {
F_10 ( V_3 -> V_16 ,
V_73 , V_77 ,
V_47 << V_78 ) ;
return 0 ;
}
V_50 ++ ;
V_47 ++ ;
}
return - V_15 ;
}
static int F_32 ( struct V_61 * V_62 ,
const struct V_63 * V_64 ,
unsigned int V_79 )
{
struct V_2 * V_3 = F_28 ( V_62 ) ;
F_10 ( V_3 -> V_16 , V_73 , V_74 , V_74 ) ;
return 0 ;
}
static int F_33 ( struct V_61 * V_62 ,
const struct V_63 * V_64 )
{
struct V_2 * V_3 = F_28 ( V_62 ) ;
T_1 V_80 ;
F_7 ( V_3 -> V_16 , V_73 , & V_80 ) ;
return ( V_80 & V_74 ) == V_74 ? 0 : - V_15 ;
}
static int F_34 ( int V_79 )
{
switch ( V_79 ) {
case 0 :
return 0 ;
case 1 :
return 5 ;
case 2 :
return 6 ;
}
return - V_15 ;
}
static int F_35 ( struct V_61 * V_62 ,
const struct V_63 * V_64 ,
unsigned int V_79 )
{
struct V_2 * V_3 = F_28 ( V_62 ) ;
int V_81 = F_34 ( V_79 ) ;
T_1 V_65 ;
if ( V_81 < 0 )
return V_81 ;
if ( V_81 == 6 ) {
F_7 ( V_3 -> V_16 , V_20 , & V_65 ) ;
if ( ! ( V_65 & V_21 ) )
F_8 ( V_3 -> V_11 ) ;
}
F_10 ( V_3 -> V_16 , V_73 , V_74 , V_81 ) ;
return 0 ;
}
static int F_36 ( int V_79 )
{
switch ( V_79 ) {
case 0 :
return 0 ;
case 5 :
return 1 ;
case 6 :
return 2 ;
}
return - V_15 ;
}
static int F_37 ( struct V_61 * V_62 ,
const struct V_63 * V_64 )
{
struct V_2 * V_3 = F_28 ( V_62 ) ;
T_1 V_80 ;
F_7 ( V_3 -> V_16 , V_73 , & V_80 ) ;
V_80 &= V_74 ;
return F_36 ( V_80 ) ;
}
static int F_38 ( struct V_61 * V_62 ,
const struct V_63 * V_64 ,
unsigned int V_79 )
{
struct V_2 * V_3 = F_28 ( V_62 ) ;
F_10 ( V_3 -> V_16 , V_73 , V_74 , V_79 + 1 ) ;
return 0 ;
}
static int F_39 ( struct V_61 * V_62 ,
const struct V_63 * V_64 )
{
struct V_2 * V_3 = F_28 ( V_62 ) ;
T_1 V_80 ;
int V_79 ;
F_7 ( V_3 -> V_16 , V_73 , & V_80 ) ;
V_79 = ( V_80 & V_74 ) - 1 ;
if ( ( V_79 < 0 ) || ( V_79 > F_40 ( V_82 ) ) )
return - V_15 ;
return V_79 ;
}
static int F_41 ( struct V_61 * V_62 ,
const struct V_63 * V_64 ,
unsigned int V_83 )
{
struct V_2 * V_3 = F_28 ( V_62 ) ;
T_1 V_65 ;
int V_79 ;
F_7 ( V_3 -> V_16 , V_73 , & V_65 ) ;
V_79 = ( V_65 & V_74 ) - 1 ;
if ( ( V_79 >= 0 ) || ( V_79 < F_40 ( V_82 ) ) )
return - V_19 ;
return F_10 ( V_3 -> V_16 , V_20 , V_84 ,
V_83 ? V_84 : 0 ) ;
}
static int F_42 ( struct V_61 * V_62 ,
const struct V_63 * V_64 )
{
struct V_2 * V_3 = F_28 ( V_62 ) ;
T_1 V_10 ;
F_7 ( V_3 -> V_16 , V_20 , & V_10 ) ;
return ( ( V_10 & V_84 ) ? 1 : 0 ) ;
}
static T_2 F_43 ( struct V_61 * V_62 ,
T_4 V_85 ,
const struct V_63 * V_64 ,
char * V_35 )
{
struct V_2 * V_3 = F_28 ( V_62 ) ;
T_1 V_40 ;
F_7 ( V_3 -> V_16 , V_23 , & V_40 ) ;
return snprintf ( V_35 , V_42 , L_8 , V_40 ) ;
}
static T_2 F_44 ( struct V_61 * V_62 ,
T_4 V_85 ,
const struct V_63 * V_64 ,
const char * V_35 , T_3 V_36 )
{
struct V_2 * V_3 = F_28 ( V_62 ) ;
unsigned int V_86 ;
int V_38 ;
V_38 = F_16 ( V_35 , 0 , & V_86 ) ;
if ( V_38 )
return V_38 ;
F_10 ( V_3 -> V_16 , V_20 , V_24 , 0 ) ;
F_9 ( V_3 -> V_16 , V_23 , V_86 ) ;
return V_36 ;
}
static struct V_2 * F_45 ( struct V_32 * V_14 )
{
struct V_61 * V_62 ;
int V_38 ;
V_62 = F_46 ( V_14 ,
sizeof( struct V_2 ) ) ;
if ( ! V_62 )
return NULL ;
V_62 -> V_1 = F_47 ( V_14 ) ;
V_62 -> V_14 . V_56 = V_14 ;
V_62 -> V_87 = & V_88 ;
V_62 -> V_89 = V_90 ;
V_62 -> V_91 = 1 ;
V_62 -> V_92 = & V_93 ;
V_62 -> V_14 . V_94 = V_14 -> V_94 ;
V_38 = F_48 ( V_14 , V_62 ) ;
if ( V_38 )
return NULL ;
return F_28 ( V_62 ) ;
}
bool F_31 ( struct V_4 * V_5 )
{
return ( V_5 -> V_57 == & V_58 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
T_1 V_65 ;
F_10 ( V_3 -> V_16 , V_25 , V_26 , V_26 ) ;
F_7 ( V_3 -> V_16 , V_25 , & V_65 ) ;
F_10 ( V_3 -> V_16 , V_25 , V_26 , 0 ) ;
V_3 -> V_54 = ! ! V_65 ;
}
static int F_50 ( struct V_95 * V_96 )
{
struct V_32 * V_14 = & V_96 -> V_14 ;
struct V_2 * V_3 ;
struct V_97 * V_98 = F_19 ( V_96 -> V_14 . V_56 ) ;
const struct V_99 * V_100 ;
unsigned int V_101 ;
int V_38 ;
if ( F_51 ( V_14 -> V_94 , L_9 , & V_101 ) )
return - V_15 ;
V_100 = ( const struct V_99 * )
F_52 ( V_14 -> V_102 -> V_103 , V_14 ) -> V_104 ;
if ( V_101 >= F_40 ( V_105 ) ||
V_101 >= V_100 -> V_106 )
return - V_15 ;
if ( * V_100 -> V_107 [ V_101 ] )
V_3 = F_45 ( V_14 ) ;
else
V_3 = F_53 ( V_14 , sizeof( * V_3 ) , V_108 ) ;
if ( ! V_3 )
return - V_55 ;
V_3 -> V_14 = V_14 ;
V_3 -> V_16 = V_98 -> V_16 ;
V_3 -> V_11 = V_98 -> V_11 ;
V_3 -> V_12 = V_98 -> V_12 ;
V_3 -> V_51 = V_105 [ V_101 ] ;
V_3 -> V_76 = V_100 -> V_107 [ V_101 ] ;
F_49 ( V_3 ) ;
V_38 = F_23 ( V_3 ) ;
if ( V_38 )
return V_38 ;
F_54 ( V_96 , V_3 ) ;
return 0 ;
}
