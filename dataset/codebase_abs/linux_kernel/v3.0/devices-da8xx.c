int T_1 F_1 ( struct V_1 * V_2 )
{
V_3 . V_2 = V_2 ;
return F_2 ( & V_4 ) ;
}
int T_1 F_3 ( struct V_1 * V_2 [ 2 ] )
{
if ( V_2 ) {
V_5 [ 0 ] . V_2 = V_2 [ 0 ] ;
V_5 [ 1 ] . V_2 = V_2 [ 1 ] ;
}
return F_2 ( & V_6 ) ;
}
int T_1 F_4 ( int V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 ;
if ( V_7 == 0 )
V_11 = & V_12 ;
else if ( V_7 == 1 )
V_11 = & V_13 ;
else
return - V_14 ;
V_11 -> V_15 . V_16 = V_9 ;
return F_2 ( V_11 ) ;
}
int T_1 F_5 ( void )
{
return F_2 ( & V_17 ) ;
}
int T_1 F_6 ( void )
{
int V_18 ;
V_18 = F_2 ( & V_19 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_2 ( & V_20 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_7 ( NULL , F_8 ( & V_19 . V_15 ) ,
NULL , & V_20 . V_15 ) ;
return V_18 ;
}
void T_1 F_9 ( int V_21 , struct V_22 * V_9 )
{
F_2 ( & V_23 ) ;
if ( F_10 () && V_21 == 1 ) {
V_24 . V_15 . V_16 = V_9 ;
F_2 ( & V_24 ) ;
} else if ( F_11 () ) {
V_25 . V_15 . V_16 = V_9 ;
F_2 ( & V_25 ) ;
}
}
int T_1 F_12 ( struct V_26 * V_9 )
{
V_27 . V_15 . V_16 = V_9 ;
return F_2 ( & V_27 ) ;
}
int T_1 F_13 ( struct V_28 * V_29 )
{
V_30 . V_15 . V_16 = V_29 ;
return F_2 ( & V_30 ) ;
}
int T_1 F_14 ( struct V_28 * V_29 )
{
V_31 . V_15 . V_16 = V_29 ;
return F_2 ( & V_31 ) ;
}
int F_15 ( void )
{
int V_18 ;
void T_2 * V_32 ;
V_32 = F_16 ( V_33 , V_34 ) ;
if ( F_17 ( ! V_32 ) )
return - V_35 ;
F_18 ( 0x83e70b13 , V_32 + 0x6c ) ;
F_18 ( 0x95a4f1e0 , V_32 + 0x70 ) ;
F_19 ( V_32 ) ;
V_18 = F_2 ( & V_36 ) ;
if ( ! V_18 )
F_20 ( & V_36 . V_15 , true ) ;
return V_18 ;
}
void T_2 * T_1 F_21 ( void )
{
if ( V_37 )
return V_37 ;
V_37 = F_16 ( V_38 , V_39 ) ;
if ( ! V_37 )
F_22 ( L_1 , V_40 ) ;
return V_37 ;
}
int T_1 F_23 ( void )
{
V_41 . V_42 = F_21 () ;
return F_2 ( & V_43 ) ;
}
int T_1 F_24 ( int V_7 , struct V_44 * V_45 ,
unsigned V_46 )
{
int V_18 ;
if ( V_7 < 0 || V_7 > 1 )
return - V_14 ;
V_18 = F_25 ( V_45 , V_46 ) ;
if ( V_18 )
F_22 ( L_2
L_3 , V_40 , V_7 , V_18 ) ;
V_47 [ V_7 ] . V_48 = V_46 ;
if ( V_7 == 1 && F_11 () ) {
V_49 [ 0 ] . V_50 = V_51 ;
V_49 [ 0 ] . V_52 = V_51 + V_34 - 1 ;
}
return F_2 ( & V_53 [ V_7 ] ) ;
}
