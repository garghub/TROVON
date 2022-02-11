void F_1 ( T_1 * V_1 , T_2 * V_2 )
{
if ( V_2 -> V_3 . V_4 != NULL )
{
F_2 ( V_2 -> V_3 . V_4 ) ;
}
V_2 -> V_3 . V_4 = F_3 ( V_5 , V_6 , NULL , V_7 ) ;
V_2 -> V_3 . V_8 = 0 ;
V_2 -> V_3 . V_9 = 0 ;
V_2 -> V_10 = NULL ;
V_2 -> V_11 . V_3 = & V_2 -> V_3 ;
F_4 ( & V_2 -> V_11 , V_1 ) ;
}
static const char *
F_5 ( int V_12 , T_3 * V_13 , T_4 V_14 ,
int V_15 )
{
const char * V_16 ;
static char V_17 [ 1024 + 1 ] ;
if ( V_12 < 0 ) {
switch ( V_12 ) {
case V_18 :
V_16 = L_1 ;
break;
case V_19 :
V_16 = L_2 ;
break;
case V_20 :
F_6 ( V_17 , sizeof( V_17 ) ,
L_3
L_4 , V_13 != NULL ? V_13 : L_5 ) ;
V_7 ( V_13 ) ;
V_16 = V_17 ;
break;
case V_21 :
F_6 ( V_17 , sizeof( V_17 ) ,
L_6
L_7 , F_7 ( V_15 ) ) ;
V_16 = V_17 ;
break;
case V_22 :
V_16 = L_8 ;
break;
case V_23 :
V_16 = L_9 ;
break;
case V_24 :
if ( V_14 )
V_16 = L_9 ;
else
V_16 = L_10 ;
break;
case V_25 :
F_6 ( V_17 , sizeof( V_17 ) ,
L_11
L_4 , V_13 != NULL ? V_13 : L_5 ) ;
V_7 ( V_13 ) ;
V_16 = V_17 ;
break;
case V_26 :
if ( V_14 )
V_16 = L_12 ;
else
V_16 = L_13 ;
break;
case V_27 :
V_16 = L_14
L_15 ;
break;
case V_28 :
V_16 = L_16 ;
break;
case V_29 :
F_6 ( V_17 , sizeof( V_17 ) ,
L_17
L_4 , V_13 != NULL ? V_13 : L_5 ) ;
V_7 ( V_13 ) ;
V_16 = V_17 ;
break;
default:
F_6 ( V_17 , sizeof( V_17 ) ,
L_18 ,
V_14 ? L_19 : L_20 ,
F_8 ( V_12 ) ) ;
V_16 = V_17 ;
break;
}
} else
V_16 = F_9 ( V_12 , V_14 ) ;
return V_16 ;
}
T_4 F_10 ( const char * V_30 , T_2 * V_2 )
{
int V_12 ;
T_3 * V_13 ;
T_3 * V_31 ;
if( V_2 -> V_10 != NULL ) {
F_11 ( V_2 -> V_10 ) ;
}
V_2 -> V_10 = F_12 ( V_30 , V_32 , & V_12 , & V_13 , FALSE ) ;
if ( ! V_2 -> V_10 ) {
V_31 = F_13 ( F_5 ( V_12 , V_13 , FALSE , V_33 ) ,
V_30 ) ;
F_14 ( L_21 , V_12 , V_31 ) ;
V_7 ( V_31 ) ;
return FALSE ;
} else
return TRUE ;
}
static void
F_15 ( T_2 * V_2 , T_5 V_34 , const T_6 * V_35 , T_7 V_36 , union V_37 * V_38 )
{
T_8 V_39 ;
V_39 . V_3 = V_2 -> V_3 . V_4 ;
V_2 -> V_3 . V_9 ++ ;
if ( ! F_16 ( L_22 , V_34 , V_35 , 0 , V_36 , & V_39 , V_38 ) )
V_2 -> V_3 . V_8 ++ ;
}
void F_17 ( int V_40 , T_2 * V_2 )
{
int V_12 ;
T_3 * V_13 ;
T_9 V_41 ;
struct V_42 * V_43 ;
union V_37 * V_38 ;
int V_34 ;
const T_6 * V_44 ;
V_2 -> V_11 . V_45 = V_40 ;
while ( V_40 > 0 ) {
F_18 ( V_2 -> V_10 ) ;
if ( F_19 ( V_2 -> V_10 , & V_12 , & V_13 , & V_41 ) ) {
V_43 = F_20 ( V_2 -> V_10 ) ;
V_38 = & V_43 -> V_38 ;
V_34 = V_43 -> V_46 ;
V_44 = F_21 ( V_2 -> V_10 ) ;
F_15 ( V_2 , V_34 , V_44 , V_43 -> V_36 , V_38 ) ;
V_40 -- ;
}
}
F_22 ( & V_2 -> V_11 ) ;
}
void F_23 ( T_2 * V_2 )
{
F_24 ( & V_2 -> V_11 ) ;
if( V_2 -> V_10 )
F_11 ( V_2 -> V_10 ) ;
}
