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
const unsigned char * V_2 ;
unsigned char * V_6 , * V_7 ;
unsigned int V_8 ;
V_2 = * V_1 + V_4 - 1 ;
V_6 = F_3 ( V_4 ) ;
if ( ! V_6 )
return 0 ;
V_7 = V_6 ;
for ( V_8 = 0 ; V_8 < V_4 ; V_8 ++ )
* V_7 ++ = * V_2 -- ;
* V_5 = F_4 ( V_6 , V_4 , NULL ) ;
F_5 ( V_6 ) ;
if ( * V_5 ) {
* V_1 += V_4 ;
return 1 ;
} else
return 0 ;
}
static int F_6 ( const unsigned char * * V_1 , unsigned int V_9 ,
unsigned int * V_10 , unsigned int * V_11 ,
int * V_12 , int * V_13 )
{
const unsigned char * V_2 = * V_1 ;
if ( V_9 < 16 )
return 0 ;
if ( * V_2 == V_14 ) {
if ( * V_13 == 0 ) {
F_7 ( V_15 , V_16 ) ;
return 0 ;
}
* V_13 = 1 ;
} else if ( * V_2 == V_17 ) {
if ( * V_13 == 1 ) {
F_7 ( V_15 , V_18 ) ;
return 0 ;
}
* V_13 = 0 ;
} else
return 0 ;
V_2 ++ ;
if ( * V_2 ++ != 0x2 ) {
F_7 ( V_15 , V_19 ) ;
return 0 ;
}
V_2 += 6 ;
* V_10 = F_1 ( & V_2 ) ;
* V_11 = F_1 ( & V_2 ) ;
* V_12 = 0 ;
switch ( * V_10 ) {
case V_20 :
* V_12 = 1 ;
case V_21 :
if ( * V_13 == 0 ) {
F_7 ( V_15 , V_16 ) ;
return 0 ;
}
break;
case V_22 :
* V_12 = 1 ;
case V_23 :
if ( * V_13 == 1 ) {
F_7 ( V_15 , V_18 ) ;
return 0 ;
}
break;
default:
F_7 ( V_15 , V_24 ) ;
return - 1 ;
}
* V_1 = V_2 ;
return 1 ;
}
static unsigned int F_8 ( unsigned V_25 , int V_26 , int V_27 )
{
unsigned int V_4 , V_28 ;
V_4 = ( V_25 + 7 ) >> 3 ;
V_28 = ( V_25 + 15 ) >> 4 ;
if ( V_26 ) {
if ( V_27 )
return 44 + 3 * V_4 ;
else
return 64 + 2 * V_4 ;
} else {
if ( V_27 )
return 4 + V_4 ;
else
return 4 + 2 * V_4 + 5 * V_28 ;
}
}
static T_2 * F_9 ( const unsigned char * * V_1 , unsigned int V_9 ,
int V_27 )
{
const unsigned char * V_2 = * V_1 ;
unsigned int V_25 , V_29 ;
int V_26 ;
if ( F_6 ( & V_2 , V_9 , & V_29 , & V_25 , & V_26 , & V_27 ) <= 0 ) {
F_7 ( V_30 , V_31 ) ;
return NULL ;
}
V_9 -= 16 ;
if ( V_9 < F_8 ( V_25 , V_26 , V_27 ) ) {
F_7 ( V_30 , V_32 ) ;
return NULL ;
}
if ( V_26 )
return F_10 ( & V_2 , V_9 , V_25 , V_27 ) ;
else
return F_11 ( & V_2 , V_9 , V_25 , V_27 ) ;
}
static T_2 * F_12 ( T_3 * V_1 , int V_27 )
{
const unsigned char * V_2 ;
unsigned char V_33 [ 16 ] , * V_34 = NULL ;
unsigned int V_25 , V_29 , V_9 ;
int V_26 ;
T_2 * V_3 = NULL ;
if ( F_13 ( V_1 , V_33 , 16 ) != 16 ) {
F_7 ( V_35 , V_32 ) ;
return NULL ;
}
V_2 = V_33 ;
if ( F_6 ( & V_2 , 16 , & V_29 , & V_25 , & V_26 , & V_27 ) <= 0 )
return NULL ;
V_9 = F_8 ( V_25 , V_26 , V_27 ) ;
V_34 = F_3 ( V_9 ) ;
if ( ! V_34 ) {
F_7 ( V_35 , V_36 ) ;
goto V_37;
}
V_2 = V_34 ;
if ( F_13 ( V_1 , V_34 , V_9 ) != ( int ) V_9 ) {
F_7 ( V_35 , V_32 ) ;
goto V_37;
}
if ( V_26 )
V_3 = F_10 ( & V_2 , V_9 , V_25 , V_27 ) ;
else
V_3 = F_11 ( & V_2 , V_9 , V_25 , V_27 ) ;
V_37:
if ( V_34 )
F_5 ( V_34 ) ;
return V_3 ;
}
static T_2 * F_10 ( const unsigned char * * V_1 , unsigned int V_9 ,
unsigned int V_25 , int V_27 )
{
const unsigned char * V_2 = * V_1 ;
T_2 * V_3 = NULL ;
T_4 * V_38 = NULL ;
T_5 * V_39 = NULL ;
unsigned int V_4 ;
V_4 = ( V_25 + 7 ) >> 3 ;
V_38 = F_14 () ;
V_3 = F_15 () ;
if ( ! V_38 || ! V_3 )
goto V_40;
if ( ! F_2 ( & V_2 , V_4 , & V_38 -> V_2 ) )
goto V_40;
if ( ! F_2 ( & V_2 , 20 , & V_38 -> V_7 ) )
goto V_40;
if ( ! F_2 ( & V_2 , V_4 , & V_38 -> V_41 ) )
goto V_40;
if ( V_27 ) {
if ( ! F_2 ( & V_2 , V_4 , & V_38 -> V_42 ) )
goto V_40;
} else {
if ( ! F_2 ( & V_2 , 20 , & V_38 -> V_43 ) )
goto V_40;
if ( ! ( V_38 -> V_42 = F_16 () ) )
goto V_40;
if ( ! ( V_39 = F_17 () ) )
goto V_40;
if ( ! F_18 ( V_38 -> V_42 , V_38 -> V_41 , V_38 -> V_43 , V_38 -> V_2 , V_39 ) )
goto V_40;
F_19 ( V_39 ) ;
}
F_20 ( V_3 , V_38 ) ;
F_21 ( V_38 ) ;
* V_1 = V_2 ;
return V_3 ;
V_40:
F_7 ( V_44 , V_36 ) ;
if ( V_38 )
F_21 ( V_38 ) ;
if ( V_3 )
F_22 ( V_3 ) ;
if ( V_39 )
F_19 ( V_39 ) ;
return NULL ;
}
static T_2 * F_11 ( const unsigned char * * V_1 , unsigned int V_9 ,
unsigned int V_25 , int V_27 )
{
const unsigned char * V_2 = * V_1 ;
T_2 * V_3 = NULL ;
T_6 * V_45 = NULL ;
unsigned int V_4 , V_28 ;
V_4 = ( V_25 + 7 ) >> 3 ;
V_28 = ( V_25 + 15 ) >> 4 ;
V_45 = F_23 () ;
V_3 = F_15 () ;
if ( ! V_45 || ! V_3 )
goto V_40;
V_45 -> V_46 = F_16 () ;
if ( ! V_45 -> V_46 )
goto V_40;
if ( ! F_24 ( V_45 -> V_46 , F_1 ( & V_2 ) ) )
goto V_40;
if ( ! F_2 ( & V_2 , V_4 , & V_45 -> V_47 ) )
goto V_40;
if ( ! V_27 ) {
if ( ! F_2 ( & V_2 , V_28 , & V_45 -> V_2 ) )
goto V_40;
if ( ! F_2 ( & V_2 , V_28 , & V_45 -> V_7 ) )
goto V_40;
if ( ! F_2 ( & V_2 , V_28 , & V_45 -> V_48 ) )
goto V_40;
if ( ! F_2 ( & V_2 , V_28 , & V_45 -> V_49 ) )
goto V_40;
if ( ! F_2 ( & V_2 , V_28 , & V_45 -> V_50 ) )
goto V_40;
if ( ! F_2 ( & V_2 , V_4 , & V_45 -> V_51 ) )
goto V_40;
}
F_25 ( V_3 , V_45 ) ;
F_26 ( V_45 ) ;
* V_1 = V_2 ;
return V_3 ;
V_40:
F_7 ( V_52 , V_36 ) ;
if ( V_45 )
F_26 ( V_45 ) ;
if ( V_3 )
F_22 ( V_3 ) ;
return NULL ;
}
T_2 * F_27 ( const unsigned char * * V_1 , long V_9 )
{
return F_9 ( V_1 , V_9 , 0 ) ;
}
T_2 * F_28 ( const unsigned char * * V_1 , long V_9 )
{
return F_9 ( V_1 , V_9 , 1 ) ;
}
T_2 * F_29 ( T_3 * V_1 )
{
return F_12 ( V_1 , 0 ) ;
}
T_2 * F_30 ( T_3 * V_1 )
{
return F_12 ( V_1 , 1 ) ;
}
static void F_31 ( unsigned char * * V_53 , unsigned int V_54 )
{
unsigned char * V_2 = * V_53 ;
* V_2 ++ = V_54 & 0xff ;
* V_2 ++ = ( V_54 >> 8 ) & 0xff ;
* V_2 ++ = ( V_54 >> 16 ) & 0xff ;
* V_2 ++ = ( V_54 >> 24 ) & 0xff ;
* V_53 = V_2 ;
}
static void F_32 ( unsigned char * * V_53 , const T_1 * V_55 , int V_56 )
{
int V_57 , V_8 ;
unsigned char * V_2 = * V_53 , * V_7 , V_58 ;
V_57 = F_33 ( V_55 ) ;
F_34 ( V_55 , V_2 ) ;
V_7 = V_2 + V_57 - 1 ;
for ( V_8 = 0 ; V_8 < V_57 / 2 ; V_8 ++ ) {
V_58 = * V_2 ;
* V_2 ++ = * V_7 ;
* V_7 -- = V_58 ;
}
* V_53 += V_57 ;
if ( V_56 > 0 ) {
V_56 -= V_57 ;
if ( V_56 > 0 ) {
memset ( * V_53 , 0 , V_56 ) ;
* V_53 += V_56 ;
}
}
}
static int F_35 ( unsigned char * * V_53 , T_2 * V_59 , int V_27 )
{
unsigned char * V_2 ;
unsigned int V_25 , V_29 = 0 , V_60 ;
int V_61 , V_62 = 0 ;
if ( V_59 -> type == V_63 ) {
V_25 = F_36 ( V_59 -> V_64 . V_38 , V_27 , & V_29 ) ;
V_60 = V_65 ;
} else if ( V_59 -> type == V_66 ) {
V_25 = F_37 ( V_59 -> V_64 . V_45 , V_27 , & V_29 ) ;
V_60 = V_67 ;
} else
return - 1 ;
if ( V_25 == 0 )
return - 1 ;
V_61 = 16 + F_8 ( V_25 ,
V_60 == V_65 ? 1 : 0 , V_27 ) ;
if ( V_53 == NULL )
return V_61 ;
if ( * V_53 )
V_2 = * V_53 ;
else {
V_2 = F_3 ( V_61 ) ;
if ( ! V_2 )
return - 1 ;
* V_53 = V_2 ;
V_62 = 1 ;
}
if ( V_27 )
* V_2 ++ = V_14 ;
else
* V_2 ++ = V_17 ;
* V_2 ++ = 0x2 ;
* V_2 ++ = 0 ;
* V_2 ++ = 0 ;
F_31 ( & V_2 , V_60 ) ;
F_31 ( & V_2 , V_29 ) ;
F_31 ( & V_2 , V_25 ) ;
if ( V_60 == V_65 )
F_38 ( & V_2 , V_59 -> V_64 . V_38 , V_27 ) ;
else
F_39 ( & V_2 , V_59 -> V_64 . V_45 , V_27 ) ;
if ( ! V_62 )
* V_53 += V_61 ;
return V_61 ;
}
static int F_40 ( T_3 * V_53 , T_2 * V_59 , int V_27 )
{
unsigned char * V_68 = NULL ;
int V_61 , V_69 ;
V_61 = F_35 ( & V_68 , V_59 , V_27 ) ;
if ( V_61 < 0 )
return - 1 ;
V_69 = F_41 ( V_53 , V_68 , V_61 ) ;
F_5 ( V_68 ) ;
if ( V_69 == V_61 )
return V_61 ;
return - 1 ;
}
static int F_36 ( T_4 * V_38 , int V_27 , unsigned int * V_10 )
{
int V_25 ;
V_25 = F_42 ( V_38 -> V_2 ) ;
if ( ( V_25 & 7 ) || ( F_42 ( V_38 -> V_7 ) != 160 )
|| ( F_42 ( V_38 -> V_41 ) > V_25 ) )
goto V_70;
if ( V_27 ) {
if ( F_42 ( V_38 -> V_42 ) > V_25 )
goto V_70;
* V_10 = V_20 ;
} else {
if ( F_42 ( V_38 -> V_43 ) > 160 )
goto V_70;
* V_10 = V_22 ;
}
return V_25 ;
V_70:
F_7 ( V_71 , V_72 ) ;
return 0 ;
}
static int F_37 ( T_6 * V_45 , int V_27 , unsigned int * V_10 )
{
int V_4 , V_28 , V_25 ;
if ( F_42 ( V_45 -> V_46 ) > 32 )
goto V_70;
V_25 = F_42 ( V_45 -> V_47 ) ;
V_4 = F_33 ( V_45 -> V_47 ) ;
V_28 = ( F_42 ( V_45 -> V_47 ) + 15 ) >> 4 ;
if ( V_27 ) {
* V_10 = V_21 ;
return V_25 ;
} else {
* V_10 = V_23 ;
if ( F_33 ( V_45 -> V_51 ) > V_4 )
goto V_70;
if ( ( F_33 ( V_45 -> V_50 ) > V_28 )
|| ( F_33 ( V_45 -> V_2 ) > V_28 )
|| ( F_33 ( V_45 -> V_7 ) > V_28 )
|| ( F_33 ( V_45 -> V_48 ) > V_28 )
|| ( F_33 ( V_45 -> V_49 ) > V_28 ) )
goto V_70;
}
return V_25 ;
V_70:
F_7 ( V_73 , V_72 ) ;
return 0 ;
}
static void F_39 ( unsigned char * * V_53 , T_6 * V_45 , int V_27 )
{
int V_4 , V_28 ;
V_4 = F_33 ( V_45 -> V_47 ) ;
V_28 = ( F_42 ( V_45 -> V_47 ) + 15 ) >> 4 ;
F_32 ( V_53 , V_45 -> V_46 , 4 ) ;
F_32 ( V_53 , V_45 -> V_47 , - 1 ) ;
if ( V_27 )
return;
F_32 ( V_53 , V_45 -> V_2 , V_28 ) ;
F_32 ( V_53 , V_45 -> V_7 , V_28 ) ;
F_32 ( V_53 , V_45 -> V_48 , V_28 ) ;
F_32 ( V_53 , V_45 -> V_49 , V_28 ) ;
F_32 ( V_53 , V_45 -> V_50 , V_28 ) ;
F_32 ( V_53 , V_45 -> V_51 , V_4 ) ;
}
static void F_38 ( unsigned char * * V_53 , T_4 * V_38 , int V_27 )
{
int V_4 ;
V_4 = F_33 ( V_38 -> V_2 ) ;
F_32 ( V_53 , V_38 -> V_2 , V_4 ) ;
F_32 ( V_53 , V_38 -> V_7 , 20 ) ;
F_32 ( V_53 , V_38 -> V_41 , V_4 ) ;
if ( V_27 )
F_32 ( V_53 , V_38 -> V_42 , V_4 ) ;
else
F_32 ( V_53 , V_38 -> V_43 , 20 ) ;
memset ( * V_53 , 0xff , 24 ) ;
* V_53 += 24 ;
return;
}
int F_43 ( T_3 * V_53 , T_2 * V_59 )
{
return F_40 ( V_53 , V_59 , 0 ) ;
}
int F_44 ( T_3 * V_53 , T_2 * V_59 )
{
return F_40 ( V_53 , V_59 , 1 ) ;
}
static int F_45 ( const unsigned char * * V_1 , unsigned int V_9 ,
int V_74 ,
unsigned int * V_75 , unsigned int * V_76 )
{
const unsigned char * V_2 = * V_1 ;
unsigned int V_77 , V_78 ;
if ( V_74 ) {
if ( V_9 < 20 ) {
F_7 ( V_79 , V_80 ) ;
return 0 ;
}
V_9 -= 20 ;
} else {
if ( V_9 < 24 ) {
F_7 ( V_79 , V_80 ) ;
return 0 ;
}
V_9 -= 24 ;
V_77 = F_1 ( & V_2 ) ;
if ( V_77 != V_81 ) {
F_7 ( V_79 , V_24 ) ;
return 0 ;
}
}
V_2 += 4 ;
F_1 ( & V_2 ) ;
V_78 = F_1 ( & V_2 ) ;
* V_75 = F_1 ( & V_2 ) ;
* V_76 = F_1 ( & V_2 ) ;
if ( V_78 && ! * V_75 ) {
F_7 ( V_79 , V_82 ) ;
return 0 ;
}
* V_1 = V_2 ;
return 1 ;
}
static int F_46 ( unsigned char * V_83 ,
const unsigned char * V_84 , unsigned int V_85 ,
const unsigned char * V_86 , int V_87 )
{
T_7 V_88 ;
int V_89 = 1 ;
F_47 ( & V_88 ) ;
if ( ! F_48 ( & V_88 , F_49 () , NULL )
|| ! F_50 ( & V_88 , V_84 , V_85 )
|| ! F_50 ( & V_88 , V_86 , V_87 )
|| ! F_51 ( & V_88 , V_83 , NULL ) )
V_89 = 0 ;
F_52 ( & V_88 ) ;
return V_89 ;
}
static T_2 * F_53 ( const unsigned char * * V_1 ,
unsigned int V_85 , unsigned int V_90 ,
T_8 * V_91 , void * V_92 )
{
T_2 * V_3 = NULL ;
const unsigned char * V_2 = * V_1 ;
unsigned int V_29 ;
unsigned char * V_93 = NULL , * V_7 ;
T_9 V_94 ;
F_54 ( & V_94 ) ;
if ( V_85 ) {
char V_95 [ V_96 ] ;
unsigned char V_97 [ 20 ] ;
int V_98 , V_99 ;
if ( V_91 )
V_99 = V_91 ( V_95 , V_96 , 0 , V_92 ) ;
else
V_99 = F_55 ( V_95 , V_96 , 0 , V_92 ) ;
if ( V_99 <= 0 ) {
F_7 ( V_100 , V_101 ) ;
return NULL ;
}
V_93 = F_3 ( V_90 + 8 ) ;
if ( ! V_93 ) {
F_7 ( V_100 , V_36 ) ;
return NULL ;
}
if ( ! F_46 ( V_97 , V_2 , V_85 ,
( unsigned char * ) V_95 , V_99 ) )
return NULL ;
V_2 += V_85 ;
memcpy ( V_93 , V_2 , 8 ) ;
V_2 += 8 ;
if ( V_90 < 8 ) {
F_7 ( V_100 , V_80 ) ;
return NULL ;
}
V_99 = V_90 - 8 ;
V_7 = V_93 + 8 ;
if ( ! F_56 ( & V_94 , F_57 () , NULL , V_97 , NULL ) )
goto V_37;
if ( ! F_58 ( & V_94 , V_7 , & V_98 , V_2 , V_99 ) )
goto V_37;
if ( ! F_59 ( & V_94 , V_7 + V_98 , & V_98 ) )
goto V_37;
V_29 = F_1 ( ( const unsigned char * * ) & V_7 ) ;
if ( V_29 != V_23 && V_29 != V_22 ) {
V_7 = V_93 + 8 ;
memset ( V_97 + 5 , 0 , 11 ) ;
if ( ! F_56 ( & V_94 , F_57 () , NULL , V_97 , NULL ) )
goto V_37;
F_60 ( V_97 , 20 ) ;
if ( ! F_58 ( & V_94 , V_7 , & V_98 , V_2 , V_99 ) )
goto V_37;
if ( ! F_59 ( & V_94 , V_7 + V_98 , & V_98 ) )
goto V_37;
V_29 = F_1 ( ( const unsigned char * * ) & V_7 ) ;
if ( V_29 != V_23 && V_29 != V_22 ) {
F_7 ( V_100 , V_102 ) ;
goto V_37;
}
} else
F_60 ( V_97 , 20 ) ;
V_2 = V_93 ;
}
V_3 = F_27 ( & V_2 , V_90 ) ;
V_37:
F_61 ( & V_94 ) ;
if ( V_93 && V_85 )
F_5 ( V_93 ) ;
return V_3 ;
}
T_2 * F_62 ( T_3 * V_1 , T_8 * V_91 , void * V_92 )
{
unsigned char V_103 [ 24 ] , * V_34 = NULL ;
const unsigned char * V_2 ;
int V_104 ;
T_2 * V_3 = NULL ;
unsigned int V_85 , V_90 ;
if ( F_13 ( V_1 , V_103 , 24 ) != 24 ) {
F_7 ( V_105 , V_106 ) ;
return NULL ;
}
V_2 = V_103 ;
if ( ! F_45 ( & V_2 , 24 , 0 , & V_85 , & V_90 ) )
return 0 ;
V_104 = ( int ) V_90 + V_85 ;
V_34 = F_3 ( V_104 ) ;
if ( ! V_34 ) {
F_7 ( V_105 , V_36 ) ;
return 0 ;
}
V_2 = V_34 ;
if ( F_13 ( V_1 , V_34 , V_104 ) != V_104 ) {
F_7 ( V_105 , V_106 ) ;
goto V_37;
}
V_3 = F_53 ( & V_2 , V_85 , V_90 , V_91 , V_92 ) ;
V_37:
if ( V_34 ) {
F_60 ( V_34 , V_104 ) ;
F_5 ( V_34 ) ;
}
return V_3 ;
}
static int F_63 ( unsigned char * * V_53 , T_2 * V_59 , int V_107 ,
T_8 * V_91 , void * V_92 )
{
int V_61 = 24 , V_108 ;
unsigned char * V_2 , * V_84 = NULL ;
T_9 V_94 ;
F_54 ( & V_94 ) ;
if ( V_107 )
V_61 += V_109 ;
V_108 = F_35 ( NULL , V_59 , 0 ) ;
if ( V_108 < 0 )
return - 1 ;
V_61 += V_108 ;
if ( ! V_53 )
return V_61 ;
if ( * V_53 )
V_2 = * V_53 ;
else {
V_2 = F_3 ( V_61 ) ;
if ( ! V_2 ) {
F_7 ( V_110 , V_36 ) ;
return - 1 ;
}
* V_53 = V_2 ;
}
F_31 ( & V_2 , V_81 ) ;
F_31 ( & V_2 , 0 ) ;
if ( V_59 -> type == V_63 )
F_31 ( & V_2 , V_111 ) ;
else
F_31 ( & V_2 , V_112 ) ;
F_31 ( & V_2 , V_107 ? 1 : 0 ) ;
F_31 ( & V_2 , V_107 ? V_109 : 0 ) ;
F_31 ( & V_2 , V_108 ) ;
if ( V_107 ) {
if ( F_64 ( V_2 , V_109 ) <= 0 )
goto error;
V_84 = V_2 ;
V_2 += V_109 ;
}
F_35 ( & V_2 , V_59 , 0 ) ;
if ( V_107 == 0 )
return V_61 ;
else {
char V_95 [ V_96 ] ;
unsigned char V_97 [ 20 ] ;
int V_98 , V_99 ;
if ( V_91 )
V_99 = V_91 ( V_95 , V_96 , 1 , V_92 ) ;
else
V_99 = F_55 ( V_95 , V_96 , 1 , V_92 ) ;
if ( V_99 <= 0 ) {
F_7 ( V_110 , V_101 ) ;
goto error;
}
if ( ! F_46 ( V_97 , V_84 , V_109 ,
( unsigned char * ) V_95 , V_99 ) )
goto error;
if ( V_107 == 1 )
memset ( V_97 + 5 , 0 , 11 ) ;
V_2 = V_84 + V_109 + 8 ;
if ( ! F_65 ( & V_94 , F_57 () , NULL , V_97 , NULL ) )
goto error;
F_60 ( V_97 , 20 ) ;
if ( ! F_58 ( & V_94 , V_2 , & V_98 , V_2 , V_108 - 8 ) )
goto error;
if ( ! F_59 ( & V_94 , V_2 + V_98 , & V_98 ) )
goto error;
}
F_61 ( & V_94 ) ;
return V_61 ;
error:
F_61 ( & V_94 ) ;
return - 1 ;
}
int F_66 ( T_3 * V_53 , T_2 * V_59 , int V_107 ,
T_8 * V_91 , void * V_92 )
{
unsigned char * V_68 = NULL ;
int V_61 , V_69 ;
V_61 = F_63 ( & V_68 , V_59 , V_107 , V_91 , V_92 ) ;
if ( V_61 < 0 )
return - 1 ;
V_69 = F_41 ( V_53 , V_68 , V_61 ) ;
F_5 ( V_68 ) ;
if ( V_69 == V_61 ) {
F_7 ( V_113 , V_114 ) ;
return V_61 ;
}
return - 1 ;
}
