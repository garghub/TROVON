static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 ;
if ( V_7 ) {
F_2 ( L_1 ) ;
}
memset ( & V_6 , 0 , sizeof( struct V_5 ) ) ;
V_6 . V_8 . type = V_9 ;
V_6 . V_8 . V_10 = sizeof( struct V_5 ) ;
V_6 . V_8 . V_11 = F_3 ( & V_11 ) ;
V_6 . V_12 = 0 ;
V_6 . V_13 = 0 ;
V_2 -> V_14 = V_15 ;
F_4 ( V_2 -> V_16 -> V_17 , & V_6 ,
sizeof( struct V_5 ) ,
( unsigned long ) NULL ,
V_18 , 0 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_19 * V_4 )
{
struct V_20 * V_21 ;
V_21 = (struct V_20 * ) V_4 -> V_22 ;
switch ( V_21 -> type ) {
case V_23 :
F_2 ( L_2 ) ;
F_2 ( L_3 , V_21 -> V_24 ) ;
break;
default:
F_2 ( L_4 , V_21 -> type ) ;
}
}
unsigned long F_6 ( void )
{
unsigned long V_25 ;
#define F_7 ( T_1 ) ((mb) << (20 - PAGE_SHIFT))
if ( V_26 < F_7 ( 128 ) )
V_25 = F_7 ( 8 ) + ( V_26 >> 1 ) ;
else if ( V_26 < F_7 ( 512 ) )
V_25 = F_7 ( 40 ) + ( V_26 >> 2 ) ;
else if ( V_26 < F_7 ( 2048 ) )
V_25 = F_7 ( 104 ) + ( V_26 >> 3 ) ;
else
V_25 = F_7 ( 296 ) + ( V_26 >> 5 ) ;
#undef F_7
return V_25 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_27 V_28 ;
struct V_29 V_30 ;
if ( V_31 > 0 ) {
-- V_31 ;
return;
}
F_9 ( & V_30 ) ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
V_28 . V_8 . type = V_32 ;
V_28 . V_8 . V_10 = sizeof( struct V_27 ) ;
V_28 . V_8 . V_11 = F_3 ( & V_11 ) ;
V_28 . V_33 = V_30 . V_34 ;
V_28 . V_35 = F_10 () +
V_2 -> V_36 +
F_6 () ;
F_4 ( V_2 -> V_16 -> V_17 , & V_28 ,
sizeof( struct V_27 ) ,
( unsigned long ) NULL ,
V_18 , 0 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
union V_37 * V_38 )
{
int V_39 = V_38 -> V_40 . V_41 ;
T_2 V_42 = V_38 -> V_40 . V_43 ;
struct V_44 * V_45 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_39 ; V_46 ++ ) {
V_45 = F_12 ( V_46 + V_42 ) ;
F_13 ( V_45 ) ;
V_2 -> V_36 -- ;
}
}
static int F_14 ( struct V_1 * V_2 , int V_39 ,
struct V_47 * V_48 , int V_49 ,
bool * V_50 )
{
int V_46 = 0 ;
struct V_44 * V_45 ;
if ( V_39 < V_49 )
return 0 ;
for ( V_46 = 0 ; ( V_46 * V_49 ) < V_39 ; V_46 ++ ) {
if ( V_48 -> V_8 . V_10 + sizeof( union V_37 ) >
V_51 )
return V_46 * V_49 ;
V_45 = F_15 ( V_52 | V_53 |
V_54 | V_55 ,
F_16 ( V_49 << V_56 ) ) ;
if ( ! V_45 ) {
* V_50 = true ;
return V_46 * V_49 ;
}
V_2 -> V_36 += V_49 ;
V_48 -> V_57 ++ ;
V_48 -> V_38 [ V_46 ] . V_40 . V_43 =
F_17 ( V_45 ) ;
V_48 -> V_38 [ V_46 ] . V_40 . V_41 = V_49 ;
V_48 -> V_8 . V_10 += sizeof( union V_37 ) ;
}
return V_39 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
int V_39 = V_59 -> V_39 ;
int V_60 = 0 ;
struct V_47 * V_48 ;
int V_49 ;
int V_61 ;
bool V_50 = false ;
bool V_62 = false ;
int V_46 ;
V_49 = 1 ;
while ( ! V_62 ) {
V_48 = (struct V_47 * ) V_63 ;
memset ( V_63 , 0 , V_51 ) ;
V_48 -> V_8 . type = V_64 ;
V_48 -> V_8 . V_11 = F_3 ( & V_11 ) ;
V_48 -> V_8 . V_10 = sizeof( struct V_47 ) ;
V_48 -> V_65 = 1 ;
V_39 -= V_60 ;
V_60 = F_14 ( V_2 , V_39 ,
V_48 , V_49 ,
& V_50 ) ;
if ( ( V_50 ) || ( V_60 == V_39 ) ) {
V_48 -> V_65 = 0 ;
V_62 = true ;
V_2 -> V_14 = V_15 ;
}
do {
V_61 = F_4 ( V_66 . V_16 -> V_17 ,
V_48 ,
V_48 -> V_8 . V_10 ,
( unsigned long ) NULL ,
V_18 , 0 ) ;
if ( V_61 == - V_67 )
F_19 ( 20 ) ;
} while ( V_61 == - V_67 );
if ( V_61 ) {
F_2 ( L_5 ) ;
for ( V_46 = 0 ; V_46 < V_48 -> V_57 ; V_46 ++ )
F_11 ( V_2 ,
& V_48 -> V_38 [ V_46 ] ) ;
V_62 = true ;
}
}
}
static void F_20 ( struct V_1 * V_2 ,
struct V_68 * V_59 )
{
union V_37 * V_38 = V_59 -> V_38 ;
int V_57 = V_59 -> V_57 ;
struct V_69 V_6 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_57 ; V_46 ++ )
F_11 ( V_2 , & V_38 [ V_46 ] ) ;
if ( V_59 -> V_65 == 1 )
return;
memset ( & V_6 , 0 , sizeof( struct V_69 ) ) ;
V_6 . V_8 . type = V_70 ;
V_6 . V_8 . V_11 = F_3 ( & V_11 ) ;
V_6 . V_8 . V_10 = sizeof( struct V_69 ) ;
F_4 ( V_66 . V_16 -> V_17 , & V_6 ,
sizeof( struct V_69 ) ,
( unsigned long ) NULL ,
V_18 , 0 ) ;
V_2 -> V_14 = V_15 ;
}
static int F_21 ( void * V_71 )
{
struct V_1 * V_2 = V_71 ;
int V_72 ;
unsigned long V_73 ;
while ( ! F_22 () ) {
V_72 = F_23 ( & V_66 . V_74 , 1 * V_75 ) ;
if ( V_72 == 0 )
F_8 ( V_2 ) ;
V_73 = V_76 ;
switch ( V_2 -> V_14 ) {
case V_77 :
F_18 ( V_2 , (struct V_58 * ) V_78 ) ;
break;
case V_79 :
F_1 ( V_2 , (struct V_3 * ) V_78 ) ;
break;
default:
break;
}
if ( ! F_24 ( V_76 , V_73 , V_73 + V_75 ) )
F_8 ( V_2 ) ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_80 * V_81 )
{
struct V_82 V_83 ;
int V_61 ;
if ( V_81 -> V_84 ) {
F_26 ( & V_2 -> V_85 ) ;
return;
}
if ( V_2 -> V_86 == 0 )
goto V_87;
V_2 -> V_86 = 0 ;
memset ( & V_83 , 0 , sizeof( struct V_82 ) ) ;
V_83 . V_8 . type = V_88 ;
V_83 . V_8 . V_10 = sizeof( struct V_82 ) ;
V_83 . V_8 . V_11 = F_3 ( & V_11 ) ;
V_83 . V_89 . V_89 = V_90 ;
V_83 . V_91 = 1 ;
V_61 = F_4 ( V_2 -> V_16 -> V_17 , & V_83 ,
sizeof( struct V_82 ) ,
( unsigned long ) NULL ,
V_18 , 0 ) ;
if ( V_61 )
goto V_87;
return;
V_87:
V_2 -> V_14 = V_92 ;
F_26 ( & V_2 -> V_85 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_93 * F_27 )
{
if ( ! F_27 -> V_84 ) {
F_2 ( L_6 ) ;
V_2 -> V_14 = V_92 ;
}
F_26 ( & V_2 -> V_85 ) ;
}
static void F_28 ( void * V_94 )
{
struct V_95 * V_16 = V_94 ;
T_3 V_96 ;
T_4 V_97 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_1 * V_2 = F_29 ( V_16 ) ;
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
F_30 ( V_16 -> V_17 , V_78 ,
V_51 , & V_96 , & V_97 ) ;
if ( V_96 > 0 ) {
V_99 = (struct V_98 * ) V_78 ;
V_101 = & V_99 -> V_8 ;
switch ( V_101 -> type ) {
case V_102 :
F_25 ( V_2 ,
(struct V_80 * ) V_99 ) ;
break;
case V_103 :
F_27 ( V_2 ,
(struct V_93 * ) V_99 ) ;
break;
case V_104 :
V_2 -> V_14 = V_77 ;
F_26 ( & V_2 -> V_74 ) ;
break;
case V_105 :
V_2 -> V_14 = V_106 ;
F_20 ( V_2 ,
(struct V_68 * ) V_78 ) ;
break;
case V_107 :
V_2 -> V_14 = V_79 ;
F_26 ( & V_2 -> V_74 ) ;
break;
case V_108 :
F_5 ( V_2 , (struct V_19 * ) V_99 ) ;
break;
default:
F_31 ( L_7 , V_101 -> type ) ;
}
}
}
static int F_32 ( struct V_95 * V_16 ,
const struct V_109 * V_110 )
{
int V_61 , V_72 ;
struct V_82 V_83 ;
struct V_111 V_112 ;
V_7 = V_113 ;
V_63 = F_33 ( V_51 , V_114 ) ;
if ( ! V_63 )
return - V_115 ;
V_61 = F_34 ( V_16 -> V_17 , V_116 , V_116 , NULL , 0 ,
F_28 , V_16 ) ;
if ( V_61 )
goto V_117;
V_66 . V_16 = V_16 ;
V_66 . V_14 = V_118 ;
V_66 . V_86 = V_90 ;
F_35 ( & V_66 . V_85 ) ;
F_35 ( & V_66 . V_74 ) ;
V_66 . V_119 =
F_36 ( F_21 , & V_66 , L_8 ) ;
if ( F_37 ( V_66 . V_119 ) ) {
V_61 = F_38 ( V_66 . V_119 ) ;
goto V_120;
}
F_39 ( V_16 , & V_66 ) ;
memset ( & V_83 , 0 , sizeof( struct V_82 ) ) ;
V_83 . V_8 . type = V_88 ;
V_83 . V_8 . V_10 = sizeof( struct V_82 ) ;
V_83 . V_8 . V_11 = F_3 ( & V_11 ) ;
V_83 . V_89 . V_89 = V_121 ;
V_83 . V_91 = 0 ;
V_61 = F_4 ( V_16 -> V_17 , & V_83 ,
sizeof( struct V_82 ) ,
( unsigned long ) NULL ,
V_18 ,
V_122 ) ;
if ( V_61 )
goto V_123;
V_72 = F_23 ( & V_66 . V_85 , 5 * V_75 ) ;
if ( V_72 == 0 ) {
V_61 = - V_124 ;
goto V_123;
}
if ( V_66 . V_14 == V_92 ) {
V_61 = - V_124 ;
goto V_123;
}
memset ( & V_112 , 0 , sizeof( struct V_111 ) ) ;
V_112 . V_8 . type = V_125 ;
V_112 . V_8 . V_10 = sizeof( struct V_111 ) ;
V_112 . V_8 . V_11 = F_3 ( & V_11 ) ;
V_112 . V_126 . V_127 . V_128 = 1 ;
V_112 . V_126 . V_127 . V_113 = 1 ;
V_112 . V_129 = 0 ;
V_112 . V_130 = - 1 ;
V_61 = F_4 ( V_16 -> V_17 , & V_112 ,
sizeof( struct V_111 ) ,
( unsigned long ) NULL ,
V_18 ,
V_122 ) ;
if ( V_61 )
goto V_123;
V_72 = F_23 ( & V_66 . V_85 , 5 * V_75 ) ;
if ( V_72 == 0 ) {
V_61 = - V_124 ;
goto V_123;
}
if ( V_66 . V_14 == V_92 ) {
V_61 = - V_124 ;
goto V_123;
}
V_66 . V_14 = V_15 ;
return 0 ;
V_123:
F_40 ( V_66 . V_119 ) ;
V_120:
F_41 ( V_16 -> V_17 ) ;
V_117:
F_42 ( V_63 ) ;
return V_61 ;
}
static int F_43 ( struct V_95 * V_16 )
{
struct V_1 * V_2 = F_29 ( V_16 ) ;
if ( V_2 -> V_36 != 0 )
F_44 ( L_9 , V_2 -> V_36 ) ;
F_41 ( V_16 -> V_17 ) ;
F_40 ( V_2 -> V_119 ) ;
F_42 ( V_63 ) ;
return 0 ;
}
static int T_5 F_45 ( void )
{
return F_46 ( & V_131 ) ;
}
static void F_47 ( void )
{
F_48 ( & V_131 ) ;
}
