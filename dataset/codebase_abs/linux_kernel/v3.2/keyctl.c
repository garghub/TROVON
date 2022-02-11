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
if ( V_17 > V_15 )
goto error;
V_18 = NULL ;
if ( V_16 ) {
V_3 = - V_19 ;
V_18 = F_14 ( V_17 , V_20 ) ;
if ( ! V_18 )
goto error;
V_3 = - V_21 ;
if ( F_15 ( V_18 , V_16 , V_17 ) != 0 )
goto V_22;
}
V_8 = F_4 ( V_6 , 0 , V_23 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto V_22;
}
V_3 = F_16 ( V_8 , V_18 , V_17 ) ;
F_8 ( V_8 ) ;
V_22:
F_12 ( V_18 ) ;
error:
return V_3 ;
}
long F_17 ( T_2 V_6 )
{
T_3 V_8 ;
long V_3 ;
V_8 = F_4 ( V_6 , 0 , V_23 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
if ( V_3 != - V_24 )
goto error;
V_8 = F_4 ( V_6 , 0 , V_25 ) ;
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
long F_19 ( T_2 V_26 )
{
T_3 V_27 ;
long V_3 ;
V_27 = F_4 ( V_26 , V_10 , V_23 ) ;
if ( F_5 ( V_27 ) ) {
V_3 = F_6 ( V_27 ) ;
goto error;
}
V_3 = F_20 ( F_7 ( V_27 ) ) ;
F_8 ( V_27 ) ;
error:
return V_3 ;
}
long F_21 ( T_2 V_6 , T_2 V_26 )
{
T_3 V_27 , V_8 ;
long V_3 ;
V_27 = F_4 ( V_26 , V_10 , V_23 ) ;
if ( F_5 ( V_27 ) ) {
V_3 = F_6 ( V_27 ) ;
goto error;
}
V_8 = F_4 ( V_6 , V_10 , V_28 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto V_22;
}
V_3 = F_22 ( F_7 ( V_27 ) , F_7 ( V_8 ) ) ;
F_8 ( V_8 ) ;
V_22:
F_8 ( V_27 ) ;
error:
return V_3 ;
}
long F_23 ( T_2 V_6 , T_2 V_26 )
{
T_3 V_27 , V_8 ;
long V_3 ;
V_27 = F_4 ( V_26 , 0 , V_23 ) ;
if ( F_5 ( V_27 ) ) {
V_3 = F_6 ( V_27 ) ;
goto error;
}
V_8 = F_4 ( V_6 , V_29 , 0 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto V_22;
}
V_3 = F_24 ( F_7 ( V_27 ) , F_7 ( V_8 ) ) ;
F_8 ( V_8 ) ;
V_22:
F_8 ( V_27 ) ;
error:
return V_3 ;
}
long F_25 ( T_2 V_30 ,
char T_1 * V_31 ,
T_4 V_32 )
{
struct V_33 * V_33 , * V_34 ;
T_3 V_8 ;
char * V_35 ;
long V_3 ;
V_8 = F_4 ( V_30 , V_36 , V_37 ) ;
if ( F_5 ( V_8 ) ) {
if ( F_6 ( V_8 ) == - V_24 ) {
V_34 = F_26 ( V_30 ) ;
if ( ! F_5 ( V_34 ) ) {
F_27 ( V_34 ) ;
V_8 = F_4 ( V_30 ,
V_36 ,
0 ) ;
if ( ! F_5 ( V_8 ) )
goto V_38;
}
}
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_38:
V_3 = - V_19 ;
V_35 = F_14 ( V_15 , V_20 ) ;
if ( ! V_35 )
goto V_22;
V_33 = F_7 ( V_8 ) ;
V_3 = snprintf ( V_35 , V_15 - 1 ,
L_1 ,
V_33 -> type -> V_14 ,
V_33 -> V_39 ,
V_33 -> V_40 ,
V_33 -> V_41 ,
V_33 -> V_42 ? : L_2 ) ;
if ( V_3 > V_15 - 1 )
V_3 = V_15 - 1 ;
V_35 [ V_3 ] = 0 ;
V_3 ++ ;
if ( V_31 && V_32 > 0 ) {
if ( V_32 > V_3 )
V_32 = V_3 ;
if ( F_28 ( V_31 , V_35 , V_32 ) != 0 )
V_3 = - V_21 ;
}
F_12 ( V_35 ) ;
V_22:
F_8 ( V_8 ) ;
error:
return V_3 ;
}
long F_29 ( T_2 V_26 ,
const char T_1 * V_1 ,
const char T_1 * V_43 ,
T_2 V_44 )
{
struct V_45 * V_46 ;
T_3 V_27 , V_8 , V_47 ;
char type [ 32 ] , * V_42 ;
long V_3 ;
V_3 = F_1 ( type , V_1 , sizeof( type ) ) ;
if ( V_3 < 0 )
goto error;
V_42 = F_10 ( V_43 , V_15 ) ;
if ( F_5 ( V_42 ) ) {
V_3 = F_6 ( V_42 ) ;
goto error;
}
V_27 = F_4 ( V_26 , 0 , V_11 ) ;
if ( F_5 ( V_27 ) ) {
V_3 = F_6 ( V_27 ) ;
goto V_22;
}
V_47 = NULL ;
if ( V_44 ) {
V_47 = F_4 ( V_44 , V_10 ,
V_23 ) ;
if ( F_5 ( V_47 ) ) {
V_3 = F_6 ( V_47 ) ;
goto V_48;
}
}
V_46 = F_30 ( type ) ;
if ( F_5 ( V_46 ) ) {
V_3 = F_6 ( V_46 ) ;
goto V_49;
}
V_8 = F_31 ( V_27 , V_46 , V_42 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
if ( V_3 == - V_50 )
V_3 = - V_51 ;
goto V_52;
}
if ( V_47 ) {
V_3 = F_32 ( V_8 , V_28 ) ;
if ( V_3 < 0 )
goto V_53;
V_3 = F_22 ( F_7 ( V_47 ) , F_7 ( V_8 ) ) ;
if ( V_3 < 0 )
goto V_53;
}
V_3 = F_7 ( V_8 ) -> V_12 ;
V_53:
F_8 ( V_8 ) ;
V_52:
F_33 ( V_46 ) ;
V_49:
F_8 ( V_47 ) ;
V_48:
F_8 ( V_27 ) ;
V_22:
F_12 ( V_42 ) ;
error:
return V_3 ;
}
long F_34 ( T_2 V_30 , char T_1 * V_31 , T_4 V_32 )
{
struct V_33 * V_33 ;
T_3 V_8 ;
long V_3 ;
V_8 = F_4 ( V_30 , 0 , 0 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = - V_51 ;
goto error;
}
V_33 = F_7 ( V_8 ) ;
V_3 = F_32 ( V_8 , V_54 ) ;
if ( V_3 == 0 )
goto V_55;
if ( V_3 != - V_24 )
goto error;
if ( ! F_35 ( V_8 ) ) {
V_3 = - V_24 ;
goto V_22;
}
V_55:
V_3 = F_36 ( V_33 ) ;
if ( V_3 == 0 ) {
V_3 = - V_56 ;
if ( V_33 -> type -> V_57 ) {
F_37 ( & V_33 -> V_58 ) ;
V_3 = V_33 -> type -> V_57 ( V_33 , V_31 , V_32 ) ;
F_38 ( & V_33 -> V_58 ) ;
}
}
V_22:
F_27 ( V_33 ) ;
error:
return V_3 ;
}
long F_39 ( T_2 V_6 , T_5 V_39 , T_6 V_40 )
{
struct V_59 * V_60 , * V_61 = NULL ;
struct V_33 * V_33 ;
T_3 V_8 ;
long V_3 ;
V_3 = 0 ;
if ( V_39 == ( T_5 ) - 1 && V_40 == ( T_6 ) - 1 )
goto error;
V_8 = F_4 ( V_6 , V_10 | V_36 ,
V_25 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_33 = F_7 ( V_8 ) ;
V_3 = - V_24 ;
F_40 ( & V_33 -> V_58 ) ;
if ( ! F_41 ( V_62 ) ) {
if ( V_39 != ( T_5 ) - 1 && V_33 -> V_39 != V_39 )
goto V_63;
if ( V_40 != ( T_6 ) - 1 && V_40 != V_33 -> V_40 && ! F_42 ( V_40 ) )
goto V_63;
}
if ( V_39 != ( T_5 ) - 1 && V_39 != V_33 -> V_39 ) {
V_3 = - V_19 ;
V_60 = F_43 ( V_39 , F_44 () ) ;
if ( ! V_60 )
goto V_63;
if ( F_45 ( V_64 , & V_33 -> V_65 ) ) {
unsigned V_66 = ( V_39 == 0 ) ?
V_67 : V_68 ;
unsigned V_69 = ( V_39 == 0 ) ?
V_70 : V_71 ;
F_46 ( & V_60 -> V_72 ) ;
if ( V_60 -> V_73 + 1 >= V_66 ||
V_60 -> V_74 + V_33 -> V_75 >= V_69 ||
V_60 -> V_74 + V_33 -> V_75 <
V_60 -> V_74 )
goto V_76;
V_60 -> V_73 ++ ;
V_60 -> V_74 += V_33 -> V_75 ;
F_47 ( & V_60 -> V_72 ) ;
F_46 ( & V_33 -> V_77 -> V_72 ) ;
V_33 -> V_77 -> V_73 -- ;
V_33 -> V_77 -> V_74 -= V_33 -> V_75 ;
F_47 ( & V_33 -> V_77 -> V_72 ) ;
}
F_48 ( & V_33 -> V_77 -> V_78 ) ;
F_49 ( & V_60 -> V_78 ) ;
if ( F_45 ( V_79 , & V_33 -> V_65 ) ) {
F_48 ( & V_33 -> V_77 -> V_80 ) ;
F_49 ( & V_60 -> V_80 ) ;
}
V_61 = V_33 -> V_77 ;
V_33 -> V_77 = V_60 ;
V_33 -> V_39 = V_39 ;
}
if ( V_40 != ( T_6 ) - 1 )
V_33 -> V_40 = V_40 ;
V_3 = 0 ;
V_63:
F_50 ( & V_33 -> V_58 ) ;
F_27 ( V_33 ) ;
if ( V_61 )
F_51 ( V_61 ) ;
error:
return V_3 ;
V_76:
F_47 ( & V_60 -> V_72 ) ;
V_61 = V_60 ;
V_3 = - V_81 ;
goto V_63;
}
long F_52 ( T_2 V_6 , T_7 V_41 )
{
struct V_33 * V_33 ;
T_3 V_8 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_41 & ~ ( V_82 | V_83 | V_84 | V_85 ) )
goto error;
V_8 = F_4 ( V_6 , V_10 | V_36 ,
V_25 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_33 = F_7 ( V_8 ) ;
V_3 = - V_24 ;
F_40 ( & V_33 -> V_58 ) ;
if ( F_41 ( V_62 ) || V_33 -> V_39 == F_53 () ) {
V_33 -> V_41 = V_41 ;
V_3 = 0 ;
}
F_50 ( & V_33 -> V_58 ) ;
F_27 ( V_33 ) ;
error:
return V_3 ;
}
static long F_54 ( T_2 V_26 ,
struct V_86 * V_87 ,
struct V_33 * * V_88 )
{
T_3 V_89 ;
* V_88 = NULL ;
if ( V_26 == 0 )
return 0 ;
if ( V_26 > 0 ) {
V_89 = F_4 ( V_26 , V_10 , V_23 ) ;
if ( F_5 ( V_89 ) )
return F_6 ( V_89 ) ;
* V_88 = F_7 ( V_89 ) ;
return 0 ;
}
if ( V_26 == V_90 )
return - V_4 ;
if ( V_26 >= V_91 ) {
* V_88 = F_55 ( V_87 -> V_92 ) ;
return 0 ;
}
return - V_51 ;
}
static int F_56 ( struct V_33 * V_33 )
{
struct V_93 * V_94 ;
V_94 = F_57 () ;
if ( ! V_94 )
return - V_19 ;
F_27 ( V_94 -> V_86 ) ;
V_94 -> V_86 = F_55 ( V_33 ) ;
return F_58 ( V_94 ) ;
}
static long F_59 ( void * V_31 , const struct V_95 * V_96 ,
unsigned V_97 )
{
for (; V_97 > 0 ; V_97 -- ) {
if ( F_15 ( V_31 , V_96 -> V_98 , V_96 -> V_99 ) != 0 )
return - V_21 ;
V_31 += V_96 -> V_99 ;
V_96 ++ ;
}
return 0 ;
}
long F_60 ( T_2 V_6 ,
const struct V_95 * V_100 ,
unsigned V_97 ,
T_4 V_17 ,
T_2 V_26 )
{
const struct V_93 * V_93 = F_61 () ;
struct V_86 * V_87 ;
struct V_33 * V_34 , * V_92 ;
void * V_18 ;
long V_3 ;
bool V_101 = false ;
F_62 ( L_3 , V_6 , V_17 , V_26 ) ;
V_3 = - V_4 ;
if ( V_17 > 1024 * 1024 - 1 )
goto error;
V_3 = - V_5 ;
V_34 = V_93 -> V_86 ;
if ( ! V_34 )
goto error;
V_87 = V_34 -> V_18 . V_102 ;
if ( V_87 -> V_103 -> V_12 != V_6 )
goto error;
V_18 = NULL ;
if ( V_100 ) {
V_3 = - V_19 ;
V_18 = F_14 ( V_17 , V_20 ) ;
if ( ! V_18 ) {
if ( V_17 <= V_15 )
goto error;
V_101 = true ;
V_18 = F_63 ( V_17 ) ;
if ( ! V_18 )
goto error;
}
V_3 = F_59 ( V_18 , V_100 , V_97 ) ;
if ( V_3 < 0 )
goto V_22;
}
V_3 = F_54 ( V_26 , V_87 , & V_92 ) ;
if ( V_3 < 0 )
goto V_22;
V_3 = F_64 ( V_87 -> V_103 , V_18 , V_17 ,
V_92 , V_34 ) ;
F_27 ( V_92 ) ;
if ( V_3 == 0 )
F_56 ( NULL ) ;
V_22:
if ( ! V_101 )
F_12 ( V_18 ) ;
else
F_65 ( V_18 ) ;
error:
return V_3 ;
}
long F_66 ( T_2 V_6 ,
const void T_1 * V_16 ,
T_4 V_17 ,
T_2 V_26 )
{
if ( V_16 && V_17 ) {
struct V_95 V_96 [ 1 ] = {
[ 0 ] . V_98 = ( void T_1 * ) V_16 ,
[ 0 ] . V_99 = V_17
} ;
return F_60 ( V_6 , V_96 , 1 , V_17 , V_26 ) ;
}
return F_60 ( V_6 , NULL , 0 , 0 , V_26 ) ;
}
long F_67 ( T_2 V_6 ,
const struct V_95 T_1 * V_104 ,
unsigned V_97 ,
T_2 V_26 )
{
struct V_95 V_105 [ V_106 ] , * V_96 = V_105 ;
long V_3 ;
if ( V_104 == 0 || V_97 == 0 )
goto V_107;
V_3 = F_68 ( V_108 , V_104 , V_97 ,
F_69 ( V_105 ) , V_105 , & V_96 , 1 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 == 0 )
goto V_109;
V_3 = F_60 ( V_6 , V_96 , V_97 , V_3 , V_26 ) ;
if ( V_96 != V_105 )
F_12 ( V_96 ) ;
return V_3 ;
V_109:
if ( V_96 != V_105 )
F_12 ( V_96 ) ;
V_107:
return F_60 ( V_6 , NULL , 0 , 0 , V_26 ) ;
}
long F_70 ( T_2 V_6 , unsigned V_110 , T_2 V_26 )
{
return F_71 ( V_6 , V_110 , V_51 , V_26 ) ;
}
long F_71 ( T_2 V_6 , unsigned V_110 , unsigned error ,
T_2 V_26 )
{
const struct V_93 * V_93 = F_61 () ;
struct V_86 * V_87 ;
struct V_33 * V_34 , * V_92 ;
long V_3 ;
F_62 ( L_4 , V_6 , V_110 , error , V_26 ) ;
if ( error <= 0 ||
error >= V_111 ||
error == V_112 ||
error == V_113 ||
error == V_114 ||
error == V_115 )
return - V_4 ;
V_3 = - V_5 ;
V_34 = V_93 -> V_86 ;
if ( ! V_34 )
goto error;
V_87 = V_34 -> V_18 . V_102 ;
if ( V_87 -> V_103 -> V_12 != V_6 )
goto error;
V_3 = F_54 ( V_26 , V_87 , & V_92 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_72 ( V_87 -> V_103 , V_110 , error ,
V_92 , V_34 ) ;
F_27 ( V_92 ) ;
if ( V_3 == 0 )
F_56 ( NULL ) ;
error:
return V_3 ;
}
long F_73 ( int V_116 )
{
struct V_93 * V_94 ;
int V_3 , V_117 ;
V_117 = F_74 ( V_118 ) ;
if ( V_116 == V_119 )
return V_117 ;
V_94 = F_57 () ;
if ( ! V_94 )
return - V_19 ;
switch ( V_116 ) {
case V_120 :
V_3 = F_75 ( V_94 ) ;
if ( V_3 < 0 )
goto error;
goto V_121;
case V_122 :
V_3 = F_76 ( V_94 ) ;
if ( V_3 < 0 ) {
if ( V_3 != - V_123 )
goto error;
V_3 = 0 ;
}
goto V_121;
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
goto V_121;
case V_119 :
case V_129 :
default:
V_3 = - V_4 ;
goto error;
}
V_121:
V_94 -> V_118 = V_116 ;
F_58 ( V_94 ) ;
return V_117 ;
error:
F_77 ( V_94 ) ;
return V_3 ;
}
long F_78 ( T_2 V_6 , unsigned V_110 )
{
struct V_130 V_131 ;
struct V_33 * V_33 , * V_34 ;
T_3 V_8 ;
T_8 V_132 ;
long V_3 ;
V_8 = F_4 ( V_6 , V_10 | V_36 ,
V_25 ) ;
if ( F_5 ( V_8 ) ) {
if ( F_6 ( V_8 ) == - V_24 ) {
V_34 = F_26 ( V_6 ) ;
if ( ! F_5 ( V_34 ) ) {
F_27 ( V_34 ) ;
V_8 = F_4 ( V_6 ,
V_36 ,
0 ) ;
if ( ! F_5 ( V_8 ) )
goto V_38;
}
}
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_38:
V_33 = F_7 ( V_8 ) ;
F_40 ( & V_33 -> V_58 ) ;
V_132 = 0 ;
if ( V_110 > 0 ) {
V_131 = F_79 () ;
V_132 = V_131 . V_133 + V_110 ;
}
V_33 -> V_132 = V_132 ;
F_80 ( V_33 -> V_132 + V_134 ) ;
F_50 ( & V_33 -> V_58 ) ;
F_27 ( V_33 ) ;
V_3 = 0 ;
error:
return V_3 ;
}
long F_81 ( T_2 V_6 )
{
struct V_33 * V_135 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_6 < 0 )
goto error;
if ( V_6 == 0 ) {
V_3 = F_56 ( NULL ) ;
goto error;
}
V_135 = F_26 ( V_6 ) ;
if ( F_5 ( V_135 ) ) {
V_3 = F_6 ( V_135 ) ;
goto error;
}
V_3 = F_56 ( V_135 ) ;
if ( V_3 < 0 )
goto error;
F_27 ( V_135 ) ;
V_3 = V_135 -> V_12 ;
error:
return V_3 ;
}
long F_82 ( T_2 V_30 ,
char T_1 * V_31 ,
T_4 V_32 )
{
struct V_33 * V_33 , * V_34 ;
T_3 V_8 ;
char * V_136 ;
long V_3 ;
V_8 = F_4 ( V_30 , V_36 , V_37 ) ;
if ( F_5 ( V_8 ) ) {
if ( F_6 ( V_8 ) != - V_24 )
return F_6 ( V_8 ) ;
V_34 = F_26 ( V_30 ) ;
if ( F_5 ( V_34 ) )
return F_6 ( V_34 ) ;
F_27 ( V_34 ) ;
V_8 = F_4 ( V_30 , V_36 , 0 ) ;
if ( F_5 ( V_8 ) )
return F_6 ( V_8 ) ;
}
V_33 = F_7 ( V_8 ) ;
V_3 = F_83 ( V_33 , & V_136 ) ;
if ( V_3 == 0 ) {
V_3 = 1 ;
if ( V_31 && V_32 > 0 &&
F_28 ( V_31 , L_2 , 1 ) != 0 )
V_3 = - V_21 ;
} else if ( V_3 > 0 ) {
if ( V_31 && V_32 > 0 ) {
if ( V_32 > V_3 )
V_32 = V_3 ;
if ( F_28 ( V_31 , V_136 , V_32 ) != 0 )
V_3 = - V_21 ;
}
F_12 ( V_136 ) ;
}
F_8 ( V_8 ) ;
return V_3 ;
}
long F_84 ( void )
{
#ifdef F_85
struct V_137 * V_138 , * V_139 ;
const struct V_93 * V_140 , * V_141 ;
struct V_93 * V_93 , * V_142 ;
T_3 V_143 ;
int V_3 ;
V_143 = F_4 ( V_144 , 0 , V_28 ) ;
if ( F_5 ( V_143 ) )
return F_6 ( V_143 ) ;
V_3 = - V_19 ;
V_93 = F_86 () ;
if ( ! V_93 )
goto V_145;
V_93 -> V_146 -> V_147 = F_7 ( V_143 ) ;
V_143 = NULL ;
V_138 = V_148 ;
F_87 () ;
F_88 ( & V_149 ) ;
V_139 = V_138 -> V_150 ;
V_3 = - V_5 ;
if ( V_139 -> V_151 <= 1 || ! V_139 -> V_152 )
goto V_153;
if ( ! F_89 ( V_139 ) )
goto V_153;
V_140 = F_61 () ;
V_141 = F_90 ( V_139 ) ;
if ( V_140 == V_141 ||
V_140 -> V_146 -> V_147 == V_141 -> V_146 -> V_147 )
goto V_154;
if ( V_141 -> V_39 != V_140 -> V_155 ||
V_141 -> V_155 != V_140 -> V_155 ||
V_141 -> V_156 != V_140 -> V_155 ||
V_141 -> V_40 != V_140 -> V_157 ||
V_141 -> V_157 != V_140 -> V_157 ||
V_141 -> V_158 != V_140 -> V_157 )
goto V_153;
if ( ( V_141 -> V_146 -> V_147 &&
V_141 -> V_146 -> V_147 -> V_39 != V_140 -> V_155 ) ||
V_140 -> V_146 -> V_147 -> V_39 != V_140 -> V_155 )
goto V_153;
V_142 = V_139 -> V_159 ;
V_139 -> V_159 = V_93 ;
V_93 = NULL ;
F_91 ( F_92 ( V_139 ) , F_85 ) ;
F_93 ( & V_149 ) ;
F_94 () ;
if ( V_142 )
F_95 ( V_142 ) ;
return 0 ;
V_154:
V_3 = 0 ;
V_153:
F_93 ( & V_149 ) ;
F_94 () ;
F_95 ( V_93 ) ;
return V_3 ;
V_145:
F_8 ( V_143 ) ;
return V_3 ;
#else
#warning TIF_NOTIFY_RESUME not implemented
return - V_56 ;
#endif
}
