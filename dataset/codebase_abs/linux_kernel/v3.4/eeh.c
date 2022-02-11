static T_1 F_1 ( struct V_1 * V_2 , char * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
T_2 V_9 ;
int V_10 , V_11 ;
int V_12 = 0 ;
V_12 += F_4 ( V_3 + V_12 , V_4 - V_12 , L_1 , V_6 -> V_13 ) ;
F_5 ( V_14 L_2 , V_6 -> V_13 ) ;
V_15 -> V_16 ( V_6 , V_17 , 4 , & V_9 ) ;
V_12 += F_4 ( V_3 + V_12 , V_4 - V_12 , L_3 , V_9 ) ;
F_5 ( V_14 L_4 , V_9 ) ;
V_15 -> V_16 ( V_6 , V_18 , 4 , & V_9 ) ;
V_12 += F_4 ( V_3 + V_12 , V_4 - V_12 , L_5 , V_9 ) ;
F_5 ( V_14 L_6 , V_9 ) ;
if ( ! V_8 ) {
F_5 ( V_14 L_7 ) ;
return V_12 ;
}
if ( V_8 -> V_19 >> 16 == V_20 ) {
V_15 -> V_16 ( V_6 , V_21 , 2 , & V_9 ) ;
V_12 += F_4 ( V_3 + V_12 , V_4 - V_12 , L_8 , V_9 ) ;
F_5 ( V_14 L_9 , V_9 ) ;
V_15 -> V_16 ( V_6 , V_22 , 2 , & V_9 ) ;
V_12 += F_4 ( V_3 + V_12 , V_4 - V_12 , L_10 , V_9 ) ;
F_5 ( V_14 L_11 , V_9 ) ;
}
V_10 = F_6 ( V_8 , V_23 ) ;
if ( V_10 ) {
V_15 -> V_16 ( V_6 , V_10 , 4 , & V_9 ) ;
V_12 += F_4 ( V_3 + V_12 , V_4 - V_12 , L_12 , V_9 ) ;
F_5 ( V_14 L_13 , V_9 ) ;
V_15 -> V_16 ( V_6 , V_10 + 4 , 4 , & V_9 ) ;
V_12 += F_4 ( V_3 + V_12 , V_4 - V_12 , L_14 , V_9 ) ;
F_5 ( V_14 L_15 , V_9 ) ;
}
V_10 = F_6 ( V_8 , V_24 ) ;
if ( V_10 ) {
V_12 += F_4 ( V_3 + V_12 , V_4 - V_12 , L_16 ) ;
F_5 ( V_14
L_17 ) ;
for ( V_11 = 0 ; V_11 <= 8 ; V_11 ++ ) {
V_15 -> V_16 ( V_6 , V_10 + 4 * V_11 , 4 , & V_9 ) ;
V_12 += F_4 ( V_3 + V_12 , V_4 - V_12 , L_18 , 4 * V_11 , V_9 ) ;
F_5 ( V_14 L_19 , V_11 , V_9 ) ;
}
V_10 = F_7 ( V_8 , V_25 ) ;
if ( V_10 ) {
V_12 += F_4 ( V_3 + V_12 , V_4 - V_12 , L_20 ) ;
F_5 ( V_14
L_21 ) ;
for ( V_11 = 0 ; V_11 < 14 ; V_11 ++ ) {
V_15 -> V_16 ( V_6 , V_10 + 4 * V_11 , 4 , & V_9 ) ;
V_12 += F_4 ( V_3 + V_12 , V_4 - V_12 , L_18 , 4 * V_11 , V_9 ) ;
F_5 ( V_14 L_22 , V_11 , V_9 ) ;
}
}
}
if ( V_8 -> V_19 >> 16 == V_20 ) {
struct V_5 * V_26 ;
F_8 (dn, child) {
if ( F_9 ( V_26 ) )
V_12 += F_1 ( F_9 ( V_26 ) , V_3 + V_12 , V_4 - V_12 ) ;
}
}
return V_12 ;
}
void F_10 ( struct V_1 * V_2 , int V_27 )
{
T_1 V_28 = 0 ;
V_29 [ 0 ] = 0 ;
F_11 ( V_2 , V_30 ) ;
V_15 -> V_31 ( F_2 ( V_2 ) ) ;
F_12 ( V_2 ) ;
V_28 = F_1 ( V_2 , V_29 , V_32 ) ;
V_15 -> V_33 ( F_2 ( V_2 ) , V_27 , V_29 , V_28 ) ;
}
static inline unsigned long F_13 ( unsigned long V_34 )
{
T_3 * V_35 ;
unsigned long V_36 ;
V_35 = F_14 ( V_37 . V_38 , V_34 ) ;
if ( ! V_35 )
return V_34 ;
V_36 = F_15 ( * V_35 ) << V_39 ;
return V_36 | ( V_34 & ( V_40 - 1 ) ) ;
}
struct V_5 * F_16 ( struct V_5 * V_6 )
{
while ( V_6 -> V_41 && F_9 ( V_6 -> V_41 ) &&
( F_9 ( V_6 -> V_41 ) -> V_42 & V_43 ) ) {
V_6 = V_6 -> V_41 ;
}
return V_6 ;
}
static void F_17 ( struct V_5 * V_41 , int V_44 )
{
struct V_5 * V_6 ;
F_8 (parent, dn) {
if ( F_9 ( V_6 ) ) {
struct V_7 * V_8 = F_9 ( V_6 ) -> V_45 ;
F_9 ( V_6 ) -> V_42 |= V_44 ;
if ( V_8 && V_8 -> V_46 )
V_8 -> V_47 = V_48 ;
F_17 ( V_6 , V_44 ) ;
}
}
}
void F_18 ( struct V_5 * V_6 , int V_44 )
{
struct V_7 * V_8 ;
V_6 = F_16 ( V_6 ) ;
if ( ! F_19 ( V_6 ) && F_9 ( V_6 -> V_41 ) )
V_6 = V_6 -> V_41 ;
F_9 ( V_6 ) -> V_42 |= V_44 ;
V_8 = F_9 ( V_6 ) -> V_45 ;
if ( V_8 )
V_8 -> V_47 = V_48 ;
F_17 ( V_6 , V_44 ) ;
}
static void F_20 ( struct V_5 * V_41 , int V_44 )
{
struct V_5 * V_6 ;
F_8 (parent, dn) {
if ( F_9 ( V_6 ) ) {
F_9 ( V_6 ) -> V_42 &= ~ V_44 ;
F_9 ( V_6 ) -> V_49 = 0 ;
F_20 ( V_6 , V_44 ) ;
}
}
}
void F_21 ( struct V_5 * V_6 , int V_44 )
{
unsigned long V_50 ;
F_22 ( & V_51 , V_50 ) ;
V_6 = F_16 ( V_6 ) ;
if ( ! F_19 ( V_6 ) && F_9 ( V_6 -> V_41 ) )
V_6 = V_6 -> V_41 ;
F_9 ( V_6 ) -> V_42 &= ~ V_44 ;
F_9 ( V_6 ) -> V_49 = 0 ;
F_20 ( V_6 , V_44 ) ;
F_23 ( & V_51 , V_50 ) ;
}
int F_24 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
int V_52 ;
unsigned long V_50 ;
struct V_1 * V_2 ;
int V_53 = 0 ;
const char * V_54 ;
V_55 . V_56 ++ ;
if ( ! V_57 )
return 0 ;
if ( ! V_6 ) {
V_55 . V_58 ++ ;
return 0 ;
}
V_6 = F_16 ( V_6 ) ;
V_2 = F_9 ( V_6 ) ;
if ( ! ( V_2 -> V_42 & V_43 ) ||
V_2 -> V_42 & V_59 ) {
V_55 . V_60 ++ ;
F_25 ( L_23 ,
V_2 -> V_42 , F_26 ( V_8 ) , V_6 -> V_13 ) ;
return 0 ;
}
if ( ! V_2 -> V_61 && ! V_2 -> V_62 ) {
V_55 . V_63 ++ ;
return 0 ;
}
F_22 ( & V_51 , V_50 ) ;
V_53 = 1 ;
if ( V_2 -> V_42 & V_64 ) {
V_2 -> V_49 ++ ;
if ( V_2 -> V_49 % V_65 == 0 ) {
V_54 = F_27 ( V_6 , L_24 , NULL ) ;
F_5 ( V_66 L_25
L_26 ,
V_2 -> V_49 , V_54 ,
F_28 ( V_8 ) , F_26 ( V_8 ) ) ;
F_5 ( V_66 L_27 ,
F_28 ( V_8 ) ) ;
F_29 () ;
}
goto V_67;
}
V_52 = V_15 -> V_68 ( V_6 , NULL ) ;
if ( ( V_52 < 0 ) ||
( V_52 == V_69 ) ||
( V_52 & ( V_70 | V_71 ) ) ==
( V_70 | V_71 ) ) {
V_55 . V_72 ++ ;
V_2 -> V_72 ++ ;
V_53 = 0 ;
goto V_67;
}
V_55 . V_73 ++ ;
F_18 ( V_6 , V_64 ) ;
F_23 ( & V_51 , V_50 ) ;
F_30 ( V_2 ) ;
F_29 () ;
return 1 ;
V_67:
F_23 ( & V_51 , V_50 ) ;
return V_53 ;
}
unsigned long F_31 ( const volatile void T_4 * V_34 , unsigned long V_74 )
{
unsigned long V_75 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
V_75 = F_13 ( ( unsigned long V_76 ) V_34 ) ;
V_8 = F_32 ( V_75 ) ;
if ( ! V_8 ) {
V_55 . V_77 ++ ;
return V_74 ;
}
V_6 = F_33 ( V_8 ) ;
F_24 ( V_6 , V_8 ) ;
F_34 ( V_8 ) ;
return V_74 ;
}
int F_11 ( struct V_1 * V_2 , int V_78 )
{
int V_53 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_53 = V_15 -> V_79 ( V_6 , V_78 ) ;
if ( V_53 )
F_5 ( V_14 L_28 ,
V_78 , V_53 , V_6 -> V_13 ) ;
V_53 = V_15 -> V_80 ( V_6 , V_81 ) ;
if ( V_53 > 0 && ( V_53 & V_82 ) &&
( V_78 == V_30 ) )
return 0 ;
return V_53 ;
}
int F_35 ( struct V_7 * V_8 , enum V_83 V_84 )
{
struct V_5 * V_6 = F_33 ( V_8 ) ;
switch ( V_84 ) {
case V_85 :
V_15 -> V_86 ( V_6 , V_87 ) ;
break;
case V_88 :
V_15 -> V_86 ( V_6 , V_89 ) ;
break;
case V_90 :
V_15 -> V_86 ( V_6 , V_91 ) ;
break;
default:
return - V_92 ;
} ;
return 0 ;
}
void F_36 ( struct V_5 * V_41 , unsigned int * V_93 )
{
struct V_5 * V_6 ;
F_8 (parent, dn) {
if ( F_9 ( V_6 ) ) {
struct V_7 * V_8 = F_9 ( V_6 ) -> V_45 ;
if ( V_8 && V_8 -> V_46 )
* V_93 |= V_8 -> V_94 ;
F_36 ( V_6 , V_93 ) ;
}
}
}
void F_37 ( struct V_5 * V_6 , unsigned int * V_93 )
{
struct V_7 * V_8 ;
V_6 = F_16 ( V_6 ) ;
if ( ! F_19 ( V_6 ) && F_9 ( V_6 -> V_41 ) )
V_6 = V_6 -> V_41 ;
V_8 = F_9 ( V_6 ) -> V_45 ;
if ( V_8 )
* V_93 |= V_8 -> V_94 ;
F_36 ( V_6 , V_93 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
unsigned int V_93 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_37 ( V_6 , & V_93 ) ;
if ( V_93 )
V_15 -> V_86 ( V_6 , V_91 ) ;
else
V_15 -> V_86 ( V_6 , V_89 ) ;
#define F_39 250
F_40 ( F_39 ) ;
F_21 ( V_6 , V_64 ) ;
V_15 -> V_86 ( V_6 , V_87 ) ;
#define F_41 1800
F_40 ( F_41 ) ;
}
int F_42 ( struct V_1 * V_2 )
{
int V_11 , V_53 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
F_38 ( V_2 ) ;
V_53 = V_15 -> V_80 ( V_6 , V_81 ) ;
if ( V_53 == ( V_70 | V_71 ) )
return 0 ;
if ( V_53 < 0 ) {
F_5 ( V_66 L_29 ,
V_6 -> V_13 ) ;
return - 1 ;
}
F_5 ( V_66 L_30 ,
V_11 + 1 , V_6 -> V_13 , V_53 ) ;
}
return - 1 ;
}
static inline void F_43 ( struct V_1 * V_2 )
{
int V_11 ;
T_2 V_95 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_2 -> V_96 )
return;
for ( V_11 = 4 ; V_11 < 10 ; V_11 ++ ) {
V_15 -> V_97 ( V_6 , V_11 * 4 , 4 , V_2 -> V_98 [ V_11 ] ) ;
}
V_15 -> V_97 ( V_6 , 12 * 4 , 4 , V_2 -> V_98 [ 12 ] ) ;
#define F_44 ( T_5 ) (8*((OFF)/4)+3-(OFF))
#define F_45 ( T_5 ) (((u8 *)(edev->config_space))[BYTE_SWAP(OFF)])
V_15 -> V_97 ( V_6 , V_99 , 1 ,
F_45 ( V_99 ) ) ;
V_15 -> V_97 ( V_6 , V_100 , 1 ,
F_45 ( V_100 ) ) ;
V_15 -> V_97 ( V_6 , 15 * 4 , 4 , V_2 -> V_98 [ 15 ] ) ;
V_15 -> V_16 ( V_6 , V_18 , 4 , & V_95 ) ;
if ( V_2 -> V_98 [ 1 ] & V_101 )
V_95 |= V_101 ;
else
V_95 &= ~ V_101 ;
if ( V_2 -> V_98 [ 1 ] & V_102 )
V_95 |= V_102 ;
else
V_95 &= ~ V_102 ;
V_15 -> V_97 ( V_6 , V_18 , 4 , V_95 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
if ( ! V_2 )
return;
if ( ( V_2 -> V_42 & V_43 ) && ! F_46 ( V_2 -> V_103 ) )
F_43 ( V_2 ) ;
F_8 (eeh_dev_to_of_node(edev), dn)
F_12 ( F_9 ( V_6 ) ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
int V_11 ;
struct V_5 * V_6 ;
if ( ! V_2 )
return;
V_6 = F_2 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
V_15 -> V_16 ( V_6 , V_11 * 4 , 4 , & V_2 -> V_98 [ V_11 ] ) ;
}
static void * F_48 ( struct V_5 * V_6 , void * V_104 )
{
int V_52 ;
const T_2 * V_103 = F_27 ( V_6 , L_31 , NULL ) ;
const T_2 * V_105 = F_27 ( V_6 , L_32 , NULL ) ;
const T_2 * V_106 = F_27 ( V_6 , L_33 , NULL ) ;
const T_2 * V_107 ;
int V_108 ;
struct V_1 * V_2 = F_9 ( V_6 ) ;
V_2 -> V_103 = 0 ;
V_2 -> V_42 = 0 ;
V_2 -> V_49 = 0 ;
V_2 -> V_109 = 0 ;
V_2 -> V_72 = 0 ;
if ( ! F_49 ( V_6 ) )
return NULL ;
if ( ! V_103 || ! V_105 || ! V_106 )
return NULL ;
if ( V_6 -> type && ! strcmp ( V_6 -> type , L_34 ) ) {
V_2 -> V_42 |= V_59 ;
return NULL ;
}
V_2 -> V_103 = * V_103 ;
V_107 = F_27 ( V_6 , L_35 , NULL ) ;
if ( V_107 ) {
V_52 = V_15 -> V_79 ( V_6 , V_110 ) ;
V_108 = 0 ;
if ( V_52 == 0 ) {
V_2 -> V_61 = V_107 [ 0 ] ;
V_2 -> V_62 = V_15 -> V_111 ( V_6 ) ;
V_52 = V_15 -> V_68 ( V_6 , NULL ) ;
if ( V_52 > 0 && V_52 != V_69 )
V_108 = 1 ;
}
if ( V_108 ) {
V_57 = 1 ;
V_2 -> V_42 |= V_43 ;
F_25 ( L_36 ,
V_6 -> V_13 , V_2 -> V_61 ,
V_2 -> V_62 ) ;
} else {
if ( V_6 -> V_41 && F_9 ( V_6 -> V_41 ) &&
( F_9 ( V_6 -> V_41 ) -> V_42 & V_43 ) ) {
V_2 -> V_42 |= V_43 ;
V_2 -> V_61 = F_9 ( V_6 -> V_41 ) -> V_61 ;
return NULL ;
}
}
} else {
F_5 ( V_14 L_37 ,
V_6 -> V_13 ) ;
}
F_47 ( V_2 ) ;
return NULL ;
}
int T_6 F_50 ( struct V_15 * V_112 )
{
if ( ! V_112 -> V_113 ) {
F_51 ( L_38 ,
V_114 , V_112 ) ;
return - V_92 ;
}
if ( V_15 && V_15 != V_112 ) {
F_51 ( L_39 ,
V_114 , V_15 -> V_113 , V_112 -> V_113 ) ;
return - V_115 ;
}
V_15 = V_112 ;
return 0 ;
}
int T_7 F_52 ( const char * V_113 )
{
if ( ! V_113 || ! strlen ( V_113 ) ) {
F_51 ( L_40 ,
V_114 ) ;
return - V_92 ;
}
if ( V_15 && ! strcmp ( V_15 -> V_113 , V_113 ) ) {
V_15 = NULL ;
return 0 ;
}
return - V_115 ;
}
void T_6 F_53 ( void )
{
struct V_116 * V_117 , * V_118 ;
struct V_5 * V_96 ;
int V_52 ;
if ( ! V_15 ) {
F_51 ( L_41 ,
V_114 ) ;
return;
} else if ( ( V_52 = V_15 -> V_119 () ) ) {
F_51 ( L_42 ,
V_114 , V_52 ) ;
return;
}
F_54 ( & V_51 ) ;
F_55 (hose, tmp, &hose_list, list_node) {
V_96 = V_117 -> V_6 ;
F_56 ( V_96 , F_48 , NULL ) ;
}
if ( V_57 )
F_5 ( V_120 L_43 ) ;
else
F_5 ( V_14 L_44 ) ;
}
static void F_57 ( struct V_5 * V_6 )
{
struct V_116 * V_96 ;
if ( ! V_6 || ! F_9 ( V_6 ) )
return;
V_96 = F_9 ( V_6 ) -> V_96 ;
if ( NULL == V_96 || 0 == V_96 -> V_121 )
return;
F_48 ( V_6 , NULL ) ;
}
void F_58 ( struct V_5 * V_6 )
{
struct V_5 * V_122 ;
F_8 (dn, sib)
F_58 ( V_122 ) ;
F_57 ( V_6 ) ;
}
static void F_59 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
if ( ! V_8 || ! V_57 )
return;
F_25 ( L_45 , F_60 ( V_8 ) ) ;
V_6 = F_33 ( V_8 ) ;
V_2 = F_9 ( V_6 ) ;
if ( V_2 -> V_45 == V_8 ) {
F_25 ( L_46 ) ;
return;
}
F_61 ( V_2 -> V_45 ) ;
F_62 ( V_8 ) ;
V_2 -> V_45 = V_8 ;
V_8 -> V_8 . V_123 . V_2 = V_2 ;
F_63 ( V_8 ) ;
F_64 ( V_8 ) ;
}
void F_65 ( struct V_124 * V_125 )
{
struct V_7 * V_8 ;
F_66 (dev, &bus->devices, bus_list) {
F_59 ( V_8 ) ;
if ( V_8 -> V_126 == V_127 ) {
struct V_124 * V_128 = V_8 -> V_129 ;
if ( V_128 )
F_65 ( V_128 ) ;
}
}
}
static void F_67 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
if ( ! V_8 || ! V_57 )
return;
V_2 = F_68 ( V_8 ) ;
F_25 ( L_47 , F_60 ( V_8 ) ) ;
if ( ! V_2 || ! V_2 -> V_45 ) {
F_25 ( L_48 ) ;
return;
}
V_2 -> V_45 = NULL ;
V_8 -> V_8 . V_123 . V_2 = NULL ;
F_34 ( V_8 ) ;
F_69 ( V_8 ) ;
F_70 ( V_8 ) ;
}
void F_71 ( struct V_7 * V_8 )
{
struct V_124 * V_125 = V_8 -> V_129 ;
struct V_7 * V_26 , * V_118 ;
F_67 ( V_8 ) ;
if ( V_125 && V_8 -> V_126 == V_127 ) {
F_55 (child, tmp, &bus->devices, bus_list)
F_71 ( V_26 ) ;
}
}
static int F_72 ( struct V_130 * V_131 , void * V_132 )
{
if ( 0 == V_57 ) {
F_73 ( V_131 , L_49 ) ;
F_73 ( V_131 , L_50 , V_55 . V_56 ) ;
} else {
F_73 ( V_131 , L_51 ) ;
F_73 ( V_131 ,
L_52
L_53
L_54
L_55
L_50
L_56
L_57 ,
V_55 . V_77 ,
V_55 . V_58 ,
V_55 . V_63 ,
V_55 . V_60 ,
V_55 . V_56 ,
V_55 . V_72 ,
V_55 . V_73 ) ;
}
return 0 ;
}
static int F_74 ( struct V_133 * V_133 , struct V_134 * V_134 )
{
return F_75 ( V_134 , F_72 , NULL ) ;
}
static int T_6 F_76 ( void )
{
if ( F_77 ( V_135 ) )
F_78 ( L_58 , 0 , NULL , & V_136 ) ;
return 0 ;
}
