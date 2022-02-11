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
struct V_22 * V_23 ,
struct V_8 * * V_24 )
{
struct V_3 * V_4 = V_7 -> V_25 ;
struct V_8 * V_9 ;
T_3 V_26 ;
int V_27 ;
int type = V_28 ;
if ( V_23 )
type = V_29 ;
V_9 = F_11 ( sizeof( struct V_8 ) , V_30 ) ;
if ( ! V_9 )
return - V_31 ;
F_12 ( & V_9 -> V_32 ) ;
F_12 ( & V_9 -> V_33 ) ;
F_12 ( & V_9 -> V_34 ) ;
V_9 -> V_17 = V_17 ;
V_9 -> V_21 = V_21 ;
V_9 -> V_2 . V_5 = & V_4 -> V_35 . V_5 ;
V_9 -> V_19 = 12 ;
if ( V_4 -> V_36 ) {
if ( ! ( V_12 & V_37 ) && V_14 > 256 * 1024 )
V_9 -> V_19 = V_4 -> V_36 -> V_38 ;
}
F_7 ( V_9 , V_12 , & V_13 , & V_14 ) ;
V_9 -> V_2 . V_39 . V_40 = V_14 >> V_41 ;
F_13 ( V_9 , V_12 , 0 ) ;
V_26 = F_14 ( & V_4 -> V_35 . V_5 , V_14 ,
sizeof( struct V_8 ) ) ;
V_27 = F_15 ( & V_4 -> V_35 . V_5 , & V_9 -> V_2 , V_14 ,
type , & V_9 -> V_42 ,
V_13 >> V_41 , 0 , false , NULL , V_26 , V_23 ,
F_1 ) ;
if ( V_27 ) {
return V_27 ;
}
* V_24 = V_9 ;
return 0 ;
}
static void
F_16 ( T_2 * V_43 , unsigned * V_44 , T_2 type , T_2 V_12 )
{
* V_44 = 0 ;
if ( type & V_45 )
V_43 [ ( * V_44 ) ++ ] = V_45 | V_12 ;
if ( type & V_37 )
V_43 [ ( * V_44 ) ++ ] = V_37 | V_12 ;
if ( type & V_46 )
V_43 [ ( * V_44 ) ++ ] = V_46 | V_12 ;
}
static void
F_17 ( struct V_8 * V_9 , T_2 type )
{
struct V_3 * V_4 = F_2 ( V_9 -> V_2 . V_5 ) ;
int V_47 = V_4 -> V_48 >> V_41 ;
if ( V_4 -> V_15 == V_49 &&
V_9 -> V_17 && ( type & V_45 ) &&
V_9 -> V_2 . V_39 . V_40 < V_47 / 4 ) {
if ( V_9 -> V_21 & V_50 ) {
V_9 -> V_42 . V_51 = V_47 / 2 ;
V_9 -> V_42 . V_52 = ~ 0 ;
} else {
V_9 -> V_42 . V_51 = 0 ;
V_9 -> V_42 . V_52 = V_47 / 2 ;
}
}
}
void
F_13 ( struct V_8 * V_9 , T_2 type , T_2 V_53 )
{
struct V_54 * V_43 = & V_9 -> V_42 ;
T_2 V_12 = V_55 |
( V_9 -> V_56 ? V_57 : 0 ) ;
V_43 -> V_42 = V_9 -> V_58 ;
F_16 ( V_9 -> V_58 , & V_43 -> V_59 ,
type , V_12 ) ;
V_43 -> V_60 = V_9 -> V_61 ;
F_16 ( V_9 -> V_61 , & V_43 -> V_62 ,
type | V_53 , V_12 ) ;
F_17 ( V_9 , type ) ;
}
int
F_18 ( struct V_8 * V_9 , T_2 V_63 )
{
struct V_3 * V_4 = F_2 ( V_9 -> V_2 . V_5 ) ;
struct V_1 * V_2 = & V_9 -> V_2 ;
int V_27 ;
if ( V_9 -> V_56 && ! ( V_63 & ( 1 << V_2 -> V_39 . V_64 ) ) ) {
F_19 ( F_2 ( V_2 -> V_5 ) -> V_7 ,
L_2 , V_2 ,
1 << V_2 -> V_39 . V_64 , V_63 ) ;
return - V_65 ;
}
if ( V_9 -> V_56 ++ )
return 0 ;
V_27 = F_20 ( V_2 , false , false , false , 0 ) ;
if ( V_27 )
goto V_66;
F_13 ( V_9 , V_63 , 0 ) ;
V_27 = F_21 ( V_9 , false , false , false ) ;
if ( V_27 == 0 ) {
switch ( V_2 -> V_39 . V_64 ) {
case V_67 :
V_4 -> V_68 -= V_2 -> V_39 . V_14 ;
break;
case V_69 :
V_4 -> V_70 . V_71 -= V_2 -> V_39 . V_14 ;
break;
default:
break;
}
}
F_22 ( V_2 ) ;
V_66:
if ( F_3 ( V_27 ) )
V_9 -> V_56 -- ;
return V_27 ;
}
int
F_23 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_2 ( V_9 -> V_2 . V_5 ) ;
struct V_1 * V_2 = & V_9 -> V_2 ;
int V_27 ;
if ( -- V_9 -> V_56 )
return 0 ;
V_27 = F_20 ( V_2 , false , false , false , 0 ) ;
if ( V_27 )
return V_27 ;
F_13 ( V_9 , V_2 -> V_39 . V_42 , 0 ) ;
V_27 = F_21 ( V_9 , false , false , false ) ;
if ( V_27 == 0 ) {
switch ( V_2 -> V_39 . V_64 ) {
case V_67 :
V_4 -> V_68 += V_2 -> V_39 . V_14 ;
break;
case V_69 :
V_4 -> V_70 . V_71 += V_2 -> V_39 . V_14 ;
break;
default:
break;
}
}
F_22 ( V_2 ) ;
return V_27 ;
}
int
F_24 ( struct V_8 * V_9 )
{
int V_27 ;
V_27 = F_20 ( & V_9 -> V_2 , false , false , false , 0 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_25 ( & V_9 -> V_2 , 0 , V_9 -> V_2 . V_39 . V_40 , & V_9 -> V_72 ) ;
F_22 ( & V_9 -> V_2 ) ;
return V_27 ;
}
void
F_26 ( struct V_8 * V_9 )
{
if ( V_9 )
F_27 ( & V_9 -> V_72 ) ;
}
int
F_21 ( struct V_8 * V_9 , bool V_73 ,
bool V_74 , bool V_75 )
{
int V_27 ;
V_27 = F_28 ( & V_9 -> V_2 , & V_9 -> V_42 , V_73 ,
V_74 , V_75 ) ;
if ( V_27 )
return V_27 ;
return 0 ;
}
T_4
F_29 ( struct V_8 * V_9 , unsigned V_76 )
{
bool V_77 ;
T_4 * V_39 = F_30 ( & V_9 -> V_72 , & V_77 ) ;
V_39 = & V_39 [ V_76 ] ;
if ( V_77 )
return F_31 ( ( void V_78 V_79 * ) V_39 ) ;
else
return * V_39 ;
}
void
F_32 ( struct V_8 * V_9 , unsigned V_76 , T_4 V_80 )
{
bool V_77 ;
T_4 * V_39 = F_30 ( & V_9 -> V_72 , & V_77 ) ;
V_39 = & V_39 [ V_76 ] ;
if ( V_77 )
F_33 ( V_80 , ( void V_78 V_79 * ) V_39 ) ;
else
* V_39 = V_80 ;
}
T_1
F_34 ( struct V_8 * V_9 , unsigned V_76 )
{
bool V_77 ;
T_1 * V_39 = F_30 ( & V_9 -> V_72 , & V_77 ) ;
V_39 = & V_39 [ V_76 ] ;
if ( V_77 )
return F_35 ( ( void V_78 V_79 * ) V_39 ) ;
else
return * V_39 ;
}
void
F_36 ( struct V_8 * V_9 , unsigned V_76 , T_1 V_80 )
{
bool V_77 ;
T_1 * V_39 = F_30 ( & V_9 -> V_72 , & V_77 ) ;
V_39 = & V_39 [ V_76 ] ;
if ( V_77 )
F_37 ( V_80 , ( void V_78 V_79 * ) V_39 ) ;
else
* V_39 = V_80 ;
}
static struct V_81 *
F_38 ( struct V_82 * V_5 ,
unsigned long V_14 , T_2 V_83 ,
struct V_84 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
switch ( V_4 -> V_70 . type ) {
#if V_86
case V_87 :
return F_39 ( V_5 , V_7 -> V_88 -> V_89 ,
V_14 , V_83 , V_85 ) ;
#endif
case V_90 :
case V_91 :
return F_40 ( V_5 , V_14 , V_83 ,
V_85 ) ;
default:
F_19 ( V_7 , L_3 ,
V_4 -> V_70 . type ) ;
break;
}
return NULL ;
}
static int
F_41 ( struct V_82 * V_5 , T_2 V_12 )
{
return 0 ;
}
static int
F_42 ( struct V_82 * V_5 , T_2 type ,
struct V_92 * V_93 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
switch ( type ) {
case V_94 :
V_93 -> V_12 = V_95 ;
V_93 -> V_96 = V_55 ;
V_93 -> V_97 = V_98 ;
break;
case V_67 :
if ( V_4 -> V_15 >= V_16 ) {
V_93 -> V_99 = & V_100 ;
V_93 -> V_101 = false ;
V_93 -> V_102 = true ;
} else {
V_93 -> V_99 = & V_103 ;
}
V_93 -> V_12 = V_104 |
V_95 ;
V_93 -> V_96 = V_105 |
V_106 ;
V_93 -> V_97 = V_106 ;
break;
case V_69 :
if ( V_4 -> V_15 >= V_16 )
V_93 -> V_99 = & V_107 ;
else
V_93 -> V_99 = & V_103 ;
switch ( V_4 -> V_70 . type ) {
case V_87 :
V_93 -> V_12 = V_95 ;
V_93 -> V_96 = V_105 |
V_106 ;
V_93 -> V_97 = V_106 ;
break;
case V_90 :
case V_91 :
V_93 -> V_12 = V_95 |
V_108 ;
V_93 -> V_96 = V_55 ;
V_93 -> V_97 = V_98 ;
break;
default:
F_19 ( V_7 , L_4 ,
V_4 -> V_70 . type ) ;
return - V_65 ;
}
break;
default:
F_19 ( V_7 , L_5 , ( unsigned ) type ) ;
return - V_65 ;
}
return 0 ;
}
static void
F_43 ( struct V_1 * V_2 , struct V_54 * V_43 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
switch ( V_2 -> V_39 . V_64 ) {
case V_67 :
F_13 ( V_9 , V_37 ,
V_46 ) ;
break;
default:
F_13 ( V_9 , V_46 , 0 ) ;
break;
}
* V_43 = V_9 -> V_42 ;
}
static int
F_44 ( struct V_109 * V_110 ,
struct V_8 * V_9 , bool V_111 ,
bool V_74 , bool V_75 ,
struct V_112 * V_113 )
{
struct V_114 * V_115 = NULL ;
int V_27 ;
V_27 = F_45 ( V_110 , & V_115 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_46 ( & V_9 -> V_2 , V_115 , NULL , V_111 ,
V_74 , V_75 , V_113 ) ;
F_47 ( & V_115 ) ;
return V_27 ;
}
static int
F_48 ( struct V_109 * V_110 , struct V_1 * V_2 ,
struct V_112 * V_116 , struct V_112 * V_113 )
{
struct V_117 * V_118 = V_116 -> V_119 ;
int V_27 = F_49 ( V_110 , 10 ) ;
if ( V_27 == 0 ) {
F_50 ( V_110 , V_120 , 0x0400 , 8 ) ;
F_51 ( V_110 , F_52 ( V_118 -> V_121 [ 0 ] . V_122 ) ) ;
F_51 ( V_110 , F_53 ( V_118 -> V_121 [ 0 ] . V_122 ) ) ;
F_51 ( V_110 , F_52 ( V_118 -> V_121 [ 1 ] . V_122 ) ) ;
F_51 ( V_110 , F_53 ( V_118 -> V_121 [ 1 ] . V_122 ) ) ;
F_51 ( V_110 , V_20 ) ;
F_51 ( V_110 , V_20 ) ;
F_51 ( V_110 , V_20 ) ;
F_51 ( V_110 , V_113 -> V_40 ) ;
F_54 ( V_110 , V_120 , 0x0300 , 0x0386 ) ;
}
return V_27 ;
}
static int
F_55 ( struct V_109 * V_110 , T_1 V_123 )
{
int V_27 = F_49 ( V_110 , 2 ) ;
if ( V_27 == 0 ) {
F_50 ( V_110 , V_120 , 0x0000 , 1 ) ;
F_51 ( V_110 , V_123 ) ;
}
return V_27 ;
}
static int
F_56 ( struct V_109 * V_110 , struct V_1 * V_2 ,
struct V_112 * V_116 , struct V_112 * V_113 )
{
struct V_117 * V_118 = V_116 -> V_119 ;
T_5 V_124 = V_118 -> V_121 [ 0 ] . V_122 ;
T_5 V_125 = V_118 -> V_121 [ 1 ] . V_122 ;
T_1 V_126 = V_113 -> V_40 ;
int V_27 ;
V_126 = V_113 -> V_40 ;
while ( V_126 ) {
int V_127 = ( V_126 > 8191 ) ? 8191 : V_126 ;
V_27 = F_49 ( V_110 , 11 ) ;
if ( V_27 )
return V_27 ;
F_50 ( V_110 , V_120 , 0x030c , 8 ) ;
F_51 ( V_110 , F_52 ( V_124 ) ) ;
F_51 ( V_110 , F_53 ( V_124 ) ) ;
F_51 ( V_110 , F_52 ( V_125 ) ) ;
F_51 ( V_110 , F_53 ( V_125 ) ) ;
F_51 ( V_110 , V_20 ) ;
F_51 ( V_110 , V_20 ) ;
F_51 ( V_110 , V_20 ) ;
F_51 ( V_110 , V_127 ) ;
F_50 ( V_110 , V_120 , 0x0300 , 1 ) ;
F_51 ( V_110 , 0x00000110 ) ;
V_126 -= V_127 ;
V_124 += ( V_20 * V_127 ) ;
V_125 += ( V_20 * V_127 ) ;
}
return 0 ;
}
static int
F_57 ( struct V_109 * V_110 , struct V_1 * V_2 ,
struct V_112 * V_116 , struct V_112 * V_113 )
{
struct V_117 * V_118 = V_116 -> V_119 ;
T_5 V_124 = V_118 -> V_121 [ 0 ] . V_122 ;
T_5 V_125 = V_118 -> V_121 [ 1 ] . V_122 ;
T_1 V_126 = V_113 -> V_40 ;
int V_27 ;
V_126 = V_113 -> V_40 ;
while ( V_126 ) {
int V_127 = ( V_126 > 2047 ) ? 2047 : V_126 ;
V_27 = F_49 ( V_110 , 12 ) ;
if ( V_27 )
return V_27 ;
F_50 ( V_110 , V_120 , 0x0238 , 2 ) ;
F_51 ( V_110 , F_52 ( V_125 ) ) ;
F_51 ( V_110 , F_53 ( V_125 ) ) ;
F_50 ( V_110 , V_120 , 0x030c , 6 ) ;
F_51 ( V_110 , F_52 ( V_124 ) ) ;
F_51 ( V_110 , F_53 ( V_124 ) ) ;
F_51 ( V_110 , V_20 ) ;
F_51 ( V_110 , V_20 ) ;
F_51 ( V_110 , V_20 ) ;
F_51 ( V_110 , V_127 ) ;
F_50 ( V_110 , V_120 , 0x0300 , 1 ) ;
F_51 ( V_110 , 0x00100110 ) ;
V_126 -= V_127 ;
V_124 += ( V_20 * V_127 ) ;
V_125 += ( V_20 * V_127 ) ;
}
return 0 ;
}
static int
F_58 ( struct V_109 * V_110 , struct V_1 * V_2 ,
struct V_112 * V_116 , struct V_112 * V_113 )
{
struct V_117 * V_118 = V_116 -> V_119 ;
T_5 V_124 = V_118 -> V_121 [ 0 ] . V_122 ;
T_5 V_125 = V_118 -> V_121 [ 1 ] . V_122 ;
T_1 V_126 = V_113 -> V_40 ;
int V_27 ;
V_126 = V_113 -> V_40 ;
while ( V_126 ) {
int V_127 = ( V_126 > 8191 ) ? 8191 : V_126 ;
V_27 = F_49 ( V_110 , 11 ) ;
if ( V_27 )
return V_27 ;
F_59 ( V_110 , V_120 , 0x030c , 8 ) ;
F_51 ( V_110 , F_52 ( V_124 ) ) ;
F_51 ( V_110 , F_53 ( V_124 ) ) ;
F_51 ( V_110 , F_52 ( V_125 ) ) ;
F_51 ( V_110 , F_53 ( V_125 ) ) ;
F_51 ( V_110 , V_20 ) ;
F_51 ( V_110 , V_20 ) ;
F_51 ( V_110 , V_20 ) ;
F_51 ( V_110 , V_127 ) ;
F_59 ( V_110 , V_120 , 0x0300 , 1 ) ;
F_51 ( V_110 , 0x00000110 ) ;
V_126 -= V_127 ;
V_124 += ( V_20 * V_127 ) ;
V_125 += ( V_20 * V_127 ) ;
}
return 0 ;
}
static int
F_60 ( struct V_109 * V_110 , struct V_1 * V_2 ,
struct V_112 * V_116 , struct V_112 * V_113 )
{
struct V_117 * V_118 = V_116 -> V_119 ;
int V_27 = F_49 ( V_110 , 7 ) ;
if ( V_27 == 0 ) {
F_59 ( V_110 , V_120 , 0x0320 , 6 ) ;
F_51 ( V_110 , F_52 ( V_118 -> V_121 [ 0 ] . V_122 ) ) ;
F_51 ( V_110 , F_53 ( V_118 -> V_121 [ 0 ] . V_122 ) ) ;
F_51 ( V_110 , F_52 ( V_118 -> V_121 [ 1 ] . V_122 ) ) ;
F_51 ( V_110 , F_53 ( V_118 -> V_121 [ 1 ] . V_122 ) ) ;
F_51 ( V_110 , 0x00000000 ) ;
F_51 ( V_110 , V_113 -> V_40 << V_41 ) ;
}
return V_27 ;
}
static int
F_61 ( struct V_109 * V_110 , struct V_1 * V_2 ,
struct V_112 * V_116 , struct V_112 * V_113 )
{
struct V_117 * V_118 = V_116 -> V_119 ;
int V_27 = F_49 ( V_110 , 7 ) ;
if ( V_27 == 0 ) {
F_59 ( V_110 , V_120 , 0x0304 , 6 ) ;
F_51 ( V_110 , V_113 -> V_40 << V_41 ) ;
F_51 ( V_110 , F_52 ( V_118 -> V_121 [ 0 ] . V_122 ) ) ;
F_51 ( V_110 , F_53 ( V_118 -> V_121 [ 0 ] . V_122 ) ) ;
F_51 ( V_110 , F_52 ( V_118 -> V_121 [ 1 ] . V_122 ) ) ;
F_51 ( V_110 , F_53 ( V_118 -> V_121 [ 1 ] . V_122 ) ) ;
F_51 ( V_110 , 0x00000000 ) ;
}
return V_27 ;
}
static int
F_62 ( struct V_109 * V_110 , T_1 V_123 )
{
int V_27 = F_63 ( V_110 , V_128 , 32 , 0xfe0 , 0x1000 ,
& V_110 -> V_129 ) ;
if ( V_27 == 0 ) {
V_27 = F_49 ( V_110 , 6 ) ;
if ( V_27 == 0 ) {
F_59 ( V_110 , V_120 , 0x0000 , 1 ) ;
F_51 ( V_110 , V_123 ) ;
F_59 ( V_110 , V_120 , 0x0180 , 3 ) ;
F_51 ( V_110 , V_128 ) ;
F_51 ( V_110 , V_130 ) ;
F_51 ( V_110 , V_130 ) ;
} else {
F_64 ( V_110 , V_128 ) ;
}
}
return V_27 ;
}
static int
F_65 ( struct V_109 * V_110 , struct V_1 * V_2 ,
struct V_112 * V_116 , struct V_112 * V_113 )
{
struct V_117 * V_118 = V_116 -> V_119 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
T_5 V_131 = ( V_113 -> V_40 << V_41 ) ;
T_5 V_124 = V_118 -> V_121 [ 0 ] . V_122 ;
T_5 V_125 = V_118 -> V_121 [ 1 ] . V_122 ;
int V_27 ;
while ( V_131 ) {
T_1 V_132 , V_133 , V_134 ;
V_132 = F_66 ( V_131 , ( T_5 ) ( 4 * 1024 * 1024 ) ) ;
V_133 = 16 * 4 ;
V_134 = V_132 / V_133 ;
if ( V_113 -> V_64 == V_67 &&
F_67 ( V_9 ) ) {
V_27 = F_49 ( V_110 , 8 ) ;
if ( V_27 )
return V_27 ;
F_59 ( V_110 , V_120 , 0x0200 , 7 ) ;
F_51 ( V_110 , 0 ) ;
F_51 ( V_110 , 0 ) ;
F_51 ( V_110 , V_133 ) ;
F_51 ( V_110 , V_134 ) ;
F_51 ( V_110 , 1 ) ;
F_51 ( V_110 , 0 ) ;
F_51 ( V_110 , 0 ) ;
} else {
V_27 = F_49 ( V_110 , 2 ) ;
if ( V_27 )
return V_27 ;
F_59 ( V_110 , V_120 , 0x0200 , 1 ) ;
F_51 ( V_110 , 1 ) ;
}
if ( V_116 -> V_64 == V_67 &&
F_67 ( V_9 ) ) {
V_27 = F_49 ( V_110 , 8 ) ;
if ( V_27 )
return V_27 ;
F_59 ( V_110 , V_120 , 0x021c , 7 ) ;
F_51 ( V_110 , 0 ) ;
F_51 ( V_110 , 0 ) ;
F_51 ( V_110 , V_133 ) ;
F_51 ( V_110 , V_134 ) ;
F_51 ( V_110 , 1 ) ;
F_51 ( V_110 , 0 ) ;
F_51 ( V_110 , 0 ) ;
} else {
V_27 = F_49 ( V_110 , 2 ) ;
if ( V_27 )
return V_27 ;
F_59 ( V_110 , V_120 , 0x021c , 1 ) ;
F_51 ( V_110 , 1 ) ;
}
V_27 = F_49 ( V_110 , 14 ) ;
if ( V_27 )
return V_27 ;
F_59 ( V_110 , V_120 , 0x0238 , 2 ) ;
F_51 ( V_110 , F_52 ( V_124 ) ) ;
F_51 ( V_110 , F_52 ( V_125 ) ) ;
F_59 ( V_110 , V_120 , 0x030c , 8 ) ;
F_51 ( V_110 , F_53 ( V_124 ) ) ;
F_51 ( V_110 , F_53 ( V_125 ) ) ;
F_51 ( V_110 , V_133 ) ;
F_51 ( V_110 , V_133 ) ;
F_51 ( V_110 , V_133 ) ;
F_51 ( V_110 , V_134 ) ;
F_51 ( V_110 , 0x00000101 ) ;
F_51 ( V_110 , 0x00000000 ) ;
F_59 ( V_110 , V_120 , V_135 , 1 ) ;
F_51 ( V_110 , 0 ) ;
V_131 -= V_132 ;
V_124 += V_132 ;
V_125 += V_132 ;
}
return 0 ;
}
static int
F_68 ( struct V_109 * V_110 , T_1 V_123 )
{
int V_27 = F_63 ( V_110 , V_128 , 32 , 0xfe0 , 0x1000 ,
& V_110 -> V_129 ) ;
if ( V_27 == 0 ) {
V_27 = F_49 ( V_110 , 4 ) ;
if ( V_27 == 0 ) {
F_59 ( V_110 , V_120 , 0x0000 , 1 ) ;
F_51 ( V_110 , V_123 ) ;
F_59 ( V_110 , V_120 , 0x0180 , 1 ) ;
F_51 ( V_110 , V_128 ) ;
}
}
return V_27 ;
}
static inline T_2
F_69 ( struct V_1 * V_2 ,
struct V_109 * V_110 , struct V_112 * V_39 )
{
if ( V_39 -> V_64 == V_69 )
return V_110 -> V_136 ;
return V_110 -> V_137 ;
}
static int
F_70 ( struct V_109 * V_110 , struct V_1 * V_2 ,
struct V_112 * V_116 , struct V_112 * V_113 )
{
T_1 V_124 = V_116 -> V_138 << V_41 ;
T_1 V_125 = V_113 -> V_138 << V_41 ;
T_1 V_126 = V_113 -> V_40 ;
int V_27 ;
V_27 = F_49 ( V_110 , 3 ) ;
if ( V_27 )
return V_27 ;
F_59 ( V_110 , V_120 , V_139 , 2 ) ;
F_51 ( V_110 , F_69 ( V_2 , V_110 , V_116 ) ) ;
F_51 ( V_110 , F_69 ( V_2 , V_110 , V_113 ) ) ;
V_126 = V_113 -> V_40 ;
while ( V_126 ) {
int V_127 = ( V_126 > 2047 ) ? 2047 : V_126 ;
V_27 = F_49 ( V_110 , 11 ) ;
if ( V_27 )
return V_27 ;
F_59 ( V_110 , V_120 ,
V_140 , 8 ) ;
F_51 ( V_110 , V_124 ) ;
F_51 ( V_110 , V_125 ) ;
F_51 ( V_110 , V_20 ) ;
F_51 ( V_110 , V_20 ) ;
F_51 ( V_110 , V_20 ) ;
F_51 ( V_110 , V_127 ) ;
F_51 ( V_110 , 0x00000101 ) ;
F_51 ( V_110 , 0x00000000 ) ;
F_59 ( V_110 , V_120 , V_135 , 1 ) ;
F_51 ( V_110 , 0 ) ;
V_126 -= V_127 ;
V_124 += ( V_20 * V_127 ) ;
V_125 += ( V_20 * V_127 ) ;
}
return 0 ;
}
static int
F_71 ( struct V_109 * V_110 , struct V_8 * V_9 ,
struct V_112 * V_39 , struct V_141 * V_121 )
{
struct V_117 * V_118 = V_39 -> V_119 ;
int V_27 ;
V_27 = F_72 ( V_110 -> V_142 , V_39 -> V_40 << V_41 ,
V_118 -> V_19 , V_143 , V_121 ) ;
if ( V_27 )
return V_27 ;
if ( V_39 -> V_64 == V_67 )
F_73 ( V_121 , V_118 ) ;
else
F_74 ( V_121 , 0 , V_39 -> V_40 << V_41 , V_118 ) ;
return 0 ;
}
static int
F_75 ( struct V_1 * V_2 , int V_111 , bool V_144 ,
bool V_74 , bool V_75 ,
struct V_112 * V_113 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_109 * V_110 = V_110 = V_4 -> V_145 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_112 * V_116 = & V_2 -> V_39 ;
int V_27 ;
F_76 ( & V_110 -> V_146 , V_147 ) ;
if ( V_4 -> V_15 >= V_16 ) {
struct V_117 * V_118 = V_116 -> V_119 ;
V_27 = F_71 ( V_110 , V_9 , V_116 , & V_118 -> V_121 [ 0 ] ) ;
if ( V_27 )
goto V_66;
V_27 = F_71 ( V_110 , V_9 , V_113 , & V_118 -> V_121 [ 1 ] ) ;
if ( V_27 )
goto V_66;
}
V_27 = V_4 -> V_35 . V_148 ( V_110 , V_2 , & V_2 -> V_39 , V_113 ) ;
if ( V_27 == 0 ) {
V_27 = F_44 ( V_110 , V_9 , V_111 ,
V_74 ,
V_75 , V_113 ) ;
}
V_66:
F_77 ( & V_110 -> V_146 ) ;
return V_27 ;
}
void
F_78 ( struct V_109 * V_110 )
{
struct V_3 * V_4 = V_110 -> V_7 -> V_25 ;
static const struct {
const char * V_149 ;
int V_150 ;
T_1 V_151 ;
int (* F_79)( struct V_109 * ,
struct V_1 * ,
struct V_112 * , struct V_112 * );
int (* F_80)( struct V_109 * , T_1 V_123 );
} V_152 [] = {
{ L_6 , 0 , 0xa0b5 , F_48 , F_55 } ,
{ L_7 , 5 , 0x90b8 , F_56 , F_55 } ,
{ L_8 , 4 , 0x90b5 , F_56 , F_55 } ,
{ L_6 , 0 , 0x85b5 , F_58 , F_62 } ,
{ L_9 , 0 , 0x74c1 , F_61 , F_62 } ,
{ L_10 , 0 , 0x9039 , F_57 , F_55 } ,
{ L_10 , 0 , 0x5039 , F_65 , F_62 } ,
{ L_10 , 0 , 0x0039 , F_70 , F_68 } ,
{} ,
{ L_9 , 0 , 0x88b4 , F_60 , F_62 } ,
} , * V_153 = V_152 ;
const char * V_149 = L_11 ;
int V_27 ;
do {
T_1 V_123 = ( V_153 -> V_150 << 16 ) | V_153 -> V_151 ;
V_27 = F_81 ( V_110 , V_123 , V_153 -> V_151 ) ;
if ( V_27 == 0 ) {
V_27 = V_153 -> F_80 ( V_110 , V_123 ) ;
if ( V_27 == 0 ) {
V_4 -> V_35 . V_148 = V_153 -> F_79 ;
V_149 = V_153 -> V_149 ;
break;
}
}
} while ( ( ++ V_153 ) -> F_79 );
F_82 ( V_110 -> V_7 , L_12 , V_149 ) ;
}
static int
F_83 ( struct V_1 * V_2 , bool V_111 , bool V_144 ,
bool V_74 , bool V_75 ,
struct V_112 * V_113 )
{
T_1 V_154 = V_37 | V_55 ;
struct V_54 V_42 ;
struct V_112 V_155 ;
int V_27 ;
V_42 . V_51 = V_42 . V_52 = 0 ;
V_42 . V_59 = V_42 . V_62 = 1 ;
V_42 . V_42 = V_42 . V_60 = & V_154 ;
V_155 = * V_113 ;
V_155 . V_119 = NULL ;
V_27 = F_84 ( V_2 , & V_42 , & V_155 , V_144 , V_74 , V_75 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_85 ( V_2 -> V_35 , & V_155 ) ;
if ( V_27 )
goto V_66;
V_27 = F_75 ( V_2 , true , V_144 , V_74 , V_75 , & V_155 ) ;
if ( V_27 )
goto V_66;
V_27 = F_86 ( V_2 , true , V_74 , V_75 , V_113 ) ;
V_66:
F_87 ( V_2 , & V_155 ) ;
return V_27 ;
}
static int
F_88 ( struct V_1 * V_2 , bool V_111 , bool V_144 ,
bool V_74 , bool V_75 ,
struct V_112 * V_113 )
{
T_1 V_154 = V_37 | V_55 ;
struct V_54 V_42 ;
struct V_112 V_155 ;
int V_27 ;
V_42 . V_51 = V_42 . V_52 = 0 ;
V_42 . V_59 = V_42 . V_62 = 1 ;
V_42 . V_42 = V_42 . V_60 = & V_154 ;
V_155 = * V_113 ;
V_155 . V_119 = NULL ;
V_27 = F_84 ( V_2 , & V_42 , & V_155 , V_144 , V_74 , V_75 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_86 ( V_2 , true , V_74 , V_75 , & V_155 ) ;
if ( V_27 )
goto V_66;
V_27 = F_75 ( V_2 , true , V_144 , V_74 , V_75 , V_113 ) ;
if ( V_27 )
goto V_66;
V_66:
F_87 ( V_2 , & V_155 ) ;
return V_27 ;
}
static void
F_89 ( struct V_1 * V_2 , struct V_112 * V_113 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_141 * V_121 ;
if ( V_2 -> V_156 != F_1 )
return;
F_90 (vma, &nvbo->vma_list, head) {
if ( V_113 && V_113 -> V_64 == V_67 ) {
F_73 ( V_121 , V_113 -> V_119 ) ;
} else
if ( V_113 && V_113 -> V_64 == V_69 &&
V_9 -> V_19 == V_121 -> V_142 -> V_157 ) {
if ( ( (struct V_117 * ) V_113 -> V_119 ) -> V_23 )
F_91 ( V_121 , 0 , V_113 ->
V_40 << V_41 ,
V_113 -> V_119 ) ;
else
F_74 ( V_121 , 0 , V_113 ->
V_40 << V_41 ,
V_113 -> V_119 ) ;
} else {
F_92 ( V_121 ) ;
}
}
}
static int
F_93 ( struct V_1 * V_2 , struct V_112 * V_113 ,
struct V_158 * * V_159 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
T_5 V_122 = V_113 -> V_138 << V_41 ;
* V_159 = NULL ;
if ( V_113 -> V_64 != V_67 )
return 0 ;
if ( V_4 -> V_15 >= V_49 ) {
* V_159 = F_94 ( V_7 , V_122 , V_113 -> V_14 ,
V_9 -> V_17 ,
V_9 -> V_21 ) ;
}
return 0 ;
}
static void
F_95 ( struct V_1 * V_2 ,
struct V_158 * V_159 ,
struct V_158 * * V_160 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
F_5 ( V_7 , * V_160 , V_2 -> V_161 ) ;
* V_160 = V_159 ;
}
static int
F_96 ( struct V_1 * V_2 , bool V_111 , bool V_144 ,
bool V_74 , bool V_75 ,
struct V_112 * V_113 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
struct V_112 * V_116 = & V_2 -> V_39 ;
struct V_158 * V_159 = NULL ;
int V_27 = 0 ;
if ( V_4 -> V_15 < V_16 ) {
V_27 = F_93 ( V_2 , V_113 , & V_159 ) ;
if ( V_27 )
return V_27 ;
}
if ( V_116 -> V_64 == V_94 && ! V_2 -> V_35 ) {
F_97 ( V_2 -> V_39 . V_119 != NULL ) ;
V_2 -> V_39 = * V_113 ;
V_113 -> V_119 = NULL ;
goto V_66;
}
if ( ! V_4 -> V_35 . V_148 ) {
V_27 = F_98 ( V_2 , V_111 , V_74 , V_75 , V_113 ) ;
goto V_66;
}
if ( V_113 -> V_64 == V_94 )
V_27 = F_83 ( V_2 , V_111 , V_144 , V_74 , V_75 , V_113 ) ;
else if ( V_116 -> V_64 == V_94 )
V_27 = F_88 ( V_2 , V_111 , V_144 , V_74 , V_75 , V_113 ) ;
else
V_27 = F_75 ( V_2 , V_111 , V_144 , V_74 , V_75 , V_113 ) ;
if ( ! V_27 )
goto V_66;
V_27 = F_98 ( V_2 , V_111 , V_74 , V_75 , V_113 ) ;
V_66:
if ( V_4 -> V_15 < V_16 ) {
if ( V_27 )
F_95 ( V_2 , NULL , & V_159 ) ;
else
F_95 ( V_2 , V_159 , & V_9 -> V_11 ) ;
}
return V_27 ;
}
static int
F_99 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
return 0 ;
}
static int
F_100 ( struct V_82 * V_5 , struct V_112 * V_39 )
{
struct V_92 * V_93 = & V_5 -> V_93 [ V_39 -> V_64 ] ;
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_27 ;
V_39 -> V_164 . V_165 = NULL ;
V_39 -> V_164 . V_122 = 0 ;
V_39 -> V_164 . V_14 = V_39 -> V_40 << V_41 ;
V_39 -> V_164 . V_166 = 0 ;
V_39 -> V_164 . V_77 = false ;
if ( ! ( V_93 -> V_12 & V_95 ) )
return - V_65 ;
switch ( V_39 -> V_64 ) {
case V_94 :
return 0 ;
case V_69 :
#if V_86
if ( V_4 -> V_70 . type == V_87 ) {
V_39 -> V_164 . V_122 = V_39 -> V_138 << V_41 ;
V_39 -> V_164 . V_166 = V_4 -> V_70 . V_167 ;
V_39 -> V_164 . V_77 = true ;
}
#endif
break;
case V_67 :
{
struct V_117 * V_118 = V_39 -> V_119 ;
T_6 V_19 ;
if ( ! V_4 -> V_36 ) {
V_39 -> V_164 . V_122 = V_39 -> V_138 << V_41 ;
V_39 -> V_164 . V_166 = F_101 ( V_7 -> V_168 , 1 ) ;
V_39 -> V_164 . V_77 = true ;
break;
}
if ( V_4 -> V_15 >= V_169 )
V_19 = V_118 -> V_19 ;
else
V_19 = 12 ;
V_27 = F_72 ( V_4 -> V_36 , V_39 -> V_164 . V_14 ,
V_19 , V_170 ,
& V_118 -> V_171 ) ;
if ( V_27 )
return V_27 ;
F_73 ( & V_118 -> V_171 , V_118 ) ;
if ( V_27 ) {
F_102 ( & V_118 -> V_171 ) ;
return V_27 ;
}
V_39 -> V_164 . V_122 = V_118 -> V_171 . V_122 ;
if ( V_4 -> V_15 == V_16 )
V_39 -> V_164 . V_122 -= 0x0020000000ULL ;
V_39 -> V_164 . V_166 = F_101 ( V_7 -> V_168 , 1 ) ;
V_39 -> V_164 . V_77 = true ;
}
break;
default:
return - V_65 ;
}
return 0 ;
}
static void
F_103 ( struct V_82 * V_5 , struct V_112 * V_39 )
{
struct V_3 * V_4 = F_2 ( V_5 ) ;
struct V_117 * V_118 = V_39 -> V_119 ;
if ( ! V_4 -> V_36 || V_39 -> V_64 != V_67 )
return;
if ( ! V_118 -> V_171 . V_118 )
return;
F_92 ( & V_118 -> V_171 ) ;
F_102 ( & V_118 -> V_171 ) ;
}
static int
F_104 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_8 * V_9 = V_8 ( V_2 ) ;
if ( V_2 -> V_39 . V_64 != V_67 ) {
if ( V_4 -> V_15 < V_16 ||
! F_67 ( V_9 ) )
return 0 ;
}
if ( V_2 -> V_39 . V_138 + V_2 -> V_39 . V_40 < V_4 -> V_172 )
return 0 ;
V_9 -> V_42 . V_51 = 0 ;
V_9 -> V_42 . V_52 = V_4 -> V_172 ;
F_13 ( V_9 , V_45 , 0 ) ;
return F_21 ( V_9 , false , true , false ) ;
}
static int
F_105 ( struct V_81 * V_35 )
{
struct V_173 * V_174 = ( void * ) V_35 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
unsigned V_175 ;
int V_176 ;
bool V_177 = ! ! ( V_35 -> V_83 & V_178 ) ;
if ( V_35 -> V_179 != V_180 )
return 0 ;
if ( V_177 && V_35 -> V_23 ) {
F_106 ( V_35 -> V_23 , V_35 -> V_181 ,
V_174 -> V_182 , V_35 -> V_40 ) ;
V_35 -> V_179 = V_183 ;
return 0 ;
}
V_4 = F_2 ( V_35 -> V_5 ) ;
V_7 = V_4 -> V_7 ;
#if V_86
if ( V_4 -> V_70 . type == V_87 ) {
return F_107 ( V_35 ) ;
}
#endif
#ifdef F_108
if ( F_109 () ) {
return F_110 ( ( void * ) V_35 , V_7 -> V_7 ) ;
}
#endif
V_176 = F_111 ( V_35 ) ;
if ( V_176 ) {
return V_176 ;
}
for ( V_175 = 0 ; V_175 < V_35 -> V_40 ; V_175 ++ ) {
V_174 -> V_182 [ V_175 ] = F_112 ( V_7 -> V_168 , V_35 -> V_181 [ V_175 ] ,
0 , V_20 ,
V_184 ) ;
if ( F_113 ( V_7 -> V_168 , V_174 -> V_182 [ V_175 ] ) ) {
while ( -- V_175 ) {
F_114 ( V_7 -> V_168 , V_174 -> V_182 [ V_175 ] ,
V_20 , V_184 ) ;
V_174 -> V_182 [ V_175 ] = 0 ;
}
F_115 ( V_35 ) ;
return - V_185 ;
}
}
return 0 ;
}
static void
F_116 ( struct V_81 * V_35 )
{
struct V_173 * V_174 = ( void * ) V_35 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
unsigned V_175 ;
bool V_177 = ! ! ( V_35 -> V_83 & V_178 ) ;
if ( V_177 )
return;
V_4 = F_2 ( V_35 -> V_5 ) ;
V_7 = V_4 -> V_7 ;
#if V_86
if ( V_4 -> V_70 . type == V_87 ) {
F_117 ( V_35 ) ;
return;
}
#endif
#ifdef F_108
if ( F_109 () ) {
F_118 ( ( void * ) V_35 , V_7 -> V_7 ) ;
return;
}
#endif
for ( V_175 = 0 ; V_175 < V_35 -> V_40 ; V_175 ++ ) {
if ( V_174 -> V_182 [ V_175 ] ) {
F_114 ( V_7 -> V_168 , V_174 -> V_182 [ V_175 ] ,
V_20 , V_184 ) ;
}
}
F_115 ( V_35 ) ;
}
void
F_119 ( struct V_8 * V_9 , struct V_114 * V_115 )
{
struct V_114 * V_186 = NULL ;
if ( F_120 ( V_115 ) )
F_121 ( V_115 ) ;
F_122 ( & V_9 -> V_2 . V_5 -> V_187 ) ;
V_186 = V_9 -> V_2 . V_161 ;
V_9 -> V_2 . V_161 = V_115 ;
F_123 ( & V_9 -> V_2 . V_5 -> V_187 ) ;
F_47 ( & V_186 ) ;
}
static void
F_124 ( void * * V_161 )
{
F_47 ( (struct V_114 * * ) V_161 ) ;
}
static void *
F_125 ( void * V_161 )
{
return F_121 ( V_161 ) ;
}
static bool
F_126 ( void * V_161 , void * V_188 )
{
return F_127 ( V_161 ) ;
}
static int
F_128 ( void * V_161 , void * V_188 , bool V_189 , bool V_144 )
{
return F_129 ( V_161 , V_189 , V_144 ) ;
}
static int
F_130 ( void * V_161 , void * V_188 )
{
return 0 ;
}
struct V_141 *
F_131 ( struct V_8 * V_9 , struct V_190 * V_142 )
{
struct V_141 * V_121 ;
F_90 (vma, &nvbo->vma_list, head) {
if ( V_121 -> V_142 == V_142 )
return V_121 ;
}
return NULL ;
}
int
F_132 ( struct V_8 * V_9 , struct V_190 * V_142 ,
struct V_141 * V_121 )
{
const T_1 V_14 = V_9 -> V_2 . V_39 . V_40 << V_41 ;
struct V_117 * V_118 = V_9 -> V_2 . V_39 . V_119 ;
int V_27 ;
V_27 = F_72 ( V_142 , V_14 , V_9 -> V_19 ,
V_170 , V_121 ) ;
if ( V_27 )
return V_27 ;
if ( V_9 -> V_2 . V_39 . V_64 == V_67 )
F_73 ( V_121 , V_9 -> V_2 . V_39 . V_119 ) ;
else if ( V_9 -> V_2 . V_39 . V_64 == V_69 ) {
if ( V_118 -> V_23 )
F_91 ( V_121 , 0 , V_14 , V_118 ) ;
else
F_74 ( V_121 , 0 , V_14 , V_118 ) ;
}
F_133 ( & V_121 -> V_32 , & V_9 -> V_34 ) ;
V_121 -> V_191 = 1 ;
return 0 ;
}
void
F_134 ( struct V_8 * V_9 , struct V_141 * V_121 )
{
if ( V_121 -> V_118 ) {
if ( V_9 -> V_2 . V_39 . V_64 != V_94 ) {
F_122 ( & V_9 -> V_2 . V_5 -> V_187 ) ;
F_135 ( & V_9 -> V_2 , false , false , false ) ;
F_123 ( & V_9 -> V_2 . V_5 -> V_187 ) ;
F_92 ( V_121 ) ;
}
F_102 ( V_121 ) ;
F_136 ( & V_121 -> V_32 ) ;
}
}
