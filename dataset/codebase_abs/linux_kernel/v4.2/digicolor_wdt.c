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
struct V_1 * V_2 = F_6 ( V_12 , struct V_1 , V_15 ) ;
F_1 ( V_2 , 1 ) ;
F_7 ( 500 ) ;
return V_16 ;
}
static int F_8 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
F_1 ( V_2 , V_18 -> V_19 * F_10 ( V_2 -> V_20 ) ) ;
return 0 ;
}
static int F_11 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
F_3 ( 0 , V_2 -> V_6 + V_7 ) ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 , unsigned int V_21 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
F_1 ( V_2 , V_21 * F_10 ( V_2 -> V_20 ) ) ;
V_18 -> V_19 = V_21 ;
return 0 ;
}
static unsigned int F_13 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
T_2 V_22 = F_14 ( V_2 -> V_6 + V_8 ) ;
return V_22 / F_10 ( V_2 -> V_20 ) ;
}
static int F_15 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = & V_24 -> V_26 ;
struct V_27 * V_28 = V_26 -> V_29 ;
struct V_1 * V_2 ;
int V_30 ;
V_2 = F_16 ( V_26 , sizeof( struct V_1 ) , V_31 ) ;
if ( ! V_2 )
return - V_32 ;
F_17 ( V_24 , V_2 ) ;
V_2 -> V_6 = F_18 ( V_28 , 0 ) ;
if ( ! V_2 -> V_6 ) {
F_19 ( V_26 , L_1 ) ;
return - V_33 ;
}
V_2 -> V_20 = F_20 ( & V_24 -> V_26 , NULL ) ;
if ( F_21 ( V_2 -> V_20 ) ) {
V_30 = F_22 ( V_2 -> V_20 ) ;
goto V_34;
}
V_35 . V_36 = V_37 / F_10 ( V_2 -> V_20 ) ;
V_35 . V_19 = V_35 . V_36 ;
F_23 ( & V_2 -> V_5 ) ;
F_24 ( & V_35 , V_2 ) ;
F_25 ( & V_35 , V_19 , V_26 ) ;
V_30 = F_26 ( & V_35 ) ;
if ( V_30 ) {
F_19 ( V_26 , L_2 ) ;
goto V_34;
}
V_2 -> V_15 . V_38 = F_5 ;
V_2 -> V_15 . V_39 = 128 ;
V_30 = F_27 ( & V_2 -> V_15 ) ;
if ( V_30 )
F_28 ( & V_24 -> V_26 , L_3 ) ;
return 0 ;
V_34:
F_29 ( V_2 -> V_6 ) ;
return V_30 ;
}
static int F_30 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_31 ( V_24 ) ;
F_32 ( & V_2 -> V_15 ) ;
F_33 ( & V_35 ) ;
F_29 ( V_2 -> V_6 ) ;
return 0 ;
}
static void F_34 ( struct V_23 * V_24 )
{
F_11 ( & V_35 ) ;
}
