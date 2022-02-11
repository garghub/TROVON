void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
for (; V_2 -> V_5 < 12 ; V_2 -> V_5 ++ )
V_2 -> V_6 [ V_2 -> V_5 ] = 0 ;
F_2 ( V_2 , V_4 ) ;
}
void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
for (; V_2 -> V_5 < 12 ; V_2 -> V_5 ++ )
V_2 -> V_6 [ V_2 -> V_5 ] = 0 ;
V_2 -> V_5 = 12 ;
switch ( V_2 -> V_6 [ 0 ] ) {
case V_7 :
V_2 -> V_6 [ 4 ] = 36 ;
break;
case V_8 :
V_2 -> V_6 [ 7 ] = 0 ;
V_2 -> V_6 [ 8 ] = 8 ;
break;
case V_9 :
V_2 -> V_6 [ 4 ] = 18 ;
break;
}
F_2 ( V_2 , V_4 ) ;
}
void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_2 , V_4 ) ;
}
unsigned int F_5 ( unsigned char * V_10 ,
unsigned int V_11 , struct V_1 * V_2 , struct V_12 * * V_13 ,
unsigned int * V_14 , enum V_15 V_16 )
{
unsigned int V_17 ;
struct V_12 * V_18 = * V_13 ;
if ( ! V_18 )
V_18 = F_6 ( V_2 ) ;
V_17 = 0 ;
while ( V_17 < V_11 && V_18 ) {
struct V_19 * V_19 = F_7 ( V_18 ) +
( ( V_18 -> V_14 + * V_14 ) >> V_20 ) ;
unsigned int V_21 = ( V_18 -> V_14 + * V_14 ) & ( V_22 - 1 ) ;
unsigned int V_23 = V_18 -> V_24 - * V_14 ;
if ( V_23 > V_11 - V_17 ) {
V_23 = V_11 - V_17 ;
* V_14 += V_23 ;
} else {
* V_14 = 0 ;
V_18 = F_8 ( V_18 ) ;
}
while ( V_23 > 0 ) {
unsigned int V_25 = F_9 ( V_23 , ( unsigned int )
V_22 - V_21 ) ;
unsigned char * V_26 = F_10 ( V_19 ) ;
if ( V_16 == V_27 )
memcpy ( V_26 + V_21 , V_10 + V_17 , V_25 ) ;
else
memcpy ( V_10 + V_17 , V_26 + V_21 , V_25 ) ;
F_11 ( V_19 ) ;
V_21 = 0 ;
++ V_19 ;
V_17 += V_25 ;
V_23 -= V_25 ;
}
}
* V_13 = V_18 ;
return V_17 ;
}
void F_12 ( unsigned char * V_10 ,
unsigned int V_11 , struct V_1 * V_2 )
{
unsigned int V_14 = 0 ;
struct V_12 * V_18 = NULL ;
V_11 = F_9 ( V_11 , F_13 ( V_2 ) ) ;
V_11 = F_5 ( V_10 , V_11 , V_2 , & V_18 , & V_14 ,
V_27 ) ;
if ( V_11 < F_13 ( V_2 ) )
F_14 ( V_2 , F_13 ( V_2 ) - V_11 ) ;
}
