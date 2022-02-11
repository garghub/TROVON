static int F_1 ( void * V_1 ,
unsigned int V_2 , void * V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_1 ;
T_3 * V_6 = V_3 ;
int V_7 = 0 , V_8 = V_4 / 4 ;
while ( V_8 -- )
* V_6 ++ = F_2 ( V_5 + V_2 + ( V_7 ++ * 4 ) ) ;
return 0 ;
}
static int F_3 ( void * V_1 ,
unsigned int V_2 , void * V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_1 ;
T_3 * V_6 = V_3 ;
int V_7 = 0 , V_8 = V_4 / 4 ;
while ( V_8 -- )
F_4 ( * V_6 ++ , V_5 + V_2 + ( V_7 ++ * 4 ) ) ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = & V_10 -> V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
void T_2 * V_5 ;
V_14 = F_6 ( V_10 , V_19 , 0 ) ;
V_5 = F_7 ( V_12 , V_14 ) ;
if ( F_8 ( V_5 ) )
return F_9 ( V_5 ) ;
V_18 = F_10 ( V_12 , sizeof( * V_18 ) , V_20 ) ;
if ( ! V_18 )
return - V_21 ;
V_18 -> V_22 = 4 ;
V_18 -> V_23 = 4 ;
V_18 -> V_24 = F_1 ;
V_18 -> V_25 = F_3 ;
V_18 -> V_26 = F_11 ( V_14 ) ;
V_18 -> V_27 = V_5 ;
V_18 -> V_12 = V_12 ;
V_18 -> V_28 = V_29 ;
V_16 = F_12 ( V_18 ) ;
if ( F_8 ( V_16 ) )
return F_9 ( V_16 ) ;
F_13 ( V_10 , V_16 ) ;
return 0 ;
}
static int F_14 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = F_15 ( V_10 ) ;
return F_16 ( V_16 ) ;
}
static int T_4 F_17 ( void )
{
int V_30 ;
V_30 = F_18 ( & V_31 ) ;
if ( V_30 ) {
F_19 ( L_1 ) ;
return V_30 ;
}
return 0 ;
}
static void T_5 F_20 ( void )
{
return F_21 ( & V_31 ) ;
}
