void
F_1 ( T_1 V_1 , const char * V_2 )
{
int V_3 , type ;
char * V_4 = NULL ;
const char * V_5 ;
V_3 = F_2 ( V_1 ) ;
type = F_3 ( V_1 ) ;
V_5 = F_4 ( F_5 ( V_6 ) ) ;
switch( type ) {
case V_7 :
V_4 = F_6 ( V_2 ) ;
break;
case V_8 :
V_4 = F_7 ( L_1 , V_2 ) ;
break;
case V_9 :
if ( ( ! V_5 ) || ( 0 == strlen ( V_5 ) ) )
V_4 = F_6 ( V_2 ) ;
else
V_4 = F_7 ( L_2 , V_5 , V_2 ) ;
break;
case V_10 :
if ( ( ! V_5 ) || ( 0 == strlen ( V_5 ) ) )
V_4 = F_6 ( V_2 ) ;
else
V_4 = F_7 ( L_3 , V_5 , V_2 ) ;
break;
case V_11 :
if ( ( ! V_5 ) || ( 0 == strlen ( V_5 ) ) )
V_4 = F_7 ( L_1 , V_2 ) ;
else
V_4 = F_7 ( L_4 , V_5 , V_2 ) ;
break;
case V_12 :
if ( ( ! V_5 ) || ( 0 == strlen ( V_5 ) ) )
V_4 = F_7 ( L_1 , V_2 ) ;
else
V_4 = F_7 ( L_5 , V_5 , V_2 ) ;
break;
}
switch( V_3 ) {
case V_13 :
F_8 ( F_5 ( V_6 ) , V_4 ) ;
F_9 ( & V_14 , V_4 , FALSE ) ;
F_10 ( F_11 ( V_15 ) ) ;
break;
case V_16 :
F_8 ( F_5 ( V_6 ) , V_4 ) ;
break;
case V_17 :
F_12 ( V_4 ) ;
break;
case V_18 :
F_13 ( & V_14 , V_4 , V_19 ) ;
break;
case V_20 :
F_13 ( & V_14 , V_4 , V_21 ) ;
break;
case V_22 :
F_14 ( V_4 ) ;
break;
}
F_15 ( V_4 ) ;
}
