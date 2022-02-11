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
static void F_6 ( struct V_1 * V_2 )
{
struct V_25 V_26 ;
memset ( & V_26 , 0 , sizeof( struct V_25 ) ) ;
V_26 . V_8 . type = V_27 ;
V_26 . V_8 . V_10 = sizeof( struct V_25 ) ;
V_26 . V_8 . V_11 = F_3 ( & V_11 ) ;
V_26 . V_28 = F_7 () ;
F_4 ( V_2 -> V_16 -> V_17 , & V_26 ,
sizeof( struct V_25 ) ,
( unsigned long ) NULL ,
V_18 , 0 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
union V_29 * V_30 )
{
int V_31 = V_30 -> V_32 . V_33 ;
T_1 V_34 = V_30 -> V_32 . V_35 ;
struct V_36 * V_37 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_31 ; V_38 ++ ) {
V_37 = F_9 ( V_38 + V_34 ) ;
F_10 ( V_37 ) ;
V_2 -> V_39 -- ;
}
}
static int F_11 ( struct V_1 * V_2 , int V_31 ,
struct V_40 * V_41 , int V_42 ,
bool * V_43 )
{
int V_38 = 0 ;
struct V_36 * V_37 ;
if ( V_31 < V_42 )
return 0 ;
for ( V_38 = 0 ; ( V_38 * V_42 ) < V_31 ; V_38 ++ ) {
if ( V_41 -> V_8 . V_10 + sizeof( union V_29 ) >
V_44 )
return V_38 * V_42 ;
V_37 = F_12 ( V_45 | V_46 |
V_47 | V_48 ,
F_13 ( V_42 << V_49 ) ) ;
if ( ! V_37 ) {
* V_43 = true ;
return V_38 * V_42 ;
}
V_2 -> V_39 += V_42 ;
V_41 -> V_50 ++ ;
V_41 -> V_30 [ V_38 ] . V_32 . V_35 =
F_14 ( V_37 ) ;
V_41 -> V_30 [ V_38 ] . V_32 . V_33 = V_42 ;
V_41 -> V_8 . V_10 += sizeof( union V_29 ) ;
}
return V_31 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
int V_31 = V_52 -> V_31 ;
int V_53 = 0 ;
struct V_40 * V_41 ;
int V_42 ;
int V_54 ;
bool V_43 = false ;
bool V_55 = false ;
int V_38 ;
V_42 = 1 ;
while ( ! V_55 ) {
V_41 = (struct V_40 * ) V_56 ;
memset ( V_56 , 0 , V_44 ) ;
V_41 -> V_8 . type = V_57 ;
V_41 -> V_8 . V_11 = F_3 ( & V_11 ) ;
V_41 -> V_8 . V_10 = sizeof( struct V_40 ) ;
V_41 -> V_58 = 1 ;
V_31 -= V_53 ;
V_53 = F_11 ( V_2 , V_31 ,
V_41 , V_42 ,
& V_43 ) ;
if ( ( V_43 ) || ( V_53 == V_31 ) ) {
V_41 -> V_58 = 0 ;
V_55 = true ;
V_2 -> V_14 = V_15 ;
}
do {
V_54 = F_4 ( V_59 . V_16 -> V_17 ,
V_41 ,
V_41 -> V_8 . V_10 ,
( unsigned long ) NULL ,
V_18 , 0 ) ;
if ( V_54 == - V_60 )
F_16 ( 20 ) ;
} while ( V_54 == - V_60 );
if ( V_54 ) {
F_2 ( L_5 ) ;
for ( V_38 = 0 ; V_38 < V_41 -> V_50 ; V_38 ++ )
F_8 ( V_2 ,
& V_41 -> V_30 [ V_38 ] ) ;
V_55 = true ;
}
}
}
static void F_17 ( struct V_1 * V_2 ,
struct V_61 * V_52 )
{
union V_29 * V_30 = V_52 -> V_30 ;
int V_50 = V_52 -> V_50 ;
struct V_62 V_6 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_50 ; V_38 ++ )
F_8 ( V_2 , & V_30 [ V_38 ] ) ;
if ( V_52 -> V_58 == 1 )
return;
memset ( & V_6 , 0 , sizeof( struct V_62 ) ) ;
V_6 . V_8 . type = V_63 ;
V_6 . V_8 . V_11 = F_3 ( & V_11 ) ;
V_6 . V_8 . V_10 = sizeof( struct V_62 ) ;
F_4 ( V_59 . V_16 -> V_17 , & V_6 ,
sizeof( struct V_62 ) ,
( unsigned long ) NULL ,
V_18 , 0 ) ;
V_2 -> V_14 = V_15 ;
}
static int F_18 ( void * V_64 )
{
struct V_1 * V_2 = V_64 ;
int V_65 ;
unsigned long V_66 ;
while ( ! F_19 () ) {
V_65 = F_20 ( & V_59 . V_67 , 1 * V_68 ) ;
if ( V_65 == 0 )
F_6 ( V_2 ) ;
V_66 = V_69 ;
switch ( V_2 -> V_14 ) {
case V_70 :
F_15 ( V_2 , (struct V_51 * ) V_71 ) ;
break;
case V_72 :
F_1 ( V_2 , (struct V_3 * ) V_71 ) ;
break;
default:
break;
}
if ( ! F_21 ( V_69 , V_66 , V_66 + V_68 ) )
F_6 ( V_2 ) ;
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_75 V_76 ;
int V_54 ;
if ( V_74 -> V_77 ) {
F_23 ( & V_2 -> V_78 ) ;
return;
}
if ( V_2 -> V_79 == 0 )
goto V_80;
V_2 -> V_79 = 0 ;
memset ( & V_76 , 0 , sizeof( struct V_75 ) ) ;
V_76 . V_8 . type = V_81 ;
V_76 . V_8 . V_10 = sizeof( struct V_75 ) ;
V_76 . V_8 . V_11 = F_3 ( & V_11 ) ;
V_76 . V_82 . V_82 = V_83 ;
V_76 . V_84 = 1 ;
V_54 = F_4 ( V_2 -> V_16 -> V_17 , & V_76 ,
sizeof( struct V_75 ) ,
( unsigned long ) NULL ,
V_18 , 0 ) ;
if ( V_54 )
goto V_80;
return;
V_80:
V_2 -> V_14 = V_85 ;
F_23 ( & V_2 -> V_78 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_86 * F_24 )
{
if ( ! F_24 -> V_77 ) {
F_2 ( L_6 ) ;
V_2 -> V_14 = V_85 ;
}
F_23 ( & V_2 -> V_78 ) ;
}
static void F_25 ( void * V_87 )
{
struct V_88 * V_16 = V_87 ;
T_2 V_89 ;
T_3 V_90 ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
struct V_1 * V_2 = F_26 ( V_16 ) ;
memset ( V_71 , 0 , sizeof( V_71 ) ) ;
F_27 ( V_16 -> V_17 , V_71 ,
V_44 , & V_89 , & V_90 ) ;
if ( V_89 > 0 ) {
V_92 = (struct V_91 * ) V_71 ;
V_94 = & V_92 -> V_8 ;
switch ( V_94 -> type ) {
case V_95 :
F_22 ( V_2 ,
(struct V_73 * ) V_92 ) ;
break;
case V_96 :
F_24 ( V_2 ,
(struct V_86 * ) V_92 ) ;
break;
case V_97 :
V_2 -> V_14 = V_70 ;
F_23 ( & V_2 -> V_67 ) ;
break;
case V_98 :
V_2 -> V_14 = V_99 ;
F_17 ( V_2 ,
(struct V_61 * ) V_71 ) ;
break;
case V_100 :
V_2 -> V_14 = V_72 ;
F_23 ( & V_2 -> V_67 ) ;
break;
case V_101 :
F_5 ( V_2 , (struct V_19 * ) V_92 ) ;
break;
default:
F_28 ( L_7 , V_94 -> type ) ;
}
}
}
static int F_29 ( struct V_88 * V_16 ,
const struct V_102 * V_103 )
{
int V_54 , V_65 ;
struct V_75 V_76 ;
struct V_104 V_105 ;
V_7 = V_106 ;
V_56 = F_30 ( V_44 , V_107 ) ;
if ( ! V_56 )
return - V_108 ;
V_54 = F_31 ( V_16 -> V_17 , V_109 , V_109 , NULL , 0 ,
F_25 , V_16 ) ;
if ( V_54 )
goto V_110;
V_59 . V_16 = V_16 ;
V_59 . V_14 = V_111 ;
V_59 . V_79 = V_83 ;
F_32 ( & V_59 . V_78 ) ;
F_32 ( & V_59 . V_67 ) ;
V_59 . V_112 =
F_33 ( F_18 , & V_59 , L_8 ) ;
if ( F_34 ( V_59 . V_112 ) ) {
V_54 = F_35 ( V_59 . V_112 ) ;
goto V_113;
}
F_36 ( V_16 , & V_59 ) ;
memset ( & V_76 , 0 , sizeof( struct V_75 ) ) ;
V_76 . V_8 . type = V_81 ;
V_76 . V_8 . V_10 = sizeof( struct V_75 ) ;
V_76 . V_8 . V_11 = F_3 ( & V_11 ) ;
V_76 . V_82 . V_82 = V_114 ;
V_76 . V_84 = 0 ;
V_54 = F_4 ( V_16 -> V_17 , & V_76 ,
sizeof( struct V_75 ) ,
( unsigned long ) NULL ,
V_18 ,
V_115 ) ;
if ( V_54 )
goto V_116;
V_65 = F_20 ( & V_59 . V_78 , 5 * V_68 ) ;
if ( V_65 == 0 ) {
V_54 = - V_117 ;
goto V_116;
}
if ( V_59 . V_14 == V_85 ) {
V_54 = - V_117 ;
goto V_116;
}
memset ( & V_105 , 0 , sizeof( struct V_104 ) ) ;
V_105 . V_8 . type = V_118 ;
V_105 . V_8 . V_10 = sizeof( struct V_104 ) ;
V_105 . V_8 . V_11 = F_3 ( & V_11 ) ;
V_105 . V_119 . V_120 . V_121 = 1 ;
V_105 . V_119 . V_120 . V_106 = 1 ;
V_105 . V_122 = 0 ;
V_105 . V_123 = - 1 ;
V_54 = F_4 ( V_16 -> V_17 , & V_105 ,
sizeof( struct V_104 ) ,
( unsigned long ) NULL ,
V_18 ,
V_115 ) ;
if ( V_54 )
goto V_116;
V_65 = F_20 ( & V_59 . V_78 , 5 * V_68 ) ;
if ( V_65 == 0 ) {
V_54 = - V_117 ;
goto V_116;
}
if ( V_59 . V_14 == V_85 ) {
V_54 = - V_117 ;
goto V_116;
}
V_59 . V_14 = V_15 ;
return 0 ;
V_116:
F_37 ( V_59 . V_112 ) ;
V_113:
F_38 ( V_16 -> V_17 ) ;
V_110:
F_39 ( V_56 ) ;
return V_54 ;
}
static int F_40 ( struct V_88 * V_16 )
{
struct V_1 * V_2 = F_26 ( V_16 ) ;
if ( V_2 -> V_39 != 0 )
F_41 ( L_9 , V_2 -> V_39 ) ;
F_38 ( V_16 -> V_17 ) ;
F_37 ( V_2 -> V_112 ) ;
F_39 ( V_56 ) ;
return 0 ;
}
static int T_4 F_42 ( void )
{
return F_43 ( & V_124 ) ;
}
static void F_44 ( void )
{
F_45 ( & V_124 ) ;
}
