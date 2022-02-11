static T_1 * F_1 ( T_2 * V_1 )
{
if ( F_2 ( V_1 -> V_2 ) != V_3 )
{
F_3 ( V_4 ,
V_5 ) ;
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
F_3 ( V_9 ,
V_10 ) ;
return NULL ;
}
V_1 -> V_6 . V_7 -> V_11 = 0 ;
V_1 -> V_6 . V_7 -> V_12 -> V_2 =
F_6 ( V_13 ) ;
F_7 ( V_1 -> V_2 ) ;
V_1 -> V_2 = F_6 ( V_3 ) ;
return V_1 -> V_6 . V_7 ;
}
return F_1 ( V_1 ) ;
}
T_2 * F_8 ( const T_3 * V_14 )
{
T_2 * V_1 ;
T_1 * V_15 ;
V_1 = F_9 () ;
if ( ! V_1 )
goto V_16;
V_15 = F_4 ( V_1 ) ;
if ( ! V_15 )
goto V_16;
if ( ! F_10 ( V_15 -> V_12 ,
V_14 , NULL , 0 ) )
goto V_16;
return V_1 ;
V_16:
if ( V_1 )
F_11 ( V_1 ) ;
F_3 ( V_17 , V_10 ) ;
return NULL ;
}
T_4 * F_12 ( T_2 * V_1 ,
T_5 * V_18 , unsigned int V_19 )
{
T_4 * V_20 = NULL ;
T_6 * V_21 ;
T_1 * V_15 ;
T_7 * V_22 = NULL ;
int V_23 , type ;
V_15 = F_1 ( V_1 ) ;
if ( ! V_15 )
goto V_24;
V_20 = F_5 ( T_4 ) ;
if ( ! V_20 )
goto V_16;
V_20 -> V_6 . V_21 = F_5 ( T_6 ) ;
if ( ! V_20 -> V_6 . V_21 )
goto V_16;
V_20 -> type = V_25 ;
V_21 = V_20 -> V_6 . V_21 ;
F_13 ( V_18 , - 1 , - 1 ) ;
V_22 = F_14 ( V_18 ) ;
if ( ! V_22 )
{
F_3 ( V_26 ,
V_27 ) ;
goto V_24;
}
F_15 ( & V_18 -> V_28 , 1 , V_29 ) ;
V_21 -> V_30 = V_22 ;
V_21 -> V_18 = V_18 ;
if ( V_19 & V_31 )
{
V_21 -> V_11 = 2 ;
type = V_32 ;
}
else
{
V_21 -> V_11 = 0 ;
type = V_33 ;
}
if ( ! F_16 ( V_21 -> V_34 , V_18 , type ) )
goto V_24;
if ( V_22 -> V_35 && V_22 -> V_35 -> V_36 )
{
V_23 = V_22 -> V_35 -> V_36 ( V_22 , V_37 ,
0 , V_20 ) ;
if ( V_23 == - 2 )
{
F_3 ( V_26 ,
V_38 ) ;
goto V_24;
}
if ( V_23 <= 0 )
{
F_3 ( V_26 ,
V_39 ) ;
goto V_24;
}
}
if ( ! F_17 ( V_15 -> V_40 , V_20 ) )
goto V_16;
return V_20 ;
V_16:
F_3 ( V_26 , V_10 ) ;
V_24:
if ( V_20 )
F_18 ( V_20 , T_4 ) ;
return NULL ;
}
int F_19 ( T_4 * V_20 ,
T_7 * * V_22 , T_5 * * V_18 ,
T_8 * * V_41 )
{
T_6 * V_21 ;
if ( V_20 -> type != V_25 )
{
F_3 ( V_42 ,
V_43 ) ;
return 0 ;
}
V_21 = V_20 -> V_6 . V_21 ;
if ( V_22 )
* V_22 = V_21 -> V_30 ;
if ( V_18 )
* V_18 = V_21 -> V_18 ;
if ( V_41 )
* V_41 = V_21 -> V_44 ;
return 1 ;
}
int F_20 ( T_4 * V_20 ,
T_9 * * V_45 ,
T_10 * * V_46 , T_11 * * V_47 )
{
T_6 * V_21 ;
if ( V_20 -> type != V_25 )
{
F_3 ( V_48 ,
V_43 ) ;
return 0 ;
}
V_21 = V_20 -> V_6 . V_21 ;
return F_21 ( V_21 -> V_34 ,
V_45 , V_46 , V_47 ) ;
}
int F_22 ( T_4 * V_20 , T_5 * V_49 )
{
if ( V_20 -> type != V_25 )
{
F_3 ( V_50 ,
V_43 ) ;
return - 2 ;
}
return F_23 ( V_20 -> V_6 . V_21 -> V_34 , V_49 ) ;
}
int F_24 ( T_4 * V_20 , T_7 * V_30 )
{
if ( V_20 -> type != V_25 )
{
F_3 ( V_51 ,
V_43 ) ;
return 0 ;
}
V_20 -> V_6 . V_21 -> V_30 = V_30 ;
return 1 ;
}
static int F_25 ( T_2 * V_1 ,
T_4 * V_20 )
{
T_6 * V_21 ;
T_12 * V_52 ;
T_13 * V_53 = NULL ;
unsigned char * V_54 = NULL ;
T_14 V_55 ;
int V_56 = 0 ;
if ( V_20 -> type != V_25 )
{
F_3 ( V_57 ,
V_43 ) ;
return 0 ;
}
V_21 = V_20 -> V_6 . V_21 ;
V_52 = V_1 -> V_6 . V_7 -> V_12 ;
V_53 = F_26 ( V_21 -> V_30 , NULL ) ;
if ( ! V_53 )
return 0 ;
if ( F_27 ( V_53 ) <= 0 )
goto V_24;
if ( F_28 ( V_53 , - 1 , V_58 ,
V_59 , 0 , V_20 ) <= 0 )
{
F_3 ( V_57 , V_60 ) ;
goto V_24;
}
if ( F_29 ( V_53 , NULL , & V_55 , V_52 -> V_61 , V_52 -> V_62 ) <= 0 )
goto V_24;
V_54 = F_30 ( V_55 ) ;
if ( V_54 == NULL )
{
F_3 ( V_57 ,
V_10 ) ;
goto V_24;
}
if ( F_29 ( V_53 , V_54 , & V_55 , V_52 -> V_61 , V_52 -> V_62 ) <= 0 )
goto V_24;
F_31 ( V_21 -> V_63 , V_54 , V_55 ) ;
V_54 = NULL ;
V_56 = 1 ;
V_24:
if ( V_53 )
F_32 ( V_53 ) ;
if ( V_54 )
F_33 ( V_54 ) ;
return V_56 ;
}
static int F_34 ( T_2 * V_1 ,
T_4 * V_20 )
{
T_6 * V_21 = V_20 -> V_6 . V_21 ;
T_13 * V_53 = NULL ;
unsigned char * V_54 = NULL ;
T_14 V_55 ;
int V_56 = 0 ;
if ( V_21 -> V_30 == NULL )
{
F_3 ( V_64 ,
V_65 ) ;
return 0 ;
}
V_53 = F_26 ( V_21 -> V_30 , NULL ) ;
if ( ! V_53 )
return 0 ;
if ( F_35 ( V_53 ) <= 0 )
goto V_24;
if ( F_28 ( V_53 , - 1 , V_66 ,
V_67 , 0 , V_20 ) <= 0 )
{
F_3 ( V_64 , V_60 ) ;
goto V_24;
}
if ( F_36 ( V_53 , NULL , & V_55 ,
V_21 -> V_63 -> V_68 ,
V_21 -> V_63 -> V_69 ) <= 0 )
goto V_24;
V_54 = F_30 ( V_55 ) ;
if ( V_54 == NULL )
{
F_3 ( V_64 ,
V_10 ) ;
goto V_24;
}
if ( F_36 ( V_53 , V_54 , & V_55 ,
V_21 -> V_63 -> V_68 ,
V_21 -> V_63 -> V_69 ) <= 0 )
{
F_3 ( V_64 , V_70 ) ;
goto V_24;
}
V_56 = 1 ;
V_1 -> V_6 . V_7 -> V_12 -> V_61 = V_54 ;
V_1 -> V_6 . V_7 -> V_12 -> V_62 = V_55 ;
V_24:
if ( V_53 )
F_32 ( V_53 ) ;
if ( ! V_56 && V_54 )
F_33 ( V_54 ) ;
return V_56 ;
}
int F_37 ( T_4 * V_20 ,
const unsigned char * V_71 , T_14 V_72 )
{
T_9 V_73 ;
T_15 * V_74 ;
if ( V_20 -> type != V_75 )
{
F_3 ( V_76 , V_77 ) ;
return - 2 ;
}
V_74 = V_20 -> V_6 . V_74 ;
V_73 . type = V_78 ;
V_73 . V_19 = 0 ;
V_73 . V_68 = ( unsigned char * ) V_71 ;
V_73 . V_69 = ( int ) V_72 ;
return F_38 ( & V_73 , V_74 -> V_79 -> V_80 ) ;
}
static T_14 F_39 ( int V_81 )
{
switch ( V_81 )
{
case V_82 :
return 16 ;
case V_83 :
return 24 ;
case V_84 :
return 32 ;
default:
return 0 ;
}
}
T_4 * F_40 ( T_2 * V_1 , int V_81 ,
unsigned char * V_61 , T_14 V_62 ,
unsigned char * V_71 , T_14 V_72 ,
T_16 * V_85 ,
T_17 * V_86 ,
T_18 * V_87 )
{
T_4 * V_20 = NULL ;
T_1 * V_15 ;
T_15 * V_74 ;
V_15 = F_1 ( V_1 ) ;
if ( ! V_15 )
goto V_24;
if ( V_81 == V_88 )
{
switch ( V_62 )
{
case 16 :
V_81 = V_82 ;
break;
case 24 :
V_81 = V_83 ;
break;
case 32 :
V_81 = V_84 ;
break;
default:
F_3 ( V_89 ,
V_90 ) ;
goto V_24;
}
}
else
{
T_14 V_91 = F_39 ( V_81 ) ;
if ( ! V_91 )
{
F_3 ( V_89 ,
V_92 ) ;
goto V_24;
}
if ( V_62 != V_91 )
{
F_3 ( V_89 ,
V_90 ) ;
goto V_24;
}
}
V_20 = F_5 ( T_4 ) ;
if ( ! V_20 )
goto V_16;
V_20 -> V_6 . V_74 = F_5 ( T_15 ) ;
if ( ! V_20 -> V_6 . V_74 )
goto V_16;
V_20 -> type = V_75 ;
V_74 = V_20 -> V_6 . V_74 ;
if ( V_86 )
{
V_74 -> V_79 -> V_8 = F_5 ( V_93 ) ;
if ( V_74 -> V_79 -> V_8 == NULL )
goto V_16;
}
if ( ! F_17 ( V_15 -> V_40 , V_20 ) )
goto V_16;
V_74 -> V_11 = 4 ;
V_74 -> V_61 = V_61 ;
V_74 -> V_62 = V_62 ;
F_31 ( V_74 -> V_79 -> V_80 , V_71 , V_72 ) ;
V_74 -> V_79 -> V_85 = V_85 ;
if ( V_74 -> V_79 -> V_8 )
{
V_74 -> V_79 -> V_8 -> V_94 = V_86 ;
V_74 -> V_79 -> V_8 -> V_95 = V_87 ;
}
F_41 ( V_74 -> V_44 ,
F_6 ( V_81 ) , V_96 , NULL ) ;
return V_20 ;
V_16:
F_3 ( V_89 , V_10 ) ;
V_24:
if ( V_20 )
F_18 ( V_20 , T_4 ) ;
return NULL ;
}
int F_42 ( T_4 * V_20 ,
T_8 * * V_41 ,
T_9 * * V_97 ,
T_16 * * V_98 ,
T_17 * * V_99 ,
T_18 * * V_100 )
{
T_19 * V_101 ;
if ( V_20 -> type != V_75 )
{
F_3 ( V_102 , V_77 ) ;
return 0 ;
}
V_101 = V_20 -> V_6 . V_74 -> V_79 ;
if ( V_41 )
* V_41 = V_20 -> V_6 . V_74 -> V_44 ;
if ( V_97 )
* V_97 = V_101 -> V_80 ;
if ( V_98 )
* V_98 = V_101 -> V_85 ;
if ( V_99 )
{
if ( V_101 -> V_8 )
* V_99 = V_101 -> V_8 -> V_94 ;
else
* V_99 = NULL ;
}
if ( V_100 )
{
if ( V_101 -> V_8 )
* V_100 = V_101 -> V_8 -> V_95 ;
else
* V_100 = NULL ;
}
return 1 ;
}
int F_43 ( T_4 * V_20 ,
unsigned char * V_61 , T_14 V_62 )
{
T_15 * V_74 ;
if ( V_20 -> type != V_75 )
{
F_3 ( V_103 , V_77 ) ;
return 0 ;
}
V_74 = V_20 -> V_6 . V_74 ;
V_74 -> V_61 = V_61 ;
V_74 -> V_62 = V_62 ;
return 1 ;
}
static int F_44 ( T_2 * V_1 ,
T_4 * V_20 )
{
T_12 * V_52 ;
T_15 * V_74 ;
T_20 V_104 ;
unsigned char * V_105 = NULL ;
int V_106 ;
int V_107 = 0 ;
V_52 = V_1 -> V_6 . V_7 -> V_12 ;
V_74 = V_20 -> V_6 . V_74 ;
if ( ! V_74 -> V_61 )
{
F_3 ( V_108 , V_109 ) ;
return 0 ;
}
if ( F_45 ( V_74 -> V_61 , V_74 -> V_62 << 3 , & V_104 ) )
{
F_3 ( V_108 ,
V_110 ) ;
goto V_24;
}
V_105 = F_30 ( V_52 -> V_62 + 8 ) ;
if ( ! V_105 )
{
F_3 ( V_108 ,
V_10 ) ;
goto V_24;
}
V_106 = F_46 ( & V_104 , NULL , V_105 , V_52 -> V_61 , V_52 -> V_62 ) ;
if ( V_106 <= 0 )
{
F_3 ( V_108 , V_111 ) ;
goto V_24;
}
F_31 ( V_74 -> V_63 , V_105 , V_106 ) ;
V_107 = 1 ;
V_24:
if ( ! V_107 && V_105 )
F_33 ( V_105 ) ;
F_47 ( & V_104 , sizeof( V_104 ) ) ;
return V_107 ;
}
static int F_48 ( T_2 * V_1 ,
T_4 * V_20 )
{
T_12 * V_52 ;
T_15 * V_74 ;
T_20 V_104 ;
unsigned char * V_112 = NULL ;
int V_113 ;
int V_107 = 0 , V_114 ;
V_52 = V_1 -> V_6 . V_7 -> V_12 ;
V_74 = V_20 -> V_6 . V_74 ;
if ( ! V_74 -> V_61 )
{
F_3 ( V_115 , V_109 ) ;
return 0 ;
}
V_114 = F_2 ( V_74 -> V_44 -> V_116 ) ;
if ( F_39 ( V_114 ) != V_74 -> V_62 )
{
F_3 ( V_115 ,
V_90 ) ;
return 0 ;
}
if ( V_74 -> V_63 -> V_69 < 16 )
{
F_3 ( V_115 ,
V_117 ) ;
goto V_24;
}
if ( F_49 ( V_74 -> V_61 , V_74 -> V_62 << 3 , & V_104 ) )
{
F_3 ( V_115 ,
V_110 ) ;
goto V_24;
}
V_112 = F_30 ( V_74 -> V_63 -> V_69 - 8 ) ;
if ( ! V_112 )
{
F_3 ( V_115 ,
V_10 ) ;
goto V_24;
}
V_113 = F_50 ( & V_104 , NULL , V_112 ,
V_74 -> V_63 -> V_68 ,
V_74 -> V_63 -> V_69 ) ;
if ( V_113 <= 0 )
{
F_3 ( V_115 ,
V_118 ) ;
goto V_24;
}
V_52 -> V_61 = V_112 ;
V_52 -> V_62 = V_113 ;
V_107 = 1 ;
V_24:
if ( ! V_107 && V_112 )
F_33 ( V_112 ) ;
F_47 ( & V_104 , sizeof( V_104 ) ) ;
return V_107 ;
}
int F_51 ( T_2 * V_1 , T_4 * V_20 )
{
switch( V_20 -> type )
{
case V_25 :
return F_34 ( V_1 , V_20 ) ;
case V_75 :
return F_48 ( V_1 , V_20 ) ;
default:
F_3 ( V_119 ,
V_120 ) ;
return 0 ;
}
}
T_21 * F_52 ( T_2 * V_1 )
{
T_12 * V_52 ;
F_53 ( T_4 ) * V_121 ;
T_4 * V_20 ;
int V_23 , V_107 , V_122 = 0 ;
T_21 * V_56 ;
V_52 = V_1 -> V_6 . V_7 -> V_12 ;
V_56 = F_54 ( V_52 ) ;
if ( ! V_56 || ! V_52 -> V_14 )
return V_56 ;
V_121 = V_1 -> V_6 . V_7 -> V_40 ;
for ( V_23 = 0 ; V_23 < F_55 ( V_121 ) ; V_23 ++ )
{
V_20 = F_56 ( V_121 , V_23 ) ;
switch ( V_20 -> type )
{
case V_25 :
V_107 = F_25 ( V_1 , V_20 ) ;
break;
case V_75 :
V_107 = F_44 ( V_1 , V_20 ) ;
break;
default:
F_3 ( V_123 ,
V_124 ) ;
goto V_24;
}
if ( V_107 <= 0 )
{
F_3 ( V_123 ,
V_125 ) ;
goto V_24;
}
}
V_122 = 1 ;
V_24:
V_52 -> V_14 = NULL ;
if ( V_52 -> V_61 )
{
F_47 ( V_52 -> V_61 , V_52 -> V_62 ) ;
F_33 ( V_52 -> V_61 ) ;
V_52 -> V_61 = NULL ;
V_52 -> V_62 = 0 ;
}
if ( V_122 )
return V_56 ;
F_57 ( V_56 ) ;
return NULL ;
}
