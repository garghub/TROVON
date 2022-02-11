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
static unsigned F_4 ( struct V_11 * V_11 )
{
return F_5 ( V_11 -> V_12 ) ? V_11 -> V_13 -> V_14 :
V_15 ;
}
static int F_6 ( struct V_11 * V_11 ,
const struct V_16 * V_17 ,
struct V_18 * V_19 )
{
T_2 V_20 ;
struct V_21 * V_2 = NULL ;
F_7 ( V_5 ) ;
struct V_22 * V_23 = F_8 ( V_11 ) -> V_24 ;
struct V_25 * V_26 = V_23 -> V_27 ;
int V_3 = 0 ;
char V_28 [ V_29 ] ;
struct V_30 V_31 , V_32 ;
int V_33 = 4 << ( V_23 -> V_34 & V_35 ) ;
char * V_36 , V_37 [ 32 ] , * V_38 = NULL ;
unsigned V_39 = F_4 ( V_11 ) ;
if ( V_17 -> V_40 <= 0 || V_17 -> V_40 > V_39 )
return - V_41 ;
V_20 = ( V_17 -> V_40 < V_29 ) ?
V_29 : V_17 -> V_40 ;
V_20 = F_9 ( V_20 , V_33 ) ;
V_20 = ( V_20 > V_39 )
? V_39 : V_20 ;
if ( V_20 <= sizeof( V_37 ) ) {
V_36 = V_37 ;
} else {
V_38 = F_10 ( V_20 , V_42 ) ;
if ( ! V_38 )
return - V_43 ;
V_36 = V_38 ;
}
V_2 = F_11 ( V_26 , V_42 ) ;
if ( ! V_2 ) {
F_12 (
V_44 L_1 , V_45 ) ;
F_13 ( V_38 ) ;
return - V_43 ;
}
F_14 ( V_2 ,
V_46 | V_47 ,
F_1 , & V_5 ) ;
memcpy ( V_36 , V_17 -> V_48 , V_17 -> V_40 ) ;
if ( V_17 -> V_40 < V_20 )
memset ( V_36 + V_17 -> V_40 , 0 , V_20 - V_17 -> V_40 ) ;
memset ( V_28 , 0 , V_29 ) ;
F_15 ( & V_31 , V_36 , V_20 ) ;
F_15 ( & V_32 , V_19 -> V_48 , V_20 ) ;
F_16 ( V_2 , & V_31 , & V_32 , V_20 , V_28 ) ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 == - V_7 || V_3 == - V_49 ) {
F_18 ( V_2 -> V_50 . V_6 != & V_5 ) ;
F_19 ( & V_5 . V_8 ) ;
V_3 = V_5 . V_3 ;
}
F_13 ( V_38 ) ;
F_20 ( V_2 ) ;
if ( V_3 < 0 ) {
F_12 (
V_44 L_2 , V_45 , V_3 ) ;
}
V_19 -> V_40 = V_20 ;
return V_3 ;
}
static int F_21 ( struct V_11 * V_11 ,
const struct V_18 * V_17 ,
struct V_18 * V_19 )
{
struct V_18 V_51 [ 2 ] , V_52 [ 1 ] ;
struct V_21 * V_2 = NULL ;
F_7 ( V_5 ) ;
struct V_30 V_31 , V_32 ;
struct V_22 * V_23 = F_8 ( V_11 ) -> V_24 ;
struct V_25 * V_26 = V_23 -> V_27 ;
int V_3 = 0 ;
char V_28 [ V_29 ] ;
unsigned V_39 = F_4 ( V_11 ) ;
if ( V_17 -> V_40 <= 0 || V_17 -> V_40 > V_39 )
return - V_41 ;
V_51 [ 0 ] . V_48 = V_17 -> V_48 ;
V_51 [ 0 ] . V_40 = V_17 -> V_40 ;
V_52 [ 0 ] . V_48 = V_19 -> V_48 ;
V_2 = F_11 ( V_26 , V_42 ) ;
if ( ! V_2 ) {
F_12 (
V_44 L_1 , V_45 ) ;
return - V_43 ;
}
F_14 ( V_2 ,
V_46 | V_47 ,
F_1 , & V_5 ) ;
memset ( V_28 , 0 , V_29 ) ;
F_15 ( & V_31 , V_17 -> V_48 , V_17 -> V_40 ) ;
F_15 ( & V_32 , V_19 -> V_48 , V_19 -> V_40 ) ;
F_16 ( V_2 , & V_31 , & V_32 , V_17 -> V_40 , V_28 ) ;
V_3 = F_22 ( V_2 ) ;
if ( V_3 == - V_7 || V_3 == - V_49 ) {
F_18 ( V_2 -> V_50 . V_6 != & V_5 ) ;
F_19 ( & V_5 . V_8 ) ;
V_3 = V_5 . V_3 ;
}
F_20 ( V_2 ) ;
if ( V_3 < 0 ) {
F_12 (
V_44 L_3 ,
V_45 , V_3 ) ;
return V_3 ;
}
V_19 -> V_40 = F_23 ( V_19 -> V_48 , V_17 -> V_40 ) ;
return V_19 -> V_40 ;
}
static int F_24 ( const char * V_53 , int V_40 , char * V_54 )
{
int V_55 = 0 , V_56 = 0 , V_57 = 0 ;
char * V_58 = V_54 ;
while ( V_55 < V_40 ) {
V_57 += ( ( ( unsigned char ) V_53 [ V_55 ] ) << V_56 ) ;
V_56 += 8 ;
do {
* V_58 ++ = V_59 [ V_57 & 0x3f ] ;
V_57 >>= 6 ;
V_56 -= 6 ;
} while ( V_56 >= 6 );
V_55 ++ ;
}
if ( V_56 )
* V_58 ++ = V_59 [ V_57 & 0x3f ] ;
return V_58 - V_54 ;
}
static int F_25 ( const char * V_53 , int V_40 , char * V_54 )
{
int V_55 = 0 , V_56 = 0 , V_57 = 0 ;
const char * V_60 ;
char * V_58 = V_54 ;
while ( V_55 < V_40 ) {
V_60 = strchr ( V_59 , V_53 [ V_55 ] ) ;
if ( V_60 == NULL || V_53 [ V_55 ] == 0 )
return - 2 ;
V_57 += ( V_60 - V_59 ) << V_56 ;
V_56 += 6 ;
if ( V_56 >= 8 ) {
* V_58 ++ = V_57 & 0xff ;
V_57 >>= 8 ;
V_56 -= 8 ;
}
V_55 ++ ;
}
if ( V_57 )
return - 1 ;
return V_58 - V_54 ;
}
T_2 F_9 ( T_2 V_61 , T_2 V_62 )
{
return ( ( V_61 + V_62 - 1 ) / V_62 ) * V_62 ;
}
unsigned F_26 ( struct V_11 * V_11 , T_2 V_63 )
{
struct V_22 * V_23 = F_8 ( V_11 ) -> V_24 ;
int V_33 = 32 ;
if ( V_23 )
V_33 = 4 << ( V_23 -> V_34 & V_35 ) ;
if ( V_63 < V_29 )
V_63 = V_29 ;
return F_9 ( V_63 , V_33 ) ;
}
int F_27 ( struct V_11 * V_11 ,
T_2 V_63 , struct V_18 * V_64 )
{
unsigned int V_65 = F_26 ( V_11 , V_63 ) ;
V_64 -> V_40 = V_65 ;
if ( V_65 < V_66 * 2 )
V_65 = V_66 * 2 ;
V_64 -> V_48 = F_10 ( V_65 + 1 , V_42 ) ;
if ( ! ( V_64 -> V_48 ) )
return - V_43 ;
return 0 ;
}
void F_28 ( struct V_18 * V_64 )
{
if ( ! V_64 )
return;
F_13 ( V_64 -> V_48 ) ;
V_64 -> V_48 = NULL ;
}
int F_29 ( struct V_11 * V_11 ,
struct V_67 * V_68 ,
const struct V_18 * V_17 ,
struct V_18 * V_19 )
{
char V_37 [ 24 ] ;
int V_69 ;
if ( V_17 -> V_40 < 3 ) {
if ( V_17 -> V_48 [ 0 ] == '.' && V_17 -> V_48 [ V_17 -> V_40 - 1 ] == '.' ) {
V_19 -> V_48 [ 0 ] = '.' ;
V_19 -> V_48 [ V_17 -> V_40 - 1 ] = '.' ;
V_19 -> V_40 = V_17 -> V_40 ;
return V_19 -> V_40 ;
}
}
if ( F_8 ( V_11 ) -> V_24 )
return F_21 ( V_11 , V_17 , V_19 ) ;
if ( V_17 -> V_40 <= V_66 ) {
V_69 = F_24 ( V_17 -> V_48 , V_17 -> V_40 , V_19 -> V_48 ) ;
V_19 -> V_40 = V_69 ;
return V_69 ;
}
if ( V_68 ) {
memcpy ( V_37 , & V_68 -> V_70 , 4 ) ;
memcpy ( V_37 + 4 , & V_68 -> V_71 , 4 ) ;
} else
memset ( V_37 , 0 , 8 ) ;
memcpy ( V_37 + 8 , V_17 -> V_48 + V_17 -> V_40 - 16 , 16 ) ;
V_19 -> V_48 [ 0 ] = '_' ;
V_69 = F_24 ( V_37 , 24 , V_19 -> V_48 + 1 ) ;
V_19 -> V_40 = V_69 + 1 ;
return V_69 + 1 ;
}
int F_30 ( struct V_11 * V_11 ,
struct V_67 * V_68 ,
const struct V_72 * V_73 ,
struct V_18 * V_19 )
{
struct V_18 V_17 = { . V_48 = ( unsigned char * ) V_73 -> V_48 ,
. V_40 = V_73 -> V_74 } ;
return F_29 ( V_11 , V_68 , & V_17 , V_19 ) ;
}
int F_31 ( struct V_11 * V_11 ,
const struct V_16 * V_17 ,
struct V_18 * V_19 )
{
int V_3 ;
struct V_22 * V_23 = F_8 ( V_11 ) -> V_24 ;
if ( V_17 -> V_40 < 3 ) {
if ( V_17 -> V_48 [ 0 ] == '.' &&
V_17 -> V_48 [ V_17 -> V_40 - 1 ] == '.' ) {
V_19 -> V_48 [ 0 ] = '.' ;
V_19 -> V_48 [ V_17 -> V_40 - 1 ] = '.' ;
V_19 -> V_40 = V_17 -> V_40 ;
return V_19 -> V_40 ;
}
}
if ( V_23 ) {
V_3 = F_6 ( V_11 , V_17 , V_19 ) ;
return V_3 ;
}
return - V_75 ;
}
int F_32 ( struct V_11 * V_76 , const struct V_16 * V_17 ,
int V_77 , struct V_78 * V_79 )
{
struct V_22 * V_23 ;
int V_69 = 0 , V_80 = 0 ;
memset ( V_79 , 0 , sizeof( struct V_78 ) ) ;
V_79 -> V_81 = V_17 ;
if ( ! F_33 ( V_76 ) ||
( ( V_17 -> V_48 [ 0 ] == '.' ) &&
( ( V_17 -> V_40 == 1 ) ||
( ( V_17 -> V_48 [ 1 ] == '.' ) && ( V_17 -> V_40 == 2 ) ) ) ) ) {
V_79 -> V_82 . V_48 = ( unsigned char * ) V_17 -> V_48 ;
V_79 -> V_82 . V_40 = V_17 -> V_40 ;
return 0 ;
}
V_69 = F_34 ( V_76 ) ;
if ( V_69 )
return V_69 ;
V_23 = F_8 ( V_76 ) -> V_24 ;
if ( V_23 ) {
V_69 = F_27 ( V_76 , V_17 -> V_40 ,
& V_79 -> V_83 ) ;
if ( V_69 < 0 )
return V_69 ;
V_69 = F_6 ( V_76 , V_17 , & V_79 -> V_83 ) ;
if ( V_69 < 0 )
goto V_84;
V_79 -> V_82 . V_48 = V_79 -> V_83 . V_48 ;
V_79 -> V_82 . V_40 = V_79 -> V_83 . V_40 ;
return 0 ;
}
if ( ! V_77 )
return - V_75 ;
if ( V_17 -> V_48 [ 0 ] == '_' )
V_80 = 1 ;
if ( ( V_80 && ( V_17 -> V_40 != 33 ) ) ||
( ! V_80 && ( V_17 -> V_40 > 43 ) ) )
return - V_85 ;
V_79 -> V_83 . V_48 = F_10 ( 32 , V_86 ) ;
if ( V_79 -> V_83 . V_48 == NULL )
return - V_43 ;
V_69 = F_25 ( V_17 -> V_48 + V_80 , V_17 -> V_40 - V_80 ,
V_79 -> V_83 . V_48 ) ;
if ( V_69 < 0 ) {
V_69 = - V_85 ;
goto V_84;
}
V_79 -> V_83 . V_40 = V_69 ;
if ( V_80 ) {
memcpy ( & V_79 -> V_68 . V_70 , V_79 -> V_83 . V_48 , 4 ) ;
memcpy ( & V_79 -> V_68 . V_71 , V_79 -> V_83 . V_48 + 4 , 4 ) ;
} else {
V_79 -> V_82 . V_48 = V_79 -> V_83 . V_48 ;
V_79 -> V_82 . V_40 = V_79 -> V_83 . V_40 ;
}
return 0 ;
V_84:
F_13 ( V_79 -> V_83 . V_48 ) ;
V_79 -> V_83 . V_48 = NULL ;
return V_69 ;
}
void F_35 ( struct V_78 * V_79 )
{
F_13 ( V_79 -> V_83 . V_48 ) ;
V_79 -> V_83 . V_48 = NULL ;
V_79 -> V_81 = NULL ;
V_79 -> V_82 . V_48 = NULL ;
}
