void
F_1 ( T_1 * V_1 )
{
int V_2 ;
T_2 * V_3 ;
F_2 ( & V_1 -> V_4 , 1 ) ;
V_1 -> V_5 = NULL ;
V_3 = V_1 -> V_3 ;
for ( V_2 = 0 ; V_2 < V_6 ; V_2 ++ ) {
memset ( & V_3 [ V_2 ] , 0 , sizeof( T_2 ) ) ;
V_3 [ V_2 ] . V_7 = V_2 ;
V_3 [ V_2 ] . V_8 = V_9 + ( V_2 << V_10 ) ;
V_3 [ V_2 ] . V_11 = - 1 ;
V_3 [ V_2 ] . V_12 = NULL ;
F_3 ( & V_3 [ V_2 ] . V_13 ) ;
F_4 ( & V_3 [ V_2 ] . V_14 ) ;
F_2 ( & V_3 [ V_2 ] . V_15 , 1 ) ;
V_3 [ V_2 ] . V_16 = 0 ;
V_3 [ V_2 ] . V_17 = 0 ;
V_3 [ V_2 ] . V_18 = 0 ;
V_3 [ V_2 ] . V_19 . V_20 = 0 ;
}
}
T_2 *
F_5 ( T_1 * V_1 , unsigned int V_21 ,
T_3 V_22 )
{
unsigned char V_2 , V_23 ;
T_2 * V_3 ;
V_3 = V_1 -> V_3 ;
for ( V_2 = 0 ; V_2 < V_6 ; V_2 ++ ) {
if ( V_3 [ V_2 ] . V_24 == 0 ) {
V_3 [ V_2 ] . V_11 = V_1 -> V_11 ;
V_3 [ V_2 ] . V_24 = 1 ;
V_3 [ V_2 ] . V_21 = V_21 ;
V_3 [ V_2 ] . V_25 = F_6 ( sizeof( V_26 ) , V_27 ) ;
if ( V_3 [ V_2 ] . V_25 == NULL ) {
F_7 ( V_1 , L_1 ) ;
return NULL ;
}
for ( V_23 = 0 ; V_23 < V_28 ; V_23 ++ ) {
V_3 [ V_2 ] . V_29 [ V_23 ] = F_6 ( sizeof( V_30 ) , V_27 ) ;
if ( V_3 [ V_2 ] . V_29 [ V_23 ] == NULL ) {
for (; V_23 > 0 ; V_23 -- ) {
F_8 ( V_3 [ V_2 ] . V_29 [ V_23 - 1 ] ) ;
}
F_8 ( V_3 [ V_2 ] . V_25 ) ;
F_7 ( V_1 , L_2 ) ;
return NULL ;
}
}
V_3 [ V_2 ] . V_12 = V_22 ;
F_9 ( V_1 , V_31 , L_3 ,
V_2 , & V_3 [ V_2 ] , V_21 ) ;
return & V_3 [ V_2 ] ;
}
}
return NULL ;
}
int
F_10 ( T_2 * V_32 )
{
struct V_33 * V_34 , * V_35 ;
T_4 * V_36 ;
T_1 * V_1 = F_11 ( V_32 -> V_11 ) ;
int V_23 ;
V_32 -> V_11 = - 1 ;
V_32 -> V_12 = NULL ;
V_32 -> V_24 = 0 ;
F_9 ( V_1 , V_37 , L_4 , V_32 ) ;
F_8 ( V_32 -> V_25 ) ;
for ( V_23 = 0 ; V_23 < V_28 ; V_23 ++ ) {
F_8 ( V_32 -> V_29 [ V_23 ] ) ;
}
if ( V_32 -> V_19 . V_20 ) {
V_32 -> V_19 . V_20 = 0 ;
F_8 ( V_32 -> V_19 . V_38 ) ;
}
F_12 ( & V_32 -> V_15 ) ;
F_13 (pos, n, &ul_client->udi_log)
{
V_36 = F_14 ( V_34 , T_4 , V_39 ) ;
F_15 ( V_34 ) ;
F_8 ( V_36 ) ;
}
F_16 ( & V_32 -> V_15 ) ;
return 0 ;
}
void
F_17 ( void * V_40 ,
T_5 * V_41 , T_6 V_42 ,
const T_7 * V_43 ,
enum V_44 V_45 )
{
T_1 * V_1 = ( T_1 * ) V_40 ;
T_2 * V_46 ;
int V_47 ;
V_47 = ( V_45 == V_48 ) ? V_49 : V_50 ;
F_12 ( & V_1 -> V_4 ) ;
V_46 = V_1 -> V_5 ;
if ( V_46 != NULL ) {
V_46 -> V_12 ( V_46 , V_41 , V_42 ,
V_43 , V_47 ) ;
}
F_16 ( & V_1 -> V_4 ) ;
}
void
F_18 ( T_1 * V_1 , T_5 * V_51 , int V_52 )
{
#ifdef F_19
if ( V_1 -> V_53 == NULL )
{
return;
}
if ( ( V_54 == ( * V_51 ) ) && ( V_1 -> V_55 == V_56 ) ) {
F_20 ( V_1 , L_5 ) ;
} else {
F_21 ( V_1 -> V_57 , 0 , ( V_58 ) ( * V_51 ) ) ;
}
#ifdef F_22
F_23 () ;
#endif
#else
T_7 V_43 ;
if ( ! V_1 ) {
F_20 ( NULL , L_6 ) ;
return;
}
V_43 . V_59 [ 0 ] . V_60 = 0 ;
V_43 . V_59 [ 1 ] . V_60 = 0 ;
F_24 ( V_1 -> V_61 , V_51 , sizeof( T_5 ) ,
& V_43 , V_62 ) ;
#endif
}
static void
F_25 ( T_1 * V_1 , T_7 * V_43 )
{
int V_63 ;
if ( V_43 ) {
for ( V_63 = 0 ; V_63 < V_28 ; ++ V_63 ) {
if ( V_43 -> V_59 [ V_63 ] . V_60 != 0 ) {
F_26 ( V_1 , ( V_64 * ) ( & V_43 -> V_59 [ V_63 ] ) ) ;
}
}
}
}
static int
F_27 ( T_1 * V_1 , T_5 * signal ,
T_7 * V_43 )
{
unsigned int V_63 ;
if ( ( V_43 == NULL ) || ( V_65 == 0 ) ) {
return 0 ;
}
for ( V_63 = 0 ; V_63 < V_28 ; V_63 ++ )
{
struct V_66 * V_67 ;
T_6 V_68 = ( T_6 ) ( long ) ( V_43 -> V_59 [ V_63 ] . V_69 ) & ( V_65 - 1 ) ;
if ( V_68 )
{
V_67 = (struct V_66 * ) V_43 -> V_59 [ V_63 ] . V_70 ;
if ( V_67 == NULL ) {
F_28 ( V_1 ,
L_7 ,
V_68 ) ;
return - V_71 ;
}
if ( V_43 -> V_59 [ V_63 ] . V_60 == 0 ) {
F_28 ( V_1 ,
L_8 ,
V_68 ) ;
return V_72 ;
}
F_9 ( V_1 , V_37 ,
L_9 ,
V_43 -> V_59 [ V_63 ] . V_69 , V_68 , V_67 -> V_73 ) ;
if ( F_29 ( F_30 ( V_67 ) < V_68 ) )
{
struct V_66 * V_74 = V_67 ;
F_9 ( V_1 , V_37 , L_10 ) ;
V_67 = F_31 ( V_67 , V_68 ) ;
if ( V_67 == NULL ) {
F_7 ( V_1 ,
L_11 ) ;
return - V_75 ;
}
F_32 ( V_74 ) ;
V_43 -> V_59 [ V_63 ] . V_70 = ( const unsigned char * ) V_67 ;
V_43 -> V_59 [ V_63 ] . V_69 = ( const void * ) V_67 -> V_73 ;
}
F_33 ( V_67 , V_68 ) ;
}
signal [ V_76 + ( V_63 * V_77 ) + 1 ] = V_68 ;
}
return 0 ;
}
int
F_34 ( T_1 * V_1 , V_26 * V_78 ,
T_7 * V_43 )
{
T_5 V_79 [ V_80 ] ;
T_8 V_81 ;
T_9 V_82 ;
unsigned long V_83 ;
int V_84 ;
V_82 = F_35 ( V_78 , V_79 , & V_81 ) ;
if ( V_82 != V_72 ) {
F_7 ( V_1 , L_12 ) ;
return F_36 ( V_82 ) ;
}
V_84 = F_27 ( V_1 , V_79 , ( T_7 * ) V_43 ) ;
if ( V_84 ) {
return V_84 ;
}
F_37 ( & V_1 -> V_85 , V_83 ) ;
V_82 = F_38 ( V_1 -> V_86 , V_79 , V_81 , V_43 ) ;
if ( V_82 != V_72 ) {
F_39 ( & V_1 -> V_85 , V_83 ) ;
return F_36 ( V_82 ) ;
}
F_39 ( & V_1 -> V_85 , V_83 ) ;
return 0 ;
}
static void
F_40 ( T_1 * V_1 )
{
V_1 -> V_87 = 0 ;
#ifdef F_41
#ifdef F_42
V_1 -> V_88 . V_89 = 0 ;
V_1 -> V_88 . V_90 = V_91 ;
V_1 -> V_88 . V_92 = 0 ;
V_1 -> V_88 . V_93 = 0 ;
#endif
#endif
}
int
F_43 ( T_1 * V_1 , unsigned char * V_78 , int V_94 ,
T_7 * V_43 )
{
T_9 V_82 ;
unsigned long V_83 ;
int V_84 ;
V_84 = F_27 ( V_1 , ( T_5 * ) V_78 , V_43 ) ;
if ( V_84 ) {
return V_84 ;
}
F_37 ( & V_1 -> V_85 , V_83 ) ;
V_82 = F_38 ( V_1 -> V_86 , V_78 , V_94 , V_43 ) ;
if ( V_82 != V_72 ) {
F_25 ( V_1 , V_43 ) ;
F_39 ( & V_1 -> V_85 , V_83 ) ;
return F_36 ( V_82 ) ;
}
F_39 ( & V_1 -> V_85 , V_83 ) ;
if ( F_44 ( V_78 ) == V_95 ) {
F_40 ( V_1 ) ;
}
return 0 ;
}
