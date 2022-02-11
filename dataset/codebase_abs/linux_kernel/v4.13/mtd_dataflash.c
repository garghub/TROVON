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
F_4 ( & V_2 -> V_5 , L_1 , V_4 ) ;
V_4 = 0 ;
}
if ( V_4 & ( 1 << 7 ) )
return V_4 ;
F_5 ( 3 ) ;
}
}
static int F_6 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_12 V_13 = { } ;
struct V_14 V_15 ;
unsigned V_16 = V_11 -> V_17 << 3 ;
T_1 * V_18 ;
T_2 V_19 ;
F_4 ( & V_2 -> V_5 , L_2 ,
( long long ) V_9 -> V_20 , ( long long ) V_9 -> V_21 ) ;
F_7 ( V_9 -> V_21 , V_11 -> V_17 , & V_19 ) ;
if ( V_19 )
return - V_22 ;
F_7 ( V_9 -> V_20 , V_11 -> V_17 , & V_19 ) ;
if ( V_19 )
return - V_22 ;
F_8 ( & V_15 ) ;
V_13 . V_23 = V_18 = V_11 -> V_18 ;
V_13 . V_21 = 4 ;
F_9 ( & V_13 , & V_15 ) ;
F_10 ( & V_11 -> V_24 ) ;
while ( V_9 -> V_21 > 0 ) {
unsigned int V_25 ;
int V_4 ;
int V_26 ;
V_25 = F_11 ( V_9 -> V_20 , V_11 -> V_17 ) ;
V_26 = ( V_25 & 0x7 ) == 0 && V_9 -> V_21 >= V_16 ;
V_25 = V_25 << V_11 -> V_27 ;
V_18 [ 0 ] = V_26 ? V_28 : V_29 ;
V_18 [ 1 ] = ( T_1 ) ( V_25 >> 16 ) ;
V_18 [ 2 ] = ( T_1 ) ( V_25 >> 8 ) ;
V_18 [ 3 ] = 0 ;
F_4 ( & V_2 -> V_5 , L_3 ,
V_26 ? L_4 : L_5 ,
V_18 [ 0 ] , V_18 [ 1 ] , V_18 [ 2 ] , V_18 [ 3 ] ,
V_25 ) ;
V_4 = F_12 ( V_2 , & V_15 ) ;
( void ) F_3 ( V_2 ) ;
if ( V_4 < 0 ) {
F_13 ( & V_2 -> V_5 , L_6 ,
V_25 , V_4 ) ;
continue;
}
if ( V_26 ) {
V_9 -> V_20 += V_16 ;
V_9 -> V_21 -= V_16 ;
} else {
V_9 -> V_20 += V_11 -> V_17 ;
V_9 -> V_21 -= V_11 -> V_17 ;
}
}
F_14 ( & V_11 -> V_24 ) ;
V_9 -> V_30 = V_31 ;
F_15 ( V_9 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , T_3 V_32 , T_4 V_21 ,
T_4 * V_33 , T_5 * V_34 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 V_13 [ 2 ] = { } ;
struct V_14 V_15 ;
unsigned int V_20 ;
T_1 * V_18 ;
int V_4 ;
F_4 ( & V_11 -> V_2 -> V_5 , L_7 ,
( unsigned int ) V_32 , ( unsigned int ) ( V_32 + V_21 ) ) ;
V_20 = ( ( ( unsigned ) V_32 / V_11 -> V_17 ) << V_11 -> V_27 )
+ ( ( unsigned ) V_32 % V_11 -> V_17 ) ;
V_18 = V_11 -> V_18 ;
F_4 ( & V_11 -> V_2 -> V_5 , L_8 ,
V_18 [ 0 ] , V_18 [ 1 ] , V_18 [ 2 ] , V_18 [ 3 ] ) ;
F_8 ( & V_15 ) ;
V_13 [ 0 ] . V_23 = V_18 ;
V_13 [ 0 ] . V_21 = 8 ;
F_9 ( & V_13 [ 0 ] , & V_15 ) ;
V_13 [ 1 ] . V_35 = V_34 ;
V_13 [ 1 ] . V_21 = V_21 ;
F_9 ( & V_13 [ 1 ] , & V_15 ) ;
F_10 ( & V_11 -> V_24 ) ;
V_18 [ 0 ] = V_36 ;
V_18 [ 1 ] = ( T_1 ) ( V_20 >> 16 ) ;
V_18 [ 2 ] = ( T_1 ) ( V_20 >> 8 ) ;
V_18 [ 3 ] = ( T_1 ) ( V_20 >> 0 ) ;
V_4 = F_12 ( V_11 -> V_2 , & V_15 ) ;
F_14 ( & V_11 -> V_24 ) ;
if ( V_4 >= 0 ) {
* V_33 = V_15 . V_37 - 8 ;
V_4 = 0 ;
} else
F_4 ( & V_11 -> V_2 -> V_5 , L_9 ,
( unsigned ) V_32 , ( unsigned ) ( V_32 + V_21 ) ,
V_4 ) ;
return V_4 ;
}
static int F_17 ( struct V_6 * V_7 , T_3 V_38 , T_4 V_21 ,
T_4 * V_33 , const T_5 * V_34 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_12 V_13 [ 2 ] = { } ;
struct V_14 V_15 ;
unsigned int V_25 , V_20 , V_39 , V_40 ;
T_4 V_41 = V_21 ;
T_5 * V_42 = ( T_5 * ) V_34 ;
int V_4 = - V_22 ;
T_1 * V_18 ;
F_4 ( & V_2 -> V_5 , L_10 ,
( unsigned int ) V_38 , ( unsigned int ) ( V_38 + V_21 ) ) ;
F_8 ( & V_15 ) ;
V_13 [ 0 ] . V_23 = V_18 = V_11 -> V_18 ;
V_13 [ 0 ] . V_21 = 4 ;
F_9 ( & V_13 [ 0 ] , & V_15 ) ;
V_25 = ( ( unsigned ) V_38 / V_11 -> V_17 ) ;
V_39 = ( ( unsigned ) V_38 % V_11 -> V_17 ) ;
if ( V_39 + V_21 > V_11 -> V_17 )
V_40 = V_11 -> V_17 - V_39 ;
else
V_40 = V_21 ;
F_10 ( & V_11 -> V_24 ) ;
while ( V_41 > 0 ) {
F_4 ( & V_2 -> V_5 , L_11 ,
V_25 , V_39 , V_40 ) ;
V_20 = V_25 << V_11 -> V_27 ;
if ( V_40 != V_11 -> V_17 ) {
V_18 [ 0 ] = V_43 ;
V_18 [ 1 ] = ( V_20 & 0x00FF0000 ) >> 16 ;
V_18 [ 2 ] = ( V_20 & 0x0000FF00 ) >> 8 ;
V_18 [ 3 ] = 0 ;
F_4 ( & V_2 -> V_5 , L_12 ,
V_18 [ 0 ] , V_18 [ 1 ] , V_18 [ 2 ] , V_18 [ 3 ] ) ;
V_4 = F_12 ( V_2 , & V_15 ) ;
if ( V_4 < 0 )
F_4 ( & V_2 -> V_5 , L_13 ,
V_20 , V_4 ) ;
( void ) F_3 ( V_11 -> V_2 ) ;
}
V_20 += V_39 ;
V_18 [ 0 ] = V_44 ;
V_18 [ 1 ] = ( V_20 & 0x00FF0000 ) >> 16 ;
V_18 [ 2 ] = ( V_20 & 0x0000FF00 ) >> 8 ;
V_18 [ 3 ] = ( V_20 & 0x000000FF ) ;
F_4 ( & V_2 -> V_5 , L_14 ,
V_18 [ 0 ] , V_18 [ 1 ] , V_18 [ 2 ] , V_18 [ 3 ] ) ;
V_13 [ 1 ] . V_23 = V_42 ;
V_13 [ 1 ] . V_21 = V_40 ;
F_9 ( V_13 + 1 , & V_15 ) ;
V_4 = F_12 ( V_2 , & V_15 ) ;
F_18 ( V_13 + 1 ) ;
if ( V_4 < 0 )
F_4 ( & V_2 -> V_5 , L_15 ,
V_20 , V_40 , V_4 ) ;
( void ) F_3 ( V_11 -> V_2 ) ;
#ifdef F_19
V_20 = V_25 << V_11 -> V_27 ;
V_18 [ 0 ] = V_45 ;
V_18 [ 1 ] = ( V_20 & 0x00FF0000 ) >> 16 ;
V_18 [ 2 ] = ( V_20 & 0x0000FF00 ) >> 8 ;
V_18 [ 3 ] = 0 ;
F_4 ( & V_2 -> V_5 , L_16 ,
V_18 [ 0 ] , V_18 [ 1 ] , V_18 [ 2 ] , V_18 [ 3 ] ) ;
V_4 = F_12 ( V_2 , & V_15 ) ;
if ( V_4 < 0 )
F_4 ( & V_2 -> V_5 , L_17 ,
V_20 , V_4 ) ;
V_4 = F_3 ( V_11 -> V_2 ) ;
if ( V_4 & ( 1 << 6 ) ) {
F_13 ( & V_2 -> V_5 , L_18 ,
V_25 , V_4 ) ;
V_41 = 0 ;
V_4 = - V_46 ;
break;
} else
V_4 = 0 ;
#endif
V_41 = V_41 - V_40 ;
V_25 ++ ;
V_39 = 0 ;
V_42 += V_40 ;
* V_33 += V_40 ;
if ( V_41 > V_11 -> V_17 )
V_40 = V_11 -> V_17 ;
else
V_40 = V_41 ;
}
F_14 ( & V_11 -> V_24 ) ;
return V_4 ;
}
static int F_20 ( struct V_6 * V_7 , T_4 V_21 ,
T_4 * V_33 , struct V_47 * V_48 )
{
V_48 -> V_49 = 0 ;
V_48 -> V_50 = 64 ;
V_48 -> V_51 = 1 ;
* V_33 = sizeof( * V_48 ) ;
return 0 ;
}
static T_6 F_21 ( struct V_1 * V_2 , unsigned V_52 ,
T_1 * V_34 , T_3 V_53 , T_4 V_21 )
{
struct V_14 V_54 ;
T_4 V_55 ;
T_1 * V_56 ;
struct V_12 V_57 ;
int V_4 ;
if ( V_53 > 64 )
return - V_22 ;
if ( ( V_53 + V_21 ) > 64 )
V_21 = 64 - V_53 ;
F_8 ( & V_54 ) ;
V_55 = 4 + V_52 + V_53 + V_21 ;
V_56 = F_22 ( V_55 , V_58 ) ;
if ( ! V_56 )
return - V_59 ;
V_56 [ 0 ] = V_60 ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_23 = V_56 ;
V_57 . V_35 = V_56 ;
V_57 . V_21 = V_55 ;
F_9 ( & V_57 , & V_54 ) ;
F_3 ( V_2 ) ;
V_4 = F_12 ( V_2 , & V_54 ) ;
if ( V_4 >= 0 ) {
memcpy ( V_34 , V_56 + 4 + V_52 + V_53 , V_21 ) ;
V_4 = V_21 ;
}
F_23 ( V_56 ) ;
return V_4 ;
}
static int F_24 ( struct V_6 * V_7 ,
T_3 V_32 , T_4 V_21 , T_4 * V_33 , T_5 * V_34 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
int V_4 ;
F_10 ( & V_11 -> V_24 ) ;
V_4 = F_21 ( V_11 -> V_2 , 64 , V_34 , V_32 , V_21 ) ;
F_14 ( & V_11 -> V_24 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_33 = V_4 ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 ,
T_3 V_32 , T_4 V_21 , T_4 * V_33 , T_5 * V_34 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
int V_4 ;
F_10 ( & V_11 -> V_24 ) ;
V_4 = F_21 ( V_11 -> V_2 , 0 , V_34 , V_32 , V_21 ) ;
F_14 ( & V_11 -> V_24 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_33 = V_4 ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 ,
T_3 V_32 , T_4 V_21 , T_4 * V_33 , T_5 * V_34 )
{
struct V_14 V_54 ;
const T_4 V_55 = 4 + 64 ;
T_1 * V_56 ;
struct V_12 V_57 ;
struct V_10 * V_11 = V_7 -> V_11 ;
int V_4 ;
if ( V_32 >= 64 ) {
* V_33 = 0 ;
return 0 ;
}
if ( ( V_32 + V_21 ) > 64 )
V_21 = 64 - V_32 ;
V_56 = F_22 ( V_55 , V_58 ) ;
if ( ! V_56 )
return - V_59 ;
V_56 [ 0 ] = V_61 ;
memcpy ( V_56 + 4 + V_32 , V_34 , V_21 ) ;
F_8 ( & V_54 ) ;
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . V_23 = V_56 ;
V_57 . V_21 = V_55 ;
F_9 ( & V_57 , & V_54 ) ;
F_10 ( & V_11 -> V_24 ) ;
F_3 ( V_11 -> V_2 ) ;
V_4 = F_12 ( V_11 -> V_2 , & V_54 ) ;
F_14 ( & V_11 -> V_24 ) ;
F_23 ( V_56 ) ;
if ( V_4 >= 0 ) {
V_4 = 0 ;
* V_33 = V_21 ;
}
return V_4 ;
}
static char * F_27 ( struct V_6 * V_62 , char V_63 )
{
V_62 -> V_64 = F_20 ;
V_62 -> V_65 = F_24 ;
V_62 -> V_66 = F_20 ;
V_62 -> V_67 = F_25 ;
if ( V_63 > 'c' )
V_62 -> V_68 = F_26 ;
return L_19 ;
}
static char * F_27 ( struct V_6 * V_62 , char V_63 )
{
return L_20 ;
}
static int F_28 ( struct V_1 * V_2 , char * V_69 , int V_70 ,
int V_71 , int V_72 , char V_63 )
{
struct V_10 * V_11 ;
struct V_6 * V_62 ;
struct V_73 * V_74 = F_29 ( & V_2 -> V_5 ) ;
char * V_75 = L_21 ;
int V_76 = 0 ;
V_11 = F_22 ( sizeof *V_11 , V_58 ) ;
if ( ! V_11 )
return - V_59 ;
F_30 ( & V_11 -> V_24 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_17 = V_71 ;
V_11 -> V_27 = V_72 ;
sprintf ( V_11 -> V_69 , L_22 ,
V_2 -> V_77 -> V_78 , V_2 -> V_79 ,
V_69 ) ;
V_62 = & V_11 -> V_7 ;
V_62 -> V_69 = ( V_74 && V_74 -> V_69 ) ? V_74 -> V_69 : V_11 -> V_69 ;
V_62 -> V_80 = V_70 * V_71 ;
V_62 -> V_81 = V_71 ;
V_62 -> V_82 = V_71 ;
V_62 -> type = V_83 ;
V_62 -> V_84 = V_85 ;
V_62 -> V_86 = F_6 ;
V_62 -> V_87 = F_16 ;
V_62 -> V_88 = F_17 ;
V_62 -> V_11 = V_11 ;
V_62 -> V_5 . V_89 = & V_2 -> V_5 ;
F_31 ( V_62 , V_2 -> V_5 . V_90 ) ;
if ( V_63 >= 'c' )
V_75 = F_27 ( V_62 , V_63 ) ;
F_32 ( & V_2 -> V_5 , L_23 ,
V_69 , ( long long ) ( ( V_62 -> V_80 + 1023 ) >> 10 ) ,
V_71 , V_75 ) ;
F_33 ( V_2 , V_11 ) ;
V_76 = F_34 ( V_62 ,
V_74 ? V_74 -> V_91 : NULL ,
V_74 ? V_74 -> V_92 : 0 ) ;
if ( ! V_76 )
return 0 ;
F_23 ( V_11 ) ;
return V_76 ;
}
static inline int F_35 ( struct V_1 * V_2 , char * V_69 ,
int V_70 , int V_71 , int V_72 )
{
return F_28 ( V_2 , V_69 , V_70 , V_71 ,
V_72 , 0 ) ;
}
static struct V_93 * F_36 ( struct V_1 * V_2 ,
T_7 V_94 , bool V_95 )
{
struct V_93 * V_48 ;
int V_4 ;
for ( V_48 = V_96 ;
V_48 < V_96 + F_37 ( V_96 ) ;
V_48 ++ ) {
if ( V_95 && ! ( V_48 -> V_84 & V_97 ) )
continue;
if ( V_48 -> V_98 == V_94 ) {
F_4 ( & V_2 -> V_5 , L_24 ,
( V_48 -> V_84 & V_99 ) ?
L_25 : L_21 ) ;
if ( V_48 -> V_84 & V_99 ) {
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 ) {
F_4 ( & V_2 -> V_5 , L_26 ,
V_4 ) ;
return F_38 ( V_4 ) ;
}
if ( V_4 & 0x1 ) {
if ( V_48 -> V_84 & V_100 )
return V_48 ;
} else {
if ( ! ( V_48 -> V_84 & V_100 ) )
return V_48 ;
}
} else
return V_48 ;
}
}
return F_38 ( - V_101 ) ;
}
static struct V_93 * F_39 ( struct V_1 * V_2 )
{
int V_102 ;
T_1 V_103 = V_104 ;
T_7 V_94 ;
T_1 V_105 [ sizeof( V_94 ) ] = { 0 } ;
const unsigned int V_106 = 5 ;
struct V_93 * V_48 ;
V_102 = F_40 ( V_2 , & V_103 , 1 , V_105 , V_106 ) ;
if ( V_102 < 0 ) {
F_4 ( & V_2 -> V_5 , L_27 , V_102 ) ;
return F_38 ( V_102 ) ;
}
if ( V_105 [ 0 ] != V_107 )
return NULL ;
V_94 = F_41 ( ( V_108 * ) V_105 ) ;
V_48 = F_36 ( V_2 , V_94 >> V_109 , true ) ;
if ( ! F_42 ( V_48 ) )
return V_48 ;
V_48 = F_36 ( V_2 , V_94 >> V_110 , false ) ;
if ( ! F_42 ( V_48 ) )
return V_48 ;
F_43 ( & V_2 -> V_5 , L_28 , V_94 ) ;
return F_38 ( - V_101 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_93 * V_48 ;
V_48 = F_39 ( V_2 ) ;
if ( F_42 ( V_48 ) )
return F_45 ( V_48 ) ;
if ( V_48 != NULL )
return F_28 ( V_2 , V_48 -> V_69 , V_48 -> V_70 ,
V_48 -> V_71 , V_48 -> V_72 ,
( V_48 -> V_84 & V_99 ) ? 'd' : 'c' ) ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 <= 0 || V_4 == 0xff ) {
F_4 ( & V_2 -> V_5 , L_26 , V_4 ) ;
if ( V_4 == 0 || V_4 == 0xff )
V_4 = - V_101 ;
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
F_32 ( & V_2 -> V_5 , L_36 ,
V_4 & 0x3c ) ;
V_4 = - V_101 ;
}
if ( V_4 < 0 )
F_4 ( & V_2 -> V_5 , L_37 , V_4 ) ;
return V_4 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_10 * V_111 = F_47 ( V_2 ) ;
int V_4 ;
F_4 ( & V_2 -> V_5 , L_38 ) ;
V_4 = F_48 ( & V_111 -> V_7 ) ;
if ( V_4 == 0 )
F_23 ( V_111 ) ;
return V_4 ;
}
