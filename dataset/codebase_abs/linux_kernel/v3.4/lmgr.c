static void
F_1 ( struct V_1 * V_2 , int Error )
{
switch ( Error ) {
case 'C' :
case 'D' :
case 'G' :
case 'H' :
V_2 -> V_3 . V_4 ( V_2 , V_5 | V_6 , NULL ) ;
break;
}
}
static void
F_2 ( struct V_1 * V_2 , int V_7 , void * V_8 )
{
long V_9 ;
switch ( V_7 ) {
case ( V_5 | V_10 ) :
V_9 = ( long ) V_8 ;
F_3 ( V_2 -> V_11 . V_12 , L_1 ,
L_2 , ( char ) V_9 ,
F_4 ( V_13 , & V_2 -> V_3 . V_14 ) ?
L_3 : L_4 ) ;
if ( F_4 ( V_13 , & V_2 -> V_3 . V_14 ) )
F_1 ( V_2 , V_9 ) ;
break;
}
}
void
F_5 ( struct V_1 * V_2 )
{
V_2 -> V_15 . V_16 = F_2 ;
}
