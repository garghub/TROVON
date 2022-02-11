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
F_10 ( V_11 , V_77 , V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_74 )
F_8 ( V_11 , V_77 , V_22 ) ;
return 0 ;
}
static struct V_78 * F_23 ( struct V_10 * V_11 )
{
struct V_79 * V_80 ;
if ( V_11 -> V_81 ) {
return V_11 -> V_81 ;
} else if ( V_11 -> V_82 ) {
V_80 = F_24 ( F_25 ( V_11 -> V_82 ) ) ;
return V_80 -> V_81 ;
}
return NULL ;
}
static int F_26 ( struct V_10 * V_11 , struct V_10 * V_83 )
{
struct V_78 * V_81 , * V_84 ;
V_81 = F_23 ( V_11 ) ;
V_84 = F_23 ( V_83 ) ;
if ( ! V_81 || ! V_84 )
return - V_15 ;
if ( V_81 && V_81 -> V_66 & V_85 )
return 0 ;
return F_27 ( V_81 , V_84 ) ;
}
static int F_28 ( struct V_10 * V_11 , struct V_10 * V_83 )
{
struct V_78 * V_81 , * V_84 ;
V_81 = F_23 ( V_11 ) ;
V_84 = F_23 ( V_83 ) ;
if ( ! V_81 || ! V_84 )
return - V_15 ;
if ( V_81 && V_81 -> V_66 & V_85 )
return 0 ;
return F_29 ( V_81 , V_84 ) ;
}
static int F_30 ( struct V_10 * V_11 )
{
int V_86 = 0 ;
if ( ! V_11 -> V_87 )
return 0 ;
V_11 -> V_82 = F_31 ( NULL , V_11 -> V_87 ) ;
if ( F_32 ( V_11 -> V_82 ) ) {
F_33 ( L_6 ,
V_11 -> V_14 , V_11 -> V_87 ) ;
return - V_15 ;
}
F_34 ( V_11 -> V_82 ) ;
if ( ! F_23 ( V_11 ) )
F_17 ( L_7 ,
V_11 -> V_14 , V_11 -> V_87 ) ;
return V_86 ;
}
static int F_35 ( struct V_10 * V_11 )
{
struct V_1 * V_88 ;
struct V_2 * V_3 ;
struct V_80 * V_41 ;
int V_4 = 0 ;
int V_86 = 0 ;
V_3 = V_11 -> V_89 . V_9 ;
while ( V_4 < V_11 -> V_90 ) {
V_88 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_88 -> V_80 )
continue;
V_41 = F_31 ( NULL , V_88 -> V_80 ) ;
if ( F_32 ( V_41 ) ) {
F_33 ( L_8 ,
V_11 -> V_14 , V_88 -> V_80 ) ;
V_86 = - V_15 ;
}
V_88 -> V_82 = V_41 ;
F_34 ( V_88 -> V_82 ) ;
}
return V_86 ;
}
static int F_36 ( struct V_10 * V_11 )
{
struct V_91 * V_92 ;
struct V_80 * V_41 ;
int V_4 ;
int V_86 = 0 ;
for ( V_4 = V_11 -> V_93 , V_92 = V_11 -> V_94 ; V_4 > 0 ; V_4 -- , V_92 ++ ) {
V_41 = F_31 ( NULL , V_92 -> V_80 ) ;
if ( F_32 ( V_41 ) ) {
F_33 ( L_9 ,
V_11 -> V_14 , V_92 -> V_80 ) ;
V_86 = - V_15 ;
}
V_92 -> V_82 = V_41 ;
F_34 ( V_92 -> V_82 ) ;
}
return V_86 ;
}
static int F_37 ( struct V_10 * V_11 )
{
struct V_1 * V_88 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_17 ( L_10 , V_11 -> V_14 ) ;
if ( V_11 -> V_82 )
F_38 ( V_11 -> V_82 ) ;
V_3 = V_11 -> V_89 . V_9 ;
while ( V_4 < V_11 -> V_90 ) {
V_88 = F_1 ( & V_3 , & V_4 ) ;
if ( V_88 -> V_82 && ( V_88 -> V_66 & V_95 ) )
F_38 ( V_88 -> V_82 ) ;
}
return 0 ;
}
static int F_39 ( struct V_10 * V_11 )
{
struct V_1 * V_88 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_17 ( L_11 , V_11 -> V_14 ) ;
if ( V_11 -> V_82 )
F_40 ( V_11 -> V_82 ) ;
V_3 = V_11 -> V_89 . V_9 ;
while ( V_4 < V_11 -> V_90 ) {
V_88 = F_1 ( & V_3 , & V_4 ) ;
if ( V_88 -> V_82 && ( V_88 -> V_66 & V_95 ) )
F_40 ( V_88 -> V_82 ) ;
}
return 0 ;
}
static void F_41 ( struct V_10 * V_11 )
{
struct V_91 * V_92 ;
int V_4 ;
F_17 ( L_12 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_93 , V_92 = V_11 -> V_94 ; V_4 > 0 ; V_4 -- , V_92 ++ )
if ( V_92 -> V_82 ) {
F_17 ( L_13 , V_92 -> V_96 ,
F_42 ( V_92 -> V_82 ) ) ;
F_38 ( V_92 -> V_82 ) ;
}
}
static void F_43 ( struct V_10 * V_11 )
{
struct V_91 * V_92 ;
int V_4 ;
F_17 ( L_14 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_93 , V_92 = V_11 -> V_94 ; V_4 > 0 ; V_4 -- , V_92 ++ )
if ( V_92 -> V_82 ) {
F_17 ( L_15 , V_92 -> V_96 ,
F_42 ( V_92 -> V_82 ) ) ;
F_40 ( V_92 -> V_82 ) ;
}
}
static void F_44 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_81 || ! V_11 -> V_97 . V_98 . V_99 )
return;
F_17 ( L_16 ,
V_11 -> V_14 , V_100 , V_11 -> V_97 . V_98 . V_99 ) ;
F_45 ( V_11 -> V_97 . V_98 . V_99 ,
V_11 -> V_81 -> V_101 ,
V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_97 . V_98 . V_104 ) ;
}
static void F_46 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_81 || ! V_11 -> V_97 . V_98 . V_99 )
return;
F_17 ( L_16 ,
V_11 -> V_14 , V_100 , V_11 -> V_97 . V_98 . V_99 ) ;
F_47 ( V_11 -> V_97 . V_98 . V_99 , V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_97 . V_98 . V_104 ) ;
}
static int F_48 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_105 || ! V_11 -> V_81 )
return 0 ;
if ( V_11 -> V_66 & V_106 )
return 0 ;
return F_49 ( V_11 -> V_81 -> V_101 ,
V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_97 . V_98 . V_104 ) ;
}
static int F_50 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_105 )
return 0 ;
if ( V_11 -> V_66 & V_106 )
return 0 ;
return F_51 ( V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_97 . V_98 . V_104 ) ;
}
static int F_52 ( struct V_10 * V_11 )
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
static int F_53 ( struct V_10 * V_11 )
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
static int F_54 ( struct V_1 * V_88 )
{
struct V_115 * V_116 ;
int V_4 = 0 ;
if ( ! V_88 || ! V_88 -> V_117 )
return 0 ;
do {
V_116 = & V_88 -> V_117 [ V_4 ++ ] ;
} while ( V_116 -> V_118 != V_116 -> V_119 );
return V_4 - 1 ;
}
static int F_55 ( struct V_10 * V_11 , const char * V_14 ,
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
static int F_56 ( struct V_10 * V_11 , const char * V_14 ,
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
static int F_57 ( struct V_10 * V_11 , const char * V_14 ,
T_1 * V_118 , T_1 * V_119 )
{
int V_4 , V_61 ;
struct V_1 * V_88 ;
struct V_2 * V_3 = NULL ;
bool V_120 = false ;
V_3 = V_11 -> V_89 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_90 ) {
V_88 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_88 -> V_117 )
return - V_121 ;
V_61 = 0 ;
while ( V_88 -> V_117 [ V_61 ] . V_118 != V_88 -> V_117 [ V_61 ] . V_119 ) {
if ( V_14 == V_88 -> V_117 [ V_61 ] . V_14 ||
! strcmp ( V_14 , V_88 -> V_117 [ V_61 ] . V_14 ) ) {
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
* V_118 = V_88 -> V_117 [ V_61 ] . V_118 ;
* V_119 = V_88 -> V_117 [ V_61 ] . V_119 ;
return 0 ;
}
static void T_4 F_58 ( struct V_10 * V_11 )
{
struct V_1 * V_88 = NULL ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( ! V_11 )
return;
V_11 -> V_20 |= V_105 ;
V_3 = V_11 -> V_89 . V_9 ;
while ( V_4 < V_11 -> V_90 ) {
V_88 = F_1 ( & V_3 , & V_4 ) ;
if ( V_88 -> V_123 & V_124 ) {
V_11 -> V_125 = V_88 ;
V_11 -> V_20 &= ~ V_105 ;
break;
}
}
return;
}
static struct V_1 * F_59 ( struct V_10 * V_11 )
{
if ( ! V_11 || V_11 -> V_20 & V_105 || V_11 -> V_90 == 0 )
return NULL ;
return V_11 -> V_125 ;
}
static struct V_115 * T_4 F_60 ( struct V_10 * V_11 )
{
struct V_1 * V_88 ;
struct V_115 * V_116 ;
int V_120 = 0 , V_4 = 0 ;
V_88 = F_59 ( V_11 ) ;
if ( ! V_88 || ! V_88 -> V_117 )
return NULL ;
do {
V_116 = & V_88 -> V_117 [ V_4 ++ ] ;
if ( V_116 -> V_66 & V_126 )
V_120 = 1 ;
} while ( ! V_120 && V_116 -> V_118 != V_116 -> V_119 );
return ( V_120 ) ? V_116 : NULL ;
}
static void F_61 ( struct V_10 * V_11 )
{
T_2 V_29 , V_127 ;
T_1 V_22 ;
bool V_128 ;
struct V_78 * V_81 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
if ( V_11 -> V_66 & V_129 )
F_41 ( V_11 ) ;
F_13 ( V_11 ) ;
if ( V_11 -> V_66 & V_129 )
F_43 ( V_11 ) ;
V_22 = V_11 -> V_16 ;
V_127 = V_11 -> V_12 -> V_13 -> V_18 ;
V_81 = F_23 ( V_11 ) ;
if ( V_127 & V_32 ) {
if ( V_11 -> V_66 & V_130 ||
V_11 -> V_66 & V_131 ) {
V_29 = V_132 ;
} else {
if ( V_127 & V_71 )
F_21 ( V_11 , & V_22 ) ;
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
F_21 ( V_11 , & V_22 ) ;
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
F_18 ( V_11 , V_29 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
}
static void F_62 ( struct V_10 * V_11 )
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
F_21 ( V_11 , & V_22 ) ;
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
F_21 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_74 )
V_29 = V_76 ;
else
V_29 = V_77 ;
}
F_8 ( V_11 , V_29 , & V_22 ) ;
}
F_6 ( V_22 , V_11 ) ;
}
static void F_63 ( struct V_10 * V_11 )
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
V_11 -> V_81 = F_67 ( V_11 -> V_141 ) ;
if ( ! V_11 -> V_81 ) {
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
int V_86 = 0 ;
if ( V_11 -> V_49 != V_143 )
return 0 ;
F_17 ( L_20 , V_11 -> V_14 ) ;
if ( V_144 . V_84 )
V_86 |= V_144 . V_84 ( V_11 ) ;
V_86 |= F_30 ( V_11 ) ;
V_86 |= F_35 ( V_11 ) ;
V_86 |= F_36 ( V_11 ) ;
if ( ! V_86 )
V_11 -> V_49 = V_145 ;
else
F_33 ( L_21 , V_11 -> V_14 ) ;
return V_86 ;
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
V_11 -> V_14 , V_100 , V_149 , V_147 -> V_151 ,
V_147 -> V_152 ) ;
return 0 ;
}
}
return - V_121 ;
}
static int F_70 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_146 V_147 ;
int V_86 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_144 . V_153 )
return - V_154 ;
V_86 = F_69 ( V_11 , V_14 , & V_147 ) ;
if ( V_86 < 0 )
return V_86 ;
V_86 = V_144 . V_153 ( V_11 , & V_147 ) ;
return V_86 ;
}
static int F_71 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_146 V_147 ;
int V_86 = - V_15 ;
int V_155 = 0 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_144 . V_156 )
return - V_154 ;
V_86 = F_69 ( V_11 , V_14 , & V_147 ) ;
if ( V_86 < 0 )
return V_86 ;
if ( V_11 -> V_81 ) {
V_155 = F_72 ( V_11 -> V_81 ) ;
V_86 = F_73 ( V_11 -> V_81 , V_11 ) ;
if ( V_86 ) {
F_4 ( 1 , L_23 ,
V_11 -> V_14 , V_11 -> V_81 -> V_14 , V_86 ) ;
return V_86 ;
}
}
F_37 ( V_11 ) ;
if ( V_144 . V_157 )
V_144 . V_157 ( V_11 ) ;
V_86 = V_144 . V_156 ( V_11 , & V_147 ) ;
if ( V_144 . V_158 )
V_144 . V_158 ( V_11 ) ;
F_39 ( V_11 ) ;
if ( V_86 == - V_159 )
F_33 ( L_24 , V_11 -> V_14 ) ;
if ( ! V_86 ) {
if ( V_11 -> V_81 && V_155 )
F_74 ( V_11 -> V_81 ) ;
} else {
if ( V_11 -> V_81 )
F_75 ( V_11 -> V_81 , V_11 ) ;
}
return V_86 ;
}
static int F_76 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_146 V_147 ;
int V_86 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_144 . V_160 )
return - V_154 ;
V_86 = F_69 ( V_11 , V_14 , & V_147 ) ;
if ( V_86 < 0 )
return V_86 ;
return V_144 . V_160 ( V_11 , & V_147 ) ;
}
static bool F_77 ( struct V_10 * V_11 )
{
int V_4 , V_161 = 0 ;
if ( V_11 -> V_148 == 0 )
return false ;
for ( V_4 = 0 ; V_4 < V_11 -> V_148 ; V_4 ++ )
if ( F_76 ( V_11 , V_11 -> V_150 [ V_4 ] . V_14 ) > 0 )
V_161 ++ ;
if ( V_11 -> V_148 == V_161 )
return true ;
return false ;
}
static bool F_78 ( struct V_10 * V_11 )
{
int V_161 = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_148 && V_161 == 0 ; V_4 ++ )
if ( F_76 ( V_11 , V_11 -> V_150 [ V_4 ] . V_14 ) > 0 )
V_161 ++ ;
return ( V_161 ) ? true : false ;
}
static int F_79 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! V_11 -> V_81 || ! V_11 -> V_97 . V_98 . V_99 )
return - V_15 ;
if ( F_78 ( V_11 ) )
return 0 ;
F_17 ( L_25 , V_11 -> V_14 , V_100 ) ;
F_80 ( V_11 -> V_81 -> V_101 ,
V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_97 . V_98 . V_104 ) ;
V_22 = F_48 ( V_11 ) ;
if ( V_22 )
F_16 ( L_26 ,
V_11 -> V_14 ) ;
return 0 ;
}
static int F_81 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! V_11 -> V_81 || ! V_11 -> V_97 . V_98 . V_99 )
return - V_15 ;
F_17 ( L_25 , V_11 -> V_14 , V_100 ) ;
if ( F_78 ( V_11 ) )
return 0 ;
F_82 ( V_11 -> V_81 -> V_102 , V_11 -> V_81 -> V_103 ,
V_11 -> V_97 . V_98 . V_104 ) ;
V_22 = F_50 ( V_11 ) ;
if ( V_22 )
F_16 ( L_26 ,
V_11 -> V_14 ) ;
return 0 ;
}
static int F_83 ( struct V_10 * V_11 )
{
T_1 V_22 ;
int V_41 = 0 ;
int V_86 = 0 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_38 ) )
return - V_121 ;
if ( V_11 -> V_49 != V_50 ) {
F_16 ( L_27 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_66 & V_129 )
F_41 ( V_11 ) ;
F_17 ( L_28 , V_11 -> V_14 ) ;
V_22 = V_11 -> V_16 ;
V_86 = F_12 ( V_11 , & V_22 ) ;
if ( V_86 )
goto V_162;
F_6 ( V_22 , V_11 ) ;
if ( V_11 -> V_12 -> V_13 -> V_163 )
F_84 ( V_11 -> V_12 -> V_13 -> V_163 ) ;
V_41 = F_13 ( V_11 ) ;
if ( V_41 == V_45 )
F_33 ( L_29 ,
V_11 -> V_14 , V_45 ) ;
else
F_17 ( L_30 , V_11 -> V_14 , V_41 ) ;
V_86 = ( V_41 == V_45 ) ? - V_164 : 0 ;
V_162:
if ( V_11 -> V_66 & V_129 )
F_43 ( V_11 ) ;
return V_86 ;
}
static int F_85 ( struct V_10 * V_11 )
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
V_165 = F_83 ( V_11 ) ;
if ( V_165 == - V_121 )
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
static void F_86 ( void )
{
unsigned long V_66 ;
F_87 ( & V_167 , V_66 ) ;
if ( F_88 () && F_89 () )
F_90 () ;
else if ( F_91 () )
F_92 () ;
F_93 ( & V_167 , V_66 ) ;
}
static void F_94 ( struct V_10 * V_11 )
{
if ( V_11 -> V_97 . V_98 . V_66 & V_168 )
return;
if ( ! F_95 ( V_11 -> V_81 -> V_169 . V_170 -> V_101 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_97 . V_98 . V_172 ) )
return;
V_11 -> V_97 . V_98 . V_173 ++ ;
F_96 ( V_11 -> V_81 -> V_169 . V_170 -> V_101 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_97 . V_98 . V_172 ) ;
}
static int F_97 ( struct V_10 * V_11 )
{
return V_11 -> V_97 . V_98 . V_173 ;
}
static int F_98 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_12 -> V_174 )
return 0 ;
return V_11 -> V_12 -> V_174 ( V_11 ) ;
}
static int F_99 ( struct V_10 * V_11 )
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
if ( F_77 ( V_11 ) )
return 0 ;
if ( V_11 -> V_62 && ( ! V_11 -> V_62 -> V_63 ||
( ( V_11 -> V_49 == V_70 ) &&
V_11 -> V_62 -> V_65 ) ) ) {
F_20 ( V_11 -> V_62 , V_50 ) ;
F_86 () ;
}
F_26 ( V_11 , V_178 ) ;
if ( V_11 -> V_81 ) {
V_155 = F_72 ( V_11 -> V_81 ) &&
! F_100 ( V_11 -> V_81 ) ;
V_165 = F_73 ( V_11 -> V_81 , V_11 ) ;
if ( V_165 ) {
F_4 ( 1 , L_23 ,
V_11 -> V_14 , V_11 -> V_81 -> V_14 , V_165 ) ;
return V_165 ;
}
}
F_37 ( V_11 ) ;
if ( V_144 . V_157 )
V_144 . V_157 ( V_11 ) ;
if ( V_11 -> V_66 & V_179 )
F_101 ( true ) ;
if ( V_144 . V_180 )
V_144 . V_180 ( V_11 ) ;
V_165 = ( V_144 . V_181 ) ? V_144 . V_181 ( V_11 ) :
- V_15 ;
if ( ! V_165 ) {
if ( V_11 -> V_81 && V_155 )
F_74 ( V_11 -> V_81 ) ;
V_11 -> V_49 = V_50 ;
if ( V_11 -> V_12 -> V_13 ) {
if ( ! ( V_11 -> V_20 & V_21 ) )
F_3 ( V_11 ) ;
F_61 ( V_11 ) ;
}
V_165 = F_98 ( V_11 ) ;
} else {
if ( V_144 . V_158 )
V_144 . V_158 ( V_11 ) ;
F_39 ( V_11 ) ;
F_17 ( L_34 ,
V_11 -> V_14 , V_165 ) ;
if ( V_11 -> V_81 )
F_75 ( V_11 -> V_81 , V_11 ) ;
}
return V_165 ;
}
static int F_102 ( struct V_10 * V_11 )
{
F_17 ( L_35 , V_11 -> V_14 ) ;
if ( V_11 -> V_49 != V_50 ) {
F_4 ( 1 , L_36 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_77 ( V_11 ) )
return 0 ;
if ( V_11 -> V_12 -> V_13 )
F_62 ( V_11 ) ;
F_28 ( V_11 , V_178 ) ;
if ( V_11 -> V_66 & V_179 )
F_101 ( false ) ;
if ( V_144 . V_158 )
V_144 . V_158 ( V_11 ) ;
F_39 ( V_11 ) ;
if ( V_11 -> V_81 )
F_75 ( V_11 -> V_81 , V_11 ) ;
if ( V_11 -> V_62 && V_11 -> V_62 -> V_65 ) {
F_20 ( V_11 -> V_62 , V_70 ) ;
F_86 () ;
}
V_11 -> V_49 = V_70 ;
return 0 ;
}
static int F_103 ( struct V_10 * V_11 )
{
int V_86 , V_4 ;
T_2 V_182 ;
if ( V_11 -> V_49 != V_70 &&
V_11 -> V_49 != V_50 ) {
F_4 ( 1 , L_37 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_77 ( V_11 ) )
return 0 ;
F_17 ( L_38 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_183 ) {
V_182 = V_11 -> V_49 ;
if ( V_11 -> V_49 == V_70 )
F_99 ( V_11 ) ;
V_86 = V_11 -> V_12 -> V_183 ( V_11 ) ;
if ( V_86 ) {
if ( V_182 == V_70 )
F_102 ( V_11 ) ;
return V_86 ;
}
}
if ( V_11 -> V_12 -> V_13 ) {
if ( V_11 -> V_49 == V_70 )
F_99 ( V_11 ) ;
F_63 ( V_11 ) ;
}
if ( V_11 -> V_49 == V_50 ) {
F_28 ( V_11 , V_178 ) ;
if ( V_11 -> V_66 & V_179 )
F_101 ( false ) ;
if ( V_144 . V_158 )
V_144 . V_158 ( V_11 ) ;
F_39 ( V_11 ) ;
if ( V_11 -> V_81 )
F_75 ( V_11 -> V_81 , V_11 ) ;
}
for ( V_4 = 0 ; V_4 < V_11 -> V_148 ; V_4 ++ )
F_70 ( V_11 , V_11 -> V_150 [ V_4 ] . V_14 ) ;
if ( V_11 -> V_62 )
F_20 ( V_11 -> V_62 , V_177 ) ;
V_11 -> V_49 = V_177 ;
return 0 ;
}
static struct V_184 * F_104 ( struct V_184 * V_185 ,
struct V_10 * V_11 )
{
struct V_184 * V_186 = NULL , * V_187 = NULL ;
const char * V_3 ;
F_105 (np, np0) {
if ( F_106 ( V_186 , L_39 , NULL ) ) {
V_3 = F_107 ( V_186 , L_39 , NULL ) ;
if ( ! strcmp ( V_3 , V_11 -> V_14 ) )
return V_186 ;
V_187 = F_104 ( V_186 , V_11 ) ;
if ( V_187 )
return V_187 ;
}
}
return NULL ;
}
static void T_4 F_108 ( struct V_10 * V_11 , void * V_142 )
{
struct V_115 * V_116 ;
void T_5 * va_start = NULL ;
struct V_184 * V_185 ;
if ( ! V_11 )
return;
F_58 ( V_11 ) ;
if ( V_11 -> V_20 & V_105 )
return;
V_116 = F_60 ( V_11 ) ;
if ( ! V_116 ) {
F_17 ( L_40 ,
V_11 -> V_14 ) ;
if ( ! F_109 () )
return;
V_185 = F_104 ( F_110 ( NULL , L_41 ) , V_11 ) ;
if ( V_185 )
va_start = F_111 ( V_185 , V_11 -> V_188 ) ;
} else {
va_start = F_112 ( V_116 -> V_118 , V_116 -> V_119 - V_116 -> V_118 ) ;
}
if ( ! va_start ) {
F_113 ( L_42 , V_11 -> V_14 ) ;
return;
}
F_17 ( L_43 ,
V_11 -> V_14 , va_start ) ;
V_11 -> V_189 = va_start ;
}
static int T_4 F_114 ( struct V_10 * V_11 , void * V_142 )
{
int V_165 ;
if ( V_11 -> V_49 != V_143 )
return 0 ;
if ( V_11 -> V_12 -> V_13 )
F_108 ( V_11 , NULL ) ;
V_165 = F_68 ( V_11 , NULL ) ;
if ( V_165 < 0 ) {
F_4 ( 1 , L_44 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_49 = V_176 ;
return 0 ;
}
static void T_4 F_115 ( struct V_10 * V_11 )
{
struct V_1 * V_88 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( V_11 -> V_49 != V_176 )
return;
V_3 = V_11 -> V_89 . V_9 ;
while ( V_4 < V_11 -> V_90 ) {
V_88 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_88 -> V_82 )
continue;
if ( V_88 -> V_66 & V_95 ) {
} else {
F_38 ( V_88 -> V_82 ) ;
}
}
return;
}
static int T_4 F_116 ( struct V_10 * V_11 )
{
int V_165 ;
if ( V_11 -> V_49 != V_176 )
return - V_15 ;
if ( V_11 -> V_66 & V_190 )
return - V_191 ;
if ( V_11 -> V_148 == 0 ) {
V_165 = F_99 ( V_11 ) ;
if ( V_165 ) {
F_33 ( L_45 ,
V_11 -> V_14 , V_11 -> V_49 ) ;
return - V_15 ;
}
}
if ( ! ( V_11 -> V_66 & V_192 ) )
V_165 = F_85 ( V_11 ) ;
return V_165 ;
}
static void T_4 F_117 ( struct V_10 * V_11 )
{
T_2 V_193 ;
if ( V_11 -> V_148 > 0 )
return;
V_193 = V_11 -> V_194 ;
if ( V_193 == V_195 )
V_193 = V_50 ;
if ( ( V_11 -> V_66 & V_196 ) &&
( V_193 == V_70 ) ) {
V_11 -> V_20 |= V_175 ;
V_193 = V_50 ;
}
if ( V_193 == V_70 )
F_102 ( V_11 ) ;
else if ( V_193 == V_177 )
F_103 ( V_11 ) ;
else if ( V_193 != V_50 )
F_4 ( 1 , L_46 ,
V_11 -> V_14 , V_193 ) ;
return;
}
static int T_4 F_118 ( struct V_10 * V_11 , void * V_142 )
{
if ( V_11 -> V_49 != V_176 )
return 0 ;
F_115 ( V_11 ) ;
if ( ! F_116 ( V_11 ) )
F_117 ( V_11 ) ;
return 0 ;
}
static int T_4 F_119 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_14 || ! V_11 -> V_12 || ! V_11 -> V_12 -> V_14 ||
( V_11 -> V_49 != V_195 ) )
return - V_15 ;
F_17 ( L_47 , V_11 -> V_14 ) ;
if ( F_64 ( V_11 -> V_14 ) )
return - V_197 ;
F_120 ( & V_11 -> V_7 , & V_198 ) ;
F_121 ( & V_11 -> V_199 ) ;
F_121 ( & V_11 -> V_89 ) ;
F_122 ( & V_11 -> V_200 ) ;
V_11 -> V_49 = V_143 ;
if ( ! strcmp ( V_11 -> V_14 , V_201 ) )
V_178 = V_11 ;
return 0 ;
}
static int T_4 F_123 ( struct V_6 * * V_202 ,
struct V_6 * * V_203 )
{
unsigned int V_204 ;
if ( ( V_205 + V_206 ) <= V_207 ) {
* V_202 = & V_208 [ V_205 ++ ] ;
* V_203 = & V_208 [ V_205 ++ ] ;
return 0 ;
}
V_204 = sizeof( struct V_6 ) * V_206 ;
* V_203 = NULL ;
* V_202 = F_124 ( V_204 ) ;
memset ( * V_202 , 0 , V_204 ) ;
* V_203 = ( void * ) ( * V_202 ) + sizeof( struct V_6 ) ;
V_209 ++ ;
F_17 ( L_48 ,
V_209 * V_206 ) ;
return 0 ;
}
static int T_4 F_125 ( struct V_1 * V_5 )
{
struct V_6 * V_202 , * V_203 ;
F_17 ( L_49 , V_5 -> V_210 -> V_14 ,
V_5 -> V_211 -> V_14 ) ;
F_123 ( & V_202 , & V_203 ) ;
V_202 -> V_8 = V_5 ;
F_121 ( & V_202 -> V_7 ) ;
F_126 ( & V_202 -> V_7 , & V_5 -> V_210 -> V_199 ) ;
V_5 -> V_210 -> V_212 ++ ;
V_203 -> V_8 = V_5 ;
F_121 ( & V_203 -> V_7 ) ;
F_126 ( & V_203 -> V_7 , & V_5 -> V_211 -> V_89 ) ;
V_5 -> V_211 -> V_90 ++ ;
return 0 ;
}
static int T_4 F_127 ( struct V_1 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_210 || ! V_5 -> V_211 || ! V_5 -> V_123 )
return - V_15 ;
if ( V_5 -> V_20 & V_213 )
return - V_197 ;
F_17 ( L_50 ,
V_5 -> V_210 -> V_14 , V_5 -> V_211 -> V_14 ) ;
if ( V_5 -> V_210 -> V_49 != V_143 )
F_119 ( V_5 -> V_210 ) ;
if ( V_5 -> V_211 -> V_49 != V_143 )
F_119 ( V_5 -> V_211 ) ;
F_125 ( V_5 ) ;
V_5 -> V_20 |= V_213 ;
return 0 ;
}
static int T_4 F_128 ( struct V_1 * * V_214 )
{
unsigned int V_4 = 0 ;
unsigned int V_204 ;
if ( V_208 ) {
F_4 ( 1 , L_51 ) ;
return - V_197 ;
}
if ( V_207 == 0 )
while ( V_214 [ V_4 ++ ] )
V_207 += V_206 ;
V_204 = sizeof( struct V_6 ) * V_207 ;
F_17 ( L_52 ,
V_100 , V_204 , V_207 ) ;
V_208 = F_124 ( V_204 ) ;
memset ( V_208 , 0 , V_204 ) ;
return 0 ;
}
static int F_129 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_106 )
return 0 ;
if ( ! F_59 ( V_11 ) )
return 0 ;
return F_130 ( V_11 -> V_97 . V_215 . V_216 ,
V_11 -> V_97 . V_215 . V_217 ,
V_11 -> V_97 . V_215 . V_218 ) ;
}
static int F_131 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_106 )
return 0 ;
if ( ! F_59 ( V_11 ) )
return 0 ;
return F_132 ( V_11 -> V_97 . V_215 . V_216 ,
V_11 -> V_97 . V_215 . V_217 ,
V_11 -> V_97 . V_215 . V_218 ) ;
}
static int F_133 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_106 || ! V_11 -> V_81 )
return 0 ;
if ( ! F_59 ( V_11 ) )
return 0 ;
return F_134 ( V_11 -> V_81 -> V_101 ,
V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_97 . V_98 . V_104 ) ;
}
static int F_135 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_81 )
return - V_15 ;
if ( V_11 -> V_66 & V_106 )
return 0 ;
if ( ! F_59 ( V_11 ) )
return 0 ;
return F_136 ( V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_97 . V_98 . V_104 ) ;
}
static int F_137 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_138 ( V_11 -> V_97 . V_215 . V_216 ,
V_147 -> V_151 ) ;
}
static int F_139 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_140 ( V_11 -> V_97 . V_215 . V_216 ,
V_147 -> V_151 ,
V_147 -> V_152 ) ;
}
static int F_141 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_142 ( V_11 -> V_97 . V_215 . V_216 ,
V_147 -> V_152 ) ;
}
static int F_143 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
return F_144 ( V_147 -> V_151 ,
V_11 -> V_81 -> V_169 . V_170 -> V_101 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_97 . V_98 . V_219 ) ;
}
static int F_145 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
if ( V_147 -> V_152 )
F_113 ( L_53 ,
V_11 -> V_14 , V_147 -> V_14 ) ;
return F_146 ( V_147 -> V_151 ,
V_11 -> V_81 -> V_169 . V_170 -> V_101 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_97 . V_98 . V_219 ) ;
}
static int F_147 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
return F_148 ( V_147 -> V_151 ,
V_11 -> V_81 -> V_169 . V_170 -> V_101 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_97 . V_98 . V_219 ) ;
}
static int F_149 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_150 ( V_147 -> V_151 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_97 . V_98 . V_219 ) ;
}
static int F_151 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_152 ( V_147 -> V_151 ,
V_147 -> V_152 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_97 . V_98 . V_219 ,
V_11 -> V_97 . V_98 . V_220 ) ;
}
static int F_153 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_154 ( V_147 -> V_151 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_97 . V_98 . V_219 ) ;
}
T_1 F_5 ( struct V_10 * V_11 , T_3 V_221 )
{
if ( V_11 -> V_66 & V_222 )
return F_155 ( V_11 -> V_189 + V_221 ) ;
else
return F_156 ( V_11 -> V_189 + V_221 ) ;
}
void F_7 ( T_1 V_22 , struct V_10 * V_11 , T_3 V_221 )
{
if ( V_11 -> V_66 & V_222 )
F_157 ( V_22 , V_11 -> V_189 + V_221 ) ;
else
F_158 ( V_22 , V_11 -> V_189 + V_221 ) ;
}
int F_159 ( struct V_10 * V_11 )
{
T_1 V_22 ;
int V_86 ;
if ( ! V_11 || ! ( V_11 -> V_16 ) )
return - V_15 ;
V_22 = V_11 -> V_16 ;
V_86 = F_12 ( V_11 , & V_22 ) ;
if ( V_86 )
goto error;
F_6 ( V_22 , V_11 ) ;
error:
return V_86 ;
}
struct V_10 * F_160 ( const char * V_14 )
{
struct V_10 * V_11 ;
if ( ! V_14 )
return NULL ;
V_11 = F_64 ( V_14 ) ;
return V_11 ;
}
int F_161 ( int (* F_162)( struct V_10 * V_11 , void * V_142 ) ,
void * V_142 )
{
struct V_10 * V_140 ;
int V_86 = 0 ;
if ( ! F_162 )
return - V_15 ;
F_65 (temp_oh, &omap_hwmod_list, node) {
V_86 = (* F_162)( V_140 , V_142 ) ;
if ( V_86 )
break;
}
return V_86 ;
}
int T_4 F_163 ( struct V_1 * * V_214 )
{
int V_165 , V_4 ;
if ( ! V_223 )
return - V_15 ;
if ( ! V_214 )
return 0 ;
if ( ! V_208 ) {
if ( F_128 ( V_214 ) ) {
F_113 ( L_54 ) ;
return - V_224 ;
}
}
V_4 = 0 ;
do {
V_165 = F_127 ( V_214 [ V_4 ] ) ;
F_4 ( V_165 && V_165 != - V_197 ,
L_55 ,
V_214 [ V_4 ] -> V_210 -> V_14 , V_214 [ V_4 ] -> V_211 -> V_14 , V_165 ) ;
} while ( V_214 [ ++ V_4 ] );
return 0 ;
}
static void T_4 F_164 ( struct V_10 * V_11 )
{
if ( ! V_178 || V_178 -> V_49 == V_195 )
F_113 ( L_56 ,
V_100 , V_201 ) ;
else if ( V_178 -> V_49 == V_143 && V_11 != V_178 )
F_165 ( V_201 ) ;
}
int T_4 F_165 ( const char * V_225 )
{
struct V_10 * V_11 ;
F_17 ( L_25 , V_225 , V_100 ) ;
V_11 = F_64 ( V_225 ) ;
if ( ! V_11 ) {
F_4 ( 1 , L_57 , V_225 ) ;
return - V_15 ;
}
F_164 ( V_11 ) ;
F_114 ( V_11 , NULL ) ;
F_118 ( V_11 , NULL ) ;
return 0 ;
}
static int T_4 F_166 ( void )
{
F_164 ( NULL ) ;
F_161 ( F_114 , NULL ) ;
F_161 ( F_118 , NULL ) ;
return 0 ;
}
int F_167 ( struct V_10 * V_11 )
{
int V_165 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_87 ( & V_11 -> V_200 , V_66 ) ;
V_165 = F_99 ( V_11 ) ;
F_93 ( & V_11 -> V_200 , V_66 ) ;
return V_165 ;
}
int F_168 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_87 ( & V_11 -> V_200 , V_66 ) ;
F_102 ( V_11 ) ;
F_93 ( & V_11 -> V_200 , V_66 ) ;
return 0 ;
}
int F_169 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_87 ( & V_11 -> V_200 , V_66 ) ;
F_103 ( V_11 ) ;
F_93 ( & V_11 -> V_200 , V_66 ) ;
return 0 ;
}
int F_170 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
F_87 ( & V_11 -> V_200 , V_66 ) ;
F_37 ( V_11 ) ;
F_93 ( & V_11 -> V_200 , V_66 ) ;
return 0 ;
}
int F_171 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
F_87 ( & V_11 -> V_200 , V_66 ) ;
F_39 ( V_11 ) ;
F_93 ( & V_11 -> V_200 , V_66 ) ;
return 0 ;
}
void F_172 ( struct V_10 * V_11 )
{
F_173 ( ! V_11 ) ;
if ( ! V_11 -> V_12 -> V_13 || ! V_11 -> V_12 -> V_13 -> V_18 ) {
F_4 ( 1 , L_58 ,
V_11 -> V_14 ) ;
return;
}
F_5 ( V_11 , V_11 -> V_12 -> V_13 -> V_17 ) ;
}
int F_174 ( struct V_10 * V_11 )
{
int V_165 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_87 ( & V_11 -> V_200 , V_66 ) ;
V_165 = F_85 ( V_11 ) ;
F_93 ( & V_11 -> V_200 , V_66 ) ;
return V_165 ;
}
int F_175 ( struct V_10 * V_11 , unsigned long V_66 )
{
int V_86 = 0 ;
if ( V_66 & V_226 )
V_86 += F_52 ( V_11 ) ;
if ( V_66 & V_227 )
V_86 += F_53 ( V_11 ) ;
if ( V_66 & V_228 ) {
int V_4 = 0 ;
struct V_1 * V_88 ;
struct V_2 * V_3 = V_11 -> V_89 . V_9 ;
while ( V_4 < V_11 -> V_90 ) {
V_88 = F_1 ( & V_3 , & V_4 ) ;
V_86 += F_54 ( V_88 ) ;
}
}
return V_86 ;
}
int F_176 ( struct V_10 * V_11 , struct V_229 * V_230 )
{
struct V_1 * V_88 ;
struct V_2 * V_3 ;
int V_4 , V_61 , V_231 , V_232 , V_233 ;
int V_165 = 0 ;
V_231 = F_52 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_231 ; V_4 ++ ) {
( V_230 + V_165 ) -> V_14 = ( V_11 -> V_109 + V_4 ) -> V_14 ;
( V_230 + V_165 ) -> V_234 = ( V_11 -> V_109 + V_4 ) -> V_110 ;
( V_230 + V_165 ) -> V_235 = ( V_11 -> V_109 + V_4 ) -> V_110 ;
( V_230 + V_165 ) -> V_66 = V_226 ;
V_165 ++ ;
}
V_232 = F_53 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_232 ; V_4 ++ ) {
( V_230 + V_165 ) -> V_14 = ( V_11 -> V_113 + V_4 ) -> V_14 ;
( V_230 + V_165 ) -> V_234 = ( V_11 -> V_113 + V_4 ) -> V_114 ;
( V_230 + V_165 ) -> V_235 = ( V_11 -> V_113 + V_4 ) -> V_114 ;
( V_230 + V_165 ) -> V_66 = V_227 ;
V_165 ++ ;
}
V_3 = V_11 -> V_89 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_90 ) {
V_88 = F_1 ( & V_3 , & V_4 ) ;
V_233 = F_54 ( V_88 ) ;
for ( V_61 = 0 ; V_61 < V_233 ; V_61 ++ ) {
( V_230 + V_165 ) -> V_14 = ( V_88 -> V_117 + V_61 ) -> V_14 ;
( V_230 + V_165 ) -> V_234 = ( V_88 -> V_117 + V_61 ) -> V_118 ;
( V_230 + V_165 ) -> V_235 = ( V_88 -> V_117 + V_61 ) -> V_119 ;
( V_230 + V_165 ) -> V_66 = V_228 ;
V_165 ++ ;
}
}
return V_165 ;
}
int F_177 ( struct V_10 * V_11 , struct V_229 * V_230 )
{
int V_4 , V_232 ;
int V_165 = 0 ;
V_232 = F_53 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_232 ; V_4 ++ ) {
( V_230 + V_165 ) -> V_14 = ( V_11 -> V_113 + V_4 ) -> V_14 ;
( V_230 + V_165 ) -> V_234 = ( V_11 -> V_113 + V_4 ) -> V_114 ;
( V_230 + V_165 ) -> V_235 = ( V_11 -> V_113 + V_4 ) -> V_114 ;
( V_230 + V_165 ) -> V_66 = V_227 ;
V_165 ++ ;
}
return V_165 ;
}
int F_178 ( struct V_10 * V_11 , unsigned int type ,
const char * V_14 , struct V_229 * V_236 )
{
int V_165 ;
unsigned int V_110 , V_122 ;
T_1 V_118 , V_119 ;
if ( ! V_11 || ! V_236 )
return - V_15 ;
if ( type == V_226 ) {
V_165 = F_55 ( V_11 , V_14 , & V_110 ) ;
if ( V_165 )
return V_165 ;
V_236 -> V_234 = V_110 ;
V_236 -> V_235 = V_110 ;
} else if ( type == V_227 ) {
V_165 = F_56 ( V_11 , V_14 , & V_122 ) ;
if ( V_165 )
return V_165 ;
V_236 -> V_234 = V_122 ;
V_236 -> V_235 = V_122 ;
} else if ( type == V_228 ) {
V_165 = F_57 ( V_11 , V_14 , & V_118 , & V_119 ) ;
if ( V_165 )
return V_165 ;
V_236 -> V_234 = V_118 ;
V_236 -> V_235 = V_119 ;
} else {
return - V_15 ;
}
V_236 -> V_66 = type ;
V_236 -> V_14 = V_14 ;
return 0 ;
}
struct V_237 * F_179 ( struct V_10 * V_11 )
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
V_5 = F_59 ( V_11 ) ;
if ( ! V_5 )
return NULL ;
V_41 = V_5 -> V_82 ;
}
V_80 = F_24 ( F_25 ( V_41 ) ) ;
V_81 = V_80 -> V_81 ;
if ( ! V_81 )
return NULL ;
return V_81 -> V_169 . V_170 ;
}
void T_5 * F_180 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_20 & V_105 )
return NULL ;
if ( V_11 -> V_49 == V_195 )
return NULL ;
return V_11 -> V_189 ;
}
int F_181 ( struct V_10 * V_11 ,
struct V_10 * V_83 )
{
return F_26 ( V_11 , V_83 ) ;
}
int F_182 ( struct V_10 * V_11 ,
struct V_10 * V_83 )
{
return F_28 ( V_11 , V_83 ) ;
}
int F_183 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
T_1 V_22 ;
F_87 ( & V_11 -> V_200 , V_66 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ) {
V_22 = V_11 -> V_16 ;
F_21 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_19 ( V_11 , true ) ;
F_93 ( & V_11 -> V_200 , V_66 ) ;
return 0 ;
}
int F_184 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
T_1 V_22 ;
F_87 ( & V_11 -> V_200 , V_66 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ) {
V_22 = V_11 -> V_16 ;
F_22 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_19 ( V_11 , false ) ;
F_93 ( & V_11 -> V_200 , V_66 ) ;
return 0 ;
}
int F_185 ( struct V_10 * V_11 , const char * V_14 )
{
int V_86 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_87 ( & V_11 -> V_200 , V_66 ) ;
V_86 = F_70 ( V_11 , V_14 ) ;
F_93 ( & V_11 -> V_200 , V_66 ) ;
return V_86 ;
}
int F_186 ( struct V_10 * V_11 , const char * V_14 )
{
int V_86 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_87 ( & V_11 -> V_200 , V_66 ) ;
V_86 = F_71 ( V_11 , V_14 ) ;
F_93 ( & V_11 -> V_200 , V_66 ) ;
return V_86 ;
}
int F_187 ( struct V_10 * V_11 , const char * V_14 )
{
int V_86 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_87 ( & V_11 -> V_200 , V_66 ) ;
V_86 = F_76 ( V_11 , V_14 ) ;
F_93 ( & V_11 -> V_200 , V_66 ) ;
return V_86 ;
}
int F_188 ( const char * V_238 ,
int (* F_162)( struct V_10 * V_11 ,
void * V_123 ) ,
void * V_123 )
{
struct V_10 * V_140 ;
int V_86 = 0 ;
if ( ! V_238 || ! F_162 )
return - V_15 ;
F_17 ( L_59 ,
V_100 , V_238 ) ;
F_65 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_140 -> V_12 -> V_14 , V_238 ) ) {
F_17 ( L_60 ,
V_100 , V_140 -> V_14 ) ;
V_86 = (* F_162)( V_140 , V_123 ) ;
if ( V_86 )
break;
}
}
if ( V_86 )
F_17 ( L_61 ,
V_100 , V_86 ) ;
return V_86 ;
}
int F_189 ( struct V_10 * V_11 , T_2 V_239 )
{
int V_86 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
if ( V_239 != V_177 &&
V_239 != V_50 &&
V_239 != V_70 )
return - V_15 ;
F_87 ( & V_11 -> V_200 , V_66 ) ;
if ( V_11 -> V_49 != V_143 ) {
V_86 = - V_15 ;
goto V_240;
}
V_11 -> V_194 = V_239 ;
V_86 = 0 ;
V_240:
F_93 ( & V_11 -> V_200 , V_66 ) ;
return V_86 ;
}
int F_190 ( struct V_10 * V_11 )
{
struct V_237 * V_169 ;
int V_86 = 0 ;
if ( V_144 . V_241 )
return V_144 . V_241 ( V_11 ) ;
V_169 = F_179 ( V_11 ) ;
if ( V_169 )
V_86 = F_191 ( V_169 ) ;
return V_86 ;
}
int F_192 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_49 != V_143 ) {
F_113 ( L_62 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_66 |= V_192 ;
return 0 ;
}
int F_193 ( struct V_10 * V_11 , int V_242 , int V_243 )
{
int V_244 ;
F_194 () ;
if ( ! V_11 || ! V_11 -> V_62 || ! V_11 -> V_109 || V_242 < 0 ||
V_242 >= V_11 -> V_62 -> V_64 )
return - V_15 ;
for ( V_244 = 0 ; V_11 -> V_109 [ V_244 ] . V_110 >= 0 ; V_244 ++ )
;
if ( V_243 >= V_244 )
return - V_15 ;
if ( ! V_11 -> V_62 -> V_245 ) {
V_11 -> V_62 -> V_245 = F_195 ( sizeof( int ) * V_11 -> V_62 -> V_64 ,
V_246 ) ;
if ( ! V_11 -> V_62 -> V_245 )
return - V_224 ;
}
V_11 -> V_62 -> V_245 [ V_242 ] = V_243 ;
return 0 ;
}
void T_4 F_196 ( void )
{
if ( F_197 () ) {
V_144 . V_181 = F_129 ;
V_144 . V_153 = F_137 ;
V_144 . V_156 = F_139 ;
V_144 . V_160 = F_141 ;
} else if ( F_88 () ) {
V_144 . V_181 = F_131 ;
V_144 . V_153 = F_137 ;
V_144 . V_156 = F_139 ;
V_144 . V_160 = F_141 ;
} else if ( F_91 () || F_198 () || F_199 () ) {
V_144 . V_157 = F_44 ;
V_144 . V_158 = F_79 ;
V_144 . V_181 = F_133 ;
V_144 . V_153 = F_143 ;
V_144 . V_156 = F_145 ;
V_144 . V_160 = F_147 ;
V_144 . V_84 = F_66 ;
V_144 . V_180 = F_94 ;
V_144 . V_241 = F_97 ;
} else if ( F_200 () ) {
V_144 . V_157 = F_46 ;
V_144 . V_158 = F_81 ;
V_144 . V_181 = F_135 ;
V_144 . V_153 = F_149 ;
V_144 . V_156 = F_151 ;
V_144 . V_160 = F_153 ;
V_144 . V_84 = F_66 ;
} else {
F_4 ( 1 , L_63 ) ;
}
V_223 = true ;
}
const char * F_201 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
return V_11 -> V_87 ;
}
