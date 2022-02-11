static unsigned long F_1 ( unsigned long V_1 ,
T_1 V_2 , T_1 V_3 )
{
if ( ( ! V_3 || ! V_2 ) || ( V_3 == V_2 ) )
return V_1 ;
return F_2 ( V_1 , ( unsigned long ) V_2 , ( unsigned long ) V_3 ) ;
}
static unsigned long F_3 ( struct V_4 * V_5 ,
unsigned long V_1 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
return F_1 ( V_1 , V_7 -> V_2 , V_7 -> V_3 ) ;
}
static void F_5 ( unsigned long V_8 ,
unsigned long V_1 , T_1 * V_2 , T_1 * V_3 )
{
unsigned long V_9 ;
unsigned long V_10 ;
unsigned long V_11 ;
if ( V_8 <= V_1 ) {
V_8 = V_1 ;
* V_2 = 0 ;
* V_3 = 0 ;
} else {
if ( V_8 < V_12 )
V_8 = V_12 ;
else if ( V_8 > V_13 )
V_8 = V_13 ;
V_11 = F_6 ( V_8 , V_1 ) ;
V_10 = V_1 / V_11 ;
V_9 = V_8 / V_11 ;
while ( ( V_9 > 4095 ) || ( V_10 > 511 ) ) {
V_9 >>= 1 ;
V_10 >>= 1 ;
}
if ( V_9 == 0 )
V_9 = 1 ;
if ( V_10 == 0 )
V_10 = 1 ;
* V_2 = V_9 ;
* V_3 = V_10 ;
}
}
static long F_7 ( struct V_4 * V_5 , unsigned long V_8 ,
unsigned long * V_1 )
{
T_1 V_2 , V_3 ;
F_5 ( V_8 , * V_1 , & V_2 , & V_3 ) ;
return ( long ) F_1 ( * V_1 , V_2 , V_3 ) ;
}
static int F_8 ( struct V_4 * V_5 , unsigned long V_8 ,
unsigned long V_1 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
if ( ! V_8 || ( V_8 == V_1 ) ) {
V_7 -> V_3 = 0 ;
V_7 -> V_2 = 0 ;
return 0 ;
}
if ( ( V_8 < V_12 ) ||
( V_8 > V_13 ) ) {
F_9 ( L_1 , V_14 , V_8 ) ;
return - V_15 ;
}
if ( V_8 < V_1 ) {
F_9 ( L_2 , V_14 ,
V_8 , V_1 ) ;
return - V_15 ;
}
F_5 ( V_8 , V_1 , & V_7 -> V_2 , & V_7 -> V_3 ) ;
return 0 ;
}
static T_2 F_10 ( T_1 V_2 , T_1 V_3 )
{
T_2 V_16 ;
T_1 V_17 = V_2 / V_3 ;
if ( V_17 >= 16 )
return 0 ;
V_16 = 4 ;
while ( V_17 > 1 ) {
V_17 >>= 1 ;
-- V_16 ;
}
return V_16 ;
}
static T_2 F_11 ( struct V_4 * V_5 , T_1 V_2 , T_1 V_3 )
{
struct V_18 * V_19 = F_12 ( V_5 -> V_18 ) ;
unsigned long V_8 = F_13 ( V_19 ) ;
V_8 = F_2 ( V_8 , ( unsigned long ) V_2 , ( unsigned long ) V_3 ) ;
if ( V_8 >= 175000000 )
return 0x3 ;
if ( V_8 >= 150000000 )
return 0x02 ;
if ( V_8 >= 125000000 )
return 0x01 ;
return 0x00 ;
}
static int F_14 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
T_1 V_2 = V_7 -> V_2 ;
T_1 V_3 = V_7 -> V_3 ;
T_1 V_17 ;
T_2 V_20 ;
T_2 V_16 ;
T_1 V_21 ;
T_2 V_22 [ 4 ] ;
T_2 V_23 = V_7 -> V_24 * V_25 ;
unsigned V_26 ;
if ( ( ! V_3 || ! V_2 ) || ( V_3 == V_2 ) ) {
F_15 ( V_7 -> V_27 -> V_28 ,
V_23 + V_29 , 0x80 , 0x80 ) ;
} else {
V_16 = F_10 ( V_2 , V_3 ) ;
V_21 = V_2 * F_16 ( V_16 ) ;
V_20 = V_21 / V_3 ;
if ( ( V_20 < 16 ) || ( V_20 > 63 ) ) {
F_9 ( L_3 , V_14 , V_20 ) ;
return - V_15 ;
}
V_17 = V_21 - ( V_3 * V_20 ) ;
if ( V_17 > 511 ) {
F_9 ( L_4 , V_14 , V_17 ) ;
return - V_15 ;
}
F_9 ( L_5 , V_14 ,
V_2 , V_3 , V_16 , V_20 , V_17 ) ;
V_22 [ 0 ] = V_2 >> 4 ;
V_22 [ 1 ] = ( ( V_2 & 0x0F ) << 4 ) | ( ( V_17 >> 5 ) & 0x0F ) ;
V_22 [ 2 ] = ( ( V_17 & 0x1F ) << 3 ) | ( ( V_20 >> 3 ) & 0x07 ) ;
V_22 [ 3 ] = ( ( V_20 & 0x07 ) << 5 ) | ( V_16 << 2 ) |
F_11 ( V_5 , V_2 , V_3 ) ;
for ( V_26 = 0 ; V_26 < F_17 ( V_22 ) ; ++ V_26 )
F_18 ( V_7 -> V_27 -> V_28 ,
V_23 + V_30 + V_26 , V_22 [ V_26 ] ) ;
F_15 ( V_7 -> V_27 -> V_28 ,
V_23 + V_29 , 0x80 , 0x00 ) ;
}
return 0 ;
}
static void F_19 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
T_2 V_23 = V_7 -> V_24 * V_25 ;
F_15 ( V_7 -> V_27 -> V_28 ,
V_23 + V_29 , 0x80 , 0x80 ) ;
}
static void F_20 ( struct V_31 * V_7 , T_1 V_32 )
{
switch ( V_7 -> V_24 ) {
case 0 :
F_15 ( V_7 -> V_27 -> V_28 ,
V_33 ,
0x03 , ( V_32 >> 8 ) & 0x03 ) ;
F_18 ( V_7 -> V_27 -> V_28 , 0x03 , V_32 & 0xFF ) ;
break;
case 1 :
F_15 ( V_7 -> V_27 -> V_28 , 0x16 , 0x7F , V_32 ) ;
break;
case 2 :
F_15 ( V_7 -> V_27 -> V_28 , 0x17 , 0x7F , V_32 ) ;
break;
case 3 :
F_15 ( V_7 -> V_27 -> V_28 , 0x26 , 0x7F , V_32 ) ;
break;
case 4 :
F_15 ( V_7 -> V_27 -> V_28 , 0x27 , 0x7F , V_32 ) ;
break;
case 5 :
F_15 ( V_7 -> V_27 -> V_28 , 0x36 , 0x7F , V_32 ) ;
break;
case 6 :
F_15 ( V_7 -> V_27 -> V_28 , 0x37 , 0x7F , V_32 ) ;
break;
case 7 :
F_15 ( V_7 -> V_27 -> V_28 , 0x46 , 0x7F , V_32 ) ;
break;
case 8 :
F_15 ( V_7 -> V_27 -> V_28 , 0x47 , 0x7F , V_32 ) ;
break;
}
}
static void F_21 ( struct V_31 * V_7 )
{
switch ( V_7 -> V_24 ) {
case 0 :
F_15 ( V_7 -> V_27 -> V_28 ,
V_33 , 0x0c , 0x0c ) ;
break;
case 1 :
case 2 :
F_15 ( V_7 -> V_27 -> V_28 , 0x14 , 0x03 , 0x03 ) ;
break;
case 3 :
case 4 :
F_15 ( V_7 -> V_27 -> V_28 , 0x24 , 0x03 , 0x03 ) ;
break;
case 5 :
case 6 :
F_15 ( V_7 -> V_27 -> V_28 , 0x34 , 0x03 , 0x03 ) ;
break;
case 7 :
case 8 :
F_15 ( V_7 -> V_27 -> V_28 , 0x44 , 0x03 , 0x03 ) ;
break;
}
}
static int F_22 ( struct V_4 * V_5 )
{
struct V_31 * V_7 = F_23 ( V_5 ) ;
F_20 ( V_7 , V_7 -> V_32 ) ;
F_21 ( V_7 ) ;
return 0 ;
}
static void F_24 ( struct V_4 * V_5 )
{
struct V_31 * V_7 = F_23 ( V_5 ) ;
F_20 ( V_7 , 0 ) ;
}
static unsigned long F_25 ( struct V_4 * V_5 ,
unsigned long V_1 )
{
struct V_31 * V_7 = F_23 ( V_5 ) ;
if ( V_7 -> V_32 )
return V_1 / V_7 -> V_32 ;
return 0 ;
}
static T_1 F_26 ( unsigned long V_8 ,
unsigned long V_1 )
{
unsigned long V_34 ;
if ( ! V_8 )
return 0 ;
if ( V_8 >= V_1 )
return 1 ;
V_34 = F_27 ( V_1 , V_8 ) ;
if ( V_34 > 0x7F )
V_34 = 0x7F ;
return ( T_1 ) V_34 ;
}
static unsigned long F_28 (
struct V_4 * V_5 , unsigned long V_8 )
{
struct V_18 * V_22 = F_12 ( V_5 -> V_18 ) ;
struct V_18 * V_35 = F_12 ( V_22 ) ;
unsigned long V_36 = F_13 ( V_35 ) ;
unsigned long V_37 = V_8 ;
T_1 V_38 ;
T_1 V_39 ;
T_1 V_40 ;
T_1 V_41 ;
if ( V_36 % V_8 == 0 )
return V_36 ;
V_38 = ( T_1 ) F_29 ( 1ul , F_30 ( V_12 , V_8 ) ) ;
V_39 = ( T_1 ) F_31 ( 127ul , V_13 / V_8 ) ;
if ( V_38 > V_39 )
return 0 ;
V_40 = V_38 ;
for ( V_41 = V_38 ; V_41 < V_39 ; ++ V_41 ) {
unsigned long V_42 = V_8 * V_41 ;
long V_43 = F_32 ( V_22 , V_42 ) ;
unsigned long V_44 ;
unsigned long V_45 ;
if ( V_43 <= 0 )
continue;
V_44 = V_43 / V_41 ;
V_45 = abs ( ( long ) V_44 - ( long ) V_8 ) ;
if ( V_45 < V_37 ) {
V_40 = V_41 ;
V_37 = V_45 ;
}
}
return V_8 * V_40 ;
}
static long F_33 ( struct V_4 * V_5 , unsigned long V_8 ,
unsigned long * V_1 )
{
unsigned long V_46 = * V_1 ;
T_1 V_34 = F_26 ( V_8 , V_46 ) ;
if ( V_46 / V_34 != V_8 ) {
V_46 = F_28 ( V_5 , V_8 ) ;
V_34 = F_26 ( V_8 , V_46 ) ;
* V_1 = V_46 ;
}
if ( V_34 )
return ( long ) ( V_46 / V_34 ) ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 , unsigned long V_8 ,
unsigned long V_1 )
{
struct V_31 * V_7 = F_23 ( V_5 ) ;
V_7 -> V_32 = F_26 ( V_8 , V_1 ) ;
return 0 ;
}
static T_1 F_35 ( unsigned long V_8 ,
unsigned long V_1 )
{
unsigned long V_34 ;
if ( ! V_8 )
return 0 ;
if ( V_8 >= V_1 )
return 1 ;
V_34 = F_27 ( V_1 , V_8 ) ;
if ( V_34 > 0x3FF )
V_34 = 0x3FF ;
return ( T_1 ) V_34 ;
}
static long F_36 ( struct V_4 * V_5 , unsigned long V_8 ,
unsigned long * V_1 )
{
unsigned long V_46 = * V_1 ;
T_1 V_34 = F_35 ( V_8 , V_46 ) ;
if ( V_34 )
return ( long ) ( V_46 / V_34 ) ;
return 0 ;
}
static int F_37 ( struct V_4 * V_5 , unsigned long V_8 ,
unsigned long V_1 )
{
struct V_31 * V_7 = F_23 ( V_5 ) ;
V_7 -> V_32 = F_35 ( V_8 , V_1 ) ;
return 0 ;
}
static int F_38 (
void * V_47 , const void * V_7 , T_3 V_48 )
{
struct V_49 * V_50 = V_47 ;
struct V_51 * V_52 = F_39 ( V_50 ) ;
int V_53 ;
T_2 V_54 [ 2 ] ;
if ( V_48 != 2 )
return - V_55 ;
V_54 [ 0 ] = V_56 | ( ( T_2 * ) V_7 ) [ 0 ] ;
V_54 [ 1 ] = ( ( T_2 * ) V_7 ) [ 1 ] ;
F_40 ( & V_52 -> V_50 , L_6 , V_14 , V_48 ,
V_54 [ 0 ] , V_54 [ 1 ] ) ;
V_53 = F_41 ( V_52 , V_54 , V_48 ) ;
if ( F_42 ( V_53 == V_48 ) )
return 0 ;
else if ( V_53 < 0 )
return V_53 ;
else
return - V_57 ;
}
static int F_43 ( void * V_47 ,
const void * V_58 , T_3 V_59 , void * V_60 , T_3 V_61 )
{
struct V_49 * V_50 = V_47 ;
struct V_51 * V_52 = F_39 ( V_50 ) ;
struct V_62 V_63 [ 2 ] ;
int V_53 ;
T_2 V_54 [ 2 ] ;
if ( V_59 != 1 )
return - V_55 ;
V_63 [ 0 ] . V_64 = V_52 -> V_64 ;
V_63 [ 0 ] . V_65 = 0 ;
V_63 [ 0 ] . V_66 = V_54 ;
if ( V_61 == 1 ) {
V_54 [ 0 ] =
V_56 | ( ( T_2 * ) V_58 ) [ 0 ] ;
V_63 [ 0 ] . V_67 = 1 ;
} else {
V_54 [ 0 ] =
V_68 | ( ( T_2 * ) V_58 ) [ 0 ] ;
V_54 [ 1 ] = V_61 ;
V_63 [ 0 ] . V_67 = 2 ;
}
V_63 [ 1 ] . V_64 = V_52 -> V_64 ;
V_63 [ 1 ] . V_65 = V_69 ;
V_63 [ 1 ] . V_67 = V_61 ;
V_63 [ 1 ] . V_66 = V_60 ;
V_53 = F_44 ( V_52 -> V_70 , V_63 , 2 ) ;
if ( F_42 ( V_53 == 2 ) ) {
F_40 ( & V_52 -> V_50 , L_7 , V_14 ,
V_59 , V_61 , V_54 [ 0 ] , * ( ( T_2 * ) V_60 ) ) ;
return 0 ;
} else if ( V_53 < 0 )
return V_53 ;
else
return - V_57 ;
}
static struct V_4 *
F_45 ( struct V_71 * V_72 , void * V_73 )
{
struct V_74 * V_7 = V_73 ;
unsigned int V_75 = V_72 -> args [ 0 ] ;
if ( V_75 >= F_17 ( V_7 -> V_18 ) ) {
F_46 ( L_8 , V_14 , V_75 ) ;
return F_47 ( - V_15 ) ;
}
return & V_7 -> V_18 [ V_75 ] . V_5 ;
}
static int F_48 ( struct V_51 * V_76 ,
const struct V_77 * V_78 )
{
struct V_74 * V_7 ;
struct V_79 * V_80 = V_76 -> V_50 . V_81 ;
const char * V_82 ;
const char * V_83 [ V_84 ] = { NULL ,} ;
struct V_85 V_86 ;
T_4 V_87 ;
int V_26 ;
int V_88 ;
struct V_79 * V_89 ;
char V_90 [ 6 ] ;
struct V_91 V_92 = {
. V_93 = L_9 ,
. V_94 = 8 ,
. V_95 = 8 ,
. V_96 = V_97 ,
} ;
F_40 ( & V_76 -> V_50 , L_10 , V_14 ) ;
V_7 = F_49 ( & V_76 -> V_50 , sizeof( * V_7 ) , V_98 ) ;
if ( ! V_7 )
return - V_99 ;
V_7 -> V_51 = V_76 ;
V_7 -> V_100 = & V_101 [ V_78 -> V_102 ] ;
V_92 . V_103 = V_25 +
V_7 -> V_100 -> V_104 * 0x10 - 1 ;
V_7 -> V_28 = F_50 ( & V_76 -> V_50 , & V_105 ,
& V_76 -> V_50 , & V_92 ) ;
if ( F_51 ( V_7 -> V_28 ) ) {
F_52 ( & V_76 -> V_50 , L_11 ) ;
return F_53 ( V_7 -> V_28 ) ;
}
F_54 ( V_76 , V_7 ) ;
V_82 = F_55 ( V_80 , 0 ) ;
if ( ! V_82 ) {
F_52 ( & V_76 -> V_50 , L_12 ) ;
return - V_106 ;
}
F_40 ( & V_76 -> V_50 , L_13 , V_82 ) ;
if ( F_56 ( V_80 , L_14 , & V_87 ) == 0 )
F_18 ( V_7 -> V_28 ,
V_107 , ( V_87 << 3 ) & 0xF8 ) ;
F_15 ( V_7 -> V_28 , V_108 , F_16 ( 4 ) , 0 ) ;
F_15 ( V_7 -> V_28 , 0x02 , F_16 ( 7 ) , 0 ) ;
V_86 . V_109 = & V_110 ;
V_86 . V_65 = 0 ;
V_86 . V_111 = & V_82 ;
V_86 . V_112 = V_82 ? 1 : 0 ;
for ( V_26 = 0 ; V_26 < V_7 -> V_100 -> V_104 ; ++ V_26 ) {
V_83 [ V_26 ] = F_57 ( V_98 , L_15 ,
V_76 -> V_50 . V_81 -> V_93 , V_26 ) ;
V_86 . V_93 = V_83 [ V_26 ] ;
V_7 -> V_22 [ V_26 ] . V_27 = V_7 ;
V_7 -> V_22 [ V_26 ] . V_5 . V_86 = & V_86 ;
V_7 -> V_22 [ V_26 ] . V_24 = V_26 ;
V_88 = F_58 ( & V_76 -> V_50 , & V_7 -> V_22 [ V_26 ] . V_5 ) ;
if ( V_88 ) {
F_52 ( & V_76 -> V_50 , L_16 , V_26 ) ;
goto error;
}
sprintf ( V_90 , L_17 , V_26 + 1 ) ;
V_89 = F_59 ( V_80 , V_90 ) ;
if ( ! V_89 )
continue;
if ( ! F_56 ( V_89 ,
L_18 , & V_87 ) ) {
V_88 = F_60 ( V_7 -> V_22 [ V_26 ] . V_5 . V_18 , V_87 ) ;
if ( V_88 )
F_52 ( & V_76 -> V_50 ,
L_19 ,
V_87 ) ;
}
if ( ! F_56 ( V_89 ,
L_20 , & V_87 ) ) {
T_2 V_113 = F_61 ( V_89 ,
L_21 ) ? 0x80 : 0x00 ;
F_15 ( V_7 -> V_28 ,
0x16 + ( V_26 * V_25 ) ,
0x80 , V_113 ) ;
F_15 ( V_7 -> V_28 ,
0x12 + ( V_26 * V_25 ) ,
0x07 , V_87 & 0x07 ) ;
}
}
V_86 . V_109 = & V_114 ;
V_86 . V_65 = 0 ;
V_86 . V_112 = 1 ;
V_86 . V_111 = & V_82 ;
V_86 . V_93 = F_57 ( V_98 , L_22 , V_76 -> V_50 . V_81 -> V_93 ) ;
V_7 -> V_18 [ 0 ] . V_27 = V_7 ;
V_7 -> V_18 [ 0 ] . V_5 . V_86 = & V_86 ;
V_7 -> V_18 [ 0 ] . V_24 = 0 ;
V_7 -> V_18 [ 0 ] . V_32 = 1 ;
V_88 = F_58 ( & V_76 -> V_50 , & V_7 -> V_18 [ 0 ] . V_5 ) ;
F_62 ( V_86 . V_93 ) ;
if ( V_88 ) {
F_52 ( & V_76 -> V_50 , L_23 ) ;
goto error;
}
V_86 . V_109 = & V_115 ;
V_86 . V_65 = V_116 ;
V_86 . V_112 = 1 ;
for ( V_26 = 1 ; V_26 < V_7 -> V_100 -> V_117 ; ++ V_26 ) {
V_86 . V_93 = F_57 ( V_98 , L_24 ,
V_76 -> V_50 . V_81 -> V_93 , V_26 + 1 ) ;
V_7 -> V_18 [ V_26 ] . V_27 = V_7 ;
V_7 -> V_18 [ V_26 ] . V_5 . V_86 = & V_86 ;
V_7 -> V_18 [ V_26 ] . V_24 = V_26 ;
V_7 -> V_18 [ V_26 ] . V_32 = 1 ;
switch ( V_26 ) {
case 1 :
case 2 :
V_86 . V_111 = & V_83 [ 0 ] ;
break;
case 3 :
case 4 :
V_86 . V_111 = & V_83 [ 1 ] ;
break;
case 5 :
case 6 :
V_86 . V_111 = & V_83 [ 2 ] ;
break;
case 7 :
case 8 :
V_86 . V_111 = & V_83 [ 3 ] ;
break;
}
V_88 = F_58 ( & V_76 -> V_50 , & V_7 -> V_18 [ V_26 ] . V_5 ) ;
F_62 ( V_86 . V_93 ) ;
if ( V_88 ) {
F_52 ( & V_76 -> V_50 , L_25 ) ;
goto error;
}
}
V_88 = F_63 ( V_76 -> V_50 . V_81 , F_45 ,
V_7 ) ;
if ( V_88 )
F_52 ( & V_76 -> V_50 , L_26 ) ;
V_88 = 0 ;
error:
for ( V_26 = 0 ; V_26 < V_7 -> V_100 -> V_104 ; ++ V_26 )
F_62 ( V_83 [ V_26 ] ) ;
return V_88 ;
}
