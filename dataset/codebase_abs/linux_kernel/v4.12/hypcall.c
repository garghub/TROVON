enum V_1 F_1 ( struct V_2 * V_3 ,
union V_4 V_5 )
{
unsigned int V_6 = ( V_5 . V_7 . V_6 >> 5 ) & 0x3ff ;
F_2 ( L_1 , V_3 -> V_8 . V_9 , V_6 ) ;
switch ( V_6 ) {
case 0 :
return V_10 ;
default:
return V_11 ;
} ;
}
static int F_3 ( struct V_2 * V_3 , unsigned long V_12 ,
const unsigned long * args , unsigned long * V_13 )
{
* V_13 = - V_14 ;
return V_15 ;
}
int F_4 ( struct V_2 * V_3 )
{
unsigned long V_12 , args [ V_16 ] ;
V_12 = V_3 -> V_8 . V_17 [ 2 ] ;
args [ 0 ] = V_3 -> V_8 . V_17 [ 4 ] ;
args [ 1 ] = V_3 -> V_8 . V_17 [ 5 ] ;
args [ 2 ] = V_3 -> V_8 . V_17 [ 6 ] ;
args [ 3 ] = V_3 -> V_8 . V_17 [ 7 ] ;
return F_3 ( V_3 , V_12 ,
args , & V_3 -> V_8 . V_17 [ 2 ] ) ;
}
