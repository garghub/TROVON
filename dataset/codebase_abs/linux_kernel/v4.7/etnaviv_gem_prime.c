struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_3 ( ! V_5 -> V_6 ) ;
return V_5 -> V_6 ;
}
void * F_4 ( struct V_2 * V_3 )
{
return F_5 ( V_3 ) ;
}
void F_6 ( struct V_2 * V_3 , void * V_7 )
{
}
int F_7 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_8 ) {
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_8 ( & V_5 -> V_9 ) ;
F_9 ( V_5 ) ;
F_10 ( & V_5 -> V_9 ) ;
}
return 0 ;
}
void F_11 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_8 ) {
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_8 ( & V_5 -> V_9 ) ;
F_12 ( F_2 ( V_3 ) ) ;
F_10 ( & V_5 -> V_9 ) ;
}
}
static void F_13 ( struct V_4 * V_5 )
{
if ( V_5 -> V_7 )
F_14 ( V_5 -> V_10 . V_8 -> V_11 ,
V_5 -> V_7 ) ;
if ( V_5 -> V_12 )
F_15 ( V_5 -> V_12 ) ;
F_16 ( & V_5 -> V_10 , V_5 -> V_6 ) ;
}
static void * F_17 ( struct V_4 * V_5 )
{
F_18 ( & V_5 -> V_9 ) ;
return F_19 ( V_5 -> V_10 . V_8 -> V_11 ) ;
}
static int F_20 ( struct V_4 * V_5 ,
struct V_13 * V_14 )
{
return F_21 ( V_5 -> V_10 . V_15 , V_14 , 0 ) ;
}
struct V_2 * F_22 ( struct V_16 * V_17 ,
struct V_18 * V_19 , struct V_1 * V_6 )
{
struct V_4 * V_5 ;
T_1 V_20 = F_23 ( V_19 -> V_11 -> V_20 ) ;
int V_21 , V_22 ;
V_21 = F_24 ( V_17 , V_20 , V_23 ,
V_19 -> V_11 -> V_24 ,
& V_25 , & V_5 ) ;
if ( V_21 < 0 )
return F_25 ( V_21 ) ;
V_22 = V_20 / V_26 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_12 = F_26 ( V_22 , sizeof( struct V_27 * ) ) ;
if ( ! V_5 -> V_12 ) {
V_21 = - V_28 ;
goto V_29;
}
V_21 = F_27 ( V_6 , V_5 -> V_12 ,
NULL , V_22 ) ;
if ( V_21 )
goto V_29;
V_21 = F_28 ( V_17 , & V_5 -> V_10 ) ;
if ( V_21 )
goto V_29;
return & V_5 -> V_10 ;
V_29:
F_29 ( & V_5 -> V_10 ) ;
return F_25 ( V_21 ) ;
}
