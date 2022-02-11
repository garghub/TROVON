static T_1 * F_1 ( T_2 * V_1 )
{
if ( F_2 ( V_1 -> V_2 ) != V_3 ) {
F_3 ( V_4 , V_5 ) ;
return NULL ;
}
return V_1 -> V_6 . V_7 ;
}
static T_1 * F_4 ( T_2 * V_1 )
{
if ( V_1 -> V_6 . V_8 == NULL ) {
V_1 -> V_6 . V_7 = F_5 ( T_1 ) ;
if ( ! V_1 -> V_6 . V_7 ) {
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
for ( V_17 = 0 ; V_17 < F_10 ( V_16 -> V_21 ) ; V_17 ++ ) {
V_18 = F_11 ( V_16 -> V_21 , V_17 ) ;
if ( V_18 -> type == V_22 ) {
if ( V_16 -> V_11 < 5 )
V_16 -> V_11 = 5 ;
} else if ( V_18 -> type == V_23 ) {
if ( V_16 -> V_11 < 4 )
V_16 -> V_11 = 4 ;
} else if ( V_18 -> type == V_24 ) {
if ( V_16 -> V_11 < 3 )
V_16 -> V_11 = 3 ;
}
}
for ( V_17 = 0 ; V_17 < F_12 ( V_16 -> V_25 ) ; V_17 ++ ) {
V_19 = F_13 ( V_16 -> V_25 , V_17 ) ;
if ( V_19 -> type == V_26 ) {
if ( V_16 -> V_11 < 5 )
V_16 -> V_11 = 5 ;
}
}
if ( ( F_2 ( V_16 -> V_12 -> V_13 ) != V_14 )
&& ( V_16 -> V_11 < 3 ) )
V_16 -> V_11 = 3 ;
for ( V_17 = 0 ; V_17 < F_14 ( V_16 -> V_27 ) ; V_17 ++ ) {
V_20 = F_15 ( V_16 -> V_27 , V_17 ) ;
if ( V_20 -> V_28 -> type == V_29 ) {
if ( V_20 -> V_11 < 3 )
V_20 -> V_11 = 3 ;
if ( V_16 -> V_11 < 3 )
V_16 -> V_11 = 3 ;
} else if ( V_20 -> V_11 < 1 )
V_20 -> V_11 = 1 ;
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
for ( V_17 = 0 ; V_17 < F_14 ( V_30 ) ; V_17 ++ ) {
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
F_6
( V_35 ) ,
- 3 , V_36 ) ;
if ( ! V_32 ) {
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
switch ( type ) {
case V_41 :
if ( ! F_24 ( & V_28 -> V_6 . V_42 , V_40 ) )
return 0 ;
break;
case V_29 :
if ( ! F_25 ( & V_28 -> V_6 . V_43 , V_40 ) )
return 0 ;
break;
default:
F_3 ( V_44 , V_45 ) ;
return 0 ;
}
V_28 -> type = type ;
return 1 ;
}
int F_26 ( T_7 * V_28 ,
T_6 * * V_46 ,
T_9 * * V_47 ,
T_10 * * V_48 )
{
if ( V_28 -> type == V_41 ) {
if ( V_47 )
* V_47 = V_28 -> V_6 . V_42 -> V_47 ;
if ( V_48 )
* V_48 = V_28 -> V_6 . V_42 -> V_49 ;
} else if ( V_28 -> type == V_29 ) {
if ( V_46 )
* V_46 = V_28 -> V_6 . V_43 ;
} else
return 0 ;
return 1 ;
}
int F_27 ( T_7 * V_28 , T_8 * V_40 )
{
if ( V_28 -> type == V_41 )
return F_28 ( V_28 -> V_6 . V_42 , V_40 ) ;
else if ( V_28 -> type == V_29 )
return F_29 ( V_28 -> V_6 . V_43 , V_40 ) ;
else
return - 1 ;
}
static int F_30 ( T_5 * V_20 , int V_50 )
{
T_11 * V_51 = V_20 -> V_51 ;
int V_17 ;
if ( ! V_51 -> V_52 || ! V_51 -> V_52 -> V_53 )
return 1 ;
V_17 = V_51 -> V_52 -> V_53 ( V_51 , V_54 , V_50 , V_20 ) ;
if ( V_17 == - 2 ) {
F_3 ( V_55 , V_56 ) ;
return 0 ;
}
if ( V_17 <= 0 ) {
F_3 ( V_55 , V_57 ) ;
return 0 ;
}
return 1 ;
}
T_5 * F_31 ( T_2 * V_1 ,
T_8 * V_58 , T_11 * V_59 , const T_12 * V_60 ,
unsigned int V_61 )
{
T_1 * V_16 ;
T_5 * V_20 = NULL ;
T_13 * V_62 ;
int V_17 , type ;
if ( ! F_32 ( V_58 , V_59 ) ) {
F_3 ( V_63 ,
V_64 ) ;
return NULL ;
}
V_16 = F_4 ( V_1 ) ;
if ( ! V_16 )
goto V_65;
V_20 = F_5 ( T_5 ) ;
if ( ! V_20 )
goto V_66;
F_33 ( V_58 , - 1 , - 1 ) ;
F_34 ( V_58 ) ;
F_35 ( V_59 ) ;
V_20 -> V_51 = V_59 ;
V_20 -> V_58 = V_58 ;
V_20 -> V_67 = F_36 () ;
V_20 -> V_68 = NULL ;
if ( V_20 -> V_67 == NULL ) {
F_3 ( V_63 , V_10 ) ;
goto V_65;
}
if ( V_61 & V_69 ) {
V_20 -> V_11 = 3 ;
if ( V_16 -> V_11 < 3 )
V_16 -> V_11 = 3 ;
type = V_29 ;
} else {
type = V_41 ;
V_20 -> V_11 = 1 ;
}
if ( ! F_23 ( V_20 -> V_28 , V_58 , type ) )
goto V_65;
if ( V_60 == NULL ) {
int V_70 ;
if ( F_37 ( V_59 , & V_70 ) <= 0 )
goto V_65;
V_60 = F_38 ( V_70 ) ;
if ( V_60 == NULL ) {
F_3 ( V_63 , V_71 ) ;
goto V_65;
}
}
if ( ! V_60 ) {
F_3 ( V_63 , V_72 ) ;
goto V_65;
}
F_39 ( V_20 -> V_33 , V_60 ) ;
for ( V_17 = 0 ; V_17 < F_40 ( V_16 -> V_73 ) ; V_17 ++ ) {
const T_14 * V_74 ;
V_62 = F_41 ( V_16 -> V_73 , V_17 ) ;
F_42 ( & V_74 , NULL , NULL , V_62 ) ;
if ( F_2 ( V_74 ) == F_43 ( V_60 ) )
break;
}
if ( V_17 == F_40 ( V_16 -> V_73 ) ) {
V_62 = F_44 () ;
if ( V_62 == NULL )
goto V_66;
F_39 ( V_62 , V_60 ) ;
if ( ! F_45 ( V_16 -> V_73 , V_62 ) ) {
F_46 ( V_62 ) ;
goto V_66;
}
}
if ( ! ( V_61 & V_75 ) && ! F_30 ( V_20 , 0 ) )
goto V_65;
if ( ! ( V_61 & V_76 ) ) {
if ( ! V_20 -> V_77 ) {
V_20 -> V_77 = F_47 () ;
if ( ! V_20 -> V_77 )
goto V_66;
}
if ( ! ( V_61 & V_78 ) ) {
F_17 ( T_13 ) * V_79 = NULL ;
V_17 = F_48 ( & V_79 ) ;
if ( V_17 )
V_17 = F_49 ( V_20 , V_79 ) ;
F_50 ( V_79 , F_46 ) ;
if ( ! V_17 )
goto V_66;
}
if ( V_61 & V_80 ) {
if ( ! F_16 ( V_1 , V_20 ) )
goto V_65;
if ( ! ( V_61 & ( V_81 | V_75 ) ) &&
! F_51 ( V_20 ) )
goto V_65;
}
}
if ( ! ( V_61 & V_82 ) ) {
if ( ! F_52 ( V_1 , V_58 ) )
goto V_66;
}
if ( V_61 & V_75 ) {
if ( V_61 & V_76 ) {
V_20 -> V_68 = F_53 ( V_20 -> V_51 , NULL ) ;
if ( V_20 -> V_68 == NULL )
goto V_65;
if ( F_54 ( V_20 -> V_68 ) <= 0 )
goto V_65;
if ( F_55 ( V_20 -> V_68 , V_60 ) <= 0 )
goto V_65;
} else if ( F_56 ( V_20 -> V_67 , & V_20 -> V_68 , V_60 , NULL , V_59 ) <=
0 )
goto V_65;
}
if ( ! V_16 -> V_27 )
V_16 -> V_27 = F_57 () ;
if ( ! V_16 -> V_27 || ! F_58 ( V_16 -> V_27 , V_20 ) )
goto V_66;
return V_20 ;
V_66:
F_3 ( V_63 , V_10 ) ;
V_65:
F_59 ( V_20 , T_5 ) ;
return NULL ;
}
static int F_60 ( T_5 * V_20 , T_15 * V_83 )
{
T_15 * V_84 ;
int V_85 = 0 ;
if ( V_83 )
V_84 = V_83 ;
else
V_84 = F_61 ( NULL , 0 ) ;
if ( ! V_84 )
goto V_66;
if ( F_22 ( V_20 , V_86 ,
V_84 -> type , V_84 , - 1 ) <= 0 )
goto V_66;
V_85 = 1 ;
V_66:
if ( ! V_83 )
F_62 ( V_84 ) ;
if ( ! V_85 )
F_3 ( V_87 , V_10 ) ;
return V_85 ;
}
T_16 * F_63 ( T_5 * V_20 )
{
return V_20 -> V_68 ;
}
T_17 * F_64 ( T_5 * V_20 )
{
return V_20 -> V_67 ;
}
int F_65 ( T_5 * V_20 ,
T_6 * * V_46 ,
T_9 * * V_47 , T_10 * * V_48 )
{
return F_26 ( V_20 -> V_28 , V_46 , V_47 , V_48 ) ;
}
int F_66 ( T_5 * V_20 , T_8 * V_40 )
{
return F_27 ( V_20 -> V_28 , V_40 ) ;
}
void F_67 ( T_5 * V_20 , T_11 * * V_59 ,
T_8 * * V_58 , T_13 * * V_88 ,
T_13 * * V_89 )
{
if ( V_59 )
* V_59 = V_20 -> V_51 ;
if ( V_58 )
* V_58 = V_20 -> V_58 ;
if ( V_88 )
* V_88 = V_20 -> V_33 ;
if ( V_89 )
* V_89 = V_20 -> V_90 ;
}
T_6 * F_68 ( T_5 * V_20 )
{
return V_20 -> V_91 ;
}
static int F_69 ( T_2 * V_1 ,
T_5 * V_20 , T_18 * V_92 )
{
T_17 * V_67 = F_36 () ;
int V_85 = 0 ;
T_16 * V_68 = NULL ;
if ( V_67 == NULL ) {
F_3 ( V_93 , V_10 ) ;
return 0 ;
}
if ( ! V_20 -> V_51 ) {
F_3 ( V_93 , V_94 ) ;
goto V_65;
}
if ( ! F_70 ( V_67 , V_92 , V_20 -> V_33 ) )
goto V_65;
if ( V_20 -> V_68 && ! F_30 ( V_20 , 0 ) )
goto V_65;
if ( F_19 ( V_20 ) >= 0 ) {
T_14 * V_95 =
V_1 -> V_6 . V_7 -> V_12 -> V_13 ;
unsigned char V_60 [ V_96 ] ;
unsigned int V_97 ;
if ( ! F_71 ( V_67 , V_60 , & V_97 ) )
goto V_65;
if ( ! F_22 ( V_20 , V_35 ,
V_36 , V_60 , V_97 ) )
goto V_65;
if ( F_22 ( V_20 , V_98 ,
V_99 , V_95 , - 1 ) <= 0 )
goto V_65;
if ( ! F_51 ( V_20 ) )
goto V_65;
} else if ( V_20 -> V_68 ) {
unsigned char * V_100 ;
T_19 V_101 ;
unsigned char V_60 [ V_96 ] ;
unsigned int V_97 ;
V_68 = V_20 -> V_68 ;
if ( ! F_71 ( V_67 , V_60 , & V_97 ) )
goto V_65;
V_101 = F_72 ( V_20 -> V_51 ) ;
V_100 = F_73 ( V_101 ) ;
if ( V_100 == NULL ) {
F_3 ( V_93 , V_10 ) ;
goto V_65;
}
if ( F_74 ( V_68 , V_100 , & V_101 , V_60 , V_97 ) <= 0 ) {
F_75 ( V_100 ) ;
goto V_65;
}
F_76 ( V_20 -> V_91 , V_100 , V_101 ) ;
} else {
unsigned char * V_100 ;
unsigned int V_101 ;
V_100 = F_73 ( F_72 ( V_20 -> V_51 ) ) ;
if ( V_100 == NULL ) {
F_3 ( V_93 , V_10 ) ;
goto V_65;
}
if ( ! F_77 ( V_67 , V_100 , & V_101 , V_20 -> V_51 ) ) {
F_3 ( V_93 , V_102 ) ;
F_75 ( V_100 ) ;
goto V_65;
}
F_76 ( V_20 -> V_91 , V_100 , V_101 ) ;
}
V_85 = 1 ;
V_65:
F_78 ( V_67 ) ;
F_79 ( V_68 ) ;
return V_85 ;
}
int F_80 ( T_2 * V_1 , T_18 * V_92 )
{
F_17 ( T_5 ) * V_30 ;
T_5 * V_20 ;
int V_17 ;
V_30 = F_18 ( V_1 ) ;
for ( V_17 = 0 ; V_17 < F_14 ( V_30 ) ; V_17 ++ ) {
V_20 = F_15 ( V_30 , V_17 ) ;
if ( ! F_69 ( V_1 , V_20 , V_92 ) )
return 0 ;
}
V_1 -> V_6 . V_7 -> V_12 -> V_15 = 0 ;
return 1 ;
}
int F_51 ( T_5 * V_20 )
{
T_17 * V_67 = V_20 -> V_67 ;
T_16 * V_68 ;
unsigned char * V_103 = NULL ;
int V_104 ;
T_19 V_101 ;
const T_12 * V_60 = NULL ;
V_60 = F_81 ( V_20 -> V_33 -> V_34 ) ;
if ( V_60 == NULL )
return 0 ;
if ( F_82 ( V_20 , V_86 , - 1 ) < 0 ) {
if ( ! F_60 ( V_20 , NULL ) )
goto V_65;
}
if ( V_20 -> V_68 )
V_68 = V_20 -> V_68 ;
else {
F_83 ( V_67 ) ;
if ( F_56 ( V_67 , & V_68 , V_60 , NULL , V_20 -> V_51 ) <= 0 )
goto V_65;
}
if ( F_84 ( V_68 , - 1 , V_105 ,
V_106 , 0 , V_20 ) <= 0 ) {
F_3 ( V_107 , V_108 ) ;
goto V_65;
}
V_104 = F_85 ( ( V_109 * ) V_20 -> V_77 , & V_103 ,
F_86 ( V_110 ) ) ;
if ( ! V_103 )
goto V_65;
if ( F_87 ( V_67 , V_103 , V_104 ) <= 0 )
goto V_65;
if ( F_88 ( V_67 , NULL , & V_101 ) <= 0 )
goto V_65;
F_75 ( V_103 ) ;
V_103 = F_73 ( V_101 ) ;
if ( V_103 == NULL )
goto V_65;
if ( F_88 ( V_67 , V_103 , & V_101 ) <= 0 )
goto V_65;
if ( F_84 ( V_68 , - 1 , V_105 ,
V_106 , 1 , V_20 ) <= 0 ) {
F_3 ( V_107 , V_108 ) ;
goto V_65;
}
F_83 ( V_67 ) ;
F_76 ( V_20 -> V_91 , V_103 , V_101 ) ;
return 1 ;
V_65:
F_75 ( V_103 ) ;
F_83 ( V_67 ) ;
return 0 ;
}
int F_89 ( T_5 * V_20 )
{
T_17 * V_67 = NULL ;
unsigned char * V_103 = NULL ;
int V_104 , V_85 = - 1 ;
const T_12 * V_60 = NULL ;
if ( ! V_20 -> V_51 ) {
F_3 ( V_111 , V_112 ) ;
return - 1 ;
}
V_60 = F_81 ( V_20 -> V_33 -> V_34 ) ;
if ( V_60 == NULL )
return - 1 ;
if ( V_20 -> V_67 == NULL )
V_20 -> V_67 = F_36 () ;
V_67 = V_20 -> V_67 ;
if ( F_90 ( V_67 , & V_20 -> V_68 , V_60 , NULL , V_20 -> V_51 ) <= 0 )
goto V_65;
if ( ! F_30 ( V_20 , 1 ) )
goto V_65;
V_104 = F_85 ( ( V_109 * ) V_20 -> V_77 , & V_103 ,
F_86 ( V_113 ) ) ;
if ( ! V_103 )
goto V_65;
V_85 = F_91 ( V_67 , V_103 , V_104 ) ;
F_75 ( V_103 ) ;
if ( V_85 <= 0 ) {
V_85 = - 1 ;
goto V_65;
}
V_85 = F_92 ( V_67 ,
V_20 -> V_91 -> V_114 , V_20 -> V_91 -> V_115 ) ;
if ( V_85 <= 0 )
F_3 ( V_111 , V_116 ) ;
V_65:
F_83 ( V_67 ) ;
return V_85 ;
}
T_18 * F_93 ( T_2 * V_1 )
{
int V_17 ;
T_1 * V_16 ;
T_18 * V_92 = NULL ;
V_16 = F_1 ( V_1 ) ;
if ( ! V_16 )
return NULL ;
if ( V_1 -> V_6 . V_7 -> V_12 -> V_15 )
F_9 ( V_16 ) ;
for ( V_17 = 0 ; V_17 < F_40 ( V_16 -> V_73 ) ; V_17 ++ ) {
T_13 * V_33 ;
T_18 * V_117 ;
V_33 = F_41 ( V_16 -> V_73 , V_17 ) ;
V_117 = F_94 ( V_33 ) ;
if ( ! V_117 )
goto V_65;
if ( V_92 )
F_95 ( V_92 , V_117 ) ;
else
V_92 = V_117 ;
}
return V_92 ;
V_65:
F_96 ( V_92 ) ;
return NULL ;
}
int F_97 ( T_5 * V_20 , T_18 * V_92 )
{
T_6 * V_118 = NULL ;
T_17 * V_67 = F_36 () ;
T_16 * V_119 = NULL ;
int V_85 = - 1 ;
unsigned char V_120 [ V_96 ] ;
unsigned int V_121 ;
if ( V_67 == NULL ) {
F_3 ( V_122 , V_10 ) ;
goto V_65;
}
if ( F_19 ( V_20 ) >= 0 ) {
V_118 = F_21 ( V_20 ,
F_6 ( V_35 ) ,
- 3 , V_36 ) ;
if ( ! V_118 ) {
F_3 ( V_122 ,
V_38 ) ;
goto V_65;
}
}
if ( ! F_70 ( V_67 , V_92 , V_20 -> V_33 ) )
goto V_65;
if ( F_71 ( V_67 , V_120 , & V_121 ) <= 0 ) {
F_3 ( V_122 ,
V_123 ) ;
goto V_65;
}
if ( V_118 ) {
if ( V_121 != ( unsigned int ) V_118 -> V_115 ) {
F_3 ( V_122 ,
V_124 ) ;
goto V_65;
}
if ( memcmp ( V_120 , V_118 -> V_114 , V_121 ) ) {
F_3 ( V_122 ,
V_116 ) ;
V_85 = 0 ;
} else
V_85 = 1 ;
} else {
const T_12 * V_60 = F_98 ( V_67 ) ;
V_119 = F_53 ( V_20 -> V_51 , NULL ) ;
if ( V_119 == NULL )
goto V_65;
if ( F_99 ( V_119 ) <= 0 )
goto V_65;
if ( F_55 ( V_119 , V_60 ) <= 0 )
goto V_65;
V_20 -> V_68 = V_119 ;
if ( ! F_30 ( V_20 , 1 ) )
goto V_65;
V_85 = F_100 ( V_119 , V_20 -> V_91 -> V_114 ,
V_20 -> V_91 -> V_115 , V_120 , V_121 ) ;
if ( V_85 <= 0 ) {
F_3 ( V_122 ,
V_116 ) ;
V_85 = 0 ;
}
}
V_65:
F_79 ( V_119 ) ;
F_78 ( V_67 ) ;
return V_85 ;
}
