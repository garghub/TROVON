static void F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
return;
}
int F_2 ( struct V_5 * V_6 ,
struct V_7 * * V_8 ,
int V_9 , int V_10 , enum V_11 V_12 ,
int V_13 )
{
struct V_14 * V_15 = V_6 -> V_15 ;
struct V_7 * V_2 ;
int V_16 ;
V_2 = F_3 ( sizeof( * V_2 ) , V_17 , V_13 ) ;
if ( ! V_2 ) {
V_2 = F_4 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 ) {
F_5 ( V_6 , L_1 ) ;
return - V_18 ;
}
}
V_2 -> V_19 = V_9 ;
V_2 -> V_20 = V_2 -> V_19 * V_15 -> V_21 -> V_22 . V_23 ;
V_2 -> V_10 = V_10 ;
V_2 -> type = V_12 ;
V_2 -> V_24 = V_15 -> V_21 -> V_22 . V_25 ;
F_6 ( & V_15 -> V_21 -> V_26 -> V_27 -> V_21 , V_13 ) ;
V_16 = F_7 ( V_15 -> V_21 , & V_2 -> V_28 ,
V_2 -> V_20 ) ;
F_6 ( & V_15 -> V_21 -> V_26 -> V_27 -> V_21 , V_15 -> V_21 -> V_29 ) ;
if ( V_16 )
goto V_30;
V_2 -> V_31 = (struct V_32 * ) V_2 -> V_28 . V_31 . V_33 . V_31 ;
* V_8 = V_2 ;
return 0 ;
V_30:
F_8 ( V_2 ) ;
* V_8 = NULL ;
return V_16 ;
}
int F_9 ( struct V_5 * V_6 , struct V_7 * V_2 ,
int V_34 )
{
struct V_14 * V_15 = V_6 -> V_15 ;
int V_16 = 0 ;
int V_35 = 0 ;
bool V_36 = false ;
V_2 -> V_21 = V_15 -> V_37 [ V_6 -> V_38 ] ;
V_2 -> V_39 . V_40 = V_2 -> V_28 . V_41 . V_41 ;
V_2 -> V_39 . V_42 = V_2 -> V_28 . V_41 . V_41 + 1 ;
* V_2 -> V_39 . V_40 = 0 ;
* V_2 -> V_39 . V_42 = 0 ;
memset ( V_2 -> V_31 , 0 , V_2 -> V_20 ) ;
if ( V_2 -> type == V_43 ) {
if ( ! F_10 ( V_15 -> V_21 , V_6 -> V_38 ,
V_2 -> V_24 ) ) {
V_2 -> V_24 = F_11 ( V_6 -> V_44 [ V_2 -> V_10 ] -> V_45 ) ;
V_16 = F_12 ( V_15 -> V_21 , V_6 -> V_38 ,
& V_2 -> V_24 ) ;
if ( V_16 ) {
F_13 ( V_15 , L_2 ,
V_2 -> V_24 ) ;
goto V_46;
}
V_36 = true ;
}
V_2 -> V_47 =
F_14 ( F_15 ( V_15 -> V_21 ,
V_2 -> V_24 ) ) ;
} else {
struct V_7 * V_48 ;
V_34 = V_34 % V_6 -> V_49 ;
V_48 = V_6 -> V_48 [ V_34 ] ;
V_2 -> V_24 = V_48 -> V_24 ;
}
if ( V_2 -> type == V_43 )
V_2 -> V_19 = V_6 -> V_44 [ V_2 -> V_10 ] -> V_50 ;
if ( ( V_2 -> type != V_43 && V_6 -> V_51 . V_52 ) ||
( V_2 -> type == V_43 && V_6 -> V_51 . V_53 ) )
V_35 = 1 ;
V_16 = F_16 ( V_15 -> V_21 , V_2 -> V_19 , & V_2 -> V_28 . V_54 ,
& V_15 -> V_55 , V_2 -> V_28 . V_41 . V_56 , & V_2 -> V_39 ,
V_2 -> V_24 , 0 , V_35 ) ;
if ( V_16 )
goto V_46;
V_2 -> V_39 . V_4 = F_1 ;
switch ( V_2 -> type ) {
case V_57 :
V_2 -> V_39 . V_58 = V_59 ;
F_17 ( V_2 -> V_21 , & V_2 -> V_60 , V_61 ,
V_62 ) ;
F_18 ( & V_2 -> V_60 ) ;
break;
case V_43 :
V_2 -> V_39 . V_58 = V_63 ;
F_19 ( V_2 -> V_21 , & V_2 -> V_60 , V_64 , 64 ) ;
F_18 ( & V_2 -> V_60 ) ;
break;
case V_65 :
V_2 -> V_66 = false ;
break;
}
return 0 ;
V_46:
if ( V_36 )
F_20 ( V_15 -> V_21 , V_2 -> V_24 ) ;
V_2 -> V_24 = V_15 -> V_21 -> V_22 . V_25 ;
return V_16 ;
}
void F_21 ( struct V_5 * V_6 , struct V_7 * * V_8 )
{
struct V_14 * V_15 = V_6 -> V_15 ;
struct V_7 * V_2 = * V_8 ;
F_22 ( V_15 -> V_21 , & V_2 -> V_28 , V_2 -> V_20 ) ;
if ( F_10 ( V_15 -> V_21 , V_6 -> V_38 , V_2 -> V_24 ) &&
V_2 -> type == V_43 )
F_20 ( V_6 -> V_15 -> V_21 , V_2 -> V_24 ) ;
V_2 -> V_24 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_31 = NULL ;
F_8 ( V_2 ) ;
* V_8 = NULL ;
}
void F_23 ( struct V_5 * V_6 , struct V_7 * V_2 )
{
if ( V_2 -> type != V_65 ) {
F_24 ( & V_2 -> V_60 ) ;
F_25 ( & V_2 -> V_60 ) ;
}
F_26 ( V_6 -> V_15 -> V_21 , & V_2 -> V_39 ) ;
}
int F_27 ( struct V_5 * V_6 , struct V_7 * V_2 )
{
return F_28 ( V_6 -> V_15 -> V_21 , & V_2 -> V_39 ,
V_2 -> V_67 , V_2 -> V_68 ) ;
}
int F_29 ( struct V_5 * V_6 , struct V_7 * V_2 )
{
F_30 ( & V_2 -> V_39 , V_69 , V_6 -> V_15 -> V_70 ,
& V_6 -> V_15 -> V_71 ) ;
return 0 ;
}
