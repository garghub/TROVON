void
F_1 ( T_1 * V_1 , const T_2 V_2 )
{
int V_3 ;
V_1 -> V_2 = V_2 ;
V_1 -> V_4 = F_2 ( V_5 , V_2 ) ;
V_1 -> V_6 = F_2 ( int , V_7 ) ;
V_1 -> V_8 = F_2 ( int , V_7 ) ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
V_1 -> V_4 [ V_3 ] . V_9 = NULL ;
}
V_1 -> V_10 . V_10 = F_2 ( const V_11 * , V_2 + 1 ) ;
V_1 -> V_10 . V_12 = F_2 ( V_11 * , V_2 + 1 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
V_1 -> V_6 [ V_3 ] = - 1 ;
V_1 -> V_8 [ V_3 ] = - 1 ;
}
V_1 -> V_13 = F_3 ( V_14 ,
V_15 , V_16 , NULL ) ;
}
static void
F_4 ( T_3 V_17 , T_3 T_4 V_18 )
{
F_5 ( V_17 ) ;
}
static void
F_6 ( T_5 * * V_19 )
{
if ( * V_19 != NULL ) {
F_7 ( * V_19 , F_4 , NULL ) ;
F_8 ( * V_19 ) ;
}
* V_19 = NULL ;
}
void
F_9 ( T_1 * V_1 )
{
int V_3 ;
V_5 * V_20 ;
for ( V_3 = 0 ; V_3 < V_1 -> V_2 ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
F_5 ( V_20 -> V_21 ) ;
F_5 ( V_20 -> V_22 ) ;
F_5 ( V_20 -> V_23 ) ;
F_10 ( V_20 -> V_24 ) ;
F_5 ( V_20 -> V_25 ) ;
F_5 ( V_1 -> V_10 . V_12 [ V_3 ] ) ;
F_6 ( & V_20 -> V_9 ) ;
}
F_5 ( V_1 -> V_4 ) ;
F_5 ( V_1 -> V_6 ) ;
F_5 ( V_1 -> V_8 ) ;
F_5 ( ( V_11 * * ) V_1 -> V_10 . V_10 ) ;
F_5 ( V_1 -> V_10 . V_12 ) ;
F_11 ( V_1 -> V_13 ) ;
}
void
F_12 ( T_1 * V_1 , const struct V_26 * V_27 )
{
int V_3 ;
V_5 * V_20 ;
if ( ! V_1 )
return;
for ( V_3 = 0 ; V_3 < V_1 -> V_2 ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
V_20 -> V_25 [ 0 ] = '\0' ;
V_20 -> V_28 = V_20 -> V_25 ;
V_20 -> V_29 = 0 ;
V_1 -> V_10 . V_10 [ V_3 ] = L_1 ;
V_1 -> V_10 . V_12 [ V_3 ] [ 0 ] = '\0' ;
}
V_1 -> V_30 = TRUE ;
V_1 -> V_27 = V_27 ;
}
T_6
F_13 ( T_1 * V_1 )
{
return F_14 ( V_1 ) ;
}
void
F_15 ( T_1 * V_1 , const T_6 V_30 )
{
if ( V_1 )
V_1 -> V_30 = V_30 ;
}
void
F_16 ( T_1 * V_1 , const T_2 V_31 )
{
int V_3 ;
V_5 * V_20 ;
if ( ! F_17 ( V_1 , V_31 ) )
return;
for ( V_3 = V_1 -> V_6 [ V_31 ] ; V_3 <= V_1 -> V_8 [ V_31 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_31 ] ) {
V_20 -> V_29 = ( int ) strlen ( V_20 -> V_28 ) ;
}
}
}
void
F_18 ( T_1 * V_1 , const T_2 V_31 )
{
int V_3 ;
V_5 * V_20 ;
if ( ! F_17 ( V_1 , V_31 ) )
return;
for ( V_3 = V_1 -> V_6 [ V_31 ] ; V_3 <= V_1 -> V_8 [ V_31 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_31 ] ) {
V_20 -> V_29 = 0 ;
}
}
}
const V_11 *
F_19 ( T_1 * V_1 , const T_2 V_31 )
{
int V_3 ;
const V_11 * V_32 = NULL ;
V_5 * V_20 ;
if ( ! ( V_1 && ( V_1 ) -> V_6 [ V_31 ] >= 0 ) ) {
return NULL ;
}
for ( V_3 = V_1 -> V_6 [ V_31 ] ; V_3 <= V_1 -> V_8 [ V_31 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_31 ] ) {
V_32 = ( V_20 -> V_28 ) ;
}
}
return V_32 ;
}
void
F_20 ( T_1 * V_1 , const T_2 V_31 )
{
int V_3 ;
V_5 * V_20 ;
if ( ! F_17 ( V_1 , V_31 ) )
return;
for ( V_3 = V_1 -> V_6 [ V_31 ] ; V_3 <= V_1 -> V_8 [ V_31 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_31 ] ) {
if ( V_20 -> V_25 == V_20 -> V_28 || V_20 -> V_29 == 0 ) {
V_20 -> V_25 [ V_20 -> V_29 ] = '\0' ;
V_20 -> V_28 = V_20 -> V_25 ;
}
V_1 -> V_10 . V_10 [ V_3 ] = L_1 ;
V_1 -> V_10 . V_12 [ V_3 ] [ 0 ] = '\0' ;
}
}
}
T_6
F_21 ( T_1 * V_1 )
{
return F_22 ( V_1 ) ;
}
T_6
F_23 ( void )
{
#ifdef F_24
return F_25 () ;
#else
return FALSE ;
#endif
}
void F_26 ( T_7 * V_33 , T_1 * V_1 )
{
int V_3 ;
V_5 * V_20 ;
if ( ! F_22 ( V_1 ) )
return;
for ( V_3 = V_1 -> V_6 [ V_34 ] ;
V_3 <= V_1 -> V_8 [ V_34 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_34 ] &&
V_20 -> V_23 &&
V_20 -> V_9 ) {
V_20 -> V_28 = V_20 -> V_25 ;
V_1 -> V_10 . V_10 [ V_3 ] = F_27 ( V_33 , V_20 -> V_9 ,
V_20 -> V_35 ,
V_20 -> V_25 ,
V_1 -> V_10 . V_12 [ V_3 ] ,
V_36 ) ;
}
}
}
void
F_28 ( T_7 * V_33 , T_1 * V_1 )
{
int V_3 ;
V_5 * V_20 ;
if ( ! F_22 ( V_1 ) )
return;
for ( V_3 = V_1 -> V_6 [ V_34 ] ;
V_3 <= V_1 -> V_8 [ V_34 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_34 ] &&
V_20 -> V_24 ) {
F_29 ( V_33 , V_20 -> V_24 ) ;
}
}
}
void
F_30 ( T_1 * V_1 , const T_2 V_31 , const V_11 * V_37 , ... )
{
T_8 V_38 ;
T_9 V_39 , V_40 ;
int V_3 ;
const V_11 * V_41 ;
V_5 * V_20 ;
if ( ! F_17 ( V_1 , V_31 ) )
return;
if ( V_31 == V_42 )
V_40 = V_43 ;
else
V_40 = V_36 ;
for ( V_3 = V_1 -> V_6 [ V_31 ] ; V_3 <= V_1 -> V_8 [ V_31 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_31 ] ) {
F_31 ( V_20 , V_40 ) ;
V_39 = strlen ( V_20 -> V_25 ) ;
if ( V_39 >= V_40 )
return;
va_start ( V_38 , V_37 ) ;
V_41 = V_37 ;
do {
if G_UNLIKELY( V_41 == NULL )
V_41 = L_2 ;
V_39 += F_32 ( & V_20 -> V_25 [ V_39 ] , V_41 , V_40 - V_39 ) ;
} while ( V_39 < V_40 && ( V_41 = va_arg ( V_38 , const char * ) ) != V_44 );
va_end ( V_38 ) ;
}
}
}
void
F_33 ( T_1 * V_1 , const T_2 V_45 , const V_11 * V_46 , T_10 V_47 , const V_11 * V_48 )
{
char V_49 [ 16 ] ;
F_34 ( V_47 , V_49 , sizeof( V_49 ) ) ;
F_30 ( V_1 , V_45 , V_48 ? V_48 : L_1 , V_46 , L_3 , V_49 , V_44 ) ;
}
static int
F_35 ( V_11 * V_49 , T_11 V_50 , T_12 V_51 , T_13 V_47 )
{
const char * V_41 ;
int V_52 ;
if ( V_53 . V_54 &&
( V_41 = F_36 ( V_51 , V_47 ) ) != NULL ) {
V_52 = F_37 ( V_49 , V_50 , L_4 V_55 L_5 , V_41 , V_47 ) ;
} else {
V_52 = F_37 ( V_49 , V_50 , L_6 V_55 , V_47 ) ;
}
return V_52 ;
}
void
F_38 ( T_1 * V_1 , const T_2 V_45 , T_12 V_51 , T_13 V_56 , T_13 V_57 )
{
char V_58 [ 32 ] , V_59 [ 32 ] ;
F_35 ( V_58 , 32 , V_51 , V_56 ) ;
F_35 ( V_59 , 32 , V_51 , V_57 ) ;
F_30 ( V_1 , V_45 , V_58 , V_60 , V_59 , V_44 ) ;
}
static void
F_39 ( T_1 * V_1 , const int V_31 , const char * V_61 , const char * V_62 , T_8 V_38 )
{
T_9 V_63 , V_40 , V_64 ;
int V_3 ;
V_5 * V_20 ;
V_64 = ( V_61 ) ? strlen ( V_61 ) : 0 ;
if ( V_31 == V_42 )
V_40 = V_43 ;
else
V_40 = V_36 ;
for ( V_3 = V_1 -> V_6 [ V_31 ] ; V_3 <= V_1 -> V_8 [ V_31 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_31 ] ) {
F_31 ( V_20 , V_40 ) ;
V_63 = strlen ( V_20 -> V_25 ) ;
if ( V_64 != 0 && V_63 != 0 ) {
F_40 ( V_20 -> V_25 , V_61 , V_40 ) ;
V_63 += V_64 ;
}
if ( V_63 < V_40 ) {
T_8 V_65 ;
F_41 ( V_65 , V_38 ) ;
F_42 ( & V_20 -> V_25 [ V_63 ] , ( T_10 ) ( V_40 - V_63 ) , V_62 , V_65 ) ;
va_end ( V_65 ) ;
}
}
}
}
void
F_43 ( T_1 * V_1 , const T_2 V_31 , const V_11 * V_62 , ... )
{
T_8 V_38 ;
if ( ! F_17 ( V_1 , V_31 ) )
return;
va_start ( V_38 , V_62 ) ;
F_39 ( V_1 , V_31 , NULL , V_62 , V_38 ) ;
va_end ( V_38 ) ;
}
void
F_44 ( T_1 * V_1 , const T_2 V_31 , const V_11 * V_61 ,
const V_11 * V_62 , ... )
{
T_8 V_38 ;
if ( ! F_17 ( V_1 , V_31 ) )
return;
if ( V_61 == NULL )
V_61 = L_7 ;
va_start ( V_38 , V_62 ) ;
F_39 ( V_1 , V_31 , V_61 , V_62 , V_38 ) ;
va_end ( V_38 ) ;
}
void
F_45 ( T_1 * V_1 , const T_2 V_31 , const V_11 * V_62 , ... )
{
T_8 V_38 ;
int V_3 ;
char V_66 [ V_67 ] ;
const char * V_68 ;
int V_40 ;
V_5 * V_20 ;
if ( ! F_17 ( V_1 , V_31 ) )
return;
if ( V_31 == V_42 )
V_40 = V_43 ;
else
V_40 = V_36 ;
for ( V_3 = V_1 -> V_6 [ V_31 ] ; V_3 <= V_1 -> V_8 [ V_31 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_31 ] ) {
if ( V_20 -> V_28 != V_20 -> V_25 ) {
V_68 = V_20 -> V_28 ;
} else {
F_32 ( V_66 , V_20 -> V_25 , V_40 ) ;
V_68 = V_66 ;
}
va_start ( V_38 , V_62 ) ;
F_42 ( V_20 -> V_25 , V_40 , V_62 , V_38 ) ;
va_end ( V_38 ) ;
if ( V_20 -> V_29 > 0 )
V_20 -> V_29 += ( int ) strlen ( V_20 -> V_25 ) ;
F_40 ( V_20 -> V_25 , V_68 , V_40 ) ;
V_20 -> V_28 = V_20 -> V_25 ;
}
}
}
void
F_46 ( T_1 * V_1 , const T_2 V_31 , const V_11 * V_62 , ... )
{
T_8 V_38 ;
int V_3 ;
char V_66 [ V_67 ] ;
const char * V_68 ;
int V_40 ;
V_5 * V_20 ;
if ( ! F_17 ( V_1 , V_31 ) )
return;
if ( V_31 == V_42 )
V_40 = V_43 ;
else
V_40 = V_36 ;
for ( V_3 = V_1 -> V_6 [ V_31 ] ; V_3 <= V_1 -> V_8 [ V_31 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_31 ] ) {
if ( V_20 -> V_28 != V_20 -> V_25 ) {
V_68 = V_20 -> V_28 ;
} else {
F_32 ( V_66 , V_20 -> V_25 , V_40 ) ;
V_68 = V_66 ;
}
va_start ( V_38 , V_62 ) ;
F_42 ( V_20 -> V_25 , V_40 , V_62 , V_38 ) ;
va_end ( V_38 ) ;
if ( V_20 -> V_29 > 0 ) {
V_20 -> V_29 += ( int ) strlen ( V_20 -> V_25 ) ;
} else {
V_20 -> V_29 = ( int ) strlen ( V_20 -> V_25 ) ;
}
F_40 ( V_20 -> V_25 , V_68 , V_40 ) ;
V_20 -> V_28 = V_20 -> V_25 ;
}
}
}
void
F_47 ( T_1 * V_1 , const T_2 V_31 , const V_11 * V_41 )
{
int V_3 ;
T_9 V_40 ;
V_5 * V_20 ;
if ( ! F_17 ( V_1 , V_31 ) )
return;
if ( V_31 == V_42 )
V_40 = V_43 ;
else
V_40 = V_36 ;
for ( V_3 = V_1 -> V_6 [ V_31 ] ; V_3 <= V_1 -> V_8 [ V_31 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_31 ] ) {
if ( V_20 -> V_29 != 0 ) {
F_31 ( V_20 , V_40 ) ;
} else {
V_20 -> V_28 = V_20 -> V_25 ;
}
F_32 ( & V_20 -> V_25 [ V_20 -> V_29 ] , V_41 , V_40 - V_20 -> V_29 ) ;
}
}
}
void
F_48 ( T_1 * V_1 , const T_2 V_31 , const V_11 * V_41 )
{
int V_3 ;
T_9 V_40 ;
V_5 * V_20 ;
F_49 ( V_41 ) ;
if ( ! F_17 ( V_1 , V_31 ) )
return;
if ( V_31 == V_42 )
V_40 = V_43 ;
else
V_40 = V_36 ;
for ( V_3 = V_1 -> V_6 [ V_31 ] ; V_3 <= V_1 -> V_8 [ V_31 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_31 ] ) {
if ( V_20 -> V_29 != 0 ) {
F_31 ( V_20 , V_40 ) ;
F_32 ( & V_20 -> V_25 [ V_20 -> V_29 ] , V_41 , V_40 - V_20 -> V_29 ) ;
} else {
V_20 -> V_28 = V_41 ;
}
}
}
}
void
F_50 ( T_1 * V_1 , const T_2 V_31 , const V_11 * V_37 , ... )
{
T_8 V_38 ;
int V_3 ;
T_14 V_39 ;
T_14 V_40 ;
const V_11 * V_41 ;
V_5 * V_20 ;
if ( ! F_17 ( V_1 , V_31 ) )
return;
if ( V_31 == V_42 )
V_40 = V_43 ;
else
V_40 = V_36 ;
for ( V_3 = V_1 -> V_6 [ V_31 ] ; V_3 <= V_1 -> V_8 [ V_31 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_31 ] ) {
V_39 = V_20 -> V_29 ;
if ( V_39 != 0 ) {
F_31 ( V_20 , V_40 ) ;
} else {
V_20 -> V_28 = V_20 -> V_25 ;
}
va_start ( V_38 , V_37 ) ;
V_41 = V_37 ;
do {
if G_UNLIKELY( V_41 == NULL )
V_41 = L_2 ;
V_39 += F_32 ( & V_20 -> V_25 [ V_39 ] , V_41 , V_40 - V_39 ) ;
} while ( V_39 < V_40 && ( V_41 = va_arg ( V_38 , const char * ) ) != V_44 );
va_end ( V_38 ) ;
}
}
}
void
F_51 ( T_1 * V_1 , const T_2 V_31 , const V_11 * V_62 , ... )
{
T_8 V_38 ;
int V_3 ;
int V_40 ;
V_5 * V_20 ;
if ( ! F_17 ( V_1 , V_31 ) )
return;
if ( V_31 == V_42 )
V_40 = V_43 ;
else
V_40 = V_36 ;
for ( V_3 = V_1 -> V_6 [ V_31 ] ; V_3 <= V_1 -> V_8 [ V_31 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_31 ] ) {
if ( V_20 -> V_29 != 0 ) {
F_31 ( V_20 , V_40 ) ;
} else {
V_20 -> V_28 = V_20 -> V_25 ;
}
va_start ( V_38 , V_62 ) ;
F_42 ( & V_20 -> V_25 [ V_20 -> V_29 ] , V_40 - V_20 -> V_29 , V_62 , V_38 ) ;
va_end ( V_38 ) ;
}
}
}
static void
F_52 ( T_1 * V_1 , const T_2 V_31 , const V_11 * V_61 ,
const V_11 * V_41 )
{
int V_3 ;
T_9 V_63 , V_40 ;
V_5 * V_20 ;
if ( V_31 == V_42 )
V_40 = V_43 ;
else
V_40 = V_36 ;
for ( V_3 = V_1 -> V_6 [ V_31 ] ; V_3 <= V_1 -> V_8 [ V_31 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_31 ] ) {
F_31 ( V_20 , V_40 ) ;
V_63 = V_20 -> V_25 [ 0 ] ;
if ( V_61 != NULL ) {
if ( V_63 != 0 ) {
F_40 ( V_20 -> V_25 , V_61 , V_40 ) ;
}
}
F_40 ( V_20 -> V_25 , V_41 , V_40 ) ;
}
}
}
void
F_53 ( T_1 * V_1 , const T_2 V_31 , const V_11 * V_41 )
{
if ( ! F_17 ( V_1 , V_31 ) )
return;
F_52 ( V_1 , V_31 , NULL , V_41 ) ;
}
void
F_54 ( T_1 * V_1 , const T_2 V_31 , const V_11 * V_61 ,
const V_11 * V_41 )
{
if ( ! F_17 ( V_1 , V_31 ) )
return;
if ( V_61 == NULL )
V_61 = L_7 ;
F_52 ( V_1 , V_31 , V_61 , V_41 ) ;
}
T_6
F_55 ( T_1 * V_1 , const T_2 V_45 )
{
V_5 * V_20 = & V_1 -> V_4 [ V_45 ] ;
return ( ( V_20 -> V_21 [ V_69 ] ) ||
( V_20 -> V_21 [ V_70 ] ) ||
( V_20 -> V_21 [ V_71 ] ) ||
( V_20 -> V_21 [ V_72 ] ) ||
( V_20 -> V_21 [ V_73 ] ) ||
( V_20 -> V_21 [ V_74 ] ) ||
( V_20 -> V_21 [ V_75 ] ) ||
( V_20 -> V_21 [ V_76 ] ) ||
( V_20 -> V_21 [ V_77 ] ) ||
( V_20 -> V_21 [ V_78 ] ) ) ;
}
static void
F_56 ( const T_15 * V_79 , V_11 * V_49 , T_6 V_80 )
{
struct V_81 * V_82 ;
T_16 V_83 ;
int V_84 ;
if ( V_79 -> V_85 . V_86 ) {
V_83 = V_79 -> V_87 . V_88 ;
if ( V_80 )
V_82 = localtime ( & V_83 ) ;
else
V_82 = gmtime ( & V_83 ) ;
} else
V_82 = NULL ;
if ( V_82 != NULL ) {
switch ( F_57 () ) {
case V_89 :
V_84 = V_90 ;
break;
case V_91 :
V_84 = V_92 ;
break;
case V_93 :
V_84 = V_94 ;
break;
case V_95 :
V_84 = V_96 ;
break;
case V_97 :
V_84 = V_98 ;
break;
case V_99 :
V_84 = V_100 ;
break;
case V_101 :
V_84 = V_79 -> V_102 ;
break;
default:
F_58 () ;
}
switch ( V_84 ) {
case V_90 :
F_37 ( V_49 , V_36 , L_8 ,
V_82 -> V_103 + 1900 ,
V_82 -> V_104 + 1 ,
V_82 -> V_105 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ) ;
break;
case V_92 :
F_37 ( V_49 , V_36 , L_9 ,
V_82 -> V_103 + 1900 ,
V_82 -> V_104 + 1 ,
V_82 -> V_105 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ,
V_79 -> V_87 . V_109 / 100000000 ) ;
break;
case V_94 :
F_37 ( V_49 , V_36 , L_10 ,
V_82 -> V_103 + 1900 ,
V_82 -> V_104 + 1 ,
V_82 -> V_105 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ,
V_79 -> V_87 . V_109 / 10000000 ) ;
break;
case V_96 :
F_37 ( V_49 , V_36 , L_11 ,
V_82 -> V_103 + 1900 ,
V_82 -> V_104 + 1 ,
V_82 -> V_105 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ,
V_79 -> V_87 . V_109 / 1000000 ) ;
break;
case V_98 :
F_37 ( V_49 , V_36 , L_12 ,
V_82 -> V_103 + 1900 ,
V_82 -> V_104 + 1 ,
V_82 -> V_105 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ,
V_79 -> V_87 . V_109 / 1000 ) ;
break;
case V_100 :
F_37 ( V_49 , V_36 , L_13 ,
V_82 -> V_103 + 1900 ,
V_82 -> V_104 + 1 ,
V_82 -> V_105 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ,
V_79 -> V_87 . V_109 ) ;
break;
default:
F_58 () ;
}
} else {
V_49 [ 0 ] = '\0' ;
}
}
static void
F_59 ( const T_15 * V_79 , T_1 * V_1 , const int V_45 )
{
F_56 ( V_79 , V_1 -> V_4 [ V_45 ] . V_25 , TRUE ) ;
V_1 -> V_10 . V_10 [ V_45 ] = L_14 ;
F_32 ( V_1 -> V_10 . V_12 [ V_45 ] , V_1 -> V_4 [ V_45 ] . V_25 , V_36 ) ;
V_1 -> V_4 [ V_45 ] . V_28 = V_1 -> V_4 [ V_45 ] . V_25 ;
}
static void
F_60 ( const T_15 * V_79 , T_1 * V_1 , const int V_45 )
{
F_56 ( V_79 , V_1 -> V_4 [ V_45 ] . V_25 , FALSE ) ;
V_1 -> V_10 . V_10 [ V_45 ] = L_14 ;
F_32 ( V_1 -> V_10 . V_12 [ V_45 ] , V_1 -> V_4 [ V_45 ] . V_25 , V_36 ) ;
V_1 -> V_4 [ V_45 ] . V_28 = V_1 -> V_4 [ V_45 ] . V_25 ;
}
static void
F_61 ( const T_15 * V_79 , V_11 * V_49 , T_6 V_80 )
{
struct V_81 * V_82 ;
T_16 V_83 ;
int V_84 ;
if ( V_79 -> V_85 . V_86 ) {
V_83 = V_79 -> V_87 . V_88 ;
if ( V_80 )
V_82 = localtime ( & V_83 ) ;
else
V_82 = gmtime ( & V_83 ) ;
} else
V_82 = NULL ;
if ( V_82 != NULL ) {
switch ( F_57 () ) {
case V_89 :
V_84 = V_90 ;
break;
case V_91 :
V_84 = V_92 ;
break;
case V_93 :
V_84 = V_94 ;
break;
case V_95 :
V_84 = V_96 ;
break;
case V_97 :
V_84 = V_98 ;
break;
case V_99 :
V_84 = V_100 ;
break;
case V_101 :
V_84 = V_79 -> V_102 ;
break;
default:
F_58 () ;
}
switch ( V_84 ) {
case V_90 :
F_37 ( V_49 , V_36 , L_15 ,
V_82 -> V_103 + 1900 ,
V_82 -> V_110 + 1 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ) ;
break;
case V_92 :
F_37 ( V_49 , V_36 , L_16 ,
V_82 -> V_103 + 1900 ,
V_82 -> V_110 + 1 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ,
V_79 -> V_87 . V_109 / 100000000 ) ;
break;
case V_94 :
F_37 ( V_49 , V_36 , L_17 ,
V_82 -> V_103 + 1900 ,
V_82 -> V_110 + 1 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ,
V_79 -> V_87 . V_109 / 10000000 ) ;
break;
case V_96 :
F_37 ( V_49 , V_36 , L_18 ,
V_82 -> V_103 + 1900 ,
V_82 -> V_110 + 1 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ,
V_79 -> V_87 . V_109 / 1000000 ) ;
break;
case V_98 :
F_37 ( V_49 , V_36 , L_19 ,
V_82 -> V_103 + 1900 ,
V_82 -> V_110 + 1 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ,
V_79 -> V_87 . V_109 / 1000 ) ;
break;
case V_100 :
F_37 ( V_49 , V_36 , L_20 ,
V_82 -> V_103 + 1900 ,
V_82 -> V_110 + 1 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ,
V_79 -> V_87 . V_109 ) ;
break;
default:
F_58 () ;
}
} else {
V_49 [ 0 ] = '\0' ;
}
}
static void
F_62 ( const T_15 * V_79 , T_1 * V_1 , const int V_45 )
{
F_61 ( V_79 , V_1 -> V_4 [ V_45 ] . V_25 , TRUE ) ;
V_1 -> V_10 . V_10 [ V_45 ] = L_14 ;
F_32 ( V_1 -> V_10 . V_12 [ V_45 ] , V_1 -> V_4 [ V_45 ] . V_25 , V_36 ) ;
V_1 -> V_4 [ V_45 ] . V_28 = V_1 -> V_4 [ V_45 ] . V_25 ;
}
static void
F_63 ( const T_15 * V_79 , T_1 * V_1 , const int V_45 )
{
F_61 ( V_79 , V_1 -> V_4 [ V_45 ] . V_25 , FALSE ) ;
V_1 -> V_10 . V_10 [ V_45 ] = L_14 ;
F_32 ( V_1 -> V_10 . V_12 [ V_45 ] , V_1 -> V_4 [ V_45 ] . V_25 , V_36 ) ;
V_1 -> V_4 [ V_45 ] . V_28 = V_1 -> V_4 [ V_45 ] . V_25 ;
}
static void
F_64 ( const T_15 * V_79 , const T_17 * V_111 , V_11 * V_49 )
{
int V_84 ;
switch ( F_57 () ) {
case V_89 :
V_84 = V_90 ;
break;
case V_91 :
V_84 = V_92 ;
break;
case V_93 :
V_84 = V_94 ;
break;
case V_95 :
V_84 = V_96 ;
break;
case V_97 :
V_84 = V_98 ;
break;
case V_99 :
V_84 = V_100 ;
break;
case V_101 :
V_84 = V_79 -> V_102 ;
break;
default:
F_58 () ;
}
switch ( V_84 ) {
case V_90 :
F_65 ( V_49 , V_36 ,
( V_112 ) V_111 -> V_88 , V_111 -> V_109 / 1000000000 , V_113 ) ;
break;
case V_92 :
F_65 ( V_49 , V_36 ,
( V_112 ) V_111 -> V_88 , V_111 -> V_109 / 100000000 , V_114 ) ;
break;
case V_94 :
F_65 ( V_49 , V_36 ,
( V_112 ) V_111 -> V_88 , V_111 -> V_109 / 10000000 , V_115 ) ;
break;
case V_96 :
F_65 ( V_49 , V_36 ,
( V_112 ) V_111 -> V_88 , V_111 -> V_109 / 1000000 , V_116 ) ;
break;
case V_98 :
F_65 ( V_49 , V_36 ,
( V_112 ) V_111 -> V_88 , V_111 -> V_109 / 1000 , V_117 ) ;
break;
case V_100 :
F_65 ( V_49 , V_36 ,
( V_112 ) V_111 -> V_88 , V_111 -> V_109 , V_118 ) ;
break;
default:
F_58 () ;
}
}
static void
F_66 ( const T_15 * V_79 , const T_17 * V_111 , V_11 * V_49 )
{
T_16 V_88 = V_111 -> V_88 ;
long V_109 = ( long ) V_111 -> V_109 ;
T_6 V_119 = FALSE ;
int V_84 ;
if ( V_88 < 0 ) {
V_88 = - V_88 ;
V_119 = TRUE ;
}
if ( V_109 < 0 ) {
V_109 = - V_109 ;
V_119 = TRUE ;
}
switch ( F_57 () ) {
case V_89 :
V_84 = V_90 ;
break;
case V_91 :
V_84 = V_92 ;
break;
case V_93 :
V_84 = V_94 ;
break;
case V_95 :
V_84 = V_96 ;
break;
case V_97 :
V_84 = V_98 ;
break;
case V_99 :
V_84 = V_100 ;
break;
case V_101 :
V_84 = V_79 -> V_102 ;
break;
default:
F_58 () ;
}
switch ( V_84 ) {
case V_90 :
if ( V_88 >= ( 60 * 60 ) ) {
F_37 ( V_49 , V_36 , L_21 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 / ( 60 * 60 ) ,
( V_112 ) ( V_88 / 60 ) % 60 ,
( V_112 ) V_88 % 60 ) ;
} else if ( V_88 >= 60 ) {
F_37 ( V_49 , V_36 , L_23 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 / 60 ,
( V_112 ) V_88 % 60 ) ;
} else {
F_37 ( V_49 , V_36 , L_24 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 ) ;
}
break;
case V_92 :
if ( V_88 >= ( 60 * 60 ) ) {
F_37 ( V_49 , V_36 , L_25 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 / ( 60 * 60 ) ,
( V_112 ) ( V_88 / 60 ) % 60 ,
( V_112 ) V_88 % 60 ,
V_109 / 100000000 ) ;
} else if ( V_88 >= 60 ) {
F_37 ( V_49 , V_36 , L_26 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 / 60 ,
( V_112 ) V_88 % 60 ,
V_109 / 100000000 ) ;
} else {
F_37 ( V_49 , V_36 , L_27 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 ,
V_109 / 100000000 ) ;
}
break;
case V_94 :
if ( V_88 >= ( 60 * 60 ) ) {
F_37 ( V_49 , V_36 , L_28 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 / ( 60 * 60 ) ,
( V_112 ) ( V_88 / 60 ) % 60 ,
( V_112 ) V_88 % 60 ,
V_109 / 10000000 ) ;
} else if ( V_88 >= 60 ) {
F_37 ( V_49 , V_36 , L_29 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 / 60 ,
( V_112 ) V_88 % 60 ,
V_109 / 10000000 ) ;
} else {
F_37 ( V_49 , V_36 , L_30 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 ,
V_109 / 10000000 ) ;
}
break;
case V_96 :
if ( V_88 >= ( 60 * 60 ) ) {
F_37 ( V_49 , V_36 , L_31 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 / ( 60 * 60 ) ,
( V_112 ) ( V_88 / 60 ) % 60 ,
( V_112 ) V_88 % 60 ,
V_109 / 1000000 ) ;
} else if ( V_88 >= 60 ) {
F_37 ( V_49 , V_36 , L_32 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 / 60 ,
( V_112 ) V_88 % 60 ,
V_109 / 1000000 ) ;
} else {
F_37 ( V_49 , V_36 , L_33 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 ,
V_109 / 1000000 ) ;
}
break;
case V_98 :
if ( V_88 >= ( 60 * 60 ) ) {
F_37 ( V_49 , V_36 , L_34 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 / ( 60 * 60 ) ,
( V_112 ) ( V_88 / 60 ) % 60 ,
( V_112 ) V_88 % 60 ,
V_109 / 1000 ) ;
} else if ( V_88 >= 60 ) {
F_37 ( V_49 , V_36 , L_35 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 / 60 ,
( V_112 ) V_88 % 60 ,
V_109 / 1000 ) ;
} else {
F_37 ( V_49 , V_36 , L_36 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 ,
V_109 / 1000 ) ;
}
break;
case V_100 :
if ( V_88 >= ( 60 * 60 ) ) {
F_37 ( V_49 , V_36 , L_37 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 / ( 60 * 60 ) ,
( V_112 ) ( V_88 / 60 ) % 60 ,
( V_112 ) V_88 % 60 ,
V_109 ) ;
} else if ( V_88 >= 60 ) {
F_37 ( V_49 , V_36 , L_38 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 / 60 ,
( V_112 ) V_88 % 60 ,
V_109 ) ;
} else {
F_37 ( V_49 , V_36 , L_39 ,
V_119 ? L_22 : L_1 ,
( V_112 ) V_88 ,
V_109 ) ;
}
break;
default:
F_58 () ;
}
}
static void
F_67 ( const T_15 * V_79 , T_1 * V_1 , const int V_45 )
{
T_17 V_120 ;
if ( ! V_79 -> V_85 . V_86 ) {
V_1 -> V_4 [ V_45 ] . V_25 [ 0 ] = '\0' ;
return;
}
F_68 ( V_1 -> V_27 , V_79 , V_79 -> V_121 , & V_120 ) ;
switch ( F_69 () ) {
case V_122 :
F_64 ( V_79 , & V_120 , V_1 -> V_4 [ V_45 ] . V_25 ) ;
V_1 -> V_10 . V_10 [ V_45 ] = L_40 ;
F_32 ( V_1 -> V_10 . V_12 [ V_45 ] , V_1 -> V_4 [ V_45 ] . V_25 , V_36 ) ;
break;
case V_123 :
F_66 ( V_79 , & V_120 , V_1 -> V_4 [ V_45 ] . V_25 ) ;
V_1 -> V_10 . V_10 [ V_45 ] = L_40 ;
F_64 ( V_79 , & V_120 , V_1 -> V_10 . V_12 [ V_45 ] ) ;
break;
default:
F_58 () ;
}
V_1 -> V_4 [ V_45 ] . V_28 = V_1 -> V_4 [ V_45 ] . V_25 ;
}
static void
F_70 ( const T_15 * V_79 , T_1 * V_1 , const int V_45 )
{
T_17 V_124 ;
F_68 ( V_1 -> V_27 , V_79 , V_79 -> V_125 - 1 , & V_124 ) ;
switch ( F_69 () ) {
case V_122 :
F_64 ( V_79 , & V_124 , V_1 -> V_4 [ V_45 ] . V_25 ) ;
V_1 -> V_10 . V_10 [ V_45 ] = L_41 ;
F_32 ( V_1 -> V_10 . V_12 [ V_45 ] , V_1 -> V_4 [ V_45 ] . V_25 , V_36 ) ;
break;
case V_123 :
F_66 ( V_79 , & V_124 , V_1 -> V_4 [ V_45 ] . V_25 ) ;
V_1 -> V_10 . V_10 [ V_45 ] = L_41 ;
F_64 ( V_79 , & V_124 , V_1 -> V_10 . V_12 [ V_45 ] ) ;
break;
default:
F_58 () ;
}
V_1 -> V_4 [ V_45 ] . V_28 = V_1 -> V_4 [ V_45 ] . V_25 ;
}
static void
F_71 ( const T_15 * V_79 , T_1 * V_1 , const int V_45 )
{
T_17 V_126 ;
if ( ! V_79 -> V_85 . V_86 ) {
V_1 -> V_4 [ V_45 ] . V_25 [ 0 ] = '\0' ;
return;
}
F_68 ( V_1 -> V_27 , V_79 , V_79 -> V_127 , & V_126 ) ;
switch ( F_69 () ) {
case V_122 :
F_64 ( V_79 , & V_126 , V_1 -> V_4 [ V_45 ] . V_25 ) ;
V_1 -> V_10 . V_10 [ V_45 ] = L_42 ;
F_32 ( V_1 -> V_10 . V_12 [ V_45 ] , V_1 -> V_4 [ V_45 ] . V_25 , V_36 ) ;
break;
case V_123 :
F_66 ( V_79 , & V_126 , V_1 -> V_4 [ V_45 ] . V_25 ) ;
V_1 -> V_10 . V_10 [ V_45 ] = L_42 ;
F_64 ( V_79 , & V_126 , V_1 -> V_10 . V_12 [ V_45 ] ) ;
break;
default:
F_58 () ;
}
V_1 -> V_4 [ V_45 ] . V_28 = V_1 -> V_4 [ V_45 ] . V_25 ;
}
static void
F_72 ( const T_15 * V_79 , V_11 * V_49 , T_6 V_80 )
{
struct V_81 * V_82 ;
T_16 V_83 ;
int V_84 ;
if ( V_79 -> V_85 . V_86 ) {
V_83 = V_79 -> V_87 . V_88 ;
if ( V_80 )
V_82 = localtime ( & V_83 ) ;
else
V_82 = gmtime ( & V_83 ) ;
} else
V_82 = NULL ;
if ( V_82 != NULL ) {
switch ( F_57 () ) {
case V_89 :
V_84 = V_90 ;
break;
case V_91 :
V_84 = V_92 ;
break;
case V_93 :
V_84 = V_94 ;
break;
case V_95 :
V_84 = V_96 ;
break;
case V_97 :
V_84 = V_98 ;
break;
case V_99 :
V_84 = V_100 ;
break;
case V_101 :
V_84 = V_79 -> V_102 ;
break;
default:
F_58 () ;
}
switch ( V_84 ) {
case V_90 :
F_37 ( V_49 , V_36 , L_43 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ) ;
break;
case V_92 :
F_37 ( V_49 , V_36 , L_44 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ,
V_79 -> V_87 . V_109 / 100000000 ) ;
break;
case V_94 :
F_37 ( V_49 , V_36 , L_45 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ,
V_79 -> V_87 . V_109 / 10000000 ) ;
break;
case V_96 :
F_37 ( V_49 , V_36 , L_46 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ,
V_79 -> V_87 . V_109 / 1000000 ) ;
break;
case V_98 :
F_37 ( V_49 , V_36 , L_47 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ,
V_79 -> V_87 . V_109 / 1000 ) ;
break;
case V_100 :
F_37 ( V_49 , V_36 , L_48 ,
V_82 -> V_106 ,
V_82 -> V_107 ,
V_82 -> V_108 ,
V_79 -> V_87 . V_109 ) ;
break;
default:
F_58 () ;
}
} else {
* V_49 = '\0' ;
}
}
static void
F_73 ( const T_15 * V_79 , T_1 * V_1 , const int V_45 )
{
F_72 ( V_79 , V_1 -> V_4 [ V_45 ] . V_25 , TRUE ) ;
V_1 -> V_10 . V_10 [ V_45 ] = L_14 ;
F_32 ( V_1 -> V_10 . V_12 [ V_45 ] , V_1 -> V_4 [ V_45 ] . V_25 , V_36 ) ;
V_1 -> V_4 [ V_45 ] . V_28 = V_1 -> V_4 [ V_45 ] . V_25 ;
}
static void
F_74 ( const T_15 * V_79 , T_1 * V_1 , const int V_45 )
{
F_72 ( V_79 , V_1 -> V_4 [ V_45 ] . V_25 , FALSE ) ;
V_1 -> V_10 . V_10 [ V_45 ] = L_14 ;
F_32 ( V_1 -> V_10 . V_12 [ V_45 ] , V_1 -> V_4 [ V_45 ] . V_25 , V_36 ) ;
V_1 -> V_4 [ V_45 ] . V_28 = V_1 -> V_4 [ V_45 ] . V_25 ;
}
static T_6
F_75 ( const T_15 * V_79 , V_11 * V_49 )
{
int V_84 ;
if ( ! V_79 -> V_85 . V_86 ) {
V_49 [ 0 ] = '\0' ;
return FALSE ;
}
switch ( F_57 () ) {
case V_89 :
V_84 = V_90 ;
break;
case V_91 :
V_84 = V_92 ;
break;
case V_93 :
V_84 = V_94 ;
break;
case V_95 :
V_84 = V_96 ;
break;
case V_97 :
V_84 = V_98 ;
break;
case V_99 :
V_84 = V_100 ;
break;
case V_101 :
V_84 = V_79 -> V_102 ;
break;
default:
F_58 () ;
}
switch ( V_84 ) {
case V_90 :
F_76 ( V_49 , V_36 ,
V_79 -> V_87 . V_88 , V_79 -> V_87 . V_109 / 1000000000 , V_113 ) ;
break;
case V_92 :
F_76 ( V_49 , V_36 ,
V_79 -> V_87 . V_88 , V_79 -> V_87 . V_109 / 100000000 , V_114 ) ;
break;
case V_94 :
F_76 ( V_49 , V_36 ,
V_79 -> V_87 . V_88 , V_79 -> V_87 . V_109 / 10000000 , V_115 ) ;
break;
case V_96 :
F_76 ( V_49 , V_36 ,
V_79 -> V_87 . V_88 , V_79 -> V_87 . V_109 / 1000000 , V_116 ) ;
break;
case V_98 :
F_76 ( V_49 , V_36 ,
V_79 -> V_87 . V_88 , V_79 -> V_87 . V_109 / 1000 , V_117 ) ;
break;
case V_100 :
F_76 ( V_49 , V_36 ,
V_79 -> V_87 . V_88 , V_79 -> V_87 . V_109 , V_118 ) ;
break;
default:
F_58 () ;
}
return TRUE ;
}
static void
F_77 ( const T_15 * V_79 , T_1 * V_1 , const int V_45 )
{
if ( F_75 ( V_79 , V_1 -> V_4 [ V_45 ] . V_25 ) ) {
V_1 -> V_10 . V_10 [ V_45 ] = L_41 ;
F_32 ( V_1 -> V_10 . V_12 [ V_45 ] , V_1 -> V_4 [ V_45 ] . V_25 , V_36 ) ;
}
V_1 -> V_4 [ V_45 ] . V_28 = V_1 -> V_4 [ V_45 ] . V_25 ;
}
void
F_78 ( const T_18 * V_27 , T_15 * V_79 , V_11 * V_49 )
{
switch ( F_79 () ) {
case V_128 :
F_72 ( V_79 , V_49 , TRUE ) ;
break;
case V_129 :
F_56 ( V_79 , V_49 , TRUE ) ;
break;
case V_130 :
F_61 ( V_79 , V_49 , TRUE ) ;
break;
case V_131 :
if ( V_79 -> V_85 . V_86 ) {
T_17 V_120 ;
F_68 ( V_27 , V_79 , V_79 -> V_121 , & V_120 ) ;
switch ( F_69 () ) {
case V_122 :
F_64 ( V_79 , & V_120 , V_49 ) ;
break;
case V_123 :
F_64 ( V_79 , & V_120 , V_49 ) ;
break;
default:
F_58 () ;
}
} else {
V_49 [ 0 ] = '\0' ;
}
break;
case V_132 :
if ( V_79 -> V_85 . V_86 ) {
T_17 V_124 ;
F_68 ( V_27 , V_79 , V_79 -> V_125 - 1 , & V_124 ) ;
switch ( F_69 () ) {
case V_122 :
F_64 ( V_79 , & V_124 , V_49 ) ;
break;
case V_123 :
F_66 ( V_79 , & V_124 , V_49 ) ;
break;
default:
F_58 () ;
}
} else {
V_49 [ 0 ] = '\0' ;
}
break;
case V_133 :
if ( V_79 -> V_85 . V_86 ) {
T_17 V_126 ;
F_68 ( V_27 , V_79 , V_79 -> V_127 , & V_126 ) ;
switch ( F_69 () ) {
case V_122 :
F_64 ( V_79 , & V_126 , V_49 ) ;
break;
case V_123 :
F_66 ( V_79 , & V_126 , V_49 ) ;
break;
default:
F_58 () ;
}
} else {
V_49 [ 0 ] = '\0' ;
}
break;
case V_134 :
F_75 ( V_79 , V_49 ) ;
break;
case V_135 :
F_72 ( V_79 , V_49 , FALSE ) ;
break;
case V_136 :
F_56 ( V_79 , V_49 , FALSE ) ;
break;
case V_137 :
F_61 ( V_79 , V_49 , FALSE ) ;
break;
case V_138 :
F_80 ( FALSE ) ;
break;
}
}
static void
F_81 ( const T_15 * V_79 , T_1 * V_1 , const T_2 V_45 )
{
switch ( F_79 () ) {
case V_128 :
F_73 ( V_79 , V_1 , V_45 ) ;
break;
case V_129 :
F_59 ( V_79 , V_1 , V_45 ) ;
break;
case V_130 :
F_62 ( V_79 , V_1 , V_45 ) ;
break;
case V_131 :
F_67 ( V_79 , V_1 , V_45 ) ;
break;
case V_132 :
F_70 ( V_79 , V_1 , V_45 ) ;
break;
case V_133 :
F_71 ( V_79 , V_1 , V_45 ) ;
break;
case V_134 :
F_77 ( V_79 , V_1 , V_45 ) ;
break;
case V_135 :
F_74 ( V_79 , V_1 , V_45 ) ;
break;
case V_136 :
F_60 ( V_79 , V_1 , V_45 ) ;
break;
case V_137 :
F_63 ( V_79 , V_1 , V_45 ) ;
break;
case V_138 :
F_58 () ;
break;
}
}
static void
F_82 ( const T_15 * V_79 , T_1 * V_1 , const T_2 V_139 , const T_2 V_45 )
{
F_83 ( V_79 , V_1 -> V_4 [ V_45 ] . V_25 ) ;
switch ( V_139 ) {
case V_69 :
F_81 ( V_79 , V_1 , V_45 ) ;
break;
case V_70 :
F_73 ( V_79 , V_1 , V_45 ) ;
break;
case V_71 :
F_59 ( V_79 , V_1 , V_45 ) ;
break;
case V_72 :
F_62 ( V_79 , V_1 , V_45 ) ;
break;
case V_76 :
F_67 ( V_79 , V_1 , V_45 ) ;
break;
case V_77 :
F_70 ( V_79 , V_1 , V_45 ) ;
break;
case V_78 :
F_71 ( V_79 , V_1 , V_45 ) ;
break;
case V_73 :
F_74 ( V_79 , V_1 , V_45 ) ;
break;
case V_74 :
F_60 ( V_79 , V_1 , V_45 ) ;
break;
case V_75 :
F_63 ( V_79 , V_1 , V_45 ) ;
break;
default:
F_58 () ;
break;
}
}
void
F_84 ( T_1 * V_1 , const T_2 V_31 , const T_17 * V_111 , const char * V_140 )
{
int V_45 ;
V_5 * V_20 ;
if ( ! F_17 ( V_1 , V_31 ) )
return;
for ( V_45 = V_1 -> V_6 [ V_31 ] ; V_45 <= V_1 -> V_8 [ V_31 ] ; V_45 ++ ) {
V_20 = & V_1 -> V_4 [ V_45 ] ;
if ( V_20 -> V_21 [ V_31 ] ) {
switch ( F_57 () ) {
case V_89 :
F_65 ( V_20 -> V_25 , V_36 ,
( V_112 ) V_111 -> V_88 , V_111 -> V_109 / 1000000000 , V_113 ) ;
break;
case V_91 :
F_65 ( V_20 -> V_25 , V_36 ,
( V_112 ) V_111 -> V_88 , V_111 -> V_109 / 100000000 , V_114 ) ;
break;
case V_93 :
F_65 ( V_20 -> V_25 , V_36 ,
( V_112 ) V_111 -> V_88 , V_111 -> V_109 / 10000000 , V_115 ) ;
break;
case V_95 :
F_65 ( V_20 -> V_25 , V_36 ,
( V_112 ) V_111 -> V_88 , V_111 -> V_109 / 1000000 , V_116 ) ;
break;
case V_97 :
F_65 ( V_20 -> V_25 , V_36 ,
( V_112 ) V_111 -> V_88 , V_111 -> V_109 / 1000 , V_117 ) ;
break;
case V_99 :
case V_101 :
F_65 ( V_20 -> V_25 , V_36 ,
( V_112 ) V_111 -> V_88 , V_111 -> V_109 , V_118 ) ;
break;
default:
F_58 () ;
}
V_20 -> V_28 = V_20 -> V_25 ;
V_1 -> V_10 . V_10 [ V_45 ] = V_140 ;
F_32 ( V_1 -> V_10 . V_12 [ V_45 ] , V_20 -> V_25 , V_36 ) ;
}
}
}
static void
F_85 ( T_19 * V_141 , const int V_45 , const T_20 * V_142 , const T_6 V_143 ,
const T_6 V_144 , const T_6 V_145 )
{
const char * V_146 ;
V_5 * V_20 = & V_141 -> V_1 -> V_4 [ V_45 ] ;
if ( V_142 -> type == V_147 ) {
return;
}
if ( V_145 && ( V_146 = F_86 ( V_142 ) ) != NULL )
V_20 -> V_28 = V_146 ;
else {
V_20 -> V_28 = V_20 -> V_25 ;
F_87 ( V_142 , V_20 -> V_25 , V_36 ) ;
}
if ( ! V_144 )
return;
V_141 -> V_1 -> V_10 . V_10 [ V_45 ] = F_88 ( V_142 , V_143 ) ;
if ( strlen ( V_141 -> V_1 -> V_10 . V_10 [ V_45 ] ) > 0 )
F_87 ( V_142 , V_141 -> V_1 -> V_10 . V_12 [ V_45 ] , V_36 ) ;
}
static void
F_89 ( T_19 * V_141 , const int V_45 , const T_6 V_148 , const T_6 V_143 , const T_6 V_144 V_18 )
{
T_10 V_149 ;
V_5 * V_20 = & V_141 -> V_1 -> V_4 [ V_45 ] ;
if ( V_143 )
V_149 = V_141 -> V_150 ;
else
V_149 = V_141 -> V_151 ;
switch ( V_141 -> V_152 ) {
case V_153 :
if ( V_148 )
F_32 ( V_20 -> V_25 , F_90 ( V_141 -> V_154 , V_149 ) , V_36 ) ;
else
F_34 ( V_149 , V_20 -> V_25 , V_36 ) ;
break;
case V_155 :
F_34 ( V_149 , V_141 -> V_1 -> V_10 . V_12 [ V_45 ] , V_36 ) ;
if ( V_148 )
F_32 ( V_20 -> V_25 , F_91 ( V_141 -> V_154 , V_149 ) , V_36 ) ;
else
F_32 ( V_20 -> V_25 , V_141 -> V_1 -> V_10 . V_12 [ V_45 ] , V_36 ) ;
if ( V_143 )
V_141 -> V_1 -> V_10 . V_10 [ V_45 ] = L_49 ;
else
V_141 -> V_1 -> V_10 . V_10 [ V_45 ] = L_50 ;
break;
case V_156 :
F_34 ( V_149 , V_141 -> V_1 -> V_10 . V_12 [ V_45 ] , V_36 ) ;
if ( V_148 )
F_32 ( V_20 -> V_25 , F_92 ( V_141 -> V_154 , V_149 ) , V_36 ) ;
else
F_32 ( V_20 -> V_25 , V_141 -> V_1 -> V_10 . V_12 [ V_45 ] , V_36 ) ;
if ( V_143 )
V_141 -> V_1 -> V_10 . V_10 [ V_45 ] = L_51 ;
else
V_141 -> V_1 -> V_10 . V_10 [ V_45 ] = L_52 ;
break;
case V_157 :
if ( V_143 )
V_141 -> V_1 -> V_10 . V_10 [ V_45 ] = L_53 ;
else
V_141 -> V_1 -> V_10 . V_10 [ V_45 ] = L_54 ;
F_34 ( V_149 , V_141 -> V_1 -> V_10 . V_12 [ V_45 ] , V_36 ) ;
F_32 ( V_20 -> V_25 , V_141 -> V_1 -> V_10 . V_12 [ V_45 ] , V_36 ) ;
break;
case V_158 :
F_37 ( V_20 -> V_25 , V_36 , L_55 , V_149 ) ;
F_32 ( V_141 -> V_1 -> V_10 . V_12 [ V_45 ] , V_20 -> V_25 , V_36 ) ;
if ( V_143 )
V_141 -> V_1 -> V_10 . V_10 [ V_45 ] = L_56 ;
else
V_141 -> V_1 -> V_10 . V_10 [ V_45 ] = L_57 ;
break;
case V_159 :
F_37 ( V_20 -> V_25 , V_36 , L_55 , V_149 ) ;
F_32 ( V_141 -> V_1 -> V_10 . V_12 [ V_45 ] , V_20 -> V_25 , V_36 ) ;
if ( V_143 )
V_141 -> V_1 -> V_10 . V_10 [ V_45 ] = L_58 ;
else
V_141 -> V_1 -> V_10 . V_10 [ V_45 ] = L_59 ;
break;
case V_160 :
F_37 ( V_20 -> V_25 , V_36 , L_60 , V_149 ) ;
F_32 ( V_141 -> V_1 -> V_10 . V_12 [ V_45 ] , V_20 -> V_25 , V_36 ) ;
if ( V_143 )
V_141 -> V_1 -> V_10 . V_10 [ V_45 ] = L_61 ;
else
V_141 -> V_1 -> V_10 . V_10 [ V_45 ] = L_62 ;
break;
default:
break;
}
V_20 -> V_28 = V_20 -> V_25 ;
}
T_6
F_93 ( T_1 * V_1 , const T_2 V_45 )
{
F_80 ( V_1 ) ;
F_80 ( V_45 < V_1 -> V_2 ) ;
switch ( V_1 -> V_4 [ V_45 ] . V_161 ) {
case V_162 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_163 :
case V_164 :
return TRUE ;
default:
return FALSE ;
}
}
void
F_94 ( const T_15 * V_79 , T_1 * V_1 , const T_2 V_45 , const T_6 V_144 )
{
V_5 * V_20 = & V_1 -> V_4 [ V_45 ] ;
switch ( V_20 -> V_161 ) {
case V_162 :
F_34 ( V_79 -> V_125 , V_20 -> V_25 , V_36 ) ;
V_20 -> V_28 = V_20 -> V_25 ;
break;
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
F_82 ( V_79 , V_1 , V_20 -> V_161 , V_45 ) ;
break;
case V_163 :
F_34 ( V_79 -> V_165 , V_20 -> V_25 , V_36 ) ;
V_20 -> V_28 = V_20 -> V_25 ;
break;
case V_164 :
F_34 ( V_79 -> V_166 , V_20 -> V_25 , V_36 ) ;
V_20 -> V_28 = V_20 -> V_25 ;
break;
default:
break;
}
if ( ! V_144 )
return;
switch ( V_20 -> V_161 ) {
case V_162 :
V_1 -> V_10 . V_10 [ V_45 ] = L_63 ;
F_32 ( V_1 -> V_10 . V_12 [ V_45 ] , V_20 -> V_25 , V_36 ) ;
break;
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
break;
case V_163 :
V_1 -> V_10 . V_10 [ V_45 ] = L_64 ;
F_32 ( V_1 -> V_10 . V_12 [ V_45 ] , V_20 -> V_25 , V_36 ) ;
break;
case V_164 :
break;
default:
break;
}
}
void
F_95 ( T_19 * V_141 , const T_6 V_144 , const T_6 V_167 )
{
int V_3 ;
V_5 * V_20 ;
if ( ! V_141 -> V_1 )
return;
for ( V_3 = 0 ; V_3 < V_141 -> V_1 -> V_2 ; V_3 ++ ) {
V_20 = & V_141 -> V_1 -> V_4 [ V_3 ] ;
if ( F_93 ( V_141 -> V_1 , V_3 ) ) {
if ( V_167 )
F_94 ( V_141 -> V_79 , V_141 -> V_1 , V_3 , V_144 ) ;
} else {
switch ( V_20 -> V_161 ) {
case V_168 :
case V_169 :
F_85 ( V_141 , V_3 , & V_141 -> V_56 , TRUE , V_144 , TRUE ) ;
break;
case V_170 :
F_85 ( V_141 , V_3 , & V_141 -> V_56 , TRUE , V_144 , FALSE ) ;
break;
case V_171 :
case V_172 :
F_85 ( V_141 , V_3 , & V_141 -> V_173 , TRUE , V_144 , TRUE ) ;
break;
case V_174 :
F_85 ( V_141 , V_3 , & V_141 -> V_173 , TRUE , V_144 , FALSE ) ;
break;
case V_175 :
case V_176 :
F_85 ( V_141 , V_3 , & V_141 -> V_177 , TRUE , V_144 , TRUE ) ;
break;
case V_178 :
F_85 ( V_141 , V_3 , & V_141 -> V_177 , TRUE , V_144 , FALSE ) ;
break;
case V_179 :
case V_180 :
F_85 ( V_141 , V_3 , & V_141 -> V_57 , FALSE , V_144 , TRUE ) ;
break;
case V_181 :
F_85 ( V_141 , V_3 , & V_141 -> V_57 , FALSE , V_144 , FALSE ) ;
break;
case V_182 :
case V_183 :
F_85 ( V_141 , V_3 , & V_141 -> V_184 , FALSE , V_144 , TRUE ) ;
break;
case V_185 :
F_85 ( V_141 , V_3 , & V_141 -> V_184 , FALSE , V_144 , FALSE ) ;
break;
case V_186 :
case V_187 :
F_85 ( V_141 , V_3 , & V_141 -> V_188 , FALSE , V_144 , TRUE ) ;
break;
case V_189 :
F_85 ( V_141 , V_3 , & V_141 -> V_188 , FALSE , V_144 , FALSE ) ;
break;
case V_190 :
case V_191 :
F_89 ( V_141 , V_3 , TRUE , TRUE , V_144 ) ;
break;
case V_192 :
F_89 ( V_141 , V_3 , FALSE , TRUE , V_144 ) ;
break;
case V_193 :
case V_194 :
F_89 ( V_141 , V_3 , TRUE , FALSE , V_144 ) ;
break;
case V_195 :
F_89 ( V_141 , V_3 , FALSE , FALSE , V_144 ) ;
break;
case V_7 :
F_58 () ;
break;
default:
if ( V_20 -> V_161 >= V_7 ) {
F_58 () ;
}
break;
}
}
}
}
void
F_96 ( T_1 * V_1 , T_15 * V_196 , const T_6 V_144 , const T_6 V_167 )
{
int V_3 ;
V_5 * V_20 ;
if ( ! V_1 )
return;
for ( V_3 = 0 ; V_3 < V_1 -> V_2 ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( F_93 ( V_1 , V_3 ) ) {
if ( V_167 )
F_94 ( V_196 , V_1 , V_3 , V_144 ) ;
} else if ( V_20 -> V_161 == V_42 ) {
V_20 -> V_28 = L_65 ;
} else {
if ( V_20 -> V_161 >= V_7 ) {
F_58 () ;
}
V_20 -> V_28 = L_66 ;
break;
}
}
}
