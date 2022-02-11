static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
if ( F_3 ( V_9 -> V_10 ) )
F_4 ( L_1 , V_2 ) ;
F_5 ( V_7 , V_9 -> V_11 , NULL ) ;
if ( V_9 -> V_12 . V_13 ) {
F_6 ( & V_9 -> V_12 ) ;
F_7 ( & V_9 -> V_12 ) ;
}
F_8 ( V_9 ) ;
}
static void
F_9 ( struct V_8 * V_9 , T_1 V_14 ,
int * V_15 , int * V_16 , int * V_17 )
{
struct V_3 * V_4 = F_2 ( V_9 -> V_2 . V_5 ) ;
if ( V_4 -> V_18 < V_19 ) {
if ( V_9 -> V_20 ) {
if ( V_4 -> V_21 >= 0x40 ) {
* V_15 = 65536 ;
* V_16 = F_10 ( * V_16 , 64 * V_9 -> V_20 ) ;
} else if ( V_4 -> V_21 >= 0x30 ) {
* V_15 = 32768 ;
* V_16 = F_10 ( * V_16 , 64 * V_9 -> V_20 ) ;
} else if ( V_4 -> V_21 >= 0x20 ) {
* V_15 = 16384 ;
* V_16 = F_10 ( * V_16 , 64 * V_9 -> V_20 ) ;
} else if ( V_4 -> V_21 >= 0x10 ) {
* V_15 = 16384 ;
* V_16 = F_10 ( * V_16 , 32 * V_9 -> V_20 ) ;
}
}
} else {
if ( F_11 ( V_4 -> V_22 ) ) {
if ( ! ( V_14 & V_23 ) && * V_16 > 256 * 1024 )
* V_17 = V_4 -> V_22 -> V_24 ;
else
* V_17 = V_4 -> V_22 -> V_25 ;
} else {
* V_17 = 12 ;
}
* V_16 = F_10 ( * V_16 , ( 1 << * V_17 ) ) ;
* V_15 = F_12 ( ( 1 << * V_17 ) , * V_15 ) ;
}
* V_16 = F_10 ( * V_16 , V_26 ) ;
}
int
F_13 ( struct V_6 * V_7 , struct V_27 * V_28 ,
int V_16 , int V_15 , T_2 V_14 , T_2 V_20 ,
T_2 V_29 , struct V_8 * * V_30 )
{
struct V_3 * V_4 = V_7 -> V_31 ;
struct V_8 * V_9 ;
int V_32 = 0 , V_17 = 0 ;
V_9 = F_14 ( sizeof( struct V_8 ) , V_33 ) ;
if ( ! V_9 )
return - V_34 ;
F_15 ( & V_9 -> V_35 ) ;
F_15 ( & V_9 -> V_36 ) ;
V_9 -> V_20 = V_20 ;
V_9 -> V_29 = V_29 ;
V_9 -> V_2 . V_5 = & V_4 -> V_37 . V_5 ;
F_9 ( V_9 , V_14 , & V_15 , & V_16 , & V_17 ) ;
V_15 >>= V_38 ;
if ( V_4 -> V_22 ) {
V_32 = F_16 ( V_4 -> V_22 , V_16 , V_17 ,
V_39 , & V_9 -> V_12 ) ;
if ( V_32 ) {
F_8 ( V_9 ) ;
return V_32 ;
}
}
V_9 -> V_2 . V_40 . V_41 = V_16 >> V_38 ;
F_17 ( V_9 , V_14 , 0 ) ;
V_9 -> V_42 = V_28 ;
V_32 = F_18 ( & V_4 -> V_37 . V_5 , & V_9 -> V_2 , V_16 ,
V_43 , & V_9 -> V_44 , V_15 , 0 ,
false , NULL , V_16 , F_1 ) ;
if ( V_32 ) {
return V_32 ;
}
V_9 -> V_42 = NULL ;
if ( V_9 -> V_12 . V_13 )
V_9 -> V_2 . V_45 = V_9 -> V_12 . V_45 ;
* V_30 = V_9 ;
return 0 ;
}
static void
F_19 ( T_2 * V_46 , unsigned * V_47 , T_2 type , T_2 V_14 )
{
* V_47 = 0 ;
if ( type & V_48 )
V_46 [ ( * V_47 ) ++ ] = V_48 | V_14 ;
if ( type & V_23 )
V_46 [ ( * V_47 ) ++ ] = V_23 | V_14 ;
if ( type & V_49 )
V_46 [ ( * V_47 ) ++ ] = V_49 | V_14 ;
}
static void
F_20 ( struct V_8 * V_9 , T_2 type )
{
struct V_3 * V_4 = F_2 ( V_9 -> V_2 . V_5 ) ;
int V_50 = V_4 -> V_51 >> V_38 ;
if ( V_4 -> V_18 == V_52 &&
V_9 -> V_20 && ( type & V_48 ) &&
V_9 -> V_2 . V_40 . V_41 < V_50 / 2 ) {
if ( V_9 -> V_29 & V_53 ) {
V_9 -> V_44 . V_54 = V_50 / 2 ;
V_9 -> V_44 . V_55 = ~ 0 ;
} else {
V_9 -> V_44 . V_54 = 0 ;
V_9 -> V_44 . V_55 = V_50 / 2 ;
}
}
}
void
F_17 ( struct V_8 * V_9 , T_2 type , T_2 V_56 )
{
struct V_57 * V_46 = & V_9 -> V_44 ;
T_2 V_14 = V_58 |
( V_9 -> V_59 ? V_60 : 0 ) ;
V_46 -> V_44 = V_9 -> V_61 ;
F_19 ( V_9 -> V_61 , & V_46 -> V_62 ,
type , V_14 ) ;
V_46 -> V_63 = V_9 -> V_64 ;
F_19 ( V_9 -> V_64 , & V_46 -> V_65 ,
type | V_56 , V_14 ) ;
F_20 ( V_9 , type ) ;
}
int
F_21 ( struct V_8 * V_9 , T_2 V_66 )
{
struct V_3 * V_4 = F_2 ( V_9 -> V_2 . V_5 ) ;
struct V_1 * V_2 = & V_9 -> V_2 ;
int V_32 ;
if ( V_9 -> V_59 && ! ( V_66 & ( 1 << V_2 -> V_40 . V_67 ) ) ) {
F_22 ( F_2 ( V_2 -> V_5 ) -> V_7 ,
L_2 , V_2 ,
1 << V_2 -> V_40 . V_67 , V_66 ) ;
return - V_68 ;
}
if ( V_9 -> V_59 ++ )
return 0 ;
V_32 = F_23 ( V_2 , false , false , false , 0 ) ;
if ( V_32 )
goto V_69;
F_17 ( V_9 , V_66 , 0 ) ;
V_32 = F_24 ( V_9 , false , false , false ) ;
if ( V_32 == 0 ) {
switch ( V_2 -> V_40 . V_67 ) {
case V_70 :
V_4 -> V_71 -= V_2 -> V_40 . V_16 ;
break;
case V_72 :
V_4 -> V_73 . V_74 -= V_2 -> V_40 . V_16 ;
break;
default:
break;
}
}
F_25 ( V_2 ) ;
V_69:
if ( F_3 ( V_32 ) )
V_9 -> V_59 -- ;
return V_32 ;
}
int
F_26 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_2 ( V_9 -> V_2 . V_5 ) ;
struct V_1 * V_2 = & V_9 -> V_2 ;
int V_32 ;
if ( -- V_9 -> V_59 )
return 0 ;
V_32 = F_23 ( V_2 , false , false , false , 0 ) ;
if ( V_32 )
return V_32 ;
F_17 ( V_9 , V_2 -> V_40 . V_44 , 0 ) ;
V_32 = F_24 ( V_9 , false , false , false ) ;
if ( V_32 == 0 ) {
switch ( V_2 -> V_40 . V_67 ) {
case V_70 :
V_4 -> V_71 += V_2 -> V_40 . V_16 ;
break;
case V_72 :
V_4 -> V_73 . V_74 += V_2 -> V_40 . V_16 ;
break;
default:
break;
}
}
F_25 ( V_2 ) ;
return V_32 ;
}
int
F_27 ( struct V_8 * V_9 )
{
int V_32 ;
V_32 = F_23 ( & V_9 -> V_2 , false , false , false , 0 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_28 ( & V_9 -> V_2 , 0 , V_9 -> V_2 . V_40 . V_41 , & V_9 -> V_75 ) ;
F_25 ( & V_9 -> V_2 ) ;
return V_32 ;
}
void
F_29 ( struct V_8 * V_9 )
{
if ( V_9 )
F_30 ( & V_9 -> V_75 ) ;
}
int
F_24 ( struct V_8 * V_9 , bool V_76 ,
bool V_77 , bool V_78 )
{
int V_32 ;
V_32 = F_31 ( & V_9 -> V_2 , & V_9 -> V_44 , V_76 ,
V_77 , V_78 ) ;
if ( V_32 )
return V_32 ;
if ( V_9 -> V_12 . V_13 )
V_9 -> V_2 . V_45 = V_9 -> V_12 . V_45 ;
return 0 ;
}
T_3
F_32 ( struct V_8 * V_9 , unsigned V_79 )
{
bool V_80 ;
T_3 * V_40 = F_33 ( & V_9 -> V_75 , & V_80 ) ;
V_40 = & V_40 [ V_79 ] ;
if ( V_80 )
return F_34 ( ( void V_81 V_82 * ) V_40 ) ;
else
return * V_40 ;
}
void
F_35 ( struct V_8 * V_9 , unsigned V_79 , T_3 V_83 )
{
bool V_80 ;
T_3 * V_40 = F_33 ( & V_9 -> V_75 , & V_80 ) ;
V_40 = & V_40 [ V_79 ] ;
if ( V_80 )
F_36 ( V_83 , ( void V_81 V_82 * ) V_40 ) ;
else
* V_40 = V_83 ;
}
T_1
F_37 ( struct V_8 * V_9 , unsigned V_79 )
{
bool V_80 ;
T_1 * V_40 = F_33 ( & V_9 -> V_75 , & V_80 ) ;
V_40 = & V_40 [ V_79 ] ;
if ( V_80 )
return F_38 ( ( void V_81 V_82 * ) V_40 ) ;
else
return * V_40 ;
}
void
F_39 ( struct V_8 * V_9 , unsigned V_79 , T_1 V_83 )
{
bool V_80 ;
T_1 * V_40 = F_33 ( & V_9 -> V_75 , & V_80 ) ;
V_40 = & V_40 [ V_79 ] ;
if ( V_80 )
F_40 ( V_83 , ( void V_81 V_82 * ) V_40 ) ;
else
* V_40 = V_83 ;
}
static struct V_84 *
F_41 ( struct V_85 * V_5 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
switch ( V_4 -> V_73 . type ) {
#if V_86
case V_87 :
return F_42 ( V_5 , V_7 -> V_88 -> V_89 ) ;
#endif
case V_90 :
case V_91 :
return F_43 ( V_7 ) ;
default:
F_22 ( V_7 , L_3 ,
V_4 -> V_73 . type ) ;
break;
}
return NULL ;
}
static int
F_44 ( struct V_85 * V_5 , T_2 V_14 )
{
return 0 ;
}
static int
F_45 ( struct V_85 * V_5 , T_2 type ,
struct V_92 * V_93 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
switch ( type ) {
case V_94 :
V_93 -> V_14 = V_95 ;
V_93 -> V_96 = V_58 ;
V_93 -> V_97 = V_98 ;
break;
case V_70 :
if ( V_4 -> V_18 >= V_19 ) {
V_93 -> V_99 = & V_100 ;
V_93 -> V_101 = false ;
V_93 -> V_102 = true ;
} else {
V_93 -> V_99 = & V_103 ;
}
V_93 -> V_14 = V_104 |
V_95 ;
V_93 -> V_96 = V_105 |
V_106 ;
V_93 -> V_97 = V_106 ;
break;
case V_72 :
if ( V_4 -> V_18 >= V_19 )
V_93 -> V_99 = & V_107 ;
else
V_93 -> V_99 = & V_103 ;
switch ( V_4 -> V_73 . type ) {
case V_87 :
V_93 -> V_14 = V_95 ;
V_93 -> V_96 = V_105 |
V_106 ;
V_93 -> V_97 = V_106 ;
break;
case V_90 :
case V_91 :
V_93 -> V_14 = V_95 |
V_108 ;
V_93 -> V_96 = V_58 ;
V_93 -> V_97 = V_98 ;
V_93 -> V_109 = V_4 -> V_73 . V_110 ;
break;
default:
F_22 ( V_7 , L_4 ,
V_4 -> V_73 . type ) ;
return - V_68 ;
}
break;
default:
F_22 ( V_7 , L_5 , ( unsigned ) type ) ;
return - V_68 ;
}
return 0 ;
}
static void
F_46 ( struct V_1 * V_2 , struct V_57 * V_46 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
switch ( V_2 -> V_40 . V_67 ) {
case V_70 :
F_17 ( V_9 , V_23 ,
V_49 ) ;
break;
default:
F_17 ( V_9 , V_49 , 0 ) ;
break;
}
* V_46 = V_9 -> V_44 ;
}
static int
F_47 ( struct V_27 * V_28 ,
struct V_8 * V_9 , bool V_111 ,
bool V_77 , bool V_78 ,
struct V_112 * V_113 )
{
struct V_114 * V_115 = NULL ;
int V_32 ;
V_32 = F_48 ( V_28 , & V_115 , true ) ;
if ( V_32 )
return V_32 ;
V_32 = F_49 ( & V_9 -> V_2 , V_115 , NULL , V_111 ,
V_77 , V_78 , V_113 ) ;
F_50 ( & V_115 ) ;
return V_32 ;
}
static int
F_51 ( struct V_27 * V_28 , struct V_1 * V_2 ,
struct V_112 * V_116 , struct V_112 * V_113 )
{
struct V_117 * V_118 = V_116 -> V_119 ;
struct V_117 * V_120 = V_113 -> V_119 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
T_1 V_121 = V_113 -> V_41 ;
T_4 V_122 , V_123 ;
int V_32 ;
V_122 = V_118 -> V_124 . V_45 ;
if ( V_120 -> V_124 . V_13 )
V_123 = V_120 -> V_124 . V_45 ;
else
V_123 = V_9 -> V_12 . V_45 ;
V_121 = V_113 -> V_41 ;
while ( V_121 ) {
int V_125 = ( V_121 > 2047 ) ? 2047 : V_121 ;
V_32 = F_52 ( V_28 , 12 ) ;
if ( V_32 )
return V_32 ;
F_53 ( V_28 , 2 , V_126 , 0x0238 , 2 ) ;
F_54 ( V_28 , F_55 ( V_123 ) ) ;
F_54 ( V_28 , F_56 ( V_123 ) ) ;
F_53 ( V_28 , 2 , V_126 , 0x030c , 6 ) ;
F_54 ( V_28 , F_55 ( V_122 ) ) ;
F_54 ( V_28 , F_56 ( V_122 ) ) ;
F_54 ( V_28 , V_26 ) ;
F_54 ( V_28 , V_26 ) ;
F_54 ( V_28 , V_26 ) ;
F_54 ( V_28 , V_125 ) ;
F_53 ( V_28 , 2 , V_126 , 0x0300 , 1 ) ;
F_54 ( V_28 , 0x00100110 ) ;
V_121 -= V_125 ;
V_122 += ( V_26 * V_125 ) ;
V_123 += ( V_26 * V_125 ) ;
}
return 0 ;
}
static int
F_57 ( struct V_27 * V_28 , struct V_1 * V_2 ,
struct V_112 * V_116 , struct V_112 * V_113 )
{
struct V_117 * V_118 = V_116 -> V_119 ;
struct V_117 * V_120 = V_113 -> V_119 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
T_4 V_127 = ( V_113 -> V_41 << V_38 ) ;
T_4 V_122 , V_123 ;
int V_32 ;
V_122 = V_118 -> V_124 . V_45 ;
if ( V_120 -> V_124 . V_13 )
V_123 = V_120 -> V_124 . V_45 ;
else
V_123 = V_9 -> V_12 . V_45 ;
while ( V_127 ) {
T_1 V_128 , V_129 , V_130 ;
V_128 = F_58 ( V_127 , ( T_4 ) ( 4 * 1024 * 1024 ) ) ;
V_129 = 16 * 4 ;
V_130 = V_128 / V_129 ;
if ( V_113 -> V_67 == V_70 &&
F_59 ( V_9 ) ) {
V_32 = F_52 ( V_28 , 8 ) ;
if ( V_32 )
return V_32 ;
F_60 ( V_28 , V_126 , 0x0200 , 7 ) ;
F_54 ( V_28 , 0 ) ;
F_54 ( V_28 , 0 ) ;
F_54 ( V_28 , V_129 ) ;
F_54 ( V_28 , V_130 ) ;
F_54 ( V_28 , 1 ) ;
F_54 ( V_28 , 0 ) ;
F_54 ( V_28 , 0 ) ;
} else {
V_32 = F_52 ( V_28 , 2 ) ;
if ( V_32 )
return V_32 ;
F_60 ( V_28 , V_126 , 0x0200 , 1 ) ;
F_54 ( V_28 , 1 ) ;
}
if ( V_116 -> V_67 == V_70 &&
F_59 ( V_9 ) ) {
V_32 = F_52 ( V_28 , 8 ) ;
if ( V_32 )
return V_32 ;
F_60 ( V_28 , V_126 , 0x021c , 7 ) ;
F_54 ( V_28 , 0 ) ;
F_54 ( V_28 , 0 ) ;
F_54 ( V_28 , V_129 ) ;
F_54 ( V_28 , V_130 ) ;
F_54 ( V_28 , 1 ) ;
F_54 ( V_28 , 0 ) ;
F_54 ( V_28 , 0 ) ;
} else {
V_32 = F_52 ( V_28 , 2 ) ;
if ( V_32 )
return V_32 ;
F_60 ( V_28 , V_126 , 0x021c , 1 ) ;
F_54 ( V_28 , 1 ) ;
}
V_32 = F_52 ( V_28 , 14 ) ;
if ( V_32 )
return V_32 ;
F_60 ( V_28 , V_126 , 0x0238 , 2 ) ;
F_54 ( V_28 , F_55 ( V_122 ) ) ;
F_54 ( V_28 , F_55 ( V_123 ) ) ;
F_60 ( V_28 , V_126 , 0x030c , 8 ) ;
F_54 ( V_28 , F_56 ( V_122 ) ) ;
F_54 ( V_28 , F_56 ( V_123 ) ) ;
F_54 ( V_28 , V_129 ) ;
F_54 ( V_28 , V_129 ) ;
F_54 ( V_28 , V_129 ) ;
F_54 ( V_28 , V_130 ) ;
F_54 ( V_28 , 0x00000101 ) ;
F_54 ( V_28 , 0x00000000 ) ;
F_60 ( V_28 , V_126 , V_131 , 1 ) ;
F_54 ( V_28 , 0 ) ;
V_127 -= V_128 ;
V_122 += V_128 ;
V_123 += V_128 ;
}
return 0 ;
}
static inline T_2
F_61 ( struct V_1 * V_2 ,
struct V_27 * V_28 , struct V_112 * V_40 )
{
if ( V_40 -> V_67 == V_72 )
return V_28 -> V_132 ;
return V_28 -> V_133 ;
}
static int
F_62 ( struct V_27 * V_28 , struct V_1 * V_2 ,
struct V_112 * V_116 , struct V_112 * V_113 )
{
T_1 V_122 = V_116 -> V_134 << V_38 ;
T_1 V_123 = V_113 -> V_134 << V_38 ;
T_1 V_121 = V_113 -> V_41 ;
int V_32 ;
V_32 = F_52 ( V_28 , 3 ) ;
if ( V_32 )
return V_32 ;
F_60 ( V_28 , V_126 , V_135 , 2 ) ;
F_54 ( V_28 , F_61 ( V_2 , V_28 , V_116 ) ) ;
F_54 ( V_28 , F_61 ( V_2 , V_28 , V_113 ) ) ;
V_121 = V_113 -> V_41 ;
while ( V_121 ) {
int V_125 = ( V_121 > 2047 ) ? 2047 : V_121 ;
V_32 = F_52 ( V_28 , 11 ) ;
if ( V_32 )
return V_32 ;
F_60 ( V_28 , V_126 ,
V_136 , 8 ) ;
F_54 ( V_28 , V_122 ) ;
F_54 ( V_28 , V_123 ) ;
F_54 ( V_28 , V_26 ) ;
F_54 ( V_28 , V_26 ) ;
F_54 ( V_28 , V_26 ) ;
F_54 ( V_28 , V_125 ) ;
F_54 ( V_28 , 0x00000101 ) ;
F_54 ( V_28 , 0x00000000 ) ;
F_60 ( V_28 , V_126 , V_131 , 1 ) ;
F_54 ( V_28 , 0 ) ;
V_121 -= V_125 ;
V_122 += ( V_26 * V_125 ) ;
V_123 += ( V_26 * V_125 ) ;
}
return 0 ;
}
static int
F_63 ( struct V_1 * V_2 , int V_111 , bool V_137 ,
bool V_77 , bool V_78 ,
struct V_112 * V_113 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_112 * V_116 = & V_2 -> V_40 ;
struct V_27 * V_28 ;
int V_32 ;
V_28 = V_9 -> V_42 ;
if ( ! V_28 ) {
V_28 = V_4 -> V_42 ;
F_64 ( & V_28 -> V_138 , V_139 ) ;
}
if ( V_4 -> V_18 >= V_19 ) {
struct V_117 * V_13 = V_116 -> V_119 ;
if ( ! V_13 -> V_124 . V_13 ) {
T_1 V_17 = V_9 -> V_12 . V_13 -> type ;
if ( V_116 -> V_67 == V_72 )
V_17 = V_9 -> V_12 . V_140 -> V_25 ;
V_32 = F_16 ( V_28 -> V_140 ,
V_116 -> V_41 << V_38 ,
V_17 , V_141 ,
& V_13 -> V_124 ) ;
if ( V_32 )
goto V_69;
}
if ( V_116 -> V_67 == V_70 )
F_65 ( & V_13 -> V_124 , V_13 ) ;
else {
F_66 ( & V_13 -> V_124 , 0 ,
V_116 -> V_41 << V_38 ,
V_13 , V_13 -> V_142 ) ;
}
}
if ( V_4 -> V_18 < V_19 )
V_32 = F_62 ( V_28 , V_2 , & V_2 -> V_40 , V_113 ) ;
else
if ( V_4 -> V_18 < V_143 )
V_32 = F_57 ( V_28 , V_2 , & V_2 -> V_40 , V_113 ) ;
else
V_32 = F_51 ( V_28 , V_2 , & V_2 -> V_40 , V_113 ) ;
if ( V_32 == 0 ) {
V_32 = F_47 ( V_28 , V_9 , V_111 ,
V_77 ,
V_78 , V_113 ) ;
}
V_69:
if ( V_28 == V_4 -> V_42 )
F_67 ( & V_28 -> V_138 ) ;
return V_32 ;
}
static int
F_68 ( struct V_1 * V_2 , bool V_111 , bool V_137 ,
bool V_77 , bool V_78 ,
struct V_112 * V_113 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
T_1 V_144 = V_23 | V_58 ;
struct V_57 V_44 ;
struct V_112 V_145 ;
int V_32 ;
V_44 . V_54 = V_44 . V_55 = 0 ;
V_44 . V_62 = V_44 . V_65 = 1 ;
V_44 . V_44 = V_44 . V_63 = & V_144 ;
V_145 = * V_113 ;
V_145 . V_119 = NULL ;
V_32 = F_69 ( V_2 , & V_44 , & V_145 , V_137 , V_77 , V_78 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_70 ( V_2 -> V_37 , & V_145 ) ;
if ( V_32 )
goto V_69;
if ( V_4 -> V_18 >= V_19 ) {
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_117 * V_13 = V_145 . V_119 ;
struct V_146 * V_12 = & V_9 -> V_12 ;
if ( V_12 -> V_13 -> type != V_12 -> V_140 -> V_25 )
V_12 = & V_13 -> V_124 ;
F_66 ( V_12 , 0 , V_145 . V_41 << V_38 ,
V_13 , V_13 -> V_142 ) ;
}
V_32 = F_63 ( V_2 , true , V_137 , V_77 , V_78 , & V_145 ) ;
if ( V_4 -> V_18 >= V_19 ) {
struct V_8 * V_9 = V_8 ( V_2 ) ;
F_6 ( & V_9 -> V_12 ) ;
}
if ( V_32 )
goto V_69;
V_32 = F_71 ( V_2 , true , V_77 , V_78 , V_113 ) ;
V_69:
F_72 ( V_2 , & V_145 ) ;
return V_32 ;
}
static int
F_73 ( struct V_1 * V_2 , bool V_111 , bool V_137 ,
bool V_77 , bool V_78 ,
struct V_112 * V_113 )
{
T_1 V_144 = V_23 | V_58 ;
struct V_57 V_44 ;
struct V_112 V_145 ;
int V_32 ;
V_44 . V_54 = V_44 . V_55 = 0 ;
V_44 . V_62 = V_44 . V_65 = 1 ;
V_44 . V_44 = V_44 . V_63 = & V_144 ;
V_145 = * V_113 ;
V_145 . V_119 = NULL ;
V_32 = F_69 ( V_2 , & V_44 , & V_145 , V_137 , V_77 , V_78 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_71 ( V_2 , true , V_77 , V_78 , & V_145 ) ;
if ( V_32 )
goto V_69;
V_32 = F_63 ( V_2 , true , V_137 , V_77 , V_78 , V_113 ) ;
if ( V_32 )
goto V_69;
V_69:
F_72 ( V_2 , & V_145 ) ;
return V_32 ;
}
static void
F_74 ( struct V_1 * V_2 , struct V_112 * V_113 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_117 * V_13 = V_113 -> V_119 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_146 * V_12 = & V_9 -> V_12 ;
struct V_147 * V_140 = V_12 -> V_140 ;
if ( V_4 -> V_18 < V_19 )
return;
switch ( V_113 -> V_67 ) {
case V_70 :
F_65 ( V_12 , V_13 ) ;
break;
case V_72 :
if ( V_12 -> V_13 -> type != V_140 -> V_25 ) {
F_6 ( V_12 ) ;
V_12 = & V_13 -> V_124 ;
}
F_66 ( V_12 , 0 , V_113 -> V_41 << V_38 ,
V_13 , V_13 -> V_142 ) ;
break;
default:
F_6 ( & V_9 -> V_12 ) ;
break;
}
}
static int
F_75 ( struct V_1 * V_2 , struct V_112 * V_113 ,
struct V_148 * * V_149 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
T_4 V_45 = V_113 -> V_134 << V_38 ;
* V_149 = NULL ;
if ( V_113 -> V_67 != V_70 )
return 0 ;
if ( V_4 -> V_18 >= V_52 ) {
* V_149 = F_76 ( V_7 , V_45 , V_113 -> V_16 ,
V_9 -> V_20 ,
V_9 -> V_29 ) ;
}
return 0 ;
}
static void
F_77 ( struct V_1 * V_2 ,
struct V_148 * V_149 ,
struct V_148 * * V_150 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
F_5 ( V_7 , * V_150 , V_2 -> V_151 ) ;
* V_150 = V_149 ;
}
static int
F_78 ( struct V_1 * V_2 , bool V_111 , bool V_137 ,
bool V_77 , bool V_78 ,
struct V_112 * V_113 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_112 * V_116 = & V_2 -> V_40 ;
struct V_148 * V_149 = NULL ;
int V_32 = 0 ;
if ( V_4 -> V_18 < V_19 ) {
V_32 = F_75 ( V_2 , V_113 , & V_149 ) ;
if ( V_32 )
return V_32 ;
}
if ( V_116 -> V_67 == V_94 && ! V_2 -> V_37 ) {
F_79 ( V_2 -> V_40 . V_119 != NULL ) ;
V_2 -> V_40 = * V_113 ;
V_113 -> V_119 = NULL ;
goto V_69;
}
if ( ! V_4 -> V_42 ) {
V_32 = F_80 ( V_2 , V_111 , V_77 , V_78 , V_113 ) ;
goto V_69;
}
if ( V_113 -> V_67 == V_94 )
V_32 = F_68 ( V_2 , V_111 , V_137 , V_77 , V_78 , V_113 ) ;
else if ( V_116 -> V_67 == V_94 )
V_32 = F_73 ( V_2 , V_111 , V_137 , V_77 , V_78 , V_113 ) ;
else
V_32 = F_63 ( V_2 , V_111 , V_137 , V_77 , V_78 , V_113 ) ;
if ( ! V_32 )
goto V_69;
V_32 = F_80 ( V_2 , V_111 , V_77 , V_78 , V_113 ) ;
V_69:
if ( V_4 -> V_18 < V_19 ) {
if ( V_32 )
F_77 ( V_2 , NULL , & V_149 ) ;
else
F_77 ( V_2 , V_149 , & V_9 -> V_11 ) ;
}
return V_32 ;
}
static int
F_81 ( struct V_1 * V_2 , struct V_152 * V_153 )
{
return 0 ;
}
static int
F_82 ( struct V_85 * V_5 , struct V_112 * V_40 )
{
struct V_92 * V_93 = & V_5 -> V_93 [ V_40 -> V_67 ] ;
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_32 ;
V_40 -> V_154 . V_155 = NULL ;
V_40 -> V_154 . V_45 = 0 ;
V_40 -> V_154 . V_16 = V_40 -> V_41 << V_38 ;
V_40 -> V_154 . V_156 = 0 ;
V_40 -> V_154 . V_80 = false ;
if ( ! ( V_93 -> V_14 & V_95 ) )
return - V_68 ;
switch ( V_40 -> V_67 ) {
case V_94 :
return 0 ;
case V_72 :
#if V_86
if ( V_4 -> V_73 . type == V_87 ) {
V_40 -> V_154 . V_45 = V_40 -> V_134 << V_38 ;
V_40 -> V_154 . V_156 = V_4 -> V_73 . V_110 ;
V_40 -> V_154 . V_80 = true ;
}
#endif
break;
case V_70 :
{
struct V_117 * V_13 = V_40 -> V_119 ;
T_5 V_17 ;
if ( ! V_4 -> V_157 ) {
V_40 -> V_154 . V_45 = V_40 -> V_134 << V_38 ;
V_40 -> V_154 . V_156 = F_83 ( V_7 -> V_158 , 1 ) ;
V_40 -> V_154 . V_80 = true ;
break;
}
if ( V_4 -> V_18 == V_143 )
V_17 = V_13 -> V_17 ;
else
V_17 = 12 ;
V_32 = F_16 ( V_4 -> V_157 , V_40 -> V_154 . V_16 ,
V_17 , V_39 ,
& V_13 -> V_159 ) ;
if ( V_32 )
return V_32 ;
F_65 ( & V_13 -> V_159 , V_13 ) ;
if ( V_32 ) {
F_7 ( & V_13 -> V_159 ) ;
return V_32 ;
}
V_40 -> V_154 . V_45 = V_13 -> V_159 . V_45 ;
if ( V_4 -> V_18 == V_19 )
V_40 -> V_154 . V_45 -= 0x0020000000ULL ;
V_40 -> V_154 . V_156 = F_83 ( V_7 -> V_158 , 1 ) ;
V_40 -> V_154 . V_80 = true ;
}
break;
default:
return - V_68 ;
}
return 0 ;
}
static void
F_84 ( struct V_85 * V_5 , struct V_112 * V_40 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_117 * V_13 = V_40 -> V_119 ;
if ( ! V_4 -> V_157 || V_40 -> V_67 != V_70 )
return;
if ( ! V_13 -> V_159 . V_13 )
return;
F_6 ( & V_13 -> V_159 ) ;
F_7 ( & V_13 -> V_159 ) ;
}
static int
F_85 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
if ( V_2 -> V_40 . V_67 != V_70 ) {
if ( V_4 -> V_18 < V_19 ||
! F_59 ( V_9 ) )
return 0 ;
}
if ( V_2 -> V_40 . V_134 + V_2 -> V_40 . V_41 < V_4 -> V_160 )
return 0 ;
V_9 -> V_44 . V_54 = 0 ;
V_9 -> V_44 . V_55 = V_4 -> V_160 ;
F_17 ( V_9 , V_70 , 0 ) ;
return F_24 ( V_9 , false , true , false ) ;
}
void
F_86 ( struct V_8 * V_9 , struct V_114 * V_115 )
{
struct V_114 * V_161 ;
if ( F_11 ( V_115 ) )
F_87 ( V_115 ) ;
F_88 ( & V_9 -> V_2 . V_5 -> V_162 ) ;
V_161 = V_9 -> V_2 . V_151 ;
V_9 -> V_2 . V_151 = V_115 ;
F_89 ( & V_9 -> V_2 . V_5 -> V_162 ) ;
F_50 ( & V_161 ) ;
}
