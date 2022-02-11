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
V_5 -> V_44 . V_45 = V_46 ;
return 0 ;
}
static int F_29 ( void )
{
F_30 () ;
return - 1 ;
}
void F_31 ( T_7 V_47 )
{
void (* F_32)( void );
if ( ! F_33 () )
return;
if ( ! V_13 )
return;
if ( V_47 == V_48 )
if ( F_29 () )
return;
V_5 -> V_47 = V_47 ;
F_9 () ;
F_32 = ( void ( * ) ( void ) ) ( unsigned long ) V_5 -> V_10 ;
F_32 () ;
while ( 1 )
F_34 () ;
}
static void F_35 ( const struct V_49 * V_50 )
{
#define F_36 ( T_9 , T_10 ) \
tbg.space_id = g.space_id; \
tbg.bit_width = g.bit_width; \
tbg.bit_offset = g.bit_offset; \
tbg.access_width = g.access_width; \
tbg.address = g.address;
F_36 ( V_5 -> V_44 . V_51 , V_50 -> V_52 ) ;
F_36 ( V_5 -> V_44 . V_53 , V_50 -> V_54 ) ;
F_36 ( V_5 -> V_44 . V_55 , V_50 -> V_56 ) ;
F_36 ( V_5 -> V_44 . V_57 , V_50 -> V_58 ) ;
V_5 -> V_44 . V_59 = V_50 -> V_60 +
F_37 ( struct V_61 , V_62 ) ;
}
static int F_38 ( T_11 V_63 , T_7 V_64 , T_7 V_65 )
{
static T_7 V_66 [ V_67 ] = {
- 1 , - 1 , - 1 ,
V_48 ,
V_68 ,
V_69 } ;
if ( ! F_33 () )
return 0 ;
F_35 ( & V_70 ) ;
V_5 -> V_44 . V_71 = V_64 ;
V_5 -> V_44 . V_72 = V_65 ;
V_5 -> V_44 . V_73 = 32 ;
if ( V_63 >= V_67 ||
V_66 [ V_63 ] == - 1 ) {
F_3 ( L_13 , V_63 ) ;
return - 1 ;
}
F_31 ( V_66 [ V_63 ] ) ;
return 0 ;
}
static int F_39 ( int V_74 )
{
unsigned long V_75 ;
V_75 = V_76 * V_77 ;
while ( F_40 ( ( V_78 * ) & V_5 -> V_79 ) != V_74 &&
V_75 ) {
F_41 ( 1 ) ;
V_75 -- ;
}
if ( V_75 )
F_3 ( L_14 ) ;
return ! ( F_40 ( ( V_78 * ) & V_5 -> V_79 ) == V_74 ) ;
}
static int T_12 F_42 ( struct V_80 * V_81 ,
unsigned long V_82 , void * V_83 )
{
switch ( V_82 ) {
case V_84 :
F_43 ( & V_85 ) ;
if ( F_44 () == 1 )
if ( F_39 ( F_40 ( & V_85 ) ) )
return V_86 ;
break;
}
return V_87 ;
}
static T_1 int F_45 ( void )
{
if ( ! F_33 () )
return 0 ;
F_22 () ;
F_46 ( & V_85 , 0 ) ;
F_47 ( & V_88 ) ;
F_48 ( & F_38 ) ;
return 0 ;
}
struct V_89 * F_49 ( struct V_89 * V_90 )
{
void * V_91 , * V_92 , * V_93 ;
if ( ! F_33 () )
return V_90 ;
V_93 = F_50 ( V_94 , V_95 *
V_24 ) ;
if ( ! V_93 )
return NULL ;
V_91 = F_50 ( * ( V_96 * ) ( V_93 + V_97 ) ,
* ( V_96 * ) ( V_93 + V_98 ) ) ;
F_51 ( V_93 ) ;
if ( ! V_91 )
return NULL ;
V_92 = V_91 + * ( V_96 * ) V_91 ;
V_92 += * ( V_96 * ) V_92 ;
V_92 += * ( V_96 * ) V_92 ;
V_92 += sizeof( V_96 ) ;
V_90 = (struct V_89 * ) ( V_92 +
( (struct V_99 * ) V_92 ) -> V_100 -
sizeof( V_96 ) ) ;
return V_90 ;
}
int F_52 ( void )
{
if ( ! F_33 () )
return 0 ;
if ( V_101 || V_102 || V_103 )
F_3 ( L_15 ) ;
V_103 = 0 ;
#ifdef F_53
V_102 = 0 ;
#endif
V_101 = 0 ;
return 1 ;
}
