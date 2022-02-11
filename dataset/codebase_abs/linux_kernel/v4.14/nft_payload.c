static bool
F_1 ( T_1 * V_1 , const struct V_2 * V_3 , T_2 V_4 , T_2 V_5 )
{
int V_6 = F_2 ( V_3 ) - V_3 -> V_7 ;
T_2 V_8 , * V_9 , * V_10 = ( T_2 * ) V_1 ;
struct V_11 V_12 ;
V_9 = ( T_2 * ) & V_12 ;
if ( V_4 < V_13 ) {
T_2 V_14 = F_3 ( T_2 , V_5 , V_13 - V_4 ) ;
if ( F_4 ( V_3 , V_6 , & V_12 , V_13 ) )
return false ;
V_12 . V_15 = V_3 -> V_16 ;
memcpy ( V_10 , V_9 + V_4 , V_14 ) ;
V_5 -= V_14 ;
if ( V_5 == 0 )
return true ;
V_10 += V_14 ;
V_4 = V_13 ;
} else if ( V_4 >= V_17 ) {
V_4 -= V_18 ;
goto V_19;
}
V_12 . V_20 = F_5 ( F_6 ( V_3 ) ) ;
V_12 . V_21 = V_3 -> V_22 ;
V_9 += V_4 ;
V_8 = F_3 ( T_2 , V_5 , V_17 - V_4 ) ;
memcpy ( V_10 , V_9 , V_8 ) ;
V_5 -= V_8 ;
if ( ! V_5 )
return true ;
V_10 += V_8 ;
V_19:
return F_4 ( V_3 , V_4 + V_6 , V_10 , V_5 ) == 0 ;
}
static void F_7 ( const struct V_23 * V_24 ,
struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
const struct V_29 * V_30 = F_8 ( V_24 ) ;
const struct V_2 * V_3 = V_28 -> V_3 ;
T_1 * V_31 = & V_26 -> V_7 [ V_30 -> V_32 ] ;
int V_4 ;
V_31 [ V_30 -> V_5 / V_33 ] = 0 ;
switch ( V_30 -> V_34 ) {
case V_35 :
if ( ! F_9 ( V_3 ) )
goto V_36;
if ( F_10 ( V_3 ) ) {
if ( ! F_1 ( V_31 , V_3 ,
V_30 -> V_4 , V_30 -> V_5 ) )
goto V_36;
return;
}
V_4 = F_2 ( V_3 ) - V_3 -> V_7 ;
break;
case V_37 :
V_4 = F_11 ( V_3 ) ;
break;
case V_38 :
if ( ! V_28 -> V_39 )
goto V_36;
V_4 = V_28 -> V_40 . V_41 ;
break;
default:
F_12 () ;
}
V_4 += V_30 -> V_4 ;
if ( F_4 ( V_3 , V_4 , V_31 , V_30 -> V_5 ) < 0 )
goto V_36;
return;
V_36:
V_26 -> V_42 . V_43 = V_44 ;
}
static int F_13 ( const struct V_45 * V_46 ,
const struct V_23 * V_24 ,
const struct V_47 * const V_48 [] )
{
struct V_29 * V_30 = F_8 ( V_24 ) ;
V_30 -> V_34 = F_14 ( F_15 ( V_48 [ V_49 ] ) ) ;
V_30 -> V_4 = F_14 ( F_15 ( V_48 [ V_50 ] ) ) ;
V_30 -> V_5 = F_14 ( F_15 ( V_48 [ V_51 ] ) ) ;
V_30 -> V_32 = F_16 ( V_48 [ V_52 ] ) ;
return F_17 ( V_46 , V_30 -> V_32 , NULL ,
V_53 , V_30 -> V_5 ) ;
}
static int F_18 ( struct V_2 * V_3 , const struct V_23 * V_24 )
{
const struct V_29 * V_30 = F_8 ( V_24 ) ;
if ( F_19 ( V_3 , V_52 , V_30 -> V_32 ) ||
F_20 ( V_3 , V_49 , F_21 ( V_30 -> V_34 ) ) ||
F_20 ( V_3 , V_50 , F_21 ( V_30 -> V_4 ) ) ||
F_20 ( V_3 , V_51 , F_21 ( V_30 -> V_5 ) ) )
goto V_54;
return 0 ;
V_54:
return - 1 ;
}
static inline void F_22 ( T_3 * V_55 , T_4 V_56 , T_4 V_57 )
{
* V_55 = F_23 ( F_24 ( F_25 ( ~ F_26 ( * V_55 ) , V_56 ) , V_57 ) ) ;
if ( * V_55 == 0 )
* V_55 = V_58 ;
}
static bool F_27 ( struct V_2 * V_3 , unsigned int V_41 )
{
struct V_59 * V_60 , V_61 ;
V_60 = F_28 ( V_3 , V_41 , sizeof( V_61 ) , & V_61 ) ;
if ( ! V_60 )
return false ;
return ( V_62 bool ) V_60 -> V_63 ;
}
static int F_29 ( const struct V_27 * V_28 ,
struct V_2 * V_3 ,
unsigned int * V_64 )
{
switch ( V_28 -> V_65 ) {
case V_66 :
* V_64 = F_30 ( struct V_67 , V_63 ) ;
break;
case V_68 :
if ( ! F_27 ( V_3 , V_28 -> V_40 . V_41 ) )
return - 1 ;
case V_69 :
* V_64 = F_30 ( struct V_59 , V_63 ) ;
break;
case V_70 :
* V_64 = F_30 ( struct V_71 , V_72 ) ;
break;
default:
return - 1 ;
}
* V_64 += V_28 -> V_40 . V_41 ;
return 0 ;
}
static int F_31 ( const struct V_27 * V_28 ,
struct V_2 * V_3 ,
T_4 V_56 , T_4 V_57 )
{
int V_64 ;
T_3 V_55 ;
if ( F_29 ( V_28 , V_3 , & V_64 ) < 0 )
return 0 ;
if ( F_4 ( V_3 , V_64 , & V_55 , sizeof( V_55 ) ) < 0 )
return - 1 ;
if ( V_3 -> V_73 != V_74 ) {
F_22 ( & V_55 , V_56 , V_57 ) ;
if ( V_3 -> V_73 == V_75 ) {
V_3 -> V_76 = ~ F_24 ( F_25 ( ~ ( V_3 -> V_76 ) , V_56 ) ,
V_57 ) ;
}
} else {
V_55 = ~ F_23 ( F_24 ( F_25 ( F_26 ( V_55 ) , V_56 ) ,
V_57 ) ) ;
}
if ( ! F_32 ( V_3 , V_64 + sizeof( V_55 ) ) ||
F_33 ( V_3 , V_64 , & V_55 , sizeof( V_55 ) ) < 0 )
return - 1 ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , const T_1 * V_77 ,
T_4 V_56 , T_4 V_57 , int V_78 )
{
T_3 V_55 ;
if ( F_4 ( V_3 , V_78 , & V_55 , sizeof( V_55 ) ) < 0 )
return - 1 ;
F_22 ( & V_55 , V_56 , V_57 ) ;
if ( ! F_32 ( V_3 , V_78 + sizeof( V_55 ) ) ||
F_33 ( V_3 , V_78 , & V_55 , sizeof( V_55 ) ) < 0 )
return - 1 ;
return 0 ;
}
static void F_35 ( const struct V_23 * V_24 ,
struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
const struct V_79 * V_30 = F_8 ( V_24 ) ;
struct V_2 * V_3 = V_28 -> V_3 ;
const T_1 * V_77 = & V_26 -> V_7 [ V_30 -> V_80 ] ;
int V_4 , V_78 ;
T_4 V_56 , V_57 ;
switch ( V_30 -> V_34 ) {
case V_35 :
if ( ! F_9 ( V_3 ) )
goto V_36;
V_4 = F_2 ( V_3 ) - V_3 -> V_7 ;
break;
case V_37 :
V_4 = F_11 ( V_3 ) ;
break;
case V_38 :
if ( ! V_28 -> V_39 )
goto V_36;
V_4 = V_28 -> V_40 . V_41 ;
break;
default:
F_12 () ;
}
V_78 = V_4 + V_30 -> V_78 ;
V_4 += V_30 -> V_4 ;
if ( ( V_30 -> V_81 == V_82 || V_30 -> V_83 ) &&
( V_30 -> V_34 != V_38 ||
V_3 -> V_73 != V_74 ) ) {
V_56 = F_36 ( V_3 , V_4 , V_30 -> V_5 , 0 ) ;
V_57 = F_37 ( V_77 , V_30 -> V_5 , 0 ) ;
if ( V_30 -> V_81 == V_82 &&
F_34 ( V_3 , V_77 , V_56 , V_57 , V_78 ) )
goto V_36;
if ( V_30 -> V_83 &&
F_31 ( V_28 , V_3 , V_56 , V_57 ) < 0 )
goto V_36;
}
if ( ! F_32 ( V_3 , F_38 ( V_4 + V_30 -> V_5 , 0 ) ) ||
F_33 ( V_3 , V_4 , V_77 , V_30 -> V_5 ) < 0 )
goto V_36;
return;
V_36:
V_26 -> V_42 . V_43 = V_44 ;
}
static int F_39 ( const struct V_45 * V_46 ,
const struct V_23 * V_24 ,
const struct V_47 * const V_48 [] )
{
struct V_79 * V_30 = F_8 ( V_24 ) ;
V_30 -> V_34 = F_14 ( F_15 ( V_48 [ V_49 ] ) ) ;
V_30 -> V_4 = F_14 ( F_15 ( V_48 [ V_50 ] ) ) ;
V_30 -> V_5 = F_14 ( F_15 ( V_48 [ V_51 ] ) ) ;
V_30 -> V_80 = F_16 ( V_48 [ V_84 ] ) ;
if ( V_48 [ V_85 ] )
V_30 -> V_81 =
F_14 ( F_15 ( V_48 [ V_85 ] ) ) ;
if ( V_48 [ V_86 ] )
V_30 -> V_78 =
F_14 ( F_15 ( V_48 [ V_86 ] ) ) ;
if ( V_48 [ V_87 ] ) {
T_1 V_88 ;
V_88 = F_14 ( F_15 ( V_48 [ V_87 ] ) ) ;
if ( V_88 & ~ V_89 )
return - V_90 ;
V_30 -> V_83 = V_88 ;
}
switch ( V_30 -> V_81 ) {
case V_91 :
case V_82 :
break;
default:
return - V_92 ;
}
return F_40 ( V_30 -> V_80 , V_30 -> V_5 ) ;
}
static int F_41 ( struct V_2 * V_3 , const struct V_23 * V_24 )
{
const struct V_79 * V_30 = F_8 ( V_24 ) ;
if ( F_19 ( V_3 , V_84 , V_30 -> V_80 ) ||
F_20 ( V_3 , V_49 , F_21 ( V_30 -> V_34 ) ) ||
F_20 ( V_3 , V_50 , F_21 ( V_30 -> V_4 ) ) ||
F_20 ( V_3 , V_51 , F_21 ( V_30 -> V_5 ) ) ||
F_20 ( V_3 , V_85 , F_21 ( V_30 -> V_81 ) ) ||
F_20 ( V_3 , V_86 ,
F_21 ( V_30 -> V_78 ) ) ||
F_20 ( V_3 , V_87 , F_21 ( V_30 -> V_83 ) ) )
goto V_54;
return 0 ;
V_54:
return - 1 ;
}
static const struct V_93 *
F_42 ( const struct V_45 * V_46 ,
const struct V_47 * const V_48 [] )
{
enum V_94 V_34 ;
unsigned int V_4 , V_5 ;
if ( V_48 [ V_49 ] == NULL ||
V_48 [ V_50 ] == NULL ||
V_48 [ V_51 ] == NULL )
return F_43 ( - V_90 ) ;
V_34 = F_14 ( F_15 ( V_48 [ V_49 ] ) ) ;
switch ( V_34 ) {
case V_35 :
case V_37 :
case V_38 :
break;
default:
return F_43 ( - V_92 ) ;
}
if ( V_48 [ V_84 ] != NULL ) {
if ( V_48 [ V_52 ] != NULL )
return F_43 ( - V_90 ) ;
return & V_95 ;
}
if ( V_48 [ V_52 ] == NULL )
return F_43 ( - V_90 ) ;
V_4 = F_14 ( F_15 ( V_48 [ V_50 ] ) ) ;
V_5 = F_14 ( F_15 ( V_48 [ V_51 ] ) ) ;
if ( V_5 <= 4 && F_44 ( V_5 ) && F_45 ( V_4 , V_5 ) &&
V_34 != V_35 )
return & V_96 ;
else
return & V_97 ;
}
