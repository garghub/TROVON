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
static int F_18 ( char * V_38 , char * * V_39 , T_2 V_40 ,
int V_41 , int * V_42 , void * V_43 )
{
char * V_44 = V_38 ;
int V_45 , V_46 ;
unsigned long V_47 ;
T_3 V_48 ;
V_46 = F_19 ( & V_47 ) ;
if ( V_46 != V_49 )
return - V_50 ;
V_48 = ( V_47 & 0xFFFFFFFF ) ;
if ( ( V_48 >> 24 ) & 0xFF )
V_44 += sprintf ( V_44 , L_6 , ( ( V_48 >> 24 ) & 0xFF ) ) ;
V_44 += sprintf ( V_44 , L_7 , ( V_48 & 0x04 ) ? L_8 : L_9 ) ;
V_44 += sprintf ( V_44 , L_10 , ( V_48 & 0x02 ) ? L_11 : L_9 ) ;
V_44 += sprintf ( V_44 , L_12 , ( V_48 & 0x01 ) ? L_11 : L_9 ) ;
V_45 = V_44 - V_38 - V_40 ;
if ( V_45 < V_41 ) {
* V_42 = 1 ;
if ( V_45 <= 0 ) return 0 ;
} else {
V_45 = V_41 ;
}
* V_39 = V_38 + V_40 ;
return V_45 ;
}
static int T_1 F_20 ( void )
{
unsigned long V_51 ;
int V_46 ;
V_46 = F_19 ( & V_51 ) ;
if ( ( V_46 == V_52 ) || ( V_46 == V_53 ) ) {
F_10 ( V_11 L_13 ) ;
return 0 ;
}
F_10 ( V_11 L_14 ,
V_12 ) ;
F_21 ( L_15 , 0400 , NULL , F_18 ,
NULL ) ;
return 0 ;
}
