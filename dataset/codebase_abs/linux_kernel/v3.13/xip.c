static inline int
F_1 ( struct V_1 * V_1 , T_1 V_2 ,
void * * V_3 , unsigned long * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 -> V_8 ;
const struct V_9 * V_10 = V_6 -> V_11 -> V_12 ;
T_1 V_13 ;
V_13 = V_2 * ( V_14 / 512 ) ;
F_2 ( ! V_10 -> V_15 ) ;
return V_10 -> V_15 ( V_6 , V_13 , V_3 , V_4 ) ;
}
static inline int
F_3 ( struct V_1 * V_1 , T_2 V_16 , int V_17 ,
T_1 * V_18 )
{
struct V_19 V_20 ;
int V_21 ;
memset ( & V_20 , 0 , sizeof( struct V_19 ) ) ;
V_20 . V_22 = 1 << V_1 -> V_23 ;
V_21 = F_4 ( V_1 , V_16 , & V_20 , V_17 ) ;
* V_18 = V_20 . V_24 ;
if ( ! V_20 . V_24 && ! V_21 ) {
F_2 ( V_17 ) ;
V_21 = - V_25 ;
}
return V_21 ;
}
int
F_5 ( struct V_1 * V_1 , T_1 V_2 )
{
void * V_3 ;
unsigned long V_4 ;
int V_21 ;
V_21 = F_1 ( V_1 , V_2 , & V_3 , & V_4 ) ;
if ( ! V_21 )
F_6 ( V_3 ) ;
return V_21 ;
}
void F_7 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_8 ( V_27 ) ;
if ( ( V_29 -> V_30 & V_31 ) &&
! V_27 -> V_8 -> V_11 -> V_12 -> V_15 ) {
V_29 -> V_30 &= ( ~ V_31 ) ;
F_9 ( V_27 , V_32 ,
L_1
L_2 ) ;
}
}
int F_10 ( struct V_33 * V_34 , T_2 V_16 , int V_17 ,
void * * V_35 , unsigned long * V_4 )
{
int V_21 ;
T_1 V_2 ;
V_21 = F_3 ( V_34 -> V_36 , V_16 , V_17 , & V_2 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_1 ( V_34 -> V_36 , V_2 , V_35 , V_4 ) ;
return V_21 ;
}
