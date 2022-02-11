static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_3 == - V_7 )
return;
V_5 -> V_3 = V_3 ;
F_2 ( & V_5 -> V_8 ) ;
}
static int F_3 ( struct V_9 * V_9 ,
const struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_14 * V_2 = NULL ;
F_4 ( V_5 ) ;
struct V_15 * V_16 = V_9 -> V_17 ;
struct V_18 * V_19 = V_16 -> V_20 ;
int V_3 = 0 ;
char V_21 [ V_22 ] ;
struct V_23 V_24 ;
int V_25 = 4 << ( V_16 -> V_26 & V_27 ) ;
unsigned int V_28 ;
unsigned int V_29 ;
V_28 = V_9 -> V_30 -> V_31 -> V_32 ( V_9 ) ;
if ( V_11 -> V_33 <= 0 || V_11 -> V_33 > V_28 )
return - V_34 ;
V_29 = F_5 (unsigned int, iname->len, FS_CRYPTO_BLOCK_SIZE) ;
V_29 = F_6 ( V_29 , V_25 ) ;
V_29 = F_7 ( V_29 , V_28 ) ;
memcpy ( V_13 -> V_35 , V_11 -> V_35 , V_11 -> V_33 ) ;
memset ( V_13 -> V_35 + V_11 -> V_33 , 0 , V_29 - V_11 -> V_33 ) ;
memset ( V_21 , 0 , V_22 ) ;
V_2 = F_8 ( V_19 , V_36 ) ;
if ( ! V_2 ) {
F_9 ( V_37
L_1 , V_38 ) ;
return - V_39 ;
}
F_10 ( V_2 ,
V_40 | V_41 ,
F_1 , & V_5 ) ;
F_11 ( & V_24 , V_13 -> V_35 , V_29 ) ;
F_12 ( V_2 , & V_24 , & V_24 , V_29 , V_21 ) ;
V_3 = F_13 ( V_2 ) ;
if ( V_3 == - V_7 || V_3 == - V_42 ) {
F_14 ( & V_5 . V_8 ) ;
V_3 = V_5 . V_3 ;
}
F_15 ( V_2 ) ;
if ( V_3 < 0 ) {
F_9 ( V_37
L_2 , V_38 , V_3 ) ;
return V_3 ;
}
V_13 -> V_33 = V_29 ;
return 0 ;
}
static int F_16 ( struct V_9 * V_9 ,
const struct V_12 * V_11 ,
struct V_12 * V_13 )
{
struct V_14 * V_2 = NULL ;
F_4 ( V_5 ) ;
struct V_23 V_43 , V_44 ;
struct V_15 * V_16 = V_9 -> V_17 ;
struct V_18 * V_19 = V_16 -> V_20 ;
int V_3 = 0 ;
char V_21 [ V_22 ] ;
unsigned V_28 ;
V_28 = V_9 -> V_30 -> V_31 -> V_32 ( V_9 ) ;
if ( V_11 -> V_33 <= 0 || V_11 -> V_33 > V_28 )
return - V_34 ;
V_2 = F_8 ( V_19 , V_36 ) ;
if ( ! V_2 ) {
F_9 ( V_37
L_3 , V_38 ) ;
return - V_39 ;
}
F_10 ( V_2 ,
V_40 | V_41 ,
F_1 , & V_5 ) ;
memset ( V_21 , 0 , V_22 ) ;
F_11 ( & V_43 , V_11 -> V_35 , V_11 -> V_33 ) ;
F_11 ( & V_44 , V_13 -> V_35 , V_13 -> V_33 ) ;
F_12 ( V_2 , & V_43 , & V_44 , V_11 -> V_33 , V_21 ) ;
V_3 = F_17 ( V_2 ) ;
if ( V_3 == - V_7 || V_3 == - V_42 ) {
F_14 ( & V_5 . V_8 ) ;
V_3 = V_5 . V_3 ;
}
F_15 ( V_2 ) ;
if ( V_3 < 0 ) {
F_9 ( V_37
L_2 , V_38 , V_3 ) ;
return V_3 ;
}
V_13 -> V_33 = F_18 ( V_13 -> V_35 , V_11 -> V_33 ) ;
return 0 ;
}
static int F_19 ( const char * V_45 , int V_33 , char * V_46 )
{
int V_47 = 0 , V_48 = 0 , V_49 = 0 ;
char * V_50 = V_46 ;
while ( V_47 < V_33 ) {
V_49 += ( ( ( unsigned char ) V_45 [ V_47 ] ) << V_48 ) ;
V_48 += 8 ;
do {
* V_50 ++ = V_51 [ V_49 & 0x3f ] ;
V_49 >>= 6 ;
V_48 -= 6 ;
} while ( V_48 >= 6 );
V_47 ++ ;
}
if ( V_48 )
* V_50 ++ = V_51 [ V_49 & 0x3f ] ;
return V_50 - V_46 ;
}
static int F_20 ( const char * V_45 , int V_33 , char * V_46 )
{
int V_47 = 0 , V_48 = 0 , V_49 = 0 ;
const char * V_52 ;
char * V_50 = V_46 ;
while ( V_47 < V_33 ) {
V_52 = strchr ( V_51 , V_45 [ V_47 ] ) ;
if ( V_52 == NULL || V_45 [ V_47 ] == 0 )
return - 2 ;
V_49 += ( V_52 - V_51 ) << V_48 ;
V_48 += 6 ;
if ( V_48 >= 8 ) {
* V_50 ++ = V_49 & 0xff ;
V_49 >>= 8 ;
V_48 -= 8 ;
}
V_47 ++ ;
}
if ( V_49 )
return - 1 ;
return V_50 - V_46 ;
}
T_1 F_21 ( const struct V_9 * V_9 , T_1 V_53 )
{
int V_25 = 32 ;
struct V_15 * V_16 = V_9 -> V_17 ;
if ( V_16 )
V_25 = 4 << ( V_16 -> V_26 & V_27 ) ;
V_53 = F_22 ( V_53 , ( T_1 ) V_22 ) ;
return F_6 ( V_53 , V_25 ) ;
}
int F_23 ( const struct V_9 * V_9 ,
T_1 V_53 , struct V_12 * V_54 )
{
T_1 V_55 = F_21 ( V_9 , V_53 ) ;
const T_1 V_56 =
F_5 ( T_1 , F_24 ( V_57 ) ,
1 + F_24 ( sizeof( struct V_58 ) ) ) ;
V_54 -> V_33 = V_55 ;
V_55 = F_22 ( V_55 , V_56 ) ;
V_54 -> V_35 = F_25 ( V_55 + 1 , V_36 ) ;
if ( ! ( V_54 -> V_35 ) )
return - V_39 ;
return 0 ;
}
void F_26 ( struct V_12 * V_54 )
{
if ( ! V_54 )
return;
F_27 ( V_54 -> V_35 ) ;
V_54 -> V_35 = NULL ;
}
int F_28 ( struct V_9 * V_9 ,
T_1 V_59 , T_1 V_60 ,
const struct V_12 * V_11 ,
struct V_12 * V_13 )
{
const struct V_10 V_61 = F_29 ( V_11 ) ;
struct V_58 V_62 ;
if ( F_30 ( & V_61 ) ) {
V_13 -> V_35 [ 0 ] = '.' ;
V_13 -> V_35 [ V_11 -> V_33 - 1 ] = '.' ;
V_13 -> V_33 = V_11 -> V_33 ;
return 0 ;
}
if ( V_11 -> V_33 < V_22 )
return - V_63 ;
if ( V_9 -> V_17 )
return F_16 ( V_9 , V_11 , V_13 ) ;
if ( V_11 -> V_33 <= V_57 ) {
V_13 -> V_33 = F_19 ( V_11 -> V_35 , V_11 -> V_33 ,
V_13 -> V_35 ) ;
return 0 ;
}
if ( V_59 ) {
V_62 . V_59 = V_59 ;
V_62 . V_60 = V_60 ;
} else {
V_62 . V_59 = 0 ;
V_62 . V_60 = 0 ;
}
memcpy ( V_62 . V_64 ,
F_31 ( V_11 -> V_35 , V_11 -> V_33 ) ,
V_65 ) ;
V_13 -> V_35 [ 0 ] = '_' ;
V_13 -> V_33 = 1 + F_19 ( ( const char * ) & V_62 ,
sizeof( V_62 ) , V_13 -> V_35 + 1 ) ;
return 0 ;
}
int F_32 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
struct V_12 * V_13 )
{
if ( F_30 ( V_11 ) ) {
V_13 -> V_35 [ 0 ] = '.' ;
V_13 -> V_35 [ V_11 -> V_33 - 1 ] = '.' ;
V_13 -> V_33 = V_11 -> V_33 ;
return 0 ;
}
if ( V_9 -> V_17 )
return F_3 ( V_9 , V_11 , V_13 ) ;
return - V_66 ;
}
int F_33 ( struct V_9 * V_67 , const struct V_10 * V_11 ,
int V_68 , struct V_69 * V_70 )
{
int V_71 ;
int V_72 ;
memset ( V_70 , 0 , sizeof( struct V_69 ) ) ;
V_70 -> V_73 = V_11 ;
if ( ! V_67 -> V_30 -> V_31 -> V_74 ( V_67 ) ||
F_30 ( V_11 ) ) {
V_70 -> V_75 . V_35 = ( unsigned char * ) V_11 -> V_35 ;
V_70 -> V_75 . V_33 = V_11 -> V_33 ;
return 0 ;
}
V_71 = F_34 ( V_67 ) ;
if ( V_71 && V_71 != - V_76 )
return V_71 ;
if ( V_67 -> V_17 ) {
V_71 = F_23 ( V_67 , V_11 -> V_33 ,
& V_70 -> V_77 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_3 ( V_67 , V_11 , & V_70 -> V_77 ) ;
if ( V_71 )
goto V_78;
V_70 -> V_75 . V_35 = V_70 -> V_77 . V_35 ;
V_70 -> V_75 . V_33 = V_70 -> V_77 . V_33 ;
return 0 ;
}
if ( ! V_68 )
return - V_66 ;
if ( V_11 -> V_35 [ 0 ] == '_' ) {
if ( V_11 -> V_33 !=
1 + F_24 ( sizeof( struct V_58 ) ) )
return - V_79 ;
V_72 = 1 ;
} else {
if ( V_11 -> V_33 >
F_24 ( V_57 ) )
return - V_79 ;
V_72 = 0 ;
}
V_70 -> V_77 . V_35 =
F_25 ( F_5 ( V_80 , V_57 ,
sizeof( struct V_58 ) ) ,
V_81 ) ;
if ( V_70 -> V_77 . V_35 == NULL )
return - V_39 ;
V_71 = F_20 ( V_11 -> V_35 + V_72 , V_11 -> V_33 - V_72 ,
V_70 -> V_77 . V_35 ) ;
if ( V_71 < 0 ) {
V_71 = - V_79 ;
goto V_78;
}
V_70 -> V_77 . V_33 = V_71 ;
if ( V_72 ) {
const struct V_58 * V_82 =
( const void * ) V_70 -> V_77 . V_35 ;
V_70 -> V_59 = V_82 -> V_59 ;
V_70 -> V_60 = V_82 -> V_60 ;
} else {
V_70 -> V_75 . V_35 = V_70 -> V_77 . V_35 ;
V_70 -> V_75 . V_33 = V_70 -> V_77 . V_33 ;
}
return 0 ;
V_78:
F_26 ( & V_70 -> V_77 ) ;
return V_71 ;
}
