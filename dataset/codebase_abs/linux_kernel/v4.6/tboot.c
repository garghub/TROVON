void T_1 F_1 ( void )
{
if ( ! V_1 . V_2 )
return;
if ( ! F_2 ( V_1 . V_2 ,
V_1 . V_2 , V_3 ) ) {
F_3 ( L_1 ) ;
return;
}
if ( F_4 () ) {
F_3 ( L_2 ) ;
return;
}
F_5 ( V_4 , V_1 . V_2 ) ;
V_5 = (struct V_5 * ) F_6 ( V_4 ) ;
if ( memcmp ( & V_6 , & V_5 -> V_7 , sizeof( V_5 -> V_7 ) ) ) {
F_3 ( L_3 ,
V_1 . V_2 ) ;
V_5 = NULL ;
return;
}
if ( V_5 -> V_8 < 5 ) {
F_3 ( L_4 , V_5 -> V_8 ) ;
V_5 = NULL ;
return;
}
F_7 ( L_5 ,
V_1 . V_2 ) ;
F_8 ( L_6 , V_5 -> V_8 ) ;
F_8 ( L_7 , V_5 -> V_9 ) ;
F_8 ( L_8 , V_5 -> V_10 ) ;
F_8 ( L_9 , V_5 -> V_11 ) ;
F_8 ( L_10 , V_5 -> V_12 ) ;
}
static inline void F_9 ( void )
{
F_10 ( F_11 ( V_13 ) ) ;
}
static int F_12 ( unsigned long V_14 , unsigned long V_15 ,
T_2 V_16 )
{
T_3 * V_17 ;
T_4 * V_18 ;
T_5 * V_19 ;
T_6 * V_20 ;
V_17 = F_13 ( & V_21 , V_14 ) ;
V_18 = F_14 ( & V_21 , V_17 , V_14 ) ;
if ( ! V_18 )
return - 1 ;
V_19 = F_15 ( & V_21 , V_18 , V_14 ) ;
if ( ! V_19 )
return - 1 ;
V_20 = F_16 ( & V_21 , V_19 , V_14 ) ;
if ( ! V_20 )
return - 1 ;
F_17 ( & V_21 , V_14 , V_20 , F_18 ( V_15 , V_16 ) ) ;
F_19 ( V_20 ) ;
return 0 ;
}
static int F_20 ( unsigned long V_14 , unsigned long V_22 ,
unsigned long V_23 )
{
V_13 = F_21 ( & V_21 ) ;
if ( ! V_13 )
return - 1 ;
for (; V_23 > 0 ; V_23 -- , V_14 += V_24 , V_22 ++ ) {
if ( F_12 ( V_14 , V_22 , V_25 ) )
return - 1 ;
}
return 0 ;
}
static void F_22 ( void )
{
T_7 V_26 , V_27 ;
V_26 = F_23 ( V_5 -> V_11 ) ;
V_27 = F_24 ( V_5 -> V_12 ) ;
if ( F_20 ( V_26 << V_28 , V_26 , V_27 ) )
F_25 ( L_11 ,
V_26 , V_27 ) ;
}
static void F_26 ( T_8 V_29 , unsigned long V_30 )
{
struct V_31 * V_32 ;
T_8 V_33 = V_29 + V_30 ;
if ( V_5 -> V_34 >= V_35 )
F_25 ( L_12 ) ;
if ( V_29 && V_30 ) {
V_32 = & V_5 -> V_36 [ V_5 -> V_34 ++ ] ;
V_32 -> V_29 = F_27 ( V_29 , V_24 ) ;
V_32 -> V_30 = F_28 ( V_33 , V_24 ) - V_32 -> V_29 ;
}
}
static int F_29 ( void )
{
int V_37 ;
V_5 -> V_34 = 0 ;
for ( V_37 = 0 ; V_37 < V_38 . V_39 ; V_37 ++ ) {
if ( ( V_38 . V_40 [ V_37 ] . type != V_41 )
&& ( V_38 . V_40 [ V_37 ] . type != V_42 ) )
continue;
F_26 ( V_38 . V_40 [ V_37 ] . V_43 , V_38 . V_40 [ V_37 ] . V_30 ) ;
}
V_5 -> V_44 . V_45 =
V_46 -> V_47 ;
return 0 ;
}
static int F_29 ( void )
{
F_30 () ;
return - 1 ;
}
void F_31 ( T_7 V_48 )
{
void (* F_32)( void );
if ( ! F_33 () )
return;
if ( ! V_13 )
return;
if ( V_48 == V_49 )
if ( F_29 () )
return;
V_5 -> V_48 = V_48 ;
F_9 () ;
F_32 = ( void ( * ) ( void ) ) ( unsigned long ) V_5 -> V_10 ;
F_32 () ;
while ( 1 )
F_34 () ;
}
static void F_35 ( const struct V_50 * V_51 )
{
#define F_36 ( T_9 , T_10 ) \
tbg.space_id = g.space_id; \
tbg.bit_width = g.bit_width; \
tbg.bit_offset = g.bit_offset; \
tbg.access_width = g.access_width; \
tbg.address = g.address;
F_36 ( V_5 -> V_44 . V_52 , V_51 -> V_53 ) ;
F_36 ( V_5 -> V_44 . V_54 , V_51 -> V_55 ) ;
F_36 ( V_5 -> V_44 . V_56 , V_51 -> V_57 ) ;
F_36 ( V_5 -> V_44 . V_58 , V_51 -> V_59 ) ;
V_5 -> V_44 . V_60 = V_51 -> V_61 +
F_37 ( struct V_62 , V_63 ) ;
}
static int F_38 ( T_11 V_64 , T_7 V_65 , T_7 V_66 )
{
static T_7 V_67 [ V_68 ] = {
- 1 , - 1 , - 1 ,
V_49 ,
V_69 ,
V_70 } ;
if ( ! F_33 () )
return 0 ;
F_35 ( & V_71 ) ;
V_5 -> V_44 . V_72 = V_65 ;
V_5 -> V_44 . V_73 = V_66 ;
V_5 -> V_44 . V_74 = 32 ;
if ( V_64 >= V_68 ||
V_67 [ V_64 ] == - 1 ) {
F_3 ( L_13 , V_64 ) ;
return - 1 ;
}
F_31 ( V_67 [ V_64 ] ) ;
return 0 ;
}
static int F_39 ( T_11 V_64 , T_7 V_75 , T_7 V_76 )
{
if ( ! F_33 () )
return 0 ;
F_3 ( L_14 ) ;
return - V_77 ;
}
static int F_40 ( int V_78 )
{
unsigned long V_79 ;
V_79 = V_80 * V_81 ;
while ( F_41 ( ( V_82 * ) & V_5 -> V_83 ) != V_78 &&
V_79 ) {
F_42 ( 1 ) ;
V_79 -- ;
}
if ( V_79 )
F_3 ( L_15 ) ;
return ! ( F_41 ( ( V_82 * ) & V_5 -> V_83 ) == V_78 ) ;
}
static int F_43 ( struct V_84 * V_85 , unsigned long V_86 ,
void * V_87 )
{
switch ( V_86 ) {
case V_88 :
F_44 ( & V_89 ) ;
if ( F_45 () == 1 )
if ( F_40 ( F_41 ( & V_89 ) ) )
return V_90 ;
break;
}
return V_91 ;
}
static T_12 F_46 ( struct V_92 * V_92 , char T_13 * V_93 , T_14 V_94 , T_15 * V_95 )
{
void T_16 * V_96 ;
T_11 V_97 [ 16 ] ;
T_7 V_98 ;
void * V_99 ;
int V_100 = - V_101 ;
V_96 = F_47 ( V_102 , V_103 ) ;
if ( ! V_96 )
return V_100 ;
F_48 ( V_97 , V_96 , sizeof( V_97 ) ) ;
if ( memcmp ( & V_104 , V_97 , sizeof( V_97 ) ) )
goto V_105;
V_98 = F_49 ( V_96 + V_106 ) ;
if ( * V_95 >= V_98 ) {
V_100 = 0 ;
goto V_105;
}
if ( * V_95 + V_94 > V_98 )
V_94 = V_98 - * V_95 ;
V_99 = F_50 ( V_94 , V_107 ) ;
if ( ! V_99 ) {
V_100 = - V_108 ;
goto V_105;
}
F_48 ( V_99 , V_96 + V_109 + * V_95 , V_94 ) ;
if ( F_51 ( V_93 , V_99 , V_94 ) )
goto V_110;
* V_95 += V_94 ;
V_100 = V_94 ;
V_110:
F_52 ( V_99 ) ;
V_105:
F_53 ( V_96 ) ;
return V_100 ;
}
static T_1 int F_54 ( void )
{
if ( ! F_33 () )
return 0 ;
F_22 () ;
F_55 ( & V_89 , 0 ) ;
F_56 ( & V_111 ) ;
#ifdef F_57
F_58 ( L_16 , V_112 ,
V_113 , NULL , & V_114 ) ;
#endif
F_59 ( & F_38 ) ;
F_60 ( & F_39 ) ;
return 0 ;
}
struct V_115 * F_61 ( struct V_115 * V_116 )
{
void * V_117 , * V_118 , * V_119 ;
if ( ! F_33 () )
return V_116 ;
V_119 = F_62 ( V_120 , V_121 *
V_24 ) ;
if ( ! V_119 )
return NULL ;
V_117 = F_62 ( * ( V_122 * ) ( V_119 + V_123 ) ,
* ( V_122 * ) ( V_119 + V_124 ) ) ;
F_53 ( V_119 ) ;
if ( ! V_117 )
return NULL ;
V_118 = V_117 + * ( V_122 * ) V_117 ;
V_118 += * ( V_122 * ) V_118 ;
V_118 += * ( V_122 * ) V_118 ;
V_118 += sizeof( V_122 ) ;
V_116 = (struct V_115 * ) ( V_118 +
( (struct V_125 * ) V_118 ) -> V_126 -
sizeof( V_122 ) ) ;
return V_116 ;
}
int F_63 ( void )
{
if ( ! F_33 () )
return 0 ;
if ( V_127 || V_128 || V_129 )
F_3 ( L_17 ) ;
V_129 = 0 ;
#ifdef F_64
V_128 = 0 ;
#endif
V_127 = 0 ;
return 1 ;
}
