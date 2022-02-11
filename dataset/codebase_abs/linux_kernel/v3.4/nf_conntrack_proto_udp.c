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
static unsigned int * F_7 ( struct V_19 * V_19 )
{
return V_20 ;
}
static int F_8 ( struct V_21 * V_22 ,
const struct V_1 * V_2 ,
unsigned int V_3 ,
enum V_23 V_24 ,
T_1 V_25 ,
unsigned int V_26 ,
unsigned int * V_27 )
{
if ( F_9 ( V_28 , & V_22 -> V_29 ) ) {
F_10 ( V_22 , V_24 , V_2 ,
V_27 [ V_30 ] ) ;
if ( ! F_11 ( V_31 , & V_22 -> V_29 ) )
F_12 ( V_32 , V_22 ) ;
} else {
F_10 ( V_22 , V_24 , V_2 ,
V_27 [ V_33 ] ) ;
}
return V_34 ;
}
static bool F_13 ( struct V_21 * V_22 , const struct V_1 * V_2 ,
unsigned int V_3 , unsigned int * V_27 )
{
return true ;
}
static int F_14 ( struct V_19 * V_19 , struct V_21 * V_35 , struct V_1 * V_2 ,
unsigned int V_3 , enum V_23 * V_24 ,
T_1 V_25 ,
unsigned int V_26 )
{
unsigned int V_36 = V_2 -> V_37 - V_3 ;
const struct V_6 * V_38 ;
struct V_6 V_8 ;
V_38 = F_2 ( V_2 , V_3 , sizeof( V_8 ) , & V_8 ) ;
if ( V_38 == NULL ) {
if ( F_15 ( V_19 , V_39 ) )
F_16 ( V_25 , 0 , V_2 , NULL , NULL , NULL ,
L_2 ) ;
return - V_34 ;
}
if ( F_6 ( V_38 -> V_37 ) > V_36 || F_6 ( V_38 -> V_37 ) < sizeof( * V_38 ) ) {
if ( F_15 ( V_19 , V_39 ) )
F_16 ( V_25 , 0 , V_2 , NULL , NULL , NULL ,
L_3 ) ;
return - V_34 ;
}
if ( ! V_38 -> V_40 )
return V_34 ;
if ( V_19 -> V_22 . V_41 && V_26 == V_42 &&
F_17 ( V_2 , V_26 , V_3 , V_39 , V_25 ) ) {
if ( F_15 ( V_19 , V_39 ) )
F_16 ( V_25 , 0 , V_2 , NULL , NULL , NULL ,
L_4 ) ;
return - V_34 ;
}
return V_34 ;
}
static int F_18 ( struct V_43 * V_44 [] , void * V_45 )
{
unsigned int * V_27 = V_45 ;
V_27 [ V_33 ] = V_20 [ V_33 ] ;
V_27 [ V_30 ] = V_20 [ V_30 ] ;
if ( V_44 [ V_46 ] ) {
V_27 [ V_33 ] =
F_19 ( F_20 ( V_44 [ V_46 ] ) ) * V_47 ;
}
if ( V_44 [ V_48 ] ) {
V_27 [ V_30 ] =
F_19 ( F_20 ( V_44 [ V_48 ] ) ) * V_47 ;
}
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 , const void * V_45 )
{
const unsigned int * V_27 = V_45 ;
F_22 ( V_2 , V_46 ,
F_23 ( V_27 [ V_33 ] / V_47 ) ) ;
F_22 ( V_2 , V_48 ,
F_23 ( V_27 [ V_30 ] / V_47 ) ) ;
return 0 ;
V_49:
return - V_50 ;
}
