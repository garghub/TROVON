T_1 F_1 ( const char * V_1 , int V_2 )
{
T_1 V_3 = 0x12a3fe2d , V_4 = 0x37abe8f9 ;
while ( V_2 -- ) {
T_1 V_5 = V_4 + ( V_3 ^ ( * V_1 ++ * 7152373 ) ) ;
if ( V_5 & 0x80000000 ) V_5 -= 0x7fffffff ;
V_4 = V_3 ;
V_3 = V_5 ;
}
return ( V_3 << 1 ) ;
}
static int F_2 ( struct V_6 * V_6 , void * V_7 )
{
return F_3 ( & F_4 ( V_6 ) -> V_8 ,
(struct V_9 * ) V_7 ) ;
}
struct V_6 * F_5 ( struct V_10 * V_11 ,
const struct V_9 * V_12 )
{
struct V_13 * V_14 = F_6 ( V_11 ) ;
struct V_15 * V_16 = NULL ;
struct V_6 * V_6 = NULL ;
int V_17 = 0 ;
unsigned long V_18 = F_7 ( V_12 ,
F_8 ( V_14 ) ) ;
struct V_19 * V_20 ;
int V_21 ;
V_22 ;
F_9 ( V_23 , L_1 V_24 L_2 , V_18 , F_10 ( V_12 ) ) ;
V_6 = F_11 ( V_11 , V_18 , F_2 , ( void * ) V_12 ) ;
if ( V_6 )
RETURN ( V_6 ) ;
V_21 = F_12 ( V_14 , & V_17 ) ;
if ( V_21 )
RETURN ( F_13 ( V_21 ) ) ;
F_14 ( V_20 ) ;
if ( V_20 == NULL )
return F_13 ( - V_25 ) ;
V_20 -> V_26 = * V_12 ;
V_20 -> V_27 = V_17 ;
V_20 -> V_28 = V_29 ;
V_21 = F_15 ( V_14 -> V_30 , V_20 , & V_16 ) ;
F_16 ( V_20 ) ;
if ( V_21 ) {
F_17 ( L_3 V_24 L_4 ,
F_10 ( V_12 ) , V_21 ) ;
RETURN ( F_13 ( V_21 ) ) ;
}
V_21 = F_18 ( & V_6 , V_16 , V_11 , NULL ) ;
F_19 ( V_16 ) ;
if ( V_21 )
RETURN ( F_13 ( V_21 ) ) ;
RETURN ( V_6 ) ;
}
static struct V_31 *
F_20 ( struct V_10 * V_11 , struct V_9 * V_12 , struct V_9 * V_32 )
{
struct V_6 * V_6 ;
struct V_31 * V_33 ;
V_22 ;
F_9 ( V_23 , L_5 V_24 L_6 , F_10 ( V_12 ) ) ;
if ( ! F_21 ( V_12 ) )
RETURN ( F_13 ( - V_34 ) ) ;
V_6 = F_5 ( V_11 , V_12 ) ;
if ( F_22 ( V_6 ) )
RETURN ( F_13 ( F_23 ( V_6 ) ) ) ;
if ( F_24 ( V_6 ) ) {
F_25 ( V_6 ) ;
RETURN ( F_13 ( - V_34 ) ) ;
}
if ( F_26 ( V_6 -> V_35 ) && ! F_4 ( V_6 ) -> V_36 &&
V_32 != NULL ) {
struct V_37 * V_38 = F_4 ( V_6 ) ;
F_27 ( & V_38 -> V_39 ) ;
V_38 -> V_40 = * V_32 ;
F_28 ( & V_38 -> V_39 ) ;
}
V_33 = F_29 ( V_6 ) ;
if ( F_22 ( V_33 ) )
RETURN ( V_33 ) ;
F_30 ( V_33 , 1 , 0 ) ;
RETURN ( V_33 ) ;
}
static int F_31 ( struct V_6 * V_6 , T_1 * V_41 , int * V_42 ,
struct V_6 * V_32 )
{
struct V_43 * V_44 = ( void * ) V_41 ;
V_22 ;
F_9 ( V_23 , L_7 V_24 L_8 ,
V_6 -> V_45 , F_10 ( F_32 ( V_6 ) ) , * V_42 ,
( int ) sizeof( struct V_43 ) ) ;
if ( * V_42 < sizeof( struct V_43 ) / 4 )
RETURN ( 255 ) ;
V_44 -> V_46 = * F_32 ( V_6 ) ;
V_44 -> V_47 = * F_32 ( V_32 ) ;
* V_42 = sizeof( struct V_43 ) / 4 ;
RETURN ( V_48 ) ;
}
static int F_33 ( void * V_49 , const char * V_1 , int V_50 ,
T_2 V_18 , T_3 V_51 , unsigned type )
{
struct V_52 * V_53 = F_34 ( V_1 , struct V_52 , V_54 ) ;
struct V_55 * V_56 = V_49 ;
struct V_9 V_12 ;
F_35 ( & V_12 , & V_53 -> V_57 ) ;
if ( F_3 ( & V_12 , & V_56 -> V_58 ) ) {
memcpy ( V_56 -> V_59 , V_1 , V_50 ) ;
V_56 -> V_59 [ V_50 ] = 0 ;
V_56 -> V_60 = 1 ;
}
return V_56 -> V_60 ;
}
static int F_36 ( struct V_31 * V_31 , char * V_1 ,
struct V_31 * V_61 )
{
struct V_6 * V_62 = V_31 -> V_63 ;
struct V_55 V_56 ;
T_4 V_64 = 0 ;
int V_21 ;
V_22 ;
if ( ! V_62 || ! F_37 ( V_62 -> V_35 ) )
GOTO ( V_65 , V_21 = - V_66 ) ;
if ( ! V_62 -> V_67 )
GOTO ( V_65 , V_21 = - V_68 ) ;
V_56 . V_59 = V_1 ;
V_56 . V_58 = F_4 ( V_61 -> V_63 ) -> V_8 ;
V_56 . V_60 = 0 ;
F_38 ( & V_62 -> V_69 ) ;
V_21 = F_39 ( V_62 , & V_64 , & V_56 , F_33 ) ;
F_40 ( & V_62 -> V_69 ) ;
if ( ! V_21 && ! V_56 . V_60 )
V_21 = - V_70 ;
EXIT ;
V_65:
return V_21 ;
}
static struct V_31 * F_41 ( struct V_10 * V_11 , struct V_12 * V_12 ,
int V_71 , int V_72 )
{
struct V_43 * V_44 = (struct V_43 * ) V_12 ;
if ( V_72 != V_48 )
RETURN ( F_13 ( - V_73 ) ) ;
RETURN ( F_20 ( V_11 , & V_44 -> V_46 , & V_44 -> V_47 ) ) ;
}
static struct V_31 * F_42 ( struct V_10 * V_11 , struct V_12 * V_12 ,
int V_71 , int V_72 )
{
struct V_43 * V_44 = (struct V_43 * ) V_12 ;
if ( V_72 != V_48 )
RETURN ( F_13 ( - V_73 ) ) ;
RETURN ( F_20 ( V_11 , & V_44 -> V_47 , NULL ) ) ;
}
static struct V_31 * F_43 ( struct V_31 * V_74 )
{
struct V_15 * V_16 = NULL ;
struct V_6 * V_62 = V_74 -> V_63 ;
struct V_13 * V_14 ;
struct V_31 * V_33 = NULL ;
struct V_75 * V_76 ;
static char V_77 [] = L_9 ;
struct V_19 * V_20 ;
int V_21 ;
int V_78 ;
V_22 ;
F_44 ( V_62 && F_37 ( V_62 -> V_35 ) ) ;
V_14 = F_6 ( V_62 -> V_79 ) ;
F_9 ( V_23 , L_10 V_24 L_2 ,
V_62 -> V_45 , F_10 ( F_32 ( V_62 ) ) ) ;
V_21 = F_12 ( V_14 , & V_78 ) ;
if ( V_21 != 0 )
RETURN ( F_13 ( V_21 ) ) ;
V_20 = F_45 ( NULL , V_62 , NULL , V_77 ,
strlen ( V_77 ) , V_78 ,
V_80 , NULL ) ;
if ( F_22 ( V_20 ) )
RETURN ( ( void * ) V_20 ) ;
V_21 = F_46 ( V_14 -> V_30 , V_20 , & V_16 ) ;
F_47 ( V_20 ) ;
if ( V_21 ) {
F_17 ( L_11 , V_21 , V_62 -> V_45 ) ;
RETURN ( F_13 ( V_21 ) ) ;
}
V_76 = F_48 ( & V_16 -> V_81 , & V_82 ) ;
F_44 ( V_76 -> V_83 & V_84 ) ;
F_9 ( V_23 , L_12 V_24 L_13 V_24 L_6 ,
F_10 ( F_32 ( V_62 ) ) , F_10 ( & V_76 -> V_85 ) ) ;
V_33 = F_20 ( V_62 -> V_79 , & V_76 -> V_85 , NULL ) ;
F_19 ( V_16 ) ;
RETURN ( V_33 ) ;
}
