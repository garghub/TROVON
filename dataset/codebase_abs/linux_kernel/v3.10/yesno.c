static void F_1 ( T_1 * V_1 , int V_2 , int V_3 , int V_4 )
{
int V_5 = V_3 / 2 - 10 ;
int V_6 = V_2 - 2 ;
F_2 ( V_1 , F_3 ( L_1 ) , V_6 , V_5 , V_4 == 0 ) ;
F_2 ( V_1 , F_3 ( L_2 ) , V_6 , V_5 + 13 , V_4 == 1 ) ;
F_4 ( V_1 , V_6 , V_5 + 1 + 13 * V_4 ) ;
F_5 ( V_1 ) ;
}
int F_6 ( const char * V_7 , const char * V_8 , int V_2 , int V_3 )
{
int V_9 , V_5 , V_6 , V_10 = 0 , V_11 = 0 ;
T_1 * V_1 ;
V_12:
if ( F_7 ( V_13 ) < ( V_2 + 4 ) )
return - V_14 ;
if ( F_8 ( V_13 ) < ( V_3 + 4 ) )
return - V_14 ;
V_5 = ( V_15 - V_3 ) / 2 ;
V_6 = ( V_16 - V_2 ) / 2 ;
F_9 ( V_13 , V_6 , V_5 , V_2 , V_3 ) ;
V_1 = F_10 ( V_2 , V_3 , V_6 , V_5 ) ;
F_11 ( V_1 , TRUE ) ;
F_12 ( V_1 , 0 , 0 , V_2 , V_3 ,
V_17 . V_1 . V_18 , V_17 . V_19 . V_18 ) ;
F_13 ( V_1 , V_17 . V_19 . V_18 ) ;
F_14 ( V_1 , V_2 - 3 , 0 , V_20 ) ;
for ( V_9 = 0 ; V_9 < V_3 - 2 ; V_9 ++ )
F_15 ( V_1 , V_21 ) ;
F_13 ( V_1 , V_17 . V_1 . V_18 ) ;
F_15 ( V_1 , V_22 ) ;
F_16 ( V_1 , V_7 , V_3 ) ;
F_13 ( V_1 , V_17 . V_1 . V_18 ) ;
F_17 ( V_1 , V_8 , V_3 - 2 , 1 , 3 ) ;
F_1 ( V_1 , V_2 , V_3 , 0 ) ;
while ( V_10 != V_23 ) {
V_10 = F_18 ( V_1 ) ;
switch ( V_10 ) {
case 'Y' :
case 'y' :
F_19 ( V_1 ) ;
return 0 ;
case 'N' :
case 'n' :
F_19 ( V_1 ) ;
return 1 ;
case V_24 :
case V_25 :
case V_26 :
V_11 = ( ( V_10 == V_25 ? -- V_11 : ++ V_11 ) < 0 ) ? 1 : ( V_11 > 1 ? 0 : V_11 ) ;
F_1 ( V_1 , V_2 , V_3 , V_11 ) ;
F_5 ( V_1 ) ;
break;
case ' ' :
case '\n' :
F_19 ( V_1 ) ;
return V_11 ;
case V_23 :
V_10 = F_20 ( V_1 ) ;
break;
case V_27 :
F_19 ( V_1 ) ;
F_21 () ;
goto V_12;
}
}
F_19 ( V_1 ) ;
return V_10 ;
}
