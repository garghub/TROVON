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
unsigned long V_24 ;
T_3 V_25 ;
V_6 = F_14 ( V_4 ) ;
V_23 = V_6 -> V_26 / V_27 ;
V_24 = V_22 * V_23 ;
V_2 = V_6 -> V_28 ( V_6 -> V_29 + V_24 ) ;
V_25 = V_6 -> V_30 -> V_31 + V_24 ;
F_20 ( V_21 , L_2 , V_25 , V_2 , V_32 ) ;
}
static void F_21 ( struct V_3 * V_4 ,
struct V_33 * V_34 , unsigned V_35 )
{
struct V_5 * V_6 ;
V_6 = F_14 ( V_4 ) ;
F_22 ( V_6 -> V_12 , V_34 ) ;
}
static int F_23 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_14 ( V_4 ) ;
return V_6 -> V_36 ;
}
static const char * F_24 ( struct V_3 * V_4 ,
unsigned V_37 )
{
struct V_5 * V_6 ;
struct V_38 * V_39 ;
V_6 = F_14 ( V_4 ) ;
V_39 = F_16 ( & V_6 -> V_40 , V_37 ) ;
if ( ! V_39 ) {
F_17 ( V_6 -> V_12 , L_3 ,
V_13 , V_37 ) ;
return NULL ;
}
return V_39 -> V_14 ;
}
static int F_25 ( struct V_3 * V_4 ,
unsigned V_37 ,
const char * const * * V_41 ,
unsigned * const V_7 )
{
struct V_5 * V_6 ;
struct V_38 * V_39 ;
V_6 = F_14 ( V_4 ) ;
V_39 = F_16 ( & V_6 -> V_40 , V_37 ) ;
if ( ! V_39 ) {
F_17 ( V_6 -> V_12 , L_3 ,
V_13 , V_37 ) ;
return - V_17 ;
}
* V_41 = V_39 -> V_42 ;
* V_7 = V_39 -> V_43 ;
return 0 ;
}
static int F_26 ( struct V_3 * V_4 , unsigned V_22 ,
struct V_38 * * V_39 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
struct V_44 * V_45 = F_27 ( V_4 , V_22 ) ;
const struct V_46 * V_47 ;
unsigned V_37 ;
V_47 = V_45 -> V_48 ;
if ( ! V_47 )
return - V_49 ;
V_37 = V_47 -> V_39 ;
* V_39 = F_16 ( & V_6 -> V_40 , V_37 ) ;
if ( ! ( * V_39 ) ) {
F_17 ( V_6 -> V_12 , L_3 ,
V_13 , V_37 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_28 ( struct V_3 * V_4 , unsigned V_37 ,
unsigned V_10 )
{
struct V_5 * V_6 ;
struct V_38 * V_39 ;
int V_50 ;
V_6 = F_14 ( V_4 ) ;
if ( ! V_6 -> V_51 )
return 0 ;
V_39 = F_16 ( & V_6 -> V_40 , V_37 ) ;
if ( ! V_39 )
return - V_17 ;
F_29 ( V_6 -> V_12 , L_4 ,
V_39 -> V_14 , V_37 ) ;
for ( V_50 = 0 ; V_50 < V_39 -> V_52 ; V_50 ++ ) {
struct V_53 * V_54 ;
unsigned long V_55 ;
unsigned V_2 , V_56 ;
V_54 = & V_39 -> V_54 [ V_50 ] ;
F_30 ( & V_6 -> V_57 , V_55 ) ;
V_2 = V_6 -> V_28 ( V_54 -> V_1 ) ;
if ( V_6 -> V_58 )
V_56 = V_54 -> V_56 ;
else
V_56 = V_6 -> V_51 ;
V_2 &= ~ V_56 ;
V_2 |= ( V_54 -> V_2 & V_56 ) ;
V_6 -> V_59 ( V_2 , V_54 -> V_1 ) ;
F_31 ( & V_6 -> V_57 , V_55 ) ;
}
return 0 ;
}
static int F_32 ( struct V_3 * V_4 ,
struct V_60 * V_61 , unsigned V_22 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
struct V_62 * V_63 = NULL ;
struct V_64 * V_65 , * V_66 ;
int V_23 = 0 ;
unsigned V_67 ;
if ( ! V_6 -> V_51 )
return - V_49 ;
F_33 (pos, tmp, &pcs->gpiofuncs) {
V_63 = F_34 ( V_65 , struct V_62 , V_68 ) ;
if ( V_22 >= V_63 -> V_24 + V_63 -> V_16
|| V_22 < V_63 -> V_24 )
continue;
V_23 = V_6 -> V_26 / V_27 ;
V_67 = V_6 -> V_28 ( V_6 -> V_29 + V_22 * V_23 ) & ~ V_6 -> V_51 ;
V_67 |= V_63 -> V_69 ;
V_6 -> V_59 ( V_67 , V_6 -> V_29 + V_22 * V_23 ) ;
break;
}
return 0 ;
}
static void F_35 ( struct V_3 * V_4 , unsigned V_22 )
{
unsigned long V_70 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < F_36 ( V_71 ) ; V_50 ++ ) {
V_70 = F_37 ( V_71 [ V_50 ] , 0 ) ;
F_38 ( V_4 , V_22 , & V_70 , 1 ) ;
}
}
static bool F_39 ( struct V_3 * V_4 , unsigned V_22 )
{
unsigned long V_70 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < F_36 ( V_71 ) ; V_50 ++ ) {
V_70 = F_37 ( V_71 [ V_50 ] , 0 ) ;
if ( ! F_40 ( V_4 , V_22 , & V_70 ) )
goto V_72;
}
return true ;
V_72:
return false ;
}
static int F_40 ( struct V_3 * V_4 ,
unsigned V_22 , unsigned long * V_70 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
struct V_38 * V_39 ;
enum V_73 V_74 ;
unsigned V_24 = 0 , V_67 = 0 , V_50 , V_75 , V_76 ;
V_76 = F_26 ( V_4 , V_22 , & V_39 ) ;
if ( V_76 )
return V_76 ;
for ( V_50 = 0 ; V_50 < V_39 -> V_77 ; V_50 ++ ) {
V_74 = F_41 ( * V_70 ) ;
if ( V_74 == V_78 ) {
if ( F_39 ( V_4 , V_22 ) ) {
* V_70 = 0 ;
return 0 ;
} else {
return - V_49 ;
}
} else if ( V_74 != V_39 -> V_79 [ V_50 ] . V_74 ) {
continue;
}
V_24 = V_22 * ( V_6 -> V_26 / V_27 ) ;
V_67 = V_6 -> V_28 ( V_6 -> V_29 + V_24 ) & V_39 -> V_79 [ V_50 ] . V_56 ;
switch ( V_39 -> V_79 [ V_50 ] . V_74 ) {
case V_80 :
case V_81 :
case V_82 :
if ( ( V_67 != V_39 -> V_79 [ V_50 ] . V_83 ) ||
( V_67 == V_39 -> V_79 [ V_50 ] . V_84 ) )
return - V_49 ;
* V_70 = 0 ;
break;
case V_85 :
for ( V_75 = 0 ; V_75 < V_39 -> V_77 ; V_75 ++ ) {
switch ( V_39 -> V_79 [ V_75 ] . V_74 ) {
case V_82 :
if ( V_67 != V_39 -> V_79 [ V_75 ] . V_83 )
return - V_49 ;
break;
default:
break;
}
}
* V_70 = V_67 ;
break;
case V_86 :
case V_87 :
case V_88 :
default:
* V_70 = V_67 ;
break;
}
return 0 ;
}
return - V_49 ;
}
static int F_38 ( struct V_3 * V_4 ,
unsigned V_22 , unsigned long * V_89 ,
unsigned V_90 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
struct V_38 * V_39 ;
unsigned V_24 = 0 , V_91 = 0 , V_50 , V_67 , V_76 ;
T_4 V_92 ;
int V_75 ;
V_76 = F_26 ( V_4 , V_22 , & V_39 ) ;
if ( V_76 )
return V_76 ;
for ( V_75 = 0 ; V_75 < V_90 ; V_75 ++ ) {
for ( V_50 = 0 ; V_50 < V_39 -> V_77 ; V_50 ++ ) {
if ( F_41 ( V_89 [ V_75 ] )
!= V_39 -> V_79 [ V_50 ] . V_74 )
continue;
V_24 = V_22 * ( V_6 -> V_26 / V_27 ) ;
V_67 = V_6 -> V_28 ( V_6 -> V_29 + V_24 ) ;
V_92 = F_42 ( V_89 [ V_75 ] ) ;
switch ( V_39 -> V_79 [ V_50 ] . V_74 ) {
case V_85 :
case V_86 :
case V_87 :
case V_88 :
V_91 = F_43 ( V_39 -> V_79 [ V_50 ] . V_56 ) - 1 ;
V_67 &= ~ V_39 -> V_79 [ V_50 ] . V_56 ;
V_67 |= ( V_92 << V_91 ) & V_39 -> V_79 [ V_50 ] . V_56 ;
break;
case V_78 :
F_35 ( V_4 , V_22 ) ;
break;
case V_80 :
case V_81 :
if ( V_92 )
F_35 ( V_4 , V_22 ) ;
case V_82 :
V_67 &= ~ V_39 -> V_79 [ V_50 ] . V_56 ;
if ( V_92 )
V_67 |= V_39 -> V_79 [ V_50 ] . V_83 ;
else
V_67 |= V_39 -> V_79 [ V_50 ] . V_84 ;
break;
default:
return - V_49 ;
}
V_6 -> V_59 ( V_67 , V_6 -> V_29 + V_24 ) ;
break;
}
if ( V_50 >= V_39 -> V_77 )
return - V_49 ;
}
return 0 ;
}
static int F_44 ( struct V_3 * V_4 ,
unsigned V_10 , unsigned long * V_70 )
{
const unsigned * V_15 ;
unsigned V_16 , V_93 = 0 ;
int V_50 , V_76 ;
V_76 = F_18 ( V_4 , V_10 , & V_15 , & V_16 ) ;
if ( V_76 )
return V_76 ;
for ( V_50 = 0 ; V_50 < V_16 ; V_50 ++ ) {
if ( F_40 ( V_4 , V_15 [ V_50 ] , V_70 ) )
return - V_49 ;
if ( V_50 && ( V_93 != * V_70 ) )
return - V_49 ;
V_93 = * V_70 ;
}
return 0 ;
}
static int F_45 ( struct V_3 * V_4 ,
unsigned V_10 , unsigned long * V_89 ,
unsigned V_90 )
{
const unsigned * V_15 ;
unsigned V_16 ;
int V_50 , V_76 ;
V_76 = F_18 ( V_4 , V_10 , & V_15 , & V_16 ) ;
if ( V_76 )
return V_76 ;
for ( V_50 = 0 ; V_50 < V_16 ; V_50 ++ ) {
if ( F_38 ( V_4 , V_15 [ V_50 ] , V_89 , V_90 ) )
return - V_49 ;
}
return 0 ;
}
static void F_46 ( struct V_3 * V_4 ,
struct V_20 * V_21 , unsigned V_22 )
{
}
static void F_47 ( struct V_3 * V_4 ,
struct V_20 * V_21 , unsigned V_94 )
{
}
static void F_48 ( struct V_3 * V_4 ,
struct V_20 * V_21 ,
unsigned long V_70 )
{
F_49 ( V_4 , V_21 , V_70 ) ;
}
static int F_50 ( struct V_5 * V_6 , unsigned V_24 ,
unsigned V_95 )
{
struct V_96 * V_97 = & V_6 -> V_98 ;
struct V_99 * V_22 ;
int V_50 ;
V_50 = V_6 -> V_15 . V_100 ;
if ( V_50 >= V_6 -> V_101 . V_16 ) {
F_17 ( V_6 -> V_12 , L_5 ,
V_6 -> V_101 . V_16 ) ;
return - V_102 ;
}
if ( V_97 -> V_103 ) {
unsigned V_2 ;
V_2 = V_6 -> V_28 ( V_6 -> V_29 + V_24 ) ;
if ( V_2 & V_97 -> V_103 ) {
F_29 ( V_6 -> V_12 , L_6 ,
( unsigned long ) V_6 -> V_30 -> V_31 + V_24 , V_2 ) ;
V_2 &= ~ V_97 -> V_103 ;
V_6 -> V_59 ( V_2 , V_6 -> V_29 + V_24 ) ;
}
}
V_22 = & V_6 -> V_15 . V_25 [ V_50 ] ;
V_22 -> V_104 = V_50 ;
V_6 -> V_15 . V_100 ++ ;
return V_50 ;
}
static int F_51 ( struct V_5 * V_6 )
{
int V_23 , V_105 , V_50 ;
int V_106 = 0 ;
V_23 = V_6 -> V_26 / V_27 ;
if ( V_6 -> V_58 ) {
V_6 -> V_107 = F_52 ( V_6 -> V_51 ) ;
V_105 = ( V_6 -> V_108 * V_27 ) / V_6 -> V_107 ;
V_106 = V_6 -> V_26 / V_6 -> V_107 ;
} else {
V_105 = V_6 -> V_108 / V_23 ;
}
F_29 ( V_6 -> V_12 , L_7 , V_105 ) ;
V_6 -> V_15 . V_25 = F_53 ( V_6 -> V_12 ,
sizeof( * V_6 -> V_15 . V_25 ) * V_105 ,
V_109 ) ;
if ( ! V_6 -> V_15 . V_25 )
return - V_102 ;
V_6 -> V_101 . V_15 = V_6 -> V_15 . V_25 ;
V_6 -> V_101 . V_16 = V_105 ;
for ( V_50 = 0 ; V_50 < V_6 -> V_101 . V_16 ; V_50 ++ ) {
unsigned V_24 ;
int V_30 ;
int V_110 ;
int V_95 = 0 ;
if ( V_6 -> V_58 ) {
V_110 = ( V_6 -> V_107 * V_50 ) / V_27 ;
V_24 = ( V_110 / V_23 ) * V_23 ;
V_95 = V_50 % V_106 ;
} else {
V_24 = V_50 * V_23 ;
}
V_30 = F_50 ( V_6 , V_24 , V_95 ) ;
if ( V_30 < 0 ) {
F_17 ( V_6 -> V_12 , L_8 , V_30 ) ;
return V_30 ;
}
}
return 0 ;
}
static struct V_38 * F_54 ( struct V_5 * V_6 ,
struct V_111 * V_112 ,
const char * V_14 ,
struct V_53 * V_54 ,
unsigned V_52 ,
const char * * V_42 ,
unsigned V_43 )
{
struct V_38 * V_113 ;
V_113 = F_53 ( V_6 -> V_12 , sizeof( * V_113 ) , V_109 ) ;
if ( ! V_113 )
return NULL ;
V_113 -> V_14 = V_14 ;
V_113 -> V_54 = V_54 ;
V_113 -> V_52 = V_52 ;
V_113 -> V_42 = V_42 ;
V_113 -> V_43 = V_43 ;
F_55 ( & V_6 -> V_114 ) ;
F_56 ( & V_113 -> V_68 , & V_6 -> V_115 ) ;
F_57 ( & V_6 -> V_40 , V_6 -> V_36 , V_113 ) ;
V_6 -> V_36 ++ ;
F_58 ( & V_6 -> V_114 ) ;
return V_113 ;
}
static void F_59 ( struct V_5 * V_6 ,
struct V_38 * V_113 )
{
int V_50 ;
F_55 ( & V_6 -> V_114 ) ;
for ( V_50 = 0 ; V_50 < V_6 -> V_36 ; V_50 ++ ) {
struct V_38 * V_116 ;
V_116 = F_16 ( & V_6 -> V_40 , V_50 ) ;
if ( V_116 == V_113 )
F_60 ( & V_6 -> V_40 , V_50 ) ;
}
F_61 ( & V_113 -> V_68 ) ;
F_58 ( & V_6 -> V_114 ) ;
}
static int F_62 ( struct V_5 * V_6 ,
struct V_111 * V_112 ,
const char * V_14 ,
int * V_18 ,
int V_19 )
{
struct V_9 * V_117 ;
V_117 = F_53 ( V_6 -> V_12 , sizeof( * V_117 ) , V_109 ) ;
if ( ! V_117 )
return - V_102 ;
V_117 -> V_14 = V_14 ;
V_117 -> V_112 = V_112 ;
V_117 -> V_18 = V_18 ;
V_117 -> V_19 = V_19 ;
F_55 ( & V_6 -> V_114 ) ;
F_56 ( & V_117 -> V_68 , & V_6 -> V_118 ) ;
F_57 ( & V_6 -> V_11 , V_6 -> V_7 , V_117 ) ;
V_6 -> V_7 ++ ;
F_58 ( & V_6 -> V_114 ) ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 , unsigned V_24 )
{
unsigned V_119 ;
if ( V_24 >= V_6 -> V_108 ) {
F_17 ( V_6 -> V_12 , L_9 ,
V_24 , V_6 -> V_108 ) ;
return - V_17 ;
}
if ( V_6 -> V_58 )
V_119 = ( V_24 * V_27 ) / V_6 -> V_107 ;
else
V_119 = V_24 / ( V_6 -> V_26 / V_27 ) ;
return V_119 ;
}
static int F_64 ( unsigned V_67 , unsigned V_83 , unsigned V_84 )
{
int V_76 = - V_17 ;
if ( V_67 == V_83 )
V_76 = 1 ;
else if ( V_67 == V_84 )
V_76 = 0 ;
return V_76 ;
}
static void F_65 ( struct V_120 * * V_79 , enum V_73 V_74 ,
unsigned V_121 , unsigned V_83 , unsigned V_84 ,
unsigned V_56 )
{
( * V_79 ) -> V_74 = V_74 ;
( * V_79 ) -> V_2 = V_121 ;
( * V_79 ) -> V_83 = V_83 ;
( * V_79 ) -> V_84 = V_84 ;
( * V_79 ) -> V_56 = V_56 ;
( * V_79 ) ++ ;
}
static void F_66 ( unsigned long * * V_47 , enum V_73 V_74 ,
unsigned V_92 )
{
* * V_47 = F_37 ( V_74 , V_92 ) ;
( * V_47 ) ++ ;
}
static void F_67 ( struct V_5 * V_6 , struct V_111 * V_112 ,
const char * V_14 , enum V_73 V_74 ,
struct V_120 * * V_79 , unsigned long * * V_122 )
{
unsigned V_121 [ 2 ] , V_91 ;
int V_76 ;
V_76 = F_68 ( V_112 , V_14 , V_121 , 2 ) ;
if ( V_76 )
return;
V_121 [ 0 ] &= V_121 [ 1 ] ;
V_91 = F_43 ( V_121 [ 1 ] ) - 1 ;
F_65 ( V_79 , V_74 , V_121 [ 0 ] , 0 , 0 , V_121 [ 1 ] ) ;
F_66 ( V_122 , V_74 , V_121 [ 0 ] >> V_91 ) ;
}
static void F_69 ( struct V_5 * V_6 , struct V_111 * V_112 ,
const char * V_14 , enum V_73 V_74 ,
struct V_120 * * V_79 , unsigned long * * V_122 )
{
unsigned V_121 [ 4 ] ;
int V_76 ;
V_76 = F_68 ( V_112 , V_14 , V_121 , 4 ) ;
if ( V_76 )
return;
if ( ! V_121 [ 3 ] ) {
F_17 ( V_6 -> V_12 , L_10 ) ;
return;
}
V_121 [ 0 ] &= V_121 [ 3 ] ;
V_121 [ 1 ] &= V_121 [ 3 ] ;
V_121 [ 2 ] &= V_121 [ 3 ] ;
V_76 = F_64 ( V_121 [ 0 ] , V_121 [ 1 ] , V_121 [ 2 ] ) ;
if ( V_76 < 0 )
F_29 ( V_6 -> V_12 , L_11 ) ;
F_65 ( V_79 , V_74 , V_121 [ 0 ] , V_121 [ 1 ] , V_121 [ 2 ] , V_121 [ 3 ] ) ;
F_66 ( V_122 , V_74 , V_76 ) ;
}
static int F_70 ( struct V_5 * V_6 , struct V_111 * V_112 ,
struct V_38 * V_39 ,
struct V_33 * * V_34 )
{
struct V_33 * V_123 = * V_34 ;
int V_50 = 0 , V_77 = 0 ;
unsigned long * V_122 = NULL , * V_21 = NULL ;
struct V_120 * V_79 = NULL ;
struct V_124 V_125 [] = {
{ L_12 , V_86 , } ,
{ L_13 , V_87 , } ,
{ L_14 , V_85 , } ,
{ L_15 , V_88 , } ,
} ;
struct V_124 V_126 [] = {
{ L_16 , V_81 , } ,
{ L_17 , V_80 , } ,
{ L_18 ,
V_82 , } ,
} ;
if ( ! V_127 )
return 0 ;
for ( V_50 = 0 ; V_50 < F_36 ( V_125 ) ; V_50 ++ ) {
if ( F_71 ( V_112 , V_125 [ V_50 ] . V_14 , NULL ) )
V_77 ++ ;
}
for ( V_50 = 0 ; V_50 < F_36 ( V_126 ) ; V_50 ++ ) {
if ( F_71 ( V_112 , V_126 [ V_50 ] . V_14 , NULL ) )
V_77 ++ ;
}
if ( ! V_77 )
return 0 ;
V_39 -> V_79 = F_53 ( V_6 -> V_12 ,
sizeof( struct V_120 ) * V_77 ,
V_109 ) ;
if ( ! V_39 -> V_79 )
return - V_102 ;
V_39 -> V_77 = V_77 ;
V_79 = & ( V_39 -> V_79 [ 0 ] ) ;
V_123 ++ ;
V_122 = F_53 ( V_6 -> V_12 , sizeof( unsigned long ) * V_77 ,
V_109 ) ;
if ( ! V_122 )
return - V_102 ;
V_21 = & V_122 [ 0 ] ;
for ( V_50 = 0 ; V_50 < F_36 ( V_125 ) ; V_50 ++ )
F_67 ( V_6 , V_112 , V_125 [ V_50 ] . V_14 , V_125 [ V_50 ] . V_74 ,
& V_79 , & V_21 ) ;
for ( V_50 = 0 ; V_50 < F_36 ( V_126 ) ; V_50 ++ )
F_69 ( V_6 , V_112 , V_126 [ V_50 ] . V_14 , V_126 [ V_50 ] . V_74 ,
& V_79 , & V_21 ) ;
V_123 -> type = V_128 ;
V_123 -> V_67 . V_89 . V_129 = V_112 -> V_14 ;
V_123 -> V_67 . V_89 . V_89 = V_122 ;
V_123 -> V_67 . V_89 . V_90 = V_77 ;
return 0 ;
}
static int F_72 ( struct V_5 * V_6 ,
struct V_111 * V_112 ,
struct V_33 * * V_34 ,
unsigned * V_35 ,
const char * * V_42 )
{
const char * V_14 = L_19 ;
struct V_53 * V_54 ;
int V_130 , * V_15 , V_116 = 0 , V_30 = - V_102 , V_50 ;
struct V_38 * V_113 ;
V_130 = F_73 ( V_112 , V_14 ) ;
if ( V_130 <= 0 ) {
F_17 ( V_6 -> V_12 , L_20 , V_130 ) ;
return - V_17 ;
}
V_54 = F_53 ( V_6 -> V_12 , sizeof( * V_54 ) * V_130 , V_109 ) ;
if ( ! V_54 )
return - V_102 ;
V_15 = F_53 ( V_6 -> V_12 , sizeof( * V_15 ) * V_130 , V_109 ) ;
if ( ! V_15 )
goto V_131;
for ( V_50 = 0 ; V_50 < V_130 ; V_50 ++ ) {
struct V_132 V_133 ;
unsigned int V_24 ;
int V_22 ;
V_30 = F_74 ( V_112 , V_14 , V_50 , & V_133 ) ;
if ( V_30 )
return V_30 ;
if ( V_133 . V_134 < 2 ) {
F_17 ( V_6 -> V_12 , L_21 ,
V_133 . V_134 ) ;
break;
}
V_24 = V_133 . args [ 0 ] ;
V_54 [ V_116 ] . V_1 = V_6 -> V_29 + V_24 ;
V_54 [ V_116 ] . V_2 = V_133 . args [ 1 ] ;
F_29 ( V_6 -> V_12 , L_22 ,
V_133 . V_112 -> V_14 , V_24 , V_133 . args [ 1 ] ) ;
V_22 = F_63 ( V_6 , V_24 ) ;
if ( V_22 < 0 ) {
F_17 ( V_6 -> V_12 ,
L_23 ,
V_112 -> V_14 , V_24 ) ;
break;
}
V_15 [ V_116 ++ ] = V_22 ;
}
V_42 [ 0 ] = V_112 -> V_14 ;
V_113 = F_54 ( V_6 , V_112 , V_112 -> V_14 , V_54 , V_116 , V_42 , 1 ) ;
if ( ! V_113 ) {
V_30 = - V_102 ;
goto V_135;
}
V_30 = F_62 ( V_6 , V_112 , V_112 -> V_14 , V_15 , V_116 ) ;
if ( V_30 < 0 )
goto V_136;
( * V_34 ) -> type = V_137 ;
( * V_34 ) -> V_67 . V_138 . V_10 = V_112 -> V_14 ;
( * V_34 ) -> V_67 . V_138 . V_113 = V_112 -> V_14 ;
if ( V_127 ) {
V_30 = F_70 ( V_6 , V_112 , V_113 , V_34 ) ;
if ( V_30 )
goto V_139;
* V_35 = 2 ;
} else {
* V_35 = 1 ;
}
return 0 ;
V_139:
F_75 ( V_6 ) ;
* V_35 = 1 ;
V_136:
F_59 ( V_6 , V_113 ) ;
V_135:
F_22 ( V_6 -> V_12 , V_15 ) ;
V_131:
F_22 ( V_6 -> V_12 , V_54 ) ;
return V_30 ;
}
static int F_76 ( struct V_5 * V_6 ,
struct V_111 * V_112 ,
struct V_33 * * V_34 ,
unsigned * V_35 ,
const char * * V_42 )
{
const char * V_14 = L_24 ;
struct V_53 * V_54 ;
int V_130 , * V_15 , V_116 = 0 , V_30 = - V_102 , V_50 ;
int V_140 ;
struct V_38 * V_113 ;
V_130 = F_73 ( V_112 , V_14 ) ;
if ( V_130 <= 0 ) {
F_17 ( V_6 -> V_12 , L_25 , V_130 ) ;
return - V_17 ;
}
V_140 = V_6 -> V_26 / V_6 -> V_107 ;
V_54 = F_53 ( V_6 -> V_12 , sizeof( * V_54 ) * V_130 * V_140 ,
V_109 ) ;
if ( ! V_54 )
return - V_102 ;
V_15 = F_53 ( V_6 -> V_12 , sizeof( * V_15 ) * V_130 * V_140 ,
V_109 ) ;
if ( ! V_15 )
goto V_131;
for ( V_50 = 0 ; V_50 < V_130 ; V_50 ++ ) {
struct V_132 V_133 ;
unsigned V_24 , V_2 ;
unsigned V_56 , V_141 , V_142 , V_143 , V_144 ;
unsigned V_145 ;
int V_22 ;
V_30 = F_74 ( V_112 , V_14 , V_50 , & V_133 ) ;
if ( V_30 )
return V_30 ;
if ( V_133 . V_134 < 3 ) {
F_17 ( V_6 -> V_12 , L_21 ,
V_133 . V_134 ) ;
break;
}
V_24 = V_133 . args [ 0 ] ;
V_2 = V_133 . args [ 1 ] ;
V_56 = V_133 . args [ 2 ] ;
F_29 ( V_6 -> V_12 , L_26 ,
V_133 . V_112 -> V_14 , V_24 , V_2 , V_56 ) ;
while ( V_56 ) {
V_141 = F_77 ( V_56 ) ;
V_145 = V_141 / V_6 -> V_107 ;
V_143 = ( ( V_6 -> V_51 ) << V_141 ) ;
V_142 = V_2 & V_143 ;
V_144 = V_56 & V_143 ;
if ( ( V_56 & V_143 ) == 0 ) {
F_17 ( V_6 -> V_12 ,
L_27 ,
V_112 -> V_14 , V_24 ) ;
break;
}
V_56 &= ~ V_143 ;
if ( V_144 != V_143 ) {
F_78 ( V_6 -> V_12 ,
L_28 ,
V_144 , V_112 -> V_14 , V_24 ) ;
continue;
}
V_54 [ V_116 ] . V_56 = V_144 ;
V_54 [ V_116 ] . V_1 = V_6 -> V_29 + V_24 ;
V_54 [ V_116 ] . V_2 = V_142 ;
V_22 = F_63 ( V_6 , V_24 ) ;
if ( V_22 < 0 ) {
F_17 ( V_6 -> V_12 ,
L_23 ,
V_112 -> V_14 , V_24 ) ;
break;
}
V_15 [ V_116 ++ ] = V_22 + V_145 ;
}
}
V_42 [ 0 ] = V_112 -> V_14 ;
V_113 = F_54 ( V_6 , V_112 , V_112 -> V_14 , V_54 , V_116 , V_42 , 1 ) ;
if ( ! V_113 ) {
V_30 = - V_102 ;
goto V_135;
}
V_30 = F_62 ( V_6 , V_112 , V_112 -> V_14 , V_15 , V_116 ) ;
if ( V_30 < 0 )
goto V_136;
( * V_34 ) -> type = V_137 ;
( * V_34 ) -> V_67 . V_138 . V_10 = V_112 -> V_14 ;
( * V_34 ) -> V_67 . V_138 . V_113 = V_112 -> V_14 ;
if ( V_127 ) {
F_17 ( V_6 -> V_12 , L_29 ) ;
goto V_139;
}
* V_35 = 1 ;
return 0 ;
V_139:
F_75 ( V_6 ) ;
* V_35 = 1 ;
V_136:
F_59 ( V_6 , V_113 ) ;
V_135:
F_22 ( V_6 -> V_12 , V_15 ) ;
V_131:
F_22 ( V_6 -> V_12 , V_54 ) ;
return V_30 ;
}
static int F_79 ( struct V_3 * V_4 ,
struct V_111 * V_146 ,
struct V_33 * * V_34 , unsigned * V_35 )
{
struct V_5 * V_6 ;
const char * * V_42 ;
int V_76 ;
V_6 = F_14 ( V_4 ) ;
* V_34 = F_53 ( V_6 -> V_12 , sizeof( * * V_34 ) * 2 , V_109 ) ;
if ( ! * V_34 )
return - V_102 ;
* V_35 = 0 ;
V_42 = F_53 ( V_6 -> V_12 , sizeof( * V_42 ) , V_109 ) ;
if ( ! V_42 ) {
V_76 = - V_102 ;
goto V_147;
}
if ( V_6 -> V_58 ) {
V_76 = F_76 ( V_6 , V_146 , V_34 ,
V_35 , V_42 ) ;
if ( V_76 < 0 ) {
F_17 ( V_6 -> V_12 , L_30 ,
V_146 -> V_14 ) ;
goto V_148;
}
} else {
V_76 = F_72 ( V_6 , V_146 , V_34 ,
V_35 , V_42 ) ;
if ( V_76 < 0 ) {
F_17 ( V_6 -> V_12 , L_30 ,
V_146 -> V_14 ) ;
goto V_148;
}
}
return 0 ;
V_148:
F_22 ( V_6 -> V_12 , V_42 ) ;
V_147:
F_22 ( V_6 -> V_12 , * V_34 ) ;
return V_76 ;
}
static void F_80 ( struct V_5 * V_6 )
{
struct V_64 * V_65 , * V_66 ;
int V_50 ;
F_55 ( & V_6 -> V_114 ) ;
for ( V_50 = 0 ; V_50 < V_6 -> V_36 ; V_50 ++ ) {
struct V_38 * V_39 ;
V_39 = F_16 ( & V_6 -> V_40 , V_50 ) ;
if ( ! V_39 )
continue;
F_60 ( & V_6 -> V_40 , V_50 ) ;
}
F_33 (pos, tmp, &pcs->functions) {
struct V_38 * V_113 ;
V_113 = F_34 ( V_65 , struct V_38 , V_68 ) ;
F_61 ( & V_113 -> V_68 ) ;
}
F_58 ( & V_6 -> V_114 ) ;
}
static void F_75 ( struct V_5 * V_6 )
{
struct V_64 * V_65 , * V_66 ;
int V_50 ;
F_55 ( & V_6 -> V_114 ) ;
for ( V_50 = 0 ; V_50 < V_6 -> V_7 ; V_50 ++ ) {
struct V_9 * V_117 ;
V_117 = F_16 ( & V_6 -> V_11 , V_50 ) ;
if ( ! V_117 )
continue;
F_60 ( & V_6 -> V_11 , V_50 ) ;
}
F_33 (pos, tmp, &pcs->pingroups) {
struct V_9 * V_117 ;
V_117 = F_34 ( V_65 , struct V_9 , V_68 ) ;
F_61 ( & V_117 -> V_68 ) ;
}
F_58 ( & V_6 -> V_114 ) ;
}
static void F_81 ( struct V_5 * V_6 )
{
struct V_96 * V_97 = & V_6 -> V_98 ;
if ( V_97 -> V_149 < 0 )
return;
if ( V_6 -> V_150 )
F_82 ( V_6 -> V_150 ) ;
if ( V_151 )
F_83 ( V_97 -> V_149 , V_97 ) ;
else
F_84 ( V_97 -> V_149 , NULL ) ;
}
static void F_85 ( struct V_5 * V_6 )
{
F_81 ( V_6 ) ;
F_86 ( V_6 -> V_152 ) ;
F_80 ( V_6 ) ;
F_75 ( V_6 ) ;
#if F_87 ( V_153 )
if ( V_6 -> V_154 )
F_88 ( V_6 -> V_112 , V_6 -> V_154 ) ;
#endif
}
static int F_89 ( struct V_111 * V_68 , struct V_5 * V_6 )
{
const char * V_155 = L_31 ;
const char * V_156 = L_32 ;
struct V_132 V_157 ;
struct V_62 * V_61 ;
int V_76 , V_50 ;
for ( V_50 = 0 ; ; V_50 ++ ) {
V_76 = F_90 ( V_68 , V_155 , V_156 ,
V_50 , & V_157 ) ;
if ( V_76 ) {
V_76 = 0 ;
break;
}
V_61 = F_53 ( V_6 -> V_12 , sizeof( * V_61 ) , V_109 ) ;
if ( ! V_61 ) {
V_76 = - V_102 ;
break;
}
V_61 -> V_24 = V_157 . args [ 0 ] ;
V_61 -> V_16 = V_157 . args [ 1 ] ;
V_61 -> V_69 = V_157 . args [ 2 ] ;
F_55 ( & V_6 -> V_114 ) ;
F_56 ( & V_61 -> V_68 , & V_6 -> V_158 ) ;
F_58 ( & V_6 -> V_114 ) ;
}
return V_76 ;
}
static inline void F_91 ( struct V_96 * V_97 ,
int V_149 , const bool V_83 )
{
struct V_5 * V_6 ;
struct V_64 * V_65 ;
unsigned V_56 ;
V_6 = F_92 ( V_97 , struct V_5 , V_98 ) ;
F_93 (pos, &pcs->irqs) {
struct V_159 * V_160 ;
unsigned V_161 ;
V_160 = F_34 ( V_65 , struct V_159 , V_68 ) ;
if ( V_149 != V_160 -> V_149 )
continue;
V_161 = V_97 -> V_103 ;
F_94 ( & V_6 -> V_57 ) ;
V_56 = V_6 -> V_28 ( V_160 -> V_1 ) ;
if ( V_83 )
V_56 |= V_161 ;
else
V_56 &= ~ V_161 ;
V_6 -> V_59 ( V_56 , V_160 -> V_1 ) ;
V_56 = V_6 -> V_28 ( V_160 -> V_1 ) ;
F_95 ( & V_6 -> V_57 ) ;
}
if ( V_97 -> V_162 )
V_97 -> V_162 () ;
}
static void F_96 ( struct V_163 * V_164 )
{
struct V_96 * V_97 = F_97 ( V_164 ) ;
F_91 ( V_97 , V_164 -> V_149 , false ) ;
}
static void F_98 ( struct V_163 * V_164 )
{
struct V_96 * V_97 = F_97 ( V_164 ) ;
F_91 ( V_97 , V_164 -> V_149 , true ) ;
}
static int F_99 ( struct V_163 * V_164 , unsigned int V_165 )
{
if ( V_165 )
F_98 ( V_164 ) ;
else
F_96 ( V_164 ) ;
return 0 ;
}
static int F_100 ( struct V_96 * V_97 )
{
struct V_5 * V_6 ;
struct V_64 * V_65 ;
int V_166 = 0 ;
V_6 = F_92 ( V_97 , struct V_5 , V_98 ) ;
F_93 (pos, &pcs->irqs) {
struct V_159 * V_160 ;
unsigned V_56 ;
V_160 = F_34 ( V_65 , struct V_159 , V_68 ) ;
F_94 ( & V_6 -> V_57 ) ;
V_56 = V_6 -> V_28 ( V_160 -> V_1 ) ;
F_95 ( & V_6 -> V_57 ) ;
if ( V_56 & V_97 -> V_167 ) {
F_101 ( F_102 ( V_6 -> V_150 ,
V_160 -> V_168 ) ) ;
V_166 ++ ;
}
}
return V_166 ;
}
static T_5 F_103 ( int V_149 , void * V_164 )
{
struct V_96 * V_97 = V_164 ;
return F_100 ( V_97 ) ? V_169 : V_170 ;
}
static void F_104 ( struct V_171 * V_101 )
{
struct V_96 * V_97 = F_105 ( V_101 ) ;
struct V_172 * V_173 ;
V_173 = F_106 ( V_101 ) ;
F_107 ( V_173 , V_101 ) ;
F_100 ( V_97 ) ;
F_108 ( V_173 , V_101 ) ;
return;
}
static int F_109 ( struct V_174 * V_164 , unsigned int V_149 ,
T_6 V_168 )
{
struct V_96 * V_97 = V_164 -> V_175 ;
struct V_5 * V_6 ;
struct V_159 * V_160 ;
V_6 = F_92 ( V_97 , struct V_5 , V_98 ) ;
V_160 = F_53 ( V_6 -> V_12 , sizeof( * V_160 ) , V_109 ) ;
if ( ! V_160 )
return - V_102 ;
V_160 -> V_1 = V_6 -> V_29 + V_168 ;
V_160 -> V_168 = V_168 ;
V_160 -> V_149 = V_149 ;
F_55 ( & V_6 -> V_114 ) ;
F_56 ( & V_160 -> V_68 , & V_6 -> V_176 ) ;
F_58 ( & V_6 -> V_114 ) ;
F_110 ( V_149 , V_97 ) ;
F_111 ( V_149 , & V_6 -> V_173 ,
V_177 ) ;
F_112 ( V_149 , & V_178 ) ;
F_113 ( V_149 ) ;
return 0 ;
}
static int F_114 ( struct V_5 * V_6 ,
struct V_111 * V_112 )
{
struct V_96 * V_97 = & V_6 -> V_98 ;
const char * V_14 = L_33 ;
int V_179 ;
if ( ! V_97 -> V_103 ||
! V_97 -> V_167 ) {
V_97 -> V_149 = - 1 ;
return - V_17 ;
}
F_115 ( & V_6 -> V_176 ) ;
V_6 -> V_173 . V_14 = V_14 ;
V_6 -> V_173 . V_180 = F_96 ;
V_6 -> V_173 . V_181 = F_96 ;
V_6 -> V_173 . V_182 = F_98 ;
V_6 -> V_173 . V_183 = F_99 ;
if ( V_151 ) {
int V_30 ;
V_30 = F_116 ( V_97 -> V_149 , F_103 ,
V_184 | V_185 |
V_186 ,
V_14 , V_97 ) ;
if ( V_30 ) {
V_97 -> V_149 = - 1 ;
return V_30 ;
}
} else {
F_117 ( V_97 -> V_149 ,
F_104 ,
V_97 ) ;
}
V_179 = V_6 -> V_108 ;
V_6 -> V_150 = F_118 ( V_112 , V_179 , 0 ,
& V_187 ,
V_97 ) ;
if ( ! V_6 -> V_150 ) {
F_84 ( V_97 -> V_149 , NULL ) ;
return - V_17 ;
}
return 0 ;
}
static int F_119 ( struct V_188 * V_189 ,
T_7 V_165 )
{
struct V_5 * V_6 ;
V_6 = F_120 ( V_189 ) ;
if ( ! V_6 )
return - V_17 ;
return F_121 ( V_6 -> V_152 ) ;
}
static int F_122 ( struct V_188 * V_189 )
{
struct V_5 * V_6 ;
V_6 = F_120 ( V_189 ) ;
if ( ! V_6 )
return - V_17 ;
return F_123 ( V_6 -> V_152 ) ;
}
static int F_124 ( struct V_5 * V_6 ,
struct V_111 * V_112 ,
int V_190 )
{
struct V_191 * V_192 ;
const char * V_14 = L_34 ;
int error ;
T_8 V_2 ;
error = F_125 ( V_112 , V_14 , & V_2 ) ;
if ( ! error )
return 0 ;
F_78 ( V_6 -> V_12 , L_35 ,
V_14 , V_190 ) ;
V_192 = F_53 ( V_6 -> V_12 , sizeof( * V_192 ) , V_109 ) ;
if ( ! V_192 )
return - V_102 ;
V_192 -> V_193 = sizeof( V_194 ) ;
V_192 -> V_121 = F_53 ( V_6 -> V_12 , sizeof( V_194 ) , V_109 ) ;
if ( ! V_192 -> V_121 )
return - V_102 ;
* ( V_194 * ) V_192 -> V_121 = F_126 ( V_190 ) ;
V_192 -> V_14 = F_127 ( V_6 -> V_12 , V_14 , V_109 ) ;
if ( ! V_192 -> V_14 )
return - V_102 ;
V_6 -> V_154 = V_192 ;
#if F_87 ( V_153 )
error = F_128 ( V_112 , V_6 -> V_154 ) ;
#endif
return error ;
}
static int F_129 ( struct V_188 * V_189 )
{
struct V_111 * V_112 = V_189 -> V_12 . V_195 ;
const struct V_196 * V_197 ;
struct V_198 * V_199 ;
struct V_200 * V_30 ;
struct V_5 * V_6 ;
const struct V_96 * V_201 ;
int V_76 ;
V_197 = F_130 ( V_202 , & V_189 -> V_12 ) ;
if ( ! V_197 )
return - V_17 ;
V_6 = F_53 ( & V_189 -> V_12 , sizeof( * V_6 ) , V_109 ) ;
if ( ! V_6 ) {
F_17 ( & V_189 -> V_12 , L_36 ) ;
return - V_102 ;
}
V_6 -> V_12 = & V_189 -> V_12 ;
V_6 -> V_112 = V_112 ;
F_131 ( & V_6 -> V_57 ) ;
F_132 ( & V_6 -> V_114 ) ;
F_115 ( & V_6 -> V_118 ) ;
F_115 ( & V_6 -> V_115 ) ;
F_115 ( & V_6 -> V_158 ) ;
V_201 = V_197 -> V_67 ;
V_6 -> V_55 = V_201 -> V_55 ;
memcpy ( & V_6 -> V_98 , V_201 , sizeof( * V_201 ) ) ;
V_76 = F_125 ( V_112 , L_37 ,
& V_6 -> V_26 ) ;
if ( V_76 ) {
F_17 ( V_6 -> V_12 , L_38 ) ;
return V_76 ;
}
V_76 = F_125 ( V_112 , L_39 ,
& V_6 -> V_51 ) ;
if ( ! V_76 ) {
V_6 -> V_203 = F_77 ( V_6 -> V_51 ) ;
V_6 -> V_204 = V_6 -> V_51 >> V_6 -> V_203 ;
} else {
V_6 -> V_51 = 0 ;
V_6 -> V_203 = 0 ;
V_6 -> V_204 = 0 ;
}
V_76 = F_125 ( V_112 , L_40 ,
& V_6 -> V_205 ) ;
if ( V_76 )
V_6 -> V_205 = V_206 ;
V_6 -> V_58 = F_133 ( V_112 ,
L_41 ) ;
V_76 = F_124 ( V_6 , V_112 ,
V_6 -> V_58 ? 2 : 1 ) ;
if ( V_76 ) {
F_17 ( & V_189 -> V_12 , L_42 ) ;
return V_76 ;
}
V_30 = F_134 ( V_189 , V_207 , 0 ) ;
if ( ! V_30 ) {
F_17 ( V_6 -> V_12 , L_43 ) ;
return - V_208 ;
}
V_6 -> V_30 = F_135 ( V_6 -> V_12 , V_30 -> V_31 ,
F_136 ( V_30 ) , V_32 ) ;
if ( ! V_6 -> V_30 ) {
F_17 ( V_6 -> V_12 , L_44 ) ;
return - V_209 ;
}
V_6 -> V_108 = F_136 ( V_6 -> V_30 ) ;
V_6 -> V_29 = F_137 ( V_6 -> V_12 , V_6 -> V_30 -> V_31 , V_6 -> V_108 ) ;
if ( ! V_6 -> V_29 ) {
F_17 ( V_6 -> V_12 , L_45 ) ;
return - V_208 ;
}
F_138 ( & V_6 -> V_11 , V_109 ) ;
F_138 ( & V_6 -> V_40 , V_109 ) ;
F_139 ( V_189 , V_6 ) ;
switch ( V_6 -> V_26 ) {
case 8 :
V_6 -> V_28 = F_1 ;
V_6 -> V_59 = F_7 ;
break;
case 16 :
V_6 -> V_28 = F_3 ;
V_6 -> V_59 = F_9 ;
break;
case 32 :
V_6 -> V_28 = F_5 ;
V_6 -> V_59 = F_11 ;
break;
default:
break;
}
V_6 -> V_101 . V_14 = V_32 ;
V_6 -> V_101 . V_210 = & V_211 ;
V_6 -> V_101 . V_212 = & V_213 ;
if ( V_127 )
V_6 -> V_101 . V_214 = & V_215 ;
V_6 -> V_101 . V_216 = V_217 ;
V_76 = F_51 ( V_6 ) ;
if ( V_76 < 0 )
goto free;
V_6 -> V_152 = F_140 ( & V_6 -> V_101 , V_6 -> V_12 , V_6 ) ;
if ( F_141 ( V_6 -> V_152 ) ) {
F_17 ( V_6 -> V_12 , L_46 ) ;
V_76 = F_142 ( V_6 -> V_152 ) ;
goto free;
}
V_76 = F_89 ( V_112 , V_6 ) ;
if ( V_76 < 0 )
goto free;
V_6 -> V_98 . V_149 = F_143 ( V_112 , 0 ) ;
if ( V_6 -> V_98 . V_149 )
V_6 -> V_55 |= V_218 ;
V_199 = F_144 ( & V_189 -> V_12 ) ;
if ( V_199 ) {
if ( V_199 -> V_162 )
V_6 -> V_98 . V_162 = V_199 -> V_162 ;
if ( V_199 -> V_149 ) {
V_6 -> V_98 . V_149 = V_199 -> V_149 ;
V_6 -> V_55 |= V_218 ;
}
}
if ( V_219 ) {
V_76 = F_114 ( V_6 , V_112 ) ;
if ( V_76 < 0 )
F_78 ( V_6 -> V_12 , L_47 ) ;
}
F_145 ( V_6 -> V_12 , L_48 ,
V_6 -> V_101 . V_16 , V_6 -> V_29 , V_6 -> V_108 ) ;
return 0 ;
free:
F_85 ( V_6 ) ;
return V_76 ;
}
static int F_146 ( struct V_188 * V_189 )
{
struct V_5 * V_6 = F_120 ( V_189 ) ;
if ( ! V_6 )
return 0 ;
F_85 ( V_6 ) ;
return 0 ;
}
