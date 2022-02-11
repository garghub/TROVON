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
if ( V_2 -> V_10 ) {
F_5 ( V_2 , V_53 ) ;
return V_53 ;
}
V_29 = (struct V_47 * ) V_2 -> V_54 . V_55 ;
V_2 -> V_56 ++ ;
V_2 -> V_12 = V_46 ;
V_2 -> V_13 = V_27 ;
V_2 -> V_10 = V_57 ;
F_18 ( V_29 -> V_32 , V_58 , V_59 ,
F_19 ( V_2 -> V_50 ) ) ;
F_20 ( V_2 -> V_50 , & V_2 -> V_54 ) ;
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
if ( V_2 -> V_10 ) {
F_5 ( V_2 , V_53 ) ;
return V_53 ;
}
V_29 = (struct V_47 * ) V_2 -> V_54 . V_55 ;
V_2 -> V_56 ++ ;
V_2 -> V_12 = V_46 ;
V_2 -> V_13 = V_27 ;
V_2 -> V_10 = V_57 ;
F_18 ( V_29 -> V_32 , V_58 , V_60 ,
F_19 ( V_2 -> V_50 ) ) ;
F_20 ( V_2 -> V_50 , & V_2 -> V_54 ) ;
return V_16 ;
}
T_3
F_22 ( struct V_1 * V_2 , union V_3 * V_4 ,
T_7 V_46 , void * V_27 )
{
struct V_61 * V_29 ;
if ( ! F_17 ( V_2 -> V_50 ) ) {
F_5 ( V_2 , V_52 ) ;
return V_52 ;
}
if ( V_2 -> V_15 ) {
F_5 ( V_2 , V_53 ) ;
return V_53 ;
}
V_29 = (struct V_61 * ) V_2 -> V_62 . V_55 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_25 = V_46 ;
V_2 -> V_26 = V_27 ;
V_2 -> V_15 = V_57 ;
F_23 ( V_29 -> V_63 , V_2 -> V_19 . V_45 ) ;
F_18 ( V_29 -> V_32 , V_58 , V_64 ,
F_19 ( V_2 -> V_50 ) ) ;
F_20 ( V_2 -> V_50 , & V_2 -> V_62 ) ;
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
F_5 ( V_2 , V_53 ) ;
return V_53 ;
}
V_29 = (struct V_47 * ) V_2 -> V_62 . V_55 ;
V_2 -> V_25 = V_46 ;
V_2 -> V_26 = V_27 ;
V_2 -> V_15 = V_57 ;
F_18 ( V_29 -> V_32 , V_58 , V_65 ,
F_19 ( V_2 -> V_50 ) ) ;
F_20 ( V_2 -> V_50 , & V_2 -> V_62 ) ;
return V_16 ;
}
void
F_25 ( void * V_66 , enum V_67 V_68 )
{
struct V_1 * V_2 = (struct V_1 * ) V_66 ;
switch ( V_68 ) {
case V_69 :
case V_70 :
if ( V_2 -> V_15 ) {
if ( V_2 -> V_25 )
V_2 -> V_25 ( V_2 -> V_26 ,
V_71 ) ;
V_2 -> V_25 = NULL ;
V_2 -> V_15 = V_11 ;
}
if ( V_2 -> V_10 ) {
if ( V_2 -> V_12 )
V_2 -> V_12 ( V_2 -> V_13 ,
V_71 ) ;
V_2 -> V_12 = NULL ;
V_2 -> V_10 = V_11 ;
}
break;
default:
break;
}
}
void
F_26 ( struct V_1 * V_2 , struct V_72 * V_50 ,
void * V_73 , struct V_74 * V_75 )
{
struct V_17 V_18 ;
F_11 ( ! V_2 ) ;
V_2 -> V_73 = V_73 ;
V_2 -> V_50 = V_50 ;
V_2 -> V_75 = V_75 ;
V_2 -> V_15 = V_11 ;
V_2 -> V_10 = V_11 ;
V_2 -> V_25 = NULL ;
V_2 -> V_12 = NULL ;
V_2 -> V_48 = V_11 ;
F_27 ( V_2 -> V_50 , V_58 , F_10 , V_2 ) ;
F_28 ( & V_2 -> V_76 ) ;
F_29 ( & V_2 -> V_76 , F_25 , V_2 ) ;
F_30 ( & V_2 -> V_76 . V_77 , & V_2 -> V_50 -> V_78 ) ;
F_8 ( & V_18 ) ;
V_2 -> V_24 = V_18 . V_23 ;
F_5 ( V_2 , 0 ) ;
}
static void
F_31 ( struct V_79 * V_80 , T_3 V_9 )
{
struct V_81 * V_82 = & V_80 -> V_83 -> V_84 ;
V_80 -> V_85 = V_9 ;
F_5 ( V_80 , 0 ) ;
if ( V_9 == V_16 ) {
F_5 ( V_80 , 0 ) ;
memcpy ( V_80 -> V_83 , V_80 -> V_86 . V_20 ,
sizeof( struct V_87 ) ) ;
V_82 -> V_88 = F_32 ( V_82 -> V_88 ) ;
V_82 -> V_89 =
F_32 ( V_82 -> V_89 ) ;
}
V_80 -> V_90 = V_11 ;
if ( V_80 -> V_46 . V_91 ) {
F_5 ( V_80 , 0 ) ;
V_80 -> V_46 . V_91 ( V_80 -> V_46 . V_92 , V_9 ) ;
}
}
static void
F_33 ( struct V_79 * V_80 , T_3 V_9 )
{
T_1 * V_93 ;
int V_8 ;
V_80 -> V_94 = V_9 ;
F_5 ( V_80 , 0 ) ;
if ( V_9 == V_16 ) {
F_5 ( V_80 , 0 ) ;
memcpy ( V_80 -> V_4 , V_80 -> V_19 . V_20 ,
sizeof( struct V_95 ) ) ;
V_93 = ( T_1 * ) V_80 -> V_4 ;
for ( V_8 = 0 ; V_8 < ( sizeof( struct V_95 ) /
sizeof( T_1 ) ) ; V_8 ++ )
V_93 [ V_8 ] = F_34 ( V_93 [ V_8 ] ) ;
}
V_80 -> V_96 = V_11 ;
F_5 ( V_80 , 0 ) ;
if ( V_80 -> V_46 . V_97 ) {
F_5 ( V_80 , 0 ) ;
V_80 -> V_46 . V_97 ( V_80 -> V_46 . V_98 , V_9 ) ;
}
}
static void
F_35 ( struct V_79 * V_80 , T_3 V_9 )
{
V_80 -> V_99 = V_9 ;
V_80 -> V_100 = V_11 ;
if ( V_80 -> V_46 . V_101 )
V_80 -> V_46 . V_101 ( V_80 -> V_46 . V_102 , V_9 ) ;
}
T_1
F_36 ( void )
{
return F_13 ( sizeof( struct V_87 ) , V_42 ) +
F_13 ( sizeof( struct V_95 ) , V_42 ) ;
}
void
F_37 ( struct V_79 * V_80 , T_4 * V_43 , T_5 V_44 )
{
V_80 -> V_86 . V_20 = V_43 ;
V_80 -> V_86 . V_45 = V_44 ;
V_80 -> V_19 . V_20 = V_43 + F_13 (
sizeof( struct V_87 ) , V_42 ) ;
V_80 -> V_19 . V_45 = V_44 + F_13 (
sizeof( struct V_87 ) , V_42 ) ;
V_80 -> V_83 = (struct V_87 * ) V_43 ;
V_80 -> V_4 = (struct V_95 * ) ( V_43 + F_13 (
sizeof( struct V_87 ) , V_42 ) ) ;
}
T_3
F_38 ( struct V_79 * V_80 , struct V_87 * V_83 ,
T_8 V_46 , void * V_27 )
{
struct V_103 * V_104 ;
F_11 ( ( V_80 == NULL ) || ( V_80 -> V_50 == NULL ) ) ;
F_5 ( V_80 , 0 ) ;
if ( ! F_17 ( V_80 -> V_50 ) ) {
F_5 ( V_80 , 0 ) ;
return V_52 ;
}
if ( V_80 -> V_90 == V_57 ) {
F_5 ( V_80 , 0 ) ;
return V_53 ;
}
V_80 -> V_90 = V_57 ;
V_104 = (struct V_103 * ) V_80 -> V_105 . V_55 ;
V_80 -> V_83 = V_83 ;
V_80 -> V_46 . V_91 = V_46 ;
V_80 -> V_46 . V_92 = V_27 ;
F_18 ( V_104 -> V_32 , V_106 , V_107 ,
F_19 ( V_80 -> V_50 ) ) ;
F_23 ( V_104 -> V_63 , V_80 -> V_86 . V_45 ) ;
F_20 ( V_80 -> V_50 , & V_80 -> V_105 ) ;
return V_16 ;
}
T_3
F_39 ( struct V_79 * V_80 , struct V_95 * V_4 ,
T_9 V_46 , void * V_27 )
{
struct V_103 * V_104 ;
F_11 ( ( V_80 == NULL ) || ( V_80 -> V_50 == NULL ) ) ;
if ( ! F_17 ( V_80 -> V_50 ) ) {
F_5 ( V_80 , 0 ) ;
return V_52 ;
}
if ( V_80 -> V_96 == V_57 ) {
F_5 ( V_80 , 0 ) ;
return V_53 ;
}
V_80 -> V_96 = V_57 ;
V_104 = (struct V_103 * ) V_80 -> V_108 . V_55 ;
V_80 -> V_4 = V_4 ;
V_80 -> V_46 . V_97 = V_46 ;
V_80 -> V_46 . V_98 = V_27 ;
F_18 ( V_104 -> V_32 , V_106 , V_109 ,
F_19 ( V_80 -> V_50 ) ) ;
F_23 ( V_104 -> V_63 , V_80 -> V_19 . V_45 ) ;
F_20 ( V_80 -> V_50 , & V_80 -> V_108 ) ;
return V_16 ;
}
T_3
F_40 ( struct V_79 * V_80 ,
T_10 V_46 , void * V_27 )
{
struct V_110 * V_104 ;
F_11 ( ( V_80 == NULL ) || ( V_80 -> V_50 == NULL ) ) ;
if ( ! F_17 ( V_80 -> V_50 ) ) {
F_5 ( V_80 , 0 ) ;
return V_52 ;
}
if ( V_80 -> V_100 == V_57 ) {
F_5 ( V_80 , 0 ) ;
return V_53 ;
}
V_80 -> V_100 = V_57 ;
V_104 = (struct V_110 * ) V_80 -> V_111 . V_55 ;
V_80 -> V_46 . V_101 = V_46 ;
V_80 -> V_46 . V_102 = V_27 ;
F_18 ( V_104 -> V_32 , V_106 , V_112 ,
F_19 ( V_80 -> V_50 ) ) ;
F_20 ( V_80 -> V_50 , & V_80 -> V_111 ) ;
return V_16 ;
}
void
F_41 ( void * V_27 , struct V_28 * V_29 )
{
union V_113 * V_55 ;
struct V_114 * V_115 ;
struct V_79 * V_80 = (struct V_79 * ) V_27 ;
V_55 = (union V_113 * ) V_29 ;
V_115 = (struct V_114 * ) V_29 ;
F_5 ( V_80 , V_55 -> V_32 . V_33 ) ;
switch ( V_55 -> V_32 . V_33 ) {
case V_116 :
F_5 ( V_80 , V_115 -> V_117 ) ;
F_31 ( V_80 , V_115 -> V_117 ) ;
break;
case V_118 :
F_33 ( V_80 , V_115 -> V_117 ) ;
break;
case V_119 :
F_35 ( V_80 , V_115 -> V_117 ) ;
break;
default:
F_11 ( 1 ) ;
}
}
void
F_42 ( void * V_66 , enum V_67 V_68 )
{
struct V_79 * V_80 = (struct V_79 * ) V_66 ;
F_5 ( V_80 , V_68 ) ;
switch ( V_68 ) {
case V_69 :
case V_70 :
if ( V_80 -> V_90 == V_57 ) {
V_80 -> V_85 = V_71 ;
V_80 -> V_90 = V_11 ;
if ( V_80 -> V_46 . V_91 ) {
V_80 -> V_46 . V_91 (
V_80 -> V_46 . V_92 ,
V_71 ) ;
}
}
if ( V_80 -> V_96 == V_57 ) {
V_80 -> V_94 = V_71 ;
V_80 -> V_96 = V_11 ;
if ( V_80 -> V_46 . V_97 ) {
V_80 -> V_46 . V_97 (
V_80 -> V_46 . V_98 ,
V_71 ) ;
}
}
if ( V_80 -> V_100 == V_57 ) {
V_80 -> V_99 = V_71 ;
V_80 -> V_100 = V_11 ;
if ( V_80 -> V_46 . V_101 ) {
V_80 -> V_46 . V_101 (
V_80 -> V_46 . V_102 ,
V_71 ) ;
}
}
break;
default:
break;
}
}
void
F_43 ( struct V_79 * V_80 , struct V_72 * V_50 ,
void * V_73 )
{
F_11 ( V_80 == NULL ) ;
V_80 -> V_73 = V_73 ;
V_80 -> V_50 = V_50 ;
F_27 ( V_80 -> V_50 , V_106 , F_41 , V_80 ) ;
F_28 ( & V_80 -> V_76 ) ;
F_29 ( & V_80 -> V_76 , F_42 , V_80 ) ;
F_30 ( & V_80 -> V_76 . V_77 , & V_80 -> V_50 -> V_78 ) ;
}
