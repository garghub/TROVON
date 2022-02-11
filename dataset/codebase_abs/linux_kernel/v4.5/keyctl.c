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
struct V_25 * V_25 ;
long V_3 ;
V_8 = F_4 ( V_6 , 0 , V_24 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
if ( V_3 != - V_26 )
goto error;
V_8 = F_4 ( V_6 , 0 , V_27 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
}
V_25 = F_7 ( V_8 ) ;
V_3 = 0 ;
if ( F_18 ( V_28 , & V_25 -> V_29 ) )
V_3 = - V_5 ;
else
F_19 ( V_25 ) ;
F_8 ( V_8 ) ;
error:
return V_3 ;
}
long F_20 ( T_2 V_6 )
{
T_3 V_8 ;
struct V_25 * V_25 ;
long V_3 ;
F_21 ( L_1 , V_6 ) ;
V_8 = F_4 ( V_6 , 0 , V_11 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
if ( F_22 ( V_30 ) ) {
V_8 = F_4 ( V_6 , 0 , 0 ) ;
if ( F_5 ( V_8 ) )
goto error;
if ( F_18 ( V_31 ,
& F_7 ( V_8 ) -> V_29 ) )
goto V_32;
goto V_33;
}
goto error;
}
V_32:
V_25 = F_7 ( V_8 ) ;
V_3 = 0 ;
if ( F_18 ( V_28 , & V_25 -> V_29 ) )
V_3 = - V_5 ;
else
F_23 ( V_25 ) ;
V_33:
F_8 ( V_8 ) ;
error:
F_24 ( L_2 , V_3 ) ;
return V_3 ;
}
long F_25 ( T_2 V_34 )
{
T_3 V_35 ;
struct V_25 * V_36 ;
long V_3 ;
V_35 = F_4 ( V_34 , V_10 , V_24 ) ;
if ( F_5 ( V_35 ) ) {
V_3 = F_6 ( V_35 ) ;
if ( F_22 ( V_30 ) ) {
V_35 = F_4 ( V_34 , 0 , 0 ) ;
if ( F_5 ( V_35 ) )
goto error;
if ( F_18 ( V_37 ,
& F_7 ( V_35 ) -> V_29 ) )
goto V_38;
goto V_33;
}
goto error;
}
V_38:
V_36 = F_7 ( V_35 ) ;
if ( F_18 ( V_28 , & V_36 -> V_29 ) )
V_3 = - V_5 ;
else
V_3 = F_26 ( V_36 ) ;
V_33:
F_8 ( V_35 ) ;
error:
return V_3 ;
}
long F_27 ( T_2 V_6 , T_2 V_34 )
{
T_3 V_35 , V_8 ;
long V_3 ;
V_35 = F_4 ( V_34 , V_10 , V_24 ) ;
if ( F_5 ( V_35 ) ) {
V_3 = F_6 ( V_35 ) ;
goto error;
}
V_8 = F_4 ( V_6 , V_10 , V_39 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto V_23;
}
V_3 = F_28 ( F_7 ( V_35 ) , F_7 ( V_8 ) ) ;
F_8 ( V_8 ) ;
V_23:
F_8 ( V_35 ) ;
error:
return V_3 ;
}
long F_29 ( T_2 V_6 , T_2 V_34 )
{
T_3 V_35 , V_8 ;
struct V_25 * V_36 , * V_25 ;
long V_3 ;
V_35 = F_4 ( V_34 , 0 , V_24 ) ;
if ( F_5 ( V_35 ) ) {
V_3 = F_6 ( V_35 ) ;
goto error;
}
V_8 = F_4 ( V_6 , V_40 , 0 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto V_23;
}
V_36 = F_7 ( V_35 ) ;
V_25 = F_7 ( V_8 ) ;
if ( F_18 ( V_28 , & V_36 -> V_29 ) &&
F_18 ( V_28 , & V_25 -> V_29 ) )
V_3 = - V_5 ;
else
V_3 = F_30 ( V_36 , V_25 ) ;
F_8 ( V_8 ) ;
V_23:
F_8 ( V_35 ) ;
error:
return V_3 ;
}
long F_31 ( T_2 V_41 ,
char T_1 * V_42 ,
T_4 V_43 )
{
struct V_25 * V_25 , * V_44 ;
T_3 V_8 ;
char * V_45 ;
long V_3 ;
int V_46 , V_47 ;
V_8 = F_4 ( V_41 , V_48 , V_49 ) ;
if ( F_5 ( V_8 ) ) {
if ( F_6 ( V_8 ) == - V_26 ) {
V_44 = F_32 ( V_41 ) ;
if ( ! F_5 ( V_44 ) ) {
F_33 ( V_44 ) ;
V_8 = F_4 ( V_41 ,
V_48 ,
0 ) ;
if ( ! F_5 ( V_8 ) )
goto V_50;
}
}
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_50:
V_25 = F_7 ( V_8 ) ;
V_46 = strlen ( V_25 -> V_51 ) ;
V_3 = - V_20 ;
V_45 = F_34 ( V_21 ,
L_3 ,
V_25 -> type -> V_14 ,
F_35 ( F_36 () , V_25 -> V_52 ) ,
F_37 ( F_36 () , V_25 -> V_53 ) ,
V_25 -> V_54 ) ;
if ( ! V_45 )
goto V_23;
V_47 = strlen ( V_45 ) ;
V_3 = V_47 + V_46 + 1 ;
if ( V_42 && V_43 >= V_3 ) {
if ( F_38 ( V_42 , V_45 , V_47 ) != 0 ||
F_38 ( V_42 + V_47 , V_25 -> V_51 ,
V_46 + 1 ) != 0 )
V_3 = - V_22 ;
}
F_12 ( V_45 ) ;
V_23:
F_8 ( V_8 ) ;
error:
return V_3 ;
}
long F_39 ( T_2 V_34 ,
const char T_1 * V_1 ,
const char T_1 * V_55 ,
T_2 V_56 )
{
struct V_57 * V_58 ;
T_3 V_35 , V_8 , V_59 ;
char type [ 32 ] , * V_51 ;
long V_3 ;
V_3 = F_1 ( type , V_1 , sizeof( type ) ) ;
if ( V_3 < 0 )
goto error;
V_51 = F_10 ( V_55 , V_15 ) ;
if ( F_5 ( V_51 ) ) {
V_3 = F_6 ( V_51 ) ;
goto error;
}
V_35 = F_4 ( V_34 , 0 , V_11 ) ;
if ( F_5 ( V_35 ) ) {
V_3 = F_6 ( V_35 ) ;
goto V_23;
}
V_59 = NULL ;
if ( V_56 ) {
V_59 = F_4 ( V_56 , V_10 ,
V_24 ) ;
if ( F_5 ( V_59 ) ) {
V_3 = F_6 ( V_59 ) ;
goto V_60;
}
}
V_58 = F_40 ( type ) ;
if ( F_5 ( V_58 ) ) {
V_3 = F_6 ( V_58 ) ;
goto V_61;
}
V_8 = F_41 ( V_35 , V_58 , V_51 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
if ( V_3 == - V_62 )
V_3 = - V_63 ;
goto V_64;
}
if ( V_59 ) {
V_3 = F_42 ( V_8 , V_39 ) ;
if ( V_3 < 0 )
goto V_65;
V_3 = F_28 ( F_7 ( V_59 ) , F_7 ( V_8 ) ) ;
if ( V_3 < 0 )
goto V_65;
}
V_3 = F_7 ( V_8 ) -> V_12 ;
V_65:
F_8 ( V_8 ) ;
V_64:
F_43 ( V_58 ) ;
V_61:
F_8 ( V_59 ) ;
V_60:
F_8 ( V_35 ) ;
V_23:
F_12 ( V_51 ) ;
error:
return V_3 ;
}
long F_44 ( T_2 V_41 , char T_1 * V_42 , T_4 V_43 )
{
struct V_25 * V_25 ;
T_3 V_8 ;
long V_3 ;
V_8 = F_4 ( V_41 , 0 , 0 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = - V_63 ;
goto error;
}
V_25 = F_7 ( V_8 ) ;
V_3 = F_42 ( V_8 , V_66 ) ;
if ( V_3 == 0 )
goto V_67;
if ( V_3 != - V_26 )
goto error;
if ( ! F_45 ( V_8 ) ) {
V_3 = - V_26 ;
goto V_23;
}
V_67:
V_3 = - V_68 ;
if ( V_25 -> type -> V_69 ) {
F_46 ( & V_25 -> V_70 ) ;
V_3 = F_47 ( V_25 ) ;
if ( V_3 == 0 )
V_3 = V_25 -> type -> V_69 ( V_25 , V_42 , V_43 ) ;
F_48 ( & V_25 -> V_70 ) ;
}
V_23:
F_33 ( V_25 ) ;
error:
return V_3 ;
}
long F_49 ( T_2 V_6 , T_5 V_71 , T_6 V_72 )
{
struct V_73 * V_74 , * V_75 = NULL ;
struct V_25 * V_25 ;
T_3 V_8 ;
long V_3 ;
T_7 V_52 ;
T_8 V_53 ;
V_52 = F_50 ( F_36 () , V_71 ) ;
V_53 = F_51 ( F_36 () , V_72 ) ;
V_3 = - V_4 ;
if ( ( V_71 != ( T_5 ) - 1 ) && ! F_52 ( V_52 ) )
goto error;
if ( ( V_72 != ( T_6 ) - 1 ) && ! F_53 ( V_53 ) )
goto error;
V_3 = 0 ;
if ( V_71 == ( T_5 ) - 1 && V_72 == ( T_6 ) - 1 )
goto error;
V_8 = F_4 ( V_6 , V_10 | V_48 ,
V_27 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_25 = F_7 ( V_8 ) ;
V_3 = - V_26 ;
F_54 ( & V_25 -> V_70 ) ;
if ( ! F_22 ( V_30 ) ) {
if ( V_71 != ( T_5 ) - 1 && ! F_55 ( V_25 -> V_52 , V_52 ) )
goto V_33;
if ( V_72 != ( T_6 ) - 1 && ! F_56 ( V_53 , V_25 -> V_53 ) && ! F_57 ( V_53 ) )
goto V_33;
}
if ( V_71 != ( T_5 ) - 1 && ! F_55 ( V_52 , V_25 -> V_52 ) ) {
V_3 = - V_20 ;
V_74 = F_58 ( V_52 ) ;
if ( ! V_74 )
goto V_33;
if ( F_18 ( V_76 , & V_25 -> V_29 ) ) {
unsigned V_77 = F_55 ( V_52 , V_78 ) ?
V_79 : V_80 ;
unsigned V_81 = F_55 ( V_52 , V_78 ) ?
V_82 : V_83 ;
F_59 ( & V_74 -> V_84 ) ;
if ( V_74 -> V_85 + 1 >= V_77 ||
V_74 -> V_86 + V_25 -> V_87 >= V_81 ||
V_74 -> V_86 + V_25 -> V_87 <
V_74 -> V_86 )
goto V_88;
V_74 -> V_85 ++ ;
V_74 -> V_86 += V_25 -> V_87 ;
F_60 ( & V_74 -> V_84 ) ;
F_59 ( & V_25 -> V_71 -> V_84 ) ;
V_25 -> V_71 -> V_85 -- ;
V_25 -> V_71 -> V_86 -= V_25 -> V_87 ;
F_60 ( & V_25 -> V_71 -> V_84 ) ;
}
F_61 ( & V_25 -> V_71 -> V_89 ) ;
F_62 ( & V_74 -> V_89 ) ;
if ( F_18 ( V_90 , & V_25 -> V_29 ) ) {
F_61 ( & V_25 -> V_71 -> V_91 ) ;
F_62 ( & V_74 -> V_91 ) ;
}
V_75 = V_25 -> V_71 ;
V_25 -> V_71 = V_74 ;
V_25 -> V_52 = V_52 ;
}
if ( V_72 != ( T_6 ) - 1 )
V_25 -> V_53 = V_53 ;
V_3 = 0 ;
V_33:
F_63 ( & V_25 -> V_70 ) ;
F_33 ( V_25 ) ;
if ( V_75 )
F_64 ( V_75 ) ;
error:
return V_3 ;
V_88:
F_60 ( & V_74 -> V_84 ) ;
V_75 = V_74 ;
V_3 = - V_92 ;
goto V_33;
}
long F_65 ( T_2 V_6 , T_9 V_54 )
{
struct V_25 * V_25 ;
T_3 V_8 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_54 & ~ ( V_93 | V_94 | V_95 | V_96 ) )
goto error;
V_8 = F_4 ( V_6 , V_10 | V_48 ,
V_27 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_25 = F_7 ( V_8 ) ;
V_3 = - V_26 ;
F_54 ( & V_25 -> V_70 ) ;
if ( F_22 ( V_30 ) || F_55 ( V_25 -> V_52 , F_66 () ) ) {
V_25 -> V_54 = V_54 ;
V_3 = 0 ;
}
F_63 ( & V_25 -> V_70 ) ;
F_33 ( V_25 ) ;
error:
return V_3 ;
}
static long F_67 ( T_2 V_34 ,
struct V_97 * V_98 ,
struct V_25 * * V_99 )
{
T_3 V_100 ;
* V_99 = NULL ;
if ( V_34 == 0 )
return 0 ;
if ( V_34 > 0 ) {
V_100 = F_4 ( V_34 , V_10 , V_24 ) ;
if ( F_5 ( V_100 ) )
return F_6 ( V_100 ) ;
* V_99 = F_7 ( V_100 ) ;
return 0 ;
}
if ( V_34 == V_101 )
return - V_4 ;
if ( V_34 >= V_102 ) {
* V_99 = F_68 ( V_98 -> V_103 ) ;
return 0 ;
}
return - V_63 ;
}
static int F_69 ( struct V_25 * V_25 )
{
struct V_104 * V_105 ;
V_105 = F_70 () ;
if ( ! V_105 )
return - V_20 ;
F_33 ( V_105 -> V_97 ) ;
V_105 -> V_97 = F_68 ( V_25 ) ;
return F_71 ( V_105 ) ;
}
long F_72 ( T_2 V_6 ,
struct V_106 * V_107 ,
T_2 V_34 )
{
const struct V_104 * V_104 = F_73 () ;
struct V_97 * V_98 ;
struct V_25 * V_44 , * V_103 ;
T_4 V_17 = V_107 ? F_74 ( V_107 ) : 0 ;
void * V_18 ;
long V_3 ;
F_21 ( L_4 , V_6 , V_17 , V_34 ) ;
if ( ! V_17 )
V_107 = NULL ;
V_3 = - V_4 ;
if ( V_17 > 1024 * 1024 - 1 )
goto error;
V_3 = - V_5 ;
V_44 = V_104 -> V_97 ;
if ( ! V_44 )
goto error;
V_98 = V_44 -> V_18 . V_108 [ 0 ] ;
if ( V_98 -> V_109 -> V_12 != V_6 )
goto error;
V_18 = NULL ;
if ( V_107 ) {
V_3 = - V_20 ;
V_18 = F_14 ( V_17 , V_21 ) ;
if ( ! V_18 ) {
if ( V_17 <= V_19 )
goto error;
V_18 = F_75 ( V_17 ) ;
if ( ! V_18 )
goto error;
}
V_3 = - V_22 ;
if ( F_76 ( V_18 , V_17 , V_107 ) != V_17 )
goto V_23;
}
V_3 = F_67 ( V_34 , V_98 , & V_103 ) ;
if ( V_3 < 0 )
goto V_23;
V_3 = F_77 ( V_98 -> V_109 , V_18 , V_17 ,
V_103 , V_44 ) ;
F_33 ( V_103 ) ;
if ( V_3 == 0 )
F_69 ( NULL ) ;
V_23:
F_78 ( V_18 ) ;
error:
return V_3 ;
}
long F_79 ( T_2 V_6 ,
const void T_1 * V_16 ,
T_4 V_17 ,
T_2 V_34 )
{
if ( V_16 && V_17 ) {
struct V_110 V_111 ;
struct V_106 V_107 ;
int V_3 ;
V_3 = F_80 ( V_112 , ( void T_1 * ) V_16 , V_17 ,
& V_111 , & V_107 ) ;
if ( F_81 ( V_3 ) )
return V_3 ;
return F_72 ( V_6 , & V_107 , V_34 ) ;
}
return F_72 ( V_6 , NULL , V_34 ) ;
}
long F_82 ( T_2 V_6 ,
const struct V_110 T_1 * V_113 ,
unsigned V_114 ,
T_2 V_34 )
{
struct V_110 V_115 [ V_116 ] , * V_111 = V_115 ;
struct V_106 V_107 ;
long V_3 ;
if ( ! V_113 )
V_114 = 0 ;
V_3 = F_83 ( V_112 , V_113 , V_114 ,
F_84 ( V_115 ) , & V_111 , & V_107 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_72 ( V_6 , & V_107 , V_34 ) ;
F_12 ( V_111 ) ;
return V_3 ;
}
long F_85 ( T_2 V_6 , unsigned V_117 , T_2 V_34 )
{
return F_86 ( V_6 , V_117 , V_63 , V_34 ) ;
}
long F_86 ( T_2 V_6 , unsigned V_117 , unsigned error ,
T_2 V_34 )
{
const struct V_104 * V_104 = F_73 () ;
struct V_97 * V_98 ;
struct V_25 * V_44 , * V_103 ;
long V_3 ;
F_21 ( L_5 , V_6 , V_117 , error , V_34 ) ;
if ( error <= 0 ||
error >= V_118 ||
error == V_119 ||
error == V_120 ||
error == V_121 ||
error == V_122 )
return - V_4 ;
V_3 = - V_5 ;
V_44 = V_104 -> V_97 ;
if ( ! V_44 )
goto error;
V_98 = V_44 -> V_18 . V_108 [ 0 ] ;
if ( V_98 -> V_109 -> V_12 != V_6 )
goto error;
V_3 = F_67 ( V_34 , V_98 , & V_103 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_87 ( V_98 -> V_109 , V_117 , error ,
V_103 , V_44 ) ;
F_33 ( V_103 ) ;
if ( V_3 == 0 )
F_69 ( NULL ) ;
error:
return V_3 ;
}
long F_88 ( int V_123 )
{
struct V_104 * V_105 ;
int V_3 , V_124 ;
V_124 = F_89 ( V_125 ) ;
if ( V_123 == V_126 )
return V_124 ;
V_105 = F_70 () ;
if ( ! V_105 )
return - V_20 ;
switch ( V_123 ) {
case V_127 :
V_3 = F_90 ( V_105 ) ;
if ( V_3 < 0 )
goto error;
goto V_128;
case V_129 :
V_3 = F_91 ( V_105 ) ;
if ( V_3 < 0 ) {
if ( V_3 != - V_130 )
goto error;
V_3 = 0 ;
}
goto V_128;
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
goto V_128;
case V_126 :
case V_136 :
default:
V_3 = - V_4 ;
goto error;
}
V_128:
V_105 -> V_125 = V_123 ;
F_71 ( V_105 ) ;
return V_124 ;
error:
F_92 ( V_105 ) ;
return V_3 ;
}
long F_93 ( T_2 V_6 , unsigned V_117 )
{
struct V_25 * V_25 , * V_44 ;
T_3 V_8 ;
long V_3 ;
V_8 = F_4 ( V_6 , V_10 | V_48 ,
V_27 ) ;
if ( F_5 ( V_8 ) ) {
if ( F_6 ( V_8 ) == - V_26 ) {
V_44 = F_32 ( V_6 ) ;
if ( ! F_5 ( V_44 ) ) {
F_33 ( V_44 ) ;
V_8 = F_4 ( V_6 ,
V_48 ,
0 ) ;
if ( ! F_5 ( V_8 ) )
goto V_50;
}
}
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_50:
V_25 = F_7 ( V_8 ) ;
V_3 = 0 ;
if ( F_18 ( V_28 , & V_25 -> V_29 ) )
V_3 = - V_5 ;
else
F_94 ( V_25 , V_117 ) ;
F_33 ( V_25 ) ;
error:
return V_3 ;
}
long F_95 ( T_2 V_6 )
{
struct V_25 * V_137 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_6 < 0 )
goto error;
if ( V_6 == 0 ) {
V_3 = F_69 ( NULL ) ;
goto error;
}
V_137 = F_32 ( V_6 ) ;
if ( F_5 ( V_137 ) ) {
V_3 = F_6 ( V_137 ) ;
goto error;
}
V_3 = F_69 ( V_137 ) ;
if ( V_3 < 0 )
goto error;
F_33 ( V_137 ) ;
V_3 = V_137 -> V_12 ;
error:
return V_3 ;
}
long F_96 ( T_2 V_41 ,
char T_1 * V_42 ,
T_4 V_43 )
{
struct V_25 * V_25 , * V_44 ;
T_3 V_8 ;
char * V_138 ;
long V_3 ;
V_8 = F_4 ( V_41 , V_48 , V_49 ) ;
if ( F_5 ( V_8 ) ) {
if ( F_6 ( V_8 ) != - V_26 )
return F_6 ( V_8 ) ;
V_44 = F_32 ( V_41 ) ;
if ( F_5 ( V_44 ) )
return F_6 ( V_44 ) ;
F_33 ( V_44 ) ;
V_8 = F_4 ( V_41 , V_48 , 0 ) ;
if ( F_5 ( V_8 ) )
return F_6 ( V_8 ) ;
}
V_25 = F_7 ( V_8 ) ;
V_3 = F_97 ( V_25 , & V_138 ) ;
if ( V_3 == 0 ) {
V_3 = 1 ;
if ( V_42 && V_43 > 0 &&
F_38 ( V_42 , L_6 , 1 ) != 0 )
V_3 = - V_22 ;
} else if ( V_3 > 0 ) {
if ( V_42 && V_43 > 0 ) {
if ( V_43 > V_3 )
V_43 = V_3 ;
if ( F_38 ( V_42 , V_138 , V_43 ) != 0 )
V_3 = - V_22 ;
}
F_12 ( V_138 ) ;
}
F_8 ( V_8 ) ;
return V_3 ;
}
long F_98 ( void )
{
struct V_139 * V_140 , * V_141 ;
const struct V_104 * V_142 , * V_143 ;
struct V_144 * V_145 , * V_146 ;
T_3 V_147 ;
struct V_104 * V_104 ;
int V_3 ;
V_147 = F_4 ( V_148 , 0 , V_39 ) ;
if ( F_5 ( V_147 ) )
return F_6 ( V_147 ) ;
V_3 = - V_20 ;
V_104 = F_99 () ;
if ( ! V_104 )
goto V_149;
V_145 = & V_104 -> V_150 ;
V_104 -> V_151 = F_7 ( V_147 ) ;
V_147 = NULL ;
F_100 ( V_145 , V_152 ) ;
V_140 = V_153 ;
F_101 () ;
F_102 ( & V_154 ) ;
V_3 = - V_5 ;
V_146 = NULL ;
V_141 = V_140 -> V_155 ;
if ( V_141 -> V_156 <= 1 || ! V_141 -> V_157 )
goto V_158;
if ( ! F_103 ( V_141 ) )
goto V_158;
V_142 = F_73 () ;
V_143 = F_104 ( V_141 ) ;
if ( V_142 == V_143 ||
V_142 -> V_151 == V_143 -> V_151 ) {
V_3 = 0 ;
goto V_158;
}
if ( ! F_55 ( V_143 -> V_52 , V_142 -> V_159 ) ||
! F_55 ( V_143 -> V_159 , V_142 -> V_159 ) ||
! F_55 ( V_143 -> V_160 , V_142 -> V_159 ) ||
! F_56 ( V_143 -> V_53 , V_142 -> V_161 ) ||
! F_56 ( V_143 -> V_161 , V_142 -> V_161 ) ||
! F_56 ( V_143 -> V_162 , V_142 -> V_161 ) )
goto V_158;
if ( ( V_143 -> V_151 &&
! F_55 ( V_143 -> V_151 -> V_52 , V_142 -> V_159 ) ) ||
! F_55 ( V_142 -> V_151 -> V_52 , V_142 -> V_159 ) )
goto V_158;
V_146 = F_105 ( V_141 , V_152 ) ;
V_3 = F_106 ( V_141 , V_145 , true ) ;
if ( ! V_3 )
V_145 = NULL ;
V_158:
F_107 ( & V_154 ) ;
F_108 () ;
if ( V_146 )
F_109 ( F_110 ( V_146 , struct V_104 , V_150 ) ) ;
if ( V_145 )
F_109 ( V_104 ) ;
return V_3 ;
V_149:
F_8 ( V_147 ) ;
return V_3 ;
}
