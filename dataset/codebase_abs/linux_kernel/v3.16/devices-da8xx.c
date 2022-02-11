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
return F_2 ( & V_26 ) ;
}
void T_1 F_12 ( int V_27 , struct V_28 * V_9 )
{
if ( F_13 () && V_27 == 1 ) {
V_29 . V_15 . V_16 = V_9 ;
F_2 ( & V_29 ) ;
} else if ( F_14 () ) {
V_30 . V_15 . V_16 = V_9 ;
F_2 ( & V_30 ) ;
}
}
int T_1 F_15 ( void )
{
V_31 . V_32 = F_16 () ;
return F_2 ( & V_33 ) ;
}
int T_1 F_17 ( struct V_34 * V_9 )
{
V_35 . V_15 . V_16 = V_9 ;
return F_2 ( & V_35 ) ;
}
int T_1 F_18 ( void * V_9 )
{
V_36 . V_15 . V_16 = V_9 ;
return F_2 ( & V_36 ) ;
}
int T_1 F_19 ( struct V_37 * V_38 )
{
V_39 . V_15 . V_16 = V_38 ;
return F_2 ( & V_39 ) ;
}
int T_1 F_20 ( struct V_37 * V_38 )
{
V_40 . V_15 . V_16 = V_38 ;
return F_2 ( & V_40 ) ;
}
static int T_1 F_21 ( char * V_41 )
{
char * V_42 ;
if ( V_41 == NULL )
return 0 ;
V_43 = F_22 ( V_41 , & V_42 ) ;
if ( * V_42 == '@' )
V_44 = F_22 ( V_42 + 1 , NULL ) ;
return 0 ;
}
void T_1 F_23 ( void )
{
int V_24 ;
if ( ! V_44 || ! V_43 ) {
F_7 ( L_3
L_4 ,
V_22 ) ;
return;
}
F_24 ( L_5 ,
V_22 , V_43 , ( unsigned long ) V_44 ) ;
V_24 = F_25 ( & V_45 . V_15 , V_43 , V_44 , 0 ) ;
if ( V_24 )
F_7 ( L_6 , V_22 , V_24 ) ;
}
void T_1 F_23 ( void )
{
}
int T_1 F_26 ( void )
{
int V_24 ;
V_24 = F_2 ( & V_45 ) ;
if ( V_24 )
F_7 ( L_7 , V_22 , V_24 ) ;
return V_24 ;
}
int F_27 ( void )
{
return F_2 ( & V_46 ) ;
}
void T_2 * T_1 F_28 ( void )
{
if ( V_47 )
return V_47 ;
V_47 = F_29 ( V_48 , V_49 ) ;
if ( ! V_47 )
F_30 ( L_8 , V_22 ) ;
return V_47 ;
}
int T_1 F_31 ( void )
{
V_50 . V_51 = F_28 () ;
return F_2 ( & V_52 ) ;
}
int T_1 F_32 ( int V_7 , unsigned V_53 )
{
if ( V_7 < 0 || V_7 > 1 )
return - V_14 ;
V_54 [ V_7 ] . V_53 = V_53 ;
if ( V_7 == 1 && F_14 () ) {
V_55 [ 0 ] . V_56 = V_57 ;
V_55 [ 0 ] . V_58 = V_57 + V_59 - 1 ;
}
return F_2 ( & V_60 [ V_7 ] ) ;
}
int T_1 F_33 ( unsigned long V_61 )
{
F_34 ( V_61 != 100 * 1000 * 1000 ) ;
return F_2 ( & V_62 ) ;
}
