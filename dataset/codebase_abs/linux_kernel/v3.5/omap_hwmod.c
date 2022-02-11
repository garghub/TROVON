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
static int F_13 ( struct V_10 * V_11 , T_2 V_40 ,
T_1 * V_22 )
{
T_1 V_41 ;
T_2 V_42 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_43 ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_27 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_42 = V_11 -> V_12 -> V_13 -> V_27 -> V_42 ;
V_41 = ( 0x1 << V_42 ) ;
* V_22 &= ~ V_41 ;
* V_22 |= V_40 << V_42 ;
return 0 ;
}
static void F_14 ( struct V_10 * V_11 , bool V_44 )
{
struct V_45 * V_46 ;
bool V_47 = false ;
T_3 V_48 ;
int V_49 ;
if ( ! V_11 -> V_50 || ! V_11 -> V_50 -> V_51 )
return;
for ( V_49 = 0 ; V_49 < V_11 -> V_50 -> V_52 ; V_49 ++ ) {
V_46 = V_11 -> V_50 -> V_53 [ V_49 ] ;
if ( ! ( V_46 -> V_54 & V_55 ) )
continue;
V_48 = V_46 -> V_56 ;
if ( V_44 )
V_46 -> V_56 |= V_57 ;
else
V_46 -> V_56 &= ~ V_57 ;
if ( V_48 != V_46 -> V_56 )
V_47 = true ;
}
if ( V_47 && V_11 -> V_58 == V_59 )
F_15 ( V_11 -> V_50 , V_59 ) ;
}
static int F_16 ( struct V_10 * V_11 , T_1 * V_22 )
{
if ( ! V_11 -> V_12 -> V_13 ||
! ( ( V_11 -> V_12 -> V_13 -> V_18 & V_60 ) ||
( V_11 -> V_12 -> V_13 -> V_61 & V_62 ) ||
( V_11 -> V_12 -> V_13 -> V_61 & V_63 ) ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_27 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_12 -> V_13 -> V_18 & V_60 )
* V_22 |= 0x1 << V_11 -> V_12 -> V_13 -> V_27 -> V_64 ;
if ( V_11 -> V_12 -> V_13 -> V_61 & V_62 )
F_10 ( V_11 , V_65 , V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_61 & V_63 )
F_8 ( V_11 , V_65 , V_22 ) ;
V_11 -> V_20 |= V_66 ;
return 0 ;
}
static int F_17 ( struct V_10 * V_11 , T_1 * V_22 )
{
if ( ! V_11 -> V_12 -> V_13 ||
! ( ( V_11 -> V_12 -> V_13 -> V_18 & V_60 ) ||
( V_11 -> V_12 -> V_13 -> V_61 & V_62 ) ||
( V_11 -> V_12 -> V_13 -> V_61 & V_63 ) ) )
return - V_15 ;
if ( ! V_11 -> V_12 -> V_13 -> V_27 ) {
F_4 ( 1 , L_3 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_12 -> V_13 -> V_18 & V_60 )
* V_22 &= ~ ( 0x1 << V_11 -> V_12 -> V_13 -> V_27 -> V_64 ) ;
if ( V_11 -> V_12 -> V_13 -> V_61 & V_62 )
F_10 ( V_11 , V_67 , V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_61 & V_63 )
F_8 ( V_11 , V_67 , V_22 ) ;
V_11 -> V_20 &= ~ V_66 ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 , struct V_10 * V_68 )
{
if ( ! V_11 -> V_69 )
return - V_15 ;
if ( V_11 -> V_69 -> V_70 && V_11 -> V_69 -> V_70 -> V_54 & V_71 )
return 0 ;
return F_19 ( V_11 -> V_69 -> V_70 , V_68 -> V_69 -> V_70 ) ;
}
static int F_20 ( struct V_10 * V_11 , struct V_10 * V_68 )
{
if ( ! V_11 -> V_69 )
return - V_15 ;
if ( V_11 -> V_69 -> V_70 && V_11 -> V_69 -> V_70 -> V_54 & V_71 )
return 0 ;
return F_21 ( V_11 -> V_69 -> V_70 , V_68 -> V_69 -> V_70 ) ;
}
static int F_22 ( struct V_10 * V_11 )
{
int V_72 = 0 ;
if ( ! V_11 -> V_73 )
return 0 ;
V_11 -> V_69 = F_23 ( V_11 -> V_73 ) ;
if ( ! V_11 -> V_69 ) {
F_24 ( L_4 ,
V_11 -> V_14 , V_11 -> V_73 ) ;
return - V_15 ;
}
if ( ! V_11 -> V_69 -> V_70 )
F_24 ( L_5 ,
V_11 -> V_73 , V_11 -> V_69 -> V_14 ) ;
return V_72 ;
}
static int F_25 ( struct V_10 * V_11 )
{
struct V_1 * V_74 ;
struct V_2 * V_3 ;
struct V_75 * V_76 ;
int V_4 = 0 ;
int V_72 = 0 ;
V_3 = V_11 -> V_77 . V_9 ;
while ( V_4 < V_11 -> V_78 ) {
V_74 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_74 -> V_75 )
continue;
V_76 = F_23 ( V_74 -> V_75 ) ;
if ( ! V_76 ) {
F_24 ( L_6 ,
V_11 -> V_14 , V_74 -> V_75 ) ;
V_72 = - V_15 ;
}
V_74 -> V_69 = V_76 ;
}
return V_72 ;
}
static int F_26 ( struct V_10 * V_11 )
{
struct V_79 * V_80 ;
struct V_75 * V_76 ;
int V_4 ;
int V_72 = 0 ;
for ( V_4 = V_11 -> V_81 , V_80 = V_11 -> V_82 ; V_4 > 0 ; V_4 -- , V_80 ++ ) {
V_76 = F_23 ( V_80 -> V_75 ) ;
if ( ! V_76 ) {
F_24 ( L_7 ,
V_11 -> V_14 , V_80 -> V_75 ) ;
V_72 = - V_15 ;
}
V_80 -> V_69 = V_76 ;
}
return V_72 ;
}
static int F_27 ( struct V_10 * V_11 )
{
struct V_1 * V_74 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_28 ( L_8 , V_11 -> V_14 ) ;
if ( V_11 -> V_69 )
F_29 ( V_11 -> V_69 ) ;
V_3 = V_11 -> V_77 . V_9 ;
while ( V_4 < V_11 -> V_78 ) {
V_74 = F_1 ( & V_3 , & V_4 ) ;
if ( V_74 -> V_69 && ( V_74 -> V_54 & V_83 ) )
F_29 ( V_74 -> V_69 ) ;
}
return 0 ;
}
static int F_30 ( struct V_10 * V_11 )
{
struct V_1 * V_74 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
F_28 ( L_9 , V_11 -> V_14 ) ;
if ( V_11 -> V_69 )
F_31 ( V_11 -> V_69 ) ;
V_3 = V_11 -> V_77 . V_9 ;
while ( V_4 < V_11 -> V_78 ) {
V_74 = F_1 ( & V_3 , & V_4 ) ;
if ( V_74 -> V_69 && ( V_74 -> V_54 & V_83 ) )
F_31 ( V_74 -> V_69 ) ;
}
return 0 ;
}
static void F_32 ( struct V_10 * V_11 )
{
struct V_79 * V_80 ;
int V_4 ;
F_28 ( L_10 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_81 , V_80 = V_11 -> V_82 ; V_4 > 0 ; V_4 -- , V_80 ++ )
if ( V_80 -> V_69 ) {
F_28 ( L_11 , V_80 -> V_84 ,
V_80 -> V_69 -> V_14 ) ;
F_29 ( V_80 -> V_69 ) ;
}
}
static void F_33 ( struct V_10 * V_11 )
{
struct V_79 * V_80 ;
int V_4 ;
F_28 ( L_12 , V_11 -> V_14 ) ;
for ( V_4 = V_11 -> V_81 , V_80 = V_11 -> V_82 ; V_4 > 0 ; V_4 -- , V_80 ++ )
if ( V_80 -> V_69 ) {
F_28 ( L_13 , V_80 -> V_84 ,
V_80 -> V_69 -> V_14 ) ;
F_31 ( V_80 -> V_69 ) ;
}
}
static void F_34 ( struct V_10 * V_11 )
{
if ( F_35 () || F_36 () )
return;
if ( ! V_11 -> V_70 || ! V_11 -> V_85 . V_86 . V_87 )
return;
F_28 ( L_14 ,
V_11 -> V_14 , V_11 -> V_85 . V_86 . V_87 ) ;
F_37 ( V_11 -> V_85 . V_86 . V_87 ,
V_11 -> V_70 -> V_88 ,
V_11 -> V_70 -> V_89 ,
V_11 -> V_70 -> V_90 ,
V_11 -> V_85 . V_86 . V_91 ) ;
}
static int F_38 ( struct V_10 * V_11 )
{
if ( ! F_39 () )
return 0 ;
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_20 & V_92 )
return 0 ;
if ( V_11 -> V_54 & V_93 )
return 0 ;
return F_40 ( V_11 -> V_70 -> V_88 ,
V_11 -> V_70 -> V_89 ,
V_11 -> V_70 -> V_90 ,
V_11 -> V_85 . V_86 . V_91 ) ;
}
static int F_41 ( struct V_10 * V_11 )
{
struct V_94 * V_95 ;
int V_4 = 0 ;
if ( ! V_11 || ! V_11 -> V_96 )
return 0 ;
do {
V_95 = & V_11 -> V_96 [ V_4 ++ ] ;
} while ( V_95 -> V_97 != - 1 );
return V_4 - 1 ;
}
static int F_42 ( struct V_10 * V_11 )
{
struct V_98 * V_99 ;
int V_4 = 0 ;
if ( ! V_11 || ! V_11 -> V_100 )
return 0 ;
do {
V_99 = & V_11 -> V_100 [ V_4 ++ ] ;
} while ( V_99 -> V_101 != - 1 );
return V_4 - 1 ;
}
static int F_43 ( struct V_1 * V_74 )
{
struct V_102 * V_103 ;
int V_4 = 0 ;
if ( ! V_74 || ! V_74 -> V_104 )
return 0 ;
do {
V_103 = & V_74 -> V_104 [ V_4 ++ ] ;
} while ( V_103 -> V_105 != V_103 -> V_106 );
return V_4 - 1 ;
}
static int F_44 ( struct V_10 * V_11 , const char * V_14 ,
unsigned int * V_97 )
{
int V_4 ;
bool V_107 = false ;
if ( ! V_11 -> V_96 )
return - V_108 ;
V_4 = 0 ;
while ( V_11 -> V_96 [ V_4 ] . V_97 != - 1 ) {
if ( V_14 == V_11 -> V_96 [ V_4 ] . V_14 ||
! strcmp ( V_14 , V_11 -> V_96 [ V_4 ] . V_14 ) ) {
V_107 = true ;
break;
}
V_4 ++ ;
}
if ( ! V_107 )
return - V_108 ;
* V_97 = V_11 -> V_96 [ V_4 ] . V_97 ;
return 0 ;
}
static int F_45 ( struct V_10 * V_11 , const char * V_14 ,
unsigned int * V_109 )
{
int V_4 ;
bool V_107 = false ;
if ( ! V_11 -> V_100 )
return - V_108 ;
V_4 = 0 ;
while ( V_11 -> V_100 [ V_4 ] . V_101 != - 1 ) {
if ( V_14 == V_11 -> V_100 [ V_4 ] . V_14 ||
! strcmp ( V_14 , V_11 -> V_100 [ V_4 ] . V_14 ) ) {
V_107 = true ;
break;
}
V_4 ++ ;
}
if ( ! V_107 )
return - V_108 ;
* V_109 = V_11 -> V_100 [ V_4 ] . V_101 ;
return 0 ;
}
static int F_46 ( struct V_10 * V_11 , const char * V_14 ,
T_1 * V_105 , T_1 * V_106 )
{
int V_4 , V_49 ;
struct V_1 * V_74 ;
struct V_2 * V_3 = NULL ;
bool V_107 = false ;
V_3 = V_11 -> V_77 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_78 ) {
V_74 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_74 -> V_104 )
return - V_108 ;
V_49 = 0 ;
while ( V_74 -> V_104 [ V_49 ] . V_105 != V_74 -> V_104 [ V_49 ] . V_106 ) {
if ( V_14 == V_74 -> V_104 [ V_49 ] . V_14 ||
! strcmp ( V_14 , V_74 -> V_104 [ V_49 ] . V_14 ) ) {
V_107 = true ;
break;
}
V_49 ++ ;
}
if ( V_107 )
break;
}
if ( ! V_107 )
return - V_108 ;
* V_105 = V_74 -> V_104 [ V_49 ] . V_105 ;
* V_106 = V_74 -> V_104 [ V_49 ] . V_106 ;
return 0 ;
}
static void T_4 F_47 ( struct V_10 * V_11 )
{
struct V_1 * V_74 = NULL ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( ! V_11 )
return;
V_11 -> V_20 |= V_92 ;
V_3 = V_11 -> V_77 . V_9 ;
while ( V_4 < V_11 -> V_78 ) {
V_74 = F_1 ( & V_3 , & V_4 ) ;
if ( V_74 -> V_110 & V_111 ) {
V_11 -> V_112 = V_74 ;
V_11 -> V_20 &= ~ V_92 ;
break;
}
}
return;
}
static struct V_1 * F_48 ( struct V_10 * V_11 )
{
if ( ! V_11 || V_11 -> V_20 & V_92 || V_11 -> V_78 == 0 )
return NULL ;
return V_11 -> V_112 ;
}
static struct V_102 * T_4 F_49 ( struct V_10 * V_11 )
{
struct V_1 * V_74 ;
struct V_102 * V_103 ;
int V_107 = 0 , V_4 = 0 ;
V_74 = F_48 ( V_11 ) ;
if ( ! V_74 || ! V_74 -> V_104 )
return NULL ;
do {
V_103 = & V_74 -> V_104 [ V_4 ++ ] ;
if ( V_103 -> V_54 & V_113 )
V_107 = 1 ;
} while ( ! V_107 && V_103 -> V_105 != V_103 -> V_106 );
return ( V_107 ) ? V_103 : NULL ;
}
static void F_50 ( struct V_10 * V_11 )
{
T_2 V_29 , V_114 ;
T_1 V_22 ;
bool V_115 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_114 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_114 & V_32 ) {
V_115 = ( ( V_11 -> V_70 &&
V_11 -> V_70 -> V_54 & V_116 ) ||
( V_11 -> V_69 && V_11 -> V_69 -> V_70 &&
V_11 -> V_69 -> V_70 -> V_54 & V_116 ) ) ;
if ( V_115 && ! ( V_11 -> V_12 -> V_13 -> V_61 &
( V_117 | V_62 ) ) )
V_29 = V_118 ;
else
V_29 = ( V_11 -> V_54 & V_119 ) ?
V_120 : V_67 ;
F_10 ( V_11 , V_29 , & V_22 ) ;
}
if ( V_114 & V_26 ) {
if ( V_11 -> V_54 & V_121 ) {
V_29 = V_120 ;
} else {
if ( V_114 & V_60 )
F_16 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_61 & V_63 )
V_29 = V_65 ;
else
V_29 = V_67 ;
}
F_8 ( V_11 , V_29 , & V_22 ) ;
}
if ( ( V_11 -> V_54 & V_122 ) &&
( V_114 & V_36 ) )
F_11 ( V_11 , V_11 -> V_12 -> V_13 -> V_33 , & V_22 ) ;
if ( ( V_114 & V_32 ) && ! ( V_11 -> V_54 & V_119 ) )
F_16 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
if ( V_114 & V_43 ) {
V_29 = ( V_11 -> V_54 & V_123 ) ?
0 : 1 ;
F_13 ( V_11 , V_29 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
}
static void F_51 ( struct V_10 * V_11 )
{
T_2 V_29 , V_114 ;
T_1 V_22 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_114 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_114 & V_32 ) {
if ( V_11 -> V_54 & V_119 ||
! ( V_11 -> V_12 -> V_13 -> V_61 &
( V_117 | V_62 ) ) )
V_29 = V_118 ;
else
V_29 = V_67 ;
F_10 ( V_11 , V_29 , & V_22 ) ;
}
if ( V_114 & V_26 ) {
if ( V_11 -> V_54 & V_121 ) {
V_29 = V_118 ;
} else {
if ( V_114 & V_60 )
F_16 ( V_11 , & V_22 ) ;
if ( V_11 -> V_12 -> V_13 -> V_61 & V_63 )
V_29 = V_65 ;
else
V_29 = V_67 ;
}
F_8 ( V_11 , V_29 , & V_22 ) ;
}
if ( ( V_114 & V_32 ) && ! ( V_11 -> V_54 & V_119 ) )
F_16 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
static void F_52 ( struct V_10 * V_11 )
{
T_1 V_22 ;
T_2 V_114 ;
if ( ! V_11 -> V_12 -> V_13 )
return;
V_22 = V_11 -> V_16 ;
V_114 = V_11 -> V_12 -> V_13 -> V_18 ;
if ( V_114 & V_32 )
F_10 ( V_11 , V_118 , & V_22 ) ;
if ( V_114 & V_26 )
F_8 ( V_11 , V_118 , & V_22 ) ;
if ( V_114 & V_43 )
F_13 ( V_11 , 1 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
static struct V_10 * F_53 ( const char * V_14 )
{
struct V_10 * V_11 , * V_124 ;
V_11 = NULL ;
F_54 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_14 , V_124 -> V_14 ) ) {
V_11 = V_124 ;
break;
}
}
return V_11 ;
}
static int F_55 ( struct V_10 * V_11 )
{
if ( F_35 () || F_36 () )
return 0 ;
if ( ! V_11 -> V_125 ) {
F_24 ( L_15 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_70 = F_56 ( V_11 -> V_125 ) ;
if ( ! V_11 -> V_70 ) {
F_24 ( L_16 ,
V_11 -> V_14 , V_11 -> V_125 ) ;
return - V_15 ;
}
F_28 ( L_17 ,
V_11 -> V_14 , V_11 -> V_125 ) ;
return 0 ;
}
static int F_57 ( struct V_10 * V_11 , void * V_126 )
{
int V_72 = 0 ;
if ( V_11 -> V_58 != V_127 )
return 0 ;
F_28 ( L_18 , V_11 -> V_14 ) ;
V_72 |= F_22 ( V_11 ) ;
V_72 |= F_25 ( V_11 ) ;
V_72 |= F_26 ( V_11 ) ;
V_72 |= F_55 ( V_11 ) ;
if ( ! V_72 )
V_11 -> V_58 = V_128 ;
else
F_24 ( L_19 , V_11 -> V_14 ) ;
return V_72 ;
}
static int F_58 ( struct V_10 * V_11 )
{
struct V_1 * V_74 ;
int V_72 ;
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_54 & V_93 )
return 0 ;
V_74 = F_48 ( V_11 ) ;
if ( ! V_74 )
return 0 ;
if ( F_35 () || F_36 () ) {
V_72 = F_59 ( V_11 -> V_85 . V_129 . V_130 ,
V_11 -> V_85 . V_129 . V_131 ,
V_11 -> V_85 . V_129 . V_132 ) ;
} else if ( F_39 () ) {
if ( ! V_11 -> V_70 )
return - V_15 ;
V_72 = F_60 ( V_11 -> V_70 -> V_88 ,
V_11 -> V_70 -> V_89 ,
V_11 -> V_70 -> V_90 ,
V_11 -> V_85 . V_86 . V_91 ) ;
} else {
F_61 () ;
} ;
return V_72 ;
}
static T_2 F_62 ( struct V_10 * V_11 , const char * V_14 ,
struct V_133 * V_134 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_135 ; V_4 ++ ) {
const char * V_136 = V_11 -> V_137 [ V_4 ] . V_14 ;
if ( ! strcmp ( V_136 , V_14 ) ) {
V_134 -> V_138 = V_11 -> V_137 [ V_4 ] . V_138 ;
V_134 -> V_139 = V_11 -> V_137 [ V_4 ] . V_139 ;
F_28 ( L_20 ,
V_11 -> V_14 , V_140 , V_136 , V_134 -> V_138 ,
V_134 -> V_139 ) ;
return 0 ;
}
}
return - V_108 ;
}
static int F_63 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_133 V_134 ;
T_2 V_72 ;
if ( ! V_11 )
return - V_15 ;
V_72 = F_62 ( V_11 , V_14 , & V_134 ) ;
if ( F_64 ( V_72 ) )
return V_72 ;
if ( F_35 () || F_36 () )
return F_65 ( V_11 -> V_85 . V_129 . V_130 ,
V_134 . V_138 ) ;
else if ( F_39 () )
return F_66 ( V_134 . V_138 ,
V_11 -> V_70 -> V_141 . V_142 -> V_88 ,
V_11 -> V_70 -> V_141 . V_142 -> V_143 ,
V_11 -> V_85 . V_86 . V_144 ) ;
else
return - V_15 ;
}
static int F_67 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_133 V_134 ;
int V_72 ;
if ( ! V_11 )
return - V_15 ;
V_72 = F_62 ( V_11 , V_14 , & V_134 ) ;
if ( F_64 ( V_72 ) )
return V_72 ;
if ( F_35 () || F_36 () ) {
V_72 = F_68 ( V_11 -> V_85 . V_129 . V_130 ,
V_134 . V_138 ,
V_134 . V_139 ) ;
} else if ( F_39 () ) {
if ( V_134 . V_139 )
F_69 ( L_21 ,
V_11 -> V_14 , V_14 ) ;
V_72 = F_70 ( V_134 . V_138 ,
V_11 -> V_70 -> V_141 . V_142 -> V_88 ,
V_11 -> V_70 -> V_141 . V_142 -> V_143 ,
V_11 -> V_85 . V_86 . V_144 ) ;
} else {
return - V_15 ;
}
if ( V_72 == - V_145 )
F_24 ( L_22 , V_11 -> V_14 ) ;
return V_72 ;
}
static int F_71 ( struct V_10 * V_11 , const char * V_14 )
{
struct V_133 V_134 ;
T_2 V_72 ;
if ( ! V_11 )
return - V_15 ;
V_72 = F_62 ( V_11 , V_14 , & V_134 ) ;
if ( F_64 ( V_72 ) )
return V_72 ;
if ( F_35 () || F_36 () ) {
return F_72 ( V_11 -> V_85 . V_129 . V_130 ,
V_134 . V_139 ) ;
} else if ( F_39 () ) {
return F_73 ( V_134 . V_138 ,
V_11 -> V_70 -> V_141 . V_142 -> V_88 ,
V_11 -> V_70 -> V_141 . V_142 -> V_143 ,
V_11 -> V_85 . V_86 . V_144 ) ;
} else {
return - V_15 ;
}
}
static bool F_74 ( struct V_10 * V_11 )
{
int V_4 ;
if ( V_11 -> V_135 == 0 )
return false ;
for ( V_4 = 0 ; V_4 < V_11 -> V_135 ; V_4 ++ )
if ( F_71 ( V_11 , V_11 -> V_137 [ V_4 ] . V_14 ) > 0 )
return true ;
return false ;
}
static int F_75 ( struct V_10 * V_11 )
{
int V_22 ;
if ( ! F_39 () )
return - V_15 ;
if ( ! V_11 -> V_70 || ! V_11 -> V_85 . V_86 . V_87 )
return - V_15 ;
F_28 ( L_23 , V_11 -> V_14 , V_140 ) ;
F_76 ( V_11 -> V_70 -> V_88 ,
V_11 -> V_70 -> V_89 ,
V_11 -> V_70 -> V_90 ,
V_11 -> V_85 . V_86 . V_91 ) ;
if ( F_74 ( V_11 ) )
return 0 ;
V_22 = F_38 ( V_11 ) ;
if ( V_22 )
F_77 ( L_24 ,
V_11 -> V_14 ) ;
return 0 ;
}
static int F_78 ( struct V_10 * V_11 )
{
T_1 V_22 , V_37 ;
int V_76 = 0 ;
int V_72 = 0 ;
if ( ! V_11 -> V_12 -> V_13 ||
! ( V_11 -> V_12 -> V_13 -> V_18 & V_38 ) )
return - V_108 ;
if ( V_11 -> V_58 != V_146 ) {
F_24 ( L_25
L_26 , V_11 -> V_14 ) ;
return - V_15 ;
}
if ( V_11 -> V_54 & V_147 )
F_32 ( V_11 ) ;
F_28 ( L_27 , V_11 -> V_14 ) ;
V_22 = V_11 -> V_16 ;
V_72 = F_12 ( V_11 , & V_22 ) ;
if ( V_72 )
goto V_148;
F_6 ( V_22 , V_11 ) ;
if ( V_11 -> V_12 -> V_13 -> V_149 )
F_79 ( V_11 -> V_12 -> V_13 -> V_149 ) ;
if ( V_11 -> V_12 -> V_13 -> V_18 & V_150 )
F_80 ( ( F_5 ( V_11 ,
V_11 -> V_12 -> V_13 -> V_151 )
& V_152 ) ,
V_153 , V_76 ) ;
else if ( V_11 -> V_12 -> V_13 -> V_18 & V_154 ) {
V_37 = ( 0x1 << V_11 -> V_12 -> V_13 -> V_27 -> V_39 ) ;
F_80 ( ! ( F_5 ( V_11 ,
V_11 -> V_12 -> V_13 -> V_17 )
& V_37 ) ,
V_153 , V_76 ) ;
}
if ( V_76 == V_153 )
F_24 ( L_28 ,
V_11 -> V_14 , V_153 ) ;
else
F_28 ( L_29 , V_11 -> V_14 , V_76 ) ;
V_72 = ( V_76 == V_153 ) ? - V_155 : 0 ;
V_148:
if ( V_11 -> V_54 & V_147 )
F_33 ( V_11 ) ;
return V_72 ;
}
static int F_81 ( struct V_10 * V_11 )
{
int V_4 , V_156 ;
F_28 ( L_30 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_157 ) {
V_156 = V_11 -> V_12 -> V_157 ( V_11 ) ;
} else {
if ( V_11 -> V_135 > 0 ) {
for ( V_4 = 0 ; V_4 < V_11 -> V_135 ; V_4 ++ )
F_63 ( V_11 , V_11 -> V_137 [ V_4 ] . V_14 ) ;
return 0 ;
} else {
V_156 = F_78 ( V_11 ) ;
if ( V_156 == - V_108 )
V_156 = 0 ;
}
}
if ( V_11 -> V_12 -> V_13 ) {
F_3 ( V_11 ) ;
F_50 ( V_11 ) ;
}
return V_156 ;
}
static int F_82 ( struct V_10 * V_11 )
{
int V_156 ;
int V_158 = 0 ;
F_28 ( L_31 , V_11 -> V_14 ) ;
if ( V_11 -> V_20 & V_159 ) {
if ( V_11 -> V_50 )
F_15 ( V_11 -> V_50 , V_146 ) ;
V_11 -> V_20 &= ~ V_159 ;
return 0 ;
}
if ( V_11 -> V_58 != V_160 &&
V_11 -> V_58 != V_59 &&
V_11 -> V_58 != V_161 ) {
F_4 ( 1 , L_32 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_74 ( V_11 ) )
return 0 ;
if ( V_11 -> V_50 && ( ! V_11 -> V_50 -> V_51 ||
( ( V_11 -> V_58 == V_59 ) &&
V_11 -> V_50 -> V_53 ) ) )
F_15 ( V_11 -> V_50 , V_146 ) ;
F_18 ( V_11 , V_162 ) ;
if ( V_11 -> V_70 ) {
V_158 = F_83 ( V_11 -> V_70 ) ;
V_156 = F_84 ( V_11 -> V_70 , V_11 ) ;
if ( V_156 ) {
F_4 ( 1 , L_33 ,
V_11 -> V_14 , V_11 -> V_70 -> V_14 , V_156 ) ;
return V_156 ;
}
}
F_27 ( V_11 ) ;
F_34 ( V_11 ) ;
V_156 = F_58 ( V_11 ) ;
if ( ! V_156 ) {
if ( V_11 -> V_70 && V_158 )
F_85 ( V_11 -> V_70 ) ;
V_11 -> V_58 = V_146 ;
if ( V_11 -> V_12 -> V_13 ) {
if ( ! ( V_11 -> V_20 & V_21 ) )
F_3 ( V_11 ) ;
F_50 ( V_11 ) ;
}
} else {
F_30 ( V_11 ) ;
F_28 ( L_34 ,
V_11 -> V_14 , V_156 ) ;
if ( V_11 -> V_70 )
F_86 ( V_11 -> V_70 , V_11 ) ;
}
return V_156 ;
}
static int F_87 ( struct V_10 * V_11 )
{
F_28 ( L_35 , V_11 -> V_14 ) ;
if ( V_11 -> V_58 != V_146 ) {
F_4 ( 1 , L_36 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_74 ( V_11 ) )
return 0 ;
if ( V_11 -> V_12 -> V_13 )
F_51 ( V_11 ) ;
F_20 ( V_11 , V_162 ) ;
F_75 ( V_11 ) ;
F_30 ( V_11 ) ;
if ( V_11 -> V_70 )
F_86 ( V_11 -> V_70 , V_11 ) ;
if ( V_11 -> V_50 && V_11 -> V_50 -> V_53 )
F_15 ( V_11 -> V_50 , V_59 ) ;
V_11 -> V_58 = V_59 ;
return 0 ;
}
int F_88 ( struct V_10 * V_11 , T_2 V_40 )
{
T_1 V_22 ;
int V_163 = 0 ;
unsigned long V_54 ;
if ( ! V_11 || V_11 -> V_58 != V_146 )
return - V_15 ;
F_89 ( & V_11 -> V_164 , V_54 ) ;
V_22 = V_11 -> V_16 ;
V_163 = F_13 ( V_11 , V_40 , & V_22 ) ;
if ( ! V_163 )
F_6 ( V_22 , V_11 ) ;
F_90 ( & V_11 -> V_164 , V_54 ) ;
return V_163 ;
}
static int F_91 ( struct V_10 * V_11 )
{
int V_72 , V_4 ;
T_2 V_165 ;
if ( V_11 -> V_58 != V_59 &&
V_11 -> V_58 != V_146 ) {
F_4 ( 1 , L_37 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
if ( F_74 ( V_11 ) )
return 0 ;
F_28 ( L_38 , V_11 -> V_14 ) ;
if ( V_11 -> V_12 -> V_166 ) {
V_165 = V_11 -> V_58 ;
if ( V_11 -> V_58 == V_59 )
F_82 ( V_11 ) ;
V_72 = V_11 -> V_12 -> V_166 ( V_11 ) ;
if ( V_72 ) {
if ( V_165 == V_59 )
F_87 ( V_11 ) ;
return V_72 ;
}
}
if ( V_11 -> V_12 -> V_13 ) {
if ( V_11 -> V_58 == V_59 )
F_82 ( V_11 ) ;
F_52 ( V_11 ) ;
}
if ( V_11 -> V_58 == V_146 ) {
F_20 ( V_11 , V_162 ) ;
F_75 ( V_11 ) ;
F_30 ( V_11 ) ;
if ( V_11 -> V_70 )
F_86 ( V_11 -> V_70 , V_11 ) ;
}
for ( V_4 = 0 ; V_4 < V_11 -> V_135 ; V_4 ++ )
F_63 ( V_11 , V_11 -> V_137 [ V_4 ] . V_14 ) ;
if ( V_11 -> V_50 )
F_15 ( V_11 -> V_50 , V_161 ) ;
V_11 -> V_58 = V_161 ;
return 0 ;
}
static void T_4 F_92 ( struct V_10 * V_11 , void * V_126 )
{
struct V_102 * V_103 ;
void T_5 * va_start ;
if ( ! V_11 )
return;
F_47 ( V_11 ) ;
if ( V_11 -> V_20 & V_92 )
return;
V_103 = F_49 ( V_11 ) ;
if ( ! V_103 ) {
F_28 ( L_39 ,
V_11 -> V_14 ) ;
return;
}
va_start = F_93 ( V_103 -> V_105 , V_103 -> V_106 - V_103 -> V_105 ) ;
if ( ! va_start ) {
F_69 ( L_40 , V_11 -> V_14 ) ;
return;
}
F_28 ( L_41 ,
V_11 -> V_14 , va_start ) ;
V_11 -> V_167 = va_start ;
}
static int T_4 F_94 ( struct V_10 * V_11 , void * V_126 )
{
int V_156 ;
if ( V_11 -> V_58 != V_127 )
return 0 ;
F_92 ( V_11 , NULL ) ;
V_156 = F_57 ( V_11 , NULL ) ;
if ( F_64 ( V_156 ) ) {
F_4 ( 1 , L_42 , V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_58 = V_160 ;
return 0 ;
}
static void T_4 F_95 ( struct V_10 * V_11 )
{
struct V_1 * V_74 ;
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( V_11 -> V_58 != V_160 )
return;
V_3 = V_11 -> V_77 . V_9 ;
while ( V_4 < V_11 -> V_78 ) {
V_74 = F_1 ( & V_3 , & V_4 ) ;
if ( ! V_74 -> V_69 )
continue;
if ( V_74 -> V_54 & V_83 ) {
} else {
F_29 ( V_74 -> V_69 ) ;
}
}
return;
}
static int T_4 F_96 ( struct V_10 * V_11 )
{
int V_156 ;
if ( V_11 -> V_58 != V_160 )
return - V_15 ;
if ( V_11 -> V_135 == 0 ) {
V_156 = F_82 ( V_11 ) ;
if ( V_156 ) {
F_24 ( L_43 ,
V_11 -> V_14 , V_11 -> V_58 ) ;
return - V_15 ;
}
}
if ( ! ( V_11 -> V_54 & V_168 ) )
V_156 = F_81 ( V_11 ) ;
return V_156 ;
}
static void T_4 F_97 ( struct V_10 * V_11 )
{
T_2 V_169 ;
if ( V_11 -> V_135 > 0 )
return;
V_169 = V_11 -> V_170 ;
if ( V_169 == V_171 )
V_169 = V_146 ;
if ( ( V_11 -> V_54 & V_172 ) &&
( V_169 == V_59 ) ) {
V_11 -> V_20 |= V_159 ;
V_169 = V_146 ;
}
if ( V_169 == V_59 )
F_87 ( V_11 ) ;
else if ( V_169 == V_161 )
F_91 ( V_11 ) ;
else if ( V_169 != V_146 )
F_4 ( 1 , L_44 ,
V_11 -> V_14 , V_169 ) ;
return;
}
static int T_4 F_98 ( struct V_10 * V_11 , void * V_126 )
{
if ( V_11 -> V_58 != V_160 )
return 0 ;
F_95 ( V_11 ) ;
if ( ! F_96 ( V_11 ) )
F_97 ( V_11 ) ;
return 0 ;
}
static int T_4 F_99 ( struct V_10 * V_11 )
{
if ( ! V_11 || ! V_11 -> V_14 || ! V_11 -> V_12 || ! V_11 -> V_12 -> V_14 ||
( V_11 -> V_58 != V_171 ) )
return - V_15 ;
F_28 ( L_45 , V_11 -> V_14 ) ;
if ( F_53 ( V_11 -> V_14 ) )
return - V_173 ;
F_100 ( & V_11 -> V_7 , & V_174 ) ;
F_101 ( & V_11 -> V_175 ) ;
F_101 ( & V_11 -> V_77 ) ;
F_102 ( & V_11 -> V_164 ) ;
V_11 -> V_58 = V_127 ;
if ( ! strcmp ( V_11 -> V_14 , V_176 ) )
V_162 = V_11 ;
return 0 ;
}
static int T_4 F_103 ( struct V_6 * * V_177 ,
struct V_6 * * V_178 )
{
unsigned int V_179 ;
if ( ( V_180 + V_181 ) <= V_182 ) {
* V_177 = & V_183 [ V_180 ++ ] ;
* V_178 = & V_183 [ V_180 ++ ] ;
return 0 ;
}
V_179 = sizeof( struct V_6 ) * V_181 ;
* V_178 = NULL ;
* V_177 = F_104 ( V_179 ) ;
memset ( * V_177 , 0 , V_179 ) ;
* V_178 = ( void * ) ( * V_177 ) + sizeof( struct V_6 ) ;
V_184 ++ ;
F_28 ( L_46 ,
V_184 * V_181 ) ;
return 0 ;
}
static int T_4 F_105 ( struct V_1 * V_5 )
{
struct V_6 * V_177 , * V_178 ;
F_28 ( L_47 , V_5 -> V_185 -> V_14 ,
V_5 -> V_186 -> V_14 ) ;
F_103 ( & V_177 , & V_178 ) ;
V_177 -> V_8 = V_5 ;
F_101 ( & V_177 -> V_7 ) ;
F_106 ( & V_177 -> V_7 , & V_5 -> V_185 -> V_175 ) ;
V_5 -> V_185 -> V_187 ++ ;
V_178 -> V_8 = V_5 ;
F_101 ( & V_178 -> V_7 ) ;
F_106 ( & V_178 -> V_7 , & V_5 -> V_186 -> V_77 ) ;
V_5 -> V_186 -> V_78 ++ ;
return 0 ;
}
static int T_4 F_107 ( struct V_1 * V_5 )
{
if ( ! V_5 || ! V_5 -> V_185 || ! V_5 -> V_186 || ! V_5 -> V_110 )
return - V_15 ;
if ( V_5 -> V_20 & V_188 )
return - V_173 ;
F_28 ( L_48 ,
V_5 -> V_185 -> V_14 , V_5 -> V_186 -> V_14 ) ;
if ( V_5 -> V_185 -> V_58 != V_127 )
F_99 ( V_5 -> V_185 ) ;
if ( V_5 -> V_186 -> V_58 != V_127 )
F_99 ( V_5 -> V_186 ) ;
F_105 ( V_5 ) ;
V_5 -> V_20 |= V_188 ;
return 0 ;
}
static int T_4 F_108 ( struct V_1 * * V_189 )
{
unsigned int V_4 = 0 ;
unsigned int V_179 ;
if ( V_183 ) {
F_4 ( 1 , L_49 ) ;
return - V_173 ;
}
if ( V_182 == 0 )
while ( V_189 [ V_4 ++ ] )
V_182 += V_181 ;
V_179 = sizeof( struct V_6 ) * V_182 ;
F_28 ( L_50 ,
V_140 , V_179 , V_182 ) ;
V_183 = F_104 ( V_179 ) ;
memset ( V_183 , 0 , V_179 ) ;
return 0 ;
}
T_1 F_5 ( struct V_10 * V_11 , T_3 V_190 )
{
if ( V_11 -> V_54 & V_191 )
return F_109 ( V_11 -> V_167 + V_190 ) ;
else
return F_110 ( V_11 -> V_167 + V_190 ) ;
}
void F_7 ( T_1 V_22 , struct V_10 * V_11 , T_3 V_190 )
{
if ( V_11 -> V_54 & V_191 )
F_111 ( V_22 , V_11 -> V_167 + V_190 ) ;
else
F_112 ( V_22 , V_11 -> V_167 + V_190 ) ;
}
int F_113 ( struct V_10 * V_11 )
{
T_1 V_22 ;
int V_72 ;
if ( ! V_11 || ! ( V_11 -> V_16 ) )
return - V_15 ;
V_22 = V_11 -> V_16 ;
V_72 = F_12 ( V_11 , & V_22 ) ;
if ( V_72 )
goto error;
F_6 ( V_22 , V_11 ) ;
error:
return V_72 ;
}
int F_114 ( struct V_10 * V_11 , T_2 V_29 )
{
T_1 V_22 ;
int V_163 = 0 ;
if ( ! V_11 )
return - V_15 ;
V_22 = V_11 -> V_16 ;
V_163 = F_10 ( V_11 , V_29 , & V_22 ) ;
if ( ! V_163 )
F_6 ( V_22 , V_11 ) ;
return V_163 ;
}
struct V_10 * F_115 ( const char * V_14 )
{
struct V_10 * V_11 ;
if ( ! V_14 )
return NULL ;
V_11 = F_53 ( V_14 ) ;
return V_11 ;
}
int F_116 ( int (* F_117)( struct V_10 * V_11 , void * V_126 ) ,
void * V_126 )
{
struct V_10 * V_124 ;
int V_72 = 0 ;
if ( ! F_117 )
return - V_15 ;
F_54 (temp_oh, &omap_hwmod_list, node) {
V_72 = (* F_117)( V_124 , V_126 ) ;
if ( V_72 )
break;
}
return V_72 ;
}
int T_4 F_118 ( struct V_1 * * V_189 )
{
int V_156 , V_4 ;
if ( ! V_189 )
return 0 ;
if ( ! V_183 ) {
if ( F_108 ( V_189 ) ) {
F_69 ( L_51 ) ;
return - V_192 ;
}
}
V_4 = 0 ;
do {
V_156 = F_107 ( V_189 [ V_4 ] ) ;
F_4 ( V_156 && V_156 != - V_173 ,
L_52 ,
V_189 [ V_4 ] -> V_185 -> V_14 , V_189 [ V_4 ] -> V_186 -> V_14 , V_156 ) ;
} while ( V_189 [ ++ V_4 ] );
return 0 ;
}
static void T_4 F_119 ( struct V_10 * V_11 )
{
if ( ! V_162 || V_162 -> V_58 == V_171 )
F_69 ( L_53 ,
V_140 , V_176 ) ;
else if ( V_162 -> V_58 == V_127 && V_11 != V_162 )
F_120 ( V_176 ) ;
}
int T_4 F_120 ( const char * V_193 )
{
struct V_10 * V_11 ;
F_28 ( L_23 , V_193 , V_140 ) ;
V_11 = F_53 ( V_193 ) ;
if ( ! V_11 ) {
F_4 ( 1 , L_54 , V_193 ) ;
return - V_15 ;
}
F_119 ( V_11 ) ;
F_94 ( V_11 , NULL ) ;
F_98 ( V_11 , NULL ) ;
return 0 ;
}
static int T_4 F_121 ( void )
{
F_119 ( NULL ) ;
F_116 ( F_94 , NULL ) ;
F_116 ( F_98 , NULL ) ;
return 0 ;
}
int F_122 ( struct V_10 * V_11 )
{
int V_156 ;
unsigned long V_54 ;
if ( ! V_11 )
return - V_15 ;
F_89 ( & V_11 -> V_164 , V_54 ) ;
V_156 = F_82 ( V_11 ) ;
F_90 ( & V_11 -> V_164 , V_54 ) ;
return V_156 ;
}
int F_123 ( struct V_10 * V_11 )
{
unsigned long V_54 ;
if ( ! V_11 )
return - V_15 ;
F_89 ( & V_11 -> V_164 , V_54 ) ;
F_87 ( V_11 ) ;
F_90 ( & V_11 -> V_164 , V_54 ) ;
return 0 ;
}
int F_124 ( struct V_10 * V_11 )
{
unsigned long V_54 ;
if ( ! V_11 )
return - V_15 ;
F_89 ( & V_11 -> V_164 , V_54 ) ;
F_91 ( V_11 ) ;
F_90 ( & V_11 -> V_164 , V_54 ) ;
return 0 ;
}
int F_125 ( struct V_10 * V_11 )
{
unsigned long V_54 ;
F_89 ( & V_11 -> V_164 , V_54 ) ;
F_27 ( V_11 ) ;
F_90 ( & V_11 -> V_164 , V_54 ) ;
return 0 ;
}
int F_126 ( struct V_10 * V_11 )
{
unsigned long V_54 ;
F_89 ( & V_11 -> V_164 , V_54 ) ;
F_30 ( V_11 ) ;
F_90 ( & V_11 -> V_164 , V_54 ) ;
return 0 ;
}
void F_127 ( struct V_10 * V_11 )
{
F_128 ( ! V_11 ) ;
if ( ! V_11 -> V_12 -> V_13 || ! V_11 -> V_12 -> V_13 -> V_18 ) {
F_4 ( 1 , L_55 ,
V_11 -> V_14 ) ;
return;
}
F_5 ( V_11 , V_11 -> V_12 -> V_13 -> V_17 ) ;
}
int F_129 ( struct V_10 * V_11 )
{
int V_156 ;
unsigned long V_54 ;
if ( ! V_11 )
return - V_15 ;
F_89 ( & V_11 -> V_164 , V_54 ) ;
V_156 = F_81 ( V_11 ) ;
F_90 ( & V_11 -> V_164 , V_54 ) ;
return V_156 ;
}
int F_130 ( struct V_10 * V_11 )
{
struct V_1 * V_74 ;
struct V_2 * V_3 ;
int V_72 ;
int V_4 = 0 ;
V_72 = F_41 ( V_11 ) + F_42 ( V_11 ) ;
V_3 = V_11 -> V_77 . V_9 ;
while ( V_4 < V_11 -> V_78 ) {
V_74 = F_1 ( & V_3 , & V_4 ) ;
V_72 += F_43 ( V_74 ) ;
}
return V_72 ;
}
int F_131 ( struct V_10 * V_11 , struct V_194 * V_195 )
{
struct V_1 * V_74 ;
struct V_2 * V_3 ;
int V_4 , V_49 , V_196 , V_197 , V_198 ;
int V_156 = 0 ;
V_196 = F_41 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_196 ; V_4 ++ ) {
( V_195 + V_156 ) -> V_14 = ( V_11 -> V_96 + V_4 ) -> V_14 ;
( V_195 + V_156 ) -> V_199 = ( V_11 -> V_96 + V_4 ) -> V_97 ;
( V_195 + V_156 ) -> V_200 = ( V_11 -> V_96 + V_4 ) -> V_97 ;
( V_195 + V_156 ) -> V_54 = V_201 ;
V_156 ++ ;
}
V_197 = F_42 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_197 ; V_4 ++ ) {
( V_195 + V_156 ) -> V_14 = ( V_11 -> V_100 + V_4 ) -> V_14 ;
( V_195 + V_156 ) -> V_199 = ( V_11 -> V_100 + V_4 ) -> V_101 ;
( V_195 + V_156 ) -> V_200 = ( V_11 -> V_100 + V_4 ) -> V_101 ;
( V_195 + V_156 ) -> V_54 = V_202 ;
V_156 ++ ;
}
V_3 = V_11 -> V_77 . V_9 ;
V_4 = 0 ;
while ( V_4 < V_11 -> V_78 ) {
V_74 = F_1 ( & V_3 , & V_4 ) ;
V_198 = F_43 ( V_74 ) ;
for ( V_49 = 0 ; V_49 < V_198 ; V_49 ++ ) {
( V_195 + V_156 ) -> V_14 = ( V_74 -> V_104 + V_49 ) -> V_14 ;
( V_195 + V_156 ) -> V_199 = ( V_74 -> V_104 + V_49 ) -> V_105 ;
( V_195 + V_156 ) -> V_200 = ( V_74 -> V_104 + V_49 ) -> V_106 ;
( V_195 + V_156 ) -> V_54 = V_203 ;
V_156 ++ ;
}
}
return V_156 ;
}
int F_132 ( struct V_10 * V_11 , unsigned int type ,
const char * V_14 , struct V_194 * V_204 )
{
int V_156 ;
unsigned int V_97 , V_109 ;
T_1 V_105 , V_106 ;
if ( ! V_11 || ! V_204 )
return - V_15 ;
if ( type == V_201 ) {
V_156 = F_44 ( V_11 , V_14 , & V_97 ) ;
if ( V_156 )
return V_156 ;
V_204 -> V_199 = V_97 ;
V_204 -> V_200 = V_97 ;
} else if ( type == V_202 ) {
V_156 = F_45 ( V_11 , V_14 , & V_109 ) ;
if ( V_156 )
return V_156 ;
V_204 -> V_199 = V_109 ;
V_204 -> V_200 = V_109 ;
} else if ( type == V_203 ) {
V_156 = F_46 ( V_11 , V_14 , & V_105 , & V_106 ) ;
if ( V_156 )
return V_156 ;
V_204 -> V_199 = V_105 ;
V_204 -> V_200 = V_106 ;
} else {
return - V_15 ;
}
V_204 -> V_54 = type ;
V_204 -> V_14 = V_14 ;
return 0 ;
}
struct V_205 * F_133 ( struct V_10 * V_11 )
{
struct V_75 * V_76 ;
struct V_1 * V_5 ;
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_69 ) {
V_76 = V_11 -> V_69 ;
} else {
V_5 = F_48 ( V_11 ) ;
if ( ! V_5 )
return NULL ;
V_76 = V_5 -> V_69 ;
}
if ( ! V_76 -> V_70 )
return NULL ;
return V_76 -> V_70 -> V_141 . V_142 ;
}
void T_5 * F_134 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_20 & V_92 )
return NULL ;
if ( V_11 -> V_58 == V_171 )
return NULL ;
return V_11 -> V_167 ;
}
int F_135 ( struct V_10 * V_11 ,
struct V_10 * V_68 )
{
return F_18 ( V_11 , V_68 ) ;
}
int F_136 ( struct V_10 * V_11 ,
struct V_10 * V_68 )
{
return F_20 ( V_11 , V_68 ) ;
}
int F_137 ( struct V_10 * V_11 )
{
unsigned long V_54 ;
T_1 V_22 ;
F_89 ( & V_11 -> V_164 , V_54 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_60 ) ) {
V_22 = V_11 -> V_16 ;
F_16 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_14 ( V_11 , true ) ;
F_90 ( & V_11 -> V_164 , V_54 ) ;
return 0 ;
}
int F_138 ( struct V_10 * V_11 )
{
unsigned long V_54 ;
T_1 V_22 ;
F_89 ( & V_11 -> V_164 , V_54 ) ;
if ( V_11 -> V_12 -> V_13 &&
( V_11 -> V_12 -> V_13 -> V_18 & V_60 ) ) {
V_22 = V_11 -> V_16 ;
F_17 ( V_11 , & V_22 ) ;
F_6 ( V_22 , V_11 ) ;
}
F_14 ( V_11 , false ) ;
F_90 ( & V_11 -> V_164 , V_54 ) ;
return 0 ;
}
int F_139 ( struct V_10 * V_11 , const char * V_14 )
{
int V_72 ;
unsigned long V_54 ;
if ( ! V_11 )
return - V_15 ;
F_89 ( & V_11 -> V_164 , V_54 ) ;
V_72 = F_63 ( V_11 , V_14 ) ;
F_90 ( & V_11 -> V_164 , V_54 ) ;
return V_72 ;
}
int F_140 ( struct V_10 * V_11 , const char * V_14 )
{
int V_72 ;
unsigned long V_54 ;
if ( ! V_11 )
return - V_15 ;
F_89 ( & V_11 -> V_164 , V_54 ) ;
V_72 = F_67 ( V_11 , V_14 ) ;
F_90 ( & V_11 -> V_164 , V_54 ) ;
return V_72 ;
}
int F_141 ( struct V_10 * V_11 , const char * V_14 )
{
int V_72 ;
unsigned long V_54 ;
if ( ! V_11 )
return - V_15 ;
F_89 ( & V_11 -> V_164 , V_54 ) ;
V_72 = F_71 ( V_11 , V_14 ) ;
F_90 ( & V_11 -> V_164 , V_54 ) ;
return V_72 ;
}
int F_142 ( const char * V_206 ,
int (* F_117)( struct V_10 * V_11 ,
void * V_110 ) ,
void * V_110 )
{
struct V_10 * V_124 ;
int V_72 = 0 ;
if ( ! V_206 || ! F_117 )
return - V_15 ;
F_28 ( L_56 ,
V_140 , V_206 ) ;
F_54 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_124 -> V_12 -> V_14 , V_206 ) ) {
F_28 ( L_57 ,
V_140 , V_124 -> V_14 ) ;
V_72 = (* F_117)( V_124 , V_110 ) ;
if ( V_72 )
break;
}
}
if ( V_72 )
F_28 ( L_58 ,
V_140 , V_72 ) ;
return V_72 ;
}
int F_143 ( struct V_10 * V_11 , T_2 V_207 )
{
int V_72 ;
unsigned long V_54 ;
if ( ! V_11 )
return - V_15 ;
if ( V_207 != V_161 &&
V_207 != V_146 &&
V_207 != V_59 )
return - V_15 ;
F_89 ( & V_11 -> V_164 , V_54 ) ;
if ( V_11 -> V_58 != V_127 ) {
V_72 = - V_15 ;
goto V_208;
}
V_11 -> V_170 = V_207 ;
V_72 = 0 ;
V_208:
F_90 ( & V_11 -> V_164 , V_54 ) ;
return V_72 ;
}
int F_144 ( struct V_10 * V_11 )
{
struct V_205 * V_141 ;
int V_72 = 0 ;
V_141 = F_133 ( V_11 ) ;
if ( V_141 )
V_72 = F_145 ( V_141 ) ;
return V_72 ;
}
int F_146 ( struct V_10 * V_11 )
{
if ( ! V_11 )
return - V_15 ;
if ( V_11 -> V_58 != V_127 ) {
F_69 ( L_59 ,
V_11 -> V_14 ) ;
return - V_15 ;
}
V_11 -> V_54 |= V_168 ;
return 0 ;
}
int F_147 ( struct V_10 * V_11 , int V_209 , int V_210 )
{
int V_211 ;
F_148 () ;
if ( ! V_11 || ! V_11 -> V_50 || ! V_11 -> V_96 || V_209 < 0 ||
V_209 >= V_11 -> V_50 -> V_52 )
return - V_15 ;
for ( V_211 = 0 ; V_11 -> V_96 [ V_211 ] . V_97 >= 0 ; V_211 ++ )
;
if ( V_210 >= V_211 )
return - V_15 ;
if ( ! V_11 -> V_50 -> V_212 ) {
V_11 -> V_50 -> V_212 = F_149 ( sizeof( int ) * V_11 -> V_50 -> V_52 ,
V_213 ) ;
if ( ! V_11 -> V_50 -> V_212 )
return - V_192 ;
}
V_11 -> V_50 -> V_212 [ V_209 ] = V_210 ;
return 0 ;
}
