int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 ;
if ( V_2 == NULL ) {
F_2 ( V_4 , V_5 ) ;
return ( 0 ) ;
}
V_3 = F_3 ( V_1 , NULL , V_2 , 0 , 1 ) ;
if ( V_3 != 1 ) {
F_2 ( V_4 , V_3 ) ;
return 0 ;
}
return ( F_4 ( V_1 -> V_6 , V_2 ) ) ;
}
int F_5 ( T_1 * V_1 , const char * V_7 , int type )
{
int V_8 ;
T_3 * V_9 ;
int V_10 = 0 ;
T_2 * V_2 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL ) {
F_2 ( V_11 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 ) {
F_2 ( V_11 , V_14 ) ;
goto V_13;
}
if ( type == V_15 ) {
V_8 = V_16 ;
V_2 = F_9 ( V_9 , NULL ) ;
} else if ( type == V_17 ) {
V_8 = V_18 ;
V_2 = F_10 ( V_9 , NULL , V_1 -> V_19 -> V_20 ,
V_1 -> V_19 -> V_21 ) ;
} else {
F_2 ( V_11 , V_22 ) ;
goto V_13;
}
if ( V_2 == NULL ) {
F_2 ( V_11 , V_8 ) ;
goto V_13;
}
V_10 = F_1 ( V_1 , V_2 ) ;
V_13:
F_11 ( V_2 ) ;
F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_13 ( T_1 * V_1 , const unsigned char * V_23 , int V_24 )
{
T_2 * V_2 ;
int V_10 ;
V_2 = F_14 ( NULL , & V_23 , ( long ) V_24 ) ;
if ( V_2 == NULL ) {
F_2 ( V_25 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_1 ( V_1 , V_2 ) ;
F_11 ( V_2 ) ;
return ( V_10 ) ;
}
int F_15 ( T_1 * V_1 , T_4 * V_26 )
{
T_5 * V_27 ;
int V_10 ;
if ( V_26 == NULL ) {
F_2 ( V_28 , V_5 ) ;
return ( 0 ) ;
}
if ( ( V_27 = F_16 () ) == NULL ) {
F_2 ( V_28 , V_29 ) ;
return ( 0 ) ;
}
F_17 ( V_26 ) ;
if ( F_18 ( V_27 , V_26 ) <= 0 ) {
F_19 ( V_26 ) ;
F_20 ( V_27 ) ;
return 0 ;
}
V_10 = F_21 ( V_1 -> V_6 , V_27 ) ;
F_20 ( V_27 ) ;
return ( V_10 ) ;
}
static int F_21 ( T_6 * V_30 , T_5 * V_27 )
{
int V_31 ;
V_31 = F_22 ( NULL , V_27 ) ;
if ( V_31 < 0 ) {
F_2 ( V_32 , V_33 ) ;
return ( 0 ) ;
}
if ( V_30 -> V_34 [ V_31 ] . V_35 != NULL ) {
T_5 * V_36 ;
V_36 = F_23 ( V_30 -> V_34 [ V_31 ] . V_35 ) ;
if ( V_36 == NULL ) {
F_2 ( V_32 , V_37 ) ;
return 0 ;
}
F_24 ( V_36 , V_27 ) ;
F_25 () ;
#ifndef F_26
if ( F_27 ( V_27 ) == V_38
&& F_28 ( F_29 ( V_27 ) ) & V_39 ) ;
else
#endif
if ( ! F_30 ( V_30 -> V_34 [ V_31 ] . V_35 , V_27 ) ) {
F_11 ( V_30 -> V_34 [ V_31 ] . V_35 ) ;
V_30 -> V_34 [ V_31 ] . V_35 = NULL ;
return 0 ;
}
}
F_20 ( V_30 -> V_34 [ V_31 ] . V_40 ) ;
F_31 ( V_27 ) ;
V_30 -> V_34 [ V_31 ] . V_40 = V_27 ;
V_30 -> V_41 = & ( V_30 -> V_34 [ V_31 ] ) ;
return ( 1 ) ;
}
int F_32 ( T_1 * V_1 , const char * V_7 , int type )
{
int V_8 , V_10 = 0 ;
T_3 * V_9 ;
T_4 * V_26 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL ) {
F_2 ( V_42 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 ) {
F_2 ( V_42 , V_14 ) ;
goto V_13;
}
if ( type == V_15 ) {
V_8 = V_16 ;
V_26 = F_33 ( V_9 , NULL ) ;
} else if ( type == V_17 ) {
V_8 = V_18 ;
V_26 = F_34 ( V_9 , NULL ,
V_1 -> V_19 -> V_20 ,
V_1 ->
V_19 -> V_21 ) ;
} else {
F_2 ( V_42 , V_22 ) ;
goto V_13;
}
if ( V_26 == NULL ) {
F_2 ( V_42 , V_8 ) ;
goto V_13;
}
V_10 = F_15 ( V_1 , V_26 ) ;
F_19 ( V_26 ) ;
V_13:
F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_35 ( T_1 * V_1 , const unsigned char * V_23 , long V_24 )
{
int V_10 ;
const unsigned char * V_43 ;
T_4 * V_26 ;
V_43 = V_23 ;
if ( ( V_26 = F_36 ( NULL , & V_43 , ( long ) V_24 ) ) == NULL ) {
F_2 ( V_44 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_15 ( V_1 , V_26 ) ;
F_19 ( V_26 ) ;
return ( V_10 ) ;
}
int F_37 ( T_1 * V_1 , T_5 * V_27 )
{
int V_10 ;
if ( V_27 == NULL ) {
F_2 ( V_45 , V_5 ) ;
return ( 0 ) ;
}
V_10 = F_21 ( V_1 -> V_6 , V_27 ) ;
return ( V_10 ) ;
}
int F_38 ( T_1 * V_1 , const char * V_7 , int type )
{
int V_8 , V_10 = 0 ;
T_3 * V_9 ;
T_5 * V_27 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL ) {
F_2 ( V_46 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 ) {
F_2 ( V_46 , V_14 ) ;
goto V_13;
}
if ( type == V_17 ) {
V_8 = V_18 ;
V_27 = F_39 ( V_9 , NULL ,
V_1 -> V_19 -> V_20 ,
V_1 ->
V_19 -> V_21 ) ;
} else if ( type == V_15 ) {
V_8 = V_16 ;
V_27 = F_40 ( V_9 , NULL ) ;
} else {
F_2 ( V_46 , V_22 ) ;
goto V_13;
}
if ( V_27 == NULL ) {
F_2 ( V_46 , V_8 ) ;
goto V_13;
}
V_10 = F_37 ( V_1 , V_27 ) ;
F_20 ( V_27 ) ;
V_13:
F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_41 ( int type , T_1 * V_1 , const unsigned char * V_23 ,
long V_24 )
{
int V_10 ;
const unsigned char * V_43 ;
T_5 * V_27 ;
V_43 = V_23 ;
if ( ( V_27 = F_42 ( type , NULL , & V_43 , ( long ) V_24 ) ) == NULL ) {
F_2 ( V_47 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_37 ( V_1 , V_27 ) ;
F_20 ( V_27 ) ;
return ( V_10 ) ;
}
int F_43 ( T_7 * V_19 , T_2 * V_2 )
{
int V_3 ;
if ( V_2 == NULL ) {
F_2 ( V_48 , V_5 ) ;
return ( 0 ) ;
}
V_3 = F_3 ( NULL , V_19 , V_2 , 0 , 1 ) ;
if ( V_3 != 1 ) {
F_2 ( V_48 , V_3 ) ;
return 0 ;
}
return ( F_4 ( V_19 -> V_6 , V_2 ) ) ;
}
static int F_4 ( T_6 * V_30 , T_2 * V_2 )
{
T_5 * V_27 ;
int V_31 ;
V_27 = F_23 ( V_2 ) ;
if ( V_27 == NULL ) {
F_2 ( V_49 , V_50 ) ;
return ( 0 ) ;
}
V_31 = F_22 ( V_2 , V_27 ) ;
if ( V_31 < 0 ) {
F_2 ( V_49 , V_33 ) ;
return 0 ;
}
#ifndef F_44
if ( V_31 == V_51 && ! F_45 ( F_46 ( V_27 ) ) ) {
F_2 ( V_49 , V_52 ) ;
return 0 ;
}
#endif
if ( V_30 -> V_34 [ V_31 ] . V_40 != NULL ) {
F_24 ( V_27 , V_30 -> V_34 [ V_31 ] . V_40 ) ;
F_25 () ;
#ifndef F_26
if ( F_27 ( V_30 -> V_34 [ V_31 ] . V_40 ) == V_38
&& F_28 ( F_29 ( V_30 -> V_34 [ V_31 ] . V_40 ) ) &
V_39 ) ;
else
#endif
if ( ! F_30 ( V_2 , V_30 -> V_34 [ V_31 ] . V_40 ) ) {
F_20 ( V_30 -> V_34 [ V_31 ] . V_40 ) ;
V_30 -> V_34 [ V_31 ] . V_40 = NULL ;
F_25 () ;
}
}
F_11 ( V_30 -> V_34 [ V_31 ] . V_35 ) ;
F_47 ( V_2 ) ;
V_30 -> V_34 [ V_31 ] . V_35 = V_2 ;
V_30 -> V_41 = & ( V_30 -> V_34 [ V_31 ] ) ;
return 1 ;
}
int F_48 ( T_7 * V_19 , const char * V_7 , int type )
{
int V_8 ;
T_3 * V_9 ;
int V_10 = 0 ;
T_2 * V_2 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL ) {
F_2 ( V_53 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 ) {
F_2 ( V_53 , V_14 ) ;
goto V_13;
}
if ( type == V_15 ) {
V_8 = V_16 ;
V_2 = F_9 ( V_9 , NULL ) ;
} else if ( type == V_17 ) {
V_8 = V_18 ;
V_2 = F_10 ( V_9 , NULL , V_19 -> V_20 ,
V_19 -> V_21 ) ;
} else {
F_2 ( V_53 , V_22 ) ;
goto V_13;
}
if ( V_2 == NULL ) {
F_2 ( V_53 , V_8 ) ;
goto V_13;
}
V_10 = F_43 ( V_19 , V_2 ) ;
V_13:
F_11 ( V_2 ) ;
F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_49 ( T_7 * V_19 , int V_24 , const unsigned char * V_23 )
{
T_2 * V_2 ;
int V_10 ;
V_2 = F_14 ( NULL , & V_23 , ( long ) V_24 ) ;
if ( V_2 == NULL ) {
F_2 ( V_54 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_43 ( V_19 , V_2 ) ;
F_11 ( V_2 ) ;
return ( V_10 ) ;
}
int F_50 ( T_7 * V_19 , T_4 * V_26 )
{
int V_10 ;
T_5 * V_27 ;
if ( V_26 == NULL ) {
F_2 ( V_55 , V_5 ) ;
return ( 0 ) ;
}
if ( ( V_27 = F_16 () ) == NULL ) {
F_2 ( V_55 , V_29 ) ;
return ( 0 ) ;
}
F_17 ( V_26 ) ;
if ( F_18 ( V_27 , V_26 ) <= 0 ) {
F_19 ( V_26 ) ;
F_20 ( V_27 ) ;
return 0 ;
}
V_10 = F_21 ( V_19 -> V_6 , V_27 ) ;
F_20 ( V_27 ) ;
return ( V_10 ) ;
}
int F_51 ( T_7 * V_19 , const char * V_7 , int type )
{
int V_8 , V_10 = 0 ;
T_3 * V_9 ;
T_4 * V_26 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL ) {
F_2 ( V_56 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 ) {
F_2 ( V_56 , V_14 ) ;
goto V_13;
}
if ( type == V_15 ) {
V_8 = V_16 ;
V_26 = F_33 ( V_9 , NULL ) ;
} else if ( type == V_17 ) {
V_8 = V_18 ;
V_26 = F_34 ( V_9 , NULL ,
V_19 -> V_20 ,
V_19 -> V_21 ) ;
} else {
F_2 ( V_56 , V_22 ) ;
goto V_13;
}
if ( V_26 == NULL ) {
F_2 ( V_56 , V_8 ) ;
goto V_13;
}
V_10 = F_50 ( V_19 , V_26 ) ;
F_19 ( V_26 ) ;
V_13:
F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_52 ( T_7 * V_19 , const unsigned char * V_23 ,
long V_24 )
{
int V_10 ;
const unsigned char * V_43 ;
T_4 * V_26 ;
V_43 = V_23 ;
if ( ( V_26 = F_36 ( NULL , & V_43 , ( long ) V_24 ) ) == NULL ) {
F_2 ( V_57 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_50 ( V_19 , V_26 ) ;
F_19 ( V_26 ) ;
return ( V_10 ) ;
}
int F_53 ( T_7 * V_19 , T_5 * V_27 )
{
if ( V_27 == NULL ) {
F_2 ( V_58 , V_5 ) ;
return ( 0 ) ;
}
return ( F_21 ( V_19 -> V_6 , V_27 ) ) ;
}
int F_54 ( T_7 * V_19 , const char * V_7 , int type )
{
int V_8 , V_10 = 0 ;
T_3 * V_9 ;
T_5 * V_27 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL ) {
F_2 ( V_59 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 ) {
F_2 ( V_59 , V_14 ) ;
goto V_13;
}
if ( type == V_17 ) {
V_8 = V_18 ;
V_27 = F_39 ( V_9 , NULL ,
V_19 -> V_20 ,
V_19 -> V_21 ) ;
} else if ( type == V_15 ) {
V_8 = V_16 ;
V_27 = F_40 ( V_9 , NULL ) ;
} else {
F_2 ( V_59 , V_22 ) ;
goto V_13;
}
if ( V_27 == NULL ) {
F_2 ( V_59 , V_8 ) ;
goto V_13;
}
V_10 = F_53 ( V_19 , V_27 ) ;
F_20 ( V_27 ) ;
V_13:
F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_55 ( int type , T_7 * V_19 ,
const unsigned char * V_23 , long V_24 )
{
int V_10 ;
const unsigned char * V_43 ;
T_5 * V_27 ;
V_43 = V_23 ;
if ( ( V_27 = F_42 ( type , NULL , & V_43 , ( long ) V_24 ) ) == NULL ) {
F_2 ( V_60 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_53 ( V_19 , V_27 ) ;
F_20 ( V_27 ) ;
return ( V_10 ) ;
}
static int F_56 ( T_7 * V_19 , T_1 * V_1 , const char * V_7 )
{
T_3 * V_9 ;
int V_10 = 0 ;
T_2 * V_2 = NULL ;
T_8 * V_61 ;
void * V_62 ;
F_25 () ;
if ( V_19 != NULL ) {
V_61 = V_19 -> V_20 ;
V_62 = V_19 -> V_21 ;
} else {
V_61 = V_1 -> V_20 ;
V_62 = V_1 -> V_21 ;
}
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL ) {
F_2 ( V_63 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 ) {
F_2 ( V_63 , V_14 ) ;
goto V_13;
}
V_2 = F_57 ( V_9 , NULL , V_61 ,
V_62 ) ;
if ( V_2 == NULL ) {
F_2 ( V_63 , V_18 ) ;
goto V_13;
}
if ( V_19 )
V_10 = F_43 ( V_19 , V_2 ) ;
else
V_10 = F_1 ( V_1 , V_2 ) ;
if ( F_58 () != 0 )
V_10 = 0 ;
if ( V_10 ) {
T_2 * V_64 ;
int V_65 ;
unsigned long V_66 ;
if ( V_19 )
V_65 = F_59 ( V_19 ) ;
else
V_65 = F_60 ( V_1 ) ;
if ( V_65 == 0 ) {
V_10 = 0 ;
goto V_13;
}
while ( ( V_64 = F_10 ( V_9 , NULL , V_61 ,
V_62 ) )
!= NULL ) {
if ( V_19 )
V_65 = F_61 ( V_19 , V_64 ) ;
else
V_65 = F_62 ( V_1 , V_64 ) ;
if ( ! V_65 ) {
F_11 ( V_64 ) ;
V_10 = 0 ;
goto V_13;
}
}
V_66 = F_63 () ;
if ( F_64 ( V_66 ) == V_67
&& F_65 ( V_66 ) == V_68 )
F_25 () ;
else
V_10 = 0 ;
}
V_13:
F_11 ( V_2 ) ;
F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_66 ( T_7 * V_19 , const char * V_7 )
{
return F_56 ( V_19 , NULL , V_7 ) ;
}
int F_67 ( T_1 * V_1 , const char * V_7 )
{
return F_56 ( NULL , V_1 , V_7 ) ;
}
static int F_68 ( const unsigned char * V_69 ,
T_9 V_70 ,
unsigned int V_71 ,
const unsigned char * * V_72 ,
T_9 * V_73 )
{
* V_72 = NULL ;
* V_73 = 0 ;
if ( V_69 == NULL || V_70 == 0 )
return - 1 ;
for (; ; ) {
unsigned int type = 0 ;
T_9 V_24 = 0 ;
if ( V_70 == 0 )
return 0 ;
if ( V_70 < 2 )
return - 1 ;
type = ( V_69 [ 0 ] << 8 ) + V_69 [ 1 ] ;
V_69 += 2 ;
V_70 -= 2 ;
if ( V_70 < 2 )
return - 1 ;
V_24 = ( V_69 [ 0 ] << 8 ) + V_69 [ 1 ] ;
V_69 += 2 ;
V_70 -= 2 ;
if ( V_24 > V_70 )
return - 1 ;
if ( type == V_71 ) {
* V_72 = V_69 ;
* V_73 = V_24 ;
return 1 ;
}
V_69 += V_24 ;
V_70 -= V_24 ;
}
}
static int F_69 ( T_1 * V_74 , unsigned int V_75 ,
const unsigned char * V_9 ,
T_9 V_76 , int * V_77 , void * V_78 )
{
if ( V_76 != 0 ) {
* V_77 = V_79 ;
return 0 ;
}
return 1 ;
}
static int F_70 ( T_1 * V_74 , unsigned int V_75 ,
const unsigned char * * V_80 , T_9 * V_81 ,
int * V_77 , void * V_78 )
{
const unsigned char * V_69 = NULL ;
T_9 V_70 = 0 ;
if ( ( F_71 ( V_74 , & V_69 ,
& V_70 ) ) != 0 ) {
int V_82 = F_68 ( V_69 , V_70 ,
V_75 , V_80 , V_81 ) ;
if ( V_82 == - 1 ) {
* V_77 = V_79 ;
return - 1 ;
}
if ( V_82 == 0 )
return 0 ;
return 1 ;
}
return 0 ;
}
static int F_72 ( const unsigned char * V_69 ,
T_9 V_70 , T_7 * V_19 )
{
if ( V_69 == NULL || V_70 == 0 )
return 0 ;
for (; ; ) {
unsigned int V_75 = 0 ;
T_9 V_24 = 0 ;
if ( V_70 == 0 )
return 1 ;
if ( V_70 < 2 )
return 0 ;
V_75 = ( V_69 [ 0 ] << 8 ) + V_69 [ 1 ] ;
if ( V_19 ) {
int V_83 = 0 ;
T_9 V_31 ;
T_10 * V_84 = & V_19 -> V_6 -> V_85 ;
T_11 * V_86 = V_84 -> V_87 ;
for ( V_31 = 0 ; V_31 < V_84 -> V_88 ; V_31 ++ , V_86 ++ ) {
if ( V_75 == V_86 -> V_75 ) {
V_83 = 1 ;
break;
}
}
if ( ! V_83 && ! F_73 ( V_19 , V_75 ,
F_70 ,
NULL , NULL ,
F_69 ,
NULL ) )
return 0 ;
}
V_69 += 2 ;
V_70 -= 2 ;
if ( V_70 < 2 )
return 0 ;
V_24 = ( V_69 [ 0 ] << 8 ) + V_69 [ 1 ] ;
V_69 += 2 ;
V_70 -= 2 ;
if ( V_24 > V_70 )
return 0 ;
V_69 += V_24 ;
V_70 -= V_24 ;
}
}
int F_74 ( T_7 * V_19 , const unsigned char * V_69 ,
T_9 V_70 )
{
unsigned char * V_89 ;
if ( V_19 == NULL || V_69 == NULL || V_70 == 0 ) {
F_2 ( V_90 , V_5 ) ;
return 0 ;
}
if ( ! F_72 ( V_69 , V_70 , NULL ) ) {
F_2 ( V_90 , V_91 ) ;
return 0 ;
}
if ( V_19 -> V_6 -> V_41 == NULL ) {
F_2 ( V_90 , V_92 ) ;
return 0 ;
}
V_89 = F_75 ( V_19 -> V_6 -> V_41 -> V_69 ,
V_70 ) ;
if ( V_89 == NULL ) {
F_2 ( V_90 , V_37 ) ;
return 0 ;
}
V_19 -> V_6 -> V_41 -> V_69 = V_89 ;
memcpy ( V_19 -> V_6 -> V_41 -> V_69 , V_69 , V_70 ) ;
V_19 -> V_6 -> V_41 -> V_70 = V_70 ;
if ( ! F_72 ( V_69 , V_70 , V_19 ) ) {
F_2 ( V_90 , V_91 ) ;
return 0 ;
}
return 1 ;
}
int F_76 ( T_7 * V_19 , const char * V_7 )
{
unsigned char * V_69 = NULL ;
unsigned char * V_93 ;
T_9 V_70 = 0 ;
unsigned char * V_94 = 0 ;
long V_73 = 0 ;
char * V_95 = NULL ;
char * V_96 = NULL ;
char V_97 [] = L_1 ;
int V_10 = 0 ;
T_3 * V_98 = NULL ;
T_9 V_99 = 0 ;
if ( V_19 == NULL || V_7 == NULL ) {
F_2 ( V_100 , V_5 ) ;
goto V_13;
}
V_98 = F_6 ( F_7 () ) ;
if ( V_98 == NULL ) {
F_2 ( V_100 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_98 , V_7 ) <= 0 ) {
F_2 ( V_100 , V_14 ) ;
goto V_13;
}
for ( V_99 = 0 ; ; V_99 ++ ) {
if ( F_77 ( V_98 , & V_95 , & V_96 , & V_94 , & V_73 )
== 0 ) {
if ( V_99 == 0 ) {
F_2 ( V_100 ,
V_101 ) ;
goto V_13;
} else
break;
}
if ( strlen ( V_95 ) < strlen ( V_97 ) ) {
F_2 ( V_100 , V_102 ) ;
goto V_13;
}
if ( strncmp ( V_95 , V_97 , strlen ( V_97 ) ) != 0 ) {
F_2 ( V_100 ,
V_103 ) ;
goto V_13;
}
if ( V_73 < 4
|| ( V_94 [ 2 ] << 8 ) + V_94 [ 3 ] != V_73 - 4 ) {
F_2 ( V_100 , V_104 ) ;
goto V_13;
}
V_93 = F_75 ( V_69 , V_70 + V_73 ) ;
if ( V_93 == NULL ) {
F_2 ( V_100 , V_37 ) ;
goto V_13;
}
V_69 = V_93 ;
memcpy ( V_69 + V_70 , V_94 , V_73 ) ;
V_70 += V_73 ;
F_78 ( V_95 ) ;
V_95 = NULL ;
F_78 ( V_96 ) ;
V_96 = NULL ;
F_78 ( V_94 ) ;
V_94 = NULL ;
}
V_10 = F_74 ( V_19 , V_69 , V_70 ) ;
V_13:
F_78 ( V_95 ) ;
F_78 ( V_96 ) ;
F_78 ( V_94 ) ;
F_78 ( V_69 ) ;
F_12 ( V_98 ) ;
return V_10 ;
}
