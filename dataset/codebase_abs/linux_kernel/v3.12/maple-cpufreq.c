static int F_1 ( int V_1 )
{
unsigned long V_2 ;
int V_3 ;
F_2 ( V_2 ) ;
F_3 ( V_4 , 0 ) ;
F_3 ( V_4 , V_5 | 0 ) ;
F_3 ( V_4 , V_5 |
V_6 [ V_1 ] ) ;
for ( V_3 = 0 ; V_3 < 10 ; V_3 ++ ) {
unsigned long V_7 = F_4 ( V_8 ) ;
if ( ( V_7 & V_9 ) == 0 &&
( ( ( V_7 >> V_10 ) ^
( V_6 [ V_1 ] >> V_11 ) ) & 0x3 )
== 0 )
break;
if ( V_7 & V_12 )
break;
F_5 ( 100 ) ;
}
F_6 ( V_2 ) ;
V_13 = V_1 ;
V_14 = V_15 [ V_1 ] . V_16 * 1000ul ;
return 0 ;
}
static int F_7 ( void )
{
unsigned long V_7 = F_4 ( V_8 ) ;
int V_17 ;
for ( V_17 = 0 ; V_17 <= V_18 ; V_17 ++ )
if ( ( ( ( V_7 >> V_10 ) ^
( V_6 [ V_17 ] >> V_11 ) ) & 0x3 ) == 0 )
break;
return V_17 ;
}
static int F_8 ( struct V_19 * V_20 )
{
return F_9 ( V_20 , V_15 ) ;
}
static int F_10 ( struct V_19 * V_20 ,
unsigned int V_21 , unsigned int V_22 )
{
unsigned int V_23 = 0 ;
struct V_24 V_25 ;
int V_26 ;
if ( F_11 ( V_20 , V_15 ,
V_21 , V_22 , & V_23 ) )
return - V_27 ;
if ( V_13 == V_23 )
return 0 ;
F_12 ( & V_28 ) ;
V_25 . V_29 = V_15 [ V_13 ] . V_16 ;
V_25 . V_30 = V_15 [ V_23 ] . V_16 ;
F_13 ( V_20 , & V_25 , V_31 ) ;
V_26 = F_1 ( V_23 ) ;
F_13 ( V_20 , & V_25 , V_32 ) ;
F_14 ( & V_28 ) ;
return V_26 ;
}
static unsigned int F_15 ( unsigned int V_33 )
{
return V_15 [ V_13 ] . V_16 ;
}
static int F_16 ( struct V_19 * V_20 )
{
V_20 -> V_34 . V_35 = 12000 ;
V_20 -> V_36 = V_15 [ F_7 () ] . V_16 ;
F_17 ( V_20 -> V_37 ) ;
F_18 ( V_15 , V_20 -> V_33 ) ;
return F_19 ( V_20 ,
V_15 ) ;
}
static int T_1 F_20 ( void )
{
struct V_38 * V_39 ;
unsigned int V_40 ;
unsigned long V_41 ;
const T_2 * V_42 ;
T_2 V_43 ;
int V_26 = - V_44 ;
if ( ! F_21 ( L_1 ) &&
! F_21 ( L_2 ) )
return 0 ;
V_39 = F_22 ( 0 ) ;
if ( V_39 == NULL ) {
F_23 ( V_45 L_3 ) ;
goto V_46;
}
V_43 = F_24 ( F_25 ( V_47 ) ) ;
if ( V_43 != 0x3c && V_43 != 0x44 ) {
F_23 ( V_45 L_4 ,
V_43 ) ;
goto V_46;
}
V_6 = F_26 ( V_39 , L_5 , & V_40 ) ;
if ( ! V_6 ) {
F_27 ( L_6 ) ;
goto V_46;
}
V_18 = V_40 / sizeof( T_2 ) - 1 ;
V_42 = F_26 ( V_39 , L_7 , NULL ) ;
if ( ! V_42 )
return - V_44 ;
V_41 = ( * V_42 ) / 1000 ;
V_15 [ 0 ] . V_16 = V_41 ;
V_15 [ 1 ] . V_16 = V_41 / 2 ;
F_28 ( 10 ) ;
V_13 = - 1 ;
F_1 ( F_7 () ) ;
F_23 ( V_48 L_8 ) ;
F_23 ( V_48 L_9 ,
V_15 [ 1 ] . V_16 / 1000 ,
V_15 [ 0 ] . V_16 / 1000 ,
V_15 [ V_13 ] . V_16 / 1000 ) ;
V_26 = F_29 ( & V_49 ) ;
F_30 ( V_39 ) ;
return V_26 ;
V_46:
F_30 ( V_39 ) ;
return V_26 ;
}
