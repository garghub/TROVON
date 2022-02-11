T_1 F_1 ( const unsigned int V_1 )
{
T_1 V_2 ;
if ( V_3 )
F_2 ( V_3 ) ;
V_2 = F_3 ( V_4 + V_5 + V_1 ) ;
if ( V_3 )
F_4 ( V_3 ) ;
return V_2 ;
}
static int F_5 ( struct V_6 * V_7 )
{
const struct V_8 * V_9 ;
V_9 = F_6 ( V_10 , & V_7 -> V_11 ) ;
if ( ! V_9 )
return - V_12 ;
V_3 = F_7 ( & V_7 -> V_11 , NULL ) ;
if ( F_8 ( V_3 ) ) {
F_9 ( & V_7 -> V_11 , L_1 ) ;
return F_10 ( V_3 ) ;
}
F_11 ( V_7 , NULL ) ;
if ( F_12 ( & V_7 -> V_11 , V_13 -> V_14 ,
F_1 ) )
return - V_12 ;
F_13 ( & V_7 -> V_11 , L_2 ) ;
return 0 ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_15 ) ;
}
static void T_2 F_16 ( void )
{
T_1 V_16 [ 12 ] ;
V_16 [ 0 ] = V_17 . V_18 ;
V_16 [ 1 ] = F_17 () ;
V_16 [ 2 ] = F_18 () ;
V_16 [ 3 ] = V_17 . V_19 << 16 ;
V_16 [ 3 ] |= V_17 . V_20 ;
V_16 [ 4 ] = V_17 . V_21 << 16 ;
V_16 [ 4 ] |= V_17 . V_22 ;
V_16 [ 5 ] = F_1 ( V_23 ) ;
V_16 [ 6 ] = F_1 ( V_24 ) ;
V_16 [ 7 ] = F_1 ( V_25 ) ;
V_16 [ 8 ] = F_1 ( V_26 ) ;
V_16 [ 9 ] = F_1 ( V_27 ) ;
V_16 [ 10 ] = F_1 ( V_28 ) ;
V_16 [ 11 ] = F_1 ( V_29 ) ;
F_19 ( V_16 , sizeof( V_16 ) ) ;
}
static void T_2 F_20 ( void )
{
switch ( F_21 () ) {
case V_30 :
V_13 = & V_31 ;
break;
case V_32 :
V_13 = & V_33 ;
break;
case V_34 :
case V_35 :
V_13 = & V_36 ;
break;
default:
return;
}
V_4 = F_22 ( V_37 , V_38 ) ;
}
bool T_2 F_23 ( int V_39 )
{
T_1 V_1 = V_13 -> V_39 + V_39 * 4 ;
return F_1 ( V_1 ) & 1 ;
}
void T_2 F_24 ( void )
{
struct V_40 * V_41 ;
const struct V_8 * V_42 ;
V_41 = F_25 ( NULL , V_10 ,
& V_42 ) ;
if ( V_41 ) {
V_4 = F_26 ( V_41 , 0 ) ;
V_13 = (struct V_43 * ) V_42 -> V_44 ;
} else
F_20 () ;
if ( ! V_4 ) {
F_27 ( L_3 ,
F_21 () ) ;
return;
}
F_28 () ;
V_45 [ V_13 -> V_46 ] ( & V_17 ) ;
F_16 () ;
}
