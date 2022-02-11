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
if ( F_7 ( V_8 ) ) {
V_12 += F_4 ( V_3 + V_12 , V_4 - V_12 , L_16 ) ;
F_5 ( V_14
L_17 ) ;
for ( V_11 = 0 ; V_11 <= 8 ; V_11 ++ ) {
V_15 -> V_16 ( V_6 , V_8 -> V_24 + 4 * V_11 , 4 , & V_9 ) ;
V_12 += F_4 ( V_3 + V_12 , V_4 - V_12 , L_18 , 4 * V_11 , V_9 ) ;
F_5 ( V_14 L_19 , V_11 , V_9 ) ;
}
V_10 = F_8 ( V_8 , V_25 ) ;
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
return V_12 ;
}
void F_9 ( struct V_26 * V_27 , int V_28 )
{
T_1 V_29 = 0 ;
struct V_1 * V_2 , * V_30 ;
bool V_31 = true ;
if ( F_10 () &&
( V_27 -> type & V_32 ) &&
( V_27 -> V_33 & ( V_34 | V_35 ) ) )
V_31 = false ;
if ( V_31 ) {
F_11 ( V_27 , V_36 ) ;
V_15 -> V_37 ( V_27 ) ;
F_12 ( V_27 ) ;
V_38 [ 0 ] = 0 ;
F_13 (pe, edev, tmp) {
V_29 += F_1 ( V_2 , V_38 + V_29 ,
V_39 - V_29 ) ;
}
}
V_15 -> V_40 ( V_27 , V_28 , V_38 , V_29 ) ;
}
static inline unsigned long F_14 ( unsigned long V_41 )
{
T_3 * V_42 ;
unsigned long V_43 ;
int V_44 ;
V_42 = F_15 ( V_45 . V_46 , V_41 , & V_44 ) ;
if ( ! V_42 )
return V_41 ;
F_16 ( V_44 ) ;
V_43 = F_17 ( * V_42 ) << V_47 ;
return V_43 | ( V_41 & ( V_48 - 1 ) ) ;
}
static int F_18 ( struct V_26 * V_27 )
{
struct V_26 * V_49 ;
unsigned long V_50 ;
int V_51 ;
if ( ! F_10 () )
return - V_52 ;
V_49 = F_19 ( V_27 -> V_53 ) ;
if ( ! V_49 ) {
F_20 ( L_23 ,
V_54 , V_27 -> V_53 -> V_55 ) ;
return - V_56 ;
}
F_21 ( & V_50 ) ;
if ( V_49 -> V_33 & ( V_34 | V_35 ) ) {
V_51 = 0 ;
goto V_57;
}
V_51 = V_15 -> V_58 ( V_49 , NULL ) ;
if ( ( V_51 < 0 ) ||
( V_51 == V_59 ) ||
( V_51 & ( V_60 | V_61 ) ) ==
( V_60 | V_61 ) ) {
V_51 = 0 ;
goto V_57;
}
F_22 ( V_49 , V_34 ) ;
F_23 ( V_50 ) ;
F_24 ( L_24 ,
V_49 -> V_53 -> V_55 ) ;
F_25 () ;
F_26 ( V_49 ) ;
return 1 ;
V_57:
F_23 ( V_50 ) ;
return V_51 ;
}
int F_27 ( struct V_1 * V_2 )
{
int V_51 ;
unsigned long V_50 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_26 * V_27 ;
int V_62 = 0 ;
const char * V_63 ;
V_64 . V_65 ++ ;
if ( ! F_28 () )
return 0 ;
if ( ! V_2 ) {
V_64 . V_66 ++ ;
return 0 ;
}
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
V_27 = V_2 -> V_27 ;
if ( ! V_27 ) {
V_64 . V_67 ++ ;
F_29 ( L_25 ,
F_30 ( V_8 ) , V_6 -> V_13 ) ;
return 0 ;
}
if ( ! V_27 -> V_68 && ! V_27 -> V_69 ) {
V_64 . V_70 ++ ;
return 0 ;
}
V_51 = F_18 ( V_27 ) ;
if ( V_51 > 0 )
return V_51 ;
F_21 ( & V_50 ) ;
V_62 = 1 ;
if ( V_27 -> V_33 & V_34 ) {
V_27 -> V_71 ++ ;
if ( V_27 -> V_71 % V_72 == 0 ) {
V_63 = F_31 ( V_6 , L_26 , NULL ) ;
F_5 ( V_73 L_27
L_28 ,
V_27 -> V_71 , V_63 ,
F_32 ( V_8 ) , F_30 ( V_8 ) ) ;
F_5 ( V_73 L_29 ,
F_32 ( V_8 ) ) ;
F_25 () ;
}
goto V_74;
}
V_51 = V_15 -> V_58 ( V_27 , NULL ) ;
if ( ( V_51 < 0 ) ||
( V_51 == V_59 ) ||
( V_51 & ( V_60 | V_61 ) ) ==
( V_60 | V_61 ) ) {
V_64 . V_75 ++ ;
V_27 -> V_75 ++ ;
V_62 = 0 ;
goto V_74;
}
V_64 . V_76 ++ ;
F_22 ( V_27 , V_34 ) ;
F_23 ( V_50 ) ;
F_24 ( L_30 ,
V_27 -> V_68 , V_27 -> V_53 -> V_55 ) ;
F_25 () ;
F_26 ( V_27 ) ;
return 1 ;
V_74:
F_23 ( V_50 ) ;
return V_62 ;
}
unsigned long F_33 ( const volatile void T_4 * V_41 , unsigned long V_77 )
{
unsigned long V_68 ;
struct V_1 * V_2 ;
V_68 = F_14 ( ( unsigned long V_78 ) V_41 ) ;
V_2 = F_34 ( V_68 ) ;
if ( ! V_2 ) {
V_64 . V_79 ++ ;
return V_77 ;
}
F_27 ( V_2 ) ;
return V_77 ;
}
int F_11 ( struct V_26 * V_27 , int V_80 )
{
int V_62 ;
V_62 = V_15 -> V_81 ( V_27 , V_80 ) ;
if ( V_62 )
F_20 ( L_31 ,
V_54 , V_80 , V_27 -> V_53 -> V_55 , V_27 -> V_68 , V_62 ) ;
V_62 = V_15 -> V_82 ( V_27 , V_83 ) ;
if ( V_62 > 0 && ( V_62 & V_84 ) &&
( V_80 == V_36 ) )
return 0 ;
return V_62 ;
}
int F_35 ( struct V_7 * V_8 , enum V_85 V_33 )
{
struct V_1 * V_2 = F_36 ( V_8 ) ;
struct V_26 * V_27 = V_2 -> V_27 ;
if ( ! V_27 ) {
F_24 ( L_32 ,
V_54 , F_37 ( V_8 ) ) ;
return - V_86 ;
}
switch ( V_33 ) {
case V_87 :
V_15 -> V_88 ( V_27 , V_89 ) ;
break;
case V_90 :
V_15 -> V_88 ( V_27 , V_91 ) ;
break;
case V_92 :
V_15 -> V_88 ( V_27 , V_93 ) ;
break;
default:
return - V_86 ;
} ;
return 0 ;
}
static void * F_38 ( void * V_94 , void * V_95 )
{
struct V_7 * V_8 ;
unsigned int * V_96 = ( unsigned int * ) V_95 ;
struct V_1 * V_2 = (struct V_1 * ) V_94 ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 )
* V_96 |= V_8 -> V_97 ;
return NULL ;
}
static void F_39 ( struct V_26 * V_27 )
{
unsigned int V_96 = 0 ;
F_40 ( V_27 , F_38 , & V_96 ) ;
if ( V_96 )
V_15 -> V_88 ( V_27 , V_93 ) ;
else
V_15 -> V_88 ( V_27 , V_91 ) ;
#define F_41 250
F_42 ( F_41 ) ;
F_43 ( V_27 , V_34 ) ;
V_15 -> V_88 ( V_27 , V_89 ) ;
#define F_44 1800
F_42 ( F_44 ) ;
}
int F_45 ( struct V_26 * V_27 )
{
int V_50 = ( V_60 | V_61 ) ;
int V_11 , V_62 ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
F_39 ( V_27 ) ;
V_62 = V_15 -> V_82 ( V_27 , V_83 ) ;
if ( ( V_62 & V_50 ) == V_50 )
return 0 ;
if ( V_62 < 0 ) {
F_24 ( L_33 ,
V_54 , V_27 -> V_53 -> V_55 , V_27 -> V_68 ) ;
return - 1 ;
}
F_24 ( L_34 ,
V_11 + 1 , V_27 -> V_53 -> V_55 , V_27 -> V_68 , V_62 ) ;
}
return - 1 ;
}
void F_46 ( struct V_1 * V_2 )
{
int V_11 ;
struct V_5 * V_6 ;
if ( ! V_2 )
return;
V_6 = F_2 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
V_15 -> V_16 ( V_6 , V_11 * 4 , 4 , & V_2 -> V_98 [ V_11 ] ) ;
if ( V_2 -> V_99 & V_100 )
V_2 -> V_98 [ 1 ] |= V_101 ;
}
int T_5 F_47 ( struct V_15 * V_102 )
{
if ( ! V_102 -> V_103 ) {
F_20 ( L_35 ,
V_54 , V_102 ) ;
return - V_86 ;
}
if ( V_15 && V_15 != V_102 ) {
F_20 ( L_36 ,
V_54 , V_15 -> V_103 , V_102 -> V_103 ) ;
return - V_56 ;
}
V_15 = V_102 ;
return 0 ;
}
int T_6 F_48 ( const char * V_103 )
{
if ( ! V_103 || ! strlen ( V_103 ) ) {
F_20 ( L_37 ,
V_54 ) ;
return - V_86 ;
}
if ( V_15 && ! strcmp ( V_15 -> V_103 , V_103 ) ) {
V_15 = NULL ;
return 0 ;
}
return - V_56 ;
}
static int F_49 ( struct V_104 * V_105 ,
unsigned long V_106 , void * V_107 )
{
F_50 ( false ) ;
return V_108 ;
}
int F_51 ( void )
{
struct V_109 * V_110 , * V_30 ;
struct V_5 * V_53 ;
static int V_111 = 0 ;
int V_51 = 0 ;
if ( F_52 ( V_112 ) && V_111 ++ <= 0 )
return V_51 ;
V_51 = F_53 ( & V_113 ) ;
if ( V_51 ) {
F_54 ( L_38 ,
V_54 , V_51 ) ;
return V_51 ;
}
if ( ! V_15 ) {
F_20 ( L_39 ,
V_54 ) ;
return - V_56 ;
} else if ( ( V_51 = V_15 -> V_114 () ) ) {
F_20 ( L_40 ,
V_54 , V_51 ) ;
return V_51 ;
}
V_51 = F_55 () ;
if ( V_51 )
return V_51 ;
if ( F_56 () ) {
F_57 (hose, tmp,
&hose_list, list_node) {
V_53 = V_110 -> V_6 ;
F_58 ( V_53 , V_15 -> V_115 , NULL ) ;
}
} else if ( F_10 () ) {
F_57 (hose, tmp,
&hose_list, list_node)
F_59 ( V_110 -> V_116 , V_15 -> V_117 , NULL ) ;
} else {
F_20 ( L_41 ,
V_54 , V_118 ) ;
return - V_86 ;
}
if ( V_15 -> V_119 ) {
V_51 = V_15 -> V_119 () ;
if ( V_51 )
return V_51 ;
}
if ( F_28 () )
F_60 ( L_42 ) ;
else
F_20 ( L_43 ) ;
return V_51 ;
}
void F_61 ( struct V_5 * V_6 )
{
struct V_109 * V_53 ;
if ( ! F_56 () )
return;
if ( ! F_62 ( V_6 ) )
return;
V_53 = F_62 ( V_6 ) -> V_53 ;
if ( NULL == V_53 || 0 == V_53 -> V_120 )
return;
V_15 -> V_115 ( V_6 , NULL ) ;
}
void F_63 ( struct V_5 * V_6 )
{
struct V_5 * V_121 ;
F_64 (dn, sib)
F_63 ( V_121 ) ;
F_61 ( V_6 ) ;
}
void F_65 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
if ( ! V_8 || ! F_28 () )
return;
F_29 ( L_44 , F_37 ( V_8 ) ) ;
V_6 = F_66 ( V_8 ) ;
V_2 = F_62 ( V_6 ) ;
if ( V_2 -> V_122 == V_8 ) {
F_29 ( L_45 ) ;
return;
}
if ( V_2 -> V_122 ) {
F_67 ( V_2 ) ;
F_68 ( V_2 -> V_122 ) ;
F_69 ( V_2 -> V_122 ) ;
V_2 -> V_99 &= ~ V_123 ;
V_2 -> V_99 |= V_124 ;
V_2 -> V_122 = NULL ;
V_8 -> V_8 . V_125 . V_2 = NULL ;
}
V_2 -> V_122 = V_8 ;
V_8 -> V_8 . V_125 . V_2 = V_2 ;
if ( F_10 () )
V_15 -> V_117 ( V_8 , NULL ) ;
F_70 ( V_8 ) ;
}
void F_71 ( struct V_126 * V_116 )
{
struct V_7 * V_8 ;
F_72 (dev, &bus->devices, bus_list) {
F_65 ( V_8 ) ;
if ( V_8 -> V_127 == V_128 ) {
struct V_126 * V_129 = V_8 -> V_130 ;
if ( V_129 )
F_71 ( V_129 ) ;
}
}
}
void F_73 ( struct V_126 * V_116 )
{
struct V_7 * V_8 ;
F_72 (dev, &bus->devices, bus_list) {
F_74 ( V_8 ) ;
if ( V_8 -> V_127 == V_128 ) {
struct V_126 * V_129 = V_8 -> V_130 ;
if ( V_129 )
F_73 ( V_129 ) ;
}
}
}
void F_75 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
if ( ! V_8 || ! F_28 () )
return;
V_2 = F_36 ( V_8 ) ;
F_29 ( L_46 , F_37 ( V_8 ) ) ;
if ( ! V_2 || ! V_2 -> V_122 || ! V_2 -> V_27 ) {
F_29 ( L_47 ) ;
return;
}
V_2 -> V_122 = NULL ;
V_8 -> V_8 . V_125 . V_2 = NULL ;
if ( ! ( V_2 -> V_27 -> V_33 & V_131 ) )
F_67 ( V_2 ) ;
else
V_2 -> V_99 |= V_132 ;
V_2 -> V_99 |= V_124 ;
F_68 ( V_8 ) ;
F_69 ( V_8 ) ;
V_2 -> V_99 &= ~ V_123 ;
}
static int F_76 ( struct V_133 * V_134 , void * V_135 )
{
if ( ! F_28 () ) {
F_77 ( V_134 , L_48 ) ;
F_77 ( V_134 , L_49 , V_64 . V_65 ) ;
} else {
F_77 ( V_134 , L_50 ) ;
F_77 ( V_134 ,
L_51
L_52
L_53
L_54
L_49
L_55
L_56 ,
V_64 . V_79 ,
V_64 . V_66 ,
V_64 . V_70 ,
V_64 . V_67 ,
V_64 . V_65 ,
V_64 . V_75 ,
V_64 . V_76 ) ;
}
return 0 ;
}
static int F_78 ( struct V_136 * V_136 , struct V_137 * V_137 )
{
return F_79 ( V_137 , F_76 , NULL ) ;
}
static int T_5 F_80 ( void )
{
if ( F_52 ( V_138 ) || F_52 ( V_112 ) )
F_81 ( L_57 , 0 , NULL , & V_139 ) ;
return 0 ;
}
