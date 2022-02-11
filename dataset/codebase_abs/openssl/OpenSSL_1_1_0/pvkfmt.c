static unsigned int F_1 ( const unsigned char * * V_1 )
{
const unsigned char * V_2 = * V_1 ;
unsigned int V_3 ;
V_3 = * V_2 ++ ;
V_3 |= ( * V_2 ++ << 8 ) ;
V_3 |= ( * V_2 ++ << 16 ) ;
V_3 |= ( * V_2 ++ << 24 ) ;
* V_1 = V_2 ;
return V_3 ;
}
static int F_2 ( const unsigned char * * V_1 , unsigned int V_4 , T_1 * * V_5 )
{
* V_5 = F_3 ( * V_1 , V_4 , NULL ) ;
if ( * V_5 == NULL )
return 0 ;
* V_1 += V_4 ;
return 1 ;
}
static int F_4 ( const unsigned char * * V_1 , unsigned int V_6 ,
unsigned int * V_7 , unsigned int * V_8 ,
int * V_9 , int * V_10 )
{
const unsigned char * V_2 = * V_1 ;
if ( V_6 < 16 )
return 0 ;
if ( * V_2 == V_11 ) {
if ( * V_10 == 0 ) {
F_5 ( V_12 , V_13 ) ;
return 0 ;
}
* V_10 = 1 ;
} else if ( * V_2 == V_14 ) {
if ( * V_10 == 1 ) {
F_5 ( V_12 , V_15 ) ;
return 0 ;
}
* V_10 = 0 ;
} else
return 0 ;
V_2 ++ ;
if ( * V_2 ++ != 0x2 ) {
F_5 ( V_12 , V_16 ) ;
return 0 ;
}
V_2 += 6 ;
* V_7 = F_1 ( & V_2 ) ;
* V_8 = F_1 ( & V_2 ) ;
* V_9 = 0 ;
switch ( * V_7 ) {
case V_17 :
* V_9 = 1 ;
case V_18 :
if ( * V_10 == 0 ) {
F_5 ( V_12 , V_13 ) ;
return 0 ;
}
break;
case V_19 :
* V_9 = 1 ;
case V_20 :
if ( * V_10 == 1 ) {
F_5 ( V_12 , V_15 ) ;
return 0 ;
}
break;
default:
F_5 ( V_12 , V_21 ) ;
return - 1 ;
}
* V_1 = V_2 ;
return 1 ;
}
static unsigned int F_6 ( unsigned V_22 , int V_23 , int V_24 )
{
unsigned int V_4 , V_25 ;
V_4 = ( V_22 + 7 ) >> 3 ;
V_25 = ( V_22 + 15 ) >> 4 ;
if ( V_23 ) {
if ( V_24 )
return 44 + 3 * V_4 ;
else
return 64 + 2 * V_4 ;
} else {
if ( V_24 )
return 4 + V_4 ;
else
return 4 + 2 * V_4 + 5 * V_25 ;
}
}
static T_2 * F_7 ( const unsigned char * * V_1 , unsigned int V_6 ,
int V_24 )
{
const unsigned char * V_2 = * V_1 ;
unsigned int V_22 , V_26 ;
int V_23 ;
if ( F_4 ( & V_2 , V_6 , & V_26 , & V_22 , & V_23 , & V_24 ) <= 0 ) {
F_5 ( V_27 , V_28 ) ;
return NULL ;
}
V_6 -= 16 ;
if ( V_6 < F_6 ( V_22 , V_23 , V_24 ) ) {
F_5 ( V_27 , V_29 ) ;
return NULL ;
}
if ( V_23 )
return F_8 ( & V_2 , V_22 , V_24 ) ;
else
return F_9 ( & V_2 , V_22 , V_24 ) ;
}
static T_2 * F_10 ( T_3 * V_1 , int V_24 )
{
const unsigned char * V_2 ;
unsigned char V_30 [ 16 ] , * V_31 = NULL ;
unsigned int V_22 , V_26 , V_6 ;
int V_23 ;
T_2 * V_3 = NULL ;
if ( F_11 ( V_1 , V_30 , 16 ) != 16 ) {
F_5 ( V_32 , V_29 ) ;
return NULL ;
}
V_2 = V_30 ;
if ( F_4 ( & V_2 , 16 , & V_26 , & V_22 , & V_23 , & V_24 ) <= 0 )
return NULL ;
V_6 = F_6 ( V_22 , V_23 , V_24 ) ;
if ( V_6 > V_33 ) {
F_5 ( V_32 , V_34 ) ;
return NULL ;
}
V_31 = F_12 ( V_6 ) ;
if ( V_31 == NULL ) {
F_5 ( V_32 , V_35 ) ;
goto V_36;
}
V_2 = V_31 ;
if ( F_11 ( V_1 , V_31 , V_6 ) != ( int ) V_6 ) {
F_5 ( V_32 , V_29 ) ;
goto V_36;
}
if ( V_23 )
V_3 = F_8 ( & V_2 , V_22 , V_24 ) ;
else
V_3 = F_9 ( & V_2 , V_22 , V_24 ) ;
V_36:
F_13 ( V_31 ) ;
return V_3 ;
}
static T_2 * F_8 ( const unsigned char * * V_1 ,
unsigned int V_22 , int V_24 )
{
const unsigned char * V_2 = * V_1 ;
T_2 * V_3 = NULL ;
T_4 * V_37 = NULL ;
T_5 * V_38 = NULL ;
unsigned int V_4 ;
T_1 * V_39 = NULL , * V_40 = NULL , * V_41 = NULL , * V_42 = NULL ;
T_1 * V_43 = NULL ;
V_4 = ( V_22 + 7 ) >> 3 ;
V_37 = F_14 () ;
V_3 = F_15 () ;
if ( V_37 == NULL || V_3 == NULL )
goto V_44;
if ( ! F_2 ( & V_2 , V_4 , & V_39 ) )
goto V_44;
if ( ! F_2 ( & V_2 , 20 , & V_40 ) )
goto V_44;
if ( ! F_2 ( & V_2 , V_4 , & V_41 ) )
goto V_44;
if ( V_24 ) {
if ( ! F_2 ( & V_2 , V_4 , & V_43 ) )
goto V_44;
} else {
if ( ! F_2 ( & V_2 , 20 , & V_42 ) )
goto V_44;
V_43 = F_16 () ;
if ( V_43 == NULL )
goto V_44;
if ( ( V_38 = F_17 () ) == NULL )
goto V_44;
if ( ! F_18 ( V_43 , V_41 , V_42 , V_39 , V_38 ) )
goto V_44;
F_19 ( V_38 ) ;
}
if ( ! F_20 ( V_37 , V_39 , V_40 , V_41 ) )
goto V_44;
V_39 = V_40 = V_41 = NULL ;
if ( ! F_21 ( V_37 , V_43 , V_42 ) )
goto V_44;
F_22 ( V_3 , V_37 ) ;
F_23 ( V_37 ) ;
* V_1 = V_2 ;
return V_3 ;
V_44:
F_5 ( V_45 , V_35 ) ;
F_23 ( V_37 ) ;
F_24 ( V_39 ) ;
F_24 ( V_40 ) ;
F_24 ( V_41 ) ;
F_24 ( V_43 ) ;
F_24 ( V_42 ) ;
F_25 ( V_3 ) ;
F_19 ( V_38 ) ;
return NULL ;
}
static T_2 * F_9 ( const unsigned char * * V_1 ,
unsigned int V_22 , int V_24 )
{
const unsigned char * V_46 = * V_1 ;
T_2 * V_3 = NULL ;
T_1 * V_47 = NULL , * V_48 = NULL , * V_49 = NULL ;
T_1 * V_2 = NULL , * V_50 = NULL , * V_51 = NULL , * V_52 = NULL , * V_53 = NULL ;
T_6 * V_54 = NULL ;
unsigned int V_4 , V_25 ;
V_4 = ( V_22 + 7 ) >> 3 ;
V_25 = ( V_22 + 15 ) >> 4 ;
V_54 = F_26 () ;
V_3 = F_15 () ;
if ( V_54 == NULL || V_3 == NULL )
goto V_44;
V_47 = F_16 () ;
if ( V_47 == NULL )
goto V_44;
if ( ! F_27 ( V_47 , F_1 ( & V_46 ) ) )
goto V_44;
if ( ! F_2 ( & V_46 , V_4 , & V_48 ) )
goto V_44;
if ( ! V_24 ) {
if ( ! F_2 ( & V_46 , V_25 , & V_2 ) )
goto V_44;
if ( ! F_2 ( & V_46 , V_25 , & V_50 ) )
goto V_44;
if ( ! F_2 ( & V_46 , V_25 , & V_51 ) )
goto V_44;
if ( ! F_2 ( & V_46 , V_25 , & V_52 ) )
goto V_44;
if ( ! F_2 ( & V_46 , V_25 , & V_53 ) )
goto V_44;
if ( ! F_2 ( & V_46 , V_4 , & V_49 ) )
goto V_44;
F_28 ( V_54 , V_2 , V_50 ) ;
F_29 ( V_54 , V_51 , V_52 , V_53 ) ;
}
F_30 ( V_54 , V_48 , V_47 , V_49 ) ;
F_31 ( V_3 , V_54 ) ;
F_32 ( V_54 ) ;
* V_1 = V_46 ;
return V_3 ;
V_44:
F_5 ( V_55 , V_35 ) ;
F_24 ( V_47 ) ;
F_24 ( V_48 ) ;
F_24 ( V_2 ) ;
F_24 ( V_50 ) ;
F_24 ( V_51 ) ;
F_24 ( V_52 ) ;
F_24 ( V_53 ) ;
F_24 ( V_49 ) ;
F_32 ( V_54 ) ;
F_25 ( V_3 ) ;
return NULL ;
}
T_2 * F_33 ( const unsigned char * * V_1 , long V_6 )
{
return F_7 ( V_1 , V_6 , 0 ) ;
}
T_2 * F_34 ( const unsigned char * * V_1 , long V_6 )
{
return F_7 ( V_1 , V_6 , 1 ) ;
}
T_2 * F_35 ( T_3 * V_1 )
{
return F_10 ( V_1 , 0 ) ;
}
T_2 * F_36 ( T_3 * V_1 )
{
return F_10 ( V_1 , 1 ) ;
}
static void F_37 ( unsigned char * * V_56 , unsigned int V_57 )
{
unsigned char * V_2 = * V_56 ;
* V_2 ++ = V_57 & 0xff ;
* V_2 ++ = ( V_57 >> 8 ) & 0xff ;
* V_2 ++ = ( V_57 >> 16 ) & 0xff ;
* V_2 ++ = ( V_57 >> 24 ) & 0xff ;
* V_56 = V_2 ;
}
static void F_38 ( unsigned char * * V_56 , const T_1 * V_58 , int V_59 )
{
F_39 ( V_58 , * V_56 , V_59 ) ;
* V_56 += V_59 ;
}
static int F_40 ( unsigned char * * V_56 , T_2 * V_60 , int V_24 )
{
unsigned char * V_2 ;
unsigned int V_22 , V_26 = 0 , V_61 ;
int V_62 , V_63 = 0 ;
int V_64 = F_41 ( V_60 ) ;
if ( V_64 == V_65 ) {
V_22 = F_42 ( F_43 ( V_60 ) , V_24 , & V_26 ) ;
V_61 = V_66 ;
} else if ( V_64 == V_67 ) {
V_22 = F_44 ( F_45 ( V_60 ) , V_24 , & V_26 ) ;
V_61 = V_68 ;
} else
return - 1 ;
if ( V_22 == 0 )
return - 1 ;
V_62 = 16 + F_6 ( V_22 ,
V_61 == V_66 ? 1 : 0 , V_24 ) ;
if ( V_56 == NULL )
return V_62 ;
if ( * V_56 )
V_2 = * V_56 ;
else {
V_2 = F_12 ( V_62 ) ;
if ( V_2 == NULL )
return - 1 ;
* V_56 = V_2 ;
V_63 = 1 ;
}
if ( V_24 )
* V_2 ++ = V_11 ;
else
* V_2 ++ = V_14 ;
* V_2 ++ = 0x2 ;
* V_2 ++ = 0 ;
* V_2 ++ = 0 ;
F_37 ( & V_2 , V_61 ) ;
F_37 ( & V_2 , V_26 ) ;
F_37 ( & V_2 , V_22 ) ;
if ( V_61 == V_66 )
F_46 ( & V_2 , F_43 ( V_60 ) , V_24 ) ;
else
F_47 ( & V_2 , F_45 ( V_60 ) , V_24 ) ;
if ( ! V_63 )
* V_56 += V_62 ;
return V_62 ;
}
static int F_48 ( T_3 * V_56 , T_2 * V_60 , int V_24 )
{
unsigned char * V_69 = NULL ;
int V_62 , V_70 ;
V_62 = F_40 ( & V_69 , V_60 , V_24 ) ;
if ( V_62 < 0 )
return - 1 ;
V_70 = F_49 ( V_56 , V_69 , V_62 ) ;
F_13 ( V_69 ) ;
if ( V_70 == V_62 )
return V_62 ;
return - 1 ;
}
static int F_42 ( T_4 * V_37 , int V_24 , unsigned int * V_7 )
{
int V_22 ;
const T_1 * V_2 = NULL , * V_50 = NULL , * V_71 = NULL ;
const T_1 * V_43 = NULL , * V_42 = NULL ;
F_50 ( V_37 , & V_2 , & V_50 , & V_71 ) ;
F_51 ( V_37 , & V_43 , & V_42 ) ;
V_22 = F_52 ( V_2 ) ;
if ( ( V_22 & 7 ) || ( F_52 ( V_50 ) != 160 )
|| ( F_52 ( V_71 ) > V_22 ) )
goto V_72;
if ( V_24 ) {
if ( F_52 ( V_43 ) > V_22 )
goto V_72;
* V_7 = V_17 ;
} else {
if ( F_52 ( V_42 ) > 160 )
goto V_72;
* V_7 = V_19 ;
}
return V_22 ;
V_72:
F_5 ( V_73 , V_74 ) ;
return 0 ;
}
static int F_44 ( T_6 * V_54 , int V_24 , unsigned int * V_7 )
{
int V_4 , V_25 , V_22 ;
const T_1 * V_47 ;
F_53 ( V_54 , NULL , & V_47 , NULL ) ;
if ( F_52 ( V_47 ) > 32 )
goto V_72;
V_22 = F_54 ( V_54 ) ;
V_4 = F_55 ( V_54 ) ;
V_25 = ( V_22 + 15 ) >> 4 ;
if ( V_24 ) {
* V_7 = V_18 ;
return V_22 ;
} else {
const T_1 * V_49 , * V_2 , * V_50 , * V_53 , * V_51 , * V_52 ;
* V_7 = V_20 ;
F_53 ( V_54 , NULL , NULL , & V_49 ) ;
if ( F_56 ( V_49 ) > V_4 )
goto V_72;
F_57 ( V_54 , & V_2 , & V_50 ) ;
F_58 ( V_54 , & V_51 , & V_52 , & V_53 ) ;
if ( ( F_56 ( V_53 ) > V_25 )
|| ( F_56 ( V_2 ) > V_25 )
|| ( F_56 ( V_50 ) > V_25 )
|| ( F_56 ( V_51 ) > V_25 )
|| ( F_56 ( V_52 ) > V_25 ) )
goto V_72;
}
return V_22 ;
V_72:
F_5 ( V_75 , V_74 ) ;
return 0 ;
}
static void F_47 ( unsigned char * * V_56 , T_6 * V_54 , int V_24 )
{
int V_4 , V_25 ;
const T_1 * V_48 , * V_49 , * V_47 , * V_2 , * V_50 , * V_53 , * V_51 , * V_52 ;
V_4 = F_55 ( V_54 ) ;
V_25 = ( F_54 ( V_54 ) + 15 ) >> 4 ;
F_53 ( V_54 , & V_48 , & V_47 , & V_49 ) ;
F_38 ( V_56 , V_47 , 4 ) ;
F_38 ( V_56 , V_48 , - 1 ) ;
if ( V_24 )
return;
F_57 ( V_54 , & V_2 , & V_50 ) ;
F_58 ( V_54 , & V_51 , & V_52 , & V_53 ) ;
F_38 ( V_56 , V_2 , V_25 ) ;
F_38 ( V_56 , V_50 , V_25 ) ;
F_38 ( V_56 , V_51 , V_25 ) ;
F_38 ( V_56 , V_52 , V_25 ) ;
F_38 ( V_56 , V_53 , V_25 ) ;
F_38 ( V_56 , V_49 , V_4 ) ;
}
static void F_46 ( unsigned char * * V_56 , T_4 * V_37 , int V_24 )
{
int V_4 ;
const T_1 * V_2 = NULL , * V_50 = NULL , * V_71 = NULL ;
const T_1 * V_43 = NULL , * V_42 = NULL ;
F_50 ( V_37 , & V_2 , & V_50 , & V_71 ) ;
F_51 ( V_37 , & V_43 , & V_42 ) ;
V_4 = F_56 ( V_2 ) ;
F_38 ( V_56 , V_2 , V_4 ) ;
F_38 ( V_56 , V_50 , 20 ) ;
F_38 ( V_56 , V_71 , V_4 ) ;
if ( V_24 )
F_38 ( V_56 , V_43 , V_4 ) ;
else
F_38 ( V_56 , V_42 , 20 ) ;
memset ( * V_56 , 0xff , 24 ) ;
* V_56 += 24 ;
return;
}
int F_59 ( T_3 * V_56 , T_2 * V_60 )
{
return F_48 ( V_56 , V_60 , 0 ) ;
}
int F_60 ( T_3 * V_56 , T_2 * V_60 )
{
return F_48 ( V_56 , V_60 , 1 ) ;
}
static int F_61 ( const unsigned char * * V_1 , unsigned int V_6 ,
int V_76 ,
unsigned int * V_77 , unsigned int * V_78 )
{
const unsigned char * V_2 = * V_1 ;
unsigned int V_79 , V_80 ;
if ( V_76 ) {
if ( V_6 < 20 ) {
F_5 ( V_81 , V_82 ) ;
return 0 ;
}
} else {
if ( V_6 < 24 ) {
F_5 ( V_81 , V_82 ) ;
return 0 ;
}
V_79 = F_1 ( & V_2 ) ;
if ( V_79 != V_83 ) {
F_5 ( V_81 , V_21 ) ;
return 0 ;
}
}
V_2 += 4 ;
F_1 ( & V_2 ) ;
V_80 = F_1 ( & V_2 ) ;
* V_77 = F_1 ( & V_2 ) ;
* V_78 = F_1 ( & V_2 ) ;
if ( * V_78 > V_84 || * V_77 > V_85 )
return 0 ;
if ( V_80 && ! * V_77 ) {
F_5 ( V_81 , V_86 ) ;
return 0 ;
}
* V_1 = V_2 ;
return 1 ;
}
static int F_62 ( unsigned char * V_87 ,
const unsigned char * V_88 , unsigned int V_89 ,
const unsigned char * V_90 , int V_91 )
{
T_7 * V_92 = F_63 () ;
int V_93 = 1 ;
if ( V_92 == NULL
|| ! F_64 ( V_92 , F_65 () , NULL )
|| ! F_66 ( V_92 , V_88 , V_89 )
|| ! F_66 ( V_92 , V_90 , V_91 )
|| ! F_67 ( V_92 , V_87 , NULL ) )
V_93 = 0 ;
F_68 ( V_92 ) ;
return V_93 ;
}
static T_2 * F_69 ( const unsigned char * * V_1 ,
unsigned int V_89 , unsigned int V_94 ,
T_8 * V_95 , void * V_96 )
{
T_2 * V_3 = NULL ;
const unsigned char * V_2 = * V_1 ;
unsigned int V_26 ;
unsigned char * V_97 = NULL , * V_50 ;
T_9 * V_98 = F_70 () ;
if ( V_89 ) {
char V_99 [ V_100 ] ;
unsigned char V_101 [ 20 ] ;
int V_102 , V_103 ;
if ( V_95 )
V_103 = V_95 ( V_99 , V_100 , 0 , V_96 ) ;
else
V_103 = F_71 ( V_99 , V_100 , 0 , V_96 ) ;
if ( V_103 <= 0 ) {
F_5 ( V_104 , V_105 ) ;
goto V_36;
}
V_97 = F_12 ( V_94 + 8 ) ;
if ( V_97 == NULL ) {
F_5 ( V_104 , V_35 ) ;
goto V_36;
}
if ( ! F_62 ( V_101 , V_2 , V_89 ,
( unsigned char * ) V_99 , V_103 ) )
goto V_36;
V_2 += V_89 ;
memcpy ( V_97 , V_2 , 8 ) ;
V_2 += 8 ;
if ( V_94 < 8 ) {
F_5 ( V_104 , V_82 ) ;
goto V_36;
}
V_103 = V_94 - 8 ;
V_50 = V_97 + 8 ;
if ( ! F_72 ( V_98 , F_73 () , NULL , V_101 , NULL ) )
goto V_36;
if ( ! F_74 ( V_98 , V_50 , & V_102 , V_2 , V_103 ) )
goto V_36;
if ( ! F_75 ( V_98 , V_50 + V_102 , & V_102 ) )
goto V_36;
V_26 = F_1 ( ( const unsigned char * * ) & V_50 ) ;
if ( V_26 != V_20 && V_26 != V_19 ) {
V_50 = V_97 + 8 ;
memset ( V_101 + 5 , 0 , 11 ) ;
if ( ! F_72 ( V_98 , F_73 () , NULL , V_101 , NULL ) )
goto V_36;
F_76 ( V_101 , 20 ) ;
if ( ! F_74 ( V_98 , V_50 , & V_102 , V_2 , V_103 ) )
goto V_36;
if ( ! F_75 ( V_98 , V_50 + V_102 , & V_102 ) )
goto V_36;
V_26 = F_1 ( ( const unsigned char * * ) & V_50 ) ;
if ( V_26 != V_20 && V_26 != V_19 ) {
F_5 ( V_104 , V_106 ) ;
goto V_36;
}
} else
F_76 ( V_101 , 20 ) ;
V_2 = V_97 ;
}
V_3 = F_33 ( & V_2 , V_94 ) ;
V_36:
F_77 ( V_98 ) ;
F_13 ( V_97 ) ;
return V_3 ;
}
T_2 * F_78 ( T_3 * V_1 , T_8 * V_95 , void * V_96 )
{
unsigned char V_107 [ 24 ] , * V_31 = NULL ;
const unsigned char * V_2 ;
int V_108 ;
T_2 * V_3 = NULL ;
unsigned int V_89 , V_94 ;
if ( F_11 ( V_1 , V_107 , 24 ) != 24 ) {
F_5 ( V_109 , V_110 ) ;
return NULL ;
}
V_2 = V_107 ;
if ( ! F_61 ( & V_2 , 24 , 0 , & V_89 , & V_94 ) )
return 0 ;
V_108 = ( int ) V_94 + V_89 ;
V_31 = F_12 ( V_108 ) ;
if ( V_31 == NULL ) {
F_5 ( V_109 , V_35 ) ;
return 0 ;
}
V_2 = V_31 ;
if ( F_11 ( V_1 , V_31 , V_108 ) != V_108 ) {
F_5 ( V_109 , V_110 ) ;
goto V_36;
}
V_3 = F_69 ( & V_2 , V_89 , V_94 , V_95 , V_96 ) ;
V_36:
F_79 ( V_31 , V_108 ) ;
return V_3 ;
}
static int F_80 ( unsigned char * * V_56 , T_2 * V_60 , int V_111 ,
T_8 * V_95 , void * V_96 )
{
int V_62 = 24 , V_112 ;
unsigned char * V_2 = NULL , * V_113 = NULL , * V_88 = NULL ;
T_9 * V_98 = NULL ;
if ( V_111 )
V_62 += V_114 ;
V_112 = F_40 ( NULL , V_60 , 0 ) ;
if ( V_112 < 0 )
return - 1 ;
V_62 += V_112 ;
if ( V_56 == NULL )
return V_62 ;
if ( * V_56 != NULL ) {
V_2 = * V_56 ;
} else {
V_113 = V_2 = F_12 ( V_62 ) ;
if ( V_2 == NULL ) {
F_5 ( V_115 , V_35 ) ;
return - 1 ;
}
}
V_98 = F_70 () ;
if ( V_98 == NULL )
goto error;
F_37 ( & V_2 , V_83 ) ;
F_37 ( & V_2 , 0 ) ;
if ( F_41 ( V_60 ) == V_65 )
F_37 ( & V_2 , V_116 ) ;
else
F_37 ( & V_2 , V_117 ) ;
F_37 ( & V_2 , V_111 ? 1 : 0 ) ;
F_37 ( & V_2 , V_111 ? V_114 : 0 ) ;
F_37 ( & V_2 , V_112 ) ;
if ( V_111 ) {
if ( F_81 ( V_2 , V_114 ) <= 0 )
goto error;
V_88 = V_2 ;
V_2 += V_114 ;
}
F_40 ( & V_2 , V_60 , 0 ) ;
if ( V_111 != 0 ) {
char V_99 [ V_100 ] ;
unsigned char V_101 [ 20 ] ;
int V_102 , V_103 ;
if ( V_95 )
V_103 = V_95 ( V_99 , V_100 , 1 , V_96 ) ;
else
V_103 = F_71 ( V_99 , V_100 , 1 , V_96 ) ;
if ( V_103 <= 0 ) {
F_5 ( V_115 , V_105 ) ;
goto error;
}
if ( ! F_62 ( V_101 , V_88 , V_114 ,
( unsigned char * ) V_99 , V_103 ) )
goto error;
if ( V_111 == 1 )
memset ( V_101 + 5 , 0 , 11 ) ;
V_2 = V_88 + V_114 + 8 ;
if ( ! F_82 ( V_98 , F_73 () , NULL , V_101 , NULL ) )
goto error;
F_76 ( V_101 , 20 ) ;
if ( ! F_74 ( V_98 , V_2 , & V_102 , V_2 , V_112 - 8 ) )
goto error;
if ( ! F_75 ( V_98 , V_2 + V_102 , & V_102 ) )
goto error;
}
F_77 ( V_98 ) ;
if ( * V_56 == NULL )
* V_56 = V_113 ;
return V_62 ;
error:
F_77 ( V_98 ) ;
if ( * V_56 == NULL )
F_13 ( V_113 ) ;
return - 1 ;
}
int F_83 ( T_3 * V_56 , T_2 * V_60 , int V_111 ,
T_8 * V_95 , void * V_96 )
{
unsigned char * V_69 = NULL ;
int V_62 , V_70 ;
V_62 = F_80 ( & V_69 , V_60 , V_111 , V_95 , V_96 ) ;
if ( V_62 < 0 )
return - 1 ;
V_70 = F_49 ( V_56 , V_69 , V_62 ) ;
F_13 ( V_69 ) ;
if ( V_70 == V_62 ) {
F_5 ( V_118 , V_119 ) ;
return V_62 ;
}
return - 1 ;
}
