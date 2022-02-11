static T_1 *
F_1 ( T_1 * V_1 , const T_2 * V_2 , const T_3 V_3 )
{
if( V_1 -> V_4 & V_5 &&
V_1 -> V_6 -> V_7 != V_8 )
{
T_1 * V_9 ;
T_4 V_4 = V_1 -> V_4 & ~ ( V_5 | V_10 | V_11 ) ;
if( V_1 -> V_4 & V_10 &&
V_1 -> V_4 & V_11 )
{
V_9 =
F_2 ( V_1 -> V_12 ,
& V_1 -> V_6 -> V_13 , V_2 ,
V_1 -> V_6 -> V_7 , V_1 -> V_6 -> V_14 ,
V_3 , V_4 ) ;
}
else if( V_1 -> V_4 & V_11 )
{
V_9 =
F_2 ( V_1 -> V_12 ,
& V_1 -> V_6 -> V_13 , & V_1 -> V_6 -> V_2 ,
V_1 -> V_6 -> V_7 , V_1 -> V_6 -> V_14 ,
V_3 , V_4 ) ;
}
else if( V_1 -> V_4 & V_10 )
{
V_9 =
F_2 ( V_1 -> V_12 ,
& V_1 -> V_6 -> V_13 , V_2 ,
V_1 -> V_6 -> V_7 , V_1 -> V_6 -> V_14 ,
V_1 -> V_6 -> V_3 , V_4 ) ;
}
else
{
return V_1 ;
}
V_9 -> V_15 = V_1 -> V_15 ;
return V_9 ;
}
else
{
return V_1 ;
}
}
static T_4
F_3 ( T_5 V_16 )
{
const T_6 * V_17 = ( const T_6 * ) V_16 ;
T_4 V_18 ;
T_2 V_19 ;
V_18 = 0 ;
V_19 . V_20 = 4 ;
F_4 ( V_18 , & V_17 -> V_13 ) ;
V_19 . V_21 = & V_17 -> V_14 ;
F_4 ( V_18 , & V_19 ) ;
F_4 ( V_18 , & V_17 -> V_2 ) ;
V_19 . V_21 = & V_17 -> V_3 ;
F_4 ( V_18 , & V_19 ) ;
V_18 += ( V_18 << 3 ) ;
V_18 ^= ( V_18 >> 11 ) ;
V_18 += ( V_18 << 15 ) ;
return V_18 ;
}
static T_7
F_5 ( T_5 V_16 , T_5 V_22 )
{
const T_6 * V_23 = ( const T_6 * ) V_16 ;
const T_6 * V_24 = ( const T_6 * ) V_22 ;
if ( V_23 -> V_7 != V_24 -> V_7 )
return 0 ;
if ( V_23 -> V_14 == V_24 -> V_14 &&
V_23 -> V_3 == V_24 -> V_3 &&
F_6 ( & V_23 -> V_13 , & V_24 -> V_13 ) &&
F_6 ( & V_23 -> V_2 , & V_24 -> V_2 ) ) {
return 1 ;
}
if ( V_23 -> V_3 == V_24 -> V_14 &&
V_23 -> V_14 == V_24 -> V_3 &&
F_6 ( & V_23 -> V_2 , & V_24 -> V_13 ) &&
F_6 ( & V_23 -> V_13 , & V_24 -> V_2 ) ) {
return 1 ;
}
return 0 ;
}
static T_4
F_7 ( T_5 V_16 )
{
const T_6 * V_17 = ( const T_6 * ) V_16 ;
T_4 V_18 ;
T_2 V_19 ;
V_18 = 0 ;
V_19 . V_20 = 4 ;
F_4 ( V_18 , & V_17 -> V_13 ) ;
V_19 . V_21 = & V_17 -> V_14 ;
F_4 ( V_18 , & V_19 ) ;
V_19 . V_21 = & V_17 -> V_3 ;
F_4 ( V_18 , & V_19 ) ;
V_18 += ( V_18 << 3 ) ;
V_18 ^= ( V_18 >> 11 ) ;
V_18 += ( V_18 << 15 ) ;
return V_18 ;
}
static T_7
F_8 ( T_5 V_16 , T_5 V_22 )
{
const T_6 * V_23 = ( const T_6 * ) V_16 ;
const T_6 * V_24 = ( const T_6 * ) V_22 ;
if ( V_23 -> V_7 != V_24 -> V_7 )
return 0 ;
if ( V_23 -> V_14 == V_24 -> V_14 &&
V_23 -> V_3 == V_24 -> V_3 &&
F_6 ( & V_23 -> V_13 , & V_24 -> V_13 ) ) {
return 1 ;
}
return 0 ;
}
static T_4
F_9 ( T_5 V_16 )
{
const T_6 * V_17 = ( const T_6 * ) V_16 ;
T_4 V_18 ;
T_2 V_19 ;
V_18 = 0 ;
V_19 . V_20 = 4 ;
F_4 ( V_18 , & V_17 -> V_13 ) ;
V_19 . V_21 = & V_17 -> V_14 ;
F_4 ( V_18 , & V_19 ) ;
F_4 ( V_18 , & V_17 -> V_2 ) ;
V_18 += ( V_18 << 3 ) ;
V_18 ^= ( V_18 >> 11 ) ;
V_18 += ( V_18 << 15 ) ;
return V_18 ;
}
static T_7
F_10 ( T_5 V_16 , T_5 V_22 )
{
const T_6 * V_23 = ( const T_6 * ) V_16 ;
const T_6 * V_24 = ( const T_6 * ) V_22 ;
if ( V_23 -> V_7 != V_24 -> V_7 )
return 0 ;
if ( V_23 -> V_14 == V_24 -> V_14 &&
F_6 ( & V_23 -> V_13 , & V_24 -> V_13 ) &&
F_6 ( & V_23 -> V_2 , & V_24 -> V_2 ) ) {
return 1 ;
}
return 0 ;
}
static T_4
F_11 ( T_5 V_16 )
{
const T_6 * V_17 = ( const T_6 * ) V_16 ;
T_4 V_18 ;
T_2 V_19 ;
V_18 = 0 ;
V_19 . V_20 = 4 ;
F_4 ( V_18 , & V_17 -> V_13 ) ;
V_19 . V_21 = & V_17 -> V_14 ;
F_4 ( V_18 , & V_19 ) ;
V_18 += ( V_18 << 3 ) ;
V_18 ^= ( V_18 >> 11 ) ;
V_18 += ( V_18 << 15 ) ;
return V_18 ;
}
static T_7
F_12 ( T_5 V_16 , T_5 V_22 )
{
const T_6 * V_23 = ( const T_6 * ) V_16 ;
const T_6 * V_24 = ( const T_6 * ) V_22 ;
if ( V_23 -> V_7 != V_24 -> V_7 )
return 0 ;
if ( V_23 -> V_14 == V_24 -> V_14 &&
F_6 ( & V_23 -> V_13 , & V_24 -> V_13 ) ) {
return 1 ;
}
return 0 ;
}
static void
F_13 ( T_8 V_17 V_25 , T_8 V_26 , T_8 T_9 V_25 )
{
T_1 * V_27 = ( T_1 * ) V_26 ;
F_14 ( V_27 -> V_28 ) ;
V_27 -> V_28 = NULL ;
}
void
F_15 ( void )
{
V_29 = NULL ;
if ( V_30 != NULL ) {
F_16 ( V_30 , F_13 , NULL ) ;
F_17 ( V_30 ) ;
}
if ( V_31 != NULL ) {
F_16 ( V_31 , F_13 , NULL ) ;
F_17 ( V_31 ) ;
}
if ( V_32 != NULL ) {
F_16 ( V_32 , F_13 , NULL ) ;
F_17 ( V_32 ) ;
}
if ( V_33 != NULL ) {
F_16 ( V_33 , F_13 , NULL ) ;
F_17 ( V_33 ) ;
}
V_30 = NULL ;
V_31 = NULL ;
V_32 = NULL ;
V_33 = NULL ;
}
void
F_18 ( void )
{
V_30 =
F_19 ( F_3 ,
F_5 ) ;
V_31 =
F_19 ( F_7 ,
F_8 ) ;
V_32 =
F_19 ( F_9 ,
F_10 ) ;
V_33 =
F_19 ( F_11 ,
F_12 ) ;
V_34 = 0 ;
}
void
F_20 ( T_10 * V_35 , T_1 * V_27 )
{
T_1 * V_36 , * V_37 , * V_38 , * V_39 ;
V_36 = ( T_1 * ) F_21 ( V_35 , V_27 -> V_6 ) ;
if ( NULL == V_36 ) {
V_27 -> V_40 = NULL ;
V_27 -> V_41 = V_27 ;
F_22 ( V_35 , V_27 -> V_6 , V_27 ) ;
}
else {
V_37 = V_36 -> V_41 ;
if( V_27 -> V_12 >= V_37 -> V_12 ) {
V_27 -> V_40 = NULL ;
V_27 -> V_41 = NULL ;
V_37 -> V_40 = V_27 ;
V_36 -> V_41 = V_27 ;
}
else {
V_38 = V_36 ;
V_39 = NULL ;
for (; ( V_27 -> V_12 > V_38 -> V_12 ) && V_38 -> V_40 ; V_39 = V_38 , V_38 = V_38 -> V_40 )
;
if ( NULL == V_39 ) {
V_27 -> V_40 = V_36 ;
V_27 -> V_41 = V_37 ;
V_36 -> V_41 = NULL ;
F_22 ( V_35 , V_27 -> V_6 , V_27 ) ;
}
else {
V_27 -> V_40 = V_38 ;
V_27 -> V_41 = NULL ;
V_39 -> V_40 = V_27 ;
}
}
}
}
void
F_23 ( T_10 * V_35 , T_1 * V_27 )
{
T_1 * V_36 , * V_38 , * V_39 ;
V_36 = ( T_1 * ) F_21 ( V_35 , V_27 -> V_6 ) ;
if ( V_27 == V_36 ) {
if ( NULL == V_27 -> V_40 ) {
F_24 ( V_35 , V_27 -> V_6 ) ;
}
else {
V_36 = V_27 -> V_40 ;
V_36 -> V_41 = V_27 -> V_41 ;
if ( V_27 -> V_42 == V_27 )
V_36 -> V_42 = NULL ;
else
V_36 -> V_42 = V_27 -> V_42 ;
F_22 ( V_35 , V_36 -> V_6 , V_36 ) ;
}
}
else {
V_38 = V_36 -> V_40 ;
V_39 = V_36 ;
for (; ( V_38 != V_27 ) && V_38 -> V_40 ; V_39 = V_38 , V_38 = V_38 -> V_40 )
;
if ( V_38 != V_27 ) {
return;
}
V_39 -> V_40 = V_27 -> V_40 ;
if ( NULL == V_27 -> V_40 ) {
V_36 -> V_41 = V_39 ;
}
if ( V_36 -> V_42 == V_27 )
V_36 -> V_42 = V_39 ;
}
}
T_1 *
F_2 ( const T_3 V_12 , const T_2 * V_13 , const T_2 * V_2 , const T_11 V_7 ,
const T_3 V_14 , const T_3 V_3 , const T_4 V_4 )
{
T_10 * V_35 ;
T_1 * V_1 = NULL ;
T_6 * V_43 ;
if ( V_4 & V_10 ) {
if ( V_4 & ( V_11 | V_44 ) ) {
V_35 = V_33 ;
} else {
V_35 = V_31 ;
}
} else {
if ( V_4 & ( V_11 | V_44 ) ) {
V_35 = V_32 ;
} else {
V_35 = V_30 ;
}
}
V_43 = F_25 ( struct T_6 ) ;
V_43 -> V_40 = V_29 ;
V_29 = V_43 ;
F_26 ( & V_43 -> V_13 , V_13 ) ;
F_26 ( & V_43 -> V_2 , V_2 ) ;
V_43 -> V_7 = V_7 ;
V_43 -> V_14 = V_14 ;
V_43 -> V_3 = V_3 ;
V_1 = F_25 ( T_1 ) ;
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
V_1 -> V_45 = V_34 ;
V_1 -> V_12 = V_1 -> V_46 = V_12 ;
V_1 -> V_28 = NULL ;
V_1 -> V_15 = NULL ;
V_1 -> V_4 = V_4 ;
V_1 -> V_6 = V_43 ;
V_34 ++ ;
F_20 ( V_35 , V_1 ) ;
return V_1 ;
}
void
F_27 ( T_1 * V_27 , const T_3 V_47 )
{
F_28 ( ! ( V_27 -> V_4 & V_5 ) ,
L_1 ) ;
if ( ( ! ( V_27 -> V_4 & V_11 ) ) || ( V_27 -> V_4 & V_44 ) )
return;
if ( V_27 -> V_4 & V_10 ) {
F_23 ( V_33 , V_27 ) ;
} else {
F_23 ( V_32 , V_27 ) ;
}
V_27 -> V_4 &= ~ V_11 ;
V_27 -> V_6 -> V_3 = V_47 ;
if ( V_27 -> V_4 & V_10 ) {
F_20 ( V_31 , V_27 ) ;
} else {
F_20 ( V_30 , V_27 ) ;
}
}
void
F_29 ( T_1 * V_27 , const T_2 * V_48 )
{
F_28 ( ! ( V_27 -> V_4 & V_5 ) ,
L_1 ) ;
if ( ! ( V_27 -> V_4 & V_10 ) )
return;
if ( V_27 -> V_4 & V_11 ) {
F_23 ( V_33 , V_27 ) ;
} else {
F_23 ( V_32 , V_27 ) ;
}
V_27 -> V_4 &= ~ V_10 ;
F_26 ( & V_27 -> V_6 -> V_2 , V_48 ) ;
if ( V_27 -> V_4 & V_11 ) {
F_20 ( V_32 , V_27 ) ;
} else {
F_20 ( V_30 , V_27 ) ;
}
}
static T_1 *
F_30 ( T_10 * V_35 , const T_3 V_49 , const T_2 * V_13 , const T_2 * V_2 ,
const T_11 V_7 , const T_3 V_14 , const T_3 V_3 )
{
T_1 * V_50 = NULL ;
T_1 * V_51 = NULL ;
T_1 * V_36 = NULL ;
T_6 V_17 ;
V_17 . V_13 = * V_13 ;
V_17 . V_2 = * V_2 ;
V_17 . V_7 = V_7 ;
V_17 . V_14 = V_14 ;
V_17 . V_3 = V_3 ;
V_36 = ( T_1 * ) F_21 ( V_35 , & V_17 ) ;
if ( V_36 && ( V_36 -> V_12 <= V_49 ) ) {
V_51 = V_36 ;
if( ( V_36 -> V_41 ) && ( V_36 -> V_41 -> V_12 <= V_49 ) )
return V_36 -> V_41 ;
if( ( V_36 -> V_42 ) && ( V_36 -> V_42 -> V_12 <= V_49 ) )
V_51 = V_36 -> V_42 ;
for ( V_50 = V_51 ; V_50 && V_50 -> V_12 <= V_49 ; V_50 = V_50 -> V_40 ) {
if ( V_50 -> V_12 > V_51 -> V_12 ) {
V_51 = V_50 ;
}
}
}
if ( V_51 )
V_36 -> V_42 = V_51 ;
return V_51 ;
}
T_1 *
F_31 ( const T_3 V_49 , const T_2 * V_52 , const T_2 * V_53 , const T_11 V_7 ,
const T_3 V_54 , const T_3 V_55 , const T_4 V_4 )
{
T_1 * V_1 ;
if ( ! ( V_4 & ( V_56 | V_57 ) ) ) {
V_1 =
F_30 ( V_30 ,
V_49 , V_52 , V_53 , V_7 ,
V_54 , V_55 ) ;
if ( V_1 == NULL ) {
V_1 =
F_30 ( V_30 ,
V_49 , V_53 , V_52 , V_7 ,
V_55 , V_54 ) ;
}
if ( ( V_1 == NULL ) && ( V_52 -> type == V_58 ) ) {
V_1 =
F_30 ( V_30 ,
V_49 , V_53 , V_52 , V_7 ,
V_54 , V_55 ) ;
}
if ( V_1 != NULL )
return V_1 ;
}
if ( ! ( V_4 & V_57 ) ) {
V_1 =
F_30 ( V_31 ,
V_49 , V_52 , V_53 , V_7 , V_54 , V_55 ) ;
if ( ( V_1 == NULL ) && ( V_52 -> type == V_58 ) ) {
V_1 =
F_30 ( V_31 ,
V_49 , V_53 , V_52 , V_7 ,
V_54 , V_55 ) ;
}
if ( V_1 != NULL ) {
if ( ! ( V_1 -> V_4 & V_56 ) && V_7 != V_8 )
{
if( ! ( V_1 -> V_4 & V_5 ) )
{
F_29 ( V_1 , V_53 ) ;
}
else
{
V_1 =
F_1 ( V_1 , V_53 , 0 ) ;
}
}
return V_1 ;
}
if ( ! ( V_4 & V_56 ) ) {
V_1 =
F_30 ( V_31 ,
V_49 , V_53 , V_52 , V_7 , V_55 , V_54 ) ;
if ( V_1 != NULL ) {
if ( V_7 != V_8 ) {
if( ! ( V_1 -> V_4 & V_5 ) )
{
F_29 ( V_1 , V_52 ) ;
}
else
{
V_1 =
F_1 ( V_1 , V_52 , 0 ) ;
}
}
return V_1 ;
}
}
}
if ( ! ( V_4 & V_56 ) ) {
V_1 =
F_30 ( V_32 ,
V_49 , V_52 , V_53 , V_7 , V_54 , V_55 ) ;
if ( ( V_1 == NULL ) && ( V_52 -> type == V_58 ) ) {
V_1 =
F_30 ( V_32 ,
V_49 , V_53 , V_52 , V_7 , V_54 , V_55 ) ;
}
if ( V_1 != NULL ) {
if ( ! ( V_1 -> V_4 & V_57 ) && V_7 != V_8 )
{
if( ! ( V_1 -> V_4 & V_5 ) )
{
F_27 ( V_1 , V_55 ) ;
}
else
{
V_1 =
F_1 ( V_1 , 0 , V_55 ) ;
}
}
return V_1 ;
}
if ( ! ( V_4 & V_57 ) ) {
V_1 =
F_30 ( V_32 ,
V_49 , V_53 , V_52 , V_7 , V_55 , V_54 ) ;
if ( V_1 != NULL ) {
if ( V_7 != V_8 )
{
if( ! ( V_1 -> V_4 & V_5 ) )
{
F_27 ( V_1 , V_54 ) ;
}
else
{
V_1 =
F_1 ( V_1 , 0 , V_54 ) ;
}
}
return V_1 ;
}
}
}
V_1 =
F_30 ( V_33 ,
V_49 , V_52 , V_53 , V_7 , V_54 , V_55 ) ;
if ( V_1 != NULL ) {
if ( V_7 != V_8 )
{
if( ! ( V_1 -> V_4 & V_5 ) )
{
if ( ! ( V_1 -> V_4 & V_56 ) )
F_29 ( V_1 , V_53 ) ;
if ( ! ( V_1 -> V_4 & V_57 ) )
F_27 ( V_1 , V_55 ) ;
}
else
{
V_1 =
F_1 ( V_1 , V_53 , V_55 ) ;
}
}
return V_1 ;
}
if ( V_52 -> type == V_58 )
V_1 =
F_30 ( V_33 ,
V_49 , V_53 , V_52 , V_7 , V_54 , V_55 ) ;
else
V_1 =
F_30 ( V_33 ,
V_49 , V_53 , V_52 , V_7 , V_55 , V_54 ) ;
if ( V_1 != NULL ) {
if ( V_7 != V_8 )
{
if( ! ( V_1 -> V_4 & V_5 ) )
{
F_29 ( V_1 , V_52 ) ;
F_27 ( V_1 , V_54 ) ;
}
else
{
V_1 = F_1 ( V_1 , V_52 , V_54 ) ;
}
}
return V_1 ;
}
return NULL ;
}
static T_7
F_32 ( T_5 V_59 , T_5 V_60 )
{
const T_12 * V_61 = ( const T_12 * ) V_59 ;
const T_12 * V_62 = ( const T_12 * ) V_60 ;
if ( V_61 -> V_63 > V_62 -> V_63 )
return 1 ;
else if ( V_61 -> V_63 == V_62 -> V_63 )
return 0 ;
else
return - 1 ;
}
void
F_33 ( T_1 * V_27 , const int V_63 , void * V_64 )
{
T_12 * V_65 = F_25 ( T_12 ) ;
V_65 -> V_63 = V_63 ;
V_65 -> V_64 = V_64 ;
V_27 -> V_28 = F_34 ( V_27 -> V_28 , ( T_8 * ) V_65 ,
F_32 ) ;
}
void *
F_35 ( const T_1 * V_27 , const int V_63 )
{
T_12 V_66 , * V_65 ;
T_13 * V_67 ;
V_66 . V_63 = V_63 ;
V_66 . V_64 = NULL ;
V_67 = F_36 ( V_27 -> V_28 , ( T_8 * ) & V_66 ,
F_32 ) ;
if ( V_67 != NULL ) {
V_65 = ( T_12 * ) V_67 -> V_21 ;
return V_65 -> V_64 ;
}
return NULL ;
}
void
F_37 ( T_1 * V_27 , const int V_63 )
{
T_12 V_66 ;
T_13 * V_67 ;
V_66 . V_63 = V_63 ;
V_66 . V_64 = NULL ;
V_67 = F_36 ( V_27 -> V_28 , ( T_8 * ) & V_66 ,
F_32 ) ;
while( V_67 ) {
V_27 -> V_28 = F_38 ( V_27 -> V_28 , V_67 -> V_21 ) ;
V_67 = V_67 -> V_40 ;
}
}
void
F_39 ( T_1 * V_1 , const T_14 V_68 )
{
V_1 -> V_15 = V_68 ;
}
T_15
F_40 ( const T_2 * V_52 , const T_2 * V_53 , const T_11 V_7 ,
const T_3 V_54 , const T_3 V_55 , T_16 * V_69 , T_17 * V_70 ,
T_18 * V_71 )
{
T_1 * V_1 ;
V_1 = F_31 ( V_70 -> V_72 -> V_73 , V_52 , V_53 , V_7 , V_54 ,
V_55 , 0 ) ;
if ( V_1 != NULL ) {
int V_74 ;
if ( V_1 -> V_15 == NULL )
return FALSE ;
V_74 = F_41 ( V_1 -> V_15 , V_69 , V_70 ,
V_71 , NULL ) ;
if( ! V_74 ) {
return FALSE ;
}
return TRUE ;
}
return FALSE ;
}
T_1 *
F_42 ( T_17 * V_70 )
{
T_1 * V_27 = NULL ;
if( ( V_27 = F_31 ( V_70 -> V_72 -> V_73 , & V_70 -> V_75 , & V_70 -> V_76 ,
V_70 -> V_7 , V_70 -> V_77 ,
V_70 -> V_78 , 0 ) ) != NULL ) {
if ( V_70 -> V_72 -> V_73 > V_27 -> V_46 ) {
V_27 -> V_46 = V_70 -> V_72 -> V_73 ;
}
} else {
V_27 = F_2 ( V_70 -> V_72 -> V_73 , & V_70 -> V_75 ,
& V_70 -> V_76 , V_70 -> V_7 ,
V_70 -> V_77 , V_70 -> V_78 , 0 ) ;
}
return V_27 ;
}
T_10 *
F_43 ( void )
{
return V_30 ;
}
T_10 *
F_44 ( void )
{
return V_31 ;
}
T_10 *
F_45 ( void )
{
return V_32 ;
}
T_10 *
F_46 ( void )
{
return V_33 ;
}
