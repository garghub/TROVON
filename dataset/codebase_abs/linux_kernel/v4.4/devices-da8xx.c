int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_5 . V_2 = V_2 ;
V_4 = F_2 ( & V_6 ) ;
return F_3 ( V_4 ) ? F_4 ( V_4 ) : 0 ;
}
int T_1 F_5 ( struct V_1 * V_2 [ 2 ] )
{
struct V_3 * V_4 ;
if ( V_2 ) {
V_5 . V_2 = V_2 [ 0 ] ;
V_7 . V_2 = V_2 [ 1 ] ;
}
V_4 = F_2 ( & V_6 ) ;
if ( F_3 ( V_4 ) ) {
F_6 ( L_1 , V_8 ) ;
return F_4 ( V_4 ) ;
}
V_4 = F_2 ( & V_9 ) ;
return F_3 ( V_4 ) ? F_4 ( V_4 ) : 0 ;
}
int T_1 F_7 ( int V_10 ,
struct V_11 * V_12 )
{
struct V_3 * V_13 ;
if ( V_10 == 0 )
V_13 = & V_14 ;
else if ( V_10 == 1 )
V_13 = & V_15 ;
else
return - V_16 ;
V_13 -> V_17 . V_18 = V_12 ;
return F_8 ( V_13 ) ;
}
void F_9 ( enum V_19 V_20 , const char * V_21 )
{
struct V_22 * V_17 ;
V_17 = F_10 ( & V_23 , NULL , L_2 ) ;
if ( ! V_17 ) {
F_11 ( L_3 , V_8 ) ;
return;
}
F_12 ( F_13 ( V_17 ) ) ;
}
int T_1 F_14 ( void )
{
return F_8 ( & V_24 ) ;
}
int T_1 F_15 ( void )
{
int V_25 ;
V_25 = F_8 ( & V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
return F_8 ( & V_27 ) ;
}
void T_1 F_16 ( int V_28 , struct V_29 * V_12 )
{
struct V_3 * V_13 ;
switch ( V_28 ) {
case 0 :
V_13 = & V_30 ;
break;
case 1 :
if ( ! F_17 () )
return;
V_13 = & V_31 ;
break;
case 2 :
if ( ! F_17 () )
return;
V_13 = & V_32 ;
break;
default:
return;
}
V_13 -> V_17 . V_18 = V_12 ;
F_8 ( V_13 ) ;
}
int T_1 F_18 ( void )
{
V_33 . V_34 = F_19 () ;
return F_8 ( & V_35 ) ;
}
int T_1 F_20 ( struct V_36 * V_12 )
{
V_37 . V_17 . V_18 = V_12 ;
return F_8 ( & V_37 ) ;
}
int T_1 F_21 ( void * V_12 )
{
V_38 . V_17 . V_18 = V_12 ;
return F_8 ( & V_38 ) ;
}
int T_1 F_22 ( struct V_39 * V_40 )
{
V_41 . V_17 . V_18 = V_40 ;
return F_8 ( & V_41 ) ;
}
int T_1 F_23 ( struct V_39 * V_40 )
{
V_42 . V_17 . V_18 = V_40 ;
return F_8 ( & V_42 ) ;
}
static int T_1 F_24 ( char * V_43 )
{
char * V_44 ;
if ( V_43 == NULL )
return 0 ;
V_45 = F_25 ( V_43 , & V_44 ) ;
if ( * V_44 == '@' )
V_46 = F_25 ( V_44 + 1 , NULL ) ;
return 0 ;
}
void T_1 F_26 ( void )
{
int V_25 ;
if ( ! V_46 || ! V_45 ) {
F_11 ( L_4
L_5 ,
V_8 ) ;
return;
}
F_27 ( L_6 ,
V_8 , V_45 , ( unsigned long ) V_46 ) ;
V_25 = F_28 ( & V_47 . V_17 , V_45 , V_46 , 0 ) ;
if ( V_25 )
F_11 ( L_7 , V_8 , V_25 ) ;
}
void T_1 F_26 ( void )
{
}
int T_1 F_29 ( void )
{
int V_25 ;
V_25 = F_8 ( & V_47 ) ;
if ( V_25 )
F_11 ( L_8 , V_8 , V_25 ) ;
return V_25 ;
}
int F_30 ( void )
{
return F_8 ( & V_48 ) ;
}
void T_2 * T_1 F_31 ( void )
{
if ( V_49 )
return V_49 ;
V_49 = F_32 ( V_50 , V_51 ) ;
if ( ! V_49 )
F_6 ( L_9 , V_8 ) ;
return V_49 ;
}
int T_1 F_33 ( void )
{
V_52 . V_53 = F_31 () ;
return F_8 ( & V_54 ) ;
}
int T_1 F_34 ( int V_10 , unsigned V_55 )
{
if ( V_10 < 0 || V_10 > 1 )
return - V_16 ;
V_56 [ V_10 ] . V_55 = V_55 ;
if ( V_10 == 1 && F_35 () ) {
V_57 [ 0 ] . V_58 = V_59 ;
V_57 [ 0 ] . V_60 = V_59 + V_61 - 1 ;
}
return F_8 ( & V_62 [ V_10 ] ) ;
}
int T_1 F_36 ( unsigned long V_63 )
{
F_37 ( V_63 != 100 * 1000 * 1000 ) ;
return F_8 ( & V_64 ) ;
}
