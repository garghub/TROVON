struct V_1 * F_1 ( const T_1 * V_2 , struct V_1 * V_3 )
{
struct V_1 * V_4 = NULL ;
#if F_2 ( V_5 ) && ! F_2 ( V_6 ) && ( ! F_2 ( V_7 ) || F_2 ( gmtime_r ) ) && ! F_2 ( V_8 )
gmtime_r ( V_2 , V_3 ) ;
V_4 = V_3 ;
#elif ! F_2 ( V_7 ) || F_2 ( V_9 )
V_4 = gmtime ( V_2 ) ;
if ( V_4 == NULL )
return NULL ;
memcpy ( V_3 , V_4 , sizeof( struct V_1 ) ) ;
V_4 = V_3 ;
#endif
#if F_2 ( V_7 ) && ! F_2 ( V_9 )
if ( V_4 == NULL ) {
static F_3 ( V_10 , L_1 ) ;
static F_3 ( V_11 , L_2 ) ;
char V_12 [ 256 ] ;
unsigned int V_13 = 0 ;
# if V_14 == 64
T_2 V_15 [ 2 ] , * V_16 ;
# else
T_3 V_15 [ 2 ] , * V_16 ;
# endif
int V_17 ;
T_1 V_18 ;
V_16 = V_15 ;
# if V_14 == 64
V_16 -> V_19 = 1 ;
V_16 -> V_20 = V_21 ;
V_16 -> V_22 = - 1 ;
V_16 -> V_23 = sizeof ( V_12 ) ;
V_16 -> V_24 = V_12 ;
V_16 -> V_25 = ( unsigned V_26 * ) & V_13 ;
V_16 ++ ;
V_16 -> V_23 = V_16 -> V_20 = 0 ;
# else
V_16 -> V_27 = sizeof ( V_12 ) ;
V_16 -> V_28 = V_21 ;
V_16 -> V_29 = V_12 ;
V_16 -> V_30 = ( unsigned short int * ) & V_13 ;
V_16 ++ ;
V_16 -> V_27 = V_16 -> V_28 = 0 ;
# endif
V_17 = F_4 ( 0 , & V_10 , & V_11 , 0 , V_15 ) ;
if ( ! ( V_17 & 1 ) )
return NULL ;
V_12 [ V_13 ] = '\0' ;
V_18 = * V_2 ;
# if V_31 < 70000000 || F_2 V_32
V_17 = atoi ( V_12 ) ;
V_18 -= V_17 ;
# endif
{
unsigned long V_33 [ 2 ] = { 1273708544 , 8164711 } ;
unsigned long V_34 [ 2 ] ;
unsigned long V_35 [ 2 ] ;
struct V_36 {
short V_37 , V_38 , V_39 , V_40 , V_41 , V_42 , V_43 ;
} V_44 ;
long V_45 ;
V_45 = V_46 ;
V_17 = F_5 ( & V_45 , & V_18 , V_34 ) ;
V_17 = F_6 ( V_33 , V_34 , V_35 ) ;
V_17 = F_7 ( & V_44 , V_35 ) ;
V_3 -> V_47 = V_44 . V_42 ;
V_3 -> V_48 = V_44 . V_41 ;
V_3 -> V_49 = V_44 . V_40 ;
V_3 -> V_50 = V_44 . V_39 ;
V_3 -> V_51 = V_44 . V_38 - 1 ;
V_3 -> V_52 = V_44 . V_37 - 1900 ;
V_45 = V_53 ;
V_17 = F_8 ( & V_45 ,
& V_3 -> V_54 , V_35 ) ;
V_3 -> V_54 %= 7 ;
V_45 = V_55 ;
V_17 = F_8 ( & V_45 ,
& V_3 -> V_56 , V_35 ) ;
V_3 -> V_56 -- ;
V_3 -> V_57 = 0 ;
V_4 = V_3 ;
}
}
#endif
return V_4 ;
}
int F_9 ( struct V_1 * V_1 , int V_58 , long V_59 )
{
int V_60 , V_61 , V_62 , V_63 ;
long V_64 ;
if ( ! F_10 ( V_1 , V_58 , V_59 , & V_64 , & V_60 ) )
return 0 ;
F_11 ( V_64 , & V_61 , & V_62 , & V_63 ) ;
if ( V_61 < 1900 || V_61 > 9999 )
return 0 ;
V_1 -> V_52 = V_61 - 1900 ;
V_1 -> V_51 = V_62 - 1 ;
V_1 -> V_50 = V_63 ;
V_1 -> V_49 = V_60 / 3600 ;
V_1 -> V_48 = ( V_60 / 60 ) % 60 ;
V_1 -> V_47 = V_60 % 60 ;
return 1 ;
}
int F_12 ( int * V_65 , int * V_66 ,
const struct V_1 * V_67 , const struct V_1 * V_68 )
{
int V_69 , V_70 , V_71 ;
long V_72 , V_73 , V_74 ;
if ( ! F_10 ( V_67 , 0 , 0 , & V_72 , & V_69 ) )
return 0 ;
if ( ! F_10 ( V_68 , 0 , 0 , & V_73 , & V_70 ) )
return 0 ;
V_74 = V_73 - V_72 ;
V_71 = V_70 - V_69 ;
if ( V_74 > 0 && V_71 < 0 ) {
V_74 -- ;
V_71 += V_75 ;
}
if ( V_74 < 0 && V_71 > 0 ) {
V_74 ++ ;
V_71 -= V_75 ;
}
if ( V_65 )
* V_65 = ( int ) V_74 ;
if ( V_66 )
* V_66 = V_71 ;
return 1 ;
}
static int F_10 ( const struct V_1 * V_1 , int V_58 , long V_59 ,
long * V_65 , int * V_66 )
{
int V_76 , V_77 ;
long V_64 ;
int V_61 , V_62 , V_63 ;
V_77 = V_59 / V_75 ;
V_76 = V_59 - ( V_77 * V_75 ) ;
V_77 += V_58 ;
V_76 += V_1 -> V_49 * 3600 + V_1 -> V_48 * 60 + V_1 -> V_47 ;
if ( V_76 >= V_75 ) {
V_77 ++ ;
V_76 -= V_75 ;
} else if ( V_76 < 0 ) {
V_77 -- ;
V_76 += V_75 ;
}
V_61 = V_1 -> V_52 + 1900 ;
V_62 = V_1 -> V_51 + 1 ;
V_63 = V_1 -> V_50 ;
V_64 = F_13 ( V_61 , V_62 , V_63 ) ;
V_64 += V_77 ;
if ( V_64 < 0 )
return 0 ;
* V_65 = V_64 ;
* V_66 = V_76 ;
return 1 ;
}
static long F_13 ( int V_78 , int V_79 , int V_80 )
{
return ( 1461 * ( V_78 + 4800 + ( V_79 - 14 ) / 12 ) ) / 4 +
( 367 * ( V_79 - 2 - 12 * ( ( V_79 - 14 ) / 12 ) ) ) / 12 -
( 3 * ( ( V_78 + 4900 + ( V_79 - 14 ) / 12 ) / 100 ) ) / 4 + V_80 - 32075 ;
}
static void F_11 ( long V_81 , int * V_78 , int * V_79 , int * V_80 )
{
long V_82 = V_81 + 68569 ;
long V_83 = ( 4 * V_82 ) / 146097 ;
long V_84 , V_85 ;
V_82 = V_82 - ( 146097 * V_83 + 3 ) / 4 ;
V_84 = ( 4000 * ( V_82 + 1 ) ) / 1461001 ;
V_82 = V_82 - ( 1461 * V_84 ) / 4 + 31 ;
V_85 = ( 80 * V_82 ) / 2447 ;
* V_80 = V_82 - ( 2447 * V_85 ) / 80 ;
V_82 = V_85 / 11 ;
* V_79 = V_85 + 2 - ( 12 * V_82 ) ;
* V_78 = 100 * ( V_83 - 49 ) + V_84 + V_82 ;
}
