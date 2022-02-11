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
switch ( V_6 -> V_11 ) {
case 0 :
case - V_18 :
break;
case - V_19 :
case - V_20 :
case - V_21 :
return;
default:
F_2 ( L_3 , V_6 -> V_11 ) ;
break;
}
if ( F_10 ( & V_2 -> V_22 ) == 0 )
return;
if ( V_2 -> V_5 . V_23 ) {
V_15 = V_2 -> V_5 . V_23 ;
V_17 = V_15 -> V_17 ;
V_13 = V_17 -> V_24 >> 3 ;
for ( V_3 = 0 ; V_3 < V_6 -> V_25 ; V_3 ++ ) {
int V_26 = V_6 -> V_27 [ V_3 ] . V_28 /
V_13 ;
V_12 = ( unsigned char * ) V_6 -> V_7 +
V_6 -> V_27 [ V_3 ] . V_29 ;
if ( ! V_26 )
continue;
V_9 = V_2 -> V_5 . V_30 ;
if ( V_9 + V_26 >= V_17 -> V_31 ) {
unsigned int V_32 ;
V_32 = V_17 -> V_31 - V_9 ;
memcpy ( V_17 -> V_33 + V_9 * V_13 , V_12 ,
V_32 * V_13 ) ;
memcpy ( V_17 -> V_33 , V_12 + V_32 * V_13 ,
V_26 * V_13 - V_32 * V_13 ) ;
} else {
memcpy ( V_17 -> V_33 + V_9 * V_13 , V_12 ,
V_26 * V_13 ) ;
}
F_11 ( V_15 ) ;
V_2 -> V_5 . V_30 += V_26 ;
if ( V_2 -> V_5 . V_30 >=
V_17 -> V_31 )
V_2 -> V_5 . V_30 -=
V_17 -> V_31 ;
V_2 -> V_5 . V_34 += V_26 ;
if ( V_2 -> V_5 . V_34 >=
V_17 -> V_35 ) {
V_2 -> V_5 . V_34 -=
V_17 -> V_35 ;
V_10 = 1 ;
}
F_12 ( V_15 ) ;
}
if ( V_10 )
F_13 ( V_15 ) ;
}
V_6 -> V_11 = 0 ;
V_11 = F_14 ( V_6 , V_36 ) ;
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
switch ( V_6 -> V_11 ) {
case 0 :
case - V_18 :
break;
case - V_19 :
case - V_20 :
case - V_21 :
return;
default:
F_2 ( L_3 , V_6 -> V_11 ) ;
break;
}
if ( F_10 ( & V_2 -> V_22 ) == 0 )
return;
if ( V_2 -> V_5 . V_23 ) {
V_15 = V_2 -> V_5 . V_23 ;
V_17 = V_15 -> V_17 ;
V_13 = V_17 -> V_24 >> 3 ;
if ( 1 ) {
int V_26 = V_6 -> V_28 /
V_13 ;
V_12 = ( unsigned char * ) V_6 -> V_7 ;
V_9 = V_2 -> V_5 . V_30 ;
if ( V_9 + V_26 >= V_17 -> V_31 ) {
unsigned int V_32 ;
V_32 = V_17 -> V_31 - V_9 ;
memcpy ( V_17 -> V_33 + V_9 * V_13 , V_12 ,
V_32 * V_13 ) ;
memcpy ( V_17 -> V_33 , V_12 + V_32 * V_13 ,
V_26 * V_13 - V_32 * V_13 ) ;
} else {
memcpy ( V_17 -> V_33 + V_9 * V_13 , V_12 ,
V_26 * V_13 ) ;
}
F_11 ( V_15 ) ;
V_2 -> V_5 . V_30 += V_26 ;
if ( V_2 -> V_5 . V_30 >=
V_17 -> V_31 )
V_2 -> V_5 . V_30 -=
V_17 -> V_31 ;
V_2 -> V_5 . V_34 += V_26 ;
if ( V_2 -> V_5 . V_34 >=
V_17 -> V_35 ) {
V_2 -> V_5 . V_34 -=
V_17 -> V_35 ;
V_10 = 1 ;
}
F_12 ( V_15 ) ;
}
if ( V_10 )
F_13 ( V_15 ) ;
}
V_6 -> V_11 = 0 ;
V_11 = F_14 ( V_6 , V_36 ) ;
if ( V_11 < 0 ) {
F_15 ( L_4 ,
V_11 ) ;
}
return;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_3 , V_37 ;
int V_38 ;
F_18 ( L_5 , V_39 ) ;
V_38 = V_40 * V_2 -> V_5 . V_41 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
struct V_6 * V_6 ;
int V_42 , V_43 ;
V_2 -> V_5 . V_7 [ V_3 ] = F_19 ( V_38 , V_36 ) ;
if ( ! V_2 -> V_5 . V_7 [ V_3 ] )
return - V_44 ;
memset ( V_2 -> V_5 . V_7 [ V_3 ] , 0x80 , V_38 ) ;
V_6 = F_20 ( V_40 , V_36 ) ;
if ( ! V_6 ) {
F_15 ( L_6 ) ;
for ( V_42 = 0 ; V_42 < V_3 ; V_42 ++ ) {
F_6 ( V_2 -> V_5 . V_6 [ V_42 ] ) ;
F_7 ( V_2 -> V_5 . V_7 [ V_42 ] ) ;
}
return - V_44 ;
}
V_6 -> V_2 = V_2 -> V_45 ;
V_6 -> V_8 = V_2 ;
V_6 -> V_46 = F_21 ( V_2 -> V_45 ,
V_2 -> V_5 . V_47 ) ;
V_6 -> V_48 = V_49 ;
V_6 -> V_7 = V_2 -> V_5 . V_7 [ V_3 ] ;
V_6 -> V_50 = 1 ;
V_6 -> V_51 = F_9 ;
V_6 -> V_25 = V_40 ;
V_6 -> V_52 = V_38 ;
for ( V_42 = V_43 = 0 ; V_42 < V_40 ;
V_42 ++ , V_43 += V_2 -> V_5 . V_41 ) {
V_6 -> V_27 [ V_42 ] . V_29 = V_43 ;
V_6 -> V_27 [ V_42 ] . V_26 = V_2 -> V_5 . V_41 ;
}
V_2 -> V_5 . V_6 [ V_3 ] = V_6 ;
}
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_37 = F_14 ( V_2 -> V_5 . V_6 [ V_3 ] , V_36 ) ;
if ( V_37 < 0 ) {
F_1 ( V_2 ) ;
return V_37 ;
}
}
return V_37 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_3 , V_37 ;
int V_38 ;
F_18 ( L_7 , V_39 ) ;
V_38 = V_53 * V_2 -> V_5 . V_41 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
struct V_6 * V_6 ;
int V_42 ;
V_2 -> V_5 . V_7 [ V_3 ] = F_19 ( V_38 , V_36 ) ;
if ( ! V_2 -> V_5 . V_7 [ V_3 ] )
return - V_44 ;
memset ( V_2 -> V_5 . V_7 [ V_3 ] , 0x80 , V_38 ) ;
V_6 = F_20 ( V_53 , V_36 ) ;
if ( ! V_6 ) {
F_15 ( L_6 ) ;
for ( V_42 = 0 ; V_42 < V_3 ; V_42 ++ ) {
F_6 ( V_2 -> V_5 . V_6 [ V_42 ] ) ;
F_7 ( V_2 -> V_5 . V_7 [ V_42 ] ) ;
}
return - V_44 ;
}
V_6 -> V_2 = V_2 -> V_45 ;
V_6 -> V_8 = V_2 ;
V_6 -> V_46 = F_23 ( V_2 -> V_45 ,
V_2 -> V_5 . V_47 ) ;
V_6 -> V_48 = 0 ;
V_6 -> V_7 = V_2 -> V_5 . V_7 [ V_3 ] ;
V_6 -> V_51 = F_16 ;
V_6 -> V_52 = V_38 ;
V_2 -> V_5 . V_6 [ V_3 ] = V_6 ;
}
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_37 = F_14 ( V_2 -> V_5 . V_6 [ V_3 ] , V_36 ) ;
if ( V_37 < 0 ) {
F_8 ( V_2 ) ;
return V_37 ;
}
}
return V_37 ;
}
static int F_24 ( struct V_14 * V_54 ,
T_1 V_55 )
{
struct V_16 * V_17 = V_54 -> V_17 ;
F_2 ( L_8 ) ;
if ( V_17 -> V_33 ) {
if ( V_17 -> V_56 > V_55 )
return 0 ;
F_25 ( V_17 -> V_33 ) ;
}
V_17 -> V_33 = F_26 ( V_55 ) ;
if ( ! V_17 -> V_33 )
return - V_44 ;
V_17 -> V_56 = V_55 ;
return 0 ;
}
static int F_27 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_28 ( V_15 ) ;
struct V_16 * V_17 = V_15 -> V_17 ;
int V_57 = 0 ;
F_2 ( L_9 ) ;
if ( ! V_2 ) {
F_15 ( L_10
L_11 ) ;
return - V_58 ;
}
V_2 -> V_59 = 0 ;
F_29 ( & V_2 -> V_60 ) ;
if ( V_2 -> V_61 )
V_57 = F_30 ( V_2 , V_62 , 1 ) ;
else
V_57 = F_30 ( V_2 , V_62 , 0 ) ;
F_31 ( & V_2 -> V_60 ) ;
if ( V_57 < 0 ) {
F_15 ( L_12 ) ;
return V_57 ;
}
V_17 -> V_63 = V_64 ;
F_29 ( & V_2 -> V_60 ) ;
V_57 = F_32 ( V_2 , 1 , V_65 ) ;
V_2 -> V_5 . V_66 ++ ;
F_31 ( & V_2 -> V_60 ) ;
F_33 ( V_17 , V_67 ) ;
V_2 -> V_5 . V_23 = V_15 ;
V_17 -> V_68 = V_2 ;
return 0 ;
}
static int F_34 ( struct V_14 * V_15 )
{
int V_57 ;
struct V_1 * V_2 = F_28 ( V_15 ) ;
F_2 ( L_13 ) ;
F_29 ( & V_2 -> V_60 ) ;
V_57 = F_32 ( V_2 , 0 , V_65 ) ;
V_57 = F_30 ( V_2 , V_62 , 0 ) ;
if ( V_57 < 0 ) {
F_15 ( L_12 ) ;
F_31 ( & V_2 -> V_60 ) ;
return V_57 ;
}
V_2 -> V_59 = 1 ;
V_2 -> V_5 . V_66 -- ;
F_31 ( & V_2 -> V_60 ) ;
if ( V_2 -> V_5 . V_66 == 0 && V_2 -> V_5 . V_69 == 1 ) {
F_2 ( L_14 , V_2 -> V_5 . V_66 ) ;
F_2 ( L_15 ) ;
V_2 -> V_5 . V_69 = 0 ;
F_2 ( L_16 ) ;
if ( F_10 ( & V_2 -> V_22 ) > 0 ) {
F_35 ( & V_2 -> V_22 , 0 ) ;
F_36 ( & V_2 -> V_70 ) ;
}
}
return 0 ;
}
static int F_37 ( struct V_14 * V_15 ,
struct V_71 * V_72 )
{
unsigned int V_73 , V_74 , V_75 ;
int V_57 ;
F_2 ( L_17 ) ;
V_57 = F_24 ( V_15 ,
F_38 ( V_72 ) ) ;
V_75 = F_39 ( V_72 ) ;
V_74 = F_40 ( V_72 ) ;
V_73 = F_41 ( V_72 ) ;
return 0 ;
}
static int F_42 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_28 ( V_15 ) ;
F_2 ( L_18 ) ;
if ( F_10 ( & V_2 -> V_22 ) > 0 ) {
F_35 ( & V_2 -> V_22 , 0 ) ;
F_36 ( & V_2 -> V_70 ) ;
}
return 0 ;
}
static int F_43 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_28 ( V_15 ) ;
V_2 -> V_5 . V_30 = 0 ;
V_2 -> V_5 . V_34 = 0 ;
return 0 ;
}
static void F_44 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_45 ( V_77 , struct V_1 , V_70 ) ;
if ( F_10 ( & V_2 -> V_22 ) ) {
F_2 ( L_19 ) ;
if ( F_46 ( V_2 ) == 0 )
F_47 ( V_2 , V_78 , V_79 ) ;
if ( V_2 -> V_61 )
F_17 ( V_2 ) ;
else
F_22 ( V_2 ) ;
} else {
F_2 ( L_20 ) ;
F_1 ( V_2 ) ;
}
}
static int F_48 ( struct V_14 * V_15 ,
int V_80 )
{
struct V_1 * V_2 = F_28 ( V_15 ) ;
int V_81 ;
F_49 ( & V_2 -> V_5 . V_82 ) ;
switch ( V_80 ) {
case V_83 :
F_35 ( & V_2 -> V_22 , 1 ) ;
break;
case V_84 :
F_35 ( & V_2 -> V_22 , 0 ) ;
break;
default:
V_81 = - V_85 ;
}
F_50 ( & V_2 -> V_5 . V_82 ) ;
F_36 ( & V_2 -> V_70 ) ;
return 0 ;
}
static T_2 F_51 ( struct V_14
* V_15 )
{
struct V_1 * V_2 ;
unsigned long V_86 ;
T_2 V_87 ;
V_2 = F_28 ( V_15 ) ;
F_52 ( & V_2 -> V_5 . V_82 , V_86 ) ;
V_87 = V_2 -> V_5 . V_30 ;
F_53 ( & V_2 -> V_5 . V_82 , V_86 ) ;
return V_87 ;
}
static struct V_88 * F_54 ( struct V_14 * V_54 ,
unsigned long V_29 )
{
void * V_89 = V_54 -> V_17 -> V_33 + V_29 ;
return F_55 ( V_89 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_90 * V_5 = & V_2 -> V_5 ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
static int V_95 ;
int V_96 ;
struct V_97 * V_98 ;
int V_3 , V_99 = 0 ;
if ( V_2 -> V_100 != 1 ) {
return 0 ;
}
F_18 ( L_21
L_22 ) ;
V_96 = F_57 ( V_101 [ V_95 ] , L_23 , V_102 ,
0 , & V_94 ) ;
if ( V_96 < 0 )
return V_96 ;
F_58 ( & V_5 -> V_82 ) ;
V_96 = F_59 ( V_94 , L_23 , 0 , 0 , 1 , & V_92 ) ;
if ( V_96 < 0 ) {
F_60 ( V_94 ) ;
return V_96 ;
}
F_61 ( V_92 , V_103 ,
& V_104 ) ;
V_92 -> V_105 = 0 ;
V_92 -> V_68 = V_2 ;
strcpy ( V_92 -> V_106 , L_24 ) ;
F_62 ( V_94 , & V_2 -> V_45 -> V_2 ) ;
strcpy ( V_94 -> V_107 , L_25 ) ;
strcpy ( V_94 -> V_108 , L_23 ) ;
strcpy ( V_94 -> V_109 , L_26 ) ;
F_63 ( & V_2 -> V_70 , F_44 ) ;
V_96 = F_64 ( V_94 ) ;
if ( V_96 < 0 ) {
F_60 ( V_94 ) ;
return V_96 ;
}
V_5 -> V_110 = V_94 ;
V_5 -> V_45 = V_2 -> V_45 ;
V_98 =
V_2 -> V_45 -> V_111 -> V_112 [ V_2 -> V_113 .
V_114 [ 0 ] . V_115 .
V_116 + 1 ] ;
V_5 -> V_47 =
F_65 ( V_98 -> V_117 [ 0 ] . V_118 [ V_99 ] . V_119 .
V_120 ) ;
V_5 -> V_121 = V_98 -> V_122 ;
F_18 ( L_27 ,
V_5 -> V_47 , V_5 -> V_121 ) ;
V_5 -> V_123 = F_19 ( 32 * V_5 -> V_121 , V_124 ) ;
if ( V_5 -> V_123 == NULL ) {
F_15 ( L_28 ) ;
return - V_44 ;
}
for ( V_3 = 0 ; V_3 < V_5 -> V_121 ; V_3 ++ ) {
T_3 V_125 =
F_65 ( V_98 -> V_117 [ V_3 ] . V_118 [ V_99 ] . V_119 .
V_126 ) ;
V_5 -> V_123 [ V_3 ] =
( V_125 & 0x07ff ) * ( ( ( V_125 & 0x1800 ) >> 11 ) + 1 ) ;
F_18 ( L_29 , V_3 ,
V_5 -> V_123 [ V_3 ] ) ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_100 != 1 ) {
return 0 ;
}
if ( V_2 -> V_5 . V_110 ) {
F_60 ( V_2 -> V_5 . V_110 ) ;
F_7 ( V_2 -> V_5 . V_123 ) ;
V_2 -> V_5 . V_110 = NULL ;
}
return 0 ;
}
static int T_4 F_67 ( void )
{
return F_68 ( & V_127 ) ;
}
static void T_5 F_69 ( void )
{
F_70 ( & V_127 ) ;
}
