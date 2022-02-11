struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_6 = V_3 -> V_7 >> V_8 ;
if ( F_3 ( ! V_5 -> V_9 ) )
return NULL ;
return F_4 ( V_5 -> V_9 , V_6 ) ;
}
void * F_5 ( struct V_2 * V_3 )
{
return F_6 ( V_3 ) ;
}
void F_7 ( struct V_2 * V_3 , void * V_10 )
{
}
int F_8 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_13 ;
V_13 = F_9 ( V_3 , V_3 -> V_7 , V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
return V_5 -> V_14 -> V_15 ( V_5 , V_12 ) ;
}
int F_10 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_16 ) {
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_11 ( & V_5 -> V_17 ) ;
F_12 ( V_5 ) ;
F_13 ( & V_5 -> V_17 ) ;
}
return 0 ;
}
void F_14 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_16 ) {
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_11 ( & V_5 -> V_17 ) ;
F_15 ( F_2 ( V_3 ) ) ;
F_13 ( & V_5 -> V_17 ) ;
}
}
static void F_16 ( struct V_4 * V_5 )
{
if ( V_5 -> V_10 )
F_17 ( V_5 -> V_18 . V_16 -> V_19 ,
V_5 -> V_10 ) ;
if ( V_5 -> V_9 )
F_18 ( V_5 -> V_9 ) ;
F_19 ( & V_5 -> V_18 , V_5 -> V_20 ) ;
}
static void * F_20 ( struct V_4 * V_5 )
{
F_21 ( & V_5 -> V_17 ) ;
return F_22 ( V_5 -> V_18 . V_16 -> V_19 ) ;
}
static int F_23 ( struct V_4 * V_5 ,
struct V_11 * V_12 )
{
return F_24 ( V_5 -> V_18 . V_21 , V_12 , 0 ) ;
}
struct V_2 * F_25 ( struct V_22 * V_23 ,
struct V_24 * V_25 , struct V_1 * V_20 )
{
struct V_4 * V_5 ;
T_1 V_7 = F_26 ( V_25 -> V_19 -> V_7 ) ;
int V_13 , V_6 ;
V_13 = F_27 ( V_23 , V_7 , V_26 ,
V_25 -> V_19 -> V_27 ,
& V_28 , & V_5 ) ;
if ( V_13 < 0 )
return F_28 ( V_13 ) ;
V_6 = V_7 / V_29 ;
V_5 -> V_20 = V_20 ;
V_5 -> V_9 = F_29 ( V_6 , sizeof( struct V_30 * ) ) ;
if ( ! V_5 -> V_9 ) {
V_13 = - V_31 ;
goto V_32;
}
V_13 = F_30 ( V_20 , V_5 -> V_9 ,
NULL , V_6 ) ;
if ( V_13 )
goto V_32;
V_13 = F_31 ( V_23 , & V_5 -> V_18 ) ;
if ( V_13 )
goto V_32;
return & V_5 -> V_18 ;
V_32:
F_32 ( & V_5 -> V_18 ) ;
return F_28 ( V_13 ) ;
}
