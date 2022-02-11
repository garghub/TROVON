struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return V_5 -> V_6 ;
}
static int F_3 ( struct V_2 * V_3 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_4 ( V_8 , V_5 -> V_6 , V_9 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_6 ( V_3 ) ;
F_7 ( V_5 -> V_6 ) ;
F_8 ( V_5 ) ;
}
static struct V_4 * F_9 ( struct V_10 * V_11 ,
const struct V_12 * V_13 ,
struct V_1 * V_14 )
{
struct V_4 * V_5 ;
int V_15 ;
if ( F_10 ( V_13 -> V_16 ) != 1 )
return F_11 ( - V_17 ) ;
V_5 = F_12 ( sizeof( * V_5 ) , V_18 ) ;
if ( ! V_5 )
return F_11 ( - V_19 ) ;
F_13 ( & V_5 -> V_20 , V_13 ) ;
V_5 -> V_6 = V_14 ;
V_15 = F_14 ( V_11 , & V_5 -> V_20 , & V_21 ) ;
if ( V_15 ) {
F_15 ( L_1 ) ;
F_8 ( V_5 ) ;
return F_11 ( V_15 ) ;
}
return V_5 ;
}
int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_22 ;
struct V_23 * V_24 ;
long V_15 ;
if ( ! V_3 )
return 0 ;
V_22 = F_1 ( V_3 ) ;
if ( ! V_22 || ! V_22 -> V_25 || ! V_22 -> V_25 -> V_24 )
return 0 ;
V_24 = V_22 -> V_25 -> V_24 ;
V_15 = F_17 ( V_24 , false , true ,
V_26 ) ;
if ( F_18 ( V_15 < 0 ) )
return V_15 ;
return 0 ;
}
struct V_2 * F_19 ( struct V_10 * V_11 ,
struct V_7 * V_27 ,
const struct V_12 * V_28 )
{
struct V_4 * V_5 ;
struct V_1 * V_22 ;
unsigned int V_29 = V_28 -> V_29 ;
unsigned int V_30 = V_28 -> V_30 ;
unsigned int V_31 , V_32 ;
int V_15 ;
if ( F_10 ( V_28 -> V_16 ) != 1 )
return F_11 ( - V_17 ) ;
V_22 = F_20 ( V_27 , V_28 -> V_33 [ 0 ] ) ;
if ( ! V_22 )
return F_11 ( - V_34 ) ;
V_32 = F_21 ( V_28 -> V_16 , 0 ) ;
V_31 = ( V_30 - 1 ) * V_28 -> V_35 [ 0 ] + V_29 * V_32 ;
V_31 += V_28 -> V_36 [ 0 ] ;
if ( V_22 -> V_31 < V_31 ) {
V_15 = - V_17 ;
goto V_37;
}
V_5 = F_9 ( V_11 , V_28 , V_22 ) ;
if ( F_22 ( V_5 ) ) {
V_15 = F_23 ( V_5 ) ;
goto V_37;
}
return & V_5 -> V_20 ;
V_37:
F_7 ( V_22 ) ;
return F_11 ( V_15 ) ;
}
