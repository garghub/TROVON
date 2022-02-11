static inline struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
return & V_3 -> V_5 [ V_4 / V_6 ] ;
}
static int F_2 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
return V_3 -> V_9 ;
}
static const char * F_4 ( struct V_7 * V_8 ,
unsigned int V_10 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
return V_3 -> V_11 [ V_10 ] . V_12 ;
}
static int F_5 ( struct V_7 * V_8 ,
unsigned int V_10 ,
const unsigned int * * V_13 ,
unsigned int * V_14 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
* V_13 = & V_3 -> V_11 [ V_10 ] . V_4 ;
* V_14 = 1 ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
return V_3 -> V_15 ;
}
static const char *
F_7 ( struct V_7 * V_8 , unsigned int V_16 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
return V_3 -> V_17 [ V_16 ] . V_12 ;
}
static int F_8 ( struct V_7 * V_8 ,
unsigned int V_16 ,
const char * const * * V_11 ,
unsigned int * const V_18 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
* V_11 = V_3 -> V_17 [ V_16 ] . V_11 ;
* V_18 = V_3 -> V_17 [ V_16 ] . V_9 ;
return 0 ;
}
static int F_9 ( struct V_7 * V_8 ,
unsigned int V_16 , unsigned int V_10 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
const struct V_19 * V_20 = & V_3 -> V_11 [ V_10 ] ;
const struct V_21 * V_22 = & V_3 -> V_17 [ V_16 ] ;
const char * V_23 = V_22 -> V_12 ;
struct V_24 * V_17 = V_20 -> V_17 ;
T_1 V_25 = F_10 ( V_20 -> V_4 ) ;
while ( V_17 -> V_12 ) {
if ( ! strcmp ( V_17 -> V_12 , V_23 ) ) {
F_11 ( V_3 -> V_26 ,
L_1 ,
V_23 , V_20 -> V_27 , V_20 -> V_4 ,
V_17 -> V_28 , V_25 ) ;
F_12 ( V_3 -> V_29 ,
( V_20 -> V_27 ?
V_30 :
V_31 ) ,
V_25 ,
( V_17 -> V_28 == 1 ?
V_25 : 0 ) ) ;
F_12 ( V_3 -> V_29 ,
( V_20 -> V_27 ?
V_32 :
V_33 ) ,
V_25 ,
( V_17 -> V_28 == 2 ?
V_25 : 0 ) ) ;
F_12 ( V_3 -> V_29 ,
( V_20 -> V_27 ?
V_34 :
V_35 ) ,
V_25 ,
( V_17 -> V_28 == 3 ?
V_25 : 0 ) ) ;
return 0 ;
}
V_17 ++ ;
}
F_13 ( V_3 -> V_26 , L_2 , V_10 , V_16 ) ;
return - V_36 ;
}
static int F_14 ( struct V_7 * V_8 ,
unsigned int V_16 , unsigned int V_10 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
const struct V_19 * V_20 = & V_3 -> V_11 [ V_10 ] ;
const struct V_21 * V_22 = & V_3 -> V_17 [ V_16 ] ;
const char * V_23 = V_22 -> V_12 ;
struct V_24 * V_17 = V_20 -> V_17 ;
unsigned int V_37 = ( V_20 -> V_27 ? V_38 : 0 ) ;
T_1 V_25 = F_10 ( V_20 -> V_4 ) ;
while ( V_17 -> V_12 ) {
if ( ! strcmp ( V_17 -> V_12 , V_23 ) ) {
F_11 ( V_3 -> V_26 ,
L_1 ,
V_23 , V_20 -> V_27 , V_20 -> V_4 ,
V_17 -> V_28 , V_25 ) ;
F_12 ( V_3 -> V_29 ,
V_37 + V_39 ,
V_25 ,
( V_17 -> V_28 == 1 ?
V_25 : 0 ) ) ;
F_12 ( V_3 -> V_29 ,
V_37 + V_40 ,
V_25 ,
( V_17 -> V_28 == 2 ?
V_25 : 0 ) ) ;
F_12 ( V_3 -> V_29 ,
V_37 + V_41 ,
V_25 ,
( V_17 -> V_28 == 3 ?
V_25 : 0 ) ) ;
F_12 ( V_3 -> V_29 ,
V_37 + V_42 ,
V_25 ,
( V_17 -> V_28 == 4 ?
V_25 : 0 ) ) ;
F_12 ( V_3 -> V_29 ,
V_37 + V_43 ,
V_25 ,
( V_17 -> V_28 == 5 ?
V_25 : 0 ) ) ;
return 0 ;
}
V_17 ++ ;
}
F_13 ( V_3 -> V_26 , L_2 , V_10 , V_16 ) ;
return - V_36 ;
}
static int F_15 ( struct V_7 * V_8 ,
struct V_44 * V_45 ,
unsigned int V_37 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_27 = F_16 ( V_45 -> V_46 ) ;
T_1 V_25 = F_10 ( V_37 - V_27 -> V_47 . V_48 ) ;
F_11 ( V_3 -> V_26 , L_3 ,
V_37 , V_27 -> V_47 . V_48 , V_27 -> V_49 , V_25 ) ;
F_12 ( V_3 -> V_29 ,
( V_27 -> V_49 ?
V_30 :
V_31 ) ,
V_25 , 0 ) ;
F_12 ( V_3 -> V_29 ,
( V_27 -> V_49 ?
V_32 :
V_33 ) ,
V_25 , 0 ) ;
F_12 ( V_3 -> V_29 ,
( V_27 -> V_49 ?
V_34 :
V_35 ) ,
V_25 , 0 ) ;
return 0 ;
}
static int F_17 ( struct V_7 * V_8 ,
struct V_44 * V_45 ,
unsigned int V_37 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_27 = F_16 ( V_45 -> V_46 ) ;
unsigned int V_50 = ( V_27 -> V_49 ? V_38 : 0 ) ;
T_1 V_25 = F_10 ( V_37 - V_27 -> V_47 . V_48 ) ;
F_11 ( V_3 -> V_26 , L_3 ,
V_37 , V_27 -> V_47 . V_48 , V_27 -> V_49 , V_25 ) ;
F_12 ( V_3 -> V_29 ,
V_50 + V_39 ,
V_25 , 0 ) ;
F_12 ( V_3 -> V_29 ,
V_50 + V_40 ,
V_25 , 0 ) ;
F_12 ( V_3 -> V_29 ,
V_50 + V_41 ,
V_25 , 0 ) ;
F_12 ( V_3 -> V_29 ,
V_50 + V_42 ,
V_25 , 0 ) ;
F_12 ( V_3 -> V_29 ,
V_50 + V_43 ,
V_25 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_47 * V_51 ,
unsigned int V_37 )
{
struct V_1 * V_27 = F_16 ( V_51 ) ;
T_1 V_25 = F_10 ( V_37 ) ;
return ! ( F_19 ( V_27 -> V_52 + V_53 ) & V_25 ) ;
}
static int F_20 ( struct V_47 * V_51 ,
unsigned int V_37 )
{
struct V_1 * V_27 = F_16 ( V_51 ) ;
T_1 V_25 = F_10 ( V_37 ) ;
F_21 ( V_25 , V_27 -> V_52 + V_54 ) ;
return 0 ;
}
static int F_22 ( struct V_47 * V_51 , unsigned int V_37 )
{
struct V_1 * V_27 = F_16 ( V_51 ) ;
T_1 V_25 = F_10 ( V_37 ) ;
return ( F_19 ( V_27 -> V_52 + V_55 ) & V_25 ) != 0 ;
}
static void F_23 ( struct V_47 * V_51 , unsigned int V_37 ,
int V_56 )
{
struct V_1 * V_27 = F_16 ( V_51 ) ;
T_1 V_25 = F_10 ( V_37 ) ;
if ( V_56 )
F_21 ( V_25 , V_27 -> V_52 + V_57 ) ;
else
F_21 ( V_25 , V_27 -> V_52 + V_58 ) ;
}
static int F_24 ( struct V_47 * V_51 ,
unsigned int V_37 , int V_56 )
{
struct V_1 * V_27 = F_16 ( V_51 ) ;
T_1 V_25 = F_10 ( V_37 ) ;
F_23 ( V_51 , V_37 , V_56 ) ;
F_21 ( V_25 , V_27 -> V_52 + V_59 ) ;
return 0 ;
}
static int F_25 ( struct V_7 * V_8 ,
struct V_44 * V_45 ,
unsigned int V_37 , bool V_60 )
{
struct V_47 * V_51 = V_45 -> V_46 ;
if ( V_60 )
F_20 ( V_51 , V_37 ) ;
else
F_24 ( V_51 , V_37 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_7 * V_8 ,
unsigned int V_4 , unsigned long * V_61 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_27 = F_1 ( V_3 , V_4 ) ;
unsigned int V_62 = F_27 ( * V_61 ) ;
T_1 V_25 = F_10 ( V_4 - V_27 -> V_47 . V_48 ) ;
int V_63 ;
T_1 V_64 ;
switch ( V_62 ) {
case V_65 :
V_63 = F_28 ( V_3 -> V_29 ,
( V_27 -> V_49 ?
V_66 :
V_67 ) ,
& V_64 ) ;
if ( V_63 )
return V_63 ;
V_64 = ! ! ( V_64 & V_25 ) ;
break;
default:
return - V_68 ;
}
* V_61 = F_29 ( V_62 , V_64 ) ;
return 0 ;
}
static int F_30 ( struct V_7 * V_8 ,
unsigned int V_4 , unsigned long * V_61 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_27 = F_1 ( V_3 , V_4 ) ;
unsigned int V_62 = F_27 ( * V_61 ) ;
unsigned int V_50 = ( V_27 -> V_49 ? V_38 : 0 ) ;
T_1 V_25 = F_10 ( V_4 - V_27 -> V_47 . V_48 ) ;
int V_63 ;
T_1 V_64 ;
switch ( V_62 ) {
case V_65 :
V_63 = F_28 ( V_3 -> V_29 ,
V_50 + V_69 ,
& V_64 ) ;
if ( V_63 )
return V_63 ;
V_64 = ! ! ( V_64 & V_25 ) ;
break;
default:
return - V_68 ;
}
* V_61 = F_29 ( V_62 , V_64 ) ;
return 0 ;
}
static int F_31 ( struct V_7 * V_8 ,
unsigned int V_4 , unsigned long * V_70 ,
unsigned int V_71 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_27 = F_1 ( V_3 , V_4 ) ;
unsigned int V_62 ;
T_1 V_64 ;
unsigned int V_72 ;
T_1 V_37 = V_4 - V_27 -> V_47 . V_48 ;
T_1 V_25 = F_10 ( V_37 ) ;
F_11 ( V_3 -> V_26 , L_4 ,
V_4 , V_27 -> V_47 . V_48 , V_25 ) ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ ) {
V_62 = F_27 ( V_70 [ V_72 ] ) ;
V_64 = F_32 ( V_70 [ V_72 ] ) ;
switch ( V_62 ) {
case V_65 :
F_11 ( V_3 -> V_26 , L_5 ) ;
F_12 ( V_3 -> V_29 ,
( V_27 -> V_49 ?
V_66 :
V_67 ) ,
V_25 , V_25 ) ;
break;
default:
F_13 ( V_3 -> V_26 , L_6 ,
V_62 ) ;
return - V_68 ;
}
}
return 0 ;
}
static int F_33 ( struct V_7 * V_8 ,
unsigned int V_4 , unsigned long * V_70 ,
unsigned int V_71 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_27 = F_1 ( V_3 , V_4 ) ;
unsigned int V_50 = ( V_27 -> V_49 ? V_38 : 0 ) ;
unsigned int V_62 ;
T_1 V_64 ;
unsigned int V_72 ;
T_1 V_37 = V_4 - V_27 -> V_47 . V_48 ;
T_1 V_25 = F_10 ( V_37 ) ;
F_11 ( V_3 -> V_26 , L_4 ,
V_4 , V_27 -> V_47 . V_48 , V_25 ) ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ ) {
V_62 = F_27 ( V_70 [ V_72 ] ) ;
V_64 = F_32 ( V_70 [ V_72 ] ) ;
switch ( V_62 ) {
case V_65 :
F_11 ( V_3 -> V_26 , L_5 ) ;
F_12 ( V_3 -> V_29 ,
V_50 + V_69 ,
V_25 , V_25 ) ;
break;
default:
F_13 ( V_3 -> V_26 , L_6 ,
V_62 ) ;
return - V_68 ;
}
}
return 0 ;
}
static void F_34 ( struct V_73 * V_74 )
{
struct V_47 * V_51 = F_35 ( V_74 ) ;
struct V_1 * V_27 = F_16 ( V_51 ) ;
T_1 V_25 = F_10 ( V_74 -> V_75 ) ;
F_36 ( V_25 , V_27 -> V_52 + V_76 ) ;
}
static void F_37 ( struct V_73 * V_74 )
{
struct V_47 * V_51 = F_35 ( V_74 ) ;
struct V_1 * V_27 = F_16 ( V_51 ) ;
unsigned int type = F_38 ( V_74 ) ;
T_1 V_25 = F_10 ( V_74 -> V_75 ) ;
if ( type & V_77 )
F_36 ( F_39 ( V_27 -> V_52 + V_78 ) & ~ V_25 ,
V_27 -> V_52 + V_78 ) ;
if ( type & V_79 )
F_36 ( F_39 ( V_27 -> V_52 + V_80 ) & ~ V_25 ,
V_27 -> V_52 + V_80 ) ;
}
static void F_40 ( struct V_73 * V_74 )
{
struct V_47 * V_51 = F_35 ( V_74 ) ;
struct V_1 * V_27 = F_16 ( V_51 ) ;
unsigned int type = F_38 ( V_74 ) ;
T_1 V_25 = F_10 ( V_74 -> V_75 ) ;
if ( type & V_77 )
F_36 ( F_39 ( V_27 -> V_52 + V_78 ) | V_25 ,
V_27 -> V_52 + V_78 ) ;
if ( type & V_79 )
F_36 ( F_39 ( V_27 -> V_52 + V_80 ) | V_25 ,
V_27 -> V_52 + V_80 ) ;
}
static unsigned int F_41 ( struct V_73 * V_74 )
{
struct V_47 * V_51 = F_35 ( V_74 ) ;
F_20 ( V_51 , V_74 -> V_75 ) ;
F_40 ( V_74 ) ;
return 0 ;
}
static int F_42 ( struct V_73 * V_74 , unsigned int type )
{
if ( ( type & ( V_77 | V_79 ) ) == 0 )
return - V_36 ;
F_43 ( V_74 , V_81 ) ;
return 0 ;
}
static void F_44 ( struct V_82 * V_83 )
{
struct V_47 * V_46 = F_45 ( V_83 ) ;
struct V_1 * V_27 = F_16 ( V_46 ) ;
struct V_84 * V_51 = F_46 ( V_83 ) ;
unsigned long V_85 ;
unsigned int V_4 ;
F_47 ( V_51 , V_83 ) ;
V_85 = F_39 ( V_27 -> V_52 + V_76 ) ;
F_48 (pin, &stat, BITS_PER_LONG)
F_49 ( F_50 ( V_46 -> V_86 , V_4 ) ) ;
F_51 ( V_51 , V_83 ) ;
}
static int F_52 ( struct V_87 * V_88 )
{
const struct V_89 * V_49 ;
const struct V_90 * V_74 ;
struct V_2 * V_3 ;
V_49 = F_53 ( V_91 , V_88 -> V_26 . V_92 ) ;
if ( ! V_49 )
return - V_93 ;
V_74 = V_49 -> V_74 ;
if ( ! V_74 || ! V_74 -> V_3 || ! V_74 -> V_83 )
return - V_36 ;
V_3 = F_54 ( & V_88 -> V_26 , sizeof( * V_3 ) , V_94 ) ;
if ( ! V_3 )
return - V_95 ;
V_3 -> V_26 = & V_88 -> V_26 ;
F_55 ( & V_88 -> V_26 , V_3 ) ;
V_3 -> V_29 = F_56 ( V_88 -> V_26 . V_92 ,
L_7 ) ;
if ( F_57 ( V_3 -> V_29 ) ) {
F_13 ( & V_88 -> V_26 , L_8 ) ;
return - V_93 ;
}
V_3 -> V_17 = V_74 -> V_3 -> V_17 ;
V_3 -> V_15 = V_74 -> V_3 -> V_15 ;
V_3 -> V_11 = V_74 -> V_3 -> V_11 ;
V_3 -> V_9 = V_74 -> V_3 -> V_9 ;
V_3 -> V_5 = V_74 -> V_3 -> V_5 ;
V_3 -> V_96 = V_74 -> V_3 -> V_96 ;
V_3 -> V_8 = F_58 ( V_74 -> V_83 , & V_88 -> V_26 , V_3 ) ;
if ( F_57 ( V_3 -> V_8 ) ) {
F_13 ( & V_88 -> V_26 , L_9 ) ;
return F_59 ( V_3 -> V_8 ) ;
}
return 0 ;
}
static int F_60 ( struct V_87 * V_88 )
{
struct V_97 * V_98 = V_88 -> V_26 . V_92 ;
struct V_99 V_100 ;
struct V_1 * V_27 ;
unsigned int V_49 , V_101 ;
int V_102 , V_63 ;
struct V_103 * V_104 ;
if ( F_61 ( V_98 , L_10 ,
3 , 0 , & V_100 ) ) {
F_13 ( & V_88 -> V_26 , L_11 ) ;
return - V_36 ;
}
V_49 = V_100 . args [ 1 ] / V_6 ;
V_101 = V_100 . args [ 2 ] ;
if ( V_49 >= F_62 ( V_105 ) ) {
F_13 ( & V_88 -> V_26 , L_12 ) ;
return - V_36 ;
}
if ( V_101 > V_6 ) {
F_13 ( & V_88 -> V_26 , L_13 ) ;
return - V_36 ;
}
V_27 = & V_105 [ V_49 ] ;
V_104 = F_63 ( V_88 , V_106 , 0 ) ;
V_27 -> V_52 = F_64 ( & V_88 -> V_26 , V_104 ) ;
if ( F_57 ( V_27 -> V_52 ) )
return F_59 ( V_27 -> V_52 ) ;
V_102 = F_65 ( V_88 , 0 ) ;
if ( V_102 < 0 ) {
F_13 ( & V_88 -> V_26 , L_14 ) ;
return V_102 ;
}
V_27 -> V_49 = V_49 ;
V_27 -> V_47 . V_107 = & V_88 -> V_26 ;
V_27 -> V_47 . V_92 = V_98 ;
V_27 -> V_47 . V_108 = V_101 ;
V_63 = F_66 ( & V_27 -> V_47 , V_27 ) ;
if ( V_63 < 0 ) {
F_13 ( & V_88 -> V_26 , L_15 ,
V_49 , V_63 ) ;
return V_63 ;
}
V_63 = F_67 ( & V_27 -> V_47 , & V_27 -> V_84 ,
0 , V_109 , V_110 ) ;
if ( V_63 < 0 ) {
F_13 ( & V_88 -> V_26 , L_16 ,
V_49 , V_63 ) ;
F_68 ( & V_27 -> V_47 ) ;
return V_63 ;
}
F_69 ( & V_27 -> V_47 , & V_27 -> V_84 ,
V_102 , F_44 ) ;
return 0 ;
}
static int T_2 F_70 ( void )
{
return F_71 ( & V_111 ) ;
}
static int T_2 F_72 ( void )
{
return F_71 ( & V_112 ) ;
}
