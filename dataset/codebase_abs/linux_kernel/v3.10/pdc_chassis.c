static int T_1 F_1 ( char * V_1 )
{
F_2 ( & V_1 , & V_2 ) ;
return 1 ;
}
static int F_3 ( struct V_3 * V_4 ,
unsigned long V_5 , void * V_6 )
{
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_5 ( struct V_3 * V_4 ,
unsigned long V_5 , void * V_6 )
{
F_4 ( V_9 ) ;
return V_8 ;
}
void T_1 F_6 ( void )
{
#ifdef F_7
if ( F_8 ( V_2 ) ) {
F_9 ( V_10 L_1 , __FILE__ ) ;
F_10 ( V_11 L_2 ,
F_11 () ? L_3 : L_4 ,
V_12 ) ;
F_12 ( & V_13 ,
& V_14 ) ;
F_13 ( & V_15 ) ;
}
#endif
}
int F_4 ( int V_16 )
{
int V_17 = 0 ;
#ifdef F_7
if ( F_8 ( V_2 ) ) {
F_9 ( V_10 L_5 , __FILE__ , V_16 ) ;
#ifdef F_14
if ( F_11 () ) {
switch( V_16 ) {
case V_18 :
V_17 = F_15 ( V_19 , V_20 ) ;
break;
case V_21 :
V_17 = F_15 ( V_22 , V_20 ) ;
break;
case V_9 :
V_17 = F_15 ( V_23 , V_24 ) ;
break;
case V_7 :
V_17 = F_15 ( V_25 , V_26 ) ;
break;
case V_27 :
V_17 = F_15 ( V_28 , V_29 ) ;
break;
case V_30 :
V_17 = F_15 ( V_31 , V_32 ) ;
break;
default:
V_17 = - 1 ;
}
} else V_17 = - 1 ;
#else
if ( 1 ) {
switch ( V_16 ) {
case V_18 :
V_17 = F_16 ( F_17 ( V_33 ) ) ;
break;
case V_21 :
V_17 = F_16 ( F_17 ( V_34 ) ) ;
break;
case V_9 :
V_17 = F_16 ( F_17 ( V_35 ) ) ;
break;
case V_30 :
case V_7 :
V_17 = F_16 ( F_17 ( V_36 ) ) ;
break;
case V_27 :
V_17 = F_16 ( F_17 ( V_37 ) ) ;
break;
default:
V_17 = - 1 ;
}
} else V_17 = - 1 ;
#endif
}
#endif
return V_17 ;
}
static int F_18 ( struct V_38 * V_39 , void * V_40 )
{
unsigned long V_41 ;
T_2 V_42 ;
if ( F_19 ( & V_41 ) != V_43 )
return - V_44 ;
V_42 = ( V_41 & 0xFFFFFFFF ) ;
if ( ( V_42 >> 24 ) & 0xFF )
F_20 ( V_39 , L_6 ,
( V_42 >> 24 ) & 0xFF ) ;
F_20 ( V_39 , L_7 , ( V_42 & 0x04 ) ? L_8 : L_9 ) ;
F_20 ( V_39 , L_10 , ( V_42 & 0x02 ) ? L_11 : L_9 ) ;
F_20 ( V_39 , L_12 , ( V_42 & 0x01 ) ? L_11 : L_9 ) ;
return 0 ;
}
static int F_21 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_22 ( V_46 , F_18 , NULL ) ;
}
static int T_1 F_23 ( void )
{
unsigned long V_47 ;
int V_48 ;
V_48 = F_19 ( & V_47 ) ;
if ( ( V_48 == V_49 ) || ( V_48 == V_50 ) ) {
F_10 ( V_11 L_13 ) ;
return 0 ;
}
F_10 ( V_11 L_14 ,
V_12 ) ;
F_24 ( L_15 , 0400 , NULL , & V_51 ) ;
return 0 ;
}
