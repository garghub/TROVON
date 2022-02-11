static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_2 ( & V_3 ) ;
if ( V_4 ||
( V_5 && ( V_2 -> V_6 & V_7 ) ) ) {
F_3 ( & V_3 ) ;
return - V_8 ;
}
if ( V_2 -> V_6 & V_7 )
V_4 = 1 ;
V_5 ++ ;
F_3 ( & V_3 ) ;
return F_4 ( V_1 , V_2 ) ;
}
static int F_5 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_2 ( & V_3 ) ;
V_5 -- ;
V_4 = 0 ;
F_3 ( & V_3 ) ;
return 0 ;
}
static T_1 F_6 ( struct V_2 * V_9 , char T_2 * V_10 ,
T_3 V_11 , T_4 * V_12 )
{
char T_2 * V_13 = V_10 ;
unsigned V_14 ;
int V_15 , V_16 ;
F_7 ( & V_17 ) ;
V_14 = V_18 . V_19 ;
V_16 = - V_20 ;
if ( * V_12 != 0 || V_11 < V_21 * sizeof( struct V_22 ) )
goto V_23;
V_16 = 0 ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ ) {
struct V_22 * V_24 = & V_18 . V_25 [ V_15 ] ;
V_16 |= F_8 ( V_13 , V_24 , sizeof( * V_24 ) ) ;
V_13 += sizeof( * V_24 ) ;
}
memset ( V_18 . V_25 , 0 , V_14 * sizeof( struct V_22 ) ) ;
V_18 . V_19 = 0 ;
if ( V_16 )
V_16 = - V_26 ;
V_23:
F_9 ( & V_17 ) ;
return V_16 ? V_16 : V_13 - V_10 ;
}
static unsigned int F_10 ( struct V_2 * V_2 , T_5 * V_27 )
{
F_11 ( V_2 , & V_28 , V_27 ) ;
if ( V_18 . V_19 )
return V_29 | V_30 ;
return 0 ;
}
static long F_12 ( struct V_2 * V_31 , unsigned int V_32 ,
unsigned long V_33 )
{
int T_2 * V_34 = ( int T_2 * ) V_33 ;
if ( ! F_13 ( V_35 ) )
return - V_36 ;
switch ( V_32 ) {
case V_37 :
return F_14 ( sizeof( struct V_22 ) , V_34 ) ;
case V_38 :
return F_14 ( V_21 , V_34 ) ;
case V_39 : {
unsigned V_40 ;
do {
V_40 = V_18 . V_40 ;
} while ( F_15 ( & V_18 . V_40 , V_40 , 0 ) != V_40 );
return F_14 ( V_40 , V_34 ) ;
}
default:
return - V_41 ;
}
}
static void F_16 ( struct V_22 * V_42 )
{
unsigned V_25 ;
V_25 = V_18 . V_19 ;
if ( V_25 >= V_21 ) {
F_17 ( V_43 ,
( unsigned long * ) & V_18 . V_40 ) ;
return;
}
memcpy ( V_18 . V_25 + V_25 , V_42 , sizeof( struct V_22 ) ) ;
V_18 . V_19 ++ ;
}
static int F_18 ( struct V_44 * V_45 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
struct V_22 V_24 ;
T_6 V_15 ;
V_47 = NULL ;
F_19 ( & V_47 , V_45 , V_52 ) ;
if ( F_20 ( ! V_47 ) ) {
F_21 ( L_1 ) ;
return - V_53 ;
}
memset ( & V_24 , 0 , sizeof( struct V_22 ) ) ;
V_49 = (struct V_48 * ) V_47 ;
V_24 . V_54 = V_49 -> V_55 ;
V_24 . V_56 = V_49 -> V_57 ;
for ( V_15 = 0 ; V_15 < V_58 ; V_15 ++ )
if ( V_59 [ V_15 ] . V_57 == V_24 . V_56 )
break;
if ( F_20 ( V_15 == V_58 ) ) {
F_21 ( L_2 , V_24 . V_56 ) ;
return - V_53 ;
}
V_24 . V_60 = V_59 [ V_15 ] . V_61 ;
V_24 . V_62 = V_24 . V_63 = V_59 [ V_15 ] . V_64 ;
V_24 . V_65 = ( V_66 ) V_59 [ V_15 ] . V_67 ;
V_24 . V_68 = V_59 [ V_15 ] . V_69 [ V_70 ] . V_71 ;
V_47 = NULL ;
F_19 ( & V_47 , V_45 , V_72 ) ;
if ( F_20 ( ! V_47 ) ) {
F_21 ( L_3 ) ;
return - V_53 ;
}
do {
if ( ( ! V_47 ) || ( V_47 -> V_73 == 0 ) ||
( V_47 -> type != V_52 &&
V_47 -> type != V_72 &&
V_47 -> type != V_74 &&
V_47 -> type != V_75 ) )
break;
if ( V_47 -> type == V_72 ) {
V_51 = (struct V_50 * ) V_47 ;
V_24 . V_76 = V_51 -> V_77 ;
V_24 . V_78 = V_51 -> V_79 ;
V_24 . V_80 = V_51 -> V_81 ;
V_24 . V_82 = V_51 -> V_83 ;
V_24 . V_84 = V_51 -> V_51 ;
V_24 . V_85 = 1 ;
F_16 ( & V_24 ) ;
}
V_47 = F_22 ( V_47 ) ;
} while ( 1 );
return 0 ;
}
static int F_23 ( T_6 V_40 )
{
struct V_86 V_87 ;
int V_88 = 0 ;
V_87 . V_32 = V_89 ;
V_87 . V_90 = V_91 ;
F_24 ( V_87 . V_92 . V_93 . V_94 , & V_95 ) ;
do {
V_87 . V_92 . V_93 . V_40 = V_40 ;
V_88 = F_25 ( & V_87 ) ;
if ( V_88 ) {
F_26 ( L_4 ,
V_40 == V_96 ? L_5 : L_6 ) ;
break;
}
if ( V_87 . V_92 . V_93 . V_40 & V_97 ||
V_87 . V_92 . V_93 . V_40 & V_98 )
break;
else {
V_88 = F_18 ( & V_95 ) ;
if ( V_88 )
F_21 ( L_7 ) ;
V_87 . V_92 . V_93 . V_40 = V_40 | V_99 ;
V_88 = F_25 ( & V_87 ) ;
if ( V_88 ) {
F_26 ( L_8 ) ;
break;
}
}
} while ( 1 );
return V_88 ;
}
static void F_27 ( struct V_100 * V_101 )
{
int V_16 ;
F_7 ( & V_17 ) ;
V_16 = F_23 ( V_96 ) ;
if ( V_16 )
F_26 ( L_9 ) ;
V_16 = F_23 ( V_102 ) ;
if ( V_16 )
F_26 ( L_10 ) ;
F_28 ( & V_28 ) ;
F_9 ( & V_17 ) ;
}
static T_7 F_29 ( int V_103 , void * V_104 )
{
F_30 ( & V_105 ) ;
return V_106 ;
}
static int F_31 ( void )
{
int V_88 ;
struct V_86 V_87 ;
memset ( & V_87 , 0 , sizeof( struct V_86 ) ) ;
V_87 . V_32 = V_107 ;
V_87 . V_90 = V_91 ;
F_24 ( V_87 . V_92 . V_108 . V_109 , V_59 ) ;
V_88 = F_25 ( & V_87 ) ;
if ( V_88 ) {
F_26 ( L_11 ) ;
return V_88 ;
}
V_58 = V_87 . V_92 . V_108 . V_58 ;
V_59 = F_32 ( V_58 , sizeof( struct V_110 ) ,
V_111 ) ;
if ( ! V_59 )
return - V_112 ;
F_24 ( V_87 . V_92 . V_108 . V_109 , V_59 ) ;
V_88 = F_25 ( & V_87 ) ;
if ( V_88 ) {
F_26 ( L_12 ) ;
F_33 ( V_59 ) ;
return V_88 ;
}
V_88 = F_34 ( V_113 , 0 ,
F_29 , 0 , L_13 , NULL ) ;
if ( V_88 < 0 ) {
F_26 ( L_14 ) ;
F_33 ( V_59 ) ;
return V_88 ;
}
return 0 ;
}
static int T_8 F_35 ( void )
{
if ( F_36 () ) {
if ( F_37 ( & V_114 ) )
return - V_53 ;
return F_31 () ;
}
return - V_53 ;
}
