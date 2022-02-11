static int F_1 ( struct V_1 * V_2 ,
void * V_3 , int V_4 , void * V_5 , T_1 V_6 )
{
struct V_7 * V_8 = V_3 ;
struct V_9 * V_10 = F_2 ( & V_2 -> V_11 ) ;
if ( V_4 < sizeof( * V_8 ) ) {
F_3 ( V_10 -> V_11 , L_1 ) ;
return - V_12 ;
}
if ( F_4 ( V_8 -> V_13 ) != 0 )
return - V_12 ;
if ( F_4 ( V_8 -> V_14 ) != V_15 )
return 0 ;
if ( F_4 ( V_8 -> V_16 ) != V_10 -> V_16 ) {
F_3 ( V_10 -> V_11 , L_2 ) ;
return - V_12 ;
}
F_5 ( & V_10 -> V_17 ) ;
return 0 ;
}
static int F_6 ( struct V_18 * V_19 , unsigned long V_20 ,
void * V_3 )
{
struct V_9 * V_10 = F_7 ( V_19 , struct V_9 , V_19 ) ;
struct V_21 V_8 ;
char * V_22 = V_3 ;
int V_23 ;
V_10 -> V_16 ++ ;
F_8 ( & V_10 -> V_17 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_24 = F_9 ( V_25 ) ;
V_8 . V_16 = F_9 ( V_10 -> V_16 ) ;
V_8 . V_26 = F_9 ( strlen ( V_22 ) ) ;
F_10 ( V_8 . V_27 , V_22 , sizeof( V_8 . V_27 ) ) ;
V_23 = F_11 ( V_10 -> V_28 , & V_8 , sizeof( V_8 ) ) ;
if ( V_23 < 0 )
F_3 ( V_10 -> V_11 , L_3 ) ;
V_23 = F_12 ( & V_10 -> V_17 , V_29 ) ;
if ( ! V_23 )
F_3 ( V_10 -> V_11 , L_4 ) ;
return V_30 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
V_10 = F_14 ( & V_2 -> V_11 , sizeof( * V_10 ) , V_31 ) ;
if ( ! V_10 )
return - V_32 ;
F_15 ( & V_10 -> V_17 ) ;
V_10 -> V_11 = & V_2 -> V_11 ;
V_10 -> V_28 = V_2 -> V_28 ;
V_10 -> V_19 . V_33 = F_6 ;
F_16 ( & V_2 -> V_11 , V_10 ) ;
return F_17 ( & V_10 -> V_19 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( & V_2 -> V_11 ) ;
F_19 ( & V_10 -> V_19 ) ;
}
