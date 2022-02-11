struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_6 ;
struct V_7 V_8 = {
F_2 ( L_1 , V_9 ) ,
} ;
V_5 -> V_10 = L_2 ;
V_8 . V_11 = V_5 ;
return F_3 ( & V_3 -> V_12 , & V_8 ) ;
}
struct V_1 * F_4 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_6 ;
struct V_7 V_13 = {
F_2 ( L_3 , V_14 ) ,
} ;
V_5 -> V_15 = V_16 ;
V_5 -> V_17 = V_18 ;
V_5 -> type = V_19 ;
V_5 -> V_10 = L_2 ;
V_5 -> V_20 = 405 ;
V_13 . V_11 = V_5 ;
return F_3 ( & V_3 -> V_12 , & V_13 ) ;
}
static int F_5 ( struct V_2 * V_3 , int V_21 ,
unsigned char V_22 , char * V_23 , int V_24 ,
char * V_25 , int V_26 )
{
int V_27 ;
if ( ( V_26 > sizeof( V_3 -> V_28 ) ) || ( V_24 > sizeof( V_3 -> V_28 ) ) )
return - V_29 ;
if ( V_24 ) {
memcpy ( & V_3 -> V_28 , V_23 , V_24 ) ;
V_27 = F_6 ( V_3 -> V_30 , F_7 ( V_3 -> V_30 , 0 ) ,
V_31 , V_32 ,
( V_21 << 8 ) | V_22 , 0 , & V_3 -> V_28 ,
V_24 , 1000 ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_27 = F_6 ( V_3 -> V_30 , F_8 ( V_3 -> V_30 , 0 ) ,
V_33 , V_34 ,
( V_21 << 8 ) | V_22 , 0 , & V_3 -> V_28 , V_26 , 1000 ) ;
if ( V_27 == V_26 ) {
memcpy ( V_25 , & V_3 -> V_28 , V_26 ) ;
V_27 = 0 ;
} else if ( V_27 >= 0 )
V_27 = - V_35 ;
return V_27 ;
}
static int F_9 ( struct V_2 * V_3 , int V_21 ,
unsigned char V_22 , char * V_25 , int V_26 )
{
int V_27 ;
if ( V_26 > sizeof( V_3 -> V_28 ) )
return - V_29 ;
memcpy ( & V_3 -> V_28 , V_25 , V_26 ) ;
V_27 = F_6 ( V_3 -> V_30 , F_7 ( V_3 -> V_30 , 0 ) ,
V_31 , V_32 ,
( V_21 << 8 ) | V_22 , 0 , & V_3 -> V_28 , V_26 , 1000 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_6 ( V_3 -> V_30 , F_8 ( V_3 -> V_30 , 0 ) ,
V_36 , V_34 ,
0 , 0 , & V_3 -> V_28 , 2 , 1000 ) ;
if ( ( V_27 == 2 ) && ( V_3 -> V_28 [ 1 ] == ( V_26 - 1 ) ) )
V_27 = 0 ;
else if ( V_27 >= 0 )
V_27 = - V_35 ;
return V_27 ;
}
static int F_10 ( struct V_12 * V_12 , struct V_37 * V_38 ,
int V_39 )
{
struct V_2 * V_3 = F_11 ( V_12 ) ;
int V_40 = 0 , V_22 ;
if ( V_39 <= 0 )
return 0 ;
F_12 ( & V_3 -> V_41 ) ;
V_22 = V_38 [ 0 ] . V_22 << 1 ;
if ( V_39 == 1 ) {
if ( V_38 [ 0 ] . V_42 & V_43 )
V_40 = F_5 ( V_3 , 1 , V_22 , NULL , 0 ,
V_38 [ 0 ] . V_44 , V_38 [ 0 ] . V_26 ) ;
else
V_40 = F_9 ( V_3 , 1 , V_22 , V_38 [ 0 ] . V_44 ,
V_38 [ 0 ] . V_26 ) ;
} else if ( V_39 == 2 ) {
if ( V_38 [ 0 ] . V_22 != V_38 [ 1 ] . V_22 ) {
F_13 ( & V_3 -> V_45 , L_4
L_5 ) ;
V_40 = - V_29 ;
goto V_46;
}
if ( ( V_38 [ 0 ] . V_42 & V_43 ) || ! ( V_38 [ 1 ] . V_42 & V_43 ) ) {
F_13 ( & V_3 -> V_45 , L_6
L_7 , V_38 [ 0 ] . V_42 & V_43 ,
V_38 [ 1 ] . V_42 & V_43 ) ;
V_40 = - V_29 ;
goto V_46;
}
V_40 = F_5 ( V_3 , 1 , V_22 , V_38 [ 0 ] . V_44 , V_38 [ 0 ] . V_26 ,
V_38 [ 1 ] . V_44 , V_38 [ 1 ] . V_26 ) ;
} else {
F_13 ( & V_3 -> V_45 , L_8 , V_39 ) ;
}
V_46:
F_14 ( & V_3 -> V_41 ) ;
return V_40 ? V_40 : V_39 ;
}
static T_1 F_15 ( struct V_12 * V_47 )
{
return V_48 | V_49 ;
}
static int F_16 ( struct V_2 * V_3 )
{
char V_50 [ 2 ] ;
F_12 ( & V_3 -> V_41 ) ;
F_5 ( V_3 , 0 , 0x54 , NULL , 0 , V_50 , 1 ) ;
V_50 [ 0 ] = 0 ;
V_50 [ 1 ] = 0x8 ;
F_9 ( V_3 , 1 , 0x54 , V_50 , 2 ) ;
V_50 [ 1 ] = 0x18 ;
F_9 ( V_3 , 1 , 0x54 , V_50 , 2 ) ;
F_14 ( & V_3 -> V_41 ) ;
return 0 ;
}
int F_17 ( struct V_2 * V_3 )
{
int V_40 = - V_51 ;
F_16 ( V_3 ) ;
memcpy ( & V_3 -> V_12 , & V_52 ,
sizeof( struct V_12 ) ) ;
V_3 -> V_12 . V_3 . V_53 = & V_3 -> V_30 -> V_3 ;
F_18 ( & V_3 -> V_12 , V_3 ) ;
V_40 = F_19 ( & V_3 -> V_12 ) ;
return V_40 ;
}
