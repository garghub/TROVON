static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
unsigned int V_6 ;
T_1 V_7 ;
T_1 V_8 ;
T_2 V_9 ;
T_2 V_10 ;
T_1 * V_11 ;
V_7 = V_4 -> V_12 ;
V_9 = V_4 -> V_9 ;
V_10 = V_4 -> V_10 ;
switch ( V_4 -> V_12 ) {
case V_13 :
case V_14 :
case V_15 :
V_8 = ( V_16 | V_17 ) ;
break;
case V_18 :
case V_19 :
case V_20 :
V_8 = ( V_16 | V_21 ) ;
break;
default:
F_2 ( & V_2 -> V_22 -> V_23 , L_1 ,
V_24 , V_4 -> V_12 ) ;
V_5 = - V_25 ;
goto error;
}
V_11 = F_3 ( V_4 -> V_26 , V_27 ) ;
if ( ! V_11 ) {
V_5 = - V_28 ;
goto error;
}
if ( V_8 == ( V_16 | V_21 ) ) {
memcpy ( V_11 , V_4 -> V_29 , V_4 -> V_26 ) ;
V_6 = F_4 ( V_2 -> V_22 , 0 ) ;
} else {
V_6 = F_5 ( V_2 -> V_22 , 0 ) ;
}
F_6 ( 1 ) ;
V_5 = F_7 ( V_2 -> V_22 , V_6 , V_7 , V_8 , V_9 , V_10 ,
V_11 , V_4 -> V_26 , V_30 ) ;
F_8 ( V_2 -> V_22 , V_7 , V_8 , V_9 , V_10 ,
V_11 , V_4 -> V_26 ) ;
if ( V_5 < 0 )
F_2 ( & V_2 -> V_22 -> V_23 , L_2 ,
V_24 , V_5 ) ;
else
V_5 = 0 ;
if ( ! V_5 && V_8 == ( V_16 | V_17 ) )
memcpy ( V_4 -> V_29 , V_11 , V_4 -> V_26 ) ;
F_9 ( V_11 ) ;
error:
return V_5 ;
}
static int F_10 ( struct V_31 * V_32 ,
struct V_33 V_34 [] , int V_35 )
{
struct V_1 * V_2 = F_11 ( V_32 ) ;
int V_5 = 0 , V_36 = 0 ;
struct V_3 V_4 ;
if ( V_35 > 2 )
return - V_37 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
if ( F_12 ( & V_2 -> V_38 ) < 0 )
return - V_39 ;
while ( V_36 < V_35 ) {
if ( V_35 > V_36 + 1 && ( V_34 [ V_36 + 1 ] . V_40 & V_41 ) ) {
if ( V_34 [ V_36 ] . V_42 ==
V_43 . V_44 ) {
V_4 . V_12 = V_14 ;
V_4 . V_9 = V_34 [ V_36 ] . V_42 >> 1 ;
V_4 . V_10 = V_34 [ V_36 ] . V_11 [ 0 ] ;
V_4 . V_26 = V_34 [ V_36 + 1 ] . V_45 ;
V_4 . V_29 = & V_34 [ V_36 + 1 ] . V_11 [ 0 ] ;
V_5 = F_1 ( V_2 , & V_4 ) ;
} else {
F_2 ( & V_2 -> V_22 -> V_23 , L_3 \
L_4 ,
V_24 ) ;
V_5 = - V_37 ;
}
V_36 += 2 ;
} else {
if ( V_34 [ V_36 ] . V_42 ==
V_43 . V_44 ) {
V_4 . V_12 = V_19 ;
V_4 . V_9 = V_34 [ V_36 ] . V_42 >> 1 ;
V_4 . V_10 = V_34 [ V_36 ] . V_11 [ 0 ] ;
V_4 . V_26 = V_34 [ V_36 ] . V_45 - 1 ;
V_4 . V_29 = & V_34 [ V_36 ] . V_11 [ 1 ] ;
V_5 = F_1 ( V_2 , & V_4 ) ;
} else {
V_4 . V_12 = V_18 ;
V_4 . V_9 = 0x2000 + ( V_34 [ V_36 ] . V_42 >> 1 ) ;
V_4 . V_10 = 0x0000 ;
V_4 . V_26 = V_34 [ V_36 ] . V_45 ;
V_4 . V_29 = & V_34 [ V_36 ] . V_11 [ 0 ] ;
V_5 = F_1 ( V_2 , & V_4 ) ;
}
V_36 += 1 ;
}
if ( V_5 )
break;
}
F_13 ( & V_2 -> V_38 ) ;
return V_5 ? V_5 : V_36 ;
}
static T_3 F_14 ( struct V_31 * V_46 )
{
return V_47 ;
}
static int F_15 ( struct V_48 * V_32 )
{
struct V_1 * V_2 = F_16 ( V_32 ) ;
F_17 ( & V_2 -> V_22 -> V_23 , L_5 , V_49 ) ;
V_32 -> V_50 [ 0 ] = F_18 ( V_51 , & V_43 ,
& V_2 -> V_52 ) ;
if ( V_32 -> V_50 [ 0 ] == NULL )
return - V_53 ;
return 0 ;
}
static int F_19 ( struct V_48 * V_32 )
{
struct V_1 * V_2 = F_16 ( V_32 ) ;
int V_5 ;
F_17 ( & V_2 -> V_22 -> V_23 , L_5 , V_49 ) ;
V_5 = F_18 ( V_54 , V_32 -> V_50 [ 0 ] , & V_2 -> V_52 ,
& V_55 ) == NULL ? - V_53 : 0 ;
return V_5 ;
}
static int F_20 ( struct V_1 * V_2 , int V_56 )
{
int V_5 ;
F_17 ( & V_2 -> V_22 -> V_23 , L_6 , V_49 , V_56 ) ;
V_5 = F_21 ( V_2 -> V_22 , 1 , V_56 ) ;
if ( V_5 )
F_2 ( & V_2 -> V_22 -> V_23 , L_7 ,
V_24 , V_5 ) ;
return V_5 ;
}
