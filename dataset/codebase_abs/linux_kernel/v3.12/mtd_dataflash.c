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
F_8 ( V_9 -> V_22 , V_11 -> V_18 , & V_20 ) ;
if ( V_20 )
return - V_23 ;
F_8 ( V_9 -> V_21 , V_11 -> V_18 , & V_20 ) ;
if ( V_20 )
return - V_23 ;
F_9 ( & V_16 ) ;
V_13 . V_24 = V_19 = V_11 -> V_19 ;
V_13 . V_22 = 4 ;
F_10 ( & V_13 , & V_16 ) ;
F_11 ( & V_11 -> V_25 ) ;
while ( V_9 -> V_22 > 0 ) {
unsigned int V_26 ;
int V_4 ;
int V_27 ;
V_26 = F_12 ( V_9 -> V_21 , V_11 -> V_18 ) ;
V_27 = ( V_26 & 0x7 ) == 0 && V_9 -> V_22 >= V_17 ;
V_26 = V_26 << V_11 -> V_28 ;
V_19 [ 0 ] = V_27 ? V_29 : V_30 ;
V_19 [ 1 ] = ( T_1 ) ( V_26 >> 16 ) ;
V_19 [ 2 ] = ( T_1 ) ( V_26 >> 8 ) ;
V_19 [ 3 ] = 0 ;
F_4 ( L_3 ,
V_27 ? L_4 : L_5 ,
V_19 [ 0 ] , V_19 [ 1 ] , V_19 [ 2 ] , V_19 [ 3 ] ,
V_26 ) ;
V_4 = F_13 ( V_2 , & V_16 ) ;
( void ) F_3 ( V_2 ) ;
if ( V_4 < 0 ) {
F_14 ( V_31 L_6 ,
F_5 ( & V_2 -> V_5 ) , V_26 , V_4 ) ;
continue;
}
if ( V_27 ) {
V_9 -> V_21 += V_17 ;
V_9 -> V_22 -= V_17 ;
} else {
V_9 -> V_21 += V_11 -> V_18 ;
V_9 -> V_22 -= V_11 -> V_18 ;
}
}
F_15 ( & V_11 -> V_25 ) ;
V_9 -> V_32 = V_33 ;
F_16 ( V_9 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , T_3 V_34 , T_4 V_22 ,
T_4 * V_35 , T_5 * V_36 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 V_13 [ 2 ] = { { . V_14 = 0 , } , } ;
struct V_15 V_16 ;
unsigned int V_21 ;
T_1 * V_19 ;
int V_4 ;
F_4 ( L_7 , F_5 ( & V_11 -> V_2 -> V_5 ) ,
( unsigned ) V_34 , ( unsigned ) ( V_34 + V_22 ) ) ;
V_21 = ( ( ( unsigned ) V_34 / V_11 -> V_18 ) << V_11 -> V_28 )
+ ( ( unsigned ) V_34 % V_11 -> V_18 ) ;
V_19 = V_11 -> V_19 ;
F_4 ( L_8 ,
V_19 [ 0 ] , V_19 [ 1 ] , V_19 [ 2 ] , V_19 [ 3 ] ) ;
F_9 ( & V_16 ) ;
V_13 [ 0 ] . V_24 = V_19 ;
V_13 [ 0 ] . V_22 = 8 ;
F_10 ( & V_13 [ 0 ] , & V_16 ) ;
V_13 [ 1 ] . V_37 = V_36 ;
V_13 [ 1 ] . V_22 = V_22 ;
F_10 ( & V_13 [ 1 ] , & V_16 ) ;
F_11 ( & V_11 -> V_25 ) ;
V_19 [ 0 ] = V_38 ;
V_19 [ 1 ] = ( T_1 ) ( V_21 >> 16 ) ;
V_19 [ 2 ] = ( T_1 ) ( V_21 >> 8 ) ;
V_19 [ 3 ] = ( T_1 ) ( V_21 >> 0 ) ;
V_4 = F_13 ( V_11 -> V_2 , & V_16 ) ;
F_15 ( & V_11 -> V_25 ) ;
if ( V_4 >= 0 ) {
* V_35 = V_16 . V_39 - 8 ;
V_4 = 0 ;
} else
F_4 ( L_9 ,
F_5 ( & V_11 -> V_2 -> V_5 ) ,
( unsigned ) V_34 , ( unsigned ) ( V_34 + V_22 ) ,
V_4 ) ;
return V_4 ;
}
static int F_18 ( struct V_6 * V_7 , T_3 V_40 , T_4 V_22 ,
T_4 * V_35 , const T_5 * V_36 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_12 V_13 [ 2 ] = { { . V_14 = 0 , } , } ;
struct V_15 V_16 ;
unsigned int V_26 , V_21 , V_41 , V_42 ;
T_4 V_43 = V_22 ;
T_5 * V_44 = ( T_5 * ) V_36 ;
int V_4 = - V_23 ;
T_1 * V_19 ;
F_4 ( L_10 ,
F_5 ( & V_2 -> V_5 ) , ( unsigned ) V_40 , ( unsigned ) ( V_40 + V_22 ) ) ;
F_9 ( & V_16 ) ;
V_13 [ 0 ] . V_24 = V_19 = V_11 -> V_19 ;
V_13 [ 0 ] . V_22 = 4 ;
F_10 ( & V_13 [ 0 ] , & V_16 ) ;
V_26 = ( ( unsigned ) V_40 / V_11 -> V_18 ) ;
V_41 = ( ( unsigned ) V_40 % V_11 -> V_18 ) ;
if ( V_41 + V_22 > V_11 -> V_18 )
V_42 = V_11 -> V_18 - V_41 ;
else
V_42 = V_22 ;
F_11 ( & V_11 -> V_25 ) ;
while ( V_43 > 0 ) {
F_4 ( L_11 ,
V_26 , V_41 , V_42 ) ;
V_21 = V_26 << V_11 -> V_28 ;
if ( V_42 != V_11 -> V_18 ) {
V_19 [ 0 ] = V_45 ;
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
V_21 += V_41 ;
V_19 [ 0 ] = V_46 ;
V_19 [ 1 ] = ( V_21 & 0x00FF0000 ) >> 16 ;
V_19 [ 2 ] = ( V_21 & 0x0000FF00 ) >> 8 ;
V_19 [ 3 ] = ( V_21 & 0x000000FF ) ;
F_4 ( L_14 ,
V_19 [ 0 ] , V_19 [ 1 ] , V_19 [ 2 ] , V_19 [ 3 ] ) ;
V_13 [ 1 ] . V_24 = V_44 ;
V_13 [ 1 ] . V_22 = V_42 ;
F_10 ( V_13 + 1 , & V_16 ) ;
V_4 = F_13 ( V_2 , & V_16 ) ;
F_19 ( V_13 + 1 ) ;
if ( V_4 < 0 )
F_4 ( L_15 ,
F_5 ( & V_2 -> V_5 ) , V_21 , V_42 , V_4 ) ;
( void ) F_3 ( V_11 -> V_2 ) ;
#ifdef F_20
V_21 = V_26 << V_11 -> V_28 ;
V_19 [ 0 ] = V_47 ;
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
F_14 ( V_31 L_18 ,
F_5 ( & V_2 -> V_5 ) , V_26 , V_4 ) ;
V_43 = 0 ;
V_4 = - V_48 ;
break;
} else
V_4 = 0 ;
#endif
V_43 = V_43 - V_42 ;
V_26 ++ ;
V_41 = 0 ;
V_44 += V_42 ;
* V_35 += V_42 ;
if ( V_43 > V_11 -> V_18 )
V_42 = V_11 -> V_18 ;
else
V_42 = V_43 ;
}
F_15 ( & V_11 -> V_25 ) ;
return V_4 ;
}
static int F_21 ( struct V_6 * V_7 ,
struct V_49 * V_50 , T_4 V_22 )
{
V_50 -> V_51 = 0 ;
V_50 -> V_52 = 64 ;
V_50 -> V_53 = 1 ;
return sizeof( * V_50 ) ;
}
static T_6 F_22 ( struct V_1 * V_2 , unsigned V_54 ,
T_1 * V_36 , T_3 V_55 , T_4 V_22 )
{
struct V_15 V_56 ;
T_4 V_57 ;
T_1 * V_58 ;
struct V_12 V_59 ;
int V_4 ;
if ( V_55 > 64 )
return - V_23 ;
if ( ( V_55 + V_22 ) > 64 )
V_22 = 64 - V_55 ;
F_9 ( & V_56 ) ;
V_57 = 4 + V_54 + V_55 + V_22 ;
V_58 = F_23 ( V_57 , V_60 ) ;
if ( ! V_58 )
return - V_61 ;
V_58 [ 0 ] = V_62 ;
memset ( & V_59 , 0 , sizeof V_59 ) ;
V_59 . V_24 = V_58 ;
V_59 . V_37 = V_58 ;
V_59 . V_22 = V_57 ;
F_10 ( & V_59 , & V_56 ) ;
F_3 ( V_2 ) ;
V_4 = F_13 ( V_2 , & V_56 ) ;
if ( V_4 >= 0 ) {
memcpy ( V_36 , V_58 + 4 + V_54 + V_55 , V_22 ) ;
V_4 = V_22 ;
}
F_24 ( V_58 ) ;
return V_4 ;
}
static int F_25 ( struct V_6 * V_7 ,
T_3 V_34 , T_4 V_22 , T_4 * V_35 , T_5 * V_36 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
int V_4 ;
F_11 ( & V_11 -> V_25 ) ;
V_4 = F_22 ( V_11 -> V_2 , 64 , V_36 , V_34 , V_22 ) ;
F_15 ( & V_11 -> V_25 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_35 = V_4 ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 ,
T_3 V_34 , T_4 V_22 , T_4 * V_35 , T_5 * V_36 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
int V_4 ;
F_11 ( & V_11 -> V_25 ) ;
V_4 = F_22 ( V_11 -> V_2 , 0 , V_36 , V_34 , V_22 ) ;
F_15 ( & V_11 -> V_25 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_35 = V_4 ;
return 0 ;
}
static int F_27 ( struct V_6 * V_7 ,
T_3 V_34 , T_4 V_22 , T_4 * V_35 , T_5 * V_36 )
{
struct V_15 V_56 ;
const T_4 V_57 = 4 + 64 ;
T_1 * V_58 ;
struct V_12 V_59 ;
struct V_10 * V_11 = V_7 -> V_11 ;
int V_4 ;
if ( V_22 > 64 )
return - V_23 ;
if ( ( V_34 + V_22 ) > 64 )
return - V_23 ;
V_58 = F_23 ( V_57 , V_60 ) ;
if ( ! V_58 )
return - V_61 ;
V_58 [ 0 ] = V_63 ;
memcpy ( V_58 + 4 + V_34 , V_36 , V_22 ) ;
F_9 ( & V_56 ) ;
memset ( & V_59 , 0 , sizeof V_59 ) ;
V_59 . V_24 = V_58 ;
V_59 . V_22 = V_57 ;
F_10 ( & V_59 , & V_56 ) ;
F_11 ( & V_11 -> V_25 ) ;
F_3 ( V_11 -> V_2 ) ;
V_4 = F_13 ( V_11 -> V_2 , & V_56 ) ;
F_15 ( & V_11 -> V_25 ) ;
F_24 ( V_58 ) ;
if ( V_4 >= 0 ) {
V_4 = 0 ;
* V_35 = V_22 ;
}
return V_4 ;
}
static char * F_28 ( struct V_6 * V_64 , char V_65 )
{
V_64 -> V_66 = F_21 ;
V_64 -> V_67 = F_25 ;
V_64 -> V_68 = F_21 ;
V_64 -> V_69 = F_26 ;
if ( V_65 > 'c' )
V_64 -> V_70 = F_27 ;
return L_19 ;
}
static char * F_28 ( struct V_6 * V_64 , char V_65 )
{
return L_20 ;
}
static int F_29 ( struct V_1 * V_2 , char * V_71 , int V_72 ,
int V_73 , int V_74 , char V_65 )
{
struct V_10 * V_11 ;
struct V_6 * V_64 ;
struct V_75 V_76 ;
struct V_77 * V_78 = F_30 ( & V_2 -> V_5 ) ;
char * V_79 = L_21 ;
int V_80 = 0 ;
V_11 = F_23 ( sizeof *V_11 , V_60 ) ;
if ( ! V_11 )
return - V_61 ;
F_31 ( & V_11 -> V_25 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_18 = V_73 ;
V_11 -> V_28 = V_74 ;
sprintf ( V_11 -> V_71 , L_22 ,
V_2 -> V_81 -> V_82 , V_2 -> V_83 ,
V_71 ) ;
V_64 = & V_11 -> V_7 ;
V_64 -> V_71 = ( V_78 && V_78 -> V_71 ) ? V_78 -> V_71 : V_11 -> V_71 ;
V_64 -> V_84 = V_72 * V_73 ;
V_64 -> V_85 = V_73 ;
V_64 -> V_86 = V_73 ;
V_64 -> V_87 = V_88 ;
V_64 -> type = V_89 ;
V_64 -> V_90 = V_91 ;
V_64 -> V_92 = F_7 ;
V_64 -> V_93 = F_17 ;
V_64 -> V_94 = F_18 ;
V_64 -> V_11 = V_11 ;
V_64 -> V_5 . V_95 = & V_2 -> V_5 ;
if ( V_65 >= 'c' )
V_79 = F_28 ( V_64 , V_65 ) ;
F_32 ( & V_2 -> V_5 , L_23 ,
V_71 , ( long long ) ( ( V_64 -> V_84 + 1023 ) >> 10 ) ,
V_73 , V_79 ) ;
F_33 ( V_2 , V_11 ) ;
V_76 . V_96 = V_2 -> V_5 . V_96 ;
V_80 = F_34 ( V_64 , NULL , & V_76 ,
V_78 ? V_78 -> V_97 : NULL ,
V_78 ? V_78 -> V_98 : 0 ) ;
if ( ! V_80 )
return 0 ;
F_33 ( V_2 , NULL ) ;
F_24 ( V_11 ) ;
return V_80 ;
}
static inline int F_35 ( struct V_1 * V_2 , char * V_71 ,
int V_72 , int V_73 , int V_74 )
{
return F_29 ( V_2 , V_71 , V_72 , V_73 ,
V_74 , 0 ) ;
}
static struct V_99 * F_36 ( struct V_1 * V_2 )
{
int V_100 ;
T_1 V_101 = V_102 ;
T_1 V_103 [ 3 ] ;
T_2 V_104 ;
struct V_99 * V_50 ;
int V_4 ;
V_100 = F_37 ( V_2 , & V_101 , 1 , V_103 , 3 ) ;
if ( V_100 < 0 ) {
F_4 ( L_24 ,
F_5 ( & V_2 -> V_5 ) , V_100 ) ;
return F_38 ( V_100 ) ;
}
if ( V_103 [ 0 ] != 0x1f )
return NULL ;
V_104 = V_103 [ 0 ] ;
V_104 = V_104 << 8 ;
V_104 |= V_103 [ 1 ] ;
V_104 = V_104 << 8 ;
V_104 |= V_103 [ 2 ] ;
for ( V_100 = 0 , V_50 = V_105 ;
V_100 < F_39 ( V_105 ) ;
V_100 ++ , V_50 ++ ) {
if ( V_50 -> V_106 == V_104 ) {
F_4 ( L_25 ,
F_5 ( & V_2 -> V_5 ) ,
( V_50 -> V_90 & V_107 )
? L_26 : L_21
) ;
if ( V_50 -> V_90 & V_107 ) {
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 ) {
F_4 ( L_27 ,
F_5 ( & V_2 -> V_5 ) , V_4 ) ;
return F_38 ( V_4 ) ;
}
if ( V_4 & 0x1 ) {
if ( V_50 -> V_90 & V_108 )
return V_50 ;
} else {
if ( ! ( V_50 -> V_90 & V_108 ) )
return V_50 ;
}
} else
return V_50 ;
}
}
F_40 ( & V_2 -> V_5 , L_28 , V_104 ) ;
return F_38 ( - V_109 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_99 * V_50 ;
V_50 = F_36 ( V_2 ) ;
if ( F_42 ( V_50 ) )
return F_43 ( V_50 ) ;
if ( V_50 != NULL )
return F_29 ( V_2 , V_50 -> V_71 , V_50 -> V_72 ,
V_50 -> V_73 , V_50 -> V_74 ,
( V_50 -> V_90 & V_107 ) ? 'd' : 'c' ) ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 <= 0 || V_4 == 0xff ) {
F_4 ( L_27 ,
F_5 ( & V_2 -> V_5 ) , V_4 ) ;
if ( V_4 == 0 || V_4 == 0xff )
V_4 = - V_109 ;
return V_4 ;
}
switch ( V_4 & 0x3c ) {
case 0x0c :
V_4 = F_35 ( V_2 , L_29 , 512 , 264 , 9 ) ;
break;
case 0x14 :
V_4 = F_35 ( V_2 , L_30 , 1024 , 264 , 9 ) ;
break;
case 0x1c :
V_4 = F_35 ( V_2 , L_31 , 2048 , 264 , 9 ) ;
break;
case 0x24 :
V_4 = F_35 ( V_2 , L_32 , 4096 , 264 , 9 ) ;
break;
case 0x2c :
V_4 = F_35 ( V_2 , L_33 , 4096 , 528 , 10 ) ;
break;
case 0x34 :
V_4 = F_35 ( V_2 , L_34 , 8192 , 528 , 10 ) ;
break;
case 0x38 :
case 0x3c :
V_4 = F_35 ( V_2 , L_35 , 8192 , 1056 , 11 ) ;
break;
default:
F_4 ( L_36 , F_5 ( & V_2 -> V_5 ) ,
V_4 & 0x3c ) ;
V_4 = - V_109 ;
}
if ( V_4 < 0 )
F_4 ( L_37 , F_5 ( & V_2 -> V_5 ) ,
V_4 ) ;
return V_4 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_10 * V_110 = F_45 ( V_2 ) ;
int V_4 ;
F_4 ( L_38 , F_5 ( & V_2 -> V_5 ) ) ;
V_4 = F_46 ( & V_110 -> V_7 ) ;
if ( V_4 == 0 ) {
F_33 ( V_2 , NULL ) ;
F_24 ( V_110 ) ;
}
return V_4 ;
}
