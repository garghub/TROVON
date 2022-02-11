static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
V_6 = F_3 ( V_2 -> V_7 ) ;
if ( V_6 == NULL )
return 0 ;
V_6 -> type = V_8 | V_9 ;
V_6 -> clock = V_4 -> V_10 -> V_6 . clock ;
V_6 -> V_11 = V_4 -> V_10 -> V_6 . V_11 ;
V_6 -> V_12 = V_4 -> V_10 -> V_6 . V_12 ;
V_6 -> V_13 = V_4 -> V_10 -> V_6 . V_13 ;
V_6 -> V_14 = V_4 -> V_10 -> V_6 . V_14 ;
V_6 -> V_15 = V_4 -> V_10 -> V_6 . V_15 ;
V_6 -> V_16 = V_4 -> V_10 -> V_6 . V_16 ;
V_6 -> V_17 = V_4 -> V_10 -> V_6 . V_17 ;
V_6 -> V_18 = V_4 -> V_10 -> V_6 . V_18 ;
V_6 -> V_19 = V_4 -> V_10 -> V_6 . V_19 ;
F_4 ( V_6 ) ;
F_5 ( V_2 , V_6 ) ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
return V_20 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
}
static enum V_21
F_10 ( struct V_1 * V_2 , bool V_22 )
{
return V_23 ;
}
static int F_11 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const struct V_28 * V_10 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_29 ;
V_4 = F_12 ( V_25 -> V_7 , sizeof( * V_4 ) , V_30 ) ;
if ( V_4 == NULL )
return - V_31 ;
V_4 -> V_10 = V_10 ;
V_2 = & V_4 -> V_2 . V_2 ;
V_2 -> V_32 . V_33 = V_10 -> V_33 ;
V_2 -> V_32 . V_34 = V_10 -> V_34 ;
V_29 = F_13 ( V_25 -> V_35 , V_2 , & V_36 ,
V_37 ) ;
if ( V_29 < 0 )
return V_29 ;
F_14 ( V_2 , & V_38 ) ;
V_29 = F_15 ( V_2 ) ;
if ( V_29 < 0 )
return V_29 ;
F_16 ( V_2 , V_39 ) ;
F_17 ( & V_2 -> V_40 ,
V_25 -> V_35 -> V_41 . V_42 , V_39 ) ;
V_29 = F_18 ( V_2 , & V_27 -> V_43 ) ;
if ( V_29 < 0 )
return V_29 ;
V_2 -> V_43 = & V_27 -> V_43 ;
V_4 -> V_2 . V_43 = V_27 ;
return 0 ;
}
static void F_19 ( struct V_44 * V_43 , int V_6 )
{
}
static bool F_20 ( struct V_44 * V_43 ,
const struct V_5 * V_6 ,
struct V_5 * V_45 )
{
const struct V_5 * V_46 ;
struct V_47 * V_7 = V_43 -> V_7 ;
struct V_1 * V_2 ;
bool V_48 = false ;
F_21 (connector, &dev->mode_config.connector_list, head) {
if ( V_2 -> V_43 == V_43 ) {
V_48 = true ;
break;
}
}
if ( ! V_48 ) {
F_22 ( V_7 -> V_7 , L_1 ) ;
return false ;
}
if ( F_23 ( & V_2 -> V_49 ) ) {
F_22 ( V_7 -> V_7 , L_2 ) ;
return false ;
}
V_46 = F_24 ( & V_2 -> V_49 ,
struct V_5 , V_50 ) ;
if ( V_6 -> V_11 != V_46 -> V_11 ||
V_6 -> V_15 != V_46 -> V_15 )
return false ;
F_25 ( V_45 , V_46 ) ;
return true ;
}
int F_26 ( struct V_24 * V_25 ,
const struct V_51 * V_52 ,
unsigned int V_53 )
{
struct V_26 * V_27 ;
int V_29 ;
V_27 = F_12 ( V_25 -> V_7 , sizeof( * V_27 ) , V_30 ) ;
if ( V_27 == NULL )
return - V_31 ;
V_27 -> V_53 = V_53 ;
V_29 = F_27 ( V_25 -> V_35 , & V_27 -> V_43 , & V_54 ,
V_55 ) ;
if ( V_29 < 0 )
return V_29 ;
F_28 ( & V_27 -> V_43 , & V_56 ) ;
return F_11 ( V_25 , V_27 , & V_52 -> V_10 ) ;
}
