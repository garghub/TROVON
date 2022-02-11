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
T_1 V_22 ;
T_1 V_40 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_41 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_27 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_42 != V_43 ) {
F_14 ( L_4 , V_11 -> V_14 ) ;
return - V_15 ;
}
F_15 ( L_5 , V_11 -> V_14 ) ;
V_22 = V_11 -> V_16 ;
V_40 =
( 0x1 << V_11 -> V_12 -> V_13 -> V_27 -> V_44 ) ;
V_22 |= V_40 ;
F_6 ( V_22 , V_11 ) ;
return 0 ;
}
static int F_16 ( struct V_10 * V_11 , T_2 V_45 ,
T_1 * V_22 )
{
T_1 V_46 ;
T_2 V_47 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_48 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_27 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_47 = V_11 -> V_12 -> V_13 -> V_27 -> V_47 ;
V_46 = ( 0x1 << V_47 ) ;
* V_22 &= ~ V_46 ;
* V_22 |= V_45 << V_47 ;
return 0 ;
}
static void F_17 ( struct V_10 * V_11 , bool V_49 )
{
struct V_50 * V_51 ;
bool V_52 = false ;
T_3 V_53 ;
int V_54 ;
if ( ! V_11 -> V_55 || ! V_11 -> V_55 -> V_56 )
return;
for ( V_54 = 0 ; V_54 < V_11 -> V_55 -> V_57 ; V_54 ++ ) {
V_51 = V_11 -> V_55 -> V_58 [ V_54 ] ;
if ( ! ( V_51 -> V_59 & V_60 ) )
continue;
V_53 = V_51 -> V_61 ;
if ( V_49 )
V_51 -> V_61 |= V_62 ;
else
V_51 -> V_61 &= ~ V_62 ;
if ( V_53 != V_51 -> V_61 )
V_52 = true ;
}
if ( V_52 && V_11 -> V_42 == V_63 )
F_18 ( V_11 -> V_55 , V_63 ) ;
}
static int F_19 ( struct V_10 * V_11 , T_1 * V_22 )
{
if ( ! V_11 -> V_12 -> V_13 ||
! ( ( V_11 -> V_12 -> V_13 -> V_18 & V_64 ) ||
( V_11 -> V_12 -> V_13 -> V_65 & V_66 ) ||
( V_11 -> V_12 -> V_13 -> V_65 & V_67 ) ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_27 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_12 -> V_13 -> V_18 & V_64 )
* V_22 |= 0x1 << V_11 -> V_12 -> V_13 -> V_27 -> V_68 ;
if ( V_11 -> V_12 -> V_13 -> V_65 & V_66 )
F_10 ( V_11 , V_69 , V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_65 & V_67 )
F_8 ( V_11 , V_69 , V_22 ) ;
V_11 -> V_20 |= V_70 ;
return 0 ;
}
static int F_20 ( struct V_10 * V_11 , T_1 * V_22 )
{
if ( ! V_11 -> V_12 -> V_13 ||
! ( ( V_11 -> V_12 -> V_13 -> V_18 & V_64 ) ||
( V_11 -> V_12 -> V_13 -> V_65 & V_66 ) ||
( V_11 -> V_12 -> V_13 -> V_65 & V_67 ) ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_27 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_12 -> V_13 -> V_18 & V_64 )
* V_22 &= ~ ( 0x1 << V_11 -> V_12 -> V_13 -> V_27 -> V_68 ) ;
if ( V_11 -> V_12 -> V_13 -> V_65 & V_66 )
F_10 ( V_11 , V_71 , V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_65 & V_67 )
F_8 ( V_11 , V_71 , V_22 ) ;
V_11 -> V_20 &= ~ V_70 ;
return 0 ;
}
static int F_21 ( struct V_10 * V_11 , struct V_10 * V_72 )
{
if ( ! V_11 -> V_73 )
return - V_15 ;
if ( V_11 -> V_73 -> V_74 && V_11 -> V_73 -> V_74 -> V_59 & V_75 )
return 0 ;
return F_22 ( V_11 -> V_73 -> V_74 , V_72 -> V_73 -> V_74 ) ;
}
static int F_23 ( struct V_10 * V_11 , struct V_10 * V_72 )
{
if ( ! V_11 -> V_73 )
return - V_15 ;
if ( V_11 -> V_73 -> V_74 && V_11 -> V_73 -> V_74 -> V_59 & V_75 )
return 0 ;
return F_24 ( V_11 -> V_73 -> V_74 , V_72 -> V_73 -> V_74 ) ;
}
static int F_25 ( struct V_10 * V_11 )
{
int V_76 = 0 ;
if ( ! V_11 -> V_77 )
return 0 ;
V_11 -> V_73 = F_26 ( V_11 -> V_77 ) ;
if ( ! V_11 -> V_73 ) {
F_27 ( L_6 ,
V_11 -> V_14 , V_11 -> V_77 ) ;
return - V_15 ;
}
if ( ! V_11 -> V_73 -> V_74 )
F_27 ( L_7 ,
V_11 -> V_77 , V_11 -> V_73 -> V_14 ) ;
return V_76 ;
}
static int F_28 ( struct V_10 * V_11 )
{
struct V_1 * V_78 ;
struct V_2 * V_3 ;
struct V_79 * V_80 ;
int V_4 = 0 ;
int V_76 = 0 ;
V_3 = V_11 -> V_81 . V_9 ;
while ( V_4 < V_11 -> V_82 ) {
V_78 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_78 -> V_79 )
continue;
V_80 = F_26 ( V_78 -> V_79 ) ;
if ( ! V_80 ) {
F_27 ( L_8 ,
V_11 -> V_14 , V_78 -> V_79 ) ;
V_76 = - V_15 ;
}
V_78 -> V_73 = V_80 ;
}
return V_76 ;
}
static int F_29 ( struct V_10 * V_11 )
{
struct V_83 * V_84 ;
struct V_79 * V_80 ;
int V_4 ;
int V_76 = 0 ;
for ( V_4 = V_11 -> V_85 , V_84 = V_11 -> V_86 ; V_4 > 0 ; V_4 -- , V_84 ++ ) {
V_80 = F_26 ( V_84 -> V_79 ) ;
if ( ! V_80 ) {
F_27 ( L_9 ,
V_11 -> V_14 , V_84 -> V_79 ) ;
V_76 = - V_15 ;
}
V_84 -> V_73 = V_80 ;
}
return V_76 ;
}
static int F_30 ( struct V_10 * V_11 )
{
struct V_1 * V_78 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_15 ( L_10 , V_11 -> V_14 ) ;
if ( V_11 -> V_73 )
F_31 ( V_11 -> V_73 ) ;
V_3 = V_11 -> V_81 . V_9 ;
while ( V_4 < V_11 -> V_82 ) {
V_78 = F_1 ( & V_3 , & V_4 ) ;
if ( V_78 -> V_73 && ( V_78 -> V_59 & V_87 ) )
F_31 ( V_78 -> V_73 ) ;
}
return 0 ;
}
static int F_32 ( struct V_10 * V_11 )
{
struct V_1 * V_78 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_15 ( L_11 , V_11 -> V_14 ) ;
if ( V_11 -> V_73 )
F_33 ( V_11 -> V_73 ) ;
V_3 = V_11 -> V_81 . V_9 ;
while ( V_4 < V_11 -> V_82 ) {
V_78 = F_1 ( & V_3 , & V_4 ) ;
if ( V_78 -> V_73 && ( V_78 -> V_59 & V_87 ) )
F_33 ( V_78 -> V_73 ) ;
}
return 0 ;
}
static void F_34 ( struct V_10 * V_11 )
{
struct V_83 * V_84 ;
int V_4 ;
F_15 ( L_12 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_85 , V_84 = V_11 -> V_86 ; V_4 > 0 ; V_4 -- , V_84 ++ )
if ( V_84 -> V_73 ) {
F_15 ( L_13 , V_84 -> V_88 ,
V_84 -> V_73 -> V_14 ) ;
F_31 ( V_84 -> V_73 ) ;
}
}
static void F_35 ( struct V_10 * V_11 )
{
struct V_83 * V_84 ;
int V_4 ;
F_15 ( L_14 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_85 , V_84 = V_11 -> V_86 ; V_4 > 0 ; V_4 -- , V_84 ++ )
if ( V_84 -> V_73 ) {
F_15 ( L_15 , V_84 -> V_88 ,
V_84 -> V_73 -> V_14 ) ;
F_33 ( V_84 -> V_73 ) ;
}
}
static void F_36 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_74 || ! V_11 -> V_89 . V_90 . V_91 )
return;
F_15 ( L_16 ,
V_11 -> V_14 , V_92 , V_11 -> V_89 . V_90 . V_91 ) ;
F_37 ( V_11 -> V_89 . V_90 . V_91 ,
V_11 -> V_74 -> V_93 ,
V_11 -> V_74 -> V_94 ,
V_11 -> V_74 -> V_95 ,
V_11 -> V_89 . V_90 . V_96 ) ;
}
static int F_38 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_74 )
return - V_15 ;
if ( V_11 -> V_20 & V_97 )
return 0 ;
if ( V_11 -> V_59 & V_98 )
return 0 ;
return F_39 ( V_11 -> V_74 -> V_93 ,
V_11 -> V_74 -> V_94 ,
V_11 -> V_74 -> V_95 ,
V_11 -> V_89 . V_90 . V_96 ) ;
}
static int F_40 ( struct V_10 * V_11 )
{
struct V_99 * V_100 ;
int V_4 = 0 ;
if ( ! V_11 || ! V_11 -> V_101 )
return 0 ;
do {
V_100 = & V_11 -> V_101 [ V_4 ++ ] ;
} while ( V_100 -> V_102 != - 1 );
return V_4 - 1 ;
}
static int F_41 ( struct V_10 * V_11 )
{
struct V_103 * V_104 ;
int V_4 = 0 ;
if ( ! V_11 || ! V_11 -> V_105 )
return 0 ;
do {
V_104 = & V_11 -> V_105 [ V_4 ++ ] ;
} while ( V_104 -> V_106 != - 1 );
return V_4 - 1 ;
}
static int F_42 ( struct V_1 * V_78 )
{
struct V_107 * V_108 ;
int V_4 = 0 ;
if ( ! V_78 || ! V_78 -> V_109 )
return 0 ;
do {
V_108 = & V_78 -> V_109 [ V_4 ++ ] ;
} while ( V_108 -> V_110 != V_108 -> V_111 );
return V_4 - 1 ;
}
static int F_43 ( struct V_10 * V_11 , const char * V_14 ,
unsigned int * V_102 )
{
int V_4 ;
bool V_112 = false ;
if ( ! V_11 -> V_101 )
return - V_113 ;
V_4 = 0 ;
while ( V_11 -> V_101 [ V_4 ] . V_102 != - 1 ) {
if ( V_14 == V_11 -> V_101 [ V_4 ] . V_14 ||
! strcmp ( V_14 , V_11 -> V_101 [ V_4 ] . V_14 ) ) {
V_112 = true ;
break;
}
V_4 ++ ;
}
if ( ! V_112 )
return - V_113 ;
* V_102 = V_11 -> V_101 [ V_4 ] . V_102 ;
return 0 ;
}
static int F_44 ( struct V_10 * V_11 , const char * V_14 ,
unsigned int * V_114 )
{
int V_4 ;
bool V_112 = false ;
if ( ! V_11 -> V_105 )
return - V_113 ;
V_4 = 0 ;
while ( V_11 -> V_105 [ V_4 ] . V_106 != - 1 ) {
if ( V_14 == V_11 -> V_105 [ V_4 ] . V_14 ||
! strcmp ( V_14 , V_11 -> V_105 [ V_4 ] . V_14 ) ) {
V_112 = true ;
break;
}
V_4 ++ ;
}
if ( ! V_112 )
return - V_113 ;
* V_114 = V_11 -> V_105 [ V_4 ] . V_106 ;
return 0 ;
}
static int F_45 ( struct V_10 * V_11 , const char * V_14 ,
T_1 * V_110 , T_1 * V_111 )
{
int V_4 , V_54 ;
struct V_1 * V_78 ;
struct V_2 * V_3 = NULL ;
bool V_112 = false ;
V_3 = V_11 -> V_81 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_82 ) {
V_78 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_78 -> V_109 )
return - V_113 ;
V_54 = 0 ;
while ( V_78 -> V_109 [ V_54 ] . V_110 != V_78 -> V_109 [ V_54 ] . V_111 ) {
if ( V_14 == V_78 -> V_109 [ V_54 ] . V_14 ||
! strcmp ( V_14 , V_78 -> V_109 [ V_54 ] . V_14 ) ) {
V_112 = true ;
break;
}
V_54 ++ ;
}
if ( V_112 )
break;
}
if ( ! V_112 )
return - V_113 ;
* V_110 = V_78 -> V_109 [ V_54 ] . V_110 ;
* V_111 = V_78 -> V_109 [ V_54 ] . V_111 ;
return 0 ;
}
static void T_4 F_46 ( struct V_10 * V_11 )
{
struct V_1 * V_78 = NULL ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( ! V_11 )
return;
V_11 -> V_20 |= V_97 ;
V_3 = V_11 -> V_81 . V_9 ;
while ( V_4 < V_11 -> V_82 ) {
V_78 = F_1 ( & V_3 , & V_4 ) ;
if ( V_78 -> V_115 & V_116 ) {
V_11 -> V_117 = V_78 ;
V_11 -> V_20 &= ~ V_97 ;
break;
}
}
return;
}
static struct V_1 * F_47 ( struct V_10 * V_11 )
{
if ( ! V_11 || V_11 -> V_20 & V_97 || V_11 -> V_82 == 0 )
return NULL ;
return V_11 -> V_117 ;
}
static struct V_107 * T_4 F_48 ( struct V_10 * V_11 )
{
struct V_1 * V_78 ;
struct V_107 * V_108 ;
int V_112 = 0 , V_4 = 0 ;
V_78 = F_47 ( V_11 ) ;
if ( ! V_78 || ! V_78 -> V_109 )
return NULL ;
do {
V_108 = & V_78 -> V_109 [ V_4 ++ ] ;
if ( V_108 -> V_59 & V_118 )
V_112 = 1 ;
} while ( ! V_112 && V_108 -> V_110 != V_108 -> V_111 );
return ( V_112 ) ? V_108 : NULL ;
}
static void F_49 ( struct V_10 * V_11 )
{
T_2 V_29 , V_119 ;
T_1 V_22 ;
bool V_120 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_119 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_119 & V_32 ) {
V_120 = ( ( V_11 -> V_74 &&
V_11 -> V_74 -> V_59 & V_121 ) ||
( V_11 -> V_73 && V_11 -> V_73 -> V_74 &&
V_11 -> V_73 -> V_74 -> V_59 & V_121 ) ) ;
if ( V_120 && ! ( V_11 -> V_12 -> V_13 -> V_65 &
( V_122 | V_66 ) ) )
V_29 = V_123 ;
else
V_29 = ( V_11 -> V_59 & V_124 ) ?
V_125 : V_71 ;
F_10 ( V_11 , V_29 , & V_22 ) ;
}
if ( V_119 & V_26 ) {
if ( V_11 -> V_59 & V_126 ) {
V_29 = V_125 ;
} else {
if ( V_119 & V_64 )
F_19 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_65 & V_67 )
V_29 = V_69 ;
else
V_29 = V_71 ;
}
F_8 ( V_11 , V_29 , & V_22 ) ;
}
if ( ( V_11 -> V_59 & V_127 ) &&
( V_119 & V_36 ) )
F_11 ( V_11 , V_11 -> V_12 -> V_13 -> V_33 , & V_22 ) ;
if ( ( V_119 & V_32 ) && ! ( V_11 -> V_59 & V_124 ) )
F_19 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
if ( V_119 & V_48 ) {
V_29 = ( V_11 -> V_59 & V_128 ) ?
0 : 1 ;
F_16 ( V_11 , V_29 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
}
static void F_50 ( struct V_10 * V_11 )
{
T_2 V_29 , V_119 ;
T_1 V_22 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_119 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_119 & V_32 ) {
if ( V_11 -> V_59 & V_124 ||
! ( V_11 -> V_12 -> V_13 -> V_65 &
( V_122 | V_66 ) ) )
V_29 = V_123 ;
else
V_29 = V_71 ;
F_10 ( V_11 , V_29 , & V_22 ) ;
}
if ( V_119 & V_26 ) {
if ( V_11 -> V_59 & V_126 ) {
V_29 = V_123 ;
} else {
if ( V_119 & V_64 )
F_19 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_65 & V_67 )
V_29 = V_69 ;
else
V_29 = V_71 ;
}
F_8 ( V_11 , V_29 , & V_22 ) ;
}
if ( ( V_119 & V_32 ) && ! ( V_11 -> V_59 & V_124 ) )
F_19 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
static void F_51 ( struct V_10 * V_11 )
{
T_1 V_22 ;
T_2 V_119 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_119 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_119 & V_32 )
F_10 ( V_11 , V_123 , & V_22 ) ;
if ( V_119 & V_26 )
F_8 ( V_11 , V_123 , & V_22 ) ;
if ( V_119 & V_48 )
F_16 ( V_11 , 1 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
static struct V_10 * F_52 ( const char * V_14 )
{
struct V_10 * V_11 , * V_129 ;
V_11 = NULL ;
F_53 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_14 , V_129 -> V_14 ) ) {
V_11 = V_129 ;
break;
}
}
return V_11 ;
}
static int F_54 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_130 )
return 0 ;
V_11 -> V_74 = F_55 ( V_11 -> V_130 ) ;
if ( ! V_11 -> V_74 ) {
F_27 ( L_17 ,
V_11 -> V_14 , V_11 -> V_130 ) ;
return - V_15 ;
}
F_15 ( L_18 ,
V_11 -> V_14 , V_11 -> V_130 ) ;
return 0 ;
}
static int F_56 ( struct V_10 * V_11 , void * V_131 )
{
int V_76 = 0 ;
if ( V_11 -> V_42 != V_132 )
return 0 ;
F_15 ( L_19 , V_11 -> V_14 ) ;
V_76 |= F_25 ( V_11 ) ;
V_76 |= F_28 ( V_11 ) ;
V_76 |= F_29 ( V_11 ) ;
if ( V_133 . V_134 )
V_76 |= V_133 . V_134 ( V_11 ) ;
if ( ! V_76 )
V_11 -> V_42 = V_135 ;
else
F_27 ( L_20 , V_11 -> V_14 ) ;
return V_76 ;
}
static T_2 F_57 ( struct V_10 * V_11 , const char * V_14 ,
struct V_136 * V_137 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_138 ; V_4 ++ ) {
const char * V_139 = V_11 -> V_140 [ V_4 ] . V_14 ;
if ( ! strcmp ( V_139 , V_14 ) ) {
V_137 -> V_141 = V_11 -> V_140 [ V_4 ] . V_141 ;
V_137 -> V_142 = V_11 -> V_140 [ V_4 ] . V_142 ;
F_15 ( L_21 ,
V_11 -> V_14 , V_92 , V_139 , V_137 -> V_141 ,
V_137 -> V_142 ) ;
return 0 ;
}
}
return - V_113 ;
}
static int F_58 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_136 V_137 ;
T_2 V_76 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_133 . V_143 )
return - V_144 ;
V_76 = F_57 ( V_11 , V_14 , & V_137 ) ;
if ( F_59 ( V_76 ) )
return V_76 ;
V_76 = V_133 . V_143 ( V_11 , & V_137 ) ;
return V_76 ;
}
static int F_60 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_136 V_137 ;
int V_76 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_133 . V_145 )
return - V_144 ;
V_76 = F_57 ( V_11 , V_14 , & V_137 ) ;
if ( F_59 ( V_76 ) )
return V_76 ;
V_76 = V_133 . V_145 ( V_11 , & V_137 ) ;
if ( V_76 == - V_146 )
F_27 ( L_22 , V_11 -> V_14 ) ;
return V_76 ;
}
static int F_61 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_136 V_137 ;
T_2 V_76 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_133 . V_147 )
return - V_144 ;
V_76 = F_57 ( V_11 , V_14 , & V_137 ) ;
if ( F_59 ( V_76 ) )
return V_76 ;
return V_133 . V_147 ( V_11 , & V_137 ) ;
}
static bool F_62 ( struct V_10 * V_11 )
{
int V_4 ;
if ( V_11 -> V_138 == 0 )
return false ;
for ( V_4 = 0 ; V_4 < V_11 -> V_138 ; V_4 ++ )
if ( F_61 ( V_11 , V_11 -> V_140 [ V_4 ] . V_14 ) > 0 )
return true ;
return false ;
}
static int F_63 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! V_11 -> V_74 || ! V_11 -> V_89 . V_90 . V_91 )
return - V_15 ;
F_15 ( L_23 , V_11 -> V_14 , V_92 ) ;
F_64 ( V_11 -> V_74 -> V_93 ,
V_11 -> V_74 -> V_94 ,
V_11 -> V_74 -> V_95 ,
V_11 -> V_89 . V_90 . V_96 ) ;
if ( F_62 ( V_11 ) )
return 0 ;
V_22 = F_38 ( V_11 ) ;
if ( V_22 )
F_14 ( L_24 ,
V_11 -> V_14 ) ;
return 0 ;
}
static int F_65 ( struct V_10 * V_11 )
{
T_1 V_22 , V_37 ;
int V_80 = 0 ;
int V_76 = 0 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_38 ) )
return - V_113 ;
if ( V_11 -> V_42 != V_43 ) {
F_27 ( L_25
L_26 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_59 & V_148 )
F_34 ( V_11 ) ;
F_15 ( L_27 , V_11 -> V_14 ) ;
V_22 = V_11 -> V_16 ;
V_76 = F_12 ( V_11 , & V_22 ) ;
if ( V_76 )
goto V_149;
F_6 ( V_22 , V_11 ) ;
if ( V_11 -> V_12 -> V_13 -> V_150 )
F_66 ( V_11 -> V_12 -> V_13 -> V_150 ) ;
if ( V_11 -> V_12 -> V_13 -> V_18 & V_151 )
F_67 ( ( F_5 ( V_11 ,
V_11 -> V_12 -> V_13 -> V_152 )
& V_153 ) ,
V_154 , V_80 ) ;
else if ( V_11 -> V_12 -> V_13 -> V_18 & V_155 ) {
V_37 = ( 0x1 << V_11 -> V_12 -> V_13 -> V_27 -> V_39 ) ;
F_67 ( ! ( F_5 ( V_11 ,
V_11 -> V_12 -> V_13 -> V_17 )
& V_37 ) ,
V_154 , V_80 ) ;
}
if ( V_80 == V_154 )
F_27 ( L_28 ,
V_11 -> V_14 , V_154 ) ;
else
F_15 ( L_29 , V_11 -> V_14 , V_80 ) ;
V_76 = ( V_80 == V_154 ) ? - V_156 : 0 ;
V_149:
if ( V_11 -> V_59 & V_148 )
F_35 ( V_11 ) ;
return V_76 ;
}
static int F_68 ( struct V_10 * V_11 )
{
int V_4 , V_157 ;
F_15 ( L_30 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_158 ) {
V_157 = V_11 -> V_12 -> V_158 ( V_11 ) ;
} else {
if ( V_11 -> V_138 > 0 ) {
for ( V_4 = 0 ; V_4 < V_11 -> V_138 ; V_4 ++ )
F_58 ( V_11 , V_11 -> V_140 [ V_4 ] . V_14 ) ;
return 0 ;
} else {
V_157 = F_65 ( V_11 ) ;
if ( V_157 == - V_113 )
V_157 = 0 ;
}
}
F_13 ( V_11 ) ;
if ( V_11 -> V_12 -> V_13 ) {
F_3 ( V_11 ) ;
F_49 ( V_11 ) ;
}
return V_157 ;
}
static void F_69 ( void )
{
unsigned long V_59 ;
F_70 ( & V_159 , V_59 ) ;
if ( F_71 () && F_72 () )
F_73 () ;
else if ( F_74 () )
F_75 () ;
F_76 ( & V_159 , V_59 ) ;
}
static int F_77 ( struct V_10 * V_11 )
{
int V_157 ;
int V_160 = 0 ;
F_15 ( L_31 , V_11 -> V_14 ) ;
if ( V_11 -> V_20 & V_161 ) {
if ( V_11 -> V_55 )
F_18 ( V_11 -> V_55 , V_43 ) ;
V_11 -> V_20 &= ~ V_161 ;
return 0 ;
}
if ( V_11 -> V_42 != V_162 &&
V_11 -> V_42 != V_63 &&
V_11 -> V_42 != V_163 ) {
F_4 ( 1 , L_32 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_62 ( V_11 ) )
return 0 ;
if ( V_11 -> V_55 && ( ! V_11 -> V_55 -> V_56 ||
( ( V_11 -> V_42 == V_63 ) &&
V_11 -> V_55 -> V_58 ) ) ) {
F_18 ( V_11 -> V_55 , V_43 ) ;
F_69 () ;
}
F_21 ( V_11 , V_164 ) ;
if ( V_11 -> V_74 ) {
V_160 = F_78 ( V_11 -> V_74 ) ;
V_157 = F_79 ( V_11 -> V_74 , V_11 ) ;
if ( V_157 ) {
F_4 ( 1 , L_33 ,
V_11 -> V_14 , V_11 -> V_74 -> V_14 , V_157 ) ;
return V_157 ;
}
}
F_30 ( V_11 ) ;
if ( V_133 . V_165 )
V_133 . V_165 ( V_11 ) ;
V_157 = ( V_133 . V_166 ) ? V_133 . V_166 ( V_11 ) :
- V_15 ;
if ( ! V_157 ) {
if ( V_11 -> V_74 && V_160 )
F_80 ( V_11 -> V_74 ) ;
V_11 -> V_42 = V_43 ;
if ( V_11 -> V_12 -> V_13 ) {
if ( ! ( V_11 -> V_20 & V_21 ) )
F_3 ( V_11 ) ;
F_49 ( V_11 ) ;
}
} else {
F_63 ( V_11 ) ;
F_32 ( V_11 ) ;
F_15 ( L_34 ,
V_11 -> V_14 , V_157 ) ;
if ( V_11 -> V_74 )
F_81 ( V_11 -> V_74 , V_11 ) ;
}
return V_157 ;
}
static int F_82 ( struct V_10 * V_11 )
{
F_15 ( L_35 , V_11 -> V_14 ) ;
if ( V_11 -> V_42 != V_43 ) {
F_4 ( 1 , L_36 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_62 ( V_11 ) )
return 0 ;
if ( V_11 -> V_12 -> V_13 )
F_50 ( V_11 ) ;
F_23 ( V_11 , V_164 ) ;
if ( V_133 . V_167 )
V_133 . V_167 ( V_11 ) ;
F_32 ( V_11 ) ;
if ( V_11 -> V_74 )
F_81 ( V_11 -> V_74 , V_11 ) ;
if ( V_11 -> V_55 && V_11 -> V_55 -> V_58 ) {
F_18 ( V_11 -> V_55 , V_63 ) ;
F_69 () ;
}
V_11 -> V_42 = V_63 ;
return 0 ;
}
int F_83 ( struct V_10 * V_11 , T_2 V_45 )
{
T_1 V_22 ;
int V_168 = 0 ;
unsigned long V_59 ;
if ( ! V_11 || V_11 -> V_42 != V_43 )
return - V_15 ;
F_70 ( & V_11 -> V_169 , V_59 ) ;
V_22 = V_11 -> V_16 ;
V_168 = F_16 ( V_11 , V_45 , & V_22 ) ;
if ( ! V_168 )
F_6 ( V_22 , V_11 ) ;
F_76 ( & V_11 -> V_169 , V_59 ) ;
return V_168 ;
}
static int F_84 ( struct V_10 * V_11 )
{
int V_76 , V_4 ;
T_2 V_170 ;
if ( V_11 -> V_42 != V_63 &&
V_11 -> V_42 != V_43 ) {
F_4 ( 1 , L_37 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_62 ( V_11 ) )
return 0 ;
F_15 ( L_38 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_171 ) {
V_170 = V_11 -> V_42 ;
if ( V_11 -> V_42 == V_63 )
F_77 ( V_11 ) ;
V_76 = V_11 -> V_12 -> V_171 ( V_11 ) ;
if ( V_76 ) {
if ( V_170 == V_63 )
F_82 ( V_11 ) ;
return V_76 ;
}
}
if ( V_11 -> V_12 -> V_13 ) {
if ( V_11 -> V_42 == V_63 )
F_77 ( V_11 ) ;
F_51 ( V_11 ) ;
}
if ( V_11 -> V_42 == V_43 ) {
F_23 ( V_11 , V_164 ) ;
if ( V_133 . V_167 )
V_133 . V_167 ( V_11 ) ;
F_32 ( V_11 ) ;
if ( V_11 -> V_74 )
F_81 ( V_11 -> V_74 , V_11 ) ;
}
for ( V_4 = 0 ; V_4 < V_11 -> V_138 ; V_4 ++ )
F_58 ( V_11 , V_11 -> V_140 [ V_4 ] . V_14 ) ;
if ( V_11 -> V_55 )
F_18 ( V_11 -> V_55 , V_163 ) ;
V_11 -> V_42 = V_163 ;
return 0 ;
}
static void T_4 F_85 ( struct V_10 * V_11 , void * V_131 )
{
struct V_107 * V_108 ;
void T_5 * va_start ;
if ( ! V_11 )
return;
F_46 ( V_11 ) ;
if ( V_11 -> V_20 & V_97 )
return;
V_108 = F_48 ( V_11 ) ;
if ( ! V_108 ) {
F_15 ( L_39 ,
V_11 -> V_14 ) ;
return;
}
va_start = F_86 ( V_108 -> V_110 , V_108 -> V_111 - V_108 -> V_110 ) ;
if ( ! va_start ) {
F_87 ( L_40 , V_11 -> V_14 ) ;
return;
}
F_15 ( L_41 ,
V_11 -> V_14 , va_start ) ;
V_11 -> V_172 = va_start ;
}
static int T_4 F_88 ( struct V_10 * V_11 , void * V_131 )
{
int V_157 ;
if ( V_11 -> V_42 != V_132 )
return 0 ;
F_85 ( V_11 , NULL ) ;
V_157 = F_56 ( V_11 , NULL ) ;
if ( F_59 ( V_157 ) ) {
F_4 ( 1 , L_42 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_42 = V_162 ;
return 0 ;
}
static void T_4 F_89 ( struct V_10 * V_11 )
{
struct V_1 * V_78 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( V_11 -> V_42 != V_162 )
return;
V_3 = V_11 -> V_81 . V_9 ;
while ( V_4 < V_11 -> V_82 ) {
V_78 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_78 -> V_73 )
continue;
if ( V_78 -> V_59 & V_87 ) {
} else {
F_31 ( V_78 -> V_73 ) ;
}
}
return;
}
static int T_4 F_90 ( struct V_10 * V_11 )
{
int V_157 ;
if ( V_11 -> V_42 != V_162 )
return - V_15 ;
if ( V_11 -> V_138 == 0 ) {
V_157 = F_77 ( V_11 ) ;
if ( V_157 ) {
F_27 ( L_43 ,
V_11 -> V_14 , V_11 -> V_42 ) ;
return - V_15 ;
}
}
if ( ! ( V_11 -> V_59 & V_173 ) )
V_157 = F_68 ( V_11 ) ;
return V_157 ;
}
static void T_4 F_91 ( struct V_10 * V_11 )
{
T_2 V_174 ;
if ( V_11 -> V_138 > 0 )
return;
V_174 = V_11 -> V_175 ;
if ( V_174 == V_176 )
V_174 = V_43 ;
if ( ( V_11 -> V_59 & V_177 ) &&
( V_174 == V_63 ) ) {
V_11 -> V_20 |= V_161 ;
V_174 = V_43 ;
}
if ( V_174 == V_63 )
F_82 ( V_11 ) ;
else if ( V_174 == V_163 )
F_84 ( V_11 ) ;
else if ( V_174 != V_43 )
F_4 ( 1 , L_44 ,
V_11 -> V_14 , V_174 ) ;
return;
}
static int T_4 F_92 ( struct V_10 * V_11 , void * V_131 )
{
if ( V_11 -> V_42 != V_162 )
return 0 ;
F_89 ( V_11 ) ;
if ( ! F_90 ( V_11 ) )
F_91 ( V_11 ) ;
return 0 ;
}
static int T_4 F_93 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_14 || ! V_11 -> V_12 || ! V_11 -> V_12 -> V_14 ||
( V_11 -> V_42 != V_176 ) )
return - V_15 ;
F_15 ( L_45 , V_11 -> V_14 ) ;
if ( F_52 ( V_11 -> V_14 ) )
return - V_178 ;
F_94 ( & V_11 -> V_7 , & V_179 ) ;
F_95 ( & V_11 -> V_180 ) ;
F_95 ( & V_11 -> V_81 ) ;
F_96 ( & V_11 -> V_169 ) ;
V_11 -> V_42 = V_132 ;
if ( ! strcmp ( V_11 -> V_14 , V_181 ) )
V_164 = V_11 ;
return 0 ;
}
static int T_4 F_97 ( struct V_6 * * V_182 ,
struct V_6 * * V_183 )
{
unsigned int V_184 ;
if ( ( V_185 + V_186 ) <= V_187 ) {
* V_182 = & V_188 [ V_185 ++ ] ;
* V_183 = & V_188 [ V_185 ++ ] ;
return 0 ;
}
V_184 = sizeof( struct V_6 ) * V_186 ;
* V_183 = NULL ;
* V_182 = F_98 ( V_184 ) ;
memset ( * V_182 , 0 , V_184 ) ;
* V_183 = ( void * ) ( * V_182 ) + sizeof( struct V_6 ) ;
V_189 ++ ;
F_15 ( L_46 ,
V_189 * V_186 ) ;
return 0 ;
}
static int T_4 F_99 ( struct V_1 * V_5 )
{
struct V_6 * V_182 , * V_183 ;
F_15 ( L_47 , V_5 -> V_190 -> V_14 ,
V_5 -> V_191 -> V_14 ) ;
F_97 ( & V_182 , & V_183 ) ;
V_182 -> V_8 = V_5 ;
F_95 ( & V_182 -> V_7 ) ;
F_100 ( & V_182 -> V_7 , & V_5 -> V_190 -> V_180 ) ;
V_5 -> V_190 -> V_192 ++ ;
V_183 -> V_8 = V_5 ;
F_95 ( & V_183 -> V_7 ) ;
F_100 ( & V_183 -> V_7 , & V_5 -> V_191 -> V_81 ) ;
V_5 -> V_191 -> V_82 ++ ;
return 0 ;
}
static int T_4 F_101 ( struct V_1 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_190 || ! V_5 -> V_191 || ! V_5 -> V_115 )
return - V_15 ;
if ( V_5 -> V_20 & V_193 )
return - V_178 ;
F_15 ( L_48 ,
V_5 -> V_190 -> V_14 , V_5 -> V_191 -> V_14 ) ;
if ( V_5 -> V_190 -> V_42 != V_132 )
F_93 ( V_5 -> V_190 ) ;
if ( V_5 -> V_191 -> V_42 != V_132 )
F_93 ( V_5 -> V_191 ) ;
F_99 ( V_5 ) ;
V_5 -> V_20 |= V_193 ;
return 0 ;
}
static int T_4 F_102 ( struct V_1 * * V_194 )
{
unsigned int V_4 = 0 ;
unsigned int V_184 ;
if ( V_188 ) {
F_4 ( 1 , L_49 ) ;
return - V_178 ;
}
if ( V_187 == 0 )
while ( V_194 [ V_4 ++ ] )
V_187 += V_186 ;
V_184 = sizeof( struct V_6 ) * V_187 ;
F_15 ( L_50 ,
V_92 , V_184 , V_187 ) ;
V_188 = F_98 ( V_184 ) ;
memset ( V_188 , 0 , V_184 ) ;
return 0 ;
}
static int F_103 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_59 & V_98 )
return 0 ;
if ( ! F_47 ( V_11 ) )
return 0 ;
return F_104 ( V_11 -> V_89 . V_195 . V_196 ,
V_11 -> V_89 . V_195 . V_197 ,
V_11 -> V_89 . V_195 . V_198 ) ;
}
static int F_105 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_74 )
return - V_15 ;
if ( V_11 -> V_59 & V_98 )
return 0 ;
if ( ! F_47 ( V_11 ) )
return 0 ;
return F_106 ( V_11 -> V_74 -> V_93 ,
V_11 -> V_74 -> V_94 ,
V_11 -> V_74 -> V_95 ,
V_11 -> V_89 . V_90 . V_96 ) ;
}
static int F_107 ( struct V_10 * V_11 ,
struct V_136 * V_137 )
{
return F_108 ( V_11 -> V_89 . V_195 . V_196 ,
V_137 -> V_141 ) ;
}
static int F_109 ( struct V_10 * V_11 ,
struct V_136 * V_137 )
{
return F_110 ( V_11 -> V_89 . V_195 . V_196 ,
V_137 -> V_141 ,
V_137 -> V_142 ) ;
}
static int F_111 ( struct V_10 * V_11 ,
struct V_136 * V_137 )
{
return F_112 ( V_11 -> V_89 . V_195 . V_196 ,
V_137 -> V_142 ) ;
}
static int F_113 ( struct V_10 * V_11 ,
struct V_136 * V_137 )
{
if ( ! V_11 -> V_74 )
return - V_15 ;
return F_114 ( V_137 -> V_141 ,
V_11 -> V_74 -> V_199 . V_200 -> V_93 ,
V_11 -> V_74 -> V_199 . V_200 -> V_201 ,
V_11 -> V_89 . V_90 . V_202 ) ;
}
static int F_115 ( struct V_10 * V_11 ,
struct V_136 * V_137 )
{
if ( ! V_11 -> V_74 )
return - V_15 ;
if ( V_137 -> V_142 )
F_87 ( L_51 ,
V_11 -> V_14 , V_137 -> V_14 ) ;
return F_116 ( V_137 -> V_141 ,
V_11 -> V_74 -> V_199 . V_200 -> V_93 ,
V_11 -> V_74 -> V_199 . V_200 -> V_201 ,
V_11 -> V_89 . V_90 . V_202 ) ;
}
static int F_117 ( struct V_10 * V_11 ,
struct V_136 * V_137 )
{
if ( ! V_11 -> V_74 )
return - V_15 ;
return F_118 ( V_137 -> V_141 ,
V_11 -> V_74 -> V_199 . V_200 -> V_93 ,
V_11 -> V_74 -> V_199 . V_200 -> V_201 ,
V_11 -> V_89 . V_90 . V_202 ) ;
}
T_1 F_5 ( struct V_10 * V_11 , T_3 V_203 )
{
if ( V_11 -> V_59 & V_204 )
return F_119 ( V_11 -> V_172 + V_203 ) ;
else
return F_120 ( V_11 -> V_172 + V_203 ) ;
}
void F_7 ( T_1 V_22 , struct V_10 * V_11 , T_3 V_203 )
{
if ( V_11 -> V_59 & V_204 )
F_121 ( V_22 , V_11 -> V_172 + V_203 ) ;
else
F_122 ( V_22 , V_11 -> V_172 + V_203 ) ;
}
int F_123 ( struct V_10 * V_11 )
{
T_1 V_22 ;
int V_76 ;
if ( ! V_11 || ! ( V_11 -> V_16 ) )
return - V_15 ;
V_22 = V_11 -> V_16 ;
V_76 = F_12 ( V_11 , & V_22 ) ;
if ( V_76 )
goto error;
F_6 ( V_22 , V_11 ) ;
error:
return V_76 ;
}
int F_124 ( struct V_10 * V_11 , T_2 V_29 )
{
T_1 V_22 ;
int V_168 = 0 ;
if ( ! V_11 )
return - V_15 ;
V_22 = V_11 -> V_16 ;
V_168 = F_10 ( V_11 , V_29 , & V_22 ) ;
if ( ! V_168 )
F_6 ( V_22 , V_11 ) ;
return V_168 ;
}
struct V_10 * F_125 ( const char * V_14 )
{
struct V_10 * V_11 ;
if ( ! V_14 )
return NULL ;
V_11 = F_52 ( V_14 ) ;
return V_11 ;
}
int F_126 ( int (* F_127)( struct V_10 * V_11 , void * V_131 ) ,
void * V_131 )
{
struct V_10 * V_129 ;
int V_76 = 0 ;
if ( ! F_127 )
return - V_15 ;
F_53 (temp_oh, &omap_hwmod_list, node) {
V_76 = (* F_127)( V_129 , V_131 ) ;
if ( V_76 )
break;
}
return V_76 ;
}
int T_4 F_128 ( struct V_1 * * V_194 )
{
int V_157 , V_4 ;
if ( ! V_205 )
return - V_15 ;
if ( ! V_194 )
return 0 ;
if ( ! V_188 ) {
if ( F_102 ( V_194 ) ) {
F_87 ( L_52 ) ;
return - V_206 ;
}
}
V_4 = 0 ;
do {
V_157 = F_101 ( V_194 [ V_4 ] ) ;
F_4 ( V_157 && V_157 != - V_178 ,
L_53 ,
V_194 [ V_4 ] -> V_190 -> V_14 , V_194 [ V_4 ] -> V_191 -> V_14 , V_157 ) ;
} while ( V_194 [ ++ V_4 ] );
return 0 ;
}
static void T_4 F_129 ( struct V_10 * V_11 )
{
if ( ! V_164 || V_164 -> V_42 == V_176 )
F_87 ( L_54 ,
V_92 , V_181 ) ;
else if ( V_164 -> V_42 == V_132 && V_11 != V_164 )
F_130 ( V_181 ) ;
}
int T_4 F_130 ( const char * V_207 )
{
struct V_10 * V_11 ;
F_15 ( L_23 , V_207 , V_92 ) ;
V_11 = F_52 ( V_207 ) ;
if ( ! V_11 ) {
F_4 ( 1 , L_55 , V_207 ) ;
return - V_15 ;
}
F_129 ( V_11 ) ;
F_88 ( V_11 , NULL ) ;
F_92 ( V_11 , NULL ) ;
return 0 ;
}
static int T_4 F_131 ( void )
{
F_129 ( NULL ) ;
F_126 ( F_88 , NULL ) ;
F_126 ( F_92 , NULL ) ;
return 0 ;
}
int F_132 ( struct V_10 * V_11 )
{
int V_157 ;
unsigned long V_59 ;
if ( ! V_11 )
return - V_15 ;
F_70 ( & V_11 -> V_169 , V_59 ) ;
V_157 = F_77 ( V_11 ) ;
F_76 ( & V_11 -> V_169 , V_59 ) ;
return V_157 ;
}
int F_133 ( struct V_10 * V_11 )
{
unsigned long V_59 ;
if ( ! V_11 )
return - V_15 ;
F_70 ( & V_11 -> V_169 , V_59 ) ;
F_82 ( V_11 ) ;
F_76 ( & V_11 -> V_169 , V_59 ) ;
return 0 ;
}
int F_134 ( struct V_10 * V_11 )
{
unsigned long V_59 ;
if ( ! V_11 )
return - V_15 ;
F_70 ( & V_11 -> V_169 , V_59 ) ;
F_84 ( V_11 ) ;
F_76 ( & V_11 -> V_169 , V_59 ) ;
return 0 ;
}
int F_135 ( struct V_10 * V_11 )
{
unsigned long V_59 ;
F_70 ( & V_11 -> V_169 , V_59 ) ;
F_30 ( V_11 ) ;
F_76 ( & V_11 -> V_169 , V_59 ) ;
return 0 ;
}
int F_136 ( struct V_10 * V_11 )
{
unsigned long V_59 ;
F_70 ( & V_11 -> V_169 , V_59 ) ;
F_32 ( V_11 ) ;
F_76 ( & V_11 -> V_169 , V_59 ) ;
return 0 ;
}
void F_137 ( struct V_10 * V_11 )
{
F_138 ( ! V_11 ) ;
if ( ! V_11 -> V_12 -> V_13 || ! V_11 -> V_12 -> V_13 -> V_18 ) {
F_4 ( 1 , L_56 ,
V_11 -> V_14 ) ;
return;
}
F_5 ( V_11 , V_11 -> V_12 -> V_13 -> V_17 ) ;
}
int F_139 ( struct V_10 * V_11 )
{
int V_157 ;
unsigned long V_59 ;
if ( ! V_11 )
return - V_15 ;
F_70 ( & V_11 -> V_169 , V_59 ) ;
V_157 = F_68 ( V_11 ) ;
F_76 ( & V_11 -> V_169 , V_59 ) ;
return V_157 ;
}
int F_140 ( struct V_10 * V_11 )
{
struct V_1 * V_78 ;
struct V_2 * V_3 ;
int V_76 ;
int V_4 = 0 ;
V_76 = F_40 ( V_11 ) + F_41 ( V_11 ) ;
V_3 = V_11 -> V_81 . V_9 ;
while ( V_4 < V_11 -> V_82 ) {
V_78 = F_1 ( & V_3 , & V_4 ) ;
V_76 += F_42 ( V_78 ) ;
}
return V_76 ;
}
int F_141 ( struct V_10 * V_11 , struct V_208 * V_209 )
{
struct V_1 * V_78 ;
struct V_2 * V_3 ;
int V_4 , V_54 , V_210 , V_211 , V_212 ;
int V_157 = 0 ;
V_210 = F_40 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_210 ; V_4 ++ ) {
( V_209 + V_157 ) -> V_14 = ( V_11 -> V_101 + V_4 ) -> V_14 ;
( V_209 + V_157 ) -> V_213 = ( V_11 -> V_101 + V_4 ) -> V_102 ;
( V_209 + V_157 ) -> V_214 = ( V_11 -> V_101 + V_4 ) -> V_102 ;
( V_209 + V_157 ) -> V_59 = V_215 ;
V_157 ++ ;
}
V_211 = F_41 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_211 ; V_4 ++ ) {
( V_209 + V_157 ) -> V_14 = ( V_11 -> V_105 + V_4 ) -> V_14 ;
( V_209 + V_157 ) -> V_213 = ( V_11 -> V_105 + V_4 ) -> V_106 ;
( V_209 + V_157 ) -> V_214 = ( V_11 -> V_105 + V_4 ) -> V_106 ;
( V_209 + V_157 ) -> V_59 = V_216 ;
V_157 ++ ;
}
V_3 = V_11 -> V_81 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_82 ) {
V_78 = F_1 ( & V_3 , & V_4 ) ;
V_212 = F_42 ( V_78 ) ;
for ( V_54 = 0 ; V_54 < V_212 ; V_54 ++ ) {
( V_209 + V_157 ) -> V_14 = ( V_78 -> V_109 + V_54 ) -> V_14 ;
( V_209 + V_157 ) -> V_213 = ( V_78 -> V_109 + V_54 ) -> V_110 ;
( V_209 + V_157 ) -> V_214 = ( V_78 -> V_109 + V_54 ) -> V_111 ;
( V_209 + V_157 ) -> V_59 = V_217 ;
V_157 ++ ;
}
}
return V_157 ;
}
int F_142 ( struct V_10 * V_11 , unsigned int type ,
const char * V_14 , struct V_208 * V_218 )
{
int V_157 ;
unsigned int V_102 , V_114 ;
T_1 V_110 , V_111 ;
if ( ! V_11 || ! V_218 )
return - V_15 ;
if ( type == V_215 ) {
V_157 = F_43 ( V_11 , V_14 , & V_102 ) ;
if ( V_157 )
return V_157 ;
V_218 -> V_213 = V_102 ;
V_218 -> V_214 = V_102 ;
} else if ( type == V_216 ) {
V_157 = F_44 ( V_11 , V_14 , & V_114 ) ;
if ( V_157 )
return V_157 ;
V_218 -> V_213 = V_114 ;
V_218 -> V_214 = V_114 ;
} else if ( type == V_217 ) {
V_157 = F_45 ( V_11 , V_14 , & V_110 , & V_111 ) ;
if ( V_157 )
return V_157 ;
V_218 -> V_213 = V_110 ;
V_218 -> V_214 = V_111 ;
} else {
return - V_15 ;
}
V_218 -> V_59 = type ;
V_218 -> V_14 = V_14 ;
return 0 ;
}
struct V_219 * F_143 ( struct V_10 * V_11 )
{
struct V_79 * V_80 ;
struct V_1 * V_5 ;
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_73 ) {
V_80 = V_11 -> V_73 ;
} else {
V_5 = F_47 ( V_11 ) ;
if ( ! V_5 )
return NULL ;
V_80 = V_5 -> V_73 ;
}
if ( ! V_80 -> V_74 )
return NULL ;
return V_80 -> V_74 -> V_199 . V_200 ;
}
void T_5 * F_144 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_20 & V_97 )
return NULL ;
if ( V_11 -> V_42 == V_176 )
return NULL ;
return V_11 -> V_172 ;
}
int F_145 ( struct V_10 * V_11 ,
struct V_10 * V_72 )
{
return F_21 ( V_11 , V_72 ) ;
}
int F_146 ( struct V_10 * V_11 ,
struct V_10 * V_72 )
{
return F_23 ( V_11 , V_72 ) ;
}
int F_147 ( struct V_10 * V_11 )
{
unsigned long V_59 ;
T_1 V_22 ;
F_70 ( & V_11 -> V_169 , V_59 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_64 ) ) {
V_22 = V_11 -> V_16 ;
F_19 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_17 ( V_11 , true ) ;
F_76 ( & V_11 -> V_169 , V_59 ) ;
return 0 ;
}
int F_148 ( struct V_10 * V_11 )
{
unsigned long V_59 ;
T_1 V_22 ;
F_70 ( & V_11 -> V_169 , V_59 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_64 ) ) {
V_22 = V_11 -> V_16 ;
F_20 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_17 ( V_11 , false ) ;
F_76 ( & V_11 -> V_169 , V_59 ) ;
return 0 ;
}
int F_149 ( struct V_10 * V_11 , const char * V_14 )
{
int V_76 ;
unsigned long V_59 ;
if ( ! V_11 )
return - V_15 ;
F_70 ( & V_11 -> V_169 , V_59 ) ;
V_76 = F_58 ( V_11 , V_14 ) ;
F_76 ( & V_11 -> V_169 , V_59 ) ;
return V_76 ;
}
int F_150 ( struct V_10 * V_11 , const char * V_14 )
{
int V_76 ;
unsigned long V_59 ;
if ( ! V_11 )
return - V_15 ;
F_70 ( & V_11 -> V_169 , V_59 ) ;
V_76 = F_60 ( V_11 , V_14 ) ;
F_76 ( & V_11 -> V_169 , V_59 ) ;
return V_76 ;
}
int F_151 ( struct V_10 * V_11 , const char * V_14 )
{
int V_76 ;
unsigned long V_59 ;
if ( ! V_11 )
return - V_15 ;
F_70 ( & V_11 -> V_169 , V_59 ) ;
V_76 = F_61 ( V_11 , V_14 ) ;
F_76 ( & V_11 -> V_169 , V_59 ) ;
return V_76 ;
}
int F_152 ( const char * V_220 ,
int (* F_127)( struct V_10 * V_11 ,
void * V_115 ) ,
void * V_115 )
{
struct V_10 * V_129 ;
int V_76 = 0 ;
if ( ! V_220 || ! F_127 )
return - V_15 ;
F_15 ( L_57 ,
V_92 , V_220 ) ;
F_53 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_129 -> V_12 -> V_14 , V_220 ) ) {
F_15 ( L_58 ,
V_92 , V_129 -> V_14 ) ;
V_76 = (* F_127)( V_129 , V_115 ) ;
if ( V_76 )
break;
}
}
if ( V_76 )
F_15 ( L_59 ,
V_92 , V_76 ) ;
return V_76 ;
}
int F_153 ( struct V_10 * V_11 , T_2 V_221 )
{
int V_76 ;
unsigned long V_59 ;
if ( ! V_11 )
return - V_15 ;
if ( V_221 != V_163 &&
V_221 != V_43 &&
V_221 != V_63 )
return - V_15 ;
F_70 ( & V_11 -> V_169 , V_59 ) ;
if ( V_11 -> V_42 != V_132 ) {
V_76 = - V_15 ;
goto V_222;
}
V_11 -> V_175 = V_221 ;
V_76 = 0 ;
V_222:
F_76 ( & V_11 -> V_169 , V_59 ) ;
return V_76 ;
}
int F_154 ( struct V_10 * V_11 )
{
struct V_219 * V_199 ;
int V_76 = 0 ;
V_199 = F_143 ( V_11 ) ;
if ( V_199 )
V_76 = F_155 ( V_199 ) ;
return V_76 ;
}
int F_156 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_42 != V_132 ) {
F_87 ( L_60 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_59 |= V_173 ;
return 0 ;
}
int F_157 ( struct V_10 * V_11 , int V_223 , int V_224 )
{
int V_225 ;
F_158 () ;
if ( ! V_11 || ! V_11 -> V_55 || ! V_11 -> V_101 || V_223 < 0 ||
V_223 >= V_11 -> V_55 -> V_57 )
return - V_15 ;
for ( V_225 = 0 ; V_11 -> V_101 [ V_225 ] . V_102 >= 0 ; V_225 ++ )
;
if ( V_224 >= V_225 )
return - V_15 ;
if ( ! V_11 -> V_55 -> V_226 ) {
V_11 -> V_55 -> V_226 = F_159 ( sizeof( int ) * V_11 -> V_55 -> V_57 ,
V_227 ) ;
if ( ! V_11 -> V_55 -> V_226 )
return - V_206 ;
}
V_11 -> V_55 -> V_226 [ V_223 ] = V_224 ;
return 0 ;
}
void T_4 F_160 ( void )
{
if ( F_161 () || F_71 () ) {
V_133 . V_166 = F_103 ;
V_133 . V_143 = F_107 ;
V_133 . V_145 = F_109 ;
V_133 . V_147 = F_111 ;
} else if ( F_74 () || F_162 () ) {
V_133 . V_165 = F_36 ;
V_133 . V_167 = F_63 ;
V_133 . V_166 = F_105 ;
V_133 . V_143 = F_113 ;
V_133 . V_145 = F_115 ;
V_133 . V_147 = F_117 ;
V_133 . V_134 = F_54 ;
} else {
F_4 ( 1 , L_61 ) ;
}
V_205 = true ;
}
const char * F_163 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
return V_11 -> V_77 ;
}
