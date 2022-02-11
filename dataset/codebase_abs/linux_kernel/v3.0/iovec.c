int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_6 , int V_7 )
{
int V_8 , V_9 , V_10 ;
if ( V_2 -> V_11 ) {
if ( V_7 == V_12 ) {
void T_1 * V_13 ;
V_13 = ( void T_1 V_14 * ) V_2 -> V_15 ;
V_10 = F_2 ( V_13 , V_2 -> V_11 ,
V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
}
V_2 -> V_15 = V_6 ;
} else {
V_2 -> V_15 = NULL ;
}
V_8 = V_2 -> V_16 * sizeof( struct V_3 ) ;
if ( F_3 ( V_4 , ( void T_1 V_14 * ) V_2 -> V_17 , V_8 ) )
return - V_18 ;
V_2 -> V_17 = V_4 ;
V_10 = 0 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_16 ; V_9 ++ ) {
T_2 V_19 = V_4 [ V_9 ] . V_20 ;
if ( V_19 > V_21 - V_10 ) {
V_19 = V_21 - V_10 ;
V_4 [ V_9 ] . V_20 = V_19 ;
}
V_10 += V_19 ;
}
return V_10 ;
}
int F_4 ( struct V_3 * V_4 , unsigned char * V_22 , int V_19 )
{
while ( V_19 > 0 ) {
if ( V_4 -> V_20 ) {
int V_23 = F_5 (unsigned int, iov->iov_len, len) ;
if ( F_6 ( V_4 -> V_24 , V_22 , V_23 ) )
return - V_18 ;
V_22 += V_23 ;
V_19 -= V_23 ;
V_4 -> V_20 -= V_23 ;
V_4 -> V_24 += V_23 ;
}
V_4 ++ ;
}
return 0 ;
}
int F_7 ( const struct V_3 * V_4 , unsigned char * V_22 ,
int V_25 , int V_19 )
{
int V_23 ;
for (; V_19 > 0 ; ++ V_4 ) {
if ( F_8 ( V_25 >= V_4 -> V_20 ) ) {
V_25 -= V_4 -> V_20 ;
continue;
}
V_23 = F_5 (unsigned int, iov->iov_len - offset, len) ;
if ( F_6 ( V_4 -> V_24 + V_25 , V_22 , V_23 ) )
return - V_18 ;
V_25 = 0 ;
V_22 += V_23 ;
V_19 -= V_23 ;
}
return 0 ;
}
int F_9 ( unsigned char * V_22 , struct V_3 * V_4 , int V_19 )
{
while ( V_19 > 0 ) {
if ( V_4 -> V_20 ) {
int V_23 = F_5 (unsigned int, len, iov->iov_len) ;
if ( F_3 ( V_22 , V_4 -> V_24 , V_23 ) )
return - V_18 ;
V_19 -= V_23 ;
V_22 += V_23 ;
V_4 -> V_24 += V_23 ;
V_4 -> V_20 -= V_23 ;
}
V_4 ++ ;
}
return 0 ;
}
int F_10 ( unsigned char * V_22 , const struct V_3 * V_4 ,
int V_25 , int V_19 )
{
while ( V_25 >= V_4 -> V_20 ) {
V_25 -= V_4 -> V_20 ;
V_4 ++ ;
}
while ( V_19 > 0 ) {
T_3 T_1 * V_26 = V_4 -> V_24 + V_25 ;
int V_23 = F_5 (unsigned int, len, iov->iov_len - offset) ;
V_25 = 0 ;
if ( F_3 ( V_22 , V_26 , V_23 ) )
return - V_18 ;
V_19 -= V_23 ;
V_22 += V_23 ;
V_4 ++ ;
}
return 0 ;
}
int F_11 ( unsigned char * V_22 , struct V_3 * V_4 ,
int V_25 , unsigned int V_19 , T_4 * V_27 )
{
T_4 V_28 = * V_27 ;
int V_29 = 0 , V_10 = 0 ;
while ( V_25 >= V_4 -> V_20 ) {
V_25 -= V_4 -> V_20 ;
V_4 ++ ;
}
while ( V_19 > 0 ) {
T_3 T_1 * V_26 = V_4 -> V_24 + V_25 ;
int V_23 = F_5 (unsigned int, len, iov->iov_len - offset) ;
V_25 = 0 ;
if ( V_29 ) {
int V_30 = 4 - V_29 ;
if ( V_30 > V_23 ) {
if ( F_3 ( V_22 , V_26 , V_23 ) )
goto V_31;
V_22 += V_23 ;
V_26 += V_23 ;
V_29 += V_23 ;
V_19 -= V_23 ;
V_4 ++ ;
if ( V_19 )
continue;
* V_27 = F_12 ( V_22 - V_29 ,
V_29 , V_28 ) ;
goto V_32;
}
if ( F_3 ( V_22 , V_26 , V_30 ) )
goto V_31;
V_28 = F_12 ( V_22 - V_29 , 4 , V_28 ) ;
V_22 += V_30 ;
V_26 += V_30 ;
V_23 -= V_30 ;
V_19 -= V_30 ;
V_29 = 0 ;
}
if ( V_19 > V_23 ) {
V_29 = V_23 % 4 ;
if ( V_29 ) {
V_23 -= V_29 ;
if ( F_3 ( V_22 + V_23 , V_26 + V_23 ,
V_29 ) )
goto V_31;
}
}
if ( V_23 ) {
V_28 = F_13 ( V_26 , V_22 , V_23 ,
V_28 , & V_10 ) ;
if ( V_10 )
goto V_32;
}
V_19 -= V_23 + V_29 ;
V_22 += V_23 + V_29 ;
V_4 ++ ;
}
* V_27 = V_28 ;
V_32:
return V_10 ;
V_31:
V_10 = - V_18 ;
goto V_32;
}
