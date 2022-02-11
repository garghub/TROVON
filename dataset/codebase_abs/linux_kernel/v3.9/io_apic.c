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
F_20 ( V_29 [ V_14 ] . V_39 ) ;
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
static int F_29 ( unsigned int V_49 , unsigned int V_30 , int V_26 )
{
return F_30 ( V_49 , V_30 , V_26 ) ;
}
static void F_31 ( unsigned int V_46 , struct V_28 * V_29 )
{
F_25 ( V_46 , V_29 ) ;
F_28 ( V_46 ) ;
}
void F_32 ( unsigned int V_50 , unsigned int V_41 )
{
struct V_51 T_2 * V_51 = F_33 ( V_50 ) ;
F_34 ( V_41 , & V_51 -> V_52 ) ;
}
unsigned int F_35 ( unsigned int V_50 , unsigned int V_53 )
{
struct V_51 T_2 * V_51 = F_33 ( V_50 ) ;
F_34 ( V_53 , & V_51 -> V_54 ) ;
return F_36 ( & V_51 -> V_55 ) ;
}
void F_37 ( unsigned int V_50 , unsigned int V_53 , unsigned int V_56 )
{
struct V_51 T_2 * V_51 = F_33 ( V_50 ) ;
F_34 ( V_53 , & V_51 -> V_54 ) ;
F_34 ( V_56 , & V_51 -> V_55 ) ;
}
void F_38 ( unsigned int V_50 , unsigned int V_53 , unsigned int V_56 )
{
struct V_51 T_2 * V_51 = F_33 ( V_50 ) ;
if ( V_57 )
F_34 ( V_53 , & V_51 -> V_54 ) ;
F_34 ( V_56 , & V_51 -> V_55 ) ;
}
static struct V_36 F_39 ( int V_50 , int V_58 )
{
union V_59 V_60 ;
V_60 . V_61 = F_40 ( V_50 , 0x10 + 2 * V_58 ) ;
V_60 . V_62 = F_40 ( V_50 , 0x11 + 2 * V_58 ) ;
return V_60 . V_63 ;
}
static struct V_36 F_41 ( int V_50 , int V_58 )
{
union V_59 V_60 ;
unsigned long V_64 ;
F_42 ( & V_65 , V_64 ) ;
V_60 . V_63 = F_39 ( V_50 , V_58 ) ;
F_43 ( & V_65 , V_64 ) ;
return V_60 . V_63 ;
}
static void F_44 ( int V_50 , int V_58 , struct V_36 V_66 )
{
union V_59 V_60 = { { 0 , 0 } } ;
V_60 . V_63 = V_66 ;
F_45 ( V_50 , 0x11 + 2 * V_58 , V_60 . V_62 ) ;
F_45 ( V_50 , 0x10 + 2 * V_58 , V_60 . V_61 ) ;
}
static void F_46 ( int V_50 , int V_58 , struct V_36 V_66 )
{
unsigned long V_64 ;
F_42 ( & V_65 , V_64 ) ;
F_44 ( V_50 , V_58 , V_66 ) ;
F_43 ( & V_65 , V_64 ) ;
}
static void F_47 ( int V_50 , int V_58 )
{
unsigned long V_64 ;
union V_59 V_60 = { . V_63 . V_67 = 1 } ;
F_42 ( & V_65 , V_64 ) ;
F_45 ( V_50 , 0x10 + 2 * V_58 , V_60 . V_61 ) ;
F_45 ( V_50 , 0x11 + 2 * V_58 , V_60 . V_62 ) ;
F_43 ( & V_65 , V_64 ) ;
}
static int F_48 ( struct V_28 * V_29 , int V_26 , int V_50 , int V_58 )
{
struct V_25 * * V_68 , * V_63 ;
V_68 = & V_29 -> V_69 ;
F_49 (entry, cfg->irq_2_pin) {
if ( V_63 -> V_50 == V_50 && V_63 -> V_58 == V_58 )
return 0 ;
V_68 = & V_63 -> V_70 ;
}
V_63 = F_10 ( V_26 ) ;
if ( ! V_63 ) {
F_14 ( L_5 ,
V_26 , V_50 , V_58 ) ;
return - V_71 ;
}
V_63 -> V_50 = V_50 ;
V_63 -> V_58 = V_58 ;
* V_68 = V_63 ;
return 0 ;
}
static void F_50 ( struct V_28 * V_29 , int V_26 , int V_50 , int V_58 )
{
if ( F_48 ( V_29 , V_26 , V_50 , V_58 ) )
F_9 ( L_6 ) ;
}
static void T_1 F_51 ( struct V_28 * V_29 , int V_26 ,
int V_72 , int V_73 ,
int V_74 , int V_75 )
{
struct V_25 * V_63 ;
F_49 (entry, cfg->irq_2_pin) {
if ( V_63 -> V_50 == V_72 && V_63 -> V_58 == V_73 ) {
V_63 -> V_50 = V_74 ;
V_63 -> V_58 = V_75 ;
return;
}
}
F_50 ( V_29 , V_26 , V_74 , V_75 ) ;
}
static void F_52 ( struct V_25 * V_63 ,
int V_76 , int V_77 ,
void (* F_53)( struct V_25 * V_63 ) )
{
unsigned int V_53 , V_58 ;
V_58 = V_63 -> V_58 ;
V_53 = F_40 ( V_63 -> V_50 , 0x10 + V_58 * 2 ) ;
V_53 &= V_76 ;
V_53 |= V_77 ;
F_54 ( V_63 -> V_50 , 0x10 + V_58 * 2 , V_53 ) ;
if ( F_53 )
F_53 ( V_63 ) ;
}
static void F_55 ( struct V_28 * V_29 ,
int V_76 , int V_77 ,
void (* F_53)( struct V_25 * V_63 ) )
{
struct V_25 * V_63 ;
F_49 (entry, cfg->irq_2_pin)
F_52 ( V_63 , V_76 , V_77 , F_53 ) ;
}
static void F_56 ( struct V_25 * V_63 )
{
struct V_51 T_2 * V_51 ;
V_51 = F_33 ( V_63 -> V_50 ) ;
F_36 ( & V_51 -> V_55 ) ;
}
static void F_57 ( struct V_28 * V_29 )
{
unsigned long V_64 ;
F_42 ( & V_65 , V_64 ) ;
F_55 ( V_29 , ~ 0 , V_78 , & F_56 ) ;
F_43 ( & V_65 , V_64 ) ;
}
static void F_58 ( struct V_79 * V_55 )
{
F_57 ( V_55 -> V_80 ) ;
}
static void F_59 ( struct V_28 * V_29 )
{
F_55 ( V_29 , ~ V_78 , 0 , NULL ) ;
}
static void F_60 ( struct V_28 * V_29 )
{
unsigned long V_64 ;
F_42 ( & V_65 , V_64 ) ;
F_59 ( V_29 ) ;
F_43 ( & V_65 , V_64 ) ;
}
static void F_61 ( struct V_79 * V_55 )
{
F_60 ( V_55 -> V_80 ) ;
}
void F_62 ( int V_50 , int V_58 , int V_41 )
{
if ( F_63 ( V_50 ) >= 0x20 ) {
F_32 ( V_50 , V_41 ) ;
} else {
struct V_36 V_63 , V_81 ;
V_63 = V_81 = F_39 ( V_50 , V_58 ) ;
V_81 . V_67 = 1 ;
V_81 . V_82 = V_83 ;
F_44 ( V_50 , V_58 , V_81 ) ;
F_44 ( V_50 , V_58 , V_63 ) ;
}
}
void F_64 ( unsigned int V_43 , struct V_28 * V_29 )
{
struct V_25 * V_63 ;
unsigned long V_64 ;
F_42 ( & V_65 , V_64 ) ;
F_49 (entry, cfg->irq_2_pin)
V_84 . V_85 ( V_63 -> V_50 , V_63 -> V_58 ,
V_29 -> V_41 ) ;
F_43 ( & V_65 , V_64 ) ;
}
static void F_65 ( unsigned int V_50 , unsigned int V_58 )
{
struct V_36 V_63 ;
V_63 = F_41 ( V_50 , V_58 ) ;
if ( V_63 . V_86 == V_87 )
return;
if ( ! V_63 . V_67 ) {
V_63 . V_67 = 1 ;
F_46 ( V_50 , V_58 , V_63 ) ;
V_63 = F_41 ( V_50 , V_58 ) ;
}
if ( V_63 . V_88 ) {
unsigned long V_64 ;
if ( ! V_63 . V_82 ) {
V_63 . V_82 = V_89 ;
F_46 ( V_50 , V_58 , V_63 ) ;
}
F_42 ( & V_65 , V_64 ) ;
V_84 . V_85 ( V_50 , V_58 , V_63 . V_41 ) ;
F_43 ( & V_65 , V_64 ) ;
}
F_47 ( V_50 , V_58 ) ;
V_63 = F_41 ( V_50 , V_58 ) ;
if ( V_63 . V_88 )
F_14 ( L_7 ,
F_1 ( V_50 ) , V_58 ) ;
}
static void F_66 ( void )
{
int V_50 , V_58 ;
for ( V_50 = 0 ; V_50 < V_34 ; V_50 ++ )
for ( V_58 = 0 ; V_58 < V_2 [ V_50 ] . V_37 ; V_58 ++ )
F_65 ( V_50 , V_58 ) ;
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
int V_50 , V_58 ;
int V_96 = 0 ;
for ( V_50 = 0 ; V_50 < V_34 ; V_50 ++ ) {
if ( ! V_2 [ V_50 ] . V_35 ) {
V_96 = - V_71 ;
continue;
}
for ( V_58 = 0 ; V_58 < V_2 [ V_50 ] . V_37 ; V_58 ++ )
V_2 [ V_50 ] . V_35 [ V_58 ] =
F_41 ( V_50 , V_58 ) ;
}
return V_96 ;
}
void F_70 ( void )
{
int V_50 , V_58 ;
for ( V_50 = 0 ; V_50 < V_34 ; V_50 ++ ) {
if ( ! V_2 [ V_50 ] . V_35 )
continue;
for ( V_58 = 0 ; V_58 < V_2 [ V_50 ] . V_37 ; V_58 ++ ) {
struct V_36 V_63 ;
V_63 = V_2 [ V_50 ] . V_35 [ V_58 ] ;
if ( ! V_63 . V_67 ) {
V_63 . V_67 = 1 ;
F_46 ( V_50 , V_58 , V_63 ) ;
}
}
}
}
int F_71 ( void )
{
int V_50 , V_58 ;
for ( V_50 = 0 ; V_50 < V_34 ; V_50 ++ ) {
if ( ! V_2 [ V_50 ] . V_35 )
continue;
for ( V_58 = 0 ; V_58 < V_2 [ V_50 ] . V_37 ; V_58 ++ )
F_46 ( V_50 , V_58 ,
V_2 [ V_50 ] . V_35 [ V_58 ] ) ;
}
return 0 ;
}
static int F_72 ( int V_1 , int V_58 , int type )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ )
if ( V_23 [ V_14 ] . V_16 == type &&
( V_23 [ V_14 ] . V_20 == F_1 ( V_1 ) ||
V_23 [ V_14 ] . V_20 == V_97 ) &&
V_23 [ V_14 ] . V_21 == V_58 )
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
F_81 ( L_11 ) ;
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
F_81 ( L_11 ) ;
V_103 = 1 ;
break;
}
}
return V_103 ;
}
static int F_82 ( int V_101 )
{
int V_102 = V_23 [ V_101 ] . V_18 ;
int V_82 ;
switch ( ( V_23 [ V_101 ] . V_17 >> 2 ) & 3 )
{
case 0 :
if ( F_74 ( V_102 , V_99 ) )
V_82 = F_83 ( V_101 ) ;
else
V_82 = F_84 ( V_101 ) ;
#ifdef F_85
switch ( V_104 [ V_102 ] ) {
case V_105 :
{
break;
}
case V_106 :
{
V_82 = F_86 ( V_101 ) ;
break;
}
case V_107 :
{
break;
}
default:
{
F_81 ( L_11 ) ;
V_82 = 1 ;
break;
}
}
#endif
break;
case 1 :
{
V_82 = 0 ;
break;
}
case 2 :
{
F_81 ( L_11 ) ;
V_82 = 1 ;
break;
}
case 3 :
{
V_82 = 1 ;
break;
}
default:
{
F_81 ( L_11 ) ;
V_82 = 0 ;
break;
}
}
return V_82 ;
}
static int F_87 ( int V_101 , int V_50 , int V_58 )
{
int V_43 ;
int V_102 = V_23 [ V_101 ] . V_18 ;
struct V_6 * V_108 = F_3 ( V_50 ) ;
if ( V_23 [ V_101 ] . V_21 != V_58 )
F_14 ( L_12 ) ;
if ( F_74 ( V_102 , V_99 ) ) {
V_43 = V_23 [ V_101 ] . V_19 ;
} else {
T_3 V_109 = V_108 -> V_110 + V_58 ;
if ( V_109 >= V_111 )
V_43 = V_109 ;
else
V_43 = V_112 + V_109 ;
}
#ifdef F_88
if ( ( V_58 >= 16 ) && ( V_58 <= 23 ) ) {
if ( V_95 [ V_58 - 16 ] != - 1 ) {
if ( ! V_95 [ V_58 - 16 ] ) {
F_8 ( V_15 , V_94
L_13 , V_58 - 16 ) ;
} else {
V_43 = V_95 [ V_58 - 16 ] ;
F_8 ( V_15 , V_94
L_14 ,
V_58 - 16 , V_43 ) ;
}
}
}
#endif
return V_43 ;
}
int F_89 ( int V_102 , int V_113 , int V_58 ,
struct V_114 * V_115 )
{
int V_1 , V_14 , V_116 = - 1 ;
F_8 ( V_117 ,
L_15 ,
V_102 , V_113 , V_58 ) ;
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
( V_113 == ( ( V_23 [ V_14 ] . V_19 >> 2 ) & 0x1f ) ) ) {
int V_43 = F_87 ( V_14 , V_1 , V_23 [ V_14 ] . V_21 ) ;
if ( ! ( V_1 || F_90 ( V_43 ) ) )
continue;
if ( V_58 == ( V_23 [ V_14 ] . V_19 & 3 ) ) {
F_91 ( V_115 , V_1 ,
V_23 [ V_14 ] . V_21 ,
F_82 ( V_14 ) ,
F_78 ( V_14 ) ) ;
return V_43 ;
}
if ( V_116 < 0 ) {
F_91 ( V_115 , V_1 ,
V_23 [ V_14 ] . V_21 ,
F_82 ( V_14 ) ,
F_78 ( V_14 ) ) ;
V_116 = V_43 ;
}
}
}
return V_116 ;
}
void F_92 ( void )
{
F_93 ( & V_118 ) ;
}
void F_94 ( void )
{
F_95 ( & V_118 ) ;
}
static int
F_96 ( int V_43 , struct V_28 * V_29 , const struct V_119 * V_67 )
{
static int V_120 = V_121 + V_122 ;
static int V_123 = V_122 % 16 ;
int V_124 , V_96 ;
T_4 V_125 ;
if ( V_29 -> V_126 )
return - V_127 ;
if ( ! F_97 ( & V_125 , V_128 ) )
return - V_71 ;
V_96 = - V_129 ;
F_98 ( V_29 -> V_40 ) ;
V_124 = F_99 ( V_67 , V_130 ) ;
while ( V_124 < V_131 ) {
int V_132 , V_41 , V_133 ;
V_50 -> V_134 ( V_124 , V_125 , V_67 ) ;
if ( F_100 ( V_125 , V_29 -> V_39 ) ) {
V_96 = 0 ;
if ( F_101 ( V_125 , V_29 -> V_39 ) )
break;
F_102 ( V_29 -> V_40 , V_29 -> V_39 , V_125 ) ;
V_29 -> V_126 =
F_103 ( V_29 -> V_40 , V_130 ) ;
F_104 ( V_29 -> V_39 , V_29 -> V_39 , V_125 ) ;
break;
}
V_41 = V_120 ;
V_133 = V_123 ;
V_70:
V_41 += 16 ;
if ( V_41 >= V_135 ) {
V_133 = ( V_133 + 1 ) % 16 ;
V_41 = V_121 + V_133 ;
}
if ( F_105 ( V_120 == V_41 ) ) {
F_106 ( V_29 -> V_40 , V_29 -> V_40 , V_125 ) ;
F_102 ( V_125 , V_67 , V_29 -> V_40 ) ;
V_124 = F_99 ( V_125 , V_130 ) ;
continue;
}
if ( F_74 ( V_41 , V_136 ) )
goto V_70;
F_107 (new_cpu, tmp_mask, cpu_online_mask)
if ( F_108 ( V_137 , V_132 ) [ V_41 ] != - 1 )
goto V_70;
V_120 = V_41 ;
V_123 = V_133 ;
if ( V_29 -> V_41 ) {
F_109 ( V_29 -> V_40 , V_29 -> V_39 ) ;
V_29 -> V_126 =
F_103 ( V_29 -> V_40 , V_130 ) ;
}
F_107 (new_cpu, tmp_mask, cpu_online_mask)
F_108 ( V_137 , V_132 ) [ V_41 ] = V_43 ;
V_29 -> V_41 = V_41 ;
F_109 ( V_29 -> V_39 , V_125 ) ;
V_96 = 0 ;
break;
}
F_23 ( V_125 ) ;
return V_96 ;
}
int F_110 ( int V_43 , struct V_28 * V_29 , const struct V_119 * V_67 )
{
int V_96 ;
unsigned long V_64 ;
F_42 ( & V_118 , V_64 ) ;
V_96 = F_96 ( V_43 , V_29 , V_67 ) ;
F_43 ( & V_118 , V_64 ) ;
return V_96 ;
}
static void F_111 ( int V_43 , struct V_28 * V_29 )
{
int V_124 , V_41 ;
F_112 ( ! V_29 -> V_41 ) ;
V_41 = V_29 -> V_41 ;
F_107 (cpu, cfg->domain, cpu_online_mask)
F_108 ( V_137 , V_124 ) [ V_41 ] = - 1 ;
V_29 -> V_41 = 0 ;
F_98 ( V_29 -> V_39 ) ;
if ( F_113 ( ! V_29 -> V_126 ) )
return;
F_107 (cpu, cfg->old_domain, cpu_online_mask) {
for ( V_41 = V_121 ; V_41 < V_138 ;
V_41 ++ ) {
if ( F_108 ( V_137 , V_124 ) [ V_41 ] != V_43 )
continue;
F_108 ( V_137 , V_124 ) [ V_41 ] = - 1 ;
break;
}
}
V_29 -> V_126 = 0 ;
}
void F_114 ( int V_124 )
{
int V_43 , V_41 ;
struct V_28 * V_29 ;
F_93 ( & V_118 ) ;
F_115 (irq) {
V_29 = F_21 ( V_43 ) ;
if ( ! V_29 )
continue;
if ( ! F_116 ( V_124 , V_29 -> V_39 ) )
continue;
V_41 = V_29 -> V_41 ;
F_108 ( V_137 , V_124 ) [ V_41 ] = V_43 ;
}
for ( V_41 = 0 ; V_41 < V_138 ; ++ V_41 ) {
V_43 = F_108 ( V_137 , V_124 ) [ V_41 ] ;
if ( V_43 < 0 )
continue;
V_29 = V_28 ( V_43 ) ;
if ( ! F_116 ( V_124 , V_29 -> V_39 ) )
F_108 ( V_137 , V_124 ) [ V_41 ] = - 1 ;
}
F_95 ( & V_118 ) ;
}
static inline int F_117 ( int V_43 )
{
int V_50 , V_101 , V_58 ;
for ( V_50 = 0 ; V_50 < V_34 ; V_50 ++ ) {
for ( V_58 = 0 ; V_58 < V_2 [ V_50 ] . V_37 ; V_58 ++ ) {
V_101 = F_72 ( V_50 , V_58 , V_139 ) ;
if ( ( V_101 != - 1 ) && ( V_43 == F_87 ( V_101 , V_50 , V_58 ) ) )
return F_82 ( V_101 ) ;
}
}
return 0 ;
}
static inline int F_117 ( int V_43 )
{
return 1 ;
}
static void F_118 ( unsigned int V_43 , struct V_28 * V_29 ,
unsigned long V_82 )
{
struct V_140 * V_141 = & V_142 ;
T_5 V_143 ;
bool V_144 ;
if ( ( V_82 == V_145 && F_117 ( V_43 ) ) ||
V_82 == V_89 ) {
F_119 ( V_43 , V_146 ) ;
V_144 = true ;
} else {
F_120 ( V_43 , V_146 ) ;
V_144 = false ;
}
if ( F_121 ( V_43 , V_29 , V_141 ) )
V_144 = V_82 != 0 ;
V_143 = V_144 ? V_147 : V_148 ;
F_122 ( V_43 , V_141 , V_143 ,
V_144 ? L_17 : L_18 ) ;
}
int F_123 ( int V_43 , struct V_36 * V_63 ,
unsigned int V_149 , int V_41 ,
struct V_114 * V_150 )
{
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_86 = V_50 -> V_151 ;
V_63 -> V_152 = V_50 -> V_153 ;
V_63 -> V_154 = V_149 ;
V_63 -> V_41 = V_41 ;
V_63 -> V_67 = 0 ;
V_63 -> V_82 = V_150 -> V_82 ;
V_63 -> V_103 = V_150 -> V_103 ;
if ( V_150 -> V_82 )
V_63 -> V_67 = 1 ;
return 0 ;
}
static void F_124 ( unsigned int V_43 , struct V_28 * V_29 ,
struct V_114 * V_150 )
{
struct V_36 V_63 ;
unsigned int V_154 ;
if ( ! F_90 ( V_43 ) )
return;
if ( F_110 ( V_43 , V_29 , V_50 -> V_155 () ) )
return;
if ( V_50 -> V_156 ( V_29 -> V_39 , V_50 -> V_155 () ,
& V_154 ) ) {
F_81 ( L_19 ,
F_1 ( V_150 -> V_157 ) , V_150 -> V_158 ) ;
F_111 ( V_43 , V_29 ) ;
return;
}
F_8 ( V_15 , V_94
L_20
L_21 ,
V_150 -> V_157 , F_1 ( V_150 -> V_157 ) , V_150 -> V_158 ,
V_29 -> V_41 , V_43 , V_150 -> V_82 , V_150 -> V_103 , V_154 ) ;
if ( V_84 . V_159 ( V_43 , & V_63 , V_154 , V_29 -> V_41 , V_150 ) ) {
F_81 ( L_22 ,
F_1 ( V_150 -> V_157 ) , V_150 -> V_158 ) ;
F_111 ( V_43 , V_29 ) ;
return;
}
F_118 ( V_43 , V_29 , V_150 -> V_82 ) ;
if ( V_43 < V_31 -> V_32 )
V_31 -> V_67 ( V_43 ) ;
F_46 ( V_150 -> V_157 , V_150 -> V_158 , V_63 ) ;
}
static bool T_1 F_125 ( int V_101 , int V_1 , int V_58 )
{
if ( V_101 != - 1 )
return false ;
F_8 ( V_15 , V_94 L_23 ,
F_1 ( V_1 ) , V_58 ) ;
return true ;
}
static void T_1 F_126 ( unsigned int V_1 )
{
int V_101 , V_26 = F_16 ( 0 ) ;
struct V_114 V_150 ;
unsigned int V_58 , V_43 ;
for ( V_58 = 0 ; V_58 < V_2 [ V_1 ] . V_37 ; V_58 ++ ) {
V_101 = F_72 ( V_1 , V_58 , V_139 ) ;
if ( F_125 ( V_101 , V_1 , V_58 ) )
continue;
V_43 = F_87 ( V_101 , V_1 , V_58 ) ;
if ( ( V_1 > 0 ) && ( V_43 > 16 ) )
continue;
if ( V_50 -> V_160 &&
V_50 -> V_160 ( V_1 , V_43 ) )
continue;
F_91 ( & V_150 , V_1 , V_58 , F_82 ( V_101 ) ,
F_78 ( V_101 ) ) ;
F_127 ( V_43 , V_26 , & V_150 ) ;
}
}
static void T_1 F_128 ( void )
{
unsigned int V_1 ;
F_8 ( V_15 , V_94 L_24 ) ;
for ( V_1 = 0 ; V_1 < V_34 ; V_1 ++ )
F_126 ( V_1 ) ;
}
void F_129 ( T_3 V_109 )
{
int V_1 = 0 , V_58 , V_101 , V_43 , V_26 = F_16 ( 0 ) ;
struct V_114 V_150 ;
V_1 = F_130 ( V_109 ) ;
if ( V_1 < 0 )
return;
V_58 = F_131 ( V_1 , V_109 ) ;
V_101 = F_72 ( V_1 , V_58 , V_139 ) ;
if ( V_101 == - 1 )
return;
V_43 = F_87 ( V_101 , V_1 , V_58 ) ;
if ( V_1 == 0 || V_43 < V_111 )
return;
F_91 ( & V_150 , V_1 , V_58 , F_82 ( V_101 ) ,
F_78 ( V_101 ) ) ;
F_132 ( V_43 , V_26 , & V_150 ) ;
}
static void T_1 F_133 ( unsigned int V_1 ,
unsigned int V_58 , int V_41 )
{
struct V_36 V_63 ;
unsigned int V_154 ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
if ( F_105 ( V_50 -> V_156 ( V_50 -> V_155 () ,
V_50 -> V_155 () , & V_154 ) ) )
V_154 = V_161 ;
V_63 . V_152 = V_50 -> V_153 ;
V_63 . V_67 = 0 ;
V_63 . V_154 = V_154 ;
V_63 . V_86 = V_50 -> V_151 ;
V_63 . V_103 = 0 ;
V_63 . V_82 = 0 ;
V_63 . V_41 = V_41 ;
F_122 ( 0 , & V_142 , V_148 ,
L_18 ) ;
F_46 ( V_1 , V_58 , V_63 ) ;
}
void F_134 ( unsigned int V_50 , unsigned int V_162 )
{
int V_14 ;
F_135 ( L_25 ) ;
for ( V_14 = 0 ; V_14 <= V_162 ; V_14 ++ ) {
struct V_36 V_63 ;
V_63 = F_41 ( V_50 , V_14 ) ;
F_135 ( L_26 , V_14 , V_63 . V_154 ) ;
F_136 ( L_27
L_28 ,
V_63 . V_67 ,
V_63 . V_82 ,
V_63 . V_88 ,
V_63 . V_103 ,
V_63 . V_163 ,
V_63 . V_152 ,
V_63 . V_86 ,
V_63 . V_41 ) ;
}
}
void F_137 ( unsigned int V_50 ,
unsigned int V_162 )
{
int V_14 ;
F_135 ( L_29 ) ;
for ( V_14 = 0 ; V_14 <= V_162 ; V_14 ++ ) {
struct V_164 * V_165 ;
struct V_36 V_63 ;
V_63 = F_41 ( V_50 , V_14 ) ;
V_165 = (struct V_164 * ) & V_63 ;
F_135 ( L_30 , V_14 , V_165 -> V_54 ) ;
F_136 ( L_31
L_32 ,
V_165 -> V_166 ,
V_165 -> V_67 ,
V_165 -> V_82 ,
V_165 -> V_88 ,
V_165 -> V_103 ,
V_165 -> V_163 ,
V_165 -> V_167 ,
V_165 -> V_168 ,
V_165 -> V_41 ) ;
}
}
static T_1 int F_138 ( char * V_169 )
{
int V_170 = - 1 ;
if ( strcmp ( V_169 , L_33 ) == 0 ) {
V_171 = V_172 ;
} else {
F_139 ( & V_169 , & V_170 ) ;
if ( V_170 >= 0 )
V_171 = V_170 ;
}
return 1 ;
}
void T_1 F_140 ( void )
{
int V_173 , V_174 ;
int V_50 ;
if ( ! V_31 -> V_32 )
return;
for( V_50 = 0 ; V_50 < V_34 ; V_50 ++ ) {
int V_58 ;
for ( V_58 = 0 ; V_58 < V_2 [ V_50 ] . V_37 ; V_58 ++ ) {
struct V_36 V_63 ;
V_63 = F_41 ( V_50 , V_58 ) ;
if ( ( V_63 . V_67 == 0 ) && ( V_63 . V_86 == V_175 ) ) {
V_176 . V_50 = V_50 ;
V_176 . V_58 = V_58 ;
goto V_177;
}
}
}
V_177:
V_174 = F_73 ( 0 , V_178 ) ;
V_173 = F_75 ( 0 , V_178 ) ;
if ( ( V_176 . V_58 == - 1 ) && ( V_174 >= 0 ) ) {
F_141 ( V_179 L_34 ) ;
V_176 . V_58 = V_174 ;
V_176 . V_50 = V_173 ;
}
if ( ( ( V_176 . V_50 != V_173 ) || ( V_176 . V_58 != V_174 ) ) &&
( V_174 >= 0 ) && ( V_176 . V_58 >= 0 ) )
{
F_141 ( V_179 L_35 ) ;
}
F_66 () ;
}
void F_142 ( void )
{
if ( V_176 . V_58 != - 1 ) {
struct V_36 V_63 ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_63 . V_67 = 0 ;
V_63 . V_82 = 0 ;
V_63 . V_88 = 0 ;
V_63 . V_103 = 0 ;
V_63 . V_163 = 0 ;
V_63 . V_152 = 0 ;
V_63 . V_86 = V_175 ;
V_63 . V_41 = 0 ;
V_63 . V_154 = F_143 () ;
F_46 ( V_176 . V_50 , V_176 . V_58 , V_63 ) ;
}
if ( V_180 || F_144 () )
F_145 ( V_176 . V_58 != - 1 ) ;
}
void F_146 ( void )
{
F_66 () ;
if ( ! V_31 -> V_32 )
return;
V_84 . V_181 () ;
}
void T_1 F_147 ( void )
{
union V_182 V_183 ;
T_6 V_184 ;
int V_1 ;
int V_14 ;
unsigned char V_185 ;
unsigned long V_64 ;
V_50 -> V_186 ( & V_187 , & V_184 ) ;
for ( V_1 = 0 ; V_1 < V_34 ; V_1 ++ ) {
F_42 ( & V_65 , V_64 ) ;
V_183 . V_188 = F_40 ( V_1 , 0 ) ;
F_43 ( & V_65 , V_64 ) ;
V_185 = F_1 ( V_1 ) ;
if ( F_1 ( V_1 ) >= F_148 () ) {
F_141 ( V_189 L_36 ,
V_1 , F_1 ( V_1 ) ) ;
F_141 ( V_189 L_37 ,
V_183 . V_190 . V_191 ) ;
V_2 [ V_1 ] . V_3 . V_4 = V_183 . V_190 . V_191 ;
}
if ( V_50 -> V_192 ( & V_184 ,
F_1 ( V_1 ) ) ) {
F_141 ( V_189 L_38 ,
V_1 , F_1 ( V_1 ) ) ;
for ( V_14 = 0 ; V_14 < F_148 () ; V_14 ++ )
if ( ! F_149 ( V_14 , V_184 ) )
break;
if ( V_14 >= F_148 () )
F_9 ( L_39 ) ;
F_141 ( V_189 L_37 ,
V_14 ) ;
F_150 ( V_14 , V_184 ) ;
V_2 [ V_1 ] . V_3 . V_4 = V_14 ;
} else {
T_6 V_193 ;
V_50 -> V_194 ( F_1 ( V_1 ) ,
& V_193 ) ;
F_8 ( V_15 , L_40
L_41 ,
F_1 ( V_1 ) ) ;
F_151 ( V_184 , V_184 , V_193 ) ;
}
if ( V_185 != F_1 ( V_1 ) )
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ )
if ( V_23 [ V_14 ] . V_20 == V_185 )
V_23 [ V_14 ] . V_20
= F_1 ( V_1 ) ;
if ( F_1 ( V_1 ) == V_183 . V_190 . V_191 )
continue;
F_8 ( V_15 , V_93
L_42 ,
F_1 ( V_1 ) ) ;
V_183 . V_190 . V_191 = F_1 ( V_1 ) ;
F_42 ( & V_65 , V_64 ) ;
F_45 ( V_1 , 0 , V_183 . V_188 ) ;
F_43 ( & V_65 , V_64 ) ;
F_42 ( & V_65 , V_64 ) ;
V_183 . V_188 = F_40 ( V_1 , 0 ) ;
F_43 ( & V_65 , V_64 ) ;
if ( V_183 . V_190 . V_191 != F_1 ( V_1 ) )
F_136 ( L_43 ) ;
else
F_8 ( V_15 , L_44 ) ;
}
}
void T_1 F_152 ( void )
{
if ( V_195 )
return;
if ( ! ( V_196 . V_197 == V_198 )
|| F_153 ( V_199 [ V_200 ] ) )
return;
F_147 () ;
}
static int T_1 F_154 ( char * V_201 )
{
V_202 = 1 ;
return 1 ;
}
static int T_1 F_155 ( void )
{
unsigned long V_203 = V_204 ;
unsigned long V_64 ;
if ( V_202 )
return 1 ;
F_156 ( V_64 ) ;
F_157 () ;
F_158 ( ( 10 * 1000 ) / V_205 ) ;
F_159 ( V_64 ) ;
if ( F_160 ( V_204 , V_203 + 4 ) )
return 1 ;
return 0 ;
}
static unsigned int F_161 ( struct V_79 * V_55 )
{
int V_206 = 0 , V_43 = V_55 -> V_43 ;
unsigned long V_64 ;
F_42 ( & V_65 , V_64 ) ;
if ( V_43 < V_31 -> V_32 ) {
V_31 -> V_67 ( V_43 ) ;
if ( V_31 -> V_207 ( V_43 ) )
V_206 = 1 ;
}
F_59 ( V_55 -> V_80 ) ;
F_43 ( & V_65 , V_64 ) ;
return V_206 ;
}
static int F_162 ( struct V_79 * V_55 )
{
struct V_28 * V_29 = V_55 -> V_80 ;
unsigned long V_64 ;
int V_124 ;
F_42 ( & V_118 , V_64 ) ;
V_124 = F_99 ( V_29 -> V_39 , V_130 ) ;
V_50 -> V_208 ( F_163 ( V_124 ) , V_29 -> V_41 ) ;
F_43 ( & V_118 , V_64 ) ;
return 1 ;
}
void F_164 ( struct V_28 * V_29 )
{
T_4 V_209 ;
if ( F_105 ( ! F_97 ( & V_209 , V_128 ) ) ) {
unsigned int V_14 ;
F_107 (i, cfg->old_domain, cpu_online_mask)
V_50 -> V_208 ( F_163 ( V_14 ) , V_210 ) ;
} else {
F_104 ( V_209 , V_29 -> V_40 , V_130 ) ;
V_50 -> V_208 ( V_209 , V_210 ) ;
F_23 ( V_209 ) ;
}
V_29 -> V_126 = 0 ;
}
T_7 void F_165 ( void )
{
unsigned V_41 , V_211 ;
F_166 () ;
F_167 () ;
F_168 () ;
V_211 = F_169 () ;
for ( V_41 = V_121 ; V_41 < V_138 ; V_41 ++ ) {
unsigned int V_43 ;
unsigned int V_88 ;
struct V_212 * V_213 ;
struct V_28 * V_29 ;
V_43 = F_170 ( V_137 [ V_41 ] ) ;
if ( V_43 == - 1 )
continue;
V_213 = F_171 ( V_43 ) ;
if ( ! V_213 )
continue;
V_29 = V_28 ( V_43 ) ;
if ( ! V_29 )
continue;
F_93 ( & V_213 -> V_214 ) ;
if ( V_29 -> V_126 )
goto V_215;
if ( V_41 == V_29 -> V_41 && F_116 ( V_211 , V_29 -> V_39 ) )
goto V_215;
V_88 = F_172 ( V_216 + ( V_41 / 32 * 0x10 ) ) ;
if ( V_88 & ( 1 << ( V_41 % 32 ) ) ) {
V_50 -> V_217 ( V_210 ) ;
goto V_215;
}
F_173 ( V_137 [ V_41 ] , - 1 ) ;
V_215:
F_95 ( & V_213 -> V_214 ) ;
}
F_174 () ;
}
static void F_175 ( struct V_28 * V_29 , unsigned V_41 )
{
unsigned V_211 ;
if ( F_113 ( ! V_29 -> V_126 ) )
return;
V_211 = F_169 () ;
if ( V_41 == V_29 -> V_41 && F_116 ( V_211 , V_29 -> V_39 ) )
F_164 ( V_29 ) ;
}
static void F_176 ( struct V_28 * V_29 )
{
F_175 ( V_29 , ~ F_177 () -> V_218 ) ;
}
void F_178 ( int V_43 )
{
struct V_28 * V_29 = F_21 ( V_43 ) ;
if ( ! V_29 )
return;
F_175 ( V_29 , V_29 -> V_41 ) ;
}
static inline void F_176 ( struct V_28 * V_29 ) { }
static void F_179 ( unsigned int V_43 , unsigned int V_154 , struct V_28 * V_29 )
{
int V_50 , V_58 ;
struct V_25 * V_63 ;
T_8 V_41 = V_29 -> V_41 ;
F_49 (entry, cfg->irq_2_pin) {
unsigned int V_53 ;
V_50 = V_63 -> V_50 ;
V_58 = V_63 -> V_58 ;
F_45 ( V_50 , 0x11 + V_58 * 2 , V_154 ) ;
V_53 = F_40 ( V_50 , 0x10 + V_58 * 2 ) ;
V_53 &= ~ V_219 ;
V_53 |= V_41 ;
F_54 ( V_50 , 0x10 + V_58 * 2 , V_53 ) ;
}
}
int F_180 ( struct V_79 * V_55 , const struct V_119 * V_67 ,
unsigned int * V_220 )
{
struct V_28 * V_29 = V_55 -> V_80 ;
unsigned int V_43 = V_55 -> V_43 ;
int V_96 ;
if ( ! F_181 ( V_221 ) )
return - 1 ;
if ( ! F_103 ( V_67 , V_130 ) )
return - V_222 ;
V_96 = F_110 ( V_43 , V_29 , V_67 ) ;
if ( V_96 )
return V_96 ;
V_96 = V_50 -> V_156 ( V_67 , V_29 -> V_39 , V_220 ) ;
if ( V_96 ) {
if ( F_110 ( V_43 , V_29 , V_55 -> V_223 ) )
F_14 ( L_45 , V_43 ) ;
return V_96 ;
}
F_109 ( V_55 -> V_223 , V_67 ) ;
return 0 ;
}
int F_182 ( struct V_79 * V_55 ,
const struct V_119 * V_67 ,
bool V_224 )
{
unsigned int V_154 , V_43 = V_55 -> V_43 ;
unsigned long V_64 ;
int V_225 ;
if ( ! F_181 ( V_221 ) )
return - 1 ;
F_42 ( & V_65 , V_64 ) ;
V_225 = F_180 ( V_55 , V_67 , & V_154 ) ;
if ( ! V_225 ) {
V_154 = F_183 ( V_154 ) ;
F_179 ( V_43 , V_154 , V_55 -> V_80 ) ;
V_225 = V_226 ;
}
F_43 ( & V_65 , V_64 ) ;
return V_225 ;
}
static void F_184 ( struct V_79 * V_55 )
{
F_176 ( V_55 -> V_80 ) ;
F_185 ( V_55 ) ;
F_166 () ;
}
static bool F_186 ( struct V_28 * V_29 )
{
struct V_25 * V_63 ;
unsigned long V_64 ;
F_42 ( & V_65 , V_64 ) ;
F_49 (entry, cfg->irq_2_pin) {
unsigned int V_53 ;
int V_58 ;
V_58 = V_63 -> V_58 ;
V_53 = F_40 ( V_63 -> V_50 , 0x10 + V_58 * 2 ) ;
if ( V_53 & V_227 ) {
F_43 ( & V_65 , V_64 ) ;
return true ;
}
}
F_43 ( & V_65 , V_64 ) ;
return false ;
}
static inline bool F_187 ( struct V_79 * V_55 , struct V_28 * V_29 )
{
if ( F_105 ( F_188 ( V_55 ) ) ) {
F_57 ( V_29 ) ;
return true ;
}
return false ;
}
static inline void F_189 ( struct V_79 * V_55 ,
struct V_28 * V_29 , bool V_228 )
{
if ( F_105 ( V_228 ) ) {
if ( ! F_186 ( V_29 ) )
F_190 ( V_55 ) ;
F_60 ( V_29 ) ;
}
}
static inline bool F_187 ( struct V_79 * V_55 , struct V_28 * V_29 )
{
return false ;
}
static inline void F_189 ( struct V_79 * V_55 ,
struct V_28 * V_29 , bool V_228 )
{
}
static void F_191 ( struct V_79 * V_55 )
{
struct V_28 * V_29 = V_55 -> V_80 ;
int V_14 , V_43 = V_55 -> V_43 ;
unsigned long V_229 ;
bool V_228 ;
F_176 ( V_29 ) ;
V_228 = F_187 ( V_55 , V_29 ) ;
V_14 = V_29 -> V_41 ;
V_229 = F_172 ( V_230 + ( ( V_14 & ~ 0x1f ) >> 1 ) ) ;
F_166 () ;
if ( ! ( V_229 & ( 1 << ( V_14 & 0x1f ) ) ) ) {
F_192 ( & V_231 ) ;
F_64 ( V_43 , V_29 ) ;
}
F_189 ( V_55 , V_29 , V_228 ) ;
}
static inline void F_193 ( void )
{
struct V_28 * V_29 ;
unsigned int V_43 ;
F_115 (irq) {
V_29 = F_21 ( V_43 ) ;
if ( F_90 ( V_43 ) && V_29 && ! V_29 -> V_41 ) {
if ( V_43 < V_31 -> V_32 )
V_31 -> V_232 ( V_43 ) ;
else
F_194 ( V_43 , & V_233 ) ;
}
}
}
static void F_195 ( struct V_79 * V_55 )
{
unsigned long V_229 ;
V_229 = F_172 ( V_234 ) ;
F_196 ( V_234 , V_229 | V_235 ) ;
}
static void F_197 ( struct V_79 * V_55 )
{
unsigned long V_229 ;
V_229 = F_172 ( V_234 ) ;
F_196 ( V_234 , V_229 & ~ V_235 ) ;
}
static void F_198 ( struct V_79 * V_55 )
{
F_166 () ;
}
static void F_199 ( int V_43 )
{
F_120 ( V_43 , V_146 ) ;
F_122 ( V_43 , & V_236 , V_148 ,
L_18 ) ;
}
static inline void T_1 F_200 ( void )
{
int V_50 , V_58 , V_14 ;
struct V_36 V_237 , V_81 ;
unsigned char V_238 , V_239 ;
V_58 = F_73 ( 8 , V_139 ) ;
if ( V_58 == - 1 ) {
F_201 ( 1 ) ;
return;
}
V_50 = F_75 ( 8 , V_139 ) ;
if ( V_50 == - 1 ) {
F_201 ( 1 ) ;
return;
}
V_237 = F_41 ( V_50 , V_58 ) ;
F_65 ( V_50 , V_58 ) ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . V_152 = 0 ;
V_81 . V_67 = 0 ;
V_81 . V_154 = F_202 () ;
V_81 . V_86 = V_175 ;
V_81 . V_103 = V_237 . V_103 ;
V_81 . V_82 = 0 ;
V_81 . V_41 = 0 ;
F_46 ( V_50 , V_58 , V_81 ) ;
V_238 = F_203 ( V_240 ) ;
V_239 = F_203 ( V_241 ) ;
F_204 ( ( V_239 & ~ V_242 ) | 0x6 ,
V_241 ) ;
F_204 ( V_238 | V_243 , V_240 ) ;
V_14 = 100 ;
while ( V_14 -- > 0 ) {
F_158 ( 10 ) ;
if ( ( F_203 ( V_244 ) & V_245 ) == V_245 )
V_14 -= 10 ;
}
F_204 ( V_238 , V_240 ) ;
F_204 ( V_239 , V_241 ) ;
F_65 ( V_50 , V_58 ) ;
F_46 ( V_50 , V_58 , V_237 ) ;
}
static int T_1 F_205 ( char * V_169 )
{
V_246 = 1 ;
return 0 ;
}
static inline void T_1 F_206 ( void )
{
struct V_28 * V_29 = F_21 ( 0 ) ;
int V_26 = F_16 ( 0 ) ;
int V_247 , V_248 , V_249 , V_250 ;
unsigned long V_64 ;
int V_251 = 0 ;
F_207 ( V_64 ) ;
V_31 -> V_67 ( 0 ) ;
F_110 ( 0 , V_29 , V_50 -> V_155 () ) ;
F_196 ( V_234 , V_235 | V_252 ) ;
V_31 -> V_253 ( 1 ) ;
V_248 = F_73 ( 0 , V_139 ) ;
V_247 = F_75 ( 0 , V_139 ) ;
V_250 = V_176 . V_58 ;
V_249 = V_176 . V_50 ;
F_8 ( V_254 , V_93 L_46
L_47 ,
V_29 -> V_41 , V_247 , V_248 , V_249 , V_250 ) ;
if ( V_248 == - 1 ) {
F_208 ( L_48 ) ;
V_248 = V_250 ;
V_247 = V_249 ;
V_251 = 1 ;
} else if ( V_250 == - 1 ) {
V_250 = V_248 ;
V_249 = V_247 ;
}
if ( V_248 != - 1 ) {
if ( V_251 ) {
F_50 ( V_29 , V_26 , V_247 , V_248 ) ;
F_133 ( V_247 , V_248 , V_29 -> V_41 ) ;
} else {
int V_101 ;
V_101 = F_72 ( V_247 , V_248 , V_139 ) ;
if ( V_101 != - 1 && F_82 ( V_101 ) )
F_60 ( V_29 ) ;
}
if ( F_155 () ) {
if ( V_246 > 0 )
F_65 ( 0 , V_248 ) ;
goto V_255;
}
F_208 ( L_49 ) ;
F_209 () ;
F_65 ( V_247 , V_248 ) ;
if ( ! V_251 )
F_8 ( V_254 , V_189 L_50
L_51 ) ;
F_8 ( V_254 , V_93 L_52
L_53 ) ;
F_8 ( V_254 , V_93
L_54 , V_249 , V_250 ) ;
F_51 ( V_29 , V_26 , V_247 , V_248 , V_249 , V_250 ) ;
F_133 ( V_249 , V_250 , V_29 -> V_41 ) ;
V_31 -> V_256 ( 0 ) ;
if ( F_155 () ) {
F_8 ( V_254 , V_93 L_55 ) ;
V_257 = 1 ;
goto V_255;
}
F_209 () ;
V_31 -> V_67 ( 0 ) ;
F_65 ( V_249 , V_250 ) ;
F_8 ( V_254 , V_93 L_56 ) ;
}
F_8 ( V_254 , V_93
L_57 ) ;
F_199 ( 0 ) ;
F_196 ( V_234 , V_258 | V_29 -> V_41 ) ;
V_31 -> V_256 ( 0 ) ;
if ( F_155 () ) {
F_8 ( V_254 , V_93 L_58 ) ;
goto V_255;
}
F_209 () ;
V_31 -> V_67 ( 0 ) ;
F_196 ( V_234 , V_235 | V_258 | V_29 -> V_41 ) ;
F_8 ( V_254 , V_93 L_59 ) ;
F_8 ( V_254 , V_93
L_60 ) ;
V_31 -> V_253 ( 0 ) ;
V_31 -> V_232 ( 0 ) ;
F_196 ( V_234 , V_252 ) ;
F_200 () ;
if ( F_155 () ) {
F_8 ( V_254 , V_93 L_58 ) ;
goto V_255;
}
F_209 () ;
F_8 ( V_254 , V_93 L_61 ) ;
if ( V_259 )
F_8 ( V_254 , V_93
L_62
L_63 ) ;
F_9 ( L_64
L_65 ) ;
V_255:
F_159 ( V_64 ) ;
}
void T_1 F_210 ( void )
{
V_33 = V_31 -> V_32 ? ~ V_260 : ~ 0UL ;
F_8 ( V_15 , L_66 ) ;
V_261 . V_262 . V_263 () ;
F_211 () ;
F_128 () ;
F_193 () ;
if ( V_31 -> V_32 )
F_206 () ;
}
static int T_1 F_212 ( void )
{
if ( V_57 == - 1 )
V_57 = 0 ;
return 0 ;
}
static void F_213 ( int V_1 )
{
unsigned long V_64 ;
union V_182 V_183 ;
F_42 ( & V_65 , V_64 ) ;
V_183 . V_188 = F_40 ( V_1 , 0 ) ;
if ( V_183 . V_190 . V_191 != F_1 ( V_1 ) ) {
V_183 . V_190 . V_191 = F_1 ( V_1 ) ;
F_45 ( V_1 , 0 , V_183 . V_188 ) ;
}
F_43 ( & V_65 , V_64 ) ;
}
static void F_214 ( void )
{
int V_1 ;
for ( V_1 = V_34 - 1 ; V_1 >= 0 ; V_1 -- )
F_213 ( V_1 ) ;
F_71 () ;
}
static int T_1 F_215 ( void )
{
F_216 ( & V_264 ) ;
return 0 ;
}
unsigned int F_217 ( unsigned int V_49 , unsigned int V_30 , int V_26 )
{
struct V_28 * * V_29 ;
unsigned long V_64 ;
int V_43 , V_14 ;
if ( V_49 < V_265 )
V_49 = V_265 ;
V_29 = F_11 ( V_30 * sizeof( V_29 [ 0 ] ) , V_27 , V_26 ) ;
if ( ! V_29 )
return 0 ;
V_43 = F_29 ( V_49 , V_30 , V_26 ) ;
if ( V_43 < 0 )
goto V_266;
for ( V_14 = 0 ; V_14 < V_30 ; V_14 ++ ) {
V_29 [ V_14 ] = F_22 ( V_43 + V_14 , V_26 ) ;
if ( ! V_29 [ V_14 ] )
goto V_267;
}
F_42 ( & V_118 , V_64 ) ;
for ( V_14 = 0 ; V_14 < V_30 ; V_14 ++ )
if ( F_96 ( V_43 + V_14 , V_29 [ V_14 ] , V_50 -> V_155 () ) )
goto V_268;
F_43 ( & V_118 , V_64 ) ;
for ( V_14 = 0 ; V_14 < V_30 ; V_14 ++ ) {
F_18 ( V_43 + V_14 , V_29 [ V_14 ] ) ;
F_120 ( V_43 + V_14 , V_269 ) ;
}
F_24 ( V_29 ) ;
return V_43 ;
V_268:
for ( V_14 -- ; V_14 >= 0 ; V_14 -- )
F_111 ( V_43 + V_14 , V_29 [ V_14 ] ) ;
F_43 ( & V_118 , V_64 ) ;
V_267:
for ( V_14 = 0 ; V_14 < V_30 ; V_14 ++ )
F_31 ( V_43 + V_14 , V_29 [ V_14 ] ) ;
V_266:
F_24 ( V_29 ) ;
return 0 ;
}
unsigned int F_218 ( unsigned int V_49 , int V_26 )
{
return F_217 ( V_49 , 1 , V_26 ) ;
}
int F_219 ( void )
{
int V_26 = F_16 ( 0 ) ;
unsigned int V_270 ;
int V_43 ;
V_270 = V_265 ;
V_43 = F_218 ( V_270 , V_26 ) ;
if ( V_43 == 0 )
V_43 = - 1 ;
return V_43 ;
}
void F_220 ( unsigned int V_43 )
{
struct V_28 * V_29 = F_21 ( V_43 ) ;
unsigned long V_64 ;
F_119 ( V_43 , V_269 | V_271 ) ;
F_221 ( V_43 ) ;
F_42 ( & V_118 , V_64 ) ;
F_111 ( V_43 , V_29 ) ;
F_43 ( & V_118 , V_64 ) ;
F_31 ( V_43 , V_29 ) ;
}
void F_222 ( unsigned int V_43 , unsigned int V_30 )
{
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_30 ; V_14 ++ )
F_220 ( V_43 + V_14 ) ;
}
void F_223 ( struct V_272 * V_273 ,
unsigned int V_43 , unsigned int V_154 ,
struct V_274 * V_275 , T_8 V_276 )
{
struct V_28 * V_29 = V_28 ( V_43 ) ;
V_275 -> V_277 = V_278 ;
if ( F_224 () )
V_275 -> V_277 |= F_225 ( V_154 ) ;
V_275 -> V_279 =
V_280 |
( ( V_50 -> V_153 == 0 ) ?
V_281 :
V_282 ) |
( ( V_50 -> V_151 != V_283 ) ?
V_284 :
V_285 ) |
F_226 ( V_154 ) ;
V_275 -> V_55 =
V_286 |
V_287 |
( ( V_50 -> V_151 != V_283 ) ?
V_288 :
V_289 ) |
F_227 ( V_29 -> V_41 ) ;
}
static int F_228 ( struct V_272 * V_273 , unsigned int V_43 ,
struct V_274 * V_275 , T_8 V_276 )
{
struct V_28 * V_29 ;
int V_96 ;
unsigned V_154 ;
if ( V_290 )
return - V_291 ;
V_29 = V_28 ( V_43 ) ;
V_96 = F_110 ( V_43 , V_29 , V_50 -> V_155 () ) ;
if ( V_96 )
return V_96 ;
V_96 = V_50 -> V_156 ( V_29 -> V_39 ,
V_50 -> V_155 () , & V_154 ) ;
if ( V_96 )
return V_96 ;
V_292 . V_293 ( V_273 , V_43 , V_154 , V_275 , V_276 ) ;
return 0 ;
}
static int
F_229 ( struct V_79 * V_55 , const struct V_119 * V_67 , bool V_224 )
{
struct V_28 * V_29 = V_55 -> V_80 ;
struct V_274 V_275 ;
unsigned int V_154 ;
if ( F_180 ( V_55 , V_67 , & V_154 ) )
return - 1 ;
F_230 ( V_55 -> V_294 , & V_275 ) ;
V_275 . V_55 &= ~ V_295 ;
V_275 . V_55 |= F_227 ( V_29 -> V_41 ) ;
V_275 . V_279 &= ~ V_296 ;
V_275 . V_279 |= F_226 ( V_154 ) ;
F_231 ( V_55 -> V_294 , & V_275 ) ;
return V_226 ;
}
int F_232 ( struct V_272 * V_297 , struct V_294 * V_298 ,
unsigned int V_299 , unsigned int V_300 )
{
struct V_140 * V_141 = & V_301 ;
struct V_274 V_275 ;
unsigned int V_43 = V_299 + V_300 ;
int V_225 ;
V_225 = F_228 ( V_297 , V_43 , & V_275 , - 1 ) ;
if ( V_225 < 0 )
return V_225 ;
F_233 ( V_299 , V_300 , V_298 ) ;
if ( ! V_300 )
F_234 ( V_43 , & V_275 ) ;
F_121 ( V_43 , F_21 ( V_43 ) , V_141 ) ;
F_122 ( V_43 , V_141 , V_148 , L_18 ) ;
F_235 ( V_94 , & V_297 -> V_297 , L_67 , V_43 ) ;
return 0 ;
}
int F_236 ( struct V_272 * V_297 , int V_302 , int type )
{
unsigned int V_43 , V_270 ;
struct V_294 * V_298 ;
int V_26 , V_225 ;
if ( type == V_303 && V_302 > 1 )
return 1 ;
V_26 = F_237 ( & V_297 -> V_297 ) ;
V_270 = V_265 ;
F_238 (msidesc, &dev->msi_list, list) {
V_43 = F_218 ( V_270 , V_26 ) ;
if ( V_43 == 0 )
return - V_129 ;
V_270 = V_43 + 1 ;
V_225 = F_232 ( V_297 , V_298 , V_43 , 0 ) ;
if ( V_225 < 0 )
goto error;
}
return 0 ;
error:
F_220 ( V_43 ) ;
return V_225 ;
}
void F_239 ( unsigned int V_43 )
{
F_220 ( V_43 ) ;
}
static int
F_240 ( struct V_79 * V_55 , const struct V_119 * V_67 ,
bool V_224 )
{
struct V_28 * V_29 = V_55 -> V_80 ;
unsigned int V_154 , V_43 = V_55 -> V_43 ;
struct V_274 V_275 ;
if ( F_180 ( V_55 , V_67 , & V_154 ) )
return - 1 ;
F_241 ( V_43 , & V_275 ) ;
V_275 . V_55 &= ~ V_295 ;
V_275 . V_55 |= F_227 ( V_29 -> V_41 ) ;
V_275 . V_279 &= ~ V_296 ;
V_275 . V_279 |= F_226 ( V_154 ) ;
V_275 . V_277 = V_278 | F_225 ( V_154 ) ;
F_242 ( V_43 , & V_275 ) ;
return V_226 ;
}
int F_243 ( unsigned int V_43 )
{
int V_225 ;
struct V_274 V_275 ;
V_225 = F_228 ( NULL , V_43 , & V_275 , - 1 ) ;
if ( V_225 < 0 )
return V_225 ;
F_242 ( V_43 , & V_275 ) ;
F_122 ( V_43 , & V_304 , V_148 ,
L_18 ) ;
return 0 ;
}
static int F_244 ( struct V_79 * V_55 ,
const struct V_119 * V_67 , bool V_224 )
{
struct V_28 * V_29 = V_55 -> V_80 ;
struct V_274 V_275 ;
unsigned int V_154 ;
if ( F_180 ( V_55 , V_67 , & V_154 ) )
return - 1 ;
F_245 ( V_55 -> V_305 , & V_275 ) ;
V_275 . V_55 &= ~ V_295 ;
V_275 . V_55 |= F_227 ( V_29 -> V_41 ) ;
V_275 . V_279 &= ~ V_296 ;
V_275 . V_279 |= F_226 ( V_154 ) ;
F_246 ( V_55 -> V_305 , & V_275 ) ;
return V_226 ;
}
int F_247 ( unsigned int V_43 , unsigned int V_306 )
{
struct V_140 * V_141 = & V_307 ;
struct V_274 V_275 ;
int V_225 ;
V_225 = F_228 ( NULL , V_43 , & V_275 , V_306 ) ;
if ( V_225 < 0 )
return V_225 ;
F_246 ( F_248 ( V_43 ) , & V_275 ) ;
F_119 ( V_43 , V_308 ) ;
F_121 ( V_43 , F_21 ( V_43 ) , V_141 ) ;
F_122 ( V_43 , V_141 , V_148 , L_18 ) ;
return 0 ;
}
static void F_249 ( unsigned int V_43 , unsigned int V_154 , T_8 V_41 )
{
struct V_309 V_275 ;
F_250 ( V_43 , & V_275 ) ;
V_275 . V_279 &= ~ ( V_310 | V_311 ) ;
V_275 . V_277 &= ~ ( V_312 ) ;
V_275 . V_279 |= F_251 ( V_41 ) | F_252 ( V_154 ) ;
V_275 . V_277 |= F_253 ( V_154 ) ;
F_254 ( V_43 , & V_275 ) ;
}
static int
F_255 ( struct V_79 * V_55 , const struct V_119 * V_67 , bool V_224 )
{
struct V_28 * V_29 = V_55 -> V_80 ;
unsigned int V_154 ;
if ( F_180 ( V_55 , V_67 , & V_154 ) )
return - 1 ;
F_249 ( V_55 -> V_43 , V_154 , V_29 -> V_41 ) ;
return V_226 ;
}
int F_256 ( unsigned int V_43 , struct V_272 * V_297 )
{
struct V_28 * V_29 ;
struct V_309 V_275 ;
unsigned V_154 ;
int V_96 ;
if ( V_290 )
return - V_291 ;
V_29 = V_28 ( V_43 ) ;
V_96 = F_110 ( V_43 , V_29 , V_50 -> V_155 () ) ;
if ( V_96 )
return V_96 ;
V_96 = V_50 -> V_156 ( V_29 -> V_39 ,
V_50 -> V_155 () , & V_154 ) ;
if ( V_96 )
return V_96 ;
V_275 . V_277 = F_253 ( V_154 ) ;
V_275 . V_279 =
V_313 |
F_252 ( V_154 ) |
F_251 ( V_29 -> V_41 ) |
( ( V_50 -> V_153 == 0 ) ?
V_314 :
V_315 ) |
V_316 |
( ( V_50 -> V_151 != V_283 ) ?
V_317 :
V_318 ) |
V_319 ;
F_254 ( V_43 , & V_275 ) ;
F_122 ( V_43 , & V_320 ,
V_148 , L_18 ) ;
F_235 ( V_94 , & V_297 -> V_297 , L_68 , V_43 ) ;
return 0 ;
}
static int
F_127 ( unsigned int V_43 , int V_26 , struct V_114 * V_150 )
{
struct V_28 * V_29 = F_26 ( V_43 , V_26 ) ;
int V_225 ;
if ( ! V_29 )
return - V_222 ;
V_225 = F_48 ( V_29 , V_26 , V_150 -> V_157 , V_150 -> V_158 ) ;
if ( ! V_225 )
F_124 ( V_43 , V_29 , V_150 ) ;
return V_225 ;
}
int F_132 ( unsigned int V_43 , int V_26 ,
struct V_114 * V_150 )
{
unsigned int V_1 = V_150 -> V_157 , V_58 = V_150 -> V_158 ;
int V_225 ;
if ( F_74 ( V_58 , V_2 [ V_1 ] . V_321 ) ) {
F_135 ( L_69 ,
F_1 ( V_1 ) , V_58 ) ;
return 0 ;
}
V_225 = F_127 ( V_43 , V_26 , V_150 ) ;
if ( ! V_225 )
F_257 ( V_58 , V_2 [ V_1 ] . V_321 ) ;
return V_225 ;
}
static int T_1 F_258 ( int V_157 )
{
union V_322 V_323 ;
unsigned long V_64 ;
F_42 ( & V_65 , V_64 ) ;
V_323 . V_188 = F_40 ( V_157 , 1 ) ;
F_43 ( & V_65 , V_64 ) ;
return V_323 . V_190 . V_324 + 1 ;
}
static void T_1 F_259 ( void )
{
int V_325 ;
V_325 = V_112 + V_111 ;
if ( V_325 > V_265 )
V_265 = V_325 ;
F_141 ( V_94 L_70 , V_265 ) ;
}
int F_260 ( void )
{
return V_265 ;
}
int T_1 F_261 ( void )
{
int V_325 ;
if ( V_326 > ( V_138 * V_131 ) )
V_326 = V_138 * V_131 ;
V_325 = V_265 + 8 * V_131 ;
#if F_262 ( V_327 ) || F_262 ( V_328 )
V_325 += V_265 * 16 ;
#endif
if ( V_325 < V_326 )
V_326 = V_325 ;
return V_111 ;
}
int F_263 ( struct V_329 * V_297 , int V_43 ,
struct V_114 * V_115 )
{
int V_26 ;
if ( ! F_90 ( V_43 ) ) {
F_8 ( V_254 , V_189 L_71 ,
V_115 -> V_157 ) ;
return - V_222 ;
}
V_26 = V_297 ? F_237 ( V_297 ) : F_16 ( 0 ) ;
return F_132 ( V_43 , V_26 , V_115 ) ;
}
static int T_1 F_264 ( int V_157 , int V_330 )
{
union V_182 V_183 ;
static T_6 V_331 = V_332 ;
T_6 V_193 ;
unsigned long V_64 ;
int V_14 = 0 ;
if ( F_265 ( V_331 ) )
V_50 -> V_186 ( & V_187 , & V_331 ) ;
F_42 ( & V_65 , V_64 ) ;
V_183 . V_188 = F_40 ( V_157 , 0 ) ;
F_43 ( & V_65 , V_64 ) ;
if ( V_330 >= F_148 () ) {
F_141 ( V_179 L_72
L_73 , V_157 , V_330 , V_183 . V_190 . V_191 ) ;
V_330 = V_183 . V_190 . V_191 ;
}
if ( V_50 -> V_192 ( & V_331 , V_330 ) ) {
for ( V_14 = 0 ; V_14 < F_148 () ; V_14 ++ ) {
if ( ! V_50 -> V_192 ( & V_331 , V_14 ) )
break;
}
if ( V_14 == F_148 () )
F_9 ( L_74 ) ;
F_141 ( V_179 L_75
L_76 , V_157 , V_330 , V_14 ) ;
V_330 = V_14 ;
}
V_50 -> V_194 ( V_330 , & V_193 ) ;
F_151 ( V_331 , V_331 , V_193 ) ;
if ( V_183 . V_190 . V_191 != V_330 ) {
V_183 . V_190 . V_191 = V_330 ;
F_42 ( & V_65 , V_64 ) ;
F_45 ( V_157 , 0 , V_183 . V_188 ) ;
V_183 . V_188 = F_40 ( V_157 , 0 ) ;
F_43 ( & V_65 , V_64 ) ;
if ( V_183 . V_190 . V_191 != V_330 ) {
F_14 ( L_77 ,
V_157 ) ;
return - 1 ;
}
}
F_8 ( V_15 , V_93
L_78 , V_157 , V_330 ) ;
return V_330 ;
}
static T_8 T_1 F_266 ( T_8 V_306 )
{
if ( ( V_196 . V_197 == V_198 ) &&
! F_153 ( V_199 [ V_200 ] ) )
return F_264 ( V_34 , V_306 ) ;
else
return V_306 ;
}
static T_8 T_1 F_266 ( T_8 V_306 )
{
int V_14 ;
F_267 ( V_333 , 256 ) ;
F_268 ( V_333 , 256 ) ;
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
F_269 ( F_1 ( V_14 ) , V_333 ) ;
}
if ( ! F_74 ( V_306 , V_333 ) )
return V_306 ;
return F_270 ( V_333 , 256 ) ;
}
static int T_1 F_271 ( int V_157 )
{
union V_322 V_323 ;
unsigned long V_64 ;
F_42 ( & V_65 , V_64 ) ;
V_323 . V_188 = F_40 ( V_157 , 1 ) ;
F_43 ( & V_65 , V_64 ) ;
return V_323 . V_190 . V_334 ;
}
int F_272 ( T_3 V_109 , int * V_82 , int * V_103 )
{
int V_157 , V_58 , V_101 ;
if ( V_10 )
return - 1 ;
V_157 = F_130 ( V_109 ) ;
if ( V_157 < 0 )
return - 1 ;
V_58 = F_131 ( V_157 , V_109 ) ;
if ( V_58 < 0 )
return - 1 ;
V_101 = F_72 ( V_157 , V_58 , V_139 ) ;
if ( V_101 < 0 )
return - 1 ;
* V_82 = F_82 ( V_101 ) ;
* V_103 = F_78 ( V_101 ) ;
return 0 ;
}
void T_1 F_273 ( void )
{
int V_58 , V_157 , V_43 , V_335 ;
const struct V_119 * V_67 ;
struct V_79 * V_336 ;
if ( V_10 == 1 )
return;
for ( V_157 = 0 ; V_157 < V_34 ; V_157 ++ )
for ( V_58 = 0 ; V_58 < V_2 [ V_157 ] . V_37 ; V_58 ++ ) {
V_335 = F_72 ( V_157 , V_58 , V_139 ) ;
if ( V_335 == - 1 )
continue;
V_43 = F_87 ( V_335 , V_157 , V_58 ) ;
if ( ( V_157 > 0 ) && ( V_43 > 16 ) )
continue;
V_336 = F_274 ( V_43 ) ;
if ( ! F_275 ( V_336 ) || F_276 ( V_336 ) )
V_67 = V_336 -> V_223 ;
else
V_67 = V_50 -> V_155 () ;
V_84 . V_337 ( V_336 , V_67 , false ) ;
}
}
static struct V_338 * T_1 F_277 ( int V_34 )
{
unsigned long V_339 ;
struct V_338 * V_47 ;
char * V_340 ;
int V_14 ;
if ( V_34 <= 0 )
return NULL ;
V_339 = V_341 + sizeof( struct V_338 ) ;
V_339 *= V_34 ;
V_340 = F_278 ( V_339 ) ;
V_47 = ( void * ) V_340 ;
V_340 += sizeof( struct V_338 ) * V_34 ;
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
V_47 [ V_14 ] . V_342 = V_340 ;
V_47 [ V_14 ] . V_64 = V_343 | V_344 ;
snprintf ( V_340 , V_341 , L_79 , V_14 ) ;
V_340 += V_341 ;
}
V_345 = V_47 ;
return V_47 ;
}
void T_1 F_279 ( void )
{
unsigned long V_346 , V_101 = V_347 ;
struct V_338 * V_348 ;
int V_14 ;
V_348 = F_277 ( V_34 ) ;
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
if ( V_349 ) {
V_346 = F_2 ( V_14 ) ;
#ifdef F_88
if ( ! V_346 ) {
F_141 ( V_189
L_80
L_81
L_82 ) ;
V_349 = 0 ;
V_10 = 1 ;
goto V_350;
}
#endif
} else {
#ifdef F_88
V_350:
#endif
V_346 = ( unsigned long ) F_280 ( V_351 ) ;
V_346 = F_281 ( V_346 ) ;
}
F_282 ( V_101 , V_346 ) ;
F_8 ( V_15 , L_83 ,
F_283 ( V_101 ) + ( V_346 & ~ V_352 ) ,
V_346 ) ;
V_101 ++ ;
V_348 -> V_353 = V_346 ;
V_348 -> V_354 = V_346 + V_355 - 1 ;
V_348 ++ ;
}
F_259 () ;
}
void T_1 F_284 ( void )
{
int V_14 ;
struct V_338 * V_356 = V_345 ;
if ( ! V_356 ) {
if ( V_34 > 0 )
F_141 ( V_189
L_84 ) ;
return;
}
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
F_285 ( & V_357 , V_356 ) ;
V_356 ++ ;
}
}
int F_130 ( T_3 V_109 )
{
int V_14 = 0 ;
if ( V_34 == 0 )
return - 1 ;
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
struct V_6 * V_108 = F_3 ( V_14 ) ;
if ( ( V_109 >= V_108 -> V_110 )
&& ( V_109 <= V_108 -> V_358 ) )
return V_14 ;
}
F_141 ( V_189 L_85 , V_109 ) ;
return - 1 ;
}
int F_131 ( int V_157 , T_3 V_109 )
{
struct V_6 * V_108 ;
if ( F_286 ( V_157 == - 1 ) )
return - 1 ;
V_108 = F_3 ( V_157 ) ;
if ( F_286 ( V_109 > V_108 -> V_358 ) )
return - 1 ;
return V_109 - V_108 -> V_110 ;
}
static T_1 int F_287 ( unsigned long V_359 )
{
if ( V_34 >= V_360 ) {
F_81 ( L_86 ,
V_360 , V_34 ) ;
return 1 ;
}
if ( ! V_359 ) {
F_81 ( L_87 ) ;
return 1 ;
}
return 0 ;
}
static T_1 int F_288 ( int V_101 )
{
union V_182 V_183 ;
union V_322 V_323 ;
union V_361 V_362 ;
V_183 . V_188 = F_40 ( V_101 , 0 ) ;
V_323 . V_188 = F_40 ( V_101 , 1 ) ;
V_362 . V_188 = F_40 ( V_101 , 2 ) ;
if ( V_183 . V_188 == - 1 && V_323 . V_188 == - 1 && V_362 . V_188 == - 1 ) {
F_81 ( L_88 ,
F_2 ( V_101 ) ) ;
return 1 ;
}
return 0 ;
}
void T_1 F_289 ( int V_306 , T_3 V_359 , T_3 V_110 )
{
int V_101 = 0 ;
int V_324 ;
struct V_6 * V_108 ;
if ( F_287 ( V_359 ) )
return;
V_101 = V_34 ;
V_2 [ V_101 ] . V_3 . type = V_363 ;
V_2 [ V_101 ] . V_3 . V_64 = V_364 ;
V_2 [ V_101 ] . V_3 . V_5 = V_359 ;
F_282 ( V_347 + V_101 , V_359 ) ;
if ( F_288 ( V_101 ) ) {
F_290 ( V_347 + V_101 ) ;
return;
}
V_2 [ V_101 ] . V_3 . V_4 = F_266 ( V_306 ) ;
V_2 [ V_101 ] . V_3 . V_365 = F_271 ( V_101 ) ;
V_324 = F_258 ( V_101 ) ;
V_108 = F_3 ( V_101 ) ;
V_108 -> V_110 = V_110 ;
V_108 -> V_358 = V_110 + V_324 - 1 ;
V_2 [ V_101 ] . V_37 = V_324 ;
if ( V_108 -> V_358 >= V_112 )
V_112 = V_108 -> V_358 + 1 ;
F_291 ( L_89 ,
V_101 , F_1 ( V_101 ) ,
F_63 ( V_101 ) , F_2 ( V_101 ) ,
V_108 -> V_110 , V_108 -> V_358 ) ;
V_34 ++ ;
}
void T_1 F_292 ( void )
{
struct V_114 V_150 = { 0 , 0 , 0 , 0 } ;
F_141 ( V_93 L_90 ) ;
#ifndef V_221
F_293 ( V_200 ,
& V_187 ) ;
#endif
F_294 () ;
F_127 ( 0 , 0 , & V_150 ) ;
F_122 ( 0 , & V_142 , V_148 ,
L_18 ) ;
}
