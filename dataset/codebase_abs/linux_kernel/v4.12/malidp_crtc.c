static bool F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
long V_11 , V_12 = V_4 -> V_13 * 1000 ;
if ( V_12 ) {
V_11 = F_3 ( V_9 -> V_14 , V_12 ) ;
if ( V_11 != V_12 ) {
F_4 ( L_1 ,
V_12 ) ;
return false ;
}
}
return true ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_15 V_16 ;
int V_17 = F_6 ( V_2 -> V_10 -> V_10 ) ;
if ( V_17 < 0 ) {
F_4 ( L_2 , V_17 ) ;
return;
}
F_7 ( & V_2 -> V_18 -> V_5 , & V_16 ) ;
F_8 ( V_9 -> V_14 ) ;
F_9 ( V_9 -> V_14 , V_2 -> V_18 -> V_5 . V_13 * 1000 ) ;
V_9 -> V_19 ( V_9 , & V_16 ) ;
V_9 -> V_20 ( V_9 ) ;
F_10 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_17 ;
F_12 ( V_2 ) ;
V_9 -> V_21 ( V_9 ) ;
F_13 ( V_9 -> V_14 ) ;
V_17 = F_14 ( V_2 -> V_10 -> V_10 ) ;
if ( V_17 < 0 ) {
F_4 ( L_3 , V_17 ) ;
}
}
static void F_15 ( struct V_22 * V_23 ,
T_1 V_24 [ V_25 ] )
{
struct V_26 * V_27 = (struct V_26 * ) V_23 -> V_28 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_25 ; ++ V_29 ) {
T_1 V_30 , V_31 , V_32 , V_33 , V_34 ;
V_32 = V_35 [ V_29 ] . V_36 - V_35 [ V_29 ] . V_37 ;
V_33 = F_16 ( V_27 [ V_35 [ V_29 ] . V_37 ] . V_38 ,
12 ) ;
V_34 = F_16 ( V_27 [ V_35 [ V_29 ] . V_36 ] . V_38 , 12 ) ;
V_30 = ( V_32 == 0 ) ? 0 : ( ( V_34 - V_33 ) * 256 ) / V_32 ;
V_31 = V_33 ;
V_24 [ V_29 ] = F_17 ( V_30 , V_31 ) ;
}
}
static int F_18 ( struct V_1 * V_2 ,
struct V_39 * V_18 )
{
struct V_40 * V_41 = F_19 ( V_18 ) ;
struct V_26 * V_27 ;
T_2 V_42 ;
int V_29 ;
if ( ! V_18 -> V_43 || ! V_18 -> V_44 )
return 0 ;
if ( V_2 -> V_18 -> V_44 &&
( V_2 -> V_18 -> V_44 -> V_45 . V_46 == V_18 -> V_44 -> V_45 . V_46 ) )
return 0 ;
if ( V_18 -> V_44 -> V_47 % sizeof( struct V_26 ) )
return - V_48 ;
V_42 = V_18 -> V_44 -> V_47 / sizeof( struct V_26 ) ;
if ( V_42 != V_49 )
return - V_48 ;
V_27 = (struct V_26 * ) V_18 -> V_44 -> V_28 ;
for ( V_29 = 0 ; V_29 < V_42 ; ++ V_29 )
if ( ! ( ( V_27 [ V_29 ] . V_50 == V_27 [ V_29 ] . V_38 ) &&
( V_27 [ V_29 ] . V_50 == V_27 [ V_29 ] . V_51 ) ) )
return - V_48 ;
if ( ! V_18 -> V_52 ) {
int V_53 ;
V_18 -> V_52 = true ;
V_53 = F_20 ( V_2 -> V_10 , V_18 -> V_18 ) ;
if ( V_53 )
return V_53 ;
}
F_15 ( V_18 -> V_44 , V_41 -> V_54 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_39 * V_18 )
{
struct V_40 * V_41 = F_19 ( V_18 ) ;
struct V_55 * V_56 ;
int V_29 ;
if ( ! V_18 -> V_43 )
return 0 ;
if ( ! V_18 -> V_56 )
return 0 ;
if ( V_2 -> V_18 -> V_56 && ( V_2 -> V_18 -> V_56 -> V_45 . V_46 ==
V_18 -> V_56 -> V_45 . V_46 ) )
return 0 ;
V_56 = (struct V_55 * ) V_18 -> V_56 -> V_28 ;
for ( V_29 = 0 ; V_29 < F_22 ( V_56 -> V_57 ) ; ++ V_29 ) {
T_3 V_58 = V_56 -> V_57 [ V_29 ] ;
T_1 V_59 = ( ( ( ( V_60 ) V_58 ) & ~ F_23 ( 63 ) ) >> 20 ) &
F_24 ( 14 , 0 ) ;
if ( V_58 & F_23 ( 63 ) )
V_59 = ~ V_59 + 1 ;
if ( ! ! ( V_58 & F_23 ( 63 ) ) != ! ! ( V_59 & F_25 ( 14 ) ) )
return - V_48 ;
V_41 -> V_61 [ V_29 ] = V_59 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_39 * V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_40 * V_62 = F_19 ( V_18 ) ;
struct V_63 * V_64 = & V_62 -> V_65 ;
struct V_66 * V_67 ;
struct V_15 V_16 ;
const struct V_68 * V_69 ;
T_1 V_70 = 0 ;
T_1 V_71 = 0 ;
T_4 V_72 = V_62 -> V_73 ;
int V_53 ;
if ( ! V_72 ) {
V_64 -> V_74 = false ;
goto V_75;
}
if ( V_72 & ( V_72 - 1 ) )
return - V_48 ;
F_27 (plane, pstate, state) {
struct V_76 * V_77 = F_28 ( V_67 ) ;
T_1 V_78 ;
if ( ! ( V_77 -> V_79 -> V_46 & V_72 ) )
continue;
V_70 = F_29 ( ( V_60 ) V_69 -> V_80 << 32 ,
V_69 -> V_81 ) ;
V_71 = F_29 ( ( V_60 ) V_69 -> V_82 << 32 ,
V_69 -> V_83 ) ;
V_64 -> V_84 = ( ( V_70 >> 16 ) >= 2 ||
( V_71 >> 16 ) >= 2 ) ;
V_64 -> V_85 = V_69 -> V_81 >> 16 ;
V_64 -> V_86 = V_69 -> V_83 >> 16 ;
V_64 -> V_87 = V_69 -> V_80 ;
V_64 -> V_88 = V_69 -> V_82 ;
#define F_30 4
#define F_31 12
V_78 = V_64 -> V_85 ;
V_64 -> V_89 =
( ( V_78 << F_30 ) / V_64 -> V_87 + 1 ) / 2 ;
V_78 = V_64 -> V_85 ;
V_78 <<= ( F_31 + F_30 ) ;
V_64 -> V_90 = V_78 / V_64 -> V_87 ;
V_78 = V_64 -> V_86 ;
V_64 -> V_91 =
( ( V_78 << F_30 ) / V_64 -> V_88 + 1 ) / 2 ;
V_78 = V_64 -> V_86 ;
V_78 <<= ( F_31 + F_30 ) ;
V_64 -> V_92 = V_78 / V_64 -> V_88 ;
#undef F_30
#undef F_31
V_64 -> V_93 = V_77 -> V_79 -> V_46 ;
}
V_64 -> V_74 = true ;
V_64 -> V_94 = F_32 ( V_70 ) ;
V_64 -> V_95 = F_32 ( V_71 ) ;
V_75:
F_7 ( & V_18 -> V_5 , & V_16 ) ;
V_53 = V_9 -> V_96 ( V_9 , V_64 , & V_16 ) ;
if ( V_53 < 0 )
return - V_48 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_39 * V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_66 * V_67 ;
const struct V_68 * V_69 ;
T_1 V_97 , V_98 ;
int V_99 = 0 ;
int V_53 ;
F_27 (plane, pstate, state) {
if ( V_69 -> V_100 & V_101 )
V_99 ++ ;
}
V_97 = V_9 -> V_102 [ 0 ] ;
if ( V_99 > 1 )
V_97 += V_9 -> V_102 [ 1 ] ;
F_27 (plane, pstate, state) {
struct V_76 * V_77 = F_28 ( V_67 ) ;
struct V_103 * V_104 = F_34 ( V_69 ) ;
if ( V_69 -> V_100 & V_101 ) {
V_99 -- ;
if ( ! V_99 ) {
V_98 = V_97 ;
} else {
if ( ( V_77 -> V_79 -> V_46 != V_105 ) ||
( V_9 -> V_102 [ 1 ] == 0 ) )
V_98 = V_97 / 2 ;
else
V_98 = V_9 -> V_102 [ 0 ] ;
}
V_97 -= V_98 ;
if ( V_104 -> V_106 > V_98 )
return - V_48 ;
}
}
V_53 = F_18 ( V_2 , V_18 ) ;
V_53 = V_53 ? V_53 : F_21 ( V_2 , V_18 ) ;
V_53 = V_53 ? V_53 : F_26 ( V_2 , V_18 ) ;
return V_53 ;
}
static struct V_39 * F_35 ( struct V_1 * V_2 )
{
struct V_40 * V_18 , * V_107 ;
if ( F_36 ( ! V_2 -> V_18 ) )
return NULL ;
V_107 = F_19 ( V_2 -> V_18 ) ;
V_18 = F_37 ( sizeof( * V_18 ) , V_108 ) ;
if ( ! V_18 )
return NULL ;
F_38 ( V_2 , & V_18 -> V_45 ) ;
memcpy ( V_18 -> V_54 , V_107 -> V_54 ,
sizeof( V_18 -> V_54 ) ) ;
memcpy ( V_18 -> V_61 , V_107 -> V_61 ,
sizeof( V_18 -> V_61 ) ) ;
memcpy ( & V_18 -> V_65 , & V_107 -> V_65 ,
sizeof( V_18 -> V_65 ) ) ;
V_18 -> V_73 = 0 ;
return & V_18 -> V_45 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_40 * V_18 = NULL ;
if ( V_2 -> V_18 ) {
V_18 = F_19 ( V_2 -> V_18 ) ;
F_40 ( V_2 -> V_18 ) ;
}
F_41 ( V_18 ) ;
V_18 = F_42 ( sizeof( * V_18 ) , V_108 ) ;
if ( V_18 ) {
V_2 -> V_18 = & V_18 -> V_45 ;
V_2 -> V_18 -> V_2 = V_2 ;
}
}
static void F_43 ( struct V_1 * V_2 ,
struct V_39 * V_18 )
{
struct V_40 * V_109 = NULL ;
if ( V_18 ) {
V_109 = F_19 ( V_18 ) ;
F_40 ( V_18 ) ;
}
F_41 ( V_109 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
F_45 ( V_9 , V_110 ,
V_9 -> V_111 . V_112 . V_113 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
F_47 ( V_9 , V_110 ,
V_9 -> V_111 . V_112 . V_113 ) ;
}
int F_48 ( struct V_114 * V_115 )
{
struct V_6 * V_7 = V_115 -> V_116 ;
struct V_66 * V_117 = NULL , * V_67 ;
int V_53 ;
V_53 = F_49 ( V_115 ) ;
if ( V_53 < 0 ) {
F_50 ( L_4 ) ;
return V_53 ;
}
F_51 (plane, drm) {
if ( V_67 -> type == V_118 ) {
V_117 = V_67 ;
break;
}
}
if ( ! V_117 ) {
F_50 ( L_5 ) ;
V_53 = - V_48 ;
goto V_119;
}
V_53 = F_52 ( V_115 , & V_7 -> V_2 , V_117 , NULL ,
& V_120 , NULL ) ;
if ( V_53 )
goto V_119;
F_53 ( & V_7 -> V_2 , & V_121 ) ;
F_54 ( & V_7 -> V_2 , V_49 ) ;
F_55 ( & V_7 -> V_2 , 0 , true , V_49 ) ;
F_56 ( V_7 -> V_10 ) ;
return 0 ;
V_119:
F_57 ( V_115 ) ;
return V_53 ;
}
