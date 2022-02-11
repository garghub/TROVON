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
static void F_54 ( int V_41 , struct V_58 * V_46 )
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
V_102 , V_122 , NULL ) ;
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
V_13 = F_94 ( V_121 , V_13 , 1 , V_59 , V_102 , true ,
NULL ) ;
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
return - V_135 ;
V_12 = F_106 ( V_8 , V_111 ) ;
V_33 = F_65 ( V_8 , V_12 , V_136 ) ;
if ( ( V_53 & V_137 ) && V_33 < 0 )
return - V_135 ;
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
int F_109 ( int V_94 , int V_138 , int V_12 )
{
int V_13 , V_22 , V_139 = - 1 , V_140 = - 1 ;
F_14 ( V_141 ,
L_20 ,
V_94 , V_138 , V_12 ) ;
if ( F_67 ( V_94 , V_92 ) ) {
F_14 ( V_23 ,
L_21 , V_94 ) ;
return - 1 ;
}
for ( V_22 = 0 ; V_22 < V_30 ; V_22 ++ ) {
int V_91 = V_31 [ V_22 ] . V_26 ;
int V_1 , V_142 = 0 ;
if ( V_94 != V_91 || V_31 [ V_22 ] . V_24 != V_136 ||
V_138 != ( ( V_31 [ V_22 ] . V_27 >> 2 ) & 0x1f ) )
continue;
F_22 (ioapic_idx)
if ( F_1 ( V_1 ) == V_31 [ V_22 ] . V_28 ||
V_31 [ V_22 ] . V_28 == V_90 ) {
V_142 = 1 ;
break;
}
if ( ! V_142 )
continue;
V_13 = F_102 ( V_22 , V_1 , V_31 [ V_22 ] . V_29 , 0 ) ;
if ( V_13 > 0 && ! F_110 ( V_13 ) )
continue;
if ( V_12 == ( V_31 [ V_22 ] . V_27 & 3 ) ) {
V_140 = V_22 ;
V_139 = V_1 ;
goto V_143;
}
if ( V_140 < 0 ) {
V_140 = V_22 ;
V_139 = V_1 ;
}
}
if ( V_140 < 0 )
return - 1 ;
V_143:
return F_102 ( V_140 , V_139 , V_31 [ V_140 ] . V_29 ,
V_133 ) ;
}
static inline int F_111 ( int V_13 )
{
int V_40 , V_33 , V_12 ;
F_57 (apic, pin) {
V_33 = F_65 ( V_40 , V_12 , V_136 ) ;
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
V_33 = F_65 ( V_8 , V_12 , V_136 ) ;
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
static void F_115 ( unsigned int V_40 , unsigned int V_144 )
{
int V_22 ;
char V_145 [ 256 ] ;
struct V_36 V_52 ;
struct V_146 * V_147 = ( void * ) & V_52 ;
F_116 ( V_87 L_24 , V_40 ) ;
for ( V_22 = 0 ; V_22 <= V_144 ; V_22 ++ ) {
V_52 = F_31 ( V_40 , V_22 ) ;
snprintf ( V_145 , sizeof( V_145 ) ,
L_25 ,
V_22 ,
V_52 . V_56 == V_57 ? L_26 : L_27 ,
V_52 . V_76 == V_82 ? L_28 : L_29 ,
V_52 . V_103 == V_96 ? L_30 : L_31 ,
V_52 . V_41 , V_52 . V_81 , V_52 . V_148 ) ;
if ( V_147 -> V_149 )
F_116 ( V_87 L_32 ,
V_145 , ( V_147 -> V_45 << 15 ) | V_147 -> V_45 ,
V_147 -> V_150 ) ;
else
F_116 ( V_87 L_33 ,
V_145 ,
V_52 . V_151 == V_152 ?
L_34 : L_35 ,
V_52 . V_153 , V_52 . V_78 ) ;
}
}
static void T_2 F_117 ( int V_1 )
{
union V_154 V_155 ;
union V_156 V_157 ;
union V_158 V_159 ;
union V_160 V_161 ;
unsigned long V_53 ;
F_32 ( & V_54 , V_53 ) ;
V_155 . V_162 = F_30 ( V_1 , 0 ) ;
V_157 . V_162 = F_30 ( V_1 , 1 ) ;
if ( V_157 . V_163 . V_164 >= 0x10 )
V_159 . V_162 = F_30 ( V_1 , 2 ) ;
if ( V_157 . V_163 . V_164 >= 0x20 )
V_161 . V_162 = F_30 ( V_1 , 3 ) ;
F_33 ( & V_54 , V_53 ) ;
F_116 ( V_87 L_36 , F_1 ( V_1 ) ) ;
F_116 ( V_87 L_37 , V_155 . V_162 ) ;
F_116 ( V_87 L_38 , V_155 . V_163 . V_165 ) ;
F_116 ( V_87 L_39 , V_155 . V_163 . V_166 ) ;
F_116 ( V_87 L_40 , V_155 . V_163 . V_167 ) ;
F_116 ( V_87 L_41 , * ( int * ) & V_157 ) ;
F_116 ( V_87 L_42 ,
V_157 . V_163 . V_168 ) ;
F_116 ( V_87 L_43 , V_157 . V_163 . V_169 ) ;
F_116 ( V_87 L_44 ,
V_157 . V_163 . V_164 ) ;
if ( V_157 . V_163 . V_164 >= 0x10 && V_159 . V_162 != V_157 . V_162 ) {
F_116 ( V_87 L_45 , V_159 . V_162 ) ;
F_116 ( V_87 L_46 , V_159 . V_163 . V_170 ) ;
}
if ( V_157 . V_163 . V_164 >= 0x20 && V_161 . V_162 != V_159 . V_162 &&
V_161 . V_162 != V_157 . V_162 ) {
F_116 ( V_87 L_47 , V_161 . V_162 ) ;
F_116 ( V_87 L_48 , V_161 . V_163 . V_171 ) ;
}
F_116 ( V_87 L_49 ) ;
F_115 ( V_1 , V_157 . V_163 . V_168 ) ;
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
struct V_172 * V_173 ;
struct V_58 * V_46 ;
V_173 = F_120 ( V_13 ) ;
if ( V_173 != & V_174 && V_173 != & V_175 )
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
int V_176 , V_177 ;
int V_40 , V_12 ;
if ( V_18 )
V_178 = 0 ;
if ( ! F_7 () || ! V_178 )
return;
F_57 (apic, pin) {
struct V_36 V_52 = F_31 ( V_40 , V_12 ) ;
if ( ( V_52 . V_56 == 0 ) && ( V_52 . V_78 == V_179 ) ) {
V_180 . V_40 = V_40 ;
V_180 . V_12 = V_12 ;
goto V_181;
}
}
V_181:
V_177 = F_66 ( 0 , V_182 ) ;
V_176 = F_68 ( 0 , V_182 ) ;
if ( ( V_180 . V_12 == - 1 ) && ( V_177 >= 0 ) ) {
F_116 ( V_183 L_58 ) ;
V_180 . V_12 = V_177 ;
V_180 . V_40 = V_176 ;
}
if ( ( ( V_180 . V_40 != V_176 ) || ( V_180 . V_12 != V_177 ) ) &&
( V_177 >= 0 ) && ( V_180 . V_12 >= 0 ) )
{
F_116 ( V_183 L_59 ) ;
}
F_56 () ;
}
void F_124 ( void )
{
if ( V_180 . V_12 != - 1 ) {
struct V_36 V_52 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_56 = V_80 ;
V_52 . V_76 = V_77 ;
V_52 . V_103 = V_95 ;
V_52 . V_151 = V_184 ;
V_52 . V_78 = V_179 ;
V_52 . V_153 = F_125 () ;
F_35 ( V_180 . V_40 , V_180 . V_12 , V_52 ) ;
}
if ( F_126 ( V_185 ) || F_127 () )
F_128 ( V_180 . V_12 != - 1 ) ;
}
void F_129 ( void )
{
F_56 () ;
if ( ! F_7 () )
return;
V_186 . V_187 () ;
}
void T_2 F_130 ( void )
{
union V_154 V_155 ;
T_6 V_188 ;
int V_1 ;
int V_22 ;
unsigned char V_189 ;
unsigned long V_53 ;
V_40 -> V_190 ( & V_191 , & V_188 ) ;
F_22 (ioapic_idx) {
F_32 ( & V_54 , V_53 ) ;
V_155 . V_162 = F_30 ( V_1 , 0 ) ;
F_33 ( & V_54 , V_53 ) ;
V_189 = F_1 ( V_1 ) ;
if ( F_1 ( V_1 ) >= F_131 () ) {
F_116 ( V_192 L_60 ,
V_1 , F_1 ( V_1 ) ) ;
F_116 ( V_192 L_61 ,
V_155 . V_163 . V_165 ) ;
V_2 [ V_1 ] . V_3 . V_4 = V_155 . V_163 . V_165 ;
}
if ( V_40 -> V_193 ( & V_188 ,
F_1 ( V_1 ) ) ) {
F_116 ( V_192 L_62 ,
V_1 , F_1 ( V_1 ) ) ;
for ( V_22 = 0 ; V_22 < F_131 () ; V_22 ++ )
if ( ! F_132 ( V_22 , V_188 ) )
break;
if ( V_22 >= F_131 () )
F_15 ( L_63 ) ;
F_116 ( V_192 L_61 ,
V_22 ) ;
F_133 ( V_22 , V_188 ) ;
V_2 [ V_1 ] . V_3 . V_4 = V_22 ;
} else {
T_6 V_65 ;
V_40 -> V_194 ( F_1 ( V_1 ) ,
& V_65 ) ;
F_14 ( V_23 , L_64
L_65 ,
F_1 ( V_1 ) ) ;
F_134 ( V_188 , V_188 , V_65 ) ;
}
if ( V_189 != F_1 ( V_1 ) )
for ( V_22 = 0 ; V_22 < V_30 ; V_22 ++ )
if ( V_31 [ V_22 ] . V_28 == V_189 )
V_31 [ V_22 ] . V_28
= F_1 ( V_1 ) ;
if ( F_1 ( V_1 ) == V_155 . V_163 . V_165 )
continue;
F_14 ( V_23 , V_86
L_66 ,
F_1 ( V_1 ) ) ;
V_155 . V_163 . V_165 = F_1 ( V_1 ) ;
F_32 ( & V_54 , V_53 ) ;
F_28 ( V_1 , 0 , V_155 . V_162 ) ;
F_33 ( & V_54 , V_53 ) ;
F_32 ( & V_54 , V_53 ) ;
V_155 . V_162 = F_30 ( V_1 , 0 ) ;
F_33 ( & V_54 , V_53 ) ;
if ( V_155 . V_163 . V_165 != F_1 ( V_1 ) )
F_122 ( L_67 ) ;
else
F_14 ( V_23 , L_68 ) ;
}
}
void T_2 F_135 ( void )
{
if ( V_195 )
return;
if ( ! ( V_196 . V_197 == V_198 )
|| F_136 ( V_199 ) )
return;
F_130 () ;
}
static int T_2 F_137 ( char * V_200 )
{
V_201 = 1 ;
return 1 ;
}
static int T_2 F_138 ( void )
{
unsigned long V_202 = V_203 ;
unsigned long V_53 ;
if ( V_201 )
return 1 ;
F_139 ( V_53 ) ;
F_140 () ;
F_141 ( ( 10 * 1000 ) / V_204 ) ;
F_142 ( V_53 ) ;
if ( F_143 ( V_203 , V_202 + 4 ) )
return 1 ;
return 0 ;
}
static unsigned int F_144 ( struct V_72 * V_46 )
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
static bool F_145 ( struct V_58 * V_46 )
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
static inline bool F_146 ( struct V_72 * V_46 )
{
if ( F_147 ( F_148 ( V_46 ) ) ) {
F_49 ( V_46 ) ;
return true ;
}
return false ;
}
static inline void F_149 ( struct V_72 * V_46 , bool V_209 )
{
if ( F_147 ( V_209 ) ) {
if ( ! F_145 ( V_46 -> V_73 ) )
F_150 ( V_46 ) ;
F_51 ( V_46 ) ;
}
}
static inline bool F_146 ( struct V_72 * V_46 )
{
return false ;
}
static inline void F_149 ( struct V_72 * V_46 , bool V_209 )
{
}
static void F_151 ( struct V_72 * V_72 )
{
struct V_210 * V_211 = F_152 ( V_72 ) ;
unsigned long V_212 ;
bool V_209 ;
int V_22 ;
F_153 ( V_211 ) ;
V_209 = F_146 ( V_72 ) ;
V_22 = V_211 -> V_41 ;
V_212 = F_154 ( V_213 + ( ( V_22 & ~ 0x1f ) >> 1 ) ) ;
F_155 () ;
if ( ! ( V_212 & ( 1 << ( V_22 & 0x1f ) ) ) ) {
F_156 ( & V_214 ) ;
F_54 ( V_211 -> V_41 , V_72 -> V_73 ) ;
}
F_149 ( V_72 , V_209 ) ;
}
static void F_157 ( struct V_72 * V_72 )
{
struct V_58 * V_46 = V_72 -> V_73 ;
F_155 () ;
F_54 ( V_46 -> V_52 . V_41 , V_46 ) ;
}
static int F_158 ( struct V_72 * V_72 ,
const struct V_215 * V_56 , bool V_216 )
{
struct V_72 * V_217 = V_72 -> V_128 ;
struct V_58 * V_46 = V_72 -> V_73 ;
struct V_60 * V_52 ;
struct V_210 * V_211 ;
unsigned long V_53 ;
int V_218 ;
V_218 = V_217 -> V_173 -> V_219 ( V_217 , V_56 , V_216 ) ;
F_32 ( & V_54 , V_53 ) ;
if ( V_218 >= 0 && V_218 != V_220 ) {
V_211 = F_152 ( V_72 ) ;
V_46 -> V_52 . V_153 = V_211 -> V_221 ;
V_46 -> V_52 . V_41 = V_211 -> V_41 ;
F_38 (entry, data->irq_2_pin)
F_34 ( V_52 -> V_40 , V_52 -> V_12 ,
V_46 -> V_52 ) ;
}
F_33 ( & V_54 , V_53 ) ;
return V_218 ;
}
static inline void F_159 ( void )
{
struct V_210 * V_211 ;
unsigned int V_13 ;
F_119 (irq) {
V_211 = V_210 ( V_13 ) ;
if ( F_110 ( V_13 ) && V_211 && ! V_211 -> V_41 ) {
if ( V_13 < F_7 () )
V_206 -> V_222 ( V_13 ) ;
else
F_160 ( V_13 , & V_223 ) ;
}
}
}
static void F_161 ( struct V_72 * V_46 )
{
unsigned long V_212 ;
V_212 = F_154 ( V_224 ) ;
F_162 ( V_224 , V_212 | V_225 ) ;
}
static void F_163 ( struct V_72 * V_46 )
{
unsigned long V_212 ;
V_212 = F_154 ( V_224 ) ;
F_162 ( V_224 , V_212 & ~ V_225 ) ;
}
static void F_164 ( struct V_72 * V_46 )
{
F_155 () ;
}
static void F_165 ( int V_13 )
{
F_88 ( V_13 , V_117 ) ;
F_166 ( V_13 , & V_226 , V_119 ,
L_15 ) ;
}
static inline void T_2 F_167 ( void )
{
int V_40 , V_12 , V_22 ;
struct V_36 V_227 , V_75 ;
unsigned char V_228 , V_229 ;
V_12 = F_66 ( 8 , V_136 ) ;
if ( V_12 == - 1 ) {
F_168 ( 1 ) ;
return;
}
V_40 = F_68 ( 8 , V_136 ) ;
if ( V_40 == - 1 ) {
F_168 ( 1 ) ;
return;
}
V_227 = F_31 ( V_40 , V_12 ) ;
F_55 ( V_40 , V_12 ) ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_151 = V_184 ;
V_75 . V_56 = V_80 ;
V_75 . V_153 = F_169 () ;
V_75 . V_78 = V_179 ;
V_75 . V_103 = V_227 . V_103 ;
V_75 . V_76 = V_77 ;
V_75 . V_41 = 0 ;
F_35 ( V_40 , V_12 , V_75 ) ;
V_228 = F_170 ( V_230 ) ;
V_229 = F_170 ( V_231 ) ;
F_171 ( ( V_229 & ~ V_232 ) | 0x6 ,
V_231 ) ;
F_171 ( V_228 | V_233 , V_230 ) ;
V_22 = 100 ;
while ( V_22 -- > 0 ) {
F_141 ( 10 ) ;
if ( ( F_170 ( V_234 ) & V_235 ) == V_235 )
V_22 -= 10 ;
}
F_171 ( V_228 , V_230 ) ;
F_171 ( V_229 , V_231 ) ;
F_55 ( V_40 , V_12 ) ;
F_35 ( V_40 , V_12 , V_227 ) ;
}
static int T_2 F_172 ( char * V_236 )
{
V_237 = 1 ;
return 0 ;
}
static int F_173 ( int V_8 , int V_12 )
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
static inline void T_2 F_174 ( void )
{
struct V_72 * V_72 = F_96 ( 0 ) ;
struct V_58 * V_46 = V_72 -> V_73 ;
struct V_210 * V_211 = F_152 ( V_72 ) ;
int V_59 = F_175 ( 0 ) ;
int V_238 , V_239 , V_240 , V_241 ;
unsigned long V_53 ;
int V_242 = 0 ;
F_176 ( V_53 ) ;
V_206 -> V_56 ( 0 ) ;
F_162 ( V_224 , V_225 | V_243 ) ;
V_206 -> V_244 ( 1 ) ;
V_239 = F_66 ( 0 , V_136 ) ;
V_238 = F_68 ( 0 , V_136 ) ;
V_241 = V_180 . V_12 ;
V_240 = V_180 . V_40 ;
F_14 ( V_245 , V_86 L_69
L_70 ,
V_211 -> V_41 , V_238 , V_239 , V_240 , V_241 ) ;
if ( V_239 == - 1 ) {
F_177 ( L_71 ) ;
V_239 = V_241 ;
V_238 = V_240 ;
V_242 = 1 ;
} else if ( V_241 == - 1 ) {
V_241 = V_239 ;
V_240 = V_238 ;
}
if ( V_239 != - 1 ) {
if ( V_242 ) {
F_173 ( V_238 , V_239 ) ;
} else {
int V_33 ;
V_33 = F_65 ( V_238 , V_239 , V_136 ) ;
if ( V_33 != - 1 && F_77 ( V_33 ) )
F_51 ( F_91 ( 0 ) ) ;
}
F_178 ( V_72 ) ;
F_179 ( V_72 ) ;
if ( F_138 () ) {
if ( V_237 > 0 )
F_55 ( 0 , V_239 ) ;
goto V_143;
}
F_177 ( L_72 ) ;
F_180 () ;
F_55 ( V_238 , V_239 ) ;
if ( ! V_242 )
F_14 ( V_245 , V_192 L_73
L_74 ) ;
F_14 ( V_245 , V_86 L_75
L_76 ) ;
F_14 ( V_245 , V_86
L_77 , V_240 , V_241 ) ;
F_45 ( V_46 , V_59 , V_238 , V_239 , V_240 , V_241 ) ;
F_178 ( V_72 ) ;
F_179 ( V_72 ) ;
V_206 -> V_246 ( 0 ) ;
if ( F_138 () ) {
F_14 ( V_245 , V_86 L_78 ) ;
goto V_143;
}
F_180 () ;
V_206 -> V_56 ( 0 ) ;
F_55 ( V_240 , V_241 ) ;
F_14 ( V_245 , V_86 L_79 ) ;
}
F_14 ( V_245 , V_86
L_80 ) ;
F_165 ( 0 ) ;
F_162 ( V_224 , V_247 | V_211 -> V_41 ) ;
V_206 -> V_246 ( 0 ) ;
if ( F_138 () ) {
F_14 ( V_245 , V_86 L_81 ) ;
goto V_143;
}
F_180 () ;
V_206 -> V_56 ( 0 ) ;
F_162 ( V_224 , V_225 | V_247 | V_211 -> V_41 ) ;
F_14 ( V_245 , V_86 L_82 ) ;
F_14 ( V_245 , V_86
L_83 ) ;
V_206 -> V_244 ( 0 ) ;
V_206 -> V_222 ( 0 ) ;
F_162 ( V_224 , V_243 ) ;
F_167 () ;
if ( F_138 () ) {
F_14 ( V_245 , V_86 L_81 ) ;
goto V_143;
}
F_180 () ;
F_14 ( V_245 , V_86 L_84 ) ;
if ( F_181 () )
F_14 ( V_245 , V_86
L_85
L_86 ) ;
F_15 ( L_87
L_88 ) ;
V_143:
F_142 ( V_53 ) ;
}
static int F_182 ( int V_8 )
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
V_217 = F_183 ( & V_102 ) ;
if ( ! V_217 )
V_217 = V_252 ;
V_249 -> V_15 = F_184 ( V_211 -> V_253 , V_248 , V_211 -> V_254 ,
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
static void F_185 ( int V_33 )
{
if ( V_2 [ V_33 ] . V_15 ) {
F_186 ( V_2 [ V_33 ] . V_15 ) ;
V_2 [ V_33 ] . V_15 = NULL ;
}
}
void T_2 F_187 ( void )
{
int V_8 ;
if ( V_18 || ! V_178 )
return;
V_39 = F_7 () ? ~ V_256 : ~ 0UL ;
F_14 ( V_23 , L_89 ) ;
F_22 (ioapic)
F_188 ( F_182 ( V_8 ) ) ;
V_257 . V_258 . V_259 () ;
F_189 () ;
F_112 () ;
F_159 () ;
if ( F_7 () )
F_174 () ;
V_125 = 1 ;
}
static void F_190 ( int V_1 )
{
unsigned long V_53 ;
union V_154 V_155 ;
F_32 ( & V_54 , V_53 ) ;
V_155 . V_162 = F_30 ( V_1 , 0 ) ;
if ( V_155 . V_163 . V_165 != F_1 ( V_1 ) ) {
V_155 . V_163 . V_165 = F_1 ( V_1 ) ;
F_28 ( V_1 , 0 , V_155 . V_162 ) ;
}
F_33 ( & V_54 , V_53 ) ;
}
static void F_191 ( void )
{
int V_1 ;
F_192 (ioapic_idx)
F_190 ( V_1 ) ;
F_64 () ;
}
static int T_2 F_193 ( void )
{
F_194 ( & V_260 ) ;
return 0 ;
}
static int F_195 ( int V_8 )
{
union V_156 V_157 ;
unsigned long V_53 ;
F_32 ( & V_54 , V_53 ) ;
V_157 . V_162 = F_30 ( V_8 , 1 ) ;
F_33 ( & V_54 , V_53 ) ;
return V_157 . V_163 . V_168 + 1 ;
}
unsigned int F_196 ( unsigned int V_261 )
{
return V_125 ? V_255 : V_262 ;
}
static int F_197 ( int V_8 , int V_263 )
{
union V_154 V_155 ;
static T_6 V_264 = V_265 ;
T_6 V_65 ;
unsigned long V_53 ;
int V_22 = 0 ;
if ( F_198 ( V_264 ) )
V_40 -> V_190 ( & V_191 , & V_264 ) ;
F_32 ( & V_54 , V_53 ) ;
V_155 . V_162 = F_30 ( V_8 , 0 ) ;
F_33 ( & V_54 , V_53 ) ;
if ( V_263 >= F_131 () ) {
F_116 ( V_183 L_90
L_91 , V_8 , V_263 , V_155 . V_163 . V_165 ) ;
V_263 = V_155 . V_163 . V_165 ;
}
if ( V_40 -> V_193 ( & V_264 , V_263 ) ) {
for ( V_22 = 0 ; V_22 < F_131 () ; V_22 ++ ) {
if ( ! V_40 -> V_193 ( & V_264 , V_22 ) )
break;
}
if ( V_22 == F_131 () )
F_15 ( L_92 ) ;
F_116 ( V_183 L_93
L_94 , V_8 , V_263 , V_22 ) ;
V_263 = V_22 ;
}
V_40 -> V_194 ( V_263 , & V_65 ) ;
F_134 ( V_264 , V_264 , V_65 ) ;
if ( V_155 . V_163 . V_165 != V_263 ) {
V_155 . V_163 . V_165 = V_263 ;
F_32 ( & V_54 , V_53 ) ;
F_28 ( V_8 , 0 , V_155 . V_162 ) ;
V_155 . V_162 = F_30 ( V_8 , 0 ) ;
F_33 ( & V_54 , V_53 ) ;
if ( V_155 . V_163 . V_165 != V_263 ) {
F_18 ( L_95 ,
V_8 ) ;
return - 1 ;
}
}
F_14 ( V_23 , V_86
L_96 , V_8 , V_263 ) ;
return V_263 ;
}
static T_7 F_199 ( int V_33 , T_7 V_266 )
{
if ( ( V_196 . V_197 == V_198 ) &&
! F_136 ( V_199 ) )
return F_197 ( V_33 , V_266 ) ;
else
return V_266 ;
}
static T_7 F_199 ( int V_33 , T_7 V_266 )
{
union V_154 V_155 ;
F_200 ( V_267 , 256 ) ;
unsigned long V_53 ;
T_7 V_268 ;
int V_22 ;
F_201 ( V_267 , 256 ) ;
F_22 (i)
F_202 ( F_1 ( V_22 ) , V_267 ) ;
if ( ! F_67 ( V_266 , V_267 ) )
return V_266 ;
F_32 ( & V_54 , V_53 ) ;
V_155 . V_162 = F_30 ( V_33 , 0 ) ;
F_33 ( & V_54 , V_53 ) ;
V_268 = V_155 . V_163 . V_165 ;
if ( ! F_67 ( V_268 , V_267 ) ) {
F_14 ( V_23 , V_86
L_97 ,
V_33 , V_268 , V_266 ) ;
return V_268 ;
}
V_268 = F_203 ( V_267 , 256 ) ;
V_155 . V_163 . V_165 = V_268 ;
F_32 ( & V_54 , V_53 ) ;
F_28 ( V_33 , 0 , V_155 . V_162 ) ;
V_155 . V_162 = F_30 ( V_33 , 0 ) ;
F_33 ( & V_54 , V_53 ) ;
F_188 ( V_155 . V_163 . V_165 != V_268 ) ;
return V_268 ;
}
static int F_204 ( int V_8 )
{
union V_156 V_157 ;
unsigned long V_53 ;
F_32 ( & V_54 , V_53 ) ;
V_157 . V_162 = F_30 ( V_8 , 1 ) ;
F_33 ( & V_54 , V_53 ) ;
return V_157 . V_163 . V_164 ;
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
V_33 = F_65 ( V_8 , V_12 , V_136 ) ;
if ( V_33 < 0 )
return - 1 ;
* V_76 = F_77 ( V_33 ) ;
* V_103 = F_71 ( V_33 ) ;
return 0 ;
}
void T_2 F_205 ( void )
{
int V_12 , V_8 , V_13 , V_269 ;
const struct V_215 * V_56 ;
struct V_270 * V_271 ;
struct V_72 * V_272 ;
struct V_172 * V_173 ;
if ( V_18 == 1 )
return;
F_57 (ioapic, pin) {
V_269 = F_65 ( V_8 , V_12 , V_136 ) ;
if ( V_269 == - 1 )
continue;
V_13 = F_102 ( V_269 , V_8 , V_12 , 0 ) ;
if ( V_13 < 0 || ! F_8 ( V_8 , V_13 ) )
continue;
V_271 = F_206 ( V_13 ) ;
F_207 ( & V_271 -> V_273 ) ;
V_272 = F_208 ( V_271 ) ;
if ( ! F_209 ( V_272 ) || F_210 ( V_272 ) )
V_56 = F_211 ( V_272 ) ;
else
V_56 = V_40 -> V_274 () ;
V_173 = F_212 ( V_272 ) ;
if ( V_173 -> V_219 )
V_173 -> V_219 ( V_272 , V_56 , false ) ;
F_213 ( & V_271 -> V_273 ) ;
}
}
static struct V_275 * T_2 F_214 ( void )
{
unsigned long V_276 ;
struct V_275 * V_277 ;
char * V_278 ;
int V_22 ;
if ( V_178 == 0 )
return NULL ;
V_276 = V_279 + sizeof( struct V_275 ) ;
V_276 *= V_178 ;
V_278 = F_215 ( V_276 ) ;
V_277 = ( void * ) V_278 ;
V_278 += sizeof( struct V_275 ) * V_178 ;
F_22 (i) {
V_277 [ V_22 ] . V_280 = V_278 ;
V_277 [ V_22 ] . V_53 = V_281 | V_282 ;
snprintf ( V_278 , V_279 , L_98 , V_22 ) ;
V_278 += V_279 ;
V_2 [ V_22 ] . V_283 = & V_277 [ V_22 ] ;
}
V_284 = V_277 ;
return V_277 ;
}
void T_2 F_216 ( void )
{
unsigned long V_285 , V_33 = V_286 ;
struct V_275 * V_287 ;
int V_22 ;
V_287 = F_214 () ;
F_22 (i) {
if ( V_288 ) {
V_285 = F_2 ( V_22 ) ;
#ifdef F_103
if ( ! V_285 ) {
F_116 ( V_192
L_99
L_100
L_101 ) ;
V_288 = 0 ;
V_18 = 1 ;
goto V_289;
}
#endif
} else {
#ifdef F_103
V_289:
#endif
V_285 = ( unsigned long ) F_217 ( V_290 ) ;
V_285 = F_218 ( V_285 ) ;
}
F_219 ( V_33 , V_285 ) ;
F_14 ( V_23 , L_102 ,
F_220 ( V_33 ) + ( V_285 & ~ V_291 ) ,
V_285 ) ;
V_33 ++ ;
V_287 -> V_292 = V_285 ;
V_287 -> V_293 = V_285 + V_294 - 1 ;
V_287 ++ ;
}
}
void T_2 F_221 ( void )
{
int V_22 ;
struct V_275 * V_295 = V_284 ;
if ( ! V_295 ) {
if ( V_178 > 0 )
F_116 ( V_192
L_103 ) ;
return;
}
F_22 (i) {
F_222 ( & V_296 , V_295 ) ;
V_295 ++ ;
}
}
int F_105 ( T_1 V_111 )
{
int V_22 ;
if ( V_178 == 0 )
return - 1 ;
F_22 (i) {
struct V_6 * V_9 = F_3 ( V_22 ) ;
if ( V_111 >= V_9 -> V_11 && V_111 <= V_9 -> V_10 )
return V_22 ;
}
F_116 ( V_192 L_104 , V_111 ) ;
return - 1 ;
}
int F_106 ( int V_8 , T_1 V_111 )
{
struct V_6 * V_9 ;
if ( F_223 ( V_8 < 0 ) )
return - 1 ;
V_9 = F_3 ( V_8 ) ;
if ( F_223 ( V_111 > V_9 -> V_10 ) )
return - 1 ;
return V_111 - V_9 -> V_11 ;
}
static int F_224 ( int V_33 )
{
union V_154 V_155 ;
union V_156 V_157 ;
union V_158 V_159 ;
V_155 . V_162 = F_30 ( V_33 , 0 ) ;
V_157 . V_162 = F_30 ( V_33 , 1 ) ;
V_159 . V_162 = F_30 ( V_33 , 2 ) ;
if ( V_155 . V_162 == - 1 && V_157 . V_162 == - 1 && V_159 . V_162 == - 1 ) {
F_74 ( L_105 ,
F_2 ( V_33 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_225 ( void )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_297 ; V_33 ++ )
if ( V_2 [ V_33 ] . V_37 == 0 )
return V_33 ;
return V_297 ;
}
int F_226 ( int V_266 , T_1 V_298 , T_1 V_11 ,
struct V_250 * V_211 )
{
bool V_299 = ! ! V_125 ;
struct V_6 * V_9 ;
int V_33 , V_8 , V_168 ;
T_1 V_10 ;
if ( ! V_298 ) {
F_74 ( L_106 ) ;
return - V_300 ;
}
F_22 (ioapic)
if ( V_2 [ V_8 ] . V_3 . V_5 == V_298 ) {
F_74 ( L_107 ,
V_298 , V_8 ) ;
return - V_301 ;
}
V_33 = F_225 () ;
if ( V_33 >= V_297 ) {
F_74 ( L_108 ,
V_297 , V_33 ) ;
return - V_302 ;
}
V_2 [ V_33 ] . V_3 . type = V_303 ;
V_2 [ V_33 ] . V_3 . V_53 = V_304 ;
V_2 [ V_33 ] . V_3 . V_5 = V_298 ;
F_219 ( V_286 + V_33 , V_298 ) ;
if ( F_224 ( V_33 ) ) {
F_227 ( V_286 + V_33 ) ;
return - V_135 ;
}
V_2 [ V_33 ] . V_3 . V_4 = F_199 ( V_33 , V_266 ) ;
V_2 [ V_33 ] . V_3 . V_305 = F_204 ( V_33 ) ;
V_168 = F_195 ( V_33 ) ;
V_10 = V_11 + V_168 - 1 ;
F_22 (ioapic) {
V_9 = F_3 ( V_8 ) ;
if ( ( V_11 >= V_9 -> V_11 &&
V_11 <= V_9 -> V_10 ) ||
( V_10 >= V_9 -> V_11 &&
V_10 <= V_9 -> V_10 ) ) {
F_74 ( L_109 ,
V_11 , V_10 ,
V_9 -> V_11 , V_9 -> V_10 ) ;
F_227 ( V_286 + V_33 ) ;
return - V_302 ;
}
}
V_9 = F_3 ( V_33 ) ;
V_9 -> V_11 = V_11 ;
V_9 -> V_10 = V_10 ;
V_2 [ V_33 ] . V_15 = NULL ;
V_2 [ V_33 ] . V_123 = * V_211 ;
if ( V_299 ) {
if ( F_182 ( V_33 ) ) {
F_227 ( V_286 + V_33 ) ;
return - V_62 ;
}
F_16 ( V_33 ) ;
}
if ( V_9 -> V_10 >= V_262 )
V_262 = V_9 -> V_10 + 1 ;
if ( V_178 <= V_33 )
V_178 = V_33 + 1 ;
V_2 [ V_33 ] . V_37 = V_168 ;
F_228 ( L_110 ,
V_33 , F_1 ( V_33 ) ,
F_53 ( V_33 ) , F_2 ( V_33 ) ,
V_9 -> V_11 , V_9 -> V_10 ) ;
return 0 ;
}
int F_229 ( T_1 V_11 )
{
int V_8 , V_12 ;
int V_142 = 0 ;
F_22 (ioapic)
if ( V_2 [ V_8 ] . V_7 . V_11 == V_11 ) {
V_142 = 1 ;
break;
}
if ( ! V_142 ) {
F_74 ( L_111 , V_11 ) ;
return - V_135 ;
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
F_185 ( V_8 ) ;
F_19 ( V_8 ) ;
if ( V_2 [ V_8 ] . V_283 )
F_230 ( V_2 [ V_8 ] . V_283 ) ;
F_227 ( V_286 + V_8 ) ;
memset ( & V_2 [ V_8 ] , 0 , sizeof( V_2 [ V_8 ] ) ) ;
return 0 ;
}
int F_231 ( T_1 V_11 )
{
int V_8 ;
F_22 (ioapic)
if ( V_2 [ V_8 ] . V_7 . V_11 == V_11 )
return 1 ;
return 0 ;
}
static void F_232 ( T_1 V_111 , struct V_58 * V_46 ,
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
static void F_233 ( struct V_210 * V_211 , struct V_58 * V_46 ,
struct V_36 * V_52 )
{
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_52 -> V_78 = V_40 -> V_306 ;
V_52 -> V_151 = V_40 -> V_307 ;
V_52 -> V_153 = V_211 -> V_221 ;
V_52 -> V_41 = V_211 -> V_41 ;
V_52 -> V_76 = V_46 -> V_76 ;
V_52 -> V_103 = V_46 -> V_103 ;
if ( V_46 -> V_76 == V_82 )
V_52 -> V_56 = V_57 ;
else
V_52 -> V_56 = V_80 ;
}
int F_234 ( struct V_14 * V_121 , unsigned int V_308 ,
unsigned int V_309 , void * V_236 )
{
int V_218 , V_8 , V_12 ;
struct V_210 * V_211 ;
struct V_72 * V_72 ;
struct V_58 * V_46 ;
struct V_101 * V_102 = V_236 ;
unsigned long V_53 ;
if ( ! V_102 || V_309 > 1 )
return - V_300 ;
V_72 = F_97 ( V_121 , V_308 ) ;
if ( ! V_72 )
return - V_300 ;
V_8 = F_235 ( V_121 ) ;
V_12 = V_102 -> V_113 ;
if ( F_100 ( V_121 , ( V_310 ) V_12 ) > 0 )
return - V_301 ;
V_46 = F_17 ( sizeof( * V_46 ) , V_38 ) ;
if ( ! V_46 )
return - V_62 ;
V_102 -> V_311 = & V_46 -> V_52 ;
V_218 = F_236 ( V_121 , V_308 , V_309 , V_102 ) ;
if ( V_218 < 0 ) {
F_20 ( V_46 ) ;
return V_218 ;
}
F_237 ( & V_46 -> V_64 ) ;
V_72 -> V_312 = V_102 -> V_113 ;
V_72 -> V_173 = ( V_121 -> V_217 == V_252 ) ?
& V_174 : & V_175 ;
V_72 -> V_73 = V_46 ;
F_232 ( F_5 ( V_8 , V_12 ) , V_46 , V_102 ) ;
V_211 = F_152 ( V_72 ) ;
F_44 ( V_46 , F_85 ( V_102 ) , V_8 , V_12 ) ;
F_176 ( V_53 ) ;
if ( V_102 -> V_311 )
F_233 ( V_211 , V_46 , V_102 -> V_311 ) ;
F_86 ( V_308 , V_46 -> V_76 ) ;
if ( V_308 < F_7 () )
V_206 -> V_56 ( V_308 ) ;
F_142 ( V_53 ) ;
F_14 ( V_23 , V_87
L_113 ,
V_8 , F_1 ( V_8 ) , V_12 , V_211 -> V_41 ,
V_308 , V_46 -> V_76 , V_46 -> V_103 , V_211 -> V_221 ) ;
return 0 ;
}
void F_238 ( struct V_14 * V_121 , unsigned int V_308 ,
unsigned int V_309 )
{
struct V_72 * V_72 ;
struct V_58 * V_46 ;
F_188 ( V_309 != 1 ) ;
V_72 = F_97 ( V_121 , V_308 ) ;
if ( V_72 && V_72 -> V_73 ) {
V_46 = V_72 -> V_73 ;
F_41 ( V_46 , F_235 ( V_121 ) ,
( int ) V_72 -> V_312 ) ;
F_223 ( ! F_121 ( & V_46 -> V_64 ) ) ;
F_20 ( V_72 -> V_73 ) ;
}
F_239 ( V_121 , V_308 , V_309 ) ;
}
void F_240 ( struct V_14 * V_121 ,
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
void F_241 ( struct V_14 * V_121 ,
struct V_72 * V_72 )
{
F_36 ( F_235 ( V_121 ) ,
( int ) V_72 -> V_312 ) ;
}
int F_235 ( struct V_14 * V_121 )
{
return ( int ) ( long ) V_121 -> V_313 ;
}
