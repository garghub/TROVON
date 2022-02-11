static int F_1 (
const struct V_1 * * V_2 , const char * V_3 , struct V_4 * V_4 )
{
int V_5 ;
F_2 ( V_4 , L_1 , V_3 ) ;
V_5 = F_3 ( V_2 , V_3 , V_4 ) ;
if ( V_5 )
F_4 ( V_4 ,
L_2 ,
V_3 , V_5 ) ;
return V_5 ;
}
static inline T_1 F_5 ( const struct V_6 * V_7 )
{
return F_6 ( V_7 -> V_8 . V_9 ) ;
}
static int F_7 ( struct V_6 * V_7 ,
const T_2 * V_10 , T_3 V_11 , T_1 V_12 , int V_13 )
{
T_2 * V_14 ;
int V_5 ;
V_14 = F_8 ( V_15 , V_16 ) ;
if ( ! V_14 ) {
F_4 ( & V_7 -> V_17 , L_3 ) ;
V_5 = - V_18 ;
goto error;
}
V_11 &= ~ 1 ;
while ( V_11 > 0 ) {
T_3 V_19 = V_11 <= V_15 ?
V_11 : V_15 ;
F_2 ( & V_7 -> V_17 , L_4 , V_19 ) ;
memcpy ( V_14 , V_10 , V_19 ) ;
V_5 = F_9 ( V_7 , F_10 ( V_7 , 0 ) ,
V_20 ,
V_21 | V_22 ,
V_12 , 0 , V_14 , V_19 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_7 -> V_17 ,
L_5
L_6 , V_5 ) ;
goto error;
}
V_19 = V_5 & ~ 1 ;
V_11 -= V_19 ;
V_10 += V_19 ;
V_12 += V_19 / sizeof( T_1 ) ;
}
if ( V_13 & V_23 ) {
T_2 V_24 ;
V_5 = F_9 ( V_7 , F_11 ( V_7 , 0 ) ,
V_25 ,
V_26 | V_22 ,
0 , 0 , V_14 , sizeof( V_24 ) , 5000 ) ;
if ( V_5 != sizeof( V_24 ) ) {
F_4 ( & V_7 -> V_17 ,
L_7
L_8 , V_5 ) ;
if ( V_5 >= 0 )
V_5 = - V_27 ;
goto error;
}
V_24 = V_14 [ 0 ] ;
if ( V_24 & 0x80 ) {
F_4 ( & V_7 -> V_17 ,
L_9
L_10 ,
( unsigned int ) V_24 ) ;
V_5 = - V_27 ;
goto error;
}
F_2 ( & V_7 -> V_17 , L_11 ,
( unsigned int ) V_24 ) ;
}
V_5 = 0 ;
error:
F_12 ( V_14 ) ;
return V_5 ;
}
static T_1 F_13 ( const void * V_10 , T_1 V_28 )
{
const T_4 * V_14 = V_10 ;
return F_6 ( V_14 [ V_28 ] ) ;
}
static char * F_14 ( struct V_29 * V_30 , char * V_31 , T_3 V_11 ,
const char * V_32 )
{
F_15 ( V_31 , V_11 , L_12 ,
V_30 -> V_33 ?
V_34 : V_35 ,
V_32 ) ;
return V_31 ;
}
static int F_16 ( struct V_29 * V_30 ,
const struct V_1 * V_36 )
{
struct V_6 * V_7 = F_17 ( V_30 ) ;
const struct V_1 * V_37 = NULL ;
int V_28 ;
int V_5 = 0 ;
char V_38 [ 128 ] ;
V_5 = F_1 ( & V_37 ,
F_14 ( V_30 , V_38 , sizeof( V_38 ) , L_13 ) ,
& V_7 -> V_17 ) ;
if ( V_5 )
goto error;
V_5 = F_7 ( V_7 , V_37 -> V_10 , V_37 -> V_11 , V_39 , V_23 ) ;
if ( V_5 )
goto error;
V_28 = ( V_40 * sizeof( T_1 ) ) ;
V_5 = F_7 ( V_7 , V_36 -> V_10 + V_28 , V_36 -> V_11 - V_28 ,
V_41 + V_40 , V_23 ) ;
error:
F_18 ( V_37 ) ;
return V_5 ;
}
static int F_19 ( struct V_29 * V_30 )
{
int V_5 ;
T_1 V_42 ;
T_1 V_9 ;
struct V_6 * V_7 = F_17 ( V_30 ) ;
const struct V_1 * V_36 = NULL ;
const struct V_1 * V_43 = NULL ;
char V_38 [ 128 ] ;
V_9 = F_5 ( V_7 ) ;
V_5 = F_1 ( & V_36 ,
F_14 ( V_30 , V_38 , sizeof( V_38 ) , L_14 ) ,
& V_7 -> V_17 ) ;
if ( V_5 )
goto error;
V_42 = F_13 ( V_36 -> V_10 , V_44 ) ;
if ( V_42 != V_9 ) {
F_20 ( & V_7 -> V_17 ,
L_15
L_16 , V_42 , V_9 ) ;
if ( V_9 <= 0x4313 )
F_21 ( & V_7 -> V_17 , L_17
L_18 ) ;
V_5 = F_16 ( V_30 , V_36 ) ;
if ( V_5 )
goto error;
} else {
F_2 ( & V_7 -> V_17 ,
L_19
L_20 , V_42 ) ;
}
V_5 = F_1 ( & V_43 ,
F_14 ( V_30 , V_38 , sizeof( V_38 ) , L_21 ) ,
& V_7 -> V_17 ) ;
if ( V_5 )
goto error;
V_5 = F_7 ( V_7 , V_43 -> V_10 , V_43 -> V_11 , V_39 , V_23 ) ;
if ( V_5 ) {
F_4 ( & V_7 -> V_17 ,
L_22 ,
V_5 ) ;
}
error:
F_18 ( V_36 ) ;
F_18 ( V_43 ) ;
return V_5 ;
}
int F_22 ( struct V_29 * V_30 , T_5 V_45 , T_2 * V_10 , T_1 V_46 )
{
int V_5 ;
struct V_6 * V_7 = F_17 ( V_30 ) ;
T_2 * V_47 ;
V_47 = F_8 ( V_46 , V_16 ) ;
if ( ! V_47 )
return - V_18 ;
V_5 = F_9 ( V_7 , F_11 ( V_7 , 0 ) ,
V_48 , V_26 | 0x40 , V_45 , 0 ,
V_47 , V_46 , 5000 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_7 -> V_17 ,
L_23 , V_5 ) ;
goto exit;
} else if ( V_5 != V_46 ) {
F_4 ( & V_7 -> V_17 ,
L_24 ,
V_5 , V_46 ) ;
V_5 = - V_49 ;
goto exit;
}
V_5 = 0 ;
memcpy ( V_10 , V_47 , V_46 ) ;
exit:
F_12 ( V_47 ) ;
return V_5 ;
}
static inline void F_23 ( struct V_50 * V_50 )
{
struct V_29 * V_30 = V_50 -> V_51 ;
struct V_52 * V_53 = & V_30 -> V_53 ;
int V_46 ;
T_1 V_54 ;
F_24 ( F_25 () ) ;
F_26 ( & V_53 -> V_55 ) ;
V_54 = F_6 ( * ( T_4 * ) ( V_50 -> V_56 + 2 ) ) ;
if ( V_54 == V_57 ) {
struct V_58 * V_59 = F_27 ( F_28 ( V_50 -> V_51 ) ) ;
F_26 ( & V_59 -> V_55 ) ;
memcpy ( & V_59 -> V_60 , V_50 -> V_56 ,
V_61 ) ;
F_29 ( & V_59 -> V_55 ) ;
F_30 ( & V_59 -> V_62 ) ;
} else if ( V_53 -> V_63 ) {
V_53 -> V_64 . V_65 = V_46 = V_50 -> V_66 ;
if ( V_46 > sizeof( V_53 -> V_64 . V_31 ) )
V_46 = sizeof( V_53 -> V_64 . V_31 ) ;
memcpy ( V_53 -> V_64 . V_31 , V_50 -> V_56 , V_46 ) ;
V_53 -> V_63 = 0 ;
F_31 ( & V_53 -> V_64 . V_67 ) ;
goto V_68;
}
V_68:
F_29 ( & V_53 -> V_55 ) ;
}
static void F_32 ( struct V_50 * V_50 )
{
int V_5 ;
struct V_69 * V_70 ;
switch ( V_50 -> V_71 ) {
case 0 :
break;
case - V_72 :
case - V_73 :
case - V_27 :
case - V_74 :
case - V_75 :
case - V_76 :
F_2 ( F_33 ( V_50 ) , L_25 , V_50 , V_50 -> V_71 ) ;
return;
default:
F_2 ( F_33 ( V_50 ) , L_25 , V_50 , V_50 -> V_71 ) ;
goto V_77;
}
if ( V_50 -> V_66 < sizeof( V_70 ) ) {
F_2 ( F_33 ( V_50 ) , L_26 , V_50 ) ;
goto V_77;
}
V_70 = V_50 -> V_56 ;
if ( V_70 -> type != V_78 ) {
F_2 ( F_33 ( V_50 ) , L_27 , V_50 ) ;
goto V_77;
}
switch ( V_70 -> V_79 ) {
case V_80 :
F_23 ( V_50 ) ;
break;
case V_81 :
F_34 ( V_50 ) ;
break;
default:
F_2 ( F_33 ( V_50 ) , L_28 , V_50 ,
( unsigned int ) V_70 -> V_79 ) ;
goto V_77;
}
V_77:
V_5 = F_35 ( V_50 , V_82 ) ;
if ( V_5 ) {
F_2 ( F_33 ( V_50 ) , L_29 ,
V_50 , V_5 ) ;
}
return;
}
static inline int F_36 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_83 ) {
case V_84 :
return 4 ;
case V_85 :
return 10 ;
case V_86 :
default:
return 1 ;
}
}
static inline int F_37 ( struct V_29 * V_30 )
{
unsigned long V_13 ;
struct V_52 * V_53 = & V_30 -> V_53 ;
struct V_50 * V_50 ;
F_38 ( & V_53 -> V_55 , V_13 ) ;
V_50 = V_53 -> V_50 ;
F_39 ( & V_53 -> V_55 , V_13 ) ;
return V_50 != NULL ;
}
int F_40 ( struct V_29 * V_30 )
{
int V_5 ;
struct V_6 * V_7 = F_17 ( V_30 ) ;
struct V_52 * V_53 = & V_30 -> V_53 ;
struct V_50 * V_50 ;
F_2 ( F_41 ( V_30 ) , L_30 ) ;
V_50 = F_42 ( 0 , V_16 ) ;
if ( ! V_50 ) {
V_5 = - V_18 ;
goto V_68;
}
F_24 ( ! F_43 () ) ;
F_44 ( & V_53 -> V_55 ) ;
if ( V_53 -> V_50 ) {
F_45 ( & V_53 -> V_55 ) ;
V_5 = 0 ;
goto V_87;
}
V_53 -> V_50 = V_50 ;
F_45 ( & V_53 -> V_55 ) ;
V_5 = - V_18 ;
V_53 -> V_31 = F_46 ( V_7 , V_61 ,
V_16 , & V_53 -> V_88 ) ;
if ( ! V_53 -> V_31 ) {
F_2 ( F_41 ( V_30 ) ,
L_31 ) ;
goto V_89;
}
F_47 ( V_50 , V_7 , F_48 ( V_7 , V_90 ) ,
V_53 -> V_31 , V_61 ,
F_32 , V_30 ,
V_53 -> V_91 ) ;
V_50 -> V_92 = V_53 -> V_88 ;
V_50 -> V_93 |= V_94 ;
F_2 ( F_41 ( V_30 ) , L_32 , V_53 -> V_50 ) ;
V_5 = F_35 ( V_50 , V_16 ) ;
if ( V_5 ) {
F_2 ( F_41 ( V_30 ) ,
L_33 , V_5 ) ;
goto error;
}
return 0 ;
error:
F_49 ( V_7 , V_61 ,
V_53 -> V_31 , V_53 -> V_88 ) ;
V_89:
F_44 ( & V_53 -> V_55 ) ;
V_53 -> V_50 = NULL ;
F_45 ( & V_53 -> V_55 ) ;
V_87:
F_50 ( V_50 ) ;
V_68:
return V_5 ;
}
void F_51 ( struct V_29 * V_30 )
{
unsigned long V_13 ;
struct V_6 * V_7 = F_17 ( V_30 ) ;
struct V_52 * V_53 = & V_30 -> V_53 ;
struct V_50 * V_50 ;
void * V_31 ;
T_6 V_88 ;
F_38 ( & V_53 -> V_55 , V_13 ) ;
V_50 = V_53 -> V_50 ;
if ( ! V_50 ) {
F_39 ( & V_53 -> V_55 , V_13 ) ;
return;
}
V_53 -> V_50 = NULL ;
V_31 = V_53 -> V_31 ;
V_88 = V_53 -> V_88 ;
V_53 -> V_31 = NULL ;
F_39 ( & V_53 -> V_55 , V_13 ) ;
F_52 ( V_50 ) ;
F_2 ( F_41 ( V_30 ) , L_34 , V_50 ) ;
F_50 ( V_50 ) ;
if ( V_31 )
F_49 ( V_7 , V_61 ,
V_31 , V_88 ) ;
}
static void F_53 ( struct V_29 * V_30 , const T_2 * V_31 ,
unsigned int V_65 )
{
int V_95 ;
const struct V_96 * V_97 ;
if ( V_65 < sizeof( struct V_96 ) ) {
F_54 ( L_35 ,
V_98 , V_65 ) ;
return;
}
V_97 = (struct V_96 * )
( V_31 + V_65 - sizeof( struct V_96 ) ) ;
if ( F_55 ( & V_97 -> V_99 ) == V_100 )
{
unsigned int V_101 , V_102 , V_103 ;
for ( V_95 = 0 , V_101 = 0 ; ; V_95 ++ ) {
V_102 = F_55 ( & V_97 -> V_65 [ V_95 ] ) ;
if ( V_102 == 0 )
return;
V_103 = V_101 + V_102 ;
if ( V_103 > V_65 )
return;
F_56 ( F_28 ( V_30 ) , V_31 + V_101 , V_102 ) ;
if ( V_95 >= 2 )
return;
V_101 = ( V_103 + 3 ) & ~ 3 ;
}
} else {
F_56 ( F_28 ( V_30 ) , V_31 , V_65 ) ;
}
}
static void F_57 ( struct V_50 * V_50 )
{
int V_5 ;
struct V_29 * V_30 ;
struct V_104 * V_105 ;
const T_2 * V_31 ;
unsigned int V_65 ;
switch ( V_50 -> V_71 ) {
case 0 :
break;
case - V_72 :
case - V_73 :
case - V_27 :
case - V_74 :
case - V_75 :
case - V_76 :
F_2 ( F_33 ( V_50 ) , L_25 , V_50 , V_50 -> V_71 ) ;
return;
default:
F_2 ( F_33 ( V_50 ) , L_25 , V_50 , V_50 -> V_71 ) ;
goto V_77;
}
V_31 = V_50 -> V_56 ;
V_65 = V_50 -> V_66 ;
V_30 = V_50 -> V_51 ;
V_105 = & V_30 -> V_105 ;
F_58 ( & V_105 -> V_106 ) ;
if ( V_65 % V_105 -> V_107 > V_105 -> V_107 - 4 ) {
F_2 ( F_33 ( V_50 ) , L_36 ) ;
F_24 ( V_65 <= F_59 ( V_105 -> V_108 ) ) ;
F_26 ( & V_105 -> V_55 ) ;
memcpy ( V_105 -> V_108 , V_31 , V_65 ) ;
V_105 -> V_109 = V_65 ;
F_29 ( & V_105 -> V_55 ) ;
goto V_77;
}
F_26 ( & V_105 -> V_55 ) ;
if ( V_105 -> V_109 > 0 ) {
F_24 ( V_65 + V_105 -> V_109 <=
F_59 ( V_105 -> V_108 ) ) ;
F_2 ( F_33 ( V_50 ) , L_37 ) ;
memcpy ( V_105 -> V_108 + V_105 -> V_109 , V_31 , V_65 ) ;
F_53 ( V_30 , V_105 -> V_108 ,
V_105 -> V_109 + V_65 ) ;
V_105 -> V_109 = 0 ;
F_29 ( & V_105 -> V_55 ) ;
} else {
F_29 ( & V_105 -> V_55 ) ;
F_53 ( V_30 , V_31 , V_65 ) ;
}
V_77:
V_5 = F_35 ( V_50 , V_82 ) ;
if ( V_5 )
F_2 ( F_33 ( V_50 ) , L_38 , V_50 , V_5 ) ;
}
static struct V_50 * F_60 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = F_17 ( V_30 ) ;
struct V_50 * V_50 ;
void * V_31 ;
V_50 = F_42 ( 0 , V_16 ) ;
if ( ! V_50 )
return NULL ;
V_31 = F_46 ( V_7 , V_110 , V_16 ,
& V_50 -> V_92 ) ;
if ( ! V_31 ) {
F_50 ( V_50 ) ;
return NULL ;
}
F_61 ( V_50 , V_7 , F_62 ( V_7 , V_111 ) ,
V_31 , V_110 ,
F_57 , V_30 ) ;
V_50 -> V_93 |= V_94 ;
return V_50 ;
}
static void F_63 ( struct V_50 * V_50 )
{
if ( ! V_50 )
return;
F_49 ( V_50 -> V_17 , V_50 -> V_112 ,
V_50 -> V_56 , V_50 -> V_92 ) ;
F_50 ( V_50 ) ;
}
static int F_64 ( struct V_29 * V_30 )
{
int V_95 , V_5 ;
struct V_104 * V_105 = & V_30 -> V_105 ;
struct V_50 * * V_113 ;
F_2 ( F_41 ( V_30 ) , L_30 ) ;
V_5 = - V_18 ;
V_113 = F_65 ( V_114 , sizeof( struct V_50 * ) , V_16 ) ;
if ( ! V_113 )
goto error;
for ( V_95 = 0 ; V_95 < V_114 ; V_95 ++ ) {
V_113 [ V_95 ] = F_60 ( V_30 ) ;
if ( ! V_113 [ V_95 ] )
goto error;
}
F_24 ( ! F_43 () ) ;
F_44 ( & V_105 -> V_55 ) ;
if ( V_105 -> V_113 ) {
F_45 ( & V_105 -> V_55 ) ;
V_5 = 0 ;
goto error;
}
V_105 -> V_113 = V_113 ;
V_105 -> V_115 = V_114 ;
F_45 ( & V_105 -> V_55 ) ;
for ( V_95 = 0 ; V_95 < V_114 ; V_95 ++ ) {
V_5 = F_35 ( V_113 [ V_95 ] , V_16 ) ;
if ( V_5 )
goto V_116;
}
return 0 ;
V_116:
for ( V_95 = 0 ; V_95 < V_114 ; V_95 ++ ) {
F_52 ( V_113 [ V_95 ] ) ;
}
F_44 ( & V_105 -> V_55 ) ;
V_105 -> V_113 = NULL ;
V_105 -> V_115 = 0 ;
F_45 ( & V_105 -> V_55 ) ;
error:
if ( V_113 ) {
for ( V_95 = 0 ; V_95 < V_114 ; V_95 ++ )
F_63 ( V_113 [ V_95 ] ) ;
}
return V_5 ;
}
int F_66 ( struct V_29 * V_30 )
{
int V_5 ;
struct V_104 * V_105 = & V_30 -> V_105 ;
F_67 ( & V_105 -> V_117 ) ;
V_5 = F_64 ( V_30 ) ;
F_68 ( & V_105 -> V_117 ) ;
F_69 ( V_30 ) ;
return V_5 ;
}
static void F_70 ( struct V_29 * V_30 )
{
int V_95 ;
unsigned long V_13 ;
struct V_50 * * V_113 ;
unsigned int V_118 ;
struct V_104 * V_105 = & V_30 -> V_105 ;
F_38 ( & V_105 -> V_55 , V_13 ) ;
V_113 = V_105 -> V_113 ;
V_118 = V_105 -> V_115 ;
F_39 ( & V_105 -> V_55 , V_13 ) ;
if ( ! V_113 )
return;
for ( V_95 = 0 ; V_95 < V_118 ; V_95 ++ ) {
F_52 ( V_113 [ V_95 ] ) ;
F_63 ( V_113 [ V_95 ] ) ;
}
F_12 ( V_113 ) ;
F_38 ( & V_105 -> V_55 , V_13 ) ;
V_105 -> V_113 = NULL ;
V_105 -> V_115 = 0 ;
F_39 ( & V_105 -> V_55 , V_13 ) ;
}
void F_71 ( struct V_29 * V_30 )
{
struct V_104 * V_105 = & V_30 -> V_105 ;
F_67 ( & V_105 -> V_117 ) ;
F_70 ( V_30 ) ;
F_68 ( & V_105 -> V_117 ) ;
F_72 ( & V_105 -> V_106 ) ;
F_73 ( & V_105 -> V_119 ) ;
}
static void F_74 ( struct V_29 * V_30 )
{
bool V_120 ;
struct V_104 * V_105 = & V_30 -> V_105 ;
unsigned long V_13 ;
F_67 ( & V_105 -> V_117 ) ;
F_38 ( & V_105 -> V_55 , V_13 ) ;
V_120 = V_105 -> V_113 != NULL ;
F_39 ( & V_105 -> V_55 , V_13 ) ;
if ( V_120 ) {
F_70 ( V_30 ) ;
F_64 ( V_30 ) ;
}
F_68 ( & V_105 -> V_117 ) ;
if ( V_120 )
F_69 ( V_30 ) ;
}
void F_75 ( struct V_29 * V_30 )
{
struct V_121 * V_122 = & V_30 -> V_122 ;
unsigned long V_13 ;
F_76 ( & V_122 -> V_123 , 0 ) ;
F_77 ( & V_122 -> V_124 ) ;
F_38 ( & V_122 -> V_55 , V_13 ) ;
F_78 ( ! F_79 ( & V_122 -> V_125 ) ) ;
F_78 ( V_122 -> V_126 != 0 ) ;
V_122 -> V_126 = 0 ;
F_39 ( & V_122 -> V_55 , V_13 ) ;
}
void F_80 ( struct V_29 * V_30 )
{
unsigned long V_13 ;
struct V_121 * V_122 = & V_30 -> V_122 ;
F_38 ( & V_122 -> V_55 , V_13 ) ;
F_76 ( & V_122 -> V_123 , 1 ) ;
V_122 -> V_126 = 0 ;
F_81 ( F_28 ( V_30 ) ) ;
V_122 -> V_127 = 0 ;
F_39 ( & V_122 -> V_55 , V_13 ) ;
}
static void F_82 ( struct V_29 * V_30 )
{
struct V_121 * V_122 = & V_30 -> V_122 ;
unsigned long V_13 ;
F_38 ( & V_122 -> V_55 , V_13 ) ;
-- V_122 -> V_126 ;
if ( V_122 -> V_127 && V_122 -> V_126 <= V_128 ) {
F_81 ( F_28 ( V_30 ) ) ;
V_122 -> V_127 = 0 ;
}
F_39 ( & V_122 -> V_55 , V_13 ) ;
}
static void F_83 ( struct V_29 * V_30 )
{
struct V_121 * V_122 = & V_30 -> V_122 ;
unsigned long V_13 ;
F_38 ( & V_122 -> V_55 , V_13 ) ;
++ V_122 -> V_126 ;
if ( ! V_122 -> V_127 && V_122 -> V_126 > V_129 ) {
F_84 ( F_28 ( V_30 ) ) ;
V_122 -> V_127 = 1 ;
}
F_39 ( & V_122 -> V_55 , V_13 ) ;
}
static void F_85 ( struct V_50 * V_50 )
{
int V_5 ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
struct V_29 * V_30 ;
struct V_121 * V_122 ;
V_131 = (struct V_130 * ) V_50 -> V_51 ;
V_133 = F_86 ( V_131 ) ;
V_30 = & F_27 ( V_133 -> V_134 [ 0 ] ) -> V_135 . V_30 ;
V_122 = & V_30 -> V_122 ;
switch ( V_50 -> V_71 ) {
case 0 :
break;
case - V_72 :
case - V_73 :
case - V_27 :
case - V_74 :
case - V_75 :
case - V_76 :
F_2 ( F_33 ( V_50 ) , L_25 , V_50 , V_50 -> V_71 ) ;
break;
default:
F_2 ( F_33 ( V_50 ) , L_25 , V_50 , V_50 -> V_71 ) ;
goto V_77;
}
V_136:
F_87 ( V_131 , & V_30 -> V_122 . V_125 ) ;
F_88 ( V_131 , V_50 -> V_71 ) ;
F_50 ( V_50 ) ;
F_82 ( V_30 ) ;
return;
V_77:
F_89 ( V_50 , & V_122 -> V_124 ) ;
V_5 = F_35 ( V_50 , V_82 ) ;
if ( V_5 ) {
F_90 ( V_50 ) ;
F_2 ( F_33 ( V_50 ) , L_39 , V_50 , V_5 ) ;
goto V_136;
}
}
int V_121 ( struct V_29 * V_30 , struct V_130 * V_131 )
{
int V_5 ;
struct V_132 * V_133 = F_86 ( V_131 ) ;
struct V_6 * V_7 = F_17 ( V_30 ) ;
struct V_50 * V_50 ;
struct V_121 * V_122 = & V_30 -> V_122 ;
if ( ! F_91 ( & V_122 -> V_123 ) ) {
V_5 = - V_74 ;
goto V_68;
}
V_50 = F_42 ( 0 , V_82 ) ;
if ( ! V_50 ) {
V_5 = - V_18 ;
goto V_68;
}
F_61 ( V_50 , V_7 , F_92 ( V_7 , V_137 ) ,
V_131 -> V_10 , V_131 -> V_46 , F_85 , V_131 ) ;
V_133 -> V_134 [ 1 ] = ( void * ) V_138 ;
F_93 ( & V_122 -> V_125 , V_131 ) ;
F_89 ( V_50 , & V_122 -> V_124 ) ;
V_5 = F_35 ( V_50 , V_82 ) ;
if ( V_5 ) {
F_2 ( F_41 ( V_30 ) , L_40 , V_50 , V_5 ) ;
F_90 ( V_50 ) ;
F_87 ( V_131 , & V_122 -> V_125 ) ;
goto error;
}
F_83 ( V_30 ) ;
return 0 ;
error:
F_50 ( V_50 ) ;
V_68:
return V_5 ;
}
static bool F_94 ( struct V_29 * V_30 )
{
struct V_121 * V_122 = & V_30 -> V_122 ;
struct V_139 * V_140 = & V_122 -> V_125 ;
struct V_130 * V_131 , * V_141 ;
struct V_132 * V_133 ;
unsigned long V_13 , V_142 ;
bool V_143 = false ;
F_38 ( & V_140 -> V_55 , V_13 ) ;
F_95 (q, skb, skbnext) {
V_133 = F_86 ( V_131 ) ;
V_142 = ( unsigned long ) V_133 -> V_134 [ 1 ] ;
if ( F_96 ( V_142 + V_144 ) ) {
V_143 = true ;
break;
}
}
F_39 ( & V_140 -> V_55 , V_13 ) ;
return V_143 ;
}
static void F_97 ( struct V_145 * V_146 )
{
struct V_29 * V_30 =
F_98 ( V_146 , struct V_29 , V_122 . V_147 . V_146 ) ;
struct V_121 * V_122 = & V_30 -> V_122 ;
if ( ! F_91 ( & V_122 -> V_123 ) || ! V_122 -> V_148 )
goto V_68;
if ( ! F_94 ( V_30 ) )
goto V_68;
F_21 ( F_41 ( V_30 ) , L_41 ) ;
F_99 ( V_30 -> V_149 ) ;
return;
V_68:
F_100 ( V_150 , & V_122 -> V_147 ,
V_151 ) ;
}
void F_101 ( struct V_29 * V_30 )
{
struct V_121 * V_122 = & V_30 -> V_122 ;
if ( ! V_122 -> V_148 ) {
F_2 ( F_41 ( V_30 ) , L_30 ) ;
F_100 ( V_150 , & V_122 -> V_147 ,
V_151 ) ;
V_122 -> V_148 = 1 ;
}
}
void F_102 ( struct V_29 * V_30 )
{
struct V_121 * V_122 = & V_30 -> V_122 ;
if ( V_122 -> V_148 ) {
F_2 ( F_41 ( V_30 ) , L_30 ) ;
V_122 -> V_148 = 0 ;
F_73 ( & V_122 -> V_147 ) ;
}
}
static void F_103 ( struct V_145 * V_146 )
{
struct V_29 * V_30 =
F_98 ( V_146 , struct V_29 , V_105 . V_119 . V_146 ) ;
struct V_58 * V_59 = F_104 ( V_30 ) ;
if ( ! F_105 ( V_152 , & V_59 -> V_13 ) )
return;
F_2 ( F_41 ( V_30 ) , L_30 ) ;
F_74 ( V_30 ) ;
}
static void F_106 ( unsigned long V_153 )
{
struct V_29 * V_30 = (struct V_29 * ) V_153 ;
F_69 ( V_30 ) ;
}
void F_69 ( struct V_29 * V_30 )
{
struct V_104 * V_105 = & V_30 -> V_105 ;
F_107 ( & V_105 -> V_119 ) ;
F_100 ( V_150 , & V_105 -> V_119 , V_154 ) ;
}
static inline void F_108 ( struct V_29 * V_30 )
{
struct V_52 * V_53 = & V_30 -> V_53 ;
F_109 ( & V_53 -> V_55 ) ;
V_53 -> V_91 = F_36 ( F_17 ( V_30 ) ) ;
F_110 ( & V_53 -> V_64 . V_67 ) ;
V_53 -> V_64 . V_155 = F_111 ( ( T_1 ) V_57 ) ;
}
static inline void F_112 ( struct V_29 * V_30 )
{
struct V_104 * V_105 = & V_30 -> V_105 ;
F_109 ( & V_105 -> V_55 ) ;
F_113 ( & V_105 -> V_117 ) ;
if ( F_114 ( V_30 -> V_149 ) -> V_83 == V_84 ) {
V_105 -> V_107 = 512 ;
} else {
V_105 -> V_107 = 64 ;
}
F_24 ( V_105 -> V_109 == 0 ) ;
F_115 ( & V_105 -> V_119 , F_103 ) ;
V_105 -> V_106 . V_156 = F_106 ;
V_105 -> V_106 . V_10 = ( unsigned long ) V_30 ;
}
static inline void F_116 ( struct V_29 * V_30 )
{
struct V_121 * V_122 = & V_30 -> V_122 ;
F_109 ( & V_122 -> V_55 ) ;
F_76 ( & V_122 -> V_123 , 0 ) ;
V_122 -> V_127 = 0 ;
F_117 ( & V_122 -> V_125 ) ;
F_118 ( & V_122 -> V_124 ) ;
V_122 -> V_126 = 0 ;
V_122 -> V_148 = 0 ;
F_115 ( & V_122 -> V_147 , F_97 ) ;
}
void F_119 ( struct V_29 * V_30 , struct V_157 * V_158 ,
struct V_159 * V_149 )
{
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_149 = F_120 ( V_149 ) ;
F_121 ( V_30 -> V_149 , V_158 ) ;
F_118 ( & V_30 -> V_160 ) ;
F_108 ( V_30 ) ;
F_116 ( V_30 ) ;
F_112 ( V_30 ) ;
}
void F_122 ( struct V_29 * V_30 )
{
F_121 ( V_30 -> V_149 , NULL ) ;
F_123 ( V_30 -> V_149 ) ;
F_124 ( V_30 , sizeof( * V_30 ) ) ;
}
static const char * V_83 ( enum V_161 V_83 )
{
switch ( V_83 ) {
case V_85 :
return L_42 ;
case V_86 :
return L_43 ;
case V_84 :
return L_44 ;
default:
return L_45 ;
}
}
static int F_125 ( struct V_6 * V_7 , char * V_31 , T_3 V_11 )
{
return F_15 ( V_31 , V_11 , L_46 ,
F_6 ( V_7 -> V_8 . V_162 ) ,
F_6 ( V_7 -> V_8 . V_163 ) ,
F_5 ( V_7 ) ,
V_83 ( V_7 -> V_83 ) ) ;
}
int F_126 ( struct V_29 * V_30 , char * V_31 , T_3 V_11 )
{
struct V_6 * V_7 = F_114 ( V_30 -> V_149 ) ;
return F_125 ( V_7 , V_31 , V_11 ) ;
}
static void F_127 ( struct V_6 * V_7 )
{
char V_31 [ 40 ] ;
F_125 ( V_7 , V_31 , sizeof( V_31 ) ) ;
V_31 [ sizeof( V_31 ) - 1 ] = 0 ;
F_2 ( & V_7 -> V_17 , L_47 , V_31 ) ;
}
static int F_128 ( struct V_159 * V_149 )
{
struct V_6 * V_7 = F_114 ( V_149 ) ;
struct V_164 * V_165 = & V_149 -> V_166 [ 0 ] ;
struct V_167 * V_168 ;
unsigned char * V_169 ;
T_2 V_170 ;
int V_5 ;
for ( V_5 = 1 ; V_5 >= 0 ; V_5 -- ) {
V_168 = & V_165 -> V_168 [ V_5 ] . V_171 ;
if ( F_129 ( V_168 ) &&
F_130 ( V_168 ) ) {
V_170 = V_168 -> V_172 ;
break;
}
}
if ( V_5 == - 1 ) {
F_4 ( & V_7 -> V_17 ,
L_48 ) ;
return - V_27 ;
}
V_169 = F_131 ( 31 , V_16 ) ;
if ( V_169 == NULL )
return - V_27 ;
V_169 [ 0 ] = 0x55 ;
V_169 [ 1 ] = 0x53 ;
V_169 [ 2 ] = 0x42 ;
V_169 [ 3 ] = 0x43 ;
V_169 [ 14 ] = 6 ;
V_169 [ 15 ] = 0x1b ;
V_169 [ 19 ] = 0x2 ;
F_20 ( & V_7 -> V_17 , L_49 ) ;
V_5 = F_132 ( V_7 , F_92 ( V_7 , V_170 ) ,
V_169 , 31 , NULL , 2000 ) ;
F_12 ( V_169 ) ;
if ( V_5 )
return V_5 ;
F_121 ( V_149 , NULL ) ;
return 0 ;
}
int F_133 ( struct V_29 * V_30 )
{
int V_5 ;
struct V_58 * V_59 = F_104 ( V_30 ) ;
F_2 ( F_41 ( V_30 ) , L_30 ) ;
V_5 = F_19 ( V_30 ) ;
if ( V_5 ) {
F_4 ( F_41 ( V_30 ) ,
L_50 , V_5 ) ;
return V_5 ;
}
V_5 = F_134 ( F_17 ( V_30 ) ) ;
if ( V_5 ) {
F_2 ( F_41 ( V_30 ) ,
L_51 , V_5 ) ;
return V_5 ;
}
V_5 = F_135 ( V_59 -> V_158 ) ;
if ( V_5 ) {
F_2 ( F_41 ( V_30 ) ,
L_52 , V_5 ) ;
return V_5 ;
}
V_30 -> V_173 = 1 ;
return 0 ;
}
static int F_136 ( struct V_159 * V_149 , const struct V_174 * V_79 )
{
int V_5 ;
struct V_6 * V_7 = F_114 ( V_149 ) ;
struct V_29 * V_30 ;
struct V_157 * V_158 = NULL ;
F_127 ( V_7 ) ;
if ( V_79 -> V_175 & V_176 )
return F_128 ( V_149 ) ;
switch ( V_7 -> V_83 ) {
case V_85 :
case V_86 :
case V_84 :
break;
default:
F_2 ( & V_149 -> V_17 , L_53 ) ;
V_5 = - V_27 ;
goto error;
}
V_5 = F_137 ( V_7 ) ;
if ( V_5 ) {
F_4 ( & V_149 -> V_17 ,
L_54 , V_5 ) ;
goto error;
}
V_158 = F_138 ( V_149 ) ;
if ( V_158 == NULL ) {
V_5 = - V_18 ;
goto error;
}
V_30 = & F_27 ( V_158 ) -> V_135 . V_30 ;
V_30 -> V_33 = ( V_79 -> V_175 == V_177 ) != 0 ;
V_5 = F_139 ( V_158 ) ;
if ( V_5 ) {
F_2 ( & V_149 -> V_17 ,
L_52 , V_5 ) ;
goto error;
}
V_5 = F_140 ( V_158 ) ;
if ( V_5 ) {
F_2 ( & V_149 -> V_17 ,
L_55 , V_5 ) ;
goto error;
}
F_2 ( & V_149 -> V_17 , L_56 ) ;
F_20 ( & V_149 -> V_17 , L_47 , F_141 ( V_158 -> V_178 ) ) ;
return 0 ;
error:
F_137 ( F_114 ( V_149 ) ) ;
if ( V_158 ) {
F_142 ( F_27 ( V_158 ) ) ;
F_143 ( V_158 ) ;
}
return V_5 ;
}
static void F_144 ( struct V_159 * V_149 )
{
struct V_157 * V_158 = F_145 ( V_149 ) ;
struct V_58 * V_59 ;
struct V_29 * V_30 ;
if ( V_158 == NULL )
return;
V_59 = F_27 ( V_158 ) ;
V_30 = & V_59 -> V_135 . V_30 ;
F_2 ( F_41 ( V_30 ) , L_30 ) ;
F_146 ( V_158 ) ;
F_75 ( V_30 ) ;
F_71 ( V_30 ) ;
F_51 ( V_30 ) ;
F_137 ( F_114 ( V_149 ) ) ;
F_142 ( V_59 ) ;
F_143 ( V_158 ) ;
F_147 ( & V_149 -> V_17 , L_57 ) ;
}
static void F_148 ( struct V_29 * V_30 )
{
struct V_58 * V_59 = F_104 ( V_30 ) ;
int V_5 ;
F_2 ( F_41 ( V_30 ) , L_30 ) ;
V_5 = F_149 ( F_28 ( V_30 ) ) ;
if ( V_5 < 0 ) {
F_21 ( F_41 ( V_30 ) , L_58
L_59 , V_5 ) ;
if ( V_30 -> V_179 )
F_150 ( V_152 , & V_59 -> V_13 ) ;
F_99 ( V_30 -> V_149 ) ;
return;
}
if ( V_59 -> type != V_180 ) {
V_5 = F_151 ( V_59 ) ;
if ( V_5 < 0 ) {
F_147 ( F_41 ( V_30 ) ,
L_60 , V_5 ) ;
return;
}
}
}
static void F_152 ( struct V_29 * V_30 )
{
F_2 ( F_41 ( V_30 ) , L_30 ) ;
F_153 ( F_28 ( V_30 ) ) ;
F_75 ( V_30 ) ;
F_71 ( V_30 ) ;
F_51 ( V_30 ) ;
V_30 -> V_173 = 0 ;
}
static int F_154 ( struct V_159 * V_149 )
{
struct V_157 * V_158 = F_155 ( V_149 ) ;
struct V_58 * V_59 ;
struct V_29 * V_30 ;
if ( ! V_158 || V_149 -> V_181 != V_182 )
return 0 ;
V_59 = F_27 ( V_158 ) ;
V_30 = & V_59 -> V_135 . V_30 ;
V_30 -> V_179 = F_105 ( V_152 , & V_59 -> V_13 ) ;
F_152 ( V_30 ) ;
F_67 ( & V_59 -> V_135 . V_183 ) ;
return 0 ;
}
static int F_156 ( struct V_159 * V_149 )
{
struct V_157 * V_158 = F_155 ( V_149 ) ;
struct V_58 * V_59 ;
struct V_29 * V_30 ;
if ( ! V_158 || V_149 -> V_181 != V_182 )
return 0 ;
V_59 = F_27 ( V_158 ) ;
V_30 = & V_59 -> V_135 . V_30 ;
F_68 ( & V_59 -> V_135 . V_183 ) ;
if ( V_30 -> V_179 )
F_148 ( V_30 ) ;
return 0 ;
}
static int T_7 F_157 ( void )
{
int V_5 ;
F_158 ( L_61 , V_184 . V_3 ) ;
V_150 = F_159 ( V_184 . V_3 ) ;
if ( V_150 == NULL ) {
F_54 ( V_185 L_62 , V_184 . V_3 ) ;
return - V_18 ;
}
V_5 = F_160 ( & V_184 ) ;
if ( V_5 ) {
F_161 ( V_150 ) ;
F_54 ( V_185 L_63 ,
V_184 . V_3 , V_5 ) ;
return V_5 ;
}
F_158 ( L_64 , V_184 . V_3 ) ;
return 0 ;
}
static void T_8 F_162 ( void )
{
F_158 ( L_65 , V_184 . V_3 ) ;
F_163 ( & V_184 ) ;
F_161 ( V_150 ) ;
}
static int F_164 ( struct V_6 * V_7 , void * V_10 , int V_46 ,
int * V_66 , int V_186 )
{
struct V_187 * V_188 ;
unsigned int V_189 ;
V_189 = F_165 ( V_7 , V_190 ) ;
V_188 = F_166 ( V_7 , V_189 ) ;
if ( ! V_188 )
return - V_73 ;
if ( F_167 ( & V_188 -> V_171 ) ) {
return F_168 ( V_7 , V_189 , V_10 , V_46 ,
V_66 , V_186 ) ;
} else {
V_189 = F_92 ( V_7 , V_190 ) ;
return F_132 ( V_7 , V_189 , V_10 , V_46 , V_66 ,
V_186 ) ;
}
}
static int F_169 ( unsigned int V_118 )
{
return sizeof( struct V_191 ) + V_118 * sizeof( struct V_192 ) ;
}
static void F_170 ( struct V_29 * V_30 )
{
struct V_52 * V_53 = & V_30 -> V_53 ;
F_44 ( & V_53 -> V_55 ) ;
V_53 -> V_63 = 1 ;
F_171 ( V_53 -> V_64 . V_67 ) ;
F_45 ( & V_53 -> V_55 ) ;
}
static void F_172 ( struct V_29 * V_30 )
{
struct V_52 * V_53 = & V_30 -> V_53 ;
F_44 ( & V_53 -> V_55 ) ;
V_53 -> V_63 = 0 ;
F_45 ( & V_53 -> V_55 ) ;
}
static int F_173 ( struct V_29 * V_30 , T_1 * V_193 ,
struct V_194 * V_195 , unsigned int V_118 )
{
int V_5 ;
int V_95 ;
struct V_52 * V_53 = & V_30 -> V_53 ;
struct V_196 * V_197 = & V_53 -> V_64 ;
struct V_191 * V_198 = (struct V_191 * ) V_197 -> V_31 ;
F_44 ( & V_53 -> V_55 ) ;
V_5 = - V_49 ;
if ( V_197 -> V_65 < F_169 ( V_118 ) ) {
F_2 ( F_41 ( V_30 ) ,
L_66 ,
V_197 -> V_65 , F_169 ( V_118 ) ) ;
goto V_199;
}
if ( V_197 -> V_65 > sizeof( V_197 -> V_31 ) ) {
F_2 ( F_41 ( V_30 ) ,
L_67 ,
V_197 -> V_65 , sizeof( V_197 -> V_31 ) ) ;
goto V_199;
}
for ( V_95 = 0 ; V_95 < V_118 ; V_95 ++ ) {
struct V_192 * V_200 = & V_198 -> V_198 [ V_95 ] ;
if ( V_200 -> V_45 != V_195 -> V_45 [ V_95 ] ) {
F_2 ( F_41 ( V_30 ) ,
L_68 , V_95 ,
F_6 ( V_200 -> V_45 ) ,
F_6 ( V_195 -> V_45 [ V_95 ] ) ) ;
goto V_199;
}
V_193 [ V_95 ] = F_6 ( V_200 -> V_201 ) ;
}
V_5 = 0 ;
V_199:
F_45 ( & V_53 -> V_55 ) ;
return V_5 ;
}
int F_174 ( struct V_29 * V_30 , T_1 * V_193 ,
const T_5 * V_202 , unsigned int V_118 )
{
int V_5 ;
int V_95 , V_203 , V_204 ;
struct V_6 * V_7 ;
struct V_194 * V_195 = NULL ;
unsigned long V_186 ;
if ( V_118 < 1 ) {
F_2 ( F_41 ( V_30 ) , L_69 ) ;
return - V_73 ;
}
if ( V_118 > V_205 ) {
F_2 ( F_41 ( V_30 ) ,
L_70 ,
V_118 , V_205 ) ;
return - V_73 ;
}
if ( F_175 () ) {
F_2 ( F_41 ( V_30 ) ,
L_71 ) ;
return - V_206 ;
}
if ( ! F_37 ( V_30 ) ) {
F_2 ( F_41 ( V_30 ) ,
L_72 ) ;
return - V_206 ;
}
F_24 ( F_176 ( & F_177 ( V_30 ) -> V_183 ) ) ;
F_178 ( sizeof( struct V_194 ) + V_205 *
sizeof( T_4 ) > sizeof( V_30 -> V_207 ) ) ;
F_179 ( sizeof( struct V_194 ) + V_118 * sizeof( T_4 ) >
sizeof( V_30 -> V_207 ) ) ;
V_203 = sizeof( struct V_194 ) + V_118 * sizeof( T_4 ) ;
V_195 = ( void * ) V_30 -> V_207 ;
V_195 -> V_79 = F_111 ( V_208 ) ;
for ( V_95 = 0 ; V_95 < V_118 ; V_95 ++ )
V_195 -> V_45 [ V_95 ] = F_111 ( ( T_1 ) V_202 [ V_95 ] ) ;
V_7 = F_17 ( V_30 ) ;
F_170 ( V_30 ) ;
V_5 = F_164 ( V_7 , V_195 , V_203 , & V_204 , 50 ) ;
if ( V_5 ) {
F_2 ( F_41 ( V_30 ) ,
L_73 , V_5 ) ;
goto error;
}
if ( V_203 != V_204 ) {
F_2 ( F_41 ( V_30 ) , L_74
L_75 ,
V_203 , V_204 ) ;
V_5 = - V_49 ;
goto error;
}
V_186 = F_180 ( & V_30 -> V_53 . V_64 . V_67 ,
F_181 ( 50 ) ) ;
if ( ! V_186 ) {
F_172 ( V_30 ) ;
F_2 ( F_41 ( V_30 ) , L_76 ) ;
V_5 = - V_209 ;
goto error;
}
V_5 = F_173 ( V_30 , V_193 , V_195 , V_118 ) ;
error:
return V_5 ;
}
static void F_182 ( struct V_50 * V_50 )
{
struct V_29 * V_30 = V_50 -> V_51 ;
if ( V_50 -> V_71 && ! V_30 -> V_210 )
V_30 -> V_210 = V_50 -> V_71 ;
if ( ! V_30 -> V_210 &&
V_50 -> V_66 != V_50 -> V_112 )
V_30 -> V_210 = - V_49 ;
}
static int F_183 ( struct V_29 * V_30 , bool V_211 )
{
int V_5 = 0 ;
struct V_50 * V_50 = V_30 -> V_212 ;
if ( ! V_50 )
return 0 ;
V_30 -> V_212 = NULL ;
if ( ! V_211 )
V_50 -> V_93 |= V_213 ;
F_89 ( V_50 , & V_30 -> V_160 ) ;
V_5 = F_35 ( V_50 , V_16 ) ;
if ( V_5 ) {
F_90 ( V_50 ) ;
F_2 ( F_41 ( V_30 ) ,
L_77 , V_5 ) ;
goto error;
}
error:
F_50 ( V_50 ) ;
return V_5 ;
}
void F_184 ( struct V_29 * V_30 )
{
F_24 ( F_185 ( & V_30 -> V_160 ) ) ;
F_24 ( V_30 -> V_212 == NULL ) ;
F_24 ( ! V_30 -> V_214 ) ;
F_24 ( F_176 ( & F_177 ( V_30 ) -> V_183 ) ) ;
V_30 -> V_214 = 1 ;
V_30 -> V_210 = 0 ;
V_30 -> V_212 = NULL ;
}
int F_186 ( struct V_29 * V_30 , unsigned int V_186 )
{
int V_5 ;
F_24 ( F_176 ( & F_177 ( V_30 ) -> V_183 ) ) ;
F_24 ( V_30 -> V_214 ) ;
V_5 = F_183 ( V_30 , true ) ;
if ( V_5 ) {
F_2 ( F_41 ( V_30 ) ,
L_78
L_79 , V_5 ) ;
F_77 ( & V_30 -> V_160 ) ;
goto error;
}
if ( V_186 )
V_186 = F_187 ( & V_30 -> V_160 ,
V_186 ) ;
if ( ! V_186 ) {
F_77 ( & V_30 -> V_160 ) ;
if ( V_30 -> V_210 == - V_74 ) {
F_2 ( F_41 ( V_30 ) , L_80 ) ;
V_5 = - V_209 ;
goto error;
}
}
V_5 = V_30 -> V_210 ;
error:
V_30 -> V_214 = 0 ;
return V_5 ;
}
int F_188 ( struct V_29 * V_30 , const struct V_215 * V_216 ,
unsigned int V_118 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_217 * V_195 = NULL ;
int V_95 , V_203 ;
struct V_50 * V_50 ;
struct V_187 * V_188 ;
F_24 ( F_176 ( & F_177 ( V_30 ) -> V_183 ) ) ;
F_24 ( V_30 -> V_214 ) ;
if ( V_118 == 0 )
return 0 ;
if ( V_118 > V_218 ) {
F_2 ( F_41 ( V_30 ) ,
L_70 ,
V_118 , V_218 ) ;
return - V_73 ;
}
if ( F_175 () ) {
F_2 ( F_41 ( V_30 ) ,
L_71 ) ;
return - V_206 ;
}
V_7 = F_17 ( V_30 ) ;
V_188 = F_166 ( V_7 , F_165 ( V_7 , V_190 ) ) ;
if ( ! V_188 )
return - V_74 ;
V_50 = F_42 ( 0 , V_16 ) ;
if ( ! V_50 )
return - V_18 ;
V_203 = sizeof( struct V_217 ) +
V_118 * sizeof( struct V_192 ) ;
V_195 = F_8 ( V_203 , V_16 ) ;
if ( ! V_195 ) {
V_5 = - V_18 ;
goto error;
}
V_195 -> V_79 = F_111 ( V_219 ) ;
for ( V_95 = 0 ; V_95 < V_118 ; V_95 ++ ) {
struct V_192 * V_220 = & V_195 -> V_221 [ V_95 ] ;
V_220 -> V_45 = F_111 ( ( T_1 ) V_216 [ V_95 ] . V_45 ) ;
V_220 -> V_201 = F_111 ( V_216 [ V_95 ] . V_201 ) ;
}
if ( F_167 ( & V_188 -> V_171 ) )
F_47 ( V_50 , V_7 , F_165 ( V_7 , V_190 ) ,
V_195 , V_203 , F_182 , V_30 ,
V_188 -> V_171 . V_222 ) ;
else
F_61 ( V_50 , V_7 , F_92 ( V_7 , V_190 ) ,
V_195 , V_203 , F_182 , V_30 ) ;
V_50 -> V_93 |= V_223 ;
V_5 = F_183 ( V_30 , false ) ;
if ( V_5 ) {
F_2 ( F_41 ( V_30 ) ,
L_78
L_79 , V_5 ) ;
goto error;
}
V_30 -> V_212 = V_50 ;
return 0 ;
error:
F_50 ( V_50 ) ;
return V_5 ;
}
int F_189 ( struct V_29 * V_30 , const struct V_215 * V_216 ,
unsigned int V_118 )
{
int V_5 ;
F_184 ( V_30 ) ;
V_5 = F_188 ( V_30 , V_216 , V_118 ) ;
if ( V_5 ) {
F_186 ( V_30 , 0 ) ;
return V_5 ;
}
return F_186 ( V_30 , 50 ) ;
}
int F_190 ( struct V_29 * V_30 , T_9 V_201 , T_2 V_224 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_225 * V_195 = NULL ;
int V_95 , V_203 , V_204 ;
T_1 V_226 ;
if ( F_175 () ) {
F_2 ( F_41 ( V_30 ) ,
L_71 ) ;
return - V_206 ;
}
if ( V_224 < V_227 ) {
F_2 ( F_41 ( V_30 ) ,
L_81
L_82 ,
V_224 , V_227 ) ;
return - V_73 ;
}
if ( V_224 > V_228 ) {
F_2 ( F_41 ( V_30 ) ,
L_83 ,
V_224 , V_228 ) ;
return - V_73 ;
}
#ifdef F_191
if ( V_201 & ( ~ 0UL << V_224 ) ) {
F_2 ( F_41 ( V_30 ) ,
L_84 ,
V_201 , V_224 ) ;
return - V_73 ;
}
#endif
F_2 ( F_41 ( V_30 ) , L_85 , V_201 , V_224 ) ;
V_5 = F_192 ( V_30 , & V_226 , V_229 ) ;
if ( V_5 ) {
F_2 ( F_41 ( V_30 ) ,
L_86 , V_5 ) ;
return V_5 ;
}
V_226 &= ~ ( V_230 | V_231 | V_232 ) ;
F_24 ( F_176 ( & F_177 ( V_30 ) -> V_183 ) ) ;
F_178 ( sizeof( struct V_225 ) +
V_228 * sizeof( T_4 ) >
sizeof( V_30 -> V_207 ) ) ;
F_179 ( sizeof( struct V_225 ) + V_224 * sizeof( T_4 ) >
sizeof( V_30 -> V_207 ) ) ;
V_203 = sizeof( struct V_225 ) + V_224 * sizeof( T_4 ) ;
V_195 = ( void * ) V_30 -> V_207 ;
V_195 -> V_79 = F_111 ( V_233 ) ;
V_195 -> V_201 = F_111 ( 2 ) ;
V_195 -> V_224 = F_111 ( V_224 ) ;
for ( V_95 = 0 ; V_95 < V_224 ; V_95 ++ ) {
T_1 V_234 = V_226 ;
if ( V_201 & ( 1 << ( V_224 - 1 - V_95 ) ) )
V_234 |= V_232 ;
V_195 -> V_235 [ V_95 ] = F_111 ( V_234 ) ;
}
V_7 = F_17 ( V_30 ) ;
V_5 = F_164 ( V_7 , V_195 , V_203 , & V_204 , 50 ) ;
if ( V_5 ) {
F_2 ( F_41 ( V_30 ) ,
L_73 , V_5 ) ;
goto V_68;
}
if ( V_203 != V_204 ) {
F_2 ( F_41 ( V_30 ) , L_87
L_75 ,
V_203 , V_204 ) ;
V_5 = - V_49 ;
goto V_68;
}
V_68:
return V_5 ;
}
