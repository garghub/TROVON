static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_3 == - V_7 )
return;
V_5 -> V_8 = V_3 ;
F_2 ( & V_5 -> V_9 ) ;
}
static int F_3 ( char V_10 [ V_11 ] ,
char V_12 [ V_13 ] ,
char V_14 [ V_13 ] )
{
int V_8 = 0 ;
struct V_15 * V_2 = NULL ;
F_4 ( V_5 ) ;
struct V_16 V_17 , V_18 ;
struct V_19 * V_20 = F_5 ( L_1 , 0 ,
0 ) ;
if ( F_6 ( V_20 ) ) {
V_8 = F_7 ( V_20 ) ;
V_20 = NULL ;
goto V_21;
}
F_8 ( V_20 , V_22 ) ;
V_2 = F_9 ( V_20 , V_23 ) ;
if ( ! V_2 ) {
V_8 = - V_24 ;
goto V_21;
}
F_10 ( V_2 ,
V_25 | V_26 ,
F_1 , & V_5 ) ;
V_8 = F_11 ( V_20 , V_10 ,
V_11 ) ;
if ( V_8 < 0 )
goto V_21;
F_12 ( & V_17 , V_12 , V_13 ) ;
F_12 ( & V_18 , V_14 , V_13 ) ;
F_13 ( V_2 , & V_17 , & V_18 ,
V_13 , NULL ) ;
V_8 = F_14 ( V_2 ) ;
if ( V_8 == - V_7 || V_8 == - V_27 ) {
F_15 ( V_2 -> V_28 . V_6 != & V_5 ) ;
F_16 ( & V_5 . V_9 ) ;
V_8 = V_5 . V_8 ;
}
V_21:
if ( V_2 )
F_17 ( V_2 ) ;
if ( V_20 )
F_18 ( V_20 ) ;
return V_8 ;
}
int F_19 ( struct V_29 * V_29 )
{
struct V_30 * V_31 = F_20 ( V_29 ) ;
struct V_32 * V_33 = & V_31 -> V_34 ;
char V_35 [ V_36 +
( V_37 * 2 ) + 1 ] ;
struct V_38 * V_39 = NULL ;
struct V_32 * V_40 ;
struct V_41 V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 = F_21 ( V_29 -> V_47 ) ;
int V_8 = F_22 ( V_29 , V_48 ,
V_49 ,
& V_42 , sizeof( V_42 ) ) ;
if ( V_8 != sizeof( V_42 ) ) {
if ( V_8 > 0 )
V_8 = - V_50 ;
goto V_21;
}
V_8 = 0 ;
V_31 -> V_51 = V_42 . V_52 ;
if ( F_23 ( V_29 -> V_53 ) )
V_33 -> V_54 = V_42 . V_55 ;
else if ( F_24 ( V_29 -> V_53 ) || F_25 ( V_29 -> V_53 ) )
V_33 -> V_54 = V_42 . V_56 ;
else {
F_26 ( V_57 L_2 ) ;
F_27 () ;
}
V_33 -> V_58 = F_28 ( V_33 -> V_54 ) ;
F_15 ( ! V_33 -> V_58 ) ;
if ( F_29 ( V_46 ) ) {
memset ( V_33 -> V_59 , 0x42 , V_13 ) ;
goto V_21;
}
memcpy ( V_35 , V_60 ,
V_36 ) ;
sprintf ( V_35 + V_36 ,
L_3 , V_37 ,
V_42 . V_61 ) ;
V_35 [ V_36 +
( 2 * V_37 ) ] = '\0' ;
V_39 = F_30 ( & V_62 , V_35 , NULL ) ;
if ( F_6 ( V_39 ) ) {
V_8 = F_7 ( V_39 ) ;
V_39 = NULL ;
goto V_21;
}
F_15 ( V_39 -> type != & V_62 ) ;
V_44 = ( (struct V_43 * ) V_39 -> V_63 . V_6 ) ;
if ( V_44 -> V_64 != sizeof( struct V_32 ) ) {
V_8 = - V_50 ;
goto V_21;
}
V_40 = (struct V_32 * ) V_44 -> V_6 ;
F_31 ( V_11 !=
V_65 ) ;
F_15 ( V_40 -> V_58 != V_13 ) ;
V_8 = F_3 ( V_42 . V_66 , V_40 -> V_59 , V_33 -> V_59 ) ;
V_21:
if ( V_39 )
F_32 ( V_39 ) ;
if ( V_8 < 0 )
V_33 -> V_54 = V_67 ;
return V_8 ;
}
int F_33 ( struct V_29 * V_29 )
{
struct V_30 * V_31 = F_20 ( V_29 ) ;
struct V_32 * V_33 = & V_31 -> V_34 ;
return ( V_33 -> V_54 != V_67 ) ;
}
