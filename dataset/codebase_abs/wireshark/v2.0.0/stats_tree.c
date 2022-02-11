extern T_1 *
F_1 ( const T_2 * V_1 , T_1 * V_2 , T_3 V_3 )
{
if ( V_2 ) {
F_2 ( V_2 , V_3 , L_1 , V_1 -> V_4 , V_1 -> V_5 ) ;
return V_2 ;
} else {
return F_3 ( L_1 , V_1 -> V_4 , V_1 -> V_5 ) ;
}
}
extern T_3
F_4 ( const T_2 * V_1 , T_3 V_6 )
{
T_2 * V_7 ;
T_3 V_8 = 0 ;
T_3 V_3 ;
V_6 = V_6 > V_9 ? V_9 : V_6 ;
if ( V_1 -> V_10 ) {
for ( V_7 = V_1 -> V_10 ; V_7 ; V_7 = V_7 -> V_11 ) {
V_3 = F_4 ( V_7 , V_6 + 1 ) ;
V_8 = V_3 > V_8 ? V_3 : V_8 ;
}
}
if ( V_1 -> V_12 & V_13 ) {
T_1 * V_14 = F_5 ( V_1 -> V_4 ) ;
V_3 = ( T_3 ) strlen ( V_14 ) + V_6 ;
F_6 ( V_14 ) ;
}
else {
V_3 = ( T_3 ) strlen ( V_1 -> V_4 ) + V_6 ;
}
V_8 = V_3 > V_8 ? V_3 : V_8 ;
return V_8 ;
}
static void
F_7 ( T_2 * V_1 )
{
T_2 * V_7 ;
T_2 * V_11 ;
T_4 * V_15 ;
if ( V_1 -> V_10 ) {
for ( V_7 = V_1 -> V_10 ; V_7 ; V_7 = V_11 ) {
V_11 = V_7 -> V_11 ;
F_7 ( V_7 ) ;
}
}
if ( V_1 -> V_16 ) F_8 ( V_1 -> V_16 ) ;
while ( V_1 -> V_17 ) {
V_15 = V_1 -> V_17 ;
V_1 -> V_17 = V_15 -> V_11 ;
F_6 ( V_15 ) ;
}
F_6 ( V_1 -> V_18 ) ;
F_6 ( V_1 -> V_4 ) ;
F_6 ( V_1 ) ;
}
extern void
F_9 ( T_5 * V_19 )
{
T_2 * V_7 ;
T_2 * V_11 ;
if ( ! V_19 ) return;
F_6 ( V_19 -> V_20 ) ;
F_8 ( V_19 -> V_21 ) ;
F_10 ( V_19 -> V_22 , TRUE ) ;
F_6 ( V_19 -> V_14 ) ;
for ( V_7 = V_19 -> V_23 . V_10 ; V_7 ; V_7 = V_11 ) {
V_11 = V_7 -> V_11 ;
F_7 ( V_7 ) ;
}
if ( V_19 -> V_24 -> V_25 )
V_19 -> V_24 -> V_25 ( V_19 ) ;
if ( V_19 -> V_24 -> V_26 )
V_19 -> V_24 -> V_26 ( V_19 ) ;
F_6 ( V_19 ) ;
}
static void
F_11 ( T_2 * V_1 )
{
T_2 * V_7 ;
T_4 * V_15 ;
V_1 -> V_5 = 0 ;
V_1 -> V_27 = 0 ;
V_1 -> V_28 = V_29 ;
V_1 -> V_30 = V_31 ;
V_1 -> V_12 = 0 ;
while ( V_1 -> V_17 ) {
V_15 = V_1 -> V_17 ;
V_1 -> V_17 = V_15 -> V_11 ;
F_6 ( V_15 ) ;
}
V_1 -> V_17 = ( T_4 * ) F_12 ( sizeof( T_4 ) ) ;
V_1 -> V_32 = V_1 -> V_17 ;
V_1 -> V_33 = 0 ;
V_1 -> V_34 = 0 ;
V_1 -> V_35 = - 1.0 ;
if ( V_1 -> V_10 ) {
for ( V_7 = V_1 -> V_10 ; V_7 ; V_7 = V_7 -> V_11 )
F_11 ( V_7 ) ;
}
}
extern void
F_13 ( void * V_36 )
{
T_5 * V_19 = ( T_5 * ) V_36 ;
V_19 -> V_37 = - 1.0 ;
V_19 -> V_38 = 0.0 ;
V_19 -> V_39 = - 1.0 ;
F_11 ( & V_19 -> V_23 ) ;
}
extern void
F_14 ( void * V_36 )
{
T_5 * V_19 = ( T_5 * ) V_36 ;
T_2 * V_7 ;
T_2 * V_11 ;
for ( V_7 = V_19 -> V_23 . V_10 ; V_7 ; V_7 = V_11 ) {
V_11 = V_7 -> V_11 ;
F_7 ( V_7 ) ;
}
V_19 -> V_23 . V_10 = NULL ;
V_19 -> V_23 . V_5 = 0 ;
V_19 -> V_23 . V_27 = 0 ;
V_19 -> V_23 . V_28 = V_29 ;
V_19 -> V_23 . V_30 = V_31 ;
V_19 -> V_23 . V_12 = 0 ;
V_19 -> V_23 . V_17 = ( T_4 * ) F_12 ( sizeof( T_4 ) ) ;
V_19 -> V_23 . V_32 = V_19 -> V_23 . V_17 ;
V_19 -> V_23 . V_33 = 0 ;
V_19 -> V_23 . V_34 = 0 ;
V_19 -> V_23 . V_35 = - 1.0 ;
F_15 ( V_19 -> V_21 ) ;
if ( V_19 -> V_22 -> V_3 > 1 ) {
F_16 ( V_19 -> V_22 , 1 , V_19 -> V_22 -> V_3 - 1 ) ;
}
V_19 -> V_40 = V_41 ;
F_6 ( V_19 -> V_14 ) ;
V_19 -> V_14 = F_5 ( V_19 -> V_24 -> V_4 ) ;
if ( V_19 -> V_24 -> V_42 ) {
V_19 -> V_24 -> V_42 ( V_19 ) ;
}
}
extern void
F_17 ( const char * V_43 , const char * V_44 , const char * V_4 ,
T_3 V_45 ,
T_6 V_46 , T_7 V_42 ,
T_8 V_26 , T_9 V_47 )
{
T_10 * V_24 = ( T_10 * ) F_12 ( sizeof( T_10 ) ) ;
F_18 ( V_43 && V_44 && V_46 ) ;
V_24 -> V_43 = F_19 ( V_43 ) ;
V_24 -> V_44 = F_19 ( V_44 ) ;
V_24 -> V_4 = V_4 ? F_19 ( V_4 ) : F_19 ( V_44 ) ;
V_24 -> V_47 = V_47 ;
V_24 -> V_46 = V_46 ;
V_24 -> V_42 = V_42 ;
V_24 -> V_26 = V_26 ;
V_24 -> V_45 = V_45 & ~ V_48 ;
V_24 -> V_12 = V_45 & V_48 ;
if ( ! V_49 ) V_49 = F_20 ( V_50 , V_51 ) ;
F_21 ( V_49 , V_24 -> V_44 , V_24 ) ;
}
extern void
F_22 ( const char * V_43 , const char * V_44 , const char * V_4 ,
T_3 V_45 ,
T_6 V_46 , T_7 V_42 ,
T_8 V_26 )
{
F_17 ( V_43 , V_44 , V_4 ,
V_45 ,
V_46 , V_42 ,
V_26 , V_52 ) ;
}
extern void
F_23 ( const char * V_43 , const char * V_44 , const char * V_4 ,
T_3 V_45 ,
T_6 V_46 , T_7 V_42 ,
T_8 V_26 )
{
T_10 * V_24 ;
F_22 ( V_43 , V_44 , V_4 ,
V_45 ,
V_46 , V_42 ,
V_26 ) ;
V_24 = F_24 ( V_44 ) ;
V_24 -> V_53 = TRUE ;
}
extern T_5 *
F_25 ( T_10 * V_24 , T_11 * V_54 , const char * V_20 )
{
T_5 * V_19 = ( T_5 * ) F_12 ( sizeof( T_5 ) ) ;
V_19 -> V_24 = V_24 ;
V_19 -> V_54 = V_54 ;
V_19 -> V_21 = F_20 ( V_50 , V_51 ) ;
V_19 -> V_22 = F_26 () ;
V_19 -> V_20 = F_19 ( V_20 ) ;
V_19 -> V_37 = - 1.0 ;
V_19 -> V_38 = 0.0 ;
V_19 -> V_23 . V_28 = V_29 ;
V_19 -> V_23 . V_30 = V_31 ;
V_19 -> V_23 . V_17 = ( T_4 * ) F_12 ( sizeof( T_4 ) ) ;
V_19 -> V_23 . V_32 = V_19 -> V_23 . V_17 ;
V_19 -> V_23 . V_35 = - 1.0 ;
V_19 -> V_23 . V_4 = F_5 ( V_24 -> V_4 ) ;
V_19 -> V_23 . V_19 = V_19 ;
V_19 -> V_12 = V_19 -> V_24 -> V_12 ;
if ( ! ( V_19 -> V_12 & V_55 ) ) {
V_19 -> V_12 |= V_56 . V_57 << V_58 ;
if ( V_56 . V_59 ) {
V_19 -> V_12 |= V_60 ;
}
}
V_19 -> V_40 = V_41 ;
V_19 -> V_14 = F_5 ( V_19 -> V_24 -> V_4 ) ;
F_27 ( V_19 -> V_22 , & V_19 -> V_23 ) ;
return V_19 ;
}
extern int
F_28 ( void * V_36 , T_12 * V_61 , T_13 * V_62 , const void * V_63 )
{
T_5 * V_19 = ( T_5 * ) V_36 ;
V_19 -> V_39 = F_29 ( & V_61 -> V_64 ) ;
if ( V_19 -> V_37 < 0.0 ) V_19 -> V_37 = V_19 -> V_39 ;
V_19 -> V_38 = V_19 -> V_39 - V_19 -> V_37 ;
if ( V_19 -> V_24 -> V_46 )
return V_19 -> V_24 -> V_46 ( V_19 , V_61 , V_62 , V_63 ) ;
else
return 0 ;
}
extern T_10 *
F_24 ( const char * V_44 )
{
if ( ! V_44 ) return NULL ;
return ( T_10 * ) F_30 ( V_49 , V_44 ) ;
}
static T_14
F_31 ( T_15 V_65 , T_15 V_66 )
{
T_10 * V_67 = ( T_10 * ) V_65 ;
T_10 * V_68 = ( T_10 * ) V_66 ;
return strcmp ( V_67 -> V_4 , V_68 -> V_4 ) ;
}
extern T_16 *
F_32 ( void )
{
T_16 * V_69 = F_33 ( V_49 ) ;
return F_34 ( V_69 , F_31 ) ;
}
static void
F_35 ( T_17 T_18 V_70 , T_17 V_71 , T_17 V_36 )
{
T_10 * V_24 = ( T_10 * ) V_71 ;
struct V_72 * V_73 = (struct V_72 * ) V_36 ;
V_24 -> V_74 = FALSE ;
V_24 -> V_75 = V_73 -> V_75 ;
V_24 -> V_25 = V_73 -> V_25 ;
}
extern void
F_36 ( void (* F_37)( T_17 , T_17 , T_17 ) ,
void (* V_75)( T_2 * ) ,
void (* V_25)( T_5 * ) ,
void * V_76 )
{
static struct V_72 V_73 ;
V_73 . V_75 = V_75 ;
V_73 . V_25 = V_25 ;
if ( V_49 ) F_38 ( V_49 , F_35 , & V_73 ) ;
if ( F_37 && V_49 )
F_38 ( V_49 , F_37 , V_76 ) ;
}
static T_2 *
F_39 ( T_5 * V_19 , const T_1 * V_4 , int V_77 ,
T_19 V_78 , T_19 V_79 )
{
T_2 * V_1 = ( T_2 * ) F_12 ( sizeof( T_2 ) ) ;
T_2 * V_80 = NULL ;
V_1 -> V_28 = V_29 ;
V_1 -> V_30 = V_31 ;
V_1 -> V_12 = V_77 ? 0 : V_13 ;
V_1 -> V_17 = ( T_4 * ) F_12 ( sizeof( T_4 ) ) ;
V_1 -> V_32 = V_1 -> V_17 ;
V_1 -> V_35 = - 1.0 ;
V_1 -> V_4 = F_19 ( V_4 ) ;
V_1 -> V_19 = ( T_5 * ) V_19 ;
V_1 -> V_16 = V_78 ? F_20 ( V_50 , V_51 ) : NULL ;
if ( V_79 ) {
F_21 ( V_19 -> V_21 ,
V_1 -> V_4 ,
V_1 ) ;
F_27 ( V_19 -> V_22 , V_1 ) ;
V_1 -> V_81 = V_19 -> V_22 -> V_3 - 1 ;
} else {
V_1 -> V_81 = - 1 ;
}
if ( V_77 >= 0 && V_77 < ( int ) V_19 -> V_22 -> V_3 ) {
V_1 -> V_82 = ( T_2 * ) F_40 ( V_19 -> V_22 , V_77 ) ;
} else {
F_41 () ;
}
if ( V_1 -> V_82 -> V_10 ) {
for ( V_80 = V_1 -> V_82 -> V_10 ;
V_80 -> V_11 ;
V_80 = V_80 -> V_11 ) ;
V_80 -> V_11 = V_1 ;
} else {
V_1 -> V_82 -> V_10 = V_1 ;
}
if( V_1 -> V_82 -> V_16 ) {
F_21 ( V_1 -> V_82 -> V_16 , V_1 -> V_4 , V_1 ) ;
}
if ( V_19 -> V_24 -> V_75 ) {
V_19 -> V_24 -> V_75 ( V_1 ) ;
} else {
V_1 -> V_54 = NULL ;
}
return V_1 ;
}
extern int
F_42 ( T_5 * V_19 , const T_1 * V_4 , int V_77 , T_19 V_78 )
{
T_2 * V_1 = F_39 ( V_19 , V_4 , V_77 , V_78 , TRUE ) ;
if ( V_1 )
return V_1 -> V_81 ;
else
return 0 ;
}
extern int
F_43 ( T_5 * V_19 , const T_1 * V_4 ,
const T_1 * V_83 , T_19 V_84 )
{
return F_42 ( V_19 , V_4 , F_44 ( V_19 , V_83 ) , V_84 ) ;
}
static void
F_45 ( T_2 * V_1 , T_14 V_85 )
{
double V_86 ;
double V_87 ;
T_4 * V_88 ;
if ( ! V_56 . V_89 ) {
return;
}
V_86 = floor ( V_1 -> V_19 -> V_39 / V_56 . V_90 ) ;
V_87 = V_56 . V_91 / V_56 . V_90 ;
if ( V_86 > V_1 -> V_32 -> V_92 ) {
V_88 = ( T_4 * ) F_12 ( sizeof( T_4 ) ) ;
V_88 -> V_93 = V_85 ;
V_88 -> V_92 = V_86 ;
V_88 -> V_94 = V_1 -> V_19 -> V_39 ;
V_88 -> V_95 = V_1 -> V_32 ;
V_1 -> V_32 -> V_11 = V_88 ;
V_1 -> V_32 = V_88 ;
V_1 -> V_33 += V_85 ;
while ( V_86 >= ( V_1 -> V_17 -> V_92 + V_87 ) ) {
V_88 = V_1 -> V_17 ;
V_1 -> V_17 = V_88 -> V_11 ;
V_1 -> V_17 -> V_95 = NULL ;
V_1 -> V_33 -= V_88 -> V_93 ;
F_6 ( V_88 ) ;
}
}
else if ( V_86 < V_1 -> V_17 -> V_92 ) {
if ( ( V_86 + V_87 ) > V_1 -> V_32 -> V_92 ) {
V_88 = ( T_4 * ) F_12 ( sizeof( T_4 ) ) ;
V_88 -> V_93 = V_85 ;
V_88 -> V_92 = V_86 ;
V_88 -> V_94 = V_1 -> V_19 -> V_39 ;
V_88 -> V_11 = V_1 -> V_17 ;
V_1 -> V_17 -> V_95 = V_88 ;
V_1 -> V_17 = V_88 ;
V_1 -> V_33 += V_85 ;
}
}
else
{
T_4 * V_96 = V_1 -> V_32 ;
while ( V_86 < V_96 -> V_92 ) {
V_96 = V_96 -> V_95 ;
}
if ( V_86 == V_96 -> V_92 ) {
V_96 -> V_93 += V_85 ;
if ( V_96 -> V_94 > V_1 -> V_19 -> V_39 ) {
V_96 -> V_94 = V_1 -> V_19 -> V_39 ;
}
}
else {
V_88 = ( T_4 * ) F_12 ( sizeof( T_4 ) ) ;
V_88 -> V_93 = V_85 ;
V_88 -> V_92 = V_86 ;
V_88 -> V_94 = V_1 -> V_19 -> V_39 ;
V_88 -> V_95 = V_96 ;
V_88 -> V_11 = V_96 -> V_11 ;
V_96 -> V_11 = V_88 ;
V_88 -> V_11 -> V_95 = V_88 ;
}
V_1 -> V_33 += V_85 ;
}
if ( V_1 -> V_33 > V_1 -> V_34 ) {
V_1 -> V_34 = V_1 -> V_33 ;
V_1 -> V_35 = V_1 -> V_17 -> V_94 ;
}
}
extern int
F_46 ( T_20 V_97 , T_5 * V_19 , const char * V_4 ,
int V_77 , T_19 V_78 , T_14 V_85 )
{
T_2 * V_1 = NULL ;
T_2 * V_82 = NULL ;
F_18 ( V_77 >= 0 && V_77 < ( int ) V_19 -> V_22 -> V_3 ) ;
V_82 = ( T_2 * ) F_40 ( V_19 -> V_22 , V_77 ) ;
if( V_82 -> V_16 ) {
V_1 = ( T_2 * ) F_30 ( V_82 -> V_16 , V_4 ) ;
} else {
V_1 = ( T_2 * ) F_30 ( V_19 -> V_21 , V_4 ) ;
}
if ( V_1 == NULL )
V_1 = F_39 ( V_19 , V_4 , V_77 , V_78 , V_78 ) ;
switch ( V_97 ) {
case V_98 :
V_1 -> V_5 += V_85 ;
F_45 ( V_1 , V_85 ) ;
break;
case V_99 : V_1 -> V_5 = V_85 ; break;
case V_100 :
V_1 -> V_5 ++ ;
F_45 ( V_1 , 1 ) ;
case V_101 :
V_1 -> V_27 += V_85 ;
if ( V_1 -> V_28 > V_85 ) {
V_1 -> V_28 = V_85 ;
}
if ( V_1 -> V_30 < V_85 ) {
V_1 -> V_30 = V_85 ;
}
V_1 -> V_12 |= V_102 ;
break;
case V_103 :
V_1 -> V_12 |= V_85 ;
break;
case V_104 :
V_1 -> V_12 &= ~ V_85 ;
break;
}
if ( V_1 )
return V_1 -> V_81 ;
else
return - 1 ;
}
extern char *
F_47 ( const char * V_105 )
{
T_3 V_106 ;
F_18 ( V_105 != NULL ) ;
for ( V_106 = 0 ; V_105 [ V_106 ] && V_105 [ V_106 ] != ',' ; V_106 ++ ) ;
if ( V_105 [ V_106 ] == ',' ) {
return F_48 ( V_105 , V_106 ) ;
} else {
return NULL ;
}
}
static T_21 *
F_49 ( char * V_107 )
{
T_1 * * V_108 ;
T_21 * V_18 ;
V_108 = F_50 ( ( T_1 * ) V_107 , L_2 , 2 ) ;
if ( V_108 [ 0 ] == NULL ) {
F_51 ( V_108 ) ;
return NULL ;
}
V_18 = ( T_21 * ) F_52 ( sizeof( T_21 ) ) ;
if ( V_108 [ 1 ] == NULL ) {
V_18 -> floor = ( T_14 ) strtol ( V_108 [ 0 ] , NULL , 10 ) ;
V_18 -> ceil = V_18 -> floor ;
} else {
if ( * ( V_108 [ 0 ] ) != '\0' ) {
V_18 -> floor = ( T_14 ) strtol ( V_108 [ 0 ] , NULL , 10 ) ;
} else
V_18 -> floor = V_31 ;
if ( * ( V_108 [ 1 ] ) != '\0' ) {
V_18 -> ceil = ( T_14 ) strtol ( V_108 [ 1 ] , NULL , 10 ) ;
} else
V_18 -> ceil = V_29 ;
}
F_51 ( V_108 ) ;
return V_18 ;
}
extern int
F_53 ( T_5 * V_19 , const T_1 * V_4 , int V_77 , ... )
{
T_22 V_109 ;
T_1 * V_110 ;
T_2 * V_111 = F_39 ( V_19 , V_4 , V_77 , FALSE , TRUE ) ;
T_2 * V_112 = NULL ;
va_start ( V_109 , V_77 ) ;
while ( ( V_110 = va_arg ( V_109 , T_1 * ) ) ) {
V_112 = F_39 ( V_19 , V_110 , V_111 -> V_81 , FALSE , FALSE ) ;
V_112 -> V_18 = F_49 ( V_110 ) ;
}
va_end ( V_109 ) ;
return V_111 -> V_81 ;
}
extern int
F_54 ( T_5 * V_19 , const T_1 * V_4 ,
int V_77 , int V_113 ,
T_1 * * V_114 )
{
int V_106 ;
T_2 * V_111 = F_39 ( V_19 , V_4 , V_77 , FALSE , TRUE ) ;
T_2 * V_112 = NULL ;
for ( V_106 = 0 ; V_106 < V_113 ; V_106 ++ ) {
V_112 = F_39 ( V_19 , V_114 [ V_106 ] , V_111 -> V_81 , FALSE , FALSE ) ;
V_112 -> V_18 = F_49 ( V_114 [ V_106 ] ) ;
}
return V_111 -> V_81 ;
}
extern int
F_44 ( T_5 * V_19 , const T_1 * V_83 )
{
T_2 * V_1 = ( T_2 * ) F_30 ( V_19 -> V_21 , V_83 ) ;
if ( V_1 )
return V_1 -> V_81 ;
else
return 0 ;
}
extern int
F_55 ( T_5 * V_19 , const T_1 * V_4 ,
const T_1 * V_83 , ... )
{
T_22 V_109 ;
T_1 * V_110 ;
T_2 * V_112 = NULL ;
int V_77 = F_44 ( V_19 , V_83 ) ;
T_2 * V_111 = F_39 ( V_19 , V_4 , V_77 , FALSE , TRUE ) ;
va_start ( V_109 , V_83 ) ;
while ( ( V_110 = va_arg ( V_109 , T_1 * ) ) ) {
V_112 = F_39 ( V_19 , V_110 , V_111 -> V_81 , FALSE , FALSE ) ;
V_112 -> V_18 = F_49 ( V_110 ) ;
}
va_end ( V_109 ) ;
return V_111 -> V_81 ;
}
extern int
F_56 ( T_5 * V_19 , const T_1 * V_4 , int V_77 ,
int V_115 )
{
T_2 * V_1 = NULL ;
T_2 * V_82 = NULL ;
T_2 * V_7 = NULL ;
T_14 V_116 , V_117 ;
if ( V_77 >= 0 && V_77 < ( int ) V_19 -> V_22 -> V_3 ) {
V_82 = ( T_2 * ) F_40 ( V_19 -> V_22 , V_77 ) ;
} else {
F_41 () ;
}
if( V_82 -> V_16 ) {
V_1 = ( T_2 * ) F_30 ( V_82 -> V_16 , V_4 ) ;
} else {
V_1 = ( T_2 * ) F_30 ( V_19 -> V_21 , V_4 ) ;
}
if ( V_1 == NULL )
F_41 () ;
V_1 -> V_27 += V_115 ;
if ( V_1 -> V_28 > V_115 ) {
V_1 -> V_28 = V_115 ;
}
if ( V_1 -> V_30 < V_115 ) {
V_1 -> V_30 = V_115 ;
}
V_1 -> V_12 |= V_102 ;
for ( V_7 = V_1 -> V_10 ; V_7 ; V_7 = V_7 -> V_11 ) {
V_116 = V_7 -> V_18 -> floor ;
V_117 = V_7 -> V_18 -> ceil ;
if ( V_115 >= V_116 && V_115 <= V_117 ) {
V_7 -> V_5 ++ ;
V_7 -> V_27 += V_115 ;
if ( V_7 -> V_28 > V_115 ) {
V_7 -> V_28 = V_115 ;
}
if ( V_7 -> V_30 < V_115 ) {
V_7 -> V_30 = V_115 ;
}
V_7 -> V_12 |= V_102 ;
F_45 ( V_7 , 1 ) ;
return V_1 -> V_81 ;
}
}
return V_1 -> V_81 ;
}
extern int
F_57 ( T_5 * V_19 , const T_1 * V_4 , int V_77 )
{
T_2 * V_1 = F_39 ( V_19 , V_4 , V_77 , TRUE , TRUE ) ;
if ( V_1 )
return V_1 -> V_81 ;
else
return 0 ;
}
extern int
F_58 ( T_5 * V_19 , const T_1 * V_4 ,
const T_1 * V_83 )
{
int V_77 = F_44 ( V_19 , V_83 ) ;
T_2 * V_1 ;
V_1 = F_39 ( V_19 , V_4 , V_77 , TRUE , TRUE ) ;
if ( V_1 )
return V_1 -> V_81 ;
else
return 0 ;
}
extern int
F_59 ( T_5 * V_19 , int V_118 , const T_1 * V_119 )
{
T_2 * V_82 = ( T_2 * ) F_40 ( V_19 -> V_22 , V_118 ) ;
V_82 -> V_5 ++ ;
F_45 ( V_82 , 1 ) ;
F_46 ( V_98 , V_19 , V_119 , V_118 , FALSE , 1 ) ;
return V_118 ;
}
extern T_1 *
F_5 ( T_1 * V_120 )
{
T_1 * V_121 = F_19 ( V_120 ) ;
T_1 * V_122 ;
if ( V_56 . V_123 ) {
return V_121 ;
}
V_122 = V_121 ;
while ( ( V_122 = strchr ( V_122 , '/' ) ) != NULL ) {
if ( * ( ++ V_122 ) == '/' ) {
memmove ( V_122 , V_122 + 1 , strlen ( V_122 ) ) ;
}
else {
memmove ( V_121 , V_122 , strlen ( V_122 ) + 1 ) ;
V_122 = V_121 ;
}
}
return V_121 ;
}
extern T_14
F_60 ( T_5 * V_19 )
{
switch ( ( V_19 -> V_12 & V_55 ) >> V_58 ) {
case V_124 : return V_125 ;
case V_126 : return V_127 ;
case V_128 : return V_129 ;
case V_130 : return V_131 ;
case V_132 : return V_133 ;
case V_134 : return V_135 ;
}
return V_127 ;
}
extern T_19
F_61 ( T_5 * V_19 )
{
return V_19 -> V_12 & V_60 ;
}
extern const T_1 *
F_62 ( T_14 V_136 )
{
switch ( V_136 ) {
case V_125 : return L_3 ;
case V_127 : return L_4 ;
case V_129 : return L_5 ;
case V_131 : return L_6 ;
case V_133 : return L_7 ;
case V_137 : return L_8 ;
case V_138 : return L_9 ;
case V_135 : return V_56 . V_139 ? L_10 : L_11 ;
case V_140 : return L_12 ;
default: return L_13 ;
}
}
extern T_14
F_63 ( T_14 V_136 )
{
if ( V_136 == V_125 ) {
return 36 ;
}
if ( V_136 < V_41 ) {
return 12 ;
}
return 0 ;
}
extern T_1 * *
F_64 ( const T_2 * V_1 )
{
T_1 * * V_141 = ( T_1 * * ) F_12 ( sizeof( T_1 * ) * ( V_1 -> V_19 -> V_40 ) ) ;
V_141 [ V_125 ] = ( V_1 -> V_12 & V_13 ) ? F_5 ( V_1 -> V_4 ) : F_19 ( V_1 -> V_4 ) ;
V_141 [ V_127 ] = F_3 ( L_14 , V_1 -> V_5 ) ;
V_141 [ V_129 ] = ( ( V_1 -> V_12 & V_102 ) || V_1 -> V_18 ) ?
( V_1 -> V_5 ? F_3 ( L_15 , ( ( float ) V_1 -> V_27 ) / V_1 -> V_5 ) : F_19 ( L_2 ) ) :
F_19 ( L_16 ) ;
V_141 [ V_131 ] = ( ( V_1 -> V_12 & V_102 ) || V_1 -> V_18 ) ?
( V_1 -> V_5 ? F_3 ( L_14 , V_1 -> V_28 ) : F_19 ( L_2 ) ) :
F_19 ( L_16 ) ;
V_141 [ V_133 ] = ( ( V_1 -> V_12 & V_102 ) || V_1 -> V_18 ) ?
( V_1 -> V_5 ? F_3 ( L_14 , V_1 -> V_30 ) : F_19 ( L_2 ) ) :
F_19 ( L_16 ) ;
V_141 [ V_137 ] = ( V_1 -> V_19 -> V_38 ) ? F_3 ( L_17 , ( ( float ) V_1 -> V_5 ) / V_1 -> V_19 -> V_38 ) : F_19 ( L_16 ) ;
V_141 [ V_138 ] = ( ( V_1 -> V_82 ) && ( V_1 -> V_82 -> V_5 ) ) ?
F_3 ( L_18 , ( V_1 -> V_5 * 100.0 ) / V_1 -> V_82 -> V_5 ) :
( V_1 -> V_82 == & ( V_1 -> V_19 -> V_23 ) ? F_19 ( L_19 ) : F_19 ( L_16 ) ) ;
if ( V_1 -> V_19 -> V_40 > V_140 ) {
V_141 [ V_135 ] = ( ! V_56 . V_89 ) ? F_19 ( L_16 ) :
( V_1 -> V_34 ? ( V_56 . V_139 ?
F_3 ( L_20 , V_1 -> V_34 ) :
F_3 ( L_17 , ( ( double ) V_1 -> V_34 ) / V_56 . V_91 ) ) :
F_19 ( L_2 ) ) ;
V_141 [ V_140 ] = ( ! V_56 . V_89 ) ? F_19 ( L_16 ) :
( V_1 -> V_34 ? F_3 ( L_21 , ( ( double ) V_1 -> V_35 / 1000.0 ) ) : F_19 ( L_2 ) ) ;
}
return V_141 ;
}
extern T_14
F_65 ( const T_2 * V_142 , const T_2 * V_143 , T_14 V_144 ,
T_19 V_145 )
{
int V_146 = 0 ;
float V_147 , V_148 ;
if ( V_56 . V_149 && ( V_142 -> V_18 && V_143 -> V_18 ) ) {
V_146 = V_142 -> V_18 -> floor - V_143 -> V_18 -> floor ;
if ( V_145 && ( ! V_56 . V_150 ) ) {
V_146 = - V_146 ;
}
return V_146 ;
}
switch ( V_144 )
{
case V_125 : if ( V_142 -> V_18 && V_143 -> V_18 ) {
V_146 = V_142 -> V_18 -> floor - V_143 -> V_18 -> floor ;
}
else if ( V_56 . V_151 ) {
V_146 = strcmp ( V_142 -> V_4 , V_143 -> V_4 ) ;
}
else {
V_146 = F_66 ( V_142 -> V_4 , V_143 -> V_4 ) ;
}
break;
case V_137 :
case V_138 :
case V_127 : V_146 = V_142 -> V_5 - V_143 -> V_5 ;
break;
case V_129 : if ( V_142 -> V_5 ) {
V_146 = 1 ;
if ( V_143 -> V_5 ) {
V_147 = ( ( float ) V_142 -> V_27 ) / V_142 -> V_5 ;
V_148 = ( ( float ) V_143 -> V_27 ) / V_143 -> V_5 ;
V_146 = ( V_147 > V_148 ) ? 1 : ( ( V_147 < V_148 ) ? - 1 : 0 ) ;
}
}
else {
V_146 = - 1 ;
}
break;
case V_131 : V_146 = V_142 -> V_28 - V_143 -> V_28 ;
break;
case V_133 : V_146 = V_142 -> V_30 - V_143 -> V_30 ;
break;
case V_135 : V_146 = V_142 -> V_34 - V_143 -> V_34 ;
break;
case V_140 : V_146 = ( V_142 -> V_35 > V_143 -> V_35 ) ? 1 : ( ( V_142 -> V_35 < V_143 -> V_35 ) ? - 1 : 0 ) ;
break;
default:
F_41 () ;
}
if ( ! V_146 ) {
if ( V_144 == V_125 ) {
V_146 = V_142 -> V_5 - V_143 -> V_5 ;
}
else {
if ( V_142 -> V_18 && V_143 -> V_18 ) {
V_146 = V_142 -> V_18 -> floor - V_143 -> V_18 -> floor ;
}
else if ( V_56 . V_151 ) {
V_146 = strcmp ( V_142 -> V_4 , V_143 -> V_4 ) ;
}
else {
V_146 = F_66 ( V_142 -> V_4 , V_143 -> V_4 ) ;
}
}
}
if ( V_145 ) {
V_146 = - V_146 ;
}
if ( ( V_142 -> V_12 & V_152 ) != ( V_143 -> V_12 & V_152 ) ) {
V_146 = ( V_142 -> V_12 & V_152 ) ? - 1 : 1 ;
}
return V_146 ;
}
extern T_23 *
F_67 ( const T_5 * V_19 , T_24 V_153 ,
T_14 V_144 , T_19 V_145 )
{
int V_154 = F_4 ( & V_19 -> V_23 , 0 ) ;
T_2 * V_7 ;
T_23 * V_155 ;
int V_93 ;
T_1 * V_156 = NULL ;
switch( V_153 )
{
case V_157 :
V_155 = F_68 ( L_22 ) ;
break;
case V_158 :
V_155 = F_68 ( L_23 ) ;
break;
case V_159 :
V_155 = F_68 ( L_24 ) ;
for ( V_93 = 0 ; V_93 < V_19 -> V_40 ; V_93 ++ ) {
F_69 ( V_155 , L_25 , F_62 ( V_93 ) ) ;
}
F_70 ( V_155 , L_26 ) ;
break;
case V_160 :
{
char V_161 [ 16 ] ;
int V_162 ;
V_162 = V_154 ;
for ( V_93 = 1 ; V_93 < V_19 -> V_40 ; V_93 ++ ) {
V_162 += F_63 ( V_93 ) + 2 ;
}
V_156 = ( T_1 * ) F_52 ( V_162 + 1 ) ;
memset ( V_156 , '=' , V_162 ) ;
V_156 [ V_162 ] = 0 ;
V_155 = F_68 ( L_26 ) ;
F_70 ( V_155 , V_156 ) ;
F_69 ( V_155 , L_27 , V_19 -> V_24 -> V_4 ) ;
F_2 ( V_161 , ( V_163 ) sizeof( V_161 ) , L_28 , V_154 ) ;
F_69 ( V_155 , V_161 , F_62 ( 0 ) ) ;
for ( V_93 = 1 ; V_93 < V_19 -> V_40 ; V_93 ++ ) {
F_2 ( V_161 , ( V_163 ) sizeof( V_161 ) , L_29 , F_63 ( V_93 ) + 1 ) ;
F_69 ( V_155 , V_161 , F_62 ( V_93 ) ) ;
}
memset ( V_156 , '-' , V_162 ) ;
F_69 ( V_155 , L_30 , V_156 ) ;
}
break;
default:
return F_68 ( L_31 ) ;
}
for ( V_7 = V_19 -> V_23 . V_10 ; V_7 ; V_7 = V_7 -> V_11 ) {
F_71 ( V_7 , V_155 , V_153 , 0 , L_16 , V_154 , V_144 , V_145 ) ;
}
if ( V_153 == V_160 ) {
F_69 ( V_155 , L_30 , V_156 ) ;
F_6 ( V_156 ) ;
}
return V_155 ;
}
extern T_14
F_72 ( T_15 V_142 , T_15 V_143 , T_17 V_164 )
{
return F_65 ( * ( const T_2 * * ) V_142 , * ( const T_2 * * ) V_143 ,
( ( V_165 * ) V_164 ) -> V_144 , ( ( V_165 * ) V_164 ) -> V_145 ) ;
}
static T_1 *
F_73 ( T_1 * V_166 )
{
T_1 * V_155 = V_166 ;
while ( ( V_155 = strpbrk ( V_155 , L_32 ) ) != NULL ) {
* ( V_155 ++ ) = '-' ;
}
return V_166 ;
}
T_25 void F_71 ( const T_2 * V_1 ,
T_23 * V_155 ,
T_24 V_153 ,
T_3 V_6 ,
const T_1 * V_167 ,
T_14 V_154 ,
T_14 V_144 ,
T_19 V_145 )
{
int V_93 ;
int V_40 = V_1 -> V_19 -> V_40 ;
T_1 * * V_141 = F_64 ( V_1 ) ;
T_2 * V_7 ;
V_165 V_168 ;
T_1 * V_169 ;
char V_161 [ 16 ] = L_33 ;
switch( V_153 )
{
case V_157 :
if ( V_6 ) {
F_2 ( V_161 , ( V_163 ) sizeof( V_161 ) , L_34 , V_6 * 4 - 2 ) ;
}
F_69 ( V_155 , V_161 , L_16 , V_6 ? L_35 : L_16 , L_36 ) ;
F_69 ( V_155 , L_37 , V_141 [ 0 ] ) ;
for ( V_93 = 1 ; V_93 < V_40 ; V_93 ++ ) {
if ( * V_141 [ V_93 ] ) {
F_69 ( V_155 , V_161 , L_16 , V_6 ? L_38 : L_16 ,
F_62 ( V_93 ) ) ;
F_69 ( V_155 , L_39 , V_141 [ V_93 ] ) ;
}
}
if ( V_1 -> V_10 ) {
F_69 ( V_155 , V_161 , L_16 , V_6 ? L_38 : L_16 , L_40 ) ;
}
break;
case V_158 :
{
char * V_170 = F_74 ( V_141 [ 0 ] ) ;
F_69 ( V_155 , L_41 , V_170 ,
V_1 -> V_18 ? L_42 : L_16 ) ;
F_6 ( V_170 ) ;
for ( V_93 = 1 ; V_93 < V_40 ; V_93 ++ ) {
T_1 * V_171 = F_19 ( F_62 ( V_93 ) ) ;
F_69 ( V_155 , L_43 , F_73 ( V_171 ) ) ;
F_69 ( V_155 , L_44 , V_141 [ V_93 ] , V_171 ) ;
F_6 ( V_171 ) ;
}
}
break;
case V_159 :
F_69 ( V_155 , L_45 , V_6 , V_167 , V_141 [ 0 ] ) ;
for ( V_93 = 1 ; V_93 < V_40 ; V_93 ++ ) {
F_69 ( V_155 , L_46 , V_141 [ V_93 ] ) ;
}
F_70 ( V_155 , L_26 ) ;
break;
case V_160 :
F_2 ( V_161 , ( V_163 ) sizeof( V_161 ) , L_47 , V_6 , V_154 - V_6 ) ;
F_69 ( V_155 , V_161 , L_16 , V_141 [ 0 ] ) ;
for ( V_93 = 1 ; V_93 < V_40 ; V_93 ++ ) {
F_2 ( V_161 , ( V_163 ) sizeof( V_161 ) , L_29 , F_63 ( V_93 ) + 1 ) ;
F_69 ( V_155 , V_161 , V_141 [ V_93 ] ) ;
}
F_70 ( V_155 , L_26 ) ;
break;
}
V_6 ++ ;
V_6 = V_6 > V_9 ? V_9 : V_6 ;
V_169 = F_3 ( L_48 , V_167 , V_141 [ 0 ] ) ;
for ( V_93 = 0 ; V_93 < V_40 ; V_93 ++ ) {
F_6 ( V_141 [ V_93 ] ) ;
}
F_6 ( V_141 ) ;
if ( V_1 -> V_10 ) {
T_26 * V_172 = F_75 ( FALSE , FALSE , sizeof( V_7 ) ) ;
for ( V_7 = V_1 -> V_10 ; V_7 ; V_7 = V_7 -> V_11 ) {
F_76 ( V_172 , V_7 ) ;
}
V_168 . V_144 = V_144 ;
V_168 . V_145 = V_145 ;
F_77 ( V_172 , F_72 , & V_168 ) ;
for ( V_93 = 0 ; V_93 < ( ( int ) V_172 -> V_3 ) ; V_93 ++ ) {
F_71 ( F_78 ( V_172 , T_2 * , V_93 ) , V_155 , V_153 ,
V_6 , V_169 , V_154 , V_144 , V_145 ) ;
}
F_79 ( V_172 , FALSE ) ;
}
F_6 ( V_169 ) ;
if ( V_153 == V_158 ) {
F_70 ( V_155 , L_49 ) ;
}
}
