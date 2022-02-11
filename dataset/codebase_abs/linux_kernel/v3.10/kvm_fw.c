static void F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_1 * V_4 , T_1 * V_5 , T_1 * V_6 ) {
struct V_7 * V_8 ;
if ( V_2 ) {
V_8 = & V_2 -> V_9 . V_10 ;
if ( V_8 -> V_11 == V_12 ) {
* V_3 = V_8 -> V_13 . V_14 . V_3 ;
* V_4 = V_8 -> V_13 . V_14 . V_4 ;
* V_5 = V_8 -> V_13 . V_14 . V_5 ;
* V_6 = V_8 -> V_13 . V_14 . V_6 ;
return ;
}
}
F_2 ( V_15 L_1 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_16 V_17 ) {
struct V_7 * V_8 ;
V_8 = F_4 ( V_2 ) ;
if ( V_8 -> V_11 == V_12 ) {
V_8 -> V_13 . V_14 . V_18 = V_17 ;
return ;
}
F_5 ( V_8 -> V_13 . V_14 . V_18 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_19 V_17 ) {
struct V_7 * V_8 ;
V_8 = F_4 ( V_2 ) ;
if ( V_8 -> V_11 == V_20 ) {
V_8 -> V_13 . V_21 . V_18 = V_17 ;
return ;
}
F_2 ( V_22 L_2 ) ;
}
static void F_7 ( void * V_23 )
{
struct V_24 * args = V_23 ;
long V_25 ;
T_1 V_26 = args -> V_26 ;
V_25 = F_8 ( args -> V_27 , args -> V_28 ,
& V_26 , NULL ) ;
if ( V_25 != 0 )
args -> V_25 = V_25 ;
}
static struct V_16 F_9 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 , V_5 , V_6 ;
struct V_16 V_17 = { 0 , 0 , 0 , 0 } ;
struct V_24 args = { 0 , 0 , 0 , 0 } ;
long V_29 ;
V_3 = V_4 = V_5 = V_6 = 0 ;
F_1 ( V_2 , & V_3 , & V_4 , & V_5 , & V_6 ) ;
if ( V_6 != 0 )
F_2 ( V_30 L_3 , V_2 ) ;
V_5 &= ~ V_31 ;
args . V_27 = V_4 ;
args . V_28 = V_5 ;
F_10 ( F_7 ,
( void * ) & args , 1 ) ;
if ( args . V_25 != 0 )
F_2 ( V_30 L_4
L_5 , args . V_25 ) ;
F_11 ( V_29 ) ;
V_17 . V_25 = F_8 ( V_4 , V_5 , & V_17 . V_32 ,
& V_17 . V_33 ) ;
F_12 ( V_29 ) ;
if ( V_17 . V_25 != 0 )
F_2 ( V_30 L_6
L_7 ,
V_2 , V_17 . V_25 , V_4 , V_5 ) ;
#if 0
if (gr29 == PAL_CACHE_TYPE_COHERENT) {
cpus_setall(vcpu->arch.cache_coherent_map);
cpu_clear(vcpu->cpu, vcpu->arch.cache_coherent_map);
cpus_setall(cpu_cache_coherent_map);
cpu_clear(vcpu->cpu, cpu_cache_coherent_map);
}
#endif
return V_17 ;
}
struct V_16 F_13 ( struct V_1 * V_2 )
{
struct V_16 V_17 ;
F_14 ( V_17 , V_34 , 0 , 0 , 0 ) ;
return V_17 ;
}
static struct V_16 F_15 ( struct V_1 * V_2 )
{
struct V_16 V_17 ;
F_14 ( V_17 , V_35 , 0 , 0 , 0 ) ;
if ( V_17 . V_33 == 0 ) {
V_17 . V_25 = F_16 ( V_36 ,
& V_17 . V_33 ,
& V_17 . V_32 ) ;
V_17 . V_37 = 0 ;
}
return V_17 ;
}
static void F_17 ( struct V_16 * V_17 )
{
struct V_38 * V_39 ;
unsigned long V_40 , V_41 , V_42 ;
V_17 -> V_25 = F_16 ( V_36 ,
& V_40 , & V_41 ) ;
V_39 = (struct V_38 * ) & V_17 -> V_37 ;
V_42 = ( ( V_40 * 3 ) + ( V_43 / 2 ) ) /
V_43 ;
V_39 -> V_44 = 3 ;
V_39 -> V_45 = V_42 ;
}
static struct V_16 F_18 ( struct V_1 * V_2 )
{
struct V_16 V_17 ;
F_14 ( V_17 , V_46 , 0 , 0 , 0 ) ;
if ( V_2 -> V_47 -> V_9 . V_48 )
F_17 ( & V_17 ) ;
return V_17 ;
}
static struct V_16 F_19 ( struct V_1 * V_2 )
{
struct V_16 V_17 ;
F_5 ( V_17 ) ;
return V_17 ;
}
static struct V_16 F_20 ( struct V_1 * V_2 )
{
struct V_16 V_17 ;
F_21 ( V_17 ) ;
return V_17 ;
}
static struct V_16 F_22 ( struct V_1 * V_2 )
{
struct V_16 V_17 = { 0 , 0 , 0 , 0 } ;
long V_49 , V_50 , V_51 , V_52 ;
F_1 ( V_2 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
V_17 . V_25 = F_23 ( & V_17 . V_33 , & V_17 . V_32 ,
& V_17 . V_37 , V_51 ) ;
return V_17 ;
}
static struct V_16 F_24 ( struct V_1 * V_2 )
{
struct V_16 V_17 = { 0 , 0 , 0 , 0 } ;
long V_49 , V_50 , V_51 , V_52 ;
F_1 ( V_2 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
V_17 . V_25 = F_25 ( V_50 , & V_17 . V_32 , & V_17 . V_37 ) ;
return V_17 ;
}
static struct V_16 F_26 ( struct V_1 * V_2 )
{
T_2 V_53 ;
long V_25 ;
unsigned long V_49 , V_50 , V_51 , V_52 , V_54 , V_55 ;
F_1 ( V_2 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
V_25 = F_27 ( V_50 , V_51 , & V_53 ) ;
V_54 = V_53 . V_56 . V_57 ;
V_55 = V_53 . V_58 . V_59 ;
return ( (struct V_16 ) { V_25 , V_54 , V_55 , 0 } ) ;
}
static struct V_16 F_28 ( struct V_1 * V_2 )
{
T_3 V_60 ;
T_4 V_61 ;
struct V_16 V_17 ;
F_14 ( V_17 , V_62 , 0 , 0 , 0 ) ;
if ( ! V_17 . V_25 ) {
V_60 . V_63 = V_17 . V_33 ;
V_60 . V_64 . V_65 = 8 ;
V_60 . V_64 . V_66 = 8 ;
V_17 . V_33 = V_60 . V_63 ;
V_61 . V_67 . V_68 = V_69 ;
V_61 . V_67 . V_70 = V_71 ;
V_17 . V_32 = V_61 . V_72 ;
}
return V_17 ;
}
static struct V_16 F_29 ( struct V_1 * V_2 )
{
struct V_16 V_17 ;
unsigned long V_49 , V_50 , V_51 , V_52 ;
F_1 ( V_2 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
V_17 . V_25 = F_30 ( V_50 , V_51 ,
( V_73 * ) & V_17 . V_32 , & V_17 . V_37 ) ;
return V_17 ;
}
static T_1 F_31 ( struct V_1 * V_2 )
{
T_1 V_74 = 0 ;
struct V_7 * V_8 ;
V_8 = F_4 ( V_2 ) ;
if ( V_8 -> V_11 == V_12 )
V_74 = V_8 -> V_13 . V_14 . V_3 ;
return V_74 ;
}
static void F_32 ( struct V_1 * V_2 )
{
V_2 -> V_9 . V_75 = 1 ;
V_2 -> V_9 . V_76 = 0 ;
}
static struct V_16 F_33 ( struct V_1 * V_2 )
{
long V_25 ;
unsigned long V_49 , V_50 , V_51 , V_52 , V_54 ;
unsigned long V_77 [ 16 ] ;
F_1 ( V_2 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
V_25 = F_34 ( V_77 ,
( V_78 * ) & V_54 ) ;
if ( V_25 != 0 ) {
F_2 ( V_15 L_8 , V_25 ) ;
} else {
if ( V_50 )
memcpy ( ( void * ) V_50 , V_77 , sizeof( V_77 ) ) ;
else {
V_25 = V_79 ;
F_2 ( V_22 L_9
L_10 , V_49 ) ;
}
}
return (struct V_16 ) { V_25 , V_54 , 0 , 0 } ;
}
static struct V_16 F_35 ( struct V_1 * V_2 )
{
unsigned long V_49 , V_50 , V_51 , V_52 ;
long V_25 ;
unsigned long V_80 = 1000UL | ( 1000UL << 16 ) | ( 10UL << 32 )
| ( 1UL << 61 ) | ( 1UL << 60 ) ;
F_1 ( V_2 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
if ( V_50 ) {
memcpy ( ( void * ) V_50 , & V_80 , sizeof( V_80 ) ) ;
V_25 = 0 ;
} else{
V_25 = V_79 ;
F_2 ( V_22 L_9
L_10 , V_49 ) ;
}
return (struct V_16 ) { V_25 , 0 , 0 , 0 } ;
}
static struct V_16 F_36 ( struct V_1 * V_2 )
{
unsigned long V_54 ;
long V_25 ;
V_25 = F_37 ( & V_54 ) ;
return (struct V_16 ) { V_25 , V_54 , 0 , 0 } ;
}
static void F_38 ( void * V_81 )
{
T_5 V_82 = ( T_5 ) V_81 ;
F_39 ( V_82 ) ;
}
static struct V_16 F_40 ( struct V_1 * V_2 )
{
struct V_16 V_17 = { 0 , 0 , 0 , 0 } ;
unsigned long V_49 , V_50 , V_51 , V_52 ;
F_1 ( V_2 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
V_17 . V_25 = F_39 ( V_50 ) ;
if ( V_17 . V_25 == 0 ) {
F_10 ( F_38 ,
( void * ) V_50 , 1 ) ;
V_17 . V_25 = 1 ;
}
return V_17 ;
}
static void F_41 ( void * V_81 )
{
F_42 () ;
}
static struct V_16 F_43 ( struct V_1 * V_2 )
{
struct V_16 V_17 = { 0 , 0 , 0 , 0 } ;
unsigned long V_49 , V_50 , V_51 , V_52 ;
F_1 ( V_2 , & V_49 , & V_50 , & V_51 , & V_52 ) ;
if ( V_50 == 0 && V_51 ) {
char V_83 [ 128 ] ;
V_17 . V_25 = F_44 ( V_83 ) ;
if ( V_17 . V_25 == V_84 )
memcpy ( ( void * ) V_51 , V_83 , 128 ) ;
} else {
V_17 . V_25 = V_85 ;
F_2 ( V_22 L_11
L_12 , V_49 ) ;
}
return V_17 ;
}
int F_45 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
T_1 V_3 ;
struct V_16 V_17 ;
int V_18 = 1 ;
V_3 = F_31 ( V_2 ) ;
switch ( V_3 ) {
case V_88 :
V_17 = F_9 ( V_2 ) ;
break;
case V_89 :
V_17 = F_36 ( V_2 ) ;
break;
case V_34 :
V_17 = F_13 ( V_2 ) ;
break;
case V_90 :
V_17 = F_33 ( V_2 ) ;
break;
case V_91 :
V_17 = F_35 ( V_2 ) ;
break;
case V_92 :
{
F_21 ( V_17 ) ;
F_32 ( V_2 ) ;
if ( F_46 ( V_2 ) == - 1 )
V_18 = F_47 ( V_2 ) ;
}
break;
case V_93 :
V_17 = F_40 ( V_2 ) ;
break;
case V_94 :
V_17 . V_25 = F_42 () ;
F_10 ( F_41 , NULL , 1 ) ;
break;
case V_46 :
V_17 = F_18 ( V_2 ) ;
break;
case V_35 :
V_17 = F_15 ( V_2 ) ;
break;
case V_95 :
V_17 = F_19 ( V_2 ) ;
break;
case V_62 :
V_17 = F_28 ( V_2 ) ;
break;
case V_96 :
V_17 = F_29 ( V_2 ) ;
break;
case V_97 :
V_17 = F_20 ( V_2 ) ;
break;
case V_98 :
V_17 = F_26 ( V_2 ) ;
break;
case V_99 :
F_21 ( V_17 ) ;
V_17 . V_32 = ( 1L << 32 ) | 1L ;
break;
case V_100 :
V_17 = F_24 ( V_2 ) ;
break;
case V_101 :
V_17 . V_25 = F_48 ( & V_17 . V_33 ,
& V_17 . V_32 ) ;
break;
case V_102 :
V_17 . V_25 = F_49 ( & V_17 . V_33 ,
( V_103 * ) & V_17 . V_32 ) ;
break;
case V_104 :
V_17 = F_22 ( V_2 ) ;
break;
case V_105 :
V_17 . V_25 = F_50 ( & V_17 . V_33 ,
& V_17 . V_32 ) ;
break;
case V_106 :
V_17 . V_25 = F_51 (
( V_107 * ) & V_17 . V_33 ,
( V_107 * ) & V_17 . V_32 ) ;
break;
case V_108 :
V_17 . V_25 = V_84 ;
V_17 . V_33 = V_2 -> V_109 ;
break;
case V_110 :
V_17 = F_43 ( V_2 ) ;
break;
case V_111 :
case V_112 :
F_5 ( V_17 ) ;
break;
default:
F_5 ( V_17 ) ;
F_2 ( V_22 L_13
L_14 , V_3 ) ;
}
F_3 ( V_2 , V_17 ) ;
return V_18 ;
}
static struct V_19 F_52 ( struct V_47 * V_47 ,
long V_74 , unsigned long V_50 ,
unsigned long V_51 , unsigned long V_52 ,
unsigned long V_113 , unsigned long V_114 ,
unsigned long V_115 , unsigned long V_116 )
{
unsigned long V_54 = 0 ;
unsigned long V_55 = 0 ;
long V_117 = 0 ;
long V_25 ;
V_25 = 0 ;
switch ( V_74 ) {
case V_118 :
V_25 = F_16 ( V_50 , & V_54 , & V_55 ) ;
break;
case V_119 :
F_2 ( V_22 L_15
L_16 ) ;
break;
case V_120 :
F_2 ( V_22 L_15
L_17 ) ;
break;
case V_121 :
if ( V_50 == V_122 ) {
if ( V_113 != 0 || V_114 != 0 || V_115 != 0 || V_116 != 0 ) {
V_25 = - 2 ;
} else {
V_47 -> V_9 . V_123 . V_124 = V_51 ;
V_47 -> V_9 . V_123 . V_125 = V_52 ;
}
F_2 ( L_18 , V_51 ) ;
} else
F_2 ( V_22 L_19
L_20 , V_50 ) ;
break;
case V_126 :
V_25 = - 5 ;
V_54 = 0 ;
break;
case V_127 :
V_25 = 0 ;
V_54 = 128 ;
break;
case V_128 :
break;
case V_129 :
F_2 ( V_22
L_21 ) ;
break;
case V_130 :
F_2 ( V_22
L_22 ) ;
break;
case V_131 :
if ( 1 ) {
V_25 = F_53 ( V_50 ) ;
} else {
V_25 = 0 ;
}
break;
case V_132 :
F_2 ( V_22
L_23 ) ;
break;
case V_133 :
F_2 ( V_22
L_24 ) ;
break;
default:
F_2 ( V_22 L_25
L_26 , V_74 ) ;
V_25 = - 1 ;
break;
}
return ( (struct V_19 ) { V_25 , V_54 , V_55 , V_117 } ) ;
}
static void F_54 ( struct V_1 * V_2 , T_1 * V_49 , T_1 * V_50 ,
T_1 * V_51 , T_1 * V_52 , T_1 * V_113 , T_1 * V_114 , T_1 * V_115 , T_1 * V_116 ) {
struct V_7 * V_8 ;
V_8 = F_4 ( V_2 ) ;
if ( V_8 -> V_11 == V_20 ) {
* V_49 = V_8 -> V_13 . V_21 . V_49 ;
* V_50 = V_8 -> V_13 . V_21 . V_50 ;
* V_51 = V_8 -> V_13 . V_21 . V_51 ;
* V_52 = V_8 -> V_13 . V_21 . V_52 ;
* V_113 = V_8 -> V_13 . V_21 . V_113 ;
* V_114 = V_8 -> V_13 . V_21 . V_114 ;
* V_115 = V_8 -> V_13 . V_21 . V_115 ;
* V_116 = V_8 -> V_13 . V_21 . V_116 ;
return ;
}
* V_49 = 0 ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_19 V_17 ;
T_1 V_74 , V_50 , V_51 , V_52 , V_113 , V_114 , V_115 , V_116 ;
F_54 ( V_2 , & V_74 , & V_50 , & V_51 ,
& V_52 , & V_113 , & V_114 , & V_115 , & V_116 ) ;
V_17 = F_52 ( V_2 -> V_47 , V_74 , V_50 , V_51 , V_52 ,
V_113 , V_114 , V_115 , V_116 ) ;
F_6 ( V_2 , V_17 ) ;
}
