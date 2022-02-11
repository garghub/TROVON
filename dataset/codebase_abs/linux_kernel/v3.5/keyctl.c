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
long F_19 ( T_2 V_6 )
{
T_3 V_8 ;
long V_3 ;
F_20 ( L_1 , V_6 ) ;
V_8 = F_4 ( V_6 , 0 , V_11 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
F_21 ( F_7 ( V_8 ) ) ;
V_3 = 0 ;
F_8 ( V_8 ) ;
error:
F_22 ( L_2 , V_3 ) ;
return V_3 ;
}
long F_23 ( T_2 V_26 )
{
T_3 V_27 ;
long V_3 ;
V_27 = F_4 ( V_26 , V_10 , V_23 ) ;
if ( F_5 ( V_27 ) ) {
V_3 = F_6 ( V_27 ) ;
if ( F_24 ( V_28 ) ) {
V_27 = F_4 ( V_26 , 0 , 0 ) ;
if ( F_5 ( V_27 ) )
goto error;
if ( F_25 ( V_29 ,
& F_7 ( V_27 ) -> V_30 ) )
goto V_31;
goto V_32;
}
goto error;
}
V_31:
V_3 = F_26 ( F_7 ( V_27 ) ) ;
V_32:
F_8 ( V_27 ) ;
error:
return V_3 ;
}
long F_27 ( T_2 V_6 , T_2 V_26 )
{
T_3 V_27 , V_8 ;
long V_3 ;
V_27 = F_4 ( V_26 , V_10 , V_23 ) ;
if ( F_5 ( V_27 ) ) {
V_3 = F_6 ( V_27 ) ;
goto error;
}
V_8 = F_4 ( V_6 , V_10 , V_33 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto V_22;
}
V_3 = F_28 ( F_7 ( V_27 ) , F_7 ( V_8 ) ) ;
F_8 ( V_8 ) ;
V_22:
F_8 ( V_27 ) ;
error:
return V_3 ;
}
long F_29 ( T_2 V_6 , T_2 V_26 )
{
T_3 V_27 , V_8 ;
long V_3 ;
V_27 = F_4 ( V_26 , 0 , V_23 ) ;
if ( F_5 ( V_27 ) ) {
V_3 = F_6 ( V_27 ) ;
goto error;
}
V_8 = F_4 ( V_6 , V_34 , 0 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto V_22;
}
V_3 = F_30 ( F_7 ( V_27 ) , F_7 ( V_8 ) ) ;
F_8 ( V_8 ) ;
V_22:
F_8 ( V_27 ) ;
error:
return V_3 ;
}
long F_31 ( T_2 V_35 ,
char T_1 * V_36 ,
T_4 V_37 )
{
struct V_38 * V_38 , * V_39 ;
T_3 V_8 ;
char * V_40 ;
long V_3 ;
V_8 = F_4 ( V_35 , V_41 , V_42 ) ;
if ( F_5 ( V_8 ) ) {
if ( F_6 ( V_8 ) == - V_24 ) {
V_39 = F_32 ( V_35 ) ;
if ( ! F_5 ( V_39 ) ) {
F_33 ( V_39 ) ;
V_8 = F_4 ( V_35 ,
V_41 ,
0 ) ;
if ( ! F_5 ( V_8 ) )
goto V_43;
}
}
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_43:
V_3 = - V_19 ;
V_40 = F_14 ( V_15 , V_20 ) ;
if ( ! V_40 )
goto V_22;
V_38 = F_7 ( V_8 ) ;
V_3 = snprintf ( V_40 , V_15 - 1 ,
L_3 ,
V_38 -> type -> V_14 ,
V_38 -> V_44 ,
V_38 -> V_45 ,
V_38 -> V_46 ,
V_38 -> V_47 ? : L_4 ) ;
if ( V_3 > V_15 - 1 )
V_3 = V_15 - 1 ;
V_40 [ V_3 ] = 0 ;
V_3 ++ ;
if ( V_36 && V_37 > 0 ) {
if ( V_37 > V_3 )
V_37 = V_3 ;
if ( F_34 ( V_36 , V_40 , V_37 ) != 0 )
V_3 = - V_21 ;
}
F_12 ( V_40 ) ;
V_22:
F_8 ( V_8 ) ;
error:
return V_3 ;
}
long F_35 ( T_2 V_26 ,
const char T_1 * V_1 ,
const char T_1 * V_48 ,
T_2 V_49 )
{
struct V_50 * V_51 ;
T_3 V_27 , V_8 , V_52 ;
char type [ 32 ] , * V_47 ;
long V_3 ;
V_3 = F_1 ( type , V_1 , sizeof( type ) ) ;
if ( V_3 < 0 )
goto error;
V_47 = F_10 ( V_48 , V_15 ) ;
if ( F_5 ( V_47 ) ) {
V_3 = F_6 ( V_47 ) ;
goto error;
}
V_27 = F_4 ( V_26 , 0 , V_11 ) ;
if ( F_5 ( V_27 ) ) {
V_3 = F_6 ( V_27 ) ;
goto V_22;
}
V_52 = NULL ;
if ( V_49 ) {
V_52 = F_4 ( V_49 , V_10 ,
V_23 ) ;
if ( F_5 ( V_52 ) ) {
V_3 = F_6 ( V_52 ) ;
goto V_53;
}
}
V_51 = F_36 ( type ) ;
if ( F_5 ( V_51 ) ) {
V_3 = F_6 ( V_51 ) ;
goto V_54;
}
V_8 = F_37 ( V_27 , V_51 , V_47 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
if ( V_3 == - V_55 )
V_3 = - V_56 ;
goto V_57;
}
if ( V_52 ) {
V_3 = F_38 ( V_8 , V_33 ) ;
if ( V_3 < 0 )
goto V_58;
V_3 = F_28 ( F_7 ( V_52 ) , F_7 ( V_8 ) ) ;
if ( V_3 < 0 )
goto V_58;
}
V_3 = F_7 ( V_8 ) -> V_12 ;
V_58:
F_8 ( V_8 ) ;
V_57:
F_39 ( V_51 ) ;
V_54:
F_8 ( V_52 ) ;
V_53:
F_8 ( V_27 ) ;
V_22:
F_12 ( V_47 ) ;
error:
return V_3 ;
}
long F_40 ( T_2 V_35 , char T_1 * V_36 , T_4 V_37 )
{
struct V_38 * V_38 ;
T_3 V_8 ;
long V_3 ;
V_8 = F_4 ( V_35 , 0 , 0 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = - V_56 ;
goto error;
}
V_38 = F_7 ( V_8 ) ;
V_3 = F_38 ( V_8 , V_59 ) ;
if ( V_3 == 0 )
goto V_60;
if ( V_3 != - V_24 )
goto error;
if ( ! F_41 ( V_8 ) ) {
V_3 = - V_24 ;
goto V_22;
}
V_60:
V_3 = F_42 ( V_38 ) ;
if ( V_3 == 0 ) {
V_3 = - V_61 ;
if ( V_38 -> type -> V_62 ) {
F_43 ( & V_38 -> V_63 ) ;
V_3 = V_38 -> type -> V_62 ( V_38 , V_36 , V_37 ) ;
F_44 ( & V_38 -> V_63 ) ;
}
}
V_22:
F_33 ( V_38 ) ;
error:
return V_3 ;
}
long F_45 ( T_2 V_6 , T_5 V_44 , T_6 V_45 )
{
struct V_64 * V_65 , * V_66 = NULL ;
struct V_38 * V_38 ;
T_3 V_8 ;
long V_3 ;
V_3 = 0 ;
if ( V_44 == ( T_5 ) - 1 && V_45 == ( T_6 ) - 1 )
goto error;
V_8 = F_4 ( V_6 , V_10 | V_41 ,
V_25 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_38 = F_7 ( V_8 ) ;
V_3 = - V_24 ;
F_46 ( & V_38 -> V_63 ) ;
if ( ! F_24 ( V_28 ) ) {
if ( V_44 != ( T_5 ) - 1 && V_38 -> V_44 != V_44 )
goto V_32;
if ( V_45 != ( T_6 ) - 1 && V_45 != V_38 -> V_45 && ! F_47 ( V_45 ) )
goto V_32;
}
if ( V_44 != ( T_5 ) - 1 && V_44 != V_38 -> V_44 ) {
V_3 = - V_19 ;
V_65 = F_48 ( V_44 , F_49 () ) ;
if ( ! V_65 )
goto V_32;
if ( F_25 ( V_67 , & V_38 -> V_30 ) ) {
unsigned V_68 = ( V_44 == 0 ) ?
V_69 : V_70 ;
unsigned V_71 = ( V_44 == 0 ) ?
V_72 : V_73 ;
F_50 ( & V_65 -> V_74 ) ;
if ( V_65 -> V_75 + 1 >= V_68 ||
V_65 -> V_76 + V_38 -> V_77 >= V_71 ||
V_65 -> V_76 + V_38 -> V_77 <
V_65 -> V_76 )
goto V_78;
V_65 -> V_75 ++ ;
V_65 -> V_76 += V_38 -> V_77 ;
F_51 ( & V_65 -> V_74 ) ;
F_50 ( & V_38 -> V_79 -> V_74 ) ;
V_38 -> V_79 -> V_75 -- ;
V_38 -> V_79 -> V_76 -= V_38 -> V_77 ;
F_51 ( & V_38 -> V_79 -> V_74 ) ;
}
F_52 ( & V_38 -> V_79 -> V_80 ) ;
F_53 ( & V_65 -> V_80 ) ;
if ( F_25 ( V_81 , & V_38 -> V_30 ) ) {
F_52 ( & V_38 -> V_79 -> V_82 ) ;
F_53 ( & V_65 -> V_82 ) ;
}
V_66 = V_38 -> V_79 ;
V_38 -> V_79 = V_65 ;
V_38 -> V_44 = V_44 ;
}
if ( V_45 != ( T_6 ) - 1 )
V_38 -> V_45 = V_45 ;
V_3 = 0 ;
V_32:
F_54 ( & V_38 -> V_63 ) ;
F_33 ( V_38 ) ;
if ( V_66 )
F_55 ( V_66 ) ;
error:
return V_3 ;
V_78:
F_51 ( & V_65 -> V_74 ) ;
V_66 = V_65 ;
V_3 = - V_83 ;
goto V_32;
}
long F_56 ( T_2 V_6 , T_7 V_46 )
{
struct V_38 * V_38 ;
T_3 V_8 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_46 & ~ ( V_84 | V_85 | V_86 | V_87 ) )
goto error;
V_8 = F_4 ( V_6 , V_10 | V_41 ,
V_25 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_38 = F_7 ( V_8 ) ;
V_3 = - V_24 ;
F_46 ( & V_38 -> V_63 ) ;
if ( F_24 ( V_28 ) || V_38 -> V_44 == F_57 () ) {
V_38 -> V_46 = V_46 ;
V_3 = 0 ;
}
F_54 ( & V_38 -> V_63 ) ;
F_33 ( V_38 ) ;
error:
return V_3 ;
}
static long F_58 ( T_2 V_26 ,
struct V_88 * V_89 ,
struct V_38 * * V_90 )
{
T_3 V_91 ;
* V_90 = NULL ;
if ( V_26 == 0 )
return 0 ;
if ( V_26 > 0 ) {
V_91 = F_4 ( V_26 , V_10 , V_23 ) ;
if ( F_5 ( V_91 ) )
return F_6 ( V_91 ) ;
* V_90 = F_7 ( V_91 ) ;
return 0 ;
}
if ( V_26 == V_92 )
return - V_4 ;
if ( V_26 >= V_93 ) {
* V_90 = F_59 ( V_89 -> V_94 ) ;
return 0 ;
}
return - V_56 ;
}
static int F_60 ( struct V_38 * V_38 )
{
struct V_95 * V_96 ;
V_96 = F_61 () ;
if ( ! V_96 )
return - V_19 ;
F_33 ( V_96 -> V_88 ) ;
V_96 -> V_88 = F_59 ( V_38 ) ;
return F_62 ( V_96 ) ;
}
static long F_63 ( void * V_36 , const struct V_97 * V_98 ,
unsigned V_99 )
{
for (; V_99 > 0 ; V_99 -- ) {
if ( F_15 ( V_36 , V_98 -> V_100 , V_98 -> V_101 ) != 0 )
return - V_21 ;
V_36 += V_98 -> V_101 ;
V_98 ++ ;
}
return 0 ;
}
long F_64 ( T_2 V_6 ,
const struct V_97 * V_102 ,
unsigned V_99 ,
T_4 V_17 ,
T_2 V_26 )
{
const struct V_95 * V_95 = F_65 () ;
struct V_88 * V_89 ;
struct V_38 * V_39 , * V_94 ;
void * V_18 ;
long V_3 ;
bool V_103 = false ;
F_20 ( L_5 , V_6 , V_17 , V_26 ) ;
V_3 = - V_4 ;
if ( V_17 > 1024 * 1024 - 1 )
goto error;
V_3 = - V_5 ;
V_39 = V_95 -> V_88 ;
if ( ! V_39 )
goto error;
V_89 = V_39 -> V_18 . V_104 ;
if ( V_89 -> V_105 -> V_12 != V_6 )
goto error;
V_18 = NULL ;
if ( V_102 ) {
V_3 = - V_19 ;
V_18 = F_14 ( V_17 , V_20 ) ;
if ( ! V_18 ) {
if ( V_17 <= V_15 )
goto error;
V_103 = true ;
V_18 = F_66 ( V_17 ) ;
if ( ! V_18 )
goto error;
}
V_3 = F_63 ( V_18 , V_102 , V_99 ) ;
if ( V_3 < 0 )
goto V_22;
}
V_3 = F_58 ( V_26 , V_89 , & V_94 ) ;
if ( V_3 < 0 )
goto V_22;
V_3 = F_67 ( V_89 -> V_105 , V_18 , V_17 ,
V_94 , V_39 ) ;
F_33 ( V_94 ) ;
if ( V_3 == 0 )
F_60 ( NULL ) ;
V_22:
if ( ! V_103 )
F_12 ( V_18 ) ;
else
F_68 ( V_18 ) ;
error:
return V_3 ;
}
long F_69 ( T_2 V_6 ,
const void T_1 * V_16 ,
T_4 V_17 ,
T_2 V_26 )
{
if ( V_16 && V_17 ) {
struct V_97 V_98 [ 1 ] = {
[ 0 ] . V_100 = ( void T_1 * ) V_16 ,
[ 0 ] . V_101 = V_17
} ;
return F_64 ( V_6 , V_98 , 1 , V_17 , V_26 ) ;
}
return F_64 ( V_6 , NULL , 0 , 0 , V_26 ) ;
}
long F_70 ( T_2 V_6 ,
const struct V_97 T_1 * V_106 ,
unsigned V_99 ,
T_2 V_26 )
{
struct V_97 V_107 [ V_108 ] , * V_98 = V_107 ;
long V_3 ;
if ( V_106 == 0 || V_99 == 0 )
goto V_109;
V_3 = F_71 ( V_110 , V_106 , V_99 ,
F_72 ( V_107 ) , V_107 , & V_98 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 == 0 )
goto V_111;
V_3 = F_64 ( V_6 , V_98 , V_99 , V_3 , V_26 ) ;
if ( V_98 != V_107 )
F_12 ( V_98 ) ;
return V_3 ;
V_111:
if ( V_98 != V_107 )
F_12 ( V_98 ) ;
V_109:
return F_64 ( V_6 , NULL , 0 , 0 , V_26 ) ;
}
long F_73 ( T_2 V_6 , unsigned V_112 , T_2 V_26 )
{
return F_74 ( V_6 , V_112 , V_56 , V_26 ) ;
}
long F_74 ( T_2 V_6 , unsigned V_112 , unsigned error ,
T_2 V_26 )
{
const struct V_95 * V_95 = F_65 () ;
struct V_88 * V_89 ;
struct V_38 * V_39 , * V_94 ;
long V_3 ;
F_20 ( L_6 , V_6 , V_112 , error , V_26 ) ;
if ( error <= 0 ||
error >= V_113 ||
error == V_114 ||
error == V_115 ||
error == V_116 ||
error == V_117 )
return - V_4 ;
V_3 = - V_5 ;
V_39 = V_95 -> V_88 ;
if ( ! V_39 )
goto error;
V_89 = V_39 -> V_18 . V_104 ;
if ( V_89 -> V_105 -> V_12 != V_6 )
goto error;
V_3 = F_58 ( V_26 , V_89 , & V_94 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_75 ( V_89 -> V_105 , V_112 , error ,
V_94 , V_39 ) ;
F_33 ( V_94 ) ;
if ( V_3 == 0 )
F_60 ( NULL ) ;
error:
return V_3 ;
}
long F_76 ( int V_118 )
{
struct V_95 * V_96 ;
int V_3 , V_119 ;
V_119 = F_77 ( V_120 ) ;
if ( V_118 == V_121 )
return V_119 ;
V_96 = F_61 () ;
if ( ! V_96 )
return - V_19 ;
switch ( V_118 ) {
case V_122 :
V_3 = F_78 ( V_96 ) ;
if ( V_3 < 0 )
goto error;
goto V_123;
case V_124 :
V_3 = F_79 ( V_96 ) ;
if ( V_3 < 0 ) {
if ( V_3 != - V_125 )
goto error;
V_3 = 0 ;
}
goto V_123;
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
goto V_123;
case V_121 :
case V_131 :
default:
V_3 = - V_4 ;
goto error;
}
V_123:
V_96 -> V_120 = V_118 ;
F_62 ( V_96 ) ;
return V_119 ;
error:
F_80 ( V_96 ) ;
return V_3 ;
}
long F_81 ( T_2 V_6 , unsigned V_112 )
{
struct V_38 * V_38 , * V_39 ;
T_3 V_8 ;
long V_3 ;
V_8 = F_4 ( V_6 , V_10 | V_41 ,
V_25 ) ;
if ( F_5 ( V_8 ) ) {
if ( F_6 ( V_8 ) == - V_24 ) {
V_39 = F_32 ( V_6 ) ;
if ( ! F_5 ( V_39 ) ) {
F_33 ( V_39 ) ;
V_8 = F_4 ( V_6 ,
V_41 ,
0 ) ;
if ( ! F_5 ( V_8 ) )
goto V_43;
}
}
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_43:
V_38 = F_7 ( V_8 ) ;
F_82 ( V_38 , V_112 ) ;
F_33 ( V_38 ) ;
V_3 = 0 ;
error:
return V_3 ;
}
long F_83 ( T_2 V_6 )
{
struct V_38 * V_132 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_6 < 0 )
goto error;
if ( V_6 == 0 ) {
V_3 = F_60 ( NULL ) ;
goto error;
}
V_132 = F_32 ( V_6 ) ;
if ( F_5 ( V_132 ) ) {
V_3 = F_6 ( V_132 ) ;
goto error;
}
V_3 = F_60 ( V_132 ) ;
if ( V_3 < 0 )
goto error;
F_33 ( V_132 ) ;
V_3 = V_132 -> V_12 ;
error:
return V_3 ;
}
long F_84 ( T_2 V_35 ,
char T_1 * V_36 ,
T_4 V_37 )
{
struct V_38 * V_38 , * V_39 ;
T_3 V_8 ;
char * V_133 ;
long V_3 ;
V_8 = F_4 ( V_35 , V_41 , V_42 ) ;
if ( F_5 ( V_8 ) ) {
if ( F_6 ( V_8 ) != - V_24 )
return F_6 ( V_8 ) ;
V_39 = F_32 ( V_35 ) ;
if ( F_5 ( V_39 ) )
return F_6 ( V_39 ) ;
F_33 ( V_39 ) ;
V_8 = F_4 ( V_35 , V_41 , 0 ) ;
if ( F_5 ( V_8 ) )
return F_6 ( V_8 ) ;
}
V_38 = F_7 ( V_8 ) ;
V_3 = F_85 ( V_38 , & V_133 ) ;
if ( V_3 == 0 ) {
V_3 = 1 ;
if ( V_36 && V_37 > 0 &&
F_34 ( V_36 , L_4 , 1 ) != 0 )
V_3 = - V_21 ;
} else if ( V_3 > 0 ) {
if ( V_36 && V_37 > 0 ) {
if ( V_37 > V_3 )
V_37 = V_3 ;
if ( F_34 ( V_36 , V_133 , V_37 ) != 0 )
V_3 = - V_21 ;
}
F_12 ( V_133 ) ;
}
F_8 ( V_8 ) ;
return V_3 ;
}
long F_86 ( void )
{
struct V_134 * V_135 , * V_136 ;
const struct V_95 * V_137 , * V_138 ;
struct V_139 * V_140 , * V_141 ;
T_3 V_142 ;
struct V_95 * V_95 ;
int V_3 ;
V_142 = F_4 ( V_143 , 0 , V_33 ) ;
if ( F_5 ( V_142 ) )
return F_6 ( V_142 ) ;
V_3 = - V_19 ;
V_140 = F_14 ( sizeof( struct V_139 ) , V_20 ) ;
if ( ! V_140 )
goto V_144;
V_95 = F_87 () ;
if ( ! V_95 )
goto V_145;
V_95 -> V_146 -> V_147 = F_7 ( V_142 ) ;
F_88 ( V_140 , V_148 , V_95 ) ;
V_135 = V_149 ;
F_89 () ;
F_90 ( & V_150 ) ;
V_3 = - V_5 ;
V_141 = NULL ;
V_136 = V_135 -> V_151 ;
if ( V_136 -> V_152 <= 1 || ! V_136 -> V_153 )
goto V_154;
if ( ! F_91 ( V_136 ) )
goto V_154;
V_137 = F_65 () ;
V_138 = F_92 ( V_136 ) ;
if ( V_137 == V_138 ||
V_137 -> V_146 -> V_147 == V_138 -> V_146 -> V_147 ) {
V_3 = 0 ;
goto V_154;
}
if ( V_138 -> V_44 != V_137 -> V_155 ||
V_138 -> V_155 != V_137 -> V_155 ||
V_138 -> V_156 != V_137 -> V_155 ||
V_138 -> V_45 != V_137 -> V_157 ||
V_138 -> V_157 != V_137 -> V_157 ||
V_138 -> V_158 != V_137 -> V_157 )
goto V_154;
if ( ( V_138 -> V_146 -> V_147 &&
V_138 -> V_146 -> V_147 -> V_44 != V_137 -> V_155 ) ||
V_137 -> V_146 -> V_147 -> V_44 != V_137 -> V_155 )
goto V_154;
V_141 = F_93 ( V_136 , V_148 ) ;
V_3 = F_94 ( V_136 , V_140 , true ) ;
if ( ! V_3 )
V_140 = NULL ;
V_154:
F_95 ( & V_150 ) ;
F_96 () ;
if ( V_141 ) {
F_97 ( V_141 -> V_104 ) ;
F_12 ( V_141 ) ;
}
if ( V_140 ) {
F_97 ( V_140 -> V_104 ) ;
F_12 ( V_140 ) ;
}
return V_3 ;
V_145:
F_12 ( V_140 ) ;
V_144:
F_8 ( V_142 ) ;
return V_3 ;
}
