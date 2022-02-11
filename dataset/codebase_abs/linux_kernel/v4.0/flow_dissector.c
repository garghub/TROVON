static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
F_2 ( F_3 ( F_4 ( * V_2 ) , V_5 ) !=
F_3 ( F_4 ( * V_2 ) , V_6 ) + sizeof( V_2 -> V_6 ) ) ;
memcpy ( & V_2 -> V_6 , & V_4 -> V_7 , sizeof( V_2 -> V_6 ) + sizeof( V_2 -> V_5 ) ) ;
}
T_1 F_5 ( const struct V_8 * V_9 , int V_10 , T_2 V_11 ,
void * V_12 , int V_13 )
{
int V_14 = F_6 ( V_11 ) ;
if ( ! V_12 ) {
V_12 = V_9 -> V_12 ;
V_13 = F_7 ( V_9 ) ;
}
if ( V_14 >= 0 ) {
T_1 * V_15 , V_16 ;
V_15 = F_8 ( V_9 , V_10 + V_14 ,
sizeof( V_16 ) , V_12 , V_13 , & V_16 ) ;
if ( V_15 )
return * V_15 ;
}
return 0 ;
}
bool F_9 ( const struct V_8 * V_9 , struct V_1 * V_2 ,
void * V_12 , T_3 V_17 , int V_18 , int V_13 )
{
T_2 V_11 ;
if ( ! V_12 ) {
V_12 = V_9 -> V_12 ;
V_17 = V_9 -> V_19 ;
V_18 = F_10 ( V_9 ) ;
V_13 = F_7 ( V_9 ) ;
}
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_20:
switch ( V_17 ) {
case F_11 ( V_21 ) : {
const struct V_3 * V_4 ;
struct V_3 V_22 ;
V_23:
V_4 = F_8 ( V_9 , V_18 , sizeof( V_22 ) , V_12 , V_13 , & V_22 ) ;
if ( ! V_4 || V_4 -> V_24 < 5 )
return false ;
V_18 += V_4 -> V_24 * 4 ;
V_11 = V_4 -> V_19 ;
if ( F_12 ( V_4 ) )
V_11 = 0 ;
if ( ! V_9 )
break;
F_1 ( V_2 , V_4 ) ;
break;
}
case F_11 ( V_25 ) : {
const struct V_26 * V_4 ;
struct V_26 V_22 ;
T_1 V_27 ;
V_28:
V_4 = F_8 ( V_9 , V_18 , sizeof( V_22 ) , V_12 , V_13 , & V_22 ) ;
if ( ! V_4 )
return false ;
V_11 = V_4 -> V_29 ;
V_18 += sizeof( struct V_26 ) ;
if ( ! V_9 )
break;
V_2 -> V_6 = ( V_30 T_1 ) F_13 ( & V_4 -> V_7 ) ;
V_2 -> V_5 = ( V_30 T_1 ) F_13 ( & V_4 -> V_31 ) ;
V_27 = F_14 ( V_4 ) ;
if ( V_27 ) {
V_2 -> V_32 = V_17 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_15 = V_27 ;
V_2 -> V_10 = ( V_33 ) V_18 ;
return true ;
}
break;
}
case F_11 ( V_34 ) :
case F_11 ( V_35 ) : {
const struct V_36 * V_37 ;
struct V_36 V_38 ;
V_37 = F_8 ( V_9 , V_18 , sizeof( V_38 ) , V_12 , V_13 , & V_38 ) ;
if ( ! V_37 )
return false ;
V_17 = V_37 -> V_39 ;
V_18 += sizeof( * V_37 ) ;
goto V_20;
}
case F_11 ( V_40 ) : {
struct {
struct V_41 V_42 ;
T_3 V_17 ;
} * V_42 , V_43 ;
V_42 = F_8 ( V_9 , V_18 , sizeof( V_43 ) , V_12 , V_13 , & V_43 ) ;
if ( ! V_42 )
return false ;
V_17 = V_42 -> V_17 ;
V_18 += V_44 ;
switch ( V_17 ) {
case F_11 ( V_45 ) :
goto V_23;
case F_11 ( V_46 ) :
goto V_28;
default:
return false ;
}
}
case F_11 ( V_47 ) : {
struct {
T_1 V_48 [ 3 ] ;
T_1 V_49 ;
} * V_42 , V_43 ;
V_42 = F_8 ( V_9 , V_18 , sizeof( V_43 ) , V_12 , V_13 , & V_43 ) ;
if ( ! V_42 )
return false ;
V_2 -> V_6 = V_42 -> V_49 ;
V_2 -> V_5 = 0 ;
V_2 -> V_32 = V_17 ;
V_2 -> V_10 = ( V_33 ) V_18 ;
return true ;
}
case F_11 ( V_50 ) :
V_2 -> V_10 = ( V_33 ) ( V_18 + V_51 ) ;
default:
return false ;
}
switch ( V_11 ) {
case V_52 : {
struct V_53 {
T_3 V_54 ;
T_3 V_17 ;
} * V_42 , V_43 ;
V_42 = F_8 ( V_9 , V_18 , sizeof( V_43 ) , V_12 , V_13 , & V_43 ) ;
if ( ! V_42 )
return false ;
if ( ! ( V_42 -> V_54 & ( V_55 | V_56 ) ) ) {
V_17 = V_42 -> V_17 ;
V_18 += 4 ;
if ( V_42 -> V_54 & V_57 )
V_18 += 4 ;
if ( V_42 -> V_54 & V_58 )
V_18 += 4 ;
if ( V_42 -> V_54 & V_59 )
V_18 += 4 ;
if ( V_17 == F_11 ( V_60 ) ) {
const struct V_61 * V_62 ;
struct V_61 V_63 ;
V_62 = F_8 ( V_9 , V_18 ,
sizeof( V_63 ) ,
V_12 , V_13 , & V_63 ) ;
if ( ! V_62 )
return false ;
V_17 = V_62 -> V_64 ;
V_18 += sizeof( * V_62 ) ;
}
goto V_20;
}
break;
}
case V_65 :
V_17 = F_11 ( V_21 ) ;
goto V_23;
case V_66 :
V_17 = F_11 ( V_25 ) ;
goto V_28;
default:
break;
}
V_2 -> V_32 = V_17 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_10 = ( V_33 ) V_18 ;
if ( V_9 )
V_2 -> V_15 = F_5 ( V_9 , V_18 , V_11 ,
V_12 , V_13 ) ;
return true ;
}
static T_4 void F_15 ( void )
{
F_16 ( & V_67 , sizeof( V_67 ) ) ;
}
static T_4 T_5 F_17 ( T_5 V_68 , T_5 V_69 , T_5 V_70 )
{
F_15 () ;
return F_18 ( V_68 , V_69 , V_70 , V_67 ) ;
}
static inline T_5 F_19 ( struct V_1 * V_71 )
{
T_5 V_72 ;
if ( ( ( V_30 T_5 ) V_71 -> V_5 < ( V_30 T_5 ) V_71 -> V_6 ) ||
( ( ( V_30 T_5 ) V_71 -> V_5 == ( V_30 T_5 ) V_71 -> V_6 ) &&
( ( V_30 V_33 ) V_71 -> V_73 [ 1 ] < ( V_30 V_33 ) V_71 -> V_73 [ 0 ] ) ) ) {
F_20 ( V_71 -> V_5 , V_71 -> V_6 ) ;
F_20 ( V_71 -> V_73 [ 0 ] , V_71 -> V_73 [ 1 ] ) ;
}
V_72 = F_17 ( ( V_30 T_5 ) V_71 -> V_5 ,
( V_30 T_5 ) V_71 -> V_6 ,
( V_30 T_5 ) V_71 -> V_15 ) ;
if ( ! V_72 )
V_72 = 1 ;
return V_72 ;
}
T_5 F_21 ( struct V_1 * V_71 )
{
return F_19 ( V_71 ) ;
}
void F_22 ( struct V_8 * V_9 )
{
struct V_1 V_71 ;
if ( ! F_23 ( V_9 , & V_71 ) )
return;
if ( V_71 . V_15 )
V_9 -> V_74 = 1 ;
V_9 -> V_75 = 1 ;
V_9 -> V_72 = F_19 ( & V_71 ) ;
}
V_33 F_24 ( const struct V_76 * V_77 , struct V_8 * V_9 ,
unsigned int V_78 )
{
T_5 V_72 ;
V_33 V_79 = 0 ;
V_33 V_80 = V_78 ;
if ( F_25 ( V_9 ) ) {
V_72 = F_26 ( V_9 ) ;
while ( F_27 ( V_72 >= V_78 ) )
V_72 -= V_78 ;
return V_72 ;
}
if ( V_77 -> V_81 ) {
T_2 V_82 = F_28 ( V_77 , V_9 -> V_83 ) ;
V_79 = V_77 -> V_84 [ V_82 ] . V_85 ;
V_80 = V_77 -> V_84 [ V_82 ] . V_86 ;
}
return ( V_33 ) F_29 ( F_30 ( V_9 ) , V_80 ) + V_79 ;
}
T_5 F_31 ( const struct V_8 * V_9 , void * V_12 ,
const struct V_1 * V_71 , int V_13 )
{
T_5 V_14 = V_71 -> V_10 ;
switch ( V_71 -> V_11 ) {
case V_87 : {
const T_2 * V_88 ;
T_2 V_89 ;
V_88 = F_8 ( V_9 , V_14 + 12 , sizeof( V_89 ) ,
V_12 , V_13 , & V_89 ) ;
if ( ! V_88 )
return V_14 ;
V_14 += F_32 ( T_5 , sizeof( struct V_90 ) , ( * V_88 & 0xF0 ) >> 2 ) ;
break;
}
case V_91 :
case V_92 :
V_14 += sizeof( struct V_93 ) ;
break;
case V_94 :
V_14 += sizeof( struct V_95 ) ;
break;
case V_96 :
V_14 += sizeof( struct V_97 ) ;
break;
case V_98 :
V_14 += sizeof( struct V_99 ) ;
break;
case V_100 :
V_14 += sizeof( struct V_101 ) ;
break;
case V_102 :
V_14 += sizeof( struct V_103 ) ;
break;
}
return V_14 ;
}
T_5 F_33 ( const struct V_8 * V_9 )
{
struct V_1 V_71 ;
if ( ! F_23 ( V_9 , & V_71 ) )
return 0 ;
return F_31 ( V_9 , V_9 -> V_12 , & V_71 , F_7 ( V_9 ) ) ;
}
static inline int F_34 ( struct V_76 * V_77 , struct V_8 * V_9 )
{
#ifdef F_35
struct V_104 * V_105 ;
struct V_106 * V_107 ;
int V_108 = - 1 ;
F_36 () ;
V_105 = F_37 ( V_77 -> V_109 ) ;
if ( V_105 ) {
V_107 = F_37 (
V_105 -> V_110 [ V_9 -> V_111 - 1 ] ) ;
if ( V_107 ) {
if ( V_107 -> V_112 == 1 )
V_108 = V_107 -> V_113 [ 0 ] ;
else
V_108 = V_107 -> V_113 [ F_29 ( F_30 ( V_9 ) ,
V_107 -> V_112 ) ] ;
if ( F_27 ( V_108 >= V_77 -> V_114 ) )
V_108 = - 1 ;
}
}
F_38 () ;
return V_108 ;
#else
return - 1 ;
#endif
}
static V_33 F_39 ( struct V_76 * V_77 , struct V_8 * V_9 )
{
struct V_115 * V_116 = V_9 -> V_116 ;
int V_108 = F_40 ( V_116 ) ;
if ( V_108 < 0 || V_9 -> V_117 ||
V_108 >= V_77 -> V_114 ) {
int V_118 = F_34 ( V_77 , V_9 ) ;
if ( V_118 < 0 )
V_118 = F_41 ( V_77 , V_9 ) ;
if ( V_108 != V_118 && V_116 &&
F_42 ( V_116 -> V_119 ) )
F_43 ( V_116 , V_118 ) ;
V_108 = V_118 ;
}
return V_108 ;
}
struct V_120 * F_44 ( struct V_76 * V_77 ,
struct V_8 * V_9 ,
void * V_121 )
{
int V_108 = 0 ;
#ifdef F_35
if ( V_9 -> V_111 == 0 )
V_9 -> V_111 = F_45 () + 1 ;
#endif
if ( V_77 -> V_114 != 1 ) {
const struct V_122 * V_123 = V_77 -> V_124 ;
if ( V_123 -> V_125 )
V_108 = V_123 -> V_125 ( V_77 , V_9 , V_121 ,
F_39 ) ;
else
V_108 = F_39 ( V_77 , V_9 ) ;
if ( ! V_121 )
V_108 = F_46 ( V_77 , V_108 ) ;
}
F_47 ( V_9 , V_108 ) ;
return F_48 ( V_77 , V_108 ) ;
}
