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
} else {
F_20 ( V_27 , V_2 , 0xd022 ,
L_11 , V_30 , V_23 -> V_47 . V_48 ) ;
F_19 ( V_23 , V_7 ) ;
goto V_57;
}
if ( V_46 < V_45 || V_46 == 0 ) {
F_20 ( V_27 , V_2 , 0xd023 ,
L_12 , V_30 ,
V_23 -> V_47 . V_50 , V_23 -> V_47 . V_49 ) ;
F_19 ( V_23 , V_7 ) ;
goto V_57;
}
V_44 = V_46 - V_45 + 1 ;
if ( V_7 ) {
V_7 += * V_8 ;
F_30 ( V_2 -> V_3 , V_45 , V_7 , V_44 , & V_7 ) ;
}
* V_8 += V_44 * sizeof( T_4 ) ;
V_57:
return false ;
}
static int
F_31 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_6 V_19 = 0 ;
T_6 V_58 ;
T_6 V_59 ;
F_20 ( V_27 , V_2 , 0xd207 ,
L_13 , V_30 , V_23 -> V_60 . V_61 , * V_8 ) ;
if ( V_23 -> V_60 . V_61 == V_62 ) {
for ( V_58 = 0 ; V_58 < V_2 -> V_3 -> V_63 ; V_58 ++ ) {
struct V_64 * V_65 = V_2 -> V_3 -> V_66 [ V_58 ] ;
if ( V_65 || ! V_7 ) {
V_59 = V_65 ?
V_65 -> V_59 : V_67 ;
F_2 ( V_58 , V_7 , V_8 ) ;
F_2 ( V_59 , V_7 , V_8 ) ;
F_6 ( V_65 ? V_65 -> V_68 : NULL ,
V_59 * sizeof( * V_65 -> V_68 ) , V_7 , V_8 ) ;
V_19 ++ ;
}
}
} else if ( V_23 -> V_60 . V_61 == V_69 ) {
for ( V_58 = 0 ; V_58 < V_2 -> V_3 -> V_70 ; V_58 ++ ) {
struct V_71 * V_72 = V_2 -> V_3 -> V_73 [ V_58 ] ;
if ( V_72 || ! V_7 ) {
V_59 = V_72 ?
V_72 -> V_59 : V_74 ;
F_2 ( V_58 , V_7 , V_8 ) ;
F_2 ( V_59 , V_7 , V_8 ) ;
F_6 ( V_72 ? V_72 -> V_68 : NULL ,
V_59 * sizeof( * V_72 -> V_68 ) , V_7 , V_8 ) ;
V_19 ++ ;
}
}
} else {
F_20 ( V_27 , V_2 , 0xd026 ,
L_14 , V_30 , V_23 -> V_60 . V_61 ) ;
F_19 ( V_23 , V_7 ) ;
}
if ( V_7 )
V_23 -> V_60 . V_75 = V_19 ;
return false ;
}
static int
F_32 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_20 ( V_27 , V_2 , 0xd208 ,
L_15 , V_30 , * V_8 ) ;
if ( V_2 -> V_3 -> V_76 ) {
if ( V_7 ) {
V_23 -> V_77 . V_78 = V_79 ;
V_23 -> V_77 . V_80 = V_2 -> V_3 -> V_81 ;
V_23 -> V_77 . V_82 = V_2 -> V_3 -> V_83 ;
V_23 -> V_77 . V_84 = V_2 -> V_3 -> V_85 [ 0 ] ;
V_23 -> V_77 . V_86 = V_2 -> V_3 -> V_85 [ 2 ] ;
V_23 -> V_77 . V_87 = V_2 -> V_3 -> V_85 [ 3 ] ;
V_23 -> V_77 . V_88 = V_2 -> V_3 -> V_85 [ 4 ] ;
V_23 -> V_77 . V_89 = V_2 -> V_3 -> V_85 [ 5 ] ;
V_23 -> V_77 . V_90 = V_2 -> V_3 -> V_85 [ 6 ] ;
}
F_6 ( V_2 -> V_3 -> V_76 , V_79 , V_7 , V_8 ) ;
} else {
F_20 ( V_27 , V_2 , 0xd027 ,
L_16 , V_30 ) ;
F_19 ( V_23 , V_7 ) ;
}
return false ;
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_20 ( V_27 , V_2 , 0xd209 ,
L_17 , V_30 , * V_8 ) ;
if ( V_7 )
F_34 ( V_15 , V_2 -> V_3 ) ;
return false ;
}
static int
F_35 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_20 ( V_27 , V_2 , 0xd20a ,
L_18 , V_30 , * V_8 ) ;
if ( V_7 )
F_36 ( V_2 -> V_3 ) ;
return false ;
}
static int
F_37 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
F_20 ( V_27 , V_2 , 0xd20b ,
L_19 , V_30 , * V_8 ) ;
F_14 ( V_15 , V_23 -> V_91 . V_33 , V_23 -> V_91 . V_17 , V_7 ) ;
return false ;
}
static int
F_38 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_20 ( V_27 , V_2 , 0xd20c ,
L_20 , V_30 , V_23 -> V_92 . V_93 , * V_8 ) ;
if ( V_23 -> V_92 . V_93 == V_94 ) {
if ( V_2 -> V_3 -> V_95 ) {
if ( V_7 ) {
V_23 -> V_92 . V_96 = V_97 ;
V_23 -> V_92 . V_49 = V_2 -> V_3 -> V_98 ;
}
F_6 ( V_2 -> V_3 -> V_95 , V_97 , V_7 , V_8 ) ;
} else {
F_20 ( V_27 , V_2 , 0xd028 ,
L_21 , V_30 ) ;
F_19 ( V_23 , V_7 ) ;
}
} else {
F_20 ( V_27 , V_2 , 0xd02b ,
L_22 , V_30 , V_23 -> V_92 . V_93 ) ;
F_19 ( V_23 , V_7 ) ;
}
return false ;
}
static int
F_39 ( struct V_1 * V_2 ,
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
V_23 -> V_99 . V_100 = 5 * sizeof( T_4 ) ;
return false ;
}
static int
F_40 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
T_3 V_44 = V_23 -> V_101 . V_19 ;
T_3 V_18 = V_23 -> V_101 . V_18 ;
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
F_41 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
struct V_14 T_1 * V_15 = F_1 ( V_2 ) ;
T_3 V_18 = V_23 -> V_102 . V_18 ;
T_3 V_17 = V_23 -> V_102 . V_17 ;
F_20 ( V_27 , V_2 , 0xd20f ,
L_25 , V_30 , * V_8 ) ;
F_14 ( V_15 , V_21 , 0x40 , V_7 ) ;
F_14 ( V_15 , 0xc4 , V_17 , V_7 ) ;
F_14 ( V_15 , 0xc0 , V_18 , V_7 ) ;
return false ;
}
static int
F_42 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_3 V_44 = V_23 -> V_103 . V_19 ;
T_3 V_45 = V_23 -> V_103 . V_18 ;
F_20 ( V_27 , V_2 , 0xd210 ,
L_26 , V_30 , * V_8 ) ;
if ( V_7 ) {
F_20 ( V_27 , V_2 , 0xd02c ,
L_27 , V_30 , V_45 , V_44 ) ;
V_7 += * V_8 ;
F_43 ( V_2 -> V_3 , V_45 , V_7 , V_44 , & V_7 ) ;
}
* V_8 += V_44 * sizeof( T_4 ) ;
return false ;
}
static int
F_44 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_3 V_44 = V_23 -> V_104 . V_19 ;
T_3 V_18 = V_23 -> V_104 . V_18 ;
T_4 V_6 ;
F_20 ( V_27 , V_2 , 0xd211 ,
L_28 , V_30 , * V_8 ) ;
while ( V_44 -- ) {
V_6 = ~ 0 ;
if ( F_45 ( V_2 -> V_3 -> V_105 , V_18 , & V_6 ) )
F_20 ( V_27 , V_2 , 0xd02d ,
L_29 , V_30 , V_18 ) ;
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
T_6 V_58 ;
F_20 ( V_27 , V_2 , 0xd212 ,
L_30 , V_30 , V_23 -> V_106 . V_61 , * V_8 ) ;
if ( V_23 -> V_106 . V_61 == V_107 ) {
for ( V_58 = 0 ; V_58 < V_2 -> V_3 -> V_63 ; V_58 ++ ) {
struct V_64 * V_65 = V_2 -> V_3 -> V_66 [ V_58 ] ;
if ( V_65 || ! V_7 ) {
F_2 ( V_58 , V_7 , V_8 ) ;
F_2 ( 1 , V_7 , V_8 ) ;
F_4 ( V_65 && V_65 -> V_108 ?
* V_65 -> V_108 : 0 , V_7 , V_8 ) ;
V_19 ++ ;
}
}
} else if ( V_23 -> V_106 . V_61 == V_109 ) {
for ( V_58 = 0 ; V_58 < V_2 -> V_3 -> V_70 ; V_58 ++ ) {
struct V_71 * V_72 = V_2 -> V_3 -> V_73 [ V_58 ] ;
if ( V_72 || ! V_7 ) {
F_2 ( V_58 , V_7 , V_8 ) ;
F_2 ( 1 , V_7 , V_8 ) ;
F_4 ( V_72 && V_72 -> V_110 ?
* V_72 -> V_110 : 0 , V_7 , V_8 ) ;
V_19 ++ ;
}
}
} else {
F_20 ( V_27 , V_2 , 0xd02f ,
L_14 , V_30 , V_23 -> V_106 . V_61 ) ;
F_19 ( V_23 , V_7 ) ;
}
if ( V_7 )
V_23 -> V_106 . V_75 = V_19 ;
if ( ! V_19 )
F_19 ( V_23 , V_7 ) ;
return false ;
}
static int
F_47 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
T_3 V_16 = F_48 ( F_49 ( * V_23 ) , V_111 . V_112 ) ;
F_20 ( V_27 , V_2 , 0xd213 ,
L_31 , V_30 , V_23 -> V_111 . V_59 , * V_8 ) ;
if ( ! V_23 -> V_111 . V_59 ) {
F_20 ( V_27 , V_2 , 0xd020 ,
L_32 , V_30 ) ;
F_19 ( V_23 , V_7 ) ;
goto V_57;
}
if ( V_16 + V_23 -> V_111 . V_59 > V_23 -> V_24 . V_113 ) {
F_20 ( V_27 , V_2 , 0xd030 ,
L_33 , V_30 ) ;
F_19 ( V_23 , V_7 ) ;
goto V_57;
}
F_6 ( V_23 -> V_111 . V_112 , V_23 -> V_111 . V_59 , V_7 , V_8 ) ;
V_57:
return false ;
}
static int
F_50 ( struct V_1 * V_2 ,
struct V_22 * V_23 , void * V_7 , T_3 * V_8 )
{
F_20 ( V_27 , V_2 , 0xd2ff ,
L_34 , V_30 , V_23 -> V_24 . V_29 , * V_8 ) ;
F_19 ( V_23 , V_7 ) ;
return false ;
}
inline void *
F_51 ( void * V_114 )
{
struct V_22 * V_23 = V_114 ;
return V_114 + V_23 -> V_24 . V_113 ;
}
static void
F_52 ( struct V_1 * V_2 ,
struct V_115 * V_116 , void * V_7 , T_3 * V_8 )
{
struct V_22 * V_23 = ( void * ) V_116 + V_116 -> V_117 ;
T_3 V_19 = V_116 -> V_118 ;
F_20 ( V_27 , V_2 , 0xd01a ,
L_35 , V_30 , V_19 ) ;
while ( V_19 -- ) {
if ( F_53 ( V_23 -> V_24 . V_29 ) ( V_2 , V_23 , V_7 , V_8 ) )
break;
V_23 = F_51 ( V_23 ) ;
}
if ( V_19 )
F_20 ( V_27 , V_2 , 0xd018 ,
L_36 , V_30 , V_19 ) ;
if ( V_23 -> V_24 . V_29 != V_119 )
F_20 ( V_27 , V_2 , 0xd019 ,
L_37 , V_30 , V_19 ) ;
F_20 ( V_27 , V_2 , 0xd01b ,
L_38 , V_30 , * V_8 ) ;
if ( V_7 ) {
F_54 ( V_120 , V_2 , 0xd015 ,
L_39 ,
V_2 -> V_121 , V_2 -> V_3 -> V_122 ) ;
F_55 ( V_2 , V_123 ) ;
}
}
static void
F_56 ( struct V_115 * V_116 )
{
V_116 -> V_124 = V_125 ;
}
static void
F_57 ( struct V_115 * V_116 )
{
T_5 V_126 [] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
sscanf ( V_127 , L_40 ,
V_126 + 0 , V_126 + 1 , V_126 + 2 , V_126 + 3 , V_126 + 4 , V_126 + 5 ) ;
V_116 -> V_128 [ 0 ] = V_126 [ 3 ] << 24 | V_126 [ 2 ] << 16 | V_126 [ 1 ] << 8 | V_126 [ 0 ] ;
V_116 -> V_128 [ 1 ] = V_126 [ 5 ] << 8 | V_126 [ 4 ] ;
V_116 -> V_128 [ 2 ] = 0x12345678 ;
}
static void
F_58 ( struct V_115 * V_116 ,
struct V_1 * V_2 )
{
V_116 -> V_129 [ 0 ] = V_2 -> V_3 -> V_130 ;
V_116 -> V_129 [ 1 ] = V_2 -> V_3 -> V_131 ;
V_116 -> V_129 [ 2 ] = V_2 -> V_3 -> V_132 ;
V_116 -> V_129 [ 3 ] =
V_2 -> V_3 -> V_133 << 16 | V_2 -> V_3 -> V_134 ;
V_116 -> V_129 [ 4 ] =
V_2 -> V_3 -> V_135 [ 1 ] << 16 | V_2 -> V_3 -> V_135 [ 0 ] ;
}
static void
F_59 ( struct V_1 * V_2 ,
struct V_115 * V_116 )
{
F_56 ( V_116 ) ;
F_57 ( V_116 ) ;
F_58 ( V_116 , V_2 ) ;
}
static inline T_4
F_60 ( void * V_114 , T_3 V_12 )
{
T_4 * V_7 = V_114 ;
T_7 V_136 = 0 ;
V_12 /= sizeof( * V_7 ) ;
while ( V_12 -- )
V_136 += * V_7 ++ ;
V_136 = ( V_136 & 0xffffffff ) + ( V_136 >> 32 ) ;
return ~ V_136 ;
}
static inline int
F_61 ( struct V_115 * V_116 )
{
return F_60 ( V_116 , V_116 -> V_137 ) == 0 ;
}
static inline int
F_62 ( struct V_115 * V_116 )
{
return V_116 -> V_138 == V_139 ;
}
static void
F_63 ( struct V_1 * V_2 )
{
struct V_115 * V_116 = V_2 -> V_3 -> V_140 ;
T_3 V_8 ;
if ( F_64 ( V_116 ) ) {
V_8 = V_116 -> V_137 ;
V_116 = memcpy ( V_2 -> V_3 -> V_122 , V_116 , V_8 ) ;
F_59 ( V_2 , V_116 ) ;
F_52 ( V_2 , V_116 , V_116 , & V_8 ) ;
V_2 -> V_3 -> V_141 = V_8 ;
V_2 -> V_3 -> V_142 = 1 ;
}
}
T_3
F_65 ( struct V_1 * V_2 )
{
struct V_115 * V_116 = V_2 -> V_3 -> V_140 ;
T_3 V_8 = 0 ;
if ( F_64 ( V_116 ) ) {
V_8 = V_116 -> V_137 ;
F_52 ( V_2 , V_116 , NULL , & V_8 ) ;
}
return V_8 ;
}
T_3
F_66 ( void * V_114 )
{
struct V_115 * V_116 = V_114 ;
return V_116 -> V_137 ;
}
T_3
F_67 ( void )
{
return sizeof( V_143 ) ;
}
const void *
F_68 ( void )
{
return V_143 ;
}
int
F_64 ( void * V_114 )
{
struct V_115 * V_116 = V_114 ;
if ( ! F_62 ( V_116 ) ) {
F_54 ( V_120 , NULL , 0xd01c ,
L_41 , V_30 , V_116 -> V_138 ) ;
return false ;
}
if ( ! F_61 ( V_116 ) ) {
F_54 ( V_120 , NULL , 0xd01d ,
L_42 , V_30 ) ;
return false ;
}
return true ;
}
void
F_69 ( T_8 * V_2 , int V_144 )
{
T_3 V_145 = 0 ;
#ifndef F_70
if ( ! V_144 )
F_71 ( & V_2 -> V_3 -> V_146 , V_145 ) ;
#endif
if ( ! V_2 -> V_3 -> V_122 )
F_54 ( V_120 , V_2 , 0xd01e , L_43 ) ;
else if ( ! V_2 -> V_3 -> V_140 )
F_54 ( V_120 , V_2 , 0xd01f , L_44 ) ;
else if ( V_2 -> V_3 -> V_142 )
F_54 ( V_120 , V_2 , 0xd300 ,
L_45
L_46 , V_2 -> V_3 -> V_122 ) ;
else
F_63 ( V_2 ) ;
#ifndef F_70
if ( ! V_144 )
F_72 ( & V_2 -> V_3 -> V_146 , V_145 ) ;
#endif
}
