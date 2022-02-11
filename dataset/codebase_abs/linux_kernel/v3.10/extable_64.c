static const struct V_1 * F_1 ( unsigned long V_2 )
{
if ( ( V_2 >= ( unsigned long ) & V_3 ) &&
( V_2 <= ( unsigned long ) & V_4 ) )
return & V_5 ;
return NULL ;
}
const struct V_1 *
F_2 ( const struct V_1 * V_6 ,
const struct V_1 * V_7 ,
unsigned long V_8 )
{
const struct V_1 * V_9 ;
V_9 = F_1 ( V_8 ) ;
if ( V_9 )
return V_9 ;
while ( V_6 <= V_7 ) {
long V_10 ;
V_9 = ( V_7 - V_6 ) / 2 + V_6 ;
V_10 = V_9 -> V_11 - V_8 ;
if ( V_10 == 0 )
return V_9 ;
else if ( V_10 < 0 )
V_6 = V_9 + 1 ;
else
V_7 = V_9 - 1 ;
}
return NULL ;
}
int F_3 ( struct V_12 * V_13 )
{
const struct V_1 * V_14 ;
V_14 = F_4 ( V_13 -> V_15 ) ;
if ( V_14 ) {
V_13 -> V_15 = V_14 -> V_14 ;
return 1 ;
}
return 0 ;
}
