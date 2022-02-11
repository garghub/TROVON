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
struct V_19 * V_15 ;
V_15 = F_6 ( & V_20 , NULL , L_1 ) ;
if ( ! V_15 ) {
F_7 ( L_2 , V_21 ) ;
return;
}
F_8 ( F_9 ( V_15 ) ) ;
}
int T_1 F_10 ( void )
{
return F_2 ( & V_22 ) ;
}
int T_1 F_11 ( void )
{
int V_23 ;
V_23 = F_2 ( & V_24 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_2 ( & V_25 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_12 ( NULL , F_13 ( & V_24 . V_15 ) ,
NULL , & V_25 . V_15 ) ;
return V_23 ;
}
void T_1 F_14 ( int V_26 , struct V_27 * V_9 )
{
if ( F_15 () && V_26 == 1 ) {
V_28 . V_15 . V_16 = V_9 ;
F_2 ( & V_28 ) ;
} else if ( F_16 () ) {
V_29 . V_15 . V_16 = V_9 ;
F_2 ( & V_29 ) ;
}
}
int T_1 F_17 ( void )
{
V_30 . V_31 = F_18 () ;
return F_2 ( & V_32 ) ;
}
int T_1 F_19 ( struct V_33 * V_9 )
{
V_34 . V_15 . V_16 = V_9 ;
return F_2 ( & V_34 ) ;
}
int T_1 F_20 ( struct V_35 * V_36 )
{
V_37 . V_15 . V_16 = V_36 ;
return F_2 ( & V_37 ) ;
}
int T_1 F_21 ( struct V_35 * V_36 )
{
V_38 . V_15 . V_16 = V_36 ;
return F_2 ( & V_38 ) ;
}
int F_22 ( void )
{
int V_23 ;
V_23 = F_2 ( & V_39 ) ;
if ( ! V_23 )
F_23 ( & V_39 . V_15 , true ) ;
return V_23 ;
}
void T_2 * T_1 F_24 ( void )
{
if ( V_40 )
return V_40 ;
V_40 = F_25 ( V_41 , V_42 ) ;
if ( ! V_40 )
F_26 ( L_3 , V_21 ) ;
return V_40 ;
}
int T_1 F_27 ( void )
{
V_43 . V_44 = F_24 () ;
return F_2 ( & V_45 ) ;
}
int T_1 F_28 ( int V_7 , unsigned V_46 )
{
if ( V_7 < 0 || V_7 > 1 )
return - V_14 ;
V_47 [ V_7 ] . V_46 = V_46 ;
if ( V_7 == 1 && F_16 () ) {
V_48 [ 0 ] . V_49 = V_50 ;
V_48 [ 0 ] . V_51 = V_50 + V_52 - 1 ;
}
return F_2 ( & V_53 [ V_7 ] ) ;
}
static int F_29 ( struct V_19 * V_15 , void T_2 * V_54 )
{
int V_55 , V_23 ;
unsigned int V_56 ;
V_57 = F_30 ( V_15 , NULL ) ;
if ( F_31 ( V_57 ) )
return F_32 ( V_57 ) ;
V_23 = F_33 ( V_57 ) ;
if ( V_23 )
goto V_58;
V_56 = F_34 ( F_35 ( V_59 ) ) ;
V_56 &= ~ F_36 ( 0 ) ;
F_37 ( V_56 , F_35 ( V_59 ) ) ;
for ( V_55 = 0 ; V_55 < F_38 ( V_60 ) ; V_55 ++ )
if ( V_60 [ V_55 ] == V_61 )
break;
if ( V_55 == F_38 ( V_60 ) ) {
V_23 = - V_14 ;
goto V_62;
}
V_56 = F_39 ( V_55 + 1 ) |
F_40 ( 1 ) |
F_41 ( 4 ) |
F_42 ( 1 ) |
F_43 ( 3 ) |
F_44 ( 1 ) ;
F_37 ( V_56 , V_54 + V_63 ) ;
return 0 ;
V_62:
F_45 ( V_57 ) ;
V_58:
F_46 ( V_57 ) ;
return V_23 ;
}
static void F_47 ( struct V_19 * V_15 )
{
F_45 ( V_57 ) ;
F_46 ( V_57 ) ;
}
int T_1 F_48 ( unsigned long V_64 )
{
V_61 = V_64 ;
if ( ! V_61 )
return - V_14 ;
return F_2 ( & V_65 ) ;
}
