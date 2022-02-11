static bool F_1 ( const struct V_1 * V_2 ,
unsigned int V_3 ,
struct V_4 * V_5 )
{
const struct V_6 * V_7 ;
struct V_6 V_8 ;
V_7 = F_2 ( V_2 , V_3 , sizeof( V_8 ) , & V_8 ) ;
if ( V_7 == NULL )
return false ;
V_5 -> V_9 . V_10 . V_11 . V_12 = V_7 -> V_13 ;
V_5 -> V_14 . V_10 . V_11 . V_12 = V_7 -> V_15 ;
return true ;
}
static bool F_3 ( struct V_4 * V_5 ,
const struct V_4 * V_16 )
{
V_5 -> V_9 . V_10 . V_11 . V_12 = V_16 -> V_14 . V_10 . V_11 . V_12 ;
V_5 -> V_14 . V_10 . V_11 . V_12 = V_16 -> V_9 . V_10 . V_11 . V_12 ;
return true ;
}
static int F_4 ( struct V_17 * V_18 ,
const struct V_4 * V_5 )
{
return F_5 ( V_18 , L_1 ,
F_6 ( V_5 -> V_9 . V_10 . V_11 . V_12 ) ,
F_6 ( V_5 -> V_14 . V_10 . V_11 . V_12 ) ) ;
}
static int F_7 ( struct V_19 * V_20 ,
const struct V_1 * V_2 ,
unsigned int V_3 ,
enum V_21 V_22 ,
T_1 V_23 ,
unsigned int V_24 )
{
if ( F_8 ( V_25 , & V_20 -> V_26 ) ) {
F_9 ( V_20 , V_22 , V_2 , V_27 ) ;
if ( ! F_10 ( V_28 , & V_20 -> V_26 ) )
F_11 ( V_29 , V_20 ) ;
} else
F_9 ( V_20 , V_22 , V_2 , V_30 ) ;
return V_31 ;
}
static bool F_12 ( struct V_19 * V_20 , const struct V_1 * V_2 ,
unsigned int V_3 )
{
return true ;
}
static int F_13 ( struct V_32 * V_32 , struct V_19 * V_33 , struct V_1 * V_2 ,
unsigned int V_3 , enum V_21 * V_22 ,
T_1 V_23 ,
unsigned int V_24 )
{
unsigned int V_34 = V_2 -> V_35 - V_3 ;
const struct V_6 * V_36 ;
struct V_6 V_8 ;
V_36 = F_2 ( V_2 , V_3 , sizeof( V_8 ) , & V_8 ) ;
if ( V_36 == NULL ) {
if ( F_14 ( V_32 , V_37 ) )
F_15 ( V_23 , 0 , V_2 , NULL , NULL , NULL ,
L_2 ) ;
return - V_31 ;
}
if ( F_6 ( V_36 -> V_35 ) > V_34 || F_6 ( V_36 -> V_35 ) < sizeof( * V_36 ) ) {
if ( F_14 ( V_32 , V_37 ) )
F_15 ( V_23 , 0 , V_2 , NULL , NULL , NULL ,
L_3 ) ;
return - V_31 ;
}
if ( ! V_36 -> V_38 )
return V_31 ;
if ( V_32 -> V_20 . V_39 && V_24 == V_40 &&
F_16 ( V_2 , V_24 , V_3 , V_37 , V_23 ) ) {
if ( F_14 ( V_32 , V_37 ) )
F_15 ( V_23 , 0 , V_2 , NULL , NULL , NULL ,
L_4 ) ;
return - V_31 ;
}
return V_31 ;
}
