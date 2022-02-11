static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 = 0 ;
unsigned V_12 ;
if ( F_2 () || F_3 () ||
F_4 () )
V_12 = 27000000 ;
else if ( F_5 () )
V_12 = 12288000 ;
else if ( F_6 () ||
F_7 () )
V_12 = 24576000 ;
else
return - V_13 ;
V_11 = F_8 ( V_9 , V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_8 ( V_10 , V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( V_9 , 0 , V_12 , V_15 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_10 = V_6 -> V_10 ;
return F_8 ( V_10 , V_14 ) ;
}
static int F_11 ( struct V_5 * V_6 )
{
struct V_16 * V_17 = V_6 -> V_17 ;
struct V_18 * V_19 = & V_17 -> V_19 ;
F_12 ( V_19 , V_20 ,
F_13 ( V_20 ) ) ;
F_14 ( V_19 , V_21 , F_13 ( V_21 ) ) ;
F_15 ( V_19 , L_1 ) ;
F_15 ( V_19 , L_2 ) ;
F_15 ( V_19 , L_3 ) ;
F_16 ( V_19 , L_4 ) ;
F_16 ( V_19 , L_5 ) ;
F_16 ( V_19 , L_6 ) ;
F_16 ( V_19 , L_7 ) ;
return 0 ;
}
static int T_1 F_17 ( void )
{
struct V_22 * V_23 ;
int V_24 ;
int V_11 ;
if ( F_5 () ) {
V_23 = & V_25 ;
V_24 = 0 ;
} else if ( F_2 () ) {
V_23 = & V_26 ;
V_24 = 1 ;
} else if ( F_4 () ) {
V_23 = & V_27 ;
V_24 = 0 ;
} else if ( F_3 () ) {
V_23 = & V_28 ;
V_24 = 0 ;
} else if ( F_6 () ) {
V_23 = & V_29 ;
V_24 = 1 ;
} else if ( F_7 () ) {
V_23 = & V_30 ;
V_24 = 0 ;
} else
return - V_13 ;
V_31 = F_18 ( L_8 , V_24 ) ;
if ( ! V_31 )
return - V_32 ;
F_19 ( V_31 , V_23 ) ;
V_11 = F_20 ( V_31 ) ;
if ( V_11 )
F_21 ( V_31 ) ;
return V_11 ;
}
static void T_2 F_22 ( void )
{
F_23 ( V_31 ) ;
}
