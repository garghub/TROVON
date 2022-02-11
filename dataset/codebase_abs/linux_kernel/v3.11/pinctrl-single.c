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
if ( V_6 -> V_52 )
V_51 = V_50 -> V_51 ;
else
V_51 = V_6 -> V_47 ;
V_2 &= ~ V_51 ;
V_2 |= ( V_50 -> V_2 & V_51 ) ;
V_6 -> V_53 ( V_2 , V_50 -> V_1 ) ;
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
if ( V_6 -> V_54 == V_55 ) {
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
V_2 |= V_6 -> V_54 << V_6 -> V_56 ;
V_6 -> V_53 ( V_2 , V_50 -> V_1 ) ;
}
}
static int F_31 ( struct V_3 * V_4 ,
struct V_57 * V_58 , unsigned V_22 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
struct V_59 * V_60 = NULL ;
struct V_61 * V_62 , * V_63 ;
int V_23 = 0 ;
unsigned V_64 ;
if ( ! V_6 -> V_47 )
return - V_45 ;
F_32 (pos, tmp, &pcs->gpiofuncs) {
V_60 = F_33 ( V_62 , struct V_59 , V_65 ) ;
if ( V_22 >= V_60 -> V_66 + V_60 -> V_16
|| V_22 < V_60 -> V_66 )
continue;
V_23 = V_6 -> V_24 / V_25 ;
V_64 = V_6 -> V_26 ( V_6 -> V_27 + V_22 * V_23 ) & ~ V_6 -> V_47 ;
V_64 |= V_60 -> V_67 ;
V_6 -> V_53 ( V_64 , V_6 -> V_27 + V_22 * V_23 ) ;
break;
}
return 0 ;
}
static void F_34 ( struct V_3 * V_4 , unsigned V_22 )
{
unsigned long V_68 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_35 ( V_69 ) ; V_46 ++ ) {
V_68 = F_36 ( V_69 [ V_46 ] , 0 ) ;
F_37 ( V_4 , V_22 , V_68 ) ;
}
}
static bool F_38 ( struct V_3 * V_4 , unsigned V_22 )
{
unsigned long V_68 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_35 ( V_69 ) ; V_46 ++ ) {
V_68 = F_36 ( V_69 [ V_46 ] , 0 ) ;
if ( ! F_39 ( V_4 , V_22 , & V_68 ) )
goto V_70;
}
return true ;
V_70:
return false ;
}
static int F_39 ( struct V_3 * V_4 ,
unsigned V_22 , unsigned long * V_68 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
struct V_34 * V_35 ;
enum V_71 V_72 ;
unsigned V_66 = 0 , V_64 = 0 , V_46 , V_73 , V_74 ;
V_74 = F_26 ( V_4 , V_22 , & V_35 ) ;
if ( V_74 )
return V_74 ;
for ( V_46 = 0 ; V_46 < V_35 -> V_75 ; V_46 ++ ) {
V_72 = F_40 ( * V_68 ) ;
if ( V_72 == V_76 ) {
if ( F_38 ( V_4 , V_22 ) ) {
* V_68 = 0 ;
return 0 ;
} else {
return - V_45 ;
}
} else if ( V_72 != V_35 -> V_77 [ V_46 ] . V_72 ) {
continue;
}
V_66 = V_22 * ( V_6 -> V_24 / V_25 ) ;
V_64 = V_6 -> V_26 ( V_6 -> V_27 + V_66 ) & V_35 -> V_77 [ V_46 ] . V_51 ;
switch ( V_35 -> V_77 [ V_46 ] . V_72 ) {
case V_78 :
case V_79 :
case V_80 :
if ( ( V_64 != V_35 -> V_77 [ V_46 ] . V_81 ) ||
( V_64 == V_35 -> V_77 [ V_46 ] . V_82 ) )
return - V_45 ;
* V_68 = 0 ;
break;
case V_83 :
for ( V_73 = 0 ; V_73 < V_35 -> V_75 ; V_73 ++ ) {
switch ( V_35 -> V_77 [ V_73 ] . V_72 ) {
case V_80 :
if ( V_64 != V_35 -> V_77 [ V_73 ] . V_81 )
return - V_45 ;
break;
default:
break;
}
}
* V_68 = V_64 ;
break;
case V_84 :
case V_85 :
default:
* V_68 = V_64 ;
break;
}
return 0 ;
}
return - V_45 ;
}
static int F_37 ( struct V_3 * V_4 ,
unsigned V_22 , unsigned long V_68 )
{
struct V_5 * V_6 = F_14 ( V_4 ) ;
struct V_34 * V_35 ;
unsigned V_66 = 0 , V_86 = 0 , V_46 , V_64 , V_74 ;
T_3 V_87 ;
V_74 = F_26 ( V_4 , V_22 , & V_35 ) ;
if ( V_74 )
return V_74 ;
for ( V_46 = 0 ; V_46 < V_35 -> V_75 ; V_46 ++ ) {
if ( F_40 ( V_68 ) == V_35 -> V_77 [ V_46 ] . V_72 ) {
V_66 = V_22 * ( V_6 -> V_24 / V_25 ) ;
V_64 = V_6 -> V_26 ( V_6 -> V_27 + V_66 ) ;
V_87 = F_41 ( V_68 ) ;
switch ( V_35 -> V_77 [ V_46 ] . V_72 ) {
case V_83 :
case V_84 :
case V_85 :
V_86 = F_42 ( V_35 -> V_77 [ V_46 ] . V_51 ) - 1 ;
V_64 &= ~ V_35 -> V_77 [ V_46 ] . V_51 ;
V_64 |= ( V_87 << V_86 ) & V_35 -> V_77 [ V_46 ] . V_51 ;
break;
case V_76 :
F_34 ( V_4 , V_22 ) ;
break;
case V_78 :
case V_79 :
if ( V_87 )
F_34 ( V_4 , V_22 ) ;
case V_80 :
V_64 &= ~ V_35 -> V_77 [ V_46 ] . V_51 ;
if ( V_87 )
V_64 |= V_35 -> V_77 [ V_46 ] . V_81 ;
else
V_64 |= V_35 -> V_77 [ V_46 ] . V_82 ;
break;
default:
return - V_45 ;
}
V_6 -> V_53 ( V_64 , V_6 -> V_27 + V_66 ) ;
return 0 ;
}
}
return - V_45 ;
}
static int F_43 ( struct V_3 * V_4 ,
unsigned V_10 , unsigned long * V_68 )
{
const unsigned * V_15 ;
unsigned V_16 , V_88 = 0 ;
int V_46 , V_74 ;
V_74 = F_18 ( V_4 , V_10 , & V_15 , & V_16 ) ;
if ( V_74 )
return V_74 ;
for ( V_46 = 0 ; V_46 < V_16 ; V_46 ++ ) {
if ( F_39 ( V_4 , V_15 [ V_46 ] , V_68 ) )
return - V_45 ;
if ( V_46 && ( V_88 != * V_68 ) )
return - V_45 ;
V_88 = * V_68 ;
}
return 0 ;
}
static int F_44 ( struct V_3 * V_4 ,
unsigned V_10 , unsigned long V_68 )
{
const unsigned * V_15 ;
unsigned V_16 ;
int V_46 , V_74 ;
V_74 = F_18 ( V_4 , V_10 , & V_15 , & V_16 ) ;
if ( V_74 )
return V_74 ;
for ( V_46 = 0 ; V_46 < V_16 ; V_46 ++ ) {
if ( F_37 ( V_4 , V_15 [ V_46 ] , V_68 ) )
return - V_45 ;
}
return 0 ;
}
static void F_45 ( struct V_3 * V_4 ,
struct V_20 * V_21 , unsigned V_22 )
{
}
static void F_46 ( struct V_3 * V_4 ,
struct V_20 * V_21 , unsigned V_89 )
{
}
static void F_47 ( struct V_3 * V_4 ,
struct V_20 * V_21 ,
unsigned long V_68 )
{
F_48 ( V_4 , V_21 , V_68 ) ;
}
static int F_49 ( struct V_5 * V_6 , unsigned V_66 ,
unsigned V_90 )
{
struct V_91 * V_22 ;
struct V_92 * V_93 ;
int V_46 ;
V_46 = V_6 -> V_15 . V_94 ;
if ( V_46 >= V_6 -> V_95 . V_16 ) {
F_17 ( V_6 -> V_12 , L_7 ,
V_6 -> V_95 . V_16 ) ;
return - V_96 ;
}
V_22 = & V_6 -> V_15 . V_97 [ V_46 ] ;
V_93 = & V_6 -> V_98 [ V_46 ] ;
sprintf ( V_93 -> V_14 , L_8 ,
( unsigned long ) V_6 -> V_99 -> V_100 + V_66 , V_90 ) ;
V_22 -> V_14 = V_93 -> V_14 ;
V_22 -> V_101 = V_46 ;
V_6 -> V_15 . V_94 ++ ;
return V_46 ;
}
static int F_50 ( struct V_5 * V_6 )
{
int V_23 , V_102 , V_46 ;
int V_103 = 0 ;
V_23 = V_6 -> V_24 / V_25 ;
if ( V_6 -> V_52 ) {
V_6 -> V_104 = F_51 ( V_6 -> V_47 ) ;
V_102 = ( V_6 -> V_105 * V_25 ) / V_6 -> V_104 ;
V_103 = V_6 -> V_24 / V_6 -> V_104 ;
} else {
V_102 = V_6 -> V_105 / V_23 ;
}
F_29 ( V_6 -> V_12 , L_9 , V_102 ) ;
V_6 -> V_15 . V_97 = F_52 ( V_6 -> V_12 ,
sizeof( * V_6 -> V_15 . V_97 ) * V_102 ,
V_106 ) ;
if ( ! V_6 -> V_15 . V_97 )
return - V_96 ;
V_6 -> V_98 = F_52 ( V_6 -> V_12 ,
sizeof( struct V_92 ) * V_102 ,
V_106 ) ;
if ( ! V_6 -> V_98 )
return - V_96 ;
V_6 -> V_95 . V_15 = V_6 -> V_15 . V_97 ;
V_6 -> V_95 . V_16 = V_102 ;
for ( V_46 = 0 ; V_46 < V_6 -> V_95 . V_16 ; V_46 ++ ) {
unsigned V_66 ;
int V_99 ;
int V_107 ;
int V_90 = 0 ;
if ( V_6 -> V_52 ) {
V_107 = ( V_6 -> V_104 * V_46 ) / V_25 ;
V_66 = ( V_107 / V_23 ) * V_23 ;
V_90 = V_46 % V_103 ;
} else {
V_66 = V_46 * V_23 ;
}
V_99 = F_49 ( V_6 , V_66 , V_90 ) ;
if ( V_99 < 0 ) {
F_17 ( V_6 -> V_12 , L_10 , V_99 ) ;
return V_99 ;
}
}
return 0 ;
}
static struct V_34 * F_53 ( struct V_5 * V_6 ,
struct V_108 * V_109 ,
const char * V_14 ,
struct V_49 * V_50 ,
unsigned V_48 ,
const char * * V_38 ,
unsigned V_39 )
{
struct V_34 * V_110 ;
V_110 = F_52 ( V_6 -> V_12 , sizeof( * V_110 ) , V_106 ) ;
if ( ! V_110 )
return NULL ;
V_110 -> V_14 = V_14 ;
V_110 -> V_50 = V_50 ;
V_110 -> V_48 = V_48 ;
V_110 -> V_38 = V_38 ;
V_110 -> V_39 = V_39 ;
F_54 ( & V_6 -> V_111 ) ;
F_55 ( & V_110 -> V_65 , & V_6 -> V_112 ) ;
F_56 ( & V_6 -> V_36 , V_6 -> V_32 , V_110 ) ;
V_6 -> V_32 ++ ;
F_57 ( & V_6 -> V_111 ) ;
return V_110 ;
}
static void F_58 ( struct V_5 * V_6 ,
struct V_34 * V_110 )
{
int V_46 ;
F_54 ( & V_6 -> V_111 ) ;
for ( V_46 = 0 ; V_46 < V_6 -> V_32 ; V_46 ++ ) {
struct V_34 * V_113 ;
V_113 = F_16 ( & V_6 -> V_36 , V_46 ) ;
if ( V_113 == V_110 )
F_59 ( & V_6 -> V_36 , V_46 ) ;
}
F_60 ( & V_110 -> V_65 ) ;
F_57 ( & V_6 -> V_111 ) ;
}
static int F_61 ( struct V_5 * V_6 ,
struct V_108 * V_109 ,
const char * V_14 ,
int * V_18 ,
int V_19 )
{
struct V_9 * V_114 ;
V_114 = F_52 ( V_6 -> V_12 , sizeof( * V_114 ) , V_106 ) ;
if ( ! V_114 )
return - V_96 ;
V_114 -> V_14 = V_14 ;
V_114 -> V_109 = V_109 ;
V_114 -> V_18 = V_18 ;
V_114 -> V_19 = V_19 ;
F_54 ( & V_6 -> V_111 ) ;
F_55 ( & V_114 -> V_65 , & V_6 -> V_115 ) ;
F_56 ( & V_6 -> V_11 , V_6 -> V_7 , V_114 ) ;
V_6 -> V_7 ++ ;
F_57 ( & V_6 -> V_111 ) ;
return 0 ;
}
static int F_62 ( struct V_5 * V_6 , unsigned V_66 )
{
unsigned V_116 ;
if ( V_66 >= V_6 -> V_105 ) {
F_17 ( V_6 -> V_12 , L_11 ,
V_66 , V_6 -> V_105 ) ;
return - V_17 ;
}
if ( V_6 -> V_52 )
V_116 = ( V_66 * V_25 ) / V_6 -> V_104 ;
else
V_116 = V_66 / ( V_6 -> V_24 / V_25 ) ;
return V_116 ;
}
static int F_63 ( unsigned V_64 , unsigned V_81 , unsigned V_82 )
{
int V_74 = - V_17 ;
if ( V_64 == V_81 )
V_74 = 1 ;
else if ( V_64 == V_82 )
V_74 = 0 ;
return V_74 ;
}
static void F_64 ( struct V_117 * * V_77 , enum V_71 V_72 ,
unsigned V_118 , unsigned V_81 , unsigned V_82 ,
unsigned V_51 )
{
( * V_77 ) -> V_72 = V_72 ;
( * V_77 ) -> V_2 = V_118 ;
( * V_77 ) -> V_81 = V_81 ;
( * V_77 ) -> V_82 = V_82 ;
( * V_77 ) -> V_51 = V_51 ;
( * V_77 ) ++ ;
}
static void F_65 ( unsigned long * * V_43 , enum V_71 V_72 ,
unsigned V_87 )
{
* * V_43 = F_36 ( V_72 , V_87 ) ;
( * V_43 ) ++ ;
}
static void F_66 ( struct V_5 * V_6 , struct V_108 * V_109 ,
const char * V_14 , enum V_71 V_72 ,
struct V_117 * * V_77 , unsigned long * * V_119 )
{
unsigned V_118 [ 2 ] , V_86 ;
int V_74 ;
V_74 = F_67 ( V_109 , V_14 , V_118 , 2 ) ;
if ( V_74 )
return;
V_118 [ 0 ] &= V_118 [ 1 ] ;
V_86 = F_42 ( V_118 [ 1 ] ) - 1 ;
F_64 ( V_77 , V_72 , V_118 [ 0 ] , 0 , 0 , V_118 [ 1 ] ) ;
F_65 ( V_119 , V_72 , V_118 [ 0 ] >> V_86 ) ;
}
static void F_68 ( struct V_5 * V_6 , struct V_108 * V_109 ,
const char * V_14 , enum V_71 V_72 ,
struct V_117 * * V_77 , unsigned long * * V_119 )
{
unsigned V_118 [ 4 ] ;
int V_74 ;
V_74 = F_67 ( V_109 , V_14 , V_118 , 4 ) ;
if ( V_74 )
return;
if ( ! V_118 [ 3 ] ) {
F_17 ( V_6 -> V_12 , L_12 ) ;
return;
}
V_118 [ 0 ] &= V_118 [ 3 ] ;
V_118 [ 1 ] &= V_118 [ 3 ] ;
V_118 [ 2 ] &= V_118 [ 3 ] ;
V_74 = F_63 ( V_118 [ 0 ] , V_118 [ 1 ] , V_118 [ 2 ] ) ;
if ( V_74 < 0 )
F_29 ( V_6 -> V_12 , L_13 ) ;
F_64 ( V_77 , V_72 , V_118 [ 0 ] , V_118 [ 1 ] , V_118 [ 2 ] , V_118 [ 3 ] ) ;
F_65 ( V_119 , V_72 , V_74 ) ;
}
static int F_69 ( struct V_5 * V_6 , struct V_108 * V_109 ,
struct V_34 * V_35 ,
struct V_29 * * V_30 )
{
struct V_29 * V_120 = * V_30 ;
int V_46 = 0 , V_75 = 0 ;
unsigned long * V_119 = NULL , * V_21 = NULL ;
struct V_117 * V_77 = NULL ;
struct V_121 V_122 [] = {
{ L_14 , V_84 , } ,
{ L_15 , V_85 , } ,
{ L_16 , V_83 , } ,
} ;
struct V_121 V_123 [] = {
{ L_17 , V_79 , } ,
{ L_18 , V_78 , } ,
{ L_19 ,
V_80 , } ,
} ;
if ( ! V_6 -> V_124 )
return 0 ;
for ( V_46 = 0 ; V_46 < F_35 ( V_122 ) ; V_46 ++ ) {
if ( F_70 ( V_109 , V_122 [ V_46 ] . V_14 , NULL ) )
V_75 ++ ;
}
for ( V_46 = 0 ; V_46 < F_35 ( V_123 ) ; V_46 ++ ) {
if ( F_70 ( V_109 , V_123 [ V_46 ] . V_14 , NULL ) )
V_75 ++ ;
}
if ( ! V_75 )
return 0 ;
V_35 -> V_77 = F_52 ( V_6 -> V_12 ,
sizeof( struct V_117 ) * V_75 ,
V_106 ) ;
if ( ! V_35 -> V_77 )
return - V_96 ;
V_35 -> V_75 = V_75 ;
V_77 = & ( V_35 -> V_77 [ 0 ] ) ;
V_120 ++ ;
V_119 = F_52 ( V_6 -> V_12 , sizeof( unsigned long ) * V_75 ,
V_106 ) ;
if ( ! V_119 )
return - V_96 ;
V_21 = & V_119 [ 0 ] ;
for ( V_46 = 0 ; V_46 < F_35 ( V_122 ) ; V_46 ++ )
F_66 ( V_6 , V_109 , V_122 [ V_46 ] . V_14 , V_122 [ V_46 ] . V_72 ,
& V_77 , & V_21 ) ;
for ( V_46 = 0 ; V_46 < F_35 ( V_123 ) ; V_46 ++ )
F_68 ( V_6 , V_109 , V_123 [ V_46 ] . V_14 , V_123 [ V_46 ] . V_72 ,
& V_77 , & V_21 ) ;
V_120 -> type = V_125 ;
V_120 -> V_64 . V_126 . V_127 = V_109 -> V_14 ;
V_120 -> V_64 . V_126 . V_126 = V_119 ;
V_120 -> V_64 . V_126 . V_128 = V_75 ;
return 0 ;
}
static int F_71 ( struct V_5 * V_6 ,
struct V_108 * V_109 ,
struct V_29 * * V_30 ,
unsigned * V_31 ,
const char * * V_38 )
{
struct V_49 * V_50 ;
const T_4 * V_129 ;
int V_105 , V_130 , * V_15 , V_116 = 0 , V_113 = 0 , V_99 = - V_96 ;
struct V_34 * V_110 ;
V_129 = F_72 ( V_109 , V_131 , & V_105 ) ;
if ( ( ! V_129 ) || ( V_105 < sizeof( * V_129 ) * 2 ) ) {
F_17 ( V_6 -> V_12 , L_20 ,
V_109 -> V_14 ) ;
return - V_17 ;
}
V_105 /= sizeof( * V_129 ) ;
V_130 = V_105 / 2 ;
V_50 = F_52 ( V_6 -> V_12 , sizeof( * V_50 ) * V_130 , V_106 ) ;
if ( ! V_50 )
return - V_96 ;
V_15 = F_52 ( V_6 -> V_12 , sizeof( * V_15 ) * V_130 , V_106 ) ;
if ( ! V_15 )
goto V_132;
while ( V_116 < V_105 ) {
unsigned V_66 , V_2 ;
int V_22 ;
V_66 = F_73 ( V_129 + V_116 ++ ) ;
V_2 = F_73 ( V_129 + V_116 ++ ) ;
V_50 [ V_113 ] . V_1 = V_6 -> V_27 + V_66 ;
V_50 [ V_113 ] . V_2 = V_2 ;
V_22 = F_62 ( V_6 , V_66 ) ;
if ( V_22 < 0 ) {
F_17 ( V_6 -> V_12 ,
L_21 ,
V_109 -> V_14 , V_66 ) ;
break;
}
V_15 [ V_113 ++ ] = V_22 ;
}
V_38 [ 0 ] = V_109 -> V_14 ;
V_110 = F_53 ( V_6 , V_109 , V_109 -> V_14 , V_50 , V_113 , V_38 , 1 ) ;
if ( ! V_110 )
goto V_133;
V_99 = F_61 ( V_6 , V_109 , V_109 -> V_14 , V_15 , V_113 ) ;
if ( V_99 < 0 )
goto V_134;
( * V_30 ) -> type = V_135 ;
( * V_30 ) -> V_64 . V_129 . V_10 = V_109 -> V_14 ;
( * V_30 ) -> V_64 . V_129 . V_110 = V_109 -> V_14 ;
if ( V_6 -> V_124 ) {
V_99 = F_69 ( V_6 , V_109 , V_110 , V_30 ) ;
if ( V_99 )
goto V_136;
* V_31 = 2 ;
} else {
* V_31 = 1 ;
}
return 0 ;
V_136:
F_74 ( V_6 ) ;
* V_31 = 1 ;
V_134:
F_58 ( V_6 , V_110 ) ;
V_133:
F_22 ( V_6 -> V_12 , V_15 ) ;
V_132:
F_22 ( V_6 -> V_12 , V_50 ) ;
return V_99 ;
}
static int F_75 ( struct V_5 * V_6 ,
struct V_108 * V_109 ,
struct V_29 * * V_30 ,
unsigned * V_31 ,
const char * * V_38 )
{
struct V_49 * V_50 ;
const T_4 * V_129 ;
int V_105 , V_130 , * V_15 , V_116 = 0 , V_113 = 0 , V_99 = - V_96 ;
int V_137 ;
struct V_34 * V_110 ;
V_129 = F_72 ( V_109 , V_138 , & V_105 ) ;
if ( ! V_129 ) {
F_17 ( V_6 -> V_12 , L_22 , V_109 -> V_14 ) ;
return - V_17 ;
}
if ( V_105 < ( sizeof( * V_129 ) * V_139 ) ) {
F_17 ( V_6 -> V_12 , L_23 , V_109 -> V_14 ) ;
return - V_17 ;
}
V_105 /= sizeof( * V_129 ) ;
V_130 = V_105 / V_139 ;
V_137 = V_6 -> V_24 / V_6 -> V_104 ;
V_50 = F_52 ( V_6 -> V_12 , sizeof( * V_50 ) * V_130 * V_137 ,
V_106 ) ;
if ( ! V_50 )
return - V_96 ;
V_15 = F_52 ( V_6 -> V_12 , sizeof( * V_15 ) * V_130 * V_137 ,
V_106 ) ;
if ( ! V_15 )
goto V_132;
while ( V_116 < V_105 ) {
unsigned V_66 , V_2 ;
unsigned V_51 , V_140 , V_141 , V_142 , V_143 ;
unsigned V_144 ;
int V_22 ;
V_66 = F_73 ( V_129 + V_116 ++ ) ;
V_2 = F_73 ( V_129 + V_116 ++ ) ;
V_51 = F_73 ( V_129 + V_116 ++ ) ;
while ( V_51 ) {
V_140 = F_42 ( V_51 ) ;
V_144 = V_140 / V_6 -> V_104 ;
V_142 = ( ( V_6 -> V_47 ) << ( V_140 - 1 ) ) ;
V_141 = V_2 & V_142 ;
V_143 = V_51 & V_142 ;
V_51 &= ~ V_142 ;
if ( V_143 != V_142 ) {
F_76 ( V_6 -> V_12 ,
L_24 ,
V_143 , V_109 -> V_14 , V_66 ) ;
continue;
}
V_50 [ V_113 ] . V_51 = V_143 ;
V_50 [ V_113 ] . V_1 = V_6 -> V_27 + V_66 ;
V_50 [ V_113 ] . V_2 = V_141 ;
V_22 = F_62 ( V_6 , V_66 ) ;
if ( V_22 < 0 ) {
F_17 ( V_6 -> V_12 ,
L_21 ,
V_109 -> V_14 , V_66 ) ;
break;
}
V_15 [ V_113 ++ ] = V_22 + V_144 ;
}
}
V_38 [ 0 ] = V_109 -> V_14 ;
V_110 = F_53 ( V_6 , V_109 , V_109 -> V_14 , V_50 , V_113 , V_38 , 1 ) ;
if ( ! V_110 )
goto V_133;
V_99 = F_61 ( V_6 , V_109 , V_109 -> V_14 , V_15 , V_113 ) ;
if ( V_99 < 0 )
goto V_134;
( * V_30 ) -> type = V_135 ;
( * V_30 ) -> V_64 . V_129 . V_10 = V_109 -> V_14 ;
( * V_30 ) -> V_64 . V_129 . V_110 = V_109 -> V_14 ;
if ( V_6 -> V_124 ) {
F_17 ( V_6 -> V_12 , L_25 ) ;
goto V_136;
}
* V_31 = 1 ;
return 0 ;
V_136:
F_74 ( V_6 ) ;
* V_31 = 1 ;
V_134:
F_58 ( V_6 , V_110 ) ;
V_133:
F_22 ( V_6 -> V_12 , V_15 ) ;
V_132:
F_22 ( V_6 -> V_12 , V_50 ) ;
return V_99 ;
}
static int F_77 ( struct V_3 * V_4 ,
struct V_108 * V_145 ,
struct V_29 * * V_30 , unsigned * V_31 )
{
struct V_5 * V_6 ;
const char * * V_38 ;
int V_74 ;
V_6 = F_14 ( V_4 ) ;
* V_30 = F_52 ( V_6 -> V_12 , sizeof( * * V_30 ) * 2 , V_106 ) ;
if ( ! * V_30 )
return - V_96 ;
* V_31 = 0 ;
V_38 = F_52 ( V_6 -> V_12 , sizeof( * V_38 ) , V_106 ) ;
if ( ! V_38 ) {
V_74 = - V_96 ;
goto V_146;
}
if ( V_6 -> V_52 ) {
V_74 = F_75 ( V_6 , V_145 , V_30 ,
V_31 , V_38 ) ;
if ( V_74 < 0 ) {
F_17 ( V_6 -> V_12 , L_26 ,
V_145 -> V_14 ) ;
goto V_147;
}
} else {
V_74 = F_71 ( V_6 , V_145 , V_30 ,
V_31 , V_38 ) ;
if ( V_74 < 0 ) {
F_17 ( V_6 -> V_12 , L_26 ,
V_145 -> V_14 ) ;
goto V_147;
}
}
return 0 ;
V_147:
F_22 ( V_6 -> V_12 , V_38 ) ;
V_146:
F_22 ( V_6 -> V_12 , * V_30 ) ;
return V_74 ;
}
static void F_78 ( struct V_5 * V_6 )
{
struct V_61 * V_62 , * V_63 ;
int V_46 ;
F_54 ( & V_6 -> V_111 ) ;
for ( V_46 = 0 ; V_46 < V_6 -> V_32 ; V_46 ++ ) {
struct V_34 * V_35 ;
V_35 = F_16 ( & V_6 -> V_36 , V_46 ) ;
if ( ! V_35 )
continue;
F_59 ( & V_6 -> V_36 , V_46 ) ;
}
F_32 (pos, tmp, &pcs->functions) {
struct V_34 * V_110 ;
V_110 = F_33 ( V_62 , struct V_34 , V_65 ) ;
F_60 ( & V_110 -> V_65 ) ;
}
F_57 ( & V_6 -> V_111 ) ;
}
static void F_74 ( struct V_5 * V_6 )
{
struct V_61 * V_62 , * V_63 ;
int V_46 ;
F_54 ( & V_6 -> V_111 ) ;
for ( V_46 = 0 ; V_46 < V_6 -> V_7 ; V_46 ++ ) {
struct V_9 * V_114 ;
V_114 = F_16 ( & V_6 -> V_11 , V_46 ) ;
if ( ! V_114 )
continue;
F_59 ( & V_6 -> V_11 , V_46 ) ;
}
F_32 (pos, tmp, &pcs->pingroups) {
struct V_9 * V_114 ;
V_114 = F_33 ( V_62 , struct V_9 , V_65 ) ;
F_60 ( & V_114 -> V_65 ) ;
}
F_57 ( & V_6 -> V_111 ) ;
}
static void F_79 ( struct V_5 * V_6 )
{
if ( V_6 -> V_148 )
F_80 ( V_6 -> V_148 ) ;
F_78 ( V_6 ) ;
F_74 ( V_6 ) ;
}
static int F_81 ( struct V_108 * V_65 , struct V_5 * V_6 )
{
const char * V_149 = L_27 ;
const char * V_150 = L_28 ;
struct V_151 V_152 ;
struct V_59 * V_58 ;
int V_74 , V_46 ;
for ( V_46 = 0 ; ; V_46 ++ ) {
V_74 = F_82 ( V_65 , V_149 , V_150 ,
V_46 , & V_152 ) ;
if ( V_74 ) {
V_74 = 0 ;
break;
}
V_58 = F_52 ( V_6 -> V_12 , sizeof( * V_58 ) , V_106 ) ;
if ( ! V_58 ) {
V_74 = - V_96 ;
break;
}
V_58 -> V_66 = V_152 . args [ 0 ] ;
V_58 -> V_16 = V_152 . args [ 1 ] ;
V_58 -> V_67 = V_152 . args [ 2 ] ;
F_54 ( & V_6 -> V_111 ) ;
F_55 ( & V_58 -> V_65 , & V_6 -> V_153 ) ;
F_57 ( & V_6 -> V_111 ) ;
}
return V_74 ;
}
static int F_83 ( struct V_154 * V_155 ,
T_5 V_156 )
{
struct V_5 * V_6 ;
V_6 = F_84 ( V_155 ) ;
if ( ! V_6 )
return - V_17 ;
return F_85 ( V_6 -> V_148 ) ;
}
static int F_86 ( struct V_154 * V_155 )
{
struct V_5 * V_6 ;
V_6 = F_84 ( V_155 ) ;
if ( ! V_6 )
return - V_17 ;
return F_87 ( V_6 -> V_148 ) ;
}
static int F_88 ( struct V_154 * V_155 )
{
struct V_108 * V_109 = V_155 -> V_12 . V_157 ;
const struct V_158 * V_159 ;
struct V_160 * V_99 ;
struct V_5 * V_6 ;
int V_74 ;
V_159 = F_89 ( V_161 , & V_155 -> V_12 ) ;
if ( ! V_159 )
return - V_17 ;
V_6 = F_52 ( & V_155 -> V_12 , sizeof( * V_6 ) , V_106 ) ;
if ( ! V_6 ) {
F_17 ( & V_155 -> V_12 , L_29 ) ;
return - V_96 ;
}
V_6 -> V_12 = & V_155 -> V_12 ;
F_90 ( & V_6 -> V_111 ) ;
F_91 ( & V_6 -> V_115 ) ;
F_91 ( & V_6 -> V_112 ) ;
F_91 ( & V_6 -> V_153 ) ;
V_6 -> V_124 = V_159 -> V_64 ;
F_92 ( L_30 , & V_6 -> V_24 ,
L_31 ) ;
V_74 = F_93 ( V_109 , L_32 ,
& V_6 -> V_47 ) ;
if ( ! V_74 ) {
V_6 -> V_56 = F_42 ( V_6 -> V_47 ) - 1 ;
V_6 -> V_162 = V_6 -> V_47 >> V_6 -> V_56 ;
} else {
V_6 -> V_47 = 0 ;
V_6 -> V_56 = 0 ;
V_6 -> V_162 = 0 ;
}
V_74 = F_93 ( V_109 , L_33 ,
& V_6 -> V_54 ) ;
if ( V_74 )
V_6 -> V_54 = V_55 ;
V_6 -> V_52 = F_94 ( V_109 ,
L_34 ) ;
V_99 = F_95 ( V_155 , V_163 , 0 ) ;
if ( ! V_99 ) {
F_17 ( V_6 -> V_12 , L_35 ) ;
return - V_164 ;
}
V_6 -> V_99 = F_96 ( V_6 -> V_12 , V_99 -> V_100 ,
F_97 ( V_99 ) , V_28 ) ;
if ( ! V_6 -> V_99 ) {
F_17 ( V_6 -> V_12 , L_36 ) ;
return - V_165 ;
}
V_6 -> V_105 = F_97 ( V_6 -> V_99 ) ;
V_6 -> V_27 = F_98 ( V_6 -> V_12 , V_6 -> V_99 -> V_100 , V_6 -> V_105 ) ;
if ( ! V_6 -> V_27 ) {
F_17 ( V_6 -> V_12 , L_37 ) ;
return - V_164 ;
}
F_99 ( & V_6 -> V_11 , V_106 ) ;
F_99 ( & V_6 -> V_36 , V_106 ) ;
F_100 ( V_155 , V_6 ) ;
switch ( V_6 -> V_24 ) {
case 8 :
V_6 -> V_26 = F_1 ;
V_6 -> V_53 = F_7 ;
break;
case 16 :
V_6 -> V_26 = F_3 ;
V_6 -> V_53 = F_9 ;
break;
case 32 :
V_6 -> V_26 = F_5 ;
V_6 -> V_53 = F_11 ;
break;
default:
break;
}
V_6 -> V_95 . V_14 = V_28 ;
V_6 -> V_95 . V_166 = & V_167 ;
V_6 -> V_95 . V_168 = & V_169 ;
if ( V_6 -> V_124 )
V_6 -> V_95 . V_170 = & V_171 ;
V_6 -> V_95 . V_172 = V_173 ;
V_74 = F_50 ( V_6 ) ;
if ( V_74 < 0 )
goto free;
V_6 -> V_148 = F_101 ( & V_6 -> V_95 , V_6 -> V_12 , V_6 ) ;
if ( ! V_6 -> V_148 ) {
F_17 ( V_6 -> V_12 , L_38 ) ;
V_74 = - V_17 ;
goto free;
}
V_74 = F_81 ( V_109 , V_6 ) ;
if ( V_74 < 0 )
goto free;
F_102 ( V_6 -> V_12 , L_39 ,
V_6 -> V_95 . V_16 , V_6 -> V_27 , V_6 -> V_105 ) ;
return 0 ;
free:
F_79 ( V_6 ) ;
return V_74 ;
}
static int F_103 ( struct V_154 * V_155 )
{
struct V_5 * V_6 = F_84 ( V_155 ) ;
if ( ! V_6 )
return 0 ;
F_79 ( V_6 ) ;
return 0 ;
}
