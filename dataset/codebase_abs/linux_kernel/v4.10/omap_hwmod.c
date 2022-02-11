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
static int F_20 ( struct V_10 * V_11 , T_1 * V_22 )
{
if ( ! V_11 -> V_12 -> V_13 ||
! ( ( V_11 -> V_12 -> V_13 -> V_18 & V_58 ) ||
( V_11 -> V_12 -> V_13 -> V_59 & V_60 ) ||
( V_11 -> V_12 -> V_13 -> V_59 & V_61 ) ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_29 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_12 -> V_13 -> V_18 & V_58 )
* V_22 |= 0x1 << V_11 -> V_12 -> V_13 -> V_29 -> V_62 ;
if ( V_11 -> V_12 -> V_13 -> V_59 & V_60 )
F_10 ( V_11 , V_63 , V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_59 & V_61 )
F_8 ( V_11 , V_63 , V_22 ) ;
return 0 ;
}
static int F_21 ( struct V_10 * V_11 , T_1 * V_22 )
{
if ( ! V_11 -> V_12 -> V_13 ||
! ( ( V_11 -> V_12 -> V_13 -> V_18 & V_58 ) ||
( V_11 -> V_12 -> V_13 -> V_59 & V_60 ) ||
( V_11 -> V_12 -> V_13 -> V_59 & V_61 ) ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_29 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_12 -> V_13 -> V_18 & V_58 )
* V_22 &= ~ ( 0x1 << V_11 -> V_12 -> V_13 -> V_29 -> V_62 ) ;
if ( V_11 -> V_12 -> V_13 -> V_59 & V_60 )
F_10 ( V_11 , V_64 , V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_59 & V_61 )
F_8 ( V_11 , V_64 , V_22 ) ;
return 0 ;
}
static struct V_65 * F_22 ( struct V_10 * V_11 )
{
struct V_66 * V_67 ;
if ( V_11 -> V_68 ) {
return V_11 -> V_68 ;
} else if ( V_11 -> V_69 ) {
if ( F_23 ( V_11 -> V_69 ) & V_70 )
return NULL ;
V_67 = F_24 ( F_25 ( V_11 -> V_69 ) ) ;
return V_67 -> V_68 ;
}
return NULL ;
}
static int F_26 ( struct V_10 * V_11 , struct V_10 * V_71 )
{
struct V_65 * V_68 , * V_72 ;
V_68 = F_22 ( V_11 ) ;
V_72 = F_22 ( V_71 ) ;
if ( ! V_68 || ! V_72 )
return - V_15 ;
if ( V_68 && V_68 -> V_73 & V_74 )
return 0 ;
return F_27 ( V_68 , V_72 ) ;
}
static int F_28 ( struct V_10 * V_11 , struct V_10 * V_71 )
{
struct V_65 * V_68 , * V_72 ;
V_68 = F_22 ( V_11 ) ;
V_72 = F_22 ( V_71 ) ;
if ( ! V_68 || ! V_72 )
return - V_15 ;
if ( V_68 && V_68 -> V_73 & V_74 )
return 0 ;
return F_29 ( V_68 , V_72 ) ;
}
static int F_30 ( struct V_10 * V_11 )
{
int V_75 = 0 ;
char V_14 [ V_76 ] ;
struct V_67 * V_67 ;
static const char V_77 [] = L_7 ;
if ( strlen ( V_11 -> V_14 ) >= V_76 - strlen ( V_77 ) )
F_17 ( L_8 , V_78 ,
V_11 -> V_14 ) ;
F_31 ( V_14 , V_11 -> V_14 , V_76 - strlen ( V_77 ) ) ;
F_32 ( V_14 , V_77 , V_76 ) ;
V_67 = F_33 ( NULL , V_14 ) ;
if ( ! F_34 ( V_67 ) ) {
V_11 -> V_69 = V_67 ;
V_79 . V_80 ( V_11 ) ;
V_11 -> V_81 = F_35 ( V_14 , V_82 ) ;
} else {
if ( ! V_11 -> V_81 )
return 0 ;
V_11 -> V_69 = F_33 ( NULL , V_11 -> V_81 ) ;
}
if ( F_34 ( V_11 -> V_69 ) ) {
F_17 ( L_9 ,
V_11 -> V_14 , V_11 -> V_81 ) ;
return - V_15 ;
}
F_36 ( V_11 -> V_69 ) ;
if ( ! F_22 ( V_11 ) )
F_18 ( L_10 ,
V_11 -> V_14 , V_11 -> V_81 ) ;
return V_75 ;
}
static int F_37 ( struct V_10 * V_11 )
{
struct V_1 * V_83 ;
struct V_2 * V_3 ;
struct V_67 * V_43 ;
int V_4 = 0 ;
int V_75 = 0 ;
V_3 = V_11 -> V_84 . V_9 ;
while ( V_4 < V_11 -> V_85 ) {
V_83 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_83 -> V_67 )
continue;
V_43 = F_33 ( NULL , V_83 -> V_67 ) ;
if ( F_34 ( V_43 ) ) {
F_17 ( L_11 ,
V_11 -> V_14 , V_83 -> V_67 ) ;
V_75 = - V_15 ;
continue;
}
V_83 -> V_69 = V_43 ;
F_36 ( V_83 -> V_69 ) ;
}
return V_75 ;
}
static int F_38 ( struct V_10 * V_11 )
{
struct V_86 * V_87 ;
struct V_67 * V_43 ;
int V_4 ;
int V_75 = 0 ;
for ( V_4 = V_11 -> V_88 , V_87 = V_11 -> V_89 ; V_4 > 0 ; V_4 -- , V_87 ++ ) {
V_43 = F_33 ( NULL , V_87 -> V_67 ) ;
if ( F_34 ( V_43 ) ) {
F_17 ( L_12 ,
V_11 -> V_14 , V_87 -> V_67 ) ;
V_75 = - V_15 ;
continue;
}
V_87 -> V_69 = V_43 ;
F_36 ( V_87 -> V_69 ) ;
}
return V_75 ;
}
static void F_39 ( struct V_10 * V_11 )
{
struct V_86 * V_87 ;
int V_4 ;
F_18 ( L_13 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_88 , V_87 = V_11 -> V_89 ; V_4 > 0 ; V_4 -- , V_87 ++ )
if ( V_87 -> V_69 ) {
F_18 ( L_14 , V_87 -> V_90 ,
F_40 ( V_87 -> V_69 ) ) ;
F_41 ( V_87 -> V_69 ) ;
}
}
static void F_42 ( struct V_10 * V_11 )
{
struct V_86 * V_87 ;
int V_4 ;
F_18 ( L_15 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_88 , V_87 = V_11 -> V_89 ; V_4 > 0 ; V_4 -- , V_87 ++ )
if ( V_87 -> V_69 ) {
F_18 ( L_16 , V_87 -> V_90 ,
F_40 ( V_87 -> V_69 ) ) ;
F_43 ( V_87 -> V_69 ) ;
}
}
static int F_44 ( struct V_10 * V_11 )
{
struct V_1 * V_83 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_18 ( L_17 , V_11 -> V_14 ) ;
if ( V_11 -> V_69 )
F_41 ( V_11 -> V_69 ) ;
V_3 = V_11 -> V_84 . V_9 ;
while ( V_4 < V_11 -> V_85 ) {
V_83 = F_1 ( & V_3 , & V_4 ) ;
if ( V_83 -> V_69 && ( V_83 -> V_73 & V_91 ) )
F_41 ( V_83 -> V_69 ) ;
}
if ( V_11 -> V_73 & V_92 )
F_39 ( V_11 ) ;
return 0 ;
}
static int F_45 ( struct V_10 * V_11 )
{
struct V_1 * V_83 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_18 ( L_18 , V_11 -> V_14 ) ;
if ( V_11 -> V_69 )
F_43 ( V_11 -> V_69 ) ;
V_3 = V_11 -> V_84 . V_9 ;
while ( V_4 < V_11 -> V_85 ) {
V_83 = F_1 ( & V_3 , & V_4 ) ;
if ( V_83 -> V_69 && ( V_83 -> V_73 & V_91 ) )
F_43 ( V_83 -> V_69 ) ;
}
if ( V_11 -> V_73 & V_92 )
F_42 ( V_11 ) ;
return 0 ;
}
static void F_46 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_68 || ! V_11 -> V_93 . V_94 . V_95 )
return;
F_18 ( L_19 ,
V_11 -> V_14 , V_78 , V_11 -> V_93 . V_94 . V_95 ) ;
F_47 ( V_11 -> V_93 . V_94 . V_95 ,
V_11 -> V_68 -> V_96 ,
V_11 -> V_68 -> V_97 , V_11 -> V_93 . V_94 . V_98 ) ;
}
static int F_48 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_99 || ! V_11 -> V_68 )
return 0 ;
if ( V_11 -> V_73 & V_100 )
return 0 ;
if ( ! V_11 -> V_93 . V_94 . V_98 &&
! ( V_11 -> V_93 . V_94 . V_73 & V_101 ) )
return 0 ;
return F_49 ( V_11 -> V_68 -> V_96 ,
V_11 -> V_68 -> V_97 ,
V_11 -> V_93 . V_94 . V_98 , 0 ) ;
}
static int F_50 ( struct V_10 * V_11 )
{
struct V_102 * V_103 ;
int V_4 = 0 ;
if ( ! V_11 || ! V_11 -> V_104 )
return 0 ;
do {
V_103 = & V_11 -> V_104 [ V_4 ++ ] ;
} while ( V_103 -> V_105 != - 1 );
return V_4 - 1 ;
}
static int F_51 ( struct V_10 * V_11 )
{
struct V_106 * V_107 ;
int V_4 = 0 ;
if ( ! V_11 || ! V_11 -> V_108 )
return 0 ;
do {
V_107 = & V_11 -> V_108 [ V_4 ++ ] ;
} while ( V_107 -> V_109 != - 1 );
return V_4 - 1 ;
}
static int F_52 ( struct V_1 * V_83 )
{
struct V_110 * V_111 ;
int V_4 = 0 ;
if ( ! V_83 || ! V_83 -> V_112 )
return 0 ;
do {
V_111 = & V_83 -> V_112 [ V_4 ++ ] ;
} while ( V_111 -> V_113 != V_111 -> V_114 );
return V_4 - 1 ;
}
static int F_53 ( struct V_10 * V_11 , const char * V_14 ,
unsigned int * V_105 )
{
int V_4 ;
bool V_115 = false ;
if ( ! V_11 -> V_104 )
return - V_116 ;
V_4 = 0 ;
while ( V_11 -> V_104 [ V_4 ] . V_105 != - 1 ) {
if ( V_14 == V_11 -> V_104 [ V_4 ] . V_14 ||
! strcmp ( V_14 , V_11 -> V_104 [ V_4 ] . V_14 ) ) {
V_115 = true ;
break;
}
V_4 ++ ;
}
if ( ! V_115 )
return - V_116 ;
* V_105 = V_11 -> V_104 [ V_4 ] . V_105 ;
return 0 ;
}
static int F_54 ( struct V_10 * V_11 , const char * V_14 ,
unsigned int * V_117 )
{
int V_4 ;
bool V_115 = false ;
if ( ! V_11 -> V_108 )
return - V_116 ;
V_4 = 0 ;
while ( V_11 -> V_108 [ V_4 ] . V_109 != - 1 ) {
if ( V_14 == V_11 -> V_108 [ V_4 ] . V_14 ||
! strcmp ( V_14 , V_11 -> V_108 [ V_4 ] . V_14 ) ) {
V_115 = true ;
break;
}
V_4 ++ ;
}
if ( ! V_115 )
return - V_116 ;
* V_117 = V_11 -> V_108 [ V_4 ] . V_109 ;
return 0 ;
}
static int F_55 ( struct V_10 * V_11 , const char * V_14 ,
T_1 * V_113 , T_1 * V_114 )
{
int V_4 , V_118 ;
struct V_1 * V_83 ;
struct V_2 * V_3 = NULL ;
bool V_115 = false ;
V_3 = V_11 -> V_84 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_85 ) {
V_83 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_83 -> V_112 )
return - V_116 ;
V_118 = 0 ;
while ( V_83 -> V_112 [ V_118 ] . V_113 != V_83 -> V_112 [ V_118 ] . V_114 ) {
if ( V_14 == V_83 -> V_112 [ V_118 ] . V_14 ||
! strcmp ( V_14 , V_83 -> V_112 [ V_118 ] . V_14 ) ) {
V_115 = true ;
break;
}
V_118 ++ ;
}
if ( V_115 )
break;
}
if ( ! V_115 )
return - V_116 ;
* V_113 = V_83 -> V_112 [ V_118 ] . V_113 ;
* V_114 = V_83 -> V_112 [ V_118 ] . V_114 ;
return 0 ;
}
static void T_3 F_56 ( struct V_10 * V_11 )
{
struct V_1 * V_83 = NULL ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( ! V_11 )
return;
V_11 -> V_20 |= V_99 ;
V_3 = V_11 -> V_84 . V_9 ;
while ( V_4 < V_11 -> V_85 ) {
V_83 = F_1 ( & V_3 , & V_4 ) ;
if ( V_83 -> V_119 & V_120 ) {
V_11 -> V_121 = V_83 ;
V_11 -> V_20 &= ~ V_99 ;
break;
}
}
return;
}
static struct V_1 * F_57 ( struct V_10 * V_11 )
{
if ( ! V_11 || V_11 -> V_20 & V_99 || V_11 -> V_85 == 0 )
return NULL ;
return V_11 -> V_121 ;
}
static struct V_110 * T_3 F_58 ( struct V_10 * V_11 )
{
struct V_1 * V_83 ;
struct V_110 * V_111 ;
int V_115 = 0 , V_4 = 0 ;
V_83 = F_57 ( V_11 ) ;
if ( ! V_83 || ! V_83 -> V_112 )
return NULL ;
do {
V_111 = & V_83 -> V_112 [ V_4 ++ ] ;
if ( V_111 -> V_73 & V_122 )
V_115 = 1 ;
} while ( ! V_115 && V_111 -> V_113 != V_111 -> V_114 );
return ( V_115 ) ? V_111 : NULL ;
}
static void F_59 ( struct V_10 * V_11 )
{
T_2 V_31 , V_123 ;
T_1 V_22 ;
bool V_124 ;
struct V_65 * V_68 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
if ( V_11 -> V_73 & V_125 )
F_39 ( V_11 ) ;
F_14 ( V_11 ) ;
if ( V_11 -> V_73 & V_125 )
F_42 ( V_11 ) ;
V_22 = V_11 -> V_16 ;
V_123 = V_11 -> V_12 -> V_13 -> V_18 ;
V_68 = F_22 ( V_11 ) ;
if ( V_123 & V_34 ) {
if ( V_11 -> V_73 & V_126 ||
V_11 -> V_73 & V_127 ) {
V_31 = V_128 ;
} else {
if ( V_123 & V_58 )
F_20 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_59 & V_60 )
V_31 = V_63 ;
else
V_31 = V_64 ;
}
V_124 = ( V_68 && V_68 -> V_73 & V_129 ) ;
if ( V_124 && ! ( V_11 -> V_12 -> V_13 -> V_59 &
( V_130 | V_60 ) ) )
V_31 = V_131 ;
F_10 ( V_11 , V_31 , & V_22 ) ;
}
if ( V_123 & V_28 ) {
if ( V_11 -> V_73 & V_132 ) {
V_31 = V_131 ;
} else if ( V_11 -> V_73 & V_133 ) {
V_31 = V_128 ;
} else {
if ( V_123 & V_58 )
F_20 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_59 & V_61 )
V_31 = V_63 ;
else
V_31 = V_64 ;
}
F_8 ( V_11 , V_31 , & V_22 ) ;
}
if ( ( V_11 -> V_73 & V_134 ) &&
( V_123 & V_38 ) )
F_11 ( V_11 , V_11 -> V_12 -> V_13 -> V_35 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
if ( V_123 & V_57 ) {
V_31 = ( V_11 -> V_73 & V_135 ) ?
0 : 1 ;
F_19 ( V_11 , V_31 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
}
static void F_60 ( struct V_10 * V_11 )
{
T_2 V_31 , V_123 ;
T_1 V_22 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_123 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_123 & V_34 ) {
if ( V_11 -> V_73 & V_126 ) {
V_31 = V_131 ;
} else {
if ( V_123 & V_58 )
F_20 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_59 & V_60 )
V_31 = V_63 ;
else
V_31 = V_64 ;
}
F_10 ( V_11 , V_31 , & V_22 ) ;
}
if ( V_123 & V_28 ) {
if ( ( V_11 -> V_73 & V_133 ) ||
( V_11 -> V_73 & V_132 ) ) {
V_31 = V_131 ;
} else {
if ( V_123 & V_58 )
F_20 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_59 & V_61 )
V_31 = V_63 ;
else
V_31 = V_64 ;
}
F_8 ( V_11 , V_31 , & V_22 ) ;
}
if ( V_11 -> V_16 != V_22 )
F_6 ( V_22 , V_11 ) ;
}
static void F_61 ( struct V_10 * V_11 )
{
T_1 V_22 ;
T_2 V_123 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_123 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_123 & V_34 )
F_10 ( V_11 , V_131 , & V_22 ) ;
if ( V_123 & V_28 )
F_8 ( V_11 , V_131 , & V_22 ) ;
if ( V_123 & V_57 )
F_19 ( V_11 , 1 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
static struct V_10 * F_62 ( const char * V_14 )
{
struct V_10 * V_11 , * V_136 ;
V_11 = NULL ;
F_63 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_14 , V_136 -> V_14 ) ) {
V_11 = V_136 ;
break;
}
}
return V_11 ;
}
static int F_64 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_137 ) {
F_18 ( L_20 , V_11 -> V_14 ) ;
return 0 ;
}
V_11 -> V_68 = F_65 ( V_11 -> V_137 ) ;
if ( ! V_11 -> V_68 ) {
F_17 ( L_21 ,
V_11 -> V_14 , V_11 -> V_137 ) ;
return 0 ;
}
F_18 ( L_22 ,
V_11 -> V_14 , V_11 -> V_137 ) ;
return 0 ;
}
static int F_66 ( struct V_10 * V_11 , void * V_138 )
{
int V_75 = 0 ;
if ( V_11 -> V_51 != V_139 )
return 0 ;
F_18 ( L_23 , V_11 -> V_14 ) ;
if ( V_79 . V_72 )
V_75 |= V_79 . V_72 ( V_11 ) ;
V_75 |= F_30 ( V_11 ) ;
V_75 |= F_37 ( V_11 ) ;
V_75 |= F_38 ( V_11 ) ;
if ( ! V_75 )
V_11 -> V_51 = V_140 ;
else
F_17 ( L_24 , V_11 -> V_14 ) ;
return V_75 ;
}
static int F_67 ( struct V_10 * V_11 , const char * V_14 ,
struct V_141 * V_142 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_143 ; V_4 ++ ) {
const char * V_144 = V_11 -> V_145 [ V_4 ] . V_14 ;
if ( ! strcmp ( V_144 , V_14 ) ) {
V_142 -> V_146 = V_11 -> V_145 [ V_4 ] . V_146 ;
V_142 -> V_147 = V_11 -> V_145 [ V_4 ] . V_147 ;
F_18 ( L_25 ,
V_11 -> V_14 , V_78 , V_144 , V_142 -> V_146 ,
V_142 -> V_147 ) ;
return 0 ;
}
}
return - V_116 ;
}
static int F_68 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_141 V_142 ;
int V_75 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_79 . V_148 )
return - V_149 ;
V_75 = F_67 ( V_11 , V_14 , & V_142 ) ;
if ( V_75 < 0 )
return V_75 ;
V_75 = V_79 . V_148 ( V_11 , & V_142 ) ;
return V_75 ;
}
static int F_69 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_141 V_142 ;
int V_75 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_79 . V_150 )
return - V_149 ;
V_75 = F_67 ( V_11 , V_14 , & V_142 ) ;
if ( V_75 < 0 )
return V_75 ;
if ( V_11 -> V_68 ) {
F_70 ( V_11 -> V_68 ) ;
V_75 = F_71 ( V_11 -> V_68 , V_11 ) ;
if ( V_75 ) {
F_4 ( 1 , L_26 ,
V_11 -> V_14 , V_11 -> V_68 -> V_14 , V_75 ) ;
return V_75 ;
}
}
F_44 ( V_11 ) ;
if ( V_79 . V_151 )
V_79 . V_151 ( V_11 ) ;
V_75 = V_79 . V_150 ( V_11 , & V_142 ) ;
if ( V_79 . V_152 )
V_79 . V_152 ( V_11 ) ;
F_45 ( V_11 ) ;
if ( V_75 == - V_153 )
F_17 ( L_27 , V_11 -> V_14 ) ;
if ( V_11 -> V_68 ) {
F_72 ( V_11 -> V_68 ) ;
F_73 ( V_11 -> V_68 , V_11 ) ;
}
return V_75 ;
}
static int F_74 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_141 V_142 ;
int V_75 = - V_15 ;
if ( ! V_11 )
return - V_15 ;
if ( ! V_79 . V_154 )
return - V_149 ;
V_75 = F_67 ( V_11 , V_14 , & V_142 ) ;
if ( V_75 < 0 )
return V_75 ;
return V_79 . V_154 ( V_11 , & V_142 ) ;
}
static bool F_75 ( struct V_10 * V_11 )
{
int V_4 , V_155 = 0 ;
if ( V_11 -> V_143 == 0 )
return false ;
for ( V_4 = 0 ; V_4 < V_11 -> V_143 ; V_4 ++ )
if ( F_74 ( V_11 , V_11 -> V_145 [ V_4 ] . V_14 ) > 0 )
V_155 ++ ;
if ( V_11 -> V_143 == V_155 )
return true ;
return false ;
}
static bool F_76 ( struct V_10 * V_11 )
{
int V_155 = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_143 && V_155 == 0 ; V_4 ++ )
if ( F_74 ( V_11 , V_11 -> V_145 [ V_4 ] . V_14 ) > 0 )
V_155 ++ ;
return ( V_155 ) ? true : false ;
}
static int F_77 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! V_11 -> V_68 || ! V_11 -> V_93 . V_94 . V_95 )
return - V_15 ;
if ( F_76 ( V_11 ) )
return 0 ;
F_18 ( L_28 , V_11 -> V_14 , V_78 ) ;
F_78 ( V_11 -> V_68 -> V_96 , V_11 -> V_68 -> V_97 ,
V_11 -> V_93 . V_94 . V_98 ) ;
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
int V_75 = 0 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_40 ) )
return - V_116 ;
if ( V_11 -> V_51 != V_52 ) {
F_17 ( L_30 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_73 & V_125 )
F_39 ( V_11 ) ;
F_18 ( L_31 , V_11 -> V_14 ) ;
V_22 = V_11 -> V_16 ;
V_75 = F_12 ( V_11 , & V_22 ) ;
if ( V_75 )
goto V_156;
F_6 ( V_22 , V_11 ) ;
if ( V_11 -> V_12 -> V_13 -> V_157 )
F_80 ( V_11 -> V_12 -> V_13 -> V_157 ) ;
V_43 = F_14 ( V_11 ) ;
if ( V_43 == V_47 ) {
F_17 ( L_32 ,
V_11 -> V_14 , V_47 ) ;
V_75 = - V_158 ;
goto V_156;
} else {
F_18 ( L_33 , V_11 -> V_14 , V_43 ) ;
}
V_75 = F_13 ( V_11 , & V_22 ) ;
if ( V_75 )
goto V_156;
F_6 ( V_22 , V_11 ) ;
V_156:
if ( V_11 -> V_73 & V_125 )
F_42 ( V_11 ) ;
return V_75 ;
}
static int F_81 ( struct V_10 * V_11 )
{
int V_4 , V_159 ;
F_18 ( L_34 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_160 ) {
V_159 = V_11 -> V_12 -> V_160 ( V_11 ) ;
} else {
if ( V_11 -> V_143 > 0 ) {
for ( V_4 = 0 ; V_4 < V_11 -> V_143 ; V_4 ++ )
F_68 ( V_11 , V_11 -> V_145 [ V_4 ] . V_14 ) ;
return 0 ;
} else {
V_159 = F_79 ( V_11 ) ;
if ( V_159 == - V_116 )
V_159 = 0 ;
}
}
F_16 ( V_11 ) ;
if ( V_11 -> V_12 -> V_13 ) {
F_3 ( V_11 ) ;
F_59 ( V_11 ) ;
}
return V_159 ;
}
static void F_82 ( struct V_10 * V_11 )
{
if ( V_11 -> V_93 . V_94 . V_73 & V_161 )
return;
if ( ! F_83 ( V_11 -> V_68 -> V_162 . V_163 -> V_96 ,
V_11 -> V_68 -> V_162 . V_163 -> V_164 ,
V_11 -> V_93 . V_94 . V_165 ) )
return;
V_11 -> V_93 . V_94 . V_166 ++ ;
F_84 ( V_11 -> V_68 -> V_162 . V_163 -> V_96 ,
V_11 -> V_68 -> V_162 . V_163 -> V_164 ,
V_11 -> V_93 . V_94 . V_165 ) ;
}
static int F_85 ( struct V_10 * V_11 )
{
return V_11 -> V_93 . V_94 . V_166 ;
}
static int F_86 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_12 -> V_167 )
return 0 ;
return V_11 -> V_12 -> V_167 ( V_11 ) ;
}
static int F_87 ( struct V_10 * V_11 )
{
int V_159 ;
F_18 ( L_35 , V_11 -> V_14 ) ;
if ( V_11 -> V_20 & V_168 ) {
V_11 -> V_20 &= ~ V_168 ;
return 0 ;
}
if ( V_11 -> V_51 != V_169 &&
V_11 -> V_51 != V_170 &&
V_11 -> V_51 != V_171 ) {
F_4 ( 1 , L_36 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_75 ( V_11 ) )
return 0 ;
F_26 ( V_11 , V_172 ) ;
if ( V_11 -> V_68 ) {
F_70 ( V_11 -> V_68 ) ;
V_159 = F_71 ( V_11 -> V_68 , V_11 ) ;
if ( V_159 ) {
F_4 ( 1 , L_26 ,
V_11 -> V_14 , V_11 -> V_68 -> V_14 , V_159 ) ;
return V_159 ;
}
}
F_44 ( V_11 ) ;
if ( V_79 . V_151 )
V_79 . V_151 ( V_11 ) ;
if ( V_11 -> V_73 & V_173 )
F_88 ( true ) ;
if ( V_79 . V_174 )
V_79 . V_174 ( V_11 ) ;
V_159 = ( V_79 . V_175 ) ? V_79 . V_175 ( V_11 ) :
- V_15 ;
if ( V_11 -> V_68 )
F_72 ( V_11 -> V_68 ) ;
if ( ! V_159 ) {
V_11 -> V_51 = V_52 ;
if ( V_11 -> V_12 -> V_13 ) {
if ( ! ( V_11 -> V_20 & V_21 ) )
F_3 ( V_11 ) ;
F_59 ( V_11 ) ;
}
V_159 = F_86 ( V_11 ) ;
} else {
if ( V_79 . V_152 )
V_79 . V_152 ( V_11 ) ;
F_45 ( V_11 ) ;
F_89 ( L_37 ,
V_11 -> V_14 , V_159 ) ;
if ( V_11 -> V_68 )
F_73 ( V_11 -> V_68 , V_11 ) ;
}
return V_159 ;
}
static int F_90 ( struct V_10 * V_11 )
{
if ( V_11 -> V_73 & V_176 ) {
V_11 -> V_20 |= V_168 ;
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
F_28 ( V_11 , V_172 ) ;
if ( V_11 -> V_68 )
F_70 ( V_11 -> V_68 ) ;
if ( V_11 -> V_73 & V_173 )
F_88 ( false ) ;
if ( V_79 . V_152 )
V_79 . V_152 ( V_11 ) ;
F_45 ( V_11 ) ;
if ( V_11 -> V_68 ) {
F_72 ( V_11 -> V_68 ) ;
F_73 ( V_11 -> V_68 , V_11 ) ;
}
V_11 -> V_51 = V_170 ;
return 0 ;
}
static int F_91 ( struct V_10 * V_11 )
{
int V_75 , V_4 ;
T_2 V_177 ;
if ( F_75 ( V_11 ) )
return 0 ;
if ( V_11 -> V_51 != V_170 &&
V_11 -> V_51 != V_52 ) {
F_4 ( 1 , L_40 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
F_18 ( L_41 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_178 ) {
V_177 = V_11 -> V_51 ;
if ( V_11 -> V_51 == V_170 )
F_87 ( V_11 ) ;
V_75 = V_11 -> V_12 -> V_178 ( V_11 ) ;
if ( V_75 ) {
if ( V_177 == V_170 )
F_90 ( V_11 ) ;
return V_75 ;
}
}
if ( V_11 -> V_12 -> V_13 ) {
if ( V_11 -> V_51 == V_170 )
F_87 ( V_11 ) ;
F_61 ( V_11 ) ;
}
if ( V_11 -> V_51 == V_52 ) {
F_28 ( V_11 , V_172 ) ;
if ( V_11 -> V_73 & V_173 )
F_88 ( false ) ;
if ( V_79 . V_152 )
V_79 . V_152 ( V_11 ) ;
F_45 ( V_11 ) ;
if ( V_11 -> V_68 )
F_73 ( V_11 -> V_68 , V_11 ) ;
}
for ( V_4 = 0 ; V_4 < V_11 -> V_143 ; V_4 ++ )
F_68 ( V_11 , V_11 -> V_145 [ V_4 ] . V_14 ) ;
V_11 -> V_51 = V_171 ;
return 0 ;
}
static int F_92 ( struct V_179 * V_180 ,
struct V_10 * V_11 )
{
int V_181 , V_4 , V_182 ;
const char * V_3 ;
V_181 = F_93 ( V_180 , L_42 ) ;
if ( V_181 < 1 )
return - V_183 ;
for ( V_4 = 0 ; V_4 < V_181 ; V_4 ++ ) {
V_182 = F_94 ( V_180 , L_42 ,
V_4 , & V_3 ) ;
if ( V_182 )
continue;
if ( ! strcmp ( V_3 , V_11 -> V_14 ) ) {
F_18 ( L_43 ,
V_180 -> V_14 , V_4 , V_11 -> V_14 ) ;
return V_4 ;
}
}
return - V_183 ;
}
static int F_95 ( struct V_179 * V_180 ,
struct V_10 * V_11 ,
int * V_184 ,
struct V_179 * * V_115 )
{
struct V_179 * V_185 = NULL ;
int V_182 ;
V_182 = F_92 ( V_180 , V_11 ) ;
if ( V_182 >= 0 ) {
* V_115 = V_180 ;
* V_184 = V_182 ;
return 0 ;
}
F_96 (np, np0) {
struct V_179 * V_186 ;
int V_4 ;
V_182 = F_95 ( V_185 , V_11 , & V_4 , & V_186 ) ;
if ( V_182 == 0 ) {
* V_115 = V_186 ;
* V_184 = V_4 ;
return 0 ;
}
}
* V_115 = NULL ;
* V_184 = 0 ;
return - V_183 ;
}
static int T_3 F_97 ( struct V_10 * V_11 , void * V_138 ,
int V_184 , struct V_179 * V_180 )
{
struct V_110 * V_111 ;
void T_4 * va_start = NULL ;
if ( ! V_11 )
return - V_15 ;
F_56 ( V_11 ) ;
if ( ! V_11 -> V_12 -> V_13 )
return 0 ;
if ( V_11 -> V_20 & V_99 )
return - V_187 ;
V_111 = F_58 ( V_11 ) ;
if ( ! V_111 ) {
F_18 ( L_44 ,
V_11 -> V_14 ) ;
if ( ! V_180 ) {
F_89 ( L_45 , V_11 -> V_14 ) ;
return - V_187 ;
}
va_start = F_98 ( V_180 , V_184 + V_11 -> V_188 ) ;
} else {
va_start = F_99 ( V_111 -> V_113 , V_111 -> V_114 - V_111 -> V_113 ) ;
}
if ( ! va_start ) {
if ( V_111 )
F_89 ( L_46 , V_11 -> V_14 ) ;
else
F_89 ( L_47 ,
V_11 -> V_14 , V_184 , V_180 -> V_189 ) ;
return - V_187 ;
}
F_18 ( L_48 ,
V_11 -> V_14 , va_start ) ;
V_11 -> V_190 = va_start ;
return 0 ;
}
static int T_3 F_100 ( struct V_10 * V_11 , void * V_138 )
{
int V_159 , V_184 ;
struct V_179 * V_180 = NULL ;
if ( V_11 -> V_51 != V_139 )
return 0 ;
if ( F_101 () ) {
struct V_179 * V_191 ;
V_191 = F_102 ( NULL , L_49 ) ;
if ( ! V_191 )
return - V_183 ;
V_159 = F_95 ( V_191 , V_11 , & V_184 , & V_180 ) ;
if ( V_159 )
F_18 ( L_50 , V_11 -> V_14 ) ;
else if ( V_180 && V_184 )
F_17 ( L_51 ,
V_11 -> V_14 , V_180 -> V_14 ) ;
}
V_159 = F_97 ( V_11 , NULL , V_184 , V_180 ) ;
if ( V_159 < 0 ) {
F_4 ( 1 , L_52 ,
V_11 -> V_14 ) ;
return 0 ;
}
V_159 = F_66 ( V_11 , NULL ) ;
if ( V_159 < 0 ) {
F_4 ( 1 , L_53 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_180 ) {
if ( F_103 ( V_180 , L_54 , NULL ) )
V_11 -> V_73 |= V_192 ;
if ( F_103 ( V_180 , L_55 , NULL ) )
V_11 -> V_73 |= V_193 ;
if ( F_103 ( V_180 , L_56 , NULL ) )
V_11 -> V_73 |= V_176 ;
}
V_11 -> V_51 = V_169 ;
return 0 ;
}
static void T_3 F_104 ( struct V_10 * V_11 )
{
struct V_1 * V_83 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( V_11 -> V_51 != V_169 )
return;
V_3 = V_11 -> V_84 . V_9 ;
while ( V_4 < V_11 -> V_85 ) {
V_83 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_83 -> V_69 )
continue;
if ( V_83 -> V_73 & V_91 ) {
} else {
F_41 ( V_83 -> V_69 ) ;
}
}
return;
}
static int T_3 F_105 ( struct V_10 * V_11 )
{
int V_159 ;
if ( V_11 -> V_51 != V_169 )
return - V_15 ;
if ( V_11 -> V_73 & V_194 )
return - V_195 ;
if ( V_11 -> V_143 == 0 ) {
V_159 = F_87 ( V_11 ) ;
if ( V_159 ) {
F_17 ( L_57 ,
V_11 -> V_14 , V_11 -> V_51 ) ;
return - V_15 ;
}
}
if ( ! ( V_11 -> V_73 & V_192 ) )
V_159 = F_81 ( V_11 ) ;
return V_159 ;
}
static void T_3 F_106 ( struct V_10 * V_11 )
{
T_2 V_196 ;
if ( V_11 -> V_143 > 0 )
return;
V_196 = V_11 -> V_197 ;
if ( V_196 == V_198 )
V_196 = V_52 ;
if ( ( V_11 -> V_73 & ( V_193 | V_176 ) ) &&
( V_196 == V_170 ) ) {
V_11 -> V_20 |= V_168 ;
V_196 = V_52 ;
}
if ( V_196 == V_170 )
F_90 ( V_11 ) ;
else if ( V_196 == V_171 )
F_91 ( V_11 ) ;
else if ( V_196 != V_52 )
F_4 ( 1 , L_58 ,
V_11 -> V_14 , V_196 ) ;
return;
}
static int T_3 F_107 ( struct V_10 * V_11 , void * V_138 )
{
if ( V_11 -> V_51 != V_169 )
return 0 ;
if ( V_11 -> V_199 ) {
int V_159 ;
V_159 = F_87 ( V_11 -> V_199 ) ;
F_4 ( V_159 , L_59 ,
V_11 -> V_14 , V_11 -> V_199 -> V_14 ) ;
}
F_104 ( V_11 ) ;
if ( ! F_105 ( V_11 ) )
F_106 ( V_11 ) ;
if ( V_11 -> V_199 ) {
T_2 V_196 ;
V_196 = V_11 -> V_199 -> V_197 ;
if ( V_196 == V_170 )
F_90 ( V_11 -> V_199 ) ;
else if ( V_196 == V_171 )
F_91 ( V_11 -> V_199 ) ;
else if ( V_196 != V_52 )
F_4 ( 1 , L_58 ,
V_11 -> V_199 -> V_14 , V_196 ) ;
}
return 0 ;
}
static int T_3 F_108 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_14 || ! V_11 -> V_12 || ! V_11 -> V_12 -> V_14 ||
( V_11 -> V_51 != V_198 ) )
return - V_15 ;
F_18 ( L_60 , V_11 -> V_14 ) ;
if ( F_62 ( V_11 -> V_14 ) )
return - V_200 ;
F_109 ( & V_11 -> V_7 , & V_201 ) ;
F_110 ( & V_11 -> V_202 ) ;
F_110 ( & V_11 -> V_84 ) ;
F_111 ( & V_11 -> V_203 ) ;
F_112 ( & V_11 -> V_203 , & V_11 -> V_204 ) ;
V_11 -> V_51 = V_139 ;
if ( ! strcmp ( V_11 -> V_14 , V_205 ) )
V_172 = V_11 ;
return 0 ;
}
static int T_3 F_113 ( struct V_6 * * V_206 ,
struct V_6 * * V_207 )
{
unsigned int V_208 ;
if ( ( V_209 + V_210 ) <= V_211 ) {
* V_206 = & V_212 [ V_209 ++ ] ;
* V_207 = & V_212 [ V_209 ++ ] ;
return 0 ;
}
V_208 = sizeof( struct V_6 ) * V_210 ;
* V_207 = NULL ;
* V_206 = F_114 ( V_208 , 0 ) ;
* V_207 = ( void * ) ( * V_206 ) + sizeof( struct V_6 ) ;
V_213 ++ ;
F_18 ( L_61 ,
V_213 * V_210 ) ;
return 0 ;
}
static int T_3 F_115 ( struct V_1 * V_5 )
{
struct V_6 * V_206 , * V_207 ;
F_18 ( L_62 , V_5 -> V_214 -> V_14 ,
V_5 -> V_215 -> V_14 ) ;
F_113 ( & V_206 , & V_207 ) ;
V_206 -> V_8 = V_5 ;
F_116 ( & V_206 -> V_7 , & V_5 -> V_214 -> V_202 ) ;
V_5 -> V_214 -> V_216 ++ ;
V_207 -> V_8 = V_5 ;
F_116 ( & V_207 -> V_7 , & V_5 -> V_215 -> V_84 ) ;
V_5 -> V_215 -> V_85 ++ ;
return 0 ;
}
static int T_3 F_117 ( struct V_1 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_214 || ! V_5 -> V_215 || ! V_5 -> V_119 )
return - V_15 ;
if ( V_5 -> V_20 & V_217 )
return - V_200 ;
F_18 ( L_63 ,
V_5 -> V_214 -> V_14 , V_5 -> V_215 -> V_14 ) ;
if ( V_5 -> V_214 -> V_51 != V_139 )
F_108 ( V_5 -> V_214 ) ;
if ( V_5 -> V_215 -> V_51 != V_139 )
F_108 ( V_5 -> V_215 ) ;
F_115 ( V_5 ) ;
V_5 -> V_20 |= V_217 ;
return 0 ;
}
static int T_3 F_118 ( struct V_1 * * V_218 )
{
unsigned int V_4 = 0 ;
unsigned int V_208 ;
if ( V_212 ) {
F_4 ( 1 , L_64 ) ;
return - V_200 ;
}
if ( V_211 == 0 )
while ( V_218 [ V_4 ++ ] )
V_211 += V_210 ;
V_208 = sizeof( struct V_6 ) * V_211 ;
F_18 ( L_65 ,
V_78 , V_208 , V_211 ) ;
V_212 = F_114 ( V_208 , 0 ) ;
return 0 ;
}
static int F_119 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_73 & V_100 )
return 0 ;
if ( ! F_57 ( V_11 ) )
return 0 ;
return F_120 ( 0 , V_11 -> V_93 . V_219 . V_220 ,
V_11 -> V_93 . V_219 . V_221 ,
V_11 -> V_93 . V_219 . V_222 ) ;
}
static int F_121 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_73 & V_100 || ! V_11 -> V_68 )
return 0 ;
if ( ! F_57 ( V_11 ) )
return 0 ;
if ( ! V_11 -> V_93 . V_94 . V_98 &&
! ( V_11 -> V_93 . V_94 . V_73 & V_101 ) )
return 0 ;
return F_120 ( V_11 -> V_68 -> V_96 ,
V_11 -> V_68 -> V_97 ,
V_11 -> V_93 . V_94 . V_98 , 0 ) ;
}
static int F_122 ( struct V_10 * V_11 ,
struct V_141 * V_142 )
{
return F_123 ( V_142 -> V_146 , 0 ,
V_11 -> V_93 . V_219 . V_220 , 0 ) ;
}
static int F_124 ( struct V_10 * V_11 ,
struct V_141 * V_142 )
{
return F_125 ( V_142 -> V_146 , V_142 -> V_147 , 0 ,
V_11 -> V_93 . V_219 . V_220 , 0 , 0 ) ;
}
static int F_126 ( struct V_10 * V_11 ,
struct V_141 * V_142 )
{
return F_127 ( V_142 -> V_147 , 0 ,
V_11 -> V_93 . V_219 . V_220 , 0 ) ;
}
static int F_128 ( struct V_10 * V_11 ,
struct V_141 * V_142 )
{
if ( ! V_11 -> V_68 )
return - V_15 ;
return F_123 ( V_142 -> V_146 ,
V_11 -> V_68 -> V_162 . V_163 -> V_96 ,
V_11 -> V_68 -> V_162 . V_163 -> V_164 ,
V_11 -> V_93 . V_94 . V_223 ) ;
}
static int F_129 ( struct V_10 * V_11 ,
struct V_141 * V_142 )
{
if ( ! V_11 -> V_68 )
return - V_15 ;
if ( V_142 -> V_147 )
F_89 ( L_66 ,
V_11 -> V_14 , V_142 -> V_14 ) ;
return F_125 ( V_142 -> V_146 , V_142 -> V_146 ,
V_11 -> V_68 -> V_162 . V_163 -> V_96 ,
V_11 -> V_68 -> V_162 . V_163 -> V_164 ,
V_11 -> V_93 . V_94 . V_223 ,
V_11 -> V_93 . V_94 . V_223 +
V_224 ) ;
}
static int F_130 ( struct V_10 * V_11 ,
struct V_141 * V_142 )
{
if ( ! V_11 -> V_68 )
return - V_15 ;
return F_127 ( V_142 -> V_146 ,
V_11 -> V_68 -> V_162 . V_163 ->
V_96 ,
V_11 -> V_68 -> V_162 . V_163 -> V_164 ,
V_11 -> V_93 . V_94 . V_223 ) ;
}
static int F_131 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
V_11 -> V_93 . V_94 . V_98 = 0 ;
V_11 -> V_93 . V_94 . V_95 = 0 ;
return 0 ;
}
static int F_132 ( struct V_10 * V_11 ,
struct V_141 * V_142 )
{
return F_125 ( V_142 -> V_146 , V_142 -> V_147 ,
V_11 -> V_68 -> V_162 . V_163 -> V_96 ,
V_11 -> V_68 -> V_162 . V_163 -> V_164 ,
V_11 -> V_93 . V_94 . V_223 ,
V_11 -> V_93 . V_94 . V_225 ) ;
}
T_1 F_5 ( struct V_10 * V_11 , T_5 V_226 )
{
if ( V_11 -> V_73 & V_227 )
return F_133 ( V_11 -> V_190 + V_226 ) ;
else
return F_134 ( V_11 -> V_190 + V_226 ) ;
}
void F_7 ( T_1 V_22 , struct V_10 * V_11 , T_5 V_226 )
{
if ( V_11 -> V_73 & V_227 )
F_135 ( V_22 , V_11 -> V_190 + V_226 ) ;
else
F_136 ( V_22 , V_11 -> V_190 + V_226 ) ;
}
int F_137 ( struct V_10 * V_11 )
{
T_1 V_22 ;
int V_75 ;
if ( ! V_11 || ! ( V_11 -> V_16 ) )
return - V_15 ;
V_22 = V_11 -> V_16 ;
V_75 = F_12 ( V_11 , & V_22 ) ;
if ( V_75 )
goto error;
F_6 ( V_22 , V_11 ) ;
V_75 = F_13 ( V_11 , & V_22 ) ;
if ( V_75 )
goto error;
F_6 ( V_22 , V_11 ) ;
error:
return V_75 ;
}
struct V_10 * F_138 ( const char * V_14 )
{
struct V_10 * V_11 ;
if ( ! V_14 )
return NULL ;
V_11 = F_62 ( V_14 ) ;
return V_11 ;
}
int F_139 ( int (* F_140)( struct V_10 * V_11 , void * V_138 ) ,
void * V_138 )
{
struct V_10 * V_136 ;
int V_75 = 0 ;
if ( ! F_140 )
return - V_15 ;
F_63 (temp_oh, &omap_hwmod_list, node) {
V_75 = (* F_140)( V_136 , V_138 ) ;
if ( V_75 )
break;
}
return V_75 ;
}
int T_3 F_141 ( struct V_1 * * V_218 )
{
int V_159 , V_4 ;
if ( ! V_228 )
return - V_15 ;
if ( ! V_218 )
return 0 ;
if ( V_218 [ 0 ] == NULL )
return 0 ;
if ( ! V_212 ) {
if ( F_118 ( V_218 ) ) {
F_89 ( L_67 ) ;
return - V_229 ;
}
}
V_4 = 0 ;
do {
V_159 = F_117 ( V_218 [ V_4 ] ) ;
F_4 ( V_159 && V_159 != - V_200 ,
L_68 ,
V_218 [ V_4 ] -> V_214 -> V_14 , V_218 [ V_4 ] -> V_215 -> V_14 , V_159 ) ;
} while ( V_218 [ ++ V_4 ] );
return 0 ;
}
static void T_3 F_142 ( struct V_10 * V_11 )
{
if ( ! V_172 || V_172 -> V_51 == V_198 )
F_89 ( L_69 ,
V_78 , V_205 ) ;
else if ( V_172 -> V_51 == V_139 && V_11 != V_172 )
F_143 ( V_205 ) ;
}
int T_3 F_143 ( const char * V_230 )
{
struct V_10 * V_11 ;
F_18 ( L_28 , V_230 , V_78 ) ;
V_11 = F_62 ( V_230 ) ;
if ( ! V_11 ) {
F_4 ( 1 , L_70 , V_230 ) ;
return - V_15 ;
}
F_142 ( V_11 ) ;
F_100 ( V_11 , NULL ) ;
F_107 ( V_11 , NULL ) ;
return 0 ;
}
static int T_3 F_144 ( void )
{
F_142 ( NULL ) ;
F_139 ( F_100 , NULL ) ;
F_139 ( F_107 , NULL ) ;
return 0 ;
}
int F_145 ( struct V_10 * V_11 )
{
int V_159 ;
unsigned long V_73 ;
if ( ! V_11 )
return - V_15 ;
F_146 ( & V_11 -> V_203 , V_73 ) ;
V_159 = F_87 ( V_11 ) ;
F_147 ( & V_11 -> V_203 , V_73 ) ;
return V_159 ;
}
int F_148 ( struct V_10 * V_11 )
{
int V_159 ;
unsigned long V_73 ;
if ( ! V_11 )
return - V_15 ;
F_146 ( & V_11 -> V_203 , V_73 ) ;
V_159 = F_90 ( V_11 ) ;
F_147 ( & V_11 -> V_203 , V_73 ) ;
return V_159 ;
}
int F_149 ( struct V_10 * V_11 )
{
int V_159 ;
unsigned long V_73 ;
if ( ! V_11 )
return - V_15 ;
F_146 ( & V_11 -> V_203 , V_73 ) ;
V_159 = F_91 ( V_11 ) ;
F_147 ( & V_11 -> V_203 , V_73 ) ;
return V_159 ;
}
int F_150 ( struct V_10 * V_11 , unsigned long V_73 )
{
int V_75 = 0 ;
if ( V_73 & V_231 )
V_75 += F_50 ( V_11 ) ;
if ( V_73 & V_232 )
V_75 += F_51 ( V_11 ) ;
if ( V_73 & V_233 ) {
int V_4 = 0 ;
struct V_1 * V_83 ;
struct V_2 * V_3 = V_11 -> V_84 . V_9 ;
while ( V_4 < V_11 -> V_85 ) {
V_83 = F_1 ( & V_3 , & V_4 ) ;
V_75 += F_52 ( V_83 ) ;
}
}
return V_75 ;
}
int F_151 ( struct V_10 * V_11 , struct V_234 * V_182 )
{
struct V_1 * V_83 ;
struct V_2 * V_3 ;
int V_4 , V_118 , V_235 , V_236 , V_237 ;
int V_159 = 0 ;
V_235 = F_50 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_235 ; V_4 ++ ) {
unsigned int V_105 ;
if ( V_11 -> V_238 )
V_105 = V_11 -> V_238 ( ( V_11 -> V_104 + V_4 ) -> V_105 ) ;
else
V_105 = ( V_11 -> V_104 + V_4 ) -> V_105 ;
( V_182 + V_159 ) -> V_14 = ( V_11 -> V_104 + V_4 ) -> V_14 ;
( V_182 + V_159 ) -> V_239 = V_105 ;
( V_182 + V_159 ) -> V_240 = V_105 ;
( V_182 + V_159 ) -> V_73 = V_231 ;
V_159 ++ ;
}
V_236 = F_51 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_236 ; V_4 ++ ) {
( V_182 + V_159 ) -> V_14 = ( V_11 -> V_108 + V_4 ) -> V_14 ;
( V_182 + V_159 ) -> V_239 = ( V_11 -> V_108 + V_4 ) -> V_109 ;
( V_182 + V_159 ) -> V_240 = ( V_11 -> V_108 + V_4 ) -> V_109 ;
( V_182 + V_159 ) -> V_73 = V_232 ;
V_159 ++ ;
}
V_3 = V_11 -> V_84 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_85 ) {
V_83 = F_1 ( & V_3 , & V_4 ) ;
V_237 = F_52 ( V_83 ) ;
for ( V_118 = 0 ; V_118 < V_237 ; V_118 ++ ) {
( V_182 + V_159 ) -> V_14 = ( V_83 -> V_112 + V_118 ) -> V_14 ;
( V_182 + V_159 ) -> V_239 = ( V_83 -> V_112 + V_118 ) -> V_113 ;
( V_182 + V_159 ) -> V_240 = ( V_83 -> V_112 + V_118 ) -> V_114 ;
( V_182 + V_159 ) -> V_73 = V_233 ;
V_159 ++ ;
}
}
return V_159 ;
}
int F_152 ( struct V_10 * V_11 , struct V_234 * V_182 )
{
int V_4 , V_236 ;
int V_159 = 0 ;
V_236 = F_51 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_236 ; V_4 ++ ) {
( V_182 + V_159 ) -> V_14 = ( V_11 -> V_108 + V_4 ) -> V_14 ;
( V_182 + V_159 ) -> V_239 = ( V_11 -> V_108 + V_4 ) -> V_109 ;
( V_182 + V_159 ) -> V_240 = ( V_11 -> V_108 + V_4 ) -> V_109 ;
( V_182 + V_159 ) -> V_73 = V_232 ;
V_159 ++ ;
}
return V_159 ;
}
int F_153 ( struct V_10 * V_11 , unsigned int type ,
const char * V_14 , struct V_234 * V_241 )
{
int V_159 ;
unsigned int V_105 , V_117 ;
T_1 V_113 , V_114 ;
if ( ! V_11 || ! V_241 )
return - V_15 ;
if ( type == V_231 ) {
V_159 = F_53 ( V_11 , V_14 , & V_105 ) ;
if ( V_159 )
return V_159 ;
V_241 -> V_239 = V_105 ;
V_241 -> V_240 = V_105 ;
} else if ( type == V_232 ) {
V_159 = F_54 ( V_11 , V_14 , & V_117 ) ;
if ( V_159 )
return V_159 ;
V_241 -> V_239 = V_117 ;
V_241 -> V_240 = V_117 ;
} else if ( type == V_233 ) {
V_159 = F_55 ( V_11 , V_14 , & V_113 , & V_114 ) ;
if ( V_159 )
return V_159 ;
V_241 -> V_239 = V_113 ;
V_241 -> V_240 = V_114 ;
} else {
return - V_15 ;
}
V_241 -> V_73 = type ;
V_241 -> V_14 = V_14 ;
return 0 ;
}
struct V_242 * F_154 ( struct V_10 * V_11 )
{
struct V_67 * V_43 ;
struct V_1 * V_5 ;
struct V_65 * V_68 ;
struct V_66 * V_67 ;
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_68 )
return V_11 -> V_68 -> V_162 . V_163 ;
if ( V_11 -> V_69 ) {
V_43 = V_11 -> V_69 ;
} else {
V_5 = F_57 ( V_11 ) ;
if ( ! V_5 )
return NULL ;
V_43 = V_5 -> V_69 ;
}
V_67 = F_24 ( F_25 ( V_43 ) ) ;
V_68 = V_67 -> V_68 ;
if ( ! V_68 )
return NULL ;
return V_68 -> V_162 . V_163 ;
}
void T_4 * F_155 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_20 & V_99 )
return NULL ;
if ( V_11 -> V_51 == V_198 )
return NULL ;
return V_11 -> V_190 ;
}
int F_156 ( struct V_10 * V_11 )
{
unsigned long V_73 ;
T_1 V_22 ;
F_146 ( & V_11 -> V_203 , V_73 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_58 ) ) {
V_22 = V_11 -> V_16 ;
F_20 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_147 ( & V_11 -> V_203 , V_73 ) ;
return 0 ;
}
int F_157 ( struct V_10 * V_11 )
{
unsigned long V_73 ;
T_1 V_22 ;
F_146 ( & V_11 -> V_203 , V_73 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_58 ) ) {
V_22 = V_11 -> V_16 ;
F_21 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_147 ( & V_11 -> V_203 , V_73 ) ;
return 0 ;
}
int F_158 ( struct V_10 * V_11 , const char * V_14 )
{
int V_75 ;
unsigned long V_73 ;
if ( ! V_11 )
return - V_15 ;
F_146 ( & V_11 -> V_203 , V_73 ) ;
V_75 = F_68 ( V_11 , V_14 ) ;
F_147 ( & V_11 -> V_203 , V_73 ) ;
return V_75 ;
}
int F_159 ( struct V_10 * V_11 , const char * V_14 )
{
int V_75 ;
unsigned long V_73 ;
if ( ! V_11 )
return - V_15 ;
F_146 ( & V_11 -> V_203 , V_73 ) ;
V_75 = F_69 ( V_11 , V_14 ) ;
F_147 ( & V_11 -> V_203 , V_73 ) ;
return V_75 ;
}
int F_160 ( const char * V_243 ,
int (* F_140)( struct V_10 * V_11 ,
void * V_119 ) ,
void * V_119 )
{
struct V_10 * V_136 ;
int V_75 = 0 ;
if ( ! V_243 || ! F_140 )
return - V_15 ;
F_18 ( L_71 ,
V_78 , V_243 ) ;
F_63 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_136 -> V_12 -> V_14 , V_243 ) ) {
F_18 ( L_72 ,
V_78 , V_136 -> V_14 ) ;
V_75 = (* F_140)( V_136 , V_119 ) ;
if ( V_75 )
break;
}
}
if ( V_75 )
F_18 ( L_73 ,
V_78 , V_75 ) ;
return V_75 ;
}
int F_161 ( struct V_10 * V_11 , T_2 V_244 )
{
int V_75 ;
unsigned long V_73 ;
if ( ! V_11 )
return - V_15 ;
if ( V_244 != V_171 &&
V_244 != V_52 &&
V_244 != V_170 )
return - V_15 ;
F_146 ( & V_11 -> V_203 , V_73 ) ;
if ( V_11 -> V_51 != V_139 ) {
V_75 = - V_15 ;
goto V_245;
}
V_11 -> V_197 = V_244 ;
V_75 = 0 ;
V_245:
F_147 ( & V_11 -> V_203 , V_73 ) ;
return V_75 ;
}
int F_162 ( struct V_10 * V_11 )
{
struct V_242 * V_162 ;
int V_75 = 0 ;
if ( V_79 . V_246 )
return V_79 . V_246 ( V_11 ) ;
V_162 = F_154 ( V_11 ) ;
if ( V_162 )
V_75 = F_163 ( V_162 ) ;
return V_75 ;
}
void T_3 F_164 ( void )
{
if ( F_165 () ) {
V_79 . V_175 = F_119 ;
V_79 . V_148 = F_122 ;
V_79 . V_150 = F_124 ;
V_79 . V_154 = F_126 ;
} else if ( F_166 () ) {
V_79 . V_175 = F_119 ;
V_79 . V_148 = F_122 ;
V_79 . V_150 = F_124 ;
V_79 . V_154 = F_126 ;
V_79 . V_72 = F_64 ;
} else if ( F_167 () || F_168 () || F_169 () ) {
V_79 . V_151 = F_46 ;
V_79 . V_152 = F_77 ;
V_79 . V_175 = F_121 ;
V_79 . V_148 = F_128 ;
V_79 . V_150 = F_129 ;
V_79 . V_154 = F_130 ;
V_79 . V_72 = F_64 ;
V_79 . V_174 = F_82 ;
V_79 . V_246 = F_85 ;
V_79 . V_80 = F_131 ;
} else if ( F_170 () || F_171 () || F_172 () ||
F_173 () ) {
V_79 . V_151 = F_46 ;
V_79 . V_152 = F_77 ;
V_79 . V_175 = F_121 ;
V_79 . V_148 = F_128 ;
V_79 . V_150 = F_132 ;
V_79 . V_154 = F_130 ;
V_79 . V_72 = F_64 ;
V_79 . V_80 = F_131 ;
} else {
F_4 ( 1 , L_74 ) ;
}
V_228 = true ;
}
const char * F_174 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
return V_11 -> V_81 ;
}
