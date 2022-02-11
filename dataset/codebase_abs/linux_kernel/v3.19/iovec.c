int F_1 ( unsigned char * V_1 , struct V_2 * V_3 , int V_4 )
{
while ( V_4 > 0 ) {
if ( V_3 -> V_5 ) {
int V_6 = F_2 (unsigned int, len, iov->iov_len) ;
if ( F_3 ( V_1 , V_3 -> V_7 , V_6 ) )
return - V_8 ;
V_4 -= V_6 ;
V_1 += V_6 ;
V_3 -> V_7 += V_6 ;
V_3 -> V_5 -= V_6 ;
}
V_3 ++ ;
}
return 0 ;
}
int F_4 ( const struct V_2 * V_3 , unsigned char * V_1 ,
int V_9 , int V_4 )
{
int V_6 ;
for (; V_4 > 0 ; ++ V_3 ) {
if ( F_5 ( V_9 >= V_3 -> V_5 ) ) {
V_9 -= V_3 -> V_5 ;
continue;
}
V_6 = F_2 (unsigned int, iov->iov_len - offset, len) ;
if ( F_6 ( V_3 -> V_7 + V_9 , V_1 , V_6 ) )
return - V_8 ;
V_9 = 0 ;
V_1 += V_6 ;
V_4 -= V_6 ;
}
return 0 ;
}
int F_7 ( unsigned char * V_1 , const struct V_2 * V_3 ,
int V_9 , int V_4 )
{
if ( V_4 == 0 )
return 0 ;
while ( V_9 >= V_3 -> V_5 ) {
V_9 -= V_3 -> V_5 ;
V_3 ++ ;
}
while ( V_4 > 0 ) {
T_1 T_2 * V_10 = V_3 -> V_7 + V_9 ;
int V_6 = F_2 (unsigned int, len, iov->iov_len - offset) ;
V_9 = 0 ;
if ( F_3 ( V_1 , V_10 , V_6 ) )
return - V_8 ;
V_4 -= V_6 ;
V_1 += V_6 ;
V_3 ++ ;
}
return 0 ;
}
