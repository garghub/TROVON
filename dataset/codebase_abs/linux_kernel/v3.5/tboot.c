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
static int T_12 F_42 ( struct V_81 * V_82 ,
unsigned long V_83 , void * V_84 )
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
static T_1 int F_45 ( void )
{
if ( ! F_33 () )
return 0 ;
F_22 () ;
F_46 ( & V_86 , 0 ) ;
F_47 ( & V_89 ) ;
F_48 ( & F_38 ) ;
return 0 ;
}
struct V_90 * F_49 ( struct V_90 * V_91 )
{
void * V_92 , * V_93 , * V_94 ;
if ( ! F_33 () )
return V_91 ;
V_94 = F_50 ( V_95 , V_96 *
V_24 ) ;
if ( ! V_94 )
return NULL ;
V_92 = F_50 ( * ( V_97 * ) ( V_94 + V_98 ) ,
* ( V_97 * ) ( V_94 + V_99 ) ) ;
F_51 ( V_94 ) ;
if ( ! V_92 )
return NULL ;
V_93 = V_92 + * ( V_97 * ) V_92 ;
V_93 += * ( V_97 * ) V_93 ;
V_93 += * ( V_97 * ) V_93 ;
V_93 += sizeof( V_97 ) ;
V_91 = (struct V_90 * ) ( V_93 +
( (struct V_100 * ) V_93 ) -> V_101 -
sizeof( V_97 ) ) ;
return V_91 ;
}
int F_52 ( void )
{
if ( ! F_33 () )
return 0 ;
if ( V_102 || V_103 || V_104 )
F_3 ( L_15 ) ;
V_104 = 0 ;
#ifdef F_53
V_103 = 0 ;
#endif
V_102 = 0 ;
return 1 ;
}
