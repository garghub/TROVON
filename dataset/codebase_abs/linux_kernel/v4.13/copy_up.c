static int F_1 ( const void * V_1 , struct V_2 * V_3 , unsigned int V_4 )
{
const struct V_5 * V_5 = V_1 ;
if ( F_2 ( V_3 ) == F_3 ( V_5 ) )
F_4 ( L_1 ,
V_3 , V_4 , V_6 -> V_7 , V_6 -> V_8 ) ;
return 0 ;
}
static void F_5 ( struct V_5 * V_5 )
{
if ( V_9 )
F_6 ( V_6 -> V_10 , 0 , F_1 , V_5 ) ;
}
int F_7 ( struct V_5 * V_11 , struct V_5 * V_12 )
{
T_1 V_13 , V_14 , V_15 = 0 ;
char * V_16 , * V_17 , * V_18 = NULL ;
int V_19 ( error ) ;
T_2 V_20 ;
if ( ! ( V_11 -> F_3 -> V_21 & V_22 ) ||
! ( V_12 -> F_3 -> V_21 & V_22 ) )
return 0 ;
V_13 = F_8 ( V_11 , NULL , 0 ) ;
if ( V_13 <= 0 ) {
if ( V_13 == - V_23 )
return 0 ;
return V_13 ;
}
V_16 = F_9 ( V_13 , V_24 ) ;
if ( ! V_16 )
return - V_25 ;
V_13 = F_8 ( V_11 , V_16 , V_13 ) ;
if ( V_13 <= 0 ) {
error = V_13 ;
goto V_26;
}
for ( V_17 = V_16 ; V_13 ; V_17 += V_20 ) {
V_20 = F_10 ( V_17 , V_13 ) + 1 ;
if ( F_11 ( V_20 > V_13 ) ) {
error = - V_27 ;
break;
}
V_13 -= V_20 ;
if ( F_12 ( V_17 ) )
continue;
V_28:
V_14 = F_13 ( V_11 , V_17 , V_18 , V_15 ) ;
if ( V_14 == - V_29 )
V_14 = F_13 ( V_11 , V_17 , NULL , 0 ) ;
if ( V_14 < 0 ) {
error = V_14 ;
break;
}
if ( V_14 > V_15 ) {
void * V_12 ;
V_12 = F_14 ( V_18 , V_14 , V_24 ) ;
if ( ! V_12 ) {
error = - V_25 ;
break;
}
V_18 = V_12 ;
V_15 = V_14 ;
goto V_28;
}
error = F_15 ( V_17 ) ;
if ( error < 0 && error != - V_23 )
break;
if ( error == 1 ) {
error = 0 ;
continue;
}
error = F_16 ( V_12 , V_17 , V_18 , V_14 , 0 ) ;
if ( error )
break;
}
F_17 ( V_18 ) ;
V_26:
F_17 ( V_16 ) ;
return error ;
}
static int F_18 ( struct V_30 * V_11 , struct V_30 * V_12 , T_3 V_31 )
{
struct V_2 * V_32 ;
struct V_2 * V_33 ;
T_3 V_34 = 0 ;
T_3 V_35 = 0 ;
int error = 0 ;
if ( V_31 == 0 )
return 0 ;
V_32 = F_19 ( V_11 , V_36 | V_37 ) ;
if ( F_20 ( V_32 ) )
return F_21 ( V_32 ) ;
V_33 = F_19 ( V_12 , V_36 | V_38 ) ;
if ( F_20 ( V_33 ) ) {
error = F_21 ( V_33 ) ;
goto V_39;
}
error = F_22 ( V_32 , 0 , V_33 , 0 , V_31 ) ;
if ( ! error )
goto V_26;
error = 0 ;
while ( V_31 ) {
T_2 V_40 = V_41 ;
long V_42 ;
if ( V_31 < V_40 )
V_40 = V_31 ;
if ( F_23 ( V_43 , V_6 ) ) {
error = - V_44 ;
break;
}
V_42 = F_24 ( V_32 , & V_34 ,
V_33 , & V_35 ,
V_40 , V_45 ) ;
if ( V_42 <= 0 ) {
error = V_42 ;
break;
}
F_11 ( V_34 != V_35 ) ;
V_31 -= V_42 ;
}
V_26:
if ( ! error )
error = F_25 ( V_33 , 0 ) ;
F_26 ( V_33 ) ;
V_39:
F_26 ( V_32 ) ;
return error ;
}
static int F_27 ( struct V_5 * V_46 , struct V_47 * V_48 )
{
struct V_49 V_50 = {
. V_51 =
V_52 | V_53 | V_54 | V_55 ,
. V_56 = V_48 -> V_57 ,
. V_58 = V_48 -> V_59 ,
} ;
return F_28 ( V_46 , & V_50 , NULL ) ;
}
int F_29 ( struct V_5 * V_46 , struct V_47 * V_48 )
{
int V_60 = 0 ;
if ( ! F_30 ( V_48 -> V_61 ) ) {
struct V_49 V_50 = {
. V_51 = V_62 ,
. V_63 = V_48 -> V_61 ,
} ;
V_60 = F_28 ( V_46 , & V_50 , NULL ) ;
}
if ( ! V_60 ) {
struct V_49 V_50 = {
. V_51 = V_64 | V_65 ,
. V_66 = V_48 -> V_67 ,
. V_68 = V_48 -> V_69 ,
} ;
V_60 = F_28 ( V_46 , & V_50 , NULL ) ;
}
if ( ! V_60 )
F_27 ( V_46 , V_48 ) ;
return V_60 ;
}
struct V_70 * F_31 ( struct V_5 * V_71 , bool V_72 )
{
struct V_70 * V_73 ;
int V_74 , V_75 , V_76 ;
void * V_16 ;
int V_77 = V_78 ;
T_4 * V_79 = & V_71 -> V_80 -> V_81 ;
V_16 = F_32 ( V_77 , V_82 ) ;
if ( ! V_16 )
return F_33 ( - V_25 ) ;
V_76 = V_77 >> 2 ;
V_74 = F_34 ( V_71 , V_16 , & V_76 , 0 ) ;
V_77 = ( V_76 << 2 ) ;
V_73 = F_33 ( - V_27 ) ;
if ( F_11 ( V_74 < 0 ) ||
F_11 ( V_77 > V_78 ) ||
F_11 ( V_74 == V_83 ) )
goto V_26;
F_35 ( V_78 + F_36 ( struct V_70 , V_84 ) > 255 ) ;
V_75 = F_36 ( struct V_70 , V_84 ) + V_77 ;
V_73 = F_32 ( V_75 , V_24 ) ;
if ( ! V_73 ) {
V_73 = F_33 ( - V_25 ) ;
goto V_26;
}
V_73 -> V_85 = V_86 ;
V_73 -> V_87 = V_88 ;
V_73 -> type = V_74 ;
V_73 -> V_89 = V_90 ;
if ( V_72 )
V_73 -> V_89 |= V_91 ;
V_73 -> V_31 = V_75 ;
V_73 -> V_79 = * V_79 ;
memcpy ( V_73 -> V_84 , V_16 , V_77 ) ;
V_26:
F_17 ( V_16 ) ;
return V_73 ;
}
static int F_37 ( struct V_5 * V_5 , struct V_5 * V_71 ,
struct V_5 * V_92 )
{
const struct V_70 * V_73 = NULL ;
int V_60 ;
if ( F_38 ( V_71 -> V_80 ) ) {
V_73 = F_31 ( V_71 , false ) ;
if ( F_20 ( V_73 ) )
return F_21 ( V_73 ) ;
}
V_60 = F_39 ( V_5 , V_92 , V_93 , V_73 ,
V_73 ? V_73 -> V_31 : 0 , 0 ) ;
F_17 ( V_73 ) ;
return V_60 ;
}
static int F_40 ( struct V_94 * V_95 )
{
int V_60 ;
struct V_5 * V_92 ;
struct V_5 * V_96 = F_41 ( V_95 -> V_97 ) ;
struct V_98 * V_99 = F_3 ( V_96 ) ;
V_60 = F_42 ( V_95 -> V_97 , V_96 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_43 ( V_95 -> V_5 ) ;
if ( V_60 )
return V_60 ;
F_44 ( V_99 , V_100 ) ;
V_92 = F_45 ( V_95 -> V_5 -> V_101 . V_17 , V_96 ,
V_95 -> V_5 -> V_101 . V_31 ) ;
V_60 = F_21 ( V_92 ) ;
if ( ! F_20 ( V_92 ) ) {
V_60 = F_46 ( F_41 ( V_95 -> V_5 ) , V_99 , V_92 ,
true ) ;
F_47 ( V_92 ) ;
if ( ! V_60 ) {
F_27 ( V_96 , & V_95 -> V_102 ) ;
F_48 ( V_95 -> V_5 ) ;
}
}
F_49 ( V_99 ) ;
F_50 ( V_95 -> V_5 ) ;
return V_60 ;
}
static int F_51 ( struct V_94 * V_95 , struct V_5 * V_103 ,
struct V_5 * * V_104 )
{
int V_60 ;
struct V_5 * V_92 ;
struct V_98 * V_99 = F_3 ( V_95 -> V_105 ) ;
V_92 = F_45 ( V_95 -> V_106 . V_17 , V_95 -> V_105 , V_95 -> V_106 . V_31 ) ;
if ( F_20 ( V_92 ) )
return F_21 ( V_92 ) ;
if ( V_95 -> tmpfile )
V_60 = F_46 ( V_103 , V_99 , V_92 , true ) ;
else
V_60 = F_52 ( F_3 ( V_95 -> V_107 ) , V_103 , V_99 , V_92 , 0 ) ;
if ( ! V_60 )
* V_104 = F_53 ( V_95 -> tmpfile ? V_92 : V_103 ) ;
F_47 ( V_92 ) ;
return V_60 ;
}
static int F_54 ( struct V_94 * V_95 , struct V_5 * * V_108 )
{
int V_60 ;
struct V_5 * V_103 ;
const struct V_109 * V_110 = NULL ;
struct V_109 * V_111 = NULL ;
struct V_112 V_112 = {
. V_61 = V_95 -> V_48 . V_61 & V_113 ,
. V_114 = V_95 -> V_48 . V_114 ,
. V_115 = V_95 -> V_115
} ;
V_60 = F_55 ( V_95 -> V_5 , & V_111 ) ;
if ( V_60 < 0 )
goto V_26;
if ( V_111 )
V_110 = F_56 ( V_111 ) ;
if ( V_95 -> tmpfile ) {
V_103 = F_57 ( V_95 -> V_107 , V_95 -> V_48 . V_61 ) ;
if ( F_20 ( V_103 ) )
goto V_116;
} else {
V_103 = F_58 ( V_95 -> V_107 ) ;
if ( F_20 ( V_103 ) )
goto V_116;
V_60 = F_59 ( F_3 ( V_95 -> V_107 ) , V_103 , & V_112 ,
NULL , true ) ;
if ( V_60 ) {
F_47 ( V_103 ) ;
goto V_26;
}
}
V_60 = 0 ;
* V_108 = V_103 ;
V_26:
if ( V_111 ) {
F_60 ( V_110 ) ;
F_61 ( V_111 ) ;
}
return V_60 ;
V_116:
V_60 = F_21 ( V_103 ) ;
goto V_26;
}
static int F_62 ( struct V_94 * V_95 , struct V_5 * V_103 )
{
int V_60 ;
if ( F_63 ( V_95 -> V_48 . V_61 ) ) {
struct V_30 V_117 ;
F_64 ( V_95 -> V_5 , & V_117 ) ;
F_65 ( V_117 . V_5 != NULL ) ;
V_117 . V_5 = V_103 ;
V_60 = F_18 ( & V_95 -> V_118 , & V_117 , V_95 -> V_48 . V_14 ) ;
if ( V_60 )
return V_60 ;
}
V_60 = F_7 ( V_95 -> V_118 . V_5 , V_103 ) ;
if ( V_60 )
return V_60 ;
F_66 ( V_103 -> F_3 ) ;
V_60 = F_29 ( V_103 , & V_95 -> V_48 ) ;
F_49 ( V_103 -> F_3 ) ;
if ( V_60 )
return V_60 ;
if ( V_95 -> V_119 ) {
V_60 = F_37 ( V_95 -> V_5 , V_95 -> V_118 . V_5 , V_103 ) ;
if ( V_60 )
return V_60 ;
}
return 0 ;
}
static int F_67 ( struct V_94 * V_95 )
{
struct V_98 * V_99 = V_95 -> V_105 -> F_3 ;
struct V_5 * V_104 = NULL ;
struct V_5 * V_103 = NULL ;
int V_60 ;
V_60 = F_54 ( V_95 , & V_103 ) ;
if ( V_60 )
goto V_26;
V_60 = F_62 ( V_95 , V_103 ) ;
if ( V_60 )
goto V_120;
if ( V_95 -> tmpfile ) {
F_44 ( V_99 , V_100 ) ;
V_60 = F_51 ( V_95 , V_103 , & V_104 ) ;
F_49 ( V_99 ) ;
} else {
V_60 = F_51 ( V_95 , V_103 , & V_104 ) ;
}
if ( V_60 )
goto V_120;
F_68 ( F_3 ( V_95 -> V_5 ) , V_104 ) ;
V_26:
F_47 ( V_103 ) ;
return V_60 ;
V_120:
if ( ! V_95 -> tmpfile )
F_69 ( F_3 ( V_95 -> V_107 ) , V_103 ) ;
goto V_26;
}
static int F_70 ( struct V_94 * V_95 )
{
int V_60 ;
struct V_121 * V_122 = V_95 -> V_5 -> V_80 -> V_123 ;
bool V_124 = false ;
if ( F_71 ( V_95 -> V_5 -> V_80 ) && ! F_72 ( V_95 -> V_48 . V_61 ) &&
V_95 -> V_48 . V_125 > 1 )
V_124 = true ;
if ( F_72 ( V_95 -> V_48 . V_61 ) || V_95 -> V_48 . V_125 == 1 || V_124 )
V_95 -> V_119 = true ;
if ( V_124 ) {
V_95 -> V_105 = F_71 ( V_95 -> V_5 -> V_80 ) ;
V_60 = F_73 ( V_95 -> V_118 . V_5 , & V_95 -> V_106 ) ;
if ( V_60 )
return V_60 ;
} else {
V_60 = F_42 ( V_95 -> V_97 , V_95 -> V_105 ) ;
if ( V_60 )
return V_60 ;
}
if ( F_63 ( V_95 -> V_48 . V_61 ) && V_122 -> tmpfile ) {
V_95 -> tmpfile = true ;
V_60 = F_67 ( V_95 ) ;
} else {
V_60 = - V_27 ;
if ( F_74 ( V_95 -> V_107 , V_95 -> V_105 ) != NULL ) {
F_75 ( L_2 ) ;
} else {
V_60 = F_67 ( V_95 ) ;
F_76 ( V_95 -> V_107 , V_95 -> V_105 ) ;
}
}
if ( V_124 ) {
if ( ! V_60 )
F_77 ( V_126 , F_3 ( V_95 -> V_5 ) ) ;
F_17 ( V_95 -> V_106 . V_17 ) ;
} else if ( ! V_60 ) {
struct V_98 * V_99 = F_3 ( V_95 -> V_105 ) ;
F_66 ( V_99 ) ;
F_27 ( V_95 -> V_105 , & V_95 -> V_102 ) ;
F_49 ( V_99 ) ;
F_48 ( V_95 -> V_5 ) ;
}
return V_60 ;
}
static int F_78 ( struct V_5 * V_97 , struct V_5 * V_5 ,
int V_89 )
{
int V_60 ;
F_79 ( V_127 ) ;
struct V_30 V_128 ;
struct V_94 V_129 = {
. V_97 = V_97 ,
. V_5 = V_5 ,
. V_107 = F_80 ( V_5 ) ,
} ;
if ( F_11 ( ! V_129 . V_107 ) )
return - V_130 ;
F_81 ( V_5 , & V_129 . V_118 ) ;
V_60 = F_82 ( & V_129 . V_118 , & V_129 . V_48 ,
V_131 , V_132 ) ;
if ( V_60 )
return V_60 ;
F_64 ( V_97 , & V_128 ) ;
V_129 . V_105 = V_128 . V_5 ;
V_129 . V_106 = V_5 -> V_101 ;
V_60 = F_82 ( & V_128 , & V_129 . V_102 ,
V_133 | V_134 , V_132 ) ;
if ( V_60 )
return V_60 ;
if ( V_89 & V_135 )
V_129 . V_48 . V_14 = 0 ;
if ( F_30 ( V_129 . V_48 . V_61 ) ) {
V_129 . V_115 = F_83 ( V_129 . V_118 . V_5 , & V_127 ) ;
if ( F_20 ( V_129 . V_115 ) )
return F_21 ( V_129 . V_115 ) ;
}
F_5 ( V_129 . V_118 . V_5 ) ;
V_60 = F_84 ( V_5 ) ;
if ( F_85 ( V_60 ) ) {
if ( V_60 > 0 )
V_60 = 0 ;
} else {
if ( ! F_41 ( V_5 ) )
V_60 = F_70 ( & V_129 ) ;
if ( ! V_60 && ! F_86 ( V_5 ) )
V_60 = F_40 ( & V_129 ) ;
F_87 ( V_5 ) ;
}
F_88 ( & V_127 ) ;
return V_60 ;
}
int F_89 ( struct V_5 * V_5 , int V_89 )
{
int V_60 = 0 ;
const struct V_109 * V_136 = F_90 ( V_5 -> V_80 ) ;
while ( ! V_60 ) {
struct V_5 * V_137 ;
struct V_5 * V_97 ;
if ( F_41 ( V_5 ) &&
F_86 ( V_5 ) )
break;
V_137 = F_53 ( V_5 ) ;
for (; ; ) {
V_97 = F_91 ( V_137 ) ;
if ( F_41 ( V_97 ) )
break;
F_47 ( V_137 ) ;
V_137 = V_97 ;
}
V_60 = F_78 ( V_97 , V_137 , V_89 ) ;
F_47 ( V_97 ) ;
F_47 ( V_137 ) ;
}
F_60 ( V_136 ) ;
return V_60 ;
}
int F_92 ( struct V_5 * V_5 )
{
return F_89 ( V_5 , 0 ) ;
}
