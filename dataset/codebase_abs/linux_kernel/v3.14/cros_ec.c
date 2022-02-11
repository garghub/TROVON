int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 * V_5 ;
int V_6 , V_7 ;
F_2 ( V_4 -> V_8 > V_9 ) ;
V_5 = V_2 -> V_10 ;
V_5 [ 0 ] = V_11 + V_4 -> V_12 ;
V_5 [ 1 ] = V_4 -> V_13 ;
V_5 [ 2 ] = V_4 -> V_8 ;
V_6 = V_5 [ 0 ] + V_5 [ 1 ] + V_5 [ 2 ] ;
for ( V_7 = 0 ; V_7 < V_4 -> V_8 ; V_7 ++ )
V_6 += V_5 [ V_14 + V_7 ] = V_4 -> V_15 [ V_7 ] ;
V_5 [ V_14 + V_4 -> V_8 ] = ( T_1 ) ( V_6 & 0xff ) ;
return V_16 + V_4 -> V_8 ;
}
static int F_3 ( struct V_1 * V_2 ,
T_2 V_13 , void * V_15 , int V_8 ,
void * V_17 , int V_18 )
{
struct V_3 V_4 ;
V_4 . V_12 = V_13 >> 8 ;
V_4 . V_13 = V_13 & 0xff ;
V_4 . V_15 = V_15 ;
V_4 . V_8 = V_8 ;
V_4 . V_17 = V_17 ;
V_4 . V_18 = V_18 ;
return V_2 -> V_19 ( V_2 , & V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
T_2 V_13 , void * V_20 , int V_21 )
{
return F_3 ( V_2 , V_13 , NULL , 0 , V_20 , V_21 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
T_2 V_13 , void * V_20 , int V_21 )
{
return F_3 ( V_2 , V_13 , V_20 , V_21 , NULL , 0 ) ;
}
static T_3 F_6 ( int V_22 , void * V_23 )
{
struct V_1 * V_2 = V_23 ;
if ( F_7 ( V_2 -> V_24 ) )
F_8 ( V_2 -> V_24 , 0 ) ;
F_9 ( & V_2 -> V_25 , 1 , V_2 ) ;
return V_26 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_27 * V_24 = V_2 -> V_24 ;
int V_28 = 0 ;
F_11 ( & V_2 -> V_25 ) ;
V_2 -> V_29 = F_5 ;
V_2 -> V_30 = F_4 ;
V_2 -> V_31 = F_3 ;
if ( V_2 -> V_32 ) {
V_2 -> V_33 = F_12 ( V_24 , V_2 -> V_32 , V_34 ) ;
if ( ! V_2 -> V_33 )
return - V_35 ;
}
if ( V_2 -> V_36 ) {
V_2 -> V_10 = F_12 ( V_24 , V_2 -> V_36 , V_34 ) ;
if ( ! V_2 -> V_10 )
return - V_35 ;
}
if ( ! V_2 -> V_22 ) {
F_13 ( V_24 , L_1 , V_2 -> V_22 ) ;
return V_28 ;
}
V_28 = F_14 ( V_2 -> V_22 , NULL , F_6 ,
V_37 | V_38 ,
L_2 , V_2 ) ;
if ( V_28 ) {
F_15 ( V_24 , L_3 , V_2 -> V_22 , V_28 ) ;
return V_28 ;
}
V_28 = F_16 ( V_24 , 0 , V_39 ,
F_17 ( V_39 ) ,
NULL , V_2 -> V_22 , NULL ) ;
if ( V_28 ) {
F_15 ( V_24 , L_4 ) ;
goto V_40;
}
F_18 ( V_24 , L_5 , V_2 -> V_41 ) ;
return 0 ;
V_40:
F_19 ( V_2 -> V_22 , V_2 ) ;
return V_28 ;
}
int F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_24 ) ;
F_19 ( V_2 -> V_22 , V_2 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_27 * V_24 = V_2 -> V_24 ;
if ( F_7 ( V_24 ) )
V_2 -> V_42 = ! F_23 ( V_2 -> V_22 ) ;
F_24 ( V_2 -> V_22 ) ;
V_2 -> V_43 = V_2 -> V_42 ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_22 ) ;
if ( V_2 -> V_42 ) {
F_27 ( V_2 -> V_22 ) ;
V_2 -> V_42 = 0 ;
}
return 0 ;
}
