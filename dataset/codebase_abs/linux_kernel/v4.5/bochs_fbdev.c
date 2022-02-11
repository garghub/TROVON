static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 =
F_2 ( V_6 , struct V_8 , V_10 . V_11 ) ;
struct V_12 * V_13 = F_3 ( V_9 -> V_10 . V_14 . V_15 ) ;
return F_4 ( V_4 , & V_13 -> V_13 ) ;
}
static int F_5 ( struct V_8 * V_9 ,
const struct V_16 * V_17 ,
struct V_18 * * V_19 )
{
struct V_20 * V_21 = V_9 -> V_21 ;
struct V_18 * V_22 ;
T_1 V_23 ;
int V_24 = 0 ;
V_23 = V_17 -> V_25 [ 0 ] * V_17 -> V_26 ;
V_24 = F_6 ( V_21 , V_23 , true , & V_22 ) ;
if ( V_24 )
return V_24 ;
* V_19 = V_22 ;
return V_24 ;
}
static int F_7 ( struct V_5 * V_11 ,
struct V_27 * V_28 )
{
struct V_8 * V_9 =
F_2 ( V_11 , struct V_8 , V_10 . V_11 ) ;
struct V_1 * V_2 ;
struct V_29 * V_10 ;
struct V_16 V_17 ;
struct V_18 * V_22 = NULL ;
struct V_12 * V_13 = NULL ;
int V_23 , V_24 ;
if ( V_28 -> V_30 != 32 )
return - V_31 ;
V_17 . V_32 = V_28 -> V_33 ;
V_17 . V_26 = V_28 -> V_34 ;
V_17 . V_25 [ 0 ] = V_17 . V_32 * ( ( V_28 -> V_30 + 7 ) / 8 ) ;
V_17 . V_35 = F_8 ( V_28 -> V_30 ,
V_28 -> V_36 ) ;
V_23 = V_17 . V_25 [ 0 ] * V_17 . V_26 ;
V_24 = F_5 ( V_9 , & V_17 , & V_22 ) ;
if ( V_24 ) {
F_9 ( L_1 , V_24 ) ;
return V_24 ;
}
V_13 = F_3 ( V_22 ) ;
V_24 = F_10 ( & V_13 -> V_13 , true , false , false , NULL ) ;
if ( V_24 )
return V_24 ;
V_24 = F_11 ( V_13 , V_37 , NULL ) ;
if ( V_24 ) {
F_9 ( L_2 ) ;
F_12 ( & V_13 -> V_13 ) ;
return V_24 ;
}
V_24 = F_13 ( & V_13 -> V_13 , 0 , V_13 -> V_13 . V_38 ,
& V_13 -> V_39 ) ;
if ( V_24 ) {
F_9 ( L_3 ) ;
F_12 ( & V_13 -> V_13 ) ;
return V_24 ;
}
F_12 ( & V_13 -> V_13 ) ;
V_2 = F_14 ( V_11 ) ;
if ( F_15 ( V_2 ) )
return F_16 ( V_2 ) ;
V_2 -> V_7 = & V_9 -> V_10 . V_11 ;
V_24 = F_17 ( V_9 -> V_21 , & V_9 -> V_10 . V_14 , & V_17 , V_22 ) ;
if ( V_24 ) {
F_18 ( V_11 ) ;
return V_24 ;
}
V_9 -> V_10 . V_23 = V_23 ;
V_10 = & V_9 -> V_10 . V_14 . V_40 ;
V_9 -> V_10 . V_11 . V_10 = V_10 ;
strcpy ( V_2 -> V_41 . V_42 , L_4 ) ;
V_2 -> V_43 = V_44 ;
V_2 -> V_45 = & V_46 ;
F_19 ( V_2 , V_10 -> V_25 [ 0 ] , V_10 -> V_47 ) ;
F_20 ( V_2 , & V_9 -> V_10 . V_11 , V_28 -> V_48 ,
V_28 -> V_49 ) ;
V_2 -> V_50 = V_13 -> V_39 . V_51 ;
V_2 -> V_52 = V_23 ;
F_21 ( & V_13 -> V_13 . V_53 -> V_54 , & V_13 -> V_13 . V_55 ) ;
V_2 -> V_41 . V_56 = 0 ;
V_2 -> V_41 . V_57 = V_23 ;
return 0 ;
}
static int F_22 ( struct V_8 * V_9 )
{
struct V_58 * V_14 = & V_9 -> V_10 . V_14 ;
F_23 ( L_5 ) ;
F_24 ( & V_9 -> V_10 . V_11 ) ;
F_18 ( & V_9 -> V_10 . V_11 ) ;
if ( V_14 -> V_15 ) {
F_25 ( V_14 -> V_15 ) ;
V_14 -> V_15 = NULL ;
}
F_26 ( & V_9 -> V_10 . V_11 ) ;
F_27 ( & V_14 -> V_40 ) ;
F_28 ( & V_14 -> V_40 ) ;
return 0 ;
}
void F_29 ( struct V_59 * V_60 , T_2 V_61 , T_2 V_62 ,
T_2 V_63 , int V_64 )
{
}
void F_30 ( struct V_59 * V_60 , T_2 * V_61 , T_2 * V_62 ,
T_2 * V_63 , int V_64 )
{
* V_61 = V_64 ;
* V_62 = V_64 ;
* V_63 = V_64 ;
}
int F_31 ( struct V_8 * V_9 )
{
int V_24 ;
F_32 ( V_9 -> V_21 , & V_9 -> V_10 . V_11 ,
& V_65 ) ;
V_24 = F_33 ( V_9 -> V_21 , & V_9 -> V_10 . V_11 ,
1 , 1 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_34 ( & V_9 -> V_10 . V_11 ) ;
if ( V_24 )
goto V_66;
F_35 ( V_9 -> V_21 ) ;
V_24 = F_36 ( & V_9 -> V_10 . V_11 , 32 ) ;
if ( V_24 )
goto V_66;
V_9 -> V_10 . V_67 = true ;
return 0 ;
V_66:
F_26 ( & V_9 -> V_10 . V_11 ) ;
return V_24 ;
}
void F_37 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_10 . V_67 )
return;
F_22 ( V_9 ) ;
V_9 -> V_10 . V_67 = false ;
}
