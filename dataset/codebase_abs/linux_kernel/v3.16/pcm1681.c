static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ! ( ( V_3 == 0x00 ) || ( V_3 == 0x0f ) ) ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned register V_3 )
{
return F_1 ( V_2 , V_3 ) &&
( V_3 != V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
int V_9 = 0 , V_10 = - 1 , V_11 = 0 ;
if ( V_8 -> V_12 )
for ( V_9 = 0 ; V_9 < F_5 ( V_13 ) ; V_9 ++ )
if ( V_13 [ V_9 ] == V_8 -> V_14 )
V_10 = V_9 ;
if ( V_10 != - 1 ) {
F_6 ( V_8 -> V_15 , V_16 ,
V_17 , V_10 ) ;
V_11 = 1 ;
} else
V_11 = 0 ;
return F_6 ( V_8 -> V_15 , V_16 ,
V_18 , V_11 ) ;
}
static int F_7 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_5 * V_6 = F_8 ( V_20 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
V_22 -> V_23 . V_24 . V_25 [ 0 ] = V_8 -> V_12 ;
return 0 ;
}
static int F_9 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_5 * V_6 = F_8 ( V_20 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
V_8 -> V_12 = V_22 -> V_23 . V_24 . V_25 [ 0 ] ;
return F_3 ( V_6 ) ;
}
static int F_10 ( struct V_26 * V_27 ,
unsigned int V_28 )
{
struct V_5 * V_6 = V_27 -> V_6 ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
if ( ( V_28 & V_29 ) != V_30 ) {
F_11 ( V_6 -> V_2 , L_1 ) ;
return - V_31 ;
}
V_8 -> V_28 = V_28 ;
return 0 ;
}
static int F_12 ( struct V_26 * V_32 , int V_33 )
{
struct V_5 * V_6 = V_32 -> V_6 ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
int V_10 ;
if ( V_33 )
V_10 = V_34 ;
else
V_10 = 0 ;
return F_13 ( V_8 -> V_15 , V_35 , V_10 ) ;
}
static int F_14 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_26 * V_32 )
{
struct V_5 * V_6 = V_32 -> V_6 ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
int V_10 = 0 , V_40 ;
V_8 -> V_14 = F_15 ( V_39 ) ;
switch ( V_8 -> V_28 & V_41 ) {
case V_42 :
switch ( F_16 ( V_39 ) ) {
case 24 :
V_10 = 0 ;
break;
case 16 :
V_10 = 3 ;
break;
default:
return - V_31 ;
}
break;
case V_43 :
V_10 = 0x04 ;
break;
case V_44 :
V_10 = 0x05 ;
break;
default:
F_11 ( V_6 -> V_2 , L_2 ) ;
return - V_31 ;
}
V_40 = F_6 ( V_8 -> V_15 , V_45 , 0x0f , V_10 ) ;
if ( V_40 < 0 )
return V_40 ;
return F_3 ( V_6 ) ;
}
static int F_17 ( struct V_46 * V_47 ,
const struct V_48 * V_49 )
{
int V_40 ;
struct V_7 * V_8 ;
V_8 = F_18 ( & V_47 -> V_2 , sizeof( * V_8 ) , V_50 ) ;
if ( ! V_8 )
return - V_51 ;
V_8 -> V_15 = F_19 ( V_47 , & V_52 ) ;
if ( F_20 ( V_8 -> V_15 ) ) {
V_40 = F_21 ( V_8 -> V_15 ) ;
F_11 ( & V_47 -> V_2 , L_3 , V_40 ) ;
return V_40 ;
}
F_22 ( V_47 , V_8 ) ;
return F_23 ( & V_47 -> V_2 , & V_53 ,
& V_54 , 1 ) ;
}
static int F_24 ( struct V_46 * V_47 )
{
F_25 ( & V_47 -> V_2 ) ;
return 0 ;
}
