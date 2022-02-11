static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_6 = V_3 ;
F_3 ( & V_4 -> V_7 , 1 ) ;
return V_4 ;
}
static void F_4 ( struct V_1 * V_4 )
{
if ( V_4 -> V_8 ) {
F_5 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
}
if ( V_4 -> V_9 ) {
F_6 ( V_4 -> V_9 ) ;
V_4 -> V_9 = NULL ;
}
F_7 ( V_4 ) ;
}
int F_8 ( const struct V_10 * V_11 , struct V_1 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_14 ;
struct V_2 * V_3 ;
int V_15 = 0 ;
F_9 ( & V_13 -> V_16 ) ;
if ( ! F_10 ( & V_4 -> V_7 ) ) {
F_11 ( & V_13 -> V_16 ) ;
return V_15 ;
}
V_13 -> V_17 [ V_4 -> V_18 ] = NULL ;
F_11 ( & V_13 -> V_16 ) ;
V_3 = V_4 -> V_6 ;
F_9 ( & V_3 -> V_19 ) ;
F_11 ( & V_3 -> V_19 ) ;
F_12 ( V_3 -> V_20 == 1 ||
V_3 -> V_21 == 1 || V_3 -> V_22 == 0 ,
L_1 , ! ! V_3 -> V_20 ,
! ! V_3 -> V_21 , ! ! V_3 -> V_22 ) ;
if ( F_13 ( V_4 , V_23 ) )
V_15 = F_13 ( V_4 , V_23 ) ( V_11 , V_4 ) ;
F_4 ( V_4 ) ;
F_14 ( & V_13 -> V_24 ) ;
return V_15 ;
}
int F_15 ( const struct V_10 * V_11 , struct V_1 * V_4 )
{
struct V_25 V_26 = F_16 ( V_27 , NULL ) ;
struct V_12 * V_13 ;
int V_15 , V_28 ;
F_17 ( V_4 != NULL ) ;
F_17 ( V_4 != V_29 ) ;
V_13 = V_4 -> V_14 ;
F_17 ( V_13 != NULL ) ;
F_17 ( V_13 != V_29 ) ;
V_28 = V_4 -> V_18 ;
F_17 ( F_18 ( & V_4 -> V_7 ) < V_30 ) ;
F_17 ( F_18 ( & V_4 -> V_7 ) > 1 ) ;
F_19 ( V_4 ) ;
V_15 = F_8 ( V_11 , V_4 ) ;
if ( V_15 )
F_20 ( L_2 ,
V_15 , V_4 ) ;
F_21 ( V_13 -> V_24 ,
F_22 ( V_13 , V_28 ) , & V_26 ) ;
return V_15 ;
}
int F_23 ( const struct V_10 * V_11 , struct V_2 * V_3 ,
struct V_12 * V_13 , int V_31 ,
struct V_2 * V_32 , struct V_33 * V_34 )
{
struct V_1 * V_4 ;
int V_15 = 0 ;
if ( V_31 < 0 || V_31 >= V_35 )
return - V_36 ;
F_17 ( V_13 != NULL ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_37 ;
V_4 -> V_6 = V_3 ;
V_4 -> V_14 = V_13 ;
V_4 -> V_18 = V_31 ;
V_4 -> V_38 = V_34 ;
F_24 ( & V_4 -> V_39 ) ;
V_4 -> V_8 = F_25 ( V_32 -> V_40 ) ;
V_4 -> V_41 = V_42 ;
V_15 = F_26 ( V_13 , V_4 , V_31 ) ;
if ( V_15 ) {
F_4 ( V_4 ) ;
if ( V_15 == - V_43 ) {
V_4 = F_27 ( V_13 , V_31 ) ;
if ( V_4 ) {
F_28 ( V_44 , L_3 ,
V_3 -> V_45 , V_31 ) ;
F_17 ( V_4 -> V_14 == V_13 ) ;
F_17 ( V_4 -> V_6 == V_3 ) ;
F_17 ( V_4 -> V_8 == V_32 -> V_40 ) ;
F_17 ( V_4 -> V_38 == V_34 ) ;
F_19 ( V_4 ) ;
}
V_15 = 0 ;
}
return V_15 ;
}
if ( V_34 -> V_46 ) {
if ( F_29 ( V_47 ) )
V_15 = - V_48 ;
else
V_15 = V_34 -> V_46 ( V_11 , V_3 , V_13 , V_31 , V_32 ) ;
}
if ( V_15 ) {
F_20 ( L_4 ,
V_3 -> V_45 , V_31 , V_34 -> V_46 , V_15 ) ;
F_30 ( V_13 , V_31 ) ;
F_4 ( V_4 ) ;
} else {
F_28 ( V_44 , L_5 ,
V_3 -> V_45 , V_31 ) ;
V_4 -> V_41 &= ~ V_42 ;
}
return V_15 ;
}
int F_31 ( struct V_1 * V_4 , struct V_49 * exp , int V_50 )
{
int V_15 = 0 ;
if ( ! V_4 )
return 0 ;
if ( F_13 ( V_4 , V_51 ) )
V_15 = F_13 ( V_4 , V_51 ) ( V_4 , exp , V_50 ) ;
return V_15 ;
}
int F_32 ( const struct V_10 * V_11 , struct V_1 * V_4 ,
struct V_52 * V_53 , int V_50 )
{
int V_15 ;
if ( ! V_4 ) {
F_20 ( L_6 ) ;
return - V_54 ;
}
F_33 ( V_4 , V_55 , - V_48 ) ;
V_15 = F_13 ( V_4 , V_55 ) ( V_11 , V_4 , V_53 , V_50 ) ;
return V_15 ;
}
int F_34 ( void )
{
F_35 ( & V_56 , NULL ) ;
F_36 ( & V_56 ) ;
return 0 ;
}
void F_37 ( void )
{
F_38 ( & V_56 ) ;
}
