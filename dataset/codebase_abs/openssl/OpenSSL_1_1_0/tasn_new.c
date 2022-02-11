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
int F_3 ( T_1 * * V_3 , const T_2 * V_1 , int V_4 )
{
const T_3 * V_5 = NULL ;
const T_4 * V_6 ;
const T_5 * V_7 = V_1 -> V_8 ;
T_6 * V_9 ;
T_1 * * V_10 ;
int V_11 ;
if ( V_7 && V_7 -> V_9 )
V_9 = V_7 -> V_9 ;
else
V_9 = 0 ;
#ifndef F_4
F_5 ( V_1 -> V_12 ? V_1 -> V_12 : L_1 ) ;
#endif
switch ( V_1 -> V_13 ) {
case V_14 :
V_6 = V_1 -> V_8 ;
if ( V_6 && V_6 -> V_15 ) {
if ( ! V_6 -> V_15 ( V_3 , V_1 ) )
goto V_16;
}
break;
case V_17 :
if ( V_1 -> V_18 ) {
if ( ! F_6 ( V_3 , V_1 -> V_18 ) )
goto V_16;
} else if ( ! F_7 ( V_3 , V_1 , V_4 ) )
goto V_16;
break;
case V_19 :
if ( ! F_7 ( V_3 , V_1 , V_4 ) )
goto V_16;
break;
case V_20 :
if ( V_9 ) {
V_11 = V_9 ( V_21 , V_3 , V_1 , NULL ) ;
if ( ! V_11 )
goto V_22;
if ( V_11 == 2 ) {
#ifndef F_4
F_8 () ;
#endif
return 1 ;
}
}
if ( V_4 ) {
memset ( * V_3 , 0 , V_1 -> V_23 ) ;
} else {
* V_3 = F_9 ( V_1 -> V_23 ) ;
if ( * V_3 == NULL )
goto V_16;
}
F_10 ( V_3 , - 1 , V_1 ) ;
if ( V_9 && ! V_9 ( V_24 , V_3 , V_1 , NULL ) )
goto V_22;
break;
case V_25 :
case V_26 :
if ( V_9 ) {
V_11 = V_9 ( V_21 , V_3 , V_1 , NULL ) ;
if ( ! V_11 )
goto V_22;
if ( V_11 == 2 ) {
#ifndef F_4
F_8 () ;
#endif
return 1 ;
}
}
if ( V_4 ) {
memset ( * V_3 , 0 , V_1 -> V_23 ) ;
} else {
* V_3 = F_9 ( V_1 -> V_23 ) ;
if ( * V_3 == NULL )
goto V_16;
}
if ( F_11 ( V_3 , 0 , V_1 ) < 0 )
goto V_16;
F_12 ( V_3 , V_1 ) ;
for ( V_11 = 0 , V_5 = V_1 -> V_18 ; V_11 < V_1 -> V_27 ; V_5 ++ , V_11 ++ ) {
V_10 = F_13 ( V_3 , V_5 ) ;
if ( ! F_6 ( V_10 , V_5 ) )
goto V_16;
}
if ( V_9 && ! V_9 ( V_24 , V_3 , V_1 , NULL ) )
goto V_22;
break;
}
#ifndef F_4
F_8 () ;
#endif
return 1 ;
V_16:
F_14 ( V_28 , V_29 ) ;
#ifndef F_4
F_8 () ;
#endif
return 0 ;
V_22:
F_14 ( V_28 , V_30 ) ;
F_15 ( V_3 , V_1 ) ;
#ifndef F_4
F_8 () ;
#endif
return 0 ;
}
static void F_16 ( T_1 * * V_3 , const T_2 * V_1 )
{
const T_4 * V_6 ;
switch ( V_1 -> V_13 ) {
case V_14 :
V_6 = V_1 -> V_8 ;
if ( V_6 && V_6 -> V_31 )
V_6 -> V_31 ( V_3 , V_1 ) ;
else
* V_3 = NULL ;
break;
case V_17 :
if ( V_1 -> V_18 )
F_17 ( V_3 , V_1 -> V_18 ) ;
else
F_18 ( V_3 , V_1 ) ;
break;
case V_19 :
F_18 ( V_3 , V_1 ) ;
break;
case V_20 :
case V_26 :
case V_25 :
* V_3 = NULL ;
break;
}
}
static int F_6 ( T_1 * * V_3 , const T_3 * V_5 )
{
const T_2 * V_1 = F_19 ( V_5 -> V_32 ) ;
int V_4 = V_5 -> V_33 & V_34 ;
T_1 * V_35 ;
int V_2 ;
if ( V_4 ) {
V_35 = ( T_1 * ) V_3 ;
V_3 = & V_35 ;
}
if ( V_5 -> V_33 & V_36 ) {
F_17 ( V_3 , V_5 ) ;
return 1 ;
}
if ( V_5 -> V_33 & V_37 ) {
* V_3 = NULL ;
return 1 ;
}
#ifndef F_4
F_5 ( V_5 -> V_38
? V_5 -> V_38 : L_2 ) ;
#endif
if ( V_5 -> V_33 & V_39 ) {
F_20 ( T_1 ) * V_40 ;
V_40 = F_21 () ;
if ( ! V_40 ) {
F_14 ( V_41 , V_29 ) ;
V_2 = 0 ;
goto V_42;
}
* V_3 = ( T_1 * ) V_40 ;
V_2 = 1 ;
goto V_42;
}
V_2 = F_3 ( V_3 , V_1 , V_4 ) ;
V_42:
#ifndef F_4
F_8 () ;
#endif
return V_2 ;
}
static void F_17 ( T_1 * * V_3 , const T_3 * V_5 )
{
if ( V_5 -> V_33 & ( V_37 | V_39 ) )
* V_3 = NULL ;
else
F_16 ( V_3 , F_19 ( V_5 -> V_32 ) ) ;
}
static int F_7 ( T_1 * * V_3 , const T_2 * V_1 ,
int V_4 )
{
T_7 * V_43 ;
T_8 * V_44 ;
int V_45 ;
if ( ! V_1 )
return 0 ;
if ( V_1 -> V_8 ) {
const T_9 * V_46 = V_1 -> V_8 ;
if ( V_46 -> V_47 )
return V_46 -> V_47 ( V_3 , V_1 ) ;
}
if ( V_1 -> V_13 == V_19 )
V_45 = - 1 ;
else
V_45 = V_1 -> V_45 ;
switch ( V_45 ) {
case V_48 :
* V_3 = ( T_1 * ) F_22 ( V_49 ) ;
return 1 ;
case V_50 :
* ( V_51 * ) V_3 = V_1 -> V_23 ;
return 1 ;
case V_52 :
* V_3 = ( T_1 * ) 1 ;
return 1 ;
case V_53 :
V_43 = F_23 ( sizeof( * V_43 ) ) ;
if ( V_43 == NULL )
return 0 ;
V_43 -> V_54 . V_55 = NULL ;
V_43 -> type = - 1 ;
* V_3 = ( T_1 * ) V_43 ;
break;
default:
if ( V_4 ) {
V_44 = * ( T_8 * * ) V_3 ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> type = V_45 ;
V_44 -> V_33 = V_56 ;
} else {
V_44 = F_24 ( V_45 ) ;
* V_3 = ( T_1 * ) V_44 ;
}
if ( V_1 -> V_13 == V_19 && V_44 )
V_44 -> V_33 |= V_57 ;
break;
}
if ( * V_3 )
return 1 ;
return 0 ;
}
static void F_18 ( T_1 * * V_3 , const T_2 * V_1 )
{
int V_45 ;
if ( V_1 && V_1 -> V_8 ) {
const T_9 * V_46 = V_1 -> V_8 ;
if ( V_46 -> V_58 )
V_46 -> V_58 ( V_3 , V_1 ) ;
else
* V_3 = NULL ;
return;
}
if ( ! V_1 || ( V_1 -> V_13 == V_19 ) )
V_45 = - 1 ;
else
V_45 = V_1 -> V_45 ;
if ( V_45 == V_50 )
* ( V_51 * ) V_3 = V_1 -> V_23 ;
else
* V_3 = NULL ;
}
