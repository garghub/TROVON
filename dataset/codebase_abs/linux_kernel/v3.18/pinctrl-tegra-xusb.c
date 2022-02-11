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
static int F_8 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * * V_16 ,
unsigned int * V_17 ,
unsigned int * V_18 )
{
unsigned int V_19 , V_20 = 0 , V_21 = 0 ;
unsigned long V_22 , * V_23 = NULL ;
const char * V_24 , * V_10 ;
struct V_25 * V_26 ;
int V_27 = 0 ;
T_1 V_3 ;
V_27 = F_9 ( V_14 , L_1 , & V_24 ) ;
if ( V_27 < 0 ) {
if ( V_27 != - V_28 )
return V_27 ;
V_24 = NULL ;
}
for ( V_19 = 0 ; V_19 < F_10 ( V_29 ) ; V_19 ++ ) {
V_27 = F_11 ( V_14 , V_29 [ V_19 ] . V_12 , & V_3 ) ;
if ( V_27 < 0 ) {
if ( V_27 == - V_28 )
continue;
return V_27 ;
}
V_22 = F_12 ( V_29 [ V_19 ] . V_30 , V_3 ) ;
V_27 = F_13 ( V_2 -> V_7 , & V_23 ,
& V_21 , V_22 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_24 )
V_20 ++ ;
if ( V_21 )
V_20 ++ ;
V_27 = F_14 ( V_14 , L_2 ) ;
if ( V_27 < 0 )
return V_27 ;
V_20 *= V_27 ;
V_27 = F_15 ( V_2 -> V_7 , V_16 , V_17 ,
V_18 , V_20 ) ;
if ( V_27 < 0 )
return V_27 ;
F_16 (np, L_2 , prop, group) {
if ( V_24 ) {
V_27 = F_17 ( V_2 -> V_7 , V_16 ,
V_17 , V_18 , V_10 ,
V_24 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_21 ) {
V_27 = F_18 ( V_2 -> V_7 ,
V_16 , V_17 , V_18 , V_10 ,
V_23 , V_21 ,
V_31 ) ;
if ( V_27 < 0 )
return V_27 ;
}
}
return 0 ;
}
static int F_19 ( struct V_6 * V_7 ,
struct V_13 * V_32 ,
struct V_15 * * V_16 ,
unsigned int * V_18 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned int V_17 = 0 ;
struct V_13 * V_14 ;
int V_27 ;
* V_18 = 0 ;
* V_16 = NULL ;
F_20 (parent, np) {
V_27 = F_8 ( V_2 , V_14 , V_16 ,
& V_17 ,
V_18 ) ;
if ( V_27 < 0 )
return V_27 ;
}
return 0 ;
}
static int F_21 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return V_2 -> V_8 -> V_33 ;
}
static const char *
F_22 ( struct V_6 * V_7 ,
unsigned int V_24 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return V_2 -> V_8 -> V_34 [ V_24 ] . V_12 ;
}
static int F_23 ( struct V_6 * V_7 ,
unsigned int V_24 ,
const char * const * * V_35 ,
unsigned * const V_36 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
* V_36 = V_2 -> V_8 -> V_34 [ V_24 ] . V_36 ;
* V_35 = V_2 -> V_8 -> V_34 [ V_24 ] . V_35 ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 ,
unsigned int V_24 ,
unsigned int V_10 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
const struct V_37 * V_38 ;
unsigned int V_19 ;
T_1 V_3 ;
V_38 = & V_2 -> V_8 -> V_39 [ V_10 ] ;
for ( V_19 = 0 ; V_19 < V_38 -> V_40 ; V_19 ++ )
if ( V_38 -> V_41 [ V_19 ] == V_24 )
break;
if ( V_19 >= V_38 -> V_40 )
return - V_28 ;
V_3 = F_3 ( V_2 , V_38 -> V_4 ) ;
V_3 &= ~ ( V_38 -> V_42 << V_38 -> V_43 ) ;
V_3 |= V_19 << V_38 -> V_43 ;
F_1 ( V_2 , V_3 , V_38 -> V_4 ) ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 ,
unsigned int V_10 ,
unsigned long * V_22 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
const struct V_37 * V_38 ;
enum V_44 V_30 ;
T_1 V_3 ;
V_30 = F_26 ( * V_22 ) ;
V_38 = & V_2 -> V_8 -> V_39 [ V_10 ] ;
switch ( V_30 ) {
case V_45 :
if ( V_38 -> V_46 == 0 )
return - V_28 ;
V_3 = F_3 ( V_2 , V_38 -> V_4 ) ;
if ( V_3 & F_27 ( V_38 -> V_46 ) )
V_3 = 0 ;
else
V_3 = 1 ;
* V_22 = F_12 ( V_30 , V_3 ) ;
break;
default:
F_28 ( V_2 -> V_47 , L_3 ,
V_30 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_29 ( struct V_6 * V_7 ,
unsigned int V_10 ,
unsigned long * V_23 ,
unsigned int V_21 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
const struct V_37 * V_38 ;
enum V_44 V_30 ;
unsigned long V_3 ;
unsigned int V_19 ;
T_1 V_49 ;
V_38 = & V_2 -> V_8 -> V_39 [ V_10 ] ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
V_30 = F_26 ( V_23 [ V_19 ] ) ;
V_3 = F_30 ( V_23 [ V_19 ] ) ;
switch ( V_30 ) {
case V_45 :
if ( V_38 -> V_46 == 0 )
return - V_28 ;
V_49 = F_3 ( V_2 , V_38 -> V_4 ) ;
if ( V_3 )
V_49 &= ~ F_27 ( V_38 -> V_46 ) ;
else
V_49 |= F_27 ( V_38 -> V_46 ) ;
F_1 ( V_2 , V_49 , V_38 -> V_4 ) ;
break;
default:
F_28 ( V_2 -> V_47 ,
L_3 ,
V_30 ) ;
return - V_48 ;
}
}
return 0 ;
}
static const char * F_31 ( const char * V_50 )
{
const char * V_51 = strchr ( V_50 , ',' ) ;
if ( ! V_51 )
return V_50 ;
return V_51 + 1 ;
}
static void
F_32 ( struct V_6 * V_7 ,
struct V_52 * V_50 ,
unsigned int V_10 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < F_10 ( V_29 ) ; V_19 ++ ) {
unsigned long V_22 , V_3 ;
int V_27 ;
V_22 = F_12 ( V_29 [ V_19 ] . V_30 , 0 ) ;
V_27 = F_25 ( V_7 , V_10 ,
& V_22 ) ;
if ( V_27 < 0 )
continue;
V_3 = F_30 ( V_22 ) ;
F_33 ( V_50 , L_4 , F_31 ( V_29 [ V_19 ] . V_12 ) ,
V_3 ) ;
}
}
static void
F_34 ( struct V_6 * V_7 ,
struct V_52 * V_50 ,
unsigned long V_22 )
{
enum V_44 V_30 ;
const char * V_12 = L_5 ;
unsigned long V_3 ;
unsigned int V_19 ;
V_30 = F_26 ( V_22 ) ;
V_3 = F_30 ( V_22 ) ;
for ( V_19 = 0 ; V_19 < F_10 ( V_29 ) ; V_19 ++ ) {
if ( V_29 [ V_19 ] . V_30 == V_30 ) {
V_12 = V_29 [ V_19 ] . V_12 ;
break;
}
}
F_33 ( V_50 , L_6 , F_31 ( V_12 ) , V_3 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_36 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_54 ++ > 0 )
goto V_55;
V_3 = F_3 ( V_2 , V_56 ) ;
V_3 &= ~ V_57 ;
F_1 ( V_2 , V_3 , V_56 ) ;
F_37 ( 100 , 200 ) ;
V_3 = F_3 ( V_2 , V_56 ) ;
V_3 &= ~ V_58 ;
F_1 ( V_2 , V_3 , V_56 ) ;
F_37 ( 100 , 200 ) ;
V_3 = F_3 ( V_2 , V_56 ) ;
V_3 &= ~ V_59 ;
F_1 ( V_2 , V_3 , V_56 ) ;
V_55:
F_38 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_36 ( & V_2 -> V_53 ) ;
if ( F_40 ( V_2 -> V_54 == 0 ) )
goto V_55;
if ( -- V_2 -> V_54 > 0 )
goto V_55;
V_3 = F_3 ( V_2 , V_56 ) ;
V_3 |= V_59 ;
F_1 ( V_2 , V_3 , V_56 ) ;
F_37 ( 100 , 200 ) ;
V_3 = F_3 ( V_2 , V_56 ) ;
V_3 |= V_58 ;
F_1 ( V_2 , V_3 , V_56 ) ;
F_37 ( 100 , 200 ) ;
V_3 = F_3 ( V_2 , V_56 ) ;
V_3 |= V_57 ;
F_1 ( V_2 , V_3 , V_56 ) ;
V_55:
F_38 ( & V_2 -> V_53 ) ;
return 0 ;
}
static int F_41 ( struct V_60 * V_60 )
{
struct V_1 * V_2 = F_42 ( V_60 ) ;
return F_35 ( V_2 ) ;
}
static int F_43 ( struct V_60 * V_60 )
{
struct V_1 * V_2 = F_42 ( V_60 ) ;
return F_39 ( V_2 ) ;
}
static int F_44 ( struct V_60 * V_60 )
{
struct V_1 * V_2 = F_42 ( V_60 ) ;
unsigned long V_61 ;
int V_27 = - V_62 ;
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_63 ) ;
V_3 &= ~ V_64 ;
F_1 ( V_2 , V_3 , V_63 ) ;
V_3 = F_3 ( V_2 , V_65 ) ;
V_3 |= V_66 |
V_67 |
V_68 ;
F_1 ( V_2 , V_3 , V_65 ) ;
V_3 = F_3 ( V_2 , V_63 ) ;
V_3 |= V_69 ;
F_1 ( V_2 , V_3 , V_63 ) ;
V_61 = V_70 + F_45 ( 50 ) ;
while ( F_46 ( V_70 , V_61 ) ) {
V_3 = F_3 ( V_2 , V_63 ) ;
if ( V_3 & V_71 ) {
V_27 = 0 ;
break;
}
F_37 ( 100 , 200 ) ;
}
return V_27 ;
}
static int F_47 ( struct V_60 * V_60 )
{
struct V_1 * V_2 = F_42 ( V_60 ) ;
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_63 ) ;
V_3 &= ~ V_69 ;
F_1 ( V_2 , V_3 , V_63 ) ;
return 0 ;
}
static int F_48 ( struct V_60 * V_60 )
{
struct V_1 * V_2 = F_42 ( V_60 ) ;
unsigned long V_61 ;
int V_27 = - V_62 ;
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_72 ) ;
V_3 &= ~ V_73 ;
V_3 &= ~ V_74 ;
F_1 ( V_2 , V_3 , V_72 ) ;
V_3 = F_3 ( V_2 , V_75 ) ;
V_3 &= ~ V_76 ;
V_3 &= ~ V_77 ;
F_1 ( V_2 , V_3 , V_75 ) ;
V_3 = F_3 ( V_2 , V_75 ) ;
V_3 |= V_78 ;
F_1 ( V_2 , V_3 , V_75 ) ;
V_3 = F_3 ( V_2 , V_75 ) ;
V_3 |= V_79 ;
F_1 ( V_2 , V_3 , V_75 ) ;
V_61 = V_70 + F_45 ( 50 ) ;
while ( F_46 ( V_70 , V_61 ) ) {
V_3 = F_3 ( V_2 , V_75 ) ;
if ( V_3 & V_80 ) {
V_27 = 0 ;
break;
}
F_37 ( 100 , 200 ) ;
}
return V_27 ;
}
static int F_49 ( struct V_60 * V_60 )
{
struct V_1 * V_2 = F_42 ( V_60 ) ;
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_75 ) ;
V_3 &= ~ V_79 ;
F_1 ( V_2 , V_3 , V_75 ) ;
V_3 = F_3 ( V_2 , V_75 ) ;
V_3 &= ~ V_78 ;
F_1 ( V_2 , V_3 , V_75 ) ;
V_3 = F_3 ( V_2 , V_75 ) ;
V_3 |= V_76 ;
V_3 |= V_77 ;
F_1 ( V_2 , V_3 , V_75 ) ;
V_3 = F_3 ( V_2 , V_72 ) ;
V_3 |= ~ V_73 ;
V_3 |= ~ V_74 ;
F_1 ( V_2 , V_3 , V_72 ) ;
return 0 ;
}
static struct V_60 * F_50 ( struct V_81 * V_47 ,
struct V_82 * args )
{
struct V_1 * V_2 = F_51 ( V_47 ) ;
unsigned int V_83 = args -> args [ 0 ] ;
if ( args -> V_84 <= 0 )
return F_52 ( - V_28 ) ;
if ( V_83 >= F_10 ( V_2 -> V_85 ) )
return F_52 ( - V_28 ) ;
return V_2 -> V_85 [ V_83 ] ;
}
static int F_53 ( struct V_86 * V_87 )
{
struct V_1 * V_2 ;
const struct V_88 * V_89 ;
struct V_90 * V_91 ;
struct V_60 * V_60 ;
int V_27 ;
V_2 = F_54 ( & V_87 -> V_47 , sizeof( * V_2 ) , V_92 ) ;
if ( ! V_2 )
return - V_93 ;
F_55 ( V_87 , V_2 ) ;
F_56 ( & V_2 -> V_53 ) ;
V_2 -> V_47 = & V_87 -> V_47 ;
V_89 = F_57 ( V_94 , V_87 -> V_47 . V_95 ) ;
V_2 -> V_8 = V_89 -> V_96 ;
V_91 = F_58 ( V_87 , V_97 , 0 ) ;
V_2 -> V_5 = F_59 ( & V_87 -> V_47 , V_91 ) ;
if ( F_60 ( V_2 -> V_5 ) )
return F_61 ( V_2 -> V_5 ) ;
V_2 -> V_98 = F_62 ( & V_87 -> V_47 , NULL ) ;
if ( F_60 ( V_2 -> V_98 ) )
return F_61 ( V_2 -> V_98 ) ;
V_27 = F_63 ( V_2 -> V_98 ) ;
if ( V_27 < 0 )
return V_27 ;
memset ( & V_2 -> V_99 , 0 , sizeof( V_2 -> V_99 ) ) ;
V_2 -> V_99 . V_12 = F_64 ( V_2 -> V_47 ) ;
V_2 -> V_99 . V_100 = & V_101 ;
V_2 -> V_99 . V_102 = & V_103 ;
V_2 -> V_99 . V_104 = & V_105 ;
V_2 -> V_99 . V_106 = V_107 ;
V_2 -> V_7 = F_65 ( & V_2 -> V_99 , & V_87 -> V_47 , V_2 ) ;
if ( ! V_2 -> V_7 ) {
F_28 ( & V_87 -> V_47 , L_7 ) ;
V_27 = - V_108 ;
goto V_109;
}
V_60 = F_66 ( & V_87 -> V_47 , NULL , & V_110 , NULL ) ;
if ( F_60 ( V_60 ) ) {
V_27 = F_61 ( V_60 ) ;
goto V_111;
}
V_2 -> V_85 [ V_112 ] = V_60 ;
F_67 ( V_60 , V_2 ) ;
V_60 = F_66 ( & V_87 -> V_47 , NULL , & V_113 , NULL ) ;
if ( F_60 ( V_60 ) ) {
V_27 = F_61 ( V_60 ) ;
goto V_111;
}
V_2 -> V_85 [ V_114 ] = V_60 ;
F_67 ( V_60 , V_2 ) ;
V_2 -> V_115 = F_68 ( & V_87 -> V_47 ,
F_50 ) ;
if ( F_60 ( V_2 -> V_115 ) ) {
V_27 = F_61 ( V_2 -> V_115 ) ;
F_28 ( & V_87 -> V_47 , L_8 , V_27 ) ;
goto V_111;
}
return 0 ;
V_111:
F_69 ( V_2 -> V_7 ) ;
V_109:
F_70 ( V_2 -> V_98 ) ;
return V_27 ;
}
static int F_71 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_72 ( V_87 ) ;
int V_27 ;
F_69 ( V_2 -> V_7 ) ;
V_27 = F_70 ( V_2 -> V_98 ) ;
if ( V_27 < 0 )
F_28 ( & V_87 -> V_47 , L_9 , V_27 ) ;
return V_27 ;
}
