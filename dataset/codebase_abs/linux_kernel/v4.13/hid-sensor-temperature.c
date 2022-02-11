static void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
V_2 [ V_3 ] . V_5 . V_6 = 's' ;
V_2 [ V_3 ] . V_5 . V_7 = V_4 * 8 ;
V_2 [ V_3 ] . V_5 . V_8 = sizeof( V_9 ) * 8 ;
}
static int F_2 ( struct V_10 * V_11 ,
struct V_1 const * V_12 ,
int * V_13 , int * V_14 , long V_15 )
{
struct V_16 * V_17 = F_3 ( V_11 ) ;
switch ( V_15 ) {
case V_18 :
if ( V_12 -> type != V_19 )
return - V_20 ;
F_4 (
& V_17 -> V_21 , true ) ;
* V_13 = F_5 (
V_17 -> V_21 . V_22 ,
V_23 ,
V_24 ,
V_17 -> V_25 . V_26 ,
V_27 ) ;
F_4 (
& V_17 -> V_21 ,
false ) ;
return V_28 ;
case V_29 :
* V_13 = V_17 -> V_30 ;
* V_14 = V_17 -> V_31 ;
return V_17 -> V_32 ;
case V_33 :
* V_13 = V_17 -> V_34 ;
return V_28 ;
case V_35 :
return F_6 (
& V_17 -> V_21 , V_13 , V_14 ) ;
case V_36 :
return F_7 (
& V_17 -> V_21 , V_13 , V_14 ) ;
default:
return - V_20 ;
}
}
static int F_8 ( struct V_10 * V_11 ,
struct V_1 const * V_12 ,
int V_13 , int V_14 , long V_15 )
{
struct V_16 * V_17 = F_3 ( V_11 ) ;
switch ( V_15 ) {
case V_35 :
return F_9 (
& V_17 -> V_21 , V_13 , V_14 ) ;
case V_36 :
return F_10 (
& V_17 -> V_21 , V_13 , V_14 ) ;
default:
return - V_20 ;
}
}
static int F_11 ( struct V_37 * V_22 ,
unsigned int V_38 , void * V_39 )
{
struct V_10 * V_11 = F_12 ( V_39 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
if ( F_13 ( & V_17 -> V_21 . V_40 ) )
F_14 ( V_11 ,
& V_17 -> V_41 ,
F_15 ( V_11 ) ) ;
return 0 ;
}
static int F_16 ( struct V_37 * V_22 ,
unsigned int V_38 , T_1 V_42 ,
char * V_43 , void * V_39 )
{
struct V_10 * V_11 = F_12 ( V_39 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
switch ( V_38 ) {
case V_24 :
V_17 -> V_41 = * ( V_9 * ) V_43 ;
return 0 ;
default:
return - V_20 ;
}
}
static int F_17 ( struct V_44 * V_39 ,
struct V_37 * V_22 ,
struct V_1 * V_2 ,
unsigned int V_38 ,
struct V_16 * V_45 )
{
int V_46 ;
V_46 = F_18 ( V_22 , V_47 ,
V_38 ,
V_24 ,
& V_45 -> V_25 ) ;
if ( V_46 < 0 )
return V_46 ;
F_1 ( V_2 , 0 ,
V_45 -> V_25 . V_4 ) ;
V_45 -> V_32 = F_19 (
V_23 ,
& V_45 -> V_25 ,
& V_45 -> V_30 , & V_45 -> V_31 ) ;
if ( V_45 -> V_21 . V_48 . V_49 < 0 )
F_18 ( V_22 ,
V_50 , V_38 ,
V_51 |
V_24 ,
& V_45 -> V_21 . V_48 ) ;
return V_46 ;
}
static int F_20 ( struct V_44 * V_39 )
{
static const char * V_52 = L_1 ;
struct V_10 * V_11 ;
struct V_16 * V_17 ;
struct V_1 * V_53 ;
struct V_37 * V_22 = F_21 ( & V_39 -> V_54 ) ;
int V_46 ;
V_11 = F_22 ( & V_39 -> V_54 , sizeof( * V_17 ) ) ;
if ( ! V_11 )
return - V_55 ;
V_17 = F_3 ( V_11 ) ;
V_17 -> V_21 . V_22 = V_22 ;
V_17 -> V_21 . V_39 = V_39 ;
V_46 = F_23 ( V_22 ,
V_23 ,
& V_17 -> V_21 ) ;
if ( V_46 )
return V_46 ;
V_53 = F_24 ( & V_11 -> V_54 , V_56 ,
sizeof( V_56 ) , V_57 ) ;
if ( ! V_53 )
return - V_55 ;
V_46 = F_17 ( V_39 , V_22 , V_53 ,
V_23 , V_17 ) ;
if ( V_46 )
return V_46 ;
V_11 -> V_2 = V_53 ;
V_11 -> V_58 = F_25 ( V_56 ) ;
V_11 -> V_54 . V_59 = & V_39 -> V_54 ;
V_11 -> V_60 = & V_61 ;
V_11 -> V_52 = V_52 ;
V_11 -> V_62 = V_63 ;
V_46 = F_26 ( & V_39 -> V_54 , V_11 ,
& V_64 , NULL , NULL ) ;
if ( V_46 )
return V_46 ;
F_27 ( & V_17 -> V_21 . V_40 , 0 ) ;
V_46 = F_28 ( V_11 , V_52 ,
& V_17 -> V_21 ) ;
if ( V_46 )
return V_46 ;
F_29 ( V_39 , V_11 ) ;
V_65 . V_39 = V_39 ;
V_46 = F_30 ( V_22 , V_23 ,
& V_65 ) ;
if ( V_46 )
goto V_66;
V_46 = F_31 ( V_11 -> V_54 . V_59 , V_11 ) ;
if ( V_46 )
goto V_67;
return V_46 ;
V_67:
F_32 ( V_22 , V_23 ) ;
V_66:
F_33 ( & V_17 -> V_21 ) ;
return V_46 ;
}
static int F_34 ( struct V_44 * V_39 )
{
struct V_37 * V_22 = F_21 ( & V_39 -> V_54 ) ;
struct V_10 * V_11 = F_12 ( V_39 ) ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
F_32 ( V_22 , V_23 ) ;
F_33 ( & V_17 -> V_21 ) ;
return 0 ;
}
