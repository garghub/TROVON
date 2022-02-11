static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 , V_7 ;
int V_8 ;
F_3 ( & V_5 -> V_9 ) ;
V_5 -> V_10 [ 0 ] = ( V_3 << V_11 ) |
V_12 | V_13 |
V_14 | V_15 | V_16 ;
V_8 = F_4 ( V_5 -> V_17 , & V_5 -> V_18 ) ;
if ( V_8 < 0 ) {
F_5 ( V_2 , L_1 , V_8 ) ;
F_6 ( & V_5 -> V_9 ) ;
return V_8 ;
}
V_6 = V_5 -> V_19 [ 0 ] ;
V_7 = V_5 -> V_19 [ 1 ] ;
F_6 ( & V_5 -> V_9 ) ;
if ( ( V_6 & 0xc0 ) || ( V_7 & 0x3f ) )
return - V_20 ;
return ( V_6 << 2 ) | ( V_7 >> 6 ) ;
}
int F_7 ( int V_3 )
{
return F_1 ( & V_21 -> V_17 -> V_2 , V_3 ) ;
}
static T_2 F_8 ( struct V_1 * V_2 ,
struct V_22 * V_23 , char * V_24 )
{
return sprintf ( V_24 , L_2 ) ;
}
static T_2 F_9 ( struct V_1 * V_2 ,
struct V_22 * V_23 , char * V_24 )
{
int V_3 = F_10 ( V_23 ) -> V_25 ;
int V_26 ;
V_26 = F_1 ( V_2 , V_3 ) ;
if ( V_26 < 0 )
return V_26 ;
return sprintf ( V_24 , L_3 , V_26 ) ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_27 * V_28 ;
struct V_29 * V_30 ;
V_5 -> V_10 = F_12 ( V_31 , V_32 ) ;
if ( ! V_5 -> V_10 )
return - V_33 ;
V_5 -> V_19 = F_12 ( V_34 , V_32 ) ;
if ( ! V_5 -> V_19 ) {
F_13 ( V_5 -> V_10 ) ;
return - V_33 ;
}
V_28 = & V_5 -> V_18 ;
V_30 = & V_5 -> V_35 [ 0 ] ;
F_14 ( V_28 ) ;
V_30 -> V_10 = & V_5 -> V_10 [ 0 ] ;
V_30 -> V_36 = 1 ;
F_15 ( V_30 , V_28 ) ;
V_30 ++ ;
V_30 -> V_19 = & V_5 -> V_19 [ 0 ] ;
V_30 -> V_36 = 2 ;
F_15 ( V_30 , V_28 ) ;
return 0 ;
}
static int T_3 F_16 ( struct V_37 * V_17 )
{
struct V_4 * V_5 ;
int V_8 ;
V_17 -> V_38 = 8 ;
V_17 -> V_39 = V_40 ;
V_8 = F_17 ( V_17 ) ;
if ( V_8 < 0 )
return V_8 ;
V_5 = F_18 ( sizeof( struct V_4 ) , V_32 ) ;
if ( V_5 == NULL ) {
F_5 ( & V_17 -> V_2 , L_4 ) ;
return - V_33 ;
}
V_8 = F_11 ( V_5 ) ;
if ( V_8 )
goto V_41;
F_19 ( & V_5 -> V_9 ) ;
V_5 -> V_17 = V_17 ;
F_20 ( V_17 , V_5 ) ;
V_8 = F_21 ( & V_17 -> V_2 . V_42 , & V_43 ) ;
if ( V_8 ) {
F_5 ( & V_17 -> V_2 , L_5 ) ;
goto V_44;
}
V_5 -> V_45 = F_22 ( & V_17 -> V_2 ) ;
if ( F_23 ( V_5 -> V_45 ) ) {
F_5 ( & V_17 -> V_2 , L_6 ) ;
V_8 = F_24 ( V_5 -> V_45 ) ;
goto V_46;
}
#ifdef F_25
V_21 = V_5 ;
#endif
return 0 ;
V_46:
F_26 ( & V_17 -> V_2 . V_42 , & V_43 ) ;
V_44:
F_13 ( V_5 -> V_19 ) ;
F_13 ( V_5 -> V_10 ) ;
V_41:
F_13 ( V_5 ) ;
return V_8 ;
}
static int T_4 F_27 ( struct V_37 * V_17 )
{
struct V_4 * V_5 = F_28 ( V_17 ) ;
F_29 ( V_5 -> V_45 ) ;
F_26 ( & V_17 -> V_2 . V_42 , & V_43 ) ;
F_30 ( & V_5 -> V_9 ) ;
F_13 ( V_5 -> V_19 ) ;
F_13 ( V_5 -> V_10 ) ;
F_13 ( V_5 ) ;
return 0 ;
}
static int T_5 F_31 ( void )
{
return F_32 ( & V_47 ) ;
}
static void T_6 F_33 ( void )
{
F_34 ( & V_47 ) ;
}
