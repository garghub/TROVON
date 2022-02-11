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
}
static int
F_20 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_21 ( V_27 , V_2 , 0xd100 ,
L_1 , V_28 , * V_8 ) ;
F_19 ( V_23 , V_7 ) ;
return false ;
}
static int
F_22 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_21 ( V_27 , V_2 , 0xd1ff ,
L_2 , V_28 , * V_8 ) ;
F_19 ( V_23 , V_7 ) ;
return true ;
}
static int
F_23 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_21 ( V_27 , V_2 , 0xd200 ,
L_3 , V_28 , * V_8 ) ;
F_16 ( V_15 , V_23 -> V_29 . V_30 , V_23 -> V_29 . V_31 ,
V_23 -> V_29 . V_32 , V_23 -> V_29 . V_33 , V_7 , V_8 ) ;
return false ;
}
static int
F_24 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_21 ( V_27 , V_2 , 0xd201 ,
L_4 , V_28 , * V_8 ) ;
F_14 ( V_15 , V_21 , V_23 -> V_34 . V_30 , V_7 ) ;
F_14 ( V_15 , V_23 -> V_34 . V_31 , V_23 -> V_34 . V_35 , V_7 ) ;
return false ;
}
static int
F_25 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_21 ( V_27 , V_2 , 0xd202 ,
L_5 , V_28 , * V_8 ) ;
F_14 ( V_15 , V_23 -> V_36 . V_37 , V_23 -> V_36 . V_38 , V_7 ) ;
F_16 ( V_15 , V_23 -> V_36 . V_30 , V_23 -> V_36 . V_31 ,
V_23 -> V_36 . V_32 , V_23 -> V_36 . V_33 , V_7 , V_8 ) ;
return false ;
}
static int
F_26 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_21 ( V_27 , V_2 , 0xd203 ,
L_6 , V_28 , * V_8 ) ;
F_14 ( V_15 , V_21 , V_23 -> V_39 . V_30 , V_7 ) ;
F_14 ( V_15 , V_23 -> V_39 . V_37 , V_23 -> V_39 . V_38 , V_7 ) ;
F_14 ( V_15 , V_23 -> V_39 . V_31 , V_23 -> V_39 . V_35 , V_7 ) ;
return false ;
}
static int
F_27 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_21 ( V_27 , V_2 , 0xd204 ,
L_7 , V_28 , * V_8 ) ;
F_4 ( V_23 -> V_40 . V_31 , V_7 , V_8 ) ;
F_13 ( V_15 , V_23 -> V_40 . V_31 , V_7 , V_8 ) ;
return false ;
}
static int
F_28 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_21 ( V_27 , V_2 , 0xd205 ,
L_8 , V_28 , * V_8 ) ;
F_14 ( V_15 , V_23 -> V_41 . V_31 , V_23 -> V_41 . V_35 , V_7 ) ;
return false ;
}
static int
F_29 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_3 V_42 ;
T_3 V_43 ;
T_3 V_44 ;
F_21 ( V_27 , V_2 , 0xd206 ,
L_9 , V_28 , V_23 -> V_45 . V_46 , * V_8 ) ;
V_43 = V_23 -> V_45 . V_47 ;
V_44 = V_23 -> V_45 . V_48 ;
if ( V_23 -> V_45 . V_46 == V_49 ) {
;
} else if ( V_23 -> V_45 . V_46 == V_50 ) {
V_44 = V_2 -> V_3 -> V_51 ;
if ( V_7 )
V_23 -> V_45 . V_48 = V_44 ;
} else if ( V_23 -> V_45 . V_46 == V_52 ) {
V_43 = V_2 -> V_3 -> V_53 ;
V_44 = V_2 -> V_3 -> V_54 ;
if ( V_7 ) {
V_23 -> V_45 . V_47 = V_43 ;
V_23 -> V_45 . V_48 = V_44 ;
}
} else if ( V_23 -> V_45 . V_46 == V_55 ) {
V_43 = V_2 -> V_3 -> V_56 ;
V_44 = V_2 -> V_3 -> V_57 ;
if ( V_7 ) {
V_23 -> V_45 . V_47 = V_43 ;
V_23 -> V_45 . V_48 = V_44 ;
}
} else {
F_21 ( V_27 , V_2 , 0xd022 ,
L_10 , V_28 , V_23 -> V_45 . V_46 ) ;
F_19 ( V_23 , V_7 ) ;
goto V_58;
}
if ( V_44 < V_43 || V_43 == 0 || V_44 == 0 ) {
F_21 ( V_27 , V_2 , 0xd023 ,
L_11 , V_28 ,
V_23 -> V_45 . V_48 , V_23 -> V_45 . V_47 ) ;
F_19 ( V_23 , V_7 ) ;
goto V_58;
}
V_42 = V_44 - V_43 + 1 ;
if ( V_7 ) {
V_7 += * V_8 ;
F_30 ( V_2 -> V_3 , V_43 , V_7 , V_42 , & V_7 ) ;
}
* V_8 += V_42 * sizeof( T_4 ) ;
V_58:
return false ;
}
static int
F_31 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_6 V_19 = 0 ;
T_6 V_59 ;
T_6 V_60 ;
F_21 ( V_27 , V_2 , 0xd207 ,
L_12 , V_28 , V_23 -> V_61 . V_62 , * V_8 ) ;
if ( V_23 -> V_61 . V_62 == V_63 ) {
for ( V_59 = 0 ; V_59 < V_2 -> V_3 -> V_64 ; V_59 ++ ) {
struct V_65 * V_66 = V_2 -> V_3 -> V_67 [ V_59 ] ;
if ( V_66 || ! V_7 ) {
V_60 = V_66 ?
V_66 -> V_60 : V_68 ;
F_2 ( V_59 , V_7 , V_8 ) ;
F_2 ( V_60 , V_7 , V_8 ) ;
F_6 ( V_66 ? V_66 -> V_69 : NULL ,
V_60 * sizeof( * V_66 -> V_69 ) , V_7 , V_8 ) ;
V_19 ++ ;
}
}
} else if ( V_23 -> V_61 . V_62 == V_70 ) {
for ( V_59 = 0 ; V_59 < V_2 -> V_3 -> V_71 ; V_59 ++ ) {
struct V_72 * V_73 = V_2 -> V_3 -> V_74 [ V_59 ] ;
if ( V_73 || ! V_7 ) {
V_60 = V_73 ?
V_73 -> V_60 : V_75 ;
F_2 ( V_59 , V_7 , V_8 ) ;
F_2 ( V_60 , V_7 , V_8 ) ;
F_6 ( V_73 ? V_73 -> V_69 : NULL ,
V_60 * sizeof( * V_73 -> V_69 ) , V_7 , V_8 ) ;
V_19 ++ ;
}
}
} else if ( F_32 () &&
V_23 -> V_61 . V_62 == V_76 ) {
struct V_77 * V_78 = V_2 -> V_3 ;
struct V_79 * V_80 = V_78 -> V_81 . V_82 ;
if ( V_80 || ! V_7 ) {
V_60 = V_78 -> V_81 . V_83 ;
F_2 ( 0 , V_7 , V_8 ) ;
F_2 ( V_60 , V_7 , V_8 ) ;
F_6 ( V_80 , V_60 * sizeof( * V_80 ) , V_7 , V_8 ) ;
V_19 ++ ;
}
} else {
F_21 ( V_27 , V_2 , 0xd026 ,
L_13 , V_28 , V_23 -> V_61 . V_62 ) ;
F_19 ( V_23 , V_7 ) ;
}
if ( V_7 )
V_23 -> V_61 . V_84 = V_19 ;
return false ;
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_21 ( V_27 , V_2 , 0xd208 ,
L_14 , V_28 , * V_8 ) ;
if ( V_2 -> V_3 -> V_85 ) {
if ( V_7 ) {
V_23 -> V_86 . V_87 = V_88 ;
V_23 -> V_86 . V_89 = V_2 -> V_3 -> V_90 ;
V_23 -> V_86 . V_91 = V_2 -> V_3 -> V_92 ;
V_23 -> V_86 . V_93 = V_2 -> V_3 -> V_94 [ 0 ] ;
V_23 -> V_86 . V_95 = V_2 -> V_3 -> V_94 [ 2 ] ;
V_23 -> V_86 . V_96 = V_2 -> V_3 -> V_94 [ 3 ] ;
V_23 -> V_86 . V_97 = V_2 -> V_3 -> V_94 [ 4 ] ;
V_23 -> V_86 . V_98 = V_2 -> V_3 -> V_94 [ 5 ] ;
V_23 -> V_86 . V_99 = V_2 -> V_3 -> V_94 [ 6 ] ;
}
F_6 ( V_2 -> V_3 -> V_85 , V_88 , V_7 , V_8 ) ;
} else {
F_21 ( V_27 , V_2 , 0xd027 ,
L_15 , V_28 ) ;
F_19 ( V_23 , V_7 ) ;
}
return false ;
}
static int
F_34 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_21 ( V_27 , V_2 , 0xd209 ,
L_16 , V_28 , * V_8 ) ;
if ( V_7 )
F_35 ( V_15 , V_2 -> V_3 ) ;
return false ;
}
static int
F_36 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_21 ( V_27 , V_2 , 0xd20a ,
L_17 , V_28 , * V_8 ) ;
if ( V_7 )
F_37 ( V_2 -> V_3 ) ;
return false ;
}
static int
F_38 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_21 ( V_27 , V_2 , 0xd20b ,
L_18 , V_28 , * V_8 ) ;
F_14 ( V_15 , V_23 -> V_100 . V_31 , V_23 -> V_100 . V_17 , V_7 ) ;
return false ;
}
static int
F_39 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_21 ( V_27 , V_2 , 0xd20c ,
L_19 , V_28 , V_23 -> V_101 . V_102 , * V_8 ) ;
if ( V_23 -> V_101 . V_102 == V_103 ) {
if ( V_2 -> V_3 -> V_104 ) {
if ( V_7 ) {
V_23 -> V_101 . V_105 = V_106 ;
V_23 -> V_101 . V_47 = V_2 -> V_3 -> V_107 ;
}
F_6 ( V_2 -> V_3 -> V_104 , V_106 , V_7 , V_8 ) ;
} else {
F_21 ( V_27 , V_2 , 0xd028 ,
L_20 , V_28 ) ;
F_19 ( V_23 , V_7 ) ;
}
} else {
F_21 ( V_27 , V_2 , 0xd02b ,
L_21 , V_28 , V_23 -> V_101 . V_102 ) ;
F_19 ( V_23 , V_7 ) ;
}
return false ;
}
static int
F_40 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_21 ( V_27 , V_2 , 0xd20d ,
L_22 , V_28 , * V_8 ) ;
F_4 ( 0xaaaaaaaa , V_7 , V_8 ) ;
F_4 ( 0xbbbbbbbb , V_7 , V_8 ) ;
F_4 ( 0xcccccccc , V_7 , V_8 ) ;
F_4 ( 0xdddddddd , V_7 , V_8 ) ;
F_4 ( * V_8 + sizeof( T_4 ) , V_7 , V_8 ) ;
if ( V_7 )
V_23 -> V_108 . V_109 = 5 * sizeof( T_4 ) ;
return false ;
}
static int
F_41 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
T_3 V_42 = V_23 -> V_110 . V_19 ;
T_3 V_18 = V_23 -> V_110 . V_18 ;
F_21 ( V_27 , V_2 , 0xd20e ,
L_23 , V_28 , * V_8 ) ;
F_14 ( V_15 , V_21 , 0x40 , V_7 ) ;
while ( V_42 -- ) {
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
T_3 V_18 = V_23 -> V_111 . V_18 ;
T_3 V_17 = V_23 -> V_111 . V_17 ;
F_21 ( V_27 , V_2 , 0xd20f ,
L_24 , V_28 , * V_8 ) ;
F_14 ( V_15 , V_21 , 0x40 , V_7 ) ;
F_14 ( V_15 , 0xc4 , V_17 , V_7 ) ;
F_14 ( V_15 , 0xc0 , V_18 , V_7 ) ;
return false ;
}
static int
F_43 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_3 V_42 = V_23 -> V_112 . V_19 ;
T_3 V_43 = V_23 -> V_112 . V_18 ;
F_21 ( V_27 , V_2 , 0xd210 ,
L_25 , V_28 , * V_8 ) ;
if ( V_7 ) {
F_21 ( V_27 , V_2 , 0xd02c ,
L_26 , V_28 , V_43 , V_42 ) ;
V_7 += * V_8 ;
F_44 ( V_2 -> V_3 , V_43 , V_7 , V_42 , & V_7 ) ;
}
* V_8 += V_42 * sizeof( T_4 ) ;
return false ;
}
static int
F_45 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_3 V_42 = V_23 -> V_113 . V_19 ;
T_3 V_18 = V_23 -> V_113 . V_18 ;
T_4 V_6 ;
F_21 ( V_27 , V_2 , 0xd211 ,
L_27 , V_28 , * V_8 ) ;
while ( V_42 -- ) {
V_6 = ~ 0 ;
if ( F_46 ( V_2 -> V_3 -> V_114 , V_18 , & V_6 ) )
F_21 ( V_27 , V_2 , 0xd02d ,
L_28 , V_28 , V_18 ) ;
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
T_6 V_59 ;
F_21 ( V_27 , V_2 , 0xd212 ,
L_29 , V_28 , V_23 -> V_115 . V_62 , * V_8 ) ;
if ( V_23 -> V_115 . V_62 == V_116 ) {
for ( V_59 = 0 ; V_59 < V_2 -> V_3 -> V_64 ; V_59 ++ ) {
struct V_65 * V_66 = V_2 -> V_3 -> V_67 [ V_59 ] ;
if ( V_66 || ! V_7 ) {
F_2 ( V_59 , V_7 , V_8 ) ;
F_2 ( 1 , V_7 , V_8 ) ;
F_4 ( V_66 && V_66 -> V_117 ?
* V_66 -> V_117 : 0 , V_7 , V_8 ) ;
V_19 ++ ;
}
}
} else if ( V_23 -> V_115 . V_62 == V_118 ) {
for ( V_59 = 0 ; V_59 < V_2 -> V_3 -> V_71 ; V_59 ++ ) {
struct V_72 * V_73 = V_2 -> V_3 -> V_74 [ V_59 ] ;
if ( V_73 || ! V_7 ) {
F_2 ( V_59 , V_7 , V_8 ) ;
F_2 ( 1 , V_7 , V_8 ) ;
F_4 ( V_73 && V_73 -> V_119 ?
* V_73 -> V_119 : 0 , V_7 , V_8 ) ;
V_19 ++ ;
}
}
} else if ( F_32 () &&
V_23 -> V_115 . V_62 == V_120 ) {
struct V_77 * V_78 = V_2 -> V_3 ;
struct V_79 * V_80 = V_78 -> V_81 . V_121 ;
if ( V_80 || ! V_7 ) {
F_2 ( 0 , V_7 , V_8 ) ;
F_2 ( 1 , V_7 , V_8 ) ;
F_4 ( V_78 -> V_81 . V_122 ?
F_48 ( V_78 -> V_81 . V_122 ) : 0 , V_7 , V_8 ) ;
V_19 ++ ;
}
} else {
F_21 ( V_27 , V_2 , 0xd02f ,
L_13 , V_28 , V_23 -> V_115 . V_62 ) ;
F_19 ( V_23 , V_7 ) ;
}
if ( V_7 )
V_23 -> V_115 . V_84 = V_19 ;
if ( ! V_19 )
F_19 ( V_23 , V_7 ) ;
return false ;
}
static int
F_49 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_3 V_16 = F_50 ( F_51 ( * V_23 ) , V_123 . V_124 ) ;
F_21 ( V_27 , V_2 , 0xd213 ,
L_30 , V_28 , V_23 -> V_123 . V_60 , * V_8 ) ;
if ( ! V_23 -> V_123 . V_60 ) {
F_21 ( V_27 , V_2 , 0xd020 ,
L_31 , V_28 ) ;
F_19 ( V_23 , V_7 ) ;
goto V_58;
}
if ( V_16 + V_23 -> V_123 . V_60 > V_23 -> V_24 . V_125 ) {
F_21 ( V_27 , V_2 , 0xd030 ,
L_32 , V_28 ) ;
F_19 ( V_23 , V_7 ) ;
goto V_58;
}
F_6 ( V_23 -> V_123 . V_124 , V_23 -> V_123 . V_60 , V_7 , V_8 ) ;
V_58:
return false ;
}
static int
F_52 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_21 ( V_27 , V_2 , 0xd2ff ,
L_33 , V_28 , V_23 -> V_24 . V_126 , * V_8 ) ;
F_19 ( V_23 , V_7 ) ;
return false ;
}
inline void *
F_53 ( void * V_127 )
{
struct V_22 * V_23 = V_127 ;
return V_127 + V_23 -> V_24 . V_125 ;
}
static void
F_54 ( struct V_1 * V_2 ,
struct V_128 * V_129 , void * V_7 , T_3 * V_8 )
{
struct V_22 * V_23 = ( void * ) V_129 + V_129 -> V_130 ;
T_3 V_19 = V_129 -> V_131 ;
F_21 ( V_27 , V_2 , 0xd01a ,
L_34 , V_28 , V_19 ) ;
while ( V_19 -- ) {
if ( V_7 && * V_8 >= V_2 -> V_3 -> V_132 )
break;
if ( F_55 ( V_23 -> V_24 . V_126 ) ( V_2 , V_23 , V_7 , V_8 ) )
break;
V_23 = F_53 ( V_23 ) ;
}
if ( V_19 )
F_21 ( V_27 , V_2 , 0xd018 ,
L_35 , V_28 , V_19 ) ;
if ( V_23 -> V_24 . V_126 != V_133 )
F_21 ( V_27 , V_2 , 0xd019 ,
L_36 , V_28 , V_19 ) ;
if ( V_7 && * V_8 != V_2 -> V_3 -> V_132 )
F_21 ( V_27 , V_2 , 0xd01b ,
L_37 ,
V_28 , * V_8 , V_2 -> V_3 -> V_132 - * V_8 ) ;
if ( V_7 ) {
F_56 ( V_134 , V_2 , 0xd015 ,
L_38 ,
V_2 -> V_135 , V_2 -> V_3 -> V_136 ) ;
F_57 ( V_2 , V_137 ) ;
}
}
static void
F_58 ( struct V_128 * V_129 )
{
V_129 -> V_138 = V_139 ;
}
static void
F_59 ( struct V_128 * V_129 )
{
T_5 V_140 [] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
sscanf ( V_141 , L_39 ,
V_140 + 0 , V_140 + 1 , V_140 + 2 , V_140 + 3 , V_140 + 4 , V_140 + 5 ) ;
V_129 -> V_142 [ 0 ] = V_140 [ 3 ] << 24 | V_140 [ 2 ] << 16 | V_140 [ 1 ] << 8 | V_140 [ 0 ] ;
V_129 -> V_142 [ 1 ] = V_140 [ 5 ] << 8 | V_140 [ 4 ] ;
V_129 -> V_142 [ 2 ] = 0x12345678 ;
}
static void
F_60 ( struct V_128 * V_129 ,
struct V_1 * V_2 )
{
V_129 -> V_143 [ 0 ] = V_2 -> V_3 -> V_144 ;
V_129 -> V_143 [ 1 ] = V_2 -> V_3 -> V_145 ;
V_129 -> V_143 [ 2 ] = V_2 -> V_3 -> V_146 ;
V_129 -> V_143 [ 3 ] =
V_2 -> V_3 -> V_147 << 16 | V_2 -> V_3 -> V_148 ;
V_129 -> V_143 [ 4 ] =
V_2 -> V_3 -> V_149 [ 1 ] << 16 | V_2 -> V_3 -> V_149 [ 0 ] ;
}
static void
F_61 ( struct V_1 * V_2 ,
struct V_128 * V_129 )
{
F_58 ( V_129 ) ;
F_59 ( V_129 ) ;
F_60 ( V_129 , V_2 ) ;
}
static inline T_4
F_62 ( void * V_127 , T_3 V_12 )
{
T_4 * V_7 = V_127 ;
T_7 V_150 = 0 ;
V_12 /= sizeof( * V_7 ) ;
while ( V_12 -- )
V_150 += * V_7 ++ ;
V_150 = ( V_150 & 0xffffffff ) + ( V_150 >> 32 ) ;
return ~ V_150 ;
}
static inline int
F_63 ( struct V_128 * V_129 )
{
return F_62 ( V_129 , V_129 -> V_151 ) == 0 ;
}
static inline int
F_64 ( struct V_128 * V_129 )
{
return V_129 -> V_152 == V_153 ;
}
static void
F_65 ( struct V_1 * V_2 )
{
struct V_128 * V_129 = V_2 -> V_3 -> V_154 ;
T_3 V_8 ;
if ( F_66 ( V_129 ) ) {
V_8 = V_129 -> V_151 ;
V_129 = memcpy ( V_2 -> V_3 -> V_136 , V_129 , V_8 ) ;
F_61 ( V_2 , V_129 ) ;
F_54 ( V_2 , V_129 , V_129 , & V_8 ) ;
V_2 -> V_3 -> V_132 = V_8 ;
V_2 -> V_3 -> V_155 = 1 ;
}
}
T_3
F_67 ( struct V_1 * V_2 )
{
struct V_128 * V_129 = V_2 -> V_3 -> V_154 ;
T_3 V_8 = 0 ;
if ( F_66 ( V_129 ) ) {
V_8 = V_129 -> V_151 ;
F_54 ( V_2 , V_129 , NULL , & V_8 ) ;
}
return V_8 ;
}
T_3
F_68 ( void * V_127 )
{
struct V_128 * V_129 = V_127 ;
return V_129 -> V_151 ;
}
T_3
F_69 ( void )
{
return sizeof( V_156 ) ;
}
const void *
F_70 ( void )
{
return V_156 ;
}
int
F_66 ( void * V_127 )
{
struct V_128 * V_129 = V_127 ;
if ( ! F_64 ( V_129 ) ) {
F_56 ( V_134 , NULL , 0xd01c ,
L_40 , V_28 , V_129 -> V_152 ) ;
return false ;
}
if ( ! F_63 ( V_129 ) ) {
F_56 ( V_134 , NULL , 0xd01d ,
L_41 , V_28 ) ;
return false ;
}
return true ;
}
void
F_71 ( T_8 * V_2 , int V_157 )
{
T_3 V_158 = 0 ;
#ifndef F_72
if ( ! V_157 )
F_73 ( & V_2 -> V_3 -> V_159 , V_158 ) ;
#endif
if ( ! V_2 -> V_3 -> V_136 )
F_56 ( V_134 , V_2 , 0xd01e , L_42 ) ;
else if ( ! V_2 -> V_3 -> V_154 )
F_56 ( V_134 , V_2 , 0xd01f , L_43 ) ;
else if ( V_2 -> V_3 -> V_155 )
F_56 ( V_134 , V_2 , 0xd300 ,
L_44
L_45 , V_2 -> V_3 -> V_136 ) ;
else
F_65 ( V_2 ) ;
#ifndef F_72
if ( ! V_157 )
F_74 ( & V_2 -> V_3 -> V_159 , V_158 ) ;
#endif
}
