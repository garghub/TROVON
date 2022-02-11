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
static int F_12 ( struct V_1 * V_2 , T_1 * V_13 )
{
if ( ! V_2 -> V_3 -> V_4 ||
! ( ( V_2 -> V_3 -> V_4 -> V_9 & V_35 ) ||
( V_2 -> V_3 -> V_4 -> V_36 & V_37 ) ||
( V_2 -> V_3 -> V_4 -> V_36 & V_38 ) ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_18 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_2 -> V_3 -> V_4 -> V_9 & V_35 )
* V_13 |= 0x1 << V_2 -> V_3 -> V_4 -> V_18 -> V_39 ;
if ( V_2 -> V_3 -> V_4 -> V_36 & V_37 )
F_8 ( V_2 , V_40 , V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_36 & V_38 )
F_6 ( V_2 , V_40 , V_13 ) ;
V_2 -> V_11 |= V_41 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 * V_13 )
{
if ( ! V_2 -> V_3 -> V_4 ||
! ( ( V_2 -> V_3 -> V_4 -> V_9 & V_35 ) ||
( V_2 -> V_3 -> V_4 -> V_36 & V_37 ) ||
( V_2 -> V_3 -> V_4 -> V_36 & V_38 ) ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_18 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_2 -> V_3 -> V_4 -> V_9 & V_35 )
* V_13 &= ~ ( 0x1 << V_2 -> V_3 -> V_4 -> V_18 -> V_39 ) ;
if ( V_2 -> V_3 -> V_4 -> V_36 & V_37 )
F_8 ( V_2 , V_42 , V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_36 & V_38 )
F_6 ( V_2 , V_40 , V_13 ) ;
V_2 -> V_11 &= ~ V_41 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_1 * V_43 )
{
if ( ! V_2 -> V_44 )
return - V_6 ;
if ( V_2 -> V_44 -> V_45 && V_2 -> V_44 -> V_45 -> V_46 & V_47 )
return 0 ;
return F_15 ( V_2 -> V_44 -> V_45 , V_43 -> V_44 -> V_45 ) ;
}
static int F_16 ( struct V_1 * V_2 , struct V_1 * V_43 )
{
if ( ! V_2 -> V_44 )
return - V_6 ;
if ( V_2 -> V_44 -> V_45 && V_2 -> V_44 -> V_45 -> V_46 & V_47 )
return 0 ;
return F_17 ( V_2 -> V_44 -> V_45 , V_43 -> V_44 -> V_45 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_48 = 0 ;
if ( ! V_2 -> V_49 )
return 0 ;
V_2 -> V_44 = F_19 ( V_2 -> V_49 ) ;
if ( ! V_2 -> V_44 ) {
F_20 ( L_4 ,
V_2 -> V_5 , V_2 -> V_49 ) ;
return - V_6 ;
}
if ( ! V_2 -> V_44 -> V_45 )
F_20 ( L_5 ,
V_2 -> V_49 , V_2 -> V_44 -> V_5 ) ;
return V_48 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
int V_52 ;
int V_48 = 0 ;
if ( V_2 -> V_53 == 0 )
return 0 ;
for ( V_52 = 0 ; V_52 < V_2 -> V_53 ; V_52 ++ ) {
struct V_54 * V_55 = V_2 -> V_56 [ V_52 ] ;
if ( ! V_55 -> V_50 )
continue;
V_51 = F_19 ( V_55 -> V_50 ) ;
if ( ! V_51 ) {
F_20 ( L_6 ,
V_2 -> V_5 , V_55 -> V_50 ) ;
V_48 = - V_6 ;
}
V_55 -> V_44 = V_51 ;
}
return V_48 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
struct V_50 * V_51 ;
int V_52 ;
int V_48 = 0 ;
for ( V_52 = V_2 -> V_59 , V_58 = V_2 -> V_60 ; V_52 > 0 ; V_52 -- , V_58 ++ ) {
V_51 = F_19 ( V_58 -> V_50 ) ;
if ( ! V_51 ) {
F_20 ( L_7 ,
V_2 -> V_5 , V_58 -> V_50 ) ;
V_48 = - V_6 ;
}
V_58 -> V_44 = V_51 ;
}
return V_48 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_52 ;
F_24 ( L_8 , V_2 -> V_5 ) ;
if ( V_2 -> V_44 )
F_25 ( V_2 -> V_44 ) ;
if ( V_2 -> V_53 > 0 ) {
for ( V_52 = 0 ; V_52 < V_2 -> V_53 ; V_52 ++ ) {
struct V_54 * V_55 = V_2 -> V_56 [ V_52 ] ;
struct V_50 * V_51 = V_55 -> V_44 ;
if ( V_51 && ( V_55 -> V_46 & V_61 ) )
F_25 ( V_51 ) ;
}
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_52 ;
F_24 ( L_9 , V_2 -> V_5 ) ;
if ( V_2 -> V_44 )
F_27 ( V_2 -> V_44 ) ;
if ( V_2 -> V_53 > 0 ) {
for ( V_52 = 0 ; V_52 < V_2 -> V_53 ; V_52 ++ ) {
struct V_54 * V_55 = V_2 -> V_56 [ V_52 ] ;
struct V_50 * V_51 = V_55 -> V_44 ;
if ( V_51 && ( V_55 -> V_46 & V_61 ) )
F_27 ( V_51 ) ;
}
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
int V_52 ;
F_24 ( L_10 , V_2 -> V_5 ) ;
for ( V_52 = V_2 -> V_59 , V_58 = V_2 -> V_60 ; V_52 > 0 ; V_52 -- , V_58 ++ )
if ( V_58 -> V_44 ) {
F_24 ( L_11 , V_58 -> V_62 ,
V_58 -> V_44 -> V_5 ) ;
F_25 ( V_58 -> V_44 ) ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
int V_52 ;
F_24 ( L_12 , V_2 -> V_5 ) ;
for ( V_52 = V_2 -> V_59 , V_58 = V_2 -> V_60 ; V_52 > 0 ; V_52 -- , V_58 ++ )
if ( V_58 -> V_44 ) {
F_24 ( L_13 , V_58 -> V_62 ,
V_58 -> V_44 -> V_5 ) ;
F_27 ( V_58 -> V_44 ) ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
if ( F_31 () || F_32 () )
return;
if ( ! V_2 -> V_45 || ! V_2 -> V_63 . V_64 . V_65 )
return;
F_24 ( L_14 ,
V_2 -> V_5 , V_2 -> V_63 . V_64 . V_65 ) ;
F_33 ( V_2 -> V_63 . V_64 . V_65 ,
V_2 -> V_45 -> V_66 ,
V_2 -> V_45 -> V_67 ,
V_2 -> V_45 -> V_68 ,
V_2 -> V_63 . V_64 . V_69 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
if ( F_31 () || F_32 () )
return;
if ( ! V_2 -> V_45 || ! V_2 -> V_63 . V_64 . V_65 )
return;
F_24 ( L_15 , V_2 -> V_5 ) ;
F_35 ( V_2 -> V_45 -> V_66 ,
V_2 -> V_45 -> V_67 ,
V_2 -> V_45 -> V_68 ,
V_2 -> V_63 . V_64 . V_69 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_70 * V_71 ;
int V_52 = 0 ;
if ( ! V_2 || ! V_2 -> V_72 )
return 0 ;
do {
V_71 = & V_2 -> V_72 [ V_52 ++ ] ;
} while ( V_71 -> V_73 != - 1 );
return V_52 - 1 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_74 * V_75 ;
int V_52 = 0 ;
if ( ! V_2 || ! V_2 -> V_76 )
return 0 ;
do {
V_75 = & V_2 -> V_76 [ V_52 ++ ] ;
} while ( V_75 -> V_77 != - 1 );
return V_52 - 1 ;
}
static int F_38 ( struct V_54 * V_55 )
{
struct V_78 * V_79 ;
int V_52 = 0 ;
if ( ! V_55 || ! V_55 -> V_80 )
return 0 ;
do {
V_79 = & V_55 -> V_80 [ V_52 ++ ] ;
} while ( V_79 -> V_81 != V_79 -> V_82 );
return V_52 - 1 ;
}
static int T_3 F_39 ( struct V_1 * V_2 )
{
int V_52 ;
int V_83 = 0 ;
if ( ! V_2 || V_2 -> V_53 == 0 )
return - V_6 ;
for ( V_52 = 0 ; V_52 < V_2 -> V_53 ; V_52 ++ ) {
struct V_54 * V_55 = V_2 -> V_56 [ V_52 ] ;
if ( V_55 -> V_84 & V_85 ) {
V_83 = 1 ;
break;
}
}
if ( V_83 )
F_24 ( L_16 ,
V_2 -> V_5 , V_52 ) ;
else
F_24 ( L_17 ,
V_2 -> V_5 ) ;
return ( V_83 ) ? V_52 : - V_6 ;
}
static void T_4 * T_3 F_40 ( struct V_1 * V_2 , T_2 V_86 )
{
struct V_54 * V_55 ;
struct V_78 * V_79 ;
int V_52 = 0 , V_83 = 0 ;
void T_4 * va_start ;
if ( ! V_2 || V_2 -> V_53 == 0 )
return NULL ;
V_55 = V_2 -> V_56 [ V_86 ] ;
if ( ! V_55 -> V_80 )
return NULL ;
do {
V_79 = & V_55 -> V_80 [ V_52 ++ ] ;
if ( V_79 -> V_46 & V_87 )
V_83 = 1 ;
} while ( ! V_83 && V_79 -> V_81 != V_79 -> V_82 );
if ( V_83 ) {
va_start = F_41 ( V_79 -> V_81 , V_79 -> V_82 - V_79 -> V_81 ) ;
if ( ! va_start ) {
F_42 ( L_18 , V_2 -> V_5 ) ;
return NULL ;
}
F_24 ( L_19 ,
V_2 -> V_5 , va_start ) ;
} else {
F_24 ( L_20 ,
V_2 -> V_5 ) ;
}
return ( V_83 ) ? va_start : NULL ;
}
static void F_43 ( struct V_1 * V_2 )
{
T_2 V_20 , V_88 ;
T_1 V_13 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
V_13 = V_2 -> V_7 ;
V_88 = V_2 -> V_3 -> V_4 -> V_9 ;
if ( V_88 & V_23 ) {
V_20 = ( V_2 -> V_46 & V_89 ) ?
V_90 : V_42 ;
F_8 ( V_2 , V_20 , & V_13 ) ;
}
if ( V_88 & V_17 ) {
if ( V_2 -> V_46 & V_91 ) {
V_20 = V_90 ;
} else {
if ( V_88 & V_35 )
F_12 ( V_2 , & V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_36 & V_38 )
V_20 = V_40 ;
else
V_20 = V_42 ;
}
F_6 ( V_2 , V_20 , & V_13 ) ;
}
if ( ( V_2 -> V_46 & V_92 ) &&
( V_88 & V_27 ) )
F_9 ( V_2 , V_2 -> V_3 -> V_4 -> V_24 , & V_13 ) ;
if ( ( V_88 & V_23 ) && ! ( V_2 -> V_46 & V_89 ) )
F_12 ( V_2 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
if ( V_88 & V_34 ) {
V_20 = ( V_2 -> V_46 & V_93 ) ?
0 : 1 ;
F_11 ( V_2 , V_20 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
}
static void F_44 ( struct V_1 * V_2 )
{
T_2 V_20 , V_88 ;
T_1 V_13 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
V_13 = V_2 -> V_7 ;
V_88 = V_2 -> V_3 -> V_4 -> V_9 ;
if ( V_88 & V_23 ) {
V_20 = ( V_2 -> V_46 & V_89 ) ?
V_94 : V_42 ;
F_8 ( V_2 , V_20 , & V_13 ) ;
}
if ( V_88 & V_17 ) {
if ( V_2 -> V_46 & V_91 ) {
V_20 = V_94 ;
} else {
if ( V_88 & V_35 )
F_12 ( V_2 , & V_13 ) ;
if ( V_2 -> V_3 -> V_4 -> V_36 & V_38 )
V_20 = V_40 ;
else
V_20 = V_42 ;
}
F_6 ( V_2 , V_20 , & V_13 ) ;
}
if ( ( V_88 & V_23 ) && ! ( V_2 -> V_46 & V_89 ) )
F_12 ( V_2 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
T_1 V_13 ;
T_2 V_88 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
V_13 = V_2 -> V_7 ;
V_88 = V_2 -> V_3 -> V_4 -> V_9 ;
if ( V_88 & V_23 )
F_8 ( V_2 , V_94 , & V_13 ) ;
if ( V_88 & V_17 )
F_6 ( V_2 , V_94 , & V_13 ) ;
if ( V_88 & V_34 )
F_11 ( V_2 , 1 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
static struct V_1 * F_46 ( const char * V_5 )
{
struct V_1 * V_2 , * V_95 ;
V_2 = NULL ;
F_47 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_5 , V_95 -> V_5 ) ) {
V_2 = V_95 ;
break;
}
}
return V_2 ;
}
static int F_48 ( struct V_1 * V_2 )
{
if ( F_31 () || F_32 () )
return 0 ;
if ( ! V_2 -> V_96 ) {
F_20 ( L_21 , V_2 -> V_5 ) ;
return - V_6 ;
}
V_2 -> V_45 = F_49 ( V_2 -> V_96 ) ;
if ( ! V_2 -> V_45 ) {
F_20 ( L_22 ,
V_2 -> V_5 , V_2 -> V_96 ) ;
return - V_6 ;
}
F_24 ( L_23 ,
V_2 -> V_5 , V_2 -> V_96 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , void * V_97 )
{
int V_48 = 0 ;
if ( V_2 -> V_98 != V_99 )
return 0 ;
F_24 ( L_24 , V_2 -> V_5 ) ;
V_48 |= F_18 ( V_2 ) ;
V_48 |= F_21 ( V_2 ) ;
V_48 |= F_22 ( V_2 ) ;
V_48 |= F_48 ( V_2 ) ;
if ( ! V_48 )
V_2 -> V_98 = V_100 ;
else
F_20 ( L_25 , V_2 -> V_5 ) ;
return V_48 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_54 * V_55 ;
int V_48 ;
if ( ! V_2 )
return - V_6 ;
if ( V_2 -> V_11 & V_101 )
return 0 ;
V_55 = V_2 -> V_56 [ V_2 -> V_102 ] ;
if ( V_2 -> V_46 & V_103 )
return 0 ;
if ( F_31 () || F_32 () ) {
V_48 = F_52 ( V_2 -> V_63 . V_104 . V_105 ,
V_2 -> V_63 . V_104 . V_106 ,
V_2 -> V_63 . V_104 . V_107 ) ;
} else if ( F_53 () ) {
if ( ! V_2 -> V_45 )
return - V_6 ;
V_48 = F_54 ( V_2 -> V_45 -> V_66 ,
V_2 -> V_45 -> V_67 ,
V_2 -> V_45 -> V_68 ,
V_2 -> V_63 . V_64 . V_69 ) ;
} else {
F_55 () ;
} ;
return V_48 ;
}
static int F_56 ( struct V_1 * V_2 )
{
if ( F_31 () || F_32 () )
return 0 ;
if ( ! V_2 )
return - V_6 ;
if ( V_2 -> V_11 & V_101 )
return 0 ;
if ( V_2 -> V_46 & V_103 )
return 0 ;
return F_57 ( V_2 -> V_45 -> V_66 ,
V_2 -> V_45 -> V_67 ,
V_2 -> V_45 -> V_68 ,
V_2 -> V_63 . V_64 . V_69 ) ;
}
static T_2 F_58 ( struct V_1 * V_2 , const char * V_5 ,
struct V_108 * V_109 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_2 -> V_110 ; V_52 ++ ) {
const char * V_111 = V_2 -> V_112 [ V_52 ] . V_5 ;
if ( ! strcmp ( V_111 , V_5 ) ) {
V_109 -> V_113 = V_2 -> V_112 [ V_52 ] . V_113 ;
V_109 -> V_114 = V_2 -> V_112 [ V_52 ] . V_114 ;
F_24 ( L_26 ,
V_2 -> V_5 , V_115 , V_111 , V_109 -> V_113 ,
V_109 -> V_114 ) ;
return 0 ;
}
}
return - V_116 ;
}
static int F_59 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_108 V_109 ;
T_2 V_48 ;
if ( ! V_2 )
return - V_6 ;
V_48 = F_58 ( V_2 , V_5 , & V_109 ) ;
if ( F_60 ( V_48 ) )
return V_48 ;
if ( F_31 () || F_32 () )
return F_61 ( V_2 -> V_63 . V_104 . V_105 ,
V_109 . V_113 ) ;
else if ( F_53 () )
return F_62 ( V_109 . V_113 ,
V_2 -> V_45 -> V_117 . V_118 -> V_66 ,
V_2 -> V_45 -> V_117 . V_118 -> V_119 ,
V_2 -> V_63 . V_64 . V_120 ) ;
else
return - V_6 ;
}
static int F_63 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_108 V_109 ;
int V_48 ;
if ( ! V_2 )
return - V_6 ;
V_48 = F_58 ( V_2 , V_5 , & V_109 ) ;
if ( F_60 ( V_48 ) )
return V_48 ;
if ( F_31 () || F_32 () ) {
V_48 = F_64 ( V_2 -> V_63 . V_104 . V_105 ,
V_109 . V_113 ,
V_109 . V_114 ) ;
} else if ( F_53 () ) {
if ( V_109 . V_114 )
F_42 ( L_27 ,
V_2 -> V_5 , V_5 ) ;
V_48 = F_65 ( V_109 . V_113 ,
V_2 -> V_45 -> V_117 . V_118 -> V_66 ,
V_2 -> V_45 -> V_117 . V_118 -> V_119 ,
V_2 -> V_63 . V_64 . V_120 ) ;
} else {
return - V_6 ;
}
if ( V_48 == - V_121 )
F_20 ( L_28 , V_2 -> V_5 ) ;
return V_48 ;
}
static int F_66 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_108 V_109 ;
T_2 V_48 ;
if ( ! V_2 )
return - V_6 ;
V_48 = F_58 ( V_2 , V_5 , & V_109 ) ;
if ( F_60 ( V_48 ) )
return V_48 ;
if ( F_31 () || F_32 () ) {
return F_67 ( V_2 -> V_63 . V_104 . V_105 ,
V_109 . V_114 ) ;
} else if ( F_53 () ) {
return F_68 ( V_109 . V_113 ,
V_2 -> V_45 -> V_117 . V_118 -> V_66 ,
V_2 -> V_45 -> V_117 . V_118 -> V_119 ,
V_2 -> V_63 . V_64 . V_120 ) ;
} else {
return - V_6 ;
}
}
static int F_69 ( struct V_1 * V_2 )
{
T_1 V_13 ;
int V_51 = 0 ;
int V_48 = 0 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_29 ) )
return - V_6 ;
if ( V_2 -> V_98 != V_122 ) {
F_20 ( L_29
L_30 , V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_2 -> V_46 & V_123 )
F_28 ( V_2 ) ;
F_24 ( L_31 , V_2 -> V_5 ) ;
V_13 = V_2 -> V_7 ;
V_48 = F_10 ( V_2 , & V_13 ) ;
if ( V_48 )
goto V_124;
F_4 ( V_13 , V_2 ) ;
if ( V_2 -> V_3 -> V_4 -> V_9 & V_125 )
F_70 ( ( F_3 ( V_2 ,
V_2 -> V_3 -> V_4 -> V_126 )
& V_127 ) ,
V_128 , V_51 ) ;
else if ( V_2 -> V_3 -> V_4 -> V_9 & V_129 )
F_70 ( ! ( F_3 ( V_2 ,
V_2 -> V_3 -> V_4 -> V_8 )
& V_130 ) ,
V_128 , V_51 ) ;
if ( V_51 == V_128 )
F_20 ( L_32 ,
V_2 -> V_5 , V_128 ) ;
else
F_24 ( L_33 , V_2 -> V_5 , V_51 ) ;
V_48 = ( V_51 == V_128 ) ? - V_131 : 0 ;
V_124:
if ( V_2 -> V_46 & V_123 )
F_29 ( V_2 ) ;
return V_48 ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_48 ;
F_24 ( L_34 , V_2 -> V_5 ) ;
V_48 = ( V_2 -> V_3 -> V_132 ) ? V_2 -> V_3 -> V_132 ( V_2 ) : F_69 ( V_2 ) ;
return V_48 ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_133 ;
int V_134 = 0 ;
F_24 ( L_35 , V_2 -> V_5 ) ;
if ( V_2 -> V_98 != V_135 &&
V_2 -> V_98 != V_136 &&
V_2 -> V_98 != V_137 ) {
F_2 ( 1 , L_36
L_37 , V_2 -> V_5 ) ;
return - V_6 ;
}
if ( ( V_2 -> V_98 == V_135 ||
V_2 -> V_98 == V_137 ) && V_2 -> V_110 == 1 )
F_63 ( V_2 , V_2 -> V_112 [ 0 ] . V_5 ) ;
if ( V_2 -> V_138 && ( ! V_2 -> V_138 -> V_139 ||
( ( V_2 -> V_98 == V_136 ) &&
V_2 -> V_138 -> V_140 ) ) )
F_73 ( V_2 -> V_138 , V_122 ) ;
F_14 ( V_2 , V_141 ) ;
if ( V_2 -> V_45 ) {
V_134 = F_74 ( V_2 -> V_45 ) ;
V_133 = F_75 ( V_2 -> V_45 , V_2 ) ;
if ( V_133 ) {
F_2 ( 1 , L_38 ,
V_2 -> V_5 , V_2 -> V_45 -> V_5 , V_133 ) ;
return V_133 ;
}
}
F_23 ( V_2 ) ;
F_30 ( V_2 ) ;
V_133 = F_51 ( V_2 ) ;
if ( ! V_133 ) {
if ( V_2 -> V_45 && V_134 )
F_76 ( V_2 -> V_45 ) ;
V_2 -> V_98 = V_122 ;
if ( V_2 -> V_3 -> V_4 ) {
if ( ! ( V_2 -> V_11 & V_12 ) )
F_1 ( V_2 ) ;
F_43 ( V_2 ) ;
}
} else {
F_26 ( V_2 ) ;
F_24 ( L_39 ,
V_2 -> V_5 , V_133 ) ;
if ( V_2 -> V_45 )
F_77 ( V_2 -> V_45 , V_2 ) ;
}
return V_133 ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_48 ;
F_24 ( L_40 , V_2 -> V_5 ) ;
if ( V_2 -> V_98 != V_122 ) {
F_2 ( 1 , L_41
L_30 , V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_2 -> V_3 -> V_4 )
F_44 ( V_2 ) ;
F_16 ( V_2 , V_141 ) ;
F_34 ( V_2 ) ;
V_48 = F_56 ( V_2 ) ;
if ( V_48 )
F_79 ( L_42 ,
V_2 -> V_5 ) ;
F_26 ( V_2 ) ;
if ( V_2 -> V_45 )
F_77 ( V_2 -> V_45 , V_2 ) ;
if ( V_2 -> V_138 && V_2 -> V_138 -> V_140 )
F_73 ( V_2 -> V_138 , V_136 ) ;
V_2 -> V_98 = V_136 ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 , T_2 V_31 )
{
T_1 V_13 ;
int V_142 = 0 ;
unsigned long V_46 ;
if ( ! V_2 || V_2 -> V_98 != V_122 )
return - V_6 ;
F_81 ( & V_2 -> V_143 , V_46 ) ;
V_13 = V_2 -> V_7 ;
V_142 = F_11 ( V_2 , V_31 , & V_13 ) ;
if ( ! V_142 )
F_4 ( V_13 , V_2 ) ;
F_82 ( & V_2 -> V_143 , V_46 ) ;
return V_142 ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_48 ;
T_2 V_144 ;
if ( V_2 -> V_98 != V_136 &&
V_2 -> V_98 != V_122 ) {
F_2 ( 1 , L_43
L_44 , V_2 -> V_5 ) ;
return - V_6 ;
}
F_24 ( L_45 , V_2 -> V_5 ) ;
if ( V_2 -> V_3 -> V_145 ) {
V_144 = V_2 -> V_98 ;
if ( V_2 -> V_98 == V_136 )
F_72 ( V_2 ) ;
V_48 = V_2 -> V_3 -> V_145 ( V_2 ) ;
if ( V_48 ) {
if ( V_144 == V_136 )
F_78 ( V_2 ) ;
return V_48 ;
}
}
if ( V_2 -> V_3 -> V_4 ) {
if ( V_2 -> V_98 == V_136 )
F_72 ( V_2 ) ;
F_45 ( V_2 ) ;
}
if ( V_2 -> V_98 == V_122 ) {
F_16 ( V_2 , V_141 ) ;
F_34 ( V_2 ) ;
V_48 = F_56 ( V_2 ) ;
if ( V_48 )
F_79 ( L_42 ,
V_2 -> V_5 ) ;
F_26 ( V_2 ) ;
if ( V_2 -> V_45 )
F_77 ( V_2 -> V_45 , V_2 ) ;
}
if ( V_2 -> V_110 == 1 )
F_59 ( V_2 , V_2 -> V_112 [ 0 ] . V_5 ) ;
if ( V_2 -> V_138 )
F_73 ( V_2 -> V_138 , V_137 ) ;
V_2 -> V_98 = V_137 ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , void * V_97 )
{
int V_52 , V_133 ;
T_2 V_146 ;
if ( V_2 -> V_98 != V_100 )
return 0 ;
if ( V_2 -> V_53 > 0 ) {
for ( V_52 = 0 ; V_52 < V_2 -> V_53 ; V_52 ++ ) {
struct V_54 * V_55 = V_2 -> V_56 [ V_52 ] ;
struct V_50 * V_51 = V_55 -> V_44 ;
if ( ! V_51 )
continue;
if ( V_55 -> V_46 & V_61 ) {
} else {
F_25 ( V_51 ) ;
}
}
}
V_2 -> V_98 = V_135 ;
if ( ( V_2 -> V_46 & V_147 ) && V_2 -> V_110 == 1 )
return 0 ;
V_133 = F_72 ( V_2 ) ;
if ( V_133 ) {
F_20 ( L_46 ,
V_2 -> V_5 , V_2 -> V_98 ) ;
return 0 ;
}
if ( ! ( V_2 -> V_46 & V_147 ) ) {
F_71 ( V_2 ) ;
if ( V_2 -> V_3 -> V_4 ) {
F_1 ( V_2 ) ;
F_43 ( V_2 ) ;
}
}
V_146 = V_2 -> V_148 ;
if ( V_146 == V_149 )
V_146 = V_122 ;
if ( ( V_2 -> V_46 & V_150 ) &&
( V_146 == V_136 ) )
V_146 = V_122 ;
if ( V_146 == V_136 )
F_78 ( V_2 ) ;
else if ( V_146 == V_137 )
F_83 ( V_2 ) ;
else if ( V_146 != V_122 )
F_2 ( 1 , L_47 ,
V_2 -> V_5 , V_146 ) ;
return 0 ;
}
static int T_3 F_85 ( struct V_1 * V_2 )
{
int V_151 ;
if ( ! V_2 || ! V_2 -> V_5 || ! V_2 -> V_3 || ! V_2 -> V_3 -> V_5 ||
( V_2 -> V_98 != V_149 ) )
return - V_6 ;
F_24 ( L_48 , V_2 -> V_5 ) ;
if ( F_46 ( V_2 -> V_5 ) )
return - V_152 ;
V_151 = F_39 ( V_2 ) ;
if ( ! F_60 ( V_151 ) )
V_2 -> V_102 = V_151 ;
else
V_2 -> V_11 |= V_101 ;
F_86 ( & V_2 -> V_153 , & V_154 ) ;
F_87 ( & V_2 -> V_143 ) ;
V_2 -> V_98 = V_99 ;
if ( ! strcmp ( V_2 -> V_5 , V_155 ) )
V_141 = V_2 ;
return 0 ;
}
T_1 F_3 ( struct V_1 * V_2 , T_5 V_156 )
{
if ( V_2 -> V_46 & V_157 )
return F_88 ( V_2 -> V_158 + V_156 ) ;
else
return F_89 ( V_2 -> V_158 + V_156 ) ;
}
void F_5 ( T_1 V_13 , struct V_1 * V_2 , T_5 V_156 )
{
if ( V_2 -> V_46 & V_157 )
F_90 ( V_13 , V_2 -> V_158 + V_156 ) ;
else
F_91 ( V_13 , V_2 -> V_158 + V_156 ) ;
}
int F_92 ( struct V_1 * V_2 )
{
T_1 V_13 ;
int V_48 ;
if ( ! V_2 || ! ( V_2 -> V_7 ) )
return - V_6 ;
V_13 = V_2 -> V_7 ;
V_48 = F_10 ( V_2 , & V_13 ) ;
if ( V_48 )
goto error;
F_4 ( V_13 , V_2 ) ;
error:
return V_48 ;
}
int F_93 ( struct V_1 * V_2 , T_2 V_20 )
{
T_1 V_13 ;
int V_142 = 0 ;
if ( ! V_2 )
return - V_6 ;
V_13 = V_2 -> V_7 ;
V_142 = F_8 ( V_2 , V_20 , & V_13 ) ;
if ( ! V_142 )
F_4 ( V_13 , V_2 ) ;
return V_142 ;
}
struct V_1 * F_94 ( const char * V_5 )
{
struct V_1 * V_2 ;
if ( ! V_5 )
return NULL ;
V_2 = F_46 ( V_5 ) ;
return V_2 ;
}
int F_95 ( int (* F_96)( struct V_1 * V_2 , void * V_97 ) ,
void * V_97 )
{
struct V_1 * V_95 ;
int V_48 = 0 ;
if ( ! F_96 )
return - V_6 ;
F_47 (temp_oh, &omap_hwmod_list, node) {
V_48 = (* F_96)( V_95 , V_97 ) ;
if ( V_48 )
break;
}
return V_48 ;
}
int T_3 F_97 ( struct V_1 * * V_159 )
{
int V_133 , V_52 ;
if ( ! V_159 )
return 0 ;
V_52 = 0 ;
do {
V_133 = F_85 ( V_159 [ V_52 ] ) ;
F_2 ( V_133 , L_49 , V_159 [ V_52 ] -> V_5 ,
V_133 ) ;
} while ( V_159 [ ++ V_52 ] );
return 0 ;
}
static int T_3 F_98 ( struct V_1 * V_2 , void * V_97 )
{
if ( V_2 -> V_98 != V_99 )
return 0 ;
if ( V_2 -> V_11 & V_101 )
return 0 ;
V_2 -> V_158 = F_40 ( V_2 , V_2 -> V_102 ) ;
return 0 ;
}
int T_3 F_99 ( const char * V_160 )
{
struct V_1 * V_2 ;
int V_133 ;
F_24 ( L_50 , V_160 , V_115 ) ;
if ( ! V_141 ) {
F_42 ( L_51 ,
V_160 , V_155 ) ;
return - V_6 ;
}
V_2 = F_46 ( V_160 ) ;
if ( ! V_2 ) {
F_2 ( 1 , L_52 , V_160 ) ;
return - V_6 ;
}
if ( V_141 -> V_98 == V_99 && V_2 != V_141 )
F_99 ( V_155 ) ;
V_133 = F_98 ( V_2 , NULL ) ;
if ( F_60 ( V_133 ) ) {
F_2 ( 1 , L_53 , V_160 ) ;
return - V_6 ;
}
V_133 = F_50 ( V_2 , NULL ) ;
if ( F_60 ( V_133 ) ) {
F_2 ( 1 , L_54 , V_160 ) ;
return - V_6 ;
}
F_84 ( V_2 , NULL ) ;
return 0 ;
}
static int T_3 F_100 ( void )
{
int V_133 ;
if ( ! V_141 ) {
F_42 ( L_55 ,
V_115 , V_155 ) ;
return - V_6 ;
}
V_133 = F_95 ( F_98 , NULL ) ;
V_133 = F_95 ( F_50 , NULL ) ;
F_2 ( F_60 ( V_133 ) ,
L_56 , V_115 ) ;
F_95 ( F_84 , NULL ) ;
return 0 ;
}
int F_101 ( struct V_1 * V_2 )
{
int V_133 ;
unsigned long V_46 ;
if ( ! V_2 )
return - V_6 ;
F_81 ( & V_2 -> V_143 , V_46 ) ;
V_133 = F_72 ( V_2 ) ;
F_82 ( & V_2 -> V_143 , V_46 ) ;
return V_133 ;
}
int F_102 ( struct V_1 * V_2 )
{
unsigned long V_46 ;
if ( ! V_2 )
return - V_6 ;
F_81 ( & V_2 -> V_143 , V_46 ) ;
F_78 ( V_2 ) ;
F_82 ( & V_2 -> V_143 , V_46 ) ;
return 0 ;
}
int F_103 ( struct V_1 * V_2 )
{
unsigned long V_46 ;
if ( ! V_2 )
return - V_6 ;
F_81 ( & V_2 -> V_143 , V_46 ) ;
F_83 ( V_2 ) ;
F_82 ( & V_2 -> V_143 , V_46 ) ;
return 0 ;
}
int F_104 ( struct V_1 * V_2 )
{
unsigned long V_46 ;
F_81 ( & V_2 -> V_143 , V_46 ) ;
F_23 ( V_2 ) ;
F_82 ( & V_2 -> V_143 , V_46 ) ;
return 0 ;
}
int F_105 ( struct V_1 * V_2 )
{
unsigned long V_46 ;
F_81 ( & V_2 -> V_143 , V_46 ) ;
F_26 ( V_2 ) ;
F_82 ( & V_2 -> V_143 , V_46 ) ;
return 0 ;
}
void F_106 ( struct V_1 * V_2 )
{
F_107 ( ! V_2 ) ;
if ( ! V_2 -> V_3 -> V_4 || ! V_2 -> V_3 -> V_4 -> V_9 ) {
F_2 ( 1 , L_57
L_58 , V_2 -> V_5 ) ;
return;
}
F_3 ( V_2 , V_2 -> V_3 -> V_4 -> V_8 ) ;
}
int F_108 ( struct V_1 * V_2 )
{
int V_133 ;
unsigned long V_46 ;
if ( ! V_2 )
return - V_6 ;
F_81 ( & V_2 -> V_143 , V_46 ) ;
V_133 = F_71 ( V_2 ) ;
F_82 ( & V_2 -> V_143 , V_46 ) ;
return V_133 ;
}
int F_109 ( struct V_1 * V_2 )
{
int V_48 , V_52 ;
V_48 = F_36 ( V_2 ) + F_37 ( V_2 ) ;
for ( V_52 = 0 ; V_52 < V_2 -> V_53 ; V_52 ++ )
V_48 += F_38 ( V_2 -> V_56 [ V_52 ] ) ;
return V_48 ;
}
int F_110 ( struct V_1 * V_2 , struct V_161 * V_162 )
{
int V_52 , V_163 , V_164 , V_165 ;
int V_133 = 0 ;
V_164 = F_36 ( V_2 ) ;
for ( V_52 = 0 ; V_52 < V_164 ; V_52 ++ ) {
( V_162 + V_133 ) -> V_5 = ( V_2 -> V_72 + V_52 ) -> V_5 ;
( V_162 + V_133 ) -> V_166 = ( V_2 -> V_72 + V_52 ) -> V_73 ;
( V_162 + V_133 ) -> V_167 = ( V_2 -> V_72 + V_52 ) -> V_73 ;
( V_162 + V_133 ) -> V_46 = V_168 ;
V_133 ++ ;
}
V_165 = F_37 ( V_2 ) ;
for ( V_52 = 0 ; V_52 < V_165 ; V_52 ++ ) {
( V_162 + V_133 ) -> V_5 = ( V_2 -> V_76 + V_52 ) -> V_5 ;
( V_162 + V_133 ) -> V_166 = ( V_2 -> V_76 + V_52 ) -> V_77 ;
( V_162 + V_133 ) -> V_167 = ( V_2 -> V_76 + V_52 ) -> V_77 ;
( V_162 + V_133 ) -> V_46 = V_169 ;
V_133 ++ ;
}
for ( V_52 = 0 ; V_52 < V_2 -> V_53 ; V_52 ++ ) {
struct V_54 * V_55 ;
int V_170 ;
V_55 = V_2 -> V_56 [ V_52 ] ;
V_170 = F_38 ( V_55 ) ;
for ( V_163 = 0 ; V_163 < V_170 ; V_163 ++ ) {
( V_162 + V_133 ) -> V_5 = ( V_55 -> V_80 + V_163 ) -> V_5 ;
( V_162 + V_133 ) -> V_166 = ( V_55 -> V_80 + V_163 ) -> V_81 ;
( V_162 + V_133 ) -> V_167 = ( V_55 -> V_80 + V_163 ) -> V_82 ;
( V_162 + V_133 ) -> V_46 = V_171 ;
V_133 ++ ;
}
}
return V_133 ;
}
struct V_172 * F_111 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_44 ) {
V_51 = V_2 -> V_44 ;
} else {
if ( V_2 -> V_11 & V_101 )
return NULL ;
V_51 = V_2 -> V_56 [ V_2 -> V_102 ] -> V_44 ;
}
if ( ! V_51 -> V_45 )
return NULL ;
return V_51 -> V_45 -> V_117 . V_118 ;
}
void T_4 * F_112 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_11 & V_101 )
return NULL ;
if ( V_2 -> V_98 == V_149 )
return NULL ;
return V_2 -> V_158 ;
}
int F_113 ( struct V_1 * V_2 ,
struct V_1 * V_43 )
{
return F_14 ( V_2 , V_43 ) ;
}
int F_114 ( struct V_1 * V_2 ,
struct V_1 * V_43 )
{
return F_16 ( V_2 , V_43 ) ;
}
int F_115 ( struct V_1 * V_2 )
{
unsigned long V_46 ;
T_1 V_13 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_35 ) )
return - V_6 ;
F_81 ( & V_2 -> V_143 , V_46 ) ;
V_13 = V_2 -> V_7 ;
F_12 ( V_2 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
F_82 ( & V_2 -> V_143 , V_46 ) ;
return 0 ;
}
int F_116 ( struct V_1 * V_2 )
{
unsigned long V_46 ;
T_1 V_13 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_35 ) )
return - V_6 ;
F_81 ( & V_2 -> V_143 , V_46 ) ;
V_13 = V_2 -> V_7 ;
F_13 ( V_2 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
F_82 ( & V_2 -> V_143 , V_46 ) ;
return 0 ;
}
int F_117 ( struct V_1 * V_2 , const char * V_5 )
{
int V_48 ;
unsigned long V_46 ;
if ( ! V_2 )
return - V_6 ;
F_81 ( & V_2 -> V_143 , V_46 ) ;
V_48 = F_59 ( V_2 , V_5 ) ;
F_82 ( & V_2 -> V_143 , V_46 ) ;
return V_48 ;
}
int F_118 ( struct V_1 * V_2 , const char * V_5 )
{
int V_48 ;
unsigned long V_46 ;
if ( ! V_2 )
return - V_6 ;
F_81 ( & V_2 -> V_143 , V_46 ) ;
V_48 = F_63 ( V_2 , V_5 ) ;
F_82 ( & V_2 -> V_143 , V_46 ) ;
return V_48 ;
}
int F_119 ( struct V_1 * V_2 , const char * V_5 )
{
int V_48 ;
unsigned long V_46 ;
if ( ! V_2 )
return - V_6 ;
F_81 ( & V_2 -> V_143 , V_46 ) ;
V_48 = F_66 ( V_2 , V_5 ) ;
F_82 ( & V_2 -> V_143 , V_46 ) ;
return V_48 ;
}
int F_120 ( const char * V_173 ,
int (* F_96)( struct V_1 * V_2 ,
void * V_84 ) ,
void * V_84 )
{
struct V_1 * V_95 ;
int V_48 = 0 ;
if ( ! V_173 || ! F_96 )
return - V_6 ;
F_24 ( L_59 ,
V_115 , V_173 ) ;
F_47 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_95 -> V_3 -> V_5 , V_173 ) ) {
F_24 ( L_60 ,
V_115 , V_95 -> V_5 ) ;
V_48 = (* F_96)( V_95 , V_84 ) ;
if ( V_48 )
break;
}
}
if ( V_48 )
F_24 ( L_61 ,
V_115 , V_48 ) ;
return V_48 ;
}
int F_121 ( struct V_1 * V_2 , T_2 V_174 )
{
int V_48 ;
unsigned long V_46 ;
if ( ! V_2 )
return - V_6 ;
if ( V_174 != V_137 &&
V_174 != V_122 &&
V_174 != V_136 )
return - V_6 ;
F_81 ( & V_2 -> V_143 , V_46 ) ;
if ( V_2 -> V_98 != V_99 ) {
V_48 = - V_6 ;
goto V_175;
}
V_2 -> V_148 = V_174 ;
V_48 = 0 ;
V_175:
F_82 ( & V_2 -> V_143 , V_46 ) ;
return V_48 ;
}
int F_122 ( struct V_1 * V_2 )
{
struct V_172 * V_117 ;
int V_48 = 0 ;
V_117 = F_111 ( V_2 ) ;
if ( V_117 )
V_48 = F_123 ( V_117 ) ;
return V_48 ;
}
int F_124 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_6 ;
if ( V_2 -> V_98 != V_99 ) {
F_42 ( L_62 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
V_2 -> V_46 |= V_147 ;
return 0 ;
}
