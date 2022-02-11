static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
while ( ! F_2 ( & V_2 -> V_11 ) ) {
F_3 ( & V_2 -> V_11 , & V_4 ) ;
F_4 ( & V_4 -> V_12 ) ;
F_5 ( V_4 , V_13 ) ;
}
}
static void
F_6 ( struct V_1 * V_2 , enum V_14 V_15 )
{
switch ( V_15 ) {
case V_16 :
F_7 ( V_2 , V_17 ) ;
break;
case V_18 :
case V_19 :
break;
case V_20 :
V_2 -> V_7 |= V_21 ;
break;
default:
F_8 ( V_15 ) ;
}
}
static void
F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_22 -> V_23 ) ;
}
static void
V_17 ( struct V_1 * V_2 , enum V_14 V_15 )
{
switch ( V_15 ) {
case V_18 :
case V_19 :
F_7 ( V_2 , F_6 ) ;
break;
case V_20 :
V_2 -> V_7 |= V_21 ;
break;
case V_24 :
if ( V_2 -> V_7 & V_21 ) {
V_2 -> V_7 &= ~ V_21 ;
F_7 ( V_2 , V_25 ) ;
} else
F_7 ( V_2 , V_26 ) ;
break;
default:
F_8 ( V_15 ) ;
}
}
static void
F_11 ( struct V_1 * V_2 )
{
}
static void
V_26 ( struct V_1 * V_2 , enum V_14 V_15 )
{
switch ( V_15 ) {
case V_18 :
case V_19 :
F_7 ( V_2 , F_6 ) ;
break;
case V_20 :
F_7 ( V_2 , V_25 ) ;
break;
default:
F_8 ( V_15 ) ;
}
}
static void
F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
}
static void
V_25 ( struct V_1 * V_2 , enum V_14 V_15 )
{
switch ( V_15 ) {
case V_18 :
case V_19 :
F_7 ( V_2 , F_6 ) ;
break;
case V_20 :
V_2 -> V_7 |= V_21 ;
break;
case V_27 :
if ( V_2 -> V_7 & V_21 ) {
V_2 -> V_7 &= ~ V_21 ;
F_7 ( V_2 , V_25 ) ;
} else
F_7 ( V_2 , V_26 ) ;
break;
default:
F_8 ( V_15 ) ;
}
}
static void
F_14 ( void * V_28 )
{
struct V_1 * V_2 = (struct V_1 * ) V_28 ;
F_15 ( V_2 , V_27 ) ;
}
static void
F_13 ( struct V_1 * V_2 )
{
struct V_29 * V_30 =
(struct V_29 * ) ( & V_2 -> V_31 . V_32 [ 0 ] ) ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
F_16 ( V_30 -> V_33 , V_34 , V_35 , 0 ) ;
V_30 -> V_33 . V_36 . V_37 = 0 ;
V_30 -> V_38 . V_39 = F_17 ( V_2 -> V_5 ) ;
if ( ! F_18 ( V_2 -> V_22 -> V_40 , & V_2 -> V_31 ,
F_14 , V_2 ) ) {
F_14 ( V_2 ) ;
}
}
static void
F_19 ( struct V_1 * V_2 , struct V_3 * V_41 )
{
T_1 V_42 = V_41 -> V_43 ;
int V_44 = 0 ;
T_1 V_45 ;
T_2 * V_46 , * V_47 ;
V_46 = ( T_2 * ) V_41 -> V_48 ;
V_47 = ( T_2 * ) V_2 -> V_49 . V_50 ;
V_47 += ( V_2 -> V_5 * V_51 ) ;
while ( V_42 ) {
V_45 = ( V_42 < V_51 ) ?
V_42 : V_51 ;
memcpy ( V_47 , V_46 , V_45 ) ;
V_42 -= V_45 ;
V_46 += V_51 ;
F_20 ( V_2 -> V_5 , 1 , V_2 -> V_52 ) ;
V_47 = ( T_2 * ) V_2 -> V_49 . V_50 ;
V_47 += ( V_2 -> V_5 * V_51 ) ;
V_44 ++ ;
}
}
static void
F_21 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_55 * V_30 = (struct V_55 * ) V_54 ;
struct V_3 * V_41 ;
int V_56 = 0 ;
V_2 -> V_6 = F_22 ( V_30 -> V_38 . V_57 ) ;
while ( ! F_2 ( & V_2 -> V_11 ) ) {
V_41 =
(struct V_3 * ) F_23 ( & V_2 -> V_11 ) ;
if ( F_22 ( V_41 -> V_48 -> V_44 ) <=
F_24 ( V_2 ) ) {
F_25 ( & V_41 -> V_12 ) ;
F_19 ( V_2 , V_41 ) ;
V_56 = 1 ;
F_5 ( V_41 , V_58 ) ;
} else {
break;
}
}
if ( V_56 )
F_15 ( V_2 , V_20 ) ;
}
static void
F_26 ( void * V_28 )
{
struct V_1 * V_2 = (struct V_1 * ) V_28 ;
if ( V_2 -> V_10 )
F_27 ( V_2 ) ;
}
static void
F_28 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_59 * V_60 =
(struct V_59 * ) V_54 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = F_22 ( V_60 -> V_9 ) ;
V_2 -> V_10 = F_22 ( V_60 -> V_42 ) ;
F_27 ( V_2 ) ;
}
static void
F_27 ( struct V_1 * V_2 )
{
struct V_61 * V_62 =
(struct V_61 * ) & V_2 -> V_63 . V_32 [ 0 ] ;
int V_64 ;
T_2 * V_49 = ( T_2 * ) V_2 -> V_49 . V_50 ;
memset ( V_62 , 0 , sizeof( struct V_61 ) ) ;
F_16 ( V_62 -> V_33 , V_34 , V_65 , 0 ) ;
V_62 -> V_33 . V_36 . V_37 = F_17 ( V_2 -> V_8 ) ;
V_64 = ( V_2 -> V_10 >= V_66 ) ? V_66 :
V_2 -> V_10 ;
V_49 += V_2 -> V_9 ;
memcpy ( V_62 -> V_67 , V_49 , V_64 ) ;
V_2 -> V_8 ++ ;
V_2 -> V_9 += V_64 ;
V_2 -> V_10 -= V_64 ;
if ( ! F_18 ( V_2 -> V_22 -> V_40 , & V_2 -> V_63 ,
F_26 , V_2 ) ) {
F_26 ( V_2 ) ;
}
}
static void
F_29 ( struct V_1 * V_2 , struct V_68 * V_22 )
{
V_2 -> V_52 = V_69 ;
F_30 ( & V_2 -> V_11 ) ;
V_2 -> V_22 = V_22 ;
F_7 ( V_2 , F_6 ) ;
}
static void
F_31 ( struct V_70 * V_71 )
{
V_71 -> V_5 = 0 ;
V_71 -> V_6 = 0 ;
V_71 -> V_7 = 0 ;
}
static void
F_32 ( struct V_70 * V_71 , enum V_72 V_15 )
{
switch ( V_15 ) {
case V_73 :
F_7 ( V_71 , V_74 ) ;
break;
case V_75 :
case V_76 :
break;
default:
F_8 ( V_15 ) ;
}
}
static void
F_33 ( struct V_70 * V_71 )
{
F_10 ( & V_71 -> V_22 -> V_23 ) ;
}
static void
V_74 ( struct V_70 * V_71 , enum V_72 V_15 )
{
switch ( V_15 ) {
case V_76 :
case V_75 :
F_7 ( V_71 , F_32 ) ;
break;
case V_77 :
F_7 ( V_71 , V_78 ) ;
break;
default:
F_8 ( V_15 ) ;
}
}
static void
F_34 ( struct V_70 * V_71 )
{
}
static void
V_78 ( struct V_70 * V_71 , enum V_72 V_15 )
{
switch ( V_15 ) {
case V_75 :
case V_76 :
F_7 ( V_71 , F_32 ) ;
break;
case V_79 :
F_7 ( V_71 , V_80 ) ;
break;
default:
F_8 ( V_15 ) ;
}
}
static void
F_35 ( struct V_70 * V_71 )
{
if ( ! F_36 ( V_71 -> V_22 -> V_40 ) )
F_37 ( V_71 ) ;
}
static void
V_80 ( struct V_70 * V_71 , enum V_72 V_15 )
{
switch ( V_15 ) {
case V_75 :
case V_76 :
F_7 ( V_71 , F_32 ) ;
break;
case V_79 :
V_71 -> V_7 |= V_81 ;
break;
case V_82 :
if ( V_71 -> V_7 & V_81 ) {
V_71 -> V_7 &= ~ V_81 ;
F_7 ( V_71 , V_80 ) ;
} else
F_7 ( V_71 , V_78 ) ;
break;
default:
F_8 ( V_15 ) ;
}
}
static void
F_38 ( void * V_28 )
{
struct V_70 * V_71 = (struct V_70 * ) V_28 ;
F_15 ( V_71 , V_82 ) ;
}
static void
F_37 ( struct V_70 * V_71 )
{
struct V_29 * V_30 =
(struct V_29 * ) ( & V_71 -> V_31 . V_32 [ 0 ] ) ;
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
F_16 ( V_30 -> V_33 , V_34 , V_83 , 0 ) ;
V_30 -> V_33 . V_36 . V_37 = 0 ;
V_30 -> V_38 . V_84 = F_17 ( V_71 -> V_6 ) ;
if ( ! F_18 ( V_71 -> V_22 -> V_40 , & V_71 -> V_31 ,
F_38 , V_71 ) ) {
F_38 ( V_71 ) ;
}
}
static void
F_39 ( struct V_70 * V_71 , struct V_53 * V_54 )
{
struct V_55 * V_30 = (struct V_55 * ) V_54 ;
struct V_85 * V_86 ;
int V_44 ;
int V_87 ;
T_2 * V_88 ;
V_71 -> V_5 = F_22 ( V_30 -> V_38 . V_89 ) ;
while ( V_71 -> V_6 != V_71 -> V_5 ) {
V_88 = ( T_2 * ) V_71 -> V_49 . V_50 ;
V_88 += ( V_71 -> V_6 * V_90 ) ;
V_86 = (struct V_85 * ) V_88 ;
V_87 = V_86 -> V_91 ;
V_44 = F_22 ( V_86 -> V_44 ) ;
if ( ( V_87 >= V_92 ) || ( V_71 -> V_93 [ V_87 ] . V_94 == NULL ) )
break;
( V_71 -> V_93 [ V_87 ] . V_94 ) ( V_71 -> V_93 [ V_87 ] . V_95 , V_86 ) ;
F_20 ( V_71 -> V_6 , V_44 ,
V_71 -> V_52 ) ;
}
F_15 ( V_71 , V_79 ) ;
}
static void
F_40 ( struct V_70 * V_71 , struct V_68 * V_22 )
{
V_71 -> V_52 = V_96 ;
V_71 -> V_22 = V_22 ;
F_7 ( V_71 , F_32 ) ;
}
static void
F_41 ( struct V_68 * V_22 ,
struct V_53 * V_54 )
{
F_15 ( & V_22 -> V_2 , V_24 ) ;
F_15 ( & V_22 -> V_71 , V_77 ) ;
}
static void
F_42 ( void * V_28 )
{
struct V_68 * V_22 = (struct V_68 * ) V_28 ;
struct V_97 * V_98 =
(struct V_97 * ) & V_22 -> V_99 . V_32 [ 0 ] ;
memset ( V_98 , 0 , sizeof( struct V_97 ) ) ;
F_16 ( V_98 -> V_33 , V_34 , V_100 , 0 ) ;
V_98 -> V_33 . V_36 . V_37 = 0 ;
F_43 ( V_98 -> V_2 . V_49 , V_22 -> V_2 . V_49 . V_101 ) ;
V_98 -> V_2 . V_102 = F_17 ( V_22 -> V_2 . V_52 ) ;
F_43 ( V_98 -> V_71 . V_49 , V_22 -> V_71 . V_49 . V_101 ) ;
V_98 -> V_71 . V_102 = F_17 ( V_22 -> V_71 . V_52 ) ;
F_18 ( V_22 -> V_40 , & V_22 -> V_99 , NULL , NULL ) ;
}
static void
F_44 ( void * V_95 , struct V_53 * V_32 )
{
struct V_68 * V_22 = (struct V_68 * ) V_95 ;
switch ( V_32 -> V_33 . V_103 ) {
case V_104 :
F_41 ( V_22 , V_32 ) ;
break;
case V_105 :
F_39 ( & V_22 -> V_71 , V_32 ) ;
break;
case V_106 :
F_21 ( & V_22 -> V_2 , V_32 ) ;
break;
case V_107 :
F_28 ( & V_22 -> V_2 , V_32 ) ;
break;
default:
F_45 ( 1 ) ;
}
}
static void
F_46 ( void * V_95 , enum V_108 V_15 )
{
struct V_68 * V_22 = (struct V_68 * ) V_95 ;
switch ( V_15 ) {
case V_109 :
F_47 ( & V_22 -> V_23 , F_42 , V_22 ) ;
F_48 ( & V_22 -> V_23 ) ;
F_15 ( & V_22 -> V_2 , V_16 ) ;
F_48 ( & V_22 -> V_23 ) ;
F_15 ( & V_22 -> V_71 , V_73 ) ;
F_49 ( & V_22 -> V_23 ) ;
break;
case V_110 :
F_15 ( & V_22 -> V_2 , V_18 ) ;
F_15 ( & V_22 -> V_71 , V_75 ) ;
break;
case V_111 :
F_15 ( & V_22 -> V_2 , V_19 ) ;
F_15 ( & V_22 -> V_71 , V_76 ) ;
break;
default:
break;
}
}
T_3
F_50 ( void )
{
return F_51 ( V_112 , V_113 ) +
F_51 ( V_114 , V_113 ) ;
}
void
F_52 ( struct V_68 * V_22 , T_2 * V_50 , T_4 V_101 )
{
V_22 -> V_2 . V_49 . V_50 = V_50 ;
V_22 -> V_2 . V_49 . V_101 = V_101 ;
V_50 += F_51 ( V_112 , V_113 ) ;
V_101 += F_51 ( V_112 , V_113 ) ;
V_22 -> V_71 . V_49 . V_50 = V_50 ;
V_22 -> V_71 . V_49 . V_101 = V_101 ;
}
void
F_53 ( struct V_68 * V_22 , struct V_115 * V_40 )
{
V_22 -> V_40 = V_40 ;
F_29 ( & V_22 -> V_2 , V_22 ) ;
F_40 ( & V_22 -> V_71 , V_22 ) ;
F_54 ( V_22 -> V_40 , V_34 , F_44 , V_22 ) ;
F_4 ( & V_22 -> V_116 ) ;
F_55 ( & V_22 -> V_116 , F_46 , V_22 ) ;
F_56 ( V_22 -> V_40 , & V_22 -> V_116 ) ;
}
void
F_57 ( struct V_68 * V_22 , enum V_117 V_87 ,
T_5 V_94 , void * V_95 )
{
V_22 -> V_71 . V_93 [ V_87 ] . V_94 = V_94 ;
V_22 -> V_71 . V_93 [ V_87 ] . V_95 = V_95 ;
}
void
F_58 ( struct V_68 * V_22 , struct V_3 * V_41 )
{
if ( F_22 ( V_41 -> V_48 -> V_44 ) <=
F_24 ( & V_22 -> V_2 ) ) {
F_19 ( & V_22 -> V_2 , V_41 ) ;
F_5 ( V_41 , V_58 ) ;
F_15 ( & V_22 -> V_2 , V_20 ) ;
} else {
F_59 ( & V_41 -> V_12 , & V_22 -> V_2 . V_11 ) ;
}
}
void
F_60 ( struct V_68 * V_22 , T_2 * V_118 , T_1 V_119 )
{
struct V_70 * V_71 = & V_22 -> V_71 ;
T_1 V_42 = V_119 ;
T_1 V_45 ;
int V_120 ;
T_2 * V_46 , * V_47 ;
V_120 = V_71 -> V_6 ;
V_46 = ( T_2 * ) V_71 -> V_49 . V_50 ;
V_46 += ( V_120 * V_90 ) ;
V_47 = V_118 ;
while ( V_42 ) {
V_45 = ( V_42 < V_90 ) ?
V_42 : V_90 ;
memcpy ( V_47 , V_46 , V_45 ) ;
V_42 -= V_45 ;
V_47 += V_90 ;
F_20 ( V_120 , 1 , V_71 -> V_52 ) ;
V_46 = ( T_2 * ) V_71 -> V_49 . V_50 ;
V_46 += ( V_120 * V_90 ) ;
}
}
