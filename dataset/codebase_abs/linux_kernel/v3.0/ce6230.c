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
F_2 ( L_1 , V_4 -> V_12 ) ;
V_5 = - V_22 ;
goto error;
}
V_11 = F_3 ( V_4 -> V_23 , V_24 ) ;
if ( ! V_11 ) {
V_5 = - V_25 ;
goto error;
}
if ( V_8 == ( V_16 | V_21 ) ) {
memcpy ( V_11 , V_4 -> V_26 , V_4 -> V_23 ) ;
V_6 = F_4 ( V_2 , 0 ) ;
} else {
V_6 = F_5 ( V_2 , 0 ) ;
}
F_6 ( 1 ) ;
V_5 = F_7 ( V_2 , V_6 , V_7 , V_8 , V_9 , V_10 ,
V_11 , V_4 -> V_23 , V_27 ) ;
F_8 ( V_7 , V_8 , V_9 , V_10 , V_11 ,
V_4 -> V_23 , V_28 ) ;
if ( V_5 < 0 )
F_9 ( L_2 , V_29 , V_5 ) ;
else
V_5 = 0 ;
if ( ! V_5 && V_8 == ( V_16 | V_17 ) )
memcpy ( V_4 -> V_26 , V_11 , V_4 -> V_23 ) ;
F_10 ( V_11 ) ;
error:
return V_5 ;
}
static int F_11 ( struct V_30 * V_31 , struct V_3 * V_4 )
{
return F_1 ( V_31 -> V_2 , V_4 ) ;
}
static int F_12 ( struct V_32 * V_33 , struct V_34 V_35 [] ,
int V_36 )
{
struct V_30 * V_31 = F_13 ( V_33 ) ;
int V_37 = 0 ;
struct V_3 V_4 ;
int V_5 = 0 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
if ( V_36 > 2 )
return - V_38 ;
if ( F_14 ( & V_31 -> V_39 ) < 0 )
return - V_40 ;
while ( V_37 < V_36 ) {
if ( V_36 > V_37 + 1 && ( V_35 [ V_37 + 1 ] . V_41 & V_42 ) ) {
if ( V_35 [ V_37 ] . V_43 ==
V_44 . V_45 ) {
V_4 . V_12 = V_14 ;
V_4 . V_9 = V_35 [ V_37 ] . V_43 >> 1 ;
V_4 . V_10 = V_35 [ V_37 ] . V_11 [ 0 ] ;
V_4 . V_23 = V_35 [ V_37 + 1 ] . V_46 ;
V_4 . V_26 = & V_35 [ V_37 + 1 ] . V_11 [ 0 ] ;
V_5 = F_11 ( V_31 , & V_4 ) ;
} else {
F_2 ( L_3 ) ;
V_5 = - V_22 ;
}
V_37 += 2 ;
} else {
if ( V_35 [ V_37 ] . V_43 ==
V_44 . V_45 ) {
V_4 . V_12 = V_19 ;
V_4 . V_9 = V_35 [ V_37 ] . V_43 >> 1 ;
V_4 . V_10 = V_35 [ V_37 ] . V_11 [ 0 ] ;
V_4 . V_23 = V_35 [ V_37 ] . V_46 - 1 ;
V_4 . V_26 = & V_35 [ V_37 ] . V_11 [ 1 ] ;
V_5 = F_11 ( V_31 , & V_4 ) ;
} else {
V_4 . V_12 = V_18 ;
V_4 . V_9 = 0x2000 + ( V_35 [ V_37 ] . V_43 >> 1 ) ;
V_4 . V_10 = 0x0000 ;
V_4 . V_23 = V_35 [ V_37 ] . V_46 ;
V_4 . V_26 = & V_35 [ V_37 ] . V_11 [ 0 ] ;
V_5 = F_11 ( V_31 , & V_4 ) ;
}
V_37 += 1 ;
}
if ( V_5 )
break;
}
F_15 ( & V_31 -> V_39 ) ;
return V_5 ? V_5 : V_37 ;
}
static T_3 F_16 ( struct V_32 * V_47 )
{
return V_48 ;
}
static int F_17 ( struct V_49 * V_33 )
{
F_9 ( L_4 , V_29 ) ;
V_33 -> V_50 = F_18 ( V_51 , & V_44 ,
& V_33 -> V_52 -> V_53 ) ;
if ( V_33 -> V_50 == NULL )
return - V_54 ;
return 0 ;
}
static int F_19 ( struct V_49 * V_33 )
{
int V_5 ;
F_9 ( L_4 , V_29 ) ;
V_5 = F_18 ( V_55 , V_33 -> V_50 , & V_33 -> V_52 -> V_53 ,
& V_56 ) == NULL ? - V_54 : 0 ;
return V_5 ;
}
static int F_20 ( struct V_30 * V_31 , int V_57 )
{
int V_5 ;
F_9 ( L_5 , V_29 , V_57 ) ;
V_5 = F_21 ( V_31 -> V_2 , 1 , V_57 ) ;
if ( V_5 )
F_2 ( L_6 , V_5 ) ;
return V_5 ;
}
static int F_22 ( struct V_58 * V_59 ,
const struct V_60 * V_61 )
{
int V_5 = 0 ;
struct V_30 * V_31 = NULL ;
F_9 ( L_7 , V_29 ,
V_59 -> V_62 -> V_63 . V_64 ) ;
if ( V_59 -> V_62 -> V_63 . V_64 == 1 ) {
V_5 = F_23 ( V_59 , & V_65 , V_66 ,
& V_31 , V_67 ) ;
if ( V_5 )
F_2 ( L_8 , V_5 ) ;
}
return V_5 ;
}
static int T_4 F_24 ( void )
{
int V_5 ;
F_9 ( L_4 , V_29 ) ;
V_5 = F_25 ( & V_68 ) ;
if ( V_5 )
F_2 ( L_9 , V_5 ) ;
return V_5 ;
}
static void T_5 F_26 ( void )
{
F_9 ( L_4 , V_29 ) ;
F_27 ( & V_68 ) ;
}
