T_1 * F_1 ( T_2 * V_1 )
{
if ( F_2 ( V_1 -> V_2 ) != V_3 ) {
F_3 ( V_4 ,
V_5 ) ;
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
V_1 -> V_6 . V_7 -> V_11 = 0 ;
V_1 -> V_6 . V_7 -> V_12 -> V_2 =
F_6 ( V_13 ) ;
F_7 ( V_1 -> V_2 ) ;
V_1 -> V_2 = F_6 ( V_3 ) ;
return V_1 -> V_6 . V_7 ;
}
return F_1 ( V_1 ) ;
}
int F_8 ( T_3 * V_14 , int V_15 )
{
T_4 * V_16 ;
int V_17 ;
if ( V_14 -> type == V_18 )
V_16 = V_14 -> V_6 . V_19 -> V_16 ;
else if ( V_14 -> type == V_20 ) {
T_5 * V_21 = V_14 -> V_6 . V_22 -> V_21 ;
if ( ! V_21 )
return 0 ;
V_16 = F_9 ( V_21 ) ;
if ( ! V_16 )
return 0 ;
} else
return 0 ;
if ( ! V_16 -> V_23 || ! V_16 -> V_23 -> V_24 )
return 1 ;
V_17 = V_16 -> V_23 -> V_24 ( V_16 , V_25 , V_15 , V_14 ) ;
if ( V_17 == - 2 ) {
F_3 ( V_26 ,
V_27 ) ;
return 0 ;
}
if ( V_17 <= 0 ) {
F_3 ( V_26 , V_28 ) ;
return 0 ;
}
return 1 ;
}
T_5 * F_10 ( T_3 * V_14 )
{
if ( V_14 -> type == V_18 )
return V_14 -> V_6 . V_19 -> V_21 ;
else if ( V_14 -> type == V_20 )
return V_14 -> V_6 . V_22 -> V_21 ;
return NULL ;
}
T_2 * F_11 ( const T_6 * V_29 )
{
T_2 * V_1 ;
T_1 * V_30 ;
V_1 = F_12 () ;
if ( V_1 == NULL )
goto V_31;
V_30 = F_4 ( V_1 ) ;
if ( V_30 == NULL )
goto V_31;
if ( ! F_13 ( V_30 -> V_12 ,
V_29 , NULL , 0 ) )
goto V_31;
return V_1 ;
V_31:
F_14 ( V_1 ) ;
F_3 ( V_32 , V_10 ) ;
return NULL ;
}
static int F_15 ( T_3 * V_14 , T_7 * V_33 ,
T_4 * V_34 , unsigned int V_35 )
{
T_8 * V_19 ;
int V_36 ;
V_14 -> V_6 . V_19 = F_5 ( T_8 ) ;
if ( ! V_14 -> V_6 . V_19 )
return 0 ;
V_14 -> type = V_18 ;
V_19 = V_14 -> V_6 . V_19 ;
if ( V_35 & V_37 ) {
V_19 -> V_11 = 2 ;
V_36 = V_38 ;
} else {
V_19 -> V_11 = 0 ;
V_36 = V_39 ;
}
if ( ! F_16 ( V_19 -> V_40 , V_33 , V_36 ) )
return 0 ;
F_17 ( V_33 ) ;
F_18 ( V_34 ) ;
V_19 -> V_16 = V_34 ;
V_19 -> V_33 = V_33 ;
if ( V_35 & V_41 ) {
V_19 -> V_21 = F_19 ( V_19 -> V_16 , NULL ) ;
if ( V_19 -> V_21 == NULL )
return 0 ;
if ( F_20 ( V_19 -> V_21 ) <= 0 )
return 0 ;
} else if ( ! F_8 ( V_14 , 0 ) )
return 0 ;
return 1 ;
}
T_3 * F_21 ( T_2 * V_1 ,
T_7 * V_33 , unsigned int V_35 )
{
T_3 * V_14 = NULL ;
T_1 * V_30 ;
T_4 * V_34 = NULL ;
V_30 = F_1 ( V_1 ) ;
if ( ! V_30 )
goto V_42;
V_14 = F_5 ( T_3 ) ;
if ( ! V_14 )
goto V_31;
V_34 = F_22 ( V_33 ) ;
if ( ! V_34 ) {
F_3 ( V_43 , V_44 ) ;
goto V_42;
}
switch ( F_23 ( V_34 ) ) {
case V_18 :
if ( ! F_15 ( V_14 , V_33 , V_34 , V_35 ) )
goto V_42;
break;
case V_20 :
if ( ! F_24 ( V_14 , V_33 , V_34 , V_35 ) )
goto V_42;
break;
default:
F_3 ( V_43 ,
V_27 ) ;
goto V_42;
}
if ( ! F_25 ( V_30 -> V_45 , V_14 ) )
goto V_31;
return V_14 ;
V_31:
F_3 ( V_43 , V_10 ) ;
V_42:
F_26 ( V_14 , T_3 ) ;
return NULL ;
}
int F_27 ( T_3 * V_14 ,
T_4 * * V_34 , T_7 * * V_33 ,
T_9 * * V_46 )
{
T_8 * V_19 ;
if ( V_14 -> type != V_18 ) {
F_3 ( V_47 ,
V_48 ) ;
return 0 ;
}
V_19 = V_14 -> V_6 . V_19 ;
if ( V_34 )
* V_34 = V_19 -> V_16 ;
if ( V_33 )
* V_33 = V_19 -> V_33 ;
if ( V_46 )
* V_46 = V_19 -> V_49 ;
return 1 ;
}
int F_28 ( T_3 * V_14 ,
T_10 * * V_50 ,
T_11 * * V_51 ,
T_12 * * V_52 )
{
T_8 * V_19 ;
if ( V_14 -> type != V_18 ) {
F_3 ( V_53 ,
V_48 ) ;
return 0 ;
}
V_19 = V_14 -> V_6 . V_19 ;
return F_29 ( V_19 -> V_40 , V_50 , V_51 , V_52 ) ;
}
int F_30 ( T_3 * V_14 , T_7 * V_54 )
{
if ( V_14 -> type != V_18 ) {
F_3 ( V_55 ,
V_48 ) ;
return - 2 ;
}
return F_31 ( V_14 -> V_6 . V_19 -> V_40 , V_54 ) ;
}
int F_32 ( T_3 * V_14 , T_4 * V_16 )
{
if ( V_14 -> type != V_18 ) {
F_3 ( V_56 , V_48 ) ;
return 0 ;
}
V_14 -> V_6 . V_19 -> V_16 = V_16 ;
return 1 ;
}
static int F_33 ( T_2 * V_1 ,
T_3 * V_14 )
{
T_8 * V_19 ;
T_13 * V_57 ;
T_5 * V_21 ;
unsigned char * V_58 = NULL ;
T_14 V_59 ;
int V_60 = 0 ;
if ( V_14 -> type != V_18 ) {
F_3 ( V_61 , V_48 ) ;
return 0 ;
}
V_19 = V_14 -> V_6 . V_19 ;
V_57 = V_1 -> V_6 . V_7 -> V_12 ;
V_21 = V_19 -> V_21 ;
if ( V_21 ) {
if ( ! F_8 ( V_14 , 0 ) )
goto V_42;
} else {
V_21 = F_19 ( V_19 -> V_16 , NULL ) ;
if ( V_21 == NULL )
return 0 ;
if ( F_20 ( V_21 ) <= 0 )
goto V_42;
}
if ( F_34 ( V_21 , - 1 , V_62 ,
V_63 , 0 , V_14 ) <= 0 ) {
F_3 ( V_61 , V_64 ) ;
goto V_42;
}
if ( F_35 ( V_21 , NULL , & V_59 , V_57 -> V_65 , V_57 -> V_66 ) <= 0 )
goto V_42;
V_58 = F_36 ( V_59 ) ;
if ( V_58 == NULL ) {
F_3 ( V_61 , V_10 ) ;
goto V_42;
}
if ( F_35 ( V_21 , V_58 , & V_59 , V_57 -> V_65 , V_57 -> V_66 ) <= 0 )
goto V_42;
F_37 ( V_19 -> V_67 , V_58 , V_59 ) ;
V_58 = NULL ;
V_60 = 1 ;
V_42:
F_38 ( V_21 ) ;
V_19 -> V_21 = NULL ;
F_39 ( V_58 ) ;
return V_60 ;
}
static int F_40 ( T_2 * V_1 ,
T_3 * V_14 )
{
T_8 * V_19 = V_14 -> V_6 . V_19 ;
T_4 * V_16 = V_19 -> V_16 ;
unsigned char * V_58 = NULL ;
T_14 V_59 ;
int V_60 = 0 ;
T_13 * V_57 ;
V_57 = V_1 -> V_6 . V_7 -> V_12 ;
if ( V_19 -> V_16 == NULL ) {
F_3 ( V_68 , V_69 ) ;
return 0 ;
}
V_19 -> V_21 = F_19 ( V_16 , NULL ) ;
if ( V_19 -> V_21 == NULL )
return 0 ;
if ( F_41 ( V_19 -> V_21 ) <= 0 )
goto V_42;
if ( ! F_8 ( V_14 , 1 ) )
goto V_42;
if ( F_34 ( V_19 -> V_21 , - 1 , V_70 ,
V_71 , 0 , V_14 ) <= 0 ) {
F_3 ( V_68 , V_64 ) ;
goto V_42;
}
if ( F_42 ( V_19 -> V_21 , NULL , & V_59 ,
V_19 -> V_67 -> V_72 ,
V_19 -> V_67 -> V_73 ) <= 0 )
goto V_42;
V_58 = F_36 ( V_59 ) ;
if ( V_58 == NULL ) {
F_3 ( V_68 , V_10 ) ;
goto V_42;
}
if ( F_42 ( V_19 -> V_21 , V_58 , & V_59 ,
V_19 -> V_67 -> V_72 ,
V_19 -> V_67 -> V_73 ) <= 0 ) {
F_3 ( V_68 , V_74 ) ;
goto V_42;
}
V_60 = 1 ;
F_43 ( V_57 -> V_65 , V_57 -> V_66 ) ;
V_57 -> V_65 = V_58 ;
V_57 -> V_66 = V_59 ;
V_42:
F_38 ( V_19 -> V_21 ) ;
V_19 -> V_21 = NULL ;
if ( ! V_60 )
F_39 ( V_58 ) ;
return V_60 ;
}
int F_44 ( T_3 * V_14 ,
const unsigned char * V_75 , T_14 V_76 )
{
T_10 V_77 ;
T_15 * V_78 ;
if ( V_14 -> type != V_79 ) {
F_3 ( V_80 , V_81 ) ;
return - 2 ;
}
V_78 = V_14 -> V_6 . V_78 ;
V_77 . type = V_82 ;
V_77 . V_35 = 0 ;
V_77 . V_72 = ( unsigned char * ) V_75 ;
V_77 . V_73 = ( int ) V_76 ;
return F_45 ( & V_77 , V_78 -> V_83 -> V_84 ) ;
}
static T_14 F_46 ( int V_85 )
{
switch ( V_85 ) {
case V_86 :
return 16 ;
case V_87 :
return 24 ;
case V_88 :
return 32 ;
default:
return 0 ;
}
}
T_3 * F_47 ( T_2 * V_1 , int V_85 ,
unsigned char * V_65 , T_14 V_66 ,
unsigned char * V_75 , T_14 V_76 ,
T_16 * V_89 ,
T_17 * V_90 ,
T_18 * V_91 )
{
T_3 * V_14 = NULL ;
T_1 * V_30 ;
T_15 * V_78 ;
V_30 = F_1 ( V_1 ) ;
if ( ! V_30 )
goto V_42;
if ( V_85 == V_92 ) {
switch ( V_66 ) {
case 16 :
V_85 = V_86 ;
break;
case 24 :
V_85 = V_87 ;
break;
case 32 :
V_85 = V_88 ;
break;
default:
F_3 ( V_93 , V_94 ) ;
goto V_42;
}
} else {
T_14 V_95 = F_46 ( V_85 ) ;
if ( ! V_95 ) {
F_3 ( V_93 ,
V_96 ) ;
goto V_42;
}
if ( V_66 != V_95 ) {
F_3 ( V_93 , V_94 ) ;
goto V_42;
}
}
V_14 = F_5 ( T_3 ) ;
if ( ! V_14 )
goto V_31;
V_14 -> V_6 . V_78 = F_5 ( T_15 ) ;
if ( ! V_14 -> V_6 . V_78 )
goto V_31;
V_14 -> type = V_79 ;
V_78 = V_14 -> V_6 . V_78 ;
if ( V_90 ) {
V_78 -> V_83 -> V_8 = F_5 ( V_97 ) ;
if ( V_78 -> V_83 -> V_8 == NULL )
goto V_31;
}
if ( ! F_25 ( V_30 -> V_45 , V_14 ) )
goto V_31;
V_78 -> V_11 = 4 ;
V_78 -> V_65 = V_65 ;
V_78 -> V_66 = V_66 ;
F_37 ( V_78 -> V_83 -> V_84 , V_75 , V_76 ) ;
V_78 -> V_83 -> V_89 = V_89 ;
if ( V_78 -> V_83 -> V_8 ) {
V_78 -> V_83 -> V_8 -> V_98 = V_90 ;
V_78 -> V_83 -> V_8 -> V_99 = V_91 ;
}
F_48 ( V_78 -> V_49 ,
F_6 ( V_85 ) , V_100 , NULL ) ;
return V_14 ;
V_31:
F_3 ( V_93 , V_10 ) ;
V_42:
F_26 ( V_14 , T_3 ) ;
return NULL ;
}
int F_49 ( T_3 * V_14 ,
T_9 * * V_46 ,
T_10 * * V_101 ,
T_16 * * V_102 ,
T_17 * * V_103 ,
T_18 * * V_104 )
{
T_19 * V_105 ;
if ( V_14 -> type != V_79 ) {
F_3 ( V_106 , V_81 ) ;
return 0 ;
}
V_105 = V_14 -> V_6 . V_78 -> V_83 ;
if ( V_46 )
* V_46 = V_14 -> V_6 . V_78 -> V_49 ;
if ( V_101 )
* V_101 = V_105 -> V_84 ;
if ( V_102 )
* V_102 = V_105 -> V_89 ;
if ( V_103 ) {
if ( V_105 -> V_8 )
* V_103 = V_105 -> V_8 -> V_98 ;
else
* V_103 = NULL ;
}
if ( V_104 ) {
if ( V_105 -> V_8 )
* V_104 = V_105 -> V_8 -> V_99 ;
else
* V_104 = NULL ;
}
return 1 ;
}
int F_50 ( T_3 * V_14 ,
unsigned char * V_65 , T_14 V_66 )
{
T_15 * V_78 ;
if ( V_14 -> type != V_79 ) {
F_3 ( V_107 , V_81 ) ;
return 0 ;
}
V_78 = V_14 -> V_6 . V_78 ;
V_78 -> V_65 = V_65 ;
V_78 -> V_66 = V_66 ;
return 1 ;
}
static int F_51 ( T_2 * V_1 ,
T_3 * V_14 )
{
T_13 * V_57 ;
T_15 * V_78 ;
T_20 V_108 ;
unsigned char * V_109 = NULL ;
int V_110 ;
int V_111 = 0 ;
V_57 = V_1 -> V_6 . V_7 -> V_12 ;
V_78 = V_14 -> V_6 . V_78 ;
if ( ! V_78 -> V_65 ) {
F_3 ( V_112 , V_113 ) ;
return 0 ;
}
if ( F_52 ( V_78 -> V_65 , V_78 -> V_66 << 3 , & V_108 ) ) {
F_3 ( V_112 ,
V_114 ) ;
goto V_42;
}
V_109 = F_36 ( V_57 -> V_66 + 8 ) ;
if ( V_109 == NULL ) {
F_3 ( V_112 , V_10 ) ;
goto V_42;
}
V_110 = F_53 ( & V_108 , NULL , V_109 , V_57 -> V_65 , V_57 -> V_66 ) ;
if ( V_110 <= 0 ) {
F_3 ( V_112 , V_115 ) ;
goto V_42;
}
F_37 ( V_78 -> V_67 , V_109 , V_110 ) ;
V_111 = 1 ;
V_42:
if ( ! V_111 )
F_39 ( V_109 ) ;
F_54 ( & V_108 , sizeof( V_108 ) ) ;
return V_111 ;
}
static int F_55 ( T_2 * V_1 ,
T_3 * V_14 )
{
T_13 * V_57 ;
T_15 * V_78 ;
T_20 V_108 ;
unsigned char * V_116 = NULL ;
int V_117 ;
int V_111 = 0 , V_118 ;
V_57 = V_1 -> V_6 . V_7 -> V_12 ;
V_78 = V_14 -> V_6 . V_78 ;
if ( ! V_78 -> V_65 ) {
F_3 ( V_119 , V_113 ) ;
return 0 ;
}
V_118 = F_2 ( V_78 -> V_49 -> V_120 ) ;
if ( F_46 ( V_118 ) != V_78 -> V_66 ) {
F_3 ( V_119 ,
V_94 ) ;
return 0 ;
}
if ( V_78 -> V_67 -> V_73 < 16 ) {
F_3 ( V_119 ,
V_121 ) ;
goto V_42;
}
if ( F_56 ( V_78 -> V_65 , V_78 -> V_66 << 3 , & V_108 ) ) {
F_3 ( V_119 ,
V_114 ) ;
goto V_42;
}
V_116 = F_36 ( V_78 -> V_67 -> V_73 - 8 ) ;
if ( V_116 == NULL ) {
F_3 ( V_119 , V_10 ) ;
goto V_42;
}
V_117 = F_57 ( & V_108 , NULL , V_116 ,
V_78 -> V_67 -> V_72 ,
V_78 -> V_67 -> V_73 ) ;
if ( V_117 <= 0 ) {
F_3 ( V_119 , V_122 ) ;
goto V_42;
}
V_57 -> V_65 = V_116 ;
V_57 -> V_66 = V_117 ;
V_111 = 1 ;
V_42:
if ( ! V_111 )
F_39 ( V_116 ) ;
F_54 ( & V_108 , sizeof( V_108 ) ) ;
return V_111 ;
}
int F_58 ( T_2 * V_1 , T_3 * V_14 )
{
switch ( V_14 -> type ) {
case V_18 :
return F_40 ( V_1 , V_14 ) ;
case V_79 :
return F_55 ( V_1 , V_14 ) ;
case V_123 :
return F_59 ( V_1 , V_14 , 0 ) ;
default:
F_3 ( V_124 ,
V_125 ) ;
return 0 ;
}
}
int F_60 ( T_2 * V_1 , T_3 * V_14 )
{
switch ( V_14 -> type ) {
case V_18 :
return F_33 ( V_1 , V_14 ) ;
case V_20 :
return F_61 ( V_1 , V_14 ) ;
case V_79 :
return F_51 ( V_1 , V_14 ) ;
case V_123 :
return F_59 ( V_1 , V_14 , 1 ) ;
default:
F_3 ( V_126 ,
V_127 ) ;
return 0 ;
}
}
static void F_62 ( T_1 * V_30 )
{
T_21 * V_128 = V_30 -> V_129 ;
int V_17 ;
if ( V_128 == NULL )
return;
for ( V_17 = 0 ; V_17 < F_63 ( V_128 -> V_130 ) ; V_17 ++ ) {
T_22 * V_131 ;
V_131 = F_64 ( V_128 -> V_130 , V_17 ) ;
if ( V_131 -> type == V_132 ) {
V_30 -> V_11 = 4 ;
return;
} else if ( V_131 -> type == V_133 ) {
if ( V_30 -> V_11 < 3 )
V_30 -> V_11 = 3 ;
}
}
for ( V_17 = 0 ; V_17 < F_65 ( V_128 -> V_134 ) ; V_17 ++ ) {
T_23 * V_135 ;
V_135 = F_66 ( V_128 -> V_134 , V_17 ) ;
if ( V_135 -> type == V_136 ) {
V_30 -> V_11 = 4 ;
return;
}
}
}
static void F_67 ( T_1 * V_30 )
{
int V_17 ;
T_3 * V_14 ;
if ( V_30 -> V_11 >= 4 )
return;
F_62 ( V_30 ) ;
if ( V_30 -> V_11 >= 3 )
return;
for ( V_17 = 0 ; V_17 < F_68 ( V_30 -> V_45 ) ; V_17 ++ ) {
V_14 = F_69 ( V_30 -> V_45 , V_17 ) ;
if ( V_14 -> type == V_123 || V_14 -> type == V_137 ) {
V_30 -> V_11 = 3 ;
return;
} else if ( V_14 -> type != V_18
|| V_14 -> V_6 . V_19 -> V_11 != 0 ) {
V_30 -> V_11 = 2 ;
}
}
if ( V_30 -> V_129 || V_30 -> V_138 )
V_30 -> V_11 = 2 ;
if ( V_30 -> V_11 == 2 )
return;
V_30 -> V_11 = 0 ;
}
T_24 * F_70 ( T_2 * V_1 )
{
T_13 * V_57 ;
F_71 ( T_3 ) * V_139 ;
T_3 * V_14 ;
int V_17 , V_140 = 0 ;
T_24 * V_60 ;
V_57 = V_1 -> V_6 . V_7 -> V_12 ;
V_60 = F_72 ( V_57 ) ;
if ( ! V_60 || ! V_57 -> V_29 )
return V_60 ;
V_139 = V_1 -> V_6 . V_7 -> V_45 ;
for ( V_17 = 0 ; V_17 < F_68 ( V_139 ) ; V_17 ++ ) {
V_14 = F_69 ( V_139 , V_17 ) ;
if ( F_60 ( V_1 , V_14 ) <= 0 ) {
F_3 ( V_141 ,
V_142 ) ;
goto V_42;
}
}
F_67 ( V_1 -> V_6 . V_7 ) ;
V_140 = 1 ;
V_42:
V_57 -> V_29 = NULL ;
F_43 ( V_57 -> V_65 , V_57 -> V_66 ) ;
V_57 -> V_65 = NULL ;
V_57 -> V_66 = 0 ;
if ( V_140 )
return V_60 ;
F_73 ( V_60 ) ;
return NULL ;
}
int F_23 ( T_4 * V_34 )
{
if ( V_34 -> V_23 && V_34 -> V_23 -> V_24 ) {
int V_17 , V_111 ;
V_17 = V_34 -> V_23 -> V_24 ( V_34 , V_143 , 0 , & V_111 ) ;
if ( V_17 > 0 )
return V_111 ;
}
return V_18 ;
}
