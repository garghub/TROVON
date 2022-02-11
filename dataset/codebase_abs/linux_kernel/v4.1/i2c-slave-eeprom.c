static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
switch ( V_4 ) {
case V_8 :
if ( V_7 -> V_9 ) {
V_7 -> V_10 = * V_5 ;
V_7 -> V_9 = false ;
} else {
F_3 ( & V_7 -> V_11 ) ;
V_7 -> V_12 [ V_7 -> V_10 ++ ] = * V_5 ;
F_4 ( & V_7 -> V_11 ) ;
}
break;
case V_13 :
V_7 -> V_10 ++ ;
case V_14 :
F_3 ( & V_7 -> V_11 ) ;
* V_5 = V_7 -> V_12 [ V_7 -> V_10 ] ;
F_4 ( & V_7 -> V_11 ) ;
break;
case V_15 :
case V_16 :
V_7 -> V_9 = true ;
break;
default:
break;
}
return 0 ;
}
static T_2 F_5 ( struct V_17 * V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 , T_3 V_24 , T_4 V_25 )
{
struct V_6 * V_7 ;
unsigned long V_26 ;
if ( V_24 + V_25 > V_22 -> V_27 )
return - V_28 ;
V_7 = F_6 ( F_7 ( V_20 , struct V_29 , V_20 ) ) ;
F_8 ( & V_7 -> V_11 , V_26 ) ;
memcpy ( V_23 , & V_7 -> V_12 [ V_24 ] , V_25 ) ;
F_9 ( & V_7 -> V_11 , V_26 ) ;
return V_25 ;
}
static T_2 F_10 ( struct V_17 * V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 , T_3 V_24 , T_4 V_25 )
{
struct V_6 * V_7 ;
unsigned long V_26 ;
if ( V_24 + V_25 > V_22 -> V_27 )
return - V_28 ;
V_7 = F_6 ( F_7 ( V_20 , struct V_29 , V_20 ) ) ;
F_8 ( & V_7 -> V_11 , V_26 ) ;
memcpy ( & V_7 -> V_12 [ V_24 ] , V_23 , V_25 ) ;
F_9 ( & V_7 -> V_11 , V_26 ) ;
return V_25 ;
}
static int F_11 ( struct V_1 * V_2 , const struct V_30 * V_31 )
{
struct V_6 * V_7 ;
int V_32 ;
unsigned V_27 = V_31 -> V_33 ;
V_7 = F_12 ( & V_2 -> V_34 , sizeof( struct V_6 ) + V_27 , V_35 ) ;
if ( ! V_7 )
return - V_36 ;
V_7 -> V_9 = true ;
F_13 ( & V_7 -> V_11 ) ;
F_14 ( V_2 , V_7 ) ;
F_15 ( & V_7 -> V_37 ) ;
V_7 -> V_37 . V_22 . V_38 = L_1 ;
V_7 -> V_37 . V_22 . V_39 = V_40 | V_41 ;
V_7 -> V_37 . V_42 = F_5 ;
V_7 -> V_37 . V_43 = F_10 ;
V_7 -> V_37 . V_27 = V_27 ;
V_32 = F_16 ( & V_2 -> V_34 . V_20 , & V_7 -> V_37 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_17 ( V_2 , F_1 ) ;
if ( V_32 ) {
F_18 ( & V_2 -> V_34 . V_20 , & V_7 -> V_37 ) ;
return V_32 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_20 ( V_2 ) ;
F_18 ( & V_2 -> V_34 . V_20 , & V_7 -> V_37 ) ;
return 0 ;
}
