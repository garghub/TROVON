static void F_1 ( unsigned long T_1 * V_1 , unsigned int V_2 )
{
while ( V_2 -- && F_2 ( V_3 , V_1 , 8 ) ) {
unsigned long V_4 ;
unsigned long T_1 * V_5 ;
if ( F_3 ( & V_4 , V_1 + 1 , sizeof( V_4 ) ) )
break;
V_4 -= 4 ;
F_4 ( V_4 ) ;
if ( F_3 ( & V_5 , V_1 + 0 , sizeof( V_5 ) ) )
break;
if ( V_5 >= V_1 )
break;
V_1 = V_5 ;
}
}
static int F_5 ( struct V_6 * V_7 , void * V_8 )
{
unsigned int * V_2 = V_8 ;
F_4 ( V_7 -> V_9 ) ;
if ( ( * V_2 ) -- == 0 )
return 1 ;
return 0 ;
}
void F_6 ( struct V_10 * const V_11 , unsigned int V_2 )
{
if ( F_7 ( V_11 ) ) {
unsigned long * V_1 = ( unsigned long * ) V_11 -> V_12 . V_13 [ 1 ] . V_14 ;
F_1 ( ( unsigned long T_1 V_15 * ) V_1 , V_2 ) ;
} else {
struct V_6 V_7 ;
V_7 . V_1 = V_11 -> V_12 . V_13 [ 1 ] . V_14 ;
V_7 . V_16 = F_8 ( V_11 ) ;
V_7 . V_17 = 0 ;
V_7 . V_9 = V_11 -> V_12 . V_18 ;
F_9 ( & V_7 , & F_5 , & V_2 ) ;
}
}
