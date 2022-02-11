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
V_25:
V_4 = F_7 ( V_9 , V_15 , sizeof( V_20 ) , & V_20 ) ;
if ( ! V_4 )
return false ;
V_11 = V_4 -> V_26 ;
V_2 -> V_6 = ( V_27 T_1 ) F_12 ( & V_4 -> V_7 ) ;
V_2 -> V_5 = ( V_27 T_1 ) F_12 ( & V_4 -> V_28 ) ;
V_15 += sizeof( struct V_24 ) ;
break;
}
case F_10 ( V_29 ) :
case F_10 ( V_30 ) : {
const struct V_31 * V_32 ;
struct V_31 V_33 ;
V_32 = F_7 ( V_9 , V_15 , sizeof( V_33 ) , & V_33 ) ;
if ( ! V_32 )
return false ;
V_16 = V_32 -> V_34 ;
V_15 += sizeof( * V_32 ) ;
goto V_18;
}
case F_10 ( V_35 ) : {
struct {
struct V_36 V_37 ;
T_3 V_16 ;
} * V_37 , V_38 ;
V_37 = F_7 ( V_9 , V_15 , sizeof( V_38 ) , & V_38 ) ;
if ( ! V_37 )
return false ;
V_16 = V_37 -> V_16 ;
V_15 += V_39 ;
switch ( V_16 ) {
case F_10 ( V_40 ) :
goto V_21;
case F_10 ( V_41 ) :
goto V_25;
default:
return false ;
}
}
default:
return false ;
}
switch ( V_11 ) {
case V_42 : {
struct V_43 {
T_3 V_44 ;
T_3 V_16 ;
} * V_37 , V_38 ;
V_37 = F_7 ( V_9 , V_15 , sizeof( V_38 ) , & V_38 ) ;
if ( ! V_37 )
return false ;
if ( ! ( V_37 -> V_44 & ( V_45 | V_46 ) ) ) {
V_16 = V_37 -> V_16 ;
V_15 += 4 ;
if ( V_37 -> V_44 & V_47 )
V_15 += 4 ;
if ( V_37 -> V_44 & V_48 )
V_15 += 4 ;
if ( V_37 -> V_44 & V_49 )
V_15 += 4 ;
if ( V_16 == F_10 ( V_50 ) ) {
const struct V_51 * V_52 ;
struct V_51 V_53 ;
V_52 = F_7 ( V_9 , V_15 ,
sizeof( V_53 ) , & V_53 ) ;
if ( ! V_52 )
return false ;
V_16 = V_52 -> V_54 ;
V_15 += sizeof( * V_52 ) ;
}
goto V_18;
}
break;
}
case V_55 :
V_16 = F_10 ( V_19 ) ;
goto V_21;
case V_56 :
V_16 = F_10 ( V_23 ) ;
goto V_25;
default:
break;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_13 = F_5 ( V_9 , V_15 , V_11 ) ;
V_2 -> V_10 = ( V_57 ) V_15 ;
return true ;
}
static T_4 void F_13 ( void )
{
F_14 ( & V_58 , sizeof( V_58 ) ) ;
}
static T_4 T_5 F_15 ( T_5 V_59 , T_5 V_60 , T_5 V_61 )
{
F_13 () ;
return F_16 ( V_59 , V_60 , V_61 , V_58 ) ;
}
static T_4 T_5 F_17 ( T_5 V_59 )
{
F_13 () ;
return F_18 ( V_59 , V_58 ) ;
}
void F_19 ( struct V_8 * V_9 )
{
struct V_1 V_62 ;
T_5 V_63 ;
if ( ! F_8 ( V_9 , & V_62 ) )
return;
if ( V_62 . V_13 )
V_9 -> V_64 = 1 ;
if ( ( ( V_27 T_5 ) V_62 . V_5 < ( V_27 T_5 ) V_62 . V_6 ) ||
( ( ( V_27 T_5 ) V_62 . V_5 == ( V_27 T_5 ) V_62 . V_6 ) &&
( ( V_27 V_57 ) V_62 . V_65 [ 1 ] < ( V_27 V_57 ) V_62 . V_65 [ 0 ] ) ) ) {
F_20 ( V_62 . V_5 , V_62 . V_6 ) ;
F_20 ( V_62 . V_65 [ 0 ] , V_62 . V_65 [ 1 ] ) ;
}
V_63 = F_15 ( ( V_27 T_5 ) V_62 . V_5 ,
( V_27 T_5 ) V_62 . V_6 ,
( V_27 T_5 ) V_62 . V_13 ) ;
if ( ! V_63 )
V_63 = 1 ;
V_9 -> V_63 = V_63 ;
}
V_57 F_21 ( const struct V_66 * V_67 , const struct V_8 * V_9 ,
unsigned int V_68 )
{
T_5 V_63 ;
V_57 V_69 = 0 ;
V_57 V_70 = V_68 ;
if ( F_22 ( V_9 ) ) {
V_63 = F_23 ( V_9 ) ;
while ( F_24 ( V_63 >= V_68 ) )
V_63 -= V_68 ;
return V_63 ;
}
if ( V_67 -> V_71 ) {
T_2 V_72 = F_25 ( V_67 , V_9 -> V_73 ) ;
V_69 = V_67 -> V_74 [ V_72 ] . V_75 ;
V_70 = V_67 -> V_74 [ V_72 ] . V_76 ;
}
if ( V_9 -> V_77 && V_9 -> V_77 -> V_78 )
V_63 = V_9 -> V_77 -> V_78 ;
else
V_63 = ( V_27 V_57 ) V_9 -> V_17 ;
V_63 = F_17 ( V_63 ) ;
return ( V_57 ) ( ( ( V_79 ) V_63 * V_70 ) >> 32 ) + V_69 ;
}
T_5 F_26 ( const struct V_8 * V_9 )
{
struct V_1 V_62 ;
T_5 V_12 = 0 ;
if ( ! F_8 ( V_9 , & V_62 ) )
return 0 ;
V_12 += V_62 . V_10 ;
switch ( V_62 . V_11 ) {
case V_80 : {
const struct V_81 * V_82 ;
struct V_81 V_83 ;
V_82 = F_7 ( V_9 , V_12 , sizeof( V_83 ) , & V_83 ) ;
if ( ! V_82 )
return V_12 ;
V_12 += F_27 ( T_5 , sizeof( struct V_81 ) , V_82 -> V_84 * 4 ) ;
break;
}
case V_85 :
case V_86 :
V_12 += sizeof( struct V_87 ) ;
break;
case V_88 :
V_12 += sizeof( struct V_89 ) ;
break;
case V_90 :
V_12 += sizeof( struct V_91 ) ;
break;
case V_92 :
V_12 += sizeof( struct V_93 ) ;
break;
case V_94 :
V_12 += sizeof( struct V_95 ) ;
break;
case V_96 :
V_12 += sizeof( struct V_97 ) ;
break;
}
return V_12 ;
}
static inline int F_28 ( struct V_66 * V_67 , struct V_8 * V_9 )
{
#ifdef F_29
struct V_98 * V_99 ;
struct V_100 * V_101 ;
int V_102 = - 1 ;
F_30 () ;
V_99 = F_31 ( V_67 -> V_103 ) ;
if ( V_99 ) {
V_101 = F_31 (
V_99 -> V_104 [ F_32 () ] ) ;
if ( V_101 ) {
if ( V_101 -> V_105 == 1 )
V_102 = V_101 -> V_106 [ 0 ] ;
else {
T_5 V_63 ;
if ( V_9 -> V_77 && V_9 -> V_77 -> V_78 )
V_63 = V_9 -> V_77 -> V_78 ;
else
V_63 = ( V_27 V_57 ) V_9 -> V_17 ^
V_9 -> V_63 ;
V_63 = F_17 ( V_63 ) ;
V_102 = V_101 -> V_106 [
( ( V_79 ) V_63 * V_101 -> V_105 ) >> 32 ] ;
}
if ( F_24 ( V_102 >= V_67 -> V_107 ) )
V_102 = - 1 ;
}
}
F_33 () ;
return V_102 ;
#else
return - 1 ;
#endif
}
static V_57 F_34 ( struct V_66 * V_67 , struct V_8 * V_9 )
{
struct V_108 * V_77 = V_9 -> V_77 ;
int V_102 = F_35 ( V_77 ) ;
if ( V_102 < 0 || V_9 -> V_109 ||
V_102 >= V_67 -> V_107 ) {
int V_110 = F_28 ( V_67 , V_9 ) ;
if ( V_110 < 0 )
V_110 = F_36 ( V_67 , V_9 ) ;
if ( V_102 != V_110 && V_77 &&
F_37 ( V_77 -> V_111 ) )
F_38 ( V_77 , V_110 ) ;
V_102 = V_110 ;
}
return V_102 ;
}
struct V_112 * F_39 ( struct V_66 * V_67 ,
struct V_8 * V_9 ,
void * V_113 )
{
int V_102 = 0 ;
if ( V_67 -> V_107 != 1 ) {
const struct V_114 * V_115 = V_67 -> V_116 ;
if ( V_115 -> V_117 )
V_102 = V_115 -> V_117 ( V_67 , V_9 , V_113 ,
F_34 ) ;
else
V_102 = F_34 ( V_67 , V_9 ) ;
if ( ! V_113 )
V_102 = F_40 ( V_67 , V_102 ) ;
}
F_41 ( V_9 , V_102 ) ;
return F_42 ( V_67 , V_102 ) ;
}
