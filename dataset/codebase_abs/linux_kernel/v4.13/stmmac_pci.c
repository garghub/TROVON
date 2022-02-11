static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
const struct V_7 * V_8 ;
const struct V_3 * V_9 ;
int V_10 = F_2 ( V_2 -> V_11 ) ;
T_1 V_12 ;
V_9 = F_3 ( V_4 ) ;
if ( ! V_9 )
return - V_13 ;
V_8 = V_9 -> V_14 ;
V_6 = V_8 -> V_10 ;
for ( V_12 = 0 ; V_12 < V_8 -> V_15 ; V_12 ++ , V_6 ++ )
if ( V_6 -> V_10 == V_10 )
return V_6 -> V_16 ;
return - V_13 ;
}
static void F_4 ( struct V_17 * V_18 )
{
V_18 -> V_19 = 2 ;
V_18 -> V_20 = 1 ;
V_18 -> V_21 = 1 ;
V_18 -> V_22 -> V_23 = NULL ;
V_18 -> V_22 -> V_24 = 0 ;
V_18 -> V_25 = V_26 ;
V_18 -> V_27 = 1 ;
V_18 -> V_28 = V_29 ;
V_18 -> V_30 = 1 ;
V_18 -> V_31 = 1 ;
V_18 -> V_32 [ 0 ] . V_33 = false ;
V_18 -> V_34 [ 0 ] . V_33 = false ;
V_18 -> V_34 [ 0 ] . V_35 = 0x0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
F_4 ( V_18 ) ;
V_18 -> V_36 = 1 ;
V_18 -> V_16 = 0 ;
V_18 -> V_37 = V_38 ;
V_18 -> V_39 -> V_40 = 32 ;
V_18 -> V_39 -> V_41 = true ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
int V_42 ;
F_4 ( V_18 ) ;
V_42 = F_1 ( V_2 , V_43 ) ;
if ( V_42 < 0 ) {
if ( F_7 ( V_44 ) )
return V_42 ;
V_42 = 1 ;
}
V_18 -> V_36 = F_8 ( V_2 -> V_45 -> V_46 , V_2 -> V_11 ) ;
V_18 -> V_16 = V_42 ;
V_18 -> V_37 = V_47 ;
V_18 -> V_39 -> V_40 = 16 ;
V_18 -> V_39 -> V_41 = true ;
V_18 -> V_39 -> V_48 = 1 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_49 * V_50 )
{
struct V_51 * V_52 = (struct V_51 * ) V_50 -> V_14 ;
struct V_17 * V_18 ;
struct V_53 V_54 ;
int V_55 ;
int V_42 ;
V_18 = F_10 ( & V_2 -> V_56 , sizeof( * V_18 ) , V_57 ) ;
if ( ! V_18 )
return - V_58 ;
V_18 -> V_22 = F_10 ( & V_2 -> V_56 ,
sizeof( * V_18 -> V_22 ) ,
V_57 ) ;
if ( ! V_18 -> V_22 )
return - V_58 ;
V_18 -> V_39 = F_10 ( & V_2 -> V_56 , sizeof( * V_18 -> V_39 ) ,
V_57 ) ;
if ( ! V_18 -> V_39 )
return - V_58 ;
V_42 = F_11 ( V_2 ) ;
if ( V_42 ) {
F_12 ( & V_2 -> V_56 , L_1 ,
V_59 ) ;
return V_42 ;
}
for ( V_55 = 0 ; V_55 <= V_60 ; V_55 ++ ) {
if ( F_13 ( V_2 , V_55 ) == 0 )
continue;
V_42 = F_14 ( V_2 , F_15 ( V_55 ) , F_16 ( V_2 ) ) ;
if ( V_42 )
return V_42 ;
break;
}
F_17 ( V_2 ) ;
V_42 = V_52 -> V_61 ( V_2 , V_18 ) ;
if ( V_42 )
return V_42 ;
F_18 ( V_2 ) ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_62 = F_19 ( V_2 ) [ V_55 ] ;
V_54 . V_63 = V_2 -> V_64 ;
V_54 . V_64 = V_2 -> V_64 ;
return F_20 ( & V_2 -> V_56 , V_18 , & V_54 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_56 ) ;
}
