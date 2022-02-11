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
V_18 = 0 ;
if ( V_4 -> V_25 ) {
F_5 ( 16 , L_4 ,
V_4 -> V_25 , V_4 -> V_26 ) ;
if ( V_4 -> V_26 )
goto V_27;
}
V_6 = V_4 -> V_28 ;
if ( ! V_6 )
goto V_27;
V_8 = V_6 -> V_29 ;
if ( ! V_8 )
goto V_27;
V_9 = ( int ) V_8 -> V_9 ;
if ( 0 == V_9 )
goto V_27;
V_10 = 4 * ( ( int ) V_8 -> V_30 ) ;
if ( 0 == V_10 )
goto V_27;
if ( V_2 -> V_31 ) {
if ( ( - V_32 == V_2 -> V_31 ) || ( - V_33 == V_2 -> V_31 ) ) {
F_5 ( 16 , L_5 ) ;
return;
}
F_6 ( L_6 ,
strerror ( V_2 -> V_31 ) , V_2 -> V_31 ) ;
goto V_27;
}
#ifdef F_2
V_21 = V_4 -> V_21 ;
#endif
for ( V_15 = 0 ; V_15 < V_2 -> V_34 ; V_15 ++ ) {
if ( V_2 -> V_35 [ V_15 ] . V_31 < 0 ) {
F_6 ( L_7 ,
strerror ( V_2 -> V_35 [ V_15 ] . V_31 ) ,
V_2 -> V_35 [ V_15 ] . V_31 ) ;
}
if ( V_2 -> V_35 [ V_15 ] . V_31 ) {
F_5 ( 12 , L_8
L_9 ,
V_2 -> V_35 [ V_15 ] . V_31 ) ;
continue;
}
V_17 = V_2 -> V_35 [ V_15 ] . V_36 ;
if ( V_17 == 0 ) {
V_4 -> V_37 ++ ;
continue;
}
if ( 0 > V_17 ) {
F_6 ( L_10 ) ;
return;
}
if ( V_4 -> V_37 ) {
F_5 ( 12 , L_11 ,
V_4 -> V_37 ) ;
V_4 -> V_37 = 0 ;
}
V_12 = ( T_1 * ) ( V_2 -> V_38 +
V_2 -> V_35 [ V_15 ] . V_39 ) ;
while ( V_17 ) {
V_18 = V_9 - V_4 -> V_40 ;
if ( 0 > V_18 ) {
F_6 ( L_12 ) ;
return;
}
if ( 0 == V_18 ) {
V_4 -> V_40 = 0 ;
V_4 -> V_41 = V_10 ;
F_5 ( 8 , L_13 ) ;
}
if ( ! V_4 -> V_42 ) {
if ( V_18 > V_17 )
V_18 = V_17 ;
memcpy ( V_8 -> V_43 + V_4 -> V_40 ,
V_12 , V_18 ) ;
V_12 += V_18 ;
V_17 -= V_18 ;
} else {
#ifdef F_2
if ( V_18 % 16 )
F_5 ( 8 , L_14
L_15 ) ;
if ( V_18 > ( 16 * V_17 ) )
V_18 = 16 * V_17 ;
V_13 = ( T_1 * ) ( V_8 -> V_43 + V_4 -> V_40 ) ;
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
V_13 = ( T_1 * ) ( V_8 -> V_43 + V_4 -> V_40 ) ;
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
V_4 -> V_40 += V_18 ;
if ( V_4 -> V_40 >= V_4 -> V_41 ) {
V_11 = V_4 -> V_40 / V_10 ;
if ( 0 > V_11 ) {
F_6 ( L_16 ) ;
return;
}
V_4 -> V_44 = ( V_11 - 1 ) * V_10 ;
V_4 -> V_41 = ( V_11 + 1 ) * V_10 ;
if ( V_9 < V_4 -> V_41 )
V_4 -> V_41 = V_10 ;
if ( 0 <= V_4 -> V_44 ) {
F_5 ( 8 , L_17
L_18 , V_11 ) ;
F_7 ( V_6 ) ;
}
}
}
#ifdef F_2
V_4 -> V_21 = V_21 ;
#endif
}
V_27:
if ( V_4 -> V_26 == 0 )
return;
V_19 = F_8 ( V_2 , V_45 ) ;
if ( V_19 ) {
if ( ( - V_46 != V_19 ) && ( - V_33 != V_19 ) ) {
F_6 ( L_19
L_20 ,
V_4 -> V_25 , strerror ( V_19 ) , V_19 ) ;
}
if ( 0 < V_4 -> V_26 )
V_4 -> V_26 -- ;
}
return;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_3 * V_4 ;
F_3 ( 4 , L_1 ) ;
if ( ! V_6 ) {
F_4 ( L_21 ) ;
return - V_51 ;
}
V_48 = V_6 -> V_52 ;
if ( ! V_48 ) {
F_4 ( L_22 ) ;
return - V_51 ;
}
V_50 = V_48 -> V_53 ;
if ( ! V_50 ) {
F_4 ( L_23 ) ;
return - V_51 ;
}
V_4 = V_50 -> V_54 ;
if ( ! V_4 ) {
F_4 ( L_24 ) ;
return - V_51 ;
}
if ( V_4 -> V_50 != V_50 ) {
F_6 ( L_25 ) ;
return - V_51 ;
}
if ( V_4 -> V_28 ) {
F_6 ( L_26 ) ;
return - V_51 ;
}
V_6 -> V_54 = V_4 ;
V_4 -> V_28 = V_6 ;
V_6 -> V_29 -> V_55 = V_4 -> V_56 ;
V_6 -> V_29 -> V_54 = V_4 ;
V_6 -> V_54 = V_4 ;
if ( 0 != F_10 ( V_4 ) ) {
F_5 ( 4 , L_27 ) ;
return - V_51 ;
}
F_5 ( 4 , L_28 ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
F_3 ( 4 , L_1 ) ;
if ( ! V_6 ) {
F_4 ( L_21 ) ;
return - V_51 ;
}
V_4 = F_12 ( V_6 ) ;
if ( ! V_4 ) {
F_4 ( L_24 ) ;
return - V_51 ;
}
V_6 -> V_54 = NULL ;
V_4 -> V_28 = NULL ;
F_3 ( 4 , L_28 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 , T_3 V_57 )
{
struct V_7 * V_8 ;
F_3 ( 4 , L_1 ) ;
if ( ! V_6 ) {
F_4 ( L_21 ) ;
return - V_51 ;
}
V_8 = V_6 -> V_29 ;
if ( ! V_8 ) {
F_4 ( L_29 ) ;
return - V_51 ;
}
if ( V_8 -> V_43 ) {
if ( V_8 -> V_9 > V_57 )
return 0 ;
F_14 ( V_8 -> V_43 ) ;
}
V_8 -> V_43 = F_15 ( V_57 ) ;
if ( ! V_8 -> V_43 )
return - V_58 ;
V_8 -> V_9 = V_57 ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
struct V_59 * V_60 )
{
int V_19 ;
F_3 ( 4 , L_30 , ( F_17 ( V_60 ) ) ) ;
if ( ! V_6 ) {
F_4 ( L_21 ) ;
return - V_51 ;
}
V_19 = F_13 ( V_6 , F_17 ( V_60 ) ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static int F_18 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
F_3 ( 4 , L_1 ) ;
if ( ! V_6 ) {
F_4 ( L_21 ) ;
return - V_51 ;
}
V_8 = V_6 -> V_29 ;
if ( ! V_8 ) {
F_4 ( L_29 ) ;
return - V_51 ;
}
if ( V_8 -> V_43 ) {
F_3 ( 8 , L_31 , V_8 -> V_43 ) ;
F_14 ( V_8 -> V_43 ) ;
V_8 -> V_43 = NULL ;
} else
F_3 ( 8 , L_32 ) ;
return 0 ;
}
static int F_19 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
struct V_7 * V_8 ;
F_3 ( 4 , L_1 ) ;
if ( ! V_6 ) {
F_4 ( L_21 ) ;
return - V_51 ;
}
V_8 = V_6 -> V_29 ;
V_4 = F_12 ( V_6 ) ;
if ( ! V_4 ) {
F_4 ( L_24 ) ;
return - V_51 ;
}
F_5 ( 16 , L_33 , V_6 -> V_29 -> V_61 ) ;
F_5 ( 16 , L_34 , V_6 -> V_29 -> V_30 ) ;
F_5 ( 16 , L_35 , V_6 -> V_29 -> V_62 ) ;
F_5 ( 16 , L_36 , V_6 -> V_29 -> V_63 ) ;
F_5 ( 16 , L_37 , V_6 -> V_29 -> V_9 ) ;
F_5 ( 16 , L_38 , V_6 -> V_29 -> V_64 ) ;
F_5 ( 16 , L_39 , V_6 -> V_29 -> V_65 ) ;
F_5 ( 16 , L_40 , V_6 -> V_29 -> V_66 ) ;
F_5 ( 16 , L_41 , V_6 -> V_29 -> V_67 ) ;
F_5 ( 16 , L_42 , V_6 -> V_29 -> V_68 ) ;
F_5 ( 12 , L_43 , V_6 -> V_29 -> V_69 ) ;
F_5 ( 12 , L_44 ,
V_6 -> V_29 -> V_70 ) ;
if ( V_8 -> V_9 != 4 * ( ( int ) V_8 -> V_30 ) * ( ( int ) V_8 -> V_62 ) ) {
F_4 ( L_45 ) ;
return - V_33 ;
}
return 0 ;
}
static int F_20 ( struct V_5 * V_6 )
{
return 0 ;
}
static int F_21 ( struct V_5 * V_6 , int V_71 )
{
struct V_3 * V_4 ;
int V_72 ;
F_3 ( 4 , L_46 , V_71 , V_73 ,
V_74 ) ;
if ( ! V_6 ) {
F_4 ( L_21 ) ;
return - V_51 ;
}
V_4 = F_12 ( V_6 ) ;
if ( ! V_4 ) {
F_4 ( L_24 ) ;
return - V_51 ;
}
switch ( V_71 ) {
case V_73 : {
V_4 -> V_25 = 0 ;
break;
}
case V_74 : {
V_4 -> V_25 = 1 ;
break;
}
default:
V_72 = - V_75 ;
}
return 0 ;
}
static T_4 F_22 ( struct V_5 * V_6 )
{
struct V_3 * V_4 ;
T_4 V_39 ;
F_3 ( 16 , L_1 ) ;
if ( ! V_6 ) {
F_4 ( L_21 ) ;
return - V_51 ;
}
V_4 = F_12 ( V_6 ) ;
if ( ! V_4 ) {
F_4 ( L_24 ) ;
return - V_51 ;
}
if ( ( 0 != V_4 -> V_76 ) || ( 0 != V_4 -> V_25 ) ) {
F_5 ( 8 , L_47
L_48 ,
V_4 -> V_25 , V_4 -> V_76 ) ;
return - V_77 ;
}
if ( 0 > V_4 -> V_44 ) {
F_5 ( 8 , L_49 ) ;
return - V_78 ;
}
V_39 = ( ( T_4 ) V_4 -> V_44 ) / 4 ;
F_5 ( 8 , L_50 , ( int ) V_6 -> V_29 -> V_69 ) ;
F_5 ( 8 , L_51 ,
( int ) V_6 -> V_29 -> V_70 ) ;
F_5 ( 8 , L_52 ,
( int ) V_39 , V_4 -> V_44 , V_4 -> V_41 ) ;
return V_39 ;
}
static struct V_79 *
F_23 ( struct V_5 * V_6 , unsigned long V_39 )
{
return F_24 ( V_6 -> V_29 -> V_43 + V_39 ) ;
}
int F_25 ( struct V_3 * V_4 )
{
int V_19 ;
struct V_49 * V_50 ;
struct V_47 * V_48 ;
if ( ! V_4 ) {
F_4 ( L_3 ) ;
return - V_46 ;
}
if ( 0 > V_4 -> V_80 ) {
F_4 ( L_53 ) ;
return - V_46 ;
}
V_4 -> V_56 = V_56 ;
if ( V_4 -> V_42 ) {
V_4 -> V_56 . V_81 = V_82 ;
V_4 -> V_56 . V_83 = 32000 ;
V_4 -> V_56 . V_84 = 32000 ;
} else {
V_4 -> V_56 . V_81 = V_85 ;
V_4 -> V_56 . V_83 = 48000 ;
V_4 -> V_56 . V_84 = 48000 ;
}
if ( 0 != F_26 ( V_86 , L_54 ,
V_87 , 0 , & V_50 ) ) {
F_4 ( L_55 ) ;
return - V_51 ;
}
sprintf ( & V_50 -> V_88 [ 0 ] , L_56 , V_4 -> V_80 ) ;
strcpy ( & V_50 -> V_89 [ 0 ] , V_90 ) ;
strcpy ( & V_50 -> V_91 [ 0 ] , L_54 ) ;
sprintf ( & V_50 -> V_92 [ 0 ] , L_57 , & V_50 -> V_91 [ 0 ] ) ;
V_50 -> V_93 = & V_4 -> V_94 -> V_93 ;
V_50 -> V_54 = V_4 ;
V_4 -> V_50 = V_50 ;
V_19 = F_27 ( V_50 , L_58 , 0 , 0 , 1 , & V_48 ) ;
if ( V_19 ) {
F_6 ( L_59 ) ;
F_28 ( V_50 ) ;
return - V_51 ;
}
F_29 ( V_48 , V_95 ,
& V_96 ) ;
V_48 -> V_97 = 0 ;
strcpy ( & V_48 -> V_98 [ 0 ] , & V_50 -> V_88 [ 0 ] ) ;
V_48 -> V_54 = V_4 ;
V_4 -> V_48 = V_48 ;
V_4 -> V_28 = NULL ;
V_19 = F_30 ( V_50 ) ;
if ( V_19 ) {
F_6 ( L_60 ) ;
F_28 ( V_50 ) ;
return - V_51 ;
}
F_6 ( L_61 , & V_50 -> V_88 [ 0 ] ) ;
return 0 ;
}
int
F_10 ( struct V_3 * V_4 )
{
int V_19 ;
F_5 ( 4 , L_62 ) ;
if ( ! V_4 ) {
F_4 ( L_63 ) ;
return - V_51 ;
}
if ( ! V_4 -> V_94 ) {
F_6 ( L_64 ) ;
return - V_46 ;
}
F_5 ( 16 , L_65 , ( long int ) V_4 -> V_94 ) ;
V_19 = F_31 ( V_4 ) ;
F_5 ( 8 , L_66 , V_19 ) ;
if ( ! V_4 -> V_94 ) {
F_6 ( L_67 ) ;
return - V_46 ;
}
if ( ! V_4 -> V_94 ) {
F_6 ( L_67 ) ;
return - V_46 ;
}
V_19 = F_32 ( V_4 -> V_94 , V_4 -> V_99 ,
V_4 -> V_100 ) ;
F_5 ( 8 , L_68 , V_4 -> V_99 ,
V_4 -> V_100 , V_19 ) ;
V_19 = F_33 ( V_4 -> V_94 ) ;
F_5 ( 8 , L_69 , V_19 ) ;
V_4 -> V_76 = 0 ;
V_4 -> V_25 = 0 ;
F_34 ( V_4 ) ;
F_5 ( 4 , L_70 ) ;
return 0 ;
}
int
F_34 ( struct V_3 * V_4 )
{
struct V_101 * V_102 ;
struct V_1 * V_2 ;
struct V_103 * V_104 ;
int V_16 , V_105 , V_106 , V_107 , V_19 ;
int V_108 ;
if ( ! V_4 ) {
F_4 ( L_3 ) ;
return - V_51 ;
}
if ( ! V_4 -> V_109 ) {
F_6 ( L_71 ) ;
return - V_51 ;
}
if ( ! V_4 -> V_94 ) {
F_6 ( L_64 ) ;
return - V_51 ;
}
if ( V_4 -> V_26 ) {
F_5 ( 4 , L_72 ) ;
return 0 ;
}
F_5 ( 4 , L_73 ) ;
V_19 = F_32 ( V_4 -> V_94 ,
V_4 -> V_99 ,
V_4 -> V_100 ) ;
F_5 ( 8 , L_68 ,
V_4 -> V_99 ,
V_4 -> V_100 , V_19 ) ;
V_105 = 0 ;
V_106 = 0 ;
V_107 = 0 ;
F_35 (plist_head, peasycap->purb_audio_head) {
V_102 = F_36 ( V_104 , struct V_101 , V_103 ) ;
if ( V_102 && V_102 -> V_2 ) {
V_2 = V_102 -> V_2 ;
V_108 = V_102 -> V_108 ;
V_2 -> V_110 = 1 ;
V_2 -> V_93 = V_4 -> V_94 ;
V_2 -> V_111 = F_37 ( V_4 -> V_94 ,
V_4 -> V_112 ) ;
V_2 -> V_113 = V_114 ;
V_2 -> V_38 = V_4 -> V_115 [ V_108 ] . V_116 ;
V_2 -> V_117 = V_4 -> V_118 ;
V_2 -> V_119 = F_1 ;
V_2 -> V_24 = V_4 ;
V_2 -> V_120 = 0 ;
V_2 -> V_34 = V_4 -> V_121 ;
for ( V_16 = 0 ; V_16 < V_4 -> V_121 ; V_16 ++ ) {
V_2 -> V_35 [ V_16 ] . V_39 = V_16 * V_4 -> V_122 ;
V_2 -> V_35 [ V_16 ] . V_123 = V_4 -> V_122 ;
}
V_19 = F_8 ( V_2 , V_124 ) ;
if ( V_19 ) {
V_105 ++ ;
F_6 ( L_74
L_75 ,
strerror ( V_19 ) , V_19 ) ;
} else {
V_107 ++ ;
}
} else {
V_105 ++ ;
}
}
if ( V_106 ) {
F_6 ( L_76 , V_106 ) ;
F_6 ( L_77 ) ;
V_4 -> V_76 = 1 ;
}
if ( V_105 ) {
F_5 ( 4 , L_78 ) ;
F_35 (plist_head, (peasycap->purb_audio_head)) {
V_102 = F_36 ( V_104 , struct V_101 , V_103 ) ;
if ( V_102 && V_102 -> V_2 )
F_38 ( V_102 -> V_2 ) ;
}
V_4 -> V_26 = 0 ;
} else {
V_4 -> V_26 = V_107 ;
F_5 ( 4 , L_79 , V_107 ) ;
}
return 0 ;
}
int
F_39 ( struct V_3 * V_4 )
{
int V_107 ;
struct V_103 * V_104 ;
struct V_101 * V_102 ;
if ( ! V_4 ) {
F_4 ( L_3 ) ;
return - V_51 ;
}
if ( ! V_4 -> V_26 ) {
F_5 ( 8 , L_80 ,
V_4 -> V_26 ) ;
return 0 ;
}
if ( ! V_4 -> V_109 ) {
F_6 ( L_81 ) ;
return - V_51 ;
}
V_4 -> V_26 = 0 ;
F_5 ( 4 , L_82 ) ;
V_107 = 0 ;
F_35 (plist_head, (peasycap->purb_audio_head)) {
V_102 = F_36 ( V_104 , struct V_101 , V_103 ) ;
if ( V_102 && V_102 -> V_2 ) {
F_38 ( V_102 -> V_2 ) ;
V_107 ++ ;
}
}
F_5 ( 4 , L_83 , V_107 ) ;
return 0 ;
}
