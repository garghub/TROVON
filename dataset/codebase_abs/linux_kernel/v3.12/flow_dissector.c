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
V_13 = F_11 ( V_16 ) ;
goto V_18;
case V_54 :
V_13 = F_11 ( V_20 ) ;
goto V_22;
default:
break;
}
V_2 -> V_12 = V_12 ;
V_10 = F_12 ( V_12 ) ;
if ( V_10 >= 0 ) {
V_25 * V_55 , V_56 ;
V_55 = F_8 ( V_9 , V_11 + V_10 ,
sizeof( V_56 ) , & V_56 ) ;
if ( V_55 )
V_2 -> V_55 = * V_55 ;
}
V_2 -> V_57 = ( V_58 ) V_11 ;
return true ;
}
void F_13 ( struct V_8 * V_9 )
{
struct V_1 V_59 ;
T_3 V_60 ;
if ( ! F_5 ( V_9 , & V_59 ) )
return;
if ( V_59 . V_55 )
V_9 -> V_61 = 1 ;
if ( ( ( V_24 T_3 ) V_59 . V_5 < ( V_24 T_3 ) V_59 . V_6 ) ||
( ( ( V_24 T_3 ) V_59 . V_5 == ( V_24 T_3 ) V_59 . V_6 ) &&
( ( V_24 V_58 ) V_59 . V_62 [ 1 ] < ( V_24 V_58 ) V_59 . V_62 [ 0 ] ) ) ) {
F_14 ( V_59 . V_5 , V_59 . V_6 ) ;
F_14 ( V_59 . V_62 [ 0 ] , V_59 . V_62 [ 1 ] ) ;
}
V_60 = F_15 ( ( V_24 T_3 ) V_59 . V_5 ,
( V_24 T_3 ) V_59 . V_6 ,
( V_24 T_3 ) V_59 . V_55 , V_63 ) ;
if ( ! V_60 )
V_60 = 1 ;
V_9 -> V_64 = V_60 ;
}
V_58 F_16 ( const struct V_65 * V_66 , const struct V_8 * V_9 ,
unsigned int V_67 )
{
T_3 V_60 ;
V_58 V_68 = 0 ;
V_58 V_69 = V_67 ;
if ( F_17 ( V_9 ) ) {
V_60 = F_18 ( V_9 ) ;
while ( F_19 ( V_60 >= V_67 ) )
V_60 -= V_67 ;
return V_60 ;
}
if ( V_66 -> V_70 ) {
T_1 V_71 = F_20 ( V_66 , V_9 -> V_72 ) ;
V_68 = V_66 -> V_73 [ V_71 ] . V_74 ;
V_69 = V_66 -> V_73 [ V_71 ] . V_75 ;
}
if ( V_9 -> V_76 && V_9 -> V_76 -> V_77 )
V_60 = V_9 -> V_76 -> V_77 ;
else
V_60 = ( V_24 V_58 ) V_9 -> V_14 ;
V_60 = F_21 ( V_60 , V_63 ) ;
return ( V_58 ) ( ( ( V_78 ) V_60 * V_69 ) >> 32 ) + V_68 ;
}
T_3 F_22 ( const struct V_8 * V_9 )
{
struct V_1 V_59 ;
T_3 V_10 = 0 ;
if ( ! F_5 ( V_9 , & V_59 ) )
return 0 ;
V_10 += V_59 . V_57 ;
switch ( V_59 . V_12 ) {
case V_79 : {
const struct V_80 * V_81 ;
struct V_80 V_82 ;
V_81 = F_8 ( V_9 , V_10 , sizeof( V_82 ) , & V_82 ) ;
if ( ! V_81 )
return V_10 ;
V_10 += F_23 ( T_3 , sizeof( struct V_80 ) , V_81 -> V_83 * 4 ) ;
break;
}
case V_84 :
case V_85 :
V_10 += sizeof( struct V_86 ) ;
break;
case V_87 :
V_10 += sizeof( struct V_88 ) ;
break;
case V_89 :
V_10 += sizeof( struct V_90 ) ;
break;
case V_91 :
V_10 += sizeof( struct V_92 ) ;
break;
case V_93 :
V_10 += sizeof( struct V_94 ) ;
break;
case V_95 :
V_10 += sizeof( struct V_96 ) ;
break;
}
return V_10 ;
}
static inline V_58 F_24 ( struct V_65 * V_66 , V_58 V_97 )
{
if ( F_19 ( V_97 >= V_66 -> V_98 ) ) {
F_25 ( L_1 ,
V_66 -> V_99 , V_97 ,
V_66 -> V_98 ) ;
return 0 ;
}
return V_97 ;
}
static inline int F_26 ( struct V_65 * V_66 , struct V_8 * V_9 )
{
#ifdef F_27
struct V_100 * V_101 ;
struct V_102 * V_103 ;
int V_97 = - 1 ;
F_28 () ;
V_101 = F_29 ( V_66 -> V_104 ) ;
if ( V_101 ) {
V_103 = F_29 (
V_101 -> V_105 [ F_30 () ] ) ;
if ( V_103 ) {
if ( V_103 -> V_106 == 1 )
V_97 = V_103 -> V_107 [ 0 ] ;
else {
T_3 V_60 ;
if ( V_9 -> V_76 && V_9 -> V_76 -> V_77 )
V_60 = V_9 -> V_76 -> V_77 ;
else
V_60 = ( V_24 V_58 ) V_9 -> V_14 ^
V_9 -> V_64 ;
V_60 = F_21 ( V_60 , V_63 ) ;
V_97 = V_103 -> V_107 [
( ( V_78 ) V_60 * V_103 -> V_106 ) >> 32 ] ;
}
if ( F_19 ( V_97 >= V_66 -> V_98 ) )
V_97 = - 1 ;
}
}
F_31 () ;
return V_97 ;
#else
return - 1 ;
#endif
}
V_58 F_32 ( struct V_65 * V_66 , struct V_8 * V_9 )
{
struct V_108 * V_76 = V_9 -> V_76 ;
int V_97 = F_33 ( V_76 ) ;
if ( V_97 < 0 || V_9 -> V_109 ||
V_97 >= V_66 -> V_98 ) {
int V_110 = F_26 ( V_66 , V_9 ) ;
if ( V_110 < 0 )
V_110 = F_34 ( V_66 , V_9 ) ;
if ( V_97 != V_110 && V_76 &&
F_35 ( V_76 -> V_111 ) )
F_36 ( V_76 , V_110 ) ;
V_97 = V_110 ;
}
return V_97 ;
}
struct V_112 * F_37 ( struct V_65 * V_66 ,
struct V_8 * V_9 )
{
int V_97 = 0 ;
if ( V_66 -> V_98 != 1 ) {
const struct V_113 * V_114 = V_66 -> V_115 ;
if ( V_114 -> V_116 )
V_97 = V_114 -> V_116 ( V_66 , V_9 ) ;
else
V_97 = F_32 ( V_66 , V_9 ) ;
V_97 = F_24 ( V_66 , V_97 ) ;
}
F_38 ( V_9 , V_97 ) ;
return F_39 ( V_66 , V_97 ) ;
}
static int T_4 F_40 ( void )
{
F_41 ( & V_63 , sizeof( V_63 ) ) ;
return 0 ;
}
