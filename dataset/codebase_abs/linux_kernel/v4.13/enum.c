const struct V_1 *
F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
while ( V_2 -> V_4 ) {
if ( V_2 -> V_3 == V_3 )
return V_2 ;
V_2 ++ ;
}
return NULL ;
}
void
F_2 ( char * V_5 , int V_6 , const struct V_7 * V_8 , T_1 V_3 )
{
bool V_9 = false ;
while ( V_6 >= 1 && V_8 -> V_4 ) {
if ( V_3 & V_8 -> V_10 ) {
int V_11 = snprintf ( V_5 , V_6 , L_1 ,
V_9 ? L_2 : L_3 , V_8 -> V_4 ) ;
V_6 -= V_11 ;
V_5 += V_11 ;
V_9 = true ;
}
V_8 ++ ;
}
V_5 [ 0 ] = '\0' ;
}
