static inline void T_1 *
F_1 ( struct V_1 * V_2 )
{
return & V_2 -> V_3 -> V_4 -> V_5 ;
}
static inline void
F_2 ( T_2 V_6 , void * V_7 , T_3 * V_8 )
{
if ( V_7 ) {
V_7 += * V_8 ;
* ( V_9 * ) V_7 = F_3 ( V_6 ) ;
}
* V_8 += sizeof( V_6 ) ;
}
static inline void
F_4 ( T_4 V_6 , void * V_7 , T_3 * V_8 )
{
if ( V_7 ) {
V_7 += * V_8 ;
* ( V_10 * ) V_7 = F_5 ( V_6 ) ;
}
* V_8 += sizeof( V_6 ) ;
}
static inline void
F_6 ( void * V_11 , T_3 V_12 , void * V_7 , T_3 * V_8 )
{
if ( V_7 && V_11 && V_12 ) {
V_7 += * V_8 ;
memcpy ( V_7 , V_11 , V_12 ) ;
}
* V_8 += V_12 ;
}
static inline void
F_7 ( void T_1 * V_13 , void * V_7 , T_3 * V_8 )
{
T_5 V_6 = ~ 0 ;
if ( V_7 ) {
V_6 = F_8 ( V_13 ) ;
}
F_4 ( V_6 , V_7 , V_8 ) ;
}
static inline void
F_9 ( void T_1 * V_13 , void * V_7 , T_3 * V_8 )
{
T_2 V_6 = ~ 0 ;
if ( V_7 ) {
V_6 = F_10 ( V_13 ) ;
}
F_4 ( V_6 , V_7 , V_8 ) ;
}
static inline void
F_11 ( void T_1 * V_13 , void * V_7 , T_3 * V_8 )
{
T_4 V_6 = ~ 0 ;
if ( V_7 ) {
V_6 = F_12 ( V_13 ) ;
}
F_4 ( V_6 , V_7 , V_8 ) ;
}
static inline void
F_13 ( T_1 struct V_14 * V_15 ,
T_6 V_16 , void * V_7 , T_3 * V_8 )
{
void T_1 * V_13 = ( void T_1 * ) V_15 + V_16 ;
F_11 ( V_13 , V_7 , V_8 ) ;
}
static inline void
F_14 ( T_1 struct V_14 * V_15 ,
T_6 V_16 , T_4 V_17 , void * V_7 )
{
T_1 void * V_13 = ( void T_1 * ) V_15 + V_16 ;
if ( V_7 ) {
F_15 ( V_13 , V_17 ) ;
}
}
static inline void
F_16 ( T_1 struct V_14 * V_15 ,
T_4 V_18 , T_6 V_16 , T_6 V_19 , T_6 V_20 , void * V_7 ,
T_3 * V_8 )
{
void T_1 * V_13 = ( void T_1 * ) V_15 + V_16 ;
void (* F_17)( void T_1 * , void * , T_3 * ) = F_18 ( V_20 ) ;
F_14 ( V_15 , V_21 , V_18 , V_7 ) ;
while ( V_19 -- ) {
F_4 ( V_18 , V_7 , V_8 ) ;
F_17 ( V_13 , V_7 , V_8 ) ;
V_13 += V_20 ;
V_18 ++ ;
}
}
static inline void
F_19 ( struct V_22 * V_23 , void * V_7 )
{
if ( V_7 )
V_23 -> V_24 . V_25 |= V_26 ;
F_20 ( V_27 + V_28 , NULL , 0xd011 ,
L_1 , V_23 -> V_24 . V_29 ) ;
}
static int
F_21 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_20 ( V_27 , V_2 , 0xd100 ,
L_2 , V_30 , * V_8 ) ;
F_19 ( V_23 , V_7 ) ;
return false ;
}
static int
F_22 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_20 ( V_27 , V_2 , 0xd1ff ,
L_3 , V_30 , * V_8 ) ;
F_19 ( V_23 , V_7 ) ;
return true ;
}
static int
F_23 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_20 ( V_27 , V_2 , 0xd200 ,
L_4 , V_30 , * V_8 ) ;
F_16 ( V_15 , V_23 -> V_31 . V_32 , V_23 -> V_31 . V_33 ,
V_23 -> V_31 . V_34 , V_23 -> V_31 . V_35 , V_7 , V_8 ) ;
return false ;
}
static int
F_24 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_20 ( V_27 , V_2 , 0xd201 ,
L_5 , V_30 , * V_8 ) ;
F_14 ( V_15 , V_21 , V_23 -> V_36 . V_32 , V_7 ) ;
F_14 ( V_15 , V_23 -> V_36 . V_33 , V_23 -> V_36 . V_37 , V_7 ) ;
return false ;
}
static int
F_25 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_20 ( V_27 , V_2 , 0xd202 ,
L_6 , V_30 , * V_8 ) ;
F_14 ( V_15 , V_23 -> V_38 . V_39 , V_23 -> V_38 . V_40 , V_7 ) ;
F_16 ( V_15 , V_23 -> V_38 . V_32 , V_23 -> V_38 . V_33 ,
V_23 -> V_38 . V_34 , V_23 -> V_38 . V_35 , V_7 , V_8 ) ;
return false ;
}
static int
F_26 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_20 ( V_27 , V_2 , 0xd203 ,
L_7 , V_30 , * V_8 ) ;
F_14 ( V_15 , V_21 , V_23 -> V_41 . V_32 , V_7 ) ;
F_14 ( V_15 , V_23 -> V_41 . V_39 , V_23 -> V_41 . V_40 , V_7 ) ;
F_14 ( V_15 , V_23 -> V_41 . V_33 , V_23 -> V_41 . V_37 , V_7 ) ;
return false ;
}
static int
F_27 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_20 ( V_27 , V_2 , 0xd204 ,
L_8 , V_30 , * V_8 ) ;
F_4 ( V_23 -> V_42 . V_33 , V_7 , V_8 ) ;
F_13 ( V_15 , V_23 -> V_42 . V_33 , V_7 , V_8 ) ;
return false ;
}
static int
F_28 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_20 ( V_27 , V_2 , 0xd205 ,
L_9 , V_30 , * V_8 ) ;
F_14 ( V_15 , V_23 -> V_43 . V_33 , V_23 -> V_43 . V_37 , V_7 ) ;
return false ;
}
static int
F_29 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_3 V_44 ;
T_3 V_45 ;
T_3 V_46 ;
F_20 ( V_27 , V_2 , 0xd206 ,
L_10 , V_30 , V_23 -> V_47 . V_48 , * V_8 ) ;
V_45 = V_23 -> V_47 . V_49 ;
V_46 = V_23 -> V_47 . V_50 ;
if ( V_23 -> V_47 . V_48 == V_51 ) {
;
} else if ( V_23 -> V_47 . V_48 == V_52 ) {
V_46 = V_2 -> V_3 -> V_53 ;
if ( V_7 )
V_23 -> V_47 . V_50 = V_46 ;
} else if ( V_23 -> V_47 . V_48 == V_54 ) {
V_45 = V_2 -> V_3 -> V_55 ;
V_46 = V_2 -> V_3 -> V_56 ;
if ( V_7 ) {
V_23 -> V_47 . V_49 = V_45 ;
V_23 -> V_47 . V_50 = V_46 ;
}
} else if ( V_23 -> V_47 . V_48 == V_57 ) {
V_45 = V_2 -> V_3 -> V_58 ;
V_46 = V_2 -> V_3 -> V_59 ;
if ( V_7 ) {
V_23 -> V_47 . V_49 = V_45 ;
V_23 -> V_47 . V_50 = V_46 ;
}
} else {
F_20 ( V_27 , V_2 , 0xd022 ,
L_11 , V_30 , V_23 -> V_47 . V_48 ) ;
F_19 ( V_23 , V_7 ) ;
goto V_60;
}
if ( V_46 <= V_45 || V_45 == 0 || V_46 == 0 ) {
F_20 ( V_27 , V_2 , 0xd023 ,
L_12 , V_30 ,
V_23 -> V_47 . V_50 , V_23 -> V_47 . V_49 ) ;
F_19 ( V_23 , V_7 ) ;
goto V_60;
}
V_44 = V_46 - V_45 + 1 ;
if ( V_7 ) {
V_7 += * V_8 ;
F_30 ( V_2 -> V_3 , V_45 , V_7 , V_44 , & V_7 ) ;
}
* V_8 += V_44 * sizeof( T_4 ) ;
V_60:
return false ;
}
static int
F_31 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_6 V_19 = 0 ;
T_6 V_61 ;
T_6 V_62 ;
F_20 ( V_27 , V_2 , 0xd207 ,
L_13 , V_30 , V_23 -> V_63 . V_64 , * V_8 ) ;
if ( V_23 -> V_63 . V_64 == V_65 ) {
for ( V_61 = 0 ; V_61 < V_2 -> V_3 -> V_66 ; V_61 ++ ) {
struct V_67 * V_68 = V_2 -> V_3 -> V_69 [ V_61 ] ;
if ( ! F_32 ( V_61 , V_2 -> V_3 -> V_70 ) )
continue;
if ( V_68 || ! V_7 ) {
V_62 = V_68 ?
V_68 -> V_62 : V_71 ;
F_2 ( V_61 , V_7 , V_8 ) ;
F_2 ( V_62 , V_7 , V_8 ) ;
F_6 ( V_68 ? V_68 -> V_72 : NULL ,
V_62 * sizeof( * V_68 -> V_72 ) , V_7 , V_8 ) ;
V_19 ++ ;
}
}
} else if ( V_23 -> V_63 . V_64 == V_73 ) {
for ( V_61 = 0 ; V_61 < V_2 -> V_3 -> V_74 ; V_61 ++ ) {
struct V_75 * V_76 = V_2 -> V_3 -> V_77 [ V_61 ] ;
if ( ! F_32 ( V_61 , V_2 -> V_3 -> V_78 ) )
continue;
if ( V_76 || ! V_7 ) {
V_62 = V_76 ?
V_76 -> V_62 : V_79 ;
F_2 ( V_61 , V_7 , V_8 ) ;
F_2 ( V_62 , V_7 , V_8 ) ;
F_6 ( V_76 ? V_76 -> V_72 : NULL ,
V_62 * sizeof( * V_76 -> V_72 ) , V_7 , V_8 ) ;
V_19 ++ ;
}
}
} else {
F_20 ( V_27 , V_2 , 0xd026 ,
L_14 , V_30 , V_23 -> V_63 . V_64 ) ;
F_19 ( V_23 , V_7 ) ;
}
if ( V_7 )
V_23 -> V_63 . V_80 = V_19 ;
return false ;
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_20 ( V_27 , V_2 , 0xd208 ,
L_15 , V_30 , * V_8 ) ;
if ( V_2 -> V_3 -> V_81 ) {
if ( V_7 ) {
V_23 -> V_82 . V_83 = V_84 ;
V_23 -> V_82 . V_85 = V_2 -> V_3 -> V_86 ;
V_23 -> V_82 . V_87 = V_2 -> V_3 -> V_88 ;
V_23 -> V_82 . V_89 = V_2 -> V_3 -> V_90 [ 0 ] ;
V_23 -> V_82 . V_91 = V_2 -> V_3 -> V_90 [ 2 ] ;
V_23 -> V_82 . V_92 = V_2 -> V_3 -> V_90 [ 3 ] ;
V_23 -> V_82 . V_93 = V_2 -> V_3 -> V_90 [ 4 ] ;
V_23 -> V_82 . V_94 = V_2 -> V_3 -> V_90 [ 5 ] ;
V_23 -> V_82 . V_95 = V_2 -> V_3 -> V_90 [ 6 ] ;
}
F_6 ( V_2 -> V_3 -> V_81 , V_84 , V_7 , V_8 ) ;
} else {
F_20 ( V_27 , V_2 , 0xd027 ,
L_16 , V_30 ) ;
F_19 ( V_23 , V_7 ) ;
}
return false ;
}
static int
F_34 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_20 ( V_27 , V_2 , 0xd209 ,
L_17 , V_30 , * V_8 ) ;
if ( V_7 )
F_35 ( V_15 , V_2 -> V_3 ) ;
return false ;
}
static int
F_36 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_20 ( V_27 , V_2 , 0xd20a ,
L_18 , V_30 , * V_8 ) ;
if ( V_7 )
F_37 ( V_2 -> V_3 ) ;
return false ;
}
static int
F_38 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_20 ( V_27 , V_2 , 0xd20b ,
L_19 , V_30 , * V_8 ) ;
F_14 ( V_15 , V_23 -> V_96 . V_33 , V_23 -> V_96 . V_17 , V_7 ) ;
return false ;
}
static int
F_39 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_20 ( V_27 , V_2 , 0xd20c ,
L_20 , V_30 , V_23 -> V_97 . V_98 , * V_8 ) ;
if ( V_23 -> V_97 . V_98 == V_99 ) {
if ( V_2 -> V_3 -> V_100 ) {
if ( V_7 ) {
V_23 -> V_97 . V_101 = V_102 ;
V_23 -> V_97 . V_49 = V_2 -> V_3 -> V_103 ;
}
F_6 ( V_2 -> V_3 -> V_100 , V_102 , V_7 , V_8 ) ;
} else {
F_20 ( V_27 , V_2 , 0xd028 ,
L_21 , V_30 ) ;
F_19 ( V_23 , V_7 ) ;
}
} else {
F_20 ( V_27 , V_2 , 0xd02b ,
L_22 , V_30 , V_23 -> V_97 . V_98 ) ;
F_19 ( V_23 , V_7 ) ;
}
return false ;
}
static int
F_40 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_20 ( V_27 , V_2 , 0xd20d ,
L_23 , V_30 , * V_8 ) ;
F_4 ( 0xaaaaaaaa , V_7 , V_8 ) ;
F_4 ( 0xbbbbbbbb , V_7 , V_8 ) ;
F_4 ( 0xcccccccc , V_7 , V_8 ) ;
F_4 ( 0xdddddddd , V_7 , V_8 ) ;
F_4 ( * V_8 + sizeof( T_4 ) , V_7 , V_8 ) ;
if ( V_7 )
V_23 -> V_104 . V_105 = 5 * sizeof( T_4 ) ;
return false ;
}
static int
F_41 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
T_3 V_44 = V_23 -> V_106 . V_19 ;
T_3 V_18 = V_23 -> V_106 . V_18 ;
F_20 ( V_27 , V_2 , 0xd20e ,
L_24 , V_30 , * V_8 ) ;
F_14 ( V_15 , V_21 , 0x40 , V_7 ) ;
while ( V_44 -- ) {
F_14 ( V_15 , 0xc0 , V_18 | 0x80000000 , V_7 ) ;
F_4 ( V_18 , V_7 , V_8 ) ;
F_13 ( V_15 , 0xc4 , V_7 , V_8 ) ;
V_18 += sizeof( T_4 ) ;
}
return false ;
}
static int
F_42 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
T_3 V_18 = V_23 -> V_107 . V_18 ;
T_3 V_17 = V_23 -> V_107 . V_17 ;
F_20 ( V_27 , V_2 , 0xd20f ,
L_25 , V_30 , * V_8 ) ;
F_14 ( V_15 , V_21 , 0x40 , V_7 ) ;
F_14 ( V_15 , 0xc4 , V_17 , V_7 ) ;
F_14 ( V_15 , 0xc0 , V_18 , V_7 ) ;
return false ;
}
static int
F_43 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_3 V_44 = V_23 -> V_108 . V_19 ;
T_3 V_45 = V_23 -> V_108 . V_18 ;
F_20 ( V_27 , V_2 , 0xd210 ,
L_26 , V_30 , * V_8 ) ;
if ( V_7 ) {
F_20 ( V_27 , V_2 , 0xd02c ,
L_27 , V_30 , V_45 , V_44 ) ;
V_7 += * V_8 ;
F_44 ( V_2 -> V_3 , V_45 , V_7 , V_44 , & V_7 ) ;
}
* V_8 += V_44 * sizeof( T_4 ) ;
return false ;
}
static int
F_45 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_3 V_44 = V_23 -> V_109 . V_19 ;
T_3 V_18 = V_23 -> V_109 . V_18 ;
T_4 V_6 ;
F_20 ( V_27 , V_2 , 0xd211 ,
L_28 , V_30 , * V_8 ) ;
while ( V_44 -- ) {
V_6 = ~ 0 ;
if ( F_46 ( V_2 -> V_3 -> V_110 , V_18 , & V_6 ) )
F_20 ( V_27 , V_2 , 0xd02d ,
L_29 , V_30 , V_18 ) ;
F_4 ( V_18 , V_7 , V_8 ) ;
F_4 ( V_6 , V_7 , V_8 ) ;
V_18 += sizeof( T_4 ) ;
}
return false ;
}
static int
F_47 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_6 V_19 = 0 ;
T_6 V_61 ;
F_20 ( V_27 , V_2 , 0xd212 ,
L_30 , V_30 , V_23 -> V_111 . V_64 , * V_8 ) ;
if ( V_23 -> V_111 . V_64 == V_112 ) {
for ( V_61 = 0 ; V_61 < V_2 -> V_3 -> V_66 ; V_61 ++ ) {
struct V_67 * V_68 = V_2 -> V_3 -> V_69 [ V_61 ] ;
if ( ! F_32 ( V_61 , V_2 -> V_3 -> V_70 ) )
continue;
if ( V_68 || ! V_7 ) {
F_2 ( V_61 , V_7 , V_8 ) ;
F_2 ( 1 , V_7 , V_8 ) ;
F_4 ( V_68 && V_68 -> V_113 ?
* V_68 -> V_113 : 0 , V_7 , V_8 ) ;
V_19 ++ ;
}
}
} else if ( V_23 -> V_111 . V_64 == V_114 ) {
for ( V_61 = 0 ; V_61 < V_2 -> V_3 -> V_74 ; V_61 ++ ) {
struct V_75 * V_76 = V_2 -> V_3 -> V_77 [ V_61 ] ;
if ( ! F_32 ( V_61 , V_2 -> V_3 -> V_78 ) )
continue;
if ( V_76 || ! V_7 ) {
F_2 ( V_61 , V_7 , V_8 ) ;
F_2 ( 1 , V_7 , V_8 ) ;
F_4 ( V_76 && V_76 -> V_115 ?
* V_76 -> V_115 : 0 , V_7 , V_8 ) ;
V_19 ++ ;
}
}
} else {
F_20 ( V_27 , V_2 , 0xd02f ,
L_14 , V_30 , V_23 -> V_111 . V_64 ) ;
F_19 ( V_23 , V_7 ) ;
}
if ( V_7 )
V_23 -> V_111 . V_80 = V_19 ;
if ( ! V_19 )
F_19 ( V_23 , V_7 ) ;
return false ;
}
static int
F_48 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_3 V_16 = F_49 ( F_50 ( * V_23 ) , V_116 . V_117 ) ;
F_20 ( V_27 , V_2 , 0xd213 ,
L_31 , V_30 , V_23 -> V_116 . V_62 , * V_8 ) ;
if ( ! V_23 -> V_116 . V_62 ) {
F_20 ( V_27 , V_2 , 0xd020 ,
L_32 , V_30 ) ;
F_19 ( V_23 , V_7 ) ;
goto V_60;
}
if ( V_16 + V_23 -> V_116 . V_62 > V_23 -> V_24 . V_118 ) {
F_20 ( V_27 , V_2 , 0xd030 ,
L_33 , V_30 ) ;
F_19 ( V_23 , V_7 ) ;
goto V_60;
}
F_6 ( V_23 -> V_116 . V_117 , V_23 -> V_116 . V_62 , V_7 , V_8 ) ;
V_60:
return false ;
}
static int
F_51 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_20 ( V_27 , V_2 , 0xd2ff ,
L_34 , V_30 , V_23 -> V_24 . V_29 , * V_8 ) ;
F_19 ( V_23 , V_7 ) ;
return false ;
}
inline void *
F_52 ( void * V_119 )
{
struct V_22 * V_23 = V_119 ;
return V_119 + V_23 -> V_24 . V_118 ;
}
static void
F_53 ( struct V_1 * V_2 ,
struct V_120 * V_121 , void * V_7 , T_3 * V_8 )
{
struct V_22 * V_23 = ( void * ) V_121 + V_121 -> V_122 ;
T_3 V_19 = V_121 -> V_123 ;
F_20 ( V_27 , V_2 , 0xd01a ,
L_35 , V_30 , V_19 ) ;
while ( V_19 -- ) {
if ( F_54 ( V_23 -> V_24 . V_29 ) ( V_2 , V_23 , V_7 , V_8 ) )
break;
V_23 = F_52 ( V_23 ) ;
}
if ( V_19 )
F_20 ( V_27 , V_2 , 0xd018 ,
L_36 , V_30 , V_19 ) ;
if ( V_23 -> V_24 . V_29 != V_124 )
F_20 ( V_27 , V_2 , 0xd019 ,
L_37 , V_30 , V_19 ) ;
F_20 ( V_27 , V_2 , 0xd01b ,
L_38 , V_30 , * V_8 ) ;
if ( V_7 ) {
F_55 ( V_125 , V_2 , 0xd015 ,
L_39 ,
V_2 -> V_126 , V_2 -> V_3 -> V_127 ) ;
F_56 ( V_2 , V_128 ) ;
}
}
static void
F_57 ( struct V_120 * V_121 )
{
V_121 -> V_129 = V_130 ;
}
static void
F_58 ( struct V_120 * V_121 )
{
T_5 V_131 [] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
sscanf ( V_132 , L_40 ,
V_131 + 0 , V_131 + 1 , V_131 + 2 , V_131 + 3 , V_131 + 4 , V_131 + 5 ) ;
V_121 -> V_133 [ 0 ] = V_131 [ 3 ] << 24 | V_131 [ 2 ] << 16 | V_131 [ 1 ] << 8 | V_131 [ 0 ] ;
V_121 -> V_133 [ 1 ] = V_131 [ 5 ] << 8 | V_131 [ 4 ] ;
V_121 -> V_133 [ 2 ] = 0x12345678 ;
}
static void
F_59 ( struct V_120 * V_121 ,
struct V_1 * V_2 )
{
V_121 -> V_134 [ 0 ] = V_2 -> V_3 -> V_135 ;
V_121 -> V_134 [ 1 ] = V_2 -> V_3 -> V_136 ;
V_121 -> V_134 [ 2 ] = V_2 -> V_3 -> V_137 ;
V_121 -> V_134 [ 3 ] =
V_2 -> V_3 -> V_138 << 16 | V_2 -> V_3 -> V_139 ;
V_121 -> V_134 [ 4 ] =
V_2 -> V_3 -> V_140 [ 1 ] << 16 | V_2 -> V_3 -> V_140 [ 0 ] ;
}
static void
F_60 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
F_57 ( V_121 ) ;
F_58 ( V_121 ) ;
F_59 ( V_121 , V_2 ) ;
}
static inline T_4
F_61 ( void * V_119 , T_3 V_12 )
{
T_4 * V_7 = V_119 ;
T_7 V_141 = 0 ;
V_12 /= sizeof( * V_7 ) ;
while ( V_12 -- )
V_141 += * V_7 ++ ;
V_141 = ( V_141 & 0xffffffff ) + ( V_141 >> 32 ) ;
return ~ V_141 ;
}
static inline int
F_62 ( struct V_120 * V_121 )
{
return F_61 ( V_121 , V_121 -> V_142 ) == 0 ;
}
static inline int
F_63 ( struct V_120 * V_121 )
{
return V_121 -> V_143 == V_144 ;
}
static void
F_64 ( struct V_1 * V_2 )
{
struct V_120 * V_121 = V_2 -> V_3 -> V_145 ;
T_3 V_8 ;
if ( F_65 ( V_121 ) ) {
V_8 = V_121 -> V_142 ;
V_121 = memcpy ( V_2 -> V_3 -> V_127 , V_121 , V_8 ) ;
F_60 ( V_2 , V_121 ) ;
F_53 ( V_2 , V_121 , V_121 , & V_8 ) ;
V_2 -> V_3 -> V_146 = V_8 ;
V_2 -> V_3 -> V_147 = 1 ;
}
}
T_3
F_66 ( struct V_1 * V_2 )
{
struct V_120 * V_121 = V_2 -> V_3 -> V_145 ;
T_3 V_8 = 0 ;
if ( F_65 ( V_121 ) ) {
V_8 = V_121 -> V_142 ;
F_53 ( V_2 , V_121 , NULL , & V_8 ) ;
}
return V_8 ;
}
T_3
F_67 ( void * V_119 )
{
struct V_120 * V_121 = V_119 ;
return V_121 -> V_142 ;
}
T_3
F_68 ( void )
{
return sizeof( V_148 ) ;
}
const void *
F_69 ( void )
{
return V_148 ;
}
int
F_65 ( void * V_119 )
{
struct V_120 * V_121 = V_119 ;
if ( ! F_63 ( V_121 ) ) {
F_55 ( V_125 , NULL , 0xd01c ,
L_41 , V_30 , V_121 -> V_143 ) ;
return false ;
}
if ( ! F_62 ( V_121 ) ) {
F_55 ( V_125 , NULL , 0xd01d ,
L_42 , V_30 ) ;
return false ;
}
return true ;
}
void
F_70 ( T_8 * V_2 , int V_149 )
{
T_3 V_150 = 0 ;
#ifndef F_71
if ( ! V_149 )
F_72 ( & V_2 -> V_3 -> V_151 , V_150 ) ;
#endif
if ( ! V_2 -> V_3 -> V_127 )
F_55 ( V_125 , V_2 , 0xd01e , L_43 ) ;
else if ( ! V_2 -> V_3 -> V_145 )
F_55 ( V_125 , V_2 , 0xd01f , L_44 ) ;
else if ( V_2 -> V_3 -> V_147 )
F_55 ( V_125 , V_2 , 0xd300 ,
L_45
L_46 , V_2 -> V_3 -> V_127 ) ;
else
F_64 ( V_2 ) ;
#ifndef F_71
if ( ! V_149 )
F_73 ( & V_2 -> V_3 -> V_151 , V_150 ) ;
#endif
}
