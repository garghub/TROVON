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
static void F_17 ( int V_38 )
{
T_3 V_39 ;
if ( V_2 [ V_38 ] . V_40 )
return;
V_39 = sizeof( struct V_41 ) * V_2 [ V_38 ] . V_42 ;
V_2 [ V_38 ] . V_40 = F_18 ( V_39 , V_37 ) ;
if ( ! V_2 [ V_38 ] . V_40 )
F_19 ( L_4 , V_38 ) ;
}
static void F_20 ( int V_38 )
{
F_21 ( V_2 [ V_38 ] . V_40 ) ;
V_2 [ V_38 ] . V_40 = NULL ;
}
int T_2 F_22 ( void )
{
struct V_43 * V_44 ;
int V_24 , V_36 = F_23 ( 0 ) ;
if ( ! F_7 () )
V_45 = ~ 0UL ;
F_24 (i)
F_17 ( V_24 ) ;
for ( V_24 = 0 ; V_24 < F_7 () ; V_24 ++ ) {
V_44 = F_25 ( V_24 , V_36 ) ;
V_44 -> V_46 = V_47 + V_24 ;
F_26 ( V_44 -> V_48 ) ;
}
return 0 ;
}
void F_27 ( unsigned int V_49 , unsigned int V_46 )
{
struct V_50 T_4 * V_50 = F_28 ( V_49 ) ;
F_29 ( V_46 , & V_50 -> V_51 ) ;
}
unsigned int F_30 ( unsigned int V_49 , unsigned int V_52 )
{
struct V_50 T_4 * V_50 = F_28 ( V_49 ) ;
F_29 ( V_52 , & V_50 -> V_53 ) ;
return F_31 ( & V_50 -> V_54 ) ;
}
void F_32 ( unsigned int V_49 , unsigned int V_52 , unsigned int V_55 )
{
struct V_50 T_4 * V_50 = F_28 ( V_49 ) ;
F_29 ( V_52 , & V_50 -> V_53 ) ;
F_29 ( V_55 , & V_50 -> V_54 ) ;
}
void F_33 ( unsigned int V_49 , unsigned int V_52 , unsigned int V_55 )
{
struct V_50 T_4 * V_50 = F_28 ( V_49 ) ;
if ( V_56 )
F_29 ( V_52 , & V_50 -> V_53 ) ;
F_29 ( V_55 , & V_50 -> V_54 ) ;
}
static struct V_41 F_34 ( int V_49 , int V_12 )
{
union V_57 V_58 ;
V_58 . V_59 = F_35 ( V_49 , 0x10 + 2 * V_12 ) ;
V_58 . V_60 = F_35 ( V_49 , 0x11 + 2 * V_12 ) ;
return V_58 . V_61 ;
}
static struct V_41 F_36 ( int V_49 , int V_12 )
{
union V_57 V_58 ;
unsigned long V_62 ;
F_37 ( & V_63 , V_62 ) ;
V_58 . V_61 = F_34 ( V_49 , V_12 ) ;
F_38 ( & V_63 , V_62 ) ;
return V_58 . V_61 ;
}
static void F_39 ( int V_49 , int V_12 , struct V_41 V_64 )
{
union V_57 V_58 = { { 0 , 0 } } ;
V_58 . V_61 = V_64 ;
F_40 ( V_49 , 0x11 + 2 * V_12 , V_58 . V_60 ) ;
F_40 ( V_49 , 0x10 + 2 * V_12 , V_58 . V_59 ) ;
}
static void F_41 ( int V_49 , int V_12 , struct V_41 V_64 )
{
unsigned long V_62 ;
F_37 ( & V_63 , V_62 ) ;
F_39 ( V_49 , V_12 , V_64 ) ;
F_38 ( & V_63 , V_62 ) ;
}
static void F_42 ( int V_49 , int V_12 )
{
unsigned long V_62 ;
union V_57 V_58 = { . V_61 . V_65 = 1 } ;
F_37 ( & V_63 , V_62 ) ;
F_40 ( V_49 , 0x10 + 2 * V_12 , V_58 . V_59 ) ;
F_40 ( V_49 , 0x11 + 2 * V_12 , V_58 . V_60 ) ;
F_38 ( & V_63 , V_62 ) ;
}
static int F_43 ( struct V_43 * V_44 , int V_36 , int V_49 , int V_12 )
{
struct V_35 * V_61 ;
F_44 (entry, cfg->irq_2_pin)
if ( V_61 -> V_49 == V_49 && V_61 -> V_12 == V_12 )
return 0 ;
V_61 = F_15 ( V_36 ) ;
if ( ! V_61 ) {
F_19 ( L_5 ,
V_36 , V_49 , V_12 ) ;
return - V_66 ;
}
V_61 -> V_49 = V_49 ;
V_61 -> V_12 = V_12 ;
F_45 ( & V_61 -> V_67 , & V_44 -> V_68 ) ;
return 0 ;
}
static void F_46 ( struct V_43 * V_44 , int V_49 , int V_12 )
{
struct V_35 * V_69 , * V_61 ;
F_47 (entry, tmp, &cfg->irq_2_pin, list)
if ( V_61 -> V_49 == V_49 && V_61 -> V_12 == V_12 ) {
F_48 ( & V_61 -> V_67 ) ;
F_21 ( V_61 ) ;
return;
}
}
static void F_49 ( struct V_43 * V_44 , int V_36 , int V_49 , int V_12 )
{
if ( F_43 ( V_44 , V_36 , V_49 , V_12 ) )
F_14 ( L_6 ) ;
}
static void T_2 F_50 ( struct V_43 * V_44 , int V_36 ,
int V_70 , int V_71 ,
int V_72 , int V_73 )
{
struct V_35 * V_61 ;
F_44 (entry, cfg->irq_2_pin) {
if ( V_61 -> V_49 == V_70 && V_61 -> V_12 == V_71 ) {
V_61 -> V_49 = V_72 ;
V_61 -> V_12 = V_73 ;
return;
}
}
F_49 ( V_44 , V_36 , V_72 , V_73 ) ;
}
static void F_51 ( struct V_35 * V_61 ,
int V_74 , int V_75 ,
void (* F_52)( struct V_35 * V_61 ) )
{
unsigned int V_52 , V_12 ;
V_12 = V_61 -> V_12 ;
V_52 = F_35 ( V_61 -> V_49 , 0x10 + V_12 * 2 ) ;
V_52 &= V_74 ;
V_52 |= V_75 ;
F_53 ( V_61 -> V_49 , 0x10 + V_12 * 2 , V_52 ) ;
if ( F_52 )
F_52 ( V_61 ) ;
}
static void F_54 ( struct V_43 * V_44 ,
int V_74 , int V_75 ,
void (* F_52)( struct V_35 * V_61 ) )
{
struct V_35 * V_61 ;
F_44 (entry, cfg->irq_2_pin)
F_51 ( V_61 , V_74 , V_75 , F_52 ) ;
}
static void F_55 ( struct V_35 * V_61 )
{
struct V_50 T_4 * V_50 ;
V_50 = F_28 ( V_61 -> V_49 ) ;
F_31 ( & V_50 -> V_54 ) ;
}
static void F_56 ( struct V_43 * V_44 )
{
unsigned long V_62 ;
F_37 ( & V_63 , V_62 ) ;
F_54 ( V_44 , ~ 0 , V_76 , & F_55 ) ;
F_38 ( & V_63 , V_62 ) ;
}
static void F_57 ( struct V_77 * V_54 )
{
F_56 ( F_58 ( V_54 ) ) ;
}
static void F_59 ( struct V_43 * V_44 )
{
F_54 ( V_44 , ~ V_76 , 0 , NULL ) ;
}
static void F_60 ( struct V_43 * V_44 )
{
unsigned long V_62 ;
F_37 ( & V_63 , V_62 ) ;
F_59 ( V_44 ) ;
F_38 ( & V_63 , V_62 ) ;
}
static void F_61 ( struct V_77 * V_54 )
{
F_60 ( F_58 ( V_54 ) ) ;
}
void F_62 ( int V_49 , int V_12 , int V_46 )
{
if ( F_63 ( V_49 ) >= 0x20 ) {
F_27 ( V_49 , V_46 ) ;
} else {
struct V_41 V_61 , V_78 ;
V_61 = V_78 = F_34 ( V_49 , V_12 ) ;
V_78 . V_65 = 1 ;
V_78 . V_79 = V_80 ;
F_39 ( V_49 , V_12 , V_78 ) ;
F_39 ( V_49 , V_12 , V_61 ) ;
}
}
void F_64 ( unsigned int V_13 , struct V_43 * V_44 )
{
struct V_35 * V_61 ;
unsigned long V_62 ;
F_37 ( & V_63 , V_62 ) ;
F_44 (entry, cfg->irq_2_pin)
V_81 . V_82 ( V_61 -> V_49 , V_61 -> V_12 ,
V_44 -> V_46 ) ;
F_38 ( & V_63 , V_62 ) ;
}
static void F_65 ( unsigned int V_49 , unsigned int V_12 )
{
struct V_41 V_61 ;
V_61 = F_36 ( V_49 , V_12 ) ;
if ( V_61 . V_83 == V_84 )
return;
if ( ! V_61 . V_65 ) {
V_61 . V_65 = 1 ;
F_41 ( V_49 , V_12 , V_61 ) ;
V_61 = F_36 ( V_49 , V_12 ) ;
}
if ( V_61 . V_85 ) {
unsigned long V_62 ;
if ( ! V_61 . V_79 ) {
V_61 . V_79 = V_86 ;
F_41 ( V_49 , V_12 , V_61 ) ;
}
F_37 ( & V_63 , V_62 ) ;
V_81 . V_82 ( V_49 , V_12 , V_61 . V_46 ) ;
F_38 ( & V_63 , V_62 ) ;
}
F_42 ( V_49 , V_12 ) ;
V_61 = F_36 ( V_49 , V_12 ) ;
if ( V_61 . V_85 )
F_19 ( L_7 ,
F_1 ( V_49 ) , V_12 ) ;
}
static void F_66 ( void )
{
int V_49 , V_12 ;
F_67 (apic, pin)
F_65 ( V_49 , V_12 ) ;
}
static int T_2 F_68 ( char * V_21 )
{
int V_24 , V_87 ;
int V_88 [ V_89 + 1 ] ;
F_69 ( V_21 , F_70 ( V_88 ) , V_88 ) ;
F_13 ( V_25 , V_90
L_8 ) ;
V_87 = V_89 ;
if ( V_88 [ 0 ] < V_89 )
V_87 = V_88 [ 0 ] ;
for ( V_24 = 0 ; V_24 < V_87 ; V_24 ++ ) {
F_13 ( V_25 , V_91
L_9 , V_24 , V_88 [ V_24 + 1 ] ) ;
V_92 [ V_89 - V_24 - 1 ] = V_88 [ V_24 + 1 ] ;
}
return 1 ;
}
int F_71 ( void )
{
int V_49 , V_12 ;
int V_93 = 0 ;
F_24 (apic) {
if ( ! V_2 [ V_49 ] . V_40 ) {
V_93 = - V_66 ;
continue;
}
F_72 (apic, pin)
V_2 [ V_49 ] . V_40 [ V_12 ] =
F_36 ( V_49 , V_12 ) ;
}
return V_93 ;
}
void F_73 ( void )
{
int V_49 , V_12 ;
F_24 (apic) {
if ( ! V_2 [ V_49 ] . V_40 )
continue;
F_72 (apic, pin) {
struct V_41 V_61 ;
V_61 = V_2 [ V_49 ] . V_40 [ V_12 ] ;
if ( ! V_61 . V_65 ) {
V_61 . V_65 = 1 ;
F_41 ( V_49 , V_12 , V_61 ) ;
}
}
}
}
int F_74 ( void )
{
int V_49 , V_12 ;
F_24 (apic) {
if ( ! V_2 [ V_49 ] . V_40 )
continue;
F_72 (apic, pin)
F_41 ( V_49 , V_12 ,
V_2 [ V_49 ] . V_40 [ V_12 ] ) ;
}
return 0 ;
}
static int F_75 ( int V_1 , int V_12 , int type )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_32 ; V_24 ++ )
if ( V_33 [ V_24 ] . V_26 == type &&
( V_33 [ V_24 ] . V_30 == F_1 ( V_1 ) ||
V_33 [ V_24 ] . V_30 == V_94 ) &&
V_33 [ V_24 ] . V_31 == V_12 )
return V_24 ;
return - 1 ;
}
static int T_2 F_76 ( int V_13 , int type )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_32 ; V_24 ++ ) {
int V_95 = V_33 [ V_24 ] . V_28 ;
if ( F_77 ( V_95 , V_96 ) &&
( V_33 [ V_24 ] . V_26 == type ) &&
( V_33 [ V_24 ] . V_29 == V_13 ) )
return V_33 [ V_24 ] . V_31 ;
}
return - 1 ;
}
static int T_2 F_78 ( int V_13 , int type )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_32 ; V_24 ++ ) {
int V_95 = V_33 [ V_24 ] . V_28 ;
if ( F_77 ( V_95 , V_96 ) &&
( V_33 [ V_24 ] . V_26 == type ) &&
( V_33 [ V_24 ] . V_29 == V_13 ) )
break;
}
if ( V_24 < V_32 ) {
int V_1 ;
F_24 (ioapic_idx)
if ( F_1 ( V_1 ) == V_33 [ V_24 ] . V_30 )
return V_1 ;
}
return - 1 ;
}
static int F_79 ( unsigned int V_13 )
{
if ( V_13 < F_7 () ) {
unsigned int V_97 = 0x4d0 + ( V_13 >> 3 ) ;
return ( F_80 ( V_97 ) >> ( V_13 & 7 ) ) & 1 ;
}
F_13 ( V_25 , V_90
L_10 , V_13 ) ;
return 0 ;
}
static int F_81 ( int V_38 )
{
int V_98 = V_33 [ V_38 ] . V_28 ;
int V_99 ;
switch ( V_33 [ V_38 ] . V_27 & 3 )
{
case 0 :
if ( F_77 ( V_98 , V_96 ) )
V_99 = F_82 ( V_38 ) ;
else
V_99 = F_83 ( V_38 ) ;
break;
case 1 :
{
V_99 = 0 ;
break;
}
case 2 :
{
F_84 ( L_11 ) ;
V_99 = 1 ;
break;
}
case 3 :
{
V_99 = 1 ;
break;
}
default:
{
F_84 ( L_11 ) ;
V_99 = 1 ;
break;
}
}
return V_99 ;
}
static int F_85 ( int V_38 )
{
int V_98 = V_33 [ V_38 ] . V_28 ;
int V_79 ;
switch ( ( V_33 [ V_38 ] . V_27 >> 2 ) & 3 )
{
case 0 :
if ( F_77 ( V_98 , V_96 ) )
V_79 = F_86 ( V_38 ) ;
else
V_79 = F_87 ( V_38 ) ;
#ifdef F_88
switch ( V_100 [ V_98 ] ) {
case V_101 :
{
break;
}
case V_102 :
{
V_79 = F_89 ( V_38 ) ;
break;
}
case V_103 :
{
break;
}
default:
{
F_84 ( L_11 ) ;
V_79 = 1 ;
break;
}
}
#endif
break;
case 1 :
{
V_79 = 0 ;
break;
}
case 2 :
{
F_84 ( L_11 ) ;
V_79 = 1 ;
break;
}
case 3 :
{
V_79 = 1 ;
break;
}
default:
{
F_84 ( L_11 ) ;
V_79 = 0 ;
break;
}
}
return V_79 ;
}
static int F_90 ( struct V_16 * V_48 , T_1 V_104 , int V_12 )
{
int V_13 = - 1 ;
int V_8 = ( int ) ( long ) V_48 -> V_105 ;
int type = V_2 [ V_8 ] . V_106 . type ;
switch ( type ) {
case V_107 :
if ( V_104 < F_7 () )
V_13 = F_91 ( V_48 , V_12 ) ;
else if ( F_92 ( V_48 , V_104 , V_12 , 1 ) == 0 )
V_13 = V_104 ;
break;
case V_108 :
if ( F_92 ( V_48 , V_104 , V_12 , 1 ) == 0 )
V_13 = V_104 ;
break;
case V_109 :
V_13 = F_91 ( V_48 , V_12 ) ;
break;
default:
F_93 ( 1 , L_12 , type ) ;
break;
}
return V_13 > 0 ? V_13 : - 1 ;
}
static int F_94 ( T_1 V_104 , int V_38 , int V_8 , int V_12 ,
unsigned int V_62 )
{
int V_13 ;
struct V_16 * V_48 = F_8 ( V_8 ) ;
struct V_14 * V_110 = V_14 ( V_8 , V_12 ) ;
if ( ! V_48 )
return - 1 ;
F_95 ( & V_111 ) ;
if ( V_38 >= 0 && F_77 ( V_33 [ V_38 ] . V_28 , V_96 ) ) {
V_13 = V_33 [ V_38 ] . V_29 ;
if ( V_62 & V_112 ) {
if ( V_110 -> V_113 == 0 &&
F_96 ( V_48 , V_13 , V_12 ) != 0 )
V_13 = - 1 ;
if ( V_13 == 0 )
V_110 -> V_113 ++ ;
}
} else {
V_13 = F_97 ( V_48 , V_12 ) ;
if ( V_13 <= 0 && ( V_62 & V_112 ) )
V_13 = F_90 ( V_48 , V_104 , V_12 ) ;
}
if ( V_62 & V_112 ) {
if ( V_13 < F_7 () && V_110 -> V_113 == 1 &&
F_96 ( V_48 , V_13 , V_12 ) != 0 )
V_13 = - 1 ;
if ( V_13 > 0 )
V_110 -> V_113 ++ ;
else if ( V_110 -> V_113 == 0 )
V_110 -> V_114 = 0 ;
}
F_98 ( & V_111 ) ;
return V_13 > 0 ? V_13 : - 1 ;
}
static int F_99 ( int V_38 , int V_8 , int V_12 , unsigned int V_62 )
{
T_1 V_104 = F_5 ( V_8 , V_12 ) ;
if ( V_33 [ V_38 ] . V_31 != V_12 )
F_19 ( L_13 ) ;
#ifdef F_100
if ( ( V_12 >= 16 ) && ( V_12 <= 23 ) ) {
if ( V_92 [ V_12 - 16 ] != - 1 ) {
if ( ! V_92 [ V_12 - 16 ] ) {
F_13 ( V_25 , V_91
L_14 , V_12 - 16 ) ;
} else {
int V_13 = V_92 [ V_12 - 16 ] ;
F_13 ( V_25 , V_91
L_15 ,
V_12 - 16 , V_13 ) ;
return V_13 ;
}
}
}
#endif
return F_94 ( V_104 , V_38 , V_8 , V_12 , V_62 ) ;
}
int F_101 ( T_1 V_104 , unsigned int V_62 )
{
int V_8 , V_12 , V_38 ;
V_8 = F_102 ( V_104 ) ;
if ( V_8 < 0 )
return - 1 ;
V_12 = F_103 ( V_8 , V_104 ) ;
V_38 = F_75 ( V_8 , V_12 , V_115 ) ;
if ( ( V_62 & V_116 ) && V_38 < 0 )
return - 1 ;
return F_94 ( V_104 , V_38 , V_8 , V_12 , V_62 ) ;
}
void F_104 ( int V_13 )
{
struct V_77 * V_54 = F_105 ( V_13 ) ;
struct V_14 * V_110 ;
int V_8 , V_12 ;
if ( ! V_54 || ! V_54 -> V_48 )
return;
V_8 = ( int ) ( long ) V_54 -> V_48 -> V_105 ;
V_12 = ( int ) V_54 -> V_117 ;
V_110 = V_14 ( V_8 , V_12 ) ;
F_95 ( & V_111 ) ;
if ( -- V_110 -> V_113 == 0 ) {
V_110 -> V_114 = 0 ;
if ( V_13 < F_7 () &&
V_2 [ V_8 ] . V_106 . type == V_107 )
F_106 ( V_54 -> V_48 , V_13 ) ;
else
F_107 ( V_13 ) ;
}
F_98 ( & V_111 ) ;
}
int F_108 ( int V_98 , int V_118 , int V_12 )
{
int V_13 , V_24 , V_119 = - 1 , V_120 = - 1 ;
F_13 ( V_121 ,
L_16 ,
V_98 , V_118 , V_12 ) ;
if ( F_77 ( V_98 , V_96 ) ) {
F_13 ( V_25 ,
L_17 , V_98 ) ;
return - 1 ;
}
for ( V_24 = 0 ; V_24 < V_32 ; V_24 ++ ) {
int V_95 = V_33 [ V_24 ] . V_28 ;
int V_1 , V_122 = 0 ;
if ( V_98 != V_95 || V_33 [ V_24 ] . V_26 != V_115 ||
V_118 != ( ( V_33 [ V_24 ] . V_29 >> 2 ) & 0x1f ) )
continue;
F_24 (ioapic_idx)
if ( F_1 ( V_1 ) == V_33 [ V_24 ] . V_30 ||
V_33 [ V_24 ] . V_30 == V_94 ) {
V_122 = 1 ;
break;
}
if ( ! V_122 )
continue;
V_13 = F_99 ( V_24 , V_1 , V_33 [ V_24 ] . V_31 , 0 ) ;
if ( V_13 > 0 && ! F_109 ( V_13 ) )
continue;
if ( V_12 == ( V_33 [ V_24 ] . V_29 & 3 ) ) {
V_120 = V_24 ;
V_119 = V_1 ;
goto V_123;
}
if ( V_120 < 0 ) {
V_120 = V_24 ;
V_119 = V_1 ;
}
}
if ( V_120 < 0 )
return - 1 ;
V_123:
return F_99 ( V_120 , V_119 , V_33 [ V_120 ] . V_31 ,
V_112 ) ;
}
static inline int F_110 ( int V_13 )
{
int V_49 , V_38 , V_12 ;
F_67 (apic, pin) {
V_38 = F_75 ( V_49 , V_12 , V_115 ) ;
if ( ( V_38 != - 1 ) && ( V_13 == F_99 ( V_38 , V_49 , V_12 , 0 ) ) )
return F_85 ( V_38 ) ;
}
return 0 ;
}
static inline int F_110 ( int V_13 )
{
return 1 ;
}
static void F_111 ( unsigned int V_13 , struct V_43 * V_44 ,
unsigned long V_79 )
{
struct V_124 * V_125 = & V_126 ;
T_5 V_127 ;
bool V_128 ;
if ( ( V_79 == V_129 && F_110 ( V_13 ) ) ||
V_79 == V_86 ) {
F_112 ( V_13 , V_130 ) ;
V_128 = true ;
} else {
F_113 ( V_13 , V_130 ) ;
V_128 = false ;
}
if ( F_114 ( V_13 , V_44 , V_125 ) )
V_128 = V_79 != 0 ;
V_127 = V_128 ? V_131 : V_132 ;
F_115 ( V_13 , V_125 , V_127 ,
V_128 ? L_18 : L_19 ) ;
}
int F_116 ( int V_13 , struct V_41 * V_61 ,
unsigned int V_133 , int V_46 ,
struct V_134 * V_135 )
{
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> V_83 = V_49 -> V_136 ;
V_61 -> V_137 = V_49 -> V_138 ;
V_61 -> V_139 = V_133 ;
V_61 -> V_46 = V_46 ;
V_61 -> V_65 = 0 ;
V_61 -> V_79 = V_135 -> V_79 ;
V_61 -> V_99 = V_135 -> V_99 ;
if ( V_135 -> V_79 )
V_61 -> V_65 = 1 ;
return 0 ;
}
static void F_117 ( unsigned int V_13 , struct V_43 * V_44 ,
struct V_134 * V_135 )
{
struct V_41 V_61 ;
unsigned int V_139 ;
if ( ! F_109 ( V_13 ) )
return;
if ( F_118 ( V_13 , V_44 , V_49 -> V_140 () ) )
return;
if ( V_49 -> V_141 ( V_44 -> V_48 , V_49 -> V_140 () ,
& V_139 ) ) {
F_84 ( L_20 ,
F_1 ( V_135 -> V_8 ) , V_135 -> V_142 ) ;
F_119 ( V_13 , V_44 ) ;
return;
}
F_13 ( V_25 , V_91
L_21
L_22 ,
V_135 -> V_8 , F_1 ( V_135 -> V_8 ) , V_135 -> V_142 ,
V_44 -> V_46 , V_13 , V_135 -> V_79 , V_135 -> V_99 , V_139 ) ;
if ( V_81 . V_143 ( V_13 , & V_61 , V_139 , V_44 -> V_46 , V_135 ) ) {
F_84 ( L_23 ,
F_1 ( V_135 -> V_8 ) , V_135 -> V_142 ) ;
F_119 ( V_13 , V_44 ) ;
return;
}
F_111 ( V_13 , V_44 , V_135 -> V_79 ) ;
if ( V_13 < F_7 () )
V_144 -> V_65 ( V_13 ) ;
F_41 ( V_135 -> V_8 , V_135 -> V_142 , V_61 ) ;
}
static void T_2 F_120 ( void )
{
unsigned int V_8 , V_12 ;
int V_38 ;
F_13 ( V_25 , V_91 L_24 ) ;
F_67 (ioapic, pin) {
V_38 = F_75 ( V_8 , V_12 , V_115 ) ;
if ( V_38 < 0 )
F_13 ( V_25 ,
V_91 L_25 ,
F_1 ( V_8 ) , V_12 ) ;
else
F_99 ( V_38 , V_8 , V_12 ,
V_8 ? 0 : V_112 ) ;
}
}
static void T_2 F_121 ( unsigned int V_1 ,
unsigned int V_12 , int V_46 )
{
struct V_41 V_61 ;
unsigned int V_139 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
if ( F_122 ( V_49 -> V_141 ( V_49 -> V_140 () ,
V_49 -> V_140 () , & V_139 ) ) )
V_139 = V_145 ;
V_61 . V_137 = V_49 -> V_138 ;
V_61 . V_65 = 0 ;
V_61 . V_139 = V_139 ;
V_61 . V_83 = V_49 -> V_136 ;
V_61 . V_99 = 0 ;
V_61 . V_79 = 0 ;
V_61 . V_46 = V_46 ;
F_115 ( 0 , & V_126 , V_132 ,
L_19 ) ;
F_41 ( V_1 , V_12 , V_61 ) ;
}
void F_123 ( unsigned int V_49 , unsigned int V_146 )
{
int V_24 ;
F_124 ( L_26 ) ;
for ( V_24 = 0 ; V_24 <= V_146 ; V_24 ++ ) {
struct V_41 V_61 ;
V_61 = F_36 ( V_49 , V_24 ) ;
F_124 ( L_27 , V_24 , V_61 . V_139 ) ;
F_125 ( L_28
L_29 ,
V_61 . V_65 ,
V_61 . V_79 ,
V_61 . V_85 ,
V_61 . V_99 ,
V_61 . V_147 ,
V_61 . V_137 ,
V_61 . V_83 ,
V_61 . V_46 ) ;
}
}
void F_126 ( unsigned int V_49 ,
unsigned int V_146 )
{
int V_24 ;
F_124 ( L_30 ) ;
for ( V_24 = 0 ; V_24 <= V_146 ; V_24 ++ ) {
struct V_148 * V_149 ;
struct V_41 V_61 ;
V_61 = F_36 ( V_49 , V_24 ) ;
V_149 = (struct V_148 * ) & V_61 ;
F_124 ( L_31 , V_24 , V_149 -> V_53 ) ;
F_125 ( L_32
L_33 ,
V_149 -> V_150 ,
V_149 -> V_65 ,
V_149 -> V_79 ,
V_149 -> V_85 ,
V_149 -> V_99 ,
V_149 -> V_147 ,
V_149 -> V_151 ,
V_149 -> V_152 ,
V_149 -> V_46 ) ;
}
}
void F_127 ( void )
{
F_128 ( & V_63 ) ;
}
static void T_2 F_129 ( int V_1 )
{
union V_153 V_154 ;
union V_155 V_156 ;
union V_157 V_158 ;
union V_159 V_160 ;
unsigned long V_62 ;
F_37 ( & V_63 , V_62 ) ;
V_154 . V_161 = F_35 ( V_1 , 0 ) ;
V_156 . V_161 = F_35 ( V_1 , 1 ) ;
if ( V_156 . V_162 . V_163 >= 0x10 )
V_158 . V_161 = F_35 ( V_1 , 2 ) ;
if ( V_156 . V_162 . V_163 >= 0x20 )
V_160 . V_161 = F_35 ( V_1 , 3 ) ;
F_38 ( & V_63 , V_62 ) ;
F_130 ( V_91 L_34 , F_1 ( V_1 ) ) ;
F_130 ( V_91 L_35 , V_154 . V_161 ) ;
F_130 ( V_91 L_36 , V_154 . V_162 . V_164 ) ;
F_130 ( V_91 L_37 , V_154 . V_162 . V_165 ) ;
F_130 ( V_91 L_38 , V_154 . V_162 . V_166 ) ;
F_130 ( V_91 L_39 , * ( int * ) & V_156 ) ;
F_130 ( V_91 L_40 ,
V_156 . V_162 . V_167 ) ;
F_130 ( V_91 L_41 , V_156 . V_162 . V_168 ) ;
F_130 ( V_91 L_42 ,
V_156 . V_162 . V_163 ) ;
if ( V_156 . V_162 . V_163 >= 0x10 && V_158 . V_161 != V_156 . V_161 ) {
F_130 ( V_91 L_43 , V_158 . V_161 ) ;
F_130 ( V_91 L_44 , V_158 . V_162 . V_169 ) ;
}
if ( V_156 . V_162 . V_163 >= 0x20 && V_160 . V_161 != V_158 . V_161 &&
V_160 . V_161 != V_156 . V_161 ) {
F_130 ( V_91 L_45 , V_160 . V_161 ) ;
F_130 ( V_91 L_46 , V_160 . V_162 . V_170 ) ;
}
F_130 ( V_91 L_47 ) ;
V_81 . V_171 ( V_1 , V_156 . V_162 . V_167 ) ;
}
void T_2 F_131 ( void )
{
int V_1 ;
struct V_43 * V_44 ;
unsigned int V_13 ;
struct V_124 * V_125 ;
F_130 ( V_91 L_48 , V_32 ) ;
F_24 (ioapic_idx)
F_130 ( V_91 L_49 ,
F_1 ( V_1 ) ,
V_2 [ V_1 ] . V_42 ) ;
F_130 ( V_90 L_50 ) ;
F_24 (ioapic_idx)
F_129 ( V_1 ) ;
F_130 ( V_91 L_51 ) ;
F_132 (irq) {
struct V_35 * V_61 ;
V_125 = F_133 ( V_13 ) ;
if ( V_125 != & V_126 )
continue;
V_44 = V_43 ( V_13 ) ;
if ( ! V_44 )
continue;
if ( F_134 ( & V_44 -> V_68 ) )
continue;
F_130 ( V_91 L_52 , V_13 ) ;
F_44 (entry, cfg->irq_2_pin)
F_125 ( L_53 , V_61 -> V_49 , V_61 -> V_12 ) ;
F_125 ( L_54 ) ;
}
F_130 ( V_90 L_55 ) ;
}
void T_2 F_135 ( void )
{
int V_172 , V_173 ;
int V_49 , V_12 ;
if ( V_20 )
V_174 = 0 ;
if ( ! F_7 () || ! V_174 )
return;
F_67 (apic, pin) {
struct V_41 V_61 = F_36 ( V_49 , V_12 ) ;
if ( ( V_61 . V_65 == 0 ) && ( V_61 . V_83 == V_175 ) ) {
V_176 . V_49 = V_49 ;
V_176 . V_12 = V_12 ;
goto V_177;
}
}
V_177:
V_173 = F_76 ( 0 , V_178 ) ;
V_172 = F_78 ( 0 , V_178 ) ;
if ( ( V_176 . V_12 == - 1 ) && ( V_173 >= 0 ) ) {
F_130 ( V_179 L_56 ) ;
V_176 . V_12 = V_173 ;
V_176 . V_49 = V_172 ;
}
if ( ( ( V_176 . V_49 != V_172 ) || ( V_176 . V_12 != V_173 ) ) &&
( V_173 >= 0 ) && ( V_176 . V_12 >= 0 ) )
{
F_130 ( V_179 L_57 ) ;
}
F_66 () ;
}
void F_136 ( void )
{
if ( V_176 . V_12 != - 1 ) {
struct V_41 V_61 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_65 = 0 ;
V_61 . V_79 = 0 ;
V_61 . V_85 = 0 ;
V_61 . V_99 = 0 ;
V_61 . V_147 = 0 ;
V_61 . V_137 = 0 ;
V_61 . V_83 = V_175 ;
V_61 . V_46 = 0 ;
V_61 . V_139 = F_137 () ;
F_41 ( V_176 . V_49 , V_176 . V_12 , V_61 ) ;
}
if ( V_180 || F_138 () )
F_139 ( V_176 . V_12 != - 1 ) ;
}
void F_140 ( void )
{
F_66 () ;
if ( ! F_7 () )
return;
V_81 . V_181 () ;
}
void T_2 F_141 ( void )
{
union V_153 V_154 ;
T_6 V_182 ;
int V_1 ;
int V_24 ;
unsigned char V_183 ;
unsigned long V_62 ;
V_49 -> V_184 ( & V_185 , & V_182 ) ;
F_24 (ioapic_idx) {
F_37 ( & V_63 , V_62 ) ;
V_154 . V_161 = F_35 ( V_1 , 0 ) ;
F_38 ( & V_63 , V_62 ) ;
V_183 = F_1 ( V_1 ) ;
if ( F_1 ( V_1 ) >= F_142 () ) {
F_130 ( V_186 L_58 ,
V_1 , F_1 ( V_1 ) ) ;
F_130 ( V_186 L_59 ,
V_154 . V_162 . V_164 ) ;
V_2 [ V_1 ] . V_3 . V_4 = V_154 . V_162 . V_164 ;
}
if ( V_49 -> V_187 ( & V_182 ,
F_1 ( V_1 ) ) ) {
F_130 ( V_186 L_60 ,
V_1 , F_1 ( V_1 ) ) ;
for ( V_24 = 0 ; V_24 < F_142 () ; V_24 ++ )
if ( ! F_143 ( V_24 , V_182 ) )
break;
if ( V_24 >= F_142 () )
F_14 ( L_61 ) ;
F_130 ( V_186 L_59 ,
V_24 ) ;
F_144 ( V_24 , V_182 ) ;
V_2 [ V_1 ] . V_3 . V_4 = V_24 ;
} else {
T_6 V_69 ;
V_49 -> V_188 ( F_1 ( V_1 ) ,
& V_69 ) ;
F_13 ( V_25 , L_62
L_63 ,
F_1 ( V_1 ) ) ;
F_145 ( V_182 , V_182 , V_69 ) ;
}
if ( V_183 != F_1 ( V_1 ) )
for ( V_24 = 0 ; V_24 < V_32 ; V_24 ++ )
if ( V_33 [ V_24 ] . V_30 == V_183 )
V_33 [ V_24 ] . V_30
= F_1 ( V_1 ) ;
if ( F_1 ( V_1 ) == V_154 . V_162 . V_164 )
continue;
F_13 ( V_25 , V_90
L_64 ,
F_1 ( V_1 ) ) ;
V_154 . V_162 . V_164 = F_1 ( V_1 ) ;
F_37 ( & V_63 , V_62 ) ;
F_40 ( V_1 , 0 , V_154 . V_161 ) ;
F_38 ( & V_63 , V_62 ) ;
F_37 ( & V_63 , V_62 ) ;
V_154 . V_161 = F_35 ( V_1 , 0 ) ;
F_38 ( & V_63 , V_62 ) ;
if ( V_154 . V_162 . V_164 != F_1 ( V_1 ) )
F_125 ( L_65 ) ;
else
F_13 ( V_25 , L_66 ) ;
}
}
void T_2 F_146 ( void )
{
if ( V_189 )
return;
if ( ! ( V_190 . V_191 == V_192 )
|| F_147 ( V_193 [ V_194 ] ) )
return;
F_141 () ;
}
static int T_2 F_148 ( char * V_195 )
{
V_196 = 1 ;
return 1 ;
}
static int T_2 F_149 ( void )
{
unsigned long V_197 = V_198 ;
unsigned long V_62 ;
if ( V_196 )
return 1 ;
F_150 ( V_62 ) ;
F_151 () ;
F_152 ( ( 10 * 1000 ) / V_199 ) ;
F_153 ( V_62 ) ;
if ( F_154 ( V_198 , V_197 + 4 ) )
return 1 ;
return 0 ;
}
static unsigned int F_155 ( struct V_77 * V_54 )
{
int V_200 = 0 , V_13 = V_54 -> V_13 ;
unsigned long V_62 ;
F_37 ( & V_63 , V_62 ) ;
if ( V_13 < F_7 () ) {
V_144 -> V_65 ( V_13 ) ;
if ( V_144 -> V_201 ( V_13 ) )
V_200 = 1 ;
}
F_59 ( F_58 ( V_54 ) ) ;
F_38 ( & V_63 , V_62 ) ;
return V_200 ;
}
static void F_156 ( unsigned int V_13 , unsigned int V_139 , struct V_43 * V_44 )
{
int V_49 , V_12 ;
struct V_35 * V_61 ;
T_7 V_46 = V_44 -> V_46 ;
F_44 (entry, cfg->irq_2_pin) {
unsigned int V_52 ;
V_49 = V_61 -> V_49 ;
V_12 = V_61 -> V_12 ;
F_40 ( V_49 , 0x11 + V_12 * 2 , V_139 ) ;
V_52 = F_35 ( V_49 , 0x10 + V_12 * 2 ) ;
V_52 &= ~ V_202 ;
V_52 |= V_46 ;
F_53 ( V_49 , 0x10 + V_12 * 2 , V_52 ) ;
}
}
int F_157 ( struct V_77 * V_54 ,
const struct V_203 * V_65 ,
bool V_204 )
{
unsigned int V_139 , V_13 = V_54 -> V_13 ;
unsigned long V_62 ;
int V_205 ;
if ( ! F_158 ( V_206 ) )
return - V_207 ;
F_37 ( & V_63 , V_62 ) ;
V_205 = F_159 ( V_54 , V_65 , & V_139 ) ;
if ( ! V_205 ) {
V_139 = F_160 ( V_139 ) ;
F_156 ( V_13 , V_139 , F_58 ( V_54 ) ) ;
V_205 = V_208 ;
}
F_38 ( & V_63 , V_62 ) ;
return V_205 ;
}
static bool F_161 ( struct V_43 * V_44 )
{
struct V_35 * V_61 ;
unsigned long V_62 ;
F_37 ( & V_63 , V_62 ) ;
F_44 (entry, cfg->irq_2_pin) {
unsigned int V_52 ;
int V_12 ;
V_12 = V_61 -> V_12 ;
V_52 = F_35 ( V_61 -> V_49 , 0x10 + V_12 * 2 ) ;
if ( V_52 & V_209 ) {
F_38 ( & V_63 , V_62 ) ;
return true ;
}
}
F_38 ( & V_63 , V_62 ) ;
return false ;
}
static inline bool F_162 ( struct V_77 * V_54 , struct V_43 * V_44 )
{
if ( F_122 ( F_163 ( V_54 ) ) ) {
F_56 ( V_44 ) ;
return true ;
}
return false ;
}
static inline void F_164 ( struct V_77 * V_54 ,
struct V_43 * V_44 , bool V_210 )
{
if ( F_122 ( V_210 ) ) {
if ( ! F_161 ( V_44 ) )
F_165 ( V_54 ) ;
F_60 ( V_44 ) ;
}
}
static inline bool F_162 ( struct V_77 * V_54 , struct V_43 * V_44 )
{
return false ;
}
static inline void F_164 ( struct V_77 * V_54 ,
struct V_43 * V_44 , bool V_210 )
{
}
static void F_166 ( struct V_77 * V_54 )
{
struct V_43 * V_44 = F_58 ( V_54 ) ;
int V_24 , V_13 = V_54 -> V_13 ;
unsigned long V_211 ;
bool V_210 ;
F_167 ( V_44 ) ;
V_210 = F_162 ( V_54 , V_44 ) ;
V_24 = V_44 -> V_46 ;
V_211 = F_168 ( V_212 + ( ( V_24 & ~ 0x1f ) >> 1 ) ) ;
F_169 () ;
if ( ! ( V_211 & ( 1 << ( V_24 & 0x1f ) ) ) ) {
F_170 ( & V_213 ) ;
F_64 ( V_13 , V_44 ) ;
}
F_164 ( V_54 , V_44 , V_210 ) ;
}
static inline void F_171 ( void )
{
struct V_43 * V_44 ;
unsigned int V_13 ;
F_132 (irq) {
V_44 = V_43 ( V_13 ) ;
if ( F_109 ( V_13 ) && V_44 && ! V_44 -> V_46 ) {
if ( V_13 < F_7 () )
V_144 -> V_214 ( V_13 ) ;
else
F_172 ( V_13 , & V_215 ) ;
}
}
}
static void F_173 ( struct V_77 * V_54 )
{
unsigned long V_211 ;
V_211 = F_168 ( V_216 ) ;
F_174 ( V_216 , V_211 | V_217 ) ;
}
static void F_175 ( struct V_77 * V_54 )
{
unsigned long V_211 ;
V_211 = F_168 ( V_216 ) ;
F_174 ( V_216 , V_211 & ~ V_217 ) ;
}
static void F_176 ( struct V_77 * V_54 )
{
F_169 () ;
}
static void F_177 ( int V_13 )
{
F_113 ( V_13 , V_130 ) ;
F_115 ( V_13 , & V_218 , V_132 ,
L_19 ) ;
}
static inline void T_2 F_178 ( void )
{
int V_49 , V_12 , V_24 ;
struct V_41 V_219 , V_78 ;
unsigned char V_220 , V_221 ;
V_12 = F_76 ( 8 , V_115 ) ;
if ( V_12 == - 1 ) {
F_179 ( 1 ) ;
return;
}
V_49 = F_78 ( 8 , V_115 ) ;
if ( V_49 == - 1 ) {
F_179 ( 1 ) ;
return;
}
V_219 = F_36 ( V_49 , V_12 ) ;
F_65 ( V_49 , V_12 ) ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . V_137 = 0 ;
V_78 . V_65 = 0 ;
V_78 . V_139 = F_180 () ;
V_78 . V_83 = V_175 ;
V_78 . V_99 = V_219 . V_99 ;
V_78 . V_79 = 0 ;
V_78 . V_46 = 0 ;
F_41 ( V_49 , V_12 , V_78 ) ;
V_220 = F_181 ( V_222 ) ;
V_221 = F_181 ( V_223 ) ;
F_182 ( ( V_221 & ~ V_224 ) | 0x6 ,
V_223 ) ;
F_182 ( V_220 | V_225 , V_222 ) ;
V_24 = 100 ;
while ( V_24 -- > 0 ) {
F_152 ( 10 ) ;
if ( ( F_181 ( V_226 ) & V_227 ) == V_227 )
V_24 -= 10 ;
}
F_182 ( V_220 , V_222 ) ;
F_182 ( V_221 , V_223 ) ;
F_65 ( V_49 , V_12 ) ;
F_41 ( V_49 , V_12 , V_219 ) ;
}
static int T_2 F_183 ( char * V_228 )
{
V_229 = 1 ;
return 0 ;
}
static inline void T_2 F_184 ( void )
{
struct V_43 * V_44 = V_43 ( 0 ) ;
int V_36 = F_23 ( 0 ) ;
int V_230 , V_231 , V_232 , V_233 ;
unsigned long V_62 ;
int V_234 = 0 ;
F_185 ( V_62 ) ;
V_144 -> V_65 ( 0 ) ;
F_118 ( 0 , V_44 , V_49 -> V_140 () ) ;
F_174 ( V_216 , V_217 | V_235 ) ;
V_144 -> V_236 ( 1 ) ;
V_231 = F_76 ( 0 , V_115 ) ;
V_230 = F_78 ( 0 , V_115 ) ;
V_233 = V_176 . V_12 ;
V_232 = V_176 . V_49 ;
F_13 ( V_237 , V_90 L_67
L_68 ,
V_44 -> V_46 , V_230 , V_231 , V_232 , V_233 ) ;
if ( V_231 == - 1 ) {
F_186 ( L_69 ) ;
V_231 = V_233 ;
V_230 = V_232 ;
V_234 = 1 ;
} else if ( V_233 == - 1 ) {
V_233 = V_231 ;
V_232 = V_230 ;
}
if ( V_231 != - 1 ) {
if ( V_234 ) {
F_49 ( V_44 , V_36 , V_230 , V_231 ) ;
F_121 ( V_230 , V_231 , V_44 -> V_46 ) ;
} else {
int V_38 ;
V_38 = F_75 ( V_230 , V_231 , V_115 ) ;
if ( V_38 != - 1 && F_85 ( V_38 ) )
F_60 ( V_44 ) ;
}
if ( F_149 () ) {
if ( V_229 > 0 )
F_65 ( 0 , V_231 ) ;
goto V_123;
}
F_186 ( L_70 ) ;
F_187 () ;
F_65 ( V_230 , V_231 ) ;
if ( ! V_234 )
F_13 ( V_237 , V_186 L_71
L_72 ) ;
F_13 ( V_237 , V_90 L_73
L_74 ) ;
F_13 ( V_237 , V_90
L_75 , V_232 , V_233 ) ;
F_50 ( V_44 , V_36 , V_230 , V_231 , V_232 , V_233 ) ;
F_121 ( V_232 , V_233 , V_44 -> V_46 ) ;
V_144 -> V_238 ( 0 ) ;
if ( F_149 () ) {
F_13 ( V_237 , V_90 L_76 ) ;
goto V_123;
}
F_187 () ;
V_144 -> V_65 ( 0 ) ;
F_65 ( V_232 , V_233 ) ;
F_13 ( V_237 , V_90 L_77 ) ;
}
F_13 ( V_237 , V_90
L_78 ) ;
F_177 ( 0 ) ;
F_174 ( V_216 , V_239 | V_44 -> V_46 ) ;
V_144 -> V_238 ( 0 ) ;
if ( F_149 () ) {
F_13 ( V_237 , V_90 L_79 ) ;
goto V_123;
}
F_187 () ;
V_144 -> V_65 ( 0 ) ;
F_174 ( V_216 , V_217 | V_239 | V_44 -> V_46 ) ;
F_13 ( V_237 , V_90 L_80 ) ;
F_13 ( V_237 , V_90
L_81 ) ;
V_144 -> V_236 ( 0 ) ;
V_144 -> V_214 ( 0 ) ;
F_174 ( V_216 , V_235 ) ;
F_178 () ;
if ( F_149 () ) {
F_13 ( V_237 , V_90 L_79 ) ;
goto V_123;
}
F_187 () ;
F_13 ( V_237 , V_90 L_82 ) ;
if ( F_188 () )
F_13 ( V_237 , V_90
L_83
L_84 ) ;
F_14 ( L_85
L_86 ) ;
V_123:
F_153 ( V_62 ) ;
}
static int F_189 ( int V_8 )
{
T_3 V_39 ;
int V_240 = F_4 ( V_8 ) ;
struct V_8 * V_241 = & V_2 [ V_8 ] ;
struct V_242 * V_44 = & V_241 -> V_106 ;
struct V_6 * V_9 = F_3 ( V_8 ) ;
V_39 = sizeof( struct V_14 ) * F_4 ( V_8 ) ;
V_241 -> V_15 = F_18 ( V_39 , V_37 ) ;
if ( ! V_241 -> V_15 )
return - V_66 ;
if ( V_44 -> type == V_243 )
return 0 ;
V_241 -> V_17 = F_190 ( V_44 -> V_244 , V_240 , V_44 -> V_245 ,
( void * ) ( long ) V_8 ) ;
if( ! V_241 -> V_17 ) {
F_21 ( V_241 -> V_15 ) ;
V_241 -> V_15 = NULL ;
return - V_66 ;
}
if ( V_44 -> type == V_107 ||
V_44 -> type == V_108 )
V_246 = V_87 ( V_246 ,
V_9 -> V_10 + 1 ) ;
if ( V_9 -> V_11 == 0 )
F_191 ( V_241 -> V_17 ) ;
return 0 ;
}
static void F_192 ( int V_38 )
{
if ( V_2 [ V_38 ] . V_17 ) {
F_193 ( V_2 [ V_38 ] . V_17 ) ;
V_2 [ V_38 ] . V_17 = NULL ;
}
F_21 ( V_2 [ V_38 ] . V_15 ) ;
V_2 [ V_38 ] . V_15 = NULL ;
}
void T_2 F_194 ( void )
{
int V_8 ;
if ( V_20 || ! V_174 )
return;
V_45 = F_7 () ? ~ V_247 : ~ 0UL ;
F_13 ( V_25 , L_87 ) ;
F_24 (ioapic)
F_195 ( F_189 ( V_8 ) ) ;
V_248 . V_249 . V_250 () ;
F_196 () ;
F_120 () ;
F_171 () ;
if ( F_7 () )
F_184 () ;
V_251 = 1 ;
}
static int T_2 F_197 ( void )
{
if ( V_56 == - 1 )
V_56 = 0 ;
return 0 ;
}
static void F_198 ( int V_1 )
{
unsigned long V_62 ;
union V_153 V_154 ;
F_37 ( & V_63 , V_62 ) ;
V_154 . V_161 = F_35 ( V_1 , 0 ) ;
if ( V_154 . V_162 . V_164 != F_1 ( V_1 ) ) {
V_154 . V_162 . V_164 = F_1 ( V_1 ) ;
F_40 ( V_1 , 0 , V_154 . V_161 ) ;
}
F_38 ( & V_63 , V_62 ) ;
}
static void F_199 ( void )
{
int V_1 ;
F_200 (ioapic_idx)
F_198 ( V_1 ) ;
F_74 () ;
}
static int T_2 F_201 ( void )
{
F_202 ( & V_252 ) ;
return 0 ;
}
static int
F_203 ( unsigned int V_13 , int V_36 , struct V_134 * V_135 )
{
struct V_43 * V_44 = F_25 ( V_13 , V_36 ) ;
int V_205 ;
if ( ! V_44 )
return - V_253 ;
V_205 = F_43 ( V_44 , V_36 , V_135 -> V_8 , V_135 -> V_142 ) ;
if ( ! V_205 )
F_117 ( V_13 , V_44 , V_135 ) ;
return V_205 ;
}
static int F_204 ( int V_8 )
{
union V_155 V_156 ;
unsigned long V_62 ;
F_37 ( & V_63 , V_62 ) ;
V_156 . V_161 = F_35 ( V_8 , 1 ) ;
F_38 ( & V_63 , V_62 ) ;
return V_156 . V_162 . V_167 + 1 ;
}
unsigned int F_205 ( unsigned int V_254 )
{
return V_251 ? V_246 : V_255 ;
}
static int F_206 ( int V_8 , int V_256 )
{
union V_153 V_154 ;
static T_6 V_257 = V_258 ;
T_6 V_69 ;
unsigned long V_62 ;
int V_24 = 0 ;
if ( F_207 ( V_257 ) )
V_49 -> V_184 ( & V_185 , & V_257 ) ;
F_37 ( & V_63 , V_62 ) ;
V_154 . V_161 = F_35 ( V_8 , 0 ) ;
F_38 ( & V_63 , V_62 ) ;
if ( V_256 >= F_142 () ) {
F_130 ( V_179 L_88
L_89 , V_8 , V_256 , V_154 . V_162 . V_164 ) ;
V_256 = V_154 . V_162 . V_164 ;
}
if ( V_49 -> V_187 ( & V_257 , V_256 ) ) {
for ( V_24 = 0 ; V_24 < F_142 () ; V_24 ++ ) {
if ( ! V_49 -> V_187 ( & V_257 , V_24 ) )
break;
}
if ( V_24 == F_142 () )
F_14 ( L_90 ) ;
F_130 ( V_179 L_91
L_92 , V_8 , V_256 , V_24 ) ;
V_256 = V_24 ;
}
V_49 -> V_188 ( V_256 , & V_69 ) ;
F_145 ( V_257 , V_257 , V_69 ) ;
if ( V_154 . V_162 . V_164 != V_256 ) {
V_154 . V_162 . V_164 = V_256 ;
F_37 ( & V_63 , V_62 ) ;
F_40 ( V_8 , 0 , V_154 . V_161 ) ;
V_154 . V_161 = F_35 ( V_8 , 0 ) ;
F_38 ( & V_63 , V_62 ) ;
if ( V_154 . V_162 . V_164 != V_256 ) {
F_19 ( L_93 ,
V_8 ) ;
return - 1 ;
}
}
F_13 ( V_25 , V_90
L_94 , V_8 , V_256 ) ;
return V_256 ;
}
static T_7 F_208 ( int V_38 , T_7 V_259 )
{
if ( ( V_190 . V_191 == V_192 ) &&
! F_147 ( V_193 [ V_194 ] ) )
return F_206 ( V_38 , V_259 ) ;
else
return V_259 ;
}
static T_7 F_208 ( int V_38 , T_7 V_259 )
{
union V_153 V_154 ;
F_209 ( V_260 , 256 ) ;
unsigned long V_62 ;
T_7 V_261 ;
int V_24 ;
F_210 ( V_260 , 256 ) ;
F_24 (i)
F_211 ( F_1 ( V_24 ) , V_260 ) ;
if ( ! F_77 ( V_259 , V_260 ) )
return V_259 ;
F_37 ( & V_63 , V_62 ) ;
V_154 . V_161 = F_35 ( V_38 , 0 ) ;
F_38 ( & V_63 , V_62 ) ;
V_261 = V_154 . V_162 . V_164 ;
if ( ! F_77 ( V_261 , V_260 ) ) {
F_13 ( V_25 , V_90
L_95 ,
V_38 , V_261 , V_259 ) ;
return V_261 ;
}
V_261 = F_212 ( V_260 , 256 ) ;
V_154 . V_162 . V_164 = V_261 ;
F_37 ( & V_63 , V_62 ) ;
F_40 ( V_38 , 0 , V_154 . V_161 ) ;
V_154 . V_161 = F_35 ( V_38 , 0 ) ;
F_38 ( & V_63 , V_62 ) ;
F_195 ( V_154 . V_162 . V_164 != V_261 ) ;
return V_261 ;
}
static int F_213 ( int V_8 )
{
union V_155 V_156 ;
unsigned long V_62 ;
F_37 ( & V_63 , V_62 ) ;
V_156 . V_161 = F_35 ( V_8 , 1 ) ;
F_38 ( & V_63 , V_62 ) ;
return V_156 . V_162 . V_163 ;
}
int F_214 ( T_1 V_104 , int * V_79 , int * V_99 )
{
int V_8 , V_12 , V_38 ;
if ( V_20 )
return - 1 ;
V_8 = F_102 ( V_104 ) ;
if ( V_8 < 0 )
return - 1 ;
V_12 = F_103 ( V_8 , V_104 ) ;
if ( V_12 < 0 )
return - 1 ;
V_38 = F_75 ( V_8 , V_12 , V_115 ) ;
if ( V_38 < 0 )
return - 1 ;
* V_79 = F_85 ( V_38 ) ;
* V_99 = F_81 ( V_38 ) ;
return 0 ;
}
void T_2 F_215 ( void )
{
int V_12 , V_8 , V_13 , V_262 ;
const struct V_203 * V_65 ;
struct V_77 * V_263 ;
if ( V_20 == 1 )
return;
F_67 (ioapic, pin) {
V_262 = F_75 ( V_8 , V_12 , V_115 ) ;
if ( V_262 == - 1 )
continue;
V_13 = F_99 ( V_262 , V_8 , V_12 , 0 ) ;
if ( V_13 < 0 || ! F_6 ( V_8 , V_13 ) )
continue;
V_263 = F_105 ( V_13 ) ;
if ( ! F_216 ( V_263 ) || F_217 ( V_263 ) )
V_65 = V_263 -> V_264 ;
else
V_65 = V_49 -> V_140 () ;
V_81 . V_265 ( V_263 , V_65 , false ) ;
}
}
static struct V_266 * T_2 F_218 ( void )
{
unsigned long V_267 ;
struct V_266 * V_268 ;
char * V_269 ;
int V_24 , V_270 = 0 ;
F_24 (i)
V_270 ++ ;
if ( V_270 == 0 )
return NULL ;
V_267 = V_271 + sizeof( struct V_266 ) ;
V_267 *= V_270 ;
V_269 = F_219 ( V_267 ) ;
V_268 = ( void * ) V_269 ;
V_269 += sizeof( struct V_266 ) * V_270 ;
V_270 = 0 ;
F_24 (i) {
V_268 [ V_270 ] . V_272 = V_269 ;
V_268 [ V_270 ] . V_62 = V_273 | V_274 ;
snprintf ( V_269 , V_271 , L_96 , V_24 ) ;
V_269 += V_271 ;
V_270 ++ ;
V_2 [ V_24 ] . V_275 = V_268 ;
}
V_276 = V_268 ;
return V_268 ;
}
void T_2 F_220 ( void )
{
unsigned long V_277 , V_38 = V_278 ;
struct V_266 * V_279 ;
int V_24 ;
V_279 = F_218 () ;
F_24 (i) {
if ( V_280 ) {
V_277 = F_2 ( V_24 ) ;
#ifdef F_100
if ( ! V_277 ) {
F_130 ( V_186
L_97
L_98
L_99 ) ;
V_280 = 0 ;
V_20 = 1 ;
goto V_281;
}
#endif
} else {
#ifdef F_100
V_281:
#endif
V_277 = ( unsigned long ) F_221 ( V_282 ) ;
V_277 = F_222 ( V_277 ) ;
}
F_223 ( V_38 , V_277 ) ;
F_13 ( V_25 , L_100 ,
F_224 ( V_38 ) + ( V_277 & ~ V_283 ) ,
V_277 ) ;
V_38 ++ ;
V_279 -> V_284 = V_277 ;
V_279 -> V_285 = V_277 + V_286 - 1 ;
V_279 ++ ;
}
}
void T_2 F_225 ( void )
{
int V_24 ;
struct V_266 * V_287 = V_276 ;
if ( ! V_287 ) {
if ( V_174 > 0 )
F_130 ( V_186
L_101 ) ;
return;
}
F_24 (i) {
F_226 ( & V_288 , V_287 ) ;
V_287 ++ ;
}
}
int F_102 ( T_1 V_104 )
{
int V_24 ;
if ( V_174 == 0 )
return - 1 ;
F_24 (i) {
struct V_6 * V_9 = F_3 ( V_24 ) ;
if ( V_104 >= V_9 -> V_11 && V_104 <= V_9 -> V_10 )
return V_24 ;
}
F_130 ( V_186 L_102 , V_104 ) ;
return - 1 ;
}
int F_103 ( int V_8 , T_1 V_104 )
{
struct V_6 * V_9 ;
if ( F_227 ( V_8 < 0 ) )
return - 1 ;
V_9 = F_3 ( V_8 ) ;
if ( F_227 ( V_104 > V_9 -> V_10 ) )
return - 1 ;
return V_104 - V_9 -> V_11 ;
}
static int F_228 ( int V_38 )
{
union V_153 V_154 ;
union V_155 V_156 ;
union V_157 V_158 ;
V_154 . V_161 = F_35 ( V_38 , 0 ) ;
V_156 . V_161 = F_35 ( V_38 , 1 ) ;
V_158 . V_161 = F_35 ( V_38 , 2 ) ;
if ( V_154 . V_161 == - 1 && V_156 . V_161 == - 1 && V_158 . V_161 == - 1 ) {
F_84 ( L_103 ,
F_2 ( V_38 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_229 ( void )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_289 ; V_38 ++ )
if ( V_2 [ V_38 ] . V_42 == 0 )
return V_38 ;
return V_289 ;
}
int F_230 ( int V_259 , T_1 V_290 , T_1 V_11 ,
struct V_242 * V_44 )
{
bool V_291 = ! ! V_251 ;
struct V_6 * V_9 ;
int V_38 , V_8 , V_167 ;
T_1 V_10 ;
if ( ! V_290 ) {
F_84 ( L_104 ) ;
return - V_253 ;
}
F_24 (ioapic)
if ( V_2 [ V_8 ] . V_3 . V_5 == V_290 ) {
F_84 ( L_105 ,
V_290 , V_8 ) ;
return - V_292 ;
}
V_38 = F_229 () ;
if ( V_38 >= V_289 ) {
F_84 ( L_106 ,
V_289 , V_38 ) ;
return - V_293 ;
}
V_2 [ V_38 ] . V_3 . type = V_294 ;
V_2 [ V_38 ] . V_3 . V_62 = V_295 ;
V_2 [ V_38 ] . V_3 . V_5 = V_290 ;
F_223 ( V_278 + V_38 , V_290 ) ;
if ( F_228 ( V_38 ) ) {
F_231 ( V_278 + V_38 ) ;
return - V_296 ;
}
V_2 [ V_38 ] . V_3 . V_4 = F_208 ( V_38 , V_259 ) ;
V_2 [ V_38 ] . V_3 . V_297 = F_213 ( V_38 ) ;
V_167 = F_204 ( V_38 ) ;
V_10 = V_11 + V_167 - 1 ;
F_24 (ioapic) {
V_9 = F_3 ( V_8 ) ;
if ( ( V_11 >= V_9 -> V_11 &&
V_11 <= V_9 -> V_10 ) ||
( V_10 >= V_9 -> V_11 &&
V_10 <= V_9 -> V_10 ) ) {
F_84 ( L_107 ,
V_11 , V_10 ,
V_9 -> V_11 , V_9 -> V_10 ) ;
F_231 ( V_278 + V_38 ) ;
return - V_293 ;
}
}
V_9 = F_3 ( V_38 ) ;
V_9 -> V_11 = V_11 ;
V_9 -> V_10 = V_10 ;
V_2 [ V_38 ] . V_17 = NULL ;
V_2 [ V_38 ] . V_106 = * V_44 ;
if ( V_291 ) {
if ( F_189 ( V_38 ) ) {
F_231 ( V_278 + V_38 ) ;
return - V_66 ;
}
F_17 ( V_38 ) ;
}
if ( V_9 -> V_10 >= V_255 )
V_255 = V_9 -> V_10 + 1 ;
if ( V_174 <= V_38 )
V_174 = V_38 + 1 ;
V_2 [ V_38 ] . V_42 = V_167 ;
F_232 ( L_108 ,
V_38 , F_1 ( V_38 ) ,
F_63 ( V_38 ) , F_2 ( V_38 ) ,
V_9 -> V_11 , V_9 -> V_10 ) ;
return 0 ;
}
int F_233 ( T_1 V_11 )
{
int V_8 , V_12 ;
int V_122 = 0 ;
struct V_14 * V_15 ;
F_24 (ioapic)
if ( V_2 [ V_8 ] . V_7 . V_11 == V_11 ) {
V_122 = 1 ;
break;
}
if ( ! V_122 ) {
F_84 ( L_109 , V_11 ) ;
return - V_296 ;
}
F_72 (ioapic, pin) {
V_15 = V_14 ( V_8 , V_12 ) ;
if ( V_15 -> V_113 ) {
F_84 ( L_110 ,
V_12 , V_8 ) ;
return - V_298 ;
}
}
V_2 [ V_8 ] . V_42 = 0 ;
F_192 ( V_8 ) ;
F_20 ( V_8 ) ;
if ( V_2 [ V_8 ] . V_275 )
F_234 ( V_2 [ V_8 ] . V_275 ) ;
F_231 ( V_278 + V_8 ) ;
memset ( & V_2 [ V_8 ] , 0 , sizeof( V_2 [ V_8 ] ) ) ;
return 0 ;
}
int F_235 ( T_1 V_11 )
{
int V_8 ;
F_24 (ioapic)
if ( V_2 [ V_8 ] . V_7 . V_11 == V_11 )
return 1 ;
return 0 ;
}
static inline void F_236 ( struct V_134 * V_299 ,
int V_8 , int V_142 ,
int V_79 , int V_99 )
{
V_299 -> V_8 = V_8 ;
V_299 -> V_142 = V_142 ;
V_299 -> V_79 = V_79 ;
V_299 -> V_99 = V_99 ;
}
int F_96 ( struct V_16 * V_48 , unsigned int V_300 ,
T_8 V_117 )
{
int V_8 = ( int ) ( long ) V_48 -> V_105 ;
struct V_14 * V_110 = V_14 ( V_8 , V_117 ) ;
struct V_134 V_135 ;
if ( ! V_110 -> V_114 ) {
T_1 V_104 = F_5 ( V_8 , V_117 ) ;
if ( F_214 ( V_104 , & V_110 -> V_79 ,
& V_110 -> V_99 ) < 0 ) {
V_110 -> V_79 = 1 ;
V_110 -> V_99 = 1 ;
}
V_110 -> V_36 = V_301 ;
if ( V_300 >= F_7 () || V_110 -> V_113 )
V_110 -> V_114 = 1 ;
}
F_236 ( & V_135 , V_8 , V_117 , V_110 -> V_79 ,
V_110 -> V_99 ) ;
return F_203 ( V_300 , V_110 -> V_36 , & V_135 ) ;
}
void F_106 ( struct V_16 * V_48 , unsigned int V_300 )
{
struct V_77 * V_54 = F_105 ( V_300 ) ;
struct V_43 * V_44 = V_43 ( V_300 ) ;
int V_8 = ( int ) ( long ) V_48 -> V_105 ;
int V_12 = ( int ) V_54 -> V_117 ;
F_42 ( V_8 , V_12 ) ;
F_46 ( V_44 , V_8 , V_12 ) ;
F_227 ( ! F_134 ( & V_44 -> V_68 ) ) ;
F_237 ( V_300 ) ;
}
int F_238 ( T_1 V_104 , int V_79 , int V_99 , int V_36 )
{
int V_205 = 0 ;
int V_8 , V_12 ;
struct V_14 * V_110 ;
V_8 = F_102 ( V_104 ) ;
if ( V_8 < 0 )
return - V_296 ;
V_12 = F_103 ( V_8 , V_104 ) ;
V_110 = V_14 ( V_8 , V_12 ) ;
V_79 = V_79 ? 1 : 0 ;
V_99 = V_99 ? 1 : 0 ;
F_95 ( & V_111 ) ;
if ( ! V_110 -> V_114 ) {
V_110 -> V_79 = V_79 ;
V_110 -> V_99 = V_99 ;
V_110 -> V_36 = V_36 ;
V_110 -> V_114 = 1 ;
} else if ( V_110 -> V_79 != V_79 || V_110 -> V_99 != V_99 ) {
V_205 = - V_298 ;
}
F_98 ( & V_111 ) ;
return V_205 ;
}
void T_2 F_239 ( void )
{
struct V_134 V_135 = { 0 , 0 , 0 , 0 } ;
F_130 ( V_90 L_111 ) ;
#ifndef V_206
F_240 ( V_194 ,
& V_185 ) ;
#endif
F_241 () ;
F_203 ( 0 , 0 , & V_135 ) ;
F_115 ( 0 , & V_126 , V_132 ,
L_19 ) ;
}
