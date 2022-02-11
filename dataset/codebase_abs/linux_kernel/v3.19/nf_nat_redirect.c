unsigned int
F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_5 )
{
struct V_6 * V_7 ;
enum V_8 V_9 ;
T_1 V_10 ;
struct V_11 V_12 ;
F_2 ( V_5 == V_13 ||
V_5 == V_14 ) ;
V_7 = F_3 ( V_2 , & V_9 ) ;
F_2 ( V_7 && ( V_9 == V_15 || V_9 == V_16 ) ) ;
if ( V_5 == V_14 ) {
V_10 = F_4 ( 0x7F000001 ) ;
} else {
struct V_17 * V_18 ;
struct V_19 * V_20 ;
V_10 = 0 ;
F_5 () ;
V_18 = F_6 ( V_2 -> V_21 ) ;
if ( V_18 != NULL ) {
V_20 = V_18 -> V_22 ;
V_10 = V_20 -> V_23 ;
}
F_7 () ;
if ( ! V_10 )
return V_24 ;
}
memset ( & V_12 . V_25 , 0 , sizeof( V_12 . V_25 ) ) ;
memset ( & V_12 . V_26 , 0 , sizeof( V_12 . V_26 ) ) ;
V_12 . V_27 = V_4 -> V_28 [ 0 ] . V_27 | V_29 ;
V_12 . V_25 . V_30 = V_10 ;
V_12 . V_26 . V_30 = V_10 ;
V_12 . V_31 = V_4 -> V_28 [ 0 ] . V_32 ;
V_12 . V_33 = V_4 -> V_28 [ 0 ] . V_34 ;
return F_8 ( V_7 , & V_12 , V_35 ) ;
}
unsigned int
F_9 ( struct V_1 * V_2 , const struct V_11 * V_28 ,
unsigned int V_5 )
{
struct V_11 V_12 ;
struct V_36 V_10 ;
enum V_8 V_9 ;
struct V_6 * V_7 ;
V_7 = F_3 ( V_2 , & V_9 ) ;
if ( V_5 == V_14 ) {
V_10 = V_37 ;
} else {
struct V_38 * V_39 ;
struct V_40 * V_20 ;
bool V_41 = false ;
F_5 () ;
V_39 = F_10 ( V_2 -> V_21 ) ;
if ( V_39 != NULL ) {
F_11 (ifa, &idev->addr_list, if_list) {
V_10 = V_20 -> V_41 ;
V_41 = true ;
break;
}
}
F_7 () ;
if ( ! V_41 )
return V_24 ;
}
V_12 . V_27 = V_28 -> V_27 | V_29 ;
V_12 . V_25 . V_42 = V_10 ;
V_12 . V_26 . V_42 = V_10 ;
V_12 . V_31 = V_28 -> V_31 ;
V_12 . V_33 = V_28 -> V_33 ;
return F_8 ( V_7 , & V_12 , V_35 ) ;
}
