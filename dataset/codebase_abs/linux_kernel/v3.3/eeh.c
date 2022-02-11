static void F_1 ( struct V_1 * V_2 , int V_3 ,
char * V_4 , T_1 V_5 )
{
int V_6 ;
unsigned long V_7 ;
int V_8 ;
F_2 ( & V_9 , V_7 ) ;
memset ( V_10 , 0 , V_11 ) ;
V_6 = V_2 -> V_12 ;
if ( V_2 -> V_13 )
V_6 = V_2 -> V_13 ;
V_8 = F_3 ( V_14 ,
8 , 1 , NULL , V_6 ,
F_4 ( V_2 -> V_15 -> V_16 ) ,
F_5 ( V_2 -> V_15 -> V_16 ) ,
F_6 ( V_4 ) , V_5 ,
F_6 ( V_10 ) ,
V_11 ,
V_3 ) ;
if ( V_8 == 0 )
F_7 ( V_10 , V_17 , 0 ) ;
F_8 ( & V_9 , V_7 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , char * V_18 , T_1 V_19 )
{
struct V_20 * V_21 = V_2 -> V_22 ;
T_2 V_23 ;
int V_24 , V_25 ;
int V_26 = 0 ;
V_26 += F_10 ( V_18 + V_26 , V_19 - V_26 , L_1 , V_2 -> V_27 -> V_28 ) ;
F_11 ( V_29 L_2 , V_2 -> V_27 -> V_28 ) ;
F_12 ( V_2 , V_30 , 4 , & V_23 ) ;
V_26 += F_10 ( V_18 + V_26 , V_19 - V_26 , L_3 , V_23 ) ;
F_11 ( V_29 L_4 , V_23 ) ;
F_12 ( V_2 , V_31 , 4 , & V_23 ) ;
V_26 += F_10 ( V_18 + V_26 , V_19 - V_26 , L_5 , V_23 ) ;
F_11 ( V_29 L_6 , V_23 ) ;
if ( ! V_21 ) {
F_11 ( V_29 L_7 ) ;
return V_26 ;
}
if ( V_21 -> V_32 >> 16 == V_33 ) {
F_12 ( V_2 , V_34 , 2 , & V_23 ) ;
V_26 += F_10 ( V_18 + V_26 , V_19 - V_26 , L_8 , V_23 ) ;
F_11 ( V_29 L_9 , V_23 ) ;
F_12 ( V_2 , V_35 , 2 , & V_23 ) ;
V_26 += F_10 ( V_18 + V_26 , V_19 - V_26 , L_10 , V_23 ) ;
F_11 ( V_29 L_11 , V_23 ) ;
}
V_24 = F_13 ( V_21 , V_36 ) ;
if ( V_24 ) {
F_12 ( V_2 , V_24 , 4 , & V_23 ) ;
V_26 += F_10 ( V_18 + V_26 , V_19 - V_26 , L_12 , V_23 ) ;
F_11 ( V_29 L_13 , V_23 ) ;
F_12 ( V_2 , V_24 + 4 , 4 , & V_23 ) ;
V_26 += F_10 ( V_18 + V_26 , V_19 - V_26 , L_14 , V_23 ) ;
F_11 ( V_29 L_15 , V_23 ) ;
}
V_24 = F_13 ( V_21 , V_37 ) ;
if ( V_24 ) {
V_26 += F_10 ( V_18 + V_26 , V_19 - V_26 , L_16 ) ;
F_11 ( V_29
L_17 ) ;
for ( V_25 = 0 ; V_25 <= 8 ; V_25 ++ ) {
F_12 ( V_2 , V_24 + 4 * V_25 , 4 , & V_23 ) ;
V_26 += F_10 ( V_18 + V_26 , V_19 - V_26 , L_18 , 4 * V_25 , V_23 ) ;
F_11 ( V_29 L_19 , V_25 , V_23 ) ;
}
V_24 = F_14 ( V_21 , V_38 ) ;
if ( V_24 ) {
V_26 += F_10 ( V_18 + V_26 , V_19 - V_26 , L_20 ) ;
F_11 ( V_29
L_21 ) ;
for ( V_25 = 0 ; V_25 < 14 ; V_25 ++ ) {
F_12 ( V_2 , V_24 + 4 * V_25 , 4 , & V_23 ) ;
V_26 += F_10 ( V_18 + V_26 , V_19 - V_26 , L_18 , 4 * V_25 , V_23 ) ;
F_11 ( V_29 L_22 , V_25 , V_23 ) ;
}
}
}
if ( V_21 -> V_32 >> 16 == V_33 ) {
struct V_39 * V_40 ;
F_15 (pdn->node, dn) {
V_2 = F_16 ( V_40 ) ;
if ( V_2 )
V_26 += F_9 ( V_2 , V_18 + V_26 , V_19 - V_26 ) ;
}
}
return V_26 ;
}
void F_17 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_5 = 0 ;
V_41 [ 0 ] = 0 ;
F_18 ( V_2 , V_42 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
V_5 = F_9 ( V_2 , V_41 , V_43 ) ;
F_1 ( V_2 , V_3 , V_41 , V_5 ) ;
}
static int F_21 ( struct V_1 * V_2 , int V_44 [] )
{
int V_45 , V_46 ;
int V_6 ;
if ( V_47 != V_48 ) {
V_45 = V_47 ;
V_46 = 4 ;
} else {
V_45 = V_49 ;
V_44 [ 2 ] = 0 ;
V_46 = 3 ;
}
V_6 = V_2 -> V_12 ;
if ( V_2 -> V_13 )
V_6 = V_2 -> V_13 ;
return F_3 ( V_45 , 3 , V_46 , V_44 , V_6 ,
F_4 ( V_2 -> V_15 -> V_16 ) , F_5 ( V_2 -> V_15 -> V_16 ) ) ;
}
int
F_22 ( struct V_1 * V_2 , int V_50 )
{
int V_8 ;
int V_44 [ 3 ] ;
int V_51 ;
while ( 1 ) {
V_8 = F_21 ( V_2 , V_44 ) ;
if ( V_8 ) return V_8 ;
if ( V_44 [ 1 ] == 0 ) return - 1 ;
if ( V_44 [ 0 ] != 5 ) return V_44 [ 0 ] ;
if ( V_44 [ 2 ] == 0 ) return - 1 ;
if ( V_50 <= 0 ) break;
V_51 = V_44 [ 2 ] ;
if ( V_51 <= 0 ) {
F_11 ( V_29
L_23 , V_51 ) ;
V_51 = 1000 ;
} else if ( V_51 > 300 * 1000 ) {
F_11 ( V_29
L_24 , V_51 ) ;
V_51 = 300 * 1000 ;
}
V_50 -= V_51 ;
F_23 ( V_51 ) ;
}
F_11 ( V_29 L_25 ) ;
return - 2 ;
}
static inline unsigned long F_24 ( unsigned long V_45 )
{
T_3 * V_52 ;
unsigned long V_53 ;
V_52 = F_25 ( V_54 . V_55 , V_45 ) ;
if ( ! V_52 )
return V_45 ;
V_53 = F_26 ( * V_52 ) << V_56 ;
return V_53 | ( V_45 & ( V_57 - 1 ) ) ;
}
struct V_39 * F_27 ( struct V_39 * V_40 )
{
while ( ( V_40 -> V_58 ) && F_16 ( V_40 -> V_58 ) &&
( F_16 ( V_40 -> V_58 ) -> V_59 & V_60 ) ) {
V_40 = V_40 -> V_58 ;
}
return V_40 ;
}
static void F_28 ( struct V_39 * V_58 , int V_61 )
{
struct V_39 * V_40 ;
F_15 (parent, dn) {
if ( F_16 ( V_40 ) ) {
struct V_20 * V_21 = F_16 ( V_40 ) -> V_22 ;
F_16 ( V_40 ) -> V_59 |= V_61 ;
if ( V_21 && V_21 -> V_62 )
V_21 -> V_63 = V_64 ;
F_28 ( V_40 , V_61 ) ;
}
}
}
void F_29 ( struct V_39 * V_40 , int V_61 )
{
struct V_20 * V_21 ;
V_40 = F_27 ( V_40 ) ;
if ( ! F_30 ( V_40 ) && F_16 ( V_40 -> V_58 ) )
V_40 = V_40 -> V_58 ;
F_16 ( V_40 ) -> V_59 |= V_61 ;
V_21 = F_16 ( V_40 ) -> V_22 ;
if ( V_21 )
V_21 -> V_63 = V_64 ;
F_28 ( V_40 , V_61 ) ;
}
static void F_31 ( struct V_39 * V_58 , int V_61 )
{
struct V_39 * V_40 ;
F_15 (parent, dn) {
if ( F_16 ( V_40 ) ) {
F_16 ( V_40 ) -> V_59 &= ~ V_61 ;
F_16 ( V_40 ) -> V_65 = 0 ;
F_31 ( V_40 , V_61 ) ;
}
}
}
void F_32 ( struct V_39 * V_40 , int V_61 )
{
unsigned long V_7 ;
F_33 ( & V_66 , V_7 ) ;
V_40 = F_27 ( V_40 ) ;
if ( ! F_30 ( V_40 ) && F_16 ( V_40 -> V_58 ) )
V_40 = V_40 -> V_58 ;
F_16 ( V_40 ) -> V_59 &= ~ V_61 ;
F_16 ( V_40 ) -> V_65 = 0 ;
F_31 ( V_40 , V_61 ) ;
F_34 ( & V_66 , V_7 ) ;
}
void F_35 ( struct V_39 * V_58 , unsigned int * V_67 )
{
struct V_39 * V_40 ;
F_15 (parent, dn) {
if ( F_16 ( V_40 ) ) {
struct V_20 * V_21 = F_16 ( V_40 ) -> V_22 ;
if ( V_21 && V_21 -> V_62 )
* V_67 |= V_21 -> V_68 ;
F_35 ( V_40 , V_67 ) ;
}
}
}
void F_36 ( struct V_39 * V_40 , unsigned int * V_67 )
{
struct V_20 * V_21 ;
V_40 = F_27 ( V_40 ) ;
if ( ! F_30 ( V_40 ) && F_16 ( V_40 -> V_58 ) )
V_40 = V_40 -> V_58 ;
V_21 = F_16 ( V_40 ) -> V_22 ;
if ( V_21 )
* V_67 |= V_21 -> V_68 ;
F_35 ( V_40 , V_67 ) ;
}
int F_37 ( struct V_39 * V_40 , struct V_20 * V_21 )
{
int V_69 ;
int V_44 [ 3 ] ;
unsigned long V_7 ;
struct V_1 * V_2 ;
int V_8 = 0 ;
const char * V_70 ;
V_71 ++ ;
if ( ! V_72 )
return 0 ;
if ( ! V_40 ) {
V_73 ++ ;
return 0 ;
}
V_40 = F_27 ( V_40 ) ;
V_2 = F_16 ( V_40 ) ;
if ( ! ( V_2 -> V_59 & V_60 ) ||
V_2 -> V_59 & V_74 ) {
V_75 ++ ;
F_38 ( L_26 ,
V_2 -> V_59 , F_39 ( V_21 ) , V_40 -> V_28 ) ;
return 0 ;
}
if ( ! V_2 -> V_12 && ! V_2 -> V_13 ) {
V_76 ++ ;
return 0 ;
}
F_33 ( & V_66 , V_7 ) ;
V_8 = 1 ;
if ( V_2 -> V_59 & V_77 ) {
V_2 -> V_65 ++ ;
if ( V_2 -> V_65 % V_78 == 0 ) {
V_70 = F_40 ( V_40 , L_27 , NULL ) ;
F_11 ( V_79 L_28
L_29 ,
V_2 -> V_65 , V_70 ,
F_41 ( V_21 ) , F_39 ( V_21 ) ) ;
F_11 ( V_79 L_30 ,
F_41 ( V_21 ) ) ;
F_42 () ;
}
goto V_80;
}
V_69 = F_21 ( V_2 , V_44 ) ;
if ( V_69 != 0 ) {
F_11 ( V_29 L_31 ,
V_69 , V_40 -> V_28 ) ;
V_81 ++ ;
V_2 -> V_82 ++ ;
V_8 = 0 ;
goto V_80;
}
if ( ( V_44 [ 0 ] == 5 ) && ( V_44 [ 2 ] == 0 ) && ( V_40 -> V_83 == NULL ) ) {
V_81 ++ ;
V_2 -> V_82 ++ ;
V_8 = 0 ;
goto V_80;
}
if ( V_44 [ 1 ] != 1 ) {
F_11 ( V_29 L_32 ,
V_69 , V_40 -> V_28 ) ;
V_81 ++ ;
V_2 -> V_82 ++ ;
V_8 = 0 ;
goto V_80;
}
if ( V_44 [ 0 ] != 1 && V_44 [ 0 ] != 2 && V_44 [ 0 ] != 4 && V_44 [ 0 ] != 5 ) {
V_81 ++ ;
V_2 -> V_82 ++ ;
V_8 = 0 ;
goto V_80;
}
V_84 ++ ;
F_29 ( V_40 , V_77 ) ;
F_34 ( & V_66 , V_7 ) ;
F_43 ( V_40 , V_21 ) ;
F_42 () ;
return 1 ;
V_80:
F_34 ( & V_66 , V_7 ) ;
return V_8 ;
}
unsigned long F_44 ( const volatile void T_4 * V_45 , unsigned long V_85 )
{
unsigned long V_86 ;
struct V_20 * V_21 ;
struct V_39 * V_40 ;
V_86 = F_24 ( ( unsigned long V_87 ) V_45 ) ;
V_21 = F_45 ( V_86 ) ;
if ( ! V_21 ) {
V_88 ++ ;
return V_85 ;
}
V_40 = F_46 ( V_21 ) ;
F_37 ( V_40 , V_21 ) ;
F_47 ( V_21 ) ;
return V_85 ;
}
int
F_18 ( struct V_1 * V_2 , int V_89 )
{
int V_6 ;
int V_8 ;
V_6 = V_2 -> V_12 ;
if ( V_2 -> V_13 )
V_6 = V_2 -> V_13 ;
V_8 = F_3 ( V_90 , 4 , 1 , NULL ,
V_6 ,
F_4 ( V_2 -> V_15 -> V_16 ) ,
F_5 ( V_2 -> V_15 -> V_16 ) ,
V_89 ) ;
if ( V_8 )
F_11 ( V_29 L_33 ,
V_89 , V_8 , V_2 -> V_27 -> V_28 ) ;
V_8 = F_22 ( V_2 , V_91 ) ;
if ( ( V_8 == 4 ) && ( V_89 == V_42 ) )
return 0 ;
return V_8 ;
}
static void
F_48 ( struct V_1 * V_2 , int V_92 )
{
int V_6 ;
int V_8 ;
F_49 ( V_2 == NULL ) ;
if ( ! V_2 -> V_15 ) {
F_11 ( V_29 L_34 ,
V_2 -> V_27 -> V_28 ) ;
return;
}
V_6 = V_2 -> V_12 ;
if ( V_2 -> V_13 )
V_6 = V_2 -> V_13 ;
V_8 = F_3 ( V_93 , 4 , 1 , NULL ,
V_6 ,
F_4 ( V_2 -> V_15 -> V_16 ) ,
F_5 ( V_2 -> V_15 -> V_16 ) ,
V_92 ) ;
if ( V_8 == - 8 && V_92 == 3 ) {
V_8 = F_3 ( V_93 , 4 , 1 , NULL ,
V_6 ,
F_4 ( V_2 -> V_15 -> V_16 ) ,
F_5 ( V_2 -> V_15 -> V_16 ) , 1 ) ;
if ( V_8 )
F_11 ( V_29
L_35
L_36 ,
V_8 , V_2 -> V_27 -> V_28 ) ;
}
}
int F_50 ( struct V_20 * V_21 , enum V_94 V_92 )
{
struct V_39 * V_40 = F_46 ( V_21 ) ;
struct V_1 * V_2 = F_16 ( V_40 ) ;
switch ( V_92 ) {
case V_95 :
F_48 ( V_2 , 0 ) ;
break;
case V_96 :
F_48 ( V_2 , 1 ) ;
break;
case V_97 :
F_48 ( V_2 , 3 ) ;
break;
default:
return - V_98 ;
} ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
unsigned int V_67 = 0 ;
F_36 ( V_2 -> V_27 , & V_67 ) ;
if ( V_67 )
F_48 ( V_2 , 3 ) ;
else
F_48 ( V_2 , 1 ) ;
#define F_52 250
F_23 ( F_52 ) ;
F_32 ( V_2 -> V_27 , V_77 ) ;
F_48 ( V_2 , 0 ) ;
#define F_53 1800
F_23 ( F_53 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
int V_25 , V_8 ;
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ ) {
F_51 ( V_2 ) ;
V_8 = F_22 ( V_2 , V_91 ) ;
if ( V_8 == 0 )
return 0 ;
if ( V_8 < 0 ) {
F_11 ( V_79 L_37 ,
V_2 -> V_27 -> V_28 ) ;
return - 1 ;
}
F_11 ( V_79 L_38 ,
V_25 + 1 , V_2 -> V_27 -> V_28 , V_8 ) ;
}
return - 1 ;
}
static inline void F_55 ( struct V_1 * V_2 )
{
int V_25 ;
T_2 V_99 ;
if ( NULL == V_2 -> V_15 ) return;
for ( V_25 = 4 ; V_25 < 10 ; V_25 ++ ) {
F_56 ( V_2 , V_25 * 4 , 4 , V_2 -> V_100 [ V_25 ] ) ;
}
F_56 ( V_2 , 12 * 4 , 4 , V_2 -> V_100 [ 12 ] ) ;
#define F_57 ( T_5 ) (8*((OFF)/4)+3-(OFF))
#define F_58 ( T_5 ) (((u8 *)(pdn->config_space))[BYTE_SWAP(OFF)])
F_56 ( V_2 , V_101 , 1 ,
F_58 ( V_101 ) ) ;
F_56 ( V_2 , V_102 , 1 ,
F_58 ( V_102 ) ) ;
F_56 ( V_2 , 15 * 4 , 4 , V_2 -> V_100 [ 15 ] ) ;
F_12 ( V_2 , V_31 , 4 , & V_99 ) ;
if ( V_2 -> V_100 [ 1 ] & V_103 )
V_99 |= V_103 ;
else
V_99 &= ~ V_103 ;
if ( V_2 -> V_100 [ 1 ] & V_104 )
V_99 |= V_104 ;
else
V_99 &= ~ V_104 ;
F_56 ( V_2 , V_31 , 4 , V_99 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
if ( ! V_2 )
return;
if ( ( V_2 -> V_59 & V_60 ) && ! F_59 ( V_2 -> V_105 ) )
F_55 ( V_2 ) ;
F_15 (pdn->node, dn)
F_20 ( F_16 ( V_40 ) ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_25 ;
if ( ! V_2 )
return;
for ( V_25 = 0 ; V_25 < 16 ; V_25 ++ )
F_12 ( V_2 , V_25 * 4 , 4 , & V_2 -> V_100 [ V_25 ] ) ;
}
void
F_19 ( struct V_1 * V_2 )
{
int V_6 ;
int V_8 ;
int V_45 ;
V_6 = V_2 -> V_12 ;
if ( V_2 -> V_13 )
V_6 = V_2 -> V_13 ;
if ( V_106 != V_48 )
V_45 = V_106 ;
else
V_45 = V_107 ;
V_8 = F_3 ( V_45 , 3 , 1 , NULL ,
V_6 ,
F_4 ( V_2 -> V_15 -> V_16 ) ,
F_5 ( V_2 -> V_15 -> V_16 ) ) ;
if ( V_8 ) {
F_11 ( V_29 L_39 ,
V_8 , V_2 -> V_27 -> V_28 ) ;
}
}
static int F_61 ( int V_6 ,
struct V_108 * V_109 )
{
unsigned int V_44 [ 3 ] ;
int V_69 ;
if ( V_110 != V_48 ) {
V_69 = F_3 ( V_110 , 4 , 2 , V_44 ,
V_6 , V_109 -> V_111 , V_109 -> V_112 , 1 ) ;
if ( V_69 || ( V_44 [ 0 ] == 0 ) )
return 0 ;
V_69 = F_3 ( V_110 , 4 , 2 , V_44 ,
V_6 , V_109 -> V_111 , V_109 -> V_112 , 0 ) ;
if ( V_69 )
return 0 ;
return V_44 [ 0 ] ;
}
if ( V_113 != V_48 ) {
V_69 = F_3 ( V_113 , 4 , 2 , V_44 ,
V_6 , V_109 -> V_111 , V_109 -> V_112 , 0 ) ;
if ( V_69 )
return 0 ;
return V_44 [ 0 ] ;
}
return 0 ;
}
static void * F_62 ( struct V_39 * V_40 , void * V_114 )
{
unsigned int V_44 [ 3 ] ;
struct V_108 * V_109 = V_114 ;
int V_69 ;
const T_2 * V_105 = F_40 ( V_40 , L_40 , NULL ) ;
const T_2 * V_115 = F_40 ( V_40 , L_41 , NULL ) ;
const T_2 * V_116 = F_40 ( V_40 , L_42 , NULL ) ;
const T_2 * V_117 ;
int V_118 ;
struct V_1 * V_2 = F_16 ( V_40 ) ;
V_2 -> V_105 = 0 ;
V_2 -> V_59 = 0 ;
V_2 -> V_65 = 0 ;
V_2 -> V_119 = 0 ;
V_2 -> V_82 = 0 ;
if ( ! F_63 ( V_40 ) )
return NULL ;
if ( ! V_105 || ! V_115 || ! V_116 )
return NULL ;
if ( V_40 -> type && ! strcmp ( V_40 -> type , L_43 ) ) {
V_2 -> V_59 |= V_74 ;
return NULL ;
}
V_2 -> V_105 = * V_105 ;
V_117 = F_40 ( V_40 , L_44 , NULL ) ;
if ( V_117 ) {
V_69 = F_3 ( V_90 , 4 , 1 , NULL ,
V_117 [ 0 ] , V_109 -> V_111 , V_109 -> V_112 ,
V_120 ) ;
V_118 = 0 ;
if ( V_69 == 0 ) {
V_2 -> V_12 = V_117 [ 0 ] ;
V_2 -> V_13 = F_61 ( V_2 -> V_12 , V_109 ) ;
V_69 = F_21 ( V_2 , V_44 ) ;
if ( ( V_69 == 0 ) && ( V_44 [ 1 ] == 1 ) )
V_118 = 1 ;
}
if ( V_118 ) {
V_72 = 1 ;
V_2 -> V_59 |= V_60 ;
F_38 ( L_45 ,
V_40 -> V_28 , V_2 -> V_12 ,
V_2 -> V_13 ) ;
} else {
if ( V_40 -> V_58 && F_16 ( V_40 -> V_58 )
&& ( F_16 ( V_40 -> V_58 ) -> V_59 & V_60 ) ) {
V_2 -> V_59 |= V_60 ;
V_2 -> V_12 = F_16 ( V_40 -> V_58 ) -> V_12 ;
return NULL ;
}
}
} else {
F_11 ( V_29 L_46 ,
V_40 -> V_28 ) ;
}
F_60 ( V_2 ) ;
return NULL ;
}
void T_6 F_64 ( void )
{
struct V_39 * V_15 , * V_121 ;
struct V_108 V_109 ;
F_65 ( & V_66 ) ;
F_66 ( & V_9 ) ;
V_121 = F_67 ( L_47 ) ;
if ( V_121 == NULL )
return;
V_90 = F_68 ( L_48 ) ;
V_93 = F_68 ( L_49 ) ;
V_47 = F_68 ( L_50 ) ;
V_49 = F_68 ( L_51 ) ;
V_14 = F_68 ( L_52 ) ;
V_113 = F_68 ( L_53 ) ;
V_110 = F_68 ( L_54 ) ;
V_107 = F_68 ( L_55 ) ;
V_106 = F_68 ( L_56 ) ;
if ( V_90 == V_48 )
return;
V_11 = F_68 ( L_57 ) ;
if ( V_11 == V_48 ) {
V_11 = 1024 ;
}
if ( V_11 > V_122 ) {
F_11 ( V_29 L_58
L_59 , V_11 , V_122 ) ;
V_11 = V_122 ;
}
for ( V_15 = F_69 ( NULL , L_60 ) ; V_15 ;
V_15 = F_69 ( V_15 , L_60 ) ) {
unsigned long V_16 ;
V_16 = F_70 ( V_15 ) ;
if ( V_16 == 0 || F_16 ( V_15 ) == NULL )
continue;
V_109 . V_112 = F_5 ( V_16 ) ;
V_109 . V_111 = F_4 ( V_16 ) ;
F_71 ( V_15 , F_62 , & V_109 ) ;
}
if ( V_72 )
F_11 ( V_123 L_61 ) ;
else
F_11 ( V_29 L_62 ) ;
}
static void F_72 ( struct V_39 * V_40 )
{
struct V_124 * V_15 ;
struct V_108 V_109 ;
if ( ! V_40 || ! F_16 ( V_40 ) )
return;
V_15 = F_16 ( V_40 ) -> V_15 ;
if ( NULL == V_15 || 0 == V_15 -> V_16 )
return;
V_109 . V_111 = F_4 ( V_15 -> V_16 ) ;
V_109 . V_112 = F_5 ( V_15 -> V_16 ) ;
F_62 ( V_40 , & V_109 ) ;
}
void F_73 ( struct V_39 * V_40 )
{
struct V_39 * V_125 ;
F_15 (dn, sib)
F_73 ( V_125 ) ;
F_72 ( V_40 ) ;
}
static void F_74 ( struct V_20 * V_21 )
{
struct V_39 * V_40 ;
struct V_1 * V_2 ;
if ( ! V_21 || ! V_72 )
return;
F_38 ( L_63 , F_75 ( V_21 ) ) ;
V_40 = F_46 ( V_21 ) ;
V_2 = F_16 ( V_40 ) ;
if ( V_2 -> V_22 == V_21 ) {
F_38 ( L_64 ) ;
return;
}
F_76 ( V_2 -> V_22 ) ;
F_77 ( V_21 ) ;
V_2 -> V_22 = V_21 ;
F_78 ( V_21 ) ;
F_79 ( V_21 ) ;
}
void F_80 ( struct V_126 * V_127 )
{
struct V_20 * V_21 ;
F_81 (dev, &bus->devices, bus_list) {
F_74 ( V_21 ) ;
if ( V_21 -> V_128 == V_129 ) {
struct V_126 * V_130 = V_21 -> V_131 ;
if ( V_130 )
F_80 ( V_130 ) ;
}
}
}
static void F_82 ( struct V_20 * V_21 )
{
struct V_39 * V_40 ;
if ( ! V_21 || ! V_72 )
return;
F_38 ( L_65 , F_75 ( V_21 ) ) ;
V_40 = F_46 ( V_21 ) ;
if ( F_16 ( V_40 ) -> V_22 == NULL ) {
F_38 ( L_66 ) ;
return;
}
F_16 ( V_40 ) -> V_22 = NULL ;
F_47 ( V_21 ) ;
F_83 ( V_21 ) ;
F_84 ( V_21 ) ;
}
void F_85 ( struct V_20 * V_21 )
{
struct V_126 * V_127 = V_21 -> V_131 ;
struct V_20 * V_83 , * V_132 ;
F_82 ( V_21 ) ;
if ( V_127 && V_21 -> V_128 == V_129 ) {
F_86 (child, tmp, &bus->devices, bus_list)
F_85 ( V_83 ) ;
}
}
static int F_87 ( struct V_133 * V_134 , void * V_135 )
{
if ( 0 == V_72 ) {
F_88 ( V_134 , L_67 ) ;
F_88 ( V_134 , L_68 , V_71 ) ;
} else {
F_88 ( V_134 , L_69 ) ;
F_88 ( V_134 ,
L_70
L_71
L_72
L_73
L_68
L_74
L_75 ,
V_88 , V_73 , V_76 ,
V_75 , V_71 ,
V_81 ,
V_84 ) ;
}
return 0 ;
}
static int F_89 ( struct V_136 * V_136 , struct V_137 * V_137 )
{
return F_90 ( V_137 , F_87 , NULL ) ;
}
static int T_6 F_91 ( void )
{
if ( F_92 ( V_138 ) )
F_93 ( L_76 , 0 , NULL , & V_139 ) ;
return 0 ;
}
