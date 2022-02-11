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
V_3 = - V_5 ;
if ( V_14 [ 0 ] == '.' )
goto V_16;
}
V_3 = F_11 ( V_14 ) ;
V_16:
F_12 ( V_14 ) ;
error:
return V_3 ;
}
long F_13 ( T_2 V_6 ,
const void T_1 * V_17 ,
T_4 V_18 )
{
T_3 V_8 ;
void * V_19 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_18 > V_20 )
goto error;
V_19 = NULL ;
if ( V_18 ) {
V_3 = - V_21 ;
V_19 = F_14 ( V_18 , V_22 ) ;
if ( ! V_19 )
goto error;
V_3 = - V_23 ;
if ( F_15 ( V_19 , V_17 , V_18 ) != 0 )
goto V_24;
}
V_8 = F_4 ( V_6 , 0 , V_25 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto V_24;
}
V_3 = F_16 ( V_8 , V_19 , V_18 ) ;
F_8 ( V_8 ) ;
V_24:
F_17 ( V_19 ) ;
error:
return V_3 ;
}
long F_18 ( T_2 V_6 )
{
T_3 V_8 ;
struct V_26 * V_26 ;
long V_3 ;
V_8 = F_4 ( V_6 , 0 , V_25 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
if ( V_3 != - V_27 )
goto error;
V_8 = F_4 ( V_6 , 0 , V_28 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
}
V_26 = F_7 ( V_8 ) ;
V_3 = 0 ;
if ( F_19 ( V_29 , & V_26 -> V_30 ) )
V_3 = - V_5 ;
else
F_20 ( V_26 ) ;
F_8 ( V_8 ) ;
error:
return V_3 ;
}
long F_21 ( T_2 V_6 )
{
T_3 V_8 ;
struct V_26 * V_26 ;
long V_3 ;
F_22 ( L_1 , V_6 ) ;
V_8 = F_4 ( V_6 , 0 , V_11 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
if ( F_23 ( V_31 ) ) {
V_8 = F_4 ( V_6 , 0 , 0 ) ;
if ( F_5 ( V_8 ) )
goto error;
if ( F_19 ( V_32 ,
& F_7 ( V_8 ) -> V_30 ) )
goto V_33;
goto V_34;
}
goto error;
}
V_33:
V_26 = F_7 ( V_8 ) ;
V_3 = 0 ;
if ( F_19 ( V_29 , & V_26 -> V_30 ) )
V_3 = - V_5 ;
else
F_24 ( V_26 ) ;
V_34:
F_8 ( V_8 ) ;
error:
F_25 ( L_2 , V_3 ) ;
return V_3 ;
}
long F_26 ( T_2 V_35 )
{
T_3 V_36 ;
struct V_26 * V_37 ;
long V_3 ;
V_36 = F_4 ( V_35 , V_10 , V_25 ) ;
if ( F_5 ( V_36 ) ) {
V_3 = F_6 ( V_36 ) ;
if ( F_23 ( V_31 ) ) {
V_36 = F_4 ( V_35 , 0 , 0 ) ;
if ( F_5 ( V_36 ) )
goto error;
if ( F_19 ( V_38 ,
& F_7 ( V_36 ) -> V_30 ) )
goto V_39;
goto V_34;
}
goto error;
}
V_39:
V_37 = F_7 ( V_36 ) ;
if ( F_19 ( V_29 , & V_37 -> V_30 ) )
V_3 = - V_5 ;
else
V_3 = F_27 ( V_37 ) ;
V_34:
F_8 ( V_36 ) ;
error:
return V_3 ;
}
long F_28 ( T_2 V_6 , T_2 V_35 )
{
T_3 V_36 , V_8 ;
long V_3 ;
V_36 = F_4 ( V_35 , V_10 , V_25 ) ;
if ( F_5 ( V_36 ) ) {
V_3 = F_6 ( V_36 ) ;
goto error;
}
V_8 = F_4 ( V_6 , V_10 , V_40 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto V_24;
}
V_3 = F_29 ( F_7 ( V_36 ) , F_7 ( V_8 ) ) ;
F_8 ( V_8 ) ;
V_24:
F_8 ( V_36 ) ;
error:
return V_3 ;
}
long F_30 ( T_2 V_6 , T_2 V_35 )
{
T_3 V_36 , V_8 ;
struct V_26 * V_37 , * V_26 ;
long V_3 ;
V_36 = F_4 ( V_35 , 0 , V_25 ) ;
if ( F_5 ( V_36 ) ) {
V_3 = F_6 ( V_36 ) ;
goto error;
}
V_8 = F_4 ( V_6 , V_41 , 0 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto V_24;
}
V_37 = F_7 ( V_36 ) ;
V_26 = F_7 ( V_8 ) ;
if ( F_19 ( V_29 , & V_37 -> V_30 ) &&
F_19 ( V_29 , & V_26 -> V_30 ) )
V_3 = - V_5 ;
else
V_3 = F_31 ( V_37 , V_26 ) ;
F_8 ( V_8 ) ;
V_24:
F_8 ( V_36 ) ;
error:
return V_3 ;
}
long F_32 ( T_2 V_42 ,
char T_1 * V_43 ,
T_4 V_44 )
{
struct V_26 * V_26 , * V_45 ;
T_3 V_8 ;
char * V_46 ;
long V_3 ;
int V_47 , V_48 ;
V_8 = F_4 ( V_42 , V_49 , V_50 ) ;
if ( F_5 ( V_8 ) ) {
if ( F_6 ( V_8 ) == - V_27 ) {
V_45 = F_33 ( V_42 ) ;
if ( ! F_5 ( V_45 ) ) {
F_34 ( V_45 ) ;
V_8 = F_4 ( V_42 ,
V_49 ,
0 ) ;
if ( ! F_5 ( V_8 ) )
goto V_51;
}
}
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_51:
V_26 = F_7 ( V_8 ) ;
V_47 = strlen ( V_26 -> V_52 ) ;
V_3 = - V_21 ;
V_46 = F_35 ( V_22 ,
L_3 ,
V_26 -> type -> V_14 ,
F_36 ( F_37 () , V_26 -> V_53 ) ,
F_38 ( F_37 () , V_26 -> V_54 ) ,
V_26 -> V_55 ) ;
if ( ! V_46 )
goto V_24;
V_48 = strlen ( V_46 ) ;
V_3 = V_48 + V_47 + 1 ;
if ( V_43 && V_44 >= V_3 ) {
if ( F_39 ( V_43 , V_46 , V_48 ) != 0 ||
F_39 ( V_43 + V_48 , V_26 -> V_52 ,
V_47 + 1 ) != 0 )
V_3 = - V_23 ;
}
F_12 ( V_46 ) ;
V_24:
F_8 ( V_8 ) ;
error:
return V_3 ;
}
long F_40 ( T_2 V_35 ,
const char T_1 * V_1 ,
const char T_1 * V_56 ,
T_2 V_57 )
{
struct V_58 * V_59 ;
T_3 V_36 , V_8 , V_60 ;
char type [ 32 ] , * V_52 ;
long V_3 ;
V_3 = F_1 ( type , V_1 , sizeof( type ) ) ;
if ( V_3 < 0 )
goto error;
V_52 = F_10 ( V_56 , V_15 ) ;
if ( F_5 ( V_52 ) ) {
V_3 = F_6 ( V_52 ) ;
goto error;
}
V_36 = F_4 ( V_35 , 0 , V_11 ) ;
if ( F_5 ( V_36 ) ) {
V_3 = F_6 ( V_36 ) ;
goto V_24;
}
V_60 = NULL ;
if ( V_57 ) {
V_60 = F_4 ( V_57 , V_10 ,
V_25 ) ;
if ( F_5 ( V_60 ) ) {
V_3 = F_6 ( V_60 ) ;
goto V_61;
}
}
V_59 = F_41 ( type ) ;
if ( F_5 ( V_59 ) ) {
V_3 = F_6 ( V_59 ) ;
goto V_62;
}
V_8 = F_42 ( V_36 , V_59 , V_52 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
if ( V_3 == - V_63 )
V_3 = - V_64 ;
goto V_65;
}
if ( V_60 ) {
V_3 = F_43 ( V_8 , V_40 ) ;
if ( V_3 < 0 )
goto V_66;
V_3 = F_29 ( F_7 ( V_60 ) , F_7 ( V_8 ) ) ;
if ( V_3 < 0 )
goto V_66;
}
V_3 = F_7 ( V_8 ) -> V_12 ;
V_66:
F_8 ( V_8 ) ;
V_65:
F_44 ( V_59 ) ;
V_62:
F_8 ( V_60 ) ;
V_61:
F_8 ( V_36 ) ;
V_24:
F_12 ( V_52 ) ;
error:
return V_3 ;
}
long F_45 ( T_2 V_42 , char T_1 * V_43 , T_4 V_44 )
{
struct V_26 * V_26 ;
T_3 V_8 ;
long V_3 ;
V_8 = F_4 ( V_42 , 0 , 0 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = - V_64 ;
goto error;
}
V_26 = F_7 ( V_8 ) ;
V_3 = F_46 ( V_26 ) ;
if ( V_3 < 0 )
goto V_24;
V_3 = F_43 ( V_8 , V_67 ) ;
if ( V_3 == 0 )
goto V_68;
if ( V_3 != - V_27 )
goto V_24;
if ( ! F_47 ( V_8 ) ) {
V_3 = - V_27 ;
goto V_24;
}
V_68:
V_3 = - V_69 ;
if ( V_26 -> type -> V_70 ) {
F_48 ( & V_26 -> V_71 ) ;
V_3 = F_49 ( V_26 ) ;
if ( V_3 == 0 )
V_3 = V_26 -> type -> V_70 ( V_26 , V_43 , V_44 ) ;
F_50 ( & V_26 -> V_71 ) ;
}
V_24:
F_34 ( V_26 ) ;
error:
return V_3 ;
}
long F_51 ( T_2 V_6 , T_5 V_72 , T_6 V_73 )
{
struct V_74 * V_75 , * V_76 = NULL ;
struct V_26 * V_26 ;
T_3 V_8 ;
long V_3 ;
T_7 V_53 ;
T_8 V_54 ;
V_53 = F_52 ( F_37 () , V_72 ) ;
V_54 = F_53 ( F_37 () , V_73 ) ;
V_3 = - V_4 ;
if ( ( V_72 != ( T_5 ) - 1 ) && ! F_54 ( V_53 ) )
goto error;
if ( ( V_73 != ( T_6 ) - 1 ) && ! F_55 ( V_54 ) )
goto error;
V_3 = 0 ;
if ( V_72 == ( T_5 ) - 1 && V_73 == ( T_6 ) - 1 )
goto error;
V_8 = F_4 ( V_6 , V_10 | V_49 ,
V_28 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_26 = F_7 ( V_8 ) ;
V_3 = - V_27 ;
F_56 ( & V_26 -> V_71 ) ;
if ( ! F_23 ( V_31 ) ) {
if ( V_72 != ( T_5 ) - 1 && ! F_57 ( V_26 -> V_53 , V_53 ) )
goto V_34;
if ( V_73 != ( T_6 ) - 1 && ! F_58 ( V_54 , V_26 -> V_54 ) && ! F_59 ( V_54 ) )
goto V_34;
}
if ( V_72 != ( T_5 ) - 1 && ! F_57 ( V_53 , V_26 -> V_53 ) ) {
V_3 = - V_21 ;
V_75 = F_60 ( V_53 ) ;
if ( ! V_75 )
goto V_34;
if ( F_19 ( V_77 , & V_26 -> V_30 ) ) {
unsigned V_78 = F_57 ( V_53 , V_79 ) ?
V_80 : V_81 ;
unsigned V_82 = F_57 ( V_53 , V_79 ) ?
V_83 : V_84 ;
F_61 ( & V_75 -> V_85 ) ;
if ( V_75 -> V_86 + 1 >= V_78 ||
V_75 -> V_87 + V_26 -> V_88 >= V_82 ||
V_75 -> V_87 + V_26 -> V_88 <
V_75 -> V_87 )
goto V_89;
V_75 -> V_86 ++ ;
V_75 -> V_87 += V_26 -> V_88 ;
F_62 ( & V_75 -> V_85 ) ;
F_61 ( & V_26 -> V_72 -> V_85 ) ;
V_26 -> V_72 -> V_86 -- ;
V_26 -> V_72 -> V_87 -= V_26 -> V_88 ;
F_62 ( & V_26 -> V_72 -> V_85 ) ;
}
F_63 ( & V_26 -> V_72 -> V_90 ) ;
F_64 ( & V_75 -> V_90 ) ;
if ( V_26 -> V_91 != V_92 ) {
F_63 ( & V_26 -> V_72 -> V_93 ) ;
F_64 ( & V_75 -> V_93 ) ;
}
V_76 = V_26 -> V_72 ;
V_26 -> V_72 = V_75 ;
V_26 -> V_53 = V_53 ;
}
if ( V_73 != ( T_6 ) - 1 )
V_26 -> V_54 = V_54 ;
V_3 = 0 ;
V_34:
F_65 ( & V_26 -> V_71 ) ;
F_34 ( V_26 ) ;
if ( V_76 )
F_66 ( V_76 ) ;
error:
return V_3 ;
V_89:
F_62 ( & V_75 -> V_85 ) ;
V_76 = V_75 ;
V_3 = - V_94 ;
goto V_34;
}
long F_67 ( T_2 V_6 , T_9 V_55 )
{
struct V_26 * V_26 ;
T_3 V_8 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_55 & ~ ( V_95 | V_96 | V_97 | V_98 ) )
goto error;
V_8 = F_4 ( V_6 , V_10 | V_49 ,
V_28 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_26 = F_7 ( V_8 ) ;
V_3 = - V_27 ;
F_56 ( & V_26 -> V_71 ) ;
if ( F_23 ( V_31 ) || F_57 ( V_26 -> V_53 , F_68 () ) ) {
V_26 -> V_55 = V_55 ;
V_3 = 0 ;
}
F_65 ( & V_26 -> V_71 ) ;
F_34 ( V_26 ) ;
error:
return V_3 ;
}
static long F_69 ( T_2 V_35 ,
struct V_99 * V_100 ,
struct V_26 * * V_101 )
{
T_3 V_102 ;
* V_101 = NULL ;
if ( V_35 == 0 )
return 0 ;
if ( V_35 > 0 ) {
V_102 = F_4 ( V_35 , V_10 , V_25 ) ;
if ( F_5 ( V_102 ) )
return F_6 ( V_102 ) ;
* V_101 = F_7 ( V_102 ) ;
return 0 ;
}
if ( V_35 == V_103 )
return - V_4 ;
if ( V_35 >= V_104 ) {
* V_101 = F_70 ( V_100 -> V_105 ) ;
return 0 ;
}
return - V_64 ;
}
static int F_71 ( struct V_26 * V_26 )
{
struct V_106 * V_107 ;
V_107 = F_72 () ;
if ( ! V_107 )
return - V_21 ;
F_34 ( V_107 -> V_99 ) ;
V_107 -> V_99 = F_70 ( V_26 ) ;
return F_73 ( V_107 ) ;
}
long F_74 ( T_2 V_6 ,
struct V_108 * V_109 ,
T_2 V_35 )
{
const struct V_106 * V_106 = F_75 () ;
struct V_99 * V_100 ;
struct V_26 * V_45 , * V_105 ;
T_4 V_18 = V_109 ? F_76 ( V_109 ) : 0 ;
void * V_19 ;
long V_3 ;
F_22 ( L_4 , V_6 , V_18 , V_35 ) ;
if ( ! V_18 )
V_109 = NULL ;
V_3 = - V_4 ;
if ( V_18 > 1024 * 1024 - 1 )
goto error;
V_3 = - V_5 ;
V_45 = V_106 -> V_99 ;
if ( ! V_45 )
goto error;
V_100 = V_45 -> V_19 . V_110 [ 0 ] ;
if ( V_100 -> V_111 -> V_12 != V_6 )
goto error;
V_19 = NULL ;
if ( V_109 ) {
V_3 = - V_21 ;
V_19 = F_77 ( V_18 , V_22 ) ;
if ( ! V_19 )
goto error;
V_3 = - V_23 ;
if ( ! F_78 ( V_19 , V_18 , V_109 ) )
goto V_24;
}
V_3 = F_69 ( V_35 , V_100 , & V_105 ) ;
if ( V_3 < 0 )
goto V_24;
V_3 = F_79 ( V_100 -> V_111 , V_19 , V_18 ,
V_105 , V_45 ) ;
F_34 ( V_105 ) ;
if ( V_3 == 0 )
F_71 ( NULL ) ;
V_24:
if ( V_19 ) {
F_80 ( V_19 , V_18 ) ;
F_81 ( V_19 ) ;
}
error:
return V_3 ;
}
long F_82 ( T_2 V_6 ,
const void T_1 * V_17 ,
T_4 V_18 ,
T_2 V_35 )
{
if ( V_17 && V_18 ) {
struct V_112 V_113 ;
struct V_108 V_109 ;
int V_3 ;
V_3 = F_83 ( V_114 , ( void T_1 * ) V_17 , V_18 ,
& V_113 , & V_109 ) ;
if ( F_84 ( V_3 ) )
return V_3 ;
return F_74 ( V_6 , & V_109 , V_35 ) ;
}
return F_74 ( V_6 , NULL , V_35 ) ;
}
long F_85 ( T_2 V_6 ,
const struct V_112 T_1 * V_115 ,
unsigned V_116 ,
T_2 V_35 )
{
struct V_112 V_117 [ V_118 ] , * V_113 = V_117 ;
struct V_108 V_109 ;
long V_3 ;
if ( ! V_115 )
V_116 = 0 ;
V_3 = F_86 ( V_114 , V_115 , V_116 ,
F_87 ( V_117 ) , & V_113 , & V_109 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_74 ( V_6 , & V_109 , V_35 ) ;
F_12 ( V_113 ) ;
return V_3 ;
}
long F_88 ( T_2 V_6 , unsigned V_119 , T_2 V_35 )
{
return F_89 ( V_6 , V_119 , V_64 , V_35 ) ;
}
long F_89 ( T_2 V_6 , unsigned V_119 , unsigned error ,
T_2 V_35 )
{
const struct V_106 * V_106 = F_75 () ;
struct V_99 * V_100 ;
struct V_26 * V_45 , * V_105 ;
long V_3 ;
F_22 ( L_5 , V_6 , V_119 , error , V_35 ) ;
if ( error <= 0 ||
error >= V_120 ||
error == V_121 ||
error == V_122 ||
error == V_123 ||
error == V_124 )
return - V_4 ;
V_3 = - V_5 ;
V_45 = V_106 -> V_99 ;
if ( ! V_45 )
goto error;
V_100 = V_45 -> V_19 . V_110 [ 0 ] ;
if ( V_100 -> V_111 -> V_12 != V_6 )
goto error;
V_3 = F_69 ( V_35 , V_100 , & V_105 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_90 ( V_100 -> V_111 , V_119 , error ,
V_105 , V_45 ) ;
F_34 ( V_105 ) ;
if ( V_3 == 0 )
F_71 ( NULL ) ;
error:
return V_3 ;
}
long F_91 ( int V_125 )
{
struct V_106 * V_107 ;
int V_3 , V_126 ;
V_126 = F_92 ( V_127 ) ;
if ( V_125 == V_128 )
return V_126 ;
V_107 = F_72 () ;
if ( ! V_107 )
return - V_21 ;
switch ( V_125 ) {
case V_129 :
V_3 = F_93 ( V_107 ) ;
if ( V_3 < 0 )
goto error;
goto V_130;
case V_131 :
V_3 = F_94 ( V_107 ) ;
if ( V_3 < 0 )
goto error;
goto V_130;
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
goto V_130;
case V_128 :
case V_137 :
default:
V_3 = - V_4 ;
goto error;
}
V_130:
V_107 -> V_127 = V_125 ;
F_73 ( V_107 ) ;
return V_126 ;
error:
F_95 ( V_107 ) ;
return V_3 ;
}
long F_96 ( T_2 V_6 , unsigned V_119 )
{
struct V_26 * V_26 , * V_45 ;
T_3 V_8 ;
long V_3 ;
V_8 = F_4 ( V_6 , V_10 | V_49 ,
V_28 ) ;
if ( F_5 ( V_8 ) ) {
if ( F_6 ( V_8 ) == - V_27 ) {
V_45 = F_33 ( V_6 ) ;
if ( ! F_5 ( V_45 ) ) {
F_34 ( V_45 ) ;
V_8 = F_4 ( V_6 ,
V_49 ,
0 ) ;
if ( ! F_5 ( V_8 ) )
goto V_51;
}
}
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_51:
V_26 = F_7 ( V_8 ) ;
V_3 = 0 ;
if ( F_19 ( V_29 , & V_26 -> V_30 ) )
V_3 = - V_5 ;
else
F_97 ( V_26 , V_119 ) ;
F_34 ( V_26 ) ;
error:
return V_3 ;
}
long F_98 ( T_2 V_6 )
{
struct V_26 * V_138 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_6 < 0 )
goto error;
if ( V_6 == 0 ) {
V_3 = F_71 ( NULL ) ;
goto error;
}
V_138 = F_33 ( V_6 ) ;
if ( F_5 ( V_138 ) ) {
V_3 = F_6 ( V_138 ) ;
goto error;
}
V_3 = F_71 ( V_138 ) ;
if ( V_3 == 0 )
V_3 = V_138 -> V_12 ;
F_34 ( V_138 ) ;
error:
return V_3 ;
}
long F_99 ( T_2 V_42 ,
char T_1 * V_43 ,
T_4 V_44 )
{
struct V_26 * V_26 , * V_45 ;
T_3 V_8 ;
char * V_139 ;
long V_3 ;
V_8 = F_4 ( V_42 , V_49 , V_50 ) ;
if ( F_5 ( V_8 ) ) {
if ( F_6 ( V_8 ) != - V_27 )
return F_6 ( V_8 ) ;
V_45 = F_33 ( V_42 ) ;
if ( F_5 ( V_45 ) )
return F_6 ( V_45 ) ;
F_34 ( V_45 ) ;
V_8 = F_4 ( V_42 , V_49 , 0 ) ;
if ( F_5 ( V_8 ) )
return F_6 ( V_8 ) ;
}
V_26 = F_7 ( V_8 ) ;
V_3 = F_100 ( V_26 , & V_139 ) ;
if ( V_3 == 0 ) {
V_3 = 1 ;
if ( V_43 && V_44 > 0 &&
F_39 ( V_43 , L_6 , 1 ) != 0 )
V_3 = - V_23 ;
} else if ( V_3 > 0 ) {
if ( V_43 && V_44 > 0 ) {
if ( V_44 > V_3 )
V_44 = V_3 ;
if ( F_39 ( V_43 , V_139 , V_44 ) != 0 )
V_3 = - V_23 ;
}
F_12 ( V_139 ) ;
}
F_8 ( V_8 ) ;
return V_3 ;
}
long F_101 ( void )
{
struct V_140 * V_141 , * V_142 ;
const struct V_106 * V_143 , * V_144 ;
struct V_145 * V_146 , * V_147 ;
T_3 V_148 ;
struct V_106 * V_106 ;
int V_3 ;
V_148 = F_4 ( V_149 , 0 , V_40 ) ;
if ( F_5 ( V_148 ) )
return F_6 ( V_148 ) ;
V_3 = - V_21 ;
V_106 = F_102 () ;
if ( ! V_106 )
goto V_150;
V_146 = & V_106 -> V_151 ;
V_106 -> V_152 = F_7 ( V_148 ) ;
V_148 = NULL ;
F_103 ( V_146 , V_153 ) ;
V_141 = V_154 ;
F_104 () ;
F_105 ( & V_155 ) ;
V_3 = - V_5 ;
V_147 = NULL ;
V_142 = V_141 -> V_156 ;
if ( V_142 -> V_157 <= 1 || ! V_142 -> V_158 )
goto V_159;
if ( ! F_106 ( V_142 ) )
goto V_159;
V_143 = F_75 () ;
V_144 = F_107 ( V_142 ) ;
if ( V_143 == V_144 ||
V_143 -> V_152 == V_144 -> V_152 ) {
V_3 = 0 ;
goto V_159;
}
if ( ! F_57 ( V_144 -> V_53 , V_143 -> V_160 ) ||
! F_57 ( V_144 -> V_160 , V_143 -> V_160 ) ||
! F_57 ( V_144 -> V_161 , V_143 -> V_160 ) ||
! F_58 ( V_144 -> V_54 , V_143 -> V_162 ) ||
! F_58 ( V_144 -> V_162 , V_143 -> V_162 ) ||
! F_58 ( V_144 -> V_163 , V_143 -> V_162 ) )
goto V_159;
if ( ( V_144 -> V_152 &&
! F_57 ( V_144 -> V_152 -> V_53 , V_143 -> V_160 ) ) ||
! F_57 ( V_143 -> V_152 -> V_53 , V_143 -> V_160 ) )
goto V_159;
V_147 = F_108 ( V_142 , V_153 ) ;
V_3 = F_109 ( V_142 , V_146 , true ) ;
if ( ! V_3 )
V_146 = NULL ;
V_159:
F_110 ( & V_155 ) ;
F_111 () ;
if ( V_147 )
F_112 ( F_113 ( V_147 , struct V_106 , V_151 ) ) ;
if ( V_146 )
F_112 ( V_106 ) ;
return V_3 ;
V_150:
F_8 ( V_148 ) ;
return V_3 ;
}
long F_114 ( T_2 V_6 , const char T_1 * V_1 ,
const char T_1 * V_164 )
{
T_3 V_8 ;
bool V_165 = ! V_1 ;
char type [ 32 ] ;
char * V_166 = NULL ;
long V_3 ;
V_8 = F_4 ( V_6 , 0 , V_28 ) ;
if ( F_5 ( V_8 ) )
return F_6 ( V_8 ) ;
if ( V_1 ) {
V_3 = F_1 ( type , V_1 , sizeof( type ) ) ;
if ( V_3 < 0 )
goto error;
}
if ( V_164 ) {
if ( ! V_1 ) {
V_3 = - V_4 ;
goto error;
}
V_166 = F_10 ( V_164 , V_20 ) ;
if ( F_5 ( V_166 ) ) {
V_3 = F_6 ( V_166 ) ;
goto error;
}
}
V_3 = F_115 ( V_8 , V_165 ? NULL : type , V_166 ) ;
F_12 ( V_166 ) ;
error:
F_8 ( V_8 ) ;
return V_3 ;
}
