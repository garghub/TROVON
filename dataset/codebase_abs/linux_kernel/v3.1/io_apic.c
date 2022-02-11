int F_1 ( int V_1 )
{
return V_2 [ V_1 ] . V_3 . V_4 ;
}
unsigned int F_2 ( int V_1 )
{
return V_2 [ V_1 ] . V_3 . V_5 ;
}
struct V_6 * F_3 ( int V_1 )
{
return & V_2 [ V_1 ] . V_7 ;
}
void F_4 ( void )
{
#ifdef F_5
V_8 = 1 ;
V_9 = - 1 ;
#endif
V_10 = 1 ;
}
static int T_1 F_6 ( char * V_11 )
{
F_4 () ;
return 0 ;
}
void F_7 ( struct V_12 * V_13 )
{
int V_14 ;
F_8 ( V_15 , L_1
L_2 ,
V_13 -> V_16 , V_13 -> V_17 & 3 , ( V_13 -> V_17 >> 2 ) & 3 , V_13 -> V_18 ,
V_13 -> V_19 , V_13 -> V_20 , V_13 -> V_21 ) ;
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ ) {
if ( ! memcmp ( & V_23 [ V_14 ] , V_13 , sizeof( * V_13 ) ) )
return;
}
memcpy ( & V_23 [ V_22 ] , V_13 , sizeof( * V_13 ) ) ;
if ( ++ V_22 == V_24 )
F_9 ( L_3 ) ;
}
static struct V_25 * F_10 ( int V_26 )
{
return F_11 ( sizeof( struct V_25 ) , V_27 , V_26 ) ;
}
int T_1 F_12 ( void )
{
struct V_28 * V_29 ;
int V_30 , V_26 , V_14 ;
if ( ! V_31 -> V_32 ) {
V_33 = 0 ;
V_34 = ~ 0UL ;
}
for ( V_14 = 0 ; V_14 < V_35 ; V_14 ++ ) {
V_2 [ V_14 ] . V_36 =
F_13 ( sizeof( struct V_37 ) *
V_2 [ V_14 ] . V_38 , V_27 ) ;
if ( ! V_2 [ V_14 ] . V_36 )
F_14 ( L_4 , V_14 ) ;
}
V_29 = V_39 ;
V_30 = F_15 ( V_39 ) ;
V_26 = F_16 ( 0 ) ;
F_17 ( 0 , V_31 -> V_32 ) ;
for ( V_14 = 0 ; V_14 < V_30 ; V_14 ++ ) {
F_18 ( V_14 , & V_29 [ V_14 ] ) ;
F_19 ( & V_29 [ V_14 ] . V_40 , V_27 , V_26 ) ;
F_19 ( & V_29 [ V_14 ] . V_41 , V_27 , V_26 ) ;
if ( V_14 < V_31 -> V_32 ) {
V_29 [ V_14 ] . V_42 = V_43 + V_14 ;
F_20 ( 0 , V_29 [ V_14 ] . V_40 ) ;
}
}
return 0 ;
}
static struct V_28 * V_28 ( unsigned int V_44 )
{
return F_21 ( V_44 ) ;
}
static struct V_28 * F_22 ( unsigned int V_44 , int V_26 )
{
struct V_28 * V_29 ;
V_29 = F_11 ( sizeof( * V_29 ) , V_27 , V_26 ) ;
if ( ! V_29 )
return NULL ;
if ( ! F_19 ( & V_29 -> V_40 , V_27 , V_26 ) )
goto V_45;
if ( ! F_19 ( & V_29 -> V_41 , V_27 , V_26 ) )
goto V_46;
return V_29 ;
V_46:
F_23 ( V_29 -> V_40 ) ;
V_45:
F_24 ( V_29 ) ;
return NULL ;
}
static void F_25 ( unsigned int V_47 , struct V_28 * V_29 )
{
if ( ! V_29 )
return;
F_18 ( V_47 , NULL ) ;
F_23 ( V_29 -> V_40 ) ;
F_23 ( V_29 -> V_41 ) ;
F_24 ( V_29 ) ;
}
struct V_28 * V_28 ( unsigned int V_44 )
{
return V_44 < V_48 ? V_39 + V_44 : NULL ;
}
static struct V_28 * F_22 ( unsigned int V_44 , int V_26 )
{
return V_39 + V_44 ;
}
static inline void F_25 ( unsigned int V_47 , struct V_28 * V_29 ) { }
static struct V_28 * F_26 ( unsigned int V_47 , int V_26 )
{
int V_49 = F_27 ( V_47 , V_26 ) ;
struct V_28 * V_29 ;
if ( V_49 < 0 ) {
if ( V_49 != - V_50 )
return NULL ;
V_29 = F_21 ( V_47 ) ;
if ( V_29 )
return V_29 ;
}
V_29 = F_22 ( V_47 , V_26 ) ;
if ( V_29 )
F_18 ( V_47 , V_29 ) ;
else
F_28 ( V_47 ) ;
return V_29 ;
}
static int F_29 ( unsigned int V_51 , int V_26 )
{
return F_30 ( V_51 , V_26 ) ;
}
static void F_31 ( unsigned int V_47 , struct V_28 * V_29 )
{
F_25 ( V_47 , V_29 ) ;
F_28 ( V_47 ) ;
}
static inline void F_32 ( unsigned int V_52 , unsigned int V_42 )
{
struct V_53 T_2 * V_53 = F_33 ( V_52 ) ;
F_34 ( V_42 , & V_53 -> V_54 ) ;
}
static inline unsigned int F_35 ( unsigned int V_52 , unsigned int V_55 )
{
struct V_53 T_2 * V_53 = F_33 ( V_52 ) ;
F_34 ( V_55 , & V_53 -> V_56 ) ;
return F_36 ( & V_53 -> V_57 ) ;
}
static inline void F_37 ( unsigned int V_52 , unsigned int V_55 , unsigned int V_58 )
{
struct V_53 T_2 * V_53 = F_33 ( V_52 ) ;
F_34 ( V_55 , & V_53 -> V_56 ) ;
F_34 ( V_58 , & V_53 -> V_57 ) ;
}
static inline void F_38 ( unsigned int V_52 , unsigned int V_55 , unsigned int V_58 )
{
struct V_53 T_2 * V_53 = F_33 ( V_52 ) ;
if ( V_59 )
F_34 ( V_55 , & V_53 -> V_56 ) ;
F_34 ( V_58 , & V_53 -> V_57 ) ;
}
static bool F_39 ( struct V_28 * V_29 )
{
struct V_25 * V_60 ;
unsigned long V_61 ;
F_40 ( & V_62 , V_61 ) ;
F_41 (entry, cfg->irq_2_pin) {
unsigned int V_55 ;
int V_63 ;
V_63 = V_60 -> V_63 ;
V_55 = F_35 ( V_60 -> V_52 , 0x10 + V_63 * 2 ) ;
if ( V_55 & V_64 ) {
F_42 ( & V_62 , V_61 ) ;
return true ;
}
}
F_42 ( & V_62 , V_61 ) ;
return false ;
}
static struct V_37 F_43 ( int V_52 , int V_63 )
{
union V_65 V_66 ;
unsigned long V_61 ;
F_40 ( & V_62 , V_61 ) ;
V_66 . V_67 = F_35 ( V_52 , 0x10 + 2 * V_63 ) ;
V_66 . V_68 = F_35 ( V_52 , 0x11 + 2 * V_63 ) ;
F_42 ( & V_62 , V_61 ) ;
return V_66 . V_60 ;
}
static void
F_44 ( int V_52 , int V_63 , struct V_37 V_69 )
{
union V_65 V_66 = { { 0 , 0 } } ;
V_66 . V_60 = V_69 ;
F_37 ( V_52 , 0x11 + 2 * V_63 , V_66 . V_68 ) ;
F_37 ( V_52 , 0x10 + 2 * V_63 , V_66 . V_67 ) ;
}
static void F_45 ( int V_52 , int V_63 , struct V_37 V_69 )
{
unsigned long V_61 ;
F_40 ( & V_62 , V_61 ) ;
F_44 ( V_52 , V_63 , V_69 ) ;
F_42 ( & V_62 , V_61 ) ;
}
static void F_46 ( int V_52 , int V_63 )
{
unsigned long V_61 ;
union V_65 V_66 = { . V_60 . V_70 = 1 } ;
F_40 ( & V_62 , V_61 ) ;
F_37 ( V_52 , 0x10 + 2 * V_63 , V_66 . V_67 ) ;
F_37 ( V_52 , 0x11 + 2 * V_63 , V_66 . V_68 ) ;
F_42 ( & V_62 , V_61 ) ;
}
static int
F_47 ( struct V_28 * V_29 , int V_26 , int V_52 , int V_63 )
{
struct V_25 * * V_71 , * V_60 ;
V_71 = & V_29 -> V_72 ;
F_41 (entry, cfg->irq_2_pin) {
if ( V_60 -> V_52 == V_52 && V_60 -> V_63 == V_63 )
return 0 ;
V_71 = & V_60 -> V_73 ;
}
V_60 = F_10 ( V_26 ) ;
if ( ! V_60 ) {
F_48 ( V_74 L_5 ,
V_26 , V_52 , V_63 ) ;
return - V_75 ;
}
V_60 -> V_52 = V_52 ;
V_60 -> V_63 = V_63 ;
* V_71 = V_60 ;
return 0 ;
}
static void F_49 ( struct V_28 * V_29 , int V_26 , int V_52 , int V_63 )
{
if ( F_47 ( V_29 , V_26 , V_52 , V_63 ) )
F_9 ( L_6 ) ;
}
static void T_1 F_50 ( struct V_28 * V_29 , int V_26 ,
int V_76 , int V_77 ,
int V_78 , int V_79 )
{
struct V_25 * V_60 ;
F_41 (entry, cfg->irq_2_pin) {
if ( V_60 -> V_52 == V_76 && V_60 -> V_63 == V_77 ) {
V_60 -> V_52 = V_78 ;
V_60 -> V_63 = V_79 ;
return;
}
}
F_49 ( V_29 , V_26 , V_78 , V_79 ) ;
}
static void F_51 ( struct V_25 * V_60 ,
int V_80 , int V_81 ,
void (* F_52)( struct V_25 * V_60 ) )
{
unsigned int V_55 , V_63 ;
V_63 = V_60 -> V_63 ;
V_55 = F_35 ( V_60 -> V_52 , 0x10 + V_63 * 2 ) ;
V_55 &= V_80 ;
V_55 |= V_81 ;
F_38 ( V_60 -> V_52 , 0x10 + V_63 * 2 , V_55 ) ;
if ( F_52 )
F_52 ( V_60 ) ;
}
static void F_53 ( struct V_28 * V_29 ,
int V_80 , int V_81 ,
void (* F_52)( struct V_25 * V_60 ) )
{
struct V_25 * V_60 ;
F_41 (entry, cfg->irq_2_pin)
F_51 ( V_60 , V_80 , V_81 , F_52 ) ;
}
static void F_54 ( struct V_25 * V_60 )
{
F_51 ( V_60 , ~ V_82 ,
V_83 , NULL ) ;
}
static void F_55 ( struct V_25 * V_60 )
{
F_51 ( V_60 , ~ V_83 ,
V_82 , NULL ) ;
}
static void F_56 ( struct V_25 * V_60 )
{
struct V_53 T_2 * V_53 ;
V_53 = F_33 ( V_60 -> V_52 ) ;
F_36 ( & V_53 -> V_57 ) ;
}
static void F_57 ( struct V_28 * V_29 )
{
unsigned long V_61 ;
F_40 ( & V_62 , V_61 ) ;
F_53 ( V_29 , ~ 0 , V_83 , & F_56 ) ;
F_42 ( & V_62 , V_61 ) ;
}
static void F_58 ( struct V_84 * V_57 )
{
F_57 ( V_57 -> V_85 ) ;
}
static void F_59 ( struct V_28 * V_29 )
{
F_53 ( V_29 , ~ V_83 , 0 , NULL ) ;
}
static void F_60 ( struct V_28 * V_29 )
{
unsigned long V_61 ;
F_40 ( & V_62 , V_61 ) ;
F_59 ( V_29 ) ;
F_42 ( & V_62 , V_61 ) ;
}
static void F_61 ( struct V_84 * V_57 )
{
F_60 ( V_57 -> V_85 ) ;
}
static void F_62 ( unsigned int V_52 , unsigned int V_63 )
{
struct V_37 V_60 ;
V_60 = F_43 ( V_52 , V_63 ) ;
if ( V_60 . V_86 == V_87 )
return;
F_46 ( V_52 , V_63 ) ;
}
static void F_63 ( void )
{
int V_52 , V_63 ;
for ( V_52 = 0 ; V_52 < V_35 ; V_52 ++ )
for ( V_63 = 0 ; V_63 < V_2 [ V_52 ] . V_38 ; V_63 ++ )
F_62 ( V_52 , V_63 ) ;
}
static int T_1 F_64 ( char * V_11 )
{
int V_14 , V_88 ;
int V_89 [ V_90 + 1 ] ;
F_65 ( V_11 , F_15 ( V_89 ) , V_89 ) ;
F_8 ( V_15 , V_91
L_7 ) ;
V_88 = V_90 ;
if ( V_89 [ 0 ] < V_90 )
V_88 = V_89 [ 0 ] ;
for ( V_14 = 0 ; V_14 < V_88 ; V_14 ++ ) {
F_8 ( V_15 , V_92
L_8 , V_14 , V_89 [ V_14 + 1 ] ) ;
V_93 [ V_90 - V_14 - 1 ] = V_89 [ V_14 + 1 ] ;
}
return 1 ;
}
int F_66 ( void )
{
int V_52 , V_63 ;
int V_94 = 0 ;
for ( V_52 = 0 ; V_52 < V_35 ; V_52 ++ ) {
if ( ! V_2 [ V_52 ] . V_36 ) {
V_94 = - V_75 ;
continue;
}
for ( V_63 = 0 ; V_63 < V_2 [ V_52 ] . V_38 ; V_63 ++ )
V_2 [ V_52 ] . V_36 [ V_63 ] =
F_43 ( V_52 , V_63 ) ;
}
return V_94 ;
}
void F_67 ( void )
{
int V_52 , V_63 ;
for ( V_52 = 0 ; V_52 < V_35 ; V_52 ++ ) {
if ( ! V_2 [ V_52 ] . V_36 )
continue;
for ( V_63 = 0 ; V_63 < V_2 [ V_52 ] . V_38 ; V_63 ++ ) {
struct V_37 V_60 ;
V_60 = V_2 [ V_52 ] . V_36 [ V_63 ] ;
if ( ! V_60 . V_70 ) {
V_60 . V_70 = 1 ;
F_45 ( V_52 , V_63 , V_60 ) ;
}
}
}
}
int F_68 ( void )
{
int V_52 , V_63 ;
for ( V_52 = 0 ; V_52 < V_35 ; V_52 ++ ) {
if ( ! V_2 [ V_52 ] . V_36 )
continue;
for ( V_63 = 0 ; V_63 < V_2 [ V_52 ] . V_38 ; V_63 ++ )
F_45 ( V_52 , V_63 ,
V_2 [ V_52 ] . V_36 [ V_63 ] ) ;
}
return 0 ;
}
static int F_69 ( int V_52 , int V_63 , int type )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ )
if ( V_23 [ V_14 ] . V_16 == type &&
( V_23 [ V_14 ] . V_20 == F_1 ( V_52 ) ||
V_23 [ V_14 ] . V_20 == V_95 ) &&
V_23 [ V_14 ] . V_21 == V_63 )
return V_14 ;
return - 1 ;
}
static int T_1 F_70 ( int V_44 , int type )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ ) {
int V_96 = V_23 [ V_14 ] . V_18 ;
if ( F_71 ( V_96 , V_97 ) &&
( V_23 [ V_14 ] . V_16 == type ) &&
( V_23 [ V_14 ] . V_19 == V_44 ) )
return V_23 [ V_14 ] . V_21 ;
}
return - 1 ;
}
static int T_1 F_72 ( int V_44 , int type )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ ) {
int V_96 = V_23 [ V_14 ] . V_18 ;
if ( F_71 ( V_96 , V_97 ) &&
( V_23 [ V_14 ] . V_16 == type ) &&
( V_23 [ V_14 ] . V_19 == V_44 ) )
break;
}
if ( V_14 < V_22 ) {
int V_52 ;
for( V_52 = 0 ; V_52 < V_35 ; V_52 ++ ) {
if ( F_1 ( V_52 ) == V_23 [ V_14 ] . V_20 )
return V_52 ;
}
}
return - 1 ;
}
static int F_73 ( unsigned int V_44 )
{
if ( V_44 < V_31 -> V_32 ) {
unsigned int V_98 = 0x4d0 + ( V_44 >> 3 ) ;
return ( F_74 ( V_98 ) >> ( V_44 & 7 ) ) & 1 ;
}
F_8 ( V_15 , V_91
L_9 , V_44 ) ;
return 0 ;
}
static int F_75 ( int V_99 )
{
int V_100 = V_23 [ V_99 ] . V_18 ;
int V_101 ;
switch ( V_23 [ V_99 ] . V_17 & 3 )
{
case 0 :
if ( F_71 ( V_100 , V_97 ) )
V_101 = F_76 ( V_99 ) ;
else
V_101 = F_77 ( V_99 ) ;
break;
case 1 :
{
V_101 = 0 ;
break;
}
case 2 :
{
F_48 ( V_102 L_10 ) ;
V_101 = 1 ;
break;
}
case 3 :
{
V_101 = 1 ;
break;
}
default:
{
F_48 ( V_102 L_10 ) ;
V_101 = 1 ;
break;
}
}
return V_101 ;
}
static int F_78 ( int V_99 )
{
int V_100 = V_23 [ V_99 ] . V_18 ;
int V_103 ;
switch ( ( V_23 [ V_99 ] . V_17 >> 2 ) & 3 )
{
case 0 :
if ( F_71 ( V_100 , V_97 ) )
V_103 = F_79 ( V_99 ) ;
else
V_103 = F_80 ( V_99 ) ;
#if F_81 ( V_104 ) || F_81 ( V_105 )
switch ( V_106 [ V_100 ] ) {
case V_107 :
{
break;
}
case V_108 :
{
V_103 = F_82 ( V_99 ) ;
break;
}
case V_109 :
{
break;
}
case V_110 :
{
V_103 = F_83 ( V_99 ) ;
break;
}
default:
{
F_48 ( V_102 L_10 ) ;
V_103 = 1 ;
break;
}
}
#endif
break;
case 1 :
{
V_103 = 0 ;
break;
}
case 2 :
{
F_48 ( V_102 L_10 ) ;
V_103 = 1 ;
break;
}
case 3 :
{
V_103 = 1 ;
break;
}
default:
{
F_48 ( V_102 L_10 ) ;
V_103 = 0 ;
break;
}
}
return V_103 ;
}
static int F_84 ( int V_99 , int V_52 , int V_63 )
{
int V_44 ;
int V_100 = V_23 [ V_99 ] . V_18 ;
struct V_6 * V_111 = F_3 ( V_52 ) ;
if ( V_23 [ V_99 ] . V_21 != V_63 )
F_48 ( V_74 L_11 ) ;
if ( F_71 ( V_100 , V_97 ) ) {
V_44 = V_23 [ V_99 ] . V_19 ;
} else {
T_3 V_112 = V_111 -> V_113 + V_63 ;
if ( V_112 >= V_114 )
V_44 = V_112 ;
else
V_44 = V_115 + V_112 ;
}
#ifdef F_85
if ( ( V_63 >= 16 ) && ( V_63 <= 23 ) ) {
if ( V_93 [ V_63 - 16 ] != - 1 ) {
if ( ! V_93 [ V_63 - 16 ] ) {
F_8 ( V_15 , V_92
L_12 , V_63 - 16 ) ;
} else {
V_44 = V_93 [ V_63 - 16 ] ;
F_8 ( V_15 , V_92
L_13 ,
V_63 - 16 , V_44 ) ;
}
}
}
#endif
return V_44 ;
}
int F_86 ( int V_100 , int V_116 , int V_63 ,
struct V_117 * V_118 )
{
int V_52 , V_14 , V_119 = - 1 ;
F_8 ( V_120 ,
L_14 ,
V_100 , V_116 , V_63 ) ;
if ( F_71 ( V_100 , V_97 ) ) {
F_8 ( V_15 ,
L_15 , V_100 ) ;
return - 1 ;
}
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ ) {
int V_96 = V_23 [ V_14 ] . V_18 ;
for ( V_52 = 0 ; V_52 < V_35 ; V_52 ++ )
if ( F_1 ( V_52 ) == V_23 [ V_14 ] . V_20 ||
V_23 [ V_14 ] . V_20 == V_95 )
break;
if ( ! F_71 ( V_96 , V_97 ) &&
! V_23 [ V_14 ] . V_16 &&
( V_100 == V_96 ) &&
( V_116 == ( ( V_23 [ V_14 ] . V_19 >> 2 ) & 0x1f ) ) ) {
int V_44 = F_84 ( V_14 , V_52 , V_23 [ V_14 ] . V_21 ) ;
if ( ! ( V_52 || F_87 ( V_44 ) ) )
continue;
if ( V_63 == ( V_23 [ V_14 ] . V_19 & 3 ) ) {
F_88 ( V_118 , V_52 ,
V_23 [ V_14 ] . V_21 ,
F_78 ( V_14 ) ,
F_75 ( V_14 ) ) ;
return V_44 ;
}
if ( V_119 < 0 ) {
F_88 ( V_118 , V_52 ,
V_23 [ V_14 ] . V_21 ,
F_78 ( V_14 ) ,
F_75 ( V_14 ) ) ;
V_119 = V_44 ;
}
}
}
return V_119 ;
}
void F_89 ( void )
{
F_90 ( & V_121 ) ;
}
void F_91 ( void )
{
F_92 ( & V_121 ) ;
}
static int
F_93 ( int V_44 , struct V_28 * V_29 , const struct V_122 * V_70 )
{
static int V_123 = V_124 + V_125 ;
static int V_126 = V_125 % 8 ;
unsigned int V_127 ;
int V_128 , V_94 ;
T_4 V_129 ;
if ( V_29 -> V_130 )
return - V_131 ;
if ( ! F_94 ( & V_129 , V_132 ) )
return - V_75 ;
V_127 = V_29 -> V_42 ;
if ( V_127 ) {
F_95 ( V_129 , V_70 , V_133 ) ;
F_95 ( V_129 , V_29 -> V_40 , V_129 ) ;
if ( ! F_96 ( V_129 ) ) {
F_23 ( V_129 ) ;
return 0 ;
}
}
V_94 = - V_134 ;
F_97 (cpu, mask, cpu_online_mask) {
int V_135 ;
int V_42 , V_136 ;
V_52 -> V_137 ( V_128 , V_129 ) ;
V_42 = V_123 ;
V_136 = V_126 ;
V_73:
V_42 += 8 ;
if ( V_42 >= V_138 ) {
V_136 = ( V_136 + 1 ) % 8 ;
V_42 = V_124 + V_136 ;
}
if ( F_98 ( V_123 == V_42 ) )
continue;
if ( F_71 ( V_42 , V_139 ) )
goto V_73;
F_97 (new_cpu, tmp_mask, cpu_online_mask)
if ( F_99 ( V_140 , V_135 ) [ V_42 ] != - 1 )
goto V_73;
V_123 = V_42 ;
V_126 = V_136 ;
if ( V_127 ) {
V_29 -> V_130 = 1 ;
F_100 ( V_29 -> V_41 , V_29 -> V_40 ) ;
}
F_97 (new_cpu, tmp_mask, cpu_online_mask)
F_99 ( V_140 , V_135 ) [ V_42 ] = V_44 ;
V_29 -> V_42 = V_42 ;
F_100 ( V_29 -> V_40 , V_129 ) ;
V_94 = 0 ;
break;
}
F_23 ( V_129 ) ;
return V_94 ;
}
int F_101 ( int V_44 , struct V_28 * V_29 , const struct V_122 * V_70 )
{
int V_94 ;
unsigned long V_61 ;
F_40 ( & V_121 , V_61 ) ;
V_94 = F_93 ( V_44 , V_29 , V_70 ) ;
F_42 ( & V_121 , V_61 ) ;
return V_94 ;
}
static void F_102 ( int V_44 , struct V_28 * V_29 )
{
int V_128 , V_42 ;
F_103 ( ! V_29 -> V_42 ) ;
V_42 = V_29 -> V_42 ;
F_97 (cpu, cfg->domain, cpu_online_mask)
F_99 ( V_140 , V_128 ) [ V_42 ] = - 1 ;
V_29 -> V_42 = 0 ;
F_104 ( V_29 -> V_40 ) ;
if ( F_105 ( ! V_29 -> V_130 ) )
return;
F_97 (cpu, cfg->old_domain, cpu_online_mask) {
for ( V_42 = V_124 ; V_42 < V_141 ;
V_42 ++ ) {
if ( F_99 ( V_140 , V_128 ) [ V_42 ] != V_44 )
continue;
F_99 ( V_140 , V_128 ) [ V_42 ] = - 1 ;
break;
}
}
V_29 -> V_130 = 0 ;
}
void F_106 ( int V_128 )
{
int V_44 , V_42 ;
struct V_28 * V_29 ;
F_90 ( & V_121 ) ;
F_107 (irq) {
V_29 = F_21 ( V_44 ) ;
if ( ! V_29 )
continue;
if ( V_44 < V_31 -> V_32 && ! F_87 ( V_44 ) )
F_20 ( V_128 , V_29 -> V_40 ) ;
if ( ! F_108 ( V_128 , V_29 -> V_40 ) )
continue;
V_42 = V_29 -> V_42 ;
F_99 ( V_140 , V_128 ) [ V_42 ] = V_44 ;
}
for ( V_42 = 0 ; V_42 < V_141 ; ++ V_42 ) {
V_44 = F_99 ( V_140 , V_128 ) [ V_42 ] ;
if ( V_44 < 0 )
continue;
V_29 = V_28 ( V_44 ) ;
if ( ! F_108 ( V_128 , V_29 -> V_40 ) )
F_99 ( V_140 , V_128 ) [ V_42 ] = - 1 ;
}
F_92 ( & V_121 ) ;
}
static inline int F_109 ( int V_44 )
{
int V_52 , V_99 , V_63 ;
for ( V_52 = 0 ; V_52 < V_35 ; V_52 ++ ) {
for ( V_63 = 0 ; V_63 < V_2 [ V_52 ] . V_38 ; V_63 ++ ) {
V_99 = F_69 ( V_52 , V_63 , V_142 ) ;
if ( ( V_99 != - 1 ) && ( V_44 == F_84 ( V_99 , V_52 , V_63 ) ) )
return F_78 ( V_99 ) ;
}
}
return 0 ;
}
static inline int F_109 ( int V_44 )
{
return 1 ;
}
static void F_110 ( unsigned int V_44 , struct V_28 * V_29 ,
unsigned long V_103 )
{
struct V_143 * V_144 = & V_145 ;
T_5 V_146 ;
bool V_147 ;
if ( ( V_103 == V_148 && F_109 ( V_44 ) ) ||
V_103 == V_149 ) {
F_111 ( V_44 , V_150 ) ;
V_147 = true ;
} else {
F_112 ( V_44 , V_150 ) ;
V_147 = false ;
}
if ( F_113 ( V_29 ) ) {
F_111 ( V_44 , V_151 ) ;
V_144 = & V_152 ;
V_147 = V_103 != 0 ;
}
V_146 = V_147 ? V_153 : V_154 ;
F_114 ( V_44 , V_144 , V_146 ,
V_147 ? L_16 : L_17 ) ;
}
static int F_115 ( int V_155 , int V_44 ,
struct V_37 * V_60 ,
unsigned int V_156 , int V_103 ,
int V_101 , int V_42 , int V_63 )
{
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
if ( V_157 ) {
struct V_158 * V_159 = F_116 ( V_155 ) ;
struct V_160 V_160 ;
struct V_161 * V_162 =
(struct V_161 * ) V_60 ;
int V_56 ;
if ( ! V_159 )
F_9 ( L_18 , V_155 ) ;
V_56 = F_117 ( V_159 , V_44 , 1 ) ;
if ( V_56 < 0 )
F_9 ( L_19 , V_155 ) ;
F_118 ( & V_160 , V_42 , V_156 ) ;
F_119 ( & V_160 , V_155 ) ;
F_120 ( V_44 , & V_160 ) ;
V_162 -> V_163 = ( V_56 >> 15 ) & 0x1 ;
V_162 -> V_164 = 0 ;
V_162 -> V_165 = 1 ;
V_162 -> V_56 = ( V_56 & 0x7fff ) ;
V_162 -> V_42 = V_63 ;
F_8 ( V_15 , V_92 L_20
L_21
L_22
L_23
L_24 ,
V_155 , V_160 . V_166 , V_160 . V_167 , V_160 . V_168 ,
V_160 . V_169 , V_160 . V_170 , V_160 . V_171 ,
V_160 . V_172 , V_160 . V_42 , V_160 . V_173 ,
V_160 . V_174 , V_160 . V_175 , V_160 . V_176 ) ;
} else {
V_60 -> V_86 = V_52 -> V_177 ;
V_60 -> V_178 = V_52 -> V_179 ;
V_60 -> V_180 = V_156 ;
V_60 -> V_42 = V_42 ;
}
V_60 -> V_70 = 0 ;
V_60 -> V_103 = V_103 ;
V_60 -> V_101 = V_101 ;
if ( V_103 )
V_60 -> V_70 = 1 ;
return 0 ;
}
static void F_121 ( int V_155 , int V_63 , unsigned int V_44 ,
struct V_28 * V_29 , int V_103 , int V_101 )
{
struct V_37 V_60 ;
unsigned int V_180 ;
if ( ! F_87 ( V_44 ) )
return;
if ( V_44 < V_31 -> V_32 && F_108 ( 0 , V_29 -> V_40 ) )
V_52 -> V_137 ( 0 , V_29 -> V_40 ) ;
if ( F_101 ( V_44 , V_29 , V_52 -> V_181 () ) )
return;
V_180 = V_52 -> V_182 ( V_29 -> V_40 , V_52 -> V_181 () ) ;
F_8 ( V_15 , V_92
L_25
L_26 ,
V_155 , F_1 ( V_155 ) , V_63 , V_29 -> V_42 ,
V_44 , V_103 , V_101 , V_180 ) ;
if ( F_115 ( F_1 ( V_155 ) , V_44 , & V_60 ,
V_180 , V_103 , V_101 , V_29 -> V_42 , V_63 ) ) {
F_48 ( L_27 ,
F_1 ( V_155 ) , V_63 ) ;
F_102 ( V_44 , V_29 ) ;
return;
}
F_110 ( V_44 , V_29 , V_103 ) ;
if ( V_44 < V_31 -> V_32 )
V_31 -> V_70 ( V_44 ) ;
F_45 ( V_155 , V_63 , V_60 ) ;
}
static bool T_1 F_122 ( int V_99 , int V_155 , int V_63 )
{
if ( V_99 != - 1 )
return false ;
F_8 ( V_15 , V_92 L_28 ,
F_1 ( V_155 ) , V_63 ) ;
return true ;
}
static void T_1 F_123 ( unsigned int V_155 )
{
int V_99 , V_26 = F_16 ( 0 ) ;
struct V_117 V_183 ;
unsigned int V_63 , V_44 ;
for ( V_63 = 0 ; V_63 < V_2 [ V_155 ] . V_38 ; V_63 ++ ) {
V_99 = F_69 ( V_155 , V_63 , V_142 ) ;
if ( F_122 ( V_99 , V_155 , V_63 ) )
continue;
V_44 = F_84 ( V_99 , V_155 , V_63 ) ;
if ( ( V_155 > 0 ) && ( V_44 > 16 ) )
continue;
if ( V_52 -> V_184 &&
V_52 -> V_184 ( V_155 , V_44 ) )
continue;
F_88 ( & V_183 , V_155 , V_63 , F_78 ( V_99 ) ,
F_75 ( V_99 ) ) ;
F_124 ( V_44 , V_26 , & V_183 ) ;
}
}
static void T_1 F_125 ( void )
{
unsigned int V_155 ;
F_8 ( V_15 , V_92 L_29 ) ;
for ( V_155 = 0 ; V_155 < V_35 ; V_155 ++ )
F_123 ( V_155 ) ;
}
void F_126 ( T_3 V_112 )
{
int V_155 = 0 , V_63 , V_99 , V_44 , V_26 = F_16 ( 0 ) ;
struct V_117 V_183 ;
V_155 = F_127 ( V_112 ) ;
if ( V_155 < 0 )
return;
V_63 = F_128 ( V_155 , V_112 ) ;
V_99 = F_69 ( V_155 , V_63 , V_142 ) ;
if ( V_99 == - 1 )
return;
V_44 = F_84 ( V_99 , V_155 , V_63 ) ;
if ( V_155 == 0 || V_44 < V_114 )
return;
F_88 ( & V_183 , V_155 , V_63 , F_78 ( V_99 ) ,
F_75 ( V_99 ) ) ;
F_129 ( V_44 , V_26 , & V_183 ) ;
}
static void T_1 F_130 ( unsigned int V_155 , unsigned int V_63 ,
int V_42 )
{
struct V_37 V_60 ;
if ( V_157 )
return;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_178 = V_52 -> V_179 ;
V_60 . V_70 = 0 ;
V_60 . V_180 = V_52 -> V_185 ( V_52 -> V_181 () ) ;
V_60 . V_86 = V_52 -> V_177 ;
V_60 . V_101 = 0 ;
V_60 . V_103 = 0 ;
V_60 . V_42 = V_42 ;
F_114 ( 0 , & V_145 , V_154 ,
L_17 ) ;
F_45 ( V_155 , V_63 , V_60 ) ;
}
static T_1 int F_131 ( char * V_186 )
{
int V_187 = - 1 ;
if ( strcmp ( V_186 , L_30 ) == 0 ) {
V_188 = V_189 ;
} else {
F_132 ( & V_186 , & V_187 ) ;
if ( V_187 >= 0 )
V_188 = V_187 ;
}
return 1 ;
}
void T_1 F_133 ( void )
{
int V_190 , V_191 ;
int V_52 ;
if ( ! V_31 -> V_32 )
return;
for( V_52 = 0 ; V_52 < V_35 ; V_52 ++ ) {
int V_63 ;
for ( V_63 = 0 ; V_63 < V_2 [ V_52 ] . V_38 ; V_63 ++ ) {
struct V_37 V_60 ;
V_60 = F_43 ( V_52 , V_63 ) ;
if ( ( V_60 . V_70 == 0 ) && ( V_60 . V_86 == V_192 ) ) {
V_193 . V_52 = V_52 ;
V_193 . V_63 = V_63 ;
goto V_194;
}
}
}
V_194:
V_191 = F_70 ( 0 , V_195 ) ;
V_190 = F_72 ( 0 , V_195 ) ;
if ( ( V_193 . V_63 == - 1 ) && ( V_191 >= 0 ) ) {
F_48 ( V_102 L_31 ) ;
V_193 . V_63 = V_191 ;
V_193 . V_52 = V_190 ;
}
if ( ( ( V_193 . V_52 != V_190 ) || ( V_193 . V_63 != V_191 ) ) &&
( V_191 >= 0 ) && ( V_193 . V_63 >= 0 ) )
{
F_48 ( V_102 L_32 ) ;
}
F_63 () ;
}
void F_134 ( void )
{
F_63 () ;
if ( ! V_31 -> V_32 )
return;
if ( V_193 . V_63 != - 1 && ! V_157 ) {
struct V_37 V_60 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_70 = 0 ;
V_60 . V_103 = 0 ;
V_60 . V_196 = 0 ;
V_60 . V_101 = 0 ;
V_60 . V_197 = 0 ;
V_60 . V_178 = 0 ;
V_60 . V_86 = V_192 ;
V_60 . V_42 = 0 ;
V_60 . V_180 = F_135 () ;
F_45 ( V_193 . V_52 , V_193 . V_63 , V_60 ) ;
}
if ( V_198 || F_136 () )
F_137 ( ! V_157 &&
V_193 . V_63 != - 1 ) ;
}
void T_1 F_138 ( void )
{
union V_199 V_200 ;
T_6 V_201 ;
int V_155 ;
int V_14 ;
unsigned char V_202 ;
unsigned long V_61 ;
V_52 -> V_203 ( & V_204 , & V_201 ) ;
for ( V_155 = 0 ; V_155 < V_35 ; V_155 ++ ) {
F_40 ( & V_62 , V_61 ) ;
V_200 . V_205 = F_35 ( V_155 , 0 ) ;
F_42 ( & V_62 , V_61 ) ;
V_202 = F_1 ( V_155 ) ;
if ( F_1 ( V_155 ) >= F_139 () ) {
F_48 ( V_74 L_33 ,
V_155 , F_1 ( V_155 ) ) ;
F_48 ( V_74 L_34 ,
V_200 . V_206 . V_207 ) ;
V_2 [ V_155 ] . V_3 . V_4 = V_200 . V_206 . V_207 ;
}
if ( V_52 -> V_208 ( & V_201 ,
F_1 ( V_155 ) ) ) {
F_48 ( V_74 L_35 ,
V_155 , F_1 ( V_155 ) ) ;
for ( V_14 = 0 ; V_14 < F_139 () ; V_14 ++ )
if ( ! F_140 ( V_14 , V_201 ) )
break;
if ( V_14 >= F_139 () )
F_9 ( L_36 ) ;
F_48 ( V_74 L_34 ,
V_14 ) ;
F_141 ( V_14 , V_201 ) ;
V_2 [ V_155 ] . V_3 . V_4 = V_14 ;
} else {
T_6 V_209 ;
V_52 -> V_210 ( F_1 ( V_155 ) ,
& V_209 ) ;
F_8 ( V_15 , L_37
L_38 ,
F_1 ( V_155 ) ) ;
F_142 ( V_201 , V_201 , V_209 ) ;
}
if ( V_202 != F_1 ( V_155 ) )
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ )
if ( V_23 [ V_14 ] . V_20 == V_202 )
V_23 [ V_14 ] . V_20
= F_1 ( V_155 ) ;
if ( F_1 ( V_155 ) == V_200 . V_206 . V_207 )
continue;
F_8 ( V_15 , V_91
L_39 ,
F_1 ( V_155 ) ) ;
V_200 . V_206 . V_207 = F_1 ( V_155 ) ;
F_40 ( & V_62 , V_61 ) ;
F_37 ( V_155 , 0 , V_200 . V_205 ) ;
F_42 ( & V_62 , V_61 ) ;
F_40 ( & V_62 , V_61 ) ;
V_200 . V_205 = F_35 ( V_155 , 0 ) ;
F_42 ( & V_62 , V_61 ) ;
if ( V_200 . V_206 . V_207 != F_1 ( V_155 ) )
F_48 ( L_40 ) ;
else
F_8 ( V_15 , L_41 ) ;
}
}
void T_1 F_143 ( void )
{
if ( V_211 )
return;
if ( ! ( V_212 . V_213 == V_214 )
|| F_144 ( V_215 [ V_216 ] ) )
return;
F_138 () ;
}
static int T_1 F_145 ( char * V_217 )
{
V_218 = 1 ;
return 1 ;
}
static int T_1 F_146 ( void )
{
unsigned long V_219 = V_220 ;
unsigned long V_61 ;
if ( V_218 )
return 1 ;
F_147 ( V_61 ) ;
F_148 () ;
F_149 ( ( 10 * 1000 ) / V_221 ) ;
F_150 ( V_61 ) ;
if ( F_151 ( V_220 , V_219 + 4 ) )
return 1 ;
return 0 ;
}
static unsigned int F_152 ( struct V_84 * V_57 )
{
int V_222 = 0 , V_44 = V_57 -> V_44 ;
unsigned long V_61 ;
F_40 ( & V_62 , V_61 ) ;
if ( V_44 < V_31 -> V_32 ) {
V_31 -> V_70 ( V_44 ) ;
if ( V_31 -> V_223 ( V_44 ) )
V_222 = 1 ;
}
F_59 ( V_57 -> V_85 ) ;
F_42 ( & V_62 , V_61 ) ;
return V_222 ;
}
static int F_153 ( struct V_84 * V_57 )
{
struct V_28 * V_29 = V_57 -> V_85 ;
unsigned long V_61 ;
F_40 ( & V_121 , V_61 ) ;
V_52 -> V_224 ( F_154 ( F_155 ( V_29 -> V_40 ) ) , V_29 -> V_42 ) ;
F_42 ( & V_121 , V_61 ) ;
return 1 ;
}
void F_156 ( struct V_28 * V_29 )
{
T_4 V_225 ;
if ( F_98 ( ! F_94 ( & V_225 , V_132 ) ) ) {
unsigned int V_14 ;
F_97 (i, cfg->old_domain, cpu_online_mask)
V_52 -> V_224 ( F_154 ( V_14 ) , V_226 ) ;
} else {
F_95 ( V_225 , V_29 -> V_41 , V_133 ) ;
V_52 -> V_224 ( V_225 , V_226 ) ;
F_23 ( V_225 ) ;
}
V_29 -> V_130 = 0 ;
}
static void F_157 ( unsigned int V_44 , unsigned int V_180 , struct V_28 * V_29 )
{
int V_52 , V_63 ;
struct V_25 * V_60 ;
T_7 V_42 = V_29 -> V_42 ;
F_41 (entry, cfg->irq_2_pin) {
unsigned int V_55 ;
V_52 = V_60 -> V_52 ;
V_63 = V_60 -> V_63 ;
if ( ! F_113 ( V_29 ) )
F_37 ( V_52 , 0x11 + V_63 * 2 , V_180 ) ;
V_55 = F_35 ( V_52 , 0x10 + V_63 * 2 ) ;
V_55 &= ~ V_227 ;
V_55 |= V_42 ;
F_38 ( V_52 , 0x10 + V_63 * 2 , V_55 ) ;
}
}
int F_158 ( struct V_84 * V_57 , const struct V_122 * V_70 ,
unsigned int * V_173 )
{
struct V_28 * V_29 = V_57 -> V_85 ;
if ( ! F_159 ( V_70 , V_133 ) )
return - 1 ;
if ( F_101 ( V_57 -> V_44 , V_57 -> V_85 , V_70 ) )
return - 1 ;
F_100 ( V_57 -> V_228 , V_70 ) ;
* V_173 = V_52 -> V_182 ( V_70 , V_29 -> V_40 ) ;
return 0 ;
}
static int
F_160 ( struct V_84 * V_57 , const struct V_122 * V_70 ,
bool V_229 )
{
unsigned int V_180 , V_44 = V_57 -> V_44 ;
unsigned long V_61 ;
int V_230 ;
F_40 ( & V_62 , V_61 ) ;
V_230 = F_158 ( V_57 , V_70 , & V_180 ) ;
if ( ! V_230 ) {
V_180 = F_161 ( V_180 ) ;
F_157 ( V_44 , V_180 , V_57 -> V_85 ) ;
}
F_42 ( & V_62 , V_61 ) ;
return V_230 ;
}
static int
F_162 ( struct V_84 * V_57 , const struct V_122 * V_70 ,
bool V_229 )
{
struct V_28 * V_29 = V_57 -> V_85 ;
unsigned int V_180 , V_44 = V_57 -> V_44 ;
struct V_160 V_160 ;
if ( ! F_159 ( V_70 , V_133 ) )
return - V_231 ;
if ( F_163 ( V_44 , & V_160 ) )
return - V_131 ;
if ( F_101 ( V_44 , V_29 , V_70 ) )
return - V_131 ;
V_180 = V_52 -> V_182 ( V_29 -> V_40 , V_70 ) ;
V_160 . V_42 = V_29 -> V_42 ;
V_160 . V_173 = F_164 ( V_180 ) ;
F_120 ( V_44 , & V_160 ) ;
if ( V_29 -> V_130 )
F_156 ( V_29 ) ;
F_100 ( V_57 -> V_228 , V_70 ) ;
return 0 ;
}
static inline int
F_162 ( struct V_84 * V_57 , const struct V_122 * V_70 ,
bool V_229 )
{
return 0 ;
}
T_8 void F_165 ( void )
{
unsigned V_42 , V_232 ;
F_166 () ;
F_167 () ;
F_168 () ;
V_232 = F_169 () ;
for ( V_42 = V_124 ; V_42 < V_141 ; V_42 ++ ) {
unsigned int V_44 ;
unsigned int V_196 ;
struct V_233 * V_234 ;
struct V_28 * V_29 ;
V_44 = F_170 ( V_140 [ V_42 ] ) ;
if ( V_44 == - 1 )
continue;
V_234 = F_171 ( V_44 ) ;
if ( ! V_234 )
continue;
V_29 = V_28 ( V_44 ) ;
F_90 ( & V_234 -> V_235 ) ;
if ( V_29 -> V_130 )
goto V_236;
if ( V_42 == V_29 -> V_42 && F_108 ( V_232 , V_29 -> V_40 ) )
goto V_236;
V_196 = F_172 ( V_237 + ( V_42 / 32 * 0x10 ) ) ;
if ( V_196 & ( 1 << ( V_42 % 32 ) ) ) {
V_52 -> V_238 ( V_226 ) ;
goto V_236;
}
F_173 ( V_140 [ V_42 ] , - 1 ) ;
V_236:
F_92 ( & V_234 -> V_235 ) ;
}
F_174 () ;
}
static void F_175 ( struct V_28 * V_29 , unsigned V_42 )
{
unsigned V_232 ;
if ( F_105 ( ! V_29 -> V_130 ) )
return;
V_232 = F_169 () ;
if ( V_42 == V_29 -> V_42 && F_108 ( V_232 , V_29 -> V_40 ) )
F_156 ( V_29 ) ;
}
static void F_176 ( struct V_28 * V_29 )
{
F_175 ( V_29 , ~ F_177 () -> V_239 ) ;
}
void F_178 ( int V_44 )
{
struct V_28 * V_29 = F_21 ( V_44 ) ;
if ( ! V_29 )
return;
F_175 ( V_29 , V_29 -> V_42 ) ;
}
static inline void F_176 ( struct V_28 * V_29 ) { }
static void F_179 ( struct V_84 * V_57 )
{
F_176 ( V_57 -> V_85 ) ;
F_180 ( V_57 ) ;
F_166 () ;
}
static void F_181 ( unsigned int V_44 , struct V_28 * V_29 )
{
struct V_25 * V_60 ;
unsigned long V_61 ;
F_40 ( & V_62 , V_61 ) ;
F_41 (entry, cfg->irq_2_pin) {
if ( F_182 ( V_60 -> V_52 ) >= 0x20 ) {
if ( F_113 ( V_29 ) )
F_32 ( V_60 -> V_52 , V_60 -> V_63 ) ;
else
F_32 ( V_60 -> V_52 , V_29 -> V_42 ) ;
} else {
F_54 ( V_60 ) ;
F_55 ( V_60 ) ;
}
}
F_42 ( & V_62 , V_61 ) ;
}
static void F_183 ( struct V_84 * V_57 )
{
struct V_28 * V_29 = V_57 -> V_85 ;
int V_14 , V_240 = 0 , V_44 = V_57 -> V_44 ;
unsigned long V_241 ;
F_176 ( V_29 ) ;
#ifdef F_184
if ( F_98 ( F_185 ( V_57 ) ) ) {
V_240 = 1 ;
F_57 ( V_29 ) ;
}
#endif
V_14 = V_29 -> V_42 ;
V_241 = F_172 ( V_242 + ( ( V_14 & ~ 0x1f ) >> 1 ) ) ;
F_166 () ;
if ( ! ( V_241 & ( 1 << ( V_14 & 0x1f ) ) ) ) {
F_186 ( & V_243 ) ;
F_181 ( V_44 , V_29 ) ;
}
if ( F_98 ( V_240 ) ) {
if ( ! F_39 ( V_29 ) )
F_187 ( V_57 ) ;
F_60 ( V_29 ) ;
}
}
static void F_188 ( struct V_84 * V_57 )
{
F_166 () ;
}
static void F_189 ( struct V_84 * V_57 )
{
F_166 () ;
F_181 ( V_57 -> V_44 , V_57 -> V_85 ) ;
}
static inline void F_190 ( void )
{
struct V_28 * V_29 ;
unsigned int V_44 ;
F_107 (irq) {
V_29 = F_21 ( V_44 ) ;
if ( F_87 ( V_44 ) && V_29 && ! V_29 -> V_42 ) {
if ( V_44 < V_31 -> V_32 )
V_31 -> V_244 ( V_44 ) ;
else
F_191 ( V_44 , & V_245 ) ;
}
}
}
static void F_192 ( struct V_84 * V_57 )
{
unsigned long V_241 ;
V_241 = F_172 ( V_246 ) ;
F_193 ( V_246 , V_241 | V_247 ) ;
}
static void F_194 ( struct V_84 * V_57 )
{
unsigned long V_241 ;
V_241 = F_172 ( V_246 ) ;
F_193 ( V_246 , V_241 & ~ V_247 ) ;
}
static void F_195 ( struct V_84 * V_57 )
{
F_166 () ;
}
static void F_196 ( int V_44 )
{
F_112 ( V_44 , V_150 ) ;
F_114 ( V_44 , & V_248 , V_154 ,
L_17 ) ;
}
static inline void T_1 F_197 ( void )
{
int V_52 , V_63 , V_14 ;
struct V_37 V_249 , V_250 ;
unsigned char V_251 , V_252 ;
V_63 = F_70 ( 8 , V_142 ) ;
if ( V_63 == - 1 ) {
F_198 ( 1 ) ;
return;
}
V_52 = F_72 ( 8 , V_142 ) ;
if ( V_52 == - 1 ) {
F_198 ( 1 ) ;
return;
}
V_249 = F_43 ( V_52 , V_63 ) ;
F_62 ( V_52 , V_63 ) ;
memset ( & V_250 , 0 , sizeof( V_250 ) ) ;
V_250 . V_178 = 0 ;
V_250 . V_70 = 0 ;
V_250 . V_180 = F_199 () ;
V_250 . V_86 = V_192 ;
V_250 . V_101 = V_249 . V_101 ;
V_250 . V_103 = 0 ;
V_250 . V_42 = 0 ;
F_45 ( V_52 , V_63 , V_250 ) ;
V_251 = F_200 ( V_253 ) ;
V_252 = F_200 ( V_254 ) ;
F_201 ( ( V_252 & ~ V_255 ) | 0x6 ,
V_254 ) ;
F_201 ( V_251 | V_256 , V_253 ) ;
V_14 = 100 ;
while ( V_14 -- > 0 ) {
F_149 ( 10 ) ;
if ( ( F_200 ( V_257 ) & V_258 ) == V_258 )
V_14 -= 10 ;
}
F_201 ( V_251 , V_253 ) ;
F_201 ( V_252 , V_254 ) ;
F_62 ( V_52 , V_63 ) ;
F_45 ( V_52 , V_63 , V_249 ) ;
}
static int T_1 F_202 ( char * V_186 )
{
V_259 = 1 ;
return 0 ;
}
static inline void T_1 F_203 ( void )
{
struct V_28 * V_29 = F_21 ( 0 ) ;
int V_26 = F_16 ( 0 ) ;
int V_260 , V_261 , V_262 , V_263 ;
unsigned long V_61 ;
int V_264 = 0 ;
F_204 ( V_61 ) ;
V_31 -> V_70 ( 0 ) ;
F_101 ( 0 , V_29 , V_52 -> V_181 () ) ;
F_193 ( V_246 , V_247 | V_265 ) ;
V_31 -> V_266 ( 1 ) ;
V_261 = F_70 ( 0 , V_142 ) ;
V_260 = F_72 ( 0 , V_142 ) ;
V_263 = V_193 . V_63 ;
V_262 = V_193 . V_52 ;
F_8 ( V_267 , V_91 L_42
L_43 ,
V_29 -> V_42 , V_260 , V_261 , V_262 , V_263 ) ;
if ( V_261 == - 1 ) {
if ( V_157 )
F_9 ( L_44 ) ;
V_261 = V_263 ;
V_260 = V_262 ;
V_264 = 1 ;
} else if ( V_263 == - 1 ) {
V_263 = V_261 ;
V_262 = V_260 ;
}
if ( V_261 != - 1 ) {
if ( V_264 ) {
F_49 ( V_29 , V_26 , V_260 , V_261 ) ;
F_130 ( V_260 , V_261 , V_29 -> V_42 ) ;
} else {
int V_99 ;
V_99 = F_69 ( V_260 , V_261 , V_142 ) ;
if ( V_99 != - 1 && F_78 ( V_99 ) )
F_60 ( V_29 ) ;
}
if ( F_146 () ) {
if ( V_259 > 0 )
F_62 ( 0 , V_261 ) ;
goto V_268;
}
if ( V_157 )
F_9 ( L_45 ) ;
F_205 () ;
F_62 ( V_260 , V_261 ) ;
if ( ! V_264 )
F_8 ( V_267 , V_74 L_46
L_47 ) ;
F_8 ( V_267 , V_91 L_48
L_49 ) ;
F_8 ( V_267 , V_91
L_50 , V_262 , V_263 ) ;
F_50 ( V_29 , V_26 , V_260 , V_261 , V_262 , V_263 ) ;
F_130 ( V_262 , V_263 , V_29 -> V_42 ) ;
V_31 -> V_269 ( 0 ) ;
if ( F_146 () ) {
F_8 ( V_267 , V_91 L_51 ) ;
V_270 = 1 ;
goto V_268;
}
F_205 () ;
V_31 -> V_70 ( 0 ) ;
F_62 ( V_262 , V_263 ) ;
F_8 ( V_267 , V_91 L_52 ) ;
}
F_8 ( V_267 , V_91
L_53 ) ;
F_196 ( 0 ) ;
F_193 ( V_246 , V_271 | V_29 -> V_42 ) ;
V_31 -> V_269 ( 0 ) ;
if ( F_146 () ) {
F_8 ( V_267 , V_91 L_54 ) ;
goto V_268;
}
F_205 () ;
V_31 -> V_70 ( 0 ) ;
F_193 ( V_246 , V_247 | V_271 | V_29 -> V_42 ) ;
F_8 ( V_267 , V_91 L_55 ) ;
F_8 ( V_267 , V_91
L_56 ) ;
V_31 -> V_266 ( 0 ) ;
V_31 -> V_244 ( 0 ) ;
F_193 ( V_246 , V_265 ) ;
F_197 () ;
if ( F_146 () ) {
F_8 ( V_267 , V_91 L_54 ) ;
goto V_268;
}
F_205 () ;
F_8 ( V_267 , V_91 L_57 ) ;
F_9 ( L_58
L_59 ) ;
V_268:
F_150 ( V_61 ) ;
}
void T_1 F_206 ( void )
{
V_34 = V_31 -> V_32 ? ~ V_272 : ~ 0UL ;
F_8 ( V_15 , L_60 ) ;
V_273 . V_274 . V_275 () ;
F_207 () ;
F_125 () ;
F_190 () ;
if ( V_31 -> V_32 )
F_203 () ;
}
static int T_1 F_208 ( void )
{
if ( V_59 == - 1 )
V_59 = 0 ;
return 0 ;
}
static void F_209 ( int V_276 )
{
unsigned long V_61 ;
union V_199 V_200 ;
F_40 ( & V_62 , V_61 ) ;
V_200 . V_205 = F_35 ( V_276 , 0 ) ;
if ( V_200 . V_206 . V_207 != F_1 ( V_276 ) ) {
V_200 . V_206 . V_207 = F_1 ( V_276 ) ;
F_37 ( V_276 , 0 , V_200 . V_205 ) ;
}
F_42 ( & V_62 , V_61 ) ;
}
static void F_210 ( void )
{
int V_276 ;
for ( V_276 = V_35 - 1 ; V_276 >= 0 ; V_276 -- )
F_209 ( V_276 ) ;
F_68 () ;
}
static int T_1 F_211 ( void )
{
F_212 ( & V_277 ) ;
return 0 ;
}
unsigned int F_213 ( unsigned int V_51 , int V_26 )
{
struct V_28 * V_29 ;
unsigned long V_61 ;
unsigned int V_230 = 0 ;
int V_44 ;
if ( V_51 < V_33 )
V_51 = V_33 ;
V_44 = F_29 ( V_51 , V_26 ) ;
if ( V_44 < 0 )
return 0 ;
V_29 = F_22 ( V_44 , V_26 ) ;
if ( ! V_29 ) {
F_31 ( V_44 , NULL ) ;
return 0 ;
}
F_40 ( & V_121 , V_61 ) ;
if ( ! F_93 ( V_44 , V_29 , V_52 -> V_181 () ) )
V_230 = V_44 ;
F_42 ( & V_121 , V_61 ) ;
if ( V_230 ) {
F_18 ( V_44 , V_29 ) ;
F_112 ( V_44 , V_278 ) ;
} else {
F_31 ( V_44 , V_29 ) ;
}
return V_230 ;
}
int F_214 ( void )
{
int V_26 = F_16 ( 0 ) ;
unsigned int V_279 ;
int V_44 ;
V_279 = V_33 ;
V_44 = F_213 ( V_279 , V_26 ) ;
if ( V_44 == 0 )
V_44 = - 1 ;
return V_44 ;
}
void F_215 ( unsigned int V_44 )
{
struct V_28 * V_29 = F_21 ( V_44 ) ;
unsigned long V_61 ;
F_111 ( V_44 , V_278 | V_280 ) ;
if ( F_113 ( V_29 ) )
F_216 ( V_44 ) ;
F_40 ( & V_121 , V_61 ) ;
F_102 ( V_44 , V_29 ) ;
F_42 ( & V_121 , V_61 ) ;
F_31 ( V_44 , V_29 ) ;
}
static int F_217 ( struct V_281 * V_282 , unsigned int V_44 ,
struct V_283 * V_284 , T_7 V_285 )
{
struct V_28 * V_29 ;
int V_94 ;
unsigned V_180 ;
if ( V_286 )
return - V_287 ;
V_29 = V_28 ( V_44 ) ;
V_94 = F_101 ( V_44 , V_29 , V_52 -> V_181 () ) ;
if ( V_94 )
return V_94 ;
V_180 = V_52 -> V_182 ( V_29 -> V_40 , V_52 -> V_181 () ) ;
if ( F_113 ( V_29 ) ) {
struct V_160 V_160 ;
int V_288 ;
T_9 V_289 ;
V_288 = F_218 ( V_44 , & V_289 ) ;
F_103 ( V_288 == - 1 ) ;
F_118 ( & V_160 , V_29 -> V_42 , V_180 ) ;
if ( V_282 )
F_219 ( & V_160 , V_282 ) ;
else
F_220 ( & V_160 , V_285 ) ;
F_120 ( V_44 , & V_160 ) ;
V_284 -> V_290 = V_291 ;
V_284 -> V_57 = V_289 ;
V_284 -> V_292 = V_293 | V_294 |
V_295 |
F_221 ( V_288 ) |
F_222 ( V_288 ) ;
} else {
if ( F_223 () )
V_284 -> V_290 = V_291 |
F_224 ( V_180 ) ;
else
V_284 -> V_290 = V_291 ;
V_284 -> V_292 =
V_293 |
( ( V_52 -> V_179 == 0 ) ?
V_296 :
V_297 ) |
( ( V_52 -> V_177 != V_298 ) ?
V_299 :
V_300 ) |
F_225 ( V_180 ) ;
V_284 -> V_57 =
V_301 |
V_302 |
( ( V_52 -> V_177 != V_298 ) ?
V_303 :
V_304 ) |
F_226 ( V_29 -> V_42 ) ;
}
return V_94 ;
}
static int
F_227 ( struct V_84 * V_57 , const struct V_122 * V_70 , bool V_229 )
{
struct V_28 * V_29 = V_57 -> V_85 ;
struct V_283 V_284 ;
unsigned int V_180 ;
if ( F_158 ( V_57 , V_70 , & V_180 ) )
return - 1 ;
F_228 ( V_57 -> V_305 , & V_284 ) ;
V_284 . V_57 &= ~ V_306 ;
V_284 . V_57 |= F_226 ( V_29 -> V_42 ) ;
V_284 . V_292 &= ~ V_307 ;
V_284 . V_292 |= F_225 ( V_180 ) ;
F_229 ( V_57 -> V_305 , & V_284 ) ;
return 0 ;
}
static int
F_230 ( struct V_84 * V_57 , const struct V_122 * V_70 ,
bool V_229 )
{
struct V_28 * V_29 = V_57 -> V_85 ;
unsigned int V_180 , V_44 = V_57 -> V_44 ;
struct V_160 V_160 ;
if ( F_163 ( V_44 , & V_160 ) )
return - 1 ;
if ( F_158 ( V_57 , V_70 , & V_180 ) )
return - 1 ;
V_160 . V_42 = V_29 -> V_42 ;
V_160 . V_173 = F_164 ( V_180 ) ;
F_120 ( V_44 , & V_160 ) ;
if ( V_29 -> V_130 )
F_156 ( V_29 ) ;
return 0 ;
}
static int F_231 ( struct V_281 * V_308 , int V_44 , int V_309 )
{
struct V_158 * V_159 ;
int V_56 ;
V_159 = F_232 ( V_308 ) ;
if ( ! V_159 ) {
F_48 ( V_74
L_61 , F_233 ( V_308 ) ) ;
return - V_310 ;
}
V_56 = F_117 ( V_159 , V_44 , V_309 ) ;
if ( V_56 < 0 ) {
F_48 ( V_74
L_62 , V_309 ,
F_233 ( V_308 ) ) ;
return - V_134 ;
}
return V_56 ;
}
static int F_234 ( struct V_281 * V_308 , struct V_305 * V_311 , int V_44 )
{
struct V_143 * V_144 = & V_312 ;
struct V_283 V_284 ;
int V_230 ;
V_230 = F_217 ( V_308 , V_44 , & V_284 , - 1 ) ;
if ( V_230 < 0 )
return V_230 ;
F_235 ( V_44 , V_311 ) ;
F_236 ( V_44 , & V_284 ) ;
if ( F_113 ( F_21 ( V_44 ) ) ) {
F_111 ( V_44 , V_151 ) ;
V_144 = & V_313 ;
}
F_114 ( V_44 , V_144 , V_154 , L_17 ) ;
F_237 ( V_92 , & V_308 -> V_308 , L_63 , V_44 ) ;
return 0 ;
}
int F_238 ( struct V_281 * V_308 , int V_309 , int type )
{
int V_26 , V_230 , V_289 , V_56 = 0 ;
unsigned int V_44 , V_279 ;
struct V_305 * V_311 ;
struct V_158 * V_159 = NULL ;
if ( type == V_314 && V_309 > 1 )
return 1 ;
V_26 = F_239 ( & V_308 -> V_308 ) ;
V_279 = V_33 ;
V_289 = 0 ;
F_240 (msidesc, &dev->msi_list, list) {
V_44 = F_213 ( V_279 , V_26 ) ;
if ( V_44 == 0 )
return - 1 ;
V_279 = V_44 + 1 ;
if ( ! V_157 )
goto V_315;
if ( ! V_289 ) {
V_56 = F_231 ( V_308 , V_44 , V_309 ) ;
if ( V_56 < 0 ) {
V_230 = V_56 ;
goto error;
}
} else {
V_159 = F_232 ( V_308 ) ;
if ( ! V_159 ) {
V_230 = - V_310 ;
goto error;
}
F_241 ( V_44 , V_159 , V_56 , V_289 ) ;
}
V_315:
V_230 = F_234 ( V_308 , V_311 , V_44 ) ;
if ( V_230 < 0 )
goto error;
V_289 ++ ;
}
return 0 ;
error:
F_215 ( V_44 ) ;
return V_230 ;
}
void F_242 ( unsigned int V_44 )
{
F_215 ( V_44 ) ;
}
static int
F_243 ( struct V_84 * V_57 , const struct V_122 * V_70 ,
bool V_229 )
{
struct V_28 * V_29 = V_57 -> V_85 ;
unsigned int V_180 , V_44 = V_57 -> V_44 ;
struct V_283 V_284 ;
if ( F_158 ( V_57 , V_70 , & V_180 ) )
return - 1 ;
F_244 ( V_44 , & V_284 ) ;
V_284 . V_57 &= ~ V_306 ;
V_284 . V_57 |= F_226 ( V_29 -> V_42 ) ;
V_284 . V_292 &= ~ V_307 ;
V_284 . V_292 |= F_225 ( V_180 ) ;
V_284 . V_290 = V_291 | F_224 ( V_180 ) ;
F_245 ( V_44 , & V_284 ) ;
return 0 ;
}
int F_246 ( unsigned int V_44 )
{
int V_230 ;
struct V_283 V_284 ;
V_230 = F_217 ( NULL , V_44 , & V_284 , - 1 ) ;
if ( V_230 < 0 )
return V_230 ;
F_245 ( V_44 , & V_284 ) ;
F_114 ( V_44 , & V_316 , V_154 ,
L_17 ) ;
return 0 ;
}
static int F_247 ( struct V_84 * V_57 ,
const struct V_122 * V_70 , bool V_229 )
{
struct V_28 * V_29 = V_57 -> V_85 ;
struct V_283 V_284 ;
unsigned int V_180 ;
if ( F_158 ( V_57 , V_70 , & V_180 ) )
return - 1 ;
F_248 ( V_57 -> V_317 , & V_284 ) ;
V_284 . V_57 &= ~ V_306 ;
V_284 . V_57 |= F_226 ( V_29 -> V_42 ) ;
V_284 . V_292 &= ~ V_307 ;
V_284 . V_292 |= F_225 ( V_180 ) ;
F_249 ( V_57 -> V_317 , & V_284 ) ;
return 0 ;
}
int F_250 ( unsigned int V_44 , unsigned int V_1 )
{
struct V_143 * V_144 = & V_318 ;
struct V_283 V_284 ;
int V_230 ;
if ( V_157 ) {
struct V_158 * V_159 = F_251 ( V_1 ) ;
int V_56 ;
if ( ! V_159 )
return - 1 ;
V_56 = F_117 ( V_159 , V_44 , 1 ) ;
if ( V_56 < 0 )
return - 1 ;
}
V_230 = F_217 ( NULL , V_44 , & V_284 , V_1 ) ;
if ( V_230 < 0 )
return V_230 ;
F_249 ( F_252 ( V_44 ) , & V_284 ) ;
F_111 ( V_44 , V_151 ) ;
if ( F_113 ( F_21 ( V_44 ) ) )
V_144 = & V_319 ;
F_114 ( V_44 , V_144 , V_154 , L_17 ) ;
return 0 ;
}
static void F_253 ( unsigned int V_44 , unsigned int V_180 , T_7 V_42 )
{
struct V_320 V_284 ;
F_254 ( V_44 , & V_284 ) ;
V_284 . V_292 &= ~ ( V_321 | V_322 ) ;
V_284 . V_290 &= ~ ( V_323 ) ;
V_284 . V_292 |= F_255 ( V_42 ) | F_256 ( V_180 ) ;
V_284 . V_290 |= F_257 ( V_180 ) ;
F_258 ( V_44 , & V_284 ) ;
}
static int
F_259 ( struct V_84 * V_57 , const struct V_122 * V_70 , bool V_229 )
{
struct V_28 * V_29 = V_57 -> V_85 ;
unsigned int V_180 ;
if ( F_158 ( V_57 , V_70 , & V_180 ) )
return - 1 ;
F_253 ( V_57 -> V_44 , V_180 , V_29 -> V_42 ) ;
return 0 ;
}
int F_260 ( unsigned int V_44 , struct V_281 * V_308 )
{
struct V_28 * V_29 ;
int V_94 ;
if ( V_286 )
return - V_287 ;
V_29 = V_28 ( V_44 ) ;
V_94 = F_101 ( V_44 , V_29 , V_52 -> V_181 () ) ;
if ( ! V_94 ) {
struct V_320 V_284 ;
unsigned V_180 ;
V_180 = V_52 -> V_182 ( V_29 -> V_40 ,
V_52 -> V_181 () ) ;
V_284 . V_290 = F_257 ( V_180 ) ;
V_284 . V_292 =
V_324 |
F_256 ( V_180 ) |
F_255 ( V_29 -> V_42 ) |
( ( V_52 -> V_179 == 0 ) ?
V_325 :
V_326 ) |
V_327 |
( ( V_52 -> V_177 != V_298 ) ?
V_328 :
V_329 ) |
V_330 ;
F_258 ( V_44 , & V_284 ) ;
F_114 ( V_44 , & V_331 ,
V_154 , L_17 ) ;
F_237 ( V_92 , & V_308 -> V_308 , L_64 , V_44 ) ;
}
return V_94 ;
}
static int
F_124 ( unsigned int V_44 , int V_26 , struct V_117 * V_183 )
{
struct V_28 * V_29 = F_26 ( V_44 , V_26 ) ;
int V_230 ;
if ( ! V_29 )
return - V_231 ;
V_230 = F_47 ( V_29 , V_26 , V_183 -> V_332 , V_183 -> V_333 ) ;
if ( ! V_230 )
F_121 ( V_183 -> V_332 , V_183 -> V_333 , V_44 , V_29 ,
V_183 -> V_103 , V_183 -> V_101 ) ;
return V_230 ;
}
int F_129 ( unsigned int V_44 , int V_26 ,
struct V_117 * V_183 )
{
unsigned int V_1 = V_183 -> V_332 , V_63 = V_183 -> V_333 ;
int V_230 ;
if ( F_71 ( V_63 , V_2 [ V_1 ] . V_334 ) ) {
F_261 ( L_65 ,
F_1 ( V_1 ) , V_63 ) ;
return 0 ;
}
V_230 = F_124 ( V_44 , V_26 , V_183 ) ;
if ( ! V_230 )
F_262 ( V_63 , V_2 [ V_1 ] . V_334 ) ;
return V_230 ;
}
static int T_1 F_263 ( int V_332 )
{
union V_335 V_336 ;
unsigned long V_61 ;
F_40 ( & V_62 , V_61 ) ;
V_336 . V_205 = F_35 ( V_332 , 1 ) ;
F_42 ( & V_62 , V_61 ) ;
return V_336 . V_206 . V_337 + 1 ;
}
static void T_1 F_264 ( void )
{
int V_338 ;
V_338 = V_115 + V_114 ;
if ( V_338 > V_33 )
V_33 = V_338 ;
F_48 ( V_92 L_66 , V_33 ) ;
}
int F_265 ( void )
{
return V_33 ;
}
int T_1 F_266 ( void )
{
int V_338 ;
if ( V_48 > ( V_141 * V_339 ) )
V_48 = V_141 * V_339 ;
V_338 = V_33 + 8 * V_339 ;
#if F_81 ( V_340 ) || F_81 ( V_341 )
V_338 += V_33 * 16 ;
#endif
if ( V_338 < V_48 )
V_48 = V_338 ;
return V_114 ;
}
int F_267 ( struct V_342 * V_308 , int V_44 ,
struct V_117 * V_118 )
{
int V_26 ;
if ( ! F_87 ( V_44 ) ) {
F_8 ( V_267 , V_74 L_67 ,
V_118 -> V_332 ) ;
return - V_231 ;
}
V_26 = V_308 ? F_239 ( V_308 ) : F_16 ( 0 ) ;
return F_129 ( V_44 , V_26 , V_118 ) ;
}
static int T_1 F_268 ( int V_332 , int V_155 )
{
union V_199 V_200 ;
static T_6 V_343 = V_344 ;
T_6 V_209 ;
unsigned long V_61 ;
int V_14 = 0 ;
if ( F_269 ( V_343 ) )
V_52 -> V_203 ( & V_204 , & V_343 ) ;
F_40 ( & V_62 , V_61 ) ;
V_200 . V_205 = F_35 ( V_332 , 0 ) ;
F_42 ( & V_62 , V_61 ) ;
if ( V_155 >= F_139 () ) {
F_48 ( V_102 L_68
L_69 , V_332 , V_155 , V_200 . V_206 . V_207 ) ;
V_155 = V_200 . V_206 . V_207 ;
}
if ( V_52 -> V_208 ( & V_343 , V_155 ) ) {
for ( V_14 = 0 ; V_14 < F_139 () ; V_14 ++ ) {
if ( ! V_52 -> V_208 ( & V_343 , V_14 ) )
break;
}
if ( V_14 == F_139 () )
F_9 ( L_70 ) ;
F_48 ( V_102 L_71
L_72 , V_332 , V_155 , V_14 ) ;
V_155 = V_14 ;
}
V_52 -> V_210 ( V_155 , & V_209 ) ;
F_142 ( V_343 , V_343 , V_209 ) ;
if ( V_200 . V_206 . V_207 != V_155 ) {
V_200 . V_206 . V_207 = V_155 ;
F_40 ( & V_62 , V_61 ) ;
F_37 ( V_332 , 0 , V_200 . V_205 ) ;
V_200 . V_205 = F_35 ( V_332 , 0 ) ;
F_42 ( & V_62 , V_61 ) ;
if ( V_200 . V_206 . V_207 != V_155 ) {
F_48 ( L_73 , V_332 ) ;
return - 1 ;
}
}
F_8 ( V_15 , V_91
L_74 , V_332 , V_155 ) ;
return V_155 ;
}
static T_7 T_1 F_270 ( T_7 V_1 )
{
if ( ( V_212 . V_213 == V_214 ) &&
! F_144 ( V_215 [ V_216 ] ) )
return F_268 ( V_35 , V_1 ) ;
else
return V_1 ;
}
static T_7 T_1 F_270 ( T_7 V_1 )
{
int V_14 ;
F_271 ( V_345 , 256 ) ;
F_272 ( V_345 , 256 ) ;
for ( V_14 = 0 ; V_14 < V_35 ; V_14 ++ ) {
F_273 ( F_1 ( V_14 ) , V_345 ) ;
}
if ( ! F_71 ( V_1 , V_345 ) )
return V_1 ;
return F_274 ( V_345 , 256 ) ;
}
static int T_1 F_275 ( int V_332 )
{
union V_335 V_336 ;
unsigned long V_61 ;
F_40 ( & V_62 , V_61 ) ;
V_336 . V_205 = F_35 ( V_332 , 1 ) ;
F_42 ( & V_62 , V_61 ) ;
return V_336 . V_206 . V_346 ;
}
int F_276 ( T_3 V_112 , int * V_103 , int * V_101 )
{
int V_332 , V_63 , V_99 ;
if ( V_10 )
return - 1 ;
V_332 = F_127 ( V_112 ) ;
if ( V_332 < 0 )
return - 1 ;
V_63 = F_128 ( V_332 , V_112 ) ;
if ( V_63 < 0 )
return - 1 ;
V_99 = F_69 ( V_332 , V_63 , V_142 ) ;
if ( V_99 < 0 )
return - 1 ;
* V_103 = F_78 ( V_99 ) ;
* V_101 = F_75 ( V_99 ) ;
return 0 ;
}
void T_1 F_277 ( void )
{
int V_63 , V_332 , V_44 , V_347 ;
const struct V_122 * V_70 ;
struct V_84 * V_348 ;
if ( V_10 == 1 )
return;
for ( V_332 = 0 ; V_332 < V_35 ; V_332 ++ )
for ( V_63 = 0 ; V_63 < V_2 [ V_332 ] . V_38 ; V_63 ++ ) {
V_347 = F_69 ( V_332 , V_63 , V_142 ) ;
if ( V_347 == - 1 )
continue;
V_44 = F_84 ( V_347 , V_332 , V_63 ) ;
if ( ( V_332 > 0 ) && ( V_44 > 16 ) )
continue;
V_348 = F_278 ( V_44 ) ;
if ( ! F_279 ( V_348 ) || F_280 ( V_348 ) )
V_70 = V_348 -> V_228 ;
else
V_70 = V_52 -> V_181 () ;
if ( V_157 )
F_162 ( V_348 , V_70 , false ) ;
else
F_160 ( V_348 , V_70 , false ) ;
}
}
static struct V_349 * T_1 F_281 ( int V_35 )
{
unsigned long V_350 ;
struct V_349 * V_49 ;
char * V_351 ;
int V_14 ;
if ( V_35 <= 0 )
return NULL ;
V_350 = V_352 + sizeof( struct V_349 ) ;
V_350 *= V_35 ;
V_351 = F_282 ( V_350 ) ;
V_49 = ( void * ) V_351 ;
V_351 += sizeof( struct V_349 ) * V_35 ;
for ( V_14 = 0 ; V_14 < V_35 ; V_14 ++ ) {
V_49 [ V_14 ] . V_353 = V_351 ;
V_49 [ V_14 ] . V_61 = V_354 | V_355 ;
snprintf ( V_351 , V_352 , L_75 , V_14 ) ;
V_351 += V_352 ;
}
V_356 = V_49 ;
return V_49 ;
}
void T_1 F_283 ( void )
{
unsigned long V_357 , V_99 = V_358 ;
struct V_349 * V_359 ;
int V_14 ;
V_359 = F_281 ( V_35 ) ;
for ( V_14 = 0 ; V_14 < V_35 ; V_14 ++ ) {
if ( V_360 ) {
V_357 = F_2 ( V_14 ) ;
#ifdef F_85
if ( ! V_357 ) {
F_48 ( V_74
L_76
L_77
L_78 ) ;
V_360 = 0 ;
V_10 = 1 ;
goto V_361;
}
#endif
} else {
#ifdef F_85
V_361:
#endif
V_357 = ( unsigned long ) F_284 ( V_362 ) ;
V_357 = F_285 ( V_357 ) ;
}
F_286 ( V_99 , V_357 ) ;
F_8 ( V_15 , L_79 ,
F_287 ( V_99 ) + ( V_357 & ~ V_363 ) ,
V_357 ) ;
V_99 ++ ;
V_359 -> V_364 = V_357 ;
V_359 -> V_365 = V_357 + V_366 - 1 ;
V_359 ++ ;
}
F_264 () ;
}
void T_1 F_288 ( void )
{
int V_14 ;
struct V_349 * V_367 = V_356 ;
if ( ! V_367 ) {
if ( V_35 > 0 )
F_48 ( V_74
L_80 ) ;
return;
}
for ( V_14 = 0 ; V_14 < V_35 ; V_14 ++ ) {
F_289 ( & V_368 , V_367 ) ;
V_367 ++ ;
}
}
int F_127 ( T_3 V_112 )
{
int V_14 = 0 ;
if ( V_35 == 0 )
return - 1 ;
for ( V_14 = 0 ; V_14 < V_35 ; V_14 ++ ) {
struct V_6 * V_111 = F_3 ( V_14 ) ;
if ( ( V_112 >= V_111 -> V_113 )
&& ( V_112 <= V_111 -> V_369 ) )
return V_14 ;
}
F_48 ( V_74 L_81 , V_112 ) ;
return - 1 ;
}
int F_128 ( int V_332 , T_3 V_112 )
{
struct V_6 * V_111 ;
if ( F_290 ( V_332 == - 1 ) )
return - 1 ;
V_111 = F_3 ( V_332 ) ;
if ( F_290 ( V_112 > V_111 -> V_369 ) )
return - 1 ;
return V_112 - V_111 -> V_113 ;
}
static T_1 int F_291 ( unsigned long V_370 )
{
if ( V_35 >= V_371 ) {
F_48 ( V_102 L_82
L_83 , V_371 , V_35 ) ;
return 1 ;
}
if ( ! V_370 ) {
F_48 ( V_102 L_84
L_85 ) ;
return 1 ;
}
return 0 ;
}
void T_1 F_292 ( int V_1 , T_3 V_370 , T_3 V_113 )
{
int V_99 = 0 ;
int V_337 ;
struct V_6 * V_111 ;
if ( F_291 ( V_370 ) )
return;
V_99 = V_35 ;
V_2 [ V_99 ] . V_3 . type = V_372 ;
V_2 [ V_99 ] . V_3 . V_61 = V_373 ;
V_2 [ V_99 ] . V_3 . V_5 = V_370 ;
F_286 ( V_358 + V_99 , V_370 ) ;
V_2 [ V_99 ] . V_3 . V_4 = F_270 ( V_1 ) ;
V_2 [ V_99 ] . V_3 . V_374 = F_275 ( V_99 ) ;
V_337 = F_263 ( V_99 ) ;
V_111 = F_3 ( V_99 ) ;
V_111 -> V_113 = V_113 ;
V_111 -> V_369 = V_113 + V_337 - 1 ;
V_2 [ V_99 ] . V_38 = V_337 ;
if ( V_111 -> V_369 >= V_115 )
V_115 = V_111 -> V_369 + 1 ;
F_48 ( V_91 L_86
L_87 , V_99 , F_1 ( V_99 ) ,
F_182 ( V_99 ) , F_2 ( V_99 ) ,
V_111 -> V_113 , V_111 -> V_369 ) ;
V_35 ++ ;
}
void T_1 F_293 ( void )
{
struct V_117 V_183 = { 0 , 0 , 0 , 0 } ;
F_48 ( V_91 L_88 ) ;
#ifndef F_294
F_295 ( V_216 ,
& V_204 ) ;
#endif
F_296 () ;
F_124 ( 0 , 0 , & V_183 ) ;
F_114 ( 0 , & V_145 , V_154 ,
L_17 ) ;
}
