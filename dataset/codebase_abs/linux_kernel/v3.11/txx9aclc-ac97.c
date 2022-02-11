static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 + V_4 ) & V_5 ;
}
static unsigned short F_3 ( struct V_6 * V_7 ,
unsigned short V_8 )
{
struct V_1 * V_2 = V_9 ;
void T_1 * V_3 = V_2 -> V_3 ;
T_2 V_10 ;
if ( ! ( F_2 ( V_3 + V_4 ) & F_4 ( V_7 -> V_11 ) ) )
return 0xffff ;
V_8 |= V_7 -> V_11 << 7 ;
V_10 = ( V_8 << V_12 ) | V_13 ;
F_5 ( V_10 , V_3 + V_14 ) ;
F_5 ( V_5 , V_3 + V_15 ) ;
if ( ! F_6 ( V_16 , F_1 ( V_9 ) , V_17 ) ) {
F_5 ( V_5 , V_3 + V_18 ) ;
F_7 ( V_19 L_1 , V_8 ) ;
V_10 = 0xffff ;
goto V_20;
}
V_10 = F_2 ( V_3 + V_14 ) ;
if ( ( ( V_10 >> V_12 ) & 0xff ) != V_8 ) {
F_7 ( V_19 L_2 ,
V_10 , V_8 ) ;
V_10 = 0xffff ;
goto V_20;
}
V_10 = ( V_10 >> V_21 ) & 0xffff ;
V_20:
F_5 ( V_5 , V_3 + V_18 ) ;
return V_10 ;
}
static void F_8 ( struct V_6 * V_7 , unsigned short V_8 ,
unsigned short V_22 )
{
struct V_1 * V_2 = V_9 ;
void T_1 * V_3 = V_2 -> V_3 ;
F_5 ( ( ( V_8 | ( V_7 -> V_11 << 7 ) ) << V_12 ) |
( V_22 << V_21 ) ,
V_3 + V_14 ) ;
F_5 ( V_5 , V_3 + V_15 ) ;
if ( ! F_6 ( V_16 , F_1 ( V_9 ) , V_17 ) ) {
F_7 ( V_19
L_3 , V_8 ) ;
}
F_5 ( V_5 , V_3 + V_18 ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_9 ;
void T_1 * V_3 = V_2 -> V_3 ;
T_2 V_23 = F_4 ( V_7 -> V_11 ) | V_5 ;
F_5 ( V_24 , V_3 + V_25 ) ;
F_10 () ;
F_11 ( 1 ) ;
F_5 ( V_24 , V_3 + V_26 ) ;
F_5 ( V_23 , V_3 + V_15 ) ;
if ( ! F_6 ( V_16 ,
( F_2 ( V_3 + V_4 ) & V_23 ) == V_23 ,
V_17 ) ) {
F_12 ( & V_7 -> V_27 , L_4
L_5 ,
F_2 ( V_3 + V_4 ) ) ;
}
F_5 ( V_5 , V_3 + V_4 ) ;
F_5 ( V_23 , V_3 + V_18 ) ;
}
static T_3 F_13 ( int V_28 , void * V_29 )
{
struct V_1 * V_2 = V_29 ;
void T_1 * V_3 = V_2 -> V_3 ;
F_5 ( F_2 ( V_3 + V_30 ) , V_3 + V_18 ) ;
F_14 ( & V_16 ) ;
return V_31 ;
}
static int F_15 ( struct V_32 * V_33 )
{
V_9 = F_16 ( V_33 ) ;
return 0 ;
}
static int F_17 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_16 ( V_33 ) ;
F_5 ( V_24 , V_2 -> V_3 + V_25 ) ;
V_9 = NULL ;
return 0 ;
}
static int F_18 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_36 * V_37 ;
int V_38 ;
int V_28 ;
V_28 = F_19 ( V_35 , 0 ) ;
if ( V_28 < 0 )
return V_28 ;
V_37 = F_20 ( V_35 , V_39 , 0 ) ;
if ( ! V_37 )
return - V_40 ;
V_2 -> V_3 = F_21 ( & V_35 -> V_27 , V_37 ) ;
if ( F_22 ( V_2 -> V_3 ) )
return F_23 ( V_2 -> V_3 ) ;
V_2 = F_24 ( & V_35 -> V_27 , sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return - V_42 ;
F_25 ( V_35 , V_2 ) ;
V_2 -> V_43 = V_37 -> V_44 ;
if ( sizeof( V_2 -> V_43 ) > sizeof( V_37 -> V_44 ) &&
V_37 -> V_44 >= V_45 &&
V_37 -> V_44 < V_45 + 0x400000 )
V_2 -> V_43 |= 0xf00000000ull ;
V_38 = F_26 ( & V_35 -> V_27 , V_28 , F_13 ,
0 , F_27 ( & V_35 -> V_27 ) , V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_28 ( & V_46 ) ;
if ( V_38 < 0 )
return V_38 ;
return F_29 ( & V_35 -> V_27 , & V_47 ,
& V_48 , 1 ) ;
}
static int F_30 ( struct V_34 * V_35 )
{
F_31 ( & V_35 -> V_27 ) ;
F_28 ( NULL ) ;
return 0 ;
}
