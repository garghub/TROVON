const T_1 * F_1 ( void )
{
#ifdef F_2
return F_3 () ;
#else
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
0 , 0 , 0 ,
V_21 ,
V_22 ,
V_23 ,
V_24 ,
V_25 ,
V_26 ,
V_27 ,
V_28 ,
0 ,
0 ,
0 ,
V_29 ,
V_30 ,
0 ,
0 ,
0 ,
0 } ;
return & V_1 ;
#endif
}
int V_4 ( T_2 * V_31 )
{
F_4 ( & V_31 -> V_32 ) ;
F_4 ( & V_31 -> V_33 ) ;
F_4 ( & V_31 -> V_34 ) ;
V_31 -> V_35 = 0 ;
return 1 ;
}
void V_5 ( T_2 * V_31 )
{
F_5 ( & V_31 -> V_32 ) ;
F_5 ( & V_31 -> V_33 ) ;
F_5 ( & V_31 -> V_34 ) ;
}
void V_6 ( T_2 * V_31 )
{
F_6 ( & V_31 -> V_32 ) ;
F_6 ( & V_31 -> V_33 ) ;
F_6 ( & V_31 -> V_34 ) ;
}
int V_7 ( T_2 * V_36 , const T_2 * V_37 )
{
if ( ! F_7 ( & V_36 -> V_32 , & V_37 -> V_32 ) ) return 0 ;
if ( ! F_7 ( & V_36 -> V_33 , & V_37 -> V_33 ) ) return 0 ;
if ( ! F_7 ( & V_36 -> V_34 , & V_37 -> V_34 ) ) return 0 ;
V_36 -> V_35 = V_37 -> V_35 ;
return 1 ;
}
int V_8 ( T_2 * V_31 ,
const T_3 * V_38 , const T_3 * V_33 , const T_3 * V_34 , T_4 * V_39 )
{
int V_1 = 0 ;
T_4 * V_40 = NULL ;
T_3 * V_41 ;
if ( F_8 ( V_38 ) <= 2 || ! F_9 ( V_38 ) )
{
F_10 ( V_42 , V_43 ) ;
return 0 ;
}
if ( V_39 == NULL )
{
V_39 = V_40 = F_11 () ;
if ( V_39 == NULL )
return 0 ;
}
F_12 ( V_39 ) ;
V_41 = F_13 ( V_39 ) ;
if ( V_41 == NULL ) goto V_44;
if ( ! F_7 ( & V_31 -> V_32 , V_38 ) ) goto V_44;
F_14 ( & V_31 -> V_32 , 0 ) ;
if ( ! F_15 ( V_41 , V_33 , V_38 , V_39 ) ) goto V_44;
if ( V_31 -> V_45 -> V_46 )
{ if ( ! V_31 -> V_45 -> V_46 ( V_31 , & V_31 -> V_33 , V_41 , V_39 ) ) goto V_44; }
else
if ( ! F_7 ( & V_31 -> V_33 , V_41 ) ) goto V_44;
if ( ! F_15 ( & V_31 -> V_34 , V_34 , V_38 , V_39 ) ) goto V_44;
if ( V_31 -> V_45 -> V_46 )
if ( ! V_31 -> V_45 -> V_46 ( V_31 , & V_31 -> V_34 , & V_31 -> V_34 , V_39 ) ) goto V_44;
if ( ! F_16 ( V_41 , 3 ) ) goto V_44;
V_31 -> V_35 = ( 0 == F_17 ( V_41 , & V_31 -> V_32 ) ) ;
V_1 = 1 ;
V_44:
F_18 ( V_39 ) ;
if ( V_40 != NULL )
F_19 ( V_40 ) ;
return V_1 ;
}
int V_9 ( const T_2 * V_31 , T_3 * V_38 , T_3 * V_33 , T_3 * V_34 , T_4 * V_39 )
{
int V_1 = 0 ;
T_4 * V_40 = NULL ;
if ( V_38 != NULL )
{
if ( ! F_7 ( V_38 , & V_31 -> V_32 ) ) return 0 ;
}
if ( V_33 != NULL || V_34 != NULL )
{
if ( V_31 -> V_45 -> V_47 )
{
if ( V_39 == NULL )
{
V_39 = V_40 = F_11 () ;
if ( V_39 == NULL )
return 0 ;
}
if ( V_33 != NULL )
{
if ( ! V_31 -> V_45 -> V_47 ( V_31 , V_33 , & V_31 -> V_33 , V_39 ) ) goto V_44;
}
if ( V_34 != NULL )
{
if ( ! V_31 -> V_45 -> V_47 ( V_31 , V_34 , & V_31 -> V_34 , V_39 ) ) goto V_44;
}
}
else
{
if ( V_33 != NULL )
{
if ( ! F_7 ( V_33 , & V_31 -> V_33 ) ) goto V_44;
}
if ( V_34 != NULL )
{
if ( ! F_7 ( V_34 , & V_31 -> V_34 ) ) goto V_44;
}
}
}
V_1 = 1 ;
V_44:
if ( V_40 )
F_19 ( V_40 ) ;
return V_1 ;
}
int V_10 ( const T_2 * V_31 )
{
return F_8 ( & V_31 -> V_32 ) ;
}
int V_11 ( const T_2 * V_31 , T_4 * V_39 )
{
int V_1 = 0 ;
T_3 * V_33 , * V_34 , * V_48 , * V_49 , * V_50 ;
const T_3 * V_38 = & V_31 -> V_32 ;
T_4 * V_40 = NULL ;
if ( V_39 == NULL )
{
V_39 = V_40 = F_11 () ;
if ( V_39 == NULL )
{
F_10 ( V_51 , V_52 ) ;
goto V_44;
}
}
F_12 ( V_39 ) ;
V_33 = F_13 ( V_39 ) ;
V_34 = F_13 ( V_39 ) ;
V_49 = F_13 ( V_39 ) ;
V_50 = F_13 ( V_39 ) ;
V_48 = F_13 ( V_39 ) ;
if ( V_48 == NULL ) goto V_44;
if ( V_31 -> V_45 -> V_47 )
{
if ( ! V_31 -> V_45 -> V_47 ( V_31 , V_33 , & V_31 -> V_33 , V_39 ) ) goto V_44;
if ( ! V_31 -> V_45 -> V_47 ( V_31 , V_34 , & V_31 -> V_34 , V_39 ) ) goto V_44;
}
else
{
if ( ! F_7 ( V_33 , & V_31 -> V_33 ) ) goto V_44;
if ( ! F_7 ( V_34 , & V_31 -> V_34 ) ) goto V_44;
}
if ( F_20 ( V_33 ) )
{
if ( F_20 ( V_34 ) ) goto V_44;
}
else if ( ! F_20 ( V_34 ) )
{
if ( ! F_21 ( V_49 , V_33 , V_38 , V_39 ) ) goto V_44;
if ( ! F_22 ( V_50 , V_49 , V_33 , V_38 , V_39 ) ) goto V_44;
if ( ! F_23 ( V_49 , V_50 , 2 ) ) goto V_44;
if ( ! F_21 ( V_50 , V_34 , V_38 , V_39 ) ) goto V_44;
if ( ! F_24 ( V_50 , 27 ) ) goto V_44;
if ( ! F_25 ( V_33 , V_49 , V_50 , V_38 , V_39 ) ) goto V_44;
if ( F_20 ( V_33 ) ) goto V_44;
}
V_1 = 1 ;
V_44:
if ( V_39 != NULL )
F_18 ( V_39 ) ;
if ( V_40 != NULL )
F_19 ( V_40 ) ;
return V_1 ;
}
int V_12 ( T_5 * V_53 )
{
F_4 ( & V_53 -> V_54 ) ;
F_4 ( & V_53 -> V_55 ) ;
F_4 ( & V_53 -> V_56 ) ;
V_53 -> V_57 = 0 ;
return 1 ;
}
void V_13 ( T_5 * V_53 )
{
F_5 ( & V_53 -> V_54 ) ;
F_5 ( & V_53 -> V_55 ) ;
F_5 ( & V_53 -> V_56 ) ;
}
void V_14 ( T_5 * V_53 )
{
F_6 ( & V_53 -> V_54 ) ;
F_6 ( & V_53 -> V_55 ) ;
F_6 ( & V_53 -> V_56 ) ;
V_53 -> V_57 = 0 ;
}
int V_15 ( T_5 * V_36 , const T_5 * V_37 )
{
if ( ! F_7 ( & V_36 -> V_54 , & V_37 -> V_54 ) ) return 0 ;
if ( ! F_7 ( & V_36 -> V_55 , & V_37 -> V_55 ) ) return 0 ;
if ( ! F_7 ( & V_36 -> V_56 , & V_37 -> V_56 ) ) return 0 ;
V_36 -> V_57 = V_37 -> V_57 ;
return 1 ;
}
int V_16 ( const T_2 * V_31 , T_5 * V_53 )
{
V_53 -> V_57 = 0 ;
F_26 ( & V_53 -> V_56 ) ;
return 1 ;
}
int V_17 ( const T_2 * V_31 , T_5 * V_53 ,
const T_3 * V_58 , const T_3 * V_59 , const T_3 * V_60 , T_4 * V_39 )
{
T_4 * V_40 = NULL ;
int V_1 = 0 ;
if ( V_39 == NULL )
{
V_39 = V_40 = F_11 () ;
if ( V_39 == NULL )
return 0 ;
}
if ( V_58 != NULL )
{
if ( ! F_15 ( & V_53 -> V_54 , V_58 , & V_31 -> V_32 , V_39 ) ) goto V_44;
if ( V_31 -> V_45 -> V_46 )
{
if ( ! V_31 -> V_45 -> V_46 ( V_31 , & V_53 -> V_54 , & V_53 -> V_54 , V_39 ) ) goto V_44;
}
}
if ( V_59 != NULL )
{
if ( ! F_15 ( & V_53 -> V_55 , V_59 , & V_31 -> V_32 , V_39 ) ) goto V_44;
if ( V_31 -> V_45 -> V_46 )
{
if ( ! V_31 -> V_45 -> V_46 ( V_31 , & V_53 -> V_55 , & V_53 -> V_55 , V_39 ) ) goto V_44;
}
}
if ( V_60 != NULL )
{
int V_57 ;
if ( ! F_15 ( & V_53 -> V_56 , V_60 , & V_31 -> V_32 , V_39 ) ) goto V_44;
V_57 = F_27 ( & V_53 -> V_56 ) ;
if ( V_31 -> V_45 -> V_46 )
{
if ( V_57 && ( V_31 -> V_45 -> V_61 != 0 ) )
{
if ( ! V_31 -> V_45 -> V_61 ( V_31 , & V_53 -> V_56 , V_39 ) ) goto V_44;
}
else
{
if ( ! V_31 -> V_45 -> V_46 ( V_31 , & V_53 -> V_56 , & V_53 -> V_56 , V_39 ) ) goto V_44;
}
}
V_53 -> V_57 = V_57 ;
}
V_1 = 1 ;
V_44:
if ( V_40 != NULL )
F_19 ( V_40 ) ;
return V_1 ;
}
int V_18 ( const T_2 * V_31 , const T_5 * V_53 ,
T_3 * V_58 , T_3 * V_59 , T_3 * V_60 , T_4 * V_39 )
{
T_4 * V_40 = NULL ;
int V_1 = 0 ;
if ( V_31 -> V_45 -> V_47 != 0 )
{
if ( V_39 == NULL )
{
V_39 = V_40 = F_11 () ;
if ( V_39 == NULL )
return 0 ;
}
if ( V_58 != NULL )
{
if ( ! V_31 -> V_45 -> V_47 ( V_31 , V_58 , & V_53 -> V_54 , V_39 ) ) goto V_44;
}
if ( V_59 != NULL )
{
if ( ! V_31 -> V_45 -> V_47 ( V_31 , V_59 , & V_53 -> V_55 , V_39 ) ) goto V_44;
}
if ( V_60 != NULL )
{
if ( ! V_31 -> V_45 -> V_47 ( V_31 , V_60 , & V_53 -> V_56 , V_39 ) ) goto V_44;
}
}
else
{
if ( V_58 != NULL )
{
if ( ! F_7 ( V_58 , & V_53 -> V_54 ) ) goto V_44;
}
if ( V_59 != NULL )
{
if ( ! F_7 ( V_59 , & V_53 -> V_55 ) ) goto V_44;
}
if ( V_60 != NULL )
{
if ( ! F_7 ( V_60 , & V_53 -> V_56 ) ) goto V_44;
}
}
V_1 = 1 ;
V_44:
if ( V_40 != NULL )
F_19 ( V_40 ) ;
return V_1 ;
}
int V_19 ( const T_2 * V_31 , T_5 * V_53 ,
const T_3 * V_58 , const T_3 * V_59 , T_4 * V_39 )
{
if ( V_58 == NULL || V_59 == NULL )
{
F_10 ( V_62 , V_63 ) ;
return 0 ;
}
return F_28 ( V_31 , V_53 , V_58 , V_59 , F_29 () , V_39 ) ;
}
int V_20 ( const T_2 * V_31 , const T_5 * V_53 ,
T_3 * V_58 , T_3 * V_59 , T_4 * V_39 )
{
T_4 * V_40 = NULL ;
T_3 * V_56 , * V_64 , * V_65 , * V_66 ;
const T_3 * V_67 ;
int V_1 = 0 ;
if ( F_30 ( V_31 , V_53 ) )
{
F_10 ( V_68 , V_69 ) ;
return 0 ;
}
if ( V_39 == NULL )
{
V_39 = V_40 = F_11 () ;
if ( V_39 == NULL )
return 0 ;
}
F_12 ( V_39 ) ;
V_56 = F_13 ( V_39 ) ;
V_64 = F_13 ( V_39 ) ;
V_65 = F_13 ( V_39 ) ;
V_66 = F_13 ( V_39 ) ;
if ( V_66 == NULL ) goto V_44;
if ( V_31 -> V_45 -> V_47 )
{
if ( ! V_31 -> V_45 -> V_47 ( V_31 , V_56 , & V_53 -> V_56 , V_39 ) ) goto V_44;
V_67 = V_56 ;
}
else
{
V_67 = & V_53 -> V_56 ;
}
if ( F_27 ( V_67 ) )
{
if ( V_31 -> V_45 -> V_47 )
{
if ( V_58 != NULL )
{
if ( ! V_31 -> V_45 -> V_47 ( V_31 , V_58 , & V_53 -> V_54 , V_39 ) ) goto V_44;
}
if ( V_59 != NULL )
{
if ( ! V_31 -> V_45 -> V_47 ( V_31 , V_59 , & V_53 -> V_55 , V_39 ) ) goto V_44;
}
}
else
{
if ( V_58 != NULL )
{
if ( ! F_7 ( V_58 , & V_53 -> V_54 ) ) goto V_44;
}
if ( V_59 != NULL )
{
if ( ! F_7 ( V_59 , & V_53 -> V_55 ) ) goto V_44;
}
}
}
else
{
if ( ! F_31 ( V_64 , V_67 , & V_31 -> V_32 , V_39 ) )
{
F_10 ( V_68 , V_70 ) ;
goto V_44;
}
if ( V_31 -> V_45 -> V_46 == 0 )
{
if ( ! V_31 -> V_45 -> V_71 ( V_31 , V_65 , V_64 , V_39 ) ) goto V_44;
}
else
{
if ( ! F_21 ( V_65 , V_64 , & V_31 -> V_32 , V_39 ) ) goto V_44;
}
if ( V_58 != NULL )
{
if ( ! V_31 -> V_45 -> V_72 ( V_31 , V_58 , & V_53 -> V_54 , V_65 , V_39 ) ) goto V_44;
}
if ( V_59 != NULL )
{
if ( V_31 -> V_45 -> V_46 == 0 )
{
if ( ! V_31 -> V_45 -> V_72 ( V_31 , V_66 , V_65 , V_64 , V_39 ) ) goto V_44;
}
else
{
if ( ! F_22 ( V_66 , V_65 , V_64 , & V_31 -> V_32 , V_39 ) ) goto V_44;
}
if ( ! V_31 -> V_45 -> V_72 ( V_31 , V_59 , & V_53 -> V_55 , V_66 , V_39 ) ) goto V_44;
}
}
V_1 = 1 ;
V_44:
F_18 ( V_39 ) ;
if ( V_40 != NULL )
F_19 ( V_40 ) ;
return V_1 ;
}
int V_21 ( const T_2 * V_31 , T_5 * V_73 , const T_5 * V_33 , const T_5 * V_34 , T_4 * V_39 )
{
int (* V_72)( const T_2 * , T_3 * , const T_3 * , const T_3 * , T_4 * );
int (* V_71)( const T_2 * , T_3 * , const T_3 * , T_4 * );
const T_3 * V_38 ;
T_4 * V_40 = NULL ;
T_3 * V_74 , * V_75 , * V_76 , * V_77 , * V_78 , * V_79 , * V_80 ;
int V_1 = 0 ;
if ( V_33 == V_34 )
return F_32 ( V_31 , V_73 , V_33 , V_39 ) ;
if ( F_30 ( V_31 , V_33 ) )
return F_33 ( V_73 , V_34 ) ;
if ( F_30 ( V_31 , V_34 ) )
return F_33 ( V_73 , V_33 ) ;
V_72 = V_31 -> V_45 -> V_72 ;
V_71 = V_31 -> V_45 -> V_71 ;
V_38 = & V_31 -> V_32 ;
if ( V_39 == NULL )
{
V_39 = V_40 = F_11 () ;
if ( V_39 == NULL )
return 0 ;
}
F_12 ( V_39 ) ;
V_74 = F_13 ( V_39 ) ;
V_75 = F_13 ( V_39 ) ;
V_76 = F_13 ( V_39 ) ;
V_77 = F_13 ( V_39 ) ;
V_78 = F_13 ( V_39 ) ;
V_79 = F_13 ( V_39 ) ;
V_80 = F_13 ( V_39 ) ;
if ( V_80 == NULL ) goto V_81;
if ( V_34 -> V_57 )
{
if ( ! F_7 ( V_75 , & V_33 -> V_54 ) ) goto V_81;
if ( ! F_7 ( V_76 , & V_33 -> V_55 ) ) goto V_81;
}
else
{
if ( ! V_71 ( V_31 , V_74 , & V_34 -> V_56 , V_39 ) ) goto V_81;
if ( ! V_72 ( V_31 , V_75 , & V_33 -> V_54 , V_74 , V_39 ) ) goto V_81;
if ( ! V_72 ( V_31 , V_74 , V_74 , & V_34 -> V_56 , V_39 ) ) goto V_81;
if ( ! V_72 ( V_31 , V_76 , & V_33 -> V_55 , V_74 , V_39 ) ) goto V_81;
}
if ( V_33 -> V_57 )
{
if ( ! F_7 ( V_77 , & V_34 -> V_54 ) ) goto V_81;
if ( ! F_7 ( V_78 , & V_34 -> V_55 ) ) goto V_81;
}
else
{
if ( ! V_71 ( V_31 , V_74 , & V_33 -> V_56 , V_39 ) ) goto V_81;
if ( ! V_72 ( V_31 , V_77 , & V_34 -> V_54 , V_74 , V_39 ) ) goto V_81;
if ( ! V_72 ( V_31 , V_74 , V_74 , & V_33 -> V_56 , V_39 ) ) goto V_81;
if ( ! V_72 ( V_31 , V_78 , & V_34 -> V_55 , V_74 , V_39 ) ) goto V_81;
}
if ( ! F_34 ( V_79 , V_75 , V_77 , V_38 ) ) goto V_81;
if ( ! F_34 ( V_80 , V_76 , V_78 , V_38 ) ) goto V_81;
if ( F_20 ( V_79 ) )
{
if ( F_20 ( V_80 ) )
{
F_18 ( V_39 ) ;
V_1 = F_32 ( V_31 , V_73 , V_33 , V_39 ) ;
V_39 = NULL ;
goto V_81;
}
else
{
F_26 ( & V_73 -> V_56 ) ;
V_73 -> V_57 = 0 ;
V_1 = 1 ;
goto V_81;
}
}
if ( ! F_35 ( V_75 , V_75 , V_77 , V_38 ) ) goto V_81;
if ( ! F_35 ( V_76 , V_76 , V_78 , V_38 ) ) goto V_81;
if ( V_33 -> V_57 && V_34 -> V_57 )
{
if ( ! F_7 ( & V_73 -> V_56 , V_79 ) ) goto V_81;
}
else
{
if ( V_33 -> V_57 )
{ if ( ! F_7 ( V_74 , & V_34 -> V_56 ) ) goto V_81; }
else if ( V_34 -> V_57 )
{ if ( ! F_7 ( V_74 , & V_33 -> V_56 ) ) goto V_81; }
else
{ if ( ! V_72 ( V_31 , V_74 , & V_33 -> V_56 , & V_34 -> V_56 , V_39 ) ) goto V_81; }
if ( ! V_72 ( V_31 , & V_73 -> V_56 , V_74 , V_79 , V_39 ) ) goto V_81;
}
V_73 -> V_57 = 0 ;
if ( ! V_71 ( V_31 , V_74 , V_80 , V_39 ) ) goto V_81;
if ( ! V_71 ( V_31 , V_78 , V_79 , V_39 ) ) goto V_81;
if ( ! V_72 ( V_31 , V_77 , V_75 , V_78 , V_39 ) ) goto V_81;
if ( ! F_34 ( & V_73 -> V_54 , V_74 , V_77 , V_38 ) ) goto V_81;
if ( ! F_36 ( V_74 , & V_73 -> V_54 , V_38 ) ) goto V_81;
if ( ! F_34 ( V_74 , V_77 , V_74 , V_38 ) ) goto V_81;
if ( ! V_72 ( V_31 , V_74 , V_74 , V_80 , V_39 ) ) goto V_81;
if ( ! V_72 ( V_31 , V_79 , V_78 , V_79 , V_39 ) ) goto V_81;
if ( ! V_72 ( V_31 , V_75 , V_76 , V_79 , V_39 ) ) goto V_81;
if ( ! F_34 ( V_74 , V_74 , V_75 , V_38 ) ) goto V_81;
if ( F_9 ( V_74 ) )
if ( ! F_37 ( V_74 , V_74 , V_38 ) ) goto V_81;
if ( ! F_38 ( & V_73 -> V_55 , V_74 ) ) goto V_81;
V_1 = 1 ;
V_81:
if ( V_39 )
F_18 ( V_39 ) ;
if ( V_40 != NULL )
F_19 ( V_40 ) ;
return V_1 ;
}
int V_22 ( const T_2 * V_31 , T_5 * V_73 , const T_5 * V_33 , T_4 * V_39 )
{
int (* V_72)( const T_2 * , T_3 * , const T_3 * , const T_3 * , T_4 * );
int (* V_71)( const T_2 * , T_3 * , const T_3 * , T_4 * );
const T_3 * V_38 ;
T_4 * V_40 = NULL ;
T_3 * V_74 , * V_75 , * V_76 , * V_77 ;
int V_1 = 0 ;
if ( F_30 ( V_31 , V_33 ) )
{
F_26 ( & V_73 -> V_56 ) ;
V_73 -> V_57 = 0 ;
return 1 ;
}
V_72 = V_31 -> V_45 -> V_72 ;
V_71 = V_31 -> V_45 -> V_71 ;
V_38 = & V_31 -> V_32 ;
if ( V_39 == NULL )
{
V_39 = V_40 = F_11 () ;
if ( V_39 == NULL )
return 0 ;
}
F_12 ( V_39 ) ;
V_74 = F_13 ( V_39 ) ;
V_75 = F_13 ( V_39 ) ;
V_76 = F_13 ( V_39 ) ;
V_77 = F_13 ( V_39 ) ;
if ( V_77 == NULL ) goto V_44;
if ( V_33 -> V_57 )
{
if ( ! V_71 ( V_31 , V_74 , & V_33 -> V_54 , V_39 ) ) goto V_44;
if ( ! F_36 ( V_75 , V_74 , V_38 ) ) goto V_44;
if ( ! F_35 ( V_74 , V_74 , V_75 , V_38 ) ) goto V_44;
if ( ! F_35 ( V_75 , V_74 , & V_31 -> V_33 , V_38 ) ) goto V_44;
}
else if ( V_31 -> V_35 )
{
if ( ! V_71 ( V_31 , V_75 , & V_33 -> V_56 , V_39 ) ) goto V_44;
if ( ! F_35 ( V_74 , & V_33 -> V_54 , V_75 , V_38 ) ) goto V_44;
if ( ! F_34 ( V_76 , & V_33 -> V_54 , V_75 , V_38 ) ) goto V_44;
if ( ! V_72 ( V_31 , V_75 , V_74 , V_76 , V_39 ) ) goto V_44;
if ( ! F_36 ( V_74 , V_75 , V_38 ) ) goto V_44;
if ( ! F_35 ( V_75 , V_74 , V_75 , V_38 ) ) goto V_44;
}
else
{
if ( ! V_71 ( V_31 , V_74 , & V_33 -> V_54 , V_39 ) ) goto V_44;
if ( ! F_36 ( V_75 , V_74 , V_38 ) ) goto V_44;
if ( ! F_35 ( V_74 , V_74 , V_75 , V_38 ) ) goto V_44;
if ( ! V_71 ( V_31 , V_75 , & V_33 -> V_56 , V_39 ) ) goto V_44;
if ( ! V_71 ( V_31 , V_75 , V_75 , V_39 ) ) goto V_44;
if ( ! V_72 ( V_31 , V_75 , V_75 , & V_31 -> V_33 , V_39 ) ) goto V_44;
if ( ! F_35 ( V_75 , V_75 , V_74 , V_38 ) ) goto V_44;
}
if ( V_33 -> V_57 )
{
if ( ! F_7 ( V_74 , & V_33 -> V_55 ) ) goto V_44;
}
else
{
if ( ! V_72 ( V_31 , V_74 , & V_33 -> V_55 , & V_33 -> V_56 , V_39 ) ) goto V_44;
}
if ( ! F_36 ( & V_73 -> V_56 , V_74 , V_38 ) ) goto V_44;
V_73 -> V_57 = 0 ;
if ( ! V_71 ( V_31 , V_77 , & V_33 -> V_55 , V_39 ) ) goto V_44;
if ( ! V_72 ( V_31 , V_76 , & V_33 -> V_54 , V_77 , V_39 ) ) goto V_44;
if ( ! F_39 ( V_76 , V_76 , 2 , V_38 ) ) goto V_44;
if ( ! F_36 ( V_74 , V_76 , V_38 ) ) goto V_44;
if ( ! V_71 ( V_31 , & V_73 -> V_54 , V_75 , V_39 ) ) goto V_44;
if ( ! F_34 ( & V_73 -> V_54 , & V_73 -> V_54 , V_74 , V_38 ) ) goto V_44;
if ( ! V_71 ( V_31 , V_74 , V_77 , V_39 ) ) goto V_44;
if ( ! F_39 ( V_77 , V_74 , 3 , V_38 ) ) goto V_44;
if ( ! F_34 ( V_74 , V_76 , & V_73 -> V_54 , V_38 ) ) goto V_44;
if ( ! V_72 ( V_31 , V_74 , V_75 , V_74 , V_39 ) ) goto V_44;
if ( ! F_34 ( & V_73 -> V_55 , V_74 , V_77 , V_38 ) ) goto V_44;
V_1 = 1 ;
V_44:
F_18 ( V_39 ) ;
if ( V_40 != NULL )
F_19 ( V_40 ) ;
return V_1 ;
}
int V_23 ( const T_2 * V_31 , T_5 * V_53 , T_4 * V_39 )
{
if ( F_30 ( V_31 , V_53 ) || F_20 ( & V_53 -> V_55 ) )
return 1 ;
return F_40 ( & V_53 -> V_55 , & V_31 -> V_32 , & V_53 -> V_55 ) ;
}
int V_24 ( const T_2 * V_31 , const T_5 * V_53 )
{
return F_20 ( & V_53 -> V_56 ) ;
}
int V_25 ( const T_2 * V_31 , const T_5 * V_53 , T_4 * V_39 )
{
int (* V_72)( const T_2 * , T_3 * , const T_3 * , const T_3 * , T_4 * );
int (* V_71)( const T_2 * , T_3 * , const T_3 * , T_4 * );
const T_3 * V_38 ;
T_4 * V_40 = NULL ;
T_3 * V_82 , * V_83 , * V_84 , * V_85 ;
int V_1 = - 1 ;
if ( F_30 ( V_31 , V_53 ) )
return 1 ;
V_72 = V_31 -> V_45 -> V_72 ;
V_71 = V_31 -> V_45 -> V_71 ;
V_38 = & V_31 -> V_32 ;
if ( V_39 == NULL )
{
V_39 = V_40 = F_11 () ;
if ( V_39 == NULL )
return - 1 ;
}
F_12 ( V_39 ) ;
V_82 = F_13 ( V_39 ) ;
V_83 = F_13 ( V_39 ) ;
V_84 = F_13 ( V_39 ) ;
V_85 = F_13 ( V_39 ) ;
if ( V_85 == NULL ) goto V_44;
if ( ! V_71 ( V_31 , V_82 , & V_53 -> V_54 , V_39 ) ) goto V_44;
if ( ! V_53 -> V_57 )
{
if ( ! V_71 ( V_31 , V_83 , & V_53 -> V_56 , V_39 ) ) goto V_44;
if ( ! V_71 ( V_31 , V_84 , V_83 , V_39 ) ) goto V_44;
if ( ! V_72 ( V_31 , V_85 , V_84 , V_83 , V_39 ) ) goto V_44;
if ( V_31 -> V_35 )
{
if ( ! F_36 ( V_83 , V_84 , V_38 ) ) goto V_44;
if ( ! F_35 ( V_83 , V_83 , V_84 , V_38 ) ) goto V_44;
if ( ! F_34 ( V_82 , V_82 , V_83 , V_38 ) ) goto V_44;
if ( ! V_72 ( V_31 , V_82 , V_82 , & V_53 -> V_54 , V_39 ) ) goto V_44;
}
else
{
if ( ! V_72 ( V_31 , V_83 , V_84 , & V_31 -> V_33 , V_39 ) ) goto V_44;
if ( ! F_35 ( V_82 , V_82 , V_83 , V_38 ) ) goto V_44;
if ( ! V_72 ( V_31 , V_82 , V_82 , & V_53 -> V_54 , V_39 ) ) goto V_44;
}
if ( ! V_72 ( V_31 , V_83 , & V_31 -> V_34 , V_85 , V_39 ) ) goto V_44;
if ( ! F_35 ( V_82 , V_82 , V_83 , V_38 ) ) goto V_44;
}
else
{
if ( ! F_35 ( V_82 , V_82 , & V_31 -> V_33 , V_38 ) ) goto V_44;
if ( ! V_72 ( V_31 , V_82 , V_82 , & V_53 -> V_54 , V_39 ) ) goto V_44;
if ( ! F_35 ( V_82 , V_82 , & V_31 -> V_34 , V_38 ) ) goto V_44;
}
if ( ! V_71 ( V_31 , V_83 , & V_53 -> V_55 , V_39 ) ) goto V_44;
V_1 = ( 0 == F_41 ( V_83 , V_82 ) ) ;
V_44:
F_18 ( V_39 ) ;
if ( V_40 != NULL )
F_19 ( V_40 ) ;
return V_1 ;
}
int V_26 ( const T_2 * V_31 , const T_5 * V_33 , const T_5 * V_34 , T_4 * V_39 )
{
int (* V_72)( const T_2 * , T_3 * , const T_3 * , const T_3 * , T_4 * );
int (* V_71)( const T_2 * , T_3 * , const T_3 * , T_4 * );
T_4 * V_40 = NULL ;
T_3 * V_86 , * V_87 , * V_88 , * V_89 ;
const T_3 * V_90 , * V_91 ;
int V_1 = - 1 ;
if ( F_30 ( V_31 , V_33 ) )
{
return F_30 ( V_31 , V_34 ) ? 0 : 1 ;
}
if ( F_30 ( V_31 , V_34 ) )
return 1 ;
if ( V_33 -> V_57 && V_34 -> V_57 )
{
return ( ( F_17 ( & V_33 -> V_54 , & V_34 -> V_54 ) == 0 ) && F_17 ( & V_33 -> V_55 , & V_34 -> V_55 ) == 0 ) ? 0 : 1 ;
}
V_72 = V_31 -> V_45 -> V_72 ;
V_71 = V_31 -> V_45 -> V_71 ;
if ( V_39 == NULL )
{
V_39 = V_40 = F_11 () ;
if ( V_39 == NULL )
return - 1 ;
}
F_12 ( V_39 ) ;
V_86 = F_13 ( V_39 ) ;
V_87 = F_13 ( V_39 ) ;
V_88 = F_13 ( V_39 ) ;
V_89 = F_13 ( V_39 ) ;
if ( V_89 == NULL ) goto V_81;
if ( ! V_34 -> V_57 )
{
if ( ! V_71 ( V_31 , V_89 , & V_34 -> V_56 , V_39 ) ) goto V_81;
if ( ! V_72 ( V_31 , V_86 , & V_33 -> V_54 , V_89 , V_39 ) ) goto V_81;
V_90 = V_86 ;
}
else
V_90 = & V_33 -> V_54 ;
if ( ! V_33 -> V_57 )
{
if ( ! V_71 ( V_31 , V_88 , & V_33 -> V_56 , V_39 ) ) goto V_81;
if ( ! V_72 ( V_31 , V_87 , & V_34 -> V_54 , V_88 , V_39 ) ) goto V_81;
V_91 = V_87 ;
}
else
V_91 = & V_34 -> V_54 ;
if ( F_17 ( V_90 , V_91 ) != 0 )
{
V_1 = 1 ;
goto V_81;
}
if ( ! V_34 -> V_57 )
{
if ( ! V_72 ( V_31 , V_89 , V_89 , & V_34 -> V_56 , V_39 ) ) goto V_81;
if ( ! V_72 ( V_31 , V_86 , & V_33 -> V_55 , V_89 , V_39 ) ) goto V_81;
}
else
V_90 = & V_33 -> V_55 ;
if ( ! V_33 -> V_57 )
{
if ( ! V_72 ( V_31 , V_88 , V_88 , & V_33 -> V_56 , V_39 ) ) goto V_81;
if ( ! V_72 ( V_31 , V_87 , & V_34 -> V_55 , V_88 , V_39 ) ) goto V_81;
}
else
V_91 = & V_34 -> V_55 ;
if ( F_17 ( V_90 , V_91 ) != 0 )
{
V_1 = 1 ;
goto V_81;
}
V_1 = 0 ;
V_81:
F_18 ( V_39 ) ;
if ( V_40 != NULL )
F_19 ( V_40 ) ;
return V_1 ;
}
int V_27 ( const T_2 * V_31 , T_5 * V_53 , T_4 * V_39 )
{
T_4 * V_40 = NULL ;
T_3 * V_58 , * V_59 ;
int V_1 = 0 ;
if ( V_53 -> V_57 || F_30 ( V_31 , V_53 ) )
return 1 ;
if ( V_39 == NULL )
{
V_39 = V_40 = F_11 () ;
if ( V_39 == NULL )
return 0 ;
}
F_12 ( V_39 ) ;
V_58 = F_13 ( V_39 ) ;
V_59 = F_13 ( V_39 ) ;
if ( V_59 == NULL ) goto V_44;
if ( ! F_42 ( V_31 , V_53 , V_58 , V_59 , V_39 ) ) goto V_44;
if ( ! F_43 ( V_31 , V_53 , V_58 , V_59 , V_39 ) ) goto V_44;
if ( ! V_53 -> V_57 )
{
F_10 ( V_92 , V_93 ) ;
goto V_44;
}
V_1 = 1 ;
V_44:
F_18 ( V_39 ) ;
if ( V_40 != NULL )
F_19 ( V_40 ) ;
return V_1 ;
}
int V_28 ( const T_2 * V_31 , T_6 V_94 , T_5 * V_95 [] , T_4 * V_39 )
{
T_4 * V_40 = NULL ;
T_3 * V_96 , * V_86 ;
T_6 V_97 = 0 ;
T_3 * * V_98 = NULL ;
T_6 V_99 ;
int V_1 = 0 ;
if ( V_94 == 0 )
return 1 ;
if ( V_39 == NULL )
{
V_39 = V_40 = F_11 () ;
if ( V_39 == NULL )
return 0 ;
}
F_12 ( V_39 ) ;
V_96 = F_13 ( V_39 ) ;
V_86 = F_13 ( V_39 ) ;
if ( V_96 == NULL || V_86 == NULL ) goto V_44;
V_97 = 1 ;
while ( V_94 > V_97 )
V_97 <<= 1 ;
V_97 <<= 1 ;
V_98 = F_44 ( V_97 * sizeof V_98 [ 0 ] ) ;
if ( V_98 == NULL ) goto V_44;
V_98 [ 0 ] = NULL ;
for ( V_99 = V_97 / 2 - 1 ; V_99 > 0 ; V_99 -- )
V_98 [ V_99 ] = NULL ;
for ( V_99 = 0 ; V_99 < V_94 ; V_99 ++ )
V_98 [ V_97 / 2 + V_99 ] = & V_95 [ V_99 ] -> V_56 ;
for ( V_99 = V_97 / 2 + V_94 ; V_99 < V_97 ; V_99 ++ )
V_98 [ V_99 ] = NULL ;
for ( V_99 = V_97 / 2 - 1 ; V_99 > 0 ; V_99 -- )
{
V_98 [ V_99 ] = F_45 () ;
if ( V_98 [ V_99 ] == NULL ) goto V_44;
if ( V_98 [ 2 * V_99 ] != NULL )
{
if ( ( V_98 [ 2 * V_99 + 1 ] == NULL ) || F_20 ( V_98 [ 2 * V_99 + 1 ] ) )
{
if ( ! F_7 ( V_98 [ V_99 ] , V_98 [ 2 * V_99 ] ) ) goto V_44;
}
else
{
if ( F_20 ( V_98 [ 2 * V_99 ] ) )
{
if ( ! F_7 ( V_98 [ V_99 ] , V_98 [ 2 * V_99 + 1 ] ) ) goto V_44;
}
else
{
if ( ! V_31 -> V_45 -> V_72 ( V_31 , V_98 [ V_99 ] ,
V_98 [ 2 * V_99 ] , V_98 [ 2 * V_99 + 1 ] , V_39 ) ) goto V_44;
}
}
}
}
if ( ! F_20 ( V_98 [ 1 ] ) )
{
if ( ! F_31 ( V_98 [ 1 ] , V_98 [ 1 ] , & V_31 -> V_32 , V_39 ) )
{
F_10 ( V_100 , V_70 ) ;
goto V_44;
}
}
if ( V_31 -> V_45 -> V_46 != 0 )
{
if ( ! V_31 -> V_45 -> V_46 ( V_31 , V_98 [ 1 ] , V_98 [ 1 ] , V_39 ) ) goto V_44;
if ( ! V_31 -> V_45 -> V_46 ( V_31 , V_98 [ 1 ] , V_98 [ 1 ] , V_39 ) ) goto V_44;
}
for ( V_99 = 2 ; V_99 < V_97 / 2 + V_94 ; V_99 += 2 )
{
if ( ( V_98 [ V_99 + 1 ] != NULL ) && ! F_20 ( V_98 [ V_99 + 1 ] ) )
{
if ( ! V_31 -> V_45 -> V_72 ( V_31 , V_96 , V_98 [ V_99 / 2 ] , V_98 [ V_99 + 1 ] , V_39 ) ) goto V_44;
if ( ! V_31 -> V_45 -> V_72 ( V_31 , V_86 , V_98 [ V_99 / 2 ] , V_98 [ V_99 ] , V_39 ) ) goto V_44;
if ( ! F_7 ( V_98 [ V_99 ] , V_96 ) ) goto V_44;
if ( ! F_7 ( V_98 [ V_99 + 1 ] , V_86 ) ) goto V_44;
}
else
{
if ( ! F_7 ( V_98 [ V_99 ] , V_98 [ V_99 / 2 ] ) ) goto V_44;
}
}
for ( V_99 = 0 ; V_99 < V_94 ; V_99 ++ )
{
T_5 * V_38 = V_95 [ V_99 ] ;
if ( ! F_20 ( & V_38 -> V_56 ) )
{
if ( ! V_31 -> V_45 -> V_71 ( V_31 , V_86 , & V_38 -> V_56 , V_39 ) ) goto V_44;
if ( ! V_31 -> V_45 -> V_72 ( V_31 , & V_38 -> V_54 , & V_38 -> V_54 , V_86 , V_39 ) ) goto V_44;
if ( ! V_31 -> V_45 -> V_72 ( V_31 , V_86 , V_86 , & V_38 -> V_56 , V_39 ) ) goto V_44;
if ( ! V_31 -> V_45 -> V_72 ( V_31 , & V_38 -> V_55 , & V_38 -> V_55 , V_86 , V_39 ) ) goto V_44;
if ( V_31 -> V_45 -> V_61 != 0 )
{
if ( ! V_31 -> V_45 -> V_61 ( V_31 , & V_38 -> V_56 , V_39 ) ) goto V_44;
}
else
{
if ( ! F_46 ( & V_38 -> V_56 ) ) goto V_44;
}
V_38 -> V_57 = 1 ;
}
}
V_1 = 1 ;
V_44:
F_18 ( V_39 ) ;
if ( V_40 != NULL )
F_19 ( V_40 ) ;
if ( V_98 != NULL )
{
for ( V_99 = V_97 / 2 - 1 ; V_99 > 0 ; V_99 -- )
{
if ( V_98 [ V_99 ] != NULL )
F_6 ( V_98 [ V_99 ] ) ;
}
F_47 ( V_98 ) ;
}
return V_1 ;
}
int V_29 ( const T_2 * V_31 , T_3 * V_73 , const T_3 * V_33 , const T_3 * V_34 , T_4 * V_39 )
{
return F_22 ( V_73 , V_33 , V_34 , & V_31 -> V_32 , V_39 ) ;
}
int V_30 ( const T_2 * V_31 , T_3 * V_73 , const T_3 * V_33 , T_4 * V_39 )
{
return F_21 ( V_73 , V_33 , & V_31 -> V_32 , V_39 ) ;
}
