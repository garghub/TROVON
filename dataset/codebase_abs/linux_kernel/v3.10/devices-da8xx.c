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
static int T_1 F_22 ( char * V_39 )
{
char * V_40 ;
if ( V_39 == NULL )
return 0 ;
V_41 = F_23 ( V_39 , & V_40 ) ;
if ( * V_40 == '@' )
V_42 = F_23 ( V_40 + 1 , NULL ) ;
return 0 ;
}
void T_1 F_24 ( void )
{
int V_23 ;
if ( ! V_42 || ! V_41 ) {
F_7 ( L_3
L_4 ,
V_21 ) ;
return;
}
F_25 ( L_5 ,
V_21 , V_41 , ( unsigned long ) V_42 ) ;
V_23 = F_26 ( & V_43 . V_15 , V_41 , V_42 , 0 ) ;
if ( V_23 )
F_7 ( L_6 , V_21 , V_23 ) ;
}
void T_1 F_24 ( void )
{
}
int T_1 F_27 ( void )
{
int V_23 ;
V_23 = F_2 ( & V_43 ) ;
if ( V_23 )
F_7 ( L_7 , V_21 , V_23 ) ;
return V_23 ;
}
int F_28 ( void )
{
int V_23 ;
V_23 = F_2 ( & V_44 ) ;
if ( ! V_23 )
F_29 ( & V_44 . V_15 , true ) ;
return V_23 ;
}
void T_2 * T_1 F_30 ( void )
{
if ( V_45 )
return V_45 ;
V_45 = F_31 ( V_46 , V_47 ) ;
if ( ! V_45 )
F_32 ( L_8 , V_21 ) ;
return V_45 ;
}
int T_1 F_33 ( void )
{
V_48 . V_49 = F_30 () ;
return F_2 ( & V_50 ) ;
}
int T_1 F_34 ( int V_7 , unsigned V_51 )
{
if ( V_7 < 0 || V_7 > 1 )
return - V_14 ;
V_52 [ V_7 ] . V_51 = V_51 ;
if ( V_7 == 1 && F_16 () ) {
V_53 [ 0 ] . V_54 = V_55 ;
V_53 [ 0 ] . V_56 = V_55 + V_57 - 1 ;
}
return F_2 ( & V_58 [ V_7 ] ) ;
}
static int F_35 ( struct V_19 * V_15 , void T_2 * V_59 )
{
int V_60 , V_23 ;
unsigned int V_61 ;
V_62 = F_36 ( V_15 , NULL ) ;
if ( F_37 ( V_62 ) )
return F_38 ( V_62 ) ;
V_23 = F_39 ( V_62 ) ;
if ( V_23 )
goto V_63;
V_61 = F_40 ( F_41 ( V_64 ) ) ;
V_61 &= ~ F_42 ( 0 ) ;
F_43 ( V_61 , F_41 ( V_64 ) ) ;
for ( V_60 = 0 ; V_60 < F_44 ( V_65 ) ; V_60 ++ )
if ( V_65 [ V_60 ] == V_66 )
break;
if ( V_60 == F_44 ( V_65 ) ) {
V_23 = - V_14 ;
goto V_67;
}
V_61 = F_45 ( V_60 + 1 ) |
F_46 ( 1 ) |
F_47 ( 4 ) |
F_48 ( 1 ) |
F_49 ( 3 ) |
F_50 ( 1 ) ;
F_43 ( V_61 , V_59 + V_68 ) ;
return 0 ;
V_67:
F_51 ( V_62 ) ;
V_63:
F_52 ( V_62 ) ;
return V_23 ;
}
static void F_53 ( struct V_19 * V_15 )
{
F_51 ( V_62 ) ;
F_52 ( V_62 ) ;
}
int T_1 F_54 ( unsigned long V_69 )
{
V_66 = V_69 ;
if ( ! V_66 )
return - V_14 ;
return F_2 ( & V_70 ) ;
}
