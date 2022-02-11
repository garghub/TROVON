struct V_1 * F_1 ( const T_1 * V_2 , struct V_1 * V_3 )
{
struct V_1 * V_4 = NULL ;
#if F_2 ( V_5 ) && ! F_2 ( V_6 ) && ! F_2 ( V_7 ) && ( ! F_2 ( V_8 ) || F_2 ( gmtime_r ) ) && ! F_2 ( V_9 ) && ! F_2 ( V_10 )
gmtime_r ( V_2 , V_3 ) ;
V_4 = V_3 ;
#elif ! F_2 ( V_8 ) || F_2 ( V_11 )
V_4 = gmtime ( V_2 ) ;
if ( V_4 == NULL )
return NULL ;
memcpy ( V_3 , V_4 , sizeof( struct V_1 ) ) ;
V_4 = V_3 ;
#endif
#if F_2 ( V_8 ) && ! F_2 ( V_11 )
if ( V_4 == NULL ) {
static F_3 ( V_12 , L_1 ) ;
static F_3 ( V_13 , L_2 ) ;
char V_14 [ 256 ] ;
unsigned int V_15 = 0 ;
struct {
short V_16 ;
short V_17 ;
void * V_18 ;
unsigned int * V_15 ;
} V_19 [] = {
{
0 , V_20 , 0 , 0
} ,
{
0 , 0 , 0 , 0
} ,
} ;
int V_21 ;
T_1 V_22 ;
V_19 [ 0 ] . V_16 = sizeof( V_14 ) ;
V_19 [ 0 ] . V_18 = V_14 ;
V_19 [ 0 ] . V_15 = & V_15 ;
V_21 = F_4 ( 0 , & V_12 , & V_13 , 0 , V_19 ) ;
if ( ! ( V_21 & 1 ) )
return NULL ;
V_14 [ V_15 ] = '\0' ;
V_22 = * V_2 ;
# if V_23 < 70000000 || F_2 V_24
V_21 = atoi ( V_14 ) ;
V_22 -= V_21 ;
# endif
{
unsigned long V_25 [ 2 ] = { 1273708544 , 8164711 } ;
unsigned long V_26 [ 2 ] ;
unsigned long V_27 [ 2 ] ;
struct V_28 {
short V_29 , V_30 , V_31 , V_32 , V_33 , V_34 , V_35 ;
} V_36 ;
long V_37 ;
V_37 = V_38 ;
V_21 = F_5 ( & V_37 , & V_22 , V_26 ) ;
V_21 = F_6 ( V_25 , V_26 , V_27 ) ;
V_21 = F_7 ( & V_36 , V_27 ) ;
V_3 -> V_39 = V_36 . V_34 ;
V_3 -> V_40 = V_36 . V_33 ;
V_3 -> V_41 = V_36 . V_32 ;
V_3 -> V_42 = V_36 . V_31 ;
V_3 -> V_43 = V_36 . V_30 - 1 ;
V_3 -> V_44 = V_36 . V_29 - 1900 ;
V_37 = V_45 ;
V_21 = F_8 ( & V_37 ,
& V_3 -> V_46 , V_27 ) ;
V_3 -> V_46 %= 7 ;
V_37 = V_47 ;
V_21 = F_8 ( & V_37 ,
& V_3 -> V_48 , V_27 ) ;
V_3 -> V_48 -- ;
V_3 -> V_49 = 0 ;
V_4 = V_3 ;
}
}
#endif
return V_4 ;
}
int F_9 ( struct V_1 * V_1 , int V_50 , long V_51 )
{
int V_52 , V_53 , V_54 , V_55 ;
long V_56 ;
if ( ! F_10 ( V_1 , V_50 , V_51 , & V_56 , & V_52 ) )
return 0 ;
F_11 ( V_56 , & V_53 , & V_54 , & V_55 ) ;
if ( V_53 < 1900 || V_53 > 9999 )
return 0 ;
V_1 -> V_44 = V_53 - 1900 ;
V_1 -> V_43 = V_54 - 1 ;
V_1 -> V_42 = V_55 ;
V_1 -> V_41 = V_52 / 3600 ;
V_1 -> V_40 = ( V_52 / 60 ) % 60 ;
V_1 -> V_39 = V_52 % 60 ;
return 1 ;
}
int F_12 ( int * V_57 , int * V_58 ,
const struct V_1 * V_59 , const struct V_1 * V_60 )
{
int V_61 , V_62 , V_63 ;
long V_64 , V_65 , V_66 ;
if ( ! F_10 ( V_59 , 0 , 0 , & V_64 , & V_61 ) )
return 0 ;
if ( ! F_10 ( V_60 , 0 , 0 , & V_65 , & V_62 ) )
return 0 ;
V_66 = V_65 - V_64 ;
V_63 = V_62 - V_61 ;
if ( V_66 > 0 && V_63 < 0 ) {
V_66 -- ;
V_63 += V_67 ;
}
if ( V_66 < 0 && V_63 > 0 ) {
V_66 ++ ;
V_63 -= V_67 ;
}
if ( V_57 )
* V_57 = ( int ) V_66 ;
if ( V_58 )
* V_58 = V_63 ;
return 1 ;
}
static int F_10 ( const struct V_1 * V_1 , int V_50 , long V_51 ,
long * V_57 , int * V_58 )
{
int V_68 , V_69 ;
long V_56 ;
int V_53 , V_54 , V_55 ;
V_69 = V_51 / V_67 ;
V_68 = V_51 - ( V_69 * V_67 ) ;
V_69 += V_50 ;
V_68 += V_1 -> V_41 * 3600 + V_1 -> V_40 * 60 + V_1 -> V_39 ;
if ( V_68 >= V_67 ) {
V_69 ++ ;
V_68 -= V_67 ;
} else if ( V_68 < 0 ) {
V_69 -- ;
V_68 += V_67 ;
}
V_53 = V_1 -> V_44 + 1900 ;
V_54 = V_1 -> V_43 + 1 ;
V_55 = V_1 -> V_42 ;
V_56 = F_13 ( V_53 , V_54 , V_55 ) ;
V_56 += V_69 ;
if ( V_56 < 0 )
return 0 ;
* V_57 = V_56 ;
* V_58 = V_68 ;
return 1 ;
}
static long F_13 ( int V_70 , int V_71 , int V_72 )
{
return ( 1461 * ( V_70 + 4800 + ( V_71 - 14 ) / 12 ) ) / 4 +
( 367 * ( V_71 - 2 - 12 * ( ( V_71 - 14 ) / 12 ) ) ) / 12 -
( 3 * ( ( V_70 + 4900 + ( V_71 - 14 ) / 12 ) / 100 ) ) / 4 + V_72 - 32075 ;
}
static void F_11 ( long V_73 , int * V_70 , int * V_71 , int * V_72 )
{
long V_74 = V_73 + 68569 ;
long V_75 = ( 4 * V_74 ) / 146097 ;
long V_76 , V_77 ;
V_74 = V_74 - ( 146097 * V_75 + 3 ) / 4 ;
V_76 = ( 4000 * ( V_74 + 1 ) ) / 1461001 ;
V_74 = V_74 - ( 1461 * V_76 ) / 4 + 31 ;
V_77 = ( 80 * V_74 ) / 2447 ;
* V_72 = V_74 - ( 2447 * V_77 ) / 80 ;
V_74 = V_77 / 11 ;
* V_71 = V_77 + 2 - ( 12 * V_74 ) ;
* V_70 = 100 * ( V_75 - 49 ) + V_76 + V_74 ;
}
int main ( int V_78 , char * * V_79 )
{
long V_80 ;
for ( V_80 = 0 ; V_80 < 1000000 ; V_80 ++ ) {
F_14 ( V_80 ) ;
F_14 ( - V_80 ) ;
F_14 ( V_80 * 1000 ) ;
F_14 ( - V_80 * 1000 ) ;
}
}
int F_14 ( long V_80 )
{
struct V_1 V_81 , V_82 , V_83 ;
int V_50 , V_84 ;
long V_85 ;
T_1 V_86 , V_87 ;
time ( & V_86 ) ;
V_87 = V_86 + V_80 ;
F_1 ( & V_87 , & V_82 ) ;
F_1 ( & V_86 , & V_81 ) ;
V_83 = V_81 ;
F_9 ( & V_81 , 0 , V_80 ) ;
if ( ( V_81 . V_44 != V_82 . V_44 ) ||
( V_81 . V_43 != V_82 . V_43 ) ||
( V_81 . V_42 != V_82 . V_42 ) ||
( V_81 . V_41 != V_82 . V_41 ) ||
( V_81 . V_40 != V_82 . V_40 ) || ( V_81 . V_39 != V_82 . V_39 ) ) {
fprintf ( V_88 , L_3 ) ;
fprintf ( V_88 , L_4 ,
V_82 . V_42 , V_82 . V_43 + 1 , V_82 . V_44 + 1900 ,
V_82 . V_41 , V_82 . V_40 , V_82 . V_39 ) ;
fprintf ( V_88 , L_5 ,
V_81 . V_42 , V_81 . V_43 + 1 , V_81 . V_44 + 1900 ,
V_81 . V_41 , V_81 . V_40 , V_81 . V_39 ) ;
return 0 ;
}
F_12 ( & V_83 , & V_81 , & V_50 , & V_84 ) ;
V_85 = ( long ) V_50 * V_67 + V_84 ;
if ( V_80 != V_85 ) {
fprintf ( V_88 , L_6 ) ;
fprintf ( V_88 , L_7 ,
V_80 , V_85 , V_50 , V_84 ) ;
return 0 ;
}
return 1 ;
}
