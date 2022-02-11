static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
F_3 ( 0 , V_2 -> V_6 + V_7 ) ;
F_3 ( V_3 , V_2 -> V_6 + V_8 ) ;
F_3 ( V_9 | V_10 ,
V_2 -> V_6 + V_7 ) ;
F_4 ( & V_2 -> V_5 , V_4 ) ;
}
static int F_5 ( struct V_11 * V_12 , unsigned long V_13 ,
void * V_14 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
F_1 ( V_2 , 1 ) ;
F_7 ( 500 ) ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
F_1 ( V_2 , V_12 -> V_15 * F_9 ( V_2 -> V_16 ) ) ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
F_3 ( 0 , V_2 -> V_6 + V_7 ) ;
return 0 ;
}
static int F_11 ( struct V_11 * V_12 , unsigned int V_17 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
F_1 ( V_2 , V_17 * F_9 ( V_2 -> V_16 ) ) ;
V_12 -> V_15 = V_17 ;
return 0 ;
}
static unsigned int F_12 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
T_2 V_18 = F_13 ( V_2 -> V_6 + V_8 ) ;
return V_18 / F_9 ( V_2 -> V_16 ) ;
}
static int F_14 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 = & V_20 -> V_24 ;
struct V_1 * V_2 ;
int V_25 ;
V_2 = F_15 ( V_24 , sizeof( struct V_1 ) , V_26 ) ;
if ( ! V_2 )
return - V_27 ;
V_22 = F_16 ( V_20 , V_28 , 0 ) ;
V_2 -> V_6 = F_17 ( V_24 , V_22 ) ;
if ( F_18 ( V_2 -> V_6 ) )
return F_19 ( V_2 -> V_6 ) ;
V_2 -> V_16 = F_20 ( V_24 , NULL ) ;
if ( F_18 ( V_2 -> V_16 ) )
return F_19 ( V_2 -> V_16 ) ;
V_29 . V_30 = V_31 / F_9 ( V_2 -> V_16 ) ;
V_29 . V_15 = V_29 . V_30 ;
V_29 . V_32 = V_24 ;
F_21 ( & V_2 -> V_5 ) ;
F_22 ( & V_29 , V_2 ) ;
F_23 ( & V_29 , 128 ) ;
F_24 ( & V_29 , V_15 , V_24 ) ;
F_25 ( & V_29 ) ;
V_25 = F_26 ( V_24 , & V_29 ) ;
if ( V_25 ) {
F_27 ( V_24 , L_1 ) ;
return V_25 ;
}
return 0 ;
}
