static int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == 1 &&
V_2 -> V_4 == 0 &&
V_2 -> V_5 == 1 &&
V_2 -> V_6 == 1 ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_7 = 0 ;
if ( V_2 -> V_6 == 1 )
V_7 |= V_8 ;
if ( V_2 -> V_3 == 1 &&
V_2 -> V_4 == 0 &&
V_2 -> V_5 == 1 )
V_7 |= V_9 ;
return V_7 ;
}
static int F_3 ( struct V_10 * V_11 )
{
return F_4 ( V_11 ) ? - V_12 : 0 ;
}
static int F_5 ( void * V_13 )
{
struct V_14 * V_15 = V_13 ;
V_15 -> V_16 = 1 ;
V_15 -> V_17 = V_18 ;
V_15 -> V_19 = 1 ;
V_15 -> V_20 = V_21 ;
return 0 ;
}
static int F_6 ( struct V_10 * V_11 , void * V_13 )
{
struct V_1 V_2 ;
struct V_22 * V_23 = V_13 ;
if ( F_7 ( V_11 , & V_2 ) )
return - V_12 ;
if ( V_23 -> V_24 != 0 )
return - V_12 ;
V_23 -> type = V_18 ;
V_23 -> V_7 = F_2 ( & V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_10 * V_11 , void * V_13 )
{
struct V_25 * V_26 = V_13 ;
return F_9 ( V_11 , V_26 -> V_27 , & V_26 -> V_28 ) ? - V_12 : 0 ;
}
static int F_10 ( struct V_10 * V_11 , void * V_13 )
{
struct V_25 * V_26 = V_13 ;
return F_11 ( V_11 , V_26 -> V_27 , & V_26 -> V_28 ) ? - V_12 : 0 ;
}
static int F_12 ( struct V_10 * V_11 , void * V_13 )
{
struct V_25 * V_26 = V_13 ;
return F_13 ( V_11 , V_26 -> V_27 , & V_26 -> V_28 ) ? - V_12 : 0 ;
}
static int F_14 ( struct V_10 * V_11 , void * V_13 )
{
struct V_1 V_2 ;
int V_29 ;
switch ( V_11 -> V_30 ) {
case V_31 :
V_29 = F_8 ( V_11 , V_13 ) ;
break;
case V_32 :
V_29 = F_10 ( V_11 , V_13 ) ;
break;
default:
if ( F_7 ( V_11 , & V_2 ) )
V_29 = - V_12 ;
else if ( V_2 . V_33 == 1 )
V_29 = F_12 ( V_11 , V_13 ) ;
else {
F_15 ( V_11 -> V_34 , L_1 ,
V_11 -> V_30 ) ;
V_29 = - V_12 ;
}
}
V_11 -> V_30 = 0 ;
return V_29 ;
}
static int F_16 ( struct V_10 * V_11 , void * V_13 )
{
struct V_25 * V_27 = V_13 ;
int V_35 ;
int V_36 ;
int V_37 ;
V_35 = 4 ;
if ( V_27 -> V_27 [ 3 ] & 0x80 ) {
V_36 = 0 ;
for ( V_37 = 0 ; V_37 < ( V_27 -> V_27 [ 3 ] & 0x7f ) ; V_37 ++ )
V_36 = ( V_36 << 8 ) + V_27 -> V_27 [ V_35 ++ ] ;
} else {
V_36 = V_27 -> V_27 [ 3 ] ;
}
return F_17 ( V_11 , & V_27 -> V_27 [ V_35 ] , V_36 ) ? - V_12 : 0 ;
}
static int F_18 ( struct V_10 * V_11 , void * V_13 )
{
struct V_25 * V_27 = V_13 ;
int V_29 ;
V_11 -> V_30 =
( V_27 -> V_27 [ 0 ] << 16 ) + ( V_27 -> V_27 [ 1 ] << 8 ) + V_27 -> V_27 [ 2 ] ;
switch ( V_11 -> V_30 ) {
case V_38 :
V_29 = F_16 ( V_11 , V_13 ) ;
break;
case V_31 :
V_29 = 0 ;
break;
case V_32 :
V_29 = 0 ;
break;
case V_39 :
V_29 = F_19 ( V_11 ) ;
break;
default:
F_20 ( V_11 -> V_34 , L_1 ,
V_11 -> V_30 ) ;
V_29 = - V_12 ;
}
return V_29 ;
}
static int F_21 ( struct V_40 * V_40 , unsigned int V_41 , void * V_13 )
{
struct V_42 * V_43 = V_40 -> V_44 ;
struct V_10 * V_11 = V_43 -> V_45 ;
struct V_1 V_2 ;
int V_29 ;
switch ( V_41 ) {
case V_46 :
V_29 = F_3 ( V_11 ) ;
break;
case V_47 :
V_29 = F_5 ( V_13 ) ;
break;
case V_48 :
V_29 = F_6 ( V_11 , V_13 ) ;
break;
case V_49 :
V_29 = F_14 ( V_11 , V_13 ) ;
break;
case V_50 :
V_29 = F_18 ( V_11 , V_13 ) ;
break;
default:
F_15 ( V_11 -> V_34 , L_2 , V_41 ) ;
V_29 = - V_51 ;
}
F_7 ( V_11 , & V_2 ) ;
return V_29 ;
}
static unsigned int F_22 ( struct V_40 * V_40 , T_1 * V_52 )
{
return V_53 ;
}
int F_23 ( struct V_10 * V_11 )
{
struct V_1 V_2 ;
int V_29 ;
if ( F_7 ( V_11 , & V_2 ) )
return - V_54 ;
if ( ! F_1 ( & V_2 ) )
return - V_12 ;
V_29 = F_24 ( & V_11 -> V_55 , & V_11 -> V_56 ,
& V_57 , V_11 , V_58 ) ;
if ( V_2 . V_59 == 0 )
F_20 ( V_11 -> V_34 , L_3 ) ;
if ( V_2 . V_60 == 1 )
F_25 ( V_11 , & V_11 -> V_61 ) ;
return V_29 ;
}
void F_26 ( struct V_10 * V_11 )
{
if ( V_11 -> V_56 )
F_27 ( V_11 -> V_56 ) ;
}
