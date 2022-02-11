static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
switch ( V_3 & V_4 ) {
case V_5 :
break;
default:
return - V_6 ;
}
switch ( V_3 & V_7 ) {
case V_8 :
break;
default:
return - V_6 ;
}
switch ( V_3 & V_9 ) {
case V_10 :
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_2 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_1 * V_15 )
{
struct V_16 * V_17 = F_3 ( V_15 -> V_18 ) ;
int V_19 = 0 ;
switch ( F_4 ( V_14 ) ) {
case V_20 :
V_19 = V_21 ;
break;
case V_22 :
V_19 = V_23 ;
break;
case V_24 :
case V_25 :
V_19 = V_26 ;
break;
}
F_5 ( V_17 -> V_27 , V_28 ,
V_29 ,
V_19 << V_30 ) ;
F_5 ( V_17 -> V_27 , V_31 ,
V_32 ,
V_19 << V_33 ) ;
return 0 ;
}
static int F_6 ( struct V_34 * V_18 )
{
struct V_16 * V_17 = F_3 ( V_18 ) ;
return F_5 ( V_17 -> V_27 , V_31 ,
V_35 , 0 ) ;
}
static int F_7 ( struct V_34 * V_18 )
{
struct V_16 * V_17 = F_3 ( V_18 ) ;
return F_5 ( V_17 -> V_27 , V_31 ,
V_35 , V_36 ) ;
}
static int F_8 ( struct V_34 * V_18 )
{
struct V_16 * V_17 = F_3 ( V_18 ) ;
struct V_37 * V_38 = & V_18 -> V_38 ;
int V_39 , V_40 ;
int V_41 = 0 ;
int V_42 ;
V_39 = V_43 [ V_17 -> type ] . V_44 . V_45 / 2 ;
V_40 = V_43 [ V_17 -> type ] . V_46 . V_45 / 2 ;
F_9 ( V_17 -> V_27 , V_28 , 0x300 ) ;
F_9 ( V_17 -> V_27 , V_47 , 0x0 ) ;
F_9 ( V_17 -> V_27 , V_48 , 0x100 ) ;
F_9 ( V_17 -> V_27 , V_31 , 0x180 ) ;
for ( V_42 = 1 ; V_42 <= V_39 ; ++ V_42 ) {
F_9 ( V_17 -> V_27 , F_10 ( V_42 ) , 0x3FF ) ;
F_9 ( V_17 -> V_27 , F_11 ( V_42 ) , 0x3FF ) ;
}
if ( V_17 -> type == V_49 ) {
F_9 ( V_17 -> V_27 , V_50 , 0x3A ) ;
V_41 = F_12 ( V_18 , V_51 ,
F_13 ( V_51 ) ) ;
if ( V_41 )
return V_41 ;
} else {
F_9 ( V_17 -> V_27 , V_50 , 0x00 ) ;
}
V_41 = F_12 ( V_18 , V_52 , V_39 * 2 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_12 ( V_18 , V_53 , V_40 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_14 ( V_38 , V_54 , V_39 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_14 ( V_38 , V_55 , V_40 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_15 ( V_38 , V_56 , V_39 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_15 ( V_38 , V_57 , V_40 ) ;
if ( V_41 )
return V_41 ;
return V_41 ;
}
static int F_16 ( struct V_34 * V_18 )
{
struct V_16 * V_17 = F_3 ( V_18 ) ;
return F_5 ( V_17 -> V_27 , V_31 ,
V_35 , 0 ) ;
}
static int F_17 ( struct V_58 * V_59 )
{
struct V_16 * V_17 ;
int V_41 ;
V_17 = F_18 ( & V_59 -> V_60 , sizeof( struct V_16 ) ,
V_61 ) ;
if ( V_17 == NULL )
return - V_62 ;
V_17 -> V_27 = F_19 ( V_59 , & V_63 ) ;
if ( F_20 ( V_17 -> V_27 ) )
return F_21 ( V_17 -> V_27 ) ;
V_17 -> type = F_22 ( V_59 ) -> V_64 ;
F_23 ( V_59 , V_17 ) ;
V_41 = F_24 ( & V_59 -> V_60 ,
& V_65 , & V_43 [ V_17 -> type ] , 1 ) ;
return V_41 ;
}
static int F_25 ( struct V_58 * V_59 )
{
F_26 ( & V_59 -> V_60 ) ;
return 0 ;
}
