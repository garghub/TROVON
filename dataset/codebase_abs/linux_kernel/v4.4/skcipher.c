static unsigned int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == & V_4 )
return sizeof( struct V_5 * ) ;
F_2 ( V_2 -> V_3 != & V_6 &&
V_2 -> V_3 != & V_7 ) ;
return sizeof( struct V_8 * ) ;
}
static int F_3 ( struct V_9 * V_10 ,
const T_1 * V_11 , unsigned int V_12 )
{
struct V_5 * * V_13 = F_4 ( V_10 ) ;
struct V_5 * V_14 = * V_13 ;
int V_15 ;
F_5 ( V_14 , ~ 0 ) ;
F_6 ( V_14 , F_7 ( V_10 ) &
V_16 ) ;
V_15 = F_8 ( V_14 , V_11 , V_12 ) ;
F_9 ( V_10 , F_10 ( V_14 ) &
V_17 ) ;
return V_15 ;
}
static int F_11 ( struct V_18 * V_19 ,
int (* F_12)( struct V_20 * ,
struct V_21 * ,
struct V_21 * ,
unsigned int ) )
{
struct V_9 * V_10 = F_13 ( V_19 ) ;
struct V_5 * * V_13 = F_4 ( V_10 ) ;
struct V_20 V_22 = {
. V_10 = * V_13 ,
. V_23 = V_19 -> V_24 ,
. V_25 = V_19 -> V_26 . V_25 ,
} ;
return F_12 ( & V_22 , V_19 -> V_27 , V_19 -> V_28 , V_19 -> V_29 ) ;
}
static int F_14 ( struct V_18 * V_19 )
{
struct V_9 * V_30 = F_13 ( V_19 ) ;
struct V_31 * V_10 = F_15 ( V_30 ) ;
struct V_32 * V_2 = & V_10 -> V_33 -> V_34 ;
return F_11 ( V_19 , V_2 -> V_35 ) ;
}
static int F_16 ( struct V_18 * V_19 )
{
struct V_9 * V_30 = F_13 ( V_19 ) ;
struct V_31 * V_10 = F_15 ( V_30 ) ;
struct V_32 * V_2 = & V_10 -> V_33 -> V_34 ;
return F_11 ( V_19 , V_2 -> V_36 ) ;
}
static void F_17 ( struct V_31 * V_10 )
{
struct V_5 * * V_13 = F_18 ( V_10 ) ;
F_19 ( * V_13 ) ;
}
static int F_20 ( struct V_31 * V_10 )
{
struct V_1 * V_37 = V_10 -> V_33 ;
struct V_9 * V_30 = F_21 ( V_10 ) ;
struct V_5 * * V_13 = F_18 ( V_10 ) ;
struct V_5 * V_14 ;
struct V_31 * V_38 ;
if ( ! F_22 ( V_37 ) )
return - V_39 ;
V_38 = F_23 ( V_37 , V_40 ,
V_41 ) ;
if ( F_24 ( V_38 ) ) {
F_25 ( V_37 ) ;
return F_26 ( V_38 ) ;
}
V_14 = F_27 ( V_38 ) ;
* V_13 = V_14 ;
V_10 -> exit = F_17 ;
V_30 -> V_42 = F_3 ;
V_30 -> V_35 = F_14 ;
V_30 -> V_36 = F_16 ;
V_30 -> V_43 = F_28 ( V_14 ) ;
return 0 ;
}
static int F_29 ( struct V_9 * V_10 ,
const T_1 * V_11 , unsigned int V_12 )
{
struct V_8 * * V_13 = F_4 ( V_10 ) ;
struct V_8 * V_44 = * V_13 ;
int V_15 ;
F_30 ( V_44 , ~ 0 ) ;
F_31 ( V_44 ,
F_7 ( V_10 ) &
V_16 ) ;
V_15 = F_32 ( V_44 , V_11 , V_12 ) ;
F_9 ( V_10 ,
F_33 ( V_44 ) &
V_17 ) ;
return V_15 ;
}
static int F_34 ( struct V_18 * V_19 ,
int (* F_12)( struct V_45 * ) )
{
struct V_9 * V_10 = F_13 ( V_19 ) ;
struct V_8 * * V_13 = F_4 ( V_10 ) ;
struct V_45 * V_46 = F_35 ( V_19 ) ;
F_36 ( V_46 , * V_13 ) ;
F_37 ( V_46 , F_38 ( V_19 ) ,
V_19 -> V_26 . V_47 , V_19 -> V_26 . V_48 ) ;
F_39 ( V_46 , V_19 -> V_28 , V_19 -> V_27 , V_19 -> V_29 ,
V_19 -> V_24 ) ;
return F_12 ( V_46 ) ;
}
static int F_40 ( struct V_18 * V_19 )
{
struct V_9 * V_30 = F_13 ( V_19 ) ;
struct V_31 * V_10 = F_15 ( V_30 ) ;
struct V_49 * V_2 = & V_10 -> V_33 -> V_50 ;
return F_34 ( V_19 , V_2 -> V_35 ) ;
}
static int F_41 ( struct V_18 * V_19 )
{
struct V_9 * V_30 = F_13 ( V_19 ) ;
struct V_31 * V_10 = F_15 ( V_30 ) ;
struct V_49 * V_2 = & V_10 -> V_33 -> V_50 ;
return F_34 ( V_19 , V_2 -> V_36 ) ;
}
static void F_42 ( struct V_31 * V_10 )
{
struct V_8 * * V_13 = F_18 ( V_10 ) ;
F_43 ( * V_13 ) ;
}
static int F_44 ( struct V_31 * V_10 )
{
struct V_1 * V_37 = V_10 -> V_33 ;
struct V_9 * V_30 = F_21 ( V_10 ) ;
struct V_8 * * V_13 = F_18 ( V_10 ) ;
struct V_8 * V_44 ;
struct V_31 * V_51 ;
if ( ! F_22 ( V_37 ) )
return - V_39 ;
V_51 = F_23 ( V_37 , 0 , 0 ) ;
if ( F_24 ( V_51 ) ) {
F_25 ( V_37 ) ;
return F_26 ( V_51 ) ;
}
V_44 = F_45 ( V_51 ) ;
* V_13 = V_44 ;
V_10 -> exit = F_42 ;
V_30 -> V_42 = F_29 ;
V_30 -> V_35 = F_40 ;
V_30 -> V_36 = F_41 ;
V_30 -> V_43 = F_46 ( V_44 ) ;
V_30 -> V_52 = F_47 ( V_44 ) +
sizeof( struct V_45 ) ;
return 0 ;
}
static int F_48 ( struct V_31 * V_10 )
{
if ( V_10 -> V_33 -> V_3 == & V_4 )
return F_20 ( V_10 ) ;
F_2 ( V_10 -> V_33 -> V_3 != & V_6 &&
V_10 -> V_33 -> V_3 != & V_7 ) ;
return F_44 ( V_10 ) ;
}
struct V_9 * F_49 ( const char * V_53 ,
T_2 type , T_2 V_54 )
{
return F_50 ( V_53 , & V_55 , type , V_54 ) ;
}
