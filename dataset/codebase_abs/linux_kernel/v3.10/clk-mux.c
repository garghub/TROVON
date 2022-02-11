static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 -> V_6 ) ;
T_2 V_7 ;
V_7 = F_4 ( V_4 -> V_8 ) >> V_4 -> V_9 ;
V_7 &= V_4 -> V_10 ;
if ( V_4 -> V_11 ) {
int V_12 ;
for ( V_12 = 0 ; V_12 < V_5 ; V_12 ++ )
if ( V_4 -> V_11 [ V_12 ] == V_7 )
return V_12 ;
return - V_13 ;
}
if ( V_7 && ( V_4 -> V_14 & V_15 ) )
V_7 = F_5 ( V_7 ) - 1 ;
if ( V_7 && ( V_4 -> V_14 & V_16 ) )
V_7 -- ;
if ( V_7 >= V_5 )
return - V_13 ;
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_7 ;
unsigned long V_14 = 0 ;
if ( V_4 -> V_11 )
V_17 = V_4 -> V_11 [ V_17 ] ;
else {
if ( V_4 -> V_14 & V_15 )
V_17 = ( 1 << F_5 ( V_17 ) ) ;
if ( V_4 -> V_14 & V_16 )
V_17 ++ ;
}
if ( V_4 -> V_18 )
F_7 ( V_4 -> V_18 , V_14 ) ;
V_7 = F_4 ( V_4 -> V_8 ) ;
V_7 &= ~ ( V_4 -> V_10 << V_4 -> V_9 ) ;
V_7 |= V_17 << V_4 -> V_9 ;
F_8 ( V_7 , V_4 -> V_8 ) ;
if ( V_4 -> V_18 )
F_9 ( V_4 -> V_18 , V_14 ) ;
return 0 ;
}
struct V_6 * F_10 ( struct V_19 * V_20 , const char * V_21 ,
const char * * V_22 , T_1 V_5 , unsigned long V_14 ,
void T_3 * V_8 , T_1 V_9 , T_2 V_10 ,
T_1 V_23 , T_2 * V_11 , T_4 * V_18 )
{
struct V_3 * V_4 ;
struct V_6 * V_6 ;
struct V_24 V_25 ;
V_4 = F_11 ( sizeof( struct V_3 ) , V_26 ) ;
if ( ! V_4 ) {
F_12 ( L_1 , V_27 ) ;
return F_13 ( - V_28 ) ;
}
V_25 . V_21 = V_21 ;
V_25 . V_29 = & V_30 ;
V_25 . V_14 = V_14 | V_31 ;
V_25 . V_22 = V_22 ;
V_25 . V_5 = V_5 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_14 = V_23 ;
V_4 -> V_18 = V_18 ;
V_4 -> V_11 = V_11 ;
V_4 -> V_2 . V_25 = & V_25 ;
V_6 = F_14 ( V_20 , & V_4 -> V_2 ) ;
if ( F_15 ( V_6 ) )
F_16 ( V_4 ) ;
return V_6 ;
}
struct V_6 * F_17 ( struct V_19 * V_20 , const char * V_21 ,
const char * * V_22 , T_1 V_5 , unsigned long V_14 ,
void T_3 * V_8 , T_1 V_9 , T_1 V_32 ,
T_1 V_23 , T_4 * V_18 )
{
T_2 V_10 = F_18 ( V_32 ) - 1 ;
return F_10 ( V_20 , V_21 , V_22 , V_5 ,
V_14 , V_8 , V_9 , V_10 , V_23 ,
NULL , V_18 ) ;
}
