static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return & V_4 -> V_5 -> V_6 -> V_7 ;
}
static int F_2 ( struct V_1 * V_8 )
{
return & V_4 -> V_5 -> V_6 -> V_7 == V_8 ;
}
static int F_3 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_13 = F_4 ( V_10 -> V_8 , struct V_13 , V_7 ) ;
if ( F_5 ( V_13 -> V_14 , V_15 ) ) {
int V_16 = ( V_12 -> V_16 >> 6 ) & 7 ;
return ( V_16 << 6 ) | ( V_16 << 3 ) | V_16 ;
}
return V_12 -> V_16 ;
}
static void F_6 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
T_1 * V_17 , T_2 * V_18 )
{
struct V_13 * V_13 = F_4 ( V_10 -> V_8 , struct V_13 , V_7 ) ;
T_1 V_19 ;
T_2 V_20 ;
V_19 = F_7 ( V_13 -> V_14 , 0 ) ;
if ( F_8 ( V_19 ) )
* V_17 = V_19 ;
V_20 = F_9 ( V_13 -> V_14 , 0 ) ;
if ( F_10 ( V_20 ) )
* V_18 = V_20 ;
}
static int T_3 F_11 ( struct V_13 * V_13 )
{
F_12 ( & V_13 -> V_7 , & V_21 , F_2 ) ;
return 0 ;
}
static void T_4 F_13 ( struct V_13 * V_13 )
{
F_14 ( & V_13 -> V_7 ) ;
}
T_5 int F_15 ( void )
{
static struct V_11 V_22 [ 1 ] ;
int V_23 = - V_24 ;
V_25 = F_16 ( L_1 , V_22 ) ;
if ( ! V_25 )
goto V_26;
V_23 = F_17 ( & V_27 ) ;
if ( V_23 )
goto V_28;
F_18 ( & V_21 ) ;
V_26:
return V_23 ;
V_28:
F_19 ( V_25 ) ;
V_25 = NULL ;
goto V_26;
}
struct V_9 * F_20 ( struct V_13 * V_13 ,
const char * V_29 , struct V_11 * V_12 )
{
return F_21 ( & V_13 -> V_7 , V_29 , V_12 ) ;
}
void F_22 ( struct V_9 * V_30 )
{
F_19 ( V_30 ) ;
}
