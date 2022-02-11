void
F_1 ( T_1 * V_1 )
{
int V_2 ;
T_2 * V_3 ;
#if V_4 >= F_2 ( 2 , 6 , 37 )
F_3 ( & V_1 -> V_5 , 1 ) ;
#else
F_4 ( & V_1 -> V_5 ) ;
#endif
V_1 -> V_6 = NULL ;
V_3 = V_1 -> V_3 ;
for ( V_2 = 0 ; V_2 < V_7 ; V_2 ++ ) {
memset ( & V_3 [ V_2 ] , 0 , sizeof( T_2 ) ) ;
V_3 [ V_2 ] . V_8 = V_2 ;
V_3 [ V_2 ] . V_9 = V_10 + ( V_2 << V_11 ) ;
V_3 [ V_2 ] . V_12 = - 1 ;
V_3 [ V_2 ] . V_13 = NULL ;
F_5 ( & V_3 [ V_2 ] . V_14 ) ;
F_6 ( & V_3 [ V_2 ] . V_15 ) ;
F_3 ( & V_3 [ V_2 ] . V_16 , 1 ) ;
V_3 [ V_2 ] . V_17 = 0 ;
V_3 [ V_2 ] . V_18 = 0 ;
V_3 [ V_2 ] . V_19 = 0 ;
V_3 [ V_2 ] . V_20 . V_21 = 0 ;
}
}
T_2 *
F_7 ( T_1 * V_1 , unsigned int V_22 ,
T_3 V_23 )
{
unsigned char V_2 , V_24 ;
T_2 * V_3 ;
V_3 = V_1 -> V_3 ;
for ( V_2 = 0 ; V_2 < V_7 ; V_2 ++ ) {
if ( V_3 [ V_2 ] . V_25 == 0 ) {
V_3 [ V_2 ] . V_12 = V_1 -> V_12 ;
V_3 [ V_2 ] . V_25 = 1 ;
V_3 [ V_2 ] . V_22 = V_22 ;
V_3 [ V_2 ] . V_26 = F_8 ( sizeof( V_27 ) , V_28 ) ;
if ( V_3 [ V_2 ] . V_26 == NULL ) {
F_9 ( V_1 , L_1 ) ;
return NULL ;
}
for ( V_24 = 0 ; V_24 < V_29 ; V_24 ++ ) {
V_3 [ V_2 ] . V_30 [ V_24 ] = F_8 ( sizeof( V_31 ) , V_28 ) ;
if ( V_3 [ V_2 ] . V_30 [ V_24 ] == NULL ) {
for (; V_24 > 0 ; V_24 -- ) {
F_10 ( V_3 [ V_2 ] . V_30 [ V_24 - 1 ] ) ;
}
F_10 ( V_3 [ V_2 ] . V_26 ) ;
F_9 ( V_1 , L_2 ) ;
return NULL ;
}
}
V_3 [ V_2 ] . V_13 = V_23 ;
F_11 ( V_1 , V_32 , L_3 ,
V_2 , & V_3 [ V_2 ] , V_22 ) ;
return & V_3 [ V_2 ] ;
}
}
return NULL ;
}
int
F_12 ( T_2 * V_33 )
{
struct V_34 * V_35 , * V_36 ;
T_4 * V_37 ;
T_1 * V_1 = F_13 ( V_33 -> V_12 ) ;
int V_24 ;
V_33 -> V_12 = - 1 ;
V_33 -> V_13 = NULL ;
V_33 -> V_25 = 0 ;
F_11 ( V_1 , V_38 , L_4 , V_33 ) ;
F_10 ( V_33 -> V_26 ) ;
for ( V_24 = 0 ; V_24 < V_29 ; V_24 ++ ) {
F_10 ( V_33 -> V_30 [ V_24 ] ) ;
}
if ( V_33 -> V_20 . V_21 ) {
V_33 -> V_20 . V_21 = 0 ;
F_10 ( V_33 -> V_20 . V_39 ) ;
}
F_14 ( & V_33 -> V_16 ) ;
F_15 (pos, n, &ul_client->udi_log)
{
V_37 = F_16 ( V_35 , T_4 , V_40 ) ;
F_17 ( V_35 ) ;
F_10 ( V_37 ) ;
}
F_18 ( & V_33 -> V_16 ) ;
return 0 ;
}
void
F_19 ( void * V_41 ,
T_5 * V_42 , T_6 V_43 ,
const T_7 * V_44 ,
enum V_45 V_46 )
{
T_1 * V_1 = ( T_1 * ) V_41 ;
T_2 * V_47 ;
int V_48 ;
V_48 = ( V_46 == V_49 ) ? V_50 : V_51 ;
F_14 ( & V_1 -> V_5 ) ;
V_47 = V_1 -> V_6 ;
if ( V_47 != NULL ) {
V_47 -> V_13 ( V_47 , V_42 , V_43 ,
V_44 , V_48 ) ;
}
F_18 ( & V_1 -> V_5 ) ;
}
void
F_20 ( T_1 * V_1 , T_5 * V_52 , int V_53 )
{
#ifdef F_21
if ( V_1 -> V_54 == NULL )
{
return;
}
if ( ( V_55 == ( * V_52 ) ) && ( V_1 -> V_56 == V_57 ) ) {
F_22 ( V_1 , L_5 ) ;
} else {
F_23 ( V_1 -> V_58 , 0 , ( V_59 ) ( * V_52 ) ) ;
}
#ifdef F_24
F_25 () ;
#endif
#else
T_7 V_44 ;
if ( ! V_1 ) {
F_22 ( NULL , L_6 ) ;
return;
}
V_44 . V_60 [ 0 ] . V_61 = 0 ;
V_44 . V_60 [ 1 ] . V_61 = 0 ;
F_26 ( V_1 -> V_62 , V_52 , sizeof( T_5 ) ,
& V_44 , V_63 ) ;
#endif
}
static void
F_27 ( T_1 * V_1 , T_7 * V_44 )
{
int V_64 ;
if ( V_44 ) {
for ( V_64 = 0 ; V_64 < V_29 ; ++ V_64 ) {
if ( V_44 -> V_60 [ V_64 ] . V_61 != 0 ) {
F_28 ( V_1 , ( V_65 * ) ( & V_44 -> V_60 [ V_64 ] ) ) ;
}
}
}
}
static int
F_29 ( T_1 * V_1 , T_5 * signal ,
T_7 * V_44 )
{
unsigned int V_64 ;
if ( ( V_44 == NULL ) || ( V_66 == 0 ) ) {
return 0 ;
}
for ( V_64 = 0 ; V_64 < V_29 ; V_64 ++ )
{
struct V_67 * V_68 ;
T_6 V_69 = ( T_6 ) ( long ) ( V_44 -> V_60 [ V_64 ] . V_70 ) & ( V_66 - 1 ) ;
if ( V_69 )
{
V_68 = (struct V_67 * ) V_44 -> V_60 [ V_64 ] . V_71 ;
if ( V_68 == NULL ) {
F_30 ( V_1 ,
L_7 ,
V_69 ) ;
return - V_72 ;
}
if ( V_44 -> V_60 [ V_64 ] . V_61 == 0 ) {
F_30 ( V_1 ,
L_8 ,
V_69 ) ;
return V_73 ;
}
F_11 ( V_1 , V_38 ,
L_9 ,
V_44 -> V_60 [ V_64 ] . V_70 , V_69 , V_68 -> V_74 ) ;
if ( F_31 ( F_32 ( V_68 ) < V_69 ) )
{
struct V_67 * V_75 = V_68 ;
F_11 ( V_1 , V_38 , L_10 ) ;
V_68 = F_33 ( V_68 , V_69 ) ;
if ( V_68 == NULL ) {
F_9 ( V_1 ,
L_11 ) ;
return - V_76 ;
}
F_34 ( V_75 ) ;
V_44 -> V_60 [ V_64 ] . V_71 = ( const unsigned char * ) V_68 ;
V_44 -> V_60 [ V_64 ] . V_70 = ( const void * ) V_68 -> V_74 ;
}
F_35 ( V_68 , V_69 ) ;
}
signal [ V_77 + ( V_64 * V_78 ) + 1 ] = V_69 ;
}
return 0 ;
}
int
F_36 ( T_1 * V_1 , V_27 * V_79 ,
T_7 * V_44 )
{
T_5 V_80 [ V_81 ] ;
T_8 V_82 ;
T_9 V_83 ;
unsigned long V_84 ;
int V_85 ;
V_83 = F_37 ( V_79 , V_80 , & V_82 ) ;
if ( V_83 != V_73 ) {
F_9 ( V_1 , L_12 ) ;
return F_38 ( V_83 ) ;
}
V_85 = F_29 ( V_1 , V_80 , ( T_7 * ) V_44 ) ;
if ( V_85 ) {
return V_85 ;
}
F_39 ( & V_1 -> V_86 , V_84 ) ;
V_83 = F_40 ( V_1 -> V_87 , V_80 , V_82 , V_44 ) ;
if ( V_83 != V_73 ) {
F_41 ( & V_1 -> V_86 , V_84 ) ;
return F_38 ( V_83 ) ;
}
F_41 ( & V_1 -> V_86 , V_84 ) ;
return 0 ;
}
static void
F_42 ( T_1 * V_1 )
{
V_1 -> V_88 = 0 ;
#ifdef F_43
#ifdef F_44
V_1 -> V_89 . V_90 = 0 ;
V_1 -> V_89 . V_91 = V_92 ;
V_1 -> V_89 . V_93 = 0 ;
V_1 -> V_89 . V_94 = 0 ;
#endif
#endif
}
int
F_45 ( T_1 * V_1 , unsigned char * V_79 , int V_95 ,
T_7 * V_44 )
{
T_9 V_83 ;
unsigned long V_84 ;
int V_85 ;
V_85 = F_29 ( V_1 , ( T_5 * ) V_79 , V_44 ) ;
if ( V_85 ) {
return V_85 ;
}
F_39 ( & V_1 -> V_86 , V_84 ) ;
V_83 = F_40 ( V_1 -> V_87 , V_79 , V_95 , V_44 ) ;
if ( V_83 != V_73 ) {
F_27 ( V_1 , V_44 ) ;
F_41 ( & V_1 -> V_86 , V_84 ) ;
return F_38 ( V_83 ) ;
}
F_41 ( & V_1 -> V_86 , V_84 ) ;
if ( F_46 ( V_79 ) == V_96 ) {
F_42 ( V_1 ) ;
}
return 0 ;
}
