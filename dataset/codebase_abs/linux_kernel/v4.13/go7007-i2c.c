static int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
T_1 V_5 , int V_6 , T_2 * V_7 )
{
int V_8 , V_9 = - V_10 ;
T_1 V_11 ;
if ( V_2 -> V_12 == V_13 )
return - V_14 ;
#ifdef F_2
if ( V_4 )
F_3 ( V_2 -> V_15 , L_1 ,
V_5 , V_3 ) ;
else
F_3 ( V_2 -> V_15 ,
L_2 ,
* V_7 , V_5 , V_3 ) ;
#endif
F_4 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_17 == V_18 ) {
F_4 ( & V_19 ) ;
F_5 ( V_2 , 0x3c82 , 0x0020 ) ;
}
for ( V_8 = 0 ; V_8 < 10 ; ++ V_8 ) {
if ( F_6 ( V_2 , V_20 , & V_11 ) < 0 )
goto V_21;
if ( ! ( V_11 & V_22 ) )
break;
F_7 ( 100 ) ;
}
if ( V_8 == 10 ) {
F_8 ( V_2 -> V_15 , L_3 ) ;
goto V_21;
}
F_5 ( V_2 , V_23 , V_6 ) ;
F_5 ( V_2 , V_24 , V_5 ) ;
if ( ! V_4 ) {
F_5 ( V_2 , V_25 , * V_7 ) ;
F_5 ( V_2 , V_26 ,
( V_3 << 9 ) | ( V_5 >> 8 ) ) ;
V_9 = 0 ;
goto V_21;
}
if ( F_6 ( V_2 , V_25 , & V_11 ) < 0 )
goto V_21;
F_5 ( V_2 , V_26 ,
( V_3 << 9 ) | 0x0100 | ( V_5 >> 8 ) ) ;
for ( V_8 = 0 ; V_8 < 10 ; ++ V_8 ) {
if ( F_6 ( V_2 , V_20 , & V_11 ) < 0 )
goto V_21;
if ( V_11 & V_27 )
break;
F_7 ( 100 ) ;
}
if ( V_8 == 10 ) {
F_8 ( V_2 -> V_15 , L_3 ) ;
goto V_21;
}
if ( F_6 ( V_2 , V_25 , & V_11 ) < 0 )
goto V_21;
* V_7 = V_11 ;
V_9 = 0 ;
V_21:
if ( V_2 -> V_17 == V_18 ) {
F_5 ( V_2 , 0x3c82 , 0x0000 ) ;
F_9 ( & V_19 ) ;
}
F_9 ( & V_2 -> V_16 ) ;
return V_9 ;
}
static int F_10 ( struct V_28 * V_29 , T_1 V_3 ,
unsigned short V_6 , char V_30 ,
T_2 V_5 , int V_31 , union V_32 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_29 ) ;
if ( V_31 != V_33 )
return - V_10 ;
return F_1 ( V_2 , V_3 , V_30 == V_34 , V_5 ,
V_6 & V_35 ? 0x10 : 0x00 , & V_7 -> V_36 ) ;
}
static int F_12 ( struct V_28 * V_29 ,
struct V_37 V_38 [] , int V_39 )
{
struct V_1 * V_2 = F_11 ( V_29 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_39 ; ++ V_8 ) {
if ( V_38 [ V_8 ] . V_40 == 2 ) {
if ( V_8 + 1 == V_39 || V_38 [ V_8 ] . V_3 != V_38 [ V_8 + 1 ] . V_3 ||
( V_38 [ V_8 ] . V_6 & V_41 ) ||
! ( V_38 [ V_8 + 1 ] . V_6 & V_41 ) ||
V_38 [ V_8 + 1 ] . V_40 != 1 )
return - V_10 ;
if ( F_1 ( V_2 , V_38 [ V_8 ] . V_3 , 1 ,
( V_38 [ V_8 ] . V_42 [ 0 ] << 8 ) | V_38 [ V_8 ] . V_42 [ 1 ] ,
0x01 , & V_38 [ V_8 + 1 ] . V_42 [ 0 ] ) < 0 )
return - V_10 ;
++ V_8 ;
} else if ( V_38 [ V_8 ] . V_40 == 3 ) {
if ( V_38 [ V_8 ] . V_6 & V_41 )
return - V_10 ;
if ( V_38 [ V_8 ] . V_40 != 3 )
return - V_10 ;
if ( F_1 ( V_2 , V_38 [ V_8 ] . V_3 , 0 ,
( V_38 [ V_8 ] . V_42 [ 0 ] << 8 ) | V_38 [ V_8 ] . V_42 [ 1 ] ,
0x01 , & V_38 [ V_8 ] . V_42 [ 2 ] ) < 0 )
return - V_10 ;
} else
return - V_10 ;
}
return V_39 ;
}
static T_3 F_13 ( struct V_28 * V_29 )
{
return V_43 ;
}
int F_14 ( struct V_1 * V_2 )
{
memcpy ( & V_2 -> V_28 , & V_44 ,
sizeof( V_44 ) ) ;
V_2 -> V_28 . V_15 . V_45 = V_2 -> V_15 ;
F_15 ( & V_2 -> V_28 , V_2 ) ;
if ( F_16 ( & V_2 -> V_28 ) < 0 ) {
F_8 ( V_2 -> V_15 ,
L_4 ) ;
return - 1 ;
}
return 0 ;
}
