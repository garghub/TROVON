int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 , V_6 ;
int V_7 ;
int V_8 ;
int V_9 , V_10 ;
if ( V_2 -> V_11 ) {
V_10 = V_4 ;
V_4 = V_2 -> V_11 ;
} else {
V_10 = 0 ;
if ( V_4 == 0 )
V_4 = 1 ;
}
V_8 = V_4 - 1 ;
if ( ( V_4 & V_8 ) != 0 )
F_2 () ;
if ( V_4 < 0 || V_4 >= V_2 -> V_12 )
F_2 () ;
if ( V_3 <= 0 || V_3 > V_2 -> V_12 )
F_2 () ;
V_10 &= V_8 ;
F_3 ( & V_2 -> V_13 ) ;
if ( V_3 < V_2 -> V_14 )
V_5 = V_2 -> V_15 ;
else
V_5 = V_2 -> V_16 & ~ V_8 ;
V_6 = 0 ;
for (; ; ) {
V_7 = F_4 ( V_2 -> V_17 , V_2 -> V_12 , V_5 ) ;
V_7 = ( ( V_7 + V_8 ) & ~ V_8 ) + V_10 ;
V_6 += V_7 - V_5 ;
V_5 = V_7 ;
if ( V_5 >= V_2 -> V_12 )
V_5 = 0 ;
if ( V_6 + V_3 > V_2 -> V_12 ) {
F_5 ( & V_2 -> V_13 ) ;
F_6 ( V_18
L_1 ,
V_2 -> V_12 , V_2 -> V_19 , V_5 , V_3 , V_4 , V_6 ) ;
return - 1 ;
}
if ( V_5 + V_3 > V_2 -> V_12 ) {
V_6 += V_2 -> V_12 - V_5 ;
V_5 = 0 ;
continue;
}
V_9 = 0 ;
while ( F_7 ( V_5 + V_9 , V_2 -> V_17 ) == 0 ) {
V_9 ++ ;
if ( V_9 == V_3 ) {
F_8 ( V_2 -> V_17 , V_5 , V_3 ) ;
if ( V_5 == V_2 -> V_15 )
V_2 -> V_15 = F_4
( V_2 -> V_17 , V_2 -> V_12 ,
V_2 -> V_15 + V_3 ) ;
if ( ( V_2 -> V_16 = V_5 + V_3 ) >= V_2 -> V_12 )
V_2 -> V_16 = 0 ;
V_2 -> V_19 += V_3 ;
V_2 -> V_14 = V_3 ;
F_5 ( & V_2 -> V_13 ) ;
return V_5 ;
}
}
V_6 += V_9 + 1 ;
if ( ( V_5 += V_9 + 1 ) >= V_2 -> V_12 )
V_5 = 0 ;
}
}
void F_9 ( struct V_1 * V_2 , int V_5 , int V_3 )
{
int V_9 ;
if ( V_2 -> V_19 < V_3 )
F_2 () ;
F_3 ( & V_2 -> V_13 ) ;
for ( V_9 = 0 ; V_9 < V_3 ; V_9 ++ ) {
if ( F_7 ( V_5 + V_9 , V_2 -> V_17 ) == 0 )
F_2 () ;
F_10 ( V_5 + V_9 , V_2 -> V_17 ) ;
}
if ( V_5 < V_2 -> V_15 )
V_2 -> V_15 = V_5 ;
V_2 -> V_19 -= V_3 ;
F_5 ( & V_2 -> V_13 ) ;
}
void F_11 ( struct V_1 * V_2 , unsigned long * V_17 , int V_12 )
{
if ( ( V_12 & 07 ) != 0 )
F_2 () ;
memset ( V_17 , 0 , V_12 >> 3 ) ;
memset ( V_2 , 0 , sizeof *V_2 ) ;
F_12 ( & V_2 -> V_13 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_12 = V_12 ;
}
