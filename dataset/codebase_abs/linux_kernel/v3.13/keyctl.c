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
F_34 ( F_35 () , V_38 -> V_44 ) ,
F_36 ( F_35 () , V_38 -> V_45 ) ,
V_38 -> V_46 ,
V_38 -> V_47 ? : L_4 ) ;
if ( V_3 > V_15 - 1 )
V_3 = V_15 - 1 ;
V_40 [ V_3 ] = 0 ;
V_3 ++ ;
if ( V_36 && V_37 > 0 ) {
if ( V_37 > V_3 )
V_37 = V_3 ;
if ( F_37 ( V_36 , V_40 , V_37 ) != 0 )
V_3 = - V_21 ;
}
F_12 ( V_40 ) ;
V_22:
F_8 ( V_8 ) ;
error:
return V_3 ;
}
long F_38 ( T_2 V_26 ,
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
V_51 = F_39 ( type ) ;
if ( F_5 ( V_51 ) ) {
V_3 = F_6 ( V_51 ) ;
goto V_54;
}
V_8 = F_40 ( V_27 , V_51 , V_47 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
if ( V_3 == - V_55 )
V_3 = - V_56 ;
goto V_57;
}
if ( V_52 ) {
V_3 = F_41 ( V_8 , V_33 ) ;
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
F_42 ( V_51 ) ;
V_54:
F_8 ( V_52 ) ;
V_53:
F_8 ( V_27 ) ;
V_22:
F_12 ( V_47 ) ;
error:
return V_3 ;
}
long F_43 ( T_2 V_35 , char T_1 * V_36 , T_4 V_37 )
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
V_3 = F_41 ( V_8 , V_59 ) ;
if ( V_3 == 0 )
goto V_60;
if ( V_3 != - V_24 )
goto error;
if ( ! F_44 ( V_8 ) ) {
V_3 = - V_24 ;
goto V_22;
}
V_60:
V_3 = F_45 ( V_38 ) ;
if ( V_3 == 0 ) {
V_3 = - V_61 ;
if ( V_38 -> type -> V_62 ) {
F_46 ( & V_38 -> V_63 ) ;
V_3 = V_38 -> type -> V_62 ( V_38 , V_36 , V_37 ) ;
F_47 ( & V_38 -> V_63 ) ;
}
}
V_22:
F_33 ( V_38 ) ;
error:
return V_3 ;
}
long F_48 ( T_2 V_6 , T_5 V_64 , T_6 V_65 )
{
struct V_66 * V_67 , * V_68 = NULL ;
struct V_38 * V_38 ;
T_3 V_8 ;
long V_3 ;
T_7 V_44 ;
T_8 V_45 ;
V_44 = F_49 ( F_35 () , V_64 ) ;
V_45 = F_50 ( F_35 () , V_65 ) ;
V_3 = - V_4 ;
if ( ( V_64 != ( T_5 ) - 1 ) && ! F_51 ( V_44 ) )
goto error;
if ( ( V_65 != ( T_6 ) - 1 ) && ! F_52 ( V_45 ) )
goto error;
V_3 = 0 ;
if ( V_64 == ( T_5 ) - 1 && V_65 == ( T_6 ) - 1 )
goto error;
V_8 = F_4 ( V_6 , V_10 | V_41 ,
V_25 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_38 = F_7 ( V_8 ) ;
V_3 = - V_24 ;
F_53 ( & V_38 -> V_63 ) ;
if ( ! F_24 ( V_28 ) ) {
if ( V_64 != ( T_5 ) - 1 && ! F_54 ( V_38 -> V_44 , V_44 ) )
goto V_32;
if ( V_65 != ( T_6 ) - 1 && ! F_55 ( V_45 , V_38 -> V_45 ) && ! F_56 ( V_45 ) )
goto V_32;
}
if ( V_64 != ( T_5 ) - 1 && ! F_54 ( V_44 , V_38 -> V_44 ) ) {
V_3 = - V_19 ;
V_67 = F_57 ( V_44 ) ;
if ( ! V_67 )
goto V_32;
if ( F_25 ( V_69 , & V_38 -> V_30 ) ) {
unsigned V_70 = F_54 ( V_44 , V_71 ) ?
V_72 : V_73 ;
unsigned V_74 = F_54 ( V_44 , V_71 ) ?
V_75 : V_76 ;
F_58 ( & V_67 -> V_77 ) ;
if ( V_67 -> V_78 + 1 >= V_70 ||
V_67 -> V_79 + V_38 -> V_80 >= V_74 ||
V_67 -> V_79 + V_38 -> V_80 <
V_67 -> V_79 )
goto V_81;
V_67 -> V_78 ++ ;
V_67 -> V_79 += V_38 -> V_80 ;
F_59 ( & V_67 -> V_77 ) ;
F_58 ( & V_38 -> V_64 -> V_77 ) ;
V_38 -> V_64 -> V_78 -- ;
V_38 -> V_64 -> V_79 -= V_38 -> V_80 ;
F_59 ( & V_38 -> V_64 -> V_77 ) ;
}
F_60 ( & V_38 -> V_64 -> V_82 ) ;
F_61 ( & V_67 -> V_82 ) ;
if ( F_25 ( V_83 , & V_38 -> V_30 ) ) {
F_60 ( & V_38 -> V_64 -> V_84 ) ;
F_61 ( & V_67 -> V_84 ) ;
}
V_68 = V_38 -> V_64 ;
V_38 -> V_64 = V_67 ;
V_38 -> V_44 = V_44 ;
}
if ( V_65 != ( T_6 ) - 1 )
V_38 -> V_45 = V_45 ;
V_3 = 0 ;
V_32:
F_62 ( & V_38 -> V_63 ) ;
F_33 ( V_38 ) ;
if ( V_68 )
F_63 ( V_68 ) ;
error:
return V_3 ;
V_81:
F_59 ( & V_67 -> V_77 ) ;
V_68 = V_67 ;
V_3 = - V_85 ;
goto V_32;
}
long F_64 ( T_2 V_6 , T_9 V_46 )
{
struct V_38 * V_38 ;
T_3 V_8 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_46 & ~ ( V_86 | V_87 | V_88 | V_89 ) )
goto error;
V_8 = F_4 ( V_6 , V_10 | V_41 ,
V_25 ) ;
if ( F_5 ( V_8 ) ) {
V_3 = F_6 ( V_8 ) ;
goto error;
}
V_38 = F_7 ( V_8 ) ;
V_3 = - V_24 ;
F_53 ( & V_38 -> V_63 ) ;
if ( F_24 ( V_28 ) || F_54 ( V_38 -> V_44 , F_65 () ) ) {
V_38 -> V_46 = V_46 ;
V_3 = 0 ;
}
F_62 ( & V_38 -> V_63 ) ;
F_33 ( V_38 ) ;
error:
return V_3 ;
}
static long F_66 ( T_2 V_26 ,
struct V_90 * V_91 ,
struct V_38 * * V_92 )
{
T_3 V_93 ;
* V_92 = NULL ;
if ( V_26 == 0 )
return 0 ;
if ( V_26 > 0 ) {
V_93 = F_4 ( V_26 , V_10 , V_23 ) ;
if ( F_5 ( V_93 ) )
return F_6 ( V_93 ) ;
* V_92 = F_7 ( V_93 ) ;
return 0 ;
}
if ( V_26 == V_94 )
return - V_4 ;
if ( V_26 >= V_95 ) {
* V_92 = F_67 ( V_91 -> V_96 ) ;
return 0 ;
}
return - V_56 ;
}
static int F_68 ( struct V_38 * V_38 )
{
struct V_97 * V_98 ;
V_98 = F_69 () ;
if ( ! V_98 )
return - V_19 ;
F_33 ( V_98 -> V_90 ) ;
V_98 -> V_90 = F_67 ( V_38 ) ;
return F_70 ( V_98 ) ;
}
static long F_71 ( void * V_36 , const struct V_99 * V_100 ,
unsigned V_101 )
{
for (; V_101 > 0 ; V_101 -- ) {
if ( F_15 ( V_36 , V_100 -> V_102 , V_100 -> V_103 ) != 0 )
return - V_21 ;
V_36 += V_100 -> V_103 ;
V_100 ++ ;
}
return 0 ;
}
long F_72 ( T_2 V_6 ,
const struct V_99 * V_104 ,
unsigned V_101 ,
T_4 V_17 ,
T_2 V_26 )
{
const struct V_97 * V_97 = F_73 () ;
struct V_90 * V_91 ;
struct V_38 * V_39 , * V_96 ;
void * V_18 ;
long V_3 ;
bool V_105 = false ;
F_20 ( L_5 , V_6 , V_17 , V_26 ) ;
V_3 = - V_4 ;
if ( V_17 > 1024 * 1024 - 1 )
goto error;
V_3 = - V_5 ;
V_39 = V_97 -> V_90 ;
if ( ! V_39 )
goto error;
V_91 = V_39 -> V_18 . V_106 ;
if ( V_91 -> V_107 -> V_12 != V_6 )
goto error;
V_18 = NULL ;
if ( V_104 ) {
V_3 = - V_19 ;
V_18 = F_14 ( V_17 , V_20 ) ;
if ( ! V_18 ) {
if ( V_17 <= V_15 )
goto error;
V_105 = true ;
V_18 = F_74 ( V_17 ) ;
if ( ! V_18 )
goto error;
}
V_3 = F_71 ( V_18 , V_104 , V_101 ) ;
if ( V_3 < 0 )
goto V_22;
}
V_3 = F_66 ( V_26 , V_91 , & V_96 ) ;
if ( V_3 < 0 )
goto V_22;
V_3 = F_75 ( V_91 -> V_107 , V_18 , V_17 ,
V_96 , V_39 ) ;
F_33 ( V_96 ) ;
if ( V_3 == 0 )
F_68 ( NULL ) ;
V_22:
if ( ! V_105 )
F_12 ( V_18 ) ;
else
F_76 ( V_18 ) ;
error:
return V_3 ;
}
long F_77 ( T_2 V_6 ,
const void T_1 * V_16 ,
T_4 V_17 ,
T_2 V_26 )
{
if ( V_16 && V_17 ) {
struct V_99 V_100 [ 1 ] = {
[ 0 ] . V_102 = ( void T_1 * ) V_16 ,
[ 0 ] . V_103 = V_17
} ;
return F_72 ( V_6 , V_100 , 1 , V_17 , V_26 ) ;
}
return F_72 ( V_6 , NULL , 0 , 0 , V_26 ) ;
}
long F_78 ( T_2 V_6 ,
const struct V_99 T_1 * V_108 ,
unsigned V_101 ,
T_2 V_26 )
{
struct V_99 V_109 [ V_110 ] , * V_100 = V_109 ;
long V_3 ;
if ( ! V_108 || ! V_101 )
goto V_111;
V_3 = F_79 ( V_112 , V_108 , V_101 ,
F_80 ( V_109 ) , V_109 , & V_100 ) ;
if ( V_3 < 0 )
goto V_113;
if ( V_3 == 0 )
goto V_114;
V_3 = F_72 ( V_6 , V_100 , V_101 , V_3 , V_26 ) ;
V_113:
if ( V_100 != V_109 )
F_12 ( V_100 ) ;
return V_3 ;
V_114:
if ( V_100 != V_109 )
F_12 ( V_100 ) ;
V_111:
return F_72 ( V_6 , NULL , 0 , 0 , V_26 ) ;
}
long F_81 ( T_2 V_6 , unsigned V_115 , T_2 V_26 )
{
return F_82 ( V_6 , V_115 , V_56 , V_26 ) ;
}
long F_82 ( T_2 V_6 , unsigned V_115 , unsigned error ,
T_2 V_26 )
{
const struct V_97 * V_97 = F_73 () ;
struct V_90 * V_91 ;
struct V_38 * V_39 , * V_96 ;
long V_3 ;
F_20 ( L_6 , V_6 , V_115 , error , V_26 ) ;
if ( error <= 0 ||
error >= V_116 ||
error == V_117 ||
error == V_118 ||
error == V_119 ||
error == V_120 )
return - V_4 ;
V_3 = - V_5 ;
V_39 = V_97 -> V_90 ;
if ( ! V_39 )
goto error;
V_91 = V_39 -> V_18 . V_106 ;
if ( V_91 -> V_107 -> V_12 != V_6 )
goto error;
V_3 = F_66 ( V_26 , V_91 , & V_96 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_83 ( V_91 -> V_107 , V_115 , error ,
V_96 , V_39 ) ;
F_33 ( V_96 ) ;
if ( V_3 == 0 )
F_68 ( NULL ) ;
error:
return V_3 ;
}
long F_84 ( int V_121 )
{
struct V_97 * V_98 ;
int V_3 , V_122 ;
V_122 = F_85 ( V_123 ) ;
if ( V_121 == V_124 )
return V_122 ;
V_98 = F_69 () ;
if ( ! V_98 )
return - V_19 ;
switch ( V_121 ) {
case V_125 :
V_3 = F_86 ( V_98 ) ;
if ( V_3 < 0 )
goto error;
goto V_126;
case V_127 :
V_3 = F_87 ( V_98 ) ;
if ( V_3 < 0 ) {
if ( V_3 != - V_128 )
goto error;
V_3 = 0 ;
}
goto V_126;
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
goto V_126;
case V_124 :
case V_134 :
default:
V_3 = - V_4 ;
goto error;
}
V_126:
V_98 -> V_123 = V_121 ;
F_70 ( V_98 ) ;
return V_122 ;
error:
F_88 ( V_98 ) ;
return V_3 ;
}
long F_89 ( T_2 V_6 , unsigned V_115 )
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
F_90 ( V_38 , V_115 ) ;
F_33 ( V_38 ) ;
V_3 = 0 ;
error:
return V_3 ;
}
long F_91 ( T_2 V_6 )
{
struct V_38 * V_135 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_6 < 0 )
goto error;
if ( V_6 == 0 ) {
V_3 = F_68 ( NULL ) ;
goto error;
}
V_135 = F_32 ( V_6 ) ;
if ( F_5 ( V_135 ) ) {
V_3 = F_6 ( V_135 ) ;
goto error;
}
V_3 = F_68 ( V_135 ) ;
if ( V_3 < 0 )
goto error;
F_33 ( V_135 ) ;
V_3 = V_135 -> V_12 ;
error:
return V_3 ;
}
long F_92 ( T_2 V_35 ,
char T_1 * V_36 ,
T_4 V_37 )
{
struct V_38 * V_38 , * V_39 ;
T_3 V_8 ;
char * V_136 ;
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
V_3 = F_93 ( V_38 , & V_136 ) ;
if ( V_3 == 0 ) {
V_3 = 1 ;
if ( V_36 && V_37 > 0 &&
F_37 ( V_36 , L_4 , 1 ) != 0 )
V_3 = - V_21 ;
} else if ( V_3 > 0 ) {
if ( V_36 && V_37 > 0 ) {
if ( V_37 > V_3 )
V_37 = V_3 ;
if ( F_37 ( V_36 , V_136 , V_37 ) != 0 )
V_3 = - V_21 ;
}
F_12 ( V_136 ) ;
}
F_8 ( V_8 ) ;
return V_3 ;
}
long F_94 ( void )
{
struct V_137 * V_138 , * V_139 ;
const struct V_97 * V_140 , * V_141 ;
struct V_142 * V_143 , * V_144 ;
T_3 V_145 ;
struct V_97 * V_97 ;
int V_3 ;
V_145 = F_4 ( V_146 , 0 , V_33 ) ;
if ( F_5 ( V_145 ) )
return F_6 ( V_145 ) ;
V_3 = - V_19 ;
V_97 = F_95 () ;
if ( ! V_97 )
goto V_147;
V_143 = & V_97 -> V_148 ;
V_97 -> V_149 = F_7 ( V_145 ) ;
V_145 = NULL ;
F_96 ( V_143 , V_150 ) ;
V_138 = V_151 ;
F_97 () ;
F_98 ( & V_152 ) ;
V_3 = - V_5 ;
V_144 = NULL ;
V_139 = V_138 -> V_153 ;
if ( V_139 -> V_154 <= 1 || ! V_139 -> V_155 )
goto V_156;
if ( ! F_99 ( V_139 ) )
goto V_156;
V_140 = F_73 () ;
V_141 = F_100 ( V_139 ) ;
if ( V_140 == V_141 ||
V_140 -> V_149 == V_141 -> V_149 ) {
V_3 = 0 ;
goto V_156;
}
if ( ! F_54 ( V_141 -> V_44 , V_140 -> V_157 ) ||
! F_54 ( V_141 -> V_157 , V_140 -> V_157 ) ||
! F_54 ( V_141 -> V_158 , V_140 -> V_157 ) ||
! F_55 ( V_141 -> V_45 , V_140 -> V_159 ) ||
! F_55 ( V_141 -> V_159 , V_140 -> V_159 ) ||
! F_55 ( V_141 -> V_160 , V_140 -> V_159 ) )
goto V_156;
if ( ( V_141 -> V_149 &&
! F_54 ( V_141 -> V_149 -> V_44 , V_140 -> V_157 ) ) ||
! F_54 ( V_140 -> V_149 -> V_44 , V_140 -> V_157 ) )
goto V_156;
V_144 = F_101 ( V_139 , V_150 ) ;
V_3 = F_102 ( V_139 , V_143 , true ) ;
if ( ! V_3 )
V_143 = NULL ;
V_156:
F_103 ( & V_152 ) ;
F_104 () ;
if ( V_144 )
F_105 ( F_106 ( V_144 , struct V_97 , V_148 ) ) ;
if ( V_143 )
F_105 ( V_97 ) ;
return V_3 ;
V_147:
F_8 ( V_145 ) ;
return V_3 ;
}
