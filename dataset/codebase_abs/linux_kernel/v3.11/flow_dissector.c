static void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
F_2 ( F_3 ( F_4 ( * V_2 ) , V_5 ) !=
F_3 ( F_4 ( * V_2 ) , V_6 ) + sizeof( V_2 -> V_6 ) ) ;
memcpy ( & V_2 -> V_6 , & V_4 -> V_7 , sizeof( V_2 -> V_6 ) + sizeof( V_2 -> V_5 ) ) ;
}
bool F_5 ( const struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_10 , V_11 = F_6 ( V_9 ) ;
T_1 V_12 ;
T_2 V_13 = V_9 -> V_14 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_15:
switch ( V_13 ) {
case F_7 ( V_16 ) : {
const struct V_3 * V_4 ;
struct V_3 V_17 ;
V_18:
V_4 = F_8 ( V_9 , V_11 , sizeof( V_17 ) , & V_17 ) ;
if ( ! V_4 )
return false ;
if ( F_9 ( V_4 ) )
V_12 = 0 ;
else
V_12 = V_4 -> V_14 ;
F_1 ( V_2 , V_4 ) ;
V_11 += V_4 -> V_19 * 4 ;
break;
}
case F_7 ( V_20 ) : {
const struct V_21 * V_4 ;
struct V_21 V_17 ;
V_22:
V_4 = F_8 ( V_9 , V_11 , sizeof( V_17 ) , & V_17 ) ;
if ( ! V_4 )
return false ;
V_12 = V_4 -> V_23 ;
V_2 -> V_6 = ( V_24 V_25 ) F_10 ( & V_4 -> V_7 ) ;
V_2 -> V_5 = ( V_24 V_25 ) F_10 ( & V_4 -> V_26 ) ;
V_11 += sizeof( struct V_21 ) ;
break;
}
case F_7 ( V_27 ) :
case F_7 ( V_28 ) : {
const struct V_29 * V_30 ;
struct V_29 V_31 ;
V_30 = F_8 ( V_9 , V_11 , sizeof( V_31 ) , & V_31 ) ;
if ( ! V_30 )
return false ;
V_13 = V_30 -> V_32 ;
V_11 += sizeof( * V_30 ) ;
goto V_15;
}
case F_7 ( V_33 ) : {
struct {
struct V_34 V_35 ;
T_2 V_13 ;
} * V_35 , V_36 ;
V_35 = F_8 ( V_9 , V_11 , sizeof( V_36 ) , & V_36 ) ;
if ( ! V_35 )
return false ;
V_13 = V_35 -> V_13 ;
V_11 += V_37 ;
switch ( V_13 ) {
case F_7 ( V_38 ) :
goto V_18;
case F_7 ( V_39 ) :
goto V_22;
default:
return false ;
}
}
default:
return false ;
}
switch ( V_12 ) {
case V_40 : {
struct V_41 {
T_2 V_42 ;
T_2 V_13 ;
} * V_35 , V_36 ;
V_35 = F_8 ( V_9 , V_11 , sizeof( V_36 ) , & V_36 ) ;
if ( ! V_35 )
return false ;
if ( ! ( V_35 -> V_42 & ( V_43 | V_44 ) ) ) {
V_13 = V_35 -> V_13 ;
V_11 += 4 ;
if ( V_35 -> V_42 & V_45 )
V_11 += 4 ;
if ( V_35 -> V_42 & V_46 )
V_11 += 4 ;
if ( V_35 -> V_42 & V_47 )
V_11 += 4 ;
if ( V_13 == F_11 ( V_48 ) ) {
const struct V_49 * V_50 ;
struct V_49 V_51 ;
V_50 = F_8 ( V_9 , V_11 ,
sizeof( V_51 ) , & V_51 ) ;
if ( ! V_50 )
return false ;
V_13 = V_50 -> V_52 ;
V_11 += sizeof( * V_50 ) ;
}
goto V_15;
}
break;
}
case V_53 :
goto V_15;
default:
break;
}
V_2 -> V_12 = V_12 ;
V_10 = F_12 ( V_12 ) ;
if ( V_10 >= 0 ) {
V_25 * V_54 , V_55 ;
V_11 += V_10 ;
V_54 = F_8 ( V_9 , V_11 , sizeof( V_55 ) , & V_55 ) ;
if ( V_54 )
V_2 -> V_54 = * V_54 ;
}
V_2 -> V_56 = ( V_57 ) V_11 ;
return true ;
}
void F_13 ( struct V_8 * V_9 )
{
struct V_1 V_58 ;
T_3 V_59 ;
if ( ! F_5 ( V_9 , & V_58 ) )
return;
if ( V_58 . V_54 )
V_9 -> V_60 = 1 ;
if ( ( ( V_24 T_3 ) V_58 . V_5 < ( V_24 T_3 ) V_58 . V_6 ) ||
( ( ( V_24 T_3 ) V_58 . V_5 == ( V_24 T_3 ) V_58 . V_6 ) &&
( ( V_24 V_57 ) V_58 . V_61 [ 1 ] < ( V_24 V_57 ) V_58 . V_61 [ 0 ] ) ) ) {
F_14 ( V_58 . V_5 , V_58 . V_6 ) ;
F_14 ( V_58 . V_61 [ 0 ] , V_58 . V_61 [ 1 ] ) ;
}
V_59 = F_15 ( ( V_24 T_3 ) V_58 . V_5 ,
( V_24 T_3 ) V_58 . V_6 ,
( V_24 T_3 ) V_58 . V_54 , V_62 ) ;
if ( ! V_59 )
V_59 = 1 ;
V_9 -> V_63 = V_59 ;
}
V_57 F_16 ( const struct V_64 * V_65 , const struct V_8 * V_9 ,
unsigned int V_66 )
{
T_3 V_59 ;
V_57 V_67 = 0 ;
V_57 V_68 = V_66 ;
if ( F_17 ( V_9 ) ) {
V_59 = F_18 ( V_9 ) ;
while ( F_19 ( V_59 >= V_66 ) )
V_59 -= V_66 ;
return V_59 ;
}
if ( V_65 -> V_69 ) {
T_1 V_70 = F_20 ( V_65 , V_9 -> V_71 ) ;
V_67 = V_65 -> V_72 [ V_70 ] . V_73 ;
V_68 = V_65 -> V_72 [ V_70 ] . V_74 ;
}
if ( V_9 -> V_75 && V_9 -> V_75 -> V_76 )
V_59 = V_9 -> V_75 -> V_76 ;
else
V_59 = ( V_24 V_57 ) V_9 -> V_14 ;
V_59 = F_21 ( V_59 , V_62 ) ;
return ( V_57 ) ( ( ( V_77 ) V_59 * V_68 ) >> 32 ) + V_67 ;
}
T_3 F_22 ( const struct V_8 * V_9 )
{
struct V_1 V_58 ;
T_3 V_10 = 0 ;
if ( ! F_5 ( V_9 , & V_58 ) )
return 0 ;
V_10 += V_58 . V_56 ;
switch ( V_58 . V_12 ) {
case V_78 : {
const struct V_79 * V_80 ;
struct V_79 V_81 ;
V_80 = F_8 ( V_9 , V_10 , sizeof( V_81 ) , & V_81 ) ;
if ( ! V_80 )
return V_10 ;
V_10 += F_23 ( T_3 , sizeof( struct V_79 ) , V_80 -> V_82 * 4 ) ;
break;
}
case V_83 :
case V_84 :
V_10 += sizeof( struct V_85 ) ;
break;
case V_86 :
V_10 += sizeof( struct V_87 ) ;
break;
case V_88 :
V_10 += sizeof( struct V_89 ) ;
break;
case V_90 :
V_10 += sizeof( struct V_91 ) ;
break;
case V_92 :
V_10 += sizeof( struct V_93 ) ;
break;
case V_94 :
V_10 += sizeof( struct V_95 ) ;
break;
}
return V_10 ;
}
static inline V_57 F_24 ( struct V_64 * V_65 , V_57 V_96 )
{
if ( F_19 ( V_96 >= V_65 -> V_97 ) ) {
F_25 ( L_1 ,
V_65 -> V_98 , V_96 ,
V_65 -> V_97 ) ;
return 0 ;
}
return V_96 ;
}
static inline int F_26 ( struct V_64 * V_65 , struct V_8 * V_9 )
{
#ifdef F_27
struct V_99 * V_100 ;
struct V_101 * V_102 ;
int V_96 = - 1 ;
F_28 () ;
V_100 = F_29 ( V_65 -> V_103 ) ;
if ( V_100 ) {
V_102 = F_29 (
V_100 -> V_104 [ F_30 () ] ) ;
if ( V_102 ) {
if ( V_102 -> V_105 == 1 )
V_96 = V_102 -> V_106 [ 0 ] ;
else {
T_3 V_59 ;
if ( V_9 -> V_75 && V_9 -> V_75 -> V_76 )
V_59 = V_9 -> V_75 -> V_76 ;
else
V_59 = ( V_24 V_57 ) V_9 -> V_14 ^
V_9 -> V_63 ;
V_59 = F_21 ( V_59 , V_62 ) ;
V_96 = V_102 -> V_106 [
( ( V_77 ) V_59 * V_102 -> V_105 ) >> 32 ] ;
}
if ( F_19 ( V_96 >= V_65 -> V_97 ) )
V_96 = - 1 ;
}
}
F_31 () ;
return V_96 ;
#else
return - 1 ;
#endif
}
V_57 F_32 ( struct V_64 * V_65 , struct V_8 * V_9 )
{
struct V_107 * V_75 = V_9 -> V_75 ;
int V_96 = F_33 ( V_75 ) ;
if ( V_96 < 0 || V_9 -> V_108 ||
V_96 >= V_65 -> V_97 ) {
int V_109 = F_26 ( V_65 , V_9 ) ;
if ( V_109 < 0 )
V_109 = F_34 ( V_65 , V_9 ) ;
if ( V_96 != V_109 && V_75 &&
F_35 ( V_75 -> V_110 ) )
F_36 ( V_75 , V_96 ) ;
V_96 = V_109 ;
}
return V_96 ;
}
struct V_111 * F_37 ( struct V_64 * V_65 ,
struct V_8 * V_9 )
{
int V_96 = 0 ;
if ( V_65 -> V_97 != 1 ) {
const struct V_112 * V_113 = V_65 -> V_114 ;
if ( V_113 -> V_115 )
V_96 = V_113 -> V_115 ( V_65 , V_9 ) ;
else
V_96 = F_32 ( V_65 , V_9 ) ;
V_96 = F_24 ( V_65 , V_96 ) ;
}
F_38 ( V_9 , V_96 ) ;
return F_39 ( V_65 , V_96 ) ;
}
static int T_4 F_40 ( void )
{
F_41 ( & V_62 , sizeof( V_62 ) ) ;
return 0 ;
}
