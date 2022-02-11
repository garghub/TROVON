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
V_25 . V_31 = 0 ;
F_13 ( & V_25 , V_32 ) ;
V_26 = F_1 ( V_23 ) ;
F_13 ( & V_25 , V_33 ) ;
F_14 ( & V_28 ) ;
return V_26 ;
}
static unsigned int F_15 ( unsigned int V_31 )
{
return V_15 [ V_13 ] . V_16 ;
}
static int F_16 ( struct V_19 * V_20 )
{
V_20 -> V_34 . V_35 = 12000 ;
V_20 -> V_36 = V_15 [ F_7 () ] . V_16 ;
F_17 ( V_20 -> V_37 , V_38 ) ;
F_18 ( V_15 , V_20 -> V_31 ) ;
return F_19 ( V_20 ,
V_15 ) ;
}
static int T_1 F_20 ( void )
{
struct V_39 * V_37 ;
struct V_39 * V_40 ;
unsigned int V_41 ;
unsigned long V_42 ;
const T_2 * V_43 ;
T_2 V_44 ;
int V_26 = - V_45 ;
if ( ! F_21 ( L_1 ) &&
! F_21 ( L_2 ) )
return 0 ;
V_37 = F_22 ( L_3 ) ;
if ( V_37 == NULL ) {
F_23 ( L_4 ) ;
return - V_45 ;
}
for ( V_40 = NULL ;
( V_40 = F_24 ( V_37 , V_40 ) ) != NULL ; ) {
const T_2 * V_46 = F_25 ( V_40 , L_5 , NULL ) ;
if ( V_46 == NULL || ( * V_46 ) != 0 )
continue;
if ( ! strcmp ( V_40 -> type , L_6 ) )
break;
}
if ( V_40 == NULL ) {
F_26 ( V_47 L_7 ) ;
goto V_48;
}
V_44 = F_27 ( F_28 ( V_49 ) ) ;
if ( V_44 != 0x3c && V_44 != 0x44 ) {
F_26 ( V_47 L_8 ,
V_44 ) ;
goto V_50;
}
V_6 = F_25 ( V_40 , L_9 , & V_41 ) ;
if ( ! V_6 ) {
F_23 ( L_10 ) ;
goto V_50;
}
V_18 = V_41 / sizeof( T_2 ) - 1 ;
V_43 = F_25 ( V_40 , L_11 , NULL ) ;
if ( ! V_43 )
return - V_45 ;
V_42 = ( * V_43 ) / 1000 ;
V_15 [ 0 ] . V_16 = V_42 ;
V_15 [ 1 ] . V_16 = V_42 / 2 ;
F_29 ( 10 ) ;
V_13 = - 1 ;
F_1 ( F_7 () ) ;
F_26 ( V_51 L_12 ) ;
F_26 ( V_51 L_13 ,
V_15 [ 1 ] . V_16 / 1000 ,
V_15 [ 0 ] . V_16 / 1000 ,
V_15 [ V_13 ] . V_16 / 1000 ) ;
V_26 = F_30 ( & V_52 ) ;
F_31 ( V_40 ) ;
F_31 ( V_37 ) ;
return V_26 ;
V_50:
F_31 ( V_40 ) ;
V_48:
F_31 ( V_37 ) ;
return V_26 ;
}
