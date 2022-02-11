T_1 * F_1 ( const T_2 * V_1 )
{
T_1 * V_2 = NULL ;
if ( F_2 ( & V_2 , V_1 ) > 0 )
return V_2 ;
return NULL ;
}
int F_2 ( T_1 * * V_3 , const T_2 * V_1 )
{
return F_3 ( V_3 , V_1 , 0 ) ;
}
static int F_3 ( T_1 * * V_3 , const T_2 * V_1 ,
int V_4 )
{
const T_3 * V_5 = NULL ;
const T_4 * V_6 ;
const T_5 * V_7 ;
const T_6 * V_8 = V_1 -> V_9 ;
T_7 * V_10 ;
T_1 * * V_11 ;
int V_12 ;
if ( V_8 && V_8 -> V_10 )
V_10 = V_8 -> V_10 ;
else
V_10 = 0 ;
if ( ! V_4 )
* V_3 = NULL ;
#ifdef F_4
if ( V_1 -> V_13 )
F_5 ( V_1 -> V_13 ) ;
#endif
switch ( V_1 -> V_14 ) {
case V_15 :
V_7 = V_1 -> V_9 ;
if ( V_7 && V_7 -> V_16 ) {
if ( ! V_7 -> V_16 ( V_3 , V_1 ) )
goto V_17;
}
break;
case V_18 :
V_6 = V_1 -> V_9 ;
if ( V_6 && V_6 -> V_19 ) {
* V_3 = V_6 -> V_19 () ;
if ( ! * V_3 )
goto V_17;
}
break;
case V_20 :
if ( V_1 -> V_21 ) {
if ( ! F_6 ( V_3 , V_1 -> V_21 ) )
goto V_17;
} else if ( ! F_7 ( V_3 , V_1 ) )
goto V_17;
break;
case V_22 :
if ( ! F_7 ( V_3 , V_1 ) )
goto V_17;
break;
case V_23 :
if ( V_10 ) {
V_12 = V_10 ( V_24 , V_3 , V_1 , NULL ) ;
if ( ! V_12 )
goto V_25;
if ( V_12 == 2 ) {
#ifdef F_4
if ( V_1 -> V_13 )
F_8 () ;
#endif
return 1 ;
}
}
if ( ! V_4 ) {
* V_3 = F_9 ( V_1 -> V_26 ) ;
if ( ! * V_3 )
goto V_17;
memset ( * V_3 , 0 , V_1 -> V_26 ) ;
}
F_10 ( V_3 , - 1 , V_1 ) ;
if ( V_10 && ! V_10 ( V_27 , V_3 , V_1 , NULL ) )
goto V_25;
break;
case V_28 :
case V_29 :
if ( V_10 ) {
V_12 = V_10 ( V_24 , V_3 , V_1 , NULL ) ;
if ( ! V_12 )
goto V_25;
if ( V_12 == 2 ) {
#ifdef F_4
if ( V_1 -> V_13 )
F_8 () ;
#endif
return 1 ;
}
}
if ( ! V_4 ) {
* V_3 = F_9 ( V_1 -> V_26 ) ;
if ( ! * V_3 )
goto V_17;
memset ( * V_3 , 0 , V_1 -> V_26 ) ;
F_11 ( V_3 , 0 , V_1 ) ;
F_12 ( V_3 , V_1 ) ;
}
for ( V_12 = 0 , V_5 = V_1 -> V_21 ; V_12 < V_1 -> V_30 ; V_5 ++ , V_12 ++ ) {
V_11 = F_13 ( V_3 , V_5 ) ;
if ( ! F_6 ( V_11 , V_5 ) )
goto V_17;
}
if ( V_10 && ! V_10 ( V_27 , V_3 , V_1 , NULL ) )
goto V_25;
break;
}
#ifdef F_4
if ( V_1 -> V_13 )
F_8 () ;
#endif
return 1 ;
V_17:
F_14 ( V_31 , V_32 ) ;
#ifdef F_4
if ( V_1 -> V_13 )
F_8 () ;
#endif
return 0 ;
V_25:
F_14 ( V_31 , V_33 ) ;
F_15 ( V_3 , V_1 ) ;
#ifdef F_4
if ( V_1 -> V_13 )
F_8 () ;
#endif
return 0 ;
}
static void F_16 ( T_1 * * V_3 , const T_2 * V_1 )
{
const T_5 * V_7 ;
switch ( V_1 -> V_14 ) {
case V_15 :
V_7 = V_1 -> V_9 ;
if ( V_7 && V_7 -> V_34 )
V_7 -> V_34 ( V_3 , V_1 ) ;
else
* V_3 = NULL ;
break;
case V_20 :
if ( V_1 -> V_21 )
F_17 ( V_3 , V_1 -> V_21 ) ;
else
F_18 ( V_3 , V_1 ) ;
break;
case V_22 :
F_18 ( V_3 , V_1 ) ;
break;
case V_18 :
case V_23 :
case V_29 :
case V_28 :
* V_3 = NULL ;
break;
}
}
int F_6 ( T_1 * * V_3 , const T_3 * V_5 )
{
const T_2 * V_1 = F_19 ( V_5 -> V_35 ) ;
int V_2 ;
if ( V_5 -> V_36 & V_37 ) {
F_17 ( V_3 , V_5 ) ;
return 1 ;
}
if ( V_5 -> V_36 & V_38 ) {
* V_3 = NULL ;
return 1 ;
}
#ifdef F_4
if ( V_5 -> V_39 )
F_5 ( V_5 -> V_39 ) ;
#endif
if ( V_5 -> V_36 & V_40 ) {
F_20 ( T_1 ) * V_41 ;
V_41 = F_21 () ;
if ( ! V_41 ) {
F_14 ( V_42 , V_32 ) ;
V_2 = 0 ;
goto V_43;
}
* V_3 = ( T_1 * ) V_41 ;
V_2 = 1 ;
goto V_43;
}
V_2 = F_3 ( V_3 , V_1 , V_5 -> V_36 & V_44 ) ;
V_43:
#ifdef F_4
if ( V_1 -> V_13 )
F_8 () ;
#endif
return V_2 ;
}
static void F_17 ( T_1 * * V_3 , const T_3 * V_5 )
{
if ( V_5 -> V_36 & ( V_38 | V_40 ) )
* V_3 = NULL ;
else
F_16 ( V_3 , F_19 ( V_5 -> V_35 ) ) ;
}
int F_7 ( T_1 * * V_3 , const T_2 * V_1 )
{
T_8 * V_45 ;
T_9 * V_46 ;
int V_47 ;
if ( V_1 && V_1 -> V_9 ) {
const T_10 * V_48 = V_1 -> V_9 ;
if ( V_48 -> V_49 )
return V_48 -> V_49 ( V_3 , V_1 ) ;
}
if ( ! V_1 || ( V_1 -> V_14 == V_22 ) )
V_47 = - 1 ;
else
V_47 = V_1 -> V_47 ;
switch ( V_47 ) {
case V_50 :
* V_3 = ( T_1 * ) F_22 ( V_51 ) ;
return 1 ;
case V_52 :
* ( V_53 * ) V_3 = V_1 -> V_26 ;
return 1 ;
case V_54 :
* V_3 = ( T_1 * ) 1 ;
return 1 ;
case V_55 :
V_45 = F_9 ( sizeof( T_8 ) ) ;
if ( ! V_45 )
return 0 ;
V_45 -> V_56 . V_57 = NULL ;
V_45 -> type = - 1 ;
* V_3 = ( T_1 * ) V_45 ;
break;
default:
V_46 = F_23 ( V_47 ) ;
if ( V_1 -> V_14 == V_22 && V_46 )
V_46 -> V_36 |= V_58 ;
* V_3 = ( T_1 * ) V_46 ;
break;
}
if ( * V_3 )
return 1 ;
return 0 ;
}
static void F_18 ( T_1 * * V_3 , const T_2 * V_1 )
{
int V_47 ;
if ( V_1 && V_1 -> V_9 ) {
const T_10 * V_48 = V_1 -> V_9 ;
if ( V_48 -> V_59 )
V_48 -> V_59 ( V_3 , V_1 ) ;
else
* V_3 = NULL ;
return;
}
if ( ! V_1 || ( V_1 -> V_14 == V_22 ) )
V_47 = - 1 ;
else
V_47 = V_1 -> V_47 ;
if ( V_47 == V_52 )
* ( V_53 * ) V_3 = V_1 -> V_26 ;
else
* V_3 = NULL ;
}
