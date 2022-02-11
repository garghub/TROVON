static inline void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
unsigned long V_4 = V_3 >> V_5 ;
if( V_4 != V_6 ) {
F_2 ( V_4 | V_7 , V_8 ) ;
V_6 = V_4 ;
}
}
static T_1 F_3 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 V_9 ;
F_4 ( & V_10 ) ;
F_1 ( V_2 , V_3 ) ;
V_9 . V_11 [ 0 ] = F_5 ( V_12 + ( V_3 & V_13 ) ) ;
F_6 ( & V_10 ) ;
return V_9 ;
}
static void F_7 ( struct V_1 * V_2 , void * V_14 , unsigned long V_15 , T_2 V_16 )
{
while( V_16 ) {
unsigned long V_17 = V_16 ;
if ( V_16 > ( V_18 - ( V_15 & V_13 ) ) )
V_17 = V_18 - ( V_15 & V_13 ) ;
F_4 ( & V_10 ) ;
F_1 ( V_2 , V_15 ) ;
F_8 ( V_14 , V_12 + ( V_15 & V_13 ) , V_17 ) ;
F_6 ( & V_10 ) ;
V_14 += V_17 ;
V_15 += V_17 ;
V_16 -= V_17 ;
}
}
static void F_9 ( struct V_1 * V_2 , T_1 V_19 , unsigned long V_20 )
{
F_4 ( & V_10 ) ;
F_1 ( V_2 , V_20 ) ;
F_10 ( V_19 . V_11 [ 0 ] , V_12 + ( V_20 & V_13 ) ) ;
F_6 ( & V_10 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned long V_14 , const void * V_15 , T_2 V_16 )
{
while( V_16 ) {
unsigned long V_17 = V_16 ;
if ( V_16 > ( V_18 - ( V_14 & V_13 ) ) )
V_17 = V_18 - ( V_14 & V_13 ) ;
F_4 ( & V_10 ) ;
F_1 ( V_2 , V_14 ) ;
F_12 ( V_12 + ( V_14 & V_13 ) , V_15 , V_17 ) ;
F_6 ( & V_10 ) ;
V_14 += V_17 ;
V_15 += V_17 ;
V_16 -= V_17 ;
}
}
static void F_13 ( void )
{
if( V_21 ) {
F_14 ( V_21 ) ;
F_15 ( V_21 ) ;
}
F_16 ( V_12 ) ;
F_17 ( V_8 , V_22 ) ;
}
static int T_3 F_18 ( void )
{
V_12 = F_19 ( V_23 , V_18 ) ;
if ( ! V_12 ) {
F_20 ( V_24 L_1 ,
V_25 . V_26 ) ;
return - V_27 ;
}
if ( ! F_21 ( V_8 , V_22 , L_2 ) ) {
F_20 ( V_24 L_3 ,
V_25 . V_26 ,
V_8 , V_8 + V_22 - 1 ) ;
F_16 ( V_12 ) ;
return - V_28 ;
}
F_20 ( V_29 L_4 ,
V_25 . V_26 ,
V_8 , V_8 + V_22 - 1 ,
V_23 , V_23 + V_18 - 1 ) ;
V_21 = F_22 ( L_5 , & V_25 ) ;
if( ! V_21 ) {
F_13 () ;
return - V_30 ;
}
V_21 -> V_31 = V_32 ;
F_23 ( V_21 , V_33 , V_34 ) ;
return 0 ;
}
