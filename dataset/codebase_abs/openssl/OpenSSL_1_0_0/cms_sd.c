static T_1 * F_1 ( T_2 * V_1 )
{
if ( F_2 ( V_1 -> V_2 ) != V_3 )
{
F_3 ( V_4 , V_5 ) ;
return NULL ;
}
return V_1 -> V_6 . V_7 ;
}
static T_1 * F_4 ( T_2 * V_1 )
{
if ( V_1 -> V_6 . V_8 == NULL )
{
V_1 -> V_6 . V_7 = F_5 ( T_1 ) ;
if ( ! V_1 -> V_6 . V_7 )
{
F_3 ( V_9 , V_10 ) ;
return NULL ;
}
V_1 -> V_6 . V_7 -> V_11 = 1 ;
V_1 -> V_6 . V_7 -> V_12 -> V_13 =
F_6 ( V_14 ) ;
V_1 -> V_6 . V_7 -> V_12 -> V_15 = 1 ;
F_7 ( V_1 -> V_2 ) ;
V_1 -> V_2 = F_6 ( V_3 ) ;
return V_1 -> V_6 . V_7 ;
}
return F_1 ( V_1 ) ;
}
int F_8 ( T_2 * V_1 )
{
if ( F_4 ( V_1 ) )
return 1 ;
else
return 0 ;
}
static void F_9 ( T_1 * V_16 )
{
int V_17 ;
T_3 * V_18 ;
T_4 * V_19 ;
T_5 * V_20 ;
for ( V_17 = 0 ; V_17 < F_10 ( V_16 -> V_21 ) ; V_17 ++ )
{
V_18 = F_11 ( V_16 -> V_21 , V_17 ) ;
if ( V_18 -> type == V_22 )
{
if ( V_16 -> V_11 < 5 )
V_16 -> V_11 = 5 ;
}
else if ( V_18 -> type == V_23 )
{
if ( V_16 -> V_11 < 4 )
V_16 -> V_11 = 4 ;
}
else if ( V_18 -> type == V_24 )
{
if ( V_16 -> V_11 < 3 )
V_16 -> V_11 = 3 ;
}
}
for ( V_17 = 0 ; V_17 < F_12 ( V_16 -> V_25 ) ; V_17 ++ )
{
V_19 = F_13 ( V_16 -> V_25 , V_17 ) ;
if ( V_19 -> type == V_26 )
{
if ( V_16 -> V_11 < 5 )
V_16 -> V_11 = 5 ;
}
}
if ( ( F_2 ( V_16 -> V_12 -> V_13 ) != V_14 )
&& ( V_16 -> V_11 < 3 ) )
V_16 -> V_11 = 3 ;
for ( V_17 = 0 ; V_17 < F_14 ( V_16 -> V_27 ) ; V_17 ++ )
{
V_20 = F_15 ( V_16 -> V_27 , V_17 ) ;
if ( V_20 -> V_28 -> type == V_29 )
{
if ( V_20 -> V_11 < 3 )
V_20 -> V_11 = 3 ;
if ( V_16 -> V_11 < 3 )
V_16 -> V_11 = 3 ;
}
else
V_16 -> V_11 = 1 ;
}
if ( V_16 -> V_11 < 1 )
V_16 -> V_11 = 1 ;
}
static int F_16 ( T_2 * V_1 , T_5 * V_20 )
{
F_17 ( T_5 ) * V_30 ;
T_5 * V_31 ;
int V_17 ;
V_30 = F_18 ( V_1 ) ;
for ( V_17 = 0 ; V_17 < F_14 ( V_30 ) ; V_17 ++ )
{
T_6 * V_32 ;
V_31 = F_15 ( V_30 , V_17 ) ;
if ( V_31 == V_20 )
continue;
if ( F_19 ( V_31 ) < 0 )
continue;
if ( F_20 ( V_20 -> V_33 -> V_34 ,
V_31 -> V_33 -> V_34 ) )
continue;
V_32 = F_21 ( V_31 ,
F_6 ( V_35 ) ,
- 3 , V_36 ) ;
if ( ! V_32 )
{
F_3 ( V_37 ,
V_38 ) ;
return 0 ;
}
if ( F_22 ( V_20 , V_35 ,
V_36 ,
V_32 , - 1 ) )
return 1 ;
else
return 0 ;
}
F_3 ( V_37 , V_39 ) ;
return 0 ;
}
int F_23 ( T_7 * V_28 , T_8 * V_40 , int type )
{
switch( type )
{
case V_41 :
V_28 -> V_6 . V_42 =
F_5 ( V_43 ) ;
if ( ! V_28 -> V_6 . V_42 )
goto V_44;
if ( ! F_24 ( & V_28 -> V_6 . V_42 -> V_45 ,
F_25 ( V_40 ) ) )
goto V_44;
if ( ! F_26 (
V_28 -> V_6 . V_42 -> V_46 ,
F_27 ( V_40 ) ) )
goto V_44;
break;
case V_29 :
if ( ! V_40 -> V_47 )
{
F_3 ( V_48 ,
V_49 ) ;
return 0 ;
}
V_28 -> V_6 . V_50 = F_28 ( V_40 -> V_47 ) ;
if ( ! V_28 -> V_6 . V_50 )
goto V_44;
break;
default:
F_3 ( V_48 , V_51 ) ;
return 0 ;
}
V_28 -> type = type ;
return 1 ;
V_44:
F_3 ( V_48 , V_10 ) ;
return 0 ;
}
int F_29 ( T_7 * V_28 ,
T_6 * * V_52 ,
T_9 * * V_45 , T_10 * * V_53 )
{
if ( V_28 -> type == V_41 )
{
if ( V_45 )
* V_45 = V_28 -> V_6 . V_42 -> V_45 ;
if ( V_53 )
* V_53 = V_28 -> V_6 . V_42 -> V_46 ;
}
else if ( V_28 -> type == V_29 )
{
if ( V_52 )
* V_52 = V_28 -> V_6 . V_50 ;
}
else
return 0 ;
return 1 ;
}
int F_30 ( T_7 * V_28 , T_8 * V_40 )
{
int V_54 ;
if ( V_28 -> type == V_41 )
{
V_54 = F_31 ( V_28 -> V_6 . V_42 -> V_45 ,
F_25 ( V_40 ) ) ;
if ( V_54 )
return V_54 ;
return F_32 ( V_28 -> V_6 . V_42 -> V_46 ,
F_27 ( V_40 ) ) ;
}
else if ( V_28 -> type == V_29 )
{
F_33 ( V_40 , - 1 , - 1 ) ;
if ( ! V_40 -> V_47 )
return - 1 ;
return F_34 ( V_28 -> V_6 . V_50 ,
V_40 -> V_47 ) ;
}
else
return - 1 ;
}
T_5 * F_35 ( T_2 * V_1 ,
T_8 * V_55 , T_11 * V_56 , const T_12 * V_57 ,
unsigned int V_58 )
{
T_1 * V_16 ;
T_5 * V_20 = NULL ;
T_13 * V_59 ;
int V_17 , type ;
if( ! F_36 ( V_55 , V_56 ) )
{
F_3 ( V_60 ,
V_61 ) ;
return NULL ;
}
V_16 = F_4 ( V_1 ) ;
if ( ! V_16 )
goto V_62;
V_20 = F_5 ( T_5 ) ;
if ( ! V_20 )
goto V_44;
F_33 ( V_55 , - 1 , - 1 ) ;
F_37 ( & V_56 -> V_63 , 1 , V_64 ) ;
F_37 ( & V_55 -> V_63 , 1 , V_65 ) ;
V_20 -> V_66 = V_56 ;
V_20 -> V_55 = V_55 ;
if ( V_58 & V_67 )
{
V_20 -> V_11 = 3 ;
if ( V_16 -> V_11 < 3 )
V_16 -> V_11 = 3 ;
type = V_29 ;
}
else
{
type = V_41 ;
V_20 -> V_11 = 1 ;
}
if ( ! F_23 ( V_20 -> V_28 , V_55 , type ) )
goto V_62;
if ( V_57 == NULL )
{
int V_68 ;
if ( F_38 ( V_56 , & V_68 ) <= 0 )
goto V_62;
V_57 = F_39 ( V_68 ) ;
if ( V_57 == NULL )
{
F_3 ( V_60 , V_69 ) ;
goto V_62;
}
}
if ( ! V_57 )
{
F_3 ( V_60 , V_70 ) ;
goto V_62;
}
F_40 ( V_20 -> V_33 , V_57 ) ;
for ( V_17 = 0 ; V_17 < F_41 ( V_16 -> V_71 ) ; V_17 ++ )
{
T_14 * V_72 ;
V_59 = F_42 ( V_16 -> V_71 , V_17 ) ;
F_43 ( & V_72 , NULL , NULL , V_59 ) ;
if ( F_2 ( V_72 ) == F_44 ( V_57 ) )
break;
}
if ( V_17 == F_41 ( V_16 -> V_71 ) )
{
V_59 = F_45 () ;
if ( ! V_59 )
goto V_44;
F_40 ( V_59 , V_57 ) ;
if ( ! F_46 ( V_16 -> V_71 , V_59 ) )
{
F_47 ( V_59 ) ;
goto V_44;
}
}
if ( V_56 -> V_73 && V_56 -> V_73 -> V_74 )
{
V_17 = V_56 -> V_73 -> V_74 ( V_56 , V_75 ,
0 , V_20 ) ;
if ( V_17 == - 2 )
{
F_3 ( V_60 ,
V_76 ) ;
goto V_62;
}
if ( V_17 <= 0 )
{
F_3 ( V_60 , V_77 ) ;
goto V_62;
}
}
if ( ! ( V_58 & V_78 ) )
{
if ( ! V_20 -> V_79 )
{
V_20 -> V_79 = F_48 () ;
if ( ! V_20 -> V_79 )
goto V_44;
}
if ( ! ( V_58 & V_80 ) )
{
F_17 ( T_13 ) * V_81 = NULL ;
V_17 = F_49 ( & V_81 ) ;
if ( V_17 )
V_17 = F_50 ( V_20 , V_81 ) ;
F_51 ( V_81 , F_47 ) ;
if ( ! V_17 )
goto V_44;
}
if ( V_58 & V_82 )
{
if ( ! F_16 ( V_1 , V_20 ) )
goto V_62;
if ( ! ( V_58 & V_83 ) &&
! F_52 ( V_20 ) )
goto V_62;
}
}
if ( ! ( V_58 & V_84 ) )
{
if ( ! F_53 ( V_1 , V_55 ) )
goto V_44;
}
if ( ! V_16 -> V_27 )
V_16 -> V_27 = F_54 () ;
if ( ! V_16 -> V_27 ||
! F_55 ( V_16 -> V_27 , V_20 ) )
goto V_44;
return V_20 ;
V_44:
F_3 ( V_60 , V_10 ) ;
V_62:
if ( V_20 )
F_56 ( V_20 , T_5 ) ;
return NULL ;
}
static int F_57 ( T_5 * V_20 , T_15 * V_85 )
{
T_15 * V_86 ;
int V_87 = 0 ;
if ( V_85 )
V_86 = V_85 ;
else
V_86 = F_58 ( NULL , 0 ) ;
if ( ! V_86 )
goto V_44;
if ( F_22 ( V_20 , V_88 ,
V_86 -> type , V_86 , - 1 ) <= 0 )
goto V_44;
V_87 = 1 ;
V_44:
if ( ! V_85 )
F_59 ( V_86 ) ;
if ( ! V_87 )
F_3 ( V_89 , V_10 ) ;
return V_87 ;
}
int F_60 ( T_5 * V_20 ,
T_6 * * V_52 ,
T_9 * * V_45 , T_10 * * V_53 )
{
return F_29 ( V_20 -> V_28 , V_52 , V_45 , V_53 ) ;
}
int F_61 ( T_5 * V_20 , T_8 * V_40 )
{
return F_30 ( V_20 -> V_28 , V_40 ) ;
}
void F_62 ( T_5 * V_20 , T_11 * * V_56 , T_8 * * V_55 ,
T_13 * * V_90 , T_13 * * V_91 )
{
if ( V_56 )
* V_56 = V_20 -> V_66 ;
if ( V_55 )
* V_55 = V_20 -> V_55 ;
if ( V_90 )
* V_90 = V_20 -> V_33 ;
if ( V_91 )
* V_91 = V_20 -> V_92 ;
}
static int F_63 ( T_2 * V_1 ,
T_5 * V_20 , T_16 * V_93 )
{
T_17 V_94 ;
int V_87 = 0 ;
F_64 ( & V_94 ) ;
if ( ! V_20 -> V_66 )
{
F_3 ( V_95 , V_96 ) ;
return 0 ;
}
if ( ! F_65 ( & V_94 , V_93 , V_20 -> V_33 ) )
goto V_62;
if ( F_19 ( V_20 ) >= 0 )
{
T_14 * V_97 =
V_1 -> V_6 . V_7 -> V_12 -> V_13 ;
unsigned char V_57 [ V_98 ] ;
unsigned int V_99 ;
F_66 ( & V_94 , V_57 , & V_99 ) ;
if ( ! F_22 ( V_20 , V_35 ,
V_36 ,
V_57 , V_99 ) )
goto V_62;
if ( F_22 ( V_20 , V_100 ,
V_101 , V_97 , - 1 ) <= 0 )
goto V_62;
if ( ! F_52 ( V_20 ) )
goto V_62;
}
else
{
unsigned char * V_102 ;
unsigned int V_103 ;
V_102 = F_67 ( F_68 ( V_20 -> V_66 ) ) ;
if ( ! V_102 )
{
F_3 ( V_95 ,
V_10 ) ;
goto V_62;
}
if ( ! F_69 ( & V_94 , V_102 , & V_103 , V_20 -> V_66 ) )
{
F_3 ( V_95 ,
V_104 ) ;
F_70 ( V_102 ) ;
goto V_62;
}
F_71 ( V_20 -> V_105 , V_102 , V_103 ) ;
}
V_87 = 1 ;
V_62:
F_72 ( & V_94 ) ;
return V_87 ;
}
int F_73 ( T_2 * V_1 , T_16 * V_93 )
{
F_17 ( T_5 ) * V_30 ;
T_5 * V_20 ;
int V_17 ;
V_30 = F_18 ( V_1 ) ;
for ( V_17 = 0 ; V_17 < F_14 ( V_30 ) ; V_17 ++ )
{
V_20 = F_15 ( V_30 , V_17 ) ;
if ( ! F_63 ( V_1 , V_20 , V_93 ) )
return 0 ;
}
V_1 -> V_6 . V_7 -> V_12 -> V_15 = 0 ;
return 1 ;
}
int F_52 ( T_5 * V_20 )
{
T_17 V_94 ;
T_18 * V_106 ;
unsigned char * V_107 = NULL ;
int V_108 ;
T_19 V_103 ;
const T_12 * V_57 = NULL ;
V_57 = F_74 ( V_20 -> V_33 -> V_34 ) ;
if ( V_57 == NULL )
return 0 ;
F_64 ( & V_94 ) ;
if ( F_75 ( V_20 , V_88 , - 1 ) < 0 )
{
if ( ! F_57 ( V_20 , NULL ) )
goto V_62;
}
if ( F_76 ( & V_94 , & V_106 , V_57 , NULL , V_20 -> V_66 ) <= 0 )
goto V_62;
if ( F_77 ( V_106 , - 1 , V_109 ,
V_110 , 0 , V_20 ) <= 0 )
{
F_3 ( V_111 , V_112 ) ;
goto V_62;
}
V_108 = F_78 ( ( V_113 * ) V_20 -> V_79 , & V_107 ,
F_79 ( V_114 ) ) ;
if( ! V_107 )
goto V_62;
if ( F_80 ( & V_94 , V_107 , V_108 ) <= 0 )
goto V_62;
if ( F_81 ( & V_94 , NULL , & V_103 ) <= 0 )
goto V_62;
F_70 ( V_107 ) ;
V_107 = F_67 ( V_103 ) ;
if( ! V_107 )
goto V_62;
if ( F_81 ( & V_94 , V_107 , & V_103 ) <= 0 )
goto V_62;
if ( F_77 ( V_106 , - 1 , V_109 ,
V_110 , 1 , V_20 ) <= 0 )
{
F_3 ( V_111 , V_112 ) ;
goto V_62;
}
F_72 ( & V_94 ) ;
F_71 ( V_20 -> V_105 , V_107 , V_103 ) ;
return 1 ;
V_62:
if ( V_107 )
F_70 ( V_107 ) ;
F_72 ( & V_94 ) ;
return 0 ;
}
int F_82 ( T_5 * V_20 )
{
T_17 V_94 ;
T_18 * V_106 ;
unsigned char * V_107 = NULL ;
int V_108 , V_87 = - 1 ;
const T_12 * V_57 = NULL ;
if ( ! V_20 -> V_66 )
{
F_3 ( V_115 , V_116 ) ;
return - 1 ;
}
V_57 = F_74 ( V_20 -> V_33 -> V_34 ) ;
if ( V_57 == NULL )
return - 1 ;
F_64 ( & V_94 ) ;
if ( F_83 ( & V_94 , & V_106 , V_57 , NULL , V_20 -> V_66 ) <= 0 )
goto V_62;
V_108 = F_78 ( ( V_113 * ) V_20 -> V_79 , & V_107 ,
F_79 ( V_117 ) ) ;
if( ! V_107 )
goto V_62;
V_87 = F_84 ( & V_94 , V_107 , V_108 ) ;
F_70 ( V_107 ) ;
if ( V_87 <= 0 )
{
V_87 = - 1 ;
goto V_62;
}
V_87 = F_85 ( & V_94 ,
V_20 -> V_105 -> V_118 , V_20 -> V_105 -> V_119 ) ;
if ( V_87 <= 0 )
F_3 ( V_115 , V_120 ) ;
V_62:
F_72 ( & V_94 ) ;
return V_87 ;
}
T_16 * F_86 ( T_2 * V_1 )
{
int V_17 ;
T_1 * V_16 ;
T_16 * V_93 = NULL ;
V_16 = F_1 ( V_1 ) ;
if ( ! V_16 )
return NULL ;
if ( V_1 -> V_6 . V_7 -> V_12 -> V_15 )
F_9 ( V_16 ) ;
for ( V_17 = 0 ; V_17 < F_41 ( V_16 -> V_71 ) ; V_17 ++ )
{
T_13 * V_33 ;
T_16 * V_121 ;
V_33 = F_42 ( V_16 -> V_71 , V_17 ) ;
V_121 = F_87 ( V_33 ) ;
if ( ! V_121 )
goto V_62;
if ( V_93 )
F_88 ( V_93 , V_121 ) ;
else
V_93 = V_121 ;
}
return V_93 ;
V_62:
if ( V_93 )
F_89 ( V_93 ) ;
return NULL ;
}
int F_90 ( T_5 * V_20 , T_16 * V_93 )
{
T_6 * V_122 = NULL ;
T_17 V_94 ;
int V_87 = - 1 ;
F_64 ( & V_94 ) ;
if ( F_19 ( V_20 ) >= 0 )
{
V_122 = F_21 ( V_20 ,
F_6 ( V_35 ) ,
- 3 , V_36 ) ;
if ( ! V_122 )
{
F_3 ( V_123 ,
V_38 ) ;
goto V_62;
}
}
if ( ! F_65 ( & V_94 , V_93 , V_20 -> V_33 ) )
goto V_62;
if ( V_122 )
{
unsigned char V_124 [ V_98 ] ;
unsigned int V_125 ;
if ( F_66 ( & V_94 , V_124 , & V_125 ) <= 0 )
{
F_3 ( V_123 ,
V_126 ) ;
goto V_62;
}
if ( V_125 != ( unsigned int ) V_122 -> V_119 )
{
F_3 ( V_123 ,
V_127 ) ;
goto V_62;
}
if ( memcmp ( V_124 , V_122 -> V_118 , V_125 ) )
{
F_3 ( V_123 ,
V_120 ) ;
V_87 = 0 ;
}
else
V_87 = 1 ;
}
else
{
V_87 = F_91 ( & V_94 , V_20 -> V_105 -> V_118 ,
V_20 -> V_105 -> V_119 , V_20 -> V_66 ) ;
if ( V_87 <= 0 )
{
F_3 ( V_123 ,
V_120 ) ;
V_87 = 0 ;
}
}
V_62:
F_72 ( & V_94 ) ;
return V_87 ;
}
