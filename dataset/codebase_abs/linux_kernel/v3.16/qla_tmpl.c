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
V_21 ++ ;
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
F_4 ( V_26 -> V_41 . V_32 , V_7 , V_8 ) ;
F_15 ( V_18 , V_26 -> V_41 . V_32 , V_7 , V_8 ) ;
return false ;
}
static int
F_29 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
struct V_17 T_1 * V_18 = F_1 ( V_2 ) ;
F_10 ( V_15 , V_2 , 0xd205 ,
L_12 , V_16 , * V_8 ) ;
F_16 ( V_18 , V_26 -> V_42 . V_32 , V_26 -> V_42 . V_36 , V_7 ) ;
return false ;
}
static int
F_30 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
T_3 V_43 ;
T_3 V_44 ;
T_3 V_45 ;
F_10 ( V_15 , V_2 , 0xd206 ,
L_13 , V_16 , V_26 -> V_46 . V_47 , * V_8 ) ;
V_44 = V_26 -> V_46 . V_48 ;
V_45 = V_26 -> V_46 . V_49 ;
if ( V_26 -> V_46 . V_47 == V_50 ) {
;
} else if ( V_26 -> V_46 . V_47 == V_51 ) {
V_45 = V_2 -> V_3 -> V_52 ;
if ( V_7 )
V_26 -> V_46 . V_49 = V_45 ;
} else if ( V_26 -> V_46 . V_47 == V_53 ) {
V_44 = V_2 -> V_3 -> V_54 ;
V_45 = V_2 -> V_3 -> V_55 ;
if ( V_7 ) {
V_26 -> V_46 . V_48 = V_44 ;
V_26 -> V_46 . V_49 = V_45 ;
}
} else if ( V_26 -> V_46 . V_47 == V_56 ) {
F_10 ( V_15 , V_2 , 0xd021 ,
L_14 , V_16 ) ;
F_21 ( V_26 , V_7 ) ;
goto V_57;
} else {
F_10 ( V_15 , V_2 , 0xd022 ,
L_15 , V_16 , V_26 -> V_46 . V_47 ) ;
F_21 ( V_26 , V_7 ) ;
goto V_57;
}
if ( V_45 < V_44 || V_45 == 0 ) {
F_10 ( V_15 , V_2 , 0xd023 ,
L_16 , V_16 ,
V_26 -> V_46 . V_49 , V_26 -> V_46 . V_48 ) ;
F_21 ( V_26 , V_7 ) ;
goto V_57;
}
V_43 = V_45 - V_44 + 1 ;
if ( V_7 ) {
F_10 ( V_15 , V_2 , 0xd024 ,
L_17 , V_16 , V_44 , V_43 ) ;
V_7 += * V_8 ;
F_31 ( V_2 -> V_3 , V_44 , V_7 , V_43 , & V_7 ) ;
}
* V_8 += V_43 * sizeof( T_4 ) ;
V_57:
return false ;
}
static int
F_32 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
T_6 V_22 = 0 ;
T_6 V_58 ;
T_6 V_59 ;
F_10 ( V_15 , V_2 , 0xd207 ,
L_18 , V_16 , V_26 -> V_60 . V_61 , * V_8 ) ;
if ( V_26 -> V_60 . V_61 == V_62 ) {
for ( V_58 = 0 ; V_58 < V_2 -> V_3 -> V_63 ; V_58 ++ ) {
struct V_64 * V_65 = V_2 -> V_3 -> V_66 [ V_58 ] ;
if ( V_65 || ! V_7 ) {
V_59 = V_65 ?
V_65 -> V_59 : V_67 ;
F_2 ( V_58 , V_7 , V_8 ) ;
F_2 ( V_59 , V_7 , V_8 ) ;
F_6 ( V_65 ? V_65 -> V_68 : NULL ,
V_59 * sizeof( * V_65 -> V_68 ) , V_7 , V_8 ) ;
V_22 ++ ;
}
}
} else if ( V_26 -> V_60 . V_61 == V_69 ) {
for ( V_58 = 0 ; V_58 < V_2 -> V_3 -> V_70 ; V_58 ++ ) {
struct V_71 * V_72 = V_2 -> V_3 -> V_73 [ V_58 ] ;
if ( V_72 || ! V_7 ) {
V_59 = V_72 ?
V_72 -> V_59 : V_74 ;
F_2 ( V_58 , V_7 , V_8 ) ;
F_2 ( V_59 , V_7 , V_8 ) ;
F_6 ( V_72 ? V_72 -> V_68 : NULL ,
V_59 * sizeof( * V_72 -> V_68 ) , V_7 , V_8 ) ;
V_22 ++ ;
}
}
} else if ( V_26 -> V_60 . V_61 == V_75 ) {
F_10 ( V_15 , V_2 , 0xd025 ,
L_19 , V_16 ) ;
F_21 ( V_26 , V_7 ) ;
} else {
F_10 ( V_15 , V_2 , 0xd026 ,
L_20 , V_16 , V_26 -> V_60 . V_61 ) ;
F_21 ( V_26 , V_7 ) ;
}
if ( V_7 )
V_26 -> V_60 . V_76 = V_22 ;
return false ;
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
F_10 ( V_15 , V_2 , 0xd208 ,
L_21 , V_16 , * V_8 ) ;
if ( V_2 -> V_3 -> V_77 ) {
if ( V_7 ) {
V_26 -> V_78 . V_79 = V_80 ;
V_26 -> V_78 . V_81 = V_2 -> V_3 -> V_82 ;
V_26 -> V_78 . V_83 = V_2 -> V_3 -> V_84 ;
V_26 -> V_78 . V_85 = V_2 -> V_3 -> V_86 [ 0 ] ;
V_26 -> V_78 . V_87 = V_2 -> V_3 -> V_86 [ 2 ] ;
V_26 -> V_78 . V_88 = V_2 -> V_3 -> V_86 [ 3 ] ;
V_26 -> V_78 . V_89 = V_2 -> V_3 -> V_86 [ 4 ] ;
V_26 -> V_78 . V_90 = V_2 -> V_3 -> V_86 [ 5 ] ;
V_26 -> V_78 . V_91 = V_2 -> V_3 -> V_86 [ 6 ] ;
}
F_6 ( V_2 -> V_3 -> V_77 , V_80 , V_7 , V_8 ) ;
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
F_35 ( V_18 , V_2 -> V_3 ) ;
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
F_16 ( V_18 , V_26 -> V_92 . V_32 , V_26 -> V_92 . V_20 , V_7 ) ;
return false ;
}
static int
F_39 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
F_10 ( V_15 , V_2 , 0xd20c ,
L_26 , V_16 , V_26 -> V_93 . V_94 , * V_8 ) ;
if ( V_26 -> V_93 . V_94 == V_95 ) {
if ( V_2 -> V_3 -> V_96 ) {
if ( V_7 ) {
V_26 -> V_93 . V_97 = V_98 ;
V_26 -> V_93 . V_48 = V_2 -> V_3 -> V_99 ;
}
F_6 ( V_2 -> V_3 -> V_96 , V_98 , V_7 , V_8 ) ;
} else {
F_10 ( V_15 , V_2 , 0xd028 ,
L_27 , V_16 ) ;
F_21 ( V_26 , V_7 ) ;
}
} else if ( V_26 -> V_93 . V_94 == V_100 ) {
F_10 ( V_15 , V_2 , 0xd029 ,
L_28 , V_16 ) ;
F_21 ( V_26 , V_7 ) ;
} else if ( V_26 -> V_93 . V_94 == V_101 ) {
F_10 ( V_15 , V_2 , 0xd02a ,
L_29 , V_16 ) ;
F_21 ( V_26 , V_7 ) ;
} else {
F_10 ( V_15 , V_2 , 0xd02b ,
L_30 , V_16 , V_26 -> V_93 . V_94 ) ;
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
V_26 -> V_102 . V_103 = 5 * sizeof( T_4 ) ;
return false ;
}
static int
F_41 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
struct V_17 T_1 * V_18 = F_1 ( V_2 ) ;
T_3 V_43 = V_26 -> V_104 . V_22 ;
T_3 V_21 = V_26 -> V_104 . V_21 ;
F_10 ( V_15 , V_2 , 0xd20e ,
L_32 , V_16 , * V_8 ) ;
F_16 ( V_18 , V_24 , 0x40 , V_7 ) ;
while ( V_43 -- ) {
F_16 ( V_18 , 0xc0 , V_21 | 0x80000000 , V_7 ) ;
F_4 ( V_21 , V_7 , V_8 ) ;
F_15 ( V_18 , 0xc4 , V_7 , V_8 ) ;
V_21 += sizeof( T_4 ) ;
}
return false ;
}
static int
F_42 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
struct V_17 T_1 * V_18 = F_1 ( V_2 ) ;
T_3 V_21 = V_26 -> V_105 . V_21 ;
T_3 V_20 = V_26 -> V_105 . V_20 ;
F_10 ( V_15 , V_2 , 0xd20f ,
L_33 , V_16 , * V_8 ) ;
F_16 ( V_18 , V_24 , 0x40 , V_7 ) ;
F_16 ( V_18 , 0xc4 , V_20 , V_7 ) ;
F_16 ( V_18 , 0xc0 , V_21 , V_7 ) ;
return false ;
}
static int
F_43 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
T_3 V_43 = V_26 -> V_106 . V_22 ;
T_3 V_44 = V_26 -> V_106 . V_21 ;
F_10 ( V_15 , V_2 , 0xd210 ,
L_34 , V_16 , * V_8 ) ;
if ( V_7 ) {
F_10 ( V_15 , V_2 , 0xd02c ,
L_17 , V_16 , V_44 , V_43 ) ;
V_7 += * V_8 ;
F_44 ( V_2 -> V_3 , V_44 , V_7 , V_43 , & V_7 ) ;
}
* V_8 += V_43 * sizeof( T_4 ) ;
return false ;
}
static int
F_45 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
T_3 V_43 = V_26 -> V_107 . V_22 ;
T_3 V_21 = V_26 -> V_107 . V_21 ;
T_4 V_6 ;
F_10 ( V_15 , V_2 , 0xd211 ,
L_35 , V_16 , * V_8 ) ;
while ( V_43 -- ) {
V_6 = ~ 0 ;
if ( F_46 ( V_2 -> V_3 -> V_108 , V_21 , & V_6 ) )
F_10 ( V_15 , V_2 , 0xd02d ,
L_36 , V_16 , V_21 ) ;
F_4 ( V_21 , V_7 , V_8 ) ;
F_4 ( V_6 , V_7 , V_8 ) ;
V_21 += sizeof( T_4 ) ;
}
return false ;
}
static int
F_47 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
T_6 V_22 = 0 ;
T_6 V_58 ;
F_10 ( V_15 , V_2 , 0xd212 ,
L_37 , V_16 , V_26 -> V_109 . V_61 , * V_8 ) ;
if ( V_26 -> V_109 . V_61 == V_110 ) {
for ( V_58 = 0 ; V_58 < V_2 -> V_3 -> V_63 ; V_58 ++ ) {
struct V_64 * V_65 = V_2 -> V_3 -> V_66 [ V_58 ] ;
if ( V_65 || ! V_7 ) {
F_2 ( V_58 , V_7 , V_8 ) ;
F_2 ( 1 , V_7 , V_8 ) ;
F_4 ( V_65 && V_65 -> V_111 ?
* V_65 -> V_111 : 0 , V_7 , V_8 ) ;
V_22 ++ ;
}
}
} else if ( V_26 -> V_109 . V_61 == V_112 ) {
for ( V_58 = 0 ; V_58 < V_2 -> V_3 -> V_70 ; V_58 ++ ) {
struct V_71 * V_72 = V_2 -> V_3 -> V_73 [ V_58 ] ;
if ( V_72 || ! V_7 ) {
F_2 ( V_58 , V_7 , V_8 ) ;
F_2 ( 1 , V_7 , V_8 ) ;
F_4 ( V_72 && V_72 -> V_113 ?
* V_72 -> V_113 : 0 , V_7 , V_8 ) ;
V_22 ++ ;
}
}
} else if ( V_26 -> V_109 . V_61 == V_114 ) {
F_10 ( V_15 , V_2 , 0xd02e ,
L_19 , V_16 ) ;
F_21 ( V_26 , V_7 ) ;
} else {
F_10 ( V_15 , V_2 , 0xd02f ,
L_20 , V_16 , V_26 -> V_109 . V_61 ) ;
F_21 ( V_26 , V_7 ) ;
}
if ( V_7 )
V_26 -> V_109 . V_76 = V_22 ;
if ( ! V_22 )
F_21 ( V_26 , V_7 ) ;
return false ;
}
static int
F_48 ( struct V_1 * V_2 ,
struct V_25 * V_26 , void * V_7 , T_3 * V_8 )
{
F_10 ( V_15 , V_2 , 0xd2ff ,
L_38 , V_16 , V_26 -> V_27 . V_115 , * V_8 ) ;
F_21 ( V_26 , V_7 ) ;
return false ;
}
inline void *
F_49 ( void * V_116 )
{
struct V_25 * V_26 = V_116 ;
return V_116 + V_26 -> V_27 . V_117 ;
}
static void
F_50 ( struct V_1 * V_2 ,
struct V_118 * V_119 , void * V_7 , T_3 * V_8 )
{
struct V_25 * V_26 = ( void * ) V_119 + V_119 -> V_120 ;
T_3 V_22 = V_119 -> V_121 ;
F_10 ( V_15 , V_2 , 0xd01a ,
L_39 , V_16 , V_22 ) ;
while ( V_22 -- ) {
if ( F_51 ( V_26 -> V_27 . V_115 ) ( V_2 , V_26 , V_7 , V_8 ) )
break;
V_26 = F_49 ( V_26 ) ;
}
F_10 ( V_15 , V_2 , 0xd01b ,
L_40 , V_16 , * V_8 ) ;
}
static void
F_52 ( struct V_118 * V_119 )
{
V_119 -> V_122 = V_123 ;
}
static void
F_53 ( struct V_118 * V_119 )
{
T_5 V_124 [] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_125 = 0 ;
V_125 = sscanf ( V_126 , L_41 ,
V_124 + 0 , V_124 + 1 , V_124 + 2 , V_124 + 3 , V_124 + 4 , V_124 + 5 ) ;
V_119 -> V_127 [ 0 ] = V_124 [ 3 ] << 24 | V_124 [ 2 ] << 16 | V_124 [ 1 ] << 8 | V_124 [ 0 ] ;
V_119 -> V_127 [ 1 ] = V_124 [ 5 ] << 8 | V_124 [ 4 ] ;
V_119 -> V_127 [ 2 ] = 0x12345678 ;
}
static void
F_54 ( struct V_118 * V_119 ,
struct V_1 * V_2 )
{
V_119 -> V_128 [ 0 ] = V_2 -> V_3 -> V_129 ;
V_119 -> V_128 [ 1 ] = V_2 -> V_3 -> V_130 ;
V_119 -> V_128 [ 2 ] = V_2 -> V_3 -> V_131 ;
V_119 -> V_128 [ 3 ] =
V_2 -> V_3 -> V_132 << 16 | V_2 -> V_3 -> V_133 ;
V_119 -> V_128 [ 4 ] =
V_2 -> V_3 -> V_134 [ 1 ] << 16 | V_2 -> V_3 -> V_134 [ 0 ] ;
}
static void
F_55 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
F_52 ( V_119 ) ;
F_53 ( V_119 ) ;
F_54 ( V_119 , V_2 ) ;
}
static inline T_4
F_56 ( void * V_116 , T_3 V_12 )
{
T_4 * V_7 = V_116 ;
T_7 V_135 = 0 ;
V_12 /= sizeof( * V_7 ) ;
while ( V_12 -- )
V_135 += * V_7 ++ ;
V_135 = ( V_135 & 0xffffffff ) + ( V_135 >> 32 ) ;
return ~ V_135 ;
}
static inline int
F_57 ( struct V_118 * V_119 )
{
return F_56 ( V_119 , V_119 -> V_136 ) == 0 ;
}
static inline int
F_58 ( struct V_118 * V_119 )
{
return V_119 -> V_137 == V_138 ;
}
static void
F_59 ( struct V_1 * V_2 )
{
struct V_118 * V_119 = V_2 -> V_3 -> V_139 ;
T_3 V_8 ;
if ( F_60 ( V_119 ) ) {
V_8 = V_119 -> V_136 ;
V_119 = memcpy ( V_2 -> V_3 -> V_140 , V_119 , V_8 ) ;
F_55 ( V_2 , V_119 ) ;
F_50 ( V_2 , V_119 , V_119 , & V_8 ) ;
V_2 -> V_3 -> V_141 = V_8 ;
V_2 -> V_3 -> V_142 = 1 ;
}
}
T_3
F_61 ( struct V_1 * V_2 )
{
struct V_118 * V_119 = V_2 -> V_3 -> V_139 ;
T_3 V_8 = 0 ;
if ( F_60 ( V_119 ) ) {
V_8 = V_119 -> V_136 ;
F_50 ( V_2 , V_119 , NULL , & V_8 ) ;
}
return V_8 ;
}
T_3
F_62 ( void * V_116 )
{
struct V_118 * V_119 = V_116 ;
return V_119 -> V_136 ;
}
T_3
F_63 ( void )
{
return sizeof( V_143 ) ;
}
const void *
F_64 ( void )
{
return V_143 ;
}
int
F_60 ( void * V_116 )
{
struct V_118 * V_119 = V_116 ;
if ( ! F_58 ( V_119 ) ) {
F_65 ( V_144 , NULL , 0xd01c ,
L_42 , V_16 , V_119 -> V_137 ) ;
return false ;
}
if ( ! F_57 ( V_119 ) ) {
F_65 ( V_144 , NULL , 0xd01d ,
L_43 , V_16 ) ;
return false ;
}
return true ;
}
void
F_66 ( T_8 * V_2 , int V_145 )
{
T_3 V_146 = 0 ;
if ( ! V_145 )
F_67 ( & V_2 -> V_3 -> V_147 , V_146 ) ;
if ( ! V_2 -> V_3 -> V_140 )
F_65 ( V_144 , V_2 , 0xd01e , L_44 ) ;
else if ( ! V_2 -> V_3 -> V_139 )
F_65 ( V_144 , V_2 , 0xd01f , L_45 ) ;
else
F_59 ( V_2 ) ;
if ( ! V_145 )
F_68 ( & V_2 -> V_3 -> V_147 , V_146 ) ;
}
