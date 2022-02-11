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
F_6 ( & V_2 -> V_9 , & V_11 -> V_9 ) ;
F_6 ( & V_2 -> V_10 , & V_11 -> V_10 ) ;
V_2 -> V_4 = V_4 ;
return ( T_5 ) V_2 ;
}
static T_5
F_7 ( const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 V_12 )
{
T_3 * V_2 = F_5 ( T_3 ) ;
F_8 ( & V_2 -> V_9 , & V_11 -> V_9 ) ;
F_8 ( & V_2 -> V_10 , & V_11 -> V_10 ) ;
V_2 -> V_4 = V_4 ;
return ( T_5 ) V_2 ;
}
static void
F_9 ( T_5 V_13 )
{
T_3 * V_2 = ( T_3 * ) V_13 ;
if( V_2 )
F_10 ( T_3 , V_2 ) ;
}
static void
F_11 ( T_5 V_13 )
{
T_3 * V_2 = ( T_3 * ) V_13 ;
if( V_2 ) {
F_12 ( & V_2 -> V_9 ) ;
F_12 ( & V_2 -> V_10 ) ;
F_10 ( T_3 , V_2 ) ;
}
}
static T_1
F_13 ( T_2 V_1 )
{
const T_9 * V_2 = ( const T_9 * ) V_1 ;
T_1 V_3 ;
V_3 = 0 ;
V_3 += V_2 -> V_4 ;
return V_3 ;
}
static T_4
F_14 ( T_2 V_5 , T_2 V_6 )
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
F_15 ( const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 V_12 )
{
T_9 * V_2 = F_5 ( T_9 ) ;
F_6 ( & V_2 -> V_14 , & V_11 -> V_9 ) ;
F_6 ( & V_2 -> V_15 , & V_11 -> V_10 ) ;
V_2 -> V_16 = V_11 -> V_18 ;
V_2 -> V_17 = V_11 -> V_19 ;
V_2 -> V_4 = V_4 ;
return ( T_5 ) V_2 ;
}
static T_5
F_16 ( const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 V_12 )
{
T_9 * V_2 = F_5 ( T_9 ) ;
F_8 ( & V_2 -> V_14 , & V_11 -> V_9 ) ;
F_8 ( & V_2 -> V_15 , & V_11 -> V_10 ) ;
V_2 -> V_16 = V_11 -> V_18 ;
V_2 -> V_17 = V_11 -> V_19 ;
V_2 -> V_4 = V_4 ;
return ( T_5 ) V_2 ;
}
static void
F_17 ( T_5 V_13 )
{
T_9 * V_2 = ( T_9 * ) V_13 ;
if( V_2 )
F_10 ( T_9 , V_2 ) ;
}
static void
F_18 ( T_5 V_13 )
{
T_9 * V_2 = ( T_9 * ) V_13 ;
if( V_2 ) {
F_12 ( & V_2 -> V_14 ) ;
F_12 ( & V_2 -> V_15 ) ;
F_10 ( T_9 , V_2 ) ;
}
}
static T_4
F_19 ( T_2 V_5 , T_2 V_6 )
{
const T_10 * V_7 = ( const T_10 * ) V_5 ;
const T_10 * V_8 = ( const T_10 * ) V_6 ;
return V_7 -> V_20 == V_8 -> V_20 && V_7 -> V_4 == V_8 -> V_4 ;
}
static T_1
F_20 ( T_2 V_1 )
{
const T_10 * V_2 = ( const T_10 * ) V_1 ;
return V_2 -> V_20 ;
}
static void
F_21 ( T_5 V_13 )
{
F_10 ( T_10 , ( T_10 * ) V_13 ) ;
}
static T_11
F_22 ( T_5 T_12 V_12 , T_5 V_21 , T_5 T_13 V_12 )
{
T_14 * V_22 ;
T_15 * V_23 ;
for ( V_22 = ( T_14 * ) V_21 ; V_22 != NULL ; V_22 = V_23 ) {
V_23 = V_22 -> V_24 ;
if( V_22 -> V_25 && ! ( V_22 -> V_26 & V_27 ) )
F_23 ( V_22 -> V_25 ) ;
F_10 ( T_15 , V_22 ) ;
}
return TRUE ;
}
static T_14 * F_24 ( const T_7 V_26 )
{
T_14 * V_22 ;
V_22 = F_25 ( T_14 ) ;
V_22 -> V_26 = V_26 ;
return V_22 ;
}
static T_11
F_26 ( T_5 T_12 V_12 , T_5 V_21 ,
T_5 T_13 )
{
T_16 * V_28 = ( T_16 * ) T_13 ;
T_14 * V_22 ;
for ( V_22 = ( T_14 * ) V_21 ; V_22 != NULL ; V_22 = V_22 -> V_24 ) {
if ( V_22 -> V_26 != V_29 ) {
if ( V_22 -> V_26 & V_27 )
V_22 -> V_25 = NULL ;
F_27 ( V_28 , V_22 ) ;
V_22 -> V_26 = V_29 ;
}
}
return TRUE ;
}
static void
F_28 ( T_5 T_8 , T_5 T_13 V_12 )
{
T_15 * V_22 = ( T_15 * ) T_8 ;
if ( V_22 -> V_25 )
F_23 ( V_22 -> V_25 ) ;
F_10 ( T_15 , V_22 ) ;
}
void
F_29 ( T_17 * V_30 ,
const T_18 * V_31 )
{
T_19 * V_32 ;
F_30 ( V_30 ) ;
F_30 ( V_31 ) ;
V_32 = F_31 ( T_19 , 1 ) ;
V_32 -> V_30 = V_30 ;
V_32 -> V_31 = V_31 ;
V_33 = F_32 ( V_33 , V_32 ) ;
}
void
F_33 ( T_17 * V_30 ,
const T_18 * V_31 )
{
if ( V_30 -> V_34 == NULL )
V_30 -> V_34 = V_31 -> V_34 ;
if ( V_30 -> V_35 == NULL )
V_30 -> V_35 = V_31 -> V_35 ;
if ( V_30 -> V_36 == NULL )
V_30 -> V_36 = V_31 -> V_36 ;
if ( V_30 -> V_37 != NULL ) {
F_34 ( V_30 -> V_37 ,
F_22 , NULL ) ;
} else {
V_30 -> V_37 = F_35 ( V_31 -> V_38 ,
V_31 -> V_39 , V_31 -> V_40 , NULL ) ;
}
if ( V_30 -> V_41 != NULL ) {
T_16 * V_28 ;
V_28 = F_36 () ;
F_34 ( V_30 -> V_41 ,
F_26 , V_28 ) ;
F_37 ( V_28 , F_28 , NULL ) ;
F_38 ( V_28 , TRUE ) ;
} else {
V_30 -> V_41 = F_35 ( F_20 ,
F_19 , F_21 , NULL ) ;
}
}
void
F_39 ( T_17 * V_30 )
{
V_30 -> V_34 = NULL ;
V_30 -> V_35 = NULL ;
V_30 -> V_36 = NULL ;
if ( V_30 -> V_37 != NULL ) {
F_34 ( V_30 -> V_37 ,
F_22 , NULL ) ;
F_40 ( V_30 -> V_37 ) ;
V_30 -> V_37 = NULL ;
}
if ( V_30 -> V_41 != NULL ) {
T_16 * V_28 ;
V_28 = F_36 () ;
F_34 ( V_30 -> V_41 ,
F_26 , V_28 ) ;
F_37 ( V_28 , F_28 , NULL ) ;
F_38 ( V_28 , TRUE ) ;
F_40 ( V_30 -> V_41 ) ;
V_30 -> V_41 = NULL ;
}
}
static T_14 *
F_41 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 , T_5 * V_42 )
{
T_5 V_2 ;
T_5 V_21 ;
V_2 = V_30 -> V_34 ( V_11 , V_4 , T_8 ) ;
if ( ! F_42 ( V_30 -> V_37 , V_2 , V_42 ,
& V_21 ) )
V_21 = NULL ;
V_30 -> V_36 ( V_2 ) ;
return ( T_14 * ) V_21 ;
}
static T_5
F_43 ( T_17 * V_30 , T_14 * V_22 ,
const T_6 * V_11 , const T_7 V_4 , const void * T_8 )
{
T_5 V_2 ;
V_2 = V_30 -> V_35 ( V_11 , V_4 , T_8 ) ;
F_44 ( V_30 -> V_37 , V_2 , V_22 ) ;
return V_2 ;
}
T_20 *
F_45 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 )
{
T_14 * V_22 ;
T_15 * V_43 ;
T_20 * V_44 = NULL ;
T_5 V_2 ;
V_22 = F_41 ( V_30 , V_11 , V_4 , T_8 , & V_2 ) ;
if( V_22 == NULL ) {
return NULL ;
}
V_44 = V_22 -> V_25 ;
for( V_43 = V_22 -> V_24 ; V_43 ; ) {
T_15 * V_23 ;
V_23 = V_43 -> V_24 ;
if ( V_43 -> V_25 && ! ( V_43 -> V_26 & V_27 ) )
F_23 ( V_43 -> V_25 ) ;
F_10 ( T_15 , V_43 ) ;
V_43 = V_23 ;
}
F_10 ( T_14 , V_22 ) ;
F_46 ( V_30 -> V_37 , V_2 ) ;
return V_44 ;
}
T_14 *
F_47 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 )
{
return F_41 ( V_30 , V_11 , V_4 , T_8 , NULL ) ;
}
T_14 *
F_48 ( T_17 * V_30 , const T_7 V_4 )
{
T_14 * V_22 ;
T_10 V_2 ;
V_2 . V_20 = V_4 ;
V_2 . V_4 = V_4 ;
V_22 = ( T_14 * ) F_49 ( V_30 -> V_41 , & V_2 ) ;
return V_22 ;
}
T_14 *
F_50 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 )
{
T_14 * V_22 ;
T_10 V_2 ;
V_2 . V_20 = V_11 -> V_45 ;
V_2 . V_4 = V_4 ;
V_22 = ( T_14 * ) F_49 ( V_30 -> V_41 , & V_2 ) ;
return V_22 ;
}
void
F_51 ( T_17 * V_30 , const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 , const T_7 V_46 )
{
T_14 * V_22 ;
V_22 = F_41 ( V_30 , V_11 , V_4 , T_8 , NULL ) ;
if ( ! V_22 )
return;
if ( V_22 -> V_47 != 0 )
return;
V_22 -> V_47 = V_46 ;
}
void
F_52 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 , const T_7 V_48 )
{
T_14 * V_22 ;
T_15 * V_43 ;
T_7 V_49 = 0 ;
V_22 = F_41 ( V_30 , V_11 , V_4 , T_8 , NULL ) ;
if ( ! V_22 )
return;
V_43 = V_22 ;
if ( V_22 -> V_26 & V_50 ) {
while ( V_43 ) {
if ( V_43 -> V_51 > V_49 ) {
V_49 = V_43 -> V_51 ;
if ( V_49 > V_48 ) {
V_22 -> error = L_1 ;
F_53 ( V_52 , V_22 -> error ) ;
}
}
V_43 = V_43 -> V_24 ;
}
}
if ( V_22 -> V_26 & V_53 ) {
if ( V_49 != V_48 ) {
V_22 -> error = L_2 ;
F_53 ( V_52 , V_22 -> error ) ;
}
}
V_22 -> V_54 = V_48 ;
V_22 -> V_26 |= V_55 ;
}
T_7
F_54 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 )
{
T_14 * V_22 ;
V_22 = F_41 ( V_30 , V_11 , V_4 , T_8 , NULL ) ;
if( V_22 ) {
return V_22 -> V_54 ;
}
return 0 ;
}
void
F_55 ( T_17 * V_30 ,
const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 )
{
T_14 * V_22 ;
V_22 = F_41 ( V_30 , V_11 , V_4 , T_8 , NULL ) ;
if( V_22 ) {
V_22 -> V_26 |= V_56 ;
}
}
static void
F_56 ( T_17 * V_30 , T_5 V_2 )
{
F_46 ( V_30 -> V_37 , V_2 ) ;
}
static void
F_57 ( T_17 * V_30 , T_14 * V_22 ,
const T_6 * V_11 , const T_7 V_4 )
{
T_10 * V_57 ;
T_15 * V_43 ;
if ( V_22 -> V_24 == NULL ) {
V_57 = F_5 ( T_10 ) ;
V_57 -> V_20 = V_11 -> V_45 ;
V_57 -> V_4 = V_4 ;
F_44 ( V_30 -> V_41 , V_57 , V_22 ) ;
} else {
for ( V_43 = V_22 -> V_24 ; V_43 != NULL ; V_43 = V_43 -> V_24 ) {
V_57 = F_5 ( T_10 ) ;
V_57 -> V_20 = V_43 -> V_20 ;
V_57 -> V_4 = V_4 ;
F_44 ( V_30 -> V_41 , V_57 ,
V_22 ) ;
}
}
V_22 -> V_26 |= V_53 ;
V_22 -> V_58 = V_11 -> V_45 ;
V_22 -> V_59 = V_11 -> V_60 ;
}
static void
F_58 ( T_17 * V_30 , T_14 * V_22 ,
const T_6 * V_11 , const T_7 V_4 )
{
T_10 * V_57 ;
T_15 * V_43 ;
if ( V_22 -> V_24 == NULL ) {
V_57 = F_5 ( T_10 ) ;
V_57 -> V_20 = V_11 -> V_45 ;
V_57 -> V_4 = V_4 ;
F_44 ( V_30 -> V_41 , V_57 , V_22 ) ;
} else {
for ( V_43 = V_22 -> V_24 ; V_43 != NULL ; V_43 = V_43 -> V_24 ) {
V_57 = F_5 ( T_10 ) ;
V_57 -> V_20 = V_43 -> V_20 ;
V_57 -> V_4 = V_4 + V_43 -> V_51 ;
F_44 ( V_30 -> V_41 , V_57 ,
V_22 ) ;
}
}
V_22 -> V_26 |= V_53 ;
V_22 -> V_58 = V_11 -> V_45 ;
V_22 -> V_59 = V_11 -> V_60 ;
}
static void
F_59 ( T_14 * V_22 , T_15 * V_43 )
{
T_15 * V_61 ;
for( V_61 = V_22 ; V_61 -> V_24 ; V_61 = V_61 -> V_24 ) {
if ( V_43 -> V_51 < V_61 -> V_24 -> V_51 )
break;
}
V_43 -> V_24 = V_61 -> V_24 ;
V_61 -> V_24 = V_43 ;
}
static void
F_60 ( T_14 * V_22 , T_15 * V_43 )
{
T_15 * V_61 , * V_62 ;
if ( V_43 == NULL ) return;
for( V_61 = V_22 ; V_61 -> V_24 ; V_61 = V_61 -> V_24 ) {
if ( V_43 -> V_51 < V_61 -> V_24 -> V_51 ) {
V_62 = V_61 -> V_24 ;
V_61 -> V_24 = V_43 ;
V_43 = V_62 ;
}
}
V_61 -> V_24 = V_43 ;
}
static T_11
F_61 ( T_14 * V_22 , T_20 * V_63 , const int V_51 ,
const T_6 * V_11 , const T_7 V_64 ,
const T_7 V_65 , const T_11 V_66 )
{
T_15 * V_43 ;
T_15 * V_61 ;
T_7 V_67 , V_68 , V_69 ;
T_20 * V_70 ;
T_21 * T_8 ;
V_43 = F_5 ( T_15 ) ;
V_43 -> V_24 = NULL ;
V_43 -> V_26 = 0 ;
V_43 -> V_20 = V_11 -> V_45 ;
V_43 -> V_51 = V_64 ;
V_43 -> V_47 = 0 ;
V_43 -> V_71 = V_65 ;
V_43 -> V_25 = NULL ;
V_43 -> error = NULL ;
if ( V_22 -> V_26 & V_53 ) {
if ( V_64 + V_65 >= V_22 -> V_54 ) {
if ( V_22 -> V_26 & V_56 ) {
for( V_61 = V_22 -> V_24 ; V_61 ; V_61 = V_61 -> V_24 ) {
if( ! V_61 -> V_25 ) {
V_61 -> V_25 = F_62 ( V_22 -> V_25 , V_61 -> V_51 ) ;
V_61 -> V_26 |= V_27 ;
}
V_61 -> V_26 &= ( ~ V_72 ) & ( ~ V_73 ) ;
}
V_22 -> V_26 &= ~ ( V_53 | V_56 | V_55 ) ;
V_22 -> V_26 &= ( ~ V_72 ) & ( ~ V_73 ) ;
V_22 -> V_54 = 0 ;
V_22 -> V_58 = 0 ;
V_22 -> V_59 = 0 ;
} else {
F_10 ( T_15 , V_43 ) ;
if ( V_64 >= V_22 -> V_54 ) {
F_53 ( V_52 , L_3 ) ;
} else {
F_53 ( V_52 , L_4 ) ;
}
}
} else {
F_10 ( T_15 , V_43 ) ;
F_53 ( V_52 , L_4 ) ;
}
}
if ( V_43 -> V_20 > V_22 -> V_20 )
V_22 -> V_20 = V_43 -> V_20 ;
if ( ! V_66 ) {
if ( V_22 -> V_26 & V_55 ) {
if ( V_22 -> V_54 != ( V_43 -> V_51 + V_43 -> V_71 ) ) {
V_43 -> V_26 |= V_73 ;
V_22 -> V_26 |= V_73 ;
}
} else {
V_22 -> V_54 = V_43 -> V_51 + V_43 -> V_71 ;
V_22 -> V_26 |= V_55 ;
}
}
if ( V_22 -> V_26 & V_53 ) {
T_7 V_74 = V_43 -> V_51 + V_43 -> V_71 ;
V_43 -> V_26 |= V_75 ;
V_22 -> V_26 |= V_75 ;
if ( V_74 > V_22 -> V_54 || V_74 < V_43 -> V_51 || V_74 < V_43 -> V_71 ) {
V_43 -> V_26 |= V_72 ;
V_22 -> V_26 |= V_72 ;
}
else if ( F_63 ( V_22 -> V_25 , V_43 -> V_51 ,
F_64 ( V_63 , V_51 , V_43 -> V_71 ) , V_43 -> V_71 ) ) {
V_43 -> V_26 |= V_76 ;
V_22 -> V_26 |= V_76 ;
}
F_59 ( V_22 , V_43 ) ;
return TRUE ;
}
if ( ! F_65 ( V_63 , V_51 , V_43 -> V_71 ) ) {
F_10 ( T_15 , V_43 ) ;
F_66 ( V_77 ) ;
}
V_43 -> V_25 = F_67 ( V_63 , V_51 , V_43 -> V_71 ) ;
F_59 ( V_22 , V_43 ) ;
if( ! ( V_22 -> V_26 & V_55 ) ) {
return FALSE ;
}
V_67 = 0 ;
for ( V_61 = V_22 -> V_24 ; V_61 ; V_61 = V_61 -> V_24 ) {
if ( ( ( V_61 -> V_51 ) <= V_67 ) &&
( ( V_61 -> V_51 + V_61 -> V_71 ) > V_67 ) ) {
V_67 = V_61 -> V_51 + V_61 -> V_71 ;
}
}
if ( V_67 < ( V_22 -> V_54 ) ) {
return FALSE ;
}
V_70 = V_22 -> V_25 ;
T_8 = ( T_21 * ) F_68 ( V_22 -> V_54 ) ;
V_22 -> V_25 = F_69 ( T_8 , V_22 -> V_54 , V_22 -> V_54 ) ;
F_70 ( V_22 -> V_25 , V_78 ) ;
for ( V_68 = 0 , V_61 = V_22 ; V_61 ; V_61 = V_61 -> V_24 ) {
if ( V_61 -> V_71 ) {
if ( V_61 -> V_51 + V_61 -> V_71 > V_68 ) {
if ( V_61 -> V_51 >= V_22 -> V_54 ) {
V_61 -> V_26 |= V_72 ;
V_22 -> V_26 |= V_72 ;
} else if ( V_68 < V_61 -> V_51 ) {
V_22 -> error = L_5 ;
} else if ( V_68 - V_61 -> V_51 > V_61 -> V_71 )
V_22 -> error = L_6 ;
else if ( ! V_22 -> V_25 )
V_22 -> error = L_7 ;
else {
V_69 = V_61 -> V_71 ;
if ( V_61 -> V_51 + V_69 > V_22 -> V_54 ) {
V_61 -> V_26 |= V_72 ;
V_22 -> V_26 |= V_72 ;
V_69 = V_22 -> V_54 - V_61 -> V_51 ;
}
if ( V_61 -> V_51 < V_68 ) {
T_7 V_79 = F_71 ( V_61 -> V_71 , ( V_68 - V_61 -> V_51 ) ) ;
V_61 -> V_26 |= V_75 ;
V_22 -> V_26 |= V_75 ;
if ( memcmp ( T_8 + V_61 -> V_51 ,
F_64 ( V_61 -> V_25 , 0 , V_79 ) ,
V_79 )
) {
V_61 -> V_26 |= V_76 ;
V_22 -> V_26 |= V_76 ;
}
}
if ( V_69 < V_68 - V_61 -> V_51 ) {
V_22 -> error = L_8 ;
} else {
memcpy ( T_8 + V_68 ,
F_64 ( V_61 -> V_25 , ( V_68 - V_61 -> V_51 ) , V_69 - ( V_68 - V_61 -> V_51 ) ) ,
V_69 - ( V_68 - V_61 -> V_51 ) ) ;
V_68 = F_72 ( V_68 , ( V_61 -> V_51 + V_69 ) ) ;
}
}
} else {
if ( V_61 -> V_51 + V_61 -> V_71 < V_61 -> V_51 ) {
V_22 -> error = L_9 ;
}
}
if ( V_61 -> V_26 & V_27 )
V_61 -> V_26 &= ~ V_27 ;
else if ( V_61 -> V_25 )
F_23 ( V_61 -> V_25 ) ;
V_61 -> V_25 = NULL ;
}
}
if ( V_70 )
F_73 ( V_63 , V_70 ) ;
V_22 -> V_26 |= V_53 ;
V_22 -> V_58 = V_11 -> V_45 ;
V_22 -> V_59 = V_11 -> V_60 ;
if ( V_22 -> error ) {
F_53 ( V_52 , V_22 -> error ) ;
}
return TRUE ;
}
static T_14 *
F_74 ( T_17 * V_30 , T_20 * V_63 , const int V_51 ,
const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 , const T_7 V_64 ,
const T_7 V_65 , const T_11 V_66 ,
const T_11 V_80 )
{
T_14 * V_22 ;
T_15 * V_81 ;
T_11 V_82 ;
F_30 ( F_65 ( V_63 , V_51 , V_65 ) ) ;
V_22 = F_41 ( V_30 , V_11 , V_4 , T_8 , NULL ) ;
#if 0
if(strcmp(pinfo->current_proto, "DCERPC") == 0) {
printf("proto:%s num:%u id:%u offset:%u len:%u more:%u visited:%u\n",
pinfo->current_proto, pinfo->num, id, frag_offset, frag_data_len, more_frags, pinfo->fd->flags.visited);
if(fd_head != NULL) {
for(fd_item=fd_head->next;fd_item;fd_item=fd_item->next){
printf("fd_frame:%u fd_offset:%u len:%u datalen:%u\n",
fd_item->frame, fd_item->offset, fd_item->len, fd_item->datalen);
}
}
}
#endif
if ( ! V_11 -> V_43 -> V_26 . V_83 ) {
if ( V_80 && V_22 != NULL ) {
if ( V_11 -> V_45 <= V_22 -> V_20 ) {
V_82 = FALSE ;
for ( V_81 = V_22 -> V_24 ; V_81 ;
V_81 = V_81 -> V_24 ) {
if ( V_11 -> V_45 == V_81 -> V_20 &&
V_64 == V_81 -> V_51 ) {
V_82 = TRUE ;
break;
}
}
if ( V_82 ) {
if ( V_22 -> V_26 & V_53 ) {
F_53 ( V_52 ,
L_10 ) ;
} else {
return NULL ;
}
}
}
}
} else {
if ( V_22 != NULL && V_22 -> V_26 & V_53 ) {
if ( V_22 -> error )
F_53 ( V_52 , V_22 -> error ) ;
if ( V_11 -> V_45 > V_22 -> V_20 ) {
F_53 ( V_52 , L_4 ) ;
}
if ( V_64 + V_65 > V_22 -> V_54 ) {
if ( V_64 >= V_22 -> V_54 ) {
F_53 ( V_52 , L_3 ) ;
} else {
F_53 ( V_52 , L_4 ) ;
}
}
return V_22 ;
} else {
return NULL ;
}
}
if ( V_22 == NULL ) {
V_22 = F_24 ( 0 ) ;
F_43 ( V_30 , V_22 , V_11 , V_4 , T_8 ) ;
}
if ( F_61 ( V_22 , V_63 , V_51 , V_11 , V_64 ,
V_65 , V_66 ) ) {
return V_22 ;
} else {
return NULL ;
}
}
T_14 *
F_75 ( T_17 * V_30 , T_20 * V_63 , const int V_51 ,
const T_6 * V_11 , const T_7 V_4 , const void * T_8 ,
const T_7 V_64 , const T_7 V_65 ,
const T_11 V_66 )
{
return F_74 ( V_30 , V_63 , V_51 , V_11 , V_4 , T_8 ,
V_64 , V_65 , V_66 , TRUE ) ;
}
T_14 *
F_76 ( T_17 * V_30 , T_20 * V_63 ,
const int V_51 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 ,
const T_7 V_64 ,
const T_7 V_65 , const T_11 V_66 )
{
return F_74 ( V_30 , V_63 , V_51 , V_11 , V_4 , T_8 ,
V_64 , V_65 , V_66 , FALSE ) ;
}
T_14 *
F_77 ( T_17 * V_30 , T_20 * V_63 , const int V_51 ,
const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 , const T_7 V_64 ,
const T_7 V_65 , const T_11 V_66 )
{
T_10 V_84 ;
T_14 * V_22 ;
T_5 V_85 ;
if ( V_11 -> V_43 -> V_26 . V_83 ) {
V_84 . V_20 = V_11 -> V_45 ;
V_84 . V_4 = V_4 ;
return ( T_14 * ) F_49 ( V_30 -> V_41 , & V_84 ) ;
}
V_22 = F_41 ( V_30 , V_11 , V_4 , T_8 , & V_85 ) ;
if ( V_22 == NULL ) {
V_22 = F_24 ( 0 ) ;
V_85 = F_43 ( V_30 , V_22 , V_11 , V_4 , T_8 ) ;
}
if ( F_78 ( V_63 ) > F_79 ( V_63 ) )
return NULL ;
if ( F_61 ( V_22 , V_63 , V_51 , V_11 , V_64 ,
V_65 , V_66 ) ) {
F_56 ( V_30 , V_85 ) ;
F_57 ( V_30 , V_22 , V_11 , V_4 ) ;
return V_22 ;
} else {
return NULL ;
}
}
static void
F_80 ( T_14 * V_22 , const T_6 * V_11 )
{
T_15 * V_61 = NULL ;
T_15 * V_86 = NULL ;
T_7 V_68 = 0 , V_87 = 0 ;
T_20 * V_70 = NULL ;
T_21 * T_8 ;
for( V_61 = V_22 -> V_24 ; V_61 ; V_61 = V_61 -> V_24 ) {
if( ! V_86 || V_86 -> V_51 != V_61 -> V_51 ) {
V_87 += V_61 -> V_71 ;
}
V_86 = V_61 ;
}
V_70 = V_22 -> V_25 ;
T_8 = ( T_21 * ) F_68 ( V_87 ) ;
V_22 -> V_25 = F_69 ( T_8 , V_87 , V_87 ) ;
F_70 ( V_22 -> V_25 , V_78 ) ;
V_22 -> V_71 = V_87 ;
V_86 = NULL ;
for ( V_61 = V_22 -> V_24 ; V_61 ; V_61 = V_61 -> V_24 ) {
if ( V_61 -> V_71 ) {
if( ! V_86 || V_86 -> V_51 != V_61 -> V_51 ) {
memcpy ( T_8 + V_68 , F_64 ( V_61 -> V_25 , 0 , V_61 -> V_71 ) , V_61 -> V_71 ) ;
V_68 += V_61 -> V_71 ;
} else {
V_61 -> V_26 |= V_75 ;
V_22 -> V_26 |= V_75 ;
if( V_86 -> V_71 != V_61 -> V_71
|| F_63 ( V_86 -> V_25 , 0 , F_64 ( V_61 -> V_25 , 0 , V_86 -> V_71 ) , V_86 -> V_71 ) ) {
V_61 -> V_26 |= V_76 ;
V_22 -> V_26 |= V_76 ;
}
}
}
V_86 = V_61 ;
}
for ( V_61 = V_22 -> V_24 ; V_61 ; V_61 = V_61 -> V_24 ) {
if ( V_61 -> V_26 & V_27 )
V_61 -> V_26 &= ~ V_27 ;
else if ( V_61 -> V_25 )
F_23 ( V_61 -> V_25 ) ;
V_61 -> V_25 = NULL ;
}
if ( V_70 )
F_23 ( V_70 ) ;
V_22 -> V_26 |= V_53 ;
V_22 -> V_58 = V_11 -> V_45 ;
V_22 -> V_59 = V_11 -> V_60 ;
}
static T_11
F_81 ( T_14 * V_22 , T_20 * V_63 , const int V_51 ,
const T_6 * V_11 , const T_7 V_88 ,
const T_7 V_65 , const T_11 V_66 )
{
T_15 * V_43 ;
T_15 * V_61 ;
T_15 * V_86 ;
T_7 V_67 , V_68 ;
T_7 V_89 ;
V_89 = V_88 ;
if ( V_22 -> V_47 != 0 )
if ( V_89 >= V_22 -> V_47 )
V_89 = V_88 - V_22 -> V_47 ;
if( V_22 -> V_26 & V_53 && V_89 >= V_22 -> V_54 &&
V_22 -> V_26 & V_56 ) {
T_7 V_90 = 0 ;
V_68 = 0 ;
for( V_61 = V_22 -> V_24 ; V_61 ; V_61 = V_61 -> V_24 ) {
if( ! V_61 -> V_25 ) {
if( V_61 -> V_26 & V_75 ) {
V_61 -> V_25 = F_62 ( V_22 -> V_25 , V_90 ) ;
} else {
V_61 -> V_25 = F_62 ( V_22 -> V_25 , V_68 ) ;
V_90 = V_68 ;
V_68 += V_61 -> V_71 ;
}
V_61 -> V_26 |= V_27 ;
}
V_61 -> V_26 &= ( ~ V_72 ) & ( ~ V_73 ) ;
}
V_22 -> V_26 &= ~ ( V_53 | V_56 | V_55 ) ;
V_22 -> V_26 &= ( ~ V_72 ) & ( ~ V_73 ) ;
V_22 -> V_54 = 0 ;
V_22 -> V_58 = 0 ;
V_22 -> V_59 = 0 ;
}
V_43 = F_5 ( T_15 ) ;
V_43 -> V_24 = NULL ;
V_43 -> V_26 = 0 ;
V_43 -> V_20 = V_11 -> V_45 ;
V_43 -> V_51 = V_89 ;
V_43 -> V_71 = V_65 ;
V_43 -> V_25 = NULL ;
V_43 -> error = NULL ;
if ( V_43 -> V_20 > V_22 -> V_20 )
V_22 -> V_20 = V_43 -> V_20 ;
if ( ! V_66 ) {
if ( V_22 -> V_26 & V_55 ) {
if ( V_22 -> V_54 != V_43 -> V_51 ) {
V_43 -> V_26 |= V_73 ;
V_22 -> V_26 |= V_73 ;
}
} else {
V_22 -> V_54 = V_43 -> V_51 ;
V_22 -> V_26 |= V_55 ;
}
}
if ( V_22 -> V_26 & V_53 ) {
V_43 -> V_26 |= V_75 ;
V_22 -> V_26 |= V_75 ;
if ( V_43 -> V_51 > V_22 -> V_54 ) {
V_43 -> V_26 |= V_72 ;
V_22 -> V_26 |= V_72 ;
F_59 ( V_22 , V_43 ) ;
return TRUE ;
}
V_68 = 0 ;
V_86 = NULL ;
for ( V_61 = V_22 -> V_24 ; V_61 && ( V_61 -> V_51 != V_43 -> V_51 ) ; V_61 = V_61 -> V_24 ) {
if ( ! V_86 || V_86 -> V_51 != V_61 -> V_51 ) {
V_68 += V_61 -> V_71 ;
}
V_86 = V_61 ;
}
if( V_61 ) {
if( V_61 -> V_71 != V_43 -> V_71 ) {
V_43 -> V_26 |= V_76 ;
V_22 -> V_26 |= V_76 ;
F_59 ( V_22 , V_43 ) ;
return TRUE ;
}
F_30 ( V_22 -> V_71 >= V_68 + V_43 -> V_71 ) ;
if ( F_63 ( V_22 -> V_25 , V_68 ,
F_64 ( V_63 , V_51 , V_43 -> V_71 ) , V_43 -> V_71 ) ) {
V_43 -> V_26 |= V_76 ;
V_22 -> V_26 |= V_76 ;
F_59 ( V_22 , V_43 ) ;
return TRUE ;
}
F_59 ( V_22 , V_43 ) ;
return TRUE ;
} else {
F_59 ( V_22 , V_43 ) ;
return TRUE ;
}
}
if ( V_43 -> V_71 ) {
if ( ! F_65 ( V_63 , V_51 , V_43 -> V_71 ) ) {
F_10 ( T_15 , V_43 ) ;
return FALSE ;
}
V_43 -> V_25 = F_67 ( V_63 , V_51 , V_43 -> V_71 ) ;
}
F_59 ( V_22 , V_43 ) ;
if( ! ( V_22 -> V_26 & V_55 ) ) {
return FALSE ;
}
V_67 = 0 ;
for( V_61 = V_22 -> V_24 ; V_61 ; V_61 = V_61 -> V_24 ) {
if ( V_61 -> V_51 == V_67 ) {
V_67 ++ ;
}
}
if ( V_67 <= V_22 -> V_54 ) {
return FALSE ;
}
if ( V_67 > ( V_22 -> V_54 + 1 ) ) {
V_43 -> V_26 |= V_72 ;
V_22 -> V_26 |= V_72 ;
}
F_80 ( V_22 , V_11 ) ;
return TRUE ;
}
static T_14 *
F_82 ( T_17 * V_30 , T_20 * V_63 ,
const int V_51 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 ,
T_7 V_88 , const T_7 V_65 ,
const T_11 V_66 , const T_7 V_26 ,
T_5 * V_42 )
{
T_14 * V_22 ;
T_5 V_85 ;
V_22 = F_41 ( V_30 , V_11 , V_4 , T_8 , & V_85 ) ;
if ( V_11 -> V_43 -> V_26 . V_83 ) {
if ( V_22 != NULL && V_22 -> V_26 & V_53 ) {
if ( V_42 != NULL )
* V_42 = V_85 ;
return V_22 ;
} else {
return NULL ;
}
}
if ( V_22 == NULL ) {
V_22 = F_24 ( V_50 ) ;
if( ( V_26 & ( V_91 | V_92 ) )
&& ! V_66 ) {
if ( V_42 != NULL )
* V_42 = NULL ;
V_22 -> V_58 = V_11 -> V_45 ;
V_22 -> V_59 = V_11 -> V_60 ;
return V_22 ;
}
V_85 = F_43 ( V_30 , V_22 , V_11 , V_4 , T_8 ) ;
if ( V_42 != NULL )
* V_42 = V_85 ;
if ( V_26 & V_91 )
V_88 = 0 ;
} else {
if ( V_42 != NULL )
* V_42 = V_85 ;
if ( V_26 & V_91 ) {
T_15 * V_43 ;
for ( V_43 = V_22 ; V_43 != NULL ; V_43 = V_43 -> V_24 ) {
if ( V_43 -> V_24 == NULL )
V_88 = V_43 -> V_51 + 1 ;
}
}
}
if ( F_81 ( V_22 , V_63 , V_51 , V_11 ,
V_88 , V_65 , V_66 ) ) {
return V_22 ;
} else {
return NULL ;
}
}
T_14 *
F_83 ( T_17 * V_30 , T_20 * V_63 , const int V_51 ,
const T_6 * V_11 , const T_7 V_4 , const void * T_8 ,
const T_7 V_88 , const T_7 V_65 ,
const T_11 V_66 , const T_7 V_26 )
{
return F_82 ( V_30 , V_63 , V_51 , V_11 , V_4 , T_8 ,
V_88 , V_65 ,
V_66 , V_26 , NULL ) ;
}
static T_14 *
F_84 ( T_17 * V_30 , T_20 * V_63 ,
const int V_51 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 ,
const T_7 V_88 ,
const T_7 V_65 ,
const T_11 V_66 , const T_7 V_26 )
{
T_10 V_84 ;
T_14 * V_22 ;
T_5 V_85 ;
if ( V_11 -> V_43 -> V_26 . V_83 ) {
V_84 . V_20 = V_11 -> V_45 ;
V_84 . V_4 = V_4 ;
return ( T_14 * ) F_49 ( V_30 -> V_41 , & V_84 ) ;
}
V_22 = F_82 ( V_30 , V_63 , V_51 , V_11 , V_4 , T_8 ,
V_88 , V_65 ,
V_66 ,
V_26 ,
& V_85 ) ;
if ( V_22 ) {
if ( V_85 != NULL )
F_56 ( V_30 , V_85 ) ;
F_57 ( V_30 , V_22 , V_11 , V_4 ) ;
return V_22 ;
} else {
return NULL ;
}
}
T_14 *
F_85 ( T_17 * V_30 , T_20 * V_63 , const int V_51 ,
const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 ,
const T_7 V_88 , const T_7 V_65 ,
const T_11 V_66 )
{
return F_84 ( V_30 , V_63 , V_51 , V_11 , V_4 , T_8 ,
V_88 , V_65 ,
V_66 , 0 ) ;
}
T_14 *
F_86 ( T_17 * V_30 , T_20 * V_63 ,
const int V_51 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 ,
const T_7 V_88 , const T_7 V_65 ,
const T_11 V_66 )
{
return F_84 ( V_30 , V_63 , V_51 , V_11 , V_4 , T_8 ,
V_88 , V_65 ,
V_66 ,
V_92 ) ;
}
T_14 *
F_87 ( T_17 * V_30 , T_20 * V_63 , const int V_51 ,
const T_6 * V_11 , const T_7 V_4 ,
const void * T_8 , const T_7 V_65 ,
const T_11 V_66 )
{
return F_84 ( V_30 , V_63 , V_51 , V_11 , V_4 , T_8 ,
0 , V_65 , V_66 ,
V_91 ) ;
}
static void
F_88 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 ,
const T_7 V_51 )
{
T_14 * V_93 , * V_94 ;
T_15 * V_43 , * V_95 ;
T_20 * V_70 ;
if ( V_51 == 0 ) {
return;
}
V_93 = F_41 ( V_30 , V_11 , V_4 , T_8 , NULL ) ;
if ( V_93 == NULL ) {
F_89 () ;
return;
}
if ( V_93 -> V_26 & V_55 && V_93 -> V_54 <= V_51 ) {
return;
}
V_94 = F_41 ( V_30 , V_11 , V_4 + V_51 , T_8 , NULL ) ;
if ( V_94 != NULL ) {
for( V_95 = V_93 ; V_95 -> V_24 != NULL ; V_95 = V_95 -> V_24 ) {}
V_43 = V_94 -> V_24 ;
if ( V_43 && V_43 -> V_51 != 0 ) {
V_95 -> V_24 = V_43 ;
for (; V_43 ; V_43 = V_43 -> V_24 ) {
V_43 -> V_51 += V_51 ;
if ( V_93 -> V_20 < V_43 -> V_20 ) {
V_93 -> V_20 = V_43 -> V_20 ;
}
}
if ( V_94 -> V_26 & V_55 ) {
V_93 -> V_26 |= V_55 ;
V_93 -> V_54 = V_94 -> V_54 + V_51 ;
}
V_94 -> V_24 = NULL ;
V_70 = F_45 ( V_30 , V_11 , V_4 + V_51 , T_8 ) ;
if ( V_70 )
F_23 ( V_70 ) ;
}
}
}
static T_14 *
F_90 ( T_17 * V_30 , T_20 * V_63 ,
const int V_51 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 ,
const T_7 V_65 ,
const T_11 V_96 , const T_11 V_97 ,
const T_7 V_98 , const T_7 V_99 ,
const T_7 V_26 )
{
T_10 V_84 ;
T_20 * V_70 ;
T_5 V_85 ;
T_14 * V_93 , * V_94 ;
T_15 * V_43 , * V_95 ;
T_7 V_88 , V_100 ;
if ( V_11 -> V_43 -> V_26 . V_83 ) {
V_84 . V_20 = V_11 -> V_45 ;
V_84 . V_4 = V_4 ;
V_93 = ( T_14 * ) F_49 ( V_30 -> V_41 , & V_84 ) ;
return V_93 ;
}
V_93 = NULL ;
if ( V_96 ) {
V_88 = 0 ;
V_93 = F_41 ( V_30 , V_11 , V_4 - V_88 , T_8 , NULL ) ;
if ( ( V_26 & V_101 ) &&
V_93 && ( ( V_93 -> V_20 + V_99 ) < V_11 -> V_45 ) ) {
V_70 = F_45 ( V_30 , V_11 , V_4 - V_88 , T_8 ) ;
if ( V_70 )
F_23 ( V_70 ) ;
V_93 = NULL ;
}
if ( V_93 == NULL ) {
V_93 = F_24 ( V_50 ) ;
F_43 ( V_30 , V_93 , V_11 , V_4 - V_88 , T_8 ) ;
}
V_43 = NULL ;
for ( V_88 = 1 ; V_88 < V_98 ; V_88 ++ ) {
V_94 = F_41 ( V_30 , V_11 , V_4 - V_88 , T_8 , NULL ) ;
if ( V_94 != NULL ) {
V_95 = V_94 ;
V_94 -> V_20 = 0 ;
for ( V_43 = V_94 -> V_24 ; V_43 && V_43 -> V_51 < V_88 ; V_43 = V_43 -> V_24 ) {
V_95 = V_43 ;
if ( V_94 -> V_20 < V_43 -> V_20 ) {
V_94 -> V_20 = V_43 -> V_20 ;
}
}
V_95 -> V_24 = NULL ;
break;
}
}
if ( V_43 != NULL ) {
V_100 = 0 ;
for ( V_95 = V_43 ; V_95 ; V_95 = V_95 -> V_24 ) {
V_95 -> V_51 -= V_88 ;
V_100 = V_95 -> V_51 ;
if ( V_93 -> V_20 < V_95 -> V_20 ) {
V_93 -> V_20 = V_95 -> V_20 ;
}
}
F_60 ( V_93 , V_43 ) ;
if ( V_94 != NULL ) {
if ( V_94 -> V_26 & V_55 &&
V_94 -> V_54 >= V_88 ) {
V_93 -> V_26 |= V_55 ;
V_93 -> V_54 = V_94 -> V_54 - V_88 ;
V_94 -> V_26 &= ~ V_55 ;
V_94 -> V_54 = 0 ;
}
if ( V_94 -> V_24 == NULL ) {
V_70 = F_45 ( V_30 , V_11 , V_4 - V_88 , T_8 ) ;
if ( V_70 )
F_23 ( V_70 ) ;
}
} else {
F_88 ( V_30 , V_11 , V_4 ,
T_8 , V_100 ) ;
}
}
V_88 = 0 ;
} else {
for ( V_88 = 1 ; V_88 < V_98 ; V_88 ++ ) {
V_93 = F_41 ( V_30 , V_11 , V_4 - V_88 , T_8 , NULL ) ;
if ( ( V_26 & V_101 ) &&
V_93 && ( ( V_93 -> V_20 + V_99 ) < V_11 -> V_45 ) ) {
V_70 = F_45 ( V_30 , V_11 , V_4 - V_88 , T_8 ) ;
if ( V_70 )
F_23 ( V_70 ) ;
V_93 = NULL ;
}
if ( V_93 != NULL ) {
if ( V_93 -> V_26 & V_55 &&
V_93 -> V_54 < V_88 ) {
V_93 = NULL ;
}
break;
}
}
if ( V_93 == NULL ) {
V_88 = 1 ;
V_93 = F_24 ( V_50 ) ;
F_43 ( V_30 , V_93 , V_11 , V_4 - V_88 , T_8 ) ;
}
}
if ( V_97 ) {
V_95 = V_93 ;
for ( V_43 = V_93 -> V_24 ; V_43 && V_43 -> V_51 <= V_88 ; V_43 = V_43 -> V_24 ) {
V_95 = V_43 ;
}
if ( V_43 != NULL ) {
V_95 -> V_24 = NULL ;
V_93 -> V_20 = 0 ;
for ( V_95 = V_93 -> V_24 ; V_95 ; V_95 = V_95 -> V_24 ) {
if ( V_93 -> V_20 < V_95 -> V_20 ) {
V_93 -> V_20 = V_95 -> V_20 ;
}
}
while ( V_43 && V_43 -> V_51 == V_88 + 1 ) {
T_15 * V_23 ;
V_23 = V_43 -> V_24 ;
if ( V_43 -> V_25 && ! ( V_43 -> V_26 & V_27 ) )
F_23 ( V_43 -> V_25 ) ;
F_10 ( T_15 , V_43 ) ;
V_43 = V_23 ;
}
}
if ( V_43 != NULL ) {
V_94 = F_41 ( V_30 , V_11 , V_4 + 1 , T_8 , NULL ) ;
if ( V_94 == NULL ) {
V_94 = F_24 ( V_50 ) ;
F_43 ( V_30 , V_94 , V_11 , V_4 + 1 , T_8 ) ;
}
V_100 = 0 ;
for ( V_95 = V_43 ; V_95 ; V_95 = V_95 -> V_24 ) {
V_95 -> V_51 -= ( V_88 + 1 ) ;
V_100 = V_95 -> V_51 ;
if ( V_94 -> V_20 < V_43 -> V_20 ) {
V_94 -> V_20 = V_43 -> V_20 ;
}
}
F_60 ( V_94 , V_43 ) ;
if ( V_93 -> V_26 & V_55 &&
V_93 -> V_54 > V_88 ) {
V_94 -> V_26 |= V_55 ;
V_94 -> V_54 = V_93 -> V_54 - ( V_88 + 1 ) ;
V_93 -> V_26 &= ~ V_55 ;
V_93 -> V_54 = 0 ;
} else {
F_88 ( V_30 , V_11 , V_4 + 1 ,
T_8 , V_100 ) ;
}
}
} else {
F_88 ( V_30 , V_11 , V_4 - V_88 , T_8 ,
V_88 + 1 ) ;
}
V_93 = F_82 ( V_30 , V_63 , V_51 , V_11 ,
V_4 - V_88 , T_8 ,
V_88 , V_65 ,
! V_97 , 0 , & V_85 ) ;
if ( V_93 ) {
if ( V_85 != NULL )
F_56 ( V_30 , V_85 ) ;
F_58 ( V_30 , V_93 , V_11 , V_4 - V_88 ) ;
return V_93 ;
} else {
return NULL ;
}
}
T_14 *
F_91 ( T_17 * V_30 , T_20 * V_63 ,
const int V_51 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 ,
const T_7 V_65 ,
const T_11 V_96 , const T_11 V_97 ,
const T_7 V_98 )
{
return F_90 ( V_30 , V_63 , V_51 , V_11 ,
V_4 , T_8 , V_65 ,
V_96 , V_97 , V_98 , 0 , 0 ) ;
}
T_14 *
F_92 ( T_17 * V_30 , T_20 * V_63 ,
const int V_51 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 ,
const T_7 V_65 ,
const T_11 V_96 , const T_11 V_97 ,
const T_7 V_98 , const T_7 V_99 )
{
return F_90 ( V_30 , V_63 , V_51 , V_11 ,
V_4 , T_8 , V_65 ,
V_96 , V_97 , V_98 , V_99 ,
V_101 ) ;
}
void
F_93 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 ,
const T_7 V_48 )
{
T_14 * V_22 ;
if ( V_11 -> V_43 -> V_26 . V_83 ) {
return;
}
V_22 = F_41 ( V_30 , V_11 , V_4 , T_8 , NULL ) ;
if ( V_22 == NULL ) {
V_22 = F_5 ( T_14 ) ;
V_22 -> V_24 = NULL ;
V_22 -> V_20 = 0 ;
V_22 -> V_51 = 0 ;
V_22 -> V_71 = 0 ;
V_22 -> V_47 = 0 ;
V_22 -> V_54 = V_48 ;
V_22 -> V_58 = 0 ;
V_22 -> V_59 = 0 ;
V_22 -> V_26 = V_50 | V_55 ;
V_22 -> V_25 = NULL ;
V_22 -> error = NULL ;
F_43 ( V_30 , V_22 , V_11 , V_4 , T_8 ) ;
}
}
T_14 *
F_94 ( T_17 * V_30 , const T_6 * V_11 ,
const T_7 V_4 , const void * T_8 )
{
T_10 V_84 ;
T_10 * V_57 ;
T_14 * V_22 ;
T_5 V_85 ;
if ( V_11 -> V_43 -> V_26 . V_83 ) {
V_84 . V_20 = V_11 -> V_45 ;
V_84 . V_4 = V_4 ;
return ( T_14 * ) F_49 ( V_30 -> V_41 , & V_84 ) ;
}
V_22 = F_41 ( V_30 , V_11 , V_4 , T_8 , & V_85 ) ;
if ( V_22 ) {
V_22 -> V_54 = V_22 -> V_51 ;
V_22 -> V_26 |= V_55 ;
F_80 ( V_22 , V_11 ) ;
F_56 ( V_30 , V_85 ) ;
F_57 ( V_30 , V_22 , V_11 , V_4 ) ;
if ( V_22 -> V_24 != NULL ) {
V_57 = F_5 ( T_10 ) ;
V_57 -> V_20 = V_11 -> V_45 ;
V_57 -> V_4 = V_4 ;
F_44 ( V_30 -> V_41 , V_57 , V_22 ) ;
}
return V_22 ;
} else {
return NULL ;
}
}
T_20 *
F_95 ( T_20 * V_63 , const int V_51 , T_6 * V_11 ,
const char * V_102 , T_14 * V_22 , const T_22 * V_103 ,
T_11 * V_104 , T_23 * V_105 )
{
T_20 * V_106 ;
T_11 V_107 ;
T_24 * V_108 ;
if ( V_22 != NULL && V_11 -> V_45 == V_22 -> V_58 && V_11 -> V_60 == V_22 -> V_59 ) {
if ( V_22 -> V_24 != NULL ) {
V_106 = F_96 ( V_63 , V_22 -> V_25 ) ;
F_97 ( V_11 , V_106 , V_102 ) ;
if ( V_22 -> V_26 & V_50 ) {
V_107 = ! F_98 (
V_22 , V_103 , V_105 , V_11 , V_106 , & V_108 ) ;
} else {
V_107 = ! F_99 ( V_22 ,
V_103 , V_105 , V_11 , V_106 , & V_108 ) ;
}
} else {
V_106 = F_62 ( V_63 , V_51 ) ;
V_11 -> V_109 = FALSE ;
V_107 = TRUE ;
}
if ( V_104 != NULL )
* V_104 = V_107 ;
} else {
V_106 = NULL ;
if ( V_22 != NULL && V_103 -> V_110 != NULL ) {
F_100 ( V_105 ,
* ( V_103 -> V_110 ) , V_63 ,
0 , 0 , V_22 -> V_58 ) ;
}
}
return V_106 ;
}
static void
F_101 ( T_15 * V_43 , const int V_51 , const T_22 * V_103 ,
T_23 * V_111 , T_24 * V_112 , const T_11 V_113 ,
const T_7 V_114 , T_20 * V_63 , T_6 * V_11 )
{
T_24 * V_115 = NULL ;
int V_116 ;
if ( V_113 ) {
T_25 * V_102 ;
if ( V_114 == 1 ) {
V_102 = F_102 ( F_103 ( * ( V_103 -> V_117 ) ) ) ;
} else {
V_102 = F_102 ( F_103 ( * ( V_103 -> V_118 ) ) ) ;
}
F_104 ( V_112 , L_11 , V_114 , V_102 , F_79 ( V_63 ) ,
F_105 ( F_79 ( V_63 ) , L_12 , L_13 ) ) ;
V_78 ( V_102 ) ;
} else {
F_106 ( V_112 , L_14 ) ;
}
F_106 ( V_112 , L_15 , V_43 -> V_20 , V_43 -> V_71 ) ;
if ( V_43 -> V_26 & ( V_76
| V_73 | V_72 ) ) {
V_116 = * ( V_103 -> V_119 ) ;
} else {
V_116 = * ( V_103 -> V_117 ) ;
}
if ( V_43 -> V_71 == 0 ) {
V_115 = F_107 ( V_111 , V_116 ,
V_63 , V_51 , V_43 -> V_71 ,
V_43 -> V_20 ,
L_16 ,
V_43 -> V_20 ) ;
} else {
V_115 = F_107 ( V_111 , V_116 ,
V_63 , V_51 , V_43 -> V_71 ,
V_43 -> V_20 ,
L_17 ,
V_43 -> V_20 ,
V_51 ,
V_51 + V_43 -> V_71 - 1 ,
V_43 -> V_71 ,
F_105 ( V_43 -> V_71 , L_12 , L_13 ) ) ;
}
F_108 ( V_115 ) ;
F_109 ( V_11 , V_43 -> V_20 ) ;
if ( V_43 -> V_26 & ( V_75 | V_76
| V_73 | V_72 ) ) {
T_23 * V_120 = NULL ;
V_120 = F_110 ( V_115 , * ( V_103 -> V_121 ) ) ;
if ( V_43 -> V_26 & V_75 ) {
V_115 = F_111 ( V_120 ,
* ( V_103 -> V_122 ) ,
V_63 , 0 , 0 ,
TRUE ) ;
F_108 ( V_115 ) ;
}
if ( V_43 -> V_26 & V_76 ) {
V_115 = F_111 ( V_120 ,
* ( V_103 -> V_123 ) ,
V_63 , 0 , 0 ,
TRUE ) ;
F_108 ( V_115 ) ;
}
if ( V_43 -> V_26 & V_73 ) {
V_115 = F_111 ( V_120 ,
* ( V_103 -> V_124 ) ,
V_63 , 0 , 0 ,
TRUE ) ;
F_108 ( V_115 ) ;
}
if ( V_43 -> V_26 & V_72 ) {
V_115 = F_111 ( V_120 ,
* ( V_103 -> V_125 ) ,
V_63 , 0 , 0 ,
TRUE ) ;
F_108 ( V_115 ) ;
}
}
}
static T_11
F_112 ( T_14 * V_22 , const T_22 * V_103 ,
T_6 * V_11 )
{
if ( V_22 -> V_26 & ( V_76
| V_73 | V_72 ) ) {
F_113 ( V_11 -> V_126 , V_127 , L_18 , V_103 -> V_128 ) ;
return TRUE ;
}
return FALSE ;
}
T_11
F_99 ( T_14 * V_22 , const T_22 * V_103 ,
T_23 * V_105 , T_6 * V_11 , T_20 * V_63 , T_24 * * V_112 )
{
T_15 * V_43 ;
T_23 * V_111 ;
T_11 V_113 ;
T_7 V_114 = 0 ;
V_11 -> V_109 = FALSE ;
* V_112 = F_114 ( V_105 , * ( V_103 -> V_118 ) , V_63 , 0 , - 1 , V_129 ) ;
F_108 ( * V_112 ) ;
V_111 = F_110 ( * V_112 , * ( V_103 -> V_130 ) ) ;
V_113 = TRUE ;
for ( V_43 = V_22 -> V_24 ; V_43 != NULL ; V_43 = V_43 -> V_24 ) {
V_114 ++ ;
}
for ( V_43 = V_22 -> V_24 ; V_43 != NULL ; V_43 = V_43 -> V_24 ) {
F_101 ( V_43 , V_43 -> V_51 , V_103 , V_111 , * V_112 , V_113 , V_114 , V_63 , V_11 ) ;
V_113 = FALSE ;
}
if ( V_103 -> V_131 ) {
T_24 * V_132 = F_100 ( V_111 , * ( V_103 -> V_131 ) ,
V_63 , 0 , 0 , V_114 ) ;
F_108 ( V_132 ) ;
}
if ( V_103 -> V_133 ) {
T_24 * V_132 = F_100 ( V_111 , * ( V_103 -> V_133 ) ,
V_63 , 0 , 0 , F_79 ( V_63 ) ) ;
F_108 ( V_132 ) ;
}
if ( V_103 -> V_134 ) {
T_24 * V_132 = F_114 ( V_111 , * ( V_103 -> V_134 ) ,
V_63 , 0 , F_79 ( V_63 ) , V_129 ) ;
F_108 ( V_132 ) ;
}
return F_112 ( V_22 , V_103 , V_11 ) ;
}
T_11
F_98 ( T_14 * V_22 , const T_22 * V_103 ,
T_23 * V_105 , T_6 * V_11 , T_20 * V_63 , T_24 * * V_112 )
{
T_7 V_51 , V_135 , V_114 = 0 ;
T_15 * V_43 , * V_86 ;
T_23 * V_111 ;
T_11 V_113 ;
V_11 -> V_109 = FALSE ;
* V_112 = F_114 ( V_105 , * ( V_103 -> V_118 ) , V_63 , 0 , - 1 , V_129 ) ;
F_108 ( * V_112 ) ;
V_111 = F_110 ( * V_112 , * ( V_103 -> V_130 ) ) ;
V_51 = 0 ;
V_135 = 0 ;
V_86 = NULL ;
V_113 = TRUE ;
for ( V_43 = V_22 -> V_24 ; V_43 != NULL ; V_43 = V_43 -> V_24 ) {
V_114 ++ ;
}
for ( V_43 = V_22 -> V_24 ; V_43 != NULL ; V_43 = V_43 -> V_24 ) {
if ( V_86 == NULL || V_86 -> V_51 != V_43 -> V_51 ) {
V_51 = V_135 ;
V_135 += V_43 -> V_71 ;
}
V_86 = V_43 ;
F_101 ( V_43 , V_51 , V_103 , V_111 , * V_112 , V_113 , V_114 , V_63 , V_11 ) ;
V_113 = FALSE ;
}
if ( V_103 -> V_131 ) {
T_24 * V_132 = F_100 ( V_111 , * ( V_103 -> V_131 ) ,
V_63 , 0 , 0 , V_114 ) ;
F_108 ( V_132 ) ;
}
if ( V_103 -> V_133 ) {
T_24 * V_132 = F_100 ( V_111 , * ( V_103 -> V_133 ) ,
V_63 , 0 , 0 , F_79 ( V_63 ) ) ;
F_108 ( V_132 ) ;
}
if ( V_103 -> V_134 ) {
T_24 * V_132 = F_114 ( V_111 , * ( V_103 -> V_134 ) ,
V_63 , 0 , F_79 ( V_63 ) , V_129 ) ;
F_108 ( V_132 ) ;
}
return F_112 ( V_22 , V_103 , V_11 ) ;
}
static void
F_115 ( T_5 V_136 , T_5 T_13 V_12 )
{
T_19 * V_32 = ( T_19 * ) V_136 ;
F_33 ( V_32 -> V_30 , V_32 -> V_31 ) ;
}
static void
F_116 ( void )
{
F_117 ( V_33 , F_115 , NULL ) ;
}
static void
F_118 ( T_5 V_136 , T_5 T_13 V_12 )
{
T_19 * V_32 = ( T_19 * ) V_136 ;
F_39 ( V_32 -> V_30 ) ;
}
static void
F_119 ( void )
{
F_117 ( V_33 , F_118 , NULL ) ;
}
void F_120 ( void )
{
F_121 ( & F_116 ) ;
F_122 ( & F_119 ) ;
}
static void
F_123 ( T_5 V_136 , T_5 T_13 V_12 )
{
T_19 * V_32 = ( T_19 * ) V_136 ;
F_39 ( V_32 -> V_30 ) ;
V_78 ( V_32 ) ;
}
void
F_124 ( void )
{
F_117 ( V_33 , F_123 , NULL ) ;
F_125 ( V_33 ) ;
}
