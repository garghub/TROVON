static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static int F_3 ( struct V_1 * V_2 , int V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_4 ( V_9 , V_4 -> V_10 ) ;
unsigned long V_11 ;
if ( ! V_8 || V_8 -> V_12 != 1 || V_8 -> V_13 [ 0 ] -> V_14 != 1 )
return - V_15 ;
V_4 -> V_5 = V_6 & 0x0ff ;
F_5 ( & V_4 -> V_16 , V_11 ) ;
F_6 ( V_8 -> V_13 [ 0 ] , 0 , V_4 -> V_5 ) ;
if ( ! ( V_4 -> V_17 & V_18 ) )
F_7 ( V_4 -> V_10 , V_8 , V_19 ) ;
F_8 ( & V_4 -> V_16 , V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
return V_21 && V_21 == F_10 ( (struct V_3 * ) F_2 ( V_2 ) ) ;
}
int F_11 ( struct V_3 * V_4 , struct V_7 * V_8 )
{
struct V_22 * V_23 = & V_4 -> V_10 -> V_23 ;
struct V_1 * V_2 ;
if ( ! V_8 )
return - V_15 ;
if ( V_8 -> V_12 != 1 || V_8 -> V_13 [ 0 ] -> V_14 != 1 ||
V_8 -> V_13 [ 0 ] -> V_24 != 8 ) {
F_12 ( V_23 , L_1 ) ;
return - V_25 ;
}
V_2 = F_13 ( F_14 ( V_23 ) , V_23 , V_4 , & V_26 ) ;
if ( F_15 ( V_2 ) ) {
F_12 ( V_23 , L_2 ) ;
return F_16 ( V_2 ) ;
}
V_2 -> V_27 . V_28 = 0x0ff ;
V_4 -> V_5 = 0xe5 ;
V_4 -> V_29 = V_2 ;
F_3 ( V_2 , 0xe5 ) ;
return 0 ;
}
void F_17 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_29 ;
V_4 -> V_29 = NULL ;
if ( V_2 )
F_18 ( V_2 ) ;
}
int F_19 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_29 )
return 0 ;
return F_3 ( V_4 -> V_29 , V_4 -> V_5 ) ;
}
