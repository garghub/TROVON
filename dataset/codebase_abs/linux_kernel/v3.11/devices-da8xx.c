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
void F_5 ( enum V_17 V_18 , const char * V_19 )
{
struct V_20 * V_15 ;
V_15 = F_6 ( & V_21 , NULL , L_1 ) ;
if ( ! V_15 ) {
F_7 ( L_2 , V_22 ) ;
return;
}
F_8 ( F_9 ( V_15 ) ) ;
}
int T_1 F_10 ( void )
{
return F_2 ( & V_23 ) ;
}
int T_1 F_11 ( void )
{
int V_24 ;
V_24 = F_2 ( & V_25 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_2 ( & V_26 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_12 ( NULL , F_13 ( & V_25 . V_15 ) ,
NULL , & V_26 . V_15 ) ;
return V_24 ;
}
void T_1 F_14 ( int V_27 , struct V_28 * V_9 )
{
if ( F_15 () && V_27 == 1 ) {
V_29 . V_15 . V_16 = V_9 ;
F_2 ( & V_29 ) ;
} else if ( F_16 () ) {
V_30 . V_15 . V_16 = V_9 ;
F_2 ( & V_30 ) ;
}
}
int T_1 F_17 ( void )
{
V_31 . V_32 = F_18 () ;
return F_2 ( & V_33 ) ;
}
int T_1 F_19 ( struct V_34 * V_9 )
{
V_35 . V_15 . V_16 = V_9 ;
return F_2 ( & V_35 ) ;
}
int T_1 F_20 ( struct V_36 * V_37 )
{
V_38 . V_15 . V_16 = V_37 ;
return F_2 ( & V_38 ) ;
}
int T_1 F_21 ( struct V_36 * V_37 )
{
V_39 . V_15 . V_16 = V_37 ;
return F_2 ( & V_39 ) ;
}
static int T_1 F_22 ( char * V_40 )
{
char * V_41 ;
if ( V_40 == NULL )
return 0 ;
V_42 = F_23 ( V_40 , & V_41 ) ;
if ( * V_41 == '@' )
V_43 = F_23 ( V_41 + 1 , NULL ) ;
return 0 ;
}
void T_1 F_24 ( void )
{
int V_24 ;
if ( ! V_43 || ! V_42 ) {
F_7 ( L_3
L_4 ,
V_22 ) ;
return;
}
F_25 ( L_5 ,
V_22 , V_42 , ( unsigned long ) V_43 ) ;
V_24 = F_26 ( & V_44 . V_15 , V_42 , V_43 , 0 ) ;
if ( V_24 )
F_7 ( L_6 , V_22 , V_24 ) ;
}
void T_1 F_24 ( void )
{
}
int T_1 F_27 ( void )
{
int V_24 ;
V_24 = F_2 ( & V_44 ) ;
if ( V_24 )
F_7 ( L_7 , V_22 , V_24 ) ;
return V_24 ;
}
int F_28 ( void )
{
int V_24 ;
V_24 = F_2 ( & V_45 ) ;
if ( ! V_24 )
F_29 ( & V_45 . V_15 , true ) ;
return V_24 ;
}
void T_2 * T_1 F_30 ( void )
{
if ( V_46 )
return V_46 ;
V_46 = F_31 ( V_47 , V_48 ) ;
if ( ! V_46 )
F_32 ( L_8 , V_22 ) ;
return V_46 ;
}
int T_1 F_33 ( void )
{
V_49 . V_50 = F_30 () ;
return F_2 ( & V_51 ) ;
}
int T_1 F_34 ( int V_7 , unsigned V_52 )
{
if ( V_7 < 0 || V_7 > 1 )
return - V_14 ;
V_53 [ V_7 ] . V_52 = V_52 ;
if ( V_7 == 1 && F_16 () ) {
V_54 [ 0 ] . V_55 = V_56 ;
V_54 [ 0 ] . V_57 = V_56 + V_58 - 1 ;
}
return F_2 ( & V_59 [ V_7 ] ) ;
}
static int F_35 ( struct V_20 * V_15 , void T_2 * V_60 )
{
int V_61 , V_24 ;
unsigned int V_62 ;
V_63 = F_36 ( V_15 , NULL ) ;
if ( F_37 ( V_63 ) )
return F_38 ( V_63 ) ;
V_24 = F_39 ( V_63 ) ;
if ( V_24 )
goto V_64;
V_62 = F_40 ( F_41 ( V_65 ) ) ;
V_62 &= ~ F_42 ( 0 ) ;
F_43 ( V_62 , F_41 ( V_65 ) ) ;
for ( V_61 = 0 ; V_61 < F_44 ( V_66 ) ; V_61 ++ )
if ( V_66 [ V_61 ] == V_67 )
break;
if ( V_61 == F_44 ( V_66 ) ) {
V_24 = - V_14 ;
goto V_68;
}
V_62 = F_45 ( V_61 + 1 ) |
F_46 ( 1 ) |
F_47 ( 4 ) |
F_48 ( 1 ) |
F_49 ( 3 ) |
F_50 ( 1 ) ;
F_43 ( V_62 , V_60 + V_69 ) ;
return 0 ;
V_68:
F_51 ( V_63 ) ;
V_64:
F_52 ( V_63 ) ;
return V_24 ;
}
static void F_53 ( struct V_20 * V_15 )
{
F_51 ( V_63 ) ;
F_52 ( V_63 ) ;
}
int T_1 F_54 ( unsigned long V_70 )
{
V_67 = V_70 ;
if ( ! V_67 )
return - V_14 ;
return F_2 ( & V_71 ) ;
}
