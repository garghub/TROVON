const T_1 * F_1 ( void )
{
static const T_1 V_1 = {
V_2 ,
V_3 ,
V_4 ,
V_5 ,
V_6 ,
V_7 ,
V_8 ,
V_9 ,
V_10 ,
V_11 ,
V_12 ,
V_13 ,
V_14 ,
V_15 ,
V_16 ,
V_17 ,
0 ,
0 ,
V_18 ,
V_19 ,
0 , 0 , 0 ,
V_20 ,
V_21 ,
V_22 ,
V_23 ,
V_24 ,
V_25 ,
V_26 ,
V_27 ,
V_28 ,
V_29 ,
V_30 ,
V_31 ,
V_32 ,
V_33 ,
0 ,
0 ,
0 ,
V_34 ,
V_35 ,
0 ,
V_36 ,
V_37 ,
V_38 ,
0 ,
0 ,
V_39
} ;
return & V_1 ;
}
int V_4 ( T_2 * V_40 )
{
V_40 -> V_41 = F_2 () ;
V_40 -> V_42 = F_2 () ;
V_40 -> V_43 = F_2 () ;
if ( V_40 -> V_41 == NULL || V_40 -> V_42 == NULL || V_40 -> V_43 == NULL ) {
F_3 ( V_40 -> V_41 ) ;
F_3 ( V_40 -> V_42 ) ;
F_3 ( V_40 -> V_43 ) ;
return 0 ;
}
return 1 ;
}
void V_5 ( T_2 * V_40 )
{
F_3 ( V_40 -> V_41 ) ;
F_3 ( V_40 -> V_42 ) ;
F_3 ( V_40 -> V_43 ) ;
}
void V_6 ( T_2 * V_40 )
{
F_4 ( V_40 -> V_41 ) ;
F_4 ( V_40 -> V_42 ) ;
F_4 ( V_40 -> V_43 ) ;
V_40 -> V_44 [ 0 ] = 0 ;
V_40 -> V_44 [ 1 ] = 0 ;
V_40 -> V_44 [ 2 ] = 0 ;
V_40 -> V_44 [ 3 ] = 0 ;
V_40 -> V_44 [ 4 ] = 0 ;
V_40 -> V_44 [ 5 ] = - 1 ;
}
int V_7 ( T_2 * V_45 , const T_2 * V_46 )
{
if ( ! F_5 ( V_45 -> V_41 , V_46 -> V_41 ) )
return 0 ;
if ( ! F_5 ( V_45 -> V_42 , V_46 -> V_42 ) )
return 0 ;
if ( ! F_5 ( V_45 -> V_43 , V_46 -> V_43 ) )
return 0 ;
V_45 -> V_44 [ 0 ] = V_46 -> V_44 [ 0 ] ;
V_45 -> V_44 [ 1 ] = V_46 -> V_44 [ 1 ] ;
V_45 -> V_44 [ 2 ] = V_46 -> V_44 [ 2 ] ;
V_45 -> V_44 [ 3 ] = V_46 -> V_44 [ 3 ] ;
V_45 -> V_44 [ 4 ] = V_46 -> V_44 [ 4 ] ;
V_45 -> V_44 [ 5 ] = V_46 -> V_44 [ 5 ] ;
if ( F_6 ( V_45 -> V_42 , ( int ) ( V_45 -> V_44 [ 0 ] + V_47 - 1 ) / V_47 ) ==
NULL )
return 0 ;
if ( F_6 ( V_45 -> V_43 , ( int ) ( V_45 -> V_44 [ 0 ] + V_47 - 1 ) / V_47 ) ==
NULL )
return 0 ;
F_7 ( V_45 -> V_42 ) ;
F_7 ( V_45 -> V_43 ) ;
return 1 ;
}
int V_8 ( T_2 * V_40 ,
const T_3 * V_48 , const T_3 * V_42 ,
const T_3 * V_43 , T_4 * V_49 )
{
int V_1 = 0 , V_50 ;
if ( ! F_5 ( V_40 -> V_41 , V_48 ) )
goto V_51;
V_50 = F_8 ( V_40 -> V_41 , V_40 -> V_44 , 6 ) - 1 ;
if ( ( V_50 != 5 ) && ( V_50 != 3 ) ) {
F_9 ( V_52 , V_53 ) ;
goto V_51;
}
if ( ! F_10 ( V_40 -> V_42 , V_42 , V_40 -> V_44 ) )
goto V_51;
if ( F_6 ( V_40 -> V_42 , ( int ) ( V_40 -> V_44 [ 0 ] + V_47 - 1 ) / V_47 )
== NULL )
goto V_51;
F_7 ( V_40 -> V_42 ) ;
if ( ! F_10 ( V_40 -> V_43 , V_43 , V_40 -> V_44 ) )
goto V_51;
if ( F_6 ( V_40 -> V_43 , ( int ) ( V_40 -> V_44 [ 0 ] + V_47 - 1 ) / V_47 )
== NULL )
goto V_51;
F_7 ( V_40 -> V_43 ) ;
V_1 = 1 ;
V_51:
return V_1 ;
}
int V_9 ( const T_2 * V_40 , T_3 * V_48 ,
T_3 * V_42 , T_3 * V_43 , T_4 * V_49 )
{
int V_1 = 0 ;
if ( V_48 != NULL ) {
if ( ! F_5 ( V_48 , V_40 -> V_41 ) )
return 0 ;
}
if ( V_42 != NULL ) {
if ( ! F_5 ( V_42 , V_40 -> V_42 ) )
goto V_51;
}
if ( V_43 != NULL ) {
if ( ! F_5 ( V_43 , V_40 -> V_43 ) )
goto V_51;
}
V_1 = 1 ;
V_51:
return V_1 ;
}
int V_10 ( const T_2 * V_40 )
{
return F_11 ( V_40 -> V_41 ) - 1 ;
}
int V_12 ( const T_2 * V_40 ,
T_4 * V_49 )
{
int V_1 = 0 ;
T_3 * V_43 ;
T_4 * V_54 = NULL ;
if ( V_49 == NULL ) {
V_49 = V_54 = F_12 () ;
if ( V_49 == NULL ) {
F_9 ( V_55 ,
V_56 ) ;
goto V_51;
}
}
F_13 ( V_49 ) ;
V_43 = F_14 ( V_49 ) ;
if ( V_43 == NULL )
goto V_51;
if ( ! F_10 ( V_43 , V_40 -> V_43 , V_40 -> V_44 ) )
goto V_51;
if ( F_15 ( V_43 ) )
goto V_51;
V_1 = 1 ;
V_51:
if ( V_49 != NULL )
F_16 ( V_49 ) ;
F_17 ( V_54 ) ;
return V_1 ;
}
int V_13 ( T_5 * V_57 )
{
V_57 -> V_58 = F_2 () ;
V_57 -> V_59 = F_2 () ;
V_57 -> V_60 = F_2 () ;
if ( V_57 -> V_58 == NULL || V_57 -> V_59 == NULL || V_57 -> V_60 == NULL ) {
F_3 ( V_57 -> V_58 ) ;
F_3 ( V_57 -> V_59 ) ;
F_3 ( V_57 -> V_60 ) ;
return 0 ;
}
return 1 ;
}
void V_14 ( T_5 * V_57 )
{
F_3 ( V_57 -> V_58 ) ;
F_3 ( V_57 -> V_59 ) ;
F_3 ( V_57 -> V_60 ) ;
}
void V_15 ( T_5 * V_57 )
{
F_4 ( V_57 -> V_58 ) ;
F_4 ( V_57 -> V_59 ) ;
F_4 ( V_57 -> V_60 ) ;
V_57 -> V_61 = 0 ;
}
int V_16 ( T_5 * V_45 , const T_5 * V_46 )
{
if ( ! F_5 ( V_45 -> V_58 , V_46 -> V_58 ) )
return 0 ;
if ( ! F_5 ( V_45 -> V_59 , V_46 -> V_59 ) )
return 0 ;
if ( ! F_5 ( V_45 -> V_60 , V_46 -> V_60 ) )
return 0 ;
V_45 -> V_61 = V_46 -> V_61 ;
return 1 ;
}
int V_17 ( const T_2 * V_40 ,
T_5 * V_57 )
{
V_57 -> V_61 = 0 ;
F_18 ( V_57 -> V_60 ) ;
return 1 ;
}
int V_18 ( const T_2 * V_40 ,
T_5 * V_57 ,
const T_3 * V_62 ,
const T_3 * V_63 , T_4 * V_49 )
{
int V_1 = 0 ;
if ( V_62 == NULL || V_63 == NULL ) {
F_9 ( V_64 ,
V_65 ) ;
return 0 ;
}
if ( ! F_5 ( V_57 -> V_58 , V_62 ) )
goto V_51;
F_19 ( V_57 -> V_58 , 0 ) ;
if ( ! F_5 ( V_57 -> V_59 , V_63 ) )
goto V_51;
F_19 ( V_57 -> V_59 , 0 ) ;
if ( ! F_5 ( V_57 -> V_60 , F_20 () ) )
goto V_51;
F_19 ( V_57 -> V_60 , 0 ) ;
V_57 -> V_61 = 1 ;
V_1 = 1 ;
V_51:
return V_1 ;
}
int V_19 ( const T_2 * V_40 ,
const T_5 * V_57 ,
T_3 * V_62 , T_3 * V_63 ,
T_4 * V_49 )
{
int V_1 = 0 ;
if ( F_21 ( V_40 , V_57 ) ) {
F_9 ( V_66 ,
V_67 ) ;
return 0 ;
}
if ( F_22 ( V_57 -> V_60 , F_20 () ) ) {
F_9 ( V_66 ,
V_68 ) ;
return 0 ;
}
if ( V_62 != NULL ) {
if ( ! F_5 ( V_62 , V_57 -> V_58 ) )
goto V_51;
F_19 ( V_62 , 0 ) ;
}
if ( V_63 != NULL ) {
if ( ! F_5 ( V_63 , V_57 -> V_59 ) )
goto V_51;
F_19 ( V_63 , 0 ) ;
}
V_1 = 1 ;
V_51:
return V_1 ;
}
int V_20 ( const T_2 * V_40 , T_5 * V_69 , const T_5 * V_42 ,
const T_5 * V_43 , T_4 * V_49 )
{
T_4 * V_54 = NULL ;
T_3 * V_70 , * y0 , * V_71 , * y1 , * V_72 , * V_73 , * V_74 , * V_75 ;
int V_1 = 0 ;
if ( F_21 ( V_40 , V_42 ) ) {
if ( ! F_23 ( V_69 , V_43 ) )
return 0 ;
return 1 ;
}
if ( F_21 ( V_40 , V_43 ) ) {
if ( ! F_23 ( V_69 , V_42 ) )
return 0 ;
return 1 ;
}
if ( V_49 == NULL ) {
V_49 = V_54 = F_12 () ;
if ( V_49 == NULL )
return 0 ;
}
F_13 ( V_49 ) ;
V_70 = F_14 ( V_49 ) ;
y0 = F_14 ( V_49 ) ;
V_71 = F_14 ( V_49 ) ;
y1 = F_14 ( V_49 ) ;
V_72 = F_14 ( V_49 ) ;
V_73 = F_14 ( V_49 ) ;
V_74 = F_14 ( V_49 ) ;
V_75 = F_14 ( V_49 ) ;
if ( V_75 == NULL )
goto V_51;
if ( V_42 -> V_61 ) {
if ( ! F_5 ( V_70 , V_42 -> V_58 ) )
goto V_51;
if ( ! F_5 ( y0 , V_42 -> V_59 ) )
goto V_51;
} else {
if ( ! F_24 ( V_40 , V_42 , V_70 , y0 , V_49 ) )
goto V_51;
}
if ( V_43 -> V_61 ) {
if ( ! F_5 ( V_71 , V_43 -> V_58 ) )
goto V_51;
if ( ! F_5 ( y1 , V_43 -> V_59 ) )
goto V_51;
} else {
if ( ! F_24 ( V_40 , V_43 , V_71 , y1 , V_49 ) )
goto V_51;
}
if ( F_25 ( V_70 , V_71 ) ) {
if ( ! F_26 ( V_75 , V_70 , V_71 ) )
goto V_51;
if ( ! F_26 ( V_74 , y0 , y1 ) )
goto V_51;
if ( ! V_40 -> V_76 -> V_77 ( V_40 , V_74 , V_74 , V_75 , V_49 ) )
goto V_51;
if ( ! V_40 -> V_76 -> V_78 ( V_40 , V_72 , V_74 , V_49 ) )
goto V_51;
if ( ! F_26 ( V_72 , V_72 , V_40 -> V_42 ) )
goto V_51;
if ( ! F_26 ( V_72 , V_72 , V_74 ) )
goto V_51;
if ( ! F_26 ( V_72 , V_72 , V_75 ) )
goto V_51;
} else {
if ( F_25 ( y0 , y1 ) || F_15 ( V_71 ) ) {
if ( ! F_27 ( V_40 , V_69 ) )
goto V_51;
V_1 = 1 ;
goto V_51;
}
if ( ! V_40 -> V_76 -> V_77 ( V_40 , V_74 , y1 , V_71 , V_49 ) )
goto V_51;
if ( ! F_26 ( V_74 , V_74 , V_71 ) )
goto V_51;
if ( ! V_40 -> V_76 -> V_78 ( V_40 , V_72 , V_74 , V_49 ) )
goto V_51;
if ( ! F_26 ( V_72 , V_72 , V_74 ) )
goto V_51;
if ( ! F_26 ( V_72 , V_72 , V_40 -> V_42 ) )
goto V_51;
}
if ( ! F_26 ( V_73 , V_71 , V_72 ) )
goto V_51;
if ( ! V_40 -> V_76 -> V_79 ( V_40 , V_73 , V_73 , V_74 , V_49 ) )
goto V_51;
if ( ! F_26 ( V_73 , V_73 , V_72 ) )
goto V_51;
if ( ! F_26 ( V_73 , V_73 , y1 ) )
goto V_51;
if ( ! F_28 ( V_40 , V_69 , V_72 , V_73 , V_49 ) )
goto V_51;
V_1 = 1 ;
V_51:
F_16 ( V_49 ) ;
F_17 ( V_54 ) ;
return V_1 ;
}
int V_21 ( const T_2 * V_40 , T_5 * V_69 , const T_5 * V_42 ,
T_4 * V_49 )
{
return V_20 ( V_40 , V_69 , V_42 , V_42 , V_49 ) ;
}
int V_22 ( const T_2 * V_40 , T_5 * V_57 , T_4 * V_49 )
{
if ( F_21 ( V_40 , V_57 ) || F_15 ( V_57 -> V_59 ) )
return 1 ;
if ( ! F_29 ( V_40 , V_57 , V_49 ) )
return 0 ;
return F_26 ( V_57 -> V_59 , V_57 -> V_58 , V_57 -> V_59 ) ;
}
int V_23 ( const T_2 * V_40 ,
const T_5 * V_57 )
{
return F_15 ( V_57 -> V_60 ) ;
}
int V_24 ( const T_2 * V_40 , const T_5 * V_57 ,
T_4 * V_49 )
{
int V_1 = - 1 ;
T_4 * V_54 = NULL ;
T_3 * V_80 , * V_73 ;
int (* V_79) ( const T_2 * , T_3 * , const T_3 * ,
const T_3 * , T_4 * );
int (* V_78) ( const T_2 * , T_3 * , const T_3 * , T_4 * );
if ( F_21 ( V_40 , V_57 ) )
return 1 ;
V_79 = V_40 -> V_76 -> V_79 ;
V_78 = V_40 -> V_76 -> V_78 ;
if ( ! V_57 -> V_61 )
return - 1 ;
if ( V_49 == NULL ) {
V_49 = V_54 = F_12 () ;
if ( V_49 == NULL )
return - 1 ;
}
F_13 ( V_49 ) ;
V_73 = F_14 ( V_49 ) ;
V_80 = F_14 ( V_49 ) ;
if ( V_80 == NULL )
goto V_51;
if ( ! F_26 ( V_80 , V_57 -> V_58 , V_40 -> V_42 ) )
goto V_51;
if ( ! V_79 ( V_40 , V_80 , V_80 , V_57 -> V_58 , V_49 ) )
goto V_51;
if ( ! F_26 ( V_80 , V_80 , V_57 -> V_59 ) )
goto V_51;
if ( ! V_79 ( V_40 , V_80 , V_80 , V_57 -> V_58 , V_49 ) )
goto V_51;
if ( ! F_26 ( V_80 , V_80 , V_40 -> V_43 ) )
goto V_51;
if ( ! V_78 ( V_40 , V_73 , V_57 -> V_59 , V_49 ) )
goto V_51;
if ( ! F_26 ( V_80 , V_80 , V_73 ) )
goto V_51;
V_1 = F_15 ( V_80 ) ;
V_51:
if ( V_49 )
F_16 ( V_49 ) ;
F_17 ( V_54 ) ;
return V_1 ;
}
int V_25 ( const T_2 * V_40 , const T_5 * V_42 ,
const T_5 * V_43 , T_4 * V_49 )
{
T_3 * V_81 , * V_82 , * V_83 , * V_84 ;
T_4 * V_54 = NULL ;
int V_1 = - 1 ;
if ( F_21 ( V_40 , V_42 ) ) {
return F_21 ( V_40 , V_43 ) ? 0 : 1 ;
}
if ( F_21 ( V_40 , V_43 ) )
return 1 ;
if ( V_42 -> V_61 && V_43 -> V_61 ) {
return ( ( F_22 ( V_42 -> V_58 , V_43 -> V_58 ) == 0 ) && F_22 ( V_42 -> V_59 , V_43 -> V_59 ) == 0 ) ? 0 : 1 ;
}
if ( V_49 == NULL ) {
V_49 = V_54 = F_12 () ;
if ( V_49 == NULL )
return - 1 ;
}
F_13 ( V_49 ) ;
V_81 = F_14 ( V_49 ) ;
V_82 = F_14 ( V_49 ) ;
V_83 = F_14 ( V_49 ) ;
V_84 = F_14 ( V_49 ) ;
if ( V_84 == NULL )
goto V_51;
if ( ! F_24 ( V_40 , V_42 , V_81 , V_82 , V_49 ) )
goto V_51;
if ( ! F_24 ( V_40 , V_43 , V_83 , V_84 , V_49 ) )
goto V_51;
V_1 = ( ( F_22 ( V_81 , V_83 ) == 0 ) && F_22 ( V_82 , V_84 ) == 0 ) ? 0 : 1 ;
V_51:
if ( V_49 )
F_16 ( V_49 ) ;
F_17 ( V_54 ) ;
return V_1 ;
}
int V_26 ( const T_2 * V_40 , T_5 * V_57 ,
T_4 * V_49 )
{
T_4 * V_54 = NULL ;
T_3 * V_62 , * V_63 ;
int V_1 = 0 ;
if ( V_57 -> V_61 || F_21 ( V_40 , V_57 ) )
return 1 ;
if ( V_49 == NULL ) {
V_49 = V_54 = F_12 () ;
if ( V_49 == NULL )
return 0 ;
}
F_13 ( V_49 ) ;
V_62 = F_14 ( V_49 ) ;
V_63 = F_14 ( V_49 ) ;
if ( V_63 == NULL )
goto V_51;
if ( ! F_24 ( V_40 , V_57 , V_62 , V_63 , V_49 ) )
goto V_51;
if ( ! F_5 ( V_57 -> V_58 , V_62 ) )
goto V_51;
if ( ! F_5 ( V_57 -> V_59 , V_63 ) )
goto V_51;
if ( ! F_30 ( V_57 -> V_60 ) )
goto V_51;
V_57 -> V_61 = 1 ;
V_1 = 1 ;
V_51:
if ( V_49 )
F_16 ( V_49 ) ;
F_17 ( V_54 ) ;
return V_1 ;
}
int V_27 ( const T_2 * V_40 , T_6 V_85 ,
T_5 * V_86 [] , T_4 * V_49 )
{
T_6 V_50 ;
for ( V_50 = 0 ; V_50 < V_85 ; V_50 ++ ) {
if ( ! V_40 -> V_76 -> V_87 ( V_40 , V_86 [ V_50 ] , V_49 ) )
return 0 ;
}
return 1 ;
}
int V_31 ( const T_2 * V_40 , T_3 * V_69 ,
const T_3 * V_42 , const T_3 * V_43 , T_4 * V_49 )
{
return F_31 ( V_69 , V_42 , V_43 , V_40 -> V_44 , V_49 ) ;
}
int V_32 ( const T_2 * V_40 , T_3 * V_69 ,
const T_3 * V_42 , T_4 * V_49 )
{
return F_32 ( V_69 , V_42 , V_40 -> V_44 , V_49 ) ;
}
int V_33 ( const T_2 * V_40 , T_3 * V_69 ,
const T_3 * V_42 , const T_3 * V_43 , T_4 * V_49 )
{
return F_33 ( V_69 , V_42 , V_43 , V_40 -> V_41 , V_49 ) ;
}
