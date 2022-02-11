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
V_11 -> V_81 -> V_103 ,
V_11 -> V_81 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static void F_47 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_81 || ! V_11 -> V_98 . V_99 . V_100 )
return;
F_18 ( L_17 ,
V_11 -> V_14 , V_101 , V_11 -> V_98 . V_99 . V_100 ) ;
F_48 ( V_11 -> V_98 . V_99 . V_100 , V_11 -> V_81 -> V_103 ,
V_11 -> V_81 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_49 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_106 || ! V_11 -> V_81 )
return 0 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
return F_50 ( V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_81 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_51 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_106 )
return 0 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
return F_52 ( V_11 -> V_81 -> V_103 ,
V_11 -> V_81 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_53 ( struct V_10 * V_11 )
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
static int F_54 ( struct V_10 * V_11 )
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
static int F_55 ( struct V_1 * V_89 )
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
static int F_56 ( struct V_10 * V_11 , const char * V_14 ,
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
static int F_57 ( struct V_10 * V_11 , const char * V_14 ,
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
static int F_58 ( struct V_10 * V_11 , const char * V_14 ,
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
static void T_4 F_59 ( struct V_10 * V_11 )
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
static struct V_1 * F_60 ( struct V_10 * V_11 )
{
if ( ! V_11 || V_11 -> V_20 & V_106 || V_11 -> V_91 == 0 )
return NULL ;
return V_11 -> V_126 ;
}
static struct V_116 * T_4 F_61 ( struct V_10 * V_11 )
{
struct V_1 * V_89 ;
struct V_116 * V_117 ;
int V_121 = 0 , V_4 = 0 ;
V_89 = F_60 ( V_11 ) ;
if ( ! V_89 || ! V_89 -> V_118 )
return NULL ;
do {
V_117 = & V_89 -> V_118 [ V_4 ++ ] ;
if ( V_117 -> V_66 & V_127 )
V_121 = 1 ;
} while ( ! V_121 && V_117 -> V_119 != V_117 -> V_120 );
return ( V_121 ) ? V_117 : NULL ;
}
static void F_62 ( struct V_10 * V_11 )
{
T_2 V_29 , V_128 ;
T_1 V_22 ;
bool V_129 ;
struct V_78 * V_81 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
if ( V_11 -> V_66 & V_130 )
F_42 ( V_11 ) ;
F_14 ( V_11 ) ;
if ( V_11 -> V_66 & V_130 )
F_44 ( V_11 ) ;
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
static void F_63 ( struct V_10 * V_11 )
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
static void F_64 ( struct V_10 * V_11 )
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
static struct V_10 * F_65 ( const char * V_14 )
{
struct V_10 * V_11 , * V_141 ;
V_11 = NULL ;
F_66 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_14 , V_141 -> V_14 ) ) {
V_11 = V_141 ;
break;
}
}
return V_11 ;
}
static int F_67 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_142 ) {
F_18 ( L_18 , V_11 -> V_14 ) ;
return 0 ;
}
V_11 -> V_81 = F_68 ( V_11 -> V_142 ) ;
if ( ! V_11 -> V_81 ) {
F_17 ( L_19 ,
V_11 -> V_14 , V_11 -> V_142 ) ;
return 0 ;
}
F_18 ( L_20 ,
V_11 -> V_14 , V_11 -> V_142 ) ;
return 0 ;
}
static int F_69 ( struct V_10 * V_11 , void * V_143 )
{
int V_87 = 0 ;
if ( V_11 -> V_49 != V_144 )
return 0 ;
F_18 ( L_21 , V_11 -> V_14 ) ;
if ( V_145 . V_85 )
V_87 |= V_145 . V_85 ( V_11 ) ;
V_87 |= F_32 ( V_11 ) ;
V_87 |= F_36 ( V_11 ) ;
V_87 |= F_37 ( V_11 ) ;
if ( ! V_87 )
V_11 -> V_49 = V_146 ;
else
F_17 ( L_22 , V_11 -> V_14 ) ;
return V_87 ;
}
static int F_70 ( struct V_10 * V_11 , const char * V_14 ,
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
static int F_71 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_147 V_148 ;
int V_87 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_145 . V_154 )
return - V_155 ;
V_87 = F_70 ( V_11 , V_14 , & V_148 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = V_145 . V_154 ( V_11 , & V_148 ) ;
return V_87 ;
}
static int F_72 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_147 V_148 ;
int V_87 = - V_15 ;
int V_156 = 0 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_145 . V_157 )
return - V_155 ;
V_87 = F_70 ( V_11 , V_14 , & V_148 ) ;
if ( V_87 < 0 )
return V_87 ;
if ( V_11 -> V_81 ) {
V_156 = F_73 ( V_11 -> V_81 ) ;
V_87 = F_74 ( V_11 -> V_81 , V_11 ) ;
if ( V_87 ) {
F_4 ( 1 , L_24 ,
V_11 -> V_14 , V_11 -> V_81 -> V_14 , V_87 ) ;
return V_87 ;
}
}
F_38 ( V_11 ) ;
if ( V_145 . V_158 )
V_145 . V_158 ( V_11 ) ;
V_87 = V_145 . V_157 ( V_11 , & V_148 ) ;
if ( V_145 . V_159 )
V_145 . V_159 ( V_11 ) ;
F_40 ( V_11 ) ;
if ( V_87 == - V_160 )
F_17 ( L_25 , V_11 -> V_14 ) ;
if ( ! V_87 ) {
if ( V_11 -> V_81 && V_156 )
F_75 ( V_11 -> V_81 ) ;
} else {
if ( V_11 -> V_81 )
F_76 ( V_11 -> V_81 , V_11 ) ;
}
return V_87 ;
}
static int F_77 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_147 V_148 ;
int V_87 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_145 . V_161 )
return - V_155 ;
V_87 = F_70 ( V_11 , V_14 , & V_148 ) ;
if ( V_87 < 0 )
return V_87 ;
return V_145 . V_161 ( V_11 , & V_148 ) ;
}
static bool F_78 ( struct V_10 * V_11 )
{
int V_4 , V_162 = 0 ;
if ( V_11 -> V_149 == 0 )
return false ;
for ( V_4 = 0 ; V_4 < V_11 -> V_149 ; V_4 ++ )
if ( F_77 ( V_11 , V_11 -> V_151 [ V_4 ] . V_14 ) > 0 )
V_162 ++ ;
if ( V_11 -> V_149 == V_162 )
return true ;
return false ;
}
static bool F_79 ( struct V_10 * V_11 )
{
int V_162 = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_149 && V_162 == 0 ; V_4 ++ )
if ( F_77 ( V_11 , V_11 -> V_151 [ V_4 ] . V_14 ) > 0 )
V_162 ++ ;
return ( V_162 ) ? true : false ;
}
static int F_80 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! V_11 -> V_81 || ! V_11 -> V_98 . V_99 . V_100 )
return - V_15 ;
if ( F_79 ( V_11 ) )
return 0 ;
F_18 ( L_26 , V_11 -> V_14 , V_101 ) ;
F_81 ( V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_81 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
V_22 = F_49 ( V_11 ) ;
if ( V_22 )
F_17 ( L_27 ,
V_11 -> V_14 ) ;
return 0 ;
}
static int F_82 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! V_11 -> V_81 || ! V_11 -> V_98 . V_99 . V_100 )
return - V_15 ;
F_18 ( L_26 , V_11 -> V_14 , V_101 ) ;
if ( F_79 ( V_11 ) )
return 0 ;
F_83 ( V_11 -> V_81 -> V_103 , V_11 -> V_81 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
V_22 = F_51 ( V_11 ) ;
if ( V_22 )
F_17 ( L_27 ,
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
F_17 ( L_28 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_66 & V_130 )
F_42 ( V_11 ) ;
F_18 ( L_29 , V_11 -> V_14 ) ;
V_22 = V_11 -> V_16 ;
V_87 = F_12 ( V_11 , & V_22 ) ;
if ( V_87 )
goto V_163;
F_6 ( V_22 , V_11 ) ;
if ( V_11 -> V_12 -> V_13 -> V_164 )
F_85 ( V_11 -> V_12 -> V_13 -> V_164 ) ;
V_41 = F_14 ( V_11 ) ;
if ( V_41 == V_45 ) {
F_17 ( L_30 ,
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
F_44 ( V_11 ) ;
return V_87 ;
}
static int F_86 ( struct V_10 * V_11 )
{
int V_4 , V_166 ;
F_18 ( L_32 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_167 ) {
V_166 = V_11 -> V_12 -> V_167 ( V_11 ) ;
} else {
if ( V_11 -> V_149 > 0 ) {
for ( V_4 = 0 ; V_4 < V_11 -> V_149 ; V_4 ++ )
F_71 ( V_11 , V_11 -> V_151 [ V_4 ] . V_14 ) ;
return 0 ;
} else {
V_166 = F_84 ( V_11 ) ;
if ( V_166 == - V_122 )
V_166 = 0 ;
}
}
F_16 ( V_11 ) ;
if ( V_11 -> V_12 -> V_13 ) {
F_3 ( V_11 ) ;
F_62 ( V_11 ) ;
}
return V_166 ;
}
static void F_87 ( void )
{
unsigned long V_66 ;
F_88 ( & V_168 , V_66 ) ;
if ( F_89 () )
F_90 () ;
else if ( F_91 () )
F_92 () ;
F_93 ( & V_168 , V_66 ) ;
}
static void F_94 ( struct V_10 * V_11 )
{
if ( V_11 -> V_98 . V_99 . V_66 & V_169 )
return;
if ( ! F_95 ( V_11 -> V_81 -> V_170 . V_171 -> V_102 ,
V_11 -> V_81 -> V_170 . V_171 -> V_172 ,
V_11 -> V_98 . V_99 . V_173 ) )
return;
V_11 -> V_98 . V_99 . V_174 ++ ;
F_96 ( V_11 -> V_81 -> V_170 . V_171 -> V_102 ,
V_11 -> V_81 -> V_170 . V_171 -> V_172 ,
V_11 -> V_98 . V_99 . V_173 ) ;
}
static int F_97 ( struct V_10 * V_11 )
{
return V_11 -> V_98 . V_99 . V_174 ;
}
static int F_98 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_12 -> V_175 )
return 0 ;
return V_11 -> V_12 -> V_175 ( V_11 ) ;
}
static int F_99 ( struct V_10 * V_11 )
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
if ( F_78 ( V_11 ) )
return 0 ;
if ( V_11 -> V_62 && ( ! V_11 -> V_62 -> V_63 ||
( ( V_11 -> V_49 == V_70 ) &&
V_11 -> V_62 -> V_65 ) ) ) {
F_21 ( V_11 -> V_62 , V_50 ) ;
F_87 () ;
} else if ( V_11 -> V_66 & V_179 ) {
F_87 () ;
}
F_28 ( V_11 , V_180 ) ;
if ( V_11 -> V_81 ) {
V_156 = F_73 ( V_11 -> V_81 ) &&
! F_100 ( V_11 -> V_81 ) ;
V_166 = F_74 ( V_11 -> V_81 , V_11 ) ;
if ( V_166 ) {
F_4 ( 1 , L_24 ,
V_11 -> V_14 , V_11 -> V_81 -> V_14 , V_166 ) ;
return V_166 ;
}
}
F_38 ( V_11 ) ;
if ( V_145 . V_158 )
V_145 . V_158 ( V_11 ) ;
if ( V_11 -> V_66 & V_181 )
F_101 ( true ) ;
if ( V_145 . V_182 )
V_145 . V_182 ( V_11 ) ;
V_166 = ( V_145 . V_183 ) ? V_145 . V_183 ( V_11 ) :
- V_15 ;
if ( ! V_166 ) {
if ( V_11 -> V_81 && V_156 )
F_75 ( V_11 -> V_81 ) ;
V_11 -> V_49 = V_50 ;
if ( V_11 -> V_12 -> V_13 ) {
if ( ! ( V_11 -> V_20 & V_21 ) )
F_3 ( V_11 ) ;
F_62 ( V_11 ) ;
}
V_166 = F_98 ( V_11 ) ;
} else {
if ( V_145 . V_159 )
V_145 . V_159 ( V_11 ) ;
F_40 ( V_11 ) ;
F_18 ( L_35 ,
V_11 -> V_14 , V_166 ) ;
if ( V_11 -> V_81 )
F_76 ( V_11 -> V_81 , V_11 ) ;
}
return V_166 ;
}
static int F_102 ( struct V_10 * V_11 )
{
F_18 ( L_36 , V_11 -> V_14 ) ;
if ( V_11 -> V_49 != V_50 ) {
F_4 ( 1 , L_37 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_78 ( V_11 ) )
return 0 ;
if ( V_11 -> V_12 -> V_13 )
F_63 ( V_11 ) ;
F_30 ( V_11 , V_180 ) ;
if ( V_11 -> V_66 & V_181 )
F_101 ( false ) ;
if ( V_145 . V_159 )
V_145 . V_159 ( V_11 ) ;
F_40 ( V_11 ) ;
if ( V_11 -> V_81 )
F_76 ( V_11 -> V_81 , V_11 ) ;
if ( V_11 -> V_62 && V_11 -> V_62 -> V_65 ) {
F_21 ( V_11 -> V_62 , V_70 ) ;
F_87 () ;
} else if ( V_11 -> V_66 & V_179 ) {
F_87 () ;
}
V_11 -> V_49 = V_70 ;
return 0 ;
}
static int F_103 ( struct V_10 * V_11 )
{
int V_87 , V_4 ;
T_2 V_184 ;
if ( V_11 -> V_49 != V_70 &&
V_11 -> V_49 != V_50 ) {
F_4 ( 1 , L_38 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_78 ( V_11 ) )
return 0 ;
F_18 ( L_39 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_185 ) {
V_184 = V_11 -> V_49 ;
if ( V_11 -> V_49 == V_70 )
F_99 ( V_11 ) ;
V_87 = V_11 -> V_12 -> V_185 ( V_11 ) ;
if ( V_87 ) {
if ( V_184 == V_70 )
F_102 ( V_11 ) ;
return V_87 ;
}
}
if ( V_11 -> V_12 -> V_13 ) {
if ( V_11 -> V_49 == V_70 )
F_99 ( V_11 ) ;
F_64 ( V_11 ) ;
}
if ( V_11 -> V_49 == V_50 ) {
F_30 ( V_11 , V_180 ) ;
if ( V_11 -> V_66 & V_181 )
F_101 ( false ) ;
if ( V_145 . V_159 )
V_145 . V_159 ( V_11 ) ;
F_40 ( V_11 ) ;
if ( V_11 -> V_81 )
F_76 ( V_11 -> V_81 , V_11 ) ;
}
for ( V_4 = 0 ; V_4 < V_11 -> V_149 ; V_4 ++ )
F_71 ( V_11 , V_11 -> V_151 [ V_4 ] . V_14 ) ;
if ( V_11 -> V_62 )
F_21 ( V_11 -> V_62 , V_178 ) ;
V_11 -> V_49 = V_178 ;
return 0 ;
}
static int F_104 ( struct V_186 * V_187 ,
struct V_10 * V_11 )
{
int V_188 , V_4 , V_189 ;
const char * V_3 ;
V_188 = F_105 ( V_187 , L_40 ) ;
if ( V_188 < 1 )
return - V_190 ;
for ( V_4 = 0 ; V_4 < V_188 ; V_4 ++ ) {
V_189 = F_106 ( V_187 , L_40 ,
V_4 , & V_3 ) ;
if ( V_189 )
continue;
if ( ! strcmp ( V_3 , V_11 -> V_14 ) ) {
F_18 ( L_41 ,
V_187 -> V_14 , V_4 , V_11 -> V_14 ) ;
return V_4 ;
}
}
return - V_190 ;
}
static int F_107 ( struct V_186 * V_187 ,
struct V_10 * V_11 ,
int * V_191 ,
struct V_186 * * V_121 )
{
struct V_186 * V_192 = NULL ;
int V_189 ;
V_189 = F_104 ( V_187 , V_11 ) ;
if ( V_189 >= 0 ) {
* V_121 = V_187 ;
* V_191 = V_189 ;
return 0 ;
}
F_108 (np, np0) {
struct V_186 * V_193 ;
int V_4 ;
V_189 = F_107 ( V_192 , V_11 , & V_4 , & V_193 ) ;
if ( V_189 == 0 ) {
* V_121 = V_193 ;
* V_191 = V_4 ;
return 0 ;
}
}
* V_121 = NULL ;
* V_191 = 0 ;
return - V_190 ;
}
static int T_4 F_109 ( struct V_10 * V_11 , void * V_143 ,
int V_191 , struct V_186 * V_187 )
{
struct V_116 * V_117 ;
void T_5 * va_start = NULL ;
if ( ! V_11 )
return - V_15 ;
F_59 ( V_11 ) ;
if ( V_11 -> V_20 & V_106 )
return - V_194 ;
V_117 = F_61 ( V_11 ) ;
if ( ! V_117 ) {
F_18 ( L_42 ,
V_11 -> V_14 ) ;
if ( ! V_187 )
return - V_194 ;
va_start = F_110 ( V_187 , V_191 + V_11 -> V_195 ) ;
} else {
va_start = F_111 ( V_117 -> V_119 , V_117 -> V_120 - V_117 -> V_119 ) ;
}
if ( ! va_start ) {
if ( V_117 )
F_112 ( L_43 , V_11 -> V_14 ) ;
else
F_112 ( L_44 ,
V_11 -> V_14 , V_191 , V_187 -> V_196 ) ;
return - V_194 ;
}
F_18 ( L_45 ,
V_11 -> V_14 , va_start ) ;
V_11 -> V_197 = va_start ;
return 0 ;
}
static int T_4 F_113 ( struct V_10 * V_11 , void * V_143 )
{
int V_166 , V_191 ;
struct V_186 * V_187 = NULL ;
if ( V_11 -> V_49 != V_144 )
return 0 ;
if ( F_114 () ) {
struct V_186 * V_198 ;
V_198 = F_115 ( NULL , L_46 ) ;
if ( ! V_198 )
return - V_190 ;
V_166 = F_107 ( V_198 , V_11 , & V_191 , & V_187 ) ;
if ( V_166 )
F_18 ( L_47 , V_11 -> V_14 ) ;
else if ( V_187 && V_191 )
F_17 ( L_48 ,
V_11 -> V_14 , V_187 -> V_14 ) ;
}
if ( V_11 -> V_12 -> V_13 ) {
V_166 = F_109 ( V_11 , NULL , V_191 , V_187 ) ;
if ( V_166 < 0 ) {
F_4 ( 1 , L_49 ,
V_11 -> V_14 ) ;
return 0 ;
}
}
V_166 = F_69 ( V_11 , NULL ) ;
if ( V_166 < 0 ) {
F_4 ( 1 , L_50 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_187 ) {
if ( F_116 ( V_187 , L_51 , NULL ) )
V_11 -> V_66 |= V_199 ;
if ( F_116 ( V_187 , L_52 , NULL ) )
V_11 -> V_66 |= V_200 ;
}
V_11 -> V_49 = V_177 ;
return 0 ;
}
static void T_4 F_117 ( struct V_10 * V_11 )
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
F_39 ( V_89 -> V_82 ) ;
}
}
return;
}
static int T_4 F_118 ( struct V_10 * V_11 )
{
int V_166 ;
if ( V_11 -> V_49 != V_177 )
return - V_15 ;
if ( V_11 -> V_66 & V_201 )
return - V_202 ;
if ( V_11 -> V_149 == 0 ) {
V_166 = F_99 ( V_11 ) ;
if ( V_166 ) {
F_17 ( L_53 ,
V_11 -> V_14 , V_11 -> V_49 ) ;
return - V_15 ;
}
}
if ( ! ( V_11 -> V_66 & V_199 ) )
V_166 = F_86 ( V_11 ) ;
return V_166 ;
}
static void T_4 F_119 ( struct V_10 * V_11 )
{
T_2 V_203 ;
if ( V_11 -> V_149 > 0 )
return;
V_203 = V_11 -> V_204 ;
if ( V_203 == V_205 )
V_203 = V_50 ;
if ( ( V_11 -> V_66 & V_200 ) &&
( V_203 == V_70 ) ) {
V_11 -> V_20 |= V_176 ;
V_203 = V_50 ;
}
if ( V_203 == V_70 )
F_102 ( V_11 ) ;
else if ( V_203 == V_178 )
F_103 ( V_11 ) ;
else if ( V_203 != V_50 )
F_4 ( 1 , L_54 ,
V_11 -> V_14 , V_203 ) ;
return;
}
static int T_4 F_120 ( struct V_10 * V_11 , void * V_143 )
{
if ( V_11 -> V_49 != V_177 )
return 0 ;
F_117 ( V_11 ) ;
if ( ! F_118 ( V_11 ) )
F_119 ( V_11 ) ;
return 0 ;
}
static int T_4 F_121 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_14 || ! V_11 -> V_12 || ! V_11 -> V_12 -> V_14 ||
( V_11 -> V_49 != V_205 ) )
return - V_15 ;
F_18 ( L_55 , V_11 -> V_14 ) ;
if ( F_65 ( V_11 -> V_14 ) )
return - V_206 ;
F_122 ( & V_11 -> V_7 , & V_207 ) ;
F_123 ( & V_11 -> V_208 ) ;
F_123 ( & V_11 -> V_90 ) ;
F_124 ( & V_11 -> V_209 ) ;
V_11 -> V_49 = V_144 ;
if ( ! strcmp ( V_11 -> V_14 , V_210 ) )
V_180 = V_11 ;
return 0 ;
}
static int T_4 F_125 ( struct V_6 * * V_211 ,
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
* V_211 = F_126 ( V_213 , 0 ) ;
* V_212 = ( void * ) ( * V_211 ) + sizeof( struct V_6 ) ;
V_218 ++ ;
F_18 ( L_56 ,
V_218 * V_215 ) ;
return 0 ;
}
static int T_4 F_127 ( struct V_1 * V_5 )
{
struct V_6 * V_211 , * V_212 ;
F_18 ( L_57 , V_5 -> V_219 -> V_14 ,
V_5 -> V_220 -> V_14 ) ;
F_125 ( & V_211 , & V_212 ) ;
V_211 -> V_8 = V_5 ;
F_123 ( & V_211 -> V_7 ) ;
F_128 ( & V_211 -> V_7 , & V_5 -> V_219 -> V_208 ) ;
V_5 -> V_219 -> V_221 ++ ;
V_212 -> V_8 = V_5 ;
F_123 ( & V_212 -> V_7 ) ;
F_128 ( & V_212 -> V_7 , & V_5 -> V_220 -> V_90 ) ;
V_5 -> V_220 -> V_91 ++ ;
return 0 ;
}
static int T_4 F_129 ( struct V_1 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_219 || ! V_5 -> V_220 || ! V_5 -> V_124 )
return - V_15 ;
if ( V_5 -> V_20 & V_222 )
return - V_206 ;
F_18 ( L_58 ,
V_5 -> V_219 -> V_14 , V_5 -> V_220 -> V_14 ) ;
if ( V_5 -> V_219 -> V_49 != V_144 )
F_121 ( V_5 -> V_219 ) ;
if ( V_5 -> V_220 -> V_49 != V_144 )
F_121 ( V_5 -> V_220 ) ;
F_127 ( V_5 ) ;
V_5 -> V_20 |= V_222 ;
return 0 ;
}
static int T_4 F_130 ( struct V_1 * * V_223 )
{
unsigned int V_4 = 0 ;
unsigned int V_213 ;
if ( V_217 ) {
F_4 ( 1 , L_59 ) ;
return - V_206 ;
}
if ( V_216 == 0 )
while ( V_223 [ V_4 ++ ] )
V_216 += V_215 ;
V_213 = sizeof( struct V_6 ) * V_216 ;
F_18 ( L_60 ,
V_101 , V_213 , V_216 ) ;
V_217 = F_126 ( V_213 , 0 ) ;
return 0 ;
}
static int F_131 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
if ( ! F_60 ( V_11 ) )
return 0 ;
return F_132 ( V_11 -> V_98 . V_224 . V_225 ,
V_11 -> V_98 . V_224 . V_226 ,
V_11 -> V_98 . V_224 . V_227 ) ;
}
static int F_133 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
if ( ! F_60 ( V_11 ) )
return 0 ;
return F_134 ( V_11 -> V_98 . V_224 . V_225 ,
V_11 -> V_98 . V_224 . V_226 ,
V_11 -> V_98 . V_224 . V_227 ) ;
}
static int F_135 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_107 || ! V_11 -> V_81 )
return 0 ;
if ( ! F_60 ( V_11 ) )
return 0 ;
return F_136 ( V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_81 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_137 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_81 )
return - V_15 ;
if ( V_11 -> V_66 & V_107 )
return 0 ;
if ( ! F_60 ( V_11 ) )
return 0 ;
return F_138 ( V_11 -> V_81 -> V_103 ,
V_11 -> V_81 -> V_104 ,
V_11 -> V_98 . V_99 . V_105 ) ;
}
static int F_139 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
return F_140 ( V_11 -> V_98 . V_224 . V_225 ,
V_148 -> V_152 ) ;
}
static int F_141 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
return F_142 ( V_11 -> V_98 . V_224 . V_225 ,
V_148 -> V_152 ,
V_148 -> V_153 ) ;
}
static int F_143 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
return F_144 ( V_11 -> V_98 . V_224 . V_225 ,
V_148 -> V_153 ) ;
}
static int F_145 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
return F_146 ( V_148 -> V_152 ,
V_11 -> V_81 -> V_170 . V_171 -> V_102 ,
V_11 -> V_81 -> V_170 . V_171 -> V_172 ,
V_11 -> V_98 . V_99 . V_228 ) ;
}
static int F_147 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
if ( V_148 -> V_153 )
F_112 ( L_61 ,
V_11 -> V_14 , V_148 -> V_14 ) ;
return F_148 ( V_148 -> V_152 ,
V_11 -> V_81 -> V_170 . V_171 -> V_102 ,
V_11 -> V_81 -> V_170 . V_171 -> V_172 ,
V_11 -> V_98 . V_99 . V_228 ) ;
}
static int F_149 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
return F_150 ( V_148 -> V_152 ,
V_11 -> V_81 -> V_170 . V_171 -> V_102 ,
V_11 -> V_81 -> V_170 . V_171 -> V_172 ,
V_11 -> V_98 . V_99 . V_228 ) ;
}
static int F_151 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
return F_152 ( V_148 -> V_152 ,
V_11 -> V_81 -> V_170 . V_171 -> V_172 ,
V_11 -> V_98 . V_99 . V_228 ) ;
}
static int F_153 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
return F_154 ( V_148 -> V_152 ,
V_148 -> V_153 ,
V_11 -> V_81 -> V_170 . V_171 -> V_172 ,
V_11 -> V_98 . V_99 . V_228 ,
V_11 -> V_98 . V_99 . V_229 ) ;
}
static int F_155 ( struct V_10 * V_11 ,
struct V_147 * V_148 )
{
return F_156 ( V_148 -> V_152 ,
V_11 -> V_81 -> V_170 . V_171 -> V_172 ,
V_11 -> V_98 . V_99 . V_228 ) ;
}
T_1 F_5 ( struct V_10 * V_11 , T_3 V_230 )
{
if ( V_11 -> V_66 & V_231 )
return F_157 ( V_11 -> V_197 + V_230 ) ;
else
return F_158 ( V_11 -> V_197 + V_230 ) ;
}
void F_7 ( T_1 V_22 , struct V_10 * V_11 , T_3 V_230 )
{
if ( V_11 -> V_66 & V_231 )
F_159 ( V_22 , V_11 -> V_197 + V_230 ) ;
else
F_160 ( V_22 , V_11 -> V_197 + V_230 ) ;
}
int F_161 ( struct V_10 * V_11 )
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
struct V_10 * F_162 ( const char * V_14 )
{
struct V_10 * V_11 ;
if ( ! V_14 )
return NULL ;
V_11 = F_65 ( V_14 ) ;
return V_11 ;
}
int F_163 ( int (* F_164)( struct V_10 * V_11 , void * V_143 ) ,
void * V_143 )
{
struct V_10 * V_141 ;
int V_87 = 0 ;
if ( ! F_164 )
return - V_15 ;
F_66 (temp_oh, &omap_hwmod_list, node) {
V_87 = (* F_164)( V_141 , V_143 ) ;
if ( V_87 )
break;
}
return V_87 ;
}
int T_4 F_165 ( struct V_1 * * V_223 )
{
int V_166 , V_4 ;
if ( ! V_232 )
return - V_15 ;
if ( ! V_223 )
return 0 ;
if ( V_223 [ 0 ] == NULL )
return 0 ;
if ( ! V_217 ) {
if ( F_130 ( V_223 ) ) {
F_112 ( L_62 ) ;
return - V_233 ;
}
}
V_4 = 0 ;
do {
V_166 = F_129 ( V_223 [ V_4 ] ) ;
F_4 ( V_166 && V_166 != - V_206 ,
L_63 ,
V_223 [ V_4 ] -> V_219 -> V_14 , V_223 [ V_4 ] -> V_220 -> V_14 , V_166 ) ;
} while ( V_223 [ ++ V_4 ] );
return 0 ;
}
static void T_4 F_166 ( struct V_10 * V_11 )
{
if ( ! V_180 || V_180 -> V_49 == V_205 )
F_112 ( L_64 ,
V_101 , V_210 ) ;
else if ( V_180 -> V_49 == V_144 && V_11 != V_180 )
F_167 ( V_210 ) ;
}
int T_4 F_167 ( const char * V_234 )
{
struct V_10 * V_11 ;
F_18 ( L_26 , V_234 , V_101 ) ;
V_11 = F_65 ( V_234 ) ;
if ( ! V_11 ) {
F_4 ( 1 , L_65 , V_234 ) ;
return - V_15 ;
}
F_166 ( V_11 ) ;
F_113 ( V_11 , NULL ) ;
F_120 ( V_11 , NULL ) ;
return 0 ;
}
static int T_4 F_168 ( void )
{
F_166 ( NULL ) ;
F_163 ( F_113 , NULL ) ;
F_163 ( F_120 , NULL ) ;
return 0 ;
}
int F_169 ( struct V_10 * V_11 )
{
int V_166 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_209 , V_66 ) ;
V_166 = F_99 ( V_11 ) ;
F_93 ( & V_11 -> V_209 , V_66 ) ;
return V_166 ;
}
int F_170 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_209 , V_66 ) ;
F_102 ( V_11 ) ;
F_93 ( & V_11 -> V_209 , V_66 ) ;
return 0 ;
}
int F_171 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_209 , V_66 ) ;
F_103 ( V_11 ) ;
F_93 ( & V_11 -> V_209 , V_66 ) ;
return 0 ;
}
int F_172 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
F_88 ( & V_11 -> V_209 , V_66 ) ;
F_38 ( V_11 ) ;
F_93 ( & V_11 -> V_209 , V_66 ) ;
return 0 ;
}
int F_173 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
F_88 ( & V_11 -> V_209 , V_66 ) ;
F_40 ( V_11 ) ;
F_93 ( & V_11 -> V_209 , V_66 ) ;
return 0 ;
}
void F_174 ( struct V_10 * V_11 )
{
F_175 ( ! V_11 ) ;
if ( ! V_11 -> V_12 -> V_13 || ! V_11 -> V_12 -> V_13 -> V_18 ) {
F_4 ( 1 , L_66 ,
V_11 -> V_14 ) ;
return;
}
F_5 ( V_11 , V_11 -> V_12 -> V_13 -> V_17 ) ;
}
int F_176 ( struct V_10 * V_11 )
{
int V_166 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_209 , V_66 ) ;
V_166 = F_86 ( V_11 ) ;
F_93 ( & V_11 -> V_209 , V_66 ) ;
return V_166 ;
}
int F_177 ( struct V_10 * V_11 , unsigned long V_66 )
{
int V_87 = 0 ;
if ( V_66 & V_235 )
V_87 += F_53 ( V_11 ) ;
if ( V_66 & V_236 )
V_87 += F_54 ( V_11 ) ;
if ( V_66 & V_237 ) {
int V_4 = 0 ;
struct V_1 * V_89 ;
struct V_2 * V_3 = V_11 -> V_90 . V_9 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
V_87 += F_55 ( V_89 ) ;
}
}
return V_87 ;
}
int F_178 ( struct V_10 * V_11 , struct V_238 * V_189 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
int V_4 , V_61 , V_239 , V_240 , V_241 ;
int V_166 = 0 ;
V_239 = F_53 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_239 ; V_4 ++ ) {
( V_189 + V_166 ) -> V_14 = ( V_11 -> V_110 + V_4 ) -> V_14 ;
( V_189 + V_166 ) -> V_242 = ( V_11 -> V_110 + V_4 ) -> V_111 ;
( V_189 + V_166 ) -> V_243 = ( V_11 -> V_110 + V_4 ) -> V_111 ;
( V_189 + V_166 ) -> V_66 = V_235 ;
V_166 ++ ;
}
V_240 = F_54 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_240 ; V_4 ++ ) {
( V_189 + V_166 ) -> V_14 = ( V_11 -> V_114 + V_4 ) -> V_14 ;
( V_189 + V_166 ) -> V_242 = ( V_11 -> V_114 + V_4 ) -> V_115 ;
( V_189 + V_166 ) -> V_243 = ( V_11 -> V_114 + V_4 ) -> V_115 ;
( V_189 + V_166 ) -> V_66 = V_236 ;
V_166 ++ ;
}
V_3 = V_11 -> V_90 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_91 ) {
V_89 = F_1 ( & V_3 , & V_4 ) ;
V_241 = F_55 ( V_89 ) ;
for ( V_61 = 0 ; V_61 < V_241 ; V_61 ++ ) {
( V_189 + V_166 ) -> V_14 = ( V_89 -> V_118 + V_61 ) -> V_14 ;
( V_189 + V_166 ) -> V_242 = ( V_89 -> V_118 + V_61 ) -> V_119 ;
( V_189 + V_166 ) -> V_243 = ( V_89 -> V_118 + V_61 ) -> V_120 ;
( V_189 + V_166 ) -> V_66 = V_237 ;
V_166 ++ ;
}
}
return V_166 ;
}
int F_179 ( struct V_10 * V_11 , struct V_238 * V_189 )
{
int V_4 , V_240 ;
int V_166 = 0 ;
V_240 = F_54 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_240 ; V_4 ++ ) {
( V_189 + V_166 ) -> V_14 = ( V_11 -> V_114 + V_4 ) -> V_14 ;
( V_189 + V_166 ) -> V_242 = ( V_11 -> V_114 + V_4 ) -> V_115 ;
( V_189 + V_166 ) -> V_243 = ( V_11 -> V_114 + V_4 ) -> V_115 ;
( V_189 + V_166 ) -> V_66 = V_236 ;
V_166 ++ ;
}
return V_166 ;
}
int F_180 ( struct V_10 * V_11 , unsigned int type ,
const char * V_14 , struct V_238 * V_244 )
{
int V_166 ;
unsigned int V_111 , V_123 ;
T_1 V_119 , V_120 ;
if ( ! V_11 || ! V_244 )
return - V_15 ;
if ( type == V_235 ) {
V_166 = F_56 ( V_11 , V_14 , & V_111 ) ;
if ( V_166 )
return V_166 ;
V_244 -> V_242 = V_111 ;
V_244 -> V_243 = V_111 ;
} else if ( type == V_236 ) {
V_166 = F_57 ( V_11 , V_14 , & V_123 ) ;
if ( V_166 )
return V_166 ;
V_244 -> V_242 = V_123 ;
V_244 -> V_243 = V_123 ;
} else if ( type == V_237 ) {
V_166 = F_58 ( V_11 , V_14 , & V_119 , & V_120 ) ;
if ( V_166 )
return V_166 ;
V_244 -> V_242 = V_119 ;
V_244 -> V_243 = V_120 ;
} else {
return - V_15 ;
}
V_244 -> V_66 = type ;
V_244 -> V_14 = V_14 ;
return 0 ;
}
struct V_245 * F_181 ( struct V_10 * V_11 )
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
V_5 = F_60 ( V_11 ) ;
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
void T_5 * F_182 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_20 & V_106 )
return NULL ;
if ( V_11 -> V_49 == V_205 )
return NULL ;
return V_11 -> V_197 ;
}
int F_183 ( struct V_10 * V_11 ,
struct V_10 * V_84 )
{
return F_28 ( V_11 , V_84 ) ;
}
int F_184 ( struct V_10 * V_11 ,
struct V_10 * V_84 )
{
return F_30 ( V_11 , V_84 ) ;
}
int F_185 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
T_1 V_22 ;
F_88 ( & V_11 -> V_209 , V_66 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ) {
V_22 = V_11 -> V_16 ;
F_22 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_20 ( V_11 , true ) ;
F_93 ( & V_11 -> V_209 , V_66 ) ;
return 0 ;
}
int F_186 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
T_1 V_22 ;
F_88 ( & V_11 -> V_209 , V_66 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ) {
V_22 = V_11 -> V_16 ;
F_23 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_20 ( V_11 , false ) ;
F_93 ( & V_11 -> V_209 , V_66 ) ;
return 0 ;
}
int F_187 ( struct V_10 * V_11 , const char * V_14 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_209 , V_66 ) ;
V_87 = F_71 ( V_11 , V_14 ) ;
F_93 ( & V_11 -> V_209 , V_66 ) ;
return V_87 ;
}
int F_188 ( struct V_10 * V_11 , const char * V_14 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_209 , V_66 ) ;
V_87 = F_72 ( V_11 , V_14 ) ;
F_93 ( & V_11 -> V_209 , V_66 ) ;
return V_87 ;
}
int F_189 ( struct V_10 * V_11 , const char * V_14 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_209 , V_66 ) ;
V_87 = F_77 ( V_11 , V_14 ) ;
F_93 ( & V_11 -> V_209 , V_66 ) ;
return V_87 ;
}
int F_190 ( const char * V_246 ,
int (* F_164)( struct V_10 * V_11 ,
void * V_124 ) ,
void * V_124 )
{
struct V_10 * V_141 ;
int V_87 = 0 ;
if ( ! V_246 || ! F_164 )
return - V_15 ;
F_18 ( L_67 ,
V_101 , V_246 ) ;
F_66 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_141 -> V_12 -> V_14 , V_246 ) ) {
F_18 ( L_68 ,
V_101 , V_141 -> V_14 ) ;
V_87 = (* F_164)( V_141 , V_124 ) ;
if ( V_87 )
break;
}
}
if ( V_87 )
F_18 ( L_69 ,
V_101 , V_87 ) ;
return V_87 ;
}
int F_191 ( struct V_10 * V_11 , T_2 V_247 )
{
int V_87 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
if ( V_247 != V_178 &&
V_247 != V_50 &&
V_247 != V_70 )
return - V_15 ;
F_88 ( & V_11 -> V_209 , V_66 ) ;
if ( V_11 -> V_49 != V_144 ) {
V_87 = - V_15 ;
goto V_248;
}
V_11 -> V_204 = V_247 ;
V_87 = 0 ;
V_248:
F_93 ( & V_11 -> V_209 , V_66 ) ;
return V_87 ;
}
int F_192 ( struct V_10 * V_11 )
{
struct V_245 * V_170 ;
int V_87 = 0 ;
if ( V_145 . V_249 )
return V_145 . V_249 ( V_11 ) ;
V_170 = F_181 ( V_11 ) ;
if ( V_170 )
V_87 = F_193 ( V_170 ) ;
return V_87 ;
}
int F_194 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_49 != V_144 ) {
F_112 ( L_70 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_66 |= V_199 ;
return 0 ;
}
int F_195 ( struct V_10 * V_11 , int V_250 , int V_251 )
{
int V_252 ;
F_196 () ;
if ( ! V_11 || ! V_11 -> V_62 || ! V_11 -> V_110 || V_250 < 0 ||
V_250 >= V_11 -> V_62 -> V_64 )
return - V_15 ;
for ( V_252 = 0 ; V_11 -> V_110 [ V_252 ] . V_111 >= 0 ; V_252 ++ )
;
if ( V_251 >= V_252 )
return - V_15 ;
if ( ! V_11 -> V_62 -> V_253 ) {
V_11 -> V_62 -> V_253 = F_197 ( sizeof( int ) * V_11 -> V_62 -> V_64 ,
V_254 ) ;
if ( ! V_11 -> V_62 -> V_253 )
return - V_233 ;
}
V_11 -> V_62 -> V_253 [ V_250 ] = V_251 ;
return 0 ;
}
void T_4 F_198 ( void )
{
if ( F_199 () ) {
V_145 . V_183 = F_131 ;
V_145 . V_154 = F_139 ;
V_145 . V_157 = F_141 ;
V_145 . V_161 = F_143 ;
} else if ( F_89 () ) {
V_145 . V_183 = F_133 ;
V_145 . V_154 = F_139 ;
V_145 . V_157 = F_141 ;
V_145 . V_161 = F_143 ;
V_145 . V_85 = F_67 ;
} else if ( F_91 () || F_200 () || F_201 () ) {
V_145 . V_158 = F_45 ;
V_145 . V_159 = F_80 ;
V_145 . V_183 = F_135 ;
V_145 . V_154 = F_145 ;
V_145 . V_157 = F_147 ;
V_145 . V_161 = F_149 ;
V_145 . V_85 = F_67 ;
V_145 . V_182 = F_94 ;
V_145 . V_249 = F_97 ;
} else if ( F_202 () ) {
V_145 . V_158 = F_45 ;
V_145 . V_159 = F_80 ;
V_145 . V_183 = F_135 ;
V_145 . V_154 = F_151 ;
V_145 . V_157 = F_153 ;
V_145 . V_161 = F_155 ;
V_145 . V_85 = F_67 ;
} else if ( F_203 () ) {
V_145 . V_158 = F_47 ;
V_145 . V_159 = F_82 ;
V_145 . V_183 = F_137 ;
V_145 . V_154 = F_151 ;
V_145 . V_157 = F_153 ;
V_145 . V_161 = F_155 ;
V_145 . V_85 = F_67 ;
} else {
F_4 ( 1 , L_71 ) ;
}
V_232 = true ;
}
const char * F_204 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
return V_11 -> V_88 ;
}
