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
return V_12 ;
}
void F_8 ( struct V_26 * V_27 , int V_28 )
{
T_1 V_29 = 0 ;
struct V_1 * V_2 , * V_30 ;
bool V_31 = true ;
if ( F_9 () &&
( V_27 -> type & V_32 ) &&
( V_27 -> V_33 & ( V_34 | V_35 ) ) )
V_31 = false ;
if ( V_31 ) {
F_10 ( V_27 , V_36 ) ;
V_15 -> V_37 ( V_27 ) ;
F_11 ( V_27 ) ;
V_38 [ 0 ] = 0 ;
F_12 (pe, edev, tmp) {
V_29 += F_1 ( V_2 , V_38 + V_29 ,
V_39 - V_29 ) ;
}
}
V_15 -> V_40 ( V_27 , V_28 , V_38 , V_29 ) ;
}
static inline unsigned long F_13 ( unsigned long V_41 )
{
T_3 * V_42 ;
unsigned long V_43 ;
int V_44 ;
V_42 = F_14 ( V_45 . V_46 , V_41 , & V_44 ) ;
if ( ! V_42 )
return V_41 ;
F_15 ( V_44 ) ;
V_43 = F_16 ( * V_42 ) << V_47 ;
return V_43 | ( V_41 & ( V_48 - 1 ) ) ;
}
static int F_17 ( struct V_26 * V_27 )
{
struct V_26 * V_49 ;
unsigned long V_50 ;
int V_51 ;
if ( ! F_9 () )
return - V_52 ;
V_49 = F_18 ( V_27 -> V_53 ) ;
if ( ! V_49 ) {
F_19 ( L_23 ,
V_54 , V_27 -> V_53 -> V_55 ) ;
return - V_56 ;
}
F_20 ( & V_50 ) ;
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
F_21 ( V_49 , V_34 ) ;
F_22 ( V_50 ) ;
F_23 ( V_49 ) ;
F_24 ( L_24 ,
V_49 -> V_53 -> V_55 ) ;
F_25 () ;
return 1 ;
V_57:
F_22 ( V_50 ) ;
return V_51 ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_51 ;
unsigned long V_50 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_26 * V_27 ;
int V_62 = 0 ;
const char * V_63 ;
V_64 . V_65 ++ ;
if ( ! V_66 )
return 0 ;
if ( ! V_2 ) {
V_64 . V_67 ++ ;
return 0 ;
}
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
V_27 = V_2 -> V_27 ;
if ( ! V_27 ) {
V_64 . V_68 ++ ;
F_27 ( L_25 ,
F_28 ( V_8 ) , V_6 -> V_13 ) ;
return 0 ;
}
if ( ! V_27 -> V_69 && ! V_27 -> V_70 ) {
V_64 . V_71 ++ ;
return 0 ;
}
V_51 = F_17 ( V_27 ) ;
if ( V_51 > 0 )
return V_51 ;
F_20 ( & V_50 ) ;
V_62 = 1 ;
if ( V_27 -> V_33 & V_34 ) {
V_27 -> V_72 ++ ;
if ( V_27 -> V_72 % V_73 == 0 ) {
V_63 = F_29 ( V_6 , L_26 , NULL ) ;
F_5 ( V_74 L_27
L_28 ,
V_27 -> V_72 , V_63 ,
F_30 ( V_8 ) , F_28 ( V_8 ) ) ;
F_5 ( V_74 L_29 ,
F_30 ( V_8 ) ) ;
F_25 () ;
}
goto V_75;
}
V_51 = V_15 -> V_58 ( V_27 , NULL ) ;
if ( ( V_51 < 0 ) ||
( V_51 == V_59 ) ||
( V_51 & ( V_60 | V_61 ) ) ==
( V_60 | V_61 ) ) {
V_64 . V_76 ++ ;
V_27 -> V_76 ++ ;
V_62 = 0 ;
goto V_75;
}
V_64 . V_77 ++ ;
F_21 ( V_27 , V_34 ) ;
F_22 ( V_50 ) ;
F_23 ( V_27 ) ;
F_24 ( L_30 ,
V_27 -> V_69 , V_27 -> V_53 -> V_55 ) ;
F_25 () ;
return 1 ;
V_75:
F_22 ( V_50 ) ;
return V_62 ;
}
unsigned long F_31 ( const volatile void T_4 * V_41 , unsigned long V_78 )
{
unsigned long V_69 ;
struct V_1 * V_2 ;
V_69 = F_13 ( ( unsigned long V_79 ) V_41 ) ;
V_2 = F_32 ( V_69 ) ;
if ( ! V_2 ) {
V_64 . V_80 ++ ;
return V_78 ;
}
F_26 ( V_2 ) ;
return V_78 ;
}
int F_10 ( struct V_26 * V_27 , int V_81 )
{
int V_62 ;
V_62 = V_15 -> V_82 ( V_27 , V_81 ) ;
if ( V_62 )
F_19 ( L_31 ,
V_54 , V_81 , V_27 -> V_53 -> V_55 , V_27 -> V_69 , V_62 ) ;
V_62 = V_15 -> V_83 ( V_27 , V_84 ) ;
if ( V_62 > 0 && ( V_62 & V_85 ) &&
( V_81 == V_36 ) )
return 0 ;
return V_62 ;
}
int F_33 ( struct V_7 * V_8 , enum V_86 V_33 )
{
struct V_1 * V_2 = F_34 ( V_8 ) ;
struct V_26 * V_27 = V_2 -> V_27 ;
if ( ! V_27 ) {
F_24 ( L_32 ,
V_54 , F_35 ( V_8 ) ) ;
return - V_87 ;
}
switch ( V_33 ) {
case V_88 :
V_15 -> V_89 ( V_27 , V_90 ) ;
break;
case V_91 :
V_15 -> V_89 ( V_27 , V_92 ) ;
break;
case V_93 :
V_15 -> V_89 ( V_27 , V_94 ) ;
break;
default:
return - V_87 ;
} ;
return 0 ;
}
static void * F_36 ( void * V_95 , void * V_96 )
{
struct V_7 * V_8 ;
unsigned int * V_97 = ( unsigned int * ) V_96 ;
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 )
* V_97 |= V_8 -> V_98 ;
return NULL ;
}
static void F_37 ( struct V_26 * V_27 )
{
unsigned int V_97 = 0 ;
F_38 ( V_27 , F_36 , & V_97 ) ;
if ( V_97 )
V_15 -> V_89 ( V_27 , V_94 ) ;
else
V_15 -> V_89 ( V_27 , V_92 ) ;
#define F_39 250
F_40 ( F_39 ) ;
F_41 ( V_27 , V_34 ) ;
V_15 -> V_89 ( V_27 , V_90 ) ;
#define F_42 1800
F_40 ( F_42 ) ;
}
int F_43 ( struct V_26 * V_27 )
{
int V_50 = ( V_60 | V_61 ) ;
int V_11 , V_62 ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
F_37 ( V_27 ) ;
V_62 = V_15 -> V_83 ( V_27 , V_84 ) ;
if ( ( V_62 & V_50 ) == V_50 )
return 0 ;
if ( V_62 < 0 ) {
F_24 ( L_33 ,
V_54 , V_27 -> V_53 -> V_55 , V_27 -> V_69 ) ;
return - 1 ;
}
F_24 ( L_34 ,
V_11 + 1 , V_27 -> V_53 -> V_55 , V_27 -> V_69 , V_62 ) ;
}
return - 1 ;
}
void F_44 ( struct V_1 * V_2 )
{
int V_11 ;
struct V_5 * V_6 ;
if ( ! V_2 )
return;
V_6 = F_2 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
V_15 -> V_16 ( V_6 , V_11 * 4 , 4 , & V_2 -> V_99 [ V_11 ] ) ;
}
int T_5 F_45 ( struct V_15 * V_100 )
{
if ( ! V_100 -> V_101 ) {
F_19 ( L_35 ,
V_54 , V_100 ) ;
return - V_87 ;
}
if ( V_15 && V_15 != V_100 ) {
F_19 ( L_36 ,
V_54 , V_15 -> V_101 , V_100 -> V_101 ) ;
return - V_56 ;
}
V_15 = V_100 ;
return 0 ;
}
int T_6 F_46 ( const char * V_101 )
{
if ( ! V_101 || ! strlen ( V_101 ) ) {
F_19 ( L_37 ,
V_54 ) ;
return - V_87 ;
}
if ( V_15 && ! strcmp ( V_15 -> V_101 , V_101 ) ) {
V_15 = NULL ;
return 0 ;
}
return - V_56 ;
}
int F_47 ( void )
{
struct V_102 * V_103 , * V_30 ;
struct V_5 * V_53 ;
static int V_104 = 0 ;
int V_51 = 0 ;
if ( F_48 ( V_105 ) && V_104 ++ <= 0 )
return V_51 ;
if ( ! V_15 ) {
F_19 ( L_38 ,
V_54 ) ;
return - V_56 ;
} else if ( ( V_51 = V_15 -> V_106 () ) ) {
F_19 ( L_39 ,
V_54 , V_51 ) ;
return V_51 ;
}
V_51 = F_49 () ;
if ( V_51 )
return V_51 ;
if ( F_50 () ) {
F_51 (hose, tmp,
&hose_list, list_node) {
V_53 = V_103 -> V_6 ;
F_52 ( V_53 , V_15 -> V_107 , NULL ) ;
}
} else if ( F_9 () ) {
F_51 (hose, tmp,
&hose_list, list_node)
F_53 ( V_103 -> V_108 , V_15 -> V_109 , NULL ) ;
} else {
F_19 ( L_40 ,
V_54 , V_110 ) ;
return - V_87 ;
}
if ( V_15 -> V_111 ) {
V_51 = V_15 -> V_111 () ;
if ( V_51 )
return V_51 ;
}
if ( V_66 )
F_54 ( L_41 ) ;
else
F_19 ( L_42 ) ;
return V_51 ;
}
void F_55 ( struct V_5 * V_6 )
{
struct V_102 * V_53 ;
if ( ! F_50 () )
return;
if ( ! F_56 ( V_6 ) )
return;
V_53 = F_56 ( V_6 ) -> V_53 ;
if ( NULL == V_53 || 0 == V_53 -> V_112 )
return;
V_15 -> V_107 ( V_6 , NULL ) ;
}
void F_57 ( struct V_5 * V_6 )
{
struct V_5 * V_113 ;
F_58 (dn, sib)
F_57 ( V_113 ) ;
F_55 ( V_6 ) ;
}
void F_59 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
if ( ! V_8 || ! V_66 )
return;
F_27 ( L_43 , F_35 ( V_8 ) ) ;
V_6 = F_60 ( V_8 ) ;
V_2 = F_56 ( V_6 ) ;
if ( V_2 -> V_114 == V_8 ) {
F_27 ( L_44 ) ;
return;
}
if ( V_2 -> V_114 ) {
F_61 ( V_2 ) ;
F_62 ( V_2 -> V_114 ) ;
F_63 ( V_2 -> V_114 ) ;
V_2 -> V_115 &= ~ V_116 ;
V_2 -> V_114 = NULL ;
V_8 -> V_8 . V_117 . V_2 = NULL ;
}
V_2 -> V_114 = V_8 ;
V_8 -> V_8 . V_117 . V_2 = V_2 ;
if ( F_9 () )
V_15 -> V_109 ( V_8 , NULL ) ;
F_64 ( V_8 ) ;
}
void F_65 ( struct V_118 * V_108 )
{
struct V_7 * V_8 ;
F_66 (dev, &bus->devices, bus_list) {
F_59 ( V_8 ) ;
if ( V_8 -> V_119 == V_120 ) {
struct V_118 * V_121 = V_8 -> V_122 ;
if ( V_121 )
F_65 ( V_121 ) ;
}
}
}
void F_67 ( struct V_118 * V_108 )
{
struct V_7 * V_8 ;
F_66 (dev, &bus->devices, bus_list) {
F_68 ( V_8 ) ;
if ( V_8 -> V_119 == V_120 ) {
struct V_118 * V_121 = V_8 -> V_122 ;
if ( V_121 )
F_67 ( V_121 ) ;
}
}
}
void F_69 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
if ( ! V_8 || ! V_66 )
return;
V_2 = F_34 ( V_8 ) ;
F_27 ( L_45 , F_35 ( V_8 ) ) ;
if ( ! V_2 || ! V_2 -> V_114 || ! V_2 -> V_27 ) {
F_27 ( L_46 ) ;
return;
}
V_2 -> V_114 = NULL ;
V_8 -> V_8 . V_117 . V_2 = NULL ;
if ( ! ( V_2 -> V_27 -> V_33 & V_123 ) )
F_61 ( V_2 ) ;
else
V_2 -> V_115 |= V_124 ;
F_62 ( V_8 ) ;
F_63 ( V_8 ) ;
V_2 -> V_115 &= ~ V_116 ;
}
static int F_70 ( struct V_125 * V_126 , void * V_127 )
{
if ( 0 == V_66 ) {
F_71 ( V_126 , L_47 ) ;
F_71 ( V_126 , L_48 , V_64 . V_65 ) ;
} else {
F_71 ( V_126 , L_49 ) ;
F_71 ( V_126 ,
L_50
L_51
L_52
L_53
L_48
L_54
L_55 ,
V_64 . V_80 ,
V_64 . V_67 ,
V_64 . V_71 ,
V_64 . V_68 ,
V_64 . V_65 ,
V_64 . V_76 ,
V_64 . V_77 ) ;
}
return 0 ;
}
static int F_72 ( struct V_128 * V_128 , struct V_129 * V_129 )
{
return F_73 ( V_129 , F_70 , NULL ) ;
}
static int T_5 F_74 ( void )
{
if ( F_48 ( V_130 ) || F_48 ( V_105 ) )
F_75 ( L_56 , 0 , NULL , & V_131 ) ;
return 0 ;
}
