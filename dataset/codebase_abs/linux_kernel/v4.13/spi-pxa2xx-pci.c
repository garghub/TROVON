static bool F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( V_5 -> V_6 != V_2 -> V_7 -> V_8 )
return false ;
V_2 -> V_9 = V_5 ;
return true ;
}
static int F_2 ( struct V_10 * V_8 , struct V_11 * V_12 )
{
struct V_10 * V_6 ;
V_12 -> V_13 = 1 ;
V_12 -> V_14 = 50000000 ;
V_6 = F_3 ( V_8 -> V_15 , F_4 ( F_5 ( V_8 -> V_16 ) , 0 ) ) ;
if ( V_12 -> V_17 ) {
struct V_4 * V_18 = V_12 -> V_17 ;
V_18 -> V_6 = & V_6 -> V_8 ;
V_18 -> V_19 = 0 ;
V_18 -> V_20 = 1 ;
}
if ( V_12 -> V_21 ) {
struct V_4 * V_18 = V_12 -> V_21 ;
V_18 -> V_6 = & V_6 -> V_8 ;
V_18 -> V_19 = 0 ;
V_18 -> V_20 = 1 ;
}
V_12 -> V_22 = F_1 ;
return 0 ;
}
static int F_6 ( struct V_10 * V_8 , struct V_11 * V_12 )
{
struct V_10 * V_6 = F_3 ( V_8 -> V_15 , F_4 ( 21 , 0 ) ) ;
struct V_4 * V_23 , * V_24 ;
switch ( F_7 ( V_8 -> V_16 ) ) {
case 0 :
V_12 -> V_25 = 3 ;
V_12 -> V_13 = 1 ;
V_12 -> V_17 = & V_26 ;
V_12 -> V_21 = & V_27 ;
break;
case 1 :
V_12 -> V_25 = 5 ;
V_12 -> V_13 = 4 ;
V_12 -> V_17 = & V_28 ;
V_12 -> V_21 = & V_29 ;
break;
case 2 :
V_12 -> V_25 = 6 ;
V_12 -> V_13 = 1 ;
V_12 -> V_17 = & V_30 ;
V_12 -> V_21 = & V_31 ;
break;
default:
return - V_32 ;
}
V_23 = V_12 -> V_17 ;
V_23 -> V_6 = & V_6 -> V_8 ;
V_24 = V_12 -> V_21 ;
V_24 -> V_6 = & V_6 -> V_8 ;
V_12 -> V_22 = F_1 ;
return 0 ;
}
static int F_8 ( struct V_10 * V_8 ,
const struct V_33 * V_34 )
{
struct V_35 V_36 ;
int V_37 ;
struct V_38 * V_39 ;
struct V_40 V_41 ;
struct V_42 * V_43 ;
struct V_11 * V_12 ;
char V_44 [ 40 ] ;
V_37 = F_9 ( V_8 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_10 ( V_8 , 1 << 0 , L_1 ) ;
if ( V_37 )
return V_37 ;
V_12 = & V_45 [ V_34 -> V_46 ] ;
if ( V_12 -> V_47 ) {
V_37 = V_12 -> V_47 ( V_8 , V_12 ) ;
if ( V_37 )
return V_37 ;
}
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_13 = ( V_12 -> V_13 > 0 ) ? V_12 -> V_13 : V_8 -> V_16 ;
V_41 . V_22 = V_12 -> V_22 ;
V_41 . V_17 = V_12 -> V_17 ;
V_41 . V_21 = V_12 -> V_21 ;
V_41 . V_48 = V_12 -> V_21 && V_12 -> V_17 ;
V_43 = & V_41 . V_43 ;
V_43 -> V_49 = F_11 ( V_8 , 0 ) ;
V_43 -> V_50 = F_12 ( V_8 ) [ 0 ] ;
V_43 -> V_25 = ( V_12 -> V_25 >= 0 ) ? V_12 -> V_25 : V_8 -> V_16 ;
V_43 -> type = V_12 -> type ;
F_13 ( V_8 ) ;
V_37 = F_14 ( V_8 , 1 , 1 , V_51 ) ;
if ( V_37 < 0 )
return V_37 ;
V_43 -> V_52 = F_15 ( V_8 , 0 ) ;
snprintf ( V_44 , sizeof( V_44 ) , L_2 , V_43 -> V_25 ) ;
V_43 -> V_53 = F_16 ( & V_8 -> V_8 , V_44 , NULL , 0 ,
V_12 -> V_14 ) ;
if ( F_17 ( V_43 -> V_53 ) )
return F_18 ( V_43 -> V_53 ) ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_54 = V_8 -> V_8 . V_54 ;
V_36 . V_55 = & V_8 -> V_8 ;
V_36 . V_56 = L_3 ;
V_36 . V_57 = V_43 -> V_25 ;
V_36 . V_58 = & V_41 ;
V_36 . V_59 = sizeof( V_41 ) ;
V_39 = F_19 ( & V_36 ) ;
if ( F_17 ( V_39 ) ) {
F_20 ( V_43 -> V_53 ) ;
return F_18 ( V_39 ) ;
}
F_21 ( V_8 , V_39 ) ;
return 0 ;
}
static void F_22 ( struct V_10 * V_8 )
{
struct V_38 * V_39 = F_23 ( V_8 ) ;
struct V_40 * V_41 ;
V_41 = F_24 ( & V_39 -> V_8 ) ;
F_25 ( V_39 ) ;
F_20 ( V_41 -> V_43 . V_53 ) ;
}
