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
static void F_13 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned V_7 )
{
struct V_8 * V_9 ;
unsigned V_2 , V_10 ;
unsigned long V_11 ;
T_3 V_12 ;
V_9 = F_14 ( V_4 ) ;
V_10 = V_9 -> V_13 / V_14 ;
V_11 = V_7 * V_10 ;
V_2 = V_9 -> V_15 ( V_9 -> V_16 + V_11 ) ;
V_12 = V_9 -> V_17 -> V_18 + V_11 ;
F_15 ( V_6 , L_1 , V_12 , V_2 , V_19 ) ;
}
static void F_16 ( struct V_3 * V_4 ,
struct V_20 * V_21 , unsigned V_22 )
{
struct V_8 * V_9 ;
V_9 = F_14 ( V_4 ) ;
F_17 ( V_9 -> V_23 , V_21 ) ;
}
static int F_18 ( struct V_3 * V_4 , unsigned V_7 ,
struct V_24 * * V_25 )
{
struct V_8 * V_9 = F_14 ( V_4 ) ;
struct V_26 * V_27 = F_19 ( V_4 , V_7 ) ;
const struct V_28 * V_29 ;
struct V_30 * V_31 ;
unsigned V_32 ;
V_29 = V_27 -> V_33 ;
if ( ! V_29 )
return - V_34 ;
V_32 = V_29 -> V_25 ;
V_31 = F_20 ( V_4 , V_32 ) ;
* V_25 = V_31 -> V_35 ;
if ( ! ( * V_25 ) ) {
F_21 ( V_9 -> V_23 , L_2 ,
V_36 , V_32 ) ;
return - V_34 ;
}
return 0 ;
}
static int F_22 ( struct V_3 * V_4 , unsigned V_32 ,
unsigned V_37 )
{
struct V_8 * V_9 ;
struct V_30 * V_31 ;
struct V_24 * V_25 ;
int V_38 ;
V_9 = F_14 ( V_4 ) ;
if ( ! V_9 -> V_39 )
return 0 ;
V_31 = F_20 ( V_4 , V_32 ) ;
V_25 = V_31 -> V_35 ;
if ( ! V_25 )
return - V_40 ;
F_23 ( V_9 -> V_23 , L_3 ,
V_25 -> V_41 , V_32 ) ;
for ( V_38 = 0 ; V_38 < V_25 -> V_42 ; V_38 ++ ) {
struct V_43 * V_44 ;
unsigned long V_45 ;
unsigned V_2 , V_46 ;
V_44 = & V_25 -> V_44 [ V_38 ] ;
F_24 ( & V_9 -> V_47 , V_45 ) ;
V_2 = V_9 -> V_15 ( V_44 -> V_1 ) ;
if ( V_9 -> V_48 )
V_46 = V_44 -> V_46 ;
else
V_46 = V_9 -> V_39 ;
V_2 &= ~ V_46 ;
V_2 |= ( V_44 -> V_2 & V_46 ) ;
V_9 -> V_49 ( V_2 , V_44 -> V_1 ) ;
F_25 ( & V_9 -> V_47 , V_45 ) ;
}
return 0 ;
}
static int F_26 ( struct V_3 * V_4 ,
struct V_50 * V_51 , unsigned V_7 )
{
struct V_8 * V_9 = F_14 ( V_4 ) ;
struct V_52 * V_53 = NULL ;
struct V_54 * V_55 , * V_56 ;
int V_10 = 0 ;
unsigned V_35 ;
if ( ! V_9 -> V_39 )
return - V_34 ;
F_27 (pos, tmp, &pcs->gpiofuncs) {
V_53 = F_28 ( V_55 , struct V_52 , V_57 ) ;
if ( V_7 >= V_53 -> V_11 + V_53 -> V_58
|| V_7 < V_53 -> V_11 )
continue;
V_10 = V_9 -> V_13 / V_14 ;
V_35 = V_9 -> V_15 ( V_9 -> V_16 + V_7 * V_10 ) & ~ V_9 -> V_39 ;
V_35 |= V_53 -> V_59 ;
V_9 -> V_49 ( V_35 , V_9 -> V_16 + V_7 * V_10 ) ;
break;
}
return 0 ;
}
static void F_29 ( struct V_3 * V_4 , unsigned V_7 )
{
unsigned long V_60 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < F_30 ( V_61 ) ; V_38 ++ ) {
V_60 = F_31 ( V_61 [ V_38 ] , 0 ) ;
F_32 ( V_4 , V_7 , & V_60 , 1 ) ;
}
}
static bool F_33 ( struct V_3 * V_4 , unsigned V_7 )
{
unsigned long V_60 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < F_30 ( V_61 ) ; V_38 ++ ) {
V_60 = F_31 ( V_61 [ V_38 ] , 0 ) ;
if ( ! F_34 ( V_4 , V_7 , & V_60 ) )
goto V_62;
}
return true ;
V_62:
return false ;
}
static int F_34 ( struct V_3 * V_4 ,
unsigned V_7 , unsigned long * V_60 )
{
struct V_8 * V_9 = F_14 ( V_4 ) ;
struct V_24 * V_25 ;
enum V_63 V_64 ;
unsigned V_11 = 0 , V_35 = 0 , V_38 , V_65 , V_66 ;
V_66 = F_18 ( V_4 , V_7 , & V_25 ) ;
if ( V_66 )
return V_66 ;
for ( V_38 = 0 ; V_38 < V_25 -> V_67 ; V_38 ++ ) {
V_64 = F_35 ( * V_60 ) ;
if ( V_64 == V_68 ) {
if ( F_33 ( V_4 , V_7 ) ) {
* V_60 = 0 ;
return 0 ;
} else {
return - V_34 ;
}
} else if ( V_64 != V_25 -> V_69 [ V_38 ] . V_64 ) {
continue;
}
V_11 = V_7 * ( V_9 -> V_13 / V_14 ) ;
V_35 = V_9 -> V_15 ( V_9 -> V_16 + V_11 ) & V_25 -> V_69 [ V_38 ] . V_46 ;
switch ( V_25 -> V_69 [ V_38 ] . V_64 ) {
case V_70 :
case V_71 :
case V_72 :
if ( ( V_35 != V_25 -> V_69 [ V_38 ] . V_73 ) ||
( V_35 == V_25 -> V_69 [ V_38 ] . V_74 ) )
return - V_34 ;
* V_60 = 0 ;
break;
case V_75 :
for ( V_65 = 0 ; V_65 < V_25 -> V_67 ; V_65 ++ ) {
switch ( V_25 -> V_69 [ V_65 ] . V_64 ) {
case V_72 :
if ( V_35 != V_25 -> V_69 [ V_65 ] . V_73 )
return - V_34 ;
break;
default:
break;
}
}
* V_60 = V_35 ;
break;
case V_76 :
case V_77 :
case V_78 :
default:
* V_60 = V_35 ;
break;
}
return 0 ;
}
return - V_34 ;
}
static int F_32 ( struct V_3 * V_4 ,
unsigned V_7 , unsigned long * V_79 ,
unsigned V_80 )
{
struct V_8 * V_9 = F_14 ( V_4 ) ;
struct V_24 * V_25 ;
unsigned V_11 = 0 , V_81 = 0 , V_38 , V_35 , V_66 ;
T_4 V_82 ;
int V_65 ;
V_66 = F_18 ( V_4 , V_7 , & V_25 ) ;
if ( V_66 )
return V_66 ;
for ( V_65 = 0 ; V_65 < V_80 ; V_65 ++ ) {
for ( V_38 = 0 ; V_38 < V_25 -> V_67 ; V_38 ++ ) {
if ( F_35 ( V_79 [ V_65 ] )
!= V_25 -> V_69 [ V_38 ] . V_64 )
continue;
V_11 = V_7 * ( V_9 -> V_13 / V_14 ) ;
V_35 = V_9 -> V_15 ( V_9 -> V_16 + V_11 ) ;
V_82 = F_36 ( V_79 [ V_65 ] ) ;
switch ( V_25 -> V_69 [ V_38 ] . V_64 ) {
case V_75 :
case V_76 :
case V_77 :
case V_78 :
V_81 = F_37 ( V_25 -> V_69 [ V_38 ] . V_46 ) - 1 ;
V_35 &= ~ V_25 -> V_69 [ V_38 ] . V_46 ;
V_35 |= ( V_82 << V_81 ) & V_25 -> V_69 [ V_38 ] . V_46 ;
break;
case V_68 :
F_29 ( V_4 , V_7 ) ;
break;
case V_70 :
case V_71 :
if ( V_82 )
F_29 ( V_4 , V_7 ) ;
case V_72 :
V_35 &= ~ V_25 -> V_69 [ V_38 ] . V_46 ;
if ( V_82 )
V_35 |= V_25 -> V_69 [ V_38 ] . V_73 ;
else
V_35 |= V_25 -> V_69 [ V_38 ] . V_74 ;
break;
default:
return - V_34 ;
}
V_9 -> V_49 ( V_35 , V_9 -> V_16 + V_11 ) ;
break;
}
if ( V_38 >= V_25 -> V_67 )
return - V_34 ;
}
return 0 ;
}
static int F_38 ( struct V_3 * V_4 ,
unsigned V_37 , unsigned long * V_60 )
{
const unsigned * V_83 ;
unsigned V_58 , V_84 = 0 ;
int V_38 , V_66 ;
V_66 = F_39 ( V_4 , V_37 , & V_83 , & V_58 ) ;
if ( V_66 )
return V_66 ;
for ( V_38 = 0 ; V_38 < V_58 ; V_38 ++ ) {
if ( F_34 ( V_4 , V_83 [ V_38 ] , V_60 ) )
return - V_34 ;
if ( V_38 && ( V_84 != * V_60 ) )
return - V_34 ;
V_84 = * V_60 ;
}
return 0 ;
}
static int F_40 ( struct V_3 * V_4 ,
unsigned V_37 , unsigned long * V_79 ,
unsigned V_80 )
{
const unsigned * V_83 ;
unsigned V_58 ;
int V_38 , V_66 ;
V_66 = F_39 ( V_4 , V_37 , & V_83 , & V_58 ) ;
if ( V_66 )
return V_66 ;
for ( V_38 = 0 ; V_38 < V_58 ; V_38 ++ ) {
if ( F_32 ( V_4 , V_83 [ V_38 ] , V_79 , V_80 ) )
return - V_34 ;
}
return 0 ;
}
static void F_41 ( struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned V_7 )
{
}
static void F_42 ( struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned V_85 )
{
}
static void F_43 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_60 )
{
F_44 ( V_4 , V_6 , V_60 ) ;
}
static int F_45 ( struct V_8 * V_9 , unsigned V_11 ,
unsigned V_86 )
{
struct V_87 * V_88 = & V_9 -> V_89 ;
struct V_90 * V_7 ;
int V_38 ;
V_38 = V_9 -> V_83 . V_91 ;
if ( V_38 >= V_9 -> V_92 . V_58 ) {
F_21 ( V_9 -> V_23 , L_4 ,
V_9 -> V_92 . V_58 ) ;
return - V_93 ;
}
if ( V_88 -> V_94 ) {
unsigned V_2 ;
V_2 = V_9 -> V_15 ( V_9 -> V_16 + V_11 ) ;
if ( V_2 & V_88 -> V_94 ) {
F_23 ( V_9 -> V_23 , L_5 ,
( unsigned long ) V_9 -> V_17 -> V_18 + V_11 , V_2 ) ;
V_2 &= ~ V_88 -> V_94 ;
V_9 -> V_49 ( V_2 , V_9 -> V_16 + V_11 ) ;
}
}
V_7 = & V_9 -> V_83 . V_12 [ V_38 ] ;
V_7 -> V_95 = V_38 ;
V_9 -> V_83 . V_91 ++ ;
return V_38 ;
}
static int F_46 ( struct V_8 * V_9 )
{
int V_10 , V_96 , V_38 ;
int V_97 = 0 ;
V_10 = V_9 -> V_13 / V_14 ;
if ( V_9 -> V_48 ) {
V_9 -> V_98 = F_47 ( V_9 -> V_39 ) ;
V_96 = ( V_9 -> V_99 * V_14 ) / V_9 -> V_98 ;
V_97 = V_9 -> V_13 / V_9 -> V_98 ;
} else {
V_96 = V_9 -> V_99 / V_10 ;
}
F_23 ( V_9 -> V_23 , L_6 , V_96 ) ;
V_9 -> V_83 . V_12 = F_48 ( V_9 -> V_23 ,
sizeof( * V_9 -> V_83 . V_12 ) * V_96 ,
V_100 ) ;
if ( ! V_9 -> V_83 . V_12 )
return - V_93 ;
V_9 -> V_92 . V_83 = V_9 -> V_83 . V_12 ;
V_9 -> V_92 . V_58 = V_96 ;
for ( V_38 = 0 ; V_38 < V_9 -> V_92 . V_58 ; V_38 ++ ) {
unsigned V_11 ;
int V_17 ;
int V_101 ;
int V_86 = 0 ;
if ( V_9 -> V_48 ) {
V_101 = ( V_9 -> V_98 * V_38 ) / V_14 ;
V_11 = ( V_101 / V_10 ) * V_10 ;
V_86 = V_38 % V_97 ;
} else {
V_11 = V_38 * V_10 ;
}
V_17 = F_45 ( V_9 , V_11 , V_86 ) ;
if ( V_17 < 0 ) {
F_21 ( V_9 -> V_23 , L_7 , V_17 ) ;
return V_17 ;
}
}
return 0 ;
}
static struct V_24 * F_49 ( struct V_8 * V_9 ,
struct V_102 * V_103 ,
const char * V_41 ,
struct V_43 * V_44 ,
unsigned V_42 ,
const char * * V_104 ,
unsigned V_105 )
{
struct V_24 * V_31 ;
int V_17 ;
V_31 = F_48 ( V_9 -> V_23 , sizeof( * V_31 ) , V_100 ) ;
if ( ! V_31 )
return NULL ;
V_31 -> V_44 = V_44 ;
V_31 -> V_42 = V_42 ;
V_17 = F_50 ( V_9 -> V_106 , V_41 ,
V_104 , V_105 ,
V_31 ) ;
if ( V_17 )
return NULL ;
return V_31 ;
}
static int F_51 ( struct V_8 * V_9 , unsigned V_11 )
{
unsigned V_107 ;
if ( V_11 >= V_9 -> V_99 ) {
F_21 ( V_9 -> V_23 , L_8 ,
V_11 , V_9 -> V_99 ) ;
return - V_40 ;
}
if ( V_9 -> V_48 )
V_107 = ( V_11 * V_14 ) / V_9 -> V_98 ;
else
V_107 = V_11 / ( V_9 -> V_13 / V_14 ) ;
return V_107 ;
}
static int F_52 ( unsigned V_35 , unsigned V_73 , unsigned V_74 )
{
int V_66 = - V_40 ;
if ( V_35 == V_73 )
V_66 = 1 ;
else if ( V_35 == V_74 )
V_66 = 0 ;
return V_66 ;
}
static void F_53 ( struct V_108 * * V_69 , enum V_63 V_64 ,
unsigned V_109 , unsigned V_73 , unsigned V_74 ,
unsigned V_46 )
{
( * V_69 ) -> V_64 = V_64 ;
( * V_69 ) -> V_2 = V_109 ;
( * V_69 ) -> V_73 = V_73 ;
( * V_69 ) -> V_74 = V_74 ;
( * V_69 ) -> V_46 = V_46 ;
( * V_69 ) ++ ;
}
static void F_54 ( unsigned long * * V_29 , enum V_63 V_64 ,
unsigned V_82 )
{
* * V_29 = F_31 ( V_64 , V_82 ) ;
( * V_29 ) ++ ;
}
static void F_55 ( struct V_8 * V_9 , struct V_102 * V_103 ,
const char * V_41 , enum V_63 V_64 ,
struct V_108 * * V_69 , unsigned long * * V_110 )
{
unsigned V_109 [ 2 ] , V_81 ;
int V_66 ;
V_66 = F_56 ( V_103 , V_41 , V_109 , 2 ) ;
if ( V_66 )
return;
V_109 [ 0 ] &= V_109 [ 1 ] ;
V_81 = F_37 ( V_109 [ 1 ] ) - 1 ;
F_53 ( V_69 , V_64 , V_109 [ 0 ] , 0 , 0 , V_109 [ 1 ] ) ;
F_54 ( V_110 , V_64 , V_109 [ 0 ] >> V_81 ) ;
}
static void F_57 ( struct V_8 * V_9 , struct V_102 * V_103 ,
const char * V_41 , enum V_63 V_64 ,
struct V_108 * * V_69 , unsigned long * * V_110 )
{
unsigned V_109 [ 4 ] ;
int V_66 ;
V_66 = F_56 ( V_103 , V_41 , V_109 , 4 ) ;
if ( V_66 )
return;
if ( ! V_109 [ 3 ] ) {
F_21 ( V_9 -> V_23 , L_9 ) ;
return;
}
V_109 [ 0 ] &= V_109 [ 3 ] ;
V_109 [ 1 ] &= V_109 [ 3 ] ;
V_109 [ 2 ] &= V_109 [ 3 ] ;
V_66 = F_52 ( V_109 [ 0 ] , V_109 [ 1 ] , V_109 [ 2 ] ) ;
if ( V_66 < 0 )
F_23 ( V_9 -> V_23 , L_10 ) ;
F_53 ( V_69 , V_64 , V_109 [ 0 ] , V_109 [ 1 ] , V_109 [ 2 ] , V_109 [ 3 ] ) ;
F_54 ( V_110 , V_64 , V_66 ) ;
}
static int F_58 ( struct V_8 * V_9 , struct V_102 * V_103 ,
struct V_24 * V_25 ,
struct V_20 * * V_21 )
{
struct V_20 * V_111 = * V_21 ;
int V_38 = 0 , V_67 = 0 ;
unsigned long * V_110 = NULL , * V_6 = NULL ;
struct V_108 * V_69 = NULL ;
struct V_112 V_113 [] = {
{ L_11 , V_76 , } ,
{ L_12 , V_77 , } ,
{ L_13 , V_75 , } ,
{ L_14 , V_78 , } ,
} ;
struct V_112 V_114 [] = {
{ L_15 , V_71 , } ,
{ L_16 , V_70 , } ,
{ L_17 ,
V_72 , } ,
} ;
if ( ! V_115 )
return 0 ;
for ( V_38 = 0 ; V_38 < F_30 ( V_113 ) ; V_38 ++ ) {
if ( F_59 ( V_103 , V_113 [ V_38 ] . V_41 , NULL ) )
V_67 ++ ;
}
for ( V_38 = 0 ; V_38 < F_30 ( V_114 ) ; V_38 ++ ) {
if ( F_59 ( V_103 , V_114 [ V_38 ] . V_41 , NULL ) )
V_67 ++ ;
}
if ( ! V_67 )
return 0 ;
V_25 -> V_69 = F_48 ( V_9 -> V_23 ,
sizeof( struct V_108 ) * V_67 ,
V_100 ) ;
if ( ! V_25 -> V_69 )
return - V_93 ;
V_25 -> V_67 = V_67 ;
V_69 = & ( V_25 -> V_69 [ 0 ] ) ;
V_111 ++ ;
V_110 = F_48 ( V_9 -> V_23 , sizeof( unsigned long ) * V_67 ,
V_100 ) ;
if ( ! V_110 )
return - V_93 ;
V_6 = & V_110 [ 0 ] ;
for ( V_38 = 0 ; V_38 < F_30 ( V_113 ) ; V_38 ++ )
F_55 ( V_9 , V_103 , V_113 [ V_38 ] . V_41 , V_113 [ V_38 ] . V_64 ,
& V_69 , & V_6 ) ;
for ( V_38 = 0 ; V_38 < F_30 ( V_114 ) ; V_38 ++ )
F_57 ( V_9 , V_103 , V_114 [ V_38 ] . V_41 , V_114 [ V_38 ] . V_64 ,
& V_69 , & V_6 ) ;
V_111 -> type = V_116 ;
V_111 -> V_35 . V_79 . V_117 = V_103 -> V_41 ;
V_111 -> V_35 . V_79 . V_79 = V_110 ;
V_111 -> V_35 . V_79 . V_80 = V_67 ;
return 0 ;
}
static int F_60 ( struct V_8 * V_9 ,
struct V_102 * V_103 ,
struct V_20 * * V_21 ,
unsigned * V_22 ,
const char * * V_104 )
{
const char * V_41 = L_18 ;
struct V_43 * V_44 ;
int V_118 , * V_83 , V_119 = 0 , V_17 = - V_93 , V_38 ;
struct V_24 * V_31 ;
V_118 = F_61 ( V_103 , V_41 ) ;
if ( V_118 <= 0 ) {
F_21 ( V_9 -> V_23 , L_19 , V_118 ) ;
return - V_40 ;
}
V_44 = F_48 ( V_9 -> V_23 , sizeof( * V_44 ) * V_118 , V_100 ) ;
if ( ! V_44 )
return - V_93 ;
V_83 = F_48 ( V_9 -> V_23 , sizeof( * V_83 ) * V_118 , V_100 ) ;
if ( ! V_83 )
goto V_120;
for ( V_38 = 0 ; V_38 < V_118 ; V_38 ++ ) {
struct V_121 V_122 ;
unsigned int V_11 ;
int V_7 ;
V_17 = F_62 ( V_103 , V_41 , V_38 , & V_122 ) ;
if ( V_17 )
return V_17 ;
if ( V_122 . V_123 < 2 ) {
F_21 ( V_9 -> V_23 , L_20 ,
V_122 . V_123 ) ;
break;
}
V_11 = V_122 . args [ 0 ] ;
V_44 [ V_119 ] . V_1 = V_9 -> V_16 + V_11 ;
V_44 [ V_119 ] . V_2 = V_122 . args [ 1 ] ;
F_23 ( V_9 -> V_23 , L_21 ,
V_122 . V_103 -> V_41 , V_11 , V_122 . args [ 1 ] ) ;
V_7 = F_51 ( V_9 , V_11 ) ;
if ( V_7 < 0 ) {
F_21 ( V_9 -> V_23 ,
L_22 ,
V_103 -> V_41 , V_11 ) ;
break;
}
V_83 [ V_119 ++ ] = V_7 ;
}
V_104 [ 0 ] = V_103 -> V_41 ;
V_31 = F_49 ( V_9 , V_103 , V_103 -> V_41 , V_44 , V_119 , V_104 , 1 ) ;
if ( ! V_31 ) {
V_17 = - V_93 ;
goto V_124;
}
V_17 = F_63 ( V_9 -> V_106 , V_103 -> V_41 , V_83 , V_119 , V_9 ) ;
if ( V_17 < 0 )
goto V_125;
( * V_21 ) -> type = V_126 ;
( * V_21 ) -> V_35 . V_127 . V_37 = V_103 -> V_41 ;
( * V_21 ) -> V_35 . V_127 . V_31 = V_103 -> V_41 ;
if ( V_115 ) {
V_17 = F_58 ( V_9 , V_103 , V_31 , V_21 ) ;
if ( V_17 )
goto V_128;
* V_22 = 2 ;
} else {
* V_22 = 1 ;
}
return 0 ;
V_128:
F_64 ( V_9 -> V_106 ) ;
* V_22 = 1 ;
V_125:
F_65 ( V_9 -> V_106 ) ;
V_124:
F_17 ( V_9 -> V_23 , V_83 ) ;
V_120:
F_17 ( V_9 -> V_23 , V_44 ) ;
return V_17 ;
}
static int F_66 ( struct V_8 * V_9 ,
struct V_102 * V_103 ,
struct V_20 * * V_21 ,
unsigned * V_22 ,
const char * * V_104 )
{
const char * V_41 = L_23 ;
struct V_43 * V_44 ;
int V_118 , * V_83 , V_119 = 0 , V_17 = - V_93 , V_38 ;
int V_129 ;
struct V_24 * V_31 ;
V_118 = F_61 ( V_103 , V_41 ) ;
if ( V_118 <= 0 ) {
F_21 ( V_9 -> V_23 , L_19 , V_118 ) ;
return - V_40 ;
}
V_129 = V_9 -> V_13 / V_9 -> V_98 ;
V_44 = F_48 ( V_9 -> V_23 , sizeof( * V_44 ) * V_118 * V_129 ,
V_100 ) ;
if ( ! V_44 )
return - V_93 ;
V_83 = F_48 ( V_9 -> V_23 , sizeof( * V_83 ) * V_118 * V_129 ,
V_100 ) ;
if ( ! V_83 )
goto V_120;
for ( V_38 = 0 ; V_38 < V_118 ; V_38 ++ ) {
struct V_121 V_122 ;
unsigned V_11 , V_2 ;
unsigned V_46 , V_130 , V_131 , V_132 , V_133 ;
unsigned V_134 ;
int V_7 ;
V_17 = F_62 ( V_103 , V_41 , V_38 , & V_122 ) ;
if ( V_17 )
return V_17 ;
if ( V_122 . V_123 < 3 ) {
F_21 ( V_9 -> V_23 , L_20 ,
V_122 . V_123 ) ;
break;
}
V_11 = V_122 . args [ 0 ] ;
V_2 = V_122 . args [ 1 ] ;
V_46 = V_122 . args [ 2 ] ;
F_23 ( V_9 -> V_23 , L_24 ,
V_122 . V_103 -> V_41 , V_11 , V_2 , V_46 ) ;
while ( V_46 ) {
V_130 = F_67 ( V_46 ) ;
V_134 = V_130 / V_9 -> V_98 ;
V_132 = ( ( V_9 -> V_39 ) << V_130 ) ;
V_131 = V_2 & V_132 ;
V_133 = V_46 & V_132 ;
if ( ( V_46 & V_132 ) == 0 ) {
F_21 ( V_9 -> V_23 ,
L_25 ,
V_103 -> V_41 , V_11 ) ;
break;
}
V_46 &= ~ V_132 ;
if ( V_133 != V_132 ) {
F_68 ( V_9 -> V_23 ,
L_26 ,
V_133 , V_103 -> V_41 , V_11 ) ;
continue;
}
V_44 [ V_119 ] . V_46 = V_133 ;
V_44 [ V_119 ] . V_1 = V_9 -> V_16 + V_11 ;
V_44 [ V_119 ] . V_2 = V_131 ;
V_7 = F_51 ( V_9 , V_11 ) ;
if ( V_7 < 0 ) {
F_21 ( V_9 -> V_23 ,
L_22 ,
V_103 -> V_41 , V_11 ) ;
break;
}
V_83 [ V_119 ++ ] = V_7 + V_134 ;
}
}
V_104 [ 0 ] = V_103 -> V_41 ;
V_31 = F_49 ( V_9 , V_103 , V_103 -> V_41 , V_44 , V_119 , V_104 , 1 ) ;
if ( ! V_31 ) {
V_17 = - V_93 ;
goto V_124;
}
V_17 = F_63 ( V_9 -> V_106 , V_103 -> V_41 , V_83 , V_119 , V_9 ) ;
if ( V_17 < 0 )
goto V_125;
( * V_21 ) -> type = V_126 ;
( * V_21 ) -> V_35 . V_127 . V_37 = V_103 -> V_41 ;
( * V_21 ) -> V_35 . V_127 . V_31 = V_103 -> V_41 ;
if ( V_115 ) {
F_21 ( V_9 -> V_23 , L_27 ) ;
goto V_128;
}
* V_22 = 1 ;
return 0 ;
V_128:
F_64 ( V_9 -> V_106 ) ;
* V_22 = 1 ;
V_125:
F_65 ( V_9 -> V_106 ) ;
V_124:
F_17 ( V_9 -> V_23 , V_83 ) ;
V_120:
F_17 ( V_9 -> V_23 , V_44 ) ;
return V_17 ;
}
static int F_69 ( struct V_3 * V_4 ,
struct V_102 * V_135 ,
struct V_20 * * V_21 , unsigned * V_22 )
{
struct V_8 * V_9 ;
const char * * V_104 ;
int V_66 ;
V_9 = F_14 ( V_4 ) ;
* V_21 = F_48 ( V_9 -> V_23 , sizeof( * * V_21 ) * 2 , V_100 ) ;
if ( ! * V_21 )
return - V_93 ;
* V_22 = 0 ;
V_104 = F_48 ( V_9 -> V_23 , sizeof( * V_104 ) , V_100 ) ;
if ( ! V_104 ) {
V_66 = - V_93 ;
goto V_136;
}
if ( V_9 -> V_48 ) {
V_66 = F_66 ( V_9 , V_135 , V_21 ,
V_22 , V_104 ) ;
if ( V_66 < 0 ) {
F_21 ( V_9 -> V_23 , L_28 ,
V_135 -> V_41 ) ;
goto V_137;
}
} else {
V_66 = F_60 ( V_9 , V_135 , V_21 ,
V_22 , V_104 ) ;
if ( V_66 < 0 ) {
F_21 ( V_9 -> V_23 , L_28 ,
V_135 -> V_41 ) ;
goto V_137;
}
}
return 0 ;
V_137:
F_17 ( V_9 -> V_23 , V_104 ) ;
V_136:
F_17 ( V_9 -> V_23 , * V_21 ) ;
return V_66 ;
}
static void F_70 ( struct V_8 * V_9 )
{
struct V_87 * V_88 = & V_9 -> V_89 ;
if ( V_88 -> V_138 < 0 )
return;
if ( V_9 -> V_139 )
F_71 ( V_9 -> V_139 ) ;
if ( V_140 )
F_72 ( V_88 -> V_138 , V_88 ) ;
else
F_73 ( V_88 -> V_138 , NULL ) ;
}
static void F_74 ( struct V_8 * V_9 )
{
F_70 ( V_9 ) ;
F_75 ( V_9 -> V_106 ) ;
#if F_76 ( V_141 )
if ( V_9 -> V_142 )
F_77 ( V_9 -> V_103 , V_9 -> V_142 ) ;
#endif
}
static int F_78 ( struct V_102 * V_57 , struct V_8 * V_9 )
{
const char * V_143 = L_29 ;
const char * V_144 = L_30 ;
struct V_121 V_145 ;
struct V_52 * V_51 ;
int V_66 , V_38 ;
for ( V_38 = 0 ; ; V_38 ++ ) {
V_66 = F_79 ( V_57 , V_143 , V_144 ,
V_38 , & V_145 ) ;
if ( V_66 ) {
V_66 = 0 ;
break;
}
V_51 = F_48 ( V_9 -> V_23 , sizeof( * V_51 ) , V_100 ) ;
if ( ! V_51 ) {
V_66 = - V_93 ;
break;
}
V_51 -> V_11 = V_145 . args [ 0 ] ;
V_51 -> V_58 = V_145 . args [ 1 ] ;
V_51 -> V_59 = V_145 . args [ 2 ] ;
F_80 ( & V_9 -> V_146 ) ;
F_81 ( & V_51 -> V_57 , & V_9 -> V_147 ) ;
F_82 ( & V_9 -> V_146 ) ;
}
return V_66 ;
}
static inline void F_83 ( struct V_87 * V_88 ,
int V_138 , const bool V_73 )
{
struct V_8 * V_9 ;
struct V_54 * V_55 ;
unsigned V_46 ;
V_9 = F_84 ( V_88 , struct V_8 , V_89 ) ;
F_85 (pos, &pcs->irqs) {
struct V_148 * V_149 ;
unsigned V_150 ;
V_149 = F_28 ( V_55 , struct V_148 , V_57 ) ;
if ( V_138 != V_149 -> V_138 )
continue;
V_150 = V_88 -> V_94 ;
F_86 ( & V_9 -> V_47 ) ;
V_46 = V_9 -> V_15 ( V_149 -> V_1 ) ;
if ( V_73 )
V_46 |= V_150 ;
else
V_46 &= ~ V_150 ;
V_9 -> V_49 ( V_46 , V_149 -> V_1 ) ;
V_46 = V_9 -> V_15 ( V_149 -> V_1 ) ;
F_87 ( & V_9 -> V_47 ) ;
}
if ( V_88 -> V_151 )
V_88 -> V_151 () ;
}
static void F_88 ( struct V_152 * V_153 )
{
struct V_87 * V_88 = F_89 ( V_153 ) ;
F_83 ( V_88 , V_153 -> V_138 , false ) ;
}
static void F_90 ( struct V_152 * V_153 )
{
struct V_87 * V_88 = F_89 ( V_153 ) ;
F_83 ( V_88 , V_153 -> V_138 , true ) ;
}
static int F_91 ( struct V_152 * V_153 , unsigned int V_154 )
{
if ( V_154 )
F_90 ( V_153 ) ;
else
F_88 ( V_153 ) ;
return 0 ;
}
static int F_92 ( struct V_87 * V_88 )
{
struct V_8 * V_9 ;
struct V_54 * V_55 ;
int V_155 = 0 ;
V_9 = F_84 ( V_88 , struct V_8 , V_89 ) ;
F_85 (pos, &pcs->irqs) {
struct V_148 * V_149 ;
unsigned V_46 ;
V_149 = F_28 ( V_55 , struct V_148 , V_57 ) ;
F_86 ( & V_9 -> V_47 ) ;
V_46 = V_9 -> V_15 ( V_149 -> V_1 ) ;
F_87 ( & V_9 -> V_47 ) ;
if ( V_46 & V_88 -> V_156 ) {
F_93 ( F_94 ( V_9 -> V_139 ,
V_149 -> V_157 ) ) ;
V_155 ++ ;
}
}
return V_155 ;
}
static T_5 F_95 ( int V_138 , void * V_153 )
{
struct V_87 * V_88 = V_153 ;
return F_92 ( V_88 ) ? V_158 : V_159 ;
}
static void F_96 ( struct V_160 * V_92 )
{
struct V_87 * V_88 = F_97 ( V_92 ) ;
struct V_161 * V_162 ;
V_162 = F_98 ( V_92 ) ;
F_99 ( V_162 , V_92 ) ;
F_92 ( V_88 ) ;
F_100 ( V_162 , V_92 ) ;
return;
}
static int F_101 ( struct V_163 * V_153 , unsigned int V_138 ,
T_6 V_157 )
{
struct V_87 * V_88 = V_153 -> V_164 ;
struct V_8 * V_9 ;
struct V_148 * V_149 ;
V_9 = F_84 ( V_88 , struct V_8 , V_89 ) ;
V_149 = F_48 ( V_9 -> V_23 , sizeof( * V_149 ) , V_100 ) ;
if ( ! V_149 )
return - V_93 ;
V_149 -> V_1 = V_9 -> V_16 + V_157 ;
V_149 -> V_157 = V_157 ;
V_149 -> V_138 = V_138 ;
F_80 ( & V_9 -> V_146 ) ;
F_81 ( & V_149 -> V_57 , & V_9 -> V_165 ) ;
F_82 ( & V_9 -> V_146 ) ;
F_102 ( V_138 , V_88 ) ;
F_103 ( V_138 , & V_9 -> V_162 ,
V_166 ) ;
F_104 ( V_138 , & V_167 ) ;
F_105 ( V_138 ) ;
return 0 ;
}
static int F_106 ( struct V_8 * V_9 ,
struct V_102 * V_103 )
{
struct V_87 * V_88 = & V_9 -> V_89 ;
const char * V_41 = L_31 ;
int V_168 ;
if ( ! V_88 -> V_94 ||
! V_88 -> V_156 ) {
V_88 -> V_138 = - 1 ;
return - V_40 ;
}
F_107 ( & V_9 -> V_165 ) ;
V_9 -> V_162 . V_41 = V_41 ;
V_9 -> V_162 . V_169 = F_88 ;
V_9 -> V_162 . V_170 = F_88 ;
V_9 -> V_162 . V_171 = F_90 ;
V_9 -> V_162 . V_172 = F_91 ;
if ( V_140 ) {
int V_17 ;
V_17 = F_108 ( V_88 -> V_138 , F_95 ,
V_173 | V_174 |
V_175 ,
V_41 , V_88 ) ;
if ( V_17 ) {
V_88 -> V_138 = - 1 ;
return V_17 ;
}
} else {
F_109 ( V_88 -> V_138 ,
F_96 ,
V_88 ) ;
}
V_168 = V_9 -> V_99 ;
V_9 -> V_139 = F_110 ( V_103 , V_168 , 0 ,
& V_176 ,
V_88 ) ;
if ( ! V_9 -> V_139 ) {
F_73 ( V_88 -> V_138 , NULL ) ;
return - V_40 ;
}
return 0 ;
}
static int F_111 ( struct V_177 * V_178 ,
T_7 V_154 )
{
struct V_8 * V_9 ;
V_9 = F_112 ( V_178 ) ;
if ( ! V_9 )
return - V_40 ;
return F_113 ( V_9 -> V_106 ) ;
}
static int F_114 ( struct V_177 * V_178 )
{
struct V_8 * V_9 ;
V_9 = F_112 ( V_178 ) ;
if ( ! V_9 )
return - V_40 ;
return F_115 ( V_9 -> V_106 ) ;
}
static int F_116 ( struct V_8 * V_9 ,
struct V_102 * V_103 ,
int V_179 )
{
struct V_180 * V_181 ;
const char * V_41 = L_32 ;
int error ;
T_4 V_2 ;
error = F_117 ( V_103 , V_41 , & V_2 ) ;
if ( ! error )
return 0 ;
F_68 ( V_9 -> V_23 , L_33 ,
V_41 , V_179 ) ;
V_181 = F_48 ( V_9 -> V_23 , sizeof( * V_181 ) , V_100 ) ;
if ( ! V_181 )
return - V_93 ;
V_181 -> V_182 = sizeof( V_183 ) ;
V_181 -> V_109 = F_48 ( V_9 -> V_23 , sizeof( V_183 ) , V_100 ) ;
if ( ! V_181 -> V_109 )
return - V_93 ;
* ( V_183 * ) V_181 -> V_109 = F_118 ( V_179 ) ;
V_181 -> V_41 = F_119 ( V_9 -> V_23 , V_41 , V_100 ) ;
if ( ! V_181 -> V_41 )
return - V_93 ;
V_9 -> V_142 = V_181 ;
#if F_76 ( V_141 )
error = F_120 ( V_103 , V_9 -> V_142 ) ;
#endif
return error ;
}
static int F_121 ( struct V_177 * V_178 )
{
struct V_102 * V_103 = V_178 -> V_23 . V_184 ;
const struct V_185 * V_186 ;
struct V_187 * V_188 ;
struct V_189 * V_17 ;
struct V_8 * V_9 ;
const struct V_87 * V_190 ;
int V_66 ;
V_186 = F_122 ( V_191 , & V_178 -> V_23 ) ;
if ( ! V_186 )
return - V_40 ;
V_9 = F_48 ( & V_178 -> V_23 , sizeof( * V_9 ) , V_100 ) ;
if ( ! V_9 ) {
F_21 ( & V_178 -> V_23 , L_34 ) ;
return - V_93 ;
}
V_9 -> V_23 = & V_178 -> V_23 ;
V_9 -> V_103 = V_103 ;
F_123 ( & V_9 -> V_47 ) ;
F_124 ( & V_9 -> V_146 ) ;
F_107 ( & V_9 -> V_147 ) ;
V_190 = V_186 -> V_35 ;
V_9 -> V_45 = V_190 -> V_45 ;
memcpy ( & V_9 -> V_89 , V_190 , sizeof( * V_190 ) ) ;
V_66 = F_117 ( V_103 , L_35 ,
& V_9 -> V_13 ) ;
if ( V_66 ) {
F_21 ( V_9 -> V_23 , L_36 ) ;
return V_66 ;
}
V_66 = F_117 ( V_103 , L_37 ,
& V_9 -> V_39 ) ;
if ( ! V_66 ) {
V_9 -> V_192 = F_67 ( V_9 -> V_39 ) ;
V_9 -> V_193 = V_9 -> V_39 >> V_9 -> V_192 ;
} else {
V_9 -> V_39 = 0 ;
V_9 -> V_192 = 0 ;
V_9 -> V_193 = 0 ;
}
V_66 = F_117 ( V_103 , L_38 ,
& V_9 -> V_194 ) ;
if ( V_66 )
V_9 -> V_194 = V_195 ;
V_9 -> V_48 = F_125 ( V_103 ,
L_39 ) ;
V_66 = F_116 ( V_9 , V_103 ,
V_9 -> V_48 ? 2 : 1 ) ;
if ( V_66 ) {
F_21 ( & V_178 -> V_23 , L_40 ) ;
return V_66 ;
}
V_17 = F_126 ( V_178 , V_196 , 0 ) ;
if ( ! V_17 ) {
F_21 ( V_9 -> V_23 , L_41 ) ;
return - V_197 ;
}
V_9 -> V_17 = F_127 ( V_9 -> V_23 , V_17 -> V_18 ,
F_128 ( V_17 ) , V_19 ) ;
if ( ! V_9 -> V_17 ) {
F_21 ( V_9 -> V_23 , L_42 ) ;
return - V_198 ;
}
V_9 -> V_99 = F_128 ( V_9 -> V_17 ) ;
V_9 -> V_16 = F_129 ( V_9 -> V_23 , V_9 -> V_17 -> V_18 , V_9 -> V_99 ) ;
if ( ! V_9 -> V_16 ) {
F_21 ( V_9 -> V_23 , L_43 ) ;
return - V_197 ;
}
F_130 ( V_178 , V_9 ) ;
switch ( V_9 -> V_13 ) {
case 8 :
V_9 -> V_15 = F_1 ;
V_9 -> V_49 = F_7 ;
break;
case 16 :
V_9 -> V_15 = F_3 ;
V_9 -> V_49 = F_9 ;
break;
case 32 :
V_9 -> V_15 = F_5 ;
V_9 -> V_49 = F_11 ;
break;
default:
break;
}
V_9 -> V_92 . V_41 = V_19 ;
V_9 -> V_92 . V_199 = & V_200 ;
V_9 -> V_92 . V_201 = & V_202 ;
if ( V_115 )
V_9 -> V_92 . V_203 = & V_204 ;
V_9 -> V_92 . V_205 = V_206 ;
V_66 = F_46 ( V_9 ) ;
if ( V_66 < 0 )
goto free;
V_66 = F_131 ( & V_9 -> V_92 , V_9 -> V_23 , V_9 , & V_9 -> V_106 ) ;
if ( V_66 ) {
F_21 ( V_9 -> V_23 , L_44 ) ;
goto free;
}
V_66 = F_78 ( V_103 , V_9 ) ;
if ( V_66 < 0 )
goto free;
V_9 -> V_89 . V_138 = F_132 ( V_103 , 0 ) ;
if ( V_9 -> V_89 . V_138 )
V_9 -> V_45 |= V_207 ;
V_188 = F_133 ( & V_178 -> V_23 ) ;
if ( V_188 ) {
if ( V_188 -> V_151 )
V_9 -> V_89 . V_151 = V_188 -> V_151 ;
if ( V_188 -> V_138 ) {
V_9 -> V_89 . V_138 = V_188 -> V_138 ;
V_9 -> V_45 |= V_207 ;
}
}
if ( V_208 ) {
V_66 = F_106 ( V_9 , V_103 ) ;
if ( V_66 < 0 )
F_68 ( V_9 -> V_23 , L_45 ) ;
}
F_134 ( V_9 -> V_23 , L_46 ,
V_9 -> V_92 . V_58 , V_9 -> V_16 , V_9 -> V_99 ) ;
return F_135 ( V_9 -> V_106 ) ;
free:
F_74 ( V_9 ) ;
return V_66 ;
}
static int F_136 ( struct V_177 * V_178 )
{
struct V_8 * V_9 = F_112 ( V_178 ) ;
if ( ! V_9 )
return 0 ;
F_74 ( V_9 ) ;
return 0 ;
}
