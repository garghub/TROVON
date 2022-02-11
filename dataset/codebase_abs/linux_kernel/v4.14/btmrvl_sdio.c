static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_2 ( L_1 , V_8 ) ;
V_6 -> V_9 = true ;
F_3 ( V_1 ) ;
F_4 ( & V_4 -> V_10 -> V_11 , 0 ) ;
F_5 () ;
return V_12 ;
}
static int F_6 ( struct V_13 * V_11 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_14 ;
if ( ! V_11 -> V_15 ||
! F_7 ( V_16 , V_11 -> V_15 ) ) {
F_8 ( L_2 ) ;
return - 1 ;
}
V_4 -> V_17 = V_11 -> V_15 ;
V_4 -> V_7 = F_9 ( V_11 , sizeof( * V_4 -> V_7 ) ,
V_18 ) ;
V_6 = V_4 -> V_7 ;
if ( V_6 && V_4 -> V_17 ) {
V_6 -> V_19 = F_10 ( V_4 -> V_17 , 0 ) ;
if ( ! V_6 -> V_19 ) {
F_11 ( V_11 , L_3 ) ;
V_6 -> V_19 = - 1 ;
} else {
V_14 = F_12 ( V_11 , V_6 -> V_19 ,
F_1 ,
0 , L_4 , V_4 ) ;
if ( V_14 ) {
F_11 ( V_11 ,
L_5 ,
V_6 -> V_19 , V_14 ) ;
}
F_13 ( V_6 -> V_19 ) ;
}
}
return 0 ;
}
static int F_14 ( struct V_3 * V_4 )
{
T_2 V_20 ;
int V_14 ;
V_20 = F_15 ( V_4 -> V_10 , V_4 -> V_20 -> V_21 , & V_14 ) ;
if ( ! V_14 )
V_4 -> V_22 = V_20 ;
return V_14 ;
}
static int F_16 ( struct V_3 * V_4 , T_3 * V_23 )
{
T_2 V_24 , V_25 ;
int V_14 ;
* V_23 = 0 ;
V_24 = F_15 ( V_4 -> V_10 , V_4 -> V_20 -> V_26 , & V_14 ) ;
if ( V_14 )
return - V_27 ;
V_25 = F_15 ( V_4 -> V_10 , V_4 -> V_20 -> V_28 , & V_14 ) ;
if ( V_14 )
return - V_27 ;
* V_23 = ( ( ( T_3 ) V_25 ) << 8 ) | V_24 ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 , T_3 * V_23 )
{
T_2 V_20 ;
int V_14 ;
V_20 = F_15 ( V_4 -> V_10 , V_4 -> V_20 -> V_29 , & V_14 ) ;
if ( ! V_14 )
* V_23 = ( T_3 ) V_20 << V_4 -> V_22 ;
return V_14 ;
}
static int F_18 ( struct V_3 * V_4 ,
T_2 V_30 )
{
int V_14 ;
F_19 ( V_4 -> V_10 , V_30 , V_4 -> V_20 -> V_31 , & V_14 ) ;
if ( V_14 ) {
F_20 ( L_6 ) ;
V_14 = - V_27 ;
}
return V_14 ;
}
static int F_21 ( struct V_3 * V_4 ,
T_2 V_30 )
{
T_2 V_31 ;
int V_14 ;
V_31 = F_15 ( V_4 -> V_10 , V_4 -> V_20 -> V_31 , & V_14 ) ;
if ( V_14 )
return - V_27 ;
V_31 &= ~ V_30 ;
F_19 ( V_4 -> V_10 , V_31 , V_4 -> V_20 -> V_31 , & V_14 ) ;
if ( V_14 < 0 ) {
F_20 ( L_7 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_22 ( struct V_3 * V_4 , T_2 V_32 )
{
unsigned int V_33 ;
T_2 V_34 ;
int V_14 ;
for ( V_33 = 0 ; V_33 < V_35 * 1000 ; V_33 ++ ) {
V_34 = F_15 ( V_4 -> V_10 , V_4 -> V_20 -> V_36 , & V_14 ) ;
if ( V_14 )
goto V_37;
if ( ( V_34 & V_32 ) == V_32 )
return V_14 ;
F_23 ( 1 ) ;
}
V_14 = - V_38 ;
V_37:
F_20 ( L_8 , V_14 ) ;
return V_14 ;
}
static int F_24 ( struct V_3 * V_4 ,
int V_39 )
{
T_3 V_40 ;
int V_33 , V_14 ;
for ( V_33 = 0 ; V_33 < V_39 ; V_33 ++ ) {
F_25 ( V_4 -> V_10 ) ;
V_14 = F_16 ( V_4 , & V_40 ) ;
F_26 ( V_4 -> V_10 ) ;
if ( V_14 < 0 )
continue;
if ( V_40 == V_41 )
return 0 ;
F_27 ( 100 ) ;
}
return - V_38 ;
}
static int F_28 ( struct V_3 * V_4 )
{
const struct V_42 * V_43 = NULL ;
const T_2 * V_44 = NULL ;
int V_14 ;
void * V_45 = NULL ;
int V_46 , V_47 , V_48 ;
T_2 * V_49 ;
T_4 V_50 ;
V_14 = F_29 ( & V_43 , V_4 -> V_44 ,
& V_4 -> V_10 -> V_11 ) ;
if ( ( V_14 < 0 ) || ! V_43 ) {
F_20 ( L_9 ,
V_14 ) ;
V_14 = - V_51 ;
goto V_52;
}
V_44 = V_43 -> V_53 ;
V_48 = V_43 -> V_54 ;
F_30 ( L_10 ,
V_48 , V_55 ) ;
V_46 = F_31 ( V_56 , V_57 ) ;
V_45 = F_32 ( V_46 , V_18 ) ;
if ( ! V_45 ) {
F_20 ( L_11
L_12 ) ;
V_14 = - V_58 ;
goto V_52;
}
V_49 = ( T_2 * ) F_33 ( V_45 , V_57 ) ;
V_50 = ( V_59 * V_55 )
- V_60 ;
V_47 = 0 ;
do {
V_14 = F_22 ( V_4 ,
V_61 | V_62 ) ;
if ( V_14 < 0 ) {
F_20 ( L_13 ,
V_47 ) ;
goto V_52;
}
if ( V_47 >= V_48 )
break;
if ( V_48 - V_47 < V_50 )
V_50 = V_48 - V_47 ;
V_49 [ 0 ] = ( ( V_50 & 0x000000ff ) >> 0 ) ;
V_49 [ 1 ] = ( ( V_50 & 0x0000ff00 ) >> 8 ) ;
V_49 [ 2 ] = ( ( V_50 & 0x00ff0000 ) >> 16 ) ;
V_49 [ 3 ] = ( ( V_50 & 0xff000000 ) >> 24 ) ;
memcpy ( & V_49 [ V_60 ] , & V_44 [ V_47 ] ,
V_50 ) ;
V_14 = F_34 ( V_4 -> V_10 , V_4 -> V_63 , V_49 ,
V_59 * V_55 ) ;
if ( V_14 < 0 ) {
F_20 ( L_14 ,
V_47 ) ;
goto V_52;
}
V_47 += V_50 ;
} while ( true );
F_30 ( L_15 ) ;
memset ( V_49 , 0x0 , V_55 ) ;
V_14 = F_34 ( V_4 -> V_10 , V_4 -> V_63 , V_49 ,
V_55 ) ;
if ( V_14 < 0 ) {
F_20 ( L_16 ) ;
goto V_52;
}
V_14 = 0 ;
V_52:
F_35 ( V_45 ) ;
F_36 ( V_43 ) ;
return V_14 ;
}
static int F_37 ( struct V_3 * V_4 )
{
const struct V_42 * V_64 = NULL ;
const T_2 * V_42 = NULL ;
int V_65 , V_66 , V_14 ;
unsigned int V_33 , V_67 ;
T_2 V_68 , V_69 ;
void * V_70 = NULL ;
T_2 * V_71 ;
T_3 V_72 , V_73 = V_4 -> V_74 ;
int V_75 = 0 , V_76 = 0 , V_77 = 0 ;
V_14 = F_29 ( & V_64 , V_4 -> V_42 ,
& V_4 -> V_10 -> V_11 ) ;
if ( ( V_14 < 0 ) || ! V_64 ) {
F_20 ( L_17 ,
V_14 ) ;
V_14 = - V_51 ;
goto V_52;
}
V_42 = V_64 -> V_53 ;
V_65 = V_64 -> V_54 ;
F_30 ( L_18 , V_65 ) ;
V_66 = F_31 ( V_56 , V_57 ) ;
V_70 = F_32 ( V_66 , V_18 ) ;
if ( ! V_70 ) {
F_20 ( L_19
L_12 ) ;
V_14 = - V_58 ;
goto V_52;
}
V_71 = ( T_2 * ) F_33 ( V_70 , V_57 ) ;
V_67 = 0 ;
do {
V_14 = F_22 ( V_4 ,
V_61 | V_62 ) ;
if ( V_14 < 0 ) {
F_20 ( L_20
L_21 , V_67 ) ;
goto V_52;
}
if ( V_67 >= V_65 )
break;
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
V_68 = F_15 ( V_4 -> V_10 ,
V_4 -> V_20 -> V_78 , & V_14 ) ;
if ( V_14 ) {
F_20 ( L_22
L_23
L_12 ,
V_68 , V_68 ) ;
V_14 = - V_27 ;
goto V_52;
}
V_69 = F_15 ( V_4 -> V_10 ,
V_4 -> V_20 -> V_79 , & V_14 ) ;
if ( V_14 ) {
F_20 ( L_24
L_25
L_12 ,
V_69 , V_69 ) ;
V_14 = - V_27 ;
goto V_52;
}
V_72 = ( ( ( T_3 ) V_69 ) << 8 ) | V_68 ;
if ( V_72 )
break;
F_23 ( 10 ) ;
}
if ( ! V_72 )
break;
else if ( V_72 > V_56 ) {
F_20 ( L_26 ,
V_67 , V_72 ) ;
V_14 = - V_80 ;
goto V_52;
}
V_75 = V_72 ;
if ( V_72 & F_38 ( 0 ) ) {
V_77 ++ ;
if ( V_77 > V_81 ) {
F_20 ( L_27
L_28 , V_67 ) ;
V_14 = - V_27 ;
goto V_52;
}
F_20 ( L_29
L_30 , V_72 , V_75 ) ;
V_72 &= ~ F_38 ( 0 ) ;
V_75 = 0 ;
} else {
V_77 = 0 ;
if ( V_65 - V_67 < V_75 )
V_75 = V_65 - V_67 ;
V_76 = F_39 ( V_75 , V_73 ) ;
memcpy ( V_71 , & V_42 [ V_67 ] , V_75 ) ;
}
V_14 = F_34 ( V_4 -> V_10 , V_4 -> V_63 , V_71 ,
V_76 * V_73 ) ;
if ( V_14 < 0 ) {
F_20 ( L_31 ,
V_77 , V_67 ) ;
F_19 ( V_4 -> V_10 , V_82 ,
V_4 -> V_20 -> V_6 , & V_14 ) ;
if ( V_14 )
F_20 ( L_32 ) ;
}
V_67 += V_75 ;
} while ( true );
F_40 ( L_33 , V_67 ) ;
V_14 = 0 ;
V_52:
F_35 ( V_70 ) ;
F_36 ( V_64 ) ;
return V_14 ;
}
static int F_41 ( struct V_83 * V_2 )
{
T_3 V_84 = 0 ;
int V_14 , V_85 , V_86 ;
struct V_87 * V_88 = NULL ;
T_4 type ;
T_2 * V_89 = NULL ;
struct V_90 * V_91 = V_2 -> V_92 . V_93 ;
struct V_3 * V_4 = V_2 -> V_92 . V_4 ;
if ( ! V_4 || ! V_4 -> V_10 ) {
F_20 ( L_34 ) ;
V_14 = - V_80 ;
goto exit;
}
V_14 = F_17 ( V_4 , & V_84 ) ;
if ( V_14 < 0 ) {
F_20 ( L_35 ) ;
V_14 = - V_27 ;
goto exit;
}
V_86 = V_55 ;
V_85 = F_39 ( V_84 , V_86 ) ;
if ( V_84 <= V_60
|| ( V_85 * V_86 ) > V_94 ) {
F_20 ( L_36 , V_84 ) ;
V_14 = - V_80 ;
goto exit;
}
V_88 = F_42 ( V_85 * V_86 + V_57 , V_95 ) ;
if ( ! V_88 ) {
F_20 ( L_37 ) ;
V_14 = - V_58 ;
goto exit;
}
if ( ( unsigned long ) V_88 -> V_53 & ( V_57 - 1 ) ) {
F_43 ( V_88 , ( unsigned long ) V_88 -> V_53 &
( V_57 - 1 ) ) ;
F_44 ( V_88 , ( unsigned long ) V_88 -> V_53 &
( V_57 - 1 ) ) ;
}
V_89 = V_88 -> V_53 ;
V_14 = F_45 ( V_4 -> V_10 , V_89 , V_4 -> V_63 ,
V_85 * V_86 ) ;
if ( V_14 < 0 ) {
F_20 ( L_38 , V_14 ) ;
V_14 = - V_27 ;
goto exit;
}
V_84 = V_89 [ 0 ] ;
V_84 |= V_89 [ 1 ] << 8 ;
V_84 |= V_89 [ 2 ] << 16 ;
if ( V_84 > V_86 * V_85 ) {
F_20 ( L_39 ,
V_84 , V_86 * V_85 ) ;
V_14 = - V_27 ;
goto exit;
}
type = V_89 [ 3 ] ;
switch ( type ) {
case V_96 :
case V_97 :
case V_98 :
F_46 ( V_88 ) = type ;
F_43 ( V_88 , V_84 ) ;
F_44 ( V_88 , V_60 ) ;
if ( type == V_98 ) {
if ( F_47 ( V_2 , V_88 ) )
F_48 ( V_91 , V_88 ) ;
} else {
F_48 ( V_91 , V_88 ) ;
}
V_91 -> V_99 . V_100 += V_84 ;
break;
case V_101 :
F_46 ( V_88 ) = V_102 ;
F_43 ( V_88 , V_84 ) ;
F_44 ( V_88 , V_60 ) ;
if ( F_49 ( V_2 , V_88 ) )
F_48 ( V_91 , V_88 ) ;
V_91 -> V_99 . V_100 += V_84 ;
break;
default:
F_20 ( L_40 , type ) ;
F_20 ( L_41 , V_86 * V_85 , V_89 ) ;
F_50 ( V_88 ) ;
V_88 = NULL ;
break;
}
exit:
if ( V_14 ) {
V_91 -> V_99 . V_103 ++ ;
F_50 ( V_88 ) ;
}
return V_14 ;
}
static int F_51 ( struct V_83 * V_2 )
{
T_5 V_104 ;
T_2 V_105 ;
struct V_3 * V_4 = V_2 -> V_92 . V_4 ;
F_52 ( & V_2 -> V_106 , V_104 ) ;
V_105 = V_107 ;
V_107 = 0 ;
F_53 ( & V_2 -> V_106 , V_104 ) ;
F_25 ( V_4 -> V_10 ) ;
if ( V_105 & V_108 ) {
if ( V_2 -> V_92 . V_109 )
F_30 ( L_42
L_43 , V_105 ) ;
else
V_2 -> V_92 . V_109 = true ;
}
if ( V_105 & V_110 )
F_41 ( V_2 ) ;
F_26 ( V_4 -> V_10 ) ;
return 0 ;
}
static int F_54 ( struct V_3 * V_4 , T_2 * V_105 )
{
struct V_111 * V_112 = V_4 -> V_2 -> V_112 ;
int V_14 ;
V_14 = F_45 ( V_4 -> V_10 , V_112 -> V_113 , 0 , V_55 ) ;
if ( V_14 ) {
F_20 ( L_44 , V_14 ) ;
return V_14 ;
}
* V_105 = V_112 -> V_113 [ V_4 -> V_20 -> V_114 ] ;
F_30 ( L_45 , V_4 -> V_20 -> V_114 , * V_105 ) ;
return 0 ;
}
static int F_55 ( struct V_3 * V_4 , T_2 * V_105 )
{
int V_14 ;
* V_105 = F_15 ( V_4 -> V_10 , V_4 -> V_20 -> V_114 , & V_14 ) ;
if ( V_14 ) {
F_20 ( L_46 , V_14 ) ;
return V_14 ;
}
if ( * V_105 ) {
F_30 ( L_47 , * V_105 ) ;
F_19 ( V_4 -> V_10 , ~ ( * V_105 ) & ( V_108 |
V_110 ) ,
V_4 -> V_20 -> V_114 , & V_14 ) ;
if ( V_14 ) {
F_20 ( L_48 , V_14 ) ;
return V_14 ;
}
}
return 0 ;
}
static void F_56 ( struct V_115 * V_10 )
{
struct V_83 * V_2 ;
struct V_3 * V_4 ;
T_5 V_104 ;
T_2 V_105 = 0 ;
int V_14 ;
V_4 = F_57 ( V_10 ) ;
if ( ! V_4 || ! V_4 -> V_2 ) {
F_20 ( L_49 ,
V_10 , V_4 ) ;
return;
}
V_2 = V_4 -> V_2 ;
if ( V_2 -> V_116 )
return;
if ( V_4 -> V_20 -> V_117 )
V_14 = F_54 ( V_4 , & V_105 ) ;
else
V_14 = F_55 ( V_4 , & V_105 ) ;
if ( V_14 )
return;
F_52 ( & V_2 -> V_106 , V_104 ) ;
V_107 |= V_105 ;
F_53 ( & V_2 -> V_106 , V_104 ) ;
F_58 ( V_2 ) ;
}
static int F_59 ( struct V_3 * V_4 )
{
struct V_115 * V_10 ;
T_2 V_20 ;
int V_14 = 0 ;
if ( ! V_4 || ! V_4 -> V_10 ) {
F_20 ( L_50 ) ;
V_14 = - V_80 ;
goto V_37;
}
V_10 = V_4 -> V_10 ;
F_25 ( V_10 ) ;
V_14 = F_60 ( V_10 ) ;
if ( V_14 ) {
F_20 ( L_51 , V_14 ) ;
V_14 = - V_27 ;
goto V_118;
}
V_14 = F_61 ( V_10 , F_56 ) ;
if ( V_14 ) {
F_20 ( L_52 , V_14 ) ;
V_14 = - V_27 ;
goto V_119;
}
V_14 = F_62 ( V_4 -> V_10 , V_55 ) ;
if ( V_14 ) {
F_20 ( L_53 ) ;
V_14 = - V_27 ;
goto V_120;
}
V_20 = F_15 ( V_10 , V_4 -> V_20 -> V_121 , & V_14 ) ;
if ( V_14 < 0 ) {
V_14 = - V_27 ;
goto V_120;
}
V_4 -> V_63 = V_20 ;
V_20 = F_15 ( V_10 , V_4 -> V_20 -> V_122 , & V_14 ) ;
if ( V_14 < 0 ) {
V_14 = - V_27 ;
goto V_120;
}
V_4 -> V_63 |= ( V_20 << 8 ) ;
V_20 = F_15 ( V_10 , V_4 -> V_20 -> V_123 , & V_14 ) ;
if ( V_14 < 0 ) {
V_14 = - V_27 ;
goto V_120;
}
V_4 -> V_63 |= ( V_20 << 16 ) ;
F_30 ( L_54 , V_10 -> V_124 , V_4 -> V_63 ) ;
if ( V_4 -> V_20 -> V_117 ) {
V_20 = F_15 ( V_10 , V_4 -> V_20 -> V_125 , & V_14 ) ;
if ( V_14 < 0 ) {
V_14 = - V_27 ;
goto V_120;
}
F_19 ( V_10 , V_20 | 0x3f , V_4 -> V_20 -> V_125 , & V_14 ) ;
if ( V_14 < 0 ) {
V_14 = - V_27 ;
goto V_120;
}
V_20 = F_15 ( V_10 , V_4 -> V_20 -> V_126 , & V_14 ) ;
if ( V_14 < 0 ) {
V_14 = - V_27 ;
goto V_120;
}
F_19 ( V_10 , V_20 | 0x10 , V_4 -> V_20 -> V_126 , & V_14 ) ;
if ( V_14 < 0 ) {
V_14 = - V_27 ;
goto V_120;
}
}
F_63 ( V_10 , V_4 ) ;
F_26 ( V_10 ) ;
return 0 ;
V_120:
F_64 ( V_10 ) ;
V_119:
F_65 ( V_10 ) ;
V_118:
F_26 ( V_10 ) ;
V_37:
return V_14 ;
}
static int F_66 ( struct V_3 * V_4 )
{
if ( V_4 && V_4 -> V_10 ) {
F_25 ( V_4 -> V_10 ) ;
F_64 ( V_4 -> V_10 ) ;
F_65 ( V_4 -> V_10 ) ;
F_26 ( V_4 -> V_10 ) ;
F_63 ( V_4 -> V_10 , NULL ) ;
}
return 0 ;
}
static int F_67 ( struct V_3 * V_4 )
{
int V_14 ;
if ( ! V_4 || ! V_4 -> V_10 )
return - V_80 ;
F_25 ( V_4 -> V_10 ) ;
V_14 = F_18 ( V_4 , V_127 ) ;
F_14 ( V_4 ) ;
F_26 ( V_4 -> V_10 ) ;
return V_14 ;
}
static int F_68 ( struct V_3 * V_4 )
{
int V_14 ;
if ( ! V_4 || ! V_4 -> V_10 )
return - V_80 ;
F_25 ( V_4 -> V_10 ) ;
V_14 = F_21 ( V_4 , V_128 ) ;
F_26 ( V_4 -> V_10 ) ;
return V_14 ;
}
static int F_69 ( struct V_83 * V_2 ,
T_2 * V_89 , T_3 V_129 )
{
struct V_3 * V_4 = V_2 -> V_92 . V_4 ;
int V_14 = 0 ;
int V_86 ;
int V_130 = 0 ;
T_2 * V_131 = NULL ;
void * V_132 = NULL ;
int V_133 ;
if ( ! V_4 || ! V_4 -> V_10 ) {
F_20 ( L_34 ) ;
return - V_80 ;
}
V_86 = F_39 ( V_129 , V_55 ) * V_55 ;
V_131 = V_89 ;
if ( ( unsigned long ) V_89 & ( V_57 - 1 ) ||
V_129 < V_86 ) {
V_133 = F_31 ( V_86 , V_57 ) +
V_57 ;
V_132 = F_32 ( V_133 , V_18 ) ;
if ( ! V_132 )
return - V_58 ;
V_131 = ( T_2 * ) F_33 ( V_132 , V_57 ) ;
memcpy ( V_131 , V_89 , V_129 ) ;
}
F_25 ( V_4 -> V_10 ) ;
do {
V_14 = F_34 ( V_4 -> V_10 , V_4 -> V_63 , V_131 ,
V_86 ) ;
if ( V_14 < 0 ) {
V_130 ++ ;
F_20 ( L_55 , V_130 , V_14 ) ;
F_20 ( L_41 , V_129 , V_89 ) ;
V_14 = - V_27 ;
if ( V_130 > V_81 )
goto exit;
}
} while ( V_14 );
V_2 -> V_92 . V_109 = false ;
exit:
F_26 ( V_4 -> V_10 ) ;
F_35 ( V_132 ) ;
return V_14 ;
}
static int F_70 ( struct V_3 * V_4 )
{
int V_14 ;
T_2 V_24 ;
int V_39 = V_35 ;
if ( ! V_4 || ! V_4 -> V_10 ) {
F_20 ( L_34 ) ;
return - V_80 ;
}
if ( ! F_24 ( V_4 , 1 ) ) {
F_30 ( L_56 ) ;
return 0 ;
}
F_25 ( V_4 -> V_10 ) ;
V_24 = F_15 ( V_4 -> V_10 , V_4 -> V_20 -> V_26 , & V_14 ) ;
if ( V_14 ) {
F_20 ( L_57 ) ;
V_14 = - V_27 ;
goto V_52;
}
if ( V_24 ) {
F_30 ( L_58 , V_24 ) ;
V_39 *= 10 ;
} else {
if ( V_4 -> V_44 ) {
V_14 = F_28 ( V_4 ) ;
if ( V_14 ) {
F_20 ( L_59 ) ;
V_14 = - V_27 ;
goto V_52;
}
}
if ( F_37 ( V_4 ) ) {
F_20 ( L_60 ) ;
V_14 = - V_27 ;
goto V_52;
}
}
if ( F_24 ( V_4 , V_39 ) ) {
F_20 ( L_61 ) ;
V_14 = - V_38 ;
goto V_52;
}
F_26 ( V_4 -> V_10 ) ;
return 0 ;
V_52:
F_26 ( V_4 -> V_10 ) ;
return V_14 ;
}
static int F_71 ( struct V_83 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_92 . V_4 ;
int V_14 = 0 ;
if ( ! V_4 || ! V_4 -> V_10 ) {
F_20 ( L_34 ) ;
return - V_80 ;
}
F_25 ( V_4 -> V_10 ) ;
F_19 ( V_4 -> V_10 , V_134 , V_4 -> V_20 -> V_6 , & V_14 ) ;
F_26 ( V_4 -> V_10 ) ;
F_30 ( L_62 ) ;
return V_14 ;
}
static void F_72 ( struct V_83 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_92 . V_4 ;
int V_14 = 0 ;
unsigned int V_20 , V_135 , V_136 ;
char V_131 [ 256 ] , * V_137 ;
T_2 V_138 , V_10 , V_53 ;
int V_139 = 2 ;
F_71 ( V_2 ) ;
F_25 ( V_4 -> V_10 ) ;
for ( V_138 = 0 ; V_138 < V_139 ; V_138 ++ ) {
memset ( V_131 , 0 , sizeof( V_131 ) ) ;
V_137 = V_131 ;
if ( V_138 == 0 ) {
V_10 = V_138 ;
V_135 = 0 ;
V_136 = 9 ;
} else {
V_10 = 2 ;
V_135 = 0 ;
V_136 = 0x09 ;
}
V_137 += sprintf ( V_137 , L_63 ,
V_10 , V_135 , V_136 ) ;
for ( V_20 = V_135 ; V_20 <= V_136 ; V_20 ++ ) {
if ( V_10 == 0 )
V_53 = F_73 ( V_4 -> V_10 , V_20 , & V_14 ) ;
else
V_53 = F_15 ( V_4 -> V_10 , V_20 , & V_14 ) ;
if ( ! V_14 ) {
V_137 += sprintf ( V_137 , L_64 , V_53 ) ;
} else {
V_137 += sprintf ( V_137 , L_65 ) ;
break;
}
}
F_40 ( L_66 , V_131 ) ;
}
F_26 ( V_4 -> V_10 ) ;
}
static enum
V_140 F_74 ( struct V_83 * V_2 ,
T_2 V_141 )
{
struct V_3 * V_4 = V_2 -> V_92 . V_4 ;
int V_14 , V_33 ;
T_2 V_142 = 0 ;
F_19 ( V_4 -> V_10 , V_143 , V_4 -> V_20 -> V_144 ,
& V_14 ) ;
if ( V_14 ) {
F_20 ( L_67 ) ;
return V_145 ;
}
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
V_142 = F_15 ( V_4 -> V_10 , V_4 -> V_20 -> V_144 ,
& V_14 ) ;
if ( V_14 ) {
F_20 ( L_68 ) ;
return V_145 ;
}
if ( V_142 == V_146 )
break;
if ( V_141 && V_142 == V_141 )
return V_147 ;
if ( V_142 != V_143 ) {
F_40 ( L_69 ) ;
F_19 ( V_4 -> V_10 , V_143 ,
V_4 -> V_20 -> V_144 , & V_14 ) ;
if ( V_14 ) {
F_20 ( L_67 ) ;
return V_145 ;
}
}
F_75 ( 100 , 200 ) ;
}
if ( V_142 == V_143 ) {
F_20 ( L_70 ) ;
return V_145 ;
}
return V_148 ;
}
static void F_76 ( struct V_83 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_92 . V_4 ;
int V_14 = 0 ;
unsigned int V_20 , V_135 , V_136 ;
enum V_140 V_99 ;
T_2 * V_149 , * V_150 , * V_151 , * V_152 ;
T_2 V_153 = 0 , V_154 , V_130 , V_155 , V_141 = 0 ;
T_4 V_156 , V_157 = 0 ;
F_72 ( V_2 ) ;
if ( ! V_4 -> V_158 ) {
F_20 ( L_71 ) ;
return;
}
for ( V_154 = 0 ; V_154 < F_77 ( V_159 ) ; V_154 ++ ) {
struct V_160 * V_161 = & V_159 [ V_154 ] ;
if ( V_161 -> V_162 ) {
F_78 ( V_161 -> V_162 ) ;
V_161 -> V_162 = NULL ;
}
V_161 -> V_163 = 0 ;
}
F_71 ( V_2 ) ;
F_25 ( V_4 -> V_10 ) ;
F_40 ( L_72 ) ;
V_99 = F_74 ( V_2 , V_141 ) ;
if ( V_99 == V_145 )
goto V_52;
V_20 = V_4 -> V_20 -> V_164 ;
V_153 = F_15 ( V_4 -> V_10 , V_20 , & V_14 ) ;
if ( V_14 ) {
F_20 ( L_73 ) ;
goto V_52;
}
for ( V_154 = 0 ; V_154 < V_153 ; V_154 ++ ) {
struct V_160 * V_161 = & V_159 [ V_154 ] ;
V_99 = F_74 ( V_2 , V_141 ) ;
if ( V_99 == V_145 )
goto V_52;
V_156 = 0 ;
V_20 = V_4 -> V_20 -> V_164 ;
for ( V_130 = 0 ; V_130 < 4 ; V_130 ++ ) {
V_155 = F_15 ( V_4 -> V_10 , V_20 , & V_14 ) ;
if ( V_14 ) {
F_20 ( L_68 ) ;
goto V_52;
}
V_156 |= ( V_155 << V_130 * 8 ) ;
V_20 ++ ;
}
if ( V_156 == 0 ) {
F_40 ( L_74 ) ;
F_19 ( V_4 -> V_10 , V_165 ,
V_4 -> V_20 -> V_144 , & V_14 ) ;
if ( V_14 ) {
F_20 ( L_75 ) ;
goto V_52;
}
break;
}
F_40 ( L_76 , V_161 -> V_166 , V_156 ) ;
V_161 -> V_162 = F_79 ( V_156 + 1 ) ;
V_161 -> V_163 = V_156 ;
if ( ! V_161 -> V_162 ) {
F_20 ( L_77 , V_161 -> V_166 ) ;
goto V_52;
}
V_157 += ( strlen ( L_78 ) +
strlen ( V_161 -> V_166 ) +
strlen ( L_79 ) +
( V_156 + 1 ) +
strlen ( L_80 ) ) ;
V_149 = V_161 -> V_162 ;
V_150 = V_149 + V_156 ;
V_141 = V_161 -> V_167 ;
F_40 ( L_81 ,
V_161 -> V_166 ) ;
do {
V_99 = F_74 ( V_2 , V_141 ) ;
if ( V_99 == V_145 )
goto V_52;
V_135 = V_4 -> V_20 -> V_164 ;
V_136 = V_4 -> V_20 -> V_168 ;
for ( V_20 = V_135 ; V_20 <= V_136 ; V_20 ++ ) {
* V_149 = F_15 ( V_4 -> V_10 , V_20 , & V_14 ) ;
if ( V_14 ) {
F_20 ( L_68 ) ;
goto V_52;
}
if ( V_149 < V_150 )
V_149 ++ ;
else
F_20 ( L_82 ) ;
}
if ( V_99 != V_147 ) {
continue;
} else {
F_40 ( L_83 ,
V_161 -> V_166 ,
V_149 - V_161 -> V_162 ) ;
break;
}
} while ( 1 );
}
F_40 ( L_84 ) ;
V_52:
F_26 ( V_4 -> V_10 ) ;
if ( V_157 == 0 )
return;
V_151 = F_79 ( V_157 + 1 ) ;
if ( ! V_151 ) {
F_20 ( L_85 ) ;
return;
}
V_152 = V_151 ;
F_40 ( L_86 ) ;
for ( V_154 = 0 ; V_154 < V_153 ; V_154 ++ ) {
struct V_160 * V_161 = & V_159 [ V_154 ] ;
if ( V_161 -> V_162 ) {
strcpy ( V_152 , L_78 ) ;
V_152 += strlen ( L_78 ) ;
strcpy ( V_152 , V_161 -> V_166 ) ;
V_152 += strlen ( V_161 -> V_166 ) ;
strcpy ( V_152 , L_79 ) ;
V_152 += strlen ( L_79 ) ;
memcpy ( V_152 , V_161 -> V_162 , V_161 -> V_163 ) ;
V_152 += V_161 -> V_163 ;
strcpy ( V_152 , L_80 ) ;
V_152 += strlen ( L_80 ) ;
F_78 ( V_159 [ V_154 ] . V_162 ) ;
V_159 [ V_154 ] . V_162 = NULL ;
}
}
F_80 ( & V_4 -> V_10 -> V_11 , V_151 , V_157 , V_18 ) ;
F_40 ( L_87 ) ;
}
static int F_81 ( struct V_115 * V_10 ,
const struct V_169 * V_170 )
{
int V_14 = 0 ;
struct V_83 * V_2 = NULL ;
struct V_3 * V_4 = NULL ;
F_40 ( L_88 ,
V_170 -> V_171 , V_170 -> V_13 , V_170 -> V_172 , V_10 -> V_124 ) ;
V_4 = F_9 ( & V_10 -> V_11 , sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return - V_58 ;
V_4 -> V_10 = V_10 ;
if ( V_170 -> V_173 ) {
struct V_174 * V_53 = ( void * ) V_170 -> V_173 ;
V_4 -> V_44 = V_53 -> V_44 ;
V_4 -> V_42 = V_53 -> V_42 ;
V_4 -> V_20 = V_53 -> V_20 ;
V_4 -> V_74 = V_53 -> V_74 ;
V_4 -> V_175 = V_53 -> V_175 ;
V_4 -> V_158 = V_53 -> V_158 ;
}
if ( F_59 ( V_4 ) < 0 ) {
F_20 ( L_89 ) ;
return - V_176 ;
}
F_68 ( V_4 ) ;
if ( F_70 ( V_4 ) ) {
F_20 ( L_90 ) ;
V_14 = - V_176 ;
goto V_177;
}
F_67 ( V_4 ) ;
F_6 ( & V_10 -> V_11 , V_4 ) ;
V_2 = F_82 ( V_4 ) ;
if ( ! V_2 ) {
F_20 ( L_91 ) ;
V_14 = - V_176 ;
goto V_178;
}
V_4 -> V_2 = V_2 ;
V_2 -> V_179 = F_69 ;
V_2 -> V_180 = F_71 ;
V_2 -> V_181 = F_51 ;
V_2 -> V_182 = F_76 ;
if ( F_83 ( V_2 ) ) {
F_20 ( L_92 ) ;
V_14 = - V_176 ;
goto V_178;
}
return 0 ;
V_178:
F_68 ( V_4 ) ;
V_177:
F_66 ( V_4 ) ;
return V_14 ;
}
static void F_84 ( struct V_115 * V_10 )
{
struct V_3 * V_4 ;
if ( V_10 ) {
V_4 = F_57 ( V_10 ) ;
if ( V_4 ) {
if ( V_183 ) {
F_85 ( V_4 -> V_2 ,
V_184 ) ;
F_68 ( V_4 ) ;
}
F_30 ( L_93 ) ;
V_4 -> V_2 -> V_116 = true ;
F_66 ( V_4 ) ;
F_86 ( V_4 -> V_2 ) ;
}
}
}
static int F_87 ( struct V_13 * V_11 )
{
struct V_115 * V_10 = F_88 ( V_11 ) ;
struct V_3 * V_4 ;
struct V_83 * V_2 ;
T_6 V_185 ;
struct V_90 * V_93 ;
if ( V_10 ) {
V_185 = F_89 ( V_10 ) ;
F_30 ( L_94 , F_90 ( V_10 ) ,
V_185 ) ;
if ( ! ( V_185 & V_186 ) ) {
F_20 ( L_95 ,
F_90 ( V_10 ) ) ;
return - V_187 ;
}
V_4 = F_57 ( V_10 ) ;
if ( ! V_4 || ! V_4 -> V_2 ) {
F_20 ( L_96 ) ;
return 0 ;
}
} else {
F_20 ( L_97 ) ;
return 0 ;
}
if ( V_4 -> V_7 && V_4 -> V_7 -> V_19 >= 0 ) {
V_4 -> V_7 -> V_9 = false ;
F_91 ( V_4 -> V_7 -> V_19 ) ;
F_92 ( V_4 -> V_7 -> V_19 ) ;
}
V_2 = V_4 -> V_2 ;
V_2 -> V_112 -> V_188 = true ;
V_93 = V_2 -> V_92 . V_93 ;
F_30 ( L_98 , V_93 -> V_189 ) ;
F_93 ( V_93 ) ;
if ( V_2 -> V_112 -> V_190 != V_191 ) {
if ( F_94 ( V_2 ) ) {
F_20 ( L_99 ) ;
if ( V_4 -> V_7 &&
V_4 -> V_7 -> V_19 >= 0 ) {
F_95 ( V_4 -> V_7 -> V_19 ) ;
F_13 ( V_4 -> V_7 -> V_19 ) ;
}
V_2 -> V_112 -> V_188 = false ;
return - V_192 ;
}
}
V_2 -> V_112 -> V_188 = false ;
V_2 -> V_112 -> V_193 = true ;
if ( V_2 -> V_112 -> V_190 == V_191 ) {
F_30 ( L_100 ) ;
return F_96 ( V_10 , V_186 ) ;
}
F_30 ( L_101 ) ;
return 0 ;
}
static int F_97 ( struct V_13 * V_11 )
{
struct V_115 * V_10 = F_88 ( V_11 ) ;
struct V_3 * V_4 ;
struct V_83 * V_2 ;
T_6 V_185 ;
struct V_90 * V_93 ;
if ( V_10 ) {
V_185 = F_89 ( V_10 ) ;
F_30 ( L_102 , F_90 ( V_10 ) ,
V_185 ) ;
V_4 = F_57 ( V_10 ) ;
if ( ! V_4 || ! V_4 -> V_2 ) {
F_20 ( L_96 ) ;
return 0 ;
}
} else {
F_20 ( L_97 ) ;
return 0 ;
}
V_2 = V_4 -> V_2 ;
if ( ! V_2 -> V_112 -> V_193 ) {
F_30 ( L_103 ) ;
return 0 ;
}
V_2 -> V_180 ( V_2 ) ;
V_2 -> V_112 -> V_190 = V_194 ;
V_93 = V_2 -> V_92 . V_93 ;
F_30 ( L_104 , V_93 -> V_189 ) ;
V_2 -> V_112 -> V_193 = false ;
F_30 ( L_105 , V_93 -> V_189 ) ;
F_98 ( V_93 ) ;
if ( V_4 -> V_7 && V_4 -> V_7 -> V_19 >= 0 ) {
F_95 ( V_4 -> V_7 -> V_19 ) ;
F_13 ( V_4 -> V_7 -> V_19 ) ;
if ( V_4 -> V_7 -> V_9 )
F_91 ( V_4 -> V_7 -> V_19 ) ;
}
return 0 ;
}
static int T_7 F_99 ( void )
{
if ( F_100 ( & V_195 ) != 0 ) {
F_20 ( L_106 ) ;
return - V_176 ;
}
V_183 = 0 ;
return 0 ;
}
static void T_8 F_101 ( void )
{
V_183 = 1 ;
F_102 ( & V_195 ) ;
}
