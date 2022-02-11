int F_1 ( unsigned long * V_1 )
{
int V_2 = 0 ;
#ifdef F_2
V_2 = F_3 ( V_1 ) ;
#else
#if F_4 ( V_3 )
if ( V_4 < 0 )
V_4 = V_3 ;
#endif
if ( V_4 < 0 ) {
F_5 ( L_1 ,
V_5 ) ;
return V_4 ;
}
F_5 ( L_2 ,
V_5 , V_4 ) ;
#if F_4 V_6
V_2 = F_6 ( V_4 ) ;
#elif F_4 V_7
F_7 ( V_4 , L_3 ) ;
V_2 = F_8 ( V_4 ) ;
F_9 ( V_4 ) ;
#endif
#endif
return V_2 ;
}
void F_10 ( int V_8 )
{
switch ( V_8 ) {
case V_9 :
F_11 ( L_4 ,
V_5 ) ;
#ifdef V_6
F_12 ( 2 ) ;
#endif
#ifdef F_2
F_13 ( 0 , 0 ) ;
#endif
F_5 ( L_5 ) ;
break;
case V_10 :
F_11 ( L_6 ,
V_5 ) ;
#ifdef V_6
F_14 ( 2 ) ;
#endif
#ifdef F_2
F_13 ( 1 , 0 ) ;
#endif
F_5 ( L_7 ) ;
break;
case V_11 :
F_11 ( L_8 ,
V_5 ) ;
#ifdef V_6
F_12 ( 1 ) ;
#endif
break;
case V_12 :
F_11 ( L_9 ,
V_5 ) ;
#ifdef V_6
F_14 ( 1 ) ;
#endif
F_15 ( 200 ) ;
break;
}
}
int F_16 ( unsigned char * V_13 )
{
F_11 ( L_10 , V_5 ) ;
if ( ! V_13 )
return - V_14 ;
#ifdef F_17
{
T_1 V_15 [ V_16 ] = { 0x00 , 0x11 , 0x22 , 0x33 , 0x44 , 0xFF } ;
memcpy ( V_13 , V_15 , V_16 ) ;
}
#endif
return 0 ;
}
