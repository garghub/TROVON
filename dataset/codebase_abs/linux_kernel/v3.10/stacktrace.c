static void F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned long * V_4 = ( unsigned long * ) V_3 ;
unsigned long V_5 ;
while ( ! F_2 ( V_4 ) ) {
V_5 = * V_4 ++ ;
if ( F_3 ( V_5 ) ) {
if ( V_2 -> V_6 > 0 )
V_2 -> V_6 -- ;
else
V_2 -> V_7 [ V_2 -> V_8 ++ ] = V_5 ;
if ( V_2 -> V_8 >= V_2 -> V_9 )
break;
}
}
}
static void F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 , struct V_12 * V_13 )
{
unsigned long V_4 = V_13 -> V_13 [ 29 ] ;
#ifdef F_5
unsigned long V_14 = V_13 -> V_13 [ 31 ] ;
unsigned long V_15 = V_13 -> V_16 ;
if ( V_17 || ! F_3 ( V_15 ) ) {
unsigned long V_18 =
( unsigned long ) F_6 ( V_11 ) ;
if ( V_18 && V_4 >= V_18 &&
V_4 <= V_18 + V_19 - 32 )
F_1 ( V_2 , V_4 ) ;
return;
}
do {
if ( V_2 -> V_6 > 0 )
V_2 -> V_6 -- ;
else
V_2 -> V_7 [ V_2 -> V_8 ++ ] = V_15 ;
if ( V_2 -> V_8 >= V_2 -> V_9 )
break;
V_15 = F_7 ( V_11 , & V_4 , V_15 , & V_14 ) ;
} while ( V_15 );
#else
F_1 ( V_2 , V_4 ) ;
#endif
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_20 , V_2 ) ;
}
void F_9 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
struct V_12 V_21 ;
struct V_12 * V_13 = & V_21 ;
F_10 ( V_2 -> V_8 || ! V_2 -> V_9 ) ;
if ( V_11 != V_20 ) {
V_13 -> V_13 [ 29 ] = V_11 -> V_22 . V_3 ;
V_13 -> V_13 [ 31 ] = 0 ;
V_13 -> V_16 = V_11 -> V_22 . V_23 ;
} else
F_11 ( V_13 ) ;
F_4 ( V_2 , V_11 , V_13 ) ;
}
