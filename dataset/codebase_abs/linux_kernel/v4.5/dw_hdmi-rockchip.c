static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
V_2 -> V_7 = F_2 ( V_4 , L_1 ) ;
if ( F_3 ( V_2 -> V_7 ) ) {
F_4 ( V_2 -> V_5 , L_2 ) ;
return F_5 ( V_2 -> V_7 ) ;
}
return 0 ;
}
static enum V_8
F_6 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
const struct V_13 * V_14 = V_15 ;
int V_16 = V_12 -> clock * 1000 ;
bool V_17 = false ;
int V_18 ;
for ( V_18 = 0 ; V_14 [ V_18 ] . V_19 != ( ~ 0UL ) ; V_18 ++ ) {
if ( V_16 == V_14 [ V_18 ] . V_19 ) {
V_17 = true ;
break;
}
}
return ( V_17 ) ? V_20 : V_21 ;
}
static void F_7 ( struct V_22 * V_23 )
{
}
static bool
F_8 ( struct V_22 * V_23 ,
const struct V_11 * V_12 ,
struct V_11 * V_24 )
{
return true ;
}
static void F_9 ( struct V_22 * V_23 ,
struct V_11 * V_12 ,
struct V_11 * V_24 )
{
}
static void F_10 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_11 ( V_23 ) ;
T_1 V_25 ;
int V_26 ;
F_12 ( V_23 -> V_27 , V_28 ,
V_29 ) ;
V_26 = F_13 ( V_2 -> V_5 -> V_6 , V_23 ) ;
if ( V_26 )
V_25 = V_30 | ( V_30 << 16 ) ;
else
V_25 = V_30 << 16 ;
F_14 ( V_2 -> V_7 , V_31 , V_25 ) ;
F_15 ( V_2 -> V_5 , L_3 ,
( V_26 ) ? L_4 : L_5 ) ;
}
static int F_16 ( struct V_32 * V_5 , struct V_32 * V_33 ,
void * V_34 )
{
struct V_35 * V_36 = F_17 ( V_5 ) ;
const struct V_37 * V_38 ;
const struct V_39 * V_40 ;
struct V_41 * V_42 = V_34 ;
struct V_22 * V_23 ;
struct V_1 * V_2 ;
struct V_43 * V_44 ;
int V_45 ;
int V_46 ;
if ( ! V_36 -> V_5 . V_6 )
return - V_47 ;
V_2 = F_18 ( & V_36 -> V_5 , sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 )
return - V_49 ;
V_40 = F_19 ( V_50 , V_36 -> V_5 . V_6 ) ;
V_38 = V_40 -> V_34 ;
V_2 -> V_5 = & V_36 -> V_5 ;
V_23 = & V_2 -> V_23 ;
V_45 = F_20 ( V_36 , 0 ) ;
if ( V_45 < 0 )
return V_45 ;
V_44 = F_21 ( V_36 , V_51 , 0 ) ;
if ( ! V_44 )
return - V_52 ;
F_22 ( V_36 , V_2 ) ;
V_23 -> V_53 = F_23 ( V_42 , V_5 -> V_6 ) ;
if ( V_23 -> V_53 == 0 )
return - V_54 ;
V_46 = F_1 ( V_2 ) ;
if ( V_46 ) {
F_4 ( V_2 -> V_5 , L_6 ) ;
return V_46 ;
}
F_24 ( V_23 , & V_55 ) ;
F_25 ( V_42 , V_23 , & V_56 ,
V_57 , NULL ) ;
return F_26 ( V_5 , V_33 , V_34 , V_23 , V_44 , V_45 , V_38 ) ;
}
static void F_27 ( struct V_32 * V_5 , struct V_32 * V_33 ,
void * V_34 )
{
return F_28 ( V_5 , V_33 , V_34 ) ;
}
static int F_29 ( struct V_35 * V_36 )
{
return F_30 ( & V_36 -> V_5 , & V_58 ) ;
}
static int F_31 ( struct V_35 * V_36 )
{
F_32 ( & V_36 -> V_5 , & V_58 ) ;
return 0 ;
}
