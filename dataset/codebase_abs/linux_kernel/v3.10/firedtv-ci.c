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
static int F_3 ( void * V_10 )
{
struct V_11 * V_12 = V_10 ;
V_12 -> V_13 = 1 ;
V_12 -> V_14 = V_15 ;
V_12 -> V_16 = 1 ;
V_12 -> V_17 = V_18 ;
return 0 ;
}
static int F_4 ( struct V_19 * V_20 , void * V_10 )
{
struct V_1 V_2 ;
struct V_21 * V_22 = V_10 ;
int V_23 ;
V_23 = F_5 ( V_20 , & V_2 ) ;
if ( V_23 )
return V_23 ;
if ( V_22 -> V_24 != 0 )
return - V_25 ;
V_22 -> type = V_15 ;
V_22 -> V_7 = F_2 ( & V_2 ) ;
return 0 ;
}
static int F_6 ( struct V_19 * V_20 , void * V_10 )
{
struct V_26 * V_27 = V_10 ;
return F_7 ( V_20 , V_27 -> V_28 , & V_27 -> V_29 ) ;
}
static int F_8 ( struct V_19 * V_20 , void * V_10 )
{
struct V_26 * V_27 = V_10 ;
return F_9 ( V_20 , V_27 -> V_28 , & V_27 -> V_29 ) ;
}
static int F_10 ( struct V_19 * V_20 , void * V_10 )
{
struct V_26 * V_27 = V_10 ;
return F_11 ( V_20 , V_27 -> V_28 , & V_27 -> V_29 ) ;
}
static int F_12 ( struct V_19 * V_20 , void * V_10 )
{
struct V_1 V_2 ;
int V_23 ;
switch ( V_20 -> V_30 ) {
case V_31 :
V_23 = F_6 ( V_20 , V_10 ) ;
break;
case V_32 :
V_23 = F_8 ( V_20 , V_10 ) ;
break;
default:
V_23 = F_5 ( V_20 , & V_2 ) ;
if ( V_23 )
break;
if ( V_2 . V_33 == 1 )
V_23 = F_10 ( V_20 , V_10 ) ;
else {
F_13 ( V_20 -> V_34 , L_1 ,
V_20 -> V_30 ) ;
V_23 = - V_25 ;
}
}
V_20 -> V_30 = 0 ;
return V_23 ;
}
static int F_14 ( struct V_19 * V_20 , void * V_10 )
{
struct V_26 * V_28 = V_10 ;
int V_35 ;
int V_36 ;
int V_37 ;
V_35 = 4 ;
if ( V_28 -> V_28 [ 3 ] & 0x80 ) {
V_36 = 0 ;
for ( V_37 = 0 ; V_37 < ( V_28 -> V_28 [ 3 ] & 0x7f ) ; V_37 ++ )
V_36 = ( V_36 << 8 ) + V_28 -> V_28 [ V_35 ++ ] ;
} else {
V_36 = V_28 -> V_28 [ 3 ] ;
}
return F_15 ( V_20 , & V_28 -> V_28 [ V_35 ] , V_36 ) ;
}
static int F_16 ( struct V_19 * V_20 , void * V_10 )
{
struct V_26 * V_28 = V_10 ;
int V_23 ;
V_20 -> V_30 =
( V_28 -> V_28 [ 0 ] << 16 ) + ( V_28 -> V_28 [ 1 ] << 8 ) + V_28 -> V_28 [ 2 ] ;
switch ( V_20 -> V_30 ) {
case V_38 :
V_23 = F_14 ( V_20 , V_10 ) ;
break;
case V_31 :
V_23 = 0 ;
break;
case V_32 :
V_23 = 0 ;
break;
case V_39 :
V_23 = F_17 ( V_20 ) ;
break;
default:
F_18 ( V_20 -> V_34 , L_1 ,
V_20 -> V_30 ) ;
V_23 = - V_25 ;
}
return V_23 ;
}
static int F_19 ( struct V_40 * V_40 , unsigned int V_41 , void * V_10 )
{
struct V_42 * V_43 = V_40 -> V_44 ;
struct V_19 * V_20 = V_43 -> V_45 ;
struct V_1 V_2 ;
int V_23 ;
switch ( V_41 ) {
case V_46 :
V_23 = F_20 ( V_20 ) ;
break;
case V_47 :
V_23 = F_3 ( V_10 ) ;
break;
case V_48 :
V_23 = F_4 ( V_20 , V_10 ) ;
break;
case V_49 :
V_23 = F_12 ( V_20 , V_10 ) ;
break;
case V_50 :
V_23 = F_16 ( V_20 , V_10 ) ;
break;
default:
F_13 ( V_20 -> V_34 , L_2 , V_41 ) ;
V_23 = - V_51 ;
}
F_5 ( V_20 , & V_2 ) ;
return V_23 ;
}
static unsigned int F_21 ( struct V_40 * V_40 , T_1 * V_52 )
{
return V_53 ;
}
int F_22 ( struct V_19 * V_20 )
{
struct V_1 V_2 ;
int V_23 ;
if ( F_5 ( V_20 , & V_2 ) )
return - V_54 ;
if ( ! F_1 ( & V_2 ) )
return - V_55 ;
V_23 = F_23 ( & V_20 -> V_56 , & V_20 -> V_57 ,
& V_58 , V_20 , V_59 ) ;
if ( V_2 . V_60 == 0 )
F_18 ( V_20 -> V_34 , L_3 ) ;
if ( V_2 . V_61 == 1 )
F_24 ( V_20 , & V_20 -> V_62 ) ;
return V_23 ;
}
void F_25 ( struct V_19 * V_20 )
{
if ( V_20 -> V_57 )
F_26 ( V_20 -> V_57 ) ;
}
