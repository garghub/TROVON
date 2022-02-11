void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
F_2 ( & V_4 -> V_6 ) ;
F_3 ( & V_4 -> V_7 , V_8 ) ;
}
static int F_4 ( struct V_9 * V_10 , T_1 V_11 )
{
T_2 V_12 [ F_5 ( V_13 ) ] = { 0 } ;
T_2 V_14 [ F_5 ( V_15 ) ] = { 0 } ;
F_6 ( V_13 , V_12 , V_16 ,
V_17 ) ;
F_6 ( V_13 , V_12 , V_18 , V_11 ) ;
return F_7 ( V_10 , V_12 , sizeof( V_12 ) , V_14 , sizeof( V_14 ) ) ;
}
static int F_8 ( struct V_9 * V_10 , T_1 V_11 )
{
T_2 V_12 [ F_5 ( V_19 ) ] = { 0 } ;
T_2 V_14 [ F_5 ( V_20 ) ] = { 0 } ;
F_6 ( V_19 , V_12 , V_16 ,
V_21 ) ;
F_6 ( V_19 , V_12 , V_18 , V_11 ) ;
return F_7 ( V_10 , V_12 , sizeof( V_12 ) , V_14 , sizeof( V_14 ) ) ;
}
struct V_22 * F_9 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_22 * V_5 ;
F_10 ( & V_4 -> V_6 ) ;
V_5 = F_11 ( & V_4 -> V_7 , V_11 ) ;
F_12 ( & V_4 -> V_6 ) ;
return V_5 ;
}
static void F_13 ( struct V_23 * V_24 )
{
struct V_25 * V_26 =
F_14 ( V_24 , struct V_25 , V_24 ) ;
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
T_1 V_11 = V_26 -> V_11 ;
struct V_22 * V_5 ;
int V_27 ;
if ( F_9 ( V_2 , V_11 ) )
goto V_28;
if ( F_4 ( V_2 -> V_10 , V_11 ) )
goto V_28;
V_5 = F_15 ( sizeof( * V_5 ) , V_29 ) ;
if ( ! V_5 )
goto V_30;
V_5 -> V_31 = V_11 ;
F_16 ( & V_4 -> V_6 ) ;
V_27 = F_17 ( & V_4 -> V_7 , V_5 -> V_31 , V_5 ) ;
F_18 ( & V_4 -> V_6 ) ;
if ( V_27 )
goto V_32;
goto V_28;
V_32:
F_19 ( V_5 ) ;
V_30:
F_8 ( V_2 -> V_10 , V_11 ) ;
V_28:
F_19 ( V_26 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_22 * V_5 ;
F_16 ( & V_4 -> V_6 ) ;
V_5 = F_21 ( & V_4 -> V_7 , V_11 ) ;
F_18 ( & V_4 -> V_6 ) ;
if ( ! V_5 )
return;
F_8 ( V_2 -> V_10 , V_5 -> V_31 ) ;
F_19 ( V_5 ) ;
}
static void F_22 ( struct V_23 * V_24 )
{
struct V_25 * V_26 =
F_14 ( V_24 , struct V_25 , V_24 ) ;
struct V_1 * V_2 = V_26 -> V_2 ;
T_1 V_11 = V_26 -> V_11 ;
F_20 ( V_2 , V_11 ) ;
F_19 ( V_26 ) ;
}
void F_23 ( struct V_1 * V_2 , T_3 V_33 ,
T_1 V_11 , int V_34 )
{
struct V_25 * V_26 ;
V_26 = F_24 ( sizeof( * V_26 ) , V_8 ) ;
if ( ! V_26 )
return;
if ( V_34 )
F_25 ( & V_26 -> V_24 , F_13 ) ;
else
F_25 ( & V_26 -> V_24 , F_22 ) ;
V_26 -> V_2 = V_2 ;
V_26 -> V_11 = V_11 ;
V_26 -> V_33 = V_33 ;
F_26 ( V_2 -> V_35 , & V_26 -> V_24 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_22 * V_5 ;
unsigned int V_11 = 0 ;
F_16 ( & V_4 -> V_6 ) ;
while ( F_28 ( & V_4 -> V_7 , ( void * * ) & V_5 , V_11 , 1 ) ) {
V_11 = V_5 -> V_31 ;
F_18 ( & V_4 -> V_6 ) ;
F_20 ( V_2 , ( T_1 ) V_11 ) ;
F_16 ( & V_4 -> V_6 ) ;
}
F_18 ( & V_4 -> V_6 ) ;
}
