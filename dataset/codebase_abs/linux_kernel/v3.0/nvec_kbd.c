static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
int V_5 , V_6 ;
unsigned char * V_7 = ( unsigned char * ) V_4 ;
if ( V_3 == V_8 ) {
T_1 V_9 = ( V_7 [ 0 ] & ( 3 << 5 ) ) >> 5 ;
if( V_9 == V_10 )
return V_11 ;
if( V_9 == V_12 )
V_7 ++ ;
V_5 = V_7 [ 1 ] & 0x7f ;
V_6 = V_7 [ 1 ] & 0x80 ;
F_2 ( V_13 . V_14 , V_15 [ V_9 ] [ V_5 ] , ! V_6 ) ;
F_3 ( V_13 . V_14 ) ;
return V_11 ;
}
return V_16 ;
}
static int F_4 ( struct V_17 * V_18 , unsigned int type ,
unsigned int V_5 , int V_19 )
{
unsigned char V_20 [] = V_21 ;
struct V_22 * V_23 = V_13 . V_23 ;
if( type == V_24 )
return 0 ;
if( type != V_25 )
return - 1 ;
if( V_5 != V_26 )
return - 1 ;
V_20 [ 2 ] = ! ! V_19 ;
F_5 ( V_23 , V_20 , sizeof( V_20 ) ) ;
return 0 ;
}
int T_2 F_6 ( struct V_22 * V_23 )
{
int V_27 , V_28 , V_29 ;
struct V_17 * V_30 ;
V_28 = 0 ;
for( V_27 = 0 ; V_27 < F_7 ( V_31 ) ; ++ V_27 )
V_32 [ V_28 ++ ] = V_31 [ V_27 ] ;
for( V_27 = 0 ; V_27 < F_7 ( V_33 ) ; ++ V_27 )
V_32 [ V_28 ++ ] = V_33 [ V_27 ] ;
V_30 = F_8 () ;
V_30 -> V_34 = L_1 ;
V_30 -> V_35 = L_2 ;
V_30 -> V_36 [ 0 ] = F_9 ( V_37 ) | F_9 ( V_24 ) | F_9 ( V_25 ) ;
V_30 -> V_38 [ 0 ] = F_9 ( V_26 ) ;
V_30 -> V_39 = F_4 ;
V_30 -> V_40 = V_32 ;
V_30 -> V_41 = sizeof( unsigned char ) ;
V_30 -> V_42 = F_7 ( V_32 ) ;
for( V_27 = 0 ; V_27 < F_7 ( V_32 ) ; ++ V_27 )
F_10 ( V_32 [ V_27 ] , V_30 -> V_43 ) ;
F_11 ( 0 , V_30 -> V_43 ) ;
V_29 = F_12 ( V_30 ) ;
if( V_29 )
goto V_44;
V_13 . V_14 = V_30 ;
V_13 . V_45 . V_46 = F_1 ;
V_13 . V_23 = V_23 ;
F_13 ( V_23 , & V_13 . V_45 , 0 ) ;
F_5 ( V_23 , L_3 , 2 ) ;
F_5 ( V_23 , L_4 , 4 ) ;
F_5 ( V_23 , L_5 , 3 ) ;
F_5 ( V_23 , L_6 , 4 ) ;
F_14 ( 1000 ) ;
return 0 ;
V_44:
F_15 ( V_30 ) ;
return V_29 ;
}
