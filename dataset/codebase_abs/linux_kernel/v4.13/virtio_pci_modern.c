static inline T_1 F_1 ( T_1 T_2 * V_1 )
{
return F_2 ( V_1 ) ;
}
static inline T_3 F_3 ( T_4 T_2 * V_1 )
{
return F_4 ( V_1 ) ;
}
static inline T_5 F_5 ( T_6 T_2 * V_1 )
{
return F_6 ( V_1 ) ;
}
static inline void F_7 ( T_1 V_2 , T_1 T_2 * V_1 )
{
F_8 ( V_2 , V_1 ) ;
}
static inline void F_9 ( T_3 V_2 , T_4 T_2 * V_1 )
{
F_10 ( V_2 , V_1 ) ;
}
static inline void F_11 ( T_5 V_2 , T_6 T_2 * V_1 )
{
F_12 ( V_2 , V_1 ) ;
}
static void F_13 ( T_7 V_3 ,
T_6 T_2 * V_4 , T_6 T_2 * V_5 )
{
F_11 ( ( T_5 ) V_3 , V_4 ) ;
F_11 ( V_3 >> 32 , V_5 ) ;
}
static void T_2 * F_14 ( struct V_6 * V_7 , int V_8 ,
T_8 V_9 ,
T_5 V_10 ,
T_5 V_11 , T_5 V_12 ,
T_8 * V_13 )
{
T_1 V_14 ;
T_5 V_15 , V_16 ;
void T_2 * V_17 ;
F_15 ( V_7 , V_8 + F_16 ( struct V_18 ,
V_14 ) ,
& V_14 ) ;
F_17 ( V_7 , V_8 + F_16 ( struct V_18 , V_15 ) ,
& V_15 ) ;
F_17 ( V_7 , V_8 + F_16 ( struct V_18 , V_16 ) ,
& V_16 ) ;
if ( V_16 <= V_11 ) {
F_18 ( & V_7 -> V_7 ,
L_1 ,
V_16 , V_11 ) ;
return NULL ;
}
if ( V_16 - V_11 < V_9 ) {
F_18 ( & V_7 -> V_7 ,
L_2 ,
V_16 , V_9 ) ;
return NULL ;
}
V_16 -= V_11 ;
if ( V_11 + V_15 < V_15 ) {
F_18 ( & V_7 -> V_7 ,
L_3 ,
V_11 , V_15 ) ;
return NULL ;
}
V_15 += V_11 ;
if ( V_15 & ( V_10 - 1 ) ) {
F_18 ( & V_7 -> V_7 ,
L_4 ,
V_15 , V_10 ) ;
return NULL ;
}
if ( V_16 > V_12 )
V_16 = V_12 ;
if ( V_13 )
* V_13 = V_16 ;
if ( V_9 + V_15 < V_9 ||
V_9 + V_15 > F_19 ( V_7 , V_14 ) ) {
F_18 ( & V_7 -> V_7 ,
L_5
L_6 ,
V_9 , V_15 ,
V_14 , ( unsigned long ) F_19 ( V_7 , V_14 ) ) ;
return NULL ;
}
V_17 = F_20 ( V_7 , V_14 , V_15 , V_16 ) ;
if ( ! V_17 )
F_18 ( & V_7 -> V_7 ,
L_7 ,
V_16 , V_15 , V_14 ) ;
return V_17 ;
}
static T_7 F_21 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
T_7 V_23 ;
F_11 ( 0 , & V_22 -> V_24 -> V_25 ) ;
V_23 = F_5 ( & V_22 -> V_24 -> V_26 ) ;
F_11 ( 1 , & V_22 -> V_24 -> V_25 ) ;
V_23 |= ( ( T_7 ) F_5 ( & V_22 -> V_24 -> V_26 ) << 32 ) ;
return V_23 ;
}
static int F_23 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
F_24 ( V_20 ) ;
if ( ! F_25 ( V_20 , V_27 ) ) {
F_18 ( & V_20 -> V_7 , L_8
L_9 ) ;
return - V_28 ;
}
F_11 ( 0 , & V_22 -> V_24 -> V_29 ) ;
F_11 ( ( T_5 ) V_20 -> V_23 , & V_22 -> V_24 -> V_30 ) ;
F_11 ( 1 , & V_22 -> V_24 -> V_29 ) ;
F_11 ( V_20 -> V_23 >> 32 , & V_22 -> V_24 -> V_30 ) ;
return 0 ;
}
static void F_26 ( struct V_19 * V_20 , unsigned V_15 ,
void * V_31 , unsigned V_13 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
T_1 V_32 ;
T_4 V_33 ;
T_6 V_34 ;
F_27 ( V_15 + V_13 > V_22 -> V_35 ) ;
switch ( V_13 ) {
case 1 :
V_32 = F_2 ( V_22 -> V_36 + V_15 ) ;
memcpy ( V_31 , & V_32 , sizeof V_32 ) ;
break;
case 2 :
V_33 = F_28 ( F_4 ( V_22 -> V_36 + V_15 ) ) ;
memcpy ( V_31 , & V_33 , sizeof V_33 ) ;
break;
case 4 :
V_34 = F_29 ( F_6 ( V_22 -> V_36 + V_15 ) ) ;
memcpy ( V_31 , & V_34 , sizeof V_34 ) ;
break;
case 8 :
V_34 = F_29 ( F_6 ( V_22 -> V_36 + V_15 ) ) ;
memcpy ( V_31 , & V_34 , sizeof V_34 ) ;
V_34 = F_29 ( F_6 ( V_22 -> V_36 + V_15 + sizeof V_34 ) ) ;
memcpy ( V_31 + sizeof V_34 , & V_34 , sizeof V_34 ) ;
break;
default:
F_30 () ;
}
}
static void F_31 ( struct V_19 * V_20 , unsigned V_15 ,
const void * V_31 , unsigned V_13 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
T_1 V_32 ;
T_4 V_33 ;
T_6 V_34 ;
F_27 ( V_15 + V_13 > V_22 -> V_35 ) ;
switch ( V_13 ) {
case 1 :
memcpy ( & V_32 , V_31 , sizeof V_32 ) ;
F_8 ( V_32 , V_22 -> V_36 + V_15 ) ;
break;
case 2 :
memcpy ( & V_33 , V_31 , sizeof V_33 ) ;
F_10 ( F_32 ( V_33 ) , V_22 -> V_36 + V_15 ) ;
break;
case 4 :
memcpy ( & V_34 , V_31 , sizeof V_34 ) ;
F_12 ( F_33 ( V_34 ) , V_22 -> V_36 + V_15 ) ;
break;
case 8 :
memcpy ( & V_34 , V_31 , sizeof V_34 ) ;
F_12 ( F_33 ( V_34 ) , V_22 -> V_36 + V_15 ) ;
memcpy ( & V_34 , V_31 + sizeof V_34 , sizeof V_34 ) ;
F_12 ( F_33 ( V_34 ) , V_22 -> V_36 + V_15 + sizeof V_34 ) ;
break;
default:
F_30 () ;
}
}
static T_5 F_34 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
return F_1 ( & V_22 -> V_24 -> V_37 ) ;
}
static T_1 F_35 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
return F_1 ( & V_22 -> V_24 -> V_38 ) ;
}
static void F_36 ( struct V_19 * V_20 , T_1 V_39 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
F_27 ( V_39 == 0 ) ;
F_7 ( V_39 , & V_22 -> V_24 -> V_38 ) ;
}
static void F_37 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
F_7 ( 0 , & V_22 -> V_24 -> V_38 ) ;
while ( F_1 ( & V_22 -> V_24 -> V_38 ) )
F_38 ( 1 ) ;
F_39 ( V_20 ) ;
}
static T_3 F_40 ( struct V_21 * V_22 , T_3 V_40 )
{
F_9 ( V_40 , & V_22 -> V_24 -> V_41 ) ;
return F_3 ( & V_22 -> V_24 -> V_41 ) ;
}
static struct V_42 * F_41 ( struct V_21 * V_22 ,
struct V_43 * V_44 ,
unsigned V_45 ,
void (* F_42)( struct V_42 * V_46 ) ,
const char * V_47 ,
bool V_48 ,
T_3 V_49 )
{
struct V_50 T_2 * V_51 = V_22 -> V_24 ;
struct V_42 * V_46 ;
T_3 V_52 , V_8 ;
int V_53 ;
if ( V_45 >= F_3 ( & V_51 -> V_54 ) )
return F_43 ( - V_55 ) ;
F_9 ( V_45 , & V_51 -> V_56 ) ;
V_52 = F_3 ( & V_51 -> V_57 ) ;
if ( ! V_52 || F_3 ( & V_51 -> V_58 ) )
return F_43 ( - V_55 ) ;
if ( V_52 & ( V_52 - 1 ) ) {
F_44 ( & V_22 -> V_6 -> V_7 , L_10 , V_52 ) ;
return F_43 ( - V_28 ) ;
}
V_8 = F_3 ( & V_51 -> V_59 ) ;
V_44 -> V_60 = V_49 ;
V_46 = F_45 ( V_45 , V_52 ,
V_61 , & V_22 -> V_20 ,
true , true , V_48 ,
V_62 , F_42 , V_47 ) ;
if ( ! V_46 )
return F_43 ( - V_63 ) ;
F_9 ( F_46 ( V_46 ) , & V_51 -> V_57 ) ;
F_13 ( F_47 ( V_46 ) ,
& V_51 -> V_64 , & V_51 -> V_65 ) ;
F_13 ( F_48 ( V_46 ) ,
& V_51 -> V_66 , & V_51 -> V_67 ) ;
F_13 ( F_49 ( V_46 ) ,
& V_51 -> V_68 , & V_51 -> V_69 ) ;
if ( V_22 -> V_70 ) {
if ( ( T_7 ) V_8 * V_22 -> V_71 + 2
> V_22 -> V_72 ) {
F_44 ( & V_22 -> V_6 -> V_7 ,
L_11
L_12 ,
V_8 , V_22 -> V_71 ,
V_45 , V_22 -> V_72 ) ;
V_53 = - V_28 ;
goto V_73;
}
V_46 -> V_74 = ( void V_75 * ) V_22 -> V_70 +
V_8 * V_22 -> V_71 ;
} else {
V_46 -> V_74 = ( void V_75 * ) F_14 ( V_22 -> V_6 ,
V_22 -> V_76 , 2 , 2 ,
V_8 * V_22 -> V_71 , 2 ,
NULL ) ;
}
if ( ! V_46 -> V_74 ) {
V_53 = - V_63 ;
goto V_73;
}
if ( V_49 != V_77 ) {
F_9 ( V_49 , & V_51 -> V_78 ) ;
V_49 = F_3 ( & V_51 -> V_78 ) ;
if ( V_49 == V_77 ) {
V_53 = - V_79 ;
goto V_80;
}
}
return V_46 ;
V_80:
if ( ! V_22 -> V_70 )
F_50 ( V_22 -> V_6 , ( void T_2 V_75 * ) V_46 -> V_74 ) ;
V_73:
F_51 ( V_46 ) ;
return F_43 ( V_53 ) ;
}
static int F_52 ( struct V_19 * V_20 , unsigned V_81 ,
struct V_42 * V_82 [] ,
T_9 * V_83 [] ,
const char * const V_84 [] , const bool * V_48 ,
struct V_85 * V_86 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
struct V_42 * V_46 ;
int V_87 = F_53 ( V_20 , V_81 , V_82 , V_83 , V_84 , V_48 , V_86 ) ;
if ( V_87 )
return V_87 ;
F_54 (vq, &vdev->vqs, list) {
F_9 ( V_46 -> V_45 , & V_22 -> V_24 -> V_56 ) ;
F_9 ( 1 , & V_22 -> V_24 -> V_58 ) ;
}
return 0 ;
}
static void F_55 ( struct V_43 * V_44 )
{
struct V_42 * V_46 = V_44 -> V_46 ;
struct V_21 * V_22 = F_22 ( V_46 -> V_20 ) ;
F_9 ( V_46 -> V_45 , & V_22 -> V_24 -> V_56 ) ;
if ( V_22 -> V_88 ) {
F_9 ( V_77 ,
& V_22 -> V_24 -> V_78 ) ;
F_3 ( & V_22 -> V_24 -> V_78 ) ;
}
if ( ! V_22 -> V_70 )
F_50 ( V_22 -> V_6 , ( void V_75 T_2 * ) V_46 -> V_74 ) ;
F_51 ( V_46 ) ;
}
static inline int F_56 ( struct V_6 * V_7 , T_1 V_89 ,
T_5 V_90 , int * V_91 )
{
int V_92 ;
for ( V_92 = F_57 ( V_7 , V_93 ) ;
V_92 > 0 ;
V_92 = F_58 ( V_7 , V_92 , V_93 ) ) {
T_1 type , V_14 ;
F_15 ( V_7 , V_92 + F_16 ( struct V_18 ,
V_89 ) ,
& type ) ;
F_15 ( V_7 , V_92 + F_16 ( struct V_18 ,
V_14 ) ,
& V_14 ) ;
if ( V_14 > 0x5 )
continue;
if ( type == V_89 ) {
if ( F_19 ( V_7 , V_14 ) &&
F_59 ( V_7 , V_14 ) & V_90 ) {
* V_91 |= ( 1 << V_14 ) ;
return V_92 ;
}
}
}
return 0 ;
}
static inline void F_60 ( void )
{
F_61 ( V_94 !=
F_16 ( struct V_18 , V_95 ) ) ;
F_61 ( V_96 !=
F_16 ( struct V_18 , V_97 ) ) ;
F_61 ( V_98 !=
F_16 ( struct V_18 , V_99 ) ) ;
F_61 ( V_100 !=
F_16 ( struct V_18 , V_89 ) ) ;
F_61 ( V_101 !=
F_16 ( struct V_18 , V_14 ) ) ;
F_61 ( V_102 !=
F_16 ( struct V_18 , V_15 ) ) ;
F_61 ( V_103 !=
F_16 ( struct V_18 , V_16 ) ) ;
F_61 ( V_104 !=
F_16 ( struct V_105 ,
V_106 ) ) ;
F_61 ( V_107 !=
F_16 ( struct V_50 ,
V_25 ) ) ;
F_61 ( V_108 !=
F_16 ( struct V_50 , V_26 ) ) ;
F_61 ( V_109 !=
F_16 ( struct V_50 ,
V_29 ) ) ;
F_61 ( V_110 !=
F_16 ( struct V_50 , V_30 ) ) ;
F_61 ( V_111 !=
F_16 ( struct V_50 , V_41 ) ) ;
F_61 ( V_112 !=
F_16 ( struct V_50 , V_54 ) ) ;
F_61 ( V_113 !=
F_16 ( struct V_50 , V_38 ) ) ;
F_61 ( V_114 !=
F_16 ( struct V_50 , V_37 ) ) ;
F_61 ( V_115 !=
F_16 ( struct V_50 , V_56 ) ) ;
F_61 ( V_116 !=
F_16 ( struct V_50 , V_57 ) ) ;
F_61 ( V_117 !=
F_16 ( struct V_50 , V_78 ) ) ;
F_61 ( V_118 !=
F_16 ( struct V_50 , V_58 ) ) ;
F_61 ( V_119 !=
F_16 ( struct V_50 , V_59 ) ) ;
F_61 ( V_120 !=
F_16 ( struct V_50 , V_64 ) ) ;
F_61 ( V_121 !=
F_16 ( struct V_50 , V_65 ) ) ;
F_61 ( V_122 !=
F_16 ( struct V_50 , V_66 ) ) ;
F_61 ( V_123 !=
F_16 ( struct V_50 , V_67 ) ) ;
F_61 ( V_124 !=
F_16 ( struct V_50 , V_68 ) ) ;
F_61 ( V_125 !=
F_16 ( struct V_50 , V_69 ) ) ;
}
int F_62 ( struct V_21 * V_22 )
{
struct V_6 * V_6 = V_22 -> V_6 ;
int V_53 , V_24 , V_126 , V_127 , V_36 ;
T_5 V_128 ;
T_5 V_129 ;
F_60 () ;
if ( V_6 -> V_36 < 0x1000 || V_6 -> V_36 > 0x107f )
return - V_130 ;
if ( V_6 -> V_36 < 0x1040 ) {
V_22 -> V_20 . V_131 . V_36 = V_6 -> V_132 ;
} else {
V_22 -> V_20 . V_131 . V_36 = V_6 -> V_36 - 0x1040 ;
}
V_22 -> V_20 . V_131 . V_133 = V_6 -> V_134 ;
V_24 = F_56 ( V_6 , V_135 ,
V_136 | V_137 ,
& V_22 -> V_138 ) ;
if ( ! V_24 ) {
F_63 ( & V_6 -> V_7 ,
L_13 ) ;
return - V_130 ;
}
V_126 = F_56 ( V_6 , V_139 ,
V_136 | V_137 ,
& V_22 -> V_138 ) ;
V_127 = F_56 ( V_6 , V_140 ,
V_136 | V_137 ,
& V_22 -> V_138 ) ;
if ( ! V_126 || ! V_127 ) {
F_18 ( & V_6 -> V_7 ,
L_14 ,
V_24 , V_126 , V_127 ) ;
return - V_28 ;
}
V_53 = F_64 ( & V_6 -> V_7 , F_65 ( 64 ) ) ;
if ( V_53 )
V_53 = F_64 ( & V_6 -> V_7 ,
F_65 ( 32 ) ) ;
if ( V_53 )
F_44 ( & V_6 -> V_7 , L_15 ) ;
V_36 = F_56 ( V_6 , V_141 ,
V_136 | V_137 ,
& V_22 -> V_138 ) ;
V_53 = F_66 ( V_6 , V_22 -> V_138 ,
L_16 ) ;
if ( V_53 )
return V_53 ;
V_53 = - V_28 ;
V_22 -> V_24 = F_14 ( V_6 , V_24 ,
sizeof( struct V_50 ) , 4 ,
0 , sizeof( struct V_50 ) ,
NULL ) ;
if ( ! V_22 -> V_24 )
goto V_142;
V_22 -> V_126 = F_14 ( V_6 , V_126 , sizeof( T_1 ) , 1 ,
0 , 1 ,
NULL ) ;
if ( ! V_22 -> V_126 )
goto V_143;
F_17 ( V_6 ,
V_127 + F_16 ( struct V_105 ,
V_106 ) ,
& V_22 -> V_71 ) ;
F_17 ( V_6 ,
V_127 + F_16 ( struct V_105 ,
V_144 . V_16 ) ,
& V_128 ) ;
F_17 ( V_6 ,
V_127 + F_16 ( struct V_105 ,
V_144 . V_15 ) ,
& V_129 ) ;
if ( ( T_7 ) V_128 + ( V_129 % V_145 ) <= V_145 ) {
V_22 -> V_70 = F_14 ( V_6 , V_127 , 2 , 2 ,
0 , V_128 ,
& V_22 -> V_72 ) ;
if ( ! V_22 -> V_70 )
goto V_73;
} else {
V_22 -> V_76 = V_127 ;
}
if ( V_36 ) {
V_22 -> V_36 = F_14 ( V_6 , V_36 , 0 , 4 ,
0 , V_145 ,
& V_22 -> V_35 ) ;
if ( ! V_22 -> V_36 )
goto V_146;
V_22 -> V_20 . V_147 = & V_148 ;
} else {
V_22 -> V_20 . V_147 = & V_149 ;
}
V_22 -> V_150 = F_40 ;
V_22 -> F_41 = F_41 ;
V_22 -> F_55 = F_55 ;
return 0 ;
V_146:
if ( V_22 -> V_70 )
F_50 ( V_6 , V_22 -> V_70 ) ;
V_73:
F_50 ( V_6 , V_22 -> V_126 ) ;
V_143:
F_50 ( V_6 , V_22 -> V_24 ) ;
V_142:
return V_53 ;
}
void F_67 ( struct V_21 * V_22 )
{
struct V_6 * V_6 = V_22 -> V_6 ;
if ( V_22 -> V_36 )
F_50 ( V_6 , V_22 -> V_36 ) ;
if ( V_22 -> V_70 )
F_50 ( V_6 , V_22 -> V_70 ) ;
F_50 ( V_6 , V_22 -> V_126 ) ;
F_50 ( V_6 , V_22 -> V_24 ) ;
F_68 ( V_6 , V_22 -> V_138 ) ;
}
