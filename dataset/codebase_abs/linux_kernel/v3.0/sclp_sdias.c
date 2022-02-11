static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
V_4 = 1 ;
F_2 ( & V_5 ) ;
F_3 ( L_1 ) ;
}
static int F_4 ( struct V_1 * V_6 )
{
int V_7 ;
int V_8 ;
for ( V_7 = V_9 ; V_7 ; V_7 -- ) {
V_4 = 0 ;
F_3 ( L_2 ) ;
V_8 = F_5 ( V_6 ) ;
if ( V_8 ) {
F_6 ( V_10 ) ;
F_3 ( L_3 , V_8 ) ;
F_7 ( V_11 ) ;
continue;
}
F_8 ( V_5 , ( V_4 == 1 ) ) ;
if ( V_6 -> V_12 == V_13 ) {
F_3 ( L_4 ) ;
V_8 = - V_14 ;
continue;
}
F_3 ( L_5 ) ;
break;
}
return V_8 ;
}
int F_9 ( void )
{
struct V_1 V_2 ;
int V_8 ;
F_10 ( & V_15 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_16 . V_17 . V_18 = sizeof( V_16 ) ;
V_16 . V_19 . V_17 . V_18 = sizeof( struct V_20 ) ;
V_16 . V_19 . V_17 . type = V_21 ;
V_16 . V_19 . V_22 = V_23 ;
V_16 . V_19 . V_24 = V_25 ;
V_16 . V_19 . V_26 = 4712 ;
V_16 . V_19 . V_27 = 1 ;
V_2 . V_16 = & V_16 ;
V_2 . V_28 = V_29 ;
V_2 . V_12 = V_30 ;
V_2 . V_31 = F_1 ;
V_8 = F_4 ( & V_2 ) ;
if ( V_8 ) {
F_11 ( L_6 ) ;
goto V_32;
}
if ( V_16 . V_17 . V_33 != 0x0020 ) {
F_3 ( L_7 , V_16 . V_17 . V_33 ) ;
V_8 = - V_14 ;
goto V_32;
}
switch ( V_16 . V_19 . V_34 ) {
case 0 :
V_8 = V_16 . V_19 . V_35 ;
break;
default:
F_11 ( L_8 ,
V_16 . V_19 . V_34 ) ;
V_8 = - V_14 ;
goto V_32;
}
F_3 ( L_9 , V_8 ) ;
V_32:
F_12 ( & V_15 ) ;
return V_8 ;
}
int F_13 ( void * V_36 , int V_37 , int V_38 )
{
struct V_1 V_2 ;
int V_8 ;
F_10 ( & V_15 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_16 . V_17 . V_18 = sizeof( V_16 ) ;
V_16 . V_19 . V_17 . V_18 = sizeof( struct V_20 ) ;
V_16 . V_19 . V_17 . type = V_21 ;
V_16 . V_19 . V_17 . V_39 = 0 ;
V_16 . V_19 . V_22 = V_40 ;
V_16 . V_19 . V_24 = V_25 ;
V_16 . V_19 . V_26 = 4712 ;
#ifdef F_14
V_16 . V_19 . V_41 = V_42 ;
#else
V_16 . V_19 . V_41 = V_43 ;
#endif
V_16 . V_19 . V_34 = 0 ;
V_16 . V_19 . V_35 = V_38 ;
V_16 . V_19 . V_44 = ( unsigned long ) V_36 ;
V_16 . V_19 . V_45 = V_37 ;
V_16 . V_19 . V_46 = 0 ;
V_16 . V_19 . V_27 = 1 ;
V_2 . V_16 = & V_16 ;
V_2 . V_28 = V_29 ;
V_2 . V_12 = V_30 ;
V_2 . V_31 = F_1 ;
V_8 = F_4 ( & V_2 ) ;
if ( V_8 ) {
F_11 ( L_10 , V_8 ) ;
goto V_32;
}
if ( V_16 . V_17 . V_33 != 0x0020 ) {
F_3 ( L_11 , V_16 . V_17 . V_33 ) ;
V_8 = - V_14 ;
goto V_32;
}
switch ( V_16 . V_19 . V_34 ) {
case V_47 :
F_3 ( L_12 ) ;
case V_48 :
F_3 ( L_13 , V_16 . V_19 . V_35 ) ;
break;
case V_49 :
F_3 ( L_14 ) ;
default:
F_11 ( L_15
L_16 ,
V_16 . V_19 . V_34 ) ;
V_8 = - V_14 ;
}
V_32:
F_12 ( & V_15 ) ;
return V_8 ;
}
int T_1 F_15 ( void )
{
int V_8 ;
if ( V_50 . type != V_51 )
return 0 ;
V_52 = F_16 ( L_17 , 4 , 1 , 4 * sizeof( long ) ) ;
F_17 ( V_52 , & V_53 ) ;
F_18 ( V_52 , 6 ) ;
V_8 = F_19 ( & V_54 ) ;
if ( V_8 )
return V_8 ;
F_20 ( & V_5 ) ;
F_3 ( L_18 ) ;
return 0 ;
}
void T_2 F_21 ( void )
{
F_22 ( V_52 ) ;
F_23 ( & V_54 ) ;
}
