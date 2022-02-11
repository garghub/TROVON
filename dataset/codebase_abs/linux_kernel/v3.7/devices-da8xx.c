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
if ( F_12 () && V_23 == 1 ) {
V_25 . V_15 . V_16 = V_9 ;
F_2 ( & V_25 ) ;
} else if ( F_13 () ) {
V_26 . V_15 . V_16 = V_9 ;
F_2 ( & V_26 ) ;
}
}
int T_1 F_14 ( struct V_27 * V_9 )
{
V_28 . V_15 . V_16 = V_9 ;
return F_2 ( & V_28 ) ;
}
int T_1 F_15 ( struct V_29 * V_30 )
{
V_31 . V_15 . V_16 = V_30 ;
return F_2 ( & V_31 ) ;
}
int T_1 F_16 ( struct V_29 * V_30 )
{
V_32 . V_15 . V_16 = V_30 ;
return F_2 ( & V_32 ) ;
}
int F_17 ( void )
{
int V_20 ;
void T_2 * V_33 ;
V_33 = F_18 ( V_34 , V_35 ) ;
if ( F_19 ( ! V_33 ) )
return - V_36 ;
F_20 ( 0x83e70b13 , V_33 + 0x6c ) ;
F_20 ( 0x95a4f1e0 , V_33 + 0x70 ) ;
F_21 ( V_33 ) ;
V_20 = F_2 ( & V_37 ) ;
if ( ! V_20 )
F_22 ( & V_37 . V_15 , true ) ;
return V_20 ;
}
void T_2 * T_1 F_23 ( void )
{
if ( V_38 )
return V_38 ;
V_38 = F_18 ( V_39 , V_40 ) ;
if ( ! V_38 )
F_24 ( L_1 , V_41 ) ;
return V_38 ;
}
int T_1 F_25 ( void )
{
V_42 . V_43 = F_23 () ;
return F_2 ( & V_44 ) ;
}
int T_1 F_26 ( int V_7 , const struct V_45 * V_46 ,
unsigned V_47 )
{
int V_20 ;
if ( V_7 < 0 || V_7 > 1 )
return - V_14 ;
V_20 = F_27 ( V_46 , V_47 ) ;
if ( V_20 )
F_24 ( L_2
L_3 , V_41 , V_7 , V_20 ) ;
V_48 [ V_7 ] . V_49 = V_47 ;
if ( V_7 == 1 && F_13 () ) {
V_50 [ 0 ] . V_51 = V_52 ;
V_50 [ 0 ] . V_53 = V_52 + V_35 - 1 ;
}
return F_2 ( & V_54 [ V_7 ] ) ;
}
static int F_28 ( struct V_55 * V_15 , void T_2 * V_56 )
{
int V_57 , V_20 ;
unsigned int V_58 ;
V_59 = F_29 ( V_15 , NULL ) ;
if ( F_30 ( V_59 ) )
return F_31 ( V_59 ) ;
V_20 = F_32 ( V_59 ) ;
if ( V_20 )
goto V_60;
V_58 = F_33 ( F_34 ( V_61 ) ) ;
V_58 &= ~ F_35 ( 0 ) ;
F_20 ( V_58 , F_34 ( V_61 ) ) ;
for ( V_57 = 0 ; V_57 < F_36 ( V_62 ) ; V_57 ++ )
if ( V_62 [ V_57 ] == V_63 )
break;
if ( V_57 == F_36 ( V_62 ) ) {
V_20 = - V_14 ;
goto V_64;
}
V_58 = F_37 ( V_57 + 1 ) |
F_38 ( 1 ) |
F_39 ( 4 ) |
F_40 ( 1 ) |
F_41 ( 3 ) |
F_42 ( 1 ) ;
F_20 ( V_58 , V_56 + V_65 ) ;
return 0 ;
V_64:
F_43 ( V_59 ) ;
V_60:
F_44 ( V_59 ) ;
return V_20 ;
}
static void F_45 ( struct V_55 * V_15 )
{
F_43 ( V_59 ) ;
F_44 ( V_59 ) ;
}
int T_1 F_46 ( unsigned long V_66 )
{
V_63 = V_66 ;
if ( ! V_63 )
return - V_14 ;
return F_2 ( & V_67 ) ;
}
