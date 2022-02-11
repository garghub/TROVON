static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_3 ( V_5 ) ;
if ( V_6 )
return V_6 ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 , F_7 ( V_2 , V_3 ) ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
F_6 ( V_2 , V_7 ) ;
V_6 = F_9 ( V_2 ) ;
if ( V_6 )
return V_6 ;
F_10 ( V_2 ) ;
V_6 = F_11 ( V_5 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
const struct V_8 * V_9 )
{
struct V_4 * V_5 ;
int V_6 = - V_10 ;
const char * V_11 ;
T_2 V_12 ;
V_5 = F_13 ( sizeof( * V_5 ) , V_13 ) ;
if ( ! V_5 )
goto V_14;
V_6 = F_9 ( V_2 ) ;
if ( V_6 )
goto V_15;
V_11 = F_14 ( & V_2 -> V_2 ) ;
if ( V_2 -> V_16 && V_2 -> V_16 -> V_11 )
V_11 = V_2 -> V_16 -> V_11 ;
V_6 = F_15 ( V_2 , V_11 ) ;
if ( V_6 )
goto V_17;
F_16 ( V_2 ) ;
F_17 ( V_2 , 0x40 , & V_12 ) ;
if ( ( V_12 & 0x0000ff00 ) != 0 )
F_18 ( V_2 , 0x40 , V_12 & 0xffff00ff ) ;
V_6 = F_19 ( V_5 , V_2 ) ;
if ( V_6 )
goto V_18;
F_20 ( V_2 , V_5 ) ;
V_14:
return V_6 ;
V_18:
F_21 ( V_2 ) ;
V_17:
F_5 ( V_2 ) ;
V_15:
F_22 ( V_5 ) ;
return V_6 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_24 ( V_5 ) ;
F_21 ( V_2 ) ;
F_5 ( V_2 ) ;
F_22 ( V_5 ) ;
F_20 ( V_2 , NULL ) ;
}
int F_25 ( struct V_19 * V_16 )
{
V_16 -> V_20 = F_12 ;
V_16 -> remove = F_23 ;
V_16 -> V_21 = F_1 ;
V_16 -> V_22 = F_8 ;
return F_26 ( V_16 ) ;
}
