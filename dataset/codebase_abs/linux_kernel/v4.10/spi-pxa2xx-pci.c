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
switch ( F_7 ( V_8 -> V_16 ) ) {
case 0 :
V_12 -> V_23 = 3 ;
V_12 -> V_13 = 1 ;
break;
case 1 :
V_12 -> V_23 = 5 ;
V_12 -> V_13 = 4 ;
break;
case 2 :
V_12 -> V_23 = 6 ;
V_12 -> V_13 = 1 ;
break;
default:
return - V_24 ;
}
return 0 ;
}
static int F_8 ( struct V_10 * V_8 ,
const struct V_25 * V_26 )
{
struct V_27 V_28 ;
int V_29 ;
struct V_30 * V_31 ;
struct V_32 V_33 ;
struct V_34 * V_35 ;
struct V_11 * V_12 ;
char V_36 [ 40 ] ;
V_29 = F_9 ( V_8 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_10 ( V_8 , 1 << 0 , L_1 ) ;
if ( V_29 )
return V_29 ;
V_12 = & V_37 [ V_26 -> V_38 ] ;
if ( V_12 -> V_39 ) {
V_29 = V_12 -> V_39 ( V_8 , V_12 ) ;
if ( V_29 )
return V_29 ;
}
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_13 = ( V_12 -> V_13 > 0 ) ? V_12 -> V_13 : V_8 -> V_16 ;
V_33 . V_22 = V_12 -> V_22 ;
V_33 . V_17 = V_12 -> V_17 ;
V_33 . V_21 = V_12 -> V_21 ;
V_33 . V_40 = V_12 -> V_21 && V_12 -> V_17 ;
V_35 = & V_33 . V_35 ;
V_35 -> V_41 = F_11 ( V_8 , 0 ) ;
V_35 -> V_42 = F_12 ( V_8 ) [ 0 ] ;
V_35 -> V_43 = V_8 -> V_43 ;
V_35 -> V_23 = ( V_12 -> V_23 >= 0 ) ? V_12 -> V_23 : V_8 -> V_16 ;
V_35 -> type = V_12 -> type ;
snprintf ( V_36 , sizeof( V_36 ) , L_2 , V_35 -> V_23 ) ;
V_35 -> V_44 = F_13 ( & V_8 -> V_8 , V_36 , NULL , 0 ,
V_12 -> V_14 ) ;
if ( F_14 ( V_35 -> V_44 ) )
return F_15 ( V_35 -> V_44 ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_45 = V_8 -> V_8 . V_45 ;
V_28 . V_46 = & V_8 -> V_8 ;
V_28 . V_47 = L_3 ;
V_28 . V_48 = V_35 -> V_23 ;
V_28 . V_49 = & V_33 ;
V_28 . V_50 = sizeof( V_33 ) ;
V_31 = F_16 ( & V_28 ) ;
if ( F_14 ( V_31 ) ) {
F_17 ( V_35 -> V_44 ) ;
return F_15 ( V_31 ) ;
}
F_18 ( V_8 , V_31 ) ;
return 0 ;
}
static void F_19 ( struct V_10 * V_8 )
{
struct V_30 * V_31 = F_20 ( V_8 ) ;
struct V_32 * V_33 ;
V_33 = F_21 ( & V_31 -> V_8 ) ;
F_22 ( V_31 ) ;
F_17 ( V_33 -> V_35 . V_44 ) ;
}
