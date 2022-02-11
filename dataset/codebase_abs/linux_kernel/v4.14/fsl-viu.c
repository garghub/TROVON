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
strcpy ( V_72 -> V_75 , L_21 ) ;
V_72 -> V_76 = V_77 |
V_78 |
V_79 |
V_80 ;
V_72 -> V_81 = V_72 -> V_76 | V_82 ;
return 0 ;
}
static int F_34 ( struct V_69 * V_69 , void * V_70 ,
struct V_83 * V_84 )
{
int V_85 = V_84 -> V_85 ;
if ( V_84 -> V_85 >= V_4 )
return - V_58 ;
V_84 -> V_6 = V_5 [ V_85 ] . V_2 ;
return 0 ;
}
static int F_35 ( struct V_69 * V_69 , void * V_70 ,
struct V_86 * V_84 )
{
struct V_44 * V_45 = V_70 ;
V_84 -> V_38 . V_87 . V_36 = V_45 -> V_36 ;
V_84 -> V_38 . V_87 . V_37 = V_45 -> V_37 ;
V_84 -> V_38 . V_87 . V_11 = V_45 -> V_88 . V_11 ;
V_84 -> V_38 . V_87 . V_6 = V_45 -> V_38 -> V_6 ;
V_84 -> V_38 . V_87 . V_89 =
( V_84 -> V_38 . V_87 . V_36 * V_45 -> V_38 -> V_47 ) >> 3 ;
V_84 -> V_38 . V_87 . V_90 = V_45 -> V_90 ;
V_84 -> V_38 . V_87 . V_91 = V_92 ;
return 0 ;
}
static int F_36 ( struct V_69 * V_69 , void * V_70 ,
struct V_86 * V_84 )
{
struct V_1 * V_38 ;
unsigned int V_93 , V_94 ;
V_38 = F_1 ( V_84 -> V_38 . V_87 . V_6 ) ;
if ( ! V_38 ) {
F_2 ( 1 , L_22 ,
V_84 -> V_38 . V_87 . V_6 ) ;
return - V_58 ;
}
V_93 = F_27 () ;
V_94 = F_28 () ;
V_84 -> V_38 . V_87 . V_11 = V_95 ;
if ( V_84 -> V_38 . V_87 . V_37 < 32 )
V_84 -> V_38 . V_87 . V_37 = 32 ;
if ( V_84 -> V_38 . V_87 . V_37 > V_94 )
V_84 -> V_38 . V_87 . V_37 = V_94 ;
if ( V_84 -> V_38 . V_87 . V_36 < 48 )
V_84 -> V_38 . V_87 . V_36 = 48 ;
if ( V_84 -> V_38 . V_87 . V_36 > V_93 )
V_84 -> V_38 . V_87 . V_36 = V_93 ;
V_84 -> V_38 . V_87 . V_36 &= ~ 0x03 ;
V_84 -> V_38 . V_87 . V_89 =
( V_84 -> V_38 . V_87 . V_36 * V_38 -> V_47 ) >> 3 ;
V_84 -> V_38 . V_87 . V_90 = V_84 -> V_38 . V_87 . V_37 * V_84 -> V_38 . V_87 . V_89 ;
V_84 -> V_38 . V_87 . V_91 = V_92 ;
return 0 ;
}
static int F_37 ( struct V_69 * V_69 , void * V_70 ,
struct V_86 * V_84 )
{
struct V_44 * V_45 = V_70 ;
int V_96 ;
V_96 = F_36 ( V_69 , V_45 , V_84 ) ;
if ( V_96 < 0 )
return V_96 ;
V_45 -> V_38 = F_1 ( V_84 -> V_38 . V_87 . V_6 ) ;
V_45 -> V_36 = V_84 -> V_38 . V_87 . V_36 ;
V_45 -> V_37 = V_84 -> V_38 . V_87 . V_37 ;
V_45 -> V_90 = V_84 -> V_38 . V_87 . V_90 ;
V_45 -> V_88 . V_11 = V_84 -> V_38 . V_87 . V_11 ;
V_45 -> type = V_84 -> type ;
return 0 ;
}
static int F_38 ( struct V_69 * V_69 , void * V_70 ,
struct V_86 * V_84 )
{
struct V_44 * V_45 = V_70 ;
V_84 -> V_38 . V_97 = V_45 -> V_97 ;
return 0 ;
}
static int F_39 ( struct V_7 * V_8 , struct V_98 * V_97 )
{
enum V_62 V_11 ;
int V_93 , V_94 ;
if ( V_8 -> V_99 . V_100 == NULL )
return - V_58 ;
if ( V_8 -> V_101 == NULL )
return - V_58 ;
if ( V_97 -> V_102 . V_36 < 48 || V_97 -> V_102 . V_37 < 32 )
return - V_58 ;
V_11 = V_97 -> V_11 ;
V_93 = V_8 -> V_103 . V_36 ;
V_94 = V_8 -> V_103 . V_37 ;
if ( V_11 == V_104 ) {
V_11 = ( V_97 -> V_102 . V_37 > V_94 / 2 )
? V_95
: V_105 ;
}
switch ( V_11 ) {
case V_105 :
case V_106 :
V_94 = V_94 / 2 ;
break;
case V_95 :
break;
default:
return - V_58 ;
}
V_97 -> V_11 = V_11 ;
if ( V_97 -> V_102 . V_36 > V_93 )
V_97 -> V_102 . V_36 = V_93 ;
if ( V_97 -> V_102 . V_37 > V_94 )
V_97 -> V_102 . V_37 = V_94 ;
return 0 ;
}
inline void F_40 ( struct V_9 * V_9 )
{
struct V_9 * V_10 = V_9 ;
F_4 ( & V_10 -> V_55 , V_54 . V_55 ) ;
F_4 ( & V_10 -> V_57 , V_54 . V_57 ) ;
F_4 ( & V_10 -> V_59 , V_54 . V_59 ) ;
}
static int F_41 ( struct V_7 * V_8 , struct V_44 * V_45 )
{
int V_53 ;
F_2 ( 1 , L_23 , V_23 ,
V_45 -> V_97 . V_102 . V_36 , V_45 -> V_97 . V_102 . V_37 ) ;
V_54 . V_12 = 0 ;
V_54 . V_59 = ( V_45 -> V_97 . V_102 . V_37 / 2 ) << 16 |
V_45 -> V_97 . V_102 . V_36 ;
V_53 = V_8 -> V_101 -> V_47 / 8 ;
switch ( V_53 ) {
case 2 :
V_54 . V_12 &= ~ V_56 ;
V_54 . V_57 = V_45 -> V_97 . V_102 . V_36 * 2 ;
break;
case 4 :
V_54 . V_12 |= V_56 ;
V_54 . V_57 = V_45 -> V_97 . V_102 . V_36 * 4 ;
break;
default:
F_2 ( 0 , L_24 ,
V_53 * 8 ) ;
return - V_58 ;
}
V_8 -> V_107 = V_45 -> V_97 . V_11 ;
if ( ! F_24 ( V_8 -> V_107 ) )
V_54 . V_57 = 0 ;
V_54 . V_12 |= V_16 | V_60 | V_14 ;
V_54 . V_55 = ( T_1 ) V_8 -> V_99 . V_100 ;
return 0 ;
}
static int F_42 ( struct V_69 * V_69 , void * V_70 ,
struct V_86 * V_84 )
{
struct V_44 * V_45 = V_70 ;
struct V_7 * V_8 = (struct V_7 * ) V_45 -> V_8 ;
unsigned long V_108 ;
int V_109 ;
V_109 = F_39 ( V_8 , & V_84 -> V_38 . V_97 ) ;
if ( V_109 )
return V_109 ;
V_45 -> V_97 = V_84 -> V_38 . V_97 ;
F_43 ( & V_8 -> V_110 , V_108 ) ;
F_41 ( V_8 , V_45 ) ;
F_44 ( & V_8 -> V_110 , V_108 ) ;
return 0 ;
}
static int F_45 ( struct V_69 * V_69 , void * V_70 ,
struct V_86 * V_84 )
{
return 0 ;
}
static int F_46 ( struct V_69 * V_69 , void * V_70 , unsigned int V_111 )
{
struct V_44 * V_45 = V_70 ;
struct V_7 * V_8 = (struct V_7 * ) V_45 -> V_8 ;
unsigned long V_108 ;
if ( V_111 ) {
F_43 ( & V_8 -> V_110 , V_108 ) ;
F_40 ( V_8 -> V_10 ) ;
V_8 -> V_112 = 1 ;
F_3 ( V_8 ) ;
F_44 ( & V_8 -> V_110 , V_108 ) ;
} else {
F_5 ( V_8 ) ;
V_8 -> V_112 = 0 ;
}
return 0 ;
}
int F_47 ( struct V_69 * V_69 , void * V_70 , struct V_113 * V_114 )
{
struct V_44 * V_45 = V_70 ;
struct V_7 * V_8 = V_45 -> V_8 ;
struct V_113 * V_115 = V_114 ;
* V_115 = V_8 -> V_99 ;
V_115 -> V_116 = V_117 ;
return 0 ;
}
int F_48 ( struct V_69 * V_69 , void * V_70 , const struct V_113 * V_114 )
{
struct V_44 * V_45 = V_70 ;
struct V_7 * V_8 = V_45 -> V_8 ;
const struct V_113 * V_115 = V_114 ;
struct V_1 * V_38 ;
if ( ! F_49 ( V_118 ) && ! F_49 ( V_119 ) )
return - V_120 ;
V_38 = F_1 ( V_115 -> V_38 . V_6 ) ;
if ( V_38 == NULL )
return - V_58 ;
V_8 -> V_99 = * V_115 ;
V_8 -> V_101 = V_38 ;
if ( V_8 -> V_99 . V_38 . V_89 == 0 ) {
V_8 -> V_99 . V_38 . V_89 =
V_8 -> V_99 . V_38 . V_36 * V_38 -> V_47 / 8 ;
}
return 0 ;
}
static int F_50 ( struct V_69 * V_69 , void * V_70 ,
struct V_121 * V_122 )
{
struct V_44 * V_45 = V_70 ;
return F_51 ( & V_45 -> V_88 , V_122 ) ;
}
static int F_52 ( struct V_69 * V_69 , void * V_70 ,
struct V_123 * V_122 )
{
struct V_44 * V_45 = V_70 ;
return F_53 ( & V_45 -> V_88 , V_122 ) ;
}
static int F_54 ( struct V_69 * V_69 , void * V_70 , struct V_123 * V_122 )
{
struct V_44 * V_45 = V_70 ;
return F_55 ( & V_45 -> V_88 , V_122 ) ;
}
static int F_56 ( struct V_69 * V_69 , void * V_70 , struct V_123 * V_122 )
{
struct V_44 * V_45 = V_70 ;
return F_57 ( & V_45 -> V_88 , V_122 ,
V_69 -> V_124 & V_125 ) ;
}
static int F_58 ( struct V_69 * V_69 , void * V_70 , enum V_126 V_3 )
{
struct V_44 * V_45 = V_70 ;
struct V_7 * V_8 = V_45 -> V_8 ;
if ( V_45 -> type != V_127 )
return - V_58 ;
if ( V_45 -> type != V_3 )
return - V_58 ;
if ( V_8 -> V_112 )
V_8 -> V_112 = 0 ;
F_3 ( V_45 -> V_8 ) ;
return F_59 ( & V_45 -> V_88 ) ;
}
static int F_60 ( struct V_69 * V_69 , void * V_70 , enum V_126 V_3 )
{
struct V_44 * V_45 = V_70 ;
if ( V_45 -> type != V_127 )
return - V_58 ;
if ( V_45 -> type != V_3 )
return - V_58 ;
F_5 ( V_45 -> V_8 ) ;
return F_61 ( & V_45 -> V_88 ) ;
}
static int F_62 ( struct V_69 * V_69 , void * V_70 , T_2 * V_128 )
{
struct V_44 * V_45 = V_70 ;
F_63 ( V_45 -> V_8 , V_129 , V_130 , V_128 ) ;
return 0 ;
}
static int F_64 ( struct V_69 * V_69 , void * V_70 , T_2 V_131 )
{
struct V_44 * V_45 = V_70 ;
V_45 -> V_8 -> V_132 = V_131 ;
F_63 ( V_45 -> V_8 , V_129 , V_133 , V_131 ) ;
return 0 ;
}
static int F_65 ( struct V_69 * V_69 , void * V_70 , T_2 * V_128 )
{
struct V_44 * V_45 = V_70 ;
* V_128 = V_45 -> V_8 -> V_132 ;
return 0 ;
}
static int F_66 ( struct V_69 * V_69 , void * V_70 ,
struct V_134 * V_135 )
{
struct V_44 * V_45 = V_70 ;
if ( V_135 -> V_85 != 0 )
return - V_58 ;
V_135 -> type = V_136 ;
V_135 -> V_132 = V_45 -> V_8 -> V_137 -> V_138 ;
strcpy ( V_135 -> V_139 , L_25 ) ;
return 0 ;
}
static int F_67 ( struct V_69 * V_69 , void * V_70 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_68 ( struct V_69 * V_69 , void * V_70 , unsigned int V_3 )
{
struct V_44 * V_45 = V_70 ;
if ( V_3 )
return - V_58 ;
F_63 ( V_45 -> V_8 , V_129 , V_140 , V_3 , 0 , 0 ) ;
return 0 ;
}
inline void F_69 ( struct V_7 * V_8 ,
struct V_18 * V_141 )
{
struct V_18 * V_19 = V_141 ;
struct V_20 * V_21 ;
if ( ! F_8 ( & V_19 -> V_24 ) ) {
V_21 = F_9 ( V_19 -> V_24 . V_25 , struct V_20 ,
V_26 . V_27 ) ;
F_2 ( 1 , L_26 , V_21 ) ;
F_22 ( V_8 , V_21 ) ;
} else if ( ! F_8 ( & V_19 -> V_34 ) ) {
V_21 = F_9 ( V_19 -> V_34 . V_25 , struct V_20 ,
V_26 . V_27 ) ;
F_11 ( & V_21 -> V_26 . V_27 ) ;
F_2 ( 1 , L_26 , V_21 ) ;
F_31 ( & V_21 -> V_26 . V_27 , & V_19 -> V_24 ) ;
V_21 -> V_26 . V_28 = V_35 ;
F_22 ( V_8 , V_21 ) ;
}
}
inline void F_70 ( struct V_9 * V_9 )
{
struct V_9 * V_10 = V_9 ;
F_4 ( & V_10 -> V_142 , 0x9512A254 ) ;
F_4 ( & V_10 -> V_143 , 0x03310000 ) ;
F_4 ( & V_10 -> V_144 , 0x06600F38 ) ;
F_4 ( & V_10 -> V_145 , 0x00000409 ) ;
F_4 ( & V_10 -> V_146 , 0x000000ff ) ;
F_4 ( & V_10 -> V_147 , 0x00000090 ) ;
F_2 ( 1 , L_27 ,
F_6 ( & V_10 -> V_12 ) , F_6 ( & V_10 -> V_55 ) ) ;
}
static void F_71 ( struct V_7 * V_8 , T_1 V_148 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
if ( V_148 & V_17 )
V_8 -> V_149 = 1 ;
if ( V_148 & V_150 ) {
if ( V_8 -> V_149 ) {
T_1 V_151 = V_54 . V_55 ;
V_8 -> V_149 = 0 ;
if ( V_148 & V_152 )
V_151 += V_54 . V_57 ;
F_4 ( & V_10 -> V_55 , V_151 ) ;
F_4 ( & V_10 -> V_57 , V_54 . V_57 ) ;
F_4 ( & V_10 -> V_12 ,
( V_148 & 0xffc0ffff ) |
( V_148 & V_153 ) |
V_54 . V_12 ) ;
} else if ( V_148 & V_154 ) {
F_4 ( & V_10 -> V_12 ,
( V_148 & 0xffc0ffff ) |
( V_148 & V_153 ) |
V_54 . V_12 ) ;
}
}
}
static void F_72 ( struct V_7 * V_8 , T_1 V_148 )
{
struct V_18 * V_19 = & V_8 -> V_19 ;
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_20 * V_21 ;
int V_155 ;
int V_156 ;
int V_149 = 0 ;
V_155 = V_148 & V_152 ;
V_156 = F_24 ( V_8 -> V_61 ) ;
if ( V_148 & V_17 ) {
V_149 = 1 ;
if ( ( ( V_155 == 0 ) && ( V_8 -> V_11 == 0 ) ) ||
( V_155 && ( V_8 -> V_11 == 1 ) ) )
V_8 -> V_11 ++ ;
}
if ( V_148 & V_150 ) {
F_2 ( 1 , L_28 ,
! ! V_155 , V_149 ) ;
if ( F_73 ( V_8 -> V_157 ) ) {
if ( V_155 == 0 ) {
V_8 -> V_157 = 0 ;
F_2 ( 1 , L_29 ) ;
F_69 ( V_8 , V_19 ) ;
} else
F_2 ( 1 , L_30 ) ;
return;
}
if ( ! F_8 ( & V_19 -> V_24 ) ) {
T_1 V_151 = V_54 . V_55 ;
if ( V_155 && V_156 ) {
V_151 += V_54 . V_57 ;
F_2 ( 1 , L_31 ,
( unsigned long ) V_151 , V_8 -> V_11 ) ;
}
F_4 ( & V_10 -> V_55 , V_151 ) ;
F_4 ( & V_10 -> V_57 , V_54 . V_57 ) ;
F_4 ( & V_10 -> V_12 ,
( V_148 & 0xffc0ffff ) |
( V_148 & V_153 ) |
V_54 . V_12 ) ;
return;
}
}
if ( V_149 && V_155 && ( V_8 -> V_11 == 2 ) ) {
V_8 -> V_11 = 0 ;
V_21 = F_9 ( V_19 -> V_24 . V_25 ,
struct V_20 , V_26 . V_27 ) ;
F_2 ( 1 , L_32 ,
V_21 , V_21 -> V_26 . V_3 ,
( unsigned long ) F_23 ( & V_21 -> V_26 ) ,
( unsigned long ) F_6 ( & V_10 -> V_55 ) ) ;
if ( F_74 ( & V_21 -> V_26 . V_30 ) ) {
F_11 ( & V_21 -> V_26 . V_27 ) ;
F_75 ( & V_21 -> V_26 . V_158 ) ;
V_21 -> V_26 . V_28 = V_159 ;
V_21 -> V_26 . V_160 ++ ;
F_12 ( & V_21 -> V_26 . V_30 ) ;
}
F_69 ( V_8 , V_19 ) ;
}
}
static T_3 F_76 ( int V_161 , void * V_162 )
{
struct V_7 * V_8 = (struct V_7 * ) V_162 ;
struct V_9 * V_10 = V_8 -> V_10 ;
T_1 V_148 ;
T_1 error ;
V_148 = F_6 ( & V_10 -> V_12 ) ;
if ( V_148 & V_163 ) {
V_8 -> V_164 . V_165 ++ ;
error = V_148 & V_166 ;
if ( error )
F_2 ( 1 , L_33 ,
error >> 4 , V_8 -> V_164 . V_165 ) ;
F_4 ( & V_10 -> V_12 ,
( V_148 & 0xffc0ffff ) | V_163 ) ;
}
if ( V_148 & V_17 ) {
V_8 -> V_164 . V_167 ++ ;
V_8 -> V_149 = 1 ;
F_2 ( 2 , L_34 ,
V_8 -> V_164 . V_167 ) ;
}
if ( V_148 & V_168 )
V_8 -> V_164 . V_169 ++ ;
if ( V_148 & V_150 ) {
V_8 -> V_164 . V_170 ++ ;
F_2 ( 2 , L_35 ,
V_8 -> V_164 . V_170 ) ;
}
if ( V_148 & V_171 )
V_8 -> V_164 . V_172 ++ ;
if ( V_148 & V_154 ) {
V_8 -> V_164 . V_173 ++ ;
F_2 ( 2 , L_36 ,
V_8 -> V_164 . V_173 ) ;
}
V_148 = F_6 ( & V_10 -> V_12 ) ;
F_4 ( & V_10 -> V_12 ,
( V_148 & 0xffc0ffff ) | ( V_148 & V_153 ) ) ;
if ( V_8 -> V_112 ) {
F_71 ( V_8 , V_148 ) ;
return V_174 ;
}
F_72 ( V_8 , V_148 ) ;
return V_174 ;
}
static int F_77 ( struct V_69 * V_69 )
{
struct V_175 * V_137 = F_78 ( V_69 ) ;
struct V_7 * V_8 = F_79 ( V_137 ) ;
struct V_44 * V_45 ;
struct V_9 * V_10 ;
int V_176 = V_137 -> V_176 ;
T_1 V_12 ;
F_2 ( 1 , L_37 , V_176 ) ;
V_8 -> V_177 ++ ;
if ( V_8 -> V_177 > 1 ) {
V_8 -> V_177 -- ;
return - V_178 ;
}
V_10 = V_8 -> V_10 ;
F_2 ( 1 , L_38 , V_176 ,
V_179 [ V_127 ] , V_8 -> V_177 ) ;
if ( F_80 ( & V_8 -> V_180 ) ) {
V_8 -> V_177 -- ;
return - V_181 ;
}
V_45 = F_81 ( sizeof( * V_45 ) , V_182 ) ;
if ( ! V_45 ) {
V_8 -> V_177 -- ;
F_82 ( & V_8 -> V_180 ) ;
return - V_183 ;
}
F_83 ( & V_45 -> V_45 , V_137 ) ;
V_69 -> V_184 = V_45 ;
V_45 -> V_8 = V_8 ;
V_45 -> type = V_127 ;
V_45 -> V_38 = F_1 ( V_185 ) ;
V_45 -> V_36 = F_27 () ;
V_45 -> V_37 = F_28 () ;
V_8 -> V_103 . V_36 = V_45 -> V_36 ;
V_8 -> V_103 . V_37 = V_45 -> V_37 ;
F_2 ( 1 , L_39 ,
( unsigned long ) V_45 , ( unsigned long ) V_8 ,
( unsigned long ) & V_8 -> V_19 ) ;
F_2 ( 1 , L_40 ,
F_8 ( & V_8 -> V_19 . V_34 ) ) ;
F_2 ( 1 , L_41 ,
F_8 ( & V_8 -> V_19 . V_24 ) ) ;
F_70 ( V_10 ) ;
V_12 = F_6 ( & V_10 -> V_12 ) ;
F_4 ( & V_10 -> V_12 ,
V_12 & ~ ( V_186 | V_187 |
V_14 | V_188 |
V_60 | V_189 | V_190 ) ) ;
V_12 = F_6 ( & V_10 -> V_12 ) ;
F_4 ( & V_10 -> V_12 , V_12 | V_153 ) ;
F_84 ( & V_45 -> V_191 ) ;
F_85 ( & V_45 -> V_88 , & V_192 ,
V_8 -> V_8 , & V_45 -> V_191 ,
V_45 -> type , V_95 ,
sizeof( struct V_20 ) , V_45 ,
& V_45 -> V_8 -> V_180 ) ;
F_86 ( & V_45 -> V_45 ) ;
F_82 ( & V_8 -> V_180 ) ;
return 0 ;
}
static T_4 F_87 ( struct V_69 * V_69 , char T_5 * V_39 , T_6 V_42 ,
T_7 * V_193 )
{
struct V_44 * V_45 = V_69 -> V_184 ;
struct V_7 * V_8 = V_45 -> V_8 ;
int V_96 = 0 ;
F_2 ( 2 , L_42 , V_23 ) ;
if ( V_8 -> V_112 )
V_8 -> V_112 = 0 ;
if ( V_45 -> type == V_127 ) {
if ( F_80 ( & V_8 -> V_180 ) )
return - V_181 ;
F_3 ( V_8 ) ;
V_96 = F_88 ( & V_45 -> V_88 , V_39 , V_42 ,
V_193 , 0 , V_69 -> V_124 & V_125 ) ;
F_82 ( & V_8 -> V_180 ) ;
return V_96 ;
}
return 0 ;
}
static unsigned int F_89 ( struct V_69 * V_69 , struct V_194 * V_195 )
{
struct V_44 * V_45 = V_69 -> V_184 ;
struct V_40 * V_196 = & V_45 -> V_88 ;
struct V_7 * V_8 = V_45 -> V_8 ;
unsigned long V_197 = F_90 ( V_195 ) ;
unsigned int V_198 = F_91 ( V_69 , V_195 ) ;
if ( V_127 != V_45 -> type )
return V_199 ;
if ( ! ( V_197 & ( V_200 | V_201 ) ) )
return V_198 ;
F_92 ( & V_8 -> V_180 ) ;
V_198 |= F_93 ( V_69 , V_196 , V_195 ) ;
F_82 ( & V_8 -> V_180 ) ;
return V_198 ;
}
static int F_94 ( struct V_69 * V_69 )
{
struct V_44 * V_45 = V_69 -> V_184 ;
struct V_7 * V_8 = V_45 -> V_8 ;
int V_176 = F_78 ( V_69 ) -> V_176 ;
F_92 ( & V_8 -> V_180 ) ;
F_5 ( V_8 ) ;
F_95 ( & V_45 -> V_88 ) ;
F_96 ( & V_45 -> V_88 ) ;
F_97 ( & V_45 -> V_45 ) ;
F_98 ( & V_45 -> V_45 ) ;
F_82 ( & V_8 -> V_180 ) ;
F_99 ( V_45 ) ;
V_8 -> V_177 -- ;
F_2 ( 1 , L_43 ,
V_176 , V_8 -> V_177 ) ;
return 0 ;
}
void F_100 ( struct V_9 * V_202 )
{
F_4 ( & V_202 -> V_12 , 0 ) ;
F_4 ( & V_202 -> V_142 , 0x9512a254 ) ;
F_4 ( & V_202 -> V_143 , 0x03310000 ) ;
F_4 ( & V_202 -> V_144 , 0x06600f38 ) ;
F_4 ( & V_202 -> V_145 , 0x00000409 ) ;
F_4 ( & V_202 -> V_55 , 0 ) ;
F_4 ( & V_202 -> V_57 , 0 ) ;
F_4 ( & V_202 -> V_59 , 0x01e002d0 ) ;
F_4 ( & V_202 -> V_147 , 0x00000090 ) ;
F_4 ( & V_202 -> V_146 , 0x000000ff ) ;
}
static int F_101 ( struct V_69 * V_69 , struct V_203 * V_204 )
{
struct V_44 * V_45 = V_69 -> V_184 ;
struct V_7 * V_8 = V_45 -> V_8 ;
int V_96 ;
F_2 ( 1 , L_44 , ( unsigned long ) V_204 ) ;
if ( F_80 ( & V_8 -> V_180 ) )
return - V_181 ;
V_96 = F_102 ( & V_45 -> V_88 , V_204 ) ;
F_82 ( & V_8 -> V_180 ) ;
F_2 ( 1 , L_45 ,
( unsigned long ) V_204 -> V_205 ,
( unsigned long ) V_204 -> V_206 - ( unsigned long ) V_204 -> V_205 ,
V_96 ) ;
return V_96 ;
}
static int F_103 ( struct V_207 * V_208 )
{
struct V_7 * V_7 ;
struct V_175 * V_137 ;
struct V_209 V_210 ;
struct V_9 T_8 * V_211 ;
struct V_212 * V_213 ;
int V_96 , V_214 ;
struct V_215 * V_215 ;
V_96 = F_104 ( V_208 -> V_8 . V_216 , 0 , & V_210 ) ;
if ( V_96 ) {
F_105 ( & V_208 -> V_8 , L_46 ) ;
return - V_217 ;
}
V_214 = F_106 ( V_208 -> V_8 . V_216 , 0 ) ;
if ( V_214 == V_218 ) {
F_105 ( & V_208 -> V_8 , L_47 ) ;
return - V_58 ;
}
if ( ! F_107 ( & V_208 -> V_8 , V_210 . V_219 ,
sizeof( struct V_9 ) , V_220 ) ) {
F_105 ( & V_208 -> V_8 , L_48 ) ;
V_96 = - V_178 ;
goto V_109;
}
V_211 = F_108 ( & V_208 -> V_8 , V_210 . V_219 , sizeof( struct V_9 ) ) ;
if ( ! V_211 ) {
F_105 ( & V_208 -> V_8 , L_49 ) ;
V_96 = - V_183 ;
goto V_109;
}
V_7 = F_109 ( & V_208 -> V_8 , sizeof( struct V_7 ) , V_221 ) ;
if ( ! V_7 ) {
F_105 ( & V_208 -> V_8 , L_50 ) ;
V_96 = - V_183 ;
goto V_109;
}
V_7 -> V_10 = V_211 ;
V_7 -> V_161 = V_214 ;
V_7 -> V_8 = & V_208 -> V_8 ;
F_110 ( & V_7 -> V_19 . V_24 ) ;
F_110 ( & V_7 -> V_19 . V_34 ) ;
snprintf ( V_7 -> V_222 . V_139 ,
sizeof( V_7 -> V_222 . V_139 ) , L_51 , L_52 ) ;
V_96 = F_111 ( V_7 -> V_8 , & V_7 -> V_222 ) ;
if ( V_96 < 0 ) {
F_105 ( & V_208 -> V_8 , L_53 , V_96 ) ;
goto V_109;
}
V_213 = F_112 ( 0 ) ;
F_113 ( & V_7 -> V_223 , 5 ) ;
if ( V_7 -> V_223 . error ) {
V_96 = V_7 -> V_223 . error ;
F_105 ( & V_208 -> V_8 , L_54 ) ;
goto V_224;
}
V_7 -> V_222 . V_225 = & V_7 -> V_223 ;
V_7 -> V_226 = F_114 ( & V_7 -> V_222 , V_213 ,
L_55 , V_227 , NULL ) ;
F_115 ( & V_7 -> V_19 . V_31 , F_15 ,
( unsigned long ) V_7 ) ;
V_7 -> V_132 = V_228 ;
V_7 -> V_157 = 1 ;
V_137 = F_116 () ;
if ( V_137 == NULL ) {
V_96 = - V_183 ;
goto V_224;
}
* V_137 = V_229 ;
V_137 -> V_222 = & V_7 -> V_222 ;
V_7 -> V_137 = V_137 ;
F_117 ( & V_7 -> V_180 ) ;
V_7 -> V_137 -> V_180 = & V_7 -> V_180 ;
F_84 ( & V_7 -> V_110 ) ;
F_118 ( V_7 -> V_137 , V_7 ) ;
F_92 ( & V_7 -> V_180 ) ;
V_96 = F_119 ( V_7 -> V_137 , V_230 , - 1 ) ;
if ( V_96 < 0 ) {
F_120 ( V_7 -> V_137 ) ;
goto V_224;
}
V_215 = F_121 ( & V_208 -> V_8 , L_56 ) ;
if ( F_122 ( V_215 ) ) {
F_105 ( & V_208 -> V_8 , L_57 ) ;
V_96 = F_123 ( V_215 ) ;
goto V_231;
}
V_96 = F_124 ( V_215 ) ;
if ( V_96 ) {
F_105 ( & V_208 -> V_8 , L_58 ) ;
goto V_231;
}
V_7 -> V_215 = V_215 ;
F_100 ( V_7 -> V_10 ) ;
if ( F_125 ( V_7 -> V_161 , F_76 , 0 , L_20 , ( void * ) V_7 ) ) {
F_105 ( & V_208 -> V_8 , L_59 ) ;
V_96 = - V_217 ;
goto V_232;
}
F_82 ( & V_7 -> V_180 ) ;
F_126 ( & V_208 -> V_8 , L_60 ) ;
return V_96 ;
V_232:
F_127 ( V_7 -> V_215 ) ;
V_231:
F_128 ( V_7 -> V_137 ) ;
V_224:
F_129 ( & V_7 -> V_223 ) ;
F_82 ( & V_7 -> V_180 ) ;
F_130 ( V_213 ) ;
F_131 ( & V_7 -> V_222 ) ;
V_109:
F_132 ( V_214 ) ;
return V_96 ;
}
static int F_133 ( struct V_207 * V_208 )
{
struct V_233 * V_222 = F_134 ( & V_208 -> V_8 ) ;
struct V_7 * V_8 = F_26 ( V_222 , struct V_7 , V_222 ) ;
struct V_234 * V_235 = F_9 ( V_222 -> V_236 . V_25 ,
struct V_234 , V_237 ) ;
struct V_238 * V_239 = F_135 ( V_235 ) ;
F_136 ( V_8 -> V_161 , ( void * ) V_8 ) ;
F_132 ( V_8 -> V_161 ) ;
F_127 ( V_8 -> V_215 ) ;
F_129 ( & V_8 -> V_223 ) ;
F_128 ( V_8 -> V_137 ) ;
F_130 ( V_239 -> V_240 ) ;
F_131 ( & V_8 -> V_222 ) ;
return 0 ;
}
static int F_137 ( struct V_207 * V_208 , T_9 V_28 )
{
struct V_233 * V_222 = F_134 ( & V_208 -> V_8 ) ;
struct V_7 * V_8 = F_26 ( V_222 , struct V_7 , V_222 ) ;
F_138 ( V_8 -> V_215 ) ;
return 0 ;
}
static int F_139 ( struct V_207 * V_208 )
{
struct V_233 * V_222 = F_134 ( & V_208 -> V_8 ) ;
struct V_7 * V_8 = F_26 ( V_222 , struct V_7 , V_222 ) ;
F_140 ( V_8 -> V_215 ) ;
return 0 ;
}
