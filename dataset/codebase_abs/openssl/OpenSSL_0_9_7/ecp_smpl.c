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
0 } ;
return & V_1 ;
}
int V_2 ( T_2 * V_34 )
{
F_2 ( & V_34 -> V_35 ) ;
F_2 ( & V_34 -> V_36 ) ;
F_2 ( & V_34 -> V_37 ) ;
V_34 -> V_38 = 0 ;
V_34 -> V_39 = NULL ;
F_2 ( & V_34 -> V_40 ) ;
F_2 ( & V_34 -> V_41 ) ;
return 1 ;
}
void V_3 ( T_2 * V_34 )
{
F_3 ( & V_34 -> V_35 ) ;
F_3 ( & V_34 -> V_36 ) ;
F_3 ( & V_34 -> V_37 ) ;
if ( V_34 -> V_39 != NULL )
F_4 ( V_34 -> V_39 ) ;
F_3 ( & V_34 -> V_40 ) ;
F_3 ( & V_34 -> V_41 ) ;
}
void V_4 ( T_2 * V_34 )
{
F_5 ( & V_34 -> V_35 ) ;
F_5 ( & V_34 -> V_36 ) ;
F_5 ( & V_34 -> V_37 ) ;
if ( V_34 -> V_39 != NULL )
{
F_6 ( V_34 -> V_39 ) ;
V_34 -> V_39 = NULL ;
}
F_5 ( & V_34 -> V_40 ) ;
F_5 ( & V_34 -> V_41 ) ;
}
int V_5 ( T_2 * V_42 , const T_2 * V_43 )
{
if ( ! F_7 ( & V_42 -> V_35 , & V_43 -> V_35 ) ) return 0 ;
if ( ! F_7 ( & V_42 -> V_36 , & V_43 -> V_36 ) ) return 0 ;
if ( ! F_7 ( & V_42 -> V_37 , & V_43 -> V_37 ) ) return 0 ;
V_42 -> V_38 = V_43 -> V_38 ;
if ( V_43 -> V_39 != NULL )
{
if ( V_42 -> V_39 == NULL )
{
V_42 -> V_39 = F_8 ( V_42 ) ;
if ( V_42 -> V_39 == NULL ) return 0 ;
}
if ( ! F_9 ( V_42 -> V_39 , V_43 -> V_39 ) ) return 0 ;
}
else
{
if ( V_42 -> V_39 != NULL )
{
F_6 ( V_42 -> V_39 ) ;
V_42 -> V_39 = NULL ;
}
}
if ( ! F_7 ( & V_42 -> V_40 , & V_43 -> V_40 ) ) return 0 ;
if ( ! F_7 ( & V_42 -> V_41 , & V_43 -> V_41 ) ) return 0 ;
return 1 ;
}
int V_6 ( T_2 * V_34 ,
const T_3 * V_44 , const T_3 * V_36 , const T_3 * V_37 , T_4 * V_45 )
{
int V_1 = 0 ;
T_4 * V_46 = NULL ;
T_3 * V_47 ;
if ( F_10 ( V_44 ) <= 2 || ! F_11 ( V_44 ) )
{
F_12 ( V_48 , V_49 ) ;
return 0 ;
}
if ( V_45 == NULL )
{
V_45 = V_46 = F_13 () ;
if ( V_45 == NULL )
return 0 ;
}
F_14 ( V_45 ) ;
V_47 = F_15 ( V_45 ) ;
if ( V_47 == NULL ) goto V_50;
if ( ! F_7 ( & V_34 -> V_35 , V_44 ) ) goto V_50;
V_34 -> V_35 . V_51 = 0 ;
if ( ! F_16 ( V_47 , V_36 , V_44 , V_45 ) ) goto V_50;
if ( V_34 -> V_52 -> V_53 )
{ if ( ! V_34 -> V_52 -> V_53 ( V_34 , & V_34 -> V_36 , V_47 , V_45 ) ) goto V_50; }
else
if ( ! F_7 ( & V_34 -> V_36 , V_47 ) ) goto V_50;
if ( ! F_16 ( & V_34 -> V_37 , V_37 , V_44 , V_45 ) ) goto V_50;
if ( V_34 -> V_52 -> V_53 )
if ( ! V_34 -> V_52 -> V_53 ( V_34 , & V_34 -> V_37 , & V_34 -> V_37 , V_45 ) ) goto V_50;
if ( ! F_17 ( V_47 , 3 ) ) goto V_50;
V_34 -> V_38 = ( 0 == F_18 ( V_47 , & V_34 -> V_35 ) ) ;
V_1 = 1 ;
V_50:
F_19 ( V_45 ) ;
if ( V_46 != NULL )
F_20 ( V_46 ) ;
return V_1 ;
}
int V_7 ( const T_2 * V_34 , T_3 * V_44 , T_3 * V_36 , T_3 * V_37 , T_4 * V_45 )
{
int V_1 = 0 ;
T_4 * V_46 = NULL ;
if ( V_44 != NULL )
{
if ( ! F_7 ( V_44 , & V_34 -> V_35 ) ) return 0 ;
}
if ( V_36 != NULL || V_37 != NULL )
{
if ( V_34 -> V_52 -> V_54 )
{
if ( V_45 == NULL )
{
V_45 = V_46 = F_13 () ;
if ( V_45 == NULL )
return 0 ;
}
if ( V_36 != NULL )
{
if ( ! V_34 -> V_52 -> V_54 ( V_34 , V_36 , & V_34 -> V_36 , V_45 ) ) goto V_50;
}
if ( V_37 != NULL )
{
if ( ! V_34 -> V_52 -> V_54 ( V_34 , V_37 , & V_34 -> V_37 , V_45 ) ) goto V_50;
}
}
else
{
if ( V_36 != NULL )
{
if ( ! F_7 ( V_36 , & V_34 -> V_36 ) ) goto V_50;
}
if ( V_37 != NULL )
{
if ( ! F_7 ( V_37 , & V_34 -> V_37 ) ) goto V_50;
}
}
}
V_1 = 1 ;
V_50:
if ( V_46 )
F_20 ( V_46 ) ;
return V_1 ;
}
int V_8 ( T_2 * V_34 , const T_5 * V_39 ,
const T_3 * V_40 , const T_3 * V_41 )
{
if ( V_39 == NULL )
{
F_12 ( V_55 , V_56 ) ;
return 0 ;
}
if ( V_34 -> V_39 == NULL )
{
V_34 -> V_39 = F_8 ( V_34 ) ;
if ( V_34 -> V_39 == NULL ) return 0 ;
}
if ( ! F_9 ( V_34 -> V_39 , V_39 ) ) return 0 ;
if ( V_40 != NULL )
{ if ( ! F_7 ( & V_34 -> V_40 , V_40 ) ) return 0 ; }
else
{ if ( ! F_21 ( & V_34 -> V_40 ) ) return 0 ; }
if ( V_41 != NULL )
{ if ( ! F_7 ( & V_34 -> V_41 , V_41 ) ) return 0 ; }
else
{ if ( ! F_21 ( & V_34 -> V_41 ) ) return 0 ; }
return 1 ;
}
T_5 * V_9 ( const T_2 * V_34 )
{
return V_34 -> V_39 ;
}
int V_10 ( const T_2 * V_34 , T_3 * V_40 , T_4 * V_45 )
{
if ( ! F_7 ( V_40 , & V_34 -> V_40 ) )
return 0 ;
return ! F_22 ( & V_34 -> V_40 ) ;
}
int V_11 ( const T_2 * V_34 , T_3 * V_41 , T_4 * V_45 )
{
if ( ! F_7 ( V_41 , & V_34 -> V_41 ) )
return 0 ;
return ! F_22 ( & V_34 -> V_41 ) ;
}
int V_12 ( T_5 * V_57 )
{
F_2 ( & V_57 -> V_58 ) ;
F_2 ( & V_57 -> V_59 ) ;
F_2 ( & V_57 -> V_60 ) ;
V_57 -> V_61 = 0 ;
return 1 ;
}
void V_13 ( T_5 * V_57 )
{
F_3 ( & V_57 -> V_58 ) ;
F_3 ( & V_57 -> V_59 ) ;
F_3 ( & V_57 -> V_60 ) ;
}
void V_14 ( T_5 * V_57 )
{
F_5 ( & V_57 -> V_58 ) ;
F_5 ( & V_57 -> V_59 ) ;
F_5 ( & V_57 -> V_60 ) ;
V_57 -> V_61 = 0 ;
}
int V_15 ( T_5 * V_42 , const T_5 * V_43 )
{
if ( ! F_7 ( & V_42 -> V_58 , & V_43 -> V_58 ) ) return 0 ;
if ( ! F_7 ( & V_42 -> V_59 , & V_43 -> V_59 ) ) return 0 ;
if ( ! F_7 ( & V_42 -> V_60 , & V_43 -> V_60 ) ) return 0 ;
V_42 -> V_61 = V_43 -> V_61 ;
return 1 ;
}
int V_16 ( const T_2 * V_34 , T_5 * V_57 )
{
V_57 -> V_61 = 0 ;
return ( F_21 ( & V_57 -> V_60 ) ) ;
}
int V_17 ( const T_2 * V_34 , T_5 * V_57 ,
const T_3 * V_62 , const T_3 * V_63 , const T_3 * V_64 , T_4 * V_45 )
{
T_4 * V_46 = NULL ;
int V_1 = 0 ;
if ( V_45 == NULL )
{
V_45 = V_46 = F_13 () ;
if ( V_45 == NULL )
return 0 ;
}
if ( V_62 != NULL )
{
if ( ! F_16 ( & V_57 -> V_58 , V_62 , & V_34 -> V_35 , V_45 ) ) goto V_50;
if ( V_34 -> V_52 -> V_53 )
{
if ( ! V_34 -> V_52 -> V_53 ( V_34 , & V_57 -> V_58 , & V_57 -> V_58 , V_45 ) ) goto V_50;
}
}
if ( V_63 != NULL )
{
if ( ! F_16 ( & V_57 -> V_59 , V_63 , & V_34 -> V_35 , V_45 ) ) goto V_50;
if ( V_34 -> V_52 -> V_53 )
{
if ( ! V_34 -> V_52 -> V_53 ( V_34 , & V_57 -> V_59 , & V_57 -> V_59 , V_45 ) ) goto V_50;
}
}
if ( V_64 != NULL )
{
int V_61 ;
if ( ! F_16 ( & V_57 -> V_60 , V_64 , & V_34 -> V_35 , V_45 ) ) goto V_50;
V_61 = F_23 ( & V_57 -> V_60 ) ;
if ( V_34 -> V_52 -> V_53 )
{
if ( V_61 && ( V_34 -> V_52 -> V_65 != 0 ) )
{
if ( ! V_34 -> V_52 -> V_65 ( V_34 , & V_57 -> V_60 , V_45 ) ) goto V_50;
}
else
{
if ( ! V_34 -> V_52 -> V_53 ( V_34 , & V_57 -> V_60 , & V_57 -> V_60 , V_45 ) ) goto V_50;
}
}
V_57 -> V_61 = V_61 ;
}
V_1 = 1 ;
V_50:
if ( V_46 != NULL )
F_20 ( V_46 ) ;
return V_1 ;
}
int V_18 ( const T_2 * V_34 , const T_5 * V_57 ,
T_3 * V_62 , T_3 * V_63 , T_3 * V_64 , T_4 * V_45 )
{
T_4 * V_46 = NULL ;
int V_1 = 0 ;
if ( V_34 -> V_52 -> V_54 != 0 )
{
if ( V_45 == NULL )
{
V_45 = V_46 = F_13 () ;
if ( V_45 == NULL )
return 0 ;
}
if ( V_62 != NULL )
{
if ( ! V_34 -> V_52 -> V_54 ( V_34 , V_62 , & V_57 -> V_58 , V_45 ) ) goto V_50;
}
if ( V_63 != NULL )
{
if ( ! V_34 -> V_52 -> V_54 ( V_34 , V_63 , & V_57 -> V_59 , V_45 ) ) goto V_50;
}
if ( V_64 != NULL )
{
if ( ! V_34 -> V_52 -> V_54 ( V_34 , V_64 , & V_57 -> V_60 , V_45 ) ) goto V_50;
}
}
else
{
if ( V_62 != NULL )
{
if ( ! F_7 ( V_62 , & V_57 -> V_58 ) ) goto V_50;
}
if ( V_63 != NULL )
{
if ( ! F_7 ( V_63 , & V_57 -> V_59 ) ) goto V_50;
}
if ( V_64 != NULL )
{
if ( ! F_7 ( V_64 , & V_57 -> V_60 ) ) goto V_50;
}
}
V_1 = 1 ;
V_50:
if ( V_46 != NULL )
F_20 ( V_46 ) ;
return V_1 ;
}
int V_19 ( const T_2 * V_34 , T_5 * V_57 ,
const T_3 * V_62 , const T_3 * V_63 , T_4 * V_45 )
{
if ( V_62 == NULL || V_63 == NULL )
{
F_12 ( V_66 , V_56 ) ;
return 0 ;
}
return F_24 ( V_34 , V_57 , V_62 , V_63 , F_25 () , V_45 ) ;
}
int V_20 ( const T_2 * V_34 , const T_5 * V_57 ,
T_3 * V_62 , T_3 * V_63 , T_4 * V_45 )
{
T_4 * V_46 = NULL ;
T_3 * V_58 , * V_59 , * V_60 , * V_67 , * V_68 , * V_69 ;
const T_3 * V_70 , * V_71 , * V_72 ;
int V_1 = 0 ;
if ( F_26 ( V_34 , V_57 ) )
{
F_12 ( V_73 , V_74 ) ;
return 0 ;
}
if ( V_45 == NULL )
{
V_45 = V_46 = F_13 () ;
if ( V_45 == NULL )
return 0 ;
}
F_14 ( V_45 ) ;
V_58 = F_15 ( V_45 ) ;
V_59 = F_15 ( V_45 ) ;
V_60 = F_15 ( V_45 ) ;
V_67 = F_15 ( V_45 ) ;
V_68 = F_15 ( V_45 ) ;
V_69 = F_15 ( V_45 ) ;
if ( V_69 == NULL ) goto V_50;
if ( V_34 -> V_52 -> V_54 )
{
if ( ! V_34 -> V_52 -> V_54 ( V_34 , V_58 , & V_57 -> V_58 , V_45 ) ) goto V_50;
if ( ! V_34 -> V_52 -> V_54 ( V_34 , V_59 , & V_57 -> V_59 , V_45 ) ) goto V_50;
if ( ! V_34 -> V_52 -> V_54 ( V_34 , V_60 , & V_57 -> V_60 , V_45 ) ) goto V_50;
V_70 = V_58 ; V_71 = V_59 ; V_72 = V_60 ;
}
else
{
V_70 = & V_57 -> V_58 ;
V_71 = & V_57 -> V_59 ;
V_72 = & V_57 -> V_60 ;
}
if ( F_23 ( V_72 ) )
{
if ( V_62 != NULL )
{
if ( ! F_7 ( V_62 , V_70 ) ) goto V_50;
}
if ( V_63 != NULL )
{
if ( ! F_7 ( V_63 , V_71 ) ) goto V_50;
}
}
else
{
if ( ! F_27 ( V_67 , V_72 , & V_34 -> V_35 , V_45 ) )
{
F_12 ( V_73 , V_75 ) ;
goto V_50;
}
if ( V_34 -> V_52 -> V_53 == 0 )
{
if ( ! V_34 -> V_52 -> V_76 ( V_34 , V_68 , V_67 , V_45 ) ) goto V_50;
}
else
{
if ( ! F_28 ( V_68 , V_67 , & V_34 -> V_35 , V_45 ) ) goto V_50;
}
if ( V_62 != NULL )
{
if ( V_34 -> V_52 -> V_53 == 0 )
{
if ( ! V_34 -> V_52 -> V_77 ( V_34 , V_62 , V_70 , V_68 , V_45 ) ) goto V_50;
}
else
{
if ( ! F_29 ( V_62 , V_70 , V_68 , & V_34 -> V_35 , V_45 ) ) goto V_50;
}
}
if ( V_63 != NULL )
{
if ( V_34 -> V_52 -> V_53 == 0 )
{
if ( ! V_34 -> V_52 -> V_77 ( V_34 , V_69 , V_68 , V_67 , V_45 ) ) goto V_50;
if ( ! V_34 -> V_52 -> V_77 ( V_34 , V_63 , V_71 , V_69 , V_45 ) ) goto V_50;
}
else
{
if ( ! F_29 ( V_69 , V_68 , V_67 , & V_34 -> V_35 , V_45 ) ) goto V_50;
if ( ! F_29 ( V_63 , V_71 , V_69 , & V_34 -> V_35 , V_45 ) ) goto V_50;
}
}
}
V_1 = 1 ;
V_50:
F_19 ( V_45 ) ;
if ( V_46 != NULL )
F_20 ( V_46 ) ;
return V_1 ;
}
int V_21 ( const T_2 * V_34 , T_5 * V_57 ,
const T_3 * V_78 , int V_79 , T_4 * V_45 )
{
T_4 * V_46 = NULL ;
T_3 * V_80 , * V_81 , * V_62 , * V_63 ;
int V_1 = 0 ;
if ( V_45 == NULL )
{
V_45 = V_46 = F_13 () ;
if ( V_45 == NULL )
return 0 ;
}
V_79 = ( V_79 != 0 ) ;
F_14 ( V_45 ) ;
V_80 = F_15 ( V_45 ) ;
V_81 = F_15 ( V_45 ) ;
V_62 = F_15 ( V_45 ) ;
V_63 = F_15 ( V_45 ) ;
if ( V_63 == NULL ) goto V_50;
if ( ! F_16 ( V_62 , V_78 , & V_34 -> V_35 , V_45 ) ) goto V_50;
if ( V_34 -> V_52 -> V_54 == 0 )
{
if ( ! V_34 -> V_52 -> V_76 ( V_34 , V_81 , V_78 , V_45 ) ) goto V_50;
if ( ! V_34 -> V_52 -> V_77 ( V_34 , V_80 , V_81 , V_78 , V_45 ) ) goto V_50;
}
else
{
if ( ! F_28 ( V_81 , V_78 , & V_34 -> V_35 , V_45 ) ) goto V_50;
if ( ! F_29 ( V_80 , V_81 , V_78 , & V_34 -> V_35 , V_45 ) ) goto V_50;
}
if ( V_34 -> V_38 )
{
if ( ! F_30 ( V_81 , V_62 , & V_34 -> V_35 ) ) goto V_50;
if ( ! F_31 ( V_81 , V_81 , V_62 , & V_34 -> V_35 ) ) goto V_50;
if ( ! F_32 ( V_80 , V_80 , V_81 , & V_34 -> V_35 ) ) goto V_50;
}
else
{
if ( V_34 -> V_52 -> V_54 )
{
if ( ! V_34 -> V_52 -> V_54 ( V_34 , V_81 , & V_34 -> V_36 , V_45 ) ) goto V_50;
if ( ! F_29 ( V_81 , V_81 , V_62 , & V_34 -> V_35 , V_45 ) ) goto V_50;
}
else
{
if ( ! V_34 -> V_52 -> V_77 ( V_34 , V_81 , & V_34 -> V_36 , V_62 , V_45 ) ) goto V_50;
}
if ( ! F_31 ( V_80 , V_80 , V_81 , & V_34 -> V_35 ) ) goto V_50;
}
if ( V_34 -> V_52 -> V_54 )
{
if ( ! V_34 -> V_52 -> V_54 ( V_34 , V_81 , & V_34 -> V_37 , V_45 ) ) goto V_50;
if ( ! F_31 ( V_80 , V_80 , V_81 , & V_34 -> V_35 ) ) goto V_50;
}
else
{
if ( ! F_31 ( V_80 , V_80 , & V_34 -> V_37 , & V_34 -> V_35 ) ) goto V_50;
}
if ( ! F_33 ( V_63 , V_80 , & V_34 -> V_35 , V_45 ) )
{
unsigned long V_50 = F_34 () ;
if ( F_35 ( V_50 ) == V_82 && F_36 ( V_50 ) == V_83 )
{
( void ) F_37 () ;
F_12 ( V_84 , V_85 ) ;
}
else
F_12 ( V_84 , V_75 ) ;
goto V_50;
}
if ( V_79 != F_11 ( V_63 ) )
{
if ( F_22 ( V_63 ) )
{
int V_86 ;
V_86 = F_38 ( V_62 , & V_34 -> V_35 , V_45 ) ;
if ( V_86 == - 2 ) goto V_50;
if ( V_86 == 1 )
F_12 ( V_84 , V_87 ) ;
else
F_12 ( V_84 , V_85 ) ;
goto V_50;
}
if ( ! F_39 ( V_63 , & V_34 -> V_35 , V_63 ) ) goto V_50;
}
if ( V_79 != F_11 ( V_63 ) )
{
F_12 ( V_84 , V_88 ) ;
goto V_50;
}
if ( ! F_40 ( V_34 , V_57 , V_62 , V_63 , V_45 ) ) goto V_50;
V_1 = 1 ;
V_50:
F_19 ( V_45 ) ;
if ( V_46 != NULL )
F_20 ( V_46 ) ;
return V_1 ;
}
T_6 V_22 ( const T_2 * V_34 , const T_5 * V_57 , T_7 V_89 ,
unsigned char * V_90 , T_6 V_91 , T_4 * V_45 )
{
T_6 V_1 ;
T_4 * V_46 = NULL ;
int V_92 = 0 ;
T_3 * V_62 , * V_63 ;
T_6 V_93 , V_94 , V_95 ;
if ( ( V_89 != V_96 )
&& ( V_89 != V_97 )
&& ( V_89 != V_98 ) )
{
F_12 ( V_99 , V_100 ) ;
goto V_50;
}
if ( F_26 ( V_34 , V_57 ) )
{
if ( V_90 != NULL )
{
if ( V_91 < 1 )
{
F_12 ( V_99 , V_101 ) ;
return 0 ;
}
V_90 [ 0 ] = 0 ;
}
return 1 ;
}
V_93 = F_41 ( & V_34 -> V_35 ) ;
V_1 = ( V_89 == V_96 ) ? 1 + V_93 : 1 + 2 * V_93 ;
if ( V_90 != NULL )
{
if ( V_91 < V_1 )
{
F_12 ( V_99 , V_101 ) ;
goto V_50;
}
if ( V_45 == NULL )
{
V_45 = V_46 = F_13 () ;
if ( V_45 == NULL )
return 0 ;
}
F_14 ( V_45 ) ;
V_92 = 1 ;
V_62 = F_15 ( V_45 ) ;
V_63 = F_15 ( V_45 ) ;
if ( V_63 == NULL ) goto V_50;
if ( ! F_42 ( V_34 , V_57 , V_62 , V_63 , V_45 ) ) goto V_50;
if ( ( V_89 == V_96 || V_89 == V_98 ) && F_11 ( V_63 ) )
V_90 [ 0 ] = V_89 + 1 ;
else
V_90 [ 0 ] = V_89 ;
V_94 = 1 ;
V_95 = V_93 - F_41 ( V_62 ) ;
if ( V_95 > V_93 )
{
F_12 ( V_99 , V_88 ) ;
goto V_50;
}
while ( V_95 > 0 )
{
V_90 [ V_94 ++ ] = 0 ;
V_95 -- ;
}
V_95 = F_43 ( V_62 , V_90 + V_94 ) ;
V_94 += V_95 ;
if ( V_94 != 1 + V_93 )
{
F_12 ( V_99 , V_88 ) ;
goto V_50;
}
if ( V_89 == V_97 || V_89 == V_98 )
{
V_95 = V_93 - F_41 ( V_63 ) ;
if ( V_95 > V_93 )
{
F_12 ( V_99 , V_88 ) ;
goto V_50;
}
while ( V_95 > 0 )
{
V_90 [ V_94 ++ ] = 0 ;
V_95 -- ;
}
V_95 = F_43 ( V_63 , V_90 + V_94 ) ;
V_94 += V_95 ;
}
if ( V_94 != V_1 )
{
F_12 ( V_99 , V_88 ) ;
goto V_50;
}
}
if ( V_92 )
F_19 ( V_45 ) ;
if ( V_46 != NULL )
F_20 ( V_46 ) ;
return V_1 ;
V_50:
if ( V_92 )
F_19 ( V_45 ) ;
if ( V_46 != NULL )
F_20 ( V_46 ) ;
return 0 ;
}
int V_23 ( const T_2 * V_34 , T_5 * V_57 ,
const unsigned char * V_90 , T_6 V_91 , T_4 * V_45 )
{
T_7 V_89 ;
int V_79 ;
T_4 * V_46 = NULL ;
T_3 * V_62 , * V_63 ;
T_6 V_93 , V_102 ;
int V_1 = 0 ;
if ( V_91 == 0 )
{
F_12 ( V_103 , V_101 ) ;
return 0 ;
}
V_89 = V_90 [ 0 ] ;
V_79 = V_89 & 1 ;
V_89 = V_89 & ~ 1 ;
if ( ( V_89 != 0 ) && ( V_89 != V_96 )
&& ( V_89 != V_97 )
&& ( V_89 != V_98 ) )
{
F_12 ( V_103 , V_104 ) ;
return 0 ;
}
if ( ( V_89 == 0 || V_89 == V_97 ) && V_79 )
{
F_12 ( V_103 , V_104 ) ;
return 0 ;
}
if ( V_89 == 0 )
{
if ( V_91 != 1 )
{
F_12 ( V_103 , V_104 ) ;
return 0 ;
}
return F_44 ( V_34 , V_57 ) ;
}
V_93 = F_41 ( & V_34 -> V_35 ) ;
V_102 = ( V_89 == V_96 ) ? 1 + V_93 : 1 + 2 * V_93 ;
if ( V_91 != V_102 )
{
F_12 ( V_103 , V_104 ) ;
return 0 ;
}
if ( V_45 == NULL )
{
V_45 = V_46 = F_13 () ;
if ( V_45 == NULL )
return 0 ;
}
F_14 ( V_45 ) ;
V_62 = F_15 ( V_45 ) ;
V_63 = F_15 ( V_45 ) ;
if ( V_63 == NULL ) goto V_50;
if ( ! F_45 ( V_90 + 1 , V_93 , V_62 ) ) goto V_50;
if ( F_46 ( V_62 , & V_34 -> V_35 ) >= 0 )
{
F_12 ( V_103 , V_104 ) ;
goto V_50;
}
if ( V_89 == V_96 )
{
if ( ! F_47 ( V_34 , V_57 , V_62 , V_79 , V_45 ) ) goto V_50;
}
else
{
if ( ! F_45 ( V_90 + 1 + V_93 , V_93 , V_63 ) ) goto V_50;
if ( F_46 ( V_63 , & V_34 -> V_35 ) >= 0 )
{
F_12 ( V_103 , V_104 ) ;
goto V_50;
}
if ( V_89 == V_98 )
{
if ( V_79 != F_11 ( V_63 ) )
{
F_12 ( V_103 , V_104 ) ;
goto V_50;
}
}
if ( ! F_40 ( V_34 , V_57 , V_62 , V_63 , V_45 ) ) goto V_50;
}
if ( ! F_48 ( V_34 , V_57 , V_45 ) )
{
F_12 ( V_103 , V_105 ) ;
goto V_50;
}
V_1 = 1 ;
V_50:
F_19 ( V_45 ) ;
if ( V_46 != NULL )
F_20 ( V_46 ) ;
return V_1 ;
}
int V_24 ( const T_2 * V_34 , T_5 * V_106 , const T_5 * V_36 , const T_5 * V_37 , T_4 * V_45 )
{
int (* V_77)( const T_2 * , T_3 * , const T_3 * , const T_3 * , T_4 * );
int (* V_76)( const T_2 * , T_3 * , const T_3 * , T_4 * );
const T_3 * V_44 ;
T_4 * V_46 = NULL ;
T_3 * V_107 , * V_108 , * V_109 , * V_110 , * V_111 , * V_112 , * V_113 ;
int V_1 = 0 ;
if ( V_36 == V_37 )
return F_49 ( V_34 , V_106 , V_36 , V_45 ) ;
if ( F_26 ( V_34 , V_36 ) )
return F_9 ( V_106 , V_37 ) ;
if ( F_26 ( V_34 , V_37 ) )
return F_9 ( V_106 , V_36 ) ;
V_77 = V_34 -> V_52 -> V_77 ;
V_76 = V_34 -> V_52 -> V_76 ;
V_44 = & V_34 -> V_35 ;
if ( V_45 == NULL )
{
V_45 = V_46 = F_13 () ;
if ( V_45 == NULL )
return 0 ;
}
F_14 ( V_45 ) ;
V_107 = F_15 ( V_45 ) ;
V_108 = F_15 ( V_45 ) ;
V_109 = F_15 ( V_45 ) ;
V_110 = F_15 ( V_45 ) ;
V_111 = F_15 ( V_45 ) ;
V_112 = F_15 ( V_45 ) ;
V_113 = F_15 ( V_45 ) ;
if ( V_113 == NULL ) goto V_114;
if ( V_37 -> V_61 )
{
if ( ! F_7 ( V_108 , & V_36 -> V_58 ) ) goto V_114;
if ( ! F_7 ( V_109 , & V_36 -> V_59 ) ) goto V_114;
}
else
{
if ( ! V_76 ( V_34 , V_107 , & V_37 -> V_60 , V_45 ) ) goto V_114;
if ( ! V_77 ( V_34 , V_108 , & V_36 -> V_58 , V_107 , V_45 ) ) goto V_114;
if ( ! V_77 ( V_34 , V_107 , V_107 , & V_37 -> V_60 , V_45 ) ) goto V_114;
if ( ! V_77 ( V_34 , V_109 , & V_36 -> V_59 , V_107 , V_45 ) ) goto V_114;
}
if ( V_36 -> V_61 )
{
if ( ! F_7 ( V_110 , & V_37 -> V_58 ) ) goto V_114;
if ( ! F_7 ( V_111 , & V_37 -> V_59 ) ) goto V_114;
}
else
{
if ( ! V_76 ( V_34 , V_107 , & V_36 -> V_60 , V_45 ) ) goto V_114;
if ( ! V_77 ( V_34 , V_110 , & V_37 -> V_58 , V_107 , V_45 ) ) goto V_114;
if ( ! V_77 ( V_34 , V_107 , V_107 , & V_36 -> V_60 , V_45 ) ) goto V_114;
if ( ! V_77 ( V_34 , V_111 , & V_37 -> V_59 , V_107 , V_45 ) ) goto V_114;
}
if ( ! F_32 ( V_112 , V_108 , V_110 , V_44 ) ) goto V_114;
if ( ! F_32 ( V_113 , V_109 , V_111 , V_44 ) ) goto V_114;
if ( F_22 ( V_112 ) )
{
if ( F_22 ( V_113 ) )
{
F_19 ( V_45 ) ;
V_1 = F_49 ( V_34 , V_106 , V_36 , V_45 ) ;
V_45 = NULL ;
goto V_114;
}
else
{
if ( ! F_21 ( & V_106 -> V_60 ) ) goto V_114;
V_106 -> V_61 = 0 ;
V_1 = 1 ;
goto V_114;
}
}
if ( ! F_31 ( V_108 , V_108 , V_110 , V_44 ) ) goto V_114;
if ( ! F_31 ( V_109 , V_109 , V_111 , V_44 ) ) goto V_114;
if ( V_36 -> V_61 && V_37 -> V_61 )
{
if ( ! F_7 ( & V_106 -> V_60 , V_112 ) ) goto V_114;
}
else
{
if ( V_36 -> V_61 )
{ if ( ! F_7 ( V_107 , & V_37 -> V_60 ) ) goto V_114; }
else if ( V_37 -> V_61 )
{ if ( ! F_7 ( V_107 , & V_36 -> V_60 ) ) goto V_114; }
else
{ if ( ! V_77 ( V_34 , V_107 , & V_36 -> V_60 , & V_37 -> V_60 , V_45 ) ) goto V_114; }
if ( ! V_77 ( V_34 , & V_106 -> V_60 , V_107 , V_112 , V_45 ) ) goto V_114;
}
V_106 -> V_61 = 0 ;
if ( ! V_76 ( V_34 , V_107 , V_113 , V_45 ) ) goto V_114;
if ( ! V_76 ( V_34 , V_111 , V_112 , V_45 ) ) goto V_114;
if ( ! V_77 ( V_34 , V_110 , V_108 , V_111 , V_45 ) ) goto V_114;
if ( ! F_32 ( & V_106 -> V_58 , V_107 , V_110 , V_44 ) ) goto V_114;
if ( ! F_30 ( V_107 , & V_106 -> V_58 , V_44 ) ) goto V_114;
if ( ! F_32 ( V_107 , V_110 , V_107 , V_44 ) ) goto V_114;
if ( ! V_77 ( V_34 , V_107 , V_107 , V_113 , V_45 ) ) goto V_114;
if ( ! V_77 ( V_34 , V_112 , V_111 , V_112 , V_45 ) ) goto V_114;
if ( ! V_77 ( V_34 , V_108 , V_109 , V_112 , V_45 ) ) goto V_114;
if ( ! F_32 ( V_107 , V_107 , V_108 , V_44 ) ) goto V_114;
if ( F_11 ( V_107 ) )
if ( ! F_50 ( V_107 , V_107 , V_44 ) ) goto V_114;
if ( ! F_51 ( & V_106 -> V_59 , V_107 ) ) goto V_114;
V_1 = 1 ;
V_114:
if ( V_45 )
F_19 ( V_45 ) ;
if ( V_46 != NULL )
F_20 ( V_46 ) ;
return V_1 ;
}
int V_25 ( const T_2 * V_34 , T_5 * V_106 , const T_5 * V_36 , T_4 * V_45 )
{
int (* V_77)( const T_2 * , T_3 * , const T_3 * , const T_3 * , T_4 * );
int (* V_76)( const T_2 * , T_3 * , const T_3 * , T_4 * );
const T_3 * V_44 ;
T_4 * V_46 = NULL ;
T_3 * V_107 , * V_108 , * V_109 , * V_110 ;
int V_1 = 0 ;
if ( F_26 ( V_34 , V_36 ) )
{
if ( ! F_21 ( & V_106 -> V_60 ) ) return 0 ;
V_106 -> V_61 = 0 ;
return 1 ;
}
V_77 = V_34 -> V_52 -> V_77 ;
V_76 = V_34 -> V_52 -> V_76 ;
V_44 = & V_34 -> V_35 ;
if ( V_45 == NULL )
{
V_45 = V_46 = F_13 () ;
if ( V_45 == NULL )
return 0 ;
}
F_14 ( V_45 ) ;
V_107 = F_15 ( V_45 ) ;
V_108 = F_15 ( V_45 ) ;
V_109 = F_15 ( V_45 ) ;
V_110 = F_15 ( V_45 ) ;
if ( V_110 == NULL ) goto V_50;
if ( V_36 -> V_61 )
{
if ( ! V_76 ( V_34 , V_107 , & V_36 -> V_58 , V_45 ) ) goto V_50;
if ( ! F_30 ( V_108 , V_107 , V_44 ) ) goto V_50;
if ( ! F_31 ( V_107 , V_107 , V_108 , V_44 ) ) goto V_50;
if ( ! F_31 ( V_108 , V_107 , & V_34 -> V_36 , V_44 ) ) goto V_50;
}
else if ( V_34 -> V_38 )
{
if ( ! V_76 ( V_34 , V_108 , & V_36 -> V_60 , V_45 ) ) goto V_50;
if ( ! F_31 ( V_107 , & V_36 -> V_58 , V_108 , V_44 ) ) goto V_50;
if ( ! F_32 ( V_109 , & V_36 -> V_58 , V_108 , V_44 ) ) goto V_50;
if ( ! V_77 ( V_34 , V_108 , V_107 , V_109 , V_45 ) ) goto V_50;
if ( ! F_30 ( V_107 , V_108 , V_44 ) ) goto V_50;
if ( ! F_31 ( V_108 , V_107 , V_108 , V_44 ) ) goto V_50;
}
else
{
if ( ! V_76 ( V_34 , V_107 , & V_36 -> V_58 , V_45 ) ) goto V_50;
if ( ! F_30 ( V_108 , V_107 , V_44 ) ) goto V_50;
if ( ! F_31 ( V_107 , V_107 , V_108 , V_44 ) ) goto V_50;
if ( ! V_76 ( V_34 , V_108 , & V_36 -> V_60 , V_45 ) ) goto V_50;
if ( ! V_76 ( V_34 , V_108 , V_108 , V_45 ) ) goto V_50;
if ( ! V_77 ( V_34 , V_108 , V_108 , & V_34 -> V_36 , V_45 ) ) goto V_50;
if ( ! F_31 ( V_108 , V_108 , V_107 , V_44 ) ) goto V_50;
}
if ( V_36 -> V_61 )
{
if ( ! F_7 ( V_107 , & V_36 -> V_59 ) ) goto V_50;
}
else
{
if ( ! V_77 ( V_34 , V_107 , & V_36 -> V_59 , & V_36 -> V_60 , V_45 ) ) goto V_50;
}
if ( ! F_30 ( & V_106 -> V_60 , V_107 , V_44 ) ) goto V_50;
V_106 -> V_61 = 0 ;
if ( ! V_76 ( V_34 , V_110 , & V_36 -> V_59 , V_45 ) ) goto V_50;
if ( ! V_77 ( V_34 , V_109 , & V_36 -> V_58 , V_110 , V_45 ) ) goto V_50;
if ( ! F_52 ( V_109 , V_109 , 2 , V_44 ) ) goto V_50;
if ( ! F_30 ( V_107 , V_109 , V_44 ) ) goto V_50;
if ( ! V_76 ( V_34 , & V_106 -> V_58 , V_108 , V_45 ) ) goto V_50;
if ( ! F_32 ( & V_106 -> V_58 , & V_106 -> V_58 , V_107 , V_44 ) ) goto V_50;
if ( ! V_76 ( V_34 , V_107 , V_110 , V_45 ) ) goto V_50;
if ( ! F_52 ( V_110 , V_107 , 3 , V_44 ) ) goto V_50;
if ( ! F_32 ( V_107 , V_109 , & V_106 -> V_58 , V_44 ) ) goto V_50;
if ( ! V_77 ( V_34 , V_107 , V_108 , V_107 , V_45 ) ) goto V_50;
if ( ! F_32 ( & V_106 -> V_59 , V_107 , V_110 , V_44 ) ) goto V_50;
V_1 = 1 ;
V_50:
F_19 ( V_45 ) ;
if ( V_46 != NULL )
F_20 ( V_46 ) ;
return V_1 ;
}
int V_26 ( const T_2 * V_34 , T_5 * V_57 , T_4 * V_45 )
{
if ( F_26 ( V_34 , V_57 ) || F_22 ( & V_57 -> V_59 ) )
return 1 ;
return F_39 ( & V_57 -> V_59 , & V_34 -> V_35 , & V_57 -> V_59 ) ;
}
int V_27 ( const T_2 * V_34 , const T_5 * V_57 )
{
return F_22 ( & V_57 -> V_60 ) ;
}
int V_28 ( const T_2 * V_34 , const T_5 * V_57 , T_4 * V_45 )
{
int (* V_77)( const T_2 * , T_3 * , const T_3 * , const T_3 * , T_4 * );
int (* V_76)( const T_2 * , T_3 * , const T_3 * , T_4 * );
const T_3 * V_44 ;
T_4 * V_46 = NULL ;
T_3 * V_115 , * V_80 , * V_81 , * V_116 , * V_117 ;
int V_1 = - 1 ;
if ( F_26 ( V_34 , V_57 ) )
return 1 ;
V_77 = V_34 -> V_52 -> V_77 ;
V_76 = V_34 -> V_52 -> V_76 ;
V_44 = & V_34 -> V_35 ;
if ( V_45 == NULL )
{
V_45 = V_46 = F_13 () ;
if ( V_45 == NULL )
return - 1 ;
}
F_14 ( V_45 ) ;
V_115 = F_15 ( V_45 ) ;
V_80 = F_15 ( V_45 ) ;
V_81 = F_15 ( V_45 ) ;
V_116 = F_15 ( V_45 ) ;
V_117 = F_15 ( V_45 ) ;
if ( V_117 == NULL ) goto V_50;
if ( ! V_76 ( V_34 , V_115 , & V_57 -> V_58 , V_45 ) ) goto V_50;
if ( ! V_77 ( V_34 , V_115 , V_115 , & V_57 -> V_58 , V_45 ) ) goto V_50;
if ( ! V_57 -> V_61 )
{
if ( ! V_76 ( V_34 , V_80 , & V_57 -> V_60 , V_45 ) ) goto V_50;
if ( ! V_76 ( V_34 , V_116 , V_80 , V_45 ) ) goto V_50;
if ( ! V_77 ( V_34 , V_117 , V_116 , V_80 , V_45 ) ) goto V_50;
if ( ! V_77 ( V_34 , V_80 , & V_57 -> V_58 , V_116 , V_45 ) ) goto V_50;
if ( V_34 -> V_38 )
{
if ( ! F_30 ( V_81 , V_80 , V_44 ) ) goto V_50;
if ( ! F_31 ( V_81 , V_81 , V_80 , V_44 ) ) goto V_50;
if ( ! F_32 ( V_115 , V_115 , V_81 , V_44 ) ) goto V_50;
}
else
{
if ( ! V_77 ( V_34 , V_81 , V_80 , & V_34 -> V_36 , V_45 ) ) goto V_50;
if ( ! F_31 ( V_115 , V_115 , V_81 , V_44 ) ) goto V_50;
}
if ( ! V_77 ( V_34 , V_80 , & V_34 -> V_37 , V_117 , V_45 ) ) goto V_50;
if ( ! F_31 ( V_115 , V_115 , V_80 , V_44 ) ) goto V_50;
}
else
{
if ( V_34 -> V_38 )
{
if ( ! F_30 ( V_81 , & V_57 -> V_58 , V_44 ) ) goto V_50;
if ( ! F_31 ( V_81 , V_81 , & V_57 -> V_58 , V_44 ) ) goto V_50;
if ( ! F_32 ( V_115 , V_115 , V_81 , V_44 ) ) goto V_50;
}
else
{
if ( ! V_77 ( V_34 , V_81 , & V_57 -> V_58 , & V_34 -> V_36 , V_45 ) ) goto V_50;
if ( ! F_31 ( V_115 , V_115 , V_81 , V_44 ) ) goto V_50;
}
if ( ! F_31 ( V_115 , V_115 , & V_34 -> V_37 , V_44 ) ) goto V_50;
}
if ( ! V_76 ( V_34 , V_80 , & V_57 -> V_59 , V_45 ) ) goto V_50;
V_1 = ( 0 == F_18 ( V_80 , V_115 ) ) ;
V_50:
F_19 ( V_45 ) ;
if ( V_46 != NULL )
F_20 ( V_46 ) ;
return V_1 ;
}
int V_29 ( const T_2 * V_34 , const T_5 * V_36 , const T_5 * V_37 , T_4 * V_45 )
{
int (* V_77)( const T_2 * , T_3 * , const T_3 * , const T_3 * , T_4 * );
int (* V_76)( const T_2 * , T_3 * , const T_3 * , T_4 * );
T_4 * V_46 = NULL ;
T_3 * V_80 , * V_81 , * V_118 , * V_119 ;
const T_3 * V_120 , * V_121 ;
int V_1 = - 1 ;
if ( F_26 ( V_34 , V_36 ) )
{
return F_26 ( V_34 , V_37 ) ? 0 : 1 ;
}
if ( V_36 -> V_61 && V_37 -> V_61 )
{
return ( ( F_18 ( & V_36 -> V_58 , & V_37 -> V_58 ) == 0 ) && F_18 ( & V_36 -> V_59 , & V_37 -> V_59 ) == 0 ) ? 0 : 1 ;
}
V_77 = V_34 -> V_52 -> V_77 ;
V_76 = V_34 -> V_52 -> V_76 ;
if ( V_45 == NULL )
{
V_45 = V_46 = F_13 () ;
if ( V_45 == NULL )
return - 1 ;
}
F_14 ( V_45 ) ;
V_80 = F_15 ( V_45 ) ;
V_81 = F_15 ( V_45 ) ;
V_118 = F_15 ( V_45 ) ;
V_119 = F_15 ( V_45 ) ;
if ( V_119 == NULL ) goto V_114;
if ( ! V_37 -> V_61 )
{
if ( ! V_76 ( V_34 , V_119 , & V_37 -> V_60 , V_45 ) ) goto V_114;
if ( ! V_77 ( V_34 , V_80 , & V_36 -> V_58 , V_119 , V_45 ) ) goto V_114;
V_120 = V_80 ;
}
else
V_120 = & V_36 -> V_58 ;
if ( ! V_36 -> V_61 )
{
if ( ! V_76 ( V_34 , V_118 , & V_36 -> V_60 , V_45 ) ) goto V_114;
if ( ! V_77 ( V_34 , V_81 , & V_37 -> V_58 , V_118 , V_45 ) ) goto V_114;
V_121 = V_81 ;
}
else
V_121 = & V_37 -> V_58 ;
if ( F_18 ( V_120 , V_121 ) != 0 )
{
V_1 = 1 ;
goto V_114;
}
if ( ! V_37 -> V_61 )
{
if ( ! V_77 ( V_34 , V_119 , V_119 , & V_37 -> V_60 , V_45 ) ) goto V_114;
if ( ! V_77 ( V_34 , V_80 , & V_36 -> V_59 , V_119 , V_45 ) ) goto V_114;
}
else
V_120 = & V_36 -> V_59 ;
if ( ! V_36 -> V_61 )
{
if ( ! V_77 ( V_34 , V_118 , V_118 , & V_36 -> V_60 , V_45 ) ) goto V_114;
if ( ! V_77 ( V_34 , V_81 , & V_37 -> V_59 , V_118 , V_45 ) ) goto V_114;
}
else
V_121 = & V_37 -> V_59 ;
if ( F_18 ( V_120 , V_121 ) != 0 )
{
V_1 = 1 ;
goto V_114;
}
V_1 = 0 ;
V_114:
F_19 ( V_45 ) ;
if ( V_46 != NULL )
F_20 ( V_46 ) ;
return V_1 ;
}
int V_30 ( const T_2 * V_34 , T_5 * V_57 , T_4 * V_45 )
{
T_4 * V_46 = NULL ;
T_3 * V_62 , * V_63 ;
int V_1 = 0 ;
if ( V_57 -> V_61 || F_26 ( V_34 , V_57 ) )
return 1 ;
if ( V_45 == NULL )
{
V_45 = V_46 = F_13 () ;
if ( V_45 == NULL )
return 0 ;
}
F_14 ( V_45 ) ;
V_62 = F_15 ( V_45 ) ;
V_63 = F_15 ( V_45 ) ;
if ( V_63 == NULL ) goto V_50;
if ( ! F_42 ( V_34 , V_57 , V_62 , V_63 , V_45 ) ) goto V_50;
if ( ! F_40 ( V_34 , V_57 , V_62 , V_63 , V_45 ) ) goto V_50;
if ( ! V_57 -> V_61 )
{
F_12 ( V_122 , V_88 ) ;
goto V_50;
}
V_1 = 1 ;
V_50:
F_19 ( V_45 ) ;
if ( V_46 != NULL )
F_20 ( V_46 ) ;
return V_1 ;
}
int V_31 ( const T_2 * V_34 , T_6 V_123 , T_5 * V_124 [] , T_4 * V_45 )
{
T_4 * V_46 = NULL ;
T_3 * V_125 , * V_80 ;
T_6 V_126 = 0 ;
T_3 * * V_127 = NULL ;
T_6 V_94 ;
int V_1 = 0 ;
if ( V_123 == 0 )
return 1 ;
if ( V_45 == NULL )
{
V_45 = V_46 = F_13 () ;
if ( V_45 == NULL )
return 0 ;
}
F_14 ( V_45 ) ;
V_125 = F_15 ( V_45 ) ;
V_80 = F_15 ( V_45 ) ;
if ( V_125 == NULL || V_80 == NULL ) goto V_50;
V_126 = 1 ;
while ( V_123 > V_126 )
V_126 <<= 1 ;
V_126 <<= 1 ;
V_127 = F_53 ( V_126 * sizeof V_127 [ 0 ] ) ;
if ( V_127 == NULL ) goto V_50;
V_127 [ 0 ] = NULL ;
for ( V_94 = V_126 / 2 - 1 ; V_94 > 0 ; V_94 -- )
V_127 [ V_94 ] = NULL ;
for ( V_94 = 0 ; V_94 < V_123 ; V_94 ++ )
V_127 [ V_126 / 2 + V_94 ] = & V_124 [ V_94 ] -> V_60 ;
for ( V_94 = V_126 / 2 + V_123 ; V_94 < V_126 ; V_94 ++ )
V_127 [ V_94 ] = NULL ;
for ( V_94 = V_126 / 2 - 1 ; V_94 > 0 ; V_94 -- )
{
V_127 [ V_94 ] = F_54 () ;
if ( V_127 [ V_94 ] == NULL ) goto V_50;
if ( V_127 [ 2 * V_94 ] != NULL )
{
if ( ( V_127 [ 2 * V_94 + 1 ] == NULL ) || F_22 ( V_127 [ 2 * V_94 + 1 ] ) )
{
if ( ! F_7 ( V_127 [ V_94 ] , V_127 [ 2 * V_94 ] ) ) goto V_50;
}
else
{
if ( F_22 ( V_127 [ 2 * V_94 ] ) )
{
if ( ! F_7 ( V_127 [ V_94 ] , V_127 [ 2 * V_94 + 1 ] ) ) goto V_50;
}
else
{
if ( ! V_34 -> V_52 -> V_77 ( V_34 , V_127 [ V_94 ] ,
V_127 [ 2 * V_94 ] , V_127 [ 2 * V_94 + 1 ] , V_45 ) ) goto V_50;
}
}
}
}
if ( ! F_22 ( V_127 [ 1 ] ) )
{
if ( ! F_27 ( V_127 [ 1 ] , V_127 [ 1 ] , & V_34 -> V_35 , V_45 ) )
{
F_12 ( V_128 , V_75 ) ;
goto V_50;
}
}
if ( V_34 -> V_52 -> V_53 != 0 )
{
if ( ! V_34 -> V_52 -> V_53 ( V_34 , V_127 [ 1 ] , V_127 [ 1 ] , V_45 ) ) goto V_50;
if ( ! V_34 -> V_52 -> V_53 ( V_34 , V_127 [ 1 ] , V_127 [ 1 ] , V_45 ) ) goto V_50;
}
for ( V_94 = 2 ; V_94 < V_126 / 2 + V_123 ; V_94 += 2 )
{
if ( ( V_127 [ V_94 + 1 ] != NULL ) && ! F_22 ( V_127 [ V_94 + 1 ] ) )
{
if ( ! V_34 -> V_52 -> V_77 ( V_34 , V_125 , V_127 [ V_94 / 2 ] , V_127 [ V_94 + 1 ] , V_45 ) ) goto V_50;
if ( ! V_34 -> V_52 -> V_77 ( V_34 , V_80 , V_127 [ V_94 / 2 ] , V_127 [ V_94 ] , V_45 ) ) goto V_50;
if ( ! F_7 ( V_127 [ V_94 ] , V_125 ) ) goto V_50;
if ( ! F_7 ( V_127 [ V_94 + 1 ] , V_80 ) ) goto V_50;
}
else
{
if ( ! F_7 ( V_127 [ V_94 ] , V_127 [ V_94 / 2 ] ) ) goto V_50;
}
}
for ( V_94 = 0 ; V_94 < V_123 ; V_94 ++ )
{
T_5 * V_44 = V_124 [ V_94 ] ;
if ( ! F_22 ( & V_44 -> V_60 ) )
{
if ( ! V_34 -> V_52 -> V_76 ( V_34 , V_80 , & V_44 -> V_60 , V_45 ) ) goto V_50;
if ( ! V_34 -> V_52 -> V_77 ( V_34 , & V_44 -> V_58 , & V_44 -> V_58 , V_80 , V_45 ) ) goto V_50;
if ( ! V_34 -> V_52 -> V_77 ( V_34 , V_80 , V_80 , & V_44 -> V_60 , V_45 ) ) goto V_50;
if ( ! V_34 -> V_52 -> V_77 ( V_34 , & V_44 -> V_59 , & V_44 -> V_59 , V_80 , V_45 ) ) goto V_50;
if ( V_34 -> V_52 -> V_65 != 0 )
{
if ( ! V_34 -> V_52 -> V_65 ( V_34 , & V_44 -> V_60 , V_45 ) ) goto V_50;
}
else
{
if ( ! F_55 ( & V_44 -> V_60 ) ) goto V_50;
}
V_44 -> V_61 = 1 ;
}
}
V_1 = 1 ;
V_50:
F_19 ( V_45 ) ;
if ( V_46 != NULL )
F_20 ( V_46 ) ;
if ( V_127 != NULL )
{
for ( V_94 = V_126 / 2 - 1 ; V_94 > 0 ; V_94 -- )
{
if ( V_127 [ V_94 ] != NULL )
F_5 ( V_127 [ V_94 ] ) ;
}
F_56 ( V_127 ) ;
}
return V_1 ;
}
int V_32 ( const T_2 * V_34 , T_3 * V_106 , const T_3 * V_36 , const T_3 * V_37 , T_4 * V_45 )
{
return F_29 ( V_106 , V_36 , V_37 , & V_34 -> V_35 , V_45 ) ;
}
int V_33 ( const T_2 * V_34 , T_3 * V_106 , const T_3 * V_36 , T_4 * V_45 )
{
return F_28 ( V_106 , V_36 , & V_34 -> V_35 , V_45 ) ;
}
