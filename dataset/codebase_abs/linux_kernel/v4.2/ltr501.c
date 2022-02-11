static unsigned int F_1 ( const struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 )
{
int V_6 , V_7 ;
V_7 = V_4 * 1000000 + V_5 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ ) {
if ( V_2 [ V_6 ] . V_8 == V_7 )
return V_6 ;
}
return - V_9 ;
}
static int F_2 ( struct V_10 * V_11 ,
int * V_4 , int * V_5 )
{
int V_12 , V_6 ;
V_12 = F_3 ( V_11 -> V_13 , & V_6 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_6 < 0 || V_6 >= F_4 ( V_14 ) )
return - V_9 ;
* V_4 = V_14 [ V_6 ] . V_8 / 1000000 ;
* V_5 = V_14 [ V_6 ] . V_8 % 1000000 ;
return V_15 ;
}
static int F_5 ( struct V_10 * V_11 ,
int * V_4 , int * V_5 )
{
int V_12 , V_6 ;
V_12 = F_3 ( V_11 -> V_16 , & V_6 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_6 < 0 || V_6 >= F_4 ( V_17 ) )
return - V_9 ;
* V_4 = V_17 [ V_6 ] . V_8 / 1000000 ;
* V_5 = V_17 [ V_6 ] . V_8 % 1000000 ;
return V_15 ;
}
static int F_6 ( struct V_10 * V_11 ,
int V_4 , int V_5 )
{
int V_6 , V_12 ;
V_6 = F_1 ( V_14 ,
F_4 ( V_14 ) ,
V_4 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( & V_11 -> V_18 ) ;
V_12 = F_8 ( V_11 -> V_13 , V_6 ) ;
F_9 ( & V_11 -> V_18 ) ;
return V_12 ;
}
static int F_10 ( struct V_10 * V_11 ,
int V_4 , int V_5 )
{
int V_6 , V_12 ;
V_6 = F_1 ( V_17 ,
F_4 ( V_17 ) ,
V_4 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
F_7 ( & V_11 -> V_19 ) ;
V_12 = F_8 ( V_11 -> V_16 , V_6 ) ;
F_9 ( & V_11 -> V_19 ) ;
return V_12 ;
}
static int F_11 ( struct V_10 * V_11 , int * V_4 )
{
int V_12 , V_6 ;
V_12 = F_3 ( V_11 -> V_13 , & V_6 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_6 < 0 || V_6 >= F_4 ( V_14 ) )
return - V_9 ;
* V_4 = V_14 [ V_6 ] . V_20 ;
return V_21 ;
}
static int F_12 ( struct V_10 * V_11 , int * V_4 )
{
int V_12 , V_6 ;
V_12 = F_3 ( V_11 -> V_16 , & V_6 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_6 < 0 || V_6 >= F_4 ( V_17 ) )
return - V_9 ;
* V_4 = V_17 [ V_6 ] . V_20 ;
return V_21 ;
}
static unsigned long F_13 ( T_1 V_22 , T_1 V_23 )
{
unsigned long V_24 , V_25 ;
if ( V_22 == 0 )
return 0 ;
V_24 = F_14 ( V_23 * 100 , V_23 + V_22 ) ;
if ( V_24 < 45 )
V_25 = F_15 ( 1774 , V_22 , - 1105 , V_23 ) ;
else if ( V_24 >= 45 && V_24 < 64 )
V_25 = F_15 ( 3772 , V_22 , 1336 , V_23 ) ;
else if ( V_24 >= 64 && V_24 < 85 )
V_25 = F_15 ( 1690 , V_22 , 169 , V_23 ) ;
else
V_25 = 0 ;
return V_25 / 1000 ;
}
static int F_16 ( struct V_10 * V_11 , T_2 V_26 )
{
int V_27 = 100 ;
int V_12 , V_28 ;
while ( V_27 -- ) {
V_12 = F_17 ( V_11 -> V_29 , V_30 , & V_28 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ( V_28 & V_26 ) == V_26 )
return 0 ;
F_18 ( 25 ) ;
}
F_19 ( & V_11 -> V_31 -> V_32 , L_1 ) ;
return - V_33 ;
}
static int F_20 ( struct V_10 * V_11 , int V_34 )
{
int V_12 , V_6 , V_35 = - 1 , V_28 ;
for ( V_6 = 0 ; V_6 < F_4 ( V_36 ) ; V_6 ++ ) {
if ( V_36 [ V_6 ] == V_34 ) {
V_35 = V_6 ;
break;
}
}
if ( V_35 < 0 )
return - V_9 ;
V_12 = F_17 ( V_11 -> V_29 , V_37 , & V_28 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_28 & V_38 ) {
if ( V_35 > 1 )
return - V_9 ;
} else
if ( V_35 == 1 )
return - V_9 ;
return F_8 ( V_11 -> V_39 , V_35 ) ;
}
static int F_21 ( struct V_10 * V_11 , int * V_4 , int * V_5 )
{
int V_12 , V_35 ;
V_12 = F_3 ( V_11 -> V_39 , & V_35 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_35 < 0 || V_35 >= F_4 ( V_36 ) )
return - V_9 ;
* V_5 = V_36 [ V_35 ] ;
* V_4 = 0 ;
return V_15 ;
}
static int F_22 ( struct V_10 * V_11 , T_3 V_40 [ 2 ] )
{
int V_12 ;
V_12 = F_16 ( V_11 , V_41 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_23 ( V_11 -> V_29 , V_42 ,
V_40 , 2 * sizeof( T_3 ) ) ;
}
static int F_24 ( struct V_10 * V_11 )
{
int V_12 , V_28 ;
V_12 = F_16 ( V_11 , V_43 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_23 ( V_11 -> V_29 , V_44 ,
& V_28 , 2 ) ;
if ( V_12 < 0 )
return V_12 ;
return V_28 ;
}
static int F_25 ( struct V_10 * V_11 ,
enum V_45 type ,
int * V_5 )
{
int V_12 , V_46 , V_47 ;
switch ( type ) {
case V_48 :
V_12 = F_3 ( V_11 -> V_49 , & V_47 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_11 , & V_46 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_5 = V_46 * V_47 ;
return V_15 ;
case V_50 :
V_12 = F_3 ( V_11 -> V_51 , & V_47 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_12 ( V_11 , & V_46 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_5 = V_46 * V_47 ;
return V_15 ;
default:
return - V_9 ;
}
return - V_9 ;
}
static int F_26 ( struct V_10 * V_11 ,
enum V_45 type ,
int V_4 , int V_5 )
{
int V_12 , V_46 , V_52 ;
unsigned long V_53 ;
if ( V_4 < 0 || V_5 < 0 )
return - V_9 ;
V_53 = ( ( V_4 * 1000000 ) + V_5 ) ;
switch ( type ) {
case V_48 :
V_12 = F_11 ( V_11 , & V_46 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_53 < V_46 )
return - V_9 ;
V_52 = F_14 ( V_53 , V_46 ) ;
if ( V_52 < 0 || V_52 > 0x0f )
return - V_9 ;
F_7 ( & V_11 -> V_18 ) ;
V_12 = F_8 ( V_11 -> V_49 , V_52 ) ;
F_9 ( & V_11 -> V_18 ) ;
if ( V_12 >= 0 )
V_11 -> V_54 = V_53 ;
return V_12 ;
case V_50 :
V_12 = F_12 ( V_11 , & V_46 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_53 < V_46 )
return - V_9 ;
V_52 = F_14 ( V_53 , V_46 ) ;
if ( V_52 < 0 || V_52 > 0x0f )
return - V_9 ;
F_7 ( & V_11 -> V_19 ) ;
V_12 = F_8 ( V_11 -> V_51 , V_52 ) ;
F_9 ( & V_11 -> V_19 ) ;
if ( V_12 >= 0 )
V_11 -> V_55 = V_53 ;
return V_12 ;
default:
return - V_9 ;
}
return - V_9 ;
}
static int F_27 ( struct V_56 * V_57 ,
struct V_58 const * V_59 ,
int * V_4 , int * V_5 , long V_60 )
{
struct V_10 * V_11 = F_28 ( V_57 ) ;
T_3 V_40 [ 2 ] ;
int V_12 , V_6 ;
switch ( V_60 ) {
case V_61 :
if ( F_29 ( V_57 ) )
return - V_62 ;
switch ( V_59 -> type ) {
case V_63 :
F_7 ( & V_11 -> V_18 ) ;
V_12 = F_22 ( V_11 , V_40 ) ;
F_9 ( & V_11 -> V_18 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_4 = F_13 ( F_30 ( V_40 [ 1 ] ) ,
F_30 ( V_40 [ 0 ] ) ) ;
return V_21 ;
default:
return - V_9 ;
}
case V_64 :
if ( F_29 ( V_57 ) )
return - V_62 ;
switch ( V_59 -> type ) {
case V_48 :
F_7 ( & V_11 -> V_18 ) ;
V_12 = F_22 ( V_11 , V_40 ) ;
F_9 ( & V_11 -> V_18 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_4 = F_30 ( V_59 -> V_65 == V_42 ?
V_40 [ 0 ] : V_40 [ 1 ] ) ;
return V_21 ;
case V_50 :
F_7 ( & V_11 -> V_19 ) ;
V_12 = F_24 ( V_11 ) ;
F_9 ( & V_11 -> V_19 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_4 = V_12 & V_66 ;
return V_21 ;
default:
return - V_9 ;
}
case V_67 :
switch ( V_59 -> type ) {
case V_48 :
V_6 = ( V_11 -> V_68 & V_11 -> V_69 -> V_70 )
>> V_11 -> V_69 -> V_71 ;
* V_4 = V_11 -> V_69 -> V_72 [ V_6 ] . V_73 ;
* V_5 = V_11 -> V_69 -> V_72 [ V_6 ] . V_74 ;
return V_15 ;
case V_50 :
V_6 = ( V_11 -> V_75 & V_76 ) >>
V_77 ;
* V_4 = V_11 -> V_69 -> V_78 [ V_6 ] . V_73 ;
* V_5 = V_11 -> V_69 -> V_78 [ V_6 ] . V_74 ;
return V_15 ;
default:
return - V_9 ;
}
case V_79 :
switch ( V_59 -> type ) {
case V_48 :
return F_21 ( V_11 , V_4 , V_5 ) ;
default:
return - V_9 ;
}
case V_80 :
switch ( V_59 -> type ) {
case V_48 :
return F_2 ( V_11 , V_4 , V_5 ) ;
case V_50 :
return F_5 ( V_11 , V_4 , V_5 ) ;
default:
return - V_9 ;
}
}
return - V_9 ;
}
static int F_31 ( struct V_81 * V_82 , int V_83 ,
int V_4 , int V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_83 ; V_6 ++ )
if ( V_4 == V_82 [ V_6 ] . V_73 && V_5 == V_82 [ V_6 ] . V_74 )
return V_6 ;
return - 1 ;
}
static int F_32 ( struct V_56 * V_57 ,
struct V_58 const * V_59 ,
int V_4 , int V_5 , long V_60 )
{
struct V_10 * V_11 = F_28 ( V_57 ) ;
int V_6 , V_12 , V_8 , V_84 ;
struct V_85 * V_86 = V_11 -> V_69 ;
if ( F_29 ( V_57 ) )
return - V_62 ;
switch ( V_60 ) {
case V_67 :
switch ( V_59 -> type ) {
case V_48 :
V_6 = F_31 ( V_86 -> V_72 ,
V_86 -> V_87 ,
V_4 , V_5 ) ;
if ( V_6 < 0 )
return - V_9 ;
V_11 -> V_68 &= ~ V_86 -> V_70 ;
V_11 -> V_68 |= V_6 << V_86 -> V_71 ;
return F_33 ( V_11 -> V_29 , V_37 ,
V_11 -> V_68 ) ;
case V_50 :
V_6 = F_31 ( V_86 -> V_78 ,
V_86 -> V_88 ,
V_4 , V_5 ) ;
if ( V_6 < 0 )
return - V_9 ;
V_11 -> V_75 &= ~ V_76 ;
V_11 -> V_75 |= V_6 << V_77 ;
return F_33 ( V_11 -> V_29 , V_89 ,
V_11 -> V_75 ) ;
default:
return - V_9 ;
}
case V_79 :
switch ( V_59 -> type ) {
case V_48 :
if ( V_4 != 0 )
return - V_9 ;
F_7 ( & V_11 -> V_18 ) ;
V_6 = F_20 ( V_11 , V_5 ) ;
F_9 ( & V_11 -> V_18 ) ;
return V_6 ;
default:
return - V_9 ;
}
case V_80 :
switch ( V_59 -> type ) {
case V_48 :
V_12 = F_2 ( V_11 , & V_8 ,
& V_84 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_6 ( V_11 , V_4 , V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_26 ( V_11 , V_59 -> type ,
0 , V_11 -> V_54 ) ;
if ( V_12 < 0 )
return F_6 ( V_11 ,
V_8 ,
V_84 ) ;
return V_12 ;
case V_50 :
V_12 = F_5 ( V_11 , & V_8 ,
& V_84 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_10 ( V_11 , V_4 , V_5 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_26 ( V_11 , V_59 -> type ,
0 , V_11 -> V_55 ) ;
if ( V_12 < 0 )
return F_10 ( V_11 ,
V_8 ,
V_84 ) ;
return V_12 ;
default:
return - V_9 ;
}
}
return - V_9 ;
}
static int F_34 ( struct V_56 * V_57 ,
const struct V_58 * V_59 ,
enum V_90 type ,
enum V_91 V_92 ,
enum V_93 V_86 ,
int * V_4 , int * V_5 )
{
struct V_10 * V_11 = F_28 ( V_57 ) ;
int V_12 , V_94 ;
switch ( V_59 -> type ) {
case V_48 :
switch ( V_92 ) {
case V_95 :
V_12 = F_23 ( V_11 -> V_29 ,
V_96 ,
& V_94 , 2 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_4 = V_94 & V_97 ;
return V_21 ;
case V_98 :
V_12 = F_23 ( V_11 -> V_29 ,
V_99 ,
& V_94 , 2 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_4 = V_94 & V_97 ;
return V_21 ;
default:
return - V_9 ;
}
case V_50 :
switch ( V_92 ) {
case V_95 :
V_12 = F_23 ( V_11 -> V_29 ,
V_100 ,
& V_94 , 2 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_4 = V_94 & V_101 ;
return V_21 ;
case V_98 :
V_12 = F_23 ( V_11 -> V_29 ,
V_102 ,
& V_94 , 2 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_4 = V_94 & V_101 ;
return V_21 ;
default:
return - V_9 ;
}
default:
return - V_9 ;
}
return - V_9 ;
}
static int F_35 ( struct V_56 * V_57 ,
const struct V_58 * V_59 ,
enum V_90 type ,
enum V_91 V_92 ,
enum V_93 V_86 ,
int V_4 , int V_5 )
{
struct V_10 * V_11 = F_28 ( V_57 ) ;
int V_12 ;
if ( V_4 < 0 )
return - V_9 ;
switch ( V_59 -> type ) {
case V_48 :
if ( V_4 > V_97 )
return - V_9 ;
switch ( V_92 ) {
case V_95 :
F_7 ( & V_11 -> V_18 ) ;
V_12 = F_36 ( V_11 -> V_29 ,
V_96 ,
& V_4 , 2 ) ;
F_9 ( & V_11 -> V_18 ) ;
return V_12 ;
case V_98 :
F_7 ( & V_11 -> V_18 ) ;
V_12 = F_36 ( V_11 -> V_29 ,
V_99 ,
& V_4 , 2 ) ;
F_9 ( & V_11 -> V_18 ) ;
return V_12 ;
default:
return - V_9 ;
}
case V_50 :
if ( V_4 > V_101 )
return - V_9 ;
switch ( V_92 ) {
case V_95 :
F_7 ( & V_11 -> V_19 ) ;
V_12 = F_36 ( V_11 -> V_29 ,
V_100 ,
& V_4 , 2 ) ;
F_9 ( & V_11 -> V_19 ) ;
return V_12 ;
case V_98 :
F_7 ( & V_11 -> V_19 ) ;
V_12 = F_36 ( V_11 -> V_29 ,
V_102 ,
& V_4 , 2 ) ;
F_9 ( & V_11 -> V_19 ) ;
return V_12 ;
default:
return - V_9 ;
}
default:
return - V_9 ;
}
return - V_9 ;
}
static int F_37 ( struct V_56 * V_57 ,
const struct V_58 * V_59 ,
enum V_90 type ,
enum V_91 V_92 ,
enum V_93 V_86 ,
int * V_4 , int * V_5 )
{
int V_12 ;
switch ( V_86 ) {
case V_103 :
return F_34 ( V_57 , V_59 , type , V_92 ,
V_86 , V_4 , V_5 ) ;
case V_104 :
V_12 = F_25 ( F_28 ( V_57 ) ,
V_59 -> type , V_5 ) ;
* V_4 = * V_5 / 1000000 ;
* V_5 = * V_5 % 1000000 ;
return V_12 ;
default:
return - V_9 ;
}
return - V_9 ;
}
static int F_38 ( struct V_56 * V_57 ,
const struct V_58 * V_59 ,
enum V_90 type ,
enum V_91 V_92 ,
enum V_93 V_86 ,
int V_4 , int V_5 )
{
switch ( V_86 ) {
case V_103 :
if ( V_5 != 0 )
return - V_9 ;
return F_35 ( V_57 , V_59 , type , V_92 ,
V_86 , V_4 , V_5 ) ;
case V_104 :
return F_26 ( F_28 ( V_57 ) , V_59 -> type ,
V_4 , V_5 ) ;
default:
return - V_9 ;
}
return - V_9 ;
}
static int F_39 ( struct V_56 * V_57 ,
const struct V_58 * V_59 ,
enum V_90 type ,
enum V_91 V_92 )
{
struct V_10 * V_11 = F_28 ( V_57 ) ;
int V_12 , V_28 ;
switch ( V_59 -> type ) {
case V_48 :
V_12 = F_3 ( V_11 -> V_105 , & V_28 ) ;
if ( V_12 < 0 )
return V_12 ;
return V_28 ;
case V_50 :
V_12 = F_3 ( V_11 -> V_106 , & V_28 ) ;
if ( V_12 < 0 )
return V_12 ;
return V_28 ;
default:
return - V_9 ;
}
return - V_9 ;
}
static int F_40 ( struct V_56 * V_57 ,
const struct V_58 * V_59 ,
enum V_90 type ,
enum V_91 V_92 , int V_107 )
{
struct V_10 * V_11 = F_28 ( V_57 ) ;
int V_12 ;
if ( V_107 != 1 && V_107 != 0 )
return - V_9 ;
switch ( V_59 -> type ) {
case V_48 :
F_7 ( & V_11 -> V_18 ) ;
V_12 = F_8 ( V_11 -> V_105 , V_107 ) ;
F_9 ( & V_11 -> V_18 ) ;
return V_12 ;
case V_50 :
F_7 ( & V_11 -> V_19 ) ;
V_12 = F_8 ( V_11 -> V_106 , V_107 ) ;
F_9 ( & V_11 -> V_19 ) ;
return V_12 ;
default:
return - V_9 ;
}
return - V_9 ;
}
static T_4 F_41 ( struct V_108 * V_32 ,
struct V_109 * V_110 ,
char * V_40 )
{
struct V_10 * V_11 = F_28 ( F_42 ( V_32 ) ) ;
struct V_85 * V_86 = V_11 -> V_69 ;
T_4 V_3 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_86 -> V_88 ; V_6 ++ ) {
if ( V_86 -> V_78 [ V_6 ] . V_73 == V_111 )
continue;
V_3 += F_43 ( V_40 + V_3 , V_112 - V_3 , L_2 ,
V_86 -> V_78 [ V_6 ] . V_73 ,
V_86 -> V_78 [ V_6 ] . V_74 ) ;
}
V_40 [ V_3 - 1 ] = '\n' ;
return V_3 ;
}
static T_4 F_44 ( struct V_108 * V_32 ,
struct V_109 * V_110 ,
char * V_40 )
{
struct V_10 * V_11 = F_28 ( F_42 ( V_32 ) ) ;
struct V_85 * V_86 = V_11 -> V_69 ;
T_4 V_3 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_86 -> V_87 ; V_6 ++ ) {
if ( V_86 -> V_72 [ V_6 ] . V_73 == V_111 )
continue;
V_3 += F_43 ( V_40 + V_3 , V_112 - V_3 , L_2 ,
V_86 -> V_72 [ V_6 ] . V_73 ,
V_86 -> V_72 [ V_6 ] . V_74 ) ;
}
V_40 [ V_3 - 1 ] = '\n' ;
return V_3 ;
}
static int F_45 ( struct V_10 * V_11 , T_2 V_113 , T_2 V_114 )
{
int V_12 ;
V_12 = F_33 ( V_11 -> V_29 , V_37 , V_113 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_33 ( V_11 -> V_29 , V_89 , V_114 ) ;
}
static T_5 F_46 ( int V_115 , void * V_116 )
{
struct V_117 * V_118 = V_116 ;
struct V_56 * V_57 = V_118 -> V_57 ;
struct V_10 * V_11 = F_28 ( V_57 ) ;
T_1 V_40 [ 8 ] ;
T_3 V_119 [ 2 ] ;
T_2 V_60 = 0 ;
int V_120 = 0 ;
int V_12 , V_121 ;
memset ( V_40 , 0 , sizeof( V_40 ) ) ;
if ( F_47 ( 0 , V_57 -> V_122 ) ||
F_47 ( 1 , V_57 -> V_122 ) )
V_60 |= V_41 ;
if ( F_47 ( 2 , V_57 -> V_122 ) )
V_60 |= V_43 ;
V_12 = F_16 ( V_11 , V_60 ) ;
if ( V_12 < 0 )
goto V_123;
if ( V_60 & V_41 ) {
V_12 = F_23 ( V_11 -> V_29 , V_42 ,
( T_2 * ) V_119 , sizeof( V_119 ) ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_47 ( 0 , V_57 -> V_122 ) )
V_40 [ V_120 ++ ] = F_30 ( V_119 [ 1 ] ) ;
if ( F_47 ( 1 , V_57 -> V_122 ) )
V_40 [ V_120 ++ ] = F_30 ( V_119 [ 0 ] ) ;
}
if ( V_60 & V_43 ) {
V_12 = F_23 ( V_11 -> V_29 , V_44 ,
& V_121 , 2 ) ;
if ( V_12 < 0 )
goto V_123;
V_40 [ V_120 ++ ] = V_121 & V_66 ;
}
F_48 ( V_57 , V_40 , F_49 () ) ;
V_123:
F_50 ( V_57 -> V_124 ) ;
return V_125 ;
}
static T_5 F_51 ( int V_115 , void * V_126 )
{
struct V_56 * V_57 = V_126 ;
struct V_10 * V_11 = F_28 ( V_57 ) ;
int V_12 , V_28 ;
V_12 = F_17 ( V_11 -> V_29 , V_30 , & V_28 ) ;
if ( V_12 < 0 ) {
F_19 ( & V_11 -> V_31 -> V_32 ,
L_3 ) ;
return V_125 ;
}
if ( V_28 & V_127 )
F_52 ( V_57 ,
F_53 ( V_48 , 0 ,
V_128 ,
V_129 ) ,
F_49 () ) ;
if ( V_28 & V_130 )
F_52 ( V_57 ,
F_53 ( V_50 , 0 ,
V_128 ,
V_129 ) ,
F_49 () ) ;
return V_125 ;
}
static int F_54 ( struct V_10 * V_11 )
{
int V_12 , V_28 ;
V_12 = F_17 ( V_11 -> V_29 , V_37 , & V_28 ) ;
if ( V_12 < 0 )
return V_12 ;
V_11 -> V_68 = V_28 | V_11 -> V_69 -> V_131 ;
V_12 = F_17 ( V_11 -> V_29 , V_89 , & V_28 ) ;
if ( V_12 < 0 )
return V_12 ;
V_11 -> V_75 = V_28 | V_132 ;
V_12 = F_25 ( V_11 , V_48 , & V_11 -> V_54 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_25 ( V_11 , V_50 , & V_11 -> V_55 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_45 ( V_11 , V_11 -> V_68 , V_11 -> V_75 ) ;
}
static bool F_55 ( struct V_108 * V_32 , unsigned int V_133 )
{
switch ( V_133 ) {
case V_42 :
case V_134 :
case V_30 :
case V_44 :
return true ;
default:
return false ;
}
}
static int F_56 ( struct V_10 * V_11 )
{
return F_45 ( V_11 , V_11 -> V_68 &
~ V_11 -> V_69 -> V_131 ,
V_11 -> V_75 & ~ V_132 ) ;
}
static const char * F_57 ( struct V_108 * V_32 , int * V_135 )
{
const struct V_136 * V_137 ;
V_137 = F_58 ( V_32 -> V_138 -> V_139 , V_32 ) ;
if ( ! V_137 )
return NULL ;
* V_135 = V_137 -> V_140 ;
return F_59 ( V_32 ) ;
}
static int F_60 ( struct V_141 * V_31 ,
const struct V_142 * V_137 )
{
struct V_10 * V_11 ;
struct V_56 * V_57 ;
struct V_29 * V_29 ;
int V_12 , V_143 , V_135 = 0 ;
const char * V_144 = NULL ;
V_57 = F_61 ( & V_31 -> V_32 , sizeof( * V_11 ) ) ;
if ( ! V_57 )
return - V_145 ;
V_29 = F_62 ( V_31 , & V_146 ) ;
if ( F_63 ( V_29 ) ) {
F_19 ( & V_31 -> V_32 , L_4 ) ;
return F_64 ( V_29 ) ;
}
V_11 = F_28 ( V_57 ) ;
F_65 ( V_31 , V_57 ) ;
V_11 -> V_31 = V_31 ;
V_11 -> V_29 = V_29 ;
F_66 ( & V_11 -> V_18 ) ;
F_66 ( & V_11 -> V_19 ) ;
V_11 -> V_39 = F_67 ( & V_31 -> V_32 , V_29 ,
V_147 ) ;
if ( F_63 ( V_11 -> V_39 ) ) {
F_19 ( & V_31 -> V_32 , L_5 ) ;
return F_64 ( V_11 -> V_39 ) ;
}
V_11 -> V_105 = F_67 ( & V_31 -> V_32 , V_29 ,
V_148 ) ;
if ( F_63 ( V_11 -> V_105 ) ) {
F_19 ( & V_31 -> V_32 , L_6 ) ;
return F_64 ( V_11 -> V_105 ) ;
}
V_11 -> V_106 = F_67 ( & V_31 -> V_32 , V_29 ,
V_149 ) ;
if ( F_63 ( V_11 -> V_106 ) ) {
F_19 ( & V_31 -> V_32 , L_7 ) ;
return F_64 ( V_11 -> V_106 ) ;
}
V_11 -> V_13 = F_67 ( & V_31 -> V_32 , V_29 ,
V_150 ) ;
if ( F_63 ( V_11 -> V_13 ) ) {
F_19 ( & V_31 -> V_32 , L_8 ) ;
return F_64 ( V_11 -> V_13 ) ;
}
V_11 -> V_16 = F_67 ( & V_31 -> V_32 , V_29 ,
V_151 ) ;
if ( F_63 ( V_11 -> V_16 ) ) {
F_19 ( & V_31 -> V_32 , L_9 ) ;
return F_64 ( V_11 -> V_16 ) ;
}
V_11 -> V_49 = F_67 ( & V_31 -> V_32 , V_29 ,
V_152 ) ;
if ( F_63 ( V_11 -> V_49 ) ) {
F_19 ( & V_31 -> V_32 , L_10 ) ;
return F_64 ( V_11 -> V_49 ) ;
}
V_11 -> V_51 = F_67 ( & V_31 -> V_32 , V_29 ,
V_153 ) ;
if ( F_63 ( V_11 -> V_51 ) ) {
F_19 ( & V_31 -> V_32 , L_11 ) ;
return F_64 ( V_11 -> V_51 ) ;
}
V_12 = F_17 ( V_11 -> V_29 , V_154 , & V_143 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_137 ) {
V_144 = V_137 -> V_144 ;
V_135 = V_137 -> V_140 ;
} else if ( F_68 ( & V_31 -> V_32 ) ) {
V_144 = F_57 ( & V_31 -> V_32 , & V_135 ) ;
} else {
return - V_155 ;
}
V_11 -> V_69 = & V_156 [ V_135 ] ;
if ( ( V_143 >> 4 ) != V_11 -> V_69 -> V_143 )
return - V_155 ;
V_57 -> V_32 . V_157 = & V_31 -> V_32 ;
V_57 -> V_86 = V_11 -> V_69 -> V_86 ;
V_57 -> V_158 = V_11 -> V_69 -> V_158 ;
V_57 -> V_159 = V_11 -> V_69 -> V_160 ;
V_57 -> V_144 = V_144 ;
V_57 -> V_161 = V_162 ;
V_12 = F_54 ( V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_31 -> V_115 > 0 ) {
V_12 = F_69 ( & V_31 -> V_32 , V_31 -> V_115 ,
NULL , F_51 ,
V_163 |
V_164 ,
L_12 ,
V_57 ) ;
if ( V_12 ) {
F_19 ( & V_31 -> V_32 , L_13 ,
V_31 -> V_115 ) ;
return V_12 ;
}
} else {
V_57 -> V_86 = V_11 -> V_69 -> V_165 ;
}
V_12 = F_70 ( V_57 , NULL ,
F_46 , NULL ) ;
if ( V_12 )
goto V_166;
V_12 = F_71 ( V_57 ) ;
if ( V_12 )
goto V_167;
return 0 ;
V_167:
F_72 ( V_57 ) ;
V_166:
F_56 ( V_11 ) ;
return V_12 ;
}
static int F_73 ( struct V_141 * V_31 )
{
struct V_56 * V_57 = F_74 ( V_31 ) ;
F_75 ( V_57 ) ;
F_72 ( V_57 ) ;
F_56 ( F_28 ( V_57 ) ) ;
return 0 ;
}
static int F_76 ( struct V_108 * V_32 )
{
struct V_10 * V_11 = F_28 ( F_74 (
F_77 ( V_32 ) ) ) ;
return F_56 ( V_11 ) ;
}
static int F_78 ( struct V_108 * V_32 )
{
struct V_10 * V_11 = F_28 ( F_74 (
F_77 ( V_32 ) ) ) ;
return F_45 ( V_11 , V_11 -> V_68 ,
V_11 -> V_75 ) ;
}
