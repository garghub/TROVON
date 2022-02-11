static struct V_1 * F_1 (
struct V_2 * V_3 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 -> V_9 ;
struct V_1 * V_10 ;
T_1 V_11 ;
int V_12 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_13 ) ;
if ( ! V_10 )
return F_3 ( - V_14 ) ;
V_12 = F_4 ( V_7 , & V_11 , true ) ;
if ( V_12 )
goto V_15;
V_12 = F_5 ( V_10 , 1 , V_13 ) ;
if ( V_12 )
goto V_15;
F_6 ( V_10 -> V_16 , 1 ) ;
F_7 ( V_10 -> V_16 ) = V_7 -> V_17 ;
F_8 ( V_10 -> V_16 , F_9 ( F_10 ( V_11 ) ) , V_7 -> V_17 , 0 ) ;
F_11 ( V_10 -> V_16 ) = V_11 ;
F_12 ( V_7 , V_5 ) ;
return V_10 ;
V_15:
F_13 ( V_10 ) ;
return F_3 ( V_12 ) ;
}
static void F_14 ( struct V_2 * V_3 ,
struct V_1 * V_10 , enum V_4 V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 -> V_9 ;
F_15 ( V_7 ) ;
F_16 ( V_10 ) ;
F_13 ( V_10 ) ;
}
static void F_17 ( struct V_18 * V_19 )
{
struct V_6 * V_7 = V_19 -> V_9 ;
F_18 ( V_7 ) ;
}
static int F_19 ( struct V_18 * V_19 ,
T_2 V_20 , T_2 V_21 , enum V_4 V_5 )
{
struct V_6 * V_7 = V_19 -> V_9 ;
struct V_22 * * V_23 ;
if ( F_20 ( V_7 ) & V_24 ) {
return - V_14 ;
}
return F_21 ( V_7 , & V_23 , true ) ;
}
static void F_22 ( struct V_18 * V_19 ,
T_2 V_20 , T_2 V_21 , enum V_4 V_5 )
{
struct V_6 * V_7 = V_19 -> V_9 ;
F_23 ( V_7 ) ;
}
static void * F_24 ( struct V_18 * V_19 ,
unsigned long V_25 )
{
struct V_6 * V_7 = V_19 -> V_9 ;
struct V_22 * * V_23 ;
F_21 ( V_7 , & V_23 , false ) ;
F_25 ( V_7 , V_25 ) ;
return F_26 ( V_23 [ V_25 ] ) ;
}
static void F_27 ( struct V_18 * V_19 ,
unsigned long V_25 , void * V_26 )
{
F_28 ( V_26 ) ;
}
static void * F_29 ( struct V_18 * V_19 ,
unsigned long V_25 )
{
struct V_6 * V_7 = V_19 -> V_9 ;
struct V_22 * * V_23 ;
F_21 ( V_7 , & V_23 , false ) ;
F_25 ( V_7 , V_25 ) ;
return F_30 ( V_23 [ V_25 ] ) ;
}
static void F_31 ( struct V_18 * V_19 ,
unsigned long V_25 , void * V_26 )
{
struct V_6 * V_7 = V_19 -> V_9 ;
struct V_22 * * V_23 ;
F_21 ( V_7 , & V_23 , false ) ;
F_32 ( V_23 [ V_25 ] ) ;
}
static int F_33 ( struct V_18 * V_19 ,
struct V_27 * V_28 )
{
struct V_6 * V_7 = V_19 -> V_9 ;
struct V_29 * V_30 = V_7 -> V_30 ;
int V_12 = 0 ;
if ( F_34 ( ! V_7 -> V_31 ) )
return - V_32 ;
F_35 ( & V_30 -> V_33 ) ;
V_12 = F_36 ( V_7 , F_37 ( V_7 ) , V_28 ) ;
F_38 ( & V_30 -> V_33 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_39 ( V_7 , V_28 ) ;
}
struct V_18 * F_40 ( struct V_29 * V_30 ,
struct V_6 * V_7 , int V_34 )
{
F_41 ( V_35 ) ;
V_35 . V_36 = & V_37 ;
V_35 . V_17 = V_7 -> V_17 ;
V_35 . V_34 = V_34 ;
V_35 . V_9 = V_7 ;
return F_42 ( & V_35 ) ;
}
struct V_6 * F_43 ( struct V_29 * V_30 ,
struct V_18 * V_19 )
{
struct V_6 * V_7 ;
if ( V_19 -> V_36 == & V_37 ) {
V_7 = V_19 -> V_9 ;
if ( V_7 -> V_30 == V_30 ) {
F_44 ( V_7 ) ;
return V_7 ;
}
}
return F_3 ( - V_32 ) ;
}
