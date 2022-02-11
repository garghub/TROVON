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
case F_7 ( V_27 ) : {
const struct V_28 * V_29 ;
struct V_28 V_30 ;
V_29 = F_8 ( V_9 , V_11 , sizeof( V_30 ) , & V_30 ) ;
if ( ! V_29 )
return false ;
V_13 = V_29 -> V_31 ;
V_11 += sizeof( * V_29 ) ;
goto V_15;
}
case F_7 ( V_32 ) : {
struct {
struct V_33 V_34 ;
T_2 V_13 ;
} * V_34 , V_35 ;
V_34 = F_8 ( V_9 , V_11 , sizeof( V_35 ) , & V_35 ) ;
if ( ! V_34 )
return false ;
V_13 = V_34 -> V_13 ;
V_11 += V_36 ;
switch ( V_13 ) {
case F_7 ( V_37 ) :
goto V_18;
case F_7 ( V_38 ) :
goto V_22;
default:
return false ;
}
}
default:
return false ;
}
switch ( V_12 ) {
case V_39 : {
struct V_40 {
T_2 V_41 ;
T_2 V_13 ;
} * V_34 , V_35 ;
V_34 = F_8 ( V_9 , V_11 , sizeof( V_35 ) , & V_35 ) ;
if ( ! V_34 )
return false ;
if ( ! ( V_34 -> V_41 & ( V_42 | V_43 ) ) ) {
V_13 = V_34 -> V_13 ;
V_11 += 4 ;
if ( V_34 -> V_41 & V_44 )
V_11 += 4 ;
if ( V_34 -> V_41 & V_45 )
V_11 += 4 ;
if ( V_34 -> V_41 & V_46 )
V_11 += 4 ;
if ( V_13 == F_11 ( V_47 ) ) {
const struct V_48 * V_49 ;
struct V_48 V_50 ;
V_49 = F_8 ( V_9 , V_11 ,
sizeof( V_50 ) , & V_50 ) ;
if ( ! V_49 )
return false ;
V_13 = V_49 -> V_51 ;
V_11 += sizeof( * V_49 ) ;
}
goto V_15;
}
break;
}
case V_52 :
goto V_15;
default:
break;
}
V_2 -> V_12 = V_12 ;
V_10 = F_12 ( V_12 ) ;
if ( V_10 >= 0 ) {
V_25 * V_53 , V_54 ;
V_11 += V_10 ;
V_53 = F_8 ( V_9 , V_11 , sizeof( V_54 ) , & V_54 ) ;
if ( V_53 )
V_2 -> V_53 = * V_53 ;
}
V_2 -> V_55 = ( V_56 ) V_11 ;
return true ;
}
void F_13 ( struct V_8 * V_9 )
{
struct V_1 V_57 ;
T_3 V_58 ;
if ( ! F_5 ( V_9 , & V_57 ) )
return;
if ( V_57 . V_53 )
V_9 -> V_59 = 1 ;
if ( ( ( V_24 T_3 ) V_57 . V_5 < ( V_24 T_3 ) V_57 . V_6 ) ||
( ( ( V_24 T_3 ) V_57 . V_5 == ( V_24 T_3 ) V_57 . V_6 ) &&
( ( V_24 V_56 ) V_57 . V_60 [ 1 ] < ( V_24 V_56 ) V_57 . V_60 [ 0 ] ) ) ) {
F_14 ( V_57 . V_5 , V_57 . V_6 ) ;
F_14 ( V_57 . V_60 [ 0 ] , V_57 . V_60 [ 1 ] ) ;
}
V_58 = F_15 ( ( V_24 T_3 ) V_57 . V_5 ,
( V_24 T_3 ) V_57 . V_6 ,
( V_24 T_3 ) V_57 . V_53 , V_61 ) ;
if ( ! V_58 )
V_58 = 1 ;
V_9 -> V_62 = V_58 ;
}
V_56 F_16 ( const struct V_63 * V_64 , const struct V_8 * V_9 ,
unsigned int V_65 )
{
T_3 V_58 ;
V_56 V_66 = 0 ;
V_56 V_67 = V_65 ;
if ( F_17 ( V_9 ) ) {
V_58 = F_18 ( V_9 ) ;
while ( F_19 ( V_58 >= V_65 ) )
V_58 -= V_65 ;
return V_58 ;
}
if ( V_64 -> V_68 ) {
T_1 V_69 = F_20 ( V_64 , V_9 -> V_70 ) ;
V_66 = V_64 -> V_71 [ V_69 ] . V_72 ;
V_67 = V_64 -> V_71 [ V_69 ] . V_73 ;
}
if ( V_9 -> V_74 && V_9 -> V_74 -> V_75 )
V_58 = V_9 -> V_74 -> V_75 ;
else
V_58 = ( V_24 V_56 ) V_9 -> V_14 ;
V_58 = F_21 ( V_58 , V_61 ) ;
return ( V_56 ) ( ( ( V_76 ) V_58 * V_67 ) >> 32 ) + V_66 ;
}
T_3 F_22 ( const struct V_8 * V_9 )
{
struct V_1 V_57 ;
T_3 V_10 = 0 ;
if ( ! F_5 ( V_9 , & V_57 ) )
return 0 ;
V_10 += V_57 . V_55 ;
switch ( V_57 . V_12 ) {
case V_77 : {
const struct V_78 * V_79 ;
struct V_78 V_80 ;
V_79 = F_8 ( V_9 , V_10 , sizeof( V_80 ) , & V_80 ) ;
if ( ! V_79 )
return V_10 ;
V_10 += F_23 ( T_3 , sizeof( struct V_78 ) , V_79 -> V_81 * 4 ) ;
break;
}
case V_82 :
case V_83 :
V_10 += sizeof( struct V_84 ) ;
break;
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
}
return V_10 ;
}
static inline V_56 F_24 ( struct V_63 * V_64 , V_56 V_95 )
{
if ( F_19 ( V_95 >= V_64 -> V_96 ) ) {
F_25 ( L_1 ,
V_64 -> V_97 , V_95 ,
V_64 -> V_96 ) ;
return 0 ;
}
return V_95 ;
}
static inline int F_26 ( struct V_63 * V_64 , struct V_8 * V_9 )
{
#ifdef F_27
struct V_98 * V_99 ;
struct V_100 * V_101 ;
int V_95 = - 1 ;
F_28 () ;
V_99 = F_29 ( V_64 -> V_102 ) ;
if ( V_99 ) {
V_101 = F_29 (
V_99 -> V_103 [ F_30 () ] ) ;
if ( V_101 ) {
if ( V_101 -> V_104 == 1 )
V_95 = V_101 -> V_105 [ 0 ] ;
else {
T_3 V_58 ;
if ( V_9 -> V_74 && V_9 -> V_74 -> V_75 )
V_58 = V_9 -> V_74 -> V_75 ;
else
V_58 = ( V_24 V_56 ) V_9 -> V_14 ^
V_9 -> V_62 ;
V_58 = F_21 ( V_58 , V_61 ) ;
V_95 = V_101 -> V_105 [
( ( V_76 ) V_58 * V_101 -> V_104 ) >> 32 ] ;
}
if ( F_19 ( V_95 >= V_64 -> V_96 ) )
V_95 = - 1 ;
}
}
F_31 () ;
return V_95 ;
#else
return - 1 ;
#endif
}
V_56 F_32 ( struct V_63 * V_64 , struct V_8 * V_9 )
{
struct V_106 * V_74 = V_9 -> V_74 ;
int V_95 = F_33 ( V_74 ) ;
if ( V_95 < 0 || V_9 -> V_107 ||
V_95 >= V_64 -> V_96 ) {
int V_108 = F_26 ( V_64 , V_9 ) ;
if ( V_108 < 0 )
V_108 = F_34 ( V_64 , V_9 ) ;
if ( V_95 != V_108 && V_74 ) {
struct V_109 * V_5 =
F_35 ( V_74 -> V_110 , 1 ) ;
if ( V_5 && F_36 ( V_9 ) == V_5 )
F_37 ( V_74 , V_95 ) ;
}
V_95 = V_108 ;
}
return V_95 ;
}
struct V_111 * F_38 ( struct V_63 * V_64 ,
struct V_8 * V_9 )
{
int V_95 = 0 ;
if ( V_64 -> V_96 != 1 ) {
const struct V_112 * V_113 = V_64 -> V_114 ;
if ( V_113 -> V_115 )
V_95 = V_113 -> V_115 ( V_64 , V_9 ) ;
else
V_95 = F_32 ( V_64 , V_9 ) ;
V_95 = F_24 ( V_64 , V_95 ) ;
}
F_39 ( V_9 , V_95 ) ;
return F_40 ( V_64 , V_95 ) ;
}
static int T_4 F_41 ( void )
{
F_42 ( & V_61 , sizeof( V_61 ) ) ;
return 0 ;
}
