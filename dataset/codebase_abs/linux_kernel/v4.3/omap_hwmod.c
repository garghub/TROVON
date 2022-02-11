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
if ( V_11 -> V_12 -> V_23 )
V_11 -> V_12 -> V_23 ( V_11 ) ;
F_7 ( V_22 , V_11 , V_11 -> V_12 -> V_13 -> V_17 ) ;
if ( V_11 -> V_12 -> V_24 )
V_11 -> V_12 -> V_24 ( V_11 ) ;
}
static int F_8 ( struct V_10 * V_11 , T_2 V_25 ,
T_1 * V_22 )
{
T_1 V_26 ;
T_2 V_27 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_28 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_29 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_27 = V_11 -> V_12 -> V_13 -> V_29 -> V_30 ;
V_26 = ( 0x3 << V_27 ) ;
* V_22 &= ~ V_26 ;
* V_22 |= F_9 ( V_25 ) << V_27 ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 , T_2 V_31 , T_1 * V_22 )
{
T_1 V_32 ;
T_2 V_33 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_34 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_29 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_33 = V_11 -> V_12 -> V_13 -> V_29 -> V_33 ;
V_32 = ( 0x3 << V_33 ) ;
* V_22 &= ~ V_32 ;
* V_22 |= F_9 ( V_31 ) << V_33 ;
return 0 ;
}
static int F_11 ( struct V_10 * V_11 , T_2 V_35 , T_1 * V_22 )
{
T_1 V_36 ;
T_2 V_37 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_38 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_29 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_37 = V_11 -> V_12 -> V_13 -> V_29 -> V_37 ;
V_36 = ( 0x3 << V_37 ) ;
* V_22 &= ~ V_36 ;
* V_22 |= V_35 << V_37 ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 , T_1 * V_22 )
{
T_1 V_39 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_40 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_29 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_39 = ( 0x1 << V_11 -> V_12 -> V_13 -> V_29 -> V_41 ) ;
* V_22 |= V_39 ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 , T_1 * V_22 )
{
T_1 V_39 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_40 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_29 ) {
F_4 ( 1 ,
L_4 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
V_39 = ( 0x1 << V_11 -> V_12 -> V_13 -> V_29 -> V_41 ) ;
* V_22 &= ~ V_39 ;
return 0 ;
}
static int F_14 ( struct V_10 * V_11 )
{
struct V_42 * V_13 ;
T_1 V_39 ;
int V_43 = 0 ;
V_13 = V_11 -> V_12 -> V_13 ;
if ( V_13 -> V_18 & V_44 )
F_15 ( ( F_5 ( V_11 , V_13 -> V_45 )
& V_46 ) ,
V_47 , V_43 ) ;
else if ( V_13 -> V_18 & V_48 ) {
V_39 = ( 0x1 << V_13 -> V_29 -> V_41 ) ;
F_15 ( ! ( F_5 ( V_11 , V_13 -> V_17 )
& V_39 ) ,
V_47 , V_43 ) ;
}
return V_43 ;
}
static int F_16 ( struct V_10 * V_11 )
{
T_1 V_22 ;
T_1 V_49 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_50 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_29 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_51 != V_52 ) {
F_17 ( L_5 , V_11 -> V_14 ) ;
return - V_15 ;
}
F_18 ( L_6 , V_11 -> V_14 ) ;
V_22 = V_11 -> V_16 ;
V_49 =
( 0x1 << V_11 -> V_12 -> V_13 -> V_29 -> V_53 ) ;
V_22 |= V_49 ;
F_6 ( V_22 , V_11 ) ;
return 0 ;
}
static int F_19 ( struct V_10 * V_11 , T_2 V_54 ,
T_1 * V_22 )
{
T_1 V_55 ;
T_2 V_56 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_57 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_29 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_56 = V_11 -> V_12 -> V_13 -> V_29 -> V_56 ;
V_55 = ( 0x1 << V_56 ) ;
* V_22 &= ~ V_55 ;
* V_22 |= V_54 << V_56 ;
return 0 ;
}
static void F_20 ( struct V_10 * V_11 , bool V_58 )
{
struct V_59 * V_60 ;
bool V_61 = false ;
T_3 V_62 ;
int V_63 ;
if ( ! V_11 -> V_64 || ! V_11 -> V_64 -> V_65 )
return;
for ( V_63 = 0 ; V_63 < V_11 -> V_64 -> V_66 ; V_63 ++ ) {
V_60 = V_11 -> V_64 -> V_67 [ V_63 ] ;
if ( ! ( V_60 -> V_68 & V_69 ) )
continue;
V_62 = V_60 -> V_70 ;
if ( V_58 )
V_60 -> V_70 |= V_71 ;
else
V_60 -> V_70 &= ~ V_71 ;
if ( V_62 != V_60 -> V_70 )
V_61 = true ;
}
if ( V_61 && V_11 -> V_51 == V_72 )
F_21 ( V_11 -> V_64 , V_72 ) ;
}
static int F_22 ( struct V_10 * V_11 , T_1 * V_22 )
{
if ( ! V_11 -> V_12 -> V_13 ||
! ( ( V_11 -> V_12 -> V_13 -> V_18 & V_73 ) ||
( V_11 -> V_12 -> V_13 -> V_74 & V_75 ) ||
( V_11 -> V_12 -> V_13 -> V_74 & V_76 ) ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_29 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_12 -> V_13 -> V_18 & V_73 )
* V_22 |= 0x1 << V_11 -> V_12 -> V_13 -> V_29 -> V_77 ;
if ( V_11 -> V_12 -> V_13 -> V_74 & V_75 )
F_10 ( V_11 , V_78 , V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_74 & V_76 )
F_8 ( V_11 , V_78 , V_22 ) ;
return 0 ;
}
static int F_23 ( struct V_10 * V_11 , T_1 * V_22 )
{
if ( ! V_11 -> V_12 -> V_13 ||
! ( ( V_11 -> V_12 -> V_13 -> V_18 & V_73 ) ||
( V_11 -> V_12 -> V_13 -> V_74 & V_75 ) ||
( V_11 -> V_12 -> V_13 -> V_74 & V_76 ) ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_29 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_12 -> V_13 -> V_18 & V_73 )
* V_22 &= ~ ( 0x1 << V_11 -> V_12 -> V_13 -> V_29 -> V_77 ) ;
if ( V_11 -> V_12 -> V_13 -> V_74 & V_75 )
F_10 ( V_11 , V_79 , V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_74 & V_76 )
F_8 ( V_11 , V_79 , V_22 ) ;
return 0 ;
}
static struct V_80 * F_24 ( struct V_10 * V_11 )
{
struct V_81 * V_82 ;
if ( V_11 -> V_83 ) {
return V_11 -> V_83 ;
} else if ( V_11 -> V_84 ) {
if ( F_25 ( V_11 -> V_84 ) & V_85 )
return NULL ;
V_82 = F_26 ( F_27 ( V_11 -> V_84 ) ) ;
return V_82 -> V_83 ;
}
return NULL ;
}
static int F_28 ( struct V_10 * V_11 , struct V_10 * V_86 )
{
struct V_80 * V_83 , * V_87 ;
V_83 = F_24 ( V_11 ) ;
V_87 = F_24 ( V_86 ) ;
if ( ! V_83 || ! V_87 )
return - V_15 ;
if ( V_83 && V_83 -> V_68 & V_88 )
return 0 ;
return F_29 ( V_83 , V_87 ) ;
}
static int F_30 ( struct V_10 * V_11 , struct V_10 * V_86 )
{
struct V_80 * V_83 , * V_87 ;
V_83 = F_24 ( V_11 ) ;
V_87 = F_24 ( V_86 ) ;
if ( ! V_83 || ! V_87 )
return - V_15 ;
if ( V_83 && V_83 -> V_68 & V_88 )
return 0 ;
return F_31 ( V_83 , V_87 ) ;
}
static int F_32 ( struct V_10 * V_11 )
{
int V_89 = 0 ;
if ( ! V_11 -> V_90 )
return 0 ;
V_11 -> V_84 = F_33 ( NULL , V_11 -> V_90 ) ;
if ( F_34 ( V_11 -> V_84 ) ) {
F_17 ( L_7 ,
V_11 -> V_14 , V_11 -> V_90 ) ;
return - V_15 ;
}
F_35 ( V_11 -> V_84 ) ;
if ( ! F_24 ( V_11 ) )
F_18 ( L_8 ,
V_11 -> V_14 , V_11 -> V_90 ) ;
return V_89 ;
}
static int F_36 ( struct V_10 * V_11 )
{
struct V_1 * V_91 ;
struct V_2 * V_3 ;
struct V_82 * V_43 ;
int V_4 = 0 ;
int V_89 = 0 ;
V_3 = V_11 -> V_92 . V_9 ;
while ( V_4 < V_11 -> V_93 ) {
V_91 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_91 -> V_82 )
continue;
V_43 = F_33 ( NULL , V_91 -> V_82 ) ;
if ( F_34 ( V_43 ) ) {
F_17 ( L_9 ,
V_11 -> V_14 , V_91 -> V_82 ) ;
V_89 = - V_15 ;
continue;
}
V_91 -> V_84 = V_43 ;
F_35 ( V_91 -> V_84 ) ;
}
return V_89 ;
}
static int F_37 ( struct V_10 * V_11 )
{
struct V_94 * V_95 ;
struct V_82 * V_43 ;
int V_4 ;
int V_89 = 0 ;
for ( V_4 = V_11 -> V_96 , V_95 = V_11 -> V_97 ; V_4 > 0 ; V_4 -- , V_95 ++ ) {
V_43 = F_33 ( NULL , V_95 -> V_82 ) ;
if ( F_34 ( V_43 ) ) {
F_17 ( L_10 ,
V_11 -> V_14 , V_95 -> V_82 ) ;
V_89 = - V_15 ;
continue;
}
V_95 -> V_84 = V_43 ;
F_35 ( V_95 -> V_84 ) ;
}
return V_89 ;
}
static int F_38 ( struct V_10 * V_11 )
{
struct V_1 * V_91 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_18 ( L_11 , V_11 -> V_14 ) ;
if ( V_11 -> V_84 )
F_39 ( V_11 -> V_84 ) ;
V_3 = V_11 -> V_92 . V_9 ;
while ( V_4 < V_11 -> V_93 ) {
V_91 = F_1 ( & V_3 , & V_4 ) ;
if ( V_91 -> V_84 && ( V_91 -> V_68 & V_98 ) )
F_39 ( V_91 -> V_84 ) ;
}
return 0 ;
}
static int F_40 ( struct V_10 * V_11 )
{
struct V_1 * V_91 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_18 ( L_12 , V_11 -> V_14 ) ;
if ( V_11 -> V_84 )
F_41 ( V_11 -> V_84 ) ;
V_3 = V_11 -> V_92 . V_9 ;
while ( V_4 < V_11 -> V_93 ) {
V_91 = F_1 ( & V_3 , & V_4 ) ;
if ( V_91 -> V_84 && ( V_91 -> V_68 & V_98 ) )
F_41 ( V_91 -> V_84 ) ;
}
return 0 ;
}
static void F_42 ( struct V_10 * V_11 )
{
struct V_94 * V_95 ;
int V_4 ;
F_18 ( L_13 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_96 , V_95 = V_11 -> V_97 ; V_4 > 0 ; V_4 -- , V_95 ++ )
if ( V_95 -> V_84 ) {
F_18 ( L_14 , V_95 -> V_99 ,
F_43 ( V_95 -> V_84 ) ) ;
F_39 ( V_95 -> V_84 ) ;
}
}
static void F_44 ( struct V_10 * V_11 )
{
struct V_94 * V_95 ;
int V_4 ;
F_18 ( L_15 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_96 , V_95 = V_11 -> V_97 ; V_4 > 0 ; V_4 -- , V_95 ++ )
if ( V_95 -> V_84 ) {
F_18 ( L_16 , V_95 -> V_99 ,
F_43 ( V_95 -> V_84 ) ) ;
F_41 ( V_95 -> V_84 ) ;
}
}
static void F_45 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_83 || ! V_11 -> V_100 . V_101 . V_102 )
return;
F_18 ( L_17 ,
V_11 -> V_14 , V_103 , V_11 -> V_100 . V_101 . V_102 ) ;
F_46 ( V_11 -> V_100 . V_101 . V_102 ,
V_11 -> V_83 -> V_104 ,
V_11 -> V_83 -> V_105 , V_11 -> V_100 . V_101 . V_106 ) ;
}
static int F_47 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_107 || ! V_11 -> V_83 )
return 0 ;
if ( V_11 -> V_68 & V_108 )
return 0 ;
return F_48 ( V_11 -> V_83 -> V_104 ,
V_11 -> V_83 -> V_105 ,
V_11 -> V_100 . V_101 . V_106 , 0 ) ;
}
static int F_49 ( struct V_10 * V_11 )
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
static int F_50 ( struct V_10 * V_11 )
{
struct V_113 * V_114 ;
int V_4 = 0 ;
if ( ! V_11 || ! V_11 -> V_115 )
return 0 ;
do {
V_114 = & V_11 -> V_115 [ V_4 ++ ] ;
} while ( V_114 -> V_116 != - 1 );
return V_4 - 1 ;
}
static int F_51 ( struct V_1 * V_91 )
{
struct V_117 * V_118 ;
int V_4 = 0 ;
if ( ! V_91 || ! V_91 -> V_119 )
return 0 ;
do {
V_118 = & V_91 -> V_119 [ V_4 ++ ] ;
} while ( V_118 -> V_120 != V_118 -> V_121 );
return V_4 - 1 ;
}
static int F_52 ( struct V_10 * V_11 , const char * V_14 ,
unsigned int * V_112 )
{
int V_4 ;
bool V_122 = false ;
if ( ! V_11 -> V_111 )
return - V_123 ;
V_4 = 0 ;
while ( V_11 -> V_111 [ V_4 ] . V_112 != - 1 ) {
if ( V_14 == V_11 -> V_111 [ V_4 ] . V_14 ||
! strcmp ( V_14 , V_11 -> V_111 [ V_4 ] . V_14 ) ) {
V_122 = true ;
break;
}
V_4 ++ ;
}
if ( ! V_122 )
return - V_123 ;
* V_112 = V_11 -> V_111 [ V_4 ] . V_112 ;
return 0 ;
}
static int F_53 ( struct V_10 * V_11 , const char * V_14 ,
unsigned int * V_124 )
{
int V_4 ;
bool V_122 = false ;
if ( ! V_11 -> V_115 )
return - V_123 ;
V_4 = 0 ;
while ( V_11 -> V_115 [ V_4 ] . V_116 != - 1 ) {
if ( V_14 == V_11 -> V_115 [ V_4 ] . V_14 ||
! strcmp ( V_14 , V_11 -> V_115 [ V_4 ] . V_14 ) ) {
V_122 = true ;
break;
}
V_4 ++ ;
}
if ( ! V_122 )
return - V_123 ;
* V_124 = V_11 -> V_115 [ V_4 ] . V_116 ;
return 0 ;
}
static int F_54 ( struct V_10 * V_11 , const char * V_14 ,
T_1 * V_120 , T_1 * V_121 )
{
int V_4 , V_63 ;
struct V_1 * V_91 ;
struct V_2 * V_3 = NULL ;
bool V_122 = false ;
V_3 = V_11 -> V_92 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_93 ) {
V_91 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_91 -> V_119 )
return - V_123 ;
V_63 = 0 ;
while ( V_91 -> V_119 [ V_63 ] . V_120 != V_91 -> V_119 [ V_63 ] . V_121 ) {
if ( V_14 == V_91 -> V_119 [ V_63 ] . V_14 ||
! strcmp ( V_14 , V_91 -> V_119 [ V_63 ] . V_14 ) ) {
V_122 = true ;
break;
}
V_63 ++ ;
}
if ( V_122 )
break;
}
if ( ! V_122 )
return - V_123 ;
* V_120 = V_91 -> V_119 [ V_63 ] . V_120 ;
* V_121 = V_91 -> V_119 [ V_63 ] . V_121 ;
return 0 ;
}
static void T_4 F_55 ( struct V_10 * V_11 )
{
struct V_1 * V_91 = NULL ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( ! V_11 )
return;
V_11 -> V_20 |= V_107 ;
V_3 = V_11 -> V_92 . V_9 ;
while ( V_4 < V_11 -> V_93 ) {
V_91 = F_1 ( & V_3 , & V_4 ) ;
if ( V_91 -> V_125 & V_126 ) {
V_11 -> V_127 = V_91 ;
V_11 -> V_20 &= ~ V_107 ;
break;
}
}
return;
}
static struct V_1 * F_56 ( struct V_10 * V_11 )
{
if ( ! V_11 || V_11 -> V_20 & V_107 || V_11 -> V_93 == 0 )
return NULL ;
return V_11 -> V_127 ;
}
static struct V_117 * T_4 F_57 ( struct V_10 * V_11 )
{
struct V_1 * V_91 ;
struct V_117 * V_118 ;
int V_122 = 0 , V_4 = 0 ;
V_91 = F_56 ( V_11 ) ;
if ( ! V_91 || ! V_91 -> V_119 )
return NULL ;
do {
V_118 = & V_91 -> V_119 [ V_4 ++ ] ;
if ( V_118 -> V_68 & V_128 )
V_122 = 1 ;
} while ( ! V_122 && V_118 -> V_120 != V_118 -> V_121 );
return ( V_122 ) ? V_118 : NULL ;
}
static void F_58 ( struct V_10 * V_11 )
{
T_2 V_31 , V_129 ;
T_1 V_22 ;
bool V_130 ;
struct V_80 * V_83 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
if ( V_11 -> V_68 & V_131 )
F_42 ( V_11 ) ;
F_14 ( V_11 ) ;
if ( V_11 -> V_68 & V_131 )
F_44 ( V_11 ) ;
V_22 = V_11 -> V_16 ;
V_129 = V_11 -> V_12 -> V_13 -> V_18 ;
V_83 = F_24 ( V_11 ) ;
if ( V_129 & V_34 ) {
if ( V_11 -> V_68 & V_132 ||
V_11 -> V_68 & V_133 ) {
V_31 = V_134 ;
} else {
if ( V_129 & V_73 )
F_22 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_74 & V_75 )
V_31 = V_78 ;
else
V_31 = V_79 ;
}
V_130 = ( V_83 && V_83 -> V_68 & V_135 ) ;
if ( V_130 && ! ( V_11 -> V_12 -> V_13 -> V_74 &
( V_136 | V_75 ) ) )
V_31 = V_137 ;
F_10 ( V_11 , V_31 , & V_22 ) ;
}
if ( V_129 & V_28 ) {
if ( V_11 -> V_68 & V_138 ) {
V_31 = V_137 ;
} else if ( V_11 -> V_68 & V_139 ) {
V_31 = V_134 ;
} else {
if ( V_129 & V_73 )
F_22 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_74 & V_76 )
V_31 = V_78 ;
else
V_31 = V_79 ;
}
F_8 ( V_11 , V_31 , & V_22 ) ;
}
if ( ( V_11 -> V_68 & V_140 ) &&
( V_129 & V_38 ) )
F_11 ( V_11 , V_11 -> V_12 -> V_13 -> V_35 , & V_22 ) ;
if ( V_11 -> V_16 != V_22 )
F_6 ( V_22 , V_11 ) ;
if ( V_129 & V_57 ) {
V_31 = ( V_11 -> V_68 & V_141 ) ?
0 : 1 ;
F_19 ( V_11 , V_31 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
}
static void F_59 ( struct V_10 * V_11 )
{
T_2 V_31 , V_129 ;
T_1 V_22 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_129 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_129 & V_34 ) {
if ( V_11 -> V_68 & V_132 ) {
V_31 = V_137 ;
} else {
if ( V_129 & V_73 )
F_22 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_74 & V_75 )
V_31 = V_78 ;
else
V_31 = V_79 ;
}
F_10 ( V_11 , V_31 , & V_22 ) ;
}
if ( V_129 & V_28 ) {
if ( ( V_11 -> V_68 & V_139 ) ||
( V_11 -> V_68 & V_138 ) ) {
V_31 = V_137 ;
} else {
if ( V_129 & V_73 )
F_22 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_74 & V_76 )
V_31 = V_78 ;
else
V_31 = V_79 ;
}
F_8 ( V_11 , V_31 , & V_22 ) ;
}
F_6 ( V_22 , V_11 ) ;
}
static void F_60 ( struct V_10 * V_11 )
{
T_1 V_22 ;
T_2 V_129 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_129 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_129 & V_34 )
F_10 ( V_11 , V_137 , & V_22 ) ;
if ( V_129 & V_28 )
F_8 ( V_11 , V_137 , & V_22 ) ;
if ( V_129 & V_57 )
F_19 ( V_11 , 1 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
static struct V_10 * F_61 ( const char * V_14 )
{
struct V_10 * V_11 , * V_142 ;
V_11 = NULL ;
F_62 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_14 , V_142 -> V_14 ) ) {
V_11 = V_142 ;
break;
}
}
return V_11 ;
}
static int F_63 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_143 ) {
F_18 ( L_18 , V_11 -> V_14 ) ;
return 0 ;
}
V_11 -> V_83 = F_64 ( V_11 -> V_143 ) ;
if ( ! V_11 -> V_83 ) {
F_17 ( L_19 ,
V_11 -> V_14 , V_11 -> V_143 ) ;
return 0 ;
}
F_18 ( L_20 ,
V_11 -> V_14 , V_11 -> V_143 ) ;
return 0 ;
}
static int F_65 ( struct V_10 * V_11 , void * V_144 )
{
int V_89 = 0 ;
if ( V_11 -> V_51 != V_145 )
return 0 ;
F_18 ( L_21 , V_11 -> V_14 ) ;
if ( V_146 . V_87 )
V_89 |= V_146 . V_87 ( V_11 ) ;
V_89 |= F_32 ( V_11 ) ;
V_89 |= F_36 ( V_11 ) ;
V_89 |= F_37 ( V_11 ) ;
if ( ! V_89 )
V_11 -> V_51 = V_147 ;
else
F_17 ( L_22 , V_11 -> V_14 ) ;
return V_89 ;
}
static int F_66 ( struct V_10 * V_11 , const char * V_14 ,
struct V_148 * V_149 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_150 ; V_4 ++ ) {
const char * V_151 = V_11 -> V_152 [ V_4 ] . V_14 ;
if ( ! strcmp ( V_151 , V_14 ) ) {
V_149 -> V_153 = V_11 -> V_152 [ V_4 ] . V_153 ;
V_149 -> V_154 = V_11 -> V_152 [ V_4 ] . V_154 ;
F_18 ( L_23 ,
V_11 -> V_14 , V_103 , V_151 , V_149 -> V_153 ,
V_149 -> V_154 ) ;
return 0 ;
}
}
return - V_123 ;
}
static int F_67 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_148 V_149 ;
int V_89 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_146 . V_155 )
return - V_156 ;
V_89 = F_66 ( V_11 , V_14 , & V_149 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = V_146 . V_155 ( V_11 , & V_149 ) ;
return V_89 ;
}
static int F_68 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_148 V_149 ;
int V_89 = - V_15 ;
int V_157 = 0 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_146 . V_158 )
return - V_156 ;
V_89 = F_66 ( V_11 , V_14 , & V_149 ) ;
if ( V_89 < 0 )
return V_89 ;
if ( V_11 -> V_83 ) {
V_157 = F_69 ( V_11 -> V_83 ) ;
V_89 = F_70 ( V_11 -> V_83 , V_11 ) ;
if ( V_89 ) {
F_4 ( 1 , L_24 ,
V_11 -> V_14 , V_11 -> V_83 -> V_14 , V_89 ) ;
return V_89 ;
}
}
F_38 ( V_11 ) ;
if ( V_146 . V_159 )
V_146 . V_159 ( V_11 ) ;
V_89 = V_146 . V_158 ( V_11 , & V_149 ) ;
if ( V_146 . V_160 )
V_146 . V_160 ( V_11 ) ;
F_40 ( V_11 ) ;
if ( V_89 == - V_161 )
F_17 ( L_25 , V_11 -> V_14 ) ;
if ( V_11 -> V_83 ) {
if ( V_157 )
F_71 ( V_11 -> V_83 ) ;
F_72 ( V_11 -> V_83 , V_11 ) ;
}
return V_89 ;
}
static int F_73 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_148 V_149 ;
int V_89 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_146 . V_162 )
return - V_156 ;
V_89 = F_66 ( V_11 , V_14 , & V_149 ) ;
if ( V_89 < 0 )
return V_89 ;
return V_146 . V_162 ( V_11 , & V_149 ) ;
}
static bool F_74 ( struct V_10 * V_11 )
{
int V_4 , V_163 = 0 ;
if ( V_11 -> V_150 == 0 )
return false ;
for ( V_4 = 0 ; V_4 < V_11 -> V_150 ; V_4 ++ )
if ( F_73 ( V_11 , V_11 -> V_152 [ V_4 ] . V_14 ) > 0 )
V_163 ++ ;
if ( V_11 -> V_150 == V_163 )
return true ;
return false ;
}
static bool F_75 ( struct V_10 * V_11 )
{
int V_163 = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_150 && V_163 == 0 ; V_4 ++ )
if ( F_73 ( V_11 , V_11 -> V_152 [ V_4 ] . V_14 ) > 0 )
V_163 ++ ;
return ( V_163 ) ? true : false ;
}
static int F_76 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! V_11 -> V_83 || ! V_11 -> V_100 . V_101 . V_102 )
return - V_15 ;
if ( F_75 ( V_11 ) )
return 0 ;
F_18 ( L_26 , V_11 -> V_14 , V_103 ) ;
F_77 ( V_11 -> V_83 -> V_104 , V_11 -> V_83 -> V_105 ,
V_11 -> V_100 . V_101 . V_106 ) ;
V_22 = F_47 ( V_11 ) ;
if ( V_22 )
F_17 ( L_27 ,
V_11 -> V_14 ) ;
return 0 ;
}
static int F_78 ( struct V_10 * V_11 )
{
T_1 V_22 ;
int V_43 = 0 ;
int V_89 = 0 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_40 ) )
return - V_123 ;
if ( V_11 -> V_51 != V_52 ) {
F_17 ( L_28 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_68 & V_131 )
F_42 ( V_11 ) ;
F_18 ( L_29 , V_11 -> V_14 ) ;
V_22 = V_11 -> V_16 ;
V_89 = F_12 ( V_11 , & V_22 ) ;
if ( V_89 )
goto V_164;
F_6 ( V_22 , V_11 ) ;
if ( V_11 -> V_12 -> V_13 -> V_165 )
F_79 ( V_11 -> V_12 -> V_13 -> V_165 ) ;
V_43 = F_14 ( V_11 ) ;
if ( V_43 == V_47 ) {
F_17 ( L_30 ,
V_11 -> V_14 , V_47 ) ;
V_89 = - V_166 ;
goto V_164;
} else {
F_18 ( L_31 , V_11 -> V_14 , V_43 ) ;
}
V_89 = F_13 ( V_11 , & V_22 ) ;
if ( V_89 )
goto V_164;
F_6 ( V_22 , V_11 ) ;
V_164:
if ( V_11 -> V_68 & V_131 )
F_44 ( V_11 ) ;
return V_89 ;
}
static int F_80 ( struct V_10 * V_11 )
{
int V_4 , V_167 ;
F_18 ( L_32 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_168 ) {
V_167 = V_11 -> V_12 -> V_168 ( V_11 ) ;
} else {
if ( V_11 -> V_150 > 0 ) {
for ( V_4 = 0 ; V_4 < V_11 -> V_150 ; V_4 ++ )
F_67 ( V_11 , V_11 -> V_152 [ V_4 ] . V_14 ) ;
return 0 ;
} else {
V_167 = F_78 ( V_11 ) ;
if ( V_167 == - V_123 )
V_167 = 0 ;
}
}
F_16 ( V_11 ) ;
if ( V_11 -> V_12 -> V_13 ) {
F_3 ( V_11 ) ;
F_58 ( V_11 ) ;
}
return V_167 ;
}
static void F_81 ( void )
{
unsigned long V_68 ;
F_82 ( & V_169 , V_68 ) ;
F_83 () ;
F_84 ( & V_169 , V_68 ) ;
}
static void F_85 ( struct V_10 * V_11 )
{
if ( V_11 -> V_100 . V_101 . V_68 & V_170 )
return;
if ( ! F_86 ( V_11 -> V_83 -> V_171 . V_172 -> V_104 ,
V_11 -> V_83 -> V_171 . V_172 -> V_173 ,
V_11 -> V_100 . V_101 . V_174 ) )
return;
V_11 -> V_100 . V_101 . V_175 ++ ;
F_87 ( V_11 -> V_83 -> V_171 . V_172 -> V_104 ,
V_11 -> V_83 -> V_171 . V_172 -> V_173 ,
V_11 -> V_100 . V_101 . V_174 ) ;
}
static int F_88 ( struct V_10 * V_11 )
{
return V_11 -> V_100 . V_101 . V_175 ;
}
static int F_89 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_12 -> V_176 )
return 0 ;
return V_11 -> V_12 -> V_176 ( V_11 ) ;
}
static int F_90 ( struct V_10 * V_11 )
{
int V_167 ;
int V_157 = 0 ;
F_18 ( L_33 , V_11 -> V_14 ) ;
if ( V_11 -> V_20 & V_177 ) {
if ( V_11 -> V_64 )
F_21 ( V_11 -> V_64 , V_52 ) ;
V_11 -> V_20 &= ~ V_177 ;
return 0 ;
}
if ( V_11 -> V_51 != V_178 &&
V_11 -> V_51 != V_72 &&
V_11 -> V_51 != V_179 ) {
F_4 ( 1 , L_34 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_74 ( V_11 ) )
return 0 ;
if ( V_11 -> V_64 && ( ! V_11 -> V_64 -> V_65 ||
( ( V_11 -> V_51 == V_72 ) &&
V_11 -> V_64 -> V_67 ) ) ) {
F_21 ( V_11 -> V_64 , V_52 ) ;
F_81 () ;
} else if ( V_11 -> V_68 & V_180 ) {
F_81 () ;
}
F_28 ( V_11 , V_181 ) ;
if ( V_11 -> V_83 ) {
V_157 = F_69 ( V_11 -> V_83 ) &&
! F_91 ( V_11 -> V_83 ) ;
V_167 = F_70 ( V_11 -> V_83 , V_11 ) ;
if ( V_167 ) {
F_4 ( 1 , L_24 ,
V_11 -> V_14 , V_11 -> V_83 -> V_14 , V_167 ) ;
return V_167 ;
}
}
F_38 ( V_11 ) ;
if ( V_146 . V_159 )
V_146 . V_159 ( V_11 ) ;
if ( V_11 -> V_68 & V_182 )
F_92 ( true ) ;
if ( V_146 . V_183 )
V_146 . V_183 ( V_11 ) ;
V_167 = ( V_146 . V_184 ) ? V_146 . V_184 ( V_11 ) :
- V_15 ;
if ( ! V_167 ) {
if ( V_11 -> V_83 && V_157 )
F_71 ( V_11 -> V_83 ) ;
V_11 -> V_51 = V_52 ;
if ( V_11 -> V_12 -> V_13 ) {
if ( ! ( V_11 -> V_20 & V_21 ) )
F_3 ( V_11 ) ;
F_58 ( V_11 ) ;
}
V_167 = F_89 ( V_11 ) ;
} else {
if ( V_146 . V_160 )
V_146 . V_160 ( V_11 ) ;
F_40 ( V_11 ) ;
F_93 ( L_35 ,
V_11 -> V_14 , V_167 ) ;
if ( V_11 -> V_83 )
F_72 ( V_11 -> V_83 , V_11 ) ;
}
return V_167 ;
}
static int F_94 ( struct V_10 * V_11 )
{
F_18 ( L_36 , V_11 -> V_14 ) ;
if ( V_11 -> V_51 != V_52 ) {
F_4 ( 1 , L_37 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_74 ( V_11 ) )
return 0 ;
if ( V_11 -> V_12 -> V_13 )
F_59 ( V_11 ) ;
F_30 ( V_11 , V_181 ) ;
if ( V_11 -> V_68 & V_182 )
F_92 ( false ) ;
if ( V_146 . V_160 )
V_146 . V_160 ( V_11 ) ;
F_40 ( V_11 ) ;
if ( V_11 -> V_83 )
F_72 ( V_11 -> V_83 , V_11 ) ;
if ( V_11 -> V_64 && V_11 -> V_64 -> V_67 ) {
F_21 ( V_11 -> V_64 , V_72 ) ;
F_81 () ;
} else if ( V_11 -> V_68 & V_180 ) {
F_81 () ;
}
V_11 -> V_51 = V_72 ;
return 0 ;
}
static int F_95 ( struct V_10 * V_11 )
{
int V_89 , V_4 ;
T_2 V_185 ;
if ( V_11 -> V_51 != V_72 &&
V_11 -> V_51 != V_52 ) {
F_4 ( 1 , L_38 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_74 ( V_11 ) )
return 0 ;
F_18 ( L_39 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_186 ) {
V_185 = V_11 -> V_51 ;
if ( V_11 -> V_51 == V_72 )
F_90 ( V_11 ) ;
V_89 = V_11 -> V_12 -> V_186 ( V_11 ) ;
if ( V_89 ) {
if ( V_185 == V_72 )
F_94 ( V_11 ) ;
return V_89 ;
}
}
if ( V_11 -> V_12 -> V_13 ) {
if ( V_11 -> V_51 == V_72 )
F_90 ( V_11 ) ;
F_60 ( V_11 ) ;
}
if ( V_11 -> V_51 == V_52 ) {
F_30 ( V_11 , V_181 ) ;
if ( V_11 -> V_68 & V_182 )
F_92 ( false ) ;
if ( V_146 . V_160 )
V_146 . V_160 ( V_11 ) ;
F_40 ( V_11 ) ;
if ( V_11 -> V_83 )
F_72 ( V_11 -> V_83 , V_11 ) ;
}
for ( V_4 = 0 ; V_4 < V_11 -> V_150 ; V_4 ++ )
F_67 ( V_11 , V_11 -> V_152 [ V_4 ] . V_14 ) ;
if ( V_11 -> V_64 )
F_21 ( V_11 -> V_64 , V_179 ) ;
V_11 -> V_51 = V_179 ;
return 0 ;
}
static int F_96 ( struct V_187 * V_188 ,
struct V_10 * V_11 )
{
int V_189 , V_4 , V_190 ;
const char * V_3 ;
V_189 = F_97 ( V_188 , L_40 ) ;
if ( V_189 < 1 )
return - V_191 ;
for ( V_4 = 0 ; V_4 < V_189 ; V_4 ++ ) {
V_190 = F_98 ( V_188 , L_40 ,
V_4 , & V_3 ) ;
if ( V_190 )
continue;
if ( ! strcmp ( V_3 , V_11 -> V_14 ) ) {
F_18 ( L_41 ,
V_188 -> V_14 , V_4 , V_11 -> V_14 ) ;
return V_4 ;
}
}
return - V_191 ;
}
static int F_99 ( struct V_187 * V_188 ,
struct V_10 * V_11 ,
int * V_192 ,
struct V_187 * * V_122 )
{
struct V_187 * V_193 = NULL ;
int V_190 ;
V_190 = F_96 ( V_188 , V_11 ) ;
if ( V_190 >= 0 ) {
* V_122 = V_188 ;
* V_192 = V_190 ;
return 0 ;
}
F_100 (np, np0) {
struct V_187 * V_194 ;
int V_4 ;
V_190 = F_99 ( V_193 , V_11 , & V_4 , & V_194 ) ;
if ( V_190 == 0 ) {
* V_122 = V_194 ;
* V_192 = V_4 ;
return 0 ;
}
}
* V_122 = NULL ;
* V_192 = 0 ;
return - V_191 ;
}
static int T_4 F_101 ( struct V_10 * V_11 , void * V_144 ,
int V_192 , struct V_187 * V_188 )
{
struct V_117 * V_118 ;
void T_5 * va_start = NULL ;
if ( ! V_11 )
return - V_15 ;
F_55 ( V_11 ) ;
if ( ! V_11 -> V_12 -> V_13 )
return 0 ;
if ( V_11 -> V_20 & V_107 )
return - V_195 ;
V_118 = F_57 ( V_11 ) ;
if ( ! V_118 ) {
F_18 ( L_42 ,
V_11 -> V_14 ) ;
if ( ! V_188 ) {
F_93 ( L_43 , V_11 -> V_14 ) ;
return - V_195 ;
}
va_start = F_102 ( V_188 , V_192 + V_11 -> V_196 ) ;
} else {
va_start = F_103 ( V_118 -> V_120 , V_118 -> V_121 - V_118 -> V_120 ) ;
}
if ( ! va_start ) {
if ( V_118 )
F_93 ( L_44 , V_11 -> V_14 ) ;
else
F_93 ( L_45 ,
V_11 -> V_14 , V_192 , V_188 -> V_197 ) ;
return - V_195 ;
}
F_18 ( L_46 ,
V_11 -> V_14 , va_start ) ;
V_11 -> V_198 = va_start ;
return 0 ;
}
static int T_4 F_104 ( struct V_10 * V_11 , void * V_144 )
{
int V_167 , V_192 ;
struct V_187 * V_188 = NULL ;
if ( V_11 -> V_51 != V_145 )
return 0 ;
if ( F_105 () ) {
struct V_187 * V_199 ;
V_199 = F_106 ( NULL , L_47 ) ;
if ( ! V_199 )
return - V_191 ;
V_167 = F_99 ( V_199 , V_11 , & V_192 , & V_188 ) ;
if ( V_167 )
F_18 ( L_48 , V_11 -> V_14 ) ;
else if ( V_188 && V_192 )
F_17 ( L_49 ,
V_11 -> V_14 , V_188 -> V_14 ) ;
}
V_167 = F_101 ( V_11 , NULL , V_192 , V_188 ) ;
if ( V_167 < 0 ) {
F_4 ( 1 , L_50 ,
V_11 -> V_14 ) ;
return 0 ;
}
V_167 = F_65 ( V_11 , NULL ) ;
if ( V_167 < 0 ) {
F_4 ( 1 , L_51 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_188 ) {
if ( F_107 ( V_188 , L_52 , NULL ) )
V_11 -> V_68 |= V_200 ;
if ( F_107 ( V_188 , L_53 , NULL ) )
V_11 -> V_68 |= V_201 ;
}
V_11 -> V_51 = V_178 ;
return 0 ;
}
static void T_4 F_108 ( struct V_10 * V_11 )
{
struct V_1 * V_91 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( V_11 -> V_51 != V_178 )
return;
V_3 = V_11 -> V_92 . V_9 ;
while ( V_4 < V_11 -> V_93 ) {
V_91 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_91 -> V_84 )
continue;
if ( V_91 -> V_68 & V_98 ) {
} else {
F_39 ( V_91 -> V_84 ) ;
}
}
return;
}
static int T_4 F_109 ( struct V_10 * V_11 )
{
int V_167 ;
if ( V_11 -> V_51 != V_178 )
return - V_15 ;
if ( V_11 -> V_68 & V_202 )
return - V_203 ;
if ( V_11 -> V_150 == 0 ) {
V_167 = F_90 ( V_11 ) ;
if ( V_167 ) {
F_17 ( L_54 ,
V_11 -> V_14 , V_11 -> V_51 ) ;
return - V_15 ;
}
}
if ( ! ( V_11 -> V_68 & V_200 ) )
V_167 = F_80 ( V_11 ) ;
return V_167 ;
}
static void T_4 F_110 ( struct V_10 * V_11 )
{
T_2 V_204 ;
if ( V_11 -> V_150 > 0 )
return;
V_204 = V_11 -> V_205 ;
if ( V_204 == V_206 )
V_204 = V_52 ;
if ( ( V_11 -> V_68 & V_201 ) &&
( V_204 == V_72 ) ) {
V_11 -> V_20 |= V_177 ;
V_204 = V_52 ;
}
if ( V_204 == V_72 )
F_94 ( V_11 ) ;
else if ( V_204 == V_179 )
F_95 ( V_11 ) ;
else if ( V_204 != V_52 )
F_4 ( 1 , L_55 ,
V_11 -> V_14 , V_204 ) ;
return;
}
static int T_4 F_111 ( struct V_10 * V_11 , void * V_144 )
{
if ( V_11 -> V_51 != V_178 )
return 0 ;
if ( V_11 -> V_207 ) {
int V_167 ;
V_167 = F_90 ( V_11 -> V_207 ) ;
F_4 ( V_167 , L_56 ,
V_11 -> V_14 , V_11 -> V_207 -> V_14 ) ;
}
F_108 ( V_11 ) ;
if ( ! F_109 ( V_11 ) )
F_110 ( V_11 ) ;
if ( V_11 -> V_207 ) {
T_2 V_204 ;
V_204 = V_11 -> V_207 -> V_205 ;
if ( V_204 == V_72 )
F_94 ( V_11 -> V_207 ) ;
else if ( V_204 == V_179 )
F_95 ( V_11 -> V_207 ) ;
else if ( V_204 != V_52 )
F_4 ( 1 , L_55 ,
V_11 -> V_207 -> V_14 , V_204 ) ;
}
return 0 ;
}
static int T_4 F_112 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_14 || ! V_11 -> V_12 || ! V_11 -> V_12 -> V_14 ||
( V_11 -> V_51 != V_206 ) )
return - V_15 ;
F_18 ( L_57 , V_11 -> V_14 ) ;
if ( F_61 ( V_11 -> V_14 ) )
return - V_208 ;
F_113 ( & V_11 -> V_7 , & V_209 ) ;
F_114 ( & V_11 -> V_210 ) ;
F_114 ( & V_11 -> V_92 ) ;
F_115 ( & V_11 -> V_211 ) ;
F_116 ( & V_11 -> V_211 , & V_11 -> V_212 ) ;
V_11 -> V_51 = V_145 ;
if ( ! strcmp ( V_11 -> V_14 , V_213 ) )
V_181 = V_11 ;
return 0 ;
}
static int T_4 F_117 ( struct V_6 * * V_214 ,
struct V_6 * * V_215 )
{
unsigned int V_216 ;
if ( ( V_217 + V_218 ) <= V_219 ) {
* V_214 = & V_220 [ V_217 ++ ] ;
* V_215 = & V_220 [ V_217 ++ ] ;
return 0 ;
}
V_216 = sizeof( struct V_6 ) * V_218 ;
* V_215 = NULL ;
* V_214 = F_118 ( V_216 , 0 ) ;
* V_215 = ( void * ) ( * V_214 ) + sizeof( struct V_6 ) ;
V_221 ++ ;
F_18 ( L_58 ,
V_221 * V_218 ) ;
return 0 ;
}
static int T_4 F_119 ( struct V_1 * V_5 )
{
struct V_6 * V_214 , * V_215 ;
F_18 ( L_59 , V_5 -> V_222 -> V_14 ,
V_5 -> V_223 -> V_14 ) ;
F_117 ( & V_214 , & V_215 ) ;
V_214 -> V_8 = V_5 ;
F_120 ( & V_214 -> V_7 , & V_5 -> V_222 -> V_210 ) ;
V_5 -> V_222 -> V_224 ++ ;
V_215 -> V_8 = V_5 ;
F_120 ( & V_215 -> V_7 , & V_5 -> V_223 -> V_92 ) ;
V_5 -> V_223 -> V_93 ++ ;
return 0 ;
}
static int T_4 F_121 ( struct V_1 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_222 || ! V_5 -> V_223 || ! V_5 -> V_125 )
return - V_15 ;
if ( V_5 -> V_20 & V_225 )
return - V_208 ;
F_18 ( L_60 ,
V_5 -> V_222 -> V_14 , V_5 -> V_223 -> V_14 ) ;
if ( V_5 -> V_222 -> V_51 != V_145 )
F_112 ( V_5 -> V_222 ) ;
if ( V_5 -> V_223 -> V_51 != V_145 )
F_112 ( V_5 -> V_223 ) ;
F_119 ( V_5 ) ;
V_5 -> V_20 |= V_225 ;
return 0 ;
}
static int T_4 F_122 ( struct V_1 * * V_226 )
{
unsigned int V_4 = 0 ;
unsigned int V_216 ;
if ( V_220 ) {
F_4 ( 1 , L_61 ) ;
return - V_208 ;
}
if ( V_219 == 0 )
while ( V_226 [ V_4 ++ ] )
V_219 += V_218 ;
V_216 = sizeof( struct V_6 ) * V_219 ;
F_18 ( L_62 ,
V_103 , V_216 , V_219 ) ;
V_220 = F_118 ( V_216 , 0 ) ;
return 0 ;
}
static int F_123 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_68 & V_108 )
return 0 ;
if ( ! F_56 ( V_11 ) )
return 0 ;
return F_124 ( 0 , V_11 -> V_100 . V_227 . V_228 ,
V_11 -> V_100 . V_227 . V_229 ,
V_11 -> V_100 . V_227 . V_230 ) ;
}
static int F_125 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_68 & V_108 || ! V_11 -> V_83 )
return 0 ;
if ( ! F_56 ( V_11 ) )
return 0 ;
return F_124 ( V_11 -> V_83 -> V_104 ,
V_11 -> V_83 -> V_105 ,
V_11 -> V_100 . V_101 . V_106 , 0 ) ;
}
static int F_126 ( struct V_10 * V_11 ,
struct V_148 * V_149 )
{
return F_127 ( V_149 -> V_153 , 0 ,
V_11 -> V_100 . V_227 . V_228 , 0 ) ;
}
static int F_128 ( struct V_10 * V_11 ,
struct V_148 * V_149 )
{
return F_129 ( V_149 -> V_153 , V_149 -> V_154 , 0 ,
V_11 -> V_100 . V_227 . V_228 , 0 , 0 ) ;
}
static int F_130 ( struct V_10 * V_11 ,
struct V_148 * V_149 )
{
return F_131 ( V_149 -> V_154 , 0 ,
V_11 -> V_100 . V_227 . V_228 , 0 ) ;
}
static int F_132 ( struct V_10 * V_11 ,
struct V_148 * V_149 )
{
if ( ! V_11 -> V_83 )
return - V_15 ;
return F_127 ( V_149 -> V_153 ,
V_11 -> V_83 -> V_171 . V_172 -> V_104 ,
V_11 -> V_83 -> V_171 . V_172 -> V_173 ,
V_11 -> V_100 . V_101 . V_231 ) ;
}
static int F_133 ( struct V_10 * V_11 ,
struct V_148 * V_149 )
{
if ( ! V_11 -> V_83 )
return - V_15 ;
if ( V_149 -> V_154 )
F_93 ( L_63 ,
V_11 -> V_14 , V_149 -> V_14 ) ;
return F_129 ( V_149 -> V_153 , V_149 -> V_153 ,
V_11 -> V_83 -> V_171 . V_172 -> V_104 ,
V_11 -> V_83 -> V_171 . V_172 -> V_173 ,
V_11 -> V_100 . V_101 . V_231 ,
V_11 -> V_100 . V_101 . V_231 +
V_232 ) ;
}
static int F_134 ( struct V_10 * V_11 ,
struct V_148 * V_149 )
{
if ( ! V_11 -> V_83 )
return - V_15 ;
return F_131 ( V_149 -> V_153 ,
V_11 -> V_83 -> V_171 . V_172 ->
V_104 ,
V_11 -> V_83 -> V_171 . V_172 -> V_173 ,
V_11 -> V_100 . V_101 . V_231 ) ;
}
static int F_135 ( struct V_10 * V_11 ,
struct V_148 * V_149 )
{
return F_129 ( V_149 -> V_153 , V_149 -> V_154 ,
V_11 -> V_83 -> V_171 . V_172 -> V_104 ,
V_11 -> V_83 -> V_171 . V_172 -> V_173 ,
V_11 -> V_100 . V_101 . V_231 ,
V_11 -> V_100 . V_101 . V_233 ) ;
}
T_1 F_5 ( struct V_10 * V_11 , T_3 V_234 )
{
if ( V_11 -> V_68 & V_235 )
return F_136 ( V_11 -> V_198 + V_234 ) ;
else
return F_137 ( V_11 -> V_198 + V_234 ) ;
}
void F_7 ( T_1 V_22 , struct V_10 * V_11 , T_3 V_234 )
{
if ( V_11 -> V_68 & V_235 )
F_138 ( V_22 , V_11 -> V_198 + V_234 ) ;
else
F_139 ( V_22 , V_11 -> V_198 + V_234 ) ;
}
int F_140 ( struct V_10 * V_11 )
{
T_1 V_22 ;
int V_89 ;
if ( ! V_11 || ! ( V_11 -> V_16 ) )
return - V_15 ;
V_22 = V_11 -> V_16 ;
V_89 = F_12 ( V_11 , & V_22 ) ;
if ( V_89 )
goto error;
F_6 ( V_22 , V_11 ) ;
V_89 = F_13 ( V_11 , & V_22 ) ;
if ( V_89 )
goto error;
F_6 ( V_22 , V_11 ) ;
error:
return V_89 ;
}
struct V_10 * F_141 ( const char * V_14 )
{
struct V_10 * V_11 ;
if ( ! V_14 )
return NULL ;
V_11 = F_61 ( V_14 ) ;
return V_11 ;
}
int F_142 ( int (* F_143)( struct V_10 * V_11 , void * V_144 ) ,
void * V_144 )
{
struct V_10 * V_142 ;
int V_89 = 0 ;
if ( ! F_143 )
return - V_15 ;
F_62 (temp_oh, &omap_hwmod_list, node) {
V_89 = (* F_143)( V_142 , V_144 ) ;
if ( V_89 )
break;
}
return V_89 ;
}
int T_4 F_144 ( struct V_1 * * V_226 )
{
int V_167 , V_4 ;
if ( ! V_236 )
return - V_15 ;
if ( ! V_226 )
return 0 ;
if ( V_226 [ 0 ] == NULL )
return 0 ;
if ( ! V_220 ) {
if ( F_122 ( V_226 ) ) {
F_93 ( L_64 ) ;
return - V_237 ;
}
}
V_4 = 0 ;
do {
V_167 = F_121 ( V_226 [ V_4 ] ) ;
F_4 ( V_167 && V_167 != - V_208 ,
L_65 ,
V_226 [ V_4 ] -> V_222 -> V_14 , V_226 [ V_4 ] -> V_223 -> V_14 , V_167 ) ;
} while ( V_226 [ ++ V_4 ] );
return 0 ;
}
static void T_4 F_145 ( struct V_10 * V_11 )
{
if ( ! V_181 || V_181 -> V_51 == V_206 )
F_93 ( L_66 ,
V_103 , V_213 ) ;
else if ( V_181 -> V_51 == V_145 && V_11 != V_181 )
F_146 ( V_213 ) ;
}
int T_4 F_146 ( const char * V_238 )
{
struct V_10 * V_11 ;
F_18 ( L_26 , V_238 , V_103 ) ;
V_11 = F_61 ( V_238 ) ;
if ( ! V_11 ) {
F_4 ( 1 , L_67 , V_238 ) ;
return - V_15 ;
}
F_145 ( V_11 ) ;
F_104 ( V_11 , NULL ) ;
F_111 ( V_11 , NULL ) ;
return 0 ;
}
static int T_4 F_147 ( void )
{
F_145 ( NULL ) ;
F_142 ( F_104 , NULL ) ;
F_142 ( F_111 , NULL ) ;
return 0 ;
}
int F_148 ( struct V_10 * V_11 )
{
int V_167 ;
unsigned long V_68 ;
if ( ! V_11 )
return - V_15 ;
F_82 ( & V_11 -> V_211 , V_68 ) ;
V_167 = F_90 ( V_11 ) ;
F_84 ( & V_11 -> V_211 , V_68 ) ;
return V_167 ;
}
int F_149 ( struct V_10 * V_11 )
{
int V_167 ;
unsigned long V_68 ;
if ( ! V_11 )
return - V_15 ;
F_82 ( & V_11 -> V_211 , V_68 ) ;
V_167 = F_94 ( V_11 ) ;
F_84 ( & V_11 -> V_211 , V_68 ) ;
return V_167 ;
}
int F_150 ( struct V_10 * V_11 )
{
int V_167 ;
unsigned long V_68 ;
if ( ! V_11 )
return - V_15 ;
F_82 ( & V_11 -> V_211 , V_68 ) ;
V_167 = F_95 ( V_11 ) ;
F_84 ( & V_11 -> V_211 , V_68 ) ;
return V_167 ;
}
int F_151 ( struct V_10 * V_11 , unsigned long V_68 )
{
int V_89 = 0 ;
if ( V_68 & V_239 )
V_89 += F_49 ( V_11 ) ;
if ( V_68 & V_240 )
V_89 += F_50 ( V_11 ) ;
if ( V_68 & V_241 ) {
int V_4 = 0 ;
struct V_1 * V_91 ;
struct V_2 * V_3 = V_11 -> V_92 . V_9 ;
while ( V_4 < V_11 -> V_93 ) {
V_91 = F_1 ( & V_3 , & V_4 ) ;
V_89 += F_51 ( V_91 ) ;
}
}
return V_89 ;
}
int F_152 ( struct V_10 * V_11 , struct V_242 * V_190 )
{
struct V_1 * V_91 ;
struct V_2 * V_3 ;
int V_4 , V_63 , V_243 , V_244 , V_245 ;
int V_167 = 0 ;
V_243 = F_49 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_243 ; V_4 ++ ) {
unsigned int V_112 ;
if ( V_11 -> V_246 )
V_112 = V_11 -> V_246 ( ( V_11 -> V_111 + V_4 ) -> V_112 ) ;
else
V_112 = ( V_11 -> V_111 + V_4 ) -> V_112 ;
( V_190 + V_167 ) -> V_14 = ( V_11 -> V_111 + V_4 ) -> V_14 ;
( V_190 + V_167 ) -> V_247 = V_112 ;
( V_190 + V_167 ) -> V_248 = V_112 ;
( V_190 + V_167 ) -> V_68 = V_239 ;
V_167 ++ ;
}
V_244 = F_50 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_244 ; V_4 ++ ) {
( V_190 + V_167 ) -> V_14 = ( V_11 -> V_115 + V_4 ) -> V_14 ;
( V_190 + V_167 ) -> V_247 = ( V_11 -> V_115 + V_4 ) -> V_116 ;
( V_190 + V_167 ) -> V_248 = ( V_11 -> V_115 + V_4 ) -> V_116 ;
( V_190 + V_167 ) -> V_68 = V_240 ;
V_167 ++ ;
}
V_3 = V_11 -> V_92 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_93 ) {
V_91 = F_1 ( & V_3 , & V_4 ) ;
V_245 = F_51 ( V_91 ) ;
for ( V_63 = 0 ; V_63 < V_245 ; V_63 ++ ) {
( V_190 + V_167 ) -> V_14 = ( V_91 -> V_119 + V_63 ) -> V_14 ;
( V_190 + V_167 ) -> V_247 = ( V_91 -> V_119 + V_63 ) -> V_120 ;
( V_190 + V_167 ) -> V_248 = ( V_91 -> V_119 + V_63 ) -> V_121 ;
( V_190 + V_167 ) -> V_68 = V_241 ;
V_167 ++ ;
}
}
return V_167 ;
}
int F_153 ( struct V_10 * V_11 , struct V_242 * V_190 )
{
int V_4 , V_244 ;
int V_167 = 0 ;
V_244 = F_50 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_244 ; V_4 ++ ) {
( V_190 + V_167 ) -> V_14 = ( V_11 -> V_115 + V_4 ) -> V_14 ;
( V_190 + V_167 ) -> V_247 = ( V_11 -> V_115 + V_4 ) -> V_116 ;
( V_190 + V_167 ) -> V_248 = ( V_11 -> V_115 + V_4 ) -> V_116 ;
( V_190 + V_167 ) -> V_68 = V_240 ;
V_167 ++ ;
}
return V_167 ;
}
int F_154 ( struct V_10 * V_11 , unsigned int type ,
const char * V_14 , struct V_242 * V_249 )
{
int V_167 ;
unsigned int V_112 , V_124 ;
T_1 V_120 , V_121 ;
if ( ! V_11 || ! V_249 )
return - V_15 ;
if ( type == V_239 ) {
V_167 = F_52 ( V_11 , V_14 , & V_112 ) ;
if ( V_167 )
return V_167 ;
V_249 -> V_247 = V_112 ;
V_249 -> V_248 = V_112 ;
} else if ( type == V_240 ) {
V_167 = F_53 ( V_11 , V_14 , & V_124 ) ;
if ( V_167 )
return V_167 ;
V_249 -> V_247 = V_124 ;
V_249 -> V_248 = V_124 ;
} else if ( type == V_241 ) {
V_167 = F_54 ( V_11 , V_14 , & V_120 , & V_121 ) ;
if ( V_167 )
return V_167 ;
V_249 -> V_247 = V_120 ;
V_249 -> V_248 = V_121 ;
} else {
return - V_15 ;
}
V_249 -> V_68 = type ;
V_249 -> V_14 = V_14 ;
return 0 ;
}
struct V_250 * F_155 ( struct V_10 * V_11 )
{
struct V_82 * V_43 ;
struct V_1 * V_5 ;
struct V_80 * V_83 ;
struct V_81 * V_82 ;
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_83 )
return V_11 -> V_83 -> V_171 . V_172 ;
if ( V_11 -> V_84 ) {
V_43 = V_11 -> V_84 ;
} else {
V_5 = F_56 ( V_11 ) ;
if ( ! V_5 )
return NULL ;
V_43 = V_5 -> V_84 ;
}
V_82 = F_26 ( F_27 ( V_43 ) ) ;
V_83 = V_82 -> V_83 ;
if ( ! V_83 )
return NULL ;
return V_83 -> V_171 . V_172 ;
}
void T_5 * F_156 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_20 & V_107 )
return NULL ;
if ( V_11 -> V_51 == V_206 )
return NULL ;
return V_11 -> V_198 ;
}
int F_157 ( struct V_10 * V_11 )
{
unsigned long V_68 ;
T_1 V_22 ;
F_82 ( & V_11 -> V_211 , V_68 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_73 ) ) {
V_22 = V_11 -> V_16 ;
F_22 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_20 ( V_11 , true ) ;
F_84 ( & V_11 -> V_211 , V_68 ) ;
return 0 ;
}
int F_158 ( struct V_10 * V_11 )
{
unsigned long V_68 ;
T_1 V_22 ;
F_82 ( & V_11 -> V_211 , V_68 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_73 ) ) {
V_22 = V_11 -> V_16 ;
F_23 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_20 ( V_11 , false ) ;
F_84 ( & V_11 -> V_211 , V_68 ) ;
return 0 ;
}
int F_159 ( struct V_10 * V_11 , const char * V_14 )
{
int V_89 ;
unsigned long V_68 ;
if ( ! V_11 )
return - V_15 ;
F_82 ( & V_11 -> V_211 , V_68 ) ;
V_89 = F_67 ( V_11 , V_14 ) ;
F_84 ( & V_11 -> V_211 , V_68 ) ;
return V_89 ;
}
int F_160 ( struct V_10 * V_11 , const char * V_14 )
{
int V_89 ;
unsigned long V_68 ;
if ( ! V_11 )
return - V_15 ;
F_82 ( & V_11 -> V_211 , V_68 ) ;
V_89 = F_68 ( V_11 , V_14 ) ;
F_84 ( & V_11 -> V_211 , V_68 ) ;
return V_89 ;
}
int F_161 ( const char * V_251 ,
int (* F_143)( struct V_10 * V_11 ,
void * V_125 ) ,
void * V_125 )
{
struct V_10 * V_142 ;
int V_89 = 0 ;
if ( ! V_251 || ! F_143 )
return - V_15 ;
F_18 ( L_68 ,
V_103 , V_251 ) ;
F_62 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_142 -> V_12 -> V_14 , V_251 ) ) {
F_18 ( L_69 ,
V_103 , V_142 -> V_14 ) ;
V_89 = (* F_143)( V_142 , V_125 ) ;
if ( V_89 )
break;
}
}
if ( V_89 )
F_18 ( L_70 ,
V_103 , V_89 ) ;
return V_89 ;
}
int F_162 ( struct V_10 * V_11 , T_2 V_252 )
{
int V_89 ;
unsigned long V_68 ;
if ( ! V_11 )
return - V_15 ;
if ( V_252 != V_179 &&
V_252 != V_52 &&
V_252 != V_72 )
return - V_15 ;
F_82 ( & V_11 -> V_211 , V_68 ) ;
if ( V_11 -> V_51 != V_145 ) {
V_89 = - V_15 ;
goto V_253;
}
V_11 -> V_205 = V_252 ;
V_89 = 0 ;
V_253:
F_84 ( & V_11 -> V_211 , V_68 ) ;
return V_89 ;
}
int F_163 ( struct V_10 * V_11 )
{
struct V_250 * V_171 ;
int V_89 = 0 ;
if ( V_146 . V_254 )
return V_146 . V_254 ( V_11 ) ;
V_171 = F_155 ( V_11 ) ;
if ( V_171 )
V_89 = F_164 ( V_171 ) ;
return V_89 ;
}
void T_4 F_165 ( void )
{
if ( F_166 () ) {
V_146 . V_184 = F_123 ;
V_146 . V_155 = F_126 ;
V_146 . V_158 = F_128 ;
V_146 . V_162 = F_130 ;
} else if ( F_167 () ) {
V_146 . V_184 = F_123 ;
V_146 . V_155 = F_126 ;
V_146 . V_158 = F_128 ;
V_146 . V_162 = F_130 ;
V_146 . V_87 = F_63 ;
} else if ( F_168 () || F_169 () || F_170 () ) {
V_146 . V_159 = F_45 ;
V_146 . V_160 = F_76 ;
V_146 . V_184 = F_125 ;
V_146 . V_155 = F_132 ;
V_146 . V_158 = F_133 ;
V_146 . V_162 = F_134 ;
V_146 . V_87 = F_63 ;
V_146 . V_183 = F_85 ;
V_146 . V_254 = F_88 ;
} else if ( F_171 () || F_172 () || F_173 () ||
F_174 () ) {
V_146 . V_159 = F_45 ;
V_146 . V_160 = F_76 ;
V_146 . V_184 = F_125 ;
V_146 . V_155 = F_132 ;
V_146 . V_158 = F_135 ;
V_146 . V_162 = F_134 ;
V_146 . V_87 = F_63 ;
} else {
F_4 ( 1 , L_71 ) ;
}
V_236 = true ;
}
const char * F_175 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
return V_11 -> V_90 ;
}
