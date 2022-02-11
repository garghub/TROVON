static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_1 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( V_2 -> V_5 . V_6 [ V_3 ] ) {
if ( ! F_3 () )
F_4 ( V_2 -> V_5 . V_6 [ V_3 ] ) ;
else
F_5 ( V_2 -> V_5 . V_6 [ V_3 ] ) ;
F_6 ( V_2 -> V_5 . V_6 [ V_3 ] ) ;
V_2 -> V_5 . V_6 [ V_3 ] = NULL ;
F_7 ( V_2 -> V_5 . V_7 [ V_3 ] ) ;
V_2 -> V_5 . V_7 [ V_3 ] = NULL ;
}
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_2 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( V_2 -> V_5 . V_6 [ V_3 ] ) {
if ( ! F_3 () )
F_4 ( V_2 -> V_5 . V_6 [ V_3 ] ) ;
else
F_5 ( V_2 -> V_5 . V_6 [ V_3 ] ) ;
F_6 ( V_2 -> V_5 . V_6 [ V_3 ] ) ;
V_2 -> V_5 . V_6 [ V_3 ] = NULL ;
F_7 ( V_2 -> V_5 . V_7 [ V_3 ] ) ;
V_2 -> V_5 . V_7 [ V_3 ] = NULL ;
}
}
return 0 ;
}
static void F_9 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_8 ;
int V_3 ;
unsigned int V_9 ;
int V_10 = 0 ;
int V_11 ;
unsigned char * V_12 ;
unsigned int V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
if ( V_2 -> V_18 & V_19 )
return;
switch ( V_6 -> V_11 ) {
case 0 :
case - V_20 :
break;
case - V_21 :
case - V_22 :
case - V_23 :
return;
default:
F_2 ( L_3 , V_6 -> V_11 ) ;
break;
}
if ( F_10 ( & V_2 -> V_24 ) == 0 )
return;
if ( V_2 -> V_5 . V_25 ) {
V_15 = V_2 -> V_5 . V_25 ;
V_17 = V_15 -> V_17 ;
V_13 = V_17 -> V_26 >> 3 ;
for ( V_3 = 0 ; V_3 < V_6 -> V_27 ; V_3 ++ ) {
int V_28 = V_6 -> V_29 [ V_3 ] . V_30 /
V_13 ;
V_12 = ( unsigned char * ) V_6 -> V_7 +
V_6 -> V_29 [ V_3 ] . V_31 ;
if ( ! V_28 )
continue;
V_9 = V_2 -> V_5 . V_32 ;
if ( V_9 + V_28 >= V_17 -> V_33 ) {
unsigned int V_34 ;
V_34 = V_17 -> V_33 - V_9 ;
memcpy ( V_17 -> V_35 + V_9 * V_13 , V_12 ,
V_34 * V_13 ) ;
memcpy ( V_17 -> V_35 , V_12 + V_34 * V_13 ,
V_28 * V_13 - V_34 * V_13 ) ;
} else {
memcpy ( V_17 -> V_35 + V_9 * V_13 , V_12 ,
V_28 * V_13 ) ;
}
F_11 ( V_15 ) ;
V_2 -> V_5 . V_32 += V_28 ;
if ( V_2 -> V_5 . V_32 >=
V_17 -> V_33 )
V_2 -> V_5 . V_32 -=
V_17 -> V_33 ;
V_2 -> V_5 . V_36 += V_28 ;
if ( V_2 -> V_5 . V_36 >=
V_17 -> V_37 ) {
V_2 -> V_5 . V_36 -=
V_17 -> V_37 ;
V_10 = 1 ;
}
F_12 ( V_15 ) ;
}
if ( V_10 )
F_13 ( V_15 ) ;
}
V_6 -> V_11 = 0 ;
V_11 = F_14 ( V_6 , V_38 ) ;
if ( V_11 < 0 ) {
F_15 ( L_4 ,
V_11 ) ;
}
return;
}
static void F_16 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_8 ;
unsigned int V_9 ;
int V_10 = 0 ;
int V_11 ;
unsigned char * V_12 ;
unsigned int V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
if ( V_2 -> V_18 & V_19 )
return;
switch ( V_6 -> V_11 ) {
case 0 :
case - V_20 :
break;
case - V_21 :
case - V_22 :
case - V_23 :
return;
default:
F_2 ( L_3 , V_6 -> V_11 ) ;
break;
}
if ( F_10 ( & V_2 -> V_24 ) == 0 )
return;
if ( V_2 -> V_5 . V_25 ) {
V_15 = V_2 -> V_5 . V_25 ;
V_17 = V_15 -> V_17 ;
V_13 = V_17 -> V_26 >> 3 ;
if ( 1 ) {
int V_28 = V_6 -> V_30 /
V_13 ;
V_12 = ( unsigned char * ) V_6 -> V_7 ;
V_9 = V_2 -> V_5 . V_32 ;
if ( V_9 + V_28 >= V_17 -> V_33 ) {
unsigned int V_34 ;
V_34 = V_17 -> V_33 - V_9 ;
memcpy ( V_17 -> V_35 + V_9 * V_13 , V_12 ,
V_34 * V_13 ) ;
memcpy ( V_17 -> V_35 , V_12 + V_34 * V_13 ,
V_28 * V_13 - V_34 * V_13 ) ;
} else {
memcpy ( V_17 -> V_35 + V_9 * V_13 , V_12 ,
V_28 * V_13 ) ;
}
F_11 ( V_15 ) ;
V_2 -> V_5 . V_32 += V_28 ;
if ( V_2 -> V_5 . V_32 >=
V_17 -> V_33 )
V_2 -> V_5 . V_32 -=
V_17 -> V_33 ;
V_2 -> V_5 . V_36 += V_28 ;
if ( V_2 -> V_5 . V_36 >=
V_17 -> V_37 ) {
V_2 -> V_5 . V_36 -=
V_17 -> V_37 ;
V_10 = 1 ;
}
F_12 ( V_15 ) ;
}
if ( V_10 )
F_13 ( V_15 ) ;
}
V_6 -> V_11 = 0 ;
V_11 = F_14 ( V_6 , V_38 ) ;
if ( V_11 < 0 ) {
F_15 ( L_4 ,
V_11 ) ;
}
return;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_3 , V_39 ;
int V_40 ;
F_18 ( L_5 , V_41 ) ;
if ( V_2 -> V_18 & V_19 )
return - V_42 ;
V_40 = V_43 * V_2 -> V_5 . V_44 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
struct V_6 * V_6 ;
int V_45 , V_46 ;
V_2 -> V_5 . V_7 [ V_3 ] = F_19 ( V_40 , V_38 ) ;
if ( ! V_2 -> V_5 . V_7 [ V_3 ] )
return - V_47 ;
memset ( V_2 -> V_5 . V_7 [ V_3 ] , 0x80 , V_40 ) ;
V_6 = F_20 ( V_43 , V_38 ) ;
if ( ! V_6 ) {
F_15 ( L_6 ) ;
for ( V_45 = 0 ; V_45 < V_3 ; V_45 ++ ) {
F_6 ( V_2 -> V_5 . V_6 [ V_45 ] ) ;
F_7 ( V_2 -> V_5 . V_7 [ V_45 ] ) ;
}
return - V_47 ;
}
V_6 -> V_2 = V_2 -> V_48 ;
V_6 -> V_8 = V_2 ;
V_6 -> V_49 = F_21 ( V_2 -> V_48 ,
V_2 -> V_5 . V_50 ) ;
V_6 -> V_51 = V_52 ;
V_6 -> V_7 = V_2 -> V_5 . V_7 [ V_3 ] ;
V_6 -> V_53 = 1 ;
V_6 -> V_54 = F_9 ;
V_6 -> V_27 = V_43 ;
V_6 -> V_55 = V_40 ;
for ( V_45 = V_46 = 0 ; V_45 < V_43 ;
V_45 ++ , V_46 += V_2 -> V_5 . V_44 ) {
V_6 -> V_29 [ V_45 ] . V_31 = V_46 ;
V_6 -> V_29 [ V_45 ] . V_28 = V_2 -> V_5 . V_44 ;
}
V_2 -> V_5 . V_6 [ V_3 ] = V_6 ;
}
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_39 = F_14 ( V_2 -> V_5 . V_6 [ V_3 ] , V_38 ) ;
if ( V_39 < 0 ) {
F_1 ( V_2 ) ;
return V_39 ;
}
}
return V_39 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_3 , V_39 ;
int V_40 ;
F_18 ( L_7 , V_41 ) ;
if ( V_2 -> V_18 & V_19 )
return - V_42 ;
V_40 = V_56 * V_2 -> V_5 . V_44 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
struct V_6 * V_6 ;
int V_45 ;
V_2 -> V_5 . V_7 [ V_3 ] = F_19 ( V_40 , V_38 ) ;
if ( ! V_2 -> V_5 . V_7 [ V_3 ] )
return - V_47 ;
memset ( V_2 -> V_5 . V_7 [ V_3 ] , 0x80 , V_40 ) ;
V_6 = F_20 ( V_56 , V_38 ) ;
if ( ! V_6 ) {
F_15 ( L_6 ) ;
for ( V_45 = 0 ; V_45 < V_3 ; V_45 ++ ) {
F_6 ( V_2 -> V_5 . V_6 [ V_45 ] ) ;
F_7 ( V_2 -> V_5 . V_7 [ V_45 ] ) ;
}
return - V_47 ;
}
V_6 -> V_2 = V_2 -> V_48 ;
V_6 -> V_8 = V_2 ;
V_6 -> V_49 = F_23 ( V_2 -> V_48 ,
V_2 -> V_5 . V_50 ) ;
V_6 -> V_51 = 0 ;
V_6 -> V_7 = V_2 -> V_5 . V_7 [ V_3 ] ;
V_6 -> V_54 = F_16 ;
V_6 -> V_55 = V_40 ;
V_2 -> V_5 . V_6 [ V_3 ] = V_6 ;
}
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_39 = F_14 ( V_2 -> V_5 . V_6 [ V_3 ] , V_38 ) ;
if ( V_39 < 0 ) {
F_8 ( V_2 ) ;
return V_39 ;
}
}
return V_39 ;
}
static int F_24 ( struct V_14 * V_57 ,
T_1 V_58 )
{
struct V_16 * V_17 = V_57 -> V_17 ;
F_2 ( L_8 ) ;
if ( V_17 -> V_35 ) {
if ( V_17 -> V_59 > V_58 )
return 0 ;
F_25 ( V_17 -> V_35 ) ;
}
V_17 -> V_35 = F_26 ( V_58 ) ;
if ( ! V_17 -> V_35 )
return - V_47 ;
V_17 -> V_59 = V_58 ;
return 0 ;
}
static int F_27 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_28 ( V_15 ) ;
struct V_16 * V_17 = V_15 -> V_17 ;
int V_60 = 0 ;
F_2 ( L_9 ) ;
if ( ! V_2 ) {
F_15 ( L_10
L_11 ) ;
return - V_42 ;
}
if ( V_2 -> V_18 & V_19 ) {
F_15 ( L_12 ) ;
return - V_42 ;
}
V_2 -> V_61 = 0 ;
F_29 ( & V_2 -> V_62 ) ;
if ( V_2 -> V_63 )
V_60 = F_30 ( V_2 , V_64 , 1 ) ;
else
V_60 = F_30 ( V_2 , V_64 , 0 ) ;
F_31 ( & V_2 -> V_62 ) ;
if ( V_60 < 0 ) {
F_15 ( L_13 ) ;
return V_60 ;
}
V_17 -> V_65 = V_66 ;
F_29 ( & V_2 -> V_62 ) ;
V_60 = F_32 ( V_2 , 1 , V_67 ) ;
V_2 -> V_5 . V_68 ++ ;
F_31 ( & V_2 -> V_62 ) ;
F_33 ( V_17 , V_69 ) ;
V_2 -> V_5 . V_25 = V_15 ;
V_17 -> V_70 = V_2 ;
return 0 ;
}
static int F_34 ( struct V_14 * V_15 )
{
int V_60 ;
struct V_1 * V_2 = F_28 ( V_15 ) ;
F_2 ( L_14 ) ;
F_29 ( & V_2 -> V_62 ) ;
V_60 = F_32 ( V_2 , 0 , V_67 ) ;
V_60 = F_30 ( V_2 , V_64 , 0 ) ;
if ( V_60 < 0 ) {
F_15 ( L_13 ) ;
F_31 ( & V_2 -> V_62 ) ;
return V_60 ;
}
V_2 -> V_61 = 1 ;
V_2 -> V_5 . V_68 -- ;
F_31 ( & V_2 -> V_62 ) ;
if ( V_2 -> V_5 . V_68 == 0 && V_2 -> V_5 . V_71 == 1 ) {
F_2 ( L_15 , V_2 -> V_5 . V_68 ) ;
F_2 ( L_16 ) ;
V_2 -> V_5 . V_71 = 0 ;
F_2 ( L_17 ) ;
if ( F_10 ( & V_2 -> V_24 ) > 0 ) {
F_35 ( & V_2 -> V_24 , 0 ) ;
F_36 ( & V_2 -> V_72 ) ;
}
}
return 0 ;
}
static int F_37 ( struct V_14 * V_15 ,
struct V_73 * V_74 )
{
int V_60 ;
F_2 ( L_18 ) ;
V_60 = F_24 ( V_15 ,
F_38 ( V_74 ) ) ;
#if 0
unsigned int channels, rate, format;
format = params_format(hw_params);
rate = params_rate(hw_params);
channels = params_channels(hw_params);
#endif
return V_60 ;
}
static int F_39 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_28 ( V_15 ) ;
F_2 ( L_19 ) ;
if ( F_10 ( & V_2 -> V_24 ) > 0 ) {
F_35 ( & V_2 -> V_24 , 0 ) ;
F_36 ( & V_2 -> V_72 ) ;
}
return 0 ;
}
static int F_40 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_28 ( V_15 ) ;
V_2 -> V_5 . V_32 = 0 ;
V_2 -> V_5 . V_36 = 0 ;
return 0 ;
}
static void F_41 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_42 ( V_76 , struct V_1 , V_72 ) ;
if ( F_10 ( & V_2 -> V_24 ) ) {
F_2 ( L_20 ) ;
if ( F_43 ( V_2 ) == 0 )
F_44 ( V_2 , V_77 , V_78 ) ;
if ( V_2 -> V_63 )
F_17 ( V_2 ) ;
else
F_22 ( V_2 ) ;
} else {
F_2 ( L_21 ) ;
F_1 ( V_2 ) ;
}
}
static int F_45 ( struct V_14 * V_15 ,
int V_79 )
{
struct V_1 * V_2 = F_28 ( V_15 ) ;
int V_80 = 0 ;
if ( V_2 -> V_18 & V_19 )
return - V_42 ;
F_46 ( & V_2 -> V_5 . V_81 ) ;
switch ( V_79 ) {
case V_82 :
F_35 ( & V_2 -> V_24 , 1 ) ;
break;
case V_83 :
F_35 ( & V_2 -> V_24 , 0 ) ;
break;
default:
V_80 = - V_84 ;
break;
}
F_47 ( & V_2 -> V_5 . V_81 ) ;
F_36 ( & V_2 -> V_72 ) ;
return V_80 ;
}
static T_2 F_48 ( struct V_14
* V_15 )
{
struct V_1 * V_2 ;
unsigned long V_85 ;
T_2 V_86 ;
V_2 = F_28 ( V_15 ) ;
F_49 ( & V_2 -> V_5 . V_81 , V_85 ) ;
V_86 = V_2 -> V_5 . V_32 ;
F_50 ( & V_2 -> V_5 . V_81 , V_85 ) ;
return V_86 ;
}
static struct V_87 * F_51 ( struct V_14 * V_57 ,
unsigned long V_31 )
{
void * V_88 = V_57 -> V_17 -> V_35 + V_31 ;
return F_52 ( V_88 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_89 * V_5 = & V_2 -> V_5 ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
static int V_94 ;
int V_95 ;
struct V_96 * V_97 ;
int V_3 , V_98 = 0 ;
if ( V_2 -> V_99 != 1 ) {
return 0 ;
}
F_18 ( L_22
L_23 ) ;
V_95 = F_54 ( V_100 [ V_94 ] , L_24 , V_101 ,
0 , & V_93 ) ;
if ( V_95 < 0 )
return V_95 ;
F_55 ( & V_5 -> V_81 ) ;
V_95 = F_56 ( V_93 , L_24 , 0 , 0 , 1 , & V_91 ) ;
if ( V_95 < 0 ) {
F_57 ( V_93 ) ;
return V_95 ;
}
F_58 ( V_91 , V_102 ,
& V_103 ) ;
V_91 -> V_104 = 0 ;
V_91 -> V_70 = V_2 ;
strcpy ( V_91 -> V_105 , L_25 ) ;
F_59 ( V_93 , & V_2 -> V_48 -> V_2 ) ;
strcpy ( V_93 -> V_106 , L_26 ) ;
strcpy ( V_93 -> V_107 , L_24 ) ;
strcpy ( V_93 -> V_108 , L_27 ) ;
F_60 ( & V_2 -> V_72 , F_41 ) ;
V_95 = F_61 ( V_93 ) ;
if ( V_95 < 0 ) {
F_57 ( V_93 ) ;
return V_95 ;
}
V_5 -> V_109 = V_93 ;
V_5 -> V_48 = V_2 -> V_48 ;
V_97 =
V_2 -> V_48 -> V_110 -> V_111 [ V_2 -> V_112 .
V_113 [ 0 ] . V_114 .
V_115 + 1 ] ;
V_5 -> V_50 =
F_62 ( V_97 -> V_116 [ 0 ] . V_117 [ V_98 ] . V_118 .
V_119 ) ;
V_5 -> V_120 = V_97 -> V_121 ;
F_18 ( L_28 ,
V_5 -> V_50 , V_5 -> V_120 ) ;
V_5 -> V_122 = F_19 ( 32 * V_5 -> V_120 , V_123 ) ;
if ( V_5 -> V_122 == NULL ) {
F_15 ( L_29 ) ;
return - V_47 ;
}
for ( V_3 = 0 ; V_3 < V_5 -> V_120 ; V_3 ++ ) {
T_3 V_124 =
F_62 ( V_97 -> V_116 [ V_3 ] . V_117 [ V_98 ] . V_118 .
V_125 ) ;
V_5 -> V_122 [ V_3 ] =
( V_124 & 0x07ff ) * ( ( ( V_124 & 0x1800 ) >> 11 ) + 1 ) ;
F_18 ( L_30 , V_3 ,
V_5 -> V_122 [ V_3 ] ) ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_99 != 1 ) {
return 0 ;
}
if ( V_2 -> V_5 . V_109 ) {
F_57 ( V_2 -> V_5 . V_109 ) ;
F_7 ( V_2 -> V_5 . V_122 ) ;
V_2 -> V_5 . V_109 = NULL ;
}
return 0 ;
}
static int T_4 F_64 ( void )
{
return F_65 ( & V_126 ) ;
}
static void T_5 F_66 ( void )
{
F_67 ( & V_126 ) ;
}
