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
V_20 -> V_30 = TRUE ;
V_1 -> V_10 . V_10 [ V_3 ] = L_1 ;
V_1 -> V_10 . V_12 [ V_3 ] [ 0 ] = '\0' ;
}
V_1 -> V_30 = TRUE ;
V_1 -> V_27 = V_27 ;
}
T_6
F_13 ( T_1 * V_1 , const T_2 V_31 )
{
int V_3 ;
V_5 * V_20 ;
if ( V_1 == NULL )
return FALSE ;
if ( ( V_31 == - 1 ) || ( V_1 -> V_30 == FALSE ) )
return V_1 -> V_30 ;
if ( V_1 -> V_6 [ V_31 ] >= 0 ) {
for ( V_3 = V_1 -> V_6 [ V_31 ] ; V_3 <= V_1 -> V_8 [ V_31 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_31 ] ) {
return V_20 -> V_30 ;
}
}
}
return FALSE ;
}
void
F_14 ( T_1 * V_1 , const T_2 V_31 , const T_6 V_30 )
{
int V_3 ;
V_5 * V_20 ;
if ( V_1 ) {
if ( V_31 == - 1 ) {
V_1 -> V_30 = V_30 ;
} else if ( V_1 -> V_6 [ V_31 ] >= 0 ) {
for ( V_3 = V_1 -> V_6 [ V_31 ] ; V_3 <= V_1 -> V_8 [ V_31 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_31 ] ) {
V_20 -> V_30 = V_30 ;
}
}
}
}
}
void
F_15 ( T_1 * V_1 , const T_2 V_32 )
{
int V_3 ;
V_5 * V_20 ;
if ( ! F_16 ( V_1 , V_32 ) )
return;
for ( V_3 = V_1 -> V_6 [ V_32 ] ; V_3 <= V_1 -> V_8 [ V_32 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_32 ] ) {
V_20 -> V_29 = ( int ) strlen ( V_20 -> V_28 ) ;
}
}
}
void
F_17 ( T_1 * V_1 , const T_2 V_32 )
{
int V_3 ;
V_5 * V_20 ;
if ( ! F_16 ( V_1 , V_32 ) )
return;
for ( V_3 = V_1 -> V_6 [ V_32 ] ; V_3 <= V_1 -> V_8 [ V_32 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_32 ] ) {
V_20 -> V_29 = 0 ;
}
}
}
const V_11 *
F_18 ( T_1 * V_1 , const T_2 V_32 )
{
int V_3 ;
const V_11 * V_33 = NULL ;
V_5 * V_20 ;
if ( ! ( V_1 && ( V_1 ) -> V_6 [ V_32 ] >= 0 ) ) {
return NULL ;
}
for ( V_3 = V_1 -> V_6 [ V_32 ] ; V_3 <= V_1 -> V_8 [ V_32 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_32 ] ) {
V_33 = ( V_20 -> V_28 ) ;
}
}
return V_33 ;
}
void
F_19 ( T_1 * V_1 , const T_2 V_32 )
{
int V_3 ;
V_5 * V_20 ;
if ( ! F_16 ( V_1 , V_32 ) )
return;
for ( V_3 = V_1 -> V_6 [ V_32 ] ; V_3 <= V_1 -> V_8 [ V_32 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_32 ] ) {
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
F_20 ( T_1 * V_1 )
{
return F_21 ( V_1 ) ;
}
T_6
F_22 ( void )
{
#ifdef F_23
return F_24 () ;
#else
return FALSE ;
#endif
}
void F_25 ( T_7 * V_34 , T_1 * V_1 )
{
int V_3 ;
V_5 * V_20 ;
if ( ! F_21 ( V_1 ) )
return;
for ( V_3 = V_1 -> V_6 [ V_35 ] ;
V_3 <= V_1 -> V_8 [ V_35 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_35 ] &&
V_20 -> V_23 &&
V_20 -> V_9 ) {
V_20 -> V_28 = V_20 -> V_25 ;
V_1 -> V_10 . V_10 [ V_3 ] = F_26 ( V_34 , V_20 -> V_9 ,
V_20 -> V_36 ,
V_20 -> V_25 ,
V_1 -> V_10 . V_12 [ V_3 ] ,
V_37 ) ;
}
}
}
void
F_27 ( T_7 * V_34 , T_1 * V_1 )
{
int V_3 ;
V_5 * V_20 ;
if ( ! F_21 ( V_1 ) )
return;
for ( V_3 = V_1 -> V_6 [ V_35 ] ;
V_3 <= V_1 -> V_8 [ V_35 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_35 ] &&
V_20 -> V_24 ) {
F_28 ( V_34 , V_20 -> V_24 ) ;
}
}
}
void
F_29 ( T_1 * V_1 , const T_2 V_32 , const V_11 * V_38 , ... )
{
T_8 V_39 ;
T_9 V_40 , V_41 ;
int V_3 ;
const V_11 * V_42 ;
V_5 * V_20 ;
if ( ! F_16 ( V_1 , V_32 ) )
return;
if ( V_32 == V_43 )
V_41 = V_44 ;
else
V_41 = V_37 ;
for ( V_3 = V_1 -> V_6 [ V_32 ] ; V_3 <= V_1 -> V_8 [ V_32 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_32 ] ) {
F_30 ( V_20 , V_41 ) ;
V_40 = strlen ( V_20 -> V_25 ) ;
if ( V_40 >= V_41 )
return;
va_start ( V_39 , V_38 ) ;
V_42 = V_38 ;
do {
if G_UNLIKELY( V_42 == NULL )
V_42 = L_2 ;
V_40 += F_31 ( & V_20 -> V_25 [ V_40 ] , V_42 , V_41 - V_40 ) ;
} while ( V_40 < V_41 && ( V_42 = va_arg ( V_39 , const char * ) ) != V_45 );
va_end ( V_39 ) ;
}
}
}
void
F_32 ( T_1 * V_1 , const T_2 V_31 , const V_11 * V_46 , T_10 V_47 , const V_11 * V_48 )
{
char V_49 [ 16 ] ;
F_33 ( V_47 , V_49 , sizeof( V_49 ) ) ;
F_29 ( V_1 , V_31 , V_48 ? V_48 : L_1 , V_46 , L_3 , V_49 , V_45 ) ;
}
static inline void
F_34 ( V_11 * V_49 , T_11 V_50 , T_12 V_51 , T_13 V_47 )
{
const char * V_42 ;
if ( V_52 . V_53 &&
( V_42 = F_35 ( V_51 , V_47 ) ) != NULL ) {
F_36 ( V_49 , V_50 , L_4 V_54 L_5 , V_42 , V_47 ) ;
} else {
F_36 ( V_49 , V_50 , L_6 V_54 , V_47 ) ;
}
}
void
F_37 ( T_1 * V_1 , const T_2 V_31 , T_12 V_51 , T_13 V_55 , T_13 V_56 )
{
char V_57 [ 32 ] , V_58 [ 32 ] ;
F_34 ( V_57 , 32 , V_51 , V_55 ) ;
F_34 ( V_58 , 32 , V_51 , V_56 ) ;
F_29 ( V_1 , V_31 , V_57 , V_59 , V_58 , V_45 ) ;
}
static void
F_38 ( T_1 * V_1 , const int V_32 , const char * V_60 , const char * V_61 , T_8 V_39 )
{
T_9 V_62 , V_41 , V_63 ;
int V_3 ;
V_5 * V_20 ;
V_63 = ( V_60 ) ? strlen ( V_60 ) : 0 ;
if ( V_32 == V_43 )
V_41 = V_44 ;
else
V_41 = V_37 ;
for ( V_3 = V_1 -> V_6 [ V_32 ] ; V_3 <= V_1 -> V_8 [ V_32 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_32 ] ) {
F_30 ( V_20 , V_41 ) ;
V_62 = strlen ( V_20 -> V_25 ) ;
if ( V_63 != 0 && V_62 != 0 ) {
F_39 ( V_20 -> V_25 , V_60 , V_41 ) ;
V_62 += V_63 ;
}
if ( V_62 < V_41 ) {
T_8 V_64 ;
F_40 ( V_64 , V_39 ) ;
F_41 ( & V_20 -> V_25 [ V_62 ] , ( T_10 ) ( V_41 - V_62 ) , V_61 , V_64 ) ;
va_end ( V_64 ) ;
}
}
}
}
void
F_42 ( T_1 * V_1 , const T_2 V_32 , const V_11 * V_61 , ... )
{
T_8 V_39 ;
if ( ! F_16 ( V_1 , V_32 ) )
return;
va_start ( V_39 , V_61 ) ;
F_38 ( V_1 , V_32 , NULL , V_61 , V_39 ) ;
va_end ( V_39 ) ;
}
void
F_43 ( T_1 * V_1 , const T_2 V_32 , const V_11 * V_60 ,
const V_11 * V_61 , ... )
{
T_8 V_39 ;
if ( ! F_16 ( V_1 , V_32 ) )
return;
if ( V_60 == NULL )
V_60 = L_7 ;
va_start ( V_39 , V_61 ) ;
F_38 ( V_1 , V_32 , V_60 , V_61 , V_39 ) ;
va_end ( V_39 ) ;
}
void
F_44 ( T_1 * V_1 , const T_2 V_32 , const V_11 * V_61 , ... )
{
T_8 V_39 ;
int V_3 ;
char V_65 [ V_66 ] ;
const char * V_67 ;
int V_41 ;
V_5 * V_20 ;
if ( ! F_16 ( V_1 , V_32 ) )
return;
if ( V_32 == V_43 )
V_41 = V_44 ;
else
V_41 = V_37 ;
for ( V_3 = V_1 -> V_6 [ V_32 ] ; V_3 <= V_1 -> V_8 [ V_32 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_32 ] ) {
if ( V_20 -> V_28 != V_20 -> V_25 ) {
V_67 = V_20 -> V_28 ;
} else {
F_31 ( V_65 , V_20 -> V_25 , V_41 ) ;
V_67 = V_65 ;
}
va_start ( V_39 , V_61 ) ;
F_41 ( V_20 -> V_25 , V_41 , V_61 , V_39 ) ;
va_end ( V_39 ) ;
if ( V_20 -> V_29 > 0 )
V_20 -> V_29 += ( int ) strlen ( V_20 -> V_25 ) ;
F_39 ( V_20 -> V_25 , V_67 , V_41 ) ;
V_20 -> V_28 = V_20 -> V_25 ;
}
}
}
void
F_45 ( T_1 * V_1 , const T_2 V_32 , const V_11 * V_61 , ... )
{
T_8 V_39 ;
int V_3 ;
char V_65 [ V_66 ] ;
const char * V_67 ;
int V_41 ;
V_5 * V_20 ;
if ( ! F_16 ( V_1 , V_32 ) )
return;
if ( V_32 == V_43 )
V_41 = V_44 ;
else
V_41 = V_37 ;
for ( V_3 = V_1 -> V_6 [ V_32 ] ; V_3 <= V_1 -> V_8 [ V_32 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_32 ] ) {
if ( V_20 -> V_28 != V_20 -> V_25 ) {
V_67 = V_20 -> V_28 ;
} else {
F_31 ( V_65 , V_20 -> V_25 , V_41 ) ;
V_67 = V_65 ;
}
va_start ( V_39 , V_61 ) ;
F_41 ( V_20 -> V_25 , V_41 , V_61 , V_39 ) ;
va_end ( V_39 ) ;
if ( V_20 -> V_29 > 0 ) {
V_20 -> V_29 += ( int ) strlen ( V_20 -> V_25 ) ;
} else {
V_20 -> V_29 = ( int ) strlen ( V_20 -> V_25 ) ;
}
F_39 ( V_20 -> V_25 , V_67 , V_41 ) ;
V_20 -> V_28 = V_20 -> V_25 ;
}
}
}
void
F_46 ( T_1 * V_1 , const T_2 V_32 , const V_11 * V_42 )
{
int V_3 ;
T_9 V_41 ;
V_5 * V_20 ;
if ( ! F_16 ( V_1 , V_32 ) )
return;
if ( V_32 == V_43 )
V_41 = V_44 ;
else
V_41 = V_37 ;
for ( V_3 = V_1 -> V_6 [ V_32 ] ; V_3 <= V_1 -> V_8 [ V_32 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_32 ] ) {
if ( V_20 -> V_29 != 0 ) {
F_30 ( V_20 , V_41 ) ;
} else {
V_20 -> V_28 = V_20 -> V_25 ;
}
F_31 ( & V_20 -> V_25 [ V_20 -> V_29 ] , V_42 , V_41 - V_20 -> V_29 ) ;
}
}
}
void
F_47 ( T_1 * V_1 , const T_2 V_32 , const V_11 * V_42 )
{
int V_3 ;
T_9 V_41 ;
V_5 * V_20 ;
F_48 ( V_42 ) ;
if ( ! F_16 ( V_1 , V_32 ) )
return;
if ( V_32 == V_43 )
V_41 = V_44 ;
else
V_41 = V_37 ;
for ( V_3 = V_1 -> V_6 [ V_32 ] ; V_3 <= V_1 -> V_8 [ V_32 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_32 ] ) {
if ( V_20 -> V_29 != 0 ) {
F_30 ( V_20 , V_41 ) ;
F_31 ( & V_20 -> V_25 [ V_20 -> V_29 ] , V_42 , V_41 - V_20 -> V_29 ) ;
} else {
V_20 -> V_28 = V_42 ;
}
}
}
}
void
F_49 ( T_1 * V_1 , const T_2 V_32 , const V_11 * V_38 , ... )
{
T_8 V_39 ;
int V_3 ;
T_14 V_40 ;
T_14 V_41 ;
const V_11 * V_42 ;
V_5 * V_20 ;
if ( ! F_16 ( V_1 , V_32 ) )
return;
if ( V_32 == V_43 )
V_41 = V_44 ;
else
V_41 = V_37 ;
for ( V_3 = V_1 -> V_6 [ V_32 ] ; V_3 <= V_1 -> V_8 [ V_32 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_32 ] ) {
V_40 = V_20 -> V_29 ;
if ( V_40 != 0 ) {
F_30 ( V_20 , V_41 ) ;
} else {
V_20 -> V_28 = V_20 -> V_25 ;
}
va_start ( V_39 , V_38 ) ;
V_42 = V_38 ;
do {
if G_UNLIKELY( V_42 == NULL )
V_42 = L_2 ;
V_40 += F_31 ( & V_20 -> V_25 [ V_40 ] , V_42 , V_41 - V_40 ) ;
} while ( V_40 < V_41 && ( V_42 = va_arg ( V_39 , const char * ) ) != V_45 );
va_end ( V_39 ) ;
}
}
}
void
F_50 ( T_1 * V_1 , const T_2 V_32 , const V_11 * V_61 , ... )
{
T_8 V_39 ;
int V_3 ;
int V_41 ;
V_5 * V_20 ;
if ( ! F_16 ( V_1 , V_32 ) )
return;
if ( V_32 == V_43 )
V_41 = V_44 ;
else
V_41 = V_37 ;
for ( V_3 = V_1 -> V_6 [ V_32 ] ; V_3 <= V_1 -> V_8 [ V_32 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_32 ] ) {
if ( V_20 -> V_29 != 0 ) {
F_30 ( V_20 , V_41 ) ;
} else {
V_20 -> V_28 = V_20 -> V_25 ;
}
va_start ( V_39 , V_61 ) ;
F_41 ( & V_20 -> V_25 [ V_20 -> V_29 ] , V_41 - V_20 -> V_29 , V_61 , V_39 ) ;
va_end ( V_39 ) ;
}
}
}
static void
F_51 ( T_1 * V_1 , const T_2 V_32 , const V_11 * V_60 ,
const V_11 * V_42 )
{
int V_3 ;
T_9 V_62 , V_41 ;
V_5 * V_20 ;
if ( V_32 == V_43 )
V_41 = V_44 ;
else
V_41 = V_37 ;
for ( V_3 = V_1 -> V_6 [ V_32 ] ; V_3 <= V_1 -> V_8 [ V_32 ] ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( V_20 -> V_21 [ V_32 ] ) {
F_30 ( V_20 , V_41 ) ;
V_62 = V_20 -> V_25 [ 0 ] ;
if ( V_60 != NULL ) {
if ( V_62 != 0 ) {
F_39 ( V_20 -> V_25 , V_60 , V_41 ) ;
}
}
F_39 ( V_20 -> V_25 , V_42 , V_41 ) ;
}
}
}
void
F_52 ( T_1 * V_1 , const T_2 V_32 , const V_11 * V_42 )
{
if ( ! F_16 ( V_1 , V_32 ) )
return;
F_51 ( V_1 , V_32 , NULL , V_42 ) ;
}
void
F_53 ( T_1 * V_1 , const T_2 V_32 , const V_11 * V_60 ,
const V_11 * V_42 )
{
if ( ! F_16 ( V_1 , V_32 ) )
return;
if ( V_60 == NULL )
V_60 = L_7 ;
F_51 ( V_1 , V_32 , V_60 , V_42 ) ;
}
T_6
F_54 ( T_1 * V_1 , const T_2 V_31 )
{
V_5 * V_20 = & V_1 -> V_4 [ V_31 ] ;
return ( ( V_20 -> V_21 [ V_68 ] ) ||
( V_20 -> V_21 [ V_69 ] ) ||
( V_20 -> V_21 [ V_70 ] ) ||
( V_20 -> V_21 [ V_71 ] ) ||
( V_20 -> V_21 [ V_72 ] ) ||
( V_20 -> V_21 [ V_73 ] ) ||
( V_20 -> V_21 [ V_74 ] ) ||
( V_20 -> V_21 [ V_75 ] ) ||
( V_20 -> V_21 [ V_76 ] ) ||
( V_20 -> V_21 [ V_77 ] ) ) ;
}
static void
F_55 ( const T_15 * V_78 , V_11 * V_49 , T_6 V_79 )
{
struct V_80 * V_81 ;
T_16 V_82 ;
int V_83 ;
if ( V_78 -> V_84 . V_85 ) {
V_82 = V_78 -> V_86 . V_87 ;
if ( V_79 )
V_81 = localtime ( & V_82 ) ;
else
V_81 = gmtime ( & V_82 ) ;
} else
V_81 = NULL ;
if ( V_81 != NULL ) {
switch ( F_56 () ) {
case V_88 :
V_83 = V_89 ;
break;
case V_90 :
V_83 = V_91 ;
break;
case V_92 :
V_83 = V_93 ;
break;
case V_94 :
V_83 = V_95 ;
break;
case V_96 :
V_83 = V_97 ;
break;
case V_98 :
V_83 = V_99 ;
break;
case V_100 :
V_83 = V_78 -> V_101 ;
break;
default:
F_57 () ;
}
switch ( V_83 ) {
case V_89 :
F_58 ( V_49 , V_37 , L_8 ,
V_81 -> V_102 + 1900 ,
V_81 -> V_103 + 1 ,
V_81 -> V_104 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ) ;
break;
case V_91 :
F_58 ( V_49 , V_37 , L_9 ,
V_81 -> V_102 + 1900 ,
V_81 -> V_103 + 1 ,
V_81 -> V_104 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ,
V_78 -> V_86 . V_108 / 100000000 ) ;
break;
case V_93 :
F_58 ( V_49 , V_37 , L_10 ,
V_81 -> V_102 + 1900 ,
V_81 -> V_103 + 1 ,
V_81 -> V_104 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ,
V_78 -> V_86 . V_108 / 10000000 ) ;
break;
case V_95 :
F_58 ( V_49 , V_37 , L_11 ,
V_81 -> V_102 + 1900 ,
V_81 -> V_103 + 1 ,
V_81 -> V_104 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ,
V_78 -> V_86 . V_108 / 1000000 ) ;
break;
case V_97 :
F_58 ( V_49 , V_37 , L_12 ,
V_81 -> V_102 + 1900 ,
V_81 -> V_103 + 1 ,
V_81 -> V_104 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ,
V_78 -> V_86 . V_108 / 1000 ) ;
break;
case V_99 :
F_58 ( V_49 , V_37 , L_13 ,
V_81 -> V_102 + 1900 ,
V_81 -> V_103 + 1 ,
V_81 -> V_104 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ,
V_78 -> V_86 . V_108 ) ;
break;
default:
F_57 () ;
}
} else {
V_49 [ 0 ] = '\0' ;
}
}
static void
F_59 ( const T_15 * V_78 , T_1 * V_1 , const int V_31 )
{
F_55 ( V_78 , V_1 -> V_4 [ V_31 ] . V_25 , TRUE ) ;
V_1 -> V_10 . V_10 [ V_31 ] = L_14 ;
F_31 ( V_1 -> V_10 . V_12 [ V_31 ] , V_1 -> V_4 [ V_31 ] . V_25 , V_37 ) ;
V_1 -> V_4 [ V_31 ] . V_28 = V_1 -> V_4 [ V_31 ] . V_25 ;
}
static void
F_60 ( const T_15 * V_78 , T_1 * V_1 , const int V_31 )
{
F_55 ( V_78 , V_1 -> V_4 [ V_31 ] . V_25 , FALSE ) ;
V_1 -> V_10 . V_10 [ V_31 ] = L_14 ;
F_31 ( V_1 -> V_10 . V_12 [ V_31 ] , V_1 -> V_4 [ V_31 ] . V_25 , V_37 ) ;
V_1 -> V_4 [ V_31 ] . V_28 = V_1 -> V_4 [ V_31 ] . V_25 ;
}
static void
F_61 ( const T_15 * V_78 , V_11 * V_49 , T_6 V_79 )
{
struct V_80 * V_81 ;
T_16 V_82 ;
int V_83 ;
if ( V_78 -> V_84 . V_85 ) {
V_82 = V_78 -> V_86 . V_87 ;
if ( V_79 )
V_81 = localtime ( & V_82 ) ;
else
V_81 = gmtime ( & V_82 ) ;
} else
V_81 = NULL ;
if ( V_81 != NULL ) {
switch ( F_56 () ) {
case V_88 :
V_83 = V_89 ;
break;
case V_90 :
V_83 = V_91 ;
break;
case V_92 :
V_83 = V_93 ;
break;
case V_94 :
V_83 = V_95 ;
break;
case V_96 :
V_83 = V_97 ;
break;
case V_98 :
V_83 = V_99 ;
break;
case V_100 :
V_83 = V_78 -> V_101 ;
break;
default:
F_57 () ;
}
switch ( V_83 ) {
case V_89 :
F_58 ( V_49 , V_37 , L_15 ,
V_81 -> V_102 + 1900 ,
V_81 -> V_109 + 1 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ) ;
break;
case V_91 :
F_58 ( V_49 , V_37 , L_16 ,
V_81 -> V_102 + 1900 ,
V_81 -> V_109 + 1 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ,
V_78 -> V_86 . V_108 / 100000000 ) ;
break;
case V_93 :
F_58 ( V_49 , V_37 , L_17 ,
V_81 -> V_102 + 1900 ,
V_81 -> V_109 + 1 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ,
V_78 -> V_86 . V_108 / 10000000 ) ;
break;
case V_95 :
F_58 ( V_49 , V_37 , L_18 ,
V_81 -> V_102 + 1900 ,
V_81 -> V_109 + 1 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ,
V_78 -> V_86 . V_108 / 1000000 ) ;
break;
case V_97 :
F_58 ( V_49 , V_37 , L_19 ,
V_81 -> V_102 + 1900 ,
V_81 -> V_109 + 1 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ,
V_78 -> V_86 . V_108 / 1000 ) ;
break;
case V_99 :
F_58 ( V_49 , V_37 , L_20 ,
V_81 -> V_102 + 1900 ,
V_81 -> V_109 + 1 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ,
V_78 -> V_86 . V_108 ) ;
break;
default:
F_57 () ;
}
} else {
V_49 [ 0 ] = '\0' ;
}
}
static void
F_62 ( const T_15 * V_78 , T_1 * V_1 , const int V_31 )
{
F_61 ( V_78 , V_1 -> V_4 [ V_31 ] . V_25 , TRUE ) ;
V_1 -> V_10 . V_10 [ V_31 ] = L_14 ;
F_31 ( V_1 -> V_10 . V_12 [ V_31 ] , V_1 -> V_4 [ V_31 ] . V_25 , V_37 ) ;
V_1 -> V_4 [ V_31 ] . V_28 = V_1 -> V_4 [ V_31 ] . V_25 ;
}
static void
F_63 ( const T_15 * V_78 , T_1 * V_1 , const int V_31 )
{
F_61 ( V_78 , V_1 -> V_4 [ V_31 ] . V_25 , FALSE ) ;
V_1 -> V_10 . V_10 [ V_31 ] = L_14 ;
F_31 ( V_1 -> V_10 . V_12 [ V_31 ] , V_1 -> V_4 [ V_31 ] . V_25 , V_37 ) ;
V_1 -> V_4 [ V_31 ] . V_28 = V_1 -> V_4 [ V_31 ] . V_25 ;
}
static void
F_64 ( const T_15 * V_78 , const T_17 * V_110 , V_11 * V_49 )
{
int V_83 ;
switch ( F_56 () ) {
case V_88 :
V_83 = V_89 ;
break;
case V_90 :
V_83 = V_91 ;
break;
case V_92 :
V_83 = V_93 ;
break;
case V_94 :
V_83 = V_95 ;
break;
case V_96 :
V_83 = V_97 ;
break;
case V_98 :
V_83 = V_99 ;
break;
case V_100 :
V_83 = V_78 -> V_101 ;
break;
default:
F_57 () ;
}
switch ( V_83 ) {
case V_89 :
F_65 ( V_49 , V_37 ,
( V_111 ) V_110 -> V_87 , V_110 -> V_108 / 1000000000 , V_112 ) ;
break;
case V_91 :
F_65 ( V_49 , V_37 ,
( V_111 ) V_110 -> V_87 , V_110 -> V_108 / 100000000 , V_113 ) ;
break;
case V_93 :
F_65 ( V_49 , V_37 ,
( V_111 ) V_110 -> V_87 , V_110 -> V_108 / 10000000 , V_114 ) ;
break;
case V_95 :
F_65 ( V_49 , V_37 ,
( V_111 ) V_110 -> V_87 , V_110 -> V_108 / 1000000 , V_115 ) ;
break;
case V_97 :
F_65 ( V_49 , V_37 ,
( V_111 ) V_110 -> V_87 , V_110 -> V_108 / 1000 , V_116 ) ;
break;
case V_99 :
F_65 ( V_49 , V_37 ,
( V_111 ) V_110 -> V_87 , V_110 -> V_108 , V_117 ) ;
break;
default:
F_57 () ;
}
}
static void
F_66 ( const T_15 * V_78 , const T_17 * V_110 , V_11 * V_49 )
{
T_16 V_87 = V_110 -> V_87 ;
long V_108 = ( long ) V_110 -> V_108 ;
T_6 V_118 = FALSE ;
int V_83 ;
if ( V_87 < 0 ) {
V_87 = - V_87 ;
V_118 = TRUE ;
}
if ( V_108 < 0 ) {
V_108 = - V_108 ;
V_118 = TRUE ;
}
switch ( F_56 () ) {
case V_88 :
V_83 = V_89 ;
break;
case V_90 :
V_83 = V_91 ;
break;
case V_92 :
V_83 = V_93 ;
break;
case V_94 :
V_83 = V_95 ;
break;
case V_96 :
V_83 = V_97 ;
break;
case V_98 :
V_83 = V_99 ;
break;
case V_100 :
V_83 = V_78 -> V_101 ;
break;
default:
F_57 () ;
}
switch ( V_83 ) {
case V_89 :
if ( V_87 >= ( 60 * 60 ) ) {
F_58 ( V_49 , V_37 , L_21 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 / ( 60 * 60 ) ,
( V_111 ) ( V_87 / 60 ) % 60 ,
( V_111 ) V_87 % 60 ) ;
} else if ( V_87 >= 60 ) {
F_58 ( V_49 , V_37 , L_23 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 / 60 ,
( V_111 ) V_87 % 60 ) ;
} else {
F_58 ( V_49 , V_37 , L_24 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 ) ;
}
break;
case V_91 :
if ( V_87 >= ( 60 * 60 ) ) {
F_58 ( V_49 , V_37 , L_25 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 / ( 60 * 60 ) ,
( V_111 ) ( V_87 / 60 ) % 60 ,
( V_111 ) V_87 % 60 ,
V_108 / 100000000 ) ;
} else if ( V_87 >= 60 ) {
F_58 ( V_49 , V_37 , L_26 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 / 60 ,
( V_111 ) V_87 % 60 ,
V_108 / 100000000 ) ;
} else {
F_58 ( V_49 , V_37 , L_27 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 ,
V_108 / 100000000 ) ;
}
break;
case V_93 :
if ( V_87 >= ( 60 * 60 ) ) {
F_58 ( V_49 , V_37 , L_28 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 / ( 60 * 60 ) ,
( V_111 ) ( V_87 / 60 ) % 60 ,
( V_111 ) V_87 % 60 ,
V_108 / 10000000 ) ;
} else if ( V_87 >= 60 ) {
F_58 ( V_49 , V_37 , L_29 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 / 60 ,
( V_111 ) V_87 % 60 ,
V_108 / 10000000 ) ;
} else {
F_58 ( V_49 , V_37 , L_30 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 ,
V_108 / 10000000 ) ;
}
break;
case V_95 :
if ( V_87 >= ( 60 * 60 ) ) {
F_58 ( V_49 , V_37 , L_31 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 / ( 60 * 60 ) ,
( V_111 ) ( V_87 / 60 ) % 60 ,
( V_111 ) V_87 % 60 ,
V_108 / 1000000 ) ;
} else if ( V_87 >= 60 ) {
F_58 ( V_49 , V_37 , L_32 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 / 60 ,
( V_111 ) V_87 % 60 ,
V_108 / 1000000 ) ;
} else {
F_58 ( V_49 , V_37 , L_33 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 ,
V_108 / 1000000 ) ;
}
break;
case V_97 :
if ( V_87 >= ( 60 * 60 ) ) {
F_58 ( V_49 , V_37 , L_34 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 / ( 60 * 60 ) ,
( V_111 ) ( V_87 / 60 ) % 60 ,
( V_111 ) V_87 % 60 ,
V_108 / 1000 ) ;
} else if ( V_87 >= 60 ) {
F_58 ( V_49 , V_37 , L_35 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 / 60 ,
( V_111 ) V_87 % 60 ,
V_108 / 1000 ) ;
} else {
F_58 ( V_49 , V_37 , L_36 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 ,
V_108 / 1000 ) ;
}
break;
case V_99 :
if ( V_87 >= ( 60 * 60 ) ) {
F_58 ( V_49 , V_37 , L_37 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 / ( 60 * 60 ) ,
( V_111 ) ( V_87 / 60 ) % 60 ,
( V_111 ) V_87 % 60 ,
V_108 ) ;
} else if ( V_87 >= 60 ) {
F_58 ( V_49 , V_37 , L_38 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 / 60 ,
( V_111 ) V_87 % 60 ,
V_108 ) ;
} else {
F_58 ( V_49 , V_37 , L_39 ,
V_118 ? L_22 : L_1 ,
( V_111 ) V_87 ,
V_108 ) ;
}
break;
default:
F_57 () ;
}
}
static void
F_67 ( const T_15 * V_78 , T_1 * V_1 , const int V_31 )
{
T_17 V_119 ;
if ( ! V_78 -> V_84 . V_85 ) {
V_1 -> V_4 [ V_31 ] . V_25 [ 0 ] = '\0' ;
return;
}
F_68 ( V_1 -> V_27 , V_78 , V_78 -> V_120 , & V_119 ) ;
switch ( F_69 () ) {
case V_121 :
F_64 ( V_78 , & V_119 , V_1 -> V_4 [ V_31 ] . V_25 ) ;
V_1 -> V_10 . V_10 [ V_31 ] = L_40 ;
F_31 ( V_1 -> V_10 . V_12 [ V_31 ] , V_1 -> V_4 [ V_31 ] . V_25 , V_37 ) ;
break;
case V_122 :
F_66 ( V_78 , & V_119 , V_1 -> V_4 [ V_31 ] . V_25 ) ;
V_1 -> V_10 . V_10 [ V_31 ] = L_40 ;
F_64 ( V_78 , & V_119 , V_1 -> V_10 . V_12 [ V_31 ] ) ;
break;
default:
F_57 () ;
}
V_1 -> V_4 [ V_31 ] . V_28 = V_1 -> V_4 [ V_31 ] . V_25 ;
}
static void
F_70 ( const T_15 * V_78 , T_1 * V_1 , const int V_31 )
{
T_17 V_123 ;
F_68 ( V_1 -> V_27 , V_78 , V_78 -> V_124 - 1 , & V_123 ) ;
switch ( F_69 () ) {
case V_121 :
F_64 ( V_78 , & V_123 , V_1 -> V_4 [ V_31 ] . V_25 ) ;
V_1 -> V_10 . V_10 [ V_31 ] = L_41 ;
F_31 ( V_1 -> V_10 . V_12 [ V_31 ] , V_1 -> V_4 [ V_31 ] . V_25 , V_37 ) ;
break;
case V_122 :
F_66 ( V_78 , & V_123 , V_1 -> V_4 [ V_31 ] . V_25 ) ;
V_1 -> V_10 . V_10 [ V_31 ] = L_41 ;
F_64 ( V_78 , & V_123 , V_1 -> V_10 . V_12 [ V_31 ] ) ;
break;
default:
F_57 () ;
}
V_1 -> V_4 [ V_31 ] . V_28 = V_1 -> V_4 [ V_31 ] . V_25 ;
}
static void
F_71 ( const T_15 * V_78 , T_1 * V_1 , const int V_31 )
{
T_17 V_125 ;
if ( ! V_78 -> V_84 . V_85 ) {
V_1 -> V_4 [ V_31 ] . V_25 [ 0 ] = '\0' ;
return;
}
F_68 ( V_1 -> V_27 , V_78 , V_78 -> V_126 , & V_125 ) ;
switch ( F_69 () ) {
case V_121 :
F_64 ( V_78 , & V_125 , V_1 -> V_4 [ V_31 ] . V_25 ) ;
V_1 -> V_10 . V_10 [ V_31 ] = L_42 ;
F_31 ( V_1 -> V_10 . V_12 [ V_31 ] , V_1 -> V_4 [ V_31 ] . V_25 , V_37 ) ;
break;
case V_122 :
F_66 ( V_78 , & V_125 , V_1 -> V_4 [ V_31 ] . V_25 ) ;
V_1 -> V_10 . V_10 [ V_31 ] = L_42 ;
F_64 ( V_78 , & V_125 , V_1 -> V_10 . V_12 [ V_31 ] ) ;
break;
default:
F_57 () ;
}
V_1 -> V_4 [ V_31 ] . V_28 = V_1 -> V_4 [ V_31 ] . V_25 ;
}
static void
F_72 ( const T_15 * V_78 , V_11 * V_49 , T_6 V_79 )
{
struct V_80 * V_81 ;
T_16 V_82 ;
int V_83 ;
if ( V_78 -> V_84 . V_85 ) {
V_82 = V_78 -> V_86 . V_87 ;
if ( V_79 )
V_81 = localtime ( & V_82 ) ;
else
V_81 = gmtime ( & V_82 ) ;
} else
V_81 = NULL ;
if ( V_81 != NULL ) {
switch ( F_56 () ) {
case V_88 :
V_83 = V_89 ;
break;
case V_90 :
V_83 = V_91 ;
break;
case V_92 :
V_83 = V_93 ;
break;
case V_94 :
V_83 = V_95 ;
break;
case V_96 :
V_83 = V_97 ;
break;
case V_98 :
V_83 = V_99 ;
break;
case V_100 :
V_83 = V_78 -> V_101 ;
break;
default:
F_57 () ;
}
switch ( V_83 ) {
case V_89 :
F_58 ( V_49 , V_37 , L_43 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ) ;
break;
case V_91 :
F_58 ( V_49 , V_37 , L_44 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ,
V_78 -> V_86 . V_108 / 100000000 ) ;
break;
case V_93 :
F_58 ( V_49 , V_37 , L_45 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ,
V_78 -> V_86 . V_108 / 10000000 ) ;
break;
case V_95 :
F_58 ( V_49 , V_37 , L_46 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ,
V_78 -> V_86 . V_108 / 1000000 ) ;
break;
case V_97 :
F_58 ( V_49 , V_37 , L_47 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ,
V_78 -> V_86 . V_108 / 1000 ) ;
break;
case V_99 :
F_58 ( V_49 , V_37 , L_48 ,
V_81 -> V_105 ,
V_81 -> V_106 ,
V_81 -> V_107 ,
V_78 -> V_86 . V_108 ) ;
break;
default:
F_57 () ;
}
} else {
* V_49 = '\0' ;
}
}
static void
F_73 ( const T_15 * V_78 , T_1 * V_1 , const int V_31 )
{
F_72 ( V_78 , V_1 -> V_4 [ V_31 ] . V_25 , TRUE ) ;
V_1 -> V_10 . V_10 [ V_31 ] = L_14 ;
F_31 ( V_1 -> V_10 . V_12 [ V_31 ] , V_1 -> V_4 [ V_31 ] . V_25 , V_37 ) ;
V_1 -> V_4 [ V_31 ] . V_28 = V_1 -> V_4 [ V_31 ] . V_25 ;
}
static void
F_74 ( const T_15 * V_78 , T_1 * V_1 , const int V_31 )
{
F_72 ( V_78 , V_1 -> V_4 [ V_31 ] . V_25 , FALSE ) ;
V_1 -> V_10 . V_10 [ V_31 ] = L_14 ;
F_31 ( V_1 -> V_10 . V_12 [ V_31 ] , V_1 -> V_4 [ V_31 ] . V_25 , V_37 ) ;
V_1 -> V_4 [ V_31 ] . V_28 = V_1 -> V_4 [ V_31 ] . V_25 ;
}
static T_6
F_75 ( const T_15 * V_78 , V_11 * V_49 )
{
int V_83 ;
if ( ! V_78 -> V_84 . V_85 ) {
V_49 [ 0 ] = '\0' ;
return FALSE ;
}
switch ( F_56 () ) {
case V_88 :
V_83 = V_89 ;
break;
case V_90 :
V_83 = V_91 ;
break;
case V_92 :
V_83 = V_93 ;
break;
case V_94 :
V_83 = V_95 ;
break;
case V_96 :
V_83 = V_97 ;
break;
case V_98 :
V_83 = V_99 ;
break;
case V_100 :
V_83 = V_78 -> V_101 ;
break;
default:
F_57 () ;
}
switch ( V_83 ) {
case V_89 :
F_76 ( V_49 , V_37 ,
V_78 -> V_86 . V_87 , V_78 -> V_86 . V_108 / 1000000000 , V_112 ) ;
break;
case V_91 :
F_76 ( V_49 , V_37 ,
V_78 -> V_86 . V_87 , V_78 -> V_86 . V_108 / 100000000 , V_113 ) ;
break;
case V_93 :
F_76 ( V_49 , V_37 ,
V_78 -> V_86 . V_87 , V_78 -> V_86 . V_108 / 10000000 , V_114 ) ;
break;
case V_95 :
F_76 ( V_49 , V_37 ,
V_78 -> V_86 . V_87 , V_78 -> V_86 . V_108 / 1000000 , V_115 ) ;
break;
case V_97 :
F_76 ( V_49 , V_37 ,
V_78 -> V_86 . V_87 , V_78 -> V_86 . V_108 / 1000 , V_116 ) ;
break;
case V_99 :
F_76 ( V_49 , V_37 ,
V_78 -> V_86 . V_87 , V_78 -> V_86 . V_108 , V_117 ) ;
break;
default:
F_57 () ;
}
return TRUE ;
}
static void
F_77 ( const T_15 * V_78 , T_1 * V_1 , const int V_31 )
{
if ( F_75 ( V_78 , V_1 -> V_4 [ V_31 ] . V_25 ) ) {
V_1 -> V_10 . V_10 [ V_31 ] = L_41 ;
F_31 ( V_1 -> V_10 . V_12 [ V_31 ] , V_1 -> V_4 [ V_31 ] . V_25 , V_37 ) ;
}
V_1 -> V_4 [ V_31 ] . V_28 = V_1 -> V_4 [ V_31 ] . V_25 ;
}
void
F_78 ( const T_18 * V_27 , T_15 * V_78 , V_11 * V_49 )
{
switch ( F_79 () ) {
case V_127 :
F_72 ( V_78 , V_49 , TRUE ) ;
break;
case V_128 :
F_55 ( V_78 , V_49 , TRUE ) ;
break;
case V_129 :
F_61 ( V_78 , V_49 , TRUE ) ;
break;
case V_130 :
if ( V_78 -> V_84 . V_85 ) {
T_17 V_119 ;
F_68 ( V_27 , V_78 , V_78 -> V_120 , & V_119 ) ;
switch ( F_69 () ) {
case V_121 :
F_64 ( V_78 , & V_119 , V_49 ) ;
break;
case V_122 :
F_64 ( V_78 , & V_119 , V_49 ) ;
break;
default:
F_57 () ;
}
} else {
V_49 [ 0 ] = '\0' ;
}
break;
case V_131 :
if ( V_78 -> V_84 . V_85 ) {
T_17 V_123 ;
F_68 ( V_27 , V_78 , V_78 -> V_124 - 1 , & V_123 ) ;
switch ( F_69 () ) {
case V_121 :
F_64 ( V_78 , & V_123 , V_49 ) ;
break;
case V_122 :
F_66 ( V_78 , & V_123 , V_49 ) ;
break;
default:
F_57 () ;
}
} else {
V_49 [ 0 ] = '\0' ;
}
break;
case V_132 :
if ( V_78 -> V_84 . V_85 ) {
T_17 V_125 ;
F_68 ( V_27 , V_78 , V_78 -> V_126 , & V_125 ) ;
switch ( F_69 () ) {
case V_121 :
F_64 ( V_78 , & V_125 , V_49 ) ;
break;
case V_122 :
F_66 ( V_78 , & V_125 , V_49 ) ;
break;
default:
F_57 () ;
}
} else {
V_49 [ 0 ] = '\0' ;
}
break;
case V_133 :
F_75 ( V_78 , V_49 ) ;
break;
case V_134 :
F_72 ( V_78 , V_49 , FALSE ) ;
break;
case V_135 :
F_55 ( V_78 , V_49 , FALSE ) ;
break;
case V_136 :
F_61 ( V_78 , V_49 , FALSE ) ;
break;
case V_137 :
F_80 ( FALSE ) ;
break;
}
}
static void
F_81 ( const T_15 * V_78 , T_1 * V_1 , const T_2 V_31 )
{
switch ( F_79 () ) {
case V_127 :
F_73 ( V_78 , V_1 , V_31 ) ;
break;
case V_128 :
F_59 ( V_78 , V_1 , V_31 ) ;
break;
case V_129 :
F_62 ( V_78 , V_1 , V_31 ) ;
break;
case V_130 :
F_67 ( V_78 , V_1 , V_31 ) ;
break;
case V_131 :
F_70 ( V_78 , V_1 , V_31 ) ;
break;
case V_132 :
F_71 ( V_78 , V_1 , V_31 ) ;
break;
case V_133 :
F_77 ( V_78 , V_1 , V_31 ) ;
break;
case V_134 :
F_74 ( V_78 , V_1 , V_31 ) ;
break;
case V_135 :
F_60 ( V_78 , V_1 , V_31 ) ;
break;
case V_136 :
F_63 ( V_78 , V_1 , V_31 ) ;
break;
case V_137 :
F_57 () ;
break;
}
}
static void
F_82 ( const T_15 * V_78 , T_1 * V_1 , const T_2 V_138 , const T_2 V_31 )
{
F_83 ( V_78 , V_1 -> V_4 [ V_31 ] . V_25 ) ;
switch ( V_138 ) {
case V_68 :
F_81 ( V_78 , V_1 , V_31 ) ;
break;
case V_69 :
F_73 ( V_78 , V_1 , V_31 ) ;
break;
case V_70 :
F_59 ( V_78 , V_1 , V_31 ) ;
break;
case V_71 :
F_62 ( V_78 , V_1 , V_31 ) ;
break;
case V_75 :
F_67 ( V_78 , V_1 , V_31 ) ;
break;
case V_76 :
F_70 ( V_78 , V_1 , V_31 ) ;
break;
case V_77 :
F_71 ( V_78 , V_1 , V_31 ) ;
break;
case V_72 :
F_74 ( V_78 , V_1 , V_31 ) ;
break;
case V_73 :
F_60 ( V_78 , V_1 , V_31 ) ;
break;
case V_74 :
F_63 ( V_78 , V_1 , V_31 ) ;
break;
default:
F_57 () ;
break;
}
}
void
F_84 ( T_1 * V_1 , const T_2 V_32 , const T_17 * V_110 , const char * V_139 )
{
int V_31 ;
V_5 * V_20 ;
if ( ! F_16 ( V_1 , V_32 ) )
return;
for ( V_31 = V_1 -> V_6 [ V_32 ] ; V_31 <= V_1 -> V_8 [ V_32 ] ; V_31 ++ ) {
V_20 = & V_1 -> V_4 [ V_31 ] ;
if ( V_20 -> V_21 [ V_32 ] ) {
switch ( F_56 () ) {
case V_88 :
F_65 ( V_20 -> V_25 , V_37 ,
( V_111 ) V_110 -> V_87 , V_110 -> V_108 / 1000000000 , V_112 ) ;
break;
case V_90 :
F_65 ( V_20 -> V_25 , V_37 ,
( V_111 ) V_110 -> V_87 , V_110 -> V_108 / 100000000 , V_113 ) ;
break;
case V_92 :
F_65 ( V_20 -> V_25 , V_37 ,
( V_111 ) V_110 -> V_87 , V_110 -> V_108 / 10000000 , V_114 ) ;
break;
case V_94 :
F_65 ( V_20 -> V_25 , V_37 ,
( V_111 ) V_110 -> V_87 , V_110 -> V_108 / 1000000 , V_115 ) ;
break;
case V_96 :
F_65 ( V_20 -> V_25 , V_37 ,
( V_111 ) V_110 -> V_87 , V_110 -> V_108 / 1000 , V_116 ) ;
break;
case V_98 :
case V_100 :
F_65 ( V_20 -> V_25 , V_37 ,
( V_111 ) V_110 -> V_87 , V_110 -> V_108 , V_117 ) ;
break;
default:
F_57 () ;
}
V_20 -> V_28 = V_20 -> V_25 ;
V_1 -> V_10 . V_10 [ V_31 ] = V_139 ;
F_31 ( V_1 -> V_10 . V_12 [ V_31 ] , V_20 -> V_25 , V_37 ) ;
}
}
}
static void
F_85 ( T_19 * V_140 , const int V_31 , const T_20 * V_141 , const T_6 V_142 ,
const T_6 V_143 , const T_6 V_144 )
{
const char * V_145 ;
V_5 * V_20 = & V_140 -> V_1 -> V_4 [ V_31 ] ;
if ( V_141 -> type == V_146 ) {
return;
}
if ( V_144 && ( V_145 = F_86 ( V_141 ) ) != NULL )
V_20 -> V_28 = V_145 ;
else {
V_20 -> V_28 = V_20 -> V_25 ;
F_87 ( V_141 , V_20 -> V_25 , V_37 ) ;
}
if ( ! V_143 )
return;
V_140 -> V_1 -> V_10 . V_10 [ V_31 ] = F_88 ( V_141 , V_142 ) ;
if ( strlen ( V_140 -> V_1 -> V_10 . V_10 [ V_31 ] ) > 0 )
F_87 ( V_141 , V_140 -> V_1 -> V_10 . V_12 [ V_31 ] , V_37 ) ;
}
static void
F_89 ( T_19 * V_140 , const int V_31 , const T_6 V_147 , const T_6 V_142 , const T_6 V_143 V_18 )
{
T_10 V_148 ;
V_5 * V_20 = & V_140 -> V_1 -> V_4 [ V_31 ] ;
if ( V_142 )
V_148 = V_140 -> V_149 ;
else
V_148 = V_140 -> V_150 ;
switch ( V_140 -> V_151 ) {
case V_152 :
if ( V_147 )
F_31 ( V_20 -> V_25 , F_90 ( V_140 -> V_153 , V_148 ) , V_37 ) ;
else
F_33 ( V_148 , V_20 -> V_25 , V_37 ) ;
break;
case V_154 :
F_33 ( V_148 , V_140 -> V_1 -> V_10 . V_12 [ V_31 ] , V_37 ) ;
if ( V_147 )
F_31 ( V_20 -> V_25 , F_91 ( V_140 -> V_153 , V_148 ) , V_37 ) ;
else
F_31 ( V_20 -> V_25 , V_140 -> V_1 -> V_10 . V_12 [ V_31 ] , V_37 ) ;
if ( V_142 )
V_140 -> V_1 -> V_10 . V_10 [ V_31 ] = L_49 ;
else
V_140 -> V_1 -> V_10 . V_10 [ V_31 ] = L_50 ;
break;
case V_155 :
F_33 ( V_148 , V_140 -> V_1 -> V_10 . V_12 [ V_31 ] , V_37 ) ;
if ( V_147 )
F_31 ( V_20 -> V_25 , F_92 ( V_140 -> V_153 , V_148 ) , V_37 ) ;
else
F_31 ( V_20 -> V_25 , V_140 -> V_1 -> V_10 . V_12 [ V_31 ] , V_37 ) ;
if ( V_142 )
V_140 -> V_1 -> V_10 . V_10 [ V_31 ] = L_51 ;
else
V_140 -> V_1 -> V_10 . V_10 [ V_31 ] = L_52 ;
break;
case V_156 :
if ( V_142 )
V_140 -> V_1 -> V_10 . V_10 [ V_31 ] = L_53 ;
else
V_140 -> V_1 -> V_10 . V_10 [ V_31 ] = L_54 ;
F_33 ( V_148 , V_140 -> V_1 -> V_10 . V_12 [ V_31 ] , V_37 ) ;
F_31 ( V_20 -> V_25 , V_140 -> V_1 -> V_10 . V_12 [ V_31 ] , V_37 ) ;
break;
case V_157 :
F_58 ( V_20 -> V_25 , V_37 , L_55 , V_148 ) ;
F_31 ( V_140 -> V_1 -> V_10 . V_12 [ V_31 ] , V_20 -> V_25 , V_37 ) ;
if ( V_142 )
V_140 -> V_1 -> V_10 . V_10 [ V_31 ] = L_56 ;
else
V_140 -> V_1 -> V_10 . V_10 [ V_31 ] = L_57 ;
break;
case V_158 :
F_58 ( V_20 -> V_25 , V_37 , L_55 , V_148 ) ;
F_31 ( V_140 -> V_1 -> V_10 . V_12 [ V_31 ] , V_20 -> V_25 , V_37 ) ;
if ( V_142 )
V_140 -> V_1 -> V_10 . V_10 [ V_31 ] = L_58 ;
else
V_140 -> V_1 -> V_10 . V_10 [ V_31 ] = L_59 ;
break;
case V_159 :
F_58 ( V_20 -> V_25 , V_37 , L_60 , V_148 ) ;
F_31 ( V_140 -> V_1 -> V_10 . V_12 [ V_31 ] , V_20 -> V_25 , V_37 ) ;
if ( V_142 )
V_140 -> V_1 -> V_10 . V_10 [ V_31 ] = L_61 ;
else
V_140 -> V_1 -> V_10 . V_10 [ V_31 ] = L_62 ;
break;
default:
break;
}
V_20 -> V_28 = V_20 -> V_25 ;
}
T_6
F_93 ( T_1 * V_1 , const T_2 V_31 )
{
F_80 ( V_1 ) ;
F_80 ( V_31 < V_1 -> V_2 ) ;
switch ( V_1 -> V_4 [ V_31 ] . V_160 ) {
case V_161 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_162 :
case V_163 :
return TRUE ;
default:
return FALSE ;
}
}
void
F_94 ( const T_15 * V_78 , T_1 * V_1 , const T_2 V_31 , const T_6 V_143 )
{
V_5 * V_20 = & V_1 -> V_4 [ V_31 ] ;
switch ( V_20 -> V_160 ) {
case V_161 :
F_33 ( V_78 -> V_124 , V_20 -> V_25 , V_37 ) ;
V_20 -> V_28 = V_20 -> V_25 ;
break;
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
F_82 ( V_78 , V_1 , V_20 -> V_160 , V_31 ) ;
break;
case V_162 :
F_33 ( V_78 -> V_164 , V_20 -> V_25 , V_37 ) ;
V_20 -> V_28 = V_20 -> V_25 ;
break;
case V_163 :
F_33 ( V_78 -> V_165 , V_20 -> V_25 , V_37 ) ;
V_20 -> V_28 = V_20 -> V_25 ;
break;
default:
break;
}
if ( ! V_143 )
return;
switch ( V_20 -> V_160 ) {
case V_161 :
V_1 -> V_10 . V_10 [ V_31 ] = L_63 ;
F_31 ( V_1 -> V_10 . V_12 [ V_31 ] , V_20 -> V_25 , V_37 ) ;
break;
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
break;
case V_162 :
V_1 -> V_10 . V_10 [ V_31 ] = L_64 ;
F_31 ( V_1 -> V_10 . V_12 [ V_31 ] , V_20 -> V_25 , V_37 ) ;
break;
case V_163 :
break;
default:
break;
}
}
void
F_95 ( T_19 * V_140 , const T_6 V_143 , const T_6 V_166 )
{
int V_3 ;
V_5 * V_20 ;
if ( ! V_140 -> V_1 )
return;
for ( V_3 = 0 ; V_3 < V_140 -> V_1 -> V_2 ; V_3 ++ ) {
V_20 = & V_140 -> V_1 -> V_4 [ V_3 ] ;
if ( F_93 ( V_140 -> V_1 , V_3 ) ) {
if ( V_166 )
F_94 ( V_140 -> V_78 , V_140 -> V_1 , V_3 , V_143 ) ;
} else {
switch ( V_20 -> V_160 ) {
case V_167 :
case V_168 :
F_85 ( V_140 , V_3 , & V_140 -> V_55 , TRUE , V_143 , TRUE ) ;
break;
case V_169 :
F_85 ( V_140 , V_3 , & V_140 -> V_55 , TRUE , V_143 , FALSE ) ;
break;
case V_170 :
case V_171 :
F_85 ( V_140 , V_3 , & V_140 -> V_172 , TRUE , V_143 , TRUE ) ;
break;
case V_173 :
F_85 ( V_140 , V_3 , & V_140 -> V_172 , TRUE , V_143 , FALSE ) ;
break;
case V_174 :
case V_175 :
F_85 ( V_140 , V_3 , & V_140 -> V_176 , TRUE , V_143 , TRUE ) ;
break;
case V_177 :
F_85 ( V_140 , V_3 , & V_140 -> V_176 , TRUE , V_143 , FALSE ) ;
break;
case V_178 :
case V_179 :
F_85 ( V_140 , V_3 , & V_140 -> V_56 , FALSE , V_143 , TRUE ) ;
break;
case V_180 :
F_85 ( V_140 , V_3 , & V_140 -> V_56 , FALSE , V_143 , FALSE ) ;
break;
case V_181 :
case V_182 :
F_85 ( V_140 , V_3 , & V_140 -> V_183 , FALSE , V_143 , TRUE ) ;
break;
case V_184 :
F_85 ( V_140 , V_3 , & V_140 -> V_183 , FALSE , V_143 , FALSE ) ;
break;
case V_185 :
case V_186 :
F_85 ( V_140 , V_3 , & V_140 -> V_187 , FALSE , V_143 , TRUE ) ;
break;
case V_188 :
F_85 ( V_140 , V_3 , & V_140 -> V_187 , FALSE , V_143 , FALSE ) ;
break;
case V_189 :
case V_190 :
F_89 ( V_140 , V_3 , TRUE , TRUE , V_143 ) ;
break;
case V_191 :
F_89 ( V_140 , V_3 , FALSE , TRUE , V_143 ) ;
break;
case V_192 :
case V_193 :
F_89 ( V_140 , V_3 , TRUE , FALSE , V_143 ) ;
break;
case V_194 :
F_89 ( V_140 , V_3 , FALSE , FALSE , V_143 ) ;
break;
case V_7 :
F_57 () ;
break;
default:
if ( V_20 -> V_160 >= V_7 ) {
F_57 () ;
}
break;
}
}
}
}
void
F_96 ( T_1 * V_1 , T_15 * V_195 , const T_6 V_143 , const T_6 V_166 )
{
int V_3 ;
V_5 * V_20 ;
if ( ! V_1 )
return;
for ( V_3 = 0 ; V_3 < V_1 -> V_2 ; V_3 ++ ) {
V_20 = & V_1 -> V_4 [ V_3 ] ;
if ( F_93 ( V_1 , V_3 ) ) {
if ( V_166 )
F_94 ( V_195 , V_1 , V_3 , V_143 ) ;
} else if ( V_20 -> V_160 == V_43 ) {
V_20 -> V_28 = L_65 ;
} else {
if ( V_20 -> V_160 >= V_7 ) {
F_57 () ;
}
V_20 -> V_28 = L_66 ;
break;
}
}
}
