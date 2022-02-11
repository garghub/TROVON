static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_3 == - V_7 )
return;
V_5 -> V_3 = V_3 ;
F_2 ( & V_5 -> V_8 ) ;
}
bool F_3 ( T_1 V_9 )
{
return ( V_9 == V_10 ) ;
}
static int F_4 ( struct V_11 * V_12 ,
const struct V_13 * V_14 ,
struct V_15 * V_16 )
{
T_2 V_17 ;
struct V_18 * V_2 = NULL ;
F_5 ( V_5 ) ;
struct V_19 * V_20 = V_12 -> V_21 ;
int V_3 = 0 ;
char V_22 [ V_23 ] ;
struct V_24 V_25 [ 1 ] ;
int V_26 = 4 << ( V_12 -> V_27 & V_28 ) ;
char * V_29 ;
if ( V_14 -> V_30 <= 0 || V_14 -> V_30 > V_12 -> V_31 )
return - V_32 ;
V_17 = ( V_14 -> V_30 < V_23 ) ?
V_23 : V_14 -> V_30 ;
V_17 = F_6 ( V_17 , V_26 ) ;
V_17 = ( V_17 > V_12 -> V_31 )
? V_12 -> V_31 : V_17 ;
V_2 = F_7 ( V_20 , V_33 ) ;
if ( ! V_2 ) {
F_8 (
V_34 L_1 , V_35 ) ;
return - V_36 ;
}
F_9 ( V_2 ,
V_37 | V_38 ,
F_1 , & V_5 ) ;
V_29 = F_10 ( V_12 -> V_39 ) ;
memcpy ( V_29 , V_14 -> V_40 , V_14 -> V_30 ) ;
if ( V_14 -> V_30 < V_17 )
memset ( V_29 + V_14 -> V_30 , 0 , V_17 - V_14 -> V_30 ) ;
memset ( V_22 , 0 , V_23 ) ;
F_11 ( V_25 , 1 ) ;
F_12 ( V_25 , V_12 -> V_39 , V_41 , 0 ) ;
F_13 ( V_2 , V_25 , V_25 , V_17 , V_22 ) ;
V_3 = F_14 ( V_2 ) ;
if ( V_3 == - V_7 || V_3 == - V_42 ) {
F_15 ( V_2 -> V_43 . V_6 != & V_5 ) ;
F_16 ( & V_5 . V_8 ) ;
V_3 = V_5 . V_3 ;
}
if ( V_3 >= 0 ) {
memcpy ( V_16 -> V_40 , V_29 , V_17 ) ;
V_3 = V_17 ;
}
F_17 ( V_12 -> V_39 ) ;
F_18 ( V_2 ) ;
if ( V_3 < 0 ) {
F_8 (
V_34 L_2 , V_35 , V_3 ) ;
}
V_16 -> V_30 = V_17 ;
return V_3 ;
}
static int F_19 ( struct V_11 * V_12 ,
const struct V_15 * V_14 ,
struct V_15 * V_16 )
{
struct V_15 V_44 [ 2 ] , V_45 [ 1 ] ;
struct V_18 * V_2 = NULL ;
F_5 ( V_5 ) ;
struct V_24 V_25 [ 1 ] ;
struct V_19 * V_20 = V_12 -> V_21 ;
int V_3 = 0 ;
char V_22 [ V_23 ] ;
char * V_29 ;
if ( V_14 -> V_30 <= 0 || V_14 -> V_30 > V_12 -> V_31 )
return - V_32 ;
V_44 [ 0 ] . V_40 = V_14 -> V_40 ;
V_44 [ 0 ] . V_30 = V_14 -> V_30 ;
V_45 [ 0 ] . V_40 = V_16 -> V_40 ;
V_2 = F_7 ( V_20 , V_33 ) ;
if ( ! V_2 ) {
F_8 (
V_34 L_1 , V_35 ) ;
return - V_36 ;
}
F_9 ( V_2 ,
V_37 | V_38 ,
F_1 , & V_5 ) ;
V_29 = F_10 ( V_12 -> V_39 ) ;
memcpy ( V_29 , V_14 -> V_40 , V_14 -> V_30 ) ;
memset ( V_22 , 0 , V_23 ) ;
F_11 ( V_25 , 1 ) ;
F_12 ( V_25 , V_12 -> V_39 , V_41 , 0 ) ;
F_13 ( V_2 , V_25 , V_25 , V_14 -> V_30 , V_22 ) ;
V_3 = F_20 ( V_2 ) ;
if ( V_3 == - V_7 || V_3 == - V_42 ) {
F_15 ( V_2 -> V_43 . V_6 != & V_5 ) ;
F_16 ( & V_5 . V_8 ) ;
V_3 = V_5 . V_3 ;
}
if ( V_3 >= 0 ) {
memcpy ( V_16 -> V_40 , V_29 , V_14 -> V_30 ) ;
V_3 = V_14 -> V_30 ;
}
F_17 ( V_12 -> V_39 ) ;
F_18 ( V_2 ) ;
if ( V_3 < 0 ) {
F_8 (
V_34 L_3 ,
V_35 , V_3 ) ;
return V_3 ;
}
V_16 -> V_30 = F_21 ( V_16 -> V_40 , V_14 -> V_30 ) ;
return V_16 -> V_30 ;
}
static int F_22 ( const char * V_46 , int V_30 , char * V_47 )
{
int V_48 = 0 , V_49 = 0 , V_50 = 0 ;
char * V_51 = V_47 ;
while ( V_48 < V_30 ) {
V_50 += ( ( ( unsigned char ) V_46 [ V_48 ] ) << V_49 ) ;
V_49 += 8 ;
do {
* V_51 ++ = V_52 [ V_50 & 0x3f ] ;
V_50 >>= 6 ;
V_49 -= 6 ;
} while ( V_49 >= 6 );
V_48 ++ ;
}
if ( V_49 )
* V_51 ++ = V_52 [ V_50 & 0x3f ] ;
return V_51 - V_47 ;
}
static int F_23 ( const char * V_46 , int V_30 , char * V_47 )
{
int V_48 = 0 , V_49 = 0 , V_50 = 0 ;
const char * V_53 ;
char * V_51 = V_47 ;
while ( V_48 < V_30 ) {
V_53 = strchr ( V_52 , V_46 [ V_48 ] ) ;
if ( V_53 == NULL || V_46 [ V_48 ] == 0 )
return - 2 ;
V_50 += ( V_53 - V_52 ) << V_49 ;
V_49 += 6 ;
if ( V_49 >= 8 ) {
* V_51 ++ = V_50 & 0xff ;
V_50 >>= 8 ;
V_49 -= 8 ;
}
V_48 ++ ;
}
if ( V_50 )
return - 1 ;
return V_51 - V_47 ;
}
void F_24 ( struct V_11 * V_12 )
{
if ( V_12 == NULL || F_25 ( V_12 ) )
return;
if ( V_12 -> V_21 && ! F_25 ( V_12 -> V_21 ) )
F_26 ( V_12 -> V_21 ) ;
if ( V_12 -> V_54 && ! F_25 ( V_12 -> V_54 ) )
F_27 ( V_12 -> V_54 ) ;
if ( V_12 -> V_39 && ! F_25 ( V_12 -> V_39 ) )
F_28 ( V_12 -> V_39 ) ;
F_29 ( V_12 ) ;
}
void F_30 ( struct V_11 * * V_12 )
{
if ( * V_12 == NULL || F_25 ( * V_12 ) )
return;
F_24 ( * V_12 ) ;
* V_12 = NULL ;
}
static struct V_11 * F_31 (
const struct V_55 * V_56 )
{
return NULL ;
}
struct V_11 * F_32 (
const struct V_55 * V_56 )
{
struct V_11 * V_12 ;
V_12 = F_33 ( sizeof( struct V_11 ) , V_33 ) ;
if ( V_12 == NULL )
return F_34 ( - V_36 ) ;
if ( V_56 -> V_9 == V_57 ) {
memset ( & V_12 -> V_56 , 0 , sizeof( V_12 -> V_56 ) ) ;
} else {
memcpy ( & V_12 -> V_56 , V_56 , sizeof( struct V_55 ) ) ;
}
V_12 -> V_58 = ( V_57 == V_56 -> V_9 )
? 0 : 1 ;
V_12 -> V_59 = 0 ;
V_12 -> V_21 = NULL ;
V_12 -> V_54 = NULL ;
V_12 -> V_39 = NULL ;
return V_12 ;
}
struct V_11 * F_35 (
struct V_60 * V_60 , T_2 V_61 )
{
struct V_11 * V_12 ;
struct V_62 * V_63 = F_36 ( V_60 ) ;
int V_3 ;
V_3 = F_37 ( V_60 ) ;
if ( V_3 == 0 )
return NULL ;
if ( ! F_38 ( V_60 ) )
F_39 ( V_60 ) ;
V_12 = F_31 ( & ( V_63 -> V_64 ) ) ;
if ( V_12 == NULL )
V_12 = F_32 ( & ( V_63 -> V_64 ) ) ;
if ( F_25 ( V_12 ) )
return V_12 ;
V_12 -> V_27 = V_63 -> V_65 ;
if ( V_12 -> V_58 ) {
if ( V_12 -> V_56 . V_9 != V_10 ) {
F_40 ( V_66
L_4 ,
V_12 -> V_56 . V_9 ) ;
return F_34 ( - V_67 ) ;
}
if ( V_12 -> V_21 == NULL ) {
V_12 -> V_21 = F_41 ( L_5 ,
0 , 0 ) ;
}
if ( F_25 ( V_12 -> V_21 ) ) {
V_3 = F_42 ( V_12 -> V_21 ) ;
F_43 (
V_68 L_6 ,
V_35 , V_3 ) ;
V_12 -> V_21 = NULL ;
F_30 ( & V_12 ) ;
return F_34 ( V_3 ) ;
}
if ( V_12 -> V_21 == NULL ) {
F_43 (
V_68 L_7 ,
V_35 ) ;
F_30 ( & V_12 ) ;
return F_34 ( - V_36 ) ;
}
if ( V_12 -> V_39 == NULL )
V_12 -> V_39 = F_44 ( V_33 ) ;
if ( F_25 ( V_12 -> V_39 ) ) {
V_3 = F_42 ( V_12 -> V_39 ) ;
F_43 (
V_68 L_8 ,
V_35 , V_3 ) ;
V_12 -> V_39 = NULL ;
F_30 ( & V_12 ) ;
return F_34 ( V_3 ) ;
}
if ( V_12 -> V_39 == NULL ) {
F_43 (
V_68 L_9 ,
V_35 ) ;
F_30 ( & V_12 ) ;
return F_34 ( - V_36 ) ;
}
V_12 -> V_31 = V_61 ;
F_45 ( V_12 -> V_21 , ~ 0 ) ;
F_46 ( F_47 ( V_12 -> V_21 ) ,
V_69 ) ;
if ( ! V_12 -> V_59 ) {
V_3 = F_48 ( V_12 -> V_21 ,
V_12 -> V_56 . V_70 , V_12 -> V_56 . V_71 ) ;
if ( V_3 ) {
F_30 ( & V_12 ) ;
return F_34 ( - V_32 ) ;
}
V_12 -> V_59 = 1 ;
} else {
F_49 () ;
}
}
if ( V_12 -> V_54 == NULL )
V_12 -> V_54 = F_50 ( L_10 , 0 , V_72 ) ;
if ( F_25 ( V_12 -> V_54 ) ) {
V_3 = F_42 ( V_12 -> V_54 ) ;
F_43 ( V_68 L_11 ,
V_35 , V_3 ) ;
V_12 -> V_54 = NULL ;
F_30 ( & V_12 ) ;
return F_34 ( V_3 ) ;
}
if ( V_12 -> V_54 == NULL ) {
F_43 ( V_68 L_12 ,
V_35 ) ;
F_30 ( & V_12 ) ;
return F_34 ( - V_36 ) ;
}
return V_12 ;
}
T_2 F_6 ( T_2 V_71 , T_2 V_73 )
{
return ( ( V_71 + V_73 - 1 ) / V_73 ) * V_73 ;
}
int F_51 ( struct V_11 * V_12 ,
T_2 V_74 )
{
T_2 V_17 ;
int V_26 = 4 << ( V_12 -> V_27 & V_28 ) ;
if ( V_12 == NULL )
return - V_32 ;
if ( ! ( V_12 -> V_58 ) )
return - V_75 ;
V_17 = ( V_74 < V_23 ) ?
V_23 : V_74 ;
V_17 = F_6 ( V_17 , V_26 ) ;
V_17 = ( V_17 > V_12 -> V_31 )
? V_12 -> V_31 : V_17 ;
return ( int ) V_17 ;
}
int F_52 ( struct V_11 * V_12 ,
T_2 V_76 , struct V_15 * V_77 )
{
unsigned int V_78 ;
int V_26 = 4 << ( V_12 -> V_27 & V_28 ) ;
if ( ! V_12 )
return - V_32 ;
if ( V_26 < V_23 )
V_26 = V_23 ;
V_78 = F_6 ( V_76 , V_26 ) ;
V_77 -> V_30 = V_78 ;
if ( V_78 < V_79 * 2 )
V_78 = V_79 * 2 ;
V_77 -> V_40 = F_33 ( V_78 + 1 , V_33 ) ;
if ( ! ( V_77 -> V_40 ) )
return - V_36 ;
return 0 ;
}
void F_53 ( struct V_15 * V_77 )
{
if ( ! V_77 )
return;
F_29 ( V_77 -> V_40 ) ;
V_77 -> V_40 = NULL ;
}
int F_54 ( struct V_11 * V_12 ,
struct V_80 * V_81 ,
const struct V_15 * V_14 ,
struct V_15 * V_16 )
{
char V_82 [ 24 ] ;
int V_83 ;
if ( V_12 == NULL )
return - V_32 ;
if ( V_14 -> V_30 < 3 ) {
if ( V_14 -> V_40 [ 0 ] == '.' && V_14 -> V_40 [ V_14 -> V_30 - 1 ] == '.' ) {
V_16 -> V_40 [ 0 ] = '.' ;
V_16 -> V_40 [ V_14 -> V_30 - 1 ] = '.' ;
V_16 -> V_30 = V_14 -> V_30 ;
return V_16 -> V_30 ;
}
}
if ( V_12 -> V_58 )
return F_19 ( V_12 , V_14 , V_16 ) ;
if ( V_14 -> V_30 <= V_79 ) {
V_83 = F_22 ( V_14 -> V_40 , V_14 -> V_30 , V_16 -> V_40 ) ;
V_16 -> V_30 = V_83 ;
return V_83 ;
}
if ( V_81 ) {
memcpy ( V_82 , & V_81 -> V_84 , 4 ) ;
memcpy ( V_82 + 4 , & V_81 -> V_85 , 4 ) ;
} else
memset ( V_82 , 0 , 8 ) ;
memcpy ( V_82 + 8 , V_14 -> V_40 + V_14 -> V_30 - 16 , 16 ) ;
V_16 -> V_40 [ 0 ] = '_' ;
V_83 = F_22 ( V_82 , 24 , V_16 -> V_40 + 1 ) ;
V_16 -> V_30 = V_83 + 1 ;
return V_83 + 1 ;
}
int F_55 ( struct V_11 * V_12 ,
struct V_80 * V_81 ,
const struct V_86 * V_87 ,
struct V_15 * V_16 )
{
struct V_15 V_14 = { . V_40 = ( unsigned char * ) V_87 -> V_40 ,
. V_30 = V_87 -> V_88 } ;
return F_54 ( V_12 , V_81 , & V_14 , V_16 ) ;
}
int F_56 ( struct V_11 * V_12 ,
const struct V_13 * V_14 ,
struct V_15 * V_16 )
{
int V_3 ;
if ( V_12 == NULL )
return - V_32 ;
if ( V_14 -> V_30 < 3 ) {
if ( V_14 -> V_40 [ 0 ] == '.' &&
V_14 -> V_40 [ V_14 -> V_30 - 1 ] == '.' ) {
V_16 -> V_40 [ 0 ] = '.' ;
V_16 -> V_40 [ V_14 -> V_30 - 1 ] = '.' ;
V_16 -> V_30 = V_14 -> V_30 ;
return V_16 -> V_30 ;
}
}
if ( V_12 -> V_58 ) {
V_3 = F_4 ( V_12 , V_14 , V_16 ) ;
return V_3 ;
}
return - V_75 ;
}
int F_57 ( struct V_11 * V_12 ,
const struct V_13 * V_14 ,
struct V_80 * V_81 )
{
struct V_15 V_89 ;
int V_83 = 0 ;
char V_82 [ V_79 + 1 ] ;
if ( ! V_12 ||
( ( V_14 -> V_40 [ 0 ] == '.' ) &&
( ( V_14 -> V_30 == 1 ) ||
( ( V_14 -> V_40 [ 1 ] == '.' ) && ( V_14 -> V_30 == 2 ) ) ) ) ) {
F_58 ( V_14 -> V_40 , V_14 -> V_30 , V_81 ) ;
return 0 ;
}
if ( ! V_12 -> V_58 && V_14 -> V_40 [ 0 ] == '_' ) {
if ( V_14 -> V_30 != 33 )
return - V_90 ;
V_83 = F_23 ( V_14 -> V_40 + 1 , V_14 -> V_30 , V_82 ) ;
if ( V_83 != 24 )
return - V_90 ;
memcpy ( & V_81 -> V_84 , V_82 , 4 ) ;
memcpy ( & V_81 -> V_85 , V_82 + 4 , 4 ) ;
return 0 ;
}
if ( ! V_12 -> V_58 && V_14 -> V_40 [ 0 ] != '_' ) {
if ( V_14 -> V_30 > 43 )
return - V_90 ;
V_83 = F_23 ( V_14 -> V_40 , V_14 -> V_30 , V_82 ) ;
F_58 ( V_82 , V_83 , V_81 ) ;
return 0 ;
}
V_83 = F_52 ( V_12 , V_14 -> V_30 , & V_89 ) ;
if ( V_83 < 0 )
return V_83 ;
V_83 = F_4 ( V_12 , V_14 , & V_89 ) ;
if ( V_83 >= 0 ) {
F_58 ( V_89 . V_40 , V_89 . V_30 , V_81 ) ;
V_83 = 0 ;
}
F_53 ( & V_89 ) ;
return V_83 ;
}
int F_59 ( struct V_11 * V_12 , struct V_15 * V_91 ,
int V_30 , const char * const V_40 ,
struct V_86 * V_87 )
{
int V_83 = - V_90 ;
int V_92 = ( * V_40 == '_' ) ;
if ( V_12 -> V_58 ) {
if ( V_91 -> V_40 == NULL ) {
struct V_13 V_93 ;
V_83 = F_52 ( V_12 , V_30 , V_91 ) ;
if ( V_83 < 0 )
goto V_94;
V_93 . V_40 = V_40 ;
V_93 . V_30 = V_30 ;
V_83 = F_4 ( V_12 , & V_93 , V_91 ) ;
if ( V_83 < 0 )
goto V_94;
}
} else {
if ( V_91 -> V_40 == NULL ) {
V_91 -> V_40 = F_33 ( 32 , V_95 ) ;
if ( V_91 -> V_40 == NULL )
return - V_36 ;
if ( ( V_92 && ( V_30 != 33 ) ) ||
( ! V_92 && ( V_30 > 43 ) ) )
goto V_94;
V_83 = F_23 ( V_40 + V_92 , V_30 - V_92 ,
V_91 -> V_40 ) ;
if ( V_83 < 0 ) {
V_83 = - V_90 ;
goto V_94;
}
V_91 -> V_30 = V_83 ;
}
if ( V_92 ) {
if ( V_87 -> V_88 < 16 )
return 0 ;
V_83 = memcmp ( V_87 -> V_40 + V_87 -> V_88 - 16 ,
V_91 -> V_40 + 8 , 16 ) ;
return ( V_83 == 0 ) ? 1 : 0 ;
}
}
if ( V_87 -> V_88 != V_91 -> V_30 )
return 0 ;
V_83 = memcmp ( V_87 -> V_40 , V_91 -> V_40 , V_91 -> V_30 ) ;
return ( V_83 == 0 ) ? 1 : 0 ;
V_94:
F_29 ( V_91 -> V_40 ) ;
V_91 -> V_40 = NULL ;
return V_83 ;
}
