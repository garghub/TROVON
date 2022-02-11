static void F_1 ( T_1 * V_1 )
{
F_2 ( L_1 ) ;
if ( ! V_1 ) {
F_2 ( L_2
L_3 , ( V_2 ) V_1 ) ;
return;
}
if ( V_1 -> V_3 ) {
F_2 ( L_4
L_5 ) ;
if ( F_3 ( V_1 -> V_3 ) !=
V_4 ) {
F_2 (
L_6 ) ;
}
}
if ( V_1 -> V_5 ) {
#ifdef F_4
if ( F_5 ( V_6 ,
V_1 -> V_5 ) != 0 )
F_2 ( L_7
L_8 ) ;
#endif
}
F_2 ( L_9 ) ;
F_6 ( V_1 ) ;
V_7 = NULL ;
F_2 ( L_10 ) ;
}
static void F_7 ( T_2 V_8 ,
T_3 V_9 , void * V_10 )
{
( void ) V_8 ;
( void ) V_10 ;
switch ( V_9 ) {
case V_11 :
F_2 ( L_4
L_11 ) ;
V_12 = 1 ;
break;
case V_13 :
F_2 ( L_4
L_12 ) ;
V_12 = 1 ;
break;
default:
break;
}
}
void F_8 ()
{
F_9 ( & V_7 -> V_14 ,
V_7 -> V_15 ) ;
}
void F_10 ()
{
F_11 ( & V_7 -> V_14 ,
V_7 -> V_15 ) ;
}
void F_12 ( T_4 V_16 )
{
F_2 ( L_13
L_14 ) ;
F_13 ( V_16 , V_17 ,
V_18 ) ;
F_14 ( 60 ) ;
F_2 ( L_15
L_16 ,
F_15 ( V_16 , V_19 ) ,
F_15 ( V_16 , V_20 )
) ;
F_13 ( V_16 , V_20 ,
V_21 ) ;
}
static int T_5 F_16 ( struct V_22 * V_23 )
{
F_2 ( L_17 , V_24 ) ;
return 0 ;
}
static int T_6 F_17 ( struct V_22 * V_23 )
{
F_2 ( L_17 , V_24 ) ;
return 0 ;
}
static int F_18 ( void )
{
T_1 * V_1 = 0 ;
int V_25 = 0 ;
int V_26 = 0 ;
T_7 V_27 ;
T_8 V_28 ;
T_9 V_29 = { 0 } ;
const char * V_30 = L_18 ;
int V_31 ;
const struct V_32 * V_33 ;
V_12 = 0 ;
F_19 ( 8 ) ;
F_2 ( L_19 ) ;
if ( V_7 != 0 ) {
F_2 ( L_20
L_21 ) ;
return - V_34 ;
}
V_1 = F_20 ( sizeof( T_1 ) ) ;
if ( V_1 == NULL ) {
F_2 ( L_4
L_22 ) ;
return - V_35 ;
}
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
#ifdef F_4
if ( ! F_21 ( V_6 ,
& ( V_1 -> V_5 ) , V_36 ) ) {
F_2 (
L_23 ) ;
goto V_37;
}
#endif
if ( F_22 ( & ( V_1 -> V_3 ) ,
V_1 -> V_5 ) != V_4 ) {
F_2 (
L_24 ) ;
goto V_37;
}
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_38 = V_39 ;
V_25 = F_23 ( V_1 -> V_3 , & V_27 ) ;
if ( V_25 != V_4 ) {
F_2 (
L_25
L_26 , V_25 ) ;
goto V_37;
}
V_25 = F_24 ( V_1 -> V_3 ,
F_7 ) ;
if ( V_25 != V_4 ) {
F_2 ( L_4
L_27
L_28 , V_25 ) ;
goto V_37;
}
V_25 = F_25 ( & V_40 ) ;
if ( F_26 ( V_25 < 0 ) )
return V_25 ;
V_41 = F_27 (
L_29 , - 1 , NULL , 0 ) ;
if ( F_28 ( V_41 ) ) {
F_29 ( & V_40 ) ;
return F_30 ( V_41 ) ;
}
V_25 = F_31 ( & V_33 ,
L_30 , & V_41 -> V_42 ) ;
if ( V_25 ) {
F_2 ( L_31
L_32 , V_25 ) ;
} else {
F_2 ( L_31
L_33 , V_25 , V_33 -> V_43 ) ;
V_25 = F_32 (
V_1 -> V_3 ,
V_33 -> V_44 ,
V_33 -> V_43 ,
0 , 0 ) ;
}
if ( V_25 != V_4 ) {
F_2 ( L_34
L_35 , V_25 ) ;
goto V_37;
}
V_31 = 50 ;
F_33 ( & V_28 ) ;
while ( ! V_12 ) {
F_34 ( & V_28 , 100 ) ;
if ( V_31 -- <= 0 ) {
F_2 (
L_36
L_37 ) ;
break;
}
}
F_35 ( & V_28 ) ;
if ( V_31 > 0 )
F_2 (
L_38 ) ;
V_25 = F_36 ( V_1 -> V_3 ,
& V_29 , 0 , 0 ) ;
if ( V_25 != V_4 ) {
F_2 ( L_39
L_40 , V_25 ) ;
goto V_37;
}
if ( ( V_29 . V_45 & 0x01 ) && ( V_29 . V_45 & 0x06 ) )
V_30 = L_41 ;
else if ( ( V_29 . V_45 & 0x01 ) && ( V_29 . V_45 & 0x08 ) )
V_30 = L_42 ;
else if ( V_29 . V_45 & 0x01 )
V_30 = L_43 ;
else if ( V_29 . V_45 & 0x08 )
V_30 = L_44 ;
else
V_30 = L_45 ;
F_2 ( L_46
L_47 ,
( ( V_29 . V_46 ) ? L_48 : L_49 ) ,
V_29 . V_47 , V_29 . V_48 , V_29 . V_49 , V_30 ) ;
F_37 ( & V_1 -> V_14 ) ;
V_7 = V_1 ;
return 0 ;
V_37:
if ( V_1 )
F_1 ( V_1 ) ;
return - V_50 ;
}
T_2 F_38 ( void )
{
if ( V_7 ) {
#ifdef F_4
F_39 () ;
#endif
return V_7 -> V_3 ;
}
return NULL ;
}
T_4 F_40 ( void )
{
if ( V_7 )
return ( T_4 )
V_7 -> V_5 ;
return NULL ;
}
static int T_10 F_41 ( void )
{
if ( F_18 () != 0 )
return - V_51 ;
return 0 ;
}
static void T_11 F_42 ( void )
{
F_1 ( V_7 ) ;
}
