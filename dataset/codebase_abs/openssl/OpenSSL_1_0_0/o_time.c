struct V_1 * F_1 ( const T_1 * V_2 , struct V_1 * V_3 )
{
struct V_1 * V_4 = NULL ;
#if F_2 ( V_5 ) && ! F_2 ( V_6 ) && ! F_2 ( V_7 ) && ( ! F_2 ( V_8 ) || F_2 ( gmtime_r ) ) && ! F_2 ( V_9 ) && ! F_2 ( V_10 )
gmtime_r ( V_2 , V_3 ) ;
V_4 = V_3 ;
#elif ! F_2 ( V_8 )
V_4 = gmtime ( V_2 ) ;
if ( V_4 == NULL )
return NULL ;
memcpy ( V_3 , V_4 , sizeof( struct V_1 ) ) ;
V_4 = V_3 ;
#endif
#ifdef V_8
if ( V_4 == NULL )
{
static F_3 ( V_11 , L_1 ) ;
static F_3 ( V_12 , L_2 ) ;
char V_13 [ 256 ] ;
unsigned int V_14 = 0 ;
struct {
short V_15 ;
short V_16 ;
void * V_17 ;
unsigned int * V_14 ;
} V_18 [] = {
{ 0 , V_19 , 0 , 0 } ,
{ 0 , 0 , 0 , 0 } ,
} ;
int V_20 ;
T_1 V_21 ;
V_18 [ 0 ] . V_15 = sizeof( V_13 ) ;
V_18 [ 0 ] . V_17 = V_13 ;
V_18 [ 0 ] . V_14 = & V_14 ;
V_20 = F_4 ( 0 , & V_11 , & V_12 , 0 , V_18 ) ;
if ( ! ( V_20 & 1 ) )
return NULL ;
V_13 [ V_14 ] = '\0' ;
V_21 = * V_2 ;
#if V_22 < 70000000 || F_2 V_23
V_20 = atoi ( V_13 ) ;
V_21 -= V_20 ;
#endif
{
unsigned long V_24 [ 2 ] = { 1273708544 , 8164711 } ;
unsigned long V_25 [ 2 ] ;
unsigned long V_26 [ 2 ] ;
struct V_27
{
short V_28 , V_29 , V_30 , V_31 , V_32 , V_33 ,
V_34 ;
} V_35 ;
long V_36 ;
V_36 = V_37 ;
V_20 = F_5 ( & V_36 ,
& V_21 , V_25 ) ;
V_20 = F_6 ( V_24 , V_25 , V_26 ) ;
V_20 = F_7 ( & V_35 , V_26 ) ;
V_3 -> V_38 = V_35 . V_33 ;
V_3 -> V_39 = V_35 . V_32 ;
V_3 -> V_40 = V_35 . V_31 ;
V_3 -> V_41 = V_35 . V_30 ;
V_3 -> V_42 = V_35 . V_29 - 1 ;
V_3 -> V_43 = V_35 . V_28 - 1900 ;
V_36 = V_44 ;
V_20 = F_8 ( & V_36 ,
& V_3 -> V_45 , V_26 ) ;
V_3 -> V_45 %= 7 ;
V_36 = V_46 ;
V_20 = F_8 ( & V_36 ,
& V_3 -> V_47 , V_26 ) ;
V_3 -> V_47 -- ;
V_3 -> V_48 = 0 ;
V_4 = V_3 ;
}
}
#endif
return V_4 ;
}
int F_9 ( struct V_1 * V_1 , int V_49 , long V_50 )
{
int V_51 , V_52 ;
long V_53 ;
int V_54 , V_55 , V_56 ;
V_52 = V_50 / V_57 ;
V_51 = V_50 - ( V_52 * V_57 ) ;
V_52 += V_49 ;
V_51 += V_1 -> V_40 * 3600 + V_1 -> V_39 * 60 + V_1 -> V_38 ;
if ( V_51 >= V_57 )
{
V_52 ++ ;
V_51 -= V_57 ;
}
else if ( V_51 < 0 )
{
V_52 -- ;
V_51 += V_57 ;
}
V_54 = V_1 -> V_43 + 1900 ;
V_55 = V_1 -> V_42 + 1 ;
V_56 = V_1 -> V_41 ;
V_53 = F_10 ( V_54 , V_55 , V_56 ) ;
V_53 += V_52 ;
if ( V_53 < 0 )
return 0 ;
F_11 ( V_53 , & V_54 , & V_55 , & V_56 ) ;
if ( V_54 < 1900 || V_54 > 9999 )
return 0 ;
V_1 -> V_43 = V_54 - 1900 ;
V_1 -> V_42 = V_55 - 1 ;
V_1 -> V_41 = V_56 ;
V_1 -> V_40 = V_51 / 3600 ;
V_1 -> V_39 = ( V_51 / 60 ) % 60 ;
V_1 -> V_38 = V_51 % 60 ;
return 1 ;
}
static long F_10 ( int V_58 , int V_59 , int V_60 )
{
return ( 1461 * ( V_58 + 4800 + ( V_59 - 14 ) / 12 ) ) / 4 +
( 367 * ( V_59 - 2 - 12 * ( ( V_59 - 14 ) / 12 ) ) ) / 12 -
( 3 * ( ( V_58 + 4900 + ( V_59 - 14 ) / 12 ) / 100 ) ) / 4 +
V_60 - 32075 ;
}
static void F_11 ( long V_61 , int * V_58 , int * V_59 , int * V_60 )
{
long V_62 = V_61 + 68569 ;
long V_63 = ( 4 * V_62 ) / 146097 ;
long V_64 , V_65 ;
V_62 = V_62 - ( 146097 * V_63 + 3 ) / 4 ;
V_64 = ( 4000 * ( V_62 + 1 ) ) / 1461001 ;
V_62 = V_62 - ( 1461 * V_64 ) / 4 + 31 ;
V_65 = ( 80 * V_62 ) / 2447 ;
* V_60 = V_62 - ( 2447 * V_65 ) / 80 ;
V_62 = V_65 / 11 ;
* V_59 = V_65 + 2 - ( 12 * V_62 ) ;
* V_58 = 100 * ( V_63 - 49 ) + V_64 + V_62 ;
}
int main ( int V_66 , char * * V_67 )
{
long V_68 ;
for ( V_68 = 0 ; V_68 < 1000000 ; V_68 ++ )
{
F_12 ( V_68 ) ;
F_12 ( - V_68 ) ;
F_12 ( V_68 * 1000 ) ;
F_12 ( - V_68 * 1000 ) ;
}
}
int F_12 ( long V_68 )
{
struct V_1 V_69 , V_70 ;
T_1 V_71 , V_72 ;
time ( & V_71 ) ;
V_72 = V_71 + V_68 ;
F_1 ( & V_72 , & V_70 ) ;
F_1 ( & V_71 , & V_69 ) ;
F_9 ( & V_69 , 0 , V_68 ) ;
if ( ( V_69 . V_43 == V_70 . V_43 ) &&
( V_69 . V_42 == V_70 . V_42 ) &&
( V_69 . V_41 == V_70 . V_41 ) &&
( V_69 . V_40 == V_70 . V_40 ) &&
( V_69 . V_39 == V_70 . V_39 ) &&
( V_69 . V_38 == V_70 . V_38 ) )
return 1 ;
fprintf ( V_73 , L_3 ) ;
fprintf ( V_73 , L_4 ,
V_70 . V_41 , V_70 . V_42 + 1 , V_70 . V_43 + 1900 ,
V_70 . V_40 , V_70 . V_39 , V_70 . V_38 ) ;
fprintf ( V_73 , L_5 ,
V_69 . V_41 , V_69 . V_42 + 1 , V_69 . V_43 + 1900 ,
V_69 . V_40 , V_69 . V_39 , V_69 . V_38 ) ;
return 0 ;
}
