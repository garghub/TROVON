static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned long long V_4 , div ;
int V_5 = 0 ;
T_1 V_6 , V_7 ;
div = ( unsigned long long ) F_2 ( V_2 -> V_8 ) ;
F_3 ( div , V_3 ) ;
V_4 = div ;
while ( div > V_2 -> V_9 ) {
V_5 ++ ;
div = V_4 ;
F_3 ( div , ( V_5 + 1 ) ) ;
}
V_4 = div ;
if ( V_5 > V_10 ) {
F_4 ( V_2 -> V_11 , L_1 ) ;
return - V_12 ;
}
F_5 ( V_2 -> V_13 , V_14 , & V_6 ) ;
if ( V_6 & V_15 )
return - V_16 ;
F_5 ( V_2 -> V_13 , V_17 , & V_7 ) ;
if ( ! ( V_7 & V_18 ) )
F_6 ( V_2 -> V_8 ) ;
F_7 ( V_2 -> V_13 , V_19 , V_5 ) ;
F_7 ( V_2 -> V_13 , V_20 , V_4 - 1 ) ;
F_8 ( V_2 -> V_13 , V_17 , V_21 , V_21 ) ;
F_8 ( V_2 -> V_13 , V_22 , V_23 , 0x20 ) ;
F_8 ( V_2 -> V_13 , V_24 , V_25 , V_25 ) ;
F_8 ( V_2 -> V_13 , V_17 , V_18 , V_18 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_6 , V_7 ;
F_5 ( V_2 -> V_13 , V_14 , & V_6 ) ;
if ( V_6 & V_15 )
return;
F_5 ( V_2 -> V_13 , V_17 , & V_7 ) ;
if ( V_7 & V_18 )
F_10 ( V_2 -> V_8 ) ;
F_8 ( V_2 -> V_13 , V_17 , V_18 , 0 ) ;
F_7 ( V_2 -> V_13 , V_19 , 0 ) ;
F_7 ( V_2 -> V_13 , V_20 , 0 ) ;
F_8 ( V_2 -> V_13 , V_24 , V_25 , V_25 ) ;
}
static T_2 F_11 ( struct V_26 * V_11 ,
struct V_27 * V_28 ,
const char * V_29 , T_3 V_30 )
{
struct V_31 * V_32 = F_12 ( V_11 ) ;
struct V_1 * V_2 = F_13 ( V_32 ) ;
unsigned int V_33 ;
int V_34 ;
V_34 = F_14 ( V_29 , 10 , & V_33 ) ;
if ( V_34 )
return V_34 ;
if ( V_33 == 0 ) {
F_9 ( V_2 ) ;
} else {
V_34 = F_1 ( V_2 , V_33 ) ;
if ( V_34 )
return V_34 ;
}
return V_30 ;
}
static T_2 F_15 ( struct V_26 * V_11 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_31 * V_32 = F_12 ( V_11 ) ;
struct V_1 * V_2 = F_13 ( V_32 ) ;
T_1 V_35 , V_36 , V_7 ;
unsigned long long V_33 = 0 ;
F_5 ( V_2 -> V_13 , V_17 , & V_7 ) ;
F_5 ( V_2 -> V_13 , V_19 , & V_35 ) ;
F_5 ( V_2 -> V_13 , V_20 , & V_36 ) ;
if ( V_7 & V_18 ) {
V_33 = ( unsigned long long ) F_2 ( V_2 -> V_8 ) ;
F_3 ( V_33 , V_35 + 1 ) ;
F_3 ( V_33 , V_36 + 1 ) ;
}
return sprintf ( V_29 , L_2 , ( unsigned int ) V_33 ) ;
}
static T_2 F_16 ( struct V_26 * V_11 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_1 * V_2 = F_17 ( V_11 ) ;
T_1 V_37 ;
F_5 ( V_2 -> V_13 , V_22 , & V_37 ) ;
V_37 = ( V_37 & V_23 ) >> V_38 ;
return snprintf ( V_29 , V_39 , L_3 , V_40 [ V_37 ] ) ;
}
static T_2 F_18 ( struct V_26 * V_11 ,
struct V_27 * V_28 ,
const char * V_29 , T_3 V_30 )
{
struct V_1 * V_2 = F_17 ( V_11 ) ;
int V_41 ;
for ( V_41 = 0 ; V_41 < F_19 ( V_40 ) ; V_41 ++ ) {
if ( ! strncmp ( V_40 [ V_41 ] , V_29 ,
strlen ( V_40 [ V_41 ] ) ) ) {
F_8 ( V_2 -> V_13 , V_22 ,
V_23 , V_41 << V_38 ) ;
F_8 ( V_2 -> V_13 , V_24 ,
V_25 , V_25 ) ;
return V_30 ;
}
}
return - V_12 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_34 ;
const char * const * V_42 = V_2 -> V_43 ;
while ( V_42 && * V_42 ) {
struct V_31 * V_32 ;
V_32 = F_21 ( V_2 -> V_11 , L_4 , * V_42 ) ;
if ( ! V_32 )
return - V_44 ;
V_32 -> V_11 . V_45 = V_2 -> V_11 -> V_45 ;
V_32 -> V_46 = & V_47 ;
if ( V_42 == V_2 -> V_43 )
V_32 -> V_11 . V_48 = V_49 ;
F_22 ( V_32 , V_2 ) ;
V_34 = F_23 ( V_2 -> V_11 , V_32 ) ;
if ( V_34 )
return V_34 ;
V_42 ++ ;
}
return 0 ;
}
static int F_24 ( struct V_50 * V_51 ,
struct V_52 const * V_53 ,
int * V_54 , int * V_55 , long V_56 )
{
struct V_1 * V_2 = F_25 ( V_51 ) ;
switch ( V_56 ) {
case V_57 :
{
T_1 V_58 ;
F_5 ( V_2 -> V_13 , V_59 , & V_58 ) ;
* V_54 = V_58 ;
return V_60 ;
}
case V_61 :
{
T_1 V_62 ;
F_5 ( V_2 -> V_13 , V_63 , & V_62 ) ;
V_62 &= V_64 ;
* V_54 = 1 ;
* V_55 = 0 ;
if ( V_62 == 3 )
* V_55 = 2 ;
return V_65 ;
}
}
return - V_12 ;
}
static int F_26 ( struct V_50 * V_51 ,
struct V_52 const * V_53 ,
int V_54 , int V_55 , long V_56 )
{
struct V_1 * V_2 = F_25 ( V_51 ) ;
switch ( V_56 ) {
case V_57 :
F_7 ( V_2 -> V_13 , V_59 , V_54 ) ;
return V_60 ;
case V_61 :
return - V_12 ;
}
return - V_12 ;
}
static int F_27 ( int V_66 )
{
switch ( V_66 ) {
case 0 :
return 0 ;
case 1 :
return 5 ;
case 2 :
return 6 ;
}
return - V_12 ;
}
static int F_28 ( struct V_50 * V_51 ,
const struct V_52 * V_53 ,
unsigned int V_66 )
{
struct V_1 * V_2 = F_25 ( V_51 ) ;
int V_67 = F_27 ( V_66 ) ;
if ( V_67 < 0 )
return V_67 ;
F_8 ( V_2 -> V_13 , V_63 , V_64 , V_67 ) ;
return 0 ;
}
static int F_29 ( int V_66 )
{
switch ( V_66 ) {
case 0 :
return 0 ;
case 5 :
return 1 ;
case 6 :
return 2 ;
}
return - V_12 ;
}
static int F_30 ( struct V_50 * V_51 ,
const struct V_52 * V_53 )
{
struct V_1 * V_2 = F_25 ( V_51 ) ;
T_1 V_62 ;
F_5 ( V_2 -> V_13 , V_63 , & V_62 ) ;
V_62 &= V_64 ;
return F_29 ( V_62 ) ;
}
static int F_31 ( struct V_50 * V_51 ,
const struct V_52 * V_53 ,
unsigned int V_66 )
{
struct V_1 * V_2 = F_25 ( V_51 ) ;
F_8 ( V_2 -> V_13 , V_63 , V_64 , V_66 + 1 ) ;
return 0 ;
}
static int F_32 ( struct V_50 * V_51 ,
const struct V_52 * V_53 )
{
struct V_1 * V_2 = F_25 ( V_51 ) ;
T_1 V_62 ;
F_5 ( V_2 -> V_13 , V_63 , & V_62 ) ;
V_62 &= V_64 ;
return V_62 - 1 ;
}
static int F_33 ( struct V_50 * V_51 ,
const struct V_52 * V_53 ,
unsigned int V_66 )
{
struct V_1 * V_2 = F_25 ( V_51 ) ;
F_8 ( V_2 -> V_13 , V_17 , V_68 , V_66 ) ;
return 0 ;
}
static int F_34 ( struct V_50 * V_51 ,
const struct V_52 * V_53 )
{
struct V_1 * V_2 = F_25 ( V_51 ) ;
T_1 V_7 ;
F_5 ( V_2 -> V_13 , V_17 , & V_7 ) ;
return ( V_7 & V_68 ) ;
}
static T_2 F_35 ( struct V_50 * V_51 ,
T_4 V_69 ,
const struct V_52 * V_53 ,
char * V_29 )
{
struct V_1 * V_2 = F_25 ( V_51 ) ;
T_1 V_36 ;
F_5 ( V_2 -> V_13 , V_20 , & V_36 ) ;
return snprintf ( V_29 , V_39 , L_5 , V_36 ) ;
}
static T_2 F_36 ( struct V_50 * V_51 ,
T_4 V_69 ,
const struct V_52 * V_53 ,
const char * V_29 , T_3 V_30 )
{
struct V_1 * V_2 = F_25 ( V_51 ) ;
unsigned int V_70 ;
int V_34 ;
V_34 = F_14 ( V_29 , 0 , & V_70 ) ;
if ( V_34 )
return V_34 ;
F_7 ( V_2 -> V_13 , V_20 , V_70 ) ;
F_8 ( V_2 -> V_13 , V_17 , V_21 , V_21 ) ;
return V_30 ;
}
static struct V_1 * F_37 ( struct V_26 * V_11 )
{
struct V_50 * V_51 ;
int V_34 ;
V_51 = F_38 ( V_11 ,
sizeof( struct V_1 ) ) ;
if ( ! V_51 )
return NULL ;
V_51 -> V_71 = F_39 ( V_11 ) ;
V_51 -> V_11 . V_45 = V_11 ;
V_51 -> V_72 = & V_73 ;
V_51 -> V_74 = 1 ;
V_51 -> V_75 = & V_76 ;
V_51 -> V_11 . V_77 = V_11 -> V_77 ;
V_34 = F_40 ( V_11 , V_51 ) ;
if ( V_34 )
return NULL ;
return F_25 ( V_51 ) ;
}
bool F_41 ( struct V_31 * V_32 )
{
return ( V_32 -> V_46 == & V_47 ) ;
}
static int F_42 ( struct V_78 * V_79 )
{
struct V_26 * V_11 = & V_79 -> V_11 ;
struct V_1 * V_2 ;
struct V_80 * V_81 = F_17 ( V_79 -> V_11 . V_45 ) ;
unsigned int V_82 ;
int V_34 ;
if ( F_43 ( V_11 -> V_77 , L_6 , & V_82 ) )
return - V_12 ;
if ( V_82 >= F_19 ( V_83 ) ||
V_82 >= F_19 ( V_84 ) )
return - V_12 ;
if ( * V_84 [ V_82 ] )
V_2 = F_37 ( V_11 ) ;
else
V_2 = F_44 ( V_11 , sizeof( * V_2 ) , V_85 ) ;
if ( ! V_2 )
return - V_44 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_13 = V_81 -> V_13 ;
V_2 -> V_8 = V_81 -> V_8 ;
V_2 -> V_9 = V_81 -> V_9 ;
V_2 -> V_43 = V_83 [ V_82 ] ;
V_2 -> V_86 = V_84 [ V_82 ] ;
V_34 = F_20 ( V_2 ) ;
if ( V_34 )
return V_34 ;
F_45 ( V_79 , V_2 ) ;
return 0 ;
}
