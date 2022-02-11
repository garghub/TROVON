static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
if ( V_6 -> V_10 == NULL )
return;
if ( V_8 != & V_4 -> V_11 ) {
F_2 ( V_8 -> V_2 . V_2 , V_8 -> V_12 , V_8 -> V_13 ,
V_8 -> V_14 ) ;
F_3 ( V_6 -> V_9 ) ;
}
F_4 ( V_4 , NULL ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
int V_15 = V_4 -> V_16 -> V_17 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_18 * V_19 = V_4 -> V_20 ;
struct V_21 * V_22 = V_19 -> V_23 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_24 ;
struct V_25 * V_26 ;
T_1 V_27 , V_28 ;
struct V_29 * V_30 ;
F_6 ( V_2 , L_1 , V_31 , V_22 -> V_32 ,
F_7 ( V_4 ) ) ;
F_6 ( V_2 , L_2 , V_31 ) ;
if ( V_15 == V_33 )
F_8 ( V_4 ,
& V_34 ) ;
else
F_8 ( V_4 ,
& V_35 ) ;
V_24 = F_9 ( V_6 ,
V_36 ) ;
if ( V_24 < 0 ) {
F_10 ( V_2 , L_3 ,
V_31 , V_24 ) ;
return V_24 ;
}
F_6 ( V_2 , L_4 , V_31 ,
F_7 ( V_4 ) ) ;
V_6 -> V_37 = ( V_15 == V_33 ) ?
V_34 : V_35 ;
V_28 = V_38 ;
V_26 = F_11 ( V_22 , V_4 ) ;
switch ( V_26 -> V_39 ) {
case 32 :
V_27 = V_40 ;
break;
case 16 :
V_27 = V_38 ;
break;
case 8 :
V_27 = V_41 ;
break;
default:
V_27 = V_40 ;
F_12 ( V_19 -> V_42 -> V_2 ,
L_5 ,
V_31 , V_26 -> V_39 ) ;
}
V_30 = V_26 -> V_30 ;
if ( V_4 -> V_17 == V_33 ) {
V_30 -> V_43 . V_44 = V_28 ;
V_30 -> V_45 . V_44 = V_27 ;
} else {
V_30 -> V_43 . V_44 = V_27 ;
V_30 -> V_45 . V_44 = V_28 ;
}
V_24 = F_13 ( V_4 , V_46 , V_30 ) ;
if ( V_24 ) {
F_6 ( V_22 -> V_2 ,
L_6 ,
V_31 , V_24 ) ;
return V_24 ;
}
F_14 ( V_4 , V_30 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_18 * V_19 = V_4 -> V_20 ;
struct V_21 * V_22 = V_19 -> V_23 ;
F_6 ( V_22 -> V_2 , L_7 , V_31 ) ;
F_16 ( V_4 ) ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_47 * V_48 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_18 * V_19 = V_4 -> V_20 ;
int V_24 = 0 ;
int V_49 ;
F_6 ( V_19 -> V_42 -> V_2 , L_7 , V_31 ) ;
V_49 = F_18 ( V_48 ) ;
if ( V_8 ) {
if ( V_8 -> V_12 >= V_49 )
goto V_50;
F_1 ( NULL , V_4 ) ;
}
if ( V_4 -> V_11 . V_13 != NULL &&
V_4 -> V_11 . V_12 >= V_49 ) {
V_8 = & V_4 -> V_11 ;
} else {
V_8 = F_19 ( sizeof( struct V_7 ) , V_51 ) ;
if ( ! V_8 )
goto V_52;
V_8 -> V_2 . type = V_53 ;
V_8 -> V_2 . V_2 = NULL ;
V_8 -> V_13 = F_20 ( NULL , V_49 , & V_8 -> V_14 ,
V_51 ) ;
V_8 -> V_12 = V_49 ;
V_8 -> V_20 = NULL ;
if ( ! V_8 -> V_13 )
goto free;
}
F_4 ( V_4 , V_8 ) ;
V_24 = 1 ;
V_50:
V_6 -> V_54 = V_49 ;
return V_24 ;
free:
F_3 ( V_8 ) ;
V_52:
return - V_55 ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_18 * V_19 = V_4 -> V_20 ;
F_6 ( V_19 -> V_42 -> V_2 , L_7 , V_31 ) ;
F_1 ( NULL , V_4 ) ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 ,
struct V_56 * V_57 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_18 * V_19 = V_4 -> V_20 ;
F_6 ( V_19 -> V_42 -> V_2 , L_8 , V_31 ) ;
return F_23 ( NULL , V_57 , V_6 -> V_10 ,
V_6 -> V_58 , V_6 -> V_54 ) ;
}
int F_24 ( struct V_18 * V_19 )
{
struct V_59 * V_60 = V_19 -> V_60 ;
F_6 ( V_19 -> V_42 -> V_2 , L_9 , V_31 ,
V_60 -> V_32 ) ;
V_60 -> V_61 = 0 ;
return 0 ;
}
int F_25 ( struct V_62 * V_63 )
{
int V_24 ;
V_24 = F_26 ( & V_63 -> V_2 , & V_64 ) ;
if ( V_24 < 0 ) {
F_10 ( & V_63 -> V_2 ,
L_10 ,
V_31 , V_63 -> V_65 , V_24 ) ;
return V_24 ;
}
return 0 ;
}
int F_27 ( struct V_62 * V_63 )
{
F_28 ( & V_63 -> V_2 ) ;
return 0 ;
}
