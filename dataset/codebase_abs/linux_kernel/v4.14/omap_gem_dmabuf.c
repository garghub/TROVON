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
V_12 = F_4 ( V_7 , & V_11 ) ;
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
static int F_17 ( struct V_18 * V_19 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = V_19 -> V_9 ;
struct V_20 * * V_21 ;
if ( F_18 ( V_7 ) & V_22 ) {
return - V_14 ;
}
return F_19 ( V_7 , & V_21 , true ) ;
}
static int F_20 ( struct V_18 * V_19 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = V_19 -> V_9 ;
F_21 ( V_7 ) ;
return 0 ;
}
static void * F_22 ( struct V_18 * V_19 ,
unsigned long V_23 )
{
struct V_6 * V_7 = V_19 -> V_9 ;
struct V_20 * * V_21 ;
F_19 ( V_7 , & V_21 , false ) ;
F_23 ( V_7 , V_23 ) ;
return F_24 ( V_21 [ V_23 ] ) ;
}
static void F_25 ( struct V_18 * V_19 ,
unsigned long V_23 , void * V_24 )
{
F_26 ( V_24 ) ;
}
static void * F_27 ( struct V_18 * V_19 ,
unsigned long V_23 )
{
struct V_6 * V_7 = V_19 -> V_9 ;
struct V_20 * * V_21 ;
F_19 ( V_7 , & V_21 , false ) ;
F_23 ( V_7 , V_23 ) ;
return F_28 ( V_21 [ V_23 ] ) ;
}
static void F_29 ( struct V_18 * V_19 ,
unsigned long V_23 , void * V_24 )
{
struct V_6 * V_7 = V_19 -> V_9 ;
struct V_20 * * V_21 ;
F_19 ( V_7 , & V_21 , false ) ;
F_30 ( V_21 [ V_23 ] ) ;
}
static int F_31 ( struct V_18 * V_19 ,
struct V_25 * V_26 )
{
struct V_6 * V_7 = V_19 -> V_9 ;
int V_12 = 0 ;
V_12 = F_32 ( V_7 , F_33 ( V_7 ) , V_26 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_34 ( V_7 , V_26 ) ;
}
struct V_18 * F_35 ( struct V_27 * V_28 ,
struct V_6 * V_7 , int V_29 )
{
F_36 ( V_30 ) ;
V_30 . V_31 = & V_32 ;
V_30 . V_17 = V_7 -> V_17 ;
V_30 . V_29 = V_29 ;
V_30 . V_9 = V_7 ;
return F_37 ( V_28 , & V_30 ) ;
}
struct V_6 * F_38 ( struct V_27 * V_28 ,
struct V_18 * V_18 )
{
struct V_2 * V_33 ;
struct V_6 * V_7 ;
struct V_1 * V_34 ;
int V_12 ;
if ( V_18 -> V_31 == & V_32 ) {
V_7 = V_18 -> V_9 ;
if ( V_7 -> V_28 == V_28 ) {
F_39 ( V_7 ) ;
return V_7 ;
}
}
V_33 = F_40 ( V_18 , V_28 -> V_28 ) ;
if ( F_41 ( V_33 ) )
return F_42 ( V_33 ) ;
F_43 ( V_18 ) ;
V_34 = F_44 ( V_33 , V_35 ) ;
if ( F_41 ( V_34 ) ) {
V_12 = F_45 ( V_34 ) ;
goto V_36;
}
V_7 = F_46 ( V_28 , V_18 -> V_17 , V_34 ) ;
if ( F_41 ( V_7 ) ) {
V_12 = F_45 ( V_7 ) ;
goto V_37;
}
V_7 -> V_38 = V_33 ;
return V_7 ;
V_37:
F_47 ( V_33 , V_34 , V_35 ) ;
V_36:
F_48 ( V_18 , V_33 ) ;
F_49 ( V_18 ) ;
return F_3 ( V_12 ) ;
}
