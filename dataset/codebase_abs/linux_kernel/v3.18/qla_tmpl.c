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
F_7 ( void * V_13 , void * V_7 , T_3 * V_8 )
{
T_5 V_6 = ~ 0 ;
if ( V_7 ) {
V_6 = F_8 ( ( T_1 void * ) V_13 ) ;
}
F_4 ( V_6 , V_7 , V_8 ) ;
}
static inline void
F_9 ( void * V_13 , void * V_7 , T_3 * V_8 )
{
T_2 V_6 = ~ 0 ;
if ( V_7 ) {
V_6 = F_10 ( ( T_1 void * ) V_13 ) ;
}
F_4 ( V_6 , V_7 , V_8 ) ;
}
static inline void
F_11 ( void * V_13 , void * V_7 , T_3 * V_8 )
{
T_4 V_6 = ~ 0 ;
if ( V_7 ) {
V_6 = F_12 ( ( T_1 void * ) V_13 ) ;
}
F_4 ( V_6 , V_7 , V_8 ) ;
}
static inline void
F_13 ( T_1 struct V_14 * V_15 ,
T_6 V_16 , void * V_7 , T_3 * V_8 )
{
void * V_13 = ( void * ) V_15 + V_16 ;
F_11 ( V_13 , V_7 , V_8 ) ;
}
static inline void
F_14 ( T_1 struct V_14 * V_15 ,
T_6 V_16 , T_4 V_17 , void * V_7 )
{
T_1 void * V_13 = V_15 + V_16 ;
if ( V_7 ) {
F_15 ( V_13 , V_17 ) ;
}
}
static inline void
F_16 ( T_1 struct V_14 * V_15 ,
T_4 V_18 , T_6 V_16 , T_6 V_19 , T_6 V_20 , void * V_7 ,
T_3 * V_8 )
{
void * V_13 = ( void * ) V_15 + V_16 ;
void (* F_17)( void * , void * , T_3 * ) = F_18 ( V_20 ) ;
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
} else {
F_21 ( V_27 , V_2 , 0xd022 ,
L_10 , V_28 , V_23 -> V_45 . V_46 ) ;
F_19 ( V_23 , V_7 ) ;
goto V_55;
}
if ( V_44 < V_43 || V_44 == 0 ) {
F_21 ( V_27 , V_2 , 0xd023 ,
L_11 , V_28 ,
V_23 -> V_45 . V_48 , V_23 -> V_45 . V_47 ) ;
F_19 ( V_23 , V_7 ) ;
goto V_55;
}
V_42 = V_44 - V_43 + 1 ;
if ( V_7 ) {
V_7 += * V_8 ;
F_30 ( V_2 -> V_3 , V_43 , V_7 , V_42 , & V_7 ) ;
}
* V_8 += V_42 * sizeof( T_4 ) ;
V_55:
return false ;
}
static int
F_31 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_6 V_19 = 0 ;
T_6 V_56 ;
T_6 V_57 ;
F_21 ( V_27 , V_2 , 0xd207 ,
L_12 , V_28 , V_23 -> V_58 . V_59 , * V_8 ) ;
if ( V_23 -> V_58 . V_59 == V_60 ) {
for ( V_56 = 0 ; V_56 < V_2 -> V_3 -> V_61 ; V_56 ++ ) {
struct V_62 * V_63 = V_2 -> V_3 -> V_64 [ V_56 ] ;
if ( V_63 || ! V_7 ) {
V_57 = V_63 ?
V_63 -> V_57 : V_65 ;
F_2 ( V_56 , V_7 , V_8 ) ;
F_2 ( V_57 , V_7 , V_8 ) ;
F_6 ( V_63 ? V_63 -> V_66 : NULL ,
V_57 * sizeof( * V_63 -> V_66 ) , V_7 , V_8 ) ;
V_19 ++ ;
}
}
} else if ( V_23 -> V_58 . V_59 == V_67 ) {
for ( V_56 = 0 ; V_56 < V_2 -> V_3 -> V_68 ; V_56 ++ ) {
struct V_69 * V_70 = V_2 -> V_3 -> V_71 [ V_56 ] ;
if ( V_70 || ! V_7 ) {
V_57 = V_70 ?
V_70 -> V_57 : V_72 ;
F_2 ( V_56 , V_7 , V_8 ) ;
F_2 ( V_57 , V_7 , V_8 ) ;
F_6 ( V_70 ? V_70 -> V_66 : NULL ,
V_57 * sizeof( * V_70 -> V_66 ) , V_7 , V_8 ) ;
V_19 ++ ;
}
}
} else {
F_21 ( V_27 , V_2 , 0xd026 ,
L_13 , V_28 , V_23 -> V_58 . V_59 ) ;
F_19 ( V_23 , V_7 ) ;
}
if ( V_7 )
V_23 -> V_58 . V_73 = V_19 ;
return false ;
}
static int
F_32 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_21 ( V_27 , V_2 , 0xd208 ,
L_14 , V_28 , * V_8 ) ;
if ( V_2 -> V_3 -> V_74 ) {
if ( V_7 ) {
V_23 -> V_75 . V_76 = V_77 ;
V_23 -> V_75 . V_78 = V_2 -> V_3 -> V_79 ;
V_23 -> V_75 . V_80 = V_2 -> V_3 -> V_81 ;
V_23 -> V_75 . V_82 = V_2 -> V_3 -> V_83 [ 0 ] ;
V_23 -> V_75 . V_84 = V_2 -> V_3 -> V_83 [ 2 ] ;
V_23 -> V_75 . V_85 = V_2 -> V_3 -> V_83 [ 3 ] ;
V_23 -> V_75 . V_86 = V_2 -> V_3 -> V_83 [ 4 ] ;
V_23 -> V_75 . V_87 = V_2 -> V_3 -> V_83 [ 5 ] ;
V_23 -> V_75 . V_88 = V_2 -> V_3 -> V_83 [ 6 ] ;
}
F_6 ( V_2 -> V_3 -> V_74 , V_77 , V_7 , V_8 ) ;
} else {
F_21 ( V_27 , V_2 , 0xd027 ,
L_15 , V_28 ) ;
F_19 ( V_23 , V_7 ) ;
}
return false ;
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_21 ( V_27 , V_2 , 0xd209 ,
L_16 , V_28 , * V_8 ) ;
if ( V_7 )
F_34 ( V_15 , V_2 -> V_3 ) ;
return false ;
}
static int
F_35 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_21 ( V_27 , V_2 , 0xd20a ,
L_17 , V_28 , * V_8 ) ;
if ( V_7 )
F_36 ( V_2 -> V_3 ) ;
return false ;
}
static int
F_37 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_21 ( V_27 , V_2 , 0xd20b ,
L_18 , V_28 , * V_8 ) ;
F_14 ( V_15 , V_23 -> V_89 . V_31 , V_23 -> V_89 . V_17 , V_7 ) ;
return false ;
}
static int
F_38 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_21 ( V_27 , V_2 , 0xd20c ,
L_19 , V_28 , V_23 -> V_90 . V_91 , * V_8 ) ;
if ( V_23 -> V_90 . V_91 == V_92 ) {
if ( V_2 -> V_3 -> V_93 ) {
if ( V_7 ) {
V_23 -> V_90 . V_94 = V_95 ;
V_23 -> V_90 . V_47 = V_2 -> V_3 -> V_96 ;
}
F_6 ( V_2 -> V_3 -> V_93 , V_95 , V_7 , V_8 ) ;
} else {
F_21 ( V_27 , V_2 , 0xd028 ,
L_20 , V_28 ) ;
F_19 ( V_23 , V_7 ) ;
}
} else {
F_21 ( V_27 , V_2 , 0xd02b ,
L_21 , V_28 , V_23 -> V_90 . V_91 ) ;
F_19 ( V_23 , V_7 ) ;
}
return false ;
}
static int
F_39 ( struct V_1 * V_2 ,
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
V_23 -> V_97 . V_98 = 5 * sizeof( T_4 ) ;
return false ;
}
static int
F_40 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
T_3 V_42 = V_23 -> V_99 . V_19 ;
T_3 V_18 = V_23 -> V_99 . V_18 ;
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
F_41 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
T_3 V_18 = V_23 -> V_100 . V_18 ;
T_3 V_17 = V_23 -> V_100 . V_17 ;
F_21 ( V_27 , V_2 , 0xd20f ,
L_24 , V_28 , * V_8 ) ;
F_14 ( V_15 , V_21 , 0x40 , V_7 ) ;
F_14 ( V_15 , 0xc4 , V_17 , V_7 ) ;
F_14 ( V_15 , 0xc0 , V_18 , V_7 ) ;
return false ;
}
static int
F_42 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_3 V_42 = V_23 -> V_101 . V_19 ;
T_3 V_43 = V_23 -> V_101 . V_18 ;
F_21 ( V_27 , V_2 , 0xd210 ,
L_25 , V_28 , * V_8 ) ;
if ( V_7 ) {
F_21 ( V_27 , V_2 , 0xd02c ,
L_26 , V_28 , V_43 , V_42 ) ;
V_7 += * V_8 ;
F_43 ( V_2 -> V_3 , V_43 , V_7 , V_42 , & V_7 ) ;
}
* V_8 += V_42 * sizeof( T_4 ) ;
return false ;
}
static int
F_44 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_3 V_42 = V_23 -> V_102 . V_19 ;
T_3 V_18 = V_23 -> V_102 . V_18 ;
T_4 V_6 ;
F_21 ( V_27 , V_2 , 0xd211 ,
L_27 , V_28 , * V_8 ) ;
while ( V_42 -- ) {
V_6 = ~ 0 ;
if ( F_45 ( V_2 -> V_3 -> V_103 , V_18 , & V_6 ) )
F_21 ( V_27 , V_2 , 0xd02d ,
L_28 , V_28 , V_18 ) ;
F_4 ( V_18 , V_7 , V_8 ) ;
F_4 ( V_6 , V_7 , V_8 ) ;
V_18 += sizeof( T_4 ) ;
}
return false ;
}
static int
F_46 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_6 V_19 = 0 ;
T_6 V_56 ;
F_21 ( V_27 , V_2 , 0xd212 ,
L_29 , V_28 , V_23 -> V_104 . V_59 , * V_8 ) ;
if ( V_23 -> V_104 . V_59 == V_105 ) {
for ( V_56 = 0 ; V_56 < V_2 -> V_3 -> V_61 ; V_56 ++ ) {
struct V_62 * V_63 = V_2 -> V_3 -> V_64 [ V_56 ] ;
if ( V_63 || ! V_7 ) {
F_2 ( V_56 , V_7 , V_8 ) ;
F_2 ( 1 , V_7 , V_8 ) ;
F_4 ( V_63 && V_63 -> V_106 ?
* V_63 -> V_106 : 0 , V_7 , V_8 ) ;
V_19 ++ ;
}
}
} else if ( V_23 -> V_104 . V_59 == V_107 ) {
for ( V_56 = 0 ; V_56 < V_2 -> V_3 -> V_68 ; V_56 ++ ) {
struct V_69 * V_70 = V_2 -> V_3 -> V_71 [ V_56 ] ;
if ( V_70 || ! V_7 ) {
F_2 ( V_56 , V_7 , V_8 ) ;
F_2 ( 1 , V_7 , V_8 ) ;
F_4 ( V_70 && V_70 -> V_108 ?
* V_70 -> V_108 : 0 , V_7 , V_8 ) ;
V_19 ++ ;
}
}
} else {
F_21 ( V_27 , V_2 , 0xd02f ,
L_13 , V_28 , V_23 -> V_104 . V_59 ) ;
F_19 ( V_23 , V_7 ) ;
}
if ( V_7 )
V_23 -> V_104 . V_73 = V_19 ;
if ( ! V_19 )
F_19 ( V_23 , V_7 ) ;
return false ;
}
static int
F_47 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_3 V_16 = F_48 ( F_49 ( * V_23 ) , V_109 . V_110 ) ;
F_21 ( V_27 , V_2 , 0xd213 ,
L_30 , V_28 , V_23 -> V_109 . V_57 , * V_8 ) ;
if ( ! V_23 -> V_109 . V_57 ) {
F_21 ( V_27 , V_2 , 0xd020 ,
L_31 , V_28 ) ;
F_19 ( V_23 , V_7 ) ;
goto V_55;
}
if ( V_16 + V_23 -> V_109 . V_57 > V_23 -> V_24 . V_111 ) {
F_21 ( V_27 , V_2 , 0xd030 ,
L_32 , V_28 ) ;
F_19 ( V_23 , V_7 ) ;
goto V_55;
}
F_6 ( V_23 -> V_109 . V_110 , V_23 -> V_109 . V_57 , V_7 , V_8 ) ;
V_55:
return false ;
}
static int
F_50 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_21 ( V_27 , V_2 , 0xd2ff ,
L_33 , V_28 , V_23 -> V_24 . V_112 , * V_8 ) ;
F_19 ( V_23 , V_7 ) ;
return false ;
}
inline void *
F_51 ( void * V_113 )
{
struct V_22 * V_23 = V_113 ;
return V_113 + V_23 -> V_24 . V_111 ;
}
static void
F_52 ( struct V_1 * V_2 ,
struct V_114 * V_115 , void * V_7 , T_3 * V_8 )
{
struct V_22 * V_23 = ( void * ) V_115 + V_115 -> V_116 ;
T_3 V_19 = V_115 -> V_117 ;
F_21 ( V_27 , V_2 , 0xd01a ,
L_34 , V_28 , V_19 ) ;
while ( V_19 -- ) {
if ( F_53 ( V_23 -> V_24 . V_112 ) ( V_2 , V_23 , V_7 , V_8 ) )
break;
V_23 = F_51 ( V_23 ) ;
}
if ( V_19 )
F_21 ( V_27 , V_2 , 0xd018 ,
L_35 , V_28 , V_19 ) ;
if ( V_23 -> V_24 . V_112 != V_118 )
F_21 ( V_27 , V_2 , 0xd019 ,
L_36 , V_28 , V_19 ) ;
F_21 ( V_27 , V_2 , 0xd01b ,
L_37 , V_28 , * V_8 ) ;
}
static void
F_54 ( struct V_114 * V_115 )
{
V_115 -> V_119 = V_120 ;
}
static void
F_55 ( struct V_114 * V_115 )
{
T_5 V_121 [] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_122 = 0 ;
V_122 = sscanf ( V_123 , L_38 ,
V_121 + 0 , V_121 + 1 , V_121 + 2 , V_121 + 3 , V_121 + 4 , V_121 + 5 ) ;
V_115 -> V_124 [ 0 ] = V_121 [ 3 ] << 24 | V_121 [ 2 ] << 16 | V_121 [ 1 ] << 8 | V_121 [ 0 ] ;
V_115 -> V_124 [ 1 ] = V_121 [ 5 ] << 8 | V_121 [ 4 ] ;
V_115 -> V_124 [ 2 ] = 0x12345678 ;
}
static void
F_56 ( struct V_114 * V_115 ,
struct V_1 * V_2 )
{
V_115 -> V_125 [ 0 ] = V_2 -> V_3 -> V_126 ;
V_115 -> V_125 [ 1 ] = V_2 -> V_3 -> V_127 ;
V_115 -> V_125 [ 2 ] = V_2 -> V_3 -> V_128 ;
V_115 -> V_125 [ 3 ] =
V_2 -> V_3 -> V_129 << 16 | V_2 -> V_3 -> V_130 ;
V_115 -> V_125 [ 4 ] =
V_2 -> V_3 -> V_131 [ 1 ] << 16 | V_2 -> V_3 -> V_131 [ 0 ] ;
}
static void
F_57 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
F_54 ( V_115 ) ;
F_55 ( V_115 ) ;
F_56 ( V_115 , V_2 ) ;
}
static inline T_4
F_58 ( void * V_113 , T_3 V_12 )
{
T_4 * V_7 = V_113 ;
T_7 V_132 = 0 ;
V_12 /= sizeof( * V_7 ) ;
while ( V_12 -- )
V_132 += * V_7 ++ ;
V_132 = ( V_132 & 0xffffffff ) + ( V_132 >> 32 ) ;
return ~ V_132 ;
}
static inline int
F_59 ( struct V_114 * V_115 )
{
return F_58 ( V_115 , V_115 -> V_133 ) == 0 ;
}
static inline int
F_60 ( struct V_114 * V_115 )
{
return V_115 -> V_134 == V_135 ;
}
static void
F_61 ( struct V_1 * V_2 )
{
struct V_114 * V_115 = V_2 -> V_3 -> V_136 ;
T_3 V_8 ;
if ( F_62 ( V_115 ) ) {
V_8 = V_115 -> V_133 ;
V_115 = memcpy ( V_2 -> V_3 -> V_137 , V_115 , V_8 ) ;
F_57 ( V_2 , V_115 ) ;
F_52 ( V_2 , V_115 , V_115 , & V_8 ) ;
V_2 -> V_3 -> V_138 = V_8 ;
V_2 -> V_3 -> V_139 = 1 ;
}
}
T_3
F_63 ( struct V_1 * V_2 )
{
struct V_114 * V_115 = V_2 -> V_3 -> V_136 ;
T_3 V_8 = 0 ;
if ( F_62 ( V_115 ) ) {
V_8 = V_115 -> V_133 ;
F_52 ( V_2 , V_115 , NULL , & V_8 ) ;
}
return V_8 ;
}
T_3
F_64 ( void * V_113 )
{
struct V_114 * V_115 = V_113 ;
return V_115 -> V_133 ;
}
T_3
F_65 ( void )
{
return sizeof( V_140 ) ;
}
const void *
F_66 ( void )
{
return V_140 ;
}
int
F_62 ( void * V_113 )
{
struct V_114 * V_115 = V_113 ;
if ( ! F_60 ( V_115 ) ) {
F_67 ( V_141 , NULL , 0xd01c ,
L_39 , V_28 , V_115 -> V_134 ) ;
return false ;
}
if ( ! F_59 ( V_115 ) ) {
F_67 ( V_141 , NULL , 0xd01d ,
L_40 , V_28 ) ;
return false ;
}
return true ;
}
void
F_68 ( T_8 * V_2 , int V_142 )
{
T_3 V_143 = 0 ;
if ( ! V_142 )
F_69 ( & V_2 -> V_3 -> V_144 , V_143 ) ;
if ( ! V_2 -> V_3 -> V_137 )
F_67 ( V_141 , V_2 , 0xd01e , L_41 ) ;
else if ( ! V_2 -> V_3 -> V_136 )
F_67 ( V_141 , V_2 , 0xd01f , L_42 ) ;
else
F_61 ( V_2 ) ;
if ( ! V_142 )
F_70 ( & V_2 -> V_3 -> V_144 , V_143 ) ;
}
