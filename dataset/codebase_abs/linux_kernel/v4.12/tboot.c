void T_1 F_1 ( void )
{
if ( ! V_1 . V_2 )
return;
if ( ! F_2 ( V_1 . V_2 ,
V_1 . V_2 , V_3 ) ) {
F_3 ( L_1 ) ;
return;
}
F_4 ( V_4 , V_1 . V_2 ) ;
V_5 = (struct V_5 * ) F_5 ( V_4 ) ;
if ( memcmp ( & V_6 , & V_5 -> V_7 , sizeof( V_5 -> V_7 ) ) ) {
F_3 ( L_2 ,
V_1 . V_2 ) ;
V_5 = NULL ;
return;
}
if ( V_5 -> V_8 < 5 ) {
F_3 ( L_3 , V_5 -> V_8 ) ;
V_5 = NULL ;
return;
}
F_6 ( L_4 ,
V_1 . V_2 ) ;
F_7 ( L_5 , V_5 -> V_8 ) ;
F_7 ( L_6 , V_5 -> V_9 ) ;
F_7 ( L_7 , V_5 -> V_10 ) ;
F_7 ( L_8 , V_5 -> V_11 ) ;
F_7 ( L_9 , V_5 -> V_12 ) ;
}
static inline void F_8 ( void )
{
F_9 ( F_10 ( V_13 ) ) ;
}
static int F_11 ( unsigned long V_14 , unsigned long V_15 ,
T_2 V_16 )
{
T_3 * V_17 ;
T_4 * V_18 ;
T_5 * V_19 ;
T_6 * V_20 ;
T_7 * V_21 ;
V_17 = F_12 ( & V_22 , V_14 ) ;
V_18 = F_13 ( & V_22 , V_17 , V_14 ) ;
if ( ! V_18 )
return - 1 ;
V_19 = F_14 ( & V_22 , V_18 , V_14 ) ;
if ( ! V_19 )
return - 1 ;
V_20 = F_15 ( & V_22 , V_19 , V_14 ) ;
if ( ! V_20 )
return - 1 ;
V_21 = F_16 ( & V_22 , V_20 , V_14 ) ;
if ( ! V_21 )
return - 1 ;
F_17 ( & V_22 , V_14 , V_21 , F_18 ( V_15 , V_16 ) ) ;
F_19 ( V_21 ) ;
return 0 ;
}
static int F_20 ( unsigned long V_14 , unsigned long V_23 ,
unsigned long V_24 )
{
V_13 = F_21 ( & V_22 ) ;
if ( ! V_13 )
return - 1 ;
for (; V_24 > 0 ; V_24 -- , V_14 += V_25 , V_23 ++ ) {
if ( F_11 ( V_14 , V_23 , V_26 ) )
return - 1 ;
}
return 0 ;
}
static void F_22 ( void )
{
T_8 V_27 , V_28 ;
V_27 = F_23 ( V_5 -> V_11 ) ;
V_28 = F_24 ( V_5 -> V_12 ) ;
if ( F_20 ( V_27 << V_29 , V_27 , V_28 ) )
F_25 ( L_10 ,
V_27 , V_28 ) ;
}
static void F_26 ( T_9 V_30 , unsigned long V_31 )
{
struct V_32 * V_33 ;
T_9 V_34 = V_30 + V_31 ;
if ( V_5 -> V_35 >= V_36 )
F_25 ( L_11 ) ;
if ( V_30 && V_31 ) {
V_33 = & V_5 -> V_37 [ V_5 -> V_35 ++ ] ;
V_33 -> V_30 = F_27 ( V_30 , V_25 ) ;
V_33 -> V_31 = F_28 ( V_34 , V_25 ) - V_33 -> V_30 ;
}
}
static int F_29 ( void )
{
int V_38 ;
V_5 -> V_35 = 0 ;
for ( V_38 = 0 ; V_38 < V_39 -> V_40 ; V_38 ++ ) {
if ( ( V_39 -> V_41 [ V_38 ] . type != V_42 )
&& ( V_39 -> V_41 [ V_38 ] . type != V_43 ) )
continue;
F_26 ( V_39 -> V_41 [ V_38 ] . V_44 , V_39 -> V_41 [ V_38 ] . V_31 ) ;
}
V_5 -> V_45 . V_46 =
V_47 -> V_48 ;
return 0 ;
}
static int F_29 ( void )
{
F_30 () ;
return - 1 ;
}
void F_31 ( T_8 V_49 )
{
void (* F_32)( void );
if ( ! F_33 () )
return;
if ( ! V_13 )
return;
if ( V_49 == V_50 )
if ( F_29 () )
return;
V_5 -> V_49 = V_49 ;
F_8 () ;
F_32 = ( void ( * ) ( void ) ) ( unsigned long ) V_5 -> V_10 ;
F_32 () ;
while ( 1 )
F_34 () ;
}
static void F_35 ( const struct V_51 * V_52 )
{
#define F_36 ( T_10 , T_11 ) \
tbg.space_id = g.space_id; \
tbg.bit_width = g.bit_width; \
tbg.bit_offset = g.bit_offset; \
tbg.access_width = g.access_width; \
tbg.address = g.address;
F_36 ( V_5 -> V_45 . V_53 , V_52 -> V_54 ) ;
F_36 ( V_5 -> V_45 . V_55 , V_52 -> V_56 ) ;
F_36 ( V_5 -> V_45 . V_57 , V_52 -> V_58 ) ;
F_36 ( V_5 -> V_45 . V_59 , V_52 -> V_60 ) ;
V_5 -> V_45 . V_61 = V_52 -> V_62 +
F_37 ( struct V_63 , V_64 ) ;
}
static int F_38 ( T_12 V_65 , T_8 V_66 , T_8 V_67 )
{
static T_8 V_68 [ V_69 ] = {
- 1 , - 1 , - 1 ,
V_50 ,
V_70 ,
V_71 } ;
if ( ! F_33 () )
return 0 ;
F_35 ( & V_72 ) ;
V_5 -> V_45 . V_73 = V_66 ;
V_5 -> V_45 . V_74 = V_67 ;
V_5 -> V_45 . V_75 = 32 ;
if ( V_65 >= V_69 ||
V_68 [ V_65 ] == - 1 ) {
F_3 ( L_12 , V_65 ) ;
return - 1 ;
}
F_31 ( V_68 [ V_65 ] ) ;
return 0 ;
}
static int F_39 ( T_12 V_65 , T_8 V_76 , T_8 V_77 )
{
if ( ! F_33 () )
return 0 ;
F_3 ( L_13 ) ;
return - V_78 ;
}
static int F_40 ( int V_79 )
{
unsigned long V_80 ;
V_80 = V_81 * V_82 ;
while ( F_41 ( ( V_83 * ) & V_5 -> V_84 ) != V_79 &&
V_80 ) {
F_42 ( 1 ) ;
V_80 -- ;
}
if ( V_80 )
F_3 ( L_14 ) ;
return ! ( F_41 ( ( V_83 * ) & V_5 -> V_84 ) == V_79 ) ;
}
static int F_43 ( unsigned int V_85 )
{
F_44 ( & V_86 ) ;
if ( F_45 () == 1 ) {
if ( F_40 ( F_41 ( & V_86 ) ) )
return - V_87 ;
}
return 0 ;
}
static T_13 F_46 ( struct V_88 * V_88 , char T_14 * V_89 , T_15 V_90 , T_16 * V_91 )
{
void T_17 * V_92 ;
T_12 V_93 [ 16 ] ;
T_8 V_94 ;
void * V_95 ;
int V_96 = - V_97 ;
V_92 = F_47 ( V_98 , V_99 ) ;
if ( ! V_92 )
return V_96 ;
F_48 ( V_93 , V_92 , sizeof( V_93 ) ) ;
if ( memcmp ( & V_100 , V_93 , sizeof( V_93 ) ) )
goto V_101;
V_94 = F_49 ( V_92 + V_102 ) ;
if ( * V_91 >= V_94 ) {
V_96 = 0 ;
goto V_101;
}
if ( * V_91 + V_90 > V_94 )
V_90 = V_94 - * V_91 ;
V_95 = F_50 ( V_90 , V_103 ) ;
if ( ! V_95 ) {
V_96 = - V_104 ;
goto V_101;
}
F_48 ( V_95 , V_92 + V_105 + * V_91 , V_90 ) ;
if ( F_51 ( V_89 , V_95 , V_90 ) )
goto V_106;
* V_91 += V_90 ;
V_96 = V_90 ;
V_106:
F_52 ( V_95 ) ;
V_101:
F_53 ( V_92 ) ;
return V_96 ;
}
static T_1 int F_54 ( void )
{
if ( ! F_33 () )
return 0 ;
F_22 () ;
F_55 ( & V_86 , 0 ) ;
F_56 ( V_107 , L_15 , NULL ,
F_43 ) ;
#ifdef F_57
F_58 ( L_16 , V_108 ,
V_109 , NULL , & V_110 ) ;
#endif
F_59 ( & F_38 ) ;
F_60 ( & F_39 ) ;
return 0 ;
}
struct V_111 * F_61 ( struct V_111 * V_112 )
{
void * V_113 , * V_114 , * V_115 ;
if ( ! F_33 () )
return V_112 ;
V_115 = F_62 ( V_116 , V_117 *
V_25 ) ;
if ( ! V_115 )
return NULL ;
V_113 = F_62 ( * ( V_118 * ) ( V_115 + V_119 ) ,
* ( V_118 * ) ( V_115 + V_120 ) ) ;
F_53 ( V_115 ) ;
if ( ! V_113 )
return NULL ;
V_114 = V_113 + * ( V_118 * ) V_113 ;
V_114 += * ( V_118 * ) V_114 ;
V_114 += * ( V_118 * ) V_114 ;
V_114 += sizeof( V_118 ) ;
V_112 = (struct V_111 * ) ( V_114 +
( (struct V_121 * ) V_114 ) -> V_122 -
sizeof( V_118 ) ) ;
return V_112 ;
}
int F_63 ( void )
{
if ( ! F_33 () )
return 0 ;
if ( V_123 )
return 1 ;
if ( V_124 || V_125 || V_126 )
F_3 ( L_17 ) ;
V_126 = 0 ;
#ifdef F_64
V_125 = 0 ;
#endif
V_124 = 0 ;
return 1 ;
}
