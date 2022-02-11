static int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
T_1 V_5 , int V_6 , T_2 * V_7 )
{
int V_8 , V_9 = - 1 ;
T_1 V_10 ;
if ( V_2 -> V_11 == V_12 )
return - 1 ;
#ifdef F_2
if ( V_4 )
F_3 ( V_13 L_1 ,
V_5 , V_3 ) ;
else
F_3 ( V_13
L_2 ,
* V_7 , V_5 , V_3 ) ;
#endif
F_4 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_15 == V_16 ) {
F_4 ( & V_17 ) ;
F_5 ( V_2 , 0x3c82 , 0x0020 ) ;
}
for ( V_8 = 0 ; V_8 < 10 ; ++ V_8 ) {
if ( F_6 ( V_2 , V_18 , & V_10 ) < 0 )
goto V_19;
if ( ! ( V_10 & V_20 ) )
break;
F_7 ( 100 ) ;
}
if ( V_8 == 10 ) {
F_3 ( V_21 L_3 ) ;
goto V_19;
}
F_5 ( V_2 , V_22 , V_6 ) ;
F_5 ( V_2 , V_23 , V_5 ) ;
if ( ! V_4 ) {
F_5 ( V_2 , V_24 , * V_7 ) ;
F_5 ( V_2 , V_25 ,
( V_3 << 9 ) | ( V_5 >> 8 ) ) ;
V_9 = 0 ;
goto V_19;
}
if ( F_6 ( V_2 , V_24 , & V_10 ) < 0 )
goto V_19;
F_5 ( V_2 , V_25 ,
( V_3 << 9 ) | 0x0100 | ( V_5 >> 8 ) ) ;
for ( V_8 = 0 ; V_8 < 10 ; ++ V_8 ) {
if ( F_6 ( V_2 , V_18 , & V_10 ) < 0 )
goto V_19;
if ( V_10 & V_26 )
break;
F_7 ( 100 ) ;
}
if ( V_8 == 10 ) {
F_3 ( V_21 L_3 ) ;
goto V_19;
}
if ( F_6 ( V_2 , V_24 , & V_10 ) < 0 )
goto V_19;
* V_7 = V_10 ;
V_9 = 0 ;
V_19:
if ( V_2 -> V_15 == V_16 ) {
F_5 ( V_2 , 0x3c82 , 0x0000 ) ;
F_8 ( & V_17 ) ;
}
F_8 ( & V_2 -> V_14 ) ;
return V_9 ;
}
static int F_9 ( struct V_27 * V_28 , T_1 V_3 ,
unsigned short V_6 , char V_29 ,
T_2 V_5 , int V_30 , union V_31 * V_7 )
{
struct V_1 * V_2 = F_10 ( V_28 ) ;
if ( V_30 != V_32 )
return - 1 ;
return F_1 ( V_2 , V_3 , V_29 == V_33 , V_5 ,
V_6 & V_34 ? 0x10 : 0x00 , & V_7 -> V_35 ) ;
}
static int F_11 ( struct V_27 * V_28 ,
struct V_36 V_37 [] , int V_38 )
{
struct V_1 * V_2 = F_10 ( V_28 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_38 ; ++ V_8 ) {
if ( V_37 [ V_8 ] . V_39 == 2 ) {
if ( V_8 + 1 == V_38 || V_37 [ V_8 ] . V_3 != V_37 [ V_8 + 1 ] . V_3 ||
( V_37 [ V_8 ] . V_6 & V_40 ) ||
! ( V_37 [ V_8 + 1 ] . V_6 & V_40 ) ||
V_37 [ V_8 + 1 ] . V_39 != 1 )
return - 1 ;
if ( F_1 ( V_2 , V_37 [ V_8 ] . V_3 , 1 ,
( V_37 [ V_8 ] . V_41 [ 0 ] << 8 ) | V_37 [ V_8 ] . V_41 [ 1 ] ,
0x01 , & V_37 [ V_8 + 1 ] . V_41 [ 0 ] ) < 0 )
return - 1 ;
++ V_8 ;
} else if ( V_37 [ V_8 ] . V_39 == 3 ) {
if ( V_37 [ V_8 ] . V_6 & V_40 )
return - 1 ;
if ( V_37 [ V_8 ] . V_39 != 3 )
return - 1 ;
if ( F_1 ( V_2 , V_37 [ V_8 ] . V_3 , 0 ,
( V_37 [ V_8 ] . V_41 [ 0 ] << 8 ) | V_37 [ V_8 ] . V_41 [ 1 ] ,
0x01 , & V_37 [ V_8 ] . V_41 [ 2 ] ) < 0 )
return - 1 ;
} else
return - 1 ;
}
return 0 ;
}
static T_3 F_12 ( struct V_27 * V_28 )
{
return V_42 ;
}
int F_13 ( struct V_1 * V_2 )
{
memcpy ( & V_2 -> V_27 , & V_43 ,
sizeof( V_43 ) ) ;
V_2 -> V_27 . V_44 . V_45 = V_2 -> V_44 ;
F_14 ( & V_2 -> V_27 , V_2 ) ;
if ( F_15 ( & V_2 -> V_27 ) < 0 ) {
F_3 ( V_21
L_4 ) ;
return - 1 ;
}
return 0 ;
}
