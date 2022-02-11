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
V_5 -> type = V_19 | V_20 | V_21 ;
V_5 -> V_10 = L_2 ;
V_5 -> V_22 = 405 ;
V_13 . V_11 = V_5 ;
return F_3 ( & V_3 -> V_12 , & V_13 ) ;
}
static int F_5 ( struct V_2 * V_3 , int V_23 ,
unsigned char V_24 , char * V_25 , int V_26 ,
char * V_27 , int V_28 )
{
int V_29 ;
if ( ( V_28 > sizeof( V_3 -> V_30 ) ) || ( V_26 > sizeof( V_3 -> V_30 ) ) )
return - V_31 ;
if ( V_26 ) {
memcpy ( & V_3 -> V_30 , V_25 , V_26 ) ;
V_29 = F_6 ( V_3 -> V_32 , F_7 ( V_3 -> V_32 , 0 ) ,
V_33 , V_34 ,
( V_23 << 8 ) | V_24 , 0 , & V_3 -> V_30 ,
V_26 , 1000 ) ;
if ( V_29 < 0 )
return V_29 ;
}
V_29 = F_6 ( V_3 -> V_32 , F_8 ( V_3 -> V_32 , 0 ) ,
V_35 , V_36 ,
( V_23 << 8 ) | V_24 , 0 , & V_3 -> V_30 , V_28 , 1000 ) ;
if ( V_29 == V_28 ) {
memcpy ( V_27 , & V_3 -> V_30 , V_28 ) ;
V_29 = 0 ;
} else if ( V_29 >= 0 )
V_29 = - V_37 ;
return V_29 ;
}
static int F_9 ( struct V_2 * V_3 , int V_23 ,
unsigned char V_24 , char * V_27 , int V_28 )
{
int V_29 ;
if ( V_28 > sizeof( V_3 -> V_30 ) )
return - V_31 ;
memcpy ( & V_3 -> V_30 , V_27 , V_28 ) ;
V_29 = F_6 ( V_3 -> V_32 , F_7 ( V_3 -> V_32 , 0 ) ,
V_33 , V_34 ,
( V_23 << 8 ) | V_24 , 0 , & V_3 -> V_30 , V_28 , 1000 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_6 ( V_3 -> V_32 , F_8 ( V_3 -> V_32 , 0 ) ,
V_38 , V_36 ,
0 , 0 , & V_3 -> V_30 , 2 , 1000 ) ;
if ( ( V_29 == 2 ) && ( V_3 -> V_30 [ 1 ] == ( V_28 - 1 ) ) )
V_29 = 0 ;
else if ( V_29 >= 0 )
V_29 = - V_37 ;
return V_29 ;
}
static int F_10 ( struct V_12 * V_12 , struct V_39 * V_40 ,
int V_41 )
{
struct V_2 * V_3 = F_11 ( V_12 ) ;
int V_42 = 0 , V_24 ;
if ( V_41 <= 0 )
return 0 ;
F_12 ( & V_3 -> V_43 ) ;
V_24 = V_40 [ 0 ] . V_24 << 1 ;
if ( V_41 == 1 ) {
if ( V_40 [ 0 ] . V_44 & V_45 )
V_42 = F_5 ( V_3 , 1 , V_24 , NULL , 0 ,
V_40 [ 0 ] . V_46 , V_40 [ 0 ] . V_28 ) ;
else
V_42 = F_9 ( V_3 , 1 , V_24 , V_40 [ 0 ] . V_46 ,
V_40 [ 0 ] . V_28 ) ;
} else if ( V_41 == 2 ) {
if ( V_40 [ 0 ] . V_24 != V_40 [ 1 ] . V_24 ) {
F_13 ( & V_3 -> V_47 , L_4 ) ;
V_42 = - V_31 ;
goto V_48;
}
if ( ( V_40 [ 0 ] . V_44 & V_45 ) || ! ( V_40 [ 1 ] . V_44 & V_45 ) ) {
F_13 ( & V_3 -> V_47 , L_5 ,
V_40 [ 0 ] . V_44 & V_45 ,
V_40 [ 1 ] . V_44 & V_45 ) ;
V_42 = - V_31 ;
goto V_48;
}
V_42 = F_5 ( V_3 , 1 , V_24 , V_40 [ 0 ] . V_46 , V_40 [ 0 ] . V_28 ,
V_40 [ 1 ] . V_46 , V_40 [ 1 ] . V_28 ) ;
} else {
F_13 ( & V_3 -> V_47 , L_6 , V_41 ) ;
}
V_48:
F_14 ( & V_3 -> V_43 ) ;
return V_42 ? V_42 : V_41 ;
}
static T_1 F_15 ( struct V_12 * V_49 )
{
return V_50 | V_51 ;
}
static int F_16 ( struct V_2 * V_3 )
{
char V_52 [ 2 ] ;
F_12 ( & V_3 -> V_43 ) ;
F_5 ( V_3 , 0 , 0x54 , NULL , 0 , V_52 , 1 ) ;
V_52 [ 0 ] = 0 ;
V_52 [ 1 ] = 0x8 ;
F_9 ( V_3 , 1 , 0x54 , V_52 , 2 ) ;
V_52 [ 1 ] = 0x18 ;
F_9 ( V_3 , 1 , 0x54 , V_52 , 2 ) ;
F_14 ( & V_3 -> V_43 ) ;
return 0 ;
}
int F_17 ( struct V_2 * V_3 )
{
int V_42 = - V_53 ;
F_16 ( V_3 ) ;
V_3 -> V_12 = V_54 ;
V_3 -> V_12 . V_3 . V_55 = & V_3 -> V_32 -> V_3 ;
F_18 ( & V_3 -> V_12 , V_3 ) ;
V_42 = F_19 ( & V_3 -> V_12 ) ;
return V_42 ;
}
