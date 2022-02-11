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
F_10 ( V_24 , L_3 V_25 L_4 ,
F_11 ( V_14 ) , V_23 ) ;
return F_14 ( V_23 ) ;
}
V_23 = F_18 ( & V_8 , V_18 , V_12 , NULL ) ;
F_19 ( V_18 ) ;
if ( V_23 )
return F_14 ( V_23 ) ;
return V_8 ;
}
static struct V_33 *
F_20 ( struct V_11 * V_12 , struct V_13 * V_14 , struct V_13 * V_34 )
{
struct V_8 * V_8 ;
struct V_33 * V_35 ;
if ( ! F_21 ( V_14 ) )
return F_14 ( - V_36 ) ;
F_10 ( V_24 , L_5 V_25 L_6 , F_11 ( V_14 ) ) ;
V_8 = F_6 ( V_12 , V_14 ) ;
if ( F_22 ( V_8 ) )
return F_23 ( V_8 ) ;
if ( F_24 ( V_8 ) ) {
F_25 ( V_8 ) ;
return F_14 ( - V_36 ) ;
}
if ( F_26 ( V_8 -> V_37 ) && ! F_5 ( V_8 ) -> V_38 &&
V_34 && ! F_27 ( V_34 ) ) {
struct V_39 * V_40 = F_5 ( V_8 ) ;
F_28 ( & V_40 -> V_41 ) ;
V_40 -> V_42 = * V_34 ;
F_29 ( & V_40 -> V_41 ) ;
}
V_35 = F_30 ( V_8 ) ;
if ( ! F_22 ( V_35 ) ) {
int V_23 ;
V_23 = F_31 ( V_35 ) ;
if ( V_23 < 0 ) {
F_32 ( V_35 ) ;
V_35 = F_14 ( V_23 ) ;
} else {
struct V_43 * V_44 = F_33 ( V_35 ) ;
V_44 -> V_45 = 1 ;
}
}
return V_35 ;
}
static int F_34 ( struct V_8 * V_8 , T_1 * V_46 , int * V_47 ,
struct V_8 * V_34 )
{
int V_48 = sizeof( struct V_49 ) / 4 ;
struct V_49 * V_50 = ( void * ) V_46 ;
F_10 ( V_24 , L_7 V_25 L_8 ,
F_35 ( V_8 -> V_51 , NULL , 0 ) ,
F_11 ( F_36 ( V_8 ) ) , * V_47 , V_48 ) ;
if ( * V_47 < V_48 ) {
* V_47 = V_48 ;
return V_52 ;
}
V_50 -> V_53 = * F_36 ( V_8 ) ;
if ( V_34 )
V_50 -> V_54 = * F_36 ( V_34 ) ;
else
F_37 ( & V_50 -> V_54 ) ;
* V_47 = V_48 ;
return V_55 ;
}
static int F_38 ( struct V_56 * V_57 , const char * V_1 ,
int V_58 , T_4 V_20 , T_5 V_59 ,
unsigned type )
{
struct V_60 * V_61 = F_39 ( V_1 , struct V_60 , V_62 ) ;
struct V_63 * V_64 =
F_40 ( V_57 , struct V_63 , V_57 ) ;
struct V_13 V_14 ;
F_41 ( & V_14 , & V_61 -> V_65 ) ;
if ( F_4 ( & V_14 , & V_64 -> V_66 ) ) {
memcpy ( V_64 -> V_67 , V_1 , V_58 ) ;
V_64 -> V_67 [ V_58 ] = 0 ;
V_64 -> V_68 = 1 ;
}
return V_64 -> V_68 ;
}
static int F_42 ( struct V_33 * V_33 , char * V_1 ,
struct V_33 * V_69 )
{
struct V_8 * V_70 = F_43 ( V_33 ) ;
int V_23 ;
struct V_63 V_64 = {
. V_67 = V_1 ,
. V_66 = F_5 ( F_43 ( V_69 ) ) -> V_10 ,
. V_57 . V_71 = F_38 ,
} ;
if ( ! V_70 || ! F_44 ( V_70 -> V_37 ) ) {
V_23 = - V_72 ;
goto V_73;
}
if ( ! V_70 -> V_74 ) {
V_23 = - V_75 ;
goto V_73;
}
F_45 ( V_70 ) ;
V_23 = F_46 ( V_70 , & V_64 . V_57 ) ;
F_47 ( V_70 ) ;
if ( ! V_23 && ! V_64 . V_68 )
V_23 = - V_76 ;
V_73:
return V_23 ;
}
static struct V_33 * F_48 ( struct V_11 * V_12 , struct V_14 * V_14 ,
int V_77 , int V_78 )
{
struct V_49 * V_50 = (struct V_49 * ) V_14 ;
if ( V_78 != V_55 )
return F_14 ( - V_79 ) ;
return F_20 ( V_12 , & V_50 -> V_53 , & V_50 -> V_54 ) ;
}
static struct V_33 * F_49 ( struct V_11 * V_12 , struct V_14 * V_14 ,
int V_77 , int V_78 )
{
struct V_49 * V_50 = (struct V_49 * ) V_14 ;
if ( V_78 != V_55 )
return F_14 ( - V_79 ) ;
return F_20 ( V_12 , & V_50 -> V_54 , NULL ) ;
}
static struct V_33 * F_50 ( struct V_33 * V_80 )
{
struct V_17 * V_18 = NULL ;
struct V_8 * V_70 = F_43 ( V_80 ) ;
struct V_15 * V_16 ;
struct V_33 * V_35 = NULL ;
struct V_81 * V_82 ;
static char V_83 [] = L_9 ;
struct V_21 * V_22 ;
int V_23 ;
int V_84 ;
F_51 ( V_70 && F_44 ( V_70 -> V_37 ) ) ;
V_16 = F_7 ( V_70 -> V_51 ) ;
F_10 ( V_24 , L_10 V_25 L_2 ,
F_35 ( V_70 -> V_51 , NULL , 0 ) ,
F_11 ( F_36 ( V_70 ) ) ) ;
V_23 = F_13 ( V_16 , & V_84 ) ;
if ( V_23 != 0 )
return F_14 ( V_23 ) ;
V_22 = F_52 ( NULL , V_70 , NULL , V_83 ,
strlen ( V_83 ) , V_84 ,
V_85 , NULL ) ;
if ( F_22 ( V_22 ) )
return ( void * ) V_22 ;
V_23 = F_53 ( V_16 -> V_32 , V_22 , & V_18 ) ;
F_54 ( V_22 ) ;
if ( V_23 ) {
F_55 ( L_11 V_25 L_12 ,
F_35 ( V_70 -> V_51 , NULL , 0 ) ,
F_11 ( F_36 ( V_70 ) ) , V_23 ) ;
return F_14 ( V_23 ) ;
}
V_82 = F_56 ( & V_18 -> V_86 , & V_87 ) ;
if ( V_82 -> V_88 & V_89 ) {
F_10 ( V_24 , L_13 V_25 L_14 V_25 L_6 ,
F_11 ( F_36 ( V_70 ) ) , F_11 ( & V_82 -> V_90 ) ) ;
}
V_35 = F_20 ( V_70 -> V_51 , & V_82 -> V_90 , NULL ) ;
F_19 ( V_18 ) ;
return V_35 ;
}
