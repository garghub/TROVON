T_1 F_1 ( const char * V_1 , int V_2 )
{
T_1 V_3 = 0x12a3fe2d , V_4 = 0x37abe8f9 ;
while ( V_2 -- ) {
T_1 V_5 = V_4 + ( V_3 ^ ( * V_1 ++ * 7152373 ) ) ;
if ( V_5 & 0x80000000 )
V_5 -= 0x7fffffff ;
V_4 = V_3 ;
V_3 = V_5 ;
}
return ( V_3 << 1 ) ;
}
void F_2 ( const char * V_1 , int V_2 , T_2 * V_6 )
{
T_3 V_5 = 0 , V_3 = 0x12a3fe2d , V_4 = 0x37abe8f9 ;
while ( V_2 -- ) {
V_5 = V_4 + ( V_3 ^ ( * V_1 ++ * 7152373 ) ) ;
if ( V_5 & 0x8000000000000000ULL )
V_5 -= 0x7fffffffffffffffULL ;
V_4 = V_3 ;
V_3 = V_5 ;
}
V_6 -> V_7 [ 0 ] = V_5 ;
V_6 -> V_7 [ 1 ] = V_5 >> 32 ;
}
static int F_3 ( struct V_8 * V_8 , void * V_9 )
{
return F_4 ( & F_5 ( V_8 ) -> V_10 ,
(struct V_11 * ) V_9 ) ;
}
struct V_8 * F_6 ( struct V_12 * V_13 ,
const struct V_11 * V_14 )
{
struct V_15 * V_16 = F_7 ( V_13 ) ;
struct V_17 * V_18 = NULL ;
struct V_8 * V_8 = NULL ;
int V_19 = 0 ;
unsigned long V_20 = F_8 ( V_14 ,
F_9 ( V_16 ) ) ;
struct V_21 * V_22 ;
int V_23 ;
F_10 ( V_24 , L_1 V_25 L_2 , V_20 , F_11 ( V_14 ) ) ;
V_8 = F_12 ( V_13 , V_20 , F_3 , ( void * ) V_14 ) ;
if ( V_8 )
return V_8 ;
V_23 = F_13 ( V_16 , & V_19 ) ;
if ( V_23 )
return F_14 ( V_23 ) ;
F_15 ( V_22 ) ;
if ( V_22 == NULL )
return F_14 ( - V_26 ) ;
V_22 -> V_27 = * V_14 ;
V_22 -> V_28 = V_19 ;
V_22 -> V_29 = V_30 ;
V_23 = F_16 ( V_16 -> V_31 , V_22 , & V_18 ) ;
F_17 ( V_22 ) ;
if ( V_23 ) {
F_18 ( L_3 V_25 L_4 ,
F_11 ( V_14 ) , V_23 ) ;
return F_14 ( V_23 ) ;
}
V_23 = F_19 ( & V_8 , V_18 , V_13 , NULL ) ;
F_20 ( V_18 ) ;
if ( V_23 )
return F_14 ( V_23 ) ;
return V_8 ;
}
static struct V_32 *
F_21 ( struct V_12 * V_13 , struct V_11 * V_14 , struct V_11 * V_33 )
{
struct V_8 * V_8 ;
struct V_32 * V_34 ;
F_10 ( V_24 , L_5 V_25 L_6 , F_11 ( V_14 ) ) ;
if ( ! F_22 ( V_14 ) )
return F_14 ( - V_35 ) ;
V_8 = F_6 ( V_13 , V_14 ) ;
if ( F_23 ( V_8 ) )
return F_24 ( V_8 ) ;
if ( F_25 ( V_8 ) ) {
F_26 ( V_8 ) ;
return F_14 ( - V_35 ) ;
}
if ( F_27 ( V_8 -> V_36 ) && ! F_5 ( V_8 ) -> V_37 &&
V_33 != NULL ) {
struct V_38 * V_39 = F_5 ( V_8 ) ;
F_28 ( & V_39 -> V_40 ) ;
V_39 -> V_41 = * V_33 ;
F_29 ( & V_39 -> V_40 ) ;
}
V_34 = F_30 ( V_8 ) ;
if ( F_23 ( V_34 ) ) {
F_26 ( V_8 ) ;
return V_34 ;
}
return V_34 ;
}
static int F_31 ( struct V_8 * V_8 , T_1 * V_42 , int * V_43 ,
struct V_8 * V_33 )
{
struct V_44 * V_45 = ( void * ) V_42 ;
F_10 ( V_24 , L_7 V_25 L_8 ,
V_8 -> V_46 , F_11 ( F_32 ( V_8 ) ) , * V_43 ,
( int ) sizeof( struct V_44 ) ) ;
if ( * V_43 < sizeof( struct V_44 ) / 4 )
return 255 ;
V_45 -> V_47 = * F_32 ( V_8 ) ;
V_45 -> V_48 = * F_32 ( V_33 ) ;
* V_43 = sizeof( struct V_44 ) / 4 ;
return V_49 ;
}
static int F_33 ( void * V_50 , const char * V_1 , int V_51 ,
T_4 V_20 , T_5 V_52 , unsigned type )
{
struct V_53 * V_54 = F_34 ( V_1 , struct V_53 , V_55 ) ;
struct V_56 * V_57 = V_50 ;
struct V_11 V_14 ;
F_35 ( & V_14 , & V_54 -> V_58 ) ;
if ( F_4 ( & V_14 , & V_57 -> V_59 ) ) {
memcpy ( V_57 -> V_60 , V_1 , V_51 ) ;
V_57 -> V_60 [ V_51 ] = 0 ;
V_57 -> V_61 = 1 ;
}
return V_57 -> V_61 ;
}
static int F_36 ( struct V_32 * V_32 , char * V_1 ,
struct V_32 * V_62 )
{
struct V_8 * V_63 = V_32 -> V_64 ;
int V_23 ;
struct V_56 V_57 = {
. V_60 = V_1 ,
. V_59 = F_5 ( V_62 -> V_64 ) -> V_10 ,
. V_65 . V_66 = F_33 ,
} ;
if ( ! V_63 || ! F_37 ( V_63 -> V_36 ) )
GOTO ( V_67 , V_23 = - V_68 ) ;
if ( ! V_63 -> V_69 )
GOTO ( V_67 , V_23 = - V_70 ) ;
F_38 ( & V_63 -> V_71 ) ;
V_23 = F_39 ( V_63 , & V_57 . V_65 ) ;
F_40 ( & V_63 -> V_71 ) ;
if ( ! V_23 && ! V_57 . V_61 )
V_23 = - V_72 ;
V_67:
return V_23 ;
}
static struct V_32 * F_41 ( struct V_12 * V_13 , struct V_14 * V_14 ,
int V_73 , int V_74 )
{
struct V_44 * V_45 = (struct V_44 * ) V_14 ;
if ( V_74 != V_49 )
return F_14 ( - V_75 ) ;
return F_21 ( V_13 , & V_45 -> V_47 , & V_45 -> V_48 ) ;
}
static struct V_32 * F_42 ( struct V_12 * V_13 , struct V_14 * V_14 ,
int V_73 , int V_74 )
{
struct V_44 * V_45 = (struct V_44 * ) V_14 ;
if ( V_74 != V_49 )
return F_14 ( - V_75 ) ;
return F_21 ( V_13 , & V_45 -> V_48 , NULL ) ;
}
static struct V_32 * F_43 ( struct V_32 * V_76 )
{
struct V_17 * V_18 = NULL ;
struct V_8 * V_63 = V_76 -> V_64 ;
struct V_15 * V_16 ;
struct V_32 * V_34 = NULL ;
struct V_77 * V_78 ;
static char V_79 [] = L_9 ;
struct V_21 * V_22 ;
int V_23 ;
int V_80 ;
F_44 ( V_63 && F_37 ( V_63 -> V_36 ) ) ;
V_16 = F_7 ( V_63 -> V_81 ) ;
F_10 ( V_24 , L_10 V_25 L_2 ,
V_63 -> V_46 , F_11 ( F_32 ( V_63 ) ) ) ;
V_23 = F_13 ( V_16 , & V_80 ) ;
if ( V_23 != 0 )
return F_14 ( V_23 ) ;
V_22 = F_45 ( NULL , V_63 , NULL , V_79 ,
strlen ( V_79 ) , V_80 ,
V_82 , NULL ) ;
if ( F_23 ( V_22 ) )
return ( void * ) V_22 ;
V_23 = F_46 ( V_16 -> V_31 , V_22 , & V_18 ) ;
F_47 ( V_22 ) ;
if ( V_23 ) {
F_18 ( L_11 , V_23 , V_63 -> V_46 ) ;
return F_14 ( V_23 ) ;
}
V_78 = F_48 ( & V_18 -> V_83 , & V_84 ) ;
F_44 ( V_78 -> V_85 & V_86 ) ;
F_10 ( V_24 , L_12 V_25 L_13 V_25 L_6 ,
F_11 ( F_32 ( V_63 ) ) , F_11 ( & V_78 -> V_87 ) ) ;
V_34 = F_21 ( V_63 -> V_81 , & V_78 -> V_87 , NULL ) ;
F_20 ( V_18 ) ;
return V_34 ;
}
