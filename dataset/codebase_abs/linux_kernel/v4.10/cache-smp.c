void F_1 ( void )
{
unsigned long V_1 = V_2 ;
switch ( (enum V_3 ) ( V_1 & V_4 ) ) {
case V_5 :
break;
case V_6 :
F_2 () ;
break;
case V_7 :
F_3 ( V_8 , V_9 ) ;
break;
case V_10 :
F_4 () ;
break;
case V_11 :
F_5 ( V_8 ,
V_9 ) ;
break;
case V_12 :
F_6 () ;
break;
case V_13 :
F_7 ( V_8 ,
V_9 ) ;
break;
}
switch ( (enum V_14 ) ( V_1 & V_15 ) ) {
case V_16 :
break;
case V_17 :
F_8 () ;
break;
case V_18 :
F_9 ( V_8 , V_9 ) ;
break;
}
F_10 ( F_11 () , & V_19 ) ;
}
void F_12 ( unsigned long V_1 ,
unsigned long V_20 , unsigned long V_21 )
{
V_2 = V_1 ;
V_8 = V_20 ;
V_9 = V_21 ;
F_13 ( & V_19 , V_22 ) ;
F_10 ( F_11 () , & V_19 ) ;
F_14 ( V_23 ) ;
while ( ! F_15 ( & V_19 ) )
F_16 () ;
}
