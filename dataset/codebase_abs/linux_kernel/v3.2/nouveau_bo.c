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
int V_24 ;
V_9 = F_11 ( sizeof( struct V_8 ) , V_25 ) ;
if ( ! V_9 )
return - V_26 ;
F_12 ( & V_9 -> V_27 ) ;
F_12 ( & V_9 -> V_28 ) ;
F_12 ( & V_9 -> V_29 ) ;
V_9 -> V_17 = V_17 ;
V_9 -> V_21 = V_21 ;
V_9 -> V_2 . V_5 = & V_4 -> V_30 . V_5 ;
V_9 -> V_19 = 12 ;
if ( V_4 -> V_31 ) {
if ( ! ( V_12 & V_32 ) && V_14 > 256 * 1024 )
V_9 -> V_19 = V_4 -> V_31 -> V_33 ;
}
F_7 ( V_9 , V_12 , & V_13 , & V_14 ) ;
V_9 -> V_2 . V_34 . V_35 = V_14 >> V_36 ;
F_13 ( V_9 , V_12 , 0 ) ;
V_24 = F_14 ( & V_4 -> V_30 . V_5 , & V_9 -> V_2 , V_14 ,
V_37 , & V_9 -> V_38 ,
V_13 >> V_36 , 0 , false , NULL , V_14 ,
F_1 ) ;
if ( V_24 ) {
return V_24 ;
}
* V_22 = V_9 ;
return 0 ;
}
static void
F_15 ( T_2 * V_39 , unsigned * V_40 , T_2 type , T_2 V_12 )
{
* V_40 = 0 ;
if ( type & V_41 )
V_39 [ ( * V_40 ) ++ ] = V_41 | V_12 ;
if ( type & V_32 )
V_39 [ ( * V_40 ) ++ ] = V_32 | V_12 ;
if ( type & V_42 )
V_39 [ ( * V_40 ) ++ ] = V_42 | V_12 ;
}
static void
F_16 ( struct V_8 * V_9 , T_2 type )
{
struct V_3 * V_4 = F_2 ( V_9 -> V_2 . V_5 ) ;
int V_43 = V_4 -> V_44 >> V_36 ;
if ( V_4 -> V_15 == V_45 &&
V_9 -> V_17 && ( type & V_41 ) &&
V_9 -> V_2 . V_34 . V_35 < V_43 / 4 ) {
if ( V_9 -> V_21 & V_46 ) {
V_9 -> V_38 . V_47 = V_43 / 2 ;
V_9 -> V_38 . V_48 = ~ 0 ;
} else {
V_9 -> V_38 . V_47 = 0 ;
V_9 -> V_38 . V_48 = V_43 / 2 ;
}
}
}
void
F_13 ( struct V_8 * V_9 , T_2 type , T_2 V_49 )
{
struct V_50 * V_39 = & V_9 -> V_38 ;
T_2 V_12 = V_51 |
( V_9 -> V_52 ? V_53 : 0 ) ;
V_39 -> V_38 = V_9 -> V_54 ;
F_15 ( V_9 -> V_54 , & V_39 -> V_55 ,
type , V_12 ) ;
V_39 -> V_56 = V_9 -> V_57 ;
F_15 ( V_9 -> V_57 , & V_39 -> V_58 ,
type | V_49 , V_12 ) ;
F_16 ( V_9 , type ) ;
}
int
F_17 ( struct V_8 * V_9 , T_2 V_59 )
{
struct V_3 * V_4 = F_2 ( V_9 -> V_2 . V_5 ) ;
struct V_1 * V_2 = & V_9 -> V_2 ;
int V_24 ;
if ( V_9 -> V_52 && ! ( V_59 & ( 1 << V_2 -> V_34 . V_60 ) ) ) {
F_18 ( F_2 ( V_2 -> V_5 ) -> V_7 ,
L_2 , V_2 ,
1 << V_2 -> V_34 . V_60 , V_59 ) ;
return - V_61 ;
}
if ( V_9 -> V_52 ++ )
return 0 ;
V_24 = F_19 ( V_2 , false , false , false , 0 ) ;
if ( V_24 )
goto V_62;
F_13 ( V_9 , V_59 , 0 ) ;
V_24 = F_20 ( V_9 , false , false , false ) ;
if ( V_24 == 0 ) {
switch ( V_2 -> V_34 . V_60 ) {
case V_63 :
V_4 -> V_64 -= V_2 -> V_34 . V_14 ;
break;
case V_65 :
V_4 -> V_66 . V_67 -= V_2 -> V_34 . V_14 ;
break;
default:
break;
}
}
F_21 ( V_2 ) ;
V_62:
if ( F_3 ( V_24 ) )
V_9 -> V_52 -- ;
return V_24 ;
}
int
F_22 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_2 ( V_9 -> V_2 . V_5 ) ;
struct V_1 * V_2 = & V_9 -> V_2 ;
int V_24 ;
if ( -- V_9 -> V_52 )
return 0 ;
V_24 = F_19 ( V_2 , false , false , false , 0 ) ;
if ( V_24 )
return V_24 ;
F_13 ( V_9 , V_2 -> V_34 . V_38 , 0 ) ;
V_24 = F_20 ( V_9 , false , false , false ) ;
if ( V_24 == 0 ) {
switch ( V_2 -> V_34 . V_60 ) {
case V_63 :
V_4 -> V_64 += V_2 -> V_34 . V_14 ;
break;
case V_65 :
V_4 -> V_66 . V_67 += V_2 -> V_34 . V_14 ;
break;
default:
break;
}
}
F_21 ( V_2 ) ;
return V_24 ;
}
int
F_23 ( struct V_8 * V_9 )
{
int V_24 ;
V_24 = F_19 ( & V_9 -> V_2 , false , false , false , 0 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_24 ( & V_9 -> V_2 , 0 , V_9 -> V_2 . V_34 . V_35 , & V_9 -> V_68 ) ;
F_21 ( & V_9 -> V_2 ) ;
return V_24 ;
}
void
F_25 ( struct V_8 * V_9 )
{
if ( V_9 )
F_26 ( & V_9 -> V_68 ) ;
}
int
F_20 ( struct V_8 * V_9 , bool V_69 ,
bool V_70 , bool V_71 )
{
int V_24 ;
V_24 = F_27 ( & V_9 -> V_2 , & V_9 -> V_38 , V_69 ,
V_70 , V_71 ) ;
if ( V_24 )
return V_24 ;
return 0 ;
}
T_3
F_28 ( struct V_8 * V_9 , unsigned V_72 )
{
bool V_73 ;
T_3 * V_34 = F_29 ( & V_9 -> V_68 , & V_73 ) ;
V_34 = & V_34 [ V_72 ] ;
if ( V_73 )
return F_30 ( ( void V_74 V_75 * ) V_34 ) ;
else
return * V_34 ;
}
void
F_31 ( struct V_8 * V_9 , unsigned V_72 , T_3 V_76 )
{
bool V_73 ;
T_3 * V_34 = F_29 ( & V_9 -> V_68 , & V_73 ) ;
V_34 = & V_34 [ V_72 ] ;
if ( V_73 )
F_32 ( V_76 , ( void V_74 V_75 * ) V_34 ) ;
else
* V_34 = V_76 ;
}
T_1
F_33 ( struct V_8 * V_9 , unsigned V_72 )
{
bool V_73 ;
T_1 * V_34 = F_29 ( & V_9 -> V_68 , & V_73 ) ;
V_34 = & V_34 [ V_72 ] ;
if ( V_73 )
return F_34 ( ( void V_74 V_75 * ) V_34 ) ;
else
return * V_34 ;
}
void
F_35 ( struct V_8 * V_9 , unsigned V_72 , T_1 V_76 )
{
bool V_73 ;
T_1 * V_34 = F_29 ( & V_9 -> V_68 , & V_73 ) ;
V_34 = & V_34 [ V_72 ] ;
if ( V_73 )
F_36 ( V_76 , ( void V_74 V_75 * ) V_34 ) ;
else
* V_34 = V_76 ;
}
static struct V_77 *
F_37 ( struct V_78 * V_5 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
switch ( V_4 -> V_66 . type ) {
#if V_79
case V_80 :
return F_38 ( V_5 , V_7 -> V_81 -> V_82 ) ;
#endif
case V_83 :
case V_84 :
return F_39 ( V_7 ) ;
default:
F_18 ( V_7 , L_3 ,
V_4 -> V_66 . type ) ;
break;
}
return NULL ;
}
static int
F_40 ( struct V_78 * V_5 , T_2 V_12 )
{
return 0 ;
}
static int
F_41 ( struct V_78 * V_5 , T_2 type ,
struct V_85 * V_86 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
switch ( type ) {
case V_87 :
V_86 -> V_12 = V_88 ;
V_86 -> V_89 = V_51 ;
V_86 -> V_90 = V_91 ;
break;
case V_63 :
if ( V_4 -> V_15 >= V_16 ) {
V_86 -> V_92 = & V_93 ;
V_86 -> V_94 = false ;
V_86 -> V_95 = true ;
} else {
V_86 -> V_92 = & V_96 ;
}
V_86 -> V_12 = V_97 |
V_88 ;
V_86 -> V_89 = V_98 |
V_99 ;
V_86 -> V_90 = V_99 ;
break;
case V_65 :
if ( V_4 -> V_15 >= V_16 )
V_86 -> V_92 = & V_100 ;
else
V_86 -> V_92 = & V_96 ;
switch ( V_4 -> V_66 . type ) {
case V_80 :
V_86 -> V_12 = V_88 ;
V_86 -> V_89 = V_98 |
V_99 ;
V_86 -> V_90 = V_99 ;
break;
case V_83 :
case V_84 :
V_86 -> V_12 = V_88 |
V_101 ;
V_86 -> V_89 = V_51 ;
V_86 -> V_90 = V_91 ;
break;
default:
F_18 ( V_7 , L_4 ,
V_4 -> V_66 . type ) ;
return - V_61 ;
}
break;
default:
F_18 ( V_7 , L_5 , ( unsigned ) type ) ;
return - V_61 ;
}
return 0 ;
}
static void
F_42 ( struct V_1 * V_2 , struct V_50 * V_39 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
switch ( V_2 -> V_34 . V_60 ) {
case V_63 :
F_13 ( V_9 , V_32 ,
V_42 ) ;
break;
default:
F_13 ( V_9 , V_42 , 0 ) ;
break;
}
* V_39 = V_9 -> V_38 ;
}
static int
F_43 ( struct V_102 * V_103 ,
struct V_8 * V_9 , bool V_104 ,
bool V_70 , bool V_71 ,
struct V_105 * V_106 )
{
struct V_107 * V_108 = NULL ;
int V_24 ;
V_24 = F_44 ( V_103 , & V_108 , true ) ;
if ( V_24 )
return V_24 ;
V_24 = F_45 ( & V_9 -> V_2 , V_108 , NULL , V_104 ,
V_70 , V_71 , V_106 ) ;
F_46 ( & V_108 ) ;
return V_24 ;
}
static int
F_47 ( struct V_102 * V_103 , struct V_1 * V_2 ,
struct V_105 * V_109 , struct V_105 * V_106 )
{
struct V_110 * V_111 = V_109 -> V_112 ;
T_4 V_113 = V_111 -> V_114 [ 0 ] . V_115 ;
T_4 V_116 = V_111 -> V_114 [ 1 ] . V_115 ;
T_1 V_117 = V_106 -> V_35 ;
int V_24 ;
V_117 = V_106 -> V_35 ;
while ( V_117 ) {
int V_118 = ( V_117 > 2047 ) ? 2047 : V_117 ;
V_24 = F_48 ( V_103 , 12 ) ;
if ( V_24 )
return V_24 ;
F_49 ( V_103 , 2 , V_119 , 0x0238 , 2 ) ;
F_50 ( V_103 , F_51 ( V_116 ) ) ;
F_50 ( V_103 , F_52 ( V_116 ) ) ;
F_49 ( V_103 , 2 , V_119 , 0x030c , 6 ) ;
F_50 ( V_103 , F_51 ( V_113 ) ) ;
F_50 ( V_103 , F_52 ( V_113 ) ) ;
F_50 ( V_103 , V_20 ) ;
F_50 ( V_103 , V_20 ) ;
F_50 ( V_103 , V_20 ) ;
F_50 ( V_103 , V_118 ) ;
F_49 ( V_103 , 2 , V_119 , 0x0300 , 1 ) ;
F_50 ( V_103 , 0x00100110 ) ;
V_117 -= V_118 ;
V_113 += ( V_20 * V_118 ) ;
V_116 += ( V_20 * V_118 ) ;
}
return 0 ;
}
static int
F_53 ( struct V_102 * V_103 , struct V_1 * V_2 ,
struct V_105 * V_109 , struct V_105 * V_106 )
{
struct V_110 * V_111 = V_109 -> V_112 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
T_4 V_120 = ( V_106 -> V_35 << V_36 ) ;
T_4 V_113 = V_111 -> V_114 [ 0 ] . V_115 ;
T_4 V_116 = V_111 -> V_114 [ 1 ] . V_115 ;
int V_24 ;
while ( V_120 ) {
T_1 V_121 , V_122 , V_123 ;
V_121 = F_54 ( V_120 , ( T_4 ) ( 4 * 1024 * 1024 ) ) ;
V_122 = 16 * 4 ;
V_123 = V_121 / V_122 ;
if ( V_106 -> V_60 == V_63 &&
F_55 ( V_9 ) ) {
V_24 = F_48 ( V_103 , 8 ) ;
if ( V_24 )
return V_24 ;
F_56 ( V_103 , V_119 , 0x0200 , 7 ) ;
F_50 ( V_103 , 0 ) ;
F_50 ( V_103 , 0 ) ;
F_50 ( V_103 , V_122 ) ;
F_50 ( V_103 , V_123 ) ;
F_50 ( V_103 , 1 ) ;
F_50 ( V_103 , 0 ) ;
F_50 ( V_103 , 0 ) ;
} else {
V_24 = F_48 ( V_103 , 2 ) ;
if ( V_24 )
return V_24 ;
F_56 ( V_103 , V_119 , 0x0200 , 1 ) ;
F_50 ( V_103 , 1 ) ;
}
if ( V_109 -> V_60 == V_63 &&
F_55 ( V_9 ) ) {
V_24 = F_48 ( V_103 , 8 ) ;
if ( V_24 )
return V_24 ;
F_56 ( V_103 , V_119 , 0x021c , 7 ) ;
F_50 ( V_103 , 0 ) ;
F_50 ( V_103 , 0 ) ;
F_50 ( V_103 , V_122 ) ;
F_50 ( V_103 , V_123 ) ;
F_50 ( V_103 , 1 ) ;
F_50 ( V_103 , 0 ) ;
F_50 ( V_103 , 0 ) ;
} else {
V_24 = F_48 ( V_103 , 2 ) ;
if ( V_24 )
return V_24 ;
F_56 ( V_103 , V_119 , 0x021c , 1 ) ;
F_50 ( V_103 , 1 ) ;
}
V_24 = F_48 ( V_103 , 14 ) ;
if ( V_24 )
return V_24 ;
F_56 ( V_103 , V_119 , 0x0238 , 2 ) ;
F_50 ( V_103 , F_51 ( V_113 ) ) ;
F_50 ( V_103 , F_51 ( V_116 ) ) ;
F_56 ( V_103 , V_119 , 0x030c , 8 ) ;
F_50 ( V_103 , F_52 ( V_113 ) ) ;
F_50 ( V_103 , F_52 ( V_116 ) ) ;
F_50 ( V_103 , V_122 ) ;
F_50 ( V_103 , V_122 ) ;
F_50 ( V_103 , V_122 ) ;
F_50 ( V_103 , V_123 ) ;
F_50 ( V_103 , 0x00000101 ) ;
F_50 ( V_103 , 0x00000000 ) ;
F_56 ( V_103 , V_119 , V_124 , 1 ) ;
F_50 ( V_103 , 0 ) ;
V_120 -= V_121 ;
V_113 += V_121 ;
V_116 += V_121 ;
}
return 0 ;
}
static inline T_2
F_57 ( struct V_1 * V_2 ,
struct V_102 * V_103 , struct V_105 * V_34 )
{
if ( V_34 -> V_60 == V_65 )
return V_103 -> V_125 ;
return V_103 -> V_126 ;
}
static int
F_58 ( struct V_102 * V_103 , struct V_1 * V_2 ,
struct V_105 * V_109 , struct V_105 * V_106 )
{
T_1 V_113 = V_109 -> V_127 << V_36 ;
T_1 V_116 = V_106 -> V_127 << V_36 ;
T_1 V_117 = V_106 -> V_35 ;
int V_24 ;
V_24 = F_48 ( V_103 , 3 ) ;
if ( V_24 )
return V_24 ;
F_56 ( V_103 , V_119 , V_128 , 2 ) ;
F_50 ( V_103 , F_57 ( V_2 , V_103 , V_109 ) ) ;
F_50 ( V_103 , F_57 ( V_2 , V_103 , V_106 ) ) ;
V_117 = V_106 -> V_35 ;
while ( V_117 ) {
int V_118 = ( V_117 > 2047 ) ? 2047 : V_117 ;
V_24 = F_48 ( V_103 , 11 ) ;
if ( V_24 )
return V_24 ;
F_56 ( V_103 , V_119 ,
V_129 , 8 ) ;
F_50 ( V_103 , V_113 ) ;
F_50 ( V_103 , V_116 ) ;
F_50 ( V_103 , V_20 ) ;
F_50 ( V_103 , V_20 ) ;
F_50 ( V_103 , V_20 ) ;
F_50 ( V_103 , V_118 ) ;
F_50 ( V_103 , 0x00000101 ) ;
F_50 ( V_103 , 0x00000000 ) ;
F_56 ( V_103 , V_119 , V_124 , 1 ) ;
F_50 ( V_103 , 0 ) ;
V_117 -= V_118 ;
V_113 += ( V_20 * V_118 ) ;
V_116 += ( V_20 * V_118 ) ;
}
return 0 ;
}
static int
F_59 ( struct V_102 * V_103 , struct V_8 * V_9 ,
struct V_105 * V_34 , struct V_130 * V_114 )
{
struct V_110 * V_111 = V_34 -> V_112 ;
int V_24 ;
V_24 = F_60 ( V_103 -> V_131 , V_34 -> V_35 << V_36 ,
V_111 -> V_19 , V_132 , V_114 ) ;
if ( V_24 )
return V_24 ;
if ( V_34 -> V_60 == V_63 )
F_61 ( V_114 , V_111 ) ;
else
F_62 ( V_114 , 0 , V_34 -> V_35 << V_36 ,
V_111 , V_111 -> V_133 ) ;
return 0 ;
}
static int
F_63 ( struct V_1 * V_2 , int V_104 , bool V_134 ,
bool V_70 , bool V_71 ,
struct V_105 * V_106 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_105 * V_109 = & V_2 -> V_34 ;
struct V_102 * V_103 ;
int V_24 ;
V_103 = V_9 -> V_135 ;
if ( ! V_103 ) {
V_103 = V_4 -> V_135 ;
F_64 ( & V_103 -> V_136 , V_137 ) ;
}
if ( V_4 -> V_15 >= V_16 ) {
struct V_110 * V_111 = V_109 -> V_112 ;
V_24 = F_59 ( V_103 , V_9 , V_109 , & V_111 -> V_114 [ 0 ] ) ;
if ( V_24 )
goto V_62;
V_24 = F_59 ( V_103 , V_9 , V_106 , & V_111 -> V_114 [ 1 ] ) ;
if ( V_24 )
goto V_62;
}
if ( V_4 -> V_15 < V_16 )
V_24 = F_58 ( V_103 , V_2 , & V_2 -> V_34 , V_106 ) ;
else
if ( V_4 -> V_15 < V_138 )
V_24 = F_53 ( V_103 , V_2 , & V_2 -> V_34 , V_106 ) ;
else
V_24 = F_47 ( V_103 , V_2 , & V_2 -> V_34 , V_106 ) ;
if ( V_24 == 0 ) {
V_24 = F_43 ( V_103 , V_9 , V_104 ,
V_70 ,
V_71 , V_106 ) ;
}
V_62:
if ( V_103 == V_4 -> V_135 )
F_65 ( & V_103 -> V_136 ) ;
return V_24 ;
}
static int
F_66 ( struct V_1 * V_2 , bool V_104 , bool V_134 ,
bool V_70 , bool V_71 ,
struct V_105 * V_106 )
{
T_1 V_139 = V_32 | V_51 ;
struct V_50 V_38 ;
struct V_105 V_140 ;
int V_24 ;
V_38 . V_47 = V_38 . V_48 = 0 ;
V_38 . V_55 = V_38 . V_58 = 1 ;
V_38 . V_38 = V_38 . V_56 = & V_139 ;
V_140 = * V_106 ;
V_140 . V_112 = NULL ;
V_24 = F_67 ( V_2 , & V_38 , & V_140 , V_134 , V_70 , V_71 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_68 ( V_2 -> V_30 , & V_140 ) ;
if ( V_24 )
goto V_62;
V_24 = F_63 ( V_2 , true , V_134 , V_70 , V_71 , & V_140 ) ;
if ( V_24 )
goto V_62;
V_24 = F_69 ( V_2 , true , V_70 , V_71 , V_106 ) ;
V_62:
F_70 ( V_2 , & V_140 ) ;
return V_24 ;
}
static int
F_71 ( struct V_1 * V_2 , bool V_104 , bool V_134 ,
bool V_70 , bool V_71 ,
struct V_105 * V_106 )
{
T_1 V_139 = V_32 | V_51 ;
struct V_50 V_38 ;
struct V_105 V_140 ;
int V_24 ;
V_38 . V_47 = V_38 . V_48 = 0 ;
V_38 . V_55 = V_38 . V_58 = 1 ;
V_38 . V_38 = V_38 . V_56 = & V_139 ;
V_140 = * V_106 ;
V_140 . V_112 = NULL ;
V_24 = F_67 ( V_2 , & V_38 , & V_140 , V_134 , V_70 , V_71 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_69 ( V_2 , true , V_70 , V_71 , & V_140 ) ;
if ( V_24 )
goto V_62;
V_24 = F_63 ( V_2 , true , V_134 , V_70 , V_71 , V_106 ) ;
if ( V_24 )
goto V_62;
V_62:
F_70 ( V_2 , & V_140 ) ;
return V_24 ;
}
static void
F_72 ( struct V_1 * V_2 , struct V_105 * V_106 )
{
struct V_110 * V_111 = V_106 -> V_112 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_130 * V_114 ;
F_73 (vma, &nvbo->vma_list, head) {
if ( V_106 -> V_60 == V_63 ) {
F_61 ( V_114 , V_106 -> V_112 ) ;
} else
if ( V_106 -> V_60 == V_65 &&
V_9 -> V_19 == V_114 -> V_131 -> V_141 ) {
F_62 ( V_114 , 0 , V_106 ->
V_35 << V_36 ,
V_111 , V_111 -> V_133 ) ;
} else {
F_74 ( V_114 ) ;
}
}
}
static int
F_75 ( struct V_1 * V_2 , struct V_105 * V_106 ,
struct V_142 * * V_143 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
T_4 V_115 = V_106 -> V_127 << V_36 ;
* V_143 = NULL ;
if ( V_106 -> V_60 != V_63 )
return 0 ;
if ( V_4 -> V_15 >= V_45 ) {
* V_143 = F_76 ( V_7 , V_115 , V_106 -> V_14 ,
V_9 -> V_17 ,
V_9 -> V_21 ) ;
}
return 0 ;
}
static void
F_77 ( struct V_1 * V_2 ,
struct V_142 * V_143 ,
struct V_142 * * V_144 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
F_5 ( V_7 , * V_144 , V_2 -> V_145 ) ;
* V_144 = V_143 ;
}
static int
F_78 ( struct V_1 * V_2 , bool V_104 , bool V_134 ,
bool V_70 , bool V_71 ,
struct V_105 * V_106 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_105 * V_109 = & V_2 -> V_34 ;
struct V_142 * V_143 = NULL ;
int V_24 = 0 ;
if ( V_4 -> V_15 < V_16 ) {
V_24 = F_75 ( V_2 , V_106 , & V_143 ) ;
if ( V_24 )
return V_24 ;
}
if ( V_109 -> V_60 == V_87 && ! V_2 -> V_30 ) {
F_79 ( V_2 -> V_34 . V_112 != NULL ) ;
V_2 -> V_34 = * V_106 ;
V_106 -> V_112 = NULL ;
goto V_62;
}
if ( ! V_4 -> V_135 ) {
V_24 = F_80 ( V_2 , V_104 , V_70 , V_71 , V_106 ) ;
goto V_62;
}
if ( V_106 -> V_60 == V_87 )
V_24 = F_66 ( V_2 , V_104 , V_134 , V_70 , V_71 , V_106 ) ;
else if ( V_109 -> V_60 == V_87 )
V_24 = F_71 ( V_2 , V_104 , V_134 , V_70 , V_71 , V_106 ) ;
else
V_24 = F_63 ( V_2 , V_104 , V_134 , V_70 , V_71 , V_106 ) ;
if ( ! V_24 )
goto V_62;
V_24 = F_80 ( V_2 , V_104 , V_70 , V_71 , V_106 ) ;
V_62:
if ( V_4 -> V_15 < V_16 ) {
if ( V_24 )
F_77 ( V_2 , NULL , & V_143 ) ;
else
F_77 ( V_2 , V_143 , & V_9 -> V_11 ) ;
}
return V_24 ;
}
static int
F_81 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
return 0 ;
}
static int
F_82 ( struct V_78 * V_5 , struct V_105 * V_34 )
{
struct V_85 * V_86 = & V_5 -> V_86 [ V_34 -> V_60 ] ;
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_24 ;
V_34 -> V_148 . V_149 = NULL ;
V_34 -> V_148 . V_115 = 0 ;
V_34 -> V_148 . V_14 = V_34 -> V_35 << V_36 ;
V_34 -> V_148 . V_150 = 0 ;
V_34 -> V_148 . V_73 = false ;
if ( ! ( V_86 -> V_12 & V_88 ) )
return - V_61 ;
switch ( V_34 -> V_60 ) {
case V_87 :
return 0 ;
case V_65 :
#if V_79
if ( V_4 -> V_66 . type == V_80 ) {
V_34 -> V_148 . V_115 = V_34 -> V_127 << V_36 ;
V_34 -> V_148 . V_150 = V_4 -> V_66 . V_151 ;
V_34 -> V_148 . V_73 = true ;
}
#endif
break;
case V_63 :
{
struct V_110 * V_111 = V_34 -> V_112 ;
T_5 V_19 ;
if ( ! V_4 -> V_31 ) {
V_34 -> V_148 . V_115 = V_34 -> V_127 << V_36 ;
V_34 -> V_148 . V_150 = F_83 ( V_7 -> V_152 , 1 ) ;
V_34 -> V_148 . V_73 = true ;
break;
}
if ( V_4 -> V_15 >= V_138 )
V_19 = V_111 -> V_19 ;
else
V_19 = 12 ;
V_24 = F_60 ( V_4 -> V_31 , V_34 -> V_148 . V_14 ,
V_19 , V_153 ,
& V_111 -> V_154 ) ;
if ( V_24 )
return V_24 ;
F_61 ( & V_111 -> V_154 , V_111 ) ;
if ( V_24 ) {
F_84 ( & V_111 -> V_154 ) ;
return V_24 ;
}
V_34 -> V_148 . V_115 = V_111 -> V_154 . V_115 ;
if ( V_4 -> V_15 == V_16 )
V_34 -> V_148 . V_115 -= 0x0020000000ULL ;
V_34 -> V_148 . V_150 = F_83 ( V_7 -> V_152 , 1 ) ;
V_34 -> V_148 . V_73 = true ;
}
break;
default:
return - V_61 ;
}
return 0 ;
}
static void
F_85 ( struct V_78 * V_5 , struct V_105 * V_34 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_110 * V_111 = V_34 -> V_112 ;
if ( ! V_4 -> V_31 || V_34 -> V_60 != V_63 )
return;
if ( ! V_111 -> V_154 . V_111 )
return;
F_74 ( & V_111 -> V_154 ) ;
F_84 ( & V_111 -> V_154 ) ;
}
static int
F_86 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
if ( V_2 -> V_34 . V_60 != V_63 ) {
if ( V_4 -> V_15 < V_16 ||
! F_55 ( V_9 ) )
return 0 ;
}
if ( V_2 -> V_34 . V_127 + V_2 -> V_34 . V_35 < V_4 -> V_155 )
return 0 ;
V_9 -> V_38 . V_47 = 0 ;
V_9 -> V_38 . V_48 = V_4 -> V_155 ;
F_13 ( V_9 , V_63 , 0 ) ;
return F_20 ( V_9 , false , true , false ) ;
}
void
F_87 ( struct V_8 * V_9 , struct V_107 * V_108 )
{
struct V_107 * V_156 ;
if ( F_88 ( V_108 ) )
F_89 ( V_108 ) ;
F_90 ( & V_9 -> V_2 . V_5 -> V_157 ) ;
V_156 = V_9 -> V_2 . V_145 ;
V_9 -> V_2 . V_145 = V_108 ;
F_91 ( & V_9 -> V_2 . V_5 -> V_157 ) ;
F_46 ( & V_156 ) ;
}
struct V_130 *
F_92 ( struct V_8 * V_9 , struct V_158 * V_131 )
{
struct V_130 * V_114 ;
F_73 (vma, &nvbo->vma_list, head) {
if ( V_114 -> V_131 == V_131 )
return V_114 ;
}
return NULL ;
}
int
F_93 ( struct V_8 * V_9 , struct V_158 * V_131 ,
struct V_130 * V_114 )
{
const T_1 V_14 = V_9 -> V_2 . V_34 . V_35 << V_36 ;
struct V_110 * V_111 = V_9 -> V_2 . V_34 . V_112 ;
int V_24 ;
V_24 = F_60 ( V_131 , V_14 , V_9 -> V_19 ,
V_153 , V_114 ) ;
if ( V_24 )
return V_24 ;
if ( V_9 -> V_2 . V_34 . V_60 == V_63 )
F_61 ( V_114 , V_9 -> V_2 . V_34 . V_112 ) ;
else
if ( V_9 -> V_2 . V_34 . V_60 == V_65 )
F_62 ( V_114 , 0 , V_14 , V_111 , V_111 -> V_133 ) ;
F_94 ( & V_114 -> V_27 , & V_9 -> V_29 ) ;
V_114 -> V_159 = 1 ;
return 0 ;
}
void
F_95 ( struct V_8 * V_9 , struct V_130 * V_114 )
{
if ( V_114 -> V_111 ) {
if ( V_9 -> V_2 . V_34 . V_60 != V_87 ) {
F_90 ( & V_9 -> V_2 . V_5 -> V_157 ) ;
F_96 ( & V_9 -> V_2 , false , false , false ) ;
F_91 ( & V_9 -> V_2 . V_5 -> V_157 ) ;
F_74 ( V_114 ) ;
}
F_84 ( V_114 ) ;
F_97 ( & V_114 -> V_27 ) ;
}
}
