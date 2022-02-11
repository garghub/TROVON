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
if ( ! V_1 )
goto V_31;
V_30 = F_4 ( V_1 ) ;
if ( ! V_30 )
goto V_31;
if ( ! F_13 ( V_30 -> V_12 ,
V_29 , NULL , 0 ) )
goto V_31;
return V_1 ;
V_31:
if ( V_1 )
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
F_17 ( & V_33 -> V_41 , 1 , V_42 ) ;
F_17 ( & V_34 -> V_41 , 1 , V_43 ) ;
V_19 -> V_16 = V_34 ;
V_19 -> V_33 = V_33 ;
if ( V_35 & V_44 ) {
V_19 -> V_21 = F_18 ( V_19 -> V_16 , NULL ) ;
if ( ! V_19 -> V_21 )
return 0 ;
if ( F_19 ( V_19 -> V_21 ) <= 0 )
return 0 ;
} else if ( ! F_8 ( V_14 , 0 ) )
return 0 ;
return 1 ;
}
T_3 * F_20 ( T_2 * V_1 ,
T_7 * V_33 , unsigned int V_35 )
{
T_3 * V_14 = NULL ;
T_1 * V_30 ;
T_4 * V_34 = NULL ;
V_30 = F_1 ( V_1 ) ;
if ( ! V_30 )
goto V_45;
V_14 = F_5 ( T_3 ) ;
if ( ! V_14 )
goto V_31;
V_34 = F_21 ( V_33 ) ;
if ( ! V_34 ) {
F_3 ( V_46 , V_47 ) ;
goto V_45;
}
switch ( F_22 ( V_34 ) ) {
case V_18 :
if ( ! F_15 ( V_14 , V_33 , V_34 , V_35 ) )
goto V_45;
break;
case V_20 :
if ( ! F_23 ( V_14 , V_33 , V_34 , V_35 ) )
goto V_45;
break;
default:
F_3 ( V_46 ,
V_27 ) ;
goto V_45;
}
if ( ! F_24 ( V_30 -> V_48 , V_14 ) )
goto V_31;
F_25 ( V_34 ) ;
return V_14 ;
V_31:
F_3 ( V_46 , V_10 ) ;
V_45:
if ( V_14 )
F_26 ( V_14 , T_3 ) ;
if ( V_34 )
F_25 ( V_34 ) ;
return NULL ;
}
int F_27 ( T_3 * V_14 ,
T_4 * * V_34 , T_7 * * V_33 ,
T_9 * * V_49 )
{
T_8 * V_19 ;
if ( V_14 -> type != V_18 ) {
F_3 ( V_50 ,
V_51 ) ;
return 0 ;
}
V_19 = V_14 -> V_6 . V_19 ;
if ( V_34 )
* V_34 = V_19 -> V_16 ;
if ( V_33 )
* V_33 = V_19 -> V_33 ;
if ( V_49 )
* V_49 = V_19 -> V_52 ;
return 1 ;
}
int F_28 ( T_3 * V_14 ,
T_10 * * V_53 ,
T_11 * * V_54 ,
T_12 * * V_55 )
{
T_8 * V_19 ;
if ( V_14 -> type != V_18 ) {
F_3 ( V_56 ,
V_51 ) ;
return 0 ;
}
V_19 = V_14 -> V_6 . V_19 ;
return F_29 ( V_19 -> V_40 , V_53 , V_54 , V_55 ) ;
}
int F_30 ( T_3 * V_14 , T_7 * V_57 )
{
if ( V_14 -> type != V_18 ) {
F_3 ( V_58 ,
V_51 ) ;
return - 2 ;
}
return F_31 ( V_14 -> V_6 . V_19 -> V_40 , V_57 ) ;
}
int F_32 ( T_3 * V_14 , T_4 * V_16 )
{
if ( V_14 -> type != V_18 ) {
F_3 ( V_59 , V_51 ) ;
return 0 ;
}
V_14 -> V_6 . V_19 -> V_16 = V_16 ;
return 1 ;
}
static int F_33 ( T_2 * V_1 ,
T_3 * V_14 )
{
T_8 * V_19 ;
T_13 * V_60 ;
T_5 * V_21 ;
unsigned char * V_61 = NULL ;
T_14 V_62 ;
int V_63 = 0 ;
if ( V_14 -> type != V_18 ) {
F_3 ( V_64 , V_51 ) ;
return 0 ;
}
V_19 = V_14 -> V_6 . V_19 ;
V_60 = V_1 -> V_6 . V_7 -> V_12 ;
V_21 = V_19 -> V_21 ;
if ( V_21 ) {
if ( ! F_8 ( V_14 , 0 ) )
goto V_45;
} else {
V_21 = F_18 ( V_19 -> V_16 , NULL ) ;
if ( ! V_21 )
return 0 ;
if ( F_19 ( V_21 ) <= 0 )
goto V_45;
}
if ( F_34 ( V_21 , - 1 , V_65 ,
V_66 , 0 , V_14 ) <= 0 ) {
F_3 ( V_64 , V_67 ) ;
goto V_45;
}
if ( F_35 ( V_21 , NULL , & V_62 , V_60 -> V_68 , V_60 -> V_69 ) <= 0 )
goto V_45;
V_61 = F_36 ( V_62 ) ;
if ( V_61 == NULL ) {
F_3 ( V_64 , V_10 ) ;
goto V_45;
}
if ( F_35 ( V_21 , V_61 , & V_62 , V_60 -> V_68 , V_60 -> V_69 ) <= 0 )
goto V_45;
F_37 ( V_19 -> V_70 , V_61 , V_62 ) ;
V_61 = NULL ;
V_63 = 1 ;
V_45:
if ( V_21 ) {
F_38 ( V_21 ) ;
V_19 -> V_21 = NULL ;
}
if ( V_61 )
F_39 ( V_61 ) ;
return V_63 ;
}
static int F_40 ( T_2 * V_1 ,
T_3 * V_14 )
{
T_8 * V_19 = V_14 -> V_6 . V_19 ;
T_4 * V_16 = V_19 -> V_16 ;
unsigned char * V_61 = NULL ;
T_14 V_62 ;
int V_63 = 0 ;
T_13 * V_60 ;
V_60 = V_1 -> V_6 . V_7 -> V_12 ;
if ( V_19 -> V_16 == NULL ) {
F_3 ( V_71 , V_72 ) ;
return 0 ;
}
V_19 -> V_21 = F_18 ( V_16 , NULL ) ;
if ( ! V_19 -> V_21 )
return 0 ;
if ( F_41 ( V_19 -> V_21 ) <= 0 )
goto V_45;
if ( ! F_8 ( V_14 , 1 ) )
goto V_45;
if ( F_34 ( V_19 -> V_21 , - 1 , V_73 ,
V_74 , 0 , V_14 ) <= 0 ) {
F_3 ( V_71 , V_67 ) ;
goto V_45;
}
if ( F_42 ( V_19 -> V_21 , NULL , & V_62 ,
V_19 -> V_70 -> V_75 ,
V_19 -> V_70 -> V_76 ) <= 0 )
goto V_45;
V_61 = F_36 ( V_62 ) ;
if ( V_61 == NULL ) {
F_3 ( V_71 , V_10 ) ;
goto V_45;
}
if ( F_42 ( V_19 -> V_21 , V_61 , & V_62 ,
V_19 -> V_70 -> V_75 ,
V_19 -> V_70 -> V_76 ) <= 0 ) {
F_3 ( V_71 , V_77 ) ;
goto V_45;
}
V_63 = 1 ;
if ( V_60 -> V_68 ) {
F_43 ( V_60 -> V_68 , V_60 -> V_69 ) ;
F_39 ( V_60 -> V_68 ) ;
}
V_60 -> V_68 = V_61 ;
V_60 -> V_69 = V_62 ;
V_45:
if ( V_19 -> V_21 ) {
F_38 ( V_19 -> V_21 ) ;
V_19 -> V_21 = NULL ;
}
if ( ! V_63 && V_61 )
F_39 ( V_61 ) ;
return V_63 ;
}
int F_44 ( T_3 * V_14 ,
const unsigned char * V_78 , T_14 V_79 )
{
T_10 V_80 ;
T_15 * V_81 ;
if ( V_14 -> type != V_82 ) {
F_3 ( V_83 , V_84 ) ;
return - 2 ;
}
V_81 = V_14 -> V_6 . V_81 ;
V_80 . type = V_85 ;
V_80 . V_35 = 0 ;
V_80 . V_75 = ( unsigned char * ) V_78 ;
V_80 . V_76 = ( int ) V_79 ;
return F_45 ( & V_80 , V_81 -> V_86 -> V_87 ) ;
}
static T_14 F_46 ( int V_88 )
{
switch ( V_88 ) {
case V_89 :
return 16 ;
case V_90 :
return 24 ;
case V_91 :
return 32 ;
default:
return 0 ;
}
}
T_3 * F_47 ( T_2 * V_1 , int V_88 ,
unsigned char * V_68 , T_14 V_69 ,
unsigned char * V_78 , T_14 V_79 ,
T_16 * V_92 ,
T_17 * V_93 ,
T_18 * V_94 )
{
T_3 * V_14 = NULL ;
T_1 * V_30 ;
T_15 * V_81 ;
V_30 = F_1 ( V_1 ) ;
if ( ! V_30 )
goto V_45;
if ( V_88 == V_95 ) {
switch ( V_69 ) {
case 16 :
V_88 = V_89 ;
break;
case 24 :
V_88 = V_90 ;
break;
case 32 :
V_88 = V_91 ;
break;
default:
F_3 ( V_96 , V_97 ) ;
goto V_45;
}
} else {
T_14 V_98 = F_46 ( V_88 ) ;
if ( ! V_98 ) {
F_3 ( V_96 ,
V_99 ) ;
goto V_45;
}
if ( V_69 != V_98 ) {
F_3 ( V_96 , V_97 ) ;
goto V_45;
}
}
V_14 = F_5 ( T_3 ) ;
if ( ! V_14 )
goto V_31;
V_14 -> V_6 . V_81 = F_5 ( T_15 ) ;
if ( ! V_14 -> V_6 . V_81 )
goto V_31;
V_14 -> type = V_82 ;
V_81 = V_14 -> V_6 . V_81 ;
if ( V_93 ) {
V_81 -> V_86 -> V_8 = F_5 ( V_100 ) ;
if ( V_81 -> V_86 -> V_8 == NULL )
goto V_31;
}
if ( ! F_24 ( V_30 -> V_48 , V_14 ) )
goto V_31;
V_81 -> V_11 = 4 ;
V_81 -> V_68 = V_68 ;
V_81 -> V_69 = V_69 ;
F_37 ( V_81 -> V_86 -> V_87 , V_78 , V_79 ) ;
V_81 -> V_86 -> V_92 = V_92 ;
if ( V_81 -> V_86 -> V_8 ) {
V_81 -> V_86 -> V_8 -> V_101 = V_93 ;
V_81 -> V_86 -> V_8 -> V_102 = V_94 ;
}
F_48 ( V_81 -> V_52 ,
F_6 ( V_88 ) , V_103 , NULL ) ;
return V_14 ;
V_31:
F_3 ( V_96 , V_10 ) ;
V_45:
if ( V_14 )
F_26 ( V_14 , T_3 ) ;
return NULL ;
}
int F_49 ( T_3 * V_14 ,
T_9 * * V_49 ,
T_10 * * V_104 ,
T_16 * * V_105 ,
T_17 * * V_106 ,
T_18 * * V_107 )
{
T_19 * V_108 ;
if ( V_14 -> type != V_82 ) {
F_3 ( V_109 , V_84 ) ;
return 0 ;
}
V_108 = V_14 -> V_6 . V_81 -> V_86 ;
if ( V_49 )
* V_49 = V_14 -> V_6 . V_81 -> V_52 ;
if ( V_104 )
* V_104 = V_108 -> V_87 ;
if ( V_105 )
* V_105 = V_108 -> V_92 ;
if ( V_106 ) {
if ( V_108 -> V_8 )
* V_106 = V_108 -> V_8 -> V_101 ;
else
* V_106 = NULL ;
}
if ( V_107 ) {
if ( V_108 -> V_8 )
* V_107 = V_108 -> V_8 -> V_102 ;
else
* V_107 = NULL ;
}
return 1 ;
}
int F_50 ( T_3 * V_14 ,
unsigned char * V_68 , T_14 V_69 )
{
T_15 * V_81 ;
if ( V_14 -> type != V_82 ) {
F_3 ( V_110 , V_84 ) ;
return 0 ;
}
V_81 = V_14 -> V_6 . V_81 ;
V_81 -> V_68 = V_68 ;
V_81 -> V_69 = V_69 ;
return 1 ;
}
static int F_51 ( T_2 * V_1 ,
T_3 * V_14 )
{
T_13 * V_60 ;
T_15 * V_81 ;
T_20 V_111 ;
unsigned char * V_112 = NULL ;
int V_113 ;
int V_114 = 0 ;
V_60 = V_1 -> V_6 . V_7 -> V_12 ;
V_81 = V_14 -> V_6 . V_81 ;
if ( ! V_81 -> V_68 ) {
F_3 ( V_115 , V_116 ) ;
return 0 ;
}
if ( F_52 ( V_81 -> V_68 , V_81 -> V_69 << 3 , & V_111 ) ) {
F_3 ( V_115 ,
V_117 ) ;
goto V_45;
}
V_112 = F_36 ( V_60 -> V_69 + 8 ) ;
if ( ! V_112 ) {
F_3 ( V_115 , V_10 ) ;
goto V_45;
}
V_113 = F_53 ( & V_111 , NULL , V_112 , V_60 -> V_68 , V_60 -> V_69 ) ;
if ( V_113 <= 0 ) {
F_3 ( V_115 , V_118 ) ;
goto V_45;
}
F_37 ( V_81 -> V_70 , V_112 , V_113 ) ;
V_114 = 1 ;
V_45:
if ( ! V_114 && V_112 )
F_39 ( V_112 ) ;
F_43 ( & V_111 , sizeof( V_111 ) ) ;
return V_114 ;
}
static int F_54 ( T_2 * V_1 ,
T_3 * V_14 )
{
T_13 * V_60 ;
T_15 * V_81 ;
T_20 V_111 ;
unsigned char * V_119 = NULL ;
int V_120 ;
int V_114 = 0 , V_121 ;
V_60 = V_1 -> V_6 . V_7 -> V_12 ;
V_81 = V_14 -> V_6 . V_81 ;
if ( ! V_81 -> V_68 ) {
F_3 ( V_122 , V_116 ) ;
return 0 ;
}
V_121 = F_2 ( V_81 -> V_52 -> V_123 ) ;
if ( F_46 ( V_121 ) != V_81 -> V_69 ) {
F_3 ( V_122 ,
V_97 ) ;
return 0 ;
}
if ( V_81 -> V_70 -> V_76 < 16 ) {
F_3 ( V_122 ,
V_124 ) ;
goto V_45;
}
if ( F_55 ( V_81 -> V_68 , V_81 -> V_69 << 3 , & V_111 ) ) {
F_3 ( V_122 ,
V_117 ) ;
goto V_45;
}
V_119 = F_36 ( V_81 -> V_70 -> V_76 - 8 ) ;
if ( ! V_119 ) {
F_3 ( V_122 , V_10 ) ;
goto V_45;
}
V_120 = F_56 ( & V_111 , NULL , V_119 ,
V_81 -> V_70 -> V_75 ,
V_81 -> V_70 -> V_76 ) ;
if ( V_120 <= 0 ) {
F_3 ( V_122 , V_125 ) ;
goto V_45;
}
V_60 -> V_68 = V_119 ;
V_60 -> V_69 = V_120 ;
V_114 = 1 ;
V_45:
if ( ! V_114 && V_119 )
F_39 ( V_119 ) ;
F_43 ( & V_111 , sizeof( V_111 ) ) ;
return V_114 ;
}
int F_57 ( T_2 * V_1 , T_3 * V_14 )
{
switch ( V_14 -> type ) {
case V_18 :
return F_40 ( V_1 , V_14 ) ;
case V_82 :
return F_54 ( V_1 , V_14 ) ;
case V_126 :
return F_58 ( V_1 , V_14 , 0 ) ;
default:
F_3 ( V_127 ,
V_128 ) ;
return 0 ;
}
}
int F_59 ( T_2 * V_1 , T_3 * V_14 )
{
switch ( V_14 -> type ) {
case V_18 :
return F_33 ( V_1 , V_14 ) ;
case V_20 :
return F_60 ( V_1 , V_14 ) ;
case V_82 :
return F_51 ( V_1 , V_14 ) ;
break;
case V_126 :
return F_58 ( V_1 , V_14 , 1 ) ;
break;
default:
F_3 ( V_129 ,
V_130 ) ;
return 0 ;
}
}
static void F_61 ( T_1 * V_30 )
{
T_21 * V_131 = V_30 -> V_132 ;
int V_17 ;
if ( V_131 == NULL )
return;
for ( V_17 = 0 ; V_17 < F_62 ( V_131 -> V_133 ) ; V_17 ++ ) {
T_22 * V_134 ;
V_134 = F_63 ( V_131 -> V_133 , V_17 ) ;
if ( V_134 -> type == V_135 ) {
V_30 -> V_11 = 4 ;
return;
} else if ( V_134 -> type == V_136 ) {
if ( V_30 -> V_11 < 3 )
V_30 -> V_11 = 3 ;
}
}
for ( V_17 = 0 ; V_17 < F_64 ( V_131 -> V_137 ) ; V_17 ++ ) {
T_23 * V_138 ;
V_138 = F_65 ( V_131 -> V_137 , V_17 ) ;
if ( V_138 -> type == V_139 ) {
V_30 -> V_11 = 4 ;
return;
}
}
}
static void F_66 ( T_1 * V_30 )
{
int V_17 ;
T_3 * V_14 ;
if ( V_30 -> V_11 >= 4 )
return;
F_61 ( V_30 ) ;
if ( V_30 -> V_11 >= 3 )
return;
for ( V_17 = 0 ; V_17 < F_67 ( V_30 -> V_48 ) ; V_17 ++ ) {
V_14 = F_68 ( V_30 -> V_48 , V_17 ) ;
if ( V_14 -> type == V_126 || V_14 -> type == V_140 ) {
V_30 -> V_11 = 3 ;
return;
} else if ( V_14 -> type != V_18
|| V_14 -> V_6 . V_19 -> V_11 != 0 ) {
V_30 -> V_11 = 2 ;
}
}
if ( V_30 -> V_11 == 2 )
return;
if ( V_30 -> V_132 || V_30 -> V_141 )
V_30 -> V_11 = 2 ;
V_30 -> V_11 = 0 ;
}
T_24 * F_69 ( T_2 * V_1 )
{
T_13 * V_60 ;
F_70 ( T_3 ) * V_142 ;
T_3 * V_14 ;
int V_17 , V_143 = 0 ;
T_24 * V_63 ;
V_60 = V_1 -> V_6 . V_7 -> V_12 ;
V_63 = F_71 ( V_60 ) ;
if ( ! V_63 || ! V_60 -> V_29 )
return V_63 ;
V_142 = V_1 -> V_6 . V_7 -> V_48 ;
for ( V_17 = 0 ; V_17 < F_67 ( V_142 ) ; V_17 ++ ) {
V_14 = F_68 ( V_142 , V_17 ) ;
if ( F_59 ( V_1 , V_14 ) <= 0 ) {
F_3 ( V_144 ,
V_145 ) ;
goto V_45;
}
}
F_66 ( V_1 -> V_6 . V_7 ) ;
V_143 = 1 ;
V_45:
V_60 -> V_29 = NULL ;
if ( V_60 -> V_68 ) {
F_43 ( V_60 -> V_68 , V_60 -> V_69 ) ;
F_39 ( V_60 -> V_68 ) ;
V_60 -> V_68 = NULL ;
V_60 -> V_69 = 0 ;
}
if ( V_143 )
return V_63 ;
F_72 ( V_63 ) ;
return NULL ;
}
int F_22 ( T_4 * V_34 )
{
if ( V_34 -> V_23 && V_34 -> V_23 -> V_24 ) {
int V_17 , V_114 ;
V_17 = V_34 -> V_23 -> V_24 ( V_34 , V_146 , 0 , & V_114 ) ;
if ( V_17 > 0 )
return V_114 ;
}
return V_18 ;
}
