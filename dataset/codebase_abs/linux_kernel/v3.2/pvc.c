static int F_1 ( struct V_1 * V_2 , int V_3 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_4 * V_4 ,
int V_5 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int error ;
if ( V_5 != sizeof( struct V_7 ) )
return - V_11 ;
V_8 = (struct V_7 * ) V_4 ;
if ( V_8 -> V_12 != V_13 )
return - V_14 ;
F_3 ( V_6 ) ;
V_10 = F_4 ( V_2 ) ;
if ( ! F_5 ( V_15 , & V_10 -> V_16 ) ) {
error = - V_17 ;
goto V_18;
}
if ( F_5 ( V_19 , & V_10 -> V_16 ) ) {
if ( V_10 -> V_20 != V_21 )
V_8 -> V_22 . V_20 = V_10 -> V_20 ;
if ( V_10 -> V_23 != V_24 )
V_8 -> V_22 . V_23 = V_10 -> V_23 ;
}
error = F_6 ( V_2 , V_8 -> V_22 . V_25 , V_8 -> V_22 . V_20 ,
V_8 -> V_22 . V_23 ) ;
V_18:
F_7 ( V_6 ) ;
return error ;
}
static int F_8 ( struct V_1 * V_2 , struct V_4 * V_4 ,
int V_5 , int V_16 )
{
return F_2 ( V_2 , V_4 , V_5 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_26 , int V_27 ,
char T_1 * V_28 , unsigned int V_29 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
int error ;
F_3 ( V_6 ) ;
error = F_10 ( V_2 , V_26 , V_27 , V_28 , V_29 ) ;
F_7 ( V_6 ) ;
return error ;
}
static int F_11 ( struct V_1 * V_2 , int V_26 , int V_27 ,
char T_1 * V_28 , int T_1 * V_29 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
int error ;
F_3 ( V_6 ) ;
error = F_12 ( V_2 , V_26 , V_27 , V_28 , V_29 ) ;
F_7 ( V_6 ) ;
return error ;
}
static int F_13 ( struct V_1 * V_2 , struct V_4 * V_4 ,
int * V_5 , int V_30 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( ! V_10 -> V_31 || ! F_5 ( V_32 , & V_10 -> V_16 ) )
return - V_33 ;
* V_5 = sizeof( struct V_7 ) ;
V_8 = (struct V_7 * ) V_4 ;
V_8 -> V_12 = V_13 ;
V_8 -> V_22 . V_25 = V_10 -> V_31 -> V_34 ;
V_8 -> V_22 . V_20 = V_10 -> V_20 ;
V_8 -> V_22 . V_23 = V_10 -> V_23 ;
return 0 ;
}
static int F_14 ( struct V_35 * V_35 , struct V_1 * V_2 , int V_36 ,
int V_37 )
{
if ( V_35 != & V_38 )
return - V_14 ;
V_2 -> V_39 = & V_40 ;
return F_15 ( V_35 , V_2 , V_36 , V_41 ) ;
}
int T_2 F_16 ( void )
{
return F_17 ( & V_42 ) ;
}
void F_18 ( void )
{
F_19 ( V_41 ) ;
}
