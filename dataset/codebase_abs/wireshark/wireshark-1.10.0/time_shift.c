static void
F_1 ( T_1 * V_1 )
{
F_2 ( V_1 , V_2 , NULL , V_3 ) ;
}
static void
F_2 ( T_1 * V_1 , int V_4 , T_2 * V_5 , int V_6 )
{
static T_1 * V_7 = NULL ;
static T_2 V_8 ;
if ( V_5 == NULL ) {
V_7 = V_1 ;
V_8 . V_9 = V_8 . V_10 = 0 ;
return;
}
if ( V_7 == NULL ) {
fprintf ( V_11 , L_1 ) ;
return;
}
if ( V_6 == V_12 ) {
F_3 ( & ( V_1 -> V_13 ) , & ( V_1 -> V_14 ) ) ;
F_4 ( & ( V_1 -> V_14 ) , & V_8 ) ;
}
if ( V_4 == V_15 ) {
F_5 ( & ( V_1 -> V_13 ) , V_5 ) ;
F_5 ( & ( V_1 -> V_14 ) , V_5 ) ;
} else if ( V_4 == V_2 ) {
F_3 ( & ( V_1 -> V_13 ) , V_5 ) ;
F_3 ( & ( V_1 -> V_14 ) , V_5 ) ;
} else {
fprintf ( V_11 , L_2 , V_4 ) ;
}
if ( V_7 != NULL ) {
F_4 ( & ( V_1 -> V_16 ) , & ( V_1 -> V_13 ) ) ;
F_3 ( & ( V_1 -> V_16 ) , & ( V_7 -> V_13 ) ) ;
} else
F_4 ( & ( V_1 -> V_16 ) , & V_8 ) ;
}
static void
F_6 ( T_2 * V_17 , T_2 * V_18 , T_2 * V_19 , T_2 * V_20 ,
T_2 * V_21 , T_2 * V_22 )
{
long double V_23 , V_24 , V_25 , V_9 , V_10 ;
V_23 = ( long double ) V_22 -> V_9 + ( V_22 -> V_10 / 1000000000.0L ) ;
V_24 = ( long double ) V_21 -> V_9 + ( V_21 -> V_10 / 1000000000.0L ) ;
V_25 = V_23 / V_24 ;
F_4 ( V_20 , V_18 ) ;
F_3 ( V_20 , V_17 ) ;
V_9 = V_25 * ( long double ) V_20 -> V_9 ;
V_10 = V_25 * ( long double ) V_20 -> V_10 ;
V_10 += ( V_9 - F_7 ( V_9 ) ) * 1000000000.0L ;
while ( V_10 > 1000000000L ) {
V_9 += 1 ;
V_10 -= 1000000000L ;
}
while ( V_10 < 0 ) {
V_9 -= 1 ;
V_10 += 1000000000L ;
}
V_20 -> V_9 = ( V_26 ) V_9 ;
V_20 -> V_10 = ( int ) V_10 ;
F_5 ( V_20 , V_19 ) ;
}
const T_3 *
F_8 ( const T_3 * V_27 , int * V_28 , int * V_29 , int * V_30 , T_4 * V_31 , int * V_32 , int * V_33 , long double * V_34 ) {
T_3 * V_35 ;
if ( ! V_27 || ! V_32 || ! V_33 || ! V_34 )
return L_3 ;
V_35 = ( T_3 * ) V_27 ;
while ( isspace ( V_35 [ 0 ] ) )
++ V_35 ;
if ( V_28 && V_29 && V_30 ) {
if ( V_35 [ 0 ] == '\0' )
return L_4 ;
if ( sscanf ( V_35 , L_5 , V_28 , V_29 , V_30 , V_32 , V_33 , V_34 ) == 6 ) {
F_9 ( V_28 ) ;
F_10 ( V_29 ) ;
F_11 ( V_30 ) ;
F_12 ( V_32 ) ;
F_13 ( V_33 ) ;
F_14 ( V_34 ) ;
} else if ( sscanf ( V_35 , L_6 , V_32 , V_33 , V_34 ) == 3 ) {
* V_28 = * V_29 = * V_30 = 0 ;
F_15 ( V_32 ) ;
F_13 ( V_33 ) ;
F_14 ( V_34 ) ;
} else {
return L_7
L_8 ;
}
} else {
if ( ! V_31 )
return L_3 ;
* V_31 = FALSE ;
if ( V_35 [ 0 ] == '-' ) {
* V_31 = TRUE ;
V_35 ++ ;
}
if ( V_35 [ 0 ] == '\0' )
return L_4 ;
if ( sscanf ( V_35 , L_6 , V_32 , V_33 , V_34 ) == 3 ) {
F_15 ( V_32 ) ;
F_13 ( V_33 ) ;
F_14 ( V_34 ) ;
} else if ( sscanf ( V_35 , L_9 , V_33 , V_34 ) == 2 ) {
F_13 ( V_33 ) ;
F_14 ( V_34 ) ;
* V_32 = 0 ;
} else if ( sscanf ( V_35 , L_10 , V_34 ) == 1 ) {
F_14 ( V_34 ) ;
* V_32 = * V_33 = 0 ;
} else {
return L_11 ;
}
}
return NULL ;
}
static const T_3 *
F_16 ( const T_3 * V_27 , T_2 * V_36 , T_2 * V_37 )
{
int V_38 , V_39 , V_40 , V_41 , V_42 ;
long double V_25 ;
struct V_43 V_43 , * V_44 ;
V_26 V_45 ;
const T_3 * V_46 ;
if ( ( V_46 = F_8 ( V_27 , & V_40 , & V_41 , & V_42 , NULL , & V_38 , & V_39 , & V_25 ) ) != NULL )
return V_46 ;
V_44 = localtime ( & ( V_36 -> V_9 ) ) ;
if ( V_44 ) {
V_43 = * V_44 ;
} else {
memset ( & V_43 , 0 , sizeof ( V_43 ) ) ;
}
if ( V_40 != 0 ) {
V_43 . V_47 = V_40 - 1900 ;
V_43 . V_48 = V_41 - 1 ;
V_43 . V_49 = V_42 ;
}
V_43 . V_50 = V_38 ;
V_43 . V_51 = V_39 ;
V_43 . V_52 = ( int ) F_7 ( V_25 ) ;
V_45 = mktime ( & V_43 ) ;
if ( V_45 == - 1 ) {
return L_12 ;
}
V_37 -> V_9 = V_45 ;
V_25 -= V_43 . V_52 ;
V_37 -> V_10 = ( int ) ( V_25 * 1000000000 ) ;
return NULL ;
}
const T_3 *
F_17 ( T_5 * V_53 , const T_3 * V_54 )
{
T_2 V_5 ;
long double V_55 = 0 ;
T_6 V_56 ;
T_1 * V_1 ;
T_4 V_4 ;
int V_38 , V_39 ;
long double V_25 ;
const T_3 * V_46 ;
if ( ! V_53 || ! V_54 )
return L_13 ;
if ( ( V_46 = F_8 ( V_54 , NULL , NULL , NULL , & V_4 , & V_38 , & V_39 , & V_25 ) ) != NULL )
return V_46 ;
V_55 = V_38 * 3600 + V_39 * 60 + V_25 ;
if ( V_55 == 0 )
return L_14 ;
F_18 ( & V_5 ) ;
V_5 . V_9 = ( V_26 ) F_7 ( V_55 ) ;
V_55 -= V_5 . V_9 ;
V_5 . V_10 = ( int ) ( V_55 * 1000000000 ) ;
if ( ( V_1 = F_19 ( V_53 -> V_57 , 1 ) ) == NULL )
return L_15 ;
F_1 ( V_1 ) ;
for ( V_56 = 1 ; V_56 <= V_53 -> V_58 ; V_56 ++ ) {
if ( ( V_1 = F_19 ( V_53 -> V_57 , V_56 ) ) == NULL )
continue;
F_2 ( V_1 , V_4 ? V_2 : V_15 , & V_5 , V_3 ) ;
}
F_20 () ;
return NULL ;
}
const T_3 *
F_21 ( T_5 * V_53 , T_7 V_59 , const T_3 * V_27 )
{
T_2 V_60 , V_61 , V_62 ;
T_1 * V_1 , * V_63 ;
T_6 V_56 ;
const T_3 * V_46 ;
if ( ! V_53 || ! V_27 )
return L_13 ;
if ( V_59 < 1 || V_59 > V_53 -> V_58 )
return L_16 ;
if ( ( V_63 = F_19 ( V_53 -> V_57 , V_59 ) ) == NULL )
return L_17 ;
F_22 ( & V_62 , & ( V_63 -> V_13 ) , & ( V_63 -> V_14 ) ) ;
if ( ( V_46 = F_16 ( V_27 , & V_62 , & V_60 ) ) != NULL )
return V_46 ;
F_22 ( & V_61 , & V_60 , & V_62 ) ;
if ( ( V_1 = F_19 ( V_53 -> V_57 , 1 ) ) == NULL )
return L_15 ;
F_1 ( V_1 ) ;
for ( V_56 = 1 ; V_56 <= V_53 -> V_58 ; V_56 ++ ) {
if ( ( V_1 = F_19 ( V_53 -> V_57 , V_56 ) ) == NULL )
continue;
F_2 ( V_1 , V_15 , & V_61 , V_12 ) ;
}
F_20 () ;
return NULL ;
}
const T_3 *
F_23 ( T_5 * V_53 , T_7 V_64 , const T_3 * V_65 , T_7 V_66 , const T_3 * V_67 )
{
T_2 V_68 , V_69 , V_70 , V_71 , V_72 ;
T_2 V_73 , V_74 , V_75 ;
T_1 * V_1 , * V_76 , * V_77 ;
T_6 V_56 ;
const T_3 * V_46 ;
if ( ! V_53 || ! V_65 || ! V_67 )
return L_13 ;
if ( V_64 < 1 || V_64 > V_53 -> V_58 || V_66 < 1 || V_66 > V_53 -> V_58 )
return L_16 ;
if ( ( V_76 = F_19 ( V_53 -> V_57 , V_64 ) ) == NULL )
return L_15 ;
F_4 ( & V_70 , & ( V_76 -> V_13 ) ) ;
F_3 ( & V_70 , & ( V_76 -> V_14 ) ) ;
if ( ( V_46 = F_16 ( V_65 , & V_70 , & V_68 ) ) != NULL )
return V_46 ;
if ( ( V_77 = F_19 ( V_53 -> V_57 , V_66 ) ) == NULL )
return L_15 ;
F_4 ( & V_71 , & ( V_77 -> V_13 ) ) ;
F_3 ( & V_71 , & ( V_77 -> V_14 ) ) ;
if ( ( V_46 = F_16 ( V_67 , & V_71 , & V_69 ) ) != NULL )
return V_46 ;
F_4 ( & V_74 , & V_71 ) ;
F_3 ( & V_74 , & V_70 ) ;
F_4 ( & V_73 , & V_69 ) ;
F_3 ( & V_73 , & V_68 ) ;
if ( ( V_1 = F_19 ( V_53 -> V_57 , 1 ) ) == NULL )
return L_15 ;
F_1 ( V_1 ) ;
for ( V_56 = 1 ; V_56 <= V_53 -> V_58 ; V_56 ++ ) {
if ( ( V_1 = F_19 ( V_53 -> V_57 , V_56 ) ) == NULL )
continue;
F_3 ( & ( V_1 -> V_13 ) , & ( V_1 -> V_14 ) ) ;
F_18 ( & ( V_1 -> V_14 ) ) ;
F_6 ( & V_70 , & ( V_1 -> V_13 ) , & V_68 , & V_72 , & V_74 , & V_73 ) ;
F_4 ( & V_75 , & V_72 ) ;
F_3 ( & V_75 , & ( V_1 -> V_13 ) ) ;
F_2 ( V_1 , V_15 , & V_75 , V_12 ) ;
}
F_20 () ;
return NULL ;
}
const T_3 *
F_24 ( T_5 * V_53 )
{
T_6 V_56 ;
T_1 * V_1 ;
T_2 V_8 ;
if ( ! V_53 )
return L_13 ;
V_8 . V_9 = V_8 . V_10 = 0 ;
if ( ( V_1 = F_19 ( V_53 -> V_57 , 1 ) ) == NULL )
return L_15 ;
F_1 ( V_1 ) ;
for ( V_56 = 1 ; V_56 <= V_53 -> V_58 ; V_56 ++ ) {
if ( ( V_1 = F_19 ( V_53 -> V_57 , V_56 ) ) == NULL )
continue;
F_2 ( V_1 , V_2 , & V_8 , V_12 ) ;
}
F_20 () ;
return NULL ;
}
