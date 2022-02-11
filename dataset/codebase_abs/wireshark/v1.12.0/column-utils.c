void
F_1 ( T_1 * V_1 , const T_2 V_2 )
{
int V_3 ;
V_1 -> V_2 = V_2 ;
V_1 -> V_4 = F_2 ( T_2 , V_2 ) ;
V_1 -> V_5 = F_2 ( V_6 * , V_2 ) ;
V_1 -> V_7 = F_2 ( int , V_8 ) ;
V_1 -> V_9 = F_2 ( int , V_8 ) ;
V_1 -> V_10 = F_2 ( V_11 * , V_2 ) ;
V_1 -> V_12 = F_2 ( V_11 * , V_2 ) ;
V_1 -> V_13 = F_2 ( T_2 , V_2 ) ;
V_1 -> V_14 = F_2 ( int , V_2 ) ;
V_1 -> V_15 = F_2 ( struct V_16 * , V_2 ) ;
V_1 -> V_17 = F_2 ( const V_11 * , V_2 ) ;
V_1 -> V_18 = F_2 ( V_11 * , V_2 ) ;
V_1 -> V_19 = F_2 ( int , V_2 ) ;
V_1 -> V_20 . V_20 = F_2 ( const V_11 * , V_2 + 1 ) ;
V_1 -> V_20 . V_21 = F_2 ( V_11 * , V_2 + 1 ) ;
for ( V_3 = 0 ; V_3 < V_8 ; V_3 ++ ) {
V_1 -> V_7 [ V_3 ] = - 1 ;
V_1 -> V_9 [ V_3 ] = - 1 ;
}
}
void
F_3 ( T_1 * V_1 )
{
F_4 ( V_1 -> V_4 ) ;
F_4 ( V_1 -> V_5 ) ;
F_4 ( V_1 -> V_7 ) ;
F_4 ( V_1 -> V_9 ) ;
F_4 ( V_1 -> V_10 ) ;
F_4 ( V_1 -> V_12 ) ;
F_4 ( V_1 -> V_13 ) ;
F_4 ( V_1 -> V_14 ) ;
F_4 ( V_1 -> V_15 ) ;
F_4 ( ( V_11 * * ) V_1 -> V_17 ) ;
F_4 ( V_1 -> V_18 ) ;
F_4 ( V_1 -> V_19 ) ;
F_4 ( ( V_11 * * ) V_1 -> V_20 . V_20 ) ;
F_4 ( V_1 -> V_20 . V_21 ) ;
}
void
F_5 ( T_1 * V_1 , const struct V_22 * V_23 )
{
int V_3 ;
if ( ! V_1 )
return;
for ( V_3 = 0 ; V_3 < V_1 -> V_2 ; V_3 ++ ) {
V_1 -> V_18 [ V_3 ] [ 0 ] = '\0' ;
V_1 -> V_17 [ V_3 ] = V_1 -> V_18 [ V_3 ] ;
V_1 -> V_19 [ V_3 ] = 0 ;
V_1 -> V_20 . V_20 [ V_3 ] = L_1 ;
V_1 -> V_20 . V_21 [ V_3 ] [ 0 ] = '\0' ;
}
V_1 -> V_24 = TRUE ;
V_1 -> V_23 = V_23 ;
}
V_6
F_6 ( T_1 * V_1 )
{
return F_7 ( V_1 ) ;
}
void
F_8 ( T_1 * V_1 , const V_6 V_24 )
{
if ( V_1 )
V_1 -> V_24 = V_24 ;
}
void
F_9 ( T_1 * V_1 , const T_2 V_25 )
{
int V_3 ;
if ( ! F_10 ( V_1 , V_25 ) )
return;
for ( V_3 = V_1 -> V_7 [ V_25 ] ; V_3 <= V_1 -> V_9 [ V_25 ] ; V_3 ++ ) {
if ( V_1 -> V_5 [ V_3 ] [ V_25 ] ) {
V_1 -> V_19 [ V_3 ] = ( int ) strlen ( V_1 -> V_17 [ V_3 ] ) ;
}
}
}
void
F_11 ( T_1 * V_1 , const T_2 V_25 )
{
int V_3 ;
if ( ! F_10 ( V_1 , V_25 ) )
return;
for ( V_3 = V_1 -> V_7 [ V_25 ] ; V_3 <= V_1 -> V_9 [ V_25 ] ; V_3 ++ ) {
if ( V_1 -> V_5 [ V_3 ] [ V_25 ] ) {
V_1 -> V_19 [ V_3 ] = 0 ;
}
}
}
const V_11 *
F_12 ( T_1 * V_1 , const T_2 V_25 )
{
int V_3 ;
const V_11 * V_26 = NULL ;
if ( ! ( V_1 && ( V_1 ) -> V_7 [ V_25 ] >= 0 ) ) {
return NULL ;
}
for ( V_3 = V_1 -> V_7 [ V_25 ] ; V_3 <= V_1 -> V_9 [ V_25 ] ; V_3 ++ ) {
if ( V_1 -> V_5 [ V_3 ] [ V_25 ] ) {
V_26 = ( V_1 -> V_17 [ V_3 ] ) ;
}
}
return V_26 ;
}
void
F_13 ( T_1 * V_1 , const T_2 V_25 )
{
int V_3 ;
int V_27 ;
if ( ! F_10 ( V_1 , V_25 ) )
return;
for ( V_3 = V_1 -> V_7 [ V_25 ] ; V_3 <= V_1 -> V_9 [ V_25 ] ; V_3 ++ ) {
if ( V_1 -> V_5 [ V_3 ] [ V_25 ] ) {
V_27 = V_1 -> V_19 [ V_3 ] ;
if ( V_1 -> V_18 [ V_3 ] == V_1 -> V_17 [ V_3 ] || V_27 == 0 ) {
V_1 -> V_18 [ V_3 ] [ V_27 ] = '\0' ;
V_1 -> V_17 [ V_3 ] = V_1 -> V_18 [ V_3 ] ;
}
V_1 -> V_20 . V_20 [ V_3 ] = L_1 ;
V_1 -> V_20 . V_21 [ V_3 ] [ 0 ] = '\0' ;
}
}
}
V_6
F_14 ( T_1 * V_1 )
{
return F_15 ( V_1 ) ;
}
void F_16 ( T_3 * V_28 , T_1 * V_1 )
{
int V_3 ;
if ( ! F_15 ( V_1 ) )
return;
for ( V_3 = V_1 -> V_7 [ V_29 ] ;
V_3 <= V_1 -> V_9 [ V_29 ] ; V_3 ++ ) {
if ( V_1 -> V_5 [ V_3 ] [ V_29 ] &&
V_1 -> V_12 [ V_3 ] &&
V_1 -> V_14 [ V_3 ] != - 1 ) {
V_1 -> V_17 [ V_3 ] = V_1 -> V_18 [ V_3 ] ;
V_1 -> V_20 . V_20 [ V_3 ] = F_17 ( V_28 , V_1 -> V_14 [ V_3 ] ,
V_1 -> V_13 [ V_3 ] ,
V_1 -> V_18 [ V_3 ] ,
V_1 -> V_20 . V_21 [ V_3 ] ,
V_30 ) ;
}
}
}
void
F_18 ( T_3 * V_28 , T_1 * V_1 )
{
int V_3 ;
if ( ! F_15 ( V_1 ) )
return;
for ( V_3 = V_1 -> V_7 [ V_29 ] ;
V_3 <= V_1 -> V_9 [ V_29 ] ; V_3 ++ ) {
V_1 -> V_14 [ V_3 ] = - 1 ;
if ( V_1 -> V_5 [ V_3 ] [ V_29 ] &&
V_1 -> V_15 [ V_3 ] ) {
F_19 ( V_28 , V_1 -> V_15 [ V_3 ] ) ;
if ( V_1 -> V_12 ) {
T_4 * V_31 = F_20 ( V_1 -> V_12 [ V_3 ] ) ;
V_1 -> V_14 [ V_3 ] = V_31 ? V_31 -> V_32 : - 1 ;
}
}
}
}
static void
F_21 ( T_1 * V_1 , const int V_25 , const char * V_33 , const char * V_34 , T_5 V_35 )
{
T_6 V_36 , V_37 , V_38 ;
int V_3 ;
V_38 = ( V_33 ) ? strlen ( V_33 ) : 0 ;
if ( V_25 == V_39 )
V_37 = V_40 ;
else
V_37 = V_30 ;
for ( V_3 = V_1 -> V_7 [ V_25 ] ; V_3 <= V_1 -> V_9 [ V_25 ] ; V_3 ++ ) {
if ( V_1 -> V_5 [ V_3 ] [ V_25 ] ) {
F_22 ( V_1 , V_3 , V_37 ) ;
V_36 = strlen ( V_1 -> V_18 [ V_3 ] ) ;
if ( V_38 != 0 && V_36 != 0 ) {
F_23 ( V_1 -> V_18 [ V_3 ] , V_33 , V_37 ) ;
V_36 += V_38 ;
}
if ( V_36 < V_37 ) {
T_5 V_41 ;
F_24 ( V_41 , V_35 ) ;
F_25 ( & V_1 -> V_18 [ V_3 ] [ V_36 ] , ( V_42 ) ( V_37 - V_36 ) , V_34 , V_41 ) ;
}
}
}
}
void
F_26 ( T_1 * V_1 , const T_2 V_25 , const V_11 * V_34 , ... )
{
T_5 V_35 ;
if ( ! F_10 ( V_1 , V_25 ) )
return;
va_start ( V_35 , V_34 ) ;
F_21 ( V_1 , V_25 , NULL , V_34 , V_35 ) ;
va_end ( V_35 ) ;
}
void
F_27 ( T_1 * V_1 , const T_2 V_25 , const V_11 * V_33 ,
const V_11 * V_34 , ... )
{
T_5 V_35 ;
if ( ! F_10 ( V_1 , V_25 ) )
return;
if ( V_33 == NULL )
V_33 = L_2 ;
va_start ( V_35 , V_34 ) ;
F_21 ( V_1 , V_25 , V_33 , V_34 , V_35 ) ;
va_end ( V_35 ) ;
}
void
F_28 ( T_1 * V_1 , const T_2 V_25 , const V_11 * V_34 , ... )
{
T_5 V_35 ;
int V_3 ;
char V_43 [ V_44 ] ;
const char * V_45 ;
int V_37 ;
if ( ! F_10 ( V_1 , V_25 ) )
return;
if ( V_25 == V_39 )
V_37 = V_40 ;
else
V_37 = V_30 ;
for ( V_3 = V_1 -> V_7 [ V_25 ] ; V_3 <= V_1 -> V_9 [ V_25 ] ; V_3 ++ ) {
if ( V_1 -> V_5 [ V_3 ] [ V_25 ] ) {
if ( V_1 -> V_17 [ V_3 ] != V_1 -> V_18 [ V_3 ] ) {
V_45 = V_1 -> V_17 [ V_3 ] ;
} else {
F_29 ( V_43 , V_1 -> V_18 [ V_3 ] , V_37 ) ;
V_45 = V_43 ;
}
va_start ( V_35 , V_34 ) ;
F_25 ( V_1 -> V_18 [ V_3 ] , V_37 , V_34 , V_35 ) ;
va_end ( V_35 ) ;
if ( V_1 -> V_19 [ V_3 ] > 0 )
V_1 -> V_19 [ V_3 ] += ( int ) strlen ( V_1 -> V_18 [ V_3 ] ) ;
F_23 ( V_1 -> V_18 [ V_3 ] , V_45 , V_37 ) ;
V_1 -> V_17 [ V_3 ] = V_1 -> V_18 [ V_3 ] ;
}
}
}
void
F_30 ( T_1 * V_1 , const T_2 V_25 , const V_11 * V_34 , ... )
{
T_5 V_35 ;
int V_3 ;
char V_43 [ V_44 ] ;
const char * V_45 ;
int V_37 ;
if ( ! F_10 ( V_1 , V_25 ) )
return;
if ( V_25 == V_39 )
V_37 = V_40 ;
else
V_37 = V_30 ;
for ( V_3 = V_1 -> V_7 [ V_25 ] ; V_3 <= V_1 -> V_9 [ V_25 ] ; V_3 ++ ) {
if ( V_1 -> V_5 [ V_3 ] [ V_25 ] ) {
if ( V_1 -> V_17 [ V_3 ] != V_1 -> V_18 [ V_3 ] ) {
V_45 = V_1 -> V_17 [ V_3 ] ;
} else {
F_29 ( V_43 , V_1 -> V_18 [ V_3 ] , V_37 ) ;
V_45 = V_43 ;
}
va_start ( V_35 , V_34 ) ;
F_25 ( V_1 -> V_18 [ V_3 ] , V_37 , V_34 , V_35 ) ;
va_end ( V_35 ) ;
if ( V_1 -> V_19 [ V_3 ] > 0 ) {
V_1 -> V_19 [ V_3 ] += ( int ) strlen ( V_1 -> V_18 [ V_3 ] ) ;
} else {
V_1 -> V_19 [ V_3 ] = ( int ) strlen ( V_1 -> V_18 [ V_3 ] ) ;
}
F_23 ( V_1 -> V_18 [ V_3 ] , V_45 , V_37 ) ;
V_1 -> V_17 [ V_3 ] = V_1 -> V_18 [ V_3 ] ;
}
}
}
void
F_31 ( T_1 * V_1 , const T_2 V_25 , const V_11 * V_46 )
{
int V_3 ;
int V_27 ;
T_6 V_37 ;
if ( ! F_10 ( V_1 , V_25 ) )
return;
if ( V_25 == V_39 )
V_37 = V_40 ;
else
V_37 = V_30 ;
for ( V_3 = V_1 -> V_7 [ V_25 ] ; V_3 <= V_1 -> V_9 [ V_25 ] ; V_3 ++ ) {
if ( V_1 -> V_5 [ V_3 ] [ V_25 ] ) {
V_27 = V_1 -> V_19 [ V_3 ] ;
if ( V_27 != 0 ) {
F_22 ( V_1 , V_3 , V_37 ) ;
} else {
V_1 -> V_17 [ V_3 ] = V_1 -> V_18 [ V_3 ] ;
}
F_29 ( & V_1 -> V_18 [ V_3 ] [ V_27 ] , V_46 , V_37 - V_27 ) ;
}
}
}
void
F_32 ( T_1 * V_1 , const T_2 V_25 , const V_11 * V_46 )
{
int V_3 ;
int V_27 ;
T_6 V_37 ;
F_33 ( V_46 ) ;
F_33 ( ! F_34 ( V_46 ) ) ;
if ( ! F_10 ( V_1 , V_25 ) )
return;
if ( V_25 == V_39 )
V_37 = V_40 ;
else
V_37 = V_30 ;
for ( V_3 = V_1 -> V_7 [ V_25 ] ; V_3 <= V_1 -> V_9 [ V_25 ] ; V_3 ++ ) {
if ( V_1 -> V_5 [ V_3 ] [ V_25 ] ) {
V_27 = V_1 -> V_19 [ V_3 ] ;
if ( V_27 != 0 ) {
F_22 ( V_1 , V_3 , V_37 ) ;
F_29 ( & V_1 -> V_18 [ V_3 ] [ V_27 ] , V_46 , V_37 - V_27 ) ;
} else {
V_1 -> V_17 [ V_3 ] = V_46 ;
}
}
}
}
void
F_35 ( T_1 * V_1 , const T_2 V_25 , const V_11 * V_46 , ... )
{
T_5 V_35 ;
int V_3 ;
T_7 V_47 ;
T_7 V_37 ;
if ( ! F_10 ( V_1 , V_25 ) )
return;
if ( V_25 == V_39 )
V_37 = V_40 ;
else
V_37 = V_30 ;
for ( V_3 = V_1 -> V_7 [ V_25 ] ; V_3 <= V_1 -> V_9 [ V_25 ] ; V_3 ++ ) {
if ( V_1 -> V_5 [ V_3 ] [ V_25 ] ) {
V_47 = V_1 -> V_19 [ V_3 ] ;
if ( V_47 != 0 ) {
F_22 ( V_1 , V_3 , V_37 ) ;
} else {
V_1 -> V_17 [ V_3 ] = V_1 -> V_18 [ V_3 ] ;
}
va_start ( V_35 , V_46 ) ;
do {
if G_UNLIKELY( V_46 == NULL )
V_46 = L_3 ;
V_47 += F_29 ( & V_1 -> V_18 [ V_3 ] [ V_47 ] , V_46 , V_37 - V_47 ) ;
} while ( V_47 < V_37 && ( V_46 = va_arg ( V_35 , const char * ) ) != V_48 );
va_end ( V_35 ) ;
}
}
}
void
F_36 ( T_1 * V_1 , const T_2 V_25 , const V_11 * V_34 , ... )
{
T_5 V_35 ;
int V_3 ;
int V_27 ;
int V_37 ;
if ( ! F_10 ( V_1 , V_25 ) )
return;
if ( V_25 == V_39 )
V_37 = V_40 ;
else
V_37 = V_30 ;
for ( V_3 = V_1 -> V_7 [ V_25 ] ; V_3 <= V_1 -> V_9 [ V_25 ] ; V_3 ++ ) {
if ( V_1 -> V_5 [ V_3 ] [ V_25 ] ) {
V_27 = V_1 -> V_19 [ V_3 ] ;
if ( V_27 != 0 ) {
F_22 ( V_1 , V_3 , V_37 ) ;
} else {
V_1 -> V_17 [ V_3 ] = V_1 -> V_18 [ V_3 ] ;
}
va_start ( V_35 , V_34 ) ;
F_25 ( & V_1 -> V_18 [ V_3 ] [ V_27 ] , V_37 - V_27 , V_34 , V_35 ) ;
va_end ( V_35 ) ;
}
}
}
static void
F_37 ( T_1 * V_1 , const T_2 V_25 , const V_11 * V_33 ,
const V_11 * V_46 )
{
int V_3 ;
T_6 V_36 , V_37 ;
if ( V_25 == V_39 )
V_37 = V_40 ;
else
V_37 = V_30 ;
for ( V_3 = V_1 -> V_7 [ V_25 ] ; V_3 <= V_1 -> V_9 [ V_25 ] ; V_3 ++ ) {
if ( V_1 -> V_5 [ V_3 ] [ V_25 ] ) {
F_22 ( V_1 , V_3 , V_37 ) ;
V_36 = V_1 -> V_18 [ V_3 ] [ 0 ] ;
if ( V_33 != NULL ) {
if ( V_36 != 0 ) {
F_23 ( V_1 -> V_18 [ V_3 ] , V_33 , V_37 ) ;
}
}
F_23 ( V_1 -> V_18 [ V_3 ] , V_46 , V_37 ) ;
}
}
}
void
F_38 ( T_1 * V_1 , const T_2 V_25 , const V_11 * V_46 )
{
if ( ! F_10 ( V_1 , V_25 ) )
return;
F_37 ( V_1 , V_25 , NULL , V_46 ) ;
}
void
F_39 ( T_1 * V_1 , const T_2 V_25 , const V_11 * V_33 ,
const V_11 * V_46 )
{
if ( ! F_10 ( V_1 , V_25 ) )
return;
if ( V_33 == NULL )
V_33 = L_2 ;
F_37 ( V_1 , V_25 , V_33 , V_46 ) ;
}
V_6
F_40 ( T_1 * V_1 , const T_2 V_49 )
{
return ( ( V_1 -> V_5 [ V_49 ] [ V_50 ] ) ||
( V_1 -> V_5 [ V_49 ] [ V_51 ] ) ||
( V_1 -> V_5 [ V_49 ] [ V_52 ] ) ||
( V_1 -> V_5 [ V_49 ] [ V_53 ] ) ||
( V_1 -> V_5 [ V_49 ] [ V_54 ] ) ||
( V_1 -> V_5 [ V_49 ] [ V_55 ] ) ||
( V_1 -> V_5 [ V_49 ] [ V_56 ] ) ||
( V_1 -> V_5 [ V_49 ] [ V_57 ] ) ||
( V_1 -> V_5 [ V_49 ] [ V_58 ] ) ||
( V_1 -> V_5 [ V_49 ] [ V_59 ] ) ) ;
}
static void
F_41 ( const T_8 * V_60 , V_11 * V_61 , V_6 V_62 )
{
struct V_63 * V_64 ;
T_9 V_65 ;
if ( V_60 -> V_66 . V_67 ) {
V_65 = V_60 -> V_68 . V_69 ;
if ( V_62 )
V_64 = localtime ( & V_65 ) ;
else
V_64 = gmtime ( & V_65 ) ;
} else
V_64 = NULL ;
if ( V_64 != NULL ) {
switch ( F_42 () ) {
case V_70 :
case V_71 :
F_43 ( V_61 , V_30 , L_4 ,
V_64 -> V_72 + 1900 ,
V_64 -> V_73 + 1 ,
V_64 -> V_74 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ) ;
break;
case V_78 :
case V_79 :
F_43 ( V_61 , V_30 , L_5 ,
V_64 -> V_72 + 1900 ,
V_64 -> V_73 + 1 ,
V_64 -> V_74 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ,
V_60 -> V_68 . V_80 / 100000000 ) ;
break;
case V_81 :
case V_82 :
F_43 ( V_61 , V_30 , L_6 ,
V_64 -> V_72 + 1900 ,
V_64 -> V_73 + 1 ,
V_64 -> V_74 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ,
V_60 -> V_68 . V_80 / 10000000 ) ;
break;
case V_83 :
case V_84 :
F_43 ( V_61 , V_30 , L_7 ,
V_64 -> V_72 + 1900 ,
V_64 -> V_73 + 1 ,
V_64 -> V_74 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ,
V_60 -> V_68 . V_80 / 1000000 ) ;
break;
case V_85 :
case V_86 :
F_43 ( V_61 , V_30 , L_8 ,
V_64 -> V_72 + 1900 ,
V_64 -> V_73 + 1 ,
V_64 -> V_74 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ,
V_60 -> V_68 . V_80 / 1000 ) ;
break;
case V_87 :
case V_88 :
F_43 ( V_61 , V_30 , L_9 ,
V_64 -> V_72 + 1900 ,
V_64 -> V_73 + 1 ,
V_64 -> V_74 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ,
V_60 -> V_68 . V_80 ) ;
break;
default:
F_44 () ;
}
} else {
V_61 [ 0 ] = '\0' ;
}
}
static void
F_45 ( const T_8 * V_60 , T_1 * V_1 , const int V_49 )
{
F_41 ( V_60 , V_1 -> V_18 [ V_49 ] , TRUE ) ;
V_1 -> V_20 . V_20 [ V_49 ] = L_10 ;
F_29 ( V_1 -> V_20 . V_21 [ V_49 ] , V_1 -> V_18 [ V_49 ] , V_30 ) ;
V_1 -> V_17 [ V_49 ] = V_1 -> V_18 [ V_49 ] ;
}
static void
F_46 ( const T_8 * V_60 , T_1 * V_1 , const int V_49 )
{
F_41 ( V_60 , V_1 -> V_18 [ V_49 ] , FALSE ) ;
V_1 -> V_20 . V_20 [ V_49 ] = L_10 ;
F_29 ( V_1 -> V_20 . V_21 [ V_49 ] , V_1 -> V_18 [ V_49 ] , V_30 ) ;
V_1 -> V_17 [ V_49 ] = V_1 -> V_18 [ V_49 ] ;
}
static void
F_47 ( const T_8 * V_60 , V_11 * V_61 , V_6 V_62 )
{
struct V_63 * V_64 ;
T_9 V_65 ;
if ( V_60 -> V_66 . V_67 ) {
V_65 = V_60 -> V_68 . V_69 ;
if ( V_62 )
V_64 = localtime ( & V_65 ) ;
else
V_64 = gmtime ( & V_65 ) ;
} else
V_64 = NULL ;
if ( V_64 != NULL ) {
switch ( F_42 () ) {
case V_70 :
case V_71 :
F_43 ( V_61 , V_30 , L_11 ,
V_64 -> V_72 + 1900 ,
V_64 -> V_89 + 1 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ) ;
break;
case V_78 :
case V_79 :
F_43 ( V_61 , V_30 , L_12 ,
V_64 -> V_72 + 1900 ,
V_64 -> V_89 + 1 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ,
V_60 -> V_68 . V_80 / 100000000 ) ;
break;
case V_81 :
case V_82 :
F_43 ( V_61 , V_30 , L_13 ,
V_64 -> V_72 + 1900 ,
V_64 -> V_89 + 1 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ,
V_60 -> V_68 . V_80 / 10000000 ) ;
break;
case V_83 :
case V_84 :
F_43 ( V_61 , V_30 , L_14 ,
V_64 -> V_72 + 1900 ,
V_64 -> V_89 + 1 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ,
V_60 -> V_68 . V_80 / 1000000 ) ;
break;
case V_85 :
case V_86 :
F_43 ( V_61 , V_30 , L_15 ,
V_64 -> V_72 + 1900 ,
V_64 -> V_89 + 1 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ,
V_60 -> V_68 . V_80 / 1000 ) ;
break;
case V_87 :
case V_88 :
F_43 ( V_61 , V_30 , L_16 ,
V_64 -> V_72 + 1900 ,
V_64 -> V_89 + 1 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ,
V_60 -> V_68 . V_80 ) ;
break;
default:
F_44 () ;
}
} else {
V_61 [ 0 ] = '\0' ;
}
}
static void
F_48 ( const T_8 * V_60 , T_1 * V_1 , const int V_49 )
{
F_47 ( V_60 , V_1 -> V_18 [ V_49 ] , TRUE ) ;
V_1 -> V_20 . V_20 [ V_49 ] = L_10 ;
F_29 ( V_1 -> V_20 . V_21 [ V_49 ] , V_1 -> V_18 [ V_49 ] , V_30 ) ;
V_1 -> V_17 [ V_49 ] = V_1 -> V_18 [ V_49 ] ;
}
static void
F_49 ( const T_8 * V_60 , T_1 * V_1 , const int V_49 )
{
F_47 ( V_60 , V_1 -> V_18 [ V_49 ] , FALSE ) ;
V_1 -> V_20 . V_20 [ V_49 ] = L_10 ;
F_29 ( V_1 -> V_20 . V_21 [ V_49 ] , V_1 -> V_18 [ V_49 ] , V_30 ) ;
V_1 -> V_17 [ V_49 ] = V_1 -> V_18 [ V_49 ] ;
}
static void
F_50 ( const T_10 * V_90 , V_11 * V_61 )
{
switch ( F_42 () ) {
case V_70 :
case V_71 :
F_51 ( V_61 , V_30 ,
( V_91 ) V_90 -> V_69 , V_90 -> V_80 / 1000000000 , V_92 ) ;
break;
case V_78 :
case V_79 :
F_51 ( V_61 , V_30 ,
( V_91 ) V_90 -> V_69 , V_90 -> V_80 / 100000000 , V_93 ) ;
break;
case V_81 :
case V_82 :
F_51 ( V_61 , V_30 ,
( V_91 ) V_90 -> V_69 , V_90 -> V_80 / 10000000 , V_94 ) ;
break;
case V_83 :
case V_84 :
F_51 ( V_61 , V_30 ,
( V_91 ) V_90 -> V_69 , V_90 -> V_80 / 1000000 , V_95 ) ;
break;
case V_85 :
case V_86 :
F_51 ( V_61 , V_30 ,
( V_91 ) V_90 -> V_69 , V_90 -> V_80 / 1000 , V_96 ) ;
break;
case V_87 :
case V_88 :
F_51 ( V_61 , V_30 ,
( V_91 ) V_90 -> V_69 , V_90 -> V_80 , V_97 ) ;
break;
default:
F_44 () ;
}
}
static void
F_52 ( const T_10 * V_90 , V_11 * V_61 )
{
T_9 V_69 = V_90 -> V_69 ;
long V_80 = ( long ) V_90 -> V_80 ;
V_6 V_98 = FALSE ;
if ( V_69 < 0 ) {
V_69 = - V_69 ;
V_98 = TRUE ;
}
if ( V_80 < 0 ) {
V_80 = - V_80 ;
V_98 = TRUE ;
}
switch ( F_42 () ) {
case V_70 :
case V_71 :
if ( V_69 >= ( 60 * 60 ) ) {
F_43 ( V_61 , V_30 , L_17 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 / ( 60 * 60 ) ,
( V_91 ) ( V_69 / 60 ) % 60 ,
( V_91 ) V_69 % 60 ) ;
} else if ( V_69 >= 60 ) {
F_43 ( V_61 , V_30 , L_19 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 / 60 ,
( V_91 ) V_69 % 60 ) ;
} else {
F_43 ( V_61 , V_30 , L_20 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 ) ;
}
break;
case V_78 :
case V_79 :
if ( V_69 >= ( 60 * 60 ) ) {
F_43 ( V_61 , V_30 , L_21 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 / ( 60 * 60 ) ,
( V_91 ) ( V_69 / 60 ) % 60 ,
( V_91 ) V_69 % 60 ,
V_80 / 100000000 ) ;
} else if ( V_69 >= 60 ) {
F_43 ( V_61 , V_30 , L_22 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 / 60 ,
( V_91 ) V_69 % 60 ,
V_80 / 100000000 ) ;
} else {
F_43 ( V_61 , V_30 , L_23 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 ,
V_80 / 100000000 ) ;
}
break;
case V_81 :
case V_82 :
if ( V_69 >= ( 60 * 60 ) ) {
F_43 ( V_61 , V_30 , L_24 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 / ( 60 * 60 ) ,
( V_91 ) ( V_69 / 60 ) % 60 ,
( V_91 ) V_69 % 60 ,
V_80 / 10000000 ) ;
} else if ( V_69 >= 60 ) {
F_43 ( V_61 , V_30 , L_25 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 / 60 ,
( V_91 ) V_69 % 60 ,
V_80 / 10000000 ) ;
} else {
F_43 ( V_61 , V_30 , L_26 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 ,
V_80 / 10000000 ) ;
}
break;
case V_83 :
case V_84 :
if ( V_69 >= ( 60 * 60 ) ) {
F_43 ( V_61 , V_30 , L_27 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 / ( 60 * 60 ) ,
( V_91 ) ( V_69 / 60 ) % 60 ,
( V_91 ) V_69 % 60 ,
V_80 / 1000000 ) ;
} else if ( V_69 >= 60 ) {
F_43 ( V_61 , V_30 , L_28 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 / 60 ,
( V_91 ) V_69 % 60 ,
V_80 / 1000000 ) ;
} else {
F_43 ( V_61 , V_30 , L_29 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 ,
V_80 / 1000000 ) ;
}
break;
case V_85 :
case V_86 :
if ( V_69 >= ( 60 * 60 ) ) {
F_43 ( V_61 , V_30 , L_30 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 / ( 60 * 60 ) ,
( V_91 ) ( V_69 / 60 ) % 60 ,
( V_91 ) V_69 % 60 ,
V_80 / 1000 ) ;
} else if ( V_69 >= 60 ) {
F_43 ( V_61 , V_30 , L_31 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 / 60 ,
( V_91 ) V_69 % 60 ,
V_80 / 1000 ) ;
} else {
F_43 ( V_61 , V_30 , L_32 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 ,
V_80 / 1000 ) ;
}
break;
case V_87 :
case V_88 :
if ( V_69 >= ( 60 * 60 ) ) {
F_43 ( V_61 , V_30 , L_33 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 / ( 60 * 60 ) ,
( V_91 ) ( V_69 / 60 ) % 60 ,
( V_91 ) V_69 % 60 ,
V_80 ) ;
} else if ( V_69 >= 60 ) {
F_43 ( V_61 , V_30 , L_34 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 / 60 ,
( V_91 ) V_69 % 60 ,
V_80 ) ;
} else {
F_43 ( V_61 , V_30 , L_35 ,
V_98 ? L_18 : L_1 ,
( V_91 ) V_69 ,
V_80 ) ;
}
break;
default:
F_44 () ;
}
}
static void
F_53 ( const T_8 * V_60 , T_1 * V_1 , const int V_49 )
{
T_10 V_99 ;
if ( ! V_60 -> V_66 . V_67 ) {
V_1 -> V_18 [ V_49 ] [ 0 ] = '\0' ;
return;
}
F_54 ( V_1 -> V_23 , V_60 , V_60 -> V_100 , & V_99 ) ;
switch ( F_55 () ) {
case V_101 :
F_50 ( & V_99 , V_1 -> V_18 [ V_49 ] ) ;
V_1 -> V_20 . V_20 [ V_49 ] = L_36 ;
F_29 ( V_1 -> V_20 . V_21 [ V_49 ] , V_1 -> V_18 [ V_49 ] , V_30 ) ;
break;
case V_102 :
F_52 ( & V_99 , V_1 -> V_18 [ V_49 ] ) ;
V_1 -> V_20 . V_20 [ V_49 ] = L_36 ;
F_50 ( & V_99 , V_1 -> V_20 . V_21 [ V_49 ] ) ;
break;
default:
F_44 () ;
}
V_1 -> V_17 [ V_49 ] = V_1 -> V_18 [ V_49 ] ;
}
static void
F_56 ( const T_8 * V_60 , T_1 * V_1 , const int V_49 )
{
T_10 V_103 ;
F_54 ( V_1 -> V_23 , V_60 , V_60 -> V_104 - 1 , & V_103 ) ;
switch ( F_55 () ) {
case V_101 :
F_50 ( & V_103 , V_1 -> V_18 [ V_49 ] ) ;
V_1 -> V_20 . V_20 [ V_49 ] = L_37 ;
F_29 ( V_1 -> V_20 . V_21 [ V_49 ] , V_1 -> V_18 [ V_49 ] , V_30 ) ;
break;
case V_102 :
F_52 ( & V_103 , V_1 -> V_18 [ V_49 ] ) ;
V_1 -> V_20 . V_20 [ V_49 ] = L_37 ;
F_50 ( & V_103 , V_1 -> V_20 . V_21 [ V_49 ] ) ;
break;
default:
F_44 () ;
}
V_1 -> V_17 [ V_49 ] = V_1 -> V_18 [ V_49 ] ;
}
static void
F_57 ( const T_8 * V_60 , T_1 * V_1 , const int V_49 )
{
T_10 V_105 ;
if ( ! V_60 -> V_66 . V_67 ) {
V_1 -> V_18 [ V_49 ] [ 0 ] = '\0' ;
return;
}
F_54 ( V_1 -> V_23 , V_60 , V_60 -> V_106 , & V_105 ) ;
switch ( F_55 () ) {
case V_101 :
F_50 ( & V_105 , V_1 -> V_18 [ V_49 ] ) ;
V_1 -> V_20 . V_20 [ V_49 ] = L_38 ;
F_29 ( V_1 -> V_20 . V_21 [ V_49 ] , V_1 -> V_18 [ V_49 ] , V_30 ) ;
break;
case V_102 :
F_52 ( & V_105 , V_1 -> V_18 [ V_49 ] ) ;
V_1 -> V_20 . V_20 [ V_49 ] = L_38 ;
F_50 ( & V_105 , V_1 -> V_20 . V_21 [ V_49 ] ) ;
break;
default:
F_44 () ;
}
V_1 -> V_17 [ V_49 ] = V_1 -> V_18 [ V_49 ] ;
}
static void
F_58 ( const T_8 * V_60 , V_11 * V_61 , V_6 V_62 )
{
struct V_63 * V_64 ;
T_9 V_65 ;
if ( V_60 -> V_66 . V_67 ) {
V_65 = V_60 -> V_68 . V_69 ;
if ( V_62 )
V_64 = localtime ( & V_65 ) ;
else
V_64 = gmtime ( & V_65 ) ;
} else
V_64 = NULL ;
if ( V_64 != NULL ) {
switch ( F_42 () ) {
case V_70 :
case V_71 :
F_43 ( V_61 , V_30 , L_39 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ) ;
break;
case V_78 :
case V_79 :
F_43 ( V_61 , V_30 , L_40 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ,
V_60 -> V_68 . V_80 / 100000000 ) ;
break;
case V_81 :
case V_82 :
F_43 ( V_61 , V_30 , L_41 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ,
V_60 -> V_68 . V_80 / 10000000 ) ;
break;
case V_83 :
case V_84 :
F_43 ( V_61 , V_30 , L_42 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ,
V_60 -> V_68 . V_80 / 1000000 ) ;
break;
case V_85 :
case V_86 :
F_43 ( V_61 , V_30 , L_43 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ,
V_60 -> V_68 . V_80 / 1000 ) ;
break;
case V_87 :
case V_88 :
F_43 ( V_61 , V_30 , L_44 ,
V_64 -> V_75 ,
V_64 -> V_76 ,
V_64 -> V_77 ,
V_60 -> V_68 . V_80 ) ;
break;
default:
F_44 () ;
}
} else {
* V_61 = '\0' ;
}
}
static void
F_59 ( const T_8 * V_60 , T_1 * V_1 , const int V_49 )
{
F_58 ( V_60 , V_1 -> V_18 [ V_49 ] , TRUE ) ;
V_1 -> V_20 . V_20 [ V_49 ] = L_10 ;
F_29 ( V_1 -> V_20 . V_21 [ V_49 ] , V_1 -> V_18 [ V_49 ] , V_30 ) ;
V_1 -> V_17 [ V_49 ] = V_1 -> V_18 [ V_49 ] ;
}
static void
F_60 ( const T_8 * V_60 , T_1 * V_1 , const int V_49 )
{
F_58 ( V_60 , V_1 -> V_18 [ V_49 ] , FALSE ) ;
V_1 -> V_20 . V_20 [ V_49 ] = L_10 ;
F_29 ( V_1 -> V_20 . V_21 [ V_49 ] , V_1 -> V_18 [ V_49 ] , V_30 ) ;
V_1 -> V_17 [ V_49 ] = V_1 -> V_18 [ V_49 ] ;
}
static V_6
F_61 ( const T_8 * V_60 , V_11 * V_61 )
{
if ( ! V_60 -> V_66 . V_67 ) {
V_61 [ 0 ] = '\0' ;
return FALSE ;
}
switch ( F_42 () ) {
case V_70 :
case V_71 :
F_62 ( V_61 , V_30 ,
V_60 -> V_68 . V_69 , V_60 -> V_68 . V_80 / 1000000000 , V_92 ) ;
break;
case V_78 :
case V_79 :
F_62 ( V_61 , V_30 ,
V_60 -> V_68 . V_69 , V_60 -> V_68 . V_80 / 100000000 , V_93 ) ;
break;
case V_81 :
case V_82 :
F_62 ( V_61 , V_30 ,
V_60 -> V_68 . V_69 , V_60 -> V_68 . V_80 / 10000000 , V_94 ) ;
break;
case V_83 :
case V_84 :
F_62 ( V_61 , V_30 ,
V_60 -> V_68 . V_69 , V_60 -> V_68 . V_80 / 1000000 , V_95 ) ;
break;
case V_85 :
case V_86 :
F_62 ( V_61 , V_30 ,
V_60 -> V_68 . V_69 , V_60 -> V_68 . V_80 / 1000 , V_96 ) ;
break;
case V_87 :
case V_88 :
F_62 ( V_61 , V_30 ,
V_60 -> V_68 . V_69 , V_60 -> V_68 . V_80 , V_97 ) ;
break;
default:
F_44 () ;
}
return TRUE ;
}
static void
F_63 ( const T_8 * V_60 , T_1 * V_1 , const int V_49 )
{
if ( F_61 ( V_60 , V_1 -> V_18 [ V_49 ] ) ) {
V_1 -> V_20 . V_20 [ V_49 ] = L_37 ;
F_29 ( V_1 -> V_20 . V_21 [ V_49 ] , V_1 -> V_18 [ V_49 ] , V_30 ) ;
}
V_1 -> V_17 [ V_49 ] = V_1 -> V_18 [ V_49 ] ;
}
void
F_64 ( const T_11 * V_23 , T_8 * V_60 , V_11 * V_61 )
{
switch ( F_65 () ) {
case V_107 :
F_58 ( V_60 , V_61 , TRUE ) ;
break;
case V_108 :
F_41 ( V_60 , V_61 , TRUE ) ;
break;
case V_109 :
F_47 ( V_60 , V_61 , TRUE ) ;
break;
case V_110 :
if ( V_60 -> V_66 . V_67 ) {
T_10 V_99 ;
F_54 ( V_23 , V_60 , V_60 -> V_100 , & V_99 ) ;
switch ( F_55 () ) {
case V_101 :
F_50 ( & V_99 , V_61 ) ;
break;
case V_102 :
F_50 ( & V_99 , V_61 ) ;
break;
default:
F_44 () ;
}
} else {
V_61 [ 0 ] = '\0' ;
}
break;
case V_111 :
if ( V_60 -> V_66 . V_67 ) {
T_10 V_103 ;
F_54 ( V_23 , V_60 , V_60 -> V_104 - 1 , & V_103 ) ;
switch ( F_55 () ) {
case V_101 :
F_50 ( & V_103 , V_61 ) ;
break;
case V_102 :
F_52 ( & V_103 , V_61 ) ;
break;
default:
F_44 () ;
}
} else {
V_61 [ 0 ] = '\0' ;
}
break;
case V_112 :
if ( V_60 -> V_66 . V_67 ) {
T_10 V_105 ;
F_54 ( V_23 , V_60 , V_60 -> V_106 , & V_105 ) ;
switch ( F_55 () ) {
case V_101 :
F_50 ( & V_105 , V_61 ) ;
break;
case V_102 :
F_52 ( & V_105 , V_61 ) ;
break;
default:
F_44 () ;
}
} else {
V_61 [ 0 ] = '\0' ;
}
break;
case V_113 :
F_61 ( V_60 , V_61 ) ;
break;
case V_114 :
F_58 ( V_60 , V_61 , FALSE ) ;
break;
case V_115 :
F_41 ( V_60 , V_61 , FALSE ) ;
break;
case V_116 :
F_47 ( V_60 , V_61 , FALSE ) ;
break;
case V_117 :
F_66 ( FALSE ) ;
break;
}
}
static void
F_67 ( const T_8 * V_60 , T_1 * V_1 , const T_2 V_49 )
{
switch ( F_65 () ) {
case V_107 :
F_59 ( V_60 , V_1 , V_49 ) ;
break;
case V_108 :
F_45 ( V_60 , V_1 , V_49 ) ;
break;
case V_109 :
F_48 ( V_60 , V_1 , V_49 ) ;
break;
case V_110 :
F_53 ( V_60 , V_1 , V_49 ) ;
break;
case V_111 :
F_56 ( V_60 , V_1 , V_49 ) ;
break;
case V_112 :
F_57 ( V_60 , V_1 , V_49 ) ;
break;
case V_113 :
F_63 ( V_60 , V_1 , V_49 ) ;
break;
case V_114 :
F_60 ( V_60 , V_1 , V_49 ) ;
break;
case V_115 :
F_46 ( V_60 , V_1 , V_49 ) ;
break;
case V_116 :
F_49 ( V_60 , V_1 , V_49 ) ;
break;
case V_117 :
F_44 () ;
break;
}
}
static void
F_68 ( const T_8 * V_60 , T_1 * V_1 , const T_2 V_118 , const T_2 V_49 )
{
F_69 ( V_60 , V_1 -> V_18 [ V_49 ] ) ;
switch ( V_118 ) {
case V_50 :
F_67 ( V_60 , V_1 , V_49 ) ;
break;
case V_51 :
F_59 ( V_60 , V_1 , V_49 ) ;
break;
case V_52 :
F_45 ( V_60 , V_1 , V_49 ) ;
break;
case V_53 :
F_48 ( V_60 , V_1 , V_49 ) ;
break;
case V_57 :
F_53 ( V_60 , V_1 , V_49 ) ;
break;
case V_58 :
F_56 ( V_60 , V_1 , V_49 ) ;
break;
case V_59 :
F_57 ( V_60 , V_1 , V_49 ) ;
break;
case V_54 :
F_60 ( V_60 , V_1 , V_49 ) ;
break;
case V_55 :
F_46 ( V_60 , V_1 , V_49 ) ;
break;
case V_56 :
F_49 ( V_60 , V_1 , V_49 ) ;
break;
default:
F_44 () ;
break;
}
}
void
F_70 ( T_1 * V_1 , const T_2 V_25 , const T_10 * V_90 , const char * V_119 )
{
int V_49 ;
if ( ! F_10 ( V_1 , V_25 ) )
return;
for ( V_49 = V_1 -> V_7 [ V_25 ] ; V_49 <= V_1 -> V_9 [ V_25 ] ; V_49 ++ ) {
if ( V_1 -> V_5 [ V_49 ] [ V_25 ] ) {
switch ( F_42 () ) {
case V_70 :
case V_71 :
F_51 ( V_1 -> V_18 [ V_49 ] , V_30 ,
( V_91 ) V_90 -> V_69 , V_90 -> V_80 / 1000000000 , V_92 ) ;
break;
case V_78 :
case V_79 :
F_51 ( V_1 -> V_18 [ V_49 ] , V_30 ,
( V_91 ) V_90 -> V_69 , V_90 -> V_80 / 100000000 , V_93 ) ;
break;
case V_81 :
case V_82 :
F_51 ( V_1 -> V_18 [ V_49 ] , V_30 ,
( V_91 ) V_90 -> V_69 , V_90 -> V_80 / 10000000 , V_94 ) ;
break;
case V_83 :
case V_84 :
F_51 ( V_1 -> V_18 [ V_49 ] , V_30 ,
( V_91 ) V_90 -> V_69 , V_90 -> V_80 / 1000000 , V_95 ) ;
break;
case V_85 :
case V_86 :
F_51 ( V_1 -> V_18 [ V_49 ] , V_30 ,
( V_91 ) V_90 -> V_69 , V_90 -> V_80 / 1000 , V_96 ) ;
break;
case V_87 :
case V_88 :
F_51 ( V_1 -> V_18 [ V_49 ] , V_30 ,
( V_91 ) V_90 -> V_69 , V_90 -> V_80 , V_97 ) ;
break;
default:
F_44 () ;
}
V_1 -> V_17 [ V_49 ] = V_1 -> V_18 [ V_49 ] ;
V_1 -> V_20 . V_20 [ V_49 ] = V_119 ;
F_29 ( V_1 -> V_20 . V_21 [ V_49 ] , V_1 -> V_18 [ V_49 ] , V_30 ) ;
}
}
}
static void
F_71 ( T_12 * V_120 , const int V_49 , const T_13 * V_121 , const V_6 V_122 ,
const V_6 V_123 , const V_6 V_124 )
{
const char * V_125 ;
if ( V_121 -> type == V_126 ) {
return;
}
if ( V_124 && ( V_125 = F_72 ( V_121 ) ) != NULL )
V_120 -> V_1 -> V_17 [ V_49 ] = V_125 ;
else {
V_120 -> V_1 -> V_17 [ V_49 ] = V_120 -> V_1 -> V_18 [ V_49 ] ;
F_73 ( V_121 , V_120 -> V_1 -> V_18 [ V_49 ] , V_30 ) ;
}
if ( ! V_123 )
return;
switch ( V_121 -> type ) {
case V_127 :
if ( V_122 )
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_45 ;
else
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_46 ;
F_29 ( V_120 -> V_1 -> V_20 . V_21 [ V_49 ] , F_74 ( ( const V_128 * ) V_121 -> V_129 ) , V_30 ) ;
break;
case V_130 :
if ( V_122 )
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_47 ;
else
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_48 ;
F_73 ( V_121 , V_120 -> V_1 -> V_20 . V_21 [ V_49 ] , V_30 ) ;
break;
case V_131 :
if ( V_122 )
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_49 ;
else
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_50 ;
F_75 ( ( const V_128 * ) V_121 -> V_129 , V_120 -> V_1 -> V_20 . V_21 [ V_49 ] , V_30 ) ;
break;
case V_132 :
if ( V_122 )
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_51 ;
else
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_52 ;
F_73 ( V_121 , V_120 -> V_1 -> V_20 . V_21 [ V_49 ] , V_30 ) ;
break;
case V_133 :
if ( V_122 )
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_53 ;
else
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_54 ;
F_29 ( V_120 -> V_1 -> V_20 . V_21 [ V_49 ] , V_120 -> V_1 -> V_18 [ V_49 ] , V_30 ) ;
break;
case V_134 :
if ( V_122 )
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_55 ;
else
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_56 ;
F_29 ( V_120 -> V_1 -> V_20 . V_21 [ V_49 ] , V_120 -> V_1 -> V_18 [ V_49 ] , V_30 ) ;
break;
case V_135 :
if ( V_122 )
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_57 ;
else
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_58 ;
F_73 ( V_121 , V_120 -> V_1 -> V_20 . V_21 [ V_49 ] , V_30 ) ;
break;
default:
break;
}
if ( V_121 -> V_136 != - 1 ) {
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = F_76 ( V_121 -> V_136 ) -> V_137 ;
}
}
static void
F_77 ( T_12 * V_120 , const int V_49 , const V_6 V_138 , const V_6 V_122 , const V_6 V_123 V_139 )
{
V_42 V_140 ;
if ( V_122 )
V_140 = V_120 -> V_141 ;
else
V_140 = V_120 -> V_142 ;
switch ( V_120 -> V_143 ) {
case V_144 :
if ( V_138 )
F_29 ( V_120 -> V_1 -> V_18 [ V_49 ] , F_78 ( V_140 ) , V_30 ) ;
else
F_79 ( V_140 , V_120 -> V_1 -> V_18 [ V_49 ] , V_30 ) ;
break;
case V_145 :
F_79 ( V_140 , V_120 -> V_1 -> V_20 . V_21 [ V_49 ] , V_30 ) ;
if ( V_138 )
F_29 ( V_120 -> V_1 -> V_18 [ V_49 ] , F_80 ( V_140 ) , V_30 ) ;
else
F_29 ( V_120 -> V_1 -> V_18 [ V_49 ] , V_120 -> V_1 -> V_20 . V_21 [ V_49 ] , V_30 ) ;
if ( V_122 )
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_59 ;
else
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_60 ;
break;
case V_146 :
F_79 ( V_140 , V_120 -> V_1 -> V_20 . V_21 [ V_49 ] , V_30 ) ;
if ( V_138 )
F_29 ( V_120 -> V_1 -> V_18 [ V_49 ] , F_81 ( V_140 ) , V_30 ) ;
else
F_29 ( V_120 -> V_1 -> V_18 [ V_49 ] , V_120 -> V_1 -> V_20 . V_21 [ V_49 ] , V_30 ) ;
if ( V_122 )
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_61 ;
else
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_62 ;
break;
case V_147 :
if ( V_122 )
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_63 ;
else
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_64 ;
F_79 ( V_140 , V_120 -> V_1 -> V_20 . V_21 [ V_49 ] , V_30 ) ;
F_29 ( V_120 -> V_1 -> V_18 [ V_49 ] , V_120 -> V_1 -> V_20 . V_21 [ V_49 ] , V_30 ) ;
break;
case V_148 :
F_43 ( V_120 -> V_1 -> V_18 [ V_49 ] , V_30 , L_65 , V_140 ) ;
F_29 ( V_120 -> V_1 -> V_20 . V_21 [ V_49 ] , V_120 -> V_1 -> V_18 [ V_49 ] , V_30 ) ;
if ( V_122 )
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_66 ;
else
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_67 ;
break;
case V_149 :
F_43 ( V_120 -> V_1 -> V_18 [ V_49 ] , V_30 , L_65 , V_140 ) ;
F_29 ( V_120 -> V_1 -> V_20 . V_21 [ V_49 ] , V_120 -> V_1 -> V_18 [ V_49 ] , V_30 ) ;
if ( V_122 )
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_68 ;
else
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_69 ;
break;
case V_150 :
F_43 ( V_120 -> V_1 -> V_18 [ V_49 ] , V_30 , L_70 , V_140 ) ;
F_29 ( V_120 -> V_1 -> V_20 . V_21 [ V_49 ] , V_120 -> V_1 -> V_18 [ V_49 ] , V_30 ) ;
if ( V_122 )
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_71 ;
else
V_120 -> V_1 -> V_20 . V_20 [ V_49 ] = L_72 ;
break;
default:
break;
}
V_120 -> V_1 -> V_17 [ V_49 ] = V_120 -> V_1 -> V_18 [ V_49 ] ;
}
V_6
F_82 ( T_1 * V_1 , const T_2 V_49 )
{
F_66 ( V_1 ) ;
F_66 ( V_49 < V_1 -> V_2 ) ;
switch ( V_1 -> V_4 [ V_49 ] ) {
case V_151 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_152 :
case V_153 :
return TRUE ;
default:
return FALSE ;
}
}
void
F_83 ( const T_8 * V_60 , T_1 * V_1 , const T_2 V_49 , const V_6 V_123 )
{
switch ( V_1 -> V_4 [ V_49 ] ) {
case V_151 :
F_79 ( V_60 -> V_104 , V_1 -> V_18 [ V_49 ] , V_30 ) ;
V_1 -> V_17 [ V_49 ] = V_1 -> V_18 [ V_49 ] ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
F_68 ( V_60 , V_1 , V_1 -> V_4 [ V_49 ] , V_49 ) ;
break;
case V_152 :
F_79 ( V_60 -> V_154 , V_1 -> V_18 [ V_49 ] , V_30 ) ;
V_1 -> V_17 [ V_49 ] = V_1 -> V_18 [ V_49 ] ;
break;
case V_153 :
F_79 ( V_60 -> V_155 , V_1 -> V_18 [ V_49 ] , V_30 ) ;
V_1 -> V_17 [ V_49 ] = V_1 -> V_18 [ V_49 ] ;
break;
default:
break;
}
if ( ! V_123 )
return;
switch ( V_1 -> V_4 [ V_49 ] ) {
case V_151 :
V_1 -> V_20 . V_20 [ V_49 ] = L_73 ;
F_29 ( V_1 -> V_20 . V_21 [ V_49 ] , V_1 -> V_18 [ V_49 ] , V_30 ) ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
break;
case V_152 :
V_1 -> V_20 . V_20 [ V_49 ] = L_74 ;
F_29 ( V_1 -> V_20 . V_21 [ V_49 ] , V_1 -> V_18 [ V_49 ] , V_30 ) ;
break;
case V_153 :
break;
default:
break;
}
}
void
F_84 ( T_12 * V_120 , const V_6 V_123 , const V_6 V_156 )
{
int V_3 ;
if ( ! V_120 -> V_1 )
return;
for ( V_3 = 0 ; V_3 < V_120 -> V_1 -> V_2 ; V_3 ++ ) {
if ( F_82 ( V_120 -> V_1 , V_3 ) ) {
if ( V_156 )
F_83 ( V_120 -> V_60 , V_120 -> V_1 , V_3 , V_123 ) ;
} else {
switch ( V_120 -> V_1 -> V_4 [ V_3 ] ) {
case V_157 :
case V_158 :
F_71 ( V_120 , V_3 , & V_120 -> V_159 , TRUE , V_123 , TRUE ) ;
break;
case V_160 :
F_71 ( V_120 , V_3 , & V_120 -> V_159 , TRUE , V_123 , FALSE ) ;
break;
case V_161 :
case V_162 :
F_71 ( V_120 , V_3 , & V_120 -> V_163 , TRUE , V_123 , TRUE ) ;
break;
case V_164 :
F_71 ( V_120 , V_3 , & V_120 -> V_163 , TRUE , V_123 , FALSE ) ;
break;
case V_165 :
case V_166 :
F_71 ( V_120 , V_3 , & V_120 -> V_167 , TRUE , V_123 , TRUE ) ;
break;
case V_168 :
F_71 ( V_120 , V_3 , & V_120 -> V_167 , TRUE , V_123 , FALSE ) ;
break;
case V_169 :
case V_170 :
F_71 ( V_120 , V_3 , & V_120 -> V_171 , FALSE , V_123 , TRUE ) ;
break;
case V_172 :
F_71 ( V_120 , V_3 , & V_120 -> V_171 , FALSE , V_123 , FALSE ) ;
break;
case V_173 :
case V_174 :
F_71 ( V_120 , V_3 , & V_120 -> V_175 , FALSE , V_123 , TRUE ) ;
break;
case V_176 :
F_71 ( V_120 , V_3 , & V_120 -> V_175 , FALSE , V_123 , FALSE ) ;
break;
case V_177 :
case V_178 :
F_71 ( V_120 , V_3 , & V_120 -> V_179 , FALSE , V_123 , TRUE ) ;
break;
case V_180 :
F_71 ( V_120 , V_3 , & V_120 -> V_179 , FALSE , V_123 , FALSE ) ;
break;
case V_181 :
case V_182 :
F_77 ( V_120 , V_3 , TRUE , TRUE , V_123 ) ;
break;
case V_183 :
F_77 ( V_120 , V_3 , FALSE , TRUE , V_123 ) ;
break;
case V_184 :
case V_185 :
F_77 ( V_120 , V_3 , TRUE , FALSE , V_123 ) ;
break;
case V_186 :
F_77 ( V_120 , V_3 , FALSE , FALSE , V_123 ) ;
break;
case V_8 :
F_44 () ;
break;
default:
if ( V_120 -> V_1 -> V_4 [ V_3 ] >= V_8 ) {
F_44 () ;
}
break;
}
}
}
}
void
F_85 ( T_1 * V_1 , T_8 * V_187 , const V_6 V_123 , const V_6 V_156 )
{
int V_3 ;
if ( ! V_1 )
return;
for ( V_3 = 0 ; V_3 < V_1 -> V_2 ; V_3 ++ ) {
if ( F_82 ( V_1 , V_3 ) ) {
if ( V_156 )
F_83 ( V_187 , V_1 , V_3 , V_123 ) ;
} else if ( V_1 -> V_4 [ V_3 ] == V_39 ) {
V_1 -> V_17 [ V_3 ] = L_75 ;
} else {
if ( V_1 -> V_4 [ V_3 ] >= V_8 ) {
F_44 () ;
}
V_1 -> V_17 [ V_3 ] = L_76 ;
break;
}
}
}
