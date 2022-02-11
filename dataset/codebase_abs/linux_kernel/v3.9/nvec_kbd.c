static void F_1 ( void )
{
char V_1 [] = { V_2 , V_3 , 0 } ;
V_4 . V_5 = ! V_4 . V_5 ;
if ( V_4 . V_5 )
V_1 [ 2 ] = F_2 ( 0 ) | F_2 ( 1 ) | F_2 ( 2 ) ;
F_3 ( V_4 . V_6 , V_1 , sizeof( V_1 ) ) ;
}
static int F_4 ( struct V_7 * V_8 ,
unsigned long V_9 , void * V_10 )
{
int V_11 , V_12 ;
unsigned char * V_13 = ( unsigned char * ) V_10 ;
if ( V_9 == V_14 ) {
int V_15 = ( V_13 [ 0 ] & ( 3 << 5 ) ) >> 5 ;
if ( V_15 == V_16 )
return V_17 ;
if ( V_15 == V_18 )
V_13 ++ ;
V_11 = V_13 [ 1 ] & 0x7f ;
V_12 = V_13 [ 1 ] & 0x80 ;
if ( V_19 [ V_15 ] [ V_11 ] == V_20 && V_12 )
F_1 () ;
F_5 ( V_4 . V_21 , V_19 [ V_15 ] [ V_11 ] ,
! V_12 ) ;
F_6 ( V_4 . V_21 ) ;
return V_17 ;
}
return V_22 ;
}
static int F_7 ( struct V_23 * V_24 , unsigned int type ,
unsigned int V_11 , int V_25 )
{
struct V_26 * V_6 = V_4 . V_6 ;
char V_1 [] = { V_2 , V_3 , 0 } ;
if ( type == V_27 )
return 0 ;
if ( type != V_28 )
return - 1 ;
if ( V_11 != V_29 )
return - 1 ;
V_1 [ 2 ] = ! ! V_25 ;
F_3 ( V_6 , V_1 , sizeof( V_1 ) ) ;
return 0 ;
}
static int F_8 ( struct V_30 * V_31 )
{
struct V_26 * V_6 = F_9 ( V_31 -> V_24 . V_32 ) ;
int V_33 , V_34 , V_35 ;
struct V_23 * V_36 ;
char V_37 [] = { V_2 , V_3 , 0 } ,
V_38 [] = { V_2 , V_39 } ,
V_40 [] = { V_2 , V_41 , true , true } ,
V_42 [] = { V_2 , V_43 ,
true } ;
V_34 = 0 ;
for ( V_33 = 0 ; V_33 < F_10 ( V_44 ) ; ++ V_33 )
V_45 [ V_34 ++ ] = V_44 [ V_33 ] ;
for ( V_33 = 0 ; V_33 < F_10 ( V_46 ) ; ++ V_33 )
V_45 [ V_34 ++ ] = V_46 [ V_33 ] ;
V_36 = F_11 () ;
V_36 -> V_47 = L_1 ;
V_36 -> V_48 = L_2 ;
V_36 -> V_49 [ 0 ] = F_12 ( V_50 ) | F_12 ( V_27 ) | F_12 ( V_28 ) ;
V_36 -> V_51 [ 0 ] = F_12 ( V_29 ) ;
V_36 -> V_52 = F_7 ;
V_36 -> V_53 = V_45 ;
V_36 -> V_54 = sizeof( unsigned char ) ;
V_36 -> V_55 = F_10 ( V_45 ) ;
for ( V_33 = 0 ; V_33 < F_10 ( V_45 ) ; ++ V_33 )
F_13 ( V_45 [ V_33 ] , V_36 -> V_56 ) ;
F_14 ( 0 , V_36 -> V_56 ) ;
V_35 = F_15 ( V_36 ) ;
if ( V_35 )
goto V_57;
V_4 . V_21 = V_36 ;
V_4 . V_58 . V_59 = F_4 ;
V_4 . V_6 = V_6 ;
F_16 ( V_6 , & V_4 . V_58 , 0 ) ;
F_3 ( V_6 , V_38 , 2 ) ;
F_3 ( V_6 , V_40 , 4 ) ;
F_3 ( V_6 , V_42 , 3 ) ;
F_3 ( V_6 , V_37 , sizeof( V_37 ) ) ;
return 0 ;
V_57:
F_17 ( V_36 ) ;
return V_35 ;
}
static int F_18 ( struct V_30 * V_31 )
{
F_19 ( V_4 . V_21 ) ;
F_17 ( V_4 . V_21 ) ;
return 0 ;
}
