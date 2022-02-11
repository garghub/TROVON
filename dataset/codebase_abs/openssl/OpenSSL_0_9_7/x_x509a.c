int F_1 ( T_1 * V_1 , unsigned char * V_2 , int V_3 )
{
T_2 * V_4 ;
if( ! ( V_4 = F_2 ( V_1 ) ) ) return 0 ;
if( ! V_4 -> V_5 && ! ( V_4 -> V_5 = F_3 () ) ) return 0 ;
return F_4 ( V_4 -> V_5 , V_2 , V_3 ) ;
}
unsigned char * F_5 ( T_1 * V_1 , int * V_3 )
{
if( ! V_1 -> V_4 || ! V_1 -> V_4 -> V_6 ) return NULL ;
if( V_3 ) * V_3 = V_1 -> V_4 -> V_6 -> V_7 ;
return V_1 -> V_4 -> V_6 -> V_8 ;
}
int F_6 ( T_1 * V_1 , T_3 * V_9 )
{
T_2 * V_4 ;
T_3 * V_10 ;
if( ! ( V_10 = F_7 ( V_9 ) ) ) return 0 ;
if( ! ( V_4 = F_2 ( V_1 ) ) ) return 0 ;
if( ! V_4 -> V_11
&& ! ( V_4 -> V_11 = F_8 () ) ) return 0 ;
return F_9 ( V_4 -> V_11 , V_10 ) ;
}
int F_10 ( T_1 * V_1 , T_3 * V_9 )
{
T_2 * V_4 ;
T_3 * V_10 ;
if( ! ( V_10 = F_7 ( V_9 ) ) ) return 0 ;
if( ! ( V_4 = F_2 ( V_1 ) ) ) return 0 ;
if( ! V_4 -> V_12
&& ! ( V_4 -> V_12 = F_8 () ) ) return 0 ;
return F_9 ( V_4 -> V_12 , V_10 ) ;
}
void F_11 ( T_1 * V_1 )
{
if( V_1 -> V_4 && V_1 -> V_4 -> V_11 ) {
F_12 ( V_1 -> V_4 -> V_11 , V_13 ) ;
V_1 -> V_4 -> V_11 = NULL ;
}
}
void F_13 ( T_1 * V_1 )
{
if( V_1 -> V_4 && V_1 -> V_4 -> V_12 ) {
F_12 ( V_1 -> V_4 -> V_12 , V_13 ) ;
V_1 -> V_4 -> V_12 = NULL ;
}
}
