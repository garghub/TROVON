static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_4 ;
for (; ; ) {
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 ) {
F_4 ( V_5 , L_1 ,
F_5 ( & V_2 -> V_6 ) , V_4 ) ;
V_4 = 0 ;
}
if ( V_4 & ( 1 << 7 ) )
return V_4 ;
F_6 ( 3 ) ;
}
}
static int F_7 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_11 * V_12 = V_8 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_13 V_14 = { . V_15 = 0 , } ;
struct V_16 V_17 ;
unsigned V_18 = V_12 -> V_19 << 3 ;
T_1 * V_20 ;
T_2 V_21 ;
F_4 ( V_22 , L_2 ,
F_5 ( & V_2 -> V_6 ) , ( long long ) V_10 -> V_23 ,
( long long ) V_10 -> V_24 ) ;
if ( V_10 -> V_23 + V_10 -> V_24 > V_8 -> V_25 )
return - V_26 ;
F_8 ( V_10 -> V_24 , V_12 -> V_19 , & V_21 ) ;
if ( V_21 )
return - V_26 ;
F_8 ( V_10 -> V_23 , V_12 -> V_19 , & V_21 ) ;
if ( V_21 )
return - V_26 ;
F_9 ( & V_17 ) ;
V_14 . V_27 = V_20 = V_12 -> V_20 ;
V_14 . V_24 = 4 ;
F_10 ( & V_14 , & V_17 ) ;
F_11 ( & V_12 -> V_28 ) ;
while ( V_10 -> V_24 > 0 ) {
unsigned int V_29 ;
int V_4 ;
int V_30 ;
V_29 = F_12 ( V_10 -> V_23 , V_12 -> V_19 ) ;
V_30 = ( V_29 & 0x7 ) == 0 && V_10 -> V_24 >= V_18 ;
V_29 = V_29 << V_12 -> V_31 ;
V_20 [ 0 ] = V_30 ? V_32 : V_33 ;
V_20 [ 1 ] = ( T_1 ) ( V_29 >> 16 ) ;
V_20 [ 2 ] = ( T_1 ) ( V_29 >> 8 ) ;
V_20 [ 3 ] = 0 ;
F_4 ( V_34 , L_3 ,
V_30 ? L_4 : L_5 ,
V_20 [ 0 ] , V_20 [ 1 ] , V_20 [ 2 ] , V_20 [ 3 ] ,
V_29 ) ;
V_4 = F_13 ( V_2 , & V_17 ) ;
( void ) F_3 ( V_2 ) ;
if ( V_4 < 0 ) {
F_14 ( V_35 L_6 ,
F_5 ( & V_2 -> V_6 ) , V_29 , V_4 ) ;
continue;
}
if ( V_30 ) {
V_10 -> V_23 += V_18 ;
V_10 -> V_24 -= V_18 ;
} else {
V_10 -> V_23 += V_12 -> V_19 ;
V_10 -> V_24 -= V_12 -> V_19 ;
}
}
F_15 ( & V_12 -> V_28 ) ;
V_10 -> V_36 = V_37 ;
F_16 ( V_10 ) ;
return 0 ;
}
static int F_17 ( struct V_7 * V_8 , T_3 V_38 , T_4 V_24 ,
T_4 * V_39 , T_5 * V_40 )
{
struct V_11 * V_12 = V_8 -> V_12 ;
struct V_13 V_14 [ 2 ] = { { . V_15 = 0 , } , } ;
struct V_16 V_17 ;
unsigned int V_23 ;
T_1 * V_20 ;
int V_4 ;
F_4 ( V_22 , L_7 ,
F_5 ( & V_12 -> V_2 -> V_6 ) , ( unsigned ) V_38 , ( unsigned ) ( V_38 + V_24 ) ) ;
* V_39 = 0 ;
if ( ! V_24 )
return 0 ;
if ( V_38 + V_24 > V_8 -> V_25 )
return - V_26 ;
V_23 = ( ( ( unsigned ) V_38 / V_12 -> V_19 ) << V_12 -> V_31 )
+ ( ( unsigned ) V_38 % V_12 -> V_19 ) ;
V_20 = V_12 -> V_20 ;
F_4 ( V_34 , L_8 ,
V_20 [ 0 ] , V_20 [ 1 ] , V_20 [ 2 ] , V_20 [ 3 ] ) ;
F_9 ( & V_17 ) ;
V_14 [ 0 ] . V_27 = V_20 ;
V_14 [ 0 ] . V_24 = 8 ;
F_10 ( & V_14 [ 0 ] , & V_17 ) ;
V_14 [ 1 ] . V_41 = V_40 ;
V_14 [ 1 ] . V_24 = V_24 ;
F_10 ( & V_14 [ 1 ] , & V_17 ) ;
F_11 ( & V_12 -> V_28 ) ;
V_20 [ 0 ] = V_42 ;
V_20 [ 1 ] = ( T_1 ) ( V_23 >> 16 ) ;
V_20 [ 2 ] = ( T_1 ) ( V_23 >> 8 ) ;
V_20 [ 3 ] = ( T_1 ) ( V_23 >> 0 ) ;
V_4 = F_13 ( V_12 -> V_2 , & V_17 ) ;
F_15 ( & V_12 -> V_28 ) ;
if ( V_4 >= 0 ) {
* V_39 = V_17 . V_43 - 8 ;
V_4 = 0 ;
} else
F_4 ( V_5 , L_9 ,
F_5 ( & V_12 -> V_2 -> V_6 ) ,
( unsigned ) V_38 , ( unsigned ) ( V_38 + V_24 ) ,
V_4 ) ;
return V_4 ;
}
static int F_18 ( struct V_7 * V_8 , T_3 V_44 , T_4 V_24 ,
T_4 * V_39 , const T_5 * V_40 )
{
struct V_11 * V_12 = V_8 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_13 V_14 [ 2 ] = { { . V_15 = 0 , } , } ;
struct V_16 V_17 ;
unsigned int V_29 , V_23 , V_45 , V_46 ;
T_4 V_47 = V_24 ;
T_5 * V_48 = ( T_5 * ) V_40 ;
int V_4 = - V_26 ;
T_1 * V_20 ;
F_4 ( V_22 , L_10 ,
F_5 ( & V_2 -> V_6 ) , ( unsigned ) V_44 , ( unsigned ) ( V_44 + V_24 ) ) ;
* V_39 = 0 ;
if ( ! V_24 )
return 0 ;
if ( ( V_44 + V_24 ) > V_8 -> V_25 )
return - V_26 ;
F_9 ( & V_17 ) ;
V_14 [ 0 ] . V_27 = V_20 = V_12 -> V_20 ;
V_14 [ 0 ] . V_24 = 4 ;
F_10 ( & V_14 [ 0 ] , & V_17 ) ;
V_29 = ( ( unsigned ) V_44 / V_12 -> V_19 ) ;
V_45 = ( ( unsigned ) V_44 % V_12 -> V_19 ) ;
if ( V_45 + V_24 > V_12 -> V_19 )
V_46 = V_12 -> V_19 - V_45 ;
else
V_46 = V_24 ;
F_11 ( & V_12 -> V_28 ) ;
while ( V_47 > 0 ) {
F_4 ( V_34 , L_11 ,
V_29 , V_45 , V_46 ) ;
V_23 = V_29 << V_12 -> V_31 ;
if ( V_46 != V_12 -> V_19 ) {
V_20 [ 0 ] = V_49 ;
V_20 [ 1 ] = ( V_23 & 0x00FF0000 ) >> 16 ;
V_20 [ 2 ] = ( V_23 & 0x0000FF00 ) >> 8 ;
V_20 [ 3 ] = 0 ;
F_4 ( V_34 , L_12 ,
V_20 [ 0 ] , V_20 [ 1 ] , V_20 [ 2 ] , V_20 [ 3 ] ) ;
V_4 = F_13 ( V_2 , & V_17 ) ;
if ( V_4 < 0 )
F_4 ( V_5 , L_13 ,
F_5 ( & V_2 -> V_6 ) , V_23 , V_4 ) ;
( void ) F_3 ( V_12 -> V_2 ) ;
}
V_23 += V_45 ;
V_20 [ 0 ] = V_50 ;
V_20 [ 1 ] = ( V_23 & 0x00FF0000 ) >> 16 ;
V_20 [ 2 ] = ( V_23 & 0x0000FF00 ) >> 8 ;
V_20 [ 3 ] = ( V_23 & 0x000000FF ) ;
F_4 ( V_34 , L_14 ,
V_20 [ 0 ] , V_20 [ 1 ] , V_20 [ 2 ] , V_20 [ 3 ] ) ;
V_14 [ 1 ] . V_27 = V_48 ;
V_14 [ 1 ] . V_24 = V_46 ;
F_10 ( V_14 + 1 , & V_17 ) ;
V_4 = F_13 ( V_2 , & V_17 ) ;
F_19 ( V_14 + 1 ) ;
if ( V_4 < 0 )
F_4 ( V_5 , L_15 ,
F_5 ( & V_2 -> V_6 ) , V_23 , V_46 , V_4 ) ;
( void ) F_3 ( V_12 -> V_2 ) ;
#ifdef F_20
V_23 = V_29 << V_12 -> V_31 ;
V_20 [ 0 ] = V_51 ;
V_20 [ 1 ] = ( V_23 & 0x00FF0000 ) >> 16 ;
V_20 [ 2 ] = ( V_23 & 0x0000FF00 ) >> 8 ;
V_20 [ 3 ] = 0 ;
F_4 ( V_34 , L_16 ,
V_20 [ 0 ] , V_20 [ 1 ] , V_20 [ 2 ] , V_20 [ 3 ] ) ;
V_4 = F_13 ( V_2 , & V_17 ) ;
if ( V_4 < 0 )
F_4 ( V_5 , L_17 ,
F_5 ( & V_2 -> V_6 ) , V_23 , V_4 ) ;
V_4 = F_3 ( V_12 -> V_2 ) ;
if ( V_4 & ( 1 << 6 ) ) {
F_14 ( V_35 L_18 ,
F_5 ( & V_2 -> V_6 ) , V_29 , V_4 ) ;
V_47 = 0 ;
V_4 = - V_52 ;
break;
} else
V_4 = 0 ;
#endif
V_47 = V_47 - V_46 ;
V_29 ++ ;
V_45 = 0 ;
V_48 += V_46 ;
* V_39 += V_46 ;
if ( V_47 > V_12 -> V_19 )
V_46 = V_12 -> V_19 ;
else
V_46 = V_47 ;
}
F_15 ( & V_12 -> V_28 ) ;
return V_4 ;
}
static int F_21 ( struct V_7 * V_8 ,
struct V_53 * V_54 , T_4 V_24 )
{
V_54 -> V_55 = 0 ;
V_54 -> V_56 = 64 ;
V_54 -> V_57 = 1 ;
return sizeof( * V_54 ) ;
}
static T_6 F_22 ( struct V_1 * V_2 , unsigned V_58 ,
T_1 * V_40 , T_3 V_59 , T_4 V_24 )
{
struct V_16 V_60 ;
T_4 V_61 ;
T_1 * V_62 ;
struct V_13 V_63 ;
int V_4 ;
if ( V_59 > 64 )
return - V_26 ;
if ( ( V_59 + V_24 ) > 64 )
V_24 = 64 - V_59 ;
if ( V_24 == 0 )
return V_24 ;
F_9 ( & V_60 ) ;
V_61 = 4 + V_58 + V_59 + V_24 ;
V_62 = F_23 ( V_61 , V_64 ) ;
if ( ! V_62 )
return - V_65 ;
V_62 [ 0 ] = V_66 ;
memset ( & V_63 , 0 , sizeof V_63 ) ;
V_63 . V_27 = V_62 ;
V_63 . V_41 = V_62 ;
V_63 . V_24 = V_61 ;
F_10 ( & V_63 , & V_60 ) ;
F_3 ( V_2 ) ;
V_4 = F_13 ( V_2 , & V_60 ) ;
if ( V_4 >= 0 ) {
memcpy ( V_40 , V_62 + 4 + V_58 + V_59 , V_24 ) ;
V_4 = V_24 ;
}
F_24 ( V_62 ) ;
return V_4 ;
}
static int F_25 ( struct V_7 * V_8 ,
T_3 V_38 , T_4 V_24 , T_4 * V_39 , T_5 * V_40 )
{
struct V_11 * V_12 = V_8 -> V_12 ;
int V_4 ;
F_11 ( & V_12 -> V_28 ) ;
V_4 = F_22 ( V_12 -> V_2 , 64 , V_40 , V_38 , V_24 ) ;
F_15 ( & V_12 -> V_28 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_39 = V_4 ;
return 0 ;
}
static int F_26 ( struct V_7 * V_8 ,
T_3 V_38 , T_4 V_24 , T_4 * V_39 , T_5 * V_40 )
{
struct V_11 * V_12 = V_8 -> V_12 ;
int V_4 ;
F_11 ( & V_12 -> V_28 ) ;
V_4 = F_22 ( V_12 -> V_2 , 0 , V_40 , V_38 , V_24 ) ;
F_15 ( & V_12 -> V_28 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_39 = V_4 ;
return 0 ;
}
static int F_27 ( struct V_7 * V_8 ,
T_3 V_38 , T_4 V_24 , T_4 * V_39 , T_5 * V_40 )
{
struct V_16 V_60 ;
const T_4 V_61 = 4 + 64 ;
T_1 * V_62 ;
struct V_13 V_63 ;
struct V_11 * V_12 = V_8 -> V_12 ;
int V_4 ;
if ( V_24 > 64 )
return - V_26 ;
if ( ( V_38 + V_24 ) > 64 )
return - V_26 ;
V_62 = F_23 ( V_61 , V_64 ) ;
if ( ! V_62 )
return - V_65 ;
V_62 [ 0 ] = V_67 ;
memcpy ( V_62 + 4 + V_38 , V_40 , V_24 ) ;
F_9 ( & V_60 ) ;
memset ( & V_63 , 0 , sizeof V_63 ) ;
V_63 . V_27 = V_62 ;
V_63 . V_24 = V_61 ;
F_10 ( & V_63 , & V_60 ) ;
F_11 ( & V_12 -> V_28 ) ;
F_3 ( V_12 -> V_2 ) ;
V_4 = F_13 ( V_12 -> V_2 , & V_60 ) ;
F_15 ( & V_12 -> V_28 ) ;
F_24 ( V_62 ) ;
if ( V_4 >= 0 ) {
V_4 = 0 ;
* V_39 = V_24 ;
}
return V_4 ;
}
static char * F_28 ( struct V_7 * V_68 , char V_69 )
{
V_68 -> V_70 = F_21 ;
V_68 -> V_71 = F_25 ;
V_68 -> V_72 = F_21 ;
V_68 -> V_73 = F_26 ;
if ( V_69 > 'c' )
V_68 -> V_74 = F_27 ;
return L_19 ;
}
static char * F_28 ( struct V_7 * V_68 , char V_69 )
{
return L_20 ;
}
static int T_7
F_29 ( struct V_1 * V_2 , char * V_75 ,
int V_76 , int V_77 , int V_78 , char V_69 )
{
struct V_11 * V_12 ;
struct V_7 * V_68 ;
struct V_79 * V_80 = V_2 -> V_6 . V_81 ;
char * V_82 = L_21 ;
int V_83 = 0 ;
struct V_84 * V_85 ;
int V_86 = 0 ;
V_12 = F_23 ( sizeof *V_12 , V_64 ) ;
if ( ! V_12 )
return - V_65 ;
F_30 ( & V_12 -> V_28 ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_19 = V_77 ;
V_12 -> V_31 = V_78 ;
sprintf ( V_12 -> V_75 , L_22 ,
V_2 -> V_87 -> V_88 , V_2 -> V_89 ,
V_75 ) ;
V_68 = & V_12 -> V_8 ;
V_68 -> V_75 = ( V_80 && V_80 -> V_75 ) ? V_80 -> V_75 : V_12 -> V_75 ;
V_68 -> V_25 = V_76 * V_77 ;
V_68 -> V_90 = V_77 ;
V_68 -> V_91 = V_77 ;
V_68 -> V_92 = V_93 ;
V_68 -> type = V_94 ;
V_68 -> V_95 = V_96 ;
V_68 -> V_97 = F_7 ;
V_68 -> V_98 = F_17 ;
V_68 -> V_99 = F_18 ;
V_68 -> V_12 = V_12 ;
V_68 -> V_6 . V_100 = & V_2 -> V_6 ;
if ( V_69 >= 'c' )
V_82 = F_28 ( V_68 , V_69 ) ;
F_31 ( & V_2 -> V_6 , L_23 ,
V_75 , ( long long ) ( ( V_68 -> V_25 + 1023 ) >> 10 ) ,
V_77 , V_82 ) ;
F_32 ( & V_2 -> V_6 , V_12 ) ;
if ( F_33 () ) {
static const char * V_101 [] = { L_24 , NULL , } ;
V_86 = F_34 ( V_68 , V_101 , & V_85 ,
0 ) ;
}
if ( V_86 <= 0 && V_80 && V_80 -> V_85 ) {
V_85 = V_80 -> V_85 ;
V_86 = V_80 -> V_86 ;
}
if ( V_86 > 0 ) {
V_12 -> V_102 = 1 ;
V_83 = F_35 ( V_68 , V_85 , V_86 ) ;
goto V_103;
}
if ( F_35 ( V_68 , NULL , 0 ) == 1 )
V_83 = - V_104 ;
V_103:
if ( ! V_83 )
return 0 ;
F_32 ( & V_2 -> V_6 , NULL ) ;
F_24 ( V_12 ) ;
return V_83 ;
}
static inline int T_7
F_36 ( struct V_1 * V_2 , char * V_75 ,
int V_76 , int V_77 , int V_78 )
{
return F_29 ( V_2 , V_75 , V_76 , V_77 ,
V_78 , 0 ) ;
}
static struct V_105 * T_7 F_37 ( struct V_1 * V_2 )
{
int V_106 ;
T_1 V_107 = V_108 ;
T_1 V_109 [ 3 ] ;
T_2 V_110 ;
struct V_105 * V_54 ;
int V_4 ;
V_106 = F_38 ( V_2 , & V_107 , 1 , V_109 , 3 ) ;
if ( V_106 < 0 ) {
F_4 ( V_111 , L_25 ,
F_5 ( & V_2 -> V_6 ) , V_106 ) ;
return F_39 ( V_106 ) ;
}
if ( V_109 [ 0 ] != 0x1f )
return NULL ;
V_110 = V_109 [ 0 ] ;
V_110 = V_110 << 8 ;
V_110 |= V_109 [ 1 ] ;
V_110 = V_110 << 8 ;
V_110 |= V_109 [ 2 ] ;
for ( V_106 = 0 , V_54 = V_112 ;
V_106 < F_40 ( V_112 ) ;
V_106 ++ , V_54 ++ ) {
if ( V_54 -> V_113 == V_110 ) {
F_4 ( V_5 , L_26 ,
F_5 ( & V_2 -> V_6 ) ,
( V_54 -> V_95 & V_114 )
? L_27 : L_21
) ;
if ( V_54 -> V_95 & V_114 ) {
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 ) {
F_4 ( V_5 ,
L_28 ,
F_5 ( & V_2 -> V_6 ) , V_4 ) ;
return F_39 ( V_4 ) ;
}
if ( V_4 & 0x1 ) {
if ( V_54 -> V_95 & V_115 )
return V_54 ;
} else {
if ( ! ( V_54 -> V_95 & V_115 ) )
return V_54 ;
}
} else
return V_54 ;
}
}
F_41 ( & V_2 -> V_6 , L_29 , V_110 ) ;
return F_39 ( - V_104 ) ;
}
static int T_7 F_42 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_105 * V_54 ;
V_54 = F_37 ( V_2 ) ;
if ( F_43 ( V_54 ) )
return F_44 ( V_54 ) ;
if ( V_54 != NULL )
return F_29 ( V_2 , V_54 -> V_75 , V_54 -> V_76 ,
V_54 -> V_77 , V_54 -> V_78 ,
( V_54 -> V_95 & V_114 ) ? 'd' : 'c' ) ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 <= 0 || V_4 == 0xff ) {
F_4 ( V_5 , L_28 ,
F_5 ( & V_2 -> V_6 ) , V_4 ) ;
if ( V_4 == 0 || V_4 == 0xff )
V_4 = - V_104 ;
return V_4 ;
}
switch ( V_4 & 0x3c ) {
case 0x0c :
V_4 = F_36 ( V_2 , L_30 , 512 , 264 , 9 ) ;
break;
case 0x14 :
V_4 = F_36 ( V_2 , L_31 , 1024 , 264 , 9 ) ;
break;
case 0x1c :
V_4 = F_36 ( V_2 , L_32 , 2048 , 264 , 9 ) ;
break;
case 0x24 :
V_4 = F_36 ( V_2 , L_33 , 4096 , 264 , 9 ) ;
break;
case 0x2c :
V_4 = F_36 ( V_2 , L_34 , 4096 , 528 , 10 ) ;
break;
case 0x34 :
V_4 = F_36 ( V_2 , L_35 , 8192 , 528 , 10 ) ;
break;
case 0x38 :
case 0x3c :
V_4 = F_36 ( V_2 , L_36 , 8192 , 1056 , 11 ) ;
break;
default:
F_4 ( V_5 , L_37 ,
F_5 ( & V_2 -> V_6 ) , V_4 & 0x3c ) ;
V_4 = - V_104 ;
}
if ( V_4 < 0 )
F_4 ( V_5 , L_38 ,
F_5 ( & V_2 -> V_6 ) , V_4 ) ;
return V_4 ;
}
static int T_8 F_45 ( struct V_1 * V_2 )
{
struct V_11 * V_116 = F_46 ( & V_2 -> V_6 ) ;
int V_4 ;
F_4 ( V_5 , L_39 , F_5 ( & V_2 -> V_6 ) ) ;
V_4 = F_47 ( & V_116 -> V_8 ) ;
if ( V_4 == 0 ) {
F_32 ( & V_2 -> V_6 , NULL ) ;
F_24 ( V_116 ) ;
}
return V_4 ;
}
static int T_9 F_48 ( void )
{
return F_49 ( & V_117 ) ;
}
static void T_10 F_50 ( void )
{
F_51 ( & V_117 ) ;
}
