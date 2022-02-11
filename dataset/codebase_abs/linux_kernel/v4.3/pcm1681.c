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
if ( V_8 -> V_12 ) {
for ( V_9 = 0 ; V_9 < F_5 ( V_13 ) ; V_9 ++ ) {
if ( V_13 [ V_9 ] == V_8 -> V_14 ) {
V_10 = V_9 ;
break;
}
}
}
if ( V_10 != - 1 ) {
F_6 ( V_8 -> V_15 , V_16 ,
V_17 , V_10 << 3 ) ;
V_11 = 1 ;
} else {
V_11 = 0 ;
}
return F_6 ( V_8 -> V_15 , V_16 ,
V_18 , V_11 ) ;
}
static int F_7 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_5 * V_6 = F_8 ( V_20 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
V_22 -> V_23 . integer . V_23 [ 0 ] = V_8 -> V_12 ;
return 0 ;
}
static int F_9 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_5 * V_6 = F_8 ( V_20 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
V_8 -> V_12 = V_22 -> V_23 . integer . V_23 [ 0 ] ;
return F_3 ( V_6 ) ;
}
static int F_10 ( struct V_24 * V_25 ,
unsigned int V_26 )
{
struct V_5 * V_6 = V_25 -> V_6 ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
if ( ( V_26 & V_27 ) != V_28 ) {
F_11 ( V_6 -> V_2 , L_1 ) ;
return - V_29 ;
}
V_8 -> V_26 = V_26 ;
return 0 ;
}
static int F_12 ( struct V_24 * V_30 , int V_31 )
{
struct V_5 * V_6 = V_30 -> V_6 ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
int V_10 ;
if ( V_31 )
V_10 = V_32 ;
else
V_10 = 0 ;
return F_13 ( V_8 -> V_15 , V_33 , V_10 ) ;
}
static int F_14 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_24 * V_30 )
{
struct V_5 * V_6 = V_30 -> V_6 ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
int V_10 = 0 , V_38 ;
V_8 -> V_14 = F_15 ( V_37 ) ;
switch ( V_8 -> V_26 & V_39 ) {
case V_40 :
switch ( F_16 ( V_37 ) ) {
case 24 :
V_10 = 0 ;
break;
case 16 :
V_10 = 3 ;
break;
default:
return - V_29 ;
}
break;
case V_41 :
V_10 = 0x04 ;
break;
case V_42 :
V_10 = 0x05 ;
break;
default:
F_11 ( V_6 -> V_2 , L_2 ) ;
return - V_29 ;
}
V_38 = F_6 ( V_8 -> V_15 , V_43 , 0x0f , V_10 ) ;
if ( V_38 < 0 )
return V_38 ;
return F_3 ( V_6 ) ;
}
static int F_17 ( struct V_44 * V_45 ,
const struct V_46 * V_47 )
{
int V_38 ;
struct V_7 * V_8 ;
V_8 = F_18 ( & V_45 -> V_2 , sizeof( * V_8 ) , V_48 ) ;
if ( ! V_8 )
return - V_49 ;
V_8 -> V_15 = F_19 ( V_45 , & V_50 ) ;
if ( F_20 ( V_8 -> V_15 ) ) {
V_38 = F_21 ( V_8 -> V_15 ) ;
F_11 ( & V_45 -> V_2 , L_3 , V_38 ) ;
return V_38 ;
}
F_22 ( V_45 , V_8 ) ;
return F_23 ( & V_45 -> V_2 , & V_51 ,
& V_52 , 1 ) ;
}
static int F_24 ( struct V_44 * V_45 )
{
F_25 ( & V_45 -> V_2 ) ;
return 0 ;
}
