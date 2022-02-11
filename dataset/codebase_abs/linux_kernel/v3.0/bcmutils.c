struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 ) {
F_3 ( V_3 , V_2 ) ;
V_3 -> V_4 = 0 ;
}
return V_3 ;
}
void F_4 ( struct V_1 * V_3 )
{
struct V_1 * V_5 ;
int V_6 = 0 ;
while ( V_3 ) {
V_5 = V_3 -> V_7 ;
V_3 -> V_7 = NULL ;
if ( V_3 -> V_8 )
F_5 ( V_3 ) ;
else
F_6 ( V_3 ) ;
V_6 ++ ;
V_3 = V_5 ;
}
}
T_1 F_7 ( struct V_1 * V_9 , T_1 V_10 , int V_2 ,
unsigned char * V_11 )
{
T_1 V_12 , V_13 = 0 ;
for (; V_9 && V_10 ; V_9 = V_9 -> V_7 ) {
if ( V_10 < ( T_1 ) ( V_9 -> V_2 ) )
break;
V_10 -= V_9 -> V_2 ;
}
if ( ! V_9 )
return 0 ;
for (; V_9 && V_2 ; V_9 = V_9 -> V_7 ) {
V_12 = F_8 ( ( T_1 ) ( V_9 -> V_2 ) - V_10 , ( T_1 ) V_2 ) ;
memcpy ( V_9 -> V_14 + V_10 , V_11 , V_12 ) ;
V_11 += V_12 ;
V_2 -= V_12 ;
V_13 += V_12 ;
V_10 = 0 ;
}
return V_13 ;
}
T_1 F_9 ( struct V_1 * V_9 )
{
T_1 V_15 ;
V_15 = 0 ;
for (; V_9 ; V_9 = V_9 -> V_7 )
V_15 += V_9 -> V_2 ;
return V_15 ;
}
struct V_1 * F_10 ( struct V_16 * V_17 , int V_18 ,
struct V_1 * V_9 )
{
struct V_19 * V_20 ;
if ( F_11 ( V_17 ) || F_12 ( V_17 , V_18 ) )
return NULL ;
V_20 = & V_17 -> V_20 [ V_18 ] ;
if ( V_20 -> V_21 )
V_20 -> V_22 -> V_23 = V_9 ;
else
V_20 -> V_21 = V_9 ;
V_20 -> V_22 = V_9 ;
V_20 -> V_2 ++ ;
V_17 -> V_2 ++ ;
if ( V_17 -> V_24 < V_18 )
V_17 -> V_24 = ( V_25 ) V_18 ;
return V_9 ;
}
struct V_1 * F_13 ( struct V_16 * V_17 , int V_18 ,
struct V_1 * V_9 )
{
struct V_19 * V_20 ;
if ( F_11 ( V_17 ) || F_12 ( V_17 , V_18 ) )
return NULL ;
V_20 = & V_17 -> V_20 [ V_18 ] ;
if ( V_20 -> V_21 == NULL )
V_20 -> V_22 = V_9 ;
V_9 -> V_23 = V_20 -> V_21 ;
V_20 -> V_21 = V_9 ;
V_20 -> V_2 ++ ;
V_17 -> V_2 ++ ;
if ( V_17 -> V_24 < V_18 )
V_17 -> V_24 = ( V_25 ) V_18 ;
return V_9 ;
}
struct V_1 * F_14 ( struct V_16 * V_17 , int V_18 )
{
struct V_19 * V_20 ;
struct V_1 * V_9 ;
V_20 = & V_17 -> V_20 [ V_18 ] ;
V_9 = V_20 -> V_21 ;
if ( V_9 == NULL )
return NULL ;
V_20 -> V_21 = V_9 -> V_23 ;
if ( V_20 -> V_21 == NULL )
V_20 -> V_22 = NULL ;
V_20 -> V_2 -- ;
V_17 -> V_2 -- ;
V_9 -> V_23 = NULL ;
return V_9 ;
}
struct V_1 * F_15 ( struct V_16 * V_17 , int V_18 )
{
struct V_19 * V_20 ;
struct V_1 * V_9 , * V_23 ;
V_20 = & V_17 -> V_20 [ V_18 ] ;
V_9 = V_20 -> V_21 ;
if ( V_9 == NULL )
return NULL ;
for ( V_23 = NULL ; V_9 != V_20 -> V_22 ; V_9 = V_9 -> V_23 )
V_23 = V_9 ;
if ( V_23 )
V_23 -> V_23 = NULL ;
else
V_20 -> V_21 = NULL ;
V_20 -> V_22 = V_23 ;
V_20 -> V_2 -- ;
V_17 -> V_2 -- ;
return V_9 ;
}
void
F_16 ( struct V_16 * V_17 , int V_18 , bool V_26 ,
T_2 V_27 , void * V_28 )
{
struct V_19 * V_20 ;
struct V_1 * V_9 , * V_23 = NULL ;
V_20 = & V_17 -> V_20 [ V_18 ] ;
V_9 = V_20 -> V_21 ;
while ( V_9 ) {
if ( V_27 == NULL || (* V_27) ( V_9 , V_28 ) ) {
bool V_21 = ( V_9 == V_20 -> V_21 ) ;
if ( V_21 )
V_20 -> V_21 = V_9 -> V_23 ;
else
V_23 -> V_23 = V_9 -> V_23 ;
V_9 -> V_23 = NULL ;
F_4 ( V_9 ) ;
V_20 -> V_2 -- ;
V_17 -> V_2 -- ;
V_9 = ( V_21 ? V_20 -> V_21 : V_23 -> V_23 ) ;
} else {
V_23 = V_9 ;
V_9 = V_9 -> V_23 ;
}
}
if ( V_20 -> V_21 == NULL ) {
V_20 -> V_22 = NULL ;
}
}
void F_17 ( struct V_16 * V_17 , bool V_26 ,
T_2 V_27 , void * V_28 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_17 -> V_29 ; V_18 ++ )
F_16 ( V_17 , V_18 , V_26 , V_27 , V_28 ) ;
}
void F_18 ( struct V_16 * V_17 , int V_29 , int V_30 )
{
int V_18 ;
memset ( V_17 , 0 ,
F_19 ( struct V_16 , V_20 ) + ( sizeof( struct V_19 ) * V_29 ) ) ;
V_17 -> V_29 = ( V_31 ) V_29 ;
V_17 -> V_32 = ( V_31 ) V_30 ;
for ( V_18 = 0 ; V_18 < V_29 ; V_18 ++ )
V_17 -> V_20 [ V_18 ] . V_32 = V_17 -> V_32 ;
}
struct V_1 * F_20 ( struct V_16 * V_17 , int * V_33 )
{
int V_18 ;
if ( V_17 -> V_2 == 0 )
return NULL ;
for ( V_18 = 0 ; V_18 < V_17 -> V_24 ; V_18 ++ )
if ( V_17 -> V_20 [ V_18 ] . V_21 )
break;
if ( V_33 )
* V_33 = V_18 ;
return V_17 -> V_20 [ V_18 ] . V_22 ;
}
int F_21 ( struct V_16 * V_17 , T_1 V_34 )
{
int V_18 , V_2 ;
V_2 = 0 ;
for ( V_18 = 0 ; V_18 <= V_17 -> V_24 ; V_18 ++ )
if ( V_34 & ( 1 << V_18 ) )
V_2 += V_17 -> V_20 [ V_18 ] . V_2 ;
return V_2 ;
}
struct V_1 * F_22 ( struct V_16 * V_17 , T_1 V_34 ,
int * V_33 )
{
struct V_19 * V_20 ;
struct V_1 * V_9 ;
int V_18 ;
if ( V_17 -> V_2 == 0 )
return NULL ;
while ( ( V_18 = V_17 -> V_24 ) > 0 && V_17 -> V_20 [ V_18 ] . V_21 == NULL )
V_17 -> V_24 -- ;
while ( ( V_34 & ( 1 << V_18 ) ) == 0 || V_17 -> V_20 [ V_18 ] . V_21 == NULL )
if ( V_18 -- == 0 )
return NULL ;
V_20 = & V_17 -> V_20 [ V_18 ] ;
V_9 = V_20 -> V_21 ;
if ( V_9 == NULL )
return NULL ;
V_20 -> V_21 = V_9 -> V_23 ;
if ( V_20 -> V_21 == NULL )
V_20 -> V_22 = NULL ;
V_20 -> V_2 -- ;
if ( V_33 )
* V_33 = V_18 ;
V_17 -> V_2 -- ;
V_9 -> V_23 = NULL ;
return V_9 ;
}
int F_23 ( char * V_9 , V_25 * V_35 )
{
int V_36 = 0 ;
for (; ; ) {
V_35 [ V_36 ++ ] = ( char ) F_24 ( V_9 , & V_9 , 16 ) ;
if ( ! * V_9 ++ || V_36 == 6 )
break;
}
return V_36 == 6 ;
}
void F_25 ( const char * V_37 , struct V_1 * V_38 )
{
struct V_1 * V_9 ;
if ( V_37 && ( V_37 [ 0 ] != '\0' ) )
F_26 ( V_39 L_1 , V_37 ) ;
for ( V_9 = V_38 ; V_9 ; V_9 = V_9 -> V_7 )
F_27 ( L_2 , V_40 , V_9 -> V_14 , V_9 -> V_2 ) ;
}
const T_3 * F_28 ( const T_3 * V_41 , const char * V_42 )
{
const T_3 * V_43 ;
const char * V_44 ;
V_44 = strrchr ( V_42 , ':' ) ;
if ( V_44 != NULL )
V_44 ++ ;
else
V_44 = V_42 ;
for ( V_43 = V_41 ; V_43 -> V_42 ; V_43 ++ ) {
if ( ! strcmp ( V_43 -> V_42 , V_44 ) )
return V_43 ;
}
return NULL ;
}
int F_29 ( const T_3 * V_43 , void * V_28 , int V_2 , bool V_45 )
{
int V_46 = 0 ;
switch ( V_43 -> type ) {
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
if ( V_2 < ( int ) sizeof( int ) ) {
V_46 = - V_54 ;
}
break;
case V_55 :
if ( V_2 < V_43 -> V_56 ) {
V_46 = - V_54 ;
}
break;
case V_57 :
if ( ! V_45 ) {
V_46 = - V_58 ;
} else if ( V_2 ) {
V_46 = - V_59 ;
}
break;
default:
V_46 = - V_58 ;
}
return V_46 ;
}
V_25 F_30 ( V_25 * V_60 ,
T_1 V_61 ,
V_25 V_62
) {
while ( V_61 -- > 0 )
V_62 = V_63 [ ( V_62 ^ * V_60 ++ ) & 0xff ] ;
return V_62 ;
}
T_4 * F_31 ( void * V_11 , int V_64 , T_1 V_65 )
{
T_4 * V_66 ;
int V_67 ;
V_66 = ( T_4 * ) V_11 ;
V_67 = V_64 ;
while ( V_67 >= 2 ) {
int V_2 = V_66 -> V_2 ;
if ( ( V_66 -> V_68 == V_65 ) && ( V_67 >= ( V_2 + 2 ) ) )
return V_66 ;
V_66 = ( T_4 * ) ( ( V_25 * ) V_66 + ( V_2 + 2 ) ) ;
V_67 -= ( V_2 + 2 ) ;
}
return NULL ;
}
int
F_32 ( const T_5 * V_69 , T_6 V_70 , char * V_11 , int V_2 )
{
int V_36 ;
char * V_9 = V_11 ;
char V_71 [ 16 ] ;
int V_72 = 0 , V_73 = 0 ;
T_6 V_74 ;
const char * V_42 ;
if ( V_2 < 2 || ! V_11 )
return 0 ;
V_11 [ 0 ] = '\0' ;
for ( V_36 = 0 ; V_70 != 0 ; V_36 ++ ) {
V_74 = V_69 [ V_36 ] . V_74 ;
V_42 = V_69 [ V_36 ] . V_42 ;
if ( V_74 == 0 && V_70 != 0 ) {
snprintf ( V_71 , 16 , L_3 , V_70 ) ;
V_42 = V_71 ;
V_70 = 0 ;
} else if ( ( V_70 & V_74 ) == 0 )
continue;
V_70 &= ~ V_74 ;
V_73 = strlen ( V_42 ) ;
V_72 += V_73 ;
if ( V_70 != 0 )
V_72 += 1 ;
if ( V_2 <= V_72 )
break;
strncpy ( V_9 , V_42 , V_73 + 1 ) ;
V_9 += V_73 ;
if ( V_70 != 0 )
V_9 += snprintf ( V_9 , 2 , L_4 ) ;
V_2 -= V_72 ;
}
if ( V_70 != 0 ) {
if ( V_2 < 2 )
V_9 -= 2 - V_2 ;
V_9 += snprintf ( V_9 , 2 , L_5 ) ;
}
return ( int ) ( V_9 - V_11 ) ;
}
int F_33 ( char * V_75 , const void * V_76 , int V_2 )
{
int V_36 ;
char * V_9 = V_75 ;
const V_25 * V_77 = ( const V_25 * ) V_76 ;
for ( V_36 = 0 ; V_36 < V_2 ; V_36 ++ ) {
V_9 += snprintf ( V_9 , 3 , L_6 , * V_77 ) ;
V_77 ++ ;
}
return ( int ) ( V_9 - V_75 ) ;
}
char * F_34 ( T_1 V_78 , char * V_11 , T_1 V_2 )
{
const char * V_79 ;
V_79 = ( ( V_78 > 0xa000 ) || ( V_78 < 0x4000 ) ) ? L_7 : L_8 ;
snprintf ( V_11 , V_2 , V_79 , V_78 ) ;
return V_11 ;
}
T_1 F_35 ( char * V_42 , char * V_14 , T_1 V_80 , char * V_11 , T_1 V_64 )
{
T_1 V_2 ;
V_2 = strlen ( V_42 ) + 1 ;
if ( ( V_2 + V_80 ) > V_64 )
return 0 ;
strncpy ( V_11 , V_42 , V_64 ) ;
memcpy ( & V_11 [ V_2 ] , V_14 , V_80 ) ;
V_2 += V_80 ;
return V_2 ;
}
V_31 F_36 ( V_25 V_81 )
{
T_1 V_82 = 1 ;
int V_83 = V_81 - V_84 ;
if ( V_83 >= V_85 ) {
return 0xFFFF ;
}
while ( V_83 < 0 ) {
V_83 += 40 ;
V_82 *= 10 ;
}
return ( V_86 [ V_83 ] + V_82 / 2 ) / V_82 ;
}
V_25 F_37 ( V_31 V_87 )
{
V_25 V_81 ;
int V_10 ;
T_1 V_88 = V_87 ;
T_1 V_89 ;
if ( V_88 <= 1 )
return 0 ;
V_10 = V_84 ;
while ( V_88 < V_90 ) {
V_88 *= 10 ;
V_10 -= 40 ;
}
for ( V_81 = 0 ; V_81 < V_85 - 1 ; V_81 ++ ) {
V_89 = V_86 [ V_81 ] + ( V_86 [ V_81 + 1 ] -
V_86 [ V_81 ] ) / 2 ;
if ( V_88 < V_89 )
break;
}
V_81 += ( V_25 ) V_10 ;
return V_81 ;
}
T_1 F_38 ( V_25 * V_91 , T_1 V_92 )
{
T_1 V_93 = 0 , V_36 ;
V_25 V_94 ;
for ( V_36 = 0 ; V_36 < V_92 ; V_36 ++ ) {
V_94 = V_91 [ V_36 ] ;
while ( V_94 ) {
V_93 ++ ;
V_94 &= ( V_94 - 1 ) ;
}
}
return V_93 ;
}
void F_39 ( struct V_95 * V_96 , char * V_11 , T_1 V_97 )
{
V_96 -> V_98 = V_96 -> V_97 = V_97 ;
V_96 -> V_99 = V_96 -> V_11 = V_11 ;
}
int F_40 ( struct V_95 * V_96 , const char * V_79 , ... )
{
T_7 V_100 ;
int V_101 ;
va_start ( V_100 , V_79 ) ;
V_101 = vsnprintf ( V_96 -> V_11 , V_96 -> V_97 , V_79 , V_100 ) ;
if ( ( V_101 == - 1 ) || ( V_101 >= ( int ) V_96 -> V_97 ) || ( V_101 == 0 ) ) {
V_96 -> V_97 = 0 ;
} else {
V_96 -> V_97 -= V_101 ;
V_96 -> V_11 += V_101 ;
}
va_end ( V_100 ) ;
return V_101 ;
}
