int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
struct V_6 V_7 = {} ;
if ( F_2 ( V_4 && V_4 -> V_2 != V_2 ) )
return - V_8 ;
V_7 . V_9 = V_10 ;
if ( V_4 ) {
V_7 . V_11 = V_4 -> V_12 << 16 ;
V_7 . V_13 = V_14 | V_15 | V_16 ;
} else {
V_7 . V_11 = 0 ;
V_7 . V_13 = V_14 | V_15 | V_17 ;
}
V_5 = F_3 ( V_2 , & V_7 , 0 ) ;
if ( V_5 )
return V_5 ;
if ( ! F_4 ( V_2 ) && ! ( V_7 . V_18 [ 0 ] & V_19 ) )
return - V_20 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_6 * V_7 , int V_21 )
{
struct V_22 V_23 = {} ;
int V_24 , V_5 ;
if ( V_21 < 0 )
V_21 = V_25 ;
V_5 = - V_26 ;
for ( V_24 = 0 ; V_24 <= V_21 ; V_24 ++ ) {
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 ) {
if ( F_4 ( V_2 ) ) {
if ( V_7 -> V_18 [ 0 ] & V_27 )
break;
}
continue;
}
memset ( & V_23 , 0 , sizeof( struct V_22 ) ) ;
memset ( V_7 -> V_18 , 0 , sizeof( V_7 -> V_18 ) ) ;
V_7 -> V_21 = 0 ;
V_23 . V_7 = V_7 ;
V_7 -> V_28 = NULL ;
F_6 ( V_2 , & V_23 ) ;
V_5 = V_7 -> error ;
if ( ! V_7 -> error )
break;
if ( F_4 ( V_2 ) ) {
if ( V_7 -> V_18 [ 0 ] & V_27 )
break;
}
}
return V_5 ;
}
int F_7 ( struct V_3 * V_4 , int V_29 )
{
struct V_6 V_7 = {} ;
V_7 . V_9 = V_30 ;
V_7 . V_13 = V_15 | V_16 ;
switch ( V_29 ) {
case V_31 :
V_7 . V_11 = V_32 ;
break;
case V_33 :
V_7 . V_11 = V_34 ;
break;
default:
return - V_8 ;
}
return F_5 ( V_4 -> V_2 , V_4 , & V_7 , V_25 ) ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_35 , T_1 * V_36 )
{
struct V_6 V_7 = {} ;
int V_24 , V_5 = 0 ;
V_7 . V_9 = V_37 ;
if ( F_4 ( V_2 ) )
V_7 . V_11 = V_35 & ( 1 << 30 ) ;
else
V_7 . V_11 = V_35 ;
V_7 . V_13 = V_14 | V_38 | V_17 ;
for ( V_24 = 100 ; V_24 ; V_24 -- ) {
V_5 = F_5 ( V_2 , NULL , & V_7 , V_25 ) ;
if ( V_5 )
break;
if ( V_35 == 0 )
break;
if ( F_4 ( V_2 ) ) {
if ( ! ( V_7 . V_18 [ 0 ] & V_39 ) )
break;
} else {
if ( V_7 . V_18 [ 0 ] & V_40 )
break;
}
V_5 = - V_41 ;
F_9 ( 10 ) ;
}
if ( ! V_24 )
F_10 ( L_1 , F_11 ( V_2 ) ) ;
if ( V_36 && ! F_4 ( V_2 ) )
* V_36 = V_7 . V_18 [ 0 ] ;
return V_5 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_35 )
{
struct V_6 V_7 = {} ;
int V_5 ;
static const T_2 V_42 = 0xAA ;
T_2 V_43 ;
V_7 . V_9 = V_44 ;
V_7 . V_11 = ( ( V_35 & 0xFF8000 ) != 0 ) << 8 | V_42 ;
V_7 . V_13 = V_45 | V_46 | V_17 ;
V_5 = F_3 ( V_2 , & V_7 , 0 ) ;
if ( V_5 )
return V_5 ;
if ( F_4 ( V_2 ) )
V_43 = V_7 . V_18 [ 1 ] & 0xFF ;
else
V_43 = V_7 . V_18 [ 0 ] & 0xFF ;
if ( V_43 != V_42 )
return - V_26 ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 , unsigned int * V_12 )
{
int V_5 ;
struct V_6 V_7 = {} ;
V_7 . V_9 = V_47 ;
V_7 . V_11 = 0 ;
V_7 . V_13 = V_48 | V_17 ;
V_5 = F_3 ( V_2 , & V_7 , V_25 ) ;
if ( V_5 )
return V_5 ;
* V_12 = V_7 . V_18 [ 0 ] >> 16 ;
return 0 ;
}
int F_14 ( struct V_3 * V_4 )
{
int V_5 ;
struct V_22 V_23 = {} ;
struct V_6 V_7 = {} ;
struct V_49 V_28 = {} ;
struct V_50 V_51 ;
T_3 * V_52 ;
V_5 = F_1 ( V_4 -> V_2 , V_4 ) ;
if ( V_5 )
return V_5 ;
V_52 = F_15 ( sizeof( V_4 -> V_53 ) , V_54 ) ;
if ( ! V_52 )
return - V_55 ;
V_23 . V_7 = & V_7 ;
V_23 . V_28 = & V_28 ;
V_7 . V_9 = V_56 ;
V_7 . V_11 = 0 ;
V_7 . V_13 = V_14 | V_15 | V_57 ;
V_28 . V_58 = 8 ;
V_28 . V_59 = 1 ;
V_28 . V_13 = V_60 ;
V_28 . V_51 = & V_51 ;
V_28 . V_61 = 1 ;
F_16 ( & V_51 , V_52 , 8 ) ;
F_17 ( & V_28 , V_4 ) ;
F_6 ( V_4 -> V_2 , & V_23 ) ;
V_4 -> V_53 [ 0 ] = F_18 ( V_52 [ 0 ] ) ;
V_4 -> V_53 [ 1 ] = F_18 ( V_52 [ 1 ] ) ;
F_19 ( V_52 ) ;
if ( V_7 . error )
return V_7 . error ;
if ( V_28 . error )
return V_28 . error ;
return 0 ;
}
int F_20 ( struct V_3 * V_4 , int V_62 , int V_63 ,
T_2 V_64 , T_2 * V_18 )
{
struct V_22 V_23 = {} ;
struct V_6 V_7 = {} ;
struct V_49 V_28 = {} ;
struct V_50 V_51 ;
V_62 = ! ! V_62 ;
V_64 &= 0xF ;
V_23 . V_7 = & V_7 ;
V_23 . V_28 = & V_28 ;
V_7 . V_9 = V_65 ;
V_7 . V_11 = V_62 << 31 | 0x00FFFFFF ;
V_7 . V_11 &= ~ ( 0xF << ( V_63 * 4 ) ) ;
V_7 . V_11 |= V_64 << ( V_63 * 4 ) ;
V_7 . V_13 = V_14 | V_15 | V_57 ;
V_28 . V_58 = 64 ;
V_28 . V_59 = 1 ;
V_28 . V_13 = V_60 ;
V_28 . V_51 = & V_51 ;
V_28 . V_61 = 1 ;
F_16 ( & V_51 , V_18 , 64 ) ;
F_17 ( & V_28 , V_4 ) ;
F_6 ( V_4 -> V_2 , & V_23 ) ;
if ( V_7 . error )
return V_7 . error ;
if ( V_28 . error )
return V_28 . error ;
return 0 ;
}
int F_21 ( struct V_3 * V_4 , void * V_66 )
{
int V_5 ;
struct V_22 V_23 = {} ;
struct V_6 V_7 = {} ;
struct V_49 V_28 = {} ;
struct V_50 V_51 ;
V_5 = F_1 ( V_4 -> V_2 , V_4 ) ;
if ( V_5 )
return V_5 ;
V_23 . V_7 = & V_7 ;
V_23 . V_28 = & V_28 ;
V_7 . V_9 = V_67 ;
V_7 . V_11 = 0 ;
V_7 . V_13 = V_68 | V_15 | V_57 ;
V_28 . V_58 = 64 ;
V_28 . V_59 = 1 ;
V_28 . V_13 = V_60 ;
V_28 . V_51 = & V_51 ;
V_28 . V_61 = 1 ;
F_16 ( & V_51 , V_66 , 64 ) ;
F_17 ( & V_28 , V_4 ) ;
F_6 ( V_4 -> V_2 , & V_23 ) ;
if ( V_7 . error )
return V_7 . error ;
if ( V_28 . error )
return V_28 . error ;
return 0 ;
}
