int F_1 ( int V_1 )
{
return V_2 [ V_1 ] . V_3 . V_4 ;
}
unsigned int F_2 ( int V_1 )
{
return V_2 [ V_1 ] . V_3 . V_5 ;
}
static inline struct V_6 * F_3 ( int V_1 )
{
return & V_2 [ V_1 ] . V_7 ;
}
static inline int F_4 ( int V_8 )
{
struct V_6 * V_9 = F_3 ( V_8 ) ;
return V_9 -> V_10 - V_9 -> V_11 + 1 ;
}
static inline T_1 F_5 ( int V_8 , int V_12 )
{
return F_3 ( V_8 ) -> V_11 + V_12 ;
}
static inline bool F_6 ( int V_13 )
{
return V_13 >= 0 && V_13 < F_7 () ;
}
static inline int F_8 ( int V_8 , int V_13 )
{
if ( ! F_7 () )
return 0 ;
return V_8 == 0 || F_6 ( V_13 ) ;
}
static inline struct V_14 * F_9 ( int V_8 )
{
return V_2 [ V_8 ] . V_15 ;
}
void F_10 ( void )
{
#ifdef F_11
V_16 = 1 ;
V_17 = - 1 ;
#endif
V_18 = 1 ;
}
static int T_2 F_12 ( char * V_19 )
{
F_10 () ;
return 0 ;
}
void F_13 ( struct V_20 * V_21 )
{
int V_22 ;
F_14 ( V_23 , L_1
L_2 ,
V_21 -> V_24 , V_21 -> V_25 & 3 , ( V_21 -> V_25 >> 2 ) & 3 , V_21 -> V_26 ,
V_21 -> V_27 , V_21 -> V_28 , V_21 -> V_29 ) ;
for ( V_22 = 0 ; V_22 < V_30 ; V_22 ++ ) {
if ( ! memcmp ( & V_31 [ V_22 ] , V_21 , sizeof( * V_21 ) ) )
return;
}
memcpy ( & V_31 [ V_30 ] , V_21 , sizeof( * V_21 ) ) ;
if ( ++ V_30 == V_32 )
F_15 ( L_3 ) ;
}
static void F_16 ( int V_33 )
{
T_3 V_34 ;
if ( V_2 [ V_33 ] . V_35 )
return;
V_34 = sizeof( struct V_36 ) * V_2 [ V_33 ] . V_37 ;
V_2 [ V_33 ] . V_35 = F_17 ( V_34 , V_38 ) ;
if ( ! V_2 [ V_33 ] . V_35 )
F_18 ( L_4 , V_33 ) ;
}
static void F_19 ( int V_33 )
{
F_20 ( V_2 [ V_33 ] . V_35 ) ;
V_2 [ V_33 ] . V_35 = NULL ;
}
int T_2 F_21 ( void )
{
int V_22 ;
if ( ! F_7 () )
V_39 = ~ 0UL ;
F_22 (i)
F_16 ( V_22 ) ;
return 0 ;
}
static inline void F_23 ( unsigned int V_40 , unsigned int V_41 )
{
struct V_42 T_4 * V_42 = F_24 ( V_40 ) ;
F_25 ( V_41 , & V_42 -> V_43 ) ;
}
unsigned int F_26 ( unsigned int V_40 , unsigned int V_44 )
{
struct V_42 T_4 * V_42 = F_24 ( V_40 ) ;
F_25 ( V_44 , & V_42 -> V_45 ) ;
return F_27 ( & V_42 -> V_46 ) ;
}
static void F_28 ( unsigned int V_40 , unsigned int V_44 ,
unsigned int V_47 )
{
struct V_42 T_4 * V_42 = F_24 ( V_40 ) ;
F_25 ( V_44 , & V_42 -> V_45 ) ;
F_25 ( V_47 , & V_42 -> V_46 ) ;
}
static struct V_36 F_29 ( int V_40 , int V_12 )
{
union V_48 V_49 ;
V_49 . V_50 = F_30 ( V_40 , 0x10 + 2 * V_12 ) ;
V_49 . V_51 = F_30 ( V_40 , 0x11 + 2 * V_12 ) ;
return V_49 . V_52 ;
}
static struct V_36 F_31 ( int V_40 , int V_12 )
{
union V_48 V_49 ;
unsigned long V_53 ;
F_32 ( & V_54 , V_53 ) ;
V_49 . V_52 = F_29 ( V_40 , V_12 ) ;
F_33 ( & V_54 , V_53 ) ;
return V_49 . V_52 ;
}
static void F_34 ( int V_40 , int V_12 , struct V_36 V_55 )
{
union V_48 V_49 = { { 0 , 0 } } ;
V_49 . V_52 = V_55 ;
F_28 ( V_40 , 0x11 + 2 * V_12 , V_49 . V_51 ) ;
F_28 ( V_40 , 0x10 + 2 * V_12 , V_49 . V_50 ) ;
}
static void F_35 ( int V_40 , int V_12 , struct V_36 V_55 )
{
unsigned long V_53 ;
F_32 ( & V_54 , V_53 ) ;
F_34 ( V_40 , V_12 , V_55 ) ;
F_33 ( & V_54 , V_53 ) ;
}
static void F_36 ( int V_40 , int V_12 )
{
unsigned long V_53 ;
union V_48 V_49 = { . V_52 . V_56 = V_57 } ;
F_32 ( & V_54 , V_53 ) ;
F_28 ( V_40 , 0x10 + 2 * V_12 , V_49 . V_50 ) ;
F_28 ( V_40 , 0x11 + 2 * V_12 , V_49 . V_51 ) ;
F_33 ( & V_54 , V_53 ) ;
}
static int F_37 ( struct V_58 * V_46 ,
int V_59 , int V_40 , int V_12 )
{
struct V_60 * V_52 ;
F_38 (entry, data->irq_2_pin)
if ( V_52 -> V_40 == V_40 && V_52 -> V_12 == V_12 )
return 0 ;
V_52 = F_39 ( sizeof( struct V_60 ) , V_61 , V_59 ) ;
if ( ! V_52 ) {
F_18 ( L_5 ,
V_59 , V_40 , V_12 ) ;
return - V_62 ;
}
V_52 -> V_40 = V_40 ;
V_52 -> V_12 = V_12 ;
F_40 ( & V_52 -> V_63 , & V_46 -> V_64 ) ;
return 0 ;
}
static void F_41 ( struct V_58 * V_46 , int V_40 , int V_12 )
{
struct V_60 * V_65 , * V_52 ;
F_42 (entry, tmp, &data->irq_2_pin, list)
if ( V_52 -> V_40 == V_40 && V_52 -> V_12 == V_12 ) {
F_43 ( & V_52 -> V_63 ) ;
F_20 ( V_52 ) ;
return;
}
}
static void F_44 ( struct V_58 * V_46 ,
int V_59 , int V_40 , int V_12 )
{
if ( F_37 ( V_46 , V_59 , V_40 , V_12 ) )
F_15 ( L_6 ) ;
}
static void T_2 F_45 ( struct V_58 * V_46 , int V_59 ,
int V_66 , int V_67 ,
int V_68 , int V_69 )
{
struct V_60 * V_52 ;
F_38 (entry, data->irq_2_pin) {
if ( V_52 -> V_40 == V_66 && V_52 -> V_12 == V_67 ) {
V_52 -> V_40 = V_68 ;
V_52 -> V_12 = V_69 ;
return;
}
}
F_44 ( V_46 , V_59 , V_68 , V_69 ) ;
}
static void F_46 ( struct V_58 * V_46 ,
int V_70 , int V_71 ,
void (* F_47)( struct V_60 * V_52 ) )
{
union V_48 V_49 ;
struct V_60 * V_52 ;
V_49 . V_52 = V_46 -> V_52 ;
V_49 . V_50 &= V_70 ;
V_49 . V_50 |= V_71 ;
V_46 -> V_52 = V_49 . V_52 ;
F_38 (entry, data->irq_2_pin) {
F_28 ( V_52 -> V_40 , 0x10 + 2 * V_52 -> V_12 , V_49 . V_50 ) ;
if ( F_47 )
F_47 ( V_52 ) ;
}
}
static void F_48 ( struct V_60 * V_52 )
{
struct V_42 T_4 * V_42 ;
V_42 = F_24 ( V_52 -> V_40 ) ;
F_27 ( & V_42 -> V_46 ) ;
}
static void F_49 ( struct V_72 * V_72 )
{
struct V_58 * V_46 = V_72 -> V_73 ;
unsigned long V_53 ;
F_32 ( & V_54 , V_53 ) ;
F_46 ( V_46 , ~ 0 , V_74 , & F_48 ) ;
F_33 ( & V_54 , V_53 ) ;
}
static void F_50 ( struct V_58 * V_46 )
{
F_46 ( V_46 , ~ V_74 , 0 , NULL ) ;
}
static void F_51 ( struct V_72 * V_72 )
{
struct V_58 * V_46 = V_72 -> V_73 ;
unsigned long V_53 ;
F_32 ( & V_54 , V_53 ) ;
F_50 ( V_46 ) ;
F_33 ( & V_54 , V_53 ) ;
}
static void F_52 ( int V_40 , int V_12 , int V_41 )
{
if ( F_53 ( V_40 ) >= 0x20 ) {
F_23 ( V_40 , V_41 ) ;
} else {
struct V_36 V_52 , V_75 ;
V_52 = V_75 = F_29 ( V_40 , V_12 ) ;
V_75 . V_56 = V_57 ;
V_75 . V_76 = V_77 ;
F_34 ( V_40 , V_12 , V_75 ) ;
F_34 ( V_40 , V_12 , V_52 ) ;
}
}
void F_54 ( int V_41 , struct V_58 * V_46 )
{
unsigned long V_53 ;
struct V_60 * V_52 ;
F_32 ( & V_54 , V_53 ) ;
F_38 (entry, data->irq_2_pin)
F_52 ( V_52 -> V_40 , V_52 -> V_12 , V_41 ) ;
F_33 ( & V_54 , V_53 ) ;
}
static void F_55 ( unsigned int V_40 , unsigned int V_12 )
{
struct V_36 V_52 ;
V_52 = F_31 ( V_40 , V_12 ) ;
if ( V_52 . V_78 == V_79 )
return;
if ( V_52 . V_56 == V_80 ) {
V_52 . V_56 = V_57 ;
F_35 ( V_40 , V_12 , V_52 ) ;
V_52 = F_31 ( V_40 , V_12 ) ;
}
if ( V_52 . V_81 ) {
unsigned long V_53 ;
if ( V_52 . V_76 == V_77 ) {
V_52 . V_76 = V_82 ;
F_35 ( V_40 , V_12 , V_52 ) ;
}
F_32 ( & V_54 , V_53 ) ;
F_52 ( V_40 , V_12 , V_52 . V_41 ) ;
F_33 ( & V_54 , V_53 ) ;
}
F_36 ( V_40 , V_12 ) ;
V_52 = F_31 ( V_40 , V_12 ) ;
if ( V_52 . V_81 )
F_18 ( L_7 ,
F_1 ( V_40 ) , V_12 ) ;
}
static void F_56 ( void )
{
int V_40 , V_12 ;
F_57 (apic, pin)
F_55 ( V_40 , V_12 ) ;
}
static int T_2 F_58 ( char * V_19 )
{
int V_22 , V_83 ;
int V_84 [ V_85 + 1 ] ;
F_59 ( V_19 , F_60 ( V_84 ) , V_84 ) ;
F_14 ( V_23 , V_86
L_8 ) ;
V_83 = V_85 ;
if ( V_84 [ 0 ] < V_85 )
V_83 = V_84 [ 0 ] ;
for ( V_22 = 0 ; V_22 < V_83 ; V_22 ++ ) {
F_14 ( V_23 , V_87
L_9 , V_22 , V_84 [ V_22 + 1 ] ) ;
V_88 [ V_85 - V_22 - 1 ] = V_84 [ V_22 + 1 ] ;
}
return 1 ;
}
int F_61 ( void )
{
int V_40 , V_12 ;
int V_89 = 0 ;
F_22 (apic) {
if ( ! V_2 [ V_40 ] . V_35 ) {
V_89 = - V_62 ;
continue;
}
F_62 (apic, pin)
V_2 [ V_40 ] . V_35 [ V_12 ] =
F_31 ( V_40 , V_12 ) ;
}
return V_89 ;
}
void F_63 ( void )
{
int V_40 , V_12 ;
F_22 (apic) {
if ( ! V_2 [ V_40 ] . V_35 )
continue;
F_62 (apic, pin) {
struct V_36 V_52 ;
V_52 = V_2 [ V_40 ] . V_35 [ V_12 ] ;
if ( V_52 . V_56 == V_80 ) {
V_52 . V_56 = V_57 ;
F_35 ( V_40 , V_12 , V_52 ) ;
}
}
}
}
int F_64 ( void )
{
int V_40 , V_12 ;
F_22 (apic) {
if ( ! V_2 [ V_40 ] . V_35 )
continue;
F_62 (apic, pin)
F_35 ( V_40 , V_12 ,
V_2 [ V_40 ] . V_35 [ V_12 ] ) ;
}
return 0 ;
}
static int F_65 ( int V_1 , int V_12 , int type )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_30 ; V_22 ++ )
if ( V_31 [ V_22 ] . V_24 == type &&
( V_31 [ V_22 ] . V_28 == F_1 ( V_1 ) ||
V_31 [ V_22 ] . V_28 == V_90 ) &&
V_31 [ V_22 ] . V_29 == V_12 )
return V_22 ;
return - 1 ;
}
static int T_2 F_66 ( int V_13 , int type )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_30 ; V_22 ++ ) {
int V_91 = V_31 [ V_22 ] . V_26 ;
if ( F_67 ( V_91 , V_92 ) &&
( V_31 [ V_22 ] . V_24 == type ) &&
( V_31 [ V_22 ] . V_27 == V_13 ) )
return V_31 [ V_22 ] . V_29 ;
}
return - 1 ;
}
static int T_2 F_68 ( int V_13 , int type )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_30 ; V_22 ++ ) {
int V_91 = V_31 [ V_22 ] . V_26 ;
if ( F_67 ( V_91 , V_92 ) &&
( V_31 [ V_22 ] . V_24 == type ) &&
( V_31 [ V_22 ] . V_27 == V_13 ) )
break;
}
if ( V_22 < V_30 ) {
int V_1 ;
F_22 (ioapic_idx)
if ( F_1 ( V_1 ) == V_31 [ V_22 ] . V_28 )
return V_1 ;
}
return - 1 ;
}
static int F_69 ( unsigned int V_13 )
{
if ( V_13 < F_7 () ) {
unsigned int V_93 = 0x4d0 + ( V_13 >> 3 ) ;
return ( F_70 ( V_93 ) >> ( V_13 & 7 ) ) & 1 ;
}
F_14 ( V_23 , V_86
L_10 , V_13 ) ;
return 0 ;
}
static int F_71 ( int V_33 )
{
int V_94 = V_31 [ V_33 ] . V_26 ;
switch ( V_31 [ V_33 ] . V_25 & 0x03 ) {
case 0 :
if ( F_67 ( V_94 , V_92 ) )
return F_72 ( V_33 ) ;
else
return F_73 ( V_33 ) ;
case 1 :
return V_95 ;
case 2 :
F_74 ( L_11 ) ;
case 3 :
default:
return V_96 ;
}
}
static int F_75 ( int V_33 , int V_94 , int V_76 )
{
switch ( V_97 [ V_94 ] ) {
case V_98 :
case V_99 :
return V_76 ;
case V_100 :
return F_76 ( V_33 ) ;
}
F_74 ( L_12 , V_94 ) ;
return V_82 ;
}
static inline int F_75 ( int V_33 , int V_94 , int V_76 )
{
return V_76 ;
}
static int F_77 ( int V_33 )
{
int V_94 = V_31 [ V_33 ] . V_26 ;
int V_76 ;
switch ( ( V_31 [ V_33 ] . V_25 >> 2 ) & 0x03 ) {
case 0 :
if ( F_67 ( V_94 , V_92 ) )
V_76 = F_78 ( V_33 ) ;
else
V_76 = F_79 ( V_33 ) ;
return F_75 ( V_33 , V_94 , V_76 ) ;
case 1 :
return V_77 ;
case 2 :
F_74 ( L_13 ) ;
case 3 :
default:
return V_82 ;
}
}
void F_80 ( struct V_101 * V_102 , int V_59 ,
int V_76 , int V_103 )
{
F_81 ( V_102 , NULL ) ;
V_102 -> type = V_104 ;
V_102 -> V_105 = V_59 ;
V_102 -> V_106 = V_76 ;
V_102 -> V_107 = V_103 ;
V_102 -> V_108 = 1 ;
}
static void F_82 ( struct V_101 * V_109 ,
struct V_101 * V_110 ,
T_1 V_111 , int V_1 , int V_12 )
{
int V_76 , V_103 ;
F_83 ( V_109 , V_110 ) ;
V_109 -> type = V_104 ;
V_109 -> V_112 = F_1 ( V_1 ) ;
V_109 -> V_113 = V_12 ;
V_109 -> V_108 = 1 ;
if ( V_110 && V_110 -> V_108 ) {
V_109 -> V_105 = V_110 -> V_105 ;
V_109 -> V_106 = V_110 -> V_106 ;
V_109 -> V_107 = V_110 -> V_107 ;
} else {
V_109 -> V_105 = V_114 ;
if ( F_84 ( V_111 , & V_76 , & V_103 ) >= 0 ) {
V_109 -> V_106 = V_76 ;
V_109 -> V_107 = V_103 ;
} else {
V_109 -> V_106 = V_82 ;
V_109 -> V_107 = V_96 ;
}
}
}
static int F_85 ( struct V_101 * V_102 )
{
return ( V_102 && V_102 -> V_108 ) ? V_102 -> V_105 : V_114 ;
}
static void F_86 ( unsigned int V_13 , unsigned long V_76 )
{
T_5 V_115 ;
bool V_116 ;
if ( V_76 ) {
F_87 ( V_13 , V_117 ) ;
V_116 = true ;
} else {
F_88 ( V_13 , V_117 ) ;
V_116 = false ;
}
V_115 = V_116 ? V_118 : V_119 ;
F_89 ( V_13 , V_115 , 0 , V_116 ? L_14 : L_15 ) ;
}
static bool F_90 ( int V_13 , struct V_101 * V_102 )
{
struct V_58 * V_46 = F_91 ( V_13 ) ;
if ( V_13 < F_7 () && V_46 -> V_120 == 1 ) {
if ( V_102 -> V_106 != V_46 -> V_76 )
F_86 ( V_13 , V_102 -> V_106 ) ;
V_46 -> V_52 . V_76 = V_46 -> V_76 = V_102 -> V_106 ;
V_46 -> V_52 . V_103 = V_46 -> V_103 = V_102 -> V_107 ;
}
return V_46 -> V_76 == V_102 -> V_106 &&
V_46 -> V_103 == V_102 -> V_107 ;
}
static int F_92 ( struct V_14 * V_121 , int V_8 , T_1 V_111 ,
struct V_101 * V_102 )
{
bool V_122 = false ;
int V_13 = - 1 ;
int type = V_2 [ V_8 ] . V_123 . type ;
switch ( type ) {
case V_124 :
if ( ! V_125 || V_111 >= F_7 () )
V_13 = V_111 ;
V_122 = F_6 ( V_13 ) ;
break;
case V_126 :
V_13 = V_111 ;
break;
case V_127 :
break;
default:
F_93 ( 1 , L_16 , type ) ;
return - 1 ;
}
return F_94 ( V_121 , V_13 , 1 ,
F_85 ( V_102 ) ,
V_102 , V_122 ) ;
}
static int F_95 ( struct V_14 * V_121 ,
int V_13 , int V_8 , int V_12 ,
struct V_101 * V_102 )
{
struct V_58 * V_46 ;
struct V_72 * V_72 = F_96 ( V_13 ) ;
int V_59 = F_85 ( V_102 ) ;
if ( V_72 && V_72 -> V_128 ) {
if ( ! F_90 ( V_13 , V_102 ) )
return - V_129 ;
if ( F_37 ( V_72 -> V_73 , V_59 , V_8 ,
V_102 -> V_113 ) )
return - V_62 ;
} else {
V_13 = F_94 ( V_121 , V_13 , 1 , V_59 , V_102 , true ) ;
if ( V_13 >= 0 ) {
V_72 = F_97 ( V_121 , V_13 ) ;
V_46 = V_72 -> V_73 ;
V_46 -> V_130 = true ;
}
}
return V_13 ;
}
static int F_98 ( T_1 V_111 , int V_33 , int V_8 , int V_12 ,
unsigned int V_53 , struct V_101 * V_102 )
{
int V_13 ;
bool V_122 = false ;
struct V_101 V_65 ;
struct V_58 * V_46 ;
struct V_14 * V_121 = F_9 ( V_8 ) ;
if ( ! V_121 )
return - V_131 ;
if ( V_33 >= 0 && F_67 ( V_31 [ V_33 ] . V_26 , V_92 ) ) {
V_13 = V_31 [ V_33 ] . V_27 ;
V_122 = F_6 ( V_13 ) ;
}
F_99 ( & V_132 ) ;
if ( ! ( V_53 & V_133 ) ) {
if ( ! V_122 ) {
V_13 = F_100 ( V_121 , V_12 ) ;
if ( V_13 == 0 )
V_13 = - V_134 ;
}
} else {
F_82 ( & V_65 , V_102 , V_111 , V_8 , V_12 ) ;
if ( V_122 )
V_13 = F_95 ( V_121 , V_13 ,
V_8 , V_12 , & V_65 ) ;
else if ( ( V_13 = F_100 ( V_121 , V_12 ) ) == 0 )
V_13 = F_92 ( V_121 , V_8 , V_111 , & V_65 ) ;
else if ( ! F_90 ( V_13 , & V_65 ) )
V_13 = - V_129 ;
if ( V_13 >= 0 ) {
V_46 = F_91 ( V_13 ) ;
V_46 -> V_120 ++ ;
}
}
F_101 ( & V_132 ) ;
return V_13 ;
}
static int F_102 ( int V_33 , int V_8 , int V_12 , unsigned int V_53 )
{
T_1 V_111 = F_5 ( V_8 , V_12 ) ;
if ( V_31 [ V_33 ] . V_29 != V_12 )
F_18 ( L_17 ) ;
#ifdef F_103
if ( ( V_12 >= 16 ) && ( V_12 <= 23 ) ) {
if ( V_88 [ V_12 - 16 ] != - 1 ) {
if ( ! V_88 [ V_12 - 16 ] ) {
F_14 ( V_23 , V_87
L_18 , V_12 - 16 ) ;
} else {
int V_13 = V_88 [ V_12 - 16 ] ;
F_14 ( V_23 , V_87
L_19 ,
V_12 - 16 , V_13 ) ;
return V_13 ;
}
}
}
#endif
return F_98 ( V_111 , V_33 , V_8 , V_12 , V_53 , NULL ) ;
}
int F_104 ( T_1 V_111 , unsigned int V_53 , struct V_101 * V_102 )
{
int V_8 , V_12 , V_33 ;
V_8 = F_105 ( V_111 ) ;
if ( V_8 < 0 )
return - 1 ;
V_12 = F_106 ( V_8 , V_111 ) ;
V_33 = F_65 ( V_8 , V_12 , V_135 ) ;
if ( ( V_53 & V_136 ) && V_33 < 0 )
return - 1 ;
return F_98 ( V_111 , V_33 , V_8 , V_12 , V_53 , V_102 ) ;
}
void F_107 ( int V_13 )
{
struct V_72 * V_72 = F_96 ( V_13 ) ;
struct V_58 * V_46 ;
if ( ! V_72 || ! V_72 -> V_121 )
return;
V_46 = V_72 -> V_73 ;
if ( ! V_46 || V_46 -> V_130 )
return;
F_99 ( & V_132 ) ;
if ( -- V_46 -> V_120 == 0 )
F_108 ( V_13 , 1 ) ;
F_101 ( & V_132 ) ;
}
int F_109 ( int V_94 , int V_137 , int V_12 )
{
int V_13 , V_22 , V_138 = - 1 , V_139 = - 1 ;
F_14 ( V_140 ,
L_20 ,
V_94 , V_137 , V_12 ) ;
if ( F_67 ( V_94 , V_92 ) ) {
F_14 ( V_23 ,
L_21 , V_94 ) ;
return - 1 ;
}
for ( V_22 = 0 ; V_22 < V_30 ; V_22 ++ ) {
int V_91 = V_31 [ V_22 ] . V_26 ;
int V_1 , V_141 = 0 ;
if ( V_94 != V_91 || V_31 [ V_22 ] . V_24 != V_135 ||
V_137 != ( ( V_31 [ V_22 ] . V_27 >> 2 ) & 0x1f ) )
continue;
F_22 (ioapic_idx)
if ( F_1 ( V_1 ) == V_31 [ V_22 ] . V_28 ||
V_31 [ V_22 ] . V_28 == V_90 ) {
V_141 = 1 ;
break;
}
if ( ! V_141 )
continue;
V_13 = F_102 ( V_22 , V_1 , V_31 [ V_22 ] . V_29 , 0 ) ;
if ( V_13 > 0 && ! F_110 ( V_13 ) )
continue;
if ( V_12 == ( V_31 [ V_22 ] . V_27 & 3 ) ) {
V_139 = V_22 ;
V_138 = V_1 ;
goto V_142;
}
if ( V_139 < 0 ) {
V_139 = V_22 ;
V_138 = V_1 ;
}
}
if ( V_139 < 0 )
return - 1 ;
V_142:
return F_102 ( V_139 , V_138 , V_31 [ V_139 ] . V_29 ,
V_133 ) ;
}
static inline int F_111 ( int V_13 )
{
int V_40 , V_33 , V_12 ;
F_57 (apic, pin) {
V_33 = F_65 ( V_40 , V_12 , V_135 ) ;
if ( ( V_33 != - 1 ) && ( V_13 == F_102 ( V_33 , V_40 , V_12 , 0 ) ) )
return F_77 ( V_33 ) ;
}
return 0 ;
}
static inline int F_111 ( int V_13 )
{
return 1 ;
}
static void T_2 F_112 ( void )
{
unsigned int V_8 , V_12 ;
int V_33 ;
F_14 ( V_23 , V_87 L_22 ) ;
F_57 (ioapic, pin) {
V_33 = F_65 ( V_8 , V_12 , V_135 ) ;
if ( V_33 < 0 )
F_14 ( V_23 ,
V_87 L_23 ,
F_1 ( V_8 ) , V_12 ) ;
else
F_102 ( V_33 , V_8 , V_12 ,
V_8 ? 0 : V_133 ) ;
}
}
void F_113 ( void )
{
F_114 ( & V_54 ) ;
}
static void F_115 ( unsigned int V_40 , unsigned int V_143 )
{
int V_22 ;
char V_144 [ 256 ] ;
struct V_36 V_52 ;
struct V_145 * V_146 = ( void * ) & V_52 ;
F_116 ( V_87 L_24 , V_40 ) ;
for ( V_22 = 0 ; V_22 <= V_143 ; V_22 ++ ) {
V_52 = F_31 ( V_40 , V_22 ) ;
snprintf ( V_144 , sizeof( V_144 ) ,
L_25 ,
V_22 ,
V_52 . V_56 == V_57 ? L_26 : L_27 ,
V_52 . V_76 == V_82 ? L_28 : L_29 ,
V_52 . V_103 == V_96 ? L_30 : L_31 ,
V_52 . V_41 , V_52 . V_81 , V_52 . V_147 ) ;
if ( V_146 -> V_148 )
F_116 ( V_87 L_32 ,
V_144 , ( V_146 -> V_45 << 15 ) | V_146 -> V_45 ,
V_146 -> V_149 ) ;
else
F_116 ( V_87 L_33 ,
V_144 ,
V_52 . V_150 == V_151 ?
L_34 : L_35 ,
V_52 . V_152 , V_52 . V_78 ) ;
}
}
static void T_2 F_117 ( int V_1 )
{
union V_153 V_154 ;
union V_155 V_156 ;
union V_157 V_158 ;
union V_159 V_160 ;
unsigned long V_53 ;
F_32 ( & V_54 , V_53 ) ;
V_154 . V_161 = F_30 ( V_1 , 0 ) ;
V_156 . V_161 = F_30 ( V_1 , 1 ) ;
if ( V_156 . V_162 . V_163 >= 0x10 )
V_158 . V_161 = F_30 ( V_1 , 2 ) ;
if ( V_156 . V_162 . V_163 >= 0x20 )
V_160 . V_161 = F_30 ( V_1 , 3 ) ;
F_33 ( & V_54 , V_53 ) ;
F_116 ( V_87 L_36 , F_1 ( V_1 ) ) ;
F_116 ( V_87 L_37 , V_154 . V_161 ) ;
F_116 ( V_87 L_38 , V_154 . V_162 . V_164 ) ;
F_116 ( V_87 L_39 , V_154 . V_162 . V_165 ) ;
F_116 ( V_87 L_40 , V_154 . V_162 . V_166 ) ;
F_116 ( V_87 L_41 , * ( int * ) & V_156 ) ;
F_116 ( V_87 L_42 ,
V_156 . V_162 . V_167 ) ;
F_116 ( V_87 L_43 , V_156 . V_162 . V_168 ) ;
F_116 ( V_87 L_44 ,
V_156 . V_162 . V_163 ) ;
if ( V_156 . V_162 . V_163 >= 0x10 && V_158 . V_161 != V_156 . V_161 ) {
F_116 ( V_87 L_45 , V_158 . V_161 ) ;
F_116 ( V_87 L_46 , V_158 . V_162 . V_169 ) ;
}
if ( V_156 . V_162 . V_163 >= 0x20 && V_160 . V_161 != V_158 . V_161 &&
V_160 . V_161 != V_156 . V_161 ) {
F_116 ( V_87 L_47 , V_160 . V_161 ) ;
F_116 ( V_87 L_48 , V_160 . V_162 . V_170 ) ;
}
F_116 ( V_87 L_49 ) ;
F_115 ( V_1 , V_156 . V_162 . V_167 ) ;
}
void T_2 F_118 ( void )
{
int V_1 ;
unsigned int V_13 ;
F_116 ( V_87 L_50 , V_30 ) ;
F_22 (ioapic_idx)
F_116 ( V_87 L_51 ,
F_1 ( V_1 ) ,
V_2 [ V_1 ] . V_37 ) ;
F_116 ( V_86 L_52 ) ;
F_22 (ioapic_idx)
F_117 ( V_1 ) ;
F_116 ( V_87 L_53 ) ;
F_119 (irq) {
struct V_60 * V_52 ;
struct V_171 * V_172 ;
struct V_58 * V_46 ;
V_172 = F_120 ( V_13 ) ;
if ( V_172 != & V_173 && V_172 != & V_174 )
continue;
V_46 = F_91 ( V_13 ) ;
if ( ! V_46 )
continue;
if ( F_121 ( & V_46 -> V_64 ) )
continue;
F_116 ( V_87 L_54 , V_13 ) ;
F_38 (entry, data->irq_2_pin)
F_122 ( L_55 , V_52 -> V_40 , V_52 -> V_12 ) ;
F_122 ( L_56 ) ;
}
F_116 ( V_86 L_57 ) ;
}
void T_2 F_123 ( void )
{
int V_175 , V_176 ;
int V_40 , V_12 ;
if ( V_18 )
V_177 = 0 ;
if ( ! F_7 () || ! V_177 )
return;
F_57 (apic, pin) {
struct V_36 V_52 = F_31 ( V_40 , V_12 ) ;
if ( ( V_52 . V_56 == 0 ) && ( V_52 . V_78 == V_178 ) ) {
V_179 . V_40 = V_40 ;
V_179 . V_12 = V_12 ;
goto V_180;
}
}
V_180:
V_176 = F_66 ( 0 , V_181 ) ;
V_175 = F_68 ( 0 , V_181 ) ;
if ( ( V_179 . V_12 == - 1 ) && ( V_176 >= 0 ) ) {
F_116 ( V_182 L_58 ) ;
V_179 . V_12 = V_176 ;
V_179 . V_40 = V_175 ;
}
if ( ( ( V_179 . V_40 != V_175 ) || ( V_179 . V_12 != V_176 ) ) &&
( V_176 >= 0 ) && ( V_179 . V_12 >= 0 ) )
{
F_116 ( V_182 L_59 ) ;
}
F_56 () ;
}
void F_124 ( void )
{
if ( V_179 . V_12 != - 1 ) {
struct V_36 V_52 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_56 = V_80 ;
V_52 . V_76 = V_77 ;
V_52 . V_103 = V_95 ;
V_52 . V_150 = V_183 ;
V_52 . V_78 = V_178 ;
V_52 . V_152 = F_125 () ;
F_35 ( V_179 . V_40 , V_179 . V_12 , V_52 ) ;
}
if ( V_184 || F_126 () )
F_127 ( V_179 . V_12 != - 1 ) ;
}
void F_128 ( void )
{
F_56 () ;
if ( ! F_7 () )
return;
V_185 . V_186 () ;
}
void T_2 F_129 ( void )
{
union V_153 V_154 ;
T_6 V_187 ;
int V_1 ;
int V_22 ;
unsigned char V_188 ;
unsigned long V_53 ;
V_40 -> V_189 ( & V_190 , & V_187 ) ;
F_22 (ioapic_idx) {
F_32 ( & V_54 , V_53 ) ;
V_154 . V_161 = F_30 ( V_1 , 0 ) ;
F_33 ( & V_54 , V_53 ) ;
V_188 = F_1 ( V_1 ) ;
if ( F_1 ( V_1 ) >= F_130 () ) {
F_116 ( V_191 L_60 ,
V_1 , F_1 ( V_1 ) ) ;
F_116 ( V_191 L_61 ,
V_154 . V_162 . V_164 ) ;
V_2 [ V_1 ] . V_3 . V_4 = V_154 . V_162 . V_164 ;
}
if ( V_40 -> V_192 ( & V_187 ,
F_1 ( V_1 ) ) ) {
F_116 ( V_191 L_62 ,
V_1 , F_1 ( V_1 ) ) ;
for ( V_22 = 0 ; V_22 < F_130 () ; V_22 ++ )
if ( ! F_131 ( V_22 , V_187 ) )
break;
if ( V_22 >= F_130 () )
F_15 ( L_63 ) ;
F_116 ( V_191 L_61 ,
V_22 ) ;
F_132 ( V_22 , V_187 ) ;
V_2 [ V_1 ] . V_3 . V_4 = V_22 ;
} else {
T_6 V_65 ;
V_40 -> V_193 ( F_1 ( V_1 ) ,
& V_65 ) ;
F_14 ( V_23 , L_64
L_65 ,
F_1 ( V_1 ) ) ;
F_133 ( V_187 , V_187 , V_65 ) ;
}
if ( V_188 != F_1 ( V_1 ) )
for ( V_22 = 0 ; V_22 < V_30 ; V_22 ++ )
if ( V_31 [ V_22 ] . V_28 == V_188 )
V_31 [ V_22 ] . V_28
= F_1 ( V_1 ) ;
if ( F_1 ( V_1 ) == V_154 . V_162 . V_164 )
continue;
F_14 ( V_23 , V_86
L_66 ,
F_1 ( V_1 ) ) ;
V_154 . V_162 . V_164 = F_1 ( V_1 ) ;
F_32 ( & V_54 , V_53 ) ;
F_28 ( V_1 , 0 , V_154 . V_161 ) ;
F_33 ( & V_54 , V_53 ) ;
F_32 ( & V_54 , V_53 ) ;
V_154 . V_161 = F_30 ( V_1 , 0 ) ;
F_33 ( & V_54 , V_53 ) ;
if ( V_154 . V_162 . V_164 != F_1 ( V_1 ) )
F_122 ( L_67 ) ;
else
F_14 ( V_23 , L_68 ) ;
}
}
void T_2 F_134 ( void )
{
if ( V_194 )
return;
if ( ! ( V_195 . V_196 == V_197 )
|| F_135 ( V_198 [ V_199 ] ) )
return;
F_129 () ;
}
static int T_2 F_136 ( char * V_200 )
{
V_201 = 1 ;
return 1 ;
}
static int T_2 F_137 ( void )
{
unsigned long V_202 = V_203 ;
unsigned long V_53 ;
if ( V_201 )
return 1 ;
F_138 ( V_53 ) ;
F_139 () ;
F_140 ( ( 10 * 1000 ) / V_204 ) ;
F_141 ( V_53 ) ;
if ( F_142 ( V_203 , V_202 + 4 ) )
return 1 ;
return 0 ;
}
static unsigned int F_143 ( struct V_72 * V_46 )
{
int V_205 = 0 , V_13 = V_46 -> V_13 ;
unsigned long V_53 ;
F_32 ( & V_54 , V_53 ) ;
if ( V_13 < F_7 () ) {
V_206 -> V_56 ( V_13 ) ;
if ( V_206 -> V_207 ( V_13 ) )
V_205 = 1 ;
}
F_50 ( V_46 -> V_73 ) ;
F_33 ( & V_54 , V_53 ) ;
return V_205 ;
}
static bool F_144 ( struct V_58 * V_46 )
{
struct V_60 * V_52 ;
unsigned long V_53 ;
F_32 ( & V_54 , V_53 ) ;
F_38 (entry, data->irq_2_pin) {
unsigned int V_44 ;
int V_12 ;
V_12 = V_52 -> V_12 ;
V_44 = F_30 ( V_52 -> V_40 , 0x10 + V_12 * 2 ) ;
if ( V_44 & V_208 ) {
F_33 ( & V_54 , V_53 ) ;
return true ;
}
}
F_33 ( & V_54 , V_53 ) ;
return false ;
}
static inline bool F_145 ( struct V_72 * V_46 )
{
if ( F_146 ( F_147 ( V_46 ) ) ) {
F_49 ( V_46 ) ;
return true ;
}
return false ;
}
static inline void F_148 ( struct V_72 * V_46 , bool V_209 )
{
if ( F_146 ( V_209 ) ) {
if ( ! F_144 ( V_46 -> V_73 ) )
F_149 ( V_46 ) ;
F_51 ( V_46 ) ;
}
}
static inline bool F_145 ( struct V_72 * V_46 )
{
return false ;
}
static inline void F_148 ( struct V_72 * V_46 , bool V_209 )
{
}
static void F_150 ( struct V_72 * V_72 )
{
struct V_210 * V_211 = F_151 ( V_72 ) ;
unsigned long V_212 ;
bool V_209 ;
int V_22 ;
F_152 ( V_211 ) ;
V_209 = F_145 ( V_72 ) ;
V_22 = V_211 -> V_41 ;
V_212 = F_153 ( V_213 + ( ( V_22 & ~ 0x1f ) >> 1 ) ) ;
F_154 () ;
if ( ! ( V_212 & ( 1 << ( V_22 & 0x1f ) ) ) ) {
F_155 ( & V_214 ) ;
F_54 ( V_211 -> V_41 , V_72 -> V_73 ) ;
}
F_148 ( V_72 , V_209 ) ;
}
static void F_156 ( struct V_72 * V_72 )
{
struct V_58 * V_46 = V_72 -> V_73 ;
F_154 () ;
F_54 ( V_46 -> V_52 . V_41 , V_46 ) ;
}
static int F_157 ( struct V_72 * V_72 ,
const struct V_215 * V_56 , bool V_216 )
{
struct V_72 * V_217 = V_72 -> V_128 ;
struct V_58 * V_46 = V_72 -> V_73 ;
struct V_60 * V_52 ;
struct V_210 * V_211 ;
unsigned long V_53 ;
int V_218 ;
V_218 = V_217 -> V_172 -> V_219 ( V_217 , V_56 , V_216 ) ;
F_32 ( & V_54 , V_53 ) ;
if ( V_218 >= 0 && V_218 != V_220 ) {
V_211 = F_151 ( V_72 ) ;
V_46 -> V_52 . V_152 = V_211 -> V_221 ;
V_46 -> V_52 . V_41 = V_211 -> V_41 ;
F_38 (entry, data->irq_2_pin)
F_34 ( V_52 -> V_40 , V_52 -> V_12 ,
V_46 -> V_52 ) ;
}
F_33 ( & V_54 , V_53 ) ;
return V_218 ;
}
static inline void F_158 ( void )
{
struct V_210 * V_211 ;
unsigned int V_13 ;
F_119 (irq) {
V_211 = V_210 ( V_13 ) ;
if ( F_110 ( V_13 ) && V_211 && ! V_211 -> V_41 ) {
if ( V_13 < F_7 () )
V_206 -> V_222 ( V_13 ) ;
else
F_159 ( V_13 , & V_223 ) ;
}
}
}
static void F_160 ( struct V_72 * V_46 )
{
unsigned long V_212 ;
V_212 = F_153 ( V_224 ) ;
F_161 ( V_224 , V_212 | V_225 ) ;
}
static void F_162 ( struct V_72 * V_46 )
{
unsigned long V_212 ;
V_212 = F_153 ( V_224 ) ;
F_161 ( V_224 , V_212 & ~ V_225 ) ;
}
static void F_163 ( struct V_72 * V_46 )
{
F_154 () ;
}
static void F_164 ( int V_13 )
{
F_88 ( V_13 , V_117 ) ;
F_165 ( V_13 , & V_226 , V_119 ,
L_15 ) ;
}
static inline void T_2 F_166 ( void )
{
int V_40 , V_12 , V_22 ;
struct V_36 V_227 , V_75 ;
unsigned char V_228 , V_229 ;
V_12 = F_66 ( 8 , V_135 ) ;
if ( V_12 == - 1 ) {
F_167 ( 1 ) ;
return;
}
V_40 = F_68 ( 8 , V_135 ) ;
if ( V_40 == - 1 ) {
F_167 ( 1 ) ;
return;
}
V_227 = F_31 ( V_40 , V_12 ) ;
F_55 ( V_40 , V_12 ) ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_150 = V_183 ;
V_75 . V_56 = V_80 ;
V_75 . V_152 = F_168 () ;
V_75 . V_78 = V_178 ;
V_75 . V_103 = V_227 . V_103 ;
V_75 . V_76 = V_77 ;
V_75 . V_41 = 0 ;
F_35 ( V_40 , V_12 , V_75 ) ;
V_228 = F_169 ( V_230 ) ;
V_229 = F_169 ( V_231 ) ;
F_170 ( ( V_229 & ~ V_232 ) | 0x6 ,
V_231 ) ;
F_170 ( V_228 | V_233 , V_230 ) ;
V_22 = 100 ;
while ( V_22 -- > 0 ) {
F_140 ( 10 ) ;
if ( ( F_169 ( V_234 ) & V_235 ) == V_235 )
V_22 -= 10 ;
}
F_170 ( V_228 , V_230 ) ;
F_170 ( V_229 , V_231 ) ;
F_55 ( V_40 , V_12 ) ;
F_35 ( V_40 , V_12 , V_227 ) ;
}
static int T_2 F_171 ( char * V_236 )
{
V_237 = 1 ;
return 0 ;
}
static int F_172 ( int V_8 , int V_12 )
{
int V_13 = - 1 ;
struct V_14 * V_121 = F_9 ( V_8 ) ;
if ( V_121 ) {
struct V_101 V_102 ;
F_80 ( & V_102 , V_114 , 0 , 0 ) ;
V_102 . V_112 = F_1 ( V_8 ) ;
V_102 . V_113 = V_12 ;
F_99 ( & V_132 ) ;
V_13 = F_95 ( V_121 , 0 , V_8 , V_12 , & V_102 ) ;
F_101 ( & V_132 ) ;
}
return V_13 ;
}
static inline void T_2 F_173 ( void )
{
struct V_72 * V_72 = F_96 ( 0 ) ;
struct V_58 * V_46 = V_72 -> V_73 ;
struct V_210 * V_211 = F_151 ( V_72 ) ;
int V_59 = F_174 ( 0 ) ;
int V_238 , V_239 , V_240 , V_241 ;
unsigned long V_53 ;
int V_242 = 0 ;
F_175 ( V_53 ) ;
V_206 -> V_56 ( 0 ) ;
F_161 ( V_224 , V_225 | V_243 ) ;
V_206 -> V_244 ( 1 ) ;
V_239 = F_66 ( 0 , V_135 ) ;
V_238 = F_68 ( 0 , V_135 ) ;
V_241 = V_179 . V_12 ;
V_240 = V_179 . V_40 ;
F_14 ( V_245 , V_86 L_69
L_70 ,
V_211 -> V_41 , V_238 , V_239 , V_240 , V_241 ) ;
if ( V_239 == - 1 ) {
F_176 ( L_71 ) ;
V_239 = V_241 ;
V_238 = V_240 ;
V_242 = 1 ;
} else if ( V_241 == - 1 ) {
V_241 = V_239 ;
V_240 = V_238 ;
}
if ( V_239 != - 1 ) {
if ( V_242 ) {
F_172 ( V_238 , V_239 ) ;
} else {
int V_33 ;
V_33 = F_65 ( V_238 , V_239 , V_135 ) ;
if ( V_33 != - 1 && F_77 ( V_33 ) )
F_51 ( F_91 ( 0 ) ) ;
}
F_177 ( V_72 ) ;
if ( F_137 () ) {
if ( V_237 > 0 )
F_55 ( 0 , V_239 ) ;
goto V_142;
}
F_176 ( L_72 ) ;
F_178 () ;
F_55 ( V_238 , V_239 ) ;
if ( ! V_242 )
F_14 ( V_245 , V_191 L_73
L_74 ) ;
F_14 ( V_245 , V_86 L_75
L_76 ) ;
F_14 ( V_245 , V_86
L_77 , V_240 , V_241 ) ;
F_45 ( V_46 , V_59 , V_238 , V_239 , V_240 , V_241 ) ;
F_177 ( V_72 ) ;
V_206 -> V_246 ( 0 ) ;
if ( F_137 () ) {
F_14 ( V_245 , V_86 L_78 ) ;
goto V_142;
}
F_178 () ;
V_206 -> V_56 ( 0 ) ;
F_55 ( V_240 , V_241 ) ;
F_14 ( V_245 , V_86 L_79 ) ;
}
F_14 ( V_245 , V_86
L_80 ) ;
F_164 ( 0 ) ;
F_161 ( V_224 , V_247 | V_211 -> V_41 ) ;
V_206 -> V_246 ( 0 ) ;
if ( F_137 () ) {
F_14 ( V_245 , V_86 L_81 ) ;
goto V_142;
}
F_178 () ;
V_206 -> V_56 ( 0 ) ;
F_161 ( V_224 , V_225 | V_247 | V_211 -> V_41 ) ;
F_14 ( V_245 , V_86 L_82 ) ;
F_14 ( V_245 , V_86
L_83 ) ;
V_206 -> V_244 ( 0 ) ;
V_206 -> V_222 ( 0 ) ;
F_161 ( V_224 , V_243 ) ;
F_166 () ;
if ( F_137 () ) {
F_14 ( V_245 , V_86 L_81 ) ;
goto V_142;
}
F_178 () ;
F_14 ( V_245 , V_86 L_84 ) ;
if ( F_179 () )
F_14 ( V_245 , V_86
L_85
L_86 ) ;
F_15 ( L_87
L_88 ) ;
V_142:
F_141 ( V_53 ) ;
}
static int F_180 ( int V_8 )
{
struct V_101 V_102 ;
struct V_14 * V_217 ;
int V_248 = F_4 ( V_8 ) ;
struct V_8 * V_249 = & V_2 [ V_8 ] ;
struct V_250 * V_211 = & V_249 -> V_123 ;
struct V_6 * V_9 = F_3 ( V_8 ) ;
if ( V_211 -> type == V_251 )
return 0 ;
F_81 ( & V_102 , NULL ) ;
V_102 . type = V_104 ;
V_102 . V_112 = F_1 ( V_8 ) ;
V_217 = F_181 ( & V_102 ) ;
if ( ! V_217 )
V_217 = V_252 ;
V_249 -> V_15 = F_182 ( V_211 -> V_253 , V_248 , V_211 -> V_254 ,
( void * ) ( long ) V_8 ) ;
if ( ! V_249 -> V_15 )
return - V_62 ;
V_249 -> V_15 -> V_217 = V_217 ;
if ( V_211 -> type == V_124 ||
V_211 -> type == V_126 )
V_255 = V_83 ( V_255 ,
V_9 -> V_10 + 1 ) ;
return 0 ;
}
static void F_183 ( int V_33 )
{
if ( V_2 [ V_33 ] . V_15 ) {
F_184 ( V_2 [ V_33 ] . V_15 ) ;
V_2 [ V_33 ] . V_15 = NULL ;
}
}
void T_2 F_185 ( void )
{
int V_8 ;
if ( V_18 || ! V_177 )
return;
V_39 = F_7 () ? ~ V_256 : ~ 0UL ;
F_14 ( V_23 , L_89 ) ;
F_22 (ioapic)
F_186 ( F_180 ( V_8 ) ) ;
V_257 . V_258 . V_259 () ;
F_187 () ;
F_112 () ;
F_158 () ;
if ( F_7 () )
F_173 () ;
V_125 = 1 ;
}
static void F_188 ( int V_1 )
{
unsigned long V_53 ;
union V_153 V_154 ;
F_32 ( & V_54 , V_53 ) ;
V_154 . V_161 = F_30 ( V_1 , 0 ) ;
if ( V_154 . V_162 . V_164 != F_1 ( V_1 ) ) {
V_154 . V_162 . V_164 = F_1 ( V_1 ) ;
F_28 ( V_1 , 0 , V_154 . V_161 ) ;
}
F_33 ( & V_54 , V_53 ) ;
}
static void F_189 ( void )
{
int V_1 ;
F_190 (ioapic_idx)
F_188 ( V_1 ) ;
F_64 () ;
}
static int T_2 F_191 ( void )
{
F_192 ( & V_260 ) ;
return 0 ;
}
static int F_193 ( int V_8 )
{
union V_155 V_156 ;
unsigned long V_53 ;
F_32 ( & V_54 , V_53 ) ;
V_156 . V_161 = F_30 ( V_8 , 1 ) ;
F_33 ( & V_54 , V_53 ) ;
return V_156 . V_162 . V_167 + 1 ;
}
unsigned int F_194 ( unsigned int V_261 )
{
return V_125 ? V_255 : V_262 ;
}
static int F_195 ( int V_8 , int V_263 )
{
union V_153 V_154 ;
static T_6 V_264 = V_265 ;
T_6 V_65 ;
unsigned long V_53 ;
int V_22 = 0 ;
if ( F_196 ( V_264 ) )
V_40 -> V_189 ( & V_190 , & V_264 ) ;
F_32 ( & V_54 , V_53 ) ;
V_154 . V_161 = F_30 ( V_8 , 0 ) ;
F_33 ( & V_54 , V_53 ) ;
if ( V_263 >= F_130 () ) {
F_116 ( V_182 L_90
L_91 , V_8 , V_263 , V_154 . V_162 . V_164 ) ;
V_263 = V_154 . V_162 . V_164 ;
}
if ( V_40 -> V_192 ( & V_264 , V_263 ) ) {
for ( V_22 = 0 ; V_22 < F_130 () ; V_22 ++ ) {
if ( ! V_40 -> V_192 ( & V_264 , V_22 ) )
break;
}
if ( V_22 == F_130 () )
F_15 ( L_92 ) ;
F_116 ( V_182 L_93
L_94 , V_8 , V_263 , V_22 ) ;
V_263 = V_22 ;
}
V_40 -> V_193 ( V_263 , & V_65 ) ;
F_133 ( V_264 , V_264 , V_65 ) ;
if ( V_154 . V_162 . V_164 != V_263 ) {
V_154 . V_162 . V_164 = V_263 ;
F_32 ( & V_54 , V_53 ) ;
F_28 ( V_8 , 0 , V_154 . V_161 ) ;
V_154 . V_161 = F_30 ( V_8 , 0 ) ;
F_33 ( & V_54 , V_53 ) ;
if ( V_154 . V_162 . V_164 != V_263 ) {
F_18 ( L_95 ,
V_8 ) ;
return - 1 ;
}
}
F_14 ( V_23 , V_86
L_96 , V_8 , V_263 ) ;
return V_263 ;
}
static T_7 F_197 ( int V_33 , T_7 V_266 )
{
if ( ( V_195 . V_196 == V_197 ) &&
! F_135 ( V_198 [ V_199 ] ) )
return F_195 ( V_33 , V_266 ) ;
else
return V_266 ;
}
static T_7 F_197 ( int V_33 , T_7 V_266 )
{
union V_153 V_154 ;
F_198 ( V_267 , 256 ) ;
unsigned long V_53 ;
T_7 V_268 ;
int V_22 ;
F_199 ( V_267 , 256 ) ;
F_22 (i)
F_200 ( F_1 ( V_22 ) , V_267 ) ;
if ( ! F_67 ( V_266 , V_267 ) )
return V_266 ;
F_32 ( & V_54 , V_53 ) ;
V_154 . V_161 = F_30 ( V_33 , 0 ) ;
F_33 ( & V_54 , V_53 ) ;
V_268 = V_154 . V_162 . V_164 ;
if ( ! F_67 ( V_268 , V_267 ) ) {
F_14 ( V_23 , V_86
L_97 ,
V_33 , V_268 , V_266 ) ;
return V_268 ;
}
V_268 = F_201 ( V_267 , 256 ) ;
V_154 . V_162 . V_164 = V_268 ;
F_32 ( & V_54 , V_53 ) ;
F_28 ( V_33 , 0 , V_154 . V_161 ) ;
V_154 . V_161 = F_30 ( V_33 , 0 ) ;
F_33 ( & V_54 , V_53 ) ;
F_186 ( V_154 . V_162 . V_164 != V_268 ) ;
return V_268 ;
}
static int F_202 ( int V_8 )
{
union V_155 V_156 ;
unsigned long V_53 ;
F_32 ( & V_54 , V_53 ) ;
V_156 . V_161 = F_30 ( V_8 , 1 ) ;
F_33 ( & V_54 , V_53 ) ;
return V_156 . V_162 . V_163 ;
}
int F_84 ( T_1 V_111 , int * V_76 , int * V_103 )
{
int V_8 , V_12 , V_33 ;
if ( V_18 )
return - 1 ;
V_8 = F_105 ( V_111 ) ;
if ( V_8 < 0 )
return - 1 ;
V_12 = F_106 ( V_8 , V_111 ) ;
if ( V_12 < 0 )
return - 1 ;
V_33 = F_65 ( V_8 , V_12 , V_135 ) ;
if ( V_33 < 0 )
return - 1 ;
* V_76 = F_77 ( V_33 ) ;
* V_103 = F_71 ( V_33 ) ;
return 0 ;
}
void T_2 F_203 ( void )
{
int V_12 , V_8 , V_13 , V_269 ;
const struct V_215 * V_56 ;
struct V_72 * V_270 ;
if ( V_18 == 1 )
return;
F_57 (ioapic, pin) {
V_269 = F_65 ( V_8 , V_12 , V_135 ) ;
if ( V_269 == - 1 )
continue;
V_13 = F_102 ( V_269 , V_8 , V_12 , 0 ) ;
if ( V_13 < 0 || ! F_8 ( V_8 , V_13 ) )
continue;
V_270 = F_96 ( V_13 ) ;
if ( ! F_204 ( V_270 ) || F_205 ( V_270 ) )
V_56 = V_270 -> V_271 ;
else
V_56 = V_40 -> V_272 () ;
V_219 ( V_13 , V_56 ) ;
}
}
static struct V_273 * T_2 F_206 ( void )
{
unsigned long V_274 ;
struct V_273 * V_275 ;
char * V_276 ;
int V_22 , V_277 = 0 ;
F_22 (i)
V_277 ++ ;
if ( V_277 == 0 )
return NULL ;
V_274 = V_278 + sizeof( struct V_273 ) ;
V_274 *= V_277 ;
V_276 = F_207 ( V_274 ) ;
V_275 = ( void * ) V_276 ;
V_276 += sizeof( struct V_273 ) * V_277 ;
V_277 = 0 ;
F_22 (i) {
V_275 [ V_277 ] . V_279 = V_276 ;
V_275 [ V_277 ] . V_53 = V_280 | V_281 ;
snprintf ( V_276 , V_278 , L_98 , V_22 ) ;
V_276 += V_278 ;
V_277 ++ ;
V_2 [ V_22 ] . V_282 = V_275 ;
}
V_283 = V_275 ;
return V_275 ;
}
void T_2 F_208 ( void )
{
unsigned long V_284 , V_33 = V_285 ;
struct V_273 * V_286 ;
int V_22 ;
V_286 = F_206 () ;
F_22 (i) {
if ( V_287 ) {
V_284 = F_2 ( V_22 ) ;
#ifdef F_103
if ( ! V_284 ) {
F_116 ( V_191
L_99
L_100
L_101 ) ;
V_287 = 0 ;
V_18 = 1 ;
goto V_288;
}
#endif
} else {
#ifdef F_103
V_288:
#endif
V_284 = ( unsigned long ) F_209 ( V_289 ) ;
V_284 = F_210 ( V_284 ) ;
}
F_211 ( V_33 , V_284 ) ;
F_14 ( V_23 , L_102 ,
F_212 ( V_33 ) + ( V_284 & ~ V_290 ) ,
V_284 ) ;
V_33 ++ ;
V_286 -> V_291 = V_284 ;
V_286 -> V_292 = V_284 + V_293 - 1 ;
V_286 ++ ;
}
}
void T_2 F_213 ( void )
{
int V_22 ;
struct V_273 * V_294 = V_283 ;
if ( ! V_294 ) {
if ( V_177 > 0 )
F_116 ( V_191
L_103 ) ;
return;
}
F_22 (i) {
F_214 ( & V_295 , V_294 ) ;
V_294 ++ ;
}
}
int F_105 ( T_1 V_111 )
{
int V_22 ;
if ( V_177 == 0 )
return - 1 ;
F_22 (i) {
struct V_6 * V_9 = F_3 ( V_22 ) ;
if ( V_111 >= V_9 -> V_11 && V_111 <= V_9 -> V_10 )
return V_22 ;
}
F_116 ( V_191 L_104 , V_111 ) ;
return - 1 ;
}
int F_106 ( int V_8 , T_1 V_111 )
{
struct V_6 * V_9 ;
if ( F_215 ( V_8 < 0 ) )
return - 1 ;
V_9 = F_3 ( V_8 ) ;
if ( F_215 ( V_111 > V_9 -> V_10 ) )
return - 1 ;
return V_111 - V_9 -> V_11 ;
}
static int F_216 ( int V_33 )
{
union V_153 V_154 ;
union V_155 V_156 ;
union V_157 V_158 ;
V_154 . V_161 = F_30 ( V_33 , 0 ) ;
V_156 . V_161 = F_30 ( V_33 , 1 ) ;
V_158 . V_161 = F_30 ( V_33 , 2 ) ;
if ( V_154 . V_161 == - 1 && V_156 . V_161 == - 1 && V_158 . V_161 == - 1 ) {
F_74 ( L_105 ,
F_2 ( V_33 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_217 ( void )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_296 ; V_33 ++ )
if ( V_2 [ V_33 ] . V_37 == 0 )
return V_33 ;
return V_296 ;
}
int F_218 ( int V_266 , T_1 V_297 , T_1 V_11 ,
struct V_250 * V_211 )
{
bool V_298 = ! ! V_125 ;
struct V_6 * V_9 ;
int V_33 , V_8 , V_167 ;
T_1 V_10 ;
if ( ! V_297 ) {
F_74 ( L_106 ) ;
return - V_299 ;
}
F_22 (ioapic)
if ( V_2 [ V_8 ] . V_3 . V_5 == V_297 ) {
F_74 ( L_107 ,
V_297 , V_8 ) ;
return - V_300 ;
}
V_33 = F_217 () ;
if ( V_33 >= V_296 ) {
F_74 ( L_108 ,
V_296 , V_33 ) ;
return - V_301 ;
}
V_2 [ V_33 ] . V_3 . type = V_302 ;
V_2 [ V_33 ] . V_3 . V_53 = V_303 ;
V_2 [ V_33 ] . V_3 . V_5 = V_297 ;
F_211 ( V_285 + V_33 , V_297 ) ;
if ( F_216 ( V_33 ) ) {
F_219 ( V_285 + V_33 ) ;
return - V_304 ;
}
V_2 [ V_33 ] . V_3 . V_4 = F_197 ( V_33 , V_266 ) ;
V_2 [ V_33 ] . V_3 . V_305 = F_202 ( V_33 ) ;
V_167 = F_193 ( V_33 ) ;
V_10 = V_11 + V_167 - 1 ;
F_22 (ioapic) {
V_9 = F_3 ( V_8 ) ;
if ( ( V_11 >= V_9 -> V_11 &&
V_11 <= V_9 -> V_10 ) ||
( V_10 >= V_9 -> V_11 &&
V_10 <= V_9 -> V_10 ) ) {
F_74 ( L_109 ,
V_11 , V_10 ,
V_9 -> V_11 , V_9 -> V_10 ) ;
F_219 ( V_285 + V_33 ) ;
return - V_301 ;
}
}
V_9 = F_3 ( V_33 ) ;
V_9 -> V_11 = V_11 ;
V_9 -> V_10 = V_10 ;
V_2 [ V_33 ] . V_15 = NULL ;
V_2 [ V_33 ] . V_123 = * V_211 ;
if ( V_298 ) {
if ( F_180 ( V_33 ) ) {
F_219 ( V_285 + V_33 ) ;
return - V_62 ;
}
F_16 ( V_33 ) ;
}
if ( V_9 -> V_10 >= V_262 )
V_262 = V_9 -> V_10 + 1 ;
if ( V_177 <= V_33 )
V_177 = V_33 + 1 ;
V_2 [ V_33 ] . V_37 = V_167 ;
F_220 ( L_110 ,
V_33 , F_1 ( V_33 ) ,
F_53 ( V_33 ) , F_2 ( V_33 ) ,
V_9 -> V_11 , V_9 -> V_10 ) ;
return 0 ;
}
int F_221 ( T_1 V_11 )
{
int V_8 , V_12 ;
int V_141 = 0 ;
F_22 (ioapic)
if ( V_2 [ V_8 ] . V_7 . V_11 == V_11 ) {
V_141 = 1 ;
break;
}
if ( ! V_141 ) {
F_74 ( L_111 , V_11 ) ;
return - V_304 ;
}
F_62 (ioapic, pin) {
T_1 V_111 = F_5 ( V_8 , V_12 ) ;
int V_13 = F_104 ( V_111 , 0 , NULL ) ;
struct V_58 * V_46 ;
if ( V_13 >= 0 ) {
V_46 = F_91 ( V_13 ) ;
if ( V_46 && V_46 -> V_120 ) {
F_74 ( L_112 ,
V_12 , V_8 ) ;
return - V_129 ;
}
}
}
V_2 [ V_8 ] . V_37 = 0 ;
F_183 ( V_8 ) ;
F_19 ( V_8 ) ;
if ( V_2 [ V_8 ] . V_282 )
F_222 ( V_2 [ V_8 ] . V_282 ) ;
F_219 ( V_285 + V_8 ) ;
memset ( & V_2 [ V_8 ] , 0 , sizeof( V_2 [ V_8 ] ) ) ;
return 0 ;
}
int F_223 ( T_1 V_11 )
{
int V_8 ;
F_22 (ioapic)
if ( V_2 [ V_8 ] . V_7 . V_11 == V_11 )
return 1 ;
return 0 ;
}
static void F_224 ( T_1 V_111 , struct V_58 * V_46 ,
struct V_101 * V_102 )
{
if ( V_102 && V_102 -> V_108 ) {
V_46 -> V_76 = V_102 -> V_106 ;
V_46 -> V_103 = V_102 -> V_107 ;
} else if ( F_84 ( V_111 , & V_46 -> V_76 ,
& V_46 -> V_103 ) < 0 ) {
V_46 -> V_76 = V_82 ;
V_46 -> V_103 = V_96 ;
}
}
static void F_225 ( struct V_210 * V_211 , struct V_58 * V_46 ,
struct V_36 * V_52 )
{
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_52 -> V_78 = V_40 -> V_306 ;
V_52 -> V_150 = V_40 -> V_307 ;
V_52 -> V_152 = V_211 -> V_221 ;
V_52 -> V_41 = V_211 -> V_41 ;
V_52 -> V_76 = V_46 -> V_76 ;
V_52 -> V_103 = V_46 -> V_103 ;
if ( V_46 -> V_76 == V_82 )
V_52 -> V_56 = V_57 ;
else
V_52 -> V_56 = V_80 ;
}
int F_226 ( struct V_14 * V_121 , unsigned int V_308 ,
unsigned int V_309 , void * V_236 )
{
int V_218 , V_8 , V_12 ;
struct V_210 * V_211 ;
struct V_72 * V_72 ;
struct V_58 * V_46 ;
struct V_101 * V_102 = V_236 ;
if ( ! V_102 || V_309 > 1 )
return - V_299 ;
V_72 = F_97 ( V_121 , V_308 ) ;
if ( ! V_72 )
return - V_299 ;
V_8 = F_227 ( V_121 ) ;
V_12 = V_102 -> V_113 ;
if ( F_100 ( V_121 , ( V_310 ) V_12 ) > 0 )
return - V_300 ;
V_46 = F_17 ( sizeof( * V_46 ) , V_38 ) ;
if ( ! V_46 )
return - V_62 ;
V_102 -> V_311 = & V_46 -> V_52 ;
V_218 = F_228 ( V_121 , V_308 , V_309 , V_102 ) ;
if ( V_218 < 0 ) {
F_20 ( V_46 ) ;
return V_218 ;
}
F_229 ( & V_46 -> V_64 ) ;
V_72 -> V_312 = V_102 -> V_113 ;
V_72 -> V_172 = ( V_121 -> V_217 == V_252 ) ?
& V_173 : & V_174 ;
V_72 -> V_73 = V_46 ;
F_224 ( F_5 ( V_8 , V_12 ) , V_46 , V_102 ) ;
V_211 = F_151 ( V_72 ) ;
F_44 ( V_46 , F_85 ( V_102 ) , V_8 , V_12 ) ;
if ( V_102 -> V_311 )
F_225 ( V_211 , V_46 , V_102 -> V_311 ) ;
F_86 ( V_308 , V_46 -> V_76 ) ;
if ( V_308 < F_7 () )
V_206 -> V_56 ( V_308 ) ;
F_14 ( V_23 , V_87
L_113 ,
V_8 , F_1 ( V_8 ) , V_12 , V_211 -> V_41 ,
V_308 , V_46 -> V_76 , V_46 -> V_103 , V_211 -> V_221 ) ;
return 0 ;
}
void F_230 ( struct V_14 * V_121 , unsigned int V_308 ,
unsigned int V_309 )
{
struct V_72 * V_72 ;
struct V_58 * V_46 ;
F_186 ( V_309 != 1 ) ;
V_72 = F_97 ( V_121 , V_308 ) ;
if ( V_72 && V_72 -> V_73 ) {
V_46 = V_72 -> V_73 ;
F_41 ( V_46 , F_227 ( V_121 ) ,
( int ) V_72 -> V_312 ) ;
F_215 ( ! F_121 ( & V_46 -> V_64 ) ) ;
F_20 ( V_72 -> V_73 ) ;
}
F_231 ( V_121 , V_308 , V_309 ) ;
}
void F_232 ( struct V_14 * V_121 ,
struct V_72 * V_72 )
{
unsigned long V_53 ;
struct V_60 * V_52 ;
struct V_58 * V_46 = V_72 -> V_73 ;
F_32 ( & V_54 , V_53 ) ;
F_38 (entry, data->irq_2_pin)
F_34 ( V_52 -> V_40 , V_52 -> V_12 , V_46 -> V_52 ) ;
F_33 ( & V_54 , V_53 ) ;
}
void F_233 ( struct V_14 * V_121 ,
struct V_72 * V_72 )
{
F_36 ( F_227 ( V_121 ) ,
( int ) V_72 -> V_312 ) ;
}
int F_227 ( struct V_14 * V_121 )
{
return ( int ) ( long ) V_121 -> V_313 ;
}
