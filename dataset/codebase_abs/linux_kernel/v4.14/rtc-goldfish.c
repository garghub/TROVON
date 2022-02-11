static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
T_1 V_6 ;
T_1 V_7 ;
void T_2 * V_8 ;
struct V_9 * V_10 ;
V_10 = F_2 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
V_6 = F_3 ( V_8 + V_11 ) ;
V_7 = F_3 ( V_8 + V_12 ) ;
V_5 = ( V_7 << 32 ) | V_6 ;
F_4 ( V_5 , V_13 ) ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
F_5 ( V_5 , & V_4 -> time ) ;
if ( F_3 ( V_8 + V_14 ) )
V_4 -> V_15 = 1 ;
else
V_4 -> V_15 = 0 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_9 * V_10 ;
unsigned long V_5 ;
T_1 V_16 ;
T_1 V_17 ;
void T_2 * V_8 ;
int V_18 = 0 ;
V_10 = F_2 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
if ( V_4 -> V_15 ) {
V_18 = F_7 ( & V_4 -> time , & V_5 ) ;
if ( V_18 != 0 )
return V_18 ;
V_16 = V_5 * V_13 ;
F_8 ( ( V_16 >> 32 ) , V_8 + V_12 ) ;
F_8 ( V_16 , V_8 + V_11 ) ;
} else {
V_17 = F_3 ( V_8 + V_14 ) ;
if ( V_17 )
F_8 ( 1 , V_8 + V_19 ) ;
}
return V_18 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_15 )
{
void T_2 * V_8 ;
struct V_9 * V_10 ;
V_10 = F_2 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
if ( V_15 )
F_8 ( 1 , V_8 + V_20 ) ;
else
F_8 ( 0 , V_8 + V_20 ) ;
return 0 ;
}
static T_3 F_10 ( int V_21 , void * V_22 )
{
struct V_9 * V_10 = V_22 ;
void T_2 * V_8 = V_10 -> V_8 ;
F_8 ( 1 , V_8 + V_23 ) ;
F_11 ( V_10 -> V_24 , 1 , V_25 | V_26 ) ;
return V_27 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_9 * V_10 ;
void T_2 * V_8 ;
T_1 V_30 ;
T_1 V_31 ;
T_1 time ;
V_10 = F_2 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
V_31 = F_3 ( V_8 + V_32 ) ;
V_30 = F_3 ( V_8 + V_33 ) ;
time = ( V_30 << 32 ) | V_31 ;
F_4 ( time , V_13 ) ;
F_5 ( time , V_29 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_9 * V_10 ;
void T_2 * V_8 ;
unsigned long V_34 ;
T_1 V_35 ;
int V_18 ;
V_10 = F_2 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
V_18 = F_7 ( V_29 , & V_34 ) ;
if ( V_18 == 0 ) {
V_35 = V_34 * V_13 ;
F_8 ( ( V_35 >> 32 ) , V_8 + V_33 ) ;
F_8 ( V_35 , V_8 + V_32 ) ;
}
return V_18 ;
}
static int F_14 ( struct V_36 * V_37 )
{
struct V_9 * V_10 ;
struct V_38 * V_39 ;
int V_40 ;
V_10 = F_15 ( & V_37 -> V_2 , sizeof( * V_10 ) , V_41 ) ;
if ( ! V_10 )
return - V_42 ;
F_16 ( V_37 , V_10 ) ;
V_39 = F_17 ( V_37 , V_43 , 0 ) ;
if ( ! V_39 )
return - V_44 ;
V_10 -> V_8 = F_18 ( & V_37 -> V_2 , V_39 ) ;
if ( F_19 ( V_10 -> V_8 ) )
return - V_44 ;
V_10 -> V_21 = F_20 ( V_37 , 0 ) ;
if ( V_10 -> V_21 < 0 )
return - V_44 ;
V_10 -> V_24 = F_21 ( & V_37 -> V_2 , V_37 -> V_45 ,
& V_46 ,
V_47 ) ;
if ( F_19 ( V_10 -> V_24 ) )
return F_22 ( V_10 -> V_24 ) ;
V_40 = F_23 ( & V_37 -> V_2 , V_10 -> V_21 ,
F_10 ,
0 , V_37 -> V_45 , V_10 ) ;
if ( V_40 )
return V_40 ;
return 0 ;
}
