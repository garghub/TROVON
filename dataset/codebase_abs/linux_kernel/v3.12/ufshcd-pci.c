static int F_1 ( struct V_1 * V_2 )
{
return - V_3 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return - V_3 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
return F_5 ( V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
return F_7 ( V_5 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_4 ( V_2 ) ;
if ( ! V_5 )
return 0 ;
return F_9 ( V_5 ) ;
}
static void F_10 ( struct V_6 * V_7 )
{
F_11 ( (struct V_4 * ) F_12 ( V_7 ) ) ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = F_12 ( V_7 ) ;
F_14 ( & V_7 -> V_2 ) ;
F_15 ( & V_7 -> V_2 ) ;
F_16 ( V_5 ) ;
F_17 ( V_7 , NULL ) ;
}
static int F_18 ( struct V_6 * V_7 )
{
int V_8 ;
if ( ! F_19 ( V_7 , F_20 ( 64 ) )
&& ! F_21 ( V_7 , F_20 ( 64 ) ) )
return 0 ;
V_8 = F_19 ( V_7 , F_20 ( 32 ) ) ;
if ( ! V_8 )
V_8 = F_21 ( V_7 , F_20 ( 32 ) ) ;
return V_8 ;
}
static int
F_22 ( struct V_6 * V_7 , const struct V_9 * V_10 )
{
struct V_4 * V_5 ;
void T_1 * V_11 ;
int V_8 ;
V_8 = F_23 ( V_7 ) ;
if ( V_8 ) {
F_24 ( & V_7 -> V_2 , L_1 ) ;
return V_8 ;
}
F_25 ( V_7 ) ;
V_8 = F_26 ( V_7 , 1 << 0 , V_12 ) ;
if ( V_8 < 0 ) {
F_24 ( & V_7 -> V_2 , L_2 ) ;
return V_8 ;
}
V_11 = F_27 ( V_7 ) [ 0 ] ;
V_8 = F_18 ( V_7 ) ;
if ( V_8 ) {
F_24 ( & V_7 -> V_2 , L_3 ) ;
return V_8 ;
}
V_8 = F_28 ( & V_7 -> V_2 , & V_5 , V_11 , V_7 -> V_13 ) ;
if ( V_8 ) {
F_24 ( & V_7 -> V_2 , L_4 ) ;
return V_8 ;
}
F_17 ( V_7 , V_5 ) ;
F_29 ( & V_7 -> V_2 ) ;
F_30 ( & V_7 -> V_2 ) ;
return 0 ;
}
