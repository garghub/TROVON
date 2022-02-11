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
return F_4 ( & F_5 ( V_8 ) -> V_10 , V_9 ) ;
}
struct V_8 * F_6 ( struct V_11 * V_12 ,
const struct V_13 * V_14 )
{
struct V_15 * V_16 = F_7 ( V_12 ) ;
struct V_17 * V_18 = NULL ;
struct V_8 * V_8 = NULL ;
int V_19 = 0 ;
unsigned long V_20 = F_8 ( V_14 ,
F_9 ( V_16 ) ) ;
struct V_21 * V_22 ;
int V_23 ;
F_10 ( V_24 , L_1 V_25 L_2 , V_20 , F_11 ( V_14 ) ) ;
V_8 = F_12 ( V_12 , V_20 , F_3 , ( void * ) V_14 ) ;
if ( V_8 )
return V_8 ;
V_23 = F_13 ( V_16 , & V_19 ) ;
if ( V_23 )
return F_14 ( V_23 ) ;
V_22 = F_15 ( sizeof( * V_22 ) , V_26 ) ;
if ( ! V_22 )
return F_14 ( - V_27 ) ;
V_22 -> V_28 = * V_14 ;
V_22 -> V_29 = V_19 ;
V_22 -> V_30 = V_31 ;
V_23 = F_16 ( V_16 -> V_32 , V_22 , & V_18 ) ;
F_17 ( V_22 ) ;
if ( V_23 ) {
F_18 ( L_3 V_25 L_4 ,
F_11 ( V_14 ) , V_23 ) ;
return F_14 ( V_23 ) ;
}
V_23 = F_19 ( & V_8 , V_18 , V_12 , NULL ) ;
F_20 ( V_18 ) ;
if ( V_23 )
return F_14 ( V_23 ) ;
return V_8 ;
}
static struct V_33 *
F_21 ( struct V_11 * V_12 , struct V_13 * V_14 , struct V_13 * V_34 )
{
struct V_8 * V_8 ;
struct V_33 * V_35 ;
F_10 ( V_24 , L_5 V_25 L_6 , F_11 ( V_14 ) ) ;
if ( ! F_22 ( V_14 ) )
return F_14 ( - V_36 ) ;
V_8 = F_6 ( V_12 , V_14 ) ;
if ( F_23 ( V_8 ) )
return F_24 ( V_8 ) ;
if ( F_25 ( V_8 ) ) {
F_26 ( V_8 ) ;
return F_14 ( - V_36 ) ;
}
if ( F_27 ( V_8 -> V_37 ) && ! F_5 ( V_8 ) -> V_38 &&
V_34 != NULL ) {
struct V_39 * V_40 = F_5 ( V_8 ) ;
F_28 ( & V_40 -> V_41 ) ;
V_40 -> V_42 = * V_34 ;
F_29 ( & V_40 -> V_41 ) ;
}
V_35 = F_30 ( V_8 ) ;
return V_35 ;
}
static int F_31 ( struct V_8 * V_8 , T_1 * V_43 , int * V_44 ,
struct V_8 * V_34 )
{
struct V_45 * V_46 = ( void * ) V_43 ;
F_10 ( V_24 , L_7 V_25 L_8 ,
V_8 -> V_47 , F_11 ( F_32 ( V_8 ) ) , * V_44 ,
( int ) sizeof( struct V_45 ) ) ;
if ( * V_44 < sizeof( struct V_45 ) / 4 )
return 255 ;
V_46 -> V_48 = * F_32 ( V_8 ) ;
V_46 -> V_49 = * F_32 ( V_34 ) ;
* V_44 = sizeof( struct V_45 ) / 4 ;
return V_50 ;
}
static int F_33 ( struct V_51 * V_52 , const char * V_1 ,
int V_53 , T_4 V_20 , T_5 V_54 ,
unsigned type )
{
struct V_55 * V_56 = F_34 ( V_1 , struct V_55 , V_57 ) ;
struct V_58 * V_59 =
F_35 ( V_52 , struct V_58 , V_52 ) ;
struct V_13 V_14 ;
F_36 ( & V_14 , & V_56 -> V_60 ) ;
if ( F_4 ( & V_14 , & V_59 -> V_61 ) ) {
memcpy ( V_59 -> V_62 , V_1 , V_53 ) ;
V_59 -> V_62 [ V_53 ] = 0 ;
V_59 -> V_63 = 1 ;
}
return V_59 -> V_63 ;
}
static int F_37 ( struct V_33 * V_33 , char * V_1 ,
struct V_33 * V_64 )
{
struct V_8 * V_65 = F_38 ( V_33 ) ;
int V_23 ;
struct V_58 V_59 = {
. V_62 = V_1 ,
. V_61 = F_5 ( F_38 ( V_64 ) ) -> V_10 ,
. V_52 . V_66 = F_33 ,
} ;
if ( ! V_65 || ! F_39 ( V_65 -> V_37 ) ) {
V_23 = - V_67 ;
goto V_68;
}
if ( ! V_65 -> V_69 ) {
V_23 = - V_70 ;
goto V_68;
}
F_40 ( V_65 ) ;
V_23 = F_41 ( V_65 , & V_59 . V_52 ) ;
F_42 ( V_65 ) ;
if ( ! V_23 && ! V_59 . V_63 )
V_23 = - V_71 ;
V_68:
return V_23 ;
}
static struct V_33 * F_43 ( struct V_11 * V_12 , struct V_14 * V_14 ,
int V_72 , int V_73 )
{
struct V_45 * V_46 = (struct V_45 * ) V_14 ;
if ( V_73 != V_50 )
return F_14 ( - V_74 ) ;
return F_21 ( V_12 , & V_46 -> V_48 , & V_46 -> V_49 ) ;
}
static struct V_33 * F_44 ( struct V_11 * V_12 , struct V_14 * V_14 ,
int V_72 , int V_73 )
{
struct V_45 * V_46 = (struct V_45 * ) V_14 ;
if ( V_73 != V_50 )
return F_14 ( - V_74 ) ;
return F_21 ( V_12 , & V_46 -> V_49 , NULL ) ;
}
static struct V_33 * F_45 ( struct V_33 * V_75 )
{
struct V_17 * V_18 = NULL ;
struct V_8 * V_65 = F_38 ( V_75 ) ;
struct V_15 * V_16 ;
struct V_33 * V_35 = NULL ;
struct V_76 * V_77 ;
static char V_78 [] = L_9 ;
struct V_21 * V_22 ;
int V_23 ;
int V_79 ;
F_46 ( V_65 && F_39 ( V_65 -> V_37 ) ) ;
V_16 = F_7 ( V_65 -> V_80 ) ;
F_10 ( V_24 , L_10 V_25 L_2 ,
V_65 -> V_47 , F_11 ( F_32 ( V_65 ) ) ) ;
V_23 = F_13 ( V_16 , & V_79 ) ;
if ( V_23 != 0 )
return F_14 ( V_23 ) ;
V_22 = F_47 ( NULL , V_65 , NULL , V_78 ,
strlen ( V_78 ) , V_79 ,
V_81 , NULL ) ;
if ( F_23 ( V_22 ) )
return ( void * ) V_22 ;
V_23 = F_48 ( V_16 -> V_32 , V_22 , & V_18 ) ;
F_49 ( V_22 ) ;
if ( V_23 ) {
F_18 ( L_11 , V_23 , V_65 -> V_47 ) ;
return F_14 ( V_23 ) ;
}
V_77 = F_50 ( & V_18 -> V_82 , & V_83 ) ;
F_46 ( V_77 -> V_84 & V_85 ) ;
F_10 ( V_24 , L_12 V_25 L_13 V_25 L_6 ,
F_11 ( F_32 ( V_65 ) ) , F_11 ( & V_77 -> V_86 ) ) ;
V_35 = F_21 ( V_65 -> V_80 , & V_77 -> V_86 , NULL ) ;
F_20 ( V_18 ) ;
return V_35 ;
}
