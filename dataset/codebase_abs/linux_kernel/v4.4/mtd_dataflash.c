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
struct V_12 V_13 = { } ;
struct V_14 V_15 ;
unsigned V_16 = V_11 -> V_17 << 3 ;
T_1 * V_18 ;
T_2 V_19 ;
F_4 ( L_2 ,
F_5 ( & V_2 -> V_5 ) , ( long long ) V_9 -> V_20 ,
( long long ) V_9 -> V_21 ) ;
F_8 ( V_9 -> V_21 , V_11 -> V_17 , & V_19 ) ;
if ( V_19 )
return - V_22 ;
F_8 ( V_9 -> V_20 , V_11 -> V_17 , & V_19 ) ;
if ( V_19 )
return - V_22 ;
F_9 ( & V_15 ) ;
V_13 . V_23 = V_18 = V_11 -> V_18 ;
V_13 . V_21 = 4 ;
F_10 ( & V_13 , & V_15 ) ;
F_11 ( & V_11 -> V_24 ) ;
while ( V_9 -> V_21 > 0 ) {
unsigned int V_25 ;
int V_4 ;
int V_26 ;
V_25 = F_12 ( V_9 -> V_20 , V_11 -> V_17 ) ;
V_26 = ( V_25 & 0x7 ) == 0 && V_9 -> V_21 >= V_16 ;
V_25 = V_25 << V_11 -> V_27 ;
V_18 [ 0 ] = V_26 ? V_28 : V_29 ;
V_18 [ 1 ] = ( T_1 ) ( V_25 >> 16 ) ;
V_18 [ 2 ] = ( T_1 ) ( V_25 >> 8 ) ;
V_18 [ 3 ] = 0 ;
F_4 ( L_3 ,
V_26 ? L_4 : L_5 ,
V_18 [ 0 ] , V_18 [ 1 ] , V_18 [ 2 ] , V_18 [ 3 ] ,
V_25 ) ;
V_4 = F_13 ( V_2 , & V_15 ) ;
( void ) F_3 ( V_2 ) ;
if ( V_4 < 0 ) {
F_14 ( V_30 L_6 ,
F_5 ( & V_2 -> V_5 ) , V_25 , V_4 ) ;
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
F_15 ( & V_11 -> V_24 ) ;
V_9 -> V_31 = V_32 ;
F_16 ( V_9 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , T_3 V_33 , T_4 V_21 ,
T_4 * V_34 , T_5 * V_35 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 V_13 [ 2 ] = { } ;
struct V_14 V_15 ;
unsigned int V_20 ;
T_1 * V_18 ;
int V_4 ;
F_4 ( L_7 , F_5 ( & V_11 -> V_2 -> V_5 ) ,
( unsigned ) V_33 , ( unsigned ) ( V_33 + V_21 ) ) ;
V_20 = ( ( ( unsigned ) V_33 / V_11 -> V_17 ) << V_11 -> V_27 )
+ ( ( unsigned ) V_33 % V_11 -> V_17 ) ;
V_18 = V_11 -> V_18 ;
F_4 ( L_8 ,
V_18 [ 0 ] , V_18 [ 1 ] , V_18 [ 2 ] , V_18 [ 3 ] ) ;
F_9 ( & V_15 ) ;
V_13 [ 0 ] . V_23 = V_18 ;
V_13 [ 0 ] . V_21 = 8 ;
F_10 ( & V_13 [ 0 ] , & V_15 ) ;
V_13 [ 1 ] . V_36 = V_35 ;
V_13 [ 1 ] . V_21 = V_21 ;
F_10 ( & V_13 [ 1 ] , & V_15 ) ;
F_11 ( & V_11 -> V_24 ) ;
V_18 [ 0 ] = V_37 ;
V_18 [ 1 ] = ( T_1 ) ( V_20 >> 16 ) ;
V_18 [ 2 ] = ( T_1 ) ( V_20 >> 8 ) ;
V_18 [ 3 ] = ( T_1 ) ( V_20 >> 0 ) ;
V_4 = F_13 ( V_11 -> V_2 , & V_15 ) ;
F_15 ( & V_11 -> V_24 ) ;
if ( V_4 >= 0 ) {
* V_34 = V_15 . V_38 - 8 ;
V_4 = 0 ;
} else
F_4 ( L_9 ,
F_5 ( & V_11 -> V_2 -> V_5 ) ,
( unsigned ) V_33 , ( unsigned ) ( V_33 + V_21 ) ,
V_4 ) ;
return V_4 ;
}
static int F_18 ( struct V_6 * V_7 , T_3 V_39 , T_4 V_21 ,
T_4 * V_34 , const T_5 * V_35 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_12 V_13 [ 2 ] = { } ;
struct V_14 V_15 ;
unsigned int V_25 , V_20 , V_40 , V_41 ;
T_4 V_42 = V_21 ;
T_5 * V_43 = ( T_5 * ) V_35 ;
int V_4 = - V_22 ;
T_1 * V_18 ;
F_4 ( L_10 ,
F_5 ( & V_2 -> V_5 ) , ( unsigned ) V_39 , ( unsigned ) ( V_39 + V_21 ) ) ;
F_9 ( & V_15 ) ;
V_13 [ 0 ] . V_23 = V_18 = V_11 -> V_18 ;
V_13 [ 0 ] . V_21 = 4 ;
F_10 ( & V_13 [ 0 ] , & V_15 ) ;
V_25 = ( ( unsigned ) V_39 / V_11 -> V_17 ) ;
V_40 = ( ( unsigned ) V_39 % V_11 -> V_17 ) ;
if ( V_40 + V_21 > V_11 -> V_17 )
V_41 = V_11 -> V_17 - V_40 ;
else
V_41 = V_21 ;
F_11 ( & V_11 -> V_24 ) ;
while ( V_42 > 0 ) {
F_4 ( L_11 ,
V_25 , V_40 , V_41 ) ;
V_20 = V_25 << V_11 -> V_27 ;
if ( V_41 != V_11 -> V_17 ) {
V_18 [ 0 ] = V_44 ;
V_18 [ 1 ] = ( V_20 & 0x00FF0000 ) >> 16 ;
V_18 [ 2 ] = ( V_20 & 0x0000FF00 ) >> 8 ;
V_18 [ 3 ] = 0 ;
F_4 ( L_12 ,
V_18 [ 0 ] , V_18 [ 1 ] , V_18 [ 2 ] , V_18 [ 3 ] ) ;
V_4 = F_13 ( V_2 , & V_15 ) ;
if ( V_4 < 0 )
F_4 ( L_13 ,
F_5 ( & V_2 -> V_5 ) , V_20 , V_4 ) ;
( void ) F_3 ( V_11 -> V_2 ) ;
}
V_20 += V_40 ;
V_18 [ 0 ] = V_45 ;
V_18 [ 1 ] = ( V_20 & 0x00FF0000 ) >> 16 ;
V_18 [ 2 ] = ( V_20 & 0x0000FF00 ) >> 8 ;
V_18 [ 3 ] = ( V_20 & 0x000000FF ) ;
F_4 ( L_14 ,
V_18 [ 0 ] , V_18 [ 1 ] , V_18 [ 2 ] , V_18 [ 3 ] ) ;
V_13 [ 1 ] . V_23 = V_43 ;
V_13 [ 1 ] . V_21 = V_41 ;
F_10 ( V_13 + 1 , & V_15 ) ;
V_4 = F_13 ( V_2 , & V_15 ) ;
F_19 ( V_13 + 1 ) ;
if ( V_4 < 0 )
F_4 ( L_15 ,
F_5 ( & V_2 -> V_5 ) , V_20 , V_41 , V_4 ) ;
( void ) F_3 ( V_11 -> V_2 ) ;
#ifdef F_20
V_20 = V_25 << V_11 -> V_27 ;
V_18 [ 0 ] = V_46 ;
V_18 [ 1 ] = ( V_20 & 0x00FF0000 ) >> 16 ;
V_18 [ 2 ] = ( V_20 & 0x0000FF00 ) >> 8 ;
V_18 [ 3 ] = 0 ;
F_4 ( L_16 ,
V_18 [ 0 ] , V_18 [ 1 ] , V_18 [ 2 ] , V_18 [ 3 ] ) ;
V_4 = F_13 ( V_2 , & V_15 ) ;
if ( V_4 < 0 )
F_4 ( L_17 ,
F_5 ( & V_2 -> V_5 ) , V_20 , V_4 ) ;
V_4 = F_3 ( V_11 -> V_2 ) ;
if ( V_4 & ( 1 << 6 ) ) {
F_14 ( V_30 L_18 ,
F_5 ( & V_2 -> V_5 ) , V_25 , V_4 ) ;
V_42 = 0 ;
V_4 = - V_47 ;
break;
} else
V_4 = 0 ;
#endif
V_42 = V_42 - V_41 ;
V_25 ++ ;
V_40 = 0 ;
V_43 += V_41 ;
* V_34 += V_41 ;
if ( V_42 > V_11 -> V_17 )
V_41 = V_11 -> V_17 ;
else
V_41 = V_42 ;
}
F_15 ( & V_11 -> V_24 ) ;
return V_4 ;
}
static int F_21 ( struct V_6 * V_7 , T_4 V_21 ,
T_4 * V_34 , struct V_48 * V_49 )
{
V_49 -> V_50 = 0 ;
V_49 -> V_51 = 64 ;
V_49 -> V_52 = 1 ;
* V_34 = sizeof( * V_49 ) ;
return 0 ;
}
static T_6 F_22 ( struct V_1 * V_2 , unsigned V_53 ,
T_1 * V_35 , T_3 V_54 , T_4 V_21 )
{
struct V_14 V_55 ;
T_4 V_56 ;
T_1 * V_57 ;
struct V_12 V_58 ;
int V_4 ;
if ( V_54 > 64 )
return - V_22 ;
if ( ( V_54 + V_21 ) > 64 )
V_21 = 64 - V_54 ;
F_9 ( & V_55 ) ;
V_56 = 4 + V_53 + V_54 + V_21 ;
V_57 = F_23 ( V_56 , V_59 ) ;
if ( ! V_57 )
return - V_60 ;
V_57 [ 0 ] = V_61 ;
memset ( & V_58 , 0 , sizeof V_58 ) ;
V_58 . V_23 = V_57 ;
V_58 . V_36 = V_57 ;
V_58 . V_21 = V_56 ;
F_10 ( & V_58 , & V_55 ) ;
F_3 ( V_2 ) ;
V_4 = F_13 ( V_2 , & V_55 ) ;
if ( V_4 >= 0 ) {
memcpy ( V_35 , V_57 + 4 + V_53 + V_54 , V_21 ) ;
V_4 = V_21 ;
}
F_24 ( V_57 ) ;
return V_4 ;
}
static int F_25 ( struct V_6 * V_7 ,
T_3 V_33 , T_4 V_21 , T_4 * V_34 , T_5 * V_35 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
int V_4 ;
F_11 ( & V_11 -> V_24 ) ;
V_4 = F_22 ( V_11 -> V_2 , 64 , V_35 , V_33 , V_21 ) ;
F_15 ( & V_11 -> V_24 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_34 = V_4 ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 ,
T_3 V_33 , T_4 V_21 , T_4 * V_34 , T_5 * V_35 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
int V_4 ;
F_11 ( & V_11 -> V_24 ) ;
V_4 = F_22 ( V_11 -> V_2 , 0 , V_35 , V_33 , V_21 ) ;
F_15 ( & V_11 -> V_24 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_34 = V_4 ;
return 0 ;
}
static int F_27 ( struct V_6 * V_7 ,
T_3 V_33 , T_4 V_21 , T_4 * V_34 , T_5 * V_35 )
{
struct V_14 V_55 ;
const T_4 V_56 = 4 + 64 ;
T_1 * V_57 ;
struct V_12 V_58 ;
struct V_10 * V_11 = V_7 -> V_11 ;
int V_4 ;
if ( V_33 >= 64 ) {
* V_34 = 0 ;
return 0 ;
}
if ( ( V_33 + V_21 ) > 64 )
V_21 = 64 - V_33 ;
V_57 = F_23 ( V_56 , V_59 ) ;
if ( ! V_57 )
return - V_60 ;
V_57 [ 0 ] = V_62 ;
memcpy ( V_57 + 4 + V_33 , V_35 , V_21 ) ;
F_9 ( & V_55 ) ;
memset ( & V_58 , 0 , sizeof V_58 ) ;
V_58 . V_23 = V_57 ;
V_58 . V_21 = V_56 ;
F_10 ( & V_58 , & V_55 ) ;
F_11 ( & V_11 -> V_24 ) ;
F_3 ( V_11 -> V_2 ) ;
V_4 = F_13 ( V_11 -> V_2 , & V_55 ) ;
F_15 ( & V_11 -> V_24 ) ;
F_24 ( V_57 ) ;
if ( V_4 >= 0 ) {
V_4 = 0 ;
* V_34 = V_21 ;
}
return V_4 ;
}
static char * F_28 ( struct V_6 * V_63 , char V_64 )
{
V_63 -> V_65 = F_21 ;
V_63 -> V_66 = F_25 ;
V_63 -> V_67 = F_21 ;
V_63 -> V_68 = F_26 ;
if ( V_64 > 'c' )
V_63 -> V_69 = F_27 ;
return L_19 ;
}
static char * F_28 ( struct V_6 * V_63 , char V_64 )
{
return L_20 ;
}
static int F_29 ( struct V_1 * V_2 , char * V_70 , int V_71 ,
int V_72 , int V_73 , char V_64 )
{
struct V_10 * V_11 ;
struct V_6 * V_63 ;
struct V_74 V_75 ;
struct V_76 * V_77 = F_30 ( & V_2 -> V_5 ) ;
char * V_78 = L_21 ;
int V_79 = 0 ;
V_11 = F_23 ( sizeof *V_11 , V_59 ) ;
if ( ! V_11 )
return - V_60 ;
F_31 ( & V_11 -> V_24 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_17 = V_72 ;
V_11 -> V_27 = V_73 ;
sprintf ( V_11 -> V_70 , L_22 ,
V_2 -> V_80 -> V_81 , V_2 -> V_82 ,
V_70 ) ;
V_63 = & V_11 -> V_7 ;
V_63 -> V_70 = ( V_77 && V_77 -> V_70 ) ? V_77 -> V_70 : V_11 -> V_70 ;
V_63 -> V_83 = V_71 * V_72 ;
V_63 -> V_84 = V_72 ;
V_63 -> V_85 = V_72 ;
V_63 -> type = V_86 ;
V_63 -> V_87 = V_88 ;
V_63 -> V_89 = F_7 ;
V_63 -> V_90 = F_17 ;
V_63 -> V_91 = F_18 ;
V_63 -> V_11 = V_11 ;
V_63 -> V_5 . V_92 = & V_2 -> V_5 ;
if ( V_64 >= 'c' )
V_78 = F_28 ( V_63 , V_64 ) ;
F_32 ( & V_2 -> V_5 , L_23 ,
V_70 , ( long long ) ( ( V_63 -> V_83 + 1023 ) >> 10 ) ,
V_72 , V_78 ) ;
F_33 ( V_2 , V_11 ) ;
V_75 . V_93 = V_2 -> V_5 . V_93 ;
V_79 = F_34 ( V_63 , NULL , & V_75 ,
V_77 ? V_77 -> V_94 : NULL ,
V_77 ? V_77 -> V_95 : 0 ) ;
if ( ! V_79 )
return 0 ;
F_24 ( V_11 ) ;
return V_79 ;
}
static inline int F_35 ( struct V_1 * V_2 , char * V_70 ,
int V_71 , int V_72 , int V_73 )
{
return F_29 ( V_2 , V_70 , V_71 , V_72 ,
V_73 , 0 ) ;
}
static struct V_96 * F_36 ( struct V_1 * V_2 )
{
int V_97 ;
T_1 V_98 = V_99 ;
T_1 V_100 [ 3 ] ;
T_2 V_101 ;
struct V_96 * V_49 ;
int V_4 ;
V_97 = F_37 ( V_2 , & V_98 , 1 , V_100 , 3 ) ;
if ( V_97 < 0 ) {
F_4 ( L_24 ,
F_5 ( & V_2 -> V_5 ) , V_97 ) ;
return F_38 ( V_97 ) ;
}
if ( V_100 [ 0 ] != 0x1f )
return NULL ;
V_101 = V_100 [ 0 ] ;
V_101 = V_101 << 8 ;
V_101 |= V_100 [ 1 ] ;
V_101 = V_101 << 8 ;
V_101 |= V_100 [ 2 ] ;
for ( V_97 = 0 , V_49 = V_102 ;
V_97 < F_39 ( V_102 ) ;
V_97 ++ , V_49 ++ ) {
if ( V_49 -> V_103 == V_101 ) {
F_4 ( L_25 ,
F_5 ( & V_2 -> V_5 ) ,
( V_49 -> V_87 & V_104 )
? L_26 : L_21
) ;
if ( V_49 -> V_87 & V_104 ) {
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 ) {
F_4 ( L_27 ,
F_5 ( & V_2 -> V_5 ) , V_4 ) ;
return F_38 ( V_4 ) ;
}
if ( V_4 & 0x1 ) {
if ( V_49 -> V_87 & V_105 )
return V_49 ;
} else {
if ( ! ( V_49 -> V_87 & V_105 ) )
return V_49 ;
}
} else
return V_49 ;
}
}
F_40 ( & V_2 -> V_5 , L_28 , V_101 ) ;
return F_38 ( - V_106 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_96 * V_49 ;
V_49 = F_36 ( V_2 ) ;
if ( F_42 ( V_49 ) )
return F_43 ( V_49 ) ;
if ( V_49 != NULL )
return F_29 ( V_2 , V_49 -> V_70 , V_49 -> V_71 ,
V_49 -> V_72 , V_49 -> V_73 ,
( V_49 -> V_87 & V_104 ) ? 'd' : 'c' ) ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 <= 0 || V_4 == 0xff ) {
F_4 ( L_27 ,
F_5 ( & V_2 -> V_5 ) , V_4 ) ;
if ( V_4 == 0 || V_4 == 0xff )
V_4 = - V_106 ;
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
V_4 = - V_106 ;
}
if ( V_4 < 0 )
F_4 ( L_37 , F_5 ( & V_2 -> V_5 ) ,
V_4 ) ;
return V_4 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_10 * V_107 = F_45 ( V_2 ) ;
int V_4 ;
F_4 ( L_38 , F_5 ( & V_2 -> V_5 ) ) ;
V_4 = F_46 ( & V_107 -> V_7 ) ;
if ( V_4 == 0 )
F_24 ( V_107 ) ;
return V_4 ;
}
