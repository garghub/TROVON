static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = F_2 ( V_2 -> V_5 , V_6 ) ;
V_2 -> V_3 . V_7 = F_2 ( V_2 -> V_5 , V_8 ) ;
V_2 -> V_3 . V_9 = F_2 ( V_2 -> V_5 , V_10 ) ;
V_2 -> V_3 . V_11 = F_2 ( V_2 -> V_5 , V_12 ) ;
V_2 -> V_3 . V_13 = F_2 ( V_2 -> V_5 , V_14 ) ;
V_2 -> V_3 . V_15 = F_2 ( V_2 -> V_5 , V_16 ) ;
V_2 -> V_3 . V_17 = F_2 ( V_2 -> V_5 , V_18 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
int V_19 , V_20 ;
T_1 V_21 ;
T_1 V_22 ;
void T_2 * V_7 = V_2 -> V_3 . V_7 ;
struct V_23 * V_24 = V_2 -> V_24 ;
V_21 = F_4 ( V_2 -> V_3 . V_4 + V_25 ) >> 4 ;
for ( V_19 = 0 ; V_19 < F_5 ( V_24 -> V_26 ) ; V_19 ++ ) {
for ( V_20 = F_5 ( V_24 -> V_26 [ V_19 ] ) - 1 ; V_20 >= 0 ; V_20 -- ) {
V_22 = ( 1 << 16 ) + ( ( V_21 + V_19 ) << 2 ) + V_20 ;
F_6 ( V_22 , V_7 + V_27 ) ;
V_22 = V_24 -> V_26 [ V_19 ] [ V_20 ] ;
F_6 ( V_22 , V_7 + V_28 ) ;
}
}
}
static void F_7 ( struct V_1 * V_2 )
{
int V_19 , V_20 ;
T_1 V_21 ;
T_1 V_22 ;
void T_2 * V_7 = V_2 -> V_3 . V_7 ;
struct V_23 * V_24 = V_2 -> V_24 ;
V_21 = F_4 ( V_2 -> V_3 . V_4 + V_25 ) >> 4 ;
for ( V_19 = 0 ; V_19 < F_5 ( V_24 -> V_26 ) ; V_19 ++ ) {
for ( V_20 = F_5 ( V_24 -> V_26 [ V_19 ] ) - 1 ; V_20 >= 0 ; V_20 -- ) {
V_22 = ( ( V_21 + V_19 ) << 2 ) + V_20 ;
F_6 ( V_22 , V_7 + V_27 ) ;
V_22 = F_4 ( V_7 + V_28 ) ;
V_24 -> V_26 [ V_19 ] [ V_20 ] = V_22 ;
}
}
}
static void F_8 ( struct V_1 * V_2 )
{
T_1 V_22 = 0 ;
void T_2 * V_11 = V_2 -> V_3 . V_11 ;
void T_2 * V_13 = V_2 -> V_3 . V_13 ;
void T_2 * V_15 = V_2 -> V_3 . V_15 ;
void T_2 * V_17 = V_2 -> V_3 . V_17 ;
void T_2 * V_9 = V_2 -> V_3 . V_9 ;
F_6 ( 0x1 , V_11 + V_29 ) ;
F_6 ( 0x101 , V_15 + V_30 ) ;
F_6 ( 0x101 , V_17 + V_30 ) ;
F_6 ( 1 , V_11 ) ;
V_22 = F_4 ( V_13 + V_31 ) ;
F_6 ( ( V_22 & 0xFFFFFFFE ) , V_13 + V_31 ) ;
F_6 ( 0x1 , V_13 + V_32 ) ;
F_6 ( 0x17F , V_13 + V_33 ) ;
F_6 ( 0x71201100 , V_13 + V_34 ) ;
F_6 ( 0x0 , V_15 + V_30 ) ;
F_6 ( 0x0 , V_17 + V_30 ) ;
F_6 ( 0x1 , V_11 + V_35 ) ;
F_6 ( 0x1 , V_13 + V_36 ) ;
F_6 ( 0x1 , V_9 + V_37 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_19 , V_20 ;
T_1 V_38 = 0 , V_22 = 0 ;
void T_2 * V_9 = V_2 -> V_3 . V_9 ;
T_1 * V_39 = & V_2 -> V_24 -> V_40 [ V_41 ] ;
for ( V_19 = 0 ; V_19 < V_42 ; V_19 ++ ) {
F_6 ( V_38 , V_9 + V_43 ) ;
for ( V_20 = 0 ; V_20 < V_44 ; V_20 ++ ) {
V_22 = * V_39 ++ ;
F_6 ( V_22 , V_9 + V_45 ) ;
}
V_38 += V_46 ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
int V_19 ;
T_1 V_38 = 0 ;
T_1 * V_39 = & V_2 -> V_24 -> V_40 [ V_41 ] ;
void T_2 * V_9 = V_2 -> V_3 . V_9 ;
for ( V_19 = 0 ; V_19 < V_42 ; V_19 ++ ) {
F_6 ( V_38 , V_9 + V_43 ) ;
* V_39 ++ = F_4 ( V_9 + V_45 ) ;
* V_39 ++ = F_4 ( V_9 + V_45 ) ;
* V_39 ++ = F_4 ( V_9 + V_45 ) & 0xFFFFFF ;
V_38 += V_46 ;
}
}
static void F_11 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
* V_48 = V_2 -> V_24 -> V_48 ;
F_12 ( V_2 , L_1 ,
V_48 -> V_49 , V_48 -> V_50 , V_48 -> V_51 , V_48 -> V_52 ) ;
F_12 ( V_2 , L_2 , V_48 -> V_53 ,
V_48 -> V_54 , V_48 -> V_55 , V_48 -> V_56 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
T_3 V_59 = V_2 -> V_24 -> V_60 . V_59 ;
F_12 ( V_2 , L_3 , V_59 ) ;
if ( V_59 != 0 ) {
F_14 (node, &inst->fb_use_list, list) {
struct V_61 * V_62 = (struct V_61 * ) V_58 -> V_62 ;
if ( V_59 == ( T_3 ) V_62 -> V_63 . V_64 ) {
F_15 ( & V_58 -> V_65 ,
& V_2 -> V_66 ) ;
break;
}
}
}
V_58 = F_16 ( & V_2 -> V_67 ,
struct V_57 , V_65 ) ;
V_58 -> V_62 = V_2 -> V_68 ;
F_15 ( & V_58 -> V_65 , & V_2 -> V_69 ) ;
if ( V_2 -> V_24 -> V_60 . V_70 ) {
V_58 = F_16 ( & V_2 -> V_67 ,
struct V_57 , V_65 ) ;
V_58 -> V_62 = V_2 -> V_68 ;
F_15 ( & V_58 -> V_65 , & V_2 -> V_71 ) ;
}
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_57 * V_58 , * V_72 ;
F_18 (node, tmp, &inst->fb_use_list, list)
F_15 ( & V_58 -> V_65 , & V_2 -> V_66 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_19 ;
F_20 ( & V_2 -> V_67 ) ;
F_20 ( & V_2 -> V_69 ) ;
F_20 ( & V_2 -> V_66 ) ;
F_20 ( & V_2 -> V_71 ) ;
for ( V_19 = 0 ; V_19 < F_5 ( V_2 -> V_73 ) ; V_19 ++ ) {
F_20 ( & V_2 -> V_73 [ V_19 ] . V_65 ) ;
V_2 -> V_73 [ V_19 ] . V_62 = NULL ;
F_21 ( & V_2 -> V_73 [ V_19 ] . V_65 ,
& V_2 -> V_67 ) ;
}
}
static void F_22 ( struct V_1 * V_2 , void * V_62 )
{
struct V_57 * V_58 ;
if ( V_62 ) {
V_58 = F_16 ( & V_2 -> V_67 ,
struct V_57 , V_65 ) ;
V_58 -> V_62 = V_62 ;
F_15 ( & V_58 -> V_65 , & V_2 -> V_66 ) ;
}
}
static int F_23 ( struct V_1 * V_2 )
{
int V_74 ;
struct V_75 * V_76 = & V_2 -> V_77 ;
V_76 -> V_78 = V_79 ;
V_74 = F_24 ( V_2 -> V_5 , V_76 ) ;
if ( V_74 ) {
F_25 ( V_2 , L_4 ) ;
return V_74 ;
}
V_2 -> V_24 -> V_60 . V_80 = ( T_3 ) V_76 -> V_64 ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_75 * V_76 = & V_2 -> V_77 ;
if ( V_76 -> V_81 )
F_27 ( V_2 -> V_5 , V_76 ) ;
V_2 -> V_24 -> V_60 . V_80 = 0 ;
}
static int F_28 ( struct V_82 * V_5 , unsigned long * V_83 )
{
struct V_1 * V_2 ;
int V_74 ;
V_2 = F_29 ( sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_86 . V_87 = V_88 ;
V_2 -> V_86 . V_89 = V_5 -> V_89 -> V_90 ;
V_2 -> V_86 . V_5 = V_5 ;
V_2 -> V_86 . V_91 = V_92 ;
V_74 = F_30 ( & V_2 -> V_86 ) ;
if ( V_74 ) {
F_25 ( V_2 , L_5 , V_74 ) ;
goto V_93;
}
V_2 -> V_24 = (struct V_23 * ) V_2 -> V_86 . V_24 ;
F_19 ( V_2 ) ;
V_74 = F_23 ( V_2 ) ;
if ( V_74 )
goto V_94;
F_1 ( V_2 ) ;
F_12 ( V_2 , L_6 , V_2 ) ;
* V_83 = ( unsigned long ) V_2 ;
return 0 ;
V_94:
F_31 ( & V_2 -> V_86 ) ;
V_93:
F_32 ( V_2 ) ;
return V_74 ;
}
static int F_33 ( unsigned long V_83 , struct V_75 * V_95 ,
struct V_61 * V_62 , bool * V_96 )
{
struct V_1 * V_2 = (struct V_1 * ) V_83 ;
struct V_97 * V_60 = & V_2 -> V_24 -> V_60 ;
struct V_98 * V_86 = & V_2 -> V_86 ;
unsigned char * V_99 ;
unsigned int V_100 ;
int V_74 = 0 ;
T_3 V_101 ;
T_3 V_102 ;
if ( V_95 == NULL ) {
F_17 ( V_2 ) ;
return F_34 ( V_86 ) ;
}
V_101 = V_62 ? ( V_103 ) V_62 -> V_63 . V_64 : 0 ;
V_102 = V_62 ? ( V_103 ) V_62 -> V_104 . V_64 : 0 ;
F_12 ( V_2 , L_7 ,
V_2 -> V_105 , V_101 , V_102 , V_62 ) ;
V_2 -> V_68 = V_62 ;
V_60 -> V_106 = ( unsigned long ) V_95 -> V_64 ;
V_60 -> V_107 = V_95 -> V_78 ;
V_60 -> V_108 = V_101 ;
V_60 -> V_109 = V_102 ;
F_12 ( V_2 , L_8 , V_2 -> V_105 ) ;
F_3 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
V_99 = ( unsigned char * ) V_95 -> V_81 ;
V_100 = ( * ( V_99 + 9 ) << 24 ) | ( * ( V_99 + 8 ) << 16 ) |
( * ( V_99 + 7 ) << 8 ) | * ( V_99 + 6 ) ;
V_74 = F_35 ( V_86 , & V_100 , 1 ) ;
if ( V_74 ) {
F_22 ( V_2 , V_62 ) ;
if ( V_60 -> V_110 ) {
F_12 ( V_2 , L_9 ) ;
return 0 ;
}
goto error;
}
if ( V_60 -> V_111 ) {
F_12 ( V_2 , L_10 ) ;
* V_96 = true ;
F_22 ( V_2 , V_62 ) ;
return 0 ;
}
F_36 ( V_2 -> V_5 , V_112 ,
V_113 ) ;
if ( V_2 -> V_24 -> V_114 )
F_10 ( V_2 ) ;
F_13 ( V_2 ) ;
F_7 ( V_2 ) ;
V_74 = F_37 ( V_86 ) ;
if ( V_74 )
goto error;
F_12 ( V_2 , L_11 , V_2 -> V_105 ,
V_60 -> V_70 ) ;
V_2 -> V_105 ++ ;
* V_96 = false ;
return 0 ;
error:
F_25 ( V_2 , L_12 , V_2 -> V_105 , V_74 ) ;
return V_74 ;
}
static void F_38 ( struct V_1 * V_2 , struct V_61 * * V_115 )
{
struct V_57 * V_58 ;
struct V_61 * V_62 ;
V_58 = F_39 ( & V_2 -> V_71 ,
struct V_57 , V_65 ) ;
if ( V_58 ) {
F_15 ( & V_58 -> V_65 , & V_2 -> V_67 ) ;
V_62 = (struct V_61 * ) V_58 -> V_62 ;
V_62 -> V_116 |= V_117 ;
F_12 ( V_2 , L_13 ,
V_58 -> V_62 , V_62 -> V_116 ) ;
} else {
V_62 = NULL ;
F_12 ( V_2 , L_14 ) ;
}
* V_115 = V_62 ;
}
static void F_40 ( struct V_1 * V_2 , struct V_61 * * V_115 )
{
struct V_57 * V_58 ;
struct V_61 * V_62 ;
V_58 = F_39 ( & V_2 -> V_66 ,
struct V_57 , V_65 ) ;
if ( V_58 ) {
F_15 ( & V_58 -> V_65 , & V_2 -> V_67 ) ;
V_62 = (struct V_61 * ) V_58 -> V_62 ;
V_62 -> V_116 |= V_118 ;
F_12 ( V_2 , L_15 ,
V_58 -> V_62 , V_62 -> V_116 ) ;
} else {
V_62 = NULL ;
F_12 ( V_2 , L_16 ) ;
}
* V_115 = V_62 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_119 * V_120 )
{
V_120 -> V_121 = 0 ;
V_120 -> V_4 = 0 ;
V_120 -> V_122 = V_2 -> V_24 -> V_48 . V_49 ;
V_120 -> V_123 = V_2 -> V_24 -> V_48 . V_50 ;
F_12 ( V_2 , L_17 ,
V_120 -> V_121 , V_120 -> V_4 , V_120 -> V_122 , V_120 -> V_123 ) ;
}
static int F_42 ( unsigned long V_83 ,
enum V_124 type , void * V_125 )
{
struct V_1 * V_2 = (struct V_1 * ) V_83 ;
switch ( type ) {
case V_126 :
F_38 ( V_2 , V_125 ) ;
break;
case V_127 :
F_40 ( V_2 , V_125 ) ;
break;
case V_128 :
F_11 ( V_2 , V_125 ) ;
break;
case V_129 :
F_41 ( V_2 , V_125 ) ;
break;
case V_130 :
* ( ( unsigned int * ) V_125 ) = V_131 ;
break;
default:
F_25 ( V_2 , L_18 , type ) ;
return - V_132 ;
}
return 0 ;
}
static void F_43 ( unsigned long V_83 )
{
struct V_1 * V_2 = (struct V_1 * ) V_83 ;
F_44 ( V_2 ) ;
F_31 ( & V_2 -> V_86 ) ;
F_26 ( V_2 ) ;
F_32 ( V_2 ) ;
}
struct V_133 * F_45 ( void )
{
return & V_134 ;
}
