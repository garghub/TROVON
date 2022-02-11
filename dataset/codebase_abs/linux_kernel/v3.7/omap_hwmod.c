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
static int F_23 ( struct V_10 * V_11 , struct V_10 * V_79 )
{
if ( ! V_11 -> V_80 )
return - V_15 ;
if ( V_11 -> V_80 -> V_81 && V_11 -> V_80 -> V_81 -> V_66 & V_82 )
return 0 ;
return F_24 ( V_11 -> V_80 -> V_81 , V_79 -> V_80 -> V_81 ) ;
}
static int F_25 ( struct V_10 * V_11 , struct V_10 * V_79 )
{
if ( ! V_11 -> V_80 )
return - V_15 ;
if ( V_11 -> V_80 -> V_81 && V_11 -> V_80 -> V_81 -> V_66 & V_82 )
return 0 ;
return F_26 ( V_11 -> V_80 -> V_81 , V_79 -> V_80 -> V_81 ) ;
}
static int F_27 ( struct V_10 * V_11 )
{
int V_83 = 0 ;
if ( ! V_11 -> V_84 )
return 0 ;
V_11 -> V_80 = F_28 ( NULL , V_11 -> V_84 ) ;
if ( F_29 ( V_11 -> V_80 ) ) {
F_30 ( L_6 ,
V_11 -> V_14 , V_11 -> V_84 ) ;
return - V_15 ;
}
F_31 ( V_11 -> V_80 ) ;
if ( ! V_11 -> V_80 -> V_81 )
F_17 ( L_7 ,
V_11 -> V_14 , V_11 -> V_84 ) ;
return V_83 ;
}
static int F_32 ( struct V_10 * V_11 )
{
struct V_1 * V_85 ;
struct V_2 * V_3 ;
struct V_86 * V_41 ;
int V_4 = 0 ;
int V_83 = 0 ;
V_3 = V_11 -> V_87 . V_9 ;
while ( V_4 < V_11 -> V_88 ) {
V_85 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_85 -> V_86 )
continue;
V_41 = F_28 ( NULL , V_85 -> V_86 ) ;
if ( F_29 ( V_41 ) ) {
F_30 ( L_8 ,
V_11 -> V_14 , V_85 -> V_86 ) ;
V_83 = - V_15 ;
}
V_85 -> V_80 = V_41 ;
F_31 ( V_85 -> V_80 ) ;
}
return V_83 ;
}
static int F_33 ( struct V_10 * V_11 )
{
struct V_89 * V_90 ;
struct V_86 * V_41 ;
int V_4 ;
int V_83 = 0 ;
for ( V_4 = V_11 -> V_91 , V_90 = V_11 -> V_92 ; V_4 > 0 ; V_4 -- , V_90 ++ ) {
V_41 = F_28 ( NULL , V_90 -> V_86 ) ;
if ( F_29 ( V_41 ) ) {
F_30 ( L_9 ,
V_11 -> V_14 , V_90 -> V_86 ) ;
V_83 = - V_15 ;
}
V_90 -> V_80 = V_41 ;
F_31 ( V_90 -> V_80 ) ;
}
return V_83 ;
}
static int F_34 ( struct V_10 * V_11 )
{
struct V_1 * V_85 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_17 ( L_10 , V_11 -> V_14 ) ;
if ( V_11 -> V_80 )
F_35 ( V_11 -> V_80 ) ;
V_3 = V_11 -> V_87 . V_9 ;
while ( V_4 < V_11 -> V_88 ) {
V_85 = F_1 ( & V_3 , & V_4 ) ;
if ( V_85 -> V_80 && ( V_85 -> V_66 & V_93 ) )
F_35 ( V_85 -> V_80 ) ;
}
return 0 ;
}
static int F_36 ( struct V_10 * V_11 )
{
struct V_1 * V_85 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_17 ( L_11 , V_11 -> V_14 ) ;
if ( V_11 -> V_80 )
F_37 ( V_11 -> V_80 ) ;
V_3 = V_11 -> V_87 . V_9 ;
while ( V_4 < V_11 -> V_88 ) {
V_85 = F_1 ( & V_3 , & V_4 ) ;
if ( V_85 -> V_80 && ( V_85 -> V_66 & V_93 ) )
F_37 ( V_85 -> V_80 ) ;
}
return 0 ;
}
static void F_38 ( struct V_10 * V_11 )
{
struct V_89 * V_90 ;
int V_4 ;
F_17 ( L_12 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_91 , V_90 = V_11 -> V_92 ; V_4 > 0 ; V_4 -- , V_90 ++ )
if ( V_90 -> V_80 ) {
F_17 ( L_13 , V_90 -> V_94 ,
F_39 ( V_90 -> V_80 ) ) ;
F_35 ( V_90 -> V_80 ) ;
}
}
static void F_40 ( struct V_10 * V_11 )
{
struct V_89 * V_90 ;
int V_4 ;
F_17 ( L_14 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_91 , V_90 = V_11 -> V_92 ; V_4 > 0 ; V_4 -- , V_90 ++ )
if ( V_90 -> V_80 ) {
F_17 ( L_15 , V_90 -> V_94 ,
F_39 ( V_90 -> V_80 ) ) ;
F_37 ( V_90 -> V_80 ) ;
}
}
static void F_41 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_81 || ! V_11 -> V_95 . V_96 . V_97 )
return;
F_17 ( L_16 ,
V_11 -> V_14 , V_98 , V_11 -> V_95 . V_96 . V_97 ) ;
F_42 ( V_11 -> V_95 . V_96 . V_97 ,
V_11 -> V_81 -> V_99 ,
V_11 -> V_81 -> V_100 ,
V_11 -> V_81 -> V_101 ,
V_11 -> V_95 . V_96 . V_102 ) ;
}
static void F_43 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_81 || ! V_11 -> V_95 . V_96 . V_97 )
return;
F_17 ( L_16 ,
V_11 -> V_14 , V_98 , V_11 -> V_95 . V_96 . V_97 ) ;
F_44 ( V_11 -> V_95 . V_96 . V_97 , V_11 -> V_81 -> V_100 ,
V_11 -> V_81 -> V_101 ,
V_11 -> V_95 . V_96 . V_102 ) ;
}
static int F_45 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_103 || ! V_11 -> V_81 )
return 0 ;
if ( V_11 -> V_66 & V_104 )
return 0 ;
return F_46 ( V_11 -> V_81 -> V_99 ,
V_11 -> V_81 -> V_100 ,
V_11 -> V_81 -> V_101 ,
V_11 -> V_95 . V_96 . V_102 ) ;
}
static int F_47 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_103 )
return 0 ;
if ( V_11 -> V_66 & V_104 )
return 0 ;
return F_48 ( V_11 -> V_81 -> V_100 ,
V_11 -> V_81 -> V_101 ,
V_11 -> V_95 . V_96 . V_102 ) ;
}
static int F_49 ( struct V_10 * V_11 )
{
struct V_105 * V_106 ;
int V_4 = 0 ;
if ( ! V_11 || ! V_11 -> V_107 )
return 0 ;
do {
V_106 = & V_11 -> V_107 [ V_4 ++ ] ;
} while ( V_106 -> V_108 != - 1 );
return V_4 - 1 ;
}
static int F_50 ( struct V_10 * V_11 )
{
struct V_109 * V_110 ;
int V_4 = 0 ;
if ( ! V_11 || ! V_11 -> V_111 )
return 0 ;
do {
V_110 = & V_11 -> V_111 [ V_4 ++ ] ;
} while ( V_110 -> V_112 != - 1 );
return V_4 - 1 ;
}
static int F_51 ( struct V_1 * V_85 )
{
struct V_113 * V_114 ;
int V_4 = 0 ;
if ( ! V_85 || ! V_85 -> V_115 )
return 0 ;
do {
V_114 = & V_85 -> V_115 [ V_4 ++ ] ;
} while ( V_114 -> V_116 != V_114 -> V_117 );
return V_4 - 1 ;
}
static int F_52 ( struct V_10 * V_11 , const char * V_14 ,
unsigned int * V_108 )
{
int V_4 ;
bool V_118 = false ;
if ( ! V_11 -> V_107 )
return - V_119 ;
V_4 = 0 ;
while ( V_11 -> V_107 [ V_4 ] . V_108 != - 1 ) {
if ( V_14 == V_11 -> V_107 [ V_4 ] . V_14 ||
! strcmp ( V_14 , V_11 -> V_107 [ V_4 ] . V_14 ) ) {
V_118 = true ;
break;
}
V_4 ++ ;
}
if ( ! V_118 )
return - V_119 ;
* V_108 = V_11 -> V_107 [ V_4 ] . V_108 ;
return 0 ;
}
static int F_53 ( struct V_10 * V_11 , const char * V_14 ,
unsigned int * V_120 )
{
int V_4 ;
bool V_118 = false ;
if ( ! V_11 -> V_111 )
return - V_119 ;
V_4 = 0 ;
while ( V_11 -> V_111 [ V_4 ] . V_112 != - 1 ) {
if ( V_14 == V_11 -> V_111 [ V_4 ] . V_14 ||
! strcmp ( V_14 , V_11 -> V_111 [ V_4 ] . V_14 ) ) {
V_118 = true ;
break;
}
V_4 ++ ;
}
if ( ! V_118 )
return - V_119 ;
* V_120 = V_11 -> V_111 [ V_4 ] . V_112 ;
return 0 ;
}
static int F_54 ( struct V_10 * V_11 , const char * V_14 ,
T_1 * V_116 , T_1 * V_117 )
{
int V_4 , V_61 ;
struct V_1 * V_85 ;
struct V_2 * V_3 = NULL ;
bool V_118 = false ;
V_3 = V_11 -> V_87 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_88 ) {
V_85 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_85 -> V_115 )
return - V_119 ;
V_61 = 0 ;
while ( V_85 -> V_115 [ V_61 ] . V_116 != V_85 -> V_115 [ V_61 ] . V_117 ) {
if ( V_14 == V_85 -> V_115 [ V_61 ] . V_14 ||
! strcmp ( V_14 , V_85 -> V_115 [ V_61 ] . V_14 ) ) {
V_118 = true ;
break;
}
V_61 ++ ;
}
if ( V_118 )
break;
}
if ( ! V_118 )
return - V_119 ;
* V_116 = V_85 -> V_115 [ V_61 ] . V_116 ;
* V_117 = V_85 -> V_115 [ V_61 ] . V_117 ;
return 0 ;
}
static void T_4 F_55 ( struct V_10 * V_11 )
{
struct V_1 * V_85 = NULL ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( ! V_11 )
return;
V_11 -> V_20 |= V_103 ;
V_3 = V_11 -> V_87 . V_9 ;
while ( V_4 < V_11 -> V_88 ) {
V_85 = F_1 ( & V_3 , & V_4 ) ;
if ( V_85 -> V_121 & V_122 ) {
V_11 -> V_123 = V_85 ;
V_11 -> V_20 &= ~ V_103 ;
break;
}
}
return;
}
static struct V_1 * F_56 ( struct V_10 * V_11 )
{
if ( ! V_11 || V_11 -> V_20 & V_103 || V_11 -> V_88 == 0 )
return NULL ;
return V_11 -> V_123 ;
}
static struct V_113 * T_4 F_57 ( struct V_10 * V_11 )
{
struct V_1 * V_85 ;
struct V_113 * V_114 ;
int V_118 = 0 , V_4 = 0 ;
V_85 = F_56 ( V_11 ) ;
if ( ! V_85 || ! V_85 -> V_115 )
return NULL ;
do {
V_114 = & V_85 -> V_115 [ V_4 ++ ] ;
if ( V_114 -> V_66 & V_124 )
V_118 = 1 ;
} while ( ! V_118 && V_114 -> V_116 != V_114 -> V_117 );
return ( V_118 ) ? V_114 : NULL ;
}
static void F_58 ( struct V_10 * V_11 )
{
T_2 V_29 , V_125 ;
T_1 V_22 ;
bool V_126 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
if ( V_11 -> V_66 & V_127 )
F_38 ( V_11 ) ;
F_13 ( V_11 ) ;
if ( V_11 -> V_66 & V_127 )
F_40 ( V_11 ) ;
V_22 = V_11 -> V_16 ;
V_125 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_125 & V_32 ) {
V_126 = ( ( V_11 -> V_81 &&
V_11 -> V_81 -> V_66 & V_128 ) ||
( V_11 -> V_80 && V_11 -> V_80 -> V_81 &&
V_11 -> V_80 -> V_81 -> V_66 & V_128 ) ) ;
if ( V_126 && ! ( V_11 -> V_12 -> V_13 -> V_72 &
( V_129 | V_73 ) ) )
V_29 = V_130 ;
else
V_29 = ( V_11 -> V_66 & V_131 ) ?
V_132 : V_78 ;
F_10 ( V_11 , V_29 , & V_22 ) ;
}
if ( V_125 & V_26 ) {
if ( V_11 -> V_66 & V_133 ) {
V_29 = V_132 ;
} else {
if ( V_125 & V_71 )
F_21 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_74 )
V_29 = V_76 ;
else
V_29 = V_78 ;
}
F_8 ( V_11 , V_29 , & V_22 ) ;
}
if ( ( V_11 -> V_66 & V_134 ) &&
( V_125 & V_36 ) )
F_11 ( V_11 , V_11 -> V_12 -> V_13 -> V_33 , & V_22 ) ;
if ( ( V_125 & V_32 ) && ! ( V_11 -> V_66 & V_131 ) )
F_21 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
if ( V_125 & V_55 ) {
V_29 = ( V_11 -> V_66 & V_135 ) ?
0 : 1 ;
F_18 ( V_11 , V_29 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
}
static void F_59 ( struct V_10 * V_11 )
{
T_2 V_29 , V_125 ;
T_1 V_22 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_125 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_125 & V_32 ) {
if ( V_11 -> V_66 & V_131 ||
! ( V_11 -> V_12 -> V_13 -> V_72 &
( V_129 | V_73 ) ) )
V_29 = V_130 ;
else
V_29 = V_78 ;
F_10 ( V_11 , V_29 , & V_22 ) ;
}
if ( V_125 & V_26 ) {
if ( V_11 -> V_66 & V_133 ) {
V_29 = V_130 ;
} else {
if ( V_125 & V_71 )
F_21 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_74 )
V_29 = V_76 ;
else
V_29 = V_78 ;
}
F_8 ( V_11 , V_29 , & V_22 ) ;
}
if ( ( V_125 & V_32 ) && ! ( V_11 -> V_66 & V_131 ) )
F_21 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
static void F_60 ( struct V_10 * V_11 )
{
T_1 V_22 ;
T_2 V_125 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_125 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_125 & V_32 )
F_10 ( V_11 , V_130 , & V_22 ) ;
if ( V_125 & V_26 )
F_8 ( V_11 , V_130 , & V_22 ) ;
if ( V_125 & V_55 )
F_18 ( V_11 , 1 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
static struct V_10 * F_61 ( const char * V_14 )
{
struct V_10 * V_11 , * V_136 ;
V_11 = NULL ;
F_62 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_14 , V_136 -> V_14 ) ) {
V_11 = V_136 ;
break;
}
}
return V_11 ;
}
static int F_63 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_137 ) {
F_17 ( L_17 , V_11 -> V_14 ) ;
return 0 ;
}
V_11 -> V_81 = F_64 ( V_11 -> V_137 ) ;
if ( ! V_11 -> V_81 ) {
F_30 ( L_18 ,
V_11 -> V_14 , V_11 -> V_137 ) ;
return - V_15 ;
}
F_17 ( L_19 ,
V_11 -> V_14 , V_11 -> V_137 ) ;
return 0 ;
}
static int F_65 ( struct V_10 * V_11 , void * V_138 )
{
int V_83 = 0 ;
if ( V_11 -> V_49 != V_139 )
return 0 ;
F_17 ( L_20 , V_11 -> V_14 ) ;
V_83 |= F_27 ( V_11 ) ;
V_83 |= F_32 ( V_11 ) ;
V_83 |= F_33 ( V_11 ) ;
if ( V_140 . V_141 )
V_83 |= V_140 . V_141 ( V_11 ) ;
if ( ! V_83 )
V_11 -> V_49 = V_142 ;
else
F_30 ( L_21 , V_11 -> V_14 ) ;
return V_83 ;
}
static int F_66 ( struct V_10 * V_11 , const char * V_14 ,
struct V_143 * V_144 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_145 ; V_4 ++ ) {
const char * V_146 = V_11 -> V_147 [ V_4 ] . V_14 ;
if ( ! strcmp ( V_146 , V_14 ) ) {
V_144 -> V_148 = V_11 -> V_147 [ V_4 ] . V_148 ;
V_144 -> V_149 = V_11 -> V_147 [ V_4 ] . V_149 ;
F_17 ( L_22 ,
V_11 -> V_14 , V_98 , V_146 , V_144 -> V_148 ,
V_144 -> V_149 ) ;
return 0 ;
}
}
return - V_119 ;
}
static int F_67 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_143 V_144 ;
int V_83 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_140 . V_150 )
return - V_151 ;
V_83 = F_66 ( V_11 , V_14 , & V_144 ) ;
if ( V_83 < 0 )
return V_83 ;
V_83 = V_140 . V_150 ( V_11 , & V_144 ) ;
return V_83 ;
}
static int F_68 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_143 V_144 ;
int V_83 = - V_15 ;
int V_152 = 0 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_140 . V_153 )
return - V_151 ;
V_83 = F_66 ( V_11 , V_14 , & V_144 ) ;
if ( F_69 ( V_83 ) )
return V_83 ;
if ( V_11 -> V_81 ) {
V_152 = F_70 ( V_11 -> V_81 ) ;
V_83 = F_71 ( V_11 -> V_81 , V_11 ) ;
if ( V_83 ) {
F_4 ( 1 , L_23 ,
V_11 -> V_14 , V_11 -> V_81 -> V_14 , V_83 ) ;
return V_83 ;
}
}
F_34 ( V_11 ) ;
if ( V_140 . V_154 )
V_140 . V_154 ( V_11 ) ;
V_83 = V_140 . V_153 ( V_11 , & V_144 ) ;
if ( V_140 . V_155 )
V_140 . V_155 ( V_11 ) ;
F_36 ( V_11 ) ;
if ( V_83 == - V_156 )
F_30 ( L_24 , V_11 -> V_14 ) ;
if ( ! V_83 ) {
if ( V_11 -> V_81 && V_152 )
F_72 ( V_11 -> V_81 ) ;
} else {
if ( V_11 -> V_81 )
F_73 ( V_11 -> V_81 , V_11 ) ;
}
return V_83 ;
}
static int F_74 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_143 V_144 ;
int V_83 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_140 . V_157 )
return - V_151 ;
V_83 = F_66 ( V_11 , V_14 , & V_144 ) ;
if ( V_83 < 0 )
return V_83 ;
return V_140 . V_157 ( V_11 , & V_144 ) ;
}
static bool F_75 ( struct V_10 * V_11 )
{
int V_4 , V_158 = 0 ;
if ( V_11 -> V_145 == 0 )
return false ;
for ( V_4 = 0 ; V_4 < V_11 -> V_145 ; V_4 ++ )
if ( F_74 ( V_11 , V_11 -> V_147 [ V_4 ] . V_14 ) > 0 )
V_158 ++ ;
if ( V_11 -> V_145 == V_158 )
return true ;
return false ;
}
static bool F_76 ( struct V_10 * V_11 )
{
int V_158 = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_145 && V_158 == 0 ; V_4 ++ )
if ( F_74 ( V_11 , V_11 -> V_147 [ V_4 ] . V_14 ) > 0 )
V_158 ++ ;
return ( V_158 ) ? true : false ;
}
static int F_77 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! V_11 -> V_81 || ! V_11 -> V_95 . V_96 . V_97 )
return - V_15 ;
if ( F_76 ( V_11 ) )
return 0 ;
F_17 ( L_25 , V_11 -> V_14 , V_98 ) ;
F_78 ( V_11 -> V_81 -> V_99 ,
V_11 -> V_81 -> V_100 ,
V_11 -> V_81 -> V_101 ,
V_11 -> V_95 . V_96 . V_102 ) ;
V_22 = F_45 ( V_11 ) ;
if ( V_22 )
F_16 ( L_26 ,
V_11 -> V_14 ) ;
return 0 ;
}
static int F_79 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! V_11 -> V_81 || ! V_11 -> V_95 . V_96 . V_97 )
return - V_15 ;
F_17 ( L_25 , V_11 -> V_14 , V_98 ) ;
if ( F_76 ( V_11 ) )
return 0 ;
F_80 ( V_11 -> V_81 -> V_100 , V_11 -> V_81 -> V_101 ,
V_11 -> V_95 . V_96 . V_102 ) ;
V_22 = F_47 ( V_11 ) ;
if ( V_22 )
F_16 ( L_26 ,
V_11 -> V_14 ) ;
return 0 ;
}
static int F_81 ( struct V_10 * V_11 )
{
T_1 V_22 ;
int V_41 = 0 ;
int V_83 = 0 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_38 ) )
return - V_119 ;
if ( V_11 -> V_49 != V_50 ) {
F_16 ( L_27 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_66 & V_127 )
F_38 ( V_11 ) ;
F_17 ( L_28 , V_11 -> V_14 ) ;
V_22 = V_11 -> V_16 ;
V_83 = F_12 ( V_11 , & V_22 ) ;
if ( V_83 )
goto V_159;
F_6 ( V_22 , V_11 ) ;
if ( V_11 -> V_12 -> V_13 -> V_160 )
F_82 ( V_11 -> V_12 -> V_13 -> V_160 ) ;
V_41 = F_13 ( V_11 ) ;
if ( V_41 == V_45 )
F_30 ( L_29 ,
V_11 -> V_14 , V_45 ) ;
else
F_17 ( L_30 , V_11 -> V_14 , V_41 ) ;
V_83 = ( V_41 == V_45 ) ? - V_161 : 0 ;
V_159:
if ( V_11 -> V_66 & V_127 )
F_40 ( V_11 ) ;
return V_83 ;
}
static int F_83 ( struct V_10 * V_11 )
{
int V_4 , V_162 ;
F_17 ( L_31 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_163 ) {
V_162 = V_11 -> V_12 -> V_163 ( V_11 ) ;
} else {
if ( V_11 -> V_145 > 0 ) {
for ( V_4 = 0 ; V_4 < V_11 -> V_145 ; V_4 ++ )
F_67 ( V_11 , V_11 -> V_147 [ V_4 ] . V_14 ) ;
return 0 ;
} else {
V_162 = F_81 ( V_11 ) ;
if ( V_162 == - V_119 )
V_162 = 0 ;
}
}
F_15 ( V_11 ) ;
if ( V_11 -> V_12 -> V_13 ) {
F_3 ( V_11 ) ;
F_58 ( V_11 ) ;
}
return V_162 ;
}
static void F_84 ( void )
{
unsigned long V_66 ;
F_85 ( & V_164 , V_66 ) ;
if ( F_86 () && F_87 () )
F_88 () ;
else if ( F_89 () )
F_90 () ;
F_91 ( & V_164 , V_66 ) ;
}
static int F_92 ( struct V_10 * V_11 )
{
int V_162 ;
int V_152 = 0 ;
F_17 ( L_32 , V_11 -> V_14 ) ;
if ( V_11 -> V_20 & V_165 ) {
if ( V_11 -> V_62 )
F_20 ( V_11 -> V_62 , V_50 ) ;
V_11 -> V_20 &= ~ V_165 ;
return 0 ;
}
if ( V_11 -> V_49 != V_166 &&
V_11 -> V_49 != V_70 &&
V_11 -> V_49 != V_167 ) {
F_4 ( 1 , L_33 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_75 ( V_11 ) )
return 0 ;
if ( V_11 -> V_62 && ( ! V_11 -> V_62 -> V_63 ||
( ( V_11 -> V_49 == V_70 ) &&
V_11 -> V_62 -> V_65 ) ) ) {
F_20 ( V_11 -> V_62 , V_50 ) ;
F_84 () ;
}
F_23 ( V_11 , V_168 ) ;
if ( V_11 -> V_81 ) {
V_152 = F_70 ( V_11 -> V_81 ) &&
! F_93 ( V_11 -> V_81 ) ;
V_162 = F_71 ( V_11 -> V_81 , V_11 ) ;
if ( V_162 ) {
F_4 ( 1 , L_23 ,
V_11 -> V_14 , V_11 -> V_81 -> V_14 , V_162 ) ;
return V_162 ;
}
}
F_34 ( V_11 ) ;
if ( V_140 . V_154 )
V_140 . V_154 ( V_11 ) ;
V_162 = ( V_140 . V_169 ) ? V_140 . V_169 ( V_11 ) :
- V_15 ;
if ( ! V_162 ) {
if ( V_11 -> V_81 && V_152 )
F_72 ( V_11 -> V_81 ) ;
V_11 -> V_49 = V_50 ;
if ( V_11 -> V_12 -> V_13 ) {
if ( ! ( V_11 -> V_20 & V_21 ) )
F_3 ( V_11 ) ;
F_58 ( V_11 ) ;
}
} else {
F_77 ( V_11 ) ;
F_36 ( V_11 ) ;
F_17 ( L_34 ,
V_11 -> V_14 , V_162 ) ;
if ( V_11 -> V_81 )
F_73 ( V_11 -> V_81 , V_11 ) ;
}
return V_162 ;
}
static int F_94 ( struct V_10 * V_11 )
{
F_17 ( L_35 , V_11 -> V_14 ) ;
if ( V_11 -> V_49 != V_50 ) {
F_4 ( 1 , L_36 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_75 ( V_11 ) )
return 0 ;
if ( V_11 -> V_12 -> V_13 )
F_59 ( V_11 ) ;
F_25 ( V_11 , V_168 ) ;
if ( V_140 . V_155 )
V_140 . V_155 ( V_11 ) ;
F_36 ( V_11 ) ;
if ( V_11 -> V_81 )
F_73 ( V_11 -> V_81 , V_11 ) ;
if ( V_11 -> V_62 && V_11 -> V_62 -> V_65 ) {
F_20 ( V_11 -> V_62 , V_70 ) ;
F_84 () ;
}
V_11 -> V_49 = V_70 ;
return 0 ;
}
int F_95 ( struct V_10 * V_11 , T_2 V_52 )
{
T_1 V_22 ;
int V_170 = 0 ;
unsigned long V_66 ;
if ( ! V_11 || V_11 -> V_49 != V_50 )
return - V_15 ;
F_85 ( & V_11 -> V_171 , V_66 ) ;
V_22 = V_11 -> V_16 ;
V_170 = F_18 ( V_11 , V_52 , & V_22 ) ;
if ( ! V_170 )
F_6 ( V_22 , V_11 ) ;
F_91 ( & V_11 -> V_171 , V_66 ) ;
return V_170 ;
}
static int F_96 ( struct V_10 * V_11 )
{
int V_83 , V_4 ;
T_2 V_172 ;
if ( V_11 -> V_49 != V_70 &&
V_11 -> V_49 != V_50 ) {
F_4 ( 1 , L_37 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_75 ( V_11 ) )
return 0 ;
F_17 ( L_38 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_173 ) {
V_172 = V_11 -> V_49 ;
if ( V_11 -> V_49 == V_70 )
F_92 ( V_11 ) ;
V_83 = V_11 -> V_12 -> V_173 ( V_11 ) ;
if ( V_83 ) {
if ( V_172 == V_70 )
F_94 ( V_11 ) ;
return V_83 ;
}
}
if ( V_11 -> V_12 -> V_13 ) {
if ( V_11 -> V_49 == V_70 )
F_92 ( V_11 ) ;
F_60 ( V_11 ) ;
}
if ( V_11 -> V_49 == V_50 ) {
F_25 ( V_11 , V_168 ) ;
if ( V_140 . V_155 )
V_140 . V_155 ( V_11 ) ;
F_36 ( V_11 ) ;
if ( V_11 -> V_81 )
F_73 ( V_11 -> V_81 , V_11 ) ;
}
for ( V_4 = 0 ; V_4 < V_11 -> V_145 ; V_4 ++ )
F_67 ( V_11 , V_11 -> V_147 [ V_4 ] . V_14 ) ;
if ( V_11 -> V_62 )
F_20 ( V_11 -> V_62 , V_167 ) ;
V_11 -> V_49 = V_167 ;
return 0 ;
}
static void T_4 F_97 ( struct V_10 * V_11 , void * V_138 )
{
struct V_113 * V_114 ;
void T_5 * va_start ;
if ( ! V_11 )
return;
F_55 ( V_11 ) ;
if ( V_11 -> V_20 & V_103 )
return;
V_114 = F_57 ( V_11 ) ;
if ( ! V_114 ) {
F_17 ( L_39 ,
V_11 -> V_14 ) ;
return;
}
va_start = F_98 ( V_114 -> V_116 , V_114 -> V_117 - V_114 -> V_116 ) ;
if ( ! va_start ) {
F_99 ( L_40 , V_11 -> V_14 ) ;
return;
}
F_17 ( L_41 ,
V_11 -> V_14 , va_start ) ;
V_11 -> V_174 = va_start ;
}
static int T_4 F_100 ( struct V_10 * V_11 , void * V_138 )
{
int V_162 ;
if ( V_11 -> V_49 != V_139 )
return 0 ;
F_97 ( V_11 , NULL ) ;
V_162 = F_65 ( V_11 , NULL ) ;
if ( F_69 ( V_162 ) ) {
F_4 ( 1 , L_42 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_49 = V_166 ;
return 0 ;
}
static void T_4 F_101 ( struct V_10 * V_11 )
{
struct V_1 * V_85 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( V_11 -> V_49 != V_166 )
return;
V_3 = V_11 -> V_87 . V_9 ;
while ( V_4 < V_11 -> V_88 ) {
V_85 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_85 -> V_80 )
continue;
if ( V_85 -> V_66 & V_93 ) {
} else {
F_35 ( V_85 -> V_80 ) ;
}
}
return;
}
static int T_4 F_102 ( struct V_10 * V_11 )
{
int V_162 ;
if ( V_11 -> V_49 != V_166 )
return - V_15 ;
if ( V_11 -> V_66 & V_175 )
return - V_176 ;
if ( V_11 -> V_145 == 0 ) {
V_162 = F_92 ( V_11 ) ;
if ( V_162 ) {
F_30 ( L_43 ,
V_11 -> V_14 , V_11 -> V_49 ) ;
return - V_15 ;
}
}
if ( ! ( V_11 -> V_66 & V_177 ) )
V_162 = F_83 ( V_11 ) ;
return V_162 ;
}
static void T_4 F_103 ( struct V_10 * V_11 )
{
T_2 V_178 ;
if ( V_11 -> V_145 > 0 )
return;
V_178 = V_11 -> V_179 ;
if ( V_178 == V_180 )
V_178 = V_50 ;
if ( ( V_11 -> V_66 & V_181 ) &&
( V_178 == V_70 ) ) {
V_11 -> V_20 |= V_165 ;
V_178 = V_50 ;
}
if ( V_178 == V_70 )
F_94 ( V_11 ) ;
else if ( V_178 == V_167 )
F_96 ( V_11 ) ;
else if ( V_178 != V_50 )
F_4 ( 1 , L_44 ,
V_11 -> V_14 , V_178 ) ;
return;
}
static int T_4 F_104 ( struct V_10 * V_11 , void * V_138 )
{
if ( V_11 -> V_49 != V_166 )
return 0 ;
F_101 ( V_11 ) ;
if ( ! F_102 ( V_11 ) )
F_103 ( V_11 ) ;
return 0 ;
}
static int T_4 F_105 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_14 || ! V_11 -> V_12 || ! V_11 -> V_12 -> V_14 ||
( V_11 -> V_49 != V_180 ) )
return - V_15 ;
F_17 ( L_45 , V_11 -> V_14 ) ;
if ( F_61 ( V_11 -> V_14 ) )
return - V_182 ;
F_106 ( & V_11 -> V_7 , & V_183 ) ;
F_107 ( & V_11 -> V_184 ) ;
F_107 ( & V_11 -> V_87 ) ;
F_108 ( & V_11 -> V_171 ) ;
V_11 -> V_49 = V_139 ;
if ( ! strcmp ( V_11 -> V_14 , V_185 ) )
V_168 = V_11 ;
return 0 ;
}
static int T_4 F_109 ( struct V_6 * * V_186 ,
struct V_6 * * V_187 )
{
unsigned int V_188 ;
if ( ( V_189 + V_190 ) <= V_191 ) {
* V_186 = & V_192 [ V_189 ++ ] ;
* V_187 = & V_192 [ V_189 ++ ] ;
return 0 ;
}
V_188 = sizeof( struct V_6 ) * V_190 ;
* V_187 = NULL ;
* V_186 = F_110 ( V_188 ) ;
memset ( * V_186 , 0 , V_188 ) ;
* V_187 = ( void * ) ( * V_186 ) + sizeof( struct V_6 ) ;
V_193 ++ ;
F_17 ( L_46 ,
V_193 * V_190 ) ;
return 0 ;
}
static int T_4 F_111 ( struct V_1 * V_5 )
{
struct V_6 * V_186 , * V_187 ;
F_17 ( L_47 , V_5 -> V_194 -> V_14 ,
V_5 -> V_195 -> V_14 ) ;
F_109 ( & V_186 , & V_187 ) ;
V_186 -> V_8 = V_5 ;
F_107 ( & V_186 -> V_7 ) ;
F_112 ( & V_186 -> V_7 , & V_5 -> V_194 -> V_184 ) ;
V_5 -> V_194 -> V_196 ++ ;
V_187 -> V_8 = V_5 ;
F_107 ( & V_187 -> V_7 ) ;
F_112 ( & V_187 -> V_7 , & V_5 -> V_195 -> V_87 ) ;
V_5 -> V_195 -> V_88 ++ ;
return 0 ;
}
static int T_4 F_113 ( struct V_1 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_194 || ! V_5 -> V_195 || ! V_5 -> V_121 )
return - V_15 ;
if ( V_5 -> V_20 & V_197 )
return - V_182 ;
F_17 ( L_48 ,
V_5 -> V_194 -> V_14 , V_5 -> V_195 -> V_14 ) ;
if ( V_5 -> V_194 -> V_49 != V_139 )
F_105 ( V_5 -> V_194 ) ;
if ( V_5 -> V_195 -> V_49 != V_139 )
F_105 ( V_5 -> V_195 ) ;
F_111 ( V_5 ) ;
V_5 -> V_20 |= V_197 ;
return 0 ;
}
static int T_4 F_114 ( struct V_1 * * V_198 )
{
unsigned int V_4 = 0 ;
unsigned int V_188 ;
if ( V_192 ) {
F_4 ( 1 , L_49 ) ;
return - V_182 ;
}
if ( V_191 == 0 )
while ( V_198 [ V_4 ++ ] )
V_191 += V_190 ;
V_188 = sizeof( struct V_6 ) * V_191 ;
F_17 ( L_50 ,
V_98 , V_188 , V_191 ) ;
V_192 = F_110 ( V_188 ) ;
memset ( V_192 , 0 , V_188 ) ;
return 0 ;
}
static int F_115 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_104 )
return 0 ;
if ( ! F_56 ( V_11 ) )
return 0 ;
return F_116 ( V_11 -> V_95 . V_199 . V_200 ,
V_11 -> V_95 . V_199 . V_201 ,
V_11 -> V_95 . V_199 . V_202 ) ;
}
static int F_117 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_104 || ! V_11 -> V_81 )
return 0 ;
if ( ! F_56 ( V_11 ) )
return 0 ;
return F_118 ( V_11 -> V_81 -> V_99 ,
V_11 -> V_81 -> V_100 ,
V_11 -> V_81 -> V_101 ,
V_11 -> V_95 . V_96 . V_102 ) ;
}
static int F_119 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_81 )
return - V_15 ;
if ( V_11 -> V_66 & V_104 )
return 0 ;
if ( ! F_56 ( V_11 ) )
return 0 ;
return F_120 ( V_11 -> V_81 -> V_100 ,
V_11 -> V_81 -> V_101 ,
V_11 -> V_95 . V_96 . V_102 ) ;
}
static int F_121 ( struct V_10 * V_11 ,
struct V_143 * V_144 )
{
return F_122 ( V_11 -> V_95 . V_199 . V_200 ,
V_144 -> V_148 ) ;
}
static int F_123 ( struct V_10 * V_11 ,
struct V_143 * V_144 )
{
return F_124 ( V_11 -> V_95 . V_199 . V_200 ,
V_144 -> V_148 ,
V_144 -> V_149 ) ;
}
static int F_125 ( struct V_10 * V_11 ,
struct V_143 * V_144 )
{
return F_126 ( V_11 -> V_95 . V_199 . V_200 ,
V_144 -> V_149 ) ;
}
static int F_127 ( struct V_10 * V_11 ,
struct V_143 * V_144 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
return F_128 ( V_144 -> V_148 ,
V_11 -> V_81 -> V_203 . V_204 -> V_99 ,
V_11 -> V_81 -> V_203 . V_204 -> V_205 ,
V_11 -> V_95 . V_96 . V_206 ) ;
}
static int F_129 ( struct V_10 * V_11 ,
struct V_143 * V_144 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
if ( V_144 -> V_149 )
F_99 ( L_51 ,
V_11 -> V_14 , V_144 -> V_14 ) ;
return F_130 ( V_144 -> V_148 ,
V_11 -> V_81 -> V_203 . V_204 -> V_99 ,
V_11 -> V_81 -> V_203 . V_204 -> V_205 ,
V_11 -> V_95 . V_96 . V_206 ) ;
}
static int F_131 ( struct V_10 * V_11 ,
struct V_143 * V_144 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
return F_132 ( V_144 -> V_148 ,
V_11 -> V_81 -> V_203 . V_204 -> V_99 ,
V_11 -> V_81 -> V_203 . V_204 -> V_205 ,
V_11 -> V_95 . V_96 . V_206 ) ;
}
static int F_133 ( struct V_10 * V_11 ,
struct V_143 * V_144 )
{
return F_134 ( V_144 -> V_148 ,
V_11 -> V_81 -> V_203 . V_204 -> V_205 ,
V_11 -> V_95 . V_96 . V_206 ) ;
}
static int F_135 ( struct V_10 * V_11 ,
struct V_143 * V_144 )
{
if ( V_144 -> V_149 )
F_99 ( L_51 ,
V_11 -> V_14 , V_144 -> V_14 ) ;
return F_136 ( V_144 -> V_148 ,
V_11 -> V_81 -> V_203 . V_204 -> V_205 ,
V_11 -> V_95 . V_96 . V_206 ,
V_11 -> V_95 . V_96 . V_207 ) ;
}
static int F_137 ( struct V_10 * V_11 ,
struct V_143 * V_144 )
{
return F_138 ( V_144 -> V_148 ,
V_11 -> V_81 -> V_203 . V_204 -> V_205 ,
V_11 -> V_95 . V_96 . V_206 ) ;
}
T_1 F_5 ( struct V_10 * V_11 , T_3 V_208 )
{
if ( V_11 -> V_66 & V_209 )
return F_139 ( V_11 -> V_174 + V_208 ) ;
else
return F_140 ( V_11 -> V_174 + V_208 ) ;
}
void F_7 ( T_1 V_22 , struct V_10 * V_11 , T_3 V_208 )
{
if ( V_11 -> V_66 & V_209 )
F_141 ( V_22 , V_11 -> V_174 + V_208 ) ;
else
F_142 ( V_22 , V_11 -> V_174 + V_208 ) ;
}
int F_143 ( struct V_10 * V_11 )
{
T_1 V_22 ;
int V_83 ;
if ( ! V_11 || ! ( V_11 -> V_16 ) )
return - V_15 ;
V_22 = V_11 -> V_16 ;
V_83 = F_12 ( V_11 , & V_22 ) ;
if ( V_83 )
goto error;
F_6 ( V_22 , V_11 ) ;
error:
return V_83 ;
}
int F_144 ( struct V_10 * V_11 , T_2 V_29 )
{
T_1 V_22 ;
int V_170 = 0 ;
if ( ! V_11 )
return - V_15 ;
V_22 = V_11 -> V_16 ;
V_170 = F_10 ( V_11 , V_29 , & V_22 ) ;
if ( ! V_170 )
F_6 ( V_22 , V_11 ) ;
return V_170 ;
}
struct V_10 * F_145 ( const char * V_14 )
{
struct V_10 * V_11 ;
if ( ! V_14 )
return NULL ;
V_11 = F_61 ( V_14 ) ;
return V_11 ;
}
int F_146 ( int (* F_147)( struct V_10 * V_11 , void * V_138 ) ,
void * V_138 )
{
struct V_10 * V_136 ;
int V_83 = 0 ;
if ( ! F_147 )
return - V_15 ;
F_62 (temp_oh, &omap_hwmod_list, node) {
V_83 = (* F_147)( V_136 , V_138 ) ;
if ( V_83 )
break;
}
return V_83 ;
}
int T_4 F_148 ( struct V_1 * * V_198 )
{
int V_162 , V_4 ;
if ( ! V_210 )
return - V_15 ;
if ( ! V_198 )
return 0 ;
if ( ! V_192 ) {
if ( F_114 ( V_198 ) ) {
F_99 ( L_52 ) ;
return - V_211 ;
}
}
V_4 = 0 ;
do {
V_162 = F_113 ( V_198 [ V_4 ] ) ;
F_4 ( V_162 && V_162 != - V_182 ,
L_53 ,
V_198 [ V_4 ] -> V_194 -> V_14 , V_198 [ V_4 ] -> V_195 -> V_14 , V_162 ) ;
} while ( V_198 [ ++ V_4 ] );
return 0 ;
}
static void T_4 F_149 ( struct V_10 * V_11 )
{
if ( ! V_168 || V_168 -> V_49 == V_180 )
F_99 ( L_54 ,
V_98 , V_185 ) ;
else if ( V_168 -> V_49 == V_139 && V_11 != V_168 )
F_150 ( V_185 ) ;
}
int T_4 F_150 ( const char * V_212 )
{
struct V_10 * V_11 ;
F_17 ( L_25 , V_212 , V_98 ) ;
V_11 = F_61 ( V_212 ) ;
if ( ! V_11 ) {
F_4 ( 1 , L_55 , V_212 ) ;
return - V_15 ;
}
F_149 ( V_11 ) ;
F_100 ( V_11 , NULL ) ;
F_104 ( V_11 , NULL ) ;
return 0 ;
}
static int T_4 F_151 ( void )
{
F_149 ( NULL ) ;
F_146 ( F_100 , NULL ) ;
F_146 ( F_104 , NULL ) ;
return 0 ;
}
int F_152 ( struct V_10 * V_11 )
{
int V_162 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_85 ( & V_11 -> V_171 , V_66 ) ;
V_162 = F_92 ( V_11 ) ;
F_91 ( & V_11 -> V_171 , V_66 ) ;
return V_162 ;
}
int F_153 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_85 ( & V_11 -> V_171 , V_66 ) ;
F_94 ( V_11 ) ;
F_91 ( & V_11 -> V_171 , V_66 ) ;
return 0 ;
}
int F_154 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_85 ( & V_11 -> V_171 , V_66 ) ;
F_96 ( V_11 ) ;
F_91 ( & V_11 -> V_171 , V_66 ) ;
return 0 ;
}
int F_155 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
F_85 ( & V_11 -> V_171 , V_66 ) ;
F_34 ( V_11 ) ;
F_91 ( & V_11 -> V_171 , V_66 ) ;
return 0 ;
}
int F_156 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
F_85 ( & V_11 -> V_171 , V_66 ) ;
F_36 ( V_11 ) ;
F_91 ( & V_11 -> V_171 , V_66 ) ;
return 0 ;
}
void F_157 ( struct V_10 * V_11 )
{
F_158 ( ! V_11 ) ;
if ( ! V_11 -> V_12 -> V_13 || ! V_11 -> V_12 -> V_13 -> V_18 ) {
F_4 ( 1 , L_56 ,
V_11 -> V_14 ) ;
return;
}
F_5 ( V_11 , V_11 -> V_12 -> V_13 -> V_17 ) ;
}
int F_159 ( struct V_10 * V_11 )
{
int V_162 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_85 ( & V_11 -> V_171 , V_66 ) ;
V_162 = F_83 ( V_11 ) ;
F_91 ( & V_11 -> V_171 , V_66 ) ;
return V_162 ;
}
int F_160 ( struct V_10 * V_11 )
{
struct V_1 * V_85 ;
struct V_2 * V_3 ;
int V_83 ;
int V_4 = 0 ;
V_83 = F_49 ( V_11 ) + F_50 ( V_11 ) ;
V_3 = V_11 -> V_87 . V_9 ;
while ( V_4 < V_11 -> V_88 ) {
V_85 = F_1 ( & V_3 , & V_4 ) ;
V_83 += F_51 ( V_85 ) ;
}
return V_83 ;
}
int F_161 ( struct V_10 * V_11 , struct V_213 * V_214 )
{
struct V_1 * V_85 ;
struct V_2 * V_3 ;
int V_4 , V_61 , V_215 , V_216 , V_217 ;
int V_162 = 0 ;
V_215 = F_49 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_215 ; V_4 ++ ) {
( V_214 + V_162 ) -> V_14 = ( V_11 -> V_107 + V_4 ) -> V_14 ;
( V_214 + V_162 ) -> V_218 = ( V_11 -> V_107 + V_4 ) -> V_108 ;
( V_214 + V_162 ) -> V_219 = ( V_11 -> V_107 + V_4 ) -> V_108 ;
( V_214 + V_162 ) -> V_66 = V_220 ;
V_162 ++ ;
}
V_216 = F_50 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_216 ; V_4 ++ ) {
( V_214 + V_162 ) -> V_14 = ( V_11 -> V_111 + V_4 ) -> V_14 ;
( V_214 + V_162 ) -> V_218 = ( V_11 -> V_111 + V_4 ) -> V_112 ;
( V_214 + V_162 ) -> V_219 = ( V_11 -> V_111 + V_4 ) -> V_112 ;
( V_214 + V_162 ) -> V_66 = V_221 ;
V_162 ++ ;
}
V_3 = V_11 -> V_87 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_88 ) {
V_85 = F_1 ( & V_3 , & V_4 ) ;
V_217 = F_51 ( V_85 ) ;
for ( V_61 = 0 ; V_61 < V_217 ; V_61 ++ ) {
( V_214 + V_162 ) -> V_14 = ( V_85 -> V_115 + V_61 ) -> V_14 ;
( V_214 + V_162 ) -> V_218 = ( V_85 -> V_115 + V_61 ) -> V_116 ;
( V_214 + V_162 ) -> V_219 = ( V_85 -> V_115 + V_61 ) -> V_117 ;
( V_214 + V_162 ) -> V_66 = V_222 ;
V_162 ++ ;
}
}
return V_162 ;
}
int F_162 ( struct V_10 * V_11 , struct V_213 * V_214 )
{
int V_4 , V_216 ;
int V_162 = 0 ;
V_216 = F_50 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_216 ; V_4 ++ ) {
( V_214 + V_162 ) -> V_14 = ( V_11 -> V_111 + V_4 ) -> V_14 ;
( V_214 + V_162 ) -> V_218 = ( V_11 -> V_111 + V_4 ) -> V_112 ;
( V_214 + V_162 ) -> V_219 = ( V_11 -> V_111 + V_4 ) -> V_112 ;
( V_214 + V_162 ) -> V_66 = V_221 ;
V_162 ++ ;
}
return V_162 ;
}
int F_163 ( struct V_10 * V_11 , unsigned int type ,
const char * V_14 , struct V_213 * V_223 )
{
int V_162 ;
unsigned int V_108 , V_120 ;
T_1 V_116 , V_117 ;
if ( ! V_11 || ! V_223 )
return - V_15 ;
if ( type == V_220 ) {
V_162 = F_52 ( V_11 , V_14 , & V_108 ) ;
if ( V_162 )
return V_162 ;
V_223 -> V_218 = V_108 ;
V_223 -> V_219 = V_108 ;
} else if ( type == V_221 ) {
V_162 = F_53 ( V_11 , V_14 , & V_120 ) ;
if ( V_162 )
return V_162 ;
V_223 -> V_218 = V_120 ;
V_223 -> V_219 = V_120 ;
} else if ( type == V_222 ) {
V_162 = F_54 ( V_11 , V_14 , & V_116 , & V_117 ) ;
if ( V_162 )
return V_162 ;
V_223 -> V_218 = V_116 ;
V_223 -> V_219 = V_117 ;
} else {
return - V_15 ;
}
V_223 -> V_66 = type ;
V_223 -> V_14 = V_14 ;
return 0 ;
}
struct V_224 * F_164 ( struct V_10 * V_11 )
{
struct V_86 * V_41 ;
struct V_1 * V_5 ;
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_80 ) {
V_41 = V_11 -> V_80 ;
} else {
V_5 = F_56 ( V_11 ) ;
if ( ! V_5 )
return NULL ;
V_41 = V_5 -> V_80 ;
}
if ( ! V_41 -> V_81 )
return NULL ;
return V_41 -> V_81 -> V_203 . V_204 ;
}
void T_5 * F_165 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_20 & V_103 )
return NULL ;
if ( V_11 -> V_49 == V_180 )
return NULL ;
return V_11 -> V_174 ;
}
int F_166 ( struct V_10 * V_11 ,
struct V_10 * V_79 )
{
return F_23 ( V_11 , V_79 ) ;
}
int F_167 ( struct V_10 * V_11 ,
struct V_10 * V_79 )
{
return F_25 ( V_11 , V_79 ) ;
}
int F_168 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
T_1 V_22 ;
F_85 ( & V_11 -> V_171 , V_66 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ) {
V_22 = V_11 -> V_16 ;
F_21 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_19 ( V_11 , true ) ;
F_91 ( & V_11 -> V_171 , V_66 ) ;
return 0 ;
}
int F_169 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
T_1 V_22 ;
F_85 ( & V_11 -> V_171 , V_66 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ) {
V_22 = V_11 -> V_16 ;
F_22 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_19 ( V_11 , false ) ;
F_91 ( & V_11 -> V_171 , V_66 ) ;
return 0 ;
}
int F_170 ( struct V_10 * V_11 , const char * V_14 )
{
int V_83 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_85 ( & V_11 -> V_171 , V_66 ) ;
V_83 = F_67 ( V_11 , V_14 ) ;
F_91 ( & V_11 -> V_171 , V_66 ) ;
return V_83 ;
}
int F_171 ( struct V_10 * V_11 , const char * V_14 )
{
int V_83 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_85 ( & V_11 -> V_171 , V_66 ) ;
V_83 = F_68 ( V_11 , V_14 ) ;
F_91 ( & V_11 -> V_171 , V_66 ) ;
return V_83 ;
}
int F_172 ( struct V_10 * V_11 , const char * V_14 )
{
int V_83 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_85 ( & V_11 -> V_171 , V_66 ) ;
V_83 = F_74 ( V_11 , V_14 ) ;
F_91 ( & V_11 -> V_171 , V_66 ) ;
return V_83 ;
}
int F_173 ( const char * V_225 ,
int (* F_147)( struct V_10 * V_11 ,
void * V_121 ) ,
void * V_121 )
{
struct V_10 * V_136 ;
int V_83 = 0 ;
if ( ! V_225 || ! F_147 )
return - V_15 ;
F_17 ( L_57 ,
V_98 , V_225 ) ;
F_62 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_136 -> V_12 -> V_14 , V_225 ) ) {
F_17 ( L_58 ,
V_98 , V_136 -> V_14 ) ;
V_83 = (* F_147)( V_136 , V_121 ) ;
if ( V_83 )
break;
}
}
if ( V_83 )
F_17 ( L_59 ,
V_98 , V_83 ) ;
return V_83 ;
}
int F_174 ( struct V_10 * V_11 , T_2 V_226 )
{
int V_83 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
if ( V_226 != V_167 &&
V_226 != V_50 &&
V_226 != V_70 )
return - V_15 ;
F_85 ( & V_11 -> V_171 , V_66 ) ;
if ( V_11 -> V_49 != V_139 ) {
V_83 = - V_15 ;
goto V_227;
}
V_11 -> V_179 = V_226 ;
V_83 = 0 ;
V_227:
F_91 ( & V_11 -> V_171 , V_66 ) ;
return V_83 ;
}
int F_175 ( struct V_10 * V_11 )
{
struct V_224 * V_203 ;
int V_83 = 0 ;
V_203 = F_164 ( V_11 ) ;
if ( V_203 )
V_83 = F_176 ( V_203 ) ;
return V_83 ;
}
int F_177 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_49 != V_139 ) {
F_99 ( L_60 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_66 |= V_177 ;
return 0 ;
}
int F_178 ( struct V_10 * V_11 , int V_228 , int V_229 )
{
int V_230 ;
F_179 () ;
if ( ! V_11 || ! V_11 -> V_62 || ! V_11 -> V_107 || V_228 < 0 ||
V_228 >= V_11 -> V_62 -> V_64 )
return - V_15 ;
for ( V_230 = 0 ; V_11 -> V_107 [ V_230 ] . V_108 >= 0 ; V_230 ++ )
;
if ( V_229 >= V_230 )
return - V_15 ;
if ( ! V_11 -> V_62 -> V_231 ) {
V_11 -> V_62 -> V_231 = F_180 ( sizeof( int ) * V_11 -> V_62 -> V_64 ,
V_232 ) ;
if ( ! V_11 -> V_62 -> V_231 )
return - V_211 ;
}
V_11 -> V_62 -> V_231 [ V_228 ] = V_229 ;
return 0 ;
}
void T_4 F_181 ( void )
{
if ( F_182 () || F_86 () ) {
V_140 . V_169 = F_115 ;
V_140 . V_150 = F_121 ;
V_140 . V_153 = F_123 ;
V_140 . V_157 = F_125 ;
} else if ( F_89 () || F_183 () ) {
V_140 . V_154 = F_41 ;
V_140 . V_155 = F_77 ;
V_140 . V_169 = F_117 ;
V_140 . V_150 = F_127 ;
V_140 . V_153 = F_129 ;
V_140 . V_157 = F_131 ;
V_140 . V_141 = F_63 ;
} else if ( F_184 () ) {
V_140 . V_154 = F_43 ;
V_140 . V_155 = F_79 ;
V_140 . V_169 = F_119 ;
V_140 . V_150 = F_133 ;
V_140 . V_153 = F_135 ;
V_140 . V_157 = F_137 ;
V_140 . V_141 = F_63 ;
} else {
F_4 ( 1 , L_61 ) ;
}
V_210 = true ;
}
const char * F_185 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
return V_11 -> V_84 ;
}
