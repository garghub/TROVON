int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
if ( V_2 == NULL ) {
F_2 ( V_3 , V_4 ) ;
return ( 0 ) ;
}
if ( ! F_3 ( & V_1 -> V_5 ) ) {
F_2 ( V_3 , V_6 ) ;
return ( 0 ) ;
}
return ( F_4 ( V_1 -> V_5 , V_2 ) ) ;
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
if ( V_2 != NULL )
F_11 ( V_2 ) ;
if ( V_9 != NULL )
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
F_2 ( V_28 , V_4 ) ;
return ( 0 ) ;
}
if ( ! F_3 ( & V_1 -> V_5 ) ) {
F_2 ( V_28 , V_6 ) ;
return ( 0 ) ;
}
if ( ( V_27 = F_16 () ) == NULL ) {
F_2 ( V_28 , V_29 ) ;
return ( 0 ) ;
}
F_17 ( V_26 ) ;
F_18 ( V_27 , V_26 ) ;
V_10 = F_19 ( V_1 -> V_5 , V_27 ) ;
F_20 ( V_27 ) ;
return ( V_10 ) ;
}
static int F_19 ( T_6 * V_30 , T_5 * V_27 )
{
int V_31 ;
if ( V_27 -> type == V_32 ) {
T_2 * V_2 ;
V_31 = - 1 ;
V_2 = V_30 -> V_33 [ V_34 ] . V_35 ;
if ( V_2 && F_21 ( V_2 , V_27 ) )
V_31 = V_34 ;
V_2 = V_30 -> V_33 [ V_36 ] . V_35 ;
if ( V_31 == - 1 && V_2 && F_21 ( V_2 , V_27 ) )
V_31 = V_36 ;
F_22 () ;
} else
V_31 = F_23 ( NULL , V_27 ) ;
if ( V_31 < 0 ) {
F_2 ( V_37 , V_38 ) ;
return ( 0 ) ;
}
if ( V_30 -> V_33 [ V_31 ] . V_35 != NULL ) {
T_5 * V_39 ;
V_39 = F_24 ( V_30 -> V_33 [ V_31 ] . V_35 ) ;
F_25 ( V_39 , V_27 ) ;
F_20 ( V_39 ) ;
F_22 () ;
#ifndef F_26
if ( ( V_27 -> type == V_40 ) &&
( F_27 ( V_27 -> V_27 . V_26 ) & V_41 ) ) ;
else
#endif
if ( ! F_21 ( V_30 -> V_33 [ V_31 ] . V_35 , V_27 ) ) {
F_11 ( V_30 -> V_33 [ V_31 ] . V_35 ) ;
V_30 -> V_33 [ V_31 ] . V_35 = NULL ;
return 0 ;
}
}
if ( V_30 -> V_33 [ V_31 ] . V_42 != NULL )
F_20 ( V_30 -> V_33 [ V_31 ] . V_42 ) ;
F_28 ( & V_27 -> V_43 , 1 , V_44 ) ;
V_30 -> V_33 [ V_31 ] . V_42 = V_27 ;
V_30 -> V_45 = & ( V_30 -> V_33 [ V_31 ] ) ;
V_30 -> V_46 = 0 ;
return ( 1 ) ;
}
int F_29 ( T_1 * V_1 , const char * V_7 , int type )
{
int V_8 , V_10 = 0 ;
T_3 * V_9 ;
T_4 * V_26 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL ) {
F_2 ( V_47 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 ) {
F_2 ( V_47 , V_14 ) ;
goto V_13;
}
if ( type == V_15 ) {
V_8 = V_16 ;
V_26 = F_30 ( V_9 , NULL ) ;
} else if ( type == V_17 ) {
V_8 = V_18 ;
V_26 = F_31 ( V_9 , NULL ,
V_1 -> V_19 -> V_20 ,
V_1 ->
V_19 -> V_21 ) ;
} else {
F_2 ( V_47 , V_22 ) ;
goto V_13;
}
if ( V_26 == NULL ) {
F_2 ( V_47 , V_8 ) ;
goto V_13;
}
V_10 = F_15 ( V_1 , V_26 ) ;
F_32 ( V_26 ) ;
V_13:
if ( V_9 != NULL )
F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_33 ( T_1 * V_1 , unsigned char * V_23 , long V_24 )
{
int V_10 ;
const unsigned char * V_48 ;
T_4 * V_26 ;
V_48 = V_23 ;
if ( ( V_26 = F_34 ( NULL , & V_48 , ( long ) V_24 ) ) == NULL ) {
F_2 ( V_49 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_15 ( V_1 , V_26 ) ;
F_32 ( V_26 ) ;
return ( V_10 ) ;
}
int F_35 ( T_1 * V_1 , T_5 * V_27 )
{
int V_10 ;
if ( V_27 == NULL ) {
F_2 ( V_50 , V_4 ) ;
return ( 0 ) ;
}
if ( ! F_3 ( & V_1 -> V_5 ) ) {
F_2 ( V_50 , V_6 ) ;
return ( 0 ) ;
}
V_10 = F_19 ( V_1 -> V_5 , V_27 ) ;
return ( V_10 ) ;
}
int F_36 ( T_1 * V_1 , const char * V_7 , int type )
{
int V_8 , V_10 = 0 ;
T_3 * V_9 ;
T_5 * V_27 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL ) {
F_2 ( V_51 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 ) {
F_2 ( V_51 , V_14 ) ;
goto V_13;
}
if ( type == V_17 ) {
V_8 = V_18 ;
V_27 = F_37 ( V_9 , NULL ,
V_1 -> V_19 -> V_20 ,
V_1 ->
V_19 -> V_21 ) ;
} else if ( type == V_15 ) {
V_8 = V_16 ;
V_27 = F_38 ( V_9 , NULL ) ;
} else {
F_2 ( V_51 , V_22 ) ;
goto V_13;
}
if ( V_27 == NULL ) {
F_2 ( V_51 , V_8 ) ;
goto V_13;
}
V_10 = F_35 ( V_1 , V_27 ) ;
F_20 ( V_27 ) ;
V_13:
if ( V_9 != NULL )
F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_39 ( int type , T_1 * V_1 , const unsigned char * V_23 ,
long V_24 )
{
int V_10 ;
const unsigned char * V_48 ;
T_5 * V_27 ;
V_48 = V_23 ;
if ( ( V_27 = F_40 ( type , NULL , & V_48 , ( long ) V_24 ) ) == NULL ) {
F_2 ( V_52 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_35 ( V_1 , V_27 ) ;
F_20 ( V_27 ) ;
return ( V_10 ) ;
}
int F_41 ( T_7 * V_19 , T_2 * V_2 )
{
if ( V_2 == NULL ) {
F_2 ( V_53 , V_4 ) ;
return ( 0 ) ;
}
if ( ! F_3 ( & V_19 -> V_5 ) ) {
F_2 ( V_53 , V_6 ) ;
return ( 0 ) ;
}
return ( F_4 ( V_19 -> V_5 , V_2 ) ) ;
}
static int F_4 ( T_6 * V_30 , T_2 * V_2 )
{
T_5 * V_27 ;
int V_31 ;
V_27 = F_24 ( V_2 ) ;
if ( V_27 == NULL ) {
F_2 ( V_54 , V_55 ) ;
return ( 0 ) ;
}
V_31 = F_23 ( V_2 , V_27 ) ;
if ( V_31 < 0 ) {
F_2 ( V_54 , V_38 ) ;
F_20 ( V_27 ) ;
return ( 0 ) ;
}
if ( V_30 -> V_33 [ V_31 ] . V_42 != NULL ) {
F_25 ( V_27 , V_30 -> V_33 [ V_31 ] . V_42 ) ;
F_22 () ;
#ifndef F_26
if ( ( V_30 -> V_33 [ V_31 ] . V_42 -> type == V_40 ) &&
( F_27 ( V_30 -> V_33 [ V_31 ] . V_42 -> V_27 . V_26 ) &
V_41 ) ) ;
else
#endif
if ( ! F_21 ( V_2 , V_30 -> V_33 [ V_31 ] . V_42 ) ) {
F_20 ( V_30 -> V_33 [ V_31 ] . V_42 ) ;
V_30 -> V_33 [ V_31 ] . V_42 = NULL ;
F_22 () ;
}
}
F_20 ( V_27 ) ;
if ( V_30 -> V_33 [ V_31 ] . V_35 != NULL )
F_11 ( V_30 -> V_33 [ V_31 ] . V_35 ) ;
F_28 ( & V_2 -> V_43 , 1 , V_56 ) ;
V_30 -> V_33 [ V_31 ] . V_35 = V_2 ;
V_30 -> V_45 = & ( V_30 -> V_33 [ V_31 ] ) ;
V_30 -> V_46 = 0 ;
return ( 1 ) ;
}
int F_42 ( T_7 * V_19 , const char * V_7 , int type )
{
int V_8 ;
T_3 * V_9 ;
int V_10 = 0 ;
T_2 * V_2 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL ) {
F_2 ( V_57 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 ) {
F_2 ( V_57 , V_14 ) ;
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
F_2 ( V_57 , V_22 ) ;
goto V_13;
}
if ( V_2 == NULL ) {
F_2 ( V_57 , V_8 ) ;
goto V_13;
}
V_10 = F_41 ( V_19 , V_2 ) ;
V_13:
if ( V_2 != NULL )
F_11 ( V_2 ) ;
if ( V_9 != NULL )
F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_43 ( T_7 * V_19 , int V_24 ,
const unsigned char * V_23 )
{
T_2 * V_2 ;
int V_10 ;
V_2 = F_14 ( NULL , & V_23 , ( long ) V_24 ) ;
if ( V_2 == NULL ) {
F_2 ( V_58 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_41 ( V_19 , V_2 ) ;
F_11 ( V_2 ) ;
return ( V_10 ) ;
}
int F_44 ( T_7 * V_19 , T_4 * V_26 )
{
int V_10 ;
T_5 * V_27 ;
if ( V_26 == NULL ) {
F_2 ( V_59 , V_4 ) ;
return ( 0 ) ;
}
if ( ! F_3 ( & V_19 -> V_5 ) ) {
F_2 ( V_59 , V_6 ) ;
return ( 0 ) ;
}
if ( ( V_27 = F_16 () ) == NULL ) {
F_2 ( V_59 , V_29 ) ;
return ( 0 ) ;
}
F_17 ( V_26 ) ;
F_18 ( V_27 , V_26 ) ;
V_10 = F_19 ( V_19 -> V_5 , V_27 ) ;
F_20 ( V_27 ) ;
return ( V_10 ) ;
}
int F_45 ( T_7 * V_19 , const char * V_7 , int type )
{
int V_8 , V_10 = 0 ;
T_3 * V_9 ;
T_4 * V_26 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL ) {
F_2 ( V_60 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 ) {
F_2 ( V_60 , V_14 ) ;
goto V_13;
}
if ( type == V_15 ) {
V_8 = V_16 ;
V_26 = F_30 ( V_9 , NULL ) ;
} else if ( type == V_17 ) {
V_8 = V_18 ;
V_26 = F_31 ( V_9 , NULL ,
V_19 -> V_20 ,
V_19 -> V_21 ) ;
} else {
F_2 ( V_60 , V_22 ) ;
goto V_13;
}
if ( V_26 == NULL ) {
F_2 ( V_60 , V_8 ) ;
goto V_13;
}
V_10 = F_44 ( V_19 , V_26 ) ;
F_32 ( V_26 ) ;
V_13:
if ( V_9 != NULL )
F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_46 ( T_7 * V_19 , const unsigned char * V_23 ,
long V_24 )
{
int V_10 ;
const unsigned char * V_48 ;
T_4 * V_26 ;
V_48 = V_23 ;
if ( ( V_26 = F_34 ( NULL , & V_48 , ( long ) V_24 ) ) == NULL ) {
F_2 ( V_61 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_44 ( V_19 , V_26 ) ;
F_32 ( V_26 ) ;
return ( V_10 ) ;
}
int F_47 ( T_7 * V_19 , T_5 * V_27 )
{
if ( V_27 == NULL ) {
F_2 ( V_62 , V_4 ) ;
return ( 0 ) ;
}
if ( ! F_3 ( & V_19 -> V_5 ) ) {
F_2 ( V_62 , V_6 ) ;
return ( 0 ) ;
}
return ( F_19 ( V_19 -> V_5 , V_27 ) ) ;
}
int F_48 ( T_7 * V_19 , const char * V_7 , int type )
{
int V_8 , V_10 = 0 ;
T_3 * V_9 ;
T_5 * V_27 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL ) {
F_2 ( V_63 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 ) {
F_2 ( V_63 , V_14 ) ;
goto V_13;
}
if ( type == V_17 ) {
V_8 = V_18 ;
V_27 = F_37 ( V_9 , NULL ,
V_19 -> V_20 ,
V_19 -> V_21 ) ;
} else if ( type == V_15 ) {
V_8 = V_16 ;
V_27 = F_38 ( V_9 , NULL ) ;
} else {
F_2 ( V_63 , V_22 ) ;
goto V_13;
}
if ( V_27 == NULL ) {
F_2 ( V_63 , V_8 ) ;
goto V_13;
}
V_10 = F_47 ( V_19 , V_27 ) ;
F_20 ( V_27 ) ;
V_13:
if ( V_9 != NULL )
F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_49 ( int type , T_7 * V_19 ,
const unsigned char * V_23 , long V_24 )
{
int V_10 ;
const unsigned char * V_48 ;
T_5 * V_27 ;
V_48 = V_23 ;
if ( ( V_27 = F_40 ( type , NULL , & V_48 , ( long ) V_24 ) ) == NULL ) {
F_2 ( V_64 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_47 ( V_19 , V_27 ) ;
F_20 ( V_27 ) ;
return ( V_10 ) ;
}
int F_50 ( T_7 * V_19 , const char * V_7 )
{
T_3 * V_9 ;
int V_10 = 0 ;
T_2 * V_2 = NULL ;
F_22 () ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL ) {
F_2 ( V_65 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 ) {
F_2 ( V_65 , V_14 ) ;
goto V_13;
}
V_2 = F_51 ( V_9 , NULL , V_19 -> V_20 ,
V_19 -> V_21 ) ;
if ( V_2 == NULL ) {
F_2 ( V_65 , V_18 ) ;
goto V_13;
}
V_10 = F_41 ( V_19 , V_2 ) ;
if ( F_52 () != 0 )
V_10 = 0 ;
if ( V_10 ) {
T_2 * V_66 ;
int V_67 ;
unsigned long V_68 ;
F_53 ( V_19 ) ;
while ( ( V_66 = F_10 ( V_9 , NULL ,
V_19 -> V_20 ,
V_19 -> V_21 ) )
!= NULL ) {
V_67 = F_54 ( V_19 , V_66 ) ;
if ( ! V_67 ) {
F_11 ( V_66 ) ;
V_10 = 0 ;
goto V_13;
}
}
V_68 = F_55 () ;
if ( F_56 ( V_68 ) == V_69
&& F_57 ( V_68 ) == V_70 )
F_22 () ;
else
V_10 = 0 ;
}
V_13:
if ( V_2 != NULL )
F_11 ( V_2 ) ;
if ( V_9 != NULL )
F_12 ( V_9 ) ;
return ( V_10 ) ;
}
static int F_58 ( const unsigned char * V_71 ,
T_8 V_72 ,
unsigned int V_73 ,
const unsigned char * * V_74 ,
T_8 * V_75 )
{
* V_74 = NULL ;
* V_75 = 0 ;
if ( V_71 == NULL || V_72 == 0 )
return 0 ;
for (; ; ) {
unsigned int type = 0 ;
T_8 V_24 = 0 ;
if ( V_72 == 0 )
return - 1 ;
if ( V_72 < 2 )
return 0 ;
type = ( V_71 [ 0 ] << 8 ) + V_71 [ 1 ] ;
V_71 += 2 ;
V_72 -= 2 ;
if ( V_72 < 2 )
return 0 ;
V_24 = ( V_71 [ 0 ] << 8 ) + V_71 [ 1 ] ;
V_71 += 2 ;
V_72 -= 2 ;
if ( V_24 > V_72 )
return 0 ;
if ( type == V_73 ) {
* V_74 = V_71 ;
* V_75 = V_24 ;
return 1 ;
}
V_71 += V_24 ;
V_72 -= V_24 ;
}
return 0 ;
}
static int F_59 ( T_1 * V_76 , unsigned int V_77 ,
const unsigned char * V_9 ,
T_8 V_78 , int * V_79 , void * V_80 )
{
if ( V_78 != 0 ) {
* V_79 = V_81 ;
return 0 ;
}
return 1 ;
}
static int F_60 ( T_1 * V_76 , unsigned int V_77 ,
const unsigned char * * V_82 , T_8 * V_83 ,
int * V_79 , void * V_80 )
{
const unsigned char * V_71 = NULL ;
T_8 V_72 = 0 ;
if ( ( F_61 ( V_76 , & V_71 ,
& V_72 ) ) != 0 ) {
int V_84 = F_58 ( V_71 , V_72 ,
V_77 , V_82 , V_83 ) ;
if ( V_84 == 0 )
return 0 ;
if ( V_84 == - 1 )
return - 1 ;
return 1 ;
}
return - 1 ;
}
static int F_62 ( const unsigned char * V_71 ,
T_8 V_72 , T_7 * V_19 )
{
if ( V_71 == NULL || V_72 == 0 )
return 0 ;
for (; ; ) {
unsigned int V_77 = 0 ;
T_8 V_24 = 0 ;
if ( V_72 == 0 )
return 1 ;
if ( V_72 < 2 )
return 0 ;
V_77 = ( V_71 [ 0 ] << 8 ) + V_71 [ 1 ] ;
if ( V_19 && ! F_63 ( V_19 , V_77 ,
F_60 ,
NULL , NULL ,
F_59 ,
NULL ) )
return 0 ;
V_71 += 2 ;
V_72 -= 2 ;
if ( V_72 < 2 )
return 0 ;
V_24 = ( V_71 [ 0 ] << 8 ) + V_71 [ 1 ] ;
V_71 += 2 ;
V_72 -= 2 ;
if ( V_24 > V_72 )
return 0 ;
V_71 += V_24 ;
V_72 -= V_24 ;
}
}
int F_64 ( T_7 * V_19 , const unsigned char * V_71 ,
T_8 V_72 )
{
if ( V_19 == NULL || V_71 == NULL || V_72 == 0 ) {
F_2 ( V_85 , V_4 ) ;
return 0 ;
}
if ( ! F_62 ( V_71 , V_72 , NULL ) ) {
F_2 ( V_85 , V_86 ) ;
return 0 ;
}
if ( ! F_3 ( & V_19 -> V_5 ) ) {
F_2 ( V_85 , V_6 ) ;
return 0 ;
}
if ( V_19 -> V_5 -> V_45 == NULL ) {
F_2 ( V_85 , V_87 ) ;
return 0 ;
}
V_19 -> V_5 -> V_45 -> V_71 = F_65 ( V_19 -> V_5 -> V_45 -> V_71 ,
V_72 ) ;
if ( V_19 -> V_5 -> V_45 -> V_71 == NULL ) {
F_2 ( V_85 , V_6 ) ;
return 0 ;
}
memcpy ( V_19 -> V_5 -> V_45 -> V_71 , V_71 , V_72 ) ;
V_19 -> V_5 -> V_45 -> V_72 = V_72 ;
if ( ! F_62 ( V_71 , V_72 , V_19 ) ) {
F_2 ( V_85 , V_86 ) ;
return 0 ;
}
return 1 ;
}
int F_66 ( T_7 * V_19 , const char * V_7 )
{
unsigned char * V_71 = NULL ;
T_8 V_72 = 0 ;
unsigned char * V_88 = 0 ;
long V_75 = 0 ;
char * V_89 = NULL ;
char * V_90 = NULL ;
char V_91 [] = L_1 ;
int V_10 = 0 ;
T_3 * V_92 = NULL ;
T_8 V_93 = 0 ;
if ( V_19 == NULL || V_7 == NULL ) {
F_2 ( V_94 ,
V_4 ) ;
goto V_13;
}
V_92 = F_6 ( F_7 () ) ;
if ( V_92 == NULL ) {
F_2 ( V_94 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_92 , V_7 ) <= 0 ) {
F_2 ( V_94 , V_14 ) ;
goto V_13;
}
for ( V_93 = 0 ; ; V_93 ++ ) {
if ( F_67 ( V_92 , & V_89 , & V_90 , & V_88 , & V_75 )
== 0 ) {
if ( V_93 == 0 ) {
F_2 ( V_94 ,
V_95 ) ;
goto V_13;
} else
break;
}
if ( strlen ( V_89 ) < strlen ( V_91 ) ) {
F_2 ( V_94 ,
V_96 ) ;
goto V_13;
}
if ( strncmp ( V_89 , V_91 , strlen ( V_91 ) ) != 0 ) {
F_2 ( V_94 ,
V_97 ) ;
goto V_13;
}
if ( V_75 < 4
|| ( V_88 [ 2 ] << 8 ) + V_88 [ 3 ] != V_75 - 4 ) {
F_2 ( V_94 , V_98 ) ;
goto V_13;
}
V_71 =
F_65 ( V_71 , V_72 + V_75 ) ;
if ( V_71 == NULL ) {
F_2 ( V_94 , V_6 ) ;
goto V_13;
}
memcpy ( V_71 + V_72 , V_88 , V_75 ) ;
V_72 += V_75 ;
F_68 ( V_89 ) ;
V_89 = NULL ;
F_68 ( V_90 ) ;
V_90 = NULL ;
F_68 ( V_88 ) ;
V_88 = NULL ;
}
V_10 = F_64 ( V_19 , V_71 , V_72 ) ;
V_13:
F_68 ( V_89 ) ;
F_68 ( V_90 ) ;
F_68 ( V_88 ) ;
F_68 ( V_71 ) ;
if ( V_92 != NULL )
F_12 ( V_92 ) ;
return V_10 ;
}
