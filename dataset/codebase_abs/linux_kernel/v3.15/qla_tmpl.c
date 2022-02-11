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
T_3 V_13 = V_12 ;
if ( V_7 && V_11 ) {
V_7 += * V_8 ;
while ( V_13 >= sizeof( T_4 ) ) {
* ( V_10 * ) V_7 = F_7 ( V_11 ) ;
V_7 += sizeof( T_4 ) ;
V_11 += sizeof( T_4 ) ;
V_13 -= sizeof( T_4 ) ;
}
if ( V_13 )
memcpy ( V_7 , V_11 , V_13 ) ;
}
* V_8 += V_12 ;
}
static inline void
F_8 ( void * V_14 , void * V_7 , T_3 * V_8 )
{
T_5 V_6 = ~ 0 ;
if ( V_7 ) {
V_6 = F_9 ( ( T_1 void * ) V_14 ) ;
F_10 ( V_15 , NULL , 0xd011 ,
L_1 , V_16 , V_6 ) ;
}
F_4 ( V_6 , V_7 , V_8 ) ;
}
static inline void
F_11 ( void * V_14 , void * V_7 , T_3 * V_8 )
{
T_2 V_6 = ~ 0 ;
if ( V_7 ) {
V_6 = F_12 ( ( T_1 void * ) V_14 ) ;
F_10 ( V_15 , NULL , 0xd012 ,
L_1 , V_16 , V_6 ) ;
}
F_4 ( V_6 , V_7 , V_8 ) ;
}
static inline void
F_13 ( void * V_14 , void * V_7 , T_3 * V_8 )
{
T_4 V_6 = ~ 0 ;
if ( V_7 ) {
V_6 = F_14 ( ( T_1 void * ) V_14 ) ;
F_10 ( V_15 , NULL , 0xd013 ,
L_1 , V_16 , V_6 ) ;
}
F_4 ( V_6 , V_7 , V_8 ) ;
}
static inline void
F_15 ( T_1 struct V_17 * V_18 ,
T_6 V_19 , void * V_7 , T_3 * V_8 )
{
void * V_14 = ( void * ) V_18 + V_19 ;
if ( V_7 ) {
F_10 ( V_15 , NULL , 0xd014 ,
L_2 , V_16 , V_19 ) ;
}
F_4 ( V_19 , V_7 , V_8 ) ;
F_13 ( V_14 , V_7 , V_8 ) ;
}
static inline void
F_16 ( T_1 struct V_17 * V_18 ,
T_6 V_19 , T_4 V_20 , void * V_7 )
{
T_1 void * V_14 = V_18 + V_19 ;
if ( V_7 ) {
F_10 ( V_15 , NULL , 0xd015 ,
L_3 , V_16 , V_19 , V_20 ) ;
F_17 ( V_14 , V_20 ) ;
}
}
static inline void
F_18 ( T_1 struct V_17 * V_18 ,
T_4 V_21 , T_6 V_19 , T_6 V_22 , T_6 V_23 , void * V_7 ,
T_3 * V_8 )
{
void * V_14 = ( void * ) V_18 + V_19 ;
void (* F_19)( void * , void * , T_3 * ) = F_20 ( V_23 ) ;
if ( V_7 ) {
F_10 ( V_15 , NULL , 0xd016 ,
L_4 ,
V_16 , V_21 , V_19 , V_22 , V_23 ) ;
}
F_16 ( V_18 , V_24 , V_21 , V_7 ) ;
while ( V_22 -- ) {
F_4 ( V_21 , V_7 , V_8 ) ;
F_19 ( V_14 , V_7 , V_8 ) ;
V_14 += V_23 ;
V_21 += V_23 ;
}
}
static inline void
F_21 ( struct V_25 * V_26 , void * V_7 )
{
if ( V_7 )
V_26 -> V_27 . V_28 |= V_29 ;
}
static int
F_22 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
F_10 ( V_15 , V_2 , 0xd100 ,
L_5 , V_16 , * V_8 ) ;
F_21 ( V_26 , V_7 ) ;
return false ;
}
static int
F_23 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
F_10 ( V_15 , V_2 , 0xd1ff ,
L_6 , V_16 , * V_8 ) ;
F_21 ( V_26 , V_7 ) ;
return true ;
}
static int
F_24 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
struct V_17 T_1 * V_18 = F_1 ( V_2 ) ;
F_10 ( V_15 , V_2 , 0xd200 ,
L_7 , V_16 , * V_8 ) ;
F_18 ( V_18 , V_26 -> V_30 . V_31 , V_26 -> V_30 . V_32 ,
V_26 -> V_30 . V_33 , V_26 -> V_30 . V_34 , V_7 , V_8 ) ;
return false ;
}
static int
F_25 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
struct V_17 T_1 * V_18 = F_1 ( V_2 ) ;
F_10 ( V_15 , V_2 , 0xd201 ,
L_8 , V_16 , * V_8 ) ;
F_16 ( V_18 , V_24 , V_26 -> V_35 . V_31 , V_7 ) ;
F_16 ( V_18 , V_26 -> V_35 . V_32 , V_26 -> V_35 . V_36 , V_7 ) ;
return false ;
}
static int
F_26 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
struct V_17 T_1 * V_18 = F_1 ( V_2 ) ;
F_10 ( V_15 , V_2 , 0xd202 ,
L_9 , V_16 , * V_8 ) ;
F_16 ( V_18 , V_26 -> V_37 . V_38 , V_26 -> V_37 . V_39 , V_7 ) ;
F_18 ( V_18 , V_26 -> V_37 . V_31 , V_26 -> V_37 . V_32 ,
V_26 -> V_37 . V_33 , V_26 -> V_37 . V_34 , V_7 , V_8 ) ;
return false ;
}
static int
F_27 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
struct V_17 T_1 * V_18 = F_1 ( V_2 ) ;
F_10 ( V_15 , V_2 , 0xd203 ,
L_10 , V_16 , * V_8 ) ;
F_16 ( V_18 , V_24 , V_26 -> V_40 . V_31 , V_7 ) ;
F_16 ( V_18 , V_26 -> V_40 . V_38 , V_26 -> V_40 . V_39 , V_7 ) ;
F_16 ( V_18 , V_26 -> V_40 . V_32 , V_26 -> V_40 . V_36 , V_7 ) ;
return false ;
}
static int
F_28 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
struct V_17 T_1 * V_18 = F_1 ( V_2 ) ;
F_10 ( V_15 , V_2 , 0xd204 ,
L_11 , V_16 , * V_8 ) ;
F_15 ( V_18 , V_26 -> V_41 . V_42 , V_7 , V_8 ) ;
return false ;
}
static int
F_29 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
struct V_17 T_1 * V_18 = F_1 ( V_2 ) ;
F_10 ( V_15 , V_2 , 0xd205 ,
L_12 , V_16 , * V_8 ) ;
F_16 ( V_18 , V_26 -> V_43 . V_42 , V_26 -> V_43 . V_36 , V_7 ) ;
return false ;
}
static int
F_30 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
T_3 V_44 ;
T_3 V_45 ;
T_3 V_46 ;
F_10 ( V_15 , V_2 , 0xd206 ,
L_13 , V_16 , V_26 -> V_47 . V_48 , * V_8 ) ;
V_45 = V_26 -> V_47 . V_49 ;
V_46 = V_26 -> V_47 . V_50 ;
if ( V_26 -> V_47 . V_48 == V_51 ) {
;
} else if ( V_26 -> V_47 . V_48 == V_52 ) {
V_46 = V_2 -> V_3 -> V_53 ;
if ( V_7 )
V_26 -> V_47 . V_50 = V_46 ;
} else if ( V_26 -> V_47 . V_48 == V_54 ) {
V_45 = V_2 -> V_3 -> V_55 ;
V_46 = V_2 -> V_3 -> V_56 ;
if ( V_7 ) {
V_26 -> V_47 . V_49 = V_45 ;
V_26 -> V_47 . V_50 = V_46 ;
}
} else if ( V_26 -> V_47 . V_48 == V_57 ) {
F_10 ( V_15 , V_2 , 0xd021 ,
L_14 , V_16 ) ;
F_21 ( V_26 , V_7 ) ;
goto V_58;
} else {
F_10 ( V_15 , V_2 , 0xd022 ,
L_15 , V_16 , V_26 -> V_47 . V_48 ) ;
F_21 ( V_26 , V_7 ) ;
goto V_58;
}
if ( V_46 < V_45 ) {
F_10 ( V_15 , V_2 , 0xd023 ,
L_16 , V_16 ,
V_26 -> V_47 . V_50 , V_26 -> V_47 . V_49 ) ;
F_21 ( V_26 , V_7 ) ;
goto V_58;
}
V_44 = V_46 - V_45 + 1 ;
if ( V_7 ) {
F_10 ( V_15 , V_2 , 0xd024 ,
L_17 , V_16 , V_45 , V_44 ) ;
V_7 += * V_8 ;
F_31 ( V_2 -> V_3 , V_45 , V_7 , V_44 , & V_7 ) ;
}
* V_8 += V_44 * sizeof( T_4 ) ;
V_58:
return false ;
}
static int
F_32 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
T_6 V_22 = 0 ;
T_6 V_59 ;
T_6 V_60 ;
F_10 ( V_15 , V_2 , 0xd207 ,
L_18 , V_16 , V_26 -> V_61 . V_62 , * V_8 ) ;
if ( V_26 -> V_61 . V_62 == V_63 ) {
for ( V_59 = 0 ; V_59 < V_2 -> V_3 -> V_64 ; V_59 ++ ) {
struct V_65 * V_66 = V_2 -> V_3 -> V_67 [ V_59 ] ;
if ( V_66 || ! V_7 ) {
V_60 = V_66 ?
V_66 -> V_60 : V_68 ;
F_2 ( V_59 , V_7 , V_8 ) ;
F_2 ( V_60 , V_7 , V_8 ) ;
F_6 ( V_66 ? V_66 -> V_69 : NULL ,
V_60 * sizeof( * V_66 -> V_69 ) , V_7 , V_8 ) ;
V_22 ++ ;
}
}
} else if ( V_26 -> V_61 . V_62 == V_70 ) {
for ( V_59 = 0 ; V_59 < V_2 -> V_3 -> V_71 ; V_59 ++ ) {
struct V_72 * V_73 = V_2 -> V_3 -> V_74 [ V_59 ] ;
if ( V_73 || ! V_7 ) {
V_60 = V_73 ?
V_73 -> V_60 : V_75 ;
F_2 ( V_59 , V_7 , V_8 ) ;
F_2 ( V_60 , V_7 , V_8 ) ;
F_6 ( V_73 ? V_73 -> V_69 : NULL ,
V_60 * sizeof( * V_73 -> V_69 ) , V_7 , V_8 ) ;
V_22 ++ ;
}
}
} else if ( V_26 -> V_61 . V_62 == V_76 ) {
F_10 ( V_15 , V_2 , 0xd025 ,
L_19 , V_16 ) ;
F_21 ( V_26 , V_7 ) ;
goto V_58;
} else {
F_10 ( V_15 , V_2 , 0xd026 ,
L_20 , V_16 , V_26 -> V_61 . V_62 ) ;
F_21 ( V_26 , V_7 ) ;
goto V_58;
}
if ( V_7 )
V_26 -> V_61 . V_77 = V_22 ;
V_58:
return false ;
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
F_10 ( V_15 , V_2 , 0xd208 ,
L_21 , V_16 , * V_8 ) ;
if ( V_2 -> V_3 -> V_78 ) {
if ( V_7 ) {
V_26 -> V_79 . V_80 = V_81 ;
V_26 -> V_79 . V_82 = V_2 -> V_3 -> V_83 ;
V_26 -> V_79 . V_84 = V_2 -> V_3 -> V_85 ;
V_26 -> V_79 . V_86 = V_2 -> V_3 -> V_87 [ 0 ] ;
V_26 -> V_79 . V_88 = V_2 -> V_3 -> V_87 [ 2 ] ;
V_26 -> V_79 . V_89 = V_2 -> V_3 -> V_87 [ 3 ] ;
V_26 -> V_79 . V_90 = V_2 -> V_3 -> V_87 [ 4 ] ;
V_26 -> V_79 . V_91 = V_2 -> V_3 -> V_87 [ 5 ] ;
V_26 -> V_79 . V_92 = V_2 -> V_3 -> V_87 [ 6 ] ;
}
F_6 ( V_2 -> V_3 -> V_78 , V_81 , V_7 , V_8 ) ;
} else {
F_10 ( V_15 , V_2 , 0xd027 ,
L_22 , V_16 ) ;
F_21 ( V_26 , V_7 ) ;
}
return false ;
}
static int
F_34 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
struct V_17 T_1 * V_18 = F_1 ( V_2 ) ;
F_10 ( V_15 , V_2 , 0xd209 ,
L_23 , V_16 , * V_8 ) ;
if ( V_7 )
F_35 ( V_18 ) ;
return false ;
}
static int
F_36 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
F_10 ( V_15 , V_2 , 0xd20a ,
L_24 , V_16 , * V_8 ) ;
if ( V_7 )
F_37 ( V_2 -> V_3 ) ;
return false ;
}
static int
F_38 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
struct V_17 T_1 * V_18 = F_1 ( V_2 ) ;
F_10 ( V_15 , V_2 , 0xd20b ,
L_25 , V_16 , * V_8 ) ;
F_16 ( V_18 , V_26 -> V_93 . V_32 , V_26 -> V_93 . V_20 , V_7 ) ;
return false ;
}
static int
F_39 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
F_10 ( V_15 , V_2 , 0xd20c ,
L_26 , V_16 , V_26 -> V_94 . V_95 , * V_8 ) ;
if ( V_26 -> V_94 . V_95 == V_96 ) {
if ( V_2 -> V_3 -> V_97 ) {
if ( V_7 ) {
V_26 -> V_94 . V_98 = V_99 ;
V_26 -> V_94 . V_49 = V_2 -> V_3 -> V_100 ;
}
F_6 ( V_2 -> V_3 -> V_97 , V_99 , V_7 , V_8 ) ;
} else {
F_10 ( V_15 , V_2 , 0xd028 ,
L_27 , V_16 ) ;
F_21 ( V_26 , V_7 ) ;
}
} else if ( V_26 -> V_94 . V_95 == V_101 ) {
F_10 ( V_15 , V_2 , 0xd029 ,
L_28 , V_16 ) ;
F_21 ( V_26 , V_7 ) ;
} else if ( V_26 -> V_94 . V_95 == V_102 ) {
F_10 ( V_15 , V_2 , 0xd02a ,
L_29 , V_16 ) ;
F_21 ( V_26 , V_7 ) ;
} else {
F_10 ( V_15 , V_2 , 0xd02b ,
L_30 , V_16 , V_26 -> V_94 . V_95 ) ;
F_21 ( V_26 , V_7 ) ;
}
return false ;
}
static int
F_40 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
F_10 ( V_15 , V_2 , 0xd20d ,
L_31 , V_16 , * V_8 ) ;
F_4 ( 0xaaaaaaaa , V_7 , V_8 ) ;
F_4 ( 0xbbbbbbbb , V_7 , V_8 ) ;
F_4 ( 0xcccccccc , V_7 , V_8 ) ;
F_4 ( 0xdddddddd , V_7 , V_8 ) ;
F_4 ( * V_8 + sizeof( T_4 ) , V_7 , V_8 ) ;
if ( V_7 )
V_26 -> V_103 . V_104 = 5 * sizeof( T_4 ) ;
return false ;
}
static int
F_41 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
struct V_17 T_1 * V_18 = F_1 ( V_2 ) ;
void * V_14 = ( void * ) V_18 + 0xc4 ;
T_3 V_44 = V_26 -> V_105 . V_22 ;
T_3 V_106 = V_26 -> V_105 . V_106 ;
F_10 ( V_15 , V_2 , 0xd20e ,
L_32 , V_16 , * V_8 ) ;
F_16 ( V_18 , V_24 , 0x40 , V_7 ) ;
while ( V_44 -- ) {
F_16 ( V_18 , 0xc0 , V_106 | 0x80000000 , V_7 ) ;
F_15 ( V_18 , 0xc4 , V_7 , V_8 ) ;
F_4 ( V_106 , V_7 , V_8 ) ;
F_13 ( V_14 , V_7 , V_8 ) ;
V_106 ++ ;
}
return false ;
}
static int
F_42 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
struct V_17 T_1 * V_18 = F_1 ( V_2 ) ;
T_3 V_106 = V_26 -> V_107 . V_106 ;
F_10 ( V_15 , V_2 , 0xd20f ,
L_33 , V_16 , * V_8 ) ;
F_16 ( V_18 , V_24 , 0x40 , V_7 ) ;
F_15 ( V_18 , 0xc4 , V_7 , V_8 ) ;
F_4 ( V_106 , V_7 , V_8 ) ;
F_16 ( V_18 , 0xc0 , V_106 , V_7 ) ;
return false ;
}
static int
F_43 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
T_3 V_44 = V_26 -> V_108 . V_22 ;
T_3 V_45 = V_26 -> V_108 . V_106 ;
F_10 ( V_15 , V_2 , 0xd210 ,
L_34 , V_16 , * V_8 ) ;
if ( V_7 ) {
F_10 ( V_15 , V_2 , 0xd02c ,
L_17 , V_16 , V_45 , V_44 ) ;
V_7 += * V_8 ;
F_44 ( V_2 -> V_3 , V_45 , V_7 , V_44 , & V_7 ) ;
}
* V_8 += V_44 * sizeof( T_4 ) ;
return false ;
}
static int
F_45 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
T_3 V_44 = V_26 -> V_109 . V_22 ;
T_3 V_106 = V_26 -> V_109 . V_106 ;
T_4 V_6 ;
F_10 ( V_15 , V_2 , 0xd211 ,
L_35 , V_16 , * V_8 ) ;
while ( V_44 -- ) {
V_6 = ~ 0 ;
if ( F_46 ( V_2 -> V_3 -> V_110 , V_106 , & V_6 ) )
F_10 ( V_15 , V_2 , 0xd02d ,
L_36 , V_16 , V_106 ) ;
F_4 ( V_106 , V_7 , V_8 ) ;
F_4 ( V_6 , V_7 , V_8 ) ;
V_106 += 4 ;
}
return false ;
}
static int
F_47 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
F_10 ( V_15 , V_2 , 0xd2ff ,
L_37 , V_16 , V_26 -> V_27 . V_111 , * V_8 ) ;
F_21 ( V_26 , V_7 ) ;
return false ;
}
inline void *
F_48 ( void * V_112 )
{
struct V_25 * V_26 = V_112 ;
return V_112 + V_26 -> V_27 . V_113 ;
}
static void
F_49 ( struct V_1 * V_2 ,
struct V_114 * V_115 , void * V_7 , T_3 * V_8 )
{
struct V_25 * V_26 = ( void * ) V_115 + V_115 -> V_116 ;
T_3 V_22 = V_115 -> V_117 ;
F_10 ( V_15 , V_2 , 0xd01a ,
L_38 , V_16 , V_22 ) ;
while ( V_22 -- ) {
if ( F_50 ( V_26 -> V_27 . V_111 ) ( V_2 , V_26 , V_7 , V_8 ) )
break;
V_26 = F_48 ( V_26 ) ;
}
F_10 ( V_15 , V_2 , 0xd01b ,
L_39 , V_16 , * V_8 ) ;
}
static void
F_51 ( struct V_114 * V_115 )
{
V_115 -> V_118 = V_119 ;
}
static void
F_52 ( struct V_114 * V_115 )
{
T_5 V_120 [] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_121 = 0 ;
V_121 = sscanf ( V_122 , L_40 ,
V_120 + 0 , V_120 + 1 , V_120 + 2 , V_120 + 3 , V_120 + 4 , V_120 + 5 ) ;
V_115 -> V_123 [ 0 ] = V_120 [ 3 ] << 24 | V_120 [ 2 ] << 16 | V_120 [ 1 ] << 8 | V_120 [ 0 ] ;
V_115 -> V_123 [ 1 ] = V_120 [ 5 ] << 8 | V_120 [ 4 ] ;
V_115 -> V_123 [ 2 ] = 0x12345678 ;
}
static void
F_53 ( struct V_114 * V_115 ,
struct V_1 * V_2 )
{
V_115 -> V_124 [ 0 ] = V_2 -> V_3 -> V_125 ;
V_115 -> V_124 [ 1 ] = V_2 -> V_3 -> V_126 ;
V_115 -> V_124 [ 2 ] = V_2 -> V_3 -> V_127 ;
V_115 -> V_124 [ 3 ] =
V_2 -> V_3 -> V_128 << 16 | V_2 -> V_3 -> V_129 ;
V_115 -> V_124 [ 4 ] =
V_2 -> V_3 -> V_130 [ 1 ] << 16 | V_2 -> V_3 -> V_130 [ 0 ] ;
}
static void
F_54 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
F_51 ( V_115 ) ;
F_52 ( V_115 ) ;
F_53 ( V_115 , V_2 ) ;
}
static inline T_4
F_55 ( void * V_112 , T_3 V_12 )
{
T_4 * V_7 = V_112 ;
T_7 V_131 = 0 ;
V_12 /= sizeof( * V_7 ) ;
while ( V_12 -- )
V_131 += * V_7 ++ ;
V_131 = ( V_131 & 0xffffffff ) + ( V_131 >> 32 ) ;
return ~ V_131 ;
}
static inline int
F_56 ( struct V_114 * V_115 )
{
return F_55 ( V_115 , V_115 -> V_132 ) == 0 ;
}
static inline int
F_57 ( struct V_114 * V_115 )
{
return V_115 -> V_133 == V_134 ;
}
static void
F_58 ( struct V_1 * V_2 )
{
struct V_114 * V_115 = V_2 -> V_3 -> V_135 ;
T_3 V_8 ;
if ( F_59 ( V_115 ) ) {
V_8 = V_115 -> V_132 ;
V_115 = memcpy ( V_2 -> V_3 -> V_136 , V_115 , V_8 ) ;
F_54 ( V_2 , V_115 ) ;
F_49 ( V_2 , V_115 , V_115 , & V_8 ) ;
V_2 -> V_3 -> V_137 = V_8 ;
V_2 -> V_3 -> V_138 = 1 ;
}
}
T_3
F_60 ( struct V_1 * V_2 )
{
struct V_114 * V_115 = V_2 -> V_3 -> V_135 ;
T_3 V_8 = 0 ;
if ( F_59 ( V_115 ) ) {
V_8 = V_115 -> V_132 ;
F_49 ( V_2 , V_115 , NULL , & V_8 ) ;
}
return V_8 ;
}
T_3
F_61 ( void * V_112 )
{
struct V_114 * V_115 = V_112 ;
return V_115 -> V_132 ;
}
T_3
F_62 ( void )
{
return sizeof( V_139 ) ;
}
const void *
F_63 ( void )
{
return V_139 ;
}
int
F_59 ( void * V_112 )
{
struct V_114 * V_115 = V_112 ;
if ( ! F_57 ( V_115 ) ) {
F_64 ( V_140 , NULL , 0xd01c ,
L_41 , V_16 , V_115 -> V_133 ) ;
return false ;
}
if ( ! F_56 ( V_115 ) ) {
F_64 ( V_140 , NULL , 0xd01d ,
L_42 , V_16 ) ;
return false ;
}
return true ;
}
void
F_65 ( T_8 * V_2 , int V_141 )
{
T_3 V_142 = 0 ;
if ( ! V_141 )
F_66 ( & V_2 -> V_3 -> V_143 , V_142 ) ;
if ( ! V_2 -> V_3 -> V_136 )
F_64 ( V_140 , V_2 , 0xd01e , L_43 ) ;
else if ( ! V_2 -> V_3 -> V_135 )
F_64 ( V_140 , V_2 , 0xd01f , L_44 ) ;
else
F_58 ( V_2 ) ;
if ( ! V_141 )
F_67 ( & V_2 -> V_3 -> V_143 , V_142 ) ;
}
