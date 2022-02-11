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
F_17 ( & V_26 -> V_33 , & V_24 -> V_34 [ V_27 ] ) ;
}
void F_18 ( struct V_22 * V_26 , bool V_35 )
{
F_19 ( & V_26 -> V_33 ) ;
if ( V_35 )
F_20 () ;
}
bool F_21 ( struct V_2 * V_3 , void * V_15 , bool V_25 )
{
struct V_23 * V_24 = V_3 -> V_24 ;
struct V_22 * V_26 ;
F_22 (addr, &ipvlan->addrs, anode) {
if ( ( V_25 && V_26 -> V_28 == V_29 &&
F_15 ( & V_26 -> V_30 , V_15 ) ) ||
( ! V_25 && V_26 -> V_28 == V_31 &&
V_26 -> V_32 . V_21 == ( (struct V_19 * ) V_15 ) -> V_21 ) )
return true ;
}
if ( F_13 ( V_24 , V_15 , V_25 ) )
return true ;
return false ;
}
static void * F_23 ( struct V_36 * V_37 , int * type )
{
void * V_38 = NULL ;
switch ( V_37 -> V_39 ) {
case F_24 ( V_40 ) : {
struct V_41 * V_42 ;
if ( F_25 ( ! F_26 ( V_37 , sizeof( * V_42 ) ) ) )
return NULL ;
V_42 = F_27 ( V_37 ) ;
* type = V_43 ;
V_38 = V_42 ;
break;
}
case F_24 ( V_44 ) : {
T_2 V_45 ;
struct V_46 * V_47 ;
if ( F_25 ( ! F_26 ( V_37 , sizeof( * V_47 ) ) ) )
return NULL ;
V_47 = F_28 ( V_37 ) ;
V_45 = F_29 ( V_47 -> V_48 ) ;
if ( V_47 -> V_49 < 5 || V_47 -> V_50 != 4 )
return NULL ;
if ( V_37 -> V_4 < V_45 || V_45 < ( V_47 -> V_49 * 4 ) )
return NULL ;
* type = V_31 ;
V_38 = V_47 ;
break;
}
case F_24 ( V_51 ) : {
struct V_52 * V_53 ;
if ( F_25 ( ! F_26 ( V_37 , sizeof( * V_53 ) ) ) )
return NULL ;
V_53 = F_30 ( V_37 ) ;
if ( V_53 -> V_50 != 6 )
return NULL ;
* type = V_29 ;
V_38 = V_53 ;
if ( F_31 ( & V_53 -> V_54 ) &&
V_53 -> V_55 == V_56 ) {
* type = V_57 ;
V_38 = V_53 + 1 ;
}
break;
}
default:
return NULL ;
}
return V_38 ;
}
unsigned int F_32 ( const unsigned char * V_26 )
{
T_2 V_27 = F_12 ( F_33 ( V_26 + 2 ) ,
V_1 ) ;
return V_27 & V_58 ;
}
static void F_34 ( struct V_23 * V_24 , struct V_36 * V_37 ,
const struct V_2 * V_59 , bool V_60 )
{
struct V_61 * V_62 = F_35 ( V_37 ) ;
struct V_2 * V_3 ;
struct V_36 * V_63 ;
unsigned int V_4 ;
unsigned int V_64 ;
int V_65 ;
if ( V_37 -> V_39 == F_24 ( V_66 ) )
return;
F_22 (ipvlan, &port->ipvlans, pnode) {
if ( V_60 && ( V_3 == V_59 ) )
continue;
V_64 = F_32 ( V_62 -> V_67 ) ;
if ( ! F_36 ( V_64 , V_3 -> V_68 ) )
continue;
V_65 = V_69 ;
V_4 = V_37 -> V_4 + V_70 ;
V_63 = F_37 ( V_37 , V_71 ) ;
if ( ! V_63 )
goto V_72;
if ( F_38 ( V_62 -> V_67 , V_3 -> V_73 -> V_74 ) )
V_63 -> V_75 = V_76 ;
else
V_63 -> V_75 = V_77 ;
V_63 -> V_78 = V_3 -> V_78 ;
if ( V_60 )
V_65 = F_39 ( V_3 -> V_78 , V_63 ) ;
else
V_65 = F_40 ( V_63 ) ;
V_72:
F_3 ( V_3 , V_4 , V_65 == V_79 , true ) ;
}
if ( V_60 ) {
V_63 = F_37 ( V_37 , V_71 ) ;
if ( V_63 ) {
if ( F_38 ( V_62 -> V_67 , V_24 -> V_78 -> V_74 ) )
V_63 -> V_75 = V_76 ;
else
V_63 -> V_75 = V_77 ;
F_39 ( V_24 -> V_78 , V_63 ) ;
}
}
}
static int F_41 ( struct V_22 * V_26 , struct V_36 * V_37 ,
bool V_60 )
{
struct V_2 * V_3 = V_26 -> V_80 ;
struct V_81 * V_78 = V_3 -> V_78 ;
unsigned int V_4 ;
T_3 V_65 = V_82 ;
bool V_5 = false ;
V_4 = V_37 -> V_4 + V_70 ;
if ( F_25 ( ! ( V_78 -> V_83 & V_84 ) ) ) {
F_42 ( V_37 ) ;
goto V_85;
}
V_37 = F_43 ( V_37 , V_71 ) ;
if ( ! V_37 )
goto V_85;
V_37 -> V_78 = V_78 ;
V_37 -> V_75 = V_86 ;
if ( V_60 ) {
if ( F_39 ( V_3 -> V_78 , V_37 ) == V_79 )
V_5 = true ;
} else {
V_65 = V_87 ;
V_5 = true ;
}
V_85:
F_3 ( V_3 , V_4 , V_5 , false ) ;
return V_65 ;
}
static struct V_22 * F_44 ( struct V_23 * V_24 ,
void * V_38 , int V_88 ,
bool V_89 )
{
struct V_22 * V_26 = NULL ;
if ( V_88 == V_29 ) {
struct V_52 * V_53 ;
struct V_16 * V_90 ;
V_53 = (struct V_52 * ) V_38 ;
V_90 = V_89 ? & V_53 -> V_91 : & V_53 -> V_54 ;
V_26 = F_13 ( V_24 , V_90 , true ) ;
} else if ( V_88 == V_57 ) {
struct V_92 * V_93 ;
struct V_16 * V_90 ;
V_93 = (struct V_92 * ) V_38 ;
if ( V_93 -> V_94 . V_95 == V_96 ) {
V_90 = & V_93 -> V_97 ;
V_26 = F_13 ( V_24 , V_90 , true ) ;
}
} else if ( V_88 == V_31 ) {
struct V_46 * V_47 ;
T_4 * V_98 ;
V_47 = (struct V_46 * ) V_38 ;
V_98 = V_89 ? & V_47 -> V_91 : & V_47 -> V_54 ;
V_26 = F_13 ( V_24 , V_98 , false ) ;
} else if ( V_88 == V_43 ) {
struct V_41 * V_42 ;
unsigned char * V_99 ;
T_4 V_100 ;
V_42 = (struct V_41 * ) V_38 ;
V_99 = ( unsigned char * ) ( V_42 + 1 ) ;
if ( V_89 )
V_99 += ( 2 * V_24 -> V_78 -> V_101 ) + 4 ;
else
V_99 += V_24 -> V_78 -> V_101 ;
memcpy ( & V_100 , V_99 , 4 ) ;
V_26 = F_13 ( V_24 , & V_100 , false ) ;
}
return V_26 ;
}
static int F_45 ( struct V_36 * V_37 )
{
const struct V_46 * V_47 = F_28 ( V_37 ) ;
struct V_81 * V_78 = V_37 -> V_78 ;
struct V_102 * V_103 ;
int V_104 , V_65 = V_105 ;
struct V_106 V_107 = {
. V_108 = V_78 -> V_109 ,
. V_110 = F_46 ( V_47 -> V_111 ) ,
. V_112 = V_113 ,
. V_91 = V_47 -> V_91 ,
. V_54 = V_47 -> V_54 ,
} ;
V_103 = F_47 ( F_48 ( V_78 ) , & V_107 , NULL ) ;
if ( F_49 ( V_103 ) )
goto V_104;
if ( V_103 -> V_114 != V_115 && V_103 -> V_114 != V_116 ) {
F_50 ( V_103 ) ;
goto V_104;
}
F_51 ( V_37 ) ;
F_52 ( V_37 , & V_103 -> V_117 ) ;
V_104 = F_53 ( V_37 ) ;
if ( F_25 ( F_54 ( V_104 ) ) )
V_78 -> V_118 . V_119 ++ ;
else
V_65 = V_120 ;
goto V_85;
V_104:
V_78 -> V_118 . V_119 ++ ;
F_42 ( V_37 ) ;
V_85:
return V_65 ;
}
static int F_55 ( struct V_36 * V_37 )
{
const struct V_52 * V_53 = F_30 ( V_37 ) ;
struct V_81 * V_78 = V_37 -> V_78 ;
struct V_121 * V_117 ;
int V_104 , V_65 = V_105 ;
struct V_122 V_123 = {
. V_124 = V_37 -> V_78 -> V_125 ,
. V_91 = V_53 -> V_91 ,
. V_54 = V_53 -> V_54 ,
. V_126 = V_113 ,
. V_127 = F_56 ( V_53 ) ,
. V_128 = V_37 -> V_129 ,
. V_130 = V_53 -> V_55 ,
} ;
V_117 = F_57 ( F_48 ( V_78 ) , NULL , & V_123 ) ;
if ( V_117 -> error ) {
V_65 = V_117 -> error ;
F_58 ( V_117 ) ;
goto V_104;
}
F_51 ( V_37 ) ;
F_52 ( V_37 , V_117 ) ;
V_104 = F_59 ( V_37 ) ;
if ( F_25 ( F_54 ( V_104 ) ) )
V_78 -> V_118 . V_119 ++ ;
else
V_65 = V_120 ;
goto V_85;
V_104:
V_78 -> V_118 . V_119 ++ ;
F_42 ( V_37 ) ;
V_85:
return V_65 ;
}
static int F_60 ( struct V_36 * V_37 ,
const struct V_2 * V_3 )
{
struct V_61 * V_131 = F_35 ( V_37 ) ;
int V_65 = V_105 ;
if ( F_61 ( V_131 -> V_67 ) ) {
F_62 ( L_1 ,
F_29 ( V_37 -> V_39 ) ) ;
F_42 ( V_37 ) ;
goto V_85;
}
if ( F_63 ( V_37 ) ) {
F_64 ( V_37 , sizeof( * V_131 ) ) ;
V_37 -> V_132 = ( F_65 ( V_37 -> V_132 ) ) ~ 0U ;
F_66 ( V_37 ) ;
}
if ( V_37 -> V_39 == F_24 ( V_51 ) )
V_65 = F_55 ( V_37 ) ;
else if ( V_37 -> V_39 == F_24 ( V_44 ) )
V_65 = F_45 ( V_37 ) ;
else {
F_62 ( L_2 ,
F_29 ( V_37 -> V_39 ) ) ;
F_42 ( V_37 ) ;
}
V_85:
return V_65 ;
}
static int F_67 ( struct V_36 * V_37 , struct V_81 * V_78 )
{
const struct V_2 * V_3 = F_68 ( V_78 ) ;
void * V_38 ;
struct V_22 * V_26 ;
int V_88 ;
V_38 = F_23 ( V_37 , & V_88 ) ;
if ( ! V_38 )
goto V_85;
V_26 = F_44 ( V_3 -> V_24 , V_38 , V_88 , true ) ;
if ( V_26 )
return F_41 ( V_26 , V_37 , true ) ;
V_85:
V_37 -> V_78 = V_3 -> V_73 ;
return F_60 ( V_37 , V_3 ) ;
}
static int F_69 ( struct V_36 * V_37 , struct V_81 * V_78 )
{
const struct V_2 * V_3 = F_68 ( V_78 ) ;
struct V_61 * V_62 = F_35 ( V_37 ) ;
struct V_22 * V_26 ;
void * V_38 ;
int V_88 ;
if ( F_38 ( V_62 -> V_67 , V_62 -> V_133 ) ) {
V_38 = F_23 ( V_37 , & V_88 ) ;
if ( V_38 ) {
V_26 = F_44 ( V_3 -> V_24 , V_38 , V_88 , true ) ;
if ( V_26 )
return F_41 ( V_26 , V_37 , true ) ;
}
V_37 = F_43 ( V_37 , V_71 ) ;
if ( ! V_37 )
return V_105 ;
return F_39 ( V_3 -> V_73 , V_37 ) ;
} else if ( F_61 ( V_62 -> V_67 ) ) {
T_1 V_134 = V_37 -> V_134 ;
V_37 -> V_134 = V_135 ;
F_34 ( V_3 -> V_24 , V_37 , V_3 , true ) ;
V_37 -> V_134 = V_134 ;
}
V_37 -> V_78 = V_3 -> V_73 ;
return F_70 ( V_37 ) ;
}
int F_71 ( struct V_36 * V_37 , struct V_81 * V_78 )
{
struct V_2 * V_3 = F_68 ( V_78 ) ;
struct V_23 * V_24 = F_72 ( V_3 -> V_73 ) ;
if ( ! V_24 )
goto V_85;
if ( F_25 ( ! F_26 ( V_37 , sizeof( struct V_61 ) ) ) )
goto V_85;
switch( V_24 -> V_136 ) {
case V_137 :
return F_69 ( V_37 , V_78 ) ;
case V_138 :
return F_67 ( V_37 , V_78 ) ;
}
F_73 ( true , L_3 ,
V_24 -> V_136 ) ;
V_85:
F_42 ( V_37 ) ;
return V_105 ;
}
static bool F_74 ( struct V_36 * V_37 , struct V_23 * V_24 )
{
struct V_61 * V_62 = F_35 ( V_37 ) ;
struct V_22 * V_26 ;
void * V_38 ;
int V_88 ;
if ( F_38 ( V_62 -> V_133 , V_37 -> V_78 -> V_139 ) ) {
V_38 = F_23 ( V_37 , & V_88 ) ;
if ( ! V_38 )
return true ;
V_26 = F_44 ( V_24 , V_38 , V_88 , false ) ;
if ( V_26 )
return false ;
}
return true ;
}
static T_3 F_75 ( struct V_36 * * V_140 ,
struct V_23 * V_24 )
{
void * V_38 ;
int V_88 ;
struct V_22 * V_26 ;
struct V_36 * V_37 = * V_140 ;
T_3 V_65 = V_141 ;
V_38 = F_23 ( V_37 , & V_88 ) ;
if ( ! V_38 )
goto V_85;
V_26 = F_44 ( V_24 , V_38 , V_88 , true ) ;
if ( V_26 )
V_65 = F_41 ( V_26 , V_37 , false ) ;
V_85:
return V_65 ;
}
static T_3 F_76 ( struct V_36 * * V_140 ,
struct V_23 * V_24 )
{
struct V_36 * V_37 = * V_140 ;
struct V_61 * V_62 = F_35 ( V_37 ) ;
T_3 V_65 = V_141 ;
void * V_38 ;
int V_88 ;
if ( F_61 ( V_62 -> V_67 ) ) {
if ( F_74 ( V_37 , V_24 ) )
F_34 ( V_24 , V_37 , NULL , false ) ;
} else {
struct V_22 * V_26 ;
V_38 = F_23 ( V_37 , & V_88 ) ;
if ( ! V_38 )
return V_65 ;
V_26 = F_44 ( V_24 , V_38 , V_88 , true ) ;
if ( V_26 )
V_65 = F_41 ( V_26 , V_37 , false ) ;
}
return V_65 ;
}
T_3 F_77 ( struct V_36 * * V_140 )
{
struct V_36 * V_37 = * V_140 ;
struct V_23 * V_24 = F_72 ( V_37 -> V_78 ) ;
if ( ! V_24 )
return V_141 ;
switch ( V_24 -> V_136 ) {
case V_137 :
return F_76 ( V_140 , V_24 ) ;
case V_138 :
return F_75 ( V_140 , V_24 ) ;
}
F_73 ( true , L_4 ,
V_24 -> V_136 ) ;
F_42 ( V_37 ) ;
return V_69 ;
}
