static int F_1 ( char * type ,
const char T_1 * V_1 ,
unsigned V_2 )
{
int V_3 ;
V_3 = F_2 ( type , V_1 , V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 == 0 || V_3 >= V_2 )
return - V_4 ;
if ( type [ 0 ] == '.' )
return - V_5 ;
type [ V_2 - 1 ] = '\0' ;
return 0 ;
}
long F_3 ( T_2 V_6 , int V_7 )
{
T_3 V_8 ;
unsigned long V_9 ;
long V_3 ;
V_9 = V_7 ? V_10 : 0 ;
V_8 = F_4 ( V_6 , V_9 , V_11 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_3 = F_7 ( V_8 ) -> V_12 ;
F_8 ( V_8 ) ;
error:
return V_3 ;
}
long F_9 ( const char T_1 * V_13 )
{
char * V_14 ;
long V_3 ;
V_14 = NULL ;
if ( V_13 ) {
V_14 = F_10 ( V_13 , V_15 ) ;
if ( F_5 ( V_14 ) ) {
V_3 = F_6 ( V_14 ) ;
goto error;
}
}
V_3 = F_11 ( V_14 ) ;
F_12 ( V_14 ) ;
error:
return V_3 ;
}
long F_13 ( T_2 V_6 ,
const void T_1 * V_16 ,
T_4 V_17 )
{
T_3 V_8 ;
void * V_18 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_17 > V_19 )
goto error;
V_18 = NULL ;
if ( V_16 ) {
V_3 = - V_20 ;
V_18 = F_14 ( V_17 , V_21 ) ;
if ( ! V_18 )
goto error;
V_3 = - V_22 ;
if ( F_15 ( V_18 , V_16 , V_17 ) != 0 )
goto V_23;
}
V_8 = F_4 ( V_6 , 0 , V_24 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto V_23;
}
V_3 = F_16 ( V_8 , V_18 , V_17 ) ;
F_8 ( V_8 ) ;
V_23:
F_12 ( V_18 ) ;
error:
return V_3 ;
}
long F_17 ( T_2 V_6 )
{
T_3 V_8 ;
long V_3 ;
V_8 = F_4 ( V_6 , 0 , V_24 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
if ( V_3 != - V_25 )
goto error;
V_8 = F_4 ( V_6 , 0 , V_26 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
}
F_18 ( F_7 ( V_8 ) ) ;
V_3 = 0 ;
F_8 ( V_8 ) ;
error:
return V_3 ;
}
long F_19 ( T_2 V_6 )
{
T_3 V_8 ;
long V_3 ;
F_20 ( L_1 , V_6 ) ;
V_8 = F_4 ( V_6 , 0 , V_11 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
if ( F_21 ( V_27 ) ) {
V_8 = F_4 ( V_6 , 0 , 0 ) ;
if ( F_5 ( V_8 ) )
goto error;
if ( F_22 ( V_28 ,
& F_7 ( V_8 ) -> V_29 ) )
goto V_30;
goto V_31;
}
goto error;
}
V_30:
F_23 ( F_7 ( V_8 ) ) ;
V_3 = 0 ;
V_31:
F_8 ( V_8 ) ;
error:
F_24 ( L_2 , V_3 ) ;
return V_3 ;
}
long F_25 ( T_2 V_32 )
{
T_3 V_33 ;
long V_3 ;
V_33 = F_4 ( V_32 , V_10 , V_24 ) ;
if ( F_5 ( V_33 ) ) {
V_3 = F_6 ( V_33 ) ;
if ( F_21 ( V_27 ) ) {
V_33 = F_4 ( V_32 , 0 , 0 ) ;
if ( F_5 ( V_33 ) )
goto error;
if ( F_22 ( V_34 ,
& F_7 ( V_33 ) -> V_29 ) )
goto V_35;
goto V_31;
}
goto error;
}
V_35:
V_3 = F_26 ( F_7 ( V_33 ) ) ;
V_31:
F_8 ( V_33 ) ;
error:
return V_3 ;
}
long F_27 ( T_2 V_6 , T_2 V_32 )
{
T_3 V_33 , V_8 ;
long V_3 ;
V_33 = F_4 ( V_32 , V_10 , V_24 ) ;
if ( F_5 ( V_33 ) ) {
V_3 = F_6 ( V_33 ) ;
goto error;
}
V_8 = F_4 ( V_6 , V_10 , V_36 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto V_23;
}
V_3 = F_28 ( F_7 ( V_33 ) , F_7 ( V_8 ) ) ;
F_8 ( V_8 ) ;
V_23:
F_8 ( V_33 ) ;
error:
return V_3 ;
}
long F_29 ( T_2 V_6 , T_2 V_32 )
{
T_3 V_33 , V_8 ;
long V_3 ;
V_33 = F_4 ( V_32 , 0 , V_24 ) ;
if ( F_5 ( V_33 ) ) {
V_3 = F_6 ( V_33 ) ;
goto error;
}
V_8 = F_4 ( V_6 , V_37 , 0 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto V_23;
}
V_3 = F_30 ( F_7 ( V_33 ) , F_7 ( V_8 ) ) ;
F_8 ( V_8 ) ;
V_23:
F_8 ( V_33 ) ;
error:
return V_3 ;
}
long F_31 ( T_2 V_38 ,
char T_1 * V_39 ,
T_4 V_40 )
{
struct V_41 * V_41 , * V_42 ;
T_3 V_8 ;
char * V_43 ;
long V_3 ;
int V_44 , V_45 ;
V_8 = F_4 ( V_38 , V_46 , V_47 ) ;
if ( F_5 ( V_8 ) ) {
if ( F_6 ( V_8 ) == - V_25 ) {
V_42 = F_32 ( V_38 ) ;
if ( ! F_5 ( V_42 ) ) {
F_33 ( V_42 ) ;
V_8 = F_4 ( V_38 ,
V_46 ,
0 ) ;
if ( ! F_5 ( V_8 ) )
goto V_48;
}
}
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_48:
V_41 = F_7 ( V_8 ) ;
V_44 = strlen ( V_41 -> V_49 ) ;
V_3 = - V_20 ;
V_43 = F_34 ( V_21 ,
L_3 ,
V_41 -> type -> V_14 ,
F_35 ( F_36 () , V_41 -> V_50 ) ,
F_37 ( F_36 () , V_41 -> V_51 ) ,
V_41 -> V_52 ) ;
if ( ! V_43 )
goto V_23;
V_45 = strlen ( V_43 ) ;
V_3 = V_45 + V_44 + 1 ;
if ( V_39 && V_40 >= V_3 ) {
if ( F_38 ( V_39 , V_43 , V_45 ) != 0 ||
F_38 ( V_39 + V_45 , V_41 -> V_49 ,
V_44 + 1 ) != 0 )
V_3 = - V_22 ;
}
F_12 ( V_43 ) ;
V_23:
F_8 ( V_8 ) ;
error:
return V_3 ;
}
long F_39 ( T_2 V_32 ,
const char T_1 * V_1 ,
const char T_1 * V_53 ,
T_2 V_54 )
{
struct V_55 * V_56 ;
T_3 V_33 , V_8 , V_57 ;
char type [ 32 ] , * V_49 ;
long V_3 ;
V_3 = F_1 ( type , V_1 , sizeof( type ) ) ;
if ( V_3 < 0 )
goto error;
V_49 = F_10 ( V_53 , V_15 ) ;
if ( F_5 ( V_49 ) ) {
V_3 = F_6 ( V_49 ) ;
goto error;
}
V_33 = F_4 ( V_32 , 0 , V_11 ) ;
if ( F_5 ( V_33 ) ) {
V_3 = F_6 ( V_33 ) ;
goto V_23;
}
V_57 = NULL ;
if ( V_54 ) {
V_57 = F_4 ( V_54 , V_10 ,
V_24 ) ;
if ( F_5 ( V_57 ) ) {
V_3 = F_6 ( V_57 ) ;
goto V_58;
}
}
V_56 = F_40 ( type ) ;
if ( F_5 ( V_56 ) ) {
V_3 = F_6 ( V_56 ) ;
goto V_59;
}
V_8 = F_41 ( V_33 , V_56 , V_49 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
if ( V_3 == - V_60 )
V_3 = - V_61 ;
goto V_62;
}
if ( V_57 ) {
V_3 = F_42 ( V_8 , V_36 ) ;
if ( V_3 < 0 )
goto V_63;
V_3 = F_28 ( F_7 ( V_57 ) , F_7 ( V_8 ) ) ;
if ( V_3 < 0 )
goto V_63;
}
V_3 = F_7 ( V_8 ) -> V_12 ;
V_63:
F_8 ( V_8 ) ;
V_62:
F_43 ( V_56 ) ;
V_59:
F_8 ( V_57 ) ;
V_58:
F_8 ( V_33 ) ;
V_23:
F_12 ( V_49 ) ;
error:
return V_3 ;
}
long F_44 ( T_2 V_38 , char T_1 * V_39 , T_4 V_40 )
{
struct V_41 * V_41 ;
T_3 V_8 ;
long V_3 ;
V_8 = F_4 ( V_38 , 0 , 0 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = - V_61 ;
goto error;
}
V_41 = F_7 ( V_8 ) ;
V_3 = F_42 ( V_8 , V_64 ) ;
if ( V_3 == 0 )
goto V_65;
if ( V_3 != - V_25 )
goto error;
if ( ! F_45 ( V_8 ) ) {
V_3 = - V_25 ;
goto V_23;
}
V_65:
V_3 = F_46 ( V_41 ) ;
if ( V_3 == 0 ) {
V_3 = - V_66 ;
if ( V_41 -> type -> V_67 ) {
F_47 ( & V_41 -> V_68 ) ;
V_3 = V_41 -> type -> V_67 ( V_41 , V_39 , V_40 ) ;
F_48 ( & V_41 -> V_68 ) ;
}
}
V_23:
F_33 ( V_41 ) ;
error:
return V_3 ;
}
long F_49 ( T_2 V_6 , T_5 V_69 , T_6 V_70 )
{
struct V_71 * V_72 , * V_73 = NULL ;
struct V_41 * V_41 ;
T_3 V_8 ;
long V_3 ;
T_7 V_50 ;
T_8 V_51 ;
V_50 = F_50 ( F_36 () , V_69 ) ;
V_51 = F_51 ( F_36 () , V_70 ) ;
V_3 = - V_4 ;
if ( ( V_69 != ( T_5 ) - 1 ) && ! F_52 ( V_50 ) )
goto error;
if ( ( V_70 != ( T_6 ) - 1 ) && ! F_53 ( V_51 ) )
goto error;
V_3 = 0 ;
if ( V_69 == ( T_5 ) - 1 && V_70 == ( T_6 ) - 1 )
goto error;
V_8 = F_4 ( V_6 , V_10 | V_46 ,
V_26 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_41 = F_7 ( V_8 ) ;
V_3 = - V_25 ;
F_54 ( & V_41 -> V_68 ) ;
if ( ! F_21 ( V_27 ) ) {
if ( V_69 != ( T_5 ) - 1 && ! F_55 ( V_41 -> V_50 , V_50 ) )
goto V_31;
if ( V_70 != ( T_6 ) - 1 && ! F_56 ( V_51 , V_41 -> V_51 ) && ! F_57 ( V_51 ) )
goto V_31;
}
if ( V_69 != ( T_5 ) - 1 && ! F_55 ( V_50 , V_41 -> V_50 ) ) {
V_3 = - V_20 ;
V_72 = F_58 ( V_50 ) ;
if ( ! V_72 )
goto V_31;
if ( F_22 ( V_74 , & V_41 -> V_29 ) ) {
unsigned V_75 = F_55 ( V_50 , V_76 ) ?
V_77 : V_78 ;
unsigned V_79 = F_55 ( V_50 , V_76 ) ?
V_80 : V_81 ;
F_59 ( & V_72 -> V_82 ) ;
if ( V_72 -> V_83 + 1 >= V_75 ||
V_72 -> V_84 + V_41 -> V_85 >= V_79 ||
V_72 -> V_84 + V_41 -> V_85 <
V_72 -> V_84 )
goto V_86;
V_72 -> V_83 ++ ;
V_72 -> V_84 += V_41 -> V_85 ;
F_60 ( & V_72 -> V_82 ) ;
F_59 ( & V_41 -> V_69 -> V_82 ) ;
V_41 -> V_69 -> V_83 -- ;
V_41 -> V_69 -> V_84 -= V_41 -> V_85 ;
F_60 ( & V_41 -> V_69 -> V_82 ) ;
}
F_61 ( & V_41 -> V_69 -> V_87 ) ;
F_62 ( & V_72 -> V_87 ) ;
if ( F_22 ( V_88 , & V_41 -> V_29 ) ) {
F_61 ( & V_41 -> V_69 -> V_89 ) ;
F_62 ( & V_72 -> V_89 ) ;
}
V_73 = V_41 -> V_69 ;
V_41 -> V_69 = V_72 ;
V_41 -> V_50 = V_50 ;
}
if ( V_70 != ( T_6 ) - 1 )
V_41 -> V_51 = V_51 ;
V_3 = 0 ;
V_31:
F_63 ( & V_41 -> V_68 ) ;
F_33 ( V_41 ) ;
if ( V_73 )
F_64 ( V_73 ) ;
error:
return V_3 ;
V_86:
F_60 ( & V_72 -> V_82 ) ;
V_73 = V_72 ;
V_3 = - V_90 ;
goto V_31;
}
long F_65 ( T_2 V_6 , T_9 V_52 )
{
struct V_41 * V_41 ;
T_3 V_8 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_52 & ~ ( V_91 | V_92 | V_93 | V_94 ) )
goto error;
V_8 = F_4 ( V_6 , V_10 | V_46 ,
V_26 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_41 = F_7 ( V_8 ) ;
V_3 = - V_25 ;
F_54 ( & V_41 -> V_68 ) ;
if ( F_21 ( V_27 ) || F_55 ( V_41 -> V_50 , F_66 () ) ) {
V_41 -> V_52 = V_52 ;
V_3 = 0 ;
}
F_63 ( & V_41 -> V_68 ) ;
F_33 ( V_41 ) ;
error:
return V_3 ;
}
static long F_67 ( T_2 V_32 ,
struct V_95 * V_96 ,
struct V_41 * * V_97 )
{
T_3 V_98 ;
* V_97 = NULL ;
if ( V_32 == 0 )
return 0 ;
if ( V_32 > 0 ) {
V_98 = F_4 ( V_32 , V_10 , V_24 ) ;
if ( F_5 ( V_98 ) )
return F_6 ( V_98 ) ;
* V_97 = F_7 ( V_98 ) ;
return 0 ;
}
if ( V_32 == V_99 )
return - V_4 ;
if ( V_32 >= V_100 ) {
* V_97 = F_68 ( V_96 -> V_101 ) ;
return 0 ;
}
return - V_61 ;
}
static int F_69 ( struct V_41 * V_41 )
{
struct V_102 * V_103 ;
V_103 = F_70 () ;
if ( ! V_103 )
return - V_20 ;
F_33 ( V_103 -> V_95 ) ;
V_103 -> V_95 = F_68 ( V_41 ) ;
return F_71 ( V_103 ) ;
}
static long F_72 ( void * V_39 , const struct V_104 * V_105 ,
unsigned V_106 )
{
for (; V_106 > 0 ; V_106 -- ) {
if ( F_15 ( V_39 , V_105 -> V_107 , V_105 -> V_108 ) != 0 )
return - V_22 ;
V_39 += V_105 -> V_108 ;
V_105 ++ ;
}
return 0 ;
}
long F_73 ( T_2 V_6 ,
const struct V_104 * V_109 ,
unsigned V_106 ,
T_4 V_17 ,
T_2 V_32 )
{
const struct V_102 * V_102 = F_74 () ;
struct V_95 * V_96 ;
struct V_41 * V_42 , * V_101 ;
void * V_18 ;
long V_3 ;
bool V_110 = false ;
F_20 ( L_4 , V_6 , V_17 , V_32 ) ;
V_3 = - V_4 ;
if ( V_17 > 1024 * 1024 - 1 )
goto error;
V_3 = - V_5 ;
V_42 = V_102 -> V_95 ;
if ( ! V_42 )
goto error;
V_96 = V_42 -> V_18 . V_111 ;
if ( V_96 -> V_112 -> V_12 != V_6 )
goto error;
V_18 = NULL ;
if ( V_109 ) {
V_3 = - V_20 ;
V_18 = F_14 ( V_17 , V_21 ) ;
if ( ! V_18 ) {
if ( V_17 <= V_19 )
goto error;
V_110 = true ;
V_18 = F_75 ( V_17 ) ;
if ( ! V_18 )
goto error;
}
V_3 = F_72 ( V_18 , V_109 , V_106 ) ;
if ( V_3 < 0 )
goto V_23;
}
V_3 = F_67 ( V_32 , V_96 , & V_101 ) ;
if ( V_3 < 0 )
goto V_23;
V_3 = F_76 ( V_96 -> V_112 , V_18 , V_17 ,
V_101 , V_42 ) ;
F_33 ( V_101 ) ;
if ( V_3 == 0 )
F_69 ( NULL ) ;
V_23:
if ( ! V_110 )
F_12 ( V_18 ) ;
else
F_77 ( V_18 ) ;
error:
return V_3 ;
}
long F_78 ( T_2 V_6 ,
const void T_1 * V_16 ,
T_4 V_17 ,
T_2 V_32 )
{
if ( V_16 && V_17 ) {
struct V_104 V_105 [ 1 ] = {
[ 0 ] . V_107 = ( void T_1 * ) V_16 ,
[ 0 ] . V_108 = V_17
} ;
return F_73 ( V_6 , V_105 , 1 , V_17 , V_32 ) ;
}
return F_73 ( V_6 , NULL , 0 , 0 , V_32 ) ;
}
long F_79 ( T_2 V_6 ,
const struct V_104 T_1 * V_113 ,
unsigned V_106 ,
T_2 V_32 )
{
struct V_104 V_114 [ V_115 ] , * V_105 = V_114 ;
long V_3 ;
if ( ! V_113 || ! V_106 )
goto V_116;
V_3 = F_80 ( V_117 , V_113 , V_106 ,
F_81 ( V_114 ) , V_114 , & V_105 ) ;
if ( V_3 < 0 )
goto V_118;
if ( V_3 == 0 )
goto V_119;
V_3 = F_73 ( V_6 , V_105 , V_106 , V_3 , V_32 ) ;
V_118:
if ( V_105 != V_114 )
F_12 ( V_105 ) ;
return V_3 ;
V_119:
if ( V_105 != V_114 )
F_12 ( V_105 ) ;
V_116:
return F_73 ( V_6 , NULL , 0 , 0 , V_32 ) ;
}
long F_82 ( T_2 V_6 , unsigned V_120 , T_2 V_32 )
{
return F_83 ( V_6 , V_120 , V_61 , V_32 ) ;
}
long F_83 ( T_2 V_6 , unsigned V_120 , unsigned error ,
T_2 V_32 )
{
const struct V_102 * V_102 = F_74 () ;
struct V_95 * V_96 ;
struct V_41 * V_42 , * V_101 ;
long V_3 ;
F_20 ( L_5 , V_6 , V_120 , error , V_32 ) ;
if ( error <= 0 ||
error >= V_121 ||
error == V_122 ||
error == V_123 ||
error == V_124 ||
error == V_125 )
return - V_4 ;
V_3 = - V_5 ;
V_42 = V_102 -> V_95 ;
if ( ! V_42 )
goto error;
V_96 = V_42 -> V_18 . V_111 ;
if ( V_96 -> V_112 -> V_12 != V_6 )
goto error;
V_3 = F_67 ( V_32 , V_96 , & V_101 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_84 ( V_96 -> V_112 , V_120 , error ,
V_101 , V_42 ) ;
F_33 ( V_101 ) ;
if ( V_3 == 0 )
F_69 ( NULL ) ;
error:
return V_3 ;
}
long F_85 ( int V_126 )
{
struct V_102 * V_103 ;
int V_3 , V_127 ;
V_127 = F_86 ( V_128 ) ;
if ( V_126 == V_129 )
return V_127 ;
V_103 = F_70 () ;
if ( ! V_103 )
return - V_20 ;
switch ( V_126 ) {
case V_130 :
V_3 = F_87 ( V_103 ) ;
if ( V_3 < 0 )
goto error;
goto V_131;
case V_132 :
V_3 = F_88 ( V_103 ) ;
if ( V_3 < 0 ) {
if ( V_3 != - V_133 )
goto error;
V_3 = 0 ;
}
goto V_131;
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
goto V_131;
case V_129 :
case V_139 :
default:
V_3 = - V_4 ;
goto error;
}
V_131:
V_103 -> V_128 = V_126 ;
F_71 ( V_103 ) ;
return V_127 ;
error:
F_89 ( V_103 ) ;
return V_3 ;
}
long F_90 ( T_2 V_6 , unsigned V_120 )
{
struct V_41 * V_41 , * V_42 ;
T_3 V_8 ;
long V_3 ;
V_8 = F_4 ( V_6 , V_10 | V_46 ,
V_26 ) ;
if ( F_5 ( V_8 ) ) {
if ( F_6 ( V_8 ) == - V_25 ) {
V_42 = F_32 ( V_6 ) ;
if ( ! F_5 ( V_42 ) ) {
F_33 ( V_42 ) ;
V_8 = F_4 ( V_6 ,
V_46 ,
0 ) ;
if ( ! F_5 ( V_8 ) )
goto V_48;
}
}
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_48:
V_41 = F_7 ( V_8 ) ;
F_91 ( V_41 , V_120 ) ;
F_33 ( V_41 ) ;
V_3 = 0 ;
error:
return V_3 ;
}
long F_92 ( T_2 V_6 )
{
struct V_41 * V_140 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_6 < 0 )
goto error;
if ( V_6 == 0 ) {
V_3 = F_69 ( NULL ) ;
goto error;
}
V_140 = F_32 ( V_6 ) ;
if ( F_5 ( V_140 ) ) {
V_3 = F_6 ( V_140 ) ;
goto error;
}
V_3 = F_69 ( V_140 ) ;
if ( V_3 < 0 )
goto error;
F_33 ( V_140 ) ;
V_3 = V_140 -> V_12 ;
error:
return V_3 ;
}
long F_93 ( T_2 V_38 ,
char T_1 * V_39 ,
T_4 V_40 )
{
struct V_41 * V_41 , * V_42 ;
T_3 V_8 ;
char * V_141 ;
long V_3 ;
V_8 = F_4 ( V_38 , V_46 , V_47 ) ;
if ( F_5 ( V_8 ) ) {
if ( F_6 ( V_8 ) != - V_25 )
return F_6 ( V_8 ) ;
V_42 = F_32 ( V_38 ) ;
if ( F_5 ( V_42 ) )
return F_6 ( V_42 ) ;
F_33 ( V_42 ) ;
V_8 = F_4 ( V_38 , V_46 , 0 ) ;
if ( F_5 ( V_8 ) )
return F_6 ( V_8 ) ;
}
V_41 = F_7 ( V_8 ) ;
V_3 = F_94 ( V_41 , & V_141 ) ;
if ( V_3 == 0 ) {
V_3 = 1 ;
if ( V_39 && V_40 > 0 &&
F_38 ( V_39 , L_6 , 1 ) != 0 )
V_3 = - V_22 ;
} else if ( V_3 > 0 ) {
if ( V_39 && V_40 > 0 ) {
if ( V_40 > V_3 )
V_40 = V_3 ;
if ( F_38 ( V_39 , V_141 , V_40 ) != 0 )
V_3 = - V_22 ;
}
F_12 ( V_141 ) ;
}
F_8 ( V_8 ) ;
return V_3 ;
}
long F_95 ( void )
{
struct V_142 * V_143 , * V_144 ;
const struct V_102 * V_145 , * V_146 ;
struct V_147 * V_148 , * V_149 ;
T_3 V_150 ;
struct V_102 * V_102 ;
int V_3 ;
V_150 = F_4 ( V_151 , 0 , V_36 ) ;
if ( F_5 ( V_150 ) )
return F_6 ( V_150 ) ;
V_3 = - V_20 ;
V_102 = F_96 () ;
if ( ! V_102 )
goto V_152;
V_148 = & V_102 -> V_153 ;
V_102 -> V_154 = F_7 ( V_150 ) ;
V_150 = NULL ;
F_97 ( V_148 , V_155 ) ;
V_143 = V_156 ;
F_98 () ;
F_99 ( & V_157 ) ;
V_3 = - V_5 ;
V_149 = NULL ;
V_144 = V_143 -> V_158 ;
if ( V_144 -> V_159 <= 1 || ! V_144 -> V_160 )
goto V_161;
if ( ! F_100 ( V_144 ) )
goto V_161;
V_145 = F_74 () ;
V_146 = F_101 ( V_144 ) ;
if ( V_145 == V_146 ||
V_145 -> V_154 == V_146 -> V_154 ) {
V_3 = 0 ;
goto V_161;
}
if ( ! F_55 ( V_146 -> V_50 , V_145 -> V_162 ) ||
! F_55 ( V_146 -> V_162 , V_145 -> V_162 ) ||
! F_55 ( V_146 -> V_163 , V_145 -> V_162 ) ||
! F_56 ( V_146 -> V_51 , V_145 -> V_164 ) ||
! F_56 ( V_146 -> V_164 , V_145 -> V_164 ) ||
! F_56 ( V_146 -> V_165 , V_145 -> V_164 ) )
goto V_161;
if ( ( V_146 -> V_154 &&
! F_55 ( V_146 -> V_154 -> V_50 , V_145 -> V_162 ) ) ||
! F_55 ( V_145 -> V_154 -> V_50 , V_145 -> V_162 ) )
goto V_161;
V_149 = F_102 ( V_144 , V_155 ) ;
V_3 = F_103 ( V_144 , V_148 , true ) ;
if ( ! V_3 )
V_148 = NULL ;
V_161:
F_104 ( & V_157 ) ;
F_105 () ;
if ( V_149 )
F_106 ( F_107 ( V_149 , struct V_102 , V_153 ) ) ;
if ( V_148 )
F_106 ( V_102 ) ;
return V_3 ;
V_152:
F_8 ( V_150 ) ;
return V_3 ;
}
