T_1 * F_1 ( void )
{
return & V_1 ;
}
static int F_2 ( T_2 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_3 ( sizeof *V_4 ) ;
if ( V_4 == NULL )
return 0 ;
V_4 -> V_5 = NULL ;
V_4 -> V_6 = 17 * 1024 ;
V_4 -> V_7 = NULL ;
V_2 -> V_8 = V_4 ;
return 1 ;
}
static int F_4 ( T_2 * V_2 )
{
struct V_3 * V_4 ;
if ( V_2 == NULL )
return 0 ;
V_4 = V_2 -> V_8 ;
assert ( V_4 != NULL ) ;
if ( V_4 -> V_5 )
F_5 ( V_2 ) ;
if ( V_4 -> V_7 != NULL )
{
F_6 ( V_4 -> V_7 ) ;
}
F_6 ( V_4 ) ;
return 1 ;
}
static int F_7 ( T_2 * V_2 , char * V_7 , int V_9 )
{
T_3 V_6 = V_9 ;
T_3 V_10 ;
struct V_3 * V_4 , * V_11 ;
F_8 ( V_2 ) ;
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
F_9 ( V_2 ) ;
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
static T_4 F_10 ( T_2 * V_2 , char * * V_7 )
{
struct V_3 * V_4 , * V_11 ;
T_4 V_18 ;
F_8 ( V_2 ) ;
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
return F_7 ( V_2 , & V_19 , 1 ) ;
}
V_18 = V_11 -> V_14 ;
if ( V_11 -> V_6 < V_11 -> V_17 + V_18 )
V_18 = V_11 -> V_6 - V_11 -> V_17 ;
assert ( V_18 > 0 ) ;
if ( V_7 != NULL )
* V_7 = V_11 -> V_7 + V_11 -> V_17 ;
return V_18 ;
}
static T_4 F_11 ( T_2 * V_2 , char * * V_7 , T_3 V_20 )
{
struct V_3 * V_4 , * V_11 ;
T_4 V_18 , V_21 ;
if ( V_20 > V_22 )
V_18 = V_22 ;
else
V_18 = ( T_4 ) V_20 ;
V_21 = F_10 ( V_2 , V_7 ) ;
if ( V_18 > V_21 )
V_18 = V_21 ;
if ( V_18 <= 0 )
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
static int F_12 ( T_2 * V_2 , const char * V_7 , int V_20 )
{
T_3 V_18 = V_20 ;
T_3 V_10 ;
struct V_3 * V_4 ;
F_8 ( V_2 ) ;
if ( ! V_2 -> V_12 || V_7 == NULL || V_18 == 0 )
return 0 ;
V_4 = V_2 -> V_8 ;
assert ( V_4 != NULL ) ;
assert ( V_4 -> V_5 != NULL ) ;
assert ( V_4 -> V_7 != NULL ) ;
V_4 -> V_13 = 0 ;
if ( V_4 -> V_15 )
{
F_13 ( V_23 , V_24 ) ;
return - 1 ;
}
assert ( V_4 -> V_14 <= V_4 -> V_6 ) ;
if ( V_4 -> V_14 == V_4 -> V_6 )
{
F_14 ( V_2 ) ;
return - 1 ;
}
if ( V_18 > V_4 -> V_6 - V_4 -> V_14 )
V_18 = V_4 -> V_6 - V_4 -> V_14 ;
V_10 = V_18 ;
assert ( V_10 > 0 ) ;
do
{
T_3 V_25 ;
T_3 V_16 ;
assert ( V_4 -> V_14 + V_10 <= V_4 -> V_6 ) ;
V_25 = V_4 -> V_17 + V_4 -> V_14 ;
if ( V_25 >= V_4 -> V_6 )
V_25 -= V_4 -> V_6 ;
if ( V_25 + V_10 <= V_4 -> V_6 )
V_16 = V_10 ;
else
V_16 = V_4 -> V_6 - V_25 ;
memcpy ( V_4 -> V_7 + V_25 , V_7 , V_16 ) ;
V_4 -> V_14 += V_16 ;
assert ( V_4 -> V_14 <= V_4 -> V_6 ) ;
V_10 -= V_16 ;
V_7 += V_16 ;
}
while ( V_10 );
return V_18 ;
}
static T_4 F_15 ( T_2 * V_2 , char * * V_7 )
{
struct V_3 * V_4 ;
T_3 V_18 ;
T_3 V_25 ;
F_8 ( V_2 ) ;
if ( ! V_2 -> V_12 )
return 0 ;
V_4 = V_2 -> V_8 ;
assert ( V_4 != NULL ) ;
assert ( V_4 -> V_5 != NULL ) ;
assert ( V_4 -> V_7 != NULL ) ;
V_4 -> V_13 = 0 ;
if ( V_4 -> V_15 )
{
F_13 ( V_26 , V_24 ) ;
return - 1 ;
}
assert ( V_4 -> V_14 <= V_4 -> V_6 ) ;
if ( V_4 -> V_14 == V_4 -> V_6 )
{
F_14 ( V_2 ) ;
return - 1 ;
}
V_18 = V_4 -> V_6 - V_4 -> V_14 ;
V_25 = V_4 -> V_17 + V_4 -> V_14 ;
if ( V_25 >= V_4 -> V_6 )
V_25 -= V_4 -> V_6 ;
if ( V_25 + V_18 > V_4 -> V_6 )
V_18 = V_4 -> V_6 - V_25 ;
if ( V_7 != NULL )
* V_7 = V_4 -> V_7 + V_25 ;
assert ( V_25 + V_18 <= V_4 -> V_6 ) ;
return V_18 ;
}
static T_4 F_16 ( T_2 * V_2 , char * * V_7 , T_3 V_20 )
{
struct V_3 * V_4 ;
T_4 V_18 , V_27 ;
if ( V_20 > V_22 )
V_18 = V_22 ;
else
V_18 = ( T_4 ) V_20 ;
V_27 = F_15 ( V_2 , V_7 ) ;
if ( V_18 > V_27 )
V_18 = V_27 ;
if ( V_18 <= 0 )
return V_18 ;
V_4 = V_2 -> V_8 ;
assert ( V_4 != NULL ) ;
V_4 -> V_14 += V_18 ;
assert ( V_4 -> V_14 <= V_4 -> V_6 ) ;
return V_18 ;
}
static long F_17 ( T_2 * V_2 , int V_28 , long V_18 , void * V_8 )
{
long V_29 ;
struct V_3 * V_4 = V_2 -> V_8 ;
assert ( V_4 != NULL ) ;
switch ( V_28 )
{
case V_30 :
if ( V_4 -> V_5 )
{
F_13 ( V_31 , V_32 ) ;
V_29 = 0 ;
}
else if ( V_18 == 0 )
{
F_13 ( V_31 , V_33 ) ;
V_29 = 0 ;
}
else
{
T_3 V_34 = V_18 ;
if ( V_4 -> V_6 != V_34 )
{
if ( V_4 -> V_7 )
{
F_6 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
}
V_4 -> V_6 = V_34 ;
}
V_29 = 1 ;
}
break;
case V_35 :
V_29 = ( long ) V_4 -> V_6 ;
break;
case V_36 :
{
T_2 * V_37 = V_8 ;
if ( F_18 ( V_2 , V_37 ) )
V_29 = 1 ;
else
V_29 = 0 ;
}
break;
case V_38 :
F_5 ( V_2 ) ;
V_29 = 1 ;
break;
case V_39 :
if ( V_4 -> V_5 == NULL || V_4 -> V_15 )
V_29 = 0 ;
else
V_29 = ( long ) V_4 -> V_6 - V_4 -> V_14 ;
break;
case V_40 :
V_29 = ( long ) V_4 -> V_13 ;
break;
case V_41 :
V_4 -> V_13 = 0 ;
V_29 = 1 ;
break;
case V_42 :
V_4 -> V_15 = 1 ;
V_29 = 1 ;
break;
case V_43 :
V_29 = ( long ) F_10 ( V_2 , V_8 ) ;
break;
case V_44 :
V_29 = ( long ) F_11 ( V_2 , V_8 , ( T_3 ) V_18 ) ;
break;
case V_45 :
V_29 = ( long ) F_15 ( V_2 , V_8 ) ;
break;
case V_46 :
V_29 = ( long ) F_16 ( V_2 , V_8 , ( T_3 ) V_18 ) ;
break;
case V_47 :
if ( V_4 -> V_7 != NULL )
{
V_4 -> V_14 = 0 ;
V_4 -> V_17 = 0 ;
}
V_29 = 0 ;
break;
case V_48 :
V_29 = V_2 -> V_49 ;
break;
case V_50 :
V_2 -> V_49 = ( int ) V_18 ;
V_29 = 1 ;
break;
case V_51 :
if ( V_4 -> V_5 != NULL )
{
struct V_3 * V_11 = V_4 -> V_5 -> V_8 ;
V_29 = ( long ) V_11 -> V_14 ;
}
else
V_29 = 0 ;
break;
case V_52 :
if ( V_4 -> V_7 != NULL )
V_29 = ( long ) V_4 -> V_14 ;
else
V_29 = 0 ;
break;
case V_53 :
{
T_2 * V_37 = V_8 ;
struct V_3 * V_54 ;
assert ( V_37 != NULL ) ;
V_54 = V_37 -> V_8 ;
assert ( V_54 != NULL ) ;
assert ( V_54 -> V_7 == NULL ) ;
V_54 -> V_6 = V_4 -> V_6 ;
}
V_29 = 1 ;
break;
case V_55 :
V_29 = 1 ;
break;
case V_56 :
{
T_2 * V_37 = V_8 ;
if ( V_37 )
{
struct V_3 * V_54 = V_37 -> V_8 ;
assert ( V_54 != NULL ) ;
V_29 = V_54 -> V_14 == 0 && V_54 -> V_15 ;
}
else
V_29 = 1 ;
}
break;
default:
V_29 = 0 ;
}
return V_29 ;
}
static int F_19 ( T_2 * V_2 , const char * V_57 )
{
return F_12 ( V_2 , V_57 , strlen ( V_57 ) ) ;
}
static int F_18 ( T_2 * V_58 , T_2 * V_59 )
{
struct V_3 * V_60 , * V_61 ;
assert ( V_58 != NULL ) ;
assert ( V_59 != NULL ) ;
V_60 = V_58 -> V_8 ;
V_61 = V_59 -> V_8 ;
if ( V_60 -> V_5 != NULL || V_61 -> V_5 != NULL )
{
F_13 ( V_62 , V_32 ) ;
return 0 ;
}
if ( V_60 -> V_7 == NULL )
{
V_60 -> V_7 = F_3 ( V_60 -> V_6 ) ;
if ( V_60 -> V_7 == NULL )
{
F_13 ( V_62 , V_63 ) ;
return 0 ;
}
V_60 -> V_14 = 0 ;
V_60 -> V_17 = 0 ;
}
if ( V_61 -> V_7 == NULL )
{
V_61 -> V_7 = F_3 ( V_61 -> V_6 ) ;
if ( V_61 -> V_7 == NULL )
{
F_13 ( V_62 , V_63 ) ;
return 0 ;
}
V_61 -> V_14 = 0 ;
V_61 -> V_17 = 0 ;
}
V_60 -> V_5 = V_59 ;
V_60 -> V_15 = 0 ;
V_60 -> V_13 = 0 ;
V_61 -> V_5 = V_58 ;
V_61 -> V_15 = 0 ;
V_61 -> V_13 = 0 ;
V_58 -> V_12 = 1 ;
V_59 -> V_12 = 1 ;
return 1 ;
}
static void F_5 ( T_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
if ( V_4 != NULL )
{
T_2 * V_64 = V_4 -> V_5 ;
if ( V_64 != NULL )
{
struct V_3 * V_11 = V_64 -> V_8 ;
assert ( V_11 != NULL ) ;
assert ( V_11 -> V_5 == V_2 ) ;
V_11 -> V_5 = NULL ;
V_64 -> V_12 = 0 ;
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
int F_20 ( T_2 * * V_65 , T_3 V_66 ,
T_2 * * V_67 , T_3 V_68 )
{
T_2 * V_58 = NULL , * V_59 = NULL ;
long V_69 ;
int V_29 = 0 ;
V_58 = F_21 ( F_1 () ) ;
if ( V_58 == NULL )
goto V_70;
V_59 = F_21 ( F_1 () ) ;
if ( V_59 == NULL )
goto V_70;
if ( V_66 )
{
V_69 = F_22 ( V_58 , V_66 ) ;
if ( ! V_69 )
goto V_70;
}
if ( V_68 )
{
V_69 = F_22 ( V_59 , V_68 ) ;
if ( ! V_69 )
goto V_70;
}
V_69 = F_23 ( V_58 , V_59 ) ;
if ( ! V_69 )
goto V_70;
V_29 = 1 ;
V_70:
if ( V_29 == 0 )
{
if ( V_58 )
{
F_24 ( V_58 ) ;
V_58 = NULL ;
}
if ( V_59 )
{
F_24 ( V_59 ) ;
V_59 = NULL ;
}
}
* V_65 = V_58 ;
* V_67 = V_59 ;
return V_29 ;
}
T_3 F_25 ( T_2 * V_2 )
{
return F_26 ( V_2 , V_39 , 0 , NULL ) ;
}
T_3 F_27 ( T_2 * V_2 )
{
return F_26 ( V_2 , V_40 , 0 , NULL ) ;
}
int F_28 ( T_2 * V_2 )
{
return ( F_26 ( V_2 , V_41 , 0 , NULL ) != 0 ) ;
}
int F_29 ( T_2 * V_2 , char * * V_7 )
{
long V_29 ;
if ( ! V_2 -> V_12 )
{
F_13 ( V_71 , V_72 ) ;
return - 2 ;
}
V_29 = F_26 ( V_2 , V_43 , 0 , V_7 ) ;
if ( V_29 > V_73 )
return V_73 ;
else
return ( int ) V_29 ;
}
int F_30 ( T_2 * V_2 , char * * V_7 , int V_18 )
{
int V_29 ;
if ( ! V_2 -> V_12 )
{
F_13 ( V_74 , V_72 ) ;
return - 2 ;
}
V_29 = ( int ) F_26 ( V_2 , V_44 , V_18 , V_7 ) ;
if ( V_29 > 0 )
V_2 -> V_75 += V_29 ;
return V_29 ;
}
int F_31 ( T_2 * V_2 , char * * V_7 )
{
long V_29 ;
if ( ! V_2 -> V_12 )
{
F_13 ( V_26 , V_72 ) ;
return - 2 ;
}
V_29 = F_26 ( V_2 , V_45 , 0 , V_7 ) ;
if ( V_29 > V_73 )
return V_73 ;
else
return ( int ) V_29 ;
}
int F_32 ( T_2 * V_2 , char * * V_7 , int V_18 )
{
int V_29 ;
if ( ! V_2 -> V_12 )
{
F_13 ( V_76 , V_72 ) ;
return - 2 ;
}
V_29 = F_26 ( V_2 , V_46 , V_18 , V_7 ) ;
if ( V_29 > 0 )
V_2 -> V_77 += V_29 ;
return V_29 ;
}
