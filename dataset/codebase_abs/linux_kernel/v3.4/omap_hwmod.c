static int F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 -> V_4 ) {
F_2 ( 1 , L_1 , V_2 -> V_5 ) ;
return - V_6 ;
}
V_2 -> V_7 = F_3 ( V_2 , V_2 -> V_3 -> V_4 -> V_8 ) ;
if ( ! ( V_2 -> V_3 -> V_4 -> V_9 & V_10 ) )
V_2 -> V_11 |= V_12 ;
return 0 ;
}
static void F_4 ( T_1 V_13 , struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 -> V_4 ) {
F_2 ( 1 , L_2 , V_2 -> V_5 ) ;
return;
}
V_2 -> V_7 = V_13 ;
F_5 ( V_13 , V_2 , V_2 -> V_3 -> V_4 -> V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_14 ,
T_1 * V_13 )
{
T_1 V_15 ;
T_2 V_16 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_17 ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_18 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
V_16 = V_2 -> V_3 -> V_4 -> V_18 -> V_19 ;
V_15 = ( 0x3 << V_16 ) ;
* V_13 &= ~ V_15 ;
* V_13 |= F_7 ( V_14 ) << V_16 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_20 , T_1 * V_13 )
{
T_1 V_21 ;
T_2 V_22 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_23 ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_18 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
V_22 = V_2 -> V_3 -> V_4 -> V_18 -> V_22 ;
V_21 = ( 0x3 << V_22 ) ;
* V_13 &= ~ V_21 ;
* V_13 |= F_7 ( V_20 ) << V_22 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_24 , T_1 * V_13 )
{
T_1 V_25 ;
T_2 V_26 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_27 ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_18 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
V_26 = V_2 -> V_3 -> V_4 -> V_18 -> V_26 ;
V_25 = ( 0x3 << V_26 ) ;
* V_13 &= ~ V_25 ;
* V_13 |= V_24 << V_26 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_13 )
{
T_1 V_28 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_29 ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_18 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
V_28 = ( 0x1 << V_2 -> V_3 -> V_4 -> V_18 -> V_30 ) ;
* V_13 |= V_28 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_31 ,
T_1 * V_13 )
{
T_1 V_32 ;
T_2 V_33 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_34 ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_18 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
V_33 = V_2 -> V_3 -> V_4 -> V_18 -> V_33 ;
V_32 = ( 0x1 << V_33 ) ;
* V_13 &= ~ V_32 ;
* V_13 |= V_31 << V_33 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , bool V_35 )
{
struct V_36 * V_37 ;
bool V_38 = false ;
T_3 V_39 ;
int V_40 ;
if ( ! V_2 -> V_41 || ! V_2 -> V_41 -> V_42 )
return;
for ( V_40 = 0 ; V_40 < V_2 -> V_41 -> V_43 ; V_40 ++ ) {
V_37 = V_2 -> V_41 -> V_44 [ V_40 ] ;
if ( ! ( V_37 -> V_45 & V_46 ) )
continue;
V_39 = V_37 -> V_47 ;
if ( V_35 )
V_37 -> V_47 |= V_48 ;
else
V_37 -> V_47 &= ~ V_48 ;
if ( V_39 != V_37 -> V_47 )
V_38 = true ;
}
if ( V_38 && V_2 -> V_49 == V_50 )
F_13 ( V_2 -> V_41 , V_50 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_13 )
{
if ( ! V_2 -> V_3 -> V_4 ||
! ( ( V_2 -> V_3 -> V_4 -> V_9 & V_51 ) ||
( V_2 -> V_3 -> V_4 -> V_52 & V_53 ) ||
( V_2 -> V_3 -> V_4 -> V_52 & V_54 ) ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_18 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_2 -> V_3 -> V_4 -> V_9 & V_51 )
* V_13 |= 0x1 << V_2 -> V_3 -> V_4 -> V_18 -> V_55 ;
if ( V_2 -> V_3 -> V_4 -> V_52 & V_53 )
F_8 ( V_2 , V_56 , V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_52 & V_54 )
F_6 ( V_2 , V_56 , V_13 ) ;
V_2 -> V_11 |= V_57 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 * V_13 )
{
if ( ! V_2 -> V_3 -> V_4 ||
! ( ( V_2 -> V_3 -> V_4 -> V_9 & V_51 ) ||
( V_2 -> V_3 -> V_4 -> V_52 & V_53 ) ||
( V_2 -> V_3 -> V_4 -> V_52 & V_54 ) ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_18 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_2 -> V_3 -> V_4 -> V_9 & V_51 )
* V_13 &= ~ ( 0x1 << V_2 -> V_3 -> V_4 -> V_18 -> V_55 ) ;
if ( V_2 -> V_3 -> V_4 -> V_52 & V_53 )
F_8 ( V_2 , V_58 , V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_52 & V_54 )
F_6 ( V_2 , V_56 , V_13 ) ;
V_2 -> V_11 &= ~ V_57 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_1 * V_59 )
{
if ( ! V_2 -> V_60 )
return - V_6 ;
if ( V_2 -> V_60 -> V_61 && V_2 -> V_60 -> V_61 -> V_45 & V_62 )
return 0 ;
return F_17 ( V_2 -> V_60 -> V_61 , V_59 -> V_60 -> V_61 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_1 * V_59 )
{
if ( ! V_2 -> V_60 )
return - V_6 ;
if ( V_2 -> V_60 -> V_61 && V_2 -> V_60 -> V_61 -> V_45 & V_62 )
return 0 ;
return F_19 ( V_2 -> V_60 -> V_61 , V_59 -> V_60 -> V_61 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_63 = 0 ;
if ( ! V_2 -> V_64 )
return 0 ;
V_2 -> V_60 = F_21 ( V_2 -> V_64 ) ;
if ( ! V_2 -> V_60 ) {
F_22 ( L_4 ,
V_2 -> V_5 , V_2 -> V_64 ) ;
return - V_6 ;
}
if ( ! V_2 -> V_60 -> V_61 )
F_22 ( L_5 ,
V_2 -> V_64 , V_2 -> V_60 -> V_5 ) ;
return V_63 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
int V_67 ;
int V_63 = 0 ;
if ( V_2 -> V_68 == 0 )
return 0 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_68 ; V_67 ++ ) {
struct V_69 * V_70 = V_2 -> V_71 [ V_67 ] ;
if ( ! V_70 -> V_65 )
continue;
V_66 = F_21 ( V_70 -> V_65 ) ;
if ( ! V_66 ) {
F_22 ( L_6 ,
V_2 -> V_5 , V_70 -> V_65 ) ;
V_63 = - V_6 ;
}
V_70 -> V_60 = V_66 ;
}
return V_63 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_72 * V_73 ;
struct V_65 * V_66 ;
int V_67 ;
int V_63 = 0 ;
for ( V_67 = V_2 -> V_74 , V_73 = V_2 -> V_75 ; V_67 > 0 ; V_67 -- , V_73 ++ ) {
V_66 = F_21 ( V_73 -> V_65 ) ;
if ( ! V_66 ) {
F_22 ( L_7 ,
V_2 -> V_5 , V_73 -> V_65 ) ;
V_63 = - V_6 ;
}
V_73 -> V_60 = V_66 ;
}
return V_63 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_67 ;
F_26 ( L_8 , V_2 -> V_5 ) ;
if ( V_2 -> V_60 )
F_27 ( V_2 -> V_60 ) ;
if ( V_2 -> V_68 > 0 ) {
for ( V_67 = 0 ; V_67 < V_2 -> V_68 ; V_67 ++ ) {
struct V_69 * V_70 = V_2 -> V_71 [ V_67 ] ;
struct V_65 * V_66 = V_70 -> V_60 ;
if ( V_66 && ( V_70 -> V_45 & V_76 ) )
F_27 ( V_66 ) ;
}
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_67 ;
F_26 ( L_9 , V_2 -> V_5 ) ;
if ( V_2 -> V_60 )
F_29 ( V_2 -> V_60 ) ;
if ( V_2 -> V_68 > 0 ) {
for ( V_67 = 0 ; V_67 < V_2 -> V_68 ; V_67 ++ ) {
struct V_69 * V_70 = V_2 -> V_71 [ V_67 ] ;
struct V_65 * V_66 = V_70 -> V_60 ;
if ( V_66 && ( V_70 -> V_45 & V_76 ) )
F_29 ( V_66 ) ;
}
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_72 * V_73 ;
int V_67 ;
F_26 ( L_10 , V_2 -> V_5 ) ;
for ( V_67 = V_2 -> V_74 , V_73 = V_2 -> V_75 ; V_67 > 0 ; V_67 -- , V_73 ++ )
if ( V_73 -> V_60 ) {
F_26 ( L_11 , V_73 -> V_77 ,
V_73 -> V_60 -> V_5 ) ;
F_27 ( V_73 -> V_60 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_72 * V_73 ;
int V_67 ;
F_26 ( L_12 , V_2 -> V_5 ) ;
for ( V_67 = V_2 -> V_74 , V_73 = V_2 -> V_75 ; V_67 > 0 ; V_67 -- , V_73 ++ )
if ( V_73 -> V_60 ) {
F_26 ( L_13 , V_73 -> V_77 ,
V_73 -> V_60 -> V_5 ) ;
F_29 ( V_73 -> V_60 ) ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
if ( F_33 () || F_34 () )
return;
if ( ! V_2 -> V_61 || ! V_2 -> V_78 . V_79 . V_80 )
return;
F_26 ( L_14 ,
V_2 -> V_5 , V_2 -> V_78 . V_79 . V_80 ) ;
F_35 ( V_2 -> V_78 . V_79 . V_80 ,
V_2 -> V_61 -> V_81 ,
V_2 -> V_61 -> V_82 ,
V_2 -> V_61 -> V_83 ,
V_2 -> V_78 . V_79 . V_84 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
if ( ! F_37 () )
return 0 ;
if ( ! V_2 )
return - V_6 ;
if ( V_2 -> V_11 & V_85 )
return 0 ;
if ( V_2 -> V_45 & V_86 )
return 0 ;
return F_38 ( V_2 -> V_61 -> V_81 ,
V_2 -> V_61 -> V_82 ,
V_2 -> V_61 -> V_83 ,
V_2 -> V_78 . V_79 . V_84 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_13 ;
if ( ! F_37 () )
return - V_6 ;
if ( ! V_2 -> V_61 || ! V_2 -> V_78 . V_79 . V_80 )
return - V_6 ;
F_26 ( L_15 , V_2 -> V_5 , V_87 ) ;
F_40 ( V_2 -> V_61 -> V_81 ,
V_2 -> V_61 -> V_82 ,
V_2 -> V_61 -> V_83 ,
V_2 -> V_78 . V_79 . V_84 ) ;
V_13 = F_36 ( V_2 ) ;
if ( V_13 )
F_41 ( L_16 ,
V_2 -> V_5 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_88 * V_89 ;
int V_67 = 0 ;
if ( ! V_2 || ! V_2 -> V_90 )
return 0 ;
do {
V_89 = & V_2 -> V_90 [ V_67 ++ ] ;
} while ( V_89 -> V_91 != - 1 );
return V_67 - 1 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_92 * V_93 ;
int V_67 = 0 ;
if ( ! V_2 || ! V_2 -> V_94 )
return 0 ;
do {
V_93 = & V_2 -> V_94 [ V_67 ++ ] ;
} while ( V_93 -> V_95 != - 1 );
return V_67 - 1 ;
}
static int F_44 ( struct V_69 * V_70 )
{
struct V_96 * V_97 ;
int V_67 = 0 ;
if ( ! V_70 || ! V_70 -> V_98 )
return 0 ;
do {
V_97 = & V_70 -> V_98 [ V_67 ++ ] ;
} while ( V_97 -> V_99 != V_97 -> V_100 );
return V_67 - 1 ;
}
static int T_4 F_45 ( struct V_1 * V_2 )
{
int V_67 ;
int V_101 = 0 ;
if ( ! V_2 || V_2 -> V_68 == 0 )
return - V_6 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_68 ; V_67 ++ ) {
struct V_69 * V_70 = V_2 -> V_71 [ V_67 ] ;
if ( V_70 -> V_102 & V_103 ) {
V_101 = 1 ;
break;
}
}
if ( V_101 )
F_26 ( L_17 ,
V_2 -> V_5 , V_67 ) ;
else
F_26 ( L_18 ,
V_2 -> V_5 ) ;
return ( V_101 ) ? V_67 : - V_6 ;
}
static void T_5 * T_4 F_46 ( struct V_1 * V_2 , T_2 V_104 )
{
struct V_69 * V_70 ;
struct V_96 * V_97 ;
int V_67 = 0 , V_101 = 0 ;
void T_5 * va_start ;
if ( ! V_2 || V_2 -> V_68 == 0 )
return NULL ;
V_70 = V_2 -> V_71 [ V_104 ] ;
if ( ! V_70 -> V_98 )
return NULL ;
do {
V_97 = & V_70 -> V_98 [ V_67 ++ ] ;
if ( V_97 -> V_45 & V_105 )
V_101 = 1 ;
} while ( ! V_101 && V_97 -> V_99 != V_97 -> V_100 );
if ( V_101 ) {
va_start = F_47 ( V_97 -> V_99 , V_97 -> V_100 - V_97 -> V_99 ) ;
if ( ! va_start ) {
F_48 ( L_19 , V_2 -> V_5 ) ;
return NULL ;
}
F_26 ( L_20 ,
V_2 -> V_5 , va_start ) ;
} else {
F_26 ( L_21 ,
V_2 -> V_5 ) ;
}
return ( V_101 ) ? va_start : NULL ;
}
static void F_49 ( struct V_1 * V_2 )
{
T_2 V_20 , V_106 ;
T_1 V_13 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
V_13 = V_2 -> V_7 ;
V_106 = V_2 -> V_3 -> V_4 -> V_9 ;
if ( V_106 & V_23 ) {
V_20 = ( V_2 -> V_45 & V_107 ) ?
V_108 : V_58 ;
F_8 ( V_2 , V_20 , & V_13 ) ;
}
if ( V_106 & V_17 ) {
if ( V_2 -> V_45 & V_109 ) {
V_20 = V_108 ;
} else {
if ( V_106 & V_51 )
F_14 ( V_2 , & V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_52 & V_54 )
V_20 = V_56 ;
else
V_20 = V_58 ;
}
F_6 ( V_2 , V_20 , & V_13 ) ;
}
if ( ( V_2 -> V_45 & V_110 ) &&
( V_106 & V_27 ) )
F_9 ( V_2 , V_2 -> V_3 -> V_4 -> V_24 , & V_13 ) ;
if ( ( V_106 & V_23 ) && ! ( V_2 -> V_45 & V_107 ) )
F_14 ( V_2 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
if ( V_106 & V_34 ) {
V_20 = ( V_2 -> V_45 & V_111 ) ?
0 : 1 ;
F_11 ( V_2 , V_20 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
}
static void F_50 ( struct V_1 * V_2 )
{
T_2 V_20 , V_106 ;
T_1 V_13 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
V_13 = V_2 -> V_7 ;
V_106 = V_2 -> V_3 -> V_4 -> V_9 ;
if ( V_106 & V_23 ) {
V_20 = ( V_2 -> V_45 & V_107 ) ?
V_112 : V_58 ;
F_8 ( V_2 , V_20 , & V_13 ) ;
}
if ( V_106 & V_17 ) {
if ( V_2 -> V_45 & V_109 ) {
V_20 = V_112 ;
} else {
if ( V_106 & V_51 )
F_14 ( V_2 , & V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_52 & V_54 )
V_20 = V_56 ;
else
V_20 = V_58 ;
}
F_6 ( V_2 , V_20 , & V_13 ) ;
}
if ( ( V_106 & V_23 ) && ! ( V_2 -> V_45 & V_107 ) )
F_14 ( V_2 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
T_1 V_13 ;
T_2 V_106 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
V_13 = V_2 -> V_7 ;
V_106 = V_2 -> V_3 -> V_4 -> V_9 ;
if ( V_106 & V_23 )
F_8 ( V_2 , V_112 , & V_13 ) ;
if ( V_106 & V_17 )
F_6 ( V_2 , V_112 , & V_13 ) ;
if ( V_106 & V_34 )
F_11 ( V_2 , 1 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
static struct V_1 * F_52 ( const char * V_5 )
{
struct V_1 * V_2 , * V_113 ;
V_2 = NULL ;
F_53 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_5 , V_113 -> V_5 ) ) {
V_2 = V_113 ;
break;
}
}
return V_2 ;
}
static int F_54 ( struct V_1 * V_2 )
{
if ( F_33 () || F_34 () )
return 0 ;
if ( ! V_2 -> V_114 ) {
F_22 ( L_22 , V_2 -> V_5 ) ;
return - V_6 ;
}
V_2 -> V_61 = F_55 ( V_2 -> V_114 ) ;
if ( ! V_2 -> V_61 ) {
F_22 ( L_23 ,
V_2 -> V_5 , V_2 -> V_114 ) ;
return - V_6 ;
}
F_26 ( L_24 ,
V_2 -> V_5 , V_2 -> V_114 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , void * V_115 )
{
int V_63 = 0 ;
if ( V_2 -> V_49 != V_116 )
return 0 ;
F_26 ( L_25 , V_2 -> V_5 ) ;
V_63 |= F_20 ( V_2 ) ;
V_63 |= F_23 ( V_2 ) ;
V_63 |= F_24 ( V_2 ) ;
V_63 |= F_54 ( V_2 ) ;
if ( ! V_63 )
V_2 -> V_49 = V_117 ;
else
F_22 ( L_26 , V_2 -> V_5 ) ;
return V_63 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_69 * V_70 ;
int V_63 ;
if ( ! V_2 )
return - V_6 ;
if ( V_2 -> V_11 & V_85 )
return 0 ;
V_70 = V_2 -> V_71 [ V_2 -> V_118 ] ;
if ( V_2 -> V_45 & V_86 )
return 0 ;
if ( F_33 () || F_34 () ) {
V_63 = F_58 ( V_2 -> V_78 . V_119 . V_120 ,
V_2 -> V_78 . V_119 . V_121 ,
V_2 -> V_78 . V_119 . V_122 ) ;
} else if ( F_37 () ) {
if ( ! V_2 -> V_61 )
return - V_6 ;
V_63 = F_59 ( V_2 -> V_61 -> V_81 ,
V_2 -> V_61 -> V_82 ,
V_2 -> V_61 -> V_83 ,
V_2 -> V_78 . V_79 . V_84 ) ;
} else {
F_60 () ;
} ;
return V_63 ;
}
static T_2 F_61 ( struct V_1 * V_2 , const char * V_5 ,
struct V_123 * V_124 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_125 ; V_67 ++ ) {
const char * V_126 = V_2 -> V_127 [ V_67 ] . V_5 ;
if ( ! strcmp ( V_126 , V_5 ) ) {
V_124 -> V_128 = V_2 -> V_127 [ V_67 ] . V_128 ;
V_124 -> V_129 = V_2 -> V_127 [ V_67 ] . V_129 ;
F_26 ( L_27 ,
V_2 -> V_5 , V_87 , V_126 , V_124 -> V_128 ,
V_124 -> V_129 ) ;
return 0 ;
}
}
return - V_130 ;
}
static int F_62 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_123 V_124 ;
T_2 V_63 ;
if ( ! V_2 )
return - V_6 ;
V_63 = F_61 ( V_2 , V_5 , & V_124 ) ;
if ( F_63 ( V_63 ) )
return V_63 ;
if ( F_33 () || F_34 () )
return F_64 ( V_2 -> V_78 . V_119 . V_120 ,
V_124 . V_128 ) ;
else if ( F_37 () )
return F_65 ( V_124 . V_128 ,
V_2 -> V_61 -> V_131 . V_132 -> V_81 ,
V_2 -> V_61 -> V_131 . V_132 -> V_133 ,
V_2 -> V_78 . V_79 . V_134 ) ;
else
return - V_6 ;
}
static int F_66 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_123 V_124 ;
int V_63 ;
if ( ! V_2 )
return - V_6 ;
V_63 = F_61 ( V_2 , V_5 , & V_124 ) ;
if ( F_63 ( V_63 ) )
return V_63 ;
if ( F_33 () || F_34 () ) {
V_63 = F_67 ( V_2 -> V_78 . V_119 . V_120 ,
V_124 . V_128 ,
V_124 . V_129 ) ;
} else if ( F_37 () ) {
if ( V_124 . V_129 )
F_48 ( L_28 ,
V_2 -> V_5 , V_5 ) ;
V_63 = F_68 ( V_124 . V_128 ,
V_2 -> V_61 -> V_131 . V_132 -> V_81 ,
V_2 -> V_61 -> V_131 . V_132 -> V_133 ,
V_2 -> V_78 . V_79 . V_134 ) ;
} else {
return - V_6 ;
}
if ( V_63 == - V_135 )
F_22 ( L_29 , V_2 -> V_5 ) ;
return V_63 ;
}
static int F_69 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_123 V_124 ;
T_2 V_63 ;
if ( ! V_2 )
return - V_6 ;
V_63 = F_61 ( V_2 , V_5 , & V_124 ) ;
if ( F_63 ( V_63 ) )
return V_63 ;
if ( F_33 () || F_34 () ) {
return F_70 ( V_2 -> V_78 . V_119 . V_120 ,
V_124 . V_129 ) ;
} else if ( F_37 () ) {
return F_71 ( V_124 . V_128 ,
V_2 -> V_61 -> V_131 . V_132 -> V_81 ,
V_2 -> V_61 -> V_131 . V_132 -> V_133 ,
V_2 -> V_78 . V_79 . V_134 ) ;
} else {
return - V_6 ;
}
}
static int F_72 ( struct V_1 * V_2 )
{
T_1 V_13 , V_28 ;
int V_66 = 0 ;
int V_63 = 0 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_29 ) )
return - V_6 ;
if ( V_2 -> V_49 != V_136 ) {
F_22 ( L_30
L_31 , V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_2 -> V_45 & V_137 )
F_30 ( V_2 ) ;
F_26 ( L_32 , V_2 -> V_5 ) ;
V_13 = V_2 -> V_7 ;
V_63 = F_10 ( V_2 , & V_13 ) ;
if ( V_63 )
goto V_138;
F_4 ( V_13 , V_2 ) ;
if ( V_2 -> V_3 -> V_4 -> V_139 )
F_73 ( V_2 -> V_3 -> V_4 -> V_139 ) ;
if ( V_2 -> V_3 -> V_4 -> V_9 & V_140 )
F_74 ( ( F_3 ( V_2 ,
V_2 -> V_3 -> V_4 -> V_141 )
& V_142 ) ,
V_143 , V_66 ) ;
else if ( V_2 -> V_3 -> V_4 -> V_9 & V_144 ) {
V_28 = ( 0x1 << V_2 -> V_3 -> V_4 -> V_18 -> V_30 ) ;
F_74 ( ! ( F_3 ( V_2 ,
V_2 -> V_3 -> V_4 -> V_8 )
& V_28 ) ,
V_143 , V_66 ) ;
}
if ( V_66 == V_143 )
F_22 ( L_33 ,
V_2 -> V_5 , V_143 ) ;
else
F_26 ( L_34 , V_2 -> V_5 , V_66 ) ;
V_63 = ( V_66 == V_143 ) ? - V_145 : 0 ;
V_138:
if ( V_2 -> V_45 & V_137 )
F_31 ( V_2 ) ;
return V_63 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_63 ;
F_26 ( L_35 , V_2 -> V_5 ) ;
V_63 = ( V_2 -> V_3 -> V_146 ) ? V_2 -> V_3 -> V_146 ( V_2 ) : F_72 ( V_2 ) ;
if ( V_2 -> V_3 -> V_4 ) {
F_1 ( V_2 ) ;
F_49 ( V_2 ) ;
}
return V_63 ;
}
static int F_76 ( struct V_1 * V_2 )
{
int V_147 ;
int V_148 = 0 ;
F_26 ( L_36 , V_2 -> V_5 ) ;
if ( V_2 -> V_11 & V_149 ) {
if ( V_2 -> V_41 )
F_13 ( V_2 -> V_41 , V_136 ) ;
V_2 -> V_11 &= ~ V_149 ;
return 0 ;
}
if ( V_2 -> V_49 != V_150 &&
V_2 -> V_49 != V_50 &&
V_2 -> V_49 != V_151 ) {
F_2 ( 1 , L_37 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
if ( ( V_2 -> V_49 == V_150 ||
V_2 -> V_49 == V_151 ) && V_2 -> V_125 == 1 )
F_66 ( V_2 , V_2 -> V_127 [ 0 ] . V_5 ) ;
if ( V_2 -> V_41 && ( ! V_2 -> V_41 -> V_42 ||
( ( V_2 -> V_49 == V_50 ) &&
V_2 -> V_41 -> V_44 ) ) )
F_13 ( V_2 -> V_41 , V_136 ) ;
F_16 ( V_2 , V_152 ) ;
if ( V_2 -> V_61 ) {
V_148 = F_77 ( V_2 -> V_61 ) ;
V_147 = F_78 ( V_2 -> V_61 , V_2 ) ;
if ( V_147 ) {
F_2 ( 1 , L_38 ,
V_2 -> V_5 , V_2 -> V_61 -> V_5 , V_147 ) ;
return V_147 ;
}
}
F_25 ( V_2 ) ;
F_32 ( V_2 ) ;
V_147 = F_57 ( V_2 ) ;
if ( ! V_147 ) {
if ( V_2 -> V_61 && V_148 )
F_79 ( V_2 -> V_61 ) ;
V_2 -> V_49 = V_136 ;
if ( V_2 -> V_3 -> V_4 ) {
if ( ! ( V_2 -> V_11 & V_12 ) )
F_1 ( V_2 ) ;
F_49 ( V_2 ) ;
}
} else {
F_28 ( V_2 ) ;
F_26 ( L_39 ,
V_2 -> V_5 , V_147 ) ;
if ( V_2 -> V_61 )
F_80 ( V_2 -> V_61 , V_2 ) ;
}
return V_147 ;
}
static int F_81 ( struct V_1 * V_2 )
{
F_26 ( L_40 , V_2 -> V_5 ) ;
if ( V_2 -> V_49 != V_136 ) {
F_2 ( 1 , L_41 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_2 -> V_3 -> V_4 )
F_50 ( V_2 ) ;
F_18 ( V_2 , V_152 ) ;
F_39 ( V_2 ) ;
F_28 ( V_2 ) ;
if ( V_2 -> V_61 )
F_80 ( V_2 -> V_61 , V_2 ) ;
if ( V_2 -> V_41 && V_2 -> V_41 -> V_44 )
F_13 ( V_2 -> V_41 , V_50 ) ;
V_2 -> V_49 = V_50 ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 , T_2 V_31 )
{
T_1 V_13 ;
int V_153 = 0 ;
unsigned long V_45 ;
if ( ! V_2 || V_2 -> V_49 != V_136 )
return - V_6 ;
F_83 ( & V_2 -> V_154 , V_45 ) ;
V_13 = V_2 -> V_7 ;
V_153 = F_11 ( V_2 , V_31 , & V_13 ) ;
if ( ! V_153 )
F_4 ( V_13 , V_2 ) ;
F_84 ( & V_2 -> V_154 , V_45 ) ;
return V_153 ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_63 ;
T_2 V_155 ;
if ( V_2 -> V_49 != V_50 &&
V_2 -> V_49 != V_136 ) {
F_2 ( 1 , L_42 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
F_26 ( L_43 , V_2 -> V_5 ) ;
if ( V_2 -> V_3 -> V_156 ) {
V_155 = V_2 -> V_49 ;
if ( V_2 -> V_49 == V_50 )
F_76 ( V_2 ) ;
V_63 = V_2 -> V_3 -> V_156 ( V_2 ) ;
if ( V_63 ) {
if ( V_155 == V_50 )
F_81 ( V_2 ) ;
return V_63 ;
}
}
if ( V_2 -> V_3 -> V_4 ) {
if ( V_2 -> V_49 == V_50 )
F_76 ( V_2 ) ;
F_51 ( V_2 ) ;
}
if ( V_2 -> V_49 == V_136 ) {
F_18 ( V_2 , V_152 ) ;
F_39 ( V_2 ) ;
F_28 ( V_2 ) ;
if ( V_2 -> V_61 )
F_80 ( V_2 -> V_61 , V_2 ) ;
}
if ( V_2 -> V_125 == 1 )
F_62 ( V_2 , V_2 -> V_127 [ 0 ] . V_5 ) ;
if ( V_2 -> V_41 )
F_13 ( V_2 -> V_41 , V_151 ) ;
V_2 -> V_49 = V_151 ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 , void * V_115 )
{
int V_67 , V_147 ;
T_2 V_157 ;
if ( V_2 -> V_49 != V_117 )
return 0 ;
if ( V_2 -> V_68 > 0 ) {
for ( V_67 = 0 ; V_67 < V_2 -> V_68 ; V_67 ++ ) {
struct V_69 * V_70 = V_2 -> V_71 [ V_67 ] ;
struct V_65 * V_66 = V_70 -> V_60 ;
if ( ! V_66 )
continue;
if ( V_70 -> V_45 & V_76 ) {
} else {
F_27 ( V_66 ) ;
}
}
}
V_2 -> V_49 = V_150 ;
if ( ( V_2 -> V_45 & V_158 ) && V_2 -> V_125 == 1 )
return 0 ;
V_147 = F_76 ( V_2 ) ;
if ( V_147 ) {
F_22 ( L_44 ,
V_2 -> V_5 , V_2 -> V_49 ) ;
return 0 ;
}
if ( ! ( V_2 -> V_45 & V_158 ) )
F_75 ( V_2 ) ;
V_157 = V_2 -> V_159 ;
if ( V_157 == V_160 )
V_157 = V_136 ;
if ( ( V_2 -> V_45 & V_161 ) &&
( V_157 == V_50 ) ) {
V_2 -> V_11 |= V_149 ;
V_157 = V_136 ;
}
if ( V_157 == V_50 )
F_81 ( V_2 ) ;
else if ( V_157 == V_151 )
F_85 ( V_2 ) ;
else if ( V_157 != V_136 )
F_2 ( 1 , L_45 ,
V_2 -> V_5 , V_157 ) ;
return 0 ;
}
static int T_4 F_87 ( struct V_1 * V_2 )
{
int V_162 ;
if ( ! V_2 || ! V_2 -> V_5 || ! V_2 -> V_3 || ! V_2 -> V_3 -> V_5 ||
( V_2 -> V_49 != V_160 ) )
return - V_6 ;
F_26 ( L_46 , V_2 -> V_5 ) ;
if ( F_52 ( V_2 -> V_5 ) )
return - V_163 ;
V_162 = F_45 ( V_2 ) ;
if ( ! F_63 ( V_162 ) )
V_2 -> V_118 = V_162 ;
else
V_2 -> V_11 |= V_85 ;
F_88 ( & V_2 -> V_164 , & V_165 ) ;
F_89 ( & V_2 -> V_154 ) ;
V_2 -> V_49 = V_116 ;
if ( ! strcmp ( V_2 -> V_5 , V_166 ) )
V_152 = V_2 ;
return 0 ;
}
T_1 F_3 ( struct V_1 * V_2 , T_3 V_167 )
{
if ( V_2 -> V_45 & V_168 )
return F_90 ( V_2 -> V_169 + V_167 ) ;
else
return F_91 ( V_2 -> V_169 + V_167 ) ;
}
void F_5 ( T_1 V_13 , struct V_1 * V_2 , T_3 V_167 )
{
if ( V_2 -> V_45 & V_168 )
F_92 ( V_13 , V_2 -> V_169 + V_167 ) ;
else
F_93 ( V_13 , V_2 -> V_169 + V_167 ) ;
}
int F_94 ( struct V_1 * V_2 )
{
T_1 V_13 ;
int V_63 ;
if ( ! V_2 || ! ( V_2 -> V_7 ) )
return - V_6 ;
V_13 = V_2 -> V_7 ;
V_63 = F_10 ( V_2 , & V_13 ) ;
if ( V_63 )
goto error;
F_4 ( V_13 , V_2 ) ;
error:
return V_63 ;
}
int F_95 ( struct V_1 * V_2 , T_2 V_20 )
{
T_1 V_13 ;
int V_153 = 0 ;
if ( ! V_2 )
return - V_6 ;
V_13 = V_2 -> V_7 ;
V_153 = F_8 ( V_2 , V_20 , & V_13 ) ;
if ( ! V_153 )
F_4 ( V_13 , V_2 ) ;
return V_153 ;
}
struct V_1 * F_96 ( const char * V_5 )
{
struct V_1 * V_2 ;
if ( ! V_5 )
return NULL ;
V_2 = F_52 ( V_5 ) ;
return V_2 ;
}
int F_97 ( int (* F_98)( struct V_1 * V_2 , void * V_115 ) ,
void * V_115 )
{
struct V_1 * V_113 ;
int V_63 = 0 ;
if ( ! F_98 )
return - V_6 ;
F_53 (temp_oh, &omap_hwmod_list, node) {
V_63 = (* F_98)( V_113 , V_115 ) ;
if ( V_63 )
break;
}
return V_63 ;
}
int T_4 F_99 ( struct V_1 * * V_170 )
{
int V_147 , V_67 ;
if ( ! V_170 )
return 0 ;
V_67 = 0 ;
do {
V_147 = F_87 ( V_170 [ V_67 ] ) ;
F_2 ( V_147 , L_47 , V_170 [ V_67 ] -> V_5 ,
V_147 ) ;
} while ( V_170 [ ++ V_67 ] );
return 0 ;
}
static int T_4 F_100 ( struct V_1 * V_2 , void * V_115 )
{
if ( V_2 -> V_49 != V_116 )
return 0 ;
if ( V_2 -> V_11 & V_85 )
return 0 ;
V_2 -> V_169 = F_46 ( V_2 , V_2 -> V_118 ) ;
return 0 ;
}
int T_4 F_101 ( const char * V_171 )
{
struct V_1 * V_2 ;
int V_147 ;
F_26 ( L_15 , V_171 , V_87 ) ;
if ( ! V_152 ) {
F_48 ( L_48 ,
V_171 , V_166 ) ;
return - V_6 ;
}
V_2 = F_52 ( V_171 ) ;
if ( ! V_2 ) {
F_2 ( 1 , L_49 , V_171 ) ;
return - V_6 ;
}
if ( V_152 -> V_49 == V_116 && V_2 != V_152 )
F_101 ( V_166 ) ;
V_147 = F_100 ( V_2 , NULL ) ;
if ( F_63 ( V_147 ) ) {
F_2 ( 1 , L_50 , V_171 ) ;
return - V_6 ;
}
V_147 = F_56 ( V_2 , NULL ) ;
if ( F_63 ( V_147 ) ) {
F_2 ( 1 , L_51 , V_171 ) ;
return - V_6 ;
}
F_86 ( V_2 , NULL ) ;
return 0 ;
}
static int T_4 F_102 ( void )
{
int V_147 ;
if ( ! V_152 ) {
F_48 ( L_52 ,
V_87 , V_166 ) ;
return - V_6 ;
}
V_147 = F_97 ( F_100 , NULL ) ;
V_147 = F_97 ( F_56 , NULL ) ;
F_2 ( F_63 ( V_147 ) ,
L_53 , V_87 ) ;
F_97 ( F_86 , NULL ) ;
return 0 ;
}
int F_103 ( struct V_1 * V_2 )
{
int V_147 ;
unsigned long V_45 ;
if ( ! V_2 )
return - V_6 ;
F_83 ( & V_2 -> V_154 , V_45 ) ;
V_147 = F_76 ( V_2 ) ;
F_84 ( & V_2 -> V_154 , V_45 ) ;
return V_147 ;
}
int F_104 ( struct V_1 * V_2 )
{
unsigned long V_45 ;
if ( ! V_2 )
return - V_6 ;
F_83 ( & V_2 -> V_154 , V_45 ) ;
F_81 ( V_2 ) ;
F_84 ( & V_2 -> V_154 , V_45 ) ;
return 0 ;
}
int F_105 ( struct V_1 * V_2 )
{
unsigned long V_45 ;
if ( ! V_2 )
return - V_6 ;
F_83 ( & V_2 -> V_154 , V_45 ) ;
F_85 ( V_2 ) ;
F_84 ( & V_2 -> V_154 , V_45 ) ;
return 0 ;
}
int F_106 ( struct V_1 * V_2 )
{
unsigned long V_45 ;
F_83 ( & V_2 -> V_154 , V_45 ) ;
F_25 ( V_2 ) ;
F_84 ( & V_2 -> V_154 , V_45 ) ;
return 0 ;
}
int F_107 ( struct V_1 * V_2 )
{
unsigned long V_45 ;
F_83 ( & V_2 -> V_154 , V_45 ) ;
F_28 ( V_2 ) ;
F_84 ( & V_2 -> V_154 , V_45 ) ;
return 0 ;
}
void F_108 ( struct V_1 * V_2 )
{
F_109 ( ! V_2 ) ;
if ( ! V_2 -> V_3 -> V_4 || ! V_2 -> V_3 -> V_4 -> V_9 ) {
F_2 ( 1 , L_54 ,
V_2 -> V_5 ) ;
return;
}
F_3 ( V_2 , V_2 -> V_3 -> V_4 -> V_8 ) ;
}
int F_110 ( struct V_1 * V_2 )
{
int V_147 ;
unsigned long V_45 ;
if ( ! V_2 )
return - V_6 ;
F_83 ( & V_2 -> V_154 , V_45 ) ;
V_147 = F_75 ( V_2 ) ;
F_84 ( & V_2 -> V_154 , V_45 ) ;
return V_147 ;
}
int F_111 ( struct V_1 * V_2 )
{
int V_63 , V_67 ;
V_63 = F_42 ( V_2 ) + F_43 ( V_2 ) ;
for ( V_67 = 0 ; V_67 < V_2 -> V_68 ; V_67 ++ )
V_63 += F_44 ( V_2 -> V_71 [ V_67 ] ) ;
return V_63 ;
}
int F_112 ( struct V_1 * V_2 , struct V_172 * V_173 )
{
int V_67 , V_40 , V_174 , V_175 ;
int V_147 = 0 ;
V_174 = F_42 ( V_2 ) ;
for ( V_67 = 0 ; V_67 < V_174 ; V_67 ++ ) {
( V_173 + V_147 ) -> V_5 = ( V_2 -> V_90 + V_67 ) -> V_5 ;
( V_173 + V_147 ) -> V_176 = ( V_2 -> V_90 + V_67 ) -> V_91 ;
( V_173 + V_147 ) -> V_177 = ( V_2 -> V_90 + V_67 ) -> V_91 ;
( V_173 + V_147 ) -> V_45 = V_178 ;
V_147 ++ ;
}
V_175 = F_43 ( V_2 ) ;
for ( V_67 = 0 ; V_67 < V_175 ; V_67 ++ ) {
( V_173 + V_147 ) -> V_5 = ( V_2 -> V_94 + V_67 ) -> V_5 ;
( V_173 + V_147 ) -> V_176 = ( V_2 -> V_94 + V_67 ) -> V_95 ;
( V_173 + V_147 ) -> V_177 = ( V_2 -> V_94 + V_67 ) -> V_95 ;
( V_173 + V_147 ) -> V_45 = V_179 ;
V_147 ++ ;
}
for ( V_67 = 0 ; V_67 < V_2 -> V_68 ; V_67 ++ ) {
struct V_69 * V_70 ;
int V_180 ;
V_70 = V_2 -> V_71 [ V_67 ] ;
V_180 = F_44 ( V_70 ) ;
for ( V_40 = 0 ; V_40 < V_180 ; V_40 ++ ) {
( V_173 + V_147 ) -> V_5 = ( V_70 -> V_98 + V_40 ) -> V_5 ;
( V_173 + V_147 ) -> V_176 = ( V_70 -> V_98 + V_40 ) -> V_99 ;
( V_173 + V_147 ) -> V_177 = ( V_70 -> V_98 + V_40 ) -> V_100 ;
( V_173 + V_147 ) -> V_45 = V_181 ;
V_147 ++ ;
}
}
return V_147 ;
}
struct V_182 * F_113 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_60 ) {
V_66 = V_2 -> V_60 ;
} else {
if ( V_2 -> V_11 & V_85 )
return NULL ;
V_66 = V_2 -> V_71 [ V_2 -> V_118 ] -> V_60 ;
}
if ( ! V_66 -> V_61 )
return NULL ;
return V_66 -> V_61 -> V_131 . V_132 ;
}
void T_5 * F_114 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_11 & V_85 )
return NULL ;
if ( V_2 -> V_49 == V_160 )
return NULL ;
return V_2 -> V_169 ;
}
int F_115 ( struct V_1 * V_2 ,
struct V_1 * V_59 )
{
return F_16 ( V_2 , V_59 ) ;
}
int F_116 ( struct V_1 * V_2 ,
struct V_1 * V_59 )
{
return F_18 ( V_2 , V_59 ) ;
}
int F_117 ( struct V_1 * V_2 )
{
unsigned long V_45 ;
T_1 V_13 ;
F_83 ( & V_2 -> V_154 , V_45 ) ;
if ( V_2 -> V_3 -> V_4 &&
( V_2 -> V_3 -> V_4 -> V_9 & V_51 ) ) {
V_13 = V_2 -> V_7 ;
F_14 ( V_2 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
F_12 ( V_2 , true ) ;
F_84 ( & V_2 -> V_154 , V_45 ) ;
return 0 ;
}
int F_118 ( struct V_1 * V_2 )
{
unsigned long V_45 ;
T_1 V_13 ;
F_83 ( & V_2 -> V_154 , V_45 ) ;
if ( V_2 -> V_3 -> V_4 &&
( V_2 -> V_3 -> V_4 -> V_9 & V_51 ) ) {
V_13 = V_2 -> V_7 ;
F_15 ( V_2 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
F_12 ( V_2 , false ) ;
F_84 ( & V_2 -> V_154 , V_45 ) ;
return 0 ;
}
int F_119 ( struct V_1 * V_2 , const char * V_5 )
{
int V_63 ;
unsigned long V_45 ;
if ( ! V_2 )
return - V_6 ;
F_83 ( & V_2 -> V_154 , V_45 ) ;
V_63 = F_62 ( V_2 , V_5 ) ;
F_84 ( & V_2 -> V_154 , V_45 ) ;
return V_63 ;
}
int F_120 ( struct V_1 * V_2 , const char * V_5 )
{
int V_63 ;
unsigned long V_45 ;
if ( ! V_2 )
return - V_6 ;
F_83 ( & V_2 -> V_154 , V_45 ) ;
V_63 = F_66 ( V_2 , V_5 ) ;
F_84 ( & V_2 -> V_154 , V_45 ) ;
return V_63 ;
}
int F_121 ( struct V_1 * V_2 , const char * V_5 )
{
int V_63 ;
unsigned long V_45 ;
if ( ! V_2 )
return - V_6 ;
F_83 ( & V_2 -> V_154 , V_45 ) ;
V_63 = F_69 ( V_2 , V_5 ) ;
F_84 ( & V_2 -> V_154 , V_45 ) ;
return V_63 ;
}
int F_122 ( const char * V_183 ,
int (* F_98)( struct V_1 * V_2 ,
void * V_102 ) ,
void * V_102 )
{
struct V_1 * V_113 ;
int V_63 = 0 ;
if ( ! V_183 || ! F_98 )
return - V_6 ;
F_26 ( L_55 ,
V_87 , V_183 ) ;
F_53 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_113 -> V_3 -> V_5 , V_183 ) ) {
F_26 ( L_56 ,
V_87 , V_113 -> V_5 ) ;
V_63 = (* F_98)( V_113 , V_102 ) ;
if ( V_63 )
break;
}
}
if ( V_63 )
F_26 ( L_57 ,
V_87 , V_63 ) ;
return V_63 ;
}
int F_123 ( struct V_1 * V_2 , T_2 V_184 )
{
int V_63 ;
unsigned long V_45 ;
if ( ! V_2 )
return - V_6 ;
if ( V_184 != V_151 &&
V_184 != V_136 &&
V_184 != V_50 )
return - V_6 ;
F_83 ( & V_2 -> V_154 , V_45 ) ;
if ( V_2 -> V_49 != V_116 ) {
V_63 = - V_6 ;
goto V_185;
}
V_2 -> V_159 = V_184 ;
V_63 = 0 ;
V_185:
F_84 ( & V_2 -> V_154 , V_45 ) ;
return V_63 ;
}
int F_124 ( struct V_1 * V_2 )
{
struct V_182 * V_131 ;
int V_63 = 0 ;
V_131 = F_113 ( V_2 ) ;
if ( V_131 )
V_63 = F_125 ( V_131 ) ;
return V_63 ;
}
int F_126 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_6 ;
if ( V_2 -> V_49 != V_116 ) {
F_48 ( L_58 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
V_2 -> V_45 |= V_158 ;
return 0 ;
}
int F_127 ( struct V_1 * V_2 , int V_186 , int V_187 )
{
int V_188 ;
F_128 () ;
if ( ! V_2 || ! V_2 -> V_41 || ! V_2 -> V_90 || V_186 < 0 ||
V_186 >= V_2 -> V_41 -> V_43 )
return - V_6 ;
for ( V_188 = 0 ; V_2 -> V_90 [ V_188 ] . V_91 >= 0 ; V_188 ++ )
;
if ( V_187 >= V_188 )
return - V_6 ;
if ( ! V_2 -> V_41 -> V_189 ) {
V_2 -> V_41 -> V_189 = F_129 ( sizeof( int ) * V_2 -> V_41 -> V_43 ,
V_190 ) ;
if ( ! V_2 -> V_41 -> V_189 )
return - V_191 ;
}
V_2 -> V_41 -> V_189 [ V_186 ] = V_187 ;
return 0 ;
}
