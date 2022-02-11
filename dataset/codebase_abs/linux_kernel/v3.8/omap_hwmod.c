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
static int F_13 ( struct V_10 * V_11 )
{
struct V_40 * V_13 ;
T_1 V_37 ;
int V_41 = 0 ;
V_13 = V_11 -> V_12 -> V_13 ;
if ( V_13 -> V_18 & V_42 )
F_14 ( ( F_5 ( V_11 , V_13 -> V_43 )
& V_44 ) ,
V_45 , V_41 ) ;
else if ( V_13 -> V_18 & V_46 ) {
V_37 = ( 0x1 << V_13 -> V_27 -> V_39 ) ;
F_14 ( ! ( F_5 ( V_11 , V_13 -> V_17 )
& V_37 ) ,
V_45 , V_41 ) ;
}
return V_41 ;
}
static int F_15 ( struct V_10 * V_11 )
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
F_16 ( L_4 , V_11 -> V_14 ) ;
return - V_15 ;
}
F_17 ( L_5 , V_11 -> V_14 ) ;
V_22 = V_11 -> V_16 ;
V_47 =
( 0x1 << V_11 -> V_12 -> V_13 -> V_27 -> V_51 ) ;
V_22 |= V_47 ;
F_6 ( V_22 , V_11 ) ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 , T_2 V_52 ,
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
static void F_19 ( struct V_10 * V_11 , bool V_56 )
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
F_20 ( V_11 -> V_62 , V_70 ) ;
}
static int F_21 ( struct V_10 * V_11 , T_1 * V_22 )
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
V_11 -> V_20 |= V_77 ;
return 0 ;
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
* V_22 &= ~ ( 0x1 << V_11 -> V_12 -> V_13 -> V_27 -> V_75 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_73 )
F_10 ( V_11 , V_78 , V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_74 )
F_8 ( V_11 , V_78 , V_22 ) ;
V_11 -> V_20 &= ~ V_77 ;
return 0 ;
}
static struct V_79 * F_23 ( struct V_10 * V_11 )
{
struct V_80 * V_81 ;
if ( V_11 -> V_82 ) {
return V_11 -> V_82 ;
} else if ( V_11 -> V_83 ) {
V_81 = F_24 ( F_25 ( V_11 -> V_83 ) ) ;
return V_81 -> V_82 ;
}
return NULL ;
}
static int F_26 ( struct V_10 * V_11 , struct V_10 * V_84 )
{
struct V_79 * V_82 , * V_85 ;
V_82 = F_23 ( V_11 ) ;
V_85 = F_23 ( V_84 ) ;
if ( ! V_82 || ! V_85 )
return - V_15 ;
if ( V_82 && V_82 -> V_66 & V_86 )
return 0 ;
return F_27 ( V_82 , V_85 ) ;
}
static int F_28 ( struct V_10 * V_11 , struct V_10 * V_84 )
{
struct V_79 * V_82 , * V_85 ;
V_82 = F_23 ( V_11 ) ;
V_85 = F_23 ( V_84 ) ;
if ( ! V_82 || ! V_85 )
return - V_15 ;
if ( V_82 && V_82 -> V_66 & V_86 )
return 0 ;
return F_29 ( V_82 , V_85 ) ;
}
static int F_30 ( struct V_10 * V_11 )
{
int V_87 = 0 ;
if ( ! V_11 -> V_88 )
return 0 ;
V_11 -> V_83 = F_31 ( NULL , V_11 -> V_88 ) ;
if ( F_32 ( V_11 -> V_83 ) ) {
F_33 ( L_6 ,
V_11 -> V_14 , V_11 -> V_88 ) ;
return - V_15 ;
}
F_34 ( V_11 -> V_83 ) ;
if ( ! F_23 ( V_11 ) )
F_17 ( L_7 ,
V_11 -> V_14 , V_11 -> V_88 ) ;
return V_87 ;
}
static int F_35 ( struct V_10 * V_11 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
struct V_81 * V_41 ;
int V_4 = 0 ;
int V_87 = 0 ;
V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_89 -> V_81 )
continue;
V_41 = F_31 ( NULL , V_89 -> V_81 ) ;
if ( F_32 ( V_41 ) ) {
F_33 ( L_8 ,
V_11 -> V_14 , V_89 -> V_81 ) ;
V_87 = - V_15 ;
}
V_89 -> V_83 = V_41 ;
F_34 ( V_89 -> V_83 ) ;
}
return V_87 ;
}
static int F_36 ( struct V_10 * V_11 )
{
struct V_92 * V_93 ;
struct V_81 * V_41 ;
int V_4 ;
int V_87 = 0 ;
for ( V_4 = V_11 -> V_94 , V_93 = V_11 -> V_95 ; V_4 > 0 ; V_4 -- , V_93 ++ ) {
V_41 = F_31 ( NULL , V_93 -> V_81 ) ;
if ( F_32 ( V_41 ) ) {
F_33 ( L_9 ,
V_11 -> V_14 , V_93 -> V_81 ) ;
V_87 = - V_15 ;
}
V_93 -> V_83 = V_41 ;
F_34 ( V_93 -> V_83 ) ;
}
return V_87 ;
}
static int F_37 ( struct V_10 * V_11 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_17 ( L_10 , V_11 -> V_14 ) ;
if ( V_11 -> V_83 )
F_38 ( V_11 -> V_83 ) ;
V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
if ( V_89 -> V_83 && ( V_89 -> V_66 & V_96 ) )
F_38 ( V_89 -> V_83 ) ;
}
return 0 ;
}
static int F_39 ( struct V_10 * V_11 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_17 ( L_11 , V_11 -> V_14 ) ;
if ( V_11 -> V_83 )
F_40 ( V_11 -> V_83 ) ;
V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
if ( V_89 -> V_83 && ( V_89 -> V_66 & V_96 ) )
F_40 ( V_89 -> V_83 ) ;
}
return 0 ;
}
static void F_41 ( struct V_10 * V_11 )
{
struct V_92 * V_93 ;
int V_4 ;
F_17 ( L_12 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_94 , V_93 = V_11 -> V_95 ; V_4 > 0 ; V_4 -- , V_93 ++ )
if ( V_93 -> V_83 ) {
F_17 ( L_13 , V_93 -> V_97 ,
F_42 ( V_93 -> V_83 ) ) ;
F_38 ( V_93 -> V_83 ) ;
}
}
static void F_43 ( struct V_10 * V_11 )
{
struct V_92 * V_93 ;
int V_4 ;
F_17 ( L_14 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_94 , V_93 = V_11 -> V_95 ; V_4 > 0 ; V_4 -- , V_93 ++ )
if ( V_93 -> V_83 ) {
F_17 ( L_15 , V_93 -> V_97 ,
F_42 ( V_93 -> V_83 ) ) ;
F_40 ( V_93 -> V_83 ) ;
}
}
static void F_44 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_82 || ! V_11 -> V_98 . V_99 . V_100 )
return;
F_17 ( L_16 ,
V_11 -> V_14 , V_101 , V_11 -> V_98 . V_99 . V_100 ) ;
F_45 ( V_11 -> V_98 . V_99 . V_100 ,
V_11 -> V_82 -> V_102 ,
V_11 -> V_82 -> V_103 ,
V_11 -> V_82 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static void F_46 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_82 || ! V_11 -> V_98 . V_99 . V_100 )
return;
F_17 ( L_16 ,
V_11 -> V_14 , V_101 , V_11 -> V_98 . V_99 . V_100 ) ;
F_47 ( V_11 -> V_98 . V_99 . V_100 , V_11 -> V_82 -> V_103 ,
V_11 -> V_82 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_48 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_106 || ! V_11 -> V_82 )
return 0 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
return F_49 ( V_11 -> V_82 -> V_102 ,
V_11 -> V_82 -> V_103 ,
V_11 -> V_82 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_50 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_106 )
return 0 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
return F_51 ( V_11 -> V_82 -> V_103 ,
V_11 -> V_82 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_52 ( struct V_10 * V_11 )
{
struct V_108 * V_109 ;
int V_4 = 0 ;
if ( ! V_11 || ! V_11 -> V_110 )
return 0 ;
do {
V_109 = & V_11 -> V_110 [ V_4 ++ ] ;
} while ( V_109 -> V_111 != - 1 );
return V_4 - 1 ;
}
static int F_53 ( struct V_10 * V_11 )
{
struct V_112 * V_113 ;
int V_4 = 0 ;
if ( ! V_11 || ! V_11 -> V_114 )
return 0 ;
do {
V_113 = & V_11 -> V_114 [ V_4 ++ ] ;
} while ( V_113 -> V_115 != - 1 );
return V_4 - 1 ;
}
static int F_54 ( struct V_1 * V_89 )
{
struct V_116 * V_117 ;
int V_4 = 0 ;
if ( ! V_89 || ! V_89 -> V_118 )
return 0 ;
do {
V_117 = & V_89 -> V_118 [ V_4 ++ ] ;
} while ( V_117 -> V_119 != V_117 -> V_120 );
return V_4 - 1 ;
}
static int F_55 ( struct V_10 * V_11 , const char * V_14 ,
unsigned int * V_111 )
{
int V_4 ;
bool V_121 = false ;
if ( ! V_11 -> V_110 )
return - V_122 ;
V_4 = 0 ;
while ( V_11 -> V_110 [ V_4 ] . V_111 != - 1 ) {
if ( V_14 == V_11 -> V_110 [ V_4 ] . V_14 ||
! strcmp ( V_14 , V_11 -> V_110 [ V_4 ] . V_14 ) ) {
V_121 = true ;
break;
}
V_4 ++ ;
}
if ( ! V_121 )
return - V_122 ;
* V_111 = V_11 -> V_110 [ V_4 ] . V_111 ;
return 0 ;
}
static int F_56 ( struct V_10 * V_11 , const char * V_14 ,
unsigned int * V_123 )
{
int V_4 ;
bool V_121 = false ;
if ( ! V_11 -> V_114 )
return - V_122 ;
V_4 = 0 ;
while ( V_11 -> V_114 [ V_4 ] . V_115 != - 1 ) {
if ( V_14 == V_11 -> V_114 [ V_4 ] . V_14 ||
! strcmp ( V_14 , V_11 -> V_114 [ V_4 ] . V_14 ) ) {
V_121 = true ;
break;
}
V_4 ++ ;
}
if ( ! V_121 )
return - V_122 ;
* V_123 = V_11 -> V_114 [ V_4 ] . V_115 ;
return 0 ;
}
static int F_57 ( struct V_10 * V_11 , const char * V_14 ,
T_1 * V_119 , T_1 * V_120 )
{
int V_4 , V_61 ;
struct V_1 * V_89 ;
struct V_2 * V_3 = NULL ;
bool V_121 = false ;
V_3 = V_11 -> V_90 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_89 -> V_118 )
return - V_122 ;
V_61 = 0 ;
while ( V_89 -> V_118 [ V_61 ] . V_119 != V_89 -> V_118 [ V_61 ] . V_120 ) {
if ( V_14 == V_89 -> V_118 [ V_61 ] . V_14 ||
! strcmp ( V_14 , V_89 -> V_118 [ V_61 ] . V_14 ) ) {
V_121 = true ;
break;
}
V_61 ++ ;
}
if ( V_121 )
break;
}
if ( ! V_121 )
return - V_122 ;
* V_119 = V_89 -> V_118 [ V_61 ] . V_119 ;
* V_120 = V_89 -> V_118 [ V_61 ] . V_120 ;
return 0 ;
}
static void T_4 F_58 ( struct V_10 * V_11 )
{
struct V_1 * V_89 = NULL ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( ! V_11 )
return;
V_11 -> V_20 |= V_106 ;
V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
if ( V_89 -> V_124 & V_125 ) {
V_11 -> V_126 = V_89 ;
V_11 -> V_20 &= ~ V_106 ;
break;
}
}
return;
}
static struct V_1 * F_59 ( struct V_10 * V_11 )
{
if ( ! V_11 || V_11 -> V_20 & V_106 || V_11 -> V_91 == 0 )
return NULL ;
return V_11 -> V_126 ;
}
static struct V_116 * T_4 F_60 ( struct V_10 * V_11 )
{
struct V_1 * V_89 ;
struct V_116 * V_117 ;
int V_121 = 0 , V_4 = 0 ;
V_89 = F_59 ( V_11 ) ;
if ( ! V_89 || ! V_89 -> V_118 )
return NULL ;
do {
V_117 = & V_89 -> V_118 [ V_4 ++ ] ;
if ( V_117 -> V_66 & V_127 )
V_121 = 1 ;
} while ( ! V_121 && V_117 -> V_119 != V_117 -> V_120 );
return ( V_121 ) ? V_117 : NULL ;
}
static void F_61 ( struct V_10 * V_11 )
{
T_2 V_29 , V_128 ;
T_1 V_22 ;
bool V_129 ;
struct V_79 * V_82 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
if ( V_11 -> V_66 & V_130 )
F_41 ( V_11 ) ;
F_13 ( V_11 ) ;
if ( V_11 -> V_66 & V_130 )
F_43 ( V_11 ) ;
V_22 = V_11 -> V_16 ;
V_128 = V_11 -> V_12 -> V_13 -> V_18 ;
V_82 = F_23 ( V_11 ) ;
if ( V_128 & V_32 ) {
V_129 = ( V_82 && V_82 -> V_66 & V_131 ) ;
if ( V_129 && ! ( V_11 -> V_12 -> V_13 -> V_72 &
( V_132 | V_73 ) ) )
V_29 = V_133 ;
else
V_29 = ( V_11 -> V_66 & V_134 ) ?
V_135 : V_78 ;
F_10 ( V_11 , V_29 , & V_22 ) ;
}
if ( V_128 & V_26 ) {
if ( V_11 -> V_66 & V_136 ) {
V_29 = V_135 ;
} else {
if ( V_128 & V_71 )
F_21 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_74 )
V_29 = V_76 ;
else
V_29 = V_78 ;
}
F_8 ( V_11 , V_29 , & V_22 ) ;
}
if ( ( V_11 -> V_66 & V_137 ) &&
( V_128 & V_36 ) )
F_11 ( V_11 , V_11 -> V_12 -> V_13 -> V_33 , & V_22 ) ;
if ( ( V_128 & V_32 ) && ! ( V_11 -> V_66 & V_134 ) )
F_21 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
if ( V_128 & V_55 ) {
V_29 = ( V_11 -> V_66 & V_138 ) ?
0 : 1 ;
F_18 ( V_11 , V_29 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
}
static void F_62 ( struct V_10 * V_11 )
{
T_2 V_29 , V_128 ;
T_1 V_22 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_128 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_128 & V_32 ) {
if ( V_11 -> V_66 & V_134 ||
! ( V_11 -> V_12 -> V_13 -> V_72 &
( V_132 | V_73 ) ) )
V_29 = V_133 ;
else
V_29 = V_78 ;
F_10 ( V_11 , V_29 , & V_22 ) ;
}
if ( V_128 & V_26 ) {
if ( V_11 -> V_66 & V_136 ) {
V_29 = V_133 ;
} else {
if ( V_128 & V_71 )
F_21 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_74 )
V_29 = V_76 ;
else
V_29 = V_78 ;
}
F_8 ( V_11 , V_29 , & V_22 ) ;
}
if ( ( V_128 & V_32 ) && ! ( V_11 -> V_66 & V_134 ) )
F_21 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
static void F_63 ( struct V_10 * V_11 )
{
T_1 V_22 ;
T_2 V_128 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_128 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_128 & V_32 )
F_10 ( V_11 , V_133 , & V_22 ) ;
if ( V_128 & V_26 )
F_8 ( V_11 , V_133 , & V_22 ) ;
if ( V_128 & V_55 )
F_18 ( V_11 , 1 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
static struct V_10 * F_64 ( const char * V_14 )
{
struct V_10 * V_11 , * V_139 ;
V_11 = NULL ;
F_65 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_14 , V_139 -> V_14 ) ) {
V_11 = V_139 ;
break;
}
}
return V_11 ;
}
static int F_66 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_140 ) {
F_17 ( L_17 , V_11 -> V_14 ) ;
return 0 ;
}
V_11 -> V_82 = F_67 ( V_11 -> V_140 ) ;
if ( ! V_11 -> V_82 ) {
F_33 ( L_18 ,
V_11 -> V_14 , V_11 -> V_140 ) ;
return - V_15 ;
}
F_17 ( L_19 ,
V_11 -> V_14 , V_11 -> V_140 ) ;
return 0 ;
}
static int F_68 ( struct V_10 * V_11 , void * V_141 )
{
int V_87 = 0 ;
if ( V_11 -> V_49 != V_142 )
return 0 ;
F_17 ( L_20 , V_11 -> V_14 ) ;
if ( V_143 . V_85 )
V_87 |= V_143 . V_85 ( V_11 ) ;
V_87 |= F_30 ( V_11 ) ;
V_87 |= F_35 ( V_11 ) ;
V_87 |= F_36 ( V_11 ) ;
if ( ! V_87 )
V_11 -> V_49 = V_144 ;
else
F_33 ( L_21 , V_11 -> V_14 ) ;
return V_87 ;
}
static int F_69 ( struct V_10 * V_11 , const char * V_14 ,
struct V_145 * V_146 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_147 ; V_4 ++ ) {
const char * V_148 = V_11 -> V_149 [ V_4 ] . V_14 ;
if ( ! strcmp ( V_148 , V_14 ) ) {
V_146 -> V_150 = V_11 -> V_149 [ V_4 ] . V_150 ;
V_146 -> V_151 = V_11 -> V_149 [ V_4 ] . V_151 ;
F_17 ( L_22 ,
V_11 -> V_14 , V_101 , V_148 , V_146 -> V_150 ,
V_146 -> V_151 ) ;
return 0 ;
}
}
return - V_122 ;
}
static int F_70 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_145 V_146 ;
int V_87 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_143 . V_152 )
return - V_153 ;
V_87 = F_69 ( V_11 , V_14 , & V_146 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = V_143 . V_152 ( V_11 , & V_146 ) ;
return V_87 ;
}
static int F_71 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_145 V_146 ;
int V_87 = - V_15 ;
int V_154 = 0 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_143 . V_155 )
return - V_153 ;
V_87 = F_69 ( V_11 , V_14 , & V_146 ) ;
if ( F_72 ( V_87 ) )
return V_87 ;
if ( V_11 -> V_82 ) {
V_154 = F_73 ( V_11 -> V_82 ) ;
V_87 = F_74 ( V_11 -> V_82 , V_11 ) ;
if ( V_87 ) {
F_4 ( 1 , L_23 ,
V_11 -> V_14 , V_11 -> V_82 -> V_14 , V_87 ) ;
return V_87 ;
}
}
F_37 ( V_11 ) ;
if ( V_143 . V_156 )
V_143 . V_156 ( V_11 ) ;
V_87 = V_143 . V_155 ( V_11 , & V_146 ) ;
if ( V_143 . V_157 )
V_143 . V_157 ( V_11 ) ;
F_39 ( V_11 ) ;
if ( V_87 == - V_158 )
F_33 ( L_24 , V_11 -> V_14 ) ;
if ( ! V_87 ) {
if ( V_11 -> V_82 && V_154 )
F_75 ( V_11 -> V_82 ) ;
} else {
if ( V_11 -> V_82 )
F_76 ( V_11 -> V_82 , V_11 ) ;
}
return V_87 ;
}
static int F_77 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_145 V_146 ;
int V_87 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_143 . V_159 )
return - V_153 ;
V_87 = F_69 ( V_11 , V_14 , & V_146 ) ;
if ( V_87 < 0 )
return V_87 ;
return V_143 . V_159 ( V_11 , & V_146 ) ;
}
static bool F_78 ( struct V_10 * V_11 )
{
int V_4 , V_160 = 0 ;
if ( V_11 -> V_147 == 0 )
return false ;
for ( V_4 = 0 ; V_4 < V_11 -> V_147 ; V_4 ++ )
if ( F_77 ( V_11 , V_11 -> V_149 [ V_4 ] . V_14 ) > 0 )
V_160 ++ ;
if ( V_11 -> V_147 == V_160 )
return true ;
return false ;
}
static bool F_79 ( struct V_10 * V_11 )
{
int V_160 = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_147 && V_160 == 0 ; V_4 ++ )
if ( F_77 ( V_11 , V_11 -> V_149 [ V_4 ] . V_14 ) > 0 )
V_160 ++ ;
return ( V_160 ) ? true : false ;
}
static int F_80 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! V_11 -> V_82 || ! V_11 -> V_98 . V_99 . V_100 )
return - V_15 ;
if ( F_79 ( V_11 ) )
return 0 ;
F_17 ( L_25 , V_11 -> V_14 , V_101 ) ;
F_81 ( V_11 -> V_82 -> V_102 ,
V_11 -> V_82 -> V_103 ,
V_11 -> V_82 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
V_22 = F_48 ( V_11 ) ;
if ( V_22 )
F_16 ( L_26 ,
V_11 -> V_14 ) ;
return 0 ;
}
static int F_82 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! V_11 -> V_82 || ! V_11 -> V_98 . V_99 . V_100 )
return - V_15 ;
F_17 ( L_25 , V_11 -> V_14 , V_101 ) ;
if ( F_79 ( V_11 ) )
return 0 ;
F_83 ( V_11 -> V_82 -> V_103 , V_11 -> V_82 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
V_22 = F_50 ( V_11 ) ;
if ( V_22 )
F_16 ( L_26 ,
V_11 -> V_14 ) ;
return 0 ;
}
static int F_84 ( struct V_10 * V_11 )
{
T_1 V_22 ;
int V_41 = 0 ;
int V_87 = 0 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_38 ) )
return - V_122 ;
if ( V_11 -> V_49 != V_50 ) {
F_16 ( L_27 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_66 & V_130 )
F_41 ( V_11 ) ;
F_17 ( L_28 , V_11 -> V_14 ) ;
V_22 = V_11 -> V_16 ;
V_87 = F_12 ( V_11 , & V_22 ) ;
if ( V_87 )
goto V_161;
F_6 ( V_22 , V_11 ) ;
if ( V_11 -> V_12 -> V_13 -> V_162 )
F_85 ( V_11 -> V_12 -> V_13 -> V_162 ) ;
V_41 = F_13 ( V_11 ) ;
if ( V_41 == V_45 )
F_33 ( L_29 ,
V_11 -> V_14 , V_45 ) ;
else
F_17 ( L_30 , V_11 -> V_14 , V_41 ) ;
V_87 = ( V_41 == V_45 ) ? - V_163 : 0 ;
V_161:
if ( V_11 -> V_66 & V_130 )
F_43 ( V_11 ) ;
return V_87 ;
}
static int F_86 ( struct V_10 * V_11 )
{
int V_4 , V_164 ;
F_17 ( L_31 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_165 ) {
V_164 = V_11 -> V_12 -> V_165 ( V_11 ) ;
} else {
if ( V_11 -> V_147 > 0 ) {
for ( V_4 = 0 ; V_4 < V_11 -> V_147 ; V_4 ++ )
F_70 ( V_11 , V_11 -> V_149 [ V_4 ] . V_14 ) ;
return 0 ;
} else {
V_164 = F_84 ( V_11 ) ;
if ( V_164 == - V_122 )
V_164 = 0 ;
}
}
F_15 ( V_11 ) ;
if ( V_11 -> V_12 -> V_13 ) {
F_3 ( V_11 ) ;
F_61 ( V_11 ) ;
}
return V_164 ;
}
static void F_87 ( void )
{
unsigned long V_66 ;
F_88 ( & V_166 , V_66 ) ;
if ( F_89 () && F_90 () )
F_91 () ;
else if ( F_92 () )
F_93 () ;
F_94 ( & V_166 , V_66 ) ;
}
static void F_95 ( struct V_10 * V_11 )
{
if ( V_11 -> V_98 . V_99 . V_66 & V_167 )
return;
if ( ! F_96 ( V_11 -> V_82 -> V_168 . V_169 -> V_102 ,
V_11 -> V_82 -> V_168 . V_169 -> V_170 ,
V_11 -> V_98 . V_99 . V_171 ) )
return;
V_11 -> V_98 . V_99 . V_172 ++ ;
F_97 ( V_11 -> V_82 -> V_168 . V_169 -> V_102 ,
V_11 -> V_82 -> V_168 . V_169 -> V_170 ,
V_11 -> V_98 . V_99 . V_171 ) ;
}
static int F_98 ( struct V_10 * V_11 )
{
return V_11 -> V_98 . V_99 . V_172 ;
}
static int F_99 ( struct V_10 * V_11 )
{
int V_164 ;
int V_154 = 0 ;
F_17 ( L_32 , V_11 -> V_14 ) ;
if ( V_11 -> V_20 & V_173 ) {
if ( V_11 -> V_62 )
F_20 ( V_11 -> V_62 , V_50 ) ;
V_11 -> V_20 &= ~ V_173 ;
return 0 ;
}
if ( V_11 -> V_49 != V_174 &&
V_11 -> V_49 != V_70 &&
V_11 -> V_49 != V_175 ) {
F_4 ( 1 , L_33 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_78 ( V_11 ) )
return 0 ;
if ( V_11 -> V_62 && ( ! V_11 -> V_62 -> V_63 ||
( ( V_11 -> V_49 == V_70 ) &&
V_11 -> V_62 -> V_65 ) ) ) {
F_20 ( V_11 -> V_62 , V_50 ) ;
F_87 () ;
}
F_26 ( V_11 , V_176 ) ;
if ( V_11 -> V_82 ) {
V_154 = F_73 ( V_11 -> V_82 ) &&
! F_100 ( V_11 -> V_82 ) ;
V_164 = F_74 ( V_11 -> V_82 , V_11 ) ;
if ( V_164 ) {
F_4 ( 1 , L_23 ,
V_11 -> V_14 , V_11 -> V_82 -> V_14 , V_164 ) ;
return V_164 ;
}
}
F_37 ( V_11 ) ;
if ( V_143 . V_156 )
V_143 . V_156 ( V_11 ) ;
if ( V_143 . V_177 )
V_143 . V_177 ( V_11 ) ;
V_164 = ( V_143 . V_178 ) ? V_143 . V_178 ( V_11 ) :
- V_15 ;
if ( ! V_164 ) {
if ( V_11 -> V_82 && V_154 )
F_75 ( V_11 -> V_82 ) ;
V_11 -> V_49 = V_50 ;
if ( V_11 -> V_12 -> V_13 ) {
if ( ! ( V_11 -> V_20 & V_21 ) )
F_3 ( V_11 ) ;
F_61 ( V_11 ) ;
}
} else {
if ( V_143 . V_157 )
V_143 . V_157 ( V_11 ) ;
F_39 ( V_11 ) ;
F_17 ( L_34 ,
V_11 -> V_14 , V_164 ) ;
if ( V_11 -> V_82 )
F_76 ( V_11 -> V_82 , V_11 ) ;
}
return V_164 ;
}
static int F_101 ( struct V_10 * V_11 )
{
F_17 ( L_35 , V_11 -> V_14 ) ;
if ( V_11 -> V_49 != V_50 ) {
F_4 ( 1 , L_36 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_78 ( V_11 ) )
return 0 ;
if ( V_11 -> V_12 -> V_13 )
F_62 ( V_11 ) ;
F_28 ( V_11 , V_176 ) ;
if ( V_143 . V_157 )
V_143 . V_157 ( V_11 ) ;
F_39 ( V_11 ) ;
if ( V_11 -> V_82 )
F_76 ( V_11 -> V_82 , V_11 ) ;
if ( V_11 -> V_62 && V_11 -> V_62 -> V_65 ) {
F_20 ( V_11 -> V_62 , V_70 ) ;
F_87 () ;
}
V_11 -> V_49 = V_70 ;
return 0 ;
}
int F_102 ( struct V_10 * V_11 , T_2 V_52 )
{
T_1 V_22 ;
int V_179 = 0 ;
unsigned long V_66 ;
if ( ! V_11 || V_11 -> V_49 != V_50 )
return - V_15 ;
F_88 ( & V_11 -> V_180 , V_66 ) ;
V_22 = V_11 -> V_16 ;
V_179 = F_18 ( V_11 , V_52 , & V_22 ) ;
if ( ! V_179 )
F_6 ( V_22 , V_11 ) ;
F_94 ( & V_11 -> V_180 , V_66 ) ;
return V_179 ;
}
static int F_103 ( struct V_10 * V_11 )
{
int V_87 , V_4 ;
T_2 V_181 ;
if ( V_11 -> V_49 != V_70 &&
V_11 -> V_49 != V_50 ) {
F_4 ( 1 , L_37 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_78 ( V_11 ) )
return 0 ;
F_17 ( L_38 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_182 ) {
V_181 = V_11 -> V_49 ;
if ( V_11 -> V_49 == V_70 )
F_99 ( V_11 ) ;
V_87 = V_11 -> V_12 -> V_182 ( V_11 ) ;
if ( V_87 ) {
if ( V_181 == V_70 )
F_101 ( V_11 ) ;
return V_87 ;
}
}
if ( V_11 -> V_12 -> V_13 ) {
if ( V_11 -> V_49 == V_70 )
F_99 ( V_11 ) ;
F_63 ( V_11 ) ;
}
if ( V_11 -> V_49 == V_50 ) {
F_28 ( V_11 , V_176 ) ;
if ( V_143 . V_157 )
V_143 . V_157 ( V_11 ) ;
F_39 ( V_11 ) ;
if ( V_11 -> V_82 )
F_76 ( V_11 -> V_82 , V_11 ) ;
}
for ( V_4 = 0 ; V_4 < V_11 -> V_147 ; V_4 ++ )
F_70 ( V_11 , V_11 -> V_149 [ V_4 ] . V_14 ) ;
if ( V_11 -> V_62 )
F_20 ( V_11 -> V_62 , V_175 ) ;
V_11 -> V_49 = V_175 ;
return 0 ;
}
static void T_4 F_104 ( struct V_10 * V_11 , void * V_141 )
{
struct V_116 * V_117 ;
void T_5 * va_start ;
if ( ! V_11 )
return;
F_58 ( V_11 ) ;
if ( V_11 -> V_20 & V_106 )
return;
V_117 = F_60 ( V_11 ) ;
if ( ! V_117 ) {
F_17 ( L_39 ,
V_11 -> V_14 ) ;
return;
}
va_start = F_105 ( V_117 -> V_119 , V_117 -> V_120 - V_117 -> V_119 ) ;
if ( ! va_start ) {
F_106 ( L_40 , V_11 -> V_14 ) ;
return;
}
F_17 ( L_41 ,
V_11 -> V_14 , va_start ) ;
V_11 -> V_183 = va_start ;
}
static int T_4 F_107 ( struct V_10 * V_11 , void * V_141 )
{
int V_164 ;
if ( V_11 -> V_49 != V_142 )
return 0 ;
F_104 ( V_11 , NULL ) ;
V_164 = F_68 ( V_11 , NULL ) ;
if ( F_72 ( V_164 ) ) {
F_4 ( 1 , L_42 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_49 = V_174 ;
return 0 ;
}
static void T_4 F_108 ( struct V_10 * V_11 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( V_11 -> V_49 != V_174 )
return;
V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_89 -> V_83 )
continue;
if ( V_89 -> V_66 & V_96 ) {
} else {
F_38 ( V_89 -> V_83 ) ;
}
}
return;
}
static int T_4 F_109 ( struct V_10 * V_11 )
{
int V_164 ;
if ( V_11 -> V_49 != V_174 )
return - V_15 ;
if ( V_11 -> V_66 & V_184 )
return - V_185 ;
if ( V_11 -> V_147 == 0 ) {
V_164 = F_99 ( V_11 ) ;
if ( V_164 ) {
F_33 ( L_43 ,
V_11 -> V_14 , V_11 -> V_49 ) ;
return - V_15 ;
}
}
if ( ! ( V_11 -> V_66 & V_186 ) )
V_164 = F_86 ( V_11 ) ;
return V_164 ;
}
static void T_4 F_110 ( struct V_10 * V_11 )
{
T_2 V_187 ;
if ( V_11 -> V_147 > 0 )
return;
V_187 = V_11 -> V_188 ;
if ( V_187 == V_189 )
V_187 = V_50 ;
if ( ( V_11 -> V_66 & V_190 ) &&
( V_187 == V_70 ) ) {
V_11 -> V_20 |= V_173 ;
V_187 = V_50 ;
}
if ( V_187 == V_70 )
F_101 ( V_11 ) ;
else if ( V_187 == V_175 )
F_103 ( V_11 ) ;
else if ( V_187 != V_50 )
F_4 ( 1 , L_44 ,
V_11 -> V_14 , V_187 ) ;
return;
}
static int T_4 F_111 ( struct V_10 * V_11 , void * V_141 )
{
if ( V_11 -> V_49 != V_174 )
return 0 ;
F_108 ( V_11 ) ;
if ( ! F_109 ( V_11 ) )
F_110 ( V_11 ) ;
return 0 ;
}
static int T_4 F_112 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_14 || ! V_11 -> V_12 || ! V_11 -> V_12 -> V_14 ||
( V_11 -> V_49 != V_189 ) )
return - V_15 ;
F_17 ( L_45 , V_11 -> V_14 ) ;
if ( F_64 ( V_11 -> V_14 ) )
return - V_191 ;
F_113 ( & V_11 -> V_7 , & V_192 ) ;
F_114 ( & V_11 -> V_193 ) ;
F_114 ( & V_11 -> V_90 ) ;
F_115 ( & V_11 -> V_180 ) ;
V_11 -> V_49 = V_142 ;
if ( ! strcmp ( V_11 -> V_14 , V_194 ) )
V_176 = V_11 ;
return 0 ;
}
static int T_4 F_116 ( struct V_6 * * V_195 ,
struct V_6 * * V_196 )
{
unsigned int V_197 ;
if ( ( V_198 + V_199 ) <= V_200 ) {
* V_195 = & V_201 [ V_198 ++ ] ;
* V_196 = & V_201 [ V_198 ++ ] ;
return 0 ;
}
V_197 = sizeof( struct V_6 ) * V_199 ;
* V_196 = NULL ;
* V_195 = F_117 ( V_197 ) ;
memset ( * V_195 , 0 , V_197 ) ;
* V_196 = ( void * ) ( * V_195 ) + sizeof( struct V_6 ) ;
V_202 ++ ;
F_17 ( L_46 ,
V_202 * V_199 ) ;
return 0 ;
}
static int T_4 F_118 ( struct V_1 * V_5 )
{
struct V_6 * V_195 , * V_196 ;
F_17 ( L_47 , V_5 -> V_203 -> V_14 ,
V_5 -> V_204 -> V_14 ) ;
F_116 ( & V_195 , & V_196 ) ;
V_195 -> V_8 = V_5 ;
F_114 ( & V_195 -> V_7 ) ;
F_119 ( & V_195 -> V_7 , & V_5 -> V_203 -> V_193 ) ;
V_5 -> V_203 -> V_205 ++ ;
V_196 -> V_8 = V_5 ;
F_114 ( & V_196 -> V_7 ) ;
F_119 ( & V_196 -> V_7 , & V_5 -> V_204 -> V_90 ) ;
V_5 -> V_204 -> V_91 ++ ;
return 0 ;
}
static int T_4 F_120 ( struct V_1 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_203 || ! V_5 -> V_204 || ! V_5 -> V_124 )
return - V_15 ;
if ( V_5 -> V_20 & V_206 )
return - V_191 ;
F_17 ( L_48 ,
V_5 -> V_203 -> V_14 , V_5 -> V_204 -> V_14 ) ;
if ( V_5 -> V_203 -> V_49 != V_142 )
F_112 ( V_5 -> V_203 ) ;
if ( V_5 -> V_204 -> V_49 != V_142 )
F_112 ( V_5 -> V_204 ) ;
F_118 ( V_5 ) ;
V_5 -> V_20 |= V_206 ;
return 0 ;
}
static int T_4 F_121 ( struct V_1 * * V_207 )
{
unsigned int V_4 = 0 ;
unsigned int V_197 ;
if ( V_201 ) {
F_4 ( 1 , L_49 ) ;
return - V_191 ;
}
if ( V_200 == 0 )
while ( V_207 [ V_4 ++ ] )
V_200 += V_199 ;
V_197 = sizeof( struct V_6 ) * V_200 ;
F_17 ( L_50 ,
V_101 , V_197 , V_200 ) ;
V_201 = F_117 ( V_197 ) ;
memset ( V_201 , 0 , V_197 ) ;
return 0 ;
}
static int F_122 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
if ( ! F_59 ( V_11 ) )
return 0 ;
return F_123 ( V_11 -> V_98 . V_208 . V_209 ,
V_11 -> V_98 . V_208 . V_210 ,
V_11 -> V_98 . V_208 . V_211 ) ;
}
static int F_124 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
if ( ! F_59 ( V_11 ) )
return 0 ;
return F_125 ( V_11 -> V_98 . V_208 . V_209 ,
V_11 -> V_98 . V_208 . V_210 ,
V_11 -> V_98 . V_208 . V_211 ) ;
}
static int F_126 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_107 || ! V_11 -> V_82 )
return 0 ;
if ( ! F_59 ( V_11 ) )
return 0 ;
return F_127 ( V_11 -> V_82 -> V_102 ,
V_11 -> V_82 -> V_103 ,
V_11 -> V_82 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_128 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_82 )
return - V_15 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
if ( ! F_59 ( V_11 ) )
return 0 ;
return F_129 ( V_11 -> V_82 -> V_103 ,
V_11 -> V_82 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_130 ( struct V_10 * V_11 ,
struct V_145 * V_146 )
{
return F_131 ( V_11 -> V_98 . V_208 . V_209 ,
V_146 -> V_150 ) ;
}
static int F_132 ( struct V_10 * V_11 ,
struct V_145 * V_146 )
{
return F_133 ( V_11 -> V_98 . V_208 . V_209 ,
V_146 -> V_150 ,
V_146 -> V_151 ) ;
}
static int F_134 ( struct V_10 * V_11 ,
struct V_145 * V_146 )
{
return F_135 ( V_11 -> V_98 . V_208 . V_209 ,
V_146 -> V_151 ) ;
}
static int F_136 ( struct V_10 * V_11 ,
struct V_145 * V_146 )
{
if ( ! V_11 -> V_82 )
return - V_15 ;
return F_137 ( V_146 -> V_150 ,
V_11 -> V_82 -> V_168 . V_169 -> V_102 ,
V_11 -> V_82 -> V_168 . V_169 -> V_170 ,
V_11 -> V_98 . V_99 . V_212 ) ;
}
static int F_138 ( struct V_10 * V_11 ,
struct V_145 * V_146 )
{
if ( ! V_11 -> V_82 )
return - V_15 ;
if ( V_146 -> V_151 )
F_106 ( L_51 ,
V_11 -> V_14 , V_146 -> V_14 ) ;
return F_139 ( V_146 -> V_150 ,
V_11 -> V_82 -> V_168 . V_169 -> V_102 ,
V_11 -> V_82 -> V_168 . V_169 -> V_170 ,
V_11 -> V_98 . V_99 . V_212 ) ;
}
static int F_140 ( struct V_10 * V_11 ,
struct V_145 * V_146 )
{
if ( ! V_11 -> V_82 )
return - V_15 ;
return F_141 ( V_146 -> V_150 ,
V_11 -> V_82 -> V_168 . V_169 -> V_102 ,
V_11 -> V_82 -> V_168 . V_169 -> V_170 ,
V_11 -> V_98 . V_99 . V_212 ) ;
}
static int F_142 ( struct V_10 * V_11 ,
struct V_145 * V_146 )
{
return F_143 ( V_146 -> V_150 ,
V_11 -> V_82 -> V_168 . V_169 -> V_170 ,
V_11 -> V_98 . V_99 . V_212 ) ;
}
static int F_144 ( struct V_10 * V_11 ,
struct V_145 * V_146 )
{
if ( V_146 -> V_151 )
F_106 ( L_51 ,
V_11 -> V_14 , V_146 -> V_14 ) ;
return F_145 ( V_146 -> V_150 ,
V_11 -> V_82 -> V_168 . V_169 -> V_170 ,
V_11 -> V_98 . V_99 . V_212 ,
V_11 -> V_98 . V_99 . V_213 ) ;
}
static int F_146 ( struct V_10 * V_11 ,
struct V_145 * V_146 )
{
return F_147 ( V_146 -> V_150 ,
V_11 -> V_82 -> V_168 . V_169 -> V_170 ,
V_11 -> V_98 . V_99 . V_212 ) ;
}
T_1 F_5 ( struct V_10 * V_11 , T_3 V_214 )
{
if ( V_11 -> V_66 & V_215 )
return F_148 ( V_11 -> V_183 + V_214 ) ;
else
return F_149 ( V_11 -> V_183 + V_214 ) ;
}
void F_7 ( T_1 V_22 , struct V_10 * V_11 , T_3 V_214 )
{
if ( V_11 -> V_66 & V_215 )
F_150 ( V_22 , V_11 -> V_183 + V_214 ) ;
else
F_151 ( V_22 , V_11 -> V_183 + V_214 ) ;
}
int F_152 ( struct V_10 * V_11 )
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
error:
return V_87 ;
}
int F_153 ( struct V_10 * V_11 , T_2 V_29 )
{
T_1 V_22 ;
int V_179 = 0 ;
if ( ! V_11 )
return - V_15 ;
V_22 = V_11 -> V_16 ;
V_179 = F_10 ( V_11 , V_29 , & V_22 ) ;
if ( ! V_179 )
F_6 ( V_22 , V_11 ) ;
return V_179 ;
}
struct V_10 * F_154 ( const char * V_14 )
{
struct V_10 * V_11 ;
if ( ! V_14 )
return NULL ;
V_11 = F_64 ( V_14 ) ;
return V_11 ;
}
int F_155 ( int (* F_156)( struct V_10 * V_11 , void * V_141 ) ,
void * V_141 )
{
struct V_10 * V_139 ;
int V_87 = 0 ;
if ( ! F_156 )
return - V_15 ;
F_65 (temp_oh, &omap_hwmod_list, node) {
V_87 = (* F_156)( V_139 , V_141 ) ;
if ( V_87 )
break;
}
return V_87 ;
}
int T_4 F_157 ( struct V_1 * * V_207 )
{
int V_164 , V_4 ;
if ( ! V_216 )
return - V_15 ;
if ( ! V_207 )
return 0 ;
if ( ! V_201 ) {
if ( F_121 ( V_207 ) ) {
F_106 ( L_52 ) ;
return - V_217 ;
}
}
V_4 = 0 ;
do {
V_164 = F_120 ( V_207 [ V_4 ] ) ;
F_4 ( V_164 && V_164 != - V_191 ,
L_53 ,
V_207 [ V_4 ] -> V_203 -> V_14 , V_207 [ V_4 ] -> V_204 -> V_14 , V_164 ) ;
} while ( V_207 [ ++ V_4 ] );
return 0 ;
}
static void T_4 F_158 ( struct V_10 * V_11 )
{
if ( ! V_176 || V_176 -> V_49 == V_189 )
F_106 ( L_54 ,
V_101 , V_194 ) ;
else if ( V_176 -> V_49 == V_142 && V_11 != V_176 )
F_159 ( V_194 ) ;
}
int T_4 F_159 ( const char * V_218 )
{
struct V_10 * V_11 ;
F_17 ( L_25 , V_218 , V_101 ) ;
V_11 = F_64 ( V_218 ) ;
if ( ! V_11 ) {
F_4 ( 1 , L_55 , V_218 ) ;
return - V_15 ;
}
F_158 ( V_11 ) ;
F_107 ( V_11 , NULL ) ;
F_111 ( V_11 , NULL ) ;
return 0 ;
}
static int T_4 F_160 ( void )
{
F_158 ( NULL ) ;
F_155 ( F_107 , NULL ) ;
F_155 ( F_111 , NULL ) ;
return 0 ;
}
int F_161 ( struct V_10 * V_11 )
{
int V_164 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_180 , V_66 ) ;
V_164 = F_99 ( V_11 ) ;
F_94 ( & V_11 -> V_180 , V_66 ) ;
return V_164 ;
}
int F_162 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_180 , V_66 ) ;
F_101 ( V_11 ) ;
F_94 ( & V_11 -> V_180 , V_66 ) ;
return 0 ;
}
int F_163 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_180 , V_66 ) ;
F_103 ( V_11 ) ;
F_94 ( & V_11 -> V_180 , V_66 ) ;
return 0 ;
}
int F_164 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
F_88 ( & V_11 -> V_180 , V_66 ) ;
F_37 ( V_11 ) ;
F_94 ( & V_11 -> V_180 , V_66 ) ;
return 0 ;
}
int F_165 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
F_88 ( & V_11 -> V_180 , V_66 ) ;
F_39 ( V_11 ) ;
F_94 ( & V_11 -> V_180 , V_66 ) ;
return 0 ;
}
void F_166 ( struct V_10 * V_11 )
{
F_167 ( ! V_11 ) ;
if ( ! V_11 -> V_12 -> V_13 || ! V_11 -> V_12 -> V_13 -> V_18 ) {
F_4 ( 1 , L_56 ,
V_11 -> V_14 ) ;
return;
}
F_5 ( V_11 , V_11 -> V_12 -> V_13 -> V_17 ) ;
}
int F_168 ( struct V_10 * V_11 )
{
int V_164 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_180 , V_66 ) ;
V_164 = F_86 ( V_11 ) ;
F_94 ( & V_11 -> V_180 , V_66 ) ;
return V_164 ;
}
int F_169 ( struct V_10 * V_11 , unsigned long V_66 )
{
int V_87 = 0 ;
if ( V_66 & V_219 )
V_87 += F_52 ( V_11 ) ;
if ( V_66 & V_220 )
V_87 += F_53 ( V_11 ) ;
if ( V_66 & V_221 ) {
int V_4 = 0 ;
struct V_1 * V_89 ;
struct V_2 * V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
V_87 += F_54 ( V_89 ) ;
}
}
return V_87 ;
}
int F_170 ( struct V_10 * V_11 , struct V_222 * V_223 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
int V_4 , V_61 , V_224 , V_225 , V_226 ;
int V_164 = 0 ;
V_224 = F_52 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_224 ; V_4 ++ ) {
( V_223 + V_164 ) -> V_14 = ( V_11 -> V_110 + V_4 ) -> V_14 ;
( V_223 + V_164 ) -> V_227 = ( V_11 -> V_110 + V_4 ) -> V_111 ;
( V_223 + V_164 ) -> V_228 = ( V_11 -> V_110 + V_4 ) -> V_111 ;
( V_223 + V_164 ) -> V_66 = V_219 ;
V_164 ++ ;
}
V_225 = F_53 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_225 ; V_4 ++ ) {
( V_223 + V_164 ) -> V_14 = ( V_11 -> V_114 + V_4 ) -> V_14 ;
( V_223 + V_164 ) -> V_227 = ( V_11 -> V_114 + V_4 ) -> V_115 ;
( V_223 + V_164 ) -> V_228 = ( V_11 -> V_114 + V_4 ) -> V_115 ;
( V_223 + V_164 ) -> V_66 = V_220 ;
V_164 ++ ;
}
V_3 = V_11 -> V_90 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
V_226 = F_54 ( V_89 ) ;
for ( V_61 = 0 ; V_61 < V_226 ; V_61 ++ ) {
( V_223 + V_164 ) -> V_14 = ( V_89 -> V_118 + V_61 ) -> V_14 ;
( V_223 + V_164 ) -> V_227 = ( V_89 -> V_118 + V_61 ) -> V_119 ;
( V_223 + V_164 ) -> V_228 = ( V_89 -> V_118 + V_61 ) -> V_120 ;
( V_223 + V_164 ) -> V_66 = V_221 ;
V_164 ++ ;
}
}
return V_164 ;
}
int F_171 ( struct V_10 * V_11 , struct V_222 * V_223 )
{
int V_4 , V_225 ;
int V_164 = 0 ;
V_225 = F_53 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_225 ; V_4 ++ ) {
( V_223 + V_164 ) -> V_14 = ( V_11 -> V_114 + V_4 ) -> V_14 ;
( V_223 + V_164 ) -> V_227 = ( V_11 -> V_114 + V_4 ) -> V_115 ;
( V_223 + V_164 ) -> V_228 = ( V_11 -> V_114 + V_4 ) -> V_115 ;
( V_223 + V_164 ) -> V_66 = V_220 ;
V_164 ++ ;
}
return V_164 ;
}
int F_172 ( struct V_10 * V_11 , unsigned int type ,
const char * V_14 , struct V_222 * V_229 )
{
int V_164 ;
unsigned int V_111 , V_123 ;
T_1 V_119 , V_120 ;
if ( ! V_11 || ! V_229 )
return - V_15 ;
if ( type == V_219 ) {
V_164 = F_55 ( V_11 , V_14 , & V_111 ) ;
if ( V_164 )
return V_164 ;
V_229 -> V_227 = V_111 ;
V_229 -> V_228 = V_111 ;
} else if ( type == V_220 ) {
V_164 = F_56 ( V_11 , V_14 , & V_123 ) ;
if ( V_164 )
return V_164 ;
V_229 -> V_227 = V_123 ;
V_229 -> V_228 = V_123 ;
} else if ( type == V_221 ) {
V_164 = F_57 ( V_11 , V_14 , & V_119 , & V_120 ) ;
if ( V_164 )
return V_164 ;
V_229 -> V_227 = V_119 ;
V_229 -> V_228 = V_120 ;
} else {
return - V_15 ;
}
V_229 -> V_66 = type ;
V_229 -> V_14 = V_14 ;
return 0 ;
}
struct V_230 * F_173 ( struct V_10 * V_11 )
{
struct V_81 * V_41 ;
struct V_1 * V_5 ;
struct V_79 * V_82 ;
struct V_80 * V_81 ;
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_82 )
return V_11 -> V_82 -> V_168 . V_169 ;
if ( V_11 -> V_83 ) {
V_41 = V_11 -> V_83 ;
} else {
V_5 = F_59 ( V_11 ) ;
if ( ! V_5 )
return NULL ;
V_41 = V_5 -> V_83 ;
}
V_81 = F_24 ( F_25 ( V_41 ) ) ;
V_82 = V_81 -> V_82 ;
if ( ! V_82 )
return NULL ;
return V_82 -> V_168 . V_169 ;
}
void T_5 * F_174 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_20 & V_106 )
return NULL ;
if ( V_11 -> V_49 == V_189 )
return NULL ;
return V_11 -> V_183 ;
}
int F_175 ( struct V_10 * V_11 ,
struct V_10 * V_84 )
{
return F_26 ( V_11 , V_84 ) ;
}
int F_176 ( struct V_10 * V_11 ,
struct V_10 * V_84 )
{
return F_28 ( V_11 , V_84 ) ;
}
int F_177 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
T_1 V_22 ;
F_88 ( & V_11 -> V_180 , V_66 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ) {
V_22 = V_11 -> V_16 ;
F_21 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_19 ( V_11 , true ) ;
F_94 ( & V_11 -> V_180 , V_66 ) ;
return 0 ;
}
int F_178 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
T_1 V_22 ;
F_88 ( & V_11 -> V_180 , V_66 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ) {
V_22 = V_11 -> V_16 ;
F_22 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_19 ( V_11 , false ) ;
F_94 ( & V_11 -> V_180 , V_66 ) ;
return 0 ;
}
int F_179 ( struct V_10 * V_11 , const char * V_14 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_180 , V_66 ) ;
V_87 = F_70 ( V_11 , V_14 ) ;
F_94 ( & V_11 -> V_180 , V_66 ) ;
return V_87 ;
}
int F_180 ( struct V_10 * V_11 , const char * V_14 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_180 , V_66 ) ;
V_87 = F_71 ( V_11 , V_14 ) ;
F_94 ( & V_11 -> V_180 , V_66 ) ;
return V_87 ;
}
int F_181 ( struct V_10 * V_11 , const char * V_14 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_180 , V_66 ) ;
V_87 = F_77 ( V_11 , V_14 ) ;
F_94 ( & V_11 -> V_180 , V_66 ) ;
return V_87 ;
}
int F_182 ( const char * V_231 ,
int (* F_156)( struct V_10 * V_11 ,
void * V_124 ) ,
void * V_124 )
{
struct V_10 * V_139 ;
int V_87 = 0 ;
if ( ! V_231 || ! F_156 )
return - V_15 ;
F_17 ( L_57 ,
V_101 , V_231 ) ;
F_65 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_139 -> V_12 -> V_14 , V_231 ) ) {
F_17 ( L_58 ,
V_101 , V_139 -> V_14 ) ;
V_87 = (* F_156)( V_139 , V_124 ) ;
if ( V_87 )
break;
}
}
if ( V_87 )
F_17 ( L_59 ,
V_101 , V_87 ) ;
return V_87 ;
}
int F_183 ( struct V_10 * V_11 , T_2 V_232 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
if ( V_232 != V_175 &&
V_232 != V_50 &&
V_232 != V_70 )
return - V_15 ;
F_88 ( & V_11 -> V_180 , V_66 ) ;
if ( V_11 -> V_49 != V_142 ) {
V_87 = - V_15 ;
goto V_233;
}
V_11 -> V_188 = V_232 ;
V_87 = 0 ;
V_233:
F_94 ( & V_11 -> V_180 , V_66 ) ;
return V_87 ;
}
int F_184 ( struct V_10 * V_11 )
{
struct V_230 * V_168 ;
int V_87 = 0 ;
if ( V_143 . V_234 )
return V_143 . V_234 ( V_11 ) ;
V_168 = F_173 ( V_11 ) ;
if ( V_168 )
V_87 = F_185 ( V_168 ) ;
return V_87 ;
}
int F_186 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_49 != V_142 ) {
F_106 ( L_60 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_66 |= V_186 ;
return 0 ;
}
int F_187 ( struct V_10 * V_11 , int V_235 , int V_236 )
{
int V_237 ;
F_188 () ;
if ( ! V_11 || ! V_11 -> V_62 || ! V_11 -> V_110 || V_235 < 0 ||
V_235 >= V_11 -> V_62 -> V_64 )
return - V_15 ;
for ( V_237 = 0 ; V_11 -> V_110 [ V_237 ] . V_111 >= 0 ; V_237 ++ )
;
if ( V_236 >= V_237 )
return - V_15 ;
if ( ! V_11 -> V_62 -> V_238 ) {
V_11 -> V_62 -> V_238 = F_189 ( sizeof( int ) * V_11 -> V_62 -> V_64 ,
V_239 ) ;
if ( ! V_11 -> V_62 -> V_238 )
return - V_217 ;
}
V_11 -> V_62 -> V_238 [ V_235 ] = V_236 ;
return 0 ;
}
void T_4 F_190 ( void )
{
if ( F_191 () ) {
V_143 . V_178 = F_122 ;
V_143 . V_152 = F_130 ;
V_143 . V_155 = F_132 ;
V_143 . V_159 = F_134 ;
} else if ( F_89 () ) {
V_143 . V_178 = F_124 ;
V_143 . V_152 = F_130 ;
V_143 . V_155 = F_132 ;
V_143 . V_159 = F_134 ;
} else if ( F_92 () || F_192 () ) {
V_143 . V_156 = F_44 ;
V_143 . V_157 = F_80 ;
V_143 . V_178 = F_126 ;
V_143 . V_152 = F_136 ;
V_143 . V_155 = F_138 ;
V_143 . V_159 = F_140 ;
V_143 . V_85 = F_66 ;
V_143 . V_177 = F_95 ;
V_143 . V_234 = F_98 ;
} else if ( F_193 () ) {
V_143 . V_156 = F_46 ;
V_143 . V_157 = F_82 ;
V_143 . V_178 = F_128 ;
V_143 . V_152 = F_142 ;
V_143 . V_155 = F_144 ;
V_143 . V_159 = F_146 ;
V_143 . V_85 = F_66 ;
} else {
F_4 ( 1 , L_61 ) ;
}
V_216 = true ;
}
const char * F_194 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
return V_11 -> V_88 ;
}
