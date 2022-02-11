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
V_3 = F_43 ( V_8 , V_67 ) ;
if ( V_3 == 0 )
goto V_68;
if ( V_3 != - V_27 )
goto error;
if ( ! F_46 ( V_8 ) ) {
V_3 = - V_27 ;
goto V_24;
}
V_68:
V_3 = - V_69 ;
if ( V_26 -> type -> V_70 ) {
F_47 ( & V_26 -> V_71 ) ;
V_3 = F_48 ( V_26 ) ;
if ( V_3 == 0 )
V_3 = V_26 -> type -> V_70 ( V_26 , V_43 , V_44 ) ;
F_49 ( & V_26 -> V_71 ) ;
}
V_24:
F_34 ( V_26 ) ;
error:
return V_3 ;
}
long F_50 ( T_2 V_6 , T_5 V_72 , T_6 V_73 )
{
struct V_74 * V_75 , * V_76 = NULL ;
struct V_26 * V_26 ;
T_3 V_8 ;
long V_3 ;
T_7 V_53 ;
T_8 V_54 ;
V_53 = F_51 ( F_37 () , V_72 ) ;
V_54 = F_52 ( F_37 () , V_73 ) ;
V_3 = - V_4 ;
if ( ( V_72 != ( T_5 ) - 1 ) && ! F_53 ( V_53 ) )
goto error;
if ( ( V_73 != ( T_6 ) - 1 ) && ! F_54 ( V_54 ) )
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
F_55 ( & V_26 -> V_71 ) ;
if ( ! F_23 ( V_31 ) ) {
if ( V_72 != ( T_5 ) - 1 && ! F_56 ( V_26 -> V_53 , V_53 ) )
goto V_34;
if ( V_73 != ( T_6 ) - 1 && ! F_57 ( V_54 , V_26 -> V_54 ) && ! F_58 ( V_54 ) )
goto V_34;
}
if ( V_72 != ( T_5 ) - 1 && ! F_56 ( V_53 , V_26 -> V_53 ) ) {
V_3 = - V_21 ;
V_75 = F_59 ( V_53 ) ;
if ( ! V_75 )
goto V_34;
if ( F_19 ( V_77 , & V_26 -> V_30 ) ) {
unsigned V_78 = F_56 ( V_53 , V_79 ) ?
V_80 : V_81 ;
unsigned V_82 = F_56 ( V_53 , V_79 ) ?
V_83 : V_84 ;
F_60 ( & V_75 -> V_85 ) ;
if ( V_75 -> V_86 + 1 >= V_78 ||
V_75 -> V_87 + V_26 -> V_88 >= V_82 ||
V_75 -> V_87 + V_26 -> V_88 <
V_75 -> V_87 )
goto V_89;
V_75 -> V_86 ++ ;
V_75 -> V_87 += V_26 -> V_88 ;
F_61 ( & V_75 -> V_85 ) ;
F_60 ( & V_26 -> V_72 -> V_85 ) ;
V_26 -> V_72 -> V_86 -- ;
V_26 -> V_72 -> V_87 -= V_26 -> V_88 ;
F_61 ( & V_26 -> V_72 -> V_85 ) ;
}
F_62 ( & V_26 -> V_72 -> V_90 ) ;
F_63 ( & V_75 -> V_90 ) ;
if ( F_19 ( V_91 , & V_26 -> V_30 ) ) {
F_62 ( & V_26 -> V_72 -> V_92 ) ;
F_63 ( & V_75 -> V_92 ) ;
}
V_76 = V_26 -> V_72 ;
V_26 -> V_72 = V_75 ;
V_26 -> V_53 = V_53 ;
}
if ( V_73 != ( T_6 ) - 1 )
V_26 -> V_54 = V_54 ;
V_3 = 0 ;
V_34:
F_64 ( & V_26 -> V_71 ) ;
F_34 ( V_26 ) ;
if ( V_76 )
F_65 ( V_76 ) ;
error:
return V_3 ;
V_89:
F_61 ( & V_75 -> V_85 ) ;
V_76 = V_75 ;
V_3 = - V_93 ;
goto V_34;
}
long F_66 ( T_2 V_6 , T_9 V_55 )
{
struct V_26 * V_26 ;
T_3 V_8 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_55 & ~ ( V_94 | V_95 | V_96 | V_97 ) )
goto error;
V_8 = F_4 ( V_6 , V_10 | V_49 ,
V_28 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_26 = F_7 ( V_8 ) ;
V_3 = - V_27 ;
F_55 ( & V_26 -> V_71 ) ;
if ( F_23 ( V_31 ) || F_56 ( V_26 -> V_53 , F_67 () ) ) {
V_26 -> V_55 = V_55 ;
V_3 = 0 ;
}
F_64 ( & V_26 -> V_71 ) ;
F_34 ( V_26 ) ;
error:
return V_3 ;
}
static long F_68 ( T_2 V_35 ,
struct V_98 * V_99 ,
struct V_26 * * V_100 )
{
T_3 V_101 ;
* V_100 = NULL ;
if ( V_35 == 0 )
return 0 ;
if ( V_35 > 0 ) {
V_101 = F_4 ( V_35 , V_10 , V_25 ) ;
if ( F_5 ( V_101 ) )
return F_6 ( V_101 ) ;
* V_100 = F_7 ( V_101 ) ;
return 0 ;
}
if ( V_35 == V_102 )
return - V_4 ;
if ( V_35 >= V_103 ) {
* V_100 = F_69 ( V_99 -> V_104 ) ;
return 0 ;
}
return - V_64 ;
}
static int F_70 ( struct V_26 * V_26 )
{
struct V_105 * V_106 ;
V_106 = F_71 () ;
if ( ! V_106 )
return - V_21 ;
F_34 ( V_106 -> V_98 ) ;
V_106 -> V_98 = F_69 ( V_26 ) ;
return F_72 ( V_106 ) ;
}
long F_73 ( T_2 V_6 ,
struct V_107 * V_108 ,
T_2 V_35 )
{
const struct V_105 * V_105 = F_74 () ;
struct V_98 * V_99 ;
struct V_26 * V_45 , * V_104 ;
T_4 V_18 = V_108 ? F_75 ( V_108 ) : 0 ;
void * V_19 ;
long V_3 ;
F_22 ( L_4 , V_6 , V_18 , V_35 ) ;
if ( ! V_18 )
V_108 = NULL ;
V_3 = - V_4 ;
if ( V_18 > 1024 * 1024 - 1 )
goto error;
V_3 = - V_5 ;
V_45 = V_105 -> V_98 ;
if ( ! V_45 )
goto error;
V_99 = V_45 -> V_19 . V_109 [ 0 ] ;
if ( V_99 -> V_110 -> V_12 != V_6 )
goto error;
V_19 = NULL ;
if ( V_108 ) {
V_3 = - V_21 ;
V_19 = F_76 ( V_18 , V_22 ) ;
if ( ! V_19 )
goto error;
V_3 = - V_23 ;
if ( ! F_77 ( V_19 , V_18 , V_108 ) )
goto V_24;
}
V_3 = F_68 ( V_35 , V_99 , & V_104 ) ;
if ( V_3 < 0 )
goto V_24;
V_3 = F_78 ( V_99 -> V_110 , V_19 , V_18 ,
V_104 , V_45 ) ;
F_34 ( V_104 ) ;
if ( V_3 == 0 )
F_70 ( NULL ) ;
V_24:
if ( V_19 ) {
F_79 ( V_19 , V_18 ) ;
F_80 ( V_19 ) ;
}
error:
return V_3 ;
}
long F_81 ( T_2 V_6 ,
const void T_1 * V_17 ,
T_4 V_18 ,
T_2 V_35 )
{
if ( V_17 && V_18 ) {
struct V_111 V_112 ;
struct V_107 V_108 ;
int V_3 ;
V_3 = F_82 ( V_113 , ( void T_1 * ) V_17 , V_18 ,
& V_112 , & V_108 ) ;
if ( F_83 ( V_3 ) )
return V_3 ;
return F_73 ( V_6 , & V_108 , V_35 ) ;
}
return F_73 ( V_6 , NULL , V_35 ) ;
}
long F_84 ( T_2 V_6 ,
const struct V_111 T_1 * V_114 ,
unsigned V_115 ,
T_2 V_35 )
{
struct V_111 V_116 [ V_117 ] , * V_112 = V_116 ;
struct V_107 V_108 ;
long V_3 ;
if ( ! V_114 )
V_115 = 0 ;
V_3 = F_85 ( V_113 , V_114 , V_115 ,
F_86 ( V_116 ) , & V_112 , & V_108 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_73 ( V_6 , & V_108 , V_35 ) ;
F_12 ( V_112 ) ;
return V_3 ;
}
long F_87 ( T_2 V_6 , unsigned V_118 , T_2 V_35 )
{
return F_88 ( V_6 , V_118 , V_64 , V_35 ) ;
}
long F_88 ( T_2 V_6 , unsigned V_118 , unsigned error ,
T_2 V_35 )
{
const struct V_105 * V_105 = F_74 () ;
struct V_98 * V_99 ;
struct V_26 * V_45 , * V_104 ;
long V_3 ;
F_22 ( L_5 , V_6 , V_118 , error , V_35 ) ;
if ( error <= 0 ||
error >= V_119 ||
error == V_120 ||
error == V_121 ||
error == V_122 ||
error == V_123 )
return - V_4 ;
V_3 = - V_5 ;
V_45 = V_105 -> V_98 ;
if ( ! V_45 )
goto error;
V_99 = V_45 -> V_19 . V_109 [ 0 ] ;
if ( V_99 -> V_110 -> V_12 != V_6 )
goto error;
V_3 = F_68 ( V_35 , V_99 , & V_104 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_89 ( V_99 -> V_110 , V_118 , error ,
V_104 , V_45 ) ;
F_34 ( V_104 ) ;
if ( V_3 == 0 )
F_70 ( NULL ) ;
error:
return V_3 ;
}
long F_90 ( int V_124 )
{
struct V_105 * V_106 ;
int V_3 , V_125 ;
V_125 = F_91 ( V_126 ) ;
if ( V_124 == V_127 )
return V_125 ;
V_106 = F_71 () ;
if ( ! V_106 )
return - V_21 ;
switch ( V_124 ) {
case V_128 :
V_3 = F_92 ( V_106 ) ;
if ( V_3 < 0 )
goto error;
goto V_129;
case V_130 :
V_3 = F_93 ( V_106 ) ;
if ( V_3 < 0 )
goto error;
goto V_129;
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
goto V_129;
case V_127 :
case V_136 :
default:
V_3 = - V_4 ;
goto error;
}
V_129:
V_106 -> V_126 = V_124 ;
F_72 ( V_106 ) ;
return V_125 ;
error:
F_94 ( V_106 ) ;
return V_3 ;
}
long F_95 ( T_2 V_6 , unsigned V_118 )
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
F_96 ( V_26 , V_118 ) ;
F_34 ( V_26 ) ;
error:
return V_3 ;
}
long F_97 ( T_2 V_6 )
{
struct V_26 * V_137 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_6 < 0 )
goto error;
if ( V_6 == 0 ) {
V_3 = F_70 ( NULL ) ;
goto error;
}
V_137 = F_33 ( V_6 ) ;
if ( F_5 ( V_137 ) ) {
V_3 = F_6 ( V_137 ) ;
goto error;
}
V_3 = F_70 ( V_137 ) ;
if ( V_3 < 0 )
goto error;
F_34 ( V_137 ) ;
V_3 = V_137 -> V_12 ;
error:
return V_3 ;
}
long F_98 ( T_2 V_42 ,
char T_1 * V_43 ,
T_4 V_44 )
{
struct V_26 * V_26 , * V_45 ;
T_3 V_8 ;
char * V_138 ;
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
V_3 = F_99 ( V_26 , & V_138 ) ;
if ( V_3 == 0 ) {
V_3 = 1 ;
if ( V_43 && V_44 > 0 &&
F_39 ( V_43 , L_6 , 1 ) != 0 )
V_3 = - V_23 ;
} else if ( V_3 > 0 ) {
if ( V_43 && V_44 > 0 ) {
if ( V_44 > V_3 )
V_44 = V_3 ;
if ( F_39 ( V_43 , V_138 , V_44 ) != 0 )
V_3 = - V_23 ;
}
F_12 ( V_138 ) ;
}
F_8 ( V_8 ) ;
return V_3 ;
}
long F_100 ( void )
{
struct V_139 * V_140 , * V_141 ;
const struct V_105 * V_142 , * V_143 ;
struct V_144 * V_145 , * V_146 ;
T_3 V_147 ;
struct V_105 * V_105 ;
int V_3 ;
V_147 = F_4 ( V_148 , 0 , V_40 ) ;
if ( F_5 ( V_147 ) )
return F_6 ( V_147 ) ;
V_3 = - V_21 ;
V_105 = F_101 () ;
if ( ! V_105 )
goto V_149;
V_145 = & V_105 -> V_150 ;
V_105 -> V_151 = F_7 ( V_147 ) ;
V_147 = NULL ;
F_102 ( V_145 , V_152 ) ;
V_140 = V_153 ;
F_103 () ;
F_104 ( & V_154 ) ;
V_3 = - V_5 ;
V_146 = NULL ;
V_141 = V_140 -> V_155 ;
if ( V_141 -> V_156 <= 1 || ! V_141 -> V_157 )
goto V_158;
if ( ! F_105 ( V_141 ) )
goto V_158;
V_142 = F_74 () ;
V_143 = F_106 ( V_141 ) ;
if ( V_142 == V_143 ||
V_142 -> V_151 == V_143 -> V_151 ) {
V_3 = 0 ;
goto V_158;
}
if ( ! F_56 ( V_143 -> V_53 , V_142 -> V_159 ) ||
! F_56 ( V_143 -> V_159 , V_142 -> V_159 ) ||
! F_56 ( V_143 -> V_160 , V_142 -> V_159 ) ||
! F_57 ( V_143 -> V_54 , V_142 -> V_161 ) ||
! F_57 ( V_143 -> V_161 , V_142 -> V_161 ) ||
! F_57 ( V_143 -> V_162 , V_142 -> V_161 ) )
goto V_158;
if ( ( V_143 -> V_151 &&
! F_56 ( V_143 -> V_151 -> V_53 , V_142 -> V_159 ) ) ||
! F_56 ( V_142 -> V_151 -> V_53 , V_142 -> V_159 ) )
goto V_158;
V_146 = F_107 ( V_141 , V_152 ) ;
V_3 = F_108 ( V_141 , V_145 , true ) ;
if ( ! V_3 )
V_145 = NULL ;
V_158:
F_109 ( & V_154 ) ;
F_110 () ;
if ( V_146 )
F_111 ( F_112 ( V_146 , struct V_105 , V_150 ) ) ;
if ( V_145 )
F_111 ( V_105 ) ;
return V_3 ;
V_149:
F_8 ( V_147 ) ;
return V_3 ;
}
long F_113 ( T_2 V_6 , const char T_1 * V_1 ,
const char T_1 * V_163 )
{
T_3 V_8 ;
bool V_164 = ! V_1 ;
char type [ 32 ] ;
char * V_165 = NULL ;
long V_3 ;
V_8 = F_4 ( V_6 , 0 , V_28 ) ;
if ( F_5 ( V_8 ) )
return F_6 ( V_8 ) ;
if ( V_1 ) {
V_3 = F_1 ( type , V_1 , sizeof( type ) ) ;
if ( V_3 < 0 )
goto error;
}
if ( V_163 ) {
if ( ! V_1 ) {
V_3 = - V_4 ;
goto error;
}
V_165 = F_10 ( V_163 , V_20 ) ;
if ( F_5 ( V_165 ) ) {
V_3 = F_6 ( V_165 ) ;
goto error;
}
}
V_3 = F_114 ( V_8 , V_164 ? NULL : type , V_165 ) ;
F_12 ( V_165 ) ;
error:
F_8 ( V_8 ) ;
return V_3 ;
}
