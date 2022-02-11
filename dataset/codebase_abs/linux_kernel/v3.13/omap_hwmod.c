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
V_80 = F_25 ( F_26 ( V_11 -> V_82 ) ) ;
return V_80 -> V_81 ;
}
return NULL ;
}
static int F_27 ( struct V_10 * V_11 , struct V_10 * V_83 )
{
struct V_78 * V_81 , * V_84 ;
V_81 = F_24 ( V_11 ) ;
V_84 = F_24 ( V_83 ) ;
if ( ! V_81 || ! V_84 )
return - V_15 ;
if ( V_81 && V_81 -> V_66 & V_85 )
return 0 ;
return F_28 ( V_81 , V_84 ) ;
}
static int F_29 ( struct V_10 * V_11 , struct V_10 * V_83 )
{
struct V_78 * V_81 , * V_84 ;
V_81 = F_24 ( V_11 ) ;
V_84 = F_24 ( V_83 ) ;
if ( ! V_81 || ! V_84 )
return - V_15 ;
if ( V_81 && V_81 -> V_66 & V_85 )
return 0 ;
return F_30 ( V_81 , V_84 ) ;
}
static int F_31 ( struct V_10 * V_11 )
{
int V_86 = 0 ;
if ( ! V_11 -> V_87 )
return 0 ;
V_11 -> V_82 = F_32 ( NULL , V_11 -> V_87 ) ;
if ( F_33 ( V_11 -> V_82 ) ) {
F_34 ( L_7 ,
V_11 -> V_14 , V_11 -> V_87 ) ;
return - V_15 ;
}
F_35 ( V_11 -> V_82 ) ;
if ( ! F_24 ( V_11 ) )
F_18 ( L_8 ,
V_11 -> V_14 , V_11 -> V_87 ) ;
return V_86 ;
}
static int F_36 ( struct V_10 * V_11 )
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
V_41 = F_32 ( NULL , V_88 -> V_80 ) ;
if ( F_33 ( V_41 ) ) {
F_34 ( L_9 ,
V_11 -> V_14 , V_88 -> V_80 ) ;
V_86 = - V_15 ;
continue;
}
V_88 -> V_82 = V_41 ;
F_35 ( V_88 -> V_82 ) ;
}
return V_86 ;
}
static int F_37 ( struct V_10 * V_11 )
{
struct V_91 * V_92 ;
struct V_80 * V_41 ;
int V_4 ;
int V_86 = 0 ;
for ( V_4 = V_11 -> V_93 , V_92 = V_11 -> V_94 ; V_4 > 0 ; V_4 -- , V_92 ++ ) {
V_41 = F_32 ( NULL , V_92 -> V_80 ) ;
if ( F_33 ( V_41 ) ) {
F_34 ( L_10 ,
V_11 -> V_14 , V_92 -> V_80 ) ;
V_86 = - V_15 ;
continue;
}
V_92 -> V_82 = V_41 ;
F_35 ( V_92 -> V_82 ) ;
}
return V_86 ;
}
static int F_38 ( struct V_10 * V_11 )
{
struct V_1 * V_88 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_18 ( L_11 , V_11 -> V_14 ) ;
if ( V_11 -> V_82 )
F_39 ( V_11 -> V_82 ) ;
V_3 = V_11 -> V_89 . V_9 ;
while ( V_4 < V_11 -> V_90 ) {
V_88 = F_1 ( & V_3 , & V_4 ) ;
if ( V_88 -> V_82 && ( V_88 -> V_66 & V_95 ) )
F_39 ( V_88 -> V_82 ) ;
}
return 0 ;
}
static int F_40 ( struct V_10 * V_11 )
{
struct V_1 * V_88 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_18 ( L_12 , V_11 -> V_14 ) ;
if ( V_11 -> V_82 )
F_41 ( V_11 -> V_82 ) ;
V_3 = V_11 -> V_89 . V_9 ;
while ( V_4 < V_11 -> V_90 ) {
V_88 = F_1 ( & V_3 , & V_4 ) ;
if ( V_88 -> V_82 && ( V_88 -> V_66 & V_95 ) )
F_41 ( V_88 -> V_82 ) ;
}
return 0 ;
}
static void F_42 ( struct V_10 * V_11 )
{
struct V_91 * V_92 ;
int V_4 ;
F_18 ( L_13 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_93 , V_92 = V_11 -> V_94 ; V_4 > 0 ; V_4 -- , V_92 ++ )
if ( V_92 -> V_82 ) {
F_18 ( L_14 , V_92 -> V_96 ,
F_43 ( V_92 -> V_82 ) ) ;
F_39 ( V_92 -> V_82 ) ;
}
}
static void F_44 ( struct V_10 * V_11 )
{
struct V_91 * V_92 ;
int V_4 ;
F_18 ( L_15 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_93 , V_92 = V_11 -> V_94 ; V_4 > 0 ; V_4 -- , V_92 ++ )
if ( V_92 -> V_82 ) {
F_18 ( L_16 , V_92 -> V_96 ,
F_43 ( V_92 -> V_82 ) ) ;
F_41 ( V_92 -> V_82 ) ;
}
}
static void F_45 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_81 || ! V_11 -> V_97 . V_98 . V_99 )
return;
F_18 ( L_17 ,
V_11 -> V_14 , V_100 , V_11 -> V_97 . V_98 . V_99 ) ;
F_46 ( V_11 -> V_97 . V_98 . V_99 ,
V_11 -> V_81 -> V_101 ,
V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_97 . V_98 . V_104 ) ;
}
static void F_47 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_81 || ! V_11 -> V_97 . V_98 . V_99 )
return;
F_18 ( L_17 ,
V_11 -> V_14 , V_100 , V_11 -> V_97 . V_98 . V_99 ) ;
F_48 ( V_11 -> V_97 . V_98 . V_99 , V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_97 . V_98 . V_104 ) ;
}
static int F_49 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_105 || ! V_11 -> V_81 )
return 0 ;
if ( V_11 -> V_66 & V_106 )
return 0 ;
return F_50 ( V_11 -> V_81 -> V_101 ,
V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_97 . V_98 . V_104 ) ;
}
static int F_51 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_105 )
return 0 ;
if ( V_11 -> V_66 & V_106 )
return 0 ;
return F_52 ( V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_97 . V_98 . V_104 ) ;
}
static int F_53 ( struct V_10 * V_11 )
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
static int F_54 ( struct V_10 * V_11 )
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
static int F_55 ( struct V_1 * V_88 )
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
static int F_56 ( struct V_10 * V_11 , const char * V_14 ,
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
static int F_57 ( struct V_10 * V_11 , const char * V_14 ,
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
static int F_58 ( struct V_10 * V_11 , const char * V_14 ,
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
static void T_4 F_59 ( struct V_10 * V_11 )
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
static struct V_1 * F_60 ( struct V_10 * V_11 )
{
if ( ! V_11 || V_11 -> V_20 & V_105 || V_11 -> V_90 == 0 )
return NULL ;
return V_11 -> V_125 ;
}
static struct V_115 * T_4 F_61 ( struct V_10 * V_11 )
{
struct V_1 * V_88 ;
struct V_115 * V_116 ;
int V_120 = 0 , V_4 = 0 ;
V_88 = F_60 ( V_11 ) ;
if ( ! V_88 || ! V_88 -> V_117 )
return NULL ;
do {
V_116 = & V_88 -> V_117 [ V_4 ++ ] ;
if ( V_116 -> V_66 & V_126 )
V_120 = 1 ;
} while ( ! V_120 && V_116 -> V_118 != V_116 -> V_119 );
return ( V_120 ) ? V_116 : NULL ;
}
static void F_62 ( struct V_10 * V_11 )
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
static void F_63 ( struct V_10 * V_11 )
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
static void F_64 ( struct V_10 * V_11 )
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
static struct V_10 * F_65 ( const char * V_14 )
{
struct V_10 * V_11 , * V_140 ;
V_11 = NULL ;
F_66 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_14 , V_140 -> V_14 ) ) {
V_11 = V_140 ;
break;
}
}
return V_11 ;
}
static int F_67 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_141 ) {
F_18 ( L_18 , V_11 -> V_14 ) ;
return 0 ;
}
V_11 -> V_81 = F_68 ( V_11 -> V_141 ) ;
if ( ! V_11 -> V_81 ) {
F_34 ( L_19 ,
V_11 -> V_14 , V_11 -> V_141 ) ;
return - V_15 ;
}
F_18 ( L_20 ,
V_11 -> V_14 , V_11 -> V_141 ) ;
return 0 ;
}
static int F_69 ( struct V_10 * V_11 , void * V_142 )
{
int V_86 = 0 ;
if ( V_11 -> V_49 != V_143 )
return 0 ;
F_18 ( L_21 , V_11 -> V_14 ) ;
if ( V_144 . V_84 )
V_86 |= V_144 . V_84 ( V_11 ) ;
V_86 |= F_31 ( V_11 ) ;
V_86 |= F_36 ( V_11 ) ;
V_86 |= F_37 ( V_11 ) ;
if ( ! V_86 )
V_11 -> V_49 = V_145 ;
else
F_34 ( L_22 , V_11 -> V_14 ) ;
return V_86 ;
}
static int F_70 ( struct V_10 * V_11 , const char * V_14 ,
struct V_146 * V_147 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_148 ; V_4 ++ ) {
const char * V_149 = V_11 -> V_150 [ V_4 ] . V_14 ;
if ( ! strcmp ( V_149 , V_14 ) ) {
V_147 -> V_151 = V_11 -> V_150 [ V_4 ] . V_151 ;
V_147 -> V_152 = V_11 -> V_150 [ V_4 ] . V_152 ;
F_18 ( L_23 ,
V_11 -> V_14 , V_100 , V_149 , V_147 -> V_151 ,
V_147 -> V_152 ) ;
return 0 ;
}
}
return - V_121 ;
}
static int F_71 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_146 V_147 ;
int V_86 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_144 . V_153 )
return - V_154 ;
V_86 = F_70 ( V_11 , V_14 , & V_147 ) ;
if ( V_86 < 0 )
return V_86 ;
V_86 = V_144 . V_153 ( V_11 , & V_147 ) ;
return V_86 ;
}
static int F_72 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_146 V_147 ;
int V_86 = - V_15 ;
int V_155 = 0 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_144 . V_156 )
return - V_154 ;
V_86 = F_70 ( V_11 , V_14 , & V_147 ) ;
if ( V_86 < 0 )
return V_86 ;
if ( V_11 -> V_81 ) {
V_155 = F_73 ( V_11 -> V_81 ) ;
V_86 = F_74 ( V_11 -> V_81 , V_11 ) ;
if ( V_86 ) {
F_4 ( 1 , L_24 ,
V_11 -> V_14 , V_11 -> V_81 -> V_14 , V_86 ) ;
return V_86 ;
}
}
F_38 ( V_11 ) ;
if ( V_144 . V_157 )
V_144 . V_157 ( V_11 ) ;
V_86 = V_144 . V_156 ( V_11 , & V_147 ) ;
if ( V_144 . V_158 )
V_144 . V_158 ( V_11 ) ;
F_40 ( V_11 ) ;
if ( V_86 == - V_159 )
F_34 ( L_25 , V_11 -> V_14 ) ;
if ( ! V_86 ) {
if ( V_11 -> V_81 && V_155 )
F_75 ( V_11 -> V_81 ) ;
} else {
if ( V_11 -> V_81 )
F_76 ( V_11 -> V_81 , V_11 ) ;
}
return V_86 ;
}
static int F_77 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_146 V_147 ;
int V_86 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_144 . V_160 )
return - V_154 ;
V_86 = F_70 ( V_11 , V_14 , & V_147 ) ;
if ( V_86 < 0 )
return V_86 ;
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
if ( ! V_11 -> V_81 || ! V_11 -> V_97 . V_98 . V_99 )
return - V_15 ;
if ( F_79 ( V_11 ) )
return 0 ;
F_18 ( L_26 , V_11 -> V_14 , V_100 ) ;
F_81 ( V_11 -> V_81 -> V_101 ,
V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_97 . V_98 . V_104 ) ;
V_22 = F_49 ( V_11 ) ;
if ( V_22 )
F_17 ( L_27 ,
V_11 -> V_14 ) ;
return 0 ;
}
static int F_82 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! V_11 -> V_81 || ! V_11 -> V_97 . V_98 . V_99 )
return - V_15 ;
F_18 ( L_26 , V_11 -> V_14 , V_100 ) ;
if ( F_79 ( V_11 ) )
return 0 ;
F_83 ( V_11 -> V_81 -> V_102 , V_11 -> V_81 -> V_103 ,
V_11 -> V_97 . V_98 . V_104 ) ;
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
int V_86 = 0 ;
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
V_86 = F_12 ( V_11 , & V_22 ) ;
if ( V_86 )
goto V_162;
F_6 ( V_22 , V_11 ) ;
V_86 = F_13 ( V_11 , & V_22 ) ;
if ( V_86 )
goto V_162;
F_6 ( V_22 , V_11 ) ;
if ( V_11 -> V_12 -> V_13 -> V_163 )
F_85 ( V_11 -> V_12 -> V_13 -> V_163 ) ;
V_41 = F_14 ( V_11 ) ;
if ( V_41 == V_45 )
F_34 ( L_30 ,
V_11 -> V_14 , V_45 ) ;
else
F_18 ( L_31 , V_11 -> V_14 , V_41 ) ;
V_86 = ( V_41 == V_45 ) ? - V_164 : 0 ;
V_162:
if ( V_11 -> V_66 & V_129 )
F_44 ( V_11 ) ;
return V_86 ;
}
static int F_86 ( struct V_10 * V_11 )
{
int V_4 , V_165 ;
F_18 ( L_32 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_166 ) {
V_165 = V_11 -> V_12 -> V_166 ( V_11 ) ;
} else {
if ( V_11 -> V_148 > 0 ) {
for ( V_4 = 0 ; V_4 < V_11 -> V_148 ; V_4 ++ )
F_71 ( V_11 , V_11 -> V_150 [ V_4 ] . V_14 ) ;
return 0 ;
} else {
V_165 = F_84 ( V_11 ) ;
if ( V_165 == - V_121 )
V_165 = 0 ;
}
}
F_16 ( V_11 ) ;
if ( V_11 -> V_12 -> V_13 ) {
F_3 ( V_11 ) ;
F_62 ( V_11 ) ;
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
if ( V_11 -> V_97 . V_98 . V_66 & V_168 )
return;
if ( ! F_96 ( V_11 -> V_81 -> V_169 . V_170 -> V_101 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_97 . V_98 . V_172 ) )
return;
V_11 -> V_97 . V_98 . V_173 ++ ;
F_97 ( V_11 -> V_81 -> V_169 . V_170 -> V_101 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_97 . V_98 . V_172 ) ;
}
static int F_98 ( struct V_10 * V_11 )
{
return V_11 -> V_97 . V_98 . V_173 ;
}
static int F_99 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_12 -> V_174 )
return 0 ;
return V_11 -> V_12 -> V_174 ( V_11 ) ;
}
static int F_100 ( struct V_10 * V_11 )
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
if ( F_78 ( V_11 ) )
return 0 ;
if ( V_11 -> V_62 && ( ! V_11 -> V_62 -> V_63 ||
( ( V_11 -> V_49 == V_70 ) &&
V_11 -> V_62 -> V_65 ) ) ) {
F_21 ( V_11 -> V_62 , V_50 ) ;
F_87 () ;
}
F_27 ( V_11 , V_178 ) ;
if ( V_11 -> V_81 ) {
V_155 = F_73 ( V_11 -> V_81 ) &&
! F_101 ( V_11 -> V_81 ) ;
V_165 = F_74 ( V_11 -> V_81 , V_11 ) ;
if ( V_165 ) {
F_4 ( 1 , L_24 ,
V_11 -> V_14 , V_11 -> V_81 -> V_14 , V_165 ) ;
return V_165 ;
}
}
F_38 ( V_11 ) ;
if ( V_144 . V_157 )
V_144 . V_157 ( V_11 ) ;
if ( V_11 -> V_66 & V_179 )
F_102 ( true ) ;
if ( V_144 . V_180 )
V_144 . V_180 ( V_11 ) ;
V_165 = ( V_144 . V_181 ) ? V_144 . V_181 ( V_11 ) :
- V_15 ;
if ( ! V_165 ) {
if ( V_11 -> V_81 && V_155 )
F_75 ( V_11 -> V_81 ) ;
V_11 -> V_49 = V_50 ;
if ( V_11 -> V_12 -> V_13 ) {
if ( ! ( V_11 -> V_20 & V_21 ) )
F_3 ( V_11 ) ;
F_62 ( V_11 ) ;
}
V_165 = F_99 ( V_11 ) ;
} else {
if ( V_144 . V_158 )
V_144 . V_158 ( V_11 ) ;
F_40 ( V_11 ) ;
F_18 ( L_35 ,
V_11 -> V_14 , V_165 ) ;
if ( V_11 -> V_81 )
F_76 ( V_11 -> V_81 , V_11 ) ;
}
return V_165 ;
}
static int F_103 ( struct V_10 * V_11 )
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
F_29 ( V_11 , V_178 ) ;
if ( V_11 -> V_66 & V_179 )
F_102 ( false ) ;
if ( V_144 . V_158 )
V_144 . V_158 ( V_11 ) ;
F_40 ( V_11 ) ;
if ( V_11 -> V_81 )
F_76 ( V_11 -> V_81 , V_11 ) ;
if ( V_11 -> V_62 && V_11 -> V_62 -> V_65 ) {
F_21 ( V_11 -> V_62 , V_70 ) ;
F_87 () ;
}
V_11 -> V_49 = V_70 ;
return 0 ;
}
static int F_104 ( struct V_10 * V_11 )
{
int V_86 , V_4 ;
T_2 V_182 ;
if ( V_11 -> V_49 != V_70 &&
V_11 -> V_49 != V_50 ) {
F_4 ( 1 , L_38 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_78 ( V_11 ) )
return 0 ;
F_18 ( L_39 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_183 ) {
V_182 = V_11 -> V_49 ;
if ( V_11 -> V_49 == V_70 )
F_100 ( V_11 ) ;
V_86 = V_11 -> V_12 -> V_183 ( V_11 ) ;
if ( V_86 ) {
if ( V_182 == V_70 )
F_103 ( V_11 ) ;
return V_86 ;
}
}
if ( V_11 -> V_12 -> V_13 ) {
if ( V_11 -> V_49 == V_70 )
F_100 ( V_11 ) ;
F_64 ( V_11 ) ;
}
if ( V_11 -> V_49 == V_50 ) {
F_29 ( V_11 , V_178 ) ;
if ( V_11 -> V_66 & V_179 )
F_102 ( false ) ;
if ( V_144 . V_158 )
V_144 . V_158 ( V_11 ) ;
F_40 ( V_11 ) ;
if ( V_11 -> V_81 )
F_76 ( V_11 -> V_81 , V_11 ) ;
}
for ( V_4 = 0 ; V_4 < V_11 -> V_148 ; V_4 ++ )
F_71 ( V_11 , V_11 -> V_150 [ V_4 ] . V_14 ) ;
if ( V_11 -> V_62 )
F_21 ( V_11 -> V_62 , V_177 ) ;
V_11 -> V_49 = V_177 ;
return 0 ;
}
static int F_105 ( struct V_184 * V_185 ,
struct V_10 * V_11 )
{
int V_186 , V_4 , V_187 ;
const char * V_3 ;
V_186 = F_106 ( V_185 , L_40 ) ;
if ( V_186 < 1 )
return - V_188 ;
for ( V_4 = 0 ; V_4 < V_186 ; V_4 ++ ) {
V_187 = F_107 ( V_185 , L_40 ,
V_4 , & V_3 ) ;
if ( V_187 )
continue;
if ( ! strcmp ( V_3 , V_11 -> V_14 ) ) {
F_18 ( L_41 ,
V_185 -> V_14 , V_4 , V_11 -> V_14 ) ;
return V_4 ;
}
}
return - V_188 ;
}
static int F_108 ( struct V_184 * V_185 ,
struct V_10 * V_11 ,
int * V_189 ,
struct V_184 * * V_120 )
{
struct V_184 * V_190 = NULL ;
int V_187 ;
V_187 = F_105 ( V_185 , V_11 ) ;
if ( V_187 >= 0 ) {
* V_120 = V_185 ;
* V_189 = V_187 ;
return 0 ;
}
F_109 (np, np0) {
struct V_184 * V_191 ;
int V_4 ;
V_187 = F_108 ( V_190 , V_11 , & V_4 , & V_191 ) ;
if ( V_187 == 0 ) {
* V_120 = V_191 ;
* V_189 = V_4 ;
return 0 ;
}
}
* V_120 = NULL ;
* V_189 = 0 ;
return - V_188 ;
}
static int T_4 F_110 ( struct V_10 * V_11 , void * V_142 ,
int V_189 , struct V_184 * V_185 )
{
struct V_115 * V_116 ;
void T_5 * va_start = NULL ;
if ( ! V_11 )
return - V_15 ;
F_59 ( V_11 ) ;
if ( V_11 -> V_20 & V_105 )
return - V_192 ;
V_116 = F_61 ( V_11 ) ;
if ( ! V_116 ) {
F_18 ( L_42 ,
V_11 -> V_14 ) ;
if ( ! V_185 )
return - V_192 ;
va_start = F_111 ( V_185 , V_189 + V_11 -> V_193 ) ;
} else {
va_start = F_112 ( V_116 -> V_118 , V_116 -> V_119 - V_116 -> V_118 ) ;
}
if ( ! va_start ) {
if ( V_116 )
F_113 ( L_43 , V_11 -> V_14 ) ;
else
F_113 ( L_44 ,
V_11 -> V_14 , V_189 , V_185 -> V_194 ) ;
return - V_192 ;
}
F_18 ( L_45 ,
V_11 -> V_14 , va_start ) ;
V_11 -> V_195 = va_start ;
return 0 ;
}
static int T_4 F_114 ( struct V_10 * V_11 , void * V_142 )
{
int V_165 , V_189 ;
struct V_184 * V_185 = NULL ;
if ( V_11 -> V_49 != V_143 )
return 0 ;
if ( F_115 () ) {
struct V_184 * V_196 ;
V_196 = F_116 ( NULL , L_46 ) ;
if ( ! V_196 )
return - V_188 ;
V_165 = F_108 ( V_196 , V_11 , & V_189 , & V_185 ) ;
if ( V_165 )
F_18 ( L_47 , V_11 -> V_14 ) ;
else if ( V_185 && V_189 )
F_17 ( L_48 ,
V_11 -> V_14 , V_185 -> V_14 ) ;
}
if ( V_11 -> V_12 -> V_13 ) {
V_165 = F_110 ( V_11 , NULL , V_189 , V_185 ) ;
if ( V_165 < 0 ) {
F_4 ( 1 , L_49 ,
V_11 -> V_14 ) ;
return 0 ;
}
}
V_165 = F_69 ( V_11 , NULL ) ;
if ( V_165 < 0 ) {
F_4 ( 1 , L_50 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_185 )
if ( F_117 ( V_185 , L_51 , NULL ) )
V_11 -> V_66 |= V_197 ;
if ( F_117 ( V_185 , L_52 , NULL ) )
V_11 -> V_66 |= V_198 ;
V_11 -> V_49 = V_176 ;
return 0 ;
}
static void T_4 F_118 ( struct V_10 * V_11 )
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
F_39 ( V_88 -> V_82 ) ;
}
}
return;
}
static int T_4 F_119 ( struct V_10 * V_11 )
{
int V_165 ;
if ( V_11 -> V_49 != V_176 )
return - V_15 ;
if ( V_11 -> V_66 & V_199 )
return - V_200 ;
if ( V_11 -> V_148 == 0 ) {
V_165 = F_100 ( V_11 ) ;
if ( V_165 ) {
F_34 ( L_53 ,
V_11 -> V_14 , V_11 -> V_49 ) ;
return - V_15 ;
}
}
if ( ! ( V_11 -> V_66 & V_197 ) )
V_165 = F_86 ( V_11 ) ;
return V_165 ;
}
static void T_4 F_120 ( struct V_10 * V_11 )
{
T_2 V_201 ;
if ( V_11 -> V_148 > 0 )
return;
V_201 = V_11 -> V_202 ;
if ( V_201 == V_203 )
V_201 = V_50 ;
if ( ( V_11 -> V_66 & V_198 ) &&
( V_201 == V_70 ) ) {
V_11 -> V_20 |= V_175 ;
V_201 = V_50 ;
}
if ( V_201 == V_70 )
F_103 ( V_11 ) ;
else if ( V_201 == V_177 )
F_104 ( V_11 ) ;
else if ( V_201 != V_50 )
F_4 ( 1 , L_54 ,
V_11 -> V_14 , V_201 ) ;
return;
}
static int T_4 F_121 ( struct V_10 * V_11 , void * V_142 )
{
if ( V_11 -> V_49 != V_176 )
return 0 ;
F_118 ( V_11 ) ;
if ( ! F_119 ( V_11 ) )
F_120 ( V_11 ) ;
return 0 ;
}
static int T_4 F_122 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_14 || ! V_11 -> V_12 || ! V_11 -> V_12 -> V_14 ||
( V_11 -> V_49 != V_203 ) )
return - V_15 ;
F_18 ( L_55 , V_11 -> V_14 ) ;
if ( F_65 ( V_11 -> V_14 ) )
return - V_204 ;
F_123 ( & V_11 -> V_7 , & V_205 ) ;
F_124 ( & V_11 -> V_206 ) ;
F_124 ( & V_11 -> V_89 ) ;
F_125 ( & V_11 -> V_207 ) ;
V_11 -> V_49 = V_143 ;
if ( ! strcmp ( V_11 -> V_14 , V_208 ) )
V_178 = V_11 ;
return 0 ;
}
static int T_4 F_126 ( struct V_6 * * V_209 ,
struct V_6 * * V_210 )
{
unsigned int V_211 ;
if ( ( V_212 + V_213 ) <= V_214 ) {
* V_209 = & V_215 [ V_212 ++ ] ;
* V_210 = & V_215 [ V_212 ++ ] ;
return 0 ;
}
V_211 = sizeof( struct V_6 ) * V_213 ;
* V_210 = NULL ;
* V_209 = F_127 ( V_211 ) ;
memset ( * V_209 , 0 , V_211 ) ;
* V_210 = ( void * ) ( * V_209 ) + sizeof( struct V_6 ) ;
V_216 ++ ;
F_18 ( L_56 ,
V_216 * V_213 ) ;
return 0 ;
}
static int T_4 F_128 ( struct V_1 * V_5 )
{
struct V_6 * V_209 , * V_210 ;
F_18 ( L_57 , V_5 -> V_217 -> V_14 ,
V_5 -> V_218 -> V_14 ) ;
F_126 ( & V_209 , & V_210 ) ;
V_209 -> V_8 = V_5 ;
F_124 ( & V_209 -> V_7 ) ;
F_129 ( & V_209 -> V_7 , & V_5 -> V_217 -> V_206 ) ;
V_5 -> V_217 -> V_219 ++ ;
V_210 -> V_8 = V_5 ;
F_124 ( & V_210 -> V_7 ) ;
F_129 ( & V_210 -> V_7 , & V_5 -> V_218 -> V_89 ) ;
V_5 -> V_218 -> V_90 ++ ;
return 0 ;
}
static int T_4 F_130 ( struct V_1 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_217 || ! V_5 -> V_218 || ! V_5 -> V_123 )
return - V_15 ;
if ( V_5 -> V_20 & V_220 )
return - V_204 ;
F_18 ( L_58 ,
V_5 -> V_217 -> V_14 , V_5 -> V_218 -> V_14 ) ;
if ( V_5 -> V_217 -> V_49 != V_143 )
F_122 ( V_5 -> V_217 ) ;
if ( V_5 -> V_218 -> V_49 != V_143 )
F_122 ( V_5 -> V_218 ) ;
F_128 ( V_5 ) ;
V_5 -> V_20 |= V_220 ;
return 0 ;
}
static int T_4 F_131 ( struct V_1 * * V_221 )
{
unsigned int V_4 = 0 ;
unsigned int V_211 ;
if ( V_215 ) {
F_4 ( 1 , L_59 ) ;
return - V_204 ;
}
if ( V_214 == 0 )
while ( V_221 [ V_4 ++ ] )
V_214 += V_213 ;
V_211 = sizeof( struct V_6 ) * V_214 ;
F_18 ( L_60 ,
V_100 , V_211 , V_214 ) ;
V_215 = F_127 ( V_211 ) ;
memset ( V_215 , 0 , V_211 ) ;
return 0 ;
}
static int F_132 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_106 )
return 0 ;
if ( ! F_60 ( V_11 ) )
return 0 ;
return F_133 ( V_11 -> V_97 . V_222 . V_223 ,
V_11 -> V_97 . V_222 . V_224 ,
V_11 -> V_97 . V_222 . V_225 ) ;
}
static int F_134 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_106 )
return 0 ;
if ( ! F_60 ( V_11 ) )
return 0 ;
return F_135 ( V_11 -> V_97 . V_222 . V_223 ,
V_11 -> V_97 . V_222 . V_224 ,
V_11 -> V_97 . V_222 . V_225 ) ;
}
static int F_136 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_66 & V_106 || ! V_11 -> V_81 )
return 0 ;
if ( ! F_60 ( V_11 ) )
return 0 ;
return F_137 ( V_11 -> V_81 -> V_101 ,
V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_97 . V_98 . V_104 ) ;
}
static int F_138 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_81 )
return - V_15 ;
if ( V_11 -> V_66 & V_106 )
return 0 ;
if ( ! F_60 ( V_11 ) )
return 0 ;
return F_139 ( V_11 -> V_81 -> V_102 ,
V_11 -> V_81 -> V_103 ,
V_11 -> V_97 . V_98 . V_104 ) ;
}
static int F_140 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_141 ( V_11 -> V_97 . V_222 . V_223 ,
V_147 -> V_151 ) ;
}
static int F_142 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_143 ( V_11 -> V_97 . V_222 . V_223 ,
V_147 -> V_151 ,
V_147 -> V_152 ) ;
}
static int F_144 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_145 ( V_11 -> V_97 . V_222 . V_223 ,
V_147 -> V_152 ) ;
}
static int F_146 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
return F_147 ( V_147 -> V_151 ,
V_11 -> V_81 -> V_169 . V_170 -> V_101 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_97 . V_98 . V_226 ) ;
}
static int F_148 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
if ( V_147 -> V_152 )
F_113 ( L_61 ,
V_11 -> V_14 , V_147 -> V_14 ) ;
return F_149 ( V_147 -> V_151 ,
V_11 -> V_81 -> V_169 . V_170 -> V_101 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_97 . V_98 . V_226 ) ;
}
static int F_150 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
if ( ! V_11 -> V_81 )
return - V_15 ;
return F_151 ( V_147 -> V_151 ,
V_11 -> V_81 -> V_169 . V_170 -> V_101 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_97 . V_98 . V_226 ) ;
}
static int F_152 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_153 ( V_147 -> V_151 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_97 . V_98 . V_226 ) ;
}
static int F_154 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_155 ( V_147 -> V_151 ,
V_147 -> V_152 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_97 . V_98 . V_226 ,
V_11 -> V_97 . V_98 . V_227 ) ;
}
static int F_156 ( struct V_10 * V_11 ,
struct V_146 * V_147 )
{
return F_157 ( V_147 -> V_151 ,
V_11 -> V_81 -> V_169 . V_170 -> V_171 ,
V_11 -> V_97 . V_98 . V_226 ) ;
}
T_1 F_5 ( struct V_10 * V_11 , T_3 V_228 )
{
if ( V_11 -> V_66 & V_229 )
return F_158 ( V_11 -> V_195 + V_228 ) ;
else
return F_159 ( V_11 -> V_195 + V_228 ) ;
}
void F_7 ( T_1 V_22 , struct V_10 * V_11 , T_3 V_228 )
{
if ( V_11 -> V_66 & V_229 )
F_160 ( V_22 , V_11 -> V_195 + V_228 ) ;
else
F_161 ( V_22 , V_11 -> V_195 + V_228 ) ;
}
int F_162 ( struct V_10 * V_11 )
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
V_86 = F_13 ( V_11 , & V_22 ) ;
if ( V_86 )
goto error;
F_6 ( V_22 , V_11 ) ;
error:
return V_86 ;
}
struct V_10 * F_163 ( const char * V_14 )
{
struct V_10 * V_11 ;
if ( ! V_14 )
return NULL ;
V_11 = F_65 ( V_14 ) ;
return V_11 ;
}
int F_164 ( int (* F_165)( struct V_10 * V_11 , void * V_142 ) ,
void * V_142 )
{
struct V_10 * V_140 ;
int V_86 = 0 ;
if ( ! F_165 )
return - V_15 ;
F_66 (temp_oh, &omap_hwmod_list, node) {
V_86 = (* F_165)( V_140 , V_142 ) ;
if ( V_86 )
break;
}
return V_86 ;
}
int T_4 F_166 ( struct V_1 * * V_221 )
{
int V_165 , V_4 ;
if ( ! V_230 )
return - V_15 ;
if ( ! V_221 )
return 0 ;
if ( ! V_215 ) {
if ( F_131 ( V_221 ) ) {
F_113 ( L_62 ) ;
return - V_231 ;
}
}
V_4 = 0 ;
do {
V_165 = F_130 ( V_221 [ V_4 ] ) ;
F_4 ( V_165 && V_165 != - V_204 ,
L_63 ,
V_221 [ V_4 ] -> V_217 -> V_14 , V_221 [ V_4 ] -> V_218 -> V_14 , V_165 ) ;
} while ( V_221 [ ++ V_4 ] );
return 0 ;
}
static void T_4 F_167 ( struct V_10 * V_11 )
{
if ( ! V_178 || V_178 -> V_49 == V_203 )
F_113 ( L_64 ,
V_100 , V_208 ) ;
else if ( V_178 -> V_49 == V_143 && V_11 != V_178 )
F_168 ( V_208 ) ;
}
int T_4 F_168 ( const char * V_232 )
{
struct V_10 * V_11 ;
F_18 ( L_26 , V_232 , V_100 ) ;
V_11 = F_65 ( V_232 ) ;
if ( ! V_11 ) {
F_4 ( 1 , L_65 , V_232 ) ;
return - V_15 ;
}
F_167 ( V_11 ) ;
F_114 ( V_11 , NULL ) ;
F_121 ( V_11 , NULL ) ;
return 0 ;
}
static int T_4 F_169 ( void )
{
F_167 ( NULL ) ;
F_164 ( F_114 , NULL ) ;
F_164 ( F_121 , NULL ) ;
return 0 ;
}
int F_170 ( struct V_10 * V_11 )
{
int V_165 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_207 , V_66 ) ;
V_165 = F_100 ( V_11 ) ;
F_94 ( & V_11 -> V_207 , V_66 ) ;
return V_165 ;
}
int F_171 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_207 , V_66 ) ;
F_103 ( V_11 ) ;
F_94 ( & V_11 -> V_207 , V_66 ) ;
return 0 ;
}
int F_172 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_207 , V_66 ) ;
F_104 ( V_11 ) ;
F_94 ( & V_11 -> V_207 , V_66 ) ;
return 0 ;
}
int F_173 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
F_88 ( & V_11 -> V_207 , V_66 ) ;
F_38 ( V_11 ) ;
F_94 ( & V_11 -> V_207 , V_66 ) ;
return 0 ;
}
int F_174 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
F_88 ( & V_11 -> V_207 , V_66 ) ;
F_40 ( V_11 ) ;
F_94 ( & V_11 -> V_207 , V_66 ) ;
return 0 ;
}
void F_175 ( struct V_10 * V_11 )
{
F_176 ( ! V_11 ) ;
if ( ! V_11 -> V_12 -> V_13 || ! V_11 -> V_12 -> V_13 -> V_18 ) {
F_4 ( 1 , L_66 ,
V_11 -> V_14 ) ;
return;
}
F_5 ( V_11 , V_11 -> V_12 -> V_13 -> V_17 ) ;
}
int F_177 ( struct V_10 * V_11 )
{
int V_165 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_207 , V_66 ) ;
V_165 = F_86 ( V_11 ) ;
F_94 ( & V_11 -> V_207 , V_66 ) ;
return V_165 ;
}
int F_178 ( struct V_10 * V_11 , unsigned long V_66 )
{
int V_86 = 0 ;
if ( V_66 & V_233 )
V_86 += F_53 ( V_11 ) ;
if ( V_66 & V_234 )
V_86 += F_54 ( V_11 ) ;
if ( V_66 & V_235 ) {
int V_4 = 0 ;
struct V_1 * V_88 ;
struct V_2 * V_3 = V_11 -> V_89 . V_9 ;
while ( V_4 < V_11 -> V_90 ) {
V_88 = F_1 ( & V_3 , & V_4 ) ;
V_86 += F_55 ( V_88 ) ;
}
}
return V_86 ;
}
int F_179 ( struct V_10 * V_11 , struct V_236 * V_187 )
{
struct V_1 * V_88 ;
struct V_2 * V_3 ;
int V_4 , V_61 , V_237 , V_238 , V_239 ;
int V_165 = 0 ;
V_237 = F_53 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_237 ; V_4 ++ ) {
( V_187 + V_165 ) -> V_14 = ( V_11 -> V_109 + V_4 ) -> V_14 ;
( V_187 + V_165 ) -> V_240 = ( V_11 -> V_109 + V_4 ) -> V_110 ;
( V_187 + V_165 ) -> V_241 = ( V_11 -> V_109 + V_4 ) -> V_110 ;
( V_187 + V_165 ) -> V_66 = V_233 ;
V_165 ++ ;
}
V_238 = F_54 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_238 ; V_4 ++ ) {
( V_187 + V_165 ) -> V_14 = ( V_11 -> V_113 + V_4 ) -> V_14 ;
( V_187 + V_165 ) -> V_240 = ( V_11 -> V_113 + V_4 ) -> V_114 ;
( V_187 + V_165 ) -> V_241 = ( V_11 -> V_113 + V_4 ) -> V_114 ;
( V_187 + V_165 ) -> V_66 = V_234 ;
V_165 ++ ;
}
V_3 = V_11 -> V_89 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_90 ) {
V_88 = F_1 ( & V_3 , & V_4 ) ;
V_239 = F_55 ( V_88 ) ;
for ( V_61 = 0 ; V_61 < V_239 ; V_61 ++ ) {
( V_187 + V_165 ) -> V_14 = ( V_88 -> V_117 + V_61 ) -> V_14 ;
( V_187 + V_165 ) -> V_240 = ( V_88 -> V_117 + V_61 ) -> V_118 ;
( V_187 + V_165 ) -> V_241 = ( V_88 -> V_117 + V_61 ) -> V_119 ;
( V_187 + V_165 ) -> V_66 = V_235 ;
V_165 ++ ;
}
}
return V_165 ;
}
int F_180 ( struct V_10 * V_11 , struct V_236 * V_187 )
{
int V_4 , V_238 ;
int V_165 = 0 ;
V_238 = F_54 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_238 ; V_4 ++ ) {
( V_187 + V_165 ) -> V_14 = ( V_11 -> V_113 + V_4 ) -> V_14 ;
( V_187 + V_165 ) -> V_240 = ( V_11 -> V_113 + V_4 ) -> V_114 ;
( V_187 + V_165 ) -> V_241 = ( V_11 -> V_113 + V_4 ) -> V_114 ;
( V_187 + V_165 ) -> V_66 = V_234 ;
V_165 ++ ;
}
return V_165 ;
}
int F_181 ( struct V_10 * V_11 , unsigned int type ,
const char * V_14 , struct V_236 * V_242 )
{
int V_165 ;
unsigned int V_110 , V_122 ;
T_1 V_118 , V_119 ;
if ( ! V_11 || ! V_242 )
return - V_15 ;
if ( type == V_233 ) {
V_165 = F_56 ( V_11 , V_14 , & V_110 ) ;
if ( V_165 )
return V_165 ;
V_242 -> V_240 = V_110 ;
V_242 -> V_241 = V_110 ;
} else if ( type == V_234 ) {
V_165 = F_57 ( V_11 , V_14 , & V_122 ) ;
if ( V_165 )
return V_165 ;
V_242 -> V_240 = V_122 ;
V_242 -> V_241 = V_122 ;
} else if ( type == V_235 ) {
V_165 = F_58 ( V_11 , V_14 , & V_118 , & V_119 ) ;
if ( V_165 )
return V_165 ;
V_242 -> V_240 = V_118 ;
V_242 -> V_241 = V_119 ;
} else {
return - V_15 ;
}
V_242 -> V_66 = type ;
V_242 -> V_14 = V_14 ;
return 0 ;
}
struct V_243 * F_182 ( struct V_10 * V_11 )
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
V_5 = F_60 ( V_11 ) ;
if ( ! V_5 )
return NULL ;
V_41 = V_5 -> V_82 ;
}
V_80 = F_25 ( F_26 ( V_41 ) ) ;
V_81 = V_80 -> V_81 ;
if ( ! V_81 )
return NULL ;
return V_81 -> V_169 . V_170 ;
}
void T_5 * F_183 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_20 & V_105 )
return NULL ;
if ( V_11 -> V_49 == V_203 )
return NULL ;
return V_11 -> V_195 ;
}
int F_184 ( struct V_10 * V_11 ,
struct V_10 * V_83 )
{
return F_27 ( V_11 , V_83 ) ;
}
int F_185 ( struct V_10 * V_11 ,
struct V_10 * V_83 )
{
return F_29 ( V_11 , V_83 ) ;
}
int F_186 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
T_1 V_22 ;
F_88 ( & V_11 -> V_207 , V_66 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ) {
V_22 = V_11 -> V_16 ;
F_22 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_20 ( V_11 , true ) ;
F_94 ( & V_11 -> V_207 , V_66 ) ;
return 0 ;
}
int F_187 ( struct V_10 * V_11 )
{
unsigned long V_66 ;
T_1 V_22 ;
F_88 ( & V_11 -> V_207 , V_66 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_71 ) ) {
V_22 = V_11 -> V_16 ;
F_23 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_20 ( V_11 , false ) ;
F_94 ( & V_11 -> V_207 , V_66 ) ;
return 0 ;
}
int F_188 ( struct V_10 * V_11 , const char * V_14 )
{
int V_86 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_207 , V_66 ) ;
V_86 = F_71 ( V_11 , V_14 ) ;
F_94 ( & V_11 -> V_207 , V_66 ) ;
return V_86 ;
}
int F_189 ( struct V_10 * V_11 , const char * V_14 )
{
int V_86 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_207 , V_66 ) ;
V_86 = F_72 ( V_11 , V_14 ) ;
F_94 ( & V_11 -> V_207 , V_66 ) ;
return V_86 ;
}
int F_190 ( struct V_10 * V_11 , const char * V_14 )
{
int V_86 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
F_88 ( & V_11 -> V_207 , V_66 ) ;
V_86 = F_77 ( V_11 , V_14 ) ;
F_94 ( & V_11 -> V_207 , V_66 ) ;
return V_86 ;
}
int F_191 ( const char * V_244 ,
int (* F_165)( struct V_10 * V_11 ,
void * V_123 ) ,
void * V_123 )
{
struct V_10 * V_140 ;
int V_86 = 0 ;
if ( ! V_244 || ! F_165 )
return - V_15 ;
F_18 ( L_67 ,
V_100 , V_244 ) ;
F_66 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_140 -> V_12 -> V_14 , V_244 ) ) {
F_18 ( L_68 ,
V_100 , V_140 -> V_14 ) ;
V_86 = (* F_165)( V_140 , V_123 ) ;
if ( V_86 )
break;
}
}
if ( V_86 )
F_18 ( L_69 ,
V_100 , V_86 ) ;
return V_86 ;
}
int F_192 ( struct V_10 * V_11 , T_2 V_245 )
{
int V_86 ;
unsigned long V_66 ;
if ( ! V_11 )
return - V_15 ;
if ( V_245 != V_177 &&
V_245 != V_50 &&
V_245 != V_70 )
return - V_15 ;
F_88 ( & V_11 -> V_207 , V_66 ) ;
if ( V_11 -> V_49 != V_143 ) {
V_86 = - V_15 ;
goto V_246;
}
V_11 -> V_202 = V_245 ;
V_86 = 0 ;
V_246:
F_94 ( & V_11 -> V_207 , V_66 ) ;
return V_86 ;
}
int F_193 ( struct V_10 * V_11 )
{
struct V_243 * V_169 ;
int V_86 = 0 ;
if ( V_144 . V_247 )
return V_144 . V_247 ( V_11 ) ;
V_169 = F_182 ( V_11 ) ;
if ( V_169 )
V_86 = F_194 ( V_169 ) ;
return V_86 ;
}
int F_195 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_49 != V_143 ) {
F_113 ( L_70 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_66 |= V_197 ;
return 0 ;
}
int F_196 ( struct V_10 * V_11 , int V_248 , int V_249 )
{
int V_250 ;
F_197 () ;
if ( ! V_11 || ! V_11 -> V_62 || ! V_11 -> V_109 || V_248 < 0 ||
V_248 >= V_11 -> V_62 -> V_64 )
return - V_15 ;
for ( V_250 = 0 ; V_11 -> V_109 [ V_250 ] . V_110 >= 0 ; V_250 ++ )
;
if ( V_249 >= V_250 )
return - V_15 ;
if ( ! V_11 -> V_62 -> V_251 ) {
V_11 -> V_62 -> V_251 = F_198 ( sizeof( int ) * V_11 -> V_62 -> V_64 ,
V_252 ) ;
if ( ! V_11 -> V_62 -> V_251 )
return - V_231 ;
}
V_11 -> V_62 -> V_251 [ V_248 ] = V_249 ;
return 0 ;
}
void T_4 F_199 ( void )
{
if ( F_200 () ) {
V_144 . V_181 = F_132 ;
V_144 . V_153 = F_140 ;
V_144 . V_156 = F_142 ;
V_144 . V_160 = F_144 ;
} else if ( F_89 () ) {
V_144 . V_181 = F_134 ;
V_144 . V_153 = F_140 ;
V_144 . V_156 = F_142 ;
V_144 . V_160 = F_144 ;
} else if ( F_92 () || F_201 () || F_202 () ) {
V_144 . V_157 = F_45 ;
V_144 . V_158 = F_80 ;
V_144 . V_181 = F_136 ;
V_144 . V_153 = F_146 ;
V_144 . V_156 = F_148 ;
V_144 . V_160 = F_150 ;
V_144 . V_84 = F_67 ;
V_144 . V_180 = F_95 ;
V_144 . V_247 = F_98 ;
} else if ( F_203 () ) {
V_144 . V_157 = F_45 ;
V_144 . V_158 = F_80 ;
V_144 . V_181 = F_136 ;
V_144 . V_153 = F_146 ;
V_144 . V_156 = F_148 ;
V_144 . V_160 = F_150 ;
V_144 . V_84 = F_67 ;
} else if ( F_204 () ) {
V_144 . V_157 = F_47 ;
V_144 . V_158 = F_82 ;
V_144 . V_181 = F_138 ;
V_144 . V_153 = F_152 ;
V_144 . V_156 = F_154 ;
V_144 . V_160 = F_156 ;
V_144 . V_84 = F_67 ;
} else {
F_4 ( 1 , L_71 ) ;
}
V_230 = true ;
}
const char * F_205 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
return V_11 -> V_87 ;
}
