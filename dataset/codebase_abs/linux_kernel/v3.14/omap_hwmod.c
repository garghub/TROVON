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
F_35 ( L_7 ,
V_11 -> V_14 , V_11 -> V_88 ) ;
return - V_15 ;
}
F_36 ( V_11 -> V_82 ) ;
if ( ! F_24 ( V_11 ) )
F_18 ( L_8 ,
V_11 -> V_14 , V_11 -> V_88 ) ;
return V_87 ;
}
static int F_37 ( struct V_10 * V_11 )
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
F_35 ( L_9 ,
V_11 -> V_14 , V_89 -> V_80 ) ;
V_87 = - V_15 ;
continue;
}
V_89 -> V_82 = V_41 ;
F_36 ( V_89 -> V_82 ) ;
}
return V_87 ;
}
static int F_38 ( struct V_10 * V_11 )
{
struct V_92 * V_93 ;
struct V_80 * V_41 ;
int V_4 ;
int V_87 = 0 ;
for ( V_4 = V_11 -> V_94 , V_93 = V_11 -> V_95 ; V_4 > 0 ; V_4 -- , V_93 ++ ) {
V_41 = F_33 ( NULL , V_93 -> V_80 ) ;
if ( F_34 ( V_41 ) ) {
F_35 ( L_10 ,
V_11 -> V_14 , V_93 -> V_80 ) ;
V_87 = - V_15 ;
continue;
}
V_93 -> V_82 = V_41 ;
F_36 ( V_93 -> V_82 ) ;
}
return V_87 ;
}
static int F_39 ( struct V_10 * V_11 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_18 ( L_11 , V_11 -> V_14 ) ;
if ( V_11 -> V_82 )
F_40 ( V_11 -> V_82 ) ;
V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
if ( V_89 -> V_82 && ( V_89 -> V_66 & V_96 ) )
F_40 ( V_89 -> V_82 ) ;
}
return 0 ;
}
static int F_41 ( struct V_10 * V_11 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_18 ( L_12 , V_11 -> V_14 ) ;
if ( V_11 -> V_82 )
F_42 ( V_11 -> V_82 ) ;
V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
if ( V_89 -> V_82 && ( V_89 -> V_66 & V_96 ) )
F_42 ( V_89 -> V_82 ) ;
}
return 0 ;
}
static void F_43 ( struct V_10 * V_11 )
{
struct V_92 * V_93 ;
int V_4 ;
F_18 ( L_13 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_94 , V_93 = V_11 -> V_95 ; V_4 > 0 ; V_4 -- , V_93 ++ )
if ( V_93 -> V_82 ) {
F_18 ( L_14 , V_93 -> V_97 ,
F_44 ( V_93 -> V_82 ) ) ;
F_40 ( V_93 -> V_82 ) ;
}
}
static void F_45 ( struct V_10 * V_11 )
{
struct V_92 * V_93 ;
int V_4 ;
F_18 ( L_15 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_94 , V_93 = V_11 -> V_95 ; V_4 > 0 ; V_4 -- , V_93 ++ )
if ( V_93 -> V_82 ) {
F_18 ( L_16 , V_93 -> V_97 ,
F_44 ( V_93 -> V_82 ) ) ;
F_42 ( V_93 -> V_82 ) ;
}
}
static void F_46 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_81 || ! V_11 -> V_98 . V_99 . V_100 )
return;
F_18 ( L_17 ,
V_11 -> V_14 , V_101 , V_11 -> V_98 . V_99 . V_100 ) ;
F_47 ( V_11 -> V_98 . V_99 . V_100 ,
V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_81 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static void F_48 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_81 || ! V_11 -> V_98 . V_99 . V_100 )
return;
F_18 ( L_17 ,
V_11 -> V_14 , V_101 , V_11 -> V_98 . V_99 . V_100 ) ;
F_49 ( V_11 -> V_98 . V_99 . V_100 , V_11 -> V_81 -> V_103 ,
V_11 -> V_81 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_50 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_106 || ! V_11 -> V_81 )
return 0 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
return F_51 ( V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_81 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_52 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_106 )
return 0 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
return F_53 ( V_11 -> V_81 -> V_103 ,
V_11 -> V_81 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_54 ( struct V_10 * V_11 )
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
static int F_55 ( struct V_10 * V_11 )
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
static int F_56 ( struct V_1 * V_89 )
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
static int F_57 ( struct V_10 * V_11 , const char * V_14 ,
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
static int F_58 ( struct V_10 * V_11 , const char * V_14 ,
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
static int F_59 ( struct V_10 * V_11 , const char * V_14 ,
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
static void T_4 F_60 ( struct V_10 * V_11 )
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
static struct V_1 * F_61 ( struct V_10 * V_11 )
{
if ( ! V_11 || V_11 -> V_20 & V_106 || V_11 -> V_91 == 0 )
return NULL ;
return V_11 -> V_126 ;
}
static struct V_116 * T_4 F_62 ( struct V_10 * V_11 )
{
struct V_1 * V_89 ;
struct V_116 * V_117 ;
int V_121 = 0 , V_4 = 0 ;
V_89 = F_61 ( V_11 ) ;
if ( ! V_89 || ! V_89 -> V_118 )
return NULL ;
do {
V_117 = & V_89 -> V_118 [ V_4 ++ ] ;
if ( V_117 -> V_66 & V_127 )
V_121 = 1 ;
} while ( ! V_121 && V_117 -> V_119 != V_117 -> V_120 );
return ( V_121 ) ? V_117 : NULL ;
}
static void F_63 ( struct V_10 * V_11 )
{
T_2 V_29 , V_128 ;
T_1 V_22 ;
bool V_129 ;
struct V_78 * V_81 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
if ( V_11 -> V_66 & V_130 )
F_43 ( V_11 ) ;
F_14 ( V_11 ) ;
if ( V_11 -> V_66 & V_130 )
F_45 ( V_11 ) ;
V_22 = V_11 -> V_16 ;
V_128 = V_11 -> V_12 -> V_13 -> V_18 ;
V_81 = F_24 ( V_11 ) ;
if ( V_128 & V_32 ) {
if ( V_11 -> V_66 & V_131 ||
V_11 -> V_66 & V_132 ) {
V_29 = V_133 ;
} else {
if ( V_128 & V_71 )
F_22 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_73 )
V_29 = V_76 ;
else
V_29 = V_77 ;
}
V_129 = ( V_81 && V_81 -> V_66 & V_134 ) ;
if ( V_129 && ! ( V_11 -> V_12 -> V_13 -> V_72 &
( V_135 | V_73 ) ) )
V_29 = V_136 ;
F_10 ( V_11 , V_29 , & V_22 ) ;
}
if ( V_128 & V_26 ) {
if ( V_11 -> V_66 & V_137 ) {
V_29 = V_136 ;
} else if ( V_11 -> V_66 & V_138 ) {
V_29 = V_133 ;
} else {
if ( V_128 & V_71 )
F_22 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_74 )
V_29 = V_76 ;
else
V_29 = V_77 ;
}
F_8 ( V_11 , V_29 , & V_22 ) ;
}
if ( ( V_11 -> V_66 & V_139 ) &&
( V_128 & V_36 ) )
F_11 ( V_11 , V_11 -> V_12 -> V_13 -> V_33 , & V_22 ) ;
if ( V_11 -> V_16 != V_22 )
F_6 ( V_22 , V_11 ) ;
if ( V_128 & V_55 ) {
V_29 = ( V_11 -> V_66 & V_140 ) ?
0 : 1 ;
F_19 ( V_11 , V_29 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
}
static void F_64 ( struct V_10 * V_11 )
{
T_2 V_29 , V_128 ;
T_1 V_22 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_128 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_128 & V_32 ) {
if ( V_11 -> V_66 & V_131 ) {
V_29 = V_136 ;
} else {
if ( V_128 & V_71 )
F_22 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_72 & V_73 )
V_29 = V_76 ;
else
V_29 = V_77 ;
}
F_10 ( V_11 , V_29 , & V_22 ) ;
}
if ( V_128 & V_26 ) {
if ( ( V_11 -> V_66 & V_138 ) ||
( V_11 -> V_66 & V_137 ) ) {
V_29 = V_136 ;
} else {
if ( V_128 & V_71 )
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
static void F_65 ( struct V_10 * V_11 )
{
T_1 V_22 ;
T_2 V_128 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_128 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_128 & V_32 )
F_10 ( V_11 , V_136 , & V_22 ) ;
if ( V_128 & V_26 )
F_8 ( V_11 , V_136 , & V_22 ) ;
if ( V_128 & V_55 )
F_19 ( V_11 , 1 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
static struct V_10 * F_66 ( const char * V_14 )
{
struct V_10 * V_11 , * V_141 ;
V_11 = NULL ;
F_67 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_14 , V_141 -> V_14 ) ) {
V_11 = V_141 ;
break;
}
}
return V_11 ;
}
static int F_68 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_142 ) {
F_18 ( L_18 , V_11 -> V_14 ) ;
return 0 ;
}
V_11 -> V_81 = F_69 ( V_11 -> V_142 ) ;
if ( ! V_11 -> V_81 ) {
F_35 ( L_19 ,
V_11 -> V_14 , V_11 -> V_142 ) ;
return 0 ;
}
F_18 ( L_20 ,
V_11 -> V_14 , V_11 -> V_142 ) ;
return 0 ;
}
static int F_70 ( struct V_10 * V_11 , void * V_143 )
{
int V_87 = 0 ;
if ( V_11 -> V_49 != V_144 )
return 0 ;
F_18 ( L_21 , V_11 -> V_14 ) ;
if ( V_145 . V_85 )
V_87 |= V_145 . V_85 ( V_11 ) ;
V_87 |= F_32 ( V_11 ) ;
V_87 |= F_37 ( V_11 ) ;
V_87 |= F_38 ( V_11 ) ;
if ( ! V_87 )
V_11 -> V_49 = V_146 ;
else
F_35 ( L_22 , V_11 -> V_14 ) ;
return V_87 ;
}
static int F_71 ( struct V_10 * V_11 , const char * V_14 ,
struct V_147 * V_148 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_149 ; V_4 ++ ) {
const char * V_150 = V_11 -> V_151 [ V_4 ] . V_14 ;
if ( ! strcmp ( V_150 , V_14 ) ) {
V_148 -> V_152 = V_11 -> V_151 [ V_4 ] . V_152 ;
V_148 -> V_153 = V_11 -> V_151 [ V_4 ] . V_153 ;
F_18 ( L_23 ,
V_11 -> V_14 , V_101 , V_150 , V_148 -> V_152 ,
V_148 -> V_153 ) ;
return 0 ;
}
}
return - V_122 ;
}
static int F_72 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_147 V_148 ;
int V_87 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_145 . V_154 )
return - V_155 ;
V_87 = F_71 ( V_11 , V_14 , & V_148 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = V_145 . V_154 ( V_11 , & V_148 ) ;
return V_87 ;
}
static int F_73 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_147 V_148 ;
int V_87 = - V_15 ;
int V_156 = 0 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_145 . V_157 )
return - V_155 ;
V_87 = F_71 ( V_11 , V_14 , & V_148 ) ;
if ( V_87 < 0 )
return V_87 ;
if ( V_11 -> V_81 ) {
V_156 = F_74 ( V_11 -> V_81 ) ;
V_87 = F_75 ( V_11 -> V_81 , V_11 ) ;
if ( V_87 ) {
F_4 ( 1 , L_24 ,
V_11 -> V_14 , V_11 -> V_81 -> V_14 , V_87 ) ;
return V_87 ;
}
}
F_39 ( V_11 ) ;
if ( V_145 . V_158 )
V_145 . V_158 ( V_11 ) ;
V_87 = V_145 . V_157 ( V_11 , & V_148 ) ;
if ( V_145 . V_159 )
V_145 . V_159 ( V_11 ) ;
F_41 ( V_11 ) ;
if ( V_87 == - V_160 )
F_35 ( L_25 , V_11 -> V_14 ) ;
if ( ! V_87 ) {
if ( V_11 -> V_81 && V_156 )
F_76 ( V_11 -> V_81 ) ;
} else {
if ( V_11 -> V_81 )
F_77 ( V_11 -> V_81 , V_11 ) ;
}
return V_87 ;
}
static int F_78 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_147 V_148 ;
int V_87 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_145 . V_161 )
return - V_155 ;
V_87 = F_71 ( V_11 , V_14 , & V_148 ) ;
if ( V_87 < 0 )
return V_87 ;
return V_145 . V_161 ( V_11 , & V_148 ) ;
}
static bool F_79 ( struct V_10 * V_11 )
{
int V_4 , V_162 = 0 ;
if ( V_11 -> V_149 == 0 )
return false ;
for ( V_4 = 0 ; V_4 < V_11 -> V_149 ; V_4 ++ )
if ( F_78 ( V_11 , V_11 -> V_151 [ V_4 ] . V_14 ) > 0 )
V_162 ++ ;
if ( V_11 -> V_149 == V_162 )
return true ;
return false ;
}
static bool F_80 ( struct V_10 * V_11 )
{
int V_162 = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_149 && V_162 == 0 ; V_4 ++ )
if ( F_78 ( V_11 , V_11 -> V_151 [ V_4 ] . V_14 ) > 0 )
V_162 ++ ;
return ( V_162 ) ? true : false ;
}
static int F_81 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! V_11 -> V_81 || ! V_11 -> V_98 . V_99 . V_100 )
return - V_15 ;
if ( F_80 ( V_11 ) )
return 0 ;
F_18 ( L_26 , V_11 -> V_14 , V_101 ) ;
F_82 ( V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_81 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
V_22 = F_50 ( V_11 ) ;
if ( V_22 )
F_17 ( L_27 ,
V_11 -> V_14 ) ;
return 0 ;
}
static int F_83 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! V_11 -> V_81 || ! V_11 -> V_98 . V_99 . V_100 )
return - V_15 ;
F_18 ( L_26 , V_11 -> V_14 , V_101 ) ;
if ( F_80 ( V_11 ) )
return 0 ;
F_84 ( V_11 -> V_81 -> V_103 , V_11 -> V_81 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
V_22 = F_52 ( V_11 ) ;
if ( V_22 )
F_17 ( L_27 ,
V_11 -> V_14 ) ;
return 0 ;
}
static int F_85 ( struct V_10 * V_11 )
{
T_1 V_22 ;
int V_41 = 0 ;
int V_87 = 0 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_38 ) )
return - V_122 ;
if ( V_11 -> V_49 != V_50 ) {
F_17 ( L_28 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_66 & V_130 )
F_43 ( V_11 ) ;
F_18 ( L_29 , V_11 -> V_14 ) ;
V_22 = V_11 -> V_16 ;
V_87 = F_12 ( V_11 , & V_22 ) ;
if ( V_87 )
goto V_163;
F_6 ( V_22 , V_11 ) ;
if ( V_11 -> V_12 -> V_13 -> V_164 )
F_86 ( V_11 -> V_12 -> V_13 -> V_164 ) ;
V_41 = F_14 ( V_11 ) ;
if ( V_41 == V_45 ) {
F_35 ( L_30 ,
V_11 -> V_14 , V_45 ) ;
V_87 = - V_165 ;
goto V_163;
} else {
F_18 ( L_31 , V_11 -> V_14 , V_41 ) ;
}
V_87 = F_13 ( V_11 , & V_22 ) ;
if ( V_87 )
goto V_163;
F_6 ( V_22 , V_11 ) ;
V_163:
if ( V_11 -> V_66 & V_130 )
F_45 ( V_11 ) ;
return V_87 ;
}
static int F_87 ( struct V_10 * V_11 )
{
int V_4 , V_166 ;
F_18 ( L_32 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_167 ) {
V_166 = V_11 -> V_12 -> V_167 ( V_11 ) ;
} else {
if ( V_11 -> V_149 > 0 ) {
for ( V_4 = 0 ; V_4 < V_11 -> V_149 ; V_4 ++ )
F_72 ( V_11 , V_11 -> V_151 [ V_4 ] . V_14 ) ;
return 0 ;
} else {
V_166 = F_85 ( V_11 ) ;
if ( V_166 == - V_122 )
V_166 = 0 ;
}
}
F_16 ( V_11 ) ;
if ( V_11 -> V_12 -> V_13 ) {
F_3 ( V_11 ) ;
F_63 ( V_11 ) ;
}
return V_166 ;
}
static void F_88 ( void )
{
unsigned long V_66 ;
F_89 ( & V_168 , V_66 ) ;
if ( F_90 () && F_91 () )
F_92 () ;
else if ( F_93 () )
F_94 () ;
F_95 ( & V_168 , V_66 ) ;
}
static void F_96 ( struct V_10 * V_11 )
{
if ( V_11 -> V_98 . V_99 . V_66 & V_169 )
return;
if ( ! F_97 ( V_11 -> V_81 -> V_170 . V_171 -> V_102 ,
V_11 -> V_81 -> V_170 . V_171 -> V_172 ,
V_11 -> V_98 . V_99 . V_173 ) )
return;
V_11 -> V_98 . V_99 . V_174 ++ ;
F_98 ( V_11 -> V_81 -> V_170 . V_171 -> V_102 ,
V_11 -> V_81 -> V_170 . V_171 -> V_172 ,
V_11 -> V_98 . V_99 . V_173 ) ;
}
static int F_99 ( struct V_10 * V_11 )
{
return V_11 -> V_98 . V_99 . V_174 ;
}
static int F_100 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_12 -> V_175 )
return 0 ;
return V_11 -> V_12 -> V_175 ( V_11 ) ;
}
static int F_101 ( struct V_10 * V_11 )
{
int V_166 ;
int V_156 = 0 ;
F_18 ( L_33 , V_11 -> V_14 ) ;
if ( V_11 -> V_20 & V_176 ) {
if ( V_11 -> V_62 )
F_21 ( V_11 -> V_62 , V_50 ) ;
V_11 -> V_20 &= ~ V_176 ;
return 0 ;
}
if ( V_11 -> V_49 != V_177 &&
V_11 -> V_49 != V_70 &&
V_11 -> V_49 != V_178 ) {
F_4 ( 1 , L_34 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_79 ( V_11 ) )
return 0 ;
if ( V_11 -> V_62 && ( ! V_11 -> V_62 -> V_63 ||
( ( V_11 -> V_49 == V_70 ) &&
V_11 -> V_62 -> V_65 ) ) ) {
F_21 ( V_11 -> V_62 , V_50 ) ;
F_88 () ;
}
F_28 ( V_11 , V_179 ) ;
if ( V_11 -> V_81 ) {
V_156 = F_74 ( V_11 -> V_81 ) &&
! F_102 ( V_11 -> V_81 ) ;
V_166 = F_75 ( V_11 -> V_81 , V_11 ) ;
if ( V_166 ) {
F_4 ( 1 , L_24 ,
V_11 -> V_14 , V_11 -> V_81 -> V_14 , V_166 ) ;
return V_166 ;
}
}
F_39 ( V_11 ) ;
if ( V_145 . V_158 )
V_145 . V_158 ( V_11 ) ;
if ( V_11 -> V_66 & V_180 )
F_103 ( true ) ;
if ( V_145 . V_181 )
V_145 . V_181 ( V_11 ) ;
V_166 = ( V_145 . V_182 ) ? V_145 . V_182 ( V_11 ) :
- V_15 ;
if ( ! V_166 ) {
if ( V_11 -> V_81 && V_156 )
F_76 ( V_11 -> V_81 ) ;
V_11 -> V_49 = V_50 ;
if ( V_11 -> V_12 -> V_13 ) {
if ( ! ( V_11 -> V_20 & V_21 ) )
F_3 ( V_11 ) ;
F_63 ( V_11 ) ;
}
V_166 = F_100 ( V_11 ) ;
} else {
if ( V_145 . V_159 )
V_145 . V_159 ( V_11 ) ;
F_41 ( V_11 ) ;
F_18 ( L_35 ,
V_11 -> V_14 , V_166 ) ;
if ( V_11 -> V_81 )
F_77 ( V_11 -> V_81 , V_11 ) ;
}
return V_166 ;
}
static int F_104 ( struct V_10 * V_11 )
{
F_18 ( L_36 , V_11 -> V_14 ) ;
if ( V_11 -> V_49 != V_50 ) {
F_4 ( 1 , L_37 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_79 ( V_11 ) )
return 0 ;
if ( V_11 -> V_12 -> V_13 )
F_64 ( V_11 ) ;
F_30 ( V_11 , V_179 ) ;
if ( V_11 -> V_66 & V_180 )
F_103 ( false ) ;
if ( V_145 . V_159 )
V_145 . V_159 ( V_11 ) ;
F_41 ( V_11 ) ;
if ( V_11 -> V_81 )
F_77 ( V_11 -> V_81 , V_11 ) ;
if ( V_11 -> V_62 && V_11 -> V_62 -> V_65 ) {
F_21 ( V_11 -> V_62 , V_70 ) ;
F_88 () ;
}
V_11 -> V_49 = V_70 ;
return 0 ;
}
static int F_105 ( struct V_10 * V_11 )
{
int V_87 , V_4 ;
T_2 V_183 ;
if ( V_11 -> V_49 != V_70 &&
V_11 -> V_49 != V_50 ) {
F_4 ( 1 , L_38 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_79 ( V_11 ) )
return 0 ;
F_18 ( L_39 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_184 ) {
V_183 = V_11 -> V_49 ;
if ( V_11 -> V_49 == V_70 )
F_101 ( V_11 ) ;
V_87 = V_11 -> V_12 -> V_184 ( V_11 ) ;
if ( V_87 ) {
if ( V_183 == V_70 )
F_104 ( V_11 ) ;
return V_87 ;
}
}
if ( V_11 -> V_12 -> V_13 ) {
if ( V_11 -> V_49 == V_70 )
F_101 ( V_11 ) ;
F_65 ( V_11 ) ;
}
if ( V_11 -> V_49 == V_50 ) {
F_30 ( V_11 , V_179 ) ;
if ( V_11 -> V_66 & V_180 )
F_103 ( false ) ;
if ( V_145 . V_159 )
V_145 . V_159 ( V_11 ) ;
F_41 ( V_11 ) ;
if ( V_11 -> V_81 )
F_77 ( V_11 -> V_81 , V_11 ) ;
}
for ( V_4 = 0 ; V_4 < V_11 -> V_149 ; V_4 ++ )
F_72 ( V_11 , V_11 -> V_151 [ V_4 ] . V_14 ) ;
if ( V_11 -> V_62 )
F_21 ( V_11 -> V_62 , V_178 ) ;
V_11 -> V_49 = V_178 ;
return 0 ;
}
static int F_106 ( struct V_185 * V_186 ,
struct V_10 * V_11 )
{
int V_187 , V_4 , V_188 ;
const char * V_3 ;
V_187 = F_107 ( V_186 , L_40 ) ;
if ( V_187 < 1 )
return - V_189 ;
for ( V_4 = 0 ; V_4 < V_187 ; V_4 ++ ) {
V_188 = F_108 ( V_186 , L_40 ,
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
static int F_109 ( struct V_185 * V_186 ,
struct V_10 * V_11 ,
int * V_190 ,
struct V_185 * * V_121 )
{
struct V_185 * V_191 = NULL ;
int V_188 ;
V_188 = F_106 ( V_186 , V_11 ) ;
if ( V_188 >= 0 ) {
* V_121 = V_186 ;
* V_190 = V_188 ;
return 0 ;
}
F_110 (np, np0) {
struct V_185 * V_192 ;
int V_4 ;
V_188 = F_109 ( V_191 , V_11 , & V_4 , & V_192 ) ;
if ( V_188 == 0 ) {
* V_121 = V_192 ;
* V_190 = V_4 ;
return 0 ;
}
}
* V_121 = NULL ;
* V_190 = 0 ;
return - V_189 ;
}
static int T_4 F_111 ( struct V_10 * V_11 , void * V_143 ,
int V_190 , struct V_185 * V_186 )
{
struct V_116 * V_117 ;
void T_5 * va_start = NULL ;
if ( ! V_11 )
return - V_15 ;
F_60 ( V_11 ) ;
if ( V_11 -> V_20 & V_106 )
return - V_193 ;
V_117 = F_62 ( V_11 ) ;
if ( ! V_117 ) {
F_18 ( L_42 ,
V_11 -> V_14 ) ;
if ( ! V_186 )
return - V_193 ;
va_start = F_112 ( V_186 , V_190 + V_11 -> V_194 ) ;
} else {
va_start = F_113 ( V_117 -> V_119 , V_117 -> V_120 - V_117 -> V_119 ) ;
}
if ( ! va_start ) {
if ( V_117 )
F_114 ( L_43 , V_11 -> V_14 ) ;
else
F_114 ( L_44 ,
V_11 -> V_14 , V_190 , V_186 -> V_195 ) ;
return - V_193 ;
}
F_18 ( L_45 ,
V_11 -> V_14 , va_start ) ;
V_11 -> V_196 = va_start ;
return 0 ;
}
static int T_4 F_115 ( struct V_10 * V_11 , void * V_143 )
{
int V_166 , V_190 ;
struct V_185 * V_186 = NULL ;
if ( V_11 -> V_49 != V_144 )
return 0 ;
if ( F_116 () ) {
struct V_185 * V_197 ;
V_197 = F_117 ( NULL , L_46 ) ;
if ( ! V_197 )
return - V_189 ;
V_166 = F_109 ( V_197 , V_11 , & V_190 , & V_186 ) ;
if ( V_166 )
F_18 ( L_47 , V_11 -> V_14 ) ;
else if ( V_186 && V_190 )
F_17 ( L_48 ,
V_11 -> V_14 , V_186 -> V_14 ) ;
}
if ( V_11 -> V_12 -> V_13 ) {
V_166 = F_111 ( V_11 , NULL , V_190 , V_186 ) ;
if ( V_166 < 0 ) {
F_4 ( 1 , L_49 ,
V_11 -> V_14 ) ;
return 0 ;
}
}
V_166 = F_70 ( V_11 , NULL ) ;
if ( V_166 < 0 ) {
F_4 ( 1 , L_50 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_186 )
if ( F_118 ( V_186 , L_51 , NULL ) )
V_11 -> V_66 |= V_198 ;
if ( F_118 ( V_186 , L_52 , NULL ) )
V_11 -> V_66 |= V_199 ;
V_11 -> V_49 = V_177 ;
return 0 ;
}
static void T_4 F_119 ( struct V_10 * V_11 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( V_11 -> V_49 != V_177 )
return;
V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_89 -> V_82 )
continue;
if ( V_89 -> V_66 & V_96 ) {
} else {
F_40 ( V_89 -> V_82 ) ;
}
}
return;
}
static int T_4 F_120 ( struct V_10 * V_11 )
{
int V_166 ;
if ( V_11 -> V_49 != V_177 )
return - V_15 ;
if ( V_11 -> V_66 & V_200 )
return - V_201 ;
if ( V_11 -> V_149 == 0 ) {
V_166 = F_101 ( V_11 ) ;
if ( V_166 ) {
F_35 ( L_53 ,
V_11 -> V_14 , V_11 -> V_49 ) ;
return - V_15 ;
}
}
if ( ! ( V_11 -> V_66 & V_198 ) )
V_166 = F_87 ( V_11 ) ;
return V_166 ;
}
static void T_4 F_121 ( struct V_10 * V_11 )
{
T_2 V_202 ;
if ( V_11 -> V_149 > 0 )
return;
V_202 = V_11 -> V_203 ;
if ( V_202 == V_204 )
V_202 = V_50 ;
if ( ( V_11 -> V_66 & V_199 ) &&
( V_202 == V_70 ) ) {
V_11 -> V_20 |= V_176 ;
V_202 = V_50 ;
}
if ( V_202 == V_70 )
F_104 ( V_11 ) ;
else if ( V_202 == V_178 )
F_105 ( V_11 ) ;
else if ( V_202 != V_50 )
F_4 ( 1 , L_54 ,
V_11 -> V_14 , V_202 ) ;
return;
}
static int T_4 F_122 ( struct V_10 * V_11 , void * V_143 )
{
if ( V_11 -> V_49 != V_177 )
return 0 ;
F_119 ( V_11 ) ;
if ( ! F_120 ( V_11 ) )
F_121 ( V_11 ) ;
return 0 ;
}
static int T_4 F_123 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_14 || ! V_11 -> V_12 || ! V_11 -> V_12 -> V_14 ||
( V_11 -> V_49 != V_204 ) )
return - V_15 ;
F_18 ( L_55 , V_11 -> V_14 ) ;
if ( F_66 ( V_11 -> V_14 ) )
return - V_205 ;
F_124 ( & V_11 -> V_7 , & V_206 ) ;
F_125 ( & V_11 -> V_207 ) ;
F_125 ( & V_11 -> V_90 ) ;
F_126 ( & V_11 -> V_208 ) ;
V_11 -> V_49 = V_144 ;
if ( ! strcmp ( V_11 -> V_14 , V_209 ) )
V_179 = V_11 ;
return 0 ;
}
static int T_4 F_127 ( struct V_6 * * V_210 ,
struct V_6 * * V_211 )
{
unsigned int V_212 ;
if ( ( V_213 + V_214 ) <= V_215 ) {
* V_210 = & V_216 [ V_213 ++ ] ;
* V_211 = & V_216 [ V_213 ++ ] ;
return 0 ;
}
V_212 = sizeof( struct V_6 ) * V_214 ;
* V_211 = NULL ;
* V_210 = F_128 ( V_212 , 0 ) ;
* V_211 = ( void * ) ( * V_210 ) + sizeof( struct V_6 ) ;
V_217 ++ ;
F_18 ( L_56 ,
V_217 * V_214 ) ;
return 0 ;
}
static int T_4 F_129 ( struct V_1 * V_5 )
{
struct V_6 * V_210 , * V_211 ;
F_18 ( L_57 , V_5 -> V_218 -> V_14 ,
V_5 -> V_219 -> V_14 ) ;
F_127 ( & V_210 , & V_211 ) ;
V_210 -> V_8 = V_5 ;
F_125 ( & V_210 -> V_7 ) ;
F_130 ( & V_210 -> V_7 , & V_5 -> V_218 -> V_207 ) ;
V_5 -> V_218 -> V_220 ++ ;
V_211 -> V_8 = V_5 ;
F_125 ( & V_211 -> V_7 ) ;
F_130 ( & V_211 -> V_7 , & V_5 -> V_219 -> V_90 ) ;
V_5 -> V_219 -> V_91 ++ ;
return 0 ;
}
static int T_4 F_131 ( struct V_1 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_218 || ! V_5 -> V_219 || ! V_5 -> V_124 )
return - V_15 ;
if ( V_5 -> V_20 & V_221 )
return - V_205 ;
F_18 ( L_58 ,
V_5 -> V_218 -> V_14 , V_5 -> V_219 -> V_14 ) ;
if ( V_5 -> V_218 -> V_49 != V_144 )
F_123 ( V_5 -> V_218 ) ;
if ( V_5 -> V_219 -> V_49 != V_144 )
F_123 ( V_5 -> V_219 ) ;
F_129 ( V_5 ) ;
V_5 -> V_20 |= V_221 ;
return 0 ;
}
static int T_4 F_132 ( struct V_1 * * V_222 )
{
unsigned int V_4 = 0 ;
unsigned int V_212 ;
if ( V_216 ) {
F_4 ( 1 , L_59 ) ;
return - V_205 ;
}
if ( V_215 == 0 )
while ( V_222 [ V_4 ++ ] )
V_215 += V_214 ;
V_212 = sizeof( struct V_6 ) * V_215 ;
F_18 ( L_60 ,
V_101 , V_212 , V_215 ) ;
V_216 = F_128 ( V_212 , 0 ) ;
return 0 ;
}
static int F_133 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
if ( ! F_61 ( V_11 ) )
return 0 ;
return F_134 ( V_11 -> V_98 . V_223 . V_224 ,
V_11 -> V_98 . V_223 . V_225 ,
V_11 -> V_98 . V_223 . V_226 ) ;
}
static int F_135 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
if ( ! F_61 ( V_11 ) )
return 0 ;
return F_136 ( V_11 -> V_98 . V_223 . V_224 ,
V_11 -> V_98 . V_223 . V_225 ,
V_11 -> V_98 . V_223 . V_226 ) ;
}
static int F_137 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_107 || ! V_11 -> V_81 )
return 0 ;
if ( ! F_61 ( V_11 ) )
return 0 ;
return F_138 ( V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_81 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_139 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_81 )
return - V_15 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
if ( ! F_61 ( V_11 ) )
return 0 ;
return F_140 ( V_11 -> V_81 -> V_103 ,
V_11 -> V_81 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_141 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
return F_142 ( V_11 -> V_98 . V_223 . V_224 ,
V_148 -> V_152 ) ;
}
static int F_143 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
return F_144 ( V_11 -> V_98 . V_223 . V_224 ,
V_148 -> V_152 ,
V_148 -> V_153 ) ;
}
static int F_145 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
return F_146 ( V_11 -> V_98 . V_223 . V_224 ,
V_148 -> V_153 ) ;
}
static int F_147 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
return F_148 ( V_148 -> V_152 ,
V_11 -> V_81 -> V_170 . V_171 -> V_102 ,
V_11 -> V_81 -> V_170 . V_171 -> V_172 ,
V_11 -> V_98 . V_99 . V_227 ) ;
}
static int F_149 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
if ( V_148 -> V_153 )
F_114 ( L_61 ,
V_11 -> V_14 , V_148 -> V_14 ) ;
return F_150 ( V_148 -> V_152 ,
V_11 -> V_81 -> V_170 . V_171 -> V_102 ,
V_11 -> V_81 -> V_170 . V_171 -> V_172 ,
V_11 -> V_98 . V_99 . V_227 ) ;
}
static int F_151 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
return F_152 ( V_148 -> V_152 ,
V_11 -> V_81 -> V_170 . V_171 -> V_102 ,
V_11 -> V_81 -> V_170 . V_171 -> V_172 ,
V_11 -> V_98 . V_99 . V_227 ) ;
}
static int F_153 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
return F_154 ( V_148 -> V_152 ,
V_11 -> V_81 -> V_170 . V_171 -> V_172 ,
V_11 -> V_98 . V_99 . V_227 ) ;
}
static int F_155 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
return F_156 ( V_148 -> V_152 ,
V_148 -> V_153 ,
V_11 -> V_81 -> V_170 . V_171 -> V_172 ,
V_11 -> V_98 . V_99 . V_227 ,
V_11 -> V_98 . V_99 . V_228 ) ;
}
static int F_157 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
return F_158 ( V_148 -> V_152 ,
V_11 -> V_81 -> V_170 . V_171 -> V_172 ,
V_11 -> V_98 . V_99 . V_227 ) ;
}
T_1 F_5 ( struct V_10 * V_11 , T_3 V_229 )
{
if ( V_11 -> V_66 & V_230 )
return F_159 ( V_11 -> V_196 + V_229 ) ;
else
return F_160 ( V_11 -> V_196 + V_229 ) ;
}
void F_7 ( T_1 V_22 , struct V_10 * V_11 , T_3 V_229 )
{
if ( V_11 -> V_66 & V_230 )
F_161 ( V_22 , V_11 -> V_196 + V_229 ) ;
else
F_162 ( V_22 , V_11 -> V_196 + V_229 ) ;
}
int F_163 ( struct V_10 * V_11 )
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
struct V_10 * F_164 ( const char * V_14 )
{
struct V_10 * V_11 ;
if ( ! V_14 )
return NULL ;
V_11 = F_66 ( V_14 ) ;
return V_11 ;
}
int F_165 ( int (* F_166)( struct V_10 * V_11 , void * V_143 ) ,
void * V_143 )
{
struct V_10 * V_141 ;
int V_87 = 0 ;
if ( ! F_166 )
return - V_15 ;
F_67 (temp_oh, &omap_hwmod_list, node) {
V_87 = (* F_166)( V_141 , V_143 ) ;
if ( V_87 )
break;
}
return V_87 ;
}
int T_4 F_167 ( struct V_1 * * V_222 )
{
int V_166 , V_4 ;
if ( ! V_231 )
return - V_15 ;
if ( ! V_222 )
return 0 ;
if ( ! V_216 ) {
if ( F_132 ( V_222 ) ) {
F_114 ( L_62 ) ;
return - V_232 ;
}
}
V_4 = 0 ;
do {
V_166 = F_131 ( V_222 [ V_4 ] ) ;
F_4 ( V_166 && V_166 != - V_205 ,
L_63 ,
V_222 [ V_4 ] -> V_218 -> V_14 , V_222 [ V_4 ] -> V_219 -> V_14 , V_166 ) ;
} while ( V_222 [ ++ V_4 ] );
return 0 ;
}
static void T_4 F_168 ( struct V_10 * V_11 )
{
if ( ! V_179 || V_179 -> V_49 == V_204 )
F_114 ( L_64 ,
V_101 , V_209 ) ;
else if ( V_179 -> V_49 == V_144 && V_11 != V_179 )
F_169 ( V_209 ) ;
}
int T_4 F_169 ( const char * V_233 )
{
struct V_10 * V_11 ;
F_18 ( L_26 , V_233 , V_101 ) ;
V_11 = F_66 ( V_233 ) ;
if ( ! V_11 ) {
F_4 ( 1 , L_65 , V_233 ) ;
return - V_15 ;
}
F_168 ( V_11 ) ;
F_115 ( V_11 , NULL ) ;
F_122 ( V_11 , NULL ) ;
return 0 ;
}
static int T_4 F_170 ( void )
{
F_168 ( NULL ) ;
F_165 ( F_115 , NULL ) ;
F_165 ( F_122 , NULL ) ;
return 0 ;
}
int F_171 ( struct V_10 * V_11 )
{
int V_166 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_89 ( & V_11 -> V_208 , V_66 ) ;
V_166 = F_101 ( V_11 ) ;
F_95 ( & V_11 -> V_208 , V_66 ) ;
return V_166 ;
}
int F_172 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_89 ( & V_11 -> V_208 , V_66 ) ;
F_104 ( V_11 ) ;
F_95 ( & V_11 -> V_208 , V_66 ) ;
return 0 ;
}
int F_173 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_89 ( & V_11 -> V_208 , V_66 ) ;
F_105 ( V_11 ) ;
F_95 ( & V_11 -> V_208 , V_66 ) ;
return 0 ;
}
int F_174 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
F_89 ( & V_11 -> V_208 , V_66 ) ;
F_39 ( V_11 ) ;
F_95 ( & V_11 -> V_208 , V_66 ) ;
return 0 ;
}
int F_175 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
F_89 ( & V_11 -> V_208 , V_66 ) ;
F_41 ( V_11 ) ;
F_95 ( & V_11 -> V_208 , V_66 ) ;
return 0 ;
}
void F_176 ( struct V_10 * V_11 )
{
F_177 ( ! V_11 ) ;
if ( ! V_11 -> V_12 -> V_13 || ! V_11 -> V_12 -> V_13 -> V_18 ) {
F_4 ( 1 , L_66 ,
V_11 -> V_14 ) ;
return;
}
F_5 ( V_11 , V_11 -> V_12 -> V_13 -> V_17 ) ;
}
int F_178 ( struct V_10 * V_11 )
{
int V_166 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_89 ( & V_11 -> V_208 , V_66 ) ;
V_166 = F_87 ( V_11 ) ;
F_95 ( & V_11 -> V_208 , V_66 ) ;
return V_166 ;
}
int F_179 ( struct V_10 * V_11 , unsigned long V_66 )
{
int V_87 = 0 ;
if ( V_66 & V_234 )
V_87 += F_54 ( V_11 ) ;
if ( V_66 & V_235 )
V_87 += F_55 ( V_11 ) ;
if ( V_66 & V_236 ) {
int V_4 = 0 ;
struct V_1 * V_89 ;
struct V_2 * V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
V_87 += F_56 ( V_89 ) ;
}
}
return V_87 ;
}
int F_180 ( struct V_10 * V_11 , struct V_237 * V_188 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
int V_4 , V_61 , V_238 , V_239 , V_240 ;
int V_166 = 0 ;
V_238 = F_54 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_238 ; V_4 ++ ) {
( V_188 + V_166 ) -> V_14 = ( V_11 -> V_110 + V_4 ) -> V_14 ;
( V_188 + V_166 ) -> V_241 = ( V_11 -> V_110 + V_4 ) -> V_111 ;
( V_188 + V_166 ) -> V_242 = ( V_11 -> V_110 + V_4 ) -> V_111 ;
( V_188 + V_166 ) -> V_66 = V_234 ;
V_166 ++ ;
}
V_239 = F_55 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_239 ; V_4 ++ ) {
( V_188 + V_166 ) -> V_14 = ( V_11 -> V_114 + V_4 ) -> V_14 ;
( V_188 + V_166 ) -> V_241 = ( V_11 -> V_114 + V_4 ) -> V_115 ;
( V_188 + V_166 ) -> V_242 = ( V_11 -> V_114 + V_4 ) -> V_115 ;
( V_188 + V_166 ) -> V_66 = V_235 ;
V_166 ++ ;
}
V_3 = V_11 -> V_90 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
V_240 = F_56 ( V_89 ) ;
for ( V_61 = 0 ; V_61 < V_240 ; V_61 ++ ) {
( V_188 + V_166 ) -> V_14 = ( V_89 -> V_118 + V_61 ) -> V_14 ;
( V_188 + V_166 ) -> V_241 = ( V_89 -> V_118 + V_61 ) -> V_119 ;
( V_188 + V_166 ) -> V_242 = ( V_89 -> V_118 + V_61 ) -> V_120 ;
( V_188 + V_166 ) -> V_66 = V_236 ;
V_166 ++ ;
}
}
return V_166 ;
}
int F_181 ( struct V_10 * V_11 , struct V_237 * V_188 )
{
int V_4 , V_239 ;
int V_166 = 0 ;
V_239 = F_55 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_239 ; V_4 ++ ) {
( V_188 + V_166 ) -> V_14 = ( V_11 -> V_114 + V_4 ) -> V_14 ;
( V_188 + V_166 ) -> V_241 = ( V_11 -> V_114 + V_4 ) -> V_115 ;
( V_188 + V_166 ) -> V_242 = ( V_11 -> V_114 + V_4 ) -> V_115 ;
( V_188 + V_166 ) -> V_66 = V_235 ;
V_166 ++ ;
}
return V_166 ;
}
int F_182 ( struct V_10 * V_11 , unsigned int type ,
const char * V_14 , struct V_237 * V_243 )
{
int V_166 ;
unsigned int V_111 , V_123 ;
T_1 V_119 , V_120 ;
if ( ! V_11 || ! V_243 )
return - V_15 ;
if ( type == V_234 ) {
V_166 = F_57 ( V_11 , V_14 , & V_111 ) ;
if ( V_166 )
return V_166 ;
V_243 -> V_241 = V_111 ;
V_243 -> V_242 = V_111 ;
} else if ( type == V_235 ) {
V_166 = F_58 ( V_11 , V_14 , & V_123 ) ;
if ( V_166 )
return V_166 ;
V_243 -> V_241 = V_123 ;
V_243 -> V_242 = V_123 ;
} else if ( type == V_236 ) {
V_166 = F_59 ( V_11 , V_14 , & V_119 , & V_120 ) ;
if ( V_166 )
return V_166 ;
V_243 -> V_241 = V_119 ;
V_243 -> V_242 = V_120 ;
} else {
return - V_15 ;
}
V_243 -> V_66 = type ;
V_243 -> V_14 = V_14 ;
return 0 ;
}
struct V_244 * F_183 ( struct V_10 * V_11 )
{
struct V_80 * V_41 ;
struct V_1 * V_5 ;
struct V_78 * V_81 ;
struct V_79 * V_80 ;
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_81 )
return V_11 -> V_81 -> V_170 . V_171 ;
if ( V_11 -> V_82 ) {
V_41 = V_11 -> V_82 ;
} else {
V_5 = F_61 ( V_11 ) ;
if ( ! V_5 )
return NULL ;
V_41 = V_5 -> V_82 ;
}
V_80 = F_26 ( F_27 ( V_41 ) ) ;
V_81 = V_80 -> V_81 ;
if ( ! V_81 )
return NULL ;
return V_81 -> V_170 . V_171 ;
}
void T_5 * F_184 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_20 & V_106 )
return NULL ;
if ( V_11 -> V_49 == V_204 )
return NULL ;
return V_11 -> V_196 ;
}
int F_185 ( struct V_10 * V_11 ,
struct V_10 * V_84 )
{
return F_28 ( V_11 , V_84 ) ;
}
int F_186 ( struct V_10 * V_11 ,
struct V_10 * V_84 )
{
return F_30 ( V_11 , V_84 ) ;
}
int F_187 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
T_1 V_22 ;
F_89 ( & V_11 -> V_208 , V_66 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ) {
V_22 = V_11 -> V_16 ;
F_22 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_20 ( V_11 , true ) ;
F_95 ( & V_11 -> V_208 , V_66 ) ;
return 0 ;
}
int F_188 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
T_1 V_22 ;
F_89 ( & V_11 -> V_208 , V_66 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ) {
V_22 = V_11 -> V_16 ;
F_23 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_20 ( V_11 , false ) ;
F_95 ( & V_11 -> V_208 , V_66 ) ;
return 0 ;
}
int F_189 ( struct V_10 * V_11 , const char * V_14 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_89 ( & V_11 -> V_208 , V_66 ) ;
V_87 = F_72 ( V_11 , V_14 ) ;
F_95 ( & V_11 -> V_208 , V_66 ) ;
return V_87 ;
}
int F_190 ( struct V_10 * V_11 , const char * V_14 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_89 ( & V_11 -> V_208 , V_66 ) ;
V_87 = F_73 ( V_11 , V_14 ) ;
F_95 ( & V_11 -> V_208 , V_66 ) ;
return V_87 ;
}
int F_191 ( struct V_10 * V_11 , const char * V_14 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_89 ( & V_11 -> V_208 , V_66 ) ;
V_87 = F_78 ( V_11 , V_14 ) ;
F_95 ( & V_11 -> V_208 , V_66 ) ;
return V_87 ;
}
int F_192 ( const char * V_245 ,
int (* F_166)( struct V_10 * V_11 ,
void * V_124 ) ,
void * V_124 )
{
struct V_10 * V_141 ;
int V_87 = 0 ;
if ( ! V_245 || ! F_166 )
return - V_15 ;
F_18 ( L_67 ,
V_101 , V_245 ) ;
F_67 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_141 -> V_12 -> V_14 , V_245 ) ) {
F_18 ( L_68 ,
V_101 , V_141 -> V_14 ) ;
V_87 = (* F_166)( V_141 , V_124 ) ;
if ( V_87 )
break;
}
}
if ( V_87 )
F_18 ( L_69 ,
V_101 , V_87 ) ;
return V_87 ;
}
int F_193 ( struct V_10 * V_11 , T_2 V_246 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
if ( V_246 != V_178 &&
V_246 != V_50 &&
V_246 != V_70 )
return - V_15 ;
F_89 ( & V_11 -> V_208 , V_66 ) ;
if ( V_11 -> V_49 != V_144 ) {
V_87 = - V_15 ;
goto V_247;
}
V_11 -> V_203 = V_246 ;
V_87 = 0 ;
V_247:
F_95 ( & V_11 -> V_208 , V_66 ) ;
return V_87 ;
}
int F_194 ( struct V_10 * V_11 )
{
struct V_244 * V_170 ;
int V_87 = 0 ;
if ( V_145 . V_248 )
return V_145 . V_248 ( V_11 ) ;
V_170 = F_183 ( V_11 ) ;
if ( V_170 )
V_87 = F_195 ( V_170 ) ;
return V_87 ;
}
int F_196 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_49 != V_144 ) {
F_114 ( L_70 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_66 |= V_198 ;
return 0 ;
}
int F_197 ( struct V_10 * V_11 , int V_249 , int V_250 )
{
int V_251 ;
F_198 () ;
if ( ! V_11 || ! V_11 -> V_62 || ! V_11 -> V_110 || V_249 < 0 ||
V_249 >= V_11 -> V_62 -> V_64 )
return - V_15 ;
for ( V_251 = 0 ; V_11 -> V_110 [ V_251 ] . V_111 >= 0 ; V_251 ++ )
;
if ( V_250 >= V_251 )
return - V_15 ;
if ( ! V_11 -> V_62 -> V_252 ) {
V_11 -> V_62 -> V_252 = F_199 ( sizeof( int ) * V_11 -> V_62 -> V_64 ,
V_253 ) ;
if ( ! V_11 -> V_62 -> V_252 )
return - V_232 ;
}
V_11 -> V_62 -> V_252 [ V_249 ] = V_250 ;
return 0 ;
}
void T_4 F_200 ( void )
{
if ( F_201 () ) {
V_145 . V_182 = F_133 ;
V_145 . V_154 = F_141 ;
V_145 . V_157 = F_143 ;
V_145 . V_161 = F_145 ;
} else if ( F_90 () ) {
V_145 . V_182 = F_135 ;
V_145 . V_154 = F_141 ;
V_145 . V_157 = F_143 ;
V_145 . V_161 = F_145 ;
V_145 . V_85 = F_68 ;
} else if ( F_93 () || F_202 () || F_203 () ) {
V_145 . V_158 = F_46 ;
V_145 . V_159 = F_81 ;
V_145 . V_182 = F_137 ;
V_145 . V_154 = F_147 ;
V_145 . V_157 = F_149 ;
V_145 . V_161 = F_151 ;
V_145 . V_85 = F_68 ;
V_145 . V_181 = F_96 ;
V_145 . V_248 = F_99 ;
} else if ( F_204 () ) {
V_145 . V_158 = F_46 ;
V_145 . V_159 = F_81 ;
V_145 . V_182 = F_137 ;
V_145 . V_154 = F_147 ;
V_145 . V_157 = F_149 ;
V_145 . V_161 = F_151 ;
V_145 . V_85 = F_68 ;
} else if ( F_205 () ) {
V_145 . V_158 = F_48 ;
V_145 . V_159 = F_83 ;
V_145 . V_182 = F_139 ;
V_145 . V_154 = F_153 ;
V_145 . V_157 = F_155 ;
V_145 . V_161 = F_157 ;
V_145 . V_85 = F_68 ;
} else {
F_4 ( 1 , L_71 ) ;
}
V_231 = true ;
}
const char * F_206 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
return V_11 -> V_88 ;
}
