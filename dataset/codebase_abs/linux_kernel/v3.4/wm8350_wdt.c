static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 ;
T_1 V_7 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_8 ) ; V_6 ++ )
if ( V_8 [ V_6 ] . time == V_3 )
break;
if ( V_6 == F_3 ( V_8 ) )
return - V_9 ;
F_4 ( & V_10 ) ;
F_5 ( V_4 ) ;
V_7 = F_6 ( V_4 , V_11 ) ;
V_7 &= ~ V_12 ;
V_7 |= V_8 [ V_6 ] . V_13 ;
V_5 = F_7 ( V_4 , V_11 , V_7 ) ;
F_8 ( V_4 ) ;
F_9 ( & V_10 ) ;
V_2 -> V_3 = V_3 ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
T_1 V_7 ;
F_4 ( & V_10 ) ;
F_5 ( V_4 ) ;
V_7 = F_6 ( V_4 , V_11 ) ;
V_7 &= ~ V_14 ;
V_7 |= 0x20 ;
V_5 = F_7 ( V_4 , V_11 , V_7 ) ;
F_8 ( V_4 ) ;
F_9 ( & V_10 ) ;
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
T_1 V_7 ;
F_4 ( & V_10 ) ;
F_5 ( V_4 ) ;
V_7 = F_6 ( V_4 , V_11 ) ;
V_7 &= ~ V_14 ;
V_5 = F_7 ( V_4 , V_11 , V_7 ) ;
F_8 ( V_4 ) ;
F_9 ( & V_10 ) ;
return V_5 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
T_1 V_7 ;
F_4 ( & V_10 ) ;
V_7 = F_6 ( V_4 , V_11 ) ;
V_5 = F_7 ( V_4 , V_11 , V_7 ) ;
F_9 ( & V_10 ) ;
return V_5 ;
}
static int T_2 F_13 ( struct V_15 * V_16 )
{
struct V_4 * V_4 = F_14 ( V_16 ) ;
if ( ! V_4 ) {
F_15 ( L_1 ) ;
return - V_17 ;
}
F_16 ( & V_18 , V_19 ) ;
F_17 ( & V_18 , V_4 ) ;
F_1 ( & V_18 , 4 ) ;
return F_18 ( & V_18 ) ;
}
static int T_3 F_19 ( struct V_15 * V_16 )
{
F_20 ( & V_18 ) ;
return 0 ;
}
