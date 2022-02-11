static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
T_2 V_6 ;
V_6 = F_4 ( V_4 -> V_7 ) >> V_4 -> V_8 ;
V_6 &= V_4 -> V_9 ;
if ( V_4 -> V_10 ) {
int V_11 ;
for ( V_11 = 0 ; V_11 < V_5 ; V_11 ++ )
if ( V_4 -> V_10 [ V_11 ] == V_6 )
return V_11 ;
return - V_12 ;
}
if ( V_6 && ( V_4 -> V_13 & V_14 ) )
V_6 = F_5 ( V_6 ) - 1 ;
if ( V_6 && ( V_4 -> V_13 & V_15 ) )
V_6 -- ;
if ( V_6 >= V_5 )
return - V_12 ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_6 ;
unsigned long V_13 = 0 ;
if ( V_4 -> V_10 )
V_16 = V_4 -> V_10 [ V_16 ] ;
else {
if ( V_4 -> V_13 & V_14 )
V_16 = 1 << V_16 ;
if ( V_4 -> V_13 & V_15 )
V_16 ++ ;
}
if ( V_4 -> V_17 )
F_7 ( V_4 -> V_17 , V_13 ) ;
else
F_8 ( V_4 -> V_17 ) ;
if ( V_4 -> V_13 & V_18 ) {
V_6 = V_4 -> V_9 << ( V_4 -> V_8 + 16 ) ;
} else {
V_6 = F_4 ( V_4 -> V_7 ) ;
V_6 &= ~ ( V_4 -> V_9 << V_4 -> V_8 ) ;
}
V_6 |= V_16 << V_4 -> V_8 ;
F_9 ( V_6 , V_4 -> V_7 ) ;
if ( V_4 -> V_17 )
F_10 ( V_4 -> V_17 , V_13 ) ;
else
F_11 ( V_4 -> V_17 ) ;
return 0 ;
}
struct V_19 * F_12 ( struct V_20 * V_21 , const char * V_22 ,
const char * const * V_23 , T_1 V_5 ,
unsigned long V_13 ,
void T_3 * V_7 , T_1 V_8 , T_2 V_9 ,
T_1 V_24 , T_2 * V_10 , T_4 * V_17 )
{
struct V_3 * V_4 ;
struct V_19 * V_19 ;
struct V_25 V_26 ;
T_1 V_27 = 0 ;
if ( V_24 & V_18 ) {
V_27 = F_13 ( V_9 ) - F_5 ( V_9 ) + 1 ;
if ( V_27 + V_8 > 16 ) {
F_14 ( L_1 ) ;
return F_15 ( - V_12 ) ;
}
}
V_4 = F_16 ( sizeof( struct V_3 ) , V_28 ) ;
if ( ! V_4 ) {
F_14 ( L_2 , V_29 ) ;
return F_15 ( - V_30 ) ;
}
V_26 . V_22 = V_22 ;
if ( V_24 & V_31 )
V_26 . V_32 = & V_33 ;
else
V_26 . V_32 = & V_34 ;
V_26 . V_13 = V_13 | V_35 ;
V_26 . V_23 = V_23 ;
V_26 . V_5 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_13 = V_24 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_2 . V_26 = & V_26 ;
V_19 = F_17 ( V_21 , & V_4 -> V_2 ) ;
if ( F_18 ( V_19 ) )
F_19 ( V_4 ) ;
return V_19 ;
}
struct V_19 * F_20 ( struct V_20 * V_21 , const char * V_22 ,
const char * const * V_23 , T_1 V_5 ,
unsigned long V_13 ,
void T_3 * V_7 , T_1 V_8 , T_1 V_27 ,
T_1 V_24 , T_4 * V_17 )
{
T_2 V_9 = F_21 ( V_27 ) - 1 ;
return F_12 ( V_21 , V_22 , V_23 , V_5 ,
V_13 , V_7 , V_8 , V_9 , V_24 ,
NULL , V_17 ) ;
}
void F_22 ( struct V_19 * V_19 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
V_2 = F_23 ( V_19 ) ;
if ( ! V_2 )
return;
V_4 = F_2 ( V_2 ) ;
F_24 ( V_19 ) ;
F_19 ( V_4 ) ;
}
