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
F_34 ( & V_59 -> V_67 , 1 , V_68 ) ;
F_34 ( & V_58 -> V_67 , 1 , V_69 ) ;
V_20 -> V_51 = V_59 ;
V_20 -> V_58 = V_58 ;
F_35 ( & V_20 -> V_70 ) ;
V_20 -> V_71 = NULL ;
if ( V_61 & V_72 ) {
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
int V_73 ;
if ( F_36 ( V_59 , & V_73 ) <= 0 )
goto V_65;
V_60 = F_37 ( V_73 ) ;
if ( V_60 == NULL ) {
F_3 ( V_63 , V_74 ) ;
goto V_65;
}
}
if ( ! V_60 ) {
F_3 ( V_63 , V_75 ) ;
goto V_65;
}
F_38 ( V_20 -> V_33 , V_60 ) ;
for ( V_17 = 0 ; V_17 < F_39 ( V_16 -> V_76 ) ; V_17 ++ ) {
T_14 * V_77 ;
V_62 = F_40 ( V_16 -> V_76 , V_17 ) ;
F_41 ( & V_77 , NULL , NULL , V_62 ) ;
if ( F_2 ( V_77 ) == F_42 ( V_60 ) )
break;
}
if ( V_17 == F_39 ( V_16 -> V_76 ) ) {
V_62 = F_43 () ;
if ( ! V_62 )
goto V_66;
F_38 ( V_62 , V_60 ) ;
if ( ! F_44 ( V_16 -> V_76 , V_62 ) ) {
F_45 ( V_62 ) ;
goto V_66;
}
}
if ( ! ( V_61 & V_78 ) && ! F_30 ( V_20 , 0 ) )
goto V_65;
if ( ! ( V_61 & V_79 ) ) {
if ( ! V_20 -> V_80 ) {
V_20 -> V_80 = F_46 () ;
if ( ! V_20 -> V_80 )
goto V_66;
}
if ( ! ( V_61 & V_81 ) ) {
F_17 ( T_13 ) * V_82 = NULL ;
V_17 = F_47 ( & V_82 ) ;
if ( V_17 )
V_17 = F_48 ( V_20 , V_82 ) ;
F_49 ( V_82 , F_45 ) ;
if ( ! V_17 )
goto V_66;
}
if ( V_61 & V_83 ) {
if ( ! F_16 ( V_1 , V_20 ) )
goto V_65;
if ( ! ( V_61 & ( V_84 | V_78 ) ) &&
! F_50 ( V_20 ) )
goto V_65;
}
}
if ( ! ( V_61 & V_85 ) ) {
if ( ! F_51 ( V_1 , V_58 ) )
goto V_66;
}
if ( V_61 & V_78 ) {
if ( V_61 & V_79 ) {
V_20 -> V_71 = F_52 ( V_20 -> V_51 , NULL ) ;
if ( ! V_20 -> V_71 )
goto V_65;
if ( F_53 ( V_20 -> V_71 ) <= 0 )
goto V_65;
if ( F_54 ( V_20 -> V_71 , V_60 ) <= 0 )
goto V_65;
} else if ( F_55 ( & V_20 -> V_70 , & V_20 -> V_71 , V_60 , NULL , V_59 ) <=
0 )
goto V_65;
}
if ( ! V_16 -> V_27 )
V_16 -> V_27 = F_56 () ;
if ( ! V_16 -> V_27 || ! F_57 ( V_16 -> V_27 , V_20 ) )
goto V_66;
return V_20 ;
V_66:
F_3 ( V_63 , V_10 ) ;
V_65:
if ( V_20 )
F_58 ( V_20 , T_5 ) ;
return NULL ;
}
static int F_59 ( T_5 * V_20 , T_15 * V_86 )
{
T_15 * V_87 ;
int V_88 = 0 ;
if ( V_86 )
V_87 = V_86 ;
else
V_87 = F_60 ( NULL , 0 ) ;
if ( ! V_87 )
goto V_66;
if ( F_22 ( V_20 , V_89 ,
V_87 -> type , V_87 , - 1 ) <= 0 )
goto V_66;
V_88 = 1 ;
V_66:
if ( ! V_86 )
F_61 ( V_87 ) ;
if ( ! V_88 )
F_3 ( V_90 , V_10 ) ;
return V_88 ;
}
T_16 * F_62 ( T_5 * V_20 )
{
return V_20 -> V_71 ;
}
T_17 * F_63 ( T_5 * V_20 )
{
return & V_20 -> V_70 ;
}
int F_64 ( T_5 * V_20 ,
T_6 * * V_46 ,
T_9 * * V_47 , T_10 * * V_48 )
{
return F_26 ( V_20 -> V_28 , V_46 , V_47 , V_48 ) ;
}
int F_65 ( T_5 * V_20 , T_8 * V_40 )
{
return F_27 ( V_20 -> V_28 , V_40 ) ;
}
void F_66 ( T_5 * V_20 , T_11 * * V_59 ,
T_8 * * V_58 , T_13 * * V_91 ,
T_13 * * V_92 )
{
if ( V_59 )
* V_59 = V_20 -> V_51 ;
if ( V_58 )
* V_58 = V_20 -> V_58 ;
if ( V_91 )
* V_91 = V_20 -> V_33 ;
if ( V_92 )
* V_92 = V_20 -> V_93 ;
}
T_6 * F_67 ( T_5 * V_20 )
{
return V_20 -> V_94 ;
}
static int F_68 ( T_2 * V_1 ,
T_5 * V_20 , T_18 * V_95 )
{
T_17 V_70 ;
int V_88 = 0 ;
T_16 * V_71 = NULL ;
F_35 ( & V_70 ) ;
if ( ! V_20 -> V_51 ) {
F_3 ( V_96 , V_97 ) ;
return 0 ;
}
if ( ! F_69 ( & V_70 , V_95 , V_20 -> V_33 ) )
goto V_65;
if ( V_20 -> V_71 && ! F_30 ( V_20 , 0 ) )
goto V_65;
if ( F_19 ( V_20 ) >= 0 ) {
T_14 * V_98 =
V_1 -> V_6 . V_7 -> V_12 -> V_13 ;
unsigned char V_60 [ V_99 ] ;
unsigned int V_100 ;
if ( ! F_70 ( & V_70 , V_60 , & V_100 ) )
goto V_65;
if ( ! F_22 ( V_20 , V_35 ,
V_36 , V_60 , V_100 ) )
goto V_65;
if ( F_22 ( V_20 , V_101 ,
V_102 , V_98 , - 1 ) <= 0 )
goto V_65;
if ( ! F_50 ( V_20 ) )
goto V_65;
} else if ( V_20 -> V_71 ) {
unsigned char * V_103 ;
T_19 V_104 ;
unsigned char V_60 [ V_99 ] ;
unsigned int V_100 ;
V_71 = V_20 -> V_71 ;
if ( ! F_70 ( & V_70 , V_60 , & V_100 ) )
goto V_65;
V_104 = F_71 ( V_20 -> V_51 ) ;
V_103 = F_72 ( V_104 ) ;
if ( ! V_103 ) {
F_3 ( V_96 , V_10 ) ;
goto V_65;
}
if ( F_73 ( V_71 , V_103 , & V_104 , V_60 , V_100 ) <= 0 )
goto V_65;
F_74 ( V_20 -> V_94 , V_103 , V_104 ) ;
} else {
unsigned char * V_103 ;
unsigned int V_104 ;
V_103 = F_72 ( F_71 ( V_20 -> V_51 ) ) ;
if ( ! V_103 ) {
F_3 ( V_96 , V_10 ) ;
goto V_65;
}
if ( ! F_75 ( & V_70 , V_103 , & V_104 , V_20 -> V_51 ) ) {
F_3 ( V_96 , V_105 ) ;
F_76 ( V_103 ) ;
goto V_65;
}
F_74 ( V_20 -> V_94 , V_103 , V_104 ) ;
}
V_88 = 1 ;
V_65:
F_77 ( & V_70 ) ;
if ( V_71 )
F_78 ( V_71 ) ;
return V_88 ;
}
int F_79 ( T_2 * V_1 , T_18 * V_95 )
{
F_17 ( T_5 ) * V_30 ;
T_5 * V_20 ;
int V_17 ;
V_30 = F_18 ( V_1 ) ;
for ( V_17 = 0 ; V_17 < F_14 ( V_30 ) ; V_17 ++ ) {
V_20 = F_15 ( V_30 , V_17 ) ;
if ( ! F_68 ( V_1 , V_20 , V_95 ) )
return 0 ;
}
V_1 -> V_6 . V_7 -> V_12 -> V_15 = 0 ;
return 1 ;
}
int F_50 ( T_5 * V_20 )
{
T_17 * V_70 = & V_20 -> V_70 ;
T_16 * V_71 ;
unsigned char * V_106 = NULL ;
int V_107 ;
T_19 V_104 ;
const T_12 * V_60 = NULL ;
V_60 = F_80 ( V_20 -> V_33 -> V_34 ) ;
if ( V_60 == NULL )
return 0 ;
if ( F_81 ( V_20 , V_89 , - 1 ) < 0 ) {
if ( ! F_59 ( V_20 , NULL ) )
goto V_65;
}
if ( V_20 -> V_71 )
V_71 = V_20 -> V_71 ;
else {
F_35 ( V_70 ) ;
if ( F_55 ( V_70 , & V_71 , V_60 , NULL , V_20 -> V_51 ) <= 0 )
goto V_65;
}
if ( F_82 ( V_71 , - 1 , V_108 ,
V_109 , 0 , V_20 ) <= 0 ) {
F_3 ( V_110 , V_111 ) ;
goto V_65;
}
V_107 = F_83 ( ( V_112 * ) V_20 -> V_80 , & V_106 ,
F_84 ( V_113 ) ) ;
if ( ! V_106 )
goto V_65;
if ( F_85 ( V_70 , V_106 , V_107 ) <= 0 )
goto V_65;
if ( F_86 ( V_70 , NULL , & V_104 ) <= 0 )
goto V_65;
F_76 ( V_106 ) ;
V_106 = F_72 ( V_104 ) ;
if ( ! V_106 )
goto V_65;
if ( F_86 ( V_70 , V_106 , & V_104 ) <= 0 )
goto V_65;
if ( F_82 ( V_71 , - 1 , V_108 ,
V_109 , 1 , V_20 ) <= 0 ) {
F_3 ( V_110 , V_111 ) ;
goto V_65;
}
F_77 ( V_70 ) ;
F_74 ( V_20 -> V_94 , V_106 , V_104 ) ;
return 1 ;
V_65:
if ( V_106 )
F_76 ( V_106 ) ;
F_77 ( V_70 ) ;
return 0 ;
}
int F_87 ( T_5 * V_20 )
{
T_17 * V_70 = & V_20 -> V_70 ;
unsigned char * V_106 = NULL ;
int V_107 , V_88 = - 1 ;
const T_12 * V_60 = NULL ;
if ( ! V_20 -> V_51 ) {
F_3 ( V_114 , V_115 ) ;
return - 1 ;
}
V_60 = F_80 ( V_20 -> V_33 -> V_34 ) ;
if ( V_60 == NULL )
return - 1 ;
F_35 ( V_70 ) ;
if ( F_88 ( V_70 , & V_20 -> V_71 , V_60 , NULL , V_20 -> V_51 ) <= 0 )
goto V_65;
if ( ! F_30 ( V_20 , 1 ) )
goto V_65;
V_107 = F_83 ( ( V_112 * ) V_20 -> V_80 , & V_106 ,
F_84 ( V_116 ) ) ;
if ( ! V_106 )
goto V_65;
V_88 = F_89 ( V_70 , V_106 , V_107 ) ;
F_76 ( V_106 ) ;
if ( V_88 <= 0 ) {
V_88 = - 1 ;
goto V_65;
}
V_88 = F_90 ( V_70 ,
V_20 -> V_94 -> V_117 , V_20 -> V_94 -> V_118 ) ;
if ( V_88 <= 0 )
F_3 ( V_114 , V_119 ) ;
V_65:
F_77 ( V_70 ) ;
return V_88 ;
}
T_18 * F_91 ( T_2 * V_1 )
{
int V_17 ;
T_1 * V_16 ;
T_18 * V_95 = NULL ;
V_16 = F_1 ( V_1 ) ;
if ( ! V_16 )
return NULL ;
if ( V_1 -> V_6 . V_7 -> V_12 -> V_15 )
F_9 ( V_16 ) ;
for ( V_17 = 0 ; V_17 < F_39 ( V_16 -> V_76 ) ; V_17 ++ ) {
T_13 * V_33 ;
T_18 * V_120 ;
V_33 = F_40 ( V_16 -> V_76 , V_17 ) ;
V_120 = F_92 ( V_33 ) ;
if ( ! V_120 )
goto V_65;
if ( V_95 )
F_93 ( V_95 , V_120 ) ;
else
V_95 = V_120 ;
}
return V_95 ;
V_65:
if ( V_95 )
F_94 ( V_95 ) ;
return NULL ;
}
int F_95 ( T_5 * V_20 , T_18 * V_95 )
{
T_6 * V_121 = NULL ;
T_17 V_70 ;
T_16 * V_122 = NULL ;
int V_88 = - 1 ;
unsigned char V_123 [ V_99 ] ;
unsigned int V_124 ;
F_35 ( & V_70 ) ;
if ( F_19 ( V_20 ) >= 0 ) {
V_121 = F_21 ( V_20 ,
F_6 ( V_35 ) ,
- 3 , V_36 ) ;
if ( ! V_121 ) {
F_3 ( V_125 ,
V_38 ) ;
goto V_65;
}
}
if ( ! F_69 ( & V_70 , V_95 , V_20 -> V_33 ) )
goto V_65;
if ( F_70 ( & V_70 , V_123 , & V_124 ) <= 0 ) {
F_3 ( V_125 ,
V_126 ) ;
goto V_65;
}
if ( V_121 ) {
if ( V_124 != ( unsigned int ) V_121 -> V_118 ) {
F_3 ( V_125 ,
V_127 ) ;
goto V_65;
}
if ( memcmp ( V_123 , V_121 -> V_117 , V_124 ) ) {
F_3 ( V_125 ,
V_119 ) ;
V_88 = 0 ;
} else
V_88 = 1 ;
} else {
const T_12 * V_60 = F_96 ( & V_70 ) ;
V_122 = F_52 ( V_20 -> V_51 , NULL ) ;
if ( F_97 ( V_122 ) <= 0 )
goto V_65;
if ( F_54 ( V_122 , V_60 ) <= 0 )
goto V_65;
V_20 -> V_71 = V_122 ;
if ( ! F_30 ( V_20 , 1 ) )
goto V_65;
V_88 = F_98 ( V_122 , V_20 -> V_94 -> V_117 ,
V_20 -> V_94 -> V_118 , V_123 , V_124 ) ;
if ( V_88 <= 0 ) {
F_3 ( V_125 ,
V_119 ) ;
V_88 = 0 ;
}
}
V_65:
if ( V_122 )
F_78 ( V_122 ) ;
F_77 ( & V_70 ) ;
return V_88 ;
}
