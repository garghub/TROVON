static void
F_1 ( struct V_1 * V_2 , union V_3 * V_4 )
{
T_1 * V_5 = ( T_1 * ) V_4 ;
T_2 V_6 , V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < sizeof( union V_3 ) / sizeof( T_1 ) ;
V_8 += 2 ) {
V_6 = V_5 [ V_8 ] ;
V_7 = V_5 [ V_8 + 1 ] ;
#ifdef F_2
V_5 [ V_8 ] = F_3 ( V_6 ) ;
V_5 [ V_8 + 1 ] = F_3 ( V_7 ) ;
#else
V_5 [ V_8 ] = F_3 ( V_7 ) ;
V_5 [ V_8 + 1 ] = F_3 ( V_6 ) ;
#endif
}
}
static void
F_4 ( struct V_1 * V_2 , T_3 V_9 )
{
F_5 ( V_2 , V_9 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 ( V_2 -> V_13 , V_9 ) ;
}
static void
F_6 ( struct V_1 * V_2 , T_3 V_9 )
{
F_5 ( V_2 , V_9 ) ;
V_2 -> V_10 = V_11 ;
V_2 -> V_12 ( V_2 -> V_13 , V_9 ) ;
}
static void
F_7 ( struct V_1 * V_2 , T_3 V_9 )
{
V_2 -> V_14 = V_9 ;
V_2 -> V_15 = V_11 ;
if ( V_9 == V_16 ) {
struct V_17 V_18 ;
memcpy ( V_2 -> V_4 , V_2 -> V_19 . V_20 ,
sizeof( union V_3 ) ) ;
F_1 ( V_2 , V_2 -> V_4 ) ;
F_8 ( & V_18 ) ;
V_2 -> V_4 -> V_21 . V_22 = V_18 . V_23 - V_2 -> V_24 ;
}
if ( V_2 -> V_25 ) {
V_2 -> V_25 ( V_2 -> V_26 , V_9 ) ;
V_2 -> V_25 = NULL ;
}
}
static void
F_9 ( struct V_1 * V_2 , T_3 V_9 )
{
struct V_17 V_18 ;
V_2 -> V_14 = V_9 ;
V_2 -> V_15 = V_11 ;
F_8 ( & V_18 ) ;
V_2 -> V_24 = V_18 . V_23 ;
if ( V_2 -> V_25 ) {
V_2 -> V_25 ( V_2 -> V_26 , V_9 ) ;
V_2 -> V_25 = NULL ;
}
}
static void
F_10 ( void * V_27 , struct V_28 * V_29 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
union V_30 * V_31 ;
V_31 = (union V_30 * ) V_29 ;
F_5 ( V_2 , V_29 -> V_32 . V_33 ) ;
switch ( V_29 -> V_32 . V_33 ) {
case V_34 :
if ( V_2 -> V_10 == V_11 )
break;
F_4 ( V_2 , V_31 -> V_35 . V_9 ) ;
break;
case V_36 :
if ( V_2 -> V_10 == V_11 )
break;
F_6 ( V_2 , V_31 -> V_37 . V_9 ) ;
break;
case V_38 :
if ( V_2 -> V_15 == V_11 )
break;
F_7 ( V_2 , V_31 -> V_39 . V_9 ) ;
break;
case V_40 :
if ( V_2 -> V_15 == V_11 )
break;
F_9 ( V_2 , V_31 -> V_41 . V_9 ) ;
break;
default:
F_11 ( 1 ) ;
}
}
T_1
F_12 ( void )
{
return F_13 ( sizeof( union V_3 ) , V_42 ) ;
}
void
F_14 ( struct V_1 * V_2 , T_4 * V_43 , T_5 V_44 )
{
V_2 -> V_19 . V_20 = V_43 ;
V_2 -> V_19 . V_45 = V_44 ;
}
T_3
F_15 ( struct V_1 * V_2 , T_6 V_46 ,
void * V_27 )
{
struct V_47 * V_29 ;
if ( V_2 -> V_48 ) {
F_5 ( V_2 , V_49 ) ;
return V_49 ;
}
if ( F_16 ( V_2 -> V_50 ) ) {
F_5 ( V_2 , V_51 ) ;
return V_51 ;
}
if ( ! F_17 ( V_2 -> V_50 ) ) {
F_5 ( V_2 , V_52 ) ;
return V_52 ;
}
if ( V_2 -> V_53 ) {
F_5 ( V_2 , V_54 ) ;
return V_54 ;
}
if ( V_2 -> V_10 ) {
F_5 ( V_2 , V_55 ) ;
return V_55 ;
}
V_29 = (struct V_47 * ) V_2 -> V_56 . V_57 ;
V_2 -> V_58 ++ ;
V_2 -> V_12 = V_46 ;
V_2 -> V_13 = V_27 ;
V_2 -> V_10 = V_59 ;
F_18 ( V_29 -> V_32 , V_60 , V_61 ,
F_19 ( V_2 -> V_50 ) ) ;
F_20 ( V_2 -> V_50 , & V_2 -> V_56 ) ;
return V_16 ;
}
T_3
F_21 ( struct V_1 * V_2 , T_6 V_46 ,
void * V_27 )
{
struct V_47 * V_29 ;
if ( V_2 -> V_48 ) {
F_5 ( V_2 , V_49 ) ;
return V_49 ;
}
if ( F_16 ( V_2 -> V_50 ) ) {
F_5 ( V_2 , V_51 ) ;
return V_51 ;
}
if ( ! F_17 ( V_2 -> V_50 ) ) {
F_5 ( V_2 , V_52 ) ;
return V_52 ;
}
if ( V_2 -> V_53 ) {
F_5 ( V_2 , V_54 ) ;
return V_54 ;
}
if ( V_2 -> V_10 ) {
F_5 ( V_2 , V_55 ) ;
return V_55 ;
}
V_29 = (struct V_47 * ) V_2 -> V_56 . V_57 ;
V_2 -> V_58 ++ ;
V_2 -> V_12 = V_46 ;
V_2 -> V_13 = V_27 ;
V_2 -> V_10 = V_59 ;
F_18 ( V_29 -> V_32 , V_60 , V_62 ,
F_19 ( V_2 -> V_50 ) ) ;
F_20 ( V_2 -> V_50 , & V_2 -> V_56 ) ;
return V_16 ;
}
T_3
F_22 ( struct V_1 * V_2 , union V_3 * V_4 ,
T_7 V_46 , void * V_27 )
{
struct V_63 * V_29 ;
if ( ! F_17 ( V_2 -> V_50 ) ) {
F_5 ( V_2 , V_52 ) ;
return V_52 ;
}
if ( V_2 -> V_15 ) {
F_5 ( V_2 , V_55 ) ;
return V_55 ;
}
V_29 = (struct V_63 * ) V_2 -> V_64 . V_57 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_25 = V_46 ;
V_2 -> V_26 = V_27 ;
V_2 -> V_15 = V_59 ;
F_23 ( V_29 -> V_65 , V_2 -> V_19 . V_45 ) ;
F_18 ( V_29 -> V_32 , V_60 , V_66 ,
F_19 ( V_2 -> V_50 ) ) ;
F_20 ( V_2 -> V_50 , & V_2 -> V_64 ) ;
return V_16 ;
}
T_3
F_24 ( struct V_1 * V_2 , T_7 V_46 ,
void * V_27 )
{
struct V_47 * V_29 ;
if ( ! F_17 ( V_2 -> V_50 ) ) {
F_5 ( V_2 , V_52 ) ;
return V_52 ;
}
if ( V_2 -> V_15 ) {
F_5 ( V_2 , V_55 ) ;
return V_55 ;
}
V_29 = (struct V_47 * ) V_2 -> V_64 . V_57 ;
V_2 -> V_25 = V_46 ;
V_2 -> V_26 = V_27 ;
V_2 -> V_15 = V_59 ;
F_18 ( V_29 -> V_32 , V_60 , V_67 ,
F_19 ( V_2 -> V_50 ) ) ;
F_20 ( V_2 -> V_50 , & V_2 -> V_64 ) ;
return V_16 ;
}
void
F_25 ( void * V_68 , enum V_69 V_70 )
{
struct V_1 * V_2 = (struct V_1 * ) V_68 ;
switch ( V_70 ) {
case V_71 :
case V_72 :
if ( V_2 -> V_15 ) {
if ( V_2 -> V_25 )
V_2 -> V_25 ( V_2 -> V_26 ,
V_73 ) ;
V_2 -> V_25 = NULL ;
V_2 -> V_15 = V_11 ;
}
if ( V_2 -> V_10 ) {
if ( V_2 -> V_12 )
V_2 -> V_12 ( V_2 -> V_13 ,
V_73 ) ;
V_2 -> V_12 = NULL ;
V_2 -> V_10 = V_11 ;
}
if ( V_2 -> V_53 )
F_26 ( V_2 , V_11 ) ;
break;
default:
break;
}
}
void
F_27 ( struct V_1 * V_2 , struct V_74 * V_50 ,
void * V_75 , struct V_76 * V_77 )
{
struct V_17 V_18 ;
F_11 ( ! V_2 ) ;
V_2 -> V_75 = V_75 ;
V_2 -> V_50 = V_50 ;
V_2 -> V_77 = V_77 ;
V_2 -> V_15 = V_11 ;
V_2 -> V_10 = V_11 ;
V_2 -> V_25 = NULL ;
V_2 -> V_12 = NULL ;
V_2 -> V_48 = V_11 ;
V_2 -> V_53 = V_11 ;
F_28 ( V_2 -> V_50 , V_60 , F_10 , V_2 ) ;
F_29 ( & V_2 -> V_78 ) ;
F_30 ( & V_2 -> V_78 , F_25 , V_2 ) ;
F_31 ( & V_2 -> V_78 . V_79 , & V_2 -> V_50 -> V_80 ) ;
F_8 ( & V_18 ) ;
V_2 -> V_24 = V_18 . V_23 ;
F_5 ( V_2 , 0 ) ;
}
void
F_26 ( struct V_1 * V_2 , T_8 V_81 )
{
V_2 -> V_53 = V_81 ;
}
static void
F_32 ( struct V_82 * V_83 , T_3 V_9 )
{
struct V_84 * V_85 = & V_83 -> V_86 -> V_87 ;
V_83 -> V_88 = V_9 ;
F_5 ( V_83 , 0 ) ;
if ( V_9 == V_16 ) {
F_5 ( V_83 , 0 ) ;
memcpy ( V_83 -> V_86 , V_83 -> V_89 . V_20 ,
sizeof( struct V_90 ) ) ;
V_85 -> V_91 = F_33 ( V_85 -> V_91 ) ;
V_85 -> V_92 =
F_33 ( V_85 -> V_92 ) ;
}
V_83 -> V_93 = V_11 ;
if ( V_83 -> V_46 . V_94 ) {
F_5 ( V_83 , 0 ) ;
V_83 -> V_46 . V_94 ( V_83 -> V_46 . V_95 , V_9 ) ;
}
}
static void
F_34 ( struct V_82 * V_83 , T_3 V_9 )
{
T_1 * V_96 ;
int V_8 ;
V_83 -> V_97 = V_9 ;
F_5 ( V_83 , 0 ) ;
if ( V_9 == V_16 ) {
F_5 ( V_83 , 0 ) ;
memcpy ( V_83 -> V_4 , V_83 -> V_19 . V_20 ,
sizeof( struct V_98 ) ) ;
V_96 = ( T_1 * ) V_83 -> V_4 ;
for ( V_8 = 0 ; V_8 < ( sizeof( struct V_98 ) /
sizeof( T_1 ) ) ; V_8 ++ )
V_96 [ V_8 ] = F_35 ( V_96 [ V_8 ] ) ;
}
V_83 -> V_99 = V_11 ;
F_5 ( V_83 , 0 ) ;
if ( V_83 -> V_46 . V_100 ) {
F_5 ( V_83 , 0 ) ;
V_83 -> V_46 . V_100 ( V_83 -> V_46 . V_101 , V_9 ) ;
}
}
static void
F_36 ( struct V_82 * V_83 , T_3 V_9 )
{
V_83 -> V_102 = V_9 ;
V_83 -> V_103 = V_11 ;
if ( V_83 -> V_46 . V_104 )
V_83 -> V_46 . V_104 ( V_83 -> V_46 . V_105 , V_9 ) ;
}
T_1
F_37 ( void )
{
return F_13 ( sizeof( struct V_90 ) , V_42 ) +
F_13 ( sizeof( struct V_98 ) , V_42 ) ;
}
void
F_38 ( struct V_82 * V_83 , T_4 * V_43 , T_5 V_44 )
{
V_83 -> V_89 . V_20 = V_43 ;
V_83 -> V_89 . V_45 = V_44 ;
V_83 -> V_19 . V_20 = V_43 + F_13 (
sizeof( struct V_90 ) , V_42 ) ;
V_83 -> V_19 . V_45 = V_44 + F_13 (
sizeof( struct V_90 ) , V_42 ) ;
V_83 -> V_86 = (struct V_90 * ) V_43 ;
V_83 -> V_4 = (struct V_98 * ) ( V_43 + F_13 (
sizeof( struct V_90 ) , V_42 ) ) ;
}
T_3
F_39 ( struct V_82 * V_83 , struct V_90 * V_86 ,
T_9 V_46 , void * V_27 )
{
struct V_106 * V_107 ;
F_11 ( ( V_83 == NULL ) || ( V_83 -> V_50 == NULL ) ) ;
F_5 ( V_83 , 0 ) ;
if ( ! F_17 ( V_83 -> V_50 ) ) {
F_5 ( V_83 , 0 ) ;
return V_52 ;
}
if ( V_83 -> V_93 == V_59 ) {
F_5 ( V_83 , 0 ) ;
return V_55 ;
}
V_83 -> V_93 = V_59 ;
V_107 = (struct V_106 * ) V_83 -> V_108 . V_57 ;
V_83 -> V_86 = V_86 ;
V_83 -> V_46 . V_94 = V_46 ;
V_83 -> V_46 . V_95 = V_27 ;
F_18 ( V_107 -> V_32 , V_109 , V_110 ,
F_19 ( V_83 -> V_50 ) ) ;
F_23 ( V_107 -> V_65 , V_83 -> V_89 . V_45 ) ;
F_20 ( V_83 -> V_50 , & V_83 -> V_108 ) ;
return V_16 ;
}
T_3
F_40 ( struct V_82 * V_83 , struct V_98 * V_4 ,
T_10 V_46 , void * V_27 )
{
struct V_106 * V_107 ;
F_11 ( ( V_83 == NULL ) || ( V_83 -> V_50 == NULL ) ) ;
if ( ! F_17 ( V_83 -> V_50 ) ) {
F_5 ( V_83 , 0 ) ;
return V_52 ;
}
if ( V_83 -> V_99 == V_59 ) {
F_5 ( V_83 , 0 ) ;
return V_55 ;
}
V_83 -> V_99 = V_59 ;
V_107 = (struct V_106 * ) V_83 -> V_111 . V_57 ;
V_83 -> V_4 = V_4 ;
V_83 -> V_46 . V_100 = V_46 ;
V_83 -> V_46 . V_101 = V_27 ;
F_18 ( V_107 -> V_32 , V_109 , V_112 ,
F_19 ( V_83 -> V_50 ) ) ;
F_23 ( V_107 -> V_65 , V_83 -> V_19 . V_45 ) ;
F_20 ( V_83 -> V_50 , & V_83 -> V_111 ) ;
return V_16 ;
}
T_3
F_41 ( struct V_82 * V_83 ,
T_11 V_46 , void * V_27 )
{
struct V_113 * V_107 ;
F_11 ( ( V_83 == NULL ) || ( V_83 -> V_50 == NULL ) ) ;
if ( ! F_17 ( V_83 -> V_50 ) ) {
F_5 ( V_83 , 0 ) ;
return V_52 ;
}
if ( V_83 -> V_103 == V_59 ) {
F_5 ( V_83 , 0 ) ;
return V_55 ;
}
V_83 -> V_103 = V_59 ;
V_107 = (struct V_113 * ) V_83 -> V_114 . V_57 ;
V_83 -> V_46 . V_104 = V_46 ;
V_83 -> V_46 . V_105 = V_27 ;
F_18 ( V_107 -> V_32 , V_109 , V_115 ,
F_19 ( V_83 -> V_50 ) ) ;
F_20 ( V_83 -> V_50 , & V_83 -> V_114 ) ;
return V_16 ;
}
void
F_42 ( void * V_27 , struct V_28 * V_29 )
{
union V_116 * V_57 ;
struct V_117 * V_118 ;
struct V_82 * V_83 = (struct V_82 * ) V_27 ;
V_57 = (union V_116 * ) V_29 ;
V_118 = (struct V_117 * ) V_29 ;
F_5 ( V_83 , V_57 -> V_32 . V_33 ) ;
switch ( V_57 -> V_32 . V_33 ) {
case V_119 :
F_5 ( V_83 , V_118 -> V_120 ) ;
F_32 ( V_83 , V_118 -> V_120 ) ;
break;
case V_121 :
F_34 ( V_83 , V_118 -> V_120 ) ;
break;
case V_122 :
F_36 ( V_83 , V_118 -> V_120 ) ;
break;
default:
F_11 ( 1 ) ;
}
}
void
F_43 ( void * V_68 , enum V_69 V_70 )
{
struct V_82 * V_83 = (struct V_82 * ) V_68 ;
F_5 ( V_83 , V_70 ) ;
switch ( V_70 ) {
case V_71 :
case V_72 :
if ( V_83 -> V_93 == V_59 ) {
V_83 -> V_88 = V_73 ;
V_83 -> V_93 = V_11 ;
if ( V_83 -> V_46 . V_94 ) {
V_83 -> V_46 . V_94 (
V_83 -> V_46 . V_95 ,
V_73 ) ;
}
}
if ( V_83 -> V_99 == V_59 ) {
V_83 -> V_97 = V_73 ;
V_83 -> V_99 = V_11 ;
if ( V_83 -> V_46 . V_100 ) {
V_83 -> V_46 . V_100 (
V_83 -> V_46 . V_101 ,
V_73 ) ;
}
}
if ( V_83 -> V_103 == V_59 ) {
V_83 -> V_102 = V_73 ;
V_83 -> V_103 = V_11 ;
if ( V_83 -> V_46 . V_104 ) {
V_83 -> V_46 . V_104 (
V_83 -> V_46 . V_105 ,
V_73 ) ;
}
}
break;
default:
break;
}
}
void
F_44 ( struct V_82 * V_83 , struct V_74 * V_50 ,
void * V_75 )
{
F_11 ( V_83 == NULL ) ;
V_83 -> V_75 = V_75 ;
V_83 -> V_50 = V_50 ;
F_28 ( V_83 -> V_50 , V_109 , F_42 , V_83 ) ;
F_29 ( & V_83 -> V_78 ) ;
F_30 ( & V_83 -> V_78 , F_43 , V_83 ) ;
F_31 ( & V_83 -> V_78 . V_79 , & V_83 -> V_50 -> V_80 ) ;
}
