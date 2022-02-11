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
T_1 V_35 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( ( V_2 -> V_3 -> V_4 -> V_9 & V_36 ) ||
( V_2 -> V_3 -> V_4 -> V_37 & V_38 ) ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_18 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
V_35 = ( 0x1 << V_2 -> V_3 -> V_4 -> V_18 -> V_39 ) ;
* V_13 |= V_35 ;
if ( V_2 -> V_3 -> V_4 -> V_37 & V_38 )
F_8 ( V_2 , V_40 , V_13 ) ;
V_2 -> V_11 |= V_41 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 * V_13 )
{
T_1 V_35 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( ( V_2 -> V_3 -> V_4 -> V_9 & V_36 ) ||
( V_2 -> V_3 -> V_4 -> V_37 & V_38 ) ) )
return - V_6 ;
if ( ! V_2 -> V_3 -> V_4 -> V_18 ) {
F_2 ( 1 , L_3 , V_2 -> V_5 ) ;
return - V_6 ;
}
V_35 = ( 0x1 << V_2 -> V_3 -> V_4 -> V_18 -> V_39 ) ;
* V_13 &= ~ V_35 ;
if ( V_2 -> V_3 -> V_4 -> V_37 & V_38 )
F_8 ( V_2 , V_42 , V_13 ) ;
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
static int T_3 F_30 ( struct V_1 * V_2 )
{
int V_52 ;
int V_63 = 0 ;
if ( ! V_2 || V_2 -> V_53 == 0 )
return - V_6 ;
for ( V_52 = 0 ; V_52 < V_2 -> V_53 ; V_52 ++ ) {
struct V_54 * V_55 = V_2 -> V_56 [ V_52 ] ;
if ( V_55 -> V_64 & V_65 ) {
V_63 = 1 ;
break;
}
}
if ( V_63 )
F_24 ( L_14 ,
V_2 -> V_5 , V_52 ) ;
else
F_24 ( L_15 ,
V_2 -> V_5 ) ;
return ( V_63 ) ? V_52 : - V_6 ;
}
static void T_4 * T_3 F_31 ( struct V_1 * V_2 , T_2 V_66 )
{
struct V_54 * V_55 ;
struct V_67 * V_68 ;
int V_52 ;
int V_63 = 0 ;
void T_4 * va_start ;
if ( ! V_2 || V_2 -> V_53 == 0 )
return NULL ;
V_55 = V_2 -> V_56 [ V_66 ] ;
for ( V_52 = 0 , V_68 = V_55 -> V_69 ; V_52 < V_55 -> V_70 ; V_52 ++ , V_68 ++ ) {
if ( V_68 -> V_46 & V_71 ) {
V_63 = 1 ;
break;
}
}
if ( V_63 ) {
va_start = F_32 ( V_68 -> V_72 , V_68 -> V_73 - V_68 -> V_72 ) ;
if ( ! va_start ) {
F_33 ( L_16 , V_2 -> V_5 ) ;
return NULL ;
}
F_24 ( L_17 ,
V_2 -> V_5 , va_start ) ;
} else {
F_24 ( L_18 ,
V_2 -> V_5 ) ;
}
return ( V_63 ) ? va_start : NULL ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_2 V_20 , V_74 ;
T_1 V_13 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
V_13 = V_2 -> V_7 ;
V_74 = V_2 -> V_3 -> V_4 -> V_9 ;
if ( V_74 & V_23 ) {
V_20 = ( V_2 -> V_46 & V_75 ) ?
V_76 : V_42 ;
F_8 ( V_2 , V_20 , & V_13 ) ;
}
if ( V_74 & V_17 ) {
V_20 = ( V_2 -> V_46 & V_77 ) ?
V_76 : V_42 ;
F_6 ( V_2 , V_20 , & V_13 ) ;
}
if ( ( V_2 -> V_46 & V_78 ) &&
( V_74 & V_27 ) )
F_9 ( V_2 , V_2 -> V_3 -> V_4 -> V_24 , & V_13 ) ;
if ( ( V_74 & V_23 ) && ! ( V_2 -> V_46 & V_75 ) )
F_12 ( V_2 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
if ( V_74 & V_34 ) {
V_20 = ( V_2 -> V_46 & V_79 ) ?
0 : 1 ;
F_11 ( V_2 , V_20 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
T_2 V_20 , V_74 ;
T_1 V_13 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
V_13 = V_2 -> V_7 ;
V_74 = V_2 -> V_3 -> V_4 -> V_9 ;
if ( V_74 & V_23 ) {
V_20 = ( V_2 -> V_46 & V_75 ) ?
V_80 : V_42 ;
F_8 ( V_2 , V_20 , & V_13 ) ;
}
if ( V_74 & V_17 ) {
V_20 = ( V_2 -> V_46 & V_77 ) ?
V_80 : V_42 ;
F_6 ( V_2 , V_20 , & V_13 ) ;
}
if ( ( V_74 & V_23 ) && ! ( V_2 -> V_46 & V_75 ) )
F_12 ( V_2 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
T_1 V_13 ;
T_2 V_74 ;
if ( ! V_2 -> V_3 -> V_4 )
return;
V_13 = V_2 -> V_7 ;
V_74 = V_2 -> V_3 -> V_4 -> V_9 ;
if ( V_74 & V_23 )
F_8 ( V_2 , V_80 , & V_13 ) ;
if ( V_74 & V_17 )
F_6 ( V_2 , V_80 , & V_13 ) ;
if ( V_74 & V_34 )
F_11 ( V_2 , 1 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
}
static struct V_1 * F_37 ( const char * V_5 )
{
struct V_1 * V_2 , * V_81 ;
V_2 = NULL ;
F_38 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_5 , V_81 -> V_5 ) ) {
V_2 = V_81 ;
break;
}
}
return V_2 ;
}
static int F_39 ( struct V_1 * V_2 , void * V_82 )
{
int V_48 = 0 ;
if ( V_2 -> V_83 != V_84 )
return 0 ;
F_24 ( L_19 , V_2 -> V_5 ) ;
V_48 |= F_18 ( V_2 ) ;
V_48 |= F_21 ( V_2 ) ;
V_48 |= F_22 ( V_2 ) ;
if ( ! V_48 )
V_2 -> V_83 = V_85 ;
return V_48 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_54 * V_55 ;
int V_48 ;
if ( ! V_2 )
return - V_6 ;
if ( V_2 -> V_11 & V_86 )
return 0 ;
V_55 = V_2 -> V_56 [ V_2 -> V_87 ] ;
if ( V_2 -> V_46 & V_88 )
return 0 ;
if ( F_41 () || F_42 () ) {
V_48 = F_43 ( V_2 -> V_89 . V_90 . V_91 ,
V_2 -> V_89 . V_90 . V_92 ,
V_2 -> V_89 . V_90 . V_93 ) ;
} else if ( F_44 () ) {
V_48 = F_45 ( V_2 -> V_89 . V_94 . V_95 ) ;
} else {
F_46 () ;
} ;
return V_48 ;
}
static T_2 F_47 ( struct V_1 * V_2 , const char * V_5 ,
struct V_96 * V_97 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_2 -> V_98 ; V_52 ++ ) {
const char * V_99 = V_2 -> V_100 [ V_52 ] . V_5 ;
if ( ! strcmp ( V_99 , V_5 ) ) {
V_97 -> V_101 = V_2 -> V_100 [ V_52 ] . V_101 ;
V_97 -> V_102 = V_2 -> V_100 [ V_52 ] . V_102 ;
F_24 ( L_20 ,
V_2 -> V_5 , V_103 , V_99 , V_97 -> V_101 ,
V_97 -> V_102 ) ;
return 0 ;
}
}
return - V_104 ;
}
static int F_48 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_96 V_97 ;
T_2 V_48 ;
if ( ! V_2 )
return - V_6 ;
V_48 = F_47 ( V_2 , V_5 , & V_97 ) ;
if ( F_49 ( V_48 ) )
return V_48 ;
if ( F_41 () || F_42 () )
return F_50 ( V_2 -> V_89 . V_90 . V_91 ,
V_97 . V_101 ) ;
else if ( F_44 () )
return F_51 ( V_2 -> V_89 . V_94 . V_105 ,
V_97 . V_101 ) ;
else
return - V_6 ;
}
static int F_52 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_96 V_97 ;
int V_48 ;
if ( ! V_2 )
return - V_6 ;
V_48 = F_47 ( V_2 , V_5 , & V_97 ) ;
if ( F_49 ( V_48 ) )
return V_48 ;
if ( F_41 () || F_42 () ) {
V_48 = F_53 ( V_2 -> V_89 . V_90 . V_91 ,
V_97 . V_101 ,
V_97 . V_102 ) ;
} else if ( F_44 () ) {
if ( V_97 . V_102 )
F_33 ( L_21 ,
V_2 -> V_5 , V_5 ) ;
V_48 = F_54 ( V_2 -> V_89 . V_94 . V_105 ,
V_97 . V_101 ) ;
} else {
return - V_6 ;
}
if ( V_48 == - V_106 )
F_20 ( L_22 , V_2 -> V_5 ) ;
return V_48 ;
}
static int F_55 ( struct V_1 * V_2 , const char * V_5 )
{
struct V_96 V_97 ;
T_2 V_48 ;
if ( ! V_2 )
return - V_6 ;
V_48 = F_47 ( V_2 , V_5 , & V_97 ) ;
if ( F_49 ( V_48 ) )
return V_48 ;
if ( F_41 () || F_42 () ) {
return F_56 ( V_2 -> V_89 . V_90 . V_91 ,
V_97 . V_102 ) ;
} else if ( F_44 () ) {
return F_57 ( V_2 -> V_89 . V_94 . V_105 ,
V_97 . V_101 ) ;
} else {
return - V_6 ;
}
}
static int F_58 ( struct V_1 * V_2 )
{
T_1 V_13 ;
int V_51 = 0 ;
int V_48 = 0 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_29 ) )
return - V_6 ;
if ( V_2 -> V_83 != V_107 ) {
F_20 ( L_23
L_24 , V_2 -> V_5 ) ;
return - V_6 ;
}
if ( V_2 -> V_46 & V_108 )
F_28 ( V_2 ) ;
F_24 ( L_25 , V_2 -> V_5 ) ;
V_13 = V_2 -> V_7 ;
V_48 = F_10 ( V_2 , & V_13 ) ;
if ( V_48 )
goto V_109;
F_4 ( V_13 , V_2 ) ;
if ( V_2 -> V_3 -> V_4 -> V_9 & V_110 )
F_59 ( ( F_3 ( V_2 ,
V_2 -> V_3 -> V_4 -> V_111 )
& V_112 ) ,
V_113 , V_51 ) ;
else if ( V_2 -> V_3 -> V_4 -> V_9 & V_114 )
F_59 ( ! ( F_3 ( V_2 ,
V_2 -> V_3 -> V_4 -> V_8 )
& V_115 ) ,
V_113 , V_51 ) ;
if ( V_51 == V_113 )
F_20 ( L_26 ,
V_2 -> V_5 , V_113 ) ;
else
F_24 ( L_27 , V_2 -> V_5 , V_51 ) ;
V_48 = ( V_51 == V_113 ) ? - V_116 : 0 ;
V_109:
if ( V_2 -> V_46 & V_108 )
F_29 ( V_2 ) ;
return V_48 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_48 ;
F_24 ( L_28 , V_2 -> V_5 ) ;
V_48 = ( V_2 -> V_3 -> V_117 ) ? V_2 -> V_3 -> V_117 ( V_2 ) : F_58 ( V_2 ) ;
return V_48 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_118 ;
if ( V_2 -> V_83 != V_119 &&
V_2 -> V_83 != V_120 &&
V_2 -> V_83 != V_121 ) {
F_2 ( 1 , L_29
L_30 , V_2 -> V_5 ) ;
return - V_6 ;
}
F_24 ( L_31 , V_2 -> V_5 ) ;
if ( ( V_2 -> V_83 == V_119 ||
V_2 -> V_83 == V_121 ) && V_2 -> V_98 == 1 )
F_52 ( V_2 , V_2 -> V_100 [ 0 ] . V_5 ) ;
if ( V_2 -> V_122 && ( ! V_2 -> V_122 -> V_123 ||
( ( V_2 -> V_83 == V_120 ) &&
V_2 -> V_122 -> V_124 ) ) )
F_62 ( V_2 -> V_122 , V_107 ) ;
F_14 ( V_2 , V_125 ) ;
F_23 ( V_2 ) ;
V_118 = F_40 ( V_2 ) ;
if ( ! V_118 ) {
V_2 -> V_83 = V_107 ;
if ( V_2 -> V_3 -> V_4 ) {
if ( ! ( V_2 -> V_11 & V_12 ) )
F_1 ( V_2 ) ;
F_34 ( V_2 ) ;
}
} else {
F_26 ( V_2 ) ;
F_24 ( L_32 ,
V_2 -> V_5 , V_118 ) ;
}
return V_118 ;
}
static int F_63 ( struct V_1 * V_2 )
{
if ( V_2 -> V_83 != V_107 ) {
F_2 ( 1 , L_33
L_24 , V_2 -> V_5 ) ;
return - V_6 ;
}
F_24 ( L_34 , V_2 -> V_5 ) ;
if ( V_2 -> V_3 -> V_4 )
F_35 ( V_2 ) ;
F_16 ( V_2 , V_125 ) ;
F_26 ( V_2 ) ;
if ( V_2 -> V_122 && V_2 -> V_122 -> V_124 )
F_62 ( V_2 -> V_122 , V_120 ) ;
V_2 -> V_83 = V_120 ;
return 0 ;
}
int F_64 ( struct V_1 * V_2 , T_2 V_31 )
{
T_1 V_13 ;
int V_126 = 0 ;
unsigned long V_46 ;
if ( ! V_2 || V_2 -> V_83 != V_107 )
return - V_6 ;
F_65 ( & V_2 -> V_127 , V_46 ) ;
V_13 = V_2 -> V_7 ;
V_126 = F_11 ( V_2 , V_31 , & V_13 ) ;
if ( ! V_126 )
F_4 ( V_13 , V_2 ) ;
F_66 ( & V_2 -> V_127 , V_46 ) ;
return V_126 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_48 ;
T_2 V_128 ;
if ( V_2 -> V_83 != V_120 &&
V_2 -> V_83 != V_107 ) {
F_2 ( 1 , L_35
L_36 , V_2 -> V_5 ) ;
return - V_6 ;
}
F_24 ( L_37 , V_2 -> V_5 ) ;
if ( V_2 -> V_3 -> V_129 ) {
V_128 = V_2 -> V_83 ;
if ( V_2 -> V_83 == V_120 )
F_61 ( V_2 ) ;
V_48 = V_2 -> V_3 -> V_129 ( V_2 ) ;
if ( V_48 ) {
if ( V_128 == V_120 )
F_63 ( V_2 ) ;
return V_48 ;
}
}
if ( V_2 -> V_3 -> V_4 )
F_36 ( V_2 ) ;
if ( V_2 -> V_98 == 1 )
F_48 ( V_2 , V_2 -> V_100 [ 0 ] . V_5 ) ;
if ( V_2 -> V_83 == V_107 ) {
F_16 ( V_2 , V_125 ) ;
F_26 ( V_2 ) ;
}
if ( V_2 -> V_122 )
F_62 ( V_2 -> V_122 , V_121 ) ;
V_2 -> V_83 = V_121 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , void * V_82 )
{
int V_52 , V_118 ;
T_2 V_130 ;
if ( V_2 -> V_83 != V_85 )
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
V_2 -> V_83 = V_119 ;
if ( ( V_2 -> V_46 & V_131 ) && V_2 -> V_98 == 1 )
return 0 ;
V_118 = F_61 ( V_2 ) ;
if ( V_118 ) {
F_20 ( L_38 ,
V_2 -> V_5 , V_2 -> V_83 ) ;
return 0 ;
}
if ( ! ( V_2 -> V_46 & V_131 ) ) {
F_60 ( V_2 ) ;
if ( V_2 -> V_3 -> V_4 ) {
F_1 ( V_2 ) ;
F_34 ( V_2 ) ;
}
}
V_130 = V_2 -> V_132 ;
if ( V_130 == V_133 )
V_130 = V_107 ;
if ( ( V_2 -> V_46 & V_134 ) &&
( V_130 == V_120 ) )
V_130 = V_107 ;
if ( V_130 == V_120 )
F_63 ( V_2 ) ;
else if ( V_130 == V_121 )
F_67 ( V_2 ) ;
else if ( V_130 != V_107 )
F_2 ( 1 , L_39 ,
V_2 -> V_5 , V_130 ) ;
return 0 ;
}
static int T_3 F_69 ( struct V_1 * V_2 )
{
int V_135 ;
if ( ! V_2 || ! V_2 -> V_5 || ! V_2 -> V_3 || ! V_2 -> V_3 -> V_5 ||
( V_2 -> V_83 != V_133 ) )
return - V_6 ;
F_24 ( L_40 , V_2 -> V_5 ) ;
if ( F_37 ( V_2 -> V_5 ) )
return - V_136 ;
V_135 = F_30 ( V_2 ) ;
if ( ! F_49 ( V_135 ) )
V_2 -> V_87 = V_135 ;
else
V_2 -> V_11 |= V_86 ;
F_70 ( & V_2 -> V_137 , & V_138 ) ;
F_71 ( & V_2 -> V_127 ) ;
V_2 -> V_83 = V_84 ;
if ( ! strcmp ( V_2 -> V_5 , V_139 ) )
V_125 = V_2 ;
return 0 ;
}
T_1 F_3 ( struct V_1 * V_2 , T_5 V_140 )
{
if ( V_2 -> V_46 & V_141 )
return F_72 ( V_2 -> V_142 + V_140 ) ;
else
return F_73 ( V_2 -> V_142 + V_140 ) ;
}
void F_5 ( T_1 V_13 , struct V_1 * V_2 , T_5 V_140 )
{
if ( V_2 -> V_46 & V_141 )
F_74 ( V_13 , V_2 -> V_142 + V_140 ) ;
else
F_75 ( V_13 , V_2 -> V_142 + V_140 ) ;
}
int F_76 ( struct V_1 * V_2 , T_2 V_20 )
{
T_1 V_13 ;
int V_126 = 0 ;
if ( ! V_2 )
return - V_6 ;
V_13 = V_2 -> V_7 ;
V_126 = F_8 ( V_2 , V_20 , & V_13 ) ;
if ( ! V_126 )
F_4 ( V_13 , V_2 ) ;
return V_126 ;
}
struct V_1 * F_77 ( const char * V_5 )
{
struct V_1 * V_2 ;
if ( ! V_5 )
return NULL ;
V_2 = F_37 ( V_5 ) ;
return V_2 ;
}
int F_78 ( int (* F_79)( struct V_1 * V_2 , void * V_82 ) ,
void * V_82 )
{
struct V_1 * V_81 ;
int V_48 = 0 ;
if ( ! F_79 )
return - V_6 ;
F_38 (temp_oh, &omap_hwmod_list, node) {
V_48 = (* F_79)( V_81 , V_82 ) ;
if ( V_48 )
break;
}
return V_48 ;
}
int T_3 F_80 ( struct V_1 * * V_143 )
{
int V_118 , V_52 ;
if ( ! V_143 )
return 0 ;
V_52 = 0 ;
do {
if ( ! F_81 ( V_143 [ V_52 ] -> V_144 ) )
continue;
V_118 = F_69 ( V_143 [ V_52 ] ) ;
F_2 ( V_118 , L_41 , V_143 [ V_52 ] -> V_5 ,
V_118 ) ;
} while ( V_143 [ ++ V_52 ] );
return 0 ;
}
static int T_3 F_82 ( struct V_1 * V_2 , void * V_82 )
{
if ( V_2 -> V_83 != V_84 )
return 0 ;
if ( V_2 -> V_11 & V_86 )
return 0 ;
V_2 -> V_142 = F_31 ( V_2 , V_2 -> V_87 ) ;
if ( ! V_2 -> V_142 )
F_20 ( L_42 ,
V_103 , V_2 -> V_5 ) ;
return 0 ;
}
int T_3 F_83 ( const char * V_145 )
{
struct V_1 * V_2 ;
int V_118 ;
F_24 ( L_43 , V_145 , V_103 ) ;
if ( ! V_125 ) {
F_33 ( L_44 ,
V_145 , V_139 ) ;
return - V_6 ;
}
V_2 = F_37 ( V_145 ) ;
if ( ! V_2 ) {
F_2 ( 1 , L_45 , V_145 ) ;
return - V_6 ;
}
if ( V_125 -> V_83 == V_84 && V_2 != V_125 )
F_83 ( V_139 ) ;
V_118 = F_82 ( V_2 , NULL ) ;
if ( F_49 ( V_118 ) ) {
F_2 ( 1 , L_46 , V_145 ) ;
return - V_6 ;
}
V_118 = F_39 ( V_2 , NULL ) ;
if ( F_49 ( V_118 ) ) {
F_2 ( 1 , L_47 , V_145 ) ;
return - V_6 ;
}
F_68 ( V_2 , NULL ) ;
return 0 ;
}
static int T_3 F_84 ( void )
{
int V_118 ;
if ( ! V_125 ) {
F_33 ( L_48 ,
V_103 , V_139 ) ;
return - V_6 ;
}
V_118 = F_78 ( F_82 , NULL ) ;
V_118 = F_78 ( F_39 , NULL ) ;
F_2 ( F_49 ( V_118 ) ,
L_49 , V_103 ) ;
F_78 ( F_68 , NULL ) ;
return 0 ;
}
int F_85 ( struct V_1 * V_2 )
{
int V_118 ;
unsigned long V_46 ;
if ( ! V_2 )
return - V_6 ;
F_65 ( & V_2 -> V_127 , V_46 ) ;
V_118 = F_61 ( V_2 ) ;
F_66 ( & V_2 -> V_127 , V_46 ) ;
return V_118 ;
}
int F_86 ( struct V_1 * V_2 )
{
unsigned long V_46 ;
if ( ! V_2 )
return - V_6 ;
F_65 ( & V_2 -> V_127 , V_46 ) ;
F_63 ( V_2 ) ;
F_66 ( & V_2 -> V_127 , V_46 ) ;
return 0 ;
}
int F_87 ( struct V_1 * V_2 )
{
unsigned long V_46 ;
if ( ! V_2 )
return - V_6 ;
F_65 ( & V_2 -> V_127 , V_46 ) ;
F_67 ( V_2 ) ;
F_66 ( & V_2 -> V_127 , V_46 ) ;
return 0 ;
}
int F_88 ( struct V_1 * V_2 )
{
unsigned long V_46 ;
F_65 ( & V_2 -> V_127 , V_46 ) ;
F_23 ( V_2 ) ;
F_66 ( & V_2 -> V_127 , V_46 ) ;
return 0 ;
}
int F_89 ( struct V_1 * V_2 )
{
unsigned long V_46 ;
F_65 ( & V_2 -> V_127 , V_46 ) ;
F_26 ( V_2 ) ;
F_66 ( & V_2 -> V_127 , V_46 ) ;
return 0 ;
}
void F_90 ( struct V_1 * V_2 )
{
F_91 ( ! V_2 ) ;
if ( ! V_2 -> V_3 -> V_4 || ! V_2 -> V_3 -> V_4 -> V_9 ) {
F_2 ( 1 , L_50
L_51 , V_2 -> V_5 ) ;
return;
}
F_3 ( V_2 , V_2 -> V_3 -> V_4 -> V_8 ) ;
}
int F_92 ( struct V_1 * V_2 )
{
int V_118 ;
unsigned long V_46 ;
if ( ! V_2 )
return - V_6 ;
F_65 ( & V_2 -> V_127 , V_46 ) ;
V_118 = F_60 ( V_2 ) ;
F_66 ( & V_2 -> V_127 , V_46 ) ;
return V_118 ;
}
int F_93 ( struct V_1 * V_2 )
{
int V_48 , V_52 ;
V_48 = V_2 -> V_146 + V_2 -> V_147 ;
for ( V_52 = 0 ; V_52 < V_2 -> V_53 ; V_52 ++ )
V_48 += V_2 -> V_56 [ V_52 ] -> V_70 ;
return V_48 ;
}
int F_94 ( struct V_1 * V_2 , struct V_148 * V_149 )
{
int V_52 , V_150 ;
int V_118 = 0 ;
for ( V_52 = 0 ; V_52 < V_2 -> V_146 ; V_52 ++ ) {
( V_149 + V_118 ) -> V_5 = ( V_2 -> V_151 + V_52 ) -> V_5 ;
( V_149 + V_118 ) -> V_152 = ( V_2 -> V_151 + V_52 ) -> V_153 ;
( V_149 + V_118 ) -> V_154 = ( V_2 -> V_151 + V_52 ) -> V_153 ;
( V_149 + V_118 ) -> V_46 = V_155 ;
V_118 ++ ;
}
for ( V_52 = 0 ; V_52 < V_2 -> V_147 ; V_52 ++ ) {
( V_149 + V_118 ) -> V_5 = ( V_2 -> V_156 + V_52 ) -> V_5 ;
( V_149 + V_118 ) -> V_152 = ( V_2 -> V_156 + V_52 ) -> V_157 ;
( V_149 + V_118 ) -> V_154 = ( V_2 -> V_156 + V_52 ) -> V_157 ;
( V_149 + V_118 ) -> V_46 = V_158 ;
V_118 ++ ;
}
for ( V_52 = 0 ; V_52 < V_2 -> V_53 ; V_52 ++ ) {
struct V_54 * V_55 ;
V_55 = V_2 -> V_56 [ V_52 ] ;
for ( V_150 = 0 ; V_150 < V_55 -> V_70 ; V_150 ++ ) {
( V_149 + V_118 ) -> V_5 = ( V_55 -> V_69 + V_150 ) -> V_5 ;
( V_149 + V_118 ) -> V_152 = ( V_55 -> V_69 + V_150 ) -> V_72 ;
( V_149 + V_118 ) -> V_154 = ( V_55 -> V_69 + V_150 ) -> V_73 ;
( V_149 + V_118 ) -> V_46 = V_159 ;
V_118 ++ ;
}
}
return V_118 ;
}
struct V_160 * F_95 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_44 ) {
V_51 = V_2 -> V_44 ;
} else {
if ( V_2 -> V_11 & V_86 )
return NULL ;
V_51 = V_2 -> V_56 [ V_2 -> V_87 ] -> V_44 ;
}
if ( ! V_51 -> V_45 )
return NULL ;
return V_51 -> V_45 -> V_161 . V_162 ;
}
void T_4 * F_96 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_11 & V_86 )
return NULL ;
if ( V_2 -> V_83 == V_133 )
return NULL ;
return V_2 -> V_142 ;
}
int F_97 ( struct V_1 * V_2 ,
struct V_1 * V_43 )
{
return F_14 ( V_2 , V_43 ) ;
}
int F_98 ( struct V_1 * V_2 ,
struct V_1 * V_43 )
{
return F_16 ( V_2 , V_43 ) ;
}
int F_99 ( struct V_1 * V_2 )
{
unsigned long V_46 ;
T_1 V_13 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_36 ) )
return - V_6 ;
F_65 ( & V_2 -> V_127 , V_46 ) ;
V_13 = V_2 -> V_7 ;
F_12 ( V_2 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
F_66 ( & V_2 -> V_127 , V_46 ) ;
return 0 ;
}
int F_100 ( struct V_1 * V_2 )
{
unsigned long V_46 ;
T_1 V_13 ;
if ( ! V_2 -> V_3 -> V_4 ||
! ( V_2 -> V_3 -> V_4 -> V_9 & V_36 ) )
return - V_6 ;
F_65 ( & V_2 -> V_127 , V_46 ) ;
V_13 = V_2 -> V_7 ;
F_13 ( V_2 , & V_13 ) ;
F_4 ( V_13 , V_2 ) ;
F_66 ( & V_2 -> V_127 , V_46 ) ;
return 0 ;
}
int F_101 ( struct V_1 * V_2 , const char * V_5 )
{
int V_48 ;
unsigned long V_46 ;
if ( ! V_2 )
return - V_6 ;
F_65 ( & V_2 -> V_127 , V_46 ) ;
V_48 = F_48 ( V_2 , V_5 ) ;
F_66 ( & V_2 -> V_127 , V_46 ) ;
return V_48 ;
}
int F_102 ( struct V_1 * V_2 , const char * V_5 )
{
int V_48 ;
unsigned long V_46 ;
if ( ! V_2 )
return - V_6 ;
F_65 ( & V_2 -> V_127 , V_46 ) ;
V_48 = F_52 ( V_2 , V_5 ) ;
F_66 ( & V_2 -> V_127 , V_46 ) ;
return V_48 ;
}
int F_103 ( struct V_1 * V_2 , const char * V_5 )
{
int V_48 ;
unsigned long V_46 ;
if ( ! V_2 )
return - V_6 ;
F_65 ( & V_2 -> V_127 , V_46 ) ;
V_48 = F_55 ( V_2 , V_5 ) ;
F_66 ( & V_2 -> V_127 , V_46 ) ;
return V_48 ;
}
int F_104 ( const char * V_163 ,
int (* F_79)( struct V_1 * V_2 ,
void * V_64 ) ,
void * V_64 )
{
struct V_1 * V_81 ;
int V_48 = 0 ;
if ( ! V_163 || ! F_79 )
return - V_6 ;
F_24 ( L_52 ,
V_103 , V_163 ) ;
F_38 (temp_oh, &omap_hwmod_list, node) {
if ( ! strcmp ( V_81 -> V_3 -> V_5 , V_163 ) ) {
F_24 ( L_53 ,
V_103 , V_81 -> V_5 ) ;
V_48 = (* F_79)( V_81 , V_64 ) ;
if ( V_48 )
break;
}
}
if ( V_48 )
F_24 ( L_54 ,
V_103 , V_48 ) ;
return V_48 ;
}
int F_105 ( struct V_1 * V_2 , T_2 V_164 )
{
int V_48 ;
unsigned long V_46 ;
if ( ! V_2 )
return - V_6 ;
if ( V_164 != V_121 &&
V_164 != V_107 &&
V_164 != V_120 )
return - V_6 ;
F_65 ( & V_2 -> V_127 , V_46 ) ;
if ( V_2 -> V_83 != V_84 ) {
V_48 = - V_6 ;
goto V_165;
}
V_2 -> V_132 = V_164 ;
V_48 = 0 ;
V_165:
F_66 ( & V_2 -> V_127 , V_46 ) ;
return V_48 ;
}
T_1 F_106 ( struct V_1 * V_2 )
{
struct V_160 * V_161 ;
int V_48 = 0 ;
V_161 = F_95 ( V_2 ) ;
if ( V_161 )
V_48 = F_107 ( V_161 ) ;
return V_48 ;
}
int F_108 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_6 ;
if ( V_2 -> V_83 != V_84 ) {
F_33 ( L_55 ,
V_2 -> V_5 ) ;
return - V_6 ;
}
V_2 -> V_46 |= V_131 ;
return 0 ;
}
