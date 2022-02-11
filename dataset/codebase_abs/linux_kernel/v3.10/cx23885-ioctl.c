int F_1 ( struct V_1 * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = ( (struct V_7 * ) V_2 ) -> V_6 ;
int V_8 = 0 ;
T_1 V_9 ;
V_4 -> V_10 = V_11 ;
V_4 -> V_12 = 0 ;
switch ( V_4 -> V_13 . type ) {
case V_14 :
switch ( V_4 -> V_13 . V_15 ) {
case 0 :
V_9 = F_2 ( V_16 ) & 0xff ;
switch ( V_6 -> V_17 -> V_18 ) {
case 0x8852 :
if ( V_9 == 0x04 )
V_4 -> V_10 = V_19 ;
else
V_4 -> V_10 = V_20 ;
break;
case 0x8880 :
if ( V_9 == 0x0e || V_9 == 0x0f )
V_4 -> V_10 = V_21 ;
else
V_4 -> V_10 = V_19 ;
break;
default:
V_4 -> V_10 = V_22 ;
break;
}
V_4 -> V_12 = ( V_6 -> V_17 -> V_18 << 16 ) | ( V_9 << 8 ) |
( V_6 -> V_23 & 0xff ) ;
break;
case 1 :
if ( V_6 -> V_24 != NULL ) {
V_4 -> V_10 = V_25 ;
V_4 -> V_12 = 0 ;
}
break;
case 2 :
F_3 ( V_6 , V_26 , V_27 , V_28 ,
V_4 ) ;
break;
default:
V_8 = - V_29 ;
break;
}
break;
case V_30 :
F_4 ( V_6 , V_27 , V_28 , V_4 ) ;
break;
case V_31 :
F_4 ( V_6 , V_27 , V_28 , V_4 ) ;
break;
default:
V_8 = - V_29 ;
break;
}
return V_8 ;
}
static int F_5 ( struct V_5 * V_6 ,
struct V_32 * V_33 )
{
if ( ( V_33 -> V_33 & 0x3 ) != 0 || V_33 -> V_33 >= F_6 ( V_6 -> V_17 , 0 ) )
return - V_29 ;
V_33 -> V_34 = 4 ;
V_33 -> V_35 = F_2 ( V_33 -> V_33 ) ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 ,
struct V_32 * V_33 )
{
T_2 V_36 ;
if ( V_6 -> V_24 == NULL )
return - V_29 ;
if ( ( V_33 -> V_33 & 0x3 ) != 0 || V_33 -> V_33 >= 0x10000 )
return - V_29 ;
if ( F_8 ( V_6 , ( V_37 ) V_33 -> V_33 , & V_36 ) )
return - V_29 ;
V_33 -> V_34 = 4 ;
V_33 -> V_35 = V_36 ;
return 0 ;
}
int F_9 ( struct V_1 * V_1 , void * V_2 ,
struct V_32 * V_33 )
{
struct V_5 * V_6 = ( (struct V_7 * ) V_2 ) -> V_6 ;
if ( ! F_10 ( V_38 ) )
return - V_39 ;
if ( V_33 -> V_13 . type == V_14 ) {
switch ( V_33 -> V_13 . V_15 ) {
case 0 :
return F_5 ( V_6 , V_33 ) ;
case 1 :
return F_7 ( V_6 , V_33 ) ;
default:
break;
}
}
F_4 ( V_6 , V_27 , V_40 , V_33 ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 ,
const struct V_32 * V_33 )
{
if ( ( V_33 -> V_33 & 0x3 ) != 0 || V_33 -> V_33 >= F_6 ( V_6 -> V_17 , 0 ) )
return - V_29 ;
F_12 ( V_33 -> V_33 , V_33 -> V_35 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 ,
const struct V_32 * V_33 )
{
if ( V_6 -> V_24 == NULL )
return - V_29 ;
if ( ( V_33 -> V_33 & 0x3 ) != 0 || V_33 -> V_33 >= 0x10000 )
return - V_29 ;
if ( F_14 ( V_6 , ( V_37 ) V_33 -> V_33 , ( T_2 ) V_33 -> V_35 ) )
return - V_29 ;
return 0 ;
}
int F_15 ( struct V_1 * V_1 , void * V_2 ,
const struct V_32 * V_33 )
{
struct V_5 * V_6 = ( (struct V_7 * ) V_2 ) -> V_6 ;
if ( ! F_10 ( V_38 ) )
return - V_39 ;
if ( V_33 -> V_13 . type == V_14 ) {
switch ( V_33 -> V_13 . V_15 ) {
case 0 :
return F_11 ( V_6 , V_33 ) ;
case 1 :
return F_13 ( V_6 , V_33 ) ;
default:
break;
}
}
F_4 ( V_6 , V_27 , V_41 , V_33 ) ;
return 0 ;
}
