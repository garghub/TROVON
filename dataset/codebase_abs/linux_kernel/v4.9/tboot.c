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
V_17 = F_12 ( & V_21 , V_14 ) ;
V_18 = F_13 ( & V_21 , V_17 , V_14 ) ;
if ( ! V_18 )
return - 1 ;
V_19 = F_14 ( & V_21 , V_18 , V_14 ) ;
if ( ! V_19 )
return - 1 ;
V_20 = F_15 ( & V_21 , V_19 , V_14 ) ;
if ( ! V_20 )
return - 1 ;
F_16 ( & V_21 , V_14 , V_20 , F_17 ( V_15 , V_16 ) ) ;
F_18 ( V_20 ) ;
return 0 ;
}
static int F_19 ( unsigned long V_14 , unsigned long V_22 ,
unsigned long V_23 )
{
V_13 = F_20 ( & V_21 ) ;
if ( ! V_13 )
return - 1 ;
for (; V_23 > 0 ; V_23 -- , V_14 += V_24 , V_22 ++ ) {
if ( F_11 ( V_14 , V_22 , V_25 ) )
return - 1 ;
}
return 0 ;
}
static void F_21 ( void )
{
T_7 V_26 , V_27 ;
V_26 = F_22 ( V_5 -> V_11 ) ;
V_27 = F_23 ( V_5 -> V_12 ) ;
if ( F_19 ( V_26 << V_28 , V_26 , V_27 ) )
F_24 ( L_10 ,
V_26 , V_27 ) ;
}
static void F_25 ( T_8 V_29 , unsigned long V_30 )
{
struct V_31 * V_32 ;
T_8 V_33 = V_29 + V_30 ;
if ( V_5 -> V_34 >= V_35 )
F_24 ( L_11 ) ;
if ( V_29 && V_30 ) {
V_32 = & V_5 -> V_36 [ V_5 -> V_34 ++ ] ;
V_32 -> V_29 = F_26 ( V_29 , V_24 ) ;
V_32 -> V_30 = F_27 ( V_33 , V_24 ) - V_32 -> V_29 ;
}
}
static int F_28 ( void )
{
int V_37 ;
V_5 -> V_34 = 0 ;
for ( V_37 = 0 ; V_37 < V_38 -> V_39 ; V_37 ++ ) {
if ( ( V_38 -> V_40 [ V_37 ] . type != V_41 )
&& ( V_38 -> V_40 [ V_37 ] . type != V_42 ) )
continue;
F_25 ( V_38 -> V_40 [ V_37 ] . V_43 , V_38 -> V_40 [ V_37 ] . V_30 ) ;
}
V_5 -> V_44 . V_45 =
V_46 -> V_47 ;
return 0 ;
}
static int F_28 ( void )
{
F_29 () ;
return - 1 ;
}
void F_30 ( T_7 V_48 )
{
void (* F_31)( void );
if ( ! F_32 () )
return;
if ( ! V_13 )
return;
if ( V_48 == V_49 )
if ( F_28 () )
return;
V_5 -> V_48 = V_48 ;
F_8 () ;
F_31 = ( void ( * ) ( void ) ) ( unsigned long ) V_5 -> V_10 ;
F_31 () ;
while ( 1 )
F_33 () ;
}
static void F_34 ( const struct V_50 * V_51 )
{
#define F_35 ( T_9 , T_10 ) \
tbg.space_id = g.space_id; \
tbg.bit_width = g.bit_width; \
tbg.bit_offset = g.bit_offset; \
tbg.access_width = g.access_width; \
tbg.address = g.address;
F_35 ( V_5 -> V_44 . V_52 , V_51 -> V_53 ) ;
F_35 ( V_5 -> V_44 . V_54 , V_51 -> V_55 ) ;
F_35 ( V_5 -> V_44 . V_56 , V_51 -> V_57 ) ;
F_35 ( V_5 -> V_44 . V_58 , V_51 -> V_59 ) ;
V_5 -> V_44 . V_60 = V_51 -> V_61 +
F_36 ( struct V_62 , V_63 ) ;
}
static int F_37 ( T_11 V_64 , T_7 V_65 , T_7 V_66 )
{
static T_7 V_67 [ V_68 ] = {
- 1 , - 1 , - 1 ,
V_49 ,
V_69 ,
V_70 } ;
if ( ! F_32 () )
return 0 ;
F_34 ( & V_71 ) ;
V_5 -> V_44 . V_72 = V_65 ;
V_5 -> V_44 . V_73 = V_66 ;
V_5 -> V_44 . V_74 = 32 ;
if ( V_64 >= V_68 ||
V_67 [ V_64 ] == - 1 ) {
F_3 ( L_12 , V_64 ) ;
return - 1 ;
}
F_30 ( V_67 [ V_64 ] ) ;
return 0 ;
}
static int F_38 ( T_11 V_64 , T_7 V_75 , T_7 V_76 )
{
if ( ! F_32 () )
return 0 ;
F_3 ( L_13 ) ;
return - V_77 ;
}
static int F_39 ( int V_78 )
{
unsigned long V_79 ;
V_79 = V_80 * V_81 ;
while ( F_40 ( ( V_82 * ) & V_5 -> V_83 ) != V_78 &&
V_79 ) {
F_41 ( 1 ) ;
V_79 -- ;
}
if ( V_79 )
F_3 ( L_14 ) ;
return ! ( F_40 ( ( V_82 * ) & V_5 -> V_83 ) == V_78 ) ;
}
static int F_42 ( unsigned int V_84 )
{
F_43 ( & V_85 ) ;
if ( F_44 () == 1 ) {
if ( F_39 ( F_40 ( & V_85 ) ) )
return - V_86 ;
}
return 0 ;
}
static T_12 F_45 ( struct V_87 * V_87 , char T_13 * V_88 , T_14 V_89 , T_15 * V_90 )
{
void T_16 * V_91 ;
T_11 V_92 [ 16 ] ;
T_7 V_93 ;
void * V_94 ;
int V_95 = - V_96 ;
V_91 = F_46 ( V_97 , V_98 ) ;
if ( ! V_91 )
return V_95 ;
F_47 ( V_92 , V_91 , sizeof( V_92 ) ) ;
if ( memcmp ( & V_99 , V_92 , sizeof( V_92 ) ) )
goto V_100;
V_93 = F_48 ( V_91 + V_101 ) ;
if ( * V_90 >= V_93 ) {
V_95 = 0 ;
goto V_100;
}
if ( * V_90 + V_89 > V_93 )
V_89 = V_93 - * V_90 ;
V_94 = F_49 ( V_89 , V_102 ) ;
if ( ! V_94 ) {
V_95 = - V_103 ;
goto V_100;
}
F_47 ( V_94 , V_91 + V_104 + * V_90 , V_89 ) ;
if ( F_50 ( V_88 , V_94 , V_89 ) )
goto V_105;
* V_90 += V_89 ;
V_95 = V_89 ;
V_105:
F_51 ( V_94 ) ;
V_100:
F_52 ( V_91 ) ;
return V_95 ;
}
static T_1 int F_53 ( void )
{
if ( ! F_32 () )
return 0 ;
F_21 () ;
F_54 ( & V_85 , 0 ) ;
F_55 ( V_106 , L_15 , NULL ,
F_42 ) ;
#ifdef F_56
F_57 ( L_16 , V_107 ,
V_108 , NULL , & V_109 ) ;
#endif
F_58 ( & F_37 ) ;
F_59 ( & F_38 ) ;
return 0 ;
}
struct V_110 * F_60 ( struct V_110 * V_111 )
{
void * V_112 , * V_113 , * V_114 ;
if ( ! F_32 () )
return V_111 ;
V_114 = F_61 ( V_115 , V_116 *
V_24 ) ;
if ( ! V_114 )
return NULL ;
V_112 = F_61 ( * ( V_117 * ) ( V_114 + V_118 ) ,
* ( V_117 * ) ( V_114 + V_119 ) ) ;
F_52 ( V_114 ) ;
if ( ! V_112 )
return NULL ;
V_113 = V_112 + * ( V_117 * ) V_112 ;
V_113 += * ( V_117 * ) V_113 ;
V_113 += * ( V_117 * ) V_113 ;
V_113 += sizeof( V_117 ) ;
V_111 = (struct V_110 * ) ( V_113 +
( (struct V_120 * ) V_113 ) -> V_121 -
sizeof( V_117 ) ) ;
return V_111 ;
}
int F_62 ( void )
{
if ( ! F_32 () )
return 0 ;
if ( V_122 || V_123 || V_124 )
F_3 ( L_17 ) ;
V_124 = 0 ;
#ifdef F_63
V_123 = 0 ;
#endif
V_122 = 0 ;
return 1 ;
}
