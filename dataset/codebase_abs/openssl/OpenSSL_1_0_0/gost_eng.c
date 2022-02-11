static int F_1 ( T_1 * V_1 )
{
return 1 ;
}
static int F_2 ( T_1 * V_1 )
{
return 1 ;
}
static int F_3 ( T_1 * V_1 )
{
F_4 () ;
return 1 ;
}
static int F_5 ( T_1 * V_1 , const char * V_2 )
{
int V_3 = 0 ;
if ( V_2 && strcmp ( V_2 , V_4 ) ) return 0 ;
if ( ! F_6 ( V_1 , V_4 ) )
{
printf ( L_1 ) ;
goto V_5;
}
if ( ! F_7 ( V_1 , V_6 ) )
{
printf ( L_2 ) ;
goto V_5;
}
if ( ! F_8 ( V_1 , V_7 ) )
{
printf ( L_3 ) ;
goto V_5;
}
if ( ! F_9 ( V_1 , V_8 ) )
{
printf ( L_4 ) ;
goto V_5;
}
if ( ! F_10 ( V_1 , V_9 ) )
{
printf ( L_5 ) ;
goto V_5;
}
if ( ! F_11 ( V_1 , V_10 ) )
{
printf ( L_6 ) ;
goto V_5;
}
if ( ! F_12 ( V_1 , V_11 ) )
{
fprintf ( V_12 , L_7 ) ;
goto V_5;
}
if ( ! F_13 ( V_1 , V_13 ) )
{
fprintf ( V_12 , L_8 ) ;
goto V_5;
}
if ( ! F_14 ( V_1 , F_3 )
|| ! F_15 ( V_1 , F_1 )
|| ! F_16 ( V_1 , F_2 ) )
{
goto V_5;
}
if ( ! F_17 ( V_14 , & V_15 , L_9 , L_10 ) ) goto V_5;
if ( ! F_17 ( V_16 , & V_17 , L_11 , L_12 ) ) goto V_5;
if ( ! F_17 ( V_18 , & V_19 ,
L_13 , L_14 ) ) goto V_5;
if ( ! F_18 ( V_14 , & V_20 , 0 ) ) goto V_5;
if ( ! F_18 ( V_16 , & V_21 , 0 ) ) goto V_5;
if ( ! F_18 ( V_18 , & V_22 , 0 ) )
goto V_5;
if ( ! F_19 ( V_1 )
|| ! F_20 ( V_1 )
|| ! F_21 ( V_1 )
|| ! F_22 ( & V_23 )
|| ! F_22 ( & V_24 )
|| ! F_23 ( & V_25 )
|| ! F_23 ( & V_26 )
)
{
goto V_5;
}
F_24 () ;
V_3 = 1 ;
V_5:
return V_3 ;
}
static int V_7 ( T_1 * V_1 , const T_2 * * V_27 ,
const int * * V_28 , int V_29 )
{
int V_30 = 1 ;
if ( ! V_27 )
{
* V_28 = V_31 ;
return 2 ;
}
if( V_29 == V_32 )
{
* V_27 = & V_25 ;
}
else if ( V_29 == V_18 )
{
* V_27 = & V_26 ;
}
else
{
V_30 = 0 ;
* V_27 = NULL ;
}
return V_30 ;
}
static int V_8 ( T_1 * V_1 , const T_3 * * V_33 ,
const int * * V_28 , int V_29 )
{
int V_30 = 1 ;
if ( ! V_33 )
{
* V_28 = V_34 ;
return 2 ;
}
if( V_29 == V_35 )
{
* V_33 = & V_23 ;
}
else if ( V_29 == V_36 )
{
* V_33 = & V_24 ;
}
else
{
V_30 = 0 ;
* V_33 = NULL ;
}
return V_30 ;
}
static int V_9 ( T_1 * V_1 , T_4 * * V_37 ,
const int * * V_28 , int V_29 )
{
if ( ! V_37 )
{
* V_28 = V_38 ;
return 3 ;
}
switch ( V_29 )
{
case V_14 : * V_37 = V_20 ; return 1 ;
case V_16 : * V_37 = V_21 ; return 1 ;
case V_18 : * V_37 = V_22 ; return 1 ;
default: ;
}
* V_37 = NULL ;
return 0 ;
}
static int V_10 ( T_1 * V_1 , T_5 * * V_39 ,
const int * * V_28 , int V_29 )
{
if ( ! V_39 )
{
* V_28 = V_38 ;
return 3 ;
}
switch ( V_29 )
{
case V_14 : * V_39 = V_15 ; return 1 ;
case V_16 : * V_39 = V_17 ; return 1 ;
case V_18 : * V_39 = V_19 ; return 1 ;
default: ;
}
* V_39 = NULL ;
return 0 ;
}
static T_1 * F_25 ( void )
{
T_1 * V_3 = F_26 () ;
if ( ! V_3 )
return NULL ;
if ( ! F_5 ( V_3 , V_4 ) )
{
F_27 ( V_3 ) ;
return NULL ;
}
return V_3 ;
}
void F_28 ( void )
{
T_1 * V_40 = F_25 () ;
if ( ! V_40 ) return;
F_29 ( V_40 ) ;
F_27 ( V_40 ) ;
F_30 () ;
}
