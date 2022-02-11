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
if ( ! V_31 -> V_32 )
V_33 = ~ 0UL ;
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
V_2 [ V_14 ] . V_35 =
F_13 ( sizeof( struct V_36 ) *
V_2 [ V_14 ] . V_37 , V_27 ) ;
if ( ! V_2 [ V_14 ] . V_35 )
F_14 ( L_4 , V_14 ) ;
}
V_29 = V_38 ;
V_30 = F_15 ( V_38 ) ;
V_26 = F_16 ( 0 ) ;
F_17 ( 0 , V_31 -> V_32 ) ;
for ( V_14 = 0 ; V_14 < V_30 ; V_14 ++ ) {
F_18 ( V_14 , & V_29 [ V_14 ] ) ;
F_19 ( & V_29 [ V_14 ] . V_39 , V_27 , V_26 ) ;
F_19 ( & V_29 [ V_14 ] . V_40 , V_27 , V_26 ) ;
if ( V_14 < V_31 -> V_32 ) {
V_29 [ V_14 ] . V_41 = V_42 + V_14 ;
F_20 ( 0 , V_29 [ V_14 ] . V_39 ) ;
}
}
return 0 ;
}
static struct V_28 * V_28 ( unsigned int V_43 )
{
return F_21 ( V_43 ) ;
}
static struct V_28 * F_22 ( unsigned int V_43 , int V_26 )
{
struct V_28 * V_29 ;
V_29 = F_11 ( sizeof( * V_29 ) , V_27 , V_26 ) ;
if ( ! V_29 )
return NULL ;
if ( ! F_19 ( & V_29 -> V_39 , V_27 , V_26 ) )
goto V_44;
if ( ! F_19 ( & V_29 -> V_40 , V_27 , V_26 ) )
goto V_45;
return V_29 ;
V_45:
F_23 ( V_29 -> V_39 ) ;
V_44:
F_24 ( V_29 ) ;
return NULL ;
}
static void F_25 ( unsigned int V_46 , struct V_28 * V_29 )
{
if ( ! V_29 )
return;
F_18 ( V_46 , NULL ) ;
F_23 ( V_29 -> V_39 ) ;
F_23 ( V_29 -> V_40 ) ;
F_24 ( V_29 ) ;
}
static struct V_28 * F_26 ( unsigned int V_46 , int V_26 )
{
int V_47 = F_27 ( V_46 , V_26 ) ;
struct V_28 * V_29 ;
if ( V_47 < 0 ) {
if ( V_47 != - V_48 )
return NULL ;
V_29 = F_21 ( V_46 ) ;
if ( V_29 )
return V_29 ;
}
V_29 = F_22 ( V_46 , V_26 ) ;
if ( V_29 )
F_18 ( V_46 , V_29 ) ;
else
F_28 ( V_46 ) ;
return V_29 ;
}
static int F_29 ( unsigned int V_49 , int V_26 )
{
return F_30 ( V_49 , V_26 ) ;
}
static void F_31 ( unsigned int V_46 , struct V_28 * V_29 )
{
F_25 ( V_46 , V_29 ) ;
F_28 ( V_46 ) ;
}
static inline void F_32 ( unsigned int V_50 , unsigned int V_41 )
{
struct V_51 T_2 * V_51 = F_33 ( V_50 ) ;
F_34 ( V_41 , & V_51 -> V_52 ) ;
}
static inline unsigned int F_35 ( unsigned int V_50 , unsigned int V_53 )
{
struct V_51 T_2 * V_51 = F_33 ( V_50 ) ;
F_34 ( V_53 , & V_51 -> V_54 ) ;
return F_36 ( & V_51 -> V_55 ) ;
}
static inline void F_37 ( unsigned int V_50 , unsigned int V_53 , unsigned int V_56 )
{
struct V_51 T_2 * V_51 = F_33 ( V_50 ) ;
F_34 ( V_53 , & V_51 -> V_54 ) ;
F_34 ( V_56 , & V_51 -> V_55 ) ;
}
static inline void F_38 ( unsigned int V_50 , unsigned int V_53 , unsigned int V_56 )
{
struct V_51 T_2 * V_51 = F_33 ( V_50 ) ;
if ( V_57 )
F_34 ( V_53 , & V_51 -> V_54 ) ;
F_34 ( V_56 , & V_51 -> V_55 ) ;
}
static bool F_39 ( struct V_28 * V_29 )
{
struct V_25 * V_58 ;
unsigned long V_59 ;
F_40 ( & V_60 , V_59 ) ;
F_41 (entry, cfg->irq_2_pin) {
unsigned int V_53 ;
int V_61 ;
V_61 = V_58 -> V_61 ;
V_53 = F_35 ( V_58 -> V_50 , 0x10 + V_61 * 2 ) ;
if ( V_53 & V_62 ) {
F_42 ( & V_60 , V_59 ) ;
return true ;
}
}
F_42 ( & V_60 , V_59 ) ;
return false ;
}
static struct V_36 F_43 ( int V_50 , int V_61 )
{
union V_63 V_64 ;
V_64 . V_65 = F_35 ( V_50 , 0x10 + 2 * V_61 ) ;
V_64 . V_66 = F_35 ( V_50 , 0x11 + 2 * V_61 ) ;
return V_64 . V_58 ;
}
static struct V_36 F_44 ( int V_50 , int V_61 )
{
union V_63 V_64 ;
unsigned long V_59 ;
F_40 ( & V_60 , V_59 ) ;
V_64 . V_58 = F_43 ( V_50 , V_61 ) ;
F_42 ( & V_60 , V_59 ) ;
return V_64 . V_58 ;
}
static void
F_45 ( int V_50 , int V_61 , struct V_36 V_67 )
{
union V_63 V_64 = { { 0 , 0 } } ;
V_64 . V_58 = V_67 ;
F_37 ( V_50 , 0x11 + 2 * V_61 , V_64 . V_66 ) ;
F_37 ( V_50 , 0x10 + 2 * V_61 , V_64 . V_65 ) ;
}
static void F_46 ( int V_50 , int V_61 , struct V_36 V_67 )
{
unsigned long V_59 ;
F_40 ( & V_60 , V_59 ) ;
F_45 ( V_50 , V_61 , V_67 ) ;
F_42 ( & V_60 , V_59 ) ;
}
static void F_47 ( int V_50 , int V_61 )
{
unsigned long V_59 ;
union V_63 V_64 = { . V_58 . V_68 = 1 } ;
F_40 ( & V_60 , V_59 ) ;
F_37 ( V_50 , 0x10 + 2 * V_61 , V_64 . V_65 ) ;
F_37 ( V_50 , 0x11 + 2 * V_61 , V_64 . V_66 ) ;
F_42 ( & V_60 , V_59 ) ;
}
static int
F_48 ( struct V_28 * V_29 , int V_26 , int V_50 , int V_61 )
{
struct V_25 * * V_69 , * V_58 ;
V_69 = & V_29 -> V_70 ;
F_41 (entry, cfg->irq_2_pin) {
if ( V_58 -> V_50 == V_50 && V_58 -> V_61 == V_61 )
return 0 ;
V_69 = & V_58 -> V_71 ;
}
V_58 = F_10 ( V_26 ) ;
if ( ! V_58 ) {
F_49 ( V_72 L_5 ,
V_26 , V_50 , V_61 ) ;
return - V_73 ;
}
V_58 -> V_50 = V_50 ;
V_58 -> V_61 = V_61 ;
* V_69 = V_58 ;
return 0 ;
}
static void F_50 ( struct V_28 * V_29 , int V_26 , int V_50 , int V_61 )
{
if ( F_48 ( V_29 , V_26 , V_50 , V_61 ) )
F_9 ( L_6 ) ;
}
static void T_1 F_51 ( struct V_28 * V_29 , int V_26 ,
int V_74 , int V_75 ,
int V_76 , int V_77 )
{
struct V_25 * V_58 ;
F_41 (entry, cfg->irq_2_pin) {
if ( V_58 -> V_50 == V_74 && V_58 -> V_61 == V_75 ) {
V_58 -> V_50 = V_76 ;
V_58 -> V_61 = V_77 ;
return;
}
}
F_50 ( V_29 , V_26 , V_76 , V_77 ) ;
}
static void F_52 ( struct V_25 * V_58 ,
int V_78 , int V_79 ,
void (* F_53)( struct V_25 * V_58 ) )
{
unsigned int V_53 , V_61 ;
V_61 = V_58 -> V_61 ;
V_53 = F_35 ( V_58 -> V_50 , 0x10 + V_61 * 2 ) ;
V_53 &= V_78 ;
V_53 |= V_79 ;
F_38 ( V_58 -> V_50 , 0x10 + V_61 * 2 , V_53 ) ;
if ( F_53 )
F_53 ( V_58 ) ;
}
static void F_54 ( struct V_28 * V_29 ,
int V_78 , int V_79 ,
void (* F_53)( struct V_25 * V_58 ) )
{
struct V_25 * V_58 ;
F_41 (entry, cfg->irq_2_pin)
F_52 ( V_58 , V_78 , V_79 , F_53 ) ;
}
static void F_55 ( struct V_25 * V_58 )
{
struct V_51 T_2 * V_51 ;
V_51 = F_33 ( V_58 -> V_50 ) ;
F_36 ( & V_51 -> V_55 ) ;
}
static void F_56 ( struct V_28 * V_29 )
{
unsigned long V_59 ;
F_40 ( & V_60 , V_59 ) ;
F_54 ( V_29 , ~ 0 , V_80 , & F_55 ) ;
F_42 ( & V_60 , V_59 ) ;
}
static void F_57 ( struct V_81 * V_55 )
{
F_56 ( V_55 -> V_82 ) ;
}
static void F_58 ( struct V_28 * V_29 )
{
F_54 ( V_29 , ~ V_80 , 0 , NULL ) ;
}
static void F_59 ( struct V_28 * V_29 )
{
unsigned long V_59 ;
F_40 ( & V_60 , V_59 ) ;
F_58 ( V_29 ) ;
F_42 ( & V_60 , V_59 ) ;
}
static void F_60 ( struct V_81 * V_55 )
{
F_59 ( V_55 -> V_82 ) ;
}
static void F_61 ( int V_50 , int V_61 , int V_41 , struct V_28 * V_29 )
{
if ( F_62 ( V_50 ) >= 0x20 ) {
if ( V_29 && F_63 ( V_29 ) )
F_32 ( V_50 , V_61 ) ;
else
F_32 ( V_50 , V_41 ) ;
} else {
struct V_36 V_58 , V_83 ;
V_58 = V_83 = F_43 ( V_50 , V_61 ) ;
V_83 . V_68 = 1 ;
V_83 . V_84 = V_85 ;
F_45 ( V_50 , V_61 , V_83 ) ;
F_45 ( V_50 , V_61 , V_58 ) ;
}
}
static void F_64 ( unsigned int V_43 , struct V_28 * V_29 )
{
struct V_25 * V_58 ;
unsigned long V_59 ;
F_40 ( & V_60 , V_59 ) ;
F_41 (entry, cfg->irq_2_pin)
F_61 ( V_58 -> V_50 , V_58 -> V_61 , V_29 -> V_41 , V_29 ) ;
F_42 ( & V_60 , V_59 ) ;
}
static void F_65 ( unsigned int V_50 , unsigned int V_61 )
{
struct V_36 V_58 ;
V_58 = F_44 ( V_50 , V_61 ) ;
if ( V_58 . V_86 == V_87 )
return;
if ( ! V_58 . V_68 ) {
V_58 . V_68 = 1 ;
F_46 ( V_50 , V_61 , V_58 ) ;
V_58 = F_44 ( V_50 , V_61 ) ;
}
if ( V_58 . V_88 ) {
unsigned long V_59 ;
if ( ! V_58 . V_84 ) {
V_58 . V_84 = V_89 ;
F_46 ( V_50 , V_61 , V_58 ) ;
}
F_40 ( & V_60 , V_59 ) ;
F_61 ( V_50 , V_61 , V_58 . V_41 , NULL ) ;
F_42 ( & V_60 , V_59 ) ;
}
F_47 ( V_50 , V_61 ) ;
V_58 = F_44 ( V_50 , V_61 ) ;
if ( V_58 . V_88 )
F_49 ( V_72 L_7 ,
F_1 ( V_50 ) , V_61 ) ;
}
static void F_66 ( void )
{
int V_50 , V_61 ;
for ( V_50 = 0 ; V_50 < V_34 ; V_50 ++ )
for ( V_61 = 0 ; V_61 < V_2 [ V_50 ] . V_37 ; V_61 ++ )
F_65 ( V_50 , V_61 ) ;
}
static int T_1 F_67 ( char * V_11 )
{
int V_14 , V_90 ;
int V_91 [ V_92 + 1 ] ;
F_68 ( V_11 , F_15 ( V_91 ) , V_91 ) ;
F_8 ( V_15 , V_93
L_8 ) ;
V_90 = V_92 ;
if ( V_91 [ 0 ] < V_92 )
V_90 = V_91 [ 0 ] ;
for ( V_14 = 0 ; V_14 < V_90 ; V_14 ++ ) {
F_8 ( V_15 , V_94
L_9 , V_14 , V_91 [ V_14 + 1 ] ) ;
V_95 [ V_92 - V_14 - 1 ] = V_91 [ V_14 + 1 ] ;
}
return 1 ;
}
int F_69 ( void )
{
int V_50 , V_61 ;
int V_96 = 0 ;
for ( V_50 = 0 ; V_50 < V_34 ; V_50 ++ ) {
if ( ! V_2 [ V_50 ] . V_35 ) {
V_96 = - V_73 ;
continue;
}
for ( V_61 = 0 ; V_61 < V_2 [ V_50 ] . V_37 ; V_61 ++ )
V_2 [ V_50 ] . V_35 [ V_61 ] =
F_44 ( V_50 , V_61 ) ;
}
return V_96 ;
}
void F_70 ( void )
{
int V_50 , V_61 ;
for ( V_50 = 0 ; V_50 < V_34 ; V_50 ++ ) {
if ( ! V_2 [ V_50 ] . V_35 )
continue;
for ( V_61 = 0 ; V_61 < V_2 [ V_50 ] . V_37 ; V_61 ++ ) {
struct V_36 V_58 ;
V_58 = V_2 [ V_50 ] . V_35 [ V_61 ] ;
if ( ! V_58 . V_68 ) {
V_58 . V_68 = 1 ;
F_46 ( V_50 , V_61 , V_58 ) ;
}
}
}
}
int F_71 ( void )
{
int V_50 , V_61 ;
for ( V_50 = 0 ; V_50 < V_34 ; V_50 ++ ) {
if ( ! V_2 [ V_50 ] . V_35 )
continue;
for ( V_61 = 0 ; V_61 < V_2 [ V_50 ] . V_37 ; V_61 ++ )
F_46 ( V_50 , V_61 ,
V_2 [ V_50 ] . V_35 [ V_61 ] ) ;
}
return 0 ;
}
static int F_72 ( int V_1 , int V_61 , int type )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ )
if ( V_23 [ V_14 ] . V_16 == type &&
( V_23 [ V_14 ] . V_20 == F_1 ( V_1 ) ||
V_23 [ V_14 ] . V_20 == V_97 ) &&
V_23 [ V_14 ] . V_21 == V_61 )
return V_14 ;
return - 1 ;
}
static int T_1 F_73 ( int V_43 , int type )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ ) {
int V_98 = V_23 [ V_14 ] . V_18 ;
if ( F_74 ( V_98 , V_99 ) &&
( V_23 [ V_14 ] . V_16 == type ) &&
( V_23 [ V_14 ] . V_19 == V_43 ) )
return V_23 [ V_14 ] . V_21 ;
}
return - 1 ;
}
static int T_1 F_75 ( int V_43 , int type )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ ) {
int V_98 = V_23 [ V_14 ] . V_18 ;
if ( F_74 ( V_98 , V_99 ) &&
( V_23 [ V_14 ] . V_16 == type ) &&
( V_23 [ V_14 ] . V_19 == V_43 ) )
break;
}
if ( V_14 < V_22 ) {
int V_1 ;
for ( V_1 = 0 ; V_1 < V_34 ; V_1 ++ )
if ( F_1 ( V_1 ) == V_23 [ V_14 ] . V_20 )
return V_1 ;
}
return - 1 ;
}
static int F_76 ( unsigned int V_43 )
{
if ( V_43 < V_31 -> V_32 ) {
unsigned int V_100 = 0x4d0 + ( V_43 >> 3 ) ;
return ( F_77 ( V_100 ) >> ( V_43 & 7 ) ) & 1 ;
}
F_8 ( V_15 , V_93
L_10 , V_43 ) ;
return 0 ;
}
static int F_78 ( int V_101 )
{
int V_102 = V_23 [ V_101 ] . V_18 ;
int V_103 ;
switch ( V_23 [ V_101 ] . V_17 & 3 )
{
case 0 :
if ( F_74 ( V_102 , V_99 ) )
V_103 = F_79 ( V_101 ) ;
else
V_103 = F_80 ( V_101 ) ;
break;
case 1 :
{
V_103 = 0 ;
break;
}
case 2 :
{
F_49 ( V_104 L_11 ) ;
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
F_49 ( V_104 L_11 ) ;
V_103 = 1 ;
break;
}
}
return V_103 ;
}
static int F_81 ( int V_101 )
{
int V_102 = V_23 [ V_101 ] . V_18 ;
int V_84 ;
switch ( ( V_23 [ V_101 ] . V_17 >> 2 ) & 3 )
{
case 0 :
if ( F_74 ( V_102 , V_99 ) )
V_84 = F_82 ( V_101 ) ;
else
V_84 = F_83 ( V_101 ) ;
#if F_84 ( V_105 ) || F_84 ( V_106 )
switch ( V_107 [ V_102 ] ) {
case V_108 :
{
break;
}
case V_109 :
{
V_84 = F_85 ( V_101 ) ;
break;
}
case V_110 :
{
break;
}
case V_111 :
{
V_84 = F_86 ( V_101 ) ;
break;
}
default:
{
F_49 ( V_104 L_11 ) ;
V_84 = 1 ;
break;
}
}
#endif
break;
case 1 :
{
V_84 = 0 ;
break;
}
case 2 :
{
F_49 ( V_104 L_11 ) ;
V_84 = 1 ;
break;
}
case 3 :
{
V_84 = 1 ;
break;
}
default:
{
F_49 ( V_104 L_11 ) ;
V_84 = 0 ;
break;
}
}
return V_84 ;
}
static int F_87 ( int V_101 , int V_50 , int V_61 )
{
int V_43 ;
int V_102 = V_23 [ V_101 ] . V_18 ;
struct V_6 * V_112 = F_3 ( V_50 ) ;
if ( V_23 [ V_101 ] . V_21 != V_61 )
F_49 ( V_72 L_12 ) ;
if ( F_74 ( V_102 , V_99 ) ) {
V_43 = V_23 [ V_101 ] . V_19 ;
} else {
T_3 V_113 = V_112 -> V_114 + V_61 ;
if ( V_113 >= V_115 )
V_43 = V_113 ;
else
V_43 = V_116 + V_113 ;
}
#ifdef F_88
if ( ( V_61 >= 16 ) && ( V_61 <= 23 ) ) {
if ( V_95 [ V_61 - 16 ] != - 1 ) {
if ( ! V_95 [ V_61 - 16 ] ) {
F_8 ( V_15 , V_94
L_13 , V_61 - 16 ) ;
} else {
V_43 = V_95 [ V_61 - 16 ] ;
F_8 ( V_15 , V_94
L_14 ,
V_61 - 16 , V_43 ) ;
}
}
}
#endif
return V_43 ;
}
int F_89 ( int V_102 , int V_117 , int V_61 ,
struct V_118 * V_119 )
{
int V_1 , V_14 , V_120 = - 1 ;
F_8 ( V_121 ,
L_15 ,
V_102 , V_117 , V_61 ) ;
if ( F_74 ( V_102 , V_99 ) ) {
F_8 ( V_15 ,
L_16 , V_102 ) ;
return - 1 ;
}
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ ) {
int V_98 = V_23 [ V_14 ] . V_18 ;
for ( V_1 = 0 ; V_1 < V_34 ; V_1 ++ )
if ( F_1 ( V_1 ) == V_23 [ V_14 ] . V_20 ||
V_23 [ V_14 ] . V_20 == V_97 )
break;
if ( ! F_74 ( V_98 , V_99 ) &&
! V_23 [ V_14 ] . V_16 &&
( V_102 == V_98 ) &&
( V_117 == ( ( V_23 [ V_14 ] . V_19 >> 2 ) & 0x1f ) ) ) {
int V_43 = F_87 ( V_14 , V_1 , V_23 [ V_14 ] . V_21 ) ;
if ( ! ( V_1 || F_90 ( V_43 ) ) )
continue;
if ( V_61 == ( V_23 [ V_14 ] . V_19 & 3 ) ) {
F_91 ( V_119 , V_1 ,
V_23 [ V_14 ] . V_21 ,
F_81 ( V_14 ) ,
F_78 ( V_14 ) ) ;
return V_43 ;
}
if ( V_120 < 0 ) {
F_91 ( V_119 , V_1 ,
V_23 [ V_14 ] . V_21 ,
F_81 ( V_14 ) ,
F_78 ( V_14 ) ) ;
V_120 = V_43 ;
}
}
}
return V_120 ;
}
void F_92 ( void )
{
F_93 ( & V_122 ) ;
}
void F_94 ( void )
{
F_95 ( & V_122 ) ;
}
static int
F_96 ( int V_43 , struct V_28 * V_29 , const struct V_123 * V_68 )
{
static int V_124 = V_125 + V_126 ;
static int V_127 = V_126 % 8 ;
unsigned int V_128 ;
int V_129 , V_96 ;
T_4 V_130 ;
if ( V_29 -> V_131 )
return - V_132 ;
if ( ! F_97 ( & V_130 , V_133 ) )
return - V_73 ;
V_128 = V_29 -> V_41 ;
if ( V_128 ) {
F_98 ( V_130 , V_68 , V_134 ) ;
F_98 ( V_130 , V_29 -> V_39 , V_130 ) ;
if ( ! F_99 ( V_130 ) ) {
F_23 ( V_130 ) ;
return 0 ;
}
}
V_96 = - V_135 ;
F_100 (cpu, mask, cpu_online_mask) {
int V_136 ;
int V_41 , V_137 ;
V_50 -> V_138 ( V_129 , V_130 ) ;
V_41 = V_124 ;
V_137 = V_127 ;
V_71:
V_41 += 8 ;
if ( V_41 >= V_139 ) {
V_137 = ( V_137 + 1 ) % 8 ;
V_41 = V_125 + V_137 ;
}
if ( F_101 ( V_124 == V_41 ) )
continue;
if ( F_74 ( V_41 , V_140 ) )
goto V_71;
F_100 (new_cpu, tmp_mask, cpu_online_mask)
if ( F_102 ( V_141 , V_136 ) [ V_41 ] != - 1 )
goto V_71;
V_124 = V_41 ;
V_127 = V_137 ;
if ( V_128 ) {
V_29 -> V_131 = 1 ;
F_103 ( V_29 -> V_40 , V_29 -> V_39 ) ;
}
F_100 (new_cpu, tmp_mask, cpu_online_mask)
F_102 ( V_141 , V_136 ) [ V_41 ] = V_43 ;
V_29 -> V_41 = V_41 ;
F_103 ( V_29 -> V_39 , V_130 ) ;
V_96 = 0 ;
break;
}
F_23 ( V_130 ) ;
return V_96 ;
}
int F_104 ( int V_43 , struct V_28 * V_29 , const struct V_123 * V_68 )
{
int V_96 ;
unsigned long V_59 ;
F_40 ( & V_122 , V_59 ) ;
V_96 = F_96 ( V_43 , V_29 , V_68 ) ;
F_42 ( & V_122 , V_59 ) ;
return V_96 ;
}
static void F_105 ( int V_43 , struct V_28 * V_29 )
{
int V_129 , V_41 ;
F_106 ( ! V_29 -> V_41 ) ;
V_41 = V_29 -> V_41 ;
F_100 (cpu, cfg->domain, cpu_online_mask)
F_102 ( V_141 , V_129 ) [ V_41 ] = - 1 ;
V_29 -> V_41 = 0 ;
F_107 ( V_29 -> V_39 ) ;
if ( F_108 ( ! V_29 -> V_131 ) )
return;
F_100 (cpu, cfg->old_domain, cpu_online_mask) {
for ( V_41 = V_125 ; V_41 < V_142 ;
V_41 ++ ) {
if ( F_102 ( V_141 , V_129 ) [ V_41 ] != V_43 )
continue;
F_102 ( V_141 , V_129 ) [ V_41 ] = - 1 ;
break;
}
}
V_29 -> V_131 = 0 ;
}
void F_109 ( int V_129 )
{
int V_43 , V_41 ;
struct V_28 * V_29 ;
F_93 ( & V_122 ) ;
F_110 (irq) {
V_29 = F_21 ( V_43 ) ;
if ( ! V_29 )
continue;
if ( V_43 < V_31 -> V_32 && ! F_90 ( V_43 ) )
F_20 ( V_129 , V_29 -> V_39 ) ;
if ( ! F_111 ( V_129 , V_29 -> V_39 ) )
continue;
V_41 = V_29 -> V_41 ;
F_102 ( V_141 , V_129 ) [ V_41 ] = V_43 ;
}
for ( V_41 = 0 ; V_41 < V_142 ; ++ V_41 ) {
V_43 = F_102 ( V_141 , V_129 ) [ V_41 ] ;
if ( V_43 < 0 )
continue;
V_29 = V_28 ( V_43 ) ;
if ( ! F_111 ( V_129 , V_29 -> V_39 ) )
F_102 ( V_141 , V_129 ) [ V_41 ] = - 1 ;
}
F_95 ( & V_122 ) ;
}
static inline int F_112 ( int V_43 )
{
int V_50 , V_101 , V_61 ;
for ( V_50 = 0 ; V_50 < V_34 ; V_50 ++ ) {
for ( V_61 = 0 ; V_61 < V_2 [ V_50 ] . V_37 ; V_61 ++ ) {
V_101 = F_72 ( V_50 , V_61 , V_143 ) ;
if ( ( V_101 != - 1 ) && ( V_43 == F_87 ( V_101 , V_50 , V_61 ) ) )
return F_81 ( V_101 ) ;
}
}
return 0 ;
}
static inline int F_112 ( int V_43 )
{
return 1 ;
}
static void F_113 ( unsigned int V_43 , struct V_28 * V_29 ,
unsigned long V_84 )
{
struct V_144 * V_145 = & V_146 ;
T_5 V_147 ;
bool V_148 ;
if ( ( V_84 == V_149 && F_112 ( V_43 ) ) ||
V_84 == V_89 ) {
F_114 ( V_43 , V_150 ) ;
V_148 = true ;
} else {
F_115 ( V_43 , V_150 ) ;
V_148 = false ;
}
if ( F_63 ( V_29 ) ) {
F_114 ( V_43 , V_151 ) ;
F_116 ( V_145 ) ;
V_148 = V_84 != 0 ;
}
V_147 = V_148 ? V_152 : V_153 ;
F_117 ( V_43 , V_145 , V_147 ,
V_148 ? L_17 : L_18 ) ;
}
static int F_118 ( int V_43 ,
struct V_154 * V_58 ,
unsigned int V_155 , int V_41 ,
struct V_118 * V_156 )
{
int V_54 ;
struct V_157 V_157 ;
int V_158 = F_1 ( V_156 -> V_159 ) ;
struct V_160 * V_161 = F_119 ( V_158 ) ;
if ( ! V_161 ) {
F_120 ( L_19 , V_158 ) ;
return - V_162 ;
}
V_54 = F_121 ( V_161 , V_43 , 1 ) ;
if ( V_54 < 0 ) {
F_120 ( L_20 , V_158 ) ;
return - V_73 ;
}
F_122 ( & V_157 , V_41 , V_155 ) ;
F_123 ( & V_157 , V_158 ) ;
F_124 ( V_43 , & V_157 ) ;
F_8 ( V_15 , V_94 L_21
L_22
L_23
L_24
L_25 ,
V_156 -> V_159 , V_157 . V_163 , V_157 . V_164 , V_157 . V_165 ,
V_157 . V_166 , V_157 . V_167 , V_157 . V_168 ,
V_157 . V_169 , V_157 . V_41 , V_157 . V_170 ,
V_157 . V_171 , V_157 . V_172 , V_157 . V_173 ) ;
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
V_58 -> V_174 = ( V_54 >> 15 ) & 0x1 ;
V_58 -> V_175 = 0 ;
V_58 -> V_176 = 1 ;
V_58 -> V_54 = ( V_54 & 0x7fff ) ;
V_58 -> V_41 = V_156 -> V_177 ;
V_58 -> V_68 = 0 ;
V_58 -> V_84 = V_156 -> V_84 ;
V_58 -> V_103 = V_156 -> V_103 ;
if ( V_156 -> V_84 )
V_58 -> V_68 = 1 ;
return 0 ;
}
static int F_125 ( int V_43 , struct V_36 * V_58 ,
unsigned int V_155 , int V_41 ,
struct V_118 * V_156 )
{
if ( V_178 )
return F_118 ( V_43 ,
(struct V_154 * ) V_58 ,
V_155 , V_41 , V_156 ) ;
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
V_58 -> V_86 = V_50 -> V_179 ;
V_58 -> V_180 = V_50 -> V_181 ;
V_58 -> V_182 = V_155 ;
V_58 -> V_41 = V_41 ;
V_58 -> V_68 = 0 ;
V_58 -> V_84 = V_156 -> V_84 ;
V_58 -> V_103 = V_156 -> V_103 ;
if ( V_156 -> V_84 )
V_58 -> V_68 = 1 ;
return 0 ;
}
static void F_126 ( unsigned int V_43 , struct V_28 * V_29 ,
struct V_118 * V_156 )
{
struct V_36 V_58 ;
unsigned int V_182 ;
if ( ! F_90 ( V_43 ) )
return;
if ( V_43 < V_31 -> V_32 && F_111 ( 0 , V_29 -> V_39 ) )
V_50 -> V_138 ( 0 , V_29 -> V_39 ) ;
if ( F_104 ( V_43 , V_29 , V_50 -> V_183 () ) )
return;
V_182 = V_50 -> V_184 ( V_29 -> V_39 , V_50 -> V_183 () ) ;
F_8 ( V_15 , V_94
L_26
L_27 ,
V_156 -> V_159 , F_1 ( V_156 -> V_159 ) , V_156 -> V_177 ,
V_29 -> V_41 , V_43 , V_156 -> V_84 , V_156 -> V_103 , V_182 ) ;
if ( F_125 ( V_43 , & V_58 , V_182 , V_29 -> V_41 , V_156 ) ) {
F_120 ( L_28 ,
F_1 ( V_156 -> V_159 ) , V_156 -> V_177 ) ;
F_105 ( V_43 , V_29 ) ;
return;
}
F_113 ( V_43 , V_29 , V_156 -> V_84 ) ;
if ( V_43 < V_31 -> V_32 )
V_31 -> V_68 ( V_43 ) ;
F_46 ( V_156 -> V_159 , V_156 -> V_177 , V_58 ) ;
}
static bool T_1 F_127 ( int V_101 , int V_1 , int V_61 )
{
if ( V_101 != - 1 )
return false ;
F_8 ( V_15 , V_94 L_29 ,
F_1 ( V_1 ) , V_61 ) ;
return true ;
}
static void T_1 F_128 ( unsigned int V_1 )
{
int V_101 , V_26 = F_16 ( 0 ) ;
struct V_118 V_156 ;
unsigned int V_61 , V_43 ;
for ( V_61 = 0 ; V_61 < V_2 [ V_1 ] . V_37 ; V_61 ++ ) {
V_101 = F_72 ( V_1 , V_61 , V_143 ) ;
if ( F_127 ( V_101 , V_1 , V_61 ) )
continue;
V_43 = F_87 ( V_101 , V_1 , V_61 ) ;
if ( ( V_1 > 0 ) && ( V_43 > 16 ) )
continue;
if ( V_50 -> V_185 &&
V_50 -> V_185 ( V_1 , V_43 ) )
continue;
F_91 ( & V_156 , V_1 , V_61 , F_81 ( V_101 ) ,
F_78 ( V_101 ) ) ;
F_129 ( V_43 , V_26 , & V_156 ) ;
}
}
static void T_1 F_130 ( void )
{
unsigned int V_1 ;
F_8 ( V_15 , V_94 L_30 ) ;
for ( V_1 = 0 ; V_1 < V_34 ; V_1 ++ )
F_128 ( V_1 ) ;
}
void F_131 ( T_3 V_113 )
{
int V_1 = 0 , V_61 , V_101 , V_43 , V_26 = F_16 ( 0 ) ;
struct V_118 V_156 ;
V_1 = F_132 ( V_113 ) ;
if ( V_1 < 0 )
return;
V_61 = F_133 ( V_1 , V_113 ) ;
V_101 = F_72 ( V_1 , V_61 , V_143 ) ;
if ( V_101 == - 1 )
return;
V_43 = F_87 ( V_101 , V_1 , V_61 ) ;
if ( V_1 == 0 || V_43 < V_115 )
return;
F_91 ( & V_156 , V_1 , V_61 , F_81 ( V_101 ) ,
F_78 ( V_101 ) ) ;
F_134 ( V_43 , V_26 , & V_156 ) ;
}
static void T_1 F_135 ( unsigned int V_1 ,
unsigned int V_61 , int V_41 )
{
struct V_36 V_58 ;
if ( V_178 )
return;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_180 = V_50 -> V_181 ;
V_58 . V_68 = 0 ;
V_58 . V_182 = V_50 -> V_186 ( V_50 -> V_183 () ) ;
V_58 . V_86 = V_50 -> V_179 ;
V_58 . V_103 = 0 ;
V_58 . V_84 = 0 ;
V_58 . V_41 = V_41 ;
F_117 ( 0 , & V_146 , V_153 ,
L_18 ) ;
F_46 ( V_1 , V_61 , V_58 ) ;
}
static T_1 int F_136 ( char * V_187 )
{
int V_188 = - 1 ;
if ( strcmp ( V_187 , L_31 ) == 0 ) {
V_189 = V_190 ;
} else {
F_137 ( & V_187 , & V_188 ) ;
if ( V_188 >= 0 )
V_189 = V_188 ;
}
return 1 ;
}
void T_1 F_138 ( void )
{
int V_191 , V_192 ;
int V_50 ;
if ( ! V_31 -> V_32 )
return;
for( V_50 = 0 ; V_50 < V_34 ; V_50 ++ ) {
int V_61 ;
for ( V_61 = 0 ; V_61 < V_2 [ V_50 ] . V_37 ; V_61 ++ ) {
struct V_36 V_58 ;
V_58 = F_44 ( V_50 , V_61 ) ;
if ( ( V_58 . V_68 == 0 ) && ( V_58 . V_86 == V_193 ) ) {
V_194 . V_50 = V_50 ;
V_194 . V_61 = V_61 ;
goto V_195;
}
}
}
V_195:
V_192 = F_73 ( 0 , V_196 ) ;
V_191 = F_75 ( 0 , V_196 ) ;
if ( ( V_194 . V_61 == - 1 ) && ( V_192 >= 0 ) ) {
F_49 ( V_104 L_32 ) ;
V_194 . V_61 = V_192 ;
V_194 . V_50 = V_191 ;
}
if ( ( ( V_194 . V_50 != V_191 ) || ( V_194 . V_61 != V_192 ) ) &&
( V_192 >= 0 ) && ( V_194 . V_61 >= 0 ) )
{
F_49 ( V_104 L_33 ) ;
}
F_66 () ;
}
void F_139 ( void )
{
F_66 () ;
if ( ! V_31 -> V_32 )
return;
if ( V_194 . V_61 != - 1 && ! V_178 ) {
struct V_36 V_58 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_68 = 0 ;
V_58 . V_84 = 0 ;
V_58 . V_88 = 0 ;
V_58 . V_103 = 0 ;
V_58 . V_197 = 0 ;
V_58 . V_180 = 0 ;
V_58 . V_86 = V_193 ;
V_58 . V_41 = 0 ;
V_58 . V_182 = F_140 () ;
F_46 ( V_194 . V_50 , V_194 . V_61 , V_58 ) ;
}
if ( V_198 || F_141 () )
F_142 ( ! V_178 &&
V_194 . V_61 != - 1 ) ;
}
void T_1 F_143 ( void )
{
union V_199 V_200 ;
T_6 V_201 ;
int V_1 ;
int V_14 ;
unsigned char V_202 ;
unsigned long V_59 ;
V_50 -> V_203 ( & V_204 , & V_201 ) ;
for ( V_1 = 0 ; V_1 < V_34 ; V_1 ++ ) {
F_40 ( & V_60 , V_59 ) ;
V_200 . V_205 = F_35 ( V_1 , 0 ) ;
F_42 ( & V_60 , V_59 ) ;
V_202 = F_1 ( V_1 ) ;
if ( F_1 ( V_1 ) >= F_144 () ) {
F_49 ( V_72 L_34 ,
V_1 , F_1 ( V_1 ) ) ;
F_49 ( V_72 L_35 ,
V_200 . V_206 . V_207 ) ;
V_2 [ V_1 ] . V_3 . V_4 = V_200 . V_206 . V_207 ;
}
if ( V_50 -> V_208 ( & V_201 ,
F_1 ( V_1 ) ) ) {
F_49 ( V_72 L_36 ,
V_1 , F_1 ( V_1 ) ) ;
for ( V_14 = 0 ; V_14 < F_144 () ; V_14 ++ )
if ( ! F_145 ( V_14 , V_201 ) )
break;
if ( V_14 >= F_144 () )
F_9 ( L_37 ) ;
F_49 ( V_72 L_35 ,
V_14 ) ;
F_146 ( V_14 , V_201 ) ;
V_2 [ V_1 ] . V_3 . V_4 = V_14 ;
} else {
T_6 V_209 ;
V_50 -> V_210 ( F_1 ( V_1 ) ,
& V_209 ) ;
F_8 ( V_15 , L_38
L_39 ,
F_1 ( V_1 ) ) ;
F_147 ( V_201 , V_201 , V_209 ) ;
}
if ( V_202 != F_1 ( V_1 ) )
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ )
if ( V_23 [ V_14 ] . V_20 == V_202 )
V_23 [ V_14 ] . V_20
= F_1 ( V_1 ) ;
if ( F_1 ( V_1 ) == V_200 . V_206 . V_207 )
continue;
F_8 ( V_15 , V_93
L_40 ,
F_1 ( V_1 ) ) ;
V_200 . V_206 . V_207 = F_1 ( V_1 ) ;
F_40 ( & V_60 , V_59 ) ;
F_37 ( V_1 , 0 , V_200 . V_205 ) ;
F_42 ( & V_60 , V_59 ) ;
F_40 ( & V_60 , V_59 ) ;
V_200 . V_205 = F_35 ( V_1 , 0 ) ;
F_42 ( & V_60 , V_59 ) ;
if ( V_200 . V_206 . V_207 != F_1 ( V_1 ) )
F_49 ( L_41 ) ;
else
F_8 ( V_15 , L_42 ) ;
}
}
void T_1 F_148 ( void )
{
if ( V_211 )
return;
if ( ! ( V_212 . V_213 == V_214 )
|| F_149 ( V_215 [ V_216 ] ) )
return;
F_143 () ;
}
static int T_1 F_150 ( char * V_217 )
{
V_218 = 1 ;
return 1 ;
}
static int T_1 F_151 ( void )
{
unsigned long V_219 = V_220 ;
unsigned long V_59 ;
if ( V_218 )
return 1 ;
F_152 ( V_59 ) ;
F_153 () ;
F_154 ( ( 10 * 1000 ) / V_221 ) ;
F_155 ( V_59 ) ;
if ( F_156 ( V_220 , V_219 + 4 ) )
return 1 ;
return 0 ;
}
static unsigned int F_157 ( struct V_81 * V_55 )
{
int V_222 = 0 , V_43 = V_55 -> V_43 ;
unsigned long V_59 ;
F_40 ( & V_60 , V_59 ) ;
if ( V_43 < V_31 -> V_32 ) {
V_31 -> V_68 ( V_43 ) ;
if ( V_31 -> V_223 ( V_43 ) )
V_222 = 1 ;
}
F_58 ( V_55 -> V_82 ) ;
F_42 ( & V_60 , V_59 ) ;
return V_222 ;
}
static int F_158 ( struct V_81 * V_55 )
{
struct V_28 * V_29 = V_55 -> V_82 ;
unsigned long V_59 ;
F_40 ( & V_122 , V_59 ) ;
V_50 -> V_224 ( F_159 ( F_160 ( V_29 -> V_39 ) ) , V_29 -> V_41 ) ;
F_42 ( & V_122 , V_59 ) ;
return 1 ;
}
void F_161 ( struct V_28 * V_29 )
{
T_4 V_225 ;
if ( F_101 ( ! F_97 ( & V_225 , V_133 ) ) ) {
unsigned int V_14 ;
F_100 (i, cfg->old_domain, cpu_online_mask)
V_50 -> V_224 ( F_159 ( V_14 ) , V_226 ) ;
} else {
F_98 ( V_225 , V_29 -> V_40 , V_134 ) ;
V_50 -> V_224 ( V_225 , V_226 ) ;
F_23 ( V_225 ) ;
}
V_29 -> V_131 = 0 ;
}
static void F_162 ( unsigned int V_43 , unsigned int V_182 , struct V_28 * V_29 )
{
int V_50 , V_61 ;
struct V_25 * V_58 ;
T_7 V_41 = V_29 -> V_41 ;
F_41 (entry, cfg->irq_2_pin) {
unsigned int V_53 ;
V_50 = V_58 -> V_50 ;
V_61 = V_58 -> V_61 ;
if ( ! F_63 ( V_29 ) )
F_37 ( V_50 , 0x11 + V_61 * 2 , V_182 ) ;
V_53 = F_35 ( V_50 , 0x10 + V_61 * 2 ) ;
V_53 &= ~ V_227 ;
V_53 |= V_41 ;
F_38 ( V_50 , 0x10 + V_61 * 2 , V_53 ) ;
}
}
int F_163 ( struct V_81 * V_55 , const struct V_123 * V_68 ,
unsigned int * V_170 )
{
struct V_28 * V_29 = V_55 -> V_82 ;
if ( ! F_164 ( V_68 , V_134 ) )
return - 1 ;
if ( F_104 ( V_55 -> V_43 , V_55 -> V_82 , V_68 ) )
return - 1 ;
F_103 ( V_55 -> V_228 , V_68 ) ;
* V_170 = V_50 -> V_184 ( V_68 , V_29 -> V_39 ) ;
return 0 ;
}
static int
F_165 ( struct V_81 * V_55 , const struct V_123 * V_68 ,
bool V_229 )
{
unsigned int V_182 , V_43 = V_55 -> V_43 ;
unsigned long V_59 ;
int V_230 ;
F_40 ( & V_60 , V_59 ) ;
V_230 = F_163 ( V_55 , V_68 , & V_182 ) ;
if ( ! V_230 ) {
V_182 = F_166 ( V_182 ) ;
F_162 ( V_43 , V_182 , V_55 -> V_82 ) ;
}
F_42 ( & V_60 , V_59 ) ;
return V_230 ;
}
static int
F_167 ( struct V_81 * V_55 , const struct V_123 * V_68 ,
bool V_229 )
{
struct V_28 * V_29 = V_55 -> V_82 ;
unsigned int V_182 , V_43 = V_55 -> V_43 ;
struct V_157 V_157 ;
if ( ! F_164 ( V_68 , V_134 ) )
return - V_231 ;
if ( F_168 ( V_43 , & V_157 ) )
return - V_132 ;
if ( F_104 ( V_43 , V_29 , V_68 ) )
return - V_132 ;
V_182 = V_50 -> V_184 ( V_29 -> V_39 , V_68 ) ;
V_157 . V_41 = V_29 -> V_41 ;
V_157 . V_170 = F_169 ( V_182 ) ;
F_124 ( V_43 , & V_157 ) ;
if ( V_29 -> V_131 )
F_161 ( V_29 ) ;
F_103 ( V_55 -> V_228 , V_68 ) ;
return 0 ;
}
static inline int
F_167 ( struct V_81 * V_55 , const struct V_123 * V_68 ,
bool V_229 )
{
return 0 ;
}
T_8 void F_170 ( void )
{
unsigned V_41 , V_232 ;
F_171 () ;
F_172 () ;
F_173 () ;
V_232 = F_174 () ;
for ( V_41 = V_125 ; V_41 < V_142 ; V_41 ++ ) {
unsigned int V_43 ;
unsigned int V_88 ;
struct V_233 * V_234 ;
struct V_28 * V_29 ;
V_43 = F_175 ( V_141 [ V_41 ] ) ;
if ( V_43 == - 1 )
continue;
V_234 = F_176 ( V_43 ) ;
if ( ! V_234 )
continue;
V_29 = V_28 ( V_43 ) ;
F_93 ( & V_234 -> V_235 ) ;
if ( V_29 -> V_131 )
goto V_236;
if ( V_41 == V_29 -> V_41 && F_111 ( V_232 , V_29 -> V_39 ) )
goto V_236;
V_88 = F_177 ( V_237 + ( V_41 / 32 * 0x10 ) ) ;
if ( V_88 & ( 1 << ( V_41 % 32 ) ) ) {
V_50 -> V_238 ( V_226 ) ;
goto V_236;
}
F_178 ( V_141 [ V_41 ] , - 1 ) ;
V_236:
F_95 ( & V_234 -> V_235 ) ;
}
F_179 () ;
}
static void F_180 ( struct V_28 * V_29 , unsigned V_41 )
{
unsigned V_232 ;
if ( F_108 ( ! V_29 -> V_131 ) )
return;
V_232 = F_174 () ;
if ( V_41 == V_29 -> V_41 && F_111 ( V_232 , V_29 -> V_39 ) )
F_161 ( V_29 ) ;
}
static void F_181 ( struct V_28 * V_29 )
{
F_180 ( V_29 , ~ F_182 () -> V_239 ) ;
}
void F_183 ( int V_43 )
{
struct V_28 * V_29 = F_21 ( V_43 ) ;
if ( ! V_29 )
return;
F_180 ( V_29 , V_29 -> V_41 ) ;
}
static inline void F_181 ( struct V_28 * V_29 ) { }
static void F_184 ( struct V_81 * V_55 )
{
F_181 ( V_55 -> V_82 ) ;
F_185 ( V_55 ) ;
F_171 () ;
}
static void F_186 ( struct V_81 * V_55 )
{
struct V_28 * V_29 = V_55 -> V_82 ;
int V_14 , V_240 = 0 , V_43 = V_55 -> V_43 ;
unsigned long V_241 ;
F_181 ( V_29 ) ;
#ifdef F_187
if ( F_101 ( F_188 ( V_55 ) ) ) {
V_240 = 1 ;
F_56 ( V_29 ) ;
}
#endif
V_14 = V_29 -> V_41 ;
V_241 = F_177 ( V_242 + ( ( V_14 & ~ 0x1f ) >> 1 ) ) ;
F_171 () ;
if ( ! ( V_241 & ( 1 << ( V_14 & 0x1f ) ) ) ) {
F_189 ( & V_243 ) ;
F_64 ( V_43 , V_29 ) ;
}
if ( F_101 ( V_240 ) ) {
if ( ! F_39 ( V_29 ) )
F_190 ( V_55 ) ;
F_59 ( V_29 ) ;
}
}
static void F_191 ( struct V_81 * V_55 )
{
F_171 () ;
}
static void F_192 ( struct V_81 * V_55 )
{
F_171 () ;
F_64 ( V_55 -> V_43 , V_55 -> V_82 ) ;
}
static void F_193 ( struct V_81 * V_55 , struct V_244 * V_245 )
{
F_194 ( V_245 , L_43 , V_55 -> V_145 -> V_246 ) ;
}
static void F_116 ( struct V_144 * V_145 )
{
V_145 -> V_247 = F_193 ;
V_145 -> V_248 = F_191 ;
V_145 -> V_249 = F_192 ;
#ifdef F_195
V_145 -> V_250 = F_167 ;
#endif
}
static inline void F_196 ( void )
{
struct V_28 * V_29 ;
unsigned int V_43 ;
F_110 (irq) {
V_29 = F_21 ( V_43 ) ;
if ( F_90 ( V_43 ) && V_29 && ! V_29 -> V_41 ) {
if ( V_43 < V_31 -> V_32 )
V_31 -> V_251 ( V_43 ) ;
else
F_197 ( V_43 , & V_252 ) ;
}
}
}
static void F_198 ( struct V_81 * V_55 )
{
unsigned long V_241 ;
V_241 = F_177 ( V_253 ) ;
F_199 ( V_253 , V_241 | V_254 ) ;
}
static void F_200 ( struct V_81 * V_55 )
{
unsigned long V_241 ;
V_241 = F_177 ( V_253 ) ;
F_199 ( V_253 , V_241 & ~ V_254 ) ;
}
static void F_201 ( struct V_81 * V_55 )
{
F_171 () ;
}
static void F_202 ( int V_43 )
{
F_115 ( V_43 , V_150 ) ;
F_117 ( V_43 , & V_255 , V_153 ,
L_18 ) ;
}
static inline void T_1 F_203 ( void )
{
int V_50 , V_61 , V_14 ;
struct V_36 V_256 , V_83 ;
unsigned char V_257 , V_258 ;
V_61 = F_73 ( 8 , V_143 ) ;
if ( V_61 == - 1 ) {
F_204 ( 1 ) ;
return;
}
V_50 = F_75 ( 8 , V_143 ) ;
if ( V_50 == - 1 ) {
F_204 ( 1 ) ;
return;
}
V_256 = F_44 ( V_50 , V_61 ) ;
F_65 ( V_50 , V_61 ) ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_180 = 0 ;
V_83 . V_68 = 0 ;
V_83 . V_182 = F_205 () ;
V_83 . V_86 = V_193 ;
V_83 . V_103 = V_256 . V_103 ;
V_83 . V_84 = 0 ;
V_83 . V_41 = 0 ;
F_46 ( V_50 , V_61 , V_83 ) ;
V_257 = F_206 ( V_259 ) ;
V_258 = F_206 ( V_260 ) ;
F_207 ( ( V_258 & ~ V_261 ) | 0x6 ,
V_260 ) ;
F_207 ( V_257 | V_262 , V_259 ) ;
V_14 = 100 ;
while ( V_14 -- > 0 ) {
F_154 ( 10 ) ;
if ( ( F_206 ( V_263 ) & V_264 ) == V_264 )
V_14 -= 10 ;
}
F_207 ( V_257 , V_259 ) ;
F_207 ( V_258 , V_260 ) ;
F_65 ( V_50 , V_61 ) ;
F_46 ( V_50 , V_61 , V_256 ) ;
}
static int T_1 F_208 ( char * V_187 )
{
V_265 = 1 ;
return 0 ;
}
static inline void T_1 F_209 ( void )
{
struct V_28 * V_29 = F_21 ( 0 ) ;
int V_26 = F_16 ( 0 ) ;
int V_266 , V_267 , V_268 , V_269 ;
unsigned long V_59 ;
int V_270 = 0 ;
F_210 ( V_59 ) ;
V_31 -> V_68 ( 0 ) ;
F_104 ( 0 , V_29 , V_50 -> V_183 () ) ;
F_199 ( V_253 , V_254 | V_271 ) ;
V_31 -> V_272 ( 1 ) ;
V_267 = F_73 ( 0 , V_143 ) ;
V_266 = F_75 ( 0 , V_143 ) ;
V_269 = V_194 . V_61 ;
V_268 = V_194 . V_50 ;
F_8 ( V_273 , V_93 L_44
L_45 ,
V_29 -> V_41 , V_266 , V_267 , V_268 , V_269 ) ;
if ( V_267 == - 1 ) {
if ( V_178 )
F_9 ( L_46 ) ;
V_267 = V_269 ;
V_266 = V_268 ;
V_270 = 1 ;
} else if ( V_269 == - 1 ) {
V_269 = V_267 ;
V_268 = V_266 ;
}
if ( V_267 != - 1 ) {
if ( V_270 ) {
F_50 ( V_29 , V_26 , V_266 , V_267 ) ;
F_135 ( V_266 , V_267 , V_29 -> V_41 ) ;
} else {
int V_101 ;
V_101 = F_72 ( V_266 , V_267 , V_143 ) ;
if ( V_101 != - 1 && F_81 ( V_101 ) )
F_59 ( V_29 ) ;
}
if ( F_151 () ) {
if ( V_265 > 0 )
F_65 ( 0 , V_267 ) ;
goto V_274;
}
if ( V_178 )
F_9 ( L_47 ) ;
F_211 () ;
F_65 ( V_266 , V_267 ) ;
if ( ! V_270 )
F_8 ( V_273 , V_72 L_48
L_49 ) ;
F_8 ( V_273 , V_93 L_50
L_51 ) ;
F_8 ( V_273 , V_93
L_52 , V_268 , V_269 ) ;
F_51 ( V_29 , V_26 , V_266 , V_267 , V_268 , V_269 ) ;
F_135 ( V_268 , V_269 , V_29 -> V_41 ) ;
V_31 -> V_275 ( 0 ) ;
if ( F_151 () ) {
F_8 ( V_273 , V_93 L_53 ) ;
V_276 = 1 ;
goto V_274;
}
F_211 () ;
V_31 -> V_68 ( 0 ) ;
F_65 ( V_268 , V_269 ) ;
F_8 ( V_273 , V_93 L_54 ) ;
}
F_8 ( V_273 , V_93
L_55 ) ;
F_202 ( 0 ) ;
F_199 ( V_253 , V_277 | V_29 -> V_41 ) ;
V_31 -> V_275 ( 0 ) ;
if ( F_151 () ) {
F_8 ( V_273 , V_93 L_56 ) ;
goto V_274;
}
F_211 () ;
V_31 -> V_68 ( 0 ) ;
F_199 ( V_253 , V_254 | V_277 | V_29 -> V_41 ) ;
F_8 ( V_273 , V_93 L_57 ) ;
F_8 ( V_273 , V_93
L_58 ) ;
V_31 -> V_272 ( 0 ) ;
V_31 -> V_251 ( 0 ) ;
F_199 ( V_253 , V_271 ) ;
F_203 () ;
if ( F_151 () ) {
F_8 ( V_273 , V_93 L_56 ) ;
goto V_274;
}
F_211 () ;
F_8 ( V_273 , V_93 L_59 ) ;
if ( V_278 )
F_8 ( V_273 , V_93
L_60
L_61 ) ;
F_9 ( L_62
L_63 ) ;
V_274:
F_155 ( V_59 ) ;
}
void T_1 F_212 ( void )
{
V_33 = V_31 -> V_32 ? ~ V_279 : ~ 0UL ;
F_8 ( V_15 , L_64 ) ;
V_280 . V_281 . V_282 () ;
F_213 () ;
F_130 () ;
F_196 () ;
if ( V_31 -> V_32 )
F_209 () ;
}
static int T_1 F_214 ( void )
{
if ( V_57 == - 1 )
V_57 = 0 ;
return 0 ;
}
static void F_215 ( int V_1 )
{
unsigned long V_59 ;
union V_199 V_200 ;
F_40 ( & V_60 , V_59 ) ;
V_200 . V_205 = F_35 ( V_1 , 0 ) ;
if ( V_200 . V_206 . V_207 != F_1 ( V_1 ) ) {
V_200 . V_206 . V_207 = F_1 ( V_1 ) ;
F_37 ( V_1 , 0 , V_200 . V_205 ) ;
}
F_42 ( & V_60 , V_59 ) ;
}
static void F_216 ( void )
{
int V_1 ;
for ( V_1 = V_34 - 1 ; V_1 >= 0 ; V_1 -- )
F_215 ( V_1 ) ;
F_71 () ;
}
static int T_1 F_217 ( void )
{
F_218 ( & V_283 ) ;
return 0 ;
}
unsigned int F_219 ( unsigned int V_49 , int V_26 )
{
struct V_28 * V_29 ;
unsigned long V_59 ;
unsigned int V_230 = 0 ;
int V_43 ;
if ( V_49 < V_284 )
V_49 = V_284 ;
V_43 = F_29 ( V_49 , V_26 ) ;
if ( V_43 < 0 )
return 0 ;
V_29 = F_22 ( V_43 , V_26 ) ;
if ( ! V_29 ) {
F_31 ( V_43 , NULL ) ;
return 0 ;
}
F_40 ( & V_122 , V_59 ) ;
if ( ! F_96 ( V_43 , V_29 , V_50 -> V_183 () ) )
V_230 = V_43 ;
F_42 ( & V_122 , V_59 ) ;
if ( V_230 ) {
F_18 ( V_43 , V_29 ) ;
F_115 ( V_43 , V_285 ) ;
} else {
F_31 ( V_43 , V_29 ) ;
}
return V_230 ;
}
int F_220 ( void )
{
int V_26 = F_16 ( 0 ) ;
unsigned int V_286 ;
int V_43 ;
V_286 = V_284 ;
V_43 = F_219 ( V_286 , V_26 ) ;
if ( V_43 == 0 )
V_43 = - 1 ;
return V_43 ;
}
void F_221 ( unsigned int V_43 )
{
struct V_28 * V_29 = F_21 ( V_43 ) ;
unsigned long V_59 ;
F_114 ( V_43 , V_285 | V_287 ) ;
if ( F_63 ( V_29 ) )
F_222 ( V_43 ) ;
F_40 ( & V_122 , V_59 ) ;
F_105 ( V_43 , V_29 ) ;
F_42 ( & V_122 , V_59 ) ;
F_31 ( V_43 , V_29 ) ;
}
static int F_223 ( struct V_288 * V_289 , unsigned int V_43 ,
struct V_290 * V_291 , T_7 V_292 )
{
struct V_28 * V_29 ;
int V_96 ;
unsigned V_182 ;
if ( V_293 )
return - V_294 ;
V_29 = V_28 ( V_43 ) ;
V_96 = F_104 ( V_43 , V_29 , V_50 -> V_183 () ) ;
if ( V_96 )
return V_96 ;
V_182 = V_50 -> V_184 ( V_29 -> V_39 , V_50 -> V_183 () ) ;
if ( F_63 ( V_29 ) ) {
struct V_157 V_157 ;
int V_295 ;
T_9 V_296 ;
V_295 = F_224 ( V_43 , & V_296 ) ;
F_106 ( V_295 == - 1 ) ;
F_122 ( & V_157 , V_29 -> V_41 , V_182 ) ;
if ( V_289 )
F_225 ( & V_157 , V_289 ) ;
else
F_226 ( & V_157 , V_292 ) ;
F_124 ( V_43 , & V_157 ) ;
V_291 -> V_297 = V_298 ;
V_291 -> V_55 = V_296 ;
V_291 -> V_299 = V_300 | V_301 |
V_302 |
F_227 ( V_295 ) |
F_228 ( V_295 ) ;
} else {
if ( F_229 () )
V_291 -> V_297 = V_298 |
F_230 ( V_182 ) ;
else
V_291 -> V_297 = V_298 ;
V_291 -> V_299 =
V_300 |
( ( V_50 -> V_181 == 0 ) ?
V_303 :
V_304 ) |
( ( V_50 -> V_179 != V_305 ) ?
V_306 :
V_307 ) |
F_231 ( V_182 ) ;
V_291 -> V_55 =
V_308 |
V_309 |
( ( V_50 -> V_179 != V_305 ) ?
V_310 :
V_311 ) |
F_232 ( V_29 -> V_41 ) ;
}
return V_96 ;
}
static int
F_233 ( struct V_81 * V_55 , const struct V_123 * V_68 , bool V_229 )
{
struct V_28 * V_29 = V_55 -> V_82 ;
struct V_290 V_291 ;
unsigned int V_182 ;
if ( F_163 ( V_55 , V_68 , & V_182 ) )
return - 1 ;
F_234 ( V_55 -> V_312 , & V_291 ) ;
V_291 . V_55 &= ~ V_313 ;
V_291 . V_55 |= F_232 ( V_29 -> V_41 ) ;
V_291 . V_299 &= ~ V_314 ;
V_291 . V_299 |= F_231 ( V_182 ) ;
F_235 ( V_55 -> V_312 , & V_291 ) ;
return 0 ;
}
static int F_236 ( struct V_288 * V_315 , int V_43 , int V_316 )
{
struct V_160 * V_161 ;
int V_54 ;
V_161 = F_237 ( V_315 ) ;
if ( ! V_161 ) {
F_49 ( V_72
L_65 , F_238 ( V_315 ) ) ;
return - V_317 ;
}
V_54 = F_121 ( V_161 , V_43 , V_316 ) ;
if ( V_54 < 0 ) {
F_49 ( V_72
L_66 , V_316 ,
F_238 ( V_315 ) ) ;
return - V_135 ;
}
return V_54 ;
}
static int F_239 ( struct V_288 * V_315 , struct V_312 * V_318 , int V_43 )
{
struct V_144 * V_145 = & V_319 ;
struct V_290 V_291 ;
int V_230 ;
V_230 = F_223 ( V_315 , V_43 , & V_291 , - 1 ) ;
if ( V_230 < 0 )
return V_230 ;
F_240 ( V_43 , V_318 ) ;
F_241 ( V_43 , & V_291 ) ;
if ( F_63 ( F_21 ( V_43 ) ) ) {
F_114 ( V_43 , V_151 ) ;
F_116 ( V_145 ) ;
}
F_117 ( V_43 , V_145 , V_153 , L_18 ) ;
F_242 ( V_94 , & V_315 -> V_315 , L_67 , V_43 ) ;
return 0 ;
}
int F_243 ( struct V_288 * V_315 , int V_316 , int type )
{
int V_26 , V_230 , V_296 , V_54 = 0 ;
unsigned int V_43 , V_286 ;
struct V_312 * V_318 ;
struct V_160 * V_161 = NULL ;
if ( type == V_320 && V_316 > 1 )
return 1 ;
V_26 = F_244 ( & V_315 -> V_315 ) ;
V_286 = V_284 ;
V_296 = 0 ;
F_245 (msidesc, &dev->msi_list, list) {
V_43 = F_219 ( V_286 , V_26 ) ;
if ( V_43 == 0 )
return - 1 ;
V_286 = V_43 + 1 ;
if ( ! V_178 )
goto V_321;
if ( ! V_296 ) {
V_54 = F_236 ( V_315 , V_43 , V_316 ) ;
if ( V_54 < 0 ) {
V_230 = V_54 ;
goto error;
}
} else {
V_161 = F_237 ( V_315 ) ;
if ( ! V_161 ) {
V_230 = - V_317 ;
goto error;
}
F_246 ( V_43 , V_161 , V_54 , V_296 ) ;
}
V_321:
V_230 = F_239 ( V_315 , V_318 , V_43 ) ;
if ( V_230 < 0 )
goto error;
V_296 ++ ;
}
return 0 ;
error:
F_221 ( V_43 ) ;
return V_230 ;
}
void F_247 ( unsigned int V_43 )
{
F_221 ( V_43 ) ;
}
static int
F_248 ( struct V_81 * V_55 , const struct V_123 * V_68 ,
bool V_229 )
{
struct V_28 * V_29 = V_55 -> V_82 ;
unsigned int V_182 , V_43 = V_55 -> V_43 ;
struct V_290 V_291 ;
if ( F_163 ( V_55 , V_68 , & V_182 ) )
return - 1 ;
F_249 ( V_43 , & V_291 ) ;
V_291 . V_55 &= ~ V_313 ;
V_291 . V_55 |= F_232 ( V_29 -> V_41 ) ;
V_291 . V_299 &= ~ V_314 ;
V_291 . V_299 |= F_231 ( V_182 ) ;
V_291 . V_297 = V_298 | F_230 ( V_182 ) ;
F_250 ( V_43 , & V_291 ) ;
return 0 ;
}
int F_251 ( unsigned int V_43 )
{
int V_230 ;
struct V_290 V_291 ;
V_230 = F_223 ( NULL , V_43 , & V_291 , - 1 ) ;
if ( V_230 < 0 )
return V_230 ;
F_250 ( V_43 , & V_291 ) ;
F_117 ( V_43 , & V_322 , V_153 ,
L_18 ) ;
return 0 ;
}
static int F_252 ( struct V_81 * V_55 ,
const struct V_123 * V_68 , bool V_229 )
{
struct V_28 * V_29 = V_55 -> V_82 ;
struct V_290 V_291 ;
unsigned int V_182 ;
if ( F_163 ( V_55 , V_68 , & V_182 ) )
return - 1 ;
F_253 ( V_55 -> V_323 , & V_291 ) ;
V_291 . V_55 &= ~ V_313 ;
V_291 . V_55 |= F_232 ( V_29 -> V_41 ) ;
V_291 . V_299 &= ~ V_314 ;
V_291 . V_299 |= F_231 ( V_182 ) ;
F_254 ( V_55 -> V_323 , & V_291 ) ;
return 0 ;
}
int F_255 ( unsigned int V_43 , unsigned int V_324 )
{
struct V_144 * V_145 = & V_325 ;
struct V_290 V_291 ;
int V_230 ;
if ( V_178 ) {
struct V_160 * V_161 = F_256 ( V_324 ) ;
int V_54 ;
if ( ! V_161 )
return - 1 ;
V_54 = F_121 ( V_161 , V_43 , 1 ) ;
if ( V_54 < 0 )
return - 1 ;
}
V_230 = F_223 ( NULL , V_43 , & V_291 , V_324 ) ;
if ( V_230 < 0 )
return V_230 ;
F_254 ( F_257 ( V_43 ) , & V_291 ) ;
F_114 ( V_43 , V_151 ) ;
if ( F_63 ( F_21 ( V_43 ) ) )
F_116 ( V_145 ) ;
F_117 ( V_43 , V_145 , V_153 , L_18 ) ;
return 0 ;
}
static void F_258 ( unsigned int V_43 , unsigned int V_182 , T_7 V_41 )
{
struct V_326 V_291 ;
F_259 ( V_43 , & V_291 ) ;
V_291 . V_299 &= ~ ( V_327 | V_328 ) ;
V_291 . V_297 &= ~ ( V_329 ) ;
V_291 . V_299 |= F_260 ( V_41 ) | F_261 ( V_182 ) ;
V_291 . V_297 |= F_262 ( V_182 ) ;
F_263 ( V_43 , & V_291 ) ;
}
static int
F_264 ( struct V_81 * V_55 , const struct V_123 * V_68 , bool V_229 )
{
struct V_28 * V_29 = V_55 -> V_82 ;
unsigned int V_182 ;
if ( F_163 ( V_55 , V_68 , & V_182 ) )
return - 1 ;
F_258 ( V_55 -> V_43 , V_182 , V_29 -> V_41 ) ;
return 0 ;
}
int F_265 ( unsigned int V_43 , struct V_288 * V_315 )
{
struct V_28 * V_29 ;
int V_96 ;
if ( V_293 )
return - V_294 ;
V_29 = V_28 ( V_43 ) ;
V_96 = F_104 ( V_43 , V_29 , V_50 -> V_183 () ) ;
if ( ! V_96 ) {
struct V_326 V_291 ;
unsigned V_182 ;
V_182 = V_50 -> V_184 ( V_29 -> V_39 ,
V_50 -> V_183 () ) ;
V_291 . V_297 = F_262 ( V_182 ) ;
V_291 . V_299 =
V_330 |
F_261 ( V_182 ) |
F_260 ( V_29 -> V_41 ) |
( ( V_50 -> V_181 == 0 ) ?
V_331 :
V_332 ) |
V_333 |
( ( V_50 -> V_179 != V_305 ) ?
V_334 :
V_335 ) |
V_336 ;
F_263 ( V_43 , & V_291 ) ;
F_117 ( V_43 , & V_337 ,
V_153 , L_18 ) ;
F_242 ( V_94 , & V_315 -> V_315 , L_68 , V_43 ) ;
}
return V_96 ;
}
static int
F_129 ( unsigned int V_43 , int V_26 , struct V_118 * V_156 )
{
struct V_28 * V_29 = F_26 ( V_43 , V_26 ) ;
int V_230 ;
if ( ! V_29 )
return - V_231 ;
V_230 = F_48 ( V_29 , V_26 , V_156 -> V_159 , V_156 -> V_177 ) ;
if ( ! V_230 )
F_126 ( V_43 , V_29 , V_156 ) ;
return V_230 ;
}
int F_134 ( unsigned int V_43 , int V_26 ,
struct V_118 * V_156 )
{
unsigned int V_1 = V_156 -> V_159 , V_61 = V_156 -> V_177 ;
int V_230 ;
if ( F_74 ( V_61 , V_2 [ V_1 ] . V_338 ) ) {
F_266 ( L_69 ,
F_1 ( V_1 ) , V_61 ) ;
return 0 ;
}
V_230 = F_129 ( V_43 , V_26 , V_156 ) ;
if ( ! V_230 )
F_267 ( V_61 , V_2 [ V_1 ] . V_338 ) ;
return V_230 ;
}
static int T_1 F_268 ( int V_159 )
{
union V_339 V_340 ;
unsigned long V_59 ;
F_40 ( & V_60 , V_59 ) ;
V_340 . V_205 = F_35 ( V_159 , 1 ) ;
F_42 ( & V_60 , V_59 ) ;
return V_340 . V_206 . V_341 + 1 ;
}
static void T_1 F_269 ( void )
{
int V_342 ;
V_342 = V_116 + V_115 ;
if ( V_342 > V_284 )
V_284 = V_342 ;
F_49 ( V_94 L_70 , V_284 ) ;
}
int F_270 ( void )
{
return V_284 ;
}
int T_1 F_271 ( void )
{
int V_342 ;
if ( V_343 > ( V_142 * V_344 ) )
V_343 = V_142 * V_344 ;
V_342 = V_284 + 8 * V_344 ;
#if F_84 ( V_345 ) || F_84 ( V_346 )
V_342 += V_284 * 16 ;
#endif
if ( V_342 < V_343 )
V_343 = V_342 ;
return V_115 ;
}
int F_272 ( struct V_347 * V_315 , int V_43 ,
struct V_118 * V_119 )
{
int V_26 ;
if ( ! F_90 ( V_43 ) ) {
F_8 ( V_273 , V_72 L_71 ,
V_119 -> V_159 ) ;
return - V_231 ;
}
V_26 = V_315 ? F_244 ( V_315 ) : F_16 ( 0 ) ;
return F_134 ( V_43 , V_26 , V_119 ) ;
}
static int T_1 F_273 ( int V_159 , int V_348 )
{
union V_199 V_200 ;
static T_6 V_349 = V_350 ;
T_6 V_209 ;
unsigned long V_59 ;
int V_14 = 0 ;
if ( F_274 ( V_349 ) )
V_50 -> V_203 ( & V_204 , & V_349 ) ;
F_40 ( & V_60 , V_59 ) ;
V_200 . V_205 = F_35 ( V_159 , 0 ) ;
F_42 ( & V_60 , V_59 ) ;
if ( V_348 >= F_144 () ) {
F_49 ( V_104 L_72
L_73 , V_159 , V_348 , V_200 . V_206 . V_207 ) ;
V_348 = V_200 . V_206 . V_207 ;
}
if ( V_50 -> V_208 ( & V_349 , V_348 ) ) {
for ( V_14 = 0 ; V_14 < F_144 () ; V_14 ++ ) {
if ( ! V_50 -> V_208 ( & V_349 , V_14 ) )
break;
}
if ( V_14 == F_144 () )
F_9 ( L_74 ) ;
F_49 ( V_104 L_75
L_76 , V_159 , V_348 , V_14 ) ;
V_348 = V_14 ;
}
V_50 -> V_210 ( V_348 , & V_209 ) ;
F_147 ( V_349 , V_349 , V_209 ) ;
if ( V_200 . V_206 . V_207 != V_348 ) {
V_200 . V_206 . V_207 = V_348 ;
F_40 ( & V_60 , V_59 ) ;
F_37 ( V_159 , 0 , V_200 . V_205 ) ;
V_200 . V_205 = F_35 ( V_159 , 0 ) ;
F_42 ( & V_60 , V_59 ) ;
if ( V_200 . V_206 . V_207 != V_348 ) {
F_49 ( L_77 , V_159 ) ;
return - 1 ;
}
}
F_8 ( V_15 , V_93
L_78 , V_159 , V_348 ) ;
return V_348 ;
}
static T_7 T_1 F_275 ( T_7 V_324 )
{
if ( ( V_212 . V_213 == V_214 ) &&
! F_149 ( V_215 [ V_216 ] ) )
return F_273 ( V_34 , V_324 ) ;
else
return V_324 ;
}
static T_7 T_1 F_275 ( T_7 V_324 )
{
int V_14 ;
F_276 ( V_351 , 256 ) ;
F_277 ( V_351 , 256 ) ;
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
F_278 ( F_1 ( V_14 ) , V_351 ) ;
}
if ( ! F_74 ( V_324 , V_351 ) )
return V_324 ;
return F_279 ( V_351 , 256 ) ;
}
static int T_1 F_280 ( int V_159 )
{
union V_339 V_340 ;
unsigned long V_59 ;
F_40 ( & V_60 , V_59 ) ;
V_340 . V_205 = F_35 ( V_159 , 1 ) ;
F_42 ( & V_60 , V_59 ) ;
return V_340 . V_206 . V_352 ;
}
int F_281 ( T_3 V_113 , int * V_84 , int * V_103 )
{
int V_159 , V_61 , V_101 ;
if ( V_10 )
return - 1 ;
V_159 = F_132 ( V_113 ) ;
if ( V_159 < 0 )
return - 1 ;
V_61 = F_133 ( V_159 , V_113 ) ;
if ( V_61 < 0 )
return - 1 ;
V_101 = F_72 ( V_159 , V_61 , V_143 ) ;
if ( V_101 < 0 )
return - 1 ;
* V_84 = F_81 ( V_101 ) ;
* V_103 = F_78 ( V_101 ) ;
return 0 ;
}
void T_1 F_282 ( void )
{
int V_61 , V_159 , V_43 , V_353 ;
const struct V_123 * V_68 ;
struct V_81 * V_354 ;
if ( V_10 == 1 )
return;
for ( V_159 = 0 ; V_159 < V_34 ; V_159 ++ )
for ( V_61 = 0 ; V_61 < V_2 [ V_159 ] . V_37 ; V_61 ++ ) {
V_353 = F_72 ( V_159 , V_61 , V_143 ) ;
if ( V_353 == - 1 )
continue;
V_43 = F_87 ( V_353 , V_159 , V_61 ) ;
if ( ( V_159 > 0 ) && ( V_43 > 16 ) )
continue;
V_354 = F_283 ( V_43 ) ;
if ( ! F_284 ( V_354 ) || F_285 ( V_354 ) )
V_68 = V_354 -> V_228 ;
else
V_68 = V_50 -> V_183 () ;
if ( V_178 )
F_167 ( V_354 , V_68 , false ) ;
else
F_165 ( V_354 , V_68 , false ) ;
}
}
static struct V_355 * T_1 F_286 ( int V_34 )
{
unsigned long V_356 ;
struct V_355 * V_47 ;
char * V_357 ;
int V_14 ;
if ( V_34 <= 0 )
return NULL ;
V_356 = V_358 + sizeof( struct V_355 ) ;
V_356 *= V_34 ;
V_357 = F_287 ( V_356 ) ;
V_47 = ( void * ) V_357 ;
V_357 += sizeof( struct V_355 ) * V_34 ;
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
V_47 [ V_14 ] . V_246 = V_357 ;
V_47 [ V_14 ] . V_59 = V_359 | V_360 ;
snprintf ( V_357 , V_358 , L_79 , V_14 ) ;
V_357 += V_358 ;
}
V_361 = V_47 ;
return V_47 ;
}
void T_1 F_288 ( void )
{
unsigned long V_362 , V_101 = V_363 ;
struct V_355 * V_364 ;
int V_14 ;
V_364 = F_286 ( V_34 ) ;
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
if ( V_365 ) {
V_362 = F_2 ( V_14 ) ;
#ifdef F_88
if ( ! V_362 ) {
F_49 ( V_72
L_80
L_81
L_82 ) ;
V_365 = 0 ;
V_10 = 1 ;
goto V_366;
}
#endif
} else {
#ifdef F_88
V_366:
#endif
V_362 = ( unsigned long ) F_289 ( V_367 ) ;
V_362 = F_290 ( V_362 ) ;
}
F_291 ( V_101 , V_362 ) ;
F_8 ( V_15 , L_83 ,
F_292 ( V_101 ) + ( V_362 & ~ V_368 ) ,
V_362 ) ;
V_101 ++ ;
V_364 -> V_369 = V_362 ;
V_364 -> V_370 = V_362 + V_371 - 1 ;
V_364 ++ ;
}
F_269 () ;
}
void T_1 F_293 ( void )
{
int V_14 ;
struct V_355 * V_372 = V_361 ;
if ( ! V_372 ) {
if ( V_34 > 0 )
F_49 ( V_72
L_84 ) ;
return;
}
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
F_294 ( & V_373 , V_372 ) ;
V_372 ++ ;
}
}
int F_132 ( T_3 V_113 )
{
int V_14 = 0 ;
if ( V_34 == 0 )
return - 1 ;
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
struct V_6 * V_112 = F_3 ( V_14 ) ;
if ( ( V_113 >= V_112 -> V_114 )
&& ( V_113 <= V_112 -> V_374 ) )
return V_14 ;
}
F_49 ( V_72 L_85 , V_113 ) ;
return - 1 ;
}
int F_133 ( int V_159 , T_3 V_113 )
{
struct V_6 * V_112 ;
if ( F_295 ( V_159 == - 1 ) )
return - 1 ;
V_112 = F_3 ( V_159 ) ;
if ( F_295 ( V_113 > V_112 -> V_374 ) )
return - 1 ;
return V_113 - V_112 -> V_114 ;
}
static T_1 int F_296 ( unsigned long V_375 )
{
if ( V_34 >= V_376 ) {
F_49 ( V_104 L_86
L_87 , V_376 , V_34 ) ;
return 1 ;
}
if ( ! V_375 ) {
F_49 ( V_104 L_88
L_89 ) ;
return 1 ;
}
return 0 ;
}
void T_1 F_297 ( int V_324 , T_3 V_375 , T_3 V_114 )
{
int V_101 = 0 ;
int V_341 ;
struct V_6 * V_112 ;
if ( F_296 ( V_375 ) )
return;
V_101 = V_34 ;
V_2 [ V_101 ] . V_3 . type = V_377 ;
V_2 [ V_101 ] . V_3 . V_59 = V_378 ;
V_2 [ V_101 ] . V_3 . V_5 = V_375 ;
F_291 ( V_363 + V_101 , V_375 ) ;
V_2 [ V_101 ] . V_3 . V_4 = F_275 ( V_324 ) ;
V_2 [ V_101 ] . V_3 . V_379 = F_280 ( V_101 ) ;
V_341 = F_268 ( V_101 ) ;
V_112 = F_3 ( V_101 ) ;
V_112 -> V_114 = V_114 ;
V_112 -> V_374 = V_114 + V_341 - 1 ;
V_2 [ V_101 ] . V_37 = V_341 ;
if ( V_112 -> V_374 >= V_116 )
V_116 = V_112 -> V_374 + 1 ;
F_49 ( V_93 L_90
L_91 , V_101 , F_1 ( V_101 ) ,
F_62 ( V_101 ) , F_2 ( V_101 ) ,
V_112 -> V_114 , V_112 -> V_374 ) ;
V_34 ++ ;
}
void T_1 F_298 ( void )
{
struct V_118 V_156 = { 0 , 0 , 0 , 0 } ;
F_49 ( V_93 L_92 ) ;
#ifndef F_195
F_299 ( V_216 ,
& V_204 ) ;
#endif
F_300 () ;
F_129 ( 0 , 0 , & V_156 ) ;
F_117 ( 0 , & V_146 , V_153 ,
L_18 ) ;
}
