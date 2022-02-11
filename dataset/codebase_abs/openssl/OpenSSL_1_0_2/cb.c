void F_1 ( const T_1 * V_1 , int V_2 , int V_3 )
{
const char * V_4 , * V_5 ;
int V_6 ;
if ( ! V_7 )
return;
V_6 = V_2 & ~ V_8 ;
V_4 = ( V_6 & V_9 ? L_1 : ( V_6 & V_10 ?
L_2 :
L_3 ) ) , V_5 =
F_2 ( V_1 ) ;
if ( V_2 & V_11 )
fprintf ( V_7 , L_4 , V_4 , V_5 ) ;
else if ( V_2 & V_12 ) {
if ( V_3 == 0 )
fprintf ( V_7 , L_5 , V_4 , V_5 ) ;
# if 0
else if (ret < 0)
fprintf(fp_cb_ssl_info, "%s:error in %s\n", str1, str2);
# endif
}
}
void F_3 ( T_2 * V_13 )
{
V_7 = V_13 ;
}
int F_4 ( int V_14 , T_3 * V_15 )
{
char V_16 [ 256 ] ;
char V_17 [ 256 ] ;
const char * V_18 = NULL ;
T_4 * V_19 ;
int V_20 , V_21 ;
if ( ! V_22 || ( V_23 == 0 ) )
return V_14 ;
V_19 = F_5 ( V_15 ) ;
V_20 = F_6 ( V_15 ) ;
V_21 = F_7 ( V_15 ) ;
V_16 [ 0 ] = V_17 [ 0 ] = '\0' ;
F_8 ( F_9 ( V_19 ) , V_16 , 256 ) ;
F_8 ( F_10 ( V_15 -> V_24 ) , V_17 , 256 ) ;
switch ( V_15 -> error ) {
case V_25 :
V_18 = V_26 ;
break;
case V_27 :
V_18 = V_28 ;
break;
case V_29 :
V_18 = V_30 ;
break;
case V_31 :
V_18 = V_32 ;
break;
case V_33 :
V_18 = V_34 ;
break;
}
if ( ( V_23 == 1 ) && V_14 )
return V_14 ;
fprintf ( V_22 , L_6 , V_21 ) ;
if ( V_18 )
fprintf ( V_22 , L_7 , V_18 ) ;
else
fprintf ( V_22 , L_8 , V_20 ) ;
if ( V_23 < 3 )
return V_14 ;
fprintf ( V_22 , L_9 , V_16 ) ;
fprintf ( V_22 , L_10 , V_17 ) ;
if ( ! V_14 )
fprintf ( V_22 , L_11 , V_20 ,
F_11 ( V_20 ) ) ;
fprintf ( V_22 , L_12 , V_14 ) ;
return V_14 ;
}
void F_12 ( T_2 * V_13 )
{
V_22 = V_13 ;
}
void F_13 ( unsigned int V_35 )
{
V_36 = V_35 ;
}
void F_14 ( unsigned int V_37 )
{
if ( V_37 < 4 )
V_23 = V_37 ;
}
T_5 * F_15 ( T_1 * V_1 , int V_38 , int V_39 )
{
static T_5 * V_40 = NULL ;
T_6 * V_41 = NULL ;
int V_14 = 1 ;
if ( ! V_40 ) {
V_14 = 0 ;
if ( ! ( V_41 = F_16 () ) )
goto V_42;
if ( ! F_17 ( V_41 , V_43 ) )
goto V_42;
if ( ! ( V_40 = F_18 () ) )
goto V_42;
if ( ! F_19 ( V_40 , V_39 , V_41 , NULL ) )
goto V_42;
V_14 = 1 ;
}
V_42:
if ( V_41 )
F_20 ( V_41 ) ;
if ( ! V_14 ) {
F_21 ( V_40 ) ;
V_40 = NULL ;
}
return V_40 ;
}
