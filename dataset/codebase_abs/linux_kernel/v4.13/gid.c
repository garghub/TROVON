void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_2 , V_4 ) ;
F_3 ( & V_2 -> V_5 . V_6 . V_7 ) ;
V_2 -> V_5 . V_6 . V_8 = V_3 ;
V_2 -> V_5 . V_6 . V_9 = 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( ! F_6 ( & V_2 -> V_5 . V_6 . V_7 ) ) ;
V_2 -> V_5 . V_6 . V_8 = 0 ;
V_2 -> V_5 . V_6 . V_9 = 0 ;
F_7 ( & V_2 -> V_5 . V_6 . V_7 ) ;
}
int F_8 ( struct V_1 * V_2 , unsigned int V_9 )
{
if ( F_9 ( V_10 , & V_2 -> V_11 ) ) {
F_10 ( V_2 , L_1 ) ;
return - V_12 ;
}
if ( V_2 -> V_5 . V_6 . V_8 < V_9 ) {
F_11 ( V_2 , L_2 ,
V_9 ) ;
return - V_13 ;
}
if ( V_2 -> V_5 . V_6 . V_9 + V_9 > V_14 ) {
F_11 ( V_2 , L_3 , V_9 ) ;
return - V_13 ;
}
V_2 -> V_5 . V_6 . V_8 -= V_9 ;
V_2 -> V_5 . V_6 . V_9 += V_9 ;
F_12 ( V_2 , L_4 ,
V_2 -> V_5 . V_6 . V_9 ,
V_2 -> V_5 . V_6 . V_8 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 , unsigned int V_9 )
{
F_14 ( F_9 ( V_10 , & V_2 -> V_11 ) , L_5 ) ;
F_14 ( V_9 > V_2 -> V_5 . V_6 . V_9 , L_6 ,
V_9 , V_2 -> V_5 . V_6 . V_9 ) ;
V_2 -> V_5 . V_6 . V_8 += V_9 ;
V_2 -> V_5 . V_6 . V_9 -= V_9 ;
F_12 ( V_2 , L_7 ,
V_2 -> V_5 . V_6 . V_9 ,
V_2 -> V_5 . V_6 . V_8 ) ;
}
int F_15 ( struct V_1 * V_2 , int * V_15 )
{
int V_16 = V_2 -> V_5 . V_6 . V_8 +
V_2 -> V_5 . V_6 . V_9 ;
int V_17 = 0 ;
V_17 = F_16 ( & V_2 -> V_5 . V_6 . V_7 ,
V_2 -> V_5 . V_6 . V_8 , V_16 ,
V_18 ) ;
if ( V_17 < 0 )
return V_17 ;
F_12 ( V_2 , L_8 , V_17 ) ;
* V_15 = V_17 ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 , int V_15 )
{
F_12 ( V_2 , L_9 , V_15 ) ;
F_18 ( & V_2 -> V_5 . V_6 . V_7 , V_15 ) ;
}
unsigned int F_19 ( struct V_1 * V_2 )
{
return V_2 -> V_5 . V_6 . V_9 ;
}
int F_20 ( struct V_1 * V_2 , unsigned int V_17 ,
T_1 V_19 , T_1 V_20 , const T_1 * V_21 ,
const T_1 * V_22 , bool V_23 , T_2 V_24 )
{
#define F_21 ( T_3 , T_4 , T_5 ) MLX5_SET(roce_addr_layout, p, f, v)
T_6 V_25 [ F_22 ( V_26 ) ] = { 0 } ;
T_6 V_27 [ F_22 ( V_28 ) ] = { 0 } ;
void * V_29 = F_23 ( V_26 , V_25 , V_30 ) ;
char * V_31 = F_23 ( V_32 , V_29 ,
V_33 ) ;
void * V_34 = F_23 ( V_32 , V_29 ,
V_35 ) ;
int V_36 = F_24 ( V_32 , V_33 ) ;
if ( F_25 ( V_2 , V_37 ) != V_38 )
return - V_39 ;
if ( V_21 ) {
if ( V_23 ) {
F_21 ( V_29 , V_40 , 1 ) ;
F_21 ( V_29 , V_24 , V_24 ) ;
}
F_26 ( V_34 , V_22 ) ;
F_21 ( V_29 , V_19 , V_19 ) ;
F_21 ( V_29 , V_20 , V_20 ) ;
memcpy ( V_31 , V_21 , V_36 ) ;
}
F_27 ( V_26 , V_25 , V_41 , V_17 ) ;
F_27 ( V_26 , V_25 , V_42 , V_43 ) ;
return F_28 ( V_2 , V_25 , sizeof( V_25 ) , V_27 , sizeof( V_27 ) ) ;
}
