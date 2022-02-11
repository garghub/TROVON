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
V_18 = 0 ;
F_4 ( V_18 , & V_17 -> V_13 ) ;
V_18 += V_17 -> V_14 ;
F_4 ( V_18 , & V_17 -> V_2 ) ;
V_18 += V_17 -> V_3 ;
return V_18 ;
}
static T_7
F_5 ( T_5 V_16 , T_5 V_19 )
{
const T_6 * V_20 = ( const T_6 * ) V_16 ;
const T_6 * V_21 = ( const T_6 * ) V_19 ;
if ( V_20 -> V_7 != V_21 -> V_7 )
return 0 ;
if ( V_20 -> V_14 == V_21 -> V_14 &&
V_20 -> V_3 == V_21 -> V_3 &&
F_6 ( & V_20 -> V_13 , & V_21 -> V_13 ) &&
F_6 ( & V_20 -> V_2 , & V_21 -> V_2 ) ) {
return 1 ;
}
if ( V_20 -> V_3 == V_21 -> V_14 &&
V_20 -> V_14 == V_21 -> V_3 &&
F_6 ( & V_20 -> V_2 , & V_21 -> V_13 ) &&
F_6 ( & V_20 -> V_13 , & V_21 -> V_2 ) ) {
return 1 ;
}
return 0 ;
}
static T_4
F_7 ( T_5 V_16 )
{
const T_6 * V_17 = ( const T_6 * ) V_16 ;
T_4 V_18 ;
V_18 = 0 ;
F_4 ( V_18 , & V_17 -> V_13 ) ;
V_18 += V_17 -> V_14 ;
V_18 += V_17 -> V_3 ;
return V_18 ;
}
static T_7
F_8 ( T_5 V_16 , T_5 V_19 )
{
const T_6 * V_20 = ( const T_6 * ) V_16 ;
const T_6 * V_21 = ( const T_6 * ) V_19 ;
if ( V_20 -> V_7 != V_21 -> V_7 )
return 0 ;
if ( V_20 -> V_14 == V_21 -> V_14 &&
V_20 -> V_3 == V_21 -> V_3 &&
F_6 ( & V_20 -> V_13 , & V_21 -> V_13 ) ) {
return 1 ;
}
return 0 ;
}
static T_4
F_9 ( T_5 V_16 )
{
const T_6 * V_17 = ( const T_6 * ) V_16 ;
T_4 V_18 ;
V_18 = 0 ;
F_4 ( V_18 , & V_17 -> V_13 ) ;
V_18 += V_17 -> V_14 ;
F_4 ( V_18 , & V_17 -> V_2 ) ;
return V_18 ;
}
static T_7
F_10 ( T_5 V_16 , T_5 V_19 )
{
const T_6 * V_20 = ( const T_6 * ) V_16 ;
const T_6 * V_21 = ( const T_6 * ) V_19 ;
if ( V_20 -> V_7 != V_21 -> V_7 )
return 0 ;
if ( V_20 -> V_14 == V_21 -> V_14 &&
F_6 ( & V_20 -> V_13 , & V_21 -> V_13 ) &&
F_6 ( & V_20 -> V_2 , & V_21 -> V_2 ) ) {
return 1 ;
}
return 0 ;
}
static T_4
F_11 ( T_5 V_16 )
{
const T_6 * V_17 = ( const T_6 * ) V_16 ;
T_4 V_18 ;
V_18 = 0 ;
F_4 ( V_18 , & V_17 -> V_13 ) ;
V_18 += V_17 -> V_14 ;
return V_18 ;
}
static T_7
F_12 ( T_5 V_16 , T_5 V_19 )
{
const T_6 * V_20 = ( const T_6 * ) V_16 ;
const T_6 * V_21 = ( const T_6 * ) V_19 ;
if ( V_20 -> V_7 != V_21 -> V_7 )
return 0 ;
if ( V_20 -> V_14 == V_21 -> V_14 &&
F_6 ( & V_20 -> V_13 , & V_21 -> V_13 ) ) {
return 1 ;
}
return 0 ;
}
static void
F_13 ( T_8 V_17 V_22 , T_8 V_23 , T_8 T_9 V_22 )
{
T_1 * V_24 = ( T_1 * ) V_23 ;
F_14 ( V_24 -> V_25 ) ;
V_24 -> V_25 = NULL ;
}
void
F_15 ( void )
{
V_26 = NULL ;
if ( V_27 != NULL ) {
F_16 ( V_27 , F_13 , NULL ) ;
F_17 ( V_27 ) ;
}
if ( V_28 != NULL ) {
F_16 ( V_28 , F_13 , NULL ) ;
F_17 ( V_28 ) ;
}
if ( V_29 != NULL ) {
F_16 ( V_29 , F_13 , NULL ) ;
F_17 ( V_29 ) ;
}
if ( V_30 != NULL ) {
F_16 ( V_30 , F_13 , NULL ) ;
F_17 ( V_30 ) ;
}
V_27 = NULL ;
V_28 = NULL ;
V_29 = NULL ;
V_30 = NULL ;
}
void
F_18 ( void )
{
V_27 =
F_19 ( F_3 ,
F_5 ) ;
V_28 =
F_19 ( F_7 ,
F_8 ) ;
V_29 =
F_19 ( F_9 ,
F_10 ) ;
V_30 =
F_19 ( F_11 ,
F_12 ) ;
V_31 = 0 ;
}
void
F_20 ( T_10 * V_32 , T_1 * V_24 )
{
T_1 * V_33 , * V_34 , * V_35 , * V_36 ;
V_33 = ( T_1 * ) F_21 ( V_32 , V_24 -> V_6 ) ;
if ( NULL == V_33 ) {
V_24 -> V_37 = NULL ;
V_24 -> V_38 = V_24 ;
F_22 ( V_32 , V_24 -> V_6 , V_24 ) ;
}
else {
V_34 = V_33 -> V_38 ;
if( V_24 -> V_12 >= V_34 -> V_12 ) {
V_24 -> V_37 = NULL ;
V_24 -> V_38 = NULL ;
V_34 -> V_37 = V_24 ;
V_33 -> V_38 = V_24 ;
}
else {
V_35 = V_33 ;
V_36 = NULL ;
for (; ( V_24 -> V_12 > V_35 -> V_12 ) && V_35 -> V_37 ; V_36 = V_35 , V_35 = V_35 -> V_37 )
;
if ( NULL == V_36 ) {
V_24 -> V_37 = V_33 ;
V_24 -> V_38 = V_34 ;
V_33 -> V_38 = NULL ;
F_22 ( V_32 , V_24 -> V_6 , V_24 ) ;
}
else {
V_24 -> V_37 = V_35 ;
V_24 -> V_38 = NULL ;
V_36 -> V_37 = V_24 ;
}
}
}
}
void
F_23 ( T_10 * V_32 , T_1 * V_24 )
{
T_1 * V_33 , * V_35 , * V_36 ;
V_33 = ( T_1 * ) F_21 ( V_32 , V_24 -> V_6 ) ;
if ( V_24 == V_33 ) {
if ( NULL == V_24 -> V_37 ) {
F_24 ( V_32 , V_24 -> V_6 ) ;
}
else {
V_33 = V_24 -> V_37 ;
V_33 -> V_38 = V_24 -> V_38 ;
if ( V_24 -> V_39 == V_24 )
V_33 -> V_39 = NULL ;
else
V_33 -> V_39 = V_24 -> V_39 ;
F_22 ( V_32 , V_33 -> V_6 , V_33 ) ;
}
}
else {
V_35 = V_33 -> V_37 ;
V_36 = V_33 ;
for (; ( V_35 != V_24 ) && V_35 -> V_37 ; V_36 = V_35 , V_35 = V_35 -> V_37 )
;
if ( V_35 != V_24 ) {
return;
}
V_36 -> V_37 = V_24 -> V_37 ;
if ( NULL == V_24 -> V_37 ) {
V_33 -> V_38 = V_36 ;
}
if ( V_33 -> V_39 == V_24 )
V_33 -> V_39 = V_36 ;
}
}
T_1 *
F_2 ( const T_3 V_12 , const T_2 * V_13 , const T_2 * V_2 , const T_11 V_7 ,
const T_3 V_14 , const T_3 V_3 , const T_4 V_4 )
{
T_10 * V_32 ;
T_1 * V_1 = NULL ;
T_6 * V_40 ;
if ( V_4 & V_10 ) {
if ( V_4 & ( V_11 | V_41 ) ) {
V_32 = V_30 ;
} else {
V_32 = V_28 ;
}
} else {
if ( V_4 & ( V_11 | V_41 ) ) {
V_32 = V_29 ;
} else {
V_32 = V_27 ;
}
}
V_40 = F_25 ( struct T_6 ) ;
V_40 -> V_37 = V_26 ;
V_26 = V_40 ;
F_26 ( & V_40 -> V_13 , V_13 ) ;
F_26 ( & V_40 -> V_2 , V_2 ) ;
V_40 -> V_7 = V_7 ;
V_40 -> V_14 = V_14 ;
V_40 -> V_3 = V_3 ;
V_1 = F_25 ( T_1 ) ;
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
V_1 -> V_42 = V_31 ;
V_1 -> V_12 = V_12 ;
V_1 -> V_25 = NULL ;
V_1 -> V_15 = NULL ;
V_1 -> V_4 = V_4 ;
V_1 -> V_6 = V_40 ;
V_31 ++ ;
F_20 ( V_32 , V_1 ) ;
return V_1 ;
}
void
F_27 ( T_1 * V_24 , const T_3 V_43 )
{
F_28 ( ! ( V_24 -> V_4 & V_5 ) ,
L_1 ) ;
if ( ( ! ( V_24 -> V_4 & V_11 ) ) || ( V_24 -> V_4 & V_41 ) )
return;
if ( V_24 -> V_4 & V_10 ) {
F_23 ( V_30 , V_24 ) ;
} else {
F_23 ( V_29 , V_24 ) ;
}
V_24 -> V_4 &= ~ V_11 ;
V_24 -> V_6 -> V_3 = V_43 ;
if ( V_24 -> V_4 & V_10 ) {
F_20 ( V_28 , V_24 ) ;
} else {
F_20 ( V_27 , V_24 ) ;
}
}
void
F_29 ( T_1 * V_24 , const T_2 * V_44 )
{
F_28 ( ! ( V_24 -> V_4 & V_5 ) ,
L_1 ) ;
if ( ! ( V_24 -> V_4 & V_10 ) )
return;
if ( V_24 -> V_4 & V_11 ) {
F_23 ( V_30 , V_24 ) ;
} else {
F_23 ( V_29 , V_24 ) ;
}
V_24 -> V_4 &= ~ V_10 ;
F_26 ( & V_24 -> V_6 -> V_2 , V_44 ) ;
if ( V_24 -> V_4 & V_11 ) {
F_20 ( V_29 , V_24 ) ;
} else {
F_20 ( V_27 , V_24 ) ;
}
}
static T_1 *
F_30 ( T_10 * V_32 , const T_3 V_45 , const T_2 * V_13 , const T_2 * V_2 ,
const T_11 V_7 , const T_3 V_14 , const T_3 V_3 )
{
T_1 * V_46 = NULL ;
T_1 * V_47 = NULL ;
T_1 * V_33 = NULL ;
T_6 V_17 ;
V_17 . V_13 = * V_13 ;
V_17 . V_2 = * V_2 ;
V_17 . V_7 = V_7 ;
V_17 . V_14 = V_14 ;
V_17 . V_3 = V_3 ;
V_33 = ( T_1 * ) F_21 ( V_32 , & V_17 ) ;
if ( V_33 && ( V_33 -> V_12 <= V_45 ) ) {
V_47 = V_33 ;
if( ( V_33 -> V_38 ) && ( V_33 -> V_38 -> V_12 <= V_45 ) )
return V_33 -> V_38 ;
if( ( V_33 -> V_39 ) && ( V_33 -> V_39 -> V_12 <= V_45 ) )
V_47 = V_33 -> V_39 ;
for ( V_46 = V_47 ; V_46 && V_46 -> V_12 <= V_45 ; V_46 = V_46 -> V_37 ) {
if ( V_46 -> V_12 > V_47 -> V_12 ) {
V_47 = V_46 ;
}
}
}
if ( V_47 )
V_33 -> V_39 = V_47 ;
return V_47 ;
}
T_1 *
F_31 ( const T_3 V_45 , const T_2 * V_48 , const T_2 * V_49 , const T_11 V_7 ,
const T_3 V_50 , const T_3 V_51 , const T_4 V_4 )
{
T_1 * V_1 ;
if ( ! ( V_4 & ( V_52 | V_53 ) ) ) {
V_1 =
F_30 ( V_27 ,
V_45 , V_48 , V_49 , V_7 ,
V_50 , V_51 ) ;
if ( ( V_1 == NULL ) && ( V_48 -> type == V_54 ) ) {
V_1 =
F_30 ( V_27 ,
V_45 , V_49 , V_48 , V_7 ,
V_50 , V_51 ) ;
}
if ( V_1 != NULL )
return V_1 ;
}
if ( ! ( V_4 & V_53 ) ) {
V_1 =
F_30 ( V_28 ,
V_45 , V_48 , V_49 , V_7 , V_50 , V_51 ) ;
if ( ( V_1 == NULL ) && ( V_48 -> type == V_54 ) ) {
V_1 =
F_30 ( V_28 ,
V_45 , V_49 , V_48 , V_7 ,
V_50 , V_51 ) ;
}
if ( V_1 != NULL ) {
if ( ! ( V_1 -> V_4 & V_52 ) && V_7 != V_8 )
{
if( ! ( V_1 -> V_4 & V_5 ) )
{
F_29 ( V_1 , V_49 ) ;
}
else
{
V_1 =
F_1 ( V_1 , V_49 , 0 ) ;
}
}
return V_1 ;
}
if ( ! ( V_4 & V_52 ) ) {
V_1 =
F_30 ( V_28 ,
V_45 , V_49 , V_48 , V_7 , V_51 , V_50 ) ;
if ( V_1 != NULL ) {
if ( V_7 != V_8 ) {
if( ! ( V_1 -> V_4 & V_5 ) )
{
F_29 ( V_1 , V_48 ) ;
}
else
{
V_1 =
F_1 ( V_1 , V_48 , 0 ) ;
}
}
return V_1 ;
}
}
}
if ( ! ( V_4 & V_52 ) ) {
V_1 =
F_30 ( V_29 ,
V_45 , V_48 , V_49 , V_7 , V_50 , V_51 ) ;
if ( ( V_1 == NULL ) && ( V_48 -> type == V_54 ) ) {
V_1 =
F_30 ( V_29 ,
V_45 , V_49 , V_48 , V_7 , V_50 , V_51 ) ;
}
if ( V_1 != NULL ) {
if ( ! ( V_1 -> V_4 & V_53 ) && V_7 != V_8 )
{
if( ! ( V_1 -> V_4 & V_5 ) )
{
F_27 ( V_1 , V_51 ) ;
}
else
{
V_1 =
F_1 ( V_1 , 0 , V_51 ) ;
}
}
return V_1 ;
}
if ( ! ( V_4 & V_53 ) ) {
V_1 =
F_30 ( V_29 ,
V_45 , V_49 , V_48 , V_7 , V_51 , V_50 ) ;
if ( V_1 != NULL ) {
if ( V_7 != V_8 )
{
if( ! ( V_1 -> V_4 & V_5 ) )
{
F_27 ( V_1 , V_50 ) ;
}
else
{
V_1 =
F_1 ( V_1 , 0 , V_50 ) ;
}
}
return V_1 ;
}
}
}
V_1 =
F_30 ( V_30 ,
V_45 , V_48 , V_49 , V_7 , V_50 , V_51 ) ;
if ( V_1 != NULL ) {
if ( V_7 != V_8 )
{
if( ! ( V_1 -> V_4 & V_5 ) )
{
if ( ! ( V_1 -> V_4 & V_52 ) )
F_29 ( V_1 , V_49 ) ;
if ( ! ( V_1 -> V_4 & V_53 ) )
F_27 ( V_1 , V_51 ) ;
}
else
{
V_1 =
F_1 ( V_1 , V_49 , V_51 ) ;
}
}
return V_1 ;
}
if ( V_48 -> type == V_54 )
V_1 =
F_30 ( V_30 ,
V_45 , V_49 , V_48 , V_7 , V_50 , V_51 ) ;
else
V_1 =
F_30 ( V_30 ,
V_45 , V_49 , V_48 , V_7 , V_51 , V_50 ) ;
if ( V_1 != NULL ) {
if ( V_7 != V_8 )
{
if( ! ( V_1 -> V_4 & V_5 ) )
{
F_29 ( V_1 , V_48 ) ;
F_27 ( V_1 , V_50 ) ;
}
else
{
V_1 = F_1 ( V_1 , V_48 , V_50 ) ;
}
}
return V_1 ;
}
return NULL ;
}
static T_7
F_32 ( T_5 V_55 , T_5 V_56 )
{
const T_12 * V_57 = ( const T_12 * ) V_55 ;
const T_12 * V_58 = ( const T_12 * ) V_56 ;
if ( V_57 -> V_59 > V_58 -> V_59 )
return 1 ;
else if ( V_57 -> V_59 == V_58 -> V_59 )
return 0 ;
else
return - 1 ;
}
void
F_33 ( T_1 * V_24 , const int V_59 , void * V_60 )
{
T_12 * V_61 = F_25 ( T_12 ) ;
V_61 -> V_59 = V_59 ;
V_61 -> V_60 = V_60 ;
V_24 -> V_25 = F_34 ( V_24 -> V_25 , ( T_8 * ) V_61 ,
F_32 ) ;
}
void *
F_35 ( const T_1 * V_24 , const int V_59 )
{
T_12 V_62 , * V_61 ;
T_13 * V_63 ;
V_62 . V_59 = V_59 ;
V_62 . V_60 = NULL ;
V_63 = F_36 ( V_24 -> V_25 , ( T_8 * ) & V_62 ,
F_32 ) ;
if ( V_63 != NULL ) {
V_61 = ( T_12 * ) V_63 -> V_64 ;
return V_61 -> V_60 ;
}
return NULL ;
}
void
F_37 ( T_1 * V_24 , const int V_59 )
{
T_12 V_62 ;
T_13 * V_63 ;
V_62 . V_59 = V_59 ;
V_62 . V_60 = NULL ;
V_63 = F_36 ( V_24 -> V_25 , ( T_8 * ) & V_62 ,
F_32 ) ;
while( V_63 ) {
V_24 -> V_25 = F_38 ( V_24 -> V_25 , V_63 -> V_64 ) ;
V_63 = V_63 -> V_37 ;
}
}
void
F_39 ( T_1 * V_1 , const T_14 V_65 )
{
V_1 -> V_15 = V_65 ;
}
T_15
F_40 ( const T_2 * V_48 , const T_2 * V_49 , const T_11 V_7 ,
const T_3 V_50 , const T_3 V_51 , T_16 * V_66 , T_17 * V_67 ,
T_18 * V_68 )
{
T_1 * V_1 ;
V_1 = F_31 ( V_67 -> V_69 -> V_70 , V_48 , V_49 , V_7 , V_50 ,
V_51 , 0 ) ;
if ( V_1 != NULL ) {
int V_71 ;
if ( V_1 -> V_15 == NULL )
return FALSE ;
V_71 = F_41 ( V_1 -> V_15 , V_66 , V_67 ,
V_68 , NULL ) ;
if( ! V_71 ) {
return FALSE ;
}
return TRUE ;
}
return FALSE ;
}
T_1 *
F_42 ( T_17 * V_67 )
{
T_1 * V_24 = NULL ;
if( ( V_24 = F_31 ( V_67 -> V_69 -> V_70 , & V_67 -> V_72 , & V_67 -> V_73 ,
V_67 -> V_7 , V_67 -> V_74 ,
V_67 -> V_75 , 0 ) ) == NULL ) {
V_24 = F_2 ( V_67 -> V_69 -> V_70 , & V_67 -> V_72 ,
& V_67 -> V_73 , V_67 -> V_7 ,
V_67 -> V_74 , V_67 -> V_75 , 0 ) ;
}
return V_24 ;
}
