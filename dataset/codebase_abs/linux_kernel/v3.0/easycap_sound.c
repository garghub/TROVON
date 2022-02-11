void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 , V_10 ;
int V_11 ;
T_1 * V_12 , * V_13 ;
T_2 V_14 ;
int V_15 , V_16 , V_17 , V_18 , V_19 ;
#ifdef F_2
int V_20 ;
T_2 V_21 , V_22 , V_23 ;
#endif
F_3 ( 16 , L_1 ) ;
if ( ! V_2 ) {
F_4 ( L_2 ) ;
return;
}
V_4 = V_2 -> V_24 ;
if ( ! V_4 ) {
F_4 ( L_3 ) ;
return;
}
if ( memcmp ( & V_4 -> V_25 [ 0 ] , V_26 , strlen ( V_26 ) ) ) {
F_4 ( L_4 ) ;
return;
}
V_18 = 0 ;
if ( V_4 -> V_27 ) {
F_5 ( 16 , L_5 ,
V_4 -> V_27 , V_4 -> V_28 ) ;
if ( V_4 -> V_28 )
goto V_29;
}
V_6 = V_4 -> V_30 ;
if ( ! V_6 )
goto V_29;
V_8 = V_6 -> V_31 ;
if ( ! V_8 )
goto V_29;
V_9 = ( int ) V_8 -> V_9 ;
if ( 0 == V_9 )
goto V_29;
V_10 = 4 * ( ( int ) V_8 -> V_32 ) ;
if ( 0 == V_10 )
goto V_29;
if ( V_2 -> V_33 ) {
if ( ( - V_34 == V_2 -> V_33 ) || ( - V_35 == V_2 -> V_33 ) ) {
F_5 ( 16 , L_6 ) ;
return;
}
F_6 ( L_7 ,
strerror ( V_2 -> V_33 ) , V_2 -> V_33 ) ;
goto V_29;
}
#ifdef F_2
V_21 = V_4 -> V_21 ;
#endif
for ( V_15 = 0 ; V_15 < V_2 -> V_36 ; V_15 ++ ) {
if ( V_2 -> V_37 [ V_15 ] . V_33 < 0 ) {
F_6 ( L_8 ,
strerror ( V_2 -> V_37 [ V_15 ] . V_33 ) ,
V_2 -> V_37 [ V_15 ] . V_33 ) ;
}
if ( V_2 -> V_37 [ V_15 ] . V_33 ) {
F_5 ( 12 , L_9
L_10 ,
V_2 -> V_37 [ V_15 ] . V_33 ) ;
continue;
}
V_17 = V_2 -> V_37 [ V_15 ] . V_38 ;
if ( V_17 == 0 ) {
V_4 -> V_39 ++ ;
continue;
}
if ( 0 > V_17 ) {
F_6 ( L_11 ) ;
return;
}
if ( V_4 -> V_39 ) {
F_5 ( 12 , L_12 ,
V_4 -> V_39 ) ;
V_4 -> V_39 = 0 ;
}
V_12 = ( T_1 * ) ( V_2 -> V_40 +
V_2 -> V_37 [ V_15 ] . V_41 ) ;
while ( V_17 ) {
V_18 = V_9 - V_4 -> V_42 ;
if ( 0 > V_18 ) {
F_6 ( L_13 ) ;
return;
}
if ( 0 == V_18 ) {
V_4 -> V_42 = 0 ;
V_4 -> V_43 = V_10 ;
F_5 ( 8 , L_14 ) ;
}
if ( ! V_4 -> V_44 ) {
if ( V_18 > V_17 )
V_18 = V_17 ;
memcpy ( V_8 -> V_45 + V_4 -> V_42 ,
V_12 , V_18 ) ;
V_12 += V_18 ;
V_17 -= V_18 ;
} else {
#ifdef F_2
if ( V_18 % 16 )
F_5 ( 8 , L_15
L_16 ) ;
if ( V_18 > ( 16 * V_17 ) )
V_18 = 16 * V_17 ;
V_13 = ( T_1 * ) ( V_8 -> V_45 + V_4 -> V_42 ) ;
for ( V_16 = 0 ; V_16 < ( V_18 / 16 ) ; V_16 ++ ) {
V_22 = ( ( int ) * V_12 ) - 128 ;
V_22 = 128 * V_22 ;
V_23 = ( V_22 - V_21 ) / 4 ;
V_14 = V_21 + V_23 ;
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ ) {
* V_13 = ( 0x00FF & V_14 ) ;
* ( V_13 + 1 ) = ( 0xFF00 & V_14 ) >> 8 ;
V_13 += 2 ;
* V_13 = ( 0x00FF & V_14 ) ;
* ( V_13 + 1 ) = ( 0xFF00 & V_14 ) >> 8 ;
V_13 += 2 ;
V_14 += V_23 ;
}
V_12 ++ ;
V_17 -- ;
V_21 = V_14 ;
}
#else
if ( V_18 > ( 2 * V_17 ) )
V_18 = 2 * V_17 ;
V_13 = ( T_1 * ) ( V_8 -> V_45 + V_4 -> V_42 ) ;
for ( V_16 = 0 ; V_16 < ( V_18 / 2 ) ; V_16 ++ ) {
V_14 = ( ( int ) * V_12 ) - 128 ;
V_14 = 128 * V_14 ;
* V_13 = ( 0x00FF & V_14 ) ;
* ( V_13 + 1 ) = ( 0xFF00 & V_14 ) >> 8 ;
V_12 ++ ;
V_13 += 2 ;
V_17 -- ;
}
#endif
}
V_4 -> V_42 += V_18 ;
if ( V_4 -> V_42 >= V_4 -> V_43 ) {
V_11 = V_4 -> V_42 / V_10 ;
if ( 0 > V_11 ) {
F_6 ( L_17 ) ;
return;
}
V_4 -> V_46 = ( V_11 - 1 ) * V_10 ;
V_4 -> V_43 = ( V_11 + 1 ) * V_10 ;
if ( V_9 < V_4 -> V_43 )
V_4 -> V_43 = V_10 ;
if ( 0 <= V_4 -> V_46 ) {
F_5 ( 8 , L_18
L_19 , V_11 ) ;
F_7 ( V_6 ) ;
}
}
}
#ifdef F_2
V_4 -> V_21 = V_21 ;
#endif
}
V_29:
if ( V_4 -> V_28 == 0 )
return;
V_19 = F_8 ( V_2 , V_47 ) ;
if ( V_19 ) {
if ( ( - V_48 != V_19 ) && ( - V_35 != V_19 ) ) {
F_6 ( L_20
L_21 ,
V_4 -> V_27 , strerror ( V_19 ) , V_19 ) ;
}
if ( 0 < V_4 -> V_28 )
V_4 -> V_28 -- ;
}
return;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_49 * V_50 ;
struct V_51 * V_52 ;
struct V_3 * V_4 ;
F_3 ( 4 , L_1 ) ;
if ( ! V_6 ) {
F_4 ( L_22 ) ;
return - V_53 ;
}
V_50 = V_6 -> V_54 ;
if ( ! V_50 ) {
F_4 ( L_23 ) ;
return - V_53 ;
}
V_52 = V_50 -> V_55 ;
if ( ! V_52 ) {
F_4 ( L_24 ) ;
return - V_53 ;
}
V_4 = V_52 -> V_56 ;
if ( ! V_4 ) {
F_4 ( L_25 ) ;
return - V_53 ;
}
if ( memcmp ( & V_4 -> V_25 [ 0 ] , V_26 , strlen ( V_26 ) ) ) {
F_4 ( L_4 ) ;
return - V_53 ;
}
if ( V_4 -> V_52 != V_52 ) {
F_6 ( L_26 ) ;
return - V_53 ;
}
if ( V_4 -> V_30 ) {
F_6 ( L_27 ) ;
return - V_53 ;
}
V_6 -> V_56 = V_4 ;
V_4 -> V_30 = V_6 ;
V_6 -> V_31 -> V_57 = V_4 -> V_58 ;
V_6 -> V_31 -> V_56 = V_4 ;
V_6 -> V_56 = V_4 ;
if ( 0 != F_10 ( V_4 ) ) {
F_5 ( 4 , L_28 ) ;
return - V_53 ;
}
F_5 ( 4 , L_29 ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
F_3 ( 4 , L_1 ) ;
if ( ! V_6 ) {
F_4 ( L_22 ) ;
return - V_53 ;
}
V_4 = F_12 ( V_6 ) ;
if ( ! V_4 ) {
F_4 ( L_25 ) ;
return - V_53 ;
}
if ( memcmp ( & V_4 -> V_25 [ 0 ] , V_26 , strlen ( V_26 ) ) ) {
F_4 ( L_4 ) ;
return - V_53 ;
}
V_6 -> V_56 = NULL ;
V_4 -> V_30 = NULL ;
F_3 ( 4 , L_29 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 , T_3 V_59 )
{
struct V_7 * V_8 ;
F_3 ( 4 , L_1 ) ;
if ( ! V_6 ) {
F_4 ( L_22 ) ;
return - V_53 ;
}
V_8 = V_6 -> V_31 ;
if ( ! V_8 ) {
F_4 ( L_30 ) ;
return - V_53 ;
}
if ( V_8 -> V_45 ) {
if ( V_8 -> V_9 > V_59 )
return 0 ;
F_14 ( V_8 -> V_45 ) ;
}
V_8 -> V_45 = F_15 ( V_59 ) ;
if ( ! V_8 -> V_45 )
return - V_60 ;
V_8 -> V_9 = V_59 ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
struct V_61 * V_62 )
{
int V_19 ;
F_3 ( 4 , L_31 , ( F_17 ( V_62 ) ) ) ;
if ( ! V_6 ) {
F_4 ( L_22 ) ;
return - V_53 ;
}
V_19 = F_13 ( V_6 , F_17 ( V_62 ) ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static int F_18 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
F_3 ( 4 , L_1 ) ;
if ( ! V_6 ) {
F_4 ( L_22 ) ;
return - V_53 ;
}
V_8 = V_6 -> V_31 ;
if ( ! V_8 ) {
F_4 ( L_30 ) ;
return - V_53 ;
}
if ( V_8 -> V_45 ) {
F_3 ( 8 , L_32 , V_8 -> V_45 ) ;
F_14 ( V_8 -> V_45 ) ;
V_8 -> V_45 = NULL ;
} else
F_3 ( 8 , L_33 ) ;
return 0 ;
}
static int F_19 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
struct V_7 * V_8 ;
F_3 ( 4 , L_1 ) ;
if ( ! V_6 ) {
F_4 ( L_22 ) ;
return - V_53 ;
}
V_8 = V_6 -> V_31 ;
V_4 = F_12 ( V_6 ) ;
if ( ! V_4 ) {
F_4 ( L_25 ) ;
return - V_53 ;
}
if ( memcmp ( & V_4 -> V_25 [ 0 ] , V_26 , strlen ( V_26 ) ) ) {
F_4 ( L_4 ) ;
return - V_53 ;
}
F_5 ( 16 , L_34 , V_6 -> V_31 -> V_63 ) ;
F_5 ( 16 , L_35 , V_6 -> V_31 -> V_32 ) ;
F_5 ( 16 , L_36 , V_6 -> V_31 -> V_64 ) ;
F_5 ( 16 , L_37 , V_6 -> V_31 -> V_65 ) ;
F_5 ( 16 , L_38 , V_6 -> V_31 -> V_9 ) ;
F_5 ( 16 , L_39 , V_6 -> V_31 -> V_66 ) ;
F_5 ( 16 , L_40 , V_6 -> V_31 -> V_67 ) ;
F_5 ( 16 , L_41 , V_6 -> V_31 -> V_68 ) ;
F_5 ( 16 , L_42 , V_6 -> V_31 -> V_69 ) ;
F_5 ( 16 , L_43 , V_6 -> V_31 -> V_70 ) ;
F_5 ( 12 , L_44 , V_6 -> V_31 -> V_71 ) ;
F_5 ( 12 , L_45 ,
V_6 -> V_31 -> V_72 ) ;
if ( V_8 -> V_9 != 4 * ( ( int ) V_8 -> V_32 ) * ( ( int ) V_8 -> V_64 ) ) {
F_4 ( L_46 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_20 ( struct V_5 * V_6 )
{
return 0 ;
}
static int F_21 ( struct V_5 * V_6 , int V_73 )
{
struct V_3 * V_4 ;
int V_74 ;
F_3 ( 4 , L_47 , V_73 , V_75 ,
V_76 ) ;
if ( ! V_6 ) {
F_4 ( L_22 ) ;
return - V_53 ;
}
V_4 = F_12 ( V_6 ) ;
if ( ! V_4 ) {
F_4 ( L_25 ) ;
return - V_53 ;
}
if ( memcmp ( & V_4 -> V_25 [ 0 ] , V_26 , strlen ( V_26 ) ) ) {
F_4 ( L_4 ) ;
return - V_53 ;
}
switch ( V_73 ) {
case V_75 : {
V_4 -> V_27 = 0 ;
break;
}
case V_76 : {
V_4 -> V_27 = 1 ;
break;
}
default:
V_74 = - V_77 ;
}
return 0 ;
}
static T_4 F_22 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
T_4 V_41 ;
F_3 ( 16 , L_1 ) ;
if ( ! V_6 ) {
F_4 ( L_22 ) ;
return - V_53 ;
}
V_4 = F_12 ( V_6 ) ;
if ( ! V_4 ) {
F_4 ( L_25 ) ;
return - V_53 ;
}
if ( memcmp ( & V_4 -> V_25 [ 0 ] , V_26 , strlen ( V_26 ) ) ) {
F_4 ( L_4 ) ;
return - V_53 ;
}
if ( ( 0 != V_4 -> V_78 ) || ( 0 != V_4 -> V_27 ) ) {
F_5 ( 8 , L_48
L_49 ,
V_4 -> V_27 , V_4 -> V_78 ) ;
return - V_79 ;
}
if ( 0 > V_4 -> V_46 ) {
F_5 ( 8 , L_50 ) ;
return - V_80 ;
}
V_41 = ( ( T_4 ) V_4 -> V_46 ) / 4 ;
F_5 ( 8 , L_51 , ( int ) V_6 -> V_31 -> V_71 ) ;
F_5 ( 8 , L_52 ,
( int ) V_6 -> V_31 -> V_72 ) ;
F_5 ( 8 , L_53 ,
( int ) V_41 , V_4 -> V_46 , V_4 -> V_43 ) ;
return V_41 ;
}
static struct V_81 *
F_23 ( struct V_5 * V_6 , unsigned long V_41 )
{
return F_24 ( V_6 -> V_31 -> V_45 + V_41 ) ;
}
int F_25 ( struct V_3 * V_4 )
{
int V_19 ;
struct V_51 * V_52 ;
struct V_49 * V_50 ;
if ( ! V_4 ) {
F_4 ( L_3 ) ;
return - V_48 ;
}
if ( memcmp ( & V_4 -> V_25 [ 0 ] , V_26 , strlen ( V_26 ) ) ) {
F_4 ( L_4 ) ;
return - V_53 ;
}
if ( 0 > V_4 -> V_82 ) {
F_4 ( L_54 ) ;
return - V_48 ;
}
V_4 -> V_58 = V_58 ;
if ( V_4 -> V_44 ) {
V_4 -> V_58 . V_83 = V_84 ;
V_4 -> V_58 . V_85 = 32000 ;
V_4 -> V_58 . V_86 = 32000 ;
} else {
V_4 -> V_58 . V_83 = V_87 ;
V_4 -> V_58 . V_85 = 48000 ;
V_4 -> V_58 . V_86 = 48000 ;
}
if ( 0 != F_26 ( V_88 , L_55 ,
V_89 , 0 , & V_52 ) ) {
F_4 ( L_56 ) ;
return - V_53 ;
}
sprintf ( & V_52 -> V_90 [ 0 ] , L_57 , V_4 -> V_82 ) ;
strcpy ( & V_52 -> V_91 [ 0 ] , V_92 ) ;
strcpy ( & V_52 -> V_93 [ 0 ] , L_55 ) ;
sprintf ( & V_52 -> V_94 [ 0 ] , L_58 , & V_52 -> V_93 [ 0 ] ) ;
V_52 -> V_95 = & V_4 -> V_96 -> V_95 ;
V_52 -> V_56 = V_4 ;
V_4 -> V_52 = V_52 ;
V_19 = F_27 ( V_52 , L_59 , 0 , 0 , 1 , & V_50 ) ;
if ( V_19 ) {
F_6 ( L_60 ) ;
F_28 ( V_52 ) ;
return - V_53 ;
}
F_29 ( V_50 , V_97 ,
& V_98 ) ;
V_50 -> V_99 = 0 ;
strcpy ( & V_50 -> V_100 [ 0 ] , & V_52 -> V_90 [ 0 ] ) ;
V_50 -> V_56 = V_4 ;
V_4 -> V_50 = V_50 ;
V_4 -> V_30 = NULL ;
V_19 = F_30 ( V_52 ) ;
if ( V_19 ) {
F_6 ( L_61 ) ;
F_28 ( V_52 ) ;
return - V_53 ;
}
F_6 ( L_62 , & V_52 -> V_90 [ 0 ] ) ;
return 0 ;
}
int
F_10 ( struct V_3 * V_4 )
{
int V_19 ;
F_5 ( 4 , L_63 ) ;
if ( ! V_4 ) {
F_4 ( L_64 ) ;
return - V_53 ;
}
if ( ! V_4 -> V_96 ) {
F_6 ( L_65 ) ;
return - V_48 ;
}
F_5 ( 16 , L_66 , ( long int ) V_4 -> V_96 ) ;
V_19 = F_31 ( V_4 ) ;
F_5 ( 8 , L_67 , V_19 ) ;
if ( ! V_4 -> V_96 ) {
F_6 ( L_68 ) ;
return - V_48 ;
}
if ( ! V_4 -> V_96 ) {
F_6 ( L_68 ) ;
return - V_48 ;
}
V_19 = F_32 ( V_4 -> V_96 , V_4 -> V_101 ,
V_4 -> V_102 ) ;
F_5 ( 8 , L_69 , V_4 -> V_101 ,
V_4 -> V_102 , V_19 ) ;
V_19 = F_33 ( V_4 -> V_96 ) ;
F_5 ( 8 , L_70 , V_19 ) ;
V_4 -> V_78 = 0 ;
V_4 -> V_27 = 0 ;
V_4 -> V_103 . V_104 = 0 ;
V_4 -> V_103 . V_105 = 0 ;
F_34 ( V_4 ) ;
F_5 ( 4 , L_71 ) ;
return 0 ;
}
int
F_34 ( struct V_3 * V_4 )
{
struct V_106 * V_107 ;
struct V_1 * V_2 ;
struct V_108 * V_109 ;
int V_16 , V_110 , V_111 , V_112 , V_19 ;
int V_113 ;
if ( ! V_4 ) {
F_4 ( L_3 ) ;
return - V_53 ;
}
if ( ! V_4 -> V_114 ) {
F_6 ( L_72 ) ;
return - V_53 ;
}
if ( ! V_4 -> V_96 ) {
F_6 ( L_65 ) ;
return - V_53 ;
}
if ( V_4 -> V_28 ) {
F_5 ( 4 , L_73 ) ;
return 0 ;
}
F_5 ( 4 , L_74 ) ;
V_19 = F_32 ( V_4 -> V_96 ,
V_4 -> V_101 ,
V_4 -> V_102 ) ;
F_5 ( 8 , L_69 ,
V_4 -> V_101 ,
V_4 -> V_102 , V_19 ) ;
V_110 = 0 ;
V_111 = 0 ;
V_112 = 0 ;
F_35 (plist_head, peasycap->purb_audio_head) {
V_107 = F_36 ( V_109 , struct V_106 , V_108 ) ;
if ( V_107 && V_107 -> V_2 ) {
V_2 = V_107 -> V_2 ;
V_113 = V_107 -> V_113 ;
V_2 -> V_115 = 1 ;
V_2 -> V_95 = V_4 -> V_96 ;
V_2 -> V_116 = F_37 ( V_4 -> V_96 ,
V_4 -> V_117 ) ;
V_2 -> V_118 = V_119 ;
V_2 -> V_40 = V_4 -> V_120 [ V_113 ] . V_121 ;
V_2 -> V_122 = V_4 -> V_123 ;
#ifdef F_38
V_2 -> V_124 = V_125 ;
#else
V_2 -> V_124 = F_1 ;
#endif
V_2 -> V_24 = V_4 ;
V_2 -> V_126 = 0 ;
V_2 -> V_36 = V_4 -> V_127 ;
for ( V_16 = 0 ; V_16 < V_4 -> V_127 ; V_16 ++ ) {
V_2 -> V_37 [ V_16 ] . V_41 = V_16 * V_4 -> V_128 ;
V_2 -> V_37 [ V_16 ] . V_129 = V_4 -> V_128 ;
}
V_19 = F_8 ( V_2 , V_130 ) ;
if ( V_19 ) {
V_110 ++ ;
F_6 ( L_75
L_76 ,
strerror ( V_19 ) , V_19 ) ;
} else {
V_112 ++ ;
}
} else {
V_110 ++ ;
}
}
if ( V_111 ) {
F_6 ( L_77 , V_111 ) ;
F_6 ( L_78 ) ;
V_4 -> V_78 = 1 ;
}
if ( V_110 ) {
F_5 ( 4 , L_79 ) ;
F_35 (plist_head, (peasycap->purb_audio_head)) {
V_107 = F_36 ( V_109 , struct V_106 , V_108 ) ;
if ( V_107 && V_107 -> V_2 )
F_39 ( V_107 -> V_2 ) ;
}
V_4 -> V_28 = 0 ;
} else {
V_4 -> V_28 = V_112 ;
F_5 ( 4 , L_80 , V_112 ) ;
}
return 0 ;
}
int
F_40 ( struct V_3 * V_4 )
{
int V_112 ;
struct V_108 * V_109 ;
struct V_106 * V_107 ;
if ( ! V_4 ) {
F_4 ( L_3 ) ;
return - V_53 ;
}
if ( ! V_4 -> V_28 ) {
F_5 ( 8 , L_81 ,
V_4 -> V_28 ) ;
return 0 ;
}
if ( ! V_4 -> V_114 ) {
F_6 ( L_82 ) ;
return - V_53 ;
}
V_4 -> V_28 = 0 ;
F_5 ( 4 , L_83 ) ;
V_112 = 0 ;
F_35 (plist_head, (peasycap->purb_audio_head)) {
V_107 = F_36 ( V_109 , struct V_106 , V_108 ) ;
if ( V_107 && V_107 -> V_2 ) {
F_39 ( V_107 -> V_2 ) ;
V_112 ++ ;
}
}
F_5 ( 4 , L_84 , V_112 ) ;
return 0 ;
}
