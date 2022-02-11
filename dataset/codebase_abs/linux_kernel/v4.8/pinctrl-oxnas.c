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
struct V_37 * V_38 ,
unsigned int V_39 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_27 = F_15 ( V_38 -> V_40 ) ;
T_1 V_25 = F_10 ( V_39 - V_27 -> V_41 . V_42 ) ;
F_11 ( V_3 -> V_26 , L_3 ,
V_39 , V_27 -> V_41 . V_42 , V_27 -> V_43 , V_25 ) ;
F_12 ( V_3 -> V_29 ,
( V_27 -> V_43 ?
V_30 :
V_31 ) ,
V_25 , 0 ) ;
F_12 ( V_3 -> V_29 ,
( V_27 -> V_43 ?
V_32 :
V_33 ) ,
V_25 , 0 ) ;
F_12 ( V_3 -> V_29 ,
( V_27 -> V_43 ?
V_34 :
V_35 ) ,
V_25 , 0 ) ;
return 0 ;
}
static int F_16 ( struct V_41 * V_44 ,
unsigned int V_39 )
{
struct V_1 * V_27 = F_15 ( V_44 ) ;
T_1 V_25 = F_10 ( V_39 ) ;
return ! ( F_17 ( V_27 -> V_45 + V_46 ) & V_25 ) ;
}
static int F_18 ( struct V_41 * V_44 ,
unsigned int V_39 )
{
struct V_1 * V_27 = F_15 ( V_44 ) ;
T_1 V_25 = F_10 ( V_39 ) ;
F_19 ( V_25 , V_27 -> V_45 + V_47 ) ;
return 0 ;
}
static int F_20 ( struct V_41 * V_44 , unsigned int V_39 )
{
struct V_1 * V_27 = F_15 ( V_44 ) ;
T_1 V_25 = F_10 ( V_39 ) ;
return ( F_17 ( V_27 -> V_45 + V_48 ) & V_25 ) != 0 ;
}
static void F_21 ( struct V_41 * V_44 , unsigned int V_39 ,
int V_49 )
{
struct V_1 * V_27 = F_15 ( V_44 ) ;
T_1 V_25 = F_10 ( V_39 ) ;
if ( V_49 )
F_19 ( V_25 , V_27 -> V_45 + V_50 ) ;
else
F_19 ( V_25 , V_27 -> V_45 + V_51 ) ;
}
static int F_22 ( struct V_41 * V_44 ,
unsigned int V_39 , int V_49 )
{
struct V_1 * V_27 = F_15 ( V_44 ) ;
T_1 V_25 = F_10 ( V_39 ) ;
F_21 ( V_44 , V_39 , V_49 ) ;
F_19 ( V_25 , V_27 -> V_45 + V_52 ) ;
return 0 ;
}
static int F_23 ( struct V_7 * V_8 ,
struct V_37 * V_38 ,
unsigned int V_39 , bool V_53 )
{
struct V_41 * V_44 = V_38 -> V_40 ;
if ( V_53 )
F_18 ( V_44 , V_39 ) ;
else
F_22 ( V_44 , V_39 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_7 * V_8 , unsigned int V_4 ,
unsigned long * V_54 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_27 = F_1 ( V_3 , V_4 ) ;
unsigned int V_55 = F_25 ( * V_54 ) ;
T_1 V_25 = F_10 ( V_4 - V_27 -> V_41 . V_42 ) ;
int V_56 ;
T_1 V_57 ;
switch ( V_55 ) {
case V_58 :
V_56 = F_26 ( V_3 -> V_29 ,
( V_27 -> V_43 ?
V_59 :
V_60 ) ,
& V_57 ) ;
if ( V_56 )
return V_56 ;
V_57 = ! ! ( V_57 & V_25 ) ;
break;
default:
return - V_61 ;
}
* V_54 = F_27 ( V_55 , V_57 ) ;
return 0 ;
}
static int F_28 ( struct V_7 * V_8 , unsigned int V_4 ,
unsigned long * V_62 , unsigned int V_63 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_27 = F_1 ( V_3 , V_4 ) ;
unsigned int V_55 ;
T_1 V_57 ;
unsigned int V_64 ;
T_1 V_39 = V_4 - V_27 -> V_41 . V_42 ;
T_1 V_25 = F_10 ( V_39 ) ;
F_11 ( V_3 -> V_26 , L_4 ,
V_4 , V_27 -> V_41 . V_42 , V_25 ) ;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
V_55 = F_25 ( V_62 [ V_64 ] ) ;
V_57 = F_29 ( V_62 [ V_64 ] ) ;
switch ( V_55 ) {
case V_58 :
F_11 ( V_3 -> V_26 , L_5 ) ;
F_12 ( V_3 -> V_29 ,
( V_27 -> V_43 ?
V_59 :
V_60 ) ,
V_25 , V_25 ) ;
break;
default:
F_13 ( V_3 -> V_26 , L_6 ,
V_55 ) ;
return - V_61 ;
}
}
return 0 ;
}
static void F_30 ( struct V_65 * V_66 )
{
struct V_41 * V_44 = F_31 ( V_66 ) ;
struct V_1 * V_27 = F_15 ( V_44 ) ;
T_1 V_25 = F_10 ( V_66 -> V_67 ) ;
F_32 ( V_25 , V_27 -> V_45 + V_68 ) ;
}
static void F_33 ( struct V_65 * V_66 )
{
struct V_41 * V_44 = F_31 ( V_66 ) ;
struct V_1 * V_27 = F_15 ( V_44 ) ;
unsigned int type = F_34 ( V_66 ) ;
T_1 V_25 = F_10 ( V_66 -> V_67 ) ;
if ( type & V_69 )
F_32 ( F_35 ( V_27 -> V_45 + V_70 ) & ~ V_25 ,
V_27 -> V_45 + V_70 ) ;
if ( type & V_71 )
F_32 ( F_35 ( V_27 -> V_45 + V_72 ) & ~ V_25 ,
V_27 -> V_45 + V_72 ) ;
}
static void F_36 ( struct V_65 * V_66 )
{
struct V_41 * V_44 = F_31 ( V_66 ) ;
struct V_1 * V_27 = F_15 ( V_44 ) ;
unsigned int type = F_34 ( V_66 ) ;
T_1 V_25 = F_10 ( V_66 -> V_67 ) ;
if ( type & V_69 )
F_32 ( F_35 ( V_27 -> V_45 + V_70 ) | V_25 ,
V_27 -> V_45 + V_70 ) ;
if ( type & V_71 )
F_32 ( F_35 ( V_27 -> V_45 + V_72 ) | V_25 ,
V_27 -> V_45 + V_72 ) ;
}
static unsigned int F_37 ( struct V_65 * V_66 )
{
struct V_41 * V_44 = F_31 ( V_66 ) ;
F_18 ( V_44 , V_66 -> V_67 ) ;
F_36 ( V_66 ) ;
return 0 ;
}
static int F_38 ( struct V_65 * V_66 , unsigned int type )
{
if ( ( type & ( V_69 | V_71 ) ) == 0 )
return - V_36 ;
F_39 ( V_66 , V_73 ) ;
return 0 ;
}
static void F_40 ( struct V_74 * V_75 )
{
struct V_41 * V_40 = F_41 ( V_75 ) ;
struct V_1 * V_27 = F_15 ( V_40 ) ;
struct V_76 * V_44 = F_42 ( V_75 ) ;
unsigned long V_77 ;
unsigned int V_4 ;
F_43 ( V_44 , V_75 ) ;
V_77 = F_35 ( V_27 -> V_45 + V_68 ) ;
F_44 (pin, &stat, BITS_PER_LONG)
F_45 ( F_46 ( V_40 -> V_78 , V_4 ) ) ;
F_47 ( V_44 , V_75 ) ;
}
static int F_48 ( struct V_79 * V_80 )
{
struct V_2 * V_3 ;
V_3 = F_49 ( & V_80 -> V_26 , sizeof( * V_3 ) , V_81 ) ;
if ( ! V_3 )
return - V_82 ;
V_3 -> V_26 = & V_80 -> V_26 ;
F_50 ( & V_80 -> V_26 , V_3 ) ;
V_3 -> V_29 = F_51 ( V_80 -> V_26 . V_83 ,
L_7 ) ;
if ( F_52 ( V_3 -> V_29 ) ) {
F_13 ( & V_80 -> V_26 , L_8 ) ;
return - V_84 ;
}
V_3 -> V_13 = V_85 ;
V_3 -> V_86 = F_53 ( V_85 ) ;
V_3 -> V_17 = V_87 ;
V_3 -> V_15 = F_53 ( V_87 ) ;
V_3 -> V_11 = V_88 ;
V_3 -> V_9 = F_53 ( V_88 ) ;
V_3 -> V_5 = V_89 ;
V_3 -> V_90 = F_53 ( V_89 ) ;
V_91 . V_13 = V_3 -> V_13 ;
V_91 . V_86 = V_3 -> V_86 ;
V_3 -> V_8 = F_54 ( & V_91 ,
& V_80 -> V_26 , V_3 ) ;
if ( F_52 ( V_3 -> V_8 ) ) {
F_13 ( & V_80 -> V_26 , L_9 ) ;
return F_55 ( V_3 -> V_8 ) ;
}
return 0 ;
}
static int F_56 ( struct V_79 * V_80 )
{
struct V_92 * V_93 = V_80 -> V_26 . V_83 ;
struct V_94 V_95 ;
struct V_1 * V_27 ;
unsigned int V_43 , V_96 ;
int V_97 , V_56 ;
struct V_98 * V_99 ;
if ( F_57 ( V_93 , L_10 ,
3 , 0 , & V_95 ) ) {
F_13 ( & V_80 -> V_26 , L_11 ) ;
return - V_36 ;
}
V_43 = V_95 . args [ 1 ] / V_6 ;
V_96 = V_95 . args [ 2 ] ;
if ( V_43 >= F_53 ( V_89 ) ) {
F_13 ( & V_80 -> V_26 , L_12 ) ;
return - V_36 ;
}
if ( V_96 > V_6 ) {
F_13 ( & V_80 -> V_26 , L_13 ) ;
return - V_36 ;
}
V_27 = & V_89 [ V_43 ] ;
V_99 = F_58 ( V_80 , V_100 , 0 ) ;
V_27 -> V_45 = F_59 ( & V_80 -> V_26 , V_99 ) ;
if ( F_52 ( V_27 -> V_45 ) )
return F_55 ( V_27 -> V_45 ) ;
V_97 = F_60 ( V_80 , 0 ) ;
if ( V_97 < 0 ) {
F_13 ( & V_80 -> V_26 , L_14 ) ;
return V_97 ;
}
V_27 -> V_43 = V_43 ;
V_27 -> V_41 . V_101 = & V_80 -> V_26 ;
V_27 -> V_41 . V_83 = V_93 ;
V_27 -> V_41 . V_102 = V_96 ;
V_56 = F_61 ( & V_27 -> V_41 , V_27 ) ;
if ( V_56 < 0 ) {
F_13 ( & V_80 -> V_26 , L_15 ,
V_43 , V_56 ) ;
return V_56 ;
}
V_56 = F_62 ( & V_27 -> V_41 , & V_27 -> V_76 ,
0 , V_103 , V_104 ) ;
if ( V_56 < 0 ) {
F_13 ( & V_80 -> V_26 , L_16 ,
V_43 , V_56 ) ;
F_63 ( & V_27 -> V_41 ) ;
return V_56 ;
}
F_64 ( & V_27 -> V_41 , & V_27 -> V_76 ,
V_97 , F_40 ) ;
return 0 ;
}
static int T_2 F_65 ( void )
{
return F_66 ( & V_105 ) ;
}
static int T_2 F_67 ( void )
{
return F_66 ( & V_106 ) ;
}
