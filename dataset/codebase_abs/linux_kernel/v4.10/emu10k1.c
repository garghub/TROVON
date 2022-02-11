static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
static int V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
#ifdef F_2
struct V_10 * V_11 = NULL ;
#endif
int V_12 ;
if ( V_5 >= V_13 )
return - V_14 ;
if ( ! V_15 [ V_5 ] ) {
V_5 ++ ;
return - V_16 ;
}
V_12 = F_3 ( & V_2 -> V_5 , V_17 [ V_5 ] , V_18 [ V_5 ] , V_19 ,
0 , & V_7 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_20 [ V_5 ] < 32 )
V_20 [ V_5 ] = 32 ;
else if ( V_20 [ V_5 ] > 1024 )
V_20 [ V_5 ] = 1024 ;
if ( ( V_12 = F_4 ( V_7 , V_2 , V_21 [ V_5 ] , V_22 [ V_5 ] ,
( long ) V_20 [ V_5 ] * 1024 * 1024 ,
V_23 [ V_5 ] , V_24 [ V_5 ] ,
& V_9 ) ) < 0 )
goto error;
V_7 -> V_25 = V_9 ;
V_9 -> V_26 = V_26 [ V_5 ] & 0x1f ;
if ( ( V_12 = F_5 ( V_9 , 0 ) ) < 0 )
goto error;
if ( ( V_12 = F_6 ( V_9 , 1 ) ) < 0 )
goto error;
if ( ( V_12 = F_7 ( V_9 , 2 ) ) < 0 )
goto error;
if ( V_9 -> V_27 -> V_28 ) {
if ( ( V_12 = F_8 ( V_29 , F_9 ( V_2 ) ,
1024 , & V_9 -> V_30 ) ) < 0 )
goto error;
}
if ( ( V_12 = F_10 ( V_9 , 0 , 3 ) ) < 0 )
goto error;
if ( ( V_12 = F_11 ( V_9 , 0 ) ) < 0 )
goto error;
if ( ( V_12 = F_12 ( V_9 , 3 ) ) < 0 )
goto error;
if ( V_9 -> V_27 -> V_28 ) {
if ( ( V_12 = F_13 ( V_9 , 4 ) ) < 0 )
goto error;
}
if ( V_9 -> V_31 ) {
if ( ( V_12 = F_14 ( V_9 ) ) < 0 )
goto error;
} else {
if ( ( V_12 = F_15 ( V_9 ) ) < 0 )
goto error;
}
if ( ( V_12 = F_16 ( V_9 , 0 ) ) < 0 )
goto error;
#ifdef F_2
if ( F_17 ( V_7 , 1 , V_32 ,
sizeof( struct V_33 ) , & V_11 ) < 0 ||
V_11 == NULL ) {
F_18 ( V_9 -> V_7 -> V_5 ,
L_1 ) ;
} else {
struct V_33 * V_34 ;
V_34 = F_19 ( V_11 ) ;
strcpy ( V_11 -> V_35 , L_2 ) ;
V_34 -> V_36 = V_9 ;
V_34 -> V_17 = 1 ;
V_34 -> V_37 = V_37 [ V_5 ] ;
V_34 -> V_38 = V_39 [ V_5 ] ;
}
#endif
F_20 ( V_7 -> V_40 , V_9 -> V_27 -> V_40 ,
sizeof( V_7 -> V_40 ) ) ;
F_20 ( V_7 -> V_41 , V_9 -> V_27 -> V_35 ,
sizeof( V_7 -> V_41 ) ) ;
snprintf ( V_7 -> V_42 , sizeof( V_7 -> V_42 ) ,
L_3 ,
V_7 -> V_41 , V_9 -> V_43 , V_9 -> V_44 , V_9 -> V_45 , V_9 -> V_46 ) ;
if ( ( V_12 = F_21 ( V_7 ) ) < 0 )
goto error;
if ( V_9 -> V_27 -> V_47 )
F_22 ( & V_9 -> V_48 . V_49 , 0 ) ;
F_23 ( V_2 , V_7 ) ;
V_5 ++ ;
return 0 ;
error:
F_24 ( V_7 ) ;
return V_12 ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_24 ( F_26 ( V_2 ) ) ;
}
static int F_27 ( struct V_50 * V_5 )
{
struct V_6 * V_7 = F_28 ( V_5 ) ;
struct V_8 * V_9 = V_7 -> V_25 ;
F_29 ( V_7 , V_51 ) ;
V_9 -> V_52 = 1 ;
F_30 ( & V_9 -> V_48 . V_49 ) ;
F_31 ( V_9 -> V_53 ) ;
F_31 ( V_9 -> V_54 ) ;
F_31 ( V_9 -> V_55 ) ;
F_31 ( V_9 -> V_56 ) ;
F_31 ( V_9 -> V_57 ) ;
F_32 ( V_9 -> V_58 ) ;
F_33 ( V_9 ) ;
F_34 ( V_9 ) ;
if ( V_9 -> V_27 -> V_28 )
F_35 ( V_9 ) ;
F_36 ( V_9 ) ;
return 0 ;
}
static int F_37 ( struct V_50 * V_5 )
{
struct V_6 * V_7 = F_28 ( V_5 ) ;
struct V_8 * V_9 = V_7 -> V_25 ;
F_38 ( V_9 ) ;
F_39 ( V_9 ) ;
F_40 ( V_9 -> V_58 ) ;
F_41 ( V_9 ) ;
if ( V_9 -> V_27 -> V_28 )
F_42 ( V_9 ) ;
V_9 -> V_52 = 0 ;
F_29 ( V_7 , V_59 ) ;
if ( V_9 -> V_27 -> V_47 )
F_22 ( & V_9 -> V_48 . V_49 , 0 ) ;
return 0 ;
}
