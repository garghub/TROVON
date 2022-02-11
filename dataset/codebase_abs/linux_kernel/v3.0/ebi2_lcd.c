static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 = NULL ;
struct V_6 * V_7 = NULL ;
int V_8 , V_9 ;
if ( V_2 -> V_10 == 0 ) {
for ( V_9 = 0 ; V_9 < V_2 -> V_11 ; V_9 ++ ) {
if ( ! strncmp ( V_2 -> V_12 [ V_9 ] . V_13 , L_1 , 4 ) ) {
V_14 = F_2 ( V_2 -> V_12 [ V_9 ] . V_15 ,
V_2 -> V_12 [ V_9 ] . V_16 -
V_2 -> V_12 [ V_9 ] . V_15 + 1 ) ;
if ( ! V_14 ) {
F_3 ( V_17
L_2 ) ;
return - V_18 ;
}
V_19 = ( void * ) ( V_14 + 0x20 ) ;
V_20 = ( void * ) ( V_14 + 0x24 ) ;
} else if ( ! strncmp ( V_2 -> V_12 [ V_9 ] . V_13 ,
L_3 , 5 ) ) {
V_21 = F_2 ( V_2 -> V_12 [ V_9 ] . V_15 ,
V_2 -> V_12 [ V_9 ] . V_16 -
V_2 -> V_12 [ V_9 ] . V_15 + 1 ) ;
if ( ! V_21 ) {
F_3 ( V_17
L_4 ) ;
return - V_18 ;
}
} else if ( ! strncmp ( V_2 -> V_12 [ V_9 ] . V_13 ,
L_5 , 5 ) ) {
V_22 = F_2 ( V_2 -> V_12 [ V_9 ] . V_15 ,
V_2 -> V_12 [ V_9 ] . V_16 -
V_2 -> V_12 [ V_9 ] . V_15 + 1 ) ;
if ( ! V_22 ) {
F_3 ( V_17
L_6 ) ;
return - V_18 ;
}
}
}
V_23 = 1 ;
return 0 ;
}
if ( ! V_23 )
return - V_24 ;
V_4 = F_4 ( V_2 ) ;
if ( ! V_4 )
return - V_25 ;
if ( V_4 -> V_26 != V_27 )
return - V_28 ;
if ( V_29 >= V_30 )
return - V_18 ;
if ( V_14 == NULL )
return - V_18 ;
V_5 = F_5 ( L_7 , V_2 -> V_10 ) ;
if ( ! V_5 )
return - V_18 ;
V_4 -> V_2 = V_5 ;
V_4 -> V_31 = V_32 ;
if ( F_6
( V_5 , V_2 -> V_33 . V_34 ,
sizeof( struct V_6 ) ) ) {
F_3 ( V_17 L_8 ) ;
F_7 ( V_5 ) ;
return - V_18 ;
}
V_7 = V_5 -> V_33 . V_34 ;
V_7 -> V_35 = V_36 ;
V_7 -> V_37 = V_38 ;
V_7 -> V_39 = V_2 ;
V_4 -> V_40 = V_7 -> V_40 ;
if ( V_4 -> V_40 . V_41 == 24 )
V_4 -> V_42 = V_43 ;
else
V_4 -> V_42 = V_44 ;
if ( V_4 -> V_40 . V_45 == V_46 ) {
F_8 ( V_14 ,
( F_9 ( V_14 ) & ( ~ ( V_47 ) ) ) |
V_48 ) ;
F_8 ( V_19 , V_4 -> V_40 . V_49 ) ;
if ( V_4 -> V_40 . V_41 == 18 )
F_8 ( V_20 , 0x01000000 ) ;
else
F_8 ( V_20 , 0x0 ) ;
} else {
#ifdef F_10
F_8 ( V_14 , ( F_9 ( V_14 ) & ( ~ ( V_50 ) ) )
| V_51 ) ;
#endif
}
if ( V_4 -> V_40 . V_45 == V_46 ) {
V_4 -> V_52 = V_21 ;
V_4 -> V_53 =
( void * ) ( ( V_54 ) V_4 -> V_52 + V_55 ) ;
V_4 -> V_56 =
( void * ) ( V_57 + V_55 ) ;
} else {
V_4 -> V_52 = V_21 ;
V_4 -> V_53 =
( void * ) ( ( V_54 ) V_4 -> V_52 + V_58 ) ;
V_4 -> V_56 =
( void * ) ( V_59 + V_58 ) ;
}
F_11 ( V_5 , V_4 ) ;
V_8 = F_12 ( V_5 ) ;
if ( V_8 ) {
goto V_60;
}
V_61 [ V_29 ++ ] = V_2 ;
return 0 ;
V_60:
F_7 ( V_5 ) ;
return V_8 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) F_4 ( V_2 ) ;
if ( ! V_4 )
return 0 ;
if ( V_4 -> V_26 != V_27 )
return 0 ;
F_14 ( V_4 -> V_52 ) ;
return 0 ;
}
static int F_15 ( void )
{
return F_16 ( & V_62 ) ;
}
static int T_1 F_17 ( void )
{
return F_15 () ;
}
