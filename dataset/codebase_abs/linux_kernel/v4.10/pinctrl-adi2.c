static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return V_3 - V_2 -> V_4 ;
}
static inline T_2 F_2 ( struct V_5 * V_6 , int V_7 )
{
return V_6 -> V_8 ? F_3 ( V_7 ) << V_9 : F_3 ( V_7 ) ;
}
static struct V_10 * F_4 ( unsigned V_11 )
{
struct V_10 * V_12 ;
int V_13 = 0 ;
F_5 (pint, &adi_pint_list, node) {
if ( V_11 == V_13 )
return V_12 ;
V_13 ++ ;
}
return NULL ;
}
static inline void F_6 ( struct V_5 * V_6 , unsigned V_14 ,
bool V_15 )
{
struct V_16 * V_17 = V_6 -> V_17 ;
if ( V_15 )
F_7 ( F_8 ( & V_17 -> V_18 ) & ~ F_3 ( V_14 ) ,
& V_17 -> V_18 ) ;
else
F_7 ( F_8 ( & V_17 -> V_18 ) | F_3 ( V_14 ) , & V_17 -> V_18 ) ;
}
static inline void F_9 ( struct V_5 * V_6 , unsigned V_14 ,
unsigned short V_19 )
{
struct V_16 * V_17 = V_6 -> V_17 ;
T_2 V_20 ;
V_20 = F_10 ( & V_17 -> V_21 ) ;
V_20 &= ~ ( 0x3 << ( 2 * V_14 ) ) ;
V_20 |= ( V_19 & 0x3 ) << ( 2 * V_14 ) ;
F_11 ( V_20 , & V_17 -> V_21 ) ;
}
static inline T_3 F_12 ( struct V_5 * V_6 , unsigned V_14 )
{
struct V_16 * V_17 = V_6 -> V_17 ;
T_2 V_20 = F_10 ( & V_17 -> V_21 ) ;
return V_20 >> ( 2 * V_14 ) & 0x3 ;
}
static void F_13 ( struct V_22 * V_23 )
{
unsigned long V_24 ;
struct V_5 * V_6 = F_14 ( V_23 ) ;
struct V_25 * V_17 = V_6 -> V_12 -> V_17 ;
unsigned V_26 = F_2 ( V_6 , V_23 -> V_7 ) ;
F_15 ( & V_6 -> V_27 , V_24 ) ;
F_16 ( & V_6 -> V_12 -> V_27 ) ;
if ( F_17 ( V_23 ) == V_28 ) {
if ( F_10 ( & V_17 -> V_29 ) & V_26 )
F_11 ( V_26 , & V_17 -> V_30 ) ;
else
F_11 ( V_26 , & V_17 -> V_29 ) ;
}
F_11 ( V_26 , & V_17 -> V_31 ) ;
F_18 ( & V_6 -> V_12 -> V_27 ) ;
F_19 ( & V_6 -> V_27 , V_24 ) ;
}
static void F_20 ( struct V_22 * V_23 )
{
unsigned long V_24 ;
struct V_5 * V_6 = F_14 ( V_23 ) ;
struct V_25 * V_17 = V_6 -> V_12 -> V_17 ;
unsigned V_26 = F_2 ( V_6 , V_23 -> V_7 ) ;
F_15 ( & V_6 -> V_27 , V_24 ) ;
F_16 ( & V_6 -> V_12 -> V_27 ) ;
if ( F_17 ( V_23 ) == V_28 ) {
if ( F_10 ( & V_17 -> V_29 ) & V_26 )
F_11 ( V_26 , & V_17 -> V_30 ) ;
else
F_11 ( V_26 , & V_17 -> V_29 ) ;
}
F_11 ( V_26 , & V_17 -> V_31 ) ;
F_11 ( V_26 , & V_17 -> V_32 ) ;
F_18 ( & V_6 -> V_12 -> V_27 ) ;
F_19 ( & V_6 -> V_27 , V_24 ) ;
}
static void F_21 ( struct V_22 * V_23 )
{
unsigned long V_24 ;
struct V_5 * V_6 = F_14 ( V_23 ) ;
struct V_25 * V_17 = V_6 -> V_12 -> V_17 ;
F_15 ( & V_6 -> V_27 , V_24 ) ;
F_16 ( & V_6 -> V_12 -> V_27 ) ;
F_11 ( F_2 ( V_6 , V_23 -> V_7 ) , & V_17 -> V_32 ) ;
F_18 ( & V_6 -> V_12 -> V_27 ) ;
F_19 ( & V_6 -> V_27 , V_24 ) ;
}
static void F_22 ( struct V_22 * V_23 )
{
unsigned long V_24 ;
struct V_5 * V_6 = F_14 ( V_23 ) ;
struct V_25 * V_17 = V_6 -> V_12 -> V_17 ;
F_15 ( & V_6 -> V_27 , V_24 ) ;
F_16 ( & V_6 -> V_12 -> V_27 ) ;
F_11 ( F_2 ( V_6 , V_23 -> V_7 ) , & V_17 -> V_33 ) ;
F_18 ( & V_6 -> V_12 -> V_27 ) ;
F_19 ( & V_6 -> V_27 , V_24 ) ;
}
static unsigned int F_23 ( struct V_22 * V_23 )
{
unsigned long V_24 ;
struct V_5 * V_6 = F_14 ( V_23 ) ;
struct V_25 * V_17 ;
if ( ! V_6 ) {
F_24 ( L_1 , V_23 -> V_34 ) ;
return - V_35 ;
}
V_17 = V_6 -> V_12 -> V_17 ;
F_15 ( & V_6 -> V_27 , V_24 ) ;
F_16 ( & V_6 -> V_12 -> V_27 ) ;
F_6 ( V_6 , V_23 -> V_7 , true ) ;
F_7 ( F_3 ( V_23 -> V_7 ) , & V_6 -> V_17 -> V_36 ) ;
F_7 ( F_8 ( & V_6 -> V_17 -> V_37 ) | F_3 ( V_23 -> V_7 ) , & V_6 -> V_17 -> V_37 ) ;
F_11 ( F_2 ( V_6 , V_23 -> V_7 ) , & V_17 -> V_33 ) ;
F_18 ( & V_6 -> V_12 -> V_27 ) ;
F_19 ( & V_6 -> V_27 , V_24 ) ;
return 0 ;
}
static void F_25 ( struct V_22 * V_23 )
{
unsigned long V_24 ;
struct V_5 * V_6 = F_14 ( V_23 ) ;
struct V_25 * V_17 = V_6 -> V_12 -> V_17 ;
F_15 ( & V_6 -> V_27 , V_24 ) ;
F_16 ( & V_6 -> V_12 -> V_27 ) ;
F_11 ( F_2 ( V_6 , V_23 -> V_7 ) , & V_17 -> V_32 ) ;
F_18 ( & V_6 -> V_12 -> V_27 ) ;
F_19 ( & V_6 -> V_27 , V_24 ) ;
}
static int F_26 ( struct V_22 * V_23 , unsigned int type )
{
unsigned long V_24 ;
struct V_5 * V_6 = F_14 ( V_23 ) ;
struct V_25 * V_38 ;
unsigned V_39 ;
unsigned int V_34 = V_23 -> V_34 ;
int V_40 = 0 ;
char V_41 [ 16 ] ;
if ( ! V_6 ) {
F_24 ( L_1 , V_23 -> V_34 ) ;
return - V_35 ;
}
V_38 = V_6 -> V_12 -> V_17 ;
V_39 = F_2 ( V_6 , V_23 -> V_7 ) ;
F_15 ( & V_6 -> V_27 , V_24 ) ;
F_16 ( & V_6 -> V_12 -> V_27 ) ;
if ( type == V_42 )
type = V_43 | V_44 ;
if ( type & ( V_43 | V_44 |
V_45 | V_46 ) ) {
snprintf ( V_41 , 16 , L_2 , V_34 ) ;
F_6 ( V_6 , V_23 -> V_7 , true ) ;
} else
goto V_47;
if ( ( type & ( V_44 | V_46 ) ) )
F_11 ( V_39 , & V_38 -> V_29 ) ;
else
F_11 ( V_39 , & V_38 -> V_30 ) ;
if ( ( type & V_28 ) == V_28 ) {
if ( F_27 ( V_6 -> V_48 . V_49 + V_23 -> V_7 ) )
F_11 ( V_39 , & V_38 -> V_29 ) ;
else
F_11 ( V_39 , & V_38 -> V_30 ) ;
}
if ( type & ( V_43 | V_44 ) ) {
F_11 ( V_39 , & V_38 -> V_50 ) ;
F_28 ( V_23 , V_51 ) ;
} else {
F_11 ( V_39 , & V_38 -> V_52 ) ;
F_28 ( V_23 , V_53 ) ;
}
V_47:
F_18 ( & V_6 -> V_12 -> V_27 ) ;
F_19 ( & V_6 -> V_27 , V_24 ) ;
return V_40 ;
}
static int F_29 ( struct V_22 * V_23 , unsigned int V_54 )
{
struct V_5 * V_6 = F_14 ( V_23 ) ;
if ( ! V_6 || ! V_6 -> V_12 || V_6 -> V_12 -> V_34 != V_23 -> V_34 )
return - V_55 ;
#ifndef F_30
F_31 ( V_6 -> V_12 -> V_34 , V_54 ) ;
#endif
return 0 ;
}
static int F_32 ( void )
{
struct V_10 * V_12 ;
F_5 (pint, &adi_pint_list, node) {
F_11 ( 0xffffffff , & V_12 -> V_17 -> V_32 ) ;
V_12 -> V_56 . V_57 = F_10 ( & V_12 -> V_17 -> V_57 ) ;
V_12 -> V_56 . V_50 = F_10 ( & V_12 -> V_17 -> V_50 ) ;
V_12 -> V_56 . V_29 = F_10 ( & V_12 -> V_17 -> V_29 ) ;
}
return 0 ;
}
static void F_33 ( void )
{
struct V_10 * V_12 ;
F_5 (pint, &adi_pint_list, node) {
F_11 ( V_12 -> V_56 . V_57 , & V_12 -> V_17 -> V_57 ) ;
F_11 ( V_12 -> V_56 . V_50 , & V_12 -> V_17 -> V_50 ) ;
F_11 ( V_12 -> V_56 . V_29 , & V_12 -> V_17 -> V_29 ) ;
}
}
static int F_34 ( void )
{
struct V_5 * V_6 ;
F_5 (port, &adi_gpio_port_list, node) {
V_6 -> V_56 . V_58 = F_8 ( & V_6 -> V_17 -> V_18 ) ;
V_6 -> V_56 . V_59 = F_10 ( & V_6 -> V_17 -> V_21 ) ;
V_6 -> V_56 . V_60 = F_8 ( & V_6 -> V_17 -> V_60 ) ;
V_6 -> V_56 . V_37 = F_8 ( & V_6 -> V_17 -> V_37 ) ;
V_6 -> V_56 . V_61 = F_8 ( & V_6 -> V_17 -> V_62 ) ;
}
return F_32 () ;
}
static void F_35 ( void )
{
struct V_5 * V_6 ;
F_33 () ;
F_5 (port, &adi_gpio_port_list, node) {
F_11 ( V_6 -> V_56 . V_59 , & V_6 -> V_17 -> V_21 ) ;
F_7 ( V_6 -> V_56 . V_58 , & V_6 -> V_17 -> V_18 ) ;
F_7 ( V_6 -> V_56 . V_37 , & V_6 -> V_17 -> V_37 ) ;
F_7 ( V_6 -> V_56 . V_60 & V_6 -> V_56 . V_61 ,
& V_6 -> V_17 -> V_63 ) ;
F_7 ( V_6 -> V_56 . V_61 , & V_6 -> V_17 -> V_62 ) ;
}
}
static inline void F_36 ( struct V_64 * V_65 )
{
if ( V_65 -> F_36 )
V_65 -> F_36 ( & V_65 -> V_22 ) ;
}
static inline void F_36 ( struct V_64 * V_65 ) { }
static void F_37 ( struct V_64 * V_65 )
{
T_2 V_31 ;
T_2 V_66 , V_7 ;
bool V_67 = false ;
struct V_10 * V_12 = F_38 ( V_65 ) ;
struct V_68 * V_48 = F_39 ( V_65 ) ;
struct V_25 * V_17 = V_12 -> V_17 ;
struct V_69 * V_70 ;
F_36 ( V_65 ) ;
F_40 ( V_48 , V_65 ) ;
V_31 = F_10 ( & V_17 -> V_31 ) ;
V_66 = F_10 ( & V_17 -> V_50 ) & V_31 ;
V_7 = 0 ;
V_70 = V_12 -> V_70 [ 0 ] ;
while ( V_31 ) {
if ( V_7 == V_9 )
V_70 = V_12 -> V_70 [ 1 ] ;
if ( V_31 & 1 ) {
if ( V_66 & F_3 ( V_7 ) ) {
V_67 = true ;
F_41 ( V_48 , V_65 ) ;
}
F_42 ( F_43 ( V_70 ,
V_7 % V_9 ) ) ;
}
V_7 ++ ;
V_31 >>= 1 ;
}
if ( ! V_67 )
F_41 ( V_48 , V_65 ) ;
}
static int F_44 ( struct V_71 * V_72 )
{
struct V_73 * V_74 = F_45 ( V_72 ) ;
return V_74 -> V_75 -> V_76 ;
}
static const char * F_46 ( struct V_71 * V_72 ,
unsigned V_77 )
{
struct V_73 * V_74 = F_45 ( V_72 ) ;
return V_74 -> V_75 -> V_78 [ V_77 ] . V_79 ;
}
static int F_47 ( struct V_71 * V_72 , unsigned V_77 ,
const unsigned * * V_80 ,
unsigned * V_81 )
{
struct V_73 * V_74 = F_45 ( V_72 ) ;
* V_80 = V_74 -> V_75 -> V_78 [ V_77 ] . V_80 ;
* V_81 = V_74 -> V_75 -> V_78 [ V_77 ] . V_82 ;
return 0 ;
}
static int F_48 ( struct V_71 * V_72 , unsigned V_83 ,
unsigned V_84 )
{
struct V_73 * V_74 = F_45 ( V_72 ) ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
unsigned long V_24 ;
unsigned short * V_59 , V_3 ;
V_59 = ( unsigned short * ) V_74 -> V_75 -> V_78 [ V_84 ] . V_59 ;
while ( * V_59 ) {
V_3 = F_49 ( * V_59 ) ;
V_2 = F_50 ( V_72 , V_3 ) ;
if ( V_2 == NULL )
return - V_35 ;
V_6 = F_51 ( V_2 -> V_85 ) ;
F_15 ( & V_6 -> V_27 , V_24 ) ;
F_9 ( V_6 , F_1 ( V_2 , V_3 ) ,
F_52 ( * V_59 ) ) ;
F_6 ( V_6 , F_1 ( V_2 , V_3 ) , false ) ;
V_59 ++ ;
F_19 ( & V_6 -> V_27 , V_24 ) ;
}
return 0 ;
}
static int F_53 ( struct V_71 * V_72 )
{
struct V_73 * V_74 = F_45 ( V_72 ) ;
return V_74 -> V_75 -> V_86 ;
}
static const char * F_54 ( struct V_71 * V_72 ,
unsigned V_77 )
{
struct V_73 * V_74 = F_45 ( V_72 ) ;
return V_74 -> V_75 -> V_87 [ V_77 ] . V_79 ;
}
static int F_55 ( struct V_71 * V_72 , unsigned V_77 ,
const char * const * * V_78 ,
unsigned * const V_88 )
{
struct V_73 * V_74 = F_45 ( V_72 ) ;
* V_78 = V_74 -> V_75 -> V_87 [ V_77 ] . V_78 ;
* V_88 = V_74 -> V_75 -> V_87 [ V_77 ] . V_88 ;
return 0 ;
}
static int F_56 ( struct V_71 * V_72 ,
struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 ;
unsigned long V_24 ;
T_1 V_14 ;
V_6 = F_51 ( V_2 -> V_85 ) ;
V_14 = F_1 ( V_2 , V_3 ) ;
F_15 ( & V_6 -> V_27 , V_24 ) ;
F_6 ( V_6 , V_14 , true ) ;
F_19 ( & V_6 -> V_27 , V_24 ) ;
return 0 ;
}
static int F_57 ( struct V_89 * V_48 , unsigned V_14 )
{
struct V_5 * V_6 ;
unsigned long V_24 ;
V_6 = F_51 ( V_48 ) ;
F_15 ( & V_6 -> V_27 , V_24 ) ;
F_7 ( F_3 ( V_14 ) , & V_6 -> V_17 -> V_36 ) ;
F_7 ( F_8 ( & V_6 -> V_17 -> V_37 ) | F_3 ( V_14 ) , & V_6 -> V_17 -> V_37 ) ;
F_19 ( & V_6 -> V_27 , V_24 ) ;
return 0 ;
}
static void F_58 ( struct V_89 * V_48 , unsigned V_14 ,
int V_90 )
{
struct V_5 * V_6 = F_51 ( V_48 ) ;
struct V_16 * V_17 = V_6 -> V_17 ;
unsigned long V_24 ;
F_15 ( & V_6 -> V_27 , V_24 ) ;
if ( V_90 )
F_7 ( F_3 ( V_14 ) , & V_17 -> V_63 ) ;
else
F_7 ( F_3 ( V_14 ) , & V_17 -> V_91 ) ;
F_19 ( & V_6 -> V_27 , V_24 ) ;
}
static int F_59 ( struct V_89 * V_48 , unsigned V_14 ,
int V_90 )
{
struct V_5 * V_6 = F_51 ( V_48 ) ;
struct V_16 * V_17 = V_6 -> V_17 ;
unsigned long V_24 ;
F_15 ( & V_6 -> V_27 , V_24 ) ;
F_7 ( F_8 ( & V_17 -> V_37 ) & ~ F_3 ( V_14 ) , & V_17 -> V_37 ) ;
if ( V_90 )
F_7 ( F_3 ( V_14 ) , & V_17 -> V_63 ) ;
else
F_7 ( F_3 ( V_14 ) , & V_17 -> V_91 ) ;
F_7 ( F_3 ( V_14 ) , & V_17 -> V_62 ) ;
F_19 ( & V_6 -> V_27 , V_24 ) ;
return 0 ;
}
static int F_60 ( struct V_89 * V_48 , unsigned V_14 )
{
struct V_5 * V_6 = F_51 ( V_48 ) ;
struct V_16 * V_17 = V_6 -> V_17 ;
unsigned long V_24 ;
int V_40 ;
F_15 ( & V_6 -> V_27 , V_24 ) ;
V_40 = ! ! ( F_8 ( & V_17 -> V_60 ) & F_3 ( V_14 ) ) ;
F_19 ( & V_6 -> V_27 , V_24 ) ;
return V_40 ;
}
static int F_61 ( struct V_89 * V_48 , unsigned V_14 )
{
struct V_5 * V_6 = F_51 ( V_48 ) ;
if ( V_6 -> V_92 >= 0 )
return F_43 ( V_6 -> V_70 , V_14 ) ;
else
return F_62 ( V_6 -> V_70 , V_14 ) ;
}
static int F_63 ( struct V_10 * V_12 , bool V_57 , T_1 V_93 ,
struct V_69 * V_70 )
{
struct V_25 * V_17 = V_12 -> V_17 ;
T_2 V_94 ;
if ( V_12 -> V_95 > 1 )
return - V_55 ;
V_12 -> V_95 ++ ;
V_94 = ( V_93 << 8 ) | V_93 ;
if ( V_57 ) {
V_94 <<= V_9 ;
F_11 ( ( F_10 ( & V_17 -> V_57 ) & 0xFFFF ) | V_94 ,
& V_17 -> V_57 ) ;
} else
F_11 ( ( F_10 ( & V_17 -> V_57 ) & 0xFFFF0000 ) | V_94 ,
& V_17 -> V_57 ) ;
V_12 -> V_70 [ V_57 ] = V_70 ;
return 0 ;
}
static int F_64 ( struct V_96 * V_97 )
{
struct V_98 * V_99 = & V_97 -> V_99 ;
struct V_100 * V_101 ;
struct V_10 * V_12 ;
V_12 = F_65 ( V_99 , sizeof( struct V_10 ) , V_102 ) ;
if ( ! V_12 ) {
F_66 ( V_99 , L_3 ) ;
return - V_103 ;
}
V_101 = F_67 ( V_97 , V_104 , 0 ) ;
V_12 -> V_49 = F_68 ( V_99 , V_101 ) ;
if ( F_69 ( V_12 -> V_49 ) )
return F_70 ( V_12 -> V_49 ) ;
V_12 -> V_17 = (struct V_25 * ) V_12 -> V_49 ;
V_101 = F_67 ( V_97 , V_105 , 0 ) ;
if ( ! V_101 ) {
F_66 ( V_99 , L_4 ) ;
return - V_35 ;
}
F_71 ( & V_12 -> V_27 ) ;
V_12 -> V_34 = V_101 -> V_106 ;
V_12 -> V_107 = F_63 ;
F_72 ( V_97 , V_12 ) ;
F_73 ( V_12 -> V_34 , F_37 ,
V_12 ) ;
F_74 ( & V_12 -> V_108 , & V_109 ) ;
return 0 ;
}
static int F_75 ( struct V_96 * V_97 )
{
struct V_10 * V_12 = F_76 ( V_97 ) ;
F_77 ( & V_12 -> V_108 ) ;
F_78 ( V_12 -> V_34 , V_110 ) ;
return 0 ;
}
static int F_79 ( struct V_69 * V_23 , unsigned int V_34 ,
T_4 V_7 )
{
struct V_5 * V_6 = V_23 -> V_111 ;
if ( ! V_6 )
return - V_55 ;
F_80 ( V_34 , V_6 ) ;
F_81 ( V_34 , & V_112 ,
V_53 ) ;
return 0 ;
}
static int F_82 ( struct V_5 * V_6 )
{
struct V_113 * V_108 = V_6 -> V_99 -> V_114 ;
struct V_10 * V_12 = V_6 -> V_12 ;
int V_40 ;
V_6 -> V_70 = F_83 ( V_108 , V_6 -> V_115 ,
& V_116 , V_6 ) ;
if ( ! V_6 -> V_70 ) {
F_66 ( V_6 -> V_99 , L_5 ) ;
return - V_117 ;
}
V_40 = V_12 -> V_107 ( V_6 -> V_12 , V_6 -> V_8 ,
V_6 -> V_118 , V_6 -> V_70 ) ;
if ( V_40 )
return V_40 ;
if ( V_6 -> V_92 >= 0 ) {
V_40 = F_84 ( V_6 -> V_70 , V_6 -> V_92 ,
0 , V_6 -> V_115 ) ;
if ( V_40 ) {
F_66 ( V_6 -> V_99 , L_6 ) ;
return V_40 ;
}
}
return 0 ;
}
static int F_85 ( struct V_96 * V_97 )
{
struct V_98 * V_99 = & V_97 -> V_99 ;
const struct V_119 * V_120 ;
struct V_100 * V_101 ;
struct V_5 * V_6 ;
char V_121 [ V_122 ] ;
static int V_123 ;
int V_40 = 0 ;
V_120 = V_99 -> V_124 ;
if ( ! V_120 )
return - V_55 ;
V_6 = F_65 ( V_99 , sizeof( struct V_5 ) , V_102 ) ;
if ( ! V_6 ) {
F_66 ( V_99 , L_3 ) ;
return - V_103 ;
}
V_101 = F_67 ( V_97 , V_104 , 0 ) ;
V_6 -> V_49 = F_68 ( V_99 , V_101 ) ;
if ( F_69 ( V_6 -> V_49 ) )
return F_70 ( V_6 -> V_49 ) ;
V_101 = F_67 ( V_97 , V_105 , 0 ) ;
if ( ! V_101 )
V_6 -> V_92 = - 1 ;
else
V_6 -> V_92 = V_101 -> V_106 ;
V_6 -> V_115 = V_120 -> V_125 ;
V_6 -> V_99 = V_99 ;
V_6 -> V_17 = (struct V_16 * ) V_6 -> V_49 ;
V_6 -> V_8 = V_120 -> V_8 ;
V_6 -> V_118 = V_120 -> V_118 ;
V_6 -> V_12 = F_4 ( V_120 -> V_126 ) ;
if ( V_6 -> V_12 ) {
V_40 = F_82 ( V_6 ) ;
if ( V_40 )
return V_40 ;
}
F_71 ( & V_6 -> V_27 ) ;
F_72 ( V_97 , V_6 ) ;
V_6 -> V_48 . V_127 = L_7 ;
V_6 -> V_48 . V_128 = F_57 ;
V_6 -> V_48 . V_129 = F_60 ;
V_6 -> V_48 . V_130 = F_59 ;
V_6 -> V_48 . V_131 = F_58 ;
V_6 -> V_48 . V_31 = V_132 ,
V_6 -> V_48 . free = V_133 ,
V_6 -> V_48 . V_134 = F_61 ;
if ( V_120 -> V_135 > 0 )
V_6 -> V_48 . V_49 = V_120 -> V_135 ;
else
V_6 -> V_48 . V_49 = V_123 ;
V_6 -> V_48 . V_136 = V_6 -> V_115 ;
V_123 = V_6 -> V_48 . V_49 + V_6 -> V_115 ;
V_40 = F_86 ( & V_6 -> V_48 , V_6 ) ;
if ( V_40 ) {
F_66 ( & V_97 -> V_99 , L_8 ) ;
goto V_137;
}
snprintf ( V_121 , V_122 , L_9 ,
V_120 -> V_138 ) ;
V_121 [ V_122 - 1 ] = 0 ;
V_40 = F_87 ( & V_6 -> V_48 , V_121 ,
0 , V_120 -> V_139 , V_6 -> V_115 ) ;
if ( V_40 ) {
F_66 ( & V_97 -> V_99 , L_10 ,
V_121 ) ;
goto V_140;
}
F_74 ( & V_6 -> V_108 , & V_141 ) ;
return 0 ;
V_140:
F_88 ( & V_6 -> V_48 ) ;
V_137:
if ( V_6 -> V_12 )
F_89 ( V_6 -> V_70 ) ;
return V_40 ;
}
static int F_90 ( struct V_96 * V_97 )
{
struct V_5 * V_6 = F_76 ( V_97 ) ;
T_1 V_14 ;
F_77 ( & V_6 -> V_108 ) ;
F_88 ( & V_6 -> V_48 ) ;
if ( V_6 -> V_12 ) {
for ( V_14 = 0 ; V_14 < V_6 -> V_115 ; V_14 ++ )
F_91 ( F_43 ( V_6 -> V_70 ,
V_14 ) ) ;
F_89 ( V_6 -> V_70 ) ;
}
return 0 ;
}
static int F_92 ( struct V_96 * V_97 )
{
struct V_73 * V_74 ;
V_74 = F_65 ( & V_97 -> V_99 , sizeof( * V_74 ) , V_102 ) ;
if ( ! V_74 )
return - V_103 ;
V_74 -> V_99 = & V_97 -> V_99 ;
F_93 ( & V_74 -> V_75 ) ;
V_142 . V_80 = V_74 -> V_75 -> V_80 ;
V_142 . V_143 = V_74 -> V_75 -> V_143 ;
V_74 -> V_144 = F_94 ( & V_97 -> V_99 , & V_142 ,
V_74 ) ;
if ( F_69 ( V_74 -> V_144 ) ) {
F_66 ( & V_97 -> V_99 , L_11 ) ;
return F_70 ( V_74 -> V_144 ) ;
}
F_72 ( V_97 , V_74 ) ;
return 0 ;
}
static int T_5 F_95 ( void )
{
int V_40 ;
V_40 = F_96 ( V_145 , F_97 ( V_145 ) ) ;
if ( V_40 )
return V_40 ;
#ifdef F_98
F_99 ( & V_146 ) ;
#endif
return 0 ;
}
