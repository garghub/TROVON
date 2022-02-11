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
0 ,
0 ,
V_17 ,
V_18 ,
0 , 0 , 0 ,
V_19 ,
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
0 ,
0 ,
0
} ;
# ifdef F_2
if ( F_3 () )
return F_4 () ;
# endif
return & V_1 ;
}
int V_4 ( T_2 * V_33 )
{
F_5 ( & V_33 -> V_34 ) ;
F_5 ( & V_33 -> V_35 ) ;
F_5 ( & V_33 -> V_36 ) ;
return 1 ;
}
void V_5 ( T_2 * V_33 )
{
F_6 ( & V_33 -> V_34 ) ;
F_6 ( & V_33 -> V_35 ) ;
F_6 ( & V_33 -> V_36 ) ;
}
void V_6 ( T_2 * V_33 )
{
F_7 ( & V_33 -> V_34 ) ;
F_7 ( & V_33 -> V_35 ) ;
F_7 ( & V_33 -> V_36 ) ;
V_33 -> V_37 [ 0 ] = 0 ;
V_33 -> V_37 [ 1 ] = 0 ;
V_33 -> V_37 [ 2 ] = 0 ;
V_33 -> V_37 [ 3 ] = 0 ;
V_33 -> V_37 [ 4 ] = 0 ;
V_33 -> V_37 [ 5 ] = - 1 ;
}
int V_7 ( T_2 * V_38 , const T_2 * V_39 )
{
int V_40 ;
if ( ! F_8 ( & V_38 -> V_34 , & V_39 -> V_34 ) )
return 0 ;
if ( ! F_8 ( & V_38 -> V_35 , & V_39 -> V_35 ) )
return 0 ;
if ( ! F_8 ( & V_38 -> V_36 , & V_39 -> V_36 ) )
return 0 ;
V_38 -> V_37 [ 0 ] = V_39 -> V_37 [ 0 ] ;
V_38 -> V_37 [ 1 ] = V_39 -> V_37 [ 1 ] ;
V_38 -> V_37 [ 2 ] = V_39 -> V_37 [ 2 ] ;
V_38 -> V_37 [ 3 ] = V_39 -> V_37 [ 3 ] ;
V_38 -> V_37 [ 4 ] = V_39 -> V_37 [ 4 ] ;
V_38 -> V_37 [ 5 ] = V_39 -> V_37 [ 5 ] ;
if ( F_9 ( & V_38 -> V_35 , ( int ) ( V_38 -> V_37 [ 0 ] + V_41 - 1 ) / V_41 )
== NULL )
return 0 ;
if ( F_9 ( & V_38 -> V_36 , ( int ) ( V_38 -> V_37 [ 0 ] + V_41 - 1 ) / V_41 )
== NULL )
return 0 ;
for ( V_40 = V_38 -> V_35 . V_42 ; V_40 < V_38 -> V_35 . V_43 ; V_40 ++ )
V_38 -> V_35 . V_44 [ V_40 ] = 0 ;
for ( V_40 = V_38 -> V_36 . V_42 ; V_40 < V_38 -> V_36 . V_43 ; V_40 ++ )
V_38 -> V_36 . V_44 [ V_40 ] = 0 ;
return 1 ;
}
int V_8 ( T_2 * V_33 ,
const T_3 * V_45 , const T_3 * V_35 ,
const T_3 * V_36 , T_4 * V_46 )
{
int V_1 = 0 , V_40 ;
if ( ! F_8 ( & V_33 -> V_34 , V_45 ) )
goto V_47;
V_40 = F_10 ( & V_33 -> V_34 , V_33 -> V_37 , 6 ) - 1 ;
if ( ( V_40 != 5 ) && ( V_40 != 3 ) ) {
F_11 ( V_48 , V_49 ) ;
goto V_47;
}
if ( ! F_12 ( & V_33 -> V_35 , V_35 , V_33 -> V_37 ) )
goto V_47;
if ( F_9 ( & V_33 -> V_35 , ( int ) ( V_33 -> V_37 [ 0 ] + V_41 - 1 ) / V_41 )
== NULL )
goto V_47;
for ( V_40 = V_33 -> V_35 . V_42 ; V_40 < V_33 -> V_35 . V_43 ; V_40 ++ )
V_33 -> V_35 . V_44 [ V_40 ] = 0 ;
if ( ! F_12 ( & V_33 -> V_36 , V_36 , V_33 -> V_37 ) )
goto V_47;
if ( F_9 ( & V_33 -> V_36 , ( int ) ( V_33 -> V_37 [ 0 ] + V_41 - 1 ) / V_41 )
== NULL )
goto V_47;
for ( V_40 = V_33 -> V_36 . V_42 ; V_40 < V_33 -> V_36 . V_43 ; V_40 ++ )
V_33 -> V_36 . V_44 [ V_40 ] = 0 ;
V_1 = 1 ;
V_47:
return V_1 ;
}
int V_9 ( const T_2 * V_33 , T_3 * V_45 ,
T_3 * V_35 , T_3 * V_36 , T_4 * V_46 )
{
int V_1 = 0 ;
if ( V_45 != NULL ) {
if ( ! F_8 ( V_45 , & V_33 -> V_34 ) )
return 0 ;
}
if ( V_35 != NULL ) {
if ( ! F_8 ( V_35 , & V_33 -> V_35 ) )
goto V_47;
}
if ( V_36 != NULL ) {
if ( ! F_8 ( V_36 , & V_33 -> V_36 ) )
goto V_47;
}
V_1 = 1 ;
V_47:
return V_1 ;
}
int V_10 ( const T_2 * V_33 )
{
return F_13 ( & V_33 -> V_34 ) - 1 ;
}
int V_11 ( const T_2 * V_33 ,
T_4 * V_46 )
{
int V_1 = 0 ;
T_3 * V_36 ;
T_4 * V_50 = NULL ;
if ( V_46 == NULL ) {
V_46 = V_50 = F_14 () ;
if ( V_46 == NULL ) {
F_11 ( V_51 ,
V_52 ) ;
goto V_47;
}
}
F_15 ( V_46 ) ;
V_36 = F_16 ( V_46 ) ;
if ( V_36 == NULL )
goto V_47;
if ( ! F_12 ( V_36 , & V_33 -> V_36 , V_33 -> V_37 ) )
goto V_47;
if ( F_17 ( V_36 ) )
goto V_47;
V_1 = 1 ;
V_47:
if ( V_46 != NULL )
F_18 ( V_46 ) ;
if ( V_50 != NULL )
F_19 ( V_50 ) ;
return V_1 ;
}
int V_12 ( T_5 * V_53 )
{
F_5 ( & V_53 -> V_54 ) ;
F_5 ( & V_53 -> V_55 ) ;
F_5 ( & V_53 -> V_56 ) ;
return 1 ;
}
void V_13 ( T_5 * V_53 )
{
F_6 ( & V_53 -> V_54 ) ;
F_6 ( & V_53 -> V_55 ) ;
F_6 ( & V_53 -> V_56 ) ;
}
void V_14 ( T_5 * V_53 )
{
F_7 ( & V_53 -> V_54 ) ;
F_7 ( & V_53 -> V_55 ) ;
F_7 ( & V_53 -> V_56 ) ;
V_53 -> V_57 = 0 ;
}
int V_15 ( T_5 * V_38 , const T_5 * V_39 )
{
if ( ! F_8 ( & V_38 -> V_54 , & V_39 -> V_54 ) )
return 0 ;
if ( ! F_8 ( & V_38 -> V_55 , & V_39 -> V_55 ) )
return 0 ;
if ( ! F_8 ( & V_38 -> V_56 , & V_39 -> V_56 ) )
return 0 ;
V_38 -> V_57 = V_39 -> V_57 ;
return 1 ;
}
int V_16 ( const T_2 * V_33 ,
T_5 * V_53 )
{
V_53 -> V_57 = 0 ;
F_20 ( & V_53 -> V_56 ) ;
return 1 ;
}
int V_17 ( const T_2 * V_33 ,
T_5 * V_53 ,
const T_3 * V_58 ,
const T_3 * V_59 , T_4 * V_46 )
{
int V_1 = 0 ;
if ( V_58 == NULL || V_59 == NULL ) {
F_11 ( V_60 ,
V_61 ) ;
return 0 ;
}
if ( ! F_8 ( & V_53 -> V_54 , V_58 ) )
goto V_47;
F_21 ( & V_53 -> V_54 , 0 ) ;
if ( ! F_8 ( & V_53 -> V_55 , V_59 ) )
goto V_47;
F_21 ( & V_53 -> V_55 , 0 ) ;
if ( ! F_8 ( & V_53 -> V_56 , F_22 () ) )
goto V_47;
F_21 ( & V_53 -> V_56 , 0 ) ;
V_53 -> V_57 = 1 ;
V_1 = 1 ;
V_47:
return V_1 ;
}
int V_18 ( const T_2 * V_33 ,
const T_5 * V_53 ,
T_3 * V_58 , T_3 * V_59 ,
T_4 * V_46 )
{
int V_1 = 0 ;
if ( F_23 ( V_33 , V_53 ) ) {
F_11 ( V_62 ,
V_63 ) ;
return 0 ;
}
if ( F_24 ( & V_53 -> V_56 , F_22 () ) ) {
F_11 ( V_62 ,
V_64 ) ;
return 0 ;
}
if ( V_58 != NULL ) {
if ( ! F_8 ( V_58 , & V_53 -> V_54 ) )
goto V_47;
F_21 ( V_58 , 0 ) ;
}
if ( V_59 != NULL ) {
if ( ! F_8 ( V_59 , & V_53 -> V_55 ) )
goto V_47;
F_21 ( V_59 , 0 ) ;
}
V_1 = 1 ;
V_47:
return V_1 ;
}
int V_19 ( const T_2 * V_33 , T_5 * V_65 , const T_5 * V_35 ,
const T_5 * V_36 , T_4 * V_46 )
{
T_4 * V_50 = NULL ;
T_3 * V_66 , * y0 , * V_67 , * y1 , * V_68 , * V_69 , * V_70 , * V_71 ;
int V_1 = 0 ;
if ( F_23 ( V_33 , V_35 ) ) {
if ( ! F_25 ( V_65 , V_36 ) )
return 0 ;
return 1 ;
}
if ( F_23 ( V_33 , V_36 ) ) {
if ( ! F_25 ( V_65 , V_35 ) )
return 0 ;
return 1 ;
}
if ( V_46 == NULL ) {
V_46 = V_50 = F_14 () ;
if ( V_46 == NULL )
return 0 ;
}
F_15 ( V_46 ) ;
V_66 = F_16 ( V_46 ) ;
y0 = F_16 ( V_46 ) ;
V_67 = F_16 ( V_46 ) ;
y1 = F_16 ( V_46 ) ;
V_68 = F_16 ( V_46 ) ;
V_69 = F_16 ( V_46 ) ;
V_70 = F_16 ( V_46 ) ;
V_71 = F_16 ( V_46 ) ;
if ( V_71 == NULL )
goto V_47;
if ( V_35 -> V_57 ) {
if ( ! F_8 ( V_66 , & V_35 -> V_54 ) )
goto V_47;
if ( ! F_8 ( y0 , & V_35 -> V_55 ) )
goto V_47;
} else {
if ( ! F_26 ( V_33 , V_35 , V_66 , y0 , V_46 ) )
goto V_47;
}
if ( V_36 -> V_57 ) {
if ( ! F_8 ( V_67 , & V_36 -> V_54 ) )
goto V_47;
if ( ! F_8 ( y1 , & V_36 -> V_55 ) )
goto V_47;
} else {
if ( ! F_26 ( V_33 , V_36 , V_67 , y1 , V_46 ) )
goto V_47;
}
if ( F_27 ( V_66 , V_67 ) ) {
if ( ! F_28 ( V_71 , V_66 , V_67 ) )
goto V_47;
if ( ! F_28 ( V_70 , y0 , y1 ) )
goto V_47;
if ( ! V_33 -> V_72 -> V_73 ( V_33 , V_70 , V_70 , V_71 , V_46 ) )
goto V_47;
if ( ! V_33 -> V_72 -> V_74 ( V_33 , V_68 , V_70 , V_46 ) )
goto V_47;
if ( ! F_28 ( V_68 , V_68 , & V_33 -> V_35 ) )
goto V_47;
if ( ! F_28 ( V_68 , V_68 , V_70 ) )
goto V_47;
if ( ! F_28 ( V_68 , V_68 , V_71 ) )
goto V_47;
} else {
if ( F_27 ( y0 , y1 ) || F_17 ( V_67 ) ) {
if ( ! F_29 ( V_33 , V_65 ) )
goto V_47;
V_1 = 1 ;
goto V_47;
}
if ( ! V_33 -> V_72 -> V_73 ( V_33 , V_70 , y1 , V_67 , V_46 ) )
goto V_47;
if ( ! F_28 ( V_70 , V_70 , V_67 ) )
goto V_47;
if ( ! V_33 -> V_72 -> V_74 ( V_33 , V_68 , V_70 , V_46 ) )
goto V_47;
if ( ! F_28 ( V_68 , V_68 , V_70 ) )
goto V_47;
if ( ! F_28 ( V_68 , V_68 , & V_33 -> V_35 ) )
goto V_47;
}
if ( ! F_28 ( V_69 , V_67 , V_68 ) )
goto V_47;
if ( ! V_33 -> V_72 -> V_75 ( V_33 , V_69 , V_69 , V_70 , V_46 ) )
goto V_47;
if ( ! F_28 ( V_69 , V_69 , V_68 ) )
goto V_47;
if ( ! F_28 ( V_69 , V_69 , y1 ) )
goto V_47;
if ( ! F_30 ( V_33 , V_65 , V_68 , V_69 , V_46 ) )
goto V_47;
V_1 = 1 ;
V_47:
F_18 ( V_46 ) ;
if ( V_50 != NULL )
F_19 ( V_50 ) ;
return V_1 ;
}
int V_20 ( const T_2 * V_33 , T_5 * V_65 , const T_5 * V_35 ,
T_4 * V_46 )
{
return V_19 ( V_33 , V_65 , V_35 , V_35 , V_46 ) ;
}
int V_21 ( const T_2 * V_33 , T_5 * V_53 , T_4 * V_46 )
{
if ( F_23 ( V_33 , V_53 ) || F_17 ( & V_53 -> V_55 ) )
return 1 ;
if ( ! F_31 ( V_33 , V_53 , V_46 ) )
return 0 ;
return F_28 ( & V_53 -> V_55 , & V_53 -> V_54 , & V_53 -> V_55 ) ;
}
int V_22 ( const T_2 * V_33 ,
const T_5 * V_53 )
{
return F_17 ( & V_53 -> V_56 ) ;
}
int V_23 ( const T_2 * V_33 , const T_5 * V_53 ,
T_4 * V_46 )
{
int V_1 = - 1 ;
T_4 * V_50 = NULL ;
T_3 * V_76 , * V_69 ;
int (* V_75) ( const T_2 * , T_3 * , const T_3 * ,
const T_3 * , T_4 * );
int (* V_74) ( const T_2 * , T_3 * , const T_3 * , T_4 * );
if ( F_23 ( V_33 , V_53 ) )
return 1 ;
V_75 = V_33 -> V_72 -> V_75 ;
V_74 = V_33 -> V_72 -> V_74 ;
if ( ! V_53 -> V_57 )
return - 1 ;
if ( V_46 == NULL ) {
V_46 = V_50 = F_14 () ;
if ( V_46 == NULL )
return - 1 ;
}
F_15 ( V_46 ) ;
V_69 = F_16 ( V_46 ) ;
V_76 = F_16 ( V_46 ) ;
if ( V_76 == NULL )
goto V_47;
if ( ! F_28 ( V_76 , & V_53 -> V_54 , & V_33 -> V_35 ) )
goto V_47;
if ( ! V_75 ( V_33 , V_76 , V_76 , & V_53 -> V_54 , V_46 ) )
goto V_47;
if ( ! F_28 ( V_76 , V_76 , & V_53 -> V_55 ) )
goto V_47;
if ( ! V_75 ( V_33 , V_76 , V_76 , & V_53 -> V_54 , V_46 ) )
goto V_47;
if ( ! F_28 ( V_76 , V_76 , & V_33 -> V_36 ) )
goto V_47;
if ( ! V_74 ( V_33 , V_69 , & V_53 -> V_55 , V_46 ) )
goto V_47;
if ( ! F_28 ( V_76 , V_76 , V_69 ) )
goto V_47;
V_1 = F_17 ( V_76 ) ;
V_47:
if ( V_46 )
F_18 ( V_46 ) ;
if ( V_50 )
F_19 ( V_50 ) ;
return V_1 ;
}
int V_24 ( const T_2 * V_33 , const T_5 * V_35 ,
const T_5 * V_36 , T_4 * V_46 )
{
T_3 * V_77 , * V_78 , * V_79 , * V_80 ;
T_4 * V_50 = NULL ;
int V_1 = - 1 ;
if ( F_23 ( V_33 , V_35 ) ) {
return F_23 ( V_33 , V_36 ) ? 0 : 1 ;
}
if ( F_23 ( V_33 , V_36 ) )
return 1 ;
if ( V_35 -> V_57 && V_36 -> V_57 ) {
return ( ( F_24 ( & V_35 -> V_54 , & V_36 -> V_54 ) == 0 )
&& F_24 ( & V_35 -> V_55 , & V_36 -> V_55 ) == 0 ) ? 0 : 1 ;
}
if ( V_46 == NULL ) {
V_46 = V_50 = F_14 () ;
if ( V_46 == NULL )
return - 1 ;
}
F_15 ( V_46 ) ;
V_77 = F_16 ( V_46 ) ;
V_78 = F_16 ( V_46 ) ;
V_79 = F_16 ( V_46 ) ;
V_80 = F_16 ( V_46 ) ;
if ( V_80 == NULL )
goto V_47;
if ( ! F_26 ( V_33 , V_35 , V_77 , V_78 , V_46 ) )
goto V_47;
if ( ! F_26 ( V_33 , V_36 , V_79 , V_80 , V_46 ) )
goto V_47;
V_1 = ( ( F_24 ( V_77 , V_79 ) == 0 ) && F_24 ( V_78 , V_80 ) == 0 ) ? 0 : 1 ;
V_47:
if ( V_46 )
F_18 ( V_46 ) ;
if ( V_50 )
F_19 ( V_50 ) ;
return V_1 ;
}
int V_25 ( const T_2 * V_33 , T_5 * V_53 ,
T_4 * V_46 )
{
T_4 * V_50 = NULL ;
T_3 * V_58 , * V_59 ;
int V_1 = 0 ;
if ( V_53 -> V_57 || F_23 ( V_33 , V_53 ) )
return 1 ;
if ( V_46 == NULL ) {
V_46 = V_50 = F_14 () ;
if ( V_46 == NULL )
return 0 ;
}
F_15 ( V_46 ) ;
V_58 = F_16 ( V_46 ) ;
V_59 = F_16 ( V_46 ) ;
if ( V_59 == NULL )
goto V_47;
if ( ! F_26 ( V_33 , V_53 , V_58 , V_59 , V_46 ) )
goto V_47;
if ( ! F_8 ( & V_53 -> V_54 , V_58 ) )
goto V_47;
if ( ! F_8 ( & V_53 -> V_55 , V_59 ) )
goto V_47;
if ( ! F_32 ( & V_53 -> V_56 ) )
goto V_47;
V_1 = 1 ;
V_47:
if ( V_46 )
F_18 ( V_46 ) ;
if ( V_50 )
F_19 ( V_50 ) ;
return V_1 ;
}
int V_26 ( const T_2 * V_33 , T_6 V_81 ,
T_5 * V_82 [] , T_4 * V_46 )
{
T_6 V_40 ;
for ( V_40 = 0 ; V_40 < V_81 ; V_40 ++ ) {
if ( ! V_33 -> V_72 -> V_83 ( V_33 , V_82 [ V_40 ] , V_46 ) )
return 0 ;
}
return 1 ;
}
int V_30 ( const T_2 * V_33 , T_3 * V_65 ,
const T_3 * V_35 , const T_3 * V_36 , T_4 * V_46 )
{
return F_33 ( V_65 , V_35 , V_36 , V_33 -> V_37 , V_46 ) ;
}
int V_31 ( const T_2 * V_33 , T_3 * V_65 ,
const T_3 * V_35 , T_4 * V_46 )
{
return F_34 ( V_65 , V_35 , V_33 -> V_37 , V_46 ) ;
}
int V_32 ( const T_2 * V_33 , T_3 * V_65 ,
const T_3 * V_35 , const T_3 * V_36 , T_4 * V_46 )
{
return F_35 ( V_65 , V_35 , V_36 , & V_33 -> V_34 , V_46 ) ;
}
