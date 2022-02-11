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
static inline int F_4 ( int V_8 )
{
struct V_6 * V_9 = F_3 ( V_8 ) ;
return V_9 -> V_10 - V_9 -> V_11 + 1 ;
}
T_1 F_5 ( int V_8 , int V_12 )
{
return F_3 ( V_8 ) -> V_11 + V_12 ;
}
static inline int F_6 ( int V_8 , int V_13 )
{
if ( ! F_7 () )
return 0 ;
return V_8 == 0 || ( V_13 >= 0 && V_13 < F_7 () ) ;
}
static inline struct V_14 * V_14 ( int V_1 , int V_12 )
{
return V_2 [ V_1 ] . V_15 + V_12 ;
}
static inline struct V_16 * F_8 ( int V_8 )
{
return V_2 [ V_8 ] . V_17 ;
}
void F_9 ( void )
{
#ifdef F_10
V_18 = 1 ;
V_19 = - 1 ;
#endif
V_20 = 1 ;
}
static int T_2 F_11 ( char * V_21 )
{
F_9 () ;
return 0 ;
}
void F_12 ( struct V_22 * V_23 )
{
int V_24 ;
F_13 ( V_25 , L_1
L_2 ,
V_23 -> V_26 , V_23 -> V_27 & 3 , ( V_23 -> V_27 >> 2 ) & 3 , V_23 -> V_28 ,
V_23 -> V_29 , V_23 -> V_30 , V_23 -> V_31 ) ;
for ( V_24 = 0 ; V_24 < V_32 ; V_24 ++ ) {
if ( ! memcmp ( & V_33 [ V_24 ] , V_23 , sizeof( * V_23 ) ) )
return;
}
memcpy ( & V_33 [ V_32 ] , V_23 , sizeof( * V_23 ) ) ;
if ( ++ V_32 == V_34 )
F_14 ( L_3 ) ;
}
static struct V_35 * F_15 ( int V_36 )
{
return F_16 ( sizeof( struct V_35 ) , V_37 , V_36 ) ;
}
int T_2 F_17 ( void )
{
struct V_38 * V_39 ;
int V_24 , V_36 = F_18 ( 0 ) ;
if ( ! F_7 () )
V_40 = ~ 0UL ;
F_19 (i) {
V_2 [ V_24 ] . V_41 =
F_20 ( sizeof( struct V_42 ) *
V_2 [ V_24 ] . V_43 , V_37 ) ;
if ( ! V_2 [ V_24 ] . V_41 )
F_21 ( L_4 , V_24 ) ;
}
for ( V_24 = 0 ; V_24 < F_7 () ; V_24 ++ ) {
V_39 = F_22 ( V_24 , V_36 ) ;
V_39 -> V_44 = V_45 + V_24 ;
F_23 ( V_39 -> V_46 ) ;
}
return 0 ;
}
static inline struct V_38 * V_38 ( unsigned int V_13 )
{
return F_24 ( V_13 ) ;
}
static struct V_38 * F_25 ( unsigned int V_13 , int V_36 )
{
struct V_38 * V_39 ;
V_39 = F_16 ( sizeof( * V_39 ) , V_37 , V_36 ) ;
if ( ! V_39 )
return NULL ;
if ( ! F_26 ( & V_39 -> V_46 , V_37 , V_36 ) )
goto V_47;
if ( ! F_26 ( & V_39 -> V_48 , V_37 , V_36 ) )
goto V_49;
return V_39 ;
V_49:
F_27 ( V_39 -> V_46 ) ;
V_47:
F_28 ( V_39 ) ;
return NULL ;
}
static void F_29 ( unsigned int V_50 , struct V_38 * V_39 )
{
if ( ! V_39 )
return;
F_30 ( V_50 , NULL ) ;
F_27 ( V_39 -> V_46 ) ;
F_27 ( V_39 -> V_48 ) ;
F_28 ( V_39 ) ;
}
static struct V_38 * F_22 ( unsigned int V_50 , int V_36 )
{
int V_51 = F_31 ( V_50 , V_36 ) ;
struct V_38 * V_39 ;
if ( V_51 < 0 ) {
if ( V_51 != - V_52 )
return NULL ;
V_39 = V_38 ( V_50 ) ;
if ( V_39 )
return V_39 ;
}
V_39 = F_25 ( V_50 , V_36 ) ;
if ( V_39 )
F_30 ( V_50 , V_39 ) ;
else
F_32 ( V_50 ) ;
return V_39 ;
}
void F_33 ( unsigned int V_53 , unsigned int V_44 )
{
struct V_54 T_3 * V_54 = F_34 ( V_53 ) ;
F_35 ( V_44 , & V_54 -> V_55 ) ;
}
unsigned int F_36 ( unsigned int V_53 , unsigned int V_56 )
{
struct V_54 T_3 * V_54 = F_34 ( V_53 ) ;
F_35 ( V_56 , & V_54 -> V_57 ) ;
return F_37 ( & V_54 -> V_58 ) ;
}
void F_38 ( unsigned int V_53 , unsigned int V_56 , unsigned int V_59 )
{
struct V_54 T_3 * V_54 = F_34 ( V_53 ) ;
F_35 ( V_56 , & V_54 -> V_57 ) ;
F_35 ( V_59 , & V_54 -> V_58 ) ;
}
void F_39 ( unsigned int V_53 , unsigned int V_56 , unsigned int V_59 )
{
struct V_54 T_3 * V_54 = F_34 ( V_53 ) ;
if ( V_60 )
F_35 ( V_56 , & V_54 -> V_57 ) ;
F_35 ( V_59 , & V_54 -> V_58 ) ;
}
static struct V_42 F_40 ( int V_53 , int V_12 )
{
union V_61 V_62 ;
V_62 . V_63 = F_41 ( V_53 , 0x10 + 2 * V_12 ) ;
V_62 . V_64 = F_41 ( V_53 , 0x11 + 2 * V_12 ) ;
return V_62 . V_65 ;
}
static struct V_42 F_42 ( int V_53 , int V_12 )
{
union V_61 V_62 ;
unsigned long V_66 ;
F_43 ( & V_67 , V_66 ) ;
V_62 . V_65 = F_40 ( V_53 , V_12 ) ;
F_44 ( & V_67 , V_66 ) ;
return V_62 . V_65 ;
}
static void F_45 ( int V_53 , int V_12 , struct V_42 V_68 )
{
union V_61 V_62 = { { 0 , 0 } } ;
V_62 . V_65 = V_68 ;
F_46 ( V_53 , 0x11 + 2 * V_12 , V_62 . V_64 ) ;
F_46 ( V_53 , 0x10 + 2 * V_12 , V_62 . V_63 ) ;
}
static void F_47 ( int V_53 , int V_12 , struct V_42 V_68 )
{
unsigned long V_66 ;
F_43 ( & V_67 , V_66 ) ;
F_45 ( V_53 , V_12 , V_68 ) ;
F_44 ( & V_67 , V_66 ) ;
}
static void F_48 ( int V_53 , int V_12 )
{
unsigned long V_66 ;
union V_61 V_62 = { . V_65 . V_69 = 1 } ;
F_43 ( & V_67 , V_66 ) ;
F_46 ( V_53 , 0x10 + 2 * V_12 , V_62 . V_63 ) ;
F_46 ( V_53 , 0x11 + 2 * V_12 , V_62 . V_64 ) ;
F_44 ( & V_67 , V_66 ) ;
}
static int F_49 ( struct V_38 * V_39 , int V_36 , int V_53 , int V_12 )
{
struct V_35 * * V_70 , * V_65 ;
V_70 = & V_39 -> V_71 ;
F_50 (entry, cfg->irq_2_pin) {
if ( V_65 -> V_53 == V_53 && V_65 -> V_12 == V_12 )
return 0 ;
V_70 = & V_65 -> V_72 ;
}
V_65 = F_15 ( V_36 ) ;
if ( ! V_65 ) {
F_21 ( L_5 ,
V_36 , V_53 , V_12 ) ;
return - V_73 ;
}
V_65 -> V_53 = V_53 ;
V_65 -> V_12 = V_12 ;
* V_70 = V_65 ;
return 0 ;
}
static void F_51 ( struct V_38 * V_39 , int V_53 , int V_12 )
{
struct V_35 * * V_70 , * V_65 ;
V_70 = & V_39 -> V_71 ;
F_50 (entry, cfg->irq_2_pin)
if ( V_65 -> V_53 == V_53 && V_65 -> V_12 == V_12 ) {
* V_70 = V_65 -> V_72 ;
F_28 ( V_65 ) ;
return;
} else {
V_70 = & V_65 -> V_72 ;
}
}
static void F_52 ( struct V_38 * V_39 , int V_36 , int V_53 , int V_12 )
{
if ( F_49 ( V_39 , V_36 , V_53 , V_12 ) )
F_14 ( L_6 ) ;
}
static void T_2 F_53 ( struct V_38 * V_39 , int V_36 ,
int V_74 , int V_75 ,
int V_76 , int V_77 )
{
struct V_35 * V_65 ;
F_50 (entry, cfg->irq_2_pin) {
if ( V_65 -> V_53 == V_74 && V_65 -> V_12 == V_75 ) {
V_65 -> V_53 = V_76 ;
V_65 -> V_12 = V_77 ;
return;
}
}
F_52 ( V_39 , V_36 , V_76 , V_77 ) ;
}
static void F_54 ( struct V_35 * V_65 ,
int V_78 , int V_79 ,
void (* F_55)( struct V_35 * V_65 ) )
{
unsigned int V_56 , V_12 ;
V_12 = V_65 -> V_12 ;
V_56 = F_41 ( V_65 -> V_53 , 0x10 + V_12 * 2 ) ;
V_56 &= V_78 ;
V_56 |= V_79 ;
F_56 ( V_65 -> V_53 , 0x10 + V_12 * 2 , V_56 ) ;
if ( F_55 )
F_55 ( V_65 ) ;
}
static void F_57 ( struct V_38 * V_39 ,
int V_78 , int V_79 ,
void (* F_55)( struct V_35 * V_65 ) )
{
struct V_35 * V_65 ;
F_50 (entry, cfg->irq_2_pin)
F_54 ( V_65 , V_78 , V_79 , F_55 ) ;
}
static void F_58 ( struct V_35 * V_65 )
{
struct V_54 T_3 * V_54 ;
V_54 = F_34 ( V_65 -> V_53 ) ;
F_37 ( & V_54 -> V_58 ) ;
}
static void F_59 ( struct V_38 * V_39 )
{
unsigned long V_66 ;
F_43 ( & V_67 , V_66 ) ;
F_57 ( V_39 , ~ 0 , V_80 , & F_58 ) ;
F_44 ( & V_67 , V_66 ) ;
}
static void F_60 ( struct V_81 * V_58 )
{
F_59 ( V_58 -> V_82 ) ;
}
static void F_61 ( struct V_38 * V_39 )
{
F_57 ( V_39 , ~ V_80 , 0 , NULL ) ;
}
static void F_62 ( struct V_38 * V_39 )
{
unsigned long V_66 ;
F_43 ( & V_67 , V_66 ) ;
F_61 ( V_39 ) ;
F_44 ( & V_67 , V_66 ) ;
}
static void F_63 ( struct V_81 * V_58 )
{
F_62 ( V_58 -> V_82 ) ;
}
void F_64 ( int V_53 , int V_12 , int V_44 )
{
if ( F_65 ( V_53 ) >= 0x20 ) {
F_33 ( V_53 , V_44 ) ;
} else {
struct V_42 V_65 , V_83 ;
V_65 = V_83 = F_40 ( V_53 , V_12 ) ;
V_83 . V_69 = 1 ;
V_83 . V_84 = V_85 ;
F_45 ( V_53 , V_12 , V_83 ) ;
F_45 ( V_53 , V_12 , V_65 ) ;
}
}
void F_66 ( unsigned int V_13 , struct V_38 * V_39 )
{
struct V_35 * V_65 ;
unsigned long V_66 ;
F_43 ( & V_67 , V_66 ) ;
F_50 (entry, cfg->irq_2_pin)
V_86 . V_87 ( V_65 -> V_53 , V_65 -> V_12 ,
V_39 -> V_44 ) ;
F_44 ( & V_67 , V_66 ) ;
}
static void F_67 ( unsigned int V_53 , unsigned int V_12 )
{
struct V_42 V_65 ;
V_65 = F_42 ( V_53 , V_12 ) ;
if ( V_65 . V_88 == V_89 )
return;
if ( ! V_65 . V_69 ) {
V_65 . V_69 = 1 ;
F_47 ( V_53 , V_12 , V_65 ) ;
V_65 = F_42 ( V_53 , V_12 ) ;
}
if ( V_65 . V_90 ) {
unsigned long V_66 ;
if ( ! V_65 . V_84 ) {
V_65 . V_84 = V_91 ;
F_47 ( V_53 , V_12 , V_65 ) ;
}
F_43 ( & V_67 , V_66 ) ;
V_86 . V_87 ( V_53 , V_12 , V_65 . V_44 ) ;
F_44 ( & V_67 , V_66 ) ;
}
F_48 ( V_53 , V_12 ) ;
V_65 = F_42 ( V_53 , V_12 ) ;
if ( V_65 . V_90 )
F_21 ( L_7 ,
F_1 ( V_53 ) , V_12 ) ;
}
static void F_68 ( void )
{
int V_53 , V_12 ;
F_69 (apic, pin)
F_67 ( V_53 , V_12 ) ;
}
static int T_2 F_70 ( char * V_21 )
{
int V_24 , V_92 ;
int V_93 [ V_94 + 1 ] ;
F_71 ( V_21 , F_72 ( V_93 ) , V_93 ) ;
F_13 ( V_25 , V_95
L_8 ) ;
V_92 = V_94 ;
if ( V_93 [ 0 ] < V_94 )
V_92 = V_93 [ 0 ] ;
for ( V_24 = 0 ; V_24 < V_92 ; V_24 ++ ) {
F_13 ( V_25 , V_96
L_9 , V_24 , V_93 [ V_24 + 1 ] ) ;
V_97 [ V_94 - V_24 - 1 ] = V_93 [ V_24 + 1 ] ;
}
return 1 ;
}
int F_73 ( void )
{
int V_53 , V_12 ;
int V_98 = 0 ;
F_19 (apic) {
if ( ! V_2 [ V_53 ] . V_41 ) {
V_98 = - V_73 ;
continue;
}
F_74 (apic, pin)
V_2 [ V_53 ] . V_41 [ V_12 ] =
F_42 ( V_53 , V_12 ) ;
}
return V_98 ;
}
void F_75 ( void )
{
int V_53 , V_12 ;
F_19 (apic) {
if ( ! V_2 [ V_53 ] . V_41 )
continue;
F_74 (apic, pin) {
struct V_42 V_65 ;
V_65 = V_2 [ V_53 ] . V_41 [ V_12 ] ;
if ( ! V_65 . V_69 ) {
V_65 . V_69 = 1 ;
F_47 ( V_53 , V_12 , V_65 ) ;
}
}
}
}
int F_76 ( void )
{
int V_53 , V_12 ;
F_19 (apic) {
if ( ! V_2 [ V_53 ] . V_41 )
continue;
F_74 (apic, pin)
F_47 ( V_53 , V_12 ,
V_2 [ V_53 ] . V_41 [ V_12 ] ) ;
}
return 0 ;
}
static int F_77 ( int V_1 , int V_12 , int type )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_32 ; V_24 ++ )
if ( V_33 [ V_24 ] . V_26 == type &&
( V_33 [ V_24 ] . V_30 == F_1 ( V_1 ) ||
V_33 [ V_24 ] . V_30 == V_99 ) &&
V_33 [ V_24 ] . V_31 == V_12 )
return V_24 ;
return - 1 ;
}
static int T_2 F_78 ( int V_13 , int type )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_32 ; V_24 ++ ) {
int V_100 = V_33 [ V_24 ] . V_28 ;
if ( F_79 ( V_100 , V_101 ) &&
( V_33 [ V_24 ] . V_26 == type ) &&
( V_33 [ V_24 ] . V_29 == V_13 ) )
return V_33 [ V_24 ] . V_31 ;
}
return - 1 ;
}
static int T_2 F_80 ( int V_13 , int type )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_32 ; V_24 ++ ) {
int V_100 = V_33 [ V_24 ] . V_28 ;
if ( F_79 ( V_100 , V_101 ) &&
( V_33 [ V_24 ] . V_26 == type ) &&
( V_33 [ V_24 ] . V_29 == V_13 ) )
break;
}
if ( V_24 < V_32 ) {
int V_1 ;
F_19 (ioapic_idx)
if ( F_1 ( V_1 ) == V_33 [ V_24 ] . V_30 )
return V_1 ;
}
return - 1 ;
}
static int F_81 ( unsigned int V_13 )
{
if ( V_13 < F_7 () ) {
unsigned int V_102 = 0x4d0 + ( V_13 >> 3 ) ;
return ( F_82 ( V_102 ) >> ( V_13 & 7 ) ) & 1 ;
}
F_13 ( V_25 , V_95
L_10 , V_13 ) ;
return 0 ;
}
static int F_83 ( int V_103 )
{
int V_104 = V_33 [ V_103 ] . V_28 ;
int V_105 ;
switch ( V_33 [ V_103 ] . V_27 & 3 )
{
case 0 :
if ( F_79 ( V_104 , V_101 ) )
V_105 = F_84 ( V_103 ) ;
else
V_105 = F_85 ( V_103 ) ;
break;
case 1 :
{
V_105 = 0 ;
break;
}
case 2 :
{
F_86 ( L_11 ) ;
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
F_86 ( L_11 ) ;
V_105 = 1 ;
break;
}
}
return V_105 ;
}
static int F_87 ( int V_103 )
{
int V_104 = V_33 [ V_103 ] . V_28 ;
int V_84 ;
switch ( ( V_33 [ V_103 ] . V_27 >> 2 ) & 3 )
{
case 0 :
if ( F_79 ( V_104 , V_101 ) )
V_84 = F_88 ( V_103 ) ;
else
V_84 = F_89 ( V_103 ) ;
#ifdef F_90
switch ( V_106 [ V_104 ] ) {
case V_107 :
{
break;
}
case V_108 :
{
V_84 = F_91 ( V_103 ) ;
break;
}
case V_109 :
{
break;
}
default:
{
F_86 ( L_11 ) ;
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
F_86 ( L_11 ) ;
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
F_86 ( L_11 ) ;
V_84 = 0 ;
break;
}
}
return V_84 ;
}
static int F_92 ( struct V_16 * V_46 , T_1 V_110 , int V_12 )
{
int V_13 = - 1 ;
int V_8 = ( int ) ( long ) V_46 -> V_111 ;
int type = V_2 [ V_8 ] . V_112 . type ;
switch ( type ) {
case V_113 :
if ( V_110 < F_7 () )
V_13 = F_93 ( V_46 , V_12 ) ;
else if ( F_94 ( V_46 , V_110 , V_12 , 1 ) == 0 )
V_13 = V_110 ;
break;
case V_114 :
if ( F_94 ( V_46 , V_110 , V_12 , 1 ) == 0 )
V_13 = V_110 ;
break;
case V_115 :
V_13 = F_93 ( V_46 , V_12 ) ;
break;
default:
F_95 ( 1 , L_12 , type ) ;
break;
}
return V_13 > 0 ? V_13 : - 1 ;
}
static int F_96 ( T_1 V_110 , int V_103 , int V_8 , int V_12 ,
unsigned int V_66 )
{
int V_13 ;
struct V_16 * V_46 = F_8 ( V_8 ) ;
struct V_14 * V_116 = V_14 ( V_8 , V_12 ) ;
if ( ! V_46 )
return - 1 ;
F_97 ( & V_117 ) ;
if ( V_103 >= 0 && F_79 ( V_33 [ V_103 ] . V_28 , V_101 ) ) {
V_13 = V_33 [ V_103 ] . V_29 ;
if ( V_66 & V_118 ) {
if ( V_116 -> V_119 == 0 &&
F_98 ( V_46 , V_13 , V_12 ) != 0 )
V_13 = - 1 ;
if ( V_13 == 0 )
V_116 -> V_119 ++ ;
}
} else {
V_13 = F_99 ( V_46 , V_12 ) ;
if ( V_13 <= 0 && ( V_66 & V_118 ) )
V_13 = F_92 ( V_46 , V_110 , V_12 ) ;
}
if ( V_66 & V_118 ) {
if ( V_13 < F_7 () && V_116 -> V_119 == 1 &&
F_98 ( V_46 , V_13 , V_12 ) != 0 )
V_13 = - 1 ;
if ( V_13 > 0 )
V_116 -> V_119 ++ ;
else if ( V_116 -> V_119 == 0 )
V_116 -> V_120 = 0 ;
}
F_100 ( & V_117 ) ;
return V_13 > 0 ? V_13 : - 1 ;
}
static int F_101 ( int V_103 , int V_8 , int V_12 , unsigned int V_66 )
{
T_1 V_110 = F_5 ( V_8 , V_12 ) ;
if ( V_33 [ V_103 ] . V_31 != V_12 )
F_21 ( L_13 ) ;
#ifdef F_102
if ( ( V_12 >= 16 ) && ( V_12 <= 23 ) ) {
if ( V_97 [ V_12 - 16 ] != - 1 ) {
if ( ! V_97 [ V_12 - 16 ] ) {
F_13 ( V_25 , V_96
L_14 , V_12 - 16 ) ;
} else {
int V_13 = V_97 [ V_12 - 16 ] ;
F_13 ( V_25 , V_96
L_15 ,
V_12 - 16 , V_13 ) ;
return V_13 ;
}
}
}
#endif
return F_96 ( V_110 , V_103 , V_8 , V_12 , V_66 ) ;
}
int F_103 ( T_1 V_110 , unsigned int V_66 )
{
int V_8 , V_12 , V_103 ;
V_8 = F_104 ( V_110 ) ;
if ( V_8 < 0 )
return - 1 ;
V_12 = F_105 ( V_8 , V_110 ) ;
V_103 = F_77 ( V_8 , V_12 , V_121 ) ;
if ( ( V_66 & V_122 ) && V_103 < 0 )
return - 1 ;
return F_96 ( V_110 , V_103 , V_8 , V_12 , V_66 ) ;
}
void F_106 ( int V_13 )
{
struct V_81 * V_58 = F_107 ( V_13 ) ;
struct V_14 * V_116 ;
int V_8 , V_12 ;
if ( ! V_58 || ! V_58 -> V_46 )
return;
V_8 = ( int ) ( long ) V_58 -> V_46 -> V_111 ;
V_12 = ( int ) V_58 -> V_123 ;
V_116 = V_14 ( V_8 , V_12 ) ;
F_97 ( & V_117 ) ;
if ( -- V_116 -> V_119 == 0 ) {
V_116 -> V_120 = 0 ;
if ( V_13 < F_7 () &&
V_2 [ V_8 ] . V_112 . type == V_113 )
F_108 ( V_58 -> V_46 , V_13 ) ;
else
F_109 ( V_13 ) ;
}
F_100 ( & V_117 ) ;
}
int F_110 ( int V_104 , int V_124 , int V_12 ,
struct V_125 * V_126 )
{
int V_13 , V_24 , V_127 = - 1 , V_128 = - 1 ;
F_13 ( V_129 ,
L_16 ,
V_104 , V_124 , V_12 ) ;
if ( F_79 ( V_104 , V_101 ) ) {
F_13 ( V_25 ,
L_17 , V_104 ) ;
return - 1 ;
}
for ( V_24 = 0 ; V_24 < V_32 ; V_24 ++ ) {
int V_100 = V_33 [ V_24 ] . V_28 ;
int V_1 , V_130 = 0 ;
if ( V_104 != V_100 || V_33 [ V_24 ] . V_26 != V_121 ||
V_124 != ( ( V_33 [ V_24 ] . V_29 >> 2 ) & 0x1f ) )
continue;
F_19 (ioapic_idx)
if ( F_1 ( V_1 ) == V_33 [ V_24 ] . V_30 ||
V_33 [ V_24 ] . V_30 == V_99 ) {
V_130 = 1 ;
break;
}
if ( ! V_130 )
continue;
V_13 = F_101 ( V_24 , V_1 , V_33 [ V_24 ] . V_31 , 0 ) ;
if ( V_13 > 0 && ! F_111 ( V_13 ) )
continue;
if ( V_12 == ( V_33 [ V_24 ] . V_29 & 3 ) ) {
V_128 = V_24 ;
V_127 = V_1 ;
goto V_131;
}
if ( V_128 < 0 ) {
V_128 = V_24 ;
V_127 = V_1 ;
}
}
if ( V_128 < 0 )
return - 1 ;
V_131:
V_13 = F_101 ( V_128 , V_127 , V_33 [ V_128 ] . V_31 ,
V_118 ) ;
if ( V_13 > 0 )
F_112 ( V_126 , V_127 ,
V_33 [ V_128 ] . V_31 ,
F_87 ( V_128 ) ,
F_83 ( V_128 ) ) ;
return V_13 ;
}
void F_113 ( void )
{
F_114 ( & V_132 ) ;
}
void F_115 ( void )
{
F_116 ( & V_132 ) ;
}
static int
F_117 ( int V_13 , struct V_38 * V_39 , const struct V_133 * V_69 )
{
static int V_134 = V_135 + V_136 ;
static int V_137 = V_136 % 16 ;
int V_138 , V_98 ;
T_4 V_139 ;
if ( V_39 -> V_140 )
return - V_141 ;
if ( ! F_118 ( & V_139 , V_142 ) )
return - V_73 ;
V_98 = - V_143 ;
F_119 ( V_39 -> V_48 ) ;
V_138 = F_120 ( V_69 , V_144 ) ;
while ( V_138 < V_145 ) {
int V_146 , V_44 , V_147 ;
V_53 -> V_148 ( V_138 , V_139 , V_69 ) ;
if ( F_121 ( V_139 , V_39 -> V_46 ) ) {
V_98 = 0 ;
if ( F_122 ( V_139 , V_39 -> V_46 ) )
break;
F_123 ( V_39 -> V_48 , V_39 -> V_46 , V_139 ) ;
V_39 -> V_140 =
F_124 ( V_39 -> V_48 , V_144 ) ;
F_125 ( V_39 -> V_46 , V_39 -> V_46 , V_139 ) ;
break;
}
V_44 = V_134 ;
V_147 = V_137 ;
V_72:
V_44 += 16 ;
if ( V_44 >= V_149 ) {
V_147 = ( V_147 + 1 ) % 16 ;
V_44 = V_135 + V_147 ;
}
if ( F_126 ( V_134 == V_44 ) ) {
F_127 ( V_39 -> V_48 , V_39 -> V_48 , V_139 ) ;
F_123 ( V_139 , V_69 , V_39 -> V_48 ) ;
V_138 = F_120 ( V_139 , V_144 ) ;
continue;
}
if ( F_79 ( V_44 , V_150 ) )
goto V_72;
F_128 (new_cpu, tmp_mask, cpu_online_mask) {
if ( F_129 ( V_151 , V_146 ) [ V_44 ] > V_152 )
goto V_72;
}
V_134 = V_44 ;
V_137 = V_147 ;
if ( V_39 -> V_44 ) {
F_130 ( V_39 -> V_48 , V_39 -> V_46 ) ;
V_39 -> V_140 =
F_124 ( V_39 -> V_48 , V_144 ) ;
}
F_128 (new_cpu, tmp_mask, cpu_online_mask)
F_129 ( V_151 , V_146 ) [ V_44 ] = V_13 ;
V_39 -> V_44 = V_44 ;
F_130 ( V_39 -> V_46 , V_139 ) ;
V_98 = 0 ;
break;
}
F_27 ( V_139 ) ;
return V_98 ;
}
int F_131 ( int V_13 , struct V_38 * V_39 , const struct V_133 * V_69 )
{
int V_98 ;
unsigned long V_66 ;
F_43 ( & V_132 , V_66 ) ;
V_98 = F_117 ( V_13 , V_39 , V_69 ) ;
F_44 ( & V_132 , V_66 ) ;
return V_98 ;
}
static void F_132 ( int V_13 , struct V_38 * V_39 )
{
int V_138 , V_44 ;
F_133 ( ! V_39 -> V_44 ) ;
V_44 = V_39 -> V_44 ;
F_128 (cpu, cfg->domain, cpu_online_mask)
F_129 ( V_151 , V_138 ) [ V_44 ] = V_152 ;
V_39 -> V_44 = 0 ;
F_119 ( V_39 -> V_46 ) ;
if ( F_134 ( ! V_39 -> V_140 ) )
return;
F_128 (cpu, cfg->old_domain, cpu_online_mask) {
for ( V_44 = V_135 ; V_44 < V_153 ; V_44 ++ ) {
if ( F_129 ( V_151 , V_138 ) [ V_44 ] != V_13 )
continue;
F_129 ( V_151 , V_138 ) [ V_44 ] = V_152 ;
break;
}
}
V_39 -> V_140 = 0 ;
}
void F_135 ( int V_138 )
{
int V_13 , V_44 ;
struct V_38 * V_39 ;
F_114 ( & V_132 ) ;
F_136 (irq) {
V_39 = V_38 ( V_13 ) ;
if ( ! V_39 )
continue;
if ( ! F_137 ( V_138 , V_39 -> V_46 ) )
continue;
V_44 = V_39 -> V_44 ;
F_129 ( V_151 , V_138 ) [ V_44 ] = V_13 ;
}
for ( V_44 = 0 ; V_44 < V_153 ; ++ V_44 ) {
V_13 = F_129 ( V_151 , V_138 ) [ V_44 ] ;
if ( V_13 <= V_152 )
continue;
V_39 = V_38 ( V_13 ) ;
if ( ! F_137 ( V_138 , V_39 -> V_46 ) )
F_129 ( V_151 , V_138 ) [ V_44 ] = V_152 ;
}
F_116 ( & V_132 ) ;
}
static inline int F_138 ( int V_13 )
{
int V_53 , V_103 , V_12 ;
F_69 (apic, pin) {
V_103 = F_77 ( V_53 , V_12 , V_121 ) ;
if ( ( V_103 != - 1 ) && ( V_13 == F_101 ( V_103 , V_53 , V_12 , 0 ) ) )
return F_87 ( V_103 ) ;
}
return 0 ;
}
static inline int F_138 ( int V_13 )
{
return 1 ;
}
static void F_139 ( unsigned int V_13 , struct V_38 * V_39 ,
unsigned long V_84 )
{
struct V_154 * V_155 = & V_156 ;
T_5 V_157 ;
bool V_158 ;
if ( ( V_84 == V_159 && F_138 ( V_13 ) ) ||
V_84 == V_91 ) {
F_140 ( V_13 , V_160 ) ;
V_158 = true ;
} else {
F_141 ( V_13 , V_160 ) ;
V_158 = false ;
}
if ( F_142 ( V_13 , V_39 , V_155 ) )
V_158 = V_84 != 0 ;
V_157 = V_158 ? V_161 : V_162 ;
F_143 ( V_13 , V_155 , V_157 ,
V_158 ? L_18 : L_19 ) ;
}
int F_144 ( int V_13 , struct V_42 * V_65 ,
unsigned int V_163 , int V_44 ,
struct V_125 * V_164 )
{
memset ( V_65 , 0 , sizeof( * V_65 ) ) ;
V_65 -> V_88 = V_53 -> V_165 ;
V_65 -> V_166 = V_53 -> V_167 ;
V_65 -> V_168 = V_163 ;
V_65 -> V_44 = V_44 ;
V_65 -> V_69 = 0 ;
V_65 -> V_84 = V_164 -> V_84 ;
V_65 -> V_105 = V_164 -> V_105 ;
if ( V_164 -> V_84 )
V_65 -> V_69 = 1 ;
return 0 ;
}
static void F_145 ( unsigned int V_13 , struct V_38 * V_39 ,
struct V_125 * V_164 )
{
struct V_42 V_65 ;
unsigned int V_168 ;
if ( ! F_111 ( V_13 ) )
return;
if ( F_131 ( V_13 , V_39 , V_53 -> V_169 () ) )
return;
if ( V_53 -> V_170 ( V_39 -> V_46 , V_53 -> V_169 () ,
& V_168 ) ) {
F_86 ( L_20 ,
F_1 ( V_164 -> V_8 ) , V_164 -> V_171 ) ;
F_132 ( V_13 , V_39 ) ;
return;
}
F_13 ( V_25 , V_96
L_21
L_22 ,
V_164 -> V_8 , F_1 ( V_164 -> V_8 ) , V_164 -> V_171 ,
V_39 -> V_44 , V_13 , V_164 -> V_84 , V_164 -> V_105 , V_168 ) ;
if ( V_86 . V_172 ( V_13 , & V_65 , V_168 , V_39 -> V_44 , V_164 ) ) {
F_86 ( L_23 ,
F_1 ( V_164 -> V_8 ) , V_164 -> V_171 ) ;
F_132 ( V_13 , V_39 ) ;
return;
}
F_139 ( V_13 , V_39 , V_164 -> V_84 ) ;
if ( V_13 < F_7 () )
V_173 -> V_69 ( V_13 ) ;
F_47 ( V_164 -> V_8 , V_164 -> V_171 , V_65 ) ;
}
static void T_2 F_146 ( void )
{
unsigned int V_8 , V_12 ;
int V_103 ;
F_13 ( V_25 , V_96 L_24 ) ;
F_69 (ioapic, pin) {
V_103 = F_77 ( V_8 , V_12 , V_121 ) ;
if ( V_103 < 0 )
F_13 ( V_25 ,
V_96 L_25 ,
F_1 ( V_8 ) , V_12 ) ;
else
F_101 ( V_103 , V_8 , V_12 ,
V_8 ? 0 : V_118 ) ;
}
}
static void T_2 F_147 ( unsigned int V_1 ,
unsigned int V_12 , int V_44 )
{
struct V_42 V_65 ;
unsigned int V_168 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
if ( F_126 ( V_53 -> V_170 ( V_53 -> V_169 () ,
V_53 -> V_169 () , & V_168 ) ) )
V_168 = V_174 ;
V_65 . V_166 = V_53 -> V_167 ;
V_65 . V_69 = 0 ;
V_65 . V_168 = V_168 ;
V_65 . V_88 = V_53 -> V_165 ;
V_65 . V_105 = 0 ;
V_65 . V_84 = 0 ;
V_65 . V_44 = V_44 ;
F_143 ( 0 , & V_156 , V_162 ,
L_19 ) ;
F_47 ( V_1 , V_12 , V_65 ) ;
}
void F_148 ( unsigned int V_53 , unsigned int V_175 )
{
int V_24 ;
F_149 ( L_26 ) ;
for ( V_24 = 0 ; V_24 <= V_175 ; V_24 ++ ) {
struct V_42 V_65 ;
V_65 = F_42 ( V_53 , V_24 ) ;
F_149 ( L_27 , V_24 , V_65 . V_168 ) ;
F_150 ( L_28
L_29 ,
V_65 . V_69 ,
V_65 . V_84 ,
V_65 . V_90 ,
V_65 . V_105 ,
V_65 . V_176 ,
V_65 . V_166 ,
V_65 . V_88 ,
V_65 . V_44 ) ;
}
}
void F_151 ( unsigned int V_53 ,
unsigned int V_175 )
{
int V_24 ;
F_149 ( L_30 ) ;
for ( V_24 = 0 ; V_24 <= V_175 ; V_24 ++ ) {
struct V_177 * V_178 ;
struct V_42 V_65 ;
V_65 = F_42 ( V_53 , V_24 ) ;
V_178 = (struct V_177 * ) & V_65 ;
F_149 ( L_31 , V_24 , V_178 -> V_57 ) ;
F_150 ( L_32
L_33 ,
V_178 -> V_179 ,
V_178 -> V_69 ,
V_178 -> V_84 ,
V_178 -> V_90 ,
V_178 -> V_105 ,
V_178 -> V_176 ,
V_178 -> V_180 ,
V_178 -> V_181 ,
V_178 -> V_44 ) ;
}
}
void F_152 ( void )
{
F_153 ( & V_67 ) ;
}
static T_2 int F_154 ( char * V_182 )
{
int V_183 = - 1 ;
if ( strcmp ( V_182 , L_34 ) == 0 ) {
V_184 = V_185 ;
} else {
F_155 ( & V_182 , & V_183 ) ;
if ( V_183 >= 0 )
V_184 = V_183 ;
}
return 1 ;
}
void T_2 F_156 ( void )
{
int V_186 , V_187 ;
int V_53 , V_12 ;
if ( ! F_7 () )
return;
F_69 (apic, pin) {
struct V_42 V_65 = F_42 ( V_53 , V_12 ) ;
if ( ( V_65 . V_69 == 0 ) && ( V_65 . V_88 == V_188 ) ) {
V_189 . V_53 = V_53 ;
V_189 . V_12 = V_12 ;
goto V_190;
}
}
V_190:
V_187 = F_78 ( 0 , V_191 ) ;
V_186 = F_80 ( 0 , V_191 ) ;
if ( ( V_189 . V_12 == - 1 ) && ( V_187 >= 0 ) ) {
F_157 ( V_192 L_35 ) ;
V_189 . V_12 = V_187 ;
V_189 . V_53 = V_186 ;
}
if ( ( ( V_189 . V_53 != V_186 ) || ( V_189 . V_12 != V_187 ) ) &&
( V_187 >= 0 ) && ( V_189 . V_12 >= 0 ) )
{
F_157 ( V_192 L_36 ) ;
}
F_68 () ;
}
void F_158 ( void )
{
if ( V_189 . V_12 != - 1 ) {
struct V_42 V_65 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_69 = 0 ;
V_65 . V_84 = 0 ;
V_65 . V_90 = 0 ;
V_65 . V_105 = 0 ;
V_65 . V_176 = 0 ;
V_65 . V_166 = 0 ;
V_65 . V_88 = V_188 ;
V_65 . V_44 = 0 ;
V_65 . V_168 = F_159 () ;
F_47 ( V_189 . V_53 , V_189 . V_12 , V_65 ) ;
}
if ( V_193 || F_160 () )
F_161 ( V_189 . V_12 != - 1 ) ;
}
void F_162 ( void )
{
F_68 () ;
if ( ! F_7 () )
return;
V_86 . V_194 () ;
}
void T_2 F_163 ( void )
{
union V_195 V_196 ;
T_6 V_197 ;
int V_1 ;
int V_24 ;
unsigned char V_198 ;
unsigned long V_66 ;
V_53 -> V_199 ( & V_200 , & V_197 ) ;
F_19 (ioapic_idx) {
F_43 ( & V_67 , V_66 ) ;
V_196 . V_201 = F_41 ( V_1 , 0 ) ;
F_44 ( & V_67 , V_66 ) ;
V_198 = F_1 ( V_1 ) ;
if ( F_1 ( V_1 ) >= F_164 () ) {
F_157 ( V_202 L_37 ,
V_1 , F_1 ( V_1 ) ) ;
F_157 ( V_202 L_38 ,
V_196 . V_203 . V_204 ) ;
V_2 [ V_1 ] . V_3 . V_4 = V_196 . V_203 . V_204 ;
}
if ( V_53 -> V_205 ( & V_197 ,
F_1 ( V_1 ) ) ) {
F_157 ( V_202 L_39 ,
V_1 , F_1 ( V_1 ) ) ;
for ( V_24 = 0 ; V_24 < F_164 () ; V_24 ++ )
if ( ! F_165 ( V_24 , V_197 ) )
break;
if ( V_24 >= F_164 () )
F_14 ( L_40 ) ;
F_157 ( V_202 L_38 ,
V_24 ) ;
F_166 ( V_24 , V_197 ) ;
V_2 [ V_1 ] . V_3 . V_4 = V_24 ;
} else {
T_6 V_206 ;
V_53 -> V_207 ( F_1 ( V_1 ) ,
& V_206 ) ;
F_13 ( V_25 , L_41
L_42 ,
F_1 ( V_1 ) ) ;
F_167 ( V_197 , V_197 , V_206 ) ;
}
if ( V_198 != F_1 ( V_1 ) )
for ( V_24 = 0 ; V_24 < V_32 ; V_24 ++ )
if ( V_33 [ V_24 ] . V_30 == V_198 )
V_33 [ V_24 ] . V_30
= F_1 ( V_1 ) ;
if ( F_1 ( V_1 ) == V_196 . V_203 . V_204 )
continue;
F_13 ( V_25 , V_95
L_43 ,
F_1 ( V_1 ) ) ;
V_196 . V_203 . V_204 = F_1 ( V_1 ) ;
F_43 ( & V_67 , V_66 ) ;
F_46 ( V_1 , 0 , V_196 . V_201 ) ;
F_44 ( & V_67 , V_66 ) ;
F_43 ( & V_67 , V_66 ) ;
V_196 . V_201 = F_41 ( V_1 , 0 ) ;
F_44 ( & V_67 , V_66 ) ;
if ( V_196 . V_203 . V_204 != F_1 ( V_1 ) )
F_150 ( L_44 ) ;
else
F_13 ( V_25 , L_45 ) ;
}
}
void T_2 F_168 ( void )
{
if ( V_208 )
return;
if ( ! ( V_209 . V_210 == V_211 )
|| F_169 ( V_212 [ V_213 ] ) )
return;
F_163 () ;
}
static int T_2 F_170 ( char * V_214 )
{
V_215 = 1 ;
return 1 ;
}
static int T_2 F_171 ( void )
{
unsigned long V_216 = V_217 ;
unsigned long V_66 ;
if ( V_215 )
return 1 ;
F_172 ( V_66 ) ;
F_173 () ;
F_174 ( ( 10 * 1000 ) / V_218 ) ;
F_175 ( V_66 ) ;
if ( F_176 ( V_217 , V_216 + 4 ) )
return 1 ;
return 0 ;
}
static unsigned int F_177 ( struct V_81 * V_58 )
{
int V_219 = 0 , V_13 = V_58 -> V_13 ;
unsigned long V_66 ;
F_43 ( & V_67 , V_66 ) ;
if ( V_13 < F_7 () ) {
V_173 -> V_69 ( V_13 ) ;
if ( V_173 -> V_220 ( V_13 ) )
V_219 = 1 ;
}
F_61 ( V_58 -> V_82 ) ;
F_44 ( & V_67 , V_66 ) ;
return V_219 ;
}
static int F_178 ( struct V_81 * V_58 )
{
struct V_38 * V_39 = V_58 -> V_82 ;
unsigned long V_66 ;
int V_138 ;
F_43 ( & V_132 , V_66 ) ;
V_138 = F_120 ( V_39 -> V_46 , V_144 ) ;
V_53 -> V_221 ( F_179 ( V_138 ) , V_39 -> V_44 ) ;
F_44 ( & V_132 , V_66 ) ;
return 1 ;
}
void F_180 ( struct V_38 * V_39 )
{
T_4 V_222 ;
if ( F_126 ( ! F_118 ( & V_222 , V_142 ) ) ) {
unsigned int V_24 ;
F_128 (i, cfg->old_domain, cpu_online_mask)
V_53 -> V_221 ( F_179 ( V_24 ) , V_223 ) ;
} else {
F_125 ( V_222 , V_39 -> V_48 , V_144 ) ;
V_53 -> V_221 ( V_222 , V_223 ) ;
F_27 ( V_222 ) ;
}
V_39 -> V_140 = 0 ;
}
T_7 T_8 void F_181 ( void )
{
unsigned V_44 , V_224 ;
F_182 () ;
F_183 () ;
F_184 () ;
V_224 = F_185 () ;
for ( V_44 = V_135 ; V_44 < V_153 ; V_44 ++ ) {
int V_13 ;
unsigned int V_90 ;
struct V_225 * V_226 ;
struct V_38 * V_39 ;
V_13 = F_186 ( V_151 [ V_44 ] ) ;
if ( V_13 <= V_152 )
continue;
V_226 = F_187 ( V_13 ) ;
if ( ! V_226 )
continue;
V_39 = V_38 ( V_13 ) ;
if ( ! V_39 )
continue;
F_114 ( & V_226 -> V_227 ) ;
if ( V_39 -> V_140 )
goto V_228;
if ( V_44 == V_39 -> V_44 && F_137 ( V_224 , V_39 -> V_46 ) )
goto V_228;
V_90 = F_188 ( V_229 + ( V_44 / 32 * 0x10 ) ) ;
if ( V_90 & ( 1 << ( V_44 % 32 ) ) ) {
V_53 -> V_230 ( V_223 ) ;
goto V_228;
}
F_189 ( V_151 [ V_44 ] , V_152 ) ;
V_228:
F_116 ( & V_226 -> V_227 ) ;
}
F_190 () ;
}
static void F_191 ( struct V_38 * V_39 , unsigned V_44 )
{
unsigned V_224 ;
if ( F_134 ( ! V_39 -> V_140 ) )
return;
V_224 = F_185 () ;
if ( V_44 == V_39 -> V_44 && F_137 ( V_224 , V_39 -> V_46 ) )
F_180 ( V_39 ) ;
}
static void F_192 ( struct V_38 * V_39 )
{
F_191 ( V_39 , ~ F_193 () -> V_231 ) ;
}
void F_194 ( int V_13 )
{
struct V_38 * V_39 = V_38 ( V_13 ) ;
if ( ! V_39 )
return;
F_191 ( V_39 , V_39 -> V_44 ) ;
}
static inline void F_192 ( struct V_38 * V_39 ) { }
static void F_195 ( unsigned int V_13 , unsigned int V_168 , struct V_38 * V_39 )
{
int V_53 , V_12 ;
struct V_35 * V_65 ;
T_9 V_44 = V_39 -> V_44 ;
F_50 (entry, cfg->irq_2_pin) {
unsigned int V_56 ;
V_53 = V_65 -> V_53 ;
V_12 = V_65 -> V_12 ;
F_46 ( V_53 , 0x11 + V_12 * 2 , V_168 ) ;
V_56 = F_41 ( V_53 , 0x10 + V_12 * 2 ) ;
V_56 &= ~ V_232 ;
V_56 |= V_44 ;
F_56 ( V_53 , 0x10 + V_12 * 2 , V_56 ) ;
}
}
int F_196 ( struct V_81 * V_58 , const struct V_133 * V_69 ,
unsigned int * V_233 )
{
struct V_38 * V_39 = V_58 -> V_82 ;
unsigned int V_13 = V_58 -> V_13 ;
int V_98 ;
if ( ! F_197 ( V_234 ) )
return - V_235 ;
if ( ! F_124 ( V_69 , V_144 ) )
return - V_236 ;
V_98 = F_131 ( V_13 , V_39 , V_69 ) ;
if ( V_98 )
return V_98 ;
V_98 = V_53 -> V_170 ( V_69 , V_39 -> V_46 , V_233 ) ;
if ( V_98 ) {
if ( F_131 ( V_13 , V_39 , V_58 -> V_237 ) )
F_21 ( L_46 , V_13 ) ;
return V_98 ;
}
F_130 ( V_58 -> V_237 , V_69 ) ;
return 0 ;
}
int F_198 ( struct V_81 * V_58 ,
const struct V_133 * V_69 ,
bool V_238 )
{
unsigned int V_168 , V_13 = V_58 -> V_13 ;
unsigned long V_66 ;
int V_239 ;
if ( ! F_197 ( V_234 ) )
return - V_235 ;
F_43 ( & V_67 , V_66 ) ;
V_239 = F_196 ( V_58 , V_69 , & V_168 ) ;
if ( ! V_239 ) {
V_168 = F_199 ( V_168 ) ;
F_195 ( V_13 , V_168 , V_58 -> V_82 ) ;
V_239 = V_240 ;
}
F_44 ( & V_67 , V_66 ) ;
return V_239 ;
}
static void F_200 ( struct V_81 * V_58 )
{
F_192 ( V_58 -> V_82 ) ;
F_201 ( V_58 ) ;
F_182 () ;
}
static bool F_202 ( struct V_38 * V_39 )
{
struct V_35 * V_65 ;
unsigned long V_66 ;
F_43 ( & V_67 , V_66 ) ;
F_50 (entry, cfg->irq_2_pin) {
unsigned int V_56 ;
int V_12 ;
V_12 = V_65 -> V_12 ;
V_56 = F_41 ( V_65 -> V_53 , 0x10 + V_12 * 2 ) ;
if ( V_56 & V_241 ) {
F_44 ( & V_67 , V_66 ) ;
return true ;
}
}
F_44 ( & V_67 , V_66 ) ;
return false ;
}
static inline bool F_203 ( struct V_81 * V_58 , struct V_38 * V_39 )
{
if ( F_126 ( F_204 ( V_58 ) ) ) {
F_59 ( V_39 ) ;
return true ;
}
return false ;
}
static inline void F_205 ( struct V_81 * V_58 ,
struct V_38 * V_39 , bool V_242 )
{
if ( F_126 ( V_242 ) ) {
if ( ! F_202 ( V_39 ) )
F_206 ( V_58 ) ;
F_62 ( V_39 ) ;
}
}
static inline bool F_203 ( struct V_81 * V_58 , struct V_38 * V_39 )
{
return false ;
}
static inline void F_205 ( struct V_81 * V_58 ,
struct V_38 * V_39 , bool V_242 )
{
}
static void F_207 ( struct V_81 * V_58 )
{
struct V_38 * V_39 = V_58 -> V_82 ;
int V_24 , V_13 = V_58 -> V_13 ;
unsigned long V_243 ;
bool V_242 ;
F_192 ( V_39 ) ;
V_242 = F_203 ( V_58 , V_39 ) ;
V_24 = V_39 -> V_44 ;
V_243 = F_188 ( V_244 + ( ( V_24 & ~ 0x1f ) >> 1 ) ) ;
F_182 () ;
if ( ! ( V_243 & ( 1 << ( V_24 & 0x1f ) ) ) ) {
F_208 ( & V_245 ) ;
F_66 ( V_13 , V_39 ) ;
}
F_205 ( V_58 , V_39 , V_242 ) ;
}
static inline void F_209 ( void )
{
struct V_38 * V_39 ;
unsigned int V_13 ;
F_136 (irq) {
V_39 = V_38 ( V_13 ) ;
if ( F_111 ( V_13 ) && V_39 && ! V_39 -> V_44 ) {
if ( V_13 < F_7 () )
V_173 -> V_246 ( V_13 ) ;
else
F_210 ( V_13 , & V_247 ) ;
}
}
}
static void F_211 ( struct V_81 * V_58 )
{
unsigned long V_243 ;
V_243 = F_188 ( V_248 ) ;
F_212 ( V_248 , V_243 | V_249 ) ;
}
static void F_213 ( struct V_81 * V_58 )
{
unsigned long V_243 ;
V_243 = F_188 ( V_248 ) ;
F_212 ( V_248 , V_243 & ~ V_249 ) ;
}
static void F_214 ( struct V_81 * V_58 )
{
F_182 () ;
}
static void F_215 ( int V_13 )
{
F_141 ( V_13 , V_160 ) ;
F_143 ( V_13 , & V_250 , V_162 ,
L_19 ) ;
}
static inline void T_2 F_216 ( void )
{
int V_53 , V_12 , V_24 ;
struct V_42 V_251 , V_83 ;
unsigned char V_252 , V_253 ;
V_12 = F_78 ( 8 , V_121 ) ;
if ( V_12 == - 1 ) {
F_217 ( 1 ) ;
return;
}
V_53 = F_80 ( 8 , V_121 ) ;
if ( V_53 == - 1 ) {
F_217 ( 1 ) ;
return;
}
V_251 = F_42 ( V_53 , V_12 ) ;
F_67 ( V_53 , V_12 ) ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_166 = 0 ;
V_83 . V_69 = 0 ;
V_83 . V_168 = F_218 () ;
V_83 . V_88 = V_188 ;
V_83 . V_105 = V_251 . V_105 ;
V_83 . V_84 = 0 ;
V_83 . V_44 = 0 ;
F_47 ( V_53 , V_12 , V_83 ) ;
V_252 = F_219 ( V_254 ) ;
V_253 = F_219 ( V_255 ) ;
F_220 ( ( V_253 & ~ V_256 ) | 0x6 ,
V_255 ) ;
F_220 ( V_252 | V_257 , V_254 ) ;
V_24 = 100 ;
while ( V_24 -- > 0 ) {
F_174 ( 10 ) ;
if ( ( F_219 ( V_258 ) & V_259 ) == V_259 )
V_24 -= 10 ;
}
F_220 ( V_252 , V_254 ) ;
F_220 ( V_253 , V_255 ) ;
F_67 ( V_53 , V_12 ) ;
F_47 ( V_53 , V_12 , V_251 ) ;
}
static int T_2 F_221 ( char * V_182 )
{
V_260 = 1 ;
return 0 ;
}
static inline void T_2 F_222 ( void )
{
struct V_38 * V_39 = V_38 ( 0 ) ;
int V_36 = F_18 ( 0 ) ;
int V_261 , V_262 , V_263 , V_264 ;
unsigned long V_66 ;
int V_265 = 0 ;
F_223 ( V_66 ) ;
V_173 -> V_69 ( 0 ) ;
F_131 ( 0 , V_39 , V_53 -> V_169 () ) ;
F_212 ( V_248 , V_249 | V_266 ) ;
V_173 -> V_267 ( 1 ) ;
V_262 = F_78 ( 0 , V_121 ) ;
V_261 = F_80 ( 0 , V_121 ) ;
V_264 = V_189 . V_12 ;
V_263 = V_189 . V_53 ;
F_13 ( V_268 , V_95 L_47
L_48 ,
V_39 -> V_44 , V_261 , V_262 , V_263 , V_264 ) ;
if ( V_262 == - 1 ) {
F_224 ( L_49 ) ;
V_262 = V_264 ;
V_261 = V_263 ;
V_265 = 1 ;
} else if ( V_264 == - 1 ) {
V_264 = V_262 ;
V_263 = V_261 ;
}
if ( V_262 != - 1 ) {
if ( V_265 ) {
F_52 ( V_39 , V_36 , V_261 , V_262 ) ;
F_147 ( V_261 , V_262 , V_39 -> V_44 ) ;
} else {
int V_103 ;
V_103 = F_77 ( V_261 , V_262 , V_121 ) ;
if ( V_103 != - 1 && F_87 ( V_103 ) )
F_62 ( V_39 ) ;
}
if ( F_171 () ) {
if ( V_260 > 0 )
F_67 ( 0 , V_262 ) ;
goto V_131;
}
F_224 ( L_50 ) ;
F_225 () ;
F_67 ( V_261 , V_262 ) ;
if ( ! V_265 )
F_13 ( V_268 , V_202 L_51
L_52 ) ;
F_13 ( V_268 , V_95 L_53
L_54 ) ;
F_13 ( V_268 , V_95
L_55 , V_263 , V_264 ) ;
F_53 ( V_39 , V_36 , V_261 , V_262 , V_263 , V_264 ) ;
F_147 ( V_263 , V_264 , V_39 -> V_44 ) ;
V_173 -> V_269 ( 0 ) ;
if ( F_171 () ) {
F_13 ( V_268 , V_95 L_56 ) ;
goto V_131;
}
F_225 () ;
V_173 -> V_69 ( 0 ) ;
F_67 ( V_263 , V_264 ) ;
F_13 ( V_268 , V_95 L_57 ) ;
}
F_13 ( V_268 , V_95
L_58 ) ;
F_215 ( 0 ) ;
F_212 ( V_248 , V_270 | V_39 -> V_44 ) ;
V_173 -> V_269 ( 0 ) ;
if ( F_171 () ) {
F_13 ( V_268 , V_95 L_59 ) ;
goto V_131;
}
F_225 () ;
V_173 -> V_69 ( 0 ) ;
F_212 ( V_248 , V_249 | V_270 | V_39 -> V_44 ) ;
F_13 ( V_268 , V_95 L_60 ) ;
F_13 ( V_268 , V_95
L_61 ) ;
V_173 -> V_267 ( 0 ) ;
V_173 -> V_246 ( 0 ) ;
F_212 ( V_248 , V_266 ) ;
F_216 () ;
if ( F_171 () ) {
F_13 ( V_268 , V_95 L_59 ) ;
goto V_131;
}
F_225 () ;
F_13 ( V_268 , V_95 L_62 ) ;
if ( V_271 )
F_13 ( V_268 , V_95
L_63
L_64 ) ;
F_14 ( L_65
L_66 ) ;
V_131:
F_175 ( V_66 ) ;
}
static int F_226 ( int V_8 )
{
T_10 V_272 ;
int V_273 = F_4 ( V_8 ) ;
struct V_8 * V_274 = & V_2 [ V_8 ] ;
struct V_275 * V_39 = & V_274 -> V_112 ;
struct V_6 * V_9 = F_3 ( V_8 ) ;
V_272 = sizeof( struct V_14 ) * F_4 ( V_8 ) ;
V_274 -> V_15 = F_20 ( V_272 , V_37 ) ;
if ( ! V_274 -> V_15 )
return - V_73 ;
if ( V_39 -> type == V_276 )
return 0 ;
V_274 -> V_17 = F_227 ( V_39 -> V_277 , V_273 , V_39 -> V_278 ,
( void * ) ( long ) V_8 ) ;
if( ! V_274 -> V_17 ) {
F_28 ( V_274 -> V_15 ) ;
V_274 -> V_15 = NULL ;
return - V_73 ;
}
if ( V_39 -> type == V_113 ||
V_39 -> type == V_114 )
V_279 = V_92 ( V_279 ,
V_9 -> V_10 + 1 ) ;
if ( V_9 -> V_11 == 0 )
F_228 ( V_274 -> V_17 ) ;
return 0 ;
}
void T_2 F_229 ( void )
{
int V_8 ;
V_40 = F_7 () ? ~ V_280 : ~ 0UL ;
F_13 ( V_25 , L_67 ) ;
F_19 (ioapic)
F_133 ( F_226 ( V_8 ) ) ;
V_281 . V_282 . V_283 () ;
F_230 () ;
F_146 () ;
F_209 () ;
if ( F_7 () )
F_222 () ;
V_284 = 1 ;
}
static int T_2 F_231 ( void )
{
if ( V_60 == - 1 )
V_60 = 0 ;
return 0 ;
}
static void F_232 ( int V_1 )
{
unsigned long V_66 ;
union V_195 V_196 ;
F_43 ( & V_67 , V_66 ) ;
V_196 . V_201 = F_41 ( V_1 , 0 ) ;
if ( V_196 . V_203 . V_204 != F_1 ( V_1 ) ) {
V_196 . V_203 . V_204 = F_1 ( V_1 ) ;
F_46 ( V_1 , 0 , V_196 . V_201 ) ;
}
F_44 ( & V_67 , V_66 ) ;
}
static void F_233 ( void )
{
int V_1 ;
F_234 (ioapic_idx)
F_232 ( V_1 ) ;
F_76 () ;
}
static int T_2 F_235 ( void )
{
F_236 ( & V_285 ) ;
return 0 ;
}
int F_237 ( unsigned int V_13 , int V_36 )
{
struct V_38 * V_39 ;
unsigned long V_66 ;
int V_239 ;
V_39 = F_25 ( V_13 , V_36 ) ;
if ( ! V_39 )
return - V_73 ;
F_43 ( & V_132 , V_66 ) ;
V_239 = F_117 ( V_13 , V_39 , V_53 -> V_169 () ) ;
F_44 ( & V_132 , V_66 ) ;
if ( ! V_239 )
F_30 ( V_13 , V_39 ) ;
else
F_29 ( V_13 , V_39 ) ;
return V_239 ;
}
void F_238 ( unsigned int V_13 )
{
struct V_38 * V_39 = V_38 ( V_13 ) ;
unsigned long V_66 ;
F_239 ( V_13 ) ;
F_43 ( & V_132 , V_66 ) ;
F_132 ( V_13 , V_39 ) ;
F_44 ( & V_132 , V_66 ) ;
F_29 ( V_13 , V_39 ) ;
}
void F_240 ( struct V_286 * V_287 ,
unsigned int V_13 , unsigned int V_168 ,
struct V_288 * V_289 , T_9 V_290 )
{
struct V_38 * V_39 = V_38 ( V_13 ) ;
V_289 -> V_291 = V_292 ;
if ( F_241 () )
V_289 -> V_291 |= F_242 ( V_168 ) ;
V_289 -> V_293 =
V_294 |
( ( V_53 -> V_167 == 0 ) ?
V_295 :
V_296 ) |
( ( V_53 -> V_165 != V_297 ) ?
V_298 :
V_299 ) |
F_243 ( V_168 ) ;
V_289 -> V_58 =
V_300 |
V_301 |
( ( V_53 -> V_165 != V_297 ) ?
V_302 :
V_303 ) |
F_244 ( V_39 -> V_44 ) ;
}
static int F_245 ( struct V_286 * V_287 , unsigned int V_13 ,
struct V_288 * V_289 , T_9 V_290 )
{
struct V_38 * V_39 ;
int V_98 ;
unsigned V_168 ;
if ( V_304 )
return - V_305 ;
V_39 = V_38 ( V_13 ) ;
V_98 = F_131 ( V_13 , V_39 , V_53 -> V_169 () ) ;
if ( V_98 )
return V_98 ;
V_98 = V_53 -> V_170 ( V_39 -> V_46 ,
V_53 -> V_169 () , & V_168 ) ;
if ( V_98 )
return V_98 ;
V_306 . V_307 ( V_287 , V_13 , V_168 , V_289 , V_290 ) ;
return 0 ;
}
static int
F_246 ( struct V_81 * V_58 , const struct V_133 * V_69 , bool V_238 )
{
struct V_38 * V_39 = V_58 -> V_82 ;
struct V_288 V_289 ;
unsigned int V_168 ;
int V_239 ;
V_239 = F_196 ( V_58 , V_69 , & V_168 ) ;
if ( V_239 )
return V_239 ;
F_247 ( V_58 -> V_308 , & V_289 ) ;
V_289 . V_58 &= ~ V_309 ;
V_289 . V_58 |= F_244 ( V_39 -> V_44 ) ;
V_289 . V_293 &= ~ V_310 ;
V_289 . V_293 |= F_243 ( V_168 ) ;
F_248 ( V_58 -> V_308 , & V_289 ) ;
return V_240 ;
}
int F_249 ( struct V_286 * V_277 , struct V_308 * V_311 ,
unsigned int V_312 , unsigned int V_313 )
{
struct V_154 * V_155 = & V_314 ;
struct V_288 V_289 ;
unsigned int V_13 = V_312 + V_313 ;
int V_239 ;
V_239 = F_245 ( V_277 , V_13 , & V_289 , - 1 ) ;
if ( V_239 < 0 )
return V_239 ;
F_250 ( V_312 , V_313 , V_311 ) ;
if ( ! V_313 )
F_251 ( V_13 , & V_289 ) ;
F_142 ( V_13 , V_38 ( V_13 ) , V_155 ) ;
F_143 ( V_13 , V_155 , V_162 , L_19 ) ;
F_252 ( V_96 , & V_277 -> V_277 , L_68 , V_13 ) ;
return 0 ;
}
int F_253 ( struct V_286 * V_277 , int V_315 , int type )
{
struct V_308 * V_311 ;
unsigned int V_13 ;
int V_36 , V_239 ;
if ( type == V_316 && V_315 > 1 )
return 1 ;
V_36 = F_254 ( & V_277 -> V_277 ) ;
F_255 (msidesc, &dev->msi_list, list) {
V_13 = F_256 ( V_36 ) ;
if ( ! V_13 )
return - V_143 ;
V_239 = F_249 ( V_277 , V_311 , V_13 , 0 ) ;
if ( V_239 < 0 ) {
F_257 ( V_13 ) ;
return V_239 ;
}
}
return 0 ;
}
void F_258 ( unsigned int V_13 )
{
F_257 ( V_13 ) ;
}
static int
F_259 ( struct V_81 * V_58 , const struct V_133 * V_69 ,
bool V_238 )
{
struct V_38 * V_39 = V_58 -> V_82 ;
unsigned int V_168 , V_13 = V_58 -> V_13 ;
struct V_288 V_289 ;
int V_239 ;
V_239 = F_196 ( V_58 , V_69 , & V_168 ) ;
if ( V_239 )
return V_239 ;
F_260 ( V_13 , & V_289 ) ;
V_289 . V_58 &= ~ V_309 ;
V_289 . V_58 |= F_244 ( V_39 -> V_44 ) ;
V_289 . V_293 &= ~ V_310 ;
V_289 . V_293 |= F_243 ( V_168 ) ;
V_289 . V_291 = V_292 | F_242 ( V_168 ) ;
F_261 ( V_13 , & V_289 ) ;
return V_240 ;
}
int F_262 ( unsigned int V_13 )
{
int V_239 ;
struct V_288 V_289 ;
V_239 = F_245 ( NULL , V_13 , & V_289 , - 1 ) ;
if ( V_239 < 0 )
return V_239 ;
F_261 ( V_13 , & V_289 ) ;
F_143 ( V_13 , & V_317 , V_162 ,
L_19 ) ;
return 0 ;
}
static int F_263 ( struct V_81 * V_58 ,
const struct V_133 * V_69 , bool V_238 )
{
struct V_38 * V_39 = V_58 -> V_82 ;
struct V_288 V_289 ;
unsigned int V_168 ;
int V_239 ;
V_239 = F_196 ( V_58 , V_69 , & V_168 ) ;
if ( V_239 )
return V_239 ;
F_264 ( V_58 -> V_318 , & V_289 ) ;
V_289 . V_58 &= ~ V_309 ;
V_289 . V_58 |= F_244 ( V_39 -> V_44 ) ;
V_289 . V_293 &= ~ V_310 ;
V_289 . V_293 |= F_243 ( V_168 ) ;
F_265 ( V_58 -> V_318 , & V_289 ) ;
return V_240 ;
}
int F_266 ( unsigned int V_13 , unsigned int V_319 )
{
struct V_154 * V_155 = & V_320 ;
struct V_288 V_289 ;
int V_239 ;
V_239 = F_245 ( NULL , V_13 , & V_289 , V_319 ) ;
if ( V_239 < 0 )
return V_239 ;
F_265 ( F_267 ( V_13 ) , & V_289 ) ;
F_140 ( V_13 , V_321 ) ;
F_142 ( V_13 , V_38 ( V_13 ) , V_155 ) ;
F_143 ( V_13 , V_155 , V_162 , L_19 ) ;
return 0 ;
}
static void F_268 ( unsigned int V_13 , unsigned int V_168 , T_9 V_44 )
{
struct V_322 V_289 ;
F_269 ( V_13 , & V_289 ) ;
V_289 . V_293 &= ~ ( V_323 | V_324 ) ;
V_289 . V_291 &= ~ ( V_325 ) ;
V_289 . V_293 |= F_270 ( V_44 ) | F_271 ( V_168 ) ;
V_289 . V_291 |= F_272 ( V_168 ) ;
F_273 ( V_13 , & V_289 ) ;
}
static int
F_274 ( struct V_81 * V_58 , const struct V_133 * V_69 , bool V_238 )
{
struct V_38 * V_39 = V_58 -> V_82 ;
unsigned int V_168 ;
int V_239 ;
V_239 = F_196 ( V_58 , V_69 , & V_168 ) ;
if ( V_239 )
return V_239 ;
F_268 ( V_58 -> V_13 , V_168 , V_39 -> V_44 ) ;
return V_240 ;
}
int F_275 ( unsigned int V_13 , struct V_286 * V_277 )
{
struct V_38 * V_39 ;
struct V_322 V_289 ;
unsigned V_168 ;
int V_98 ;
if ( V_304 )
return - V_305 ;
V_39 = V_38 ( V_13 ) ;
V_98 = F_131 ( V_13 , V_39 , V_53 -> V_169 () ) ;
if ( V_98 )
return V_98 ;
V_98 = V_53 -> V_170 ( V_39 -> V_46 ,
V_53 -> V_169 () , & V_168 ) ;
if ( V_98 )
return V_98 ;
V_289 . V_291 = F_272 ( V_168 ) ;
V_289 . V_293 =
V_326 |
F_271 ( V_168 ) |
F_270 ( V_39 -> V_44 ) |
( ( V_53 -> V_167 == 0 ) ?
V_327 :
V_328 ) |
V_329 |
( ( V_53 -> V_165 != V_297 ) ?
V_330 :
V_331 ) |
V_332 ;
F_273 ( V_13 , & V_289 ) ;
F_143 ( V_13 , & V_333 ,
V_162 , L_19 ) ;
F_252 ( V_96 , & V_277 -> V_277 , L_69 , V_13 ) ;
return 0 ;
}
static int
F_276 ( unsigned int V_13 , int V_36 , struct V_125 * V_164 )
{
struct V_38 * V_39 = F_22 ( V_13 , V_36 ) ;
int V_239 ;
if ( ! V_39 )
return - V_236 ;
V_239 = F_49 ( V_39 , V_36 , V_164 -> V_8 , V_164 -> V_171 ) ;
if ( ! V_239 )
F_145 ( V_13 , V_39 , V_164 ) ;
return V_239 ;
}
static int T_2 F_277 ( int V_8 )
{
union V_334 V_335 ;
unsigned long V_66 ;
F_43 ( & V_67 , V_66 ) ;
V_335 . V_201 = F_41 ( V_8 , 1 ) ;
F_44 ( & V_67 , V_66 ) ;
return V_335 . V_203 . V_336 + 1 ;
}
unsigned int F_278 ( unsigned int V_337 )
{
return V_284 ? V_279 : V_338 ;
}
int T_2 F_279 ( void )
{
int V_339 ;
if ( V_340 > ( V_153 * V_145 ) )
V_340 = V_153 * V_145 ;
V_339 = ( V_338 + F_7 () ) + 8 * V_145 ;
#if F_280 ( V_341 ) || F_280 ( V_342 )
V_339 += V_338 * 16 ;
#endif
if ( V_339 < V_340 )
V_340 = V_339 ;
return 0 ;
}
static int T_2 F_281 ( int V_8 , int V_343 )
{
union V_195 V_196 ;
static T_6 V_344 = V_345 ;
T_6 V_206 ;
unsigned long V_66 ;
int V_24 = 0 ;
if ( F_282 ( V_344 ) )
V_53 -> V_199 ( & V_200 , & V_344 ) ;
F_43 ( & V_67 , V_66 ) ;
V_196 . V_201 = F_41 ( V_8 , 0 ) ;
F_44 ( & V_67 , V_66 ) ;
if ( V_343 >= F_164 () ) {
F_157 ( V_192 L_70
L_71 , V_8 , V_343 , V_196 . V_203 . V_204 ) ;
V_343 = V_196 . V_203 . V_204 ;
}
if ( V_53 -> V_205 ( & V_344 , V_343 ) ) {
for ( V_24 = 0 ; V_24 < F_164 () ; V_24 ++ ) {
if ( ! V_53 -> V_205 ( & V_344 , V_24 ) )
break;
}
if ( V_24 == F_164 () )
F_14 ( L_72 ) ;
F_157 ( V_192 L_73
L_74 , V_8 , V_343 , V_24 ) ;
V_343 = V_24 ;
}
V_53 -> V_207 ( V_343 , & V_206 ) ;
F_167 ( V_344 , V_344 , V_206 ) ;
if ( V_196 . V_203 . V_204 != V_343 ) {
V_196 . V_203 . V_204 = V_343 ;
F_43 ( & V_67 , V_66 ) ;
F_46 ( V_8 , 0 , V_196 . V_201 ) ;
V_196 . V_201 = F_41 ( V_8 , 0 ) ;
F_44 ( & V_67 , V_66 ) ;
if ( V_196 . V_203 . V_204 != V_343 ) {
F_21 ( L_75 ,
V_8 ) ;
return - 1 ;
}
}
F_13 ( V_25 , V_95
L_76 , V_8 , V_343 ) ;
return V_343 ;
}
static T_9 T_2 F_283 ( T_9 V_319 )
{
if ( ( V_209 . V_210 == V_211 ) &&
! F_169 ( V_212 [ V_213 ] ) )
return F_281 ( V_346 , V_319 ) ;
else
return V_319 ;
}
static T_9 T_2 F_283 ( T_9 V_319 )
{
int V_24 ;
F_284 ( V_347 , 256 ) ;
F_285 ( V_347 , 256 ) ;
F_19 (i)
F_286 ( F_1 ( V_24 ) , V_347 ) ;
if ( ! F_79 ( V_319 , V_347 ) )
return V_319 ;
return F_287 ( V_347 , 256 ) ;
}
static int T_2 F_288 ( int V_8 )
{
union V_334 V_335 ;
unsigned long V_66 ;
F_43 ( & V_67 , V_66 ) ;
V_335 . V_201 = F_41 ( V_8 , 1 ) ;
F_44 ( & V_67 , V_66 ) ;
return V_335 . V_203 . V_348 ;
}
int F_289 ( T_1 V_110 , int * V_84 , int * V_105 )
{
int V_8 , V_12 , V_103 ;
if ( V_20 )
return - 1 ;
V_8 = F_104 ( V_110 ) ;
if ( V_8 < 0 )
return - 1 ;
V_12 = F_105 ( V_8 , V_110 ) ;
if ( V_12 < 0 )
return - 1 ;
V_103 = F_77 ( V_8 , V_12 , V_121 ) ;
if ( V_103 < 0 )
return - 1 ;
* V_84 = F_87 ( V_103 ) ;
* V_105 = F_83 ( V_103 ) ;
return 0 ;
}
void T_2 F_290 ( void )
{
int V_12 , V_8 , V_13 , V_349 ;
const struct V_133 * V_69 ;
struct V_81 * V_350 ;
if ( V_20 == 1 )
return;
F_69 (ioapic, pin) {
V_349 = F_77 ( V_8 , V_12 , V_121 ) ;
if ( V_349 == - 1 )
continue;
V_13 = F_101 ( V_349 , V_8 , V_12 , 0 ) ;
if ( V_13 < 0 || ! F_6 ( V_8 , V_13 ) )
continue;
V_350 = F_107 ( V_13 ) ;
if ( ! F_291 ( V_350 ) || F_292 ( V_350 ) )
V_69 = V_350 -> V_237 ;
else
V_69 = V_53 -> V_169 () ;
V_86 . V_351 ( V_350 , V_69 , false ) ;
}
}
static struct V_352 * T_2 F_293 ( void )
{
unsigned long V_353 ;
struct V_352 * V_51 ;
char * V_354 ;
int V_24 , V_183 = 0 ;
F_19 (i)
V_183 ++ ;
if ( V_183 == 0 )
return NULL ;
V_353 = V_355 + sizeof( struct V_352 ) ;
V_353 *= V_183 ;
V_354 = F_294 ( V_353 ) ;
V_51 = ( void * ) V_354 ;
V_354 += sizeof( struct V_352 ) * V_183 ;
V_183 = 0 ;
F_19 (i) {
V_51 [ V_183 ] . V_356 = V_354 ;
V_51 [ V_183 ] . V_66 = V_357 | V_358 ;
snprintf ( V_354 , V_355 , L_77 , V_24 ) ;
V_354 += V_355 ;
V_183 ++ ;
}
V_359 = V_51 ;
return V_51 ;
}
void T_2 F_295 ( void )
{
unsigned long V_360 , V_103 = V_361 ;
struct V_352 * V_362 ;
int V_24 ;
V_362 = F_293 () ;
F_19 (i) {
if ( V_363 ) {
V_360 = F_2 ( V_24 ) ;
#ifdef F_102
if ( ! V_360 ) {
F_157 ( V_202
L_78
L_79
L_80 ) ;
V_363 = 0 ;
V_20 = 1 ;
goto V_364;
}
#endif
} else {
#ifdef F_102
V_364:
#endif
V_360 = ( unsigned long ) F_296 ( V_365 ) ;
V_360 = F_297 ( V_360 ) ;
}
F_298 ( V_103 , V_360 ) ;
F_13 ( V_25 , L_81 ,
F_299 ( V_103 ) + ( V_360 & ~ V_366 ) ,
V_360 ) ;
V_103 ++ ;
V_362 -> V_367 = V_360 ;
V_362 -> V_368 = V_360 + V_369 - 1 ;
V_362 ++ ;
}
}
void T_2 F_300 ( void )
{
int V_24 ;
struct V_352 * V_370 = V_359 ;
if ( ! V_370 ) {
if ( V_346 > 0 )
F_157 ( V_202
L_82 ) ;
return;
}
F_19 (i) {
F_301 ( & V_371 , V_370 ) ;
V_370 ++ ;
}
}
int F_104 ( T_1 V_110 )
{
int V_24 ;
if ( V_346 == 0 )
return - 1 ;
F_19 (i) {
struct V_6 * V_9 = F_3 ( V_24 ) ;
if ( V_110 >= V_9 -> V_11 && V_110 <= V_9 -> V_10 )
return V_24 ;
}
F_157 ( V_202 L_83 , V_110 ) ;
return - 1 ;
}
int F_105 ( int V_8 , T_1 V_110 )
{
struct V_6 * V_9 ;
if ( F_302 ( V_8 < 0 ) )
return - 1 ;
V_9 = F_3 ( V_8 ) ;
if ( F_302 ( V_110 > V_9 -> V_10 ) )
return - 1 ;
return V_110 - V_9 -> V_11 ;
}
static T_2 int F_303 ( unsigned long V_372 )
{
if ( V_346 >= V_373 ) {
F_86 ( L_84 ,
V_373 , V_346 ) ;
return 1 ;
}
if ( ! V_372 ) {
F_86 ( L_85 ) ;
return 1 ;
}
return 0 ;
}
static T_2 int F_304 ( int V_103 )
{
union V_195 V_196 ;
union V_334 V_335 ;
union V_374 V_375 ;
V_196 . V_201 = F_41 ( V_103 , 0 ) ;
V_335 . V_201 = F_41 ( V_103 , 1 ) ;
V_375 . V_201 = F_41 ( V_103 , 2 ) ;
if ( V_196 . V_201 == - 1 && V_335 . V_201 == - 1 && V_375 . V_201 == - 1 ) {
F_86 ( L_86 ,
F_2 ( V_103 ) ) ;
return 1 ;
}
return 0 ;
}
void T_2 F_305 ( int V_319 , T_1 V_372 , T_1 V_11 ,
struct V_275 * V_39 )
{
int V_103 = 0 ;
int V_336 ;
struct V_6 * V_9 ;
if ( F_303 ( V_372 ) )
return;
V_103 = V_346 ;
V_2 [ V_103 ] . V_3 . type = V_376 ;
V_2 [ V_103 ] . V_3 . V_66 = V_377 ;
V_2 [ V_103 ] . V_3 . V_5 = V_372 ;
V_2 [ V_103 ] . V_17 = NULL ;
V_2 [ V_103 ] . V_112 = * V_39 ;
F_298 ( V_361 + V_103 , V_372 ) ;
if ( F_304 ( V_103 ) ) {
F_306 ( V_361 + V_103 ) ;
return;
}
V_2 [ V_103 ] . V_3 . V_4 = F_283 ( V_319 ) ;
V_2 [ V_103 ] . V_3 . V_378 = F_288 ( V_103 ) ;
V_336 = F_277 ( V_103 ) ;
V_9 = F_3 ( V_103 ) ;
V_9 -> V_11 = V_11 ;
V_9 -> V_10 = V_11 + V_336 - 1 ;
V_2 [ V_103 ] . V_43 = V_336 ;
if ( V_9 -> V_10 >= V_338 )
V_338 = V_9 -> V_10 + 1 ;
F_307 ( L_87 ,
V_103 , F_1 ( V_103 ) ,
F_65 ( V_103 ) , F_2 ( V_103 ) ,
V_9 -> V_11 , V_9 -> V_10 ) ;
V_346 ++ ;
}
int F_98 ( struct V_16 * V_46 , unsigned int V_379 ,
T_11 V_123 )
{
int V_8 = ( int ) ( long ) V_46 -> V_111 ;
struct V_14 * V_116 = V_14 ( V_8 , V_123 ) ;
struct V_125 V_164 ;
if ( ! V_116 -> V_120 ) {
T_1 V_110 = F_5 ( V_8 , V_123 ) ;
if ( F_289 ( V_110 , & V_116 -> V_84 ,
& V_116 -> V_105 ) < 0 ) {
V_116 -> V_84 = 1 ;
V_116 -> V_105 = 1 ;
}
V_116 -> V_36 = V_380 ;
if ( V_379 >= F_7 () || V_116 -> V_119 )
V_116 -> V_120 = 1 ;
}
F_112 ( & V_164 , V_8 , V_123 , V_116 -> V_84 ,
V_116 -> V_105 ) ;
return F_276 ( V_379 , V_116 -> V_36 , & V_164 ) ;
}
void F_108 ( struct V_16 * V_46 , unsigned int V_379 )
{
struct V_81 * V_58 = F_107 ( V_379 ) ;
struct V_38 * V_39 = V_38 ( V_379 ) ;
int V_8 = ( int ) ( long ) V_46 -> V_111 ;
int V_12 = ( int ) V_58 -> V_123 ;
F_48 ( V_8 , V_12 ) ;
F_51 ( V_39 , V_8 , V_12 ) ;
F_302 ( V_39 -> V_71 != NULL ) ;
F_238 ( V_379 ) ;
}
int F_308 ( T_1 V_110 , int V_84 , int V_105 , int V_36 )
{
int V_239 = 0 ;
int V_8 , V_12 ;
struct V_14 * V_116 ;
V_8 = F_104 ( V_110 ) ;
if ( V_8 < 0 )
return - V_381 ;
V_12 = F_105 ( V_8 , V_110 ) ;
V_116 = V_14 ( V_8 , V_12 ) ;
V_84 = V_84 ? 1 : 0 ;
V_105 = V_105 ? 1 : 0 ;
F_97 ( & V_117 ) ;
if ( ! V_116 -> V_120 ) {
V_116 -> V_84 = V_84 ;
V_116 -> V_105 = V_105 ;
V_116 -> V_36 = V_36 ;
V_116 -> V_120 = 1 ;
} else if ( V_116 -> V_84 != V_84 || V_116 -> V_105 != V_105 ) {
V_239 = - V_141 ;
}
F_100 ( & V_117 ) ;
return V_239 ;
}
bool F_309 ( struct V_382 * V_277 )
{
if ( V_277 -> V_383 . V_384 )
return true ;
#ifdef F_310
if ( V_277 -> V_383 . V_385 == V_386 )
return true ;
#endif
return false ;
}
void T_2 F_311 ( void )
{
struct V_125 V_164 = { 0 , 0 , 0 , 0 } ;
F_157 ( V_95 L_88 ) ;
#ifndef V_234
F_312 ( V_213 ,
& V_200 ) ;
#endif
F_313 () ;
F_276 ( 0 , 0 , & V_164 ) ;
F_143 ( 0 , & V_156 , V_162 ,
L_19 ) ;
}
