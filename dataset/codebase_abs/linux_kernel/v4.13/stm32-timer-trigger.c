static bool F_1 ( const char * V_1 )
{
return ! ! strstr ( V_1 , L_1 ) ;
}
static int F_2 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
unsigned int V_6 )
{
unsigned long long V_7 , div ;
int V_8 = 0 ;
T_1 V_9 , V_10 ;
div = ( unsigned long long ) F_3 ( V_3 -> V_11 ) ;
F_4 ( div , V_6 ) ;
V_7 = div ;
while ( div > V_3 -> V_12 ) {
V_8 ++ ;
div = V_7 ;
F_4 ( div , ( V_8 + 1 ) ) ;
}
V_7 = div ;
if ( V_8 > V_13 ) {
F_5 ( V_3 -> V_14 , L_2 ) ;
return - V_15 ;
}
F_6 ( V_3 -> V_16 , V_17 , & V_9 ) ;
if ( V_9 & V_18 )
return - V_19 ;
F_6 ( V_3 -> V_16 , V_20 , & V_10 ) ;
if ( ! ( V_10 & V_21 ) )
F_7 ( V_3 -> V_11 ) ;
F_8 ( V_3 -> V_16 , V_22 , V_8 ) ;
F_8 ( V_3 -> V_16 , V_23 , V_7 - 1 ) ;
F_9 ( V_3 -> V_16 , V_20 , V_24 , V_24 ) ;
if ( F_1 ( V_5 -> V_1 ) )
F_9 ( V_3 -> V_16 , V_25 , V_26 ,
0x2 << V_27 ) ;
else
F_9 ( V_3 -> V_16 , V_25 , V_28 ,
0x2 << V_29 ) ;
F_9 ( V_3 -> V_16 , V_30 , V_31 , V_31 ) ;
F_9 ( V_3 -> V_16 , V_20 , V_21 , V_21 ) ;
return 0 ;
}
static void F_10 ( struct V_2 * V_3 )
{
T_1 V_9 , V_10 ;
F_6 ( V_3 -> V_16 , V_17 , & V_9 ) ;
if ( V_9 & V_18 )
return;
F_6 ( V_3 -> V_16 , V_20 , & V_10 ) ;
if ( V_10 & V_21 )
F_11 ( V_3 -> V_11 ) ;
F_9 ( V_3 -> V_16 , V_20 , V_21 , 0 ) ;
F_8 ( V_3 -> V_16 , V_22 , 0 ) ;
F_8 ( V_3 -> V_16 , V_23 , 0 ) ;
F_9 ( V_3 -> V_16 , V_30 , V_31 , V_31 ) ;
}
static T_2 F_12 ( struct V_32 * V_14 ,
struct V_33 * V_34 ,
const char * V_35 , T_3 V_36 )
{
struct V_4 * V_5 = F_13 ( V_14 ) ;
struct V_2 * V_3 = F_14 ( V_5 ) ;
unsigned int V_37 ;
int V_38 ;
V_38 = F_15 ( V_35 , 10 , & V_37 ) ;
if ( V_38 )
return V_38 ;
if ( V_37 == 0 ) {
F_10 ( V_3 ) ;
} else {
V_38 = F_2 ( V_3 , V_5 , V_37 ) ;
if ( V_38 )
return V_38 ;
}
return V_36 ;
}
static T_2 F_16 ( struct V_32 * V_14 ,
struct V_33 * V_34 , char * V_35 )
{
struct V_4 * V_5 = F_13 ( V_14 ) ;
struct V_2 * V_3 = F_14 ( V_5 ) ;
T_1 V_39 , V_40 , V_10 ;
unsigned long long V_37 = 0 ;
F_6 ( V_3 -> V_16 , V_20 , & V_10 ) ;
F_6 ( V_3 -> V_16 , V_22 , & V_39 ) ;
F_6 ( V_3 -> V_16 , V_23 , & V_40 ) ;
if ( V_10 & V_21 ) {
V_37 = ( unsigned long long ) F_3 ( V_3 -> V_11 ) ;
F_4 ( V_37 , V_39 + 1 ) ;
F_4 ( V_37 , V_40 + 1 ) ;
}
return sprintf ( V_35 , L_3 , ( unsigned int ) V_37 ) ;
}
static T_2 F_17 ( struct V_32 * V_14 ,
struct V_33 * V_34 ,
char * V_35 )
{
struct V_2 * V_3 = F_18 ( V_14 ) ;
struct V_4 * V_5 = F_13 ( V_14 ) ;
T_1 V_41 ;
F_6 ( V_3 -> V_16 , V_25 , & V_41 ) ;
if ( F_1 ( V_5 -> V_1 ) )
V_41 = ( V_41 & V_26 ) >> V_27 ;
else
V_41 = ( V_41 & V_28 ) >> V_29 ;
return snprintf ( V_35 , V_42 , L_4 , V_43 [ V_41 ] ) ;
}
static T_2 F_19 ( struct V_32 * V_14 ,
struct V_33 * V_34 ,
const char * V_35 , T_3 V_36 )
{
struct V_2 * V_3 = F_18 ( V_14 ) ;
struct V_4 * V_5 = F_13 ( V_14 ) ;
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
F_9 ( V_3 -> V_16 , V_25 , V_44 ,
V_47 << V_45 ) ;
F_9 ( V_3 -> V_16 , V_30 ,
V_31 , V_31 ) ;
return V_36 ;
}
}
return - V_15 ;
}
static T_2 F_20 ( struct V_32 * V_14 ,
struct V_33 * V_34 ,
char * V_35 )
{
struct V_4 * V_5 = F_13 ( V_14 ) ;
unsigned int V_47 , V_46 ;
T_3 V_36 = 0 ;
if ( F_1 ( V_5 -> V_1 ) )
V_46 = V_48 ;
else
V_46 = V_49 ;
for ( V_47 = 0 ; V_47 <= V_46 ; V_47 ++ )
V_36 += F_21 ( V_35 + V_36 , V_42 - V_36 ,
L_5 , V_43 [ V_47 ] ) ;
V_35 [ V_36 - 1 ] = '\n' ;
return V_36 ;
}
static int F_22 ( struct V_2 * V_3 )
{
int V_38 ;
const char * const * V_50 = V_3 -> V_51 ;
while ( V_50 && * V_50 ) {
struct V_4 * V_5 ;
bool V_52 = F_1 ( * V_50 ) ;
if ( V_52 && ! V_3 -> V_53 ) {
V_50 ++ ;
continue;
}
V_5 = F_23 ( V_3 -> V_14 , L_6 , * V_50 ) ;
if ( ! V_5 )
return - V_54 ;
V_5 -> V_14 . V_55 = V_3 -> V_14 -> V_55 ;
V_5 -> V_56 = & V_57 ;
if ( V_50 == V_3 -> V_51 || V_52 )
V_5 -> V_14 . V_58 = V_59 ;
F_24 ( V_5 , V_3 ) ;
V_38 = F_25 ( V_3 -> V_14 , V_5 ) ;
if ( V_38 )
return V_38 ;
V_50 ++ ;
}
return 0 ;
}
static int F_26 ( struct V_60 * V_61 ,
struct V_62 const * V_63 ,
int * V_64 , int * V_65 , long V_44 )
{
struct V_2 * V_3 = F_27 ( V_61 ) ;
T_1 V_66 ;
switch ( V_44 ) {
case V_67 :
F_6 ( V_3 -> V_16 , V_68 , & V_66 ) ;
* V_64 = V_66 ;
return V_69 ;
case V_70 :
F_6 ( V_3 -> V_16 , V_20 , & V_66 ) ;
* V_64 = ( V_66 & V_21 ) ? 1 : 0 ;
return V_69 ;
case V_71 :
F_6 ( V_3 -> V_16 , V_72 , & V_66 ) ;
V_66 &= V_73 ;
* V_64 = 1 ;
* V_65 = 0 ;
if ( V_66 == 3 )
* V_65 = 2 ;
return V_74 ;
}
return - V_15 ;
}
static int F_28 ( struct V_60 * V_61 ,
struct V_62 const * V_63 ,
int V_64 , int V_65 , long V_44 )
{
struct V_2 * V_3 = F_27 ( V_61 ) ;
T_1 V_66 ;
switch ( V_44 ) {
case V_67 :
return F_8 ( V_3 -> V_16 , V_68 , V_64 ) ;
case V_71 :
return - V_15 ;
case V_70 :
if ( V_64 ) {
F_6 ( V_3 -> V_16 , V_20 , & V_66 ) ;
if ( ! ( V_66 & V_21 ) )
F_7 ( V_3 -> V_11 ) ;
F_9 ( V_3 -> V_16 , V_20 , V_21 ,
V_21 ) ;
} else {
F_6 ( V_3 -> V_16 , V_20 , & V_66 ) ;
F_9 ( V_3 -> V_16 , V_20 , V_21 ,
0 ) ;
if ( V_66 & V_21 )
F_11 ( V_3 -> V_11 ) ;
}
return 0 ;
}
return - V_15 ;
}
static int F_29 ( struct V_60 * V_61 ,
struct V_4 * V_5 )
{
struct V_2 * V_3 = F_27 ( V_61 ) ;
const char * const * V_50 = V_3 -> V_75 ;
unsigned int V_47 = 0 ;
if ( ! F_30 ( V_5 ) )
return - V_15 ;
while ( V_50 && * V_50 ) {
if ( ! strncmp ( V_5 -> V_1 , * V_50 , strlen ( V_5 -> V_1 ) ) ) {
F_9 ( V_3 -> V_16 ,
V_72 , V_76 ,
V_47 << V_77 ) ;
return 0 ;
}
V_50 ++ ;
V_47 ++ ;
}
return - V_15 ;
}
static int F_31 ( struct V_60 * V_61 ,
const struct V_62 * V_63 ,
unsigned int V_78 )
{
struct V_2 * V_3 = F_27 ( V_61 ) ;
F_9 ( V_3 -> V_16 , V_72 , V_73 , V_73 ) ;
return 0 ;
}
static int F_32 ( struct V_60 * V_61 ,
const struct V_62 * V_63 )
{
struct V_2 * V_3 = F_27 ( V_61 ) ;
T_1 V_79 ;
F_6 ( V_3 -> V_16 , V_72 , & V_79 ) ;
return ( V_79 & V_73 ) == V_73 ? 0 : - V_15 ;
}
static int F_33 ( int V_78 )
{
switch ( V_78 ) {
case 0 :
return 0 ;
case 1 :
return 5 ;
case 2 :
return 6 ;
}
return - V_15 ;
}
static int F_34 ( struct V_60 * V_61 ,
const struct V_62 * V_63 ,
unsigned int V_78 )
{
struct V_2 * V_3 = F_27 ( V_61 ) ;
int V_80 = F_33 ( V_78 ) ;
T_1 V_64 ;
if ( V_80 < 0 )
return V_80 ;
if ( V_80 == 6 ) {
F_6 ( V_3 -> V_16 , V_20 , & V_64 ) ;
if ( ! ( V_64 & V_21 ) )
F_7 ( V_3 -> V_11 ) ;
}
F_9 ( V_3 -> V_16 , V_72 , V_73 , V_80 ) ;
return 0 ;
}
static int F_35 ( int V_78 )
{
switch ( V_78 ) {
case 0 :
return 0 ;
case 5 :
return 1 ;
case 6 :
return 2 ;
}
return - V_15 ;
}
static int F_36 ( struct V_60 * V_61 ,
const struct V_62 * V_63 )
{
struct V_2 * V_3 = F_27 ( V_61 ) ;
T_1 V_79 ;
F_6 ( V_3 -> V_16 , V_72 , & V_79 ) ;
V_79 &= V_73 ;
return F_35 ( V_79 ) ;
}
static int F_37 ( struct V_60 * V_61 ,
const struct V_62 * V_63 ,
unsigned int V_78 )
{
struct V_2 * V_3 = F_27 ( V_61 ) ;
F_9 ( V_3 -> V_16 , V_72 , V_73 , V_78 + 1 ) ;
return 0 ;
}
static int F_38 ( struct V_60 * V_61 ,
const struct V_62 * V_63 )
{
struct V_2 * V_3 = F_27 ( V_61 ) ;
T_1 V_79 ;
int V_78 ;
F_6 ( V_3 -> V_16 , V_72 , & V_79 ) ;
V_78 = ( V_79 & V_73 ) - 1 ;
if ( ( V_78 < 0 ) || ( V_78 > F_39 ( V_81 ) ) )
return - V_15 ;
return V_78 ;
}
static int F_40 ( struct V_60 * V_61 ,
const struct V_62 * V_63 ,
unsigned int V_82 )
{
struct V_2 * V_3 = F_27 ( V_61 ) ;
T_1 V_64 ;
int V_78 ;
F_6 ( V_3 -> V_16 , V_72 , & V_64 ) ;
V_78 = ( V_64 & V_73 ) - 1 ;
if ( ( V_78 >= 0 ) || ( V_78 < F_39 ( V_81 ) ) )
return - V_19 ;
return F_9 ( V_3 -> V_16 , V_20 , V_83 ,
V_82 ? V_83 : 0 ) ;
}
static int F_41 ( struct V_60 * V_61 ,
const struct V_62 * V_63 )
{
struct V_2 * V_3 = F_27 ( V_61 ) ;
T_1 V_10 ;
F_6 ( V_3 -> V_16 , V_20 , & V_10 ) ;
return ( ( V_10 & V_83 ) ? 1 : 0 ) ;
}
static T_2 F_42 ( struct V_60 * V_61 ,
T_4 V_84 ,
const struct V_62 * V_63 ,
char * V_35 )
{
struct V_2 * V_3 = F_27 ( V_61 ) ;
T_1 V_40 ;
F_6 ( V_3 -> V_16 , V_23 , & V_40 ) ;
return snprintf ( V_35 , V_42 , L_7 , V_40 ) ;
}
static T_2 F_43 ( struct V_60 * V_61 ,
T_4 V_84 ,
const struct V_62 * V_63 ,
const char * V_35 , T_3 V_36 )
{
struct V_2 * V_3 = F_27 ( V_61 ) ;
unsigned int V_85 ;
int V_38 ;
V_38 = F_15 ( V_35 , 0 , & V_85 ) ;
if ( V_38 )
return V_38 ;
F_8 ( V_3 -> V_16 , V_23 , V_85 ) ;
F_9 ( V_3 -> V_16 , V_20 , V_24 , V_24 ) ;
return V_36 ;
}
static struct V_2 * F_44 ( struct V_32 * V_14 )
{
struct V_60 * V_61 ;
int V_38 ;
V_61 = F_45 ( V_14 ,
sizeof( struct V_2 ) ) ;
if ( ! V_61 )
return NULL ;
V_61 -> V_1 = F_46 ( V_14 ) ;
V_61 -> V_14 . V_55 = V_14 ;
V_61 -> V_86 = & V_87 ;
V_61 -> V_88 = V_89 ;
V_61 -> V_90 = 1 ;
V_61 -> V_91 = & V_92 ;
V_61 -> V_14 . V_93 = V_14 -> V_93 ;
V_38 = F_47 ( V_14 , V_61 ) ;
if ( V_38 )
return NULL ;
return F_27 ( V_61 ) ;
}
bool F_30 ( struct V_4 * V_5 )
{
return ( V_5 -> V_56 == & V_57 ) ;
}
static void F_48 ( struct V_2 * V_3 )
{
T_1 V_64 ;
F_9 ( V_3 -> V_16 , V_25 , V_26 , V_26 ) ;
F_6 ( V_3 -> V_16 , V_25 , & V_64 ) ;
F_9 ( V_3 -> V_16 , V_25 , V_26 , 0 ) ;
V_3 -> V_53 = ! ! V_64 ;
}
static int F_49 ( struct V_94 * V_95 )
{
struct V_32 * V_14 = & V_95 -> V_14 ;
struct V_2 * V_3 ;
struct V_96 * V_97 = F_18 ( V_95 -> V_14 . V_55 ) ;
unsigned int V_98 ;
int V_38 ;
if ( F_50 ( V_14 -> V_93 , L_8 , & V_98 ) )
return - V_15 ;
if ( V_98 >= F_39 ( V_99 ) ||
V_98 >= F_39 ( V_100 ) )
return - V_15 ;
if ( * V_100 [ V_98 ] )
V_3 = F_44 ( V_14 ) ;
else
V_3 = F_51 ( V_14 , sizeof( * V_3 ) , V_101 ) ;
if ( ! V_3 )
return - V_54 ;
V_3 -> V_14 = V_14 ;
V_3 -> V_16 = V_97 -> V_16 ;
V_3 -> V_11 = V_97 -> V_11 ;
V_3 -> V_12 = V_97 -> V_12 ;
V_3 -> V_51 = V_99 [ V_98 ] ;
V_3 -> V_75 = V_100 [ V_98 ] ;
F_48 ( V_3 ) ;
V_38 = F_22 ( V_3 ) ;
if ( V_38 )
return V_38 ;
F_52 ( V_95 , V_3 ) ;
return 0 ;
}
