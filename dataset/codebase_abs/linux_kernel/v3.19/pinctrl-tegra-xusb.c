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
goto V_30;
}
V_22 = F_12 ( V_29 [ V_19 ] . V_31 , V_3 ) ;
V_27 = F_13 ( V_2 -> V_7 , & V_23 ,
& V_21 , V_22 ) ;
if ( V_27 < 0 )
goto V_30;
}
if ( V_24 )
V_20 ++ ;
if ( V_21 )
V_20 ++ ;
V_27 = F_14 ( V_14 , L_2 ) ;
if ( V_27 < 0 )
goto V_30;
V_20 *= V_27 ;
V_27 = F_15 ( V_2 -> V_7 , V_16 , V_17 ,
V_18 , V_20 ) ;
if ( V_27 < 0 )
goto V_30;
F_16 (np, L_2 , prop, group) {
if ( V_24 ) {
V_27 = F_17 ( V_2 -> V_7 , V_16 ,
V_17 , V_18 , V_10 ,
V_24 ) ;
if ( V_27 < 0 )
goto V_30;
}
if ( V_21 ) {
V_27 = F_18 ( V_2 -> V_7 ,
V_16 , V_17 , V_18 , V_10 ,
V_23 , V_21 ,
V_32 ) ;
if ( V_27 < 0 )
goto V_30;
}
}
V_27 = 0 ;
V_30:
F_19 ( V_23 ) ;
return V_27 ;
}
static int F_20 ( struct V_6 * V_7 ,
struct V_13 * V_33 ,
struct V_15 * * V_16 ,
unsigned int * V_18 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned int V_17 = 0 ;
struct V_13 * V_14 ;
int V_27 ;
* V_18 = 0 ;
* V_16 = NULL ;
F_21 (parent, np) {
V_27 = F_8 ( V_2 , V_14 , V_16 ,
& V_17 ,
V_18 ) ;
if ( V_27 < 0 )
return V_27 ;
}
return 0 ;
}
static int F_22 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return V_2 -> V_8 -> V_34 ;
}
static const char *
F_23 ( struct V_6 * V_7 ,
unsigned int V_24 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return V_2 -> V_8 -> V_35 [ V_24 ] . V_12 ;
}
static int F_24 ( struct V_6 * V_7 ,
unsigned int V_24 ,
const char * const * * V_36 ,
unsigned * const V_37 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
* V_37 = V_2 -> V_8 -> V_35 [ V_24 ] . V_37 ;
* V_36 = V_2 -> V_8 -> V_35 [ V_24 ] . V_36 ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 ,
unsigned int V_24 ,
unsigned int V_10 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
const struct V_38 * V_39 ;
unsigned int V_19 ;
T_1 V_3 ;
V_39 = & V_2 -> V_8 -> V_40 [ V_10 ] ;
for ( V_19 = 0 ; V_19 < V_39 -> V_41 ; V_19 ++ )
if ( V_39 -> V_42 [ V_19 ] == V_24 )
break;
if ( V_19 >= V_39 -> V_41 )
return - V_28 ;
V_3 = F_3 ( V_2 , V_39 -> V_4 ) ;
V_3 &= ~ ( V_39 -> V_43 << V_39 -> V_44 ) ;
V_3 |= V_19 << V_39 -> V_44 ;
F_1 ( V_2 , V_3 , V_39 -> V_4 ) ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 ,
unsigned int V_10 ,
unsigned long * V_22 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
const struct V_38 * V_39 ;
enum V_45 V_31 ;
T_1 V_3 ;
V_31 = F_27 ( * V_22 ) ;
V_39 = & V_2 -> V_8 -> V_40 [ V_10 ] ;
switch ( V_31 ) {
case V_46 :
if ( V_39 -> V_47 == 0 )
return - V_28 ;
V_3 = F_3 ( V_2 , V_39 -> V_4 ) ;
if ( V_3 & F_28 ( V_39 -> V_47 ) )
V_3 = 0 ;
else
V_3 = 1 ;
* V_22 = F_12 ( V_31 , V_3 ) ;
break;
default:
F_29 ( V_2 -> V_48 , L_3 ,
V_31 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_30 ( struct V_6 * V_7 ,
unsigned int V_10 ,
unsigned long * V_23 ,
unsigned int V_21 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
const struct V_38 * V_39 ;
enum V_45 V_31 ;
unsigned long V_3 ;
unsigned int V_19 ;
T_1 V_50 ;
V_39 = & V_2 -> V_8 -> V_40 [ V_10 ] ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
V_31 = F_27 ( V_23 [ V_19 ] ) ;
V_3 = F_31 ( V_23 [ V_19 ] ) ;
switch ( V_31 ) {
case V_46 :
if ( V_39 -> V_47 == 0 )
return - V_28 ;
V_50 = F_3 ( V_2 , V_39 -> V_4 ) ;
if ( V_3 )
V_50 &= ~ F_28 ( V_39 -> V_47 ) ;
else
V_50 |= F_28 ( V_39 -> V_47 ) ;
F_1 ( V_2 , V_50 , V_39 -> V_4 ) ;
break;
default:
F_29 ( V_2 -> V_48 ,
L_3 ,
V_31 ) ;
return - V_49 ;
}
}
return 0 ;
}
static const char * F_32 ( const char * V_51 )
{
const char * V_52 = strchr ( V_51 , ',' ) ;
if ( ! V_52 )
return V_51 ;
return V_52 + 1 ;
}
static void
F_33 ( struct V_6 * V_7 ,
struct V_53 * V_51 ,
unsigned int V_10 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < F_10 ( V_29 ) ; V_19 ++ ) {
unsigned long V_22 , V_3 ;
int V_27 ;
V_22 = F_12 ( V_29 [ V_19 ] . V_31 , 0 ) ;
V_27 = F_26 ( V_7 , V_10 ,
& V_22 ) ;
if ( V_27 < 0 )
continue;
V_3 = F_31 ( V_22 ) ;
F_34 ( V_51 , L_4 , F_32 ( V_29 [ V_19 ] . V_12 ) ,
V_3 ) ;
}
}
static void
F_35 ( struct V_6 * V_7 ,
struct V_53 * V_51 ,
unsigned long V_22 )
{
enum V_45 V_31 ;
const char * V_12 = L_5 ;
unsigned long V_3 ;
unsigned int V_19 ;
V_31 = F_27 ( V_22 ) ;
V_3 = F_31 ( V_22 ) ;
for ( V_19 = 0 ; V_19 < F_10 ( V_29 ) ; V_19 ++ ) {
if ( V_29 [ V_19 ] . V_31 == V_31 ) {
V_12 = V_29 [ V_19 ] . V_12 ;
break;
}
}
F_34 ( V_51 , L_6 , F_32 ( V_12 ) , V_3 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_37 ( & V_2 -> V_54 ) ;
if ( V_2 -> V_55 ++ > 0 )
goto V_30;
V_3 = F_3 ( V_2 , V_56 ) ;
V_3 &= ~ V_57 ;
F_1 ( V_2 , V_3 , V_56 ) ;
F_38 ( 100 , 200 ) ;
V_3 = F_3 ( V_2 , V_56 ) ;
V_3 &= ~ V_58 ;
F_1 ( V_2 , V_3 , V_56 ) ;
F_38 ( 100 , 200 ) ;
V_3 = F_3 ( V_2 , V_56 ) ;
V_3 &= ~ V_59 ;
F_1 ( V_2 , V_3 , V_56 ) ;
V_30:
F_39 ( & V_2 -> V_54 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_37 ( & V_2 -> V_54 ) ;
if ( F_41 ( V_2 -> V_55 == 0 ) )
goto V_30;
if ( -- V_2 -> V_55 > 0 )
goto V_30;
V_3 = F_3 ( V_2 , V_56 ) ;
V_3 |= V_59 ;
F_1 ( V_2 , V_3 , V_56 ) ;
F_38 ( 100 , 200 ) ;
V_3 = F_3 ( V_2 , V_56 ) ;
V_3 |= V_58 ;
F_1 ( V_2 , V_3 , V_56 ) ;
F_38 ( 100 , 200 ) ;
V_3 = F_3 ( V_2 , V_56 ) ;
V_3 |= V_57 ;
F_1 ( V_2 , V_3 , V_56 ) ;
V_30:
F_39 ( & V_2 -> V_54 ) ;
return 0 ;
}
static int F_42 ( struct V_60 * V_60 )
{
struct V_1 * V_2 = F_43 ( V_60 ) ;
return F_36 ( V_2 ) ;
}
static int F_44 ( struct V_60 * V_60 )
{
struct V_1 * V_2 = F_43 ( V_60 ) ;
return F_40 ( V_2 ) ;
}
static int F_45 ( struct V_60 * V_60 )
{
struct V_1 * V_2 = F_43 ( V_60 ) ;
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
V_61 = V_70 + F_46 ( 50 ) ;
while ( F_47 ( V_70 , V_61 ) ) {
V_3 = F_3 ( V_2 , V_63 ) ;
if ( V_3 & V_71 ) {
V_27 = 0 ;
break;
}
F_38 ( 100 , 200 ) ;
}
return V_27 ;
}
static int F_48 ( struct V_60 * V_60 )
{
struct V_1 * V_2 = F_43 ( V_60 ) ;
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_63 ) ;
V_3 &= ~ V_69 ;
F_1 ( V_2 , V_3 , V_63 ) ;
return 0 ;
}
static int F_49 ( struct V_60 * V_60 )
{
struct V_1 * V_2 = F_43 ( V_60 ) ;
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
V_61 = V_70 + F_46 ( 50 ) ;
while ( F_47 ( V_70 , V_61 ) ) {
V_3 = F_3 ( V_2 , V_75 ) ;
if ( V_3 & V_80 ) {
V_27 = 0 ;
break;
}
F_38 ( 100 , 200 ) ;
}
return V_27 ;
}
static int F_50 ( struct V_60 * V_60 )
{
struct V_1 * V_2 = F_43 ( V_60 ) ;
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
static struct V_60 * F_51 ( struct V_81 * V_48 ,
struct V_82 * args )
{
struct V_1 * V_2 = F_52 ( V_48 ) ;
unsigned int V_83 = args -> args [ 0 ] ;
if ( args -> V_84 <= 0 )
return F_53 ( - V_28 ) ;
if ( V_83 >= F_10 ( V_2 -> V_85 ) )
return F_53 ( - V_28 ) ;
return V_2 -> V_85 [ V_83 ] ;
}
static int F_54 ( struct V_86 * V_87 )
{
struct V_1 * V_2 ;
const struct V_88 * V_89 ;
struct V_90 * V_91 ;
struct V_60 * V_60 ;
int V_27 ;
V_2 = F_55 ( & V_87 -> V_48 , sizeof( * V_2 ) , V_92 ) ;
if ( ! V_2 )
return - V_93 ;
F_56 ( V_87 , V_2 ) ;
F_57 ( & V_2 -> V_54 ) ;
V_2 -> V_48 = & V_87 -> V_48 ;
V_89 = F_58 ( V_94 , V_87 -> V_48 . V_95 ) ;
V_2 -> V_8 = V_89 -> V_96 ;
V_91 = F_59 ( V_87 , V_97 , 0 ) ;
V_2 -> V_5 = F_60 ( & V_87 -> V_48 , V_91 ) ;
if ( F_61 ( V_2 -> V_5 ) )
return F_62 ( V_2 -> V_5 ) ;
V_2 -> V_98 = F_63 ( & V_87 -> V_48 , NULL ) ;
if ( F_61 ( V_2 -> V_98 ) )
return F_62 ( V_2 -> V_98 ) ;
V_27 = F_64 ( V_2 -> V_98 ) ;
if ( V_27 < 0 )
return V_27 ;
memset ( & V_2 -> V_99 , 0 , sizeof( V_2 -> V_99 ) ) ;
V_2 -> V_99 . V_12 = F_65 ( V_2 -> V_48 ) ;
V_2 -> V_99 . V_100 = & V_101 ;
V_2 -> V_99 . V_102 = & V_103 ;
V_2 -> V_99 . V_104 = & V_105 ;
V_2 -> V_99 . V_106 = V_107 ;
V_2 -> V_7 = F_66 ( & V_2 -> V_99 , & V_87 -> V_48 , V_2 ) ;
if ( ! V_2 -> V_7 ) {
F_29 ( & V_87 -> V_48 , L_7 ) ;
V_27 = - V_108 ;
goto V_109;
}
V_60 = F_67 ( & V_87 -> V_48 , NULL , & V_110 ) ;
if ( F_61 ( V_60 ) ) {
V_27 = F_62 ( V_60 ) ;
goto V_111;
}
V_2 -> V_85 [ V_112 ] = V_60 ;
F_68 ( V_60 , V_2 ) ;
V_60 = F_67 ( & V_87 -> V_48 , NULL , & V_113 ) ;
if ( F_61 ( V_60 ) ) {
V_27 = F_62 ( V_60 ) ;
goto V_111;
}
V_2 -> V_85 [ V_114 ] = V_60 ;
F_68 ( V_60 , V_2 ) ;
V_2 -> V_115 = F_69 ( & V_87 -> V_48 ,
F_51 ) ;
if ( F_61 ( V_2 -> V_115 ) ) {
V_27 = F_62 ( V_2 -> V_115 ) ;
F_29 ( & V_87 -> V_48 , L_8 , V_27 ) ;
goto V_111;
}
return 0 ;
V_111:
F_70 ( V_2 -> V_7 ) ;
V_109:
F_71 ( V_2 -> V_98 ) ;
return V_27 ;
}
static int F_72 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_73 ( V_87 ) ;
int V_27 ;
F_70 ( V_2 -> V_7 ) ;
V_27 = F_71 ( V_2 -> V_98 ) ;
if ( V_27 < 0 )
F_29 ( & V_87 -> V_48 , L_9 , V_27 ) ;
return V_27 ;
}
