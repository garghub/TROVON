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
V_18 ,
V_19 ,
V_20 ,
V_21 ,
0 , 0 , 0 ,
V_22 ,
V_23 ,
V_24 ,
V_25 ,
V_26 ,
V_27 ,
V_28 ,
V_29 ,
0 ,
0 ,
0 ,
V_30 ,
V_31 ,
0 ,
0 ,
0 ,
0 ,
V_32 ,
V_33 ,
0 ,
V_34 ,
V_35 ,
V_36 ,
0 ,
0 ,
V_37
} ;
return & V_1 ;
}
int V_4 ( T_2 * V_38 )
{
V_38 -> V_39 = F_2 () ;
V_38 -> V_40 = F_2 () ;
V_38 -> V_41 = F_2 () ;
if ( V_38 -> V_39 == NULL || V_38 -> V_40 == NULL || V_38 -> V_41 == NULL ) {
F_3 ( V_38 -> V_39 ) ;
F_3 ( V_38 -> V_40 ) ;
F_3 ( V_38 -> V_41 ) ;
return 0 ;
}
V_38 -> V_42 = 0 ;
return 1 ;
}
void V_5 ( T_2 * V_38 )
{
F_3 ( V_38 -> V_39 ) ;
F_3 ( V_38 -> V_40 ) ;
F_3 ( V_38 -> V_41 ) ;
}
void V_6 ( T_2 * V_38 )
{
F_4 ( V_38 -> V_39 ) ;
F_4 ( V_38 -> V_40 ) ;
F_4 ( V_38 -> V_41 ) ;
}
int V_7 ( T_2 * V_43 , const T_2 * V_44 )
{
if ( ! F_5 ( V_43 -> V_39 , V_44 -> V_39 ) )
return 0 ;
if ( ! F_5 ( V_43 -> V_40 , V_44 -> V_40 ) )
return 0 ;
if ( ! F_5 ( V_43 -> V_41 , V_44 -> V_41 ) )
return 0 ;
V_43 -> V_42 = V_44 -> V_42 ;
return 1 ;
}
int V_8 ( T_2 * V_38 ,
const T_3 * V_45 , const T_3 * V_40 ,
const T_3 * V_41 , T_4 * V_46 )
{
int V_1 = 0 ;
T_4 * V_47 = NULL ;
T_3 * V_48 ;
if ( F_6 ( V_45 ) <= 2 || ! F_7 ( V_45 ) ) {
F_8 ( V_49 , V_50 ) ;
return 0 ;
}
if ( V_46 == NULL ) {
V_46 = V_47 = F_9 () ;
if ( V_46 == NULL )
return 0 ;
}
F_10 ( V_46 ) ;
V_48 = F_11 ( V_46 ) ;
if ( V_48 == NULL )
goto V_51;
if ( ! F_5 ( V_38 -> V_39 , V_45 ) )
goto V_51;
F_12 ( V_38 -> V_39 , 0 ) ;
if ( ! F_13 ( V_48 , V_40 , V_45 , V_46 ) )
goto V_51;
if ( V_38 -> V_52 -> V_53 ) {
if ( ! V_38 -> V_52 -> V_53 ( V_38 , V_38 -> V_40 , V_48 , V_46 ) )
goto V_51;
} else if ( ! F_5 ( V_38 -> V_40 , V_48 ) )
goto V_51;
if ( ! F_13 ( V_38 -> V_41 , V_41 , V_45 , V_46 ) )
goto V_51;
if ( V_38 -> V_52 -> V_53 )
if ( ! V_38 -> V_52 -> V_53 ( V_38 , V_38 -> V_41 , V_38 -> V_41 , V_46 ) )
goto V_51;
if ( ! F_14 ( V_48 , 3 ) )
goto V_51;
V_38 -> V_42 = ( 0 == F_15 ( V_48 , V_38 -> V_39 ) ) ;
V_1 = 1 ;
V_51:
F_16 ( V_46 ) ;
F_17 ( V_47 ) ;
return V_1 ;
}
int V_9 ( const T_2 * V_38 , T_3 * V_45 , T_3 * V_40 ,
T_3 * V_41 , T_4 * V_46 )
{
int V_1 = 0 ;
T_4 * V_47 = NULL ;
if ( V_45 != NULL ) {
if ( ! F_5 ( V_45 , V_38 -> V_39 ) )
return 0 ;
}
if ( V_40 != NULL || V_41 != NULL ) {
if ( V_38 -> V_52 -> V_54 ) {
if ( V_46 == NULL ) {
V_46 = V_47 = F_9 () ;
if ( V_46 == NULL )
return 0 ;
}
if ( V_40 != NULL ) {
if ( ! V_38 -> V_52 -> V_54 ( V_38 , V_40 , V_38 -> V_40 , V_46 ) )
goto V_51;
}
if ( V_41 != NULL ) {
if ( ! V_38 -> V_52 -> V_54 ( V_38 , V_41 , V_38 -> V_41 , V_46 ) )
goto V_51;
}
} else {
if ( V_40 != NULL ) {
if ( ! F_5 ( V_40 , V_38 -> V_40 ) )
goto V_51;
}
if ( V_41 != NULL ) {
if ( ! F_5 ( V_41 , V_38 -> V_41 ) )
goto V_51;
}
}
}
V_1 = 1 ;
V_51:
F_17 ( V_47 ) ;
return V_1 ;
}
int V_10 ( const T_2 * V_38 )
{
return F_6 ( V_38 -> V_39 ) ;
}
int V_12 ( const T_2 * V_38 , T_4 * V_46 )
{
int V_1 = 0 ;
T_3 * V_40 , * V_41 , * V_55 , * V_56 , * V_57 ;
const T_3 * V_45 = V_38 -> V_39 ;
T_4 * V_47 = NULL ;
if ( V_46 == NULL ) {
V_46 = V_47 = F_9 () ;
if ( V_46 == NULL ) {
F_8 ( V_58 ,
V_59 ) ;
goto V_51;
}
}
F_10 ( V_46 ) ;
V_40 = F_11 ( V_46 ) ;
V_41 = F_11 ( V_46 ) ;
V_56 = F_11 ( V_46 ) ;
V_57 = F_11 ( V_46 ) ;
V_55 = F_11 ( V_46 ) ;
if ( V_55 == NULL )
goto V_51;
if ( V_38 -> V_52 -> V_54 ) {
if ( ! V_38 -> V_52 -> V_54 ( V_38 , V_40 , V_38 -> V_40 , V_46 ) )
goto V_51;
if ( ! V_38 -> V_52 -> V_54 ( V_38 , V_41 , V_38 -> V_41 , V_46 ) )
goto V_51;
} else {
if ( ! F_5 ( V_40 , V_38 -> V_40 ) )
goto V_51;
if ( ! F_5 ( V_41 , V_38 -> V_41 ) )
goto V_51;
}
if ( F_18 ( V_40 ) ) {
if ( F_18 ( V_41 ) )
goto V_51;
} else if ( ! F_18 ( V_41 ) ) {
if ( ! F_19 ( V_56 , V_40 , V_45 , V_46 ) )
goto V_51;
if ( ! F_20 ( V_57 , V_56 , V_40 , V_45 , V_46 ) )
goto V_51;
if ( ! F_21 ( V_56 , V_57 , 2 ) )
goto V_51;
if ( ! F_19 ( V_57 , V_41 , V_45 , V_46 ) )
goto V_51;
if ( ! F_22 ( V_57 , 27 ) )
goto V_51;
if ( ! F_23 ( V_40 , V_56 , V_57 , V_45 , V_46 ) )
goto V_51;
if ( F_18 ( V_40 ) )
goto V_51;
}
V_1 = 1 ;
V_51:
if ( V_46 != NULL )
F_16 ( V_46 ) ;
F_17 ( V_47 ) ;
return V_1 ;
}
int V_13 ( T_5 * V_60 )
{
V_60 -> V_61 = F_2 () ;
V_60 -> V_62 = F_2 () ;
V_60 -> V_63 = F_2 () ;
V_60 -> V_64 = 0 ;
if ( V_60 -> V_61 == NULL || V_60 -> V_62 == NULL || V_60 -> V_63 == NULL ) {
F_3 ( V_60 -> V_61 ) ;
F_3 ( V_60 -> V_62 ) ;
F_3 ( V_60 -> V_63 ) ;
return 0 ;
}
return 1 ;
}
void V_14 ( T_5 * V_60 )
{
F_3 ( V_60 -> V_61 ) ;
F_3 ( V_60 -> V_62 ) ;
F_3 ( V_60 -> V_63 ) ;
}
void V_15 ( T_5 * V_60 )
{
F_4 ( V_60 -> V_61 ) ;
F_4 ( V_60 -> V_62 ) ;
F_4 ( V_60 -> V_63 ) ;
V_60 -> V_64 = 0 ;
}
int V_16 ( T_5 * V_43 , const T_5 * V_44 )
{
if ( ! F_5 ( V_43 -> V_61 , V_44 -> V_61 ) )
return 0 ;
if ( ! F_5 ( V_43 -> V_62 , V_44 -> V_62 ) )
return 0 ;
if ( ! F_5 ( V_43 -> V_63 , V_44 -> V_63 ) )
return 0 ;
V_43 -> V_64 = V_44 -> V_64 ;
return 1 ;
}
int V_17 ( const T_2 * V_38 ,
T_5 * V_60 )
{
V_60 -> V_64 = 0 ;
F_24 ( V_60 -> V_63 ) ;
return 1 ;
}
int V_18 ( const T_2 * V_38 ,
T_5 * V_60 ,
const T_3 * V_65 ,
const T_3 * V_66 ,
const T_3 * V_67 ,
T_4 * V_46 )
{
T_4 * V_47 = NULL ;
int V_1 = 0 ;
if ( V_46 == NULL ) {
V_46 = V_47 = F_9 () ;
if ( V_46 == NULL )
return 0 ;
}
if ( V_65 != NULL ) {
if ( ! F_13 ( V_60 -> V_61 , V_65 , V_38 -> V_39 , V_46 ) )
goto V_51;
if ( V_38 -> V_52 -> V_53 ) {
if ( ! V_38 -> V_52 -> V_53 ( V_38 , V_60 -> V_61 , V_60 -> V_61 , V_46 ) )
goto V_51;
}
}
if ( V_66 != NULL ) {
if ( ! F_13 ( V_60 -> V_62 , V_66 , V_38 -> V_39 , V_46 ) )
goto V_51;
if ( V_38 -> V_52 -> V_53 ) {
if ( ! V_38 -> V_52 -> V_53 ( V_38 , V_60 -> V_62 , V_60 -> V_62 , V_46 ) )
goto V_51;
}
}
if ( V_67 != NULL ) {
int V_64 ;
if ( ! F_13 ( V_60 -> V_63 , V_67 , V_38 -> V_39 , V_46 ) )
goto V_51;
V_64 = F_25 ( V_60 -> V_63 ) ;
if ( V_38 -> V_52 -> V_53 ) {
if ( V_64 && ( V_38 -> V_52 -> V_68 != 0 ) ) {
if ( ! V_38 -> V_52 -> V_68 ( V_38 , V_60 -> V_63 , V_46 ) )
goto V_51;
} else {
if ( ! V_38 ->
V_52 -> V_53 ( V_38 , V_60 -> V_63 , V_60 -> V_63 , V_46 ) )
goto V_51;
}
}
V_60 -> V_64 = V_64 ;
}
V_1 = 1 ;
V_51:
F_17 ( V_47 ) ;
return V_1 ;
}
int V_19 ( const T_2 * V_38 ,
const T_5 * V_60 ,
T_3 * V_65 , T_3 * V_66 ,
T_3 * V_67 , T_4 * V_46 )
{
T_4 * V_47 = NULL ;
int V_1 = 0 ;
if ( V_38 -> V_52 -> V_54 != 0 ) {
if ( V_46 == NULL ) {
V_46 = V_47 = F_9 () ;
if ( V_46 == NULL )
return 0 ;
}
if ( V_65 != NULL ) {
if ( ! V_38 -> V_52 -> V_54 ( V_38 , V_65 , V_60 -> V_61 , V_46 ) )
goto V_51;
}
if ( V_66 != NULL ) {
if ( ! V_38 -> V_52 -> V_54 ( V_38 , V_66 , V_60 -> V_62 , V_46 ) )
goto V_51;
}
if ( V_67 != NULL ) {
if ( ! V_38 -> V_52 -> V_54 ( V_38 , V_67 , V_60 -> V_63 , V_46 ) )
goto V_51;
}
} else {
if ( V_65 != NULL ) {
if ( ! F_5 ( V_65 , V_60 -> V_61 ) )
goto V_51;
}
if ( V_66 != NULL ) {
if ( ! F_5 ( V_66 , V_60 -> V_62 ) )
goto V_51;
}
if ( V_67 != NULL ) {
if ( ! F_5 ( V_67 , V_60 -> V_63 ) )
goto V_51;
}
}
V_1 = 1 ;
V_51:
F_17 ( V_47 ) ;
return V_1 ;
}
int V_20 ( const T_2 * V_38 ,
T_5 * V_60 ,
const T_3 * V_65 ,
const T_3 * V_66 , T_4 * V_46 )
{
if ( V_65 == NULL || V_66 == NULL ) {
F_8 ( V_69 ,
V_70 ) ;
return 0 ;
}
return F_26 ( V_38 , V_60 , V_65 , V_66 ,
F_27 () , V_46 ) ;
}
int V_21 ( const T_2 * V_38 ,
const T_5 * V_60 ,
T_3 * V_65 , T_3 * V_66 ,
T_4 * V_46 )
{
T_4 * V_47 = NULL ;
T_3 * V_63 , * V_71 , * V_72 , * V_73 ;
const T_3 * V_74 ;
int V_1 = 0 ;
if ( F_28 ( V_38 , V_60 ) ) {
F_8 ( V_75 ,
V_76 ) ;
return 0 ;
}
if ( V_46 == NULL ) {
V_46 = V_47 = F_9 () ;
if ( V_46 == NULL )
return 0 ;
}
F_10 ( V_46 ) ;
V_63 = F_11 ( V_46 ) ;
V_71 = F_11 ( V_46 ) ;
V_72 = F_11 ( V_46 ) ;
V_73 = F_11 ( V_46 ) ;
if ( V_73 == NULL )
goto V_51;
if ( V_38 -> V_52 -> V_54 ) {
if ( ! V_38 -> V_52 -> V_54 ( V_38 , V_63 , V_60 -> V_63 , V_46 ) )
goto V_51;
V_74 = V_63 ;
} else {
V_74 = V_60 -> V_63 ;
}
if ( F_25 ( V_74 ) ) {
if ( V_38 -> V_52 -> V_54 ) {
if ( V_65 != NULL ) {
if ( ! V_38 -> V_52 -> V_54 ( V_38 , V_65 , V_60 -> V_61 , V_46 ) )
goto V_51;
}
if ( V_66 != NULL ) {
if ( ! V_38 -> V_52 -> V_54 ( V_38 , V_66 , V_60 -> V_62 , V_46 ) )
goto V_51;
}
} else {
if ( V_65 != NULL ) {
if ( ! F_5 ( V_65 , V_60 -> V_61 ) )
goto V_51;
}
if ( V_66 != NULL ) {
if ( ! F_5 ( V_66 , V_60 -> V_62 ) )
goto V_51;
}
}
} else {
if ( ! F_29 ( V_71 , V_74 , V_38 -> V_39 , V_46 ) ) {
F_8 ( V_75 ,
V_77 ) ;
goto V_51;
}
if ( V_38 -> V_52 -> V_53 == 0 ) {
if ( ! V_38 -> V_52 -> V_78 ( V_38 , V_72 , V_71 , V_46 ) )
goto V_51;
} else {
if ( ! F_19 ( V_72 , V_71 , V_38 -> V_39 , V_46 ) )
goto V_51;
}
if ( V_65 != NULL ) {
if ( ! V_38 -> V_52 -> V_79 ( V_38 , V_65 , V_60 -> V_61 , V_72 , V_46 ) )
goto V_51;
}
if ( V_66 != NULL ) {
if ( V_38 -> V_52 -> V_53 == 0 ) {
if ( ! V_38 -> V_52 -> V_79 ( V_38 , V_73 , V_72 , V_71 , V_46 ) )
goto V_51;
} else {
if ( ! F_20 ( V_73 , V_72 , V_71 , V_38 -> V_39 , V_46 ) )
goto V_51;
}
if ( ! V_38 -> V_52 -> V_79 ( V_38 , V_66 , V_60 -> V_62 , V_73 , V_46 ) )
goto V_51;
}
}
V_1 = 1 ;
V_51:
F_16 ( V_46 ) ;
F_17 ( V_47 ) ;
return V_1 ;
}
int V_22 ( const T_2 * V_38 , T_5 * V_80 , const T_5 * V_40 ,
const T_5 * V_41 , T_4 * V_46 )
{
int (* V_79) ( const T_2 * , T_3 * , const T_3 * ,
const T_3 * , T_4 * );
int (* V_78) ( const T_2 * , T_3 * , const T_3 * , T_4 * );
const T_3 * V_45 ;
T_4 * V_47 = NULL ;
T_3 * V_81 , * V_82 , * V_83 , * V_84 , * V_85 , * V_86 , * V_87 ;
int V_1 = 0 ;
if ( V_40 == V_41 )
return F_30 ( V_38 , V_80 , V_40 , V_46 ) ;
if ( F_28 ( V_38 , V_40 ) )
return F_31 ( V_80 , V_41 ) ;
if ( F_28 ( V_38 , V_41 ) )
return F_31 ( V_80 , V_40 ) ;
V_79 = V_38 -> V_52 -> V_79 ;
V_78 = V_38 -> V_52 -> V_78 ;
V_45 = V_38 -> V_39 ;
if ( V_46 == NULL ) {
V_46 = V_47 = F_9 () ;
if ( V_46 == NULL )
return 0 ;
}
F_10 ( V_46 ) ;
V_81 = F_11 ( V_46 ) ;
V_82 = F_11 ( V_46 ) ;
V_83 = F_11 ( V_46 ) ;
V_84 = F_11 ( V_46 ) ;
V_85 = F_11 ( V_46 ) ;
V_86 = F_11 ( V_46 ) ;
V_87 = F_11 ( V_46 ) ;
if ( V_87 == NULL )
goto V_88;
if ( V_41 -> V_64 ) {
if ( ! F_5 ( V_82 , V_40 -> V_61 ) )
goto V_88;
if ( ! F_5 ( V_83 , V_40 -> V_62 ) )
goto V_88;
} else {
if ( ! V_78 ( V_38 , V_81 , V_41 -> V_63 , V_46 ) )
goto V_88;
if ( ! V_79 ( V_38 , V_82 , V_40 -> V_61 , V_81 , V_46 ) )
goto V_88;
if ( ! V_79 ( V_38 , V_81 , V_81 , V_41 -> V_63 , V_46 ) )
goto V_88;
if ( ! V_79 ( V_38 , V_83 , V_40 -> V_62 , V_81 , V_46 ) )
goto V_88;
}
if ( V_40 -> V_64 ) {
if ( ! F_5 ( V_84 , V_41 -> V_61 ) )
goto V_88;
if ( ! F_5 ( V_85 , V_41 -> V_62 ) )
goto V_88;
} else {
if ( ! V_78 ( V_38 , V_81 , V_40 -> V_63 , V_46 ) )
goto V_88;
if ( ! V_79 ( V_38 , V_84 , V_41 -> V_61 , V_81 , V_46 ) )
goto V_88;
if ( ! V_79 ( V_38 , V_81 , V_81 , V_40 -> V_63 , V_46 ) )
goto V_88;
if ( ! V_79 ( V_38 , V_85 , V_41 -> V_62 , V_81 , V_46 ) )
goto V_88;
}
if ( ! F_32 ( V_86 , V_82 , V_84 , V_45 ) )
goto V_88;
if ( ! F_32 ( V_87 , V_83 , V_85 , V_45 ) )
goto V_88;
if ( F_18 ( V_86 ) ) {
if ( F_18 ( V_87 ) ) {
F_16 ( V_46 ) ;
V_1 = F_30 ( V_38 , V_80 , V_40 , V_46 ) ;
V_46 = NULL ;
goto V_88;
} else {
F_24 ( V_80 -> V_63 ) ;
V_80 -> V_64 = 0 ;
V_1 = 1 ;
goto V_88;
}
}
if ( ! F_33 ( V_82 , V_82 , V_84 , V_45 ) )
goto V_88;
if ( ! F_33 ( V_83 , V_83 , V_85 , V_45 ) )
goto V_88;
if ( V_40 -> V_64 && V_41 -> V_64 ) {
if ( ! F_5 ( V_80 -> V_63 , V_86 ) )
goto V_88;
} else {
if ( V_40 -> V_64 ) {
if ( ! F_5 ( V_81 , V_41 -> V_63 ) )
goto V_88;
} else if ( V_41 -> V_64 ) {
if ( ! F_5 ( V_81 , V_40 -> V_63 ) )
goto V_88;
} else {
if ( ! V_79 ( V_38 , V_81 , V_40 -> V_63 , V_41 -> V_63 , V_46 ) )
goto V_88;
}
if ( ! V_79 ( V_38 , V_80 -> V_63 , V_81 , V_86 , V_46 ) )
goto V_88;
}
V_80 -> V_64 = 0 ;
if ( ! V_78 ( V_38 , V_81 , V_87 , V_46 ) )
goto V_88;
if ( ! V_78 ( V_38 , V_85 , V_86 , V_46 ) )
goto V_88;
if ( ! V_79 ( V_38 , V_84 , V_82 , V_85 , V_46 ) )
goto V_88;
if ( ! F_32 ( V_80 -> V_61 , V_81 , V_84 , V_45 ) )
goto V_88;
if ( ! F_34 ( V_81 , V_80 -> V_61 , V_45 ) )
goto V_88;
if ( ! F_32 ( V_81 , V_84 , V_81 , V_45 ) )
goto V_88;
if ( ! V_79 ( V_38 , V_81 , V_81 , V_87 , V_46 ) )
goto V_88;
if ( ! V_79 ( V_38 , V_86 , V_85 , V_86 , V_46 ) )
goto V_88;
if ( ! V_79 ( V_38 , V_82 , V_83 , V_86 , V_46 ) )
goto V_88;
if ( ! F_32 ( V_81 , V_81 , V_82 , V_45 ) )
goto V_88;
if ( F_7 ( V_81 ) )
if ( ! F_35 ( V_81 , V_81 , V_45 ) )
goto V_88;
if ( ! F_36 ( V_80 -> V_62 , V_81 ) )
goto V_88;
V_1 = 1 ;
V_88:
if ( V_46 )
F_16 ( V_46 ) ;
F_17 ( V_47 ) ;
return V_1 ;
}
int V_23 ( const T_2 * V_38 , T_5 * V_80 , const T_5 * V_40 ,
T_4 * V_46 )
{
int (* V_79) ( const T_2 * , T_3 * , const T_3 * ,
const T_3 * , T_4 * );
int (* V_78) ( const T_2 * , T_3 * , const T_3 * , T_4 * );
const T_3 * V_45 ;
T_4 * V_47 = NULL ;
T_3 * V_81 , * V_82 , * V_83 , * V_84 ;
int V_1 = 0 ;
if ( F_28 ( V_38 , V_40 ) ) {
F_24 ( V_80 -> V_63 ) ;
V_80 -> V_64 = 0 ;
return 1 ;
}
V_79 = V_38 -> V_52 -> V_79 ;
V_78 = V_38 -> V_52 -> V_78 ;
V_45 = V_38 -> V_39 ;
if ( V_46 == NULL ) {
V_46 = V_47 = F_9 () ;
if ( V_46 == NULL )
return 0 ;
}
F_10 ( V_46 ) ;
V_81 = F_11 ( V_46 ) ;
V_82 = F_11 ( V_46 ) ;
V_83 = F_11 ( V_46 ) ;
V_84 = F_11 ( V_46 ) ;
if ( V_84 == NULL )
goto V_51;
if ( V_40 -> V_64 ) {
if ( ! V_78 ( V_38 , V_81 , V_40 -> V_61 , V_46 ) )
goto V_51;
if ( ! F_34 ( V_82 , V_81 , V_45 ) )
goto V_51;
if ( ! F_33 ( V_81 , V_81 , V_82 , V_45 ) )
goto V_51;
if ( ! F_33 ( V_82 , V_81 , V_38 -> V_40 , V_45 ) )
goto V_51;
} else if ( V_38 -> V_42 ) {
if ( ! V_78 ( V_38 , V_82 , V_40 -> V_63 , V_46 ) )
goto V_51;
if ( ! F_33 ( V_81 , V_40 -> V_61 , V_82 , V_45 ) )
goto V_51;
if ( ! F_32 ( V_83 , V_40 -> V_61 , V_82 , V_45 ) )
goto V_51;
if ( ! V_79 ( V_38 , V_82 , V_81 , V_83 , V_46 ) )
goto V_51;
if ( ! F_34 ( V_81 , V_82 , V_45 ) )
goto V_51;
if ( ! F_33 ( V_82 , V_81 , V_82 , V_45 ) )
goto V_51;
} else {
if ( ! V_78 ( V_38 , V_81 , V_40 -> V_61 , V_46 ) )
goto V_51;
if ( ! F_34 ( V_82 , V_81 , V_45 ) )
goto V_51;
if ( ! F_33 ( V_81 , V_81 , V_82 , V_45 ) )
goto V_51;
if ( ! V_78 ( V_38 , V_82 , V_40 -> V_63 , V_46 ) )
goto V_51;
if ( ! V_78 ( V_38 , V_82 , V_82 , V_46 ) )
goto V_51;
if ( ! V_79 ( V_38 , V_82 , V_82 , V_38 -> V_40 , V_46 ) )
goto V_51;
if ( ! F_33 ( V_82 , V_82 , V_81 , V_45 ) )
goto V_51;
}
if ( V_40 -> V_64 ) {
if ( ! F_5 ( V_81 , V_40 -> V_62 ) )
goto V_51;
} else {
if ( ! V_79 ( V_38 , V_81 , V_40 -> V_62 , V_40 -> V_63 , V_46 ) )
goto V_51;
}
if ( ! F_34 ( V_80 -> V_63 , V_81 , V_45 ) )
goto V_51;
V_80 -> V_64 = 0 ;
if ( ! V_78 ( V_38 , V_84 , V_40 -> V_62 , V_46 ) )
goto V_51;
if ( ! V_79 ( V_38 , V_83 , V_40 -> V_61 , V_84 , V_46 ) )
goto V_51;
if ( ! F_37 ( V_83 , V_83 , 2 , V_45 ) )
goto V_51;
if ( ! F_34 ( V_81 , V_83 , V_45 ) )
goto V_51;
if ( ! V_78 ( V_38 , V_80 -> V_61 , V_82 , V_46 ) )
goto V_51;
if ( ! F_32 ( V_80 -> V_61 , V_80 -> V_61 , V_81 , V_45 ) )
goto V_51;
if ( ! V_78 ( V_38 , V_81 , V_84 , V_46 ) )
goto V_51;
if ( ! F_37 ( V_84 , V_81 , 3 , V_45 ) )
goto V_51;
if ( ! F_32 ( V_81 , V_83 , V_80 -> V_61 , V_45 ) )
goto V_51;
if ( ! V_79 ( V_38 , V_81 , V_82 , V_81 , V_46 ) )
goto V_51;
if ( ! F_32 ( V_80 -> V_62 , V_81 , V_84 , V_45 ) )
goto V_51;
V_1 = 1 ;
V_51:
F_16 ( V_46 ) ;
F_17 ( V_47 ) ;
return V_1 ;
}
int V_24 ( const T_2 * V_38 , T_5 * V_60 , T_4 * V_46 )
{
if ( F_28 ( V_38 , V_60 ) || F_18 ( V_60 -> V_62 ) )
return 1 ;
return F_38 ( V_60 -> V_62 , V_38 -> V_39 , V_60 -> V_62 ) ;
}
int V_25 ( const T_2 * V_38 , const T_5 * V_60 )
{
return F_18 ( V_60 -> V_63 ) ;
}
int V_26 ( const T_2 * V_38 , const T_5 * V_60 ,
T_4 * V_46 )
{
int (* V_79) ( const T_2 * , T_3 * , const T_3 * ,
const T_3 * , T_4 * );
int (* V_78) ( const T_2 * , T_3 * , const T_3 * , T_4 * );
const T_3 * V_45 ;
T_4 * V_47 = NULL ;
T_3 * V_89 , * V_90 , * V_91 , * V_92 ;
int V_1 = - 1 ;
if ( F_28 ( V_38 , V_60 ) )
return 1 ;
V_79 = V_38 -> V_52 -> V_79 ;
V_78 = V_38 -> V_52 -> V_78 ;
V_45 = V_38 -> V_39 ;
if ( V_46 == NULL ) {
V_46 = V_47 = F_9 () ;
if ( V_46 == NULL )
return - 1 ;
}
F_10 ( V_46 ) ;
V_89 = F_11 ( V_46 ) ;
V_90 = F_11 ( V_46 ) ;
V_91 = F_11 ( V_46 ) ;
V_92 = F_11 ( V_46 ) ;
if ( V_92 == NULL )
goto V_51;
if ( ! V_78 ( V_38 , V_89 , V_60 -> V_61 , V_46 ) )
goto V_51;
if ( ! V_60 -> V_64 ) {
if ( ! V_78 ( V_38 , V_90 , V_60 -> V_63 , V_46 ) )
goto V_51;
if ( ! V_78 ( V_38 , V_91 , V_90 , V_46 ) )
goto V_51;
if ( ! V_79 ( V_38 , V_92 , V_91 , V_90 , V_46 ) )
goto V_51;
if ( V_38 -> V_42 ) {
if ( ! F_34 ( V_90 , V_91 , V_45 ) )
goto V_51;
if ( ! F_33 ( V_90 , V_90 , V_91 , V_45 ) )
goto V_51;
if ( ! F_32 ( V_89 , V_89 , V_90 , V_45 ) )
goto V_51;
if ( ! V_79 ( V_38 , V_89 , V_89 , V_60 -> V_61 , V_46 ) )
goto V_51;
} else {
if ( ! V_79 ( V_38 , V_90 , V_91 , V_38 -> V_40 , V_46 ) )
goto V_51;
if ( ! F_33 ( V_89 , V_89 , V_90 , V_45 ) )
goto V_51;
if ( ! V_79 ( V_38 , V_89 , V_89 , V_60 -> V_61 , V_46 ) )
goto V_51;
}
if ( ! V_79 ( V_38 , V_90 , V_38 -> V_41 , V_92 , V_46 ) )
goto V_51;
if ( ! F_33 ( V_89 , V_89 , V_90 , V_45 ) )
goto V_51;
} else {
if ( ! F_33 ( V_89 , V_89 , V_38 -> V_40 , V_45 ) )
goto V_51;
if ( ! V_79 ( V_38 , V_89 , V_89 , V_60 -> V_61 , V_46 ) )
goto V_51;
if ( ! F_33 ( V_89 , V_89 , V_38 -> V_41 , V_45 ) )
goto V_51;
}
if ( ! V_78 ( V_38 , V_90 , V_60 -> V_62 , V_46 ) )
goto V_51;
V_1 = ( 0 == F_39 ( V_90 , V_89 ) ) ;
V_51:
F_16 ( V_46 ) ;
F_17 ( V_47 ) ;
return V_1 ;
}
int V_27 ( const T_2 * V_38 , const T_5 * V_40 ,
const T_5 * V_41 , T_4 * V_46 )
{
int (* V_79) ( const T_2 * , T_3 * , const T_3 * ,
const T_3 * , T_4 * );
int (* V_78) ( const T_2 * , T_3 * , const T_3 * , T_4 * );
T_4 * V_47 = NULL ;
T_3 * V_93 , * V_94 , * V_95 , * V_96 ;
const T_3 * V_97 , * V_98 ;
int V_1 = - 1 ;
if ( F_28 ( V_38 , V_40 ) ) {
return F_28 ( V_38 , V_41 ) ? 0 : 1 ;
}
if ( F_28 ( V_38 , V_41 ) )
return 1 ;
if ( V_40 -> V_64 && V_41 -> V_64 ) {
return ( ( F_15 ( V_40 -> V_61 , V_41 -> V_61 ) == 0 ) && F_15 ( V_40 -> V_62 , V_41 -> V_62 ) == 0 ) ? 0 : 1 ;
}
V_79 = V_38 -> V_52 -> V_79 ;
V_78 = V_38 -> V_52 -> V_78 ;
if ( V_46 == NULL ) {
V_46 = V_47 = F_9 () ;
if ( V_46 == NULL )
return - 1 ;
}
F_10 ( V_46 ) ;
V_93 = F_11 ( V_46 ) ;
V_94 = F_11 ( V_46 ) ;
V_95 = F_11 ( V_46 ) ;
V_96 = F_11 ( V_46 ) ;
if ( V_96 == NULL )
goto V_88;
if ( ! V_41 -> V_64 ) {
if ( ! V_78 ( V_38 , V_96 , V_41 -> V_63 , V_46 ) )
goto V_88;
if ( ! V_79 ( V_38 , V_93 , V_40 -> V_61 , V_96 , V_46 ) )
goto V_88;
V_97 = V_93 ;
} else
V_97 = V_40 -> V_61 ;
if ( ! V_40 -> V_64 ) {
if ( ! V_78 ( V_38 , V_95 , V_40 -> V_63 , V_46 ) )
goto V_88;
if ( ! V_79 ( V_38 , V_94 , V_41 -> V_61 , V_95 , V_46 ) )
goto V_88;
V_98 = V_94 ;
} else
V_98 = V_41 -> V_61 ;
if ( F_15 ( V_97 , V_98 ) != 0 ) {
V_1 = 1 ;
goto V_88;
}
if ( ! V_41 -> V_64 ) {
if ( ! V_79 ( V_38 , V_96 , V_96 , V_41 -> V_63 , V_46 ) )
goto V_88;
if ( ! V_79 ( V_38 , V_93 , V_40 -> V_62 , V_96 , V_46 ) )
goto V_88;
} else
V_97 = V_40 -> V_62 ;
if ( ! V_40 -> V_64 ) {
if ( ! V_79 ( V_38 , V_95 , V_95 , V_40 -> V_63 , V_46 ) )
goto V_88;
if ( ! V_79 ( V_38 , V_94 , V_41 -> V_62 , V_95 , V_46 ) )
goto V_88;
} else
V_98 = V_41 -> V_62 ;
if ( F_15 ( V_97 , V_98 ) != 0 ) {
V_1 = 1 ;
goto V_88;
}
V_1 = 0 ;
V_88:
F_16 ( V_46 ) ;
F_17 ( V_47 ) ;
return V_1 ;
}
int V_28 ( const T_2 * V_38 , T_5 * V_60 ,
T_4 * V_46 )
{
T_4 * V_47 = NULL ;
T_3 * V_65 , * V_66 ;
int V_1 = 0 ;
if ( V_60 -> V_64 || F_28 ( V_38 , V_60 ) )
return 1 ;
if ( V_46 == NULL ) {
V_46 = V_47 = F_9 () ;
if ( V_46 == NULL )
return 0 ;
}
F_10 ( V_46 ) ;
V_65 = F_11 ( V_46 ) ;
V_66 = F_11 ( V_46 ) ;
if ( V_66 == NULL )
goto V_51;
if ( ! F_40 ( V_38 , V_60 , V_65 , V_66 , V_46 ) )
goto V_51;
if ( ! F_41 ( V_38 , V_60 , V_65 , V_66 , V_46 ) )
goto V_51;
if ( ! V_60 -> V_64 ) {
F_8 ( V_99 , V_100 ) ;
goto V_51;
}
V_1 = 1 ;
V_51:
F_16 ( V_46 ) ;
F_17 ( V_47 ) ;
return V_1 ;
}
int V_29 ( const T_2 * V_38 , T_6 V_101 ,
T_5 * V_102 [] , T_4 * V_46 )
{
T_4 * V_47 = NULL ;
T_3 * V_90 , * V_103 ;
T_3 * * V_104 = NULL ;
T_6 V_105 ;
int V_1 = 0 ;
if ( V_101 == 0 )
return 1 ;
if ( V_46 == NULL ) {
V_46 = V_47 = F_9 () ;
if ( V_46 == NULL )
return 0 ;
}
F_10 ( V_46 ) ;
V_90 = F_11 ( V_46 ) ;
V_103 = F_11 ( V_46 ) ;
if ( V_90 == NULL || V_103 == NULL )
goto V_51;
V_104 = F_42 ( V_101 * sizeof V_104 [ 0 ] ) ;
if ( V_104 == NULL )
goto V_51;
for ( V_105 = 0 ; V_105 < V_101 ; V_105 ++ ) {
V_104 [ V_105 ] = F_2 () ;
if ( V_104 [ V_105 ] == NULL )
goto V_51;
}
if ( ! F_18 ( V_102 [ 0 ] -> V_63 ) ) {
if ( ! F_5 ( V_104 [ 0 ] , V_102 [ 0 ] -> V_63 ) )
goto V_51;
} else {
if ( V_38 -> V_52 -> V_68 != 0 ) {
if ( ! V_38 -> V_52 -> V_68 ( V_38 , V_104 [ 0 ] , V_46 ) )
goto V_51;
} else {
if ( ! F_43 ( V_104 [ 0 ] ) )
goto V_51;
}
}
for ( V_105 = 1 ; V_105 < V_101 ; V_105 ++ ) {
if ( ! F_18 ( V_102 [ V_105 ] -> V_63 ) ) {
if ( ! V_38 ->
V_52 -> V_79 ( V_38 , V_104 [ V_105 ] , V_104 [ V_105 - 1 ] , V_102 [ V_105 ] -> V_63 ,
V_46 ) )
goto V_51;
} else {
if ( ! F_5 ( V_104 [ V_105 ] , V_104 [ V_105 - 1 ] ) )
goto V_51;
}
}
if ( ! F_29 ( V_90 , V_104 [ V_101 - 1 ] , V_38 -> V_39 , V_46 ) ) {
F_8 ( V_106 , V_77 ) ;
goto V_51;
}
if ( V_38 -> V_52 -> V_53 != 0 ) {
if ( ! V_38 -> V_52 -> V_53 ( V_38 , V_90 , V_90 , V_46 ) )
goto V_51;
if ( ! V_38 -> V_52 -> V_53 ( V_38 , V_90 , V_90 , V_46 ) )
goto V_51;
}
for ( V_105 = V_101 - 1 ; V_105 > 0 ; -- V_105 ) {
if ( ! F_18 ( V_102 [ V_105 ] -> V_63 ) ) {
if ( ! V_38 ->
V_52 -> V_79 ( V_38 , V_103 , V_104 [ V_105 - 1 ] , V_90 , V_46 ) )
goto V_51;
if ( ! V_38 -> V_52 -> V_79 ( V_38 , V_90 , V_90 , V_102 [ V_105 ] -> V_63 , V_46 ) )
goto V_51;
if ( ! F_5 ( V_102 [ V_105 ] -> V_63 , V_103 ) )
goto V_51;
}
}
if ( ! F_18 ( V_102 [ 0 ] -> V_63 ) ) {
if ( ! F_5 ( V_102 [ 0 ] -> V_63 , V_90 ) )
goto V_51;
}
for ( V_105 = 0 ; V_105 < V_101 ; V_105 ++ ) {
T_5 * V_45 = V_102 [ V_105 ] ;
if ( ! F_18 ( V_45 -> V_63 ) ) {
if ( ! V_38 -> V_52 -> V_78 ( V_38 , V_90 , V_45 -> V_63 , V_46 ) )
goto V_51;
if ( ! V_38 -> V_52 -> V_79 ( V_38 , V_45 -> V_61 , V_45 -> V_61 , V_90 , V_46 ) )
goto V_51;
if ( ! V_38 -> V_52 -> V_79 ( V_38 , V_90 , V_90 , V_45 -> V_63 , V_46 ) )
goto V_51;
if ( ! V_38 -> V_52 -> V_79 ( V_38 , V_45 -> V_62 , V_45 -> V_62 , V_90 , V_46 ) )
goto V_51;
if ( V_38 -> V_52 -> V_68 != 0 ) {
if ( ! V_38 -> V_52 -> V_68 ( V_38 , V_45 -> V_63 , V_46 ) )
goto V_51;
} else {
if ( ! F_43 ( V_45 -> V_63 ) )
goto V_51;
}
V_45 -> V_64 = 1 ;
}
}
V_1 = 1 ;
V_51:
F_16 ( V_46 ) ;
F_17 ( V_47 ) ;
if ( V_104 != NULL ) {
for ( V_105 = 0 ; V_105 < V_101 ; V_105 ++ ) {
if ( V_104 [ V_105 ] == NULL )
break;
F_4 ( V_104 [ V_105 ] ) ;
}
F_44 ( V_104 ) ;
}
return V_1 ;
}
int V_30 ( const T_2 * V_38 , T_3 * V_80 , const T_3 * V_40 ,
const T_3 * V_41 , T_4 * V_46 )
{
return F_20 ( V_80 , V_40 , V_41 , V_38 -> V_39 , V_46 ) ;
}
int V_31 ( const T_2 * V_38 , T_3 * V_80 , const T_3 * V_40 ,
T_4 * V_46 )
{
return F_19 ( V_80 , V_40 , V_38 -> V_39 , V_46 ) ;
}
