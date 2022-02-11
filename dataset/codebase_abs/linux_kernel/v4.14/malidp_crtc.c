static enum V_1 F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
long V_11 , V_12 = V_5 -> V_13 * 1000 ;
if ( V_12 ) {
V_11 = F_3 ( V_9 -> V_14 , V_12 ) ;
if ( V_11 != V_12 ) {
F_4 ( L_1 ,
V_12 ) ;
return V_15 ;
}
}
return V_16 ;
}
static void F_5 ( struct V_2 * V_3 ,
struct V_17 * V_18 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_19 V_20 ;
int V_21 = F_6 ( V_3 -> V_10 -> V_10 ) ;
if ( V_21 < 0 ) {
F_4 ( L_2 , V_21 ) ;
return;
}
F_7 ( & V_3 -> V_22 -> V_23 , & V_20 ) ;
F_8 ( V_9 -> V_14 ) ;
F_9 ( V_9 -> V_14 , V_3 -> V_22 -> V_23 . V_13 * 1000 ) ;
V_9 -> V_24 ( V_9 , & V_20 ) ;
V_9 -> V_25 ( V_9 ) ;
F_10 ( V_3 ) ;
}
static void F_11 ( struct V_2 * V_3 ,
struct V_17 * V_18 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_21 ;
F_12 ( V_3 ) ;
V_9 -> V_26 ( V_9 ) ;
F_13 ( V_9 -> V_14 ) ;
V_21 = F_14 ( V_3 -> V_10 -> V_10 ) ;
if ( V_21 < 0 ) {
F_4 ( L_3 , V_21 ) ;
}
}
static void F_15 ( struct V_27 * V_28 ,
T_1 V_29 [ V_30 ] )
{
struct V_31 * V_32 = (struct V_31 * ) V_28 -> V_33 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_30 ; ++ V_34 ) {
T_1 V_35 , V_36 , V_37 , V_38 , V_39 ;
V_37 = V_40 [ V_34 ] . V_41 - V_40 [ V_34 ] . V_42 ;
V_38 = F_16 ( V_32 [ V_40 [ V_34 ] . V_42 ] . V_43 ,
12 ) ;
V_39 = F_16 ( V_32 [ V_40 [ V_34 ] . V_41 ] . V_43 , 12 ) ;
V_35 = ( V_37 == 0 ) ? 0 : ( ( V_39 - V_38 ) * 256 ) / V_37 ;
V_36 = V_38 ;
V_29 [ V_34 ] = F_17 ( V_35 , V_36 ) ;
}
}
static int F_18 ( struct V_2 * V_3 ,
struct V_17 * V_22 )
{
struct V_44 * V_45 = F_19 ( V_22 ) ;
struct V_31 * V_32 ;
T_2 V_46 ;
int V_34 ;
if ( ! V_22 -> V_47 || ! V_22 -> V_48 )
return 0 ;
if ( V_3 -> V_22 -> V_48 &&
( V_3 -> V_22 -> V_48 -> V_49 . V_50 == V_22 -> V_48 -> V_49 . V_50 ) )
return 0 ;
if ( V_22 -> V_48 -> V_51 % sizeof( struct V_31 ) )
return - V_52 ;
V_46 = V_22 -> V_48 -> V_51 / sizeof( struct V_31 ) ;
if ( V_46 != V_53 )
return - V_52 ;
V_32 = (struct V_31 * ) V_22 -> V_48 -> V_33 ;
for ( V_34 = 0 ; V_34 < V_46 ; ++ V_34 )
if ( ! ( ( V_32 [ V_34 ] . V_54 == V_32 [ V_34 ] . V_43 ) &&
( V_32 [ V_34 ] . V_54 == V_32 [ V_34 ] . V_55 ) ) )
return - V_52 ;
if ( ! V_22 -> V_56 ) {
int V_57 ;
V_22 -> V_56 = true ;
V_57 = F_20 ( V_3 -> V_10 , V_22 -> V_22 ) ;
if ( V_57 )
return V_57 ;
}
F_15 ( V_22 -> V_48 , V_45 -> V_58 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_17 * V_22 )
{
struct V_44 * V_45 = F_19 ( V_22 ) ;
struct V_59 * V_60 ;
int V_34 ;
if ( ! V_22 -> V_47 )
return 0 ;
if ( ! V_22 -> V_60 )
return 0 ;
if ( V_3 -> V_22 -> V_60 && ( V_3 -> V_22 -> V_60 -> V_49 . V_50 ==
V_22 -> V_60 -> V_49 . V_50 ) )
return 0 ;
V_60 = (struct V_59 * ) V_22 -> V_60 -> V_33 ;
for ( V_34 = 0 ; V_34 < F_22 ( V_60 -> V_61 ) ; ++ V_34 ) {
T_3 V_62 = V_60 -> V_61 [ V_34 ] ;
T_1 V_63 = ( ( ( ( V_64 ) V_62 ) & ~ F_23 ( 63 ) ) >> 20 ) &
F_24 ( 14 , 0 ) ;
if ( V_62 & F_23 ( 63 ) )
V_63 = ~ V_63 + 1 ;
if ( ! ! ( V_62 & F_23 ( 63 ) ) != ! ! ( V_63 & F_25 ( 14 ) ) )
return - V_52 ;
V_45 -> V_65 [ V_34 ] = V_63 ;
}
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_17 * V_22 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_44 * V_66 = F_19 ( V_22 ) ;
struct V_67 * V_68 = & V_66 -> V_69 ;
struct V_70 * V_71 ;
struct V_19 V_20 ;
const struct V_72 * V_73 ;
T_1 V_74 = 0 ;
T_1 V_75 = 0 ;
T_4 V_76 = V_66 -> V_77 ;
int V_57 ;
if ( ! V_76 ) {
V_68 -> V_78 = false ;
goto V_79;
}
if ( V_76 & ( V_76 - 1 ) )
return - V_52 ;
F_27 (plane, pstate, state) {
struct V_80 * V_81 = F_28 ( V_71 ) ;
T_1 V_82 ;
if ( ! ( V_81 -> V_83 -> V_50 & V_76 ) )
continue;
V_74 = F_29 ( ( V_64 ) V_73 -> V_84 << 32 ,
V_73 -> V_85 ) ;
V_75 = F_29 ( ( V_64 ) V_73 -> V_86 << 32 ,
V_73 -> V_87 ) ;
V_68 -> V_88 = ( ( V_74 >> 16 ) >= 2 ||
( V_75 >> 16 ) >= 2 ) ;
V_68 -> V_89 = V_73 -> V_85 >> 16 ;
V_68 -> V_90 = V_73 -> V_87 >> 16 ;
V_68 -> V_91 = V_73 -> V_84 ;
V_68 -> V_92 = V_73 -> V_86 ;
#define F_30 4
#define F_31 12
V_82 = V_68 -> V_89 ;
V_68 -> V_93 =
( ( V_82 << F_30 ) / V_68 -> V_91 + 1 ) / 2 ;
V_82 = V_68 -> V_89 ;
V_82 <<= ( F_31 + F_30 ) ;
V_68 -> V_94 = V_82 / V_68 -> V_91 ;
V_82 = V_68 -> V_90 ;
V_68 -> V_95 =
( ( V_82 << F_30 ) / V_68 -> V_92 + 1 ) / 2 ;
V_82 = V_68 -> V_90 ;
V_82 <<= ( F_31 + F_30 ) ;
V_68 -> V_96 = V_82 / V_68 -> V_92 ;
#undef F_30
#undef F_31
V_68 -> V_97 = V_81 -> V_83 -> V_50 ;
}
V_68 -> V_78 = true ;
V_68 -> V_98 = F_32 ( V_74 ) ;
V_68 -> V_99 = F_32 ( V_75 ) ;
V_79:
F_7 ( & V_22 -> V_23 , & V_20 ) ;
V_57 = V_9 -> V_100 ( V_9 , V_68 , & V_20 ) ;
if ( V_57 < 0 )
return - V_52 ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_17 * V_22 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_70 * V_71 ;
const struct V_72 * V_73 ;
T_1 V_101 , V_102 ;
int V_103 = 0 ;
int V_57 ;
F_27 (plane, pstate, state) {
if ( V_73 -> V_104 & V_105 )
V_103 ++ ;
}
V_101 = V_9 -> V_106 [ 0 ] ;
if ( V_103 > 1 )
V_101 += V_9 -> V_106 [ 1 ] ;
F_27 (plane, pstate, state) {
struct V_80 * V_81 = F_28 ( V_71 ) ;
struct V_107 * V_108 = F_34 ( V_73 ) ;
if ( V_73 -> V_104 & V_105 ) {
V_103 -- ;
if ( ! V_103 ) {
V_102 = V_101 ;
} else {
if ( ( V_81 -> V_83 -> V_50 != V_109 ) ||
( V_9 -> V_106 [ 1 ] == 0 ) )
V_102 = V_101 / 2 ;
else
V_102 = V_9 -> V_106 [ 0 ] ;
}
V_101 -= V_102 ;
if ( V_108 -> V_110 > V_102 )
return - V_52 ;
}
}
V_57 = F_18 ( V_3 , V_22 ) ;
V_57 = V_57 ? V_57 : F_21 ( V_3 , V_22 ) ;
V_57 = V_57 ? V_57 : F_26 ( V_3 , V_22 ) ;
return V_57 ;
}
static struct V_17 * F_35 ( struct V_2 * V_3 )
{
struct V_44 * V_22 , * V_18 ;
if ( F_36 ( ! V_3 -> V_22 ) )
return NULL ;
V_18 = F_19 ( V_3 -> V_22 ) ;
V_22 = F_37 ( sizeof( * V_22 ) , V_111 ) ;
if ( ! V_22 )
return NULL ;
F_38 ( V_3 , & V_22 -> V_49 ) ;
memcpy ( V_22 -> V_58 , V_18 -> V_58 ,
sizeof( V_22 -> V_58 ) ) ;
memcpy ( V_22 -> V_65 , V_18 -> V_65 ,
sizeof( V_22 -> V_65 ) ) ;
memcpy ( & V_22 -> V_69 , & V_18 -> V_69 ,
sizeof( V_22 -> V_69 ) ) ;
V_22 -> V_77 = 0 ;
return & V_22 -> V_49 ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_44 * V_22 = NULL ;
if ( V_3 -> V_22 ) {
V_22 = F_19 ( V_3 -> V_22 ) ;
F_40 ( V_3 -> V_22 ) ;
}
F_41 ( V_22 ) ;
V_22 = F_42 ( sizeof( * V_22 ) , V_111 ) ;
if ( V_22 ) {
V_3 -> V_22 = & V_22 -> V_49 ;
V_3 -> V_22 -> V_3 = V_3 ;
}
}
static void F_43 ( struct V_2 * V_3 ,
struct V_17 * V_22 )
{
struct V_44 * V_112 = NULL ;
if ( V_22 ) {
V_112 = F_19 ( V_22 ) ;
F_40 ( V_22 ) ;
}
F_41 ( V_112 ) ;
}
static int F_44 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
F_45 ( V_9 , V_113 ,
V_9 -> V_114 . V_115 . V_116 ) ;
return 0 ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
F_47 ( V_9 , V_113 ,
V_9 -> V_114 . V_115 . V_116 ) ;
}
int F_48 ( struct V_117 * V_118 )
{
struct V_6 * V_7 = V_118 -> V_119 ;
struct V_70 * V_120 = NULL , * V_71 ;
int V_57 ;
V_57 = F_49 ( V_118 ) ;
if ( V_57 < 0 ) {
F_50 ( L_4 ) ;
return V_57 ;
}
F_51 (plane, drm) {
if ( V_71 -> type == V_121 ) {
V_120 = V_71 ;
break;
}
}
if ( ! V_120 ) {
F_50 ( L_5 ) ;
V_57 = - V_52 ;
goto V_122;
}
V_57 = F_52 ( V_118 , & V_7 -> V_3 , V_120 , NULL ,
& V_123 , NULL ) ;
if ( V_57 )
goto V_122;
F_53 ( & V_7 -> V_3 , & V_124 ) ;
F_54 ( & V_7 -> V_3 , V_53 ) ;
F_55 ( & V_7 -> V_3 , 0 , true , V_53 ) ;
F_56 ( V_7 -> V_10 ) ;
return 0 ;
V_122:
F_57 ( V_118 ) ;
return V_57 ;
}
