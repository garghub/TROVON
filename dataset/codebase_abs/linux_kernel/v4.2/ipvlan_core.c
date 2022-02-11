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
struct V_22 * F_13 ( const struct V_23 * V_24 ,
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
bool V_69 , V_70 ;
F_38 ( & V_65 ) ;
F_39 ( & V_24 -> V_71 . V_72 ) ;
F_40 ( & V_24 -> V_71 , & V_65 ) ;
F_41 ( & V_24 -> V_71 . V_72 ) ;
while ( ( V_36 = F_42 ( & V_65 ) ) != NULL ) {
V_62 = F_43 ( V_36 ) ;
V_69 = F_44 ( V_62 -> V_73 , V_24 -> V_74 -> V_75 ) ;
V_66 = F_34 ( V_62 -> V_76 ) ;
if ( F_44 ( V_62 -> V_76 , V_24 -> V_74 -> V_77 ) )
V_68 = V_78 ;
else
V_68 = V_79 ;
V_70 = false ;
F_45 () ;
F_46 (ipvlan, &port->ipvlans, pnode) {
if ( V_69 && ( V_3 -> V_74 == V_36 -> V_74 ) ) {
V_70 = true ;
continue;
}
if ( ! F_47 ( V_66 , V_3 -> V_80 ) )
continue;
V_67 = V_81 ;
V_4 = V_36 -> V_4 + V_82 ;
V_63 = F_48 ( V_36 , V_83 ) ;
if ( ! V_63 )
goto V_84;
V_63 -> V_68 = V_68 ;
V_63 -> V_74 = V_3 -> V_74 ;
if ( V_69 )
V_67 = F_49 ( V_3 -> V_74 , V_63 ) ;
else
V_67 = F_50 ( V_63 ) ;
V_84:
F_3 ( V_3 , V_4 , V_67 == V_85 , true ) ;
}
F_51 () ;
if ( V_70 ) {
V_36 -> V_74 = V_24 -> V_74 ;
V_36 -> V_68 = V_68 ;
F_52 ( V_36 ) ;
} else {
F_53 ( V_36 ) ;
}
}
}
static int F_54 ( struct V_22 * V_26 , struct V_35 * V_36 ,
bool V_86 )
{
struct V_2 * V_3 = V_26 -> V_87 ;
struct V_88 * V_74 = V_3 -> V_74 ;
unsigned int V_4 ;
T_3 V_67 = V_89 ;
bool V_5 = false ;
V_4 = V_36 -> V_4 + V_82 ;
if ( F_27 ( ! ( V_74 -> V_90 & V_91 ) ) ) {
F_53 ( V_36 ) ;
goto V_92;
}
V_36 = F_55 ( V_36 , V_83 ) ;
if ( ! V_36 )
goto V_92;
V_36 -> V_74 = V_74 ;
V_36 -> V_68 = V_93 ;
if ( V_86 ) {
if ( F_49 ( V_3 -> V_74 , V_36 ) == V_85 )
V_5 = true ;
} else {
V_67 = V_94 ;
V_5 = true ;
}
V_92:
F_3 ( V_3 , V_4 , V_5 , false ) ;
return V_67 ;
}
static struct V_22 * F_56 ( struct V_23 * V_24 ,
void * V_37 , int V_95 ,
bool V_96 )
{
struct V_22 * V_26 = NULL ;
if ( V_95 == V_29 ) {
struct V_51 * V_52 ;
struct V_16 * V_97 ;
V_52 = (struct V_51 * ) V_37 ;
V_97 = V_96 ? & V_52 -> V_98 : & V_52 -> V_53 ;
V_26 = F_13 ( V_24 , V_97 , true ) ;
} else if ( V_95 == V_56 ) {
struct V_99 * V_100 ;
struct V_16 * V_97 ;
V_100 = (struct V_99 * ) V_37 ;
if ( V_100 -> V_101 . V_102 == V_103 ) {
V_97 = & V_100 -> V_104 ;
V_26 = F_13 ( V_24 , V_97 , true ) ;
}
} else if ( V_95 == V_31 ) {
struct V_45 * V_46 ;
T_4 * V_105 ;
V_46 = (struct V_45 * ) V_37 ;
V_105 = V_96 ? & V_46 -> V_98 : & V_46 -> V_53 ;
V_26 = F_13 ( V_24 , V_105 , false ) ;
} else if ( V_95 == V_42 ) {
struct V_40 * V_41 ;
unsigned char * V_106 ;
T_4 V_107 ;
V_41 = (struct V_40 * ) V_37 ;
V_106 = ( unsigned char * ) ( V_41 + 1 ) ;
if ( V_96 )
V_106 += ( 2 * V_24 -> V_74 -> V_108 ) + 4 ;
else
V_106 += V_24 -> V_74 -> V_108 ;
memcpy ( & V_107 , V_106 , 4 ) ;
V_26 = F_13 ( V_24 , & V_107 , false ) ;
}
return V_26 ;
}
static int F_57 ( struct V_35 * V_36 )
{
const struct V_45 * V_46 = F_30 ( V_36 ) ;
struct V_88 * V_74 = V_36 -> V_74 ;
struct V_109 * V_110 ;
int V_111 , V_67 = V_112 ;
struct V_113 V_114 = {
. V_115 = F_58 ( V_74 ) ,
. V_116 = F_59 ( V_46 -> V_117 ) ,
. V_118 = V_119 ,
. V_98 = V_46 -> V_98 ,
. V_53 = V_46 -> V_53 ,
} ;
V_110 = F_60 ( F_61 ( V_74 ) , & V_114 , NULL ) ;
if ( F_62 ( V_110 ) )
goto V_111;
if ( V_110 -> V_120 != V_121 && V_110 -> V_120 != V_122 ) {
F_63 ( V_110 ) ;
goto V_111;
}
F_64 ( V_36 ) ;
F_65 ( V_36 , & V_110 -> V_123 ) ;
V_111 = F_66 ( V_36 ) ;
if ( F_27 ( F_67 ( V_111 ) ) )
V_74 -> V_124 . V_125 ++ ;
else
V_67 = V_126 ;
goto V_92;
V_111:
V_74 -> V_124 . V_125 ++ ;
F_53 ( V_36 ) ;
V_92:
return V_67 ;
}
static int F_68 ( struct V_35 * V_36 )
{
const struct V_51 * V_52 = F_32 ( V_36 ) ;
struct V_88 * V_74 = V_36 -> V_74 ;
struct V_127 * V_123 ;
int V_111 , V_67 = V_112 ;
struct V_128 V_129 = {
. V_130 = V_36 -> V_74 -> V_131 ,
. V_98 = V_52 -> V_98 ,
. V_53 = V_52 -> V_53 ,
. V_132 = V_119 ,
. V_133 = F_69 ( V_52 ) ,
. V_134 = V_36 -> V_135 ,
. V_136 = V_52 -> V_54 ,
} ;
V_123 = F_70 ( F_61 ( V_74 ) , NULL , & V_129 ) ;
if ( V_123 -> error ) {
V_67 = V_123 -> error ;
F_71 ( V_123 ) ;
goto V_111;
}
F_64 ( V_36 ) ;
F_65 ( V_36 , V_123 ) ;
V_111 = F_72 ( V_36 ) ;
if ( F_27 ( F_67 ( V_111 ) ) )
V_74 -> V_124 . V_125 ++ ;
else
V_67 = V_126 ;
goto V_92;
V_111:
V_74 -> V_124 . V_125 ++ ;
F_53 ( V_36 ) ;
V_92:
return V_67 ;
}
static int F_73 ( struct V_35 * V_36 ,
const struct V_2 * V_3 )
{
struct V_61 * V_62 = F_43 ( V_36 ) ;
int V_67 = V_112 ;
if ( F_74 ( V_62 -> V_76 ) ) {
F_75 ( L_1 ,
F_31 ( V_36 -> V_38 ) ) ;
F_53 ( V_36 ) ;
goto V_92;
}
if ( F_76 ( V_36 ) ) {
F_77 ( V_36 , sizeof( * V_62 ) ) ;
V_36 -> V_137 = ( F_78 ( V_36 -> V_137 ) ) ~ 0U ;
F_79 ( V_36 ) ;
}
if ( V_36 -> V_38 == F_26 ( V_50 ) )
V_67 = F_68 ( V_36 ) ;
else if ( V_36 -> V_38 == F_26 ( V_43 ) )
V_67 = F_57 ( V_36 ) ;
else {
F_75 ( L_2 ,
F_31 ( V_36 -> V_38 ) ) ;
F_53 ( V_36 ) ;
}
V_92:
return V_67 ;
}
static void F_80 ( struct V_23 * V_24 ,
struct V_35 * V_36 )
{
if ( V_36 -> V_38 == F_26 ( V_138 ) ) {
F_53 ( V_36 ) ;
return;
}
F_81 ( & V_24 -> V_71 . V_72 ) ;
if ( F_82 ( & V_24 -> V_71 ) < V_139 ) {
F_83 ( & V_24 -> V_71 , V_36 ) ;
F_84 ( & V_24 -> V_71 . V_72 ) ;
F_85 ( & V_24 -> V_60 ) ;
} else {
F_84 ( & V_24 -> V_71 . V_72 ) ;
F_86 ( & V_36 -> V_74 -> V_140 ) ;
F_53 ( V_36 ) ;
}
}
static int F_87 ( struct V_35 * V_36 , struct V_88 * V_74 )
{
const struct V_2 * V_3 = F_88 ( V_74 ) ;
void * V_37 ;
struct V_22 * V_26 ;
int V_95 ;
V_37 = F_25 ( V_36 , & V_95 ) ;
if ( ! V_37 )
goto V_92;
V_26 = F_56 ( V_3 -> V_24 , V_37 , V_95 , true ) ;
if ( V_26 )
return F_54 ( V_26 , V_36 , true ) ;
V_92:
V_36 -> V_74 = V_3 -> V_141 ;
return F_73 ( V_36 , V_3 ) ;
}
static int F_89 ( struct V_35 * V_36 , struct V_88 * V_74 )
{
const struct V_2 * V_3 = F_88 ( V_74 ) ;
struct V_61 * V_142 = F_43 ( V_36 ) ;
struct V_22 * V_26 ;
void * V_37 ;
int V_95 ;
if ( F_44 ( V_142 -> V_76 , V_142 -> V_73 ) ) {
V_37 = F_25 ( V_36 , & V_95 ) ;
if ( V_37 ) {
V_26 = F_56 ( V_3 -> V_24 , V_37 , V_95 , true ) ;
if ( V_26 )
return F_54 ( V_26 , V_36 , true ) ;
}
V_36 = F_55 ( V_36 , V_83 ) ;
if ( ! V_36 )
return V_112 ;
return F_49 ( V_3 -> V_141 , V_36 ) ;
} else if ( F_74 ( V_142 -> V_76 ) ) {
F_80 ( V_3 -> V_24 , V_36 ) ;
return V_126 ;
}
V_36 -> V_74 = V_3 -> V_141 ;
return F_52 ( V_36 ) ;
}
int F_90 ( struct V_35 * V_36 , struct V_88 * V_74 )
{
struct V_2 * V_3 = F_88 ( V_74 ) ;
struct V_23 * V_24 = F_91 ( V_3 -> V_141 ) ;
if ( ! V_24 )
goto V_92;
if ( F_27 ( ! F_28 ( V_36 , sizeof( struct V_61 ) ) ) )
goto V_92;
switch( V_24 -> V_143 ) {
case V_144 :
return F_89 ( V_36 , V_74 ) ;
case V_145 :
return F_87 ( V_36 , V_74 ) ;
}
F_92 ( true , L_3 ,
V_24 -> V_143 ) ;
V_92:
F_53 ( V_36 ) ;
return V_112 ;
}
static bool F_93 ( struct V_35 * V_36 , struct V_23 * V_24 )
{
struct V_61 * V_142 = F_43 ( V_36 ) ;
struct V_22 * V_26 ;
void * V_37 ;
int V_95 ;
if ( F_44 ( V_142 -> V_73 , V_36 -> V_74 -> V_75 ) ) {
V_37 = F_25 ( V_36 , & V_95 ) ;
if ( ! V_37 )
return true ;
V_26 = F_56 ( V_24 , V_37 , V_95 , false ) ;
if ( V_26 )
return false ;
}
return true ;
}
static T_3 F_94 ( struct V_35 * * V_146 ,
struct V_23 * V_24 )
{
void * V_37 ;
int V_95 ;
struct V_22 * V_26 ;
struct V_35 * V_36 = * V_146 ;
T_3 V_67 = V_147 ;
V_37 = F_25 ( V_36 , & V_95 ) ;
if ( ! V_37 )
goto V_92;
V_26 = F_56 ( V_24 , V_37 , V_95 , true ) ;
if ( V_26 )
V_67 = F_54 ( V_26 , V_36 , false ) ;
V_92:
return V_67 ;
}
static T_3 F_95 ( struct V_35 * * V_146 ,
struct V_23 * V_24 )
{
struct V_35 * V_36 = * V_146 ;
struct V_61 * V_142 = F_43 ( V_36 ) ;
T_3 V_67 = V_147 ;
void * V_37 ;
int V_95 ;
if ( F_74 ( V_142 -> V_76 ) ) {
if ( F_93 ( V_36 , V_24 ) ) {
struct V_35 * V_63 = F_48 ( V_36 , V_83 ) ;
if ( V_63 )
F_80 ( V_24 , V_63 ) ;
}
} else {
struct V_22 * V_26 ;
V_37 = F_25 ( V_36 , & V_95 ) ;
if ( ! V_37 )
return V_67 ;
V_26 = F_56 ( V_24 , V_37 , V_95 , true ) ;
if ( V_26 )
V_67 = F_54 ( V_26 , V_36 , false ) ;
}
return V_67 ;
}
T_3 F_96 ( struct V_35 * * V_146 )
{
struct V_35 * V_36 = * V_146 ;
struct V_23 * V_24 = F_97 ( V_36 -> V_74 ) ;
if ( ! V_24 )
return V_147 ;
switch ( V_24 -> V_143 ) {
case V_144 :
return F_95 ( V_146 , V_24 ) ;
case V_145 :
return F_94 ( V_146 , V_24 ) ;
}
F_92 ( true , L_4 ,
V_24 -> V_143 ) ;
F_53 ( V_36 ) ;
return V_81 ;
}
