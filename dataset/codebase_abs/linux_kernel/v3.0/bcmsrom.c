static void F_1 ( T_1 * V_1 , char * V_2 , T_2 V_3 )
{
V_1 -> V_3 = V_3 ;
V_1 -> V_4 = V_1 -> V_2 = V_2 ;
}
static int F_2 ( T_1 * V_1 , const char * V_5 , ... )
{
T_3 V_6 ;
int V_7 ;
T_4 V_8 ;
char * V_9 ;
if ( V_1 -> V_3 < 2 )
return 0 ;
va_start ( V_6 , V_5 ) ;
V_7 = vsnprintf ( V_1 -> V_2 , V_1 -> V_3 , V_5 , V_6 ) ;
va_end ( V_6 ) ;
if ( ( V_7 == - 1 ) || ( V_7 > ( int ) ( V_1 -> V_3 - 2 ) ) ) {
V_1 -> V_3 = 0 ;
return 0 ;
}
V_9 = strchr ( V_1 -> V_2 , '=' ) ;
if ( V_9 != NULL ) {
V_8 = ( T_4 ) ( V_9 - V_1 -> V_2 ) ;
for ( V_9 = V_1 -> V_4 ; V_9 < V_1 -> V_2 ; ) {
if ( ( memcmp ( V_9 , V_1 -> V_2 , V_8 ) == 0 ) && V_9 [ V_8 ] == '=' ) {
V_8 = strlen ( V_9 ) + 1 ;
memmove ( V_9 , ( V_9 + V_8 ) ,
( ( V_1 -> V_2 + V_7 + 1 ) - ( V_9 + V_8 ) ) ) ;
V_1 -> V_2 -= V_8 ;
V_1 -> V_3 += ( unsigned int ) V_8 ;
break;
}
while ( * V_9 ++ )
;
}
}
V_7 ++ ;
V_1 -> V_3 -= V_7 ;
V_1 -> V_2 += V_7 ;
return V_7 ;
}
int F_3 ( T_5 * V_10 , T_2 V_11 , void * V_12 ,
char * * V_13 , T_2 * V_14 )
{
T_2 V_8 ;
V_8 = 0 ;
if ( V_13 == NULL || V_14 == NULL )
return 0 ;
* V_13 = NULL ;
* V_14 = 0 ;
switch ( V_11 ) {
case V_15 :
case V_16 :
return F_4 ( V_10 , V_12 , V_13 , V_14 ) ;
case V_17 :
if ( V_12 == NULL )
return - 1 ;
return F_5 ( V_10 , V_12 , V_13 , V_14 ) ;
default:
break;
}
return - 1 ;
}
static T_6
F_6 ( T_5 * V_10 , void * V_18 , T_7 V_19 ,
T_2 V_20 , T_6 V_21 )
{
T_8 * V_22 = ( T_8 * ) V_18 ;
T_2 V_23 = 1000 ;
if ( ( V_19 == V_24 ) || ( V_19 == V_25 ) ) {
F_7 ( & V_22 -> V_26 , V_20 * 2 ) ;
if ( V_19 == V_25 )
F_7 ( & V_22 -> V_27 , V_21 ) ;
}
F_7 ( & V_22 -> V_28 , V_29 | V_19 ) ;
while ( V_23 -- ) {
if ( ( F_8 ( & V_22 -> V_28 ) & V_30 ) == 0 )
break;
}
if ( ! V_23 ) {
return 0xffff ;
}
if ( V_19 == V_24 )
return ( T_6 ) F_8 ( & V_22 -> V_27 ) ;
else
return 0xffff ;
}
static inline void F_9 ( T_6 * V_2 , unsigned int V_3 )
{
for ( V_3 /= 2 ; V_3 ; V_3 -- )
* ( V_2 + V_3 ) = F_10 ( * ( V_2 + V_3 ) ) ;
}
static inline void F_11 ( T_6 * V_2 , unsigned int V_3 )
{
for ( V_3 /= 2 ; V_3 ; V_3 -- )
* ( V_2 + V_3 ) = F_12 ( * ( V_2 + V_3 ) ) ;
}
static int
F_13 ( T_5 * V_10 , T_6 * V_31 , T_2 V_20 ,
T_6 * V_2 , T_2 V_32 , bool V_33 )
{
int V_34 = 0 ;
T_2 V_35 ;
void * V_18 = NULL ;
for ( V_35 = 0 ; V_35 < V_32 ; V_35 ++ ) {
if ( V_10 -> V_36 > 31 && F_14 ( V_10 ) ) {
if ( ( V_10 -> V_37 & V_38 ) == 0 )
return 1 ;
V_18 = ( void * ) ( ( V_39 * ) V_31 - V_40 ) ;
V_2 [ V_35 ] =
F_6 ( V_10 , V_18 , V_24 ,
V_20 + V_35 , 0 ) ;
} else {
if ( F_14 ( V_10 ) )
V_2 [ V_35 ] = F_8 ( & V_31 [ V_20 + V_35 ] ) ;
V_2 [ V_35 ] = F_8 ( & V_31 [ V_20 + V_35 ] ) ;
}
}
if ( F_14 ( V_10 ) )
return V_34 ;
if ( V_33 ) {
if ( V_2 [ 0 ] == 0xffff ) {
return 1 ;
}
F_11 ( V_2 , V_32 * 2 ) ;
if ( F_15 ( ( V_39 * ) V_2 , V_32 * 2 , V_41 ) !=
V_42 ) {
V_34 = 1 ;
}
F_9 ( V_2 , V_32 * 2 ) ;
}
return V_34 ;
}
static int F_16 ( T_5 * V_10 , T_6 * V_2 , T_2 V_43 )
{
V_39 * V_44 ;
T_2 V_45 = V_46 / 2 ;
int V_34 = 0 ;
V_44 = F_17 ( V_46 , V_47 ) ;
if ( V_44 == NULL ) {
return - V_48 ;
}
V_34 = F_18 ( V_10 , V_49 , ( T_6 * ) V_44 , & V_45 ) ;
memcpy ( V_2 , V_44 , V_43 ) ;
F_19 ( V_44 ) ;
if ( V_2 [ 0 ] == 0xffff ) {
return 1 ;
}
F_11 ( V_2 , V_43 ) ;
if ( F_15 ( ( V_39 * ) V_2 , V_50 * 2 , V_41 ) !=
V_42 ) {
V_34 = 1 ;
}
F_9 ( V_2 , V_43 ) ;
return V_34 ;
}
static int F_20 ( char * V_51 , char * V_52 ,
char * * V_13 , T_2 * V_14 )
{
int V_53 = ( int ) ( V_52 - V_51 ) ;
if ( V_53 > 1 ) {
char * V_54 = F_21 ( V_53 , V_47 ) ;
if ( ! V_54 )
return - V_55 ;
memcpy ( V_54 , V_51 , V_53 ) ;
* V_13 = V_54 ;
* V_14 = V_53 ;
} else {
* V_13 = NULL ;
* V_14 = 0 ;
}
return 0 ;
}
static int F_22 ( T_5 * V_10 , char * * V_4 , T_2 V_8 )
{
char * V_54 = * V_4 ;
char * V_56 ;
int V_34 ;
char * V_9 ;
T_2 V_57 , V_58 , V_59 ;
char V_60 [ V_61 ] ;
V_56 = F_21 ( V_62 , V_47 ) ;
if ( ! V_56 )
return - V_55 ;
V_34 = F_23 ( V_56 , V_62 ) ;
if ( V_34 )
goto exit;
F_24 ( V_10 , V_60 , sizeof( V_60 ) ) ;
V_58 = strlen ( V_60 ) ;
for ( V_9 = V_56 ; V_9 && * V_9 ; V_9 += V_57 + 1 ) {
V_57 = strlen ( V_9 ) ;
if ( strncmp ( V_9 , V_60 , V_58 ) )
continue;
V_59 = V_57 - V_58 + 1 ;
if ( V_8 < V_59 ) {
V_34 = - V_63 ;
goto exit;
}
strncpy ( V_54 , & V_9 [ V_58 ] , V_59 ) ;
V_54 += V_59 ;
V_8 -= V_59 ;
}
if ( V_8 < 1 ) {
V_34 = - V_63 ;
goto exit;
}
* V_54 ++ = '\0' ;
* V_4 = V_54 ;
exit: F_19 ( V_56 ) ;
return V_34 ;
}
static int F_25 ( T_5 * V_10 , char * * V_13 , T_2 * V_14 )
{
char * V_54 , * V_4 ;
int V_34 ;
V_4 = V_54 = F_21 ( V_64 , V_47 ) ;
if ( ! V_54 )
return - V_55 ;
V_34 = F_22 ( V_10 , & V_54 , V_64 ) ;
if ( V_34 == 0 )
V_34 = F_20 ( V_4 , V_54 , V_13 , V_14 ) ;
F_19 ( V_4 ) ;
return V_34 ;
}
static T_2 F_26 ( T_6 V_65 )
{
T_2 V_35 ;
for ( V_35 = 0 ; V_35 < ( sizeof( V_65 ) << 3 ) ; V_35 ++ ) {
if ( V_65 & ( 1 << V_35 ) )
return V_35 ;
}
return 0 ;
}
static T_2 F_27 ( T_6 V_65 )
{
int V_35 ;
for ( V_35 = ( sizeof( V_65 ) << 3 ) - 1 ; V_35 >= 0 ; V_35 -- ) {
if ( V_65 & ( 1 << V_35 ) )
return ( T_2 ) ( V_35 - F_26 ( V_65 ) + 1 ) ;
}
return 0 ;
}
static void F_28 ( V_39 V_66 , T_6 * V_67 , T_2 V_68 , T_1 * V_1 )
{
T_6 V_69 ;
T_7 V_70 ;
const T_9 * V_71 ;
T_2 V_72 ;
T_2 V_73 ;
T_7 V_74 = ( 1 << V_66 ) ;
F_2 ( V_1 , L_1 , V_66 ) ;
for ( V_71 = V_75 ; V_71 -> V_76 != NULL ; V_71 ++ ) {
const char * V_76 ;
if ( ( V_71 -> V_77 & V_74 ) == 0 )
continue;
if ( V_71 -> V_68 < V_68 )
continue;
V_73 = V_71 -> V_73 ;
V_76 = V_71 -> V_76 ;
if ( V_73 & V_78 )
continue;
if ( V_73 & V_79 ) {
V_39 V_80 [ V_81 ] ;
V_80 [ 0 ] = ( V_67 [ V_71 -> V_68 - V_68 ] >> 8 ) & 0xff ;
V_80 [ 1 ] = V_67 [ V_71 -> V_68 - V_68 ] & 0xff ;
V_80 [ 2 ] = ( V_67 [ V_71 -> V_68 + 1 - V_68 ] >> 8 ) & 0xff ;
V_80 [ 3 ] = V_67 [ V_71 -> V_68 + 1 - V_68 ] & 0xff ;
V_80 [ 4 ] = ( V_67 [ V_71 -> V_68 + 2 - V_68 ] >> 8 ) & 0xff ;
V_80 [ 5 ] = V_67 [ V_71 -> V_68 + 2 - V_68 ] & 0xff ;
F_2 ( V_1 , L_2 , V_76 , V_80 ) ;
} else {
V_69 = V_67 [ V_71 -> V_68 - V_68 ] ;
V_70 = ( V_69 & V_71 -> V_65 ) >> F_26 ( V_71 -> V_65 ) ;
V_72 = F_27 ( V_71 -> V_65 ) ;
while ( V_71 -> V_73 & V_82 ) {
V_71 ++ ;
if ( V_71 -> V_68 == 0 || V_71 -> V_68 < V_68 )
continue;
V_69 = V_67 [ V_71 -> V_68 - V_68 ] ;
V_70 +=
( ( V_69 & V_71 -> V_65 ) >> F_26 ( V_71 ->
V_65 ) ) <<
V_72 ;
V_72 += F_27 ( V_71 -> V_65 ) ;
}
if ( ( V_73 & V_83 )
&& ( ( int ) V_70 == ( 1 << V_72 ) - 1 ) )
continue;
if ( V_73 & V_84 ) {
if ( V_70 == 0 )
F_2 ( V_1 , L_3 ) ;
else
F_2 ( V_1 , L_4 ,
( V_70 >> 8 ) , ( V_70 & 0xff ) ) ;
}
else if ( V_73 & V_85 ) {
T_7 V_86 = ( ( ( V_70 >> 8 ) & 0xff ) << 24 ) |
( ( ( V_70 & 0xff ) ) << 8 ) ;
F_2 ( V_1 , L_5 , V_86 ) ;
} else if ( V_73 & V_87 )
F_2 ( V_1 , L_6 , V_76 , V_70 ) ;
else if ( ( V_73 & V_88 )
&& ( V_70 & ( 1 << ( V_72 - 1 ) ) ) )
F_2 ( V_1 , L_7 , V_76 ,
( int ) ( V_70 | ( ~ 0 << V_72 ) ) ) ;
else
F_2 ( V_1 , L_8 , V_76 , V_70 ) ;
}
}
if ( V_66 >= 4 ) {
T_2 V_89 , V_90 , V_91 ;
if ( V_66 >= 8 ) {
V_90 = V_92 ;
V_91 = V_93 - V_92 ;
} else {
V_90 = V_94 ;
V_91 = V_95 - V_94 ;
}
for ( V_89 = 0 ; V_89 < V_96 ; V_89 ++ ) {
for ( V_71 = V_97 ; V_71 -> V_76 != NULL ;
V_71 ++ ) {
if ( ( V_71 -> V_77 & V_74 ) == 0 )
continue;
if ( V_90 + V_71 -> V_68 < V_68 )
continue;
if ( V_71 -> V_73 & V_78 )
continue;
V_69 = V_67 [ V_90 + V_71 -> V_68 - V_68 ] ;
V_70 = ( V_69 & V_71 -> V_65 ) >> F_26 ( V_71 -> V_65 ) ;
V_72 = F_27 ( V_71 -> V_65 ) ;
if ( ( V_71 -> V_73 & V_83 )
&& ( ( int ) V_70 == ( 1 << V_72 ) - 1 ) )
continue;
if ( V_71 -> V_73 & V_87 )
F_2 ( V_1 , L_9 , V_71 -> V_76 ,
V_89 , V_70 ) ;
else
F_2 ( V_1 , L_10 , V_71 -> V_76 ,
V_89 , V_70 ) ;
}
V_90 += V_91 ;
}
}
}
static int F_5 ( T_5 * V_10 , void * V_12 , char * * V_13 , T_2 * V_14 )
{
T_6 * V_67 , * V_98 ;
V_39 V_66 = 0 ;
T_7 V_74 ;
T_1 V_1 ;
char * V_54 , * V_4 = NULL ;
bool V_56 = false ;
int V_34 = 0 ;
V_67 = F_21 ( V_99 , V_47 ) ;
if ( ! V_67 )
return - 2 ;
V_98 = ( T_6 * ) F_29 ( V_10 ) ;
if ( F_30 ( V_10 ) ) {
V_34 =
F_13 ( V_10 , V_98 , 0 , V_67 , V_100 ,
true ) ;
if ( ( V_67 [ V_101 ] == V_102 ) ||
( ( ( V_10 -> V_103 == V_104 )
&& ( V_10 -> V_105 >= 6 ) )
|| ( ( V_10 -> V_103 == V_106 )
&& ( V_10 -> V_105 >= 0xe ) ) ) ) {
V_34 =
F_13 ( V_10 , V_98 , 0 , V_67 ,
V_50 , true ) ;
V_66 = V_67 [ V_107 ] & 0xff ;
} else if ( V_34 == 0 ) {
V_66 = V_67 [ V_108 ] & 0xff ;
if ( V_66 == 0x10 )
V_66 = 1 ;
}
}
#if F_31 ( V_109 )
else {
V_34 = F_16 ( V_10 , V_67 , V_99 ) ;
if ( V_34 == 0 )
V_66 = V_67 [ V_107 ] & 0xff ;
else
V_34 = 1 ;
}
#else
else
V_34 = 1 ;
#endif
if ( V_34 ) {
char * V_110 ;
T_7 V_70 ;
V_70 = 0 ;
V_110 = F_32 ( V_10 , L_11 ) ;
if ( V_110 ) {
V_66 = ( V_39 ) F_33 ( V_110 , NULL , 0 ) ;
V_56 = true ;
goto V_111;
}
V_110 = F_34 ( V_10 , L_11 ) ;
if ( V_110 ) {
V_34 = 0 ;
goto V_112;
}
{
V_34 = - 1 ;
goto V_112;
}
}
V_111:
V_74 = 1 << V_66 ;
if ( ( V_74 & 0x33e ) == 0 ) {
V_34 = - 2 ;
goto V_112;
}
V_4 = V_54 = F_21 ( V_64 , V_47 ) ;
if ( ! V_54 ) {
V_34 = - 2 ;
goto V_112;
}
if ( V_56 ) {
V_34 = F_22 ( V_10 , & V_54 , V_64 ) ;
if ( V_34 )
goto V_112;
goto V_113;
}
F_1 ( & V_1 , V_4 , V_64 ) ;
F_28 ( V_66 , V_67 , 0 , & V_1 ) ;
V_54 = V_1 . V_2 ;
* V_54 ++ = '\0' ;
V_113:
V_34 = F_20 ( V_4 , V_54 , V_13 , V_14 ) ;
V_112:
if ( V_4 )
F_19 ( V_4 ) ;
F_19 ( V_67 ) ;
return V_34 ;
}
static int F_4 ( T_5 * V_10 , void * V_12 , char * * V_13 , T_2 * V_114 )
{
return F_25 ( V_10 , V_13 , V_114 ) ;
}
