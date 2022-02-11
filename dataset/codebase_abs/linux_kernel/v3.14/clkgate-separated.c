static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 = 0 ;
T_1 V_6 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
if ( V_4 -> V_7 )
F_3 ( V_4 -> V_7 , V_5 ) ;
V_6 = F_4 ( V_4 -> V_8 ) ;
F_5 ( V_6 , V_4 -> V_9 ) ;
F_6 ( V_4 -> V_9 + V_10 ) ;
if ( V_4 -> V_7 )
F_7 ( V_4 -> V_7 , V_5 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 = 0 ;
T_1 V_6 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
if ( V_4 -> V_7 )
F_3 ( V_4 -> V_7 , V_5 ) ;
V_6 = F_4 ( V_4 -> V_8 ) ;
F_5 ( V_6 , V_4 -> V_9 + V_11 ) ;
F_6 ( V_4 -> V_9 + V_10 ) ;
if ( V_4 -> V_7 )
F_7 ( V_4 -> V_7 , V_5 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_6 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_6 = F_6 ( V_4 -> V_9 + V_10 ) ;
V_6 &= F_4 ( V_4 -> V_8 ) ;
return V_6 ? 1 : 0 ;
}
struct V_12 * F_10 ( struct V_13 * V_14 , const char * V_15 ,
const char * V_16 ,
unsigned long V_5 ,
void T_2 * V_6 , T_3 V_8 ,
T_3 V_17 , T_4 * V_7 )
{
struct V_3 * V_4 ;
struct V_12 * V_12 ;
struct V_18 V_19 ;
V_4 = F_11 ( sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 ) {
F_12 ( L_1 , V_21 ) ;
return F_13 ( - V_22 ) ;
}
V_19 . V_15 = V_15 ;
V_19 . V_23 = & V_24 ;
V_19 . V_5 = V_5 | V_25 ;
V_19 . V_26 = ( V_16 ? & V_16 : NULL ) ;
V_19 . V_27 = ( V_16 ? 1 : 0 ) ;
V_4 -> V_9 = V_6 + V_28 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_5 = V_17 ;
V_4 -> V_2 . V_19 = & V_19 ;
V_12 = F_14 ( V_14 , & V_4 -> V_2 ) ;
if ( F_15 ( V_12 ) )
F_16 ( V_4 ) ;
return V_12 ;
}
