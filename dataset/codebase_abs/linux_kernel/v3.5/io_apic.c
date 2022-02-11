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
F_52 ( V_75 L_5 ,
V_32 , V_54 , V_62 ) ;
return - V_76 ;
}
V_67 -> V_54 = V_54 ;
V_67 -> V_62 = V_62 ;
* V_72 = V_67 ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 , int V_32 , int V_54 , int V_62 )
{
if ( F_50 ( V_2 , V_32 , V_54 , V_62 ) )
F_11 ( L_6 ) ;
}
static void T_1 F_54 ( struct V_1 * V_2 , int V_32 ,
int V_77 , int V_78 ,
int V_79 , int V_80 )
{
struct V_31 * V_67 ;
F_51 (entry, cfg->irq_2_pin) {
if ( V_67 -> V_54 == V_77 && V_67 -> V_62 == V_78 ) {
V_67 -> V_54 = V_79 ;
V_67 -> V_62 = V_80 ;
return;
}
}
F_53 ( V_2 , V_32 , V_79 , V_80 ) ;
}
static void F_55 ( struct V_31 * V_67 ,
int V_81 , int V_82 ,
void (* F_56)( struct V_31 * V_67 ) )
{
unsigned int V_57 , V_62 ;
V_62 = V_67 -> V_62 ;
V_57 = F_42 ( V_67 -> V_54 , 0x10 + V_62 * 2 ) ;
V_57 &= V_81 ;
V_57 |= V_82 ;
F_57 ( V_67 -> V_54 , 0x10 + V_62 * 2 , V_57 ) ;
if ( F_56 )
F_56 ( V_67 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
int V_81 , int V_82 ,
void (* F_56)( struct V_31 * V_67 ) )
{
struct V_31 * V_67 ;
F_51 (entry, cfg->irq_2_pin)
F_55 ( V_67 , V_81 , V_82 , F_56 ) ;
}
static void F_59 ( struct V_31 * V_67 )
{
struct V_55 T_2 * V_55 ;
V_55 = F_35 ( V_67 -> V_54 ) ;
F_38 ( & V_55 -> V_59 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
unsigned long V_68 ;
F_44 ( & V_69 , V_68 ) ;
F_58 ( V_2 , ~ 0 , V_83 , & F_59 ) ;
F_45 ( & V_69 , V_68 ) ;
}
static void F_61 ( struct V_84 * V_59 )
{
F_60 ( V_59 -> V_85 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_58 ( V_2 , ~ V_83 , 0 , NULL ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
unsigned long V_68 ;
F_44 ( & V_69 , V_68 ) ;
F_62 ( V_2 ) ;
F_45 ( & V_69 , V_68 ) ;
}
static void F_64 ( struct V_84 * V_59 )
{
F_63 ( V_59 -> V_85 ) ;
}
static void F_65 ( int V_54 , int V_62 , int V_45 , struct V_1 * V_2 )
{
if ( F_66 ( V_54 ) >= 0x20 ) {
if ( V_2 && F_1 ( V_2 ) )
F_34 ( V_54 , V_62 ) ;
else
F_34 ( V_54 , V_45 ) ;
} else {
struct V_40 V_67 , V_86 ;
V_67 = V_86 = F_41 ( V_54 , V_62 ) ;
V_86 . V_71 = 1 ;
V_86 . V_87 = V_88 ;
F_46 ( V_54 , V_62 , V_86 ) ;
F_46 ( V_54 , V_62 , V_67 ) ;
}
}
static void F_67 ( unsigned int V_47 , struct V_1 * V_2 )
{
struct V_31 * V_67 ;
unsigned long V_68 ;
F_44 ( & V_69 , V_68 ) ;
F_51 (entry, cfg->irq_2_pin)
F_65 ( V_67 -> V_54 , V_67 -> V_62 , V_2 -> V_45 , V_2 ) ;
F_45 ( & V_69 , V_68 ) ;
}
static void F_68 ( unsigned int V_54 , unsigned int V_62 )
{
struct V_40 V_67 ;
V_67 = F_43 ( V_54 , V_62 ) ;
if ( V_67 . V_89 == V_90 )
return;
if ( ! V_67 . V_71 ) {
V_67 . V_71 = 1 ;
F_48 ( V_54 , V_62 , V_67 ) ;
V_67 = F_43 ( V_54 , V_62 ) ;
}
if ( V_67 . V_91 ) {
unsigned long V_68 ;
if ( ! V_67 . V_87 ) {
V_67 . V_87 = V_92 ;
F_48 ( V_54 , V_62 , V_67 ) ;
}
F_44 ( & V_69 , V_68 ) ;
F_65 ( V_54 , V_62 , V_67 . V_45 , NULL ) ;
F_45 ( & V_69 , V_68 ) ;
}
F_49 ( V_54 , V_62 ) ;
V_67 = F_43 ( V_54 , V_62 ) ;
if ( V_67 . V_91 )
F_52 ( V_75 L_7 ,
F_3 ( V_54 ) , V_62 ) ;
}
static void F_69 ( void )
{
int V_54 , V_62 ;
for ( V_54 = 0 ; V_54 < V_38 ; V_54 ++ )
for ( V_62 = 0 ; V_62 < V_8 [ V_54 ] . V_41 ; V_62 ++ )
F_68 ( V_54 , V_62 ) ;
}
static int T_1 F_70 ( char * V_17 )
{
int V_20 , V_93 ;
int V_94 [ V_95 + 1 ] ;
F_71 ( V_17 , F_17 ( V_94 ) , V_94 ) ;
F_10 ( V_21 , V_96
L_8 ) ;
V_93 = V_95 ;
if ( V_94 [ 0 ] < V_95 )
V_93 = V_94 [ 0 ] ;
for ( V_20 = 0 ; V_20 < V_93 ; V_20 ++ ) {
F_10 ( V_21 , V_97
L_9 , V_20 , V_94 [ V_20 + 1 ] ) ;
V_98 [ V_95 - V_20 - 1 ] = V_94 [ V_20 + 1 ] ;
}
return 1 ;
}
int F_72 ( void )
{
int V_54 , V_62 ;
int V_99 = 0 ;
for ( V_54 = 0 ; V_54 < V_38 ; V_54 ++ ) {
if ( ! V_8 [ V_54 ] . V_39 ) {
V_99 = - V_76 ;
continue;
}
for ( V_62 = 0 ; V_62 < V_8 [ V_54 ] . V_41 ; V_62 ++ )
V_8 [ V_54 ] . V_39 [ V_62 ] =
F_43 ( V_54 , V_62 ) ;
}
return V_99 ;
}
void F_73 ( void )
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
int F_74 ( void )
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
static int F_75 ( int V_7 , int V_62 , int type )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ )
if ( V_29 [ V_20 ] . V_22 == type &&
( V_29 [ V_20 ] . V_26 == F_3 ( V_7 ) ||
V_29 [ V_20 ] . V_26 == V_100 ) &&
V_29 [ V_20 ] . V_27 == V_62 )
return V_20 ;
return - 1 ;
}
static int T_1 F_76 ( int V_47 , int type )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ ) {
int V_101 = V_29 [ V_20 ] . V_24 ;
if ( F_77 ( V_101 , V_102 ) &&
( V_29 [ V_20 ] . V_22 == type ) &&
( V_29 [ V_20 ] . V_25 == V_47 ) )
return V_29 [ V_20 ] . V_27 ;
}
return - 1 ;
}
static int T_1 F_78 ( int V_47 , int type )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ ) {
int V_101 = V_29 [ V_20 ] . V_24 ;
if ( F_77 ( V_101 , V_102 ) &&
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
static int F_79 ( unsigned int V_47 )
{
if ( V_47 < V_35 -> V_36 ) {
unsigned int V_103 = 0x4d0 + ( V_47 >> 3 ) ;
return ( F_80 ( V_103 ) >> ( V_47 & 7 ) ) & 1 ;
}
F_10 ( V_21 , V_96
L_10 , V_47 ) ;
return 0 ;
}
static int F_81 ( int V_104 )
{
int V_105 = V_29 [ V_104 ] . V_24 ;
int V_106 ;
switch ( V_29 [ V_104 ] . V_23 & 3 )
{
case 0 :
if ( F_77 ( V_105 , V_102 ) )
V_106 = F_82 ( V_104 ) ;
else
V_106 = F_83 ( V_104 ) ;
break;
case 1 :
{
V_106 = 0 ;
break;
}
case 2 :
{
F_52 ( V_107 L_11 ) ;
V_106 = 1 ;
break;
}
case 3 :
{
V_106 = 1 ;
break;
}
default:
{
F_52 ( V_107 L_11 ) ;
V_106 = 1 ;
break;
}
}
return V_106 ;
}
static int F_84 ( int V_104 )
{
int V_105 = V_29 [ V_104 ] . V_24 ;
int V_87 ;
switch ( ( V_29 [ V_104 ] . V_23 >> 2 ) & 3 )
{
case 0 :
if ( F_77 ( V_105 , V_102 ) )
V_87 = F_85 ( V_104 ) ;
else
V_87 = F_86 ( V_104 ) ;
#ifdef F_87
switch ( V_108 [ V_105 ] ) {
case V_109 :
{
break;
}
case V_110 :
{
V_87 = F_88 ( V_104 ) ;
break;
}
case V_111 :
{
break;
}
default:
{
F_52 ( V_107 L_11 ) ;
V_87 = 1 ;
break;
}
}
#endif
break;
case 1 :
{
V_87 = 0 ;
break;
}
case 2 :
{
F_52 ( V_107 L_11 ) ;
V_87 = 1 ;
break;
}
case 3 :
{
V_87 = 1 ;
break;
}
default:
{
F_52 ( V_107 L_11 ) ;
V_87 = 0 ;
break;
}
}
return V_87 ;
}
static int F_89 ( int V_104 , int V_54 , int V_62 )
{
int V_47 ;
int V_105 = V_29 [ V_104 ] . V_24 ;
struct V_12 * V_112 = F_5 ( V_54 ) ;
if ( V_29 [ V_104 ] . V_27 != V_62 )
F_52 ( V_75 L_12 ) ;
if ( F_77 ( V_105 , V_102 ) ) {
V_47 = V_29 [ V_104 ] . V_25 ;
} else {
T_3 V_113 = V_112 -> V_114 + V_62 ;
if ( V_113 >= V_115 )
V_47 = V_113 ;
else
V_47 = V_116 + V_113 ;
}
#ifdef F_90
if ( ( V_62 >= 16 ) && ( V_62 <= 23 ) ) {
if ( V_98 [ V_62 - 16 ] != - 1 ) {
if ( ! V_98 [ V_62 - 16 ] ) {
F_10 ( V_21 , V_97
L_13 , V_62 - 16 ) ;
} else {
V_47 = V_98 [ V_62 - 16 ] ;
F_10 ( V_21 , V_97
L_14 ,
V_62 - 16 , V_47 ) ;
}
}
}
#endif
return V_47 ;
}
int F_91 ( int V_105 , int V_117 , int V_62 ,
struct V_118 * V_119 )
{
int V_7 , V_20 , V_120 = - 1 ;
F_10 ( V_121 ,
L_15 ,
V_105 , V_117 , V_62 ) ;
if ( F_77 ( V_105 , V_102 ) ) {
F_10 ( V_21 ,
L_16 , V_105 ) ;
return - 1 ;
}
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ ) {
int V_101 = V_29 [ V_20 ] . V_24 ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ )
if ( F_3 ( V_7 ) == V_29 [ V_20 ] . V_26 ||
V_29 [ V_20 ] . V_26 == V_100 )
break;
if ( ! F_77 ( V_101 , V_102 ) &&
! V_29 [ V_20 ] . V_22 &&
( V_105 == V_101 ) &&
( V_117 == ( ( V_29 [ V_20 ] . V_25 >> 2 ) & 0x1f ) ) ) {
int V_47 = F_89 ( V_20 , V_7 , V_29 [ V_20 ] . V_27 ) ;
if ( ! ( V_7 || F_92 ( V_47 ) ) )
continue;
if ( V_62 == ( V_29 [ V_20 ] . V_25 & 3 ) ) {
F_93 ( V_119 , V_7 ,
V_29 [ V_20 ] . V_27 ,
F_84 ( V_20 ) ,
F_81 ( V_20 ) ) ;
return V_47 ;
}
if ( V_120 < 0 ) {
F_93 ( V_119 , V_7 ,
V_29 [ V_20 ] . V_27 ,
F_84 ( V_20 ) ,
F_81 ( V_20 ) ) ;
V_120 = V_47 ;
}
}
}
return V_120 ;
}
void F_94 ( void )
{
F_95 ( & V_122 ) ;
}
void F_96 ( void )
{
F_97 ( & V_122 ) ;
}
static int
F_98 ( int V_47 , struct V_1 * V_2 , const struct V_123 * V_71 )
{
static int V_124 = V_125 + V_126 ;
static int V_127 = V_126 % 8 ;
unsigned int V_128 ;
int V_129 , V_99 ;
T_4 V_130 ;
if ( V_2 -> V_131 )
return - V_132 ;
if ( ! F_99 ( & V_130 , V_133 ) )
return - V_76 ;
V_128 = V_2 -> V_45 ;
if ( V_128 ) {
F_100 ( V_130 , V_71 , V_134 ) ;
F_100 ( V_130 , V_2 -> V_43 , V_130 ) ;
if ( ! F_101 ( V_130 ) ) {
F_25 ( V_130 ) ;
return 0 ;
}
}
V_99 = - V_135 ;
F_102 (cpu, mask, cpu_online_mask) {
int V_136 ;
int V_45 , V_137 ;
V_54 -> V_138 ( V_129 , V_130 ) ;
V_45 = V_124 ;
V_137 = V_127 ;
V_74:
V_45 += 8 ;
if ( V_45 >= V_139 ) {
V_137 = ( V_137 + 1 ) % 8 ;
V_45 = V_125 + V_137 ;
}
if ( F_103 ( V_124 == V_45 ) )
continue;
if ( F_77 ( V_45 , V_140 ) )
goto V_74;
F_102 (new_cpu, tmp_mask, cpu_online_mask)
if ( F_104 ( V_141 , V_136 ) [ V_45 ] != - 1 )
goto V_74;
V_124 = V_45 ;
V_127 = V_137 ;
if ( V_128 ) {
V_2 -> V_131 = 1 ;
F_105 ( V_2 -> V_44 , V_2 -> V_43 ) ;
}
F_102 (new_cpu, tmp_mask, cpu_online_mask)
F_104 ( V_141 , V_136 ) [ V_45 ] = V_47 ;
V_2 -> V_45 = V_45 ;
F_105 ( V_2 -> V_43 , V_130 ) ;
V_99 = 0 ;
break;
}
F_25 ( V_130 ) ;
return V_99 ;
}
int F_106 ( int V_47 , struct V_1 * V_2 , const struct V_123 * V_71 )
{
int V_99 ;
unsigned long V_68 ;
F_44 ( & V_122 , V_68 ) ;
V_99 = F_98 ( V_47 , V_2 , V_71 ) ;
F_45 ( & V_122 , V_68 ) ;
return V_99 ;
}
static void F_107 ( int V_47 , struct V_1 * V_2 )
{
int V_129 , V_45 ;
F_108 ( ! V_2 -> V_45 ) ;
V_45 = V_2 -> V_45 ;
F_109 (cpu, cfg->domain)
F_104 ( V_141 , V_129 ) [ V_45 ] = - 1 ;
V_2 -> V_45 = 0 ;
F_110 ( V_2 -> V_43 ) ;
if ( F_111 ( ! V_2 -> V_131 ) )
return;
F_109 (cpu, cfg->old_domain) {
for ( V_45 = V_125 ; V_45 < V_142 ;
V_45 ++ ) {
if ( F_104 ( V_141 , V_129 ) [ V_45 ] != V_47 )
continue;
F_104 ( V_141 , V_129 ) [ V_45 ] = - 1 ;
break;
}
}
V_2 -> V_131 = 0 ;
}
void F_112 ( int V_129 )
{
int V_47 , V_45 ;
struct V_1 * V_2 ;
F_95 ( & V_122 ) ;
F_113 (irq) {
V_2 = F_23 ( V_47 ) ;
if ( ! V_2 )
continue;
if ( V_47 < V_35 -> V_36 && ! F_92 ( V_47 ) )
F_22 ( V_129 , V_2 -> V_43 ) ;
if ( ! F_114 ( V_129 , V_2 -> V_43 ) )
continue;
V_45 = V_2 -> V_45 ;
F_104 ( V_141 , V_129 ) [ V_45 ] = V_47 ;
}
for ( V_45 = 0 ; V_45 < V_142 ; ++ V_45 ) {
V_47 = F_104 ( V_141 , V_129 ) [ V_45 ] ;
if ( V_47 < 0 )
continue;
V_2 = V_1 ( V_47 ) ;
if ( ! F_114 ( V_129 , V_2 -> V_43 ) )
F_104 ( V_141 , V_129 ) [ V_45 ] = - 1 ;
}
F_97 ( & V_122 ) ;
}
static inline int F_115 ( int V_47 )
{
int V_54 , V_104 , V_62 ;
for ( V_54 = 0 ; V_54 < V_38 ; V_54 ++ ) {
for ( V_62 = 0 ; V_62 < V_8 [ V_54 ] . V_41 ; V_62 ++ ) {
V_104 = F_75 ( V_54 , V_62 , V_143 ) ;
if ( ( V_104 != - 1 ) && ( V_47 == F_89 ( V_104 , V_54 , V_62 ) ) )
return F_84 ( V_104 ) ;
}
}
return 0 ;
}
static inline int F_115 ( int V_47 )
{
return 1 ;
}
static void F_116 ( unsigned int V_47 , struct V_1 * V_2 ,
unsigned long V_87 )
{
struct V_5 * V_6 = & V_144 ;
T_5 V_145 ;
bool V_146 ;
if ( ( V_87 == V_147 && F_115 ( V_47 ) ) ||
V_87 == V_92 ) {
F_117 ( V_47 , V_148 ) ;
V_146 = true ;
} else {
F_118 ( V_47 , V_148 ) ;
V_146 = false ;
}
if ( F_1 ( V_2 ) ) {
F_117 ( V_47 , V_149 ) ;
F_2 ( V_6 ) ;
V_146 = V_87 != 0 ;
}
V_145 = V_146 ? V_150 : V_151 ;
F_119 ( V_47 , V_6 , V_145 ,
V_146 ? L_17 : L_18 ) ;
}
static int F_120 ( int V_47 , struct V_40 * V_67 ,
unsigned int V_152 , int V_45 ,
struct V_118 * V_153 )
{
if ( V_154 )
return F_121 ( V_47 , V_67 , V_152 ,
V_45 , V_153 ) ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_67 -> V_89 = V_54 -> V_155 ;
V_67 -> V_156 = V_54 -> V_157 ;
V_67 -> V_158 = V_152 ;
V_67 -> V_45 = V_45 ;
V_67 -> V_71 = 0 ;
V_67 -> V_87 = V_153 -> V_87 ;
V_67 -> V_106 = V_153 -> V_106 ;
if ( V_153 -> V_87 )
V_67 -> V_71 = 1 ;
return 0 ;
}
static void F_122 ( unsigned int V_47 , struct V_1 * V_2 ,
struct V_118 * V_153 )
{
struct V_40 V_67 ;
unsigned int V_158 ;
if ( ! F_92 ( V_47 ) )
return;
if ( V_47 < V_35 -> V_36 && F_114 ( 0 , V_2 -> V_43 ) )
V_54 -> V_138 ( 0 , V_2 -> V_43 ) ;
if ( F_106 ( V_47 , V_2 , V_54 -> V_159 () ) )
return;
V_158 = V_54 -> V_160 ( V_2 -> V_43 , V_54 -> V_159 () ) ;
F_10 ( V_21 , V_97
L_19
L_20 ,
V_153 -> V_161 , F_3 ( V_153 -> V_161 ) , V_153 -> V_162 ,
V_2 -> V_45 , V_47 , V_153 -> V_87 , V_153 -> V_106 , V_158 ) ;
if ( F_120 ( V_47 , & V_67 , V_158 , V_2 -> V_45 , V_153 ) ) {
F_123 ( L_21 ,
F_3 ( V_153 -> V_161 ) , V_153 -> V_162 ) ;
F_107 ( V_47 , V_2 ) ;
return;
}
F_116 ( V_47 , V_2 , V_153 -> V_87 ) ;
if ( V_47 < V_35 -> V_36 )
V_35 -> V_71 ( V_47 ) ;
F_48 ( V_153 -> V_161 , V_153 -> V_162 , V_67 ) ;
}
static bool T_1 F_124 ( int V_104 , int V_7 , int V_62 )
{
if ( V_104 != - 1 )
return false ;
F_10 ( V_21 , V_97 L_22 ,
F_3 ( V_7 ) , V_62 ) ;
return true ;
}
static void T_1 F_125 ( unsigned int V_7 )
{
int V_104 , V_32 = F_18 ( 0 ) ;
struct V_118 V_153 ;
unsigned int V_62 , V_47 ;
for ( V_62 = 0 ; V_62 < V_8 [ V_7 ] . V_41 ; V_62 ++ ) {
V_104 = F_75 ( V_7 , V_62 , V_143 ) ;
if ( F_124 ( V_104 , V_7 , V_62 ) )
continue;
V_47 = F_89 ( V_104 , V_7 , V_62 ) ;
if ( ( V_7 > 0 ) && ( V_47 > 16 ) )
continue;
if ( V_54 -> V_163 &&
V_54 -> V_163 ( V_7 , V_47 ) )
continue;
F_93 ( & V_153 , V_7 , V_62 , F_84 ( V_104 ) ,
F_81 ( V_104 ) ) ;
F_126 ( V_47 , V_32 , & V_153 ) ;
}
}
static void T_1 F_127 ( void )
{
unsigned int V_7 ;
F_10 ( V_21 , V_97 L_23 ) ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ )
F_125 ( V_7 ) ;
}
void F_128 ( T_3 V_113 )
{
int V_7 = 0 , V_62 , V_104 , V_47 , V_32 = F_18 ( 0 ) ;
struct V_118 V_153 ;
V_7 = F_129 ( V_113 ) ;
if ( V_7 < 0 )
return;
V_62 = F_130 ( V_7 , V_113 ) ;
V_104 = F_75 ( V_7 , V_62 , V_143 ) ;
if ( V_104 == - 1 )
return;
V_47 = F_89 ( V_104 , V_7 , V_62 ) ;
if ( V_7 == 0 || V_47 < V_115 )
return;
F_93 ( & V_153 , V_7 , V_62 , F_84 ( V_104 ) ,
F_81 ( V_104 ) ) ;
F_131 ( V_47 , V_32 , & V_153 ) ;
}
static void T_1 F_132 ( unsigned int V_7 ,
unsigned int V_62 , int V_45 )
{
struct V_40 V_67 ;
if ( V_154 )
return;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_156 = V_54 -> V_157 ;
V_67 . V_71 = 0 ;
V_67 . V_158 = V_54 -> V_164 ( V_54 -> V_159 () ) ;
V_67 . V_89 = V_54 -> V_155 ;
V_67 . V_106 = 0 ;
V_67 . V_87 = 0 ;
V_67 . V_45 = V_45 ;
F_119 ( 0 , & V_144 , V_151 ,
L_18 ) ;
F_48 ( V_7 , V_62 , V_67 ) ;
}
static T_1 int F_133 ( char * V_165 )
{
int V_166 = - 1 ;
if ( strcmp ( V_165 , L_24 ) == 0 ) {
V_167 = V_168 ;
} else {
F_134 ( & V_165 , & V_166 ) ;
if ( V_166 >= 0 )
V_167 = V_166 ;
}
return 1 ;
}
void T_1 F_135 ( void )
{
int V_169 , V_170 ;
int V_54 ;
if ( ! V_35 -> V_36 )
return;
for( V_54 = 0 ; V_54 < V_38 ; V_54 ++ ) {
int V_62 ;
for ( V_62 = 0 ; V_62 < V_8 [ V_54 ] . V_41 ; V_62 ++ ) {
struct V_40 V_67 ;
V_67 = F_43 ( V_54 , V_62 ) ;
if ( ( V_67 . V_71 == 0 ) && ( V_67 . V_89 == V_171 ) ) {
V_172 . V_54 = V_54 ;
V_172 . V_62 = V_62 ;
goto V_173;
}
}
}
V_173:
V_170 = F_76 ( 0 , V_174 ) ;
V_169 = F_78 ( 0 , V_174 ) ;
if ( ( V_172 . V_62 == - 1 ) && ( V_170 >= 0 ) ) {
F_52 ( V_107 L_25 ) ;
V_172 . V_62 = V_170 ;
V_172 . V_54 = V_169 ;
}
if ( ( ( V_172 . V_54 != V_169 ) || ( V_172 . V_62 != V_170 ) ) &&
( V_170 >= 0 ) && ( V_172 . V_62 >= 0 ) )
{
F_52 ( V_107 L_26 ) ;
}
F_69 () ;
}
void F_136 ( void )
{
F_69 () ;
if ( ! V_35 -> V_36 )
return;
if ( V_172 . V_62 != - 1 && ! V_154 ) {
struct V_40 V_67 ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_71 = 0 ;
V_67 . V_87 = 0 ;
V_67 . V_91 = 0 ;
V_67 . V_106 = 0 ;
V_67 . V_175 = 0 ;
V_67 . V_156 = 0 ;
V_67 . V_89 = V_171 ;
V_67 . V_45 = 0 ;
V_67 . V_158 = F_137 () ;
F_48 ( V_172 . V_54 , V_172 . V_62 , V_67 ) ;
}
if ( V_176 || F_138 () )
F_139 ( ! V_154 &&
V_172 . V_62 != - 1 ) ;
}
void T_1 F_140 ( void )
{
union V_177 V_178 ;
T_6 V_179 ;
int V_7 ;
int V_20 ;
unsigned char V_180 ;
unsigned long V_68 ;
V_54 -> V_181 ( & V_182 , & V_179 ) ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ ) {
F_44 ( & V_69 , V_68 ) ;
V_178 . V_183 = F_42 ( V_7 , 0 ) ;
F_45 ( & V_69 , V_68 ) ;
V_180 = F_3 ( V_7 ) ;
if ( F_3 ( V_7 ) >= F_141 () ) {
F_52 ( V_75 L_27 ,
V_7 , F_3 ( V_7 ) ) ;
F_52 ( V_75 L_28 ,
V_178 . V_184 . V_185 ) ;
V_8 [ V_7 ] . V_9 . V_10 = V_178 . V_184 . V_185 ;
}
if ( V_54 -> V_186 ( & V_179 ,
F_3 ( V_7 ) ) ) {
F_52 ( V_75 L_29 ,
V_7 , F_3 ( V_7 ) ) ;
for ( V_20 = 0 ; V_20 < F_141 () ; V_20 ++ )
if ( ! F_142 ( V_20 , V_179 ) )
break;
if ( V_20 >= F_141 () )
F_11 ( L_30 ) ;
F_52 ( V_75 L_28 ,
V_20 ) ;
F_143 ( V_20 , V_179 ) ;
V_8 [ V_7 ] . V_9 . V_10 = V_20 ;
} else {
T_6 V_187 ;
V_54 -> V_188 ( F_3 ( V_7 ) ,
& V_187 ) ;
F_10 ( V_21 , L_31
L_32 ,
F_3 ( V_7 ) ) ;
F_144 ( V_179 , V_179 , V_187 ) ;
}
if ( V_180 != F_3 ( V_7 ) )
for ( V_20 = 0 ; V_20 < V_28 ; V_20 ++ )
if ( V_29 [ V_20 ] . V_26 == V_180 )
V_29 [ V_20 ] . V_26
= F_3 ( V_7 ) ;
if ( F_3 ( V_7 ) == V_178 . V_184 . V_185 )
continue;
F_10 ( V_21 , V_96
L_33 ,
F_3 ( V_7 ) ) ;
V_178 . V_184 . V_185 = F_3 ( V_7 ) ;
F_44 ( & V_69 , V_68 ) ;
F_47 ( V_7 , 0 , V_178 . V_183 ) ;
F_45 ( & V_69 , V_68 ) ;
F_44 ( & V_69 , V_68 ) ;
V_178 . V_183 = F_42 ( V_7 , 0 ) ;
F_45 ( & V_69 , V_68 ) ;
if ( V_178 . V_184 . V_185 != F_3 ( V_7 ) )
F_52 ( L_34 ) ;
else
F_10 ( V_21 , L_35 ) ;
}
}
void T_1 F_145 ( void )
{
if ( V_189 )
return;
if ( ! ( V_190 . V_191 == V_192 )
|| F_146 ( V_193 [ V_194 ] ) )
return;
F_140 () ;
}
static int T_1 F_147 ( char * V_195 )
{
V_196 = 1 ;
return 1 ;
}
static int T_1 F_148 ( void )
{
unsigned long V_197 = V_198 ;
unsigned long V_68 ;
if ( V_196 )
return 1 ;
F_149 ( V_68 ) ;
F_150 () ;
F_151 ( ( 10 * 1000 ) / V_199 ) ;
F_152 ( V_68 ) ;
if ( F_153 ( V_198 , V_197 + 4 ) )
return 1 ;
return 0 ;
}
static unsigned int F_154 ( struct V_84 * V_59 )
{
int V_200 = 0 , V_47 = V_59 -> V_47 ;
unsigned long V_68 ;
F_44 ( & V_69 , V_68 ) ;
if ( V_47 < V_35 -> V_36 ) {
V_35 -> V_71 ( V_47 ) ;
if ( V_35 -> V_201 ( V_47 ) )
V_200 = 1 ;
}
F_62 ( V_59 -> V_85 ) ;
F_45 ( & V_69 , V_68 ) ;
return V_200 ;
}
static int F_155 ( struct V_84 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_85 ;
unsigned long V_68 ;
F_44 ( & V_122 , V_68 ) ;
V_54 -> V_202 ( F_156 ( F_157 ( V_2 -> V_43 ) ) , V_2 -> V_45 ) ;
F_45 ( & V_122 , V_68 ) ;
return 1 ;
}
void F_158 ( struct V_1 * V_2 )
{
T_4 V_203 ;
if ( F_103 ( ! F_99 ( & V_203 , V_133 ) ) ) {
unsigned int V_20 ;
F_102 (i, cfg->old_domain, cpu_online_mask)
V_54 -> V_202 ( F_156 ( V_20 ) , V_204 ) ;
} else {
F_100 ( V_203 , V_2 -> V_44 , V_134 ) ;
V_54 -> V_202 ( V_203 , V_204 ) ;
F_25 ( V_203 ) ;
}
V_2 -> V_131 = 0 ;
}
static void F_159 ( unsigned int V_47 , unsigned int V_158 , struct V_1 * V_2 )
{
int V_54 , V_62 ;
struct V_31 * V_67 ;
T_7 V_45 = V_2 -> V_45 ;
F_51 (entry, cfg->irq_2_pin) {
unsigned int V_57 ;
V_54 = V_67 -> V_54 ;
V_62 = V_67 -> V_62 ;
if ( ! F_1 ( V_2 ) )
F_47 ( V_54 , 0x11 + V_62 * 2 , V_158 ) ;
V_57 = F_42 ( V_54 , 0x10 + V_62 * 2 ) ;
V_57 &= ~ V_205 ;
V_57 |= V_45 ;
F_57 ( V_54 , 0x10 + V_62 * 2 , V_57 ) ;
}
}
int F_160 ( struct V_84 * V_59 , const struct V_123 * V_71 ,
unsigned int * V_206 )
{
struct V_1 * V_2 = V_59 -> V_85 ;
if ( ! F_161 ( V_71 , V_134 ) )
return - 1 ;
if ( F_106 ( V_59 -> V_47 , V_59 -> V_85 , V_71 ) )
return - 1 ;
F_105 ( V_59 -> V_207 , V_71 ) ;
* V_206 = V_54 -> V_160 ( V_71 , V_2 -> V_43 ) ;
return 0 ;
}
static int
F_162 ( struct V_84 * V_59 , const struct V_123 * V_71 ,
bool V_208 )
{
unsigned int V_158 , V_47 = V_59 -> V_47 ;
unsigned long V_68 ;
int V_209 ;
F_44 ( & V_69 , V_68 ) ;
V_209 = F_160 ( V_59 , V_71 , & V_158 ) ;
if ( ! V_209 ) {
V_158 = F_163 ( V_158 ) ;
F_159 ( V_47 , V_158 , V_59 -> V_85 ) ;
}
F_45 ( & V_69 , V_68 ) ;
return V_209 ;
}
T_8 void F_164 ( void )
{
unsigned V_45 , V_210 ;
F_165 () ;
F_166 () ;
F_167 () ;
V_210 = F_168 () ;
for ( V_45 = V_125 ; V_45 < V_142 ; V_45 ++ ) {
unsigned int V_47 ;
unsigned int V_91 ;
struct V_211 * V_212 ;
struct V_1 * V_2 ;
V_47 = F_169 ( V_141 [ V_45 ] ) ;
if ( V_47 == - 1 )
continue;
V_212 = F_170 ( V_47 ) ;
if ( ! V_212 )
continue;
V_2 = V_1 ( V_47 ) ;
F_95 ( & V_212 -> V_213 ) ;
if ( V_2 -> V_131 )
goto V_214;
if ( V_45 == V_2 -> V_45 && F_114 ( V_210 , V_2 -> V_43 ) )
goto V_214;
V_91 = F_171 ( V_215 + ( V_45 / 32 * 0x10 ) ) ;
if ( V_91 & ( 1 << ( V_45 % 32 ) ) ) {
V_54 -> V_216 ( V_204 ) ;
goto V_214;
}
F_172 ( V_141 [ V_45 ] , - 1 ) ;
V_214:
F_97 ( & V_212 -> V_213 ) ;
}
F_173 () ;
}
static void F_174 ( struct V_1 * V_2 , unsigned V_45 )
{
unsigned V_210 ;
if ( F_111 ( ! V_2 -> V_131 ) )
return;
V_210 = F_168 () ;
if ( V_45 == V_2 -> V_45 && F_114 ( V_210 , V_2 -> V_43 ) )
F_158 ( V_2 ) ;
}
static void F_175 ( struct V_1 * V_2 )
{
F_174 ( V_2 , ~ F_176 () -> V_217 ) ;
}
void F_177 ( int V_47 )
{
struct V_1 * V_2 = F_23 ( V_47 ) ;
if ( ! V_2 )
return;
F_174 ( V_2 , V_2 -> V_45 ) ;
}
static inline void F_175 ( struct V_1 * V_2 ) { }
static void F_178 ( struct V_84 * V_59 )
{
F_175 ( V_59 -> V_85 ) ;
F_179 ( V_59 ) ;
F_165 () ;
}
static bool F_180 ( struct V_1 * V_2 )
{
struct V_31 * V_67 ;
unsigned long V_68 ;
F_44 ( & V_69 , V_68 ) ;
F_51 (entry, cfg->irq_2_pin) {
unsigned int V_57 ;
int V_62 ;
V_62 = V_67 -> V_62 ;
V_57 = F_42 ( V_67 -> V_54 , 0x10 + V_62 * 2 ) ;
if ( V_57 & V_218 ) {
F_45 ( & V_69 , V_68 ) ;
return true ;
}
}
F_45 ( & V_69 , V_68 ) ;
return false ;
}
static inline bool F_181 ( struct V_84 * V_59 , struct V_1 * V_2 )
{
if ( F_103 ( F_182 ( V_59 ) ) ) {
F_60 ( V_2 ) ;
return true ;
}
return false ;
}
static inline void F_183 ( struct V_84 * V_59 ,
struct V_1 * V_2 , bool V_219 )
{
if ( F_103 ( V_219 ) ) {
if ( ! F_180 ( V_2 ) )
F_184 ( V_59 ) ;
F_63 ( V_2 ) ;
}
}
static inline bool F_181 ( struct V_84 * V_59 , struct V_1 * V_2 )
{
return false ;
}
static inline void F_183 ( struct V_84 * V_59 ,
struct V_1 * V_2 , bool V_219 )
{
}
static void F_185 ( struct V_84 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_85 ;
int V_20 , V_47 = V_59 -> V_47 ;
unsigned long V_220 ;
bool V_219 ;
F_175 ( V_2 ) ;
V_219 = F_181 ( V_59 , V_2 ) ;
V_20 = V_2 -> V_45 ;
V_220 = F_171 ( V_221 + ( ( V_20 & ~ 0x1f ) >> 1 ) ) ;
F_165 () ;
if ( ! ( V_220 & ( 1 << ( V_20 & 0x1f ) ) ) ) {
F_186 ( & V_222 ) ;
F_67 ( V_47 , V_2 ) ;
}
F_183 ( V_59 , V_2 , V_219 ) ;
}
static void F_187 ( struct V_84 * V_59 )
{
F_165 () ;
}
static void F_188 ( struct V_84 * V_59 )
{
F_165 () ;
F_67 ( V_59 -> V_47 , V_59 -> V_85 ) ;
}
static void F_189 ( struct V_84 * V_59 , struct V_223 * V_224 )
{
F_190 ( V_224 , L_36 , V_59 -> V_6 -> V_225 ) ;
}
static void F_2 ( struct V_5 * V_6 )
{
V_6 -> V_226 = F_189 ;
V_6 -> V_227 = F_187 ;
V_6 -> V_228 = F_188 ;
#ifdef F_191
V_6 -> V_229 = V_230 ;
#endif
}
static inline void F_192 ( void )
{
struct V_1 * V_2 ;
unsigned int V_47 ;
F_113 (irq) {
V_2 = F_23 ( V_47 ) ;
if ( F_92 ( V_47 ) && V_2 && ! V_2 -> V_45 ) {
if ( V_47 < V_35 -> V_36 )
V_35 -> V_231 ( V_47 ) ;
else
F_193 ( V_47 , & V_232 ) ;
}
}
}
static void F_194 ( struct V_84 * V_59 )
{
unsigned long V_220 ;
V_220 = F_171 ( V_233 ) ;
F_195 ( V_233 , V_220 | V_234 ) ;
}
static void F_196 ( struct V_84 * V_59 )
{
unsigned long V_220 ;
V_220 = F_171 ( V_233 ) ;
F_195 ( V_233 , V_220 & ~ V_234 ) ;
}
static void F_197 ( struct V_84 * V_59 )
{
F_165 () ;
}
static void F_198 ( int V_47 )
{
F_118 ( V_47 , V_148 ) ;
F_119 ( V_47 , & V_235 , V_151 ,
L_18 ) ;
}
static inline void T_1 F_199 ( void )
{
int V_54 , V_62 , V_20 ;
struct V_40 V_236 , V_86 ;
unsigned char V_237 , V_238 ;
V_62 = F_76 ( 8 , V_143 ) ;
if ( V_62 == - 1 ) {
F_200 ( 1 ) ;
return;
}
V_54 = F_78 ( 8 , V_143 ) ;
if ( V_54 == - 1 ) {
F_200 ( 1 ) ;
return;
}
V_236 = F_43 ( V_54 , V_62 ) ;
F_68 ( V_54 , V_62 ) ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_156 = 0 ;
V_86 . V_71 = 0 ;
V_86 . V_158 = F_201 () ;
V_86 . V_89 = V_171 ;
V_86 . V_106 = V_236 . V_106 ;
V_86 . V_87 = 0 ;
V_86 . V_45 = 0 ;
F_48 ( V_54 , V_62 , V_86 ) ;
V_237 = F_202 ( V_239 ) ;
V_238 = F_202 ( V_240 ) ;
F_203 ( ( V_238 & ~ V_241 ) | 0x6 ,
V_240 ) ;
F_203 ( V_237 | V_242 , V_239 ) ;
V_20 = 100 ;
while ( V_20 -- > 0 ) {
F_151 ( 10 ) ;
if ( ( F_202 ( V_243 ) & V_244 ) == V_244 )
V_20 -= 10 ;
}
F_203 ( V_237 , V_239 ) ;
F_203 ( V_238 , V_240 ) ;
F_68 ( V_54 , V_62 ) ;
F_48 ( V_54 , V_62 , V_236 ) ;
}
static int T_1 F_204 ( char * V_165 )
{
V_245 = 1 ;
return 0 ;
}
static inline void T_1 F_205 ( void )
{
struct V_1 * V_2 = F_23 ( 0 ) ;
int V_32 = F_18 ( 0 ) ;
int V_246 , V_247 , V_248 , V_249 ;
unsigned long V_68 ;
int V_250 = 0 ;
F_206 ( V_68 ) ;
V_35 -> V_71 ( 0 ) ;
F_106 ( 0 , V_2 , V_54 -> V_159 () ) ;
F_195 ( V_233 , V_234 | V_251 ) ;
V_35 -> V_252 ( 1 ) ;
V_247 = F_76 ( 0 , V_143 ) ;
V_246 = F_78 ( 0 , V_143 ) ;
V_249 = V_172 . V_62 ;
V_248 = V_172 . V_54 ;
F_10 ( V_253 , V_96 L_37
L_38 ,
V_2 -> V_45 , V_246 , V_247 , V_248 , V_249 ) ;
if ( V_247 == - 1 ) {
if ( V_154 )
F_11 ( L_39 ) ;
V_247 = V_249 ;
V_246 = V_248 ;
V_250 = 1 ;
} else if ( V_249 == - 1 ) {
V_249 = V_247 ;
V_248 = V_246 ;
}
if ( V_247 != - 1 ) {
if ( V_250 ) {
F_53 ( V_2 , V_32 , V_246 , V_247 ) ;
F_132 ( V_246 , V_247 , V_2 -> V_45 ) ;
} else {
int V_104 ;
V_104 = F_75 ( V_246 , V_247 , V_143 ) ;
if ( V_104 != - 1 && F_84 ( V_104 ) )
F_63 ( V_2 ) ;
}
if ( F_148 () ) {
if ( V_245 > 0 )
F_68 ( 0 , V_247 ) ;
goto V_254;
}
if ( V_154 )
F_11 ( L_40 ) ;
F_207 () ;
F_68 ( V_246 , V_247 ) ;
if ( ! V_250 )
F_10 ( V_253 , V_75 L_41
L_42 ) ;
F_10 ( V_253 , V_96 L_43
L_44 ) ;
F_10 ( V_253 , V_96
L_45 , V_248 , V_249 ) ;
F_54 ( V_2 , V_32 , V_246 , V_247 , V_248 , V_249 ) ;
F_132 ( V_248 , V_249 , V_2 -> V_45 ) ;
V_35 -> V_255 ( 0 ) ;
if ( F_148 () ) {
F_10 ( V_253 , V_96 L_46 ) ;
V_256 = 1 ;
goto V_254;
}
F_207 () ;
V_35 -> V_71 ( 0 ) ;
F_68 ( V_248 , V_249 ) ;
F_10 ( V_253 , V_96 L_47 ) ;
}
F_10 ( V_253 , V_96
L_48 ) ;
F_198 ( 0 ) ;
F_195 ( V_233 , V_257 | V_2 -> V_45 ) ;
V_35 -> V_255 ( 0 ) ;
if ( F_148 () ) {
F_10 ( V_253 , V_96 L_49 ) ;
goto V_254;
}
F_207 () ;
V_35 -> V_71 ( 0 ) ;
F_195 ( V_233 , V_234 | V_257 | V_2 -> V_45 ) ;
F_10 ( V_253 , V_96 L_50 ) ;
F_10 ( V_253 , V_96
L_51 ) ;
V_35 -> V_252 ( 0 ) ;
V_35 -> V_231 ( 0 ) ;
F_195 ( V_233 , V_251 ) ;
F_199 () ;
if ( F_148 () ) {
F_10 ( V_253 , V_96 L_49 ) ;
goto V_254;
}
F_207 () ;
F_10 ( V_253 , V_96 L_52 ) ;
if ( V_258 )
F_10 ( V_253 , V_96
L_53
L_54 ) ;
F_11 ( L_55
L_56 ) ;
V_254:
F_152 ( V_68 ) ;
}
void T_1 F_208 ( void )
{
V_37 = V_35 -> V_36 ? ~ V_259 : ~ 0UL ;
F_10 ( V_21 , L_57 ) ;
V_260 . V_261 . V_262 () ;
F_209 () ;
F_127 () ;
F_192 () ;
if ( V_35 -> V_36 )
F_205 () ;
}
static int T_1 F_210 ( void )
{
if ( V_61 == - 1 )
V_61 = 0 ;
return 0 ;
}
static void F_211 ( int V_7 )
{
unsigned long V_68 ;
union V_177 V_178 ;
F_44 ( & V_69 , V_68 ) ;
V_178 . V_183 = F_42 ( V_7 , 0 ) ;
if ( V_178 . V_184 . V_185 != F_3 ( V_7 ) ) {
V_178 . V_184 . V_185 = F_3 ( V_7 ) ;
F_47 ( V_7 , 0 , V_178 . V_183 ) ;
}
F_45 ( & V_69 , V_68 ) ;
}
static void F_212 ( void )
{
int V_7 ;
for ( V_7 = V_38 - 1 ; V_7 >= 0 ; V_7 -- )
F_211 ( V_7 ) ;
F_74 () ;
}
static int T_1 F_213 ( void )
{
F_214 ( & V_263 ) ;
return 0 ;
}
unsigned int F_215 ( unsigned int V_53 , int V_32 )
{
struct V_1 * V_2 ;
unsigned long V_68 ;
unsigned int V_209 = 0 ;
int V_47 ;
if ( V_53 < V_264 )
V_53 = V_264 ;
V_47 = F_31 ( V_53 , V_32 ) ;
if ( V_47 < 0 )
return 0 ;
V_2 = F_24 ( V_47 , V_32 ) ;
if ( ! V_2 ) {
F_33 ( V_47 , NULL ) ;
return 0 ;
}
F_44 ( & V_122 , V_68 ) ;
if ( ! F_98 ( V_47 , V_2 , V_54 -> V_159 () ) )
V_209 = V_47 ;
F_45 ( & V_122 , V_68 ) ;
if ( V_209 ) {
F_20 ( V_47 , V_2 ) ;
F_118 ( V_47 , V_265 ) ;
} else {
F_33 ( V_47 , V_2 ) ;
}
return V_209 ;
}
int F_216 ( void )
{
int V_32 = F_18 ( 0 ) ;
unsigned int V_266 ;
int V_47 ;
V_266 = V_264 ;
V_47 = F_215 ( V_266 , V_32 ) ;
if ( V_47 == 0 )
V_47 = - 1 ;
return V_47 ;
}
void F_217 ( unsigned int V_47 )
{
struct V_1 * V_2 = F_23 ( V_47 ) ;
unsigned long V_68 ;
F_117 ( V_47 , V_265 | V_267 ) ;
if ( F_1 ( V_2 ) )
F_218 ( V_47 ) ;
F_44 ( & V_122 , V_68 ) ;
F_107 ( V_47 , V_2 ) ;
F_45 ( & V_122 , V_68 ) ;
F_33 ( V_47 , V_2 ) ;
}
static int F_219 ( struct V_268 * V_269 , unsigned int V_47 ,
struct V_270 * V_271 , T_7 V_272 )
{
struct V_1 * V_2 ;
int V_99 ;
unsigned V_158 ;
if ( V_273 )
return - V_274 ;
V_2 = V_1 ( V_47 ) ;
V_99 = F_106 ( V_47 , V_2 , V_54 -> V_159 () ) ;
if ( V_99 )
return V_99 ;
V_158 = V_54 -> V_160 ( V_2 -> V_43 , V_54 -> V_159 () ) ;
if ( F_1 ( V_2 ) ) {
F_220 ( V_269 , V_47 , V_158 , V_271 , V_272 ) ;
return V_99 ;
}
if ( F_221 () )
V_271 -> V_275 = V_276 |
F_222 ( V_158 ) ;
else
V_271 -> V_275 = V_276 ;
V_271 -> V_277 =
V_278 |
( ( V_54 -> V_157 == 0 ) ?
V_279 :
V_280 ) |
( ( V_54 -> V_155 != V_281 ) ?
V_282 :
V_283 ) |
F_223 ( V_158 ) ;
V_271 -> V_59 =
V_284 |
V_285 |
( ( V_54 -> V_155 != V_281 ) ?
V_286 :
V_287 ) |
F_224 ( V_2 -> V_45 ) ;
return V_99 ;
}
static int
F_225 ( struct V_84 * V_59 , const struct V_123 * V_71 , bool V_208 )
{
struct V_1 * V_2 = V_59 -> V_85 ;
struct V_270 V_271 ;
unsigned int V_158 ;
if ( F_160 ( V_59 , V_71 , & V_158 ) )
return - 1 ;
F_226 ( V_59 -> V_288 , & V_271 ) ;
V_271 . V_59 &= ~ V_289 ;
V_271 . V_59 |= F_224 ( V_2 -> V_45 ) ;
V_271 . V_277 &= ~ V_290 ;
V_271 . V_277 |= F_223 ( V_158 ) ;
F_227 ( V_59 -> V_288 , & V_271 ) ;
return 0 ;
}
static int F_228 ( struct V_268 * V_291 , struct V_288 * V_292 , int V_47 )
{
struct V_5 * V_6 = & V_293 ;
struct V_270 V_271 ;
int V_209 ;
V_209 = F_219 ( V_291 , V_47 , & V_271 , - 1 ) ;
if ( V_209 < 0 )
return V_209 ;
F_229 ( V_47 , V_292 ) ;
F_230 ( V_47 , & V_271 ) ;
if ( F_1 ( F_23 ( V_47 ) ) ) {
F_117 ( V_47 , V_149 ) ;
F_2 ( V_6 ) ;
}
F_119 ( V_47 , V_6 , V_151 , L_18 ) ;
F_231 ( V_97 , & V_291 -> V_291 , L_58 , V_47 ) ;
return 0 ;
}
int F_232 ( struct V_268 * V_291 , int V_294 , int type )
{
int V_32 , V_209 , V_295 , V_58 = 0 ;
unsigned int V_47 , V_266 ;
struct V_288 * V_292 ;
if ( type == V_296 && V_294 > 1 )
return 1 ;
V_32 = F_233 ( & V_291 -> V_291 ) ;
V_266 = V_264 ;
V_295 = 0 ;
F_234 (msidesc, &dev->msi_list, list) {
V_47 = F_215 ( V_266 , V_32 ) ;
if ( V_47 == 0 )
return - 1 ;
V_266 = V_47 + 1 ;
if ( ! V_154 )
goto V_297;
if ( ! V_295 ) {
V_58 = F_235 ( V_291 , V_47 , V_294 ) ;
if ( V_58 < 0 ) {
V_209 = V_58 ;
goto error;
}
} else {
V_209 = F_236 ( V_291 , V_47 , V_58 ,
V_295 ) ;
if ( V_209 < 0 )
goto error;
}
V_297:
V_209 = F_228 ( V_291 , V_292 , V_47 ) ;
if ( V_209 < 0 )
goto error;
V_295 ++ ;
}
return 0 ;
error:
F_217 ( V_47 ) ;
return V_209 ;
}
void F_237 ( unsigned int V_47 )
{
F_217 ( V_47 ) ;
}
static int
F_238 ( struct V_84 * V_59 , const struct V_123 * V_71 ,
bool V_208 )
{
struct V_1 * V_2 = V_59 -> V_85 ;
unsigned int V_158 , V_47 = V_59 -> V_47 ;
struct V_270 V_271 ;
if ( F_160 ( V_59 , V_71 , & V_158 ) )
return - 1 ;
F_239 ( V_47 , & V_271 ) ;
V_271 . V_59 &= ~ V_289 ;
V_271 . V_59 |= F_224 ( V_2 -> V_45 ) ;
V_271 . V_277 &= ~ V_290 ;
V_271 . V_277 |= F_223 ( V_158 ) ;
V_271 . V_275 = V_276 | F_222 ( V_158 ) ;
F_240 ( V_47 , & V_271 ) ;
return 0 ;
}
int F_241 ( unsigned int V_47 )
{
int V_209 ;
struct V_270 V_271 ;
V_209 = F_219 ( NULL , V_47 , & V_271 , - 1 ) ;
if ( V_209 < 0 )
return V_209 ;
F_240 ( V_47 , & V_271 ) ;
F_119 ( V_47 , & V_298 , V_151 ,
L_18 ) ;
return 0 ;
}
static int F_242 ( struct V_84 * V_59 ,
const struct V_123 * V_71 , bool V_208 )
{
struct V_1 * V_2 = V_59 -> V_85 ;
struct V_270 V_271 ;
unsigned int V_158 ;
if ( F_160 ( V_59 , V_71 , & V_158 ) )
return - 1 ;
F_243 ( V_59 -> V_299 , & V_271 ) ;
V_271 . V_59 &= ~ V_289 ;
V_271 . V_59 |= F_224 ( V_2 -> V_45 ) ;
V_271 . V_277 &= ~ V_290 ;
V_271 . V_277 |= F_223 ( V_158 ) ;
F_244 ( V_59 -> V_299 , & V_271 ) ;
return 0 ;
}
int F_245 ( unsigned int V_47 , unsigned int V_300 )
{
struct V_5 * V_6 = & V_301 ;
struct V_270 V_271 ;
int V_209 ;
if ( V_154 ) {
if ( ! F_246 ( V_47 , V_300 ) )
return - 1 ;
}
V_209 = F_219 ( NULL , V_47 , & V_271 , V_300 ) ;
if ( V_209 < 0 )
return V_209 ;
F_244 ( F_247 ( V_47 ) , & V_271 ) ;
F_117 ( V_47 , V_149 ) ;
if ( F_1 ( F_23 ( V_47 ) ) )
F_2 ( V_6 ) ;
F_119 ( V_47 , V_6 , V_151 , L_18 ) ;
return 0 ;
}
static void F_248 ( unsigned int V_47 , unsigned int V_158 , T_7 V_45 )
{
struct V_302 V_271 ;
F_249 ( V_47 , & V_271 ) ;
V_271 . V_277 &= ~ ( V_303 | V_304 ) ;
V_271 . V_275 &= ~ ( V_305 ) ;
V_271 . V_277 |= F_250 ( V_45 ) | F_251 ( V_158 ) ;
V_271 . V_275 |= F_252 ( V_158 ) ;
F_253 ( V_47 , & V_271 ) ;
}
static int
F_254 ( struct V_84 * V_59 , const struct V_123 * V_71 , bool V_208 )
{
struct V_1 * V_2 = V_59 -> V_85 ;
unsigned int V_158 ;
if ( F_160 ( V_59 , V_71 , & V_158 ) )
return - 1 ;
F_248 ( V_59 -> V_47 , V_158 , V_2 -> V_45 ) ;
return 0 ;
}
int F_255 ( unsigned int V_47 , struct V_268 * V_291 )
{
struct V_1 * V_2 ;
int V_99 ;
if ( V_273 )
return - V_274 ;
V_2 = V_1 ( V_47 ) ;
V_99 = F_106 ( V_47 , V_2 , V_54 -> V_159 () ) ;
if ( ! V_99 ) {
struct V_302 V_271 ;
unsigned V_158 ;
V_158 = V_54 -> V_160 ( V_2 -> V_43 ,
V_54 -> V_159 () ) ;
V_271 . V_275 = F_252 ( V_158 ) ;
V_271 . V_277 =
V_306 |
F_251 ( V_158 ) |
F_250 ( V_2 -> V_45 ) |
( ( V_54 -> V_157 == 0 ) ?
V_307 :
V_308 ) |
V_309 |
( ( V_54 -> V_155 != V_281 ) ?
V_310 :
V_311 ) |
V_312 ;
F_253 ( V_47 , & V_271 ) ;
F_119 ( V_47 , & V_313 ,
V_151 , L_18 ) ;
F_231 ( V_97 , & V_291 -> V_291 , L_59 , V_47 ) ;
}
return V_99 ;
}
static int
F_126 ( unsigned int V_47 , int V_32 , struct V_118 * V_153 )
{
struct V_1 * V_2 = F_28 ( V_47 , V_32 ) ;
int V_209 ;
if ( ! V_2 )
return - V_314 ;
V_209 = F_50 ( V_2 , V_32 , V_153 -> V_161 , V_153 -> V_162 ) ;
if ( ! V_209 )
F_122 ( V_47 , V_2 , V_153 ) ;
return V_209 ;
}
int F_131 ( unsigned int V_47 , int V_32 ,
struct V_118 * V_153 )
{
unsigned int V_7 = V_153 -> V_161 , V_62 = V_153 -> V_162 ;
int V_209 ;
if ( F_77 ( V_62 , V_8 [ V_7 ] . V_315 ) ) {
F_256 ( L_60 ,
F_3 ( V_7 ) , V_62 ) ;
return 0 ;
}
V_209 = F_126 ( V_47 , V_32 , V_153 ) ;
if ( ! V_209 )
F_257 ( V_62 , V_8 [ V_7 ] . V_315 ) ;
return V_209 ;
}
static int T_1 F_258 ( int V_161 )
{
union V_316 V_317 ;
unsigned long V_68 ;
F_44 ( & V_69 , V_68 ) ;
V_317 . V_183 = F_42 ( V_161 , 1 ) ;
F_45 ( & V_69 , V_68 ) ;
return V_317 . V_184 . V_318 + 1 ;
}
static void T_1 F_259 ( void )
{
int V_319 ;
V_319 = V_116 + V_115 ;
if ( V_319 > V_264 )
V_264 = V_319 ;
F_52 ( V_97 L_61 , V_264 ) ;
}
int F_260 ( void )
{
return V_264 ;
}
int T_1 F_261 ( void )
{
int V_319 ;
if ( V_320 > ( V_142 * V_321 ) )
V_320 = V_142 * V_321 ;
V_319 = V_264 + 8 * V_321 ;
#if F_262 ( V_322 ) || F_262 ( V_323 )
V_319 += V_264 * 16 ;
#endif
if ( V_319 < V_320 )
V_320 = V_319 ;
return V_115 ;
}
int F_263 ( struct V_324 * V_291 , int V_47 ,
struct V_118 * V_119 )
{
int V_32 ;
if ( ! F_92 ( V_47 ) ) {
F_10 ( V_253 , V_75 L_62 ,
V_119 -> V_161 ) ;
return - V_314 ;
}
V_32 = V_291 ? F_233 ( V_291 ) : F_18 ( 0 ) ;
return F_131 ( V_47 , V_32 , V_119 ) ;
}
static int T_1 F_264 ( int V_161 , int V_325 )
{
union V_177 V_178 ;
static T_6 V_326 = V_327 ;
T_6 V_187 ;
unsigned long V_68 ;
int V_20 = 0 ;
if ( F_265 ( V_326 ) )
V_54 -> V_181 ( & V_182 , & V_326 ) ;
F_44 ( & V_69 , V_68 ) ;
V_178 . V_183 = F_42 ( V_161 , 0 ) ;
F_45 ( & V_69 , V_68 ) ;
if ( V_325 >= F_141 () ) {
F_52 ( V_107 L_63
L_64 , V_161 , V_325 , V_178 . V_184 . V_185 ) ;
V_325 = V_178 . V_184 . V_185 ;
}
if ( V_54 -> V_186 ( & V_326 , V_325 ) ) {
for ( V_20 = 0 ; V_20 < F_141 () ; V_20 ++ ) {
if ( ! V_54 -> V_186 ( & V_326 , V_20 ) )
break;
}
if ( V_20 == F_141 () )
F_11 ( L_65 ) ;
F_52 ( V_107 L_66
L_67 , V_161 , V_325 , V_20 ) ;
V_325 = V_20 ;
}
V_54 -> V_188 ( V_325 , & V_187 ) ;
F_144 ( V_326 , V_326 , V_187 ) ;
if ( V_178 . V_184 . V_185 != V_325 ) {
V_178 . V_184 . V_185 = V_325 ;
F_44 ( & V_69 , V_68 ) ;
F_47 ( V_161 , 0 , V_178 . V_183 ) ;
V_178 . V_183 = F_42 ( V_161 , 0 ) ;
F_45 ( & V_69 , V_68 ) ;
if ( V_178 . V_184 . V_185 != V_325 ) {
F_52 ( L_68 , V_161 ) ;
return - 1 ;
}
}
F_10 ( V_21 , V_96
L_69 , V_161 , V_325 ) ;
return V_325 ;
}
static T_7 T_1 F_266 ( T_7 V_300 )
{
if ( ( V_190 . V_191 == V_192 ) &&
! F_146 ( V_193 [ V_194 ] ) )
return F_264 ( V_38 , V_300 ) ;
else
return V_300 ;
}
static T_7 T_1 F_266 ( T_7 V_300 )
{
int V_20 ;
F_267 ( V_328 , 256 ) ;
F_268 ( V_328 , 256 ) ;
for ( V_20 = 0 ; V_20 < V_38 ; V_20 ++ ) {
F_269 ( F_3 ( V_20 ) , V_328 ) ;
}
if ( ! F_77 ( V_300 , V_328 ) )
return V_300 ;
return F_270 ( V_328 , 256 ) ;
}
static int T_1 F_271 ( int V_161 )
{
union V_316 V_317 ;
unsigned long V_68 ;
F_44 ( & V_69 , V_68 ) ;
V_317 . V_183 = F_42 ( V_161 , 1 ) ;
F_45 ( & V_69 , V_68 ) ;
return V_317 . V_184 . V_329 ;
}
int F_272 ( T_3 V_113 , int * V_87 , int * V_106 )
{
int V_161 , V_62 , V_104 ;
if ( V_16 )
return - 1 ;
V_161 = F_129 ( V_113 ) ;
if ( V_161 < 0 )
return - 1 ;
V_62 = F_130 ( V_161 , V_113 ) ;
if ( V_62 < 0 )
return - 1 ;
V_104 = F_75 ( V_161 , V_62 , V_143 ) ;
if ( V_104 < 0 )
return - 1 ;
* V_87 = F_84 ( V_104 ) ;
* V_106 = F_81 ( V_104 ) ;
return 0 ;
}
void T_1 F_273 ( void )
{
int V_62 , V_161 , V_47 , V_330 ;
const struct V_123 * V_71 ;
struct V_84 * V_331 ;
if ( V_16 == 1 )
return;
for ( V_161 = 0 ; V_161 < V_38 ; V_161 ++ )
for ( V_62 = 0 ; V_62 < V_8 [ V_161 ] . V_41 ; V_62 ++ ) {
V_330 = F_75 ( V_161 , V_62 , V_143 ) ;
if ( V_330 == - 1 )
continue;
V_47 = F_89 ( V_330 , V_161 , V_62 ) ;
if ( ( V_161 > 0 ) && ( V_47 > 16 ) )
continue;
V_331 = F_274 ( V_47 ) ;
if ( ! F_275 ( V_331 ) || F_276 ( V_331 ) )
V_71 = V_331 -> V_207 ;
else
V_71 = V_54 -> V_159 () ;
if ( V_154 )
V_230 ( V_331 , V_71 , false ) ;
else
F_162 ( V_331 , V_71 , false ) ;
}
}
static struct V_332 * T_1 F_277 ( int V_38 )
{
unsigned long V_333 ;
struct V_332 * V_51 ;
char * V_334 ;
int V_20 ;
if ( V_38 <= 0 )
return NULL ;
V_333 = V_335 + sizeof( struct V_332 ) ;
V_333 *= V_38 ;
V_334 = F_278 ( V_333 ) ;
V_51 = ( void * ) V_334 ;
V_334 += sizeof( struct V_332 ) * V_38 ;
for ( V_20 = 0 ; V_20 < V_38 ; V_20 ++ ) {
V_51 [ V_20 ] . V_225 = V_334 ;
V_51 [ V_20 ] . V_68 = V_336 | V_337 ;
snprintf ( V_334 , V_335 , L_70 , V_20 ) ;
V_334 += V_335 ;
}
V_338 = V_51 ;
return V_51 ;
}
void T_1 F_279 ( void )
{
unsigned long V_339 , V_104 = V_340 ;
struct V_332 * V_341 ;
int V_20 ;
V_341 = F_277 ( V_38 ) ;
for ( V_20 = 0 ; V_20 < V_38 ; V_20 ++ ) {
if ( V_342 ) {
V_339 = F_4 ( V_20 ) ;
#ifdef F_90
if ( ! V_339 ) {
F_52 ( V_75
L_71
L_72
L_73 ) ;
V_342 = 0 ;
V_16 = 1 ;
goto V_343;
}
#endif
} else {
#ifdef F_90
V_343:
#endif
V_339 = ( unsigned long ) F_280 ( V_344 ) ;
V_339 = F_281 ( V_339 ) ;
}
F_282 ( V_104 , V_339 ) ;
F_10 ( V_21 , L_74 ,
F_283 ( V_104 ) + ( V_339 & ~ V_345 ) ,
V_339 ) ;
V_104 ++ ;
V_341 -> V_346 = V_339 ;
V_341 -> V_347 = V_339 + V_348 - 1 ;
V_341 ++ ;
}
F_259 () ;
}
void T_1 F_284 ( void )
{
int V_20 ;
struct V_332 * V_349 = V_338 ;
if ( ! V_349 ) {
if ( V_38 > 0 )
F_52 ( V_75
L_75 ) ;
return;
}
for ( V_20 = 0 ; V_20 < V_38 ; V_20 ++ ) {
F_285 ( & V_350 , V_349 ) ;
V_349 ++ ;
}
}
int F_129 ( T_3 V_113 )
{
int V_20 = 0 ;
if ( V_38 == 0 )
return - 1 ;
for ( V_20 = 0 ; V_20 < V_38 ; V_20 ++ ) {
struct V_12 * V_112 = F_5 ( V_20 ) ;
if ( ( V_113 >= V_112 -> V_114 )
&& ( V_113 <= V_112 -> V_351 ) )
return V_20 ;
}
F_52 ( V_75 L_76 , V_113 ) ;
return - 1 ;
}
int F_130 ( int V_161 , T_3 V_113 )
{
struct V_12 * V_112 ;
if ( F_286 ( V_161 == - 1 ) )
return - 1 ;
V_112 = F_5 ( V_161 ) ;
if ( F_286 ( V_113 > V_112 -> V_351 ) )
return - 1 ;
return V_113 - V_112 -> V_114 ;
}
static T_1 int F_287 ( unsigned long V_352 )
{
if ( V_38 >= V_353 ) {
F_123 ( L_77 ,
V_353 , V_38 ) ;
return 1 ;
}
if ( ! V_352 ) {
F_123 ( L_78 ) ;
return 1 ;
}
return 0 ;
}
static T_1 int F_288 ( int V_104 )
{
union V_177 V_178 ;
union V_316 V_317 ;
union V_354 V_355 ;
V_178 . V_183 = F_42 ( V_104 , 0 ) ;
V_317 . V_183 = F_42 ( V_104 , 1 ) ;
V_355 . V_183 = F_42 ( V_104 , 2 ) ;
if ( V_178 . V_183 == - 1 && V_317 . V_183 == - 1 && V_355 . V_183 == - 1 ) {
F_123 ( L_79 ,
F_4 ( V_104 ) ) ;
return 1 ;
}
return 0 ;
}
void T_1 F_289 ( int V_300 , T_3 V_352 , T_3 V_114 )
{
int V_104 = 0 ;
int V_318 ;
struct V_12 * V_112 ;
if ( F_287 ( V_352 ) )
return;
V_104 = V_38 ;
V_8 [ V_104 ] . V_9 . type = V_356 ;
V_8 [ V_104 ] . V_9 . V_68 = V_357 ;
V_8 [ V_104 ] . V_9 . V_11 = V_352 ;
F_282 ( V_340 + V_104 , V_352 ) ;
if ( F_288 ( V_104 ) ) {
F_290 ( V_340 + V_104 ) ;
return;
}
V_8 [ V_104 ] . V_9 . V_10 = F_266 ( V_300 ) ;
V_8 [ V_104 ] . V_9 . V_358 = F_271 ( V_104 ) ;
V_318 = F_258 ( V_104 ) ;
V_112 = F_5 ( V_104 ) ;
V_112 -> V_114 = V_114 ;
V_112 -> V_351 = V_114 + V_318 - 1 ;
V_8 [ V_104 ] . V_41 = V_318 ;
if ( V_112 -> V_351 >= V_116 )
V_116 = V_112 -> V_351 + 1 ;
F_291 ( L_80 ,
V_104 , F_3 ( V_104 ) ,
F_66 ( V_104 ) , F_4 ( V_104 ) ,
V_112 -> V_114 , V_112 -> V_351 ) ;
V_38 ++ ;
}
void T_1 F_292 ( void )
{
struct V_118 V_153 = { 0 , 0 , 0 , 0 } ;
F_52 ( V_96 L_81 ) ;
#ifndef F_191
F_293 ( V_194 ,
& V_182 ) ;
#endif
F_294 () ;
F_126 ( 0 , 0 , & V_153 ) ;
F_119 ( 0 , & V_144 , V_151 ,
L_18 ) ;
}
