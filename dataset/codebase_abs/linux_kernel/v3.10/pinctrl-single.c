static unsigned T_1 F_1 ( void T_2 * V_1 )
{
return F_2 ( V_1 ) ;
}
static unsigned T_1 F_3 ( void T_2 * V_1 )
{
return F_4 ( V_1 ) ;
}
static unsigned T_1 F_5 ( void T_2 * V_1 )
{
return F_6 ( V_1 ) ;
}
static void T_1 F_7 ( unsigned V_2 , void T_2 * V_1 )
{
F_8 ( V_2 , V_1 ) ;
}
static void T_1 F_9 ( unsigned V_2 , void T_2 * V_1 )
{
F_10 ( V_2 , V_1 ) ;
}
static void T_1 F_11 ( unsigned V_2 , void T_2 * V_1 )
{
F_12 ( V_2 , V_1 ) ;
}
static int F_13 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_14 ( V_4 ) ;
return V_6 -> V_7 ;
}
static const char * F_15 ( struct V_3 * V_4 ,
unsigned V_8 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
V_6 = F_14 ( V_4 ) ;
V_10 = F_16 ( & V_6 -> V_11 , V_8 ) ;
if ( ! V_10 ) {
F_17 ( V_6 -> V_12 , L_1 ,
V_13 , V_8 ) ;
return NULL ;
}
return V_10 -> V_14 ;
}
static int F_18 ( struct V_3 * V_4 ,
unsigned V_8 ,
const unsigned * * V_15 ,
unsigned * V_16 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
V_6 = F_14 ( V_4 ) ;
V_10 = F_16 ( & V_6 -> V_11 , V_8 ) ;
if ( ! V_10 ) {
F_17 ( V_6 -> V_12 , L_1 ,
V_13 , V_8 ) ;
return - V_17 ;
}
* V_15 = V_10 -> V_18 ;
* V_16 = V_10 -> V_19 ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 ,
struct V_20 * V_21 ,
unsigned V_22 )
{
struct V_5 * V_6 ;
unsigned V_2 , V_23 ;
V_6 = F_14 ( V_4 ) ;
V_23 = V_6 -> V_24 / V_25 ;
V_2 = V_6 -> V_26 ( V_6 -> V_27 + V_22 * V_23 ) ;
F_20 ( V_21 , L_2 , V_2 , V_28 ) ;
}
static void F_21 ( struct V_3 * V_4 ,
struct V_29 * V_30 , unsigned V_31 )
{
struct V_5 * V_6 ;
V_6 = F_14 ( V_4 ) ;
F_22 ( V_6 -> V_12 , V_30 ) ;
}
static int F_23 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_14 ( V_4 ) ;
return V_6 -> V_32 ;
}
static const char * F_24 ( struct V_3 * V_4 ,
unsigned V_33 )
{
struct V_5 * V_6 ;
struct V_34 * V_35 ;
V_6 = F_14 ( V_4 ) ;
V_35 = F_16 ( & V_6 -> V_36 , V_33 ) ;
if ( ! V_35 ) {
F_17 ( V_6 -> V_12 , L_3 ,
V_13 , V_33 ) ;
return NULL ;
}
return V_35 -> V_14 ;
}
static int F_25 ( struct V_3 * V_4 ,
unsigned V_33 ,
const char * const * * V_37 ,
unsigned * const V_7 )
{
struct V_5 * V_6 ;
struct V_34 * V_35 ;
V_6 = F_14 ( V_4 ) ;
V_35 = F_16 ( & V_6 -> V_36 , V_33 ) ;
if ( ! V_35 ) {
F_17 ( V_6 -> V_12 , L_3 ,
V_13 , V_33 ) ;
return - V_17 ;
}
* V_37 = V_35 -> V_38 ;
* V_7 = V_35 -> V_39 ;
return 0 ;
}
static int F_26 ( struct V_3 * V_4 , unsigned V_22 ,
struct V_34 * * V_35 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
struct V_40 * V_41 = F_27 ( V_4 , V_22 ) ;
const struct V_42 * V_43 ;
unsigned V_33 ;
V_43 = V_41 -> V_44 ;
if ( ! V_43 )
return - V_45 ;
V_33 = V_43 -> V_35 ;
* V_35 = F_16 ( & V_6 -> V_36 , V_33 ) ;
if ( ! ( * V_35 ) ) {
F_17 ( V_6 -> V_12 , L_3 ,
V_13 , V_33 ) ;
return - V_45 ;
}
return 0 ;
}
static int F_28 ( struct V_3 * V_4 , unsigned V_33 ,
unsigned V_10 )
{
struct V_5 * V_6 ;
struct V_34 * V_35 ;
int V_46 ;
V_6 = F_14 ( V_4 ) ;
if ( ! V_6 -> V_47 )
return 0 ;
V_35 = F_16 ( & V_6 -> V_36 , V_33 ) ;
if ( ! V_35 )
return - V_17 ;
F_29 ( V_6 -> V_12 , L_4 ,
V_35 -> V_14 , V_33 ) ;
for ( V_46 = 0 ; V_46 < V_35 -> V_48 ; V_46 ++ ) {
struct V_49 * V_50 ;
unsigned V_2 , V_51 ;
V_50 = & V_35 -> V_50 [ V_46 ] ;
V_2 = V_6 -> V_26 ( V_50 -> V_1 ) ;
if ( ! V_50 -> V_51 )
V_51 = V_6 -> V_47 ;
else
V_51 = V_6 -> V_47 & V_50 -> V_51 ;
V_2 &= ~ V_51 ;
V_2 |= ( V_50 -> V_2 & V_51 ) ;
V_6 -> V_52 ( V_2 , V_50 -> V_1 ) ;
}
return 0 ;
}
static void F_30 ( struct V_3 * V_4 , unsigned V_33 ,
unsigned V_10 )
{
struct V_5 * V_6 ;
struct V_34 * V_35 ;
int V_46 ;
V_6 = F_14 ( V_4 ) ;
if ( ! V_6 -> V_47 )
return;
V_35 = F_16 ( & V_6 -> V_36 , V_33 ) ;
if ( ! V_35 ) {
F_17 ( V_6 -> V_12 , L_3 ,
V_13 , V_33 ) ;
return;
}
if ( V_6 -> V_53 == V_54 ) {
F_29 ( V_6 -> V_12 , L_5 ,
V_35 -> V_14 , V_33 ) ;
return;
}
F_29 ( V_6 -> V_12 , L_6 ,
V_33 , V_35 -> V_14 ) ;
for ( V_46 = 0 ; V_46 < V_35 -> V_48 ; V_46 ++ ) {
struct V_49 * V_50 ;
unsigned V_2 ;
V_50 = & V_35 -> V_50 [ V_46 ] ;
V_2 = V_6 -> V_26 ( V_50 -> V_1 ) ;
V_2 &= ~ V_6 -> V_47 ;
V_2 |= V_6 -> V_53 << V_6 -> V_55 ;
V_6 -> V_52 ( V_2 , V_50 -> V_1 ) ;
}
}
static int F_31 ( struct V_3 * V_4 ,
struct V_56 * V_57 , unsigned V_22 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
struct V_58 * V_59 = NULL ;
struct V_60 * V_61 , * V_62 ;
int V_23 = 0 ;
unsigned V_63 ;
if ( ! V_6 -> V_47 )
return - V_45 ;
F_32 (pos, tmp, &pcs->gpiofuncs) {
V_59 = F_33 ( V_61 , struct V_58 , V_64 ) ;
if ( V_22 >= V_59 -> V_65 + V_59 -> V_16
|| V_22 < V_59 -> V_65 )
continue;
V_23 = V_6 -> V_24 / V_25 ;
V_63 = V_6 -> V_26 ( V_6 -> V_27 + V_22 * V_23 ) & ~ V_6 -> V_47 ;
V_63 |= V_59 -> V_66 ;
V_6 -> V_52 ( V_63 , V_6 -> V_27 + V_22 * V_23 ) ;
break;
}
return 0 ;
}
static void F_34 ( struct V_3 * V_4 , unsigned V_22 )
{
unsigned long V_67 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_35 ( V_68 ) ; V_46 ++ ) {
V_67 = F_36 ( V_68 [ V_46 ] , 0 ) ;
F_37 ( V_4 , V_22 , V_67 ) ;
}
}
static bool F_38 ( struct V_3 * V_4 , unsigned V_22 )
{
unsigned long V_67 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_35 ( V_68 ) ; V_46 ++ ) {
V_67 = F_36 ( V_68 [ V_46 ] , 0 ) ;
if ( ! F_39 ( V_4 , V_22 , & V_67 ) )
goto V_69;
}
return true ;
V_69:
return false ;
}
static int F_39 ( struct V_3 * V_4 ,
unsigned V_22 , unsigned long * V_67 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
struct V_34 * V_35 ;
enum V_70 V_71 ;
unsigned V_65 = 0 , V_63 = 0 , V_46 , V_72 , V_73 ;
V_73 = F_26 ( V_4 , V_22 , & V_35 ) ;
if ( V_73 )
return V_73 ;
for ( V_46 = 0 ; V_46 < V_35 -> V_74 ; V_46 ++ ) {
V_71 = F_40 ( * V_67 ) ;
if ( V_71 == V_75 ) {
if ( F_38 ( V_4 , V_22 ) ) {
* V_67 = 0 ;
return 0 ;
} else {
return - V_45 ;
}
} else if ( V_71 != V_35 -> V_76 [ V_46 ] . V_71 ) {
continue;
}
V_65 = V_22 * ( V_6 -> V_24 / V_25 ) ;
V_63 = V_6 -> V_26 ( V_6 -> V_27 + V_65 ) & V_35 -> V_76 [ V_46 ] . V_51 ;
switch ( V_35 -> V_76 [ V_46 ] . V_71 ) {
case V_77 :
case V_78 :
case V_79 :
if ( ( V_63 != V_35 -> V_76 [ V_46 ] . V_80 ) ||
( V_63 == V_35 -> V_76 [ V_46 ] . V_81 ) )
return - V_45 ;
* V_67 = 0 ;
break;
case V_82 :
for ( V_72 = 0 ; V_72 < V_35 -> V_74 ; V_72 ++ ) {
switch ( V_35 -> V_76 [ V_72 ] . V_71 ) {
case V_79 :
if ( V_63 != V_35 -> V_76 [ V_72 ] . V_80 )
return - V_45 ;
break;
default:
break;
}
}
* V_67 = V_63 ;
break;
case V_83 :
case V_84 :
default:
* V_67 = V_63 ;
break;
}
return 0 ;
}
return - V_45 ;
}
static int F_37 ( struct V_3 * V_4 ,
unsigned V_22 , unsigned long V_67 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
struct V_34 * V_35 ;
unsigned V_65 = 0 , V_85 = 0 , V_46 , V_63 , V_73 ;
T_3 V_86 ;
V_73 = F_26 ( V_4 , V_22 , & V_35 ) ;
if ( V_73 )
return V_73 ;
for ( V_46 = 0 ; V_46 < V_35 -> V_74 ; V_46 ++ ) {
if ( F_40 ( V_67 ) == V_35 -> V_76 [ V_46 ] . V_71 ) {
V_65 = V_22 * ( V_6 -> V_24 / V_25 ) ;
V_63 = V_6 -> V_26 ( V_6 -> V_27 + V_65 ) ;
V_86 = F_41 ( V_67 ) ;
switch ( V_35 -> V_76 [ V_46 ] . V_71 ) {
case V_82 :
case V_83 :
case V_84 :
V_85 = F_42 ( V_35 -> V_76 [ V_46 ] . V_51 ) - 1 ;
V_63 &= ~ V_35 -> V_76 [ V_46 ] . V_51 ;
V_63 |= ( V_86 << V_85 ) & V_35 -> V_76 [ V_46 ] . V_51 ;
break;
case V_75 :
F_34 ( V_4 , V_22 ) ;
break;
case V_77 :
case V_78 :
if ( V_86 )
F_34 ( V_4 , V_22 ) ;
case V_79 :
V_63 &= ~ V_35 -> V_76 [ V_46 ] . V_51 ;
if ( V_86 )
V_63 |= V_35 -> V_76 [ V_46 ] . V_80 ;
else
V_63 |= V_35 -> V_76 [ V_46 ] . V_81 ;
break;
default:
return - V_45 ;
}
V_6 -> V_52 ( V_63 , V_6 -> V_27 + V_65 ) ;
return 0 ;
}
}
return - V_45 ;
}
static int F_43 ( struct V_3 * V_4 ,
unsigned V_10 , unsigned long * V_67 )
{
const unsigned * V_15 ;
unsigned V_16 , V_87 = 0 ;
int V_46 , V_73 ;
V_73 = F_18 ( V_4 , V_10 , & V_15 , & V_16 ) ;
if ( V_73 )
return V_73 ;
for ( V_46 = 0 ; V_46 < V_16 ; V_46 ++ ) {
if ( F_39 ( V_4 , V_15 [ V_46 ] , V_67 ) )
return - V_45 ;
if ( V_46 && ( V_87 != * V_67 ) )
return - V_45 ;
V_87 = * V_67 ;
}
return 0 ;
}
static int F_44 ( struct V_3 * V_4 ,
unsigned V_10 , unsigned long V_67 )
{
const unsigned * V_15 ;
unsigned V_16 ;
int V_46 , V_73 ;
V_73 = F_18 ( V_4 , V_10 , & V_15 , & V_16 ) ;
if ( V_73 )
return V_73 ;
for ( V_46 = 0 ; V_46 < V_16 ; V_46 ++ ) {
if ( F_37 ( V_4 , V_15 [ V_46 ] , V_67 ) )
return - V_45 ;
}
return 0 ;
}
static void F_45 ( struct V_3 * V_4 ,
struct V_20 * V_21 , unsigned V_22 )
{
}
static void F_46 ( struct V_3 * V_4 ,
struct V_20 * V_21 , unsigned V_88 )
{
}
static void F_47 ( struct V_3 * V_4 ,
struct V_20 * V_21 ,
unsigned long V_67 )
{
F_48 ( V_4 , V_21 , V_67 ) ;
}
static int F_49 ( struct V_5 * V_6 , unsigned V_65 )
{
struct V_89 * V_22 ;
struct V_90 * V_91 ;
int V_46 ;
V_46 = V_6 -> V_15 . V_92 ;
if ( V_46 >= V_6 -> V_93 . V_16 ) {
F_17 ( V_6 -> V_12 , L_7 ,
V_6 -> V_93 . V_16 ) ;
return - V_94 ;
}
V_22 = & V_6 -> V_15 . V_95 [ V_46 ] ;
V_91 = & V_6 -> V_96 [ V_46 ] ;
sprintf ( V_91 -> V_14 , L_8 ,
( unsigned long ) V_6 -> V_97 -> V_98 + V_65 ) ;
V_22 -> V_14 = V_91 -> V_14 ;
V_22 -> V_99 = V_46 ;
V_6 -> V_15 . V_92 ++ ;
return V_46 ;
}
static int F_50 ( struct V_5 * V_6 )
{
int V_23 , V_100 , V_46 ;
V_23 = V_6 -> V_24 / V_25 ;
V_100 = V_6 -> V_101 / V_23 ;
F_29 ( V_6 -> V_12 , L_9 , V_100 ) ;
V_6 -> V_15 . V_95 = F_51 ( V_6 -> V_12 ,
sizeof( * V_6 -> V_15 . V_95 ) * V_100 ,
V_102 ) ;
if ( ! V_6 -> V_15 . V_95 )
return - V_94 ;
V_6 -> V_96 = F_51 ( V_6 -> V_12 ,
sizeof( struct V_90 ) * V_100 ,
V_102 ) ;
if ( ! V_6 -> V_96 )
return - V_94 ;
V_6 -> V_93 . V_15 = V_6 -> V_15 . V_95 ;
V_6 -> V_93 . V_16 = V_100 ;
for ( V_46 = 0 ; V_46 < V_6 -> V_93 . V_16 ; V_46 ++ ) {
unsigned V_65 ;
int V_97 ;
V_65 = V_46 * V_23 ;
V_97 = F_49 ( V_6 , V_65 ) ;
if ( V_97 < 0 ) {
F_17 ( V_6 -> V_12 , L_10 , V_97 ) ;
return V_97 ;
}
}
return 0 ;
}
static struct V_34 * F_52 ( struct V_5 * V_6 ,
struct V_103 * V_104 ,
const char * V_14 ,
struct V_49 * V_50 ,
unsigned V_48 ,
const char * * V_38 ,
unsigned V_39 )
{
struct V_34 * V_105 ;
V_105 = F_51 ( V_6 -> V_12 , sizeof( * V_105 ) , V_102 ) ;
if ( ! V_105 )
return NULL ;
V_105 -> V_14 = V_14 ;
V_105 -> V_50 = V_50 ;
V_105 -> V_48 = V_48 ;
V_105 -> V_38 = V_38 ;
V_105 -> V_39 = V_39 ;
F_53 ( & V_6 -> V_106 ) ;
F_54 ( & V_105 -> V_64 , & V_6 -> V_107 ) ;
F_55 ( & V_6 -> V_36 , V_6 -> V_32 , V_105 ) ;
V_6 -> V_32 ++ ;
F_56 ( & V_6 -> V_106 ) ;
return V_105 ;
}
static void F_57 ( struct V_5 * V_6 ,
struct V_34 * V_105 )
{
int V_46 ;
F_53 ( & V_6 -> V_106 ) ;
for ( V_46 = 0 ; V_46 < V_6 -> V_32 ; V_46 ++ ) {
struct V_34 * V_108 ;
V_108 = F_16 ( & V_6 -> V_36 , V_46 ) ;
if ( V_108 == V_105 )
F_58 ( & V_6 -> V_36 , V_46 ) ;
}
F_59 ( & V_105 -> V_64 ) ;
F_56 ( & V_6 -> V_106 ) ;
}
static int F_60 ( struct V_5 * V_6 ,
struct V_103 * V_104 ,
const char * V_14 ,
int * V_18 ,
int V_19 )
{
struct V_9 * V_109 ;
V_109 = F_51 ( V_6 -> V_12 , sizeof( * V_109 ) , V_102 ) ;
if ( ! V_109 )
return - V_94 ;
V_109 -> V_14 = V_14 ;
V_109 -> V_104 = V_104 ;
V_109 -> V_18 = V_18 ;
V_109 -> V_19 = V_19 ;
F_53 ( & V_6 -> V_106 ) ;
F_54 ( & V_109 -> V_64 , & V_6 -> V_110 ) ;
F_55 ( & V_6 -> V_11 , V_6 -> V_7 , V_109 ) ;
V_6 -> V_7 ++ ;
F_56 ( & V_6 -> V_106 ) ;
return 0 ;
}
static int F_61 ( struct V_5 * V_6 , unsigned V_65 )
{
unsigned V_111 ;
if ( V_65 >= V_6 -> V_101 ) {
F_17 ( V_6 -> V_12 , L_11 ,
V_65 , V_6 -> V_101 ) ;
return - V_17 ;
}
V_111 = V_65 / ( V_6 -> V_24 / V_25 ) ;
return V_111 ;
}
static int F_62 ( unsigned V_63 , unsigned V_80 , unsigned V_81 )
{
int V_73 = - V_17 ;
if ( V_63 == V_80 )
V_73 = 1 ;
else if ( V_63 == V_81 )
V_73 = 0 ;
return V_73 ;
}
static void F_63 ( struct V_112 * * V_76 , enum V_70 V_71 ,
unsigned V_113 , unsigned V_80 , unsigned V_81 ,
unsigned V_51 )
{
( * V_76 ) -> V_71 = V_71 ;
( * V_76 ) -> V_2 = V_113 ;
( * V_76 ) -> V_80 = V_80 ;
( * V_76 ) -> V_81 = V_81 ;
( * V_76 ) -> V_51 = V_51 ;
( * V_76 ) ++ ;
}
static void F_64 ( unsigned long * * V_43 , enum V_70 V_71 ,
unsigned V_86 )
{
* * V_43 = F_36 ( V_71 , V_86 ) ;
( * V_43 ) ++ ;
}
static void F_65 ( struct V_5 * V_6 , struct V_103 * V_104 ,
const char * V_14 , enum V_70 V_71 ,
struct V_112 * * V_76 , unsigned long * * V_114 )
{
unsigned V_113 [ 2 ] , V_85 ;
int V_73 ;
V_73 = F_66 ( V_104 , V_14 , V_113 , 2 ) ;
if ( V_73 )
return;
V_113 [ 0 ] &= V_113 [ 1 ] ;
V_85 = F_42 ( V_113 [ 1 ] ) - 1 ;
F_63 ( V_76 , V_71 , V_113 [ 0 ] , 0 , 0 , V_113 [ 1 ] ) ;
F_64 ( V_114 , V_71 , V_113 [ 0 ] >> V_85 ) ;
}
static void F_67 ( struct V_5 * V_6 , struct V_103 * V_104 ,
const char * V_14 , enum V_70 V_71 ,
struct V_112 * * V_76 , unsigned long * * V_114 )
{
unsigned V_113 [ 4 ] ;
int V_73 ;
V_73 = F_66 ( V_104 , V_14 , V_113 , 4 ) ;
if ( V_73 )
return;
if ( ! V_113 [ 3 ] ) {
F_17 ( V_6 -> V_12 , L_12 ) ;
return;
}
V_113 [ 0 ] &= V_113 [ 3 ] ;
V_113 [ 1 ] &= V_113 [ 3 ] ;
V_113 [ 2 ] &= V_113 [ 3 ] ;
V_73 = F_62 ( V_113 [ 0 ] , V_113 [ 1 ] , V_113 [ 2 ] ) ;
if ( V_73 < 0 )
F_29 ( V_6 -> V_12 , L_13 ) ;
F_63 ( V_76 , V_71 , V_113 [ 0 ] , V_113 [ 1 ] , V_113 [ 2 ] , V_113 [ 3 ] ) ;
F_64 ( V_114 , V_71 , V_73 ) ;
}
static int F_68 ( struct V_5 * V_6 , struct V_103 * V_104 ,
struct V_34 * V_35 ,
struct V_29 * * V_30 )
{
struct V_29 * V_115 = * V_30 ;
int V_46 = 0 , V_74 = 0 ;
unsigned long * V_114 = NULL , * V_21 = NULL ;
struct V_112 * V_76 = NULL ;
struct V_116 V_117 [] = {
{ L_14 , V_83 , } ,
{ L_15 , V_84 , } ,
{ L_16 , V_82 , } ,
} ;
struct V_116 V_118 [] = {
{ L_17 , V_78 , } ,
{ L_18 , V_77 , } ,
{ L_19 ,
V_79 , } ,
} ;
if ( ! V_6 -> V_119 )
return 0 ;
for ( V_46 = 0 ; V_46 < F_35 ( V_117 ) ; V_46 ++ ) {
if ( F_69 ( V_104 , V_117 [ V_46 ] . V_14 , NULL ) )
V_74 ++ ;
}
for ( V_46 = 0 ; V_46 < F_35 ( V_118 ) ; V_46 ++ ) {
if ( F_69 ( V_104 , V_118 [ V_46 ] . V_14 , NULL ) )
V_74 ++ ;
}
if ( ! V_74 )
return 0 ;
V_35 -> V_76 = F_51 ( V_6 -> V_12 ,
sizeof( struct V_112 ) * V_74 ,
V_102 ) ;
if ( ! V_35 -> V_76 )
return - V_94 ;
V_35 -> V_74 = V_74 ;
V_76 = & ( V_35 -> V_76 [ 0 ] ) ;
V_115 ++ ;
V_114 = F_51 ( V_6 -> V_12 , sizeof( unsigned long ) * V_74 ,
V_102 ) ;
if ( ! V_114 )
return - V_94 ;
V_21 = & V_114 [ 0 ] ;
for ( V_46 = 0 ; V_46 < F_35 ( V_117 ) ; V_46 ++ )
F_65 ( V_6 , V_104 , V_117 [ V_46 ] . V_14 , V_117 [ V_46 ] . V_71 ,
& V_76 , & V_21 ) ;
for ( V_46 = 0 ; V_46 < F_35 ( V_118 ) ; V_46 ++ )
F_67 ( V_6 , V_104 , V_118 [ V_46 ] . V_14 , V_118 [ V_46 ] . V_71 ,
& V_76 , & V_21 ) ;
V_115 -> type = V_120 ;
V_115 -> V_63 . V_121 . V_122 = V_104 -> V_14 ;
V_115 -> V_63 . V_121 . V_121 = V_114 ;
V_115 -> V_63 . V_121 . V_123 = V_74 ;
return 0 ;
}
static int F_70 ( struct V_5 * V_6 ,
struct V_103 * V_104 ,
struct V_29 * * V_30 ,
unsigned * V_31 ,
const char * * V_38 )
{
struct V_49 * V_50 ;
const T_4 * V_124 ;
int V_101 , V_125 , V_126 , * V_15 , V_111 = 0 , V_108 = 0 , V_97 = - V_94 ;
struct V_34 * V_105 ;
if ( V_6 -> V_127 ) {
V_125 = 3 ;
V_124 = F_71 ( V_104 , V_128 , & V_101 ) ;
} else {
V_125 = 2 ;
V_124 = F_71 ( V_104 , V_129 , & V_101 ) ;
}
if ( ! V_124 ) {
F_17 ( V_6 -> V_12 , L_20 , V_104 -> V_14 ) ;
return - V_17 ;
}
if ( V_101 < ( sizeof( * V_124 ) * V_125 ) ) {
F_17 ( V_6 -> V_12 , L_21 , V_104 -> V_14 ) ;
return - V_17 ;
}
V_101 /= sizeof( * V_124 ) ;
V_126 = V_101 / V_125 ;
V_50 = F_51 ( V_6 -> V_12 , sizeof( * V_50 ) * V_126 , V_102 ) ;
if ( ! V_50 )
return - V_94 ;
V_15 = F_51 ( V_6 -> V_12 , sizeof( * V_15 ) * V_126 , V_102 ) ;
if ( ! V_15 )
goto V_130;
while ( V_111 < V_101 ) {
unsigned V_65 , V_2 ;
int V_22 ;
V_65 = F_72 ( V_124 + V_111 ++ ) ;
V_2 = F_72 ( V_124 + V_111 ++ ) ;
V_50 [ V_108 ] . V_1 = V_6 -> V_27 + V_65 ;
V_50 [ V_108 ] . V_2 = V_2 ;
if ( V_125 == 3 ) {
V_2 = F_72 ( V_124 + V_111 ++ ) ;
V_50 [ V_108 ] . V_51 = V_2 ;
}
V_22 = F_61 ( V_6 , V_65 ) ;
if ( V_22 < 0 ) {
F_17 ( V_6 -> V_12 ,
L_22 ,
V_104 -> V_14 , V_65 ) ;
break;
}
V_15 [ V_108 ++ ] = V_22 ;
}
V_38 [ 0 ] = V_104 -> V_14 ;
V_105 = F_52 ( V_6 , V_104 , V_104 -> V_14 , V_50 , V_108 , V_38 , 1 ) ;
if ( ! V_105 )
goto V_131;
V_97 = F_60 ( V_6 , V_104 , V_104 -> V_14 , V_15 , V_108 ) ;
if ( V_97 < 0 )
goto V_132;
( * V_30 ) -> type = V_133 ;
( * V_30 ) -> V_63 . V_124 . V_10 = V_104 -> V_14 ;
( * V_30 ) -> V_63 . V_124 . V_105 = V_104 -> V_14 ;
if ( V_6 -> V_119 ) {
V_97 = F_68 ( V_6 , V_104 , V_105 , V_30 ) ;
if ( V_97 )
goto V_134;
* V_31 = 2 ;
} else {
* V_31 = 1 ;
}
return 0 ;
V_134:
F_73 ( V_6 ) ;
* V_31 = 1 ;
V_132:
F_57 ( V_6 , V_105 ) ;
V_131:
F_22 ( V_6 -> V_12 , V_15 ) ;
V_130:
F_22 ( V_6 -> V_12 , V_50 ) ;
return V_97 ;
}
static int F_74 ( struct V_3 * V_4 ,
struct V_103 * V_135 ,
struct V_29 * * V_30 , unsigned * V_31 )
{
struct V_5 * V_6 ;
const char * * V_38 ;
int V_73 ;
V_6 = F_14 ( V_4 ) ;
* V_30 = F_51 ( V_6 -> V_12 , sizeof( * * V_30 ) * 2 , V_102 ) ;
if ( ! * V_30 )
return - V_94 ;
* V_31 = 0 ;
V_38 = F_51 ( V_6 -> V_12 , sizeof( * V_38 ) , V_102 ) ;
if ( ! V_38 ) {
V_73 = - V_94 ;
goto V_136;
}
V_73 = F_70 ( V_6 , V_135 , V_30 , V_31 ,
V_38 ) ;
if ( V_73 < 0 ) {
F_17 ( V_6 -> V_12 , L_23 ,
V_135 -> V_14 ) ;
goto V_137;
}
return 0 ;
V_137:
F_22 ( V_6 -> V_12 , V_38 ) ;
V_136:
F_22 ( V_6 -> V_12 , * V_30 ) ;
return V_73 ;
}
static void F_75 ( struct V_5 * V_6 )
{
struct V_60 * V_61 , * V_62 ;
int V_46 ;
F_53 ( & V_6 -> V_106 ) ;
for ( V_46 = 0 ; V_46 < V_6 -> V_32 ; V_46 ++ ) {
struct V_34 * V_35 ;
V_35 = F_16 ( & V_6 -> V_36 , V_46 ) ;
if ( ! V_35 )
continue;
F_58 ( & V_6 -> V_36 , V_46 ) ;
}
F_32 (pos, tmp, &pcs->functions) {
struct V_34 * V_105 ;
V_105 = F_33 ( V_61 , struct V_34 , V_64 ) ;
F_59 ( & V_105 -> V_64 ) ;
}
F_56 ( & V_6 -> V_106 ) ;
}
static void F_73 ( struct V_5 * V_6 )
{
struct V_60 * V_61 , * V_62 ;
int V_46 ;
F_53 ( & V_6 -> V_106 ) ;
for ( V_46 = 0 ; V_46 < V_6 -> V_7 ; V_46 ++ ) {
struct V_9 * V_109 ;
V_109 = F_16 ( & V_6 -> V_11 , V_46 ) ;
if ( ! V_109 )
continue;
F_58 ( & V_6 -> V_11 , V_46 ) ;
}
F_32 (pos, tmp, &pcs->pingroups) {
struct V_9 * V_109 ;
V_109 = F_33 ( V_61 , struct V_9 , V_64 ) ;
F_59 ( & V_109 -> V_64 ) ;
}
F_56 ( & V_6 -> V_106 ) ;
}
static void F_76 ( struct V_5 * V_6 )
{
if ( V_6 -> V_138 )
F_77 ( V_6 -> V_138 ) ;
F_75 ( V_6 ) ;
F_73 ( V_6 ) ;
}
static int F_78 ( struct V_103 * V_64 , struct V_5 * V_6 )
{
const char * V_139 = L_24 ;
const char * V_140 = L_25 ;
struct V_141 V_142 ;
struct V_58 * V_57 ;
int V_73 , V_46 ;
for ( V_46 = 0 ; ; V_46 ++ ) {
V_73 = F_79 ( V_64 , V_139 , V_140 ,
V_46 , & V_142 ) ;
if ( V_73 ) {
V_73 = 0 ;
break;
}
V_57 = F_51 ( V_6 -> V_12 , sizeof( * V_57 ) , V_102 ) ;
if ( ! V_57 ) {
V_73 = - V_94 ;
break;
}
V_57 -> V_65 = V_142 . args [ 0 ] ;
V_57 -> V_16 = V_142 . args [ 1 ] ;
V_57 -> V_66 = V_142 . args [ 2 ] ;
F_53 ( & V_6 -> V_106 ) ;
F_54 ( & V_57 -> V_64 , & V_6 -> V_143 ) ;
F_56 ( & V_6 -> V_106 ) ;
}
return V_73 ;
}
static int F_80 ( struct V_144 * V_145 )
{
struct V_103 * V_104 = V_145 -> V_12 . V_146 ;
const struct V_147 * V_148 ;
struct V_149 * V_97 ;
struct V_5 * V_6 ;
int V_73 ;
V_148 = F_81 ( V_150 , & V_145 -> V_12 ) ;
if ( ! V_148 )
return - V_17 ;
V_6 = F_51 ( & V_145 -> V_12 , sizeof( * V_6 ) , V_102 ) ;
if ( ! V_6 ) {
F_17 ( & V_145 -> V_12 , L_26 ) ;
return - V_94 ;
}
V_6 -> V_12 = & V_145 -> V_12 ;
F_82 ( & V_6 -> V_106 ) ;
F_83 ( & V_6 -> V_110 ) ;
F_83 ( & V_6 -> V_107 ) ;
F_83 ( & V_6 -> V_143 ) ;
V_6 -> V_119 = V_148 -> V_63 ;
F_84 ( L_27 , & V_6 -> V_24 ,
L_28 ) ;
V_73 = F_85 ( V_104 , L_29 ,
& V_6 -> V_47 ) ;
if ( ! V_73 ) {
V_6 -> V_55 = F_42 ( V_6 -> V_47 ) - 1 ;
V_6 -> V_151 = V_6 -> V_47 >> V_6 -> V_55 ;
} else {
V_6 -> V_47 = 0 ;
V_6 -> V_55 = 0 ;
V_6 -> V_151 = 0 ;
}
V_73 = F_85 ( V_104 , L_30 ,
& V_6 -> V_53 ) ;
if ( V_73 )
V_6 -> V_53 = V_54 ;
V_6 -> V_127 = F_86 ( V_104 ,
L_31 ) ;
V_97 = F_87 ( V_145 , V_152 , 0 ) ;
if ( ! V_97 ) {
F_17 ( V_6 -> V_12 , L_32 ) ;
return - V_153 ;
}
V_6 -> V_97 = F_88 ( V_6 -> V_12 , V_97 -> V_98 ,
F_89 ( V_97 ) , V_28 ) ;
if ( ! V_6 -> V_97 ) {
F_17 ( V_6 -> V_12 , L_33 ) ;
return - V_154 ;
}
V_6 -> V_101 = F_89 ( V_6 -> V_97 ) ;
V_6 -> V_27 = F_90 ( V_6 -> V_12 , V_6 -> V_97 -> V_98 , V_6 -> V_101 ) ;
if ( ! V_6 -> V_27 ) {
F_17 ( V_6 -> V_12 , L_34 ) ;
return - V_153 ;
}
F_91 ( & V_6 -> V_11 , V_102 ) ;
F_91 ( & V_6 -> V_36 , V_102 ) ;
F_92 ( V_145 , V_6 ) ;
switch ( V_6 -> V_24 ) {
case 8 :
V_6 -> V_26 = F_1 ;
V_6 -> V_52 = F_7 ;
break;
case 16 :
V_6 -> V_26 = F_3 ;
V_6 -> V_52 = F_9 ;
break;
case 32 :
V_6 -> V_26 = F_5 ;
V_6 -> V_52 = F_11 ;
break;
default:
break;
}
V_6 -> V_93 . V_14 = V_28 ;
V_6 -> V_93 . V_155 = & V_156 ;
V_6 -> V_93 . V_157 = & V_158 ;
if ( V_6 -> V_119 )
V_6 -> V_93 . V_159 = & V_160 ;
V_6 -> V_93 . V_161 = V_162 ;
V_73 = F_50 ( V_6 ) ;
if ( V_73 < 0 )
goto free;
V_6 -> V_138 = F_93 ( & V_6 -> V_93 , V_6 -> V_12 , V_6 ) ;
if ( ! V_6 -> V_138 ) {
F_17 ( V_6 -> V_12 , L_35 ) ;
V_73 = - V_17 ;
goto free;
}
V_73 = F_78 ( V_104 , V_6 ) ;
if ( V_73 < 0 )
goto free;
F_94 ( V_6 -> V_12 , L_36 ,
V_6 -> V_93 . V_16 , V_6 -> V_27 , V_6 -> V_101 ) ;
return 0 ;
free:
F_76 ( V_6 ) ;
return V_73 ;
}
static int F_95 ( struct V_144 * V_145 )
{
struct V_5 * V_6 = F_96 ( V_145 ) ;
if ( ! V_6 )
return 0 ;
F_76 ( V_6 ) ;
return 0 ;
}
