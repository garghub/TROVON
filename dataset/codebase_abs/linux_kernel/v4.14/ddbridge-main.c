static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0 , V_3 ) ;
F_2 ( V_2 , 0 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
if ( V_2 -> V_5 == 2 )
F_4 ( V_2 -> V_6 -> V_7 + 1 , V_2 ) ;
F_4 ( V_2 -> V_6 -> V_7 , V_2 ) ;
#ifdef F_5
if ( V_2 -> V_5 )
F_6 ( V_2 -> V_6 ) ;
#endif
}
static void F_7 ( struct V_8 * V_6 )
{
struct V_1 * V_2 = (struct V_1 * ) F_8 ( V_6 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
F_3 ( V_2 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
F_15 ( V_6 , NULL ) ;
F_16 ( V_6 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_9 )
{
int V_10 ;
if ( V_5 && F_18 () ) {
V_10 = F_19 ( V_2 -> V_6 , 1 , V_9 , V_11 ) ;
if ( V_10 >= 1 ) {
V_2 -> V_5 = V_10 ;
F_20 ( V_2 -> V_2 , L_1 ,
V_2 -> V_5 ) ;
} else
F_20 ( V_2 -> V_2 , L_2 ) ;
}
}
static int F_21 ( struct V_1 * V_2 )
{
int V_10 ;
int V_12 = V_13 ;
F_2 ( V_2 , 0x00000000 , V_3 ) ;
F_2 ( V_2 , 0x00000000 , V_4 ) ;
F_2 ( V_2 , 0x00000000 , V_14 ) ;
F_2 ( V_2 , 0x00000000 , V_15 ) ;
F_2 ( V_2 , 0x00000000 , V_16 ) ;
F_2 ( V_2 , 0x00000000 , V_17 ) ;
F_2 ( V_2 , 0x00000000 , V_18 ) ;
F_2 ( V_2 , 0x00000000 , V_19 ) ;
#ifdef F_5
F_17 ( V_2 , 2 ) ;
if ( V_2 -> V_5 )
V_12 = 0 ;
if ( V_2 -> V_5 == 2 ) {
V_10 = F_22 ( V_2 -> V_6 -> V_7 , V_20 ,
V_12 , L_3 , ( void * ) V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_22 ( V_2 -> V_6 -> V_7 + 1 , V_21 ,
V_12 , L_3 , ( void * ) V_2 ) ;
if ( V_10 < 0 ) {
F_4 ( V_2 -> V_6 -> V_7 , V_2 ) ;
return V_10 ;
}
} else
#endif
{
V_10 = F_22 ( V_2 -> V_6 -> V_7 , V_22 ,
V_12 , L_3 , ( void * ) V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_2 -> V_5 == 2 ) {
F_2 ( V_2 , 0x0fffff00 , V_3 ) ;
F_2 ( V_2 , 0x0000000f , V_4 ) ;
} else {
F_2 ( V_2 , 0x0fffff0f , V_3 ) ;
F_2 ( V_2 , 0x00000000 , V_4 ) ;
}
return V_10 ;
}
static int F_23 ( struct V_8 * V_6 ,
const struct V_23 * V_24 )
{
struct V_1 * V_2 ;
int V_10 = 0 ;
if ( F_24 ( V_6 ) < 0 )
return - V_25 ;
F_25 ( V_6 ) ;
if ( F_26 ( V_6 , F_27 ( 64 ) ) )
if ( F_26 ( V_6 , F_27 ( 32 ) ) )
return - V_25 ;
V_2 = F_28 ( sizeof( struct V_1 ) ) ;
if ( V_2 == NULL )
return - V_26 ;
F_29 ( & V_2 -> V_27 ) ;
V_2 -> V_28 = 1 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_2 = & V_6 -> V_2 ;
F_15 ( V_6 , V_2 ) ;
V_2 -> V_29 [ 0 ] . V_30 . V_31 = V_24 -> V_31 ;
V_2 -> V_29 [ 0 ] . V_30 . V_32 = V_24 -> V_32 ;
V_2 -> V_29 [ 0 ] . V_30 . V_33 = V_24 -> V_33 ;
V_2 -> V_29 [ 0 ] . V_30 . V_34 = V_6 -> V_35 ;
V_2 -> V_29 [ 0 ] . V_2 = V_2 ;
V_2 -> V_29 [ 0 ] . V_36 = F_30 ( V_24 -> V_31 , V_24 -> V_32 ,
V_24 -> V_33 , V_6 -> V_35 ) ;
F_20 ( & V_6 -> V_2 , L_4 , V_2 -> V_29 [ 0 ] . V_36 -> V_37 ) ;
V_2 -> V_38 = F_31 ( V_2 -> V_6 , 0 ) ;
V_2 -> V_39 = F_32 ( F_33 ( V_2 -> V_6 , 0 ) ,
F_31 ( V_2 -> V_6 , 0 ) ) ;
if ( ! V_2 -> V_39 ) {
F_34 ( & V_6 -> V_2 , L_5 ) ;
V_10 = - V_26 ;
goto V_40;
}
if ( F_35 ( V_2 , 0 ) == 0xffffffff ) {
F_34 ( & V_6 -> V_2 , L_6 ) ;
V_10 = - V_25 ;
goto V_40;
}
V_2 -> V_29 [ 0 ] . V_30 . V_41 = F_35 ( V_2 , 0 ) ;
V_2 -> V_29 [ 0 ] . V_30 . V_42 = F_35 ( V_2 , 4 ) ;
F_20 ( & V_6 -> V_2 , L_7 ,
V_2 -> V_29 [ 0 ] . V_30 . V_41 , V_2 -> V_29 [ 0 ] . V_30 . V_42 ) ;
F_2 ( V_2 , 0 , V_43 ) ;
F_2 ( V_2 , 0 , V_44 ) ;
V_10 = F_21 ( V_2 ) ;
if ( V_10 < 0 )
goto V_45;
if ( F_36 ( V_2 ) == 0 )
return 0 ;
F_3 ( V_2 ) ;
V_45:
F_34 ( & V_6 -> V_2 , L_8 ) ;
if ( V_2 -> V_5 )
F_6 ( V_2 -> V_6 ) ;
V_40:
F_34 ( & V_6 -> V_2 , L_9 ) ;
F_14 ( V_2 ) ;
F_15 ( V_6 , NULL ) ;
F_16 ( V_6 ) ;
return - 1 ;
}
static T_1 int F_37 ( void )
{
int V_10 = - 1 ;
F_38 ( L_10
V_46
L_11 ) ;
if ( F_39 () < 0 )
return - 1 ;
V_47 = F_40 ( L_3 ) ;
if ( V_47 == NULL )
goto V_48;
V_10 = F_41 ( & V_49 ) ;
if ( V_10 < 0 )
goto V_50;
return V_10 ;
V_50:
F_42 ( V_47 ) ;
V_48:
F_43 () ;
return V_10 ;
}
static T_2 void F_44 ( void )
{
F_45 ( & V_49 ) ;
F_42 ( V_47 ) ;
F_43 () ;
}
