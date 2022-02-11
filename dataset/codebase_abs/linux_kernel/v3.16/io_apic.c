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
for ( V_14 = 0 ; V_14 < V_30 ; V_14 ++ ) {
F_17 ( V_14 , & V_29 [ V_14 ] ) ;
F_18 ( & V_29 [ V_14 ] . V_39 , V_27 , V_26 ) ;
F_18 ( & V_29 [ V_14 ] . V_40 , V_27 , V_26 ) ;
if ( V_14 < V_31 -> V_32 ) {
V_29 [ V_14 ] . V_41 = V_42 + V_14 ;
F_19 ( V_29 [ V_14 ] . V_39 ) ;
}
}
return 0 ;
}
static struct V_28 * V_28 ( unsigned int V_43 )
{
return F_20 ( V_43 ) ;
}
static struct V_28 * F_21 ( unsigned int V_43 , int V_26 )
{
struct V_28 * V_29 ;
V_29 = F_11 ( sizeof( * V_29 ) , V_27 , V_26 ) ;
if ( ! V_29 )
return NULL ;
if ( ! F_18 ( & V_29 -> V_39 , V_27 , V_26 ) )
goto V_44;
if ( ! F_18 ( & V_29 -> V_40 , V_27 , V_26 ) )
goto V_45;
return V_29 ;
V_45:
F_22 ( V_29 -> V_39 ) ;
V_44:
F_23 ( V_29 ) ;
return NULL ;
}
static void F_24 ( unsigned int V_46 , struct V_28 * V_29 )
{
if ( ! V_29 )
return;
F_17 ( V_46 , NULL ) ;
F_22 ( V_29 -> V_39 ) ;
F_22 ( V_29 -> V_40 ) ;
F_23 ( V_29 ) ;
}
static struct V_28 * F_25 ( unsigned int V_46 , int V_26 )
{
int V_47 = F_26 ( V_46 , V_26 ) ;
struct V_28 * V_29 ;
if ( V_47 < 0 ) {
if ( V_47 != - V_48 )
return NULL ;
V_29 = F_20 ( V_46 ) ;
if ( V_29 )
return V_29 ;
}
V_29 = F_21 ( V_46 , V_26 ) ;
if ( V_29 )
F_17 ( V_46 , V_29 ) ;
else
F_27 ( V_46 ) ;
return V_29 ;
}
void F_28 ( unsigned int V_49 , unsigned int V_41 )
{
struct V_50 T_2 * V_50 = F_29 ( V_49 ) ;
F_30 ( V_41 , & V_50 -> V_51 ) ;
}
unsigned int F_31 ( unsigned int V_49 , unsigned int V_52 )
{
struct V_50 T_2 * V_50 = F_29 ( V_49 ) ;
F_30 ( V_52 , & V_50 -> V_53 ) ;
return F_32 ( & V_50 -> V_54 ) ;
}
void F_33 ( unsigned int V_49 , unsigned int V_52 , unsigned int V_55 )
{
struct V_50 T_2 * V_50 = F_29 ( V_49 ) ;
F_30 ( V_52 , & V_50 -> V_53 ) ;
F_30 ( V_55 , & V_50 -> V_54 ) ;
}
void F_34 ( unsigned int V_49 , unsigned int V_52 , unsigned int V_55 )
{
struct V_50 T_2 * V_50 = F_29 ( V_49 ) ;
if ( V_56 )
F_30 ( V_52 , & V_50 -> V_53 ) ;
F_30 ( V_55 , & V_50 -> V_54 ) ;
}
static struct V_36 F_35 ( int V_49 , int V_57 )
{
union V_58 V_59 ;
V_59 . V_60 = F_36 ( V_49 , 0x10 + 2 * V_57 ) ;
V_59 . V_61 = F_36 ( V_49 , 0x11 + 2 * V_57 ) ;
return V_59 . V_62 ;
}
static struct V_36 F_37 ( int V_49 , int V_57 )
{
union V_58 V_59 ;
unsigned long V_63 ;
F_38 ( & V_64 , V_63 ) ;
V_59 . V_62 = F_35 ( V_49 , V_57 ) ;
F_39 ( & V_64 , V_63 ) ;
return V_59 . V_62 ;
}
static void F_40 ( int V_49 , int V_57 , struct V_36 V_65 )
{
union V_58 V_59 = { { 0 , 0 } } ;
V_59 . V_62 = V_65 ;
F_41 ( V_49 , 0x11 + 2 * V_57 , V_59 . V_61 ) ;
F_41 ( V_49 , 0x10 + 2 * V_57 , V_59 . V_60 ) ;
}
static void F_42 ( int V_49 , int V_57 , struct V_36 V_65 )
{
unsigned long V_63 ;
F_38 ( & V_64 , V_63 ) ;
F_40 ( V_49 , V_57 , V_65 ) ;
F_39 ( & V_64 , V_63 ) ;
}
static void F_43 ( int V_49 , int V_57 )
{
unsigned long V_63 ;
union V_58 V_59 = { . V_62 . V_66 = 1 } ;
F_38 ( & V_64 , V_63 ) ;
F_41 ( V_49 , 0x10 + 2 * V_57 , V_59 . V_60 ) ;
F_41 ( V_49 , 0x11 + 2 * V_57 , V_59 . V_61 ) ;
F_39 ( & V_64 , V_63 ) ;
}
static int F_44 ( struct V_28 * V_29 , int V_26 , int V_49 , int V_57 )
{
struct V_25 * * V_67 , * V_62 ;
V_67 = & V_29 -> V_68 ;
F_45 (entry, cfg->irq_2_pin) {
if ( V_62 -> V_49 == V_49 && V_62 -> V_57 == V_57 )
return 0 ;
V_67 = & V_62 -> V_69 ;
}
V_62 = F_10 ( V_26 ) ;
if ( ! V_62 ) {
F_14 ( L_5 ,
V_26 , V_49 , V_57 ) ;
return - V_70 ;
}
V_62 -> V_49 = V_49 ;
V_62 -> V_57 = V_57 ;
* V_67 = V_62 ;
return 0 ;
}
static void F_46 ( struct V_28 * V_29 , int V_26 , int V_49 , int V_57 )
{
if ( F_44 ( V_29 , V_26 , V_49 , V_57 ) )
F_9 ( L_6 ) ;
}
static void T_1 F_47 ( struct V_28 * V_29 , int V_26 ,
int V_71 , int V_72 ,
int V_73 , int V_74 )
{
struct V_25 * V_62 ;
F_45 (entry, cfg->irq_2_pin) {
if ( V_62 -> V_49 == V_71 && V_62 -> V_57 == V_72 ) {
V_62 -> V_49 = V_73 ;
V_62 -> V_57 = V_74 ;
return;
}
}
F_46 ( V_29 , V_26 , V_73 , V_74 ) ;
}
static void F_48 ( struct V_25 * V_62 ,
int V_75 , int V_76 ,
void (* F_49)( struct V_25 * V_62 ) )
{
unsigned int V_52 , V_57 ;
V_57 = V_62 -> V_57 ;
V_52 = F_36 ( V_62 -> V_49 , 0x10 + V_57 * 2 ) ;
V_52 &= V_75 ;
V_52 |= V_76 ;
F_50 ( V_62 -> V_49 , 0x10 + V_57 * 2 , V_52 ) ;
if ( F_49 )
F_49 ( V_62 ) ;
}
static void F_51 ( struct V_28 * V_29 ,
int V_75 , int V_76 ,
void (* F_49)( struct V_25 * V_62 ) )
{
struct V_25 * V_62 ;
F_45 (entry, cfg->irq_2_pin)
F_48 ( V_62 , V_75 , V_76 , F_49 ) ;
}
static void F_52 ( struct V_25 * V_62 )
{
struct V_50 T_2 * V_50 ;
V_50 = F_29 ( V_62 -> V_49 ) ;
F_32 ( & V_50 -> V_54 ) ;
}
static void F_53 ( struct V_28 * V_29 )
{
unsigned long V_63 ;
F_38 ( & V_64 , V_63 ) ;
F_51 ( V_29 , ~ 0 , V_77 , & F_52 ) ;
F_39 ( & V_64 , V_63 ) ;
}
static void F_54 ( struct V_78 * V_54 )
{
F_53 ( V_54 -> V_79 ) ;
}
static void F_55 ( struct V_28 * V_29 )
{
F_51 ( V_29 , ~ V_77 , 0 , NULL ) ;
}
static void F_56 ( struct V_28 * V_29 )
{
unsigned long V_63 ;
F_38 ( & V_64 , V_63 ) ;
F_55 ( V_29 ) ;
F_39 ( & V_64 , V_63 ) ;
}
static void F_57 ( struct V_78 * V_54 )
{
F_56 ( V_54 -> V_79 ) ;
}
void F_58 ( int V_49 , int V_57 , int V_41 )
{
if ( F_59 ( V_49 ) >= 0x20 ) {
F_28 ( V_49 , V_41 ) ;
} else {
struct V_36 V_62 , V_80 ;
V_62 = V_80 = F_35 ( V_49 , V_57 ) ;
V_80 . V_66 = 1 ;
V_80 . V_81 = V_82 ;
F_40 ( V_49 , V_57 , V_80 ) ;
F_40 ( V_49 , V_57 , V_62 ) ;
}
}
void F_60 ( unsigned int V_43 , struct V_28 * V_29 )
{
struct V_25 * V_62 ;
unsigned long V_63 ;
F_38 ( & V_64 , V_63 ) ;
F_45 (entry, cfg->irq_2_pin)
V_83 . V_84 ( V_62 -> V_49 , V_62 -> V_57 ,
V_29 -> V_41 ) ;
F_39 ( & V_64 , V_63 ) ;
}
static void F_61 ( unsigned int V_49 , unsigned int V_57 )
{
struct V_36 V_62 ;
V_62 = F_37 ( V_49 , V_57 ) ;
if ( V_62 . V_85 == V_86 )
return;
if ( ! V_62 . V_66 ) {
V_62 . V_66 = 1 ;
F_42 ( V_49 , V_57 , V_62 ) ;
V_62 = F_37 ( V_49 , V_57 ) ;
}
if ( V_62 . V_87 ) {
unsigned long V_63 ;
if ( ! V_62 . V_81 ) {
V_62 . V_81 = V_88 ;
F_42 ( V_49 , V_57 , V_62 ) ;
}
F_38 ( & V_64 , V_63 ) ;
V_83 . V_84 ( V_49 , V_57 , V_62 . V_41 ) ;
F_39 ( & V_64 , V_63 ) ;
}
F_43 ( V_49 , V_57 ) ;
V_62 = F_37 ( V_49 , V_57 ) ;
if ( V_62 . V_87 )
F_14 ( L_7 ,
F_1 ( V_49 ) , V_57 ) ;
}
static void F_62 ( void )
{
int V_49 , V_57 ;
for ( V_49 = 0 ; V_49 < V_34 ; V_49 ++ )
for ( V_57 = 0 ; V_57 < V_2 [ V_49 ] . V_37 ; V_57 ++ )
F_61 ( V_49 , V_57 ) ;
}
static int T_1 F_63 ( char * V_11 )
{
int V_14 , V_89 ;
int V_90 [ V_91 + 1 ] ;
F_64 ( V_11 , F_15 ( V_90 ) , V_90 ) ;
F_8 ( V_15 , V_92
L_8 ) ;
V_89 = V_91 ;
if ( V_90 [ 0 ] < V_91 )
V_89 = V_90 [ 0 ] ;
for ( V_14 = 0 ; V_14 < V_89 ; V_14 ++ ) {
F_8 ( V_15 , V_93
L_9 , V_14 , V_90 [ V_14 + 1 ] ) ;
V_94 [ V_91 - V_14 - 1 ] = V_90 [ V_14 + 1 ] ;
}
return 1 ;
}
int F_65 ( void )
{
int V_49 , V_57 ;
int V_95 = 0 ;
for ( V_49 = 0 ; V_49 < V_34 ; V_49 ++ ) {
if ( ! V_2 [ V_49 ] . V_35 ) {
V_95 = - V_70 ;
continue;
}
for ( V_57 = 0 ; V_57 < V_2 [ V_49 ] . V_37 ; V_57 ++ )
V_2 [ V_49 ] . V_35 [ V_57 ] =
F_37 ( V_49 , V_57 ) ;
}
return V_95 ;
}
void F_66 ( void )
{
int V_49 , V_57 ;
for ( V_49 = 0 ; V_49 < V_34 ; V_49 ++ ) {
if ( ! V_2 [ V_49 ] . V_35 )
continue;
for ( V_57 = 0 ; V_57 < V_2 [ V_49 ] . V_37 ; V_57 ++ ) {
struct V_36 V_62 ;
V_62 = V_2 [ V_49 ] . V_35 [ V_57 ] ;
if ( ! V_62 . V_66 ) {
V_62 . V_66 = 1 ;
F_42 ( V_49 , V_57 , V_62 ) ;
}
}
}
}
int F_67 ( void )
{
int V_49 , V_57 ;
for ( V_49 = 0 ; V_49 < V_34 ; V_49 ++ ) {
if ( ! V_2 [ V_49 ] . V_35 )
continue;
for ( V_57 = 0 ; V_57 < V_2 [ V_49 ] . V_37 ; V_57 ++ )
F_42 ( V_49 , V_57 ,
V_2 [ V_49 ] . V_35 [ V_57 ] ) ;
}
return 0 ;
}
static int F_68 ( int V_1 , int V_57 , int type )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ )
if ( V_23 [ V_14 ] . V_16 == type &&
( V_23 [ V_14 ] . V_20 == F_1 ( V_1 ) ||
V_23 [ V_14 ] . V_20 == V_96 ) &&
V_23 [ V_14 ] . V_21 == V_57 )
return V_14 ;
return - 1 ;
}
static int T_1 F_69 ( int V_43 , int type )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ ) {
int V_97 = V_23 [ V_14 ] . V_18 ;
if ( F_70 ( V_97 , V_98 ) &&
( V_23 [ V_14 ] . V_16 == type ) &&
( V_23 [ V_14 ] . V_19 == V_43 ) )
return V_23 [ V_14 ] . V_21 ;
}
return - 1 ;
}
static int T_1 F_71 ( int V_43 , int type )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ ) {
int V_97 = V_23 [ V_14 ] . V_18 ;
if ( F_70 ( V_97 , V_98 ) &&
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
static int F_72 ( unsigned int V_43 )
{
if ( V_43 < V_31 -> V_32 ) {
unsigned int V_99 = 0x4d0 + ( V_43 >> 3 ) ;
return ( F_73 ( V_99 ) >> ( V_43 & 7 ) ) & 1 ;
}
F_8 ( V_15 , V_92
L_10 , V_43 ) ;
return 0 ;
}
static int F_74 ( int V_100 )
{
int V_101 = V_23 [ V_100 ] . V_18 ;
int V_102 ;
switch ( V_23 [ V_100 ] . V_17 & 3 )
{
case 0 :
if ( F_70 ( V_101 , V_98 ) )
V_102 = F_75 ( V_100 ) ;
else
V_102 = F_76 ( V_100 ) ;
break;
case 1 :
{
V_102 = 0 ;
break;
}
case 2 :
{
F_77 ( L_11 ) ;
V_102 = 1 ;
break;
}
case 3 :
{
V_102 = 1 ;
break;
}
default:
{
F_77 ( L_11 ) ;
V_102 = 1 ;
break;
}
}
return V_102 ;
}
static int F_78 ( int V_100 )
{
int V_101 = V_23 [ V_100 ] . V_18 ;
int V_81 ;
switch ( ( V_23 [ V_100 ] . V_17 >> 2 ) & 3 )
{
case 0 :
if ( F_70 ( V_101 , V_98 ) )
V_81 = F_79 ( V_100 ) ;
else
V_81 = F_80 ( V_100 ) ;
#ifdef F_81
switch ( V_103 [ V_101 ] ) {
case V_104 :
{
break;
}
case V_105 :
{
V_81 = F_82 ( V_100 ) ;
break;
}
case V_106 :
{
break;
}
default:
{
F_77 ( L_11 ) ;
V_81 = 1 ;
break;
}
}
#endif
break;
case 1 :
{
V_81 = 0 ;
break;
}
case 2 :
{
F_77 ( L_11 ) ;
V_81 = 1 ;
break;
}
case 3 :
{
V_81 = 1 ;
break;
}
default:
{
F_77 ( L_11 ) ;
V_81 = 0 ;
break;
}
}
return V_81 ;
}
static int F_83 ( int V_100 , int V_49 , int V_57 )
{
int V_43 ;
int V_101 = V_23 [ V_100 ] . V_18 ;
struct V_6 * V_107 = F_3 ( V_49 ) ;
if ( V_23 [ V_100 ] . V_21 != V_57 )
F_14 ( L_12 ) ;
if ( F_70 ( V_101 , V_98 ) ) {
V_43 = V_23 [ V_100 ] . V_19 ;
} else {
T_3 V_108 = V_107 -> V_109 + V_57 ;
if ( V_108 >= V_110 )
V_43 = V_108 ;
else
V_43 = V_111 + V_108 ;
}
#ifdef F_84
if ( ( V_57 >= 16 ) && ( V_57 <= 23 ) ) {
if ( V_94 [ V_57 - 16 ] != - 1 ) {
if ( ! V_94 [ V_57 - 16 ] ) {
F_8 ( V_15 , V_93
L_13 , V_57 - 16 ) ;
} else {
V_43 = V_94 [ V_57 - 16 ] ;
F_8 ( V_15 , V_93
L_14 ,
V_57 - 16 , V_43 ) ;
}
}
}
#endif
return V_43 ;
}
int F_85 ( int V_101 , int V_112 , int V_57 ,
struct V_113 * V_114 )
{
int V_1 , V_14 , V_115 = - 1 ;
F_8 ( V_116 ,
L_15 ,
V_101 , V_112 , V_57 ) ;
if ( F_70 ( V_101 , V_98 ) ) {
F_8 ( V_15 ,
L_16 , V_101 ) ;
return - 1 ;
}
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ ) {
int V_97 = V_23 [ V_14 ] . V_18 ;
for ( V_1 = 0 ; V_1 < V_34 ; V_1 ++ )
if ( F_1 ( V_1 ) == V_23 [ V_14 ] . V_20 ||
V_23 [ V_14 ] . V_20 == V_96 )
break;
if ( ! F_70 ( V_97 , V_98 ) &&
! V_23 [ V_14 ] . V_16 &&
( V_101 == V_97 ) &&
( V_112 == ( ( V_23 [ V_14 ] . V_19 >> 2 ) & 0x1f ) ) ) {
int V_43 = F_83 ( V_14 , V_1 , V_23 [ V_14 ] . V_21 ) ;
if ( ! ( V_1 || F_86 ( V_43 ) ) )
continue;
if ( V_57 == ( V_23 [ V_14 ] . V_19 & 3 ) ) {
F_87 ( V_114 , V_1 ,
V_23 [ V_14 ] . V_21 ,
F_78 ( V_14 ) ,
F_74 ( V_14 ) ) ;
return V_43 ;
}
if ( V_115 < 0 ) {
F_87 ( V_114 , V_1 ,
V_23 [ V_14 ] . V_21 ,
F_78 ( V_14 ) ,
F_74 ( V_14 ) ) ;
V_115 = V_43 ;
}
}
}
return V_115 ;
}
void F_88 ( void )
{
F_89 ( & V_117 ) ;
}
void F_90 ( void )
{
F_91 ( & V_117 ) ;
}
static int
F_92 ( int V_43 , struct V_28 * V_29 , const struct V_118 * V_66 )
{
static int V_119 = V_120 + V_121 ;
static int V_122 = V_121 % 16 ;
int V_123 , V_95 ;
T_4 V_124 ;
if ( V_29 -> V_125 )
return - V_126 ;
if ( ! F_93 ( & V_124 , V_127 ) )
return - V_70 ;
V_95 = - V_128 ;
F_94 ( V_29 -> V_40 ) ;
V_123 = F_95 ( V_66 , V_129 ) ;
while ( V_123 < V_130 ) {
int V_131 , V_41 , V_132 ;
V_49 -> V_133 ( V_123 , V_124 , V_66 ) ;
if ( F_96 ( V_124 , V_29 -> V_39 ) ) {
V_95 = 0 ;
if ( F_97 ( V_124 , V_29 -> V_39 ) )
break;
F_98 ( V_29 -> V_40 , V_29 -> V_39 , V_124 ) ;
V_29 -> V_125 =
F_99 ( V_29 -> V_40 , V_129 ) ;
F_100 ( V_29 -> V_39 , V_29 -> V_39 , V_124 ) ;
break;
}
V_41 = V_119 ;
V_132 = V_122 ;
V_69:
V_41 += 16 ;
if ( V_41 >= V_134 ) {
V_132 = ( V_132 + 1 ) % 16 ;
V_41 = V_120 + V_132 ;
}
if ( F_101 ( V_119 == V_41 ) ) {
F_102 ( V_29 -> V_40 , V_29 -> V_40 , V_124 ) ;
F_98 ( V_124 , V_66 , V_29 -> V_40 ) ;
V_123 = F_95 ( V_124 , V_129 ) ;
continue;
}
if ( F_70 ( V_41 , V_135 ) )
goto V_69;
F_103 (new_cpu, tmp_mask, cpu_online_mask) {
if ( F_104 ( V_136 , V_131 ) [ V_41 ] > V_137 )
goto V_69;
}
V_119 = V_41 ;
V_122 = V_132 ;
if ( V_29 -> V_41 ) {
F_105 ( V_29 -> V_40 , V_29 -> V_39 ) ;
V_29 -> V_125 =
F_99 ( V_29 -> V_40 , V_129 ) ;
}
F_103 (new_cpu, tmp_mask, cpu_online_mask)
F_104 ( V_136 , V_131 ) [ V_41 ] = V_43 ;
V_29 -> V_41 = V_41 ;
F_105 ( V_29 -> V_39 , V_124 ) ;
V_95 = 0 ;
break;
}
F_22 ( V_124 ) ;
return V_95 ;
}
int F_106 ( int V_43 , struct V_28 * V_29 , const struct V_118 * V_66 )
{
int V_95 ;
unsigned long V_63 ;
F_38 ( & V_117 , V_63 ) ;
V_95 = F_92 ( V_43 , V_29 , V_66 ) ;
F_39 ( & V_117 , V_63 ) ;
return V_95 ;
}
static void F_107 ( int V_43 , struct V_28 * V_29 )
{
int V_123 , V_41 ;
F_108 ( ! V_29 -> V_41 ) ;
V_41 = V_29 -> V_41 ;
F_103 (cpu, cfg->domain, cpu_online_mask)
F_104 ( V_136 , V_123 ) [ V_41 ] = V_137 ;
V_29 -> V_41 = 0 ;
F_94 ( V_29 -> V_39 ) ;
if ( F_109 ( ! V_29 -> V_125 ) )
return;
F_103 (cpu, cfg->old_domain, cpu_online_mask) {
for ( V_41 = V_120 ; V_41 < V_138 ; V_41 ++ ) {
if ( F_104 ( V_136 , V_123 ) [ V_41 ] != V_43 )
continue;
F_104 ( V_136 , V_123 ) [ V_41 ] = V_137 ;
break;
}
}
V_29 -> V_125 = 0 ;
}
void F_110 ( int V_123 )
{
int V_43 , V_41 ;
struct V_28 * V_29 ;
F_89 ( & V_117 ) ;
F_111 (irq) {
V_29 = F_20 ( V_43 ) ;
if ( ! V_29 )
continue;
if ( ! F_112 ( V_123 , V_29 -> V_39 ) )
continue;
V_41 = V_29 -> V_41 ;
F_104 ( V_136 , V_123 ) [ V_41 ] = V_43 ;
}
for ( V_41 = 0 ; V_41 < V_138 ; ++ V_41 ) {
V_43 = F_104 ( V_136 , V_123 ) [ V_41 ] ;
if ( V_43 <= V_137 )
continue;
V_29 = V_28 ( V_43 ) ;
if ( ! F_112 ( V_123 , V_29 -> V_39 ) )
F_104 ( V_136 , V_123 ) [ V_41 ] = V_137 ;
}
F_91 ( & V_117 ) ;
}
static inline int F_113 ( int V_43 )
{
int V_49 , V_100 , V_57 ;
for ( V_49 = 0 ; V_49 < V_34 ; V_49 ++ ) {
for ( V_57 = 0 ; V_57 < V_2 [ V_49 ] . V_37 ; V_57 ++ ) {
V_100 = F_68 ( V_49 , V_57 , V_139 ) ;
if ( ( V_100 != - 1 ) && ( V_43 == F_83 ( V_100 , V_49 , V_57 ) ) )
return F_78 ( V_100 ) ;
}
}
return 0 ;
}
static inline int F_113 ( int V_43 )
{
return 1 ;
}
static void F_114 ( unsigned int V_43 , struct V_28 * V_29 ,
unsigned long V_81 )
{
struct V_140 * V_141 = & V_142 ;
T_5 V_143 ;
bool V_144 ;
if ( ( V_81 == V_145 && F_113 ( V_43 ) ) ||
V_81 == V_88 ) {
F_115 ( V_43 , V_146 ) ;
V_144 = true ;
} else {
F_116 ( V_43 , V_146 ) ;
V_144 = false ;
}
if ( F_117 ( V_43 , V_29 , V_141 ) )
V_144 = V_81 != 0 ;
V_143 = V_144 ? V_147 : V_148 ;
F_118 ( V_43 , V_141 , V_143 ,
V_144 ? L_17 : L_18 ) ;
}
int F_119 ( int V_43 , struct V_36 * V_62 ,
unsigned int V_149 , int V_41 ,
struct V_113 * V_150 )
{
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
V_62 -> V_85 = V_49 -> V_151 ;
V_62 -> V_152 = V_49 -> V_153 ;
V_62 -> V_154 = V_149 ;
V_62 -> V_41 = V_41 ;
V_62 -> V_66 = 0 ;
V_62 -> V_81 = V_150 -> V_81 ;
V_62 -> V_102 = V_150 -> V_102 ;
if ( V_150 -> V_81 )
V_62 -> V_66 = 1 ;
return 0 ;
}
static void F_120 ( unsigned int V_43 , struct V_28 * V_29 ,
struct V_113 * V_150 )
{
struct V_36 V_62 ;
unsigned int V_154 ;
if ( ! F_86 ( V_43 ) )
return;
if ( F_106 ( V_43 , V_29 , V_49 -> V_155 () ) )
return;
if ( V_49 -> V_156 ( V_29 -> V_39 , V_49 -> V_155 () ,
& V_154 ) ) {
F_77 ( L_19 ,
F_1 ( V_150 -> V_157 ) , V_150 -> V_158 ) ;
F_107 ( V_43 , V_29 ) ;
return;
}
F_8 ( V_15 , V_93
L_20
L_21 ,
V_150 -> V_157 , F_1 ( V_150 -> V_157 ) , V_150 -> V_158 ,
V_29 -> V_41 , V_43 , V_150 -> V_81 , V_150 -> V_102 , V_154 ) ;
if ( V_83 . V_159 ( V_43 , & V_62 , V_154 , V_29 -> V_41 , V_150 ) ) {
F_77 ( L_22 ,
F_1 ( V_150 -> V_157 ) , V_150 -> V_158 ) ;
F_107 ( V_43 , V_29 ) ;
return;
}
F_114 ( V_43 , V_29 , V_150 -> V_81 ) ;
if ( V_43 < V_31 -> V_32 )
V_31 -> V_66 ( V_43 ) ;
F_42 ( V_150 -> V_157 , V_150 -> V_158 , V_62 ) ;
}
static bool T_1 F_121 ( int V_100 , int V_1 , int V_57 )
{
if ( V_100 != - 1 )
return false ;
F_8 ( V_15 , V_93 L_23 ,
F_1 ( V_1 ) , V_57 ) ;
return true ;
}
static void T_1 F_122 ( unsigned int V_1 )
{
int V_100 , V_26 = F_16 ( 0 ) ;
struct V_113 V_150 ;
unsigned int V_57 , V_43 ;
for ( V_57 = 0 ; V_57 < V_2 [ V_1 ] . V_37 ; V_57 ++ ) {
V_100 = F_68 ( V_1 , V_57 , V_139 ) ;
if ( F_121 ( V_100 , V_1 , V_57 ) )
continue;
V_43 = F_83 ( V_100 , V_1 , V_57 ) ;
if ( ( V_1 > 0 ) && ( V_43 > 16 ) )
continue;
if ( V_49 -> V_160 &&
V_49 -> V_160 ( V_1 , V_43 ) )
continue;
F_87 ( & V_150 , V_1 , V_57 , F_78 ( V_100 ) ,
F_74 ( V_100 ) ) ;
F_123 ( V_43 , V_26 , & V_150 ) ;
}
}
static void T_1 F_124 ( void )
{
unsigned int V_1 ;
F_8 ( V_15 , V_93 L_24 ) ;
for ( V_1 = 0 ; V_1 < V_34 ; V_1 ++ )
F_122 ( V_1 ) ;
}
void F_125 ( T_3 V_108 )
{
int V_1 = 0 , V_57 , V_100 , V_43 , V_26 = F_16 ( 0 ) ;
struct V_113 V_150 ;
V_1 = F_126 ( V_108 ) ;
if ( V_1 < 0 )
return;
V_57 = F_127 ( V_1 , V_108 ) ;
V_100 = F_68 ( V_1 , V_57 , V_139 ) ;
if ( V_100 == - 1 )
return;
V_43 = F_83 ( V_100 , V_1 , V_57 ) ;
if ( V_1 == 0 || V_43 < V_110 )
return;
F_87 ( & V_150 , V_1 , V_57 , F_78 ( V_100 ) ,
F_74 ( V_100 ) ) ;
F_128 ( V_43 , V_26 , & V_150 ) ;
}
static void T_1 F_129 ( unsigned int V_1 ,
unsigned int V_57 , int V_41 )
{
struct V_36 V_62 ;
unsigned int V_154 ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
if ( F_101 ( V_49 -> V_156 ( V_49 -> V_155 () ,
V_49 -> V_155 () , & V_154 ) ) )
V_154 = V_161 ;
V_62 . V_152 = V_49 -> V_153 ;
V_62 . V_66 = 0 ;
V_62 . V_154 = V_154 ;
V_62 . V_85 = V_49 -> V_151 ;
V_62 . V_102 = 0 ;
V_62 . V_81 = 0 ;
V_62 . V_41 = V_41 ;
F_118 ( 0 , & V_142 , V_148 ,
L_18 ) ;
F_42 ( V_1 , V_57 , V_62 ) ;
}
void F_130 ( unsigned int V_49 , unsigned int V_162 )
{
int V_14 ;
F_131 ( L_25 ) ;
for ( V_14 = 0 ; V_14 <= V_162 ; V_14 ++ ) {
struct V_36 V_62 ;
V_62 = F_37 ( V_49 , V_14 ) ;
F_131 ( L_26 , V_14 , V_62 . V_154 ) ;
F_132 ( L_27
L_28 ,
V_62 . V_66 ,
V_62 . V_81 ,
V_62 . V_87 ,
V_62 . V_102 ,
V_62 . V_163 ,
V_62 . V_152 ,
V_62 . V_85 ,
V_62 . V_41 ) ;
}
}
void F_133 ( unsigned int V_49 ,
unsigned int V_162 )
{
int V_14 ;
F_131 ( L_29 ) ;
for ( V_14 = 0 ; V_14 <= V_162 ; V_14 ++ ) {
struct V_164 * V_165 ;
struct V_36 V_62 ;
V_62 = F_37 ( V_49 , V_14 ) ;
V_165 = (struct V_164 * ) & V_62 ;
F_131 ( L_30 , V_14 , V_165 -> V_53 ) ;
F_132 ( L_31
L_32 ,
V_165 -> V_166 ,
V_165 -> V_66 ,
V_165 -> V_81 ,
V_165 -> V_87 ,
V_165 -> V_102 ,
V_165 -> V_163 ,
V_165 -> V_167 ,
V_165 -> V_168 ,
V_165 -> V_41 ) ;
}
}
void F_134 ( void )
{
F_135 ( & V_64 ) ;
}
static T_1 int F_136 ( char * V_169 )
{
int V_170 = - 1 ;
if ( strcmp ( V_169 , L_33 ) == 0 ) {
V_171 = V_172 ;
} else {
F_137 ( & V_169 , & V_170 ) ;
if ( V_170 >= 0 )
V_171 = V_170 ;
}
return 1 ;
}
void T_1 F_138 ( void )
{
int V_173 , V_174 ;
int V_49 ;
if ( ! V_31 -> V_32 )
return;
for( V_49 = 0 ; V_49 < V_34 ; V_49 ++ ) {
int V_57 ;
for ( V_57 = 0 ; V_57 < V_2 [ V_49 ] . V_37 ; V_57 ++ ) {
struct V_36 V_62 ;
V_62 = F_37 ( V_49 , V_57 ) ;
if ( ( V_62 . V_66 == 0 ) && ( V_62 . V_85 == V_175 ) ) {
V_176 . V_49 = V_49 ;
V_176 . V_57 = V_57 ;
goto V_177;
}
}
}
V_177:
V_174 = F_69 ( 0 , V_178 ) ;
V_173 = F_71 ( 0 , V_178 ) ;
if ( ( V_176 . V_57 == - 1 ) && ( V_174 >= 0 ) ) {
F_139 ( V_179 L_34 ) ;
V_176 . V_57 = V_174 ;
V_176 . V_49 = V_173 ;
}
if ( ( ( V_176 . V_49 != V_173 ) || ( V_176 . V_57 != V_174 ) ) &&
( V_174 >= 0 ) && ( V_176 . V_57 >= 0 ) )
{
F_139 ( V_179 L_35 ) ;
}
F_62 () ;
}
void F_140 ( void )
{
if ( V_176 . V_57 != - 1 ) {
struct V_36 V_62 ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_66 = 0 ;
V_62 . V_81 = 0 ;
V_62 . V_87 = 0 ;
V_62 . V_102 = 0 ;
V_62 . V_163 = 0 ;
V_62 . V_152 = 0 ;
V_62 . V_85 = V_175 ;
V_62 . V_41 = 0 ;
V_62 . V_154 = F_141 () ;
F_42 ( V_176 . V_49 , V_176 . V_57 , V_62 ) ;
}
if ( V_180 || F_142 () )
F_143 ( V_176 . V_57 != - 1 ) ;
}
void F_144 ( void )
{
F_62 () ;
if ( ! V_31 -> V_32 )
return;
V_83 . V_181 () ;
}
void T_1 F_145 ( void )
{
union V_182 V_183 ;
T_6 V_184 ;
int V_1 ;
int V_14 ;
unsigned char V_185 ;
unsigned long V_63 ;
V_49 -> V_186 ( & V_187 , & V_184 ) ;
for ( V_1 = 0 ; V_1 < V_34 ; V_1 ++ ) {
F_38 ( & V_64 , V_63 ) ;
V_183 . V_188 = F_36 ( V_1 , 0 ) ;
F_39 ( & V_64 , V_63 ) ;
V_185 = F_1 ( V_1 ) ;
if ( F_1 ( V_1 ) >= F_146 () ) {
F_139 ( V_189 L_36 ,
V_1 , F_1 ( V_1 ) ) ;
F_139 ( V_189 L_37 ,
V_183 . V_190 . V_191 ) ;
V_2 [ V_1 ] . V_3 . V_4 = V_183 . V_190 . V_191 ;
}
if ( V_49 -> V_192 ( & V_184 ,
F_1 ( V_1 ) ) ) {
F_139 ( V_189 L_38 ,
V_1 , F_1 ( V_1 ) ) ;
for ( V_14 = 0 ; V_14 < F_146 () ; V_14 ++ )
if ( ! F_147 ( V_14 , V_184 ) )
break;
if ( V_14 >= F_146 () )
F_9 ( L_39 ) ;
F_139 ( V_189 L_37 ,
V_14 ) ;
F_148 ( V_14 , V_184 ) ;
V_2 [ V_1 ] . V_3 . V_4 = V_14 ;
} else {
T_6 V_193 ;
V_49 -> V_194 ( F_1 ( V_1 ) ,
& V_193 ) ;
F_8 ( V_15 , L_40
L_41 ,
F_1 ( V_1 ) ) ;
F_149 ( V_184 , V_184 , V_193 ) ;
}
if ( V_185 != F_1 ( V_1 ) )
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ )
if ( V_23 [ V_14 ] . V_20 == V_185 )
V_23 [ V_14 ] . V_20
= F_1 ( V_1 ) ;
if ( F_1 ( V_1 ) == V_183 . V_190 . V_191 )
continue;
F_8 ( V_15 , V_92
L_42 ,
F_1 ( V_1 ) ) ;
V_183 . V_190 . V_191 = F_1 ( V_1 ) ;
F_38 ( & V_64 , V_63 ) ;
F_41 ( V_1 , 0 , V_183 . V_188 ) ;
F_39 ( & V_64 , V_63 ) ;
F_38 ( & V_64 , V_63 ) ;
V_183 . V_188 = F_36 ( V_1 , 0 ) ;
F_39 ( & V_64 , V_63 ) ;
if ( V_183 . V_190 . V_191 != F_1 ( V_1 ) )
F_132 ( L_43 ) ;
else
F_8 ( V_15 , L_44 ) ;
}
}
void T_1 F_150 ( void )
{
if ( V_195 )
return;
if ( ! ( V_196 . V_197 == V_198 )
|| F_151 ( V_199 [ V_200 ] ) )
return;
F_145 () ;
}
static int T_1 F_152 ( char * V_201 )
{
V_202 = 1 ;
return 1 ;
}
static int T_1 F_153 ( void )
{
unsigned long V_203 = V_204 ;
unsigned long V_63 ;
if ( V_202 )
return 1 ;
F_154 ( V_63 ) ;
F_155 () ;
F_156 ( ( 10 * 1000 ) / V_205 ) ;
F_157 ( V_63 ) ;
if ( F_158 ( V_204 , V_203 + 4 ) )
return 1 ;
return 0 ;
}
static unsigned int F_159 ( struct V_78 * V_54 )
{
int V_206 = 0 , V_43 = V_54 -> V_43 ;
unsigned long V_63 ;
F_38 ( & V_64 , V_63 ) ;
if ( V_43 < V_31 -> V_32 ) {
V_31 -> V_66 ( V_43 ) ;
if ( V_31 -> V_207 ( V_43 ) )
V_206 = 1 ;
}
F_55 ( V_54 -> V_79 ) ;
F_39 ( & V_64 , V_63 ) ;
return V_206 ;
}
static int F_160 ( struct V_78 * V_54 )
{
struct V_28 * V_29 = V_54 -> V_79 ;
unsigned long V_63 ;
int V_123 ;
F_38 ( & V_117 , V_63 ) ;
V_123 = F_95 ( V_29 -> V_39 , V_129 ) ;
V_49 -> V_208 ( F_161 ( V_123 ) , V_29 -> V_41 ) ;
F_39 ( & V_117 , V_63 ) ;
return 1 ;
}
void F_162 ( struct V_28 * V_29 )
{
T_4 V_209 ;
if ( F_101 ( ! F_93 ( & V_209 , V_127 ) ) ) {
unsigned int V_14 ;
F_103 (i, cfg->old_domain, cpu_online_mask)
V_49 -> V_208 ( F_161 ( V_14 ) , V_210 ) ;
} else {
F_100 ( V_209 , V_29 -> V_40 , V_129 ) ;
V_49 -> V_208 ( V_209 , V_210 ) ;
F_22 ( V_209 ) ;
}
V_29 -> V_125 = 0 ;
}
T_7 T_8 void F_163 ( void )
{
unsigned V_41 , V_211 ;
F_164 () ;
F_165 () ;
F_166 () ;
V_211 = F_167 () ;
for ( V_41 = V_120 ; V_41 < V_138 ; V_41 ++ ) {
int V_43 ;
unsigned int V_87 ;
struct V_212 * V_213 ;
struct V_28 * V_29 ;
V_43 = F_168 ( V_136 [ V_41 ] ) ;
if ( V_43 <= V_137 )
continue;
V_213 = F_169 ( V_43 ) ;
if ( ! V_213 )
continue;
V_29 = V_28 ( V_43 ) ;
if ( ! V_29 )
continue;
F_89 ( & V_213 -> V_214 ) ;
if ( V_29 -> V_125 )
goto V_215;
if ( V_41 == V_29 -> V_41 && F_112 ( V_211 , V_29 -> V_39 ) )
goto V_215;
V_87 = F_170 ( V_216 + ( V_41 / 32 * 0x10 ) ) ;
if ( V_87 & ( 1 << ( V_41 % 32 ) ) ) {
V_49 -> V_217 ( V_210 ) ;
goto V_215;
}
F_171 ( V_136 [ V_41 ] , - 1 ) ;
V_215:
F_91 ( & V_213 -> V_214 ) ;
}
F_172 () ;
}
static void F_173 ( struct V_28 * V_29 , unsigned V_41 )
{
unsigned V_211 ;
if ( F_109 ( ! V_29 -> V_125 ) )
return;
V_211 = F_167 () ;
if ( V_41 == V_29 -> V_41 && F_112 ( V_211 , V_29 -> V_39 ) )
F_162 ( V_29 ) ;
}
static void F_174 ( struct V_28 * V_29 )
{
F_173 ( V_29 , ~ F_175 () -> V_218 ) ;
}
void F_176 ( int V_43 )
{
struct V_28 * V_29 = F_20 ( V_43 ) ;
if ( ! V_29 )
return;
F_173 ( V_29 , V_29 -> V_41 ) ;
}
static inline void F_174 ( struct V_28 * V_29 ) { }
static void F_177 ( unsigned int V_43 , unsigned int V_154 , struct V_28 * V_29 )
{
int V_49 , V_57 ;
struct V_25 * V_62 ;
T_9 V_41 = V_29 -> V_41 ;
F_45 (entry, cfg->irq_2_pin) {
unsigned int V_52 ;
V_49 = V_62 -> V_49 ;
V_57 = V_62 -> V_57 ;
F_41 ( V_49 , 0x11 + V_57 * 2 , V_154 ) ;
V_52 = F_36 ( V_49 , 0x10 + V_57 * 2 ) ;
V_52 &= ~ V_219 ;
V_52 |= V_41 ;
F_50 ( V_49 , 0x10 + V_57 * 2 , V_52 ) ;
}
}
int F_178 ( struct V_78 * V_54 , const struct V_118 * V_66 ,
unsigned int * V_220 )
{
struct V_28 * V_29 = V_54 -> V_79 ;
unsigned int V_43 = V_54 -> V_43 ;
int V_95 ;
if ( ! F_179 ( V_221 ) )
return - V_222 ;
if ( ! F_99 ( V_66 , V_129 ) )
return - V_223 ;
V_95 = F_106 ( V_43 , V_29 , V_66 ) ;
if ( V_95 )
return V_95 ;
V_95 = V_49 -> V_156 ( V_66 , V_29 -> V_39 , V_220 ) ;
if ( V_95 ) {
if ( F_106 ( V_43 , V_29 , V_54 -> V_224 ) )
F_14 ( L_45 , V_43 ) ;
return V_95 ;
}
F_105 ( V_54 -> V_224 , V_66 ) ;
return 0 ;
}
int F_180 ( struct V_78 * V_54 ,
const struct V_118 * V_66 ,
bool V_225 )
{
unsigned int V_154 , V_43 = V_54 -> V_43 ;
unsigned long V_63 ;
int V_226 ;
if ( ! F_179 ( V_221 ) )
return - V_222 ;
F_38 ( & V_64 , V_63 ) ;
V_226 = F_178 ( V_54 , V_66 , & V_154 ) ;
if ( ! V_226 ) {
V_154 = F_181 ( V_154 ) ;
F_177 ( V_43 , V_154 , V_54 -> V_79 ) ;
V_226 = V_227 ;
}
F_39 ( & V_64 , V_63 ) ;
return V_226 ;
}
static void F_182 ( struct V_78 * V_54 )
{
F_174 ( V_54 -> V_79 ) ;
F_183 ( V_54 ) ;
F_164 () ;
}
static bool F_184 ( struct V_28 * V_29 )
{
struct V_25 * V_62 ;
unsigned long V_63 ;
F_38 ( & V_64 , V_63 ) ;
F_45 (entry, cfg->irq_2_pin) {
unsigned int V_52 ;
int V_57 ;
V_57 = V_62 -> V_57 ;
V_52 = F_36 ( V_62 -> V_49 , 0x10 + V_57 * 2 ) ;
if ( V_52 & V_228 ) {
F_39 ( & V_64 , V_63 ) ;
return true ;
}
}
F_39 ( & V_64 , V_63 ) ;
return false ;
}
static inline bool F_185 ( struct V_78 * V_54 , struct V_28 * V_29 )
{
if ( F_101 ( F_186 ( V_54 ) ) ) {
F_53 ( V_29 ) ;
return true ;
}
return false ;
}
static inline void F_187 ( struct V_78 * V_54 ,
struct V_28 * V_29 , bool V_229 )
{
if ( F_101 ( V_229 ) ) {
if ( ! F_184 ( V_29 ) )
F_188 ( V_54 ) ;
F_56 ( V_29 ) ;
}
}
static inline bool F_185 ( struct V_78 * V_54 , struct V_28 * V_29 )
{
return false ;
}
static inline void F_187 ( struct V_78 * V_54 ,
struct V_28 * V_29 , bool V_229 )
{
}
static void F_189 ( struct V_78 * V_54 )
{
struct V_28 * V_29 = V_54 -> V_79 ;
int V_14 , V_43 = V_54 -> V_43 ;
unsigned long V_230 ;
bool V_229 ;
F_174 ( V_29 ) ;
V_229 = F_185 ( V_54 , V_29 ) ;
V_14 = V_29 -> V_41 ;
V_230 = F_170 ( V_231 + ( ( V_14 & ~ 0x1f ) >> 1 ) ) ;
F_164 () ;
if ( ! ( V_230 & ( 1 << ( V_14 & 0x1f ) ) ) ) {
F_190 ( & V_232 ) ;
F_60 ( V_43 , V_29 ) ;
}
F_187 ( V_54 , V_29 , V_229 ) ;
}
static inline void F_191 ( void )
{
struct V_28 * V_29 ;
unsigned int V_43 ;
F_111 (irq) {
V_29 = F_20 ( V_43 ) ;
if ( F_86 ( V_43 ) && V_29 && ! V_29 -> V_41 ) {
if ( V_43 < V_31 -> V_32 )
V_31 -> V_233 ( V_43 ) ;
else
F_192 ( V_43 , & V_234 ) ;
}
}
}
static void F_193 ( struct V_78 * V_54 )
{
unsigned long V_230 ;
V_230 = F_170 ( V_235 ) ;
F_194 ( V_235 , V_230 | V_236 ) ;
}
static void F_195 ( struct V_78 * V_54 )
{
unsigned long V_230 ;
V_230 = F_170 ( V_235 ) ;
F_194 ( V_235 , V_230 & ~ V_236 ) ;
}
static void F_196 ( struct V_78 * V_54 )
{
F_164 () ;
}
static void F_197 ( int V_43 )
{
F_116 ( V_43 , V_146 ) ;
F_118 ( V_43 , & V_237 , V_148 ,
L_18 ) ;
}
static inline void T_1 F_198 ( void )
{
int V_49 , V_57 , V_14 ;
struct V_36 V_238 , V_80 ;
unsigned char V_239 , V_240 ;
V_57 = F_69 ( 8 , V_139 ) ;
if ( V_57 == - 1 ) {
F_199 ( 1 ) ;
return;
}
V_49 = F_71 ( 8 , V_139 ) ;
if ( V_49 == - 1 ) {
F_199 ( 1 ) ;
return;
}
V_238 = F_37 ( V_49 , V_57 ) ;
F_61 ( V_49 , V_57 ) ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_80 . V_152 = 0 ;
V_80 . V_66 = 0 ;
V_80 . V_154 = F_200 () ;
V_80 . V_85 = V_175 ;
V_80 . V_102 = V_238 . V_102 ;
V_80 . V_81 = 0 ;
V_80 . V_41 = 0 ;
F_42 ( V_49 , V_57 , V_80 ) ;
V_239 = F_201 ( V_241 ) ;
V_240 = F_201 ( V_242 ) ;
F_202 ( ( V_240 & ~ V_243 ) | 0x6 ,
V_242 ) ;
F_202 ( V_239 | V_244 , V_241 ) ;
V_14 = 100 ;
while ( V_14 -- > 0 ) {
F_156 ( 10 ) ;
if ( ( F_201 ( V_245 ) & V_246 ) == V_246 )
V_14 -= 10 ;
}
F_202 ( V_239 , V_241 ) ;
F_202 ( V_240 , V_242 ) ;
F_61 ( V_49 , V_57 ) ;
F_42 ( V_49 , V_57 , V_238 ) ;
}
static int T_1 F_203 ( char * V_169 )
{
V_247 = 1 ;
return 0 ;
}
static inline void T_1 F_204 ( void )
{
struct V_28 * V_29 = F_20 ( 0 ) ;
int V_26 = F_16 ( 0 ) ;
int V_248 , V_249 , V_250 , V_251 ;
unsigned long V_63 ;
int V_252 = 0 ;
F_205 ( V_63 ) ;
V_31 -> V_66 ( 0 ) ;
F_106 ( 0 , V_29 , V_49 -> V_155 () ) ;
F_194 ( V_235 , V_236 | V_253 ) ;
V_31 -> V_254 ( 1 ) ;
V_249 = F_69 ( 0 , V_139 ) ;
V_248 = F_71 ( 0 , V_139 ) ;
V_251 = V_176 . V_57 ;
V_250 = V_176 . V_49 ;
F_8 ( V_255 , V_92 L_46
L_47 ,
V_29 -> V_41 , V_248 , V_249 , V_250 , V_251 ) ;
if ( V_249 == - 1 ) {
F_206 ( L_48 ) ;
V_249 = V_251 ;
V_248 = V_250 ;
V_252 = 1 ;
} else if ( V_251 == - 1 ) {
V_251 = V_249 ;
V_250 = V_248 ;
}
if ( V_249 != - 1 ) {
if ( V_252 ) {
F_46 ( V_29 , V_26 , V_248 , V_249 ) ;
F_129 ( V_248 , V_249 , V_29 -> V_41 ) ;
} else {
int V_100 ;
V_100 = F_68 ( V_248 , V_249 , V_139 ) ;
if ( V_100 != - 1 && F_78 ( V_100 ) )
F_56 ( V_29 ) ;
}
if ( F_153 () ) {
if ( V_247 > 0 )
F_61 ( 0 , V_249 ) ;
goto V_256;
}
F_206 ( L_49 ) ;
F_207 () ;
F_61 ( V_248 , V_249 ) ;
if ( ! V_252 )
F_8 ( V_255 , V_189 L_50
L_51 ) ;
F_8 ( V_255 , V_92 L_52
L_53 ) ;
F_8 ( V_255 , V_92
L_54 , V_250 , V_251 ) ;
F_47 ( V_29 , V_26 , V_248 , V_249 , V_250 , V_251 ) ;
F_129 ( V_250 , V_251 , V_29 -> V_41 ) ;
V_31 -> V_257 ( 0 ) ;
if ( F_153 () ) {
F_8 ( V_255 , V_92 L_55 ) ;
V_258 = 1 ;
goto V_256;
}
F_207 () ;
V_31 -> V_66 ( 0 ) ;
F_61 ( V_250 , V_251 ) ;
F_8 ( V_255 , V_92 L_56 ) ;
}
F_8 ( V_255 , V_92
L_57 ) ;
F_197 ( 0 ) ;
F_194 ( V_235 , V_259 | V_29 -> V_41 ) ;
V_31 -> V_257 ( 0 ) ;
if ( F_153 () ) {
F_8 ( V_255 , V_92 L_58 ) ;
goto V_256;
}
F_207 () ;
V_31 -> V_66 ( 0 ) ;
F_194 ( V_235 , V_236 | V_259 | V_29 -> V_41 ) ;
F_8 ( V_255 , V_92 L_59 ) ;
F_8 ( V_255 , V_92
L_60 ) ;
V_31 -> V_254 ( 0 ) ;
V_31 -> V_233 ( 0 ) ;
F_194 ( V_235 , V_253 ) ;
F_198 () ;
if ( F_153 () ) {
F_8 ( V_255 , V_92 L_58 ) ;
goto V_256;
}
F_207 () ;
F_8 ( V_255 , V_92 L_61 ) ;
if ( V_260 )
F_8 ( V_255 , V_92
L_62
L_63 ) ;
F_9 ( L_64
L_65 ) ;
V_256:
F_157 ( V_63 ) ;
}
void T_1 F_208 ( void )
{
V_33 = V_31 -> V_32 ? ~ V_261 : ~ 0UL ;
F_8 ( V_15 , L_66 ) ;
V_262 . V_263 . V_264 () ;
F_209 () ;
F_124 () ;
F_191 () ;
if ( V_31 -> V_32 )
F_204 () ;
}
static int T_1 F_210 ( void )
{
if ( V_56 == - 1 )
V_56 = 0 ;
return 0 ;
}
static void F_211 ( int V_1 )
{
unsigned long V_63 ;
union V_182 V_183 ;
F_38 ( & V_64 , V_63 ) ;
V_183 . V_188 = F_36 ( V_1 , 0 ) ;
if ( V_183 . V_190 . V_191 != F_1 ( V_1 ) ) {
V_183 . V_190 . V_191 = F_1 ( V_1 ) ;
F_41 ( V_1 , 0 , V_183 . V_188 ) ;
}
F_39 ( & V_64 , V_63 ) ;
}
static void F_212 ( void )
{
int V_1 ;
for ( V_1 = V_34 - 1 ; V_1 >= 0 ; V_1 -- )
F_211 ( V_1 ) ;
F_67 () ;
}
static int T_1 F_213 ( void )
{
F_214 ( & V_265 ) ;
return 0 ;
}
int F_215 ( unsigned int V_43 , int V_26 )
{
struct V_28 * V_29 ;
unsigned long V_63 ;
int V_226 ;
V_29 = F_21 ( V_43 , V_26 ) ;
if ( ! V_29 )
return - V_70 ;
F_38 ( & V_117 , V_63 ) ;
V_226 = F_92 ( V_43 , V_29 , V_49 -> V_155 () ) ;
F_39 ( & V_117 , V_63 ) ;
if ( ! V_226 )
F_17 ( V_43 , V_29 ) ;
else
F_24 ( V_43 , V_29 ) ;
return V_226 ;
}
void F_216 ( unsigned int V_43 )
{
struct V_28 * V_29 = F_20 ( V_43 ) ;
unsigned long V_63 ;
F_217 ( V_43 ) ;
F_38 ( & V_117 , V_63 ) ;
F_107 ( V_43 , V_29 ) ;
F_39 ( & V_117 , V_63 ) ;
F_24 ( V_43 , V_29 ) ;
}
void F_218 ( struct V_266 * V_267 ,
unsigned int V_43 , unsigned int V_154 ,
struct V_268 * V_269 , T_9 V_270 )
{
struct V_28 * V_29 = V_28 ( V_43 ) ;
V_269 -> V_271 = V_272 ;
if ( F_219 () )
V_269 -> V_271 |= F_220 ( V_154 ) ;
V_269 -> V_273 =
V_274 |
( ( V_49 -> V_153 == 0 ) ?
V_275 :
V_276 ) |
( ( V_49 -> V_151 != V_277 ) ?
V_278 :
V_279 ) |
F_221 ( V_154 ) ;
V_269 -> V_54 =
V_280 |
V_281 |
( ( V_49 -> V_151 != V_277 ) ?
V_282 :
V_283 ) |
F_222 ( V_29 -> V_41 ) ;
}
static int F_223 ( struct V_266 * V_267 , unsigned int V_43 ,
struct V_268 * V_269 , T_9 V_270 )
{
struct V_28 * V_29 ;
int V_95 ;
unsigned V_154 ;
if ( V_284 )
return - V_285 ;
V_29 = V_28 ( V_43 ) ;
V_95 = F_106 ( V_43 , V_29 , V_49 -> V_155 () ) ;
if ( V_95 )
return V_95 ;
V_95 = V_49 -> V_156 ( V_29 -> V_39 ,
V_49 -> V_155 () , & V_154 ) ;
if ( V_95 )
return V_95 ;
V_286 . V_287 ( V_267 , V_43 , V_154 , V_269 , V_270 ) ;
return 0 ;
}
static int
F_224 ( struct V_78 * V_54 , const struct V_118 * V_66 , bool V_225 )
{
struct V_28 * V_29 = V_54 -> V_79 ;
struct V_268 V_269 ;
unsigned int V_154 ;
int V_226 ;
V_226 = F_178 ( V_54 , V_66 , & V_154 ) ;
if ( V_226 )
return V_226 ;
F_225 ( V_54 -> V_288 , & V_269 ) ;
V_269 . V_54 &= ~ V_289 ;
V_269 . V_54 |= F_222 ( V_29 -> V_41 ) ;
V_269 . V_273 &= ~ V_290 ;
V_269 . V_273 |= F_221 ( V_154 ) ;
F_226 ( V_54 -> V_288 , & V_269 ) ;
return V_227 ;
}
int F_227 ( struct V_266 * V_291 , struct V_288 * V_292 ,
unsigned int V_293 , unsigned int V_294 )
{
struct V_140 * V_141 = & V_295 ;
struct V_268 V_269 ;
unsigned int V_43 = V_293 + V_294 ;
int V_226 ;
V_226 = F_223 ( V_291 , V_43 , & V_269 , - 1 ) ;
if ( V_226 < 0 )
return V_226 ;
F_228 ( V_293 , V_294 , V_292 ) ;
if ( ! V_294 )
F_229 ( V_43 , & V_269 ) ;
F_117 ( V_43 , F_20 ( V_43 ) , V_141 ) ;
F_118 ( V_43 , V_141 , V_148 , L_18 ) ;
F_230 ( V_93 , & V_291 -> V_291 , L_67 , V_43 ) ;
return 0 ;
}
int F_231 ( struct V_266 * V_291 , int V_296 , int type )
{
struct V_288 * V_292 ;
unsigned int V_43 ;
int V_26 , V_226 ;
if ( type == V_297 && V_296 > 1 )
return 1 ;
V_26 = F_232 ( & V_291 -> V_291 ) ;
F_233 (msidesc, &dev->msi_list, list) {
V_43 = F_234 ( V_26 ) ;
if ( ! V_43 )
return - V_128 ;
V_226 = F_227 ( V_291 , V_292 , V_43 , 0 ) ;
if ( V_226 < 0 ) {
F_235 ( V_43 ) ;
return V_226 ;
}
}
return 0 ;
}
void F_236 ( unsigned int V_43 )
{
F_235 ( V_43 ) ;
}
static int
F_237 ( struct V_78 * V_54 , const struct V_118 * V_66 ,
bool V_225 )
{
struct V_28 * V_29 = V_54 -> V_79 ;
unsigned int V_154 , V_43 = V_54 -> V_43 ;
struct V_268 V_269 ;
int V_226 ;
V_226 = F_178 ( V_54 , V_66 , & V_154 ) ;
if ( V_226 )
return V_226 ;
F_238 ( V_43 , & V_269 ) ;
V_269 . V_54 &= ~ V_289 ;
V_269 . V_54 |= F_222 ( V_29 -> V_41 ) ;
V_269 . V_273 &= ~ V_290 ;
V_269 . V_273 |= F_221 ( V_154 ) ;
V_269 . V_271 = V_272 | F_220 ( V_154 ) ;
F_239 ( V_43 , & V_269 ) ;
return V_227 ;
}
int F_240 ( unsigned int V_43 )
{
int V_226 ;
struct V_268 V_269 ;
V_226 = F_223 ( NULL , V_43 , & V_269 , - 1 ) ;
if ( V_226 < 0 )
return V_226 ;
F_239 ( V_43 , & V_269 ) ;
F_118 ( V_43 , & V_298 , V_148 ,
L_18 ) ;
return 0 ;
}
static int F_241 ( struct V_78 * V_54 ,
const struct V_118 * V_66 , bool V_225 )
{
struct V_28 * V_29 = V_54 -> V_79 ;
struct V_268 V_269 ;
unsigned int V_154 ;
int V_226 ;
V_226 = F_178 ( V_54 , V_66 , & V_154 ) ;
if ( V_226 )
return V_226 ;
F_242 ( V_54 -> V_299 , & V_269 ) ;
V_269 . V_54 &= ~ V_289 ;
V_269 . V_54 |= F_222 ( V_29 -> V_41 ) ;
V_269 . V_273 &= ~ V_290 ;
V_269 . V_273 |= F_221 ( V_154 ) ;
F_243 ( V_54 -> V_299 , & V_269 ) ;
return V_227 ;
}
int F_244 ( unsigned int V_43 , unsigned int V_300 )
{
struct V_140 * V_141 = & V_301 ;
struct V_268 V_269 ;
int V_226 ;
V_226 = F_223 ( NULL , V_43 , & V_269 , V_300 ) ;
if ( V_226 < 0 )
return V_226 ;
F_243 ( F_245 ( V_43 ) , & V_269 ) ;
F_115 ( V_43 , V_302 ) ;
F_117 ( V_43 , F_20 ( V_43 ) , V_141 ) ;
F_118 ( V_43 , V_141 , V_148 , L_18 ) ;
return 0 ;
}
static void F_246 ( unsigned int V_43 , unsigned int V_154 , T_9 V_41 )
{
struct V_303 V_269 ;
F_247 ( V_43 , & V_269 ) ;
V_269 . V_273 &= ~ ( V_304 | V_305 ) ;
V_269 . V_271 &= ~ ( V_306 ) ;
V_269 . V_273 |= F_248 ( V_41 ) | F_249 ( V_154 ) ;
V_269 . V_271 |= F_250 ( V_154 ) ;
F_251 ( V_43 , & V_269 ) ;
}
static int
F_252 ( struct V_78 * V_54 , const struct V_118 * V_66 , bool V_225 )
{
struct V_28 * V_29 = V_54 -> V_79 ;
unsigned int V_154 ;
int V_226 ;
V_226 = F_178 ( V_54 , V_66 , & V_154 ) ;
if ( V_226 )
return V_226 ;
F_246 ( V_54 -> V_43 , V_154 , V_29 -> V_41 ) ;
return V_227 ;
}
int F_253 ( unsigned int V_43 , struct V_266 * V_291 )
{
struct V_28 * V_29 ;
struct V_303 V_269 ;
unsigned V_154 ;
int V_95 ;
if ( V_284 )
return - V_285 ;
V_29 = V_28 ( V_43 ) ;
V_95 = F_106 ( V_43 , V_29 , V_49 -> V_155 () ) ;
if ( V_95 )
return V_95 ;
V_95 = V_49 -> V_156 ( V_29 -> V_39 ,
V_49 -> V_155 () , & V_154 ) ;
if ( V_95 )
return V_95 ;
V_269 . V_271 = F_250 ( V_154 ) ;
V_269 . V_273 =
V_307 |
F_249 ( V_154 ) |
F_248 ( V_29 -> V_41 ) |
( ( V_49 -> V_153 == 0 ) ?
V_308 :
V_309 ) |
V_310 |
( ( V_49 -> V_151 != V_277 ) ?
V_311 :
V_312 ) |
V_313 ;
F_251 ( V_43 , & V_269 ) ;
F_118 ( V_43 , & V_314 ,
V_148 , L_18 ) ;
F_230 ( V_93 , & V_291 -> V_291 , L_68 , V_43 ) ;
return 0 ;
}
static int
F_123 ( unsigned int V_43 , int V_26 , struct V_113 * V_150 )
{
struct V_28 * V_29 = F_25 ( V_43 , V_26 ) ;
int V_226 ;
if ( ! V_29 )
return - V_223 ;
V_226 = F_44 ( V_29 , V_26 , V_150 -> V_157 , V_150 -> V_158 ) ;
if ( ! V_226 )
F_120 ( V_43 , V_29 , V_150 ) ;
return V_226 ;
}
int F_128 ( unsigned int V_43 , int V_26 ,
struct V_113 * V_150 )
{
unsigned int V_1 = V_150 -> V_157 , V_57 = V_150 -> V_158 ;
int V_226 ;
struct V_36 V_315 ;
if ( F_70 ( V_57 , V_2 [ V_1 ] . V_316 ) ) {
F_131 ( L_69 , F_1 ( V_1 ) , V_57 ) ;
V_315 = F_37 ( V_150 -> V_157 , V_57 ) ;
if ( V_150 -> V_81 == V_315 . V_81 && V_150 -> V_102 == V_315 . V_102 )
return 0 ;
return - V_126 ;
}
V_226 = F_123 ( V_43 , V_26 , V_150 ) ;
if ( ! V_226 )
F_254 ( V_57 , V_2 [ V_1 ] . V_316 ) ;
return V_226 ;
}
static int T_1 F_255 ( int V_157 )
{
union V_317 V_318 ;
unsigned long V_63 ;
F_38 ( & V_64 , V_63 ) ;
V_318 . V_188 = F_36 ( V_157 , 1 ) ;
F_39 ( & V_64 , V_63 ) ;
return V_318 . V_190 . V_319 + 1 ;
}
static void T_1 F_256 ( void )
{
int V_320 ;
V_320 = V_111 + V_110 ;
if ( V_320 > V_321 )
V_321 = V_320 ;
F_139 ( V_93 L_70 , V_321 ) ;
}
unsigned int F_257 ( unsigned int V_322 )
{
return V_322 < V_321 ? V_321 : V_322 ;
}
int T_1 F_258 ( void )
{
int V_320 ;
if ( V_323 > ( V_138 * V_130 ) )
V_323 = V_138 * V_130 ;
V_320 = V_321 + 8 * V_130 ;
#if F_259 ( V_324 ) || F_259 ( V_325 )
V_320 += V_321 * 16 ;
#endif
if ( V_320 < V_323 )
V_323 = V_320 ;
return V_110 ;
}
int F_260 ( struct V_326 * V_291 , int V_43 ,
struct V_113 * V_114 )
{
int V_26 ;
if ( ! F_86 ( V_43 ) ) {
F_8 ( V_255 , V_189 L_71 ,
V_114 -> V_157 ) ;
return - V_223 ;
}
V_26 = V_291 ? F_232 ( V_291 ) : F_16 ( 0 ) ;
return F_128 ( V_43 , V_26 , V_114 ) ;
}
static int T_1 F_261 ( int V_157 , int V_327 )
{
union V_182 V_183 ;
static T_6 V_328 = V_329 ;
T_6 V_193 ;
unsigned long V_63 ;
int V_14 = 0 ;
if ( F_262 ( V_328 ) )
V_49 -> V_186 ( & V_187 , & V_328 ) ;
F_38 ( & V_64 , V_63 ) ;
V_183 . V_188 = F_36 ( V_157 , 0 ) ;
F_39 ( & V_64 , V_63 ) ;
if ( V_327 >= F_146 () ) {
F_139 ( V_179 L_72
L_73 , V_157 , V_327 , V_183 . V_190 . V_191 ) ;
V_327 = V_183 . V_190 . V_191 ;
}
if ( V_49 -> V_192 ( & V_328 , V_327 ) ) {
for ( V_14 = 0 ; V_14 < F_146 () ; V_14 ++ ) {
if ( ! V_49 -> V_192 ( & V_328 , V_14 ) )
break;
}
if ( V_14 == F_146 () )
F_9 ( L_74 ) ;
F_139 ( V_179 L_75
L_76 , V_157 , V_327 , V_14 ) ;
V_327 = V_14 ;
}
V_49 -> V_194 ( V_327 , & V_193 ) ;
F_149 ( V_328 , V_328 , V_193 ) ;
if ( V_183 . V_190 . V_191 != V_327 ) {
V_183 . V_190 . V_191 = V_327 ;
F_38 ( & V_64 , V_63 ) ;
F_41 ( V_157 , 0 , V_183 . V_188 ) ;
V_183 . V_188 = F_36 ( V_157 , 0 ) ;
F_39 ( & V_64 , V_63 ) ;
if ( V_183 . V_190 . V_191 != V_327 ) {
F_14 ( L_77 ,
V_157 ) ;
return - 1 ;
}
}
F_8 ( V_15 , V_92
L_78 , V_157 , V_327 ) ;
return V_327 ;
}
static T_9 T_1 F_263 ( T_9 V_300 )
{
if ( ( V_196 . V_197 == V_198 ) &&
! F_151 ( V_199 [ V_200 ] ) )
return F_261 ( V_34 , V_300 ) ;
else
return V_300 ;
}
static T_9 T_1 F_263 ( T_9 V_300 )
{
int V_14 ;
F_264 ( V_330 , 256 ) ;
F_265 ( V_330 , 256 ) ;
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
F_266 ( F_1 ( V_14 ) , V_330 ) ;
}
if ( ! F_70 ( V_300 , V_330 ) )
return V_300 ;
return F_267 ( V_330 , 256 ) ;
}
static int T_1 F_268 ( int V_157 )
{
union V_317 V_318 ;
unsigned long V_63 ;
F_38 ( & V_64 , V_63 ) ;
V_318 . V_188 = F_36 ( V_157 , 1 ) ;
F_39 ( & V_64 , V_63 ) ;
return V_318 . V_190 . V_331 ;
}
int F_269 ( T_3 V_108 , int * V_81 , int * V_102 )
{
int V_157 , V_57 , V_100 ;
if ( V_10 )
return - 1 ;
V_157 = F_126 ( V_108 ) ;
if ( V_157 < 0 )
return - 1 ;
V_57 = F_127 ( V_157 , V_108 ) ;
if ( V_57 < 0 )
return - 1 ;
V_100 = F_68 ( V_157 , V_57 , V_139 ) ;
if ( V_100 < 0 )
return - 1 ;
* V_81 = F_78 ( V_100 ) ;
* V_102 = F_74 ( V_100 ) ;
return 0 ;
}
void T_1 F_270 ( void )
{
int V_57 , V_157 , V_43 , V_332 ;
const struct V_118 * V_66 ;
struct V_78 * V_333 ;
if ( V_10 == 1 )
return;
for ( V_157 = 0 ; V_157 < V_34 ; V_157 ++ )
for ( V_57 = 0 ; V_57 < V_2 [ V_157 ] . V_37 ; V_57 ++ ) {
V_332 = F_68 ( V_157 , V_57 , V_139 ) ;
if ( V_332 == - 1 )
continue;
V_43 = F_83 ( V_332 , V_157 , V_57 ) ;
if ( ( V_157 > 0 ) && ( V_43 > 16 ) )
continue;
V_333 = F_271 ( V_43 ) ;
if ( ! F_272 ( V_333 ) || F_273 ( V_333 ) )
V_66 = V_333 -> V_224 ;
else
V_66 = V_49 -> V_155 () ;
V_83 . V_334 ( V_333 , V_66 , false ) ;
}
}
static struct V_335 * T_1 F_274 ( int V_34 )
{
unsigned long V_336 ;
struct V_335 * V_47 ;
char * V_337 ;
int V_14 ;
if ( V_34 <= 0 )
return NULL ;
V_336 = V_338 + sizeof( struct V_335 ) ;
V_336 *= V_34 ;
V_337 = F_275 ( V_336 ) ;
V_47 = ( void * ) V_337 ;
V_337 += sizeof( struct V_335 ) * V_34 ;
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
V_47 [ V_14 ] . V_339 = V_337 ;
V_47 [ V_14 ] . V_63 = V_340 | V_341 ;
snprintf ( V_337 , V_338 , L_79 , V_14 ) ;
V_337 += V_338 ;
}
V_342 = V_47 ;
return V_47 ;
}
void T_1 F_276 ( void )
{
unsigned long V_343 , V_100 = V_344 ;
struct V_335 * V_345 ;
int V_14 ;
V_345 = F_274 ( V_34 ) ;
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
if ( V_346 ) {
V_343 = F_2 ( V_14 ) ;
#ifdef F_84
if ( ! V_343 ) {
F_139 ( V_189
L_80
L_81
L_82 ) ;
V_346 = 0 ;
V_10 = 1 ;
goto V_347;
}
#endif
} else {
#ifdef F_84
V_347:
#endif
V_343 = ( unsigned long ) F_277 ( V_348 ) ;
V_343 = F_278 ( V_343 ) ;
}
F_279 ( V_100 , V_343 ) ;
F_8 ( V_15 , L_83 ,
F_280 ( V_100 ) + ( V_343 & ~ V_349 ) ,
V_343 ) ;
V_100 ++ ;
V_345 -> V_350 = V_343 ;
V_345 -> V_351 = V_343 + V_352 - 1 ;
V_345 ++ ;
}
F_256 () ;
}
void T_1 F_281 ( void )
{
int V_14 ;
struct V_335 * V_353 = V_342 ;
if ( ! V_353 ) {
if ( V_34 > 0 )
F_139 ( V_189
L_84 ) ;
return;
}
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
F_282 ( & V_354 , V_353 ) ;
V_353 ++ ;
}
}
int F_126 ( T_3 V_108 )
{
int V_14 = 0 ;
if ( V_34 == 0 )
return - 1 ;
for ( V_14 = 0 ; V_14 < V_34 ; V_14 ++ ) {
struct V_6 * V_107 = F_3 ( V_14 ) ;
if ( ( V_108 >= V_107 -> V_109 )
&& ( V_108 <= V_107 -> V_355 ) )
return V_14 ;
}
F_139 ( V_189 L_85 , V_108 ) ;
return - 1 ;
}
int F_127 ( int V_157 , T_3 V_108 )
{
struct V_6 * V_107 ;
if ( F_283 ( V_157 == - 1 ) )
return - 1 ;
V_107 = F_3 ( V_157 ) ;
if ( F_283 ( V_108 > V_107 -> V_355 ) )
return - 1 ;
return V_108 - V_107 -> V_109 ;
}
static T_1 int F_284 ( unsigned long V_356 )
{
if ( V_34 >= V_357 ) {
F_77 ( L_86 ,
V_357 , V_34 ) ;
return 1 ;
}
if ( ! V_356 ) {
F_77 ( L_87 ) ;
return 1 ;
}
return 0 ;
}
static T_1 int F_285 ( int V_100 )
{
union V_182 V_183 ;
union V_317 V_318 ;
union V_358 V_359 ;
V_183 . V_188 = F_36 ( V_100 , 0 ) ;
V_318 . V_188 = F_36 ( V_100 , 1 ) ;
V_359 . V_188 = F_36 ( V_100 , 2 ) ;
if ( V_183 . V_188 == - 1 && V_318 . V_188 == - 1 && V_359 . V_188 == - 1 ) {
F_77 ( L_88 ,
F_2 ( V_100 ) ) ;
return 1 ;
}
return 0 ;
}
void T_1 F_286 ( int V_300 , T_3 V_356 , T_3 V_109 )
{
int V_100 = 0 ;
int V_319 ;
struct V_6 * V_107 ;
if ( F_284 ( V_356 ) )
return;
V_100 = V_34 ;
V_2 [ V_100 ] . V_3 . type = V_360 ;
V_2 [ V_100 ] . V_3 . V_63 = V_361 ;
V_2 [ V_100 ] . V_3 . V_5 = V_356 ;
F_279 ( V_344 + V_100 , V_356 ) ;
if ( F_285 ( V_100 ) ) {
F_287 ( V_344 + V_100 ) ;
return;
}
V_2 [ V_100 ] . V_3 . V_4 = F_263 ( V_300 ) ;
V_2 [ V_100 ] . V_3 . V_362 = F_268 ( V_100 ) ;
V_319 = F_255 ( V_100 ) ;
V_107 = F_3 ( V_100 ) ;
V_107 -> V_109 = V_109 ;
V_107 -> V_355 = V_109 + V_319 - 1 ;
V_2 [ V_100 ] . V_37 = V_319 ;
if ( V_107 -> V_355 >= V_111 )
V_111 = V_107 -> V_355 + 1 ;
F_288 ( L_89 ,
V_100 , F_1 ( V_100 ) ,
F_59 ( V_100 ) , F_2 ( V_100 ) ,
V_107 -> V_109 , V_107 -> V_355 ) ;
V_34 ++ ;
}
void T_1 F_289 ( void )
{
struct V_113 V_150 = { 0 , 0 , 0 , 0 } ;
F_139 ( V_92 L_90 ) ;
#ifndef V_221
F_290 ( V_200 ,
& V_187 ) ;
#endif
F_291 () ;
F_123 ( 0 , 0 , & V_150 ) ;
F_118 ( 0 , & V_142 , V_148 ,
L_18 ) ;
}
