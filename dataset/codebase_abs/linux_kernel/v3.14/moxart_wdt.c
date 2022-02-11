static void F_1 ( enum V_1 V_1 , const char * V_2 )
{
F_2 ( 1 , V_3 -> V_4 + V_5 ) ;
F_2 ( 0x5ab9 , V_3 -> V_4 + V_6 ) ;
F_2 ( 0x03 , V_3 -> V_4 + V_7 ) ;
}
static int F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
F_2 ( 0 , V_11 -> V_4 + V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
F_2 ( V_11 -> V_12 * V_9 -> V_13 ,
V_11 -> V_4 + V_5 ) ;
F_2 ( 0x5ab9 , V_11 -> V_4 + V_6 ) ;
F_2 ( 0x03 , V_11 -> V_4 + V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_8 * V_9 ,
unsigned int V_13 )
{
V_9 -> V_13 = V_13 ;
return 0 ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_10 * V_11 ;
struct V_16 * V_17 = & V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_23 ;
int V_24 ;
unsigned int V_25 ;
bool V_26 = V_27 ;
V_11 = F_8 ( V_17 , sizeof( * V_11 ) , V_28 ) ;
if ( ! V_11 )
return - V_29 ;
F_9 ( V_15 , V_11 ) ;
V_22 = F_10 ( V_15 , V_30 , 0 ) ;
V_11 -> V_4 = F_11 ( V_17 , V_22 ) ;
if ( F_12 ( V_11 -> V_4 ) )
return F_13 ( V_11 -> V_4 ) ;
V_23 = F_14 ( V_19 , 0 ) ;
if ( F_12 ( V_23 ) ) {
F_15 ( L_1 , V_31 ) ;
return F_13 ( V_23 ) ;
}
V_11 -> V_12 = F_16 ( V_23 ) ;
if ( V_11 -> V_12 == 0 ) {
F_15 ( L_2 , V_31 ) ;
return - V_32 ;
}
V_25 = V_33 / V_11 -> V_12 ;
V_11 -> V_17 . V_34 = & V_35 ;
V_11 -> V_17 . V_36 = & V_37 ;
V_11 -> V_17 . V_13 = V_25 ;
V_11 -> V_17 . V_38 = 1 ;
V_11 -> V_17 . V_25 = V_25 ;
V_11 -> V_17 . V_39 = V_17 ;
F_17 ( & V_11 -> V_17 , V_40 , V_17 ) ;
F_18 ( & V_11 -> V_17 , V_26 ) ;
F_19 ( & V_11 -> V_17 , V_11 ) ;
V_24 = F_20 ( & V_11 -> V_17 ) ;
if ( V_24 )
return V_24 ;
V_3 = V_11 ;
V_41 = F_1 ;
F_21 ( V_17 , L_3 ,
V_11 -> V_17 . V_13 , V_26 ) ;
return 0 ;
}
static int F_22 ( struct V_14 * V_15 )
{
struct V_10 * V_11 = F_23 ( V_15 ) ;
V_41 = NULL ;
F_3 ( & V_11 -> V_17 ) ;
F_24 ( & V_11 -> V_17 ) ;
return 0 ;
}
