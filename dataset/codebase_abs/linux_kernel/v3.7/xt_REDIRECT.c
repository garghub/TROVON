static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_5 V_8 ;
struct V_9 V_10 ;
enum V_11 V_12 ;
struct V_13 * V_14 ;
V_14 = F_2 ( V_2 , & V_12 ) ;
if ( V_4 -> V_15 == V_16 )
V_10 = V_17 ;
else {
struct V_18 * V_19 ;
struct V_20 * V_21 ;
bool V_22 = false ;
F_3 () ;
V_19 = F_4 ( V_2 -> V_23 ) ;
if ( V_19 != NULL ) {
F_5 (ifa, &idev->addr_list, if_list) {
V_10 = V_21 -> V_22 ;
V_22 = true ;
break;
}
}
F_6 () ;
if ( ! V_22 )
return V_24 ;
}
V_8 . V_25 = V_6 -> V_25 | V_26 ;
V_8 . V_27 . V_28 = V_10 ;
V_8 . V_29 . V_28 = V_10 ;
V_8 . V_30 = V_6 -> V_30 ;
V_8 . V_31 = V_6 -> V_31 ;
return F_7 ( V_14 , & V_8 , V_32 ) ;
}
static int F_8 ( const struct V_33 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_25 & V_26 )
return - V_34 ;
return 0 ;
}
static int F_9 ( const struct V_33 * V_4 )
{
const struct V_35 * V_36 = V_4 -> V_7 ;
if ( V_36 -> V_6 [ 0 ] . V_25 & V_26 ) {
F_10 ( L_1 ) ;
return - V_34 ;
}
if ( V_36 -> V_37 != 1 ) {
F_10 ( L_2 , V_36 -> V_37 ) ;
return - V_34 ;
}
return 0 ;
}
static unsigned int
F_11 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_13 * V_14 ;
enum V_11 V_12 ;
T_1 V_10 ;
const struct V_35 * V_36 = V_4 -> V_7 ;
struct V_5 V_8 ;
F_12 ( V_4 -> V_15 == V_38 ||
V_4 -> V_15 == V_16 ) ;
V_14 = F_2 ( V_2 , & V_12 ) ;
F_12 ( V_14 && ( V_12 == V_39 || V_12 == V_40 ) ) ;
if ( V_4 -> V_15 == V_16 )
V_10 = F_13 ( 0x7F000001 ) ;
else {
struct V_41 * V_42 ;
struct V_43 * V_21 ;
V_10 = 0 ;
F_3 () ;
V_42 = F_14 ( V_2 -> V_23 ) ;
if ( V_42 && ( V_21 = V_42 -> V_44 ) )
V_10 = V_21 -> V_45 ;
F_6 () ;
if ( ! V_10 )
return V_24 ;
}
memset ( & V_8 . V_27 , 0 , sizeof( V_8 . V_27 ) ) ;
memset ( & V_8 . V_29 , 0 , sizeof( V_8 . V_29 ) ) ;
V_8 . V_25 = V_36 -> V_6 [ 0 ] . V_25 | V_26 ;
V_8 . V_27 . V_46 = V_10 ;
V_8 . V_29 . V_46 = V_10 ;
V_8 . V_30 = V_36 -> V_6 [ 0 ] . V_47 ;
V_8 . V_31 = V_36 -> V_6 [ 0 ] . V_48 ;
return F_7 ( V_14 , & V_8 , V_32 ) ;
}
static int T_2 F_15 ( void )
{
return F_16 ( V_49 ,
F_17 ( V_49 ) ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( V_49 , F_17 ( V_49 ) ) ;
}
