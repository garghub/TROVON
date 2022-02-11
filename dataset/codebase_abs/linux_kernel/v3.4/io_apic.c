void T_1 F_1 ( const struct V_1 * V_2 )
{
V_1 = * V_2 ;
}
int F_2 ( int V_3 )
{
return V_4 [ V_3 ] . V_5 . V_6 ;
}
unsigned int F_3 ( int V_3 )
{
return V_4 [ V_3 ] . V_5 . V_7 ;
}
struct V_8 * F_4 ( int V_3 )
{
return & V_4 [ V_3 ] . V_9 ;
}
void F_5 ( void )
{
#ifdef F_6
V_10 = 1 ;
V_11 = - 1 ;
#endif
V_12 = 1 ;
}
static int T_1 F_7 ( char * V_13 )
{
F_5 () ;
return 0 ;
}
void F_8 ( struct V_14 * V_15 )
{
int V_16 ;
F_9 ( V_17 , L_1
L_2 ,
V_15 -> V_18 , V_15 -> V_19 & 3 , ( V_15 -> V_19 >> 2 ) & 3 , V_15 -> V_20 ,
V_15 -> V_21 , V_15 -> V_22 , V_15 -> V_23 ) ;
for ( V_16 = 0 ; V_16 < V_24 ; V_16 ++ ) {
if ( ! memcmp ( & V_25 [ V_16 ] , V_15 , sizeof( * V_15 ) ) )
return;
}
memcpy ( & V_25 [ V_24 ] , V_15 , sizeof( * V_15 ) ) ;
if ( ++ V_24 == V_26 )
F_10 ( L_3 ) ;
}
static struct V_27 * F_11 ( int V_28 )
{
return F_12 ( sizeof( struct V_27 ) , V_29 , V_28 ) ;
}
int T_1 F_13 ( void )
{
struct V_30 * V_31 ;
int V_32 , V_28 , V_16 ;
if ( ! V_33 -> V_34 )
V_35 = ~ 0UL ;
for ( V_16 = 0 ; V_16 < V_36 ; V_16 ++ ) {
V_4 [ V_16 ] . V_37 =
F_14 ( sizeof( struct V_38 ) *
V_4 [ V_16 ] . V_39 , V_29 ) ;
if ( ! V_4 [ V_16 ] . V_37 )
F_15 ( L_4 , V_16 ) ;
}
V_31 = V_40 ;
V_32 = F_16 ( V_40 ) ;
V_28 = F_17 ( 0 ) ;
F_18 ( 0 , V_33 -> V_34 ) ;
for ( V_16 = 0 ; V_16 < V_32 ; V_16 ++ ) {
F_19 ( V_16 , & V_31 [ V_16 ] ) ;
F_20 ( & V_31 [ V_16 ] . V_41 , V_29 , V_28 ) ;
F_20 ( & V_31 [ V_16 ] . V_42 , V_29 , V_28 ) ;
if ( V_16 < V_33 -> V_34 ) {
V_31 [ V_16 ] . V_43 = V_44 + V_16 ;
F_21 ( 0 , V_31 [ V_16 ] . V_41 ) ;
}
}
return 0 ;
}
static struct V_30 * V_30 ( unsigned int V_45 )
{
return F_22 ( V_45 ) ;
}
static struct V_30 * F_23 ( unsigned int V_45 , int V_28 )
{
struct V_30 * V_31 ;
V_31 = F_12 ( sizeof( * V_31 ) , V_29 , V_28 ) ;
if ( ! V_31 )
return NULL ;
if ( ! F_20 ( & V_31 -> V_41 , V_29 , V_28 ) )
goto V_46;
if ( ! F_20 ( & V_31 -> V_42 , V_29 , V_28 ) )
goto V_47;
return V_31 ;
V_47:
F_24 ( V_31 -> V_41 ) ;
V_46:
F_25 ( V_31 ) ;
return NULL ;
}
static void F_26 ( unsigned int V_48 , struct V_30 * V_31 )
{
if ( ! V_31 )
return;
F_19 ( V_48 , NULL ) ;
F_24 ( V_31 -> V_41 ) ;
F_24 ( V_31 -> V_42 ) ;
F_25 ( V_31 ) ;
}
static struct V_30 * F_27 ( unsigned int V_48 , int V_28 )
{
int V_49 = F_28 ( V_48 , V_28 ) ;
struct V_30 * V_31 ;
if ( V_49 < 0 ) {
if ( V_49 != - V_50 )
return NULL ;
V_31 = F_22 ( V_48 ) ;
if ( V_31 )
return V_31 ;
}
V_31 = F_23 ( V_48 , V_28 ) ;
if ( V_31 )
F_19 ( V_48 , V_31 ) ;
else
F_29 ( V_48 ) ;
return V_31 ;
}
static int F_30 ( unsigned int V_51 , int V_28 )
{
return F_31 ( V_51 , V_28 ) ;
}
static void F_32 ( unsigned int V_48 , struct V_30 * V_31 )
{
F_26 ( V_48 , V_31 ) ;
F_29 ( V_48 ) ;
}
static inline unsigned int F_33 ( unsigned int V_52 , unsigned int V_53 )
{
return V_1 . V_54 ( V_52 , V_53 ) ;
}
static inline void F_34 ( unsigned int V_52 , unsigned int V_53 , unsigned int V_55 )
{
V_1 . V_56 ( V_52 , V_53 , V_55 ) ;
}
static inline void F_35 ( unsigned int V_52 , unsigned int V_53 , unsigned int V_55 )
{
V_1 . V_57 ( V_52 , V_53 , V_55 ) ;
}
static inline void F_36 ( unsigned int V_52 , unsigned int V_43 )
{
struct V_58 T_2 * V_58 = F_37 ( V_52 ) ;
F_38 ( V_43 , & V_58 -> V_59 ) ;
}
static unsigned int F_39 ( unsigned int V_52 , unsigned int V_53 )
{
struct V_58 T_2 * V_58 = F_37 ( V_52 ) ;
F_38 ( V_53 , & V_58 -> V_60 ) ;
return F_40 ( & V_58 -> V_61 ) ;
}
static void F_41 ( unsigned int V_52 , unsigned int V_53 , unsigned int V_55 )
{
struct V_58 T_2 * V_58 = F_37 ( V_52 ) ;
F_38 ( V_53 , & V_58 -> V_60 ) ;
F_38 ( V_55 , & V_58 -> V_61 ) ;
}
static void F_42 ( unsigned int V_52 , unsigned int V_53 , unsigned int V_55 )
{
struct V_58 T_2 * V_58 = F_37 ( V_52 ) ;
if ( V_62 )
F_38 ( V_53 , & V_58 -> V_60 ) ;
F_38 ( V_55 , & V_58 -> V_61 ) ;
}
static bool F_43 ( struct V_30 * V_31 )
{
struct V_27 * V_63 ;
unsigned long V_64 ;
F_44 ( & V_65 , V_64 ) ;
F_45 (entry, cfg->irq_2_pin) {
unsigned int V_53 ;
int V_66 ;
V_66 = V_63 -> V_66 ;
V_53 = F_33 ( V_63 -> V_52 , 0x10 + V_66 * 2 ) ;
if ( V_53 & V_67 ) {
F_46 ( & V_65 , V_64 ) ;
return true ;
}
}
F_46 ( & V_65 , V_64 ) ;
return false ;
}
static struct V_38 F_47 ( int V_52 , int V_66 )
{
union V_68 V_69 ;
V_69 . V_70 = F_33 ( V_52 , 0x10 + 2 * V_66 ) ;
V_69 . V_71 = F_33 ( V_52 , 0x11 + 2 * V_66 ) ;
return V_69 . V_63 ;
}
static struct V_38 F_48 ( int V_52 , int V_66 )
{
union V_68 V_69 ;
unsigned long V_64 ;
F_44 ( & V_65 , V_64 ) ;
V_69 . V_63 = F_47 ( V_52 , V_66 ) ;
F_46 ( & V_65 , V_64 ) ;
return V_69 . V_63 ;
}
static void F_49 ( int V_52 , int V_66 , struct V_38 V_72 )
{
union V_68 V_69 = { { 0 , 0 } } ;
V_69 . V_63 = V_72 ;
F_34 ( V_52 , 0x11 + 2 * V_66 , V_69 . V_71 ) ;
F_34 ( V_52 , 0x10 + 2 * V_66 , V_69 . V_70 ) ;
}
static void F_50 ( int V_52 , int V_66 , struct V_38 V_72 )
{
unsigned long V_64 ;
F_44 ( & V_65 , V_64 ) ;
F_49 ( V_52 , V_66 , V_72 ) ;
F_46 ( & V_65 , V_64 ) ;
}
static void F_51 ( int V_52 , int V_66 )
{
unsigned long V_64 ;
union V_68 V_69 = { . V_63 . V_73 = 1 } ;
F_44 ( & V_65 , V_64 ) ;
F_34 ( V_52 , 0x10 + 2 * V_66 , V_69 . V_70 ) ;
F_34 ( V_52 , 0x11 + 2 * V_66 , V_69 . V_71 ) ;
F_46 ( & V_65 , V_64 ) ;
}
static int F_52 ( struct V_30 * V_31 , int V_28 , int V_52 , int V_66 )
{
struct V_27 * * V_74 , * V_63 ;
V_74 = & V_31 -> V_75 ;
F_45 (entry, cfg->irq_2_pin) {
if ( V_63 -> V_52 == V_52 && V_63 -> V_66 == V_66 )
return 0 ;
V_74 = & V_63 -> V_76 ;
}
V_63 = F_11 ( V_28 ) ;
if ( ! V_63 ) {
F_53 ( V_77 L_5 ,
V_28 , V_52 , V_66 ) ;
return - V_78 ;
}
V_63 -> V_52 = V_52 ;
V_63 -> V_66 = V_66 ;
* V_74 = V_63 ;
return 0 ;
}
static void F_54 ( struct V_30 * V_31 , int V_28 , int V_52 , int V_66 )
{
if ( F_52 ( V_31 , V_28 , V_52 , V_66 ) )
F_10 ( L_6 ) ;
}
static void T_1 F_55 ( struct V_30 * V_31 , int V_28 ,
int V_79 , int V_80 ,
int V_81 , int V_82 )
{
struct V_27 * V_63 ;
F_45 (entry, cfg->irq_2_pin) {
if ( V_63 -> V_52 == V_79 && V_63 -> V_66 == V_80 ) {
V_63 -> V_52 = V_81 ;
V_63 -> V_66 = V_82 ;
return;
}
}
F_54 ( V_31 , V_28 , V_81 , V_82 ) ;
}
static void F_56 ( struct V_27 * V_63 ,
int V_83 , int V_84 ,
void (* F_57)( struct V_27 * V_63 ) )
{
unsigned int V_53 , V_66 ;
V_66 = V_63 -> V_66 ;
V_53 = F_33 ( V_63 -> V_52 , 0x10 + V_66 * 2 ) ;
V_53 &= V_83 ;
V_53 |= V_84 ;
F_35 ( V_63 -> V_52 , 0x10 + V_66 * 2 , V_53 ) ;
if ( F_57 )
F_57 ( V_63 ) ;
}
static void F_58 ( struct V_30 * V_31 ,
int V_83 , int V_84 ,
void (* F_57)( struct V_27 * V_63 ) )
{
struct V_27 * V_63 ;
F_45 (entry, cfg->irq_2_pin)
F_56 ( V_63 , V_83 , V_84 , F_57 ) ;
}
static void F_59 ( struct V_27 * V_63 )
{
struct V_58 T_2 * V_58 ;
V_58 = F_37 ( V_63 -> V_52 ) ;
F_40 ( & V_58 -> V_61 ) ;
}
static void F_60 ( struct V_30 * V_31 )
{
unsigned long V_64 ;
F_44 ( & V_65 , V_64 ) ;
F_58 ( V_31 , ~ 0 , V_85 , & F_59 ) ;
F_46 ( & V_65 , V_64 ) ;
}
static void F_61 ( struct V_86 * V_61 )
{
F_60 ( V_61 -> V_87 ) ;
}
static void F_62 ( struct V_30 * V_31 )
{
F_58 ( V_31 , ~ V_85 , 0 , NULL ) ;
}
static void F_63 ( struct V_30 * V_31 )
{
unsigned long V_64 ;
F_44 ( & V_65 , V_64 ) ;
F_62 ( V_31 ) ;
F_46 ( & V_65 , V_64 ) ;
}
static void F_64 ( struct V_86 * V_61 )
{
F_63 ( V_61 -> V_87 ) ;
}
static void F_65 ( int V_52 , int V_66 , int V_43 , struct V_30 * V_31 )
{
if ( F_66 ( V_52 ) >= 0x20 ) {
if ( V_31 && F_67 ( V_31 ) )
F_36 ( V_52 , V_66 ) ;
else
F_36 ( V_52 , V_43 ) ;
} else {
struct V_38 V_63 , V_88 ;
V_63 = V_88 = F_47 ( V_52 , V_66 ) ;
V_88 . V_73 = 1 ;
V_88 . V_89 = V_90 ;
F_49 ( V_52 , V_66 , V_88 ) ;
F_49 ( V_52 , V_66 , V_63 ) ;
}
}
static void F_68 ( unsigned int V_45 , struct V_30 * V_31 )
{
struct V_27 * V_63 ;
unsigned long V_64 ;
F_44 ( & V_65 , V_64 ) ;
F_45 (entry, cfg->irq_2_pin)
F_65 ( V_63 -> V_52 , V_63 -> V_66 , V_31 -> V_43 , V_31 ) ;
F_46 ( & V_65 , V_64 ) ;
}
static void F_69 ( unsigned int V_52 , unsigned int V_66 )
{
struct V_38 V_63 ;
V_63 = F_48 ( V_52 , V_66 ) ;
if ( V_63 . V_91 == V_92 )
return;
if ( ! V_63 . V_73 ) {
V_63 . V_73 = 1 ;
F_50 ( V_52 , V_66 , V_63 ) ;
V_63 = F_48 ( V_52 , V_66 ) ;
}
if ( V_63 . V_93 ) {
unsigned long V_64 ;
if ( ! V_63 . V_89 ) {
V_63 . V_89 = V_94 ;
F_50 ( V_52 , V_66 , V_63 ) ;
}
F_44 ( & V_65 , V_64 ) ;
F_65 ( V_52 , V_66 , V_63 . V_43 , NULL ) ;
F_46 ( & V_65 , V_64 ) ;
}
F_51 ( V_52 , V_66 ) ;
V_63 = F_48 ( V_52 , V_66 ) ;
if ( V_63 . V_93 )
F_53 ( V_77 L_7 ,
F_2 ( V_52 ) , V_66 ) ;
}
static void F_70 ( void )
{
int V_52 , V_66 ;
for ( V_52 = 0 ; V_52 < V_36 ; V_52 ++ )
for ( V_66 = 0 ; V_66 < V_4 [ V_52 ] . V_39 ; V_66 ++ )
F_69 ( V_52 , V_66 ) ;
}
static int T_1 F_71 ( char * V_13 )
{
int V_16 , V_95 ;
int V_96 [ V_97 + 1 ] ;
F_72 ( V_13 , F_16 ( V_96 ) , V_96 ) ;
F_9 ( V_17 , V_98
L_8 ) ;
V_95 = V_97 ;
if ( V_96 [ 0 ] < V_97 )
V_95 = V_96 [ 0 ] ;
for ( V_16 = 0 ; V_16 < V_95 ; V_16 ++ ) {
F_9 ( V_17 , V_99
L_9 , V_16 , V_96 [ V_16 + 1 ] ) ;
V_100 [ V_97 - V_16 - 1 ] = V_96 [ V_16 + 1 ] ;
}
return 1 ;
}
int F_73 ( void )
{
int V_52 , V_66 ;
int V_101 = 0 ;
for ( V_52 = 0 ; V_52 < V_36 ; V_52 ++ ) {
if ( ! V_4 [ V_52 ] . V_37 ) {
V_101 = - V_78 ;
continue;
}
for ( V_66 = 0 ; V_66 < V_4 [ V_52 ] . V_39 ; V_66 ++ )
V_4 [ V_52 ] . V_37 [ V_66 ] =
F_48 ( V_52 , V_66 ) ;
}
return V_101 ;
}
void F_74 ( void )
{
int V_52 , V_66 ;
for ( V_52 = 0 ; V_52 < V_36 ; V_52 ++ ) {
if ( ! V_4 [ V_52 ] . V_37 )
continue;
for ( V_66 = 0 ; V_66 < V_4 [ V_52 ] . V_39 ; V_66 ++ ) {
struct V_38 V_63 ;
V_63 = V_4 [ V_52 ] . V_37 [ V_66 ] ;
if ( ! V_63 . V_73 ) {
V_63 . V_73 = 1 ;
F_50 ( V_52 , V_66 , V_63 ) ;
}
}
}
}
int F_75 ( void )
{
int V_52 , V_66 ;
for ( V_52 = 0 ; V_52 < V_36 ; V_52 ++ ) {
if ( ! V_4 [ V_52 ] . V_37 )
continue;
for ( V_66 = 0 ; V_66 < V_4 [ V_52 ] . V_39 ; V_66 ++ )
F_50 ( V_52 , V_66 ,
V_4 [ V_52 ] . V_37 [ V_66 ] ) ;
}
return 0 ;
}
static int F_76 ( int V_3 , int V_66 , int type )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_24 ; V_16 ++ )
if ( V_25 [ V_16 ] . V_18 == type &&
( V_25 [ V_16 ] . V_22 == F_2 ( V_3 ) ||
V_25 [ V_16 ] . V_22 == V_102 ) &&
V_25 [ V_16 ] . V_23 == V_66 )
return V_16 ;
return - 1 ;
}
static int T_1 F_77 ( int V_45 , int type )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_24 ; V_16 ++ ) {
int V_103 = V_25 [ V_16 ] . V_20 ;
if ( F_78 ( V_103 , V_104 ) &&
( V_25 [ V_16 ] . V_18 == type ) &&
( V_25 [ V_16 ] . V_21 == V_45 ) )
return V_25 [ V_16 ] . V_23 ;
}
return - 1 ;
}
static int T_1 F_79 ( int V_45 , int type )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_24 ; V_16 ++ ) {
int V_103 = V_25 [ V_16 ] . V_20 ;
if ( F_78 ( V_103 , V_104 ) &&
( V_25 [ V_16 ] . V_18 == type ) &&
( V_25 [ V_16 ] . V_21 == V_45 ) )
break;
}
if ( V_16 < V_24 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_36 ; V_3 ++ )
if ( F_2 ( V_3 ) == V_25 [ V_16 ] . V_22 )
return V_3 ;
}
return - 1 ;
}
static int F_80 ( unsigned int V_45 )
{
if ( V_45 < V_33 -> V_34 ) {
unsigned int V_105 = 0x4d0 + ( V_45 >> 3 ) ;
return ( F_81 ( V_105 ) >> ( V_45 & 7 ) ) & 1 ;
}
F_9 ( V_17 , V_98
L_10 , V_45 ) ;
return 0 ;
}
static int F_82 ( int V_106 )
{
int V_107 = V_25 [ V_106 ] . V_20 ;
int V_108 ;
switch ( V_25 [ V_106 ] . V_19 & 3 )
{
case 0 :
if ( F_78 ( V_107 , V_104 ) )
V_108 = F_83 ( V_106 ) ;
else
V_108 = F_84 ( V_106 ) ;
break;
case 1 :
{
V_108 = 0 ;
break;
}
case 2 :
{
F_53 ( V_109 L_11 ) ;
V_108 = 1 ;
break;
}
case 3 :
{
V_108 = 1 ;
break;
}
default:
{
F_53 ( V_109 L_11 ) ;
V_108 = 1 ;
break;
}
}
return V_108 ;
}
static int F_85 ( int V_106 )
{
int V_107 = V_25 [ V_106 ] . V_20 ;
int V_89 ;
switch ( ( V_25 [ V_106 ] . V_19 >> 2 ) & 3 )
{
case 0 :
if ( F_78 ( V_107 , V_104 ) )
V_89 = F_86 ( V_106 ) ;
else
V_89 = F_87 ( V_106 ) ;
#if F_88 ( V_110 ) || F_88 ( V_111 )
switch ( V_112 [ V_107 ] ) {
case V_113 :
{
break;
}
case V_114 :
{
V_89 = F_89 ( V_106 ) ;
break;
}
case V_115 :
{
break;
}
case V_116 :
{
V_89 = F_90 ( V_106 ) ;
break;
}
default:
{
F_53 ( V_109 L_11 ) ;
V_89 = 1 ;
break;
}
}
#endif
break;
case 1 :
{
V_89 = 0 ;
break;
}
case 2 :
{
F_53 ( V_109 L_11 ) ;
V_89 = 1 ;
break;
}
case 3 :
{
V_89 = 1 ;
break;
}
default:
{
F_53 ( V_109 L_11 ) ;
V_89 = 0 ;
break;
}
}
return V_89 ;
}
static int F_91 ( int V_106 , int V_52 , int V_66 )
{
int V_45 ;
int V_107 = V_25 [ V_106 ] . V_20 ;
struct V_8 * V_117 = F_4 ( V_52 ) ;
if ( V_25 [ V_106 ] . V_23 != V_66 )
F_53 ( V_77 L_12 ) ;
if ( F_78 ( V_107 , V_104 ) ) {
V_45 = V_25 [ V_106 ] . V_21 ;
} else {
T_3 V_118 = V_117 -> V_119 + V_66 ;
if ( V_118 >= V_120 )
V_45 = V_118 ;
else
V_45 = V_121 + V_118 ;
}
#ifdef F_92
if ( ( V_66 >= 16 ) && ( V_66 <= 23 ) ) {
if ( V_100 [ V_66 - 16 ] != - 1 ) {
if ( ! V_100 [ V_66 - 16 ] ) {
F_9 ( V_17 , V_99
L_13 , V_66 - 16 ) ;
} else {
V_45 = V_100 [ V_66 - 16 ] ;
F_9 ( V_17 , V_99
L_14 ,
V_66 - 16 , V_45 ) ;
}
}
}
#endif
return V_45 ;
}
int F_93 ( int V_107 , int V_122 , int V_66 ,
struct V_123 * V_124 )
{
int V_3 , V_16 , V_125 = - 1 ;
F_9 ( V_126 ,
L_15 ,
V_107 , V_122 , V_66 ) ;
if ( F_78 ( V_107 , V_104 ) ) {
F_9 ( V_17 ,
L_16 , V_107 ) ;
return - 1 ;
}
for ( V_16 = 0 ; V_16 < V_24 ; V_16 ++ ) {
int V_103 = V_25 [ V_16 ] . V_20 ;
for ( V_3 = 0 ; V_3 < V_36 ; V_3 ++ )
if ( F_2 ( V_3 ) == V_25 [ V_16 ] . V_22 ||
V_25 [ V_16 ] . V_22 == V_102 )
break;
if ( ! F_78 ( V_103 , V_104 ) &&
! V_25 [ V_16 ] . V_18 &&
( V_107 == V_103 ) &&
( V_122 == ( ( V_25 [ V_16 ] . V_21 >> 2 ) & 0x1f ) ) ) {
int V_45 = F_91 ( V_16 , V_3 , V_25 [ V_16 ] . V_23 ) ;
if ( ! ( V_3 || F_94 ( V_45 ) ) )
continue;
if ( V_66 == ( V_25 [ V_16 ] . V_21 & 3 ) ) {
F_95 ( V_124 , V_3 ,
V_25 [ V_16 ] . V_23 ,
F_85 ( V_16 ) ,
F_82 ( V_16 ) ) ;
return V_45 ;
}
if ( V_125 < 0 ) {
F_95 ( V_124 , V_3 ,
V_25 [ V_16 ] . V_23 ,
F_85 ( V_16 ) ,
F_82 ( V_16 ) ) ;
V_125 = V_45 ;
}
}
}
return V_125 ;
}
void F_96 ( void )
{
F_97 ( & V_127 ) ;
}
void F_98 ( void )
{
F_99 ( & V_127 ) ;
}
static int
F_100 ( int V_45 , struct V_30 * V_31 , const struct V_128 * V_73 )
{
static int V_129 = V_130 + V_131 ;
static int V_132 = V_131 % 8 ;
unsigned int V_133 ;
int V_134 , V_101 ;
T_4 V_135 ;
if ( V_31 -> V_136 )
return - V_137 ;
if ( ! F_101 ( & V_135 , V_138 ) )
return - V_78 ;
V_133 = V_31 -> V_43 ;
if ( V_133 ) {
F_102 ( V_135 , V_73 , V_139 ) ;
F_102 ( V_135 , V_31 -> V_41 , V_135 ) ;
if ( ! F_103 ( V_135 ) ) {
F_24 ( V_135 ) ;
return 0 ;
}
}
V_101 = - V_140 ;
F_104 (cpu, mask, cpu_online_mask) {
int V_141 ;
int V_43 , V_142 ;
V_52 -> V_143 ( V_134 , V_135 ) ;
V_43 = V_129 ;
V_142 = V_132 ;
V_76:
V_43 += 8 ;
if ( V_43 >= V_144 ) {
V_142 = ( V_142 + 1 ) % 8 ;
V_43 = V_130 + V_142 ;
}
if ( F_105 ( V_129 == V_43 ) )
continue;
if ( F_78 ( V_43 , V_145 ) )
goto V_76;
F_104 (new_cpu, tmp_mask, cpu_online_mask)
if ( F_106 ( V_146 , V_141 ) [ V_43 ] != - 1 )
goto V_76;
V_129 = V_43 ;
V_132 = V_142 ;
if ( V_133 ) {
V_31 -> V_136 = 1 ;
F_107 ( V_31 -> V_42 , V_31 -> V_41 ) ;
}
F_104 (new_cpu, tmp_mask, cpu_online_mask)
F_106 ( V_146 , V_141 ) [ V_43 ] = V_45 ;
V_31 -> V_43 = V_43 ;
F_107 ( V_31 -> V_41 , V_135 ) ;
V_101 = 0 ;
break;
}
F_24 ( V_135 ) ;
return V_101 ;
}
int F_108 ( int V_45 , struct V_30 * V_31 , const struct V_128 * V_73 )
{
int V_101 ;
unsigned long V_64 ;
F_44 ( & V_127 , V_64 ) ;
V_101 = F_100 ( V_45 , V_31 , V_73 ) ;
F_46 ( & V_127 , V_64 ) ;
return V_101 ;
}
static void F_109 ( int V_45 , struct V_30 * V_31 )
{
int V_134 , V_43 ;
F_110 ( ! V_31 -> V_43 ) ;
V_43 = V_31 -> V_43 ;
F_104 (cpu, cfg->domain, cpu_online_mask)
F_106 ( V_146 , V_134 ) [ V_43 ] = - 1 ;
V_31 -> V_43 = 0 ;
F_111 ( V_31 -> V_41 ) ;
if ( F_112 ( ! V_31 -> V_136 ) )
return;
F_104 (cpu, cfg->old_domain, cpu_online_mask) {
for ( V_43 = V_130 ; V_43 < V_147 ;
V_43 ++ ) {
if ( F_106 ( V_146 , V_134 ) [ V_43 ] != V_45 )
continue;
F_106 ( V_146 , V_134 ) [ V_43 ] = - 1 ;
break;
}
}
V_31 -> V_136 = 0 ;
}
void F_113 ( int V_134 )
{
int V_45 , V_43 ;
struct V_30 * V_31 ;
F_97 ( & V_127 ) ;
F_114 (irq) {
V_31 = F_22 ( V_45 ) ;
if ( ! V_31 )
continue;
if ( V_45 < V_33 -> V_34 && ! F_94 ( V_45 ) )
F_21 ( V_134 , V_31 -> V_41 ) ;
if ( ! F_115 ( V_134 , V_31 -> V_41 ) )
continue;
V_43 = V_31 -> V_43 ;
F_106 ( V_146 , V_134 ) [ V_43 ] = V_45 ;
}
for ( V_43 = 0 ; V_43 < V_147 ; ++ V_43 ) {
V_45 = F_106 ( V_146 , V_134 ) [ V_43 ] ;
if ( V_45 < 0 )
continue;
V_31 = V_30 ( V_45 ) ;
if ( ! F_115 ( V_134 , V_31 -> V_41 ) )
F_106 ( V_146 , V_134 ) [ V_43 ] = - 1 ;
}
F_99 ( & V_127 ) ;
}
static inline int F_116 ( int V_45 )
{
int V_52 , V_106 , V_66 ;
for ( V_52 = 0 ; V_52 < V_36 ; V_52 ++ ) {
for ( V_66 = 0 ; V_66 < V_4 [ V_52 ] . V_39 ; V_66 ++ ) {
V_106 = F_76 ( V_52 , V_66 , V_148 ) ;
if ( ( V_106 != - 1 ) && ( V_45 == F_91 ( V_106 , V_52 , V_66 ) ) )
return F_85 ( V_106 ) ;
}
}
return 0 ;
}
static inline int F_116 ( int V_45 )
{
return 1 ;
}
static void F_117 ( unsigned int V_45 , struct V_30 * V_31 ,
unsigned long V_89 )
{
struct V_149 * V_150 = & V_151 ;
T_5 V_152 ;
bool V_153 ;
if ( ( V_89 == V_154 && F_116 ( V_45 ) ) ||
V_89 == V_94 ) {
F_118 ( V_45 , V_155 ) ;
V_153 = true ;
} else {
F_119 ( V_45 , V_155 ) ;
V_153 = false ;
}
if ( F_67 ( V_31 ) ) {
F_118 ( V_45 , V_156 ) ;
F_120 ( V_150 ) ;
V_153 = V_89 != 0 ;
}
V_152 = V_153 ? V_157 : V_158 ;
F_121 ( V_45 , V_150 , V_152 ,
V_153 ? L_17 : L_18 ) ;
}
static int F_122 ( int V_45 ,
struct V_159 * V_63 ,
unsigned int V_160 , int V_43 ,
struct V_123 * V_161 )
{
int V_60 ;
struct V_162 V_162 ;
int V_163 = F_2 ( V_161 -> V_164 ) ;
struct V_165 * V_166 = F_123 ( V_163 ) ;
if ( ! V_166 ) {
F_124 ( L_19 , V_163 ) ;
return - V_167 ;
}
V_60 = F_125 ( V_166 , V_45 , 1 ) ;
if ( V_60 < 0 ) {
F_124 ( L_20 , V_163 ) ;
return - V_78 ;
}
F_126 ( & V_162 , V_43 , V_160 ) ;
F_127 ( & V_162 , V_163 ) ;
F_128 ( V_45 , & V_162 ) ;
F_9 ( V_17 , V_99 L_21
L_22
L_23
L_24
L_25 ,
V_161 -> V_164 , V_162 . V_168 , V_162 . V_169 , V_162 . V_170 ,
V_162 . V_171 , V_162 . V_172 , V_162 . V_173 ,
V_162 . V_174 , V_162 . V_43 , V_162 . V_175 ,
V_162 . V_176 , V_162 . V_177 , V_162 . V_178 ) ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_179 = ( V_60 >> 15 ) & 0x1 ;
V_63 -> V_180 = 0 ;
V_63 -> V_181 = 1 ;
V_63 -> V_60 = ( V_60 & 0x7fff ) ;
V_63 -> V_43 = V_161 -> V_182 ;
V_63 -> V_73 = 0 ;
V_63 -> V_89 = V_161 -> V_89 ;
V_63 -> V_108 = V_161 -> V_108 ;
if ( V_161 -> V_89 )
V_63 -> V_73 = 1 ;
return 0 ;
}
static int F_129 ( int V_45 , struct V_38 * V_63 ,
unsigned int V_160 , int V_43 ,
struct V_123 * V_161 )
{
if ( V_183 )
return F_122 ( V_45 ,
(struct V_159 * ) V_63 ,
V_160 , V_43 , V_161 ) ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_91 = V_52 -> V_184 ;
V_63 -> V_185 = V_52 -> V_186 ;
V_63 -> V_187 = V_160 ;
V_63 -> V_43 = V_43 ;
V_63 -> V_73 = 0 ;
V_63 -> V_89 = V_161 -> V_89 ;
V_63 -> V_108 = V_161 -> V_108 ;
if ( V_161 -> V_89 )
V_63 -> V_73 = 1 ;
return 0 ;
}
static void F_130 ( unsigned int V_45 , struct V_30 * V_31 ,
struct V_123 * V_161 )
{
struct V_38 V_63 ;
unsigned int V_187 ;
if ( ! F_94 ( V_45 ) )
return;
if ( V_45 < V_33 -> V_34 && F_115 ( 0 , V_31 -> V_41 ) )
V_52 -> V_143 ( 0 , V_31 -> V_41 ) ;
if ( F_108 ( V_45 , V_31 , V_52 -> V_188 () ) )
return;
V_187 = V_52 -> V_189 ( V_31 -> V_41 , V_52 -> V_188 () ) ;
F_9 ( V_17 , V_99
L_26
L_27 ,
V_161 -> V_164 , F_2 ( V_161 -> V_164 ) , V_161 -> V_182 ,
V_31 -> V_43 , V_45 , V_161 -> V_89 , V_161 -> V_108 , V_187 ) ;
if ( F_129 ( V_45 , & V_63 , V_187 , V_31 -> V_43 , V_161 ) ) {
F_124 ( L_28 ,
F_2 ( V_161 -> V_164 ) , V_161 -> V_182 ) ;
F_109 ( V_45 , V_31 ) ;
return;
}
F_117 ( V_45 , V_31 , V_161 -> V_89 ) ;
if ( V_45 < V_33 -> V_34 )
V_33 -> V_73 ( V_45 ) ;
F_50 ( V_161 -> V_164 , V_161 -> V_182 , V_63 ) ;
}
static bool T_1 F_131 ( int V_106 , int V_3 , int V_66 )
{
if ( V_106 != - 1 )
return false ;
F_9 ( V_17 , V_99 L_29 ,
F_2 ( V_3 ) , V_66 ) ;
return true ;
}
static void T_1 F_132 ( unsigned int V_3 )
{
int V_106 , V_28 = F_17 ( 0 ) ;
struct V_123 V_161 ;
unsigned int V_66 , V_45 ;
for ( V_66 = 0 ; V_66 < V_4 [ V_3 ] . V_39 ; V_66 ++ ) {
V_106 = F_76 ( V_3 , V_66 , V_148 ) ;
if ( F_131 ( V_106 , V_3 , V_66 ) )
continue;
V_45 = F_91 ( V_106 , V_3 , V_66 ) ;
if ( ( V_3 > 0 ) && ( V_45 > 16 ) )
continue;
if ( V_52 -> V_190 &&
V_52 -> V_190 ( V_3 , V_45 ) )
continue;
F_95 ( & V_161 , V_3 , V_66 , F_85 ( V_106 ) ,
F_82 ( V_106 ) ) ;
F_133 ( V_45 , V_28 , & V_161 ) ;
}
}
static void T_1 F_134 ( void )
{
unsigned int V_3 ;
F_9 ( V_17 , V_99 L_30 ) ;
for ( V_3 = 0 ; V_3 < V_36 ; V_3 ++ )
F_132 ( V_3 ) ;
}
void F_135 ( T_3 V_118 )
{
int V_3 = 0 , V_66 , V_106 , V_45 , V_28 = F_17 ( 0 ) ;
struct V_123 V_161 ;
V_3 = F_136 ( V_118 ) ;
if ( V_3 < 0 )
return;
V_66 = F_137 ( V_3 , V_118 ) ;
V_106 = F_76 ( V_3 , V_66 , V_148 ) ;
if ( V_106 == - 1 )
return;
V_45 = F_91 ( V_106 , V_3 , V_66 ) ;
if ( V_3 == 0 || V_45 < V_120 )
return;
F_95 ( & V_161 , V_3 , V_66 , F_85 ( V_106 ) ,
F_82 ( V_106 ) ) ;
F_138 ( V_45 , V_28 , & V_161 ) ;
}
static void T_1 F_139 ( unsigned int V_3 ,
unsigned int V_66 , int V_43 )
{
struct V_38 V_63 ;
if ( V_183 )
return;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_63 . V_185 = V_52 -> V_186 ;
V_63 . V_73 = 0 ;
V_63 . V_187 = V_52 -> V_191 ( V_52 -> V_188 () ) ;
V_63 . V_91 = V_52 -> V_184 ;
V_63 . V_108 = 0 ;
V_63 . V_89 = 0 ;
V_63 . V_43 = V_43 ;
F_121 ( 0 , & V_151 , V_158 ,
L_18 ) ;
F_50 ( V_3 , V_66 , V_63 ) ;
}
static T_1 int F_140 ( char * V_192 )
{
int V_193 = - 1 ;
if ( strcmp ( V_192 , L_31 ) == 0 ) {
V_194 = V_195 ;
} else {
F_141 ( & V_192 , & V_193 ) ;
if ( V_193 >= 0 )
V_194 = V_193 ;
}
return 1 ;
}
void T_1 F_142 ( void )
{
int V_196 , V_197 ;
int V_52 ;
if ( ! V_33 -> V_34 )
return;
for( V_52 = 0 ; V_52 < V_36 ; V_52 ++ ) {
int V_66 ;
for ( V_66 = 0 ; V_66 < V_4 [ V_52 ] . V_39 ; V_66 ++ ) {
struct V_38 V_63 ;
V_63 = F_48 ( V_52 , V_66 ) ;
if ( ( V_63 . V_73 == 0 ) && ( V_63 . V_91 == V_198 ) ) {
V_199 . V_52 = V_52 ;
V_199 . V_66 = V_66 ;
goto V_200;
}
}
}
V_200:
V_197 = F_77 ( 0 , V_201 ) ;
V_196 = F_79 ( 0 , V_201 ) ;
if ( ( V_199 . V_66 == - 1 ) && ( V_197 >= 0 ) ) {
F_53 ( V_109 L_32 ) ;
V_199 . V_66 = V_197 ;
V_199 . V_52 = V_196 ;
}
if ( ( ( V_199 . V_52 != V_196 ) || ( V_199 . V_66 != V_197 ) ) &&
( V_197 >= 0 ) && ( V_199 . V_66 >= 0 ) )
{
F_53 ( V_109 L_33 ) ;
}
F_70 () ;
}
void F_143 ( void )
{
F_70 () ;
if ( ! V_33 -> V_34 )
return;
if ( V_199 . V_66 != - 1 && ! V_183 ) {
struct V_38 V_63 ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_63 . V_73 = 0 ;
V_63 . V_89 = 0 ;
V_63 . V_93 = 0 ;
V_63 . V_108 = 0 ;
V_63 . V_202 = 0 ;
V_63 . V_185 = 0 ;
V_63 . V_91 = V_198 ;
V_63 . V_43 = 0 ;
V_63 . V_187 = F_144 () ;
F_50 ( V_199 . V_52 , V_199 . V_66 , V_63 ) ;
}
if ( V_203 || F_145 () )
F_146 ( ! V_183 &&
V_199 . V_66 != - 1 ) ;
}
void T_1 F_147 ( void )
{
union V_204 V_205 ;
T_6 V_206 ;
int V_3 ;
int V_16 ;
unsigned char V_207 ;
unsigned long V_64 ;
V_52 -> V_208 ( & V_209 , & V_206 ) ;
for ( V_3 = 0 ; V_3 < V_36 ; V_3 ++ ) {
F_44 ( & V_65 , V_64 ) ;
V_205 . V_210 = F_33 ( V_3 , 0 ) ;
F_46 ( & V_65 , V_64 ) ;
V_207 = F_2 ( V_3 ) ;
if ( F_2 ( V_3 ) >= F_148 () ) {
F_53 ( V_77 L_34 ,
V_3 , F_2 ( V_3 ) ) ;
F_53 ( V_77 L_35 ,
V_205 . V_211 . V_212 ) ;
V_4 [ V_3 ] . V_5 . V_6 = V_205 . V_211 . V_212 ;
}
if ( V_52 -> V_213 ( & V_206 ,
F_2 ( V_3 ) ) ) {
F_53 ( V_77 L_36 ,
V_3 , F_2 ( V_3 ) ) ;
for ( V_16 = 0 ; V_16 < F_148 () ; V_16 ++ )
if ( ! F_149 ( V_16 , V_206 ) )
break;
if ( V_16 >= F_148 () )
F_10 ( L_37 ) ;
F_53 ( V_77 L_35 ,
V_16 ) ;
F_150 ( V_16 , V_206 ) ;
V_4 [ V_3 ] . V_5 . V_6 = V_16 ;
} else {
T_6 V_214 ;
V_52 -> V_215 ( F_2 ( V_3 ) ,
& V_214 ) ;
F_9 ( V_17 , L_38
L_39 ,
F_2 ( V_3 ) ) ;
F_151 ( V_206 , V_206 , V_214 ) ;
}
if ( V_207 != F_2 ( V_3 ) )
for ( V_16 = 0 ; V_16 < V_24 ; V_16 ++ )
if ( V_25 [ V_16 ] . V_22 == V_207 )
V_25 [ V_16 ] . V_22
= F_2 ( V_3 ) ;
if ( F_2 ( V_3 ) == V_205 . V_211 . V_212 )
continue;
F_9 ( V_17 , V_98
L_40 ,
F_2 ( V_3 ) ) ;
V_205 . V_211 . V_212 = F_2 ( V_3 ) ;
F_44 ( & V_65 , V_64 ) ;
F_34 ( V_3 , 0 , V_205 . V_210 ) ;
F_46 ( & V_65 , V_64 ) ;
F_44 ( & V_65 , V_64 ) ;
V_205 . V_210 = F_33 ( V_3 , 0 ) ;
F_46 ( & V_65 , V_64 ) ;
if ( V_205 . V_211 . V_212 != F_2 ( V_3 ) )
F_53 ( L_41 ) ;
else
F_9 ( V_17 , L_42 ) ;
}
}
void T_1 F_152 ( void )
{
if ( V_216 )
return;
if ( ! ( V_217 . V_218 == V_219 )
|| F_153 ( V_220 [ V_221 ] ) )
return;
F_147 () ;
}
static int T_1 F_154 ( char * V_222 )
{
V_223 = 1 ;
return 1 ;
}
static int T_1 F_155 ( void )
{
unsigned long V_224 = V_225 ;
unsigned long V_64 ;
if ( V_223 )
return 1 ;
F_156 ( V_64 ) ;
F_157 () ;
F_158 ( ( 10 * 1000 ) / V_226 ) ;
F_159 ( V_64 ) ;
if ( F_160 ( V_225 , V_224 + 4 ) )
return 1 ;
return 0 ;
}
static unsigned int F_161 ( struct V_86 * V_61 )
{
int V_227 = 0 , V_45 = V_61 -> V_45 ;
unsigned long V_64 ;
F_44 ( & V_65 , V_64 ) ;
if ( V_45 < V_33 -> V_34 ) {
V_33 -> V_73 ( V_45 ) ;
if ( V_33 -> V_228 ( V_45 ) )
V_227 = 1 ;
}
F_62 ( V_61 -> V_87 ) ;
F_46 ( & V_65 , V_64 ) ;
return V_227 ;
}
static int F_162 ( struct V_86 * V_61 )
{
struct V_30 * V_31 = V_61 -> V_87 ;
unsigned long V_64 ;
F_44 ( & V_127 , V_64 ) ;
V_52 -> V_229 ( F_163 ( F_164 ( V_31 -> V_41 ) ) , V_31 -> V_43 ) ;
F_46 ( & V_127 , V_64 ) ;
return 1 ;
}
void F_165 ( struct V_30 * V_31 )
{
T_4 V_230 ;
if ( F_105 ( ! F_101 ( & V_230 , V_138 ) ) ) {
unsigned int V_16 ;
F_104 (i, cfg->old_domain, cpu_online_mask)
V_52 -> V_229 ( F_163 ( V_16 ) , V_231 ) ;
} else {
F_102 ( V_230 , V_31 -> V_42 , V_139 ) ;
V_52 -> V_229 ( V_230 , V_231 ) ;
F_24 ( V_230 ) ;
}
V_31 -> V_136 = 0 ;
}
static void F_166 ( unsigned int V_45 , unsigned int V_187 , struct V_30 * V_31 )
{
int V_52 , V_66 ;
struct V_27 * V_63 ;
T_7 V_43 = V_31 -> V_43 ;
F_45 (entry, cfg->irq_2_pin) {
unsigned int V_53 ;
V_52 = V_63 -> V_52 ;
V_66 = V_63 -> V_66 ;
if ( ! F_67 ( V_31 ) )
F_34 ( V_52 , 0x11 + V_66 * 2 , V_187 ) ;
V_53 = F_33 ( V_52 , 0x10 + V_66 * 2 ) ;
V_53 &= ~ V_232 ;
V_53 |= V_43 ;
F_35 ( V_52 , 0x10 + V_66 * 2 , V_53 ) ;
}
}
int F_167 ( struct V_86 * V_61 , const struct V_128 * V_73 ,
unsigned int * V_175 )
{
struct V_30 * V_31 = V_61 -> V_87 ;
if ( ! F_168 ( V_73 , V_139 ) )
return - 1 ;
if ( F_108 ( V_61 -> V_45 , V_61 -> V_87 , V_73 ) )
return - 1 ;
F_107 ( V_61 -> V_233 , V_73 ) ;
* V_175 = V_52 -> V_189 ( V_73 , V_31 -> V_41 ) ;
return 0 ;
}
static int
F_169 ( struct V_86 * V_61 , const struct V_128 * V_73 ,
bool V_234 )
{
unsigned int V_187 , V_45 = V_61 -> V_45 ;
unsigned long V_64 ;
int V_235 ;
F_44 ( & V_65 , V_64 ) ;
V_235 = F_167 ( V_61 , V_73 , & V_187 ) ;
if ( ! V_235 ) {
V_187 = F_170 ( V_187 ) ;
F_166 ( V_45 , V_187 , V_61 -> V_87 ) ;
}
F_46 ( & V_65 , V_64 ) ;
return V_235 ;
}
static int
F_171 ( struct V_86 * V_61 , const struct V_128 * V_73 ,
bool V_234 )
{
struct V_30 * V_31 = V_61 -> V_87 ;
unsigned int V_187 , V_45 = V_61 -> V_45 ;
struct V_162 V_162 ;
if ( ! F_168 ( V_73 , V_139 ) )
return - V_236 ;
if ( F_172 ( V_45 , & V_162 ) )
return - V_137 ;
if ( F_108 ( V_45 , V_31 , V_73 ) )
return - V_137 ;
V_187 = V_52 -> V_189 ( V_31 -> V_41 , V_73 ) ;
V_162 . V_43 = V_31 -> V_43 ;
V_162 . V_175 = F_173 ( V_187 ) ;
F_128 ( V_45 , & V_162 ) ;
if ( V_31 -> V_136 )
F_165 ( V_31 ) ;
F_107 ( V_61 -> V_233 , V_73 ) ;
return 0 ;
}
static inline int
F_171 ( struct V_86 * V_61 , const struct V_128 * V_73 ,
bool V_234 )
{
return 0 ;
}
T_8 void F_174 ( void )
{
unsigned V_43 , V_237 ;
F_175 () ;
F_176 () ;
F_177 () ;
V_237 = F_178 () ;
for ( V_43 = V_130 ; V_43 < V_147 ; V_43 ++ ) {
unsigned int V_45 ;
unsigned int V_93 ;
struct V_238 * V_239 ;
struct V_30 * V_31 ;
V_45 = F_179 ( V_146 [ V_43 ] ) ;
if ( V_45 == - 1 )
continue;
V_239 = F_180 ( V_45 ) ;
if ( ! V_239 )
continue;
V_31 = V_30 ( V_45 ) ;
F_97 ( & V_239 -> V_240 ) ;
if ( V_31 -> V_136 )
goto V_241;
if ( V_43 == V_31 -> V_43 && F_115 ( V_237 , V_31 -> V_41 ) )
goto V_241;
V_93 = F_181 ( V_242 + ( V_43 / 32 * 0x10 ) ) ;
if ( V_93 & ( 1 << ( V_43 % 32 ) ) ) {
V_52 -> V_243 ( V_231 ) ;
goto V_241;
}
F_182 ( V_146 [ V_43 ] , - 1 ) ;
V_241:
F_99 ( & V_239 -> V_240 ) ;
}
F_183 () ;
}
static void F_184 ( struct V_30 * V_31 , unsigned V_43 )
{
unsigned V_237 ;
if ( F_112 ( ! V_31 -> V_136 ) )
return;
V_237 = F_178 () ;
if ( V_43 == V_31 -> V_43 && F_115 ( V_237 , V_31 -> V_41 ) )
F_165 ( V_31 ) ;
}
static void F_185 ( struct V_30 * V_31 )
{
F_184 ( V_31 , ~ F_186 () -> V_244 ) ;
}
void F_187 ( int V_45 )
{
struct V_30 * V_31 = F_22 ( V_45 ) ;
if ( ! V_31 )
return;
F_184 ( V_31 , V_31 -> V_43 ) ;
}
static inline void F_185 ( struct V_30 * V_31 ) { }
static void F_188 ( struct V_86 * V_61 )
{
F_185 ( V_61 -> V_87 ) ;
F_189 ( V_61 ) ;
F_175 () ;
}
static inline bool F_190 ( struct V_86 * V_61 , struct V_30 * V_31 )
{
if ( F_105 ( F_191 ( V_61 ) ) ) {
F_60 ( V_31 ) ;
return true ;
}
return false ;
}
static inline void F_192 ( struct V_86 * V_61 ,
struct V_30 * V_31 , bool V_245 )
{
if ( F_105 ( V_245 ) ) {
if ( ! F_43 ( V_31 ) )
F_193 ( V_61 ) ;
F_63 ( V_31 ) ;
}
}
static inline bool F_190 ( struct V_86 * V_61 , struct V_30 * V_31 )
{
return false ;
}
static inline void F_192 ( struct V_86 * V_61 ,
struct V_30 * V_31 , bool V_245 )
{
}
static void F_194 ( struct V_86 * V_61 )
{
struct V_30 * V_31 = V_61 -> V_87 ;
int V_16 , V_45 = V_61 -> V_45 ;
unsigned long V_246 ;
bool V_245 ;
F_185 ( V_31 ) ;
V_245 = F_190 ( V_61 , V_31 ) ;
V_16 = V_31 -> V_43 ;
V_246 = F_181 ( V_247 + ( ( V_16 & ~ 0x1f ) >> 1 ) ) ;
F_175 () ;
if ( ! ( V_246 & ( 1 << ( V_16 & 0x1f ) ) ) ) {
F_195 ( & V_248 ) ;
F_68 ( V_45 , V_31 ) ;
}
F_192 ( V_61 , V_31 , V_245 ) ;
}
static void F_196 ( struct V_86 * V_61 )
{
F_175 () ;
}
static void F_197 ( struct V_86 * V_61 )
{
F_175 () ;
F_68 ( V_61 -> V_45 , V_61 -> V_87 ) ;
}
static void F_198 ( struct V_86 * V_61 , struct V_249 * V_250 )
{
F_199 ( V_250 , L_43 , V_61 -> V_150 -> V_251 ) ;
}
static void F_120 ( struct V_149 * V_150 )
{
V_150 -> V_252 = F_198 ;
V_150 -> V_253 = F_196 ;
V_150 -> V_254 = F_197 ;
#ifdef F_200
V_150 -> V_255 = F_171 ;
#endif
}
static inline void F_201 ( void )
{
struct V_30 * V_31 ;
unsigned int V_45 ;
F_114 (irq) {
V_31 = F_22 ( V_45 ) ;
if ( F_94 ( V_45 ) && V_31 && ! V_31 -> V_43 ) {
if ( V_45 < V_33 -> V_34 )
V_33 -> V_256 ( V_45 ) ;
else
F_202 ( V_45 , & V_257 ) ;
}
}
}
static void F_203 ( struct V_86 * V_61 )
{
unsigned long V_246 ;
V_246 = F_181 ( V_258 ) ;
F_204 ( V_258 , V_246 | V_259 ) ;
}
static void F_205 ( struct V_86 * V_61 )
{
unsigned long V_246 ;
V_246 = F_181 ( V_258 ) ;
F_204 ( V_258 , V_246 & ~ V_259 ) ;
}
static void F_206 ( struct V_86 * V_61 )
{
F_175 () ;
}
static void F_207 ( int V_45 )
{
F_119 ( V_45 , V_155 ) ;
F_121 ( V_45 , & V_260 , V_158 ,
L_18 ) ;
}
static inline void T_1 F_208 ( void )
{
int V_52 , V_66 , V_16 ;
struct V_38 V_261 , V_88 ;
unsigned char V_262 , V_263 ;
V_66 = F_77 ( 8 , V_148 ) ;
if ( V_66 == - 1 ) {
F_209 ( 1 ) ;
return;
}
V_52 = F_79 ( 8 , V_148 ) ;
if ( V_52 == - 1 ) {
F_209 ( 1 ) ;
return;
}
V_261 = F_48 ( V_52 , V_66 ) ;
F_69 ( V_52 , V_66 ) ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_185 = 0 ;
V_88 . V_73 = 0 ;
V_88 . V_187 = F_210 () ;
V_88 . V_91 = V_198 ;
V_88 . V_108 = V_261 . V_108 ;
V_88 . V_89 = 0 ;
V_88 . V_43 = 0 ;
F_50 ( V_52 , V_66 , V_88 ) ;
V_262 = F_211 ( V_264 ) ;
V_263 = F_211 ( V_265 ) ;
F_212 ( ( V_263 & ~ V_266 ) | 0x6 ,
V_265 ) ;
F_212 ( V_262 | V_267 , V_264 ) ;
V_16 = 100 ;
while ( V_16 -- > 0 ) {
F_158 ( 10 ) ;
if ( ( F_211 ( V_268 ) & V_269 ) == V_269 )
V_16 -= 10 ;
}
F_212 ( V_262 , V_264 ) ;
F_212 ( V_263 , V_265 ) ;
F_69 ( V_52 , V_66 ) ;
F_50 ( V_52 , V_66 , V_261 ) ;
}
static int T_1 F_213 ( char * V_192 )
{
V_270 = 1 ;
return 0 ;
}
static inline void T_1 F_214 ( void )
{
struct V_30 * V_31 = F_22 ( 0 ) ;
int V_28 = F_17 ( 0 ) ;
int V_271 , V_272 , V_273 , V_274 ;
unsigned long V_64 ;
int V_275 = 0 ;
F_215 ( V_64 ) ;
V_33 -> V_73 ( 0 ) ;
F_108 ( 0 , V_31 , V_52 -> V_188 () ) ;
F_204 ( V_258 , V_259 | V_276 ) ;
V_33 -> V_277 ( 1 ) ;
V_272 = F_77 ( 0 , V_148 ) ;
V_271 = F_79 ( 0 , V_148 ) ;
V_274 = V_199 . V_66 ;
V_273 = V_199 . V_52 ;
F_9 ( V_278 , V_98 L_44
L_45 ,
V_31 -> V_43 , V_271 , V_272 , V_273 , V_274 ) ;
if ( V_272 == - 1 ) {
if ( V_183 )
F_10 ( L_46 ) ;
V_272 = V_274 ;
V_271 = V_273 ;
V_275 = 1 ;
} else if ( V_274 == - 1 ) {
V_274 = V_272 ;
V_273 = V_271 ;
}
if ( V_272 != - 1 ) {
if ( V_275 ) {
F_54 ( V_31 , V_28 , V_271 , V_272 ) ;
F_139 ( V_271 , V_272 , V_31 -> V_43 ) ;
} else {
int V_106 ;
V_106 = F_76 ( V_271 , V_272 , V_148 ) ;
if ( V_106 != - 1 && F_85 ( V_106 ) )
F_63 ( V_31 ) ;
}
if ( F_155 () ) {
if ( V_270 > 0 )
F_69 ( 0 , V_272 ) ;
goto V_279;
}
if ( V_183 )
F_10 ( L_47 ) ;
F_216 () ;
F_69 ( V_271 , V_272 ) ;
if ( ! V_275 )
F_9 ( V_278 , V_77 L_48
L_49 ) ;
F_9 ( V_278 , V_98 L_50
L_51 ) ;
F_9 ( V_278 , V_98
L_52 , V_273 , V_274 ) ;
F_55 ( V_31 , V_28 , V_271 , V_272 , V_273 , V_274 ) ;
F_139 ( V_273 , V_274 , V_31 -> V_43 ) ;
V_33 -> V_280 ( 0 ) ;
if ( F_155 () ) {
F_9 ( V_278 , V_98 L_53 ) ;
V_281 = 1 ;
goto V_279;
}
F_216 () ;
V_33 -> V_73 ( 0 ) ;
F_69 ( V_273 , V_274 ) ;
F_9 ( V_278 , V_98 L_54 ) ;
}
F_9 ( V_278 , V_98
L_55 ) ;
F_207 ( 0 ) ;
F_204 ( V_258 , V_282 | V_31 -> V_43 ) ;
V_33 -> V_280 ( 0 ) ;
if ( F_155 () ) {
F_9 ( V_278 , V_98 L_56 ) ;
goto V_279;
}
F_216 () ;
V_33 -> V_73 ( 0 ) ;
F_204 ( V_258 , V_259 | V_282 | V_31 -> V_43 ) ;
F_9 ( V_278 , V_98 L_57 ) ;
F_9 ( V_278 , V_98
L_58 ) ;
V_33 -> V_277 ( 0 ) ;
V_33 -> V_256 ( 0 ) ;
F_204 ( V_258 , V_276 ) ;
F_208 () ;
if ( F_155 () ) {
F_9 ( V_278 , V_98 L_56 ) ;
goto V_279;
}
F_216 () ;
F_9 ( V_278 , V_98 L_59 ) ;
if ( V_283 )
F_9 ( V_278 , V_98
L_60
L_61 ) ;
F_10 ( L_62
L_63 ) ;
V_279:
F_159 ( V_64 ) ;
}
void T_1 F_217 ( void )
{
V_35 = V_33 -> V_34 ? ~ V_284 : ~ 0UL ;
F_9 ( V_17 , L_64 ) ;
V_285 . V_286 . V_287 () ;
F_218 () ;
F_134 () ;
F_201 () ;
if ( V_33 -> V_34 )
F_214 () ;
}
static int T_1 F_219 ( void )
{
if ( V_62 == - 1 )
V_62 = 0 ;
return 0 ;
}
static void F_220 ( int V_3 )
{
unsigned long V_64 ;
union V_204 V_205 ;
F_44 ( & V_65 , V_64 ) ;
V_205 . V_210 = F_33 ( V_3 , 0 ) ;
if ( V_205 . V_211 . V_212 != F_2 ( V_3 ) ) {
V_205 . V_211 . V_212 = F_2 ( V_3 ) ;
F_34 ( V_3 , 0 , V_205 . V_210 ) ;
}
F_46 ( & V_65 , V_64 ) ;
}
static void F_221 ( void )
{
int V_3 ;
for ( V_3 = V_36 - 1 ; V_3 >= 0 ; V_3 -- )
F_220 ( V_3 ) ;
F_75 () ;
}
static int T_1 F_222 ( void )
{
F_223 ( & V_288 ) ;
return 0 ;
}
unsigned int F_224 ( unsigned int V_51 , int V_28 )
{
struct V_30 * V_31 ;
unsigned long V_64 ;
unsigned int V_235 = 0 ;
int V_45 ;
if ( V_51 < V_289 )
V_51 = V_289 ;
V_45 = F_30 ( V_51 , V_28 ) ;
if ( V_45 < 0 )
return 0 ;
V_31 = F_23 ( V_45 , V_28 ) ;
if ( ! V_31 ) {
F_32 ( V_45 , NULL ) ;
return 0 ;
}
F_44 ( & V_127 , V_64 ) ;
if ( ! F_100 ( V_45 , V_31 , V_52 -> V_188 () ) )
V_235 = V_45 ;
F_46 ( & V_127 , V_64 ) ;
if ( V_235 ) {
F_19 ( V_45 , V_31 ) ;
F_119 ( V_45 , V_290 ) ;
} else {
F_32 ( V_45 , V_31 ) ;
}
return V_235 ;
}
int F_225 ( void )
{
int V_28 = F_17 ( 0 ) ;
unsigned int V_291 ;
int V_45 ;
V_291 = V_289 ;
V_45 = F_224 ( V_291 , V_28 ) ;
if ( V_45 == 0 )
V_45 = - 1 ;
return V_45 ;
}
void F_226 ( unsigned int V_45 )
{
struct V_30 * V_31 = F_22 ( V_45 ) ;
unsigned long V_64 ;
F_118 ( V_45 , V_290 | V_292 ) ;
if ( F_67 ( V_31 ) )
F_227 ( V_45 ) ;
F_44 ( & V_127 , V_64 ) ;
F_109 ( V_45 , V_31 ) ;
F_46 ( & V_127 , V_64 ) ;
F_32 ( V_45 , V_31 ) ;
}
static int F_228 ( struct V_293 * V_294 , unsigned int V_45 ,
struct V_295 * V_296 , T_7 V_297 )
{
struct V_30 * V_31 ;
int V_101 ;
unsigned V_187 ;
if ( V_298 )
return - V_299 ;
V_31 = V_30 ( V_45 ) ;
V_101 = F_108 ( V_45 , V_31 , V_52 -> V_188 () ) ;
if ( V_101 )
return V_101 ;
V_187 = V_52 -> V_189 ( V_31 -> V_41 , V_52 -> V_188 () ) ;
if ( F_67 ( V_31 ) ) {
struct V_162 V_162 ;
int V_300 ;
T_9 V_301 ;
V_300 = F_229 ( V_45 , & V_301 ) ;
F_110 ( V_300 == - 1 ) ;
F_126 ( & V_162 , V_31 -> V_43 , V_187 ) ;
if ( V_294 )
F_230 ( & V_162 , V_294 ) ;
else
F_231 ( & V_162 , V_297 ) ;
F_128 ( V_45 , & V_162 ) ;
V_296 -> V_302 = V_303 ;
V_296 -> V_61 = V_301 ;
V_296 -> V_304 = V_305 | V_306 |
V_307 |
F_232 ( V_300 ) |
F_233 ( V_300 ) ;
} else {
if ( F_234 () )
V_296 -> V_302 = V_303 |
F_235 ( V_187 ) ;
else
V_296 -> V_302 = V_303 ;
V_296 -> V_304 =
V_305 |
( ( V_52 -> V_186 == 0 ) ?
V_308 :
V_309 ) |
( ( V_52 -> V_184 != V_310 ) ?
V_311 :
V_312 ) |
F_236 ( V_187 ) ;
V_296 -> V_61 =
V_313 |
V_314 |
( ( V_52 -> V_184 != V_310 ) ?
V_315 :
V_316 ) |
F_237 ( V_31 -> V_43 ) ;
}
return V_101 ;
}
static int
F_238 ( struct V_86 * V_61 , const struct V_128 * V_73 , bool V_234 )
{
struct V_30 * V_31 = V_61 -> V_87 ;
struct V_295 V_296 ;
unsigned int V_187 ;
if ( F_167 ( V_61 , V_73 , & V_187 ) )
return - 1 ;
F_239 ( V_61 -> V_317 , & V_296 ) ;
V_296 . V_61 &= ~ V_318 ;
V_296 . V_61 |= F_237 ( V_31 -> V_43 ) ;
V_296 . V_304 &= ~ V_319 ;
V_296 . V_304 |= F_236 ( V_187 ) ;
F_240 ( V_61 -> V_317 , & V_296 ) ;
return 0 ;
}
static int F_241 ( struct V_293 * V_320 , int V_45 , int V_321 )
{
struct V_165 * V_166 ;
int V_60 ;
V_166 = F_242 ( V_320 ) ;
if ( ! V_166 ) {
F_53 ( V_77
L_65 , F_243 ( V_320 ) ) ;
return - V_322 ;
}
V_60 = F_125 ( V_166 , V_45 , V_321 ) ;
if ( V_60 < 0 ) {
F_53 ( V_77
L_66 , V_321 ,
F_243 ( V_320 ) ) ;
return - V_140 ;
}
return V_60 ;
}
static int F_244 ( struct V_293 * V_320 , struct V_317 * V_323 , int V_45 )
{
struct V_149 * V_150 = & V_324 ;
struct V_295 V_296 ;
int V_235 ;
V_235 = F_228 ( V_320 , V_45 , & V_296 , - 1 ) ;
if ( V_235 < 0 )
return V_235 ;
F_245 ( V_45 , V_323 ) ;
F_246 ( V_45 , & V_296 ) ;
if ( F_67 ( F_22 ( V_45 ) ) ) {
F_118 ( V_45 , V_156 ) ;
F_120 ( V_150 ) ;
}
F_121 ( V_45 , V_150 , V_158 , L_18 ) ;
F_247 ( V_99 , & V_320 -> V_320 , L_67 , V_45 ) ;
return 0 ;
}
int F_248 ( struct V_293 * V_320 , int V_321 , int type )
{
int V_28 , V_235 , V_301 , V_60 = 0 ;
unsigned int V_45 , V_291 ;
struct V_317 * V_323 ;
struct V_165 * V_166 = NULL ;
if ( type == V_325 && V_321 > 1 )
return 1 ;
V_28 = F_249 ( & V_320 -> V_320 ) ;
V_291 = V_289 ;
V_301 = 0 ;
F_250 (msidesc, &dev->msi_list, list) {
V_45 = F_224 ( V_291 , V_28 ) ;
if ( V_45 == 0 )
return - 1 ;
V_291 = V_45 + 1 ;
if ( ! V_183 )
goto V_326;
if ( ! V_301 ) {
V_60 = F_241 ( V_320 , V_45 , V_321 ) ;
if ( V_60 < 0 ) {
V_235 = V_60 ;
goto error;
}
} else {
V_166 = F_242 ( V_320 ) ;
if ( ! V_166 ) {
V_235 = - V_322 ;
goto error;
}
F_251 ( V_45 , V_166 , V_60 , V_301 ) ;
}
V_326:
V_235 = F_244 ( V_320 , V_323 , V_45 ) ;
if ( V_235 < 0 )
goto error;
V_301 ++ ;
}
return 0 ;
error:
F_226 ( V_45 ) ;
return V_235 ;
}
void F_252 ( unsigned int V_45 )
{
F_226 ( V_45 ) ;
}
static int
F_253 ( struct V_86 * V_61 , const struct V_128 * V_73 ,
bool V_234 )
{
struct V_30 * V_31 = V_61 -> V_87 ;
unsigned int V_187 , V_45 = V_61 -> V_45 ;
struct V_295 V_296 ;
if ( F_167 ( V_61 , V_73 , & V_187 ) )
return - 1 ;
F_254 ( V_45 , & V_296 ) ;
V_296 . V_61 &= ~ V_318 ;
V_296 . V_61 |= F_237 ( V_31 -> V_43 ) ;
V_296 . V_304 &= ~ V_319 ;
V_296 . V_304 |= F_236 ( V_187 ) ;
V_296 . V_302 = V_303 | F_235 ( V_187 ) ;
F_255 ( V_45 , & V_296 ) ;
return 0 ;
}
int F_256 ( unsigned int V_45 )
{
int V_235 ;
struct V_295 V_296 ;
V_235 = F_228 ( NULL , V_45 , & V_296 , - 1 ) ;
if ( V_235 < 0 )
return V_235 ;
F_255 ( V_45 , & V_296 ) ;
F_121 ( V_45 , & V_327 , V_158 ,
L_18 ) ;
return 0 ;
}
static int F_257 ( struct V_86 * V_61 ,
const struct V_128 * V_73 , bool V_234 )
{
struct V_30 * V_31 = V_61 -> V_87 ;
struct V_295 V_296 ;
unsigned int V_187 ;
if ( F_167 ( V_61 , V_73 , & V_187 ) )
return - 1 ;
F_258 ( V_61 -> V_328 , & V_296 ) ;
V_296 . V_61 &= ~ V_318 ;
V_296 . V_61 |= F_237 ( V_31 -> V_43 ) ;
V_296 . V_304 &= ~ V_319 ;
V_296 . V_304 |= F_236 ( V_187 ) ;
F_259 ( V_61 -> V_328 , & V_296 ) ;
return 0 ;
}
int F_260 ( unsigned int V_45 , unsigned int V_329 )
{
struct V_149 * V_150 = & V_330 ;
struct V_295 V_296 ;
int V_235 ;
if ( V_183 ) {
struct V_165 * V_166 = F_261 ( V_329 ) ;
int V_60 ;
if ( ! V_166 )
return - 1 ;
V_60 = F_125 ( V_166 , V_45 , 1 ) ;
if ( V_60 < 0 )
return - 1 ;
}
V_235 = F_228 ( NULL , V_45 , & V_296 , V_329 ) ;
if ( V_235 < 0 )
return V_235 ;
F_259 ( F_262 ( V_45 ) , & V_296 ) ;
F_118 ( V_45 , V_156 ) ;
if ( F_67 ( F_22 ( V_45 ) ) )
F_120 ( V_150 ) ;
F_121 ( V_45 , V_150 , V_158 , L_18 ) ;
return 0 ;
}
static void F_263 ( unsigned int V_45 , unsigned int V_187 , T_7 V_43 )
{
struct V_331 V_296 ;
F_264 ( V_45 , & V_296 ) ;
V_296 . V_304 &= ~ ( V_332 | V_333 ) ;
V_296 . V_302 &= ~ ( V_334 ) ;
V_296 . V_304 |= F_265 ( V_43 ) | F_266 ( V_187 ) ;
V_296 . V_302 |= F_267 ( V_187 ) ;
F_268 ( V_45 , & V_296 ) ;
}
static int
F_269 ( struct V_86 * V_61 , const struct V_128 * V_73 , bool V_234 )
{
struct V_30 * V_31 = V_61 -> V_87 ;
unsigned int V_187 ;
if ( F_167 ( V_61 , V_73 , & V_187 ) )
return - 1 ;
F_263 ( V_61 -> V_45 , V_187 , V_31 -> V_43 ) ;
return 0 ;
}
int F_270 ( unsigned int V_45 , struct V_293 * V_320 )
{
struct V_30 * V_31 ;
int V_101 ;
if ( V_298 )
return - V_299 ;
V_31 = V_30 ( V_45 ) ;
V_101 = F_108 ( V_45 , V_31 , V_52 -> V_188 () ) ;
if ( ! V_101 ) {
struct V_331 V_296 ;
unsigned V_187 ;
V_187 = V_52 -> V_189 ( V_31 -> V_41 ,
V_52 -> V_188 () ) ;
V_296 . V_302 = F_267 ( V_187 ) ;
V_296 . V_304 =
V_335 |
F_266 ( V_187 ) |
F_265 ( V_31 -> V_43 ) |
( ( V_52 -> V_186 == 0 ) ?
V_336 :
V_337 ) |
V_338 |
( ( V_52 -> V_184 != V_310 ) ?
V_339 :
V_340 ) |
V_341 ;
F_268 ( V_45 , & V_296 ) ;
F_121 ( V_45 , & V_342 ,
V_158 , L_18 ) ;
F_247 ( V_99 , & V_320 -> V_320 , L_68 , V_45 ) ;
}
return V_101 ;
}
static int
F_133 ( unsigned int V_45 , int V_28 , struct V_123 * V_161 )
{
struct V_30 * V_31 = F_27 ( V_45 , V_28 ) ;
int V_235 ;
if ( ! V_31 )
return - V_236 ;
V_235 = F_52 ( V_31 , V_28 , V_161 -> V_164 , V_161 -> V_182 ) ;
if ( ! V_235 )
F_130 ( V_45 , V_31 , V_161 ) ;
return V_235 ;
}
int F_138 ( unsigned int V_45 , int V_28 ,
struct V_123 * V_161 )
{
unsigned int V_3 = V_161 -> V_164 , V_66 = V_161 -> V_182 ;
int V_235 ;
if ( F_78 ( V_66 , V_4 [ V_3 ] . V_343 ) ) {
F_271 ( L_69 ,
F_2 ( V_3 ) , V_66 ) ;
return 0 ;
}
V_235 = F_133 ( V_45 , V_28 , V_161 ) ;
if ( ! V_235 )
F_272 ( V_66 , V_4 [ V_3 ] . V_343 ) ;
return V_235 ;
}
static int T_1 F_273 ( int V_164 )
{
union V_344 V_345 ;
unsigned long V_64 ;
F_44 ( & V_65 , V_64 ) ;
V_345 . V_210 = F_33 ( V_164 , 1 ) ;
F_46 ( & V_65 , V_64 ) ;
return V_345 . V_211 . V_346 + 1 ;
}
static void T_1 F_274 ( void )
{
int V_347 ;
V_347 = V_121 + V_120 ;
if ( V_347 > V_289 )
V_289 = V_347 ;
F_53 ( V_99 L_70 , V_289 ) ;
}
int F_275 ( void )
{
return V_289 ;
}
int T_1 F_276 ( void )
{
int V_347 ;
if ( V_348 > ( V_147 * V_349 ) )
V_348 = V_147 * V_349 ;
V_347 = V_289 + 8 * V_349 ;
#if F_88 ( V_350 ) || F_88 ( V_351 )
V_347 += V_289 * 16 ;
#endif
if ( V_347 < V_348 )
V_348 = V_347 ;
return V_120 ;
}
int F_277 ( struct V_352 * V_320 , int V_45 ,
struct V_123 * V_124 )
{
int V_28 ;
if ( ! F_94 ( V_45 ) ) {
F_9 ( V_278 , V_77 L_71 ,
V_124 -> V_164 ) ;
return - V_236 ;
}
V_28 = V_320 ? F_249 ( V_320 ) : F_17 ( 0 ) ;
return F_138 ( V_45 , V_28 , V_124 ) ;
}
static int T_1 F_278 ( int V_164 , int V_353 )
{
union V_204 V_205 ;
static T_6 V_354 = V_355 ;
T_6 V_214 ;
unsigned long V_64 ;
int V_16 = 0 ;
if ( F_279 ( V_354 ) )
V_52 -> V_208 ( & V_209 , & V_354 ) ;
F_44 ( & V_65 , V_64 ) ;
V_205 . V_210 = F_33 ( V_164 , 0 ) ;
F_46 ( & V_65 , V_64 ) ;
if ( V_353 >= F_148 () ) {
F_53 ( V_109 L_72
L_73 , V_164 , V_353 , V_205 . V_211 . V_212 ) ;
V_353 = V_205 . V_211 . V_212 ;
}
if ( V_52 -> V_213 ( & V_354 , V_353 ) ) {
for ( V_16 = 0 ; V_16 < F_148 () ; V_16 ++ ) {
if ( ! V_52 -> V_213 ( & V_354 , V_16 ) )
break;
}
if ( V_16 == F_148 () )
F_10 ( L_74 ) ;
F_53 ( V_109 L_75
L_76 , V_164 , V_353 , V_16 ) ;
V_353 = V_16 ;
}
V_52 -> V_215 ( V_353 , & V_214 ) ;
F_151 ( V_354 , V_354 , V_214 ) ;
if ( V_205 . V_211 . V_212 != V_353 ) {
V_205 . V_211 . V_212 = V_353 ;
F_44 ( & V_65 , V_64 ) ;
F_34 ( V_164 , 0 , V_205 . V_210 ) ;
V_205 . V_210 = F_33 ( V_164 , 0 ) ;
F_46 ( & V_65 , V_64 ) ;
if ( V_205 . V_211 . V_212 != V_353 ) {
F_53 ( L_77 , V_164 ) ;
return - 1 ;
}
}
F_9 ( V_17 , V_98
L_78 , V_164 , V_353 ) ;
return V_353 ;
}
static T_7 T_1 F_280 ( T_7 V_329 )
{
if ( ( V_217 . V_218 == V_219 ) &&
! F_153 ( V_220 [ V_221 ] ) )
return F_278 ( V_36 , V_329 ) ;
else
return V_329 ;
}
static T_7 T_1 F_280 ( T_7 V_329 )
{
int V_16 ;
F_281 ( V_356 , 256 ) ;
F_282 ( V_356 , 256 ) ;
for ( V_16 = 0 ; V_16 < V_36 ; V_16 ++ ) {
F_283 ( F_2 ( V_16 ) , V_356 ) ;
}
if ( ! F_78 ( V_329 , V_356 ) )
return V_329 ;
return F_284 ( V_356 , 256 ) ;
}
static int T_1 F_285 ( int V_164 )
{
union V_344 V_345 ;
unsigned long V_64 ;
F_44 ( & V_65 , V_64 ) ;
V_345 . V_210 = F_33 ( V_164 , 1 ) ;
F_46 ( & V_65 , V_64 ) ;
return V_345 . V_211 . V_357 ;
}
int F_286 ( T_3 V_118 , int * V_89 , int * V_108 )
{
int V_164 , V_66 , V_106 ;
if ( V_12 )
return - 1 ;
V_164 = F_136 ( V_118 ) ;
if ( V_164 < 0 )
return - 1 ;
V_66 = F_137 ( V_164 , V_118 ) ;
if ( V_66 < 0 )
return - 1 ;
V_106 = F_76 ( V_164 , V_66 , V_148 ) ;
if ( V_106 < 0 )
return - 1 ;
* V_89 = F_85 ( V_106 ) ;
* V_108 = F_82 ( V_106 ) ;
return 0 ;
}
void T_1 F_287 ( void )
{
int V_66 , V_164 , V_45 , V_358 ;
const struct V_128 * V_73 ;
struct V_86 * V_359 ;
if ( V_12 == 1 )
return;
for ( V_164 = 0 ; V_164 < V_36 ; V_164 ++ )
for ( V_66 = 0 ; V_66 < V_4 [ V_164 ] . V_39 ; V_66 ++ ) {
V_358 = F_76 ( V_164 , V_66 , V_148 ) ;
if ( V_358 == - 1 )
continue;
V_45 = F_91 ( V_358 , V_164 , V_66 ) ;
if ( ( V_164 > 0 ) && ( V_45 > 16 ) )
continue;
V_359 = F_288 ( V_45 ) ;
if ( ! F_289 ( V_359 ) || F_290 ( V_359 ) )
V_73 = V_359 -> V_233 ;
else
V_73 = V_52 -> V_188 () ;
if ( V_183 )
F_171 ( V_359 , V_73 , false ) ;
else
F_169 ( V_359 , V_73 , false ) ;
}
}
static struct V_360 * T_1 F_291 ( int V_36 )
{
unsigned long V_361 ;
struct V_360 * V_49 ;
char * V_362 ;
int V_16 ;
if ( V_36 <= 0 )
return NULL ;
V_361 = V_363 + sizeof( struct V_360 ) ;
V_361 *= V_36 ;
V_362 = F_292 ( V_361 ) ;
V_49 = ( void * ) V_362 ;
V_362 += sizeof( struct V_360 ) * V_36 ;
for ( V_16 = 0 ; V_16 < V_36 ; V_16 ++ ) {
V_49 [ V_16 ] . V_251 = V_362 ;
V_49 [ V_16 ] . V_64 = V_364 | V_365 ;
snprintf ( V_362 , V_363 , L_79 , V_16 ) ;
V_362 += V_363 ;
}
V_366 = V_49 ;
return V_49 ;
}
void T_1 F_293 ( void )
{
V_1 . V_277 () ;
}
static void T_1 F_294 ( void )
{
unsigned long V_367 , V_106 = V_368 ;
struct V_360 * V_369 ;
int V_16 ;
V_369 = F_291 ( V_36 ) ;
for ( V_16 = 0 ; V_16 < V_36 ; V_16 ++ ) {
if ( V_370 ) {
V_367 = F_3 ( V_16 ) ;
#ifdef F_92
if ( ! V_367 ) {
F_53 ( V_77
L_80
L_81
L_82 ) ;
V_370 = 0 ;
V_12 = 1 ;
goto V_371;
}
#endif
} else {
#ifdef F_92
V_371:
#endif
V_367 = ( unsigned long ) F_295 ( V_372 ) ;
V_367 = F_296 ( V_367 ) ;
}
F_297 ( V_106 , V_367 ) ;
F_9 ( V_17 , L_83 ,
F_298 ( V_106 ) + ( V_367 & ~ V_373 ) ,
V_367 ) ;
V_106 ++ ;
V_369 -> V_374 = V_367 ;
V_369 -> V_375 = V_367 + V_376 - 1 ;
V_369 ++ ;
}
F_274 () ;
}
void T_1 F_299 ( void )
{
int V_16 ;
struct V_360 * V_377 = V_366 ;
if ( ! V_377 ) {
if ( V_36 > 0 )
F_53 ( V_77
L_84 ) ;
return;
}
for ( V_16 = 0 ; V_16 < V_36 ; V_16 ++ ) {
F_300 ( & V_378 , V_377 ) ;
V_377 ++ ;
}
}
int F_136 ( T_3 V_118 )
{
int V_16 = 0 ;
if ( V_36 == 0 )
return - 1 ;
for ( V_16 = 0 ; V_16 < V_36 ; V_16 ++ ) {
struct V_8 * V_117 = F_4 ( V_16 ) ;
if ( ( V_118 >= V_117 -> V_119 )
&& ( V_118 <= V_117 -> V_379 ) )
return V_16 ;
}
F_53 ( V_77 L_85 , V_118 ) ;
return - 1 ;
}
int F_137 ( int V_164 , T_3 V_118 )
{
struct V_8 * V_117 ;
if ( F_301 ( V_164 == - 1 ) )
return - 1 ;
V_117 = F_4 ( V_164 ) ;
if ( F_301 ( V_118 > V_117 -> V_379 ) )
return - 1 ;
return V_118 - V_117 -> V_119 ;
}
static T_1 int F_302 ( unsigned long V_380 )
{
if ( V_36 >= V_381 ) {
F_124 ( L_86 ,
V_381 , V_36 ) ;
return 1 ;
}
if ( ! V_380 ) {
F_124 ( L_87 ) ;
return 1 ;
}
return 0 ;
}
static T_1 int F_303 ( int V_106 )
{
union V_204 V_205 ;
union V_344 V_345 ;
union V_382 V_383 ;
V_205 . V_210 = F_33 ( V_106 , 0 ) ;
V_345 . V_210 = F_33 ( V_106 , 1 ) ;
V_383 . V_210 = F_33 ( V_106 , 2 ) ;
if ( V_205 . V_210 == - 1 && V_345 . V_210 == - 1 && V_383 . V_210 == - 1 ) {
F_124 ( L_88 ,
F_3 ( V_106 ) ) ;
return 1 ;
}
return 0 ;
}
void T_1 F_304 ( int V_329 , T_3 V_380 , T_3 V_119 )
{
int V_106 = 0 ;
int V_346 ;
struct V_8 * V_117 ;
if ( F_302 ( V_380 ) )
return;
V_106 = V_36 ;
V_4 [ V_106 ] . V_5 . type = V_384 ;
V_4 [ V_106 ] . V_5 . V_64 = V_385 ;
V_4 [ V_106 ] . V_5 . V_7 = V_380 ;
F_297 ( V_368 + V_106 , V_380 ) ;
if ( F_303 ( V_106 ) ) {
F_305 ( V_368 + V_106 ) ;
return;
}
V_4 [ V_106 ] . V_5 . V_6 = F_280 ( V_329 ) ;
V_4 [ V_106 ] . V_5 . V_386 = F_285 ( V_106 ) ;
V_346 = F_273 ( V_106 ) ;
V_117 = F_4 ( V_106 ) ;
V_117 -> V_119 = V_119 ;
V_117 -> V_379 = V_119 + V_346 - 1 ;
V_4 [ V_106 ] . V_39 = V_346 ;
if ( V_117 -> V_379 >= V_121 )
V_121 = V_117 -> V_379 + 1 ;
F_306 ( L_89 ,
V_106 , F_2 ( V_106 ) ,
F_66 ( V_106 ) , F_3 ( V_106 ) ,
V_117 -> V_119 , V_117 -> V_379 ) ;
V_36 ++ ;
}
void T_1 F_307 ( void )
{
struct V_123 V_161 = { 0 , 0 , 0 , 0 } ;
F_53 ( V_98 L_90 ) ;
#ifndef F_200
F_308 ( V_221 ,
& V_209 ) ;
#endif
F_309 () ;
F_133 ( 0 , 0 , & V_161 ) ;
F_121 ( 0 , & V_151 , V_158 ,
L_18 ) ;
}
