static void F_1 ( void )
{
V_1 . V_2 = ! V_1 . V_2 ;
if ( V_1 . V_2 )
F_2 ( V_1 . V_3 , V_4 , sizeof( V_4 ) ) ;
else
F_2 ( V_1 . V_3 , V_5 , sizeof( V_5 ) ) ;
}
static int F_3 ( struct V_6 * V_7 ,
unsigned long V_8 , void * V_9 )
{
int V_10 , V_11 ;
unsigned char * V_12 = ( unsigned char * ) V_9 ;
if ( V_8 == V_13 ) {
int V_14 = ( V_12 [ 0 ] & ( 3 << 5 ) ) >> 5 ;
if ( V_14 == V_15 )
return V_16 ;
if ( V_14 == V_17 )
V_12 ++ ;
V_10 = V_12 [ 1 ] & 0x7f ;
V_11 = V_12 [ 1 ] & 0x80 ;
if ( V_18 [ V_14 ] [ V_10 ] == V_19 && V_11 )
F_1 () ;
F_4 ( V_1 . V_20 , V_18 [ V_14 ] [ V_10 ] ,
! V_11 ) ;
F_5 ( V_1 . V_20 ) ;
return V_16 ;
}
return V_21 ;
}
static int F_6 ( struct V_22 * V_23 , unsigned int type ,
unsigned int V_10 , int V_24 )
{
unsigned char V_25 [] = V_26 ;
struct V_27 * V_3 = V_1 . V_3 ;
if ( type == V_28 )
return 0 ;
if ( type != V_29 )
return - 1 ;
if ( V_10 != V_30 )
return - 1 ;
V_25 [ 2 ] = ! ! V_24 ;
F_2 ( V_3 , V_25 , sizeof( V_25 ) ) ;
return 0 ;
}
static int F_7 ( struct V_31 * V_32 )
{
struct V_27 * V_3 = F_8 ( V_32 -> V_23 . V_33 ) ;
int V_34 , V_35 , V_36 ;
struct V_22 * V_37 ;
V_35 = 0 ;
for ( V_34 = 0 ; V_34 < F_9 ( V_38 ) ; ++ V_34 )
V_39 [ V_35 ++ ] = V_38 [ V_34 ] ;
for ( V_34 = 0 ; V_34 < F_9 ( V_40 ) ; ++ V_34 )
V_39 [ V_35 ++ ] = V_40 [ V_34 ] ;
V_37 = F_10 () ;
V_37 -> V_41 = L_1 ;
V_37 -> V_42 = L_2 ;
V_37 -> V_43 [ 0 ] = F_11 ( V_44 ) | F_11 ( V_28 ) | F_11 ( V_29 ) ;
V_37 -> V_45 [ 0 ] = F_11 ( V_30 ) ;
V_37 -> V_46 = F_6 ;
V_37 -> V_47 = V_39 ;
V_37 -> V_48 = sizeof( unsigned char ) ;
V_37 -> V_49 = F_9 ( V_39 ) ;
for ( V_34 = 0 ; V_34 < F_9 ( V_39 ) ; ++ V_34 )
F_12 ( V_39 [ V_34 ] , V_37 -> V_50 ) ;
F_13 ( 0 , V_37 -> V_50 ) ;
V_36 = F_14 ( V_37 ) ;
if ( V_36 )
goto V_51;
V_1 . V_20 = V_37 ;
V_1 . V_52 . V_53 = F_3 ;
V_1 . V_3 = V_3 ;
F_15 ( V_3 , & V_1 . V_52 , 0 ) ;
F_2 ( V_3 , L_3 , 2 ) ;
F_2 ( V_3 , L_4 , 4 ) ;
F_2 ( V_3 , L_5 , 3 ) ;
F_2 ( V_3 , L_6 , 4 ) ;
F_16 ( 1000 ) ;
F_2 ( V_3 , V_5 , sizeof( V_5 ) ) ;
return 0 ;
V_51:
F_17 ( V_37 ) ;
return V_36 ;
}
static int F_18 ( struct V_31 * V_32 )
{
F_19 ( V_1 . V_20 ) ;
F_17 ( V_1 . V_20 ) ;
return 0 ;
}
