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
V_29 = V_133 ;
} else if ( V_11 -> V_66 & V_137 ) {
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
if ( ( V_11 -> V_66 & V_138 ) &&
( V_128 & V_36 ) )
F_11 ( V_11 , V_11 -> V_12 -> V_13 -> V_33 , & V_22 ) ;
if ( ( V_128 & V_32 ) && ! ( V_11 -> V_66 & V_134 ) )
F_21 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
if ( V_128 & V_55 ) {
V_29 = ( V_11 -> V_66 & V_139 ) ?
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
if ( ( V_11 -> V_66 & V_137 ) ||
( V_11 -> V_66 & V_136 ) ) {
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
struct V_10 * V_11 , * V_140 ;
V_11 = NULL ;
F_65 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_14 , V_140 -> V_14 ) ) {
V_11 = V_140 ;
break;
}
}
return V_11 ;
}
static int F_66 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_141 ) {
F_17 ( L_17 , V_11 -> V_14 ) ;
return 0 ;
}
V_11 -> V_82 = F_67 ( V_11 -> V_141 ) ;
if ( ! V_11 -> V_82 ) {
F_33 ( L_18 ,
V_11 -> V_14 , V_11 -> V_141 ) ;
return - V_15 ;
}
F_17 ( L_19 ,
V_11 -> V_14 , V_11 -> V_141 ) ;
return 0 ;
}
static int F_68 ( struct V_10 * V_11 , void * V_142 )
{
int V_87 = 0 ;
if ( V_11 -> V_49 != V_143 )
return 0 ;
F_17 ( L_20 , V_11 -> V_14 ) ;
if ( V_144 . V_85 )
V_87 |= V_144 . V_85 ( V_11 ) ;
V_87 |= F_30 ( V_11 ) ;
V_87 |= F_35 ( V_11 ) ;
V_87 |= F_36 ( V_11 ) ;
if ( ! V_87 )
V_11 -> V_49 = V_145 ;
else
F_33 ( L_21 , V_11 -> V_14 ) ;
return V_87 ;
}
static int F_69 ( struct V_10 * V_11 , const char * V_14 ,
struct V_146 * V_147 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_148 ; V_4 ++ ) {
const char * V_149 = V_11 -> V_150 [ V_4 ] . V_14 ;
if ( ! strcmp ( V_149 , V_14 ) ) {
V_147 -> V_151 = V_11 -> V_150 [ V_4 ] . V_151 ;
V_147 -> V_152 = V_11 -> V_150 [ V_4 ] . V_152 ;
F_17 ( L_22 ,
V_11 -> V_14 , V_101 , V_149 , V_147 -> V_151 ,
V_147 -> V_152 ) ;
return 0 ;
}
}
return - V_122 ;
}
static int F_70 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_146 V_147 ;
int V_87 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_144 . V_153 )
return - V_154 ;
V_87 = F_69 ( V_11 , V_14 , & V_147 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = V_144 . V_153 ( V_11 , & V_147 ) ;
return V_87 ;
}
static int F_71 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_146 V_147 ;
int V_87 = - V_15 ;
int V_155 = 0 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_144 . V_156 )
return - V_154 ;
V_87 = F_69 ( V_11 , V_14 , & V_147 ) ;
if ( F_72 ( V_87 ) )
return V_87 ;
if ( V_11 -> V_82 ) {
V_155 = F_73 ( V_11 -> V_82 ) ;
V_87 = F_74 ( V_11 -> V_82 , V_11 ) ;
if ( V_87 ) {
F_4 ( 1 , L_23 ,
V_11 -> V_14 , V_11 -> V_82 -> V_14 , V_87 ) ;
return V_87 ;
}
}
F_37 ( V_11 ) ;
if ( V_144 . V_157 )
V_144 . V_157 ( V_11 ) ;
V_87 = V_144 . V_156 ( V_11 , & V_147 ) ;
if ( V_144 . V_158 )
V_144 . V_158 ( V_11 ) ;
F_39 ( V_11 ) ;
if ( V_87 == - V_159 )
F_33 ( L_24 , V_11 -> V_14 ) ;
if ( ! V_87 ) {
if ( V_11 -> V_82 && V_155 )
F_75 ( V_11 -> V_82 ) ;
} else {
if ( V_11 -> V_82 )
F_76 ( V_11 -> V_82 , V_11 ) ;
}
return V_87 ;
}
static int F_77 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_146 V_147 ;
int V_87 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_144 . V_160 )
return - V_154 ;
V_87 = F_69 ( V_11 , V_14 , & V_147 ) ;
if ( V_87 < 0 )
return V_87 ;
return V_144 . V_160 ( V_11 , & V_147 ) ;
}
static bool F_78 ( struct V_10 * V_11 )
{
int V_4 , V_161 = 0 ;
if ( V_11 -> V_148 == 0 )
return false ;
for ( V_4 = 0 ; V_4 < V_11 -> V_148 ; V_4 ++ )
if ( F_77 ( V_11 , V_11 -> V_150 [ V_4 ] . V_14 ) > 0 )
V_161 ++ ;
if ( V_11 -> V_148 == V_161 )
return true ;
return false ;
}
static bool F_79 ( struct V_10 * V_11 )
{
int V_161 = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_148 && V_161 == 0 ; V_4 ++ )
if ( F_77 ( V_11 , V_11 -> V_150 [ V_4 ] . V_14 ) > 0 )
V_161 ++ ;
return ( V_161 ) ? true : false ;
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
goto V_162;
F_6 ( V_22 , V_11 ) ;
if ( V_11 -> V_12 -> V_13 -> V_163 )
F_85 ( V_11 -> V_12 -> V_13 -> V_163 ) ;
V_41 = F_13 ( V_11 ) ;
if ( V_41 == V_45 )
F_33 ( L_29 ,
V_11 -> V_14 , V_45 ) ;
else
F_17 ( L_30 , V_11 -> V_14 , V_41 ) ;
V_87 = ( V_41 == V_45 ) ? - V_164 : 0 ;
V_162:
if ( V_11 -> V_66 & V_130 )
F_43 ( V_11 ) ;
return V_87 ;
}
static int F_86 ( struct V_10 * V_11 )
{
int V_4 , V_165 ;
F_17 ( L_31 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_166 ) {
V_165 = V_11 -> V_12 -> V_166 ( V_11 ) ;
} else {
if ( V_11 -> V_148 > 0 ) {
for ( V_4 = 0 ; V_4 < V_11 -> V_148 ; V_4 ++ )
F_70 ( V_11 , V_11 -> V_150 [ V_4 ] . V_14 ) ;
return 0 ;
} else {
V_165 = F_84 ( V_11 ) ;
if ( V_165 == - V_122 )
V_165 = 0 ;
}
}
F_15 ( V_11 ) ;
if ( V_11 -> V_12 -> V_13 ) {
F_3 ( V_11 ) ;
F_61 ( V_11 ) ;
}
return V_165 ;
}
static void F_87 ( void )
{
unsigned long V_66 ;
F_88 ( & V_167 , V_66 ) ;
if ( F_89 () && F_90 () )
F_91 () ;
else if ( F_92 () )
F_93 () ;
F_94 ( & V_167 , V_66 ) ;
}
static void F_95 ( struct V_10 * V_11 )
{
if ( V_11 -> V_98 . V_99 . V_66 & V_168 )
return;
if ( ! F_96 ( V_11 -> V_82 -> V_169 . V_170 -> V_102 ,
V_11 -> V_82 -> V_169 . V_170 -> V_171 ,
V_11 -> V_98 . V_99 . V_172 ) )
return;
V_11 -> V_98 . V_99 . V_173 ++ ;
F_97 ( V_11 -> V_82 -> V_169 . V_170 -> V_102 ,
V_11 -> V_82 -> V_169 . V_170 -> V_171 ,
V_11 -> V_98 . V_99 . V_172 ) ;
}
static int F_98 ( struct V_10 * V_11 )
{
return V_11 -> V_98 . V_99 . V_173 ;
}
static int T_4 F_99 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_12 -> V_174 )
return 0 ;
return V_11 -> V_12 -> V_174 ( V_11 ) ;
}
static int F_100 ( struct V_10 * V_11 )
{
int V_165 ;
int V_155 = 0 ;
F_17 ( L_32 , V_11 -> V_14 ) ;
if ( V_11 -> V_20 & V_175 ) {
if ( V_11 -> V_62 )
F_20 ( V_11 -> V_62 , V_50 ) ;
V_11 -> V_20 &= ~ V_175 ;
return 0 ;
}
if ( V_11 -> V_49 != V_176 &&
V_11 -> V_49 != V_70 &&
V_11 -> V_49 != V_177 ) {
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
F_26 ( V_11 , V_178 ) ;
if ( V_11 -> V_82 ) {
V_155 = F_73 ( V_11 -> V_82 ) &&
! F_101 ( V_11 -> V_82 ) ;
V_165 = F_74 ( V_11 -> V_82 , V_11 ) ;
if ( V_165 ) {
F_4 ( 1 , L_23 ,
V_11 -> V_14 , V_11 -> V_82 -> V_14 , V_165 ) ;
return V_165 ;
}
}
F_37 ( V_11 ) ;
if ( V_144 . V_157 )
V_144 . V_157 ( V_11 ) ;
if ( V_11 -> V_66 & V_179 )
F_102 () ;
if ( V_144 . V_180 )
V_144 . V_180 ( V_11 ) ;
V_165 = ( V_144 . V_181 ) ? V_144 . V_181 ( V_11 ) :
- V_15 ;
if ( ! V_165 ) {
if ( V_11 -> V_82 && V_155 )
F_75 ( V_11 -> V_82 ) ;
V_11 -> V_49 = V_50 ;
if ( V_11 -> V_12 -> V_13 ) {
if ( ! ( V_11 -> V_20 & V_21 ) )
F_3 ( V_11 ) ;
F_61 ( V_11 ) ;
}
V_165 = F_99 ( V_11 ) ;
} else {
if ( V_144 . V_158 )
V_144 . V_158 ( V_11 ) ;
F_39 ( V_11 ) ;
F_17 ( L_34 ,
V_11 -> V_14 , V_165 ) ;
if ( V_11 -> V_82 )
F_76 ( V_11 -> V_82 , V_11 ) ;
}
return V_165 ;
}
static int F_103 ( struct V_10 * V_11 )
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
F_28 ( V_11 , V_178 ) ;
if ( V_11 -> V_66 & V_179 )
F_104 () ;
if ( V_144 . V_158 )
V_144 . V_158 ( V_11 ) ;
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
int F_105 ( struct V_10 * V_11 , T_2 V_52 )
{
T_1 V_22 ;
int V_182 = 0 ;
unsigned long V_66 ;
if ( ! V_11 || V_11 -> V_49 != V_50 )
return - V_15 ;
F_88 ( & V_11 -> V_183 , V_66 ) ;
V_22 = V_11 -> V_16 ;
V_182 = F_18 ( V_11 , V_52 , & V_22 ) ;
if ( ! V_182 )
F_6 ( V_22 , V_11 ) ;
F_94 ( & V_11 -> V_183 , V_66 ) ;
return V_182 ;
}
static int F_106 ( struct V_10 * V_11 )
{
int V_87 , V_4 ;
T_2 V_184 ;
if ( V_11 -> V_49 != V_70 &&
V_11 -> V_49 != V_50 ) {
F_4 ( 1 , L_37 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_78 ( V_11 ) )
return 0 ;
F_17 ( L_38 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_185 ) {
V_184 = V_11 -> V_49 ;
if ( V_11 -> V_49 == V_70 )
F_100 ( V_11 ) ;
V_87 = V_11 -> V_12 -> V_185 ( V_11 ) ;
if ( V_87 ) {
if ( V_184 == V_70 )
F_103 ( V_11 ) ;
return V_87 ;
}
}
if ( V_11 -> V_12 -> V_13 ) {
if ( V_11 -> V_49 == V_70 )
F_100 ( V_11 ) ;
F_63 ( V_11 ) ;
}
if ( V_11 -> V_49 == V_50 ) {
F_28 ( V_11 , V_178 ) ;
if ( V_11 -> V_66 & V_179 )
F_104 () ;
if ( V_144 . V_158 )
V_144 . V_158 ( V_11 ) ;
F_39 ( V_11 ) ;
if ( V_11 -> V_82 )
F_76 ( V_11 -> V_82 , V_11 ) ;
}
for ( V_4 = 0 ; V_4 < V_11 -> V_148 ; V_4 ++ )
F_70 ( V_11 , V_11 -> V_150 [ V_4 ] . V_14 ) ;
if ( V_11 -> V_62 )
F_20 ( V_11 -> V_62 , V_177 ) ;
V_11 -> V_49 = V_177 ;
return 0 ;
}
static void T_4 F_107 ( struct V_10 * V_11 , void * V_142 )
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
va_start = F_108 ( V_117 -> V_119 , V_117 -> V_120 - V_117 -> V_119 ) ;
if ( ! va_start ) {
F_109 ( L_40 , V_11 -> V_14 ) ;
return;
}
F_17 ( L_41 ,
V_11 -> V_14 , va_start ) ;
V_11 -> V_186 = va_start ;
}
static int T_4 F_110 ( struct V_10 * V_11 , void * V_142 )
{
int V_165 ;
if ( V_11 -> V_49 != V_143 )
return 0 ;
F_107 ( V_11 , NULL ) ;
V_165 = F_68 ( V_11 , NULL ) ;
if ( F_72 ( V_165 ) ) {
F_4 ( 1 , L_42 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_49 = V_176 ;
return 0 ;
}
static void T_4 F_111 ( struct V_10 * V_11 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( V_11 -> V_49 != V_176 )
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
static int T_4 F_112 ( struct V_10 * V_11 )
{
int V_165 ;
if ( V_11 -> V_49 != V_176 )
return - V_15 ;
if ( V_11 -> V_66 & V_187 )
return - V_188 ;
if ( V_11 -> V_148 == 0 ) {
V_165 = F_100 ( V_11 ) ;
if ( V_165 ) {
F_33 ( L_43 ,
V_11 -> V_14 , V_11 -> V_49 ) ;
return - V_15 ;
}
}
if ( ! ( V_11 -> V_66 & V_189 ) )
V_165 = F_86 ( V_11 ) ;
return V_165 ;
}
static void T_4 F_113 ( struct V_10 * V_11 )
{
T_2 V_190 ;
if ( V_11 -> V_148 > 0 )
return;
V_190 = V_11 -> V_191 ;
if ( V_190 == V_192 )
V_190 = V_50 ;
if ( ( V_11 -> V_66 & V_193 ) &&
( V_190 == V_70 ) ) {
V_11 -> V_20 |= V_175 ;
V_190 = V_50 ;
}
if ( V_190 == V_70 )
F_103 ( V_11 ) ;
else if ( V_190 == V_177 )
F_106 ( V_11 ) ;
else if ( V_190 != V_50 )
F_4 ( 1 , L_44 ,
V_11 -> V_14 , V_190 ) ;
return;
}
static int T_4 F_114 ( struct V_10 * V_11 , void * V_142 )
{
if ( V_11 -> V_49 != V_176 )
return 0 ;
F_111 ( V_11 ) ;
if ( ! F_112 ( V_11 ) )
F_113 ( V_11 ) ;
return 0 ;
}
static int T_4 F_115 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_14 || ! V_11 -> V_12 || ! V_11 -> V_12 -> V_14 ||
( V_11 -> V_49 != V_192 ) )
return - V_15 ;
F_17 ( L_45 , V_11 -> V_14 ) ;
if ( F_64 ( V_11 -> V_14 ) )
return - V_194 ;
F_116 ( & V_11 -> V_7 , & V_195 ) ;
F_117 ( & V_11 -> V_196 ) ;
F_117 ( & V_11 -> V_90 ) ;
F_118 ( & V_11 -> V_183 ) ;
V_11 -> V_49 = V_143 ;
if ( ! strcmp ( V_11 -> V_14 , V_197 ) )
V_178 = V_11 ;
return 0 ;
}
static int T_4 F_119 ( struct V_6 * * V_198 ,
struct V_6 * * V_199 )
{
unsigned int V_200 ;
if ( ( V_201 + V_202 ) <= V_203 ) {
* V_198 = & V_204 [ V_201 ++ ] ;
* V_199 = & V_204 [ V_201 ++ ] ;
return 0 ;
}
V_200 = sizeof( struct V_6 ) * V_202 ;
* V_199 = NULL ;
* V_198 = F_120 ( V_200 ) ;
memset ( * V_198 , 0 , V_200 ) ;
* V_199 = ( void * ) ( * V_198 ) + sizeof( struct V_6 ) ;
V_205 ++ ;
F_17 ( L_46 ,
V_205 * V_202 ) ;
return 0 ;
}
static int T_4 F_121 ( struct V_1 * V_5 )
{
struct V_6 * V_198 , * V_199 ;
F_17 ( L_47 , V_5 -> V_206 -> V_14 ,
V_5 -> V_207 -> V_14 ) ;
F_119 ( & V_198 , & V_199 ) ;
V_198 -> V_8 = V_5 ;
F_117 ( & V_198 -> V_7 ) ;
F_122 ( & V_198 -> V_7 , & V_5 -> V_206 -> V_196 ) ;
V_5 -> V_206 -> V_208 ++ ;
V_199 -> V_8 = V_5 ;
F_117 ( & V_199 -> V_7 ) ;
F_122 ( & V_199 -> V_7 , & V_5 -> V_207 -> V_90 ) ;
V_5 -> V_207 -> V_91 ++ ;
return 0 ;
}
static int T_4 F_123 ( struct V_1 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_206 || ! V_5 -> V_207 || ! V_5 -> V_124 )
return - V_15 ;
if ( V_5 -> V_20 & V_209 )
return - V_194 ;
F_17 ( L_48 ,
V_5 -> V_206 -> V_14 , V_5 -> V_207 -> V_14 ) ;
if ( V_5 -> V_206 -> V_49 != V_143 )
F_115 ( V_5 -> V_206 ) ;
if ( V_5 -> V_207 -> V_49 != V_143 )
F_115 ( V_5 -> V_207 ) ;
F_121 ( V_5 ) ;
V_5 -> V_20 |= V_209 ;
return 0 ;
}
static int T_4 F_124 ( struct V_1 * * V_210 )
{
unsigned int V_4 = 0 ;
unsigned int V_200 ;
if ( V_204 ) {
F_4 ( 1 , L_49 ) ;
return - V_194 ;
}
if ( V_203 == 0 )
while ( V_210 [ V_4 ++ ] )
V_203 += V_202 ;
V_200 = sizeof( struct V_6 ) * V_203 ;
F_17 ( L_50 ,
V_101 , V_200 , V_203 ) ;
V_204 = F_120 ( V_200 ) ;
memset ( V_204 , 0 , V_200 ) ;
return 0 ;
}
static int F_125 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
if ( ! F_59 ( V_11 ) )
return 0 ;
return F_126 ( V_11 -> V_98 . V_211 . V_212 ,
V_11 -> V_98 . V_211 . V_213 ,
V_11 -> V_98 . V_211 . V_214 ) ;
}
static int F_127 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
if ( ! F_59 ( V_11 ) )
return 0 ;
return F_128 ( V_11 -> V_98 . V_211 . V_212 ,
V_11 -> V_98 . V_211 . V_213 ,
V_11 -> V_98 . V_211 . V_214 ) ;
}
static int F_129 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_107 || ! V_11 -> V_82 )
return 0 ;
if ( ! F_59 ( V_11 ) )
return 0 ;
return F_130 ( V_11 -> V_82 -> V_102 ,
V_11 -> V_82 -> V_103 ,
V_11 -> V_82 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_131 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_82 )
return - V_15 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
if ( ! F_59 ( V_11 ) )
return 0 ;
return F_132 ( V_11 -> V_82 -> V_103 ,
V_11 -> V_82 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_133 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_134 ( V_11 -> V_98 . V_211 . V_212 ,
V_147 -> V_151 ) ;
}
static int F_135 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_136 ( V_11 -> V_98 . V_211 . V_212 ,
V_147 -> V_151 ,
V_147 -> V_152 ) ;
}
static int F_137 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_138 ( V_11 -> V_98 . V_211 . V_212 ,
V_147 -> V_152 ) ;
}
static int F_139 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
if ( ! V_11 -> V_82 )
return - V_15 ;
return F_140 ( V_147 -> V_151 ,
V_11 -> V_82 -> V_169 . V_170 -> V_102 ,
V_11 -> V_82 -> V_169 . V_170 -> V_171 ,
V_11 -> V_98 . V_99 . V_215 ) ;
}
static int F_141 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
if ( ! V_11 -> V_82 )
return - V_15 ;
if ( V_147 -> V_152 )
F_109 ( L_51 ,
V_11 -> V_14 , V_147 -> V_14 ) ;
return F_142 ( V_147 -> V_151 ,
V_11 -> V_82 -> V_169 . V_170 -> V_102 ,
V_11 -> V_82 -> V_169 . V_170 -> V_171 ,
V_11 -> V_98 . V_99 . V_215 ) ;
}
static int F_143 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
if ( ! V_11 -> V_82 )
return - V_15 ;
return F_144 ( V_147 -> V_151 ,
V_11 -> V_82 -> V_169 . V_170 -> V_102 ,
V_11 -> V_82 -> V_169 . V_170 -> V_171 ,
V_11 -> V_98 . V_99 . V_215 ) ;
}
static int F_145 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_146 ( V_147 -> V_151 ,
V_11 -> V_82 -> V_169 . V_170 -> V_171 ,
V_11 -> V_98 . V_99 . V_215 ) ;
}
static int F_147 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_148 ( V_147 -> V_151 ,
V_147 -> V_152 ,
V_11 -> V_82 -> V_169 . V_170 -> V_171 ,
V_11 -> V_98 . V_99 . V_215 ,
V_11 -> V_98 . V_99 . V_216 ) ;
}
static int F_149 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_150 ( V_147 -> V_151 ,
V_11 -> V_82 -> V_169 . V_170 -> V_171 ,
V_11 -> V_98 . V_99 . V_215 ) ;
}
T_1 F_5 ( struct V_10 * V_11 , T_3 V_217 )
{
if ( V_11 -> V_66 & V_218 )
return F_151 ( V_11 -> V_186 + V_217 ) ;
else
return F_152 ( V_11 -> V_186 + V_217 ) ;
}
void F_7 ( T_1 V_22 , struct V_10 * V_11 , T_3 V_217 )
{
if ( V_11 -> V_66 & V_218 )
F_153 ( V_22 , V_11 -> V_186 + V_217 ) ;
else
F_154 ( V_22 , V_11 -> V_186 + V_217 ) ;
}
int F_155 ( struct V_10 * V_11 )
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
int F_156 ( struct V_10 * V_11 , T_2 V_29 )
{
T_1 V_22 ;
int V_182 = 0 ;
if ( ! V_11 )
return - V_15 ;
V_22 = V_11 -> V_16 ;
V_182 = F_10 ( V_11 , V_29 , & V_22 ) ;
if ( ! V_182 )
F_6 ( V_22 , V_11 ) ;
return V_182 ;
}
struct V_10 * F_157 ( const char * V_14 )
{
struct V_10 * V_11 ;
if ( ! V_14 )
return NULL ;
V_11 = F_64 ( V_14 ) ;
return V_11 ;
}
int F_158 ( int (* F_159)( struct V_10 * V_11 , void * V_142 ) ,
void * V_142 )
{
struct V_10 * V_140 ;
int V_87 = 0 ;
if ( ! F_159 )
return - V_15 ;
F_65 (temp_oh, &omap_hwmod_list, node) {
V_87 = (* F_159)( V_140 , V_142 ) ;
if ( V_87 )
break;
}
return V_87 ;
}
int T_4 F_160 ( struct V_1 * * V_210 )
{
int V_165 , V_4 ;
if ( ! V_219 )
return - V_15 ;
if ( ! V_210 )
return 0 ;
if ( ! V_204 ) {
if ( F_124 ( V_210 ) ) {
F_109 ( L_52 ) ;
return - V_220 ;
}
}
V_4 = 0 ;
do {
V_165 = F_123 ( V_210 [ V_4 ] ) ;
F_4 ( V_165 && V_165 != - V_194 ,
L_53 ,
V_210 [ V_4 ] -> V_206 -> V_14 , V_210 [ V_4 ] -> V_207 -> V_14 , V_165 ) ;
} while ( V_210 [ ++ V_4 ] );
return 0 ;
}
static void T_4 F_161 ( struct V_10 * V_11 )
{
if ( ! V_178 || V_178 -> V_49 == V_192 )
F_109 ( L_54 ,
V_101 , V_197 ) ;
else if ( V_178 -> V_49 == V_143 && V_11 != V_178 )
F_162 ( V_197 ) ;
}
int T_4 F_162 ( const char * V_221 )
{
struct V_10 * V_11 ;
F_17 ( L_25 , V_221 , V_101 ) ;
V_11 = F_64 ( V_221 ) ;
if ( ! V_11 ) {
F_4 ( 1 , L_55 , V_221 ) ;
return - V_15 ;
}
F_161 ( V_11 ) ;
F_110 ( V_11 , NULL ) ;
F_114 ( V_11 , NULL ) ;
return 0 ;
}
static int T_4 F_163 ( void )
{
F_161 ( NULL ) ;
F_158 ( F_110 , NULL ) ;
F_158 ( F_114 , NULL ) ;
return 0 ;
}
int F_164 ( struct V_10 * V_11 )
{
int V_165 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_183 , V_66 ) ;
V_165 = F_100 ( V_11 ) ;
F_94 ( & V_11 -> V_183 , V_66 ) ;
return V_165 ;
}
int F_165 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_183 , V_66 ) ;
F_103 ( V_11 ) ;
F_94 ( & V_11 -> V_183 , V_66 ) ;
return 0 ;
}
int F_166 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_183 , V_66 ) ;
F_106 ( V_11 ) ;
F_94 ( & V_11 -> V_183 , V_66 ) ;
return 0 ;
}
int F_167 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
F_88 ( & V_11 -> V_183 , V_66 ) ;
F_37 ( V_11 ) ;
F_94 ( & V_11 -> V_183 , V_66 ) ;
return 0 ;
}
int F_168 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
F_88 ( & V_11 -> V_183 , V_66 ) ;
F_39 ( V_11 ) ;
F_94 ( & V_11 -> V_183 , V_66 ) ;
return 0 ;
}
void F_169 ( struct V_10 * V_11 )
{
F_170 ( ! V_11 ) ;
if ( ! V_11 -> V_12 -> V_13 || ! V_11 -> V_12 -> V_13 -> V_18 ) {
F_4 ( 1 , L_56 ,
V_11 -> V_14 ) ;
return;
}
F_5 ( V_11 , V_11 -> V_12 -> V_13 -> V_17 ) ;
}
int F_171 ( struct V_10 * V_11 )
{
int V_165 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_183 , V_66 ) ;
V_165 = F_86 ( V_11 ) ;
F_94 ( & V_11 -> V_183 , V_66 ) ;
return V_165 ;
}
int F_172 ( struct V_10 * V_11 , unsigned long V_66 )
{
int V_87 = 0 ;
if ( V_66 & V_222 )
V_87 += F_52 ( V_11 ) ;
if ( V_66 & V_223 )
V_87 += F_53 ( V_11 ) ;
if ( V_66 & V_224 ) {
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
int F_173 ( struct V_10 * V_11 , struct V_225 * V_226 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
int V_4 , V_61 , V_227 , V_228 , V_229 ;
int V_165 = 0 ;
V_227 = F_52 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_227 ; V_4 ++ ) {
( V_226 + V_165 ) -> V_14 = ( V_11 -> V_110 + V_4 ) -> V_14 ;
( V_226 + V_165 ) -> V_230 = ( V_11 -> V_110 + V_4 ) -> V_111 ;
( V_226 + V_165 ) -> V_231 = ( V_11 -> V_110 + V_4 ) -> V_111 ;
( V_226 + V_165 ) -> V_66 = V_222 ;
V_165 ++ ;
}
V_228 = F_53 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_228 ; V_4 ++ ) {
( V_226 + V_165 ) -> V_14 = ( V_11 -> V_114 + V_4 ) -> V_14 ;
( V_226 + V_165 ) -> V_230 = ( V_11 -> V_114 + V_4 ) -> V_115 ;
( V_226 + V_165 ) -> V_231 = ( V_11 -> V_114 + V_4 ) -> V_115 ;
( V_226 + V_165 ) -> V_66 = V_223 ;
V_165 ++ ;
}
V_3 = V_11 -> V_90 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
V_229 = F_54 ( V_89 ) ;
for ( V_61 = 0 ; V_61 < V_229 ; V_61 ++ ) {
( V_226 + V_165 ) -> V_14 = ( V_89 -> V_118 + V_61 ) -> V_14 ;
( V_226 + V_165 ) -> V_230 = ( V_89 -> V_118 + V_61 ) -> V_119 ;
( V_226 + V_165 ) -> V_231 = ( V_89 -> V_118 + V_61 ) -> V_120 ;
( V_226 + V_165 ) -> V_66 = V_224 ;
V_165 ++ ;
}
}
return V_165 ;
}
int F_174 ( struct V_10 * V_11 , struct V_225 * V_226 )
{
int V_4 , V_228 ;
int V_165 = 0 ;
V_228 = F_53 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_228 ; V_4 ++ ) {
( V_226 + V_165 ) -> V_14 = ( V_11 -> V_114 + V_4 ) -> V_14 ;
( V_226 + V_165 ) -> V_230 = ( V_11 -> V_114 + V_4 ) -> V_115 ;
( V_226 + V_165 ) -> V_231 = ( V_11 -> V_114 + V_4 ) -> V_115 ;
( V_226 + V_165 ) -> V_66 = V_223 ;
V_165 ++ ;
}
return V_165 ;
}
int F_175 ( struct V_10 * V_11 , unsigned int type ,
const char * V_14 , struct V_225 * V_232 )
{
int V_165 ;
unsigned int V_111 , V_123 ;
T_1 V_119 , V_120 ;
if ( ! V_11 || ! V_232 )
return - V_15 ;
if ( type == V_222 ) {
V_165 = F_55 ( V_11 , V_14 , & V_111 ) ;
if ( V_165 )
return V_165 ;
V_232 -> V_230 = V_111 ;
V_232 -> V_231 = V_111 ;
} else if ( type == V_223 ) {
V_165 = F_56 ( V_11 , V_14 , & V_123 ) ;
if ( V_165 )
return V_165 ;
V_232 -> V_230 = V_123 ;
V_232 -> V_231 = V_123 ;
} else if ( type == V_224 ) {
V_165 = F_57 ( V_11 , V_14 , & V_119 , & V_120 ) ;
if ( V_165 )
return V_165 ;
V_232 -> V_230 = V_119 ;
V_232 -> V_231 = V_120 ;
} else {
return - V_15 ;
}
V_232 -> V_66 = type ;
V_232 -> V_14 = V_14 ;
return 0 ;
}
struct V_233 * F_176 ( struct V_10 * V_11 )
{
struct V_81 * V_41 ;
struct V_1 * V_5 ;
struct V_79 * V_82 ;
struct V_80 * V_81 ;
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_82 )
return V_11 -> V_82 -> V_169 . V_170 ;
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
return V_82 -> V_169 . V_170 ;
}
void T_5 * F_177 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_20 & V_106 )
return NULL ;
if ( V_11 -> V_49 == V_192 )
return NULL ;
return V_11 -> V_186 ;
}
int F_178 ( struct V_10 * V_11 ,
struct V_10 * V_84 )
{
return F_26 ( V_11 , V_84 ) ;
}
int F_179 ( struct V_10 * V_11 ,
struct V_10 * V_84 )
{
return F_28 ( V_11 , V_84 ) ;
}
int F_180 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
T_1 V_22 ;
F_88 ( & V_11 -> V_183 , V_66 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ) {
V_22 = V_11 -> V_16 ;
F_21 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_19 ( V_11 , true ) ;
F_94 ( & V_11 -> V_183 , V_66 ) ;
return 0 ;
}
int F_181 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
T_1 V_22 ;
F_88 ( & V_11 -> V_183 , V_66 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ) {
V_22 = V_11 -> V_16 ;
F_22 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_19 ( V_11 , false ) ;
F_94 ( & V_11 -> V_183 , V_66 ) ;
return 0 ;
}
int F_182 ( struct V_10 * V_11 , const char * V_14 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_183 , V_66 ) ;
V_87 = F_70 ( V_11 , V_14 ) ;
F_94 ( & V_11 -> V_183 , V_66 ) ;
return V_87 ;
}
int F_183 ( struct V_10 * V_11 , const char * V_14 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_183 , V_66 ) ;
V_87 = F_71 ( V_11 , V_14 ) ;
F_94 ( & V_11 -> V_183 , V_66 ) ;
return V_87 ;
}
int F_184 ( struct V_10 * V_11 , const char * V_14 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_183 , V_66 ) ;
V_87 = F_77 ( V_11 , V_14 ) ;
F_94 ( & V_11 -> V_183 , V_66 ) ;
return V_87 ;
}
int F_185 ( const char * V_234 ,
int (* F_159)( struct V_10 * V_11 ,
void * V_124 ) ,
void * V_124 )
{
struct V_10 * V_140 ;
int V_87 = 0 ;
if ( ! V_234 || ! F_159 )
return - V_15 ;
F_17 ( L_57 ,
V_101 , V_234 ) ;
F_65 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_140 -> V_12 -> V_14 , V_234 ) ) {
F_17 ( L_58 ,
V_101 , V_140 -> V_14 ) ;
V_87 = (* F_159)( V_140 , V_124 ) ;
if ( V_87 )
break;
}
}
if ( V_87 )
F_17 ( L_59 ,
V_101 , V_87 ) ;
return V_87 ;
}
int F_186 ( struct V_10 * V_11 , T_2 V_235 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
if ( V_235 != V_177 &&
V_235 != V_50 &&
V_235 != V_70 )
return - V_15 ;
F_88 ( & V_11 -> V_183 , V_66 ) ;
if ( V_11 -> V_49 != V_143 ) {
V_87 = - V_15 ;
goto V_236;
}
V_11 -> V_191 = V_235 ;
V_87 = 0 ;
V_236:
F_94 ( & V_11 -> V_183 , V_66 ) ;
return V_87 ;
}
int F_187 ( struct V_10 * V_11 )
{
struct V_233 * V_169 ;
int V_87 = 0 ;
if ( V_144 . V_237 )
return V_144 . V_237 ( V_11 ) ;
V_169 = F_176 ( V_11 ) ;
if ( V_169 )
V_87 = F_188 ( V_169 ) ;
return V_87 ;
}
int F_189 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_49 != V_143 ) {
F_109 ( L_60 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_66 |= V_189 ;
return 0 ;
}
int F_190 ( struct V_10 * V_11 , int V_238 , int V_239 )
{
int V_240 ;
F_191 () ;
if ( ! V_11 || ! V_11 -> V_62 || ! V_11 -> V_110 || V_238 < 0 ||
V_238 >= V_11 -> V_62 -> V_64 )
return - V_15 ;
for ( V_240 = 0 ; V_11 -> V_110 [ V_240 ] . V_111 >= 0 ; V_240 ++ )
;
if ( V_239 >= V_240 )
return - V_15 ;
if ( ! V_11 -> V_62 -> V_241 ) {
V_11 -> V_62 -> V_241 = F_192 ( sizeof( int ) * V_11 -> V_62 -> V_64 ,
V_242 ) ;
if ( ! V_11 -> V_62 -> V_241 )
return - V_220 ;
}
V_11 -> V_62 -> V_241 [ V_238 ] = V_239 ;
return 0 ;
}
void T_4 F_193 ( void )
{
if ( F_194 () ) {
V_144 . V_181 = F_125 ;
V_144 . V_153 = F_133 ;
V_144 . V_156 = F_135 ;
V_144 . V_160 = F_137 ;
} else if ( F_89 () ) {
V_144 . V_181 = F_127 ;
V_144 . V_153 = F_133 ;
V_144 . V_156 = F_135 ;
V_144 . V_160 = F_137 ;
} else if ( F_92 () || F_195 () ) {
V_144 . V_157 = F_44 ;
V_144 . V_158 = F_80 ;
V_144 . V_181 = F_129 ;
V_144 . V_153 = F_139 ;
V_144 . V_156 = F_141 ;
V_144 . V_160 = F_143 ;
V_144 . V_85 = F_66 ;
V_144 . V_180 = F_95 ;
V_144 . V_237 = F_98 ;
} else if ( F_196 () ) {
V_144 . V_157 = F_46 ;
V_144 . V_158 = F_82 ;
V_144 . V_181 = F_131 ;
V_144 . V_153 = F_145 ;
V_144 . V_156 = F_147 ;
V_144 . V_160 = F_149 ;
V_144 . V_85 = F_66 ;
} else {
F_4 ( 1 , L_61 ) ;
}
V_219 = true ;
}
const char * F_197 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
return V_11 -> V_88 ;
}
