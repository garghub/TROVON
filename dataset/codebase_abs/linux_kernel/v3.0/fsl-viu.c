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
F_11 ( & V_21 -> V_26 . V_27 ) ;
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
F_11 ( & V_21 -> V_26 . V_27 ) ;
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
F_14 ( & V_21 -> V_26 . V_27 , & V_19 -> V_34 ) ;
V_21 -> V_26 . V_28 = V_68 ;
F_2 ( 2 , L_14 ,
V_21 , V_21 -> V_26 . V_3 ) ;
} else if ( F_8 ( & V_19 -> V_24 ) ) {
F_2 ( 1 , L_15 ,
( unsigned long ) & V_21 -> V_26 . V_27 ) ;
F_14 ( & V_21 -> V_26 . V_27 , & V_19 -> V_24 ) ;
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
F_14 ( & V_21 -> V_26 . V_27 , & V_19 -> V_24 ) ;
V_21 -> V_26 . V_28 = V_35 ;
F_2 ( 2 , L_18 ,
V_21 , V_21 -> V_26 . V_3 ) ;
} else {
F_14 ( & V_21 -> V_26 . V_27 , & V_19 -> V_34 ) ;
V_21 -> V_26 . V_28 = V_68 ;
F_2 ( 2 , L_19 ,
V_21 , V_21 -> V_26 . V_3 ) ;
}
}
}
static void F_31 ( struct V_40 * V_41 ,
struct V_49 * V_26 )
{
struct V_20 * V_21 = F_26 ( V_26 , struct V_20 , V_26 ) ;
struct V_44 * V_45 = V_41 -> V_46 ;
struct V_7 * V_8 = (struct V_7 * ) V_45 -> V_8 ;
F_5 ( V_8 ) ;
F_17 ( V_41 , V_21 ) ;
}
static int F_32 ( struct V_69 * V_69 , void * V_70 ,
struct V_71 * V_72 )
{
strcpy ( V_72 -> V_73 , L_20 ) ;
strcpy ( V_72 -> V_74 , L_20 ) ;
V_72 -> V_75 = V_76 ;
V_72 -> V_77 = V_78 |
V_79 |
V_80 |
V_81 ;
return 0 ;
}
static int F_33 ( struct V_69 * V_69 , void * V_70 ,
struct V_82 * V_83 )
{
int V_84 = V_83 -> V_84 ;
if ( V_83 -> V_84 > V_4 )
return - V_58 ;
F_34 ( V_83 -> V_85 , V_5 [ V_84 ] . V_86 , sizeof( V_83 -> V_85 ) ) ;
V_83 -> V_6 = V_5 [ V_84 ] . V_2 ;
return 0 ;
}
static int F_35 ( struct V_69 * V_69 , void * V_70 ,
struct V_87 * V_83 )
{
struct V_44 * V_45 = V_70 ;
V_83 -> V_38 . V_88 . V_36 = V_45 -> V_36 ;
V_83 -> V_38 . V_88 . V_37 = V_45 -> V_37 ;
V_83 -> V_38 . V_88 . V_11 = V_45 -> V_89 . V_11 ;
V_83 -> V_38 . V_88 . V_6 = V_45 -> V_38 -> V_6 ;
V_83 -> V_38 . V_88 . V_90 =
( V_83 -> V_38 . V_88 . V_36 * V_45 -> V_38 -> V_47 ) >> 3 ;
V_83 -> V_38 . V_88 . V_91 = V_45 -> V_91 ;
return 0 ;
}
static int F_36 ( struct V_69 * V_69 , void * V_70 ,
struct V_87 * V_83 )
{
struct V_1 * V_38 ;
enum V_62 V_11 ;
unsigned int V_92 , V_93 ;
V_38 = F_1 ( V_83 -> V_38 . V_88 . V_6 ) ;
if ( ! V_38 ) {
F_2 ( 1 , L_21 ,
V_83 -> V_38 . V_88 . V_6 ) ;
return - V_58 ;
}
V_11 = V_83 -> V_38 . V_88 . V_11 ;
if ( V_11 == V_94 ) {
V_11 = V_95 ;
} else if ( V_11 != V_95 ) {
F_2 ( 1 , L_22 ) ;
return - V_58 ;
}
V_92 = F_27 () ;
V_93 = F_28 () ;
V_83 -> V_38 . V_88 . V_11 = V_11 ;
if ( V_83 -> V_38 . V_88 . V_37 < 32 )
V_83 -> V_38 . V_88 . V_37 = 32 ;
if ( V_83 -> V_38 . V_88 . V_37 > V_93 )
V_83 -> V_38 . V_88 . V_37 = V_93 ;
if ( V_83 -> V_38 . V_88 . V_36 < 48 )
V_83 -> V_38 . V_88 . V_36 = 48 ;
if ( V_83 -> V_38 . V_88 . V_36 > V_92 )
V_83 -> V_38 . V_88 . V_36 = V_92 ;
V_83 -> V_38 . V_88 . V_36 &= ~ 0x03 ;
V_83 -> V_38 . V_88 . V_90 =
( V_83 -> V_38 . V_88 . V_36 * V_38 -> V_47 ) >> 3 ;
return 0 ;
}
static int F_37 ( struct V_69 * V_69 , void * V_70 ,
struct V_87 * V_83 )
{
struct V_44 * V_45 = V_70 ;
int V_96 ;
V_96 = F_36 ( V_69 , V_45 , V_83 ) ;
if ( V_96 < 0 )
return V_96 ;
V_45 -> V_38 = F_1 ( V_83 -> V_38 . V_88 . V_6 ) ;
V_45 -> V_36 = V_83 -> V_38 . V_88 . V_36 ;
V_45 -> V_37 = V_83 -> V_38 . V_88 . V_37 ;
V_45 -> V_91 = V_83 -> V_38 . V_88 . V_91 ;
V_45 -> V_89 . V_11 = V_83 -> V_38 . V_88 . V_11 ;
V_45 -> type = V_83 -> type ;
F_2 ( 1 , L_23 , ( char * ) & V_45 -> V_38 -> V_86 ) ;
return 0 ;
}
static int F_38 ( struct V_69 * V_69 , void * V_70 ,
struct V_87 * V_83 )
{
struct V_44 * V_45 = V_70 ;
V_83 -> V_38 . V_97 = V_45 -> V_97 ;
return 0 ;
}
static int F_39 ( struct V_7 * V_8 , struct V_98 * V_97 )
{
enum V_62 V_11 ;
int V_92 , V_93 ;
if ( V_8 -> V_99 . V_100 == NULL )
return - V_58 ;
if ( V_8 -> V_101 == NULL )
return - V_58 ;
if ( V_97 -> V_102 . V_36 < 48 || V_97 -> V_102 . V_37 < 32 )
return - V_58 ;
V_11 = V_97 -> V_11 ;
V_92 = V_8 -> V_103 . V_36 ;
V_93 = V_8 -> V_103 . V_37 ;
if ( V_11 == V_94 ) {
V_11 = ( V_97 -> V_102 . V_37 > V_93 / 2 )
? V_95
: V_104 ;
}
switch ( V_11 ) {
case V_104 :
case V_105 :
V_93 = V_93 / 2 ;
break;
case V_95 :
break;
default:
return - V_58 ;
}
V_97 -> V_11 = V_11 ;
if ( V_97 -> V_102 . V_36 > V_92 )
V_97 -> V_102 . V_36 = V_92 ;
if ( V_97 -> V_102 . V_37 > V_93 )
V_97 -> V_102 . V_37 = V_93 ;
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
F_2 ( 1 , L_24 , V_23 ,
V_45 -> V_97 . V_102 . V_36 , V_45 -> V_97 . V_102 . V_37 , V_8 -> V_101 -> V_86 ) ;
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
F_2 ( 0 , L_25 ,
V_53 * 8 ) ;
return - V_58 ;
}
V_8 -> V_106 = V_45 -> V_97 . V_11 ;
if ( ! F_24 ( V_8 -> V_106 ) )
V_54 . V_57 = 0 ;
V_54 . V_12 |= V_16 | V_60 | V_14 ;
V_54 . V_55 = ( T_1 ) V_8 -> V_99 . V_100 ;
return 0 ;
}
static int F_42 ( struct V_69 * V_69 , void * V_70 ,
struct V_87 * V_83 )
{
struct V_44 * V_45 = V_70 ;
struct V_7 * V_8 = (struct V_7 * ) V_45 -> V_8 ;
unsigned long V_107 ;
int V_108 ;
V_108 = F_39 ( V_8 , & V_83 -> V_38 . V_97 ) ;
if ( V_108 )
return V_108 ;
V_45 -> V_97 = V_83 -> V_38 . V_97 ;
F_43 ( & V_8 -> V_109 , V_107 ) ;
F_41 ( V_8 , V_45 ) ;
F_44 ( & V_8 -> V_109 , V_107 ) ;
return 0 ;
}
static int F_45 ( struct V_69 * V_69 , void * V_70 ,
struct V_87 * V_83 )
{
return 0 ;
}
static int F_46 ( struct V_69 * V_69 , void * V_70 , unsigned int V_110 )
{
struct V_44 * V_45 = V_70 ;
struct V_7 * V_8 = (struct V_7 * ) V_45 -> V_8 ;
unsigned long V_107 ;
if ( V_110 ) {
F_43 ( & V_8 -> V_109 , V_107 ) ;
F_40 ( V_8 -> V_10 ) ;
V_8 -> V_111 = 1 ;
F_3 ( V_8 ) ;
F_44 ( & V_8 -> V_109 , V_107 ) ;
} else {
F_5 ( V_8 ) ;
V_8 -> V_111 = 0 ;
}
return 0 ;
}
int F_47 ( struct V_69 * V_69 , void * V_70 , struct V_112 * V_113 )
{
struct V_44 * V_45 = V_70 ;
struct V_7 * V_8 = V_45 -> V_8 ;
struct V_112 * V_114 = V_113 ;
* V_114 = V_8 -> V_99 ;
V_114 -> V_115 = V_116 ;
return 0 ;
}
int F_48 ( struct V_69 * V_69 , void * V_70 , struct V_112 * V_113 )
{
struct V_44 * V_45 = V_70 ;
struct V_7 * V_8 = V_45 -> V_8 ;
struct V_112 * V_114 = V_113 ;
struct V_1 * V_38 ;
if ( ! F_49 ( V_117 ) && ! F_49 ( V_118 ) )
return - V_119 ;
V_38 = F_1 ( V_114 -> V_38 . V_6 ) ;
if ( V_38 == NULL )
return - V_58 ;
V_8 -> V_99 = * V_114 ;
V_8 -> V_101 = V_38 ;
if ( V_8 -> V_99 . V_38 . V_90 == 0 ) {
V_8 -> V_99 . V_38 . V_90 =
V_8 -> V_99 . V_38 . V_36 * V_38 -> V_47 / 8 ;
}
return 0 ;
}
static int F_50 ( struct V_69 * V_69 , void * V_70 ,
struct V_120 * V_121 )
{
struct V_44 * V_45 = V_70 ;
return F_51 ( & V_45 -> V_89 , V_121 ) ;
}
static int F_52 ( struct V_69 * V_69 , void * V_70 ,
struct V_122 * V_121 )
{
struct V_44 * V_45 = V_70 ;
return F_53 ( & V_45 -> V_89 , V_121 ) ;
}
static int F_54 ( struct V_69 * V_69 , void * V_70 , struct V_122 * V_121 )
{
struct V_44 * V_45 = V_70 ;
return F_55 ( & V_45 -> V_89 , V_121 ) ;
}
static int F_56 ( struct V_69 * V_69 , void * V_70 , struct V_122 * V_121 )
{
struct V_44 * V_45 = V_70 ;
return F_57 ( & V_45 -> V_89 , V_121 ,
V_69 -> V_123 & V_124 ) ;
}
static int F_58 ( struct V_69 * V_69 , void * V_70 , enum V_125 V_3 )
{
struct V_44 * V_45 = V_70 ;
struct V_7 * V_8 = V_45 -> V_8 ;
if ( V_45 -> type != V_126 )
return - V_58 ;
if ( V_45 -> type != V_3 )
return - V_58 ;
if ( V_8 -> V_111 )
V_8 -> V_111 = 0 ;
F_3 ( V_45 -> V_8 ) ;
return F_59 ( & V_45 -> V_89 ) ;
}
static int F_60 ( struct V_69 * V_69 , void * V_70 , enum V_125 V_3 )
{
struct V_44 * V_45 = V_70 ;
if ( V_45 -> type != V_126 )
return - V_58 ;
if ( V_45 -> type != V_3 )
return - V_58 ;
F_5 ( V_45 -> V_8 ) ;
return F_61 ( & V_45 -> V_89 ) ;
}
static int F_62 ( struct V_69 * V_69 , void * V_70 , T_2 * V_127 )
{
struct V_44 * V_45 = V_70 ;
F_63 ( V_45 -> V_8 , V_128 , V_129 , V_127 ) ;
return 0 ;
}
static int F_64 ( struct V_69 * V_69 , void * V_70 , T_2 * V_130 )
{
struct V_44 * V_45 = V_70 ;
V_45 -> V_8 -> V_131 = * V_130 ;
F_63 ( V_45 -> V_8 , V_132 , V_133 , * V_130 ) ;
return 0 ;
}
static int F_65 ( struct V_69 * V_69 , void * V_70 , T_2 * V_127 )
{
struct V_44 * V_45 = V_70 ;
* V_127 = V_45 -> V_8 -> V_131 ;
return 0 ;
}
static int F_66 ( struct V_69 * V_69 , void * V_70 ,
struct V_134 * V_135 )
{
struct V_44 * V_45 = V_70 ;
if ( V_135 -> V_84 != 0 )
return - V_58 ;
V_135 -> type = V_136 ;
V_135 -> V_131 = V_45 -> V_8 -> V_137 -> V_138 ;
strcpy ( V_135 -> V_86 , L_26 ) ;
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
if ( V_3 > 1 )
return - V_58 ;
F_63 ( V_45 -> V_8 , V_128 , V_139 , V_3 , 0 , 0 ) ;
return 0 ;
}
static int F_69 ( struct V_69 * V_69 , void * V_70 ,
struct V_140 * V_141 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_70 ( V_142 ) ; V_3 ++ ) {
if ( V_141 -> V_130 && V_141 -> V_130 == V_142 [ V_3 ] . V_130 ) {
memcpy ( V_141 , & ( V_142 [ V_3 ] ) , sizeof( * V_141 ) ) ;
return 0 ;
}
}
return - V_58 ;
}
static int F_71 ( struct V_69 * V_69 , void * V_70 ,
struct V_143 * V_144 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_70 ( V_142 ) ; V_3 ++ ) {
if ( V_144 -> V_130 == V_142 [ V_3 ] . V_130 ) {
V_144 -> V_145 = V_146 [ V_3 ] ;
return 0 ;
}
}
return - V_58 ;
}
static int F_72 ( struct V_69 * V_69 , void * V_70 ,
struct V_143 * V_144 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_70 ( V_142 ) ; V_3 ++ ) {
if ( V_144 -> V_130 == V_142 [ V_3 ] . V_130 ) {
if ( V_144 -> V_145 < V_142 [ V_3 ] . V_147
|| V_144 -> V_145 > V_142 [ V_3 ] . V_148 )
return - V_149 ;
V_146 [ V_3 ] = V_144 -> V_145 ;
return 0 ;
}
}
return - V_58 ;
}
inline void F_73 ( struct V_7 * V_8 ,
struct V_18 * V_150 )
{
struct V_18 * V_19 = V_150 ;
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
F_14 ( & V_21 -> V_26 . V_27 , & V_19 -> V_24 ) ;
V_21 -> V_26 . V_28 = V_35 ;
F_22 ( V_8 , V_21 ) ;
}
}
inline void F_74 ( struct V_9 * V_9 )
{
struct V_9 * V_10 = V_9 ;
F_4 ( & V_10 -> V_151 , 0x9512A254 ) ;
F_4 ( & V_10 -> V_152 , 0x03310000 ) ;
F_4 ( & V_10 -> V_153 , 0x06600F38 ) ;
F_4 ( & V_10 -> V_154 , 0x00000409 ) ;
F_4 ( & V_10 -> V_155 , 0x000000ff ) ;
F_4 ( & V_10 -> V_156 , 0x00000090 ) ;
F_2 ( 1 , L_28 ,
F_6 ( & V_10 -> V_12 ) , F_6 ( & V_10 -> V_55 ) ) ;
}
static void F_75 ( struct V_7 * V_8 , T_1 V_157 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
if ( V_157 & V_17 )
V_8 -> V_158 = 1 ;
if ( V_157 & V_159 ) {
if ( V_8 -> V_158 ) {
T_1 V_160 = V_54 . V_55 ;
V_8 -> V_158 = 0 ;
if ( V_157 & V_161 )
V_160 += V_54 . V_57 ;
F_4 ( & V_10 -> V_55 , V_160 ) ;
F_4 ( & V_10 -> V_57 , V_54 . V_57 ) ;
F_4 ( & V_10 -> V_12 ,
( V_157 & 0xffc0ffff ) |
( V_157 & V_162 ) |
V_54 . V_12 ) ;
} else if ( V_157 & V_163 ) {
F_4 ( & V_10 -> V_12 ,
( V_157 & 0xffc0ffff ) |
( V_157 & V_162 ) |
V_54 . V_12 ) ;
}
}
}
static void F_76 ( struct V_7 * V_8 , T_1 V_157 )
{
struct V_18 * V_19 = & V_8 -> V_19 ;
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_20 * V_21 ;
int V_164 ;
int V_165 ;
int V_158 = 0 ;
V_164 = V_157 & V_161 ;
V_165 = F_24 ( V_8 -> V_61 ) ;
if ( V_157 & V_17 ) {
V_158 = 1 ;
if ( ( ( V_164 == 0 ) && ( V_8 -> V_11 == 0 ) ) ||
( V_164 && ( V_8 -> V_11 == 1 ) ) )
V_8 -> V_11 ++ ;
}
if ( V_157 & V_159 ) {
F_2 ( 1 , L_29 ,
! ! V_164 , V_158 ) ;
if ( F_77 ( V_8 -> V_166 ) ) {
if ( V_164 == 0 ) {
V_8 -> V_166 = 0 ;
F_2 ( 1 , L_30 ) ;
F_73 ( V_8 , V_19 ) ;
} else
F_2 ( 1 , L_31 ) ;
return;
}
if ( ! F_8 ( & V_19 -> V_24 ) ) {
T_1 V_160 = V_54 . V_55 ;
if ( V_164 && V_165 ) {
V_160 += V_54 . V_57 ;
F_2 ( 1 , L_32 ,
( unsigned long ) V_160 , V_8 -> V_11 ) ;
}
F_4 ( & V_10 -> V_55 , V_160 ) ;
F_4 ( & V_10 -> V_57 , V_54 . V_57 ) ;
F_4 ( & V_10 -> V_12 ,
( V_157 & 0xffc0ffff ) |
( V_157 & V_162 ) |
V_54 . V_12 ) ;
return;
}
}
if ( V_158 && V_164 && ( V_8 -> V_11 == 2 ) ) {
V_8 -> V_11 = 0 ;
V_21 = F_9 ( V_19 -> V_24 . V_25 ,
struct V_20 , V_26 . V_27 ) ;
F_2 ( 1 , L_33 ,
V_21 , V_21 -> V_26 . V_3 ,
( unsigned long ) F_23 ( & V_21 -> V_26 ) ,
( unsigned long ) F_6 ( & V_10 -> V_55 ) ) ;
if ( F_78 ( & V_21 -> V_26 . V_30 ) ) {
F_11 ( & V_21 -> V_26 . V_27 ) ;
F_79 ( & V_21 -> V_26 . V_167 ) ;
V_21 -> V_26 . V_28 = V_168 ;
V_21 -> V_26 . V_169 ++ ;
F_12 ( & V_21 -> V_26 . V_30 ) ;
}
F_73 ( V_8 , V_19 ) ;
}
}
static T_3 F_80 ( int V_170 , void * V_171 )
{
struct V_7 * V_8 = (struct V_7 * ) V_171 ;
struct V_9 * V_10 = V_8 -> V_10 ;
T_1 V_157 ;
T_1 error ;
V_157 = F_6 ( & V_10 -> V_12 ) ;
if ( V_157 & V_172 ) {
V_8 -> V_173 . V_174 ++ ;
error = V_157 & V_175 ;
if ( error )
F_2 ( 1 , L_34 ,
error >> 4 , V_8 -> V_173 . V_174 ) ;
F_4 ( & V_10 -> V_12 ,
( V_157 & 0xffc0ffff ) | V_172 ) ;
}
if ( V_157 & V_17 ) {
V_8 -> V_173 . V_176 ++ ;
V_8 -> V_158 = 1 ;
F_2 ( 2 , L_35 ,
V_8 -> V_173 . V_176 ) ;
}
if ( V_157 & V_177 )
V_8 -> V_173 . V_178 ++ ;
if ( V_157 & V_159 ) {
V_8 -> V_173 . V_179 ++ ;
F_2 ( 2 , L_36 ,
V_8 -> V_173 . V_179 ) ;
}
if ( V_157 & V_180 )
V_8 -> V_173 . V_181 ++ ;
if ( V_157 & V_163 ) {
V_8 -> V_173 . V_182 ++ ;
F_2 ( 2 , L_37 ,
V_8 -> V_173 . V_182 ) ;
}
V_157 = F_6 ( & V_10 -> V_12 ) ;
F_4 ( & V_10 -> V_12 ,
( V_157 & 0xffc0ffff ) | ( V_157 & V_162 ) ) ;
if ( V_8 -> V_111 ) {
F_75 ( V_8 , V_157 ) ;
return V_183 ;
}
F_76 ( V_8 , V_157 ) ;
return V_183 ;
}
static int F_81 ( struct V_69 * V_69 )
{
struct V_184 * V_137 = F_82 ( V_69 ) ;
struct V_7 * V_8 = F_83 ( V_137 ) ;
struct V_44 * V_45 ;
struct V_9 * V_10 ;
int V_185 = V_137 -> V_185 ;
T_1 V_12 ;
int V_3 ;
F_2 ( 1 , L_38 , V_185 ) ;
V_8 -> V_186 ++ ;
if ( V_8 -> V_186 > 1 ) {
V_8 -> V_186 -- ;
return - V_187 ;
}
V_10 = V_8 -> V_10 ;
F_2 ( 1 , L_39 , V_185 ,
V_188 [ V_126 ] , V_8 -> V_186 ) ;
V_45 = F_84 ( sizeof( * V_45 ) , V_189 ) ;
if ( ! V_45 ) {
V_8 -> V_186 -- ;
return - V_190 ;
}
V_69 -> V_191 = V_45 ;
V_45 -> V_8 = V_8 ;
V_45 -> type = V_126 ;
V_45 -> V_38 = F_1 ( V_192 ) ;
V_45 -> V_36 = F_27 () ;
V_45 -> V_37 = F_28 () ;
V_8 -> V_103 . V_36 = V_45 -> V_36 ;
V_8 -> V_103 . V_37 = V_45 -> V_37 ;
for ( V_3 = 0 ; V_3 < F_70 ( V_142 ) ; V_3 ++ )
V_146 [ V_3 ] = V_142 [ V_3 ] . V_193 ;
F_2 ( 1 , L_40 ,
( unsigned long ) V_45 , ( unsigned long ) V_8 ,
( unsigned long ) & V_8 -> V_19 ) ;
F_2 ( 1 , L_41 ,
F_8 ( & V_8 -> V_19 . V_34 ) ) ;
F_2 ( 1 , L_42 ,
F_8 ( & V_8 -> V_19 . V_24 ) ) ;
F_74 ( V_10 ) ;
V_12 = F_6 ( & V_10 -> V_12 ) ;
F_4 ( & V_10 -> V_12 ,
V_12 & ~ ( V_194 | V_195 |
V_14 | V_196 |
V_60 | V_197 | V_198 ) ) ;
V_12 = F_6 ( & V_10 -> V_12 ) ;
F_4 ( & V_10 -> V_12 , V_12 | V_162 ) ;
F_85 ( & V_45 -> V_199 ) ;
F_86 ( & V_45 -> V_89 , & V_200 ,
V_8 -> V_8 , & V_45 -> V_199 ,
V_45 -> type , V_95 ,
sizeof( struct V_20 ) , V_45 ,
& V_45 -> V_8 -> V_201 ) ;
return 0 ;
}
static T_4 F_87 ( struct V_69 * V_69 , char T_5 * V_39 , T_6 V_42 ,
T_7 * V_202 )
{
struct V_44 * V_45 = V_69 -> V_191 ;
struct V_7 * V_8 = V_45 -> V_8 ;
int V_96 = 0 ;
F_2 ( 2 , L_43 , V_23 ) ;
if ( V_8 -> V_111 )
V_8 -> V_111 = 0 ;
if ( V_45 -> type == V_126 ) {
F_3 ( V_8 ) ;
V_96 = F_88 ( & V_45 -> V_89 , V_39 , V_42 ,
V_202 , 0 , V_69 -> V_123 & V_124 ) ;
return V_96 ;
}
return 0 ;
}
static unsigned int F_89 ( struct V_69 * V_69 , struct V_203 * V_204 )
{
struct V_44 * V_45 = V_69 -> V_191 ;
struct V_40 * V_205 = & V_45 -> V_89 ;
if ( V_126 != V_45 -> type )
return V_206 ;
return F_90 ( V_69 , V_205 , V_204 ) ;
}
static int F_91 ( struct V_69 * V_69 )
{
struct V_44 * V_45 = V_69 -> V_191 ;
struct V_7 * V_8 = V_45 -> V_8 ;
int V_185 = F_82 ( V_69 ) -> V_185 ;
F_5 ( V_8 ) ;
F_92 ( & V_45 -> V_89 ) ;
F_93 ( & V_45 -> V_89 ) ;
F_94 ( V_45 ) ;
V_8 -> V_186 -- ;
F_2 ( 1 , L_44 ,
V_185 , V_8 -> V_186 ) ;
return 0 ;
}
void F_95 ( struct V_9 * V_207 )
{
F_4 ( & V_207 -> V_12 , 0 ) ;
F_4 ( & V_207 -> V_151 , 0x9512a254 ) ;
F_4 ( & V_207 -> V_152 , 0x03310000 ) ;
F_4 ( & V_207 -> V_153 , 0x06600f38 ) ;
F_4 ( & V_207 -> V_154 , 0x00000409 ) ;
F_4 ( & V_207 -> V_55 , 0 ) ;
F_4 ( & V_207 -> V_57 , 0 ) ;
F_4 ( & V_207 -> V_59 , 0x01e002d0 ) ;
F_4 ( & V_207 -> V_156 , 0x00000090 ) ;
F_4 ( & V_207 -> V_155 , 0x000000ff ) ;
}
static int F_96 ( struct V_69 * V_69 , struct V_208 * V_209 )
{
struct V_44 * V_45 = V_69 -> V_191 ;
int V_96 ;
F_2 ( 1 , L_45 , ( unsigned long ) V_209 ) ;
V_96 = F_97 ( & V_45 -> V_89 , V_209 ) ;
F_2 ( 1 , L_46 ,
( unsigned long ) V_209 -> V_210 ,
( unsigned long ) V_209 -> V_211 - ( unsigned long ) V_209 -> V_210 ,
V_96 ) ;
return V_96 ;
}
static int T_8 F_98 ( struct V_212 * V_213 )
{
struct V_7 * V_7 ;
struct V_184 * V_137 ;
struct V_214 V_215 ;
struct V_9 T_9 * V_216 ;
struct V_217 * V_218 ;
int V_96 , V_219 ;
V_96 = F_99 ( V_213 -> V_8 . V_220 , 0 , & V_215 ) ;
if ( V_96 ) {
F_100 ( & V_213 -> V_8 , L_47 ) ;
return - V_221 ;
}
V_219 = F_101 ( V_213 -> V_8 . V_220 , 0 ) ;
if ( V_219 == V_222 ) {
F_100 ( & V_213 -> V_8 , L_48 ) ;
return - V_58 ;
}
if ( ! F_102 ( & V_213 -> V_8 , V_215 . V_223 ,
sizeof( struct V_9 ) , V_224 ) ) {
F_100 ( & V_213 -> V_8 , L_49 ) ;
V_96 = - V_187 ;
goto V_108;
}
V_216 = F_103 ( & V_213 -> V_8 , V_215 . V_223 , sizeof( struct V_9 ) ) ;
if ( ! V_216 ) {
F_100 ( & V_213 -> V_8 , L_50 ) ;
V_96 = - V_190 ;
goto V_108;
}
V_7 = F_104 ( & V_213 -> V_8 , sizeof( struct V_7 ) , V_225 ) ;
if ( ! V_7 ) {
F_100 ( & V_213 -> V_8 , L_51 ) ;
V_96 = - V_190 ;
goto V_108;
}
V_7 -> V_10 = V_216 ;
V_7 -> V_170 = V_219 ;
V_7 -> V_8 = & V_213 -> V_8 ;
F_105 ( & V_7 -> V_19 . V_24 ) ;
F_105 ( & V_7 -> V_19 . V_34 ) ;
snprintf ( V_7 -> V_226 . V_86 ,
sizeof( V_7 -> V_226 . V_86 ) , L_52 , L_53 ) ;
V_96 = F_106 ( V_7 -> V_8 , & V_7 -> V_226 ) ;
if ( V_96 < 0 ) {
F_100 ( & V_213 -> V_8 , L_54 , V_96 ) ;
goto V_108;
}
V_218 = F_107 ( 0 ) ;
V_7 -> V_227 = F_108 ( & V_7 -> V_226 , V_218 ,
L_55 , V_228 , NULL ) ;
V_7 -> V_19 . V_31 . V_229 = F_15 ;
V_7 -> V_19 . V_31 . V_39 = ( unsigned long ) V_7 ;
F_109 ( & V_7 -> V_19 . V_31 ) ;
V_7 -> V_166 = 1 ;
V_137 = F_110 () ;
if ( V_137 == NULL ) {
V_96 = - V_190 ;
goto V_230;
}
memcpy ( V_137 , & V_231 , sizeof( V_231 ) ) ;
V_137 -> V_226 = & V_7 -> V_226 ;
V_7 -> V_137 = V_137 ;
F_111 ( & V_7 -> V_201 ) ;
V_7 -> V_137 -> V_201 = & V_7 -> V_201 ;
F_85 ( & V_7 -> V_109 ) ;
F_112 ( V_7 -> V_137 , V_7 ) ;
F_113 ( & V_7 -> V_201 ) ;
V_96 = F_114 ( V_7 -> V_137 , V_232 , - 1 ) ;
if ( V_96 < 0 ) {
F_115 ( V_7 -> V_137 ) ;
goto V_230;
}
V_7 -> V_233 = F_116 ( & V_213 -> V_8 , L_56 ) ;
if ( F_117 ( V_7 -> V_233 ) ) {
F_100 ( & V_213 -> V_8 , L_57 ) ;
V_96 = - V_221 ;
goto V_234;
} else {
F_118 ( V_7 -> V_233 ) ;
}
F_95 ( V_7 -> V_10 ) ;
if ( F_119 ( V_7 -> V_170 , F_80 , 0 , L_20 , ( void * ) V_7 ) ) {
F_100 ( & V_213 -> V_8 , L_58 ) ;
V_96 = - V_221 ;
goto V_235;
}
F_120 ( & V_7 -> V_201 ) ;
F_121 ( & V_213 -> V_8 , L_59 ) ;
return V_96 ;
V_235:
F_122 ( V_7 -> V_233 ) ;
F_123 ( V_7 -> V_233 ) ;
V_234:
F_124 ( V_7 -> V_137 ) ;
V_230:
F_120 ( & V_7 -> V_201 ) ;
F_125 ( V_218 ) ;
F_126 ( & V_7 -> V_226 ) ;
V_108:
F_127 ( V_219 ) ;
return V_96 ;
}
static int T_10 F_128 ( struct V_212 * V_213 )
{
struct V_236 * V_226 = F_129 ( & V_213 -> V_8 ) ;
struct V_7 * V_8 = F_26 ( V_226 , struct V_7 , V_226 ) ;
struct V_237 * V_238 = F_9 ( V_226 -> V_239 . V_25 ,
struct V_237 , V_240 ) ;
struct V_241 * V_242 = F_130 ( V_238 ) ;
F_131 ( V_8 -> V_170 , ( void * ) V_8 ) ;
F_127 ( V_8 -> V_170 ) ;
F_122 ( V_8 -> V_233 ) ;
F_123 ( V_8 -> V_233 ) ;
F_124 ( V_8 -> V_137 ) ;
F_125 ( V_242 -> V_243 ) ;
F_126 ( & V_8 -> V_226 ) ;
return 0 ;
}
static int F_132 ( struct V_212 * V_213 , T_11 V_28 )
{
struct V_236 * V_226 = F_129 ( & V_213 -> V_8 ) ;
struct V_7 * V_8 = F_26 ( V_226 , struct V_7 , V_226 ) ;
F_122 ( V_8 -> V_233 ) ;
return 0 ;
}
static int F_133 ( struct V_212 * V_213 )
{
struct V_236 * V_226 = F_129 ( & V_213 -> V_8 ) ;
struct V_7 * V_8 = F_26 ( V_226 , struct V_7 , V_226 ) ;
F_118 ( V_8 -> V_233 ) ;
return 0 ;
}
static int T_12 F_134 ( void )
{
return F_135 ( & V_244 ) ;
}
static void T_13 F_136 ( void )
{
F_137 ( & V_244 ) ;
}
