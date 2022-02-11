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
struct V_1 * V_2 ;
F_9 ( V_27 , V_30 ) ;
V_15 -> V_31 ( V_27 ) ;
F_10 ( V_27 ) ;
V_32 [ 0 ] = 0 ;
F_11 (pe, edev) {
V_29 += F_1 ( V_2 , V_32 ,
V_33 ) ;
}
V_15 -> V_34 ( V_27 , V_28 , V_32 , V_29 ) ;
}
static inline unsigned long F_12 ( unsigned long V_35 )
{
T_3 * V_36 ;
unsigned long V_37 ;
V_36 = F_13 ( V_38 . V_39 , V_35 ) ;
if ( ! V_36 )
return V_35 ;
V_37 = F_14 ( * V_36 ) << V_40 ;
return V_37 | ( V_35 & ( V_41 - 1 ) ) ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_42 ;
unsigned long V_43 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_26 * V_27 ;
int V_44 = 0 ;
const char * V_45 ;
V_46 . V_47 ++ ;
if ( ! V_48 )
return 0 ;
if ( ! V_2 ) {
V_46 . V_49 ++ ;
return 0 ;
}
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_2 ) ;
V_27 = V_2 -> V_27 ;
if ( ! V_27 ) {
V_46 . V_50 ++ ;
F_16 ( L_23 ,
F_17 ( V_8 ) , V_6 -> V_13 ) ;
return 0 ;
}
if ( ! V_27 -> V_51 && ! V_27 -> V_52 ) {
V_46 . V_53 ++ ;
return 0 ;
}
F_18 ( & V_54 , V_43 ) ;
V_44 = 1 ;
if ( V_27 -> V_55 & V_56 ) {
V_27 -> V_57 ++ ;
if ( V_27 -> V_57 % V_58 == 0 ) {
V_45 = F_19 ( V_6 , L_24 , NULL ) ;
F_5 ( V_59 L_25
L_26 ,
V_27 -> V_57 , V_45 ,
F_20 ( V_8 ) , F_17 ( V_8 ) ) ;
F_5 ( V_59 L_27 ,
F_20 ( V_8 ) ) ;
F_21 () ;
}
goto V_60;
}
V_42 = V_15 -> V_61 ( V_27 , NULL ) ;
if ( ( V_42 < 0 ) ||
( V_42 == V_62 ) ||
( V_42 & ( V_63 | V_64 ) ) ==
( V_63 | V_64 ) ) {
V_46 . V_65 ++ ;
V_27 -> V_65 ++ ;
V_44 = 0 ;
goto V_60;
}
V_46 . V_66 ++ ;
F_22 ( V_27 , V_56 ) ;
F_23 ( & V_54 , V_43 ) ;
F_24 ( V_27 ) ;
F_25 ( 1 , L_28 ) ;
return 1 ;
V_60:
F_23 ( & V_54 , V_43 ) ;
return V_44 ;
}
unsigned long F_26 ( const volatile void T_4 * V_35 , unsigned long V_67 )
{
unsigned long V_51 ;
struct V_1 * V_2 ;
V_51 = F_12 ( ( unsigned long V_68 ) V_35 ) ;
V_2 = F_27 ( V_51 ) ;
if ( ! V_2 ) {
V_46 . V_69 ++ ;
return V_67 ;
}
F_15 ( V_2 ) ;
F_28 ( F_3 ( V_2 ) ) ;
return V_67 ;
}
int F_9 ( struct V_26 * V_27 , int V_70 )
{
int V_44 ;
V_44 = V_15 -> V_71 ( V_27 , V_70 ) ;
if ( V_44 )
F_29 ( L_29 ,
V_72 , V_70 , V_27 -> V_73 -> V_74 , V_27 -> V_51 , V_44 ) ;
V_44 = V_15 -> V_75 ( V_27 , V_76 ) ;
if ( V_44 > 0 && ( V_44 & V_77 ) &&
( V_70 == V_30 ) )
return 0 ;
return V_44 ;
}
int F_30 ( struct V_7 * V_8 , enum V_78 V_55 )
{
struct V_1 * V_2 = F_31 ( V_8 ) ;
struct V_26 * V_27 = V_2 -> V_27 ;
if ( ! V_27 ) {
F_32 ( L_30 ,
V_72 , F_33 ( V_8 ) ) ;
return - V_79 ;
}
switch ( V_55 ) {
case V_80 :
V_15 -> V_81 ( V_27 , V_82 ) ;
break;
case V_83 :
V_15 -> V_81 ( V_27 , V_84 ) ;
break;
case V_85 :
V_15 -> V_81 ( V_27 , V_86 ) ;
break;
default:
return - V_79 ;
} ;
return 0 ;
}
static void * F_34 ( void * V_87 , void * V_88 )
{
struct V_7 * V_8 ;
unsigned int * V_89 = ( unsigned int * ) V_88 ;
struct V_1 * V_2 = (struct V_1 * ) V_87 ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 )
* V_89 |= V_8 -> V_90 ;
return NULL ;
}
static void F_35 ( struct V_26 * V_27 )
{
unsigned int V_89 = 0 ;
F_36 ( V_27 , F_34 , & V_89 ) ;
if ( V_89 )
V_15 -> V_81 ( V_27 , V_86 ) ;
else
V_15 -> V_81 ( V_27 , V_84 ) ;
#define F_37 250
F_38 ( F_37 ) ;
F_39 ( V_27 , V_56 ) ;
V_15 -> V_81 ( V_27 , V_82 ) ;
#define F_40 1800
F_38 ( F_40 ) ;
}
int F_41 ( struct V_26 * V_27 )
{
int V_11 , V_44 ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
F_35 ( V_27 ) ;
V_44 = V_15 -> V_75 ( V_27 , V_76 ) ;
if ( V_44 == ( V_63 | V_64 ) )
return 0 ;
if ( V_44 < 0 ) {
F_32 ( L_31 ,
V_72 , V_27 -> V_73 -> V_74 , V_27 -> V_51 ) ;
return - 1 ;
}
F_32 ( L_32 ,
V_11 + 1 , V_27 -> V_73 -> V_74 , V_27 -> V_51 , V_44 ) ;
}
return - 1 ;
}
void F_42 ( struct V_1 * V_2 )
{
int V_11 ;
struct V_5 * V_6 ;
if ( ! V_2 )
return;
V_6 = F_2 ( V_2 ) ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
V_15 -> V_16 ( V_6 , V_11 * 4 , 4 , & V_2 -> V_91 [ V_11 ] ) ;
}
int T_5 F_43 ( struct V_15 * V_92 )
{
if ( ! V_92 -> V_93 ) {
F_29 ( L_33 ,
V_72 , V_92 ) ;
return - V_79 ;
}
if ( V_15 && V_15 != V_92 ) {
F_29 ( L_34 ,
V_72 , V_15 -> V_93 , V_92 -> V_93 ) ;
return - V_94 ;
}
V_15 = V_92 ;
return 0 ;
}
int T_6 F_44 ( const char * V_93 )
{
if ( ! V_93 || ! strlen ( V_93 ) ) {
F_29 ( L_35 ,
V_72 ) ;
return - V_79 ;
}
if ( V_15 && ! strcmp ( V_15 -> V_93 , V_93 ) ) {
V_15 = NULL ;
return 0 ;
}
return - V_94 ;
}
static int T_5 F_45 ( void )
{
struct V_95 * V_96 , * V_97 ;
struct V_5 * V_73 ;
int V_42 ;
if ( ! V_15 ) {
F_29 ( L_36 ,
V_72 ) ;
return - V_94 ;
} else if ( ( V_42 = V_15 -> V_98 () ) ) {
F_29 ( L_37 ,
V_72 , V_42 ) ;
return V_42 ;
}
F_46 ( & V_54 ) ;
if ( F_47 () ) {
F_48 (hose, tmp,
&hose_list, list_node) {
V_73 = V_96 -> V_6 ;
F_49 ( V_73 , V_15 -> V_99 , NULL ) ;
}
}
if ( V_48 )
F_50 ( L_38 ) ;
else
F_29 ( L_39 ) ;
return V_42 ;
}
static void F_51 ( struct V_5 * V_6 )
{
struct V_95 * V_73 ;
if ( ! F_52 ( V_6 ) )
return;
V_73 = F_52 ( V_6 ) -> V_73 ;
if ( NULL == V_73 || 0 == V_73 -> V_100 )
return;
V_15 -> V_99 ( V_6 , NULL ) ;
}
void F_53 ( struct V_5 * V_6 )
{
struct V_5 * V_101 ;
F_54 (dn, sib)
F_53 ( V_101 ) ;
F_51 ( V_6 ) ;
}
static void F_55 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
if ( ! V_8 || ! V_48 )
return;
F_16 ( L_40 , F_33 ( V_8 ) ) ;
V_6 = F_56 ( V_8 ) ;
V_2 = F_52 ( V_6 ) ;
if ( V_2 -> V_102 == V_8 ) {
F_16 ( L_41 ) ;
return;
}
F_57 ( V_2 -> V_102 ) ;
F_58 ( V_8 ) ;
V_2 -> V_102 = V_8 ;
V_8 -> V_8 . V_103 . V_2 = V_2 ;
F_59 ( V_8 ) ;
F_60 ( V_8 ) ;
}
void F_61 ( struct V_104 * V_105 )
{
struct V_7 * V_8 ;
F_62 (dev, &bus->devices, bus_list) {
F_55 ( V_8 ) ;
if ( V_8 -> V_106 == V_107 ) {
struct V_104 * V_108 = V_8 -> V_109 ;
if ( V_108 )
F_61 ( V_108 ) ;
}
}
}
static void F_63 ( struct V_7 * V_8 , int V_110 )
{
struct V_1 * V_2 ;
if ( ! V_8 || ! V_48 )
return;
V_2 = F_31 ( V_8 ) ;
F_16 ( L_42 , F_33 ( V_8 ) ) ;
if ( ! V_2 || ! V_2 -> V_102 ) {
F_16 ( L_43 ) ;
return;
}
V_2 -> V_102 = NULL ;
V_8 -> V_8 . V_103 . V_2 = NULL ;
F_28 ( V_8 ) ;
F_64 ( V_2 , V_110 ) ;
F_65 ( V_8 ) ;
F_66 ( V_8 ) ;
}
void F_67 ( struct V_7 * V_8 , int V_110 )
{
struct V_104 * V_105 = V_8 -> V_109 ;
struct V_7 * V_111 , * V_97 ;
F_63 ( V_8 , V_110 ) ;
if ( V_105 && V_8 -> V_106 == V_107 ) {
F_48 (child, tmp, &bus->devices, bus_list)
F_67 ( V_111 , V_110 ) ;
}
}
static int F_68 ( struct V_112 * V_113 , void * V_114 )
{
if ( 0 == V_48 ) {
F_69 ( V_113 , L_44 ) ;
F_69 ( V_113 , L_45 , V_46 . V_47 ) ;
} else {
F_69 ( V_113 , L_46 ) ;
F_69 ( V_113 ,
L_47
L_48
L_49
L_50
L_45
L_51
L_52 ,
V_46 . V_69 ,
V_46 . V_49 ,
V_46 . V_53 ,
V_46 . V_50 ,
V_46 . V_47 ,
V_46 . V_65 ,
V_46 . V_66 ) ;
}
return 0 ;
}
static int F_70 ( struct V_115 * V_115 , struct V_116 * V_116 )
{
return F_71 ( V_116 , F_68 , NULL ) ;
}
static int T_5 F_72 ( void )
{
if ( F_73 ( V_117 ) )
F_74 ( L_53 , 0 , NULL , & V_118 ) ;
return 0 ;
}
