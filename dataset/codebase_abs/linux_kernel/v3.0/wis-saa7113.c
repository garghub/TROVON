static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_2 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_5 [ V_6 ] != 0x00 ; V_6 += 2 )
if ( F_2 ( V_2 , V_5 [ V_6 ] , V_5 [ V_6 + 1 ] ) < 0 )
return - 1 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_7 , void * V_8 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
switch ( V_7 ) {
case V_11 :
{
int * V_12 = V_8 ;
F_2 ( V_2 , 0x02 , 0xC0 | * V_12 ) ;
F_2 ( V_2 , 0x09 ,
* V_12 < 6 ? 0x40 : 0x80 ) ;
break;
}
case V_13 :
{
T_2 * V_12 = V_8 ;
V_10 -> V_14 = * V_12 ;
if ( V_10 -> V_14 & V_15 ) {
F_1 ( V_2 , 0x0e , 0x01 ) ;
F_1 ( V_2 , 0x10 , 0x40 ) ;
} else if ( V_10 -> V_14 & V_16 ) {
F_1 ( V_2 , 0x0e , 0x01 ) ;
F_1 ( V_2 , 0x10 , 0x48 ) ;
} else if ( V_10 -> V_14 * V_17 ) {
F_1 ( V_2 , 0x0e , 0x50 ) ;
F_1 ( V_2 , 0x10 , 0x48 ) ;
}
break;
}
case V_18 :
{
struct V_19 * V_20 = V_8 ;
switch ( V_20 -> V_21 ) {
case V_22 :
V_20 -> type = V_23 ;
strncpy ( V_20 -> V_24 , L_1 , sizeof( V_20 -> V_24 ) ) ;
V_20 -> V_25 = 0 ;
V_20 -> V_26 = 255 ;
V_20 -> V_27 = 1 ;
V_20 -> V_28 = 128 ;
V_20 -> V_29 = 0 ;
break;
case V_30 :
V_20 -> type = V_23 ;
strncpy ( V_20 -> V_24 , L_2 , sizeof( V_20 -> V_24 ) ) ;
V_20 -> V_25 = 0 ;
V_20 -> V_26 = 127 ;
V_20 -> V_27 = 1 ;
V_20 -> V_28 = 71 ;
V_20 -> V_29 = 0 ;
break;
case V_31 :
V_20 -> type = V_23 ;
strncpy ( V_20 -> V_24 , L_3 , sizeof( V_20 -> V_24 ) ) ;
V_20 -> V_25 = 0 ;
V_20 -> V_26 = 127 ;
V_20 -> V_27 = 1 ;
V_20 -> V_28 = 64 ;
V_20 -> V_29 = 0 ;
break;
case V_32 :
V_20 -> type = V_23 ;
strncpy ( V_20 -> V_24 , L_4 , sizeof( V_20 -> V_24 ) ) ;
V_20 -> V_25 = - 128 ;
V_20 -> V_26 = 127 ;
V_20 -> V_27 = 1 ;
V_20 -> V_28 = 0 ;
V_20 -> V_29 = 0 ;
break;
}
break;
}
case V_33 :
{
struct V_34 * V_20 = V_8 ;
switch ( V_20 -> V_21 ) {
case V_22 :
if ( V_20 -> V_4 > 255 )
V_10 -> V_35 = 255 ;
else if ( V_20 -> V_4 < 0 )
V_10 -> V_35 = 0 ;
else
V_10 -> V_35 = V_20 -> V_4 ;
F_1 ( V_2 , 0x0a , V_10 -> V_35 ) ;
break;
case V_30 :
if ( V_20 -> V_4 > 127 )
V_10 -> V_36 = 127 ;
else if ( V_20 -> V_4 < 0 )
V_10 -> V_36 = 0 ;
else
V_10 -> V_36 = V_20 -> V_4 ;
F_1 ( V_2 , 0x0b , V_10 -> V_36 ) ;
break;
case V_31 :
if ( V_20 -> V_4 > 127 )
V_10 -> V_37 = 127 ;
else if ( V_20 -> V_4 < 0 )
V_10 -> V_37 = 0 ;
else
V_10 -> V_37 = V_20 -> V_4 ;
F_1 ( V_2 , 0x0c , V_10 -> V_37 ) ;
break;
case V_32 :
if ( V_20 -> V_4 > 127 )
V_10 -> V_38 = 127 ;
else if ( V_20 -> V_4 < - 128 )
V_10 -> V_38 = - 128 ;
else
V_10 -> V_38 = V_20 -> V_4 ;
F_1 ( V_2 , 0x0d , V_10 -> V_38 ) ;
break;
}
break;
}
case V_39 :
{
struct V_34 * V_20 = V_8 ;
switch ( V_20 -> V_21 ) {
case V_22 :
V_20 -> V_4 = V_10 -> V_35 ;
break;
case V_30 :
V_20 -> V_4 = V_10 -> V_36 ;
break;
case V_31 :
V_20 -> V_4 = V_10 -> V_37 ;
break;
case V_32 :
V_20 -> V_4 = V_10 -> V_38 ;
break;
}
break;
}
default:
break;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_40 * V_21 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
struct V_9 * V_10 ;
if ( ! F_7 ( V_42 , V_43 ) )
return - V_44 ;
V_10 = F_8 ( sizeof( struct V_9 ) , V_45 ) ;
if ( V_10 == NULL )
return - V_46 ;
V_10 -> V_14 = V_15 ;
V_10 -> V_35 = 128 ;
V_10 -> V_36 = 71 ;
V_10 -> V_37 = 64 ;
V_10 -> V_38 = 0 ;
F_9 ( V_2 , V_10 ) ;
F_10 ( V_47
L_5 ,
V_2 -> V_48 , V_42 -> V_24 ) ;
if ( F_3 ( V_2 , V_49 ) < 0 ) {
F_10 ( V_50
L_6 ) ;
F_11 ( V_10 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
F_11 ( V_10 ) ;
return 0 ;
}
static int T_3 F_13 ( void )
{
return F_14 ( & V_51 ) ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_51 ) ;
}
