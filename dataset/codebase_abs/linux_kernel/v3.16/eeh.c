static int T_1 F_1 ( char * V_1 )
{
if ( ! strcmp ( V_1 , L_1 ) )
V_2 |= V_3 ;
return 1 ;
}
static T_2 F_2 ( struct V_4 * V_5 , char * V_6 , T_2 V_7 )
{
struct V_8 * V_9 = F_3 ( V_5 ) ;
T_3 V_10 ;
int V_11 , V_12 ;
int V_13 = 0 ;
V_13 += F_4 ( V_6 + V_13 , V_7 - V_13 , L_2 , V_9 -> V_14 ) ;
F_5 ( L_3 , V_9 -> V_14 ) ;
V_15 -> V_16 ( V_9 , V_17 , 4 , & V_10 ) ;
V_13 += F_4 ( V_6 + V_13 , V_7 - V_13 , L_4 , V_10 ) ;
F_5 ( L_5 , V_10 ) ;
V_15 -> V_16 ( V_9 , V_18 , 4 , & V_10 ) ;
V_13 += F_4 ( V_6 + V_13 , V_7 - V_13 , L_6 , V_10 ) ;
F_5 ( L_7 , V_10 ) ;
if ( V_5 -> V_19 & V_20 ) {
V_15 -> V_16 ( V_9 , V_21 , 2 , & V_10 ) ;
V_13 += F_4 ( V_6 + V_13 , V_7 - V_13 , L_8 , V_10 ) ;
F_5 ( L_9 , V_10 ) ;
V_15 -> V_16 ( V_9 , V_22 , 2 , & V_10 ) ;
V_13 += F_4 ( V_6 + V_13 , V_7 - V_13 , L_10 , V_10 ) ;
F_5 ( L_11 , V_10 ) ;
}
V_11 = V_5 -> V_23 ;
if ( V_11 ) {
V_15 -> V_16 ( V_9 , V_11 , 4 , & V_10 ) ;
V_13 += F_4 ( V_6 + V_13 , V_7 - V_13 , L_12 , V_10 ) ;
F_5 ( L_13 , V_10 ) ;
V_15 -> V_16 ( V_9 , V_11 + 4 , 4 , & V_10 ) ;
V_13 += F_4 ( V_6 + V_13 , V_7 - V_13 , L_14 , V_10 ) ;
F_5 ( L_15 , V_10 ) ;
}
V_11 = V_5 -> V_24 ;
if ( V_11 ) {
V_13 += F_4 ( V_6 + V_13 , V_7 - V_13 , L_16 ) ;
F_5 ( L_17 ) ;
for ( V_12 = 0 ; V_12 <= 8 ; V_12 ++ ) {
V_15 -> V_16 ( V_9 , V_11 + 4 * V_12 , 4 , & V_10 ) ;
V_13 += F_4 ( V_6 + V_13 , V_7 - V_13 , L_18 , 4 * V_12 , V_10 ) ;
F_5 ( L_19 , V_12 , V_10 ) ;
}
}
V_11 = V_5 -> V_25 ;
if ( V_11 ) {
V_13 += F_4 ( V_6 + V_13 , V_7 - V_13 , L_20 ) ;
F_5 ( L_21 ) ;
for ( V_12 = 0 ; V_12 < 14 ; V_12 ++ ) {
V_15 -> V_16 ( V_9 , V_11 + 4 * V_12 , 4 , & V_10 ) ;
V_13 += F_4 ( V_6 + V_13 , V_7 - V_13 , L_18 , 4 * V_12 , V_10 ) ;
F_5 ( L_22 , V_12 , V_10 ) ;
}
}
return V_13 ;
}
void F_6 ( struct V_26 * V_27 , int V_28 )
{
T_2 V_29 = 0 ;
struct V_4 * V_5 , * V_30 ;
if ( ! ( V_27 -> type & V_31 ) ) {
if ( F_7 () )
F_8 ( V_27 , V_32 ) ;
V_15 -> V_33 ( V_27 ) ;
F_9 ( V_27 ) ;
V_34 [ 0 ] = 0 ;
F_10 (pe, edev, tmp) {
V_29 += F_2 ( V_5 , V_34 + V_29 ,
V_35 - V_29 ) ;
}
}
V_15 -> V_36 ( V_27 , V_28 , V_34 , V_29 ) ;
}
static inline unsigned long F_11 ( unsigned long V_37 )
{
T_4 * V_38 ;
unsigned long V_39 ;
int V_40 ;
V_38 = F_12 ( V_41 . V_42 , V_37 , & V_40 ) ;
if ( ! V_38 )
return V_37 ;
F_13 ( V_40 ) ;
V_39 = F_14 ( * V_38 ) << V_43 ;
return V_39 | ( V_37 & ( V_44 - 1 ) ) ;
}
static int F_15 ( struct V_26 * V_27 )
{
struct V_26 * V_45 ;
unsigned long V_46 ;
int V_47 ;
if ( ! F_16 () )
return - V_48 ;
V_45 = F_17 ( V_27 -> V_49 ) ;
if ( ! V_45 ) {
F_18 ( L_23 ,
V_50 , V_27 -> V_49 -> V_51 ) ;
return - V_52 ;
}
F_19 ( & V_46 ) ;
if ( V_45 -> V_53 & V_54 ) {
V_47 = 0 ;
goto V_55;
}
V_47 = V_15 -> V_56 ( V_45 , NULL ) ;
if ( ( V_47 < 0 ) ||
( V_47 == V_57 ) ||
( V_47 & ( V_58 | V_59 ) ) ==
( V_58 | V_59 ) ) {
V_47 = 0 ;
goto V_55;
}
F_20 ( V_45 , V_54 ) ;
F_21 ( V_46 ) ;
F_22 ( L_24 ,
V_45 -> V_49 -> V_51 , F_23 ( V_45 ) ) ;
F_24 () ;
F_25 ( V_45 ) ;
return 1 ;
V_55:
F_21 ( V_46 ) ;
return V_47 ;
}
int F_26 ( struct V_4 * V_5 )
{
int V_47 ;
int V_60 = ( V_58 | V_59 ) ;
unsigned long V_46 ;
struct V_8 * V_9 ;
struct V_61 * V_62 ;
struct V_26 * V_27 , * V_63 , * V_45 ;
int V_64 = 0 ;
const char * V_65 ;
V_66 . V_67 ++ ;
if ( ! F_27 () )
return 0 ;
if ( ! V_5 ) {
V_66 . V_68 ++ ;
return 0 ;
}
V_9 = F_3 ( V_5 ) ;
V_62 = F_28 ( V_5 ) ;
V_27 = V_5 -> V_27 ;
if ( ! V_27 ) {
V_66 . V_69 ++ ;
F_29 ( L_25 ,
F_30 ( V_62 ) , V_9 -> V_14 ) ;
return 0 ;
}
if ( ! V_27 -> V_70 && ! V_27 -> V_71 ) {
V_66 . V_72 ++ ;
return 0 ;
}
V_47 = F_15 ( V_27 ) ;
if ( V_47 > 0 )
return V_47 ;
F_19 ( & V_46 ) ;
V_64 = 1 ;
if ( V_27 -> V_53 & V_54 ) {
V_27 -> V_73 ++ ;
if ( V_27 -> V_73 % V_74 == 0 ) {
V_65 = F_31 ( V_9 , L_26 , NULL ) ;
F_32 ( V_75 L_27
L_28 ,
V_27 -> V_73 , V_65 ,
F_33 ( V_62 ) , F_30 ( V_62 ) ) ;
F_32 ( V_75 L_29 ,
F_33 ( V_62 ) ) ;
F_24 () ;
}
goto V_76;
}
V_47 = V_15 -> V_56 ( V_27 , NULL ) ;
if ( ( V_47 < 0 ) ||
( V_47 == V_57 ) ||
( ( V_47 & V_60 ) == V_60 ) ) {
V_66 . V_77 ++ ;
V_27 -> V_77 ++ ;
V_64 = 0 ;
goto V_76;
}
V_63 = V_27 -> V_78 ;
while ( V_63 ) {
if ( V_63 -> type & V_31 )
break;
V_47 = V_15 -> V_56 ( V_63 , NULL ) ;
if ( V_47 > 0 &&
( V_47 & V_60 ) != V_60 )
V_27 = V_63 ;
V_63 = V_63 -> V_78 ;
}
V_66 . V_79 ++ ;
F_20 ( V_27 , V_54 ) ;
F_21 ( V_46 ) ;
V_45 = F_17 ( V_27 -> V_49 ) ;
F_22 ( L_30 ,
V_27 -> V_49 -> V_51 , V_27 -> V_70 ) ;
F_22 ( L_31 ,
F_23 ( V_27 ) , F_23 ( V_45 ) ) ;
F_24 () ;
F_25 ( V_27 ) ;
return 1 ;
V_76:
F_21 ( V_46 ) ;
return V_64 ;
}
unsigned long F_34 ( const volatile void T_5 * V_37 , unsigned long V_80 )
{
unsigned long V_70 ;
struct V_4 * V_5 ;
V_70 = F_11 ( ( unsigned long V_81 ) V_37 ) ;
V_5 = F_35 ( V_70 ) ;
if ( ! V_5 ) {
V_66 . V_82 ++ ;
return V_80 ;
}
F_26 ( V_5 ) ;
return V_80 ;
}
int F_8 ( struct V_26 * V_27 , int V_83 )
{
int V_64 , V_46 = ( V_58 | V_59 ) ;
if ( V_83 == V_32 ||
V_83 == V_84 ) {
V_64 = V_15 -> V_56 ( V_27 , NULL ) ;
if ( V_64 < 0 )
return V_64 ;
if ( ( V_64 == V_57 ) ||
( ( V_64 & V_46 ) == V_46 ) )
return 0 ;
}
V_64 = V_15 -> V_85 ( V_27 , V_83 ) ;
if ( V_64 )
F_5 ( L_32
L_33 ,
V_50 , V_83 , V_27 -> V_49 -> V_51 ,
V_27 -> V_70 , V_64 ) ;
V_64 = V_15 -> V_86 ( V_27 , V_87 ) ;
if ( V_64 <= 0 )
return V_64 ;
if ( ( V_83 == V_32 ) &&
( V_64 & V_88 ) )
return 0 ;
if ( ( V_83 == V_84 ) &&
( V_64 & V_89 ) )
return 0 ;
return V_64 ;
}
int F_36 ( struct V_61 * V_62 , enum V_90 V_53 )
{
struct V_4 * V_5 = F_37 ( V_62 ) ;
struct V_26 * V_27 = V_5 -> V_27 ;
if ( ! V_27 ) {
F_22 ( L_34 ,
V_50 , F_38 ( V_62 ) ) ;
return - V_91 ;
}
switch ( V_53 ) {
case V_92 :
V_15 -> V_93 ( V_27 , V_94 ) ;
break;
case V_95 :
V_15 -> V_93 ( V_27 , V_96 ) ;
break;
case V_97 :
V_15 -> V_93 ( V_27 , V_98 ) ;
break;
default:
return - V_91 ;
} ;
return 0 ;
}
static void * F_39 ( void * V_99 , void * V_100 )
{
struct V_61 * V_62 ;
unsigned int * V_101 = ( unsigned int * ) V_100 ;
struct V_4 * V_5 = (struct V_4 * ) V_99 ;
V_62 = F_28 ( V_5 ) ;
if ( V_62 )
* V_101 |= V_62 -> V_102 ;
return NULL ;
}
static void F_40 ( struct V_26 * V_27 )
{
unsigned int V_101 = 0 ;
F_41 ( V_27 , F_39 , & V_101 ) ;
if ( V_101 )
V_15 -> V_93 ( V_27 , V_98 ) ;
else
V_15 -> V_93 ( V_27 , V_96 ) ;
V_15 -> V_93 ( V_27 , V_94 ) ;
}
int F_42 ( struct V_26 * V_27 )
{
int V_46 = ( V_58 | V_59 ) ;
int V_12 , V_64 ;
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ ) {
F_40 ( V_27 ) ;
V_64 = V_15 -> V_86 ( V_27 , V_87 ) ;
if ( ( V_64 & V_46 ) == V_46 )
return 0 ;
if ( V_64 < 0 ) {
F_22 ( L_35 ,
V_50 , V_27 -> V_49 -> V_51 , V_27 -> V_70 ) ;
return - 1 ;
}
F_22 ( L_36 ,
V_12 + 1 , V_27 -> V_49 -> V_51 , V_27 -> V_70 , V_64 ) ;
}
return - 1 ;
}
void F_43 ( struct V_4 * V_5 )
{
int V_12 ;
struct V_8 * V_9 ;
if ( ! V_5 )
return;
V_9 = F_3 ( V_5 ) ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ )
V_15 -> V_16 ( V_9 , V_12 * 4 , 4 , & V_5 -> V_103 [ V_12 ] ) ;
if ( V_5 -> V_19 & V_20 )
V_5 -> V_103 [ 1 ] |= V_104 ;
}
int T_1 F_44 ( struct V_15 * V_105 )
{
if ( ! V_105 -> V_106 ) {
F_18 ( L_37 ,
V_50 , V_105 ) ;
return - V_91 ;
}
if ( V_15 && V_15 != V_105 ) {
F_18 ( L_38 ,
V_50 , V_15 -> V_106 , V_105 -> V_106 ) ;
return - V_52 ;
}
V_15 = V_105 ;
return 0 ;
}
int T_6 F_45 ( const char * V_106 )
{
if ( ! V_106 || ! strlen ( V_106 ) ) {
F_18 ( L_39 ,
V_50 ) ;
return - V_91 ;
}
if ( V_15 && ! strcmp ( V_15 -> V_106 , V_106 ) ) {
V_15 = NULL ;
return 0 ;
}
return - V_52 ;
}
static int F_46 ( struct V_107 * V_108 ,
unsigned long V_109 , void * V_110 )
{
F_47 ( false ) ;
return V_111 ;
}
int F_48 ( void )
{
struct V_112 * V_113 , * V_30 ;
struct V_8 * V_49 ;
static int V_114 = 0 ;
int V_47 = 0 ;
if ( F_49 ( V_115 ) && V_114 ++ <= 0 )
return V_47 ;
V_47 = F_50 ( & V_116 ) ;
if ( V_47 ) {
F_5 ( L_40 ,
V_50 , V_47 ) ;
return V_47 ;
}
if ( ! V_15 ) {
F_18 ( L_41 ,
V_50 ) ;
return - V_52 ;
} else if ( ( V_47 = V_15 -> V_117 () ) ) {
F_18 ( L_42 ,
V_50 , V_47 ) ;
return V_47 ;
}
V_47 = F_51 () ;
if ( V_47 )
return V_47 ;
if ( F_7 () ) {
F_52 (hose, tmp,
&hose_list, list_node) {
V_49 = V_113 -> V_9 ;
F_53 ( V_49 , V_15 -> V_118 , NULL ) ;
}
} else if ( F_16 () ) {
F_52 (hose, tmp,
&hose_list, list_node)
F_54 ( V_113 -> V_119 , V_15 -> V_120 , NULL ) ;
} else {
F_5 ( L_43 ,
V_50 , V_2 ) ;
return - V_91 ;
}
if ( V_15 -> V_121 ) {
V_47 = V_15 -> V_121 () ;
if ( V_47 )
return V_47 ;
}
if ( F_27 () )
F_55 ( L_44 ) ;
else
F_18 ( L_45 ) ;
return V_47 ;
}
void F_56 ( struct V_8 * V_9 )
{
struct V_112 * V_49 ;
if ( ! F_7 () )
return;
if ( ! F_57 ( V_9 ) )
return;
V_49 = F_57 ( V_9 ) -> V_49 ;
if ( NULL == V_49 || 0 == V_49 -> V_122 )
return;
V_15 -> V_118 ( V_9 , NULL ) ;
}
void F_58 ( struct V_8 * V_9 )
{
struct V_8 * V_123 ;
F_59 (dn, sib)
F_58 ( V_123 ) ;
F_56 ( V_9 ) ;
}
void F_60 ( struct V_61 * V_62 )
{
struct V_8 * V_9 ;
struct V_4 * V_5 ;
if ( ! V_62 || ! F_27 () )
return;
F_29 ( L_46 , F_38 ( V_62 ) ) ;
V_9 = F_61 ( V_62 ) ;
V_5 = F_57 ( V_9 ) ;
if ( V_5 -> V_124 == V_62 ) {
F_29 ( L_47 ) ;
return;
}
if ( V_5 -> V_124 ) {
F_62 ( V_5 ) ;
F_63 ( V_5 -> V_124 ) ;
F_64 ( V_5 -> V_124 ) ;
V_5 -> V_19 &= ~ V_125 ;
V_5 -> V_19 |= V_126 ;
V_5 -> V_124 = NULL ;
V_62 -> V_62 . V_127 . V_5 = NULL ;
}
V_5 -> V_124 = V_62 ;
V_62 -> V_62 . V_127 . V_5 = V_5 ;
if ( F_16 () )
V_15 -> V_120 ( V_62 , NULL ) ;
F_65 ( V_62 ) ;
}
void F_66 ( struct V_128 * V_119 )
{
struct V_61 * V_62 ;
F_67 (dev, &bus->devices, bus_list) {
F_60 ( V_62 ) ;
if ( V_62 -> V_129 == V_130 ) {
struct V_128 * V_131 = V_62 -> V_132 ;
if ( V_131 )
F_66 ( V_131 ) ;
}
}
}
void F_68 ( struct V_128 * V_119 )
{
struct V_61 * V_62 ;
F_67 (dev, &bus->devices, bus_list) {
F_69 ( V_62 ) ;
if ( V_62 -> V_129 == V_130 ) {
struct V_128 * V_131 = V_62 -> V_132 ;
if ( V_131 )
F_68 ( V_131 ) ;
}
}
}
void F_70 ( struct V_61 * V_62 )
{
struct V_4 * V_5 ;
if ( ! V_62 || ! F_27 () )
return;
V_5 = F_37 ( V_62 ) ;
F_29 ( L_48 , F_38 ( V_62 ) ) ;
if ( ! V_5 || ! V_5 -> V_124 || ! V_5 -> V_27 ) {
F_29 ( L_49 ) ;
return;
}
V_5 -> V_124 = NULL ;
V_62 -> V_62 . V_127 . V_5 = NULL ;
if ( ! ( V_5 -> V_27 -> V_53 & V_133 ) )
F_62 ( V_5 ) ;
else
V_5 -> V_19 |= V_134 ;
V_5 -> V_19 |= V_126 ;
F_63 ( V_62 ) ;
F_64 ( V_62 ) ;
V_5 -> V_19 &= ~ V_125 ;
}
static int F_71 ( struct V_135 * V_136 , void * V_137 )
{
if ( ! F_27 () ) {
F_72 ( V_136 , L_50 ) ;
F_72 ( V_136 , L_51 , V_66 . V_67 ) ;
} else {
F_72 ( V_136 , L_52 ) ;
F_72 ( V_136 ,
L_53
L_54
L_55
L_56
L_51
L_57
L_58 ,
V_66 . V_82 ,
V_66 . V_68 ,
V_66 . V_72 ,
V_66 . V_69 ,
V_66 . V_67 ,
V_66 . V_77 ,
V_66 . V_79 ) ;
}
return 0 ;
}
static int F_73 ( struct V_138 * V_138 , struct V_139 * V_139 )
{
return F_74 ( V_139 , F_71 , NULL ) ;
}
static int F_75 ( void * V_99 , T_7 V_80 )
{
if ( V_80 )
V_2 &= ~ V_3 ;
else
V_2 |= V_3 ;
if ( V_15 -> V_121 )
V_15 -> V_121 () ;
return 0 ;
}
static int F_76 ( void * V_99 , T_7 * V_80 )
{
if ( F_27 () )
* V_80 = 0x1ul ;
else
* V_80 = 0x0ul ;
return 0 ;
}
static int T_1 F_77 ( void )
{
if ( F_49 ( V_140 ) || F_49 ( V_115 ) ) {
F_78 ( L_59 , 0 , NULL , & V_141 ) ;
#ifdef F_79
F_80 ( L_60 , 0600 ,
V_142 , NULL ,
& V_143 ) ;
#endif
}
return 0 ;
}
