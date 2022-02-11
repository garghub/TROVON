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
V_5 = - V_17 ;
goto error;
}
V_11 &= ~ 1 ;
while ( V_11 > 0 ) {
T_3 V_18 = V_11 <= V_15 ?
V_11 : V_15 ;
F_2 ( & V_7 -> V_19 , L_3 , V_18 ) ;
memcpy ( V_14 , V_10 , V_18 ) ;
V_5 = F_9 ( V_7 , F_10 ( V_7 , 0 ) ,
V_20 ,
V_21 | V_22 ,
V_12 , 0 , V_14 , V_18 , 1000 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_7 -> V_19 ,
L_4
L_5 , V_5 ) ;
goto error;
}
V_18 = V_5 & ~ 1 ;
V_11 -= V_18 ;
V_10 += V_18 ;
V_12 += V_18 / sizeof( T_1 ) ;
}
if ( V_13 & V_23 ) {
T_2 V_24 ;
V_5 = F_9 ( V_7 , F_11 ( V_7 , 0 ) ,
V_25 ,
V_26 | V_22 ,
0 , 0 , V_14 , sizeof( V_24 ) , 5000 ) ;
if ( V_5 != sizeof( V_24 ) ) {
F_4 ( & V_7 -> V_19 ,
L_6
L_7 , V_5 ) ;
if ( V_5 >= 0 )
V_5 = - V_27 ;
goto error;
}
V_24 = V_14 [ 0 ] ;
if ( V_24 & 0x80 ) {
F_4 ( & V_7 -> V_19 ,
L_8
L_9 ,
( unsigned int ) V_24 ) ;
V_5 = - V_27 ;
goto error;
}
F_2 ( & V_7 -> V_19 , L_10 ,
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
F_15 ( V_31 , V_11 , L_11 ,
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
F_14 ( V_30 , V_38 , sizeof( V_38 ) , L_12 ) ,
& V_7 -> V_19 ) ;
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
F_14 ( V_30 , V_38 , sizeof( V_38 ) , L_13 ) ,
& V_7 -> V_19 ) ;
if ( V_5 )
goto error;
V_42 = F_13 ( V_36 -> V_10 , V_44 ) ;
if ( V_42 != V_9 ) {
F_20 ( & V_7 -> V_19 ,
L_14
L_15 , V_42 , V_9 ) ;
if ( V_9 <= 0x4313 )
F_21 ( & V_7 -> V_19 , L_16
L_17 ) ;
V_5 = F_16 ( V_30 , V_36 ) ;
if ( V_5 )
goto error;
} else {
F_2 ( & V_7 -> V_19 ,
L_18
L_19 , V_42 ) ;
}
V_5 = F_1 ( & V_43 ,
F_14 ( V_30 , V_38 , sizeof( V_38 ) , L_20 ) ,
& V_7 -> V_19 ) ;
if ( V_5 )
goto error;
V_5 = F_7 ( V_7 , V_43 -> V_10 , V_43 -> V_11 , V_39 , V_23 ) ;
if ( V_5 ) {
F_4 ( & V_7 -> V_19 ,
L_21 ,
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
return - V_17 ;
V_5 = F_9 ( V_7 , F_11 ( V_7 , 0 ) ,
V_48 , V_26 | 0x40 , V_45 , 0 ,
V_47 , V_46 , 5000 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_7 -> V_19 ,
L_22 , V_5 ) ;
goto exit;
} else if ( V_5 != V_46 ) {
F_4 ( & V_7 -> V_19 ,
L_23 ,
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
F_24 ( & V_53 -> V_54 ) ;
if ( F_25 ( & V_53 -> V_55 ) ) {
F_26 ( & V_53 -> V_55 , 0 ) ;
V_53 -> V_56 = 1 ;
F_27 ( & V_53 -> V_57 . V_58 ) ;
}
F_28 ( & V_53 -> V_54 ) ;
}
static inline void F_29 ( struct V_50 * V_50 )
{
struct V_29 * V_30 = V_50 -> V_51 ;
struct V_52 * V_53 = & V_30 -> V_53 ;
int V_46 ;
T_1 V_59 ;
F_30 ( F_31 () ) ;
F_24 ( & V_53 -> V_54 ) ;
V_59 = F_6 ( * ( T_4 * ) ( V_50 -> V_60 + 2 ) ) ;
if ( V_59 == V_61 ) {
struct V_62 * V_63 = F_32 ( F_33 ( V_50 -> V_51 ) ) ;
F_24 ( & V_63 -> V_54 ) ;
memcpy ( & V_63 -> V_64 , V_50 -> V_60 ,
V_65 ) ;
F_28 ( & V_63 -> V_54 ) ;
F_34 ( & V_63 -> V_66 ) ;
} else if ( F_25 ( & V_53 -> V_55 ) ) {
V_46 = V_50 -> V_67 ;
V_53 -> V_57 . V_68 = V_50 -> V_67 ;
if ( V_46 > sizeof( V_53 -> V_57 . V_31 ) )
V_46 = sizeof( V_53 -> V_57 . V_31 ) ;
memcpy ( V_53 -> V_57 . V_31 , V_50 -> V_60 , V_46 ) ;
if ( ! F_35 ( V_30 , V_53 -> V_57 . V_69 ,
V_53 -> V_57 . V_70 ) )
goto V_71;
F_26 ( & V_53 -> V_55 , 0 ) ;
V_53 -> V_56 = 0 ;
F_27 ( & V_53 -> V_57 . V_58 ) ;
goto V_71;
}
V_71:
F_28 ( & V_53 -> V_54 ) ;
if ( V_59 == V_61 && F_25 ( & V_53 -> V_55 ) )
F_23 ( V_50 ) ;
}
static void F_36 ( struct V_50 * V_50 )
{
int V_5 ;
struct V_72 * V_73 ;
struct V_29 * V_30 ;
struct V_52 * V_53 ;
switch ( V_50 -> V_74 ) {
case 0 :
break;
case - V_75 :
case - V_76 :
case - V_27 :
case - V_77 :
case - V_78 :
case - V_79 :
F_2 ( F_37 ( V_50 ) , L_24 , V_50 , V_50 -> V_74 ) ;
return;
default:
F_2 ( F_37 ( V_50 ) , L_24 , V_50 , V_50 -> V_74 ) ;
goto V_80;
}
if ( V_50 -> V_67 < sizeof( V_73 ) ) {
F_2 ( F_37 ( V_50 ) , L_25 , V_50 ) ;
goto V_80;
}
V_73 = V_50 -> V_60 ;
if ( V_73 -> type != V_81 ) {
F_2 ( F_37 ( V_50 ) , L_26 , V_50 ) ;
goto V_80;
}
V_30 = V_50 -> V_51 ;
V_53 = & V_30 -> V_53 ;
if ( V_73 -> V_82 != V_83 && F_25 ( & V_53 -> V_55 ) )
F_23 ( V_50 ) ;
switch ( V_73 -> V_82 ) {
case V_83 :
F_29 ( V_50 ) ;
break;
case V_84 :
F_38 ( V_50 ) ;
break;
default:
F_2 ( F_37 ( V_50 ) , L_27 , V_50 ,
( unsigned int ) V_73 -> V_82 ) ;
goto V_80;
}
V_80:
V_5 = F_39 ( V_50 , V_85 ) ;
if ( V_5 ) {
F_2 ( F_37 ( V_50 ) , L_28 ,
V_50 , V_5 ) ;
}
return;
}
static inline int F_40 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_86 ) {
case V_87 :
return 4 ;
case V_88 :
return 10 ;
case V_89 :
default:
return 1 ;
}
}
static inline int F_41 ( struct V_29 * V_30 )
{
unsigned long V_13 ;
struct V_52 * V_53 = & V_30 -> V_53 ;
struct V_50 * V_50 ;
F_42 ( & V_53 -> V_54 , V_13 ) ;
V_50 = V_53 -> V_50 ;
F_43 ( & V_53 -> V_54 , V_13 ) ;
return V_50 != NULL ;
}
int F_44 ( struct V_29 * V_30 )
{
int V_5 ;
struct V_6 * V_7 = F_17 ( V_30 ) ;
struct V_52 * V_53 = & V_30 -> V_53 ;
struct V_50 * V_50 ;
F_2 ( F_45 ( V_30 ) , L_29 ) ;
V_50 = F_46 ( 0 , V_16 ) ;
if ( ! V_50 ) {
V_5 = - V_17 ;
goto V_71;
}
F_30 ( ! F_47 () ) ;
F_48 ( & V_53 -> V_54 ) ;
if ( V_53 -> V_50 ) {
F_49 ( & V_53 -> V_54 ) ;
V_5 = 0 ;
goto V_90;
}
V_53 -> V_50 = V_50 ;
F_49 ( & V_53 -> V_54 ) ;
V_5 = - V_17 ;
V_53 -> V_31 = F_50 ( V_7 , V_65 ,
V_16 , & V_53 -> V_91 ) ;
if ( ! V_53 -> V_31 ) {
F_2 ( F_45 ( V_30 ) ,
L_30 ) ;
goto V_92;
}
F_51 ( V_50 , V_7 , F_52 ( V_7 , V_93 ) ,
V_53 -> V_31 , V_65 ,
F_36 , V_30 ,
V_53 -> V_94 ) ;
V_50 -> V_95 = V_53 -> V_91 ;
V_50 -> V_96 |= V_97 ;
F_2 ( F_45 ( V_30 ) , L_31 , V_53 -> V_50 ) ;
V_5 = F_39 ( V_50 , V_16 ) ;
if ( V_5 ) {
F_2 ( F_45 ( V_30 ) ,
L_32 , V_5 ) ;
goto error;
}
return 0 ;
error:
F_53 ( V_7 , V_65 ,
V_53 -> V_31 , V_53 -> V_91 ) ;
V_92:
F_48 ( & V_53 -> V_54 ) ;
V_53 -> V_50 = NULL ;
F_49 ( & V_53 -> V_54 ) ;
V_90:
F_54 ( V_50 ) ;
V_71:
return V_5 ;
}
void F_55 ( struct V_29 * V_30 )
{
unsigned long V_13 ;
struct V_6 * V_7 = F_17 ( V_30 ) ;
struct V_52 * V_53 = & V_30 -> V_53 ;
struct V_50 * V_50 ;
void * V_31 ;
T_6 V_91 ;
F_42 ( & V_53 -> V_54 , V_13 ) ;
V_50 = V_53 -> V_50 ;
if ( ! V_50 ) {
F_43 ( & V_53 -> V_54 , V_13 ) ;
return;
}
V_53 -> V_50 = NULL ;
V_31 = V_53 -> V_31 ;
V_91 = V_53 -> V_91 ;
V_53 -> V_31 = NULL ;
F_43 ( & V_53 -> V_54 , V_13 ) ;
F_56 ( V_50 ) ;
F_2 ( F_45 ( V_30 ) , L_33 , V_50 ) ;
F_54 ( V_50 ) ;
if ( V_31 )
F_53 ( V_7 , V_65 ,
V_31 , V_91 ) ;
}
static void F_57 ( struct V_29 * V_30 , const T_2 * V_31 ,
unsigned int V_68 )
{
int V_98 ;
const struct V_99 * V_100 ;
if ( V_68 < sizeof( struct V_99 ) ) {
F_2 ( F_45 ( V_30 ) , L_34 ,
V_68 ) ;
return;
}
V_100 = (struct V_99 * )
( V_31 + V_68 - sizeof( struct V_99 ) ) ;
if ( F_58 ( & V_100 -> V_101 ) == V_102 )
{
unsigned int V_103 , V_104 , V_105 ;
for ( V_98 = 0 , V_103 = 0 ; ; V_98 ++ ) {
V_104 = F_58 ( & V_100 -> V_68 [ V_98 ] ) ;
if ( V_104 == 0 )
return;
V_105 = V_103 + V_104 ;
if ( V_105 > V_68 )
return;
F_59 ( F_33 ( V_30 ) , V_31 + V_103 , V_104 ) ;
if ( V_98 >= 2 )
return;
V_103 = ( V_105 + 3 ) & ~ 3 ;
}
} else {
F_59 ( F_33 ( V_30 ) , V_31 , V_68 ) ;
}
}
static void F_60 ( struct V_50 * V_50 )
{
int V_5 ;
struct V_29 * V_30 ;
struct V_106 * V_107 ;
const T_2 * V_31 ;
unsigned int V_68 ;
switch ( V_50 -> V_74 ) {
case 0 :
break;
case - V_75 :
case - V_76 :
case - V_27 :
case - V_77 :
case - V_78 :
case - V_79 :
F_2 ( F_37 ( V_50 ) , L_24 , V_50 , V_50 -> V_74 ) ;
return;
default:
F_2 ( F_37 ( V_50 ) , L_24 , V_50 , V_50 -> V_74 ) ;
goto V_80;
}
V_31 = V_50 -> V_60 ;
V_68 = V_50 -> V_67 ;
V_30 = V_50 -> V_51 ;
V_107 = & V_30 -> V_107 ;
F_61 ( & V_107 -> V_108 ) ;
if ( V_68 % V_107 -> V_109 > V_107 -> V_109 - 4 ) {
F_2 ( F_37 ( V_50 ) , L_35 ) ;
F_30 ( V_68 <= F_62 ( V_107 -> V_110 ) ) ;
F_24 ( & V_107 -> V_54 ) ;
memcpy ( V_107 -> V_110 , V_31 , V_68 ) ;
V_107 -> V_111 = V_68 ;
F_28 ( & V_107 -> V_54 ) ;
goto V_80;
}
F_24 ( & V_107 -> V_54 ) ;
if ( V_107 -> V_111 > 0 ) {
F_30 ( V_68 + V_107 -> V_111 <=
F_62 ( V_107 -> V_110 ) ) ;
F_2 ( F_37 ( V_50 ) , L_36 ) ;
memcpy ( V_107 -> V_110 + V_107 -> V_111 , V_31 , V_68 ) ;
F_57 ( V_30 , V_107 -> V_110 ,
V_107 -> V_111 + V_68 ) ;
V_107 -> V_111 = 0 ;
F_28 ( & V_107 -> V_54 ) ;
} else {
F_28 ( & V_107 -> V_54 ) ;
F_57 ( V_30 , V_31 , V_68 ) ;
}
V_80:
V_5 = F_39 ( V_50 , V_85 ) ;
if ( V_5 )
F_2 ( F_37 ( V_50 ) , L_37 , V_50 , V_5 ) ;
}
static struct V_50 * F_63 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = F_17 ( V_30 ) ;
struct V_50 * V_50 ;
void * V_31 ;
V_50 = F_46 ( 0 , V_16 ) ;
if ( ! V_50 )
return NULL ;
V_31 = F_50 ( V_7 , V_112 , V_16 ,
& V_50 -> V_95 ) ;
if ( ! V_31 ) {
F_54 ( V_50 ) ;
return NULL ;
}
F_64 ( V_50 , V_7 , F_65 ( V_7 , V_113 ) ,
V_31 , V_112 ,
F_60 , V_30 ) ;
V_50 -> V_96 |= V_97 ;
return V_50 ;
}
static void F_66 ( struct V_50 * V_50 )
{
if ( ! V_50 )
return;
F_53 ( V_50 -> V_19 , V_50 -> V_114 ,
V_50 -> V_60 , V_50 -> V_95 ) ;
F_54 ( V_50 ) ;
}
static int F_67 ( struct V_29 * V_30 )
{
int V_98 , V_5 ;
struct V_106 * V_107 = & V_30 -> V_107 ;
struct V_50 * * V_115 ;
F_2 ( F_45 ( V_30 ) , L_29 ) ;
V_5 = - V_17 ;
V_115 = F_68 ( V_116 , sizeof( struct V_50 * ) , V_16 ) ;
if ( ! V_115 )
goto error;
for ( V_98 = 0 ; V_98 < V_116 ; V_98 ++ ) {
V_115 [ V_98 ] = F_63 ( V_30 ) ;
if ( ! V_115 [ V_98 ] )
goto error;
}
F_30 ( ! F_47 () ) ;
F_48 ( & V_107 -> V_54 ) ;
if ( V_107 -> V_115 ) {
F_49 ( & V_107 -> V_54 ) ;
V_5 = 0 ;
goto error;
}
V_107 -> V_115 = V_115 ;
V_107 -> V_117 = V_116 ;
F_49 ( & V_107 -> V_54 ) ;
for ( V_98 = 0 ; V_98 < V_116 ; V_98 ++ ) {
V_5 = F_39 ( V_115 [ V_98 ] , V_16 ) ;
if ( V_5 )
goto V_118;
}
return 0 ;
V_118:
for ( V_98 = 0 ; V_98 < V_116 ; V_98 ++ ) {
F_56 ( V_115 [ V_98 ] ) ;
}
F_48 ( & V_107 -> V_54 ) ;
V_107 -> V_115 = NULL ;
V_107 -> V_117 = 0 ;
F_49 ( & V_107 -> V_54 ) ;
error:
if ( V_115 ) {
for ( V_98 = 0 ; V_98 < V_116 ; V_98 ++ )
F_66 ( V_115 [ V_98 ] ) ;
}
return V_5 ;
}
int F_69 ( struct V_29 * V_30 )
{
int V_5 ;
struct V_106 * V_107 = & V_30 -> V_107 ;
F_70 ( & V_107 -> V_119 ) ;
V_5 = F_67 ( V_30 ) ;
F_71 ( & V_107 -> V_119 ) ;
F_72 ( V_30 ) ;
return V_5 ;
}
static void F_73 ( struct V_29 * V_30 )
{
int V_98 ;
unsigned long V_13 ;
struct V_50 * * V_115 ;
unsigned int V_120 ;
struct V_106 * V_107 = & V_30 -> V_107 ;
F_42 ( & V_107 -> V_54 , V_13 ) ;
V_115 = V_107 -> V_115 ;
V_120 = V_107 -> V_117 ;
F_43 ( & V_107 -> V_54 , V_13 ) ;
if ( ! V_115 )
return;
for ( V_98 = 0 ; V_98 < V_120 ; V_98 ++ ) {
F_56 ( V_115 [ V_98 ] ) ;
F_66 ( V_115 [ V_98 ] ) ;
}
F_12 ( V_115 ) ;
F_42 ( & V_107 -> V_54 , V_13 ) ;
V_107 -> V_115 = NULL ;
V_107 -> V_117 = 0 ;
F_43 ( & V_107 -> V_54 , V_13 ) ;
}
void F_74 ( struct V_29 * V_30 )
{
struct V_106 * V_107 = & V_30 -> V_107 ;
F_70 ( & V_107 -> V_119 ) ;
F_73 ( V_30 ) ;
F_71 ( & V_107 -> V_119 ) ;
F_75 ( & V_107 -> V_108 ) ;
F_76 ( & V_107 -> V_121 ) ;
}
static void F_77 ( struct V_29 * V_30 )
{
bool V_122 ;
struct V_106 * V_107 = & V_30 -> V_107 ;
unsigned long V_13 ;
F_70 ( & V_107 -> V_119 ) ;
F_42 ( & V_107 -> V_54 , V_13 ) ;
V_122 = V_107 -> V_115 != NULL ;
F_43 ( & V_107 -> V_54 , V_13 ) ;
if ( V_122 ) {
F_73 ( V_30 ) ;
F_67 ( V_30 ) ;
}
F_71 ( & V_107 -> V_119 ) ;
if ( V_122 )
F_72 ( V_30 ) ;
}
void F_78 ( struct V_29 * V_30 )
{
struct V_123 * V_124 = & V_30 -> V_124 ;
unsigned long V_13 ;
F_26 ( & V_124 -> V_125 , 0 ) ;
F_79 ( & V_124 -> V_126 ) ;
F_42 ( & V_124 -> V_54 , V_13 ) ;
F_80 ( ! F_81 ( & V_124 -> V_127 ) ) ;
F_80 ( V_124 -> V_128 != 0 ) ;
V_124 -> V_128 = 0 ;
F_43 ( & V_124 -> V_54 , V_13 ) ;
}
void F_82 ( struct V_29 * V_30 )
{
unsigned long V_13 ;
struct V_123 * V_124 = & V_30 -> V_124 ;
F_42 ( & V_124 -> V_54 , V_13 ) ;
F_26 ( & V_124 -> V_125 , 1 ) ;
V_124 -> V_128 = 0 ;
F_83 ( F_33 ( V_30 ) ) ;
V_124 -> V_129 = 0 ;
F_43 ( & V_124 -> V_54 , V_13 ) ;
}
static void F_84 ( struct V_29 * V_30 )
{
struct V_123 * V_124 = & V_30 -> V_124 ;
unsigned long V_13 ;
F_42 ( & V_124 -> V_54 , V_13 ) ;
-- V_124 -> V_128 ;
if ( V_124 -> V_129 && V_124 -> V_128 <= V_130 ) {
F_83 ( F_33 ( V_30 ) ) ;
V_124 -> V_129 = 0 ;
}
F_43 ( & V_124 -> V_54 , V_13 ) ;
}
static void F_85 ( struct V_29 * V_30 )
{
struct V_123 * V_124 = & V_30 -> V_124 ;
unsigned long V_13 ;
F_42 ( & V_124 -> V_54 , V_13 ) ;
++ V_124 -> V_128 ;
if ( ! V_124 -> V_129 && V_124 -> V_128 > V_131 ) {
F_86 ( F_33 ( V_30 ) ) ;
V_124 -> V_129 = 1 ;
}
F_43 ( & V_124 -> V_54 , V_13 ) ;
}
static void F_87 ( struct V_50 * V_50 )
{
int V_5 ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
struct V_29 * V_30 ;
struct V_123 * V_124 ;
V_133 = (struct V_132 * ) V_50 -> V_51 ;
V_135 = F_88 ( V_133 ) ;
V_30 = & F_32 ( V_135 -> V_136 [ 0 ] ) -> V_137 . V_30 ;
V_124 = & V_30 -> V_124 ;
switch ( V_50 -> V_74 ) {
case 0 :
break;
case - V_75 :
case - V_76 :
case - V_27 :
case - V_77 :
case - V_78 :
case - V_79 :
F_2 ( F_37 ( V_50 ) , L_24 , V_50 , V_50 -> V_74 ) ;
break;
default:
F_2 ( F_37 ( V_50 ) , L_24 , V_50 , V_50 -> V_74 ) ;
goto V_80;
}
V_138:
F_89 ( V_133 , & V_30 -> V_124 . V_127 ) ;
F_90 ( V_133 , V_50 -> V_74 ) ;
F_54 ( V_50 ) ;
F_84 ( V_30 ) ;
return;
V_80:
F_91 ( V_50 , & V_124 -> V_126 ) ;
V_5 = F_39 ( V_50 , V_85 ) ;
if ( V_5 ) {
F_92 ( V_50 ) ;
F_2 ( F_37 ( V_50 ) , L_38 , V_50 , V_5 ) ;
goto V_138;
}
}
int V_123 ( struct V_29 * V_30 , struct V_132 * V_133 )
{
int V_5 ;
struct V_134 * V_135 = F_88 ( V_133 ) ;
struct V_6 * V_7 = F_17 ( V_30 ) ;
struct V_50 * V_50 ;
struct V_123 * V_124 = & V_30 -> V_124 ;
if ( ! F_25 ( & V_124 -> V_125 ) ) {
V_5 = - V_77 ;
goto V_71;
}
V_50 = F_46 ( 0 , V_85 ) ;
if ( ! V_50 ) {
V_5 = - V_17 ;
goto V_71;
}
F_64 ( V_50 , V_7 , F_93 ( V_7 , V_139 ) ,
V_133 -> V_10 , V_133 -> V_46 , F_87 , V_133 ) ;
V_135 -> V_136 [ 1 ] = ( void * ) V_140 ;
F_94 ( & V_124 -> V_127 , V_133 ) ;
F_91 ( V_50 , & V_124 -> V_126 ) ;
V_5 = F_39 ( V_50 , V_85 ) ;
if ( V_5 ) {
F_2 ( F_45 ( V_30 ) , L_39 , V_50 , V_5 ) ;
F_92 ( V_50 ) ;
F_89 ( V_133 , & V_124 -> V_127 ) ;
goto error;
}
F_85 ( V_30 ) ;
return 0 ;
error:
F_54 ( V_50 ) ;
V_71:
return V_5 ;
}
static bool F_95 ( struct V_29 * V_30 )
{
struct V_123 * V_124 = & V_30 -> V_124 ;
struct V_141 * V_142 = & V_124 -> V_127 ;
struct V_132 * V_133 , * V_143 ;
struct V_134 * V_135 ;
unsigned long V_13 , V_144 ;
bool V_145 = false ;
F_42 ( & V_142 -> V_54 , V_13 ) ;
F_96 (q, skb, skbnext) {
V_135 = F_88 ( V_133 ) ;
V_144 = ( unsigned long ) V_135 -> V_136 [ 1 ] ;
if ( F_97 ( V_144 + V_146 ) ) {
V_145 = true ;
break;
}
}
F_43 ( & V_142 -> V_54 , V_13 ) ;
return V_145 ;
}
static void F_98 ( struct V_147 * V_148 )
{
struct V_29 * V_30 =
F_99 ( V_148 , struct V_29 , V_124 . V_149 . V_148 ) ;
struct V_123 * V_124 = & V_30 -> V_124 ;
if ( ! F_25 ( & V_124 -> V_125 ) || ! V_124 -> V_150 )
goto V_71;
if ( ! F_95 ( V_30 ) )
goto V_71;
F_21 ( F_45 ( V_30 ) , L_40 ) ;
F_100 ( V_30 -> V_151 ) ;
return;
V_71:
F_101 ( V_152 , & V_124 -> V_149 ,
V_153 ) ;
}
void F_102 ( struct V_29 * V_30 )
{
struct V_123 * V_124 = & V_30 -> V_124 ;
if ( ! V_124 -> V_150 ) {
F_2 ( F_45 ( V_30 ) , L_29 ) ;
F_101 ( V_152 , & V_124 -> V_149 ,
V_153 ) ;
V_124 -> V_150 = 1 ;
}
}
void F_103 ( struct V_29 * V_30 )
{
struct V_123 * V_124 = & V_30 -> V_124 ;
if ( V_124 -> V_150 ) {
F_2 ( F_45 ( V_30 ) , L_29 ) ;
V_124 -> V_150 = 0 ;
F_76 ( & V_124 -> V_149 ) ;
}
}
static void F_104 ( struct V_147 * V_148 )
{
struct V_29 * V_30 =
F_99 ( V_148 , struct V_29 , V_107 . V_121 . V_148 ) ;
struct V_62 * V_63 = F_105 ( V_30 ) ;
if ( ! F_106 ( V_154 , & V_63 -> V_13 ) )
return;
F_2 ( F_45 ( V_30 ) , L_29 ) ;
F_77 ( V_30 ) ;
}
static void F_107 ( unsigned long V_155 )
{
struct V_29 * V_30 = (struct V_29 * ) V_155 ;
F_72 ( V_30 ) ;
}
void F_72 ( struct V_29 * V_30 )
{
struct V_106 * V_107 = & V_30 -> V_107 ;
F_108 ( V_152 , & V_107 -> V_121 , V_156 ) ;
}
static inline void F_109 ( struct V_29 * V_30 )
{
struct V_52 * V_53 = & V_30 -> V_53 ;
F_110 ( & V_53 -> V_54 ) ;
V_53 -> V_94 = F_40 ( F_17 ( V_30 ) ) ;
F_111 ( & V_53 -> V_57 . V_58 ) ;
F_26 ( & V_53 -> V_55 , 0 ) ;
V_53 -> V_57 . V_157 = F_112 ( ( T_1 ) V_61 ) ;
}
static inline void F_113 ( struct V_29 * V_30 )
{
struct V_106 * V_107 = & V_30 -> V_107 ;
F_110 ( & V_107 -> V_54 ) ;
F_114 ( & V_107 -> V_119 ) ;
if ( F_115 ( V_30 -> V_151 ) -> V_86 == V_87 ) {
V_107 -> V_109 = 512 ;
} else {
V_107 -> V_109 = 64 ;
}
F_30 ( V_107 -> V_111 == 0 ) ;
F_116 ( & V_107 -> V_121 , F_104 ) ;
V_107 -> V_108 . V_158 = F_107 ;
V_107 -> V_108 . V_10 = ( unsigned long ) V_30 ;
}
static inline void F_117 ( struct V_29 * V_30 )
{
struct V_123 * V_124 = & V_30 -> V_124 ;
F_110 ( & V_124 -> V_54 ) ;
F_26 ( & V_124 -> V_125 , 0 ) ;
V_124 -> V_129 = 0 ;
F_118 ( & V_124 -> V_127 ) ;
F_119 ( & V_124 -> V_126 ) ;
V_124 -> V_128 = 0 ;
V_124 -> V_150 = 0 ;
F_116 ( & V_124 -> V_149 , F_98 ) ;
}
void F_120 ( struct V_29 * V_30 , struct V_159 * V_160 ,
struct V_161 * V_151 )
{
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_151 = F_121 ( V_151 ) ;
F_122 ( V_30 -> V_151 , V_160 ) ;
F_119 ( & V_30 -> V_162 ) ;
F_109 ( V_30 ) ;
F_117 ( V_30 ) ;
F_113 ( V_30 ) ;
}
void F_123 ( struct V_29 * V_30 )
{
F_122 ( V_30 -> V_151 , NULL ) ;
F_124 ( V_30 -> V_151 ) ;
F_125 ( V_30 , sizeof( * V_30 ) ) ;
}
static const char * V_86 ( enum V_163 V_86 )
{
switch ( V_86 ) {
case V_88 :
return L_41 ;
case V_89 :
return L_42 ;
case V_87 :
return L_43 ;
default:
return L_44 ;
}
}
static int F_126 ( struct V_6 * V_7 , char * V_31 , T_3 V_11 )
{
return F_15 ( V_31 , V_11 , L_45 ,
F_6 ( V_7 -> V_8 . V_164 ) ,
F_6 ( V_7 -> V_8 . V_165 ) ,
F_5 ( V_7 ) ,
V_86 ( V_7 -> V_86 ) ) ;
}
int F_127 ( struct V_29 * V_30 , char * V_31 , T_3 V_11 )
{
struct V_6 * V_7 = F_115 ( V_30 -> V_151 ) ;
return F_126 ( V_7 , V_31 , V_11 ) ;
}
static void F_128 ( struct V_6 * V_7 )
{
char V_31 [ 40 ] ;
F_126 ( V_7 , V_31 , sizeof( V_31 ) ) ;
V_31 [ sizeof( V_31 ) - 1 ] = 0 ;
F_2 ( & V_7 -> V_19 , L_46 , V_31 ) ;
}
static int F_129 ( struct V_161 * V_151 )
{
struct V_6 * V_7 = F_115 ( V_151 ) ;
struct V_166 * V_167 = & V_151 -> V_168 [ 0 ] ;
struct V_169 * V_170 ;
unsigned char * V_171 ;
T_2 V_172 ;
int V_5 ;
for ( V_5 = 1 ; V_5 >= 0 ; V_5 -- ) {
V_170 = & V_167 -> V_170 [ V_5 ] . V_173 ;
if ( F_130 ( V_170 ) &&
F_131 ( V_170 ) ) {
V_172 = V_170 -> V_174 ;
break;
}
}
if ( V_5 == - 1 ) {
F_4 ( & V_7 -> V_19 ,
L_47 ) ;
return - V_27 ;
}
V_171 = F_132 ( 31 , V_16 ) ;
if ( V_171 == NULL )
return - V_27 ;
V_171 [ 0 ] = 0x55 ;
V_171 [ 1 ] = 0x53 ;
V_171 [ 2 ] = 0x42 ;
V_171 [ 3 ] = 0x43 ;
V_171 [ 14 ] = 6 ;
V_171 [ 15 ] = 0x1b ;
V_171 [ 19 ] = 0x2 ;
F_20 ( & V_7 -> V_19 , L_48 ) ;
V_5 = F_133 ( V_7 , F_93 ( V_7 , V_172 ) ,
V_171 , 31 , NULL , 2000 ) ;
F_12 ( V_171 ) ;
if ( V_5 )
return V_5 ;
F_122 ( V_151 , NULL ) ;
return 0 ;
}
int F_134 ( struct V_29 * V_30 )
{
int V_5 ;
struct V_62 * V_63 = F_105 ( V_30 ) ;
F_2 ( F_45 ( V_30 ) , L_29 ) ;
V_5 = F_19 ( V_30 ) ;
if ( V_5 ) {
F_4 ( F_45 ( V_30 ) ,
L_49 , V_5 ) ;
return V_5 ;
}
V_5 = F_135 ( F_17 ( V_30 ) ) ;
if ( V_5 ) {
F_2 ( F_45 ( V_30 ) ,
L_50 , V_5 ) ;
return V_5 ;
}
V_5 = F_136 ( V_63 -> V_160 ) ;
if ( V_5 ) {
F_2 ( F_45 ( V_30 ) ,
L_51 , V_5 ) ;
return V_5 ;
}
V_30 -> V_175 = 1 ;
return 0 ;
}
static int F_137 ( struct V_161 * V_151 , const struct V_176 * V_82 )
{
int V_5 ;
struct V_6 * V_7 = F_115 ( V_151 ) ;
struct V_29 * V_30 ;
struct V_159 * V_160 = NULL ;
F_128 ( V_7 ) ;
if ( V_82 -> V_177 & V_178 )
return F_129 ( V_151 ) ;
switch ( V_7 -> V_86 ) {
case V_88 :
case V_89 :
case V_87 :
break;
default:
F_2 ( & V_151 -> V_19 , L_52 ) ;
V_5 = - V_27 ;
goto error;
}
V_5 = F_138 ( V_7 ) ;
if ( V_5 ) {
F_4 ( & V_151 -> V_19 ,
L_53 , V_5 ) ;
goto error;
}
V_160 = F_139 ( V_151 ) ;
if ( V_160 == NULL ) {
V_5 = - V_17 ;
goto error;
}
V_30 = & F_32 ( V_160 ) -> V_137 . V_30 ;
V_30 -> V_33 = ( V_82 -> V_177 == V_179 ) != 0 ;
V_5 = F_140 ( V_160 ) ;
if ( V_5 ) {
F_2 ( & V_151 -> V_19 ,
L_51 , V_5 ) ;
goto error;
}
V_5 = F_141 ( V_160 ) ;
if ( V_5 ) {
F_2 ( & V_151 -> V_19 ,
L_54 , V_5 ) ;
goto error;
}
F_2 ( & V_151 -> V_19 , L_55 ) ;
F_20 ( & V_151 -> V_19 , L_46 , F_142 ( V_160 -> V_180 ) ) ;
return 0 ;
error:
F_138 ( F_115 ( V_151 ) ) ;
if ( V_160 ) {
F_143 ( F_32 ( V_160 ) ) ;
F_144 ( V_160 ) ;
}
return V_5 ;
}
static void F_145 ( struct V_161 * V_151 )
{
struct V_159 * V_160 = F_146 ( V_151 ) ;
struct V_62 * V_63 ;
struct V_29 * V_30 ;
if ( V_160 == NULL )
return;
V_63 = F_32 ( V_160 ) ;
V_30 = & V_63 -> V_137 . V_30 ;
F_2 ( F_45 ( V_30 ) , L_29 ) ;
F_147 ( V_160 ) ;
F_78 ( V_30 ) ;
F_74 ( V_30 ) ;
F_55 ( V_30 ) ;
F_138 ( F_115 ( V_151 ) ) ;
F_143 ( V_63 ) ;
F_144 ( V_160 ) ;
F_148 ( & V_151 -> V_19 , L_56 ) ;
}
static void F_149 ( struct V_29 * V_30 )
{
struct V_62 * V_63 = F_105 ( V_30 ) ;
int V_5 ;
F_2 ( F_45 ( V_30 ) , L_29 ) ;
V_5 = F_150 ( F_33 ( V_30 ) ) ;
if ( V_5 < 0 ) {
F_21 ( F_45 ( V_30 ) , L_57
L_58 , V_5 ) ;
if ( V_30 -> V_181 )
F_151 ( V_154 , & V_63 -> V_13 ) ;
F_100 ( V_30 -> V_151 ) ;
return;
}
if ( V_63 -> type != V_182 ) {
V_5 = F_152 ( V_63 ) ;
if ( V_5 < 0 ) {
F_148 ( F_45 ( V_30 ) ,
L_59 , V_5 ) ;
return;
}
}
}
static void F_153 ( struct V_29 * V_30 )
{
F_2 ( F_45 ( V_30 ) , L_29 ) ;
F_154 ( F_33 ( V_30 ) ) ;
F_78 ( V_30 ) ;
F_74 ( V_30 ) ;
F_55 ( V_30 ) ;
V_30 -> V_175 = 0 ;
}
static int F_155 ( struct V_161 * V_151 )
{
struct V_159 * V_160 = F_156 ( V_151 ) ;
struct V_62 * V_63 ;
struct V_29 * V_30 ;
if ( ! V_160 || V_151 -> V_183 != V_184 )
return 0 ;
V_63 = F_32 ( V_160 ) ;
V_30 = & V_63 -> V_137 . V_30 ;
V_30 -> V_181 = F_106 ( V_154 , & V_63 -> V_13 ) ;
F_153 ( V_30 ) ;
F_70 ( & V_63 -> V_137 . V_185 ) ;
return 0 ;
}
static int F_157 ( struct V_161 * V_151 )
{
struct V_159 * V_160 = F_156 ( V_151 ) ;
struct V_62 * V_63 ;
struct V_29 * V_30 ;
if ( ! V_160 || V_151 -> V_183 != V_184 )
return 0 ;
V_63 = F_32 ( V_160 ) ;
V_30 = & V_63 -> V_137 . V_30 ;
F_71 ( & V_63 -> V_137 . V_185 ) ;
if ( V_30 -> V_181 )
F_149 ( V_30 ) ;
return 0 ;
}
static int T_7 F_158 ( void )
{
int V_5 ;
F_159 ( L_60 , V_186 . V_3 ) ;
V_152 = F_160 ( V_186 . V_3 ) ;
if ( V_152 == NULL ) {
F_161 ( V_187 L_61 , V_186 . V_3 ) ;
return - V_17 ;
}
V_5 = F_162 ( & V_186 ) ;
if ( V_5 ) {
F_163 ( V_152 ) ;
F_161 ( V_187 L_62 ,
V_186 . V_3 , V_5 ) ;
return V_5 ;
}
F_159 ( L_63 , V_186 . V_3 ) ;
return 0 ;
}
static void T_8 F_164 ( void )
{
F_159 ( L_64 , V_186 . V_3 ) ;
F_165 ( & V_186 ) ;
F_163 ( V_152 ) ;
}
static int F_166 ( struct V_6 * V_7 , void * V_10 , int V_46 ,
int * V_67 , int V_188 )
{
struct V_189 * V_190 ;
unsigned int V_191 ;
V_191 = F_167 ( V_7 , V_192 ) ;
V_190 = F_168 ( V_7 , V_191 ) ;
if ( ! V_190 )
return - V_76 ;
if ( F_169 ( & V_190 -> V_173 ) ) {
return F_170 ( V_7 , V_191 , V_10 , V_46 ,
V_67 , V_188 ) ;
} else {
V_191 = F_93 ( V_7 , V_192 ) ;
return F_133 ( V_7 , V_191 , V_10 , V_46 , V_67 ,
V_188 ) ;
}
}
static int F_171 ( unsigned int V_120 )
{
return sizeof( struct V_193 ) + V_120 * sizeof( struct V_194 ) ;
}
static void F_172 ( struct V_29 * V_30 ,
struct V_195 * V_69 ,
unsigned int V_120 )
{
struct V_52 * V_53 = & V_30 -> V_53 ;
F_48 ( & V_53 -> V_54 ) ;
F_26 ( & V_53 -> V_55 , 1 ) ;
V_53 -> V_57 . V_69 = V_69 ;
V_53 -> V_57 . V_70 = V_120 ;
F_173 ( & V_53 -> V_57 . V_58 ) ;
F_49 ( & V_53 -> V_54 ) ;
}
static void F_174 ( struct V_29 * V_30 )
{
struct V_52 * V_53 = & V_30 -> V_53 ;
F_48 ( & V_53 -> V_54 ) ;
F_26 ( & V_53 -> V_55 , 0 ) ;
F_49 ( & V_53 -> V_54 ) ;
}
static bool F_35 ( struct V_29 * V_30 , struct V_195 * V_69 ,
unsigned int V_120 )
{
int V_98 ;
struct V_52 * V_53 = & V_30 -> V_53 ;
struct V_196 * V_197 = & V_53 -> V_57 ;
struct V_193 * V_198 = (struct V_193 * ) V_197 -> V_31 ;
if ( V_197 -> V_68 < F_171 ( V_120 ) ) {
F_2 ( F_45 ( V_30 ) ,
L_65 ,
V_197 -> V_68 , F_171 ( V_120 ) ) ;
return false ;
}
if ( V_197 -> V_68 > sizeof( V_197 -> V_31 ) ) {
F_2 ( F_45 ( V_30 ) ,
L_66 ,
V_197 -> V_68 , sizeof( V_197 -> V_31 ) ) ;
return false ;
}
for ( V_98 = 0 ; V_98 < V_120 ; V_98 ++ ) {
struct V_194 * V_199 = & V_198 -> V_198 [ V_98 ] ;
if ( V_199 -> V_45 != V_69 -> V_45 [ V_98 ] ) {
F_2 ( F_45 ( V_30 ) ,
L_67 , V_98 ,
F_6 ( V_199 -> V_45 ) ,
F_6 ( V_69 -> V_45 [ V_98 ] ) ) ;
return false ;
}
}
return true ;
}
static int F_175 ( struct V_29 * V_30 , T_1 * V_200 ,
struct V_195 * V_69 , unsigned int V_120 ,
bool * V_201 )
{
int V_5 ;
int V_98 ;
struct V_52 * V_53 = & V_30 -> V_53 ;
struct V_196 * V_197 = & V_53 -> V_57 ;
struct V_193 * V_198 = (struct V_193 * ) V_197 -> V_31 ;
F_48 ( & V_53 -> V_54 ) ;
V_5 = - V_49 ;
* V_201 = ! ! V_53 -> V_56 ;
if ( * V_201 )
goto V_202;
if ( ! F_35 ( V_30 , V_69 , V_120 ) ) {
F_2 ( F_45 ( V_30 ) , L_68 ) ;
goto V_202;
}
for ( V_98 = 0 ; V_98 < V_120 ; V_98 ++ ) {
struct V_194 * V_199 = & V_198 -> V_198 [ V_98 ] ;
V_200 [ V_98 ] = F_6 ( V_199 -> V_203 ) ;
}
V_5 = 0 ;
V_202:
F_49 ( & V_53 -> V_54 ) ;
return V_5 ;
}
int F_176 ( struct V_29 * V_30 , T_1 * V_200 ,
const T_5 * V_204 , unsigned int V_120 )
{
int V_5 , V_98 , V_205 , V_206 , V_207 = 0 ;
struct V_6 * V_7 ;
struct V_195 * V_69 = NULL ;
unsigned long V_188 ;
bool V_201 = false ;
if ( V_120 < 1 ) {
F_2 ( F_45 ( V_30 ) , L_69 ) ;
return - V_76 ;
}
if ( V_120 > V_208 ) {
F_2 ( F_45 ( V_30 ) ,
L_70 ,
V_120 , V_208 ) ;
return - V_76 ;
}
if ( F_177 () ) {
F_2 ( F_45 ( V_30 ) ,
L_71 ) ;
return - V_209 ;
}
if ( ! F_41 ( V_30 ) ) {
F_2 ( F_45 ( V_30 ) ,
L_72 ) ;
return - V_209 ;
}
F_30 ( F_178 ( & F_179 ( V_30 ) -> V_185 ) ) ;
F_180 ( sizeof( struct V_195 ) + V_208 *
sizeof( T_4 ) > sizeof( V_30 -> V_210 ) ) ;
F_181 ( sizeof( struct V_195 ) + V_120 * sizeof( T_4 ) >
sizeof( V_30 -> V_210 ) ) ;
V_205 = sizeof( struct V_195 ) + V_120 * sizeof( T_4 ) ;
V_69 = ( void * ) V_30 -> V_210 ;
V_69 -> V_82 = F_112 ( V_211 ) ;
for ( V_98 = 0 ; V_98 < V_120 ; V_98 ++ )
V_69 -> V_45 [ V_98 ] = F_112 ( ( T_1 ) V_204 [ V_98 ] ) ;
V_212:
V_207 ++ ;
V_7 = F_17 ( V_30 ) ;
F_172 ( V_30 , V_69 , V_120 ) ;
V_5 = F_166 ( V_7 , V_69 , V_205 , & V_206 , 50 ) ;
if ( V_5 ) {
F_2 ( F_45 ( V_30 ) ,
L_73 , V_5 ) ;
goto error;
}
if ( V_205 != V_206 ) {
F_2 ( F_45 ( V_30 ) , L_74
L_75 ,
V_205 , V_206 ) ;
V_5 = - V_49 ;
goto error;
}
V_188 = F_182 ( & V_30 -> V_53 . V_57 . V_58 ,
F_183 ( 50 ) ) ;
if ( ! V_188 ) {
F_174 ( V_30 ) ;
F_2 ( F_45 ( V_30 ) , L_76 ) ;
V_5 = - V_213 ;
goto error;
}
V_5 = F_175 ( V_30 , V_200 , V_69 , V_120 , & V_201 ) ;
if ( V_201 && V_207 < 20 ) {
F_2 ( F_45 ( V_30 ) , L_77 ,
V_207 ) ;
goto V_212;
}
error:
return V_5 ;
}
static void F_184 ( struct V_50 * V_50 )
{
struct V_29 * V_30 = V_50 -> V_51 ;
if ( V_50 -> V_74 && ! V_30 -> V_214 )
V_30 -> V_214 = V_50 -> V_74 ;
if ( ! V_30 -> V_214 &&
V_50 -> V_67 != V_50 -> V_114 )
V_30 -> V_214 = - V_49 ;
}
static int F_185 ( struct V_29 * V_30 , bool V_215 )
{
int V_5 = 0 ;
struct V_50 * V_50 = V_30 -> V_216 ;
if ( ! V_50 )
return 0 ;
V_30 -> V_216 = NULL ;
if ( ! V_215 )
V_50 -> V_96 |= V_217 ;
F_91 ( V_50 , & V_30 -> V_162 ) ;
V_5 = F_39 ( V_50 , V_16 ) ;
if ( V_5 ) {
F_92 ( V_50 ) ;
F_2 ( F_45 ( V_30 ) ,
L_78 , V_5 ) ;
goto error;
}
error:
F_54 ( V_50 ) ;
return V_5 ;
}
void F_186 ( struct V_29 * V_30 )
{
F_30 ( F_187 ( & V_30 -> V_162 ) ) ;
F_30 ( V_30 -> V_216 == NULL ) ;
F_30 ( ! V_30 -> V_218 ) ;
F_30 ( F_178 ( & F_179 ( V_30 ) -> V_185 ) ) ;
V_30 -> V_218 = 1 ;
V_30 -> V_214 = 0 ;
V_30 -> V_216 = NULL ;
}
int F_188 ( struct V_29 * V_30 , unsigned int V_188 )
{
int V_5 ;
F_30 ( F_178 ( & F_179 ( V_30 ) -> V_185 ) ) ;
F_30 ( V_30 -> V_218 ) ;
V_5 = F_185 ( V_30 , true ) ;
if ( V_5 ) {
F_2 ( F_45 ( V_30 ) ,
L_79
L_80 , V_5 ) ;
F_79 ( & V_30 -> V_162 ) ;
goto error;
}
if ( V_188 )
V_188 = F_189 ( & V_30 -> V_162 ,
V_188 ) ;
if ( ! V_188 ) {
F_79 ( & V_30 -> V_162 ) ;
if ( V_30 -> V_214 == - V_77 ) {
F_2 ( F_45 ( V_30 ) , L_81 ) ;
V_5 = - V_213 ;
goto error;
}
}
V_5 = V_30 -> V_214 ;
error:
V_30 -> V_218 = 0 ;
return V_5 ;
}
int F_190 ( struct V_29 * V_30 , const struct V_219 * V_220 ,
unsigned int V_120 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_221 * V_69 = NULL ;
int V_98 , V_205 ;
struct V_50 * V_50 ;
struct V_189 * V_190 ;
F_30 ( F_178 ( & F_179 ( V_30 ) -> V_185 ) ) ;
F_30 ( V_30 -> V_218 ) ;
if ( V_120 == 0 )
return 0 ;
if ( V_120 > V_222 ) {
F_2 ( F_45 ( V_30 ) ,
L_70 ,
V_120 , V_222 ) ;
return - V_76 ;
}
if ( F_177 () ) {
F_2 ( F_45 ( V_30 ) ,
L_71 ) ;
return - V_209 ;
}
V_7 = F_17 ( V_30 ) ;
V_190 = F_168 ( V_7 , F_167 ( V_7 , V_192 ) ) ;
if ( ! V_190 )
return - V_77 ;
V_50 = F_46 ( 0 , V_16 ) ;
if ( ! V_50 )
return - V_17 ;
V_205 = sizeof( struct V_221 ) +
V_120 * sizeof( struct V_194 ) ;
V_69 = F_8 ( V_205 , V_16 ) ;
if ( ! V_69 ) {
V_5 = - V_17 ;
goto error;
}
V_69 -> V_82 = F_112 ( V_223 ) ;
for ( V_98 = 0 ; V_98 < V_120 ; V_98 ++ ) {
struct V_194 * V_224 = & V_69 -> V_225 [ V_98 ] ;
V_224 -> V_45 = F_112 ( ( T_1 ) V_220 [ V_98 ] . V_45 ) ;
V_224 -> V_203 = F_112 ( V_220 [ V_98 ] . V_203 ) ;
}
if ( F_169 ( & V_190 -> V_173 ) )
F_51 ( V_50 , V_7 , F_167 ( V_7 , V_192 ) ,
V_69 , V_205 , F_184 , V_30 ,
V_190 -> V_173 . V_226 ) ;
else
F_64 ( V_50 , V_7 , F_93 ( V_7 , V_192 ) ,
V_69 , V_205 , F_184 , V_30 ) ;
V_50 -> V_96 |= V_227 ;
V_5 = F_185 ( V_30 , false ) ;
if ( V_5 ) {
F_2 ( F_45 ( V_30 ) ,
L_79
L_80 , V_5 ) ;
goto error;
}
V_30 -> V_216 = V_50 ;
return 0 ;
error:
F_54 ( V_50 ) ;
return V_5 ;
}
int F_191 ( struct V_29 * V_30 , const struct V_219 * V_220 ,
unsigned int V_120 )
{
int V_5 ;
F_186 ( V_30 ) ;
V_5 = F_190 ( V_30 , V_220 , V_120 ) ;
if ( V_5 ) {
F_188 ( V_30 , 0 ) ;
return V_5 ;
}
return F_188 ( V_30 , 50 ) ;
}
int F_192 ( struct V_29 * V_30 , T_9 V_203 , T_2 V_228 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_229 * V_69 = NULL ;
int V_98 , V_205 , V_206 ;
T_1 V_230 ;
if ( F_177 () ) {
F_2 ( F_45 ( V_30 ) ,
L_71 ) ;
return - V_209 ;
}
if ( V_228 < V_231 ) {
F_2 ( F_45 ( V_30 ) ,
L_82
L_83 ,
V_228 , V_231 ) ;
return - V_76 ;
}
if ( V_228 > V_232 ) {
F_2 ( F_45 ( V_30 ) ,
L_84 ,
V_228 , V_232 ) ;
return - V_76 ;
}
#ifdef F_193
if ( V_203 & ( ~ 0UL << V_228 ) ) {
F_2 ( F_45 ( V_30 ) ,
L_85 ,
V_203 , V_228 ) ;
return - V_76 ;
}
#endif
F_2 ( F_45 ( V_30 ) , L_86 , V_203 , V_228 ) ;
V_5 = F_194 ( V_30 , & V_230 , V_233 ) ;
if ( V_5 ) {
F_2 ( F_45 ( V_30 ) ,
L_87 , V_5 ) ;
return V_5 ;
}
V_230 &= ~ ( V_234 | V_235 | V_236 ) ;
F_30 ( F_178 ( & F_179 ( V_30 ) -> V_185 ) ) ;
F_180 ( sizeof( struct V_229 ) +
V_232 * sizeof( T_4 ) >
sizeof( V_30 -> V_210 ) ) ;
F_181 ( sizeof( struct V_229 ) + V_228 * sizeof( T_4 ) >
sizeof( V_30 -> V_210 ) ) ;
V_205 = sizeof( struct V_229 ) + V_228 * sizeof( T_4 ) ;
V_69 = ( void * ) V_30 -> V_210 ;
V_69 -> V_82 = F_112 ( V_237 ) ;
V_69 -> V_203 = F_112 ( 2 ) ;
V_69 -> V_228 = F_112 ( V_228 ) ;
for ( V_98 = 0 ; V_98 < V_228 ; V_98 ++ ) {
T_1 V_238 = V_230 ;
if ( V_203 & ( 1 << ( V_228 - 1 - V_98 ) ) )
V_238 |= V_236 ;
V_69 -> V_239 [ V_98 ] = F_112 ( V_238 ) ;
}
V_7 = F_17 ( V_30 ) ;
V_5 = F_166 ( V_7 , V_69 , V_205 , & V_206 , 50 ) ;
if ( V_5 ) {
F_2 ( F_45 ( V_30 ) ,
L_73 , V_5 ) ;
goto V_71;
}
if ( V_205 != V_206 ) {
F_2 ( F_45 ( V_30 ) , L_88
L_75 ,
V_205 , V_206 ) ;
V_5 = - V_49 ;
goto V_71;
}
V_71:
return V_5 ;
}
