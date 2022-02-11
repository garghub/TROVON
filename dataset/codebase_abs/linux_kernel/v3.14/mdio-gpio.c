static void * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_2 ( & V_2 -> V_5 , sizeof( * V_8 ) , V_10 ) ;
if ( ! V_8 )
return NULL ;
V_9 = F_3 ( V_4 , 0 ) ;
if ( V_9 < 0 )
return NULL ;
V_8 -> V_11 = V_9 ;
V_9 = F_3 ( V_4 , 1 ) ;
if ( V_9 < 0 )
return NULL ;
V_8 -> V_12 = V_9 ;
return V_8 ;
}
static void F_4 ( struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 =
F_5 ( V_14 , struct V_16 , V_14 ) ;
if ( V_15 )
F_6 ( V_17 -> V_12 , 1 ) ;
else
F_7 ( V_17 -> V_12 ) ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_16 * V_17 =
F_5 ( V_14 , struct V_16 , V_14 ) ;
return F_9 ( V_17 -> V_12 ) ;
}
static void F_10 ( struct V_13 * V_14 , int V_18 )
{
struct V_16 * V_17 =
F_5 ( V_14 , struct V_16 , V_14 ) ;
F_11 ( V_17 -> V_12 , V_18 ) ;
}
static void F_12 ( struct V_13 * V_14 , int V_18 )
{
struct V_16 * V_17 =
F_5 ( V_14 , struct V_16 , V_14 ) ;
F_11 ( V_17 -> V_11 , V_18 ) ;
}
static struct V_19 * F_13 ( struct V_20 * V_5 ,
struct V_7 * V_8 ,
int V_21 )
{
struct V_19 * V_22 ;
struct V_16 * V_17 ;
int V_23 ;
V_17 = F_14 ( sizeof( * V_17 ) , V_10 ) ;
if ( ! V_17 )
goto V_24;
V_17 -> V_14 . V_25 = & V_26 ;
V_17 -> V_14 . V_27 = V_8 -> V_27 ;
V_17 -> V_11 = V_8 -> V_11 ;
V_17 -> V_12 = V_8 -> V_12 ;
V_22 = F_15 ( & V_17 -> V_14 ) ;
if ( ! V_22 )
goto V_28;
V_22 -> V_29 = L_1 ,
V_22 -> V_30 = V_8 -> V_30 ;
V_22 -> V_31 = V_8 -> V_32 ;
V_22 -> V_33 = V_5 ;
if ( V_22 -> V_30 == ~ 0 )
goto V_34;
for ( V_23 = 0 ; V_23 < V_35 ; V_23 ++ )
if ( ! V_22 -> V_31 [ V_23 ] )
V_22 -> V_31 [ V_23 ] = V_36 ;
snprintf ( V_22 -> V_37 , V_38 , L_2 , V_21 ) ;
if ( F_16 ( V_17 -> V_11 , L_3 ) )
goto V_34;
if ( F_16 ( V_17 -> V_12 , L_4 ) )
goto V_39;
F_6 ( V_17 -> V_11 , 0 ) ;
F_17 ( V_5 , V_22 ) ;
return V_22 ;
V_39:
F_18 ( V_17 -> V_11 ) ;
V_34:
F_19 ( V_22 ) ;
V_28:
F_20 ( V_17 ) ;
V_24:
return NULL ;
}
static void F_21 ( struct V_20 * V_5 )
{
struct V_19 * V_40 = F_22 ( V_5 ) ;
struct V_16 * V_17 = V_40 -> V_41 ;
F_17 ( V_5 , NULL ) ;
F_18 ( V_17 -> V_12 ) ;
F_18 ( V_17 -> V_11 ) ;
F_19 ( V_40 ) ;
F_20 ( V_17 ) ;
}
static void F_23 ( struct V_20 * V_5 )
{
struct V_19 * V_40 = F_22 ( V_5 ) ;
F_24 ( V_40 ) ;
F_21 ( V_5 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_19 * V_22 ;
int V_9 , V_21 ;
if ( V_2 -> V_5 . V_6 ) {
V_8 = F_1 ( V_2 ) ;
V_21 = F_26 ( V_2 -> V_5 . V_6 , L_5 ) ;
} else {
V_8 = F_27 ( & V_2 -> V_5 ) ;
V_21 = V_2 -> V_37 ;
}
if ( ! V_8 )
return - V_42 ;
V_22 = F_13 ( & V_2 -> V_5 , V_8 , V_21 ) ;
if ( ! V_22 )
return - V_42 ;
if ( V_2 -> V_5 . V_6 )
V_9 = F_28 ( V_22 , V_2 -> V_5 . V_6 ) ;
else
V_9 = F_29 ( V_22 ) ;
if ( V_9 )
F_21 ( & V_2 -> V_5 ) ;
return V_9 ;
}
static int F_30 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_5 ) ;
return 0 ;
}
