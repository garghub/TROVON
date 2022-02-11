static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( ! V_4 ) {
F_2 ( V_5 L_1 ) ;
return;
}
if ( V_6 == NULL ) {
F_2 ( V_5
L_2 ) ;
return;
}
F_3 ( & V_4 -> V_7 , V_6 ) ;
}
static int F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
int V_12 )
{
int V_13 ;
V_6 = V_11 ;
V_13 = F_5 ( V_14 , V_15 , V_12 ) ;
if ( V_13 < 0 ) {
F_2 ( L_3 ,
V_13 ) ;
goto V_16;
}
V_13 = F_6 ( V_15 , F_1 ) ;
if ( V_13 < 0 ) {
F_2 ( L_4 ,
V_13 ) ;
goto V_17;
}
return 0 ;
V_17:
F_7 ( V_14 , V_15 , V_12 ) ;
V_16:
return - 1 ;
}
static void F_8 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
int V_12 )
{
F_9 ( V_15 ) ;
F_7 ( V_14 , V_15 , V_12 ) ;
}
static int F_10 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
return 0 ;
}
static int F_11 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
return 0 ;
}
static int F_12 ( struct V_10 * V_11 ,
T_1 V_18 , T_1 V_19 )
{
V_6 = V_11 ;
return F_13 ( V_14 ,
V_20 ,
V_15 ,
V_21 ,
V_22 ,
F_14 ( V_14 ) ,
F_15 ( V_14 ) ,
0 ,
V_23 << 16 , V_18 , V_19 , 0 ,
0 ) ;
}
static int F_16 ( struct V_10 * V_11 )
{
return 0 ;
}
