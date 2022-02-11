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
V_6 -> V_51 = V_52 | V_53 ;
V_6 -> V_7 = V_2 -> V_5 . V_7 [ V_3 ] ;
V_6 -> V_54 = 1 ;
V_6 -> V_55 = F_9 ;
V_6 -> V_27 = V_43 ;
V_6 -> V_56 = V_40 ;
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
V_40 = V_57 * V_2 -> V_5 . V_44 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
struct V_6 * V_6 ;
int V_45 ;
V_2 -> V_5 . V_7 [ V_3 ] = F_19 ( V_40 , V_38 ) ;
if ( ! V_2 -> V_5 . V_7 [ V_3 ] )
return - V_47 ;
memset ( V_2 -> V_5 . V_7 [ V_3 ] , 0x80 , V_40 ) ;
V_6 = F_20 ( V_57 , V_38 ) ;
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
V_6 -> V_51 = V_53 ;
V_6 -> V_7 = V_2 -> V_5 . V_7 [ V_3 ] ;
V_6 -> V_55 = F_16 ;
V_6 -> V_56 = V_40 ;
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
static int F_24 ( struct V_14 * V_58 ,
T_1 V_59 )
{
struct V_16 * V_17 = V_58 -> V_17 ;
F_2 ( L_8 ) ;
if ( V_17 -> V_35 ) {
if ( V_17 -> V_60 > V_59 )
return 0 ;
F_25 ( V_17 -> V_35 ) ;
}
V_17 -> V_35 = F_26 ( V_59 ) ;
if ( ! V_17 -> V_35 )
return - V_47 ;
V_17 -> V_60 = V_59 ;
return 0 ;
}
static int F_27 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_28 ( V_15 ) ;
struct V_16 * V_17 = V_15 -> V_17 ;
int V_61 = 0 ;
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
V_2 -> V_62 = 0 ;
F_29 ( & V_2 -> V_63 ) ;
if ( V_2 -> V_64 )
V_61 = F_30 ( V_2 , V_65 , 1 ) ;
else
V_61 = F_30 ( V_2 , V_65 , 0 ) ;
F_31 ( & V_2 -> V_63 ) ;
if ( V_61 < 0 ) {
F_15 ( L_13 ) ;
return V_61 ;
}
V_17 -> V_66 = V_67 ;
F_29 ( & V_2 -> V_63 ) ;
V_61 = F_32 ( V_2 , 1 , V_68 ) ;
V_2 -> V_5 . V_69 ++ ;
F_31 ( & V_2 -> V_63 ) ;
F_33 ( V_17 , V_70 ) ;
V_2 -> V_5 . V_25 = V_15 ;
V_17 -> V_71 = V_2 ;
return 0 ;
}
static int F_34 ( struct V_14 * V_15 )
{
int V_61 ;
struct V_1 * V_2 = F_28 ( V_15 ) ;
F_2 ( L_14 ) ;
F_29 ( & V_2 -> V_63 ) ;
V_61 = F_32 ( V_2 , 0 , V_68 ) ;
V_61 = F_30 ( V_2 , V_65 , 0 ) ;
if ( V_61 < 0 ) {
F_15 ( L_13 ) ;
F_31 ( & V_2 -> V_63 ) ;
return V_61 ;
}
V_2 -> V_62 = 1 ;
V_2 -> V_5 . V_69 -- ;
F_31 ( & V_2 -> V_63 ) ;
if ( V_2 -> V_5 . V_69 == 0 && V_2 -> V_5 . V_72 == 1 ) {
F_2 ( L_15 , V_2 -> V_5 . V_69 ) ;
F_2 ( L_16 ) ;
V_2 -> V_5 . V_72 = 0 ;
F_2 ( L_17 ) ;
if ( F_10 ( & V_2 -> V_24 ) > 0 ) {
F_35 ( & V_2 -> V_24 , 0 ) ;
F_36 ( & V_2 -> V_73 ) ;
}
}
return 0 ;
}
static int F_37 ( struct V_14 * V_15 ,
struct V_74 * V_75 )
{
unsigned int V_76 , V_77 , V_78 ;
int V_61 ;
F_2 ( L_18 ) ;
V_61 = F_24 ( V_15 ,
F_38 ( V_75 ) ) ;
V_78 = F_39 ( V_75 ) ;
V_77 = F_40 ( V_75 ) ;
V_76 = F_41 ( V_75 ) ;
return 0 ;
}
static int F_42 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_28 ( V_15 ) ;
F_2 ( L_19 ) ;
if ( F_10 ( & V_2 -> V_24 ) > 0 ) {
F_35 ( & V_2 -> V_24 , 0 ) ;
F_36 ( & V_2 -> V_73 ) ;
}
return 0 ;
}
static int F_43 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_28 ( V_15 ) ;
V_2 -> V_5 . V_32 = 0 ;
V_2 -> V_5 . V_36 = 0 ;
return 0 ;
}
static void F_44 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = F_45 ( V_80 , struct V_1 , V_73 ) ;
if ( F_10 ( & V_2 -> V_24 ) ) {
F_2 ( L_20 ) ;
if ( F_46 ( V_2 ) == 0 )
F_47 ( V_2 , V_81 , V_82 ) ;
if ( V_2 -> V_64 )
F_17 ( V_2 ) ;
else
F_22 ( V_2 ) ;
} else {
F_2 ( L_21 ) ;
F_1 ( V_2 ) ;
}
}
static int F_48 ( struct V_14 * V_15 ,
int V_83 )
{
struct V_1 * V_2 = F_28 ( V_15 ) ;
int V_84 ;
if ( V_2 -> V_18 & V_19 )
return - V_42 ;
F_49 ( & V_2 -> V_5 . V_85 ) ;
switch ( V_83 ) {
case V_86 :
F_35 ( & V_2 -> V_24 , 1 ) ;
break;
case V_87 :
F_35 ( & V_2 -> V_24 , 0 ) ;
break;
default:
V_84 = - V_88 ;
}
F_50 ( & V_2 -> V_5 . V_85 ) ;
F_36 ( & V_2 -> V_73 ) ;
return 0 ;
}
static T_2 F_51 ( struct V_14
* V_15 )
{
struct V_1 * V_2 ;
unsigned long V_89 ;
T_2 V_90 ;
V_2 = F_28 ( V_15 ) ;
F_52 ( & V_2 -> V_5 . V_85 , V_89 ) ;
V_90 = V_2 -> V_5 . V_32 ;
F_53 ( & V_2 -> V_5 . V_85 , V_89 ) ;
return V_90 ;
}
static struct V_91 * F_54 ( struct V_14 * V_58 ,
unsigned long V_31 )
{
void * V_92 = V_58 -> V_17 -> V_35 + V_31 ;
return F_55 ( V_92 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_93 * V_5 = & V_2 -> V_5 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
static int V_98 ;
int V_99 ;
struct V_100 * V_101 ;
int V_3 , V_102 = 0 ;
if ( V_2 -> V_103 != 1 ) {
return 0 ;
}
F_18 ( L_22
L_23 ) ;
V_99 = F_57 ( V_104 [ V_98 ] , L_24 , V_105 ,
0 , & V_97 ) ;
if ( V_99 < 0 )
return V_99 ;
F_58 ( & V_5 -> V_85 ) ;
V_99 = F_59 ( V_97 , L_24 , 0 , 0 , 1 , & V_95 ) ;
if ( V_99 < 0 ) {
F_60 ( V_97 ) ;
return V_99 ;
}
F_61 ( V_95 , V_106 ,
& V_107 ) ;
V_95 -> V_108 = 0 ;
V_95 -> V_71 = V_2 ;
strcpy ( V_95 -> V_109 , L_25 ) ;
F_62 ( V_97 , & V_2 -> V_48 -> V_2 ) ;
strcpy ( V_97 -> V_110 , L_26 ) ;
strcpy ( V_97 -> V_111 , L_24 ) ;
strcpy ( V_97 -> V_112 , L_27 ) ;
F_63 ( & V_2 -> V_73 , F_44 ) ;
V_99 = F_64 ( V_97 ) ;
if ( V_99 < 0 ) {
F_60 ( V_97 ) ;
return V_99 ;
}
V_5 -> V_113 = V_97 ;
V_5 -> V_48 = V_2 -> V_48 ;
V_101 =
V_2 -> V_48 -> V_114 -> V_115 [ V_2 -> V_116 .
V_117 [ 0 ] . V_118 .
V_119 + 1 ] ;
V_5 -> V_50 =
F_65 ( V_101 -> V_120 [ 0 ] . V_121 [ V_102 ] . V_122 .
V_123 ) ;
V_5 -> V_124 = V_101 -> V_125 ;
F_18 ( L_28 ,
V_5 -> V_50 , V_5 -> V_124 ) ;
V_5 -> V_126 = F_19 ( 32 * V_5 -> V_124 , V_127 ) ;
if ( V_5 -> V_126 == NULL ) {
F_15 ( L_29 ) ;
return - V_47 ;
}
for ( V_3 = 0 ; V_3 < V_5 -> V_124 ; V_3 ++ ) {
T_3 V_128 =
F_65 ( V_101 -> V_120 [ V_3 ] . V_121 [ V_102 ] . V_122 .
V_129 ) ;
V_5 -> V_126 [ V_3 ] =
( V_128 & 0x07ff ) * ( ( ( V_128 & 0x1800 ) >> 11 ) + 1 ) ;
F_18 ( L_30 , V_3 ,
V_5 -> V_126 [ V_3 ] ) ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_103 != 1 ) {
return 0 ;
}
if ( V_2 -> V_5 . V_113 ) {
F_60 ( V_2 -> V_5 . V_113 ) ;
F_7 ( V_2 -> V_5 . V_126 ) ;
V_2 -> V_5 . V_113 = NULL ;
}
return 0 ;
}
static int T_4 F_67 ( void )
{
return F_68 ( & V_130 ) ;
}
static void T_5 F_69 ( void )
{
F_70 ( & V_130 ) ;
}
