static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
char * V_5 ;
int V_6 ;
int V_7 ;
int V_8 ;
V_5 = F_2 ( 8 , V_9 ) ;
if ( ! V_5 ) {
F_3 ( & V_2 -> V_10 -> V_2 , L_1 ) ;
return - V_11 ;
}
V_6 = F_4 ( V_4 , F_5 ( V_4 , 0 ) ,
V_12 ,
V_13 | V_14 | V_15 ,
V_16 ,
V_17 , V_5 , 8 , 5000 ) ;
if ( V_6 != 8 ) {
F_6 ( L_2 ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
F_6 ( L_3 , V_7 , V_5 [ V_7 ] ) ;
F_3 ( & V_2 -> V_10 -> V_2 , L_4 ) ;
V_8 = - V_18 ;
goto V_19;
}
V_5 [ 0 ] = V_20 ;
V_6 = F_4 ( V_4 , F_7 ( V_4 , 0 ) ,
V_21 ,
V_22 | V_14 | V_15 ,
V_16 ,
V_17 , V_5 , 8 , 5000 ) ;
if ( V_6 != 8 ) {
F_6 ( L_5 ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
F_6 ( L_3 , V_7 , V_5 [ V_7 ] ) ;
F_3 ( & V_2 -> V_10 -> V_2 , L_6 ) ;
V_8 = - V_18 ;
goto V_19;
}
V_8 = 0 ;
V_19:
F_8 ( V_5 ) ;
return V_8 ;
}
static void F_9 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_10 ( V_24 , struct V_1 , V_24 ) ;
int V_25 ;
F_6 ( L_7 ) ;
F_1 ( V_2 ) ;
V_25 = F_11 ( V_2 -> V_26 , V_27 ) ;
if ( V_25 )
F_3 ( & V_2 -> V_10 -> V_2 ,
L_8 ,
V_25 ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_28 , int V_29 ,
int V_30 , int * V_31 , int * V_32 )
{
int V_7 , V_33 ;
int * V_34 = V_2 -> V_35 + V_28 ;
int V_36 = 0 , V_37 = 0 ;
int V_38 = 0 ;
* V_32 = 0 ;
for ( V_7 = 0 ; V_7 < V_29 ; V_7 ++ ) {
if ( V_34 [ V_7 ] < V_39 ) {
if ( V_38 )
V_38 = 0 ;
} else if ( V_7 < 1 ||
( ! V_38 && V_34 [ V_7 - 1 ] < V_34 [ V_7 ] ) ) {
( * V_32 ) ++ ;
V_38 = 1 ;
} else if ( V_7 > 0 && ( V_34 [ V_7 - 1 ] - V_34 [ V_7 ] > V_39 ) ) {
V_38 = 0 ;
}
}
if ( * V_32 < 1 )
return 0 ;
memset ( V_2 -> V_40 , 0 , 4 * sizeof( V_2 -> V_40 [ 0 ] ) ) ;
for ( V_7 = 0 ; V_7 < V_29 ; V_7 ++ )
V_2 -> V_40 [ V_7 + 4 ] = V_34 [ V_7 ] << V_41 ;
memset ( & V_2 -> V_40 [ V_29 + 4 ] , 0 , 4 * sizeof( V_2 -> V_40 [ 0 ] ) ) ;
for ( V_33 = 0 ; V_33 < 4 ; V_33 ++ ) {
V_2 -> V_42 [ 0 ] = ( V_2 -> V_40 [ 0 ] + V_2 -> V_40 [ 1 ] ) / 2 ;
for ( V_7 = 1 ; V_7 < V_29 + 7 ; V_7 ++ )
V_2 -> V_42 [ V_7 ] = ( V_2 -> V_40 [ V_7 - 1 ] +
V_2 -> V_40 [ V_7 ] * 2 +
V_2 -> V_40 [ V_7 + 1 ] ) / 4 ;
V_2 -> V_42 [ V_7 ] = ( V_2 -> V_40 [ V_7 - 1 ] + V_2 -> V_40 [ V_7 ] ) / 2 ;
memcpy ( V_2 -> V_40 , V_2 -> V_42 , sizeof( V_2 -> V_40 ) ) ;
}
for ( V_7 = 0 ; V_7 < V_29 + 8 ; V_7 ++ ) {
if ( ( V_2 -> V_40 [ V_7 ] >> V_41 ) > 0 ) {
V_36 += V_2 -> V_40 [ V_7 ] * V_7 ;
V_37 += V_2 -> V_40 [ V_7 ] ;
}
}
if ( V_37 > 0 ) {
* V_31 = V_37 >> V_41 ;
return V_36 * V_30 / V_37 ;
}
return 0 ;
}
static inline void F_13 ( struct V_43 * V_44 , int V_32 )
{
F_14 ( V_44 , V_45 , V_32 == 1 ) ;
F_14 ( V_44 , V_46 , V_32 == 2 ) ;
F_14 ( V_44 , V_47 , V_32 > 2 ) ;
}
static int F_15 ( struct V_26 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_48 ;
struct V_49 * V_10 = V_2 -> V_10 ;
switch ( V_26 -> V_50 ) {
case 0 :
break;
case - V_51 :
if ( ! V_2 -> V_52 ) {
F_16 ( & V_10 -> V_2 ,
L_9 ,
V_2 -> V_53 -> V_54 , V_2 -> V_26 -> V_55 ) ;
V_2 -> V_52 = true ;
}
case - V_56 :
case - V_57 :
case - V_58 :
F_17 ( & V_10 -> V_2 ,
L_10 ,
V_26 -> V_50 ) ;
return V_59 ;
default:
F_17 ( & V_10 -> V_2 ,
L_11 ,
V_26 -> V_50 ) ;
return V_60 ;
}
if ( V_2 -> V_26 -> V_55 != V_2 -> V_53 -> V_54 ) {
F_6 ( L_12
L_13 ,
V_2 -> V_5 [ 0 ] , V_2 -> V_26 -> V_55 ) ;
return V_60 ;
}
return V_61 ;
}
static void F_18 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = V_2 -> V_53 -> V_62 ; V_7 < V_63 ; V_7 ++ ) {
if ( V_2 -> V_64 [ V_7 ] ) {
F_19 ( & V_2 -> V_10 -> V_2 ,
L_14 ) ;
F_20 ( V_2 -> V_44 , V_65 , 0 ,
( V_2 -> V_53 -> V_66 - 1 ) *
V_2 -> V_53 -> V_67 - 1 ,
V_2 -> V_53 -> V_68 , 0 ) ;
break;
}
}
}
static void F_21 ( struct V_26 * V_26 )
{
int V_69 , V_70 , V_71 , V_72 , V_73 , V_74 ;
int V_25 , V_7 , V_75 ;
int V_76 , V_32 ;
struct V_1 * V_2 = V_26 -> V_48 ;
int V_50 = F_15 ( V_26 ) ;
if ( V_50 == V_59 )
return;
else if ( V_50 == V_60 )
goto exit;
if ( V_2 -> V_53 == & V_77 ) {
memset ( V_2 -> V_64 , 0 , sizeof( V_2 -> V_64 ) ) ;
for ( V_7 = 0 , V_75 = 19 ; V_7 < 20 ; V_7 += 2 , V_75 += 3 ) {
V_2 -> V_64 [ V_7 ] = V_2 -> V_5 [ V_75 ] ;
V_2 -> V_64 [ V_7 + 1 ] = V_2 -> V_5 [ V_75 + 1 ] ;
}
for ( V_7 = 0 , V_75 = 1 ; V_7 < 9 ; V_7 += 2 , V_75 += 3 ) {
V_2 -> V_64 [ V_63 + V_7 ] = V_2 -> V_5 [ V_75 ] ;
V_2 -> V_64 [ V_63 + V_7 + 1 ] = V_2 -> V_5 [ V_75 + 1 ] ;
}
} else {
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
V_2 -> V_64 [ V_7 + 0 ] = V_2 -> V_5 [ 5 * V_7 + 2 ] ;
V_2 -> V_64 [ V_7 + 8 ] = V_2 -> V_5 [ 5 * V_7 + 4 ] ;
V_2 -> V_64 [ V_7 + 16 ] = V_2 -> V_5 [ 5 * V_7 + 42 ] ;
if ( V_7 < 2 )
V_2 -> V_64 [ V_7 + 24 ] = V_2 -> V_5 [ 5 * V_7 + 44 ] ;
V_2 -> V_64 [ V_63 + V_7 ] = V_2 -> V_5 [ 5 * V_7 + 1 ] ;
V_2 -> V_64 [ V_63 + V_7 + 8 ] = V_2 -> V_5 [ 5 * V_7 + 3 ] ;
}
}
F_22 ( L_15 , V_2 -> V_64 ) ;
if ( ! V_2 -> V_78 ) {
V_2 -> V_78 = true ;
V_2 -> V_79 = V_2 -> V_80 = - 1 ;
memcpy ( V_2 -> V_81 , V_2 -> V_64 , sizeof( V_2 -> V_81 ) ) ;
if ( F_23 ( ! V_2 -> V_82 ) ) {
F_18 ( V_2 ) ;
V_2 -> V_82 = 1 ;
goto exit;
}
}
for ( V_7 = 0 ; V_7 < V_63 + V_83 ; V_7 ++ ) {
signed char V_84 = V_2 -> V_81 [ V_7 ] - V_2 -> V_64 [ V_7 ] ;
V_2 -> V_35 [ V_7 ] -= V_84 ;
if ( V_2 -> V_35 [ V_7 ] < 0 )
V_2 -> V_35 [ V_7 ] = 0 ;
}
memcpy ( V_2 -> V_81 , V_2 -> V_64 , sizeof( V_2 -> V_81 ) ) ;
F_22 ( L_16 , V_2 -> V_35 ) ;
V_69 = F_12 ( V_2 , 0 , V_63 ,
V_2 -> V_53 -> V_67 , & V_71 , & V_73 ) ;
V_70 = F_12 ( V_2 , V_63 , V_83 ,
V_2 -> V_53 -> V_85 , & V_72 , & V_74 ) ;
V_76 = V_2 -> V_5 [ V_2 -> V_53 -> V_54 - 1 ] & V_86 ;
V_32 = F_24 ( V_73 , V_74 ) ;
if ( V_69 && V_70 && V_32 == V_2 -> V_87 ) {
if ( V_2 -> V_79 != - 1 ) {
V_69 = ( V_2 -> V_79 * 7 + V_69 ) >> 3 ;
V_70 = ( V_2 -> V_80 * 7 + V_70 ) >> 3 ;
V_2 -> V_79 = V_69 ;
V_2 -> V_80 = V_70 ;
if ( V_88 > 1 )
F_25 ( V_89 L_17
L_18 ,
V_69 , V_70 , V_71 , V_72 ) ;
F_14 ( V_2 -> V_44 , V_90 , 1 ) ;
F_26 ( V_2 -> V_44 , V_65 , V_69 ) ;
F_26 ( V_2 -> V_44 , V_91 , V_70 ) ;
F_26 ( V_2 -> V_44 , V_92 ,
F_27 ( V_93 , V_71 + V_72 ) ) ;
F_13 ( V_2 -> V_44 , V_32 ) ;
}
V_2 -> V_79 = V_69 ;
V_2 -> V_80 = V_70 ;
} else if ( ! V_69 && ! V_70 ) {
V_2 -> V_79 = V_2 -> V_80 = - 1 ;
V_2 -> V_87 = 0 ;
F_14 ( V_2 -> V_44 , V_90 , 0 ) ;
F_26 ( V_2 -> V_44 , V_92 , 0 ) ;
F_13 ( V_2 -> V_44 , 0 ) ;
memset ( V_2 -> V_35 , 0 , sizeof( V_2 -> V_35 ) ) ;
}
if ( V_32 != V_2 -> V_87 )
V_2 -> V_79 = V_2 -> V_80 = - 1 ;
V_2 -> V_87 = V_32 ;
F_14 ( V_2 -> V_44 , V_94 , V_76 ) ;
F_28 ( V_2 -> V_44 ) ;
exit:
V_25 = F_11 ( V_2 -> V_26 , V_27 ) ;
if ( V_25 )
F_3 ( & V_2 -> V_10 -> V_2 ,
L_19 ,
V_25 ) ;
}
static void F_29 ( struct V_26 * V_26 )
{
int V_69 , V_70 , V_71 , V_72 , V_73 , V_74 ;
int V_25 , V_7 , V_75 ;
int V_76 , V_32 ;
struct V_1 * V_2 = V_26 -> V_48 ;
int V_50 = F_15 ( V_26 ) ;
if ( V_50 == V_59 )
return;
else if ( V_50 == V_60 )
goto exit;
for ( V_7 = 0 , V_75 = 19 ; V_7 < 20 ; V_7 += 2 , V_75 += 3 ) {
V_2 -> V_64 [ V_7 ] = V_2 -> V_5 [ V_75 + 1 ] ;
V_2 -> V_64 [ V_7 + 1 ] = V_2 -> V_5 [ V_75 + 2 ] ;
}
for ( V_7 = 0 , V_75 = 1 ; V_7 < 9 ; V_7 += 2 , V_75 += 3 ) {
V_2 -> V_64 [ V_63 + V_7 ] = V_2 -> V_5 [ V_75 + 1 ] ;
V_2 -> V_64 [ V_63 + V_7 + 1 ] = V_2 -> V_5 [ V_75 + 2 ] ;
}
F_22 ( L_15 , V_2 -> V_64 ) ;
if ( V_2 -> V_5 [ V_2 -> V_53 -> V_54 - 1 ] & V_95 ) {
F_6 ( L_20 ) ;
memcpy ( V_2 -> V_81 , V_2 -> V_64 , sizeof( V_2 -> V_81 ) ) ;
goto exit;
}
for ( V_7 = 0 ; V_7 < V_63 + V_83 ; V_7 ++ ) {
V_2 -> V_35 [ V_7 ] = V_2 -> V_64 [ V_7 ] - V_2 -> V_81 [ V_7 ] ;
if ( V_2 -> V_35 [ V_7 ] > 127 )
V_2 -> V_35 [ V_7 ] -= 256 ;
if ( V_2 -> V_35 [ V_7 ] < - 127 )
V_2 -> V_35 [ V_7 ] += 256 ;
if ( V_2 -> V_35 [ V_7 ] < 0 )
V_2 -> V_35 [ V_7 ] = 0 ;
}
F_22 ( L_16 , V_2 -> V_35 ) ;
V_69 = F_12 ( V_2 , 0 , V_63 ,
V_2 -> V_53 -> V_67 , & V_71 , & V_73 ) ;
V_70 = F_12 ( V_2 , V_63 , V_83 ,
V_2 -> V_53 -> V_85 , & V_72 , & V_74 ) ;
V_76 = V_2 -> V_5 [ V_2 -> V_53 -> V_54 - 1 ] & V_86 ;
V_32 = F_24 ( V_73 , V_74 ) ;
if ( V_69 && V_70 && V_32 == V_2 -> V_87 ) {
if ( V_2 -> V_79 != - 1 ) {
V_69 = ( V_2 -> V_79 * 7 + V_69 ) >> 3 ;
V_70 = ( V_2 -> V_80 * 7 + V_70 ) >> 3 ;
V_2 -> V_79 = V_69 ;
V_2 -> V_80 = V_70 ;
if ( V_88 > 1 )
F_25 ( V_89 L_21
L_22 ,
V_69 , V_70 , V_71 , V_72 ) ;
F_14 ( V_2 -> V_44 , V_90 , 1 ) ;
F_26 ( V_2 -> V_44 , V_65 , V_69 ) ;
F_26 ( V_2 -> V_44 , V_91 , V_70 ) ;
F_26 ( V_2 -> V_44 , V_92 ,
F_27 ( V_93 , V_71 + V_72 ) ) ;
F_13 ( V_2 -> V_44 , V_32 ) ;
}
V_2 -> V_79 = V_69 ;
V_2 -> V_80 = V_70 ;
} else if ( ! V_69 && ! V_70 ) {
V_2 -> V_79 = V_2 -> V_80 = - 1 ;
V_2 -> V_87 = 0 ;
F_14 ( V_2 -> V_44 , V_90 , 0 ) ;
F_26 ( V_2 -> V_44 , V_92 , 0 ) ;
F_13 ( V_2 -> V_44 , 0 ) ;
memset ( V_2 -> V_35 , 0 , sizeof( V_2 -> V_35 ) ) ;
}
if ( V_32 != V_2 -> V_87 )
V_2 -> V_79 = V_2 -> V_80 = - 1 ;
V_2 -> V_87 = V_32 ;
F_14 ( V_2 -> V_44 , V_94 , V_76 ) ;
F_28 ( V_2 -> V_44 ) ;
if ( ! V_69 && ! V_70 && ! V_76 ) {
V_2 -> V_96 ++ ;
if ( V_2 -> V_96 == 10 ) {
V_2 -> V_79 = V_2 -> V_80 = - 1 ;
V_2 -> V_96 = 0 ;
F_30 ( & V_2 -> V_24 ) ;
return;
}
} else
V_2 -> V_96 = 0 ;
exit:
V_25 = F_11 ( V_2 -> V_26 , V_27 ) ;
if ( V_25 )
F_3 ( & V_2 -> V_10 -> V_2 ,
L_19 ,
V_25 ) ;
}
static int F_31 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_32 ( V_44 ) ;
if ( F_11 ( V_2 -> V_26 , V_27 ) )
return - V_18 ;
V_2 -> V_97 = 1 ;
return 0 ;
}
static void F_33 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_32 ( V_44 ) ;
F_34 ( V_2 -> V_26 ) ;
F_35 ( & V_2 -> V_24 ) ;
V_2 -> V_97 = 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_53 != & V_98 ) {
if ( F_1 ( V_2 ) )
return - V_18 ;
F_19 ( & V_2 -> V_10 -> V_2 , L_23 ) ;
}
return 0 ;
}
static int F_37 ( struct V_49 * V_99 ,
const struct V_100 * V_101 )
{
struct V_1 * V_2 ;
struct V_43 * V_43 ;
struct V_3 * V_4 = F_38 ( V_99 ) ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
int V_106 = 0 ;
int V_7 , error = - V_11 ;
const struct V_107 * V_53 = ( const struct V_107 * ) V_101 -> V_108 ;
V_103 = V_99 -> V_109 ;
for ( V_7 = 0 ; V_7 < V_103 -> V_110 . V_111 ; V_7 ++ ) {
V_105 = & V_103 -> V_105 [ V_7 ] . V_110 ;
if ( ! V_106 && F_39 ( V_105 ) ) {
V_106 = V_105 -> V_112 ;
break;
}
}
if ( ! V_106 ) {
F_3 ( & V_99 -> V_2 , L_24 ) ;
return - V_18 ;
}
V_2 = F_40 ( sizeof( struct V_1 ) , V_9 ) ;
V_43 = F_41 () ;
if ( ! V_2 || ! V_43 ) {
F_3 ( & V_99 -> V_2 , L_1 ) ;
goto V_113;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_10 = V_99 ;
V_2 -> V_44 = V_43 ;
V_2 -> V_53 = V_53 ;
V_2 -> V_52 = false ;
V_2 -> V_26 = F_42 ( 0 , V_9 ) ;
if ( ! V_2 -> V_26 )
goto V_113;
V_2 -> V_5 = F_43 ( V_2 -> V_4 , V_2 -> V_53 -> V_54 , V_9 ,
& V_2 -> V_26 -> V_114 ) ;
if ( ! V_2 -> V_5 )
goto V_115;
F_44 ( V_2 -> V_26 , V_4 ,
F_45 ( V_4 , V_106 ) ,
V_2 -> V_5 , V_2 -> V_53 -> V_54 ,
V_2 -> V_53 -> V_116 , V_2 , 1 ) ;
error = F_36 ( V_2 ) ;
if ( error )
goto V_117;
F_46 ( V_4 , V_2 -> V_118 , sizeof( V_2 -> V_118 ) ) ;
F_47 ( V_2 -> V_118 , L_25 , sizeof( V_2 -> V_118 ) ) ;
V_43 -> V_119 = L_26 ;
V_43 -> V_118 = V_2 -> V_118 ;
F_48 ( V_2 -> V_4 , & V_43 -> V_101 ) ;
V_43 -> V_2 . V_120 = & V_99 -> V_2 ;
F_49 ( V_43 , V_2 ) ;
V_43 -> V_97 = F_31 ;
V_43 -> V_121 = F_33 ;
F_50 ( V_122 , V_43 -> V_123 ) ;
F_20 ( V_43 , V_65 , 0 ,
( V_2 -> V_53 -> V_62 - 1 ) * V_2 -> V_53 -> V_67 - 1 ,
V_2 -> V_53 -> V_68 , 0 ) ;
F_20 ( V_43 , V_91 , 0 ,
( V_2 -> V_53 -> V_124 - 1 ) * V_2 -> V_53 -> V_85 - 1 ,
V_2 -> V_53 -> V_68 , 0 ) ;
F_20 ( V_43 , V_92 , 0 , V_93 , 0 , 0 ) ;
F_50 ( V_125 , V_43 -> V_123 ) ;
F_50 ( V_90 , V_43 -> V_126 ) ;
F_50 ( V_45 , V_43 -> V_126 ) ;
F_50 ( V_46 , V_43 -> V_126 ) ;
F_50 ( V_47 , V_43 -> V_126 ) ;
F_50 ( V_94 , V_43 -> V_126 ) ;
error = F_51 ( V_2 -> V_44 ) ;
if ( error )
goto V_117;
F_52 ( V_99 , V_2 ) ;
F_53 ( & V_2 -> V_24 , F_9 ) ;
return 0 ;
V_117:
F_54 ( V_2 -> V_4 , V_2 -> V_53 -> V_54 ,
V_2 -> V_5 , V_2 -> V_26 -> V_114 ) ;
V_115:
F_55 ( V_2 -> V_26 ) ;
V_113:
F_52 ( V_99 , NULL ) ;
F_8 ( V_2 ) ;
F_56 ( V_43 ) ;
return error ;
}
static void F_57 ( struct V_49 * V_99 )
{
struct V_1 * V_2 = F_58 ( V_99 ) ;
F_52 ( V_99 , NULL ) ;
if ( V_2 ) {
F_34 ( V_2 -> V_26 ) ;
F_59 ( V_2 -> V_44 ) ;
F_54 ( V_2 -> V_4 , V_2 -> V_53 -> V_54 ,
V_2 -> V_5 , V_2 -> V_26 -> V_114 ) ;
F_55 ( V_2 -> V_26 ) ;
F_8 ( V_2 ) ;
}
F_19 ( & V_99 -> V_2 , L_27 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
int error ;
error = F_36 ( V_2 ) ;
if ( error )
return error ;
if ( V_2 -> V_97 && F_11 ( V_2 -> V_26 , V_27 ) )
return - V_18 ;
return 0 ;
}
static int F_61 ( struct V_49 * V_99 , T_1 V_127 )
{
struct V_1 * V_2 = F_58 ( V_99 ) ;
F_34 ( V_2 -> V_26 ) ;
return 0 ;
}
static int F_62 ( struct V_49 * V_99 )
{
struct V_1 * V_2 = F_58 ( V_99 ) ;
if ( V_2 -> V_97 && F_11 ( V_2 -> V_26 , V_27 ) )
return - V_18 ;
return 0 ;
}
static int F_63 ( struct V_49 * V_99 )
{
struct V_1 * V_2 = F_58 ( V_99 ) ;
return F_60 ( V_2 ) ;
}
