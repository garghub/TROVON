static T_1 * F_1 ( const T_2 * V_1 , const unsigned char * * V_2 ,
long V_3 )
{
if ( V_1 -> V_4 == & V_5 )
return F_2 ( NULL , V_2 , V_3 ) ;
return F_3 ( NULL , V_2 , V_3 ) ;
}
static int F_4 ( const T_2 * V_1 , const T_1 * V_6 , unsigned char * * V_2 )
{
if ( V_1 -> V_4 == & V_5 )
return F_5 ( V_6 , V_2 ) ;
return F_6 ( V_6 , V_2 ) ;
}
static void F_7 ( T_2 * V_1 )
{
F_8 ( V_1 -> V_1 . V_7 ) ;
}
static int F_9 ( T_2 * V_1 , T_3 * V_8 )
{
const unsigned char * V_9 , * V_10 ;
int V_11 , V_12 ;
int V_13 ;
const void * V_14 ;
const T_4 * V_15 ;
T_5 * V_16 ;
T_6 * V_17 = NULL ;
T_1 * V_7 = NULL ;
if ( ! F_10 ( NULL , & V_9 , & V_11 , & V_16 , V_8 ) )
return 0 ;
F_11 ( NULL , & V_13 , & V_14 , V_16 ) ;
if ( V_13 != V_18 ) {
F_12 ( V_19 , V_20 ) ;
goto V_21;
}
V_15 = V_14 ;
V_10 = V_15 -> V_22 ;
V_12 = V_15 -> V_3 ;
if ( ( V_7 = F_1 ( V_1 , & V_10 , V_12 ) ) == NULL ) {
F_12 ( V_19 , V_23 ) ;
goto V_21;
}
if ( ( V_17 = F_13 ( NULL , & V_9 , V_11 ) ) == NULL ) {
F_12 ( V_19 , V_23 ) ;
goto V_21;
}
if ( ( V_7 -> V_24 = F_14 ( V_17 , NULL ) ) == NULL ) {
F_12 ( V_19 , V_25 ) ;
goto V_21;
}
F_15 ( V_17 ) ;
F_16 ( V_1 , V_1 -> V_4 -> V_26 , V_7 ) ;
return 1 ;
V_21:
F_15 ( V_17 ) ;
F_8 ( V_7 ) ;
return 0 ;
}
static int F_17 ( T_3 * V_27 , const T_2 * V_1 )
{
T_1 * V_7 ;
int V_13 ;
unsigned char * V_28 = NULL ;
int V_29 ;
T_4 * V_30 ;
T_6 * V_24 = NULL ;
V_7 = V_1 -> V_1 . V_7 ;
V_30 = F_18 () ;
if ( V_30 == NULL ) {
F_12 ( V_31 , V_32 ) ;
goto V_21;
}
V_30 -> V_3 = F_4 ( V_1 , V_7 , & V_30 -> V_22 ) ;
if ( V_30 -> V_3 <= 0 ) {
F_12 ( V_31 , V_32 ) ;
goto V_21;
}
V_13 = V_18 ;
V_24 = F_19 ( V_7 -> V_24 , NULL ) ;
if ( ! V_24 )
goto V_21;
V_29 = F_20 ( V_24 , & V_28 ) ;
F_15 ( V_24 ) ;
if ( V_29 <= 0 ) {
F_12 ( V_31 , V_32 ) ;
goto V_21;
}
if ( F_21 ( V_27 , F_22 ( V_1 -> V_4 -> V_26 ) ,
V_13 , V_30 , V_28 , V_29 ) )
return 1 ;
V_21:
F_23 ( V_28 ) ;
F_24 ( V_30 ) ;
return 0 ;
}
static int F_25 ( T_2 * V_1 , const T_7 * V_33 )
{
const unsigned char * V_9 , * V_10 ;
int V_11 , V_12 ;
int V_13 ;
const void * V_14 ;
const T_4 * V_15 ;
const T_5 * V_16 ;
T_6 * V_34 = NULL ;
T_1 * V_7 = NULL ;
if ( ! F_26 ( NULL , & V_9 , & V_11 , & V_16 , V_33 ) )
return 0 ;
F_11 ( NULL , & V_13 , & V_14 , V_16 ) ;
if ( V_13 != V_18 )
goto V_35;
if ( ( V_34 = F_13 ( NULL , & V_9 , V_11 ) ) == NULL )
goto V_35;
V_15 = V_14 ;
V_10 = V_15 -> V_22 ;
V_12 = V_15 -> V_3 ;
if ( ( V_7 = F_1 ( V_1 , & V_10 , V_12 ) ) == NULL )
goto V_35;
if ( ( V_7 -> V_36 = F_27 () ) == NULL
|| ! F_14 ( V_34 , V_7 -> V_36 ) ) {
F_12 ( V_37 , V_38 ) ;
goto V_39;
}
if ( ! F_28 ( V_7 ) )
goto V_39;
F_16 ( V_1 , V_1 -> V_4 -> V_26 , V_7 ) ;
F_29 ( V_34 ) ;
return 1 ;
V_35:
F_12 ( V_37 , V_40 ) ;
V_39:
F_8 ( V_7 ) ;
F_29 ( V_34 ) ;
return 0 ;
}
static int F_30 ( T_7 * V_33 , const T_2 * V_1 )
{
T_4 * V_41 = NULL ;
T_6 * V_42 = NULL ;
unsigned char * V_43 = NULL ;
int V_44 ;
V_41 = F_18 () ;
if ( V_41 == NULL ) {
F_12 ( V_45 , V_32 ) ;
goto V_21;
}
V_41 -> V_3 = F_4 ( V_1 , V_1 -> V_1 . V_7 , & V_41 -> V_22 ) ;
if ( V_41 -> V_3 <= 0 ) {
F_12 ( V_45 , V_32 ) ;
goto V_21;
}
V_41 -> type = V_18 ;
V_42 = F_19 ( V_1 -> V_1 . V_7 -> V_36 , NULL ) ;
if ( ! V_42 ) {
F_12 ( V_45 , V_38 ) ;
goto V_21;
}
V_44 = F_20 ( V_42 , & V_43 ) ;
F_29 ( V_42 ) ;
V_42 = NULL ;
if ( ! F_31 ( V_33 , F_22 ( V_1 -> V_4 -> V_26 ) , 0 ,
V_18 , V_41 , V_43 , V_44 ) )
goto V_21;
return 1 ;
V_21:
F_23 ( V_43 ) ;
F_24 ( V_41 ) ;
F_29 ( V_42 ) ;
return 0 ;
}
static int F_32 ( T_2 * V_1 ,
const unsigned char * * V_46 , int V_47 )
{
T_1 * V_7 ;
if ( ( V_7 = F_1 ( V_1 , V_46 , V_47 ) ) == NULL ) {
F_12 ( V_48 , V_49 ) ;
return 0 ;
}
F_16 ( V_1 , V_1 -> V_4 -> V_26 , V_7 ) ;
return 1 ;
}
static int F_33 ( const T_2 * V_1 , unsigned char * * V_46 )
{
return F_4 ( V_1 , V_1 -> V_1 . V_7 , V_46 ) ;
}
static int F_34 ( T_8 * V_50 , const T_1 * V_51 , int V_52 , int V_13 )
{
int V_53 = V_54 ;
const char * V_55 = NULL ;
T_9 * V_36 , * V_24 ;
if ( V_13 == 2 )
V_36 = V_51 -> V_36 ;
else
V_36 = NULL ;
if ( V_13 > 0 )
V_24 = V_51 -> V_24 ;
else
V_24 = NULL ;
if ( V_51 -> V_9 == NULL || ( V_13 == 2 && V_36 == NULL )
|| ( V_13 > 0 && V_24 == NULL ) ) {
V_53 = V_56 ;
goto V_21;
}
if ( V_13 == 2 )
V_55 = L_1 ;
else if ( V_13 == 1 )
V_55 = L_2 ;
else
V_55 = L_3 ;
F_35 ( V_50 , V_52 , 128 ) ;
if ( F_36 ( V_50 , L_4 , V_55 , F_37 ( V_51 -> V_9 ) ) <= 0 )
goto V_21;
V_52 += 4 ;
if ( ! F_38 ( V_50 , L_5 , V_36 , NULL , V_52 ) )
goto V_21;
if ( ! F_38 ( V_50 , L_6 , V_24 , NULL , V_52 ) )
goto V_21;
if ( ! F_38 ( V_50 , L_7 , V_51 -> V_9 , NULL , V_52 ) )
goto V_21;
if ( ! F_38 ( V_50 , L_8 , V_51 -> V_57 , NULL , V_52 ) )
goto V_21;
if ( V_51 -> V_58 && ! F_38 ( V_50 , L_9 , V_51 -> V_58 , NULL , V_52 ) )
goto V_21;
if ( V_51 -> V_59 && ! F_38 ( V_50 , L_10 , V_51 -> V_59 , NULL , V_52 ) )
goto V_21;
if ( V_51 -> V_60 ) {
int V_61 ;
F_35 ( V_50 , V_52 , 128 ) ;
F_39 ( V_50 , L_11 ) ;
for ( V_61 = 0 ; V_61 < V_51 -> V_62 ; V_61 ++ ) {
if ( ( V_61 % 15 ) == 0 ) {
if ( F_39 ( V_50 , L_12 ) <= 0
|| ! F_35 ( V_50 , V_52 + 4 , 128 ) )
goto V_21;
}
if ( F_36 ( V_50 , L_13 , V_51 -> V_60 [ V_61 ] ,
( ( V_61 + 1 ) == V_51 -> V_62 ) ? L_14 : L_15 ) <= 0 )
goto V_21;
}
if ( F_40 ( V_50 , L_12 , 1 ) <= 0 )
return ( 0 ) ;
}
if ( V_51 -> V_63 && ! F_38 ( V_50 , L_16 , V_51 -> V_63 , NULL , V_52 ) )
goto V_21;
if ( V_51 -> V_3 != 0 ) {
F_35 ( V_50 , V_52 , 128 ) ;
if ( F_36 ( V_50 , L_17 ,
( int ) V_51 -> V_3 ) <= 0 )
goto V_21;
}
return 1 ;
V_21:
F_12 ( V_64 , V_53 ) ;
return 0 ;
}
static int F_41 ( const T_2 * V_1 )
{
return ( F_42 ( V_1 -> V_1 . V_7 ) ) ;
}
static int F_43 ( const T_2 * V_1 )
{
return F_37 ( V_1 -> V_1 . V_7 -> V_9 ) ;
}
static int F_44 ( const T_2 * V_1 )
{
return F_45 ( V_1 -> V_1 . V_7 ) ;
}
static int F_46 ( const T_2 * V_6 , const T_2 * V_65 )
{
if ( F_47 ( V_6 -> V_1 . V_7 -> V_9 , V_65 -> V_1 . V_7 -> V_9 ) ||
F_47 ( V_6 -> V_1 . V_7 -> V_57 , V_65 -> V_1 . V_7 -> V_57 ) )
return 0 ;
else if ( V_6 -> V_4 == & V_5 ) {
if ( F_47 ( V_6 -> V_1 . V_7 -> V_58 , V_65 -> V_1 . V_7 -> V_58 ) )
return 0 ;
}
return 1 ;
}
static int F_48 ( T_9 * * V_66 , const T_9 * V_67 )
{
T_9 * V_6 ;
if ( V_67 ) {
V_6 = F_49 ( V_67 ) ;
if ( ! V_6 )
return 0 ;
} else
V_6 = NULL ;
F_50 ( * V_66 ) ;
* V_66 = V_6 ;
return 1 ;
}
static int F_51 ( T_1 * V_68 , const T_1 * V_69 , int V_70 )
{
if ( V_70 == - 1 )
V_70 = ! ! V_69 -> V_58 ;
if ( ! F_48 ( & V_68 -> V_9 , V_69 -> V_9 ) )
return 0 ;
if ( ! F_48 ( & V_68 -> V_57 , V_69 -> V_57 ) )
return 0 ;
if ( V_70 ) {
if ( ! F_48 ( & V_68 -> V_58 , V_69 -> V_58 ) )
return 0 ;
if ( ! F_48 ( & V_68 -> V_59 , V_69 -> V_59 ) )
return 0 ;
F_23 ( V_68 -> V_60 ) ;
V_68 -> V_60 = NULL ;
V_68 -> V_62 = 0 ;
if ( V_69 -> V_60 ) {
V_68 -> V_60 = F_52 ( V_69 -> V_60 , V_69 -> V_62 ) ;
if ( ! V_68 -> V_60 )
return 0 ;
V_68 -> V_62 = V_69 -> V_62 ;
}
} else
V_68 -> V_3 = V_69 -> V_3 ;
return 1 ;
}
T_1 * F_53 ( T_1 * V_7 )
{
T_1 * V_71 ;
V_71 = F_54 () ;
if ( V_71 == NULL )
return NULL ;
if ( ! F_51 ( V_71 , V_7 , - 1 ) ) {
F_8 ( V_71 ) ;
return NULL ;
}
return V_71 ;
}
static int F_55 ( T_2 * V_68 , const T_2 * V_69 )
{
if ( V_68 -> V_1 . V_7 == NULL ) {
V_68 -> V_1 . V_7 = F_54 () ;
if ( V_68 -> V_1 . V_7 == NULL )
return 0 ;
}
return F_51 ( V_68 -> V_1 . V_7 , V_69 -> V_1 . V_7 ,
V_69 -> V_4 == & V_5 ) ;
}
static int F_56 ( const T_2 * V_6 )
{
if ( V_6 -> V_1 . V_7 == NULL || V_6 -> V_1 . V_7 -> V_9 == NULL || V_6 -> V_1 . V_7 -> V_57 == NULL )
return 1 ;
return 0 ;
}
static int F_57 ( const T_2 * V_6 , const T_2 * V_65 )
{
if ( F_46 ( V_6 , V_65 ) == 0 )
return 0 ;
if ( F_47 ( V_65 -> V_1 . V_7 -> V_24 , V_6 -> V_1 . V_7 -> V_24 ) != 0 )
return 0 ;
else
return 1 ;
}
static int F_58 ( T_8 * V_50 , const T_2 * V_1 , int V_52 ,
T_10 * V_72 )
{
return F_34 ( V_50 , V_1 -> V_1 . V_7 , V_52 , 0 ) ;
}
static int F_59 ( T_8 * V_50 , const T_2 * V_1 , int V_52 ,
T_10 * V_72 )
{
return F_34 ( V_50 , V_1 -> V_1 . V_7 , V_52 , 1 ) ;
}
static int F_60 ( T_8 * V_50 , const T_2 * V_1 , int V_52 ,
T_10 * V_72 )
{
return F_34 ( V_50 , V_1 -> V_1 . V_7 , V_52 , 2 ) ;
}
int F_61 ( T_8 * V_50 , const T_1 * V_51 )
{
return F_34 ( V_50 , V_51 , 4 , 0 ) ;
}
static int F_62 ( T_2 * V_1 , int V_73 , long V_74 , void * V_75 )
{
switch ( V_73 ) {
#ifndef F_63
case V_76 :
if ( V_74 == 1 )
return F_64 ( V_75 ) ;
else if ( V_74 == 0 )
return F_65 ( V_75 ) ;
return - 2 ;
case V_77 :
* ( int * ) V_75 = V_78 ;
return 1 ;
#endif
default:
return - 2 ;
}
}
static int F_66 ( T_11 * V_79 ,
T_5 * V_80 , T_12 * V_8 )
{
const T_13 * V_81 ;
int V_82 ;
const void * V_83 ;
T_6 * V_17 = NULL ;
int V_84 = 0 ;
T_2 * V_85 = NULL , * V_27 = NULL ;
T_1 * V_86 = NULL ;
const unsigned char * V_9 ;
int V_87 ;
F_11 ( & V_81 , & V_82 , & V_83 , V_80 ) ;
if ( F_67 ( V_81 ) != V_88 )
goto V_21;
if ( V_82 != V_89 && V_82 == V_90 )
goto V_21;
V_27 = F_68 ( V_79 ) ;
if ( ! V_27 )
goto V_21;
if ( V_27 -> type != V_91 )
goto V_21;
V_86 = F_53 ( V_27 -> V_1 . V_7 ) ;
V_87 = F_69 ( V_8 ) ;
V_9 = F_70 ( V_8 ) ;
if ( ! V_9 || ! V_87 )
goto V_21;
if ( ( V_17 = F_13 ( NULL , & V_9 , V_87 ) ) == NULL ) {
F_12 ( V_92 , V_23 ) ;
goto V_21;
}
if ( ( V_86 -> V_24 = F_14 ( V_17 , NULL ) ) == NULL ) {
F_12 ( V_92 , V_25 ) ;
goto V_21;
}
V_85 = F_71 () ;
if ( V_85 == NULL )
goto V_21;
F_16 ( V_85 , V_27 -> V_4 -> V_26 , V_86 ) ;
V_86 = NULL ;
if ( F_72 ( V_79 , V_85 ) > 0 )
V_84 = 1 ;
V_21:
F_15 ( V_17 ) ;
F_73 ( V_85 ) ;
F_8 ( V_86 ) ;
return V_84 ;
}
static int F_74 ( T_11 * V_79 , T_14 * V_93 )
{
int V_84 = 0 ;
T_5 * V_80 , * V_94 = NULL ;
T_15 * V_95 ;
const unsigned char * V_9 ;
unsigned char * V_96 = NULL ;
T_16 V_97 = 0 ;
int V_98 , V_87 ;
const T_17 * V_99 ;
T_18 * V_100 ;
if ( ! F_75 ( V_93 , & V_80 , & V_95 ) )
goto V_21;
if ( F_67 ( V_80 -> V_101 ) != V_102 ) {
F_12 ( V_103 , V_104 ) ;
goto V_21;
}
if ( F_76 ( V_79 , V_105 ) <= 0 )
goto V_21;
if ( F_77 ( V_79 , F_78 () ) <= 0 )
goto V_21;
if ( V_80 -> V_106 -> type != V_18 )
goto V_21;
V_9 = V_80 -> V_106 -> V_107 . V_108 -> V_22 ;
V_87 = V_80 -> V_106 -> V_107 . V_108 -> V_3 ;
V_94 = F_79 ( NULL , & V_9 , V_87 ) ;
if ( ! V_94 )
goto V_21;
V_100 = F_80 ( V_93 ) ;
if ( ! V_100 )
goto V_21;
V_99 = F_81 ( V_94 -> V_101 ) ;
if ( ! V_99 || F_82 ( V_99 ) != V_109 )
goto V_21;
if ( ! F_83 ( V_100 , V_99 , NULL , NULL , NULL ) )
goto V_21;
if ( F_84 ( V_100 , V_94 -> V_106 ) <= 0 )
goto V_21;
V_98 = F_85 ( V_100 ) ;
if ( F_86 ( V_79 , V_98 ) <= 0 )
goto V_21;
if ( F_87 ( V_79 ,
F_22 ( F_88 ( V_99 ) ) )
<= 0 )
goto V_21;
if ( V_95 ) {
V_97 = F_69 ( V_95 ) ;
V_96 = F_52 ( F_70 ( V_95 ) , V_97 ) ;
if ( ! V_96 )
goto V_21;
}
if ( F_89 ( V_79 , V_96 , V_97 ) <= 0 )
goto V_21;
V_96 = NULL ;
V_84 = 1 ;
V_21:
F_90 ( V_94 ) ;
F_23 ( V_96 ) ;
return V_84 ;
}
static int F_64 ( T_14 * V_93 )
{
T_11 * V_79 ;
V_79 = F_91 ( V_93 ) ;
if ( ! V_79 )
return 0 ;
if ( ! F_92 ( V_79 ) ) {
T_5 * V_80 ;
T_12 * V_8 ;
if ( ! F_93 ( V_93 , & V_80 , & V_8 ,
NULL , NULL , NULL ) )
return 0 ;
if ( ! V_80 || ! V_8 )
return 0 ;
if ( ! F_66 ( V_79 , V_80 , V_8 ) ) {
F_12 ( V_110 , V_111 ) ;
return 0 ;
}
}
if ( ! F_74 ( V_79 , V_93 ) ) {
F_12 ( V_110 , V_112 ) ;
return 0 ;
}
return 1 ;
}
static int F_65 ( T_14 * V_93 )
{
T_11 * V_79 ;
T_2 * V_1 ;
T_18 * V_72 ;
int V_98 ;
T_5 * V_113 , * V_114 = NULL ;
const T_13 * V_81 ;
T_12 * V_8 ;
T_4 * V_115 ;
T_15 * V_95 ;
unsigned char * V_28 = NULL , * V_96 = NULL ;
int V_29 ;
T_16 V_97 = 0 ;
int V_84 = 0 ;
int V_116 , V_117 ;
const T_19 * V_118 ;
V_79 = F_91 ( V_93 ) ;
if ( ! V_79 )
return 0 ;
V_1 = F_68 ( V_79 ) ;
if ( ! F_93 ( V_93 , & V_113 , & V_8 ,
NULL , NULL , NULL ) )
goto V_21;
F_11 ( & V_81 , NULL , NULL , V_113 ) ;
if ( V_81 == F_22 ( V_119 ) ) {
T_6 * V_120 = F_19 ( V_1 -> V_1 . V_7 -> V_24 , NULL ) ;
if ( ! V_120 )
goto V_21;
V_29 = F_20 ( V_120 , & V_28 ) ;
F_15 ( V_120 ) ;
if ( V_29 <= 0 )
goto V_21;
F_94 ( V_8 , V_28 , V_29 ) ;
V_8 -> V_121 &= ~ ( V_122 | 0x07 ) ;
V_8 -> V_121 |= V_122 ;
V_28 = NULL ;
F_95 ( V_113 , F_22 ( V_88 ) ,
V_89 , NULL ) ;
}
V_116 = F_96 ( V_79 ) ;
if ( V_116 <= 0 )
goto V_21;
if ( ! F_97 ( V_79 , & V_118 ) )
goto V_21;
if ( V_116 == V_123 ) {
V_116 = V_105 ;
if ( F_76 ( V_79 , V_116 ) <= 0 )
goto V_21;
} else if ( V_116 != V_105 )
goto V_21;
if ( V_118 == NULL ) {
V_118 = F_78 () ;
if ( F_77 ( V_79 , V_118 ) <= 0 )
goto V_21;
} else if ( F_98 ( V_118 ) != V_124 )
goto V_21;
if ( ! F_75 ( V_93 , & V_113 , & V_95 ) )
goto V_21;
V_72 = F_80 ( V_93 ) ;
V_117 = F_99 ( V_72 ) ;
if ( F_87 ( V_79 , F_22 ( V_117 ) ) <= 0 )
goto V_21;
V_98 = F_85 ( V_72 ) ;
V_114 = F_100 () ;
if ( V_114 == NULL )
goto V_21;
V_114 -> V_101 = F_22 ( V_117 ) ;
V_114 -> V_106 = F_101 () ;
if ( V_114 -> V_106 == NULL )
goto V_21;
if ( F_102 ( V_72 , V_114 -> V_106 ) <= 0 )
goto V_21;
if ( F_103 ( V_114 -> V_106 ) == V_119 ) {
F_104 ( V_114 -> V_106 ) ;
V_114 -> V_106 = NULL ;
}
if ( F_86 ( V_79 , V_98 ) <= 0 )
goto V_21;
if ( V_95 ) {
V_97 = F_69 ( V_95 ) ;
V_96 = F_52 ( F_70 ( V_95 ) , V_97 ) ;
if ( ! V_96 )
goto V_21;
}
if ( F_89 ( V_79 , V_96 , V_97 ) <= 0 )
goto V_21;
V_96 = NULL ;
V_28 = NULL ;
V_29 = F_105 ( V_114 , & V_28 ) ;
if ( ! V_28 || ! V_29 )
goto V_21;
V_115 = F_18 () ;
if ( V_115 == NULL )
goto V_21;
F_94 ( V_115 , V_28 , V_29 ) ;
V_28 = NULL ;
F_95 ( V_113 , F_22 ( V_102 ) ,
V_18 , V_115 ) ;
V_84 = 1 ;
V_21:
F_23 ( V_28 ) ;
F_90 ( V_114 ) ;
return V_84 ;
}
