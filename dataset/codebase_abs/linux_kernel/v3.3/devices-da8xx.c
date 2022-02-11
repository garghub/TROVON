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
void F_5 ( char V_17 , const char * V_18 )
{
F_6 ( & V_19 ) ;
}
int T_1 F_7 ( void )
{
return F_2 ( & V_19 ) ;
}
int T_1 F_8 ( void )
{
int V_20 ;
V_20 = F_2 ( & V_21 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_2 ( & V_22 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_9 ( NULL , F_10 ( & V_21 . V_15 ) ,
NULL , & V_22 . V_15 ) ;
return V_20 ;
}
void T_1 F_11 ( int V_23 , struct V_24 * V_9 )
{
F_2 ( & V_25 ) ;
if ( F_12 () && V_23 == 1 ) {
V_26 . V_15 . V_16 = V_9 ;
F_2 ( & V_26 ) ;
} else if ( F_13 () ) {
V_27 . V_15 . V_16 = V_9 ;
F_2 ( & V_27 ) ;
}
}
int T_1 F_14 ( struct V_28 * V_9 )
{
V_29 . V_15 . V_16 = V_9 ;
return F_2 ( & V_29 ) ;
}
int T_1 F_15 ( struct V_30 * V_31 )
{
V_32 . V_15 . V_16 = V_31 ;
return F_2 ( & V_32 ) ;
}
int T_1 F_16 ( struct V_30 * V_31 )
{
V_33 . V_15 . V_16 = V_31 ;
return F_2 ( & V_33 ) ;
}
int F_17 ( void )
{
int V_20 ;
void T_2 * V_34 ;
V_34 = F_18 ( V_35 , V_36 ) ;
if ( F_19 ( ! V_34 ) )
return - V_37 ;
F_20 ( 0x83e70b13 , V_34 + 0x6c ) ;
F_20 ( 0x95a4f1e0 , V_34 + 0x70 ) ;
F_21 ( V_34 ) ;
V_20 = F_2 ( & V_38 ) ;
if ( ! V_20 )
F_22 ( & V_38 . V_15 , true ) ;
return V_20 ;
}
void T_2 * T_1 F_23 ( void )
{
if ( V_39 )
return V_39 ;
V_39 = F_18 ( V_40 , V_41 ) ;
if ( ! V_39 )
F_24 ( L_1 , V_42 ) ;
return V_39 ;
}
int T_1 F_25 ( void )
{
V_43 . V_44 = F_23 () ;
return F_2 ( & V_45 ) ;
}
int T_1 F_26 ( int V_7 , struct V_46 * V_47 ,
unsigned V_48 )
{
int V_20 ;
if ( V_7 < 0 || V_7 > 1 )
return - V_14 ;
V_20 = F_27 ( V_47 , V_48 ) ;
if ( V_20 )
F_24 ( L_2
L_3 , V_42 , V_7 , V_20 ) ;
V_49 [ V_7 ] . V_50 = V_48 ;
if ( V_7 == 1 && F_13 () ) {
V_51 [ 0 ] . V_52 = V_53 ;
V_51 [ 0 ] . V_54 = V_53 + V_36 - 1 ;
}
return F_2 ( & V_55 [ V_7 ] ) ;
}
static int F_28 ( struct V_56 * V_15 , void T_2 * V_57 )
{
int V_58 , V_20 ;
unsigned int V_59 ;
V_60 = F_29 ( V_15 , NULL ) ;
if ( F_30 ( V_60 ) )
return F_31 ( V_60 ) ;
V_20 = F_32 ( V_60 ) ;
if ( V_20 )
goto V_61;
V_59 = F_33 ( F_34 ( V_62 ) ) ;
V_59 &= ~ F_35 ( 0 ) ;
F_20 ( V_59 , F_34 ( V_62 ) ) ;
for ( V_58 = 0 ; V_58 < F_36 ( V_63 ) ; V_58 ++ )
if ( V_63 [ V_58 ] == V_64 )
break;
if ( V_58 == F_36 ( V_63 ) ) {
V_20 = - V_14 ;
goto V_65;
}
V_59 = F_37 ( V_58 + 1 ) |
F_38 ( 1 ) |
F_39 ( 4 ) |
F_40 ( 1 ) |
F_41 ( 3 ) |
F_42 ( 1 ) ;
F_20 ( V_59 , V_57 + V_66 ) ;
return 0 ;
V_65:
F_43 ( V_60 ) ;
V_61:
F_44 ( V_60 ) ;
return V_20 ;
}
static void F_45 ( struct V_56 * V_15 )
{
F_43 ( V_60 ) ;
F_44 ( V_60 ) ;
}
int T_1 F_46 ( unsigned long V_67 )
{
V_64 = V_67 ;
if ( ! V_64 )
return - V_14 ;
return F_2 ( & V_68 ) ;
}
