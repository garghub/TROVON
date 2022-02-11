void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
F_2 ( & V_4 -> V_6 ) ;
F_3 ( & V_4 -> V_7 , V_8 ) ;
}
static int F_4 ( struct V_9 * V_10 , T_1 V_11 )
{
struct V_12 * V_13 ;
int V_14 ;
T_2 V_15 [ F_5 ( V_16 ) ] ;
T_2 V_17 [ F_5 ( V_18 ) ] ;
memset ( V_15 , 0 , sizeof( V_15 ) ) ;
memset ( V_17 , 0 , sizeof( V_17 ) ) ;
F_6 ( V_16 , V_15 , V_19 ,
V_20 ) ;
F_6 ( V_16 , V_15 , V_21 , V_11 ) ;
V_14 = F_7 ( V_10 , V_15 , sizeof( V_15 ) , V_17 , sizeof( V_17 ) ) ;
if ( V_14 )
return V_14 ;
V_13 = (struct V_12 * ) V_17 ;
return V_13 -> V_22 ? - V_23 : 0 ;
}
static int F_8 ( struct V_9 * V_10 , T_1 V_11 )
{
T_2 V_15 [ F_5 ( V_24 ) ] ;
T_2 V_17 [ F_5 ( V_25 ) ] ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
F_6 ( V_24 , V_15 , V_19 ,
V_26 ) ;
F_6 ( V_24 , V_15 , V_21 , V_11 ) ;
return F_9 ( V_10 , V_15 , sizeof( V_15 ) , V_17 ,
sizeof( V_17 ) ) ;
}
struct V_27 * F_10 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_27 * V_5 ;
F_11 ( & V_4 -> V_6 ) ;
V_5 = F_12 ( & V_4 -> V_7 , V_11 ) ;
F_13 ( & V_4 -> V_6 ) ;
return V_5 ;
}
static void F_14 ( struct V_28 * V_29 )
{
struct V_30 * V_31 =
F_15 ( V_29 , struct V_30 , V_29 ) ;
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
T_1 V_11 = V_31 -> V_11 ;
struct V_27 * V_5 ;
int V_14 ;
if ( F_4 ( V_2 -> V_10 , V_11 ) )
goto V_32;
V_5 = F_16 ( sizeof( * V_5 ) , V_33 ) ;
if ( ! V_5 )
goto V_34;
V_5 -> V_35 = V_11 ;
F_17 ( & V_4 -> V_6 ) ;
V_14 = F_18 ( & V_4 -> V_7 , V_5 -> V_35 , V_5 ) ;
F_19 ( & V_4 -> V_6 ) ;
if ( V_14 )
goto V_36;
goto V_32;
V_36:
F_20 ( V_5 ) ;
V_34:
F_8 ( V_2 -> V_10 , V_11 ) ;
V_32:
F_20 ( V_31 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_27 * V_5 ;
F_17 ( & V_4 -> V_6 ) ;
V_5 = F_22 ( & V_4 -> V_7 , V_11 ) ;
F_19 ( & V_4 -> V_6 ) ;
if ( ! V_5 )
return;
F_8 ( V_2 -> V_10 , V_5 -> V_35 ) ;
F_20 ( V_5 ) ;
}
static void F_23 ( struct V_28 * V_29 )
{
struct V_30 * V_31 =
F_15 ( V_29 , struct V_30 , V_29 ) ;
struct V_1 * V_2 = V_31 -> V_2 ;
T_1 V_11 = V_31 -> V_11 ;
F_21 ( V_2 , V_11 ) ;
F_20 ( V_31 ) ;
}
void F_24 ( struct V_1 * V_2 , T_3 V_37 ,
T_1 V_11 , int V_38 )
{
struct V_30 * V_31 ;
V_31 = F_25 ( sizeof( * V_31 ) , V_8 ) ;
if ( ! V_31 )
return;
if ( V_38 )
F_26 ( & V_31 -> V_29 , F_14 ) ;
else
F_26 ( & V_31 -> V_29 , F_23 ) ;
V_31 -> V_2 = V_2 ;
V_31 -> V_11 = V_11 ;
V_31 -> V_37 = V_37 ;
F_27 ( V_2 -> V_39 , & V_31 -> V_29 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_27 * V_5 ;
unsigned int V_11 = 0 ;
F_17 ( & V_4 -> V_6 ) ;
while ( F_29 ( & V_4 -> V_7 , ( void * * ) & V_5 , V_11 , 1 ) ) {
V_11 = V_5 -> V_35 ;
F_19 ( & V_4 -> V_6 ) ;
F_21 ( V_2 , ( T_1 ) V_11 ) ;
F_17 ( & V_4 -> V_6 ) ;
}
F_19 ( & V_4 -> V_6 ) ;
}
