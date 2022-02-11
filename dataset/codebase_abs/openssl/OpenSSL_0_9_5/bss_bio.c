T_1 * F_1 ( void )
{
return & V_1 ;
}
static int F_2 ( T_2 * V_2 )
{
struct V_3 * V_4 ;
V_4 = Malloc ( sizeof *V_4 ) ;
if ( V_4 == NULL )
return 0 ;
V_4 -> V_5 = NULL ;
V_4 -> V_6 = 17 * 1024 ;
V_4 -> V_7 = NULL ;
V_2 -> V_8 = V_4 ;
return 1 ;
}
static int F_3 ( T_2 * V_2 )
{
struct V_3 * V_4 ;
if ( V_2 == NULL )
return 0 ;
V_4 = V_2 -> V_8 ;
assert ( V_4 != NULL ) ;
if ( V_4 -> V_5 )
F_4 ( V_2 ) ;
if ( V_4 -> V_7 != NULL )
{
Free ( V_4 -> V_7 ) ;
}
Free ( V_4 ) ;
return 1 ;
}
static int F_5 ( T_2 * V_2 , char * V_7 , int V_9 )
{
T_3 V_6 = V_9 ;
T_3 V_10 ;
struct V_3 * V_4 , * V_11 ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_12 )
return 0 ;
V_4 = V_2 -> V_8 ;
assert ( V_4 != NULL ) ;
assert ( V_4 -> V_5 != NULL ) ;
V_11 = V_4 -> V_5 -> V_8 ;
assert ( V_11 != NULL ) ;
assert ( V_11 -> V_7 != NULL ) ;
V_11 -> V_13 = 0 ;
if ( V_7 == NULL || V_6 == 0 )
return 0 ;
if ( V_11 -> V_14 == 0 )
{
if ( V_11 -> V_15 )
return 0 ;
else
{
F_7 ( V_2 ) ;
if ( V_6 <= V_11 -> V_6 )
V_11 -> V_13 = V_6 ;
else
V_11 -> V_13 = V_11 -> V_6 ;
return - 1 ;
}
}
if ( V_11 -> V_14 < V_6 )
V_6 = V_11 -> V_14 ;
V_10 = V_6 ;
assert ( V_10 > 0 ) ;
do
{
T_3 V_16 ;
assert ( V_10 <= V_11 -> V_14 ) ;
if ( V_11 -> V_17 + V_10 <= V_11 -> V_6 )
V_16 = V_10 ;
else
V_16 = V_11 -> V_6 - V_11 -> V_17 ;
assert ( V_11 -> V_17 + V_16 <= V_11 -> V_6 ) ;
memcpy ( V_7 , V_11 -> V_7 + V_11 -> V_17 , V_16 ) ;
V_11 -> V_14 -= V_16 ;
if ( V_11 -> V_14 )
{
V_11 -> V_17 += V_16 ;
assert ( V_11 -> V_17 <= V_11 -> V_6 ) ;
if ( V_11 -> V_17 == V_11 -> V_6 )
V_11 -> V_17 = 0 ;
V_7 += V_16 ;
}
else
{
assert ( V_16 == V_10 ) ;
V_11 -> V_17 = 0 ;
}
V_10 -= V_16 ;
}
while ( V_10 );
return V_6 ;
}
static T_3 F_8 ( T_2 * V_2 , char * * V_7 )
{
struct V_3 * V_4 , * V_11 ;
T_3 V_18 ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_12 )
return 0 ;
V_4 = V_2 -> V_8 ;
assert ( V_4 != NULL ) ;
assert ( V_4 -> V_5 != NULL ) ;
V_11 = V_4 -> V_5 -> V_8 ;
assert ( V_11 != NULL ) ;
assert ( V_11 -> V_7 != NULL ) ;
V_11 -> V_13 = 0 ;
if ( V_11 -> V_14 == 0 )
{
char V_19 ;
return F_5 ( V_2 , & V_19 , 1 ) ;
}
V_18 = V_11 -> V_14 ;
if ( V_11 -> V_6 < V_11 -> V_17 + V_18 )
V_18 = V_11 -> V_6 - V_11 -> V_17 ;
assert ( V_18 > 0 ) ;
if ( V_7 != NULL )
* V_7 = V_11 -> V_7 + V_11 -> V_17 ;
return V_18 ;
}
static T_3 F_9 ( T_2 * V_2 , char * * V_7 , T_3 V_18 )
{
struct V_3 * V_4 , * V_11 ;
T_3 V_20 ;
V_20 = F_8 ( V_2 , V_7 ) ;
if ( V_18 > V_20 )
V_18 = V_20 ;
if ( V_18 == 0 )
return V_18 ;
V_4 = V_2 -> V_8 ;
V_11 = V_4 -> V_5 -> V_8 ;
V_11 -> V_14 -= V_18 ;
if ( V_11 -> V_14 )
{
V_11 -> V_17 += V_18 ;
assert ( V_11 -> V_17 <= V_11 -> V_6 ) ;
if ( V_11 -> V_17 == V_11 -> V_6 )
V_11 -> V_17 = 0 ;
}
else
V_11 -> V_17 = 0 ;
return V_18 ;
}
static int F_10 ( T_2 * V_2 , char * V_7 , int V_21 )
{
T_3 V_18 = V_21 ;
T_3 V_10 ;
struct V_3 * V_4 ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_12 || V_7 == NULL || V_18 == 0 )
return 0 ;
V_4 = V_2 -> V_8 ;
assert ( V_4 != NULL ) ;
assert ( V_4 -> V_5 != NULL ) ;
assert ( V_4 -> V_7 != NULL ) ;
V_4 -> V_13 = 0 ;
if ( V_4 -> V_15 )
{
F_11 ( V_22 , V_23 ) ;
return - 1 ;
}
assert ( V_4 -> V_14 <= V_4 -> V_6 ) ;
if ( V_4 -> V_14 == V_4 -> V_6 )
{
F_12 ( V_2 ) ;
return - 1 ;
}
if ( V_18 > V_4 -> V_6 - V_4 -> V_14 )
V_18 = V_4 -> V_6 - V_4 -> V_14 ;
V_10 = V_18 ;
assert ( V_10 > 0 ) ;
do
{
T_3 V_24 ;
T_3 V_16 ;
assert ( V_4 -> V_14 + V_10 <= V_4 -> V_6 ) ;
V_24 = V_4 -> V_17 + V_4 -> V_14 ;
if ( V_24 >= V_4 -> V_6 )
V_24 -= V_4 -> V_6 ;
if ( V_24 + V_10 <= V_4 -> V_6 )
V_16 = V_10 ;
else
V_16 = V_4 -> V_6 - V_24 ;
memcpy ( V_4 -> V_7 + V_24 , V_7 , V_16 ) ;
V_4 -> V_14 += V_16 ;
assert ( V_4 -> V_14 <= V_4 -> V_6 ) ;
V_10 -= V_16 ;
V_7 += V_16 ;
}
while ( V_10 );
return V_18 ;
}
static T_3 F_13 ( T_2 * V_2 , char * * V_7 )
{
struct V_3 * V_4 ;
T_3 V_18 ;
T_3 V_24 ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_12 )
return 0 ;
V_4 = V_2 -> V_8 ;
assert ( V_4 != NULL ) ;
assert ( V_4 -> V_5 != NULL ) ;
assert ( V_4 -> V_7 != NULL ) ;
V_4 -> V_13 = 0 ;
if ( V_4 -> V_15 )
{
F_11 ( V_25 , V_23 ) ;
return - 1 ;
}
assert ( V_4 -> V_14 <= V_4 -> V_6 ) ;
if ( V_4 -> V_14 == V_4 -> V_6 )
{
F_12 ( V_2 ) ;
return - 1 ;
}
V_18 = V_4 -> V_6 - V_4 -> V_14 ;
V_24 = V_4 -> V_17 + V_4 -> V_14 ;
if ( V_24 >= V_4 -> V_6 )
V_24 -= V_4 -> V_6 ;
if ( V_24 + V_18 > V_4 -> V_6 )
V_18 = V_4 -> V_6 - V_24 ;
if ( V_7 != NULL )
* V_7 = V_4 -> V_7 + V_24 ;
assert ( V_24 + V_18 <= V_4 -> V_6 ) ;
return V_18 ;
}
static T_3 F_14 ( T_2 * V_2 , char * * V_7 , T_3 V_18 )
{
struct V_3 * V_4 ;
T_3 V_26 ;
V_26 = F_13 ( V_2 , V_7 ) ;
if ( V_18 > V_26 )
V_18 = V_26 ;
if ( V_18 == 0 )
return V_18 ;
V_4 = V_2 -> V_8 ;
assert ( V_4 != NULL ) ;
V_4 -> V_14 += V_18 ;
assert ( V_4 -> V_14 <= V_4 -> V_6 ) ;
return V_18 ;
}
static long F_15 ( T_2 * V_2 , int V_27 , long V_18 , void * V_8 )
{
long V_28 ;
struct V_3 * V_4 = V_2 -> V_8 ;
assert ( V_4 != NULL ) ;
switch ( V_27 )
{
case V_29 :
if ( V_4 -> V_5 )
{
F_11 ( V_30 , V_31 ) ;
V_28 = 0 ;
}
else if ( V_18 == 0 )
{
F_11 ( V_30 , V_32 ) ;
V_28 = 0 ;
}
else
{
T_3 V_33 = V_18 ;
if ( V_4 -> V_6 != V_33 )
{
if ( V_4 -> V_7 )
{
Free ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
}
V_4 -> V_6 = V_33 ;
}
V_28 = 1 ;
}
break;
case V_34 :
V_18 = ( long ) V_4 -> V_6 ;
case V_35 :
{
T_2 * V_36 = V_8 ;
if ( F_16 ( V_2 , V_36 ) )
V_28 = 1 ;
else
V_28 = 0 ;
}
break;
case V_37 :
F_4 ( V_2 ) ;
V_28 = 1 ;
break;
case V_38 :
if ( V_4 -> V_5 == NULL || V_4 -> V_15 )
V_28 = 0 ;
else
V_28 = ( long ) V_4 -> V_6 - V_4 -> V_14 ;
break;
case V_39 :
V_28 = ( long ) V_4 -> V_13 ;
break;
case V_40 :
V_4 -> V_13 = 0 ;
V_28 = 1 ;
break;
case V_41 :
V_4 -> V_15 = 1 ;
V_28 = 1 ;
break;
case V_42 :
V_28 = ( long ) F_9 ( V_2 , V_8 , ( T_3 ) V_18 ) ;
break;
case V_43 :
V_28 = ( long ) F_13 ( V_2 , V_8 ) ;
break;
case V_44 :
V_28 = ( long ) F_14 ( V_2 , V_8 , ( T_3 ) V_18 ) ;
break;
case V_45 :
if ( V_4 -> V_7 != NULL )
{
V_4 -> V_14 = 0 ;
V_4 -> V_17 = 0 ;
}
V_28 = 0 ;
break;
case V_46 :
V_28 = V_2 -> V_47 ;
break;
case V_48 :
V_2 -> V_47 = ( int ) V_18 ;
V_28 = 1 ;
break;
case V_49 :
if ( V_4 -> V_5 != NULL )
{
struct V_3 * V_11 = V_4 -> V_5 -> V_8 ;
V_28 = ( long ) V_11 -> V_14 ;
}
else
V_28 = 0 ;
break;
case V_50 :
if ( V_4 -> V_7 != NULL )
V_28 = ( long ) V_4 -> V_14 ;
else
V_28 = 0 ;
break;
case V_51 :
{
T_2 * V_36 = V_8 ;
struct V_3 * V_52 ;
assert ( V_36 != NULL ) ;
V_52 = V_36 -> V_8 ;
assert ( V_52 != NULL ) ;
assert ( V_52 -> V_7 == NULL ) ;
V_52 -> V_6 = V_4 -> V_6 ;
}
V_28 = 1 ;
break;
case V_53 :
V_28 = 1 ;
break;
case V_54 :
{
T_2 * V_36 = V_8 ;
if ( V_36 )
{
struct V_3 * V_52 = V_36 -> V_8 ;
assert ( V_52 != NULL ) ;
V_28 = V_52 -> V_14 == 0 && V_52 -> V_15 ;
}
else
V_28 = 1 ;
}
break;
default:
V_28 = 0 ;
}
return V_28 ;
}
static int F_17 ( T_2 * V_2 , char * V_55 )
{
return F_10 ( V_2 , V_55 , strlen ( V_55 ) ) ;
}
static int F_16 ( T_2 * V_56 , T_2 * V_57 )
{
struct V_3 * V_58 , * V_59 ;
assert ( V_56 != NULL ) ;
assert ( V_57 != NULL ) ;
V_58 = V_56 -> V_8 ;
V_59 = V_57 -> V_8 ;
if ( V_58 -> V_5 != NULL || V_59 -> V_5 != NULL )
{
F_11 ( V_60 , V_31 ) ;
return 0 ;
}
if ( V_58 -> V_7 == NULL )
{
V_58 -> V_7 = Malloc ( V_58 -> V_6 ) ;
if ( V_58 -> V_7 == NULL )
{
F_11 ( V_60 , V_61 ) ;
return 0 ;
}
V_58 -> V_14 = 0 ;
V_58 -> V_17 = 0 ;
}
if ( V_59 -> V_7 == NULL )
{
V_59 -> V_7 = Malloc ( V_59 -> V_6 ) ;
if ( V_59 -> V_7 == NULL )
{
F_11 ( V_60 , V_61 ) ;
return 0 ;
}
V_59 -> V_14 = 0 ;
V_59 -> V_17 = 0 ;
}
V_58 -> V_5 = V_57 ;
V_58 -> V_15 = 0 ;
V_58 -> V_13 = 0 ;
V_59 -> V_5 = V_56 ;
V_59 -> V_15 = 0 ;
V_59 -> V_13 = 0 ;
V_56 -> V_12 = 1 ;
V_57 -> V_12 = 1 ;
return 1 ;
}
static void F_4 ( T_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
if ( V_4 != NULL )
{
T_2 * V_62 = V_4 -> V_5 ;
if ( V_62 != NULL )
{
struct V_3 * V_11 = V_62 -> V_8 ;
assert ( V_11 != NULL ) ;
assert ( V_11 -> V_5 == V_2 ) ;
V_11 -> V_5 = NULL ;
V_62 -> V_12 = 0 ;
assert ( V_11 -> V_7 != NULL ) ;
V_11 -> V_14 = 0 ;
V_11 -> V_17 = 0 ;
V_4 -> V_5 = NULL ;
V_2 -> V_12 = 0 ;
assert ( V_4 -> V_7 != NULL ) ;
V_4 -> V_14 = 0 ;
V_4 -> V_17 = 0 ;
}
}
}
int F_18 ( T_2 * * V_63 , T_3 V_64 ,
T_2 * * V_65 , T_3 V_66 )
{
T_2 * V_56 = NULL , * V_57 = NULL ;
long V_67 ;
int V_28 = 0 ;
V_56 = F_19 ( F_1 () ) ;
if ( V_56 == NULL )
goto V_68;
V_57 = F_19 ( F_1 () ) ;
if ( V_57 == NULL )
goto V_68;
if ( V_64 )
{
V_67 = F_20 ( V_56 , V_64 ) ;
if ( ! V_67 )
goto V_68;
}
if ( V_66 )
{
V_67 = F_20 ( V_57 , V_66 ) ;
if ( ! V_67 )
goto V_68;
}
V_67 = F_21 ( V_56 , V_57 ) ;
if ( ! V_67 )
goto V_68;
V_28 = 1 ;
V_68:
if ( V_28 == 0 )
{
if ( V_56 )
{
F_22 ( V_56 ) ;
V_56 = NULL ;
}
if ( V_57 )
{
F_22 ( V_57 ) ;
V_57 = NULL ;
}
}
* V_63 = V_56 ;
* V_65 = V_57 ;
return V_28 ;
}
T_3 F_23 ( T_2 * V_2 )
{
return F_24 ( V_2 , V_38 , 0 , NULL ) ;
}
T_3 F_25 ( T_2 * V_2 )
{
return F_24 ( V_2 , V_39 , 0 , NULL ) ;
}
int F_26 ( T_2 * V_2 )
{
return ( F_24 ( V_2 , V_40 , 0 , NULL ) != 0 ) ;
}
int F_27 ( T_2 * V_2 , char * * V_7 )
{
long V_28 ;
if ( ! V_2 -> V_12 )
{
F_11 ( V_69 , V_70 ) ;
return - 2 ;
}
V_28 = F_24 ( V_2 , V_71 , 0 , V_7 ) ;
if ( V_28 > V_72 )
return V_72 ;
else
return ( int ) V_28 ;
}
int F_28 ( T_2 * V_2 , char * * V_7 , int V_18 )
{
int V_28 ;
if ( ! V_2 -> V_12 )
{
F_11 ( V_73 , V_70 ) ;
return - 2 ;
}
V_28 = ( int ) F_24 ( V_2 , V_42 , V_18 , V_7 ) ;
if ( V_28 > 0 )
V_2 -> V_74 += V_28 ;
return V_28 ;
}
int F_29 ( T_2 * V_2 , char * * V_7 )
{
long V_28 ;
if ( ! V_2 -> V_12 )
{
F_11 ( V_25 , V_70 ) ;
return - 2 ;
}
V_28 = F_24 ( V_2 , V_43 , 0 , V_7 ) ;
if ( V_28 > V_72 )
return V_72 ;
else
return ( int ) V_28 ;
}
int F_30 ( T_2 * V_2 , char * * V_7 , int V_18 )
{
int V_28 ;
if ( ! V_2 -> V_12 )
{
F_11 ( V_75 , V_70 ) ;
return - 2 ;
}
V_28 = F_24 ( V_2 , V_44 , V_18 , V_7 ) ;
if ( V_28 > 0 )
V_2 -> V_74 += V_28 ;
return V_28 ;
}
