int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_5 . V_2 = V_2 ;
V_5 . V_6 = V_7 ;
V_5 . V_8 = F_2 ( V_7 ) ;
V_4 = F_3 ( & V_9 ) ;
return F_4 ( V_4 ) ? F_5 ( V_4 ) : 0 ;
}
int T_1 F_6 ( struct V_1 * V_2 [ 2 ] )
{
struct V_3 * V_4 ;
if ( V_2 ) {
V_5 . V_2 = V_2 [ 0 ] ;
V_10 . V_2 = V_2 [ 1 ] ;
}
V_5 . V_6 = V_11 ;
V_5 . V_8 = F_2 ( V_11 ) ;
V_4 = F_3 ( & V_9 ) ;
if ( F_4 ( V_4 ) ) {
F_7 ( L_1 , V_12 ) ;
return F_5 ( V_4 ) ;
}
V_10 . V_6 = V_13 ;
V_10 . V_8 = F_2 ( V_13 ) ;
V_4 = F_3 ( & V_14 ) ;
return F_4 ( V_4 ) ? F_5 ( V_4 ) : 0 ;
}
int T_1 F_8 ( int V_15 ,
struct V_16 * V_17 )
{
struct V_3 * V_18 ;
if ( V_15 == 0 )
V_18 = & V_19 ;
else if ( V_15 == 1 )
V_18 = & V_20 ;
else
return - V_21 ;
V_18 -> V_22 . V_23 = V_17 ;
return F_9 ( V_18 ) ;
}
void F_10 ( enum V_24 V_25 , const char * V_26 )
{
struct V_27 * V_22 ;
V_22 = F_11 ( & V_28 , NULL , L_2 ) ;
if ( ! V_22 ) {
F_12 ( L_3 , V_12 ) ;
return;
}
F_13 ( F_14 ( V_22 ) ) ;
}
int T_1 F_15 ( void )
{
return F_9 ( & V_29 ) ;
}
int T_1 F_16 ( void )
{
int V_30 ;
V_30 = F_9 ( & V_31 ) ;
if ( V_30 < 0 )
return V_30 ;
return F_9 ( & V_32 ) ;
}
void T_1 F_17 ( int V_33 , struct V_34 * V_17 )
{
struct V_3 * V_18 ;
switch ( V_33 ) {
case 0 :
V_18 = & V_35 ;
break;
case 1 :
if ( ! F_18 () )
return;
V_18 = & V_36 ;
break;
case 2 :
if ( ! F_18 () )
return;
V_18 = & V_37 ;
break;
default:
return;
}
V_18 -> V_22 . V_23 = V_17 ;
F_9 ( V_18 ) ;
}
int T_1 F_19 ( void )
{
V_38 . V_39 = F_20 () ;
return F_9 ( & V_40 ) ;
}
int T_1 F_21 ( struct V_41 * V_17 )
{
V_42 . V_22 . V_23 = V_17 ;
return F_9 ( & V_42 ) ;
}
int T_1 F_22 ( void * V_17 )
{
V_43 . V_22 . V_23 = V_17 ;
return F_9 ( & V_43 ) ;
}
int T_1 F_23 ( struct V_44 * V_45 )
{
V_46 . V_22 . V_23 = V_45 ;
return F_9 ( & V_46 ) ;
}
int T_1 F_24 ( struct V_44 * V_45 )
{
V_47 . V_22 . V_23 = V_45 ;
return F_9 ( & V_47 ) ;
}
static int T_1 F_25 ( char * V_48 )
{
char * V_49 ;
if ( V_48 == NULL )
return 0 ;
V_50 = F_26 ( V_48 , & V_49 ) ;
if ( * V_49 == '@' )
V_51 = F_26 ( V_49 + 1 , NULL ) ;
return 0 ;
}
void T_1 F_27 ( void )
{
int V_30 ;
if ( ! V_51 || ! V_50 ) {
F_12 ( L_4
L_5 ,
V_12 ) ;
return;
}
F_28 ( L_6 ,
V_12 , V_50 , ( unsigned long ) V_51 ) ;
V_30 = F_29 ( & V_52 . V_22 , V_50 , V_51 , 0 ) ;
if ( V_30 )
F_12 ( L_7 , V_12 , V_30 ) ;
}
void T_1 F_27 ( void )
{
}
int T_1 F_30 ( void )
{
int V_30 ;
V_30 = F_9 ( & V_52 ) ;
if ( V_30 )
F_12 ( L_8 , V_12 , V_30 ) ;
return V_30 ;
}
int F_31 ( void )
{
return F_9 ( & V_53 ) ;
}
void T_2 * T_1 F_32 ( void )
{
if ( V_54 )
return V_54 ;
V_54 = F_33 ( V_55 , V_56 ) ;
if ( ! V_54 )
F_7 ( L_9 , V_12 ) ;
return V_54 ;
}
int T_1 F_34 ( void )
{
V_57 . V_58 = F_32 () ;
return F_9 ( & V_59 ) ;
}
int T_1 F_35 ( int V_15 , unsigned V_60 )
{
if ( V_15 < 0 || V_15 > 1 )
return - V_21 ;
V_61 [ V_15 ] . V_60 = V_60 ;
if ( V_15 == 1 && F_36 () ) {
V_62 [ 0 ] . V_63 = V_64 ;
V_62 [ 0 ] . V_65 = V_64 + V_66 - 1 ;
}
return F_9 ( & V_67 [ V_15 ] ) ;
}
int T_1 F_37 ( unsigned long V_68 )
{
F_38 ( V_68 != 100 * 1000 * 1000 ) ;
return F_9 ( & V_69 ) ;
}
int T_1 F_39 ( void )
{
return F_9 ( & V_70 ) ;
}
