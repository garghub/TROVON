static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) ) ;
}
static inline struct V_1 * F_4 ( struct V_4 * V_5 ,
unsigned V_6 )
{
return & V_5 -> V_7 [ V_6 / V_8 ] ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = F_6 ( V_10 ) ;
return V_5 -> V_11 ;
}
static const char * F_7 ( struct V_9 * V_10 ,
unsigned V_12 )
{
struct V_4 * V_5 = F_6 ( V_10 ) ;
return V_5 -> V_13 [ V_12 ] . V_14 ;
}
static int F_8 ( struct V_9 * V_10 ,
unsigned V_12 ,
const unsigned * * V_15 ,
unsigned * V_16 )
{
struct V_4 * V_5 = F_6 ( V_10 ) ;
* V_15 = & V_5 -> V_13 [ V_12 ] . V_6 ;
* V_16 = 1 ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = F_6 ( V_10 ) ;
return V_5 -> V_17 ;
}
static const char *
F_10 ( struct V_9 * V_10 , unsigned V_18 )
{
struct V_4 * V_5 = F_6 ( V_10 ) ;
return V_5 -> V_19 [ V_18 ] . V_14 ;
}
static int F_11 ( struct V_9 * V_10 ,
unsigned V_18 ,
const char * const * * V_13 ,
unsigned * const V_20 )
{
struct V_4 * V_5 = F_6 ( V_10 ) ;
* V_13 = V_5 -> V_19 [ V_18 ] . V_13 ;
* V_20 = V_5 -> V_19 [ V_18 ] . V_11 ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 ,
unsigned V_18 , unsigned V_12 )
{
struct V_4 * V_5 = F_6 ( V_10 ) ;
const struct V_21 * V_22 = & V_5 -> V_13 [ V_12 ] ;
const struct V_23 * V_24 = & V_5 -> V_19 [ V_18 ] ;
const char * V_25 = V_24 -> V_14 ;
struct V_26 * V_19 = V_22 -> V_19 ;
while ( V_19 -> V_14 ) {
if ( ! strcmp ( V_19 -> V_14 , V_25 ) ) {
F_13 ( V_5 -> V_27 ,
L_1 ,
V_25 , V_19 -> V_28 , V_19 -> V_29 ) ;
F_14 ( V_19 -> V_29 , V_5 -> V_30 + V_19 -> V_28 ) ;
return 0 ;
}
V_19 ++ ;
}
F_15 ( V_5 -> V_27 , L_2 , V_12 , V_18 ) ;
return - V_31 ;
}
static int F_16 ( struct V_9 * V_10 ,
struct V_32 * V_33 ,
unsigned V_34 )
{
struct V_4 * V_5 = F_6 ( V_10 ) ;
struct V_1 * V_35 = F_2 ( V_33 -> V_36 ) ;
T_1 V_37 = F_17 ( V_34 - V_35 -> V_38 . V_39 ) ;
F_13 ( V_5 -> V_27 , L_3 ,
V_34 , V_35 -> V_38 . V_39 , V_37 ) ;
F_14 ( V_37 , V_35 -> V_30 + F_18 ( V_40 ) ) ;
return 0 ;
}
static int F_19 ( struct V_38 * V_41 ,
unsigned V_34 )
{
struct V_1 * V_35 = F_2 ( V_41 ) ;
T_1 V_37 = F_17 ( V_34 ) ;
F_14 ( V_37 , V_35 -> V_30 + F_20 ( V_42 ) ) ;
return 0 ;
}
static int F_21 ( struct V_38 * V_41 , unsigned V_34 )
{
struct V_1 * V_35 = F_2 ( V_41 ) ;
return ! ! ( F_22 ( V_35 -> V_30 + V_43 ) & F_17 ( V_34 ) ) ;
}
static void F_23 ( struct V_38 * V_41 , unsigned V_34 ,
int V_44 )
{
struct V_1 * V_35 = F_2 ( V_41 ) ;
T_1 V_37 = F_17 ( V_34 ) ;
if ( V_44 )
F_14 ( V_37 , V_35 -> V_30 + F_20 ( V_43 ) ) ;
else
F_14 ( V_37 , V_35 -> V_30 + F_18 ( V_43 ) ) ;
}
static int F_24 ( struct V_38 * V_41 ,
unsigned V_34 , int V_44 )
{
struct V_1 * V_35 = F_2 ( V_41 ) ;
T_1 V_37 = F_17 ( V_34 ) ;
F_23 ( V_41 , V_34 , V_44 ) ;
F_14 ( V_37 , V_35 -> V_30 + F_18 ( V_42 ) ) ;
return 0 ;
}
static int F_25 ( struct V_9 * V_10 ,
struct V_32 * V_33 ,
unsigned V_34 , bool V_45 )
{
struct V_38 * V_41 = V_33 -> V_36 ;
if ( V_45 )
F_19 ( V_41 , V_34 ) ;
else
F_24 ( V_41 , V_34 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_9 * V_10 , unsigned V_6 ,
unsigned long * V_46 )
{
struct V_4 * V_5 = F_6 ( V_10 ) ;
struct V_1 * V_35 = F_4 ( V_5 , V_6 ) ;
unsigned V_47 = F_27 ( * V_46 ) ;
T_1 V_37 = F_17 ( V_6 - V_35 -> V_38 . V_39 ) ;
T_1 V_48 ;
switch ( V_47 ) {
case V_49 :
V_48 = ! ! ( F_22 ( V_35 -> V_30 + V_50 ) & V_37 ) ;
break;
case V_51 :
V_48 = ! ! ( F_22 ( V_35 -> V_30 + V_52 ) & V_37 ) ;
break;
case V_53 :
V_48 = ! ( F_22 ( V_35 -> V_30 + V_40 ) & V_37 ) ;
break;
case V_54 :
V_48 = ! ! ( F_22 ( V_35 -> V_30 + V_40 ) & V_37 ) ;
break;
case V_55 :
V_48 = ! ! ( F_22 ( V_35 -> V_30 + V_56 ) & V_37 ) ;
break;
case V_57 :
V_48 = ! ! ( F_22 ( V_35 -> V_30 + V_42 ) & V_37 ) ;
break;
case V_58 :
V_48 = ! ( F_22 ( V_35 -> V_30 + V_42 ) & V_37 ) ;
break;
default:
F_15 ( V_5 -> V_27 , L_4 , V_47 ) ;
return - V_59 ;
}
* V_46 = F_28 ( V_47 , V_48 ) ;
return 0 ;
}
static int F_29 ( struct V_9 * V_10 , unsigned V_6 ,
unsigned long * V_60 , unsigned V_61 )
{
struct V_4 * V_5 = F_6 ( V_10 ) ;
struct V_1 * V_35 = F_4 ( V_5 , V_6 ) ;
unsigned V_47 ;
T_1 V_48 ;
unsigned int V_62 ;
T_1 V_34 = V_6 - V_35 -> V_38 . V_39 ;
T_1 V_37 = F_17 ( V_34 ) ;
F_13 ( V_5 -> V_27 , L_5 ,
V_6 , V_35 -> V_38 . V_39 , V_37 ) ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
V_47 = F_27 ( V_60 [ V_62 ] ) ;
V_48 = F_30 ( V_60 [ V_62 ] ) ;
switch ( V_47 ) {
case V_49 :
F_13 ( V_5 -> V_27 , L_6 ) ;
F_14 ( V_37 , V_35 -> V_30 + F_20 ( V_50 ) ) ;
break;
case V_51 :
F_13 ( V_5 -> V_27 , L_7 ) ;
F_14 ( V_37 , V_35 -> V_30 + F_20 ( V_52 ) ) ;
break;
case V_53 :
F_13 ( V_5 -> V_27 , L_8 ) ;
F_14 ( V_37 , V_35 -> V_30 + F_18 ( V_40 ) ) ;
break;
case V_54 :
F_13 ( V_5 -> V_27 , L_9 ) ;
F_14 ( V_37 , V_35 -> V_30 + F_20 ( V_40 ) ) ;
break;
case V_55 :
F_13 ( V_5 -> V_27 , L_10 ) ;
F_14 ( V_37 , V_35 -> V_30 + F_20 ( V_56 ) ) ;
break;
case V_57 :
F_19 ( & V_35 -> V_38 , V_34 ) ;
break;
case V_58 :
F_24 ( & V_35 -> V_38 ,
V_34 , V_48 ) ;
break;
default:
F_15 ( V_5 -> V_27 , L_4 ,
V_47 ) ;
return - V_59 ;
}
}
return 0 ;
}
static int F_31 ( struct V_38 * V_41 , unsigned V_34 )
{
struct V_1 * V_35 = F_2 ( V_41 ) ;
return ! ! ( F_22 ( V_35 -> V_30 + V_42 ) & F_17 ( V_34 ) ) ;
}
static void F_32 ( struct V_2 * V_63 )
{
struct V_1 * V_35 = F_1 ( V_63 ) ;
F_14 ( 0 , V_35 -> V_30 + V_64 ) ;
}
static void F_33 ( struct V_2 * V_63 )
{
struct V_1 * V_35 = F_1 ( V_63 ) ;
F_14 ( F_17 ( V_65 ) , V_35 -> V_30 + F_18 ( V_66 ) ) ;
}
static void F_34 ( struct V_2 * V_63 )
{
struct V_1 * V_35 = F_1 ( V_63 ) ;
F_14 ( F_17 ( V_65 ) , V_35 -> V_30 + F_20 ( V_66 ) ) ;
}
static unsigned int F_35 ( struct V_2 * V_63 )
{
struct V_38 * V_41 = F_3 ( V_63 ) ;
F_19 ( V_41 , V_63 -> V_67 ) ;
F_34 ( V_63 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_63 , unsigned int type )
{
struct V_1 * V_35 = F_1 ( V_63 ) ;
T_1 V_37 = F_17 ( V_63 -> V_67 ) ;
switch ( type & V_68 ) {
case V_69 :
F_14 ( V_37 , V_35 -> V_30 + F_20 ( V_70 ) ) ;
F_14 ( V_37 , V_35 -> V_30 + F_18 ( V_71 ) ) ;
F_14 ( F_17 ( V_72 ) , V_35 -> V_30 + F_20 ( V_66 ) ) ;
break;
case V_73 :
F_14 ( V_37 , V_35 -> V_30 + F_18 ( V_70 ) ) ;
F_14 ( V_37 , V_35 -> V_30 + F_20 ( V_71 ) ) ;
F_14 ( F_17 ( V_72 ) , V_35 -> V_30 + F_20 ( V_66 ) ) ;
break;
case V_74 :
F_14 ( V_37 , V_35 -> V_30 + F_20 ( V_70 ) ) ;
F_14 ( V_37 , V_35 -> V_30 + F_20 ( V_71 ) ) ;
F_14 ( F_17 ( V_72 ) , V_35 -> V_30 + F_20 ( V_66 ) ) ;
break;
default:
return - V_31 ;
}
F_37 ( V_63 , V_75 ) ;
return 0 ;
}
static T_1 F_38 ( struct V_38 * V_36 , unsigned long V_76 )
{
struct V_1 * V_35 = F_2 ( V_36 ) ;
T_1 V_77 = 0 ;
T_1 V_78 , V_79 ;
T_1 V_6 ;
V_78 = F_22 ( V_35 -> V_30 + V_70 ) ;
V_79 = F_22 ( V_35 -> V_30 + V_71 ) ;
F_39 (pin, &status, BITS_PER_LONG) {
T_1 V_37 = F_17 ( V_6 ) ;
if ( ( V_37 & V_78 ) || ( V_37 && V_79 ) )
V_77 |= V_37 ;
}
return V_77 ;
}
static void F_40 ( struct V_80 * V_81 )
{
struct V_38 * V_36 = F_41 ( V_81 ) ;
struct V_1 * V_35 = F_2 ( V_36 ) ;
struct V_82 * V_41 = F_42 ( V_81 ) ;
unsigned long V_77 ;
unsigned int V_6 ;
T_1 V_83 ;
F_43 ( V_41 , V_81 ) ;
V_83 = F_22 ( V_35 -> V_30 + V_64 ) ;
V_77 = F_38 ( V_36 , V_83 ) ;
F_39 (pin, &pending, BITS_PER_LONG)
F_44 ( F_45 ( V_36 -> V_84 , V_6 ) ) ;
F_46 ( V_41 , V_81 ) ;
}
static int F_47 ( struct V_85 * V_86 )
{
struct V_4 * V_5 ;
struct V_87 * V_88 ;
int V_89 ;
V_5 = F_48 ( & V_86 -> V_27 , sizeof( * V_5 ) , V_90 ) ;
if ( ! V_5 )
return - V_91 ;
V_5 -> V_27 = & V_86 -> V_27 ;
F_49 ( & V_86 -> V_27 , V_5 ) ;
V_88 = F_50 ( V_86 , V_92 , 0 ) ;
V_5 -> V_30 = F_51 ( & V_86 -> V_27 , V_88 ) ;
if ( F_52 ( V_5 -> V_30 ) )
return F_53 ( V_5 -> V_30 ) ;
V_5 -> V_93 = F_54 ( & V_86 -> V_27 , NULL ) ;
if ( F_52 ( V_5 -> V_93 ) ) {
V_89 = F_53 ( V_5 -> V_93 ) ;
F_15 ( & V_86 -> V_27 , L_11 ) ;
return V_89 ;
}
V_89 = F_55 ( V_5 -> V_93 ) ;
if ( V_89 ) {
F_15 ( & V_86 -> V_27 , L_12 ) ;
return V_89 ;
}
V_5 -> V_15 = V_94 ;
V_5 -> V_95 = F_56 ( V_94 ) ;
V_5 -> V_19 = V_96 ;
V_5 -> V_17 = F_56 ( V_96 ) ;
V_5 -> V_13 = V_97 ;
V_5 -> V_11 = F_56 ( V_97 ) ;
V_5 -> V_7 = V_98 ;
V_5 -> V_99 = F_56 ( V_98 ) ;
V_100 . V_15 = V_5 -> V_15 ;
V_100 . V_95 = V_5 -> V_95 ;
V_100 . V_101 = V_102 ;
V_100 . V_103 = F_56 ( V_102 ) ;
V_5 -> V_10 = F_57 ( & V_100 , & V_86 -> V_27 , V_5 ) ;
if ( F_52 ( V_5 -> V_10 ) ) {
F_15 ( & V_86 -> V_27 , L_13 ) ;
return F_53 ( V_5 -> V_10 ) ;
}
return 0 ;
}
static int F_58 ( struct V_85 * V_86 )
{
struct V_104 * V_105 = V_86 -> V_27 . V_106 ;
struct V_1 * V_35 ;
T_1 V_107 ;
int V_108 , V_89 ;
struct V_87 * V_88 ;
if ( F_59 ( V_105 , L_14 , & V_107 ) ) {
F_15 ( & V_86 -> V_27 , L_15 ) ;
return - V_31 ;
}
if ( V_107 >= F_56 ( V_98 ) ) {
F_15 ( & V_86 -> V_27 , L_16 ) ;
return - V_31 ;
}
V_35 = & V_98 [ V_107 ] ;
V_88 = F_50 ( V_86 , V_92 , 0 ) ;
V_35 -> V_30 = F_51 ( & V_86 -> V_27 , V_88 ) ;
if ( F_52 ( V_35 -> V_30 ) )
return F_53 ( V_35 -> V_30 ) ;
V_108 = F_60 ( V_86 , 0 ) ;
if ( V_108 < 0 ) {
F_15 ( & V_86 -> V_27 , L_17 ) ;
return V_108 ;
}
V_35 -> V_93 = F_54 ( & V_86 -> V_27 , NULL ) ;
if ( F_52 ( V_35 -> V_93 ) ) {
V_89 = F_53 ( V_35 -> V_93 ) ;
F_15 ( & V_86 -> V_27 , L_11 ) ;
return V_89 ;
}
V_89 = F_55 ( V_35 -> V_93 ) ;
if ( V_89 ) {
F_15 ( & V_86 -> V_27 , L_12 ) ;
return V_89 ;
}
V_35 -> V_38 . V_109 = & V_86 -> V_27 ;
V_35 -> V_38 . V_106 = V_105 ;
V_89 = F_61 ( & V_35 -> V_38 , V_35 ) ;
if ( V_89 < 0 ) {
F_15 ( & V_86 -> V_27 , L_18 ,
V_107 , V_89 ) ;
return V_89 ;
}
V_89 = F_62 ( & V_35 -> V_38 , & V_35 -> V_82 ,
0 , V_110 , V_111 ) ;
if ( V_89 < 0 ) {
F_15 ( & V_86 -> V_27 , L_19 ,
V_107 , V_89 ) ;
F_63 ( & V_35 -> V_38 ) ;
return V_89 ;
}
F_64 ( & V_35 -> V_38 , & V_35 -> V_82 ,
V_108 , F_40 ) ;
return 0 ;
}
static int T_2 F_65 ( void )
{
return F_66 ( & V_112 ) ;
}
static int T_2 F_67 ( void )
{
return F_66 ( & V_113 ) ;
}
