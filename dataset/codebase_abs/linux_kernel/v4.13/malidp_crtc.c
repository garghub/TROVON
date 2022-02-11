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
static void F_5 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_17 V_18 ;
int V_19 = F_6 ( V_3 -> V_10 -> V_10 ) ;
if ( V_19 < 0 ) {
F_4 ( L_2 , V_19 ) ;
return;
}
F_7 ( & V_3 -> V_20 -> V_21 , & V_18 ) ;
F_8 ( V_9 -> V_14 ) ;
F_9 ( V_9 -> V_14 , V_3 -> V_20 -> V_21 . V_13 * 1000 ) ;
V_9 -> V_22 ( V_9 , & V_18 ) ;
V_9 -> V_23 ( V_9 ) ;
F_10 ( V_3 ) ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_19 ;
F_12 ( V_3 ) ;
V_9 -> V_24 ( V_9 ) ;
F_13 ( V_9 -> V_14 ) ;
V_19 = F_14 ( V_3 -> V_10 -> V_10 ) ;
if ( V_19 < 0 ) {
F_4 ( L_3 , V_19 ) ;
}
}
static void F_15 ( struct V_25 * V_26 ,
T_1 V_27 [ V_28 ] )
{
struct V_29 * V_30 = (struct V_29 * ) V_26 -> V_31 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_28 ; ++ V_32 ) {
T_1 V_33 , V_34 , V_35 , V_36 , V_37 ;
V_35 = V_38 [ V_32 ] . V_39 - V_38 [ V_32 ] . V_40 ;
V_36 = F_16 ( V_30 [ V_38 [ V_32 ] . V_40 ] . V_41 ,
12 ) ;
V_37 = F_16 ( V_30 [ V_38 [ V_32 ] . V_39 ] . V_41 , 12 ) ;
V_33 = ( V_35 == 0 ) ? 0 : ( ( V_37 - V_36 ) * 256 ) / V_35 ;
V_34 = V_36 ;
V_27 [ V_32 ] = F_17 ( V_33 , V_34 ) ;
}
}
static int F_18 ( struct V_2 * V_3 ,
struct V_42 * V_20 )
{
struct V_43 * V_44 = F_19 ( V_20 ) ;
struct V_29 * V_30 ;
T_2 V_45 ;
int V_32 ;
if ( ! V_20 -> V_46 || ! V_20 -> V_47 )
return 0 ;
if ( V_3 -> V_20 -> V_47 &&
( V_3 -> V_20 -> V_47 -> V_48 . V_49 == V_20 -> V_47 -> V_48 . V_49 ) )
return 0 ;
if ( V_20 -> V_47 -> V_50 % sizeof( struct V_29 ) )
return - V_51 ;
V_45 = V_20 -> V_47 -> V_50 / sizeof( struct V_29 ) ;
if ( V_45 != V_52 )
return - V_51 ;
V_30 = (struct V_29 * ) V_20 -> V_47 -> V_31 ;
for ( V_32 = 0 ; V_32 < V_45 ; ++ V_32 )
if ( ! ( ( V_30 [ V_32 ] . V_53 == V_30 [ V_32 ] . V_41 ) &&
( V_30 [ V_32 ] . V_53 == V_30 [ V_32 ] . V_54 ) ) )
return - V_51 ;
if ( ! V_20 -> V_55 ) {
int V_56 ;
V_20 -> V_55 = true ;
V_56 = F_20 ( V_3 -> V_10 , V_20 -> V_20 ) ;
if ( V_56 )
return V_56 ;
}
F_15 ( V_20 -> V_47 , V_44 -> V_57 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_42 * V_20 )
{
struct V_43 * V_44 = F_19 ( V_20 ) ;
struct V_58 * V_59 ;
int V_32 ;
if ( ! V_20 -> V_46 )
return 0 ;
if ( ! V_20 -> V_59 )
return 0 ;
if ( V_3 -> V_20 -> V_59 && ( V_3 -> V_20 -> V_59 -> V_48 . V_49 ==
V_20 -> V_59 -> V_48 . V_49 ) )
return 0 ;
V_59 = (struct V_58 * ) V_20 -> V_59 -> V_31 ;
for ( V_32 = 0 ; V_32 < F_22 ( V_59 -> V_60 ) ; ++ V_32 ) {
T_3 V_61 = V_59 -> V_60 [ V_32 ] ;
T_1 V_62 = ( ( ( ( V_63 ) V_61 ) & ~ F_23 ( 63 ) ) >> 20 ) &
F_24 ( 14 , 0 ) ;
if ( V_61 & F_23 ( 63 ) )
V_62 = ~ V_62 + 1 ;
if ( ! ! ( V_61 & F_23 ( 63 ) ) != ! ! ( V_62 & F_25 ( 14 ) ) )
return - V_51 ;
V_44 -> V_64 [ V_32 ] = V_62 ;
}
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_42 * V_20 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_43 * V_65 = F_19 ( V_20 ) ;
struct V_66 * V_67 = & V_65 -> V_68 ;
struct V_69 * V_70 ;
struct V_17 V_18 ;
const struct V_71 * V_72 ;
T_1 V_73 = 0 ;
T_1 V_74 = 0 ;
T_4 V_75 = V_65 -> V_76 ;
int V_56 ;
if ( ! V_75 ) {
V_67 -> V_77 = false ;
goto V_78;
}
if ( V_75 & ( V_75 - 1 ) )
return - V_51 ;
F_27 (plane, pstate, state) {
struct V_79 * V_80 = F_28 ( V_70 ) ;
T_1 V_81 ;
if ( ! ( V_80 -> V_82 -> V_49 & V_75 ) )
continue;
V_73 = F_29 ( ( V_63 ) V_72 -> V_83 << 32 ,
V_72 -> V_84 ) ;
V_74 = F_29 ( ( V_63 ) V_72 -> V_85 << 32 ,
V_72 -> V_86 ) ;
V_67 -> V_87 = ( ( V_73 >> 16 ) >= 2 ||
( V_74 >> 16 ) >= 2 ) ;
V_67 -> V_88 = V_72 -> V_84 >> 16 ;
V_67 -> V_89 = V_72 -> V_86 >> 16 ;
V_67 -> V_90 = V_72 -> V_83 ;
V_67 -> V_91 = V_72 -> V_85 ;
#define F_30 4
#define F_31 12
V_81 = V_67 -> V_88 ;
V_67 -> V_92 =
( ( V_81 << F_30 ) / V_67 -> V_90 + 1 ) / 2 ;
V_81 = V_67 -> V_88 ;
V_81 <<= ( F_31 + F_30 ) ;
V_67 -> V_93 = V_81 / V_67 -> V_90 ;
V_81 = V_67 -> V_89 ;
V_67 -> V_94 =
( ( V_81 << F_30 ) / V_67 -> V_91 + 1 ) / 2 ;
V_81 = V_67 -> V_89 ;
V_81 <<= ( F_31 + F_30 ) ;
V_67 -> V_95 = V_81 / V_67 -> V_91 ;
#undef F_30
#undef F_31
V_67 -> V_96 = V_80 -> V_82 -> V_49 ;
}
V_67 -> V_77 = true ;
V_67 -> V_97 = F_32 ( V_73 ) ;
V_67 -> V_98 = F_32 ( V_74 ) ;
V_78:
F_7 ( & V_20 -> V_21 , & V_18 ) ;
V_56 = V_9 -> V_99 ( V_9 , V_67 , & V_18 ) ;
if ( V_56 < 0 )
return - V_51 ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_42 * V_20 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_69 * V_70 ;
const struct V_71 * V_72 ;
T_1 V_100 , V_101 ;
int V_102 = 0 ;
int V_56 ;
F_27 (plane, pstate, state) {
if ( V_72 -> V_103 & V_104 )
V_102 ++ ;
}
V_100 = V_9 -> V_105 [ 0 ] ;
if ( V_102 > 1 )
V_100 += V_9 -> V_105 [ 1 ] ;
F_27 (plane, pstate, state) {
struct V_79 * V_80 = F_28 ( V_70 ) ;
struct V_106 * V_107 = F_34 ( V_72 ) ;
if ( V_72 -> V_103 & V_104 ) {
V_102 -- ;
if ( ! V_102 ) {
V_101 = V_100 ;
} else {
if ( ( V_80 -> V_82 -> V_49 != V_108 ) ||
( V_9 -> V_105 [ 1 ] == 0 ) )
V_101 = V_100 / 2 ;
else
V_101 = V_9 -> V_105 [ 0 ] ;
}
V_100 -= V_101 ;
if ( V_107 -> V_109 > V_101 )
return - V_51 ;
}
}
V_56 = F_18 ( V_3 , V_20 ) ;
V_56 = V_56 ? V_56 : F_21 ( V_3 , V_20 ) ;
V_56 = V_56 ? V_56 : F_26 ( V_3 , V_20 ) ;
return V_56 ;
}
static struct V_42 * F_35 ( struct V_2 * V_3 )
{
struct V_43 * V_20 , * V_110 ;
if ( F_36 ( ! V_3 -> V_20 ) )
return NULL ;
V_110 = F_19 ( V_3 -> V_20 ) ;
V_20 = F_37 ( sizeof( * V_20 ) , V_111 ) ;
if ( ! V_20 )
return NULL ;
F_38 ( V_3 , & V_20 -> V_48 ) ;
memcpy ( V_20 -> V_57 , V_110 -> V_57 ,
sizeof( V_20 -> V_57 ) ) ;
memcpy ( V_20 -> V_64 , V_110 -> V_64 ,
sizeof( V_20 -> V_64 ) ) ;
memcpy ( & V_20 -> V_68 , & V_110 -> V_68 ,
sizeof( V_20 -> V_68 ) ) ;
V_20 -> V_76 = 0 ;
return & V_20 -> V_48 ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_43 * V_20 = NULL ;
if ( V_3 -> V_20 ) {
V_20 = F_19 ( V_3 -> V_20 ) ;
F_40 ( V_3 -> V_20 ) ;
}
F_41 ( V_20 ) ;
V_20 = F_42 ( sizeof( * V_20 ) , V_111 ) ;
if ( V_20 ) {
V_3 -> V_20 = & V_20 -> V_48 ;
V_3 -> V_20 -> V_3 = V_3 ;
}
}
static void F_43 ( struct V_2 * V_3 ,
struct V_42 * V_20 )
{
struct V_43 * V_112 = NULL ;
if ( V_20 ) {
V_112 = F_19 ( V_20 ) ;
F_40 ( V_20 ) ;
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
struct V_69 * V_120 = NULL , * V_70 ;
int V_56 ;
V_56 = F_49 ( V_118 ) ;
if ( V_56 < 0 ) {
F_50 ( L_4 ) ;
return V_56 ;
}
F_51 (plane, drm) {
if ( V_70 -> type == V_121 ) {
V_120 = V_70 ;
break;
}
}
if ( ! V_120 ) {
F_50 ( L_5 ) ;
V_56 = - V_51 ;
goto V_122;
}
V_56 = F_52 ( V_118 , & V_7 -> V_3 , V_120 , NULL ,
& V_123 , NULL ) ;
if ( V_56 )
goto V_122;
F_53 ( & V_7 -> V_3 , & V_124 ) ;
F_54 ( & V_7 -> V_3 , V_52 ) ;
F_55 ( & V_7 -> V_3 , 0 , true , V_52 ) ;
F_56 ( V_7 -> V_10 ) ;
return 0 ;
V_122:
F_57 ( V_118 ) ;
return V_56 ;
}
