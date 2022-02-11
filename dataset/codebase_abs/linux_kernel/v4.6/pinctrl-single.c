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
unsigned long V_51 ;
unsigned V_2 , V_52 ;
V_50 = & V_35 -> V_50 [ V_46 ] ;
F_30 ( & V_6 -> V_53 , V_51 ) ;
V_2 = V_6 -> V_26 ( V_50 -> V_1 ) ;
if ( V_6 -> V_54 )
V_52 = V_50 -> V_52 ;
else
V_52 = V_6 -> V_47 ;
V_2 &= ~ V_52 ;
V_2 |= ( V_50 -> V_2 & V_52 ) ;
V_6 -> V_55 ( V_2 , V_50 -> V_1 ) ;
F_31 ( & V_6 -> V_53 , V_51 ) ;
}
return 0 ;
}
static int F_32 ( struct V_3 * V_4 ,
struct V_56 * V_57 , unsigned V_22 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
struct V_58 * V_59 = NULL ;
struct V_60 * V_61 , * V_62 ;
int V_23 = 0 ;
unsigned V_63 ;
if ( ! V_6 -> V_47 )
return - V_45 ;
F_33 (pos, tmp, &pcs->gpiofuncs) {
V_59 = F_34 ( V_61 , struct V_58 , V_64 ) ;
if ( V_22 >= V_59 -> V_65 + V_59 -> V_16
|| V_22 < V_59 -> V_65 )
continue;
V_23 = V_6 -> V_24 / V_25 ;
V_63 = V_6 -> V_26 ( V_6 -> V_27 + V_22 * V_23 ) & ~ V_6 -> V_47 ;
V_63 |= V_59 -> V_66 ;
V_6 -> V_55 ( V_63 , V_6 -> V_27 + V_22 * V_23 ) ;
break;
}
return 0 ;
}
static void F_35 ( struct V_3 * V_4 , unsigned V_22 )
{
unsigned long V_67 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_36 ( V_68 ) ; V_46 ++ ) {
V_67 = F_37 ( V_68 [ V_46 ] , 0 ) ;
F_38 ( V_4 , V_22 , & V_67 , 1 ) ;
}
}
static bool F_39 ( struct V_3 * V_4 , unsigned V_22 )
{
unsigned long V_67 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_36 ( V_68 ) ; V_46 ++ ) {
V_67 = F_37 ( V_68 [ V_46 ] , 0 ) ;
if ( ! F_40 ( V_4 , V_22 , & V_67 ) )
goto V_69;
}
return true ;
V_69:
return false ;
}
static int F_40 ( struct V_3 * V_4 ,
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
V_71 = F_41 ( * V_67 ) ;
if ( V_71 == V_75 ) {
if ( F_39 ( V_4 , V_22 ) ) {
* V_67 = 0 ;
return 0 ;
} else {
return - V_45 ;
}
} else if ( V_71 != V_35 -> V_76 [ V_46 ] . V_71 ) {
continue;
}
V_65 = V_22 * ( V_6 -> V_24 / V_25 ) ;
V_63 = V_6 -> V_26 ( V_6 -> V_27 + V_65 ) & V_35 -> V_76 [ V_46 ] . V_52 ;
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
case V_85 :
default:
* V_67 = V_63 ;
break;
}
return 0 ;
}
return - V_45 ;
}
static int F_38 ( struct V_3 * V_4 ,
unsigned V_22 , unsigned long * V_86 ,
unsigned V_87 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
struct V_34 * V_35 ;
unsigned V_65 = 0 , V_88 = 0 , V_46 , V_63 , V_73 ;
T_3 V_89 ;
int V_72 ;
V_73 = F_26 ( V_4 , V_22 , & V_35 ) ;
if ( V_73 )
return V_73 ;
for ( V_72 = 0 ; V_72 < V_87 ; V_72 ++ ) {
for ( V_46 = 0 ; V_46 < V_35 -> V_74 ; V_46 ++ ) {
if ( F_41 ( V_86 [ V_72 ] )
!= V_35 -> V_76 [ V_46 ] . V_71 )
continue;
V_65 = V_22 * ( V_6 -> V_24 / V_25 ) ;
V_63 = V_6 -> V_26 ( V_6 -> V_27 + V_65 ) ;
V_89 = F_42 ( V_86 [ V_72 ] ) ;
switch ( V_35 -> V_76 [ V_46 ] . V_71 ) {
case V_82 :
case V_83 :
case V_84 :
case V_85 :
V_88 = F_43 ( V_35 -> V_76 [ V_46 ] . V_52 ) - 1 ;
V_63 &= ~ V_35 -> V_76 [ V_46 ] . V_52 ;
V_63 |= ( V_89 << V_88 ) & V_35 -> V_76 [ V_46 ] . V_52 ;
break;
case V_75 :
F_35 ( V_4 , V_22 ) ;
break;
case V_77 :
case V_78 :
if ( V_89 )
F_35 ( V_4 , V_22 ) ;
case V_79 :
V_63 &= ~ V_35 -> V_76 [ V_46 ] . V_52 ;
if ( V_89 )
V_63 |= V_35 -> V_76 [ V_46 ] . V_80 ;
else
V_63 |= V_35 -> V_76 [ V_46 ] . V_81 ;
break;
default:
return - V_45 ;
}
V_6 -> V_55 ( V_63 , V_6 -> V_27 + V_65 ) ;
break;
}
if ( V_46 >= V_35 -> V_74 )
return - V_45 ;
}
return 0 ;
}
static int F_44 ( struct V_3 * V_4 ,
unsigned V_10 , unsigned long * V_67 )
{
const unsigned * V_15 ;
unsigned V_16 , V_90 = 0 ;
int V_46 , V_73 ;
V_73 = F_18 ( V_4 , V_10 , & V_15 , & V_16 ) ;
if ( V_73 )
return V_73 ;
for ( V_46 = 0 ; V_46 < V_16 ; V_46 ++ ) {
if ( F_40 ( V_4 , V_15 [ V_46 ] , V_67 ) )
return - V_45 ;
if ( V_46 && ( V_90 != * V_67 ) )
return - V_45 ;
V_90 = * V_67 ;
}
return 0 ;
}
static int F_45 ( struct V_3 * V_4 ,
unsigned V_10 , unsigned long * V_86 ,
unsigned V_87 )
{
const unsigned * V_15 ;
unsigned V_16 ;
int V_46 , V_73 ;
V_73 = F_18 ( V_4 , V_10 , & V_15 , & V_16 ) ;
if ( V_73 )
return V_73 ;
for ( V_46 = 0 ; V_46 < V_16 ; V_46 ++ ) {
if ( F_38 ( V_4 , V_15 [ V_46 ] , V_86 , V_87 ) )
return - V_45 ;
}
return 0 ;
}
static void F_46 ( struct V_3 * V_4 ,
struct V_20 * V_21 , unsigned V_22 )
{
}
static void F_47 ( struct V_3 * V_4 ,
struct V_20 * V_21 , unsigned V_91 )
{
}
static void F_48 ( struct V_3 * V_4 ,
struct V_20 * V_21 ,
unsigned long V_67 )
{
F_49 ( V_4 , V_21 , V_67 ) ;
}
static int F_50 ( struct V_5 * V_6 , unsigned V_65 ,
unsigned V_92 )
{
struct V_93 * V_94 = & V_6 -> V_95 ;
struct V_96 * V_22 ;
struct V_97 * V_98 ;
int V_46 ;
V_46 = V_6 -> V_15 . V_99 ;
if ( V_46 >= V_6 -> V_100 . V_16 ) {
F_17 ( V_6 -> V_12 , L_5 ,
V_6 -> V_100 . V_16 ) ;
return - V_101 ;
}
if ( V_94 -> V_102 ) {
unsigned V_2 ;
V_2 = V_6 -> V_26 ( V_6 -> V_27 + V_65 ) ;
if ( V_2 & V_94 -> V_102 ) {
F_29 ( V_6 -> V_12 , L_6 ,
( unsigned long ) V_6 -> V_103 -> V_104 + V_65 , V_2 ) ;
V_2 &= ~ V_94 -> V_102 ;
V_6 -> V_55 ( V_2 , V_6 -> V_27 + V_65 ) ;
}
}
V_22 = & V_6 -> V_15 . V_105 [ V_46 ] ;
V_98 = & V_6 -> V_106 [ V_46 ] ;
sprintf ( V_98 -> V_14 , L_7 ,
( unsigned long ) V_6 -> V_103 -> V_104 + V_65 , V_92 ) ;
V_22 -> V_14 = V_98 -> V_14 ;
V_22 -> V_107 = V_46 ;
V_6 -> V_15 . V_99 ++ ;
return V_46 ;
}
static int F_51 ( struct V_5 * V_6 )
{
int V_23 , V_108 , V_46 ;
int V_109 = 0 ;
V_23 = V_6 -> V_24 / V_25 ;
if ( V_6 -> V_54 ) {
V_6 -> V_110 = F_52 ( V_6 -> V_47 ) ;
V_108 = ( V_6 -> V_111 * V_25 ) / V_6 -> V_110 ;
V_109 = V_6 -> V_24 / V_6 -> V_110 ;
} else {
V_108 = V_6 -> V_111 / V_23 ;
}
F_29 ( V_6 -> V_12 , L_8 , V_108 ) ;
V_6 -> V_15 . V_105 = F_53 ( V_6 -> V_12 ,
sizeof( * V_6 -> V_15 . V_105 ) * V_108 ,
V_112 ) ;
if ( ! V_6 -> V_15 . V_105 )
return - V_101 ;
V_6 -> V_106 = F_53 ( V_6 -> V_12 ,
sizeof( struct V_97 ) * V_108 ,
V_112 ) ;
if ( ! V_6 -> V_106 )
return - V_101 ;
V_6 -> V_100 . V_15 = V_6 -> V_15 . V_105 ;
V_6 -> V_100 . V_16 = V_108 ;
for ( V_46 = 0 ; V_46 < V_6 -> V_100 . V_16 ; V_46 ++ ) {
unsigned V_65 ;
int V_103 ;
int V_113 ;
int V_92 = 0 ;
if ( V_6 -> V_54 ) {
V_113 = ( V_6 -> V_110 * V_46 ) / V_25 ;
V_65 = ( V_113 / V_23 ) * V_23 ;
V_92 = V_46 % V_109 ;
} else {
V_65 = V_46 * V_23 ;
}
V_103 = F_50 ( V_6 , V_65 , V_92 ) ;
if ( V_103 < 0 ) {
F_17 ( V_6 -> V_12 , L_9 , V_103 ) ;
return V_103 ;
}
}
return 0 ;
}
static struct V_34 * F_54 ( struct V_5 * V_6 ,
struct V_114 * V_115 ,
const char * V_14 ,
struct V_49 * V_50 ,
unsigned V_48 ,
const char * * V_38 ,
unsigned V_39 )
{
struct V_34 * V_116 ;
V_116 = F_53 ( V_6 -> V_12 , sizeof( * V_116 ) , V_112 ) ;
if ( ! V_116 )
return NULL ;
V_116 -> V_14 = V_14 ;
V_116 -> V_50 = V_50 ;
V_116 -> V_48 = V_48 ;
V_116 -> V_38 = V_38 ;
V_116 -> V_39 = V_39 ;
F_55 ( & V_6 -> V_117 ) ;
F_56 ( & V_116 -> V_64 , & V_6 -> V_118 ) ;
F_57 ( & V_6 -> V_36 , V_6 -> V_32 , V_116 ) ;
V_6 -> V_32 ++ ;
F_58 ( & V_6 -> V_117 ) ;
return V_116 ;
}
static void F_59 ( struct V_5 * V_6 ,
struct V_34 * V_116 )
{
int V_46 ;
F_55 ( & V_6 -> V_117 ) ;
for ( V_46 = 0 ; V_46 < V_6 -> V_32 ; V_46 ++ ) {
struct V_34 * V_119 ;
V_119 = F_16 ( & V_6 -> V_36 , V_46 ) ;
if ( V_119 == V_116 )
F_60 ( & V_6 -> V_36 , V_46 ) ;
}
F_61 ( & V_116 -> V_64 ) ;
F_58 ( & V_6 -> V_117 ) ;
}
static int F_62 ( struct V_5 * V_6 ,
struct V_114 * V_115 ,
const char * V_14 ,
int * V_18 ,
int V_19 )
{
struct V_9 * V_120 ;
V_120 = F_53 ( V_6 -> V_12 , sizeof( * V_120 ) , V_112 ) ;
if ( ! V_120 )
return - V_101 ;
V_120 -> V_14 = V_14 ;
V_120 -> V_115 = V_115 ;
V_120 -> V_18 = V_18 ;
V_120 -> V_19 = V_19 ;
F_55 ( & V_6 -> V_117 ) ;
F_56 ( & V_120 -> V_64 , & V_6 -> V_121 ) ;
F_57 ( & V_6 -> V_11 , V_6 -> V_7 , V_120 ) ;
V_6 -> V_7 ++ ;
F_58 ( & V_6 -> V_117 ) ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 , unsigned V_65 )
{
unsigned V_122 ;
if ( V_65 >= V_6 -> V_111 ) {
F_17 ( V_6 -> V_12 , L_10 ,
V_65 , V_6 -> V_111 ) ;
return - V_17 ;
}
if ( V_6 -> V_54 )
V_122 = ( V_65 * V_25 ) / V_6 -> V_110 ;
else
V_122 = V_65 / ( V_6 -> V_24 / V_25 ) ;
return V_122 ;
}
static int F_64 ( unsigned V_63 , unsigned V_80 , unsigned V_81 )
{
int V_73 = - V_17 ;
if ( V_63 == V_80 )
V_73 = 1 ;
else if ( V_63 == V_81 )
V_73 = 0 ;
return V_73 ;
}
static void F_65 ( struct V_123 * * V_76 , enum V_70 V_71 ,
unsigned V_124 , unsigned V_80 , unsigned V_81 ,
unsigned V_52 )
{
( * V_76 ) -> V_71 = V_71 ;
( * V_76 ) -> V_2 = V_124 ;
( * V_76 ) -> V_80 = V_80 ;
( * V_76 ) -> V_81 = V_81 ;
( * V_76 ) -> V_52 = V_52 ;
( * V_76 ) ++ ;
}
static void F_66 ( unsigned long * * V_43 , enum V_70 V_71 ,
unsigned V_89 )
{
* * V_43 = F_37 ( V_71 , V_89 ) ;
( * V_43 ) ++ ;
}
static void F_67 ( struct V_5 * V_6 , struct V_114 * V_115 ,
const char * V_14 , enum V_70 V_71 ,
struct V_123 * * V_76 , unsigned long * * V_125 )
{
unsigned V_124 [ 2 ] , V_88 ;
int V_73 ;
V_73 = F_68 ( V_115 , V_14 , V_124 , 2 ) ;
if ( V_73 )
return;
V_124 [ 0 ] &= V_124 [ 1 ] ;
V_88 = F_43 ( V_124 [ 1 ] ) - 1 ;
F_65 ( V_76 , V_71 , V_124 [ 0 ] , 0 , 0 , V_124 [ 1 ] ) ;
F_66 ( V_125 , V_71 , V_124 [ 0 ] >> V_88 ) ;
}
static void F_69 ( struct V_5 * V_6 , struct V_114 * V_115 ,
const char * V_14 , enum V_70 V_71 ,
struct V_123 * * V_76 , unsigned long * * V_125 )
{
unsigned V_124 [ 4 ] ;
int V_73 ;
V_73 = F_68 ( V_115 , V_14 , V_124 , 4 ) ;
if ( V_73 )
return;
if ( ! V_124 [ 3 ] ) {
F_17 ( V_6 -> V_12 , L_11 ) ;
return;
}
V_124 [ 0 ] &= V_124 [ 3 ] ;
V_124 [ 1 ] &= V_124 [ 3 ] ;
V_124 [ 2 ] &= V_124 [ 3 ] ;
V_73 = F_64 ( V_124 [ 0 ] , V_124 [ 1 ] , V_124 [ 2 ] ) ;
if ( V_73 < 0 )
F_29 ( V_6 -> V_12 , L_12 ) ;
F_65 ( V_76 , V_71 , V_124 [ 0 ] , V_124 [ 1 ] , V_124 [ 2 ] , V_124 [ 3 ] ) ;
F_66 ( V_125 , V_71 , V_73 ) ;
}
static int F_70 ( struct V_5 * V_6 , struct V_114 * V_115 ,
struct V_34 * V_35 ,
struct V_29 * * V_30 )
{
struct V_29 * V_126 = * V_30 ;
int V_46 = 0 , V_74 = 0 ;
unsigned long * V_125 = NULL , * V_21 = NULL ;
struct V_123 * V_76 = NULL ;
struct V_127 V_128 [] = {
{ L_13 , V_83 , } ,
{ L_14 , V_84 , } ,
{ L_15 , V_82 , } ,
{ L_16 , V_85 , } ,
} ;
struct V_127 V_129 [] = {
{ L_17 , V_78 , } ,
{ L_18 , V_77 , } ,
{ L_19 ,
V_79 , } ,
} ;
if ( ! V_130 )
return 0 ;
for ( V_46 = 0 ; V_46 < F_36 ( V_128 ) ; V_46 ++ ) {
if ( F_71 ( V_115 , V_128 [ V_46 ] . V_14 , NULL ) )
V_74 ++ ;
}
for ( V_46 = 0 ; V_46 < F_36 ( V_129 ) ; V_46 ++ ) {
if ( F_71 ( V_115 , V_129 [ V_46 ] . V_14 , NULL ) )
V_74 ++ ;
}
if ( ! V_74 )
return 0 ;
V_35 -> V_76 = F_53 ( V_6 -> V_12 ,
sizeof( struct V_123 ) * V_74 ,
V_112 ) ;
if ( ! V_35 -> V_76 )
return - V_101 ;
V_35 -> V_74 = V_74 ;
V_76 = & ( V_35 -> V_76 [ 0 ] ) ;
V_126 ++ ;
V_125 = F_53 ( V_6 -> V_12 , sizeof( unsigned long ) * V_74 ,
V_112 ) ;
if ( ! V_125 )
return - V_101 ;
V_21 = & V_125 [ 0 ] ;
for ( V_46 = 0 ; V_46 < F_36 ( V_128 ) ; V_46 ++ )
F_67 ( V_6 , V_115 , V_128 [ V_46 ] . V_14 , V_128 [ V_46 ] . V_71 ,
& V_76 , & V_21 ) ;
for ( V_46 = 0 ; V_46 < F_36 ( V_129 ) ; V_46 ++ )
F_69 ( V_6 , V_115 , V_129 [ V_46 ] . V_14 , V_129 [ V_46 ] . V_71 ,
& V_76 , & V_21 ) ;
V_126 -> type = V_131 ;
V_126 -> V_63 . V_86 . V_132 = V_115 -> V_14 ;
V_126 -> V_63 . V_86 . V_86 = V_125 ;
V_126 -> V_63 . V_86 . V_87 = V_74 ;
return 0 ;
}
static int F_72 ( struct V_5 * V_6 ,
struct V_114 * V_115 ,
struct V_29 * * V_30 ,
unsigned * V_31 ,
const char * * V_38 )
{
struct V_49 * V_50 ;
const T_4 * V_133 ;
int V_111 , V_134 , * V_15 , V_122 = 0 , V_119 = 0 , V_103 = - V_101 ;
struct V_34 * V_116 ;
V_133 = F_73 ( V_115 , V_135 , & V_111 ) ;
if ( ( ! V_133 ) || ( V_111 < sizeof( * V_133 ) * 2 ) ) {
F_17 ( V_6 -> V_12 , L_20 ,
V_115 -> V_14 ) ;
return - V_17 ;
}
V_111 /= sizeof( * V_133 ) ;
V_134 = V_111 / 2 ;
V_50 = F_53 ( V_6 -> V_12 , sizeof( * V_50 ) * V_134 , V_112 ) ;
if ( ! V_50 )
return - V_101 ;
V_15 = F_53 ( V_6 -> V_12 , sizeof( * V_15 ) * V_134 , V_112 ) ;
if ( ! V_15 )
goto V_136;
while ( V_122 < V_111 ) {
unsigned V_65 , V_2 ;
int V_22 ;
V_65 = F_74 ( V_133 + V_122 ++ ) ;
V_2 = F_74 ( V_133 + V_122 ++ ) ;
V_50 [ V_119 ] . V_1 = V_6 -> V_27 + V_65 ;
V_50 [ V_119 ] . V_2 = V_2 ;
V_22 = F_63 ( V_6 , V_65 ) ;
if ( V_22 < 0 ) {
F_17 ( V_6 -> V_12 ,
L_21 ,
V_115 -> V_14 , V_65 ) ;
break;
}
V_15 [ V_119 ++ ] = V_22 ;
}
V_38 [ 0 ] = V_115 -> V_14 ;
V_116 = F_54 ( V_6 , V_115 , V_115 -> V_14 , V_50 , V_119 , V_38 , 1 ) ;
if ( ! V_116 )
goto V_137;
V_103 = F_62 ( V_6 , V_115 , V_115 -> V_14 , V_15 , V_119 ) ;
if ( V_103 < 0 )
goto V_138;
( * V_30 ) -> type = V_139 ;
( * V_30 ) -> V_63 . V_133 . V_10 = V_115 -> V_14 ;
( * V_30 ) -> V_63 . V_133 . V_116 = V_115 -> V_14 ;
if ( V_130 ) {
V_103 = F_70 ( V_6 , V_115 , V_116 , V_30 ) ;
if ( V_103 )
goto V_140;
* V_31 = 2 ;
} else {
* V_31 = 1 ;
}
return 0 ;
V_140:
F_75 ( V_6 ) ;
* V_31 = 1 ;
V_138:
F_59 ( V_6 , V_116 ) ;
V_137:
F_22 ( V_6 -> V_12 , V_15 ) ;
V_136:
F_22 ( V_6 -> V_12 , V_50 ) ;
return V_103 ;
}
static int F_76 ( struct V_5 * V_6 ,
struct V_114 * V_115 ,
struct V_29 * * V_30 ,
unsigned * V_31 ,
const char * * V_38 )
{
struct V_49 * V_50 ;
const T_4 * V_133 ;
int V_111 , V_134 , * V_15 , V_122 = 0 , V_119 = 0 , V_103 = - V_101 ;
int V_141 ;
struct V_34 * V_116 ;
V_133 = F_73 ( V_115 , V_142 , & V_111 ) ;
if ( ! V_133 ) {
F_17 ( V_6 -> V_12 , L_22 , V_115 -> V_14 ) ;
return - V_17 ;
}
if ( V_111 < ( sizeof( * V_133 ) * V_143 ) ) {
F_17 ( V_6 -> V_12 , L_23 , V_115 -> V_14 ) ;
return - V_17 ;
}
V_111 /= sizeof( * V_133 ) ;
V_134 = V_111 / V_143 ;
V_141 = V_6 -> V_24 / V_6 -> V_110 ;
V_50 = F_53 ( V_6 -> V_12 , sizeof( * V_50 ) * V_134 * V_141 ,
V_112 ) ;
if ( ! V_50 )
return - V_101 ;
V_15 = F_53 ( V_6 -> V_12 , sizeof( * V_15 ) * V_134 * V_141 ,
V_112 ) ;
if ( ! V_15 )
goto V_136;
while ( V_122 < V_111 ) {
unsigned V_65 , V_2 ;
unsigned V_52 , V_144 , V_145 , V_146 , V_147 ;
unsigned V_148 ;
int V_22 ;
V_65 = F_74 ( V_133 + V_122 ++ ) ;
V_2 = F_74 ( V_133 + V_122 ++ ) ;
V_52 = F_74 ( V_133 + V_122 ++ ) ;
while ( V_52 ) {
V_144 = F_77 ( V_52 ) ;
V_148 = V_144 / V_6 -> V_110 ;
V_146 = ( ( V_6 -> V_47 ) << V_144 ) ;
V_145 = V_2 & V_146 ;
V_147 = V_52 & V_146 ;
if ( ( V_52 & V_146 ) == 0 ) {
F_17 ( V_6 -> V_12 ,
L_24 ,
V_115 -> V_14 , V_65 ) ;
break;
}
V_52 &= ~ V_146 ;
if ( V_147 != V_146 ) {
F_78 ( V_6 -> V_12 ,
L_25 ,
V_147 , V_115 -> V_14 , V_65 ) ;
continue;
}
V_50 [ V_119 ] . V_52 = V_147 ;
V_50 [ V_119 ] . V_1 = V_6 -> V_27 + V_65 ;
V_50 [ V_119 ] . V_2 = V_145 ;
V_22 = F_63 ( V_6 , V_65 ) ;
if ( V_22 < 0 ) {
F_17 ( V_6 -> V_12 ,
L_21 ,
V_115 -> V_14 , V_65 ) ;
break;
}
V_15 [ V_119 ++ ] = V_22 + V_148 ;
}
}
V_38 [ 0 ] = V_115 -> V_14 ;
V_116 = F_54 ( V_6 , V_115 , V_115 -> V_14 , V_50 , V_119 , V_38 , 1 ) ;
if ( ! V_116 )
goto V_137;
V_103 = F_62 ( V_6 , V_115 , V_115 -> V_14 , V_15 , V_119 ) ;
if ( V_103 < 0 )
goto V_138;
( * V_30 ) -> type = V_139 ;
( * V_30 ) -> V_63 . V_133 . V_10 = V_115 -> V_14 ;
( * V_30 ) -> V_63 . V_133 . V_116 = V_115 -> V_14 ;
if ( V_130 ) {
F_17 ( V_6 -> V_12 , L_26 ) ;
goto V_140;
}
* V_31 = 1 ;
return 0 ;
V_140:
F_75 ( V_6 ) ;
* V_31 = 1 ;
V_138:
F_59 ( V_6 , V_116 ) ;
V_137:
F_22 ( V_6 -> V_12 , V_15 ) ;
V_136:
F_22 ( V_6 -> V_12 , V_50 ) ;
return V_103 ;
}
static int F_79 ( struct V_3 * V_4 ,
struct V_114 * V_149 ,
struct V_29 * * V_30 , unsigned * V_31 )
{
struct V_5 * V_6 ;
const char * * V_38 ;
int V_73 ;
V_6 = F_14 ( V_4 ) ;
* V_30 = F_53 ( V_6 -> V_12 , sizeof( * * V_30 ) * 2 , V_112 ) ;
if ( ! * V_30 )
return - V_101 ;
* V_31 = 0 ;
V_38 = F_53 ( V_6 -> V_12 , sizeof( * V_38 ) , V_112 ) ;
if ( ! V_38 ) {
V_73 = - V_101 ;
goto V_150;
}
if ( V_6 -> V_54 ) {
V_73 = F_76 ( V_6 , V_149 , V_30 ,
V_31 , V_38 ) ;
if ( V_73 < 0 ) {
F_17 ( V_6 -> V_12 , L_27 ,
V_149 -> V_14 ) ;
goto V_151;
}
} else {
V_73 = F_72 ( V_6 , V_149 , V_30 ,
V_31 , V_38 ) ;
if ( V_73 < 0 ) {
F_17 ( V_6 -> V_12 , L_27 ,
V_149 -> V_14 ) ;
goto V_151;
}
}
return 0 ;
V_151:
F_22 ( V_6 -> V_12 , V_38 ) ;
V_150:
F_22 ( V_6 -> V_12 , * V_30 ) ;
return V_73 ;
}
static void F_80 ( struct V_5 * V_6 )
{
struct V_60 * V_61 , * V_62 ;
int V_46 ;
F_55 ( & V_6 -> V_117 ) ;
for ( V_46 = 0 ; V_46 < V_6 -> V_32 ; V_46 ++ ) {
struct V_34 * V_35 ;
V_35 = F_16 ( & V_6 -> V_36 , V_46 ) ;
if ( ! V_35 )
continue;
F_60 ( & V_6 -> V_36 , V_46 ) ;
}
F_33 (pos, tmp, &pcs->functions) {
struct V_34 * V_116 ;
V_116 = F_34 ( V_61 , struct V_34 , V_64 ) ;
F_61 ( & V_116 -> V_64 ) ;
}
F_58 ( & V_6 -> V_117 ) ;
}
static void F_75 ( struct V_5 * V_6 )
{
struct V_60 * V_61 , * V_62 ;
int V_46 ;
F_55 ( & V_6 -> V_117 ) ;
for ( V_46 = 0 ; V_46 < V_6 -> V_7 ; V_46 ++ ) {
struct V_9 * V_120 ;
V_120 = F_16 ( & V_6 -> V_11 , V_46 ) ;
if ( ! V_120 )
continue;
F_60 ( & V_6 -> V_11 , V_46 ) ;
}
F_33 (pos, tmp, &pcs->pingroups) {
struct V_9 * V_120 ;
V_120 = F_34 ( V_61 , struct V_9 , V_64 ) ;
F_61 ( & V_120 -> V_64 ) ;
}
F_58 ( & V_6 -> V_117 ) ;
}
static void F_81 ( struct V_5 * V_6 )
{
struct V_93 * V_94 = & V_6 -> V_95 ;
if ( V_94 -> V_152 < 0 )
return;
if ( V_6 -> V_153 )
F_82 ( V_6 -> V_153 ) ;
if ( V_154 )
F_83 ( V_94 -> V_152 , V_94 ) ;
else
F_84 ( V_94 -> V_152 , NULL ) ;
}
static void F_85 ( struct V_5 * V_6 )
{
F_81 ( V_6 ) ;
F_86 ( V_6 -> V_155 ) ;
F_80 ( V_6 ) ;
F_75 ( V_6 ) ;
}
static int F_87 ( struct V_114 * V_64 , struct V_5 * V_6 )
{
const char * V_156 = L_28 ;
const char * V_157 = L_29 ;
struct V_158 V_159 ;
struct V_58 * V_57 ;
int V_73 , V_46 ;
for ( V_46 = 0 ; ; V_46 ++ ) {
V_73 = F_88 ( V_64 , V_156 , V_157 ,
V_46 , & V_159 ) ;
if ( V_73 ) {
V_73 = 0 ;
break;
}
V_57 = F_53 ( V_6 -> V_12 , sizeof( * V_57 ) , V_112 ) ;
if ( ! V_57 ) {
V_73 = - V_101 ;
break;
}
V_57 -> V_65 = V_159 . args [ 0 ] ;
V_57 -> V_16 = V_159 . args [ 1 ] ;
V_57 -> V_66 = V_159 . args [ 2 ] ;
F_55 ( & V_6 -> V_117 ) ;
F_56 ( & V_57 -> V_64 , & V_6 -> V_160 ) ;
F_58 ( & V_6 -> V_117 ) ;
}
return V_73 ;
}
static inline void F_89 ( struct V_93 * V_94 ,
int V_152 , const bool V_80 )
{
struct V_5 * V_6 ;
struct V_60 * V_61 ;
unsigned V_52 ;
V_6 = F_90 ( V_94 , struct V_5 , V_95 ) ;
F_91 (pos, &pcs->irqs) {
struct V_161 * V_162 ;
unsigned V_163 ;
V_162 = F_34 ( V_61 , struct V_161 , V_64 ) ;
if ( V_152 != V_162 -> V_152 )
continue;
V_163 = V_94 -> V_102 ;
F_92 ( & V_6 -> V_53 ) ;
V_52 = V_6 -> V_26 ( V_162 -> V_1 ) ;
if ( V_80 )
V_52 |= V_163 ;
else
V_52 &= ~ V_163 ;
V_6 -> V_55 ( V_52 , V_162 -> V_1 ) ;
F_93 ( & V_6 -> V_53 ) ;
}
if ( V_94 -> V_164 )
V_94 -> V_164 () ;
}
static void F_94 ( struct V_165 * V_166 )
{
struct V_93 * V_94 = F_95 ( V_166 ) ;
F_89 ( V_94 , V_166 -> V_152 , false ) ;
}
static void F_96 ( struct V_165 * V_166 )
{
struct V_93 * V_94 = F_95 ( V_166 ) ;
F_89 ( V_94 , V_166 -> V_152 , true ) ;
}
static int F_97 ( struct V_165 * V_166 , unsigned int V_167 )
{
if ( V_167 )
F_96 ( V_166 ) ;
else
F_94 ( V_166 ) ;
return 0 ;
}
static int F_98 ( struct V_93 * V_94 )
{
struct V_5 * V_6 ;
struct V_60 * V_61 ;
int V_168 = 0 ;
V_6 = F_90 ( V_94 , struct V_5 , V_95 ) ;
F_91 (pos, &pcs->irqs) {
struct V_161 * V_162 ;
unsigned V_52 ;
V_162 = F_34 ( V_61 , struct V_161 , V_64 ) ;
F_92 ( & V_6 -> V_53 ) ;
V_52 = V_6 -> V_26 ( V_162 -> V_1 ) ;
F_93 ( & V_6 -> V_53 ) ;
if ( V_52 & V_94 -> V_169 ) {
F_99 ( F_100 ( V_6 -> V_153 ,
V_162 -> V_170 ) ) ;
V_168 ++ ;
}
}
return V_168 ;
}
static T_5 F_101 ( int V_152 , void * V_166 )
{
struct V_93 * V_94 = V_166 ;
return F_98 ( V_94 ) ? V_171 : V_172 ;
}
static void F_102 ( struct V_173 * V_100 )
{
struct V_93 * V_94 = F_103 ( V_100 ) ;
struct V_174 * V_175 ;
V_175 = F_104 ( V_100 ) ;
F_105 ( V_175 , V_100 ) ;
F_98 ( V_94 ) ;
F_106 ( V_175 , V_100 ) ;
return;
}
static int F_107 ( struct V_176 * V_166 , unsigned int V_152 ,
T_6 V_170 )
{
struct V_93 * V_94 = V_166 -> V_177 ;
struct V_5 * V_6 ;
struct V_161 * V_162 ;
V_6 = F_90 ( V_94 , struct V_5 , V_95 ) ;
V_162 = F_53 ( V_6 -> V_12 , sizeof( * V_162 ) , V_112 ) ;
if ( ! V_162 )
return - V_101 ;
V_162 -> V_1 = V_6 -> V_27 + V_170 ;
V_162 -> V_170 = V_170 ;
V_162 -> V_152 = V_152 ;
F_55 ( & V_6 -> V_117 ) ;
F_56 ( & V_162 -> V_64 , & V_6 -> V_178 ) ;
F_58 ( & V_6 -> V_117 ) ;
F_108 ( V_152 , V_94 ) ;
F_109 ( V_152 , & V_6 -> V_175 ,
V_179 ) ;
F_110 ( V_152 , & V_180 ) ;
F_111 ( V_152 ) ;
return 0 ;
}
static int F_112 ( struct V_5 * V_6 ,
struct V_114 * V_115 )
{
struct V_93 * V_94 = & V_6 -> V_95 ;
const char * V_14 = L_30 ;
int V_181 ;
if ( ! V_94 -> V_102 ||
! V_94 -> V_169 ) {
V_94 -> V_152 = - 1 ;
return - V_17 ;
}
F_113 ( & V_6 -> V_178 ) ;
V_6 -> V_175 . V_14 = V_14 ;
V_6 -> V_175 . V_182 = F_94 ;
V_6 -> V_175 . V_183 = F_94 ;
V_6 -> V_175 . V_184 = F_96 ;
V_6 -> V_175 . V_185 = F_97 ;
if ( V_154 ) {
int V_103 ;
V_103 = F_114 ( V_94 -> V_152 , F_101 ,
V_186 | V_187 |
V_188 ,
V_14 , V_94 ) ;
if ( V_103 ) {
V_94 -> V_152 = - 1 ;
return V_103 ;
}
} else {
F_115 ( V_94 -> V_152 ,
F_102 ,
V_94 ) ;
}
V_181 = V_6 -> V_111 ;
V_6 -> V_153 = F_116 ( V_115 , V_181 , 0 ,
& V_189 ,
V_94 ) ;
if ( ! V_6 -> V_153 ) {
F_84 ( V_94 -> V_152 , NULL ) ;
return - V_17 ;
}
return 0 ;
}
static int F_117 ( struct V_190 * V_191 ,
T_7 V_167 )
{
struct V_5 * V_6 ;
V_6 = F_118 ( V_191 ) ;
if ( ! V_6 )
return - V_17 ;
return F_119 ( V_6 -> V_155 ) ;
}
static int F_120 ( struct V_190 * V_191 )
{
struct V_5 * V_6 ;
V_6 = F_118 ( V_191 ) ;
if ( ! V_6 )
return - V_17 ;
return F_121 ( V_6 -> V_155 ) ;
}
static int F_122 ( struct V_190 * V_191 )
{
struct V_114 * V_115 = V_191 -> V_12 . V_192 ;
const struct V_193 * V_194 ;
struct V_195 * V_196 ;
struct V_197 * V_103 ;
struct V_5 * V_6 ;
const struct V_93 * V_198 ;
int V_73 ;
V_194 = F_123 ( V_199 , & V_191 -> V_12 ) ;
if ( ! V_194 )
return - V_17 ;
V_6 = F_53 ( & V_191 -> V_12 , sizeof( * V_6 ) , V_112 ) ;
if ( ! V_6 ) {
F_17 ( & V_191 -> V_12 , L_31 ) ;
return - V_101 ;
}
V_6 -> V_12 = & V_191 -> V_12 ;
F_124 ( & V_6 -> V_53 ) ;
F_125 ( & V_6 -> V_117 ) ;
F_113 ( & V_6 -> V_121 ) ;
F_113 ( & V_6 -> V_118 ) ;
F_113 ( & V_6 -> V_160 ) ;
V_198 = V_194 -> V_63 ;
V_6 -> V_51 = V_198 -> V_51 ;
memcpy ( & V_6 -> V_95 , V_198 , sizeof( * V_198 ) ) ;
F_126 ( L_32 , & V_6 -> V_24 ,
L_33 ) ;
V_73 = F_127 ( V_115 , L_34 ,
& V_6 -> V_47 ) ;
if ( ! V_73 ) {
V_6 -> V_200 = F_77 ( V_6 -> V_47 ) ;
V_6 -> V_201 = V_6 -> V_47 >> V_6 -> V_200 ;
} else {
V_6 -> V_47 = 0 ;
V_6 -> V_200 = 0 ;
V_6 -> V_201 = 0 ;
}
V_73 = F_127 ( V_115 , L_35 ,
& V_6 -> V_202 ) ;
if ( V_73 )
V_6 -> V_202 = V_203 ;
V_6 -> V_54 = F_128 ( V_115 ,
L_36 ) ;
V_103 = F_129 ( V_191 , V_204 , 0 ) ;
if ( ! V_103 ) {
F_17 ( V_6 -> V_12 , L_37 ) ;
return - V_205 ;
}
V_6 -> V_103 = F_130 ( V_6 -> V_12 , V_103 -> V_104 ,
F_131 ( V_103 ) , V_28 ) ;
if ( ! V_6 -> V_103 ) {
F_17 ( V_6 -> V_12 , L_38 ) ;
return - V_206 ;
}
V_6 -> V_111 = F_131 ( V_6 -> V_103 ) ;
V_6 -> V_27 = F_132 ( V_6 -> V_12 , V_6 -> V_103 -> V_104 , V_6 -> V_111 ) ;
if ( ! V_6 -> V_27 ) {
F_17 ( V_6 -> V_12 , L_39 ) ;
return - V_205 ;
}
F_133 ( & V_6 -> V_11 , V_112 ) ;
F_133 ( & V_6 -> V_36 , V_112 ) ;
F_134 ( V_191 , V_6 ) ;
switch ( V_6 -> V_24 ) {
case 8 :
V_6 -> V_26 = F_1 ;
V_6 -> V_55 = F_7 ;
break;
case 16 :
V_6 -> V_26 = F_3 ;
V_6 -> V_55 = F_9 ;
break;
case 32 :
V_6 -> V_26 = F_5 ;
V_6 -> V_55 = F_11 ;
break;
default:
break;
}
V_6 -> V_100 . V_14 = V_28 ;
V_6 -> V_100 . V_207 = & V_208 ;
V_6 -> V_100 . V_209 = & V_210 ;
if ( V_130 )
V_6 -> V_100 . V_211 = & V_212 ;
V_6 -> V_100 . V_213 = V_214 ;
V_73 = F_51 ( V_6 ) ;
if ( V_73 < 0 )
goto free;
V_6 -> V_155 = F_135 ( & V_6 -> V_100 , V_6 -> V_12 , V_6 ) ;
if ( F_136 ( V_6 -> V_155 ) ) {
F_17 ( V_6 -> V_12 , L_40 ) ;
V_73 = F_137 ( V_6 -> V_155 ) ;
goto free;
}
V_73 = F_87 ( V_115 , V_6 ) ;
if ( V_73 < 0 )
goto free;
V_6 -> V_95 . V_152 = F_138 ( V_115 , 0 ) ;
if ( V_6 -> V_95 . V_152 )
V_6 -> V_51 |= V_215 ;
V_196 = F_139 ( & V_191 -> V_12 ) ;
if ( V_196 ) {
if ( V_196 -> V_164 )
V_6 -> V_95 . V_164 = V_196 -> V_164 ;
if ( V_196 -> V_152 ) {
V_6 -> V_95 . V_152 = V_196 -> V_152 ;
V_6 -> V_51 |= V_215 ;
}
}
if ( V_216 ) {
V_73 = F_112 ( V_6 , V_115 ) ;
if ( V_73 < 0 )
F_78 ( V_6 -> V_12 , L_41 ) ;
}
F_140 ( V_6 -> V_12 , L_42 ,
V_6 -> V_100 . V_16 , V_6 -> V_27 , V_6 -> V_111 ) ;
return 0 ;
free:
F_85 ( V_6 ) ;
return V_73 ;
}
static int F_141 ( struct V_190 * V_191 )
{
struct V_5 * V_6 = F_118 ( V_191 ) ;
if ( ! V_6 )
return 0 ;
F_85 ( V_6 ) ;
return 0 ;
}
