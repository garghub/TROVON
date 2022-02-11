static struct V_1 * F_1 (
struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_3 ) ;
}
static void F_3 ( void * V_5 )
{
struct V_6 * V_7 = V_5 ;
unsigned long V_8 ;
F_4 ( & V_7 -> V_4 -> V_9 , V_8 ) ;
F_5 ( & V_7 -> V_10 ) ;
F_6 ( & V_7 -> V_4 -> V_9 , V_8 ) ;
F_7 ( V_7 ) ;
}
static int F_8 ( struct V_11 * V_4 ,
struct V_6 * V_7 )
{
struct V_1 * V_1 =
F_1 ( & V_4 -> V_3 ) ;
struct V_12 * V_13 ;
T_1 V_14 ;
V_7 -> V_15 = F_9 ( V_7 -> V_16 , V_1 -> V_17 ) ;
V_7 -> V_15 = F_10 ( V_7 -> V_15 ,
V_1 -> V_18 ) ;
V_13 = F_11 ( V_1 -> V_19 ,
V_7 -> V_20 , V_7 -> V_15 , V_21 ,
V_22 ) ;
if ( ! V_13 )
return - V_23 ;
V_13 -> V_24 = F_3 ;
V_13 -> V_25 = V_7 ;
V_14 = F_12 ( V_13 ) ;
if ( F_13 ( V_14 ) )
return F_13 ( V_14 ) ;
F_14 ( & V_1 -> V_4 . V_9 ) ;
F_15 ( & V_7 -> V_10 , & V_1 -> V_26 ) ;
F_16 ( & V_1 -> V_4 . V_9 ) ;
F_17 ( V_1 -> V_19 ) ;
return 0 ;
}
static void F_18 ( struct V_11 * V_4 )
{
struct V_1 * V_1 =
F_1 ( & V_4 -> V_3 ) ;
F_19 ( V_1 -> V_19 ) ;
F_20 ( V_4 , & V_1 -> V_26 ) ;
}
static void F_21 ( struct V_2 * V_27 )
{
struct V_1 * V_1 =
F_1 ( V_27 ) ;
F_22 ( & V_1 -> V_4 ) ;
F_23 ( V_1 ) ;
}
struct V_2 * F_24 ( struct V_28 * V_29 ,
const char * V_30 )
{
struct V_1 * V_1 ;
unsigned int V_31 , V_32 , V_33 ;
struct V_34 V_35 ;
struct V_36 * V_19 ;
int V_37 ;
V_1 = F_25 ( sizeof( * V_1 ) , V_38 ) ;
if ( ! V_1 )
return F_26 ( - V_23 ) ;
V_19 = F_27 ( V_29 , V_30 ) ;
if ( F_28 ( V_19 ) ) {
V_37 = F_29 ( V_19 ) ;
goto V_39;
}
V_37 = F_30 ( V_19 , & V_35 ) ;
if ( V_37 < 0 )
goto V_39;
if ( V_35 . V_40 )
V_32 = F_31 ( V_35 . V_40 ) ;
else
V_32 = 1 ;
if ( V_35 . V_41 )
V_33 = F_31 ( V_35 . V_41 ) ;
else
V_33 = 1 ;
V_31 = F_32 ( V_32 , V_33 ) ;
F_33 ( & V_1 -> V_26 ) ;
V_1 -> V_19 = V_19 ;
V_1 -> V_18 = V_31 ;
V_1 -> V_17 = F_34 ( V_19 -> V_28 -> V_29 ) ;
F_35 ( & V_1 -> V_4 , V_19 -> V_28 -> V_29 ,
& V_42 ) ;
V_1 -> V_4 . V_3 . V_43 = & V_44 ;
return & V_1 -> V_4 . V_3 ;
V_39:
F_23 ( V_1 ) ;
return F_26 ( V_37 ) ;
}
void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_1 =
F_1 ( V_3 ) ;
F_37 ( & V_1 -> V_4 ) ;
F_38 ( V_1 -> V_19 ) ;
F_39 ( V_3 ) ;
}
