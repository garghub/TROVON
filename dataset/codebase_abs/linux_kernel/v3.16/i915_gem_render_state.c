static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_5 ;
int V_6 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_7 ) ;
if ( ! V_4 )
return F_3 ( - V_8 ) ;
V_4 -> V_9 = F_4 ( V_3 , 4096 ) ;
if ( V_4 -> V_9 == NULL ) {
V_6 = - V_8 ;
goto free;
}
V_4 -> V_10 = 4096 ;
V_6 = F_5 ( V_4 -> V_9 , 4096 , 0 ) ;
if ( V_6 )
goto V_11;
F_6 ( V_4 -> V_9 -> V_12 -> V_13 != 1 ) ;
V_5 = F_7 ( V_4 -> V_9 -> V_12 -> V_14 ) ;
V_4 -> V_15 = F_8 ( V_5 ) ;
if ( ! V_4 -> V_15 ) {
V_6 = - V_8 ;
goto V_16;
}
V_4 -> V_17 = F_9 ( V_4 -> V_9 ) ;
return V_4 ;
V_16:
F_10 ( V_4 -> V_9 ) ;
V_11:
F_11 ( & V_4 -> V_9 -> V_18 ) ;
free:
F_12 ( V_4 ) ;
return F_3 ( V_6 ) ;
}
static void F_13 ( struct V_1 * V_4 )
{
F_14 ( F_15 ( V_4 -> V_15 ) ) ;
F_10 ( V_4 -> V_9 ) ;
F_11 ( & V_4 -> V_9 -> V_18 ) ;
F_12 ( V_4 ) ;
}
static const struct V_19 *
F_16 ( struct V_2 * V_3 , const int V_20 )
{
switch ( V_20 ) {
case 6 :
return & V_21 ;
case 7 :
return & V_22 ;
case 8 :
return & V_23 ;
}
return NULL ;
}
static int F_17 ( const int V_20 ,
const struct V_19 * V_24 ,
struct V_1 * V_4 )
{
const T_1 V_25 = F_9 ( V_4 -> V_9 ) ;
T_2 V_26 = 0 ;
T_2 * const V_27 = V_4 -> V_15 ;
unsigned int V_28 = 0 ;
int V_6 ;
if ( ! V_24 || V_24 -> V_29 * 4 > V_4 -> V_10 )
return - V_30 ;
V_6 = F_18 ( V_4 -> V_9 , true ) ;
if ( V_6 )
return V_6 ;
while ( V_28 < V_24 -> V_29 ) {
T_2 V_31 = V_24 -> V_15 [ V_28 ] ;
if ( V_26 < V_24 -> V_32 &&
V_28 * 4 == V_24 -> V_33 [ V_26 ] ) {
V_31 += V_25 & 0xffffffff ;
if ( V_20 >= 8 ) {
if ( V_28 + 1 >= V_24 -> V_29 ||
V_24 -> V_15 [ V_28 + 1 ] != 0 )
return - V_30 ;
V_27 [ V_28 ] = V_31 ;
V_28 ++ ;
V_31 = ( V_25 & 0xffffffff00000000ull ) >> 32 ;
}
V_26 ++ ;
}
V_27 [ V_28 ] = V_31 ;
V_28 ++ ;
}
V_6 = F_19 ( V_4 -> V_9 , false ) ;
if ( V_6 )
return V_6 ;
if ( V_24 -> V_32 != V_26 ) {
F_20 ( L_1 ,
V_26 , V_24 -> V_32 ) ;
return - V_30 ;
}
V_4 -> V_34 = V_24 -> V_29 * 4 ;
return 0 ;
}
int F_21 ( struct V_35 * V_36 )
{
const int V_20 = F_22 ( V_36 -> V_3 ) -> V_20 ;
struct V_1 * V_4 ;
const struct V_19 * V_24 ;
int V_6 ;
if ( F_23 ( V_36 -> V_37 != V_38 ) )
return - V_39 ;
V_24 = F_16 ( V_36 -> V_3 , V_20 ) ;
if ( V_24 == NULL )
return 0 ;
V_4 = F_1 ( V_36 -> V_3 ) ;
if ( F_24 ( V_4 ) )
return F_25 ( V_4 ) ;
V_6 = F_17 ( V_20 , V_24 , V_4 ) ;
if ( V_6 )
goto V_40;
V_6 = V_36 -> V_41 ( V_36 ,
F_9 ( V_4 -> V_9 ) ,
V_4 -> V_34 ,
V_42 ) ;
if ( V_6 )
goto V_40;
F_26 ( F_27 ( V_4 -> V_9 ) , V_36 ) ;
V_6 = F_28 ( V_36 , NULL , V_4 -> V_9 , NULL ) ;
V_40:
F_13 ( V_4 ) ;
return V_6 ;
}
