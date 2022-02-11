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
goto V_15;
}
break;
}
case V_47 :
goto V_15;
default:
break;
}
V_2 -> V_12 = V_12 ;
V_10 = F_11 ( V_12 ) ;
if ( V_10 >= 0 ) {
V_25 * V_48 , V_49 ;
V_11 += V_10 ;
V_48 = F_8 ( V_9 , V_11 , sizeof( V_49 ) , & V_49 ) ;
if ( V_48 )
V_2 -> V_48 = * V_48 ;
}
V_2 -> V_50 = ( V_51 ) V_11 ;
return true ;
}
void F_12 ( struct V_8 * V_9 )
{
struct V_1 V_52 ;
T_3 V_53 ;
if ( ! F_5 ( V_9 , & V_52 ) )
return;
if ( V_52 . V_48 )
V_9 -> V_54 = 1 ;
if ( ( ( V_24 T_3 ) V_52 . V_5 < ( V_24 T_3 ) V_52 . V_6 ) ||
( ( ( V_24 T_3 ) V_52 . V_5 == ( V_24 T_3 ) V_52 . V_6 ) &&
( ( V_24 V_51 ) V_52 . V_55 [ 1 ] < ( V_24 V_51 ) V_52 . V_55 [ 0 ] ) ) ) {
F_13 ( V_52 . V_5 , V_52 . V_6 ) ;
F_13 ( V_52 . V_55 [ 0 ] , V_52 . V_55 [ 1 ] ) ;
}
V_53 = F_14 ( ( V_24 T_3 ) V_52 . V_5 ,
( V_24 T_3 ) V_52 . V_6 ,
( V_24 T_3 ) V_52 . V_48 , V_56 ) ;
if ( ! V_53 )
V_53 = 1 ;
V_9 -> V_57 = V_53 ;
}
V_51 F_15 ( const struct V_58 * V_59 , const struct V_8 * V_9 ,
unsigned int V_60 )
{
T_3 V_53 ;
V_51 V_61 = 0 ;
V_51 V_62 = V_60 ;
if ( F_16 ( V_9 ) ) {
V_53 = F_17 ( V_9 ) ;
while ( F_18 ( V_53 >= V_60 ) )
V_53 -= V_60 ;
return V_53 ;
}
if ( V_59 -> V_63 ) {
T_1 V_64 = F_19 ( V_59 , V_9 -> V_65 ) ;
V_61 = V_59 -> V_66 [ V_64 ] . V_67 ;
V_62 = V_59 -> V_66 [ V_64 ] . V_68 ;
}
if ( V_9 -> V_69 && V_9 -> V_69 -> V_70 )
V_53 = V_9 -> V_69 -> V_70 ;
else
V_53 = ( V_24 V_51 ) V_9 -> V_14 ;
V_53 = F_20 ( V_53 , V_56 ) ;
return ( V_51 ) ( ( ( V_71 ) V_53 * V_62 ) >> 32 ) + V_61 ;
}
static inline V_51 F_21 ( struct V_58 * V_59 , V_51 V_72 )
{
if ( F_18 ( V_72 >= V_59 -> V_73 ) ) {
F_22 ( L_1 ,
V_59 -> V_74 , V_72 ,
V_59 -> V_73 ) ;
return 0 ;
}
return V_72 ;
}
static inline int F_23 ( struct V_58 * V_59 , struct V_8 * V_9 )
{
#ifdef F_24
struct V_75 * V_76 ;
struct V_77 * V_78 ;
int V_72 = - 1 ;
F_25 () ;
V_76 = F_26 ( V_59 -> V_79 ) ;
if ( V_76 ) {
V_78 = F_26 (
V_76 -> V_80 [ F_27 () ] ) ;
if ( V_78 ) {
if ( V_78 -> V_81 == 1 )
V_72 = V_78 -> V_82 [ 0 ] ;
else {
T_3 V_53 ;
if ( V_9 -> V_69 && V_9 -> V_69 -> V_70 )
V_53 = V_9 -> V_69 -> V_70 ;
else
V_53 = ( V_24 V_51 ) V_9 -> V_14 ^
V_9 -> V_57 ;
V_53 = F_20 ( V_53 , V_56 ) ;
V_72 = V_78 -> V_82 [
( ( V_71 ) V_53 * V_78 -> V_81 ) >> 32 ] ;
}
if ( F_18 ( V_72 >= V_59 -> V_73 ) )
V_72 = - 1 ;
}
}
F_28 () ;
return V_72 ;
#else
return - 1 ;
#endif
}
V_51 F_29 ( struct V_58 * V_59 , struct V_8 * V_9 )
{
struct V_83 * V_69 = V_9 -> V_69 ;
int V_72 = F_30 ( V_69 ) ;
if ( V_72 < 0 || V_9 -> V_84 ||
V_72 >= V_59 -> V_73 ) {
int V_85 = F_23 ( V_59 , V_9 ) ;
if ( V_85 < 0 )
V_85 = F_31 ( V_59 , V_9 ) ;
if ( V_72 != V_85 && V_69 ) {
struct V_86 * V_5 =
F_32 ( V_69 -> V_87 , 1 ) ;
if ( V_5 && F_33 ( V_9 ) == V_5 )
F_34 ( V_69 , V_72 ) ;
}
V_72 = V_85 ;
}
return V_72 ;
}
struct V_88 * F_35 ( struct V_58 * V_59 ,
struct V_8 * V_9 )
{
int V_72 = 0 ;
if ( V_59 -> V_73 != 1 ) {
const struct V_89 * V_90 = V_59 -> V_91 ;
if ( V_90 -> V_92 )
V_72 = V_90 -> V_92 ( V_59 , V_9 ) ;
else
V_72 = F_29 ( V_59 , V_9 ) ;
V_72 = F_21 ( V_59 , V_72 ) ;
}
F_36 ( V_9 , V_72 ) ;
return F_37 ( V_59 , V_72 ) ;
}
static int T_4 F_38 ( void )
{
F_39 ( & V_56 , sizeof( V_56 ) ) ;
return 0 ;
}
