static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
F_2 ( F_3 ( F_4 ( * V_2 ) , V_5 ) !=
F_3 ( F_4 ( * V_2 ) , V_6 ) + sizeof( V_2 -> V_6 ) ) ;
memcpy ( & V_2 -> V_6 , & V_4 -> V_7 , sizeof( V_2 -> V_6 ) + sizeof( V_2 -> V_5 ) ) ;
}
T_1 F_5 ( const struct V_8 * V_9 , int V_10 , T_2 V_11 )
{
int V_12 = F_6 ( V_11 ) ;
if ( V_12 >= 0 ) {
T_1 * V_13 , V_14 ;
V_13 = F_7 ( V_9 , V_10 + V_12 ,
sizeof( V_14 ) , & V_14 ) ;
if ( V_13 )
return * V_13 ;
}
return 0 ;
}
bool F_8 ( const struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_15 = F_9 ( V_9 ) ;
T_2 V_11 ;
T_3 V_16 = V_9 -> V_17 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_18:
switch ( V_16 ) {
case F_10 ( V_19 ) : {
const struct V_3 * V_4 ;
struct V_3 V_20 ;
V_21:
V_4 = F_7 ( V_9 , V_15 , sizeof( V_20 ) , & V_20 ) ;
if ( ! V_4 || V_4 -> V_22 < 5 )
return false ;
V_15 += V_4 -> V_22 * 4 ;
V_11 = V_4 -> V_17 ;
if ( F_11 ( V_4 ) )
V_11 = 0 ;
F_1 ( V_2 , V_4 ) ;
break;
}
case F_10 ( V_23 ) : {
const struct V_24 * V_4 ;
struct V_24 V_20 ;
T_1 V_25 ;
V_26:
V_4 = F_7 ( V_9 , V_15 , sizeof( V_20 ) , & V_20 ) ;
if ( ! V_4 )
return false ;
V_11 = V_4 -> V_27 ;
V_2 -> V_6 = ( V_28 T_1 ) F_12 ( & V_4 -> V_7 ) ;
V_2 -> V_5 = ( V_28 T_1 ) F_12 ( & V_4 -> V_29 ) ;
V_15 += sizeof( struct V_24 ) ;
V_25 = F_13 ( V_4 ) ;
if ( V_25 ) {
V_2 -> V_30 = V_16 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_13 = V_25 ;
V_2 -> V_10 = ( V_31 ) V_15 ;
return true ;
}
break;
}
case F_10 ( V_32 ) :
case F_10 ( V_33 ) : {
const struct V_34 * V_35 ;
struct V_34 V_36 ;
V_35 = F_7 ( V_9 , V_15 , sizeof( V_36 ) , & V_36 ) ;
if ( ! V_35 )
return false ;
V_16 = V_35 -> V_37 ;
V_15 += sizeof( * V_35 ) ;
goto V_18;
}
case F_10 ( V_38 ) : {
struct {
struct V_39 V_40 ;
T_3 V_16 ;
} * V_40 , V_41 ;
V_40 = F_7 ( V_9 , V_15 , sizeof( V_41 ) , & V_41 ) ;
if ( ! V_40 )
return false ;
V_16 = V_40 -> V_16 ;
V_15 += V_42 ;
switch ( V_16 ) {
case F_10 ( V_43 ) :
goto V_21;
case F_10 ( V_44 ) :
goto V_26;
default:
return false ;
}
}
default:
return false ;
}
switch ( V_11 ) {
case V_45 : {
struct V_46 {
T_3 V_47 ;
T_3 V_16 ;
} * V_40 , V_41 ;
V_40 = F_7 ( V_9 , V_15 , sizeof( V_41 ) , & V_41 ) ;
if ( ! V_40 )
return false ;
if ( ! ( V_40 -> V_47 & ( V_48 | V_49 ) ) ) {
V_16 = V_40 -> V_16 ;
V_15 += 4 ;
if ( V_40 -> V_47 & V_50 )
V_15 += 4 ;
if ( V_40 -> V_47 & V_51 )
V_15 += 4 ;
if ( V_40 -> V_47 & V_52 )
V_15 += 4 ;
if ( V_16 == F_10 ( V_53 ) ) {
const struct V_54 * V_55 ;
struct V_54 V_56 ;
V_55 = F_7 ( V_9 , V_15 ,
sizeof( V_56 ) , & V_56 ) ;
if ( ! V_55 )
return false ;
V_16 = V_55 -> V_57 ;
V_15 += sizeof( * V_55 ) ;
}
goto V_18;
}
break;
}
case V_58 :
V_16 = F_10 ( V_19 ) ;
goto V_21;
case V_59 :
V_16 = F_10 ( V_23 ) ;
goto V_26;
default:
break;
}
V_2 -> V_30 = V_16 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_13 = F_5 ( V_9 , V_15 , V_11 ) ;
V_2 -> V_10 = ( V_31 ) V_15 ;
return true ;
}
static T_4 void F_14 ( void )
{
F_15 ( & V_60 , sizeof( V_60 ) ) ;
}
static T_4 T_5 F_16 ( T_5 V_61 , T_5 V_62 , T_5 V_63 )
{
F_14 () ;
return F_17 ( V_61 , V_62 , V_63 , V_60 ) ;
}
static inline T_5 F_18 ( struct V_1 * V_64 )
{
T_5 V_65 ;
if ( ( ( V_28 T_5 ) V_64 -> V_5 < ( V_28 T_5 ) V_64 -> V_6 ) ||
( ( ( V_28 T_5 ) V_64 -> V_5 == ( V_28 T_5 ) V_64 -> V_6 ) &&
( ( V_28 V_31 ) V_64 -> V_66 [ 1 ] < ( V_28 V_31 ) V_64 -> V_66 [ 0 ] ) ) ) {
F_19 ( V_64 -> V_5 , V_64 -> V_6 ) ;
F_19 ( V_64 -> V_66 [ 0 ] , V_64 -> V_66 [ 1 ] ) ;
}
V_65 = F_16 ( ( V_28 T_5 ) V_64 -> V_5 ,
( V_28 T_5 ) V_64 -> V_6 ,
( V_28 T_5 ) V_64 -> V_13 ) ;
if ( ! V_65 )
V_65 = 1 ;
return V_65 ;
}
T_5 F_20 ( struct V_1 * V_64 )
{
return F_18 ( V_64 ) ;
}
void F_21 ( struct V_8 * V_9 )
{
struct V_1 V_64 ;
if ( ! F_8 ( V_9 , & V_64 ) )
return;
if ( V_64 . V_13 )
V_9 -> V_67 = 1 ;
V_9 -> V_68 = 1 ;
V_9 -> V_65 = F_18 ( & V_64 ) ;
}
V_31 F_22 ( const struct V_69 * V_70 , struct V_8 * V_9 ,
unsigned int V_71 )
{
T_5 V_65 ;
V_31 V_72 = 0 ;
V_31 V_73 = V_71 ;
if ( F_23 ( V_9 ) ) {
V_65 = F_24 ( V_9 ) ;
while ( F_25 ( V_65 >= V_71 ) )
V_65 -= V_71 ;
return V_65 ;
}
if ( V_70 -> V_74 ) {
T_2 V_75 = F_26 ( V_70 , V_9 -> V_76 ) ;
V_72 = V_70 -> V_77 [ V_75 ] . V_78 ;
V_73 = V_70 -> V_77 [ V_75 ] . V_79 ;
}
return ( V_31 ) ( ( ( V_80 ) F_27 ( V_9 ) * V_73 ) >> 32 ) + V_72 ;
}
T_5 F_28 ( const struct V_8 * V_9 )
{
struct V_1 V_64 ;
T_5 V_12 = 0 ;
if ( ! F_8 ( V_9 , & V_64 ) )
return 0 ;
V_12 += V_64 . V_10 ;
switch ( V_64 . V_11 ) {
case V_81 : {
const struct V_82 * V_83 ;
struct V_82 V_84 ;
V_83 = F_7 ( V_9 , V_12 , sizeof( V_84 ) , & V_84 ) ;
if ( ! V_83 )
return V_12 ;
V_12 += F_29 ( T_5 , sizeof( struct V_82 ) , V_83 -> V_85 * 4 ) ;
break;
}
case V_86 :
case V_87 :
V_12 += sizeof( struct V_88 ) ;
break;
case V_89 :
V_12 += sizeof( struct V_90 ) ;
break;
case V_91 :
V_12 += sizeof( struct V_92 ) ;
break;
case V_93 :
V_12 += sizeof( struct V_94 ) ;
break;
case V_95 :
V_12 += sizeof( struct V_96 ) ;
break;
case V_97 :
V_12 += sizeof( struct V_98 ) ;
break;
}
return V_12 ;
}
static inline int F_30 ( struct V_69 * V_70 , struct V_8 * V_9 )
{
#ifdef F_31
struct V_99 * V_100 ;
struct V_101 * V_102 ;
int V_103 = - 1 ;
F_32 () ;
V_100 = F_33 ( V_70 -> V_104 ) ;
if ( V_100 ) {
V_102 = F_33 (
V_100 -> V_105 [ F_34 () ] ) ;
if ( V_102 ) {
if ( V_102 -> V_106 == 1 )
V_103 = V_102 -> V_107 [ 0 ] ;
else
V_103 = V_102 -> V_107 [
( ( V_80 ) F_27 ( V_9 ) * V_102 -> V_106 ) >> 32 ] ;
if ( F_25 ( V_103 >= V_70 -> V_108 ) )
V_103 = - 1 ;
}
}
F_35 () ;
return V_103 ;
#else
return - 1 ;
#endif
}
static V_31 F_36 ( struct V_69 * V_70 , struct V_8 * V_9 )
{
struct V_109 * V_110 = V_9 -> V_110 ;
int V_103 = F_37 ( V_110 ) ;
if ( V_103 < 0 || V_9 -> V_111 ||
V_103 >= V_70 -> V_108 ) {
int V_112 = F_30 ( V_70 , V_9 ) ;
if ( V_112 < 0 )
V_112 = F_38 ( V_70 , V_9 ) ;
if ( V_103 != V_112 && V_110 &&
F_39 ( V_110 -> V_113 ) )
F_40 ( V_110 , V_112 ) ;
V_103 = V_112 ;
}
return V_103 ;
}
struct V_114 * F_41 ( struct V_69 * V_70 ,
struct V_8 * V_9 ,
void * V_115 )
{
int V_103 = 0 ;
if ( V_70 -> V_108 != 1 ) {
const struct V_116 * V_117 = V_70 -> V_118 ;
if ( V_117 -> V_119 )
V_103 = V_117 -> V_119 ( V_70 , V_9 , V_115 ,
F_36 ) ;
else
V_103 = F_36 ( V_70 , V_9 ) ;
if ( ! V_115 )
V_103 = F_42 ( V_70 , V_103 ) ;
}
F_43 ( V_9 , V_103 ) ;
return F_44 ( V_70 , V_103 ) ;
}
