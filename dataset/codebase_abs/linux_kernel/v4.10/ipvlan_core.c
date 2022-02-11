void F_1 ( void )
{
F_2 ( & V_1 , sizeof( V_1 ) ) ;
}
static void F_3 ( const struct V_2 * V_3 ,
unsigned int V_4 , bool V_5 , bool V_6 )
{
if ( ! V_3 )
return;
if ( F_4 ( V_5 ) ) {
struct V_7 * V_8 ;
V_8 = F_5 ( V_3 -> V_9 ) ;
F_6 ( & V_8 -> V_10 ) ;
V_8 -> V_11 ++ ;
V_8 -> V_12 += V_4 ;
if ( V_6 )
V_8 -> V_13 ++ ;
F_7 ( & V_8 -> V_10 ) ;
} else {
F_8 ( V_3 -> V_9 -> V_14 ) ;
}
}
static T_1 F_9 ( const void * V_15 )
{
const struct V_16 * V_17 = V_15 ;
return F_10 ( V_17 , V_1 ) &
V_18 ;
}
static T_1 F_11 ( const void * V_15 )
{
const struct V_19 * V_20 = V_15 ;
return F_12 ( V_20 -> V_21 , V_1 ) &
V_18 ;
}
static struct V_22 * F_13 ( const struct V_23 * V_24 ,
const void * V_15 , bool V_25 )
{
struct V_22 * V_26 ;
T_1 V_27 ;
V_27 = V_25 ? F_9 ( V_15 ) :
F_11 ( V_15 ) ;
F_14 (addr, &port->hlhead[hash], hlnode) {
if ( V_25 && V_26 -> V_28 == V_29 &&
F_15 ( & V_26 -> V_30 , V_15 ) )
return V_26 ;
else if ( ! V_25 && V_26 -> V_28 == V_31 &&
V_26 -> V_32 . V_21 ==
( (struct V_19 * ) V_15 ) -> V_21 )
return V_26 ;
}
return NULL ;
}
void F_16 ( struct V_2 * V_3 , struct V_22 * V_26 )
{
struct V_23 * V_24 = V_3 -> V_24 ;
T_1 V_27 ;
V_27 = ( V_26 -> V_28 == V_29 ) ?
F_9 ( & V_26 -> V_30 ) :
F_11 ( & V_26 -> V_32 ) ;
if ( F_17 ( & V_26 -> V_33 ) )
F_18 ( & V_26 -> V_33 , & V_24 -> V_34 [ V_27 ] ) ;
}
void F_19 ( struct V_22 * V_26 )
{
F_20 ( & V_26 -> V_33 ) ;
}
struct V_22 * F_21 ( const struct V_2 * V_3 ,
const void * V_15 , bool V_25 )
{
struct V_22 * V_26 ;
F_22 (addr, &ipvlan->addrs, anode) {
if ( ( V_25 && V_26 -> V_28 == V_29 &&
F_15 ( & V_26 -> V_30 , V_15 ) ) ||
( ! V_25 && V_26 -> V_28 == V_31 &&
V_26 -> V_32 . V_21 == ( (struct V_19 * ) V_15 ) -> V_21 ) )
return V_26 ;
}
return NULL ;
}
bool F_23 ( struct V_23 * V_24 , void * V_15 , bool V_25 )
{
struct V_2 * V_3 ;
F_24 () ;
F_22 (ipvlan, &port->ipvlans, pnode) {
if ( F_21 ( V_3 , V_15 , V_25 ) )
return true ;
}
return false ;
}
static void * F_25 ( struct V_35 * V_36 , int * type )
{
void * V_37 = NULL ;
switch ( V_36 -> V_38 ) {
case F_26 ( V_39 ) : {
struct V_40 * V_41 ;
if ( F_27 ( ! F_28 ( V_36 , sizeof( * V_41 ) ) ) )
return NULL ;
V_41 = F_29 ( V_36 ) ;
* type = V_42 ;
V_37 = V_41 ;
break;
}
case F_26 ( V_43 ) : {
T_2 V_44 ;
struct V_45 * V_46 ;
if ( F_27 ( ! F_28 ( V_36 , sizeof( * V_46 ) ) ) )
return NULL ;
V_46 = F_30 ( V_36 ) ;
V_44 = F_31 ( V_46 -> V_47 ) ;
if ( V_46 -> V_48 < 5 || V_46 -> V_49 != 4 )
return NULL ;
if ( V_36 -> V_4 < V_44 || V_44 < ( V_46 -> V_48 * 4 ) )
return NULL ;
* type = V_31 ;
V_37 = V_46 ;
break;
}
case F_26 ( V_50 ) : {
struct V_51 * V_52 ;
if ( F_27 ( ! F_28 ( V_36 , sizeof( * V_52 ) ) ) )
return NULL ;
V_52 = F_32 ( V_36 ) ;
if ( V_52 -> V_49 != 6 )
return NULL ;
* type = V_29 ;
V_37 = V_52 ;
if ( F_33 ( & V_52 -> V_53 ) &&
V_52 -> V_54 == V_55 ) {
* type = V_56 ;
V_37 = V_52 + 1 ;
}
break;
}
default:
return NULL ;
}
return V_37 ;
}
unsigned int F_34 ( const unsigned char * V_26 )
{
T_2 V_27 = F_12 ( F_35 ( V_26 + 2 ) ,
V_1 ) ;
return V_27 & V_57 ;
}
void F_36 ( struct V_58 * V_59 )
{
struct V_23 * V_24 = F_37 ( V_59 , struct V_23 , V_60 ) ;
struct V_61 * V_62 ;
struct V_2 * V_3 ;
struct V_35 * V_36 , * V_63 ;
struct V_64 V_65 ;
unsigned int V_4 ;
unsigned int V_66 ;
int V_67 ;
T_1 V_68 ;
bool V_69 ;
F_38 ( & V_65 ) ;
F_39 ( & V_24 -> V_70 . V_71 ) ;
F_40 ( & V_24 -> V_70 , & V_65 ) ;
F_41 ( & V_24 -> V_70 . V_71 ) ;
while ( ( V_36 = F_42 ( & V_65 ) ) != NULL ) {
struct V_72 * V_73 = V_36 -> V_73 ;
bool V_74 = false ;
V_62 = F_43 ( V_36 ) ;
V_69 = F_44 ( V_36 ) -> V_69 ;
V_66 = F_34 ( V_62 -> V_75 ) ;
if ( F_45 ( V_62 -> V_75 , V_24 -> V_73 -> V_76 ) )
V_68 = V_77 ;
else
V_68 = V_78 ;
F_46 () ;
F_47 (ipvlan, &port->ipvlans, pnode) {
if ( V_69 && ( V_3 -> V_73 == V_36 -> V_73 ) )
continue;
if ( ! F_48 ( V_66 , V_3 -> V_79 ) )
continue;
if ( ! ( V_3 -> V_73 -> V_80 & V_81 ) )
continue;
V_67 = V_82 ;
V_4 = V_36 -> V_4 + V_83 ;
V_63 = F_49 ( V_36 , V_84 ) ;
F_50 () ;
if ( V_63 ) {
V_74 = true ;
V_63 -> V_68 = V_68 ;
V_63 -> V_73 = V_3 -> V_73 ;
if ( V_69 )
V_67 = F_51 ( V_3 -> V_73 , V_63 ) ;
else
V_67 = F_52 ( V_63 ) ;
}
F_3 ( V_3 , V_4 , V_67 == V_85 , true ) ;
F_53 () ;
}
F_54 () ;
if ( V_69 ) {
V_36 -> V_73 = V_24 -> V_73 ;
V_36 -> V_68 = V_68 ;
F_55 ( V_36 ) ;
} else {
if ( V_74 )
F_56 ( V_36 ) ;
else
F_57 ( V_36 ) ;
}
if ( V_73 )
F_58 ( V_73 ) ;
}
}
static void F_59 ( struct V_35 * V_36 , struct V_72 * V_73 )
{
bool V_86 = true ;
if ( V_73 )
V_86 = ! F_60 ( F_61 ( V_36 -> V_73 ) , F_61 ( V_73 ) ) ;
F_62 ( V_36 , V_86 ) ;
if ( V_73 )
V_36 -> V_73 = V_73 ;
}
static int F_63 ( struct V_22 * V_26 , struct V_35 * * V_87 ,
bool V_88 )
{
struct V_2 * V_3 = V_26 -> V_89 ;
struct V_72 * V_73 = V_3 -> V_73 ;
unsigned int V_4 ;
T_3 V_67 = V_90 ;
bool V_5 = false ;
struct V_35 * V_36 = * V_87 ;
V_4 = V_36 -> V_4 + V_83 ;
if ( V_88 ) {
if ( F_27 ( ! ( V_73 -> V_80 & V_81 ) ) ) {
F_57 ( V_36 ) ;
goto V_91;
}
V_36 = F_64 ( V_36 , V_84 ) ;
if ( ! V_36 )
goto V_91;
* V_87 = V_36 ;
}
F_59 ( V_36 , V_73 ) ;
if ( V_88 ) {
V_36 -> V_68 = V_92 ;
if ( F_51 ( V_3 -> V_73 , V_36 ) == V_85 )
V_5 = true ;
} else {
V_67 = V_93 ;
V_5 = true ;
}
V_91:
F_3 ( V_3 , V_4 , V_5 , false ) ;
return V_67 ;
}
static struct V_22 * F_65 ( struct V_23 * V_24 ,
void * V_37 , int V_94 ,
bool V_95 )
{
struct V_22 * V_26 = NULL ;
if ( V_94 == V_29 ) {
struct V_51 * V_52 ;
struct V_16 * V_96 ;
V_52 = (struct V_51 * ) V_37 ;
V_96 = V_95 ? & V_52 -> V_97 : & V_52 -> V_53 ;
V_26 = F_13 ( V_24 , V_96 , true ) ;
} else if ( V_94 == V_56 ) {
struct V_98 * V_99 ;
struct V_16 * V_96 ;
V_99 = (struct V_98 * ) V_37 ;
if ( V_99 -> V_100 . V_101 == V_102 ) {
V_96 = & V_99 -> V_103 ;
V_26 = F_13 ( V_24 , V_96 , true ) ;
}
} else if ( V_94 == V_31 ) {
struct V_45 * V_46 ;
T_4 * V_104 ;
V_46 = (struct V_45 * ) V_37 ;
V_104 = V_95 ? & V_46 -> V_97 : & V_46 -> V_53 ;
V_26 = F_13 ( V_24 , V_104 , false ) ;
} else if ( V_94 == V_42 ) {
struct V_40 * V_41 ;
unsigned char * V_105 ;
T_4 V_106 ;
V_41 = (struct V_40 * ) V_37 ;
V_105 = ( unsigned char * ) ( V_41 + 1 ) ;
if ( V_95 )
V_105 += ( 2 * V_24 -> V_73 -> V_107 ) + 4 ;
else
V_105 += V_24 -> V_73 -> V_107 ;
memcpy ( & V_106 , V_105 , 4 ) ;
V_26 = F_13 ( V_24 , & V_106 , false ) ;
}
return V_26 ;
}
static int F_66 ( struct V_35 * V_36 )
{
const struct V_45 * V_46 = F_30 ( V_36 ) ;
struct V_72 * V_73 = V_36 -> V_73 ;
struct V_108 * V_108 = F_61 ( V_73 ) ;
struct V_109 * V_110 ;
int V_111 , V_67 = V_112 ;
struct V_113 V_114 = {
. V_115 = V_73 -> V_116 ,
. V_117 = F_67 ( V_46 -> V_118 ) ,
. V_119 = V_120 ,
. V_97 = V_46 -> V_97 ,
. V_53 = V_46 -> V_53 ,
} ;
V_110 = F_68 ( V_108 , & V_114 , NULL ) ;
if ( F_69 ( V_110 ) )
goto V_111;
if ( V_110 -> V_121 != V_122 && V_110 -> V_121 != V_123 ) {
F_70 ( V_110 ) ;
goto V_111;
}
F_71 ( V_36 , & V_110 -> V_124 ) ;
V_111 = F_72 ( V_108 , V_36 -> V_125 , V_36 ) ;
if ( F_27 ( F_73 ( V_111 ) ) )
V_73 -> V_126 . V_127 ++ ;
else
V_67 = V_128 ;
goto V_91;
V_111:
V_73 -> V_126 . V_127 ++ ;
F_57 ( V_36 ) ;
V_91:
return V_67 ;
}
static int F_74 ( struct V_35 * V_36 )
{
const struct V_51 * V_52 = F_32 ( V_36 ) ;
struct V_72 * V_73 = V_36 -> V_73 ;
struct V_108 * V_108 = F_61 ( V_73 ) ;
struct V_129 * V_124 ;
int V_111 , V_67 = V_112 ;
struct V_130 V_131 = {
. V_132 = V_73 -> V_116 ,
. V_97 = V_52 -> V_97 ,
. V_53 = V_52 -> V_53 ,
. V_133 = V_120 ,
. V_134 = F_75 ( V_52 ) ,
. V_135 = V_36 -> V_136 ,
. V_137 = V_52 -> V_54 ,
} ;
V_124 = F_76 ( V_108 , NULL , & V_131 ) ;
if ( V_124 -> error ) {
V_67 = V_124 -> error ;
F_77 ( V_124 ) ;
goto V_111;
}
F_71 ( V_36 , V_124 ) ;
V_111 = F_78 ( V_108 , V_36 -> V_125 , V_36 ) ;
if ( F_27 ( F_73 ( V_111 ) ) )
V_73 -> V_126 . V_127 ++ ;
else
V_67 = V_128 ;
goto V_91;
V_111:
V_73 -> V_126 . V_127 ++ ;
F_57 ( V_36 ) ;
V_91:
return V_67 ;
}
static int F_79 ( struct V_35 * V_36 )
{
struct V_61 * V_62 = F_43 ( V_36 ) ;
int V_67 = V_112 ;
if ( F_80 ( V_62 -> V_75 ) ) {
F_81 ( L_1 ,
F_31 ( V_36 -> V_38 ) ) ;
F_57 ( V_36 ) ;
goto V_91;
}
if ( F_82 ( V_36 ) ) {
F_83 ( V_36 , sizeof( * V_62 ) ) ;
V_36 -> V_138 = ( F_84 ( V_36 -> V_138 ) ) ~ 0U ;
F_85 ( V_36 ) ;
}
if ( V_36 -> V_38 == F_26 ( V_50 ) )
V_67 = F_74 ( V_36 ) ;
else if ( V_36 -> V_38 == F_26 ( V_43 ) )
V_67 = F_66 ( V_36 ) ;
else {
F_81 ( L_2 ,
F_31 ( V_36 -> V_38 ) ) ;
F_57 ( V_36 ) ;
}
V_91:
return V_67 ;
}
static void F_86 ( struct V_23 * V_24 ,
struct V_35 * V_36 , bool V_69 )
{
if ( V_36 -> V_38 == F_26 ( V_139 ) ) {
F_57 ( V_36 ) ;
return;
}
F_44 ( V_36 ) -> V_69 = V_69 ;
F_87 ( & V_24 -> V_70 . V_71 ) ;
if ( F_88 ( & V_24 -> V_70 ) < V_140 ) {
if ( V_36 -> V_73 )
F_89 ( V_36 -> V_73 ) ;
F_90 ( & V_24 -> V_70 , V_36 ) ;
F_91 ( & V_24 -> V_70 . V_71 ) ;
F_92 ( & V_24 -> V_60 ) ;
} else {
F_91 ( & V_24 -> V_70 . V_71 ) ;
F_93 ( & V_36 -> V_73 -> V_141 ) ;
F_57 ( V_36 ) ;
}
}
static int F_94 ( struct V_35 * V_36 , struct V_72 * V_73 )
{
const struct V_2 * V_3 = F_95 ( V_73 ) ;
void * V_37 ;
struct V_22 * V_26 ;
int V_94 ;
V_37 = F_25 ( V_36 , & V_94 ) ;
if ( ! V_37 )
goto V_91;
V_26 = F_65 ( V_3 -> V_24 , V_37 , V_94 , true ) ;
if ( V_26 )
return F_63 ( V_26 , & V_36 , true ) ;
V_91:
F_59 ( V_36 , V_3 -> V_142 ) ;
return F_79 ( V_36 ) ;
}
static int F_96 ( struct V_35 * V_36 , struct V_72 * V_73 )
{
const struct V_2 * V_3 = F_95 ( V_73 ) ;
struct V_61 * V_143 = F_43 ( V_36 ) ;
struct V_22 * V_26 ;
void * V_37 ;
int V_94 ;
if ( F_45 ( V_143 -> V_75 , V_143 -> V_144 ) ) {
V_37 = F_25 ( V_36 , & V_94 ) ;
if ( V_37 ) {
V_26 = F_65 ( V_3 -> V_24 , V_37 , V_94 , true ) ;
if ( V_26 )
return F_63 ( V_26 , & V_36 , true ) ;
}
V_36 = F_64 ( V_36 , V_84 ) ;
if ( ! V_36 )
return V_112 ;
return F_51 ( V_3 -> V_142 , V_36 ) ;
} else if ( F_80 ( V_143 -> V_75 ) ) {
F_59 ( V_36 , NULL ) ;
F_86 ( V_3 -> V_24 , V_36 , true ) ;
return V_128 ;
}
F_59 ( V_36 , V_3 -> V_142 ) ;
return F_55 ( V_36 ) ;
}
int F_97 ( struct V_35 * V_36 , struct V_72 * V_73 )
{
struct V_2 * V_3 = F_95 ( V_73 ) ;
struct V_23 * V_24 = F_98 ( V_3 -> V_142 ) ;
if ( ! V_24 )
goto V_91;
if ( F_27 ( ! F_28 ( V_36 , sizeof( struct V_61 ) ) ) )
goto V_91;
switch( V_24 -> V_145 ) {
case V_146 :
return F_96 ( V_36 , V_73 ) ;
case V_147 :
case V_148 :
return F_94 ( V_36 , V_73 ) ;
}
F_99 ( true , L_3 ,
V_24 -> V_145 ) ;
V_91:
F_57 ( V_36 ) ;
return V_112 ;
}
static bool F_100 ( struct V_35 * V_36 , struct V_23 * V_24 )
{
struct V_61 * V_143 = F_43 ( V_36 ) ;
struct V_22 * V_26 ;
void * V_37 ;
int V_94 ;
if ( F_45 ( V_143 -> V_144 , V_36 -> V_73 -> V_149 ) ) {
V_37 = F_25 ( V_36 , & V_94 ) ;
if ( ! V_37 )
return true ;
V_26 = F_65 ( V_24 , V_37 , V_94 , false ) ;
if ( V_26 )
return false ;
}
return true ;
}
static T_3 F_101 ( struct V_35 * * V_87 ,
struct V_23 * V_24 )
{
void * V_37 ;
int V_94 ;
struct V_22 * V_26 ;
struct V_35 * V_36 = * V_87 ;
T_3 V_67 = V_150 ;
V_37 = F_25 ( V_36 , & V_94 ) ;
if ( ! V_37 )
goto V_91;
V_26 = F_65 ( V_24 , V_37 , V_94 , true ) ;
if ( V_26 )
V_67 = F_63 ( V_26 , V_87 , false ) ;
V_91:
return V_67 ;
}
static T_3 F_102 ( struct V_35 * * V_87 ,
struct V_23 * V_24 )
{
struct V_35 * V_36 = * V_87 ;
struct V_61 * V_143 = F_43 ( V_36 ) ;
T_3 V_67 = V_150 ;
void * V_37 ;
int V_94 ;
if ( F_80 ( V_143 -> V_75 ) ) {
if ( F_100 ( V_36 , V_24 ) ) {
struct V_35 * V_63 = F_49 ( V_36 , V_84 ) ;
if ( V_63 ) {
F_59 ( V_63 , NULL ) ;
F_86 ( V_24 , V_63 , false ) ;
}
}
} else {
struct V_22 * V_26 ;
V_37 = F_25 ( V_36 , & V_94 ) ;
if ( ! V_37 )
return V_67 ;
V_26 = F_65 ( V_24 , V_37 , V_94 , true ) ;
if ( V_26 )
V_67 = F_63 ( V_26 , V_87 , false ) ;
}
return V_67 ;
}
T_3 F_103 ( struct V_35 * * V_87 )
{
struct V_35 * V_36 = * V_87 ;
struct V_23 * V_24 = F_104 ( V_36 -> V_73 ) ;
if ( ! V_24 )
return V_150 ;
switch ( V_24 -> V_145 ) {
case V_146 :
return F_102 ( V_87 , V_24 ) ;
case V_147 :
return F_101 ( V_87 , V_24 ) ;
case V_148 :
return V_150 ;
}
F_99 ( true , L_4 ,
V_24 -> V_145 ) ;
F_57 ( V_36 ) ;
return V_90 ;
}
static struct V_22 * F_105 ( struct V_35 * V_36 ,
struct V_72 * V_73 )
{
struct V_22 * V_26 = NULL ;
struct V_23 * V_24 ;
void * V_37 ;
int V_94 ;
if ( ! V_73 || ! F_106 ( V_73 ) )
goto V_91;
V_24 = F_104 ( V_73 ) ;
if ( ! V_24 || V_24 -> V_145 != V_148 )
goto V_91;
V_37 = F_25 ( V_36 , & V_94 ) ;
if ( ! V_37 )
goto V_91;
V_26 = F_65 ( V_24 , V_37 , V_94 , true ) ;
V_91:
return V_26 ;
}
struct V_35 * F_107 ( struct V_72 * V_73 , struct V_35 * V_36 ,
T_5 V_151 )
{
struct V_22 * V_26 ;
struct V_72 * V_152 ;
V_26 = F_105 ( V_36 , V_73 ) ;
if ( ! V_26 )
goto V_91;
V_152 = V_26 -> V_89 -> V_73 ;
switch ( V_151 ) {
case V_153 :
{
int V_111 ;
struct V_45 * V_46 = F_30 ( V_36 ) ;
V_111 = F_108 ( V_36 , V_46 -> V_97 , V_46 -> V_53 ,
V_46 -> V_118 , V_152 ) ;
if ( F_27 ( V_111 ) )
goto V_91;
break;
}
case V_154 :
{
struct V_129 * V_124 ;
struct V_51 * V_52 = F_32 ( V_36 ) ;
int V_80 = V_155 ;
struct V_130 V_131 = {
. V_132 = V_152 -> V_116 ,
. V_97 = V_52 -> V_97 ,
. V_53 = V_52 -> V_53 ,
. V_134 = F_75 ( V_52 ) ,
. V_135 = V_36 -> V_136 ,
. V_137 = V_52 -> V_54 ,
} ;
F_109 ( V_36 ) ;
V_124 = F_110 ( F_61 ( V_152 ) , V_152 , & V_131 , V_80 ) ;
F_71 ( V_36 , V_124 ) ;
break;
}
default:
break;
}
V_91:
return V_36 ;
}
unsigned int F_111 ( void * V_156 , struct V_35 * V_36 ,
const struct V_157 * V_158 )
{
struct V_22 * V_26 ;
unsigned int V_4 ;
V_26 = F_105 ( V_36 , V_36 -> V_73 ) ;
if ( ! V_26 )
goto V_91;
V_36 -> V_73 = V_26 -> V_89 -> V_73 ;
V_4 = V_36 -> V_4 + V_83 ;
F_3 ( V_26 -> V_89 , V_4 , true , false ) ;
V_91:
return V_159 ;
}
