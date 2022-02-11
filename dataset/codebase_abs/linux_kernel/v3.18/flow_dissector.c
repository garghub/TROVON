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
case F_11 ( V_47 ) :
V_2 -> V_10 = ( V_33 ) ( V_18 + V_48 ) ;
default:
return false ;
}
switch ( V_11 ) {
case V_49 : {
struct V_50 {
T_3 V_51 ;
T_3 V_17 ;
} * V_42 , V_43 ;
V_42 = F_8 ( V_9 , V_18 , sizeof( V_43 ) , V_12 , V_13 , & V_43 ) ;
if ( ! V_42 )
return false ;
if ( ! ( V_42 -> V_51 & ( V_52 | V_53 ) ) ) {
V_17 = V_42 -> V_17 ;
V_18 += 4 ;
if ( V_42 -> V_51 & V_54 )
V_18 += 4 ;
if ( V_42 -> V_51 & V_55 )
V_18 += 4 ;
if ( V_42 -> V_51 & V_56 )
V_18 += 4 ;
if ( V_17 == F_11 ( V_57 ) ) {
const struct V_58 * V_59 ;
struct V_58 V_60 ;
V_59 = F_8 ( V_9 , V_18 ,
sizeof( V_60 ) ,
V_12 , V_13 , & V_60 ) ;
if ( ! V_59 )
return false ;
V_17 = V_59 -> V_61 ;
V_18 += sizeof( * V_59 ) ;
}
goto V_20;
}
break;
}
case V_62 :
V_17 = F_11 ( V_21 ) ;
goto V_23;
case V_63 :
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
F_16 ( & V_64 , sizeof( V_64 ) ) ;
}
static T_4 T_5 F_17 ( T_5 V_65 , T_5 V_66 , T_5 V_67 )
{
F_15 () ;
return F_18 ( V_65 , V_66 , V_67 , V_64 ) ;
}
static inline T_5 F_19 ( struct V_1 * V_68 )
{
T_5 V_69 ;
if ( ( ( V_30 T_5 ) V_68 -> V_5 < ( V_30 T_5 ) V_68 -> V_6 ) ||
( ( ( V_30 T_5 ) V_68 -> V_5 == ( V_30 T_5 ) V_68 -> V_6 ) &&
( ( V_30 V_33 ) V_68 -> V_70 [ 1 ] < ( V_30 V_33 ) V_68 -> V_70 [ 0 ] ) ) ) {
F_20 ( V_68 -> V_5 , V_68 -> V_6 ) ;
F_20 ( V_68 -> V_70 [ 0 ] , V_68 -> V_70 [ 1 ] ) ;
}
V_69 = F_17 ( ( V_30 T_5 ) V_68 -> V_5 ,
( V_30 T_5 ) V_68 -> V_6 ,
( V_30 T_5 ) V_68 -> V_15 ) ;
if ( ! V_69 )
V_69 = 1 ;
return V_69 ;
}
T_5 F_21 ( struct V_1 * V_68 )
{
return F_19 ( V_68 ) ;
}
void F_22 ( struct V_8 * V_9 )
{
struct V_1 V_68 ;
if ( ! F_23 ( V_9 , & V_68 ) )
return;
if ( V_68 . V_15 )
V_9 -> V_71 = 1 ;
V_9 -> V_72 = 1 ;
V_9 -> V_69 = F_19 ( & V_68 ) ;
}
V_33 F_24 ( const struct V_73 * V_74 , struct V_8 * V_9 ,
unsigned int V_75 )
{
T_5 V_69 ;
V_33 V_76 = 0 ;
V_33 V_77 = V_75 ;
if ( F_25 ( V_9 ) ) {
V_69 = F_26 ( V_9 ) ;
while ( F_27 ( V_69 >= V_75 ) )
V_69 -= V_75 ;
return V_69 ;
}
if ( V_74 -> V_78 ) {
T_2 V_79 = F_28 ( V_74 , V_9 -> V_80 ) ;
V_76 = V_74 -> V_81 [ V_79 ] . V_82 ;
V_77 = V_74 -> V_81 [ V_79 ] . V_83 ;
}
return ( V_33 ) F_29 ( F_30 ( V_9 ) , V_77 ) + V_76 ;
}
T_5 F_31 ( const struct V_8 * V_9 , void * V_12 ,
const struct V_1 * V_68 , int V_13 )
{
T_5 V_14 = V_68 -> V_10 ;
switch ( V_68 -> V_11 ) {
case V_84 : {
const T_2 * V_85 ;
T_2 V_86 ;
V_85 = F_8 ( V_9 , V_14 + 12 , sizeof( V_86 ) ,
V_12 , V_13 , & V_86 ) ;
if ( ! V_85 )
return V_14 ;
V_14 += F_32 ( T_5 , sizeof( struct V_87 ) , ( * V_85 & 0xF0 ) >> 2 ) ;
break;
}
case V_88 :
case V_89 :
V_14 += sizeof( struct V_90 ) ;
break;
case V_91 :
V_14 += sizeof( struct V_92 ) ;
break;
case V_93 :
V_14 += sizeof( struct V_94 ) ;
break;
case V_95 :
V_14 += sizeof( struct V_96 ) ;
break;
case V_97 :
V_14 += sizeof( struct V_98 ) ;
break;
case V_99 :
V_14 += sizeof( struct V_100 ) ;
break;
}
return V_14 ;
}
T_5 F_33 ( const struct V_8 * V_9 )
{
struct V_1 V_68 ;
if ( ! F_23 ( V_9 , & V_68 ) )
return 0 ;
return F_31 ( V_9 , V_9 -> V_12 , & V_68 , F_7 ( V_9 ) ) ;
}
static inline int F_34 ( struct V_73 * V_74 , struct V_8 * V_9 )
{
#ifdef F_35
struct V_101 * V_102 ;
struct V_103 * V_104 ;
int V_105 = - 1 ;
F_36 () ;
V_102 = F_37 ( V_74 -> V_106 ) ;
if ( V_102 ) {
V_104 = F_37 (
V_102 -> V_107 [ F_38 () ] ) ;
if ( V_104 ) {
if ( V_104 -> V_108 == 1 )
V_105 = V_104 -> V_109 [ 0 ] ;
else
V_105 = V_104 -> V_109 [ F_29 ( F_30 ( V_9 ) ,
V_104 -> V_108 ) ] ;
if ( F_27 ( V_105 >= V_74 -> V_110 ) )
V_105 = - 1 ;
}
}
F_39 () ;
return V_105 ;
#else
return - 1 ;
#endif
}
static V_33 F_40 ( struct V_73 * V_74 , struct V_8 * V_9 )
{
struct V_111 * V_112 = V_9 -> V_112 ;
int V_105 = F_41 ( V_112 ) ;
if ( V_105 < 0 || V_9 -> V_113 ||
V_105 >= V_74 -> V_110 ) {
int V_114 = F_34 ( V_74 , V_9 ) ;
if ( V_114 < 0 )
V_114 = F_42 ( V_74 , V_9 ) ;
if ( V_105 != V_114 && V_112 &&
F_43 ( V_112 -> V_115 ) )
F_44 ( V_112 , V_114 ) ;
V_105 = V_114 ;
}
return V_105 ;
}
struct V_116 * F_45 ( struct V_73 * V_74 ,
struct V_8 * V_9 ,
void * V_117 )
{
int V_105 = 0 ;
if ( V_74 -> V_110 != 1 ) {
const struct V_118 * V_119 = V_74 -> V_120 ;
if ( V_119 -> V_121 )
V_105 = V_119 -> V_121 ( V_74 , V_9 , V_117 ,
F_40 ) ;
else
V_105 = F_40 ( V_74 , V_9 ) ;
if ( ! V_117 )
V_105 = F_46 ( V_74 , V_105 ) ;
}
F_47 ( V_9 , V_105 ) ;
return F_48 ( V_74 , V_105 ) ;
}
