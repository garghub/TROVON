int F_1 ( T_1 * V_1 , int V_2 )
{
T_2 * V_3 ;
T_3 * V_4 ;
unsigned long V_5 ;
int V_6 , V_7 , V_8 , V_9 , V_10 , V_11 = 0 ;
const T_4 * V_12 ;
if ( V_2 )
{
if ( F_2 ( V_1 -> V_13 ) )
{
V_11 = F_3 ( V_1 -> V_13 ) ;
if ( V_11 < 0 )
return - 1 ;
}
V_4 = V_1 -> V_14 ;
V_3 = & ( V_1 -> V_15 -> V_16 ) ;
if ( V_1 -> V_14 == NULL )
V_12 = NULL ;
else
{
V_12 = F_4 ( V_1 -> V_14 ) ;
if ( V_3 -> V_17 != V_3 -> V_18 )
fprintf ( V_19 , L_1 ,
__FILE__ , __LINE__ ) ;
else if ( F_5 ( V_4 -> V_20 ) > 1 )
{
if ( F_6 ( V_3 -> V_18 , F_5 ( V_4 -> V_20 ) ) <= 0 )
return - 1 ;
}
}
}
else
{
if ( F_2 ( V_1 -> V_21 ) )
{
V_11 = F_3 ( V_1 -> V_21 ) ;
if ( V_11 < 0 )
return - 1 ;
}
V_4 = V_1 -> V_22 ;
V_3 = & ( V_1 -> V_15 -> V_23 ) ;
if ( V_1 -> V_22 == NULL )
V_12 = NULL ;
else
V_12 = F_4 ( V_1 -> V_22 ) ;
}
#ifdef F_7
printf ( L_2 , V_2 ) ;
#endif
if ( ( V_1 -> V_24 == NULL ) || ( V_4 == NULL ) ||
( V_12 == NULL ) )
{
memmove ( V_3 -> V_17 , V_3 -> V_18 , V_3 -> V_25 ) ;
V_3 -> V_18 = V_3 -> V_17 ;
}
else
{
V_5 = V_3 -> V_25 ;
V_6 = F_5 ( V_4 -> V_20 ) ;
if ( ( V_6 != 1 ) && V_2 )
{
V_7 = V_6 - ( ( int ) V_5 % V_6 ) ;
V_9 = V_7 - 1 ;
if ( V_1 -> V_26 & V_27 )
{
if ( V_1 -> V_15 -> V_28 & V_29 )
V_9 ++ ;
}
for ( V_10 = ( int ) V_5 ; V_10 < ( int ) ( V_5 + V_7 ) ; V_10 ++ )
V_3 -> V_18 [ V_10 ] = V_9 ;
V_5 += V_7 ;
V_3 -> V_25 += V_7 ;
}
#ifdef F_7
{
unsigned long V_30 ;
printf ( L_3 ,
V_4 , V_3 -> V_17 , V_3 -> V_18 , V_5 ) ;
printf ( L_4 ,
V_4 -> V_31 , V_4 -> V_20 -> V_32 ,
V_33 , V_34 ,
V_4 -> V_20 -> V_35 ) ;
printf ( L_5 ) ;
for ( V_7 = 0 ; V_7 < V_4 -> V_20 -> V_35 ; V_7 ++ ) printf ( L_6 , V_4 -> V_36 [ V_7 ] ) ;
printf ( L_7 ) ;
printf ( L_8 ) ;
for ( V_30 = 0 ; V_30 < V_5 ; V_30 ++ ) printf ( L_9 , V_3 -> V_18 [ V_30 ] ) ;
printf ( L_7 ) ;
}
#endif
if ( ! V_2 )
{
if ( V_5 == 0 || V_5 % V_6 != 0 )
{
F_8 ( V_37 , V_38 ) ;
F_9 ( V_1 , V_39 , V_40 ) ;
return 0 ;
}
}
F_10 ( V_4 , V_3 -> V_17 , V_3 -> V_18 , V_5 ) ;
#ifdef F_7
{
unsigned long V_7 ;
printf ( L_10 ) ;
for ( V_7 = 0 ; V_7 < V_5 ; V_7 ++ )
printf ( L_9 , V_3 -> V_17 [ V_7 ] ) ; printf ( L_7 ) ;
}
#endif
if ( ( V_6 != 1 ) && ! V_2 )
{
V_8 = V_7 = V_3 -> V_17 [ V_5 - 1 ] ;
V_7 ++ ;
if ( V_1 -> V_26 & V_27 )
{
if ( ( memcmp ( V_1 -> V_15 -> V_41 ,
L_11 , 8 ) == 0 ) && ! ( V_8 & 1 ) )
V_1 -> V_15 -> V_28 |= V_29 ;
if ( V_1 -> V_15 -> V_28 & V_29 )
V_7 -- ;
}
if ( V_7 > ( int ) V_3 -> V_25 )
{
return - 1 ;
}
for ( V_9 = ( int ) ( V_5 - V_7 ) ; V_9 < ( int ) V_5 ; V_9 ++ )
{
if ( V_3 -> V_17 [ V_9 ] != V_8 )
{
return - 1 ;
}
}
V_3 -> V_25 -= V_7 ;
V_3 -> V_17 += V_6 ;
V_3 -> V_18 += V_6 ;
V_3 -> V_25 -= V_6 ;
}
}
return ( 1 ) ;
}
