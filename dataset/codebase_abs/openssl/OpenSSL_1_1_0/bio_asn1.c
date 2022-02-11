const T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 = F_3 ( sizeof( * V_3 ) ) ;
if ( V_3 == NULL )
return 0 ;
if ( ! F_4 ( V_3 , V_4 ) ) {
F_5 ( V_3 ) ;
return 0 ;
}
F_6 ( V_2 , V_3 ) ;
F_7 ( V_2 , 1 ) ;
return 1 ;
}
static int F_4 ( T_3 * V_3 , int V_5 )
{
V_3 -> V_6 = F_8 ( V_5 ) ;
if ( V_3 -> V_6 == NULL )
return 0 ;
V_3 -> V_7 = V_5 ;
V_3 -> V_8 = V_9 ;
V_3 -> V_10 = V_11 ;
V_3 -> V_12 = V_13 ;
return 1 ;
}
static int F_9 ( T_2 * V_2 )
{
T_3 * V_3 ;
if ( V_2 == NULL )
return 0 ;
V_3 = F_10 ( V_2 ) ;
if ( V_3 == NULL )
return 0 ;
F_5 ( V_3 -> V_6 ) ;
F_5 ( V_3 ) ;
F_6 ( V_2 , NULL ) ;
F_7 ( V_2 , 0 ) ;
return 1 ;
}
static int F_11 ( T_2 * V_2 , const char * V_14 , int V_15 )
{
T_3 * V_3 ;
int V_16 , V_17 , V_18 ;
unsigned char * V_19 ;
T_2 * V_20 ;
V_3 = F_10 ( V_2 ) ;
V_20 = F_12 ( V_2 ) ;
if ( V_14 == NULL || V_15 < 0 || V_3 == NULL || V_20 == NULL )
return 0 ;
V_17 = 0 ;
V_18 = - 1 ;
for (; ; ) {
switch ( V_3 -> V_12 ) {
case V_13 :
if ( ! F_13 ( V_2 , V_3 , V_3 -> V_21 ,
V_22 , V_23 ) )
return 0 ;
break;
case V_22 :
V_18 = F_14 ( V_2 , V_3 , V_3 -> V_24 ,
V_23 ) ;
if ( V_18 <= 0 )
goto V_25;
break;
case V_23 :
V_3 -> V_26 = F_15 ( 0 , V_15 , V_3 -> V_10 ) - V_15 ;
F_16 ( V_3 -> V_26 <= V_3 -> V_7 ) ;
V_19 = V_3 -> V_6 ;
F_17 ( & V_19 , 0 , V_15 , V_3 -> V_10 , V_3 -> V_8 ) ;
V_3 -> V_27 = V_15 ;
V_3 -> V_12 = V_28 ;
break;
case V_28 :
V_18 = F_18 ( V_20 , V_3 -> V_6 + V_3 -> V_29 , V_3 -> V_26 ) ;
if ( V_18 <= 0 )
goto V_25;
V_3 -> V_26 -= V_18 ;
if ( V_3 -> V_26 )
V_3 -> V_29 += V_18 ;
else {
V_3 -> V_29 = 0 ;
V_3 -> V_12 = V_30 ;
}
break;
case V_30 :
if ( V_15 > V_3 -> V_27 )
V_16 = V_3 -> V_27 ;
else
V_16 = V_15 ;
V_18 = F_18 ( V_20 , V_14 , V_16 ) ;
if ( V_18 <= 0 )
break;
V_17 += V_18 ;
V_3 -> V_27 -= V_18 ;
V_14 += V_18 ;
V_15 -= V_18 ;
if ( V_3 -> V_27 == 0 )
V_3 -> V_12 = V_23 ;
if ( V_15 == 0 )
goto V_25;
break;
default:
F_19 ( V_2 ) ;
return 0 ;
}
}
V_25:
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
return ( V_17 > 0 ) ? V_17 : V_18 ;
}
static int F_14 ( T_2 * V_2 , T_3 * V_3 ,
T_4 * V_31 , T_5 V_20 )
{
int V_18 ;
if ( V_3 -> V_32 <= 0 )
return 1 ;
for (; ; ) {
V_18 = F_18 ( F_12 ( V_2 ) , V_3 -> V_33 + V_3 -> V_34 , V_3 -> V_32 ) ;
if ( V_18 <= 0 )
break;
V_3 -> V_32 -= V_18 ;
if ( V_3 -> V_32 > 0 )
V_3 -> V_34 += V_18 ;
else {
if ( V_31 )
V_31 ( V_2 , & V_3 -> V_33 , & V_3 -> V_32 , & V_3 -> V_35 ) ;
V_3 -> V_12 = V_20 ;
V_3 -> V_34 = 0 ;
break;
}
}
return V_18 ;
}
static int F_13 ( T_2 * V_2 , T_3 * V_3 ,
T_4 * V_36 ,
T_5 V_37 ,
T_5 V_38 )
{
if ( V_36 && ! V_36 ( V_2 , & V_3 -> V_33 , & V_3 -> V_32 , & V_3 -> V_35 ) ) {
F_19 ( V_2 ) ;
return 0 ;
}
if ( V_3 -> V_32 > 0 )
V_3 -> V_12 = V_37 ;
else
V_3 -> V_12 = V_38 ;
return 1 ;
}
static int F_21 ( T_2 * V_2 , char * V_14 , int V_15 )
{
T_2 * V_20 = F_12 ( V_2 ) ;
if ( V_20 == NULL )
return 0 ;
return F_22 ( V_20 , V_14 , V_15 ) ;
}
static int F_23 ( T_2 * V_2 , const char * V_39 )
{
return F_11 ( V_2 , V_39 , strlen ( V_39 ) ) ;
}
static int F_24 ( T_2 * V_2 , char * V_39 , int V_5 )
{
T_2 * V_20 = F_12 ( V_2 ) ;
if ( V_20 == NULL )
return 0 ;
return F_25 ( V_20 , V_39 , V_5 ) ;
}
static long F_26 ( T_2 * V_2 , int V_40 , T_6 * V_41 )
{
T_2 * V_20 = F_12 ( V_2 ) ;
if ( V_20 == NULL )
return 0 ;
return F_27 ( V_20 , V_40 , V_41 ) ;
}
static long F_28 ( T_2 * V_2 , int V_40 , long V_42 , void * V_43 )
{
T_3 * V_3 ;
T_7 * V_44 ;
long V_18 = 1 ;
T_2 * V_20 ;
V_3 = F_10 ( V_2 ) ;
if ( V_3 == NULL )
return 0 ;
V_20 = F_12 ( V_2 ) ;
switch ( V_40 ) {
case V_45 :
V_44 = V_43 ;
V_3 -> V_21 = V_44 -> V_44 ;
V_3 -> V_24 = V_44 -> V_46 ;
break;
case V_47 :
V_44 = V_43 ;
V_44 -> V_44 = V_3 -> V_21 ;
V_44 -> V_46 = V_3 -> V_24 ;
break;
case V_48 :
V_44 = V_43 ;
V_3 -> V_49 = V_44 -> V_44 ;
V_3 -> V_50 = V_44 -> V_46 ;
break;
case V_51 :
V_44 = V_43 ;
V_44 -> V_44 = V_3 -> V_49 ;
V_44 -> V_46 = V_3 -> V_50 ;
break;
case V_52 :
V_3 -> V_35 = V_43 ;
break;
case V_53 :
* ( void * * ) V_43 = V_3 -> V_35 ;
break;
case V_54 :
if ( V_20 == NULL )
return 0 ;
if ( V_3 -> V_12 == V_23 ) {
if ( ! F_13 ( V_2 , V_3 , V_3 -> V_49 ,
V_55 , V_56 ) )
return 0 ;
}
if ( V_3 -> V_12 == V_55 ) {
V_18 = F_14 ( V_2 , V_3 , V_3 -> V_50 ,
V_56 ) ;
if ( V_18 <= 0 )
return V_18 ;
}
if ( V_3 -> V_12 == V_56 )
return F_29 ( V_20 , V_40 , V_42 , V_43 ) ;
else {
F_19 ( V_2 ) ;
return 0 ;
}
default:
if ( V_20 == NULL )
return 0 ;
return F_29 ( V_20 , V_40 , V_42 , V_43 ) ;
}
return V_18 ;
}
static int F_30 ( T_2 * V_2 , int V_40 ,
T_4 * V_44 , T_4 * V_46 )
{
T_7 V_57 ;
V_57 . V_44 = V_44 ;
V_57 . V_46 = V_46 ;
return F_29 ( V_2 , V_40 , 0 , & V_57 ) ;
}
static int F_31 ( T_2 * V_2 , int V_40 ,
T_4 * * V_44 ,
T_4 * * V_46 )
{
T_7 V_57 ;
int V_18 ;
V_18 = F_29 ( V_2 , V_40 , 0 , & V_57 ) ;
if ( V_18 > 0 ) {
* V_44 = V_57 . V_44 ;
* V_46 = V_57 . V_46 ;
}
return V_18 ;
}
int F_32 ( T_2 * V_2 , T_4 * V_21 ,
T_4 * V_24 )
{
return F_30 ( V_2 , V_45 , V_21 , V_24 ) ;
}
int F_33 ( T_2 * V_2 , T_4 * * V_58 ,
T_4 * * V_59 )
{
return F_31 ( V_2 , V_47 , V_58 , V_59 ) ;
}
int F_34 ( T_2 * V_2 , T_4 * V_49 ,
T_4 * V_50 )
{
return F_30 ( V_2 , V_48 , V_49 , V_50 ) ;
}
int F_35 ( T_2 * V_2 , T_4 * * V_60 ,
T_4 * * V_61 )
{
return F_31 ( V_2 , V_51 , V_60 , V_61 ) ;
}
