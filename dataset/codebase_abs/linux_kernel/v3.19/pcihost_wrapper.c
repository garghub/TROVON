static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
V_7 = F_4 ( V_6 ) ;
if ( V_7 )
return V_7 ;
F_5 ( V_4 ) ;
F_6 ( V_4 ) ;
F_7 ( V_2 , V_2 -> V_8 . V_9 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
F_10 ( V_4 ) ;
V_7 = F_11 ( V_4 ) ;
if ( V_7 )
return V_7 ;
F_12 ( V_4 ) ;
V_7 = F_13 ( V_6 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
static int F_14 ( struct V_3 * V_4 ,
const struct V_10 * V_11 )
{
struct V_5 * V_6 ;
int V_7 = - V_12 ;
const char * V_13 ;
T_1 V_14 ;
V_6 = F_15 ( sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
goto V_16;
V_7 = F_11 ( V_4 ) ;
if ( V_7 )
goto V_17;
V_13 = F_16 ( & V_4 -> V_4 ) ;
if ( V_4 -> V_18 && V_4 -> V_18 -> V_13 )
V_13 = V_4 -> V_18 -> V_13 ;
V_7 = F_17 ( V_4 , V_13 ) ;
if ( V_7 )
goto V_19;
F_18 ( V_4 ) ;
F_19 ( V_4 , 0x40 , & V_14 ) ;
if ( ( V_14 & 0x0000ff00 ) != 0 )
F_20 ( V_4 , 0x40 , V_14 & 0xffff00ff ) ;
V_7 = F_21 ( V_6 , V_4 ) ;
if ( V_7 )
goto V_20;
F_22 ( V_4 , V_6 ) ;
V_16:
return V_7 ;
V_20:
F_23 ( V_4 ) ;
V_19:
F_6 ( V_4 ) ;
V_17:
F_24 ( V_6 ) ;
return V_7 ;
}
static void F_25 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_26 ( V_6 ) ;
F_23 ( V_4 ) ;
F_6 ( V_4 ) ;
F_24 ( V_6 ) ;
F_22 ( V_4 , NULL ) ;
}
int F_27 ( struct V_21 * V_18 )
{
V_18 -> V_22 = F_14 ;
V_18 -> remove = F_25 ;
#ifdef F_28
V_18 -> V_18 . V_23 = & V_24 ;
#endif
return F_29 ( V_18 ) ;
}
