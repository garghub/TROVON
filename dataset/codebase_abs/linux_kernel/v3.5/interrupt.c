T_1 F_1 ( int V_1 , void * V_2 )
{
T_2 V_3 ;
int V_4 ;
int V_5 = ( int ) ( unsigned long ) V_2 ;
if ( ! F_2 ( V_5 ) ) {
F_3 ( L_1 , V_5 ) ;
return V_6 ;
}
F_3 ( L_2 ,
V_7 [ V_5 ] -> V_8 ) ;
while ( ! F_4 ( V_5 , & V_3 ) ) {
if ( V_7 [ V_5 ] -> V_9 )
memcpy ( & ( V_7 [ V_5 ] -> V_10 ) ,
& V_3 , sizeof( T_2 ) ) ;
V_4 = ( unsigned int ) V_3 . V_11 ;
if ( F_5 ( V_3 , 0 , 0 , V_12 ) ) {
F_3 ( L_3 ,
V_7 [ V_5 ] -> V_8 ,
V_3 . V_13 ) ;
break;
}
if ( F_6 ( V_3 , V_14 , 1 , V_15 ) )
{
F_3 ( L_4 ,
V_7 [ V_5 ] -> V_8 ,
V_3 . V_16 . V_17 . V_18 ,
V_3 . V_16 . V_17 . V_19 ) ;
F_7 ( V_5 , & V_3 ) ;
continue;
}
if ( F_6 ( V_3 , V_14 , 1 , V_20 ) ) {
F_3 ( L_5 ,
V_7 [ V_5 ] -> V_8 ,
V_3 . V_11 ) ;
V_7 [ V_5 ] -> V_4 [ V_3 . V_11 - 1 ] . V_21 ++ ;
continue;
}
if ( F_6 ( V_3 , V_22 , 1 , V_23 ) )
{
unsigned int V_24 ;
T_3 V_25 ;
F_3 ( L_6 ,
V_7 [ V_5 ] -> V_8 ,
V_3 . V_11 ,
V_3 . V_13 ,
V_3 . V_16 . V_26 [ 2 ] ) ;
memcpy ( & V_24 , V_3 . V_16 . V_26 , sizeof( int ) ) ;
if ( V_24 >= 0x8000 && V_24 <= 0xFFFF )
{
F_3 ( L_7 ,
V_7 [ V_5 ] -> V_8 ) ;
F_8 ( V_5 , V_27 ,
( unsigned long ) V_3 . V_11 - 1 , NULL ) ;
}
else if ( V_24 >= 0x0000 && V_24 <= 0x7FFF )
{
int V_28 ;
F_3 ( L_8 ,
V_7 [ V_5 ] -> V_8 ) ;
V_28 = F_9 ( V_25 . V_29 , & ( V_3 . V_16 . V_26 [ 4 ] ) ,
sizeof( V_25 . V_29 ) ) ;
if ( V_28 >= sizeof( V_25 . V_29 ) )
continue;
V_28 = F_9 ( V_25 . V_30 ,
V_7 [ V_5 ] -> V_4 [ V_3 . V_11 - 1 ] . V_31 ,
sizeof( V_25 . V_30 ) ) ;
if ( V_28 >= sizeof( V_25 . V_30 ) )
continue;
V_25 . V_32 = 7 ;
V_25 . V_33 = 0 ;
V_25 . V_34 = 0 ;
V_25 . V_35 = 0 ;
F_8 ( V_5 , V_36 , ( unsigned long ) V_3 . V_11 - 1 , ( char * ) & V_25 ) ;
F_8 ( V_5 , V_27 , ( unsigned long ) V_3 . V_11 - 1 , NULL ) ;
}
continue;
}
if ( F_6 ( V_3 , V_22 , 1 , V_37 ) )
{
F_3 ( L_9 ,
V_7 [ V_5 ] -> V_8 ,
V_3 . V_11 ,
V_3 . V_13 ,
V_3 . V_16 . V_26 [ 2 ] ) ;
F_8 ( V_5 , V_38 , ( unsigned long ) V_3 . V_11 - 1 , NULL ) ;
F_8 ( V_5 , V_39 , ( unsigned long ) V_3 . V_11 - 1 , NULL ) ;
continue;
}
if ( F_5 ( V_3 , 5 , 0 , V_40 ) ) {
F_3 ( L_10 ,
V_7 [ V_5 ] -> V_8 ) ;
V_7 [ V_5 ] -> V_41 = 1 ;
F_10 ( V_5 , V_42 , V_43 , V_44 , V_45 , 1 , 0 , NULL ) ;
F_10 ( V_5 , V_42 , V_43 , V_44 , V_45 , 2 , 0 , NULL ) ;
F_11 ( & V_7 [ V_5 ] -> V_46 ) ;
V_7 [ V_5 ] -> V_46 . V_47 = V_48 ;
V_7 [ V_5 ] -> V_46 . V_49 = V_5 ;
V_7 [ V_5 ] -> V_46 . V_50 = V_51 + V_52 ;
F_12 ( & V_7 [ V_5 ] -> V_46 ) ;
continue;
}
if ( F_5 ( V_3 , 2 , 0 , V_53 ) ) {
F_3 ( L_11 ,
V_7 [ V_5 ] -> V_8 ,
V_3 . V_13 ) ;
continue;
}
if ( F_6 ( V_3 , V_54 , 0 , V_55 ) ) {
F_9 ( V_7 [ V_5 ] -> V_4 [ V_3 . V_11 - 1 ] . V_31 ,
V_3 . V_16 . V_26 ,
sizeof( V_3 . V_16 . V_26 ) ) ;
continue;
}
if ( F_6 ( V_3 , V_22 , 2 , V_56 ) ) {
unsigned int V_57 , V_58 ;
V_57 = ( unsigned int ) V_3 . V_16 . V_26 [ 0 ] ;
V_58 = ( unsigned int ) V_3 . V_16 . V_26 [ 1 ] ;
V_7 [ V_5 ] -> V_59 = ( V_58 >> 8 ) | V_57 ;
F_3 ( L_12 ,
V_7 [ V_5 ] -> V_8 ,
V_7 [ V_5 ] -> V_59 ) ;
continue;
}
if ( F_6 ( V_3 , V_54 , 0 , V_60 ) ) {
if ( V_3 . V_16 . V_26 [ 0 ] != V_61 ) {
unsigned int V_62 = V_61 ;
F_3 ( L_13 ,
V_7 [ V_5 ] -> V_8 ,
V_3 . V_16 . V_26 [ 0 ] ) ;
F_10 ( V_5 , V_42 , V_43 ,
V_44 ,
V_63 ,
( unsigned char ) V_4 + 1 ,
1 , & V_62 ) ;
}
continue;
}
F_3 ( L_14 ,
V_7 [ V_5 ] -> V_8 ,
V_3 . type , V_3 . V_64 , V_3 . V_65 ,
V_3 . V_11 ) ;
}
F_3 ( L_15 ,
V_7 [ V_5 ] -> V_8 ) ;
return V_66 ;
}
