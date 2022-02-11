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
static void F_32 ( struct V_3 * V_4 , unsigned V_33 ,
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
if ( V_6 -> V_56 == V_57 ) {
F_29 ( V_6 -> V_12 , L_5 ,
V_35 -> V_14 , V_33 ) ;
return;
}
F_29 ( V_6 -> V_12 , L_6 ,
V_33 , V_35 -> V_14 ) ;
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
V_2 |= V_6 -> V_56 << V_6 -> V_58 ;
V_6 -> V_55 ( V_2 , V_50 -> V_1 ) ;
F_31 ( & V_6 -> V_53 , V_51 ) ;
}
}
static int F_33 ( struct V_3 * V_4 ,
struct V_59 * V_60 , unsigned V_22 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
struct V_61 * V_62 = NULL ;
struct V_63 * V_64 , * V_65 ;
int V_23 = 0 ;
unsigned V_66 ;
if ( ! V_6 -> V_47 )
return - V_45 ;
F_34 (pos, tmp, &pcs->gpiofuncs) {
V_62 = F_35 ( V_64 , struct V_61 , V_67 ) ;
if ( V_22 >= V_62 -> V_68 + V_62 -> V_16
|| V_22 < V_62 -> V_68 )
continue;
V_23 = V_6 -> V_24 / V_25 ;
V_66 = V_6 -> V_26 ( V_6 -> V_27 + V_22 * V_23 ) & ~ V_6 -> V_47 ;
V_66 |= V_62 -> V_69 ;
V_6 -> V_55 ( V_66 , V_6 -> V_27 + V_22 * V_23 ) ;
break;
}
return 0 ;
}
static void F_36 ( struct V_3 * V_4 , unsigned V_22 )
{
unsigned long V_70 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_37 ( V_71 ) ; V_46 ++ ) {
V_70 = F_38 ( V_71 [ V_46 ] , 0 ) ;
F_39 ( V_4 , V_22 , & V_70 , 1 ) ;
}
}
static bool F_40 ( struct V_3 * V_4 , unsigned V_22 )
{
unsigned long V_70 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_37 ( V_71 ) ; V_46 ++ ) {
V_70 = F_38 ( V_71 [ V_46 ] , 0 ) ;
if ( ! F_41 ( V_4 , V_22 , & V_70 ) )
goto V_72;
}
return true ;
V_72:
return false ;
}
static int F_41 ( struct V_3 * V_4 ,
unsigned V_22 , unsigned long * V_70 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
struct V_34 * V_35 ;
enum V_73 V_74 ;
unsigned V_68 = 0 , V_66 = 0 , V_46 , V_75 , V_76 ;
V_76 = F_26 ( V_4 , V_22 , & V_35 ) ;
if ( V_76 )
return V_76 ;
for ( V_46 = 0 ; V_46 < V_35 -> V_77 ; V_46 ++ ) {
V_74 = F_42 ( * V_70 ) ;
if ( V_74 == V_78 ) {
if ( F_40 ( V_4 , V_22 ) ) {
* V_70 = 0 ;
return 0 ;
} else {
return - V_45 ;
}
} else if ( V_74 != V_35 -> V_79 [ V_46 ] . V_74 ) {
continue;
}
V_68 = V_22 * ( V_6 -> V_24 / V_25 ) ;
V_66 = V_6 -> V_26 ( V_6 -> V_27 + V_68 ) & V_35 -> V_79 [ V_46 ] . V_52 ;
switch ( V_35 -> V_79 [ V_46 ] . V_74 ) {
case V_80 :
case V_81 :
case V_82 :
if ( ( V_66 != V_35 -> V_79 [ V_46 ] . V_83 ) ||
( V_66 == V_35 -> V_79 [ V_46 ] . V_84 ) )
return - V_45 ;
* V_70 = 0 ;
break;
case V_85 :
for ( V_75 = 0 ; V_75 < V_35 -> V_77 ; V_75 ++ ) {
switch ( V_35 -> V_79 [ V_75 ] . V_74 ) {
case V_82 :
if ( V_66 != V_35 -> V_79 [ V_75 ] . V_83 )
return - V_45 ;
break;
default:
break;
}
}
* V_70 = V_66 ;
break;
case V_86 :
case V_87 :
case V_88 :
default:
* V_70 = V_66 ;
break;
}
return 0 ;
}
return - V_45 ;
}
static int F_39 ( struct V_3 * V_4 ,
unsigned V_22 , unsigned long * V_89 ,
unsigned V_90 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
struct V_34 * V_35 ;
unsigned V_68 = 0 , V_91 = 0 , V_46 , V_66 , V_76 ;
T_3 V_92 ;
int V_75 ;
V_76 = F_26 ( V_4 , V_22 , & V_35 ) ;
if ( V_76 )
return V_76 ;
for ( V_75 = 0 ; V_75 < V_90 ; V_75 ++ ) {
for ( V_46 = 0 ; V_46 < V_35 -> V_77 ; V_46 ++ ) {
if ( F_42 ( V_89 [ V_75 ] )
!= V_35 -> V_79 [ V_46 ] . V_74 )
continue;
V_68 = V_22 * ( V_6 -> V_24 / V_25 ) ;
V_66 = V_6 -> V_26 ( V_6 -> V_27 + V_68 ) ;
V_92 = F_43 ( V_89 [ V_75 ] ) ;
switch ( V_35 -> V_79 [ V_46 ] . V_74 ) {
case V_85 :
case V_86 :
case V_87 :
case V_88 :
V_91 = F_44 ( V_35 -> V_79 [ V_46 ] . V_52 ) - 1 ;
V_66 &= ~ V_35 -> V_79 [ V_46 ] . V_52 ;
V_66 |= ( V_92 << V_91 ) & V_35 -> V_79 [ V_46 ] . V_52 ;
break;
case V_78 :
F_36 ( V_4 , V_22 ) ;
break;
case V_80 :
case V_81 :
if ( V_92 )
F_36 ( V_4 , V_22 ) ;
case V_82 :
V_66 &= ~ V_35 -> V_79 [ V_46 ] . V_52 ;
if ( V_92 )
V_66 |= V_35 -> V_79 [ V_46 ] . V_83 ;
else
V_66 |= V_35 -> V_79 [ V_46 ] . V_84 ;
break;
default:
return - V_45 ;
}
V_6 -> V_55 ( V_66 , V_6 -> V_27 + V_68 ) ;
break;
}
if ( V_46 >= V_35 -> V_77 )
return - V_45 ;
}
return 0 ;
}
static int F_45 ( struct V_3 * V_4 ,
unsigned V_10 , unsigned long * V_70 )
{
const unsigned * V_15 ;
unsigned V_16 , V_93 = 0 ;
int V_46 , V_76 ;
V_76 = F_18 ( V_4 , V_10 , & V_15 , & V_16 ) ;
if ( V_76 )
return V_76 ;
for ( V_46 = 0 ; V_46 < V_16 ; V_46 ++ ) {
if ( F_41 ( V_4 , V_15 [ V_46 ] , V_70 ) )
return - V_45 ;
if ( V_46 && ( V_93 != * V_70 ) )
return - V_45 ;
V_93 = * V_70 ;
}
return 0 ;
}
static int F_46 ( struct V_3 * V_4 ,
unsigned V_10 , unsigned long * V_89 ,
unsigned V_90 )
{
const unsigned * V_15 ;
unsigned V_16 ;
int V_46 , V_76 ;
V_76 = F_18 ( V_4 , V_10 , & V_15 , & V_16 ) ;
if ( V_76 )
return V_76 ;
for ( V_46 = 0 ; V_46 < V_16 ; V_46 ++ ) {
if ( F_39 ( V_4 , V_15 [ V_46 ] , V_89 , V_90 ) )
return - V_45 ;
}
return 0 ;
}
static void F_47 ( struct V_3 * V_4 ,
struct V_20 * V_21 , unsigned V_22 )
{
}
static void F_48 ( struct V_3 * V_4 ,
struct V_20 * V_21 , unsigned V_94 )
{
}
static void F_49 ( struct V_3 * V_4 ,
struct V_20 * V_21 ,
unsigned long V_70 )
{
F_50 ( V_4 , V_21 , V_70 ) ;
}
static int F_51 ( struct V_5 * V_6 , unsigned V_68 ,
unsigned V_95 )
{
struct V_96 * V_97 = & V_6 -> V_98 ;
struct V_99 * V_22 ;
struct V_100 * V_101 ;
int V_46 ;
V_46 = V_6 -> V_15 . V_102 ;
if ( V_46 >= V_6 -> V_103 . V_16 ) {
F_17 ( V_6 -> V_12 , L_7 ,
V_6 -> V_103 . V_16 ) ;
return - V_104 ;
}
if ( V_97 -> V_105 ) {
unsigned V_2 ;
V_2 = V_6 -> V_26 ( V_6 -> V_27 + V_68 ) ;
if ( V_2 & V_97 -> V_105 ) {
F_29 ( V_6 -> V_12 , L_8 ,
( unsigned long ) V_6 -> V_106 -> V_107 + V_68 , V_2 ) ;
V_2 &= ~ V_97 -> V_105 ;
V_6 -> V_55 ( V_2 , V_6 -> V_27 + V_68 ) ;
}
}
V_22 = & V_6 -> V_15 . V_108 [ V_46 ] ;
V_101 = & V_6 -> V_109 [ V_46 ] ;
sprintf ( V_101 -> V_14 , L_9 ,
( unsigned long ) V_6 -> V_106 -> V_107 + V_68 , V_95 ) ;
V_22 -> V_14 = V_101 -> V_14 ;
V_22 -> V_110 = V_46 ;
V_6 -> V_15 . V_102 ++ ;
return V_46 ;
}
static int F_52 ( struct V_5 * V_6 )
{
int V_23 , V_111 , V_46 ;
int V_112 = 0 ;
V_23 = V_6 -> V_24 / V_25 ;
if ( V_6 -> V_54 ) {
V_6 -> V_113 = F_53 ( V_6 -> V_47 ) ;
V_111 = ( V_6 -> V_114 * V_25 ) / V_6 -> V_113 ;
V_112 = V_6 -> V_24 / V_6 -> V_113 ;
} else {
V_111 = V_6 -> V_114 / V_23 ;
}
F_29 ( V_6 -> V_12 , L_10 , V_111 ) ;
V_6 -> V_15 . V_108 = F_54 ( V_6 -> V_12 ,
sizeof( * V_6 -> V_15 . V_108 ) * V_111 ,
V_115 ) ;
if ( ! V_6 -> V_15 . V_108 )
return - V_104 ;
V_6 -> V_109 = F_54 ( V_6 -> V_12 ,
sizeof( struct V_100 ) * V_111 ,
V_115 ) ;
if ( ! V_6 -> V_109 )
return - V_104 ;
V_6 -> V_103 . V_15 = V_6 -> V_15 . V_108 ;
V_6 -> V_103 . V_16 = V_111 ;
for ( V_46 = 0 ; V_46 < V_6 -> V_103 . V_16 ; V_46 ++ ) {
unsigned V_68 ;
int V_106 ;
int V_116 ;
int V_95 = 0 ;
if ( V_6 -> V_54 ) {
V_116 = ( V_6 -> V_113 * V_46 ) / V_25 ;
V_68 = ( V_116 / V_23 ) * V_23 ;
V_95 = V_46 % V_112 ;
} else {
V_68 = V_46 * V_23 ;
}
V_106 = F_51 ( V_6 , V_68 , V_95 ) ;
if ( V_106 < 0 ) {
F_17 ( V_6 -> V_12 , L_11 , V_106 ) ;
return V_106 ;
}
}
return 0 ;
}
static struct V_34 * F_55 ( struct V_5 * V_6 ,
struct V_117 * V_118 ,
const char * V_14 ,
struct V_49 * V_50 ,
unsigned V_48 ,
const char * * V_38 ,
unsigned V_39 )
{
struct V_34 * V_119 ;
V_119 = F_54 ( V_6 -> V_12 , sizeof( * V_119 ) , V_115 ) ;
if ( ! V_119 )
return NULL ;
V_119 -> V_14 = V_14 ;
V_119 -> V_50 = V_50 ;
V_119 -> V_48 = V_48 ;
V_119 -> V_38 = V_38 ;
V_119 -> V_39 = V_39 ;
F_56 ( & V_6 -> V_120 ) ;
F_57 ( & V_119 -> V_67 , & V_6 -> V_121 ) ;
F_58 ( & V_6 -> V_36 , V_6 -> V_32 , V_119 ) ;
V_6 -> V_32 ++ ;
F_59 ( & V_6 -> V_120 ) ;
return V_119 ;
}
static void F_60 ( struct V_5 * V_6 ,
struct V_34 * V_119 )
{
int V_46 ;
F_56 ( & V_6 -> V_120 ) ;
for ( V_46 = 0 ; V_46 < V_6 -> V_32 ; V_46 ++ ) {
struct V_34 * V_122 ;
V_122 = F_16 ( & V_6 -> V_36 , V_46 ) ;
if ( V_122 == V_119 )
F_61 ( & V_6 -> V_36 , V_46 ) ;
}
F_62 ( & V_119 -> V_67 ) ;
F_59 ( & V_6 -> V_120 ) ;
}
static int F_63 ( struct V_5 * V_6 ,
struct V_117 * V_118 ,
const char * V_14 ,
int * V_18 ,
int V_19 )
{
struct V_9 * V_123 ;
V_123 = F_54 ( V_6 -> V_12 , sizeof( * V_123 ) , V_115 ) ;
if ( ! V_123 )
return - V_104 ;
V_123 -> V_14 = V_14 ;
V_123 -> V_118 = V_118 ;
V_123 -> V_18 = V_18 ;
V_123 -> V_19 = V_19 ;
F_56 ( & V_6 -> V_120 ) ;
F_57 ( & V_123 -> V_67 , & V_6 -> V_124 ) ;
F_58 ( & V_6 -> V_11 , V_6 -> V_7 , V_123 ) ;
V_6 -> V_7 ++ ;
F_59 ( & V_6 -> V_120 ) ;
return 0 ;
}
static int F_64 ( struct V_5 * V_6 , unsigned V_68 )
{
unsigned V_125 ;
if ( V_68 >= V_6 -> V_114 ) {
F_17 ( V_6 -> V_12 , L_12 ,
V_68 , V_6 -> V_114 ) ;
return - V_17 ;
}
if ( V_6 -> V_54 )
V_125 = ( V_68 * V_25 ) / V_6 -> V_113 ;
else
V_125 = V_68 / ( V_6 -> V_24 / V_25 ) ;
return V_125 ;
}
static int F_65 ( unsigned V_66 , unsigned V_83 , unsigned V_84 )
{
int V_76 = - V_17 ;
if ( V_66 == V_83 )
V_76 = 1 ;
else if ( V_66 == V_84 )
V_76 = 0 ;
return V_76 ;
}
static void F_66 ( struct V_126 * * V_79 , enum V_73 V_74 ,
unsigned V_127 , unsigned V_83 , unsigned V_84 ,
unsigned V_52 )
{
( * V_79 ) -> V_74 = V_74 ;
( * V_79 ) -> V_2 = V_127 ;
( * V_79 ) -> V_83 = V_83 ;
( * V_79 ) -> V_84 = V_84 ;
( * V_79 ) -> V_52 = V_52 ;
( * V_79 ) ++ ;
}
static void F_67 ( unsigned long * * V_43 , enum V_73 V_74 ,
unsigned V_92 )
{
* * V_43 = F_38 ( V_74 , V_92 ) ;
( * V_43 ) ++ ;
}
static void F_68 ( struct V_5 * V_6 , struct V_117 * V_118 ,
const char * V_14 , enum V_73 V_74 ,
struct V_126 * * V_79 , unsigned long * * V_128 )
{
unsigned V_127 [ 2 ] , V_91 ;
int V_76 ;
V_76 = F_69 ( V_118 , V_14 , V_127 , 2 ) ;
if ( V_76 )
return;
V_127 [ 0 ] &= V_127 [ 1 ] ;
V_91 = F_44 ( V_127 [ 1 ] ) - 1 ;
F_66 ( V_79 , V_74 , V_127 [ 0 ] , 0 , 0 , V_127 [ 1 ] ) ;
F_67 ( V_128 , V_74 , V_127 [ 0 ] >> V_91 ) ;
}
static void F_70 ( struct V_5 * V_6 , struct V_117 * V_118 ,
const char * V_14 , enum V_73 V_74 ,
struct V_126 * * V_79 , unsigned long * * V_128 )
{
unsigned V_127 [ 4 ] ;
int V_76 ;
V_76 = F_69 ( V_118 , V_14 , V_127 , 4 ) ;
if ( V_76 )
return;
if ( ! V_127 [ 3 ] ) {
F_17 ( V_6 -> V_12 , L_13 ) ;
return;
}
V_127 [ 0 ] &= V_127 [ 3 ] ;
V_127 [ 1 ] &= V_127 [ 3 ] ;
V_127 [ 2 ] &= V_127 [ 3 ] ;
V_76 = F_65 ( V_127 [ 0 ] , V_127 [ 1 ] , V_127 [ 2 ] ) ;
if ( V_76 < 0 )
F_29 ( V_6 -> V_12 , L_14 ) ;
F_66 ( V_79 , V_74 , V_127 [ 0 ] , V_127 [ 1 ] , V_127 [ 2 ] , V_127 [ 3 ] ) ;
F_67 ( V_128 , V_74 , V_76 ) ;
}
static int F_71 ( struct V_5 * V_6 , struct V_117 * V_118 ,
struct V_34 * V_35 ,
struct V_29 * * V_30 )
{
struct V_29 * V_129 = * V_30 ;
int V_46 = 0 , V_77 = 0 ;
unsigned long * V_128 = NULL , * V_21 = NULL ;
struct V_126 * V_79 = NULL ;
struct V_130 V_131 [] = {
{ L_15 , V_86 , } ,
{ L_16 , V_87 , } ,
{ L_17 , V_85 , } ,
{ L_18 , V_88 , } ,
} ;
struct V_130 V_132 [] = {
{ L_19 , V_81 , } ,
{ L_20 , V_80 , } ,
{ L_21 ,
V_82 , } ,
} ;
if ( ! V_133 )
return 0 ;
for ( V_46 = 0 ; V_46 < F_37 ( V_131 ) ; V_46 ++ ) {
if ( F_72 ( V_118 , V_131 [ V_46 ] . V_14 , NULL ) )
V_77 ++ ;
}
for ( V_46 = 0 ; V_46 < F_37 ( V_132 ) ; V_46 ++ ) {
if ( F_72 ( V_118 , V_132 [ V_46 ] . V_14 , NULL ) )
V_77 ++ ;
}
if ( ! V_77 )
return 0 ;
V_35 -> V_79 = F_54 ( V_6 -> V_12 ,
sizeof( struct V_126 ) * V_77 ,
V_115 ) ;
if ( ! V_35 -> V_79 )
return - V_104 ;
V_35 -> V_77 = V_77 ;
V_79 = & ( V_35 -> V_79 [ 0 ] ) ;
V_129 ++ ;
V_128 = F_54 ( V_6 -> V_12 , sizeof( unsigned long ) * V_77 ,
V_115 ) ;
if ( ! V_128 )
return - V_104 ;
V_21 = & V_128 [ 0 ] ;
for ( V_46 = 0 ; V_46 < F_37 ( V_131 ) ; V_46 ++ )
F_68 ( V_6 , V_118 , V_131 [ V_46 ] . V_14 , V_131 [ V_46 ] . V_74 ,
& V_79 , & V_21 ) ;
for ( V_46 = 0 ; V_46 < F_37 ( V_132 ) ; V_46 ++ )
F_70 ( V_6 , V_118 , V_132 [ V_46 ] . V_14 , V_132 [ V_46 ] . V_74 ,
& V_79 , & V_21 ) ;
V_129 -> type = V_134 ;
V_129 -> V_66 . V_89 . V_135 = V_118 -> V_14 ;
V_129 -> V_66 . V_89 . V_89 = V_128 ;
V_129 -> V_66 . V_89 . V_90 = V_77 ;
return 0 ;
}
static int F_73 ( struct V_5 * V_6 ,
struct V_117 * V_118 ,
struct V_29 * * V_30 ,
unsigned * V_31 ,
const char * * V_38 )
{
struct V_49 * V_50 ;
const T_4 * V_136 ;
int V_114 , V_137 , * V_15 , V_125 = 0 , V_122 = 0 , V_106 = - V_104 ;
struct V_34 * V_119 ;
V_136 = F_74 ( V_118 , V_138 , & V_114 ) ;
if ( ( ! V_136 ) || ( V_114 < sizeof( * V_136 ) * 2 ) ) {
F_17 ( V_6 -> V_12 , L_22 ,
V_118 -> V_14 ) ;
return - V_17 ;
}
V_114 /= sizeof( * V_136 ) ;
V_137 = V_114 / 2 ;
V_50 = F_54 ( V_6 -> V_12 , sizeof( * V_50 ) * V_137 , V_115 ) ;
if ( ! V_50 )
return - V_104 ;
V_15 = F_54 ( V_6 -> V_12 , sizeof( * V_15 ) * V_137 , V_115 ) ;
if ( ! V_15 )
goto V_139;
while ( V_125 < V_114 ) {
unsigned V_68 , V_2 ;
int V_22 ;
V_68 = F_75 ( V_136 + V_125 ++ ) ;
V_2 = F_75 ( V_136 + V_125 ++ ) ;
V_50 [ V_122 ] . V_1 = V_6 -> V_27 + V_68 ;
V_50 [ V_122 ] . V_2 = V_2 ;
V_22 = F_64 ( V_6 , V_68 ) ;
if ( V_22 < 0 ) {
F_17 ( V_6 -> V_12 ,
L_23 ,
V_118 -> V_14 , V_68 ) ;
break;
}
V_15 [ V_122 ++ ] = V_22 ;
}
V_38 [ 0 ] = V_118 -> V_14 ;
V_119 = F_55 ( V_6 , V_118 , V_118 -> V_14 , V_50 , V_122 , V_38 , 1 ) ;
if ( ! V_119 )
goto V_140;
V_106 = F_63 ( V_6 , V_118 , V_118 -> V_14 , V_15 , V_122 ) ;
if ( V_106 < 0 )
goto V_141;
( * V_30 ) -> type = V_142 ;
( * V_30 ) -> V_66 . V_136 . V_10 = V_118 -> V_14 ;
( * V_30 ) -> V_66 . V_136 . V_119 = V_118 -> V_14 ;
if ( V_133 ) {
V_106 = F_71 ( V_6 , V_118 , V_119 , V_30 ) ;
if ( V_106 )
goto V_143;
* V_31 = 2 ;
} else {
* V_31 = 1 ;
}
return 0 ;
V_143:
F_76 ( V_6 ) ;
* V_31 = 1 ;
V_141:
F_60 ( V_6 , V_119 ) ;
V_140:
F_22 ( V_6 -> V_12 , V_15 ) ;
V_139:
F_22 ( V_6 -> V_12 , V_50 ) ;
return V_106 ;
}
static int F_77 ( struct V_5 * V_6 ,
struct V_117 * V_118 ,
struct V_29 * * V_30 ,
unsigned * V_31 ,
const char * * V_38 )
{
struct V_49 * V_50 ;
const T_4 * V_136 ;
int V_114 , V_137 , * V_15 , V_125 = 0 , V_122 = 0 , V_106 = - V_104 ;
int V_144 ;
struct V_34 * V_119 ;
V_136 = F_74 ( V_118 , V_145 , & V_114 ) ;
if ( ! V_136 ) {
F_17 ( V_6 -> V_12 , L_24 , V_118 -> V_14 ) ;
return - V_17 ;
}
if ( V_114 < ( sizeof( * V_136 ) * V_146 ) ) {
F_17 ( V_6 -> V_12 , L_25 , V_118 -> V_14 ) ;
return - V_17 ;
}
V_114 /= sizeof( * V_136 ) ;
V_137 = V_114 / V_146 ;
V_144 = V_6 -> V_24 / V_6 -> V_113 ;
V_50 = F_54 ( V_6 -> V_12 , sizeof( * V_50 ) * V_137 * V_144 ,
V_115 ) ;
if ( ! V_50 )
return - V_104 ;
V_15 = F_54 ( V_6 -> V_12 , sizeof( * V_15 ) * V_137 * V_144 ,
V_115 ) ;
if ( ! V_15 )
goto V_139;
while ( V_125 < V_114 ) {
unsigned V_68 , V_2 ;
unsigned V_52 , V_147 , V_148 , V_149 , V_150 ;
unsigned V_151 ;
int V_22 ;
V_68 = F_75 ( V_136 + V_125 ++ ) ;
V_2 = F_75 ( V_136 + V_125 ++ ) ;
V_52 = F_75 ( V_136 + V_125 ++ ) ;
while ( V_52 ) {
V_147 = F_44 ( V_52 ) ;
V_151 = V_147 / V_6 -> V_113 ;
V_149 = ( ( V_6 -> V_47 ) << ( V_147 - 1 ) ) ;
V_148 = V_2 & V_149 ;
V_150 = V_52 & V_149 ;
if ( ( V_52 & V_149 ) == 0 ) {
F_17 ( V_6 -> V_12 ,
L_26 ,
V_118 -> V_14 , V_68 ) ;
break;
}
V_52 &= ~ V_149 ;
if ( V_150 != V_149 ) {
F_78 ( V_6 -> V_12 ,
L_27 ,
V_150 , V_118 -> V_14 , V_68 ) ;
continue;
}
V_50 [ V_122 ] . V_52 = V_150 ;
V_50 [ V_122 ] . V_1 = V_6 -> V_27 + V_68 ;
V_50 [ V_122 ] . V_2 = V_148 ;
V_22 = F_64 ( V_6 , V_68 ) ;
if ( V_22 < 0 ) {
F_17 ( V_6 -> V_12 ,
L_23 ,
V_118 -> V_14 , V_68 ) ;
break;
}
V_15 [ V_122 ++ ] = V_22 + V_151 ;
}
}
V_38 [ 0 ] = V_118 -> V_14 ;
V_119 = F_55 ( V_6 , V_118 , V_118 -> V_14 , V_50 , V_122 , V_38 , 1 ) ;
if ( ! V_119 )
goto V_140;
V_106 = F_63 ( V_6 , V_118 , V_118 -> V_14 , V_15 , V_122 ) ;
if ( V_106 < 0 )
goto V_141;
( * V_30 ) -> type = V_142 ;
( * V_30 ) -> V_66 . V_136 . V_10 = V_118 -> V_14 ;
( * V_30 ) -> V_66 . V_136 . V_119 = V_118 -> V_14 ;
if ( V_133 ) {
F_17 ( V_6 -> V_12 , L_28 ) ;
goto V_143;
}
* V_31 = 1 ;
return 0 ;
V_143:
F_76 ( V_6 ) ;
* V_31 = 1 ;
V_141:
F_60 ( V_6 , V_119 ) ;
V_140:
F_22 ( V_6 -> V_12 , V_15 ) ;
V_139:
F_22 ( V_6 -> V_12 , V_50 ) ;
return V_106 ;
}
static int F_79 ( struct V_3 * V_4 ,
struct V_117 * V_152 ,
struct V_29 * * V_30 , unsigned * V_31 )
{
struct V_5 * V_6 ;
const char * * V_38 ;
int V_76 ;
V_6 = F_14 ( V_4 ) ;
* V_30 = F_54 ( V_6 -> V_12 , sizeof( * * V_30 ) * 2 , V_115 ) ;
if ( ! * V_30 )
return - V_104 ;
* V_31 = 0 ;
V_38 = F_54 ( V_6 -> V_12 , sizeof( * V_38 ) , V_115 ) ;
if ( ! V_38 ) {
V_76 = - V_104 ;
goto V_153;
}
if ( V_6 -> V_54 ) {
V_76 = F_77 ( V_6 , V_152 , V_30 ,
V_31 , V_38 ) ;
if ( V_76 < 0 ) {
F_17 ( V_6 -> V_12 , L_29 ,
V_152 -> V_14 ) ;
goto V_154;
}
} else {
V_76 = F_73 ( V_6 , V_152 , V_30 ,
V_31 , V_38 ) ;
if ( V_76 < 0 ) {
F_17 ( V_6 -> V_12 , L_29 ,
V_152 -> V_14 ) ;
goto V_154;
}
}
return 0 ;
V_154:
F_22 ( V_6 -> V_12 , V_38 ) ;
V_153:
F_22 ( V_6 -> V_12 , * V_30 ) ;
return V_76 ;
}
static void F_80 ( struct V_5 * V_6 )
{
struct V_63 * V_64 , * V_65 ;
int V_46 ;
F_56 ( & V_6 -> V_120 ) ;
for ( V_46 = 0 ; V_46 < V_6 -> V_32 ; V_46 ++ ) {
struct V_34 * V_35 ;
V_35 = F_16 ( & V_6 -> V_36 , V_46 ) ;
if ( ! V_35 )
continue;
F_61 ( & V_6 -> V_36 , V_46 ) ;
}
F_34 (pos, tmp, &pcs->functions) {
struct V_34 * V_119 ;
V_119 = F_35 ( V_64 , struct V_34 , V_67 ) ;
F_62 ( & V_119 -> V_67 ) ;
}
F_59 ( & V_6 -> V_120 ) ;
}
static void F_76 ( struct V_5 * V_6 )
{
struct V_63 * V_64 , * V_65 ;
int V_46 ;
F_56 ( & V_6 -> V_120 ) ;
for ( V_46 = 0 ; V_46 < V_6 -> V_7 ; V_46 ++ ) {
struct V_9 * V_123 ;
V_123 = F_16 ( & V_6 -> V_11 , V_46 ) ;
if ( ! V_123 )
continue;
F_61 ( & V_6 -> V_11 , V_46 ) ;
}
F_34 (pos, tmp, &pcs->pingroups) {
struct V_9 * V_123 ;
V_123 = F_35 ( V_64 , struct V_9 , V_67 ) ;
F_62 ( & V_123 -> V_67 ) ;
}
F_59 ( & V_6 -> V_120 ) ;
}
static void F_81 ( struct V_5 * V_6 )
{
struct V_96 * V_97 = & V_6 -> V_98 ;
if ( V_97 -> V_155 < 0 )
return;
if ( V_6 -> V_156 )
F_82 ( V_6 -> V_156 ) ;
if ( V_157 )
F_83 ( V_97 -> V_155 , V_97 ) ;
else
F_84 ( V_97 -> V_155 , NULL ) ;
}
static void F_85 ( struct V_5 * V_6 )
{
F_81 ( V_6 ) ;
if ( V_6 -> V_158 )
F_86 ( V_6 -> V_158 ) ;
F_80 ( V_6 ) ;
F_76 ( V_6 ) ;
}
static int F_87 ( struct V_117 * V_67 , struct V_5 * V_6 )
{
const char * V_159 = L_30 ;
const char * V_160 = L_31 ;
struct V_161 V_162 ;
struct V_61 * V_60 ;
int V_76 , V_46 ;
for ( V_46 = 0 ; ; V_46 ++ ) {
V_76 = F_88 ( V_67 , V_159 , V_160 ,
V_46 , & V_162 ) ;
if ( V_76 ) {
V_76 = 0 ;
break;
}
V_60 = F_54 ( V_6 -> V_12 , sizeof( * V_60 ) , V_115 ) ;
if ( ! V_60 ) {
V_76 = - V_104 ;
break;
}
V_60 -> V_68 = V_162 . args [ 0 ] ;
V_60 -> V_16 = V_162 . args [ 1 ] ;
V_60 -> V_69 = V_162 . args [ 2 ] ;
F_56 ( & V_6 -> V_120 ) ;
F_57 ( & V_60 -> V_67 , & V_6 -> V_163 ) ;
F_59 ( & V_6 -> V_120 ) ;
}
return V_76 ;
}
static inline void F_89 ( struct V_96 * V_97 ,
int V_155 , const bool V_83 )
{
struct V_5 * V_6 ;
struct V_63 * V_64 ;
unsigned V_52 ;
V_6 = F_90 ( V_97 , struct V_5 , V_98 ) ;
F_91 (pos, &pcs->irqs) {
struct V_164 * V_165 ;
unsigned V_166 ;
V_165 = F_35 ( V_64 , struct V_164 , V_67 ) ;
if ( V_155 != V_165 -> V_155 )
continue;
V_166 = V_97 -> V_105 ;
F_92 ( & V_6 -> V_53 ) ;
V_52 = V_6 -> V_26 ( V_165 -> V_1 ) ;
if ( V_83 )
V_52 |= V_166 ;
else
V_52 &= ~ V_166 ;
V_6 -> V_55 ( V_52 , V_165 -> V_1 ) ;
F_93 ( & V_6 -> V_53 ) ;
}
if ( V_97 -> V_167 )
V_97 -> V_167 () ;
}
static void F_94 ( struct V_168 * V_169 )
{
struct V_96 * V_97 = F_95 ( V_169 ) ;
F_89 ( V_97 , V_169 -> V_155 , false ) ;
}
static void F_96 ( struct V_168 * V_169 )
{
struct V_96 * V_97 = F_95 ( V_169 ) ;
F_89 ( V_97 , V_169 -> V_155 , true ) ;
}
static int F_97 ( struct V_168 * V_169 , unsigned int V_170 )
{
if ( V_170 )
F_96 ( V_169 ) ;
else
F_94 ( V_169 ) ;
return 0 ;
}
static int F_98 ( struct V_96 * V_97 )
{
struct V_5 * V_6 ;
struct V_63 * V_64 ;
int V_171 = 0 ;
V_6 = F_90 ( V_97 , struct V_5 , V_98 ) ;
F_91 (pos, &pcs->irqs) {
struct V_164 * V_165 ;
unsigned V_52 ;
V_165 = F_35 ( V_64 , struct V_164 , V_67 ) ;
F_92 ( & V_6 -> V_53 ) ;
V_52 = V_6 -> V_26 ( V_165 -> V_1 ) ;
F_93 ( & V_6 -> V_53 ) ;
if ( V_52 & V_97 -> V_172 ) {
F_99 ( F_100 ( V_6 -> V_156 ,
V_165 -> V_173 ) ) ;
V_171 ++ ;
}
}
return V_171 ;
}
static T_5 F_101 ( int V_155 , void * V_169 )
{
struct V_96 * V_97 = V_169 ;
return F_98 ( V_97 ) ? V_174 : V_175 ;
}
static void F_102 ( unsigned int V_155 , struct V_176 * V_103 )
{
struct V_96 * V_97 = F_103 ( V_103 ) ;
struct V_177 * V_178 ;
int V_106 ;
V_178 = F_104 ( V_155 ) ;
F_105 ( V_178 , V_103 ) ;
V_106 = F_98 ( V_97 ) ;
F_106 ( V_178 , V_103 ) ;
return;
}
static int F_107 ( struct V_179 * V_169 , unsigned int V_155 ,
T_6 V_173 )
{
struct V_96 * V_97 = V_169 -> V_180 ;
struct V_5 * V_6 ;
struct V_164 * V_165 ;
V_6 = F_90 ( V_97 , struct V_5 , V_98 ) ;
V_165 = F_54 ( V_6 -> V_12 , sizeof( * V_165 ) , V_115 ) ;
if ( ! V_165 )
return - V_104 ;
V_165 -> V_1 = V_6 -> V_27 + V_173 ;
V_165 -> V_173 = V_173 ;
V_165 -> V_155 = V_155 ;
F_56 ( & V_6 -> V_120 ) ;
F_57 ( & V_165 -> V_67 , & V_6 -> V_181 ) ;
F_59 ( & V_6 -> V_120 ) ;
F_108 ( V_155 , V_97 ) ;
F_109 ( V_155 , & V_6 -> V_178 ,
V_182 ) ;
#ifdef F_110
F_111 ( V_155 , V_183 ) ;
#else
F_112 ( V_155 ) ;
#endif
return 0 ;
}
static int F_113 ( struct V_5 * V_6 ,
struct V_117 * V_118 )
{
struct V_96 * V_97 = & V_6 -> V_98 ;
const char * V_14 = L_32 ;
int V_184 ;
if ( ! V_97 -> V_105 ||
! V_97 -> V_172 ) {
V_97 -> V_155 = - 1 ;
return - V_17 ;
}
F_114 ( & V_6 -> V_181 ) ;
V_6 -> V_178 . V_14 = V_14 ;
V_6 -> V_178 . V_185 = F_94 ;
V_6 -> V_178 . V_186 = F_94 ;
V_6 -> V_178 . V_187 = F_96 ;
V_6 -> V_178 . V_188 = F_97 ;
if ( V_157 ) {
int V_106 ;
V_106 = F_115 ( V_97 -> V_155 , F_101 ,
V_189 | V_190 ,
V_14 , V_97 ) ;
if ( V_106 ) {
V_97 -> V_155 = - 1 ;
return V_106 ;
}
} else {
F_116 ( V_97 -> V_155 , V_97 ) ;
F_84 ( V_97 -> V_155 ,
F_102 ) ;
}
V_184 = V_6 -> V_114 ;
V_6 -> V_156 = F_117 ( V_118 , V_184 , 0 ,
& V_191 ,
V_97 ) ;
if ( ! V_6 -> V_156 ) {
F_84 ( V_97 -> V_155 , NULL ) ;
return - V_17 ;
}
return 0 ;
}
static int F_118 ( struct V_192 * V_193 ,
T_7 V_170 )
{
struct V_5 * V_6 ;
V_6 = F_119 ( V_193 ) ;
if ( ! V_6 )
return - V_17 ;
return F_120 ( V_6 -> V_158 ) ;
}
static int F_121 ( struct V_192 * V_193 )
{
struct V_5 * V_6 ;
V_6 = F_119 ( V_193 ) ;
if ( ! V_6 )
return - V_17 ;
return F_122 ( V_6 -> V_158 ) ;
}
static int F_123 ( struct V_192 * V_193 )
{
struct V_117 * V_118 = V_193 -> V_12 . V_194 ;
const struct V_195 * V_196 ;
struct V_197 * V_198 ;
struct V_199 * V_106 ;
struct V_5 * V_6 ;
const struct V_96 * V_200 ;
int V_76 ;
V_196 = F_124 ( V_201 , & V_193 -> V_12 ) ;
if ( ! V_196 )
return - V_17 ;
V_6 = F_54 ( & V_193 -> V_12 , sizeof( * V_6 ) , V_115 ) ;
if ( ! V_6 ) {
F_17 ( & V_193 -> V_12 , L_33 ) ;
return - V_104 ;
}
V_6 -> V_12 = & V_193 -> V_12 ;
F_125 ( & V_6 -> V_53 ) ;
F_126 ( & V_6 -> V_120 ) ;
F_114 ( & V_6 -> V_124 ) ;
F_114 ( & V_6 -> V_121 ) ;
F_114 ( & V_6 -> V_163 ) ;
V_200 = V_196 -> V_66 ;
V_6 -> V_51 = V_200 -> V_51 ;
memcpy ( & V_6 -> V_98 , V_200 , sizeof( * V_200 ) ) ;
F_127 ( L_34 , & V_6 -> V_24 ,
L_35 ) ;
V_76 = F_128 ( V_118 , L_36 ,
& V_6 -> V_47 ) ;
if ( ! V_76 ) {
V_6 -> V_58 = F_44 ( V_6 -> V_47 ) - 1 ;
V_6 -> V_202 = V_6 -> V_47 >> V_6 -> V_58 ;
} else {
V_6 -> V_47 = 0 ;
V_6 -> V_58 = 0 ;
V_6 -> V_202 = 0 ;
}
V_76 = F_128 ( V_118 , L_37 ,
& V_6 -> V_56 ) ;
if ( V_76 )
V_6 -> V_56 = V_57 ;
V_6 -> V_54 = F_129 ( V_118 ,
L_38 ) ;
V_106 = F_130 ( V_193 , V_203 , 0 ) ;
if ( ! V_106 ) {
F_17 ( V_6 -> V_12 , L_39 ) ;
return - V_204 ;
}
V_6 -> V_106 = F_131 ( V_6 -> V_12 , V_106 -> V_107 ,
F_132 ( V_106 ) , V_28 ) ;
if ( ! V_6 -> V_106 ) {
F_17 ( V_6 -> V_12 , L_40 ) ;
return - V_205 ;
}
V_6 -> V_114 = F_132 ( V_6 -> V_106 ) ;
V_6 -> V_27 = F_133 ( V_6 -> V_12 , V_6 -> V_106 -> V_107 , V_6 -> V_114 ) ;
if ( ! V_6 -> V_27 ) {
F_17 ( V_6 -> V_12 , L_41 ) ;
return - V_204 ;
}
F_134 ( & V_6 -> V_11 , V_115 ) ;
F_134 ( & V_6 -> V_36 , V_115 ) ;
F_135 ( V_193 , V_6 ) ;
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
V_6 -> V_103 . V_14 = V_28 ;
V_6 -> V_103 . V_206 = & V_207 ;
V_6 -> V_103 . V_208 = & V_209 ;
if ( V_133 )
V_6 -> V_103 . V_210 = & V_211 ;
V_6 -> V_103 . V_212 = V_213 ;
V_76 = F_52 ( V_6 ) ;
if ( V_76 < 0 )
goto free;
V_6 -> V_158 = F_136 ( & V_6 -> V_103 , V_6 -> V_12 , V_6 ) ;
if ( ! V_6 -> V_158 ) {
F_17 ( V_6 -> V_12 , L_42 ) ;
V_76 = - V_17 ;
goto free;
}
V_76 = F_87 ( V_118 , V_6 ) ;
if ( V_76 < 0 )
goto free;
V_6 -> V_98 . V_155 = F_137 ( V_118 , 0 ) ;
if ( V_6 -> V_98 . V_155 )
V_6 -> V_51 |= V_214 ;
V_198 = F_138 ( & V_193 -> V_12 ) ;
if ( V_198 ) {
if ( V_198 -> V_167 )
V_6 -> V_98 . V_167 = V_198 -> V_167 ;
if ( V_198 -> V_155 ) {
V_6 -> V_98 . V_155 = V_198 -> V_155 ;
V_6 -> V_51 |= V_214 ;
}
}
if ( V_215 ) {
V_76 = F_113 ( V_6 , V_118 ) ;
if ( V_76 < 0 )
F_78 ( V_6 -> V_12 , L_43 ) ;
}
F_139 ( V_6 -> V_12 , L_44 ,
V_6 -> V_103 . V_16 , V_6 -> V_27 , V_6 -> V_114 ) ;
return 0 ;
free:
F_85 ( V_6 ) ;
return V_76 ;
}
static int F_140 ( struct V_192 * V_193 )
{
struct V_5 * V_6 = F_119 ( V_193 ) ;
if ( ! V_6 )
return 0 ;
F_85 ( V_6 ) ;
return 0 ;
}
