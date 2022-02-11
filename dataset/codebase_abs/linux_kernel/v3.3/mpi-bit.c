void F_1 ( T_1 V_1 )
{
for (; V_1 -> V_2 && ! V_1 -> V_3 [ V_1 -> V_2 - 1 ] ; V_1 -> V_2 -- )
;
}
unsigned F_2 ( T_1 V_1 )
{
unsigned V_4 ;
F_1 ( V_1 ) ;
if ( V_1 -> V_2 ) {
T_2 V_5 = V_1 -> V_3 [ V_1 -> V_2 - 1 ] ;
if ( V_5 )
F_3 ( V_4 , V_5 ) ;
else
V_4 = V_6 ;
V_4 = V_6 - V_4 + ( V_1 -> V_2 - 1 ) * V_6 ;
} else
V_4 = 0 ;
return V_4 ;
}
int F_4 ( T_1 V_1 , unsigned V_4 )
{
unsigned V_7 , V_8 ;
T_2 V_9 ;
V_7 = V_4 / V_6 ;
V_8 = V_4 % V_6 ;
if ( V_7 >= V_1 -> V_2 )
return 0 ;
V_9 = V_1 -> V_3 [ V_7 ] ;
return ( V_9 & ( V_10 << V_8 ) ) ? 1 : 0 ;
}
int F_5 ( T_1 V_1 , unsigned V_4 )
{
unsigned V_7 , V_8 ;
V_7 = V_4 / V_6 ;
V_8 = V_4 % V_6 ;
if ( V_7 >= V_1 -> V_2 ) {
if ( V_1 -> V_11 >= V_7 )
if ( F_6 ( V_1 , V_7 + 1 ) < 0 )
return - V_12 ;
V_1 -> V_2 = V_7 + 1 ;
}
V_1 -> V_3 [ V_7 ] |= ( V_10 << V_8 ) ;
return 0 ;
}
int F_7 ( T_1 V_1 , unsigned V_4 )
{
unsigned V_7 , V_8 ;
V_7 = V_4 / V_6 ;
V_8 = V_4 % V_6 ;
if ( V_7 >= V_1 -> V_2 ) {
if ( V_1 -> V_11 >= V_7 )
if ( F_6 ( V_1 , V_7 + 1 ) < 0 )
return - V_12 ;
V_1 -> V_2 = V_7 + 1 ;
}
V_1 -> V_3 [ V_7 ] |= ( V_10 << V_8 ) ;
for ( V_8 ++ ; V_8 < V_6 ; V_8 ++ )
V_1 -> V_3 [ V_7 ] &= ~ ( V_10 << V_8 ) ;
V_1 -> V_2 = V_7 + 1 ;
return 0 ;
}
void F_8 ( T_1 V_1 , unsigned V_4 )
{
unsigned V_7 , V_8 ;
V_7 = V_4 / V_6 ;
V_8 = V_4 % V_6 ;
if ( V_7 >= V_1 -> V_2 )
return;
for (; V_8 < V_6 ; V_8 ++ )
V_1 -> V_3 [ V_7 ] &= ~ ( V_10 << V_8 ) ;
V_1 -> V_2 = V_7 + 1 ;
}
void F_9 ( T_1 V_1 , unsigned V_4 )
{
unsigned V_7 , V_8 ;
V_7 = V_4 / V_6 ;
V_8 = V_4 % V_6 ;
if ( V_7 >= V_1 -> V_2 )
return;
V_1 -> V_3 [ V_7 ] &= ~ ( V_10 << V_8 ) ;
}
int F_10 ( T_1 V_13 , T_1 V_1 , unsigned V_4 )
{
T_3 V_14 ;
T_4 V_15 ;
V_15 = V_1 -> V_2 ;
V_13 -> V_16 = V_1 -> V_16 ;
if ( F_11 ( V_13 , ( V_17 ) V_15 ) < 0 )
return - V_12 ;
V_14 = V_13 -> V_3 ;
if ( V_15 ) {
F_12 ( V_14 , V_1 -> V_3 , V_15 , V_4 ) ;
F_13 ( V_14 , V_15 ) ;
}
V_13 -> V_2 = V_15 ;
return 0 ;
}
int F_14 ( T_1 V_1 , unsigned int V_18 )
{
T_3 V_19 = V_1 -> V_3 ;
int V_4 = V_1 -> V_2 ;
int V_20 ;
if ( ! V_18 || ! V_4 )
return 0 ;
if ( F_11 ( V_1 , V_4 + V_18 ) < 0 )
return - V_12 ;
for ( V_20 = V_4 - 1 ; V_20 >= 0 ; V_20 -- )
V_19 [ V_20 + V_18 ] = V_19 [ V_20 ] ;
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ )
V_19 [ V_20 ] = 0 ;
V_1 -> V_2 += V_18 ;
return 0 ;
}
void F_15 ( T_1 V_1 , unsigned int V_18 )
{
T_3 V_19 = V_1 -> V_3 ;
T_4 V_4 = V_1 -> V_2 ;
unsigned int V_20 ;
if ( V_18 >= V_4 ) {
V_1 -> V_2 = 0 ;
return;
}
for ( V_20 = 0 ; V_20 < V_4 - V_18 ; V_20 ++ )
V_19 [ V_20 ] = V_19 [ V_20 + V_18 ] ;
V_19 [ V_20 ] = 0 ;
V_1 -> V_2 -= V_18 ;
}
