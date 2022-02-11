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
F_4 ( L_1 ,
F_5 ( & V_2 -> V_5 ) , V_4 ) ;
V_4 = 0 ;
}
if ( V_4 & ( 1 << 7 ) )
return V_4 ;
F_6 ( 3 ) ;
}
}
static int F_7 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_12 V_13 = { . V_14 = 0 , } ;
struct V_15 V_16 ;
unsigned V_17 = V_11 -> V_18 << 3 ;
T_1 * V_19 ;
T_2 V_20 ;
F_4 ( L_2 ,
F_5 ( & V_2 -> V_5 ) , ( long long ) V_9 -> V_21 ,
( long long ) V_9 -> V_22 ) ;
if ( V_9 -> V_21 + V_9 -> V_22 > V_7 -> V_23 )
return - V_24 ;
F_8 ( V_9 -> V_22 , V_11 -> V_18 , & V_20 ) ;
if ( V_20 )
return - V_24 ;
F_8 ( V_9 -> V_21 , V_11 -> V_18 , & V_20 ) ;
if ( V_20 )
return - V_24 ;
F_9 ( & V_16 ) ;
V_13 . V_25 = V_19 = V_11 -> V_19 ;
V_13 . V_22 = 4 ;
F_10 ( & V_13 , & V_16 ) ;
F_11 ( & V_11 -> V_26 ) ;
while ( V_9 -> V_22 > 0 ) {
unsigned int V_27 ;
int V_4 ;
int V_28 ;
V_27 = F_12 ( V_9 -> V_21 , V_11 -> V_18 ) ;
V_28 = ( V_27 & 0x7 ) == 0 && V_9 -> V_22 >= V_17 ;
V_27 = V_27 << V_11 -> V_29 ;
V_19 [ 0 ] = V_28 ? V_30 : V_31 ;
V_19 [ 1 ] = ( T_1 ) ( V_27 >> 16 ) ;
V_19 [ 2 ] = ( T_1 ) ( V_27 >> 8 ) ;
V_19 [ 3 ] = 0 ;
F_4 ( L_3 ,
V_28 ? L_4 : L_5 ,
V_19 [ 0 ] , V_19 [ 1 ] , V_19 [ 2 ] , V_19 [ 3 ] ,
V_27 ) ;
V_4 = F_13 ( V_2 , & V_16 ) ;
( void ) F_3 ( V_2 ) ;
if ( V_4 < 0 ) {
F_14 ( V_32 L_6 ,
F_5 ( & V_2 -> V_5 ) , V_27 , V_4 ) ;
continue;
}
if ( V_28 ) {
V_9 -> V_21 += V_17 ;
V_9 -> V_22 -= V_17 ;
} else {
V_9 -> V_21 += V_11 -> V_18 ;
V_9 -> V_22 -= V_11 -> V_18 ;
}
}
F_15 ( & V_11 -> V_26 ) ;
V_9 -> V_33 = V_34 ;
F_16 ( V_9 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , T_3 V_35 , T_4 V_22 ,
T_4 * V_36 , T_5 * V_37 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 V_13 [ 2 ] = { { . V_14 = 0 , } , } ;
struct V_15 V_16 ;
unsigned int V_21 ;
T_1 * V_19 ;
int V_4 ;
F_4 ( L_7 , F_5 ( & V_11 -> V_2 -> V_5 ) ,
( unsigned ) V_35 , ( unsigned ) ( V_35 + V_22 ) ) ;
* V_36 = 0 ;
if ( ! V_22 )
return 0 ;
if ( V_35 + V_22 > V_7 -> V_23 )
return - V_24 ;
V_21 = ( ( ( unsigned ) V_35 / V_11 -> V_18 ) << V_11 -> V_29 )
+ ( ( unsigned ) V_35 % V_11 -> V_18 ) ;
V_19 = V_11 -> V_19 ;
F_4 ( L_8 ,
V_19 [ 0 ] , V_19 [ 1 ] , V_19 [ 2 ] , V_19 [ 3 ] ) ;
F_9 ( & V_16 ) ;
V_13 [ 0 ] . V_25 = V_19 ;
V_13 [ 0 ] . V_22 = 8 ;
F_10 ( & V_13 [ 0 ] , & V_16 ) ;
V_13 [ 1 ] . V_38 = V_37 ;
V_13 [ 1 ] . V_22 = V_22 ;
F_10 ( & V_13 [ 1 ] , & V_16 ) ;
F_11 ( & V_11 -> V_26 ) ;
V_19 [ 0 ] = V_39 ;
V_19 [ 1 ] = ( T_1 ) ( V_21 >> 16 ) ;
V_19 [ 2 ] = ( T_1 ) ( V_21 >> 8 ) ;
V_19 [ 3 ] = ( T_1 ) ( V_21 >> 0 ) ;
V_4 = F_13 ( V_11 -> V_2 , & V_16 ) ;
F_15 ( & V_11 -> V_26 ) ;
if ( V_4 >= 0 ) {
* V_36 = V_16 . V_40 - 8 ;
V_4 = 0 ;
} else
F_4 ( L_9 ,
F_5 ( & V_11 -> V_2 -> V_5 ) ,
( unsigned ) V_35 , ( unsigned ) ( V_35 + V_22 ) ,
V_4 ) ;
return V_4 ;
}
static int F_18 ( struct V_6 * V_7 , T_3 V_41 , T_4 V_22 ,
T_4 * V_36 , const T_5 * V_37 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_12 V_13 [ 2 ] = { { . V_14 = 0 , } , } ;
struct V_15 V_16 ;
unsigned int V_27 , V_21 , V_42 , V_43 ;
T_4 V_44 = V_22 ;
T_5 * V_45 = ( T_5 * ) V_37 ;
int V_4 = - V_24 ;
T_1 * V_19 ;
F_4 ( L_10 ,
F_5 ( & V_2 -> V_5 ) , ( unsigned ) V_41 , ( unsigned ) ( V_41 + V_22 ) ) ;
* V_36 = 0 ;
if ( ! V_22 )
return 0 ;
if ( ( V_41 + V_22 ) > V_7 -> V_23 )
return - V_24 ;
F_9 ( & V_16 ) ;
V_13 [ 0 ] . V_25 = V_19 = V_11 -> V_19 ;
V_13 [ 0 ] . V_22 = 4 ;
F_10 ( & V_13 [ 0 ] , & V_16 ) ;
V_27 = ( ( unsigned ) V_41 / V_11 -> V_18 ) ;
V_42 = ( ( unsigned ) V_41 % V_11 -> V_18 ) ;
if ( V_42 + V_22 > V_11 -> V_18 )
V_43 = V_11 -> V_18 - V_42 ;
else
V_43 = V_22 ;
F_11 ( & V_11 -> V_26 ) ;
while ( V_44 > 0 ) {
F_4 ( L_11 ,
V_27 , V_42 , V_43 ) ;
V_21 = V_27 << V_11 -> V_29 ;
if ( V_43 != V_11 -> V_18 ) {
V_19 [ 0 ] = V_46 ;
V_19 [ 1 ] = ( V_21 & 0x00FF0000 ) >> 16 ;
V_19 [ 2 ] = ( V_21 & 0x0000FF00 ) >> 8 ;
V_19 [ 3 ] = 0 ;
F_4 ( L_12 ,
V_19 [ 0 ] , V_19 [ 1 ] , V_19 [ 2 ] , V_19 [ 3 ] ) ;
V_4 = F_13 ( V_2 , & V_16 ) ;
if ( V_4 < 0 )
F_4 ( L_13 ,
F_5 ( & V_2 -> V_5 ) , V_21 , V_4 ) ;
( void ) F_3 ( V_11 -> V_2 ) ;
}
V_21 += V_42 ;
V_19 [ 0 ] = V_47 ;
V_19 [ 1 ] = ( V_21 & 0x00FF0000 ) >> 16 ;
V_19 [ 2 ] = ( V_21 & 0x0000FF00 ) >> 8 ;
V_19 [ 3 ] = ( V_21 & 0x000000FF ) ;
F_4 ( L_14 ,
V_19 [ 0 ] , V_19 [ 1 ] , V_19 [ 2 ] , V_19 [ 3 ] ) ;
V_13 [ 1 ] . V_25 = V_45 ;
V_13 [ 1 ] . V_22 = V_43 ;
F_10 ( V_13 + 1 , & V_16 ) ;
V_4 = F_13 ( V_2 , & V_16 ) ;
F_19 ( V_13 + 1 ) ;
if ( V_4 < 0 )
F_4 ( L_15 ,
F_5 ( & V_2 -> V_5 ) , V_21 , V_43 , V_4 ) ;
( void ) F_3 ( V_11 -> V_2 ) ;
#ifdef F_20
V_21 = V_27 << V_11 -> V_29 ;
V_19 [ 0 ] = V_48 ;
V_19 [ 1 ] = ( V_21 & 0x00FF0000 ) >> 16 ;
V_19 [ 2 ] = ( V_21 & 0x0000FF00 ) >> 8 ;
V_19 [ 3 ] = 0 ;
F_4 ( L_16 ,
V_19 [ 0 ] , V_19 [ 1 ] , V_19 [ 2 ] , V_19 [ 3 ] ) ;
V_4 = F_13 ( V_2 , & V_16 ) ;
if ( V_4 < 0 )
F_4 ( L_17 ,
F_5 ( & V_2 -> V_5 ) , V_21 , V_4 ) ;
V_4 = F_3 ( V_11 -> V_2 ) ;
if ( V_4 & ( 1 << 6 ) ) {
F_14 ( V_32 L_18 ,
F_5 ( & V_2 -> V_5 ) , V_27 , V_4 ) ;
V_44 = 0 ;
V_4 = - V_49 ;
break;
} else
V_4 = 0 ;
#endif
V_44 = V_44 - V_43 ;
V_27 ++ ;
V_42 = 0 ;
V_45 += V_43 ;
* V_36 += V_43 ;
if ( V_44 > V_11 -> V_18 )
V_43 = V_11 -> V_18 ;
else
V_43 = V_44 ;
}
F_15 ( & V_11 -> V_26 ) ;
return V_4 ;
}
static int F_21 ( struct V_6 * V_7 ,
struct V_50 * V_51 , T_4 V_22 )
{
V_51 -> V_52 = 0 ;
V_51 -> V_53 = 64 ;
V_51 -> V_54 = 1 ;
return sizeof( * V_51 ) ;
}
static T_6 F_22 ( struct V_1 * V_2 , unsigned V_55 ,
T_1 * V_37 , T_3 V_56 , T_4 V_22 )
{
struct V_15 V_57 ;
T_4 V_58 ;
T_1 * V_59 ;
struct V_12 V_60 ;
int V_4 ;
if ( V_56 > 64 )
return - V_24 ;
if ( ( V_56 + V_22 ) > 64 )
V_22 = 64 - V_56 ;
if ( V_22 == 0 )
return V_22 ;
F_9 ( & V_57 ) ;
V_58 = 4 + V_55 + V_56 + V_22 ;
V_59 = F_23 ( V_58 , V_61 ) ;
if ( ! V_59 )
return - V_62 ;
V_59 [ 0 ] = V_63 ;
memset ( & V_60 , 0 , sizeof V_60 ) ;
V_60 . V_25 = V_59 ;
V_60 . V_38 = V_59 ;
V_60 . V_22 = V_58 ;
F_10 ( & V_60 , & V_57 ) ;
F_3 ( V_2 ) ;
V_4 = F_13 ( V_2 , & V_57 ) ;
if ( V_4 >= 0 ) {
memcpy ( V_37 , V_59 + 4 + V_55 + V_56 , V_22 ) ;
V_4 = V_22 ;
}
F_24 ( V_59 ) ;
return V_4 ;
}
static int F_25 ( struct V_6 * V_7 ,
T_3 V_35 , T_4 V_22 , T_4 * V_36 , T_5 * V_37 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
int V_4 ;
F_11 ( & V_11 -> V_26 ) ;
V_4 = F_22 ( V_11 -> V_2 , 64 , V_37 , V_35 , V_22 ) ;
F_15 ( & V_11 -> V_26 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_36 = V_4 ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 ,
T_3 V_35 , T_4 V_22 , T_4 * V_36 , T_5 * V_37 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
int V_4 ;
F_11 ( & V_11 -> V_26 ) ;
V_4 = F_22 ( V_11 -> V_2 , 0 , V_37 , V_35 , V_22 ) ;
F_15 ( & V_11 -> V_26 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_36 = V_4 ;
return 0 ;
}
static int F_27 ( struct V_6 * V_7 ,
T_3 V_35 , T_4 V_22 , T_4 * V_36 , T_5 * V_37 )
{
struct V_15 V_57 ;
const T_4 V_58 = 4 + 64 ;
T_1 * V_59 ;
struct V_12 V_60 ;
struct V_10 * V_11 = V_7 -> V_11 ;
int V_4 ;
if ( V_22 > 64 )
return - V_24 ;
if ( ( V_35 + V_22 ) > 64 )
return - V_24 ;
V_59 = F_23 ( V_58 , V_61 ) ;
if ( ! V_59 )
return - V_62 ;
V_59 [ 0 ] = V_64 ;
memcpy ( V_59 + 4 + V_35 , V_37 , V_22 ) ;
F_9 ( & V_57 ) ;
memset ( & V_60 , 0 , sizeof V_60 ) ;
V_60 . V_25 = V_59 ;
V_60 . V_22 = V_58 ;
F_10 ( & V_60 , & V_57 ) ;
F_11 ( & V_11 -> V_26 ) ;
F_3 ( V_11 -> V_2 ) ;
V_4 = F_13 ( V_11 -> V_2 , & V_57 ) ;
F_15 ( & V_11 -> V_26 ) ;
F_24 ( V_59 ) ;
if ( V_4 >= 0 ) {
V_4 = 0 ;
* V_36 = V_22 ;
}
return V_4 ;
}
static char * F_28 ( struct V_6 * V_65 , char V_66 )
{
V_65 -> V_67 = F_21 ;
V_65 -> V_68 = F_25 ;
V_65 -> V_69 = F_21 ;
V_65 -> V_70 = F_26 ;
if ( V_66 > 'c' )
V_65 -> V_71 = F_27 ;
return L_19 ;
}
static char * F_28 ( struct V_6 * V_65 , char V_66 )
{
return L_20 ;
}
static int T_7
F_29 ( struct V_1 * V_2 , char * V_72 ,
int V_73 , int V_74 , int V_75 , char V_66 )
{
struct V_10 * V_11 ;
struct V_6 * V_65 ;
struct V_76 V_77 ;
struct V_78 * V_79 = V_2 -> V_5 . V_80 ;
char * V_81 = L_21 ;
int V_82 = 0 ;
V_11 = F_23 ( sizeof *V_11 , V_61 ) ;
if ( ! V_11 )
return - V_62 ;
F_30 ( & V_11 -> V_26 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_18 = V_74 ;
V_11 -> V_29 = V_75 ;
sprintf ( V_11 -> V_72 , L_22 ,
V_2 -> V_83 -> V_84 , V_2 -> V_85 ,
V_72 ) ;
V_65 = & V_11 -> V_7 ;
V_65 -> V_72 = ( V_79 && V_79 -> V_72 ) ? V_79 -> V_72 : V_11 -> V_72 ;
V_65 -> V_23 = V_73 * V_74 ;
V_65 -> V_86 = V_74 ;
V_65 -> V_87 = V_74 ;
V_65 -> V_88 = V_89 ;
V_65 -> type = V_90 ;
V_65 -> V_91 = V_92 ;
V_65 -> V_93 = F_7 ;
V_65 -> V_94 = F_17 ;
V_65 -> V_95 = F_18 ;
V_65 -> V_11 = V_11 ;
V_65 -> V_5 . V_96 = & V_2 -> V_5 ;
if ( V_66 >= 'c' )
V_81 = F_28 ( V_65 , V_66 ) ;
F_31 ( & V_2 -> V_5 , L_23 ,
V_72 , ( long long ) ( ( V_65 -> V_23 + 1023 ) >> 10 ) ,
V_74 , V_81 ) ;
F_32 ( & V_2 -> V_5 , V_11 ) ;
V_77 . V_97 = V_2 -> V_5 . V_97 ;
V_82 = F_33 ( V_65 , NULL , & V_77 ,
V_79 ? V_79 -> V_98 : NULL ,
V_79 ? V_79 -> V_99 : 0 ) ;
if ( ! V_82 )
return 0 ;
F_32 ( & V_2 -> V_5 , NULL ) ;
F_24 ( V_11 ) ;
return V_82 ;
}
static inline int T_7
F_34 ( struct V_1 * V_2 , char * V_72 ,
int V_73 , int V_74 , int V_75 )
{
return F_29 ( V_2 , V_72 , V_73 , V_74 ,
V_75 , 0 ) ;
}
static struct V_100 * T_7 F_35 ( struct V_1 * V_2 )
{
int V_101 ;
T_1 V_102 = V_103 ;
T_1 V_104 [ 3 ] ;
T_2 V_105 ;
struct V_100 * V_51 ;
int V_4 ;
V_101 = F_36 ( V_2 , & V_102 , 1 , V_104 , 3 ) ;
if ( V_101 < 0 ) {
F_4 ( L_24 ,
F_5 ( & V_2 -> V_5 ) , V_101 ) ;
return F_37 ( V_101 ) ;
}
if ( V_104 [ 0 ] != 0x1f )
return NULL ;
V_105 = V_104 [ 0 ] ;
V_105 = V_105 << 8 ;
V_105 |= V_104 [ 1 ] ;
V_105 = V_105 << 8 ;
V_105 |= V_104 [ 2 ] ;
for ( V_101 = 0 , V_51 = V_106 ;
V_101 < F_38 ( V_106 ) ;
V_101 ++ , V_51 ++ ) {
if ( V_51 -> V_107 == V_105 ) {
F_4 ( L_25 ,
F_5 ( & V_2 -> V_5 ) ,
( V_51 -> V_91 & V_108 )
? L_26 : L_21
) ;
if ( V_51 -> V_91 & V_108 ) {
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 ) {
F_4 ( L_27 ,
F_5 ( & V_2 -> V_5 ) , V_4 ) ;
return F_37 ( V_4 ) ;
}
if ( V_4 & 0x1 ) {
if ( V_51 -> V_91 & V_109 )
return V_51 ;
} else {
if ( ! ( V_51 -> V_91 & V_109 ) )
return V_51 ;
}
} else
return V_51 ;
}
}
F_39 ( & V_2 -> V_5 , L_28 , V_105 ) ;
return F_37 ( - V_110 ) ;
}
static int T_7 F_40 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_100 * V_51 ;
V_51 = F_35 ( V_2 ) ;
if ( F_41 ( V_51 ) )
return F_42 ( V_51 ) ;
if ( V_51 != NULL )
return F_29 ( V_2 , V_51 -> V_72 , V_51 -> V_73 ,
V_51 -> V_74 , V_51 -> V_75 ,
( V_51 -> V_91 & V_108 ) ? 'd' : 'c' ) ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 <= 0 || V_4 == 0xff ) {
F_4 ( L_27 ,
F_5 ( & V_2 -> V_5 ) , V_4 ) ;
if ( V_4 == 0 || V_4 == 0xff )
V_4 = - V_110 ;
return V_4 ;
}
switch ( V_4 & 0x3c ) {
case 0x0c :
V_4 = F_34 ( V_2 , L_29 , 512 , 264 , 9 ) ;
break;
case 0x14 :
V_4 = F_34 ( V_2 , L_30 , 1024 , 264 , 9 ) ;
break;
case 0x1c :
V_4 = F_34 ( V_2 , L_31 , 2048 , 264 , 9 ) ;
break;
case 0x24 :
V_4 = F_34 ( V_2 , L_32 , 4096 , 264 , 9 ) ;
break;
case 0x2c :
V_4 = F_34 ( V_2 , L_33 , 4096 , 528 , 10 ) ;
break;
case 0x34 :
V_4 = F_34 ( V_2 , L_34 , 8192 , 528 , 10 ) ;
break;
case 0x38 :
case 0x3c :
V_4 = F_34 ( V_2 , L_35 , 8192 , 1056 , 11 ) ;
break;
default:
F_4 ( L_36 , F_5 ( & V_2 -> V_5 ) ,
V_4 & 0x3c ) ;
V_4 = - V_110 ;
}
if ( V_4 < 0 )
F_4 ( L_37 , F_5 ( & V_2 -> V_5 ) ,
V_4 ) ;
return V_4 ;
}
static int T_8 F_43 ( struct V_1 * V_2 )
{
struct V_10 * V_111 = F_44 ( & V_2 -> V_5 ) ;
int V_4 ;
F_4 ( L_38 , F_5 ( & V_2 -> V_5 ) ) ;
V_4 = F_45 ( & V_111 -> V_7 ) ;
if ( V_4 == 0 ) {
F_32 ( & V_2 -> V_5 , NULL ) ;
F_24 ( V_111 ) ;
}
return V_4 ;
}
static int T_9 F_46 ( void )
{
return F_47 ( & V_112 ) ;
}
static void T_10 F_48 ( void )
{
F_49 ( & V_112 ) ;
}
