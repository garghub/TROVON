static const struct V_1 * F_1 (
struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_2 -> V_5 == V_4 [ V_3 ] . V_5 )
return & V_4 [ V_3 ] ;
return & V_4 [ 0 ] ;
}
static int F_3 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_5 )
{
if ( V_5 -> V_11 >= F_2 ( V_4 ) )
return - V_12 ;
V_5 -> V_5 = V_4 [ V_5 -> V_11 ] . V_5 ;
return 0 ;
}
static void F_4 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
const struct V_15 * V_16 = V_14 -> V_17 ;
const struct V_1 * V_18 ;
V_18 = F_1 ( V_2 ) ;
V_2 -> V_5 = V_18 -> V_5 ;
F_5 ( & V_2 -> V_19 , 16 + 8 , V_16 -> V_19 , 0 ,
& V_2 -> V_20 , 12 + 8 , V_16 -> V_20 , 0 , 0 ) ;
}
static struct V_1 * F_6 (
struct V_13 * V_14 , struct V_8 * V_9 ,
T_1 V_21 , enum V_22 V_23 )
{
if ( V_23 == V_24 )
return V_9 ? F_7 ( V_9 , V_21 ) : NULL ;
return & V_14 -> V_25 ;
}
static int F_8 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_26 * V_18 )
{
struct V_13 * V_14 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
F_4 ( V_14 , & V_18 -> V_25 ) ;
V_2 = F_6 ( V_14 , V_9 , V_18 -> V_21 , V_18 -> V_23 ) ;
if ( V_2 ) {
F_10 ( & V_14 -> V_27 ) ;
if ( V_18 -> V_23 == V_28 )
* V_2 = V_18 -> V_25 ;
F_11 ( & V_14 -> V_27 ) ;
}
return 0 ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_26 * V_18 )
{
struct V_13 * V_14 = F_9 ( V_7 ) ;
struct V_1 * V_2 ;
V_2 = F_6 ( V_14 , V_9 , V_18 -> V_21 , V_18 -> V_23 ) ;
F_10 ( & V_14 -> V_27 ) ;
V_18 -> V_25 = * V_2 ;
F_11 ( & V_14 -> V_27 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_1 * V_25 = F_7 ( V_9 , 0 ) ;
* V_25 = V_4 [ 0 ] ;
V_25 -> V_19 = V_29 ;
V_25 -> V_20 = V_30 ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 , int V_31 )
{
struct V_13 * V_14 = F_9 ( V_7 ) ;
int V_32 = V_14 -> V_33 ;
int V_34 ;
if ( V_31 ) {
V_34 = F_15 ( V_14 -> V_35 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_16 ( V_36 ,
V_14 -> V_37 ) ;
if ( V_34 < 0 ) {
F_17 ( V_14 -> V_35 ) ;
return V_34 ;
}
if ( F_18 ( V_32 ) ) {
F_19 ( V_32 , 1 ) ;
F_20 ( 600 , 800 ) ;
F_19 ( V_32 , 0 ) ;
F_20 ( 10000 , 11000 ) ;
F_19 ( V_32 , 1 ) ;
}
F_21 ( 20 ) ;
} else {
if ( F_18 ( V_32 ) )
F_19 ( V_32 , 0 ) ;
V_34 = F_22 ( V_36 ,
V_14 -> V_37 ) ;
if ( ! V_34 )
F_17 ( V_14 -> V_35 ) ;
}
F_23 ( L_1 , V_38 , __LINE__ , V_31 , V_34 ) ;
return V_34 ;
}
static int F_24 ( struct V_39 * V_40 ,
const struct V_41 * V_42 )
{
struct V_43 * V_35 = & V_40 -> V_35 ;
struct V_13 * V_14 ;
const struct V_44 * V_45 ;
struct V_6 * V_7 ;
int V_32 , V_3 , V_34 ;
V_14 = F_25 ( V_35 , sizeof( * V_14 ) , V_46 ) ;
if ( ! V_14 )
return - V_47 ;
F_26 ( & V_14 -> V_27 ) ;
V_14 -> V_33 = - V_12 ;
V_32 = F_27 ( V_35 -> V_48 , 0 , NULL ) ;
if ( F_18 ( V_32 ) ) {
V_34 = F_28 ( V_35 , V_32 , V_49 ,
V_50 ) ;
if ( V_34 < 0 )
return V_34 ;
}
V_14 -> V_33 = V_32 ;
for ( V_3 = 0 ; V_3 < V_36 ; V_3 ++ )
V_14 -> V_37 [ V_3 ] . V_51 = V_52 [ V_3 ] ;
V_34 = F_29 ( & V_40 -> V_35 , V_36 ,
V_14 -> V_37 ) ;
if ( V_34 < 0 )
return V_34 ;
V_45 = F_30 ( V_53 , V_35 -> V_48 ) ;
if ( ! V_45 )
return - V_54 ;
V_14 -> V_17 = V_45 -> V_55 ;
V_14 -> V_35 = V_35 ;
V_7 = & V_14 -> V_56 ;
F_31 ( V_7 , V_40 , & V_57 ) ;
snprintf ( V_7 -> V_58 , sizeof( V_7 -> V_58 ) , V_14 -> V_17 -> V_59 ) ;
V_14 -> V_56 . V_60 |= V_61 ;
V_14 -> V_25 . V_5 = V_4 [ 0 ] . V_5 ;
V_14 -> V_25 . V_19 = V_29 ;
V_14 -> V_25 . V_20 = V_30 ;
V_14 -> V_21 . V_60 = V_62 ;
V_34 = F_32 ( & V_7 -> V_63 , 1 , & V_14 -> V_21 , 0 ) ;
if ( V_34 < 0 )
return V_34 ;
F_33 ( V_35 ) ;
F_34 ( V_35 ) ;
return V_34 ;
}
static int F_35 ( struct V_39 * V_40 )
{
struct V_6 * V_7 = F_36 ( V_40 ) ;
F_37 ( & V_7 -> V_63 ) ;
return 0 ;
}
int F_38 ( void )
{
return F_39 ( & V_64 ) ;
}
void F_40 ( void )
{
F_41 ( & V_64 ) ;
}
