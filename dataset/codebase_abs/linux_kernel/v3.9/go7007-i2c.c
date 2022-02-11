static int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
T_1 V_5 , int V_6 , T_2 * V_7 )
{
int V_8 , V_9 = - 1 ;
T_1 V_10 ;
if ( V_2 -> V_11 == V_12 )
return - 1 ;
#ifdef F_2
if ( V_4 )
F_3 ( V_2 -> V_13 , L_1 ,
V_5 , V_3 ) ;
else
F_3 ( V_2 -> V_13 ,
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
F_8 ( V_2 -> V_13 , L_3 ) ;
goto V_19;
}
F_5 ( V_2 , V_21 , V_6 ) ;
F_5 ( V_2 , V_22 , V_5 ) ;
if ( ! V_4 ) {
F_5 ( V_2 , V_23 , * V_7 ) ;
F_5 ( V_2 , V_24 ,
( V_3 << 9 ) | ( V_5 >> 8 ) ) ;
V_9 = 0 ;
goto V_19;
}
if ( F_6 ( V_2 , V_23 , & V_10 ) < 0 )
goto V_19;
F_5 ( V_2 , V_24 ,
( V_3 << 9 ) | 0x0100 | ( V_5 >> 8 ) ) ;
for ( V_8 = 0 ; V_8 < 10 ; ++ V_8 ) {
if ( F_6 ( V_2 , V_18 , & V_10 ) < 0 )
goto V_19;
if ( V_10 & V_25 )
break;
F_7 ( 100 ) ;
}
if ( V_8 == 10 ) {
F_8 ( V_2 -> V_13 , L_3 ) ;
goto V_19;
}
if ( F_6 ( V_2 , V_23 , & V_10 ) < 0 )
goto V_19;
* V_7 = V_10 ;
V_9 = 0 ;
V_19:
if ( V_2 -> V_15 == V_16 ) {
F_5 ( V_2 , 0x3c82 , 0x0000 ) ;
F_9 ( & V_17 ) ;
}
F_9 ( & V_2 -> V_14 ) ;
return V_9 ;
}
static int F_10 ( struct V_26 * V_27 , T_1 V_3 ,
unsigned short V_6 , char V_28 ,
T_2 V_5 , int V_29 , union V_30 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_27 ) ;
if ( V_29 != V_31 )
return - 1 ;
return F_1 ( V_2 , V_3 , V_28 == V_32 , V_5 ,
V_6 & V_33 ? 0x10 : 0x00 , & V_7 -> V_34 ) ;
}
static int F_12 ( struct V_26 * V_27 ,
struct V_35 V_36 [] , int V_37 )
{
struct V_1 * V_2 = F_11 ( V_27 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_37 ; ++ V_8 ) {
if ( V_36 [ V_8 ] . V_38 == 2 ) {
if ( V_8 + 1 == V_37 || V_36 [ V_8 ] . V_3 != V_36 [ V_8 + 1 ] . V_3 ||
( V_36 [ V_8 ] . V_6 & V_39 ) ||
! ( V_36 [ V_8 + 1 ] . V_6 & V_39 ) ||
V_36 [ V_8 + 1 ] . V_38 != 1 )
return - 1 ;
if ( F_1 ( V_2 , V_36 [ V_8 ] . V_3 , 1 ,
( V_36 [ V_8 ] . V_40 [ 0 ] << 8 ) | V_36 [ V_8 ] . V_40 [ 1 ] ,
0x01 , & V_36 [ V_8 + 1 ] . V_40 [ 0 ] ) < 0 )
return - 1 ;
++ V_8 ;
} else if ( V_36 [ V_8 ] . V_38 == 3 ) {
if ( V_36 [ V_8 ] . V_6 & V_39 )
return - 1 ;
if ( V_36 [ V_8 ] . V_38 != 3 )
return - 1 ;
if ( F_1 ( V_2 , V_36 [ V_8 ] . V_3 , 0 ,
( V_36 [ V_8 ] . V_40 [ 0 ] << 8 ) | V_36 [ V_8 ] . V_40 [ 1 ] ,
0x01 , & V_36 [ V_8 ] . V_40 [ 2 ] ) < 0 )
return - 1 ;
} else
return - 1 ;
}
return 0 ;
}
static T_3 F_13 ( struct V_26 * V_27 )
{
return V_41 ;
}
int F_14 ( struct V_1 * V_2 )
{
memcpy ( & V_2 -> V_26 , & V_42 ,
sizeof( V_42 ) ) ;
V_2 -> V_26 . V_13 . V_43 = V_2 -> V_13 ;
F_15 ( & V_2 -> V_26 , V_2 ) ;
if ( F_16 ( & V_2 -> V_26 ) < 0 ) {
F_8 ( V_2 -> V_13 ,
L_4 ) ;
return - 1 ;
}
return 0 ;
}
