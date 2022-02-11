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
char V_14 [ V_90 ] ;
struct V_82 * V_82 ;
if ( strlen ( V_11 -> V_14 ) + 7 > V_90 )
F_17 ( L_7 , V_91 ,
V_11 -> V_14 ) ;
strncpy ( V_14 , V_11 -> V_14 , V_90 - 7 ) ;
strcat ( V_14 , L_8 ) ;
V_82 = F_33 ( NULL , V_14 ) ;
if ( ! F_34 ( V_82 ) ) {
V_11 -> V_84 = V_82 ;
V_92 . V_93 ( V_11 ) ;
V_11 -> V_94 = F_35 ( V_14 , V_95 ) ;
} else {
if ( ! V_11 -> V_94 )
return 0 ;
V_11 -> V_84 = F_33 ( NULL , V_11 -> V_94 ) ;
}
if ( F_34 ( V_11 -> V_84 ) ) {
F_17 ( L_9 ,
V_11 -> V_14 , V_11 -> V_94 ) ;
return - V_15 ;
}
F_36 ( V_11 -> V_84 ) ;
if ( ! F_24 ( V_11 ) )
F_18 ( L_10 ,
V_11 -> V_14 , V_11 -> V_94 ) ;
return V_89 ;
}
static int F_37 ( struct V_10 * V_11 )
{
struct V_1 * V_96 ;
struct V_2 * V_3 ;
struct V_82 * V_43 ;
int V_4 = 0 ;
int V_89 = 0 ;
V_3 = V_11 -> V_97 . V_9 ;
while ( V_4 < V_11 -> V_98 ) {
V_96 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_96 -> V_82 )
continue;
V_43 = F_33 ( NULL , V_96 -> V_82 ) ;
if ( F_34 ( V_43 ) ) {
F_17 ( L_11 ,
V_11 -> V_14 , V_96 -> V_82 ) ;
V_89 = - V_15 ;
continue;
}
V_96 -> V_84 = V_43 ;
F_36 ( V_96 -> V_84 ) ;
}
return V_89 ;
}
static int F_38 ( struct V_10 * V_11 )
{
struct V_99 * V_100 ;
struct V_82 * V_43 ;
int V_4 ;
int V_89 = 0 ;
for ( V_4 = V_11 -> V_101 , V_100 = V_11 -> V_102 ; V_4 > 0 ; V_4 -- , V_100 ++ ) {
V_43 = F_33 ( NULL , V_100 -> V_82 ) ;
if ( F_34 ( V_43 ) ) {
F_17 ( L_12 ,
V_11 -> V_14 , V_100 -> V_82 ) ;
V_89 = - V_15 ;
continue;
}
V_100 -> V_84 = V_43 ;
F_36 ( V_100 -> V_84 ) ;
}
return V_89 ;
}
static void F_39 ( struct V_10 * V_11 )
{
struct V_99 * V_100 ;
int V_4 ;
F_18 ( L_13 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_101 , V_100 = V_11 -> V_102 ; V_4 > 0 ; V_4 -- , V_100 ++ )
if ( V_100 -> V_84 ) {
F_18 ( L_14 , V_100 -> V_103 ,
F_40 ( V_100 -> V_84 ) ) ;
F_41 ( V_100 -> V_84 ) ;
}
}
static void F_42 ( struct V_10 * V_11 )
{
struct V_99 * V_100 ;
int V_4 ;
F_18 ( L_15 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_101 , V_100 = V_11 -> V_102 ; V_4 > 0 ; V_4 -- , V_100 ++ )
if ( V_100 -> V_84 ) {
F_18 ( L_16 , V_100 -> V_103 ,
F_40 ( V_100 -> V_84 ) ) ;
F_43 ( V_100 -> V_84 ) ;
}
}
static int F_44 ( struct V_10 * V_11 )
{
struct V_1 * V_96 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_18 ( L_17 , V_11 -> V_14 ) ;
if ( V_11 -> V_84 )
F_41 ( V_11 -> V_84 ) ;
V_3 = V_11 -> V_97 . V_9 ;
while ( V_4 < V_11 -> V_98 ) {
V_96 = F_1 ( & V_3 , & V_4 ) ;
if ( V_96 -> V_84 && ( V_96 -> V_68 & V_104 ) )
F_41 ( V_96 -> V_84 ) ;
}
if ( V_11 -> V_68 & V_105 )
F_39 ( V_11 ) ;
return 0 ;
}
static int F_45 ( struct V_10 * V_11 )
{
struct V_1 * V_96 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_18 ( L_18 , V_11 -> V_14 ) ;
if ( V_11 -> V_84 )
F_43 ( V_11 -> V_84 ) ;
V_3 = V_11 -> V_97 . V_9 ;
while ( V_4 < V_11 -> V_98 ) {
V_96 = F_1 ( & V_3 , & V_4 ) ;
if ( V_96 -> V_84 && ( V_96 -> V_68 & V_104 ) )
F_43 ( V_96 -> V_84 ) ;
}
if ( V_11 -> V_68 & V_105 )
F_42 ( V_11 ) ;
return 0 ;
}
static void F_46 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_83 || ! V_11 -> V_106 . V_107 . V_108 )
return;
F_18 ( L_19 ,
V_11 -> V_14 , V_91 , V_11 -> V_106 . V_107 . V_108 ) ;
F_47 ( V_11 -> V_106 . V_107 . V_108 ,
V_11 -> V_83 -> V_109 ,
V_11 -> V_83 -> V_110 , V_11 -> V_106 . V_107 . V_111 ) ;
}
static int F_48 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_112 || ! V_11 -> V_83 )
return 0 ;
if ( V_11 -> V_68 & V_113 )
return 0 ;
if ( ! V_11 -> V_106 . V_107 . V_111 &&
! ( V_11 -> V_106 . V_107 . V_68 & V_114 ) )
return 0 ;
return F_49 ( V_11 -> V_83 -> V_109 ,
V_11 -> V_83 -> V_110 ,
V_11 -> V_106 . V_107 . V_111 , 0 ) ;
}
static int F_50 ( struct V_10 * V_11 )
{
struct V_115 * V_116 ;
int V_4 = 0 ;
if ( ! V_11 || ! V_11 -> V_117 )
return 0 ;
do {
V_116 = & V_11 -> V_117 [ V_4 ++ ] ;
} while ( V_116 -> V_118 != - 1 );
return V_4 - 1 ;
}
static int F_51 ( struct V_10 * V_11 )
{
struct V_119 * V_120 ;
int V_4 = 0 ;
if ( ! V_11 || ! V_11 -> V_121 )
return 0 ;
do {
V_120 = & V_11 -> V_121 [ V_4 ++ ] ;
} while ( V_120 -> V_122 != - 1 );
return V_4 - 1 ;
}
static int F_52 ( struct V_1 * V_96 )
{
struct V_123 * V_124 ;
int V_4 = 0 ;
if ( ! V_96 || ! V_96 -> V_125 )
return 0 ;
do {
V_124 = & V_96 -> V_125 [ V_4 ++ ] ;
} while ( V_124 -> V_126 != V_124 -> V_127 );
return V_4 - 1 ;
}
static int F_53 ( struct V_10 * V_11 , const char * V_14 ,
unsigned int * V_118 )
{
int V_4 ;
bool V_128 = false ;
if ( ! V_11 -> V_117 )
return - V_129 ;
V_4 = 0 ;
while ( V_11 -> V_117 [ V_4 ] . V_118 != - 1 ) {
if ( V_14 == V_11 -> V_117 [ V_4 ] . V_14 ||
! strcmp ( V_14 , V_11 -> V_117 [ V_4 ] . V_14 ) ) {
V_128 = true ;
break;
}
V_4 ++ ;
}
if ( ! V_128 )
return - V_129 ;
* V_118 = V_11 -> V_117 [ V_4 ] . V_118 ;
return 0 ;
}
static int F_54 ( struct V_10 * V_11 , const char * V_14 ,
unsigned int * V_130 )
{
int V_4 ;
bool V_128 = false ;
if ( ! V_11 -> V_121 )
return - V_129 ;
V_4 = 0 ;
while ( V_11 -> V_121 [ V_4 ] . V_122 != - 1 ) {
if ( V_14 == V_11 -> V_121 [ V_4 ] . V_14 ||
! strcmp ( V_14 , V_11 -> V_121 [ V_4 ] . V_14 ) ) {
V_128 = true ;
break;
}
V_4 ++ ;
}
if ( ! V_128 )
return - V_129 ;
* V_130 = V_11 -> V_121 [ V_4 ] . V_122 ;
return 0 ;
}
static int F_55 ( struct V_10 * V_11 , const char * V_14 ,
T_1 * V_126 , T_1 * V_127 )
{
int V_4 , V_63 ;
struct V_1 * V_96 ;
struct V_2 * V_3 = NULL ;
bool V_128 = false ;
V_3 = V_11 -> V_97 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_98 ) {
V_96 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_96 -> V_125 )
return - V_129 ;
V_63 = 0 ;
while ( V_96 -> V_125 [ V_63 ] . V_126 != V_96 -> V_125 [ V_63 ] . V_127 ) {
if ( V_14 == V_96 -> V_125 [ V_63 ] . V_14 ||
! strcmp ( V_14 , V_96 -> V_125 [ V_63 ] . V_14 ) ) {
V_128 = true ;
break;
}
V_63 ++ ;
}
if ( V_128 )
break;
}
if ( ! V_128 )
return - V_129 ;
* V_126 = V_96 -> V_125 [ V_63 ] . V_126 ;
* V_127 = V_96 -> V_125 [ V_63 ] . V_127 ;
return 0 ;
}
static void T_4 F_56 ( struct V_10 * V_11 )
{
struct V_1 * V_96 = NULL ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( ! V_11 )
return;
V_11 -> V_20 |= V_112 ;
V_3 = V_11 -> V_97 . V_9 ;
while ( V_4 < V_11 -> V_98 ) {
V_96 = F_1 ( & V_3 , & V_4 ) ;
if ( V_96 -> V_131 & V_132 ) {
V_11 -> V_133 = V_96 ;
V_11 -> V_20 &= ~ V_112 ;
break;
}
}
return;
}
static struct V_1 * F_57 ( struct V_10 * V_11 )
{
if ( ! V_11 || V_11 -> V_20 & V_112 || V_11 -> V_98 == 0 )
return NULL ;
return V_11 -> V_133 ;
}
static struct V_123 * T_4 F_58 ( struct V_10 * V_11 )
{
struct V_1 * V_96 ;
struct V_123 * V_124 ;
int V_128 = 0 , V_4 = 0 ;
V_96 = F_57 ( V_11 ) ;
if ( ! V_96 || ! V_96 -> V_125 )
return NULL ;
do {
V_124 = & V_96 -> V_125 [ V_4 ++ ] ;
if ( V_124 -> V_68 & V_134 )
V_128 = 1 ;
} while ( ! V_128 && V_124 -> V_126 != V_124 -> V_127 );
return ( V_128 ) ? V_124 : NULL ;
}
static void F_59 ( struct V_10 * V_11 )
{
T_2 V_31 , V_135 ;
T_1 V_22 ;
bool V_136 ;
struct V_80 * V_83 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
if ( V_11 -> V_68 & V_137 )
F_39 ( V_11 ) ;
F_14 ( V_11 ) ;
if ( V_11 -> V_68 & V_137 )
F_42 ( V_11 ) ;
V_22 = V_11 -> V_16 ;
V_135 = V_11 -> V_12 -> V_13 -> V_18 ;
V_83 = F_24 ( V_11 ) ;
if ( V_135 & V_34 ) {
if ( V_11 -> V_68 & V_138 ||
V_11 -> V_68 & V_139 ) {
V_31 = V_140 ;
} else {
if ( V_135 & V_73 )
F_22 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_74 & V_75 )
V_31 = V_78 ;
else
V_31 = V_79 ;
}
V_136 = ( V_83 && V_83 -> V_68 & V_141 ) ;
if ( V_136 && ! ( V_11 -> V_12 -> V_13 -> V_74 &
( V_142 | V_75 ) ) )
V_31 = V_143 ;
F_10 ( V_11 , V_31 , & V_22 ) ;
}
if ( V_135 & V_28 ) {
if ( V_11 -> V_68 & V_144 ) {
V_31 = V_143 ;
} else if ( V_11 -> V_68 & V_145 ) {
V_31 = V_140 ;
} else {
if ( V_135 & V_73 )
F_22 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_74 & V_76 )
V_31 = V_78 ;
else
V_31 = V_79 ;
}
F_8 ( V_11 , V_31 , & V_22 ) ;
}
if ( ( V_11 -> V_68 & V_146 ) &&
( V_135 & V_38 ) )
F_11 ( V_11 , V_11 -> V_12 -> V_13 -> V_35 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
if ( V_135 & V_57 ) {
V_31 = ( V_11 -> V_68 & V_147 ) ?
0 : 1 ;
F_19 ( V_11 , V_31 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
}
static void F_60 ( struct V_10 * V_11 )
{
T_2 V_31 , V_135 ;
T_1 V_22 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_135 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_135 & V_34 ) {
if ( V_11 -> V_68 & V_138 ) {
V_31 = V_143 ;
} else {
if ( V_135 & V_73 )
F_22 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_74 & V_75 )
V_31 = V_78 ;
else
V_31 = V_79 ;
}
F_10 ( V_11 , V_31 , & V_22 ) ;
}
if ( V_135 & V_28 ) {
if ( ( V_11 -> V_68 & V_145 ) ||
( V_11 -> V_68 & V_144 ) ) {
V_31 = V_143 ;
} else {
if ( V_135 & V_73 )
F_22 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_74 & V_76 )
V_31 = V_78 ;
else
V_31 = V_79 ;
}
F_8 ( V_11 , V_31 , & V_22 ) ;
}
if ( V_11 -> V_16 != V_22 )
F_6 ( V_22 , V_11 ) ;
}
static void F_61 ( struct V_10 * V_11 )
{
T_1 V_22 ;
T_2 V_135 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_135 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_135 & V_34 )
F_10 ( V_11 , V_143 , & V_22 ) ;
if ( V_135 & V_28 )
F_8 ( V_11 , V_143 , & V_22 ) ;
if ( V_135 & V_57 )
F_19 ( V_11 , 1 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
static struct V_10 * F_62 ( const char * V_14 )
{
struct V_10 * V_11 , * V_148 ;
V_11 = NULL ;
F_63 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_14 , V_148 -> V_14 ) ) {
V_11 = V_148 ;
break;
}
}
return V_11 ;
}
static int F_64 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_149 ) {
F_18 ( L_20 , V_11 -> V_14 ) ;
return 0 ;
}
V_11 -> V_83 = F_65 ( V_11 -> V_149 ) ;
if ( ! V_11 -> V_83 ) {
F_17 ( L_21 ,
V_11 -> V_14 , V_11 -> V_149 ) ;
return 0 ;
}
F_18 ( L_22 ,
V_11 -> V_14 , V_11 -> V_149 ) ;
return 0 ;
}
static int F_66 ( struct V_10 * V_11 , void * V_150 )
{
int V_89 = 0 ;
if ( V_11 -> V_51 != V_151 )
return 0 ;
F_18 ( L_23 , V_11 -> V_14 ) ;
if ( V_92 . V_87 )
V_89 |= V_92 . V_87 ( V_11 ) ;
V_89 |= F_32 ( V_11 ) ;
V_89 |= F_37 ( V_11 ) ;
V_89 |= F_38 ( V_11 ) ;
if ( ! V_89 )
V_11 -> V_51 = V_152 ;
else
F_17 ( L_24 , V_11 -> V_14 ) ;
return V_89 ;
}
static int F_67 ( struct V_10 * V_11 , const char * V_14 ,
struct V_153 * V_154 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_155 ; V_4 ++ ) {
const char * V_156 = V_11 -> V_157 [ V_4 ] . V_14 ;
if ( ! strcmp ( V_156 , V_14 ) ) {
V_154 -> V_158 = V_11 -> V_157 [ V_4 ] . V_158 ;
V_154 -> V_159 = V_11 -> V_157 [ V_4 ] . V_159 ;
F_18 ( L_25 ,
V_11 -> V_14 , V_91 , V_156 , V_154 -> V_158 ,
V_154 -> V_159 ) ;
return 0 ;
}
}
return - V_129 ;
}
static int F_68 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_153 V_154 ;
int V_89 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_92 . V_160 )
return - V_161 ;
V_89 = F_67 ( V_11 , V_14 , & V_154 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = V_92 . V_160 ( V_11 , & V_154 ) ;
return V_89 ;
}
static int F_69 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_153 V_154 ;
int V_89 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_92 . V_162 )
return - V_161 ;
V_89 = F_67 ( V_11 , V_14 , & V_154 ) ;
if ( V_89 < 0 )
return V_89 ;
if ( V_11 -> V_83 ) {
F_70 ( V_11 -> V_83 ) ;
V_89 = F_71 ( V_11 -> V_83 , V_11 ) ;
if ( V_89 ) {
F_4 ( 1 , L_26 ,
V_11 -> V_14 , V_11 -> V_83 -> V_14 , V_89 ) ;
return V_89 ;
}
}
F_44 ( V_11 ) ;
if ( V_92 . V_163 )
V_92 . V_163 ( V_11 ) ;
V_89 = V_92 . V_162 ( V_11 , & V_154 ) ;
if ( V_92 . V_164 )
V_92 . V_164 ( V_11 ) ;
F_45 ( V_11 ) ;
if ( V_89 == - V_165 )
F_17 ( L_27 , V_11 -> V_14 ) ;
if ( V_11 -> V_83 ) {
F_72 ( V_11 -> V_83 ) ;
F_73 ( V_11 -> V_83 , V_11 ) ;
}
return V_89 ;
}
static int F_74 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_153 V_154 ;
int V_89 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_92 . V_166 )
return - V_161 ;
V_89 = F_67 ( V_11 , V_14 , & V_154 ) ;
if ( V_89 < 0 )
return V_89 ;
return V_92 . V_166 ( V_11 , & V_154 ) ;
}
static bool F_75 ( struct V_10 * V_11 )
{
int V_4 , V_167 = 0 ;
if ( V_11 -> V_155 == 0 )
return false ;
for ( V_4 = 0 ; V_4 < V_11 -> V_155 ; V_4 ++ )
if ( F_74 ( V_11 , V_11 -> V_157 [ V_4 ] . V_14 ) > 0 )
V_167 ++ ;
if ( V_11 -> V_155 == V_167 )
return true ;
return false ;
}
static bool F_76 ( struct V_10 * V_11 )
{
int V_167 = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_155 && V_167 == 0 ; V_4 ++ )
if ( F_74 ( V_11 , V_11 -> V_157 [ V_4 ] . V_14 ) > 0 )
V_167 ++ ;
return ( V_167 ) ? true : false ;
}
static int F_77 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! V_11 -> V_83 || ! V_11 -> V_106 . V_107 . V_108 )
return - V_15 ;
if ( F_76 ( V_11 ) )
return 0 ;
F_18 ( L_28 , V_11 -> V_14 , V_91 ) ;
F_78 ( V_11 -> V_83 -> V_109 , V_11 -> V_83 -> V_110 ,
V_11 -> V_106 . V_107 . V_111 ) ;
V_22 = F_48 ( V_11 ) ;
if ( V_22 )
F_17 ( L_29 ,
V_11 -> V_14 ) ;
return 0 ;
}
static int F_79 ( struct V_10 * V_11 )
{
T_1 V_22 ;
int V_43 = 0 ;
int V_89 = 0 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_40 ) )
return - V_129 ;
if ( V_11 -> V_51 != V_52 ) {
F_17 ( L_30 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_68 & V_137 )
F_39 ( V_11 ) ;
F_18 ( L_31 , V_11 -> V_14 ) ;
V_22 = V_11 -> V_16 ;
V_89 = F_12 ( V_11 , & V_22 ) ;
if ( V_89 )
goto V_168;
F_6 ( V_22 , V_11 ) ;
if ( V_11 -> V_12 -> V_13 -> V_169 )
F_80 ( V_11 -> V_12 -> V_13 -> V_169 ) ;
V_43 = F_14 ( V_11 ) ;
if ( V_43 == V_47 ) {
F_17 ( L_32 ,
V_11 -> V_14 , V_47 ) ;
V_89 = - V_170 ;
goto V_168;
} else {
F_18 ( L_33 , V_11 -> V_14 , V_43 ) ;
}
V_89 = F_13 ( V_11 , & V_22 ) ;
if ( V_89 )
goto V_168;
F_6 ( V_22 , V_11 ) ;
V_168:
if ( V_11 -> V_68 & V_137 )
F_42 ( V_11 ) ;
return V_89 ;
}
static int F_81 ( struct V_10 * V_11 )
{
int V_4 , V_171 ;
F_18 ( L_34 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_172 ) {
V_171 = V_11 -> V_12 -> V_172 ( V_11 ) ;
} else {
if ( V_11 -> V_155 > 0 ) {
for ( V_4 = 0 ; V_4 < V_11 -> V_155 ; V_4 ++ )
F_68 ( V_11 , V_11 -> V_157 [ V_4 ] . V_14 ) ;
return 0 ;
} else {
V_171 = F_79 ( V_11 ) ;
if ( V_171 == - V_129 )
V_171 = 0 ;
}
}
F_16 ( V_11 ) ;
if ( V_11 -> V_12 -> V_13 ) {
F_3 ( V_11 ) ;
F_59 ( V_11 ) ;
}
return V_171 ;
}
static void F_82 ( void )
{
unsigned long V_68 ;
F_83 ( & V_173 , V_68 ) ;
F_84 () ;
F_85 ( & V_173 , V_68 ) ;
}
static void F_86 ( struct V_10 * V_11 )
{
if ( V_11 -> V_106 . V_107 . V_68 & V_174 )
return;
if ( ! F_87 ( V_11 -> V_83 -> V_175 . V_176 -> V_109 ,
V_11 -> V_83 -> V_175 . V_176 -> V_177 ,
V_11 -> V_106 . V_107 . V_178 ) )
return;
V_11 -> V_106 . V_107 . V_179 ++ ;
F_88 ( V_11 -> V_83 -> V_175 . V_176 -> V_109 ,
V_11 -> V_83 -> V_175 . V_176 -> V_177 ,
V_11 -> V_106 . V_107 . V_178 ) ;
}
static int F_89 ( struct V_10 * V_11 )
{
return V_11 -> V_106 . V_107 . V_179 ;
}
static int F_90 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_12 -> V_180 )
return 0 ;
return V_11 -> V_12 -> V_180 ( V_11 ) ;
}
static int F_91 ( struct V_10 * V_11 )
{
int V_171 ;
F_18 ( L_35 , V_11 -> V_14 ) ;
if ( V_11 -> V_20 & V_181 ) {
if ( V_11 -> V_64 )
F_21 ( V_11 -> V_64 , V_52 ) ;
V_11 -> V_20 &= ~ V_181 ;
return 0 ;
}
if ( V_11 -> V_51 != V_182 &&
V_11 -> V_51 != V_72 &&
V_11 -> V_51 != V_183 ) {
F_4 ( 1 , L_36 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_75 ( V_11 ) )
return 0 ;
if ( V_11 -> V_64 && ( ! V_11 -> V_64 -> V_65 ||
( ( V_11 -> V_51 == V_72 ) &&
V_11 -> V_64 -> V_67 ) ) ) {
F_21 ( V_11 -> V_64 , V_52 ) ;
F_82 () ;
} else if ( V_11 -> V_68 & V_184 ) {
F_82 () ;
}
F_28 ( V_11 , V_185 ) ;
if ( V_11 -> V_83 ) {
F_70 ( V_11 -> V_83 ) ;
V_171 = F_71 ( V_11 -> V_83 , V_11 ) ;
if ( V_171 ) {
F_4 ( 1 , L_26 ,
V_11 -> V_14 , V_11 -> V_83 -> V_14 , V_171 ) ;
return V_171 ;
}
}
F_44 ( V_11 ) ;
if ( V_92 . V_163 )
V_92 . V_163 ( V_11 ) ;
if ( V_11 -> V_68 & V_186 )
F_92 ( true ) ;
if ( V_92 . V_187 )
V_92 . V_187 ( V_11 ) ;
V_171 = ( V_92 . V_188 ) ? V_92 . V_188 ( V_11 ) :
- V_15 ;
if ( V_11 -> V_83 )
F_72 ( V_11 -> V_83 ) ;
if ( ! V_171 ) {
V_11 -> V_51 = V_52 ;
if ( V_11 -> V_12 -> V_13 ) {
if ( ! ( V_11 -> V_20 & V_21 ) )
F_3 ( V_11 ) ;
F_59 ( V_11 ) ;
}
V_171 = F_90 ( V_11 ) ;
} else {
if ( V_92 . V_164 )
V_92 . V_164 ( V_11 ) ;
F_45 ( V_11 ) ;
F_93 ( L_37 ,
V_11 -> V_14 , V_171 ) ;
if ( V_11 -> V_83 )
F_73 ( V_11 -> V_83 , V_11 ) ;
}
return V_171 ;
}
static int F_94 ( struct V_10 * V_11 )
{
if ( V_11 -> V_68 & V_189 ) {
V_11 -> V_20 |= V_181 ;
return 0 ;
}
F_18 ( L_38 , V_11 -> V_14 ) ;
if ( F_75 ( V_11 ) )
return 0 ;
if ( V_11 -> V_51 != V_52 ) {
F_4 ( 1 , L_39 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_12 -> V_13 )
F_60 ( V_11 ) ;
F_30 ( V_11 , V_185 ) ;
if ( V_11 -> V_83 )
F_70 ( V_11 -> V_83 ) ;
if ( V_11 -> V_68 & V_186 )
F_92 ( false ) ;
if ( V_92 . V_164 )
V_92 . V_164 ( V_11 ) ;
F_45 ( V_11 ) ;
if ( V_11 -> V_83 ) {
F_72 ( V_11 -> V_83 ) ;
F_73 ( V_11 -> V_83 , V_11 ) ;
}
if ( V_11 -> V_64 && V_11 -> V_64 -> V_67 ) {
F_21 ( V_11 -> V_64 , V_72 ) ;
F_82 () ;
} else if ( V_11 -> V_68 & V_184 ) {
F_82 () ;
}
V_11 -> V_51 = V_72 ;
return 0 ;
}
static int F_95 ( struct V_10 * V_11 )
{
int V_89 , V_4 ;
T_2 V_190 ;
if ( F_75 ( V_11 ) )
return 0 ;
if ( V_11 -> V_51 != V_72 &&
V_11 -> V_51 != V_52 ) {
F_4 ( 1 , L_40 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
F_18 ( L_41 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_191 ) {
V_190 = V_11 -> V_51 ;
if ( V_11 -> V_51 == V_72 )
F_91 ( V_11 ) ;
V_89 = V_11 -> V_12 -> V_191 ( V_11 ) ;
if ( V_89 ) {
if ( V_190 == V_72 )
F_94 ( V_11 ) ;
return V_89 ;
}
}
if ( V_11 -> V_12 -> V_13 ) {
if ( V_11 -> V_51 == V_72 )
F_91 ( V_11 ) ;
F_61 ( V_11 ) ;
}
if ( V_11 -> V_51 == V_52 ) {
F_30 ( V_11 , V_185 ) ;
if ( V_11 -> V_68 & V_186 )
F_92 ( false ) ;
if ( V_92 . V_164 )
V_92 . V_164 ( V_11 ) ;
F_45 ( V_11 ) ;
if ( V_11 -> V_83 )
F_73 ( V_11 -> V_83 , V_11 ) ;
}
for ( V_4 = 0 ; V_4 < V_11 -> V_155 ; V_4 ++ )
F_68 ( V_11 , V_11 -> V_157 [ V_4 ] . V_14 ) ;
if ( V_11 -> V_64 )
F_21 ( V_11 -> V_64 , V_183 ) ;
V_11 -> V_51 = V_183 ;
return 0 ;
}
static int F_96 ( struct V_192 * V_193 ,
struct V_10 * V_11 )
{
int V_194 , V_4 , V_195 ;
const char * V_3 ;
V_194 = F_97 ( V_193 , L_42 ) ;
if ( V_194 < 1 )
return - V_196 ;
for ( V_4 = 0 ; V_4 < V_194 ; V_4 ++ ) {
V_195 = F_98 ( V_193 , L_42 ,
V_4 , & V_3 ) ;
if ( V_195 )
continue;
if ( ! strcmp ( V_3 , V_11 -> V_14 ) ) {
F_18 ( L_43 ,
V_193 -> V_14 , V_4 , V_11 -> V_14 ) ;
return V_4 ;
}
}
return - V_196 ;
}
static int F_99 ( struct V_192 * V_193 ,
struct V_10 * V_11 ,
int * V_197 ,
struct V_192 * * V_128 )
{
struct V_192 * V_198 = NULL ;
int V_195 ;
V_195 = F_96 ( V_193 , V_11 ) ;
if ( V_195 >= 0 ) {
* V_128 = V_193 ;
* V_197 = V_195 ;
return 0 ;
}
F_100 (np, np0) {
struct V_192 * V_199 ;
int V_4 ;
V_195 = F_99 ( V_198 , V_11 , & V_4 , & V_199 ) ;
if ( V_195 == 0 ) {
* V_128 = V_199 ;
* V_197 = V_4 ;
return 0 ;
}
}
* V_128 = NULL ;
* V_197 = 0 ;
return - V_196 ;
}
static int T_4 F_101 ( struct V_10 * V_11 , void * V_150 ,
int V_197 , struct V_192 * V_193 )
{
struct V_123 * V_124 ;
void T_5 * va_start = NULL ;
if ( ! V_11 )
return - V_15 ;
F_56 ( V_11 ) ;
if ( ! V_11 -> V_12 -> V_13 )
return 0 ;
if ( V_11 -> V_20 & V_112 )
return - V_200 ;
V_124 = F_58 ( V_11 ) ;
if ( ! V_124 ) {
F_18 ( L_44 ,
V_11 -> V_14 ) ;
if ( ! V_193 ) {
F_93 ( L_45 , V_11 -> V_14 ) ;
return - V_200 ;
}
va_start = F_102 ( V_193 , V_197 + V_11 -> V_201 ) ;
} else {
va_start = F_103 ( V_124 -> V_126 , V_124 -> V_127 - V_124 -> V_126 ) ;
}
if ( ! va_start ) {
if ( V_124 )
F_93 ( L_46 , V_11 -> V_14 ) ;
else
F_93 ( L_47 ,
V_11 -> V_14 , V_197 , V_193 -> V_202 ) ;
return - V_200 ;
}
F_18 ( L_48 ,
V_11 -> V_14 , va_start ) ;
V_11 -> V_203 = va_start ;
return 0 ;
}
static int T_4 F_104 ( struct V_10 * V_11 , void * V_150 )
{
int V_171 , V_197 ;
struct V_192 * V_193 = NULL ;
if ( V_11 -> V_51 != V_151 )
return 0 ;
if ( F_105 () ) {
struct V_192 * V_204 ;
V_204 = F_106 ( NULL , L_49 ) ;
if ( ! V_204 )
return - V_196 ;
V_171 = F_99 ( V_204 , V_11 , & V_197 , & V_193 ) ;
if ( V_171 )
F_18 ( L_50 , V_11 -> V_14 ) ;
else if ( V_193 && V_197 )
F_17 ( L_51 ,
V_11 -> V_14 , V_193 -> V_14 ) ;
}
V_171 = F_101 ( V_11 , NULL , V_197 , V_193 ) ;
if ( V_171 < 0 ) {
F_4 ( 1 , L_52 ,
V_11 -> V_14 ) ;
return 0 ;
}
V_171 = F_66 ( V_11 , NULL ) ;
if ( V_171 < 0 ) {
F_4 ( 1 , L_53 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_193 ) {
if ( F_107 ( V_193 , L_54 , NULL ) )
V_11 -> V_68 |= V_205 ;
if ( F_107 ( V_193 , L_55 , NULL ) )
V_11 -> V_68 |= V_206 ;
if ( F_107 ( V_193 , L_56 , NULL ) )
V_11 -> V_68 |= V_189 ;
}
V_11 -> V_51 = V_182 ;
return 0 ;
}
static void T_4 F_108 ( struct V_10 * V_11 )
{
struct V_1 * V_96 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( V_11 -> V_51 != V_182 )
return;
V_3 = V_11 -> V_97 . V_9 ;
while ( V_4 < V_11 -> V_98 ) {
V_96 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_96 -> V_84 )
continue;
if ( V_96 -> V_68 & V_104 ) {
} else {
F_41 ( V_96 -> V_84 ) ;
}
}
return;
}
static int T_4 F_109 ( struct V_10 * V_11 )
{
int V_171 ;
if ( V_11 -> V_51 != V_182 )
return - V_15 ;
if ( V_11 -> V_68 & V_207 )
return - V_208 ;
if ( V_11 -> V_155 == 0 ) {
V_171 = F_91 ( V_11 ) ;
if ( V_171 ) {
F_17 ( L_57 ,
V_11 -> V_14 , V_11 -> V_51 ) ;
return - V_15 ;
}
}
if ( ! ( V_11 -> V_68 & V_205 ) )
V_171 = F_81 ( V_11 ) ;
return V_171 ;
}
static void T_4 F_110 ( struct V_10 * V_11 )
{
T_2 V_209 ;
if ( V_11 -> V_155 > 0 )
return;
V_209 = V_11 -> V_210 ;
if ( V_209 == V_211 )
V_209 = V_52 ;
if ( ( V_11 -> V_68 & ( V_206 | V_189 ) ) &&
( V_209 == V_72 ) ) {
V_11 -> V_20 |= V_181 ;
V_209 = V_52 ;
}
if ( V_209 == V_72 )
F_94 ( V_11 ) ;
else if ( V_209 == V_183 )
F_95 ( V_11 ) ;
else if ( V_209 != V_52 )
F_4 ( 1 , L_58 ,
V_11 -> V_14 , V_209 ) ;
return;
}
static int T_4 F_111 ( struct V_10 * V_11 , void * V_150 )
{
if ( V_11 -> V_51 != V_182 )
return 0 ;
if ( V_11 -> V_212 ) {
int V_171 ;
V_171 = F_91 ( V_11 -> V_212 ) ;
F_4 ( V_171 , L_59 ,
V_11 -> V_14 , V_11 -> V_212 -> V_14 ) ;
}
F_108 ( V_11 ) ;
if ( ! F_109 ( V_11 ) )
F_110 ( V_11 ) ;
if ( V_11 -> V_212 ) {
T_2 V_209 ;
V_209 = V_11 -> V_212 -> V_210 ;
if ( V_209 == V_72 )
F_94 ( V_11 -> V_212 ) ;
else if ( V_209 == V_183 )
F_95 ( V_11 -> V_212 ) ;
else if ( V_209 != V_52 )
F_4 ( 1 , L_58 ,
V_11 -> V_212 -> V_14 , V_209 ) ;
}
return 0 ;
}
static int T_4 F_112 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_14 || ! V_11 -> V_12 || ! V_11 -> V_12 -> V_14 ||
( V_11 -> V_51 != V_211 ) )
return - V_15 ;
F_18 ( L_60 , V_11 -> V_14 ) ;
if ( F_62 ( V_11 -> V_14 ) )
return - V_213 ;
F_113 ( & V_11 -> V_7 , & V_214 ) ;
F_114 ( & V_11 -> V_215 ) ;
F_114 ( & V_11 -> V_97 ) ;
F_115 ( & V_11 -> V_216 ) ;
F_116 ( & V_11 -> V_216 , & V_11 -> V_217 ) ;
V_11 -> V_51 = V_151 ;
if ( ! strcmp ( V_11 -> V_14 , V_218 ) )
V_185 = V_11 ;
return 0 ;
}
static int T_4 F_117 ( struct V_6 * * V_219 ,
struct V_6 * * V_220 )
{
unsigned int V_221 ;
if ( ( V_222 + V_223 ) <= V_224 ) {
* V_219 = & V_225 [ V_222 ++ ] ;
* V_220 = & V_225 [ V_222 ++ ] ;
return 0 ;
}
V_221 = sizeof( struct V_6 ) * V_223 ;
* V_220 = NULL ;
* V_219 = F_118 ( V_221 , 0 ) ;
* V_220 = ( void * ) ( * V_219 ) + sizeof( struct V_6 ) ;
V_226 ++ ;
F_18 ( L_61 ,
V_226 * V_223 ) ;
return 0 ;
}
static int T_4 F_119 ( struct V_1 * V_5 )
{
struct V_6 * V_219 , * V_220 ;
F_18 ( L_62 , V_5 -> V_227 -> V_14 ,
V_5 -> V_228 -> V_14 ) ;
F_117 ( & V_219 , & V_220 ) ;
V_219 -> V_8 = V_5 ;
F_120 ( & V_219 -> V_7 , & V_5 -> V_227 -> V_215 ) ;
V_5 -> V_227 -> V_229 ++ ;
V_220 -> V_8 = V_5 ;
F_120 ( & V_220 -> V_7 , & V_5 -> V_228 -> V_97 ) ;
V_5 -> V_228 -> V_98 ++ ;
return 0 ;
}
static int T_4 F_121 ( struct V_1 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_227 || ! V_5 -> V_228 || ! V_5 -> V_131 )
return - V_15 ;
if ( V_5 -> V_20 & V_230 )
return - V_213 ;
F_18 ( L_63 ,
V_5 -> V_227 -> V_14 , V_5 -> V_228 -> V_14 ) ;
if ( V_5 -> V_227 -> V_51 != V_151 )
F_112 ( V_5 -> V_227 ) ;
if ( V_5 -> V_228 -> V_51 != V_151 )
F_112 ( V_5 -> V_228 ) ;
F_119 ( V_5 ) ;
V_5 -> V_20 |= V_230 ;
return 0 ;
}
static int T_4 F_122 ( struct V_1 * * V_231 )
{
unsigned int V_4 = 0 ;
unsigned int V_221 ;
if ( V_225 ) {
F_4 ( 1 , L_64 ) ;
return - V_213 ;
}
if ( V_224 == 0 )
while ( V_231 [ V_4 ++ ] )
V_224 += V_223 ;
V_221 = sizeof( struct V_6 ) * V_224 ;
F_18 ( L_65 ,
V_91 , V_221 , V_224 ) ;
V_225 = F_118 ( V_221 , 0 ) ;
return 0 ;
}
static int F_123 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_68 & V_113 )
return 0 ;
if ( ! F_57 ( V_11 ) )
return 0 ;
return F_124 ( 0 , V_11 -> V_106 . V_232 . V_233 ,
V_11 -> V_106 . V_232 . V_234 ,
V_11 -> V_106 . V_232 . V_235 ) ;
}
static int F_125 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_68 & V_113 || ! V_11 -> V_83 )
return 0 ;
if ( ! F_57 ( V_11 ) )
return 0 ;
if ( ! V_11 -> V_106 . V_107 . V_111 &&
! ( V_11 -> V_106 . V_107 . V_68 & V_114 ) )
return 0 ;
return F_124 ( V_11 -> V_83 -> V_109 ,
V_11 -> V_83 -> V_110 ,
V_11 -> V_106 . V_107 . V_111 , 0 ) ;
}
static int F_126 ( struct V_10 * V_11 ,
struct V_153 * V_154 )
{
return F_127 ( V_154 -> V_158 , 0 ,
V_11 -> V_106 . V_232 . V_233 , 0 ) ;
}
static int F_128 ( struct V_10 * V_11 ,
struct V_153 * V_154 )
{
return F_129 ( V_154 -> V_158 , V_154 -> V_159 , 0 ,
V_11 -> V_106 . V_232 . V_233 , 0 , 0 ) ;
}
static int F_130 ( struct V_10 * V_11 ,
struct V_153 * V_154 )
{
return F_131 ( V_154 -> V_159 , 0 ,
V_11 -> V_106 . V_232 . V_233 , 0 ) ;
}
static int F_132 ( struct V_10 * V_11 ,
struct V_153 * V_154 )
{
if ( ! V_11 -> V_83 )
return - V_15 ;
return F_127 ( V_154 -> V_158 ,
V_11 -> V_83 -> V_175 . V_176 -> V_109 ,
V_11 -> V_83 -> V_175 . V_176 -> V_177 ,
V_11 -> V_106 . V_107 . V_236 ) ;
}
static int F_133 ( struct V_10 * V_11 ,
struct V_153 * V_154 )
{
if ( ! V_11 -> V_83 )
return - V_15 ;
if ( V_154 -> V_159 )
F_93 ( L_66 ,
V_11 -> V_14 , V_154 -> V_14 ) ;
return F_129 ( V_154 -> V_158 , V_154 -> V_158 ,
V_11 -> V_83 -> V_175 . V_176 -> V_109 ,
V_11 -> V_83 -> V_175 . V_176 -> V_177 ,
V_11 -> V_106 . V_107 . V_236 ,
V_11 -> V_106 . V_107 . V_236 +
V_237 ) ;
}
static int F_134 ( struct V_10 * V_11 ,
struct V_153 * V_154 )
{
if ( ! V_11 -> V_83 )
return - V_15 ;
return F_131 ( V_154 -> V_158 ,
V_11 -> V_83 -> V_175 . V_176 ->
V_109 ,
V_11 -> V_83 -> V_175 . V_176 -> V_177 ,
V_11 -> V_106 . V_107 . V_236 ) ;
}
static int F_135 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
V_11 -> V_106 . V_107 . V_111 = 0 ;
V_11 -> V_106 . V_107 . V_108 = 0 ;
return 0 ;
}
static int F_136 ( struct V_10 * V_11 ,
struct V_153 * V_154 )
{
return F_129 ( V_154 -> V_158 , V_154 -> V_159 ,
V_11 -> V_83 -> V_175 . V_176 -> V_109 ,
V_11 -> V_83 -> V_175 . V_176 -> V_177 ,
V_11 -> V_106 . V_107 . V_236 ,
V_11 -> V_106 . V_107 . V_238 ) ;
}
T_1 F_5 ( struct V_10 * V_11 , T_3 V_239 )
{
if ( V_11 -> V_68 & V_240 )
return F_137 ( V_11 -> V_203 + V_239 ) ;
else
return F_138 ( V_11 -> V_203 + V_239 ) ;
}
void F_7 ( T_1 V_22 , struct V_10 * V_11 , T_3 V_239 )
{
if ( V_11 -> V_68 & V_240 )
F_139 ( V_22 , V_11 -> V_203 + V_239 ) ;
else
F_140 ( V_22 , V_11 -> V_203 + V_239 ) ;
}
int F_141 ( struct V_10 * V_11 )
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
struct V_10 * F_142 ( const char * V_14 )
{
struct V_10 * V_11 ;
if ( ! V_14 )
return NULL ;
V_11 = F_62 ( V_14 ) ;
return V_11 ;
}
int F_143 ( int (* F_144)( struct V_10 * V_11 , void * V_150 ) ,
void * V_150 )
{
struct V_10 * V_148 ;
int V_89 = 0 ;
if ( ! F_144 )
return - V_15 ;
F_63 (temp_oh, &omap_hwmod_list, node) {
V_89 = (* F_144)( V_148 , V_150 ) ;
if ( V_89 )
break;
}
return V_89 ;
}
int T_4 F_145 ( struct V_1 * * V_231 )
{
int V_171 , V_4 ;
if ( ! V_241 )
return - V_15 ;
if ( ! V_231 )
return 0 ;
if ( V_231 [ 0 ] == NULL )
return 0 ;
if ( ! V_225 ) {
if ( F_122 ( V_231 ) ) {
F_93 ( L_67 ) ;
return - V_242 ;
}
}
V_4 = 0 ;
do {
V_171 = F_121 ( V_231 [ V_4 ] ) ;
F_4 ( V_171 && V_171 != - V_213 ,
L_68 ,
V_231 [ V_4 ] -> V_227 -> V_14 , V_231 [ V_4 ] -> V_228 -> V_14 , V_171 ) ;
} while ( V_231 [ ++ V_4 ] );
return 0 ;
}
static void T_4 F_146 ( struct V_10 * V_11 )
{
if ( ! V_185 || V_185 -> V_51 == V_211 )
F_93 ( L_69 ,
V_91 , V_218 ) ;
else if ( V_185 -> V_51 == V_151 && V_11 != V_185 )
F_147 ( V_218 ) ;
}
int T_4 F_147 ( const char * V_243 )
{
struct V_10 * V_11 ;
F_18 ( L_28 , V_243 , V_91 ) ;
V_11 = F_62 ( V_243 ) ;
if ( ! V_11 ) {
F_4 ( 1 , L_70 , V_243 ) ;
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
int V_171 ;
unsigned long V_68 ;
if ( ! V_11 )
return - V_15 ;
F_83 ( & V_11 -> V_216 , V_68 ) ;
V_171 = F_91 ( V_11 ) ;
F_85 ( & V_11 -> V_216 , V_68 ) ;
return V_171 ;
}
int F_150 ( struct V_10 * V_11 )
{
int V_171 ;
unsigned long V_68 ;
if ( ! V_11 )
return - V_15 ;
F_83 ( & V_11 -> V_216 , V_68 ) ;
V_171 = F_94 ( V_11 ) ;
F_85 ( & V_11 -> V_216 , V_68 ) ;
return V_171 ;
}
int F_151 ( struct V_10 * V_11 )
{
int V_171 ;
unsigned long V_68 ;
if ( ! V_11 )
return - V_15 ;
F_83 ( & V_11 -> V_216 , V_68 ) ;
V_171 = F_95 ( V_11 ) ;
F_85 ( & V_11 -> V_216 , V_68 ) ;
return V_171 ;
}
int F_152 ( struct V_10 * V_11 , unsigned long V_68 )
{
int V_89 = 0 ;
if ( V_68 & V_244 )
V_89 += F_50 ( V_11 ) ;
if ( V_68 & V_245 )
V_89 += F_51 ( V_11 ) ;
if ( V_68 & V_246 ) {
int V_4 = 0 ;
struct V_1 * V_96 ;
struct V_2 * V_3 = V_11 -> V_97 . V_9 ;
while ( V_4 < V_11 -> V_98 ) {
V_96 = F_1 ( & V_3 , & V_4 ) ;
V_89 += F_52 ( V_96 ) ;
}
}
return V_89 ;
}
int F_153 ( struct V_10 * V_11 , struct V_247 * V_195 )
{
struct V_1 * V_96 ;
struct V_2 * V_3 ;
int V_4 , V_63 , V_248 , V_249 , V_250 ;
int V_171 = 0 ;
V_248 = F_50 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_248 ; V_4 ++ ) {
unsigned int V_118 ;
if ( V_11 -> V_251 )
V_118 = V_11 -> V_251 ( ( V_11 -> V_117 + V_4 ) -> V_118 ) ;
else
V_118 = ( V_11 -> V_117 + V_4 ) -> V_118 ;
( V_195 + V_171 ) -> V_14 = ( V_11 -> V_117 + V_4 ) -> V_14 ;
( V_195 + V_171 ) -> V_252 = V_118 ;
( V_195 + V_171 ) -> V_253 = V_118 ;
( V_195 + V_171 ) -> V_68 = V_244 ;
V_171 ++ ;
}
V_249 = F_51 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_249 ; V_4 ++ ) {
( V_195 + V_171 ) -> V_14 = ( V_11 -> V_121 + V_4 ) -> V_14 ;
( V_195 + V_171 ) -> V_252 = ( V_11 -> V_121 + V_4 ) -> V_122 ;
( V_195 + V_171 ) -> V_253 = ( V_11 -> V_121 + V_4 ) -> V_122 ;
( V_195 + V_171 ) -> V_68 = V_245 ;
V_171 ++ ;
}
V_3 = V_11 -> V_97 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_98 ) {
V_96 = F_1 ( & V_3 , & V_4 ) ;
V_250 = F_52 ( V_96 ) ;
for ( V_63 = 0 ; V_63 < V_250 ; V_63 ++ ) {
( V_195 + V_171 ) -> V_14 = ( V_96 -> V_125 + V_63 ) -> V_14 ;
( V_195 + V_171 ) -> V_252 = ( V_96 -> V_125 + V_63 ) -> V_126 ;
( V_195 + V_171 ) -> V_253 = ( V_96 -> V_125 + V_63 ) -> V_127 ;
( V_195 + V_171 ) -> V_68 = V_246 ;
V_171 ++ ;
}
}
return V_171 ;
}
int F_154 ( struct V_10 * V_11 , struct V_247 * V_195 )
{
int V_4 , V_249 ;
int V_171 = 0 ;
V_249 = F_51 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_249 ; V_4 ++ ) {
( V_195 + V_171 ) -> V_14 = ( V_11 -> V_121 + V_4 ) -> V_14 ;
( V_195 + V_171 ) -> V_252 = ( V_11 -> V_121 + V_4 ) -> V_122 ;
( V_195 + V_171 ) -> V_253 = ( V_11 -> V_121 + V_4 ) -> V_122 ;
( V_195 + V_171 ) -> V_68 = V_245 ;
V_171 ++ ;
}
return V_171 ;
}
int F_155 ( struct V_10 * V_11 , unsigned int type ,
const char * V_14 , struct V_247 * V_254 )
{
int V_171 ;
unsigned int V_118 , V_130 ;
T_1 V_126 , V_127 ;
if ( ! V_11 || ! V_254 )
return - V_15 ;
if ( type == V_244 ) {
V_171 = F_53 ( V_11 , V_14 , & V_118 ) ;
if ( V_171 )
return V_171 ;
V_254 -> V_252 = V_118 ;
V_254 -> V_253 = V_118 ;
} else if ( type == V_245 ) {
V_171 = F_54 ( V_11 , V_14 , & V_130 ) ;
if ( V_171 )
return V_171 ;
V_254 -> V_252 = V_130 ;
V_254 -> V_253 = V_130 ;
} else if ( type == V_246 ) {
V_171 = F_55 ( V_11 , V_14 , & V_126 , & V_127 ) ;
if ( V_171 )
return V_171 ;
V_254 -> V_252 = V_126 ;
V_254 -> V_253 = V_127 ;
} else {
return - V_15 ;
}
V_254 -> V_68 = type ;
V_254 -> V_14 = V_14 ;
return 0 ;
}
struct V_255 * F_156 ( struct V_10 * V_11 )
{
struct V_82 * V_43 ;
struct V_1 * V_5 ;
struct V_80 * V_83 ;
struct V_81 * V_82 ;
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_83 )
return V_11 -> V_83 -> V_175 . V_176 ;
if ( V_11 -> V_84 ) {
V_43 = V_11 -> V_84 ;
} else {
V_5 = F_57 ( V_11 ) ;
if ( ! V_5 )
return NULL ;
V_43 = V_5 -> V_84 ;
}
V_82 = F_26 ( F_27 ( V_43 ) ) ;
V_83 = V_82 -> V_83 ;
if ( ! V_83 )
return NULL ;
return V_83 -> V_175 . V_176 ;
}
void T_5 * F_157 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_20 & V_112 )
return NULL ;
if ( V_11 -> V_51 == V_211 )
return NULL ;
return V_11 -> V_203 ;
}
int F_158 ( struct V_10 * V_11 )
{
unsigned long V_68 ;
T_1 V_22 ;
F_83 ( & V_11 -> V_216 , V_68 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_73 ) ) {
V_22 = V_11 -> V_16 ;
F_22 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_20 ( V_11 , true ) ;
F_85 ( & V_11 -> V_216 , V_68 ) ;
return 0 ;
}
int F_159 ( struct V_10 * V_11 )
{
unsigned long V_68 ;
T_1 V_22 ;
F_83 ( & V_11 -> V_216 , V_68 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_73 ) ) {
V_22 = V_11 -> V_16 ;
F_23 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_20 ( V_11 , false ) ;
F_85 ( & V_11 -> V_216 , V_68 ) ;
return 0 ;
}
int F_160 ( struct V_10 * V_11 , const char * V_14 )
{
int V_89 ;
unsigned long V_68 ;
if ( ! V_11 )
return - V_15 ;
F_83 ( & V_11 -> V_216 , V_68 ) ;
V_89 = F_68 ( V_11 , V_14 ) ;
F_85 ( & V_11 -> V_216 , V_68 ) ;
return V_89 ;
}
int F_161 ( struct V_10 * V_11 , const char * V_14 )
{
int V_89 ;
unsigned long V_68 ;
if ( ! V_11 )
return - V_15 ;
F_83 ( & V_11 -> V_216 , V_68 ) ;
V_89 = F_69 ( V_11 , V_14 ) ;
F_85 ( & V_11 -> V_216 , V_68 ) ;
return V_89 ;
}
int F_162 ( const char * V_256 ,
int (* F_144)( struct V_10 * V_11 ,
void * V_131 ) ,
void * V_131 )
{
struct V_10 * V_148 ;
int V_89 = 0 ;
if ( ! V_256 || ! F_144 )
return - V_15 ;
F_18 ( L_71 ,
V_91 , V_256 ) ;
F_63 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_148 -> V_12 -> V_14 , V_256 ) ) {
F_18 ( L_72 ,
V_91 , V_148 -> V_14 ) ;
V_89 = (* F_144)( V_148 , V_131 ) ;
if ( V_89 )
break;
}
}
if ( V_89 )
F_18 ( L_73 ,
V_91 , V_89 ) ;
return V_89 ;
}
int F_163 ( struct V_10 * V_11 , T_2 V_257 )
{
int V_89 ;
unsigned long V_68 ;
if ( ! V_11 )
return - V_15 ;
if ( V_257 != V_183 &&
V_257 != V_52 &&
V_257 != V_72 )
return - V_15 ;
F_83 ( & V_11 -> V_216 , V_68 ) ;
if ( V_11 -> V_51 != V_151 ) {
V_89 = - V_15 ;
goto V_258;
}
V_11 -> V_210 = V_257 ;
V_89 = 0 ;
V_258:
F_85 ( & V_11 -> V_216 , V_68 ) ;
return V_89 ;
}
int F_164 ( struct V_10 * V_11 )
{
struct V_255 * V_175 ;
int V_89 = 0 ;
if ( V_92 . V_259 )
return V_92 . V_259 ( V_11 ) ;
V_175 = F_156 ( V_11 ) ;
if ( V_175 )
V_89 = F_165 ( V_175 ) ;
return V_89 ;
}
void T_4 F_166 ( void )
{
if ( F_167 () ) {
V_92 . V_188 = F_123 ;
V_92 . V_160 = F_126 ;
V_92 . V_162 = F_128 ;
V_92 . V_166 = F_130 ;
} else if ( F_168 () ) {
V_92 . V_188 = F_123 ;
V_92 . V_160 = F_126 ;
V_92 . V_162 = F_128 ;
V_92 . V_166 = F_130 ;
V_92 . V_87 = F_64 ;
} else if ( F_169 () || F_170 () || F_171 () ) {
V_92 . V_163 = F_46 ;
V_92 . V_164 = F_77 ;
V_92 . V_188 = F_125 ;
V_92 . V_160 = F_132 ;
V_92 . V_162 = F_133 ;
V_92 . V_166 = F_134 ;
V_92 . V_87 = F_64 ;
V_92 . V_187 = F_86 ;
V_92 . V_259 = F_89 ;
V_92 . V_93 = F_135 ;
} else if ( F_172 () || F_173 () || F_174 () ||
F_175 () ) {
V_92 . V_163 = F_46 ;
V_92 . V_164 = F_77 ;
V_92 . V_188 = F_125 ;
V_92 . V_160 = F_132 ;
V_92 . V_162 = F_136 ;
V_92 . V_166 = F_134 ;
V_92 . V_87 = F_64 ;
V_92 . V_93 = F_135 ;
} else {
F_4 ( 1 , L_74 ) ;
}
V_241 = true ;
}
const char * F_176 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
return V_11 -> V_94 ;
}
