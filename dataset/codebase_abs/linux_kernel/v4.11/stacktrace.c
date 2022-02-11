static void F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , int V_4 )
{
unsigned long * V_5 = ( unsigned long * ) V_3 ;
unsigned long V_6 ;
while ( ! F_2 ( V_5 ) ) {
V_6 = * V_5 ++ ;
if ( F_3 ( V_6 ) &&
( V_4 || ! F_4 ( V_6 ) ) ) {
if ( V_2 -> V_7 > 0 )
V_2 -> V_7 -- ;
else
V_2 -> V_8 [ V_2 -> V_9 ++ ] = V_6 ;
if ( V_2 -> V_9 >= V_2 -> V_10 )
break;
}
}
}
static void F_5 ( struct V_1 * V_2 ,
struct V_11 * V_12 , struct V_13 * V_14 , int V_4 )
{
unsigned long V_5 = V_14 -> V_14 [ 29 ] ;
#ifdef F_6
unsigned long V_15 = V_14 -> V_14 [ 31 ] ;
unsigned long V_16 = V_14 -> V_17 ;
if ( V_18 || ! F_3 ( V_16 ) ) {
unsigned long V_19 =
( unsigned long ) F_7 ( V_12 ) ;
if ( V_19 && V_5 >= V_19 &&
V_5 <= V_19 + V_20 - 32 )
F_1 ( V_2 , V_5 , V_4 ) ;
return;
}
do {
if ( V_4 || ! F_4 ( V_16 ) ) {
if ( V_2 -> V_7 > 0 )
V_2 -> V_7 -- ;
else
V_2 -> V_8 [ V_2 -> V_9 ++ ] = V_16 ;
if ( V_2 -> V_9 >= V_2 -> V_10 )
break;
}
V_16 = F_8 ( V_12 , & V_5 , V_16 , & V_15 ) ;
} while ( V_16 );
#else
F_1 ( V_2 , V_5 , V_4 ) ;
#endif
}
void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_21 , V_2 ) ;
}
void F_10 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_13 V_22 ;
struct V_13 * V_14 = & V_22 ;
F_11 ( V_2 -> V_9 || ! V_2 -> V_10 ) ;
if ( V_12 != V_21 ) {
V_14 -> V_14 [ 29 ] = V_12 -> V_23 . V_3 ;
V_14 -> V_14 [ 31 ] = 0 ;
V_14 -> V_17 = V_12 -> V_23 . V_24 ;
} else
F_12 ( V_14 ) ;
F_5 ( V_2 , V_12 , V_14 , V_12 == V_21 ) ;
}
