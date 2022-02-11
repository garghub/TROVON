static T_1 F_1 ( T_2 V_1 , const char * V_2 ,
int V_3 )
{
struct V_4 V_5 ;
union V_6 V_7 ;
T_3 V_8 ;
T_1 V_9 ;
F_2 ( V_1 , L_1 ,
V_2 , V_3 ) ;
V_7 . type = V_10 ;
V_7 . integer . V_11 = V_3 ;
V_5 . V_12 = 1 ;
V_5 . V_13 = & V_7 ;
V_8 = F_3 ( V_1 , ( V_14 ) V_2 , & V_5 , & V_9 ) ;
if ( F_4 ( V_8 ) )
F_5 ( V_1 ,
L_2 ,
V_2 , V_3 , V_8 ) ;
F_2 ( V_1 , L_3 , V_2 , ( V_15 ) V_9 ) ;
return V_9 ;
}
static enum V_16 F_6 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
int V_8 ;
V_20 = F_7 ( V_18 , struct V_19 , V_18 ) ;
V_8 = F_1 ( F_8 ( V_20 -> V_21 ) , L_4 ,
V_20 -> V_22 -> V_23 ) ;
if ( V_8 == V_20 -> V_22 -> V_24 )
return V_25 ;
return V_26 ;
}
static void F_9 ( struct V_27 * V_28 )
{
struct V_19 * V_20 ;
V_20 = F_7 ( V_28 , struct V_19 , V_29 ) ;
F_1 ( F_8 ( V_20 -> V_21 ) , L_4 ,
V_20 -> V_30 ) ;
}
static void F_10 ( struct V_17 * V_18 , enum V_16 V_11 )
{
struct V_19 * V_20 ;
V_20 = F_7 ( V_18 , struct V_19 , V_18 ) ;
V_20 -> V_30 = V_11 == V_26 ? V_20 -> V_22 -> V_31 :
V_20 -> V_22 -> V_24 ;
F_11 ( V_20 -> V_32 , & V_20 -> V_29 ) ;
}
static void F_12 ( struct V_33 * V_21 , T_4 V_34 )
{
struct V_19 * V_20 = F_13 ( V_21 ) ;
F_14 ( & V_21 -> V_35 , L_5 , V_34 ) ;
if ( V_34 != 0x88 ) {
F_15 ( & V_21 -> V_35 , L_6 , V_34 ) ;
return;
}
F_16 ( V_20 -> V_36 , V_37 , 1 ) ;
F_16 ( V_20 -> V_36 , V_37 , 0 ) ;
F_17 ( V_20 -> V_36 ) ;
}
static int F_18 ( struct V_33 * V_21 )
{
struct V_19 * V_20 ;
const struct V_38 * V_39 ;
int V_40 ;
V_20 = F_19 ( & V_21 -> V_35 , sizeof( * V_20 ) , V_41 ) ;
if ( ! V_20 )
return - V_42 ;
V_21 -> V_43 = V_20 ;
V_20 -> V_21 = V_21 ;
V_20 -> V_36 = F_20 ( & V_21 -> V_35 ) ;
if ( ! V_20 -> V_36 )
return - V_42 ;
V_20 -> V_36 -> V_44 = L_7 ;
V_20 -> V_36 -> V_45 = L_8 ;
V_20 -> V_36 -> V_39 . V_46 = V_47 ;
V_20 -> V_36 -> V_39 . V_48 = V_49 ;
F_21 ( V_50 , V_20 -> V_36 -> V_51 ) ;
F_21 ( V_37 , V_20 -> V_36 -> V_52 ) ;
V_40 = F_22 ( V_20 -> V_36 ) ;
if ( V_40 )
return V_40 ;
for ( V_39 = V_53 ; V_39 -> V_39 [ 0 ] ; V_39 ++ ) {
if ( ! strcmp ( ( char * ) V_39 -> V_39 , F_23 ( V_21 ) ) ) {
V_20 -> V_22 =
( const struct V_22 * ) V_39 -> V_43 ;
break;
}
}
if ( ! V_20 -> V_22 )
return 0 ;
V_20 -> V_32 = F_24 ( L_9 ) ;
if ( ! V_20 -> V_32 )
return - V_42 ;
F_25 ( & V_20 -> V_29 , F_9 ) ;
V_20 -> V_18 . V_44 = L_10 ;
V_20 -> V_18 . V_54 = F_10 ;
V_20 -> V_18 . V_55 = F_6 ;
V_20 -> V_18 . V_56 = V_57 ;
V_20 -> V_18 . V_58 = 1 ;
V_40 = F_26 ( & V_21 -> V_35 , & V_20 -> V_18 ) ;
if ( V_40 )
F_27 ( V_20 -> V_32 ) ;
return V_40 ;
}
static int F_28 ( struct V_33 * V_21 )
{
struct V_19 * V_20 = F_13 ( V_21 ) ;
if ( V_20 -> V_32 )
F_27 ( V_20 -> V_32 ) ;
return 0 ;
}
