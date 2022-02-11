struct V_1 * F_1 ( int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( V_5 [ V_3 ] . V_6 == V_2 )
return V_5 + V_3 ;
}
F_2 ( 0 , L_1 , ( char * ) & V_2 ) ;
return NULL ;
}
void F_3 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
V_8 -> V_11 = 0 ;
F_4 ( & V_10 -> V_12 , V_13 ) ;
F_4 ( & V_10 -> V_12 , V_14 ) ;
}
void F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
int V_15 = 100 ;
T_1 V_12 ;
F_4 ( & V_10 -> V_12 , 0 ) ;
V_12 = F_6 ( & V_10 -> V_12 ) ;
if ( V_12 & 0x3f0000 )
F_4 ( & V_10 -> V_12 , V_12 & 0x3f0000 ) ;
if ( V_12 & V_16 ) {
do {
V_12 = F_6 ( & V_10 -> V_12 ) ;
if ( V_12 & V_17 )
break;
} while ( V_15 -- );
if ( V_15 < 0 ) {
F_4 ( & V_10 -> V_12 , V_13 ) ;
F_4 ( & V_10 -> V_12 , 0 ) ;
} else {
F_4 ( & V_10 -> V_12 , V_12 & 0x3f0000 ) ;
}
}
V_8 -> V_11 = 0 ;
}
static int F_7 ( struct V_18 * V_19 )
{
struct V_20 * V_21 , * V_22 ;
F_2 ( 1 , L_2 , V_23 , ( unsigned long ) V_19 ) ;
if ( ! F_8 ( & V_19 -> V_24 ) ) {
V_21 = F_9 ( V_19 -> V_24 . V_25 , struct V_20 , V_26 . V_27 ) ;
F_2 ( 2 , L_3 ,
V_21 , V_21 -> V_26 . V_3 ) ;
F_5 ( V_19 -> V_8 ) ;
F_10 (buf, prev, &vidq->active, vb.queue) {
F_11 ( & V_21 -> V_26 . V_27 ) ;
V_21 -> V_26 . V_28 = V_29 ;
F_12 ( & V_21 -> V_26 . V_30 ) ;
}
F_13 ( & V_19 -> V_31 , V_32 + V_33 ) ;
return 0 ;
}
V_22 = NULL ;
for (; ; ) {
if ( F_8 ( & V_19 -> V_34 ) )
return 0 ;
V_21 = F_9 ( V_19 -> V_34 . V_25 , struct V_20 , V_26 . V_27 ) ;
if ( V_22 == NULL ) {
F_14 ( & V_21 -> V_26 . V_27 , & V_19 -> V_24 ) ;
F_2 ( 1 , L_4 ) ;
F_5 ( V_19 -> V_8 ) ;
F_3 ( V_19 -> V_8 ) ;
V_21 -> V_26 . V_28 = V_35 ;
F_13 ( & V_19 -> V_31 , V_32 + V_33 ) ;
F_2 ( 2 , L_5 ,
V_21 , V_21 -> V_26 . V_3 ) ;
} else if ( V_22 -> V_26 . V_36 == V_21 -> V_26 . V_36 &&
V_22 -> V_26 . V_37 == V_21 -> V_26 . V_37 &&
V_22 -> V_38 == V_21 -> V_38 ) {
F_14 ( & V_21 -> V_26 . V_27 , & V_19 -> V_24 ) ;
V_21 -> V_26 . V_28 = V_35 ;
F_2 ( 2 , L_6 ,
V_21 , V_21 -> V_26 . V_3 ) ;
} else {
return 0 ;
}
V_22 = V_21 ;
}
}
static void F_15 ( unsigned long V_39 )
{
struct V_7 * V_8 = (struct V_7 * ) V_39 ;
struct V_20 * V_21 ;
struct V_18 * V_19 = & V_8 -> V_19 ;
while ( ! F_8 ( & V_19 -> V_24 ) ) {
V_21 = F_9 ( V_19 -> V_24 . V_25 , struct V_20 , V_26 . V_27 ) ;
F_11 ( & V_21 -> V_26 . V_27 ) ;
V_21 -> V_26 . V_28 = V_29 ;
F_12 ( & V_21 -> V_26 . V_30 ) ;
F_2 ( 1 , L_7 , V_21 , V_21 -> V_26 . V_3 ) ;
}
F_7 ( V_19 ) ;
}
static int F_16 ( struct V_40 * V_41 , unsigned int * V_42 ,
unsigned int * V_43 )
{
struct V_44 * V_45 = V_41 -> V_46 ;
* V_43 = V_45 -> V_36 * V_45 -> V_37 * V_45 -> V_38 -> V_47 >> 3 ;
if ( * V_42 == 0 )
* V_42 = 32 ;
while ( * V_43 * * V_42 > V_48 * 1024 * 1024 )
( * V_42 ) -- ;
F_2 ( 1 , L_8 , V_23 , * V_42 , * V_43 ) ;
return 0 ;
}
static void F_17 ( struct V_40 * V_41 , struct V_20 * V_21 )
{
struct V_49 * V_26 = & V_21 -> V_26 ;
void * V_50 = NULL ;
F_18 ( F_19 () ) ;
F_20 ( V_41 , & V_21 -> V_26 , 0 , 0 ) ;
if ( V_41 -> V_51 && V_41 -> V_51 -> V_50 )
V_50 = V_41 -> V_51 -> V_50 ( V_26 ) ;
if ( V_50 )
F_21 ( V_41 , & V_21 -> V_26 ) ;
V_21 -> V_26 . V_28 = V_52 ;
}
inline int F_22 ( struct V_7 * V_8 , struct V_20 * V_21 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
int V_53 ;
V_54 . V_55 = F_23 ( & V_21 -> V_26 ) ;
F_2 ( 1 , L_9 ,
V_21 , V_21 -> V_26 . V_3 , ( unsigned long ) V_54 . V_55 ) ;
V_54 . V_12 = 0 ;
V_53 = V_21 -> V_38 -> V_47 >> 3 ;
switch ( V_53 ) {
case 2 :
V_54 . V_12 &= ~ V_56 ;
V_54 . V_57 = V_21 -> V_26 . V_36 * 2 ;
break;
case 4 :
V_54 . V_12 |= V_56 ;
V_54 . V_57 = V_21 -> V_26 . V_36 * 4 ;
break;
default:
F_2 ( 0 , L_10 ,
V_53 * 8 ) ;
return - V_58 ;
}
V_54 . V_59 = ( V_21 -> V_26 . V_37 / 2 ) << 16 |
V_21 -> V_26 . V_36 ;
V_54 . V_12 |= V_16 | V_60 | V_14 ;
V_21 -> V_26 . V_28 = V_35 ;
V_8 -> V_61 = V_21 -> V_26 . V_11 ;
if ( ! F_24 ( V_21 -> V_26 . V_11 ) )
V_54 . V_57 = 0 ;
F_4 ( & V_10 -> V_57 , V_54 . V_57 ) ;
F_4 ( & V_10 -> V_59 , V_54 . V_59 ) ;
F_4 ( & V_10 -> V_55 , V_54 . V_55 ) ;
F_13 ( & V_8 -> V_19 . V_31 , V_32 + V_33 ) ;
return 0 ;
}
static int F_25 ( struct V_40 * V_41 ,
struct V_49 * V_26 ,
enum V_62 V_11 )
{
struct V_44 * V_45 = V_41 -> V_46 ;
struct V_20 * V_21 = F_26 ( V_26 , struct V_20 , V_26 ) ;
int V_63 ;
F_18 ( V_45 -> V_38 == NULL ) ;
if ( V_45 -> V_36 < 48 || V_45 -> V_36 > F_27 () ||
V_45 -> V_37 < 32 || V_45 -> V_37 > F_28 () )
return - V_58 ;
V_21 -> V_26 . V_43 = ( V_45 -> V_36 * V_45 -> V_37 * V_45 -> V_38 -> V_47 ) >> 3 ;
if ( V_21 -> V_26 . V_64 != 0 && V_21 -> V_26 . V_65 < V_21 -> V_26 . V_43 )
return - V_58 ;
if ( V_21 -> V_38 != V_45 -> V_38 ||
V_21 -> V_26 . V_36 != V_45 -> V_36 ||
V_21 -> V_26 . V_37 != V_45 -> V_37 ||
V_21 -> V_26 . V_11 != V_11 ) {
V_21 -> V_38 = V_45 -> V_38 ;
V_21 -> V_26 . V_36 = V_45 -> V_36 ;
V_21 -> V_26 . V_37 = V_45 -> V_37 ;
V_21 -> V_26 . V_11 = V_11 ;
}
if ( V_21 -> V_26 . V_28 == V_52 ) {
V_63 = F_29 ( V_41 , & V_21 -> V_26 , NULL ) ;
if ( V_63 != 0 )
goto V_66;
V_21 -> V_26 . V_36 = V_45 -> V_36 ;
V_21 -> V_26 . V_37 = V_45 -> V_37 ;
V_21 -> V_26 . V_11 = V_11 ;
V_21 -> V_38 = V_45 -> V_38 ;
}
V_21 -> V_26 . V_28 = V_67 ;
return 0 ;
V_66:
F_17 ( V_41 , V_21 ) ;
return V_63 ;
}
static void F_30 ( struct V_40 * V_41 , struct V_49 * V_26 )
{
struct V_20 * V_21 = F_26 ( V_26 , struct V_20 , V_26 ) ;
struct V_44 * V_45 = V_41 -> V_46 ;
struct V_7 * V_8 = V_45 -> V_8 ;
struct V_18 * V_19 = & V_8 -> V_19 ;
struct V_20 * V_22 ;
if ( ! F_8 ( & V_19 -> V_34 ) ) {
F_2 ( 1 , L_11 ,
( unsigned long ) & V_21 -> V_26 . V_27 ) ;
F_2 ( 1 , L_12 ,
V_19 , & V_19 -> V_34 ) ;
F_2 ( 1 , L_13 ,
V_8 , & V_19 -> V_34 , V_19 -> V_34 . V_25 ,
V_19 -> V_34 . V_22 ) ;
F_31 ( & V_21 -> V_26 . V_27 , & V_19 -> V_34 ) ;
V_21 -> V_26 . V_28 = V_68 ;
F_2 ( 2 , L_14 ,
V_21 , V_21 -> V_26 . V_3 ) ;
} else if ( F_8 ( & V_19 -> V_24 ) ) {
F_2 ( 1 , L_15 ,
( unsigned long ) & V_21 -> V_26 . V_27 ) ;
F_31 ( & V_21 -> V_26 . V_27 , & V_19 -> V_24 ) ;
V_21 -> V_26 . V_28 = V_35 ;
F_13 ( & V_19 -> V_31 , V_32 + V_33 ) ;
F_2 ( 2 , L_16 ,
V_21 , V_21 -> V_26 . V_3 ) ;
F_22 ( V_8 , V_21 ) ;
} else {
F_2 ( 1 , L_17 ,
( unsigned long ) & V_21 -> V_26 . V_27 ) ;
V_22 = F_9 ( V_19 -> V_24 . V_22 , struct V_20 , V_26 . V_27 ) ;
if ( V_22 -> V_26 . V_36 == V_21 -> V_26 . V_36 &&
V_22 -> V_26 . V_37 == V_21 -> V_26 . V_37 &&
V_22 -> V_38 == V_21 -> V_38 ) {
F_31 ( & V_21 -> V_26 . V_27 , & V_19 -> V_24 ) ;
V_21 -> V_26 . V_28 = V_35 ;
F_2 ( 2 , L_18 ,
V_21 , V_21 -> V_26 . V_3 ) ;
} else {
F_31 ( & V_21 -> V_26 . V_27 , & V_19 -> V_34 ) ;
V_21 -> V_26 . V_28 = V_68 ;
F_2 ( 2 , L_19 ,
V_21 , V_21 -> V_26 . V_3 ) ;
}
}
}
static void F_32 ( struct V_40 * V_41 ,
struct V_49 * V_26 )
{
struct V_20 * V_21 = F_26 ( V_26 , struct V_20 , V_26 ) ;
struct V_44 * V_45 = V_41 -> V_46 ;
struct V_7 * V_8 = (struct V_7 * ) V_45 -> V_8 ;
F_5 ( V_8 ) ;
F_17 ( V_41 , V_21 ) ;
}
static int F_33 ( struct V_69 * V_69 , void * V_70 ,
struct V_71 * V_72 )
{
strcpy ( V_72 -> V_73 , L_20 ) ;
strcpy ( V_72 -> V_74 , L_20 ) ;
V_72 -> V_75 = V_76 |
V_77 |
V_78 |
V_79 ;
return 0 ;
}
static int F_34 ( struct V_69 * V_69 , void * V_70 ,
struct V_80 * V_81 )
{
int V_82 = V_81 -> V_82 ;
if ( V_81 -> V_82 > V_4 )
return - V_58 ;
F_35 ( V_81 -> V_83 , V_5 [ V_82 ] . V_84 , sizeof( V_81 -> V_83 ) ) ;
V_81 -> V_6 = V_5 [ V_82 ] . V_2 ;
return 0 ;
}
static int F_36 ( struct V_69 * V_69 , void * V_70 ,
struct V_85 * V_81 )
{
struct V_44 * V_45 = V_70 ;
V_81 -> V_38 . V_86 . V_36 = V_45 -> V_36 ;
V_81 -> V_38 . V_86 . V_37 = V_45 -> V_37 ;
V_81 -> V_38 . V_86 . V_11 = V_45 -> V_87 . V_11 ;
V_81 -> V_38 . V_86 . V_6 = V_45 -> V_38 -> V_6 ;
V_81 -> V_38 . V_86 . V_88 =
( V_81 -> V_38 . V_86 . V_36 * V_45 -> V_38 -> V_47 ) >> 3 ;
V_81 -> V_38 . V_86 . V_89 = V_45 -> V_89 ;
return 0 ;
}
static int F_37 ( struct V_69 * V_69 , void * V_70 ,
struct V_85 * V_81 )
{
struct V_1 * V_38 ;
enum V_62 V_11 ;
unsigned int V_90 , V_91 ;
V_38 = F_1 ( V_81 -> V_38 . V_86 . V_6 ) ;
if ( ! V_38 ) {
F_2 ( 1 , L_21 ,
V_81 -> V_38 . V_86 . V_6 ) ;
return - V_58 ;
}
V_11 = V_81 -> V_38 . V_86 . V_11 ;
if ( V_11 == V_92 ) {
V_11 = V_93 ;
} else if ( V_11 != V_93 ) {
F_2 ( 1 , L_22 ) ;
return - V_58 ;
}
V_90 = F_27 () ;
V_91 = F_28 () ;
V_81 -> V_38 . V_86 . V_11 = V_11 ;
if ( V_81 -> V_38 . V_86 . V_37 < 32 )
V_81 -> V_38 . V_86 . V_37 = 32 ;
if ( V_81 -> V_38 . V_86 . V_37 > V_91 )
V_81 -> V_38 . V_86 . V_37 = V_91 ;
if ( V_81 -> V_38 . V_86 . V_36 < 48 )
V_81 -> V_38 . V_86 . V_36 = 48 ;
if ( V_81 -> V_38 . V_86 . V_36 > V_90 )
V_81 -> V_38 . V_86 . V_36 = V_90 ;
V_81 -> V_38 . V_86 . V_36 &= ~ 0x03 ;
V_81 -> V_38 . V_86 . V_88 =
( V_81 -> V_38 . V_86 . V_36 * V_38 -> V_47 ) >> 3 ;
return 0 ;
}
static int F_38 ( struct V_69 * V_69 , void * V_70 ,
struct V_85 * V_81 )
{
struct V_44 * V_45 = V_70 ;
int V_94 ;
V_94 = F_37 ( V_69 , V_45 , V_81 ) ;
if ( V_94 < 0 )
return V_94 ;
V_45 -> V_38 = F_1 ( V_81 -> V_38 . V_86 . V_6 ) ;
V_45 -> V_36 = V_81 -> V_38 . V_86 . V_36 ;
V_45 -> V_37 = V_81 -> V_38 . V_86 . V_37 ;
V_45 -> V_89 = V_81 -> V_38 . V_86 . V_89 ;
V_45 -> V_87 . V_11 = V_81 -> V_38 . V_86 . V_11 ;
V_45 -> type = V_81 -> type ;
F_2 ( 1 , L_23 , ( char * ) & V_45 -> V_38 -> V_84 ) ;
return 0 ;
}
static int F_39 ( struct V_69 * V_69 , void * V_70 ,
struct V_85 * V_81 )
{
struct V_44 * V_45 = V_70 ;
V_81 -> V_38 . V_95 = V_45 -> V_95 ;
return 0 ;
}
static int F_40 ( struct V_7 * V_8 , struct V_96 * V_95 )
{
enum V_62 V_11 ;
int V_90 , V_91 ;
if ( V_8 -> V_97 . V_98 == NULL )
return - V_58 ;
if ( V_8 -> V_99 == NULL )
return - V_58 ;
if ( V_95 -> V_100 . V_36 < 48 || V_95 -> V_100 . V_37 < 32 )
return - V_58 ;
V_11 = V_95 -> V_11 ;
V_90 = V_8 -> V_101 . V_36 ;
V_91 = V_8 -> V_101 . V_37 ;
if ( V_11 == V_92 ) {
V_11 = ( V_95 -> V_100 . V_37 > V_91 / 2 )
? V_93
: V_102 ;
}
switch ( V_11 ) {
case V_102 :
case V_103 :
V_91 = V_91 / 2 ;
break;
case V_93 :
break;
default:
return - V_58 ;
}
V_95 -> V_11 = V_11 ;
if ( V_95 -> V_100 . V_36 > V_90 )
V_95 -> V_100 . V_36 = V_90 ;
if ( V_95 -> V_100 . V_37 > V_91 )
V_95 -> V_100 . V_37 = V_91 ;
return 0 ;
}
inline void F_41 ( struct V_9 * V_9 )
{
struct V_9 * V_10 = V_9 ;
F_4 ( & V_10 -> V_55 , V_54 . V_55 ) ;
F_4 ( & V_10 -> V_57 , V_54 . V_57 ) ;
F_4 ( & V_10 -> V_59 , V_54 . V_59 ) ;
}
static int F_42 ( struct V_7 * V_8 , struct V_44 * V_45 )
{
int V_53 ;
F_2 ( 1 , L_24 , V_23 ,
V_45 -> V_95 . V_100 . V_36 , V_45 -> V_95 . V_100 . V_37 , V_8 -> V_99 -> V_84 ) ;
V_54 . V_12 = 0 ;
V_54 . V_59 = ( V_45 -> V_95 . V_100 . V_37 / 2 ) << 16 |
V_45 -> V_95 . V_100 . V_36 ;
V_53 = V_8 -> V_99 -> V_47 / 8 ;
switch ( V_53 ) {
case 2 :
V_54 . V_12 &= ~ V_56 ;
V_54 . V_57 = V_45 -> V_95 . V_100 . V_36 * 2 ;
break;
case 4 :
V_54 . V_12 |= V_56 ;
V_54 . V_57 = V_45 -> V_95 . V_100 . V_36 * 4 ;
break;
default:
F_2 ( 0 , L_25 ,
V_53 * 8 ) ;
return - V_58 ;
}
V_8 -> V_104 = V_45 -> V_95 . V_11 ;
if ( ! F_24 ( V_8 -> V_104 ) )
V_54 . V_57 = 0 ;
V_54 . V_12 |= V_16 | V_60 | V_14 ;
V_54 . V_55 = ( T_1 ) V_8 -> V_97 . V_98 ;
return 0 ;
}
static int F_43 ( struct V_69 * V_69 , void * V_70 ,
struct V_85 * V_81 )
{
struct V_44 * V_45 = V_70 ;
struct V_7 * V_8 = (struct V_7 * ) V_45 -> V_8 ;
unsigned long V_105 ;
int V_106 ;
V_106 = F_40 ( V_8 , & V_81 -> V_38 . V_95 ) ;
if ( V_106 )
return V_106 ;
V_45 -> V_95 = V_81 -> V_38 . V_95 ;
F_44 ( & V_8 -> V_107 , V_105 ) ;
F_42 ( V_8 , V_45 ) ;
F_45 ( & V_8 -> V_107 , V_105 ) ;
return 0 ;
}
static int F_46 ( struct V_69 * V_69 , void * V_70 ,
struct V_85 * V_81 )
{
return 0 ;
}
static int F_47 ( struct V_69 * V_69 , void * V_70 , unsigned int V_108 )
{
struct V_44 * V_45 = V_70 ;
struct V_7 * V_8 = (struct V_7 * ) V_45 -> V_8 ;
unsigned long V_105 ;
if ( V_108 ) {
F_44 ( & V_8 -> V_107 , V_105 ) ;
F_41 ( V_8 -> V_10 ) ;
V_8 -> V_109 = 1 ;
F_3 ( V_8 ) ;
F_45 ( & V_8 -> V_107 , V_105 ) ;
} else {
F_5 ( V_8 ) ;
V_8 -> V_109 = 0 ;
}
return 0 ;
}
int F_48 ( struct V_69 * V_69 , void * V_70 , struct V_110 * V_111 )
{
struct V_44 * V_45 = V_70 ;
struct V_7 * V_8 = V_45 -> V_8 ;
struct V_110 * V_112 = V_111 ;
* V_112 = V_8 -> V_97 ;
V_112 -> V_113 = V_114 ;
return 0 ;
}
int F_49 ( struct V_69 * V_69 , void * V_70 , const struct V_110 * V_111 )
{
struct V_44 * V_45 = V_70 ;
struct V_7 * V_8 = V_45 -> V_8 ;
const struct V_110 * V_112 = V_111 ;
struct V_1 * V_38 ;
if ( ! F_50 ( V_115 ) && ! F_50 ( V_116 ) )
return - V_117 ;
V_38 = F_1 ( V_112 -> V_38 . V_6 ) ;
if ( V_38 == NULL )
return - V_58 ;
V_8 -> V_97 = * V_112 ;
V_8 -> V_99 = V_38 ;
if ( V_8 -> V_97 . V_38 . V_88 == 0 ) {
V_8 -> V_97 . V_38 . V_88 =
V_8 -> V_97 . V_38 . V_36 * V_38 -> V_47 / 8 ;
}
return 0 ;
}
static int F_51 ( struct V_69 * V_69 , void * V_70 ,
struct V_118 * V_119 )
{
struct V_44 * V_45 = V_70 ;
return F_52 ( & V_45 -> V_87 , V_119 ) ;
}
static int F_53 ( struct V_69 * V_69 , void * V_70 ,
struct V_120 * V_119 )
{
struct V_44 * V_45 = V_70 ;
return F_54 ( & V_45 -> V_87 , V_119 ) ;
}
static int F_55 ( struct V_69 * V_69 , void * V_70 , struct V_120 * V_119 )
{
struct V_44 * V_45 = V_70 ;
return F_56 ( & V_45 -> V_87 , V_119 ) ;
}
static int F_57 ( struct V_69 * V_69 , void * V_70 , struct V_120 * V_119 )
{
struct V_44 * V_45 = V_70 ;
return F_58 ( & V_45 -> V_87 , V_119 ,
V_69 -> V_121 & V_122 ) ;
}
static int F_59 ( struct V_69 * V_69 , void * V_70 , enum V_123 V_3 )
{
struct V_44 * V_45 = V_70 ;
struct V_7 * V_8 = V_45 -> V_8 ;
if ( V_45 -> type != V_124 )
return - V_58 ;
if ( V_45 -> type != V_3 )
return - V_58 ;
if ( V_8 -> V_109 )
V_8 -> V_109 = 0 ;
F_3 ( V_45 -> V_8 ) ;
return F_60 ( & V_45 -> V_87 ) ;
}
static int F_61 ( struct V_69 * V_69 , void * V_70 , enum V_123 V_3 )
{
struct V_44 * V_45 = V_70 ;
if ( V_45 -> type != V_124 )
return - V_58 ;
if ( V_45 -> type != V_3 )
return - V_58 ;
F_5 ( V_45 -> V_8 ) ;
return F_62 ( & V_45 -> V_87 ) ;
}
static int F_63 ( struct V_69 * V_69 , void * V_70 , T_2 * V_125 )
{
struct V_44 * V_45 = V_70 ;
F_64 ( V_45 -> V_8 , V_126 , V_127 , V_125 ) ;
return 0 ;
}
static int F_65 ( struct V_69 * V_69 , void * V_70 , T_2 V_128 )
{
struct V_44 * V_45 = V_70 ;
V_45 -> V_8 -> V_129 = V_128 ;
F_64 ( V_45 -> V_8 , V_130 , V_131 , V_128 ) ;
return 0 ;
}
static int F_66 ( struct V_69 * V_69 , void * V_70 , T_2 * V_125 )
{
struct V_44 * V_45 = V_70 ;
* V_125 = V_45 -> V_8 -> V_129 ;
return 0 ;
}
static int F_67 ( struct V_69 * V_69 , void * V_70 ,
struct V_132 * V_133 )
{
struct V_44 * V_45 = V_70 ;
if ( V_133 -> V_82 != 0 )
return - V_58 ;
V_133 -> type = V_134 ;
V_133 -> V_129 = V_45 -> V_8 -> V_135 -> V_136 ;
strcpy ( V_133 -> V_84 , L_26 ) ;
return 0 ;
}
static int F_68 ( struct V_69 * V_69 , void * V_70 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_69 ( struct V_69 * V_69 , void * V_70 , unsigned int V_3 )
{
struct V_44 * V_45 = V_70 ;
if ( V_3 > 1 )
return - V_58 ;
F_64 ( V_45 -> V_8 , V_126 , V_137 , V_3 , 0 , 0 ) ;
return 0 ;
}
static int F_70 ( struct V_69 * V_69 , void * V_70 ,
struct V_138 * V_139 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_71 ( V_140 ) ; V_3 ++ ) {
if ( V_139 -> V_128 && V_139 -> V_128 == V_140 [ V_3 ] . V_128 ) {
memcpy ( V_139 , & ( V_140 [ V_3 ] ) , sizeof( * V_139 ) ) ;
return 0 ;
}
}
return - V_58 ;
}
static int F_72 ( struct V_69 * V_69 , void * V_70 ,
struct V_141 * V_142 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_71 ( V_140 ) ; V_3 ++ ) {
if ( V_142 -> V_128 == V_140 [ V_3 ] . V_128 ) {
V_142 -> V_143 = V_144 [ V_3 ] ;
return 0 ;
}
}
return - V_58 ;
}
static int F_73 ( struct V_69 * V_69 , void * V_70 ,
struct V_141 * V_142 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_71 ( V_140 ) ; V_3 ++ ) {
if ( V_142 -> V_128 == V_140 [ V_3 ] . V_128 ) {
if ( V_142 -> V_143 < V_140 [ V_3 ] . V_145
|| V_142 -> V_143 > V_140 [ V_3 ] . V_146 )
return - V_147 ;
V_144 [ V_3 ] = V_142 -> V_143 ;
return 0 ;
}
}
return - V_58 ;
}
inline void F_74 ( struct V_7 * V_8 ,
struct V_18 * V_148 )
{
struct V_18 * V_19 = V_148 ;
struct V_20 * V_21 ;
if ( ! F_8 ( & V_19 -> V_24 ) ) {
V_21 = F_9 ( V_19 -> V_24 . V_25 , struct V_20 ,
V_26 . V_27 ) ;
F_2 ( 1 , L_27 , V_21 ) ;
F_22 ( V_8 , V_21 ) ;
} else if ( ! F_8 ( & V_19 -> V_34 ) ) {
V_21 = F_9 ( V_19 -> V_34 . V_25 , struct V_20 ,
V_26 . V_27 ) ;
F_11 ( & V_21 -> V_26 . V_27 ) ;
F_2 ( 1 , L_27 , V_21 ) ;
F_31 ( & V_21 -> V_26 . V_27 , & V_19 -> V_24 ) ;
V_21 -> V_26 . V_28 = V_35 ;
F_22 ( V_8 , V_21 ) ;
}
}
inline void F_75 ( struct V_9 * V_9 )
{
struct V_9 * V_10 = V_9 ;
F_4 ( & V_10 -> V_149 , 0x9512A254 ) ;
F_4 ( & V_10 -> V_150 , 0x03310000 ) ;
F_4 ( & V_10 -> V_151 , 0x06600F38 ) ;
F_4 ( & V_10 -> V_152 , 0x00000409 ) ;
F_4 ( & V_10 -> V_153 , 0x000000ff ) ;
F_4 ( & V_10 -> V_154 , 0x00000090 ) ;
F_2 ( 1 , L_28 ,
F_6 ( & V_10 -> V_12 ) , F_6 ( & V_10 -> V_55 ) ) ;
}
static void F_76 ( struct V_7 * V_8 , T_1 V_155 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
if ( V_155 & V_17 )
V_8 -> V_156 = 1 ;
if ( V_155 & V_157 ) {
if ( V_8 -> V_156 ) {
T_1 V_158 = V_54 . V_55 ;
V_8 -> V_156 = 0 ;
if ( V_155 & V_159 )
V_158 += V_54 . V_57 ;
F_4 ( & V_10 -> V_55 , V_158 ) ;
F_4 ( & V_10 -> V_57 , V_54 . V_57 ) ;
F_4 ( & V_10 -> V_12 ,
( V_155 & 0xffc0ffff ) |
( V_155 & V_160 ) |
V_54 . V_12 ) ;
} else if ( V_155 & V_161 ) {
F_4 ( & V_10 -> V_12 ,
( V_155 & 0xffc0ffff ) |
( V_155 & V_160 ) |
V_54 . V_12 ) ;
}
}
}
static void F_77 ( struct V_7 * V_8 , T_1 V_155 )
{
struct V_18 * V_19 = & V_8 -> V_19 ;
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_20 * V_21 ;
int V_162 ;
int V_163 ;
int V_156 = 0 ;
V_162 = V_155 & V_159 ;
V_163 = F_24 ( V_8 -> V_61 ) ;
if ( V_155 & V_17 ) {
V_156 = 1 ;
if ( ( ( V_162 == 0 ) && ( V_8 -> V_11 == 0 ) ) ||
( V_162 && ( V_8 -> V_11 == 1 ) ) )
V_8 -> V_11 ++ ;
}
if ( V_155 & V_157 ) {
F_2 ( 1 , L_29 ,
! ! V_162 , V_156 ) ;
if ( F_78 ( V_8 -> V_164 ) ) {
if ( V_162 == 0 ) {
V_8 -> V_164 = 0 ;
F_2 ( 1 , L_30 ) ;
F_74 ( V_8 , V_19 ) ;
} else
F_2 ( 1 , L_31 ) ;
return;
}
if ( ! F_8 ( & V_19 -> V_24 ) ) {
T_1 V_158 = V_54 . V_55 ;
if ( V_162 && V_163 ) {
V_158 += V_54 . V_57 ;
F_2 ( 1 , L_32 ,
( unsigned long ) V_158 , V_8 -> V_11 ) ;
}
F_4 ( & V_10 -> V_55 , V_158 ) ;
F_4 ( & V_10 -> V_57 , V_54 . V_57 ) ;
F_4 ( & V_10 -> V_12 ,
( V_155 & 0xffc0ffff ) |
( V_155 & V_160 ) |
V_54 . V_12 ) ;
return;
}
}
if ( V_156 && V_162 && ( V_8 -> V_11 == 2 ) ) {
V_8 -> V_11 = 0 ;
V_21 = F_9 ( V_19 -> V_24 . V_25 ,
struct V_20 , V_26 . V_27 ) ;
F_2 ( 1 , L_33 ,
V_21 , V_21 -> V_26 . V_3 ,
( unsigned long ) F_23 ( & V_21 -> V_26 ) ,
( unsigned long ) F_6 ( & V_10 -> V_55 ) ) ;
if ( F_79 ( & V_21 -> V_26 . V_30 ) ) {
F_11 ( & V_21 -> V_26 . V_27 ) ;
F_80 ( & V_21 -> V_26 . V_165 ) ;
V_21 -> V_26 . V_28 = V_166 ;
V_21 -> V_26 . V_167 ++ ;
F_12 ( & V_21 -> V_26 . V_30 ) ;
}
F_74 ( V_8 , V_19 ) ;
}
}
static T_3 F_81 ( int V_168 , void * V_169 )
{
struct V_7 * V_8 = (struct V_7 * ) V_169 ;
struct V_9 * V_10 = V_8 -> V_10 ;
T_1 V_155 ;
T_1 error ;
V_155 = F_6 ( & V_10 -> V_12 ) ;
if ( V_155 & V_170 ) {
V_8 -> V_171 . V_172 ++ ;
error = V_155 & V_173 ;
if ( error )
F_2 ( 1 , L_34 ,
error >> 4 , V_8 -> V_171 . V_172 ) ;
F_4 ( & V_10 -> V_12 ,
( V_155 & 0xffc0ffff ) | V_170 ) ;
}
if ( V_155 & V_17 ) {
V_8 -> V_171 . V_174 ++ ;
V_8 -> V_156 = 1 ;
F_2 ( 2 , L_35 ,
V_8 -> V_171 . V_174 ) ;
}
if ( V_155 & V_175 )
V_8 -> V_171 . V_176 ++ ;
if ( V_155 & V_157 ) {
V_8 -> V_171 . V_177 ++ ;
F_2 ( 2 , L_36 ,
V_8 -> V_171 . V_177 ) ;
}
if ( V_155 & V_178 )
V_8 -> V_171 . V_179 ++ ;
if ( V_155 & V_161 ) {
V_8 -> V_171 . V_180 ++ ;
F_2 ( 2 , L_37 ,
V_8 -> V_171 . V_180 ) ;
}
V_155 = F_6 ( & V_10 -> V_12 ) ;
F_4 ( & V_10 -> V_12 ,
( V_155 & 0xffc0ffff ) | ( V_155 & V_160 ) ) ;
if ( V_8 -> V_109 ) {
F_76 ( V_8 , V_155 ) ;
return V_181 ;
}
F_77 ( V_8 , V_155 ) ;
return V_181 ;
}
static int F_82 ( struct V_69 * V_69 )
{
struct V_182 * V_135 = F_83 ( V_69 ) ;
struct V_7 * V_8 = F_84 ( V_135 ) ;
struct V_44 * V_45 ;
struct V_9 * V_10 ;
int V_183 = V_135 -> V_183 ;
T_1 V_12 ;
int V_3 ;
F_2 ( 1 , L_38 , V_183 ) ;
V_8 -> V_184 ++ ;
if ( V_8 -> V_184 > 1 ) {
V_8 -> V_184 -- ;
return - V_185 ;
}
V_10 = V_8 -> V_10 ;
F_2 ( 1 , L_39 , V_183 ,
V_186 [ V_124 ] , V_8 -> V_184 ) ;
if ( F_85 ( & V_8 -> V_187 ) ) {
V_8 -> V_184 -- ;
return - V_188 ;
}
V_45 = F_86 ( sizeof( * V_45 ) , V_189 ) ;
if ( ! V_45 ) {
V_8 -> V_184 -- ;
F_87 ( & V_8 -> V_187 ) ;
return - V_190 ;
}
V_69 -> V_191 = V_45 ;
V_45 -> V_8 = V_8 ;
V_45 -> type = V_124 ;
V_45 -> V_38 = F_1 ( V_192 ) ;
V_45 -> V_36 = F_27 () ;
V_45 -> V_37 = F_28 () ;
V_8 -> V_101 . V_36 = V_45 -> V_36 ;
V_8 -> V_101 . V_37 = V_45 -> V_37 ;
for ( V_3 = 0 ; V_3 < F_71 ( V_140 ) ; V_3 ++ )
V_144 [ V_3 ] = V_140 [ V_3 ] . V_193 ;
F_2 ( 1 , L_40 ,
( unsigned long ) V_45 , ( unsigned long ) V_8 ,
( unsigned long ) & V_8 -> V_19 ) ;
F_2 ( 1 , L_41 ,
F_8 ( & V_8 -> V_19 . V_34 ) ) ;
F_2 ( 1 , L_42 ,
F_8 ( & V_8 -> V_19 . V_24 ) ) ;
F_75 ( V_10 ) ;
V_12 = F_6 ( & V_10 -> V_12 ) ;
F_4 ( & V_10 -> V_12 ,
V_12 & ~ ( V_194 | V_195 |
V_14 | V_196 |
V_60 | V_197 | V_198 ) ) ;
V_12 = F_6 ( & V_10 -> V_12 ) ;
F_4 ( & V_10 -> V_12 , V_12 | V_160 ) ;
F_88 ( & V_45 -> V_199 ) ;
F_89 ( & V_45 -> V_87 , & V_200 ,
V_8 -> V_8 , & V_45 -> V_199 ,
V_45 -> type , V_93 ,
sizeof( struct V_20 ) , V_45 ,
& V_45 -> V_8 -> V_187 ) ;
F_87 ( & V_8 -> V_187 ) ;
return 0 ;
}
static T_4 F_90 ( struct V_69 * V_69 , char T_5 * V_39 , T_6 V_42 ,
T_7 * V_201 )
{
struct V_44 * V_45 = V_69 -> V_191 ;
struct V_7 * V_8 = V_45 -> V_8 ;
int V_94 = 0 ;
F_2 ( 2 , L_43 , V_23 ) ;
if ( V_8 -> V_109 )
V_8 -> V_109 = 0 ;
if ( V_45 -> type == V_124 ) {
if ( F_85 ( & V_8 -> V_187 ) )
return - V_188 ;
F_3 ( V_8 ) ;
V_94 = F_91 ( & V_45 -> V_87 , V_39 , V_42 ,
V_201 , 0 , V_69 -> V_121 & V_122 ) ;
F_87 ( & V_8 -> V_187 ) ;
return V_94 ;
}
return 0 ;
}
static unsigned int F_92 ( struct V_69 * V_69 , struct V_202 * V_203 )
{
struct V_44 * V_45 = V_69 -> V_191 ;
struct V_40 * V_204 = & V_45 -> V_87 ;
struct V_7 * V_8 = V_45 -> V_8 ;
unsigned int V_205 ;
if ( V_124 != V_45 -> type )
return V_206 ;
F_93 ( & V_8 -> V_187 ) ;
V_205 = F_94 ( V_69 , V_204 , V_203 ) ;
F_87 ( & V_8 -> V_187 ) ;
return V_205 ;
}
static int F_95 ( struct V_69 * V_69 )
{
struct V_44 * V_45 = V_69 -> V_191 ;
struct V_7 * V_8 = V_45 -> V_8 ;
int V_183 = F_83 ( V_69 ) -> V_183 ;
F_93 ( & V_8 -> V_187 ) ;
F_5 ( V_8 ) ;
F_96 ( & V_45 -> V_87 ) ;
F_97 ( & V_45 -> V_87 ) ;
F_87 ( & V_8 -> V_187 ) ;
F_98 ( V_45 ) ;
V_8 -> V_184 -- ;
F_2 ( 1 , L_44 ,
V_183 , V_8 -> V_184 ) ;
return 0 ;
}
void F_99 ( struct V_9 * V_207 )
{
F_4 ( & V_207 -> V_12 , 0 ) ;
F_4 ( & V_207 -> V_149 , 0x9512a254 ) ;
F_4 ( & V_207 -> V_150 , 0x03310000 ) ;
F_4 ( & V_207 -> V_151 , 0x06600f38 ) ;
F_4 ( & V_207 -> V_152 , 0x00000409 ) ;
F_4 ( & V_207 -> V_55 , 0 ) ;
F_4 ( & V_207 -> V_57 , 0 ) ;
F_4 ( & V_207 -> V_59 , 0x01e002d0 ) ;
F_4 ( & V_207 -> V_154 , 0x00000090 ) ;
F_4 ( & V_207 -> V_153 , 0x000000ff ) ;
}
static int F_100 ( struct V_69 * V_69 , struct V_208 * V_209 )
{
struct V_44 * V_45 = V_69 -> V_191 ;
struct V_7 * V_8 = V_45 -> V_8 ;
int V_94 ;
F_2 ( 1 , L_45 , ( unsigned long ) V_209 ) ;
if ( F_85 ( & V_8 -> V_187 ) )
return - V_188 ;
V_94 = F_101 ( & V_45 -> V_87 , V_209 ) ;
F_87 ( & V_8 -> V_187 ) ;
F_2 ( 1 , L_46 ,
( unsigned long ) V_209 -> V_210 ,
( unsigned long ) V_209 -> V_211 - ( unsigned long ) V_209 -> V_210 ,
V_94 ) ;
return V_94 ;
}
static int F_102 ( struct V_212 * V_213 )
{
struct V_7 * V_7 ;
struct V_182 * V_135 ;
struct V_214 V_215 ;
struct V_9 T_8 * V_216 ;
struct V_217 * V_218 ;
int V_94 , V_219 ;
struct V_220 * V_220 ;
V_94 = F_103 ( V_213 -> V_8 . V_221 , 0 , & V_215 ) ;
if ( V_94 ) {
F_104 ( & V_213 -> V_8 , L_47 ) ;
return - V_222 ;
}
V_219 = F_105 ( V_213 -> V_8 . V_221 , 0 ) ;
if ( V_219 == V_223 ) {
F_104 ( & V_213 -> V_8 , L_48 ) ;
return - V_58 ;
}
if ( ! F_106 ( & V_213 -> V_8 , V_215 . V_224 ,
sizeof( struct V_9 ) , V_225 ) ) {
F_104 ( & V_213 -> V_8 , L_49 ) ;
V_94 = - V_185 ;
goto V_106;
}
V_216 = F_107 ( & V_213 -> V_8 , V_215 . V_224 , sizeof( struct V_9 ) ) ;
if ( ! V_216 ) {
F_104 ( & V_213 -> V_8 , L_50 ) ;
V_94 = - V_190 ;
goto V_106;
}
V_7 = F_108 ( & V_213 -> V_8 , sizeof( struct V_7 ) , V_226 ) ;
if ( ! V_7 ) {
F_104 ( & V_213 -> V_8 , L_51 ) ;
V_94 = - V_190 ;
goto V_106;
}
V_7 -> V_10 = V_216 ;
V_7 -> V_168 = V_219 ;
V_7 -> V_8 = & V_213 -> V_8 ;
F_109 ( & V_7 -> V_19 . V_24 ) ;
F_109 ( & V_7 -> V_19 . V_34 ) ;
snprintf ( V_7 -> V_227 . V_84 ,
sizeof( V_7 -> V_227 . V_84 ) , L_52 , L_53 ) ;
V_94 = F_110 ( V_7 -> V_8 , & V_7 -> V_227 ) ;
if ( V_94 < 0 ) {
F_104 ( & V_213 -> V_8 , L_54 , V_94 ) ;
goto V_106;
}
V_218 = F_111 ( 0 ) ;
V_7 -> V_228 = F_112 ( & V_7 -> V_227 , V_218 ,
L_55 , V_229 , NULL ) ;
V_7 -> V_19 . V_31 . V_230 = F_15 ;
V_7 -> V_19 . V_31 . V_39 = ( unsigned long ) V_7 ;
F_113 ( & V_7 -> V_19 . V_31 ) ;
V_7 -> V_129 = V_231 ;
V_7 -> V_164 = 1 ;
V_135 = F_114 () ;
if ( V_135 == NULL ) {
V_94 = - V_190 ;
goto V_232;
}
memcpy ( V_135 , & V_233 , sizeof( V_233 ) ) ;
V_135 -> V_227 = & V_7 -> V_227 ;
V_7 -> V_135 = V_135 ;
F_115 ( & V_7 -> V_187 ) ;
V_7 -> V_135 -> V_187 = & V_7 -> V_187 ;
F_88 ( & V_7 -> V_107 ) ;
F_116 ( V_7 -> V_135 , V_7 ) ;
F_93 ( & V_7 -> V_187 ) ;
V_94 = F_117 ( V_7 -> V_135 , V_234 , - 1 ) ;
if ( V_94 < 0 ) {
F_118 ( V_7 -> V_135 ) ;
goto V_232;
}
V_220 = F_119 ( & V_213 -> V_8 , L_56 ) ;
if ( F_120 ( V_220 ) ) {
F_104 ( & V_213 -> V_8 , L_57 ) ;
V_94 = F_121 ( V_220 ) ;
goto V_235;
}
V_94 = F_122 ( V_220 ) ;
if ( V_94 ) {
F_104 ( & V_213 -> V_8 , L_58 ) ;
goto V_235;
}
V_7 -> V_220 = V_220 ;
F_99 ( V_7 -> V_10 ) ;
if ( F_123 ( V_7 -> V_168 , F_81 , 0 , L_20 , ( void * ) V_7 ) ) {
F_104 ( & V_213 -> V_8 , L_59 ) ;
V_94 = - V_222 ;
goto V_236;
}
F_87 ( & V_7 -> V_187 ) ;
F_124 ( & V_213 -> V_8 , L_60 ) ;
return V_94 ;
V_236:
F_125 ( V_7 -> V_220 ) ;
V_235:
F_126 ( V_7 -> V_135 ) ;
V_232:
F_87 ( & V_7 -> V_187 ) ;
F_127 ( V_218 ) ;
F_128 ( & V_7 -> V_227 ) ;
V_106:
F_129 ( V_219 ) ;
return V_94 ;
}
static int F_130 ( struct V_212 * V_213 )
{
struct V_237 * V_227 = F_131 ( & V_213 -> V_8 ) ;
struct V_7 * V_8 = F_26 ( V_227 , struct V_7 , V_227 ) ;
struct V_238 * V_239 = F_9 ( V_227 -> V_240 . V_25 ,
struct V_238 , V_241 ) ;
struct V_242 * V_243 = F_132 ( V_239 ) ;
F_133 ( V_8 -> V_168 , ( void * ) V_8 ) ;
F_129 ( V_8 -> V_168 ) ;
F_125 ( V_8 -> V_220 ) ;
F_126 ( V_8 -> V_135 ) ;
F_127 ( V_243 -> V_244 ) ;
F_128 ( & V_8 -> V_227 ) ;
return 0 ;
}
static int F_134 ( struct V_212 * V_213 , T_9 V_28 )
{
struct V_237 * V_227 = F_131 ( & V_213 -> V_8 ) ;
struct V_7 * V_8 = F_26 ( V_227 , struct V_7 , V_227 ) ;
F_135 ( V_8 -> V_220 ) ;
return 0 ;
}
static int F_136 ( struct V_212 * V_213 )
{
struct V_237 * V_227 = F_131 ( & V_213 -> V_8 ) ;
struct V_7 * V_8 = F_26 ( V_227 , struct V_7 , V_227 ) ;
F_137 ( V_8 -> V_220 ) ;
return 0 ;
}
