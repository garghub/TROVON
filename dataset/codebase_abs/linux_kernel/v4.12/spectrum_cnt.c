static int F_1 ( struct V_1 * V_1 )
{
unsigned int V_2 = 0 ;
unsigned int V_3 ;
int V_4 ;
V_3 = F_2 ( V_1 -> V_5 , V_6 ) ;
for ( V_4 = 0 ; V_4 < F_3 ( V_7 ) ; V_4 ++ )
V_2 += V_7 [ V_4 ] . V_8 ;
if ( V_2 > V_3 / V_9 + 1 )
return - V_10 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 )
{
struct V_11 * V_12 ;
V_12 = & V_7 [ V_13 ] ;
if ( ! F_5 ( V_1 -> V_5 , V_14 ) )
return - V_15 ;
V_12 -> V_16 = F_2 ( V_1 -> V_5 ,
V_14 ) ;
V_12 = & V_7 [ V_17 ] ;
if ( ! F_5 ( V_1 -> V_5 , V_18 ) )
return - V_15 ;
V_12 -> V_16 = F_2 ( V_1 -> V_5 ,
V_18 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_1 )
{
struct V_11 * V_12 ;
struct V_19 * V_20 ;
unsigned int V_21 ;
unsigned int V_22 ;
int V_4 ;
int V_23 ;
if ( ! F_5 ( V_1 -> V_5 , V_6 ) )
return - V_15 ;
V_23 = F_1 ( V_1 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_4 ( V_1 ) ;
if ( V_23 )
return V_23 ;
V_20 = F_7 ( sizeof( * V_20 ) , V_24 ) ;
if ( ! V_20 )
return - V_25 ;
V_20 -> V_3 = F_2 ( V_1 -> V_5 , V_6 ) ;
V_22 = F_8 ( V_20 -> V_3 ) * sizeof( unsigned long ) ;
V_20 -> V_26 = F_7 ( V_22 , V_24 ) ;
if ( ! V_20 -> V_26 ) {
V_23 = - V_25 ;
goto V_27;
}
V_20 -> V_28 = V_7 ;
V_21 = 0 ;
for ( V_4 = 0 ; V_4 < F_3 ( V_7 ) ; V_4 ++ ) {
V_12 = & V_20 -> V_28 [ V_4 ] ;
V_12 -> V_29 = V_12 -> V_8 *
V_9 ;
V_12 -> V_21 = V_21 ;
V_21 += V_12 -> V_29 ;
if ( V_12 -> V_21 + V_12 -> V_29 > V_20 -> V_3 )
V_12 -> V_29 = V_20 -> V_3 - V_12 -> V_21 ;
}
V_1 -> V_30 = V_20 ;
return 0 ;
V_27:
F_9 ( V_20 ) ;
return V_23 ;
}
void F_10 ( struct V_1 * V_1 )
{
struct V_19 * V_20 = V_1 -> V_30 ;
F_11 ( F_12 ( V_20 -> V_26 , V_20 -> V_3 ) !=
V_20 -> V_3 ) ;
F_9 ( V_20 -> V_26 ) ;
F_9 ( V_20 ) ;
}
int F_13 ( struct V_1 * V_1 ,
enum V_31 V_32 ,
unsigned int * V_33 )
{
struct V_19 * V_20 = V_1 -> V_30 ;
struct V_11 * V_12 ;
unsigned int V_34 ;
unsigned int V_35 ;
int V_4 ;
V_12 = & V_7 [ V_32 ] ;
V_35 = V_12 -> V_21 + V_12 -> V_29 ;
V_34 = V_12 -> V_21 ;
V_34 = F_14 ( V_20 -> V_26 , V_35 , V_34 ) ;
if ( V_34 == V_35 )
return - V_36 ;
if ( V_34 + V_12 -> V_16 > V_35 )
return - V_36 ;
for ( V_4 = 0 ; V_4 < V_12 -> V_16 ; V_4 ++ )
F_15 ( V_34 + V_4 , V_20 -> V_26 ) ;
* V_33 = V_34 ;
return 0 ;
}
void F_16 ( struct V_1 * V_1 ,
enum V_31 V_32 ,
unsigned int V_37 )
{
struct V_19 * V_20 = V_1 -> V_30 ;
struct V_11 * V_12 ;
int V_4 ;
if ( F_11 ( V_37 >= V_20 -> V_3 ) )
return;
V_12 = & V_7 [ V_32 ] ;
for ( V_4 = 0 ; V_4 < V_12 -> V_16 ; V_4 ++ )
F_17 ( V_37 + V_4 , V_20 -> V_26 ) ;
}
