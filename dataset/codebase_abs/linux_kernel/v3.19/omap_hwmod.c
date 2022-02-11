static struct V_1 * F_1 ( struct V_2 * * V_3 ,
int * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( * V_3 , struct V_6 , V_7 ) -> V_8 ;
* V_3 = ( * V_3 ) -> V_9 ;
* V_4 = * V_4 + 1 ;
return V_5 ;
}
static int F_3 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_12 -> V_13 ) {
F_4 ( 1 , L_1 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_16 = F_5 ( V_11 , V_11 -> V_12 -> V_13 -> V_17 ) ;
if ( ! ( V_11 -> V_12 -> V_13 -> V_18 & V_19 ) )
V_11 -> V_20 |= V_21 ;
return 0 ;
}
static void F_6 ( T_1 V_22 , struct V_10 * V_11 )
{
if ( ! V_11 -> V_12 -> V_13 ) {
F_4 ( 1 , L_2 , V_11 -> V_14 ) ;
return;
}
V_11 -> V_16 = V_22 ;
F_7 ( V_22 , V_11 , V_11 -> V_12 -> V_13 -> V_17 ) ;
}
static int F_8 ( struct V_10 * V_11 , T_2 V_23 ,
T_1 * V_22 )
{
T_1 V_24 ;
T_2 V_25 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_26 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_27 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_25 = V_11 -> V_12 -> V_13 -> V_27 -> V_28 ;
V_24 = ( 0x3 << V_25 ) ;
* V_22 &= ~ V_24 ;
* V_22 |= F_9 ( V_23 ) << V_25 ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 , T_2 V_29 , T_1 * V_22 )
{
T_1 V_30 ;
T_2 V_31 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_32 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_27 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_31 = V_11 -> V_12 -> V_13 -> V_27 -> V_31 ;
V_30 = ( 0x3 << V_31 ) ;
* V_22 &= ~ V_30 ;
* V_22 |= F_9 ( V_29 ) << V_31 ;
return 0 ;
}
static int F_11 ( struct V_10 * V_11 , T_2 V_33 , T_1 * V_22 )
{
T_1 V_34 ;
T_2 V_35 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_36 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_27 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_35 = V_11 -> V_12 -> V_13 -> V_27 -> V_35 ;
V_34 = ( 0x3 << V_35 ) ;
* V_22 &= ~ V_34 ;
* V_22 |= V_33 << V_35 ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 , T_1 * V_22 )
{
T_1 V_37 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_38 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_27 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_37 = ( 0x1 << V_11 -> V_12 -> V_13 -> V_27 -> V_39 ) ;
* V_22 |= V_37 ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 , T_1 * V_22 )
{
T_1 V_37 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_38 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_27 ) {
F_4 ( 1 ,
L_4 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
V_37 = ( 0x1 << V_11 -> V_12 -> V_13 -> V_27 -> V_39 ) ;
* V_22 &= ~ V_37 ;
return 0 ;
}
static int F_14 ( struct V_10 * V_11 )
{
struct V_40 * V_13 ;
T_1 V_37 ;
int V_41 = 0 ;
V_13 = V_11 -> V_12 -> V_13 ;
if ( V_13 -> V_18 & V_42 )
F_15 ( ( F_5 ( V_11 , V_13 -> V_43 )
& V_44 ) ,
V_45 , V_41 ) ;
else if ( V_13 -> V_18 & V_46 ) {
V_37 = ( 0x1 << V_13 -> V_27 -> V_39 ) ;
F_15 ( ! ( F_5 ( V_11 , V_13 -> V_17 )
& V_37 ) ,
V_45 , V_41 ) ;
}
return V_41 ;
}
static int F_16 ( struct V_10 * V_11 )
{
T_1 V_22 ;
T_1 V_47 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_48 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_27 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_49 != V_50 ) {
F_17 ( L_5 , V_11 -> V_14 ) ;
return - V_15 ;
}
F_18 ( L_6 , V_11 -> V_14 ) ;
V_22 = V_11 -> V_16 ;
V_47 =
( 0x1 << V_11 -> V_12 -> V_13 -> V_27 -> V_51 ) ;
V_22 |= V_47 ;
F_6 ( V_22 , V_11 ) ;
return 0 ;
}
static int F_19 ( struct V_10 * V_11 , T_2 V_52 ,
T_1 * V_22 )
{
T_1 V_53 ;
T_2 V_54 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_55 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_27 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_54 = V_11 -> V_12 -> V_13 -> V_27 -> V_54 ;
V_53 = ( 0x1 << V_54 ) ;
* V_22 &= ~ V_53 ;
* V_22 |= V_52 << V_54 ;
return 0 ;
}
static void F_20 ( struct V_10 * V_11 , bool V_56 )
{
struct V_57 * V_58 ;
bool V_59 = false ;
T_3 V_60 ;
int V_61 ;
if ( ! V_11 -> V_62 || ! V_11 -> V_62 -> V_63 )
return;
for ( V_61 = 0 ; V_61 < V_11 -> V_62 -> V_64 ; V_61 ++ ) {
V_58 = V_11 -> V_62 -> V_65 [ V_61 ] ;
if ( ! ( V_58 -> V_66 & V_67 ) )
continue;
V_60 = V_58 -> V_68 ;
if ( V_56 )
V_58 -> V_68 |= V_69 ;
else
V_58 -> V_68 &= ~ V_69 ;
if ( V_60 != V_58 -> V_68 )
V_59 = true ;
}
if ( V_59 && V_11 -> V_49 == V_70 )
F_21 ( V_11 -> V_62 , V_70 ) ;
}
static int F_22 ( struct V_10 * V_11 , T_1 * V_22 )
{
if ( ! V_11 -> V_12 -> V_13 ||
! ( ( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ||
( V_11 -> V_12 -> V_13 -> V_72 & V_73 ) ||
( V_11 -> V_12 -> V_13 -> V_72 & V_74 ) ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_27 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_12 -> V_13 -> V_18 & V_71 )
* V_22 |= 0x1 << V_11 -> V_12 -> V_13 -> V_27 -> V_75 ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_73 )
F_10 ( V_11 , V_76 , V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_74 )
F_8 ( V_11 , V_76 , V_22 ) ;
return 0 ;
}
static int F_23 ( struct V_10 * V_11 , T_1 * V_22 )
{
if ( ! V_11 -> V_12 -> V_13 ||
! ( ( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ||
( V_11 -> V_12 -> V_13 -> V_72 & V_73 ) ||
( V_11 -> V_12 -> V_13 -> V_72 & V_74 ) ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_27 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_12 -> V_13 -> V_18 & V_71 )
* V_22 &= ~ ( 0x1 << V_11 -> V_12 -> V_13 -> V_27 -> V_75 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_73 )
F_10 ( V_11 , V_77 , V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_74 )
F_8 ( V_11 , V_77 , V_22 ) ;
return 0 ;
}
static struct V_78 * F_24 ( struct V_10 * V_11 )
{
struct V_79 * V_80 ;
if ( V_11 -> V_81 ) {
return V_11 -> V_81 ;
} else if ( V_11 -> V_82 ) {
if ( F_25 ( V_11 -> V_82 ) & V_83 )
return NULL ;
V_80 = F_26 ( F_27 ( V_11 -> V_82 ) ) ;
return V_80 -> V_81 ;
}
return NULL ;
}
static int F_28 ( struct V_10 * V_11 , struct V_10 * V_84 )
{
struct V_78 * V_81 , * V_85 ;
V_81 = F_24 ( V_11 ) ;
V_85 = F_24 ( V_84 ) ;
if ( ! V_81 || ! V_85 )
return - V_15 ;
if ( V_81 && V_81 -> V_66 & V_86 )
return 0 ;
return F_29 ( V_81 , V_85 ) ;
}
static int F_30 ( struct V_10 * V_11 , struct V_10 * V_84 )
{
struct V_78 * V_81 , * V_85 ;
V_81 = F_24 ( V_11 ) ;
V_85 = F_24 ( V_84 ) ;
if ( ! V_81 || ! V_85 )
return - V_15 ;
if ( V_81 && V_81 -> V_66 & V_86 )
return 0 ;
return F_31 ( V_81 , V_85 ) ;
}
static int F_32 ( struct V_10 * V_11 )
{
int V_87 = 0 ;
if ( ! V_11 -> V_88 )
return 0 ;
V_11 -> V_82 = F_33 ( NULL , V_11 -> V_88 ) ;
if ( F_34 ( V_11 -> V_82 ) ) {
F_17 ( L_7 ,
V_11 -> V_14 , V_11 -> V_88 ) ;
return - V_15 ;
}
F_35 ( V_11 -> V_82 ) ;
if ( ! F_24 ( V_11 ) )
F_18 ( L_8 ,
V_11 -> V_14 , V_11 -> V_88 ) ;
return V_87 ;
}
static int F_36 ( struct V_10 * V_11 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
struct V_80 * V_41 ;
int V_4 = 0 ;
int V_87 = 0 ;
V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_89 -> V_80 )
continue;
V_41 = F_33 ( NULL , V_89 -> V_80 ) ;
if ( F_34 ( V_41 ) ) {
F_17 ( L_9 ,
V_11 -> V_14 , V_89 -> V_80 ) ;
V_87 = - V_15 ;
continue;
}
V_89 -> V_82 = V_41 ;
F_35 ( V_89 -> V_82 ) ;
}
return V_87 ;
}
static int F_37 ( struct V_10 * V_11 )
{
struct V_92 * V_93 ;
struct V_80 * V_41 ;
int V_4 ;
int V_87 = 0 ;
for ( V_4 = V_11 -> V_94 , V_93 = V_11 -> V_95 ; V_4 > 0 ; V_4 -- , V_93 ++ ) {
V_41 = F_33 ( NULL , V_93 -> V_80 ) ;
if ( F_34 ( V_41 ) ) {
F_17 ( L_10 ,
V_11 -> V_14 , V_93 -> V_80 ) ;
V_87 = - V_15 ;
continue;
}
V_93 -> V_82 = V_41 ;
F_35 ( V_93 -> V_82 ) ;
}
return V_87 ;
}
static int F_38 ( struct V_10 * V_11 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_18 ( L_11 , V_11 -> V_14 ) ;
if ( V_11 -> V_82 )
F_39 ( V_11 -> V_82 ) ;
V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
if ( V_89 -> V_82 && ( V_89 -> V_66 & V_96 ) )
F_39 ( V_89 -> V_82 ) ;
}
return 0 ;
}
static int F_40 ( struct V_10 * V_11 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_18 ( L_12 , V_11 -> V_14 ) ;
if ( V_11 -> V_82 )
F_41 ( V_11 -> V_82 ) ;
V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
if ( V_89 -> V_82 && ( V_89 -> V_66 & V_96 ) )
F_41 ( V_89 -> V_82 ) ;
}
return 0 ;
}
static void F_42 ( struct V_10 * V_11 )
{
struct V_92 * V_93 ;
int V_4 ;
F_18 ( L_13 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_94 , V_93 = V_11 -> V_95 ; V_4 > 0 ; V_4 -- , V_93 ++ )
if ( V_93 -> V_82 ) {
F_18 ( L_14 , V_93 -> V_97 ,
F_43 ( V_93 -> V_82 ) ) ;
F_39 ( V_93 -> V_82 ) ;
}
}
static void F_44 ( struct V_10 * V_11 )
{
struct V_92 * V_93 ;
int V_4 ;
F_18 ( L_15 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_94 , V_93 = V_11 -> V_95 ; V_4 > 0 ; V_4 -- , V_93 ++ )
if ( V_93 -> V_82 ) {
F_18 ( L_16 , V_93 -> V_97 ,
F_43 ( V_93 -> V_82 ) ) ;
F_41 ( V_93 -> V_82 ) ;
}
}
static void F_45 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_81 || ! V_11 -> V_98 . V_99 . V_100 )
return;
F_18 ( L_17 ,
V_11 -> V_14 , V_101 , V_11 -> V_98 . V_99 . V_100 ) ;
F_46 ( V_11 -> V_98 . V_99 . V_100 ,
V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 , V_11 -> V_98 . V_99 . V_104 ) ;
}
static int F_47 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_105 || ! V_11 -> V_81 )
return 0 ;
if ( V_11 -> V_66 & V_106 )
return 0 ;
return F_48 ( V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_98 . V_99 . V_104 , 0 ) ;
}
static int F_49 ( struct V_10 * V_11 )
{
struct V_107 * V_108 ;
int V_4 = 0 ;
if ( ! V_11 || ! V_11 -> V_109 )
return 0 ;
do {
V_108 = & V_11 -> V_109 [ V_4 ++ ] ;
} while ( V_108 -> V_110 != - 1 );
return V_4 - 1 ;
}
static int F_50 ( struct V_10 * V_11 )
{
struct V_111 * V_112 ;
int V_4 = 0 ;
if ( ! V_11 || ! V_11 -> V_113 )
return 0 ;
do {
V_112 = & V_11 -> V_113 [ V_4 ++ ] ;
} while ( V_112 -> V_114 != - 1 );
return V_4 - 1 ;
}
static int F_51 ( struct V_1 * V_89 )
{
struct V_115 * V_116 ;
int V_4 = 0 ;
if ( ! V_89 || ! V_89 -> V_117 )
return 0 ;
do {
V_116 = & V_89 -> V_117 [ V_4 ++ ] ;
} while ( V_116 -> V_118 != V_116 -> V_119 );
return V_4 - 1 ;
}
static int F_52 ( struct V_10 * V_11 , const char * V_14 ,
unsigned int * V_110 )
{
int V_4 ;
bool V_120 = false ;
if ( ! V_11 -> V_109 )
return - V_121 ;
V_4 = 0 ;
while ( V_11 -> V_109 [ V_4 ] . V_110 != - 1 ) {
if ( V_14 == V_11 -> V_109 [ V_4 ] . V_14 ||
! strcmp ( V_14 , V_11 -> V_109 [ V_4 ] . V_14 ) ) {
V_120 = true ;
break;
}
V_4 ++ ;
}
if ( ! V_120 )
return - V_121 ;
* V_110 = V_11 -> V_109 [ V_4 ] . V_110 ;
return 0 ;
}
static int F_53 ( struct V_10 * V_11 , const char * V_14 ,
unsigned int * V_122 )
{
int V_4 ;
bool V_120 = false ;
if ( ! V_11 -> V_113 )
return - V_121 ;
V_4 = 0 ;
while ( V_11 -> V_113 [ V_4 ] . V_114 != - 1 ) {
if ( V_14 == V_11 -> V_113 [ V_4 ] . V_14 ||
! strcmp ( V_14 , V_11 -> V_113 [ V_4 ] . V_14 ) ) {
V_120 = true ;
break;
}
V_4 ++ ;
}
if ( ! V_120 )
return - V_121 ;
* V_122 = V_11 -> V_113 [ V_4 ] . V_114 ;
return 0 ;
}
static int F_54 ( struct V_10 * V_11 , const char * V_14 ,
T_1 * V_118 , T_1 * V_119 )
{
int V_4 , V_61 ;
struct V_1 * V_89 ;
struct V_2 * V_3 = NULL ;
bool V_120 = false ;
V_3 = V_11 -> V_90 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_89 -> V_117 )
return - V_121 ;
V_61 = 0 ;
while ( V_89 -> V_117 [ V_61 ] . V_118 != V_89 -> V_117 [ V_61 ] . V_119 ) {
if ( V_14 == V_89 -> V_117 [ V_61 ] . V_14 ||
! strcmp ( V_14 , V_89 -> V_117 [ V_61 ] . V_14 ) ) {
V_120 = true ;
break;
}
V_61 ++ ;
}
if ( V_120 )
break;
}
if ( ! V_120 )
return - V_121 ;
* V_118 = V_89 -> V_117 [ V_61 ] . V_118 ;
* V_119 = V_89 -> V_117 [ V_61 ] . V_119 ;
return 0 ;
}
static void T_4 F_55 ( struct V_10 * V_11 )
{
struct V_1 * V_89 = NULL ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( ! V_11 )
return;
V_11 -> V_20 |= V_105 ;
V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
if ( V_89 -> V_123 & V_124 ) {
V_11 -> V_125 = V_89 ;
V_11 -> V_20 &= ~ V_105 ;
break;
}
}
return;
}
static struct V_1 * F_56 ( struct V_10 * V_11 )
{
if ( ! V_11 || V_11 -> V_20 & V_105 || V_11 -> V_91 == 0 )
return NULL ;
return V_11 -> V_125 ;
}
static struct V_115 * T_4 F_57 ( struct V_10 * V_11 )
{
struct V_1 * V_89 ;
struct V_115 * V_116 ;
int V_120 = 0 , V_4 = 0 ;
V_89 = F_56 ( V_11 ) ;
if ( ! V_89 || ! V_89 -> V_117 )
return NULL ;
do {
V_116 = & V_89 -> V_117 [ V_4 ++ ] ;
if ( V_116 -> V_66 & V_126 )
V_120 = 1 ;
} while ( ! V_120 && V_116 -> V_118 != V_116 -> V_119 );
return ( V_120 ) ? V_116 : NULL ;
}
static void F_58 ( struct V_10 * V_11 )
{
T_2 V_29 , V_127 ;
T_1 V_22 ;
bool V_128 ;
struct V_78 * V_81 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
if ( V_11 -> V_66 & V_129 )
F_42 ( V_11 ) ;
F_14 ( V_11 ) ;
if ( V_11 -> V_66 & V_129 )
F_44 ( V_11 ) ;
V_22 = V_11 -> V_16 ;
V_127 = V_11 -> V_12 -> V_13 -> V_18 ;
V_81 = F_24 ( V_11 ) ;
if ( V_127 & V_32 ) {
if ( V_11 -> V_66 & V_130 ||
V_11 -> V_66 & V_131 ) {
V_29 = V_132 ;
} else {
if ( V_127 & V_71 )
F_22 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_73 )
V_29 = V_76 ;
else
V_29 = V_77 ;
}
V_128 = ( V_81 && V_81 -> V_66 & V_133 ) ;
if ( V_128 && ! ( V_11 -> V_12 -> V_13 -> V_72 &
( V_134 | V_73 ) ) )
V_29 = V_135 ;
F_10 ( V_11 , V_29 , & V_22 ) ;
}
if ( V_127 & V_26 ) {
if ( V_11 -> V_66 & V_136 ) {
V_29 = V_135 ;
} else if ( V_11 -> V_66 & V_137 ) {
V_29 = V_132 ;
} else {
if ( V_127 & V_71 )
F_22 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_74 )
V_29 = V_76 ;
else
V_29 = V_77 ;
}
F_8 ( V_11 , V_29 , & V_22 ) ;
}
if ( ( V_11 -> V_66 & V_138 ) &&
( V_127 & V_36 ) )
F_11 ( V_11 , V_11 -> V_12 -> V_13 -> V_33 , & V_22 ) ;
if ( V_11 -> V_16 != V_22 )
F_6 ( V_22 , V_11 ) ;
if ( V_127 & V_55 ) {
V_29 = ( V_11 -> V_66 & V_139 ) ?
0 : 1 ;
F_19 ( V_11 , V_29 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
}
static void F_59 ( struct V_10 * V_11 )
{
T_2 V_29 , V_127 ;
T_1 V_22 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_127 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_127 & V_32 ) {
if ( V_11 -> V_66 & V_130 ) {
V_29 = V_135 ;
} else {
if ( V_127 & V_71 )
F_22 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_73 )
V_29 = V_76 ;
else
V_29 = V_77 ;
}
F_10 ( V_11 , V_29 , & V_22 ) ;
}
if ( V_127 & V_26 ) {
if ( ( V_11 -> V_66 & V_137 ) ||
( V_11 -> V_66 & V_136 ) ) {
V_29 = V_135 ;
} else {
if ( V_127 & V_71 )
F_22 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_74 )
V_29 = V_76 ;
else
V_29 = V_77 ;
}
F_8 ( V_11 , V_29 , & V_22 ) ;
}
F_6 ( V_22 , V_11 ) ;
}
static void F_60 ( struct V_10 * V_11 )
{
T_1 V_22 ;
T_2 V_127 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_127 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_127 & V_32 )
F_10 ( V_11 , V_135 , & V_22 ) ;
if ( V_127 & V_26 )
F_8 ( V_11 , V_135 , & V_22 ) ;
if ( V_127 & V_55 )
F_19 ( V_11 , 1 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
static struct V_10 * F_61 ( const char * V_14 )
{
struct V_10 * V_11 , * V_140 ;
V_11 = NULL ;
F_62 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_14 , V_140 -> V_14 ) ) {
V_11 = V_140 ;
break;
}
}
return V_11 ;
}
static int F_63 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_141 ) {
F_18 ( L_18 , V_11 -> V_14 ) ;
return 0 ;
}
V_11 -> V_81 = F_64 ( V_11 -> V_141 ) ;
if ( ! V_11 -> V_81 ) {
F_17 ( L_19 ,
V_11 -> V_14 , V_11 -> V_141 ) ;
return 0 ;
}
F_18 ( L_20 ,
V_11 -> V_14 , V_11 -> V_141 ) ;
return 0 ;
}
static int F_65 ( struct V_10 * V_11 , void * V_142 )
{
int V_87 = 0 ;
if ( V_11 -> V_49 != V_143 )
return 0 ;
F_18 ( L_21 , V_11 -> V_14 ) ;
if ( V_144 . V_85 )
V_87 |= V_144 . V_85 ( V_11 ) ;
V_87 |= F_32 ( V_11 ) ;
V_87 |= F_36 ( V_11 ) ;
V_87 |= F_37 ( V_11 ) ;
if ( ! V_87 )
V_11 -> V_49 = V_145 ;
else
F_17 ( L_22 , V_11 -> V_14 ) ;
return V_87 ;
}
static int F_66 ( struct V_10 * V_11 , const char * V_14 ,
struct V_146 * V_147 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_148 ; V_4 ++ ) {
const char * V_149 = V_11 -> V_150 [ V_4 ] . V_14 ;
if ( ! strcmp ( V_149 , V_14 ) ) {
V_147 -> V_151 = V_11 -> V_150 [ V_4 ] . V_151 ;
V_147 -> V_152 = V_11 -> V_150 [ V_4 ] . V_152 ;
F_18 ( L_23 ,
V_11 -> V_14 , V_101 , V_149 , V_147 -> V_151 ,
V_147 -> V_152 ) ;
return 0 ;
}
}
return - V_121 ;
}
static int F_67 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_146 V_147 ;
int V_87 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_144 . V_153 )
return - V_154 ;
V_87 = F_66 ( V_11 , V_14 , & V_147 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = V_144 . V_153 ( V_11 , & V_147 ) ;
return V_87 ;
}
static int F_68 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_146 V_147 ;
int V_87 = - V_15 ;
int V_155 = 0 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_144 . V_156 )
return - V_154 ;
V_87 = F_66 ( V_11 , V_14 , & V_147 ) ;
if ( V_87 < 0 )
return V_87 ;
if ( V_11 -> V_81 ) {
V_155 = F_69 ( V_11 -> V_81 ) ;
V_87 = F_70 ( V_11 -> V_81 , V_11 ) ;
if ( V_87 ) {
F_4 ( 1 , L_24 ,
V_11 -> V_14 , V_11 -> V_81 -> V_14 , V_87 ) ;
return V_87 ;
}
}
F_38 ( V_11 ) ;
if ( V_144 . V_157 )
V_144 . V_157 ( V_11 ) ;
V_87 = V_144 . V_156 ( V_11 , & V_147 ) ;
if ( V_144 . V_158 )
V_144 . V_158 ( V_11 ) ;
F_40 ( V_11 ) ;
if ( V_87 == - V_159 )
F_17 ( L_25 , V_11 -> V_14 ) ;
if ( ! V_87 ) {
if ( V_11 -> V_81 && V_155 )
F_71 ( V_11 -> V_81 ) ;
} else {
if ( V_11 -> V_81 )
F_72 ( V_11 -> V_81 , V_11 ) ;
}
return V_87 ;
}
static int F_73 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_146 V_147 ;
int V_87 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_144 . V_160 )
return - V_154 ;
V_87 = F_66 ( V_11 , V_14 , & V_147 ) ;
if ( V_87 < 0 )
return V_87 ;
return V_144 . V_160 ( V_11 , & V_147 ) ;
}
static bool F_74 ( struct V_10 * V_11 )
{
int V_4 , V_161 = 0 ;
if ( V_11 -> V_148 == 0 )
return false ;
for ( V_4 = 0 ; V_4 < V_11 -> V_148 ; V_4 ++ )
if ( F_73 ( V_11 , V_11 -> V_150 [ V_4 ] . V_14 ) > 0 )
V_161 ++ ;
if ( V_11 -> V_148 == V_161 )
return true ;
return false ;
}
static bool F_75 ( struct V_10 * V_11 )
{
int V_161 = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_148 && V_161 == 0 ; V_4 ++ )
if ( F_73 ( V_11 , V_11 -> V_150 [ V_4 ] . V_14 ) > 0 )
V_161 ++ ;
return ( V_161 ) ? true : false ;
}
static int F_76 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! V_11 -> V_81 || ! V_11 -> V_98 . V_99 . V_100 )
return - V_15 ;
if ( F_75 ( V_11 ) )
return 0 ;
F_18 ( L_26 , V_11 -> V_14 , V_101 ) ;
F_77 ( V_11 -> V_81 -> V_102 , V_11 -> V_81 -> V_103 ,
V_11 -> V_98 . V_99 . V_104 ) ;
V_22 = F_47 ( V_11 ) ;
if ( V_22 )
F_17 ( L_27 ,
V_11 -> V_14 ) ;
return 0 ;
}
static int F_78 ( struct V_10 * V_11 )
{
T_1 V_22 ;
int V_41 = 0 ;
int V_87 = 0 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_38 ) )
return - V_121 ;
if ( V_11 -> V_49 != V_50 ) {
F_17 ( L_28 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_66 & V_129 )
F_42 ( V_11 ) ;
F_18 ( L_29 , V_11 -> V_14 ) ;
V_22 = V_11 -> V_16 ;
V_87 = F_12 ( V_11 , & V_22 ) ;
if ( V_87 )
goto V_162;
F_6 ( V_22 , V_11 ) ;
if ( V_11 -> V_12 -> V_13 -> V_163 )
F_79 ( V_11 -> V_12 -> V_13 -> V_163 ) ;
V_41 = F_14 ( V_11 ) ;
if ( V_41 == V_45 ) {
F_17 ( L_30 ,
V_11 -> V_14 , V_45 ) ;
V_87 = - V_164 ;
goto V_162;
} else {
F_18 ( L_31 , V_11 -> V_14 , V_41 ) ;
}
V_87 = F_13 ( V_11 , & V_22 ) ;
if ( V_87 )
goto V_162;
F_6 ( V_22 , V_11 ) ;
V_162:
if ( V_11 -> V_66 & V_129 )
F_44 ( V_11 ) ;
return V_87 ;
}
static int F_80 ( struct V_10 * V_11 )
{
int V_4 , V_165 ;
F_18 ( L_32 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_166 ) {
V_165 = V_11 -> V_12 -> V_166 ( V_11 ) ;
} else {
if ( V_11 -> V_148 > 0 ) {
for ( V_4 = 0 ; V_4 < V_11 -> V_148 ; V_4 ++ )
F_67 ( V_11 , V_11 -> V_150 [ V_4 ] . V_14 ) ;
return 0 ;
} else {
V_165 = F_78 ( V_11 ) ;
if ( V_165 == - V_121 )
V_165 = 0 ;
}
}
F_16 ( V_11 ) ;
if ( V_11 -> V_12 -> V_13 ) {
F_3 ( V_11 ) ;
F_58 ( V_11 ) ;
}
return V_165 ;
}
static void F_81 ( void )
{
unsigned long V_66 ;
F_82 ( & V_167 , V_66 ) ;
F_83 () ;
F_84 ( & V_167 , V_66 ) ;
}
static void F_85 ( struct V_10 * V_11 )
{
if ( V_11 -> V_98 . V_99 . V_66 & V_168 )
return;
if ( ! F_86 ( V_11 -> V_81 -> V_169 . V_170 -> V_102 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_98 . V_99 . V_172 ) )
return;
V_11 -> V_98 . V_99 . V_173 ++ ;
F_87 ( V_11 -> V_81 -> V_169 . V_170 -> V_102 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_98 . V_99 . V_172 ) ;
}
static int F_88 ( struct V_10 * V_11 )
{
return V_11 -> V_98 . V_99 . V_173 ;
}
static int F_89 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_12 -> V_174 )
return 0 ;
return V_11 -> V_12 -> V_174 ( V_11 ) ;
}
static int F_90 ( struct V_10 * V_11 )
{
int V_165 ;
int V_155 = 0 ;
F_18 ( L_33 , V_11 -> V_14 ) ;
if ( V_11 -> V_20 & V_175 ) {
if ( V_11 -> V_62 )
F_21 ( V_11 -> V_62 , V_50 ) ;
V_11 -> V_20 &= ~ V_175 ;
return 0 ;
}
if ( V_11 -> V_49 != V_176 &&
V_11 -> V_49 != V_70 &&
V_11 -> V_49 != V_177 ) {
F_4 ( 1 , L_34 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_74 ( V_11 ) )
return 0 ;
if ( V_11 -> V_62 && ( ! V_11 -> V_62 -> V_63 ||
( ( V_11 -> V_49 == V_70 ) &&
V_11 -> V_62 -> V_65 ) ) ) {
F_21 ( V_11 -> V_62 , V_50 ) ;
F_81 () ;
} else if ( V_11 -> V_66 & V_178 ) {
F_81 () ;
}
F_28 ( V_11 , V_179 ) ;
if ( V_11 -> V_81 ) {
V_155 = F_69 ( V_11 -> V_81 ) &&
! F_91 ( V_11 -> V_81 ) ;
V_165 = F_70 ( V_11 -> V_81 , V_11 ) ;
if ( V_165 ) {
F_4 ( 1 , L_24 ,
V_11 -> V_14 , V_11 -> V_81 -> V_14 , V_165 ) ;
return V_165 ;
}
}
F_38 ( V_11 ) ;
if ( V_144 . V_157 )
V_144 . V_157 ( V_11 ) ;
if ( V_11 -> V_66 & V_180 )
F_92 ( true ) ;
if ( V_144 . V_181 )
V_144 . V_181 ( V_11 ) ;
V_165 = ( V_144 . V_182 ) ? V_144 . V_182 ( V_11 ) :
- V_15 ;
if ( ! V_165 ) {
if ( V_11 -> V_81 && V_155 )
F_71 ( V_11 -> V_81 ) ;
V_11 -> V_49 = V_50 ;
if ( V_11 -> V_12 -> V_13 ) {
if ( ! ( V_11 -> V_20 & V_21 ) )
F_3 ( V_11 ) ;
F_58 ( V_11 ) ;
}
V_165 = F_89 ( V_11 ) ;
} else {
if ( V_144 . V_158 )
V_144 . V_158 ( V_11 ) ;
F_40 ( V_11 ) ;
F_18 ( L_35 ,
V_11 -> V_14 , V_165 ) ;
if ( V_11 -> V_81 )
F_72 ( V_11 -> V_81 , V_11 ) ;
}
return V_165 ;
}
static int F_93 ( struct V_10 * V_11 )
{
F_18 ( L_36 , V_11 -> V_14 ) ;
if ( V_11 -> V_49 != V_50 ) {
F_4 ( 1 , L_37 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_74 ( V_11 ) )
return 0 ;
if ( V_11 -> V_12 -> V_13 )
F_59 ( V_11 ) ;
F_30 ( V_11 , V_179 ) ;
if ( V_11 -> V_66 & V_180 )
F_92 ( false ) ;
if ( V_144 . V_158 )
V_144 . V_158 ( V_11 ) ;
F_40 ( V_11 ) ;
if ( V_11 -> V_81 )
F_72 ( V_11 -> V_81 , V_11 ) ;
if ( V_11 -> V_62 && V_11 -> V_62 -> V_65 ) {
F_21 ( V_11 -> V_62 , V_70 ) ;
F_81 () ;
} else if ( V_11 -> V_66 & V_178 ) {
F_81 () ;
}
V_11 -> V_49 = V_70 ;
return 0 ;
}
static int F_94 ( struct V_10 * V_11 )
{
int V_87 , V_4 ;
T_2 V_183 ;
if ( V_11 -> V_49 != V_70 &&
V_11 -> V_49 != V_50 ) {
F_4 ( 1 , L_38 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_74 ( V_11 ) )
return 0 ;
F_18 ( L_39 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_184 ) {
V_183 = V_11 -> V_49 ;
if ( V_11 -> V_49 == V_70 )
F_90 ( V_11 ) ;
V_87 = V_11 -> V_12 -> V_184 ( V_11 ) ;
if ( V_87 ) {
if ( V_183 == V_70 )
F_93 ( V_11 ) ;
return V_87 ;
}
}
if ( V_11 -> V_12 -> V_13 ) {
if ( V_11 -> V_49 == V_70 )
F_90 ( V_11 ) ;
F_60 ( V_11 ) ;
}
if ( V_11 -> V_49 == V_50 ) {
F_30 ( V_11 , V_179 ) ;
if ( V_11 -> V_66 & V_180 )
F_92 ( false ) ;
if ( V_144 . V_158 )
V_144 . V_158 ( V_11 ) ;
F_40 ( V_11 ) ;
if ( V_11 -> V_81 )
F_72 ( V_11 -> V_81 , V_11 ) ;
}
for ( V_4 = 0 ; V_4 < V_11 -> V_148 ; V_4 ++ )
F_67 ( V_11 , V_11 -> V_150 [ V_4 ] . V_14 ) ;
if ( V_11 -> V_62 )
F_21 ( V_11 -> V_62 , V_177 ) ;
V_11 -> V_49 = V_177 ;
return 0 ;
}
static int F_95 ( struct V_185 * V_186 ,
struct V_10 * V_11 )
{
int V_187 , V_4 , V_188 ;
const char * V_3 ;
V_187 = F_96 ( V_186 , L_40 ) ;
if ( V_187 < 1 )
return - V_189 ;
for ( V_4 = 0 ; V_4 < V_187 ; V_4 ++ ) {
V_188 = F_97 ( V_186 , L_40 ,
V_4 , & V_3 ) ;
if ( V_188 )
continue;
if ( ! strcmp ( V_3 , V_11 -> V_14 ) ) {
F_18 ( L_41 ,
V_186 -> V_14 , V_4 , V_11 -> V_14 ) ;
return V_4 ;
}
}
return - V_189 ;
}
static int F_98 ( struct V_185 * V_186 ,
struct V_10 * V_11 ,
int * V_190 ,
struct V_185 * * V_120 )
{
struct V_185 * V_191 = NULL ;
int V_188 ;
V_188 = F_95 ( V_186 , V_11 ) ;
if ( V_188 >= 0 ) {
* V_120 = V_186 ;
* V_190 = V_188 ;
return 0 ;
}
F_99 (np, np0) {
struct V_185 * V_192 ;
int V_4 ;
V_188 = F_98 ( V_191 , V_11 , & V_4 , & V_192 ) ;
if ( V_188 == 0 ) {
* V_120 = V_192 ;
* V_190 = V_4 ;
return 0 ;
}
}
* V_120 = NULL ;
* V_190 = 0 ;
return - V_189 ;
}
static int T_4 F_100 ( struct V_10 * V_11 , void * V_142 ,
int V_190 , struct V_185 * V_186 )
{
struct V_115 * V_116 ;
void T_5 * va_start = NULL ;
if ( ! V_11 )
return - V_15 ;
F_55 ( V_11 ) ;
if ( V_11 -> V_20 & V_105 )
return - V_193 ;
V_116 = F_57 ( V_11 ) ;
if ( ! V_116 ) {
F_18 ( L_42 ,
V_11 -> V_14 ) ;
if ( ! V_186 )
return - V_193 ;
va_start = F_101 ( V_186 , V_190 + V_11 -> V_194 ) ;
} else {
va_start = F_102 ( V_116 -> V_118 , V_116 -> V_119 - V_116 -> V_118 ) ;
}
if ( ! va_start ) {
if ( V_116 )
F_103 ( L_43 , V_11 -> V_14 ) ;
else
F_103 ( L_44 ,
V_11 -> V_14 , V_190 , V_186 -> V_195 ) ;
return - V_193 ;
}
F_18 ( L_45 ,
V_11 -> V_14 , va_start ) ;
V_11 -> V_196 = va_start ;
return 0 ;
}
static int T_4 F_104 ( struct V_10 * V_11 , void * V_142 )
{
int V_165 , V_190 ;
struct V_185 * V_186 = NULL ;
if ( V_11 -> V_49 != V_143 )
return 0 ;
if ( F_105 () ) {
struct V_185 * V_197 ;
V_197 = F_106 ( NULL , L_46 ) ;
if ( ! V_197 )
return - V_189 ;
V_165 = F_98 ( V_197 , V_11 , & V_190 , & V_186 ) ;
if ( V_165 )
F_18 ( L_47 , V_11 -> V_14 ) ;
else if ( V_186 && V_190 )
F_17 ( L_48 ,
V_11 -> V_14 , V_186 -> V_14 ) ;
}
if ( V_11 -> V_12 -> V_13 ) {
V_165 = F_100 ( V_11 , NULL , V_190 , V_186 ) ;
if ( V_165 < 0 ) {
F_4 ( 1 , L_49 ,
V_11 -> V_14 ) ;
return 0 ;
}
}
V_165 = F_65 ( V_11 , NULL ) ;
if ( V_165 < 0 ) {
F_4 ( 1 , L_50 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_186 ) {
if ( F_107 ( V_186 , L_51 , NULL ) )
V_11 -> V_66 |= V_198 ;
if ( F_107 ( V_186 , L_52 , NULL ) )
V_11 -> V_66 |= V_199 ;
}
V_11 -> V_49 = V_176 ;
return 0 ;
}
static void T_4 F_108 ( struct V_10 * V_11 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( V_11 -> V_49 != V_176 )
return;
V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_89 -> V_82 )
continue;
if ( V_89 -> V_66 & V_96 ) {
} else {
F_39 ( V_89 -> V_82 ) ;
}
}
return;
}
static int T_4 F_109 ( struct V_10 * V_11 )
{
int V_165 ;
if ( V_11 -> V_49 != V_176 )
return - V_15 ;
if ( V_11 -> V_66 & V_200 )
return - V_201 ;
if ( V_11 -> V_148 == 0 ) {
V_165 = F_90 ( V_11 ) ;
if ( V_165 ) {
F_17 ( L_53 ,
V_11 -> V_14 , V_11 -> V_49 ) ;
return - V_15 ;
}
}
if ( ! ( V_11 -> V_66 & V_198 ) )
V_165 = F_80 ( V_11 ) ;
return V_165 ;
}
static void T_4 F_110 ( struct V_10 * V_11 )
{
T_2 V_202 ;
if ( V_11 -> V_148 > 0 )
return;
V_202 = V_11 -> V_203 ;
if ( V_202 == V_204 )
V_202 = V_50 ;
if ( ( V_11 -> V_66 & V_199 ) &&
( V_202 == V_70 ) ) {
V_11 -> V_20 |= V_175 ;
V_202 = V_50 ;
}
if ( V_202 == V_70 )
F_93 ( V_11 ) ;
else if ( V_202 == V_177 )
F_94 ( V_11 ) ;
else if ( V_202 != V_50 )
F_4 ( 1 , L_54 ,
V_11 -> V_14 , V_202 ) ;
return;
}
static int T_4 F_111 ( struct V_10 * V_11 , void * V_142 )
{
if ( V_11 -> V_49 != V_176 )
return 0 ;
if ( V_11 -> V_205 ) {
int V_165 ;
V_165 = F_90 ( V_11 -> V_205 ) ;
F_4 ( V_165 , L_55 ,
V_11 -> V_14 , V_11 -> V_205 -> V_14 ) ;
}
F_108 ( V_11 ) ;
if ( ! F_109 ( V_11 ) )
F_110 ( V_11 ) ;
if ( V_11 -> V_205 ) {
T_2 V_202 ;
V_202 = V_11 -> V_205 -> V_203 ;
if ( V_202 == V_70 )
F_93 ( V_11 -> V_205 ) ;
else if ( V_202 == V_177 )
F_94 ( V_11 -> V_205 ) ;
else if ( V_202 != V_50 )
F_4 ( 1 , L_54 ,
V_11 -> V_205 -> V_14 , V_202 ) ;
}
return 0 ;
}
static int T_4 F_112 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_14 || ! V_11 -> V_12 || ! V_11 -> V_12 -> V_14 ||
( V_11 -> V_49 != V_204 ) )
return - V_15 ;
F_18 ( L_56 , V_11 -> V_14 ) ;
if ( F_61 ( V_11 -> V_14 ) )
return - V_206 ;
F_113 ( & V_11 -> V_7 , & V_207 ) ;
F_114 ( & V_11 -> V_208 ) ;
F_114 ( & V_11 -> V_90 ) ;
F_115 ( & V_11 -> V_209 ) ;
V_11 -> V_49 = V_143 ;
if ( ! strcmp ( V_11 -> V_14 , V_210 ) )
V_179 = V_11 ;
return 0 ;
}
static int T_4 F_116 ( struct V_6 * * V_211 ,
struct V_6 * * V_212 )
{
unsigned int V_213 ;
if ( ( V_214 + V_215 ) <= V_216 ) {
* V_211 = & V_217 [ V_214 ++ ] ;
* V_212 = & V_217 [ V_214 ++ ] ;
return 0 ;
}
V_213 = sizeof( struct V_6 ) * V_215 ;
* V_212 = NULL ;
* V_211 = F_117 ( V_213 , 0 ) ;
* V_212 = ( void * ) ( * V_211 ) + sizeof( struct V_6 ) ;
V_218 ++ ;
F_18 ( L_57 ,
V_218 * V_215 ) ;
return 0 ;
}
static int T_4 F_118 ( struct V_1 * V_5 )
{
struct V_6 * V_211 , * V_212 ;
F_18 ( L_58 , V_5 -> V_219 -> V_14 ,
V_5 -> V_220 -> V_14 ) ;
F_116 ( & V_211 , & V_212 ) ;
V_211 -> V_8 = V_5 ;
F_119 ( & V_211 -> V_7 , & V_5 -> V_219 -> V_208 ) ;
V_5 -> V_219 -> V_221 ++ ;
V_212 -> V_8 = V_5 ;
F_119 ( & V_212 -> V_7 , & V_5 -> V_220 -> V_90 ) ;
V_5 -> V_220 -> V_91 ++ ;
return 0 ;
}
static int T_4 F_120 ( struct V_1 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_219 || ! V_5 -> V_220 || ! V_5 -> V_123 )
return - V_15 ;
if ( V_5 -> V_20 & V_222 )
return - V_206 ;
F_18 ( L_59 ,
V_5 -> V_219 -> V_14 , V_5 -> V_220 -> V_14 ) ;
if ( V_5 -> V_219 -> V_49 != V_143 )
F_112 ( V_5 -> V_219 ) ;
if ( V_5 -> V_220 -> V_49 != V_143 )
F_112 ( V_5 -> V_220 ) ;
F_118 ( V_5 ) ;
V_5 -> V_20 |= V_222 ;
return 0 ;
}
static int T_4 F_121 ( struct V_1 * * V_223 )
{
unsigned int V_4 = 0 ;
unsigned int V_213 ;
if ( V_217 ) {
F_4 ( 1 , L_60 ) ;
return - V_206 ;
}
if ( V_216 == 0 )
while ( V_223 [ V_4 ++ ] )
V_216 += V_215 ;
V_213 = sizeof( struct V_6 ) * V_216 ;
F_18 ( L_61 ,
V_101 , V_213 , V_216 ) ;
V_217 = F_117 ( V_213 , 0 ) ;
return 0 ;
}
static int F_122 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_106 )
return 0 ;
if ( ! F_56 ( V_11 ) )
return 0 ;
return F_123 ( 0 , V_11 -> V_98 . V_224 . V_225 ,
V_11 -> V_98 . V_224 . V_226 ,
V_11 -> V_98 . V_224 . V_227 ) ;
}
static int F_124 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_106 || ! V_11 -> V_81 )
return 0 ;
if ( ! F_56 ( V_11 ) )
return 0 ;
return F_123 ( V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_98 . V_99 . V_104 , 0 ) ;
}
static int F_125 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_126 ( V_147 -> V_151 , 0 ,
V_11 -> V_98 . V_224 . V_225 , 0 ) ;
}
static int F_127 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_128 ( V_147 -> V_151 , V_147 -> V_152 , 0 ,
V_11 -> V_98 . V_224 . V_225 , 0 , 0 ) ;
}
static int F_129 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_130 ( V_147 -> V_152 , 0 ,
V_11 -> V_98 . V_224 . V_225 , 0 ) ;
}
static int F_131 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
return F_126 ( V_147 -> V_151 ,
V_11 -> V_81 -> V_169 . V_170 -> V_102 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_98 . V_99 . V_228 ) ;
}
static int F_132 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
if ( V_147 -> V_152 )
F_103 ( L_62 ,
V_11 -> V_14 , V_147 -> V_14 ) ;
return F_128 ( V_147 -> V_151 , 0 ,
V_11 -> V_81 -> V_169 . V_170 -> V_102 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_98 . V_99 . V_228 , 0 ) ;
}
static int F_133 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
return F_130 ( V_147 -> V_151 ,
V_11 -> V_81 -> V_169 . V_170 ->
V_102 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_98 . V_99 . V_228 ) ;
}
static int F_134 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_126 ( V_147 -> V_151 , 0 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_98 . V_99 . V_228 ) ;
}
static int F_135 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_128 ( V_147 -> V_151 , V_147 -> V_152 , 0 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_98 . V_99 . V_228 ,
V_11 -> V_98 . V_99 . V_229 ) ;
}
static int F_136 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_130 ( V_147 -> V_151 , 0 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_98 . V_99 . V_228 ) ;
}
T_1 F_5 ( struct V_10 * V_11 , T_3 V_230 )
{
if ( V_11 -> V_66 & V_231 )
return F_137 ( V_11 -> V_196 + V_230 ) ;
else
return F_138 ( V_11 -> V_196 + V_230 ) ;
}
void F_7 ( T_1 V_22 , struct V_10 * V_11 , T_3 V_230 )
{
if ( V_11 -> V_66 & V_231 )
F_139 ( V_22 , V_11 -> V_196 + V_230 ) ;
else
F_140 ( V_22 , V_11 -> V_196 + V_230 ) ;
}
int F_141 ( struct V_10 * V_11 )
{
T_1 V_22 ;
int V_87 ;
if ( ! V_11 || ! ( V_11 -> V_16 ) )
return - V_15 ;
V_22 = V_11 -> V_16 ;
V_87 = F_12 ( V_11 , & V_22 ) ;
if ( V_87 )
goto error;
F_6 ( V_22 , V_11 ) ;
V_87 = F_13 ( V_11 , & V_22 ) ;
if ( V_87 )
goto error;
F_6 ( V_22 , V_11 ) ;
error:
return V_87 ;
}
struct V_10 * F_142 ( const char * V_14 )
{
struct V_10 * V_11 ;
if ( ! V_14 )
return NULL ;
V_11 = F_61 ( V_14 ) ;
return V_11 ;
}
int F_143 ( int (* F_144)( struct V_10 * V_11 , void * V_142 ) ,
void * V_142 )
{
struct V_10 * V_140 ;
int V_87 = 0 ;
if ( ! F_144 )
return - V_15 ;
F_62 (temp_oh, &omap_hwmod_list, node) {
V_87 = (* F_144)( V_140 , V_142 ) ;
if ( V_87 )
break;
}
return V_87 ;
}
int T_4 F_145 ( struct V_1 * * V_223 )
{
int V_165 , V_4 ;
if ( ! V_232 )
return - V_15 ;
if ( ! V_223 )
return 0 ;
if ( V_223 [ 0 ] == NULL )
return 0 ;
if ( ! V_217 ) {
if ( F_121 ( V_223 ) ) {
F_103 ( L_63 ) ;
return - V_233 ;
}
}
V_4 = 0 ;
do {
V_165 = F_120 ( V_223 [ V_4 ] ) ;
F_4 ( V_165 && V_165 != - V_206 ,
L_64 ,
V_223 [ V_4 ] -> V_219 -> V_14 , V_223 [ V_4 ] -> V_220 -> V_14 , V_165 ) ;
} while ( V_223 [ ++ V_4 ] );
return 0 ;
}
static void T_4 F_146 ( struct V_10 * V_11 )
{
if ( ! V_179 || V_179 -> V_49 == V_204 )
F_103 ( L_65 ,
V_101 , V_210 ) ;
else if ( V_179 -> V_49 == V_143 && V_11 != V_179 )
F_147 ( V_210 ) ;
}
int T_4 F_147 ( const char * V_234 )
{
struct V_10 * V_11 ;
F_18 ( L_26 , V_234 , V_101 ) ;
V_11 = F_61 ( V_234 ) ;
if ( ! V_11 ) {
F_4 ( 1 , L_66 , V_234 ) ;
return - V_15 ;
}
F_146 ( V_11 ) ;
F_104 ( V_11 , NULL ) ;
F_111 ( V_11 , NULL ) ;
return 0 ;
}
static int T_4 F_148 ( void )
{
F_146 ( NULL ) ;
F_143 ( F_104 , NULL ) ;
F_143 ( F_111 , NULL ) ;
return 0 ;
}
int F_149 ( struct V_10 * V_11 )
{
int V_165 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_82 ( & V_11 -> V_209 , V_66 ) ;
V_165 = F_90 ( V_11 ) ;
F_84 ( & V_11 -> V_209 , V_66 ) ;
return V_165 ;
}
int F_150 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_82 ( & V_11 -> V_209 , V_66 ) ;
F_93 ( V_11 ) ;
F_84 ( & V_11 -> V_209 , V_66 ) ;
return 0 ;
}
int F_151 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_82 ( & V_11 -> V_209 , V_66 ) ;
F_94 ( V_11 ) ;
F_84 ( & V_11 -> V_209 , V_66 ) ;
return 0 ;
}
int F_152 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
F_82 ( & V_11 -> V_209 , V_66 ) ;
F_38 ( V_11 ) ;
F_84 ( & V_11 -> V_209 , V_66 ) ;
return 0 ;
}
int F_153 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
F_82 ( & V_11 -> V_209 , V_66 ) ;
F_40 ( V_11 ) ;
F_84 ( & V_11 -> V_209 , V_66 ) ;
return 0 ;
}
void F_154 ( struct V_10 * V_11 )
{
F_155 ( ! V_11 ) ;
if ( ! V_11 -> V_12 -> V_13 || ! V_11 -> V_12 -> V_13 -> V_18 ) {
F_4 ( 1 , L_67 ,
V_11 -> V_14 ) ;
return;
}
F_5 ( V_11 , V_11 -> V_12 -> V_13 -> V_17 ) ;
}
int F_156 ( struct V_10 * V_11 )
{
int V_165 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_82 ( & V_11 -> V_209 , V_66 ) ;
V_165 = F_80 ( V_11 ) ;
F_84 ( & V_11 -> V_209 , V_66 ) ;
return V_165 ;
}
int F_157 ( struct V_10 * V_11 , unsigned long V_66 )
{
int V_87 = 0 ;
if ( V_66 & V_235 )
V_87 += F_49 ( V_11 ) ;
if ( V_66 & V_236 )
V_87 += F_50 ( V_11 ) ;
if ( V_66 & V_237 ) {
int V_4 = 0 ;
struct V_1 * V_89 ;
struct V_2 * V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
V_87 += F_51 ( V_89 ) ;
}
}
return V_87 ;
}
int F_158 ( struct V_10 * V_11 , struct V_238 * V_188 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
int V_4 , V_61 , V_239 , V_240 , V_241 ;
int V_165 = 0 ;
V_239 = F_49 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_239 ; V_4 ++ ) {
unsigned int V_110 ;
if ( V_11 -> V_242 )
V_110 = V_11 -> V_242 ( ( V_11 -> V_109 + V_4 ) -> V_110 ) ;
else
V_110 = ( V_11 -> V_109 + V_4 ) -> V_110 ;
( V_188 + V_165 ) -> V_14 = ( V_11 -> V_109 + V_4 ) -> V_14 ;
( V_188 + V_165 ) -> V_243 = V_110 ;
( V_188 + V_165 ) -> V_244 = V_110 ;
( V_188 + V_165 ) -> V_66 = V_235 ;
V_165 ++ ;
}
V_240 = F_50 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_240 ; V_4 ++ ) {
( V_188 + V_165 ) -> V_14 = ( V_11 -> V_113 + V_4 ) -> V_14 ;
( V_188 + V_165 ) -> V_243 = ( V_11 -> V_113 + V_4 ) -> V_114 ;
( V_188 + V_165 ) -> V_244 = ( V_11 -> V_113 + V_4 ) -> V_114 ;
( V_188 + V_165 ) -> V_66 = V_236 ;
V_165 ++ ;
}
V_3 = V_11 -> V_90 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
V_241 = F_51 ( V_89 ) ;
for ( V_61 = 0 ; V_61 < V_241 ; V_61 ++ ) {
( V_188 + V_165 ) -> V_14 = ( V_89 -> V_117 + V_61 ) -> V_14 ;
( V_188 + V_165 ) -> V_243 = ( V_89 -> V_117 + V_61 ) -> V_118 ;
( V_188 + V_165 ) -> V_244 = ( V_89 -> V_117 + V_61 ) -> V_119 ;
( V_188 + V_165 ) -> V_66 = V_237 ;
V_165 ++ ;
}
}
return V_165 ;
}
int F_159 ( struct V_10 * V_11 , struct V_238 * V_188 )
{
int V_4 , V_240 ;
int V_165 = 0 ;
V_240 = F_50 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_240 ; V_4 ++ ) {
( V_188 + V_165 ) -> V_14 = ( V_11 -> V_113 + V_4 ) -> V_14 ;
( V_188 + V_165 ) -> V_243 = ( V_11 -> V_113 + V_4 ) -> V_114 ;
( V_188 + V_165 ) -> V_244 = ( V_11 -> V_113 + V_4 ) -> V_114 ;
( V_188 + V_165 ) -> V_66 = V_236 ;
V_165 ++ ;
}
return V_165 ;
}
int F_160 ( struct V_10 * V_11 , unsigned int type ,
const char * V_14 , struct V_238 * V_245 )
{
int V_165 ;
unsigned int V_110 , V_122 ;
T_1 V_118 , V_119 ;
if ( ! V_11 || ! V_245 )
return - V_15 ;
if ( type == V_235 ) {
V_165 = F_52 ( V_11 , V_14 , & V_110 ) ;
if ( V_165 )
return V_165 ;
V_245 -> V_243 = V_110 ;
V_245 -> V_244 = V_110 ;
} else if ( type == V_236 ) {
V_165 = F_53 ( V_11 , V_14 , & V_122 ) ;
if ( V_165 )
return V_165 ;
V_245 -> V_243 = V_122 ;
V_245 -> V_244 = V_122 ;
} else if ( type == V_237 ) {
V_165 = F_54 ( V_11 , V_14 , & V_118 , & V_119 ) ;
if ( V_165 )
return V_165 ;
V_245 -> V_243 = V_118 ;
V_245 -> V_244 = V_119 ;
} else {
return - V_15 ;
}
V_245 -> V_66 = type ;
V_245 -> V_14 = V_14 ;
return 0 ;
}
struct V_246 * F_161 ( struct V_10 * V_11 )
{
struct V_80 * V_41 ;
struct V_1 * V_5 ;
struct V_78 * V_81 ;
struct V_79 * V_80 ;
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_81 )
return V_11 -> V_81 -> V_169 . V_170 ;
if ( V_11 -> V_82 ) {
V_41 = V_11 -> V_82 ;
} else {
V_5 = F_56 ( V_11 ) ;
if ( ! V_5 )
return NULL ;
V_41 = V_5 -> V_82 ;
}
V_80 = F_26 ( F_27 ( V_41 ) ) ;
V_81 = V_80 -> V_81 ;
if ( ! V_81 )
return NULL ;
return V_81 -> V_169 . V_170 ;
}
void T_5 * F_162 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_20 & V_105 )
return NULL ;
if ( V_11 -> V_49 == V_204 )
return NULL ;
return V_11 -> V_196 ;
}
int F_163 ( struct V_10 * V_11 ,
struct V_10 * V_84 )
{
return F_28 ( V_11 , V_84 ) ;
}
int F_164 ( struct V_10 * V_11 ,
struct V_10 * V_84 )
{
return F_30 ( V_11 , V_84 ) ;
}
int F_165 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
T_1 V_22 ;
F_82 ( & V_11 -> V_209 , V_66 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ) {
V_22 = V_11 -> V_16 ;
F_22 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_20 ( V_11 , true ) ;
F_84 ( & V_11 -> V_209 , V_66 ) ;
return 0 ;
}
int F_166 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
T_1 V_22 ;
F_82 ( & V_11 -> V_209 , V_66 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ) {
V_22 = V_11 -> V_16 ;
F_23 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_20 ( V_11 , false ) ;
F_84 ( & V_11 -> V_209 , V_66 ) ;
return 0 ;
}
int F_167 ( struct V_10 * V_11 , const char * V_14 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_82 ( & V_11 -> V_209 , V_66 ) ;
V_87 = F_67 ( V_11 , V_14 ) ;
F_84 ( & V_11 -> V_209 , V_66 ) ;
return V_87 ;
}
int F_168 ( struct V_10 * V_11 , const char * V_14 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_82 ( & V_11 -> V_209 , V_66 ) ;
V_87 = F_68 ( V_11 , V_14 ) ;
F_84 ( & V_11 -> V_209 , V_66 ) ;
return V_87 ;
}
int F_169 ( struct V_10 * V_11 , const char * V_14 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_82 ( & V_11 -> V_209 , V_66 ) ;
V_87 = F_73 ( V_11 , V_14 ) ;
F_84 ( & V_11 -> V_209 , V_66 ) ;
return V_87 ;
}
int F_170 ( const char * V_247 ,
int (* F_144)( struct V_10 * V_11 ,
void * V_123 ) ,
void * V_123 )
{
struct V_10 * V_140 ;
int V_87 = 0 ;
if ( ! V_247 || ! F_144 )
return - V_15 ;
F_18 ( L_68 ,
V_101 , V_247 ) ;
F_62 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_140 -> V_12 -> V_14 , V_247 ) ) {
F_18 ( L_69 ,
V_101 , V_140 -> V_14 ) ;
V_87 = (* F_144)( V_140 , V_123 ) ;
if ( V_87 )
break;
}
}
if ( V_87 )
F_18 ( L_70 ,
V_101 , V_87 ) ;
return V_87 ;
}
int F_171 ( struct V_10 * V_11 , T_2 V_248 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
if ( V_248 != V_177 &&
V_248 != V_50 &&
V_248 != V_70 )
return - V_15 ;
F_82 ( & V_11 -> V_209 , V_66 ) ;
if ( V_11 -> V_49 != V_143 ) {
V_87 = - V_15 ;
goto V_249;
}
V_11 -> V_203 = V_248 ;
V_87 = 0 ;
V_249:
F_84 ( & V_11 -> V_209 , V_66 ) ;
return V_87 ;
}
int F_172 ( struct V_10 * V_11 )
{
struct V_246 * V_169 ;
int V_87 = 0 ;
if ( V_144 . V_250 )
return V_144 . V_250 ( V_11 ) ;
V_169 = F_161 ( V_11 ) ;
if ( V_169 )
V_87 = F_173 ( V_169 ) ;
return V_87 ;
}
int F_174 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_49 != V_143 ) {
F_103 ( L_71 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_66 |= V_198 ;
return 0 ;
}
int F_175 ( struct V_10 * V_11 , int V_251 , int V_252 )
{
int V_253 ;
F_176 () ;
if ( ! V_11 || ! V_11 -> V_62 || ! V_11 -> V_109 || V_251 < 0 ||
V_251 >= V_11 -> V_62 -> V_64 )
return - V_15 ;
for ( V_253 = 0 ; V_11 -> V_109 [ V_253 ] . V_110 >= 0 ; V_253 ++ )
;
if ( V_252 >= V_253 )
return - V_15 ;
if ( ! V_11 -> V_62 -> V_254 ) {
V_11 -> V_62 -> V_254 = F_177 ( sizeof( int ) * V_11 -> V_62 -> V_64 ,
V_255 ) ;
if ( ! V_11 -> V_62 -> V_254 )
return - V_233 ;
}
V_11 -> V_62 -> V_254 [ V_251 ] = V_252 ;
return 0 ;
}
void T_4 F_178 ( void )
{
if ( F_179 () ) {
V_144 . V_182 = F_122 ;
V_144 . V_153 = F_125 ;
V_144 . V_156 = F_127 ;
V_144 . V_160 = F_129 ;
} else if ( F_180 () ) {
V_144 . V_182 = F_122 ;
V_144 . V_153 = F_125 ;
V_144 . V_156 = F_127 ;
V_144 . V_160 = F_129 ;
V_144 . V_85 = F_63 ;
} else if ( F_181 () || F_182 () || F_183 () ) {
V_144 . V_157 = F_45 ;
V_144 . V_158 = F_76 ;
V_144 . V_182 = F_124 ;
V_144 . V_153 = F_131 ;
V_144 . V_156 = F_132 ;
V_144 . V_160 = F_133 ;
V_144 . V_85 = F_63 ;
V_144 . V_181 = F_85 ;
V_144 . V_250 = F_88 ;
} else if ( F_184 () ) {
V_144 . V_157 = F_45 ;
V_144 . V_158 = F_76 ;
V_144 . V_182 = F_124 ;
V_144 . V_153 = F_131 ;
V_144 . V_156 = F_132 ;
V_144 . V_160 = F_133 ;
V_144 . V_85 = F_63 ;
} else if ( F_185 () ) {
V_144 . V_157 = F_45 ;
V_144 . V_158 = F_76 ;
V_144 . V_182 = F_124 ;
V_144 . V_153 = F_134 ;
V_144 . V_156 = F_135 ;
V_144 . V_160 = F_136 ;
V_144 . V_85 = F_63 ;
} else {
F_4 ( 1 , L_72 ) ;
}
V_232 = true ;
}
const char * F_186 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
return V_11 -> V_88 ;
}
