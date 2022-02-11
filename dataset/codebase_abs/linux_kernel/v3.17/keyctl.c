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
type [ V_2 - 1 ] = '\0' ;
return 0 ;
}
long F_3 ( T_2 V_5 , int V_6 )
{
T_3 V_7 ;
unsigned long V_8 ;
long V_3 ;
V_8 = V_6 ? V_9 : 0 ;
V_7 = F_4 ( V_5 , V_8 , V_10 ) ;
if ( F_5 ( V_7 ) ) {
V_3 = F_6 ( V_7 ) ;
goto error;
}
V_3 = F_7 ( V_7 ) -> V_11 ;
F_8 ( V_7 ) ;
error:
return V_3 ;
}
long F_9 ( const char T_1 * V_12 )
{
char * V_13 ;
long V_3 ;
V_13 = NULL ;
if ( V_12 ) {
V_13 = F_10 ( V_12 , V_14 ) ;
if ( F_5 ( V_13 ) ) {
V_3 = F_6 ( V_13 ) ;
goto error;
}
}
V_3 = F_11 ( V_13 ) ;
F_12 ( V_13 ) ;
error:
return V_3 ;
}
long F_13 ( T_2 V_5 ,
const void T_1 * V_15 ,
T_4 V_16 )
{
T_3 V_7 ;
void * V_17 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_16 > V_14 )
goto error;
V_17 = NULL ;
if ( V_15 ) {
V_3 = - V_18 ;
V_17 = F_14 ( V_16 , V_19 ) ;
if ( ! V_17 )
goto error;
V_3 = - V_20 ;
if ( F_15 ( V_17 , V_15 , V_16 ) != 0 )
goto V_21;
}
V_7 = F_4 ( V_5 , 0 , V_22 ) ;
if ( F_5 ( V_7 ) ) {
V_3 = F_6 ( V_7 ) ;
goto V_21;
}
V_3 = F_16 ( V_7 , V_17 , V_16 ) ;
F_8 ( V_7 ) ;
V_21:
F_12 ( V_17 ) ;
error:
return V_3 ;
}
long F_17 ( T_2 V_5 )
{
T_3 V_7 ;
long V_3 ;
V_7 = F_4 ( V_5 , 0 , V_22 ) ;
if ( F_5 ( V_7 ) ) {
V_3 = F_6 ( V_7 ) ;
if ( V_3 != - V_23 )
goto error;
V_7 = F_4 ( V_5 , 0 , V_24 ) ;
if ( F_5 ( V_7 ) ) {
V_3 = F_6 ( V_7 ) ;
goto error;
}
}
F_18 ( F_7 ( V_7 ) ) ;
V_3 = 0 ;
F_8 ( V_7 ) ;
error:
return V_3 ;
}
long F_19 ( T_2 V_5 )
{
T_3 V_7 ;
long V_3 ;
F_20 ( L_1 , V_5 ) ;
V_7 = F_4 ( V_5 , 0 , V_10 ) ;
if ( F_5 ( V_7 ) ) {
V_3 = F_6 ( V_7 ) ;
if ( F_21 ( V_25 ) ) {
V_7 = F_4 ( V_5 , 0 , 0 ) ;
if ( F_5 ( V_7 ) )
goto error;
if ( F_22 ( V_26 ,
& F_7 ( V_7 ) -> V_27 ) )
goto V_28;
goto V_29;
}
goto error;
}
V_28:
F_23 ( F_7 ( V_7 ) ) ;
V_3 = 0 ;
V_29:
F_8 ( V_7 ) ;
error:
F_24 ( L_2 , V_3 ) ;
return V_3 ;
}
long F_25 ( T_2 V_30 )
{
T_3 V_31 ;
long V_3 ;
V_31 = F_4 ( V_30 , V_9 , V_22 ) ;
if ( F_5 ( V_31 ) ) {
V_3 = F_6 ( V_31 ) ;
if ( F_21 ( V_25 ) ) {
V_31 = F_4 ( V_30 , 0 , 0 ) ;
if ( F_5 ( V_31 ) )
goto error;
if ( F_22 ( V_32 ,
& F_7 ( V_31 ) -> V_27 ) )
goto V_33;
goto V_29;
}
goto error;
}
V_33:
V_3 = F_26 ( F_7 ( V_31 ) ) ;
V_29:
F_8 ( V_31 ) ;
error:
return V_3 ;
}
long F_27 ( T_2 V_5 , T_2 V_30 )
{
T_3 V_31 , V_7 ;
long V_3 ;
V_31 = F_4 ( V_30 , V_9 , V_22 ) ;
if ( F_5 ( V_31 ) ) {
V_3 = F_6 ( V_31 ) ;
goto error;
}
V_7 = F_4 ( V_5 , V_9 , V_34 ) ;
if ( F_5 ( V_7 ) ) {
V_3 = F_6 ( V_7 ) ;
goto V_21;
}
V_3 = F_28 ( F_7 ( V_31 ) , F_7 ( V_7 ) ) ;
F_8 ( V_7 ) ;
V_21:
F_8 ( V_31 ) ;
error:
return V_3 ;
}
long F_29 ( T_2 V_5 , T_2 V_30 )
{
T_3 V_31 , V_7 ;
long V_3 ;
V_31 = F_4 ( V_30 , 0 , V_22 ) ;
if ( F_5 ( V_31 ) ) {
V_3 = F_6 ( V_31 ) ;
goto error;
}
V_7 = F_4 ( V_5 , V_35 , 0 ) ;
if ( F_5 ( V_7 ) ) {
V_3 = F_6 ( V_7 ) ;
goto V_21;
}
V_3 = F_30 ( F_7 ( V_31 ) , F_7 ( V_7 ) ) ;
F_8 ( V_7 ) ;
V_21:
F_8 ( V_31 ) ;
error:
return V_3 ;
}
long F_31 ( T_2 V_36 ,
char T_1 * V_37 ,
T_4 V_38 )
{
struct V_39 * V_39 , * V_40 ;
T_3 V_7 ;
char * V_41 ;
long V_3 ;
V_7 = F_4 ( V_36 , V_42 , V_43 ) ;
if ( F_5 ( V_7 ) ) {
if ( F_6 ( V_7 ) == - V_23 ) {
V_40 = F_32 ( V_36 ) ;
if ( ! F_5 ( V_40 ) ) {
F_33 ( V_40 ) ;
V_7 = F_4 ( V_36 ,
V_42 ,
0 ) ;
if ( ! F_5 ( V_7 ) )
goto V_44;
}
}
V_3 = F_6 ( V_7 ) ;
goto error;
}
V_44:
V_3 = - V_18 ;
V_41 = F_14 ( V_14 , V_19 ) ;
if ( ! V_41 )
goto V_21;
V_39 = F_7 ( V_7 ) ;
V_3 = snprintf ( V_41 , V_14 - 1 ,
L_3 ,
V_39 -> type -> V_13 ,
F_34 ( F_35 () , V_39 -> V_45 ) ,
F_36 ( F_35 () , V_39 -> V_46 ) ,
V_39 -> V_47 ,
V_39 -> V_48 ? : L_4 ) ;
if ( V_3 > V_14 - 1 )
V_3 = V_14 - 1 ;
V_41 [ V_3 ] = 0 ;
V_3 ++ ;
if ( V_37 && V_38 > 0 ) {
if ( V_38 > V_3 )
V_38 = V_3 ;
if ( F_37 ( V_37 , V_41 , V_38 ) != 0 )
V_3 = - V_20 ;
}
F_12 ( V_41 ) ;
V_21:
F_8 ( V_7 ) ;
error:
return V_3 ;
}
long F_38 ( T_2 V_30 ,
const char T_1 * V_1 ,
const char T_1 * V_49 ,
T_2 V_50 )
{
struct V_51 * V_52 ;
T_3 V_31 , V_7 , V_53 ;
char type [ 32 ] , * V_48 ;
long V_3 ;
V_3 = F_1 ( type , V_1 , sizeof( type ) ) ;
if ( V_3 < 0 )
goto error;
V_48 = F_10 ( V_49 , V_14 ) ;
if ( F_5 ( V_48 ) ) {
V_3 = F_6 ( V_48 ) ;
goto error;
}
V_31 = F_4 ( V_30 , 0 , V_10 ) ;
if ( F_5 ( V_31 ) ) {
V_3 = F_6 ( V_31 ) ;
goto V_21;
}
V_53 = NULL ;
if ( V_50 ) {
V_53 = F_4 ( V_50 , V_9 ,
V_22 ) ;
if ( F_5 ( V_53 ) ) {
V_3 = F_6 ( V_53 ) ;
goto V_54;
}
}
V_52 = F_39 ( type ) ;
if ( F_5 ( V_52 ) ) {
V_3 = F_6 ( V_52 ) ;
goto V_55;
}
V_7 = F_40 ( V_31 , V_52 , V_48 ) ;
if ( F_5 ( V_7 ) ) {
V_3 = F_6 ( V_7 ) ;
if ( V_3 == - V_56 )
V_3 = - V_57 ;
goto V_58;
}
if ( V_53 ) {
V_3 = F_41 ( V_7 , V_34 ) ;
if ( V_3 < 0 )
goto V_59;
V_3 = F_28 ( F_7 ( V_53 ) , F_7 ( V_7 ) ) ;
if ( V_3 < 0 )
goto V_59;
}
V_3 = F_7 ( V_7 ) -> V_11 ;
V_59:
F_8 ( V_7 ) ;
V_58:
F_42 ( V_52 ) ;
V_55:
F_8 ( V_53 ) ;
V_54:
F_8 ( V_31 ) ;
V_21:
F_12 ( V_48 ) ;
error:
return V_3 ;
}
long F_43 ( T_2 V_36 , char T_1 * V_37 , T_4 V_38 )
{
struct V_39 * V_39 ;
T_3 V_7 ;
long V_3 ;
V_7 = F_4 ( V_36 , 0 , 0 ) ;
if ( F_5 ( V_7 ) ) {
V_3 = - V_57 ;
goto error;
}
V_39 = F_7 ( V_7 ) ;
V_3 = F_41 ( V_7 , V_60 ) ;
if ( V_3 == 0 )
goto V_61;
if ( V_3 != - V_23 )
goto error;
if ( ! F_44 ( V_7 ) ) {
V_3 = - V_23 ;
goto V_21;
}
V_61:
V_3 = F_45 ( V_39 ) ;
if ( V_3 == 0 ) {
V_3 = - V_62 ;
if ( V_39 -> type -> V_63 ) {
F_46 ( & V_39 -> V_64 ) ;
V_3 = V_39 -> type -> V_63 ( V_39 , V_37 , V_38 ) ;
F_47 ( & V_39 -> V_64 ) ;
}
}
V_21:
F_33 ( V_39 ) ;
error:
return V_3 ;
}
long F_48 ( T_2 V_5 , T_5 V_65 , T_6 V_66 )
{
struct V_67 * V_68 , * V_69 = NULL ;
struct V_39 * V_39 ;
T_3 V_7 ;
long V_3 ;
T_7 V_45 ;
T_8 V_46 ;
V_45 = F_49 ( F_35 () , V_65 ) ;
V_46 = F_50 ( F_35 () , V_66 ) ;
V_3 = - V_4 ;
if ( ( V_65 != ( T_5 ) - 1 ) && ! F_51 ( V_45 ) )
goto error;
if ( ( V_66 != ( T_6 ) - 1 ) && ! F_52 ( V_46 ) )
goto error;
V_3 = 0 ;
if ( V_65 == ( T_5 ) - 1 && V_66 == ( T_6 ) - 1 )
goto error;
V_7 = F_4 ( V_5 , V_9 | V_42 ,
V_24 ) ;
if ( F_5 ( V_7 ) ) {
V_3 = F_6 ( V_7 ) ;
goto error;
}
V_39 = F_7 ( V_7 ) ;
V_3 = - V_23 ;
F_53 ( & V_39 -> V_64 ) ;
if ( ! F_21 ( V_25 ) ) {
if ( V_65 != ( T_5 ) - 1 && ! F_54 ( V_39 -> V_45 , V_45 ) )
goto V_29;
if ( V_66 != ( T_6 ) - 1 && ! F_55 ( V_46 , V_39 -> V_46 ) && ! F_56 ( V_46 ) )
goto V_29;
}
if ( V_65 != ( T_5 ) - 1 && ! F_54 ( V_45 , V_39 -> V_45 ) ) {
V_3 = - V_18 ;
V_68 = F_57 ( V_45 ) ;
if ( ! V_68 )
goto V_29;
if ( F_22 ( V_70 , & V_39 -> V_27 ) ) {
unsigned V_71 = F_54 ( V_45 , V_72 ) ?
V_73 : V_74 ;
unsigned V_75 = F_54 ( V_45 , V_72 ) ?
V_76 : V_77 ;
F_58 ( & V_68 -> V_78 ) ;
if ( V_68 -> V_79 + 1 >= V_71 ||
V_68 -> V_80 + V_39 -> V_81 >= V_75 ||
V_68 -> V_80 + V_39 -> V_81 <
V_68 -> V_80 )
goto V_82;
V_68 -> V_79 ++ ;
V_68 -> V_80 += V_39 -> V_81 ;
F_59 ( & V_68 -> V_78 ) ;
F_58 ( & V_39 -> V_65 -> V_78 ) ;
V_39 -> V_65 -> V_79 -- ;
V_39 -> V_65 -> V_80 -= V_39 -> V_81 ;
F_59 ( & V_39 -> V_65 -> V_78 ) ;
}
F_60 ( & V_39 -> V_65 -> V_83 ) ;
F_61 ( & V_68 -> V_83 ) ;
if ( F_22 ( V_84 , & V_39 -> V_27 ) ) {
F_60 ( & V_39 -> V_65 -> V_85 ) ;
F_61 ( & V_68 -> V_85 ) ;
}
V_69 = V_39 -> V_65 ;
V_39 -> V_65 = V_68 ;
V_39 -> V_45 = V_45 ;
}
if ( V_66 != ( T_6 ) - 1 )
V_39 -> V_46 = V_46 ;
V_3 = 0 ;
V_29:
F_62 ( & V_39 -> V_64 ) ;
F_33 ( V_39 ) ;
if ( V_69 )
F_63 ( V_69 ) ;
error:
return V_3 ;
V_82:
F_59 ( & V_68 -> V_78 ) ;
V_69 = V_68 ;
V_3 = - V_86 ;
goto V_29;
}
long F_64 ( T_2 V_5 , T_9 V_47 )
{
struct V_39 * V_39 ;
T_3 V_7 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_47 & ~ ( V_87 | V_88 | V_89 | V_90 ) )
goto error;
V_7 = F_4 ( V_5 , V_9 | V_42 ,
V_24 ) ;
if ( F_5 ( V_7 ) ) {
V_3 = F_6 ( V_7 ) ;
goto error;
}
V_39 = F_7 ( V_7 ) ;
V_3 = - V_23 ;
F_53 ( & V_39 -> V_64 ) ;
if ( F_21 ( V_25 ) || F_54 ( V_39 -> V_45 , F_65 () ) ) {
V_39 -> V_47 = V_47 ;
V_3 = 0 ;
}
F_62 ( & V_39 -> V_64 ) ;
F_33 ( V_39 ) ;
error:
return V_3 ;
}
static long F_66 ( T_2 V_30 ,
struct V_91 * V_92 ,
struct V_39 * * V_93 )
{
T_3 V_94 ;
* V_93 = NULL ;
if ( V_30 == 0 )
return 0 ;
if ( V_30 > 0 ) {
V_94 = F_4 ( V_30 , V_9 , V_22 ) ;
if ( F_5 ( V_94 ) )
return F_6 ( V_94 ) ;
* V_93 = F_7 ( V_94 ) ;
return 0 ;
}
if ( V_30 == V_95 )
return - V_4 ;
if ( V_30 >= V_96 ) {
* V_93 = F_67 ( V_92 -> V_97 ) ;
return 0 ;
}
return - V_57 ;
}
static int F_68 ( struct V_39 * V_39 )
{
struct V_98 * V_99 ;
V_99 = F_69 () ;
if ( ! V_99 )
return - V_18 ;
F_33 ( V_99 -> V_91 ) ;
V_99 -> V_91 = F_67 ( V_39 ) ;
return F_70 ( V_99 ) ;
}
static long F_71 ( void * V_37 , const struct V_100 * V_101 ,
unsigned V_102 )
{
for (; V_102 > 0 ; V_102 -- ) {
if ( F_15 ( V_37 , V_101 -> V_103 , V_101 -> V_104 ) != 0 )
return - V_20 ;
V_37 += V_101 -> V_104 ;
V_101 ++ ;
}
return 0 ;
}
long F_72 ( T_2 V_5 ,
const struct V_100 * V_105 ,
unsigned V_102 ,
T_4 V_16 ,
T_2 V_30 )
{
const struct V_98 * V_98 = F_73 () ;
struct V_91 * V_92 ;
struct V_39 * V_40 , * V_97 ;
void * V_17 ;
long V_3 ;
bool V_106 = false ;
F_20 ( L_5 , V_5 , V_16 , V_30 ) ;
V_3 = - V_4 ;
if ( V_16 > 1024 * 1024 - 1 )
goto error;
V_3 = - V_107 ;
V_40 = V_98 -> V_91 ;
if ( ! V_40 )
goto error;
V_92 = V_40 -> V_17 . V_108 ;
if ( V_92 -> V_109 -> V_11 != V_5 )
goto error;
V_17 = NULL ;
if ( V_105 ) {
V_3 = - V_18 ;
V_17 = F_14 ( V_16 , V_19 ) ;
if ( ! V_17 ) {
if ( V_16 <= V_14 )
goto error;
V_106 = true ;
V_17 = F_74 ( V_16 ) ;
if ( ! V_17 )
goto error;
}
V_3 = F_71 ( V_17 , V_105 , V_102 ) ;
if ( V_3 < 0 )
goto V_21;
}
V_3 = F_66 ( V_30 , V_92 , & V_97 ) ;
if ( V_3 < 0 )
goto V_21;
V_3 = F_75 ( V_92 -> V_109 , V_17 , V_16 ,
V_97 , V_40 ) ;
F_33 ( V_97 ) ;
if ( V_3 == 0 )
F_68 ( NULL ) ;
V_21:
if ( ! V_106 )
F_12 ( V_17 ) ;
else
F_76 ( V_17 ) ;
error:
return V_3 ;
}
long F_77 ( T_2 V_5 ,
const void T_1 * V_15 ,
T_4 V_16 ,
T_2 V_30 )
{
if ( V_15 && V_16 ) {
struct V_100 V_101 [ 1 ] = {
[ 0 ] . V_103 = ( void T_1 * ) V_15 ,
[ 0 ] . V_104 = V_16
} ;
return F_72 ( V_5 , V_101 , 1 , V_16 , V_30 ) ;
}
return F_72 ( V_5 , NULL , 0 , 0 , V_30 ) ;
}
long F_78 ( T_2 V_5 ,
const struct V_100 T_1 * V_110 ,
unsigned V_102 ,
T_2 V_30 )
{
struct V_100 V_111 [ V_112 ] , * V_101 = V_111 ;
long V_3 ;
if ( ! V_110 || ! V_102 )
goto V_113;
V_3 = F_79 ( V_114 , V_110 , V_102 ,
F_80 ( V_111 ) , V_111 , & V_101 ) ;
if ( V_3 < 0 )
goto V_115;
if ( V_3 == 0 )
goto V_116;
V_3 = F_72 ( V_5 , V_101 , V_102 , V_3 , V_30 ) ;
V_115:
if ( V_101 != V_111 )
F_12 ( V_101 ) ;
return V_3 ;
V_116:
if ( V_101 != V_111 )
F_12 ( V_101 ) ;
V_113:
return F_72 ( V_5 , NULL , 0 , 0 , V_30 ) ;
}
long F_81 ( T_2 V_5 , unsigned V_117 , T_2 V_30 )
{
return F_82 ( V_5 , V_117 , V_57 , V_30 ) ;
}
long F_82 ( T_2 V_5 , unsigned V_117 , unsigned error ,
T_2 V_30 )
{
const struct V_98 * V_98 = F_73 () ;
struct V_91 * V_92 ;
struct V_39 * V_40 , * V_97 ;
long V_3 ;
F_20 ( L_6 , V_5 , V_117 , error , V_30 ) ;
if ( error <= 0 ||
error >= V_118 ||
error == V_119 ||
error == V_120 ||
error == V_121 ||
error == V_122 )
return - V_4 ;
V_3 = - V_107 ;
V_40 = V_98 -> V_91 ;
if ( ! V_40 )
goto error;
V_92 = V_40 -> V_17 . V_108 ;
if ( V_92 -> V_109 -> V_11 != V_5 )
goto error;
V_3 = F_66 ( V_30 , V_92 , & V_97 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_83 ( V_92 -> V_109 , V_117 , error ,
V_97 , V_40 ) ;
F_33 ( V_97 ) ;
if ( V_3 == 0 )
F_68 ( NULL ) ;
error:
return V_3 ;
}
long F_84 ( int V_123 )
{
struct V_98 * V_99 ;
int V_3 , V_124 ;
V_124 = F_85 ( V_125 ) ;
if ( V_123 == V_126 )
return V_124 ;
V_99 = F_69 () ;
if ( ! V_99 )
return - V_18 ;
switch ( V_123 ) {
case V_127 :
V_3 = F_86 ( V_99 ) ;
if ( V_3 < 0 )
goto error;
goto V_128;
case V_129 :
V_3 = F_87 ( V_99 ) ;
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
V_99 -> V_125 = V_123 ;
F_70 ( V_99 ) ;
return V_124 ;
error:
F_88 ( V_99 ) ;
return V_3 ;
}
long F_89 ( T_2 V_5 , unsigned V_117 )
{
struct V_39 * V_39 , * V_40 ;
T_3 V_7 ;
long V_3 ;
V_7 = F_4 ( V_5 , V_9 | V_42 ,
V_24 ) ;
if ( F_5 ( V_7 ) ) {
if ( F_6 ( V_7 ) == - V_23 ) {
V_40 = F_32 ( V_5 ) ;
if ( ! F_5 ( V_40 ) ) {
F_33 ( V_40 ) ;
V_7 = F_4 ( V_5 ,
V_42 ,
0 ) ;
if ( ! F_5 ( V_7 ) )
goto V_44;
}
}
V_3 = F_6 ( V_7 ) ;
goto error;
}
V_44:
V_39 = F_7 ( V_7 ) ;
F_90 ( V_39 , V_117 ) ;
F_33 ( V_39 ) ;
V_3 = 0 ;
error:
return V_3 ;
}
long F_91 ( T_2 V_5 )
{
struct V_39 * V_137 ;
long V_3 ;
V_3 = - V_4 ;
if ( V_5 < 0 )
goto error;
if ( V_5 == 0 ) {
V_3 = F_68 ( NULL ) ;
goto error;
}
V_137 = F_32 ( V_5 ) ;
if ( F_5 ( V_137 ) ) {
V_3 = F_6 ( V_137 ) ;
goto error;
}
V_3 = F_68 ( V_137 ) ;
if ( V_3 < 0 )
goto error;
F_33 ( V_137 ) ;
V_3 = V_137 -> V_11 ;
error:
return V_3 ;
}
long F_92 ( T_2 V_36 ,
char T_1 * V_37 ,
T_4 V_38 )
{
struct V_39 * V_39 , * V_40 ;
T_3 V_7 ;
char * V_138 ;
long V_3 ;
V_7 = F_4 ( V_36 , V_42 , V_43 ) ;
if ( F_5 ( V_7 ) ) {
if ( F_6 ( V_7 ) != - V_23 )
return F_6 ( V_7 ) ;
V_40 = F_32 ( V_36 ) ;
if ( F_5 ( V_40 ) )
return F_6 ( V_40 ) ;
F_33 ( V_40 ) ;
V_7 = F_4 ( V_36 , V_42 , 0 ) ;
if ( F_5 ( V_7 ) )
return F_6 ( V_7 ) ;
}
V_39 = F_7 ( V_7 ) ;
V_3 = F_93 ( V_39 , & V_138 ) ;
if ( V_3 == 0 ) {
V_3 = 1 ;
if ( V_37 && V_38 > 0 &&
F_37 ( V_37 , L_4 , 1 ) != 0 )
V_3 = - V_20 ;
} else if ( V_3 > 0 ) {
if ( V_37 && V_38 > 0 ) {
if ( V_38 > V_3 )
V_38 = V_3 ;
if ( F_37 ( V_37 , V_138 , V_38 ) != 0 )
V_3 = - V_20 ;
}
F_12 ( V_138 ) ;
}
F_8 ( V_7 ) ;
return V_3 ;
}
long F_94 ( void )
{
struct V_139 * V_140 , * V_141 ;
const struct V_98 * V_142 , * V_143 ;
struct V_144 * V_145 , * V_146 ;
T_3 V_147 ;
struct V_98 * V_98 ;
int V_3 ;
V_147 = F_4 ( V_148 , 0 , V_34 ) ;
if ( F_5 ( V_147 ) )
return F_6 ( V_147 ) ;
V_3 = - V_18 ;
V_98 = F_95 () ;
if ( ! V_98 )
goto V_149;
V_145 = & V_98 -> V_150 ;
V_98 -> V_151 = F_7 ( V_147 ) ;
V_147 = NULL ;
F_96 ( V_145 , V_152 ) ;
V_140 = V_153 ;
F_97 () ;
F_98 ( & V_154 ) ;
V_3 = - V_107 ;
V_146 = NULL ;
V_141 = V_140 -> V_155 ;
if ( V_141 -> V_156 <= 1 || ! V_141 -> V_157 )
goto V_158;
if ( ! F_99 ( V_141 ) )
goto V_158;
V_142 = F_73 () ;
V_143 = F_100 ( V_141 ) ;
if ( V_142 == V_143 ||
V_142 -> V_151 == V_143 -> V_151 ) {
V_3 = 0 ;
goto V_158;
}
if ( ! F_54 ( V_143 -> V_45 , V_142 -> V_159 ) ||
! F_54 ( V_143 -> V_159 , V_142 -> V_159 ) ||
! F_54 ( V_143 -> V_160 , V_142 -> V_159 ) ||
! F_55 ( V_143 -> V_46 , V_142 -> V_161 ) ||
! F_55 ( V_143 -> V_161 , V_142 -> V_161 ) ||
! F_55 ( V_143 -> V_162 , V_142 -> V_161 ) )
goto V_158;
if ( ( V_143 -> V_151 &&
! F_54 ( V_143 -> V_151 -> V_45 , V_142 -> V_159 ) ) ||
! F_54 ( V_142 -> V_151 -> V_45 , V_142 -> V_159 ) )
goto V_158;
V_146 = F_101 ( V_141 , V_152 ) ;
V_3 = F_102 ( V_141 , V_145 , true ) ;
if ( ! V_3 )
V_145 = NULL ;
V_158:
F_103 ( & V_154 ) ;
F_104 () ;
if ( V_146 )
F_105 ( F_106 ( V_146 , struct V_98 , V_150 ) ) ;
if ( V_145 )
F_105 ( V_98 ) ;
return V_3 ;
V_149:
F_8 ( V_147 ) ;
return V_3 ;
}
