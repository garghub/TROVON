T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = F_3 ( sizeof( T_3 ) ) ;
if ( ! V_3 )
return 0 ;
if ( ! F_4 ( V_3 , V_4 ) ) {
F_5 ( V_3 ) ;
return 0 ;
}
V_2 -> V_5 = 1 ;
V_2 -> V_6 = ( char * ) V_3 ;
V_2 -> V_7 = 0 ;
return 1 ;
}
static int F_4 ( T_3 * V_3 , int V_8 )
{
V_3 -> V_9 = F_3 ( V_8 ) ;
if ( ! V_3 -> V_9 )
return 0 ;
V_3 -> V_10 = V_8 ;
V_3 -> V_11 = 0 ;
V_3 -> V_12 = 0 ;
V_3 -> V_13 = 0 ;
V_3 -> V_14 = V_15 ;
V_3 -> V_16 = V_17 ;
V_3 -> V_18 = 0 ;
V_3 -> V_19 = 0 ;
V_3 -> V_20 = 0 ;
V_3 -> V_21 = V_22 ;
return 1 ;
}
static int F_6 ( T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = ( T_3 * ) V_2 -> V_6 ;
if ( V_3 == NULL )
return 0 ;
if ( V_3 -> V_9 )
F_5 ( V_3 -> V_9 ) ;
F_5 ( V_3 ) ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = NULL ;
V_2 -> V_7 = 0 ;
return 1 ;
}
static int F_7 ( T_2 * V_2 , const char * V_23 , int V_24 )
{
T_3 * V_3 ;
int V_25 , V_26 , V_27 ;
unsigned char * V_28 ;
if ( ! V_23 || ( V_24 < 0 ) || ( V_2 -> V_29 == NULL ) )
return 0 ;
V_3 = ( T_3 * ) V_2 -> V_6 ;
if ( V_3 == NULL )
return 0 ;
V_26 = 0 ;
V_27 = - 1 ;
for (; ; ) {
switch ( V_3 -> V_21 ) {
case V_22 :
if ( ! F_8 ( V_2 , V_3 , V_3 -> V_30 ,
V_31 , V_32 ) )
return 0 ;
break;
case V_31 :
V_27 = F_9 ( V_2 , V_3 , V_3 -> V_33 ,
V_32 ) ;
if ( V_27 <= 0 )
goto V_34;
break;
case V_32 :
V_3 -> V_12 = F_10 ( 0 , V_24 , V_3 -> V_16 ) - V_24 ;
F_11 ( V_3 -> V_12 <= V_3 -> V_10 ) ;
V_28 = V_3 -> V_9 ;
F_12 ( & V_28 , 0 , V_24 , V_3 -> V_16 , V_3 -> V_14 ) ;
V_3 -> V_13 = V_24 ;
V_3 -> V_21 = V_35 ;
break;
case V_35 :
V_27 = F_13 ( V_2 -> V_29 , V_3 -> V_9 + V_3 -> V_11 , V_3 -> V_12 ) ;
if ( V_27 <= 0 )
goto V_34;
V_3 -> V_12 -= V_27 ;
if ( V_3 -> V_12 )
V_3 -> V_11 += V_27 ;
else {
V_3 -> V_11 = 0 ;
V_3 -> V_21 = V_36 ;
}
break;
case V_36 :
if ( V_24 > V_3 -> V_13 )
V_25 = V_3 -> V_13 ;
else
V_25 = V_24 ;
V_27 = F_13 ( V_2 -> V_29 , V_23 , V_25 ) ;
if ( V_27 <= 0 )
break;
V_26 += V_27 ;
V_3 -> V_13 -= V_27 ;
V_23 += V_27 ;
V_24 -= V_27 ;
if ( V_3 -> V_13 == 0 )
V_3 -> V_21 = V_32 ;
if ( V_24 == 0 )
goto V_34;
break;
default:
F_14 ( V_2 ) ;
return 0 ;
}
}
V_34:
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
return ( V_26 > 0 ) ? V_26 : V_27 ;
}
static int F_9 ( T_2 * V_2 , T_3 * V_3 ,
T_4 * V_37 , T_5 V_38 )
{
int V_27 ;
if ( V_3 -> V_20 <= 0 )
return 1 ;
for (; ; ) {
V_27 = F_13 ( V_2 -> V_29 , V_3 -> V_18 + V_3 -> V_19 , V_3 -> V_20 ) ;
if ( V_27 <= 0 )
break;
V_3 -> V_20 -= V_27 ;
if ( V_3 -> V_20 > 0 )
V_3 -> V_19 += V_27 ;
else {
if ( V_37 )
V_37 ( V_2 , & V_3 -> V_18 , & V_3 -> V_20 , & V_3 -> V_39 ) ;
V_3 -> V_21 = V_38 ;
V_3 -> V_19 = 0 ;
break;
}
}
return V_27 ;
}
static int F_8 ( T_2 * V_2 , T_3 * V_3 ,
T_4 * V_40 ,
T_5 V_41 ,
T_5 V_42 )
{
if ( V_40 && ! V_40 ( V_2 , & V_3 -> V_18 , & V_3 -> V_20 , & V_3 -> V_39 ) ) {
F_14 ( V_2 ) ;
return 0 ;
}
if ( V_3 -> V_20 > 0 )
V_3 -> V_21 = V_41 ;
else
V_3 -> V_21 = V_42 ;
return 1 ;
}
static int F_16 ( T_2 * V_2 , char * V_23 , int V_24 )
{
if ( ! V_2 -> V_29 )
return 0 ;
return F_17 ( V_2 -> V_29 , V_23 , V_24 ) ;
}
static int F_18 ( T_2 * V_2 , const char * V_43 )
{
return F_7 ( V_2 , V_43 , strlen ( V_43 ) ) ;
}
static int F_19 ( T_2 * V_2 , char * V_43 , int V_8 )
{
if ( ! V_2 -> V_29 )
return 0 ;
return F_20 ( V_2 -> V_29 , V_43 , V_8 ) ;
}
static long F_21 ( T_2 * V_2 , int V_44 , T_6 * V_45 )
{
if ( V_2 -> V_29 == NULL )
return ( 0 ) ;
return F_22 ( V_2 -> V_29 , V_44 , V_45 ) ;
}
static long F_23 ( T_2 * V_2 , int V_44 , long V_46 , void * V_47 )
{
T_3 * V_3 ;
T_7 * V_48 ;
long V_27 = 1 ;
V_3 = ( T_3 * ) V_2 -> V_6 ;
if ( V_3 == NULL )
return 0 ;
switch ( V_44 ) {
case V_49 :
V_48 = V_47 ;
V_3 -> V_30 = V_48 -> V_48 ;
V_3 -> V_33 = V_48 -> V_50 ;
break;
case V_51 :
V_48 = V_47 ;
V_48 -> V_48 = V_3 -> V_30 ;
V_48 -> V_50 = V_3 -> V_33 ;
break;
case V_52 :
V_48 = V_47 ;
V_3 -> V_53 = V_48 -> V_48 ;
V_3 -> V_54 = V_48 -> V_50 ;
break;
case V_55 :
V_48 = V_47 ;
V_48 -> V_48 = V_3 -> V_53 ;
V_48 -> V_50 = V_3 -> V_54 ;
break;
case V_56 :
V_3 -> V_39 = V_47 ;
break;
case V_57 :
* ( void * * ) V_47 = V_3 -> V_39 ;
break;
case V_58 :
if ( ! V_2 -> V_29 )
return 0 ;
if ( V_3 -> V_21 == V_32 ) {
if ( ! F_8 ( V_2 , V_3 , V_3 -> V_53 ,
V_59 , V_60 ) )
return 0 ;
}
if ( V_3 -> V_21 == V_59 ) {
V_27 = F_9 ( V_2 , V_3 , V_3 -> V_54 ,
V_60 ) ;
if ( V_27 <= 0 )
return V_27 ;
}
if ( V_3 -> V_21 == V_60 )
return F_24 ( V_2 -> V_29 , V_44 , V_46 , V_47 ) ;
else {
F_14 ( V_2 ) ;
return 0 ;
}
break;
default:
if ( ! V_2 -> V_29 )
return 0 ;
return F_24 ( V_2 -> V_29 , V_44 , V_46 , V_47 ) ;
}
return V_27 ;
}
static int F_25 ( T_2 * V_2 , int V_44 ,
T_4 * V_48 , T_4 * V_50 )
{
T_7 V_61 ;
V_61 . V_48 = V_48 ;
V_61 . V_50 = V_50 ;
return F_24 ( V_2 , V_44 , 0 , & V_61 ) ;
}
static int F_26 ( T_2 * V_2 , int V_44 ,
T_4 * * V_48 ,
T_4 * * V_50 )
{
T_7 V_61 ;
int V_27 ;
V_27 = F_24 ( V_2 , V_44 , 0 , & V_61 ) ;
if ( V_27 > 0 ) {
* V_48 = V_61 . V_48 ;
* V_50 = V_61 . V_50 ;
}
return V_27 ;
}
int F_27 ( T_2 * V_2 , T_4 * V_30 ,
T_4 * V_33 )
{
return F_25 ( V_2 , V_49 , V_30 , V_33 ) ;
}
int F_28 ( T_2 * V_2 , T_4 * * V_62 ,
T_4 * * V_63 )
{
return F_26 ( V_2 , V_51 , V_62 , V_63 ) ;
}
int F_29 ( T_2 * V_2 , T_4 * V_53 ,
T_4 * V_54 )
{
return F_25 ( V_2 , V_52 , V_53 , V_54 ) ;
}
int F_30 ( T_2 * V_2 , T_4 * * V_64 ,
T_4 * * V_65 )
{
return F_26 ( V_2 , V_55 , V_64 , V_65 ) ;
}
