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
struct V_10 * V_11 ;
switch ( V_27 ) {
case 0 :
V_11 = & V_29 ;
break;
case 1 :
if ( ! F_13 () )
return;
V_11 = & V_30 ;
break;
case 2 :
if ( ! F_13 () )
return;
V_11 = & V_31 ;
break;
default:
return;
}
V_11 -> V_15 . V_16 = V_9 ;
F_2 ( V_11 ) ;
}
int T_1 F_14 ( void )
{
V_32 . V_33 = F_15 () ;
return F_2 ( & V_34 ) ;
}
int T_1 F_16 ( struct V_35 * V_9 )
{
V_36 . V_15 . V_16 = V_9 ;
return F_2 ( & V_36 ) ;
}
int T_1 F_17 ( void * V_9 )
{
V_37 . V_15 . V_16 = V_9 ;
return F_2 ( & V_37 ) ;
}
int T_1 F_18 ( struct V_38 * V_39 )
{
V_40 . V_15 . V_16 = V_39 ;
return F_2 ( & V_40 ) ;
}
int T_1 F_19 ( struct V_38 * V_39 )
{
V_41 . V_15 . V_16 = V_39 ;
return F_2 ( & V_41 ) ;
}
static int T_1 F_20 ( char * V_42 )
{
char * V_43 ;
if ( V_42 == NULL )
return 0 ;
V_44 = F_21 ( V_42 , & V_43 ) ;
if ( * V_43 == '@' )
V_45 = F_21 ( V_43 + 1 , NULL ) ;
return 0 ;
}
void T_1 F_22 ( void )
{
int V_24 ;
if ( ! V_45 || ! V_44 ) {
F_7 ( L_3
L_4 ,
V_22 ) ;
return;
}
F_23 ( L_5 ,
V_22 , V_44 , ( unsigned long ) V_45 ) ;
V_24 = F_24 ( & V_46 . V_15 , V_44 , V_45 , 0 ) ;
if ( V_24 )
F_7 ( L_6 , V_22 , V_24 ) ;
}
void T_1 F_22 ( void )
{
}
int T_1 F_25 ( void )
{
int V_24 ;
V_24 = F_2 ( & V_46 ) ;
if ( V_24 )
F_7 ( L_7 , V_22 , V_24 ) ;
return V_24 ;
}
int F_26 ( void )
{
return F_2 ( & V_47 ) ;
}
void T_2 * T_1 F_27 ( void )
{
if ( V_48 )
return V_48 ;
V_48 = F_28 ( V_49 , V_50 ) ;
if ( ! V_48 )
F_29 ( L_8 , V_22 ) ;
return V_48 ;
}
int T_1 F_30 ( void )
{
V_51 . V_52 = F_27 () ;
return F_2 ( & V_53 ) ;
}
int T_1 F_31 ( int V_7 , unsigned V_54 )
{
if ( V_7 < 0 || V_7 > 1 )
return - V_14 ;
V_55 [ V_7 ] . V_54 = V_54 ;
if ( V_7 == 1 && F_32 () ) {
V_56 [ 0 ] . V_57 = V_58 ;
V_56 [ 0 ] . V_59 = V_58 + V_60 - 1 ;
}
return F_2 ( & V_61 [ V_7 ] ) ;
}
int T_1 F_33 ( unsigned long V_62 )
{
F_34 ( V_62 != 100 * 1000 * 1000 ) ;
return F_2 ( & V_63 ) ;
}
