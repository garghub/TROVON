static T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
return ( ( V_1 + V_2 - 1 ) / V_2 ) * V_2 ;
}
static void F_2 ( struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
if ( V_5 == - V_9 )
return;
V_7 -> V_5 = V_5 ;
F_3 ( & V_7 -> V_10 ) ;
}
static int F_4 ( struct V_11 * V_11 ,
const struct V_12 * V_13 , struct V_14 * V_15 )
{
T_1 V_16 ;
struct V_17 * V_4 = NULL ;
F_5 ( V_7 ) ;
struct V_18 * V_19 = V_11 -> V_20 ;
struct V_21 * V_22 = V_19 -> V_23 ;
int V_5 = 0 ;
char V_24 [ V_25 ] ;
struct V_26 V_27 , V_28 ;
int V_29 = 4 << ( V_19 -> V_30 & V_31 ) ;
char * V_32 , V_33 [ 32 ] , * V_34 = NULL ;
unsigned V_35 ;
V_35 = V_11 -> V_36 -> V_37 -> V_38 ( V_11 ) ;
if ( V_13 -> V_39 <= 0 || V_13 -> V_39 > V_35 )
return - V_40 ;
V_16 = ( V_13 -> V_39 < V_25 ) ?
V_25 : V_13 -> V_39 ;
V_16 = F_1 ( V_16 , V_29 ) ;
V_16 = ( V_16 > V_35 ) ? V_35 : V_16 ;
if ( V_16 <= sizeof( V_33 ) ) {
V_32 = V_33 ;
} else {
V_34 = F_6 ( V_16 , V_41 ) ;
if ( ! V_34 )
return - V_42 ;
V_32 = V_34 ;
}
V_4 = F_7 ( V_22 , V_41 ) ;
if ( ! V_4 ) {
F_8 ( V_43
L_1 , V_44 ) ;
F_9 ( V_34 ) ;
return - V_42 ;
}
F_10 ( V_4 ,
V_45 | V_46 ,
F_2 , & V_7 ) ;
memcpy ( V_32 , V_13 -> V_47 , V_13 -> V_39 ) ;
if ( V_13 -> V_39 < V_16 )
memset ( V_32 + V_13 -> V_39 , 0 , V_16 - V_13 -> V_39 ) ;
memset ( V_24 , 0 , V_25 ) ;
F_11 ( & V_27 , V_32 , V_16 ) ;
F_11 ( & V_28 , V_15 -> V_47 , V_16 ) ;
F_12 ( V_4 , & V_27 , & V_28 , V_16 , V_24 ) ;
V_5 = F_13 ( V_4 ) ;
if ( V_5 == - V_9 || V_5 == - V_48 ) {
F_14 ( & V_7 . V_10 ) ;
V_5 = V_7 . V_5 ;
}
F_9 ( V_34 ) ;
F_15 ( V_4 ) ;
if ( V_5 < 0 )
F_8 ( V_43
L_2 , V_44 , V_5 ) ;
V_15 -> V_39 = V_16 ;
return V_5 ;
}
static int F_16 ( struct V_11 * V_11 ,
const struct V_14 * V_13 ,
struct V_14 * V_15 )
{
struct V_17 * V_4 = NULL ;
F_5 ( V_7 ) ;
struct V_26 V_27 , V_28 ;
struct V_18 * V_19 = V_11 -> V_20 ;
struct V_21 * V_22 = V_19 -> V_23 ;
int V_5 = 0 ;
char V_24 [ V_25 ] ;
unsigned V_35 ;
V_35 = V_11 -> V_36 -> V_37 -> V_38 ( V_11 ) ;
if ( V_13 -> V_39 <= 0 || V_13 -> V_39 > V_35 )
return - V_40 ;
V_4 = F_7 ( V_22 , V_41 ) ;
if ( ! V_4 ) {
F_8 ( V_43
L_1 , V_44 ) ;
return - V_42 ;
}
F_10 ( V_4 ,
V_45 | V_46 ,
F_2 , & V_7 ) ;
memset ( V_24 , 0 , V_25 ) ;
F_11 ( & V_27 , V_13 -> V_47 , V_13 -> V_39 ) ;
F_11 ( & V_28 , V_15 -> V_47 , V_15 -> V_39 ) ;
F_12 ( V_4 , & V_27 , & V_28 , V_13 -> V_39 , V_24 ) ;
V_5 = F_17 ( V_4 ) ;
if ( V_5 == - V_9 || V_5 == - V_48 ) {
F_14 ( & V_7 . V_10 ) ;
V_5 = V_7 . V_5 ;
}
F_15 ( V_4 ) ;
if ( V_5 < 0 ) {
F_8 ( V_43
L_2 , V_44 , V_5 ) ;
return V_5 ;
}
V_15 -> V_39 = F_18 ( V_15 -> V_47 , V_13 -> V_39 ) ;
return V_15 -> V_39 ;
}
static int F_19 ( const char * V_49 , int V_39 , char * V_50 )
{
int V_51 = 0 , V_52 = 0 , V_53 = 0 ;
char * V_54 = V_50 ;
while ( V_51 < V_39 ) {
V_53 += ( ( ( unsigned char ) V_49 [ V_51 ] ) << V_52 ) ;
V_52 += 8 ;
do {
* V_54 ++ = V_55 [ V_53 & 0x3f ] ;
V_53 >>= 6 ;
V_52 -= 6 ;
} while ( V_52 >= 6 );
V_51 ++ ;
}
if ( V_52 )
* V_54 ++ = V_55 [ V_53 & 0x3f ] ;
return V_54 - V_50 ;
}
static int F_20 ( const char * V_49 , int V_39 , char * V_50 )
{
int V_51 = 0 , V_52 = 0 , V_53 = 0 ;
const char * V_56 ;
char * V_54 = V_50 ;
while ( V_51 < V_39 ) {
V_56 = strchr ( V_55 , V_49 [ V_51 ] ) ;
if ( V_56 == NULL || V_49 [ V_51 ] == 0 )
return - 2 ;
V_53 += ( V_56 - V_55 ) << V_52 ;
V_52 += 6 ;
if ( V_52 >= 8 ) {
* V_54 ++ = V_53 & 0xff ;
V_53 >>= 8 ;
V_52 -= 8 ;
}
V_51 ++ ;
}
if ( V_53 )
return - 1 ;
return V_54 - V_50 ;
}
T_1 F_21 ( struct V_11 * V_11 , T_1 V_57 )
{
int V_29 = 32 ;
struct V_18 * V_19 = V_11 -> V_20 ;
if ( V_19 )
V_29 = 4 << ( V_19 -> V_30 & V_31 ) ;
if ( V_57 < V_25 )
V_57 = V_25 ;
return F_1 ( V_57 , V_29 ) ;
}
int F_22 ( struct V_11 * V_11 ,
T_1 V_57 , struct V_14 * V_58 )
{
unsigned int V_59 = F_21 ( V_11 , V_57 ) ;
V_58 -> V_39 = V_59 ;
if ( V_59 < V_60 * 2 )
V_59 = V_60 * 2 ;
V_58 -> V_47 = F_6 ( V_59 + 1 , V_41 ) ;
if ( ! ( V_58 -> V_47 ) )
return - V_42 ;
return 0 ;
}
void F_23 ( struct V_14 * V_58 )
{
if ( ! V_58 )
return;
F_9 ( V_58 -> V_47 ) ;
V_58 -> V_47 = NULL ;
}
int F_24 ( struct V_11 * V_11 ,
T_1 V_61 , T_1 V_62 ,
const struct V_14 * V_13 ,
struct V_14 * V_15 )
{
const struct V_12 V_63 = F_25 ( V_13 ) ;
char V_33 [ 24 ] ;
int V_64 ;
if ( F_26 ( & V_63 ) ) {
V_15 -> V_47 [ 0 ] = '.' ;
V_15 -> V_47 [ V_13 -> V_39 - 1 ] = '.' ;
V_15 -> V_39 = V_13 -> V_39 ;
return V_15 -> V_39 ;
}
if ( V_13 -> V_39 < V_25 )
return - V_65 ;
if ( V_11 -> V_20 )
return F_16 ( V_11 , V_13 , V_15 ) ;
if ( V_13 -> V_39 <= V_60 ) {
V_64 = F_19 ( V_13 -> V_47 , V_13 -> V_39 , V_15 -> V_47 ) ;
V_15 -> V_39 = V_64 ;
return V_64 ;
}
if ( V_61 ) {
memcpy ( V_33 , & V_61 , 4 ) ;
memcpy ( V_33 + 4 , & V_62 , 4 ) ;
} else {
memset ( V_33 , 0 , 8 ) ;
}
memcpy ( V_33 + 8 , V_13 -> V_47 + V_13 -> V_39 - 16 , 16 ) ;
V_15 -> V_47 [ 0 ] = '_' ;
V_64 = F_19 ( V_33 , 24 , V_15 -> V_47 + 1 ) ;
V_15 -> V_39 = V_64 + 1 ;
return V_64 + 1 ;
}
int F_27 ( struct V_11 * V_11 ,
const struct V_12 * V_13 ,
struct V_14 * V_15 )
{
if ( F_26 ( V_13 ) ) {
V_15 -> V_47 [ 0 ] = '.' ;
V_15 -> V_47 [ V_13 -> V_39 - 1 ] = '.' ;
V_15 -> V_39 = V_13 -> V_39 ;
return V_15 -> V_39 ;
}
if ( V_11 -> V_20 )
return F_4 ( V_11 , V_13 , V_15 ) ;
return - V_66 ;
}
int F_28 ( struct V_11 * V_67 , const struct V_12 * V_13 ,
int V_68 , struct V_69 * V_70 )
{
int V_64 = 0 , V_71 = 0 ;
memset ( V_70 , 0 , sizeof( struct V_69 ) ) ;
V_70 -> V_72 = V_13 ;
if ( ! V_67 -> V_36 -> V_37 -> V_73 ( V_67 ) ||
F_26 ( V_13 ) ) {
V_70 -> V_74 . V_47 = ( unsigned char * ) V_13 -> V_47 ;
V_70 -> V_74 . V_39 = V_13 -> V_39 ;
return 0 ;
}
V_64 = F_29 ( V_67 ) ;
if ( V_64 && V_64 != - V_75 )
return V_64 ;
if ( V_67 -> V_20 ) {
V_64 = F_22 ( V_67 , V_13 -> V_39 ,
& V_70 -> V_76 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_4 ( V_67 , V_13 , & V_70 -> V_76 ) ;
if ( V_64 < 0 )
goto V_77;
V_70 -> V_74 . V_47 = V_70 -> V_76 . V_47 ;
V_70 -> V_74 . V_39 = V_70 -> V_76 . V_39 ;
return 0 ;
}
if ( ! V_68 )
return - V_66 ;
if ( V_13 -> V_47 [ 0 ] == '_' )
V_71 = 1 ;
if ( ( V_71 && ( V_13 -> V_39 != 33 ) ) || ( ! V_71 && ( V_13 -> V_39 > 43 ) ) )
return - V_78 ;
V_70 -> V_76 . V_47 = F_6 ( 32 , V_79 ) ;
if ( V_70 -> V_76 . V_47 == NULL )
return - V_42 ;
V_64 = F_20 ( V_13 -> V_47 + V_71 , V_13 -> V_39 - V_71 ,
V_70 -> V_76 . V_47 ) ;
if ( V_64 < 0 ) {
V_64 = - V_78 ;
goto V_77;
}
V_70 -> V_76 . V_39 = V_64 ;
if ( V_71 ) {
memcpy ( & V_70 -> V_61 , V_70 -> V_76 . V_47 , 4 ) ;
memcpy ( & V_70 -> V_62 , V_70 -> V_76 . V_47 + 4 , 4 ) ;
} else {
V_70 -> V_74 . V_47 = V_70 -> V_76 . V_47 ;
V_70 -> V_74 . V_39 = V_70 -> V_76 . V_39 ;
}
return 0 ;
V_77:
F_23 ( & V_70 -> V_76 ) ;
return V_64 ;
}
void F_30 ( struct V_69 * V_70 )
{
F_9 ( V_70 -> V_76 . V_47 ) ;
V_70 -> V_76 . V_47 = NULL ;
V_70 -> V_72 = NULL ;
V_70 -> V_74 . V_47 = NULL ;
}
