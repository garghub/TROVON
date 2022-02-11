static unsigned int F_1 ( T_1 * V_1 , const char * V_2 , char * V_3 ,
unsigned int V_4 ,
unsigned char * V_5 ,
unsigned int V_6 )
{
return 0 ;
}
static char * F_2 ( T_1 * V_1 , void * V_7 )
{
return L_1 ;
}
int F_3 ( int V_8 , char * * V_9 )
{
T_2 * V_10 = NULL ;
T_1 * V_1 = NULL ;
F_4 ( V_11 ) * V_12 = NULL ;
const T_3 * V_13 = F_5 () ;
int V_14 = 1 , V_15 , V_16 = 0 , V_17 = 0 , V_18 = 0 ;
#ifndef F_6
int V_19 = 0 ;
#endif
#ifndef F_7
int V_5 = 0 ;
#endif
#ifndef F_8
int V_20 = 0 ;
#endif
const char * V_21 ;
char * V_22 = NULL , * V_23 ;
char V_24 [ 512 ] ;
T_4 V_25 ;
int V_26 = 0 , V_27 = 0 ;
V_23 = F_9 ( V_8 , V_9 , V_28 ) ;
while ( ( V_25 = F_10 () ) != V_29 ) {
switch ( V_25 ) {
case V_29 :
case V_30 :
V_31:
F_11 ( V_32 , L_2 , V_23 ) ;
goto V_33;
case V_34 :
F_12 ( V_28 ) ;
V_14 = 0 ;
goto V_33;
case V_35 :
V_16 = 1 ;
break;
case V_36 :
V_16 = V_17 = 1 ;
break;
case V_37 :
V_18 = 1 ;
break;
case V_38 :
#ifndef F_6
V_19 = V_16 = 1 ;
#endif
break;
case V_39 :
V_26 = V_40 ;
V_27 = V_40 ;
break;
case V_41 :
V_26 = V_42 ;
V_27 = V_42 ;
break;
case V_43 :
V_26 = V_44 ;
V_27 = V_44 ;
break;
case V_45 :
V_26 = V_46 ;
V_27 = V_46 ;
break;
case V_47 :
#ifndef F_7
V_5 = 1 ;
#endif
break;
case V_48 :
#ifndef F_8
V_20 = 1 ;
#endif
break;
}
}
V_9 = F_13 () ;
V_8 = F_14 () ;
if ( V_8 == 1 )
V_22 = * V_9 ;
else if ( V_8 != 0 )
goto V_31;
V_10 = F_15 ( V_13 ) ;
if ( V_10 == NULL )
goto V_49;
if ( F_16 ( V_10 , V_26 ) == 0 )
goto V_49;
if ( F_17 ( V_10 , V_27 ) == 0 )
goto V_49;
#ifndef F_7
if ( V_5 )
F_18 ( V_10 , F_1 ) ;
#endif
#ifndef F_8
if ( V_20 )
F_19 ( V_10 , F_2 ) ;
#endif
if ( V_22 != NULL ) {
if ( ! F_20 ( V_10 , V_22 ) ) {
F_11 ( V_32 , L_3 ) ;
goto V_49;
}
}
V_1 = F_21 ( V_10 ) ;
if ( V_1 == NULL )
goto V_49;
if ( V_18 )
V_12 = F_22 ( V_1 ) ;
else
V_12 = F_23 ( V_1 ) ;
if ( ! V_16 ) {
for ( V_15 = 0 ; V_15 < F_24 ( V_12 ) ; V_15 ++ ) {
const V_11 * V_50 = F_25 ( V_12 , V_15 ) ;
V_21 = F_26 ( V_50 ) ;
if ( V_21 == NULL )
break;
if ( V_15 != 0 )
F_11 ( V_51 , L_4 ) ;
F_11 ( V_51 , L_5 , V_21 ) ;
}
F_11 ( V_51 , L_6 ) ;
} else {
for ( V_15 = 0 ; V_15 < F_24 ( V_12 ) ; V_15 ++ ) {
const V_11 * V_50 ;
V_50 = F_25 ( V_12 , V_15 ) ;
if ( V_17 ) {
unsigned long V_52 = F_27 ( V_50 ) ;
int V_53 = ( int ) ( V_52 >> 24 ) ;
int V_54 = ( int ) ( ( V_52 >> 16 ) & 0xffL ) ;
int V_55 = ( int ) ( ( V_52 >> 8 ) & 0xffL ) ;
int V_56 = ( int ) ( V_52 & 0xffL ) ;
if ( ( V_52 & 0xff000000L ) == 0x03000000L )
F_11 ( V_51 , L_7 , V_55 , V_56 ) ;
else
F_11 ( V_51 , L_8 , V_53 , V_54 , V_55 , V_56 ) ;
}
#ifndef F_6
if ( V_19 ) {
const char * V_57 = F_28 ( V_50 ) ;
if ( V_57 == NULL )
V_57 = L_9 ;
F_11 ( V_51 , L_10 , V_57 ) ;
}
#endif
F_29 ( V_51 , F_30 ( V_50 , V_24 , sizeof V_24 ) ) ;
}
}
V_14 = 0 ;
goto V_33;
V_49:
F_31 ( V_32 ) ;
V_33:
if ( V_18 )
F_32 ( V_12 ) ;
F_33 ( V_10 ) ;
F_34 ( V_1 ) ;
return ( V_14 ) ;
}
