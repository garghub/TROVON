static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_5 = F_2 ( V_4 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_2 V_8 , V_9 , V_10 ;
F_3 () ;
if ( F_4 ( V_11 ) != V_12 ) {
F_5 ( & V_4 -> V_13 ,
L_1 ) ;
} else {
V_8 = F_6 ( V_12 ) ;
while ( V_8 -- ) {
V_9 = F_6 ( V_12 ) ;
V_10 = V_9 & 0x7f ;
F_7 ( V_7 , V_14 , V_15 , V_10 ) ;
F_8 ( V_7 , V_5 -> V_16 [ V_10 ] ,
! ( V_9 & 0x80 ) ) ;
F_9 ( V_7 ) ;
}
}
F_10 () ;
return V_17 ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_5 * V_5 ;
struct V_6 * V_6 ;
int V_18 , V_19 , V_1 ;
V_1 = F_12 ( V_4 , 0 ) ;
if ( V_1 <= 0 )
return V_1 < 0 ? V_1 : - V_20 ;
V_5 = F_13 ( & V_4 -> V_13 , sizeof( * V_5 ) , V_21 ) ;
V_6 = F_14 ( & V_4 -> V_13 ) ;
if ( ! V_5 || ! V_6 )
return - V_22 ;
F_15 ( V_4 , V_5 ) ;
memcpy ( V_5 -> V_16 , V_23 ,
sizeof( V_23 ) ) ;
V_5 -> V_7 = V_6 ;
V_6 -> V_24 [ 0 ] = F_16 ( V_25 ) | F_16 ( V_26 ) ;
V_6 -> V_27 = L_2 ;
V_6 -> V_28 = L_3 ;
V_6 -> V_29 = V_5 -> V_16 ;
V_6 -> V_30 = sizeof( unsigned short ) ;
V_6 -> V_31 = F_17 ( V_23 ) ;
V_6 -> V_32 . V_33 = V_34 ;
V_6 -> V_13 . V_35 = & V_4 -> V_13 ;
for ( V_18 = 0 ; V_18 < F_17 ( V_5 -> V_16 ) ; V_18 ++ )
F_18 ( V_5 -> V_16 [ V_18 ] , V_6 -> V_36 ) ;
F_19 ( V_37 , V_6 -> V_36 ) ;
F_20 ( V_6 , V_14 , V_15 ) ;
V_19 = F_21 ( & V_4 -> V_13 , V_1 , F_1 ,
V_38 , L_4 , V_4 ) ;
if ( V_19 ) {
F_22 ( & V_4 -> V_13 , L_5 , V_1 , V_19 ) ;
return V_19 ;
}
return F_23 ( V_5 -> V_7 ) ;
}
