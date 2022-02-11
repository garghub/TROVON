static void F_1 ( T_1 * V_1 , unsigned char * V_2 ,
int V_3 )
{
struct V_4 * V_5 ;
if ( V_3 < sizeof( struct V_4 ) ) {
F_2 ( V_6 L_1
L_2 , V_1 -> V_7 -> V_8 , V_3 ) ;
return;
}
V_5 = (struct V_4 * ) V_2 ;
#define F_3 ( V_8 ) \
local->comm_tallies.name += le16_to_cpu(tallies->name)
F_3 ( V_9 ) ;
F_3 ( V_10 ) ;
F_3 ( V_11 ) ;
F_3 ( V_12 ) ;
F_3 ( V_13 ) ;
F_3 ( V_14 ) ;
F_3 ( V_15 ) ;
F_3 ( V_16 ) ;
F_3 ( V_17 ) ;
F_3 ( V_18 ) ;
F_3 ( V_19 ) ;
F_3 ( V_20 ) ;
F_3 ( V_21 ) ;
F_3 ( V_22 ) ;
F_3 ( V_23 ) ;
F_3 ( V_24 ) ;
F_3 ( V_25 ) ;
F_3 ( V_26 ) ;
F_3 ( V_27 ) ;
F_3 ( V_28 ) ;
F_3 ( V_29 ) ;
#undef F_3
}
static void F_4 ( T_1 * V_1 , unsigned char * V_2 ,
int V_3 )
{
struct V_30 * V_5 ;
if ( V_3 < sizeof( struct V_30 ) ) {
F_2 ( V_6 L_3
L_2 , V_1 -> V_7 -> V_8 , V_3 ) ;
return;
}
V_5 = (struct V_30 * ) V_2 ;
#define F_3 ( V_8 ) \
local->comm_tallies.name += le32_to_cpu(tallies->name)
F_3 ( V_9 ) ;
F_3 ( V_10 ) ;
F_3 ( V_11 ) ;
F_3 ( V_12 ) ;
F_3 ( V_13 ) ;
F_3 ( V_14 ) ;
F_3 ( V_15 ) ;
F_3 ( V_16 ) ;
F_3 ( V_17 ) ;
F_3 ( V_18 ) ;
F_3 ( V_19 ) ;
F_3 ( V_20 ) ;
F_3 ( V_21 ) ;
F_3 ( V_22 ) ;
F_3 ( V_23 ) ;
F_3 ( V_24 ) ;
F_3 ( V_25 ) ;
F_3 ( V_26 ) ;
F_3 ( V_27 ) ;
F_3 ( V_28 ) ;
F_3 ( V_29 ) ;
#undef F_3
}
static void F_5 ( T_1 * V_1 , unsigned char * V_2 ,
int V_3 )
{
if ( V_1 -> V_31 )
F_4 ( V_1 , V_2 , V_3 ) ;
else
F_1 ( V_1 , V_2 , V_3 ) ;
}
static const char * F_6 ( T_2 V_32 )
{
switch ( V_32 ) {
case V_33 :
return L_4 ;
case V_34 :
return L_5 ;
case V_35 :
return L_6 ;
case V_36 :
return L_7 ;
case V_37 :
return L_8 ;
case V_38 :
return L_9 ;
default:
return L_10 ;
}
}
static void F_7 ( T_1 * V_1 , unsigned char * V_2 ,
int V_3 )
{
T_2 V_39 ;
int V_40 ;
V_1 -> V_41 = 0 ;
if ( V_3 != 2 ) {
F_2 ( V_6 L_11
L_12 , V_1 -> V_7 -> V_8 , V_3 ) ;
return;
}
V_40 = V_1 -> V_42 == V_43 ||
V_1 -> V_42 == V_44 ||
V_1 -> V_42 == V_45 ;
V_39 = V_2 [ 0 ] | ( V_2 [ 1 ] << 8 ) ;
if ( ! V_40 || V_39 != V_34 ) {
F_8 ( V_46 , L_13 ,
V_1 -> V_7 -> V_8 , V_39 , F_6 ( V_39 ) ) ;
}
if ( V_40 ) {
F_9 ( V_1 -> V_7 ) ;
F_9 ( V_1 -> V_47 ) ;
return;
}
F_10 ( V_48 , & V_1 -> V_49 ) ;
V_1 -> V_50 = V_39 ;
F_11 ( & V_1 -> V_51 ) ;
}
static void F_12 ( T_1 * V_1 )
{
struct V_52 V_53 ;
struct V_54 * V_7 = V_1 -> V_7 ;
struct V_55 * V_56 , * V_57 ;
int V_58 ;
unsigned long V_59 ;
if ( V_1 -> V_41 &&
F_13 ( V_60 , V_1 -> V_41 + 10 * V_61 ) ) {
F_8 ( V_46 , L_14
L_15 ,
V_7 -> V_8 ) ;
return;
}
F_14 ( & V_1 -> V_62 , V_59 ) ;
if ( V_1 -> V_63 == NULL ||
V_1 -> V_64 == 0 ) {
F_15 ( & V_1 -> V_62 , V_59 ) ;
F_8 ( V_46 , L_16 ,
V_7 -> V_8 ) ;
return;
}
V_56 = & V_1 -> V_63 [ 0 ] ;
if ( V_1 -> V_65 [ 0 ] || V_1 -> V_65 [ 1 ] ||
V_1 -> V_65 [ 2 ] || V_1 -> V_65 [ 3 ] ||
V_1 -> V_65 [ 4 ] || V_1 -> V_65 [ 5 ] ) {
F_8 ( V_46 , L_17 ,
V_7 -> V_8 , V_1 -> V_65 ) ;
for ( V_58 = 0 ; V_58 < V_1 -> V_64 ; V_58 ++ ) {
V_57 = & V_1 -> V_63 [ V_58 ] ;
if ( memcmp ( V_1 -> V_65 , V_57 -> V_66 , 6 ) == 0 )
{
F_8 ( V_46 , L_18
L_19 , V_7 -> V_8 ) ;
V_56 = V_57 ;
break;
}
}
}
memcpy ( V_53 . V_66 , V_56 -> V_66 , V_67 ) ;
V_53 . V_68 = V_56 -> V_69 ;
F_15 ( & V_1 -> V_62 , V_59 ) ;
F_8 ( V_46 , L_20
L_21 ,
V_7 -> V_8 , V_53 . V_66 , F_16 ( V_53 . V_68 ) ) ;
if ( V_1 -> V_70 -> V_71 ( V_7 , V_72 , & V_53 ,
sizeof( V_53 ) ) ) {
F_2 ( V_6 L_22 , V_7 -> V_8 ) ;
}
V_1 -> V_41 = V_60 ;
}
static void F_17 ( T_1 * V_1 )
{
union V_73 V_74 ;
V_74 . V_75 . V_76 = 0 ;
V_74 . V_75 . V_59 = 0 ;
F_18 ( V_1 -> V_7 , V_77 , & V_74 , NULL ) ;
V_1 -> V_78 = 0 ;
}
static void F_19 ( T_1 * V_1 , unsigned char * V_2 ,
int V_3 )
{
T_2 * V_79 ;
int V_80 , V_58 ;
unsigned long V_59 ;
struct V_81 * V_82 ;
struct V_55 * V_83 , * V_84 ;
if ( V_3 < 4 ) {
F_2 ( V_6 L_23
L_12 , V_1 -> V_7 -> V_8 , V_3 ) ;
return;
}
V_79 = ( T_2 * ) V_2 ;
V_79 ++ ;
V_79 ++ ;
V_3 -= 4 ;
V_80 = V_3 / sizeof( struct V_81 ) ;
V_83 = F_20 ( V_80 * sizeof( struct V_55 ) ,
V_85 ) ;
if ( V_83 == NULL )
return;
V_82 = (struct V_81 * ) V_79 ;
for ( V_58 = 0 ; V_58 < V_80 ; V_58 ++ ) {
memcpy ( & V_83 [ V_58 ] , & V_82 [ V_58 ] ,
sizeof( struct V_81 ) ) ;
V_83 [ V_58 ] . V_86 = 0 ;
}
F_14 ( & V_1 -> V_62 , V_59 ) ;
V_1 -> V_87 = V_88 ;
V_84 = V_1 -> V_63 ;
V_1 -> V_63 = V_83 ;
V_1 -> V_64 = V_80 ;
F_15 ( & V_1 -> V_62 , V_59 ) ;
F_21 ( V_84 ) ;
F_17 ( V_1 ) ;
F_10 ( V_89 , & V_1 -> V_49 ) ;
F_11 ( & V_1 -> V_51 ) ;
}
static void F_22 ( T_1 * V_1 ,
unsigned char * V_2 , int V_3 )
{
int V_58 , V_90 , V_91 , V_80 ;
struct V_55 * V_83 , * V_84 ;
unsigned long V_59 ;
T_3 * V_79 ;
T_4 * V_92 ;
F_23 ( & V_1 -> V_93 ) ;
if ( V_3 < 4 ) {
F_2 ( V_6 L_24
L_12 , V_1 -> V_7 -> V_8 , V_3 ) ;
return;
}
V_79 = ( T_3 * ) V_2 ;
V_91 = V_90 = F_16 ( * V_79 ) ;
if ( V_90 == 0 ) {
F_2 ( V_6 L_25
L_26 , V_1 -> V_7 -> V_8 ) ;
return;
}
if ( V_91 > sizeof( struct V_55 ) )
V_91 = sizeof( struct V_55 ) ;
V_79 ++ ;
V_79 ++ ;
V_3 -= 4 ;
V_92 = ( T_4 * ) V_79 ;
V_80 = V_3 / V_90 ;
V_83 = F_24 ( V_80 , sizeof( struct V_55 ) ,
V_85 ) ;
if ( V_83 == NULL )
return;
for ( V_58 = 0 ; V_58 < V_80 ; V_58 ++ ) {
memcpy ( & V_83 [ V_58 ] , V_92 , V_91 ) ;
V_92 += V_90 ;
V_3 -= V_90 ;
}
if ( V_3 ) {
F_2 ( V_6 L_27 ,
V_1 -> V_7 -> V_8 , V_3 , V_90 ) ;
}
F_14 ( & V_1 -> V_62 , V_59 ) ;
V_1 -> V_87 = V_94 ;
V_84 = V_1 -> V_63 ;
V_1 -> V_63 = V_83 ;
V_1 -> V_64 = V_80 ;
F_15 ( & V_1 -> V_62 , V_59 ) ;
F_21 ( V_84 ) ;
F_17 ( V_1 ) ;
}
void F_25 ( T_1 * V_1 , struct V_95 * V_96 )
{
struct V_97 * V_98 ;
unsigned char * V_2 ;
int V_3 ;
#ifndef F_26
int V_58 ;
#endif
V_98 = (struct V_97 * ) V_96 -> V_75 ;
V_2 = V_96 -> V_75 + sizeof( * V_98 ) ;
V_3 = V_96 -> V_99 - sizeof( * V_98 ) ;
switch ( F_16 ( V_98 -> type ) ) {
case V_100 :
F_5 ( V_1 , V_2 , V_3 ) ;
break;
#ifndef F_27
case V_101 :
F_7 ( V_1 , V_2 , V_3 ) ;
break;
case V_102 :
F_19 ( V_1 , V_2 , V_3 ) ;
break;
case V_103 :
F_22 ( V_1 , V_2 , V_3 ) ;
break;
#endif
#ifndef F_26
default:
F_8 ( V_46 , L_28 ,
V_1 -> V_7 -> V_8 , F_16 ( V_98 -> V_99 ) ,
F_16 ( V_98 -> type ) ) ;
F_8 ( V_46 , L_29 ) ;
for ( V_58 = 0 ; V_58 < ( V_3 < 100 ? V_3 : 100 ) ; V_58 ++ )
F_28 ( V_46 , L_30 , V_2 [ V_58 ] ) ;
F_28 ( V_46 , L_31 ) ;
break;
#endif
}
}
static void F_29 ( T_1 * V_1 )
{
int V_39 = V_1 -> V_50 ;
int V_104 ;
union V_73 V_74 ;
V_104 =
V_39 == V_33 ||
V_39 == V_35 ||
V_39 == V_37 ;
if ( V_1 -> V_70 -> V_105 ( V_1 -> V_7 , V_106 ,
V_1 -> V_66 , V_67 , 1 ) < 0 ) {
F_2 ( V_6 L_32
L_33 , V_1 -> V_7 -> V_8 ) ;
} else {
F_8 ( V_46 , L_34 ,
V_1 -> V_7 -> V_8 ,
( unsigned char * ) V_1 -> V_66 ) ;
if ( V_1 -> V_107 & V_108 )
F_30 ( V_1 -> V_109 , V_1 -> V_66 ) ;
}
if ( V_104 ) {
F_9 ( V_1 -> V_7 ) ;
F_9 ( V_1 -> V_47 ) ;
memcpy ( V_74 . V_110 . V_111 , V_1 -> V_66 , V_67 ) ;
} else {
F_31 ( V_1 -> V_7 ) ;
F_31 ( V_1 -> V_47 ) ;
F_32 ( V_74 . V_110 . V_111 ) ;
}
V_74 . V_110 . V_112 = V_113 ;
if ( V_104 || V_1 -> V_114 )
F_18 ( V_1 -> V_7 , V_115 , & V_74 , NULL ) ;
V_1 -> V_114 = V_104 ;
}
static void F_33 ( T_1 * V_1 )
{
if ( V_1 -> V_116 == 1 && V_1 -> V_42 == V_117 )
F_12 ( V_1 ) ;
if ( V_1 -> V_116 == 2 && V_1 -> V_42 == V_117 &&
! F_34 ( V_1 -> V_65 ) ) {
F_12 ( V_1 ) ;
}
}
static void F_35 ( struct V_118 * V_119 )
{
T_1 * V_1 = F_36 ( V_119 , T_1 , V_51 ) ;
if ( F_37 ( V_48 ,
& V_1 -> V_49 ) )
F_29 ( V_1 ) ;
if ( F_37 ( V_89 ,
& V_1 -> V_49 ) )
F_33 ( V_1 ) ;
}
void F_38 ( T_1 * V_1 )
{
F_39 ( & V_1 -> V_120 ) ;
#ifndef F_27
F_40 ( & V_1 -> V_51 , F_35 ) ;
#endif
}
