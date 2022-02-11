static void F_1 ( unsigned long V_1 )
{
if ( F_2 ( V_2 , V_3 ) )
F_3 ( 0x5555 , V_4 + V_5 ) ;
F_4 ( & V_6 , V_2 + V_7 ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
V_3 = V_2 + ( V_10 * V_11 ) ;
F_3 ( 0xaaaa , V_4 + V_5 ) ;
F_4 ( & V_6 , V_2 + V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_8 * V_9 )
{
F_7 ( & V_6 ) ;
F_3 ( 0xaa55 , V_4 + V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_8 * V_9 )
{
V_3 = V_2 + ( V_10 * V_11 ) ;
return 0 ;
}
static int T_1 F_9 ( struct V_12 * V_13 )
{
struct V_14 * V_15 ;
unsigned long V_16 ;
int V_17 ;
V_15 = F_10 ( V_13 , V_18 , 0 ) ;
if ( ! V_15 )
return - V_19 ;
if ( ! F_11 ( & V_13 -> V_20 , V_15 -> V_21 ,
F_12 ( V_15 ) , V_13 -> V_22 ) )
return - V_23 ;
V_4 = F_13 ( & V_13 -> V_20 , V_15 -> V_21 , F_12 ( V_15 ) ) ;
if ( ! V_4 )
return - V_19 ;
if ( V_10 < 1 || V_10 > 3600 ) {
V_10 = V_24 ;
F_14 ( & V_13 -> V_20 ,
L_1 ,
V_10 ) ;
}
V_16 = F_15 ( V_4 + V_5 ) ;
V_25 . V_26 = ( V_16 & 0x01 ) ? V_27 : 0 ;
V_25 . V_10 = V_10 ;
F_16 ( & V_25 , V_28 ) ;
F_17 ( & V_6 , F_1 , 1 ) ;
V_17 = F_18 ( & V_25 ) ;
if ( V_17 )
return V_17 ;
F_19 ( & V_13 -> V_20 ,
L_2 V_29 L_3 ,
( V_16 & 0x08 ) ? L_4 : L_5 ) ;
return 0 ;
}
static int T_2 F_20 ( struct V_12 * V_13 )
{
F_21 ( & V_25 ) ;
return 0 ;
}
