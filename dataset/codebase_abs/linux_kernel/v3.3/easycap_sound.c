static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 , V_10 , V_11 , V_12 , V_13 ;
int V_14 ;
if ( ! V_2 -> V_15 ) {
F_2 ( L_1 ) ;
return - V_16 ;
}
if ( ! V_2 -> V_17 ) {
F_2 ( L_2 ) ;
return - V_16 ;
}
if ( V_2 -> V_18 ) {
F_3 ( 4 , L_3 ) ;
return 0 ;
}
F_3 ( 4 , L_4 ) ;
V_13 = F_4 ( V_2 -> V_17 ,
V_2 -> V_19 ,
V_2 -> V_20 ) ;
F_3 ( 8 , L_5 ,
V_2 -> V_19 ,
V_2 -> V_20 , V_13 ) ;
V_10 = 0 ;
V_11 = 0 ;
V_12 = 0 ;
F_5 (plist_head, peasycap->purb_audio_head) {
V_4 = F_6 ( V_8 , struct V_3 , V_7 ) ;
if ( V_4 && V_4 -> V_6 ) {
V_6 = V_4 -> V_6 ;
V_14 = V_4 -> V_14 ;
V_6 -> V_21 = 1 ;
V_6 -> V_22 = V_2 -> V_17 ;
V_6 -> V_23 = F_7 ( V_2 -> V_17 ,
V_2 -> V_24 ) ;
V_6 -> V_25 = V_26 ;
V_6 -> V_27 = V_2 -> V_28 [ V_14 ] . V_29 ;
V_6 -> V_30 = V_2 -> V_31 ;
V_6 -> V_32 = V_33 ;
V_6 -> V_34 = V_2 ;
V_6 -> V_35 = 0 ;
V_6 -> V_36 = V_2 -> V_37 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_37 ; V_9 ++ ) {
V_6 -> V_38 [ V_9 ] . V_39 = V_9 * V_2 -> V_40 ;
V_6 -> V_38 [ V_9 ] . V_41 = V_2 -> V_40 ;
}
V_13 = F_8 ( V_6 , V_42 ) ;
if ( V_13 ) {
V_10 ++ ;
F_2 ( L_6
L_7 ,
strerror ( V_13 ) , V_13 ) ;
} else {
V_12 ++ ;
}
} else {
V_10 ++ ;
}
}
if ( V_11 ) {
F_2 ( L_8 , V_11 ) ;
F_2 ( L_9 ) ;
V_2 -> V_43 = 1 ;
}
if ( V_10 )
F_9 ( V_2 ) ;
else
V_2 -> V_18 = V_12 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_13 ;
F_3 ( 4 , L_10 ) ;
if ( ! V_2 ) {
F_11 ( L_11 ) ;
return - V_16 ;
}
if ( ! V_2 -> V_17 ) {
F_2 ( L_2 ) ;
return - V_44 ;
}
F_3 ( 16 , L_12 , ( long int ) V_2 -> V_17 ) ;
V_13 = F_12 ( V_2 ) ;
F_3 ( 8 , L_13 , V_13 ) ;
if ( ! V_2 -> V_17 ) {
F_2 ( L_14 ) ;
return - V_44 ;
}
if ( ! V_2 -> V_17 ) {
F_2 ( L_14 ) ;
return - V_44 ;
}
V_13 = F_4 ( V_2 -> V_17 , V_2 -> V_19 ,
V_2 -> V_20 ) ;
F_3 ( 8 , L_5 , V_2 -> V_19 ,
V_2 -> V_20 , V_13 ) ;
V_13 = F_13 ( V_2 -> V_17 ) ;
F_3 ( 8 , L_15 , V_13 ) ;
V_2 -> V_43 = 0 ;
V_2 -> V_45 = 0 ;
F_1 ( V_2 ) ;
F_3 ( 4 , L_16 ) ;
return 0 ;
}
void V_33 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_50 , V_51 ;
int V_52 ;
T_1 * V_53 , * V_54 ;
T_2 V_55 ;
int V_56 , V_9 , V_57 , V_58 , V_13 ;
#ifdef F_14
int V_59 ;
T_2 V_60 , V_61 , V_62 ;
#endif
F_15 ( 16 , L_17 ) ;
if ( ! V_6 ) {
F_11 ( L_18 ) ;
return;
}
V_2 = V_6 -> V_34 ;
if ( ! V_2 ) {
F_11 ( L_19 ) ;
return;
}
V_58 = 0 ;
if ( V_2 -> V_45 ) {
F_3 ( 16 , L_20 ,
V_2 -> V_45 , V_2 -> V_18 ) ;
if ( V_2 -> V_18 )
goto V_63;
}
V_47 = V_2 -> V_64 ;
if ( ! V_47 )
goto V_63;
V_49 = V_47 -> V_65 ;
if ( ! V_49 )
goto V_63;
V_50 = ( int ) V_49 -> V_50 ;
if ( 0 == V_50 )
goto V_63;
V_51 = 4 * ( ( int ) V_49 -> V_66 ) ;
if ( 0 == V_51 )
goto V_63;
if ( V_6 -> V_67 ) {
if ( ( - V_68 == V_6 -> V_67 ) || ( - V_69 == V_6 -> V_67 ) ) {
F_3 ( 16 , L_21 ) ;
return;
}
F_2 ( L_22 ,
strerror ( V_6 -> V_67 ) , V_6 -> V_67 ) ;
goto V_63;
}
#ifdef F_14
V_60 = V_2 -> V_60 ;
#endif
for ( V_56 = 0 ; V_56 < V_6 -> V_36 ; V_56 ++ ) {
if ( V_6 -> V_38 [ V_56 ] . V_67 < 0 ) {
F_2 ( L_23 ,
strerror ( V_6 -> V_38 [ V_56 ] . V_67 ) ,
V_6 -> V_38 [ V_56 ] . V_67 ) ;
}
if ( V_6 -> V_38 [ V_56 ] . V_67 ) {
F_3 ( 12 , L_24
L_25 ,
V_6 -> V_38 [ V_56 ] . V_67 ) ;
continue;
}
V_57 = V_6 -> V_38 [ V_56 ] . V_70 ;
if ( V_57 == 0 ) {
V_2 -> V_71 ++ ;
continue;
}
if ( 0 > V_57 ) {
F_2 ( L_26 ) ;
return;
}
if ( V_2 -> V_71 ) {
F_3 ( 12 , L_27 ,
V_2 -> V_71 ) ;
V_2 -> V_71 = 0 ;
}
V_53 = ( T_1 * ) ( V_6 -> V_27 +
V_6 -> V_38 [ V_56 ] . V_39 ) ;
while ( V_57 ) {
V_58 = V_50 - V_2 -> V_72 ;
if ( 0 > V_58 ) {
F_2 ( L_28 ) ;
return;
}
if ( 0 == V_58 ) {
V_2 -> V_72 = 0 ;
V_2 -> V_73 = V_51 ;
F_3 ( 8 , L_29 ) ;
}
if ( ! V_2 -> V_74 ) {
if ( V_58 > V_57 )
V_58 = V_57 ;
memcpy ( V_49 -> V_75 + V_2 -> V_72 ,
V_53 , V_58 ) ;
V_53 += V_58 ;
V_57 -= V_58 ;
} else {
#ifdef F_14
if ( V_58 % 16 )
F_3 ( 8 , L_30
L_31 ) ;
if ( V_58 > ( 16 * V_57 ) )
V_58 = 16 * V_57 ;
V_54 = ( T_1 * ) ( V_49 -> V_75 + V_2 -> V_72 ) ;
for ( V_9 = 0 ; V_9 < ( V_58 / 16 ) ; V_9 ++ ) {
V_61 = ( ( int ) * V_53 ) - 128 ;
V_61 = 128 * V_61 ;
V_62 = ( V_61 - V_60 ) / 4 ;
V_55 = V_60 + V_62 ;
for ( V_59 = 0 ; V_59 < 4 ; V_59 ++ ) {
* V_54 = ( 0x00FF & V_55 ) ;
* ( V_54 + 1 ) = ( 0xFF00 & V_55 ) >> 8 ;
V_54 += 2 ;
* V_54 = ( 0x00FF & V_55 ) ;
* ( V_54 + 1 ) = ( 0xFF00 & V_55 ) >> 8 ;
V_54 += 2 ;
V_55 += V_62 ;
}
V_53 ++ ;
V_57 -- ;
V_60 = V_55 ;
}
#else
if ( V_58 > ( 2 * V_57 ) )
V_58 = 2 * V_57 ;
V_54 = ( T_1 * ) ( V_49 -> V_75 + V_2 -> V_72 ) ;
for ( V_9 = 0 ; V_9 < ( V_58 / 2 ) ; V_9 ++ ) {
V_55 = ( ( int ) * V_53 ) - 128 ;
V_55 = 128 * V_55 ;
* V_54 = ( 0x00FF & V_55 ) ;
* ( V_54 + 1 ) = ( 0xFF00 & V_55 ) >> 8 ;
V_53 ++ ;
V_54 += 2 ;
V_57 -- ;
}
#endif
}
V_2 -> V_72 += V_58 ;
if ( V_2 -> V_72 >= V_2 -> V_73 ) {
V_52 = V_2 -> V_72 / V_51 ;
if ( 0 > V_52 ) {
F_2 ( L_32 ) ;
return;
}
V_2 -> V_76 = ( V_52 - 1 ) * V_51 ;
V_2 -> V_73 = ( V_52 + 1 ) * V_51 ;
if ( V_50 < V_2 -> V_73 )
V_2 -> V_73 = V_51 ;
if ( 0 <= V_2 -> V_76 ) {
F_3 ( 8 , L_33
L_34 , V_52 ) ;
F_16 ( V_47 ) ;
}
}
}
#ifdef F_14
V_2 -> V_60 = V_60 ;
#endif
}
V_63:
if ( V_2 -> V_18 == 0 )
return;
V_13 = F_8 ( V_6 , V_77 ) ;
if ( V_13 ) {
if ( ( - V_44 != V_13 ) && ( - V_69 != V_13 ) ) {
F_2 ( L_35
L_36 ,
V_2 -> V_45 , strerror ( V_13 ) , V_13 ) ;
}
if ( 0 < V_2 -> V_18 )
V_2 -> V_18 -- ;
}
return;
}
static int F_17 ( struct V_46 * V_47 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_1 * V_2 ;
F_15 ( 4 , L_17 ) ;
if ( ! V_47 ) {
F_11 ( L_37 ) ;
return - V_16 ;
}
V_79 = V_47 -> V_82 ;
if ( ! V_79 ) {
F_11 ( L_38 ) ;
return - V_16 ;
}
V_81 = V_79 -> V_83 ;
if ( ! V_81 ) {
F_11 ( L_39 ) ;
return - V_16 ;
}
V_2 = V_81 -> V_84 ;
if ( ! V_2 ) {
F_11 ( L_40 ) ;
return - V_16 ;
}
if ( V_2 -> V_81 != V_81 ) {
F_2 ( L_41 ) ;
return - V_16 ;
}
if ( V_2 -> V_64 ) {
F_2 ( L_42 ) ;
return - V_16 ;
}
V_47 -> V_84 = V_2 ;
V_2 -> V_64 = V_47 ;
V_47 -> V_65 -> V_85 = V_2 -> V_86 ;
V_47 -> V_65 -> V_84 = V_2 ;
V_47 -> V_84 = V_2 ;
if ( 0 != F_10 ( V_2 ) ) {
F_3 ( 4 , L_43 ) ;
return - V_16 ;
}
F_3 ( 4 , L_44 ) ;
return 0 ;
}
static int F_18 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
F_15 ( 4 , L_17 ) ;
if ( ! V_47 ) {
F_11 ( L_37 ) ;
return - V_16 ;
}
V_2 = F_19 ( V_47 ) ;
if ( ! V_2 ) {
F_11 ( L_40 ) ;
return - V_16 ;
}
V_47 -> V_84 = NULL ;
V_2 -> V_64 = NULL ;
F_15 ( 4 , L_44 ) ;
return 0 ;
}
static int F_20 ( struct V_46 * V_47 , T_3 V_87 )
{
struct V_48 * V_49 ;
F_15 ( 4 , L_17 ) ;
if ( ! V_47 ) {
F_11 ( L_37 ) ;
return - V_16 ;
}
V_49 = V_47 -> V_65 ;
if ( ! V_49 ) {
F_11 ( L_45 ) ;
return - V_16 ;
}
if ( V_49 -> V_75 ) {
if ( V_49 -> V_50 > V_87 )
return 0 ;
F_21 ( V_49 -> V_75 ) ;
}
V_49 -> V_75 = F_22 ( V_87 ) ;
if ( ! V_49 -> V_75 )
return - V_88 ;
V_49 -> V_50 = V_87 ;
return 0 ;
}
static int F_23 ( struct V_46 * V_47 ,
struct V_89 * V_90 )
{
int V_13 ;
F_15 ( 4 , L_46 , ( F_24 ( V_90 ) ) ) ;
if ( ! V_47 ) {
F_11 ( L_37 ) ;
return - V_16 ;
}
V_13 = F_20 ( V_47 , F_24 ( V_90 ) ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
static int F_25 ( struct V_46 * V_47 )
{
struct V_48 * V_49 ;
F_15 ( 4 , L_17 ) ;
if ( ! V_47 ) {
F_11 ( L_37 ) ;
return - V_16 ;
}
V_49 = V_47 -> V_65 ;
if ( ! V_49 ) {
F_11 ( L_45 ) ;
return - V_16 ;
}
if ( V_49 -> V_75 ) {
F_15 ( 8 , L_47 , V_49 -> V_75 ) ;
F_21 ( V_49 -> V_75 ) ;
V_49 -> V_75 = NULL ;
} else
F_15 ( 8 , L_48 ) ;
return 0 ;
}
static int F_26 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
struct V_48 * V_49 ;
F_15 ( 4 , L_17 ) ;
if ( ! V_47 ) {
F_11 ( L_37 ) ;
return - V_16 ;
}
V_49 = V_47 -> V_65 ;
V_2 = F_19 ( V_47 ) ;
if ( ! V_2 ) {
F_11 ( L_40 ) ;
return - V_16 ;
}
F_3 ( 16 , L_49 , V_47 -> V_65 -> V_91 ) ;
F_3 ( 16 , L_50 , V_47 -> V_65 -> V_66 ) ;
F_3 ( 16 , L_51 , V_47 -> V_65 -> V_92 ) ;
F_3 ( 16 , L_52 , V_47 -> V_65 -> V_93 ) ;
F_3 ( 16 , L_53 , V_47 -> V_65 -> V_50 ) ;
F_3 ( 16 , L_54 , V_47 -> V_65 -> V_94 ) ;
F_3 ( 16 , L_55 , V_47 -> V_65 -> V_95 ) ;
F_3 ( 16 , L_56 , V_47 -> V_65 -> V_96 ) ;
F_3 ( 16 , L_57 , V_47 -> V_65 -> V_97 ) ;
F_3 ( 16 , L_58 , V_47 -> V_65 -> V_98 ) ;
F_3 ( 12 , L_59 , V_47 -> V_65 -> V_99 ) ;
F_3 ( 12 , L_60 ,
V_47 -> V_65 -> V_100 ) ;
if ( V_49 -> V_50 != 4 * ( ( int ) V_49 -> V_66 ) * ( ( int ) V_49 -> V_92 ) ) {
F_11 ( L_61 ) ;
return - V_69 ;
}
return 0 ;
}
static int F_27 ( struct V_46 * V_47 )
{
return 0 ;
}
static int F_28 ( struct V_46 * V_47 , int V_101 )
{
struct V_1 * V_2 ;
F_15 ( 4 , L_62 , V_101 , V_102 ,
V_103 ) ;
if ( ! V_47 ) {
F_11 ( L_37 ) ;
return - V_16 ;
}
V_2 = F_19 ( V_47 ) ;
if ( ! V_2 ) {
F_11 ( L_40 ) ;
return - V_16 ;
}
switch ( V_101 ) {
case V_102 : {
V_2 -> V_45 = 0 ;
break;
}
case V_103 : {
V_2 -> V_45 = 1 ;
break;
}
default:
return - V_104 ;
}
return 0 ;
}
static T_4 F_29 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
T_4 V_39 ;
F_15 ( 16 , L_17 ) ;
if ( ! V_47 ) {
F_11 ( L_37 ) ;
return - V_16 ;
}
V_2 = F_19 ( V_47 ) ;
if ( ! V_2 ) {
F_11 ( L_40 ) ;
return - V_16 ;
}
if ( ( 0 != V_2 -> V_43 ) || ( 0 != V_2 -> V_45 ) ) {
F_3 ( 8 , L_63
L_64 ,
V_2 -> V_45 , V_2 -> V_43 ) ;
return - V_105 ;
}
if ( 0 > V_2 -> V_76 ) {
F_3 ( 8 , L_65 ) ;
return - V_106 ;
}
V_39 = ( ( T_4 ) V_2 -> V_76 ) / 4 ;
F_3 ( 8 , L_66 , ( int ) V_47 -> V_65 -> V_99 ) ;
F_3 ( 8 , L_67 ,
( int ) V_47 -> V_65 -> V_100 ) ;
F_3 ( 8 , L_68 ,
( int ) V_39 , V_2 -> V_76 , V_2 -> V_73 ) ;
return V_39 ;
}
static struct V_107 *
F_30 ( struct V_46 * V_47 , unsigned long V_39 )
{
return F_31 ( V_47 -> V_65 -> V_75 + V_39 ) ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_13 ;
struct V_80 * V_81 ;
struct V_78 * V_79 ;
if ( ! V_2 ) {
F_11 ( L_19 ) ;
return - V_44 ;
}
if ( 0 > V_2 -> V_108 ) {
F_11 ( L_69 ) ;
return - V_44 ;
}
V_2 -> V_86 = V_86 ;
if ( V_2 -> V_74 ) {
V_2 -> V_86 . V_109 = V_110 ;
V_2 -> V_86 . V_111 = 32000 ;
V_2 -> V_86 . V_112 = 32000 ;
} else {
V_2 -> V_86 . V_109 = V_113 ;
V_2 -> V_86 . V_111 = 48000 ;
V_2 -> V_86 . V_112 = 48000 ;
}
if ( 0 != F_33 ( V_114 , L_70 ,
V_115 , 0 , & V_81 ) ) {
F_11 ( L_71 ) ;
return - V_16 ;
}
sprintf ( & V_81 -> V_116 [ 0 ] , L_72 , V_2 -> V_108 ) ;
strcpy ( & V_81 -> V_117 [ 0 ] , V_118 ) ;
strcpy ( & V_81 -> V_119 [ 0 ] , L_70 ) ;
sprintf ( & V_81 -> V_120 [ 0 ] , L_73 , & V_81 -> V_119 [ 0 ] ) ;
V_81 -> V_22 = & V_2 -> V_17 -> V_22 ;
V_81 -> V_84 = V_2 ;
V_2 -> V_81 = V_81 ;
V_13 = F_34 ( V_81 , L_74 , 0 , 0 , 1 , & V_79 ) ;
if ( V_13 ) {
F_2 ( L_75 ) ;
F_35 ( V_81 ) ;
return - V_16 ;
}
F_36 ( V_79 , V_121 ,
& V_122 ) ;
V_79 -> V_123 = 0 ;
strcpy ( & V_79 -> V_124 [ 0 ] , & V_81 -> V_116 [ 0 ] ) ;
V_79 -> V_84 = V_2 ;
V_2 -> V_79 = V_79 ;
V_2 -> V_64 = NULL ;
V_13 = F_37 ( V_81 ) ;
if ( V_13 ) {
F_2 ( L_76 ) ;
F_35 ( V_81 ) ;
return - V_16 ;
}
F_2 ( L_77 , & V_81 -> V_116 [ 0 ] ) ;
return 0 ;
}
