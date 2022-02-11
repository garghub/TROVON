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
static int F_8 ( T_2 * V_2 , char * V_7 , int V_18 )
{
T_3 V_19 = V_18 ;
T_3 V_10 ;
struct V_3 * V_4 ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_12 || V_7 == NULL || V_19 == 0 )
return 0 ;
V_4 = V_2 -> V_8 ;
assert ( V_4 != NULL ) ;
assert ( V_4 -> V_5 != NULL ) ;
assert ( V_4 -> V_7 != NULL ) ;
V_4 -> V_13 = 0 ;
if ( V_4 -> V_15 )
{
F_9 ( V_20 , V_21 ) ;
return - 1 ;
}
assert ( V_4 -> V_14 <= V_4 -> V_6 ) ;
if ( V_4 -> V_14 == V_4 -> V_6 )
{
F_10 ( V_2 ) ;
return - 1 ;
}
if ( V_19 > V_4 -> V_6 - V_4 -> V_14 )
V_19 = V_4 -> V_6 - V_4 -> V_14 ;
V_10 = V_19 ;
assert ( V_10 > 0 ) ;
do
{
T_3 V_22 ;
T_3 V_16 ;
assert ( V_4 -> V_14 + V_10 <= V_4 -> V_6 ) ;
V_22 = V_4 -> V_17 + V_4 -> V_14 ;
if ( V_22 >= V_4 -> V_6 )
V_22 -= V_4 -> V_6 ;
if ( V_22 + V_10 <= V_4 -> V_6 )
V_16 = V_10 ;
else
V_16 = V_4 -> V_6 - V_22 ;
memcpy ( V_4 -> V_7 + V_22 , V_7 , V_16 ) ;
V_4 -> V_14 += V_16 ;
assert ( V_4 -> V_14 <= V_4 -> V_6 ) ;
V_10 -= V_16 ;
V_7 += V_16 ;
}
while ( V_10 );
return V_19 ;
}
static long F_11 ( T_2 * V_2 , int V_23 , long V_19 , void * V_8 )
{
long V_24 ;
struct V_3 * V_4 = V_2 -> V_8 ;
assert ( V_4 != NULL ) ;
switch ( V_23 )
{
case V_25 :
if ( V_4 -> V_5 )
{
F_9 ( V_26 , V_27 ) ;
V_24 = 0 ;
}
else if ( V_19 == 0 )
{
F_9 ( V_26 , V_28 ) ;
V_24 = 0 ;
}
else
{
T_3 V_29 = V_19 ;
if ( V_4 -> V_6 != V_29 )
{
if ( V_4 -> V_7 )
{
Free ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
}
V_4 -> V_6 = V_29 ;
}
V_24 = 1 ;
}
break;
case V_30 :
V_19 = ( long ) V_4 -> V_6 ;
case V_31 :
{
T_2 * V_32 = V_8 ;
if ( F_12 ( V_2 , V_32 ) )
V_24 = 1 ;
else
V_24 = 0 ;
}
break;
case V_33 :
F_4 ( V_2 ) ;
V_24 = 1 ;
break;
case V_34 :
if ( V_4 -> V_5 == NULL || V_4 -> V_15 )
V_24 = 0 ;
else
V_24 = ( long ) V_4 -> V_6 - V_4 -> V_14 ;
break;
case V_35 :
V_24 = ( long ) V_4 -> V_13 ;
break;
case V_36 :
V_4 -> V_15 = 1 ;
V_24 = 1 ;
break;
case V_37 :
if ( V_4 -> V_7 != NULL )
{
V_4 -> V_14 = 0 ;
V_4 -> V_17 = 0 ;
}
V_24 = 0 ;
break;
case V_38 :
V_24 = V_2 -> V_39 ;
break;
case V_40 :
V_2 -> V_39 = ( int ) V_19 ;
V_24 = 1 ;
break;
case V_41 :
if ( V_4 -> V_5 != NULL )
{
struct V_3 * V_11 = V_4 -> V_5 -> V_8 ;
V_24 = ( long ) V_11 -> V_14 ;
}
else
V_24 = 0 ;
break;
case V_42 :
if ( V_4 -> V_7 != NULL )
V_24 = ( long ) V_4 -> V_14 ;
else
V_24 = 0 ;
break;
case V_43 :
{
T_2 * V_32 = V_8 ;
struct V_3 * V_44 ;
assert ( V_32 != NULL ) ;
V_44 = V_32 -> V_8 ;
assert ( V_44 != NULL ) ;
assert ( V_44 -> V_7 == NULL ) ;
V_44 -> V_6 = V_4 -> V_6 ;
}
V_24 = 1 ;
break;
case V_45 :
V_24 = 1 ;
break;
case V_46 :
{
T_2 * V_32 = V_8 ;
if ( V_32 )
{
struct V_3 * V_44 = V_32 -> V_8 ;
assert ( V_44 != NULL ) ;
V_24 = V_44 -> V_14 == 0 && V_44 -> V_15 ;
}
else
V_24 = 1 ;
}
break;
default:
V_24 = 0 ;
}
return V_24 ;
}
static int F_13 ( T_2 * V_2 , char * V_47 )
{
return F_8 ( V_2 , V_47 , strlen ( V_47 ) ) ;
}
static int F_12 ( T_2 * V_48 , T_2 * V_49 )
{
struct V_3 * V_50 , * V_51 ;
assert ( V_48 != NULL ) ;
assert ( V_49 != NULL ) ;
V_50 = V_48 -> V_8 ;
V_51 = V_49 -> V_8 ;
if ( V_50 -> V_5 != NULL || V_51 -> V_5 != NULL )
{
F_9 ( V_52 , V_27 ) ;
return 0 ;
}
if ( V_50 -> V_7 == NULL )
{
V_50 -> V_7 = Malloc ( V_50 -> V_6 ) ;
if ( V_50 -> V_7 == NULL )
{
F_9 ( V_52 , V_53 ) ;
return 0 ;
}
V_50 -> V_14 = 0 ;
V_50 -> V_17 = 0 ;
}
if ( V_51 -> V_7 == NULL )
{
V_51 -> V_7 = Malloc ( V_51 -> V_6 ) ;
if ( V_51 -> V_7 == NULL )
{
F_9 ( V_52 , V_53 ) ;
return 0 ;
}
V_51 -> V_14 = 0 ;
V_51 -> V_17 = 0 ;
}
V_50 -> V_5 = V_49 ;
V_50 -> V_15 = 0 ;
V_50 -> V_13 = 0 ;
V_51 -> V_5 = V_48 ;
V_51 -> V_15 = 0 ;
V_51 -> V_13 = 0 ;
V_48 -> V_12 = 1 ;
V_49 -> V_12 = 1 ;
return 1 ;
}
static void F_4 ( T_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
if ( V_4 != NULL )
{
T_2 * V_54 = V_4 -> V_5 ;
if ( V_54 != NULL )
{
struct V_3 * V_11 = V_54 -> V_8 ;
assert ( V_11 != NULL ) ;
assert ( V_11 -> V_5 == V_2 ) ;
V_11 -> V_5 = NULL ;
V_54 -> V_12 = 0 ;
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
int F_14 ( T_2 * * V_55 , T_3 V_56 ,
T_2 * * V_57 , T_3 V_58 )
{
T_2 * V_48 = NULL , * V_49 = NULL ;
long V_59 ;
int V_24 = 0 ;
V_48 = F_15 ( F_1 () ) ;
if ( V_48 == NULL )
goto V_60;
V_49 = F_15 ( F_1 () ) ;
if ( V_49 == NULL )
goto V_60;
if ( V_56 )
{
V_59 = F_16 ( V_48 , V_56 ) ;
if ( ! V_59 )
goto V_60;
}
if ( V_58 )
{
V_59 = F_16 ( V_49 , V_58 ) ;
if ( ! V_59 )
goto V_60;
}
V_59 = F_17 ( V_48 , V_49 ) ;
if ( ! V_59 )
goto V_60;
V_24 = 1 ;
V_60:
if ( V_24 == 0 )
{
if ( V_48 )
{
F_18 ( V_48 ) ;
V_48 = NULL ;
}
if ( V_49 )
{
F_18 ( V_49 ) ;
V_49 = NULL ;
}
}
* V_55 = V_48 ;
* V_57 = V_49 ;
return V_24 ;
}
T_3 F_19 ( T_2 * V_2 )
{
return F_20 ( V_2 , V_34 , 0 , NULL ) ;
}
T_3 F_21 ( T_2 * V_2 )
{
return F_20 ( V_2 , V_35 , 0 , NULL ) ;
}
