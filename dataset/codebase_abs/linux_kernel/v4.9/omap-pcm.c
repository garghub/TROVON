static void F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; V_1 ++ ) {
switch ( F_2 ( V_1 ) ) {
case 8 :
case 16 :
case 32 :
V_3 . V_4 |= ( 1LL << V_1 ) ;
break;
default:
break;
}
}
}
static int F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_11 * V_12 = V_6 -> V_13 ;
struct V_14 * V_15 ;
struct V_16 V_17 ;
struct V_18 * V_19 ;
int V_20 = 0 ;
memset ( & V_17 , 0x00 , sizeof( V_17 ) ) ;
V_15 = F_4 ( V_12 -> V_21 , V_6 ) ;
if ( ! V_15 )
return 0 ;
F_5 ( V_6 , & V_6 -> V_22 ) ;
V_10 -> V_23 = F_6 ( V_8 ) ;
V_19 = F_7 ( V_6 ) ;
if ( ! V_19 )
return - V_24 ;
V_20 = F_8 ( V_6 , V_8 , & V_17 ) ;
if ( V_20 )
return V_20 ;
F_9 ( V_6 ,
F_4 ( V_12 -> V_21 , V_6 ) ,
& V_17 ) ;
return F_10 ( V_19 , & V_17 ) ;
}
static int F_11 ( struct V_5 * V_6 )
{
F_5 ( V_6 , NULL ) ;
return 0 ;
}
static T_1 F_12 ( struct V_5 * V_6 )
{
T_1 V_25 ;
if ( F_13 () )
V_25 = F_14 ( V_6 ) ;
else
V_25 = F_15 ( V_6 ) ;
return V_25 ;
}
static int F_16 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
struct V_26 * V_15 ;
int V_27 ;
F_17 ( V_6 , & V_3 ) ;
V_15 = F_4 ( V_12 -> V_21 , V_6 ) ;
if ( V_12 -> V_21 -> V_28 -> V_29 ) {
struct V_18 * V_19 ;
V_19 = F_18 ( V_12 -> V_21 -> V_28 ,
V_15 -> V_30 ) ;
V_27 = F_19 ( V_6 , V_19 ) ;
} else {
V_27 = F_20 ( V_6 ,
V_31 ,
V_15 -> V_30 ) ;
}
return V_27 ;
}
static int F_21 ( struct V_5 * V_6 ,
struct V_32 * V_33 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
return F_22 ( V_6 -> V_34 -> V_35 -> V_28 , V_33 , V_10 -> V_36 ,
V_10 -> V_37 , V_10 -> V_23 ) ;
}
static int F_23 ( struct V_38 * V_34 ,
int V_39 )
{
struct V_5 * V_6 = V_34 -> V_40 [ V_39 ] . V_6 ;
struct V_41 * V_42 = & V_6 -> V_22 ;
T_2 V_43 = V_3 . V_44 ;
V_42 -> V_28 . type = V_45 ;
V_42 -> V_28 . V_28 = V_34 -> V_35 -> V_28 ;
V_42 -> V_13 = NULL ;
V_42 -> V_46 = F_24 ( V_34 -> V_35 -> V_28 , V_43 , & V_42 -> V_47 , V_48 ) ;
if ( ! V_42 -> V_46 )
return - V_49 ;
V_42 -> V_50 = V_43 ;
return 0 ;
}
static void F_25 ( struct V_38 * V_34 )
{
struct V_5 * V_6 ;
struct V_41 * V_42 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 2 ; V_39 ++ ) {
V_6 = V_34 -> V_40 [ V_39 ] . V_6 ;
if ( ! V_6 )
continue;
V_42 = & V_6 -> V_22 ;
if ( ! V_42 -> V_46 )
continue;
F_26 ( V_34 -> V_35 -> V_28 , V_42 -> V_50 , V_42 -> V_46 , V_42 -> V_47 ) ;
V_42 -> V_46 = NULL ;
}
}
static int F_27 ( struct V_11 * V_12 )
{
struct V_51 * V_35 = V_12 -> V_35 -> V_51 ;
struct V_38 * V_34 = V_12 -> V_34 ;
int V_27 ;
V_27 = F_28 ( V_35 -> V_28 , F_29 ( 32 ) ) ;
if ( V_27 )
return V_27 ;
if ( V_34 -> V_40 [ V_52 ] . V_6 ) {
V_27 = F_23 ( V_34 ,
V_52 ) ;
if ( V_27 )
goto V_53;
}
if ( V_34 -> V_40 [ V_54 ] . V_6 ) {
V_27 = F_23 ( V_34 ,
V_54 ) ;
if ( V_27 )
goto V_53;
}
V_53:
if ( V_27 )
F_25 ( V_34 ) ;
return V_27 ;
}
int F_30 ( struct V_55 * V_28 )
{
F_1 () ;
return F_31 ( V_28 , & V_56 ) ;
}
