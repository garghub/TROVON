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
case 16 :
V_19 = V_20 ;
break;
case 20 :
V_19 = V_21 ;
break;
case 24 :
case 32 :
V_19 = V_22 ;
break;
default:
return - V_6 ;
}
F_5 ( V_17 -> V_23 , V_24 ,
V_25 ,
V_19 << V_26 ) ;
F_5 ( V_17 -> V_23 , V_27 ,
V_28 ,
V_19 << V_29 ) ;
return 0 ;
}
static int F_6 ( struct V_30 * V_18 )
{
struct V_16 * V_17 = F_3 ( V_18 ) ;
return F_5 ( V_17 -> V_23 , V_27 ,
V_31 , 0 ) ;
}
static int F_7 ( struct V_30 * V_18 )
{
struct V_16 * V_17 = F_3 ( V_18 ) ;
return F_5 ( V_17 -> V_23 , V_27 ,
V_31 , V_32 ) ;
}
static int F_8 ( struct V_30 * V_18 )
{
struct V_16 * V_17 = F_3 ( V_18 ) ;
struct V_33 * V_34 = F_9 ( V_18 ) ;
int V_35 , V_36 ;
int V_37 = 0 ;
int V_38 ;
V_35 = V_39 [ V_17 -> type ] . V_40 . V_41 / 2 ;
V_36 = V_39 [ V_17 -> type ] . V_42 . V_41 / 2 ;
F_10 ( V_17 -> V_23 , V_24 , 0x300 ) ;
F_10 ( V_17 -> V_23 , V_43 , 0x0 ) ;
F_10 ( V_17 -> V_23 , V_44 , 0x100 ) ;
F_10 ( V_17 -> V_23 , V_27 , 0x180 ) ;
for ( V_38 = 1 ; V_38 <= V_35 ; ++ V_38 ) {
F_10 ( V_17 -> V_23 , F_11 ( V_38 ) , 0x3FF ) ;
F_10 ( V_17 -> V_23 , F_12 ( V_38 ) , 0x3FF ) ;
}
if ( V_17 -> type == V_45 ) {
F_10 ( V_17 -> V_23 , V_46 , 0x3A ) ;
V_37 = F_13 ( V_18 , V_47 ,
F_14 ( V_47 ) ) ;
if ( V_37 )
return V_37 ;
} else {
F_10 ( V_17 -> V_23 , V_46 , 0x00 ) ;
}
V_37 = F_13 ( V_18 , V_48 , V_35 * 2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_13 ( V_18 , V_49 , V_36 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_15 ( V_34 , V_50 , V_35 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_15 ( V_34 , V_51 , V_36 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_16 ( V_34 , V_52 , V_35 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_16 ( V_34 , V_53 , V_36 ) ;
if ( V_37 )
return V_37 ;
return V_37 ;
}
static int F_17 ( struct V_30 * V_18 )
{
struct V_16 * V_17 = F_3 ( V_18 ) ;
return F_5 ( V_17 -> V_23 , V_27 ,
V_31 , 0 ) ;
}
static int F_18 ( struct V_54 * V_55 )
{
struct V_16 * V_17 ;
int V_37 ;
V_17 = F_19 ( & V_55 -> V_56 , sizeof( struct V_16 ) ,
V_57 ) ;
if ( V_17 == NULL )
return - V_58 ;
V_17 -> V_23 = F_20 ( V_55 , & V_59 ) ;
if ( F_21 ( V_17 -> V_23 ) )
return F_22 ( V_17 -> V_23 ) ;
V_17 -> type = F_23 ( V_55 ) -> V_60 ;
F_24 ( V_55 , V_17 ) ;
V_37 = F_25 ( & V_55 -> V_56 ,
& V_61 , & V_39 [ V_17 -> type ] , 1 ) ;
return V_37 ;
}
static int F_26 ( struct V_54 * V_55 )
{
F_27 ( & V_55 -> V_56 ) ;
return 0 ;
}
