static void
F_1 ( T_1 * V_1 , int V_2 , T_2 * V_3 , int V_4 )
{
if ( V_4 == V_5 ) {
F_2 ( & ( V_1 -> V_6 ) , & ( V_1 -> V_7 ) ) ;
F_3 ( & ( V_1 -> V_7 ) ) ;
}
if ( V_2 == V_8 ) {
F_4 ( & ( V_1 -> V_6 ) , V_3 ) ;
F_4 ( & ( V_1 -> V_7 ) , V_3 ) ;
} else if ( V_2 == V_9 ) {
F_2 ( & ( V_1 -> V_6 ) , V_3 ) ;
F_2 ( & ( V_1 -> V_7 ) , V_3 ) ;
} else {
fprintf ( V_10 , L_1 , V_2 ) ;
}
}
static void
F_5 ( T_2 * V_11 , T_2 * V_12 , T_2 * V_13 , T_2 * V_14 ,
T_2 * V_15 , T_2 * V_16 )
{
long double V_17 , V_18 , V_19 , V_20 , V_21 ;
V_17 = ( long double ) V_16 -> V_20 + ( V_16 -> V_21 / 1000000000.0L ) ;
V_18 = ( long double ) V_15 -> V_20 + ( V_15 -> V_21 / 1000000000.0L ) ;
V_19 = V_17 / V_18 ;
F_6 ( V_14 , V_12 ) ;
F_2 ( V_14 , V_11 ) ;
V_20 = V_19 * ( long double ) V_14 -> V_20 ;
V_21 = V_19 * ( long double ) V_14 -> V_21 ;
V_21 += ( V_20 - F_7 ( V_20 ) ) * 1000000000.0L ;
while ( V_21 > 1000000000L ) {
V_20 += 1 ;
V_21 -= 1000000000L ;
}
while ( V_21 < 0 ) {
V_20 -= 1 ;
V_21 += 1000000000L ;
}
V_14 -> V_20 = ( V_22 ) V_20 ;
V_14 -> V_21 = ( int ) V_21 ;
F_4 ( V_14 , V_13 ) ;
}
const T_3 *
F_8 ( const T_3 * V_23 , int * V_24 , int * V_25 , int * V_26 , T_4 * V_27 , int * V_28 , int * V_29 , long double * V_30 ) {
const T_3 * V_31 = V_23 ;
if ( ! V_23 || ! V_28 || ! V_29 || ! V_30 )
return L_2 ;
while ( F_9 ( V_31 [ 0 ] ) )
++ V_31 ;
if ( V_24 && V_25 && V_26 ) {
if ( V_31 [ 0 ] == '\0' )
return L_3 ;
if ( sscanf ( V_31 , L_4 , V_24 , V_25 , V_26 , V_28 , V_29 , V_30 ) == 6 ) {
F_10 ( V_24 ) ;
F_11 ( V_25 ) ;
F_12 ( V_26 ) ;
F_13 ( V_28 ) ;
F_14 ( V_29 ) ;
F_15 ( V_30 ) ;
} else if ( sscanf ( V_31 , L_5 , V_28 , V_29 , V_30 ) == 3 ) {
* V_24 = * V_25 = * V_26 = 0 ;
F_16 ( V_28 ) ;
F_14 ( V_29 ) ;
F_15 ( V_30 ) ;
} else {
return L_6
L_7 ;
}
} else {
if ( ! V_27 )
return L_2 ;
* V_27 = FALSE ;
if ( V_31 [ 0 ] == '-' ) {
* V_27 = TRUE ;
V_31 ++ ;
}
if ( V_31 [ 0 ] == '\0' )
return L_3 ;
if ( sscanf ( V_31 , L_5 , V_28 , V_29 , V_30 ) == 3 ) {
F_16 ( V_28 ) ;
F_14 ( V_29 ) ;
F_15 ( V_30 ) ;
} else if ( sscanf ( V_31 , L_8 , V_29 , V_30 ) == 2 ) {
F_14 ( V_29 ) ;
F_15 ( V_30 ) ;
* V_28 = 0 ;
} else if ( sscanf ( V_31 , L_9 , V_30 ) == 1 ) {
F_15 ( V_30 ) ;
* V_28 = * V_29 = 0 ;
} else {
return L_10 ;
}
}
return NULL ;
}
static const T_3 *
F_17 ( const T_3 * V_23 , T_2 * V_32 , T_2 * V_33 )
{
int V_34 , V_35 , V_36 , V_37 , V_38 ;
long double V_19 ;
struct V_39 V_39 , * V_40 ;
V_22 V_41 ;
const T_3 * V_42 ;
if ( ( V_42 = F_8 ( V_23 , & V_36 , & V_37 , & V_38 , NULL , & V_34 , & V_35 , & V_19 ) ) != NULL )
return V_42 ;
V_40 = localtime ( & ( V_32 -> V_20 ) ) ;
if ( V_40 ) {
V_39 = * V_40 ;
} else {
memset ( & V_39 , 0 , sizeof ( V_39 ) ) ;
}
if ( V_36 != 0 ) {
V_39 . V_43 = V_36 - 1900 ;
V_39 . V_44 = V_37 - 1 ;
V_39 . V_45 = V_38 ;
}
V_39 . V_46 = V_34 ;
V_39 . V_47 = V_35 ;
V_39 . V_48 = ( int ) F_7 ( V_19 ) ;
V_41 = mktime ( & V_39 ) ;
if ( V_41 == - 1 ) {
return L_11 ;
}
V_33 -> V_20 = V_41 ;
V_19 -= V_39 . V_48 ;
V_33 -> V_21 = ( int ) ( V_19 * 1000000000 ) ;
return NULL ;
}
const T_3 *
F_18 ( T_5 * V_49 , const T_3 * V_50 )
{
T_2 V_3 ;
long double V_51 = 0 ;
T_6 V_52 ;
T_1 * V_1 ;
T_4 V_2 ;
int V_34 , V_35 ;
long double V_19 ;
const T_3 * V_42 ;
if ( ! V_49 || ! V_50 )
return L_12 ;
if ( ( V_42 = F_8 ( V_50 , NULL , NULL , NULL , & V_2 , & V_34 , & V_35 , & V_19 ) ) != NULL )
return V_42 ;
V_51 = V_34 * 3600 + V_35 * 60 + V_19 ;
if ( V_51 == 0 )
return L_13 ;
F_3 ( & V_3 ) ;
V_3 . V_20 = ( V_22 ) F_7 ( V_51 ) ;
V_51 -= V_3 . V_20 ;
V_3 . V_21 = ( int ) ( V_51 * 1000000000 ) ;
if ( ! F_19 ( V_49 -> V_53 , 1 ) )
return L_14 ;
for ( V_52 = 1 ; V_52 <= V_49 -> V_54 ; V_52 ++ ) {
if ( ( V_1 = F_19 ( V_49 -> V_53 , V_52 ) ) == NULL )
continue;
F_1 ( V_1 , V_2 ? V_9 : V_8 , & V_3 , V_55 ) ;
}
F_20 () ;
return NULL ;
}
const T_3 *
F_21 ( T_5 * V_49 , T_7 V_56 , const T_3 * V_23 )
{
T_2 V_57 , V_58 , V_59 ;
T_1 * V_1 , * V_60 ;
T_6 V_52 ;
const T_3 * V_42 ;
if ( ! V_49 || ! V_23 )
return L_12 ;
if ( V_56 < 1 || V_56 > V_49 -> V_54 )
return L_15 ;
if ( ( V_60 = F_19 ( V_49 -> V_53 , V_56 ) ) == NULL )
return L_16 ;
F_22 ( & V_59 , & ( V_60 -> V_6 ) , & ( V_60 -> V_7 ) ) ;
if ( ( V_42 = F_17 ( V_23 , & V_59 , & V_57 ) ) != NULL )
return V_42 ;
F_22 ( & V_58 , & V_57 , & V_59 ) ;
if ( ! F_19 ( V_49 -> V_53 , 1 ) )
return L_14 ;
for ( V_52 = 1 ; V_52 <= V_49 -> V_54 ; V_52 ++ ) {
if ( ( V_1 = F_19 ( V_49 -> V_53 , V_52 ) ) == NULL )
continue;
F_1 ( V_1 , V_8 , & V_58 , V_5 ) ;
}
F_20 () ;
return NULL ;
}
const T_3 *
F_23 ( T_5 * V_49 , T_7 V_61 , const T_3 * V_62 , T_7 V_63 , const T_3 * V_64 )
{
T_2 V_65 , V_66 , V_67 , V_68 , V_69 ;
T_2 V_70 , V_71 , V_72 ;
T_1 * V_1 , * V_73 , * V_74 ;
T_6 V_52 ;
const T_3 * V_42 ;
if ( ! V_49 || ! V_62 || ! V_64 )
return L_12 ;
if ( V_61 < 1 || V_61 > V_49 -> V_54 || V_63 < 1 || V_63 > V_49 -> V_54 )
return L_15 ;
if ( ( V_73 = F_19 ( V_49 -> V_53 , V_61 ) ) == NULL )
return L_14 ;
F_6 ( & V_67 , & ( V_73 -> V_6 ) ) ;
F_2 ( & V_67 , & ( V_73 -> V_7 ) ) ;
if ( ( V_42 = F_17 ( V_62 , & V_67 , & V_65 ) ) != NULL )
return V_42 ;
if ( ( V_74 = F_19 ( V_49 -> V_53 , V_63 ) ) == NULL )
return L_14 ;
F_6 ( & V_68 , & ( V_74 -> V_6 ) ) ;
F_2 ( & V_68 , & ( V_74 -> V_7 ) ) ;
if ( ( V_42 = F_17 ( V_64 , & V_68 , & V_66 ) ) != NULL )
return V_42 ;
F_6 ( & V_71 , & V_68 ) ;
F_2 ( & V_71 , & V_67 ) ;
F_6 ( & V_70 , & V_66 ) ;
F_2 ( & V_70 , & V_65 ) ;
if ( ! F_19 ( V_49 -> V_53 , 1 ) )
return L_14 ;
for ( V_52 = 1 ; V_52 <= V_49 -> V_54 ; V_52 ++ ) {
if ( ( V_1 = F_19 ( V_49 -> V_53 , V_52 ) ) == NULL )
continue;
F_2 ( & ( V_1 -> V_6 ) , & ( V_1 -> V_7 ) ) ;
F_3 ( & ( V_1 -> V_7 ) ) ;
F_5 ( & V_67 , & ( V_1 -> V_6 ) , & V_65 , & V_69 , & V_71 , & V_70 ) ;
F_6 ( & V_72 , & V_69 ) ;
F_2 ( & V_72 , & ( V_1 -> V_6 ) ) ;
F_1 ( V_1 , V_8 , & V_72 , V_5 ) ;
}
F_20 () ;
return NULL ;
}
const T_3 *
F_24 ( T_5 * V_49 )
{
T_6 V_52 ;
T_1 * V_1 ;
T_2 V_75 ;
if ( ! V_49 )
return L_12 ;
V_75 . V_20 = V_75 . V_21 = 0 ;
if ( ! F_19 ( V_49 -> V_53 , 1 ) )
return L_14 ;
for ( V_52 = 1 ; V_52 <= V_49 -> V_54 ; V_52 ++ ) {
if ( ( V_1 = F_19 ( V_49 -> V_53 , V_52 ) ) == NULL )
continue;
F_1 ( V_1 , V_9 , & V_75 , V_5 ) ;
}
F_20 () ;
return NULL ;
}
