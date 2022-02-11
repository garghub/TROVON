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
0 ,
0 ,
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
V_34 ,
0 ,
0 ,
0 } ;
return & V_1 ;
}
int V_3 ( T_2 * V_35 )
{
F_2 ( & V_35 -> V_36 ) ;
F_2 ( & V_35 -> V_37 ) ;
F_2 ( & V_35 -> V_38 ) ;
return 1 ;
}
void V_4 ( T_2 * V_35 )
{
F_3 ( & V_35 -> V_36 ) ;
F_3 ( & V_35 -> V_37 ) ;
F_3 ( & V_35 -> V_38 ) ;
}
void V_5 ( T_2 * V_35 )
{
F_4 ( & V_35 -> V_36 ) ;
F_4 ( & V_35 -> V_37 ) ;
F_4 ( & V_35 -> V_38 ) ;
V_35 -> V_39 [ 0 ] = 0 ;
V_35 -> V_39 [ 1 ] = 0 ;
V_35 -> V_39 [ 2 ] = 0 ;
V_35 -> V_39 [ 3 ] = 0 ;
V_35 -> V_39 [ 4 ] = 0 ;
V_35 -> V_39 [ 5 ] = - 1 ;
}
int V_6 ( T_2 * V_40 , const T_2 * V_41 )
{
int V_42 ;
if ( ! F_5 ( & V_40 -> V_36 , & V_41 -> V_36 ) ) return 0 ;
if ( ! F_5 ( & V_40 -> V_37 , & V_41 -> V_37 ) ) return 0 ;
if ( ! F_5 ( & V_40 -> V_38 , & V_41 -> V_38 ) ) return 0 ;
V_40 -> V_39 [ 0 ] = V_41 -> V_39 [ 0 ] ;
V_40 -> V_39 [ 1 ] = V_41 -> V_39 [ 1 ] ;
V_40 -> V_39 [ 2 ] = V_41 -> V_39 [ 2 ] ;
V_40 -> V_39 [ 3 ] = V_41 -> V_39 [ 3 ] ;
V_40 -> V_39 [ 4 ] = V_41 -> V_39 [ 4 ] ;
V_40 -> V_39 [ 5 ] = V_41 -> V_39 [ 5 ] ;
if ( F_6 ( & V_40 -> V_37 , ( int ) ( V_40 -> V_39 [ 0 ] + V_43 - 1 ) / V_43 ) == NULL ) return 0 ;
if ( F_6 ( & V_40 -> V_38 , ( int ) ( V_40 -> V_39 [ 0 ] + V_43 - 1 ) / V_43 ) == NULL ) return 0 ;
for ( V_42 = V_40 -> V_37 . V_44 ; V_42 < V_40 -> V_37 . V_45 ; V_42 ++ ) V_40 -> V_37 . V_46 [ V_42 ] = 0 ;
for ( V_42 = V_40 -> V_38 . V_44 ; V_42 < V_40 -> V_38 . V_45 ; V_42 ++ ) V_40 -> V_38 . V_46 [ V_42 ] = 0 ;
return 1 ;
}
int V_7 ( T_2 * V_35 ,
const T_3 * V_47 , const T_3 * V_37 , const T_3 * V_38 , T_4 * V_48 )
{
int V_1 = 0 , V_42 ;
if ( ! F_5 ( & V_35 -> V_36 , V_47 ) ) goto V_49;
V_42 = F_7 ( & V_35 -> V_36 , V_35 -> V_39 , 6 ) - 1 ;
if ( ( V_42 != 5 ) && ( V_42 != 3 ) )
{
F_8 ( V_50 , V_51 ) ;
goto V_49;
}
if ( ! F_9 ( & V_35 -> V_37 , V_37 , V_35 -> V_39 ) ) goto V_49;
if( F_6 ( & V_35 -> V_37 , ( int ) ( V_35 -> V_39 [ 0 ] + V_43 - 1 ) / V_43 ) == NULL ) goto V_49;
for ( V_42 = V_35 -> V_37 . V_44 ; V_42 < V_35 -> V_37 . V_45 ; V_42 ++ ) V_35 -> V_37 . V_46 [ V_42 ] = 0 ;
if ( ! F_9 ( & V_35 -> V_38 , V_38 , V_35 -> V_39 ) ) goto V_49;
if( F_6 ( & V_35 -> V_38 , ( int ) ( V_35 -> V_39 [ 0 ] + V_43 - 1 ) / V_43 ) == NULL ) goto V_49;
for ( V_42 = V_35 -> V_38 . V_44 ; V_42 < V_35 -> V_38 . V_45 ; V_42 ++ ) V_35 -> V_38 . V_46 [ V_42 ] = 0 ;
V_1 = 1 ;
V_49:
return V_1 ;
}
int V_8 ( const T_2 * V_35 , T_3 * V_47 , T_3 * V_37 , T_3 * V_38 , T_4 * V_48 )
{
int V_1 = 0 ;
if ( V_47 != NULL )
{
if ( ! F_5 ( V_47 , & V_35 -> V_36 ) ) return 0 ;
}
if ( V_37 != NULL )
{
if ( ! F_5 ( V_37 , & V_35 -> V_37 ) ) goto V_49;
}
if ( V_38 != NULL )
{
if ( ! F_5 ( V_38 , & V_35 -> V_38 ) ) goto V_49;
}
V_1 = 1 ;
V_49:
return V_1 ;
}
int V_9 ( const T_2 * V_35 )
{
return F_10 ( & V_35 -> V_36 ) - 1 ;
}
int V_10 ( const T_2 * V_35 , T_4 * V_48 )
{
int V_1 = 0 ;
T_3 * V_38 ;
T_4 * V_52 = NULL ;
if ( V_48 == NULL )
{
V_48 = V_52 = F_11 () ;
if ( V_48 == NULL )
{
F_8 ( V_53 , V_54 ) ;
goto V_49;
}
}
F_12 ( V_48 ) ;
V_38 = F_13 ( V_48 ) ;
if ( V_38 == NULL ) goto V_49;
if ( ! F_9 ( V_38 , & V_35 -> V_38 , V_35 -> V_39 ) ) goto V_49;
if ( F_14 ( V_38 ) ) goto V_49;
V_1 = 1 ;
V_49:
if ( V_48 != NULL )
F_15 ( V_48 ) ;
if ( V_52 != NULL )
F_16 ( V_52 ) ;
return V_1 ;
}
int V_11 ( T_5 * V_55 )
{
F_2 ( & V_55 -> V_56 ) ;
F_2 ( & V_55 -> V_57 ) ;
F_2 ( & V_55 -> V_58 ) ;
return 1 ;
}
void V_12 ( T_5 * V_55 )
{
F_3 ( & V_55 -> V_56 ) ;
F_3 ( & V_55 -> V_57 ) ;
F_3 ( & V_55 -> V_58 ) ;
}
void V_13 ( T_5 * V_55 )
{
F_4 ( & V_55 -> V_56 ) ;
F_4 ( & V_55 -> V_57 ) ;
F_4 ( & V_55 -> V_58 ) ;
V_55 -> V_59 = 0 ;
}
int V_14 ( T_5 * V_40 , const T_5 * V_41 )
{
if ( ! F_5 ( & V_40 -> V_56 , & V_41 -> V_56 ) ) return 0 ;
if ( ! F_5 ( & V_40 -> V_57 , & V_41 -> V_57 ) ) return 0 ;
if ( ! F_5 ( & V_40 -> V_58 , & V_41 -> V_58 ) ) return 0 ;
V_40 -> V_59 = V_41 -> V_59 ;
return 1 ;
}
int V_15 ( const T_2 * V_35 , T_5 * V_55 )
{
V_55 -> V_59 = 0 ;
F_17 ( & V_55 -> V_58 ) ;
return 1 ;
}
int V_16 ( const T_2 * V_35 , T_5 * V_55 ,
const T_3 * V_60 , const T_3 * V_61 , T_4 * V_48 )
{
int V_1 = 0 ;
if ( V_60 == NULL || V_61 == NULL )
{
F_8 ( V_62 , V_63 ) ;
return 0 ;
}
if ( ! F_5 ( & V_55 -> V_56 , V_60 ) ) goto V_49;
F_18 ( & V_55 -> V_56 , 0 ) ;
if ( ! F_5 ( & V_55 -> V_57 , V_61 ) ) goto V_49;
F_18 ( & V_55 -> V_57 , 0 ) ;
if ( ! F_5 ( & V_55 -> V_58 , F_19 () ) ) goto V_49;
F_18 ( & V_55 -> V_58 , 0 ) ;
V_55 -> V_59 = 1 ;
V_1 = 1 ;
V_49:
return V_1 ;
}
int V_17 ( const T_2 * V_35 , const T_5 * V_55 ,
T_3 * V_60 , T_3 * V_61 , T_4 * V_48 )
{
int V_1 = 0 ;
if ( F_20 ( V_35 , V_55 ) )
{
F_8 ( V_64 , V_65 ) ;
return 0 ;
}
if ( F_21 ( & V_55 -> V_58 , F_19 () ) )
{
F_8 ( V_64 , V_66 ) ;
return 0 ;
}
if ( V_60 != NULL )
{
if ( ! F_5 ( V_60 , & V_55 -> V_56 ) ) goto V_49;
F_18 ( V_60 , 0 ) ;
}
if ( V_61 != NULL )
{
if ( ! F_5 ( V_61 , & V_55 -> V_57 ) ) goto V_49;
F_18 ( V_61 , 0 ) ;
}
V_1 = 1 ;
V_49:
return V_1 ;
}
int V_18 ( const T_2 * V_35 , T_5 * V_55 ,
const T_3 * V_67 , int V_68 , T_4 * V_48 )
{
T_4 * V_52 = NULL ;
T_3 * V_69 , * V_60 , * V_61 , * V_70 ;
int V_1 = 0 , V_71 ;
F_22 () ;
if ( V_48 == NULL )
{
V_48 = V_52 = F_11 () ;
if ( V_48 == NULL )
return 0 ;
}
V_68 = ( V_68 != 0 ) ? 1 : 0 ;
F_12 ( V_48 ) ;
V_69 = F_13 ( V_48 ) ;
V_60 = F_13 ( V_48 ) ;
V_61 = F_13 ( V_48 ) ;
V_70 = F_13 ( V_48 ) ;
if ( V_70 == NULL ) goto V_49;
if ( ! F_9 ( V_60 , V_67 , V_35 -> V_39 ) ) goto V_49;
if ( F_14 ( V_60 ) )
{
if ( ! F_23 ( V_61 , & V_35 -> V_38 , V_35 -> V_39 , V_48 ) ) goto V_49;
}
else
{
if ( ! V_35 -> V_72 -> V_73 ( V_35 , V_69 , V_60 , V_48 ) ) goto V_49;
if ( ! V_35 -> V_72 -> V_74 ( V_35 , V_69 , & V_35 -> V_38 , V_69 , V_48 ) ) goto V_49;
if ( ! F_24 ( V_69 , & V_35 -> V_37 , V_69 ) ) goto V_49;
if ( ! F_24 ( V_69 , V_60 , V_69 ) ) goto V_49;
if ( ! F_25 ( V_70 , V_69 , V_35 -> V_39 , V_48 ) )
{
unsigned long V_49 = F_26 () ;
if ( F_27 ( V_49 ) == V_75 && F_28 ( V_49 ) == V_76 )
{
F_22 () ;
F_8 ( V_77 , V_78 ) ;
}
else
F_8 ( V_77 , V_79 ) ;
goto V_49;
}
V_71 = ( F_29 ( V_70 ) ) ? 1 : 0 ;
if ( ! V_35 -> V_72 -> V_80 ( V_35 , V_61 , V_60 , V_70 , V_48 ) ) goto V_49;
if ( V_71 != V_68 )
{
if ( ! F_24 ( V_61 , V_61 , V_60 ) ) goto V_49;
}
}
if ( ! F_30 ( V_35 , V_55 , V_60 , V_61 , V_48 ) ) goto V_49;
V_1 = 1 ;
V_49:
F_15 ( V_48 ) ;
if ( V_52 != NULL )
F_16 ( V_52 ) ;
return V_1 ;
}
T_6 V_19 ( const T_2 * V_35 , const T_5 * V_55 , T_7 V_81 ,
unsigned char * V_82 , T_6 V_83 , T_4 * V_48 )
{
T_6 V_1 ;
T_4 * V_52 = NULL ;
int V_84 = 0 ;
T_3 * V_60 , * V_61 , * V_85 ;
T_6 V_86 , V_42 , V_87 ;
if ( ( V_81 != V_88 )
&& ( V_81 != V_89 )
&& ( V_81 != V_90 ) )
{
F_8 ( V_91 , V_92 ) ;
goto V_49;
}
if ( F_20 ( V_35 , V_55 ) )
{
if ( V_82 != NULL )
{
if ( V_83 < 1 )
{
F_8 ( V_91 , V_93 ) ;
return 0 ;
}
V_82 [ 0 ] = 0 ;
}
return 1 ;
}
V_86 = ( F_31 ( V_35 ) + 7 ) / 8 ;
V_1 = ( V_81 == V_88 ) ? 1 + V_86 : 1 + 2 * V_86 ;
if ( V_82 != NULL )
{
if ( V_83 < V_1 )
{
F_8 ( V_91 , V_93 ) ;
goto V_49;
}
if ( V_48 == NULL )
{
V_48 = V_52 = F_11 () ;
if ( V_48 == NULL )
return 0 ;
}
F_12 ( V_48 ) ;
V_84 = 1 ;
V_60 = F_13 ( V_48 ) ;
V_61 = F_13 ( V_48 ) ;
V_85 = F_13 ( V_48 ) ;
if ( V_85 == NULL ) goto V_49;
if ( ! F_32 ( V_35 , V_55 , V_60 , V_61 , V_48 ) ) goto V_49;
V_82 [ 0 ] = V_81 ;
if ( ( V_81 != V_89 ) && ! F_14 ( V_60 ) )
{
if ( ! V_35 -> V_72 -> V_74 ( V_35 , V_85 , V_61 , V_60 , V_48 ) ) goto V_49;
if ( F_29 ( V_85 ) ) V_82 [ 0 ] ++ ;
}
V_42 = 1 ;
V_87 = V_86 - F_33 ( V_60 ) ;
if ( V_87 > V_86 )
{
F_8 ( V_91 , V_94 ) ;
goto V_49;
}
while ( V_87 > 0 )
{
V_82 [ V_42 ++ ] = 0 ;
V_87 -- ;
}
V_87 = F_34 ( V_60 , V_82 + V_42 ) ;
V_42 += V_87 ;
if ( V_42 != 1 + V_86 )
{
F_8 ( V_91 , V_94 ) ;
goto V_49;
}
if ( V_81 == V_89 || V_81 == V_90 )
{
V_87 = V_86 - F_33 ( V_61 ) ;
if ( V_87 > V_86 )
{
F_8 ( V_91 , V_94 ) ;
goto V_49;
}
while ( V_87 > 0 )
{
V_82 [ V_42 ++ ] = 0 ;
V_87 -- ;
}
V_87 = F_34 ( V_61 , V_82 + V_42 ) ;
V_42 += V_87 ;
}
if ( V_42 != V_1 )
{
F_8 ( V_91 , V_94 ) ;
goto V_49;
}
}
if ( V_84 )
F_15 ( V_48 ) ;
if ( V_52 != NULL )
F_16 ( V_52 ) ;
return V_1 ;
V_49:
if ( V_84 )
F_15 ( V_48 ) ;
if ( V_52 != NULL )
F_16 ( V_52 ) ;
return 0 ;
}
int V_20 ( const T_2 * V_35 , T_5 * V_55 ,
const unsigned char * V_82 , T_6 V_83 , T_4 * V_48 )
{
T_7 V_81 ;
int V_68 ;
T_4 * V_52 = NULL ;
T_3 * V_60 , * V_61 , * V_85 ;
T_6 V_86 , V_95 ;
int V_1 = 0 ;
if ( V_83 == 0 )
{
F_8 ( V_96 , V_93 ) ;
return 0 ;
}
V_81 = V_82 [ 0 ] ;
V_68 = V_81 & 1 ;
V_81 = V_81 & ~ 1U ;
if ( ( V_81 != 0 ) && ( V_81 != V_88 )
&& ( V_81 != V_89 )
&& ( V_81 != V_90 ) )
{
F_8 ( V_96 , V_97 ) ;
return 0 ;
}
if ( ( V_81 == 0 || V_81 == V_89 ) && V_68 )
{
F_8 ( V_96 , V_97 ) ;
return 0 ;
}
if ( V_81 == 0 )
{
if ( V_83 != 1 )
{
F_8 ( V_96 , V_97 ) ;
return 0 ;
}
return F_35 ( V_35 , V_55 ) ;
}
V_86 = ( F_31 ( V_35 ) + 7 ) / 8 ;
V_95 = ( V_81 == V_88 ) ? 1 + V_86 : 1 + 2 * V_86 ;
if ( V_83 != V_95 )
{
F_8 ( V_96 , V_97 ) ;
return 0 ;
}
if ( V_48 == NULL )
{
V_48 = V_52 = F_11 () ;
if ( V_48 == NULL )
return 0 ;
}
F_12 ( V_48 ) ;
V_60 = F_13 ( V_48 ) ;
V_61 = F_13 ( V_48 ) ;
V_85 = F_13 ( V_48 ) ;
if ( V_85 == NULL ) goto V_49;
if ( ! F_36 ( V_82 + 1 , V_86 , V_60 ) ) goto V_49;
if ( F_37 ( V_60 , & V_35 -> V_36 ) >= 0 )
{
F_8 ( V_96 , V_97 ) ;
goto V_49;
}
if ( V_81 == V_88 )
{
if ( ! F_38 ( V_35 , V_55 , V_60 , V_68 , V_48 ) ) goto V_49;
}
else
{
if ( ! F_36 ( V_82 + 1 + V_86 , V_86 , V_61 ) ) goto V_49;
if ( F_37 ( V_61 , & V_35 -> V_36 ) >= 0 )
{
F_8 ( V_96 , V_97 ) ;
goto V_49;
}
if ( V_81 == V_90 )
{
if ( ! V_35 -> V_72 -> V_74 ( V_35 , V_85 , V_61 , V_60 , V_48 ) ) goto V_49;
if ( V_68 != F_29 ( V_85 ) )
{
F_8 ( V_96 , V_97 ) ;
goto V_49;
}
}
if ( ! F_30 ( V_35 , V_55 , V_60 , V_61 , V_48 ) ) goto V_49;
}
if ( ! F_39 ( V_35 , V_55 , V_48 ) )
{
F_8 ( V_96 , V_98 ) ;
goto V_49;
}
V_1 = 1 ;
V_49:
F_15 ( V_48 ) ;
if ( V_52 != NULL )
F_16 ( V_52 ) ;
return V_1 ;
}
int V_21 ( const T_2 * V_35 , T_5 * V_99 , const T_5 * V_37 , const T_5 * V_38 , T_4 * V_48 )
{
T_4 * V_52 = NULL ;
T_3 * V_100 , * y0 , * V_101 , * y1 , * V_102 , * V_103 , * V_104 , * V_105 ;
int V_1 = 0 ;
if ( F_20 ( V_35 , V_37 ) )
{
if ( ! F_40 ( V_99 , V_38 ) ) return 0 ;
return 1 ;
}
if ( F_20 ( V_35 , V_38 ) )
{
if ( ! F_40 ( V_99 , V_37 ) ) return 0 ;
return 1 ;
}
if ( V_48 == NULL )
{
V_48 = V_52 = F_11 () ;
if ( V_48 == NULL )
return 0 ;
}
F_12 ( V_48 ) ;
V_100 = F_13 ( V_48 ) ;
y0 = F_13 ( V_48 ) ;
V_101 = F_13 ( V_48 ) ;
y1 = F_13 ( V_48 ) ;
V_102 = F_13 ( V_48 ) ;
V_103 = F_13 ( V_48 ) ;
V_104 = F_13 ( V_48 ) ;
V_105 = F_13 ( V_48 ) ;
if ( V_105 == NULL ) goto V_49;
if ( V_37 -> V_59 )
{
if ( ! F_5 ( V_100 , & V_37 -> V_56 ) ) goto V_49;
if ( ! F_5 ( y0 , & V_37 -> V_57 ) ) goto V_49;
}
else
{
if ( ! F_32 ( V_35 , V_37 , V_100 , y0 , V_48 ) ) goto V_49;
}
if ( V_38 -> V_59 )
{
if ( ! F_5 ( V_101 , & V_38 -> V_56 ) ) goto V_49;
if ( ! F_5 ( y1 , & V_38 -> V_57 ) ) goto V_49;
}
else
{
if ( ! F_32 ( V_35 , V_38 , V_101 , y1 , V_48 ) ) goto V_49;
}
if ( F_41 ( V_100 , V_101 ) )
{
if ( ! F_24 ( V_105 , V_100 , V_101 ) ) goto V_49;
if ( ! F_24 ( V_104 , y0 , y1 ) ) goto V_49;
if ( ! V_35 -> V_72 -> V_74 ( V_35 , V_104 , V_104 , V_105 , V_48 ) ) goto V_49;
if ( ! V_35 -> V_72 -> V_73 ( V_35 , V_102 , V_104 , V_48 ) ) goto V_49;
if ( ! F_24 ( V_102 , V_102 , & V_35 -> V_37 ) ) goto V_49;
if ( ! F_24 ( V_102 , V_102 , V_104 ) ) goto V_49;
if ( ! F_24 ( V_102 , V_102 , V_105 ) ) goto V_49;
}
else
{
if ( F_41 ( y0 , y1 ) || F_14 ( V_101 ) )
{
if ( ! F_35 ( V_35 , V_99 ) ) goto V_49;
V_1 = 1 ;
goto V_49;
}
if ( ! V_35 -> V_72 -> V_74 ( V_35 , V_104 , y1 , V_101 , V_48 ) ) goto V_49;
if ( ! F_24 ( V_104 , V_104 , V_101 ) ) goto V_49;
if ( ! V_35 -> V_72 -> V_73 ( V_35 , V_102 , V_104 , V_48 ) ) goto V_49;
if ( ! F_24 ( V_102 , V_102 , V_104 ) ) goto V_49;
if ( ! F_24 ( V_102 , V_102 , & V_35 -> V_37 ) ) goto V_49;
}
if ( ! F_24 ( V_103 , V_101 , V_102 ) ) goto V_49;
if ( ! V_35 -> V_72 -> V_80 ( V_35 , V_103 , V_103 , V_104 , V_48 ) ) goto V_49;
if ( ! F_24 ( V_103 , V_103 , V_102 ) ) goto V_49;
if ( ! F_24 ( V_103 , V_103 , y1 ) ) goto V_49;
if ( ! F_30 ( V_35 , V_99 , V_102 , V_103 , V_48 ) ) goto V_49;
V_1 = 1 ;
V_49:
F_15 ( V_48 ) ;
if ( V_52 != NULL )
F_16 ( V_52 ) ;
return V_1 ;
}
int V_22 ( const T_2 * V_35 , T_5 * V_99 , const T_5 * V_37 , T_4 * V_48 )
{
return V_21 ( V_35 , V_99 , V_37 , V_37 , V_48 ) ;
}
int V_23 ( const T_2 * V_35 , T_5 * V_55 , T_4 * V_48 )
{
if ( F_20 ( V_35 , V_55 ) || F_14 ( & V_55 -> V_57 ) )
return 1 ;
if ( ! F_42 ( V_35 , V_55 , V_48 ) ) return 0 ;
return F_24 ( & V_55 -> V_57 , & V_55 -> V_56 , & V_55 -> V_57 ) ;
}
int V_24 ( const T_2 * V_35 , const T_5 * V_55 )
{
return F_14 ( & V_55 -> V_58 ) ;
}
int V_25 ( const T_2 * V_35 , const T_5 * V_55 , T_4 * V_48 )
{
int V_1 = - 1 ;
T_4 * V_52 = NULL ;
T_3 * V_106 , * V_103 ;
int (* V_80)( const T_2 * , T_3 * , const T_3 * , const T_3 * , T_4 * );
int (* V_73)( const T_2 * , T_3 * , const T_3 * , T_4 * );
if ( F_20 ( V_35 , V_55 ) )
return 1 ;
V_80 = V_35 -> V_72 -> V_80 ;
V_73 = V_35 -> V_72 -> V_73 ;
if ( ! V_55 -> V_59 ) goto V_49;
if ( V_48 == NULL )
{
V_48 = V_52 = F_11 () ;
if ( V_48 == NULL )
return - 1 ;
}
F_12 ( V_48 ) ;
V_103 = F_13 ( V_48 ) ;
V_106 = F_13 ( V_48 ) ;
if ( V_106 == NULL ) goto V_49;
if ( ! F_24 ( V_106 , & V_55 -> V_56 , & V_35 -> V_37 ) ) goto V_49;
if ( ! V_80 ( V_35 , V_106 , V_106 , & V_55 -> V_56 , V_48 ) ) goto V_49;
if ( ! F_24 ( V_106 , V_106 , & V_55 -> V_57 ) ) goto V_49;
if ( ! V_80 ( V_35 , V_106 , V_106 , & V_55 -> V_56 , V_48 ) ) goto V_49;
if ( ! F_24 ( V_106 , V_106 , & V_35 -> V_38 ) ) goto V_49;
if ( ! V_73 ( V_35 , V_103 , & V_55 -> V_57 , V_48 ) ) goto V_49;
if ( ! F_24 ( V_106 , V_106 , V_103 ) ) goto V_49;
V_1 = F_14 ( V_106 ) ;
V_49:
if ( V_48 ) F_15 ( V_48 ) ;
if ( V_52 ) F_16 ( V_52 ) ;
return V_1 ;
}
int V_26 ( const T_2 * V_35 , const T_5 * V_37 , const T_5 * V_38 , T_4 * V_48 )
{
T_3 * V_107 , * V_108 , * V_109 , * V_110 ;
T_4 * V_52 = NULL ;
int V_1 = - 1 ;
if ( F_20 ( V_35 , V_37 ) )
{
return F_20 ( V_35 , V_38 ) ? 0 : 1 ;
}
if ( V_37 -> V_59 && V_38 -> V_59 )
{
return ( ( F_21 ( & V_37 -> V_56 , & V_38 -> V_56 ) == 0 ) && F_21 ( & V_37 -> V_57 , & V_38 -> V_57 ) == 0 ) ? 0 : 1 ;
}
if ( V_48 == NULL )
{
V_48 = V_52 = F_11 () ;
if ( V_48 == NULL )
return - 1 ;
}
F_12 ( V_48 ) ;
V_107 = F_13 ( V_48 ) ;
V_108 = F_13 ( V_48 ) ;
V_109 = F_13 ( V_48 ) ;
V_110 = F_13 ( V_48 ) ;
if ( V_110 == NULL ) goto V_49;
if ( ! F_32 ( V_35 , V_37 , V_107 , V_108 , V_48 ) ) goto V_49;
if ( ! F_32 ( V_35 , V_38 , V_109 , V_110 , V_48 ) ) goto V_49;
V_1 = ( ( F_21 ( V_107 , V_109 ) == 0 ) && F_21 ( V_108 , V_110 ) == 0 ) ? 0 : 1 ;
V_49:
if ( V_48 ) F_15 ( V_48 ) ;
if ( V_52 ) F_16 ( V_52 ) ;
return V_1 ;
}
int V_27 ( const T_2 * V_35 , T_5 * V_55 , T_4 * V_48 )
{
T_4 * V_52 = NULL ;
T_3 * V_60 , * V_61 ;
int V_1 = 0 ;
if ( V_55 -> V_59 || F_20 ( V_35 , V_55 ) )
return 1 ;
if ( V_48 == NULL )
{
V_48 = V_52 = F_11 () ;
if ( V_48 == NULL )
return 0 ;
}
F_12 ( V_48 ) ;
V_60 = F_13 ( V_48 ) ;
V_61 = F_13 ( V_48 ) ;
if ( V_61 == NULL ) goto V_49;
if ( ! F_32 ( V_35 , V_55 , V_60 , V_61 , V_48 ) ) goto V_49;
if ( ! F_5 ( & V_55 -> V_56 , V_60 ) ) goto V_49;
if ( ! F_5 ( & V_55 -> V_57 , V_61 ) ) goto V_49;
if ( ! F_43 ( & V_55 -> V_58 ) ) goto V_49;
V_1 = 1 ;
V_49:
if ( V_48 ) F_15 ( V_48 ) ;
if ( V_52 ) F_16 ( V_52 ) ;
return V_1 ;
}
int V_28 ( const T_2 * V_35 , T_6 V_111 , T_5 * V_112 [] , T_4 * V_48 )
{
T_6 V_42 ;
for ( V_42 = 0 ; V_42 < V_111 ; V_42 ++ )
{
if ( ! V_35 -> V_72 -> V_113 ( V_35 , V_112 [ V_42 ] , V_48 ) ) return 0 ;
}
return 1 ;
}
int V_32 ( const T_2 * V_35 , T_3 * V_99 , const T_3 * V_37 , const T_3 * V_38 , T_4 * V_48 )
{
return F_44 ( V_99 , V_37 , V_38 , V_35 -> V_39 , V_48 ) ;
}
int V_33 ( const T_2 * V_35 , T_3 * V_99 , const T_3 * V_37 , T_4 * V_48 )
{
return F_45 ( V_99 , V_37 , V_35 -> V_39 , V_48 ) ;
}
int V_34 ( const T_2 * V_35 , T_3 * V_99 , const T_3 * V_37 , const T_3 * V_38 , T_4 * V_48 )
{
return F_46 ( V_99 , V_37 , V_38 , & V_35 -> V_36 , V_48 ) ;
}
