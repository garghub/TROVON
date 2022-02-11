static void F_1 ( void )
{
F_2 ( 55 , V_1 ) ;
return;
}
static void F_3 ( unsigned long V_2 )
{
F_1 () ;
F_4 ( & V_3 , V_4 + 5 * V_5 ) ;
}
static int F_5 ( struct V_6 * V_6 , struct V_7 * V_7 )
{
if ( F_6 ( 0 , & V_8 ) )
return - V_9 ;
F_1 () ;
if ( V_10 )
F_7 ( V_11 ) ;
else {
if ( V_12 ) {
F_8 ( & V_3 ) ;
V_12 = 0 ;
}
}
return F_9 ( V_6 , V_7 ) ;
}
static int F_10 ( struct V_6 * V_6 , struct V_7 * V_7 )
{
if ( V_13 == 42 ) {
if ( V_12 ) {
F_11 ( L_1 ) ;
return - V_9 ;
}
V_12 = 1 ;
F_4 ( & V_3 , V_4 + 5 * V_5 ) ;
} else
F_12 ( L_2 ) ;
F_13 ( 0 , & V_8 ) ;
V_13 = 0 ;
return 0 ;
}
static T_1 F_14 ( struct V_7 * V_7 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
if ( V_15 ) {
if ( ! V_10 ) {
T_3 V_17 ;
V_13 = 0 ;
for ( V_17 = 0 ; V_17 != V_15 ; V_17 ++ ) {
char V_18 ;
if ( F_15 ( V_18 , V_14 + V_17 ) )
return - V_19 ;
if ( V_18 == 'V' )
V_13 = 42 ;
}
}
F_1 () ;
}
return V_15 ;
}
static long F_16 ( struct V_7 * V_7 ,
unsigned int V_20 , unsigned long V_21 )
{
void T_2 * V_22 = ( void T_2 * ) V_21 ;
int T_2 * V_23 = V_22 ;
int V_24 ;
static const struct V_25 V_26 = {
. V_27 = V_28 | V_29 ,
. V_30 = 1 ,
. V_31 = L_3 ,
} ;
switch ( V_20 ) {
case V_32 :
if ( F_17 ( V_22 , & V_26 , sizeof( V_26 ) ) )
return - V_19 ;
break;
case V_33 :
V_24 = V_8 ;
if ( ! V_10 )
V_24 |= V_12 ;
return F_18 ( V_24 , V_23 ) ;
case V_34 :
return F_18 ( 0 , V_23 ) ;
case V_35 :
F_1 () ;
break;
default:
return - V_36 ;
}
return 0 ;
}
static int T_5 F_19 ( int V_37 , int V_38 )
{
int V_39 ;
if ( ! F_20 ( V_37 , 1 , L_3 ) )
return 0 ;
V_39 = F_21 ( V_37 ) ;
if ( V_38 == V_40 )
V_39 &= 0x3f ;
if ( V_39 != V_38 ) {
F_22 ( V_37 , 1 ) ;
return 0 ;
}
return 1 ;
}
static int T_5 F_23 ( void )
{
int V_17 , V_41 , V_42 = 0 ;
for ( V_17 = 0 ; ! V_42 && V_43 [ V_17 ] . V_44 != 0 ; V_17 ++ ) {
if ( F_19 ( V_43 [ V_17 ] . V_44 ,
V_43 [ V_17 ] . V_39 ) ) {
V_42 = 1 ;
V_1 = V_43 [ V_17 ] . V_44 ;
}
}
if ( ! V_42 ) {
F_11 ( L_4 ) ;
return - V_45 ;
}
V_41 = F_24 ( & V_46 ) ;
if ( V_41 ) {
F_11 ( L_5 ,
V_47 , V_41 ) ;
goto V_48;
}
F_25 ( L_6 ,
V_49 , V_1 ) ;
return 0 ;
V_48:
F_22 ( V_1 , 1 ) ;
V_1 = 0x0000 ;
return V_41 ;
}
static void T_6 F_26 ( void )
{
if ( ! V_10 ) {
if ( V_12 ) {
F_27 ( L_7 ) ;
F_28 ( & V_3 ) ;
V_12 = 0 ;
}
}
F_29 ( & V_46 ) ;
F_22 ( V_1 , 1 ) ;
}
