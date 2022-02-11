static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 != NULL ;
}
static inline bool F_1 ( struct V_1 * V_2 )
{
return false ;
}
static inline void F_2 ( struct V_5 * V_6 )
{
}
int F_3 ( int V_7 )
{
return V_8 [ V_7 ] . V_9 . V_10 ;
}
unsigned int F_4 ( int V_7 )
{
return V_8 [ V_7 ] . V_9 . V_11 ;
}
struct V_12 * F_5 ( int V_7 )
{
return & V_8 [ V_7 ] . V_13 ;
}
void F_6 ( void )
{
#ifdef F_7
V_14 = 1 ;
V_15 = - 1 ;
#endif
V_16 = 1 ;
}
static int T_1 F_8 ( char * V_17 )
{
F_6 () ;
return 0 ;
}
void F_9 ( struct V_18 * V_19 )
{
int V_20 ;
F_10 ( V_21 , L_1
L_2 ,
V_19 -> V_22 , V_19 -> V_23 & 3 , ( V_19 -> V_23 >> 2 ) & 3 , V_19 -> V_24 ,
V_19 -> V_25 , V_19 -> V_26 , V_19 -> V_27 ) ;
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ ) {
if ( ! memcmp ( & V_29 [ V_20 ] , V_19 , sizeof( * V_19 ) ) )
return;
}
memcpy ( & V_29 [ V_28 ] , V_19 , sizeof( * V_19 ) ) ;
if ( ++ V_28 == V_30 )
F_11 ( L_3 ) ;
}
static struct V_31 * F_12 ( int V_32 )
{
return F_13 ( sizeof( struct V_31 ) , V_33 , V_32 ) ;
}
int T_1 F_14 ( void )
{
struct V_1 * V_2 ;
int V_34 , V_32 , V_20 ;
if ( ! V_35 -> V_36 )
V_37 = ~ 0UL ;
for ( V_20 = 0 ; V_20 < V_38 ; V_20 ++ ) {
V_8 [ V_20 ] . V_39 =
F_15 ( sizeof( struct V_40 ) *
V_8 [ V_20 ] . V_41 , V_33 ) ;
if ( ! V_8 [ V_20 ] . V_39 )
F_16 ( L_4 , V_20 ) ;
}
V_2 = V_42 ;
V_34 = F_17 ( V_42 ) ;
V_32 = F_18 ( 0 ) ;
F_19 ( 0 , V_35 -> V_36 ) ;
for ( V_20 = 0 ; V_20 < V_34 ; V_20 ++ ) {
F_20 ( V_20 , & V_2 [ V_20 ] ) ;
F_21 ( & V_2 [ V_20 ] . V_43 , V_33 , V_32 ) ;
F_21 ( & V_2 [ V_20 ] . V_44 , V_33 , V_32 ) ;
if ( V_20 < V_35 -> V_36 ) {
V_2 [ V_20 ] . V_45 = V_46 + V_20 ;
F_22 ( 0 , V_2 [ V_20 ] . V_43 ) ;
}
}
return 0 ;
}
static struct V_1 * V_1 ( unsigned int V_47 )
{
return F_23 ( V_47 ) ;
}
static struct V_1 * F_24 ( unsigned int V_47 , int V_32 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( sizeof( * V_2 ) , V_33 , V_32 ) ;
if ( ! V_2 )
return NULL ;
if ( ! F_21 ( & V_2 -> V_43 , V_33 , V_32 ) )
goto V_48;
if ( ! F_21 ( & V_2 -> V_44 , V_33 , V_32 ) )
goto V_49;
return V_2 ;
V_49:
F_25 ( V_2 -> V_43 ) ;
V_48:
F_26 ( V_2 ) ;
return NULL ;
}
static void F_27 ( unsigned int V_50 , struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_20 ( V_50 , NULL ) ;
F_25 ( V_2 -> V_43 ) ;
F_25 ( V_2 -> V_44 ) ;
F_26 ( V_2 ) ;
}
static struct V_1 * F_28 ( unsigned int V_50 , int V_32 )
{
int V_51 = F_29 ( V_50 , V_32 ) ;
struct V_1 * V_2 ;
if ( V_51 < 0 ) {
if ( V_51 != - V_52 )
return NULL ;
V_2 = F_23 ( V_50 ) ;
if ( V_2 )
return V_2 ;
}
V_2 = F_24 ( V_50 , V_32 ) ;
if ( V_2 )
F_20 ( V_50 , V_2 ) ;
else
F_30 ( V_50 ) ;
return V_2 ;
}
static int F_31 ( unsigned int V_53 , int V_32 )
{
return F_32 ( V_53 , V_32 ) ;
}
static void F_33 ( unsigned int V_50 , struct V_1 * V_2 )
{
F_27 ( V_50 , V_2 ) ;
F_30 ( V_50 ) ;
}
static inline void F_34 ( unsigned int V_54 , unsigned int V_45 )
{
struct V_55 T_2 * V_55 = F_35 ( V_54 ) ;
F_36 ( V_45 , & V_55 -> V_56 ) ;
}
unsigned int F_37 ( unsigned int V_54 , unsigned int V_57 )
{
struct V_55 T_2 * V_55 = F_35 ( V_54 ) ;
F_36 ( V_57 , & V_55 -> V_58 ) ;
return F_38 ( & V_55 -> V_59 ) ;
}
void F_39 ( unsigned int V_54 , unsigned int V_57 , unsigned int V_60 )
{
struct V_55 T_2 * V_55 = F_35 ( V_54 ) ;
F_36 ( V_57 , & V_55 -> V_58 ) ;
F_36 ( V_60 , & V_55 -> V_59 ) ;
}
void F_40 ( unsigned int V_54 , unsigned int V_57 , unsigned int V_60 )
{
struct V_55 T_2 * V_55 = F_35 ( V_54 ) ;
if ( V_61 )
F_36 ( V_57 , & V_55 -> V_58 ) ;
F_36 ( V_60 , & V_55 -> V_59 ) ;
}
static struct V_40 F_41 ( int V_54 , int V_62 )
{
union V_63 V_64 ;
V_64 . V_65 = F_42 ( V_54 , 0x10 + 2 * V_62 ) ;
V_64 . V_66 = F_42 ( V_54 , 0x11 + 2 * V_62 ) ;
return V_64 . V_67 ;
}
static struct V_40 F_43 ( int V_54 , int V_62 )
{
union V_63 V_64 ;
unsigned long V_68 ;
F_44 ( & V_69 , V_68 ) ;
V_64 . V_67 = F_41 ( V_54 , V_62 ) ;
F_45 ( & V_69 , V_68 ) ;
return V_64 . V_67 ;
}
static void F_46 ( int V_54 , int V_62 , struct V_40 V_70 )
{
union V_63 V_64 = { { 0 , 0 } } ;
V_64 . V_67 = V_70 ;
F_47 ( V_54 , 0x11 + 2 * V_62 , V_64 . V_66 ) ;
F_47 ( V_54 , 0x10 + 2 * V_62 , V_64 . V_65 ) ;
}
static void F_48 ( int V_54 , int V_62 , struct V_40 V_70 )
{
unsigned long V_68 ;
F_44 ( & V_69 , V_68 ) ;
F_46 ( V_54 , V_62 , V_70 ) ;
F_45 ( & V_69 , V_68 ) ;
}
static void F_49 ( int V_54 , int V_62 )
{
unsigned long V_68 ;
union V_63 V_64 = { . V_67 . V_71 = 1 } ;
F_44 ( & V_69 , V_68 ) ;
F_47 ( V_54 , 0x10 + 2 * V_62 , V_64 . V_65 ) ;
F_47 ( V_54 , 0x11 + 2 * V_62 , V_64 . V_66 ) ;
F_45 ( & V_69 , V_68 ) ;
}
static int F_50 ( struct V_1 * V_2 , int V_32 , int V_54 , int V_62 )
{
struct V_31 * * V_72 , * V_67 ;
V_72 = & V_2 -> V_73 ;
F_51 (entry, cfg->irq_2_pin) {
if ( V_67 -> V_54 == V_54 && V_67 -> V_62 == V_62 )
return 0 ;
V_72 = & V_67 -> V_74 ;
}
V_67 = F_12 ( V_32 ) ;
if ( ! V_67 ) {
F_16 ( L_5 ,
V_32 , V_54 , V_62 ) ;
return - V_75 ;
}
V_67 -> V_54 = V_54 ;
V_67 -> V_62 = V_62 ;
* V_72 = V_67 ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 , int V_32 , int V_54 , int V_62 )
{
if ( F_50 ( V_2 , V_32 , V_54 , V_62 ) )
F_11 ( L_6 ) ;
}
static void T_1 F_53 ( struct V_1 * V_2 , int V_32 ,
int V_76 , int V_77 ,
int V_78 , int V_79 )
{
struct V_31 * V_67 ;
F_51 (entry, cfg->irq_2_pin) {
if ( V_67 -> V_54 == V_76 && V_67 -> V_62 == V_77 ) {
V_67 -> V_54 = V_78 ;
V_67 -> V_62 = V_79 ;
return;
}
}
F_52 ( V_2 , V_32 , V_78 , V_79 ) ;
}
static void F_54 ( struct V_31 * V_67 ,
int V_80 , int V_81 ,
void (* F_55)( struct V_31 * V_67 ) )
{
unsigned int V_57 , V_62 ;
V_62 = V_67 -> V_62 ;
V_57 = F_42 ( V_67 -> V_54 , 0x10 + V_62 * 2 ) ;
V_57 &= V_80 ;
V_57 |= V_81 ;
F_56 ( V_67 -> V_54 , 0x10 + V_62 * 2 , V_57 ) ;
if ( F_55 )
F_55 ( V_67 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
int V_80 , int V_81 ,
void (* F_55)( struct V_31 * V_67 ) )
{
struct V_31 * V_67 ;
F_51 (entry, cfg->irq_2_pin)
F_54 ( V_67 , V_80 , V_81 , F_55 ) ;
}
static void F_58 ( struct V_31 * V_67 )
{
struct V_55 T_2 * V_55 ;
V_55 = F_35 ( V_67 -> V_54 ) ;
F_38 ( & V_55 -> V_59 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
unsigned long V_68 ;
F_44 ( & V_69 , V_68 ) ;
F_57 ( V_2 , ~ 0 , V_82 , & F_58 ) ;
F_45 ( & V_69 , V_68 ) ;
}
static void F_60 ( struct V_83 * V_59 )
{
F_59 ( V_59 -> V_84 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_57 ( V_2 , ~ V_82 , 0 , NULL ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
unsigned long V_68 ;
F_44 ( & V_69 , V_68 ) ;
F_61 ( V_2 ) ;
F_45 ( & V_69 , V_68 ) ;
}
static void F_63 ( struct V_83 * V_59 )
{
F_62 ( V_59 -> V_84 ) ;
}
static void F_64 ( int V_54 , int V_62 , int V_45 , struct V_1 * V_2 )
{
if ( F_65 ( V_54 ) >= 0x20 ) {
if ( V_2 && F_1 ( V_2 ) )
F_34 ( V_54 , V_62 ) ;
else
F_34 ( V_54 , V_45 ) ;
} else {
struct V_40 V_67 , V_85 ;
V_67 = V_85 = F_41 ( V_54 , V_62 ) ;
V_85 . V_71 = 1 ;
V_85 . V_86 = V_87 ;
F_46 ( V_54 , V_62 , V_85 ) ;
F_46 ( V_54 , V_62 , V_67 ) ;
}
}
static void F_66 ( unsigned int V_47 , struct V_1 * V_2 )
{
struct V_31 * V_67 ;
unsigned long V_68 ;
F_44 ( & V_69 , V_68 ) ;
F_51 (entry, cfg->irq_2_pin)
F_64 ( V_67 -> V_54 , V_67 -> V_62 , V_2 -> V_45 , V_2 ) ;
F_45 ( & V_69 , V_68 ) ;
}
static void F_67 ( unsigned int V_54 , unsigned int V_62 )
{
struct V_40 V_67 ;
V_67 = F_43 ( V_54 , V_62 ) ;
if ( V_67 . V_88 == V_89 )
return;
if ( ! V_67 . V_71 ) {
V_67 . V_71 = 1 ;
F_48 ( V_54 , V_62 , V_67 ) ;
V_67 = F_43 ( V_54 , V_62 ) ;
}
if ( V_67 . V_90 ) {
unsigned long V_68 ;
if ( ! V_67 . V_86 ) {
V_67 . V_86 = V_91 ;
F_48 ( V_54 , V_62 , V_67 ) ;
}
F_44 ( & V_69 , V_68 ) ;
F_64 ( V_54 , V_62 , V_67 . V_45 , NULL ) ;
F_45 ( & V_69 , V_68 ) ;
}
F_49 ( V_54 , V_62 ) ;
V_67 = F_43 ( V_54 , V_62 ) ;
if ( V_67 . V_90 )
F_16 ( L_7 ,
F_3 ( V_54 ) , V_62 ) ;
}
static void F_68 ( void )
{
int V_54 , V_62 ;
for ( V_54 = 0 ; V_54 < V_38 ; V_54 ++ )
for ( V_62 = 0 ; V_62 < V_8 [ V_54 ] . V_41 ; V_62 ++ )
F_67 ( V_54 , V_62 ) ;
}
static int T_1 F_69 ( char * V_17 )
{
int V_20 , V_92 ;
int V_93 [ V_94 + 1 ] ;
F_70 ( V_17 , F_17 ( V_93 ) , V_93 ) ;
F_10 ( V_21 , V_95
L_8 ) ;
V_92 = V_94 ;
if ( V_93 [ 0 ] < V_94 )
V_92 = V_93 [ 0 ] ;
for ( V_20 = 0 ; V_20 < V_92 ; V_20 ++ ) {
F_10 ( V_21 , V_96
L_9 , V_20 , V_93 [ V_20 + 1 ] ) ;
V_97 [ V_94 - V_20 - 1 ] = V_93 [ V_20 + 1 ] ;
}
return 1 ;
}
int F_71 ( void )
{
int V_54 , V_62 ;
int V_98 = 0 ;
for ( V_54 = 0 ; V_54 < V_38 ; V_54 ++ ) {
if ( ! V_8 [ V_54 ] . V_39 ) {
V_98 = - V_75 ;
continue;
}
for ( V_62 = 0 ; V_62 < V_8 [ V_54 ] . V_41 ; V_62 ++ )
V_8 [ V_54 ] . V_39 [ V_62 ] =
F_43 ( V_54 , V_62 ) ;
}
return V_98 ;
}
void F_72 ( void )
{
int V_54 , V_62 ;
for ( V_54 = 0 ; V_54 < V_38 ; V_54 ++ ) {
if ( ! V_8 [ V_54 ] . V_39 )
continue;
for ( V_62 = 0 ; V_62 < V_8 [ V_54 ] . V_41 ; V_62 ++ ) {
struct V_40 V_67 ;
V_67 = V_8 [ V_54 ] . V_39 [ V_62 ] ;
if ( ! V_67 . V_71 ) {
V_67 . V_71 = 1 ;
F_48 ( V_54 , V_62 , V_67 ) ;
}
}
}
}
int F_73 ( void )
{
int V_54 , V_62 ;
for ( V_54 = 0 ; V_54 < V_38 ; V_54 ++ ) {
if ( ! V_8 [ V_54 ] . V_39 )
continue;
for ( V_62 = 0 ; V_62 < V_8 [ V_54 ] . V_41 ; V_62 ++ )
F_48 ( V_54 , V_62 ,
V_8 [ V_54 ] . V_39 [ V_62 ] ) ;
}
return 0 ;
}
static int F_74 ( int V_7 , int V_62 , int type )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ )
if ( V_29 [ V_20 ] . V_22 == type &&
( V_29 [ V_20 ] . V_26 == F_3 ( V_7 ) ||
V_29 [ V_20 ] . V_26 == V_99 ) &&
V_29 [ V_20 ] . V_27 == V_62 )
return V_20 ;
return - 1 ;
}
static int T_1 F_75 ( int V_47 , int type )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ ) {
int V_100 = V_29 [ V_20 ] . V_24 ;
if ( F_76 ( V_100 , V_101 ) &&
( V_29 [ V_20 ] . V_22 == type ) &&
( V_29 [ V_20 ] . V_25 == V_47 ) )
return V_29 [ V_20 ] . V_27 ;
}
return - 1 ;
}
static int T_1 F_77 ( int V_47 , int type )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ ) {
int V_100 = V_29 [ V_20 ] . V_24 ;
if ( F_76 ( V_100 , V_101 ) &&
( V_29 [ V_20 ] . V_22 == type ) &&
( V_29 [ V_20 ] . V_25 == V_47 ) )
break;
}
if ( V_20 < V_28 ) {
int V_7 ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ )
if ( F_3 ( V_7 ) == V_29 [ V_20 ] . V_26 )
return V_7 ;
}
return - 1 ;
}
static int F_78 ( unsigned int V_47 )
{
if ( V_47 < V_35 -> V_36 ) {
unsigned int V_102 = 0x4d0 + ( V_47 >> 3 ) ;
return ( F_79 ( V_102 ) >> ( V_47 & 7 ) ) & 1 ;
}
F_10 ( V_21 , V_95
L_10 , V_47 ) ;
return 0 ;
}
static int F_80 ( int V_103 )
{
int V_104 = V_29 [ V_103 ] . V_24 ;
int V_105 ;
switch ( V_29 [ V_103 ] . V_23 & 3 )
{
case 0 :
if ( F_76 ( V_104 , V_101 ) )
V_105 = F_81 ( V_103 ) ;
else
V_105 = F_82 ( V_103 ) ;
break;
case 1 :
{
V_105 = 0 ;
break;
}
case 2 :
{
F_83 ( L_11 ) ;
V_105 = 1 ;
break;
}
case 3 :
{
V_105 = 1 ;
break;
}
default:
{
F_83 ( L_11 ) ;
V_105 = 1 ;
break;
}
}
return V_105 ;
}
static int F_84 ( int V_103 )
{
int V_104 = V_29 [ V_103 ] . V_24 ;
int V_86 ;
switch ( ( V_29 [ V_103 ] . V_23 >> 2 ) & 3 )
{
case 0 :
if ( F_76 ( V_104 , V_101 ) )
V_86 = F_85 ( V_103 ) ;
else
V_86 = F_86 ( V_103 ) ;
#ifdef F_87
switch ( V_106 [ V_104 ] ) {
case V_107 :
{
break;
}
case V_108 :
{
V_86 = F_88 ( V_103 ) ;
break;
}
case V_109 :
{
break;
}
default:
{
F_83 ( L_11 ) ;
V_86 = 1 ;
break;
}
}
#endif
break;
case 1 :
{
V_86 = 0 ;
break;
}
case 2 :
{
F_83 ( L_11 ) ;
V_86 = 1 ;
break;
}
case 3 :
{
V_86 = 1 ;
break;
}
default:
{
F_83 ( L_11 ) ;
V_86 = 0 ;
break;
}
}
return V_86 ;
}
static int F_89 ( int V_103 , int V_54 , int V_62 )
{
int V_47 ;
int V_104 = V_29 [ V_103 ] . V_24 ;
struct V_12 * V_110 = F_5 ( V_54 ) ;
if ( V_29 [ V_103 ] . V_27 != V_62 )
F_16 ( L_12 ) ;
if ( F_76 ( V_104 , V_101 ) ) {
V_47 = V_29 [ V_103 ] . V_25 ;
} else {
T_3 V_111 = V_110 -> V_112 + V_62 ;
if ( V_111 >= V_113 )
V_47 = V_111 ;
else
V_47 = V_114 + V_111 ;
}
#ifdef F_90
if ( ( V_62 >= 16 ) && ( V_62 <= 23 ) ) {
if ( V_97 [ V_62 - 16 ] != - 1 ) {
if ( ! V_97 [ V_62 - 16 ] ) {
F_10 ( V_21 , V_96
L_13 , V_62 - 16 ) ;
} else {
V_47 = V_97 [ V_62 - 16 ] ;
F_10 ( V_21 , V_96
L_14 ,
V_62 - 16 , V_47 ) ;
}
}
}
#endif
return V_47 ;
}
int F_91 ( int V_104 , int V_115 , int V_62 ,
struct V_116 * V_117 )
{
int V_7 , V_20 , V_118 = - 1 ;
F_10 ( V_119 ,
L_15 ,
V_104 , V_115 , V_62 ) ;
if ( F_76 ( V_104 , V_101 ) ) {
F_10 ( V_21 ,
L_16 , V_104 ) ;
return - 1 ;
}
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ ) {
int V_100 = V_29 [ V_20 ] . V_24 ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ )
if ( F_3 ( V_7 ) == V_29 [ V_20 ] . V_26 ||
V_29 [ V_20 ] . V_26 == V_99 )
break;
if ( ! F_76 ( V_100 , V_101 ) &&
! V_29 [ V_20 ] . V_22 &&
( V_104 == V_100 ) &&
( V_115 == ( ( V_29 [ V_20 ] . V_25 >> 2 ) & 0x1f ) ) ) {
int V_47 = F_89 ( V_20 , V_7 , V_29 [ V_20 ] . V_27 ) ;
if ( ! ( V_7 || F_92 ( V_47 ) ) )
continue;
if ( V_62 == ( V_29 [ V_20 ] . V_25 & 3 ) ) {
F_93 ( V_117 , V_7 ,
V_29 [ V_20 ] . V_27 ,
F_84 ( V_20 ) ,
F_80 ( V_20 ) ) ;
return V_47 ;
}
if ( V_118 < 0 ) {
F_93 ( V_117 , V_7 ,
V_29 [ V_20 ] . V_27 ,
F_84 ( V_20 ) ,
F_80 ( V_20 ) ) ;
V_118 = V_47 ;
}
}
}
return V_118 ;
}
void F_94 ( void )
{
F_95 ( & V_120 ) ;
}
void F_96 ( void )
{
F_97 ( & V_120 ) ;
}
static int
F_98 ( int V_47 , struct V_1 * V_2 , const struct V_121 * V_71 )
{
static int V_122 = V_123 + V_124 ;
static int V_125 = V_124 % 16 ;
int V_126 , V_98 ;
T_4 V_127 ;
if ( V_2 -> V_128 )
return - V_129 ;
if ( ! F_99 ( & V_127 , V_130 ) )
return - V_75 ;
V_98 = - V_131 ;
F_100 ( V_2 -> V_44 ) ;
V_126 = F_101 ( V_71 , V_132 ) ;
while ( V_126 < V_133 ) {
int V_134 , V_45 , V_135 ;
V_54 -> V_136 ( V_126 , V_127 , V_71 ) ;
if ( F_102 ( V_127 , V_2 -> V_43 ) ) {
V_98 = 0 ;
if ( F_103 ( V_127 , V_2 -> V_43 ) )
break;
F_104 ( V_2 -> V_44 , V_2 -> V_43 , V_127 ) ;
V_2 -> V_128 = 1 ;
F_105 ( V_2 -> V_43 , V_2 -> V_43 , V_127 ) ;
break;
}
V_45 = V_122 ;
V_135 = V_125 ;
V_74:
V_45 += 16 ;
if ( V_45 >= V_137 ) {
V_135 = ( V_135 + 1 ) % 16 ;
V_45 = V_123 + V_135 ;
}
if ( F_106 ( V_122 == V_45 ) ) {
F_107 ( V_2 -> V_44 , V_2 -> V_44 , V_127 ) ;
F_104 ( V_127 , V_71 , V_2 -> V_44 ) ;
V_126 = F_101 ( V_127 , V_132 ) ;
continue;
}
if ( F_76 ( V_45 , V_138 ) )
goto V_74;
F_108 (new_cpu, tmp_mask, cpu_online_mask)
if ( F_109 ( V_139 , V_134 ) [ V_45 ] != - 1 )
goto V_74;
V_122 = V_45 ;
V_125 = V_135 ;
if ( V_2 -> V_45 ) {
V_2 -> V_128 = 1 ;
F_110 ( V_2 -> V_44 , V_2 -> V_43 ) ;
}
F_108 (new_cpu, tmp_mask, cpu_online_mask)
F_109 ( V_139 , V_134 ) [ V_45 ] = V_47 ;
V_2 -> V_45 = V_45 ;
F_110 ( V_2 -> V_43 , V_127 ) ;
V_98 = 0 ;
break;
}
F_25 ( V_127 ) ;
return V_98 ;
}
int F_111 ( int V_47 , struct V_1 * V_2 , const struct V_121 * V_71 )
{
int V_98 ;
unsigned long V_68 ;
F_44 ( & V_120 , V_68 ) ;
V_98 = F_98 ( V_47 , V_2 , V_71 ) ;
F_45 ( & V_120 , V_68 ) ;
return V_98 ;
}
static void F_112 ( int V_47 , struct V_1 * V_2 )
{
int V_126 , V_45 ;
F_113 ( ! V_2 -> V_45 ) ;
V_45 = V_2 -> V_45 ;
F_108 (cpu, cfg->domain, cpu_online_mask)
F_109 ( V_139 , V_126 ) [ V_45 ] = - 1 ;
V_2 -> V_45 = 0 ;
F_100 ( V_2 -> V_43 ) ;
if ( F_114 ( ! V_2 -> V_128 ) )
return;
F_108 (cpu, cfg->old_domain, cpu_online_mask) {
for ( V_45 = V_123 ; V_45 < V_140 ;
V_45 ++ ) {
if ( F_109 ( V_139 , V_126 ) [ V_45 ] != V_47 )
continue;
F_109 ( V_139 , V_126 ) [ V_45 ] = - 1 ;
break;
}
}
V_2 -> V_128 = 0 ;
}
void F_115 ( int V_126 )
{
int V_47 , V_45 ;
struct V_1 * V_2 ;
F_95 ( & V_120 ) ;
F_116 (irq) {
V_2 = F_23 ( V_47 ) ;
if ( ! V_2 )
continue;
if ( V_47 < V_35 -> V_36 && ! F_92 ( V_47 ) )
F_22 ( V_126 , V_2 -> V_43 ) ;
if ( ! F_117 ( V_126 , V_2 -> V_43 ) )
continue;
V_45 = V_2 -> V_45 ;
F_109 ( V_139 , V_126 ) [ V_45 ] = V_47 ;
}
for ( V_45 = 0 ; V_45 < V_140 ; ++ V_45 ) {
V_47 = F_109 ( V_139 , V_126 ) [ V_45 ] ;
if ( V_47 < 0 )
continue;
V_2 = V_1 ( V_47 ) ;
if ( ! F_117 ( V_126 , V_2 -> V_43 ) )
F_109 ( V_139 , V_126 ) [ V_45 ] = - 1 ;
}
F_97 ( & V_120 ) ;
}
static inline int F_118 ( int V_47 )
{
int V_54 , V_103 , V_62 ;
for ( V_54 = 0 ; V_54 < V_38 ; V_54 ++ ) {
for ( V_62 = 0 ; V_62 < V_8 [ V_54 ] . V_41 ; V_62 ++ ) {
V_103 = F_74 ( V_54 , V_62 , V_141 ) ;
if ( ( V_103 != - 1 ) && ( V_47 == F_89 ( V_103 , V_54 , V_62 ) ) )
return F_84 ( V_103 ) ;
}
}
return 0 ;
}
static inline int F_118 ( int V_47 )
{
return 1 ;
}
static void F_119 ( unsigned int V_47 , struct V_1 * V_2 ,
unsigned long V_86 )
{
struct V_5 * V_6 = & V_142 ;
T_5 V_143 ;
bool V_144 ;
if ( ( V_86 == V_145 && F_118 ( V_47 ) ) ||
V_86 == V_91 ) {
F_120 ( V_47 , V_146 ) ;
V_144 = true ;
} else {
F_121 ( V_47 , V_146 ) ;
V_144 = false ;
}
if ( F_1 ( V_2 ) ) {
F_120 ( V_47 , V_147 ) ;
F_2 ( V_6 ) ;
V_144 = V_86 != 0 ;
}
V_143 = V_144 ? V_148 : V_149 ;
F_122 ( V_47 , V_6 , V_143 ,
V_144 ? L_17 : L_18 ) ;
}
static int F_123 ( int V_47 , struct V_40 * V_67 ,
unsigned int V_150 , int V_45 ,
struct V_116 * V_151 )
{
if ( V_152 )
return F_124 ( V_47 , V_67 , V_150 ,
V_45 , V_151 ) ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_67 -> V_88 = V_54 -> V_153 ;
V_67 -> V_154 = V_54 -> V_155 ;
V_67 -> V_156 = V_150 ;
V_67 -> V_45 = V_45 ;
V_67 -> V_71 = 0 ;
V_67 -> V_86 = V_151 -> V_86 ;
V_67 -> V_105 = V_151 -> V_105 ;
if ( V_151 -> V_86 )
V_67 -> V_71 = 1 ;
return 0 ;
}
static void F_125 ( unsigned int V_47 , struct V_1 * V_2 ,
struct V_116 * V_151 )
{
struct V_40 V_67 ;
unsigned int V_156 ;
if ( ! F_92 ( V_47 ) )
return;
if ( V_47 < V_35 -> V_36 &&
F_103 ( V_2 -> V_43 , F_126 ( 0 ) ) )
V_54 -> V_136 ( 0 , V_2 -> V_43 ,
V_54 -> V_157 () ) ;
if ( F_111 ( V_47 , V_2 , V_54 -> V_157 () ) )
return;
if ( V_54 -> V_158 ( V_2 -> V_43 , V_54 -> V_157 () ,
& V_156 ) ) {
F_83 ( L_19 ,
F_3 ( V_151 -> V_159 ) , V_151 -> V_160 ) ;
F_112 ( V_47 , V_2 ) ;
return;
}
F_10 ( V_21 , V_96
L_20
L_21 ,
V_151 -> V_159 , F_3 ( V_151 -> V_159 ) , V_151 -> V_160 ,
V_2 -> V_45 , V_47 , V_151 -> V_86 , V_151 -> V_105 , V_156 ) ;
if ( F_123 ( V_47 , & V_67 , V_156 , V_2 -> V_45 , V_151 ) ) {
F_83 ( L_22 ,
F_3 ( V_151 -> V_159 ) , V_151 -> V_160 ) ;
F_112 ( V_47 , V_2 ) ;
return;
}
F_119 ( V_47 , V_2 , V_151 -> V_86 ) ;
if ( V_47 < V_35 -> V_36 )
V_35 -> V_71 ( V_47 ) ;
F_48 ( V_151 -> V_159 , V_151 -> V_160 , V_67 ) ;
}
static bool T_1 F_127 ( int V_103 , int V_7 , int V_62 )
{
if ( V_103 != - 1 )
return false ;
F_10 ( V_21 , V_96 L_23 ,
F_3 ( V_7 ) , V_62 ) ;
return true ;
}
static void T_1 F_128 ( unsigned int V_7 )
{
int V_103 , V_32 = F_18 ( 0 ) ;
struct V_116 V_151 ;
unsigned int V_62 , V_47 ;
for ( V_62 = 0 ; V_62 < V_8 [ V_7 ] . V_41 ; V_62 ++ ) {
V_103 = F_74 ( V_7 , V_62 , V_141 ) ;
if ( F_127 ( V_103 , V_7 , V_62 ) )
continue;
V_47 = F_89 ( V_103 , V_7 , V_62 ) ;
if ( ( V_7 > 0 ) && ( V_47 > 16 ) )
continue;
if ( V_54 -> V_161 &&
V_54 -> V_161 ( V_7 , V_47 ) )
continue;
F_93 ( & V_151 , V_7 , V_62 , F_84 ( V_103 ) ,
F_80 ( V_103 ) ) ;
F_129 ( V_47 , V_32 , & V_151 ) ;
}
}
static void T_1 F_130 ( void )
{
unsigned int V_7 ;
F_10 ( V_21 , V_96 L_24 ) ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ )
F_128 ( V_7 ) ;
}
void F_131 ( T_3 V_111 )
{
int V_7 = 0 , V_62 , V_103 , V_47 , V_32 = F_18 ( 0 ) ;
struct V_116 V_151 ;
V_7 = F_132 ( V_111 ) ;
if ( V_7 < 0 )
return;
V_62 = F_133 ( V_7 , V_111 ) ;
V_103 = F_74 ( V_7 , V_62 , V_141 ) ;
if ( V_103 == - 1 )
return;
V_47 = F_89 ( V_103 , V_7 , V_62 ) ;
if ( V_7 == 0 || V_47 < V_113 )
return;
F_93 ( & V_151 , V_7 , V_62 , F_84 ( V_103 ) ,
F_80 ( V_103 ) ) ;
F_134 ( V_47 , V_32 , & V_151 ) ;
}
static void T_1 F_135 ( unsigned int V_7 ,
unsigned int V_62 , int V_45 )
{
struct V_40 V_67 ;
unsigned int V_156 ;
if ( V_152 )
return;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
if ( F_106 ( V_54 -> V_158 ( V_54 -> V_157 () ,
V_54 -> V_157 () , & V_156 ) ) )
V_156 = V_162 ;
V_67 . V_154 = V_54 -> V_155 ;
V_67 . V_71 = 0 ;
V_67 . V_156 = V_156 ;
V_67 . V_88 = V_54 -> V_153 ;
V_67 . V_105 = 0 ;
V_67 . V_86 = 0 ;
V_67 . V_45 = V_45 ;
F_122 ( 0 , & V_142 , V_149 ,
L_18 ) ;
F_48 ( V_7 , V_62 , V_67 ) ;
}
static T_1 int F_136 ( char * V_163 )
{
int V_164 = - 1 ;
if ( strcmp ( V_163 , L_25 ) == 0 ) {
V_165 = V_166 ;
} else {
F_137 ( & V_163 , & V_164 ) ;
if ( V_164 >= 0 )
V_165 = V_164 ;
}
return 1 ;
}
void T_1 F_138 ( void )
{
int V_167 , V_168 ;
int V_54 ;
if ( ! V_35 -> V_36 )
return;
for( V_54 = 0 ; V_54 < V_38 ; V_54 ++ ) {
int V_62 ;
for ( V_62 = 0 ; V_62 < V_8 [ V_54 ] . V_41 ; V_62 ++ ) {
struct V_40 V_67 ;
V_67 = F_43 ( V_54 , V_62 ) ;
if ( ( V_67 . V_71 == 0 ) && ( V_67 . V_88 == V_169 ) ) {
V_170 . V_54 = V_54 ;
V_170 . V_62 = V_62 ;
goto V_171;
}
}
}
V_171:
V_168 = F_75 ( 0 , V_172 ) ;
V_167 = F_77 ( 0 , V_172 ) ;
if ( ( V_170 . V_62 == - 1 ) && ( V_168 >= 0 ) ) {
F_139 ( V_173 L_26 ) ;
V_170 . V_62 = V_168 ;
V_170 . V_54 = V_167 ;
}
if ( ( ( V_170 . V_54 != V_167 ) || ( V_170 . V_62 != V_168 ) ) &&
( V_168 >= 0 ) && ( V_170 . V_62 >= 0 ) )
{
F_139 ( V_173 L_27 ) ;
}
F_68 () ;
}
void F_140 ( void )
{
F_68 () ;
if ( ! V_35 -> V_36 )
return;
if ( V_170 . V_62 != - 1 && ! V_152 ) {
struct V_40 V_67 ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_71 = 0 ;
V_67 . V_86 = 0 ;
V_67 . V_90 = 0 ;
V_67 . V_105 = 0 ;
V_67 . V_174 = 0 ;
V_67 . V_154 = 0 ;
V_67 . V_88 = V_169 ;
V_67 . V_45 = 0 ;
V_67 . V_156 = F_141 () ;
F_48 ( V_170 . V_54 , V_170 . V_62 , V_67 ) ;
}
if ( V_175 || F_142 () )
F_143 ( ! V_152 &&
V_170 . V_62 != - 1 ) ;
}
void T_1 F_144 ( void )
{
union V_176 V_177 ;
T_6 V_178 ;
int V_7 ;
int V_20 ;
unsigned char V_179 ;
unsigned long V_68 ;
V_54 -> V_180 ( & V_181 , & V_178 ) ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ ) {
F_44 ( & V_69 , V_68 ) ;
V_177 . V_182 = F_42 ( V_7 , 0 ) ;
F_45 ( & V_69 , V_68 ) ;
V_179 = F_3 ( V_7 ) ;
if ( F_3 ( V_7 ) >= F_145 () ) {
F_139 ( V_183 L_28 ,
V_7 , F_3 ( V_7 ) ) ;
F_139 ( V_183 L_29 ,
V_177 . V_184 . V_185 ) ;
V_8 [ V_7 ] . V_9 . V_10 = V_177 . V_184 . V_185 ;
}
if ( V_54 -> V_186 ( & V_178 ,
F_3 ( V_7 ) ) ) {
F_139 ( V_183 L_30 ,
V_7 , F_3 ( V_7 ) ) ;
for ( V_20 = 0 ; V_20 < F_145 () ; V_20 ++ )
if ( ! F_146 ( V_20 , V_178 ) )
break;
if ( V_20 >= F_145 () )
F_11 ( L_31 ) ;
F_139 ( V_183 L_29 ,
V_20 ) ;
F_147 ( V_20 , V_178 ) ;
V_8 [ V_7 ] . V_9 . V_10 = V_20 ;
} else {
T_6 V_187 ;
V_54 -> V_188 ( F_3 ( V_7 ) ,
& V_187 ) ;
F_10 ( V_21 , L_32
L_33 ,
F_3 ( V_7 ) ) ;
F_148 ( V_178 , V_178 , V_187 ) ;
}
if ( V_179 != F_3 ( V_7 ) )
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ )
if ( V_29 [ V_20 ] . V_26 == V_179 )
V_29 [ V_20 ] . V_26
= F_3 ( V_7 ) ;
if ( F_3 ( V_7 ) == V_177 . V_184 . V_185 )
continue;
F_10 ( V_21 , V_95
L_34 ,
F_3 ( V_7 ) ) ;
V_177 . V_184 . V_185 = F_3 ( V_7 ) ;
F_44 ( & V_69 , V_68 ) ;
F_47 ( V_7 , 0 , V_177 . V_182 ) ;
F_45 ( & V_69 , V_68 ) ;
F_44 ( & V_69 , V_68 ) ;
V_177 . V_182 = F_42 ( V_7 , 0 ) ;
F_45 ( & V_69 , V_68 ) ;
if ( V_177 . V_184 . V_185 != F_3 ( V_7 ) )
F_149 ( L_35 ) ;
else
F_10 ( V_21 , L_36 ) ;
}
}
void T_1 F_150 ( void )
{
if ( V_189 )
return;
if ( ! ( V_190 . V_191 == V_192 )
|| F_151 ( V_193 [ V_194 ] ) )
return;
F_144 () ;
}
static int T_1 F_152 ( char * V_195 )
{
V_196 = 1 ;
return 1 ;
}
static int T_1 F_153 ( void )
{
unsigned long V_197 = V_198 ;
unsigned long V_68 ;
if ( V_196 )
return 1 ;
F_154 ( V_68 ) ;
F_155 () ;
F_156 ( ( 10 * 1000 ) / V_199 ) ;
F_157 ( V_68 ) ;
if ( F_158 ( V_198 , V_197 + 4 ) )
return 1 ;
return 0 ;
}
static unsigned int F_159 ( struct V_83 * V_59 )
{
int V_200 = 0 , V_47 = V_59 -> V_47 ;
unsigned long V_68 ;
F_44 ( & V_69 , V_68 ) ;
if ( V_47 < V_35 -> V_36 ) {
V_35 -> V_71 ( V_47 ) ;
if ( V_35 -> V_201 ( V_47 ) )
V_200 = 1 ;
}
F_61 ( V_59 -> V_84 ) ;
F_45 ( & V_69 , V_68 ) ;
return V_200 ;
}
static int F_160 ( struct V_83 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_84 ;
unsigned long V_68 ;
F_44 ( & V_120 , V_68 ) ;
V_54 -> V_202 ( F_126 ( F_161 ( V_2 -> V_43 ) ) , V_2 -> V_45 ) ;
F_45 ( & V_120 , V_68 ) ;
return 1 ;
}
void F_162 ( struct V_1 * V_2 )
{
T_4 V_203 ;
if ( F_106 ( ! F_99 ( & V_203 , V_130 ) ) ) {
unsigned int V_20 ;
F_108 (i, cfg->old_domain, cpu_online_mask)
V_54 -> V_202 ( F_126 ( V_20 ) , V_204 ) ;
} else {
F_105 ( V_203 , V_2 -> V_44 , V_132 ) ;
V_54 -> V_202 ( V_203 , V_204 ) ;
F_25 ( V_203 ) ;
}
V_2 -> V_128 = 0 ;
}
T_7 void F_163 ( void )
{
unsigned V_45 , V_205 ;
F_164 () ;
F_165 () ;
F_166 () ;
V_205 = F_167 () ;
for ( V_45 = V_123 ; V_45 < V_140 ; V_45 ++ ) {
unsigned int V_47 ;
unsigned int V_90 ;
struct V_206 * V_207 ;
struct V_1 * V_2 ;
V_47 = F_168 ( V_139 [ V_45 ] ) ;
if ( V_47 == - 1 )
continue;
V_207 = F_169 ( V_47 ) ;
if ( ! V_207 )
continue;
V_2 = V_1 ( V_47 ) ;
if ( ! V_2 )
continue;
F_95 ( & V_207 -> V_208 ) ;
if ( V_2 -> V_128 )
goto V_209;
if ( V_45 == V_2 -> V_45 && F_117 ( V_205 , V_2 -> V_43 ) )
goto V_209;
V_90 = F_170 ( V_210 + ( V_45 / 32 * 0x10 ) ) ;
if ( V_90 & ( 1 << ( V_45 % 32 ) ) ) {
V_54 -> V_211 ( V_204 ) ;
goto V_209;
}
F_171 ( V_139 [ V_45 ] , - 1 ) ;
V_209:
F_97 ( & V_207 -> V_208 ) ;
}
F_172 () ;
}
static void F_173 ( struct V_1 * V_2 , unsigned V_45 )
{
unsigned V_205 ;
if ( F_114 ( ! V_2 -> V_128 ) )
return;
V_205 = F_167 () ;
if ( V_45 == V_2 -> V_45 && F_117 ( V_205 , V_2 -> V_43 ) )
F_162 ( V_2 ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
F_173 ( V_2 , ~ F_175 () -> V_212 ) ;
}
void F_176 ( int V_47 )
{
struct V_1 * V_2 = F_23 ( V_47 ) ;
if ( ! V_2 )
return;
F_173 ( V_2 , V_2 -> V_45 ) ;
}
static inline void F_174 ( struct V_1 * V_2 ) { }
static void F_177 ( unsigned int V_47 , unsigned int V_156 , struct V_1 * V_2 )
{
int V_54 , V_62 ;
struct V_31 * V_67 ;
T_8 V_45 = V_2 -> V_45 ;
F_51 (entry, cfg->irq_2_pin) {
unsigned int V_57 ;
V_54 = V_67 -> V_54 ;
V_62 = V_67 -> V_62 ;
if ( ! F_1 ( V_2 ) )
F_47 ( V_54 , 0x11 + V_62 * 2 , V_156 ) ;
V_57 = F_42 ( V_54 , 0x10 + V_62 * 2 ) ;
V_57 &= ~ V_213 ;
V_57 |= V_45 ;
F_56 ( V_54 , 0x10 + V_62 * 2 , V_57 ) ;
}
}
int F_178 ( struct V_83 * V_59 , const struct V_121 * V_71 ,
unsigned int * V_214 )
{
struct V_1 * V_2 = V_59 -> V_84 ;
unsigned int V_47 = V_59 -> V_47 ;
int V_98 ;
if ( ! F_179 ( V_215 ) )
return - 1 ;
if ( ! F_180 ( V_71 , V_132 ) )
return - V_216 ;
V_98 = F_111 ( V_47 , V_2 , V_71 ) ;
if ( V_98 )
return V_98 ;
V_98 = V_54 -> V_158 ( V_71 , V_2 -> V_43 , V_214 ) ;
if ( V_98 ) {
if ( F_111 ( V_47 , V_2 , V_59 -> V_217 ) )
F_16 ( L_37 , V_47 ) ;
return V_98 ;
}
F_110 ( V_59 -> V_217 , V_71 ) ;
return 0 ;
}
static int
F_181 ( struct V_83 * V_59 , const struct V_121 * V_71 ,
bool V_218 )
{
unsigned int V_156 , V_47 = V_59 -> V_47 ;
unsigned long V_68 ;
int V_219 ;
if ( ! F_179 ( V_215 ) )
return - 1 ;
F_44 ( & V_69 , V_68 ) ;
V_219 = F_178 ( V_59 , V_71 , & V_156 ) ;
if ( ! V_219 ) {
V_156 = F_182 ( V_156 ) ;
F_177 ( V_47 , V_156 , V_59 -> V_84 ) ;
V_219 = V_220 ;
}
F_45 ( & V_69 , V_68 ) ;
return V_219 ;
}
static void F_183 ( struct V_83 * V_59 )
{
F_174 ( V_59 -> V_84 ) ;
F_184 ( V_59 ) ;
F_164 () ;
}
static bool F_185 ( struct V_1 * V_2 )
{
struct V_31 * V_67 ;
unsigned long V_68 ;
F_44 ( & V_69 , V_68 ) ;
F_51 (entry, cfg->irq_2_pin) {
unsigned int V_57 ;
int V_62 ;
V_62 = V_67 -> V_62 ;
V_57 = F_42 ( V_67 -> V_54 , 0x10 + V_62 * 2 ) ;
if ( V_57 & V_221 ) {
F_45 ( & V_69 , V_68 ) ;
return true ;
}
}
F_45 ( & V_69 , V_68 ) ;
return false ;
}
static inline bool F_186 ( struct V_83 * V_59 , struct V_1 * V_2 )
{
if ( F_106 ( F_187 ( V_59 ) ) ) {
F_59 ( V_2 ) ;
return true ;
}
return false ;
}
static inline void F_188 ( struct V_83 * V_59 ,
struct V_1 * V_2 , bool V_222 )
{
if ( F_106 ( V_222 ) ) {
if ( ! F_185 ( V_2 ) )
F_189 ( V_59 ) ;
F_62 ( V_2 ) ;
}
}
static inline bool F_186 ( struct V_83 * V_59 , struct V_1 * V_2 )
{
return false ;
}
static inline void F_188 ( struct V_83 * V_59 ,
struct V_1 * V_2 , bool V_222 )
{
}
static void F_190 ( struct V_83 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_84 ;
int V_20 , V_47 = V_59 -> V_47 ;
unsigned long V_223 ;
bool V_222 ;
F_174 ( V_2 ) ;
V_222 = F_186 ( V_59 , V_2 ) ;
V_20 = V_2 -> V_45 ;
V_223 = F_170 ( V_224 + ( ( V_20 & ~ 0x1f ) >> 1 ) ) ;
F_164 () ;
if ( ! ( V_223 & ( 1 << ( V_20 & 0x1f ) ) ) ) {
F_191 ( & V_225 ) ;
F_66 ( V_47 , V_2 ) ;
}
F_188 ( V_59 , V_2 , V_222 ) ;
}
static void F_192 ( struct V_83 * V_59 )
{
F_164 () ;
}
static void F_193 ( struct V_83 * V_59 )
{
F_164 () ;
F_66 ( V_59 -> V_47 , V_59 -> V_84 ) ;
}
static void F_194 ( struct V_83 * V_59 , struct V_226 * V_227 )
{
F_195 ( V_227 , L_38 , V_59 -> V_6 -> V_228 ) ;
}
static void F_2 ( struct V_5 * V_6 )
{
V_6 -> V_229 = F_194 ;
V_6 -> V_230 = F_192 ;
V_6 -> V_231 = F_193 ;
V_6 -> V_232 = V_233 ;
}
static inline void F_196 ( void )
{
struct V_1 * V_2 ;
unsigned int V_47 ;
F_116 (irq) {
V_2 = F_23 ( V_47 ) ;
if ( F_92 ( V_47 ) && V_2 && ! V_2 -> V_45 ) {
if ( V_47 < V_35 -> V_36 )
V_35 -> V_234 ( V_47 ) ;
else
F_197 ( V_47 , & V_235 ) ;
}
}
}
static void F_198 ( struct V_83 * V_59 )
{
unsigned long V_223 ;
V_223 = F_170 ( V_236 ) ;
F_199 ( V_236 , V_223 | V_237 ) ;
}
static void F_200 ( struct V_83 * V_59 )
{
unsigned long V_223 ;
V_223 = F_170 ( V_236 ) ;
F_199 ( V_236 , V_223 & ~ V_237 ) ;
}
static void F_201 ( struct V_83 * V_59 )
{
F_164 () ;
}
static void F_202 ( int V_47 )
{
F_121 ( V_47 , V_146 ) ;
F_122 ( V_47 , & V_238 , V_149 ,
L_18 ) ;
}
static inline void T_1 F_203 ( void )
{
int V_54 , V_62 , V_20 ;
struct V_40 V_239 , V_85 ;
unsigned char V_240 , V_241 ;
V_62 = F_75 ( 8 , V_141 ) ;
if ( V_62 == - 1 ) {
F_204 ( 1 ) ;
return;
}
V_54 = F_77 ( 8 , V_141 ) ;
if ( V_54 == - 1 ) {
F_204 ( 1 ) ;
return;
}
V_239 = F_43 ( V_54 , V_62 ) ;
F_67 ( V_54 , V_62 ) ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . V_154 = 0 ;
V_85 . V_71 = 0 ;
V_85 . V_156 = F_205 () ;
V_85 . V_88 = V_169 ;
V_85 . V_105 = V_239 . V_105 ;
V_85 . V_86 = 0 ;
V_85 . V_45 = 0 ;
F_48 ( V_54 , V_62 , V_85 ) ;
V_240 = F_206 ( V_242 ) ;
V_241 = F_206 ( V_243 ) ;
F_207 ( ( V_241 & ~ V_244 ) | 0x6 ,
V_243 ) ;
F_207 ( V_240 | V_245 , V_242 ) ;
V_20 = 100 ;
while ( V_20 -- > 0 ) {
F_156 ( 10 ) ;
if ( ( F_206 ( V_246 ) & V_247 ) == V_247 )
V_20 -= 10 ;
}
F_207 ( V_240 , V_242 ) ;
F_207 ( V_241 , V_243 ) ;
F_67 ( V_54 , V_62 ) ;
F_48 ( V_54 , V_62 , V_239 ) ;
}
static int T_1 F_208 ( char * V_163 )
{
V_248 = 1 ;
return 0 ;
}
static inline void T_1 F_209 ( void )
{
struct V_1 * V_2 = F_23 ( 0 ) ;
int V_32 = F_18 ( 0 ) ;
int V_249 , V_250 , V_251 , V_252 ;
unsigned long V_68 ;
int V_253 = 0 ;
F_210 ( V_68 ) ;
V_35 -> V_71 ( 0 ) ;
F_111 ( 0 , V_2 , V_54 -> V_157 () ) ;
F_199 ( V_236 , V_237 | V_254 ) ;
V_35 -> V_255 ( 1 ) ;
V_250 = F_75 ( 0 , V_141 ) ;
V_249 = F_77 ( 0 , V_141 ) ;
V_252 = V_170 . V_62 ;
V_251 = V_170 . V_54 ;
F_10 ( V_256 , V_95 L_39
L_40 ,
V_2 -> V_45 , V_249 , V_250 , V_251 , V_252 ) ;
if ( V_250 == - 1 ) {
if ( V_152 )
F_11 ( L_41 ) ;
V_250 = V_252 ;
V_249 = V_251 ;
V_253 = 1 ;
} else if ( V_252 == - 1 ) {
V_252 = V_250 ;
V_251 = V_249 ;
}
if ( V_250 != - 1 ) {
if ( V_253 ) {
F_52 ( V_2 , V_32 , V_249 , V_250 ) ;
F_135 ( V_249 , V_250 , V_2 -> V_45 ) ;
} else {
int V_103 ;
V_103 = F_74 ( V_249 , V_250 , V_141 ) ;
if ( V_103 != - 1 && F_84 ( V_103 ) )
F_62 ( V_2 ) ;
}
if ( F_153 () ) {
if ( V_248 > 0 )
F_67 ( 0 , V_250 ) ;
goto V_257;
}
if ( V_152 )
F_11 ( L_42 ) ;
F_211 () ;
F_67 ( V_249 , V_250 ) ;
if ( ! V_253 )
F_10 ( V_256 , V_183 L_43
L_44 ) ;
F_10 ( V_256 , V_95 L_45
L_46 ) ;
F_10 ( V_256 , V_95
L_47 , V_251 , V_252 ) ;
F_53 ( V_2 , V_32 , V_249 , V_250 , V_251 , V_252 ) ;
F_135 ( V_251 , V_252 , V_2 -> V_45 ) ;
V_35 -> V_258 ( 0 ) ;
if ( F_153 () ) {
F_10 ( V_256 , V_95 L_48 ) ;
V_259 = 1 ;
goto V_257;
}
F_211 () ;
V_35 -> V_71 ( 0 ) ;
F_67 ( V_251 , V_252 ) ;
F_10 ( V_256 , V_95 L_49 ) ;
}
F_10 ( V_256 , V_95
L_50 ) ;
F_202 ( 0 ) ;
F_199 ( V_236 , V_260 | V_2 -> V_45 ) ;
V_35 -> V_258 ( 0 ) ;
if ( F_153 () ) {
F_10 ( V_256 , V_95 L_51 ) ;
goto V_257;
}
F_211 () ;
V_35 -> V_71 ( 0 ) ;
F_199 ( V_236 , V_237 | V_260 | V_2 -> V_45 ) ;
F_10 ( V_256 , V_95 L_52 ) ;
F_10 ( V_256 , V_95
L_53 ) ;
V_35 -> V_255 ( 0 ) ;
V_35 -> V_234 ( 0 ) ;
F_199 ( V_236 , V_254 ) ;
F_203 () ;
if ( F_153 () ) {
F_10 ( V_256 , V_95 L_51 ) ;
goto V_257;
}
F_211 () ;
F_10 ( V_256 , V_95 L_54 ) ;
if ( V_261 )
F_10 ( V_256 , V_95
L_55
L_56 ) ;
F_11 ( L_57
L_58 ) ;
V_257:
F_157 ( V_68 ) ;
}
void T_1 F_212 ( void )
{
V_37 = V_35 -> V_36 ? ~ V_262 : ~ 0UL ;
F_10 ( V_21 , L_59 ) ;
V_263 . V_264 . V_265 () ;
F_213 () ;
F_130 () ;
F_196 () ;
if ( V_35 -> V_36 )
F_209 () ;
}
static int T_1 F_214 ( void )
{
if ( V_61 == - 1 )
V_61 = 0 ;
return 0 ;
}
static void F_215 ( int V_7 )
{
unsigned long V_68 ;
union V_176 V_177 ;
F_44 ( & V_69 , V_68 ) ;
V_177 . V_182 = F_42 ( V_7 , 0 ) ;
if ( V_177 . V_184 . V_185 != F_3 ( V_7 ) ) {
V_177 . V_184 . V_185 = F_3 ( V_7 ) ;
F_47 ( V_7 , 0 , V_177 . V_182 ) ;
}
F_45 ( & V_69 , V_68 ) ;
}
static void F_216 ( void )
{
int V_7 ;
for ( V_7 = V_38 - 1 ; V_7 >= 0 ; V_7 -- )
F_215 ( V_7 ) ;
F_73 () ;
}
static int T_1 F_217 ( void )
{
F_218 ( & V_266 ) ;
return 0 ;
}
unsigned int F_219 ( unsigned int V_53 , int V_32 )
{
struct V_1 * V_2 ;
unsigned long V_68 ;
unsigned int V_219 = 0 ;
int V_47 ;
if ( V_53 < V_267 )
V_53 = V_267 ;
V_47 = F_31 ( V_53 , V_32 ) ;
if ( V_47 < 0 )
return 0 ;
V_2 = F_24 ( V_47 , V_32 ) ;
if ( ! V_2 ) {
F_33 ( V_47 , NULL ) ;
return 0 ;
}
F_44 ( & V_120 , V_68 ) ;
if ( ! F_98 ( V_47 , V_2 , V_54 -> V_157 () ) )
V_219 = V_47 ;
F_45 ( & V_120 , V_68 ) ;
if ( V_219 ) {
F_20 ( V_47 , V_2 ) ;
F_121 ( V_47 , V_268 ) ;
} else {
F_33 ( V_47 , V_2 ) ;
}
return V_219 ;
}
int F_220 ( void )
{
int V_32 = F_18 ( 0 ) ;
unsigned int V_269 ;
int V_47 ;
V_269 = V_267 ;
V_47 = F_219 ( V_269 , V_32 ) ;
if ( V_47 == 0 )
V_47 = - 1 ;
return V_47 ;
}
void F_221 ( unsigned int V_47 )
{
struct V_1 * V_2 = F_23 ( V_47 ) ;
unsigned long V_68 ;
F_120 ( V_47 , V_268 | V_270 ) ;
if ( F_1 ( V_2 ) )
F_222 ( V_47 ) ;
F_44 ( & V_120 , V_68 ) ;
F_112 ( V_47 , V_2 ) ;
F_45 ( & V_120 , V_68 ) ;
F_33 ( V_47 , V_2 ) ;
}
static int F_223 ( struct V_271 * V_272 , unsigned int V_47 ,
struct V_273 * V_274 , T_8 V_275 )
{
struct V_1 * V_2 ;
int V_98 ;
unsigned V_156 ;
if ( V_276 )
return - V_277 ;
V_2 = V_1 ( V_47 ) ;
V_98 = F_111 ( V_47 , V_2 , V_54 -> V_157 () ) ;
if ( V_98 )
return V_98 ;
V_98 = V_54 -> V_158 ( V_2 -> V_43 ,
V_54 -> V_157 () , & V_156 ) ;
if ( V_98 )
return V_98 ;
if ( F_1 ( V_2 ) ) {
F_224 ( V_272 , V_47 , V_156 , V_274 , V_275 ) ;
return V_98 ;
}
if ( F_225 () )
V_274 -> V_278 = V_279 |
F_226 ( V_156 ) ;
else
V_274 -> V_278 = V_279 ;
V_274 -> V_280 =
V_281 |
( ( V_54 -> V_155 == 0 ) ?
V_282 :
V_283 ) |
( ( V_54 -> V_153 != V_284 ) ?
V_285 :
V_286 ) |
F_227 ( V_156 ) ;
V_274 -> V_59 =
V_287 |
V_288 |
( ( V_54 -> V_153 != V_284 ) ?
V_289 :
V_290 ) |
F_228 ( V_2 -> V_45 ) ;
return V_98 ;
}
static int
F_229 ( struct V_83 * V_59 , const struct V_121 * V_71 , bool V_218 )
{
struct V_1 * V_2 = V_59 -> V_84 ;
struct V_273 V_274 ;
unsigned int V_156 ;
if ( F_178 ( V_59 , V_71 , & V_156 ) )
return - 1 ;
F_230 ( V_59 -> V_291 , & V_274 ) ;
V_274 . V_59 &= ~ V_292 ;
V_274 . V_59 |= F_228 ( V_2 -> V_45 ) ;
V_274 . V_280 &= ~ V_293 ;
V_274 . V_280 |= F_227 ( V_156 ) ;
F_231 ( V_59 -> V_291 , & V_274 ) ;
return V_220 ;
}
static int F_232 ( struct V_271 * V_294 , struct V_291 * V_295 , int V_47 )
{
struct V_5 * V_6 = & V_296 ;
struct V_273 V_274 ;
int V_219 ;
V_219 = F_223 ( V_294 , V_47 , & V_274 , - 1 ) ;
if ( V_219 < 0 )
return V_219 ;
F_233 ( V_47 , V_295 ) ;
F_234 ( V_47 , & V_274 ) ;
if ( F_1 ( F_23 ( V_47 ) ) ) {
F_120 ( V_47 , V_147 ) ;
F_2 ( V_6 ) ;
}
F_122 ( V_47 , V_6 , V_149 , L_18 ) ;
F_235 ( V_96 , & V_294 -> V_294 , L_60 , V_47 ) ;
return 0 ;
}
int F_236 ( struct V_271 * V_294 , int V_297 , int type )
{
int V_32 , V_219 , V_298 , V_58 = 0 ;
unsigned int V_47 , V_269 ;
struct V_291 * V_295 ;
if ( type == V_299 && V_297 > 1 )
return 1 ;
V_32 = F_237 ( & V_294 -> V_294 ) ;
V_269 = V_267 ;
V_298 = 0 ;
F_238 (msidesc, &dev->msi_list, list) {
V_47 = F_219 ( V_269 , V_32 ) ;
if ( V_47 == 0 )
return - 1 ;
V_269 = V_47 + 1 ;
if ( ! V_152 )
goto V_300;
if ( ! V_298 ) {
V_58 = F_239 ( V_294 , V_47 , V_297 ) ;
if ( V_58 < 0 ) {
V_219 = V_58 ;
goto error;
}
} else {
V_219 = F_240 ( V_294 , V_47 , V_58 ,
V_298 ) ;
if ( V_219 < 0 )
goto error;
}
V_300:
V_219 = F_232 ( V_294 , V_295 , V_47 ) ;
if ( V_219 < 0 )
goto error;
V_298 ++ ;
}
return 0 ;
error:
F_221 ( V_47 ) ;
return V_219 ;
}
void F_241 ( unsigned int V_47 )
{
F_221 ( V_47 ) ;
}
static int
F_242 ( struct V_83 * V_59 , const struct V_121 * V_71 ,
bool V_218 )
{
struct V_1 * V_2 = V_59 -> V_84 ;
unsigned int V_156 , V_47 = V_59 -> V_47 ;
struct V_273 V_274 ;
if ( F_178 ( V_59 , V_71 , & V_156 ) )
return - 1 ;
F_243 ( V_47 , & V_274 ) ;
V_274 . V_59 &= ~ V_292 ;
V_274 . V_59 |= F_228 ( V_2 -> V_45 ) ;
V_274 . V_280 &= ~ V_293 ;
V_274 . V_280 |= F_227 ( V_156 ) ;
V_274 . V_278 = V_279 | F_226 ( V_156 ) ;
F_244 ( V_47 , & V_274 ) ;
return V_220 ;
}
int F_245 ( unsigned int V_47 )
{
int V_219 ;
struct V_273 V_274 ;
V_219 = F_223 ( NULL , V_47 , & V_274 , - 1 ) ;
if ( V_219 < 0 )
return V_219 ;
F_244 ( V_47 , & V_274 ) ;
F_122 ( V_47 , & V_301 , V_149 ,
L_18 ) ;
return 0 ;
}
static int F_246 ( struct V_83 * V_59 ,
const struct V_121 * V_71 , bool V_218 )
{
struct V_1 * V_2 = V_59 -> V_84 ;
struct V_273 V_274 ;
unsigned int V_156 ;
if ( F_178 ( V_59 , V_71 , & V_156 ) )
return - 1 ;
F_247 ( V_59 -> V_302 , & V_274 ) ;
V_274 . V_59 &= ~ V_292 ;
V_274 . V_59 |= F_228 ( V_2 -> V_45 ) ;
V_274 . V_280 &= ~ V_293 ;
V_274 . V_280 |= F_227 ( V_156 ) ;
F_248 ( V_59 -> V_302 , & V_274 ) ;
return V_220 ;
}
int F_249 ( unsigned int V_47 , unsigned int V_303 )
{
struct V_5 * V_6 = & V_304 ;
struct V_273 V_274 ;
int V_219 ;
if ( V_152 ) {
if ( ! F_250 ( V_47 , V_303 ) )
return - 1 ;
}
V_219 = F_223 ( NULL , V_47 , & V_274 , V_303 ) ;
if ( V_219 < 0 )
return V_219 ;
F_248 ( F_251 ( V_47 ) , & V_274 ) ;
F_120 ( V_47 , V_147 ) ;
if ( F_1 ( F_23 ( V_47 ) ) )
F_2 ( V_6 ) ;
F_122 ( V_47 , V_6 , V_149 , L_18 ) ;
return 0 ;
}
static void F_252 ( unsigned int V_47 , unsigned int V_156 , T_8 V_45 )
{
struct V_305 V_274 ;
F_253 ( V_47 , & V_274 ) ;
V_274 . V_280 &= ~ ( V_306 | V_307 ) ;
V_274 . V_278 &= ~ ( V_308 ) ;
V_274 . V_280 |= F_254 ( V_45 ) | F_255 ( V_156 ) ;
V_274 . V_278 |= F_256 ( V_156 ) ;
F_257 ( V_47 , & V_274 ) ;
}
static int
F_258 ( struct V_83 * V_59 , const struct V_121 * V_71 , bool V_218 )
{
struct V_1 * V_2 = V_59 -> V_84 ;
unsigned int V_156 ;
if ( F_178 ( V_59 , V_71 , & V_156 ) )
return - 1 ;
F_252 ( V_59 -> V_47 , V_156 , V_2 -> V_45 ) ;
return V_220 ;
}
int F_259 ( unsigned int V_47 , struct V_271 * V_294 )
{
struct V_1 * V_2 ;
struct V_305 V_274 ;
unsigned V_156 ;
int V_98 ;
if ( V_276 )
return - V_277 ;
V_2 = V_1 ( V_47 ) ;
V_98 = F_111 ( V_47 , V_2 , V_54 -> V_157 () ) ;
if ( V_98 )
return V_98 ;
V_98 = V_54 -> V_158 ( V_2 -> V_43 ,
V_54 -> V_157 () , & V_156 ) ;
if ( V_98 )
return V_98 ;
V_274 . V_278 = F_256 ( V_156 ) ;
V_274 . V_280 =
V_309 |
F_255 ( V_156 ) |
F_254 ( V_2 -> V_45 ) |
( ( V_54 -> V_155 == 0 ) ?
V_310 :
V_311 ) |
V_312 |
( ( V_54 -> V_153 != V_284 ) ?
V_313 :
V_314 ) |
V_315 ;
F_257 ( V_47 , & V_274 ) ;
F_122 ( V_47 , & V_316 ,
V_149 , L_18 ) ;
F_235 ( V_96 , & V_294 -> V_294 , L_61 , V_47 ) ;
return 0 ;
}
static int
F_129 ( unsigned int V_47 , int V_32 , struct V_116 * V_151 )
{
struct V_1 * V_2 = F_28 ( V_47 , V_32 ) ;
int V_219 ;
if ( ! V_2 )
return - V_216 ;
V_219 = F_50 ( V_2 , V_32 , V_151 -> V_159 , V_151 -> V_160 ) ;
if ( ! V_219 )
F_125 ( V_47 , V_2 , V_151 ) ;
return V_219 ;
}
int F_134 ( unsigned int V_47 , int V_32 ,
struct V_116 * V_151 )
{
unsigned int V_7 = V_151 -> V_159 , V_62 = V_151 -> V_160 ;
int V_219 ;
if ( F_76 ( V_62 , V_8 [ V_7 ] . V_317 ) ) {
F_260 ( L_62 ,
F_3 ( V_7 ) , V_62 ) ;
return 0 ;
}
V_219 = F_129 ( V_47 , V_32 , V_151 ) ;
if ( ! V_219 )
F_261 ( V_62 , V_8 [ V_7 ] . V_317 ) ;
return V_219 ;
}
static int T_1 F_262 ( int V_159 )
{
union V_318 V_319 ;
unsigned long V_68 ;
F_44 ( & V_69 , V_68 ) ;
V_319 . V_182 = F_42 ( V_159 , 1 ) ;
F_45 ( & V_69 , V_68 ) ;
return V_319 . V_184 . V_320 + 1 ;
}
static void T_1 F_263 ( void )
{
int V_321 ;
V_321 = V_114 + V_113 ;
if ( V_321 > V_267 )
V_267 = V_321 ;
F_139 ( V_96 L_63 , V_267 ) ;
}
int F_264 ( void )
{
return V_267 ;
}
int T_1 F_265 ( void )
{
int V_321 ;
if ( V_322 > ( V_140 * V_133 ) )
V_322 = V_140 * V_133 ;
V_321 = V_267 + 8 * V_133 ;
#if F_266 ( V_323 ) || F_266 ( V_324 )
V_321 += V_267 * 16 ;
#endif
if ( V_321 < V_322 )
V_322 = V_321 ;
return V_113 ;
}
int F_267 ( struct V_325 * V_294 , int V_47 ,
struct V_116 * V_117 )
{
int V_32 ;
if ( ! F_92 ( V_47 ) ) {
F_10 ( V_256 , V_183 L_64 ,
V_117 -> V_159 ) ;
return - V_216 ;
}
V_32 = V_294 ? F_237 ( V_294 ) : F_18 ( 0 ) ;
return F_134 ( V_47 , V_32 , V_117 ) ;
}
static int T_1 F_268 ( int V_159 , int V_326 )
{
union V_176 V_177 ;
static T_6 V_327 = V_328 ;
T_6 V_187 ;
unsigned long V_68 ;
int V_20 = 0 ;
if ( F_269 ( V_327 ) )
V_54 -> V_180 ( & V_181 , & V_327 ) ;
F_44 ( & V_69 , V_68 ) ;
V_177 . V_182 = F_42 ( V_159 , 0 ) ;
F_45 ( & V_69 , V_68 ) ;
if ( V_326 >= F_145 () ) {
F_139 ( V_173 L_65
L_66 , V_159 , V_326 , V_177 . V_184 . V_185 ) ;
V_326 = V_177 . V_184 . V_185 ;
}
if ( V_54 -> V_186 ( & V_327 , V_326 ) ) {
for ( V_20 = 0 ; V_20 < F_145 () ; V_20 ++ ) {
if ( ! V_54 -> V_186 ( & V_327 , V_20 ) )
break;
}
if ( V_20 == F_145 () )
F_11 ( L_67 ) ;
F_139 ( V_173 L_68
L_69 , V_159 , V_326 , V_20 ) ;
V_326 = V_20 ;
}
V_54 -> V_188 ( V_326 , & V_187 ) ;
F_148 ( V_327 , V_327 , V_187 ) ;
if ( V_177 . V_184 . V_185 != V_326 ) {
V_177 . V_184 . V_185 = V_326 ;
F_44 ( & V_69 , V_68 ) ;
F_47 ( V_159 , 0 , V_177 . V_182 ) ;
V_177 . V_182 = F_42 ( V_159 , 0 ) ;
F_45 ( & V_69 , V_68 ) ;
if ( V_177 . V_184 . V_185 != V_326 ) {
F_16 ( L_70 ,
V_159 ) ;
return - 1 ;
}
}
F_10 ( V_21 , V_95
L_71 , V_159 , V_326 ) ;
return V_326 ;
}
static T_8 T_1 F_270 ( T_8 V_303 )
{
if ( ( V_190 . V_191 == V_192 ) &&
! F_151 ( V_193 [ V_194 ] ) )
return F_268 ( V_38 , V_303 ) ;
else
return V_303 ;
}
static T_8 T_1 F_270 ( T_8 V_303 )
{
int V_20 ;
F_271 ( V_329 , 256 ) ;
F_272 ( V_329 , 256 ) ;
for ( V_20 = 0 ; V_20 < V_38 ; V_20 ++ ) {
F_273 ( F_3 ( V_20 ) , V_329 ) ;
}
if ( ! F_76 ( V_303 , V_329 ) )
return V_303 ;
return F_274 ( V_329 , 256 ) ;
}
static int T_1 F_275 ( int V_159 )
{
union V_318 V_319 ;
unsigned long V_68 ;
F_44 ( & V_69 , V_68 ) ;
V_319 . V_182 = F_42 ( V_159 , 1 ) ;
F_45 ( & V_69 , V_68 ) ;
return V_319 . V_184 . V_330 ;
}
int F_276 ( T_3 V_111 , int * V_86 , int * V_105 )
{
int V_159 , V_62 , V_103 ;
if ( V_16 )
return - 1 ;
V_159 = F_132 ( V_111 ) ;
if ( V_159 < 0 )
return - 1 ;
V_62 = F_133 ( V_159 , V_111 ) ;
if ( V_62 < 0 )
return - 1 ;
V_103 = F_74 ( V_159 , V_62 , V_141 ) ;
if ( V_103 < 0 )
return - 1 ;
* V_86 = F_84 ( V_103 ) ;
* V_105 = F_80 ( V_103 ) ;
return 0 ;
}
void T_1 F_277 ( void )
{
int V_62 , V_159 , V_47 , V_331 ;
const struct V_121 * V_71 ;
struct V_83 * V_332 ;
if ( V_16 == 1 )
return;
for ( V_159 = 0 ; V_159 < V_38 ; V_159 ++ )
for ( V_62 = 0 ; V_62 < V_8 [ V_159 ] . V_41 ; V_62 ++ ) {
V_331 = F_74 ( V_159 , V_62 , V_141 ) ;
if ( V_331 == - 1 )
continue;
V_47 = F_89 ( V_331 , V_159 , V_62 ) ;
if ( ( V_159 > 0 ) && ( V_47 > 16 ) )
continue;
V_332 = F_278 ( V_47 ) ;
if ( ! F_279 ( V_332 ) || F_280 ( V_332 ) )
V_71 = V_332 -> V_217 ;
else
V_71 = V_54 -> V_157 () ;
if ( V_152 )
V_233 ( V_332 , V_71 , false ) ;
else
F_181 ( V_332 , V_71 , false ) ;
}
}
static struct V_333 * T_1 F_281 ( int V_38 )
{
unsigned long V_334 ;
struct V_333 * V_51 ;
char * V_335 ;
int V_20 ;
if ( V_38 <= 0 )
return NULL ;
V_334 = V_336 + sizeof( struct V_333 ) ;
V_334 *= V_38 ;
V_335 = F_282 ( V_334 ) ;
V_51 = ( void * ) V_335 ;
V_335 += sizeof( struct V_333 ) * V_38 ;
for ( V_20 = 0 ; V_20 < V_38 ; V_20 ++ ) {
V_51 [ V_20 ] . V_228 = V_335 ;
V_51 [ V_20 ] . V_68 = V_337 | V_338 ;
snprintf ( V_335 , V_336 , L_72 , V_20 ) ;
V_335 += V_336 ;
}
V_339 = V_51 ;
return V_51 ;
}
void T_1 F_283 ( void )
{
unsigned long V_340 , V_103 = V_341 ;
struct V_333 * V_342 ;
int V_20 ;
V_342 = F_281 ( V_38 ) ;
for ( V_20 = 0 ; V_20 < V_38 ; V_20 ++ ) {
if ( V_343 ) {
V_340 = F_4 ( V_20 ) ;
#ifdef F_90
if ( ! V_340 ) {
F_139 ( V_183
L_73
L_74
L_75 ) ;
V_343 = 0 ;
V_16 = 1 ;
goto V_344;
}
#endif
} else {
#ifdef F_90
V_344:
#endif
V_340 = ( unsigned long ) F_284 ( V_345 ) ;
V_340 = F_285 ( V_340 ) ;
}
F_286 ( V_103 , V_340 ) ;
F_10 ( V_21 , L_76 ,
F_287 ( V_103 ) + ( V_340 & ~ V_346 ) ,
V_340 ) ;
V_103 ++ ;
V_342 -> V_347 = V_340 ;
V_342 -> V_348 = V_340 + V_349 - 1 ;
V_342 ++ ;
}
F_263 () ;
}
void T_1 F_288 ( void )
{
int V_20 ;
struct V_333 * V_350 = V_339 ;
if ( ! V_350 ) {
if ( V_38 > 0 )
F_139 ( V_183
L_77 ) ;
return;
}
for ( V_20 = 0 ; V_20 < V_38 ; V_20 ++ ) {
F_289 ( & V_351 , V_350 ) ;
V_350 ++ ;
}
}
int F_132 ( T_3 V_111 )
{
int V_20 = 0 ;
if ( V_38 == 0 )
return - 1 ;
for ( V_20 = 0 ; V_20 < V_38 ; V_20 ++ ) {
struct V_12 * V_110 = F_5 ( V_20 ) ;
if ( ( V_111 >= V_110 -> V_112 )
&& ( V_111 <= V_110 -> V_352 ) )
return V_20 ;
}
F_139 ( V_183 L_78 , V_111 ) ;
return - 1 ;
}
int F_133 ( int V_159 , T_3 V_111 )
{
struct V_12 * V_110 ;
if ( F_290 ( V_159 == - 1 ) )
return - 1 ;
V_110 = F_5 ( V_159 ) ;
if ( F_290 ( V_111 > V_110 -> V_352 ) )
return - 1 ;
return V_111 - V_110 -> V_112 ;
}
static T_1 int F_291 ( unsigned long V_353 )
{
if ( V_38 >= V_354 ) {
F_83 ( L_79 ,
V_354 , V_38 ) ;
return 1 ;
}
if ( ! V_353 ) {
F_83 ( L_80 ) ;
return 1 ;
}
return 0 ;
}
static T_1 int F_292 ( int V_103 )
{
union V_176 V_177 ;
union V_318 V_319 ;
union V_355 V_356 ;
V_177 . V_182 = F_42 ( V_103 , 0 ) ;
V_319 . V_182 = F_42 ( V_103 , 1 ) ;
V_356 . V_182 = F_42 ( V_103 , 2 ) ;
if ( V_177 . V_182 == - 1 && V_319 . V_182 == - 1 && V_356 . V_182 == - 1 ) {
F_83 ( L_81 ,
F_4 ( V_103 ) ) ;
return 1 ;
}
return 0 ;
}
void T_1 F_293 ( int V_303 , T_3 V_353 , T_3 V_112 )
{
int V_103 = 0 ;
int V_320 ;
struct V_12 * V_110 ;
if ( F_291 ( V_353 ) )
return;
V_103 = V_38 ;
V_8 [ V_103 ] . V_9 . type = V_357 ;
V_8 [ V_103 ] . V_9 . V_68 = V_358 ;
V_8 [ V_103 ] . V_9 . V_11 = V_353 ;
F_286 ( V_341 + V_103 , V_353 ) ;
if ( F_292 ( V_103 ) ) {
F_294 ( V_341 + V_103 ) ;
return;
}
V_8 [ V_103 ] . V_9 . V_10 = F_270 ( V_303 ) ;
V_8 [ V_103 ] . V_9 . V_359 = F_275 ( V_103 ) ;
V_320 = F_262 ( V_103 ) ;
V_110 = F_5 ( V_103 ) ;
V_110 -> V_112 = V_112 ;
V_110 -> V_352 = V_112 + V_320 - 1 ;
V_8 [ V_103 ] . V_41 = V_320 ;
if ( V_110 -> V_352 >= V_114 )
V_114 = V_110 -> V_352 + 1 ;
F_295 ( L_82 ,
V_103 , F_3 ( V_103 ) ,
F_65 ( V_103 ) , F_4 ( V_103 ) ,
V_110 -> V_112 , V_110 -> V_352 ) ;
V_38 ++ ;
}
void T_1 F_296 ( void )
{
struct V_116 V_151 = { 0 , 0 , 0 , 0 } ;
F_139 ( V_95 L_83 ) ;
#ifndef V_215
F_297 ( V_194 ,
& V_181 ) ;
#endif
F_298 () ;
F_129 ( 0 , 0 , & V_151 ) ;
F_122 ( 0 , & V_142 , V_149 ,
L_18 ) ;
}
