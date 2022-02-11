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
V_20 = F_16 ( & V_21 , NULL , V_19 , V_14 ) ;
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
static int F_39 ( int V_75 )
{
unsigned long V_76 ;
V_76 = V_77 * V_78 ;
while ( F_40 ( ( V_79 * ) & V_5 -> V_80 ) != V_75 &&
V_76 ) {
F_41 ( 1 ) ;
V_76 -- ;
}
if ( V_76 )
F_3 ( L_14 ) ;
return ! ( F_40 ( ( V_79 * ) & V_5 -> V_80 ) == V_75 ) ;
}
static int F_42 ( struct V_81 * V_82 , unsigned long V_83 ,
void * V_84 )
{
switch ( V_83 ) {
case V_85 :
F_43 ( & V_86 ) ;
if ( F_44 () == 1 )
if ( F_39 ( F_40 ( & V_86 ) ) )
return V_87 ;
break;
}
return V_88 ;
}
static T_12 F_45 ( struct V_89 * V_89 , char T_13 * V_90 , T_14 V_91 , T_15 * V_92 )
{
void T_16 * V_93 ;
T_11 V_94 [ 16 ] ;
T_7 V_95 ;
void * V_96 ;
int V_97 = - V_98 ;
V_93 = F_46 ( V_99 , V_100 ) ;
if ( ! V_93 )
return V_97 ;
F_47 ( V_94 , V_93 , sizeof( V_94 ) ) ;
if ( memcmp ( & V_101 , V_94 , sizeof( V_94 ) ) )
goto V_102;
V_95 = F_48 ( V_93 + V_103 ) ;
if ( * V_92 >= V_95 ) {
V_97 = 0 ;
goto V_102;
}
if ( * V_92 + V_91 > V_95 )
V_91 = V_95 - * V_92 ;
V_96 = F_49 ( V_91 , V_104 ) ;
if ( ! V_96 ) {
V_97 = - V_105 ;
goto V_102;
}
F_47 ( V_96 , V_93 + V_106 + * V_92 , V_91 ) ;
if ( F_50 ( V_90 , V_96 , V_91 ) )
goto V_107;
* V_92 += V_91 ;
V_97 = V_91 ;
V_107:
F_51 ( V_96 ) ;
V_102:
F_52 ( V_93 ) ;
return V_97 ;
}
static T_1 int F_53 ( void )
{
if ( ! F_33 () )
return 0 ;
F_22 () ;
F_54 ( & V_86 , 0 ) ;
F_55 ( & V_108 ) ;
#ifdef F_56
F_57 ( L_15 , V_109 ,
V_110 , NULL , & V_111 ) ;
#endif
F_58 ( & F_38 ) ;
return 0 ;
}
struct V_112 * F_59 ( struct V_112 * V_113 )
{
void * V_114 , * V_115 , * V_116 ;
if ( ! F_33 () )
return V_113 ;
V_116 = F_60 ( V_117 , V_118 *
V_24 ) ;
if ( ! V_116 )
return NULL ;
V_114 = F_60 ( * ( V_119 * ) ( V_116 + V_120 ) ,
* ( V_119 * ) ( V_116 + V_121 ) ) ;
F_52 ( V_116 ) ;
if ( ! V_114 )
return NULL ;
V_115 = V_114 + * ( V_119 * ) V_114 ;
V_115 += * ( V_119 * ) V_115 ;
V_115 += * ( V_119 * ) V_115 ;
V_115 += sizeof( V_119 ) ;
V_113 = (struct V_112 * ) ( V_115 +
( (struct V_122 * ) V_115 ) -> V_123 -
sizeof( V_119 ) ) ;
return V_113 ;
}
int F_61 ( void )
{
if ( ! F_33 () )
return 0 ;
if ( V_124 || V_125 || V_126 )
F_3 ( L_16 ) ;
V_126 = 0 ;
#ifdef F_62
V_125 = 0 ;
#endif
V_124 = 0 ;
return 1 ;
}
