static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
if ( F_3 ( V_9 -> V_10 ) )
F_4 ( L_1 , V_2 ) ;
F_5 ( V_7 , V_9 -> V_11 , NULL ) ;
F_6 ( V_9 ) ;
}
static void
F_7 ( struct V_8 * V_9 , T_1 V_12 ,
int * V_13 , int * V_14 )
{
struct V_3 * V_4 = F_2 ( V_9 -> V_2 . V_5 ) ;
if ( V_4 -> V_15 < V_16 ) {
if ( V_9 -> V_17 ) {
if ( V_4 -> V_18 >= 0x40 ) {
* V_13 = 65536 ;
* V_14 = F_8 ( * V_14 , 64 * V_9 -> V_17 ) ;
} else if ( V_4 -> V_18 >= 0x30 ) {
* V_13 = 32768 ;
* V_14 = F_8 ( * V_14 , 64 * V_9 -> V_17 ) ;
} else if ( V_4 -> V_18 >= 0x20 ) {
* V_13 = 16384 ;
* V_14 = F_8 ( * V_14 , 64 * V_9 -> V_17 ) ;
} else if ( V_4 -> V_18 >= 0x10 ) {
* V_13 = 16384 ;
* V_14 = F_8 ( * V_14 , 32 * V_9 -> V_17 ) ;
}
}
} else {
* V_14 = F_8 ( * V_14 , ( 1 << V_9 -> V_19 ) ) ;
* V_13 = F_9 ( ( 1 << V_9 -> V_19 ) , * V_13 ) ;
}
* V_14 = F_8 ( * V_14 , V_20 ) ;
}
int
F_10 ( struct V_6 * V_7 , int V_14 , int V_13 ,
T_2 V_12 , T_2 V_17 , T_2 V_21 ,
struct V_8 * * V_22 )
{
struct V_3 * V_4 = V_7 -> V_23 ;
struct V_8 * V_9 ;
T_3 V_24 ;
int V_25 ;
V_9 = F_11 ( sizeof( struct V_8 ) , V_26 ) ;
if ( ! V_9 )
return - V_27 ;
F_12 ( & V_9 -> V_28 ) ;
F_12 ( & V_9 -> V_29 ) ;
F_12 ( & V_9 -> V_30 ) ;
V_9 -> V_17 = V_17 ;
V_9 -> V_21 = V_21 ;
V_9 -> V_2 . V_5 = & V_4 -> V_31 . V_5 ;
V_9 -> V_19 = 12 ;
if ( V_4 -> V_32 ) {
if ( ! ( V_12 & V_33 ) && V_14 > 256 * 1024 )
V_9 -> V_19 = V_4 -> V_32 -> V_34 ;
}
F_7 ( V_9 , V_12 , & V_13 , & V_14 ) ;
V_9 -> V_2 . V_35 . V_36 = V_14 >> V_37 ;
F_13 ( V_9 , V_12 , 0 ) ;
V_24 = F_14 ( & V_4 -> V_31 . V_5 , V_14 ,
sizeof( struct V_8 ) ) ;
V_25 = F_15 ( & V_4 -> V_31 . V_5 , & V_9 -> V_2 , V_14 ,
V_38 , & V_9 -> V_39 ,
V_13 >> V_37 , 0 , false , NULL , V_24 ,
F_1 ) ;
if ( V_25 ) {
return V_25 ;
}
* V_22 = V_9 ;
return 0 ;
}
static void
F_16 ( T_2 * V_40 , unsigned * V_41 , T_2 type , T_2 V_12 )
{
* V_41 = 0 ;
if ( type & V_42 )
V_40 [ ( * V_41 ) ++ ] = V_42 | V_12 ;
if ( type & V_33 )
V_40 [ ( * V_41 ) ++ ] = V_33 | V_12 ;
if ( type & V_43 )
V_40 [ ( * V_41 ) ++ ] = V_43 | V_12 ;
}
static void
F_17 ( struct V_8 * V_9 , T_2 type )
{
struct V_3 * V_4 = F_2 ( V_9 -> V_2 . V_5 ) ;
int V_44 = V_4 -> V_45 >> V_37 ;
if ( V_4 -> V_15 == V_46 &&
V_9 -> V_17 && ( type & V_42 ) &&
V_9 -> V_2 . V_35 . V_36 < V_44 / 4 ) {
if ( V_9 -> V_21 & V_47 ) {
V_9 -> V_39 . V_48 = V_44 / 2 ;
V_9 -> V_39 . V_49 = ~ 0 ;
} else {
V_9 -> V_39 . V_48 = 0 ;
V_9 -> V_39 . V_49 = V_44 / 2 ;
}
}
}
void
F_13 ( struct V_8 * V_9 , T_2 type , T_2 V_50 )
{
struct V_51 * V_40 = & V_9 -> V_39 ;
T_2 V_12 = V_52 |
( V_9 -> V_53 ? V_54 : 0 ) ;
V_40 -> V_39 = V_9 -> V_55 ;
F_16 ( V_9 -> V_55 , & V_40 -> V_56 ,
type , V_12 ) ;
V_40 -> V_57 = V_9 -> V_58 ;
F_16 ( V_9 -> V_58 , & V_40 -> V_59 ,
type | V_50 , V_12 ) ;
F_17 ( V_9 , type ) ;
}
int
F_18 ( struct V_8 * V_9 , T_2 V_60 )
{
struct V_3 * V_4 = F_2 ( V_9 -> V_2 . V_5 ) ;
struct V_1 * V_2 = & V_9 -> V_2 ;
int V_25 ;
if ( V_9 -> V_53 && ! ( V_60 & ( 1 << V_2 -> V_35 . V_61 ) ) ) {
F_19 ( F_2 ( V_2 -> V_5 ) -> V_7 ,
L_2 , V_2 ,
1 << V_2 -> V_35 . V_61 , V_60 ) ;
return - V_62 ;
}
if ( V_9 -> V_53 ++ )
return 0 ;
V_25 = F_20 ( V_2 , false , false , false , 0 ) ;
if ( V_25 )
goto V_63;
F_13 ( V_9 , V_60 , 0 ) ;
V_25 = F_21 ( V_9 , false , false , false ) ;
if ( V_25 == 0 ) {
switch ( V_2 -> V_35 . V_61 ) {
case V_64 :
V_4 -> V_65 -= V_2 -> V_35 . V_14 ;
break;
case V_66 :
V_4 -> V_67 . V_68 -= V_2 -> V_35 . V_14 ;
break;
default:
break;
}
}
F_22 ( V_2 ) ;
V_63:
if ( F_3 ( V_25 ) )
V_9 -> V_53 -- ;
return V_25 ;
}
int
F_23 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_2 ( V_9 -> V_2 . V_5 ) ;
struct V_1 * V_2 = & V_9 -> V_2 ;
int V_25 ;
if ( -- V_9 -> V_53 )
return 0 ;
V_25 = F_20 ( V_2 , false , false , false , 0 ) ;
if ( V_25 )
return V_25 ;
F_13 ( V_9 , V_2 -> V_35 . V_39 , 0 ) ;
V_25 = F_21 ( V_9 , false , false , false ) ;
if ( V_25 == 0 ) {
switch ( V_2 -> V_35 . V_61 ) {
case V_64 :
V_4 -> V_65 += V_2 -> V_35 . V_14 ;
break;
case V_66 :
V_4 -> V_67 . V_68 += V_2 -> V_35 . V_14 ;
break;
default:
break;
}
}
F_22 ( V_2 ) ;
return V_25 ;
}
int
F_24 ( struct V_8 * V_9 )
{
int V_25 ;
V_25 = F_20 ( & V_9 -> V_2 , false , false , false , 0 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_25 ( & V_9 -> V_2 , 0 , V_9 -> V_2 . V_35 . V_36 , & V_9 -> V_69 ) ;
F_22 ( & V_9 -> V_2 ) ;
return V_25 ;
}
void
F_26 ( struct V_8 * V_9 )
{
if ( V_9 )
F_27 ( & V_9 -> V_69 ) ;
}
int
F_21 ( struct V_8 * V_9 , bool V_70 ,
bool V_71 , bool V_72 )
{
int V_25 ;
V_25 = F_28 ( & V_9 -> V_2 , & V_9 -> V_39 , V_70 ,
V_71 , V_72 ) ;
if ( V_25 )
return V_25 ;
return 0 ;
}
T_4
F_29 ( struct V_8 * V_9 , unsigned V_73 )
{
bool V_74 ;
T_4 * V_35 = F_30 ( & V_9 -> V_69 , & V_74 ) ;
V_35 = & V_35 [ V_73 ] ;
if ( V_74 )
return F_31 ( ( void V_75 V_76 * ) V_35 ) ;
else
return * V_35 ;
}
void
F_32 ( struct V_8 * V_9 , unsigned V_73 , T_4 V_77 )
{
bool V_74 ;
T_4 * V_35 = F_30 ( & V_9 -> V_69 , & V_74 ) ;
V_35 = & V_35 [ V_73 ] ;
if ( V_74 )
F_33 ( V_77 , ( void V_75 V_76 * ) V_35 ) ;
else
* V_35 = V_77 ;
}
T_1
F_34 ( struct V_8 * V_9 , unsigned V_73 )
{
bool V_74 ;
T_1 * V_35 = F_30 ( & V_9 -> V_69 , & V_74 ) ;
V_35 = & V_35 [ V_73 ] ;
if ( V_74 )
return F_35 ( ( void V_75 V_76 * ) V_35 ) ;
else
return * V_35 ;
}
void
F_36 ( struct V_8 * V_9 , unsigned V_73 , T_1 V_77 )
{
bool V_74 ;
T_1 * V_35 = F_30 ( & V_9 -> V_69 , & V_74 ) ;
V_35 = & V_35 [ V_73 ] ;
if ( V_74 )
F_37 ( V_77 , ( void V_75 V_76 * ) V_35 ) ;
else
* V_35 = V_77 ;
}
static struct V_78 *
F_38 ( struct V_79 * V_5 ,
unsigned long V_14 , T_2 V_80 ,
struct V_81 * V_82 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
switch ( V_4 -> V_67 . type ) {
#if V_83
case V_84 :
return F_39 ( V_5 , V_7 -> V_85 -> V_86 ,
V_14 , V_80 , V_82 ) ;
#endif
case V_87 :
case V_88 :
return F_40 ( V_5 , V_14 , V_80 ,
V_82 ) ;
default:
F_19 ( V_7 , L_3 ,
V_4 -> V_67 . type ) ;
break;
}
return NULL ;
}
static int
F_41 ( struct V_79 * V_5 , T_2 V_12 )
{
return 0 ;
}
static int
F_42 ( struct V_79 * V_5 , T_2 type ,
struct V_89 * V_90 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
switch ( type ) {
case V_91 :
V_90 -> V_12 = V_92 ;
V_90 -> V_93 = V_52 ;
V_90 -> V_94 = V_95 ;
break;
case V_64 :
if ( V_4 -> V_15 >= V_16 ) {
V_90 -> V_96 = & V_97 ;
V_90 -> V_98 = false ;
V_90 -> V_99 = true ;
} else {
V_90 -> V_96 = & V_100 ;
}
V_90 -> V_12 = V_101 |
V_92 ;
V_90 -> V_93 = V_102 |
V_103 ;
V_90 -> V_94 = V_103 ;
break;
case V_66 :
if ( V_4 -> V_15 >= V_16 )
V_90 -> V_96 = & V_104 ;
else
V_90 -> V_96 = & V_100 ;
switch ( V_4 -> V_67 . type ) {
case V_84 :
V_90 -> V_12 = V_92 ;
V_90 -> V_93 = V_102 |
V_103 ;
V_90 -> V_94 = V_103 ;
break;
case V_87 :
case V_88 :
V_90 -> V_12 = V_92 |
V_105 ;
V_90 -> V_93 = V_52 ;
V_90 -> V_94 = V_95 ;
break;
default:
F_19 ( V_7 , L_4 ,
V_4 -> V_67 . type ) ;
return - V_62 ;
}
break;
default:
F_19 ( V_7 , L_5 , ( unsigned ) type ) ;
return - V_62 ;
}
return 0 ;
}
static void
F_43 ( struct V_1 * V_2 , struct V_51 * V_40 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
switch ( V_2 -> V_35 . V_61 ) {
case V_64 :
F_13 ( V_9 , V_33 ,
V_43 ) ;
break;
default:
F_13 ( V_9 , V_43 , 0 ) ;
break;
}
* V_40 = V_9 -> V_39 ;
}
static int
F_44 ( struct V_106 * V_107 ,
struct V_8 * V_9 , bool V_108 ,
bool V_71 , bool V_72 ,
struct V_109 * V_110 )
{
struct V_111 * V_112 = NULL ;
int V_25 ;
V_25 = F_45 ( V_107 , & V_112 , true ) ;
if ( V_25 )
return V_25 ;
V_25 = F_46 ( & V_9 -> V_2 , V_112 , NULL , V_108 ,
V_71 , V_72 , V_110 ) ;
F_47 ( & V_112 ) ;
return V_25 ;
}
static int
F_48 ( struct V_106 * V_107 , struct V_1 * V_2 ,
struct V_109 * V_113 , struct V_109 * V_110 )
{
struct V_114 * V_115 = V_113 -> V_116 ;
T_5 V_117 = V_115 -> V_118 [ 0 ] . V_119 ;
T_5 V_120 = V_115 -> V_118 [ 1 ] . V_119 ;
T_1 V_121 = V_110 -> V_36 ;
int V_25 ;
V_121 = V_110 -> V_36 ;
while ( V_121 ) {
int V_122 = ( V_121 > 2047 ) ? 2047 : V_121 ;
V_25 = F_49 ( V_107 , 12 ) ;
if ( V_25 )
return V_25 ;
F_50 ( V_107 , 2 , V_123 , 0x0238 , 2 ) ;
F_51 ( V_107 , F_52 ( V_120 ) ) ;
F_51 ( V_107 , F_53 ( V_120 ) ) ;
F_50 ( V_107 , 2 , V_123 , 0x030c , 6 ) ;
F_51 ( V_107 , F_52 ( V_117 ) ) ;
F_51 ( V_107 , F_53 ( V_117 ) ) ;
F_51 ( V_107 , V_20 ) ;
F_51 ( V_107 , V_20 ) ;
F_51 ( V_107 , V_20 ) ;
F_51 ( V_107 , V_122 ) ;
F_50 ( V_107 , 2 , V_123 , 0x0300 , 1 ) ;
F_51 ( V_107 , 0x00100110 ) ;
V_121 -= V_122 ;
V_117 += ( V_20 * V_122 ) ;
V_120 += ( V_20 * V_122 ) ;
}
return 0 ;
}
static int
F_54 ( struct V_106 * V_107 , struct V_1 * V_2 ,
struct V_109 * V_113 , struct V_109 * V_110 )
{
struct V_114 * V_115 = V_113 -> V_116 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
T_5 V_124 = ( V_110 -> V_36 << V_37 ) ;
T_5 V_117 = V_115 -> V_118 [ 0 ] . V_119 ;
T_5 V_120 = V_115 -> V_118 [ 1 ] . V_119 ;
int V_25 ;
while ( V_124 ) {
T_1 V_125 , V_126 , V_127 ;
V_125 = F_55 ( V_124 , ( T_5 ) ( 4 * 1024 * 1024 ) ) ;
V_126 = 16 * 4 ;
V_127 = V_125 / V_126 ;
if ( V_110 -> V_61 == V_64 &&
F_56 ( V_9 ) ) {
V_25 = F_49 ( V_107 , 8 ) ;
if ( V_25 )
return V_25 ;
F_57 ( V_107 , V_123 , 0x0200 , 7 ) ;
F_51 ( V_107 , 0 ) ;
F_51 ( V_107 , 0 ) ;
F_51 ( V_107 , V_126 ) ;
F_51 ( V_107 , V_127 ) ;
F_51 ( V_107 , 1 ) ;
F_51 ( V_107 , 0 ) ;
F_51 ( V_107 , 0 ) ;
} else {
V_25 = F_49 ( V_107 , 2 ) ;
if ( V_25 )
return V_25 ;
F_57 ( V_107 , V_123 , 0x0200 , 1 ) ;
F_51 ( V_107 , 1 ) ;
}
if ( V_113 -> V_61 == V_64 &&
F_56 ( V_9 ) ) {
V_25 = F_49 ( V_107 , 8 ) ;
if ( V_25 )
return V_25 ;
F_57 ( V_107 , V_123 , 0x021c , 7 ) ;
F_51 ( V_107 , 0 ) ;
F_51 ( V_107 , 0 ) ;
F_51 ( V_107 , V_126 ) ;
F_51 ( V_107 , V_127 ) ;
F_51 ( V_107 , 1 ) ;
F_51 ( V_107 , 0 ) ;
F_51 ( V_107 , 0 ) ;
} else {
V_25 = F_49 ( V_107 , 2 ) ;
if ( V_25 )
return V_25 ;
F_57 ( V_107 , V_123 , 0x021c , 1 ) ;
F_51 ( V_107 , 1 ) ;
}
V_25 = F_49 ( V_107 , 14 ) ;
if ( V_25 )
return V_25 ;
F_57 ( V_107 , V_123 , 0x0238 , 2 ) ;
F_51 ( V_107 , F_52 ( V_117 ) ) ;
F_51 ( V_107 , F_52 ( V_120 ) ) ;
F_57 ( V_107 , V_123 , 0x030c , 8 ) ;
F_51 ( V_107 , F_53 ( V_117 ) ) ;
F_51 ( V_107 , F_53 ( V_120 ) ) ;
F_51 ( V_107 , V_126 ) ;
F_51 ( V_107 , V_126 ) ;
F_51 ( V_107 , V_126 ) ;
F_51 ( V_107 , V_127 ) ;
F_51 ( V_107 , 0x00000101 ) ;
F_51 ( V_107 , 0x00000000 ) ;
F_57 ( V_107 , V_123 , V_128 , 1 ) ;
F_51 ( V_107 , 0 ) ;
V_124 -= V_125 ;
V_117 += V_125 ;
V_120 += V_125 ;
}
return 0 ;
}
static inline T_2
F_58 ( struct V_1 * V_2 ,
struct V_106 * V_107 , struct V_109 * V_35 )
{
if ( V_35 -> V_61 == V_66 )
return V_107 -> V_129 ;
return V_107 -> V_130 ;
}
static int
F_59 ( struct V_106 * V_107 , struct V_1 * V_2 ,
struct V_109 * V_113 , struct V_109 * V_110 )
{
T_1 V_117 = V_113 -> V_131 << V_37 ;
T_1 V_120 = V_110 -> V_131 << V_37 ;
T_1 V_121 = V_110 -> V_36 ;
int V_25 ;
V_25 = F_49 ( V_107 , 3 ) ;
if ( V_25 )
return V_25 ;
F_57 ( V_107 , V_123 , V_132 , 2 ) ;
F_51 ( V_107 , F_58 ( V_2 , V_107 , V_113 ) ) ;
F_51 ( V_107 , F_58 ( V_2 , V_107 , V_110 ) ) ;
V_121 = V_110 -> V_36 ;
while ( V_121 ) {
int V_122 = ( V_121 > 2047 ) ? 2047 : V_121 ;
V_25 = F_49 ( V_107 , 11 ) ;
if ( V_25 )
return V_25 ;
F_57 ( V_107 , V_123 ,
V_133 , 8 ) ;
F_51 ( V_107 , V_117 ) ;
F_51 ( V_107 , V_120 ) ;
F_51 ( V_107 , V_20 ) ;
F_51 ( V_107 , V_20 ) ;
F_51 ( V_107 , V_20 ) ;
F_51 ( V_107 , V_122 ) ;
F_51 ( V_107 , 0x00000101 ) ;
F_51 ( V_107 , 0x00000000 ) ;
F_57 ( V_107 , V_123 , V_128 , 1 ) ;
F_51 ( V_107 , 0 ) ;
V_121 -= V_122 ;
V_117 += ( V_20 * V_122 ) ;
V_120 += ( V_20 * V_122 ) ;
}
return 0 ;
}
static int
F_60 ( struct V_106 * V_107 , struct V_8 * V_9 ,
struct V_109 * V_35 , struct V_134 * V_118 )
{
struct V_114 * V_115 = V_35 -> V_116 ;
int V_25 ;
V_25 = F_61 ( V_107 -> V_135 , V_35 -> V_36 << V_37 ,
V_115 -> V_19 , V_136 , V_118 ) ;
if ( V_25 )
return V_25 ;
if ( V_35 -> V_61 == V_64 )
F_62 ( V_118 , V_115 ) ;
else
F_63 ( V_118 , 0 , V_35 -> V_36 << V_37 , V_115 ) ;
return 0 ;
}
static int
F_64 ( struct V_1 * V_2 , int V_108 , bool V_137 ,
bool V_71 , bool V_72 ,
struct V_109 * V_110 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_109 * V_113 = & V_2 -> V_35 ;
struct V_106 * V_107 ;
int V_25 ;
V_107 = V_9 -> V_138 ;
if ( ! V_107 ) {
V_107 = V_4 -> V_138 ;
F_65 ( & V_107 -> V_139 , V_140 ) ;
}
if ( V_4 -> V_15 >= V_16 ) {
struct V_114 * V_115 = V_113 -> V_116 ;
V_25 = F_60 ( V_107 , V_9 , V_113 , & V_115 -> V_118 [ 0 ] ) ;
if ( V_25 )
goto V_63;
V_25 = F_60 ( V_107 , V_9 , V_110 , & V_115 -> V_118 [ 1 ] ) ;
if ( V_25 )
goto V_63;
}
if ( V_4 -> V_15 < V_16 )
V_25 = F_59 ( V_107 , V_2 , & V_2 -> V_35 , V_110 ) ;
else
if ( V_4 -> V_15 < V_141 )
V_25 = F_54 ( V_107 , V_2 , & V_2 -> V_35 , V_110 ) ;
else
V_25 = F_48 ( V_107 , V_2 , & V_2 -> V_35 , V_110 ) ;
if ( V_25 == 0 ) {
V_25 = F_44 ( V_107 , V_9 , V_108 ,
V_71 ,
V_72 , V_110 ) ;
}
V_63:
if ( V_107 == V_4 -> V_138 )
F_66 ( & V_107 -> V_139 ) ;
return V_25 ;
}
static int
F_67 ( struct V_1 * V_2 , bool V_108 , bool V_137 ,
bool V_71 , bool V_72 ,
struct V_109 * V_110 )
{
T_1 V_142 = V_33 | V_52 ;
struct V_51 V_39 ;
struct V_109 V_143 ;
int V_25 ;
V_39 . V_48 = V_39 . V_49 = 0 ;
V_39 . V_56 = V_39 . V_59 = 1 ;
V_39 . V_39 = V_39 . V_57 = & V_142 ;
V_143 = * V_110 ;
V_143 . V_116 = NULL ;
V_25 = F_68 ( V_2 , & V_39 , & V_143 , V_137 , V_71 , V_72 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_69 ( V_2 -> V_31 , & V_143 ) ;
if ( V_25 )
goto V_63;
V_25 = F_64 ( V_2 , true , V_137 , V_71 , V_72 , & V_143 ) ;
if ( V_25 )
goto V_63;
V_25 = F_70 ( V_2 , true , V_71 , V_72 , V_110 ) ;
V_63:
F_71 ( V_2 , & V_143 ) ;
return V_25 ;
}
static int
F_72 ( struct V_1 * V_2 , bool V_108 , bool V_137 ,
bool V_71 , bool V_72 ,
struct V_109 * V_110 )
{
T_1 V_142 = V_33 | V_52 ;
struct V_51 V_39 ;
struct V_109 V_143 ;
int V_25 ;
V_39 . V_48 = V_39 . V_49 = 0 ;
V_39 . V_56 = V_39 . V_59 = 1 ;
V_39 . V_39 = V_39 . V_57 = & V_142 ;
V_143 = * V_110 ;
V_143 . V_116 = NULL ;
V_25 = F_68 ( V_2 , & V_39 , & V_143 , V_137 , V_71 , V_72 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_70 ( V_2 , true , V_71 , V_72 , & V_143 ) ;
if ( V_25 )
goto V_63;
V_25 = F_64 ( V_2 , true , V_137 , V_71 , V_72 , V_110 ) ;
if ( V_25 )
goto V_63;
V_63:
F_71 ( V_2 , & V_143 ) ;
return V_25 ;
}
static void
F_73 ( struct V_1 * V_2 , struct V_109 * V_110 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_134 * V_118 ;
if ( V_2 -> V_144 != F_1 )
return;
F_74 (vma, &nvbo->vma_list, head) {
if ( V_110 && V_110 -> V_61 == V_64 ) {
F_62 ( V_118 , V_110 -> V_116 ) ;
} else
if ( V_110 && V_110 -> V_61 == V_66 &&
V_9 -> V_19 == V_118 -> V_135 -> V_145 ) {
F_63 ( V_118 , 0 , V_110 ->
V_36 << V_37 ,
V_110 -> V_116 ) ;
} else {
F_75 ( V_118 ) ;
}
}
}
static int
F_76 ( struct V_1 * V_2 , struct V_109 * V_110 ,
struct V_146 * * V_147 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
T_5 V_119 = V_110 -> V_131 << V_37 ;
* V_147 = NULL ;
if ( V_110 -> V_61 != V_64 )
return 0 ;
if ( V_4 -> V_15 >= V_46 ) {
* V_147 = F_77 ( V_7 , V_119 , V_110 -> V_14 ,
V_9 -> V_17 ,
V_9 -> V_21 ) ;
}
return 0 ;
}
static void
F_78 ( struct V_1 * V_2 ,
struct V_146 * V_147 ,
struct V_146 * * V_148 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
F_5 ( V_7 , * V_148 , V_2 -> V_149 ) ;
* V_148 = V_147 ;
}
static int
F_79 ( struct V_1 * V_2 , bool V_108 , bool V_137 ,
bool V_71 , bool V_72 ,
struct V_109 * V_110 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_109 * V_113 = & V_2 -> V_35 ;
struct V_146 * V_147 = NULL ;
int V_25 = 0 ;
if ( V_4 -> V_15 < V_16 ) {
V_25 = F_76 ( V_2 , V_110 , & V_147 ) ;
if ( V_25 )
return V_25 ;
}
if ( V_113 -> V_61 == V_91 && ! V_2 -> V_31 ) {
F_80 ( V_2 -> V_35 . V_116 != NULL ) ;
V_2 -> V_35 = * V_110 ;
V_110 -> V_116 = NULL ;
goto V_63;
}
if ( ! V_4 -> V_138 ) {
V_25 = F_81 ( V_2 , V_108 , V_71 , V_72 , V_110 ) ;
goto V_63;
}
if ( V_110 -> V_61 == V_91 )
V_25 = F_67 ( V_2 , V_108 , V_137 , V_71 , V_72 , V_110 ) ;
else if ( V_113 -> V_61 == V_91 )
V_25 = F_72 ( V_2 , V_108 , V_137 , V_71 , V_72 , V_110 ) ;
else
V_25 = F_64 ( V_2 , V_108 , V_137 , V_71 , V_72 , V_110 ) ;
if ( ! V_25 )
goto V_63;
V_25 = F_81 ( V_2 , V_108 , V_71 , V_72 , V_110 ) ;
V_63:
if ( V_4 -> V_15 < V_16 ) {
if ( V_25 )
F_78 ( V_2 , NULL , & V_147 ) ;
else
F_78 ( V_2 , V_147 , & V_9 -> V_11 ) ;
}
return V_25 ;
}
static int
F_82 ( struct V_1 * V_2 , struct V_150 * V_151 )
{
return 0 ;
}
static int
F_83 ( struct V_79 * V_5 , struct V_109 * V_35 )
{
struct V_89 * V_90 = & V_5 -> V_90 [ V_35 -> V_61 ] ;
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_25 ;
V_35 -> V_152 . V_153 = NULL ;
V_35 -> V_152 . V_119 = 0 ;
V_35 -> V_152 . V_14 = V_35 -> V_36 << V_37 ;
V_35 -> V_152 . V_154 = 0 ;
V_35 -> V_152 . V_74 = false ;
if ( ! ( V_90 -> V_12 & V_92 ) )
return - V_62 ;
switch ( V_35 -> V_61 ) {
case V_91 :
return 0 ;
case V_66 :
#if V_83
if ( V_4 -> V_67 . type == V_84 ) {
V_35 -> V_152 . V_119 = V_35 -> V_131 << V_37 ;
V_35 -> V_152 . V_154 = V_4 -> V_67 . V_155 ;
V_35 -> V_152 . V_74 = true ;
}
#endif
break;
case V_64 :
{
struct V_114 * V_115 = V_35 -> V_116 ;
T_6 V_19 ;
if ( ! V_4 -> V_32 ) {
V_35 -> V_152 . V_119 = V_35 -> V_131 << V_37 ;
V_35 -> V_152 . V_154 = F_84 ( V_7 -> V_156 , 1 ) ;
V_35 -> V_152 . V_74 = true ;
break;
}
if ( V_4 -> V_15 >= V_141 )
V_19 = V_115 -> V_19 ;
else
V_19 = 12 ;
V_25 = F_61 ( V_4 -> V_32 , V_35 -> V_152 . V_14 ,
V_19 , V_157 ,
& V_115 -> V_158 ) ;
if ( V_25 )
return V_25 ;
F_62 ( & V_115 -> V_158 , V_115 ) ;
if ( V_25 ) {
F_85 ( & V_115 -> V_158 ) ;
return V_25 ;
}
V_35 -> V_152 . V_119 = V_115 -> V_158 . V_119 ;
if ( V_4 -> V_15 == V_16 )
V_35 -> V_152 . V_119 -= 0x0020000000ULL ;
V_35 -> V_152 . V_154 = F_84 ( V_7 -> V_156 , 1 ) ;
V_35 -> V_152 . V_74 = true ;
}
break;
default:
return - V_62 ;
}
return 0 ;
}
static void
F_86 ( struct V_79 * V_5 , struct V_109 * V_35 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_114 * V_115 = V_35 -> V_116 ;
if ( ! V_4 -> V_32 || V_35 -> V_61 != V_64 )
return;
if ( ! V_115 -> V_158 . V_115 )
return;
F_75 ( & V_115 -> V_158 ) ;
F_85 ( & V_115 -> V_158 ) ;
}
static int
F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
if ( V_2 -> V_35 . V_61 != V_64 ) {
if ( V_4 -> V_15 < V_16 ||
! F_56 ( V_9 ) )
return 0 ;
}
if ( V_2 -> V_35 . V_131 + V_2 -> V_35 . V_36 < V_4 -> V_159 )
return 0 ;
V_9 -> V_39 . V_48 = 0 ;
V_9 -> V_39 . V_49 = V_4 -> V_159 ;
F_13 ( V_9 , V_64 , 0 ) ;
return F_21 ( V_9 , false , true , false ) ;
}
void
F_88 ( struct V_8 * V_9 , struct V_111 * V_112 )
{
struct V_111 * V_160 ;
if ( F_89 ( V_112 ) )
F_90 ( V_112 ) ;
F_91 ( & V_9 -> V_2 . V_5 -> V_161 ) ;
V_160 = V_9 -> V_2 . V_149 ;
V_9 -> V_2 . V_149 = V_112 ;
F_92 ( & V_9 -> V_2 . V_5 -> V_161 ) ;
F_47 ( & V_160 ) ;
}
static int
F_93 ( struct V_78 * V_31 )
{
struct V_162 * V_163 = ( void * ) V_31 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
unsigned V_164 ;
int V_165 ;
if ( V_31 -> V_166 != V_167 )
return 0 ;
V_4 = F_2 ( V_31 -> V_5 ) ;
V_7 = V_4 -> V_7 ;
#if V_83
if ( V_4 -> V_67 . type == V_84 ) {
return F_94 ( V_31 ) ;
}
#endif
#ifdef F_95
if ( F_96 () ) {
return F_97 ( ( void * ) V_31 , V_7 -> V_7 ) ;
}
#endif
V_165 = F_98 ( V_31 ) ;
if ( V_165 ) {
return V_165 ;
}
for ( V_164 = 0 ; V_164 < V_31 -> V_36 ; V_164 ++ ) {
V_163 -> V_168 [ V_164 ] = F_99 ( V_7 -> V_156 , V_31 -> V_169 [ V_164 ] ,
0 , V_20 ,
V_170 ) ;
if ( F_100 ( V_7 -> V_156 , V_163 -> V_168 [ V_164 ] ) ) {
while ( -- V_164 ) {
F_101 ( V_7 -> V_156 , V_163 -> V_168 [ V_164 ] ,
V_20 , V_170 ) ;
V_163 -> V_168 [ V_164 ] = 0 ;
}
F_102 ( V_31 ) ;
return - V_171 ;
}
}
return 0 ;
}
static void
F_103 ( struct V_78 * V_31 )
{
struct V_162 * V_163 = ( void * ) V_31 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
unsigned V_164 ;
V_4 = F_2 ( V_31 -> V_5 ) ;
V_7 = V_4 -> V_7 ;
#if V_83
if ( V_4 -> V_67 . type == V_84 ) {
F_104 ( V_31 ) ;
return;
}
#endif
#ifdef F_95
if ( F_96 () ) {
F_105 ( ( void * ) V_31 , V_7 -> V_7 ) ;
return;
}
#endif
for ( V_164 = 0 ; V_164 < V_31 -> V_36 ; V_164 ++ ) {
if ( V_163 -> V_168 [ V_164 ] ) {
F_101 ( V_7 -> V_156 , V_163 -> V_168 [ V_164 ] ,
V_20 , V_170 ) ;
}
}
F_102 ( V_31 ) ;
}
struct V_134 *
F_106 ( struct V_8 * V_9 , struct V_172 * V_135 )
{
struct V_134 * V_118 ;
F_74 (vma, &nvbo->vma_list, head) {
if ( V_118 -> V_135 == V_135 )
return V_118 ;
}
return NULL ;
}
int
F_107 ( struct V_8 * V_9 , struct V_172 * V_135 ,
struct V_134 * V_118 )
{
const T_1 V_14 = V_9 -> V_2 . V_35 . V_36 << V_37 ;
struct V_114 * V_115 = V_9 -> V_2 . V_35 . V_116 ;
int V_25 ;
V_25 = F_61 ( V_135 , V_14 , V_9 -> V_19 ,
V_157 , V_118 ) ;
if ( V_25 )
return V_25 ;
if ( V_9 -> V_2 . V_35 . V_61 == V_64 )
F_62 ( V_118 , V_9 -> V_2 . V_35 . V_116 ) ;
else
if ( V_9 -> V_2 . V_35 . V_61 == V_66 )
F_63 ( V_118 , 0 , V_14 , V_115 ) ;
F_108 ( & V_118 -> V_28 , & V_9 -> V_30 ) ;
V_118 -> V_173 = 1 ;
return 0 ;
}
void
F_109 ( struct V_8 * V_9 , struct V_134 * V_118 )
{
if ( V_118 -> V_115 ) {
if ( V_9 -> V_2 . V_35 . V_61 != V_91 ) {
F_91 ( & V_9 -> V_2 . V_5 -> V_161 ) ;
F_110 ( & V_9 -> V_2 , false , false , false ) ;
F_92 ( & V_9 -> V_2 . V_5 -> V_161 ) ;
F_75 ( V_118 ) ;
}
F_85 ( V_118 ) ;
F_111 ( & V_118 -> V_28 ) ;
}
}
