static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_6 * V_7 ;
V_7 = F_4 ( V_3 -> V_8 , V_5 -> V_7 ) ;
if ( ! V_7 ) {
F_5 ( L_1 ) ;
return 0 ;
}
if ( V_7 -> V_9 [ 0 ] == '\0' )
F_6 ( V_7 ) ;
V_7 -> type |= V_10 ;
F_7 ( V_3 , V_7 ) ;
if ( V_7 -> V_11 ) {
V_3 -> V_12 . V_11 = V_7 -> V_11 ;
V_3 -> V_12 . V_13 = V_7 -> V_13 ;
}
return 1 ;
}
static enum V_14
F_8 ( struct V_2 * V_3 , bool V_15 )
{
if ( F_9 ( V_3 -> V_8 ) )
return V_16 ;
return V_3 -> V_17 ;
}
static void F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_11 ( V_3 ) ;
F_12 ( V_5 ) ;
}
struct V_2 *
F_13 ( struct V_18 * V_19 ,
const struct V_6 * V_7 ,
int V_20 )
{
struct V_1 * V_5 ;
struct V_2 * V_3 ;
int V_21 ;
V_5 = F_14 ( sizeof( * V_5 ) , V_22 ) ;
if ( ! V_5 )
return F_15 ( - V_23 ) ;
V_5 -> V_7 = V_7 ;
V_3 = & V_5 -> V_4 ;
F_16 ( V_3 , & V_24 ) ;
V_21 = F_17 ( V_19 , V_3 , & V_25 ,
V_20 ) ;
if ( V_21 ) {
F_12 ( V_5 ) ;
return F_15 ( V_21 ) ;
}
V_3 -> V_17 = V_26 ;
return V_3 ;
}
void F_18 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 = F_19 ( V_28 ) ;
struct V_33 * V_34 = V_28 -> V_35 . V_36 -> V_34 ;
struct V_37 * V_38 = & V_32 -> V_28 . V_38 ;
if ( V_34 && ( V_34 != V_30 -> V_34 ) ) {
V_28 -> V_35 . V_34 = V_34 ;
if ( V_34 -> V_39 -> V_40 )
V_34 -> V_39 -> V_40 ( V_34 , NULL , 0 , 0 , NULL , 0 ) ;
}
if ( V_38 -> V_36 -> V_41 ) {
F_20 ( & V_38 -> V_8 -> V_42 ) ;
F_21 ( V_38 , V_38 -> V_36 -> V_41 ) ;
F_22 ( & V_38 -> V_8 -> V_42 ) ;
V_38 -> V_36 -> V_41 = NULL ;
}
}
int F_23 ( struct V_27 * V_28 ,
struct V_29 * V_43 )
{
return F_24 ( & V_28 -> V_35 , V_43 ) ;
}
static int F_25 ( struct V_6 * V_7 ,
unsigned int V_44 )
{
if ( V_44 == 0 || V_44 == 180 ) {
return 0 ;
} else if ( V_44 == 90 || V_44 == 270 ) {
F_26 ( V_7 -> V_45 , V_7 -> V_46 ) ;
F_26 ( V_7 -> V_47 , V_7 -> V_48 ) ;
F_26 ( V_7 -> V_49 , V_7 -> V_50 ) ;
F_26 ( V_7 -> V_51 , V_7 -> V_52 ) ;
F_26 ( V_7 -> V_11 , V_7 -> V_13 ) ;
return 0 ;
} else {
return - V_53 ;
}
}
int
F_27 ( struct V_31 * V_32 ,
const struct V_54 * V_39 ,
int V_20 ,
const T_1 * V_55 ,
unsigned int V_56 ,
const struct V_6 * V_7 ,
unsigned int V_44 )
{
struct V_18 * V_19 = V_32 -> V_19 ;
struct V_6 * V_57 ;
struct V_2 * V_3 ;
int V_21 ;
V_57 = F_28 ( V_19 -> V_8 , sizeof( * V_57 ) , V_22 ) ;
if ( ! V_57 )
return - V_23 ;
* V_57 = * V_7 ;
V_21 = F_25 ( V_57 , V_44 ) ;
if ( V_21 ) {
F_5 ( L_2 , V_44 ) ;
return - V_53 ;
}
V_19 -> V_58 . V_59 = V_57 -> V_45 ;
V_19 -> V_58 . V_60 = V_57 -> V_45 ;
V_19 -> V_58 . V_61 = V_57 -> V_46 ;
V_19 -> V_58 . V_62 = V_57 -> V_46 ;
V_3 = F_13 ( V_19 , V_57 , V_20 ) ;
if ( F_29 ( V_3 ) )
return F_30 ( V_3 ) ;
V_21 = F_31 ( V_19 , & V_32 -> V_28 , V_39 , V_55 ,
V_56 , NULL , V_3 ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
