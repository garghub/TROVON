static void T_1 * F_1 ( struct V_1 * V_2 , int V_3 ,
T_2 V_4 ,
T_3 V_5 ,
T_3 V_6 , T_3 V_7 ,
T_2 * V_8 )
{
T_4 V_9 ;
T_3 V_10 , V_11 ;
void T_1 * V_12 ;
F_2 ( V_2 , V_3 + F_3 ( struct V_13 ,
V_9 ) ,
& V_9 ) ;
F_4 ( V_2 , V_3 + F_3 ( struct V_13 , V_10 ) ,
& V_10 ) ;
F_4 ( V_2 , V_3 + F_3 ( struct V_13 , V_11 ) ,
& V_11 ) ;
if ( V_11 <= V_6 ) {
F_5 ( & V_2 -> V_2 ,
L_1 ,
V_11 , V_6 ) ;
return NULL ;
}
if ( V_11 - V_6 < V_4 ) {
F_5 ( & V_2 -> V_2 ,
L_2 ,
V_11 , V_4 ) ;
return NULL ;
}
V_11 -= V_6 ;
if ( V_6 + V_10 < V_10 ) {
F_5 ( & V_2 -> V_2 ,
L_3 ,
V_6 , V_10 ) ;
return NULL ;
}
V_10 += V_6 ;
if ( V_10 & ( V_5 - 1 ) ) {
F_5 ( & V_2 -> V_2 ,
L_4 ,
V_10 , V_5 ) ;
return NULL ;
}
if ( V_11 > V_7 )
V_11 = V_7 ;
if ( V_8 )
* V_8 = V_11 ;
if ( V_4 + V_10 < V_4 ||
V_4 + V_10 > F_6 ( V_2 , V_9 ) ) {
F_5 ( & V_2 -> V_2 ,
L_5
L_6 ,
V_4 , V_10 ,
V_9 , ( unsigned long ) F_6 ( V_2 , V_9 ) ) ;
return NULL ;
}
V_12 = F_7 ( V_2 , V_9 , V_10 , V_11 ) ;
if ( ! V_12 )
F_5 ( & V_2 -> V_2 ,
L_7 ,
V_11 , V_10 , V_9 ) ;
return V_12 ;
}
static void F_8 ( T_5 V_14 , T_6 T_1 * V_15 , T_6 T_1 * V_16 )
{
F_9 ( ( T_3 ) V_14 , V_15 ) ;
F_9 ( V_14 >> 32 , V_16 ) ;
}
static T_5 F_10 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_11 ( V_18 ) ;
T_5 V_21 ;
F_9 ( 0 , & V_20 -> V_22 -> V_23 ) ;
V_21 = F_12 ( & V_20 -> V_22 -> V_24 ) ;
F_9 ( 1 , & V_20 -> V_22 -> V_23 ) ;
V_21 |= ( ( T_5 ) F_12 ( & V_20 -> V_22 -> V_24 ) << 32 ) ;
return V_21 ;
}
static int F_13 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_11 ( V_18 ) ;
F_14 ( V_18 ) ;
if ( ! F_15 ( V_18 , V_25 ) ) {
F_5 ( & V_18 -> V_2 , L_8
L_9 ) ;
return - V_26 ;
}
F_9 ( 0 , & V_20 -> V_22 -> V_27 ) ;
F_9 ( ( T_3 ) V_18 -> V_21 , & V_20 -> V_22 -> V_28 ) ;
F_9 ( 1 , & V_20 -> V_22 -> V_27 ) ;
F_9 ( V_18 -> V_21 >> 32 , & V_20 -> V_22 -> V_28 ) ;
return 0 ;
}
static void F_16 ( struct V_17 * V_18 , unsigned V_10 ,
void * V_29 , unsigned V_8 )
{
struct V_19 * V_20 = F_11 ( V_18 ) ;
T_4 V_30 ;
T_7 V_31 ;
T_6 V_32 ;
F_17 ( V_10 + V_8 > V_20 -> V_33 ) ;
switch ( V_8 ) {
case 1 :
V_30 = F_18 ( V_20 -> V_34 + V_10 ) ;
memcpy ( V_29 , & V_30 , sizeof V_30 ) ;
break;
case 2 :
V_31 = F_19 ( F_20 ( V_20 -> V_34 + V_10 ) ) ;
memcpy ( V_29 , & V_31 , sizeof V_31 ) ;
break;
case 4 :
V_32 = F_21 ( F_12 ( V_20 -> V_34 + V_10 ) ) ;
memcpy ( V_29 , & V_32 , sizeof V_32 ) ;
break;
case 8 :
V_32 = F_21 ( F_12 ( V_20 -> V_34 + V_10 ) ) ;
memcpy ( V_29 , & V_32 , sizeof V_32 ) ;
V_32 = F_21 ( F_12 ( V_20 -> V_34 + V_10 + sizeof V_32 ) ) ;
memcpy ( V_29 + sizeof V_32 , & V_32 , sizeof V_32 ) ;
break;
default:
F_22 () ;
}
}
static void F_23 ( struct V_17 * V_18 , unsigned V_10 ,
const void * V_29 , unsigned V_8 )
{
struct V_19 * V_20 = F_11 ( V_18 ) ;
T_4 V_30 ;
T_7 V_31 ;
T_6 V_32 ;
F_17 ( V_10 + V_8 > V_20 -> V_33 ) ;
switch ( V_8 ) {
case 1 :
memcpy ( & V_30 , V_29 , sizeof V_30 ) ;
F_24 ( V_30 , V_20 -> V_34 + V_10 ) ;
break;
case 2 :
memcpy ( & V_31 , V_29 , sizeof V_31 ) ;
F_25 ( F_26 ( V_31 ) , V_20 -> V_34 + V_10 ) ;
break;
case 4 :
memcpy ( & V_32 , V_29 , sizeof V_32 ) ;
F_9 ( F_27 ( V_32 ) , V_20 -> V_34 + V_10 ) ;
break;
case 8 :
memcpy ( & V_32 , V_29 , sizeof V_32 ) ;
F_9 ( F_27 ( V_32 ) , V_20 -> V_34 + V_10 ) ;
memcpy ( & V_32 , V_29 + sizeof V_32 , sizeof V_32 ) ;
F_9 ( F_27 ( V_32 ) , V_20 -> V_34 + V_10 + sizeof V_32 ) ;
break;
default:
F_22 () ;
}
}
static T_3 F_28 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_11 ( V_18 ) ;
return F_18 ( & V_20 -> V_22 -> V_35 ) ;
}
static T_4 F_29 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_11 ( V_18 ) ;
return F_18 ( & V_20 -> V_22 -> V_36 ) ;
}
static void F_30 ( struct V_17 * V_18 , T_4 V_37 )
{
struct V_19 * V_20 = F_11 ( V_18 ) ;
F_17 ( V_37 == 0 ) ;
F_24 ( V_37 , & V_20 -> V_22 -> V_36 ) ;
}
static void F_31 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_11 ( V_18 ) ;
F_24 ( 0 , & V_20 -> V_22 -> V_36 ) ;
F_18 ( & V_20 -> V_22 -> V_36 ) ;
F_32 ( V_18 ) ;
}
static T_8 F_33 ( struct V_19 * V_20 , T_8 V_38 )
{
F_25 ( V_38 , & V_20 -> V_22 -> V_39 ) ;
return F_20 ( & V_20 -> V_22 -> V_39 ) ;
}
static T_2 F_34 ( T_8 V_40 )
{
return F_35 ( F_36 ( V_40 , V_41 ) ) ;
}
static void * F_37 ( int * V_40 )
{
void * V_42 ;
for (; * V_40 && F_34 ( * V_40 ) > V_43 ; * V_40 /= 2 ) {
V_42 = F_38 ( F_34 ( * V_40 ) ,
V_44 | V_45 | V_46 ) ;
if ( V_42 )
return V_42 ;
}
if ( ! * V_40 )
return NULL ;
return F_38 ( F_34 ( * V_40 ) , V_44 | V_45 ) ;
}
static struct V_47 * F_39 ( struct V_19 * V_20 ,
struct V_48 * V_49 ,
unsigned V_50 ,
void (* F_40)( struct V_47 * V_51 ) ,
const char * V_52 ,
T_8 V_53 )
{
struct V_54 T_1 * V_55 = V_20 -> V_22 ;
struct V_47 * V_51 ;
T_8 V_40 , V_3 ;
int V_56 ;
if ( V_50 >= F_20 ( & V_55 -> V_57 ) )
return F_41 ( - V_58 ) ;
F_25 ( V_50 , & V_55 -> V_59 ) ;
V_40 = F_20 ( & V_55 -> V_60 ) ;
if ( ! V_40 || F_20 ( & V_55 -> V_61 ) )
return F_41 ( - V_58 ) ;
if ( V_40 & ( V_40 - 1 ) ) {
F_42 ( & V_20 -> V_1 -> V_2 , L_10 , V_40 ) ;
return F_41 ( - V_26 ) ;
}
V_3 = F_20 ( & V_55 -> V_62 ) ;
V_49 -> V_40 = V_40 ;
V_49 -> V_63 = V_53 ;
V_49 -> V_64 = F_37 ( & V_49 -> V_40 ) ;
if ( V_49 -> V_64 == NULL )
return F_41 ( - V_65 ) ;
V_51 = F_43 ( V_50 , V_49 -> V_40 ,
V_41 , & V_20 -> V_18 ,
true , V_49 -> V_64 , V_66 , F_40 , V_52 ) ;
if ( ! V_51 ) {
V_56 = - V_65 ;
goto V_67;
}
F_25 ( V_40 , & V_55 -> V_60 ) ;
F_8 ( F_44 ( V_49 -> V_64 ) ,
& V_55 -> V_68 , & V_55 -> V_69 ) ;
F_8 ( F_44 ( F_45 ( V_51 ) ) ,
& V_55 -> V_70 , & V_55 -> V_71 ) ;
F_8 ( F_44 ( F_46 ( V_51 ) ) ,
& V_55 -> V_72 , & V_55 -> V_73 ) ;
if ( V_20 -> V_74 ) {
if ( ( T_5 ) V_3 * V_20 -> V_75 + 2
> V_20 -> V_76 ) {
F_42 ( & V_20 -> V_1 -> V_2 ,
L_11
L_12 ,
V_3 , V_20 -> V_75 ,
V_50 , V_20 -> V_76 ) ;
V_56 = - V_26 ;
goto V_77;
}
V_51 -> V_78 = ( void V_79 * ) V_20 -> V_74 +
V_3 * V_20 -> V_75 ;
} else {
V_51 -> V_78 = ( void V_79 * ) F_1 ( V_20 -> V_1 ,
V_20 -> V_80 , 2 , 2 ,
V_3 * V_20 -> V_75 , 2 ,
NULL ) ;
}
if ( ! V_51 -> V_78 ) {
V_56 = - V_65 ;
goto V_77;
}
if ( V_53 != V_81 ) {
F_25 ( V_53 , & V_55 -> V_82 ) ;
V_53 = F_20 ( & V_55 -> V_82 ) ;
if ( V_53 == V_81 ) {
V_56 = - V_83 ;
goto V_84;
}
}
return V_51 ;
V_84:
if ( ! V_20 -> V_74 )
F_47 ( V_20 -> V_1 , ( void T_1 V_79 * ) V_51 -> V_78 ) ;
V_77:
F_48 ( V_51 ) ;
V_67:
F_49 ( V_49 -> V_64 , F_34 ( V_49 -> V_40 ) ) ;
return F_41 ( V_56 ) ;
}
static int F_50 ( struct V_17 * V_18 , unsigned V_85 ,
struct V_47 * V_86 [] ,
T_9 * V_87 [] ,
const char * V_88 [] )
{
struct V_19 * V_20 = F_11 ( V_18 ) ;
struct V_47 * V_51 ;
int V_89 = F_51 ( V_18 , V_85 , V_86 , V_87 , V_88 ) ;
if ( V_89 )
return V_89 ;
F_52 (vq, &vdev->vqs, list) {
F_25 ( V_51 -> V_50 , & V_20 -> V_22 -> V_59 ) ;
F_25 ( 1 , & V_20 -> V_22 -> V_61 ) ;
}
return 0 ;
}
static void F_53 ( struct V_48 * V_49 )
{
struct V_47 * V_51 = V_49 -> V_51 ;
struct V_19 * V_20 = F_11 ( V_51 -> V_18 ) ;
F_25 ( V_51 -> V_50 , & V_20 -> V_22 -> V_59 ) ;
if ( V_20 -> V_90 ) {
F_25 ( V_81 ,
& V_20 -> V_22 -> V_82 ) ;
F_20 ( & V_20 -> V_22 -> V_82 ) ;
}
if ( ! V_20 -> V_74 )
F_47 ( V_20 -> V_1 , ( void V_79 T_1 * ) V_51 -> V_78 ) ;
F_48 ( V_51 ) ;
F_49 ( V_49 -> V_64 , F_34 ( V_49 -> V_40 ) ) ;
}
static inline int F_54 ( struct V_1 * V_2 , T_4 V_91 ,
T_3 V_92 )
{
int V_93 ;
for ( V_93 = F_55 ( V_2 , V_94 ) ;
V_93 > 0 ;
V_93 = F_56 ( V_2 , V_93 , V_94 ) ) {
T_4 type , V_9 ;
F_2 ( V_2 , V_93 + F_3 ( struct V_13 ,
V_91 ) ,
& type ) ;
F_2 ( V_2 , V_93 + F_3 ( struct V_13 ,
V_9 ) ,
& V_9 ) ;
if ( V_9 > 0x5 )
continue;
if ( type == V_91 ) {
if ( F_6 ( V_2 , V_9 ) &&
F_57 ( V_2 , V_9 ) & V_92 )
return V_93 ;
}
}
return 0 ;
}
static inline void F_58 ( void )
{
F_59 ( V_95 !=
F_3 ( struct V_13 , V_96 ) ) ;
F_59 ( V_97 !=
F_3 ( struct V_13 , V_98 ) ) ;
F_59 ( V_99 !=
F_3 ( struct V_13 , V_100 ) ) ;
F_59 ( V_101 !=
F_3 ( struct V_13 , V_91 ) ) ;
F_59 ( V_102 !=
F_3 ( struct V_13 , V_9 ) ) ;
F_59 ( V_103 !=
F_3 ( struct V_13 , V_10 ) ) ;
F_59 ( V_104 !=
F_3 ( struct V_13 , V_11 ) ) ;
F_59 ( V_105 !=
F_3 ( struct V_106 ,
V_107 ) ) ;
F_59 ( V_108 !=
F_3 ( struct V_54 ,
V_23 ) ) ;
F_59 ( V_109 !=
F_3 ( struct V_54 , V_24 ) ) ;
F_59 ( V_110 !=
F_3 ( struct V_54 ,
V_27 ) ) ;
F_59 ( V_111 !=
F_3 ( struct V_54 , V_28 ) ) ;
F_59 ( V_112 !=
F_3 ( struct V_54 , V_39 ) ) ;
F_59 ( V_113 !=
F_3 ( struct V_54 , V_57 ) ) ;
F_59 ( V_114 !=
F_3 ( struct V_54 , V_36 ) ) ;
F_59 ( V_115 !=
F_3 ( struct V_54 , V_35 ) ) ;
F_59 ( V_116 !=
F_3 ( struct V_54 , V_59 ) ) ;
F_59 ( V_117 !=
F_3 ( struct V_54 , V_60 ) ) ;
F_59 ( V_118 !=
F_3 ( struct V_54 , V_82 ) ) ;
F_59 ( V_119 !=
F_3 ( struct V_54 , V_61 ) ) ;
F_59 ( V_120 !=
F_3 ( struct V_54 , V_62 ) ) ;
F_59 ( V_121 !=
F_3 ( struct V_54 , V_68 ) ) ;
F_59 ( V_122 !=
F_3 ( struct V_54 , V_69 ) ) ;
F_59 ( V_123 !=
F_3 ( struct V_54 , V_70 ) ) ;
F_59 ( V_124 !=
F_3 ( struct V_54 , V_71 ) ) ;
F_59 ( V_125 !=
F_3 ( struct V_54 , V_72 ) ) ;
F_59 ( V_126 !=
F_3 ( struct V_54 , V_73 ) ) ;
}
int F_60 ( struct V_19 * V_20 )
{
struct V_1 * V_1 = V_20 -> V_1 ;
int V_56 , V_22 , V_127 , V_128 , V_34 ;
T_3 V_129 ;
T_3 V_130 ;
F_58 () ;
if ( V_1 -> V_34 < 0x1000 || V_1 -> V_34 > 0x107f )
return - V_131 ;
if ( V_1 -> V_34 < 0x1040 ) {
V_20 -> V_18 . V_132 . V_34 = V_1 -> V_133 ;
} else {
V_20 -> V_18 . V_132 . V_34 = V_1 -> V_34 - 0x1040 ;
}
V_20 -> V_18 . V_132 . V_134 = V_1 -> V_135 ;
if ( F_61 ( V_20 -> V_18 . V_132 ) )
return - V_131 ;
V_22 = F_54 ( V_1 , V_136 ,
V_137 | V_138 ) ;
if ( ! V_22 ) {
F_62 ( & V_1 -> V_2 ,
L_13 ) ;
return - V_131 ;
}
V_127 = F_54 ( V_1 , V_139 ,
V_137 | V_138 ) ;
V_128 = F_54 ( V_1 , V_140 ,
V_137 | V_138 ) ;
if ( ! V_127 || ! V_128 ) {
F_5 ( & V_1 -> V_2 ,
L_14 ,
V_22 , V_127 , V_128 ) ;
return - V_26 ;
}
V_34 = F_54 ( V_1 , V_141 ,
V_137 | V_138 ) ;
V_56 = - V_26 ;
V_20 -> V_22 = F_1 ( V_1 , V_22 ,
sizeof( struct V_54 ) , 4 ,
0 , sizeof( struct V_54 ) ,
NULL ) ;
if ( ! V_20 -> V_22 )
goto V_142;
V_20 -> V_127 = F_1 ( V_1 , V_127 , sizeof( T_4 ) , 1 ,
0 , 1 ,
NULL ) ;
if ( ! V_20 -> V_127 )
goto V_143;
F_4 ( V_1 ,
V_128 + F_3 ( struct V_106 ,
V_107 ) ,
& V_20 -> V_75 ) ;
F_4 ( V_1 ,
V_128 + F_3 ( struct V_106 ,
V_144 . V_11 ) ,
& V_129 ) ;
F_4 ( V_1 ,
V_128 + F_3 ( struct V_106 ,
V_144 . V_11 ) ,
& V_130 ) ;
if ( ( T_5 ) V_129 + ( V_130 % V_43 ) <= V_43 ) {
V_20 -> V_74 = F_1 ( V_1 , V_128 , 2 , 2 ,
0 , V_129 ,
& V_20 -> V_76 ) ;
if ( ! V_20 -> V_74 )
goto V_77;
} else {
V_20 -> V_80 = V_128 ;
}
if ( V_34 ) {
V_20 -> V_34 = F_1 ( V_1 , V_34 , 0 , 4 ,
0 , V_43 ,
& V_20 -> V_33 ) ;
if ( ! V_20 -> V_34 )
goto V_145;
V_20 -> V_18 . V_146 = & V_147 ;
} else {
V_20 -> V_18 . V_146 = & V_148 ;
}
V_20 -> V_149 = F_33 ;
V_20 -> F_39 = F_39 ;
V_20 -> F_53 = F_53 ;
return 0 ;
V_145:
if ( V_20 -> V_74 )
F_47 ( V_1 , V_20 -> V_74 ) ;
V_77:
F_47 ( V_1 , V_20 -> V_127 ) ;
V_143:
F_47 ( V_1 , V_20 -> V_22 ) ;
V_142:
return V_56 ;
}
void F_63 ( struct V_19 * V_20 )
{
struct V_1 * V_1 = V_20 -> V_1 ;
if ( V_20 -> V_34 )
F_47 ( V_1 , V_20 -> V_34 ) ;
if ( V_20 -> V_74 )
F_47 ( V_1 , V_20 -> V_74 ) ;
F_47 ( V_1 , V_20 -> V_127 ) ;
F_47 ( V_1 , V_20 -> V_22 ) ;
}
