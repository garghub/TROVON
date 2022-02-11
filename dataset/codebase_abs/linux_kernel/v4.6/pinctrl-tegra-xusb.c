static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned long V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 ,
unsigned long V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return V_2 -> V_8 -> V_9 ;
}
static const char * F_7 ( struct V_6 * V_7 ,
unsigned int V_10 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return V_2 -> V_8 -> V_11 [ V_10 ] . V_12 ;
}
static int F_8 ( struct V_6 * V_7 ,
unsigned V_10 ,
const unsigned * * V_11 ,
unsigned * V_9 )
{
* V_11 = & V_7 -> V_13 -> V_11 [ V_10 ] . V_14 ;
* V_9 = 1 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_17 * * V_18 ,
unsigned int * V_19 ,
unsigned int * V_20 )
{
unsigned int V_21 , V_22 = 0 , V_23 = 0 ;
unsigned long V_24 , * V_25 = NULL ;
const char * V_26 , * V_10 ;
struct V_27 * V_28 ;
int V_29 = 0 ;
T_1 V_3 ;
V_29 = F_10 ( V_16 , L_1 , & V_26 ) ;
if ( V_29 < 0 ) {
if ( V_29 != - V_30 )
return V_29 ;
V_26 = NULL ;
}
for ( V_21 = 0 ; V_21 < F_11 ( V_31 ) ; V_21 ++ ) {
V_29 = F_12 ( V_16 , V_31 [ V_21 ] . V_12 , & V_3 ) ;
if ( V_29 < 0 ) {
if ( V_29 == - V_30 )
continue;
goto V_32;
}
V_24 = F_13 ( V_31 [ V_21 ] . V_33 , V_3 ) ;
V_29 = F_14 ( V_2 -> V_7 , & V_25 ,
& V_23 , V_24 ) ;
if ( V_29 < 0 )
goto V_32;
}
if ( V_26 )
V_22 ++ ;
if ( V_23 )
V_22 ++ ;
V_29 = F_15 ( V_16 , L_2 ) ;
if ( V_29 < 0 )
goto V_32;
V_22 *= V_29 ;
V_29 = F_16 ( V_2 -> V_7 , V_18 , V_19 ,
V_20 , V_22 ) ;
if ( V_29 < 0 )
goto V_32;
F_17 (np, L_2 , prop, group) {
if ( V_26 ) {
V_29 = F_18 ( V_2 -> V_7 , V_18 ,
V_19 , V_20 , V_10 ,
V_26 ) ;
if ( V_29 < 0 )
goto V_32;
}
if ( V_23 ) {
V_29 = F_19 ( V_2 -> V_7 ,
V_18 , V_19 , V_20 , V_10 ,
V_25 , V_23 ,
V_34 ) ;
if ( V_29 < 0 )
goto V_32;
}
}
V_29 = 0 ;
V_32:
F_20 ( V_25 ) ;
return V_29 ;
}
static int F_21 ( struct V_6 * V_7 ,
struct V_15 * V_35 ,
struct V_17 * * V_18 ,
unsigned int * V_20 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned int V_19 = 0 ;
struct V_15 * V_16 ;
int V_29 ;
* V_20 = 0 ;
* V_18 = NULL ;
F_22 (parent, np) {
V_29 = F_9 ( V_2 , V_16 , V_18 ,
& V_19 ,
V_20 ) ;
if ( V_29 < 0 ) {
F_23 ( V_16 ) ;
return V_29 ;
}
}
return 0 ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return V_2 -> V_8 -> V_36 ;
}
static const char *
F_25 ( struct V_6 * V_7 ,
unsigned int V_26 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return V_2 -> V_8 -> V_37 [ V_26 ] . V_12 ;
}
static int F_26 ( struct V_6 * V_7 ,
unsigned int V_26 ,
const char * const * * V_38 ,
unsigned * const V_39 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
* V_39 = V_2 -> V_8 -> V_37 [ V_26 ] . V_39 ;
* V_38 = V_2 -> V_8 -> V_37 [ V_26 ] . V_38 ;
return 0 ;
}
static int F_27 ( struct V_6 * V_7 ,
unsigned int V_26 ,
unsigned int V_10 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
const struct V_40 * V_41 ;
unsigned int V_21 ;
T_1 V_3 ;
V_41 = & V_2 -> V_8 -> V_42 [ V_10 ] ;
for ( V_21 = 0 ; V_21 < V_41 -> V_43 ; V_21 ++ )
if ( V_41 -> V_44 [ V_21 ] == V_26 )
break;
if ( V_21 >= V_41 -> V_43 )
return - V_30 ;
V_3 = F_3 ( V_2 , V_41 -> V_4 ) ;
V_3 &= ~ ( V_41 -> V_45 << V_41 -> V_46 ) ;
V_3 |= V_21 << V_41 -> V_46 ;
F_1 ( V_2 , V_3 , V_41 -> V_4 ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 ,
unsigned int V_10 ,
unsigned long * V_24 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
const struct V_40 * V_41 ;
enum V_47 V_33 ;
T_1 V_3 ;
V_33 = F_29 ( * V_24 ) ;
V_41 = & V_2 -> V_8 -> V_42 [ V_10 ] ;
switch ( V_33 ) {
case V_48 :
if ( V_41 -> V_49 == 0 )
return - V_30 ;
V_3 = F_3 ( V_2 , V_41 -> V_4 ) ;
if ( V_3 & F_30 ( V_41 -> V_49 ) )
V_3 = 0 ;
else
V_3 = 1 ;
* V_24 = F_13 ( V_33 , V_3 ) ;
break;
default:
F_31 ( V_2 -> V_50 , L_3 ,
V_33 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_32 ( struct V_6 * V_7 ,
unsigned int V_10 ,
unsigned long * V_25 ,
unsigned int V_23 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
const struct V_40 * V_41 ;
enum V_47 V_33 ;
unsigned long V_3 ;
unsigned int V_21 ;
T_1 V_52 ;
V_41 = & V_2 -> V_8 -> V_42 [ V_10 ] ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
V_33 = F_29 ( V_25 [ V_21 ] ) ;
V_3 = F_33 ( V_25 [ V_21 ] ) ;
switch ( V_33 ) {
case V_48 :
if ( V_41 -> V_49 == 0 )
return - V_30 ;
V_52 = F_3 ( V_2 , V_41 -> V_4 ) ;
if ( V_3 )
V_52 &= ~ F_30 ( V_41 -> V_49 ) ;
else
V_52 |= F_30 ( V_41 -> V_49 ) ;
F_1 ( V_2 , V_52 , V_41 -> V_4 ) ;
break;
default:
F_31 ( V_2 -> V_50 ,
L_3 ,
V_33 ) ;
return - V_51 ;
}
}
return 0 ;
}
static const char * F_34 ( const char * V_53 )
{
const char * V_54 = strchr ( V_53 , ',' ) ;
if ( ! V_54 )
return V_53 ;
return V_54 + 1 ;
}
static void
F_35 ( struct V_6 * V_7 ,
struct V_55 * V_53 ,
unsigned int V_10 )
{
unsigned int V_21 ;
for ( V_21 = 0 ; V_21 < F_11 ( V_31 ) ; V_21 ++ ) {
unsigned long V_24 , V_3 ;
int V_29 ;
V_24 = F_13 ( V_31 [ V_21 ] . V_33 , 0 ) ;
V_29 = F_28 ( V_7 , V_10 ,
& V_24 ) ;
if ( V_29 < 0 )
continue;
V_3 = F_33 ( V_24 ) ;
F_36 ( V_53 , L_4 , F_34 ( V_31 [ V_21 ] . V_12 ) ,
V_3 ) ;
}
}
static void
F_37 ( struct V_6 * V_7 ,
struct V_55 * V_53 ,
unsigned long V_24 )
{
enum V_47 V_33 ;
const char * V_12 = L_5 ;
unsigned long V_3 ;
unsigned int V_21 ;
V_33 = F_29 ( V_24 ) ;
V_3 = F_33 ( V_24 ) ;
for ( V_21 = 0 ; V_21 < F_11 ( V_31 ) ; V_21 ++ ) {
if ( V_31 [ V_21 ] . V_33 == V_33 ) {
V_12 = V_31 [ V_21 ] . V_12 ;
break;
}
}
F_36 ( V_53 , L_6 , F_34 ( V_12 ) , V_3 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_39 ( & V_2 -> V_56 ) ;
if ( V_2 -> V_57 ++ > 0 )
goto V_32;
V_3 = F_3 ( V_2 , V_58 ) ;
V_3 &= ~ V_59 ;
F_1 ( V_2 , V_3 , V_58 ) ;
F_40 ( 100 , 200 ) ;
V_3 = F_3 ( V_2 , V_58 ) ;
V_3 &= ~ V_60 ;
F_1 ( V_2 , V_3 , V_58 ) ;
F_40 ( 100 , 200 ) ;
V_3 = F_3 ( V_2 , V_58 ) ;
V_3 &= ~ V_61 ;
F_1 ( V_2 , V_3 , V_58 ) ;
V_32:
F_41 ( & V_2 -> V_56 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_39 ( & V_2 -> V_56 ) ;
if ( F_43 ( V_2 -> V_57 == 0 ) )
goto V_32;
if ( -- V_2 -> V_57 > 0 )
goto V_32;
V_3 = F_3 ( V_2 , V_58 ) ;
V_3 |= V_61 ;
F_1 ( V_2 , V_3 , V_58 ) ;
F_40 ( 100 , 200 ) ;
V_3 = F_3 ( V_2 , V_58 ) ;
V_3 |= V_60 ;
F_1 ( V_2 , V_3 , V_58 ) ;
F_40 ( 100 , 200 ) ;
V_3 = F_3 ( V_2 , V_58 ) ;
V_3 |= V_59 ;
F_1 ( V_2 , V_3 , V_58 ) ;
V_32:
F_41 ( & V_2 -> V_56 ) ;
return 0 ;
}
static int F_44 ( struct V_62 * V_62 )
{
struct V_1 * V_2 = F_45 ( V_62 ) ;
return F_38 ( V_2 ) ;
}
static int F_46 ( struct V_62 * V_62 )
{
struct V_1 * V_2 = F_45 ( V_62 ) ;
return F_42 ( V_2 ) ;
}
static int F_47 ( struct V_62 * V_62 )
{
struct V_1 * V_2 = F_45 ( V_62 ) ;
unsigned long V_63 ;
int V_29 = - V_64 ;
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_65 ) ;
V_3 &= ~ V_66 ;
F_1 ( V_2 , V_3 , V_65 ) ;
V_3 = F_3 ( V_2 , V_67 ) ;
V_3 |= V_68 |
V_69 |
V_70 ;
F_1 ( V_2 , V_3 , V_67 ) ;
V_3 = F_3 ( V_2 , V_65 ) ;
V_3 |= V_71 ;
F_1 ( V_2 , V_3 , V_65 ) ;
V_63 = V_72 + F_48 ( 50 ) ;
while ( F_49 ( V_72 , V_63 ) ) {
V_3 = F_3 ( V_2 , V_65 ) ;
if ( V_3 & V_73 ) {
V_29 = 0 ;
break;
}
F_40 ( 100 , 200 ) ;
}
return V_29 ;
}
static int F_50 ( struct V_62 * V_62 )
{
struct V_1 * V_2 = F_45 ( V_62 ) ;
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_65 ) ;
V_3 &= ~ V_71 ;
F_1 ( V_2 , V_3 , V_65 ) ;
return 0 ;
}
static int F_51 ( struct V_62 * V_62 )
{
struct V_1 * V_2 = F_45 ( V_62 ) ;
unsigned long V_63 ;
int V_29 = - V_64 ;
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_74 ) ;
V_3 &= ~ V_75 ;
V_3 &= ~ V_76 ;
F_1 ( V_2 , V_3 , V_74 ) ;
V_3 = F_3 ( V_2 , V_77 ) ;
V_3 &= ~ V_78 ;
V_3 &= ~ V_79 ;
F_1 ( V_2 , V_3 , V_77 ) ;
V_3 = F_3 ( V_2 , V_77 ) ;
V_3 |= V_80 ;
F_1 ( V_2 , V_3 , V_77 ) ;
V_3 = F_3 ( V_2 , V_77 ) ;
V_3 |= V_81 ;
F_1 ( V_2 , V_3 , V_77 ) ;
V_63 = V_72 + F_48 ( 50 ) ;
while ( F_49 ( V_72 , V_63 ) ) {
V_3 = F_3 ( V_2 , V_77 ) ;
if ( V_3 & V_82 ) {
V_29 = 0 ;
break;
}
F_40 ( 100 , 200 ) ;
}
return V_29 ;
}
static int F_52 ( struct V_62 * V_62 )
{
struct V_1 * V_2 = F_45 ( V_62 ) ;
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_77 ) ;
V_3 &= ~ V_81 ;
F_1 ( V_2 , V_3 , V_77 ) ;
V_3 = F_3 ( V_2 , V_77 ) ;
V_3 &= ~ V_80 ;
F_1 ( V_2 , V_3 , V_77 ) ;
V_3 = F_3 ( V_2 , V_77 ) ;
V_3 |= V_78 ;
V_3 |= V_79 ;
F_1 ( V_2 , V_3 , V_77 ) ;
V_3 = F_3 ( V_2 , V_74 ) ;
V_3 |= ~ V_75 ;
V_3 |= ~ V_76 ;
F_1 ( V_2 , V_3 , V_74 ) ;
return 0 ;
}
static struct V_62 * F_53 ( struct V_83 * V_50 ,
struct V_84 * args )
{
struct V_1 * V_2 = F_54 ( V_50 ) ;
unsigned int V_85 = args -> args [ 0 ] ;
if ( args -> V_86 <= 0 )
return F_55 ( - V_30 ) ;
if ( V_85 >= F_11 ( V_2 -> V_87 ) )
return F_55 ( - V_30 ) ;
return V_2 -> V_87 [ V_85 ] ;
}
static int F_56 ( struct V_88 * V_89 )
{
struct V_1 * V_2 ;
const struct V_90 * V_91 ;
struct V_92 * V_93 ;
struct V_62 * V_62 ;
int V_29 ;
V_2 = F_57 ( & V_89 -> V_50 , sizeof( * V_2 ) , V_94 ) ;
if ( ! V_2 )
return - V_95 ;
F_58 ( V_89 , V_2 ) ;
F_59 ( & V_2 -> V_56 ) ;
V_2 -> V_50 = & V_89 -> V_50 ;
V_91 = F_60 ( V_96 , V_89 -> V_50 . V_97 ) ;
V_2 -> V_8 = V_91 -> V_98 ;
V_93 = F_61 ( V_89 , V_99 , 0 ) ;
V_2 -> V_5 = F_62 ( & V_89 -> V_50 , V_93 ) ;
if ( F_63 ( V_2 -> V_5 ) )
return F_64 ( V_2 -> V_5 ) ;
V_2 -> V_100 = F_65 ( & V_89 -> V_50 , NULL ) ;
if ( F_63 ( V_2 -> V_100 ) )
return F_64 ( V_2 -> V_100 ) ;
V_29 = F_66 ( V_2 -> V_100 ) ;
if ( V_29 < 0 )
return V_29 ;
memset ( & V_2 -> V_13 , 0 , sizeof( V_2 -> V_13 ) ) ;
V_2 -> V_13 . V_12 = F_67 ( V_2 -> V_50 ) ;
V_2 -> V_13 . V_11 = V_101 ;
V_2 -> V_13 . V_102 = F_11 ( V_101 ) ;
V_2 -> V_13 . V_103 = & V_104 ;
V_2 -> V_13 . V_105 = & V_106 ;
V_2 -> V_13 . V_107 = & V_108 ;
V_2 -> V_13 . V_109 = V_110 ;
V_2 -> V_7 = F_68 ( & V_2 -> V_13 , & V_89 -> V_50 , V_2 ) ;
if ( F_63 ( V_2 -> V_7 ) ) {
F_31 ( & V_89 -> V_50 , L_7 ) ;
V_29 = F_64 ( V_2 -> V_7 ) ;
goto V_111;
}
V_62 = F_69 ( & V_89 -> V_50 , NULL , & V_112 ) ;
if ( F_63 ( V_62 ) ) {
V_29 = F_64 ( V_62 ) ;
goto V_113;
}
V_2 -> V_87 [ V_114 ] = V_62 ;
F_70 ( V_62 , V_2 ) ;
V_62 = F_69 ( & V_89 -> V_50 , NULL , & V_115 ) ;
if ( F_63 ( V_62 ) ) {
V_29 = F_64 ( V_62 ) ;
goto V_113;
}
V_2 -> V_87 [ V_116 ] = V_62 ;
F_70 ( V_62 , V_2 ) ;
V_2 -> V_117 = F_71 ( & V_89 -> V_50 ,
F_53 ) ;
if ( F_63 ( V_2 -> V_117 ) ) {
V_29 = F_64 ( V_2 -> V_117 ) ;
F_31 ( & V_89 -> V_50 , L_8 , V_29 ) ;
goto V_113;
}
return 0 ;
V_113:
F_72 ( V_2 -> V_7 ) ;
V_111:
F_73 ( V_2 -> V_100 ) ;
return V_29 ;
}
static int F_74 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_75 ( V_89 ) ;
int V_29 ;
F_72 ( V_2 -> V_7 ) ;
V_29 = F_73 ( V_2 -> V_100 ) ;
if ( V_29 < 0 )
F_31 ( & V_89 -> V_50 , L_9 , V_29 ) ;
return V_29 ;
}
