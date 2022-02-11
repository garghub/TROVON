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
struct V_2 * F_20 ( struct V_13 * V_14 ,
struct V_15 * V_16 , struct V_1 * V_6 )
{
struct V_4 * V_5 ;
T_1 V_17 = F_21 ( V_16 -> V_11 -> V_17 ) ;
int V_18 , V_19 ;
V_18 = F_22 ( V_14 , V_17 , V_20 ,
V_16 -> V_11 -> V_21 ,
& V_22 , & V_5 ) ;
if ( V_18 < 0 )
return F_23 ( V_18 ) ;
V_19 = V_17 / V_23 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_12 = F_24 ( V_19 , sizeof( struct V_24 * ) ) ;
if ( ! V_5 -> V_12 ) {
V_18 = - V_25 ;
goto V_26;
}
V_18 = F_25 ( V_6 , V_5 -> V_12 ,
NULL , V_19 ) ;
if ( V_18 )
goto V_26;
V_18 = F_26 ( V_14 , & V_5 -> V_10 ) ;
if ( V_18 )
goto V_26;
return & V_5 -> V_10 ;
V_26:
F_27 ( & V_5 -> V_10 ) ;
return F_23 ( V_18 ) ;
}
