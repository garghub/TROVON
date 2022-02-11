static T_1
F_1 ( T_2 V_1 )
{
const T_3 * V_2 = ( const T_3 * ) V_1 ;
T_1 V_3 ;
V_3 = 0 ;
V_3 += V_2 -> V_4 ;
return V_3 ;
}
static T_4
F_2 ( T_2 V_5 , T_2 V_6 )
{
const T_3 * V_7 = ( const T_3 * ) V_5 ;
const T_3 * V_8 = ( const T_3 * ) V_6 ;
return ( V_7 -> V_4 == V_8 -> V_4 ) &&
( F_3 ( & V_7 -> V_9 , & V_8 -> V_9 ) ) &&
( F_3 ( & V_7 -> V_10 , & V_8 -> V_10 ) ) ;
}
static T_5
F_4 ( const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 V_12 )
{
T_3 * V_2 = F_5 ( T_3 ) ;
V_2 -> V_9 = V_11 -> V_9 ;
V_2 -> V_10 = V_11 -> V_10 ;
V_2 -> V_4 = V_4 ;
return ( T_5 ) V_2 ;
}
static T_5
F_6 ( const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 V_12 )
{
T_3 * V_2 = F_5 ( T_3 ) ;
F_7 ( & V_2 -> V_9 , & V_11 -> V_9 ) ;
F_7 ( & V_2 -> V_10 , & V_11 -> V_10 ) ;
V_2 -> V_4 = V_4 ;
return ( T_5 ) V_2 ;
}
static void
F_8 ( T_5 V_13 )
{
T_3 * V_2 = ( T_3 * ) V_13 ;
if( V_2 )
F_9 ( T_3 , V_2 ) ;
}
static void
F_10 ( T_5 V_13 )
{
T_3 * V_2 = ( T_3 * ) V_13 ;
if( V_2 ) {
F_11 ( ( T_5 ) V_2 -> V_9 . T_8 ) ;
F_11 ( ( T_5 ) V_2 -> V_10 . T_8 ) ;
F_9 ( T_3 , V_2 ) ;
}
}
static T_1
F_12 ( T_2 V_1 )
{
const T_9 * V_2 = ( const T_9 * ) V_1 ;
T_1 V_3 ;
V_3 = 0 ;
V_3 += V_2 -> V_4 ;
return V_3 ;
}
static T_4
F_13 ( T_2 V_5 , T_2 V_6 )
{
const T_9 * V_7 = ( const T_9 * ) V_5 ;
const T_9 * V_8 = ( const T_9 * ) V_6 ;
return ( V_7 -> V_4 == V_8 -> V_4 ) &&
( F_3 ( & V_7 -> V_14 , & V_8 -> V_14 ) ) &&
( F_3 ( & V_7 -> V_15 , & V_8 -> V_15 ) ) &&
( V_7 -> V_16 == V_8 -> V_16 ) &&
( V_7 -> V_17 == V_8 -> V_17 ) ;
}
static T_5
F_14 ( const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 V_12 )
{
T_9 * V_2 = F_5 ( T_9 ) ;
V_2 -> V_14 = V_11 -> V_9 ;
V_2 -> V_15 = V_11 -> V_10 ;
V_2 -> V_16 = V_11 -> V_18 ;
V_2 -> V_17 = V_11 -> V_19 ;
V_2 -> V_4 = V_4 ;
return ( T_5 ) V_2 ;
}
static T_5
F_15 ( const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 V_12 )
{
T_9 * V_2 = F_5 ( T_9 ) ;
F_7 ( & V_2 -> V_14 , & V_11 -> V_9 ) ;
F_7 ( & V_2 -> V_15 , & V_11 -> V_10 ) ;
V_2 -> V_16 = V_11 -> V_18 ;
V_2 -> V_17 = V_11 -> V_19 ;
V_2 -> V_4 = V_4 ;
return ( T_5 ) V_2 ;
}
static void
F_16 ( T_5 V_13 )
{
T_9 * V_2 = ( T_9 * ) V_13 ;
if( V_2 )
F_9 ( T_9 , V_2 ) ;
}
static void
F_17 ( T_5 V_13 )
{
T_9 * V_2 = ( T_9 * ) V_13 ;
if( V_2 ) {
F_11 ( ( T_5 ) V_2 -> V_14 . T_8 ) ;
F_11 ( ( T_5 ) V_2 -> V_15 . T_8 ) ;
F_9 ( T_9 , V_2 ) ;
}
}
static T_4
F_18 ( T_2 V_5 , T_2 V_6 )
{
const T_10 * V_7 = ( const T_10 * ) V_5 ;
const T_10 * V_8 = ( const T_10 * ) V_6 ;
return V_7 -> V_20 == V_8 -> V_20 && V_7 -> V_4 == V_8 -> V_4 ;
}
static T_1
F_19 ( T_2 V_1 )
{
const T_10 * V_2 = ( const T_10 * ) V_1 ;
return V_2 -> V_20 ;
}
static void
F_20 ( T_5 V_13 )
{
F_9 ( T_10 , ( T_10 * ) V_13 ) ;
}
static T_11
F_21 ( T_5 T_12 V_12 , T_5 V_21 , T_5 T_13 V_12 )
{
T_14 * V_22 ;
T_15 * V_23 ;
for ( V_22 = ( T_14 * ) V_21 ; V_22 != NULL ; V_22 = V_23 ) {
V_23 = V_22 -> V_24 ;
if( V_22 -> V_25 && ! ( V_22 -> V_26 & V_27 ) )
F_22 ( V_22 -> V_25 ) ;
F_9 ( T_15 , V_22 ) ;
}
return TRUE ;
}
static T_14 * F_23 ( const T_7 V_26 )
{
T_14 * V_22 ;
V_22 = F_24 ( T_14 ) ;
V_22 -> V_26 = V_26 ;
return V_22 ;
}
static T_11
F_25 ( T_5 T_12 V_12 , T_5 V_21 ,
T_5 T_13 )
{
T_16 * V_28 = ( T_16 * ) T_13 ;
T_14 * V_22 ;
for ( V_22 = ( T_14 * ) V_21 ; V_22 != NULL ; V_22 = V_22 -> V_24 ) {
if ( V_22 -> V_26 != V_29 ) {
if ( V_22 -> V_26 & V_27 )
V_22 -> V_25 = NULL ;
F_26 ( V_28 , V_22 ) ;
V_22 -> V_26 = V_29 ;
}
}
return TRUE ;
}
static void
F_27 ( T_5 T_8 , T_5 T_13 V_12 )
{
T_15 * V_22 = ( T_15 * ) T_8 ;
if ( V_22 -> V_25 )
F_22 ( V_22 -> V_25 ) ;
F_9 ( T_15 , V_22 ) ;
}
void
F_28 ( T_17 * V_30 ,
const T_18 * V_31 )
{
if ( V_30 -> V_32 == NULL )
V_30 -> V_32 = V_31 -> V_32 ;
if ( V_30 -> V_33 == NULL )
V_30 -> V_33 = V_31 -> V_33 ;
if ( V_30 -> V_34 == NULL )
V_30 -> V_34 = V_31 -> V_34 ;
if ( V_30 -> V_35 != NULL ) {
F_29 ( V_30 -> V_35 ,
F_21 , NULL ) ;
} else {
V_30 -> V_35 = F_30 ( V_31 -> V_36 ,
V_31 -> V_37 , V_31 -> V_38 , NULL ) ;
}
if ( V_30 -> V_39 != NULL ) {
T_16 * V_28 ;
V_28 = F_31 () ;
F_29 ( V_30 -> V_39 ,
F_25 , V_28 ) ;
F_32 ( V_28 , F_27 , NULL ) ;
F_33 ( V_28 , TRUE ) ;
} else {
V_30 -> V_39 = F_30 ( F_19 ,
F_18 , F_20 , NULL ) ;
}
}
void
F_34 ( T_17 * V_30 )
{
V_30 -> V_32 = NULL ;
V_30 -> V_33 = NULL ;
V_30 -> V_34 = NULL ;
if ( V_30 -> V_35 != NULL ) {
F_29 ( V_30 -> V_35 ,
F_21 , NULL ) ;
F_35 ( V_30 -> V_35 ) ;
V_30 -> V_35 = NULL ;
}
if ( V_30 -> V_39 != NULL ) {
T_16 * V_28 ;
V_28 = F_31 () ;
F_29 ( V_30 -> V_39 ,
F_25 , V_28 ) ;
F_32 ( V_28 , F_27 , NULL ) ;
F_33 ( V_28 , TRUE ) ;
F_35 ( V_30 -> V_39 ) ;
V_30 -> V_39 = NULL ;
}
}
static T_14 *
F_36 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 , T_5 * V_40 )
{
T_5 V_2 ;
T_5 V_21 ;
V_2 = V_30 -> V_32 ( V_11 , V_4 , T_8 ) ;
if ( ! F_37 ( V_30 -> V_35 , V_2 , V_40 ,
& V_21 ) )
V_21 = NULL ;
V_30 -> V_34 ( V_2 ) ;
return ( T_14 * ) V_21 ;
}
static T_5
F_38 ( T_17 * V_30 , T_14 * V_22 ,
const T_6 * V_11 , const T_7 V_4 , const void * T_8 )
{
T_5 V_2 ;
V_2 = V_30 -> V_33 ( V_11 , V_4 , T_8 ) ;
F_39 ( V_30 -> V_35 , V_2 , V_22 ) ;
return V_2 ;
}
T_19 *
F_40 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 )
{
T_14 * V_22 ;
T_15 * V_41 ;
T_19 * V_42 = NULL ;
T_5 V_2 ;
V_22 = F_36 ( V_30 , V_11 , V_4 , T_8 , & V_2 ) ;
if( V_22 == NULL ) {
return NULL ;
}
V_42 = V_22 -> V_25 ;
for( V_41 = V_22 -> V_24 ; V_41 ; ) {
T_15 * V_23 ;
V_23 = V_41 -> V_24 ;
if ( V_41 -> V_25 && ! ( V_41 -> V_26 & V_27 ) )
F_22 ( V_41 -> V_25 ) ;
F_9 ( T_15 , V_41 ) ;
V_41 = V_23 ;
}
F_9 ( T_14 , V_22 ) ;
F_41 ( V_30 -> V_35 , V_2 ) ;
return V_42 ;
}
T_14 *
F_42 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 )
{
return F_36 ( V_30 , V_11 , V_4 , T_8 , NULL ) ;
}
T_14 *
F_43 ( T_17 * V_30 , const T_7 V_4 )
{
T_14 * V_22 ;
T_10 V_2 ;
V_2 . V_20 = V_4 ;
V_2 . V_4 = V_4 ;
V_22 = ( T_14 * ) F_44 ( V_30 -> V_39 , & V_2 ) ;
return V_22 ;
}
T_14 *
F_45 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 )
{
T_14 * V_22 ;
T_10 V_2 ;
V_2 . V_20 = V_11 -> V_41 -> V_43 ;
V_2 . V_4 = V_4 ;
V_22 = ( T_14 * ) F_44 ( V_30 -> V_39 , & V_2 ) ;
return V_22 ;
}
void
F_46 ( T_17 * V_30 , const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 , const T_7 V_44 )
{
T_14 * V_22 ;
V_22 = F_36 ( V_30 , V_11 , V_4 , T_8 , NULL ) ;
if ( ! V_22 )
return;
if ( V_22 -> V_45 != 0 )
return;
V_22 -> V_45 = V_44 ;
}
void
F_47 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 , const T_7 V_46 )
{
T_14 * V_22 ;
T_15 * V_41 ;
T_7 V_47 = 0 ;
V_22 = F_36 ( V_30 , V_11 , V_4 , T_8 , NULL ) ;
if ( ! V_22 )
return;
V_41 = V_22 ;
if ( V_22 -> V_26 & V_48 ) {
while ( V_41 ) {
if ( V_41 -> V_49 > V_47 ) {
V_47 = V_41 -> V_49 ;
if ( V_47 > V_46 ) {
V_22 -> error = L_1 ;
F_48 ( V_50 , V_22 -> error ) ;
}
}
V_41 = V_41 -> V_24 ;
}
}
if ( V_22 -> V_26 & V_51 ) {
if ( V_47 != V_46 ) {
V_22 -> error = L_2 ;
F_48 ( V_50 , V_22 -> error ) ;
}
}
V_22 -> V_52 = V_46 ;
V_22 -> V_26 |= V_53 ;
}
T_7
F_49 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 )
{
T_14 * V_22 ;
V_22 = F_36 ( V_30 , V_11 , V_4 , T_8 , NULL ) ;
if( V_22 ) {
return V_22 -> V_52 ;
}
return 0 ;
}
void
F_50 ( T_17 * V_30 ,
const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 )
{
T_14 * V_22 ;
V_22 = F_36 ( V_30 , V_11 , V_4 , T_8 , NULL ) ;
if( V_22 ) {
V_22 -> V_26 |= V_54 ;
}
}
static void
F_51 ( T_17 * V_30 , T_5 V_2 )
{
F_41 ( V_30 -> V_35 , V_2 ) ;
}
static void
F_52 ( T_17 * V_30 , T_14 * V_22 ,
const T_6 * V_11 , const T_7 V_4 )
{
T_10 * V_55 ;
T_15 * V_41 ;
if ( V_22 -> V_24 == NULL ) {
V_55 = F_5 ( T_10 ) ;
V_55 -> V_20 = V_11 -> V_41 -> V_43 ;
V_55 -> V_4 = V_4 ;
F_39 ( V_30 -> V_39 , V_55 , V_22 ) ;
} else {
for ( V_41 = V_22 -> V_24 ; V_41 != NULL ; V_41 = V_41 -> V_24 ) {
V_55 = F_5 ( T_10 ) ;
V_55 -> V_20 = V_41 -> V_20 ;
V_55 -> V_4 = V_4 ;
F_39 ( V_30 -> V_39 , V_55 ,
V_22 ) ;
}
}
V_22 -> V_26 |= V_51 ;
V_22 -> V_56 = V_11 -> V_41 -> V_43 ;
V_22 -> V_57 = V_11 -> V_58 ;
}
static void
F_53 ( T_14 * V_22 , T_15 * V_41 )
{
T_15 * V_59 ;
for( V_59 = V_22 ; V_59 -> V_24 ; V_59 = V_59 -> V_24 ) {
if ( V_41 -> V_49 < V_59 -> V_24 -> V_49 )
break;
}
V_41 -> V_24 = V_59 -> V_24 ;
V_59 -> V_24 = V_41 ;
}
static T_11
F_54 ( T_14 * V_22 , T_19 * V_60 , const int V_49 ,
const T_6 * V_11 , const T_7 V_61 ,
const T_7 V_62 , const T_11 V_63 )
{
T_15 * V_41 ;
T_15 * V_59 ;
T_7 V_64 , V_65 , V_66 ;
T_19 * V_67 ;
T_20 * T_8 ;
V_41 = F_5 ( T_15 ) ;
V_41 -> V_24 = NULL ;
V_41 -> V_26 = 0 ;
V_41 -> V_20 = V_11 -> V_41 -> V_43 ;
V_41 -> V_49 = V_61 ;
V_41 -> V_45 = 0 ;
V_41 -> V_68 = V_62 ;
V_41 -> V_25 = NULL ;
V_41 -> error = NULL ;
if ( V_22 -> V_26 & V_51 ) {
if ( V_61 + V_62 >= V_22 -> V_52 ) {
if ( V_22 -> V_26 & V_54 ) {
for( V_59 = V_22 -> V_24 ; V_59 ; V_59 = V_59 -> V_24 ) {
if( ! V_59 -> V_25 ) {
V_59 -> V_25 = F_55 ( V_22 -> V_25 , V_59 -> V_49 ) ;
V_59 -> V_26 |= V_27 ;
}
V_59 -> V_26 &= ( ~ V_69 ) & ( ~ V_70 ) ;
}
V_22 -> V_26 &= ~ ( V_51 | V_54 | V_53 ) ;
V_22 -> V_26 &= ( ~ V_69 ) & ( ~ V_70 ) ;
V_22 -> V_52 = 0 ;
V_22 -> V_56 = 0 ;
V_22 -> V_57 = 0 ;
} else {
F_9 ( T_15 , V_41 ) ;
if ( V_61 >= V_22 -> V_52 ) {
F_48 ( V_50 , L_3 ) ;
} else {
F_48 ( V_50 , L_4 ) ;
}
}
} else {
F_9 ( T_15 , V_41 ) ;
F_48 ( V_50 , L_4 ) ;
}
}
if ( V_41 -> V_20 > V_22 -> V_20 )
V_22 -> V_20 = V_41 -> V_20 ;
if ( ! V_63 ) {
if ( V_22 -> V_26 & V_53 ) {
if ( V_22 -> V_52 != ( V_41 -> V_49 + V_41 -> V_68 ) ) {
V_41 -> V_26 |= V_70 ;
V_22 -> V_26 |= V_70 ;
}
} else {
V_22 -> V_52 = V_41 -> V_49 + V_41 -> V_68 ;
V_22 -> V_26 |= V_53 ;
}
}
if ( V_22 -> V_26 & V_51 ) {
T_7 V_71 = V_41 -> V_49 + V_41 -> V_68 ;
V_41 -> V_26 |= V_72 ;
V_22 -> V_26 |= V_72 ;
if ( V_71 > V_22 -> V_52 || V_71 < V_41 -> V_49 || V_71 < V_41 -> V_68 ) {
V_41 -> V_26 |= V_69 ;
V_22 -> V_26 |= V_69 ;
}
else if ( F_56 ( V_22 -> V_25 , V_41 -> V_49 ,
F_57 ( V_60 , V_49 , V_41 -> V_68 ) , V_41 -> V_68 ) ) {
V_41 -> V_26 |= V_73 ;
V_22 -> V_26 |= V_73 ;
}
F_53 ( V_22 , V_41 ) ;
return TRUE ;
}
if ( ! F_58 ( V_60 , V_49 , V_41 -> V_68 ) ) {
F_9 ( T_15 , V_41 ) ;
F_59 ( V_74 ) ;
}
V_41 -> V_25 = F_60 ( V_60 , V_49 , V_41 -> V_68 ) ;
F_53 ( V_22 , V_41 ) ;
if( ! ( V_22 -> V_26 & V_53 ) ) {
return FALSE ;
}
V_64 = 0 ;
for ( V_59 = V_22 -> V_24 ; V_59 ; V_59 = V_59 -> V_24 ) {
if ( ( ( V_59 -> V_49 ) <= V_64 ) &&
( ( V_59 -> V_49 + V_59 -> V_68 ) > V_64 ) ) {
V_64 = V_59 -> V_49 + V_59 -> V_68 ;
}
}
if ( V_64 < ( V_22 -> V_52 ) ) {
return FALSE ;
}
V_67 = V_22 -> V_25 ;
T_8 = ( T_20 * ) F_61 ( V_22 -> V_52 ) ;
V_22 -> V_25 = F_62 ( T_8 , V_22 -> V_52 , V_22 -> V_52 ) ;
F_63 ( V_22 -> V_25 , F_11 ) ;
for ( V_65 = 0 , V_59 = V_22 ; V_59 ; V_59 = V_59 -> V_24 ) {
if ( V_59 -> V_68 ) {
if ( V_59 -> V_49 + V_59 -> V_68 > V_65 ) {
if ( V_59 -> V_49 >= V_22 -> V_52 ) {
V_59 -> V_26 |= V_69 ;
V_22 -> V_26 |= V_69 ;
} else if ( V_65 < V_59 -> V_49 ) {
V_22 -> error = L_5 ;
} else if ( V_65 - V_59 -> V_49 > V_59 -> V_68 )
V_22 -> error = L_6 ;
else if ( ! V_22 -> V_25 )
V_22 -> error = L_7 ;
else {
V_66 = V_59 -> V_68 ;
if ( V_59 -> V_49 + V_66 > V_22 -> V_52 ) {
V_59 -> V_26 |= V_69 ;
V_22 -> V_26 |= V_69 ;
V_66 = V_22 -> V_52 - V_59 -> V_49 ;
}
if ( V_59 -> V_49 < V_65 ) {
T_7 V_75 = F_64 ( V_59 -> V_68 , ( V_65 - V_59 -> V_49 ) ) ;
V_59 -> V_26 |= V_72 ;
V_22 -> V_26 |= V_72 ;
if ( memcmp ( T_8 + V_59 -> V_49 ,
F_57 ( V_59 -> V_25 , 0 , V_75 ) ,
V_75 )
) {
V_59 -> V_26 |= V_73 ;
V_22 -> V_26 |= V_73 ;
}
}
if ( V_66 < V_65 - V_59 -> V_49 ) {
V_22 -> error = L_8 ;
} else {
memcpy ( T_8 + V_65 ,
F_57 ( V_59 -> V_25 , ( V_65 - V_59 -> V_49 ) , V_66 - ( V_65 - V_59 -> V_49 ) ) ,
V_66 - ( V_65 - V_59 -> V_49 ) ) ;
V_65 = F_65 ( V_65 , ( V_59 -> V_49 + V_66 ) ) ;
}
}
} else {
if ( V_59 -> V_49 + V_59 -> V_68 < V_59 -> V_49 ) {
V_22 -> error = L_9 ;
}
}
if ( V_59 -> V_26 & V_27 )
V_59 -> V_26 &= ~ V_27 ;
else if ( V_59 -> V_25 )
F_22 ( V_59 -> V_25 ) ;
V_59 -> V_25 = NULL ;
}
}
if ( V_67 )
F_66 ( V_60 , V_67 ) ;
V_22 -> V_26 |= V_51 ;
V_22 -> V_56 = V_11 -> V_41 -> V_43 ;
V_22 -> V_57 = V_11 -> V_58 ;
if ( V_22 -> error ) {
F_48 ( V_50 , V_22 -> error ) ;
}
return TRUE ;
}
static T_14 *
F_67 ( T_17 * V_30 , T_19 * V_60 , const int V_49 ,
const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 , const T_7 V_61 ,
const T_7 V_62 , const T_11 V_63 ,
const T_11 V_76 )
{
T_14 * V_22 ;
T_15 * V_77 ;
T_11 V_78 ;
F_68 ( F_58 ( V_60 , V_49 , V_62 ) ) ;
V_22 = F_36 ( V_30 , V_11 , V_4 , T_8 , NULL ) ;
#if 0
if(strcmp(pinfo->current_proto, "DCERPC") == 0) {
printf("proto:%s num:%u id:%u offset:%u len:%u more:%u visited:%u\n",
pinfo->current_proto, pinfo->fd->num, id, frag_offset, frag_data_len, more_frags, pinfo->fd->flags.visited);
if(fd_head != NULL) {
for(fd_item=fd_head->next;fd_item;fd_item=fd_item->next){
printf("fd_frame:%u fd_offset:%u len:%u datalen:%u\n",
fd_item->frame, fd_item->offset, fd_item->len, fd_item->datalen);
}
}
}
#endif
if ( ! V_11 -> V_41 -> V_26 . V_79 ) {
if ( V_76 && V_22 != NULL ) {
if ( V_11 -> V_41 -> V_43 <= V_22 -> V_20 ) {
V_78 = FALSE ;
for ( V_77 = V_22 -> V_24 ; V_77 ;
V_77 = V_77 -> V_24 ) {
if ( V_11 -> V_41 -> V_43 == V_77 -> V_20 &&
V_61 == V_77 -> V_49 ) {
V_78 = TRUE ;
break;
}
}
if ( V_78 ) {
if ( V_22 -> V_26 & V_51 ) {
F_48 ( V_50 ,
L_10 ) ;
} else {
return NULL ;
}
}
}
}
} else {
if ( V_22 != NULL && V_22 -> V_26 & V_51 ) {
if ( V_22 -> error )
F_48 ( V_50 , V_22 -> error ) ;
if ( V_11 -> V_41 -> V_43 > V_22 -> V_20 ) {
F_48 ( V_50 , L_4 ) ;
}
if ( V_61 + V_62 > V_22 -> V_52 ) {
if ( V_61 >= V_22 -> V_52 ) {
F_48 ( V_50 , L_3 ) ;
} else {
F_48 ( V_50 , L_4 ) ;
}
}
return V_22 ;
} else {
return NULL ;
}
}
if ( V_22 == NULL ) {
V_22 = F_23 ( 0 ) ;
F_38 ( V_30 , V_22 , V_11 , V_4 , T_8 ) ;
}
if ( F_54 ( V_22 , V_60 , V_49 , V_11 , V_61 ,
V_62 , V_63 ) ) {
return V_22 ;
} else {
return NULL ;
}
}
T_14 *
F_69 ( T_17 * V_30 , T_19 * V_60 , const int V_49 ,
const T_6 * V_11 , const T_7 V_4 , const void * T_8 ,
const T_7 V_61 , const T_7 V_62 ,
const T_11 V_63 )
{
return F_67 ( V_30 , V_60 , V_49 , V_11 , V_4 , T_8 ,
V_61 , V_62 , V_63 , TRUE ) ;
}
T_14 *
F_70 ( T_17 * V_30 , T_19 * V_60 ,
const int V_49 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 ,
const T_7 V_61 ,
const T_7 V_62 , const T_11 V_63 )
{
return F_67 ( V_30 , V_60 , V_49 , V_11 , V_4 , T_8 ,
V_61 , V_62 , V_63 , FALSE ) ;
}
T_14 *
F_71 ( T_17 * V_30 , T_19 * V_60 , const int V_49 ,
const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 , const T_7 V_61 ,
const T_7 V_62 , const T_11 V_63 )
{
T_10 V_80 ;
T_14 * V_22 ;
T_5 V_81 ;
if ( V_11 -> V_41 -> V_26 . V_79 ) {
V_80 . V_20 = V_11 -> V_41 -> V_43 ;
V_80 . V_4 = V_4 ;
return ( T_14 * ) F_44 ( V_30 -> V_39 , & V_80 ) ;
}
V_22 = F_36 ( V_30 , V_11 , V_4 , T_8 , & V_81 ) ;
if ( V_22 == NULL ) {
V_22 = F_23 ( 0 ) ;
V_81 = F_38 ( V_30 , V_22 , V_11 , V_4 , T_8 ) ;
}
if ( F_72 ( V_60 ) > F_73 ( V_60 ) )
return NULL ;
if ( F_54 ( V_22 , V_60 , V_49 , V_11 , V_61 ,
V_62 , V_63 ) ) {
F_51 ( V_30 , V_81 ) ;
F_52 ( V_30 , V_22 , V_11 , V_4 ) ;
return V_22 ;
} else {
return NULL ;
}
}
static void
F_74 ( T_14 * V_22 , const T_6 * V_11 )
{
T_15 * V_59 = NULL ;
T_15 * V_82 = NULL ;
T_7 V_65 = 0 , V_83 = 0 ;
T_19 * V_67 = NULL ;
T_20 * T_8 ;
for( V_59 = V_22 -> V_24 ; V_59 ; V_59 = V_59 -> V_24 ) {
if( ! V_82 || V_82 -> V_49 != V_59 -> V_49 ) {
V_83 += V_59 -> V_68 ;
}
V_82 = V_59 ;
}
V_67 = V_22 -> V_25 ;
T_8 = ( T_20 * ) F_61 ( V_83 ) ;
V_22 -> V_25 = F_62 ( T_8 , V_83 , V_83 ) ;
F_63 ( V_22 -> V_25 , F_11 ) ;
V_22 -> V_68 = V_83 ;
V_82 = NULL ;
for ( V_59 = V_22 -> V_24 ; V_59 ; V_59 = V_59 -> V_24 ) {
if ( V_59 -> V_68 ) {
if( ! V_82 || V_82 -> V_49 != V_59 -> V_49 ) {
memcpy ( T_8 + V_65 , F_57 ( V_59 -> V_25 , 0 , V_59 -> V_68 ) , V_59 -> V_68 ) ;
V_65 += V_59 -> V_68 ;
} else {
V_59 -> V_26 |= V_72 ;
V_22 -> V_26 |= V_72 ;
if( V_82 -> V_68 != V_59 -> V_68
|| F_56 ( V_82 -> V_25 , 0 , F_57 ( V_59 -> V_25 , 0 , V_82 -> V_68 ) , V_82 -> V_68 ) ) {
V_59 -> V_26 |= V_73 ;
V_22 -> V_26 |= V_73 ;
}
}
}
V_82 = V_59 ;
}
for ( V_59 = V_22 -> V_24 ; V_59 ; V_59 = V_59 -> V_24 ) {
if ( V_59 -> V_26 & V_27 )
V_59 -> V_26 &= ~ V_27 ;
else if ( V_59 -> V_25 )
F_22 ( V_59 -> V_25 ) ;
V_59 -> V_25 = NULL ;
}
if ( V_67 )
F_22 ( V_67 ) ;
V_22 -> V_26 |= V_51 ;
V_22 -> V_56 = V_11 -> V_41 -> V_43 ;
V_22 -> V_57 = V_11 -> V_58 ;
}
static T_11
F_75 ( T_14 * V_22 , T_19 * V_60 , const int V_49 ,
const T_6 * V_11 , const T_7 V_84 ,
const T_7 V_62 , const T_11 V_63 )
{
T_15 * V_41 ;
T_15 * V_59 ;
T_15 * V_82 ;
T_7 V_64 , V_65 ;
T_7 V_85 ;
V_85 = V_84 ;
if ( V_22 -> V_45 != 0 )
if ( V_85 >= V_22 -> V_45 )
V_85 = V_84 - V_22 -> V_45 ;
if( V_22 -> V_26 & V_51 && V_85 >= V_22 -> V_52 &&
V_22 -> V_26 & V_54 ) {
T_7 V_86 = 0 ;
V_65 = 0 ;
for( V_59 = V_22 -> V_24 ; V_59 ; V_59 = V_59 -> V_24 ) {
if( ! V_59 -> V_25 ) {
if( V_59 -> V_26 & V_72 ) {
V_59 -> V_25 = F_55 ( V_22 -> V_25 , V_86 ) ;
} else {
V_59 -> V_25 = F_55 ( V_22 -> V_25 , V_65 ) ;
V_86 = V_65 ;
V_65 += V_59 -> V_68 ;
}
V_59 -> V_26 |= V_27 ;
}
V_59 -> V_26 &= ( ~ V_69 ) & ( ~ V_70 ) ;
}
V_22 -> V_26 &= ~ ( V_51 | V_54 | V_53 ) ;
V_22 -> V_26 &= ( ~ V_69 ) & ( ~ V_70 ) ;
V_22 -> V_52 = 0 ;
V_22 -> V_56 = 0 ;
V_22 -> V_57 = 0 ;
}
V_41 = F_5 ( T_15 ) ;
V_41 -> V_24 = NULL ;
V_41 -> V_26 = 0 ;
V_41 -> V_20 = V_11 -> V_41 -> V_43 ;
V_41 -> V_49 = V_85 ;
V_41 -> V_68 = V_62 ;
V_41 -> V_25 = NULL ;
V_41 -> error = NULL ;
if ( ! V_63 ) {
if ( V_22 -> V_26 & V_53 ) {
if ( V_22 -> V_52 != V_41 -> V_49 ) {
V_41 -> V_26 |= V_70 ;
V_22 -> V_26 |= V_70 ;
}
} else {
V_22 -> V_52 = V_41 -> V_49 ;
V_22 -> V_26 |= V_53 ;
}
}
if ( V_22 -> V_26 & V_51 ) {
V_41 -> V_26 |= V_72 ;
V_22 -> V_26 |= V_72 ;
if ( V_41 -> V_49 > V_22 -> V_52 ) {
V_41 -> V_26 |= V_69 ;
V_22 -> V_26 |= V_69 ;
F_53 ( V_22 , V_41 ) ;
return TRUE ;
}
V_65 = 0 ;
V_82 = NULL ;
for ( V_59 = V_22 -> V_24 ; V_59 && ( V_59 -> V_49 != V_41 -> V_49 ) ; V_59 = V_59 -> V_24 ) {
if ( ! V_82 || V_82 -> V_49 != V_59 -> V_49 ) {
V_65 += V_59 -> V_68 ;
}
V_82 = V_59 ;
}
if( V_59 ) {
if( V_59 -> V_68 != V_41 -> V_68 ) {
V_41 -> V_26 |= V_73 ;
V_22 -> V_26 |= V_73 ;
F_53 ( V_22 , V_41 ) ;
return TRUE ;
}
F_68 ( V_22 -> V_68 >= V_65 + V_41 -> V_68 ) ;
if ( F_56 ( V_22 -> V_25 , V_65 ,
F_57 ( V_60 , V_49 , V_41 -> V_68 ) , V_41 -> V_68 ) ) {
V_41 -> V_26 |= V_73 ;
V_22 -> V_26 |= V_73 ;
F_53 ( V_22 , V_41 ) ;
return TRUE ;
}
F_53 ( V_22 , V_41 ) ;
return TRUE ;
} else {
F_53 ( V_22 , V_41 ) ;
return TRUE ;
}
}
if ( V_41 -> V_68 ) {
if ( ! F_58 ( V_60 , V_49 , V_41 -> V_68 ) ) {
F_9 ( T_15 , V_41 ) ;
return FALSE ;
}
V_41 -> V_25 = F_60 ( V_60 , V_49 , V_41 -> V_68 ) ;
}
F_53 ( V_22 , V_41 ) ;
if( ! ( V_22 -> V_26 & V_53 ) ) {
return FALSE ;
}
V_64 = 0 ;
for( V_59 = V_22 -> V_24 ; V_59 ; V_59 = V_59 -> V_24 ) {
if ( V_59 -> V_49 == V_64 ) {
V_64 ++ ;
}
}
if ( V_64 <= V_22 -> V_52 ) {
return FALSE ;
}
if ( V_64 > ( V_22 -> V_52 + 1 ) ) {
V_41 -> V_26 |= V_69 ;
V_22 -> V_26 |= V_69 ;
}
F_74 ( V_22 , V_11 ) ;
return TRUE ;
}
static T_14 *
F_76 ( T_17 * V_30 , T_19 * V_60 ,
const int V_49 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 ,
T_7 V_84 , const T_7 V_62 ,
const T_11 V_63 , const T_7 V_26 ,
T_5 * V_40 )
{
T_14 * V_22 ;
T_5 V_81 ;
V_22 = F_36 ( V_30 , V_11 , V_4 , T_8 , & V_81 ) ;
if ( V_11 -> V_41 -> V_26 . V_79 ) {
if ( V_22 != NULL && V_22 -> V_26 & V_51 ) {
if ( V_40 != NULL )
* V_40 = V_81 ;
return V_22 ;
} else {
return NULL ;
}
}
if ( V_22 == NULL ) {
V_22 = F_23 ( V_48 ) ;
if( ( V_26 & ( V_87 | V_88 ) )
&& ! V_63 ) {
if ( V_40 != NULL )
* V_40 = NULL ;
V_22 -> V_56 = V_11 -> V_41 -> V_43 ;
V_22 -> V_57 = V_11 -> V_58 ;
return V_22 ;
}
V_81 = F_38 ( V_30 , V_22 , V_11 , V_4 , T_8 ) ;
if ( V_40 != NULL )
* V_40 = V_81 ;
if ( V_26 & V_87 )
V_84 = 0 ;
} else {
if ( V_40 != NULL )
* V_40 = V_81 ;
if ( V_26 & V_87 ) {
T_15 * V_41 ;
for ( V_41 = V_22 ; V_41 != NULL ; V_41 = V_41 -> V_24 ) {
if ( V_41 -> V_24 == NULL )
V_84 = V_41 -> V_49 + 1 ;
}
}
}
if ( ( V_26 & V_89 ) &&
! F_58 ( V_60 , V_49 , V_62 ) ) {
V_22 -> V_26 |= V_90 ;
if ( V_84 == 0 ) {
return V_22 ;
}
else {
if ( ! V_63 ) {
F_51 ( V_30 , * V_40 ) ;
F_21 ( NULL , V_22 , NULL ) ;
}
return NULL ;
}
}
if ( F_75 ( V_22 , V_60 , V_49 , V_11 ,
V_84 , V_62 , V_63 ) ) {
return V_22 ;
} else {
return NULL ;
}
}
T_14 *
F_77 ( T_17 * V_30 , T_19 * V_60 , const int V_49 ,
const T_6 * V_11 , const T_7 V_4 , const void * T_8 ,
const T_7 V_84 , const T_7 V_62 ,
const T_11 V_63 , const T_7 V_26 )
{
return F_76 ( V_30 , V_60 , V_49 , V_11 , V_4 , T_8 ,
V_84 , V_62 ,
V_63 , V_26 , NULL ) ;
}
static T_14 *
F_78 ( T_17 * V_30 , T_19 * V_60 ,
const int V_49 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 ,
const T_7 V_84 ,
const T_7 V_62 ,
const T_11 V_63 , const T_7 V_26 )
{
T_10 V_80 ;
T_14 * V_22 ;
T_5 V_81 ;
if ( V_11 -> V_41 -> V_26 . V_79 ) {
V_80 . V_20 = V_11 -> V_41 -> V_43 ;
V_80 . V_4 = V_4 ;
return ( T_14 * ) F_44 ( V_30 -> V_39 , & V_80 ) ;
}
V_22 = F_76 ( V_30 , V_60 , V_49 , V_11 , V_4 , T_8 ,
V_84 , V_62 ,
V_63 ,
V_26 | V_89 ,
& V_81 ) ;
if ( V_22 ) {
if( V_22 -> V_26 & V_90 ) {
return V_22 ;
}
if ( V_81 != NULL )
F_51 ( V_30 , V_81 ) ;
F_52 ( V_30 , V_22 , V_11 , V_4 ) ;
return V_22 ;
} else {
return NULL ;
}
}
T_14 *
F_79 ( T_17 * V_30 , T_19 * V_60 , const int V_49 ,
const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 ,
const T_7 V_84 , const T_7 V_62 ,
const T_11 V_63 )
{
return F_78 ( V_30 , V_60 , V_49 , V_11 , V_4 , T_8 ,
V_84 , V_62 ,
V_63 , 0 ) ;
}
T_14 *
F_80 ( T_17 * V_30 , T_19 * V_60 ,
const int V_49 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 ,
const T_7 V_84 , const T_7 V_62 ,
const T_11 V_63 )
{
return F_78 ( V_30 , V_60 , V_49 , V_11 , V_4 , T_8 ,
V_84 , V_62 ,
V_63 ,
V_88 ) ;
}
T_14 *
F_81 ( T_17 * V_30 , T_19 * V_60 , const int V_49 ,
const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 , const T_7 V_62 ,
const T_11 V_63 )
{
return F_78 ( V_30 , V_60 , V_49 , V_11 , V_4 , T_8 ,
0 , V_62 , V_63 ,
V_87 ) ;
}
void
F_82 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 ,
const T_7 V_46 )
{
T_14 * V_22 ;
if ( V_11 -> V_41 -> V_26 . V_79 ) {
return;
}
V_22 = F_36 ( V_30 , V_11 , V_4 , T_8 , NULL ) ;
if ( V_22 == NULL ) {
V_22 = F_5 ( T_14 ) ;
V_22 -> V_24 = NULL ;
V_22 -> V_52 = V_46 ;
V_22 -> V_49 = 0 ;
V_22 -> V_45 = 0 ;
V_22 -> V_68 = 0 ;
V_22 -> V_26 = V_48 | V_53 ;
V_22 -> V_25 = NULL ;
V_22 -> V_56 = 0 ;
V_22 -> V_57 = 0 ;
V_22 -> error = NULL ;
F_38 ( V_30 , V_22 , V_11 , V_4 , T_8 ) ;
}
}
T_14 *
F_83 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 )
{
T_10 V_80 ;
T_10 * V_55 ;
T_14 * V_22 ;
T_5 V_81 ;
if ( V_11 -> V_41 -> V_26 . V_79 ) {
V_80 . V_20 = V_11 -> V_41 -> V_43 ;
V_80 . V_4 = V_4 ;
return ( T_14 * ) F_44 ( V_30 -> V_39 , & V_80 ) ;
}
V_22 = F_36 ( V_30 , V_11 , V_4 , T_8 , & V_81 ) ;
if ( V_22 ) {
if ( V_22 -> V_26 & V_90 ) {
return NULL ;
}
V_22 -> V_52 = V_22 -> V_49 ;
V_22 -> V_26 |= V_53 ;
F_74 ( V_22 , V_11 ) ;
F_51 ( V_30 , V_81 ) ;
F_52 ( V_30 , V_22 , V_11 , V_4 ) ;
if ( V_22 -> V_24 != NULL ) {
V_55 = F_5 ( T_10 ) ;
V_55 -> V_20 = V_11 -> V_41 -> V_43 ;
V_55 -> V_4 = V_4 ;
F_39 ( V_30 -> V_39 , V_55 , V_22 ) ;
}
return V_22 ;
} else {
return NULL ;
}
}
T_19 *
F_84 ( T_19 * V_60 , const int V_49 , T_6 * V_11 ,
const char * V_91 , T_14 * V_22 , const T_21 * V_92 ,
T_11 * V_93 , T_22 * V_94 )
{
T_19 * V_95 ;
T_11 V_96 ;
T_23 * V_97 ;
if ( V_22 != NULL && V_11 -> V_41 -> V_43 == V_22 -> V_56 && V_11 -> V_58 == V_22 -> V_57 ) {
if ( V_22 -> V_24 != NULL ) {
V_95 = F_85 ( V_60 , V_22 -> V_25 ) ;
F_86 ( V_11 , V_95 , V_91 ) ;
if ( V_22 -> V_26 & V_48 ) {
V_96 = ! F_87 (
V_22 , V_92 , V_94 , V_11 , V_95 , & V_97 ) ;
} else {
V_96 = ! F_88 ( V_22 ,
V_92 , V_94 , V_11 , V_95 , & V_97 ) ;
}
} else {
V_95 = F_55 ( V_60 , V_49 ) ;
V_11 -> V_98 = FALSE ;
V_96 = TRUE ;
}
if ( V_93 != NULL )
* V_93 = V_96 ;
} else {
V_95 = NULL ;
if ( V_22 != NULL && V_92 -> V_99 != NULL ) {
F_89 ( V_94 ,
* ( V_92 -> V_99 ) , V_60 ,
0 , 0 , V_22 -> V_56 ) ;
}
}
return V_95 ;
}
static void
F_90 ( T_15 * V_41 , const int V_49 , const T_21 * V_92 ,
T_22 * V_100 , T_23 * V_101 , const T_11 V_102 ,
const T_7 V_103 , T_19 * V_60 , T_6 * V_11 )
{
T_23 * V_104 = NULL ;
int V_105 ;
if ( V_102 ) {
T_24 * V_91 ;
if ( V_103 == 1 ) {
V_91 = F_91 ( F_92 ( * ( V_92 -> V_106 ) ) ) ;
} else {
V_91 = F_91 ( F_92 ( * ( V_92 -> V_107 ) ) ) ;
}
F_93 ( V_101 , L_11 , V_103 , V_91 , F_73 ( V_60 ) ,
F_94 ( F_73 ( V_60 ) , L_12 , L_13 ) ) ;
F_11 ( V_91 ) ;
} else {
F_95 ( V_101 , L_14 ) ;
}
F_95 ( V_101 , L_15 , V_41 -> V_20 , V_41 -> V_68 ) ;
if ( V_41 -> V_26 & ( V_73
| V_70 | V_69 ) ) {
V_105 = * ( V_92 -> V_108 ) ;
} else {
V_105 = * ( V_92 -> V_106 ) ;
}
if ( V_41 -> V_68 == 0 ) {
V_104 = F_96 ( V_100 , V_105 ,
V_60 , V_49 , V_41 -> V_68 ,
V_41 -> V_20 ,
L_16 ,
V_41 -> V_20 ) ;
} else {
V_104 = F_96 ( V_100 , V_105 ,
V_60 , V_49 , V_41 -> V_68 ,
V_41 -> V_20 ,
L_17 ,
V_41 -> V_20 ,
V_49 ,
V_49 + V_41 -> V_68 - 1 ,
V_41 -> V_68 ,
F_94 ( V_41 -> V_68 , L_12 , L_13 ) ) ;
}
F_97 ( V_104 ) ;
F_98 ( V_11 , V_41 -> V_20 ) ;
if ( V_41 -> V_26 & ( V_72 | V_73
| V_70 | V_69 ) ) {
T_22 * V_109 = NULL ;
V_109 = F_99 ( V_104 , * ( V_92 -> V_110 ) ) ;
if ( V_41 -> V_26 & V_72 ) {
V_104 = F_100 ( V_109 ,
* ( V_92 -> V_111 ) ,
V_60 , 0 , 0 ,
TRUE ) ;
F_97 ( V_104 ) ;
}
if ( V_41 -> V_26 & V_73 ) {
V_104 = F_100 ( V_109 ,
* ( V_92 -> V_112 ) ,
V_60 , 0 , 0 ,
TRUE ) ;
F_97 ( V_104 ) ;
}
if ( V_41 -> V_26 & V_70 ) {
V_104 = F_100 ( V_109 ,
* ( V_92 -> V_113 ) ,
V_60 , 0 , 0 ,
TRUE ) ;
F_97 ( V_104 ) ;
}
if ( V_41 -> V_26 & V_69 ) {
V_104 = F_100 ( V_109 ,
* ( V_92 -> V_114 ) ,
V_60 , 0 , 0 ,
TRUE ) ;
F_97 ( V_104 ) ;
}
}
}
static T_11
F_101 ( T_14 * V_22 , const T_21 * V_92 ,
T_6 * V_11 )
{
if ( V_22 -> V_26 & ( V_73
| V_70 | V_69 ) ) {
F_102 ( V_11 -> V_115 , V_116 , L_18 , V_92 -> V_117 ) ;
return TRUE ;
}
return FALSE ;
}
T_11
F_88 ( T_14 * V_22 , const T_21 * V_92 ,
T_22 * V_94 , T_6 * V_11 , T_19 * V_60 , T_23 * * V_101 )
{
T_15 * V_41 ;
T_22 * V_100 ;
T_11 V_102 ;
T_7 V_103 = 0 ;
V_11 -> V_98 = FALSE ;
* V_101 = F_103 ( V_94 , * ( V_92 -> V_107 ) , V_60 , 0 , - 1 , V_118 ) ;
F_97 ( * V_101 ) ;
V_100 = F_99 ( * V_101 , * ( V_92 -> V_119 ) ) ;
V_102 = TRUE ;
for ( V_41 = V_22 -> V_24 ; V_41 != NULL ; V_41 = V_41 -> V_24 ) {
V_103 ++ ;
}
for ( V_41 = V_22 -> V_24 ; V_41 != NULL ; V_41 = V_41 -> V_24 ) {
F_90 ( V_41 , V_41 -> V_49 , V_92 , V_100 , * V_101 , V_102 , V_103 , V_60 , V_11 ) ;
V_102 = FALSE ;
}
if ( V_92 -> V_120 ) {
T_23 * V_121 = F_89 ( V_100 , * ( V_92 -> V_120 ) ,
V_60 , 0 , 0 , V_103 ) ;
F_97 ( V_121 ) ;
}
if ( V_92 -> V_122 ) {
T_23 * V_121 = F_89 ( V_100 , * ( V_92 -> V_122 ) ,
V_60 , 0 , 0 , F_73 ( V_60 ) ) ;
F_97 ( V_121 ) ;
}
if ( V_92 -> V_123 ) {
T_23 * V_121 = F_103 ( V_100 , * ( V_92 -> V_123 ) ,
V_60 , 0 , F_73 ( V_60 ) , V_118 ) ;
F_97 ( V_121 ) ;
}
return F_101 ( V_22 , V_92 , V_11 ) ;
}
T_11
F_87 ( T_14 * V_22 , const T_21 * V_92 ,
T_22 * V_94 , T_6 * V_11 , T_19 * V_60 , T_23 * * V_101 )
{
T_7 V_49 , V_124 , V_103 = 0 ;
T_15 * V_41 , * V_82 ;
T_22 * V_100 ;
T_11 V_102 ;
V_11 -> V_98 = FALSE ;
* V_101 = F_103 ( V_94 , * ( V_92 -> V_107 ) , V_60 , 0 , - 1 , V_118 ) ;
F_97 ( * V_101 ) ;
V_100 = F_99 ( * V_101 , * ( V_92 -> V_119 ) ) ;
V_49 = 0 ;
V_124 = 0 ;
V_82 = NULL ;
V_102 = TRUE ;
for ( V_41 = V_22 -> V_24 ; V_41 != NULL ; V_41 = V_41 -> V_24 ) {
V_103 ++ ;
}
for ( V_41 = V_22 -> V_24 ; V_41 != NULL ; V_41 = V_41 -> V_24 ) {
if ( V_82 == NULL || V_82 -> V_49 != V_41 -> V_49 ) {
V_49 = V_124 ;
V_124 += V_41 -> V_68 ;
}
V_82 = V_41 ;
F_90 ( V_41 , V_49 , V_92 , V_100 , * V_101 , V_102 , V_103 , V_60 , V_11 ) ;
V_102 = FALSE ;
}
if ( V_92 -> V_120 ) {
T_23 * V_121 = F_89 ( V_100 , * ( V_92 -> V_120 ) ,
V_60 , 0 , 0 , V_103 ) ;
F_97 ( V_121 ) ;
}
if ( V_92 -> V_122 ) {
T_23 * V_121 = F_89 ( V_100 , * ( V_92 -> V_122 ) ,
V_60 , 0 , 0 , F_73 ( V_60 ) ) ;
F_97 ( V_121 ) ;
}
if ( V_92 -> V_123 ) {
T_23 * V_121 = F_103 ( V_100 , * ( V_92 -> V_123 ) ,
V_60 , 0 , F_73 ( V_60 ) , V_118 ) ;
F_97 ( V_121 ) ;
}
return F_101 ( V_22 , V_92 , V_11 ) ;
}
