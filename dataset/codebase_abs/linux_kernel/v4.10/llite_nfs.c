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
struct V_8 * F_3 ( struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
struct V_13 * V_14 = F_4 ( V_10 ) ;
struct V_15 * V_16 = NULL ;
struct V_8 * V_8 = NULL ;
int V_17 = 0 ;
unsigned long V_18 = F_5 ( V_12 ,
F_6 ( V_14 ) ) ;
struct V_19 * V_20 ;
int V_21 ;
F_7 ( V_22 , L_1 V_23 L_2 , V_18 , F_8 ( V_12 ) ) ;
V_8 = F_9 ( V_10 , V_18 , V_24 , ( void * ) V_12 ) ;
if ( V_8 )
return V_8 ;
V_21 = F_10 ( V_14 , & V_17 ) ;
if ( V_21 )
return F_11 ( V_21 ) ;
V_20 = F_12 ( sizeof( * V_20 ) , V_25 ) ;
if ( ! V_20 )
return F_11 ( - V_26 ) ;
V_20 -> V_27 = * V_12 ;
V_20 -> V_28 = V_17 ;
V_20 -> V_29 = V_30 ;
V_21 = F_13 ( V_14 -> V_31 , V_20 , & V_16 ) ;
F_14 ( V_20 ) ;
if ( V_21 ) {
F_7 ( V_22 , L_3 V_23 L_4 ,
F_8 ( V_12 ) , V_21 ) ;
return F_11 ( V_21 ) ;
}
V_21 = F_15 ( & V_8 , V_16 , V_10 , NULL ) ;
F_16 ( V_16 ) ;
if ( V_21 )
return F_11 ( V_21 ) ;
return V_8 ;
}
static struct V_32 *
F_17 ( struct V_9 * V_10 , struct V_11 * V_12 , struct V_11 * V_33 )
{
struct V_8 * V_8 ;
struct V_32 * V_34 ;
if ( ! F_18 ( V_12 ) )
return F_11 ( - V_35 ) ;
F_7 ( V_22 , L_5 V_23 L_6 , F_8 ( V_12 ) ) ;
V_8 = F_3 ( V_10 , V_12 ) ;
if ( F_19 ( V_8 ) )
return F_20 ( V_8 ) ;
if ( F_21 ( V_8 ) ) {
F_22 ( V_8 ) ;
return F_11 ( - V_35 ) ;
}
V_34 = F_23 ( V_8 ) ;
if ( F_19 ( V_34 ) ) {
F_22 ( V_8 ) ;
return V_34 ;
}
if ( V_33 ) {
struct V_36 * V_37 = F_24 ( V_8 ) ;
F_25 ( & V_37 -> V_38 ) ;
V_37 -> V_39 = * V_33 ;
F_26 ( & V_37 -> V_38 ) ;
}
V_34 = F_23 ( V_8 ) ;
if ( ! F_19 ( V_34 ) ) {
F_27 ( V_34 ) -> V_40 = 1 ;
}
return V_34 ;
}
static int F_28 ( struct V_8 * V_8 , T_1 * V_41 , int * V_42 ,
struct V_8 * V_33 )
{
int V_43 = sizeof( struct V_44 ) / 4 ;
struct V_44 * V_45 = ( void * ) V_41 ;
F_7 ( V_22 , L_7 V_23 L_8 ,
F_29 ( V_8 -> V_46 , NULL , 0 ) ,
F_8 ( F_30 ( V_8 ) ) , * V_42 , V_43 ) ;
if ( * V_42 < V_43 ) {
* V_42 = V_43 ;
return V_47 ;
}
V_45 -> V_48 = * F_30 ( V_8 ) ;
if ( V_33 )
V_45 -> V_49 = * F_30 ( V_33 ) ;
else
F_31 ( & V_45 -> V_49 ) ;
* V_42 = V_43 ;
return V_50 ;
}
static int F_32 ( struct V_51 * V_52 , const char * V_1 ,
int V_53 , T_4 V_18 , T_5 V_54 ,
unsigned int type )
{
struct V_55 * V_56 = F_33 ( V_1 , struct V_55 , V_57 ) ;
struct V_58 * V_59 =
F_34 ( V_52 , struct V_58 , V_52 ) ;
struct V_11 V_12 ;
F_35 ( & V_12 , & V_56 -> V_60 ) ;
if ( F_36 ( & V_12 , & V_59 -> V_61 ) ) {
memcpy ( V_59 -> V_62 , V_1 , V_53 ) ;
V_59 -> V_62 [ V_53 ] = 0 ;
V_59 -> V_63 = 1 ;
}
return V_59 -> V_63 ;
}
static int F_37 ( struct V_32 * V_32 , char * V_1 ,
struct V_32 * V_64 )
{
struct V_8 * V_65 = F_38 ( V_32 ) ;
int V_21 ;
struct V_58 V_59 = {
. V_62 = V_1 ,
. V_61 = F_24 ( F_38 ( V_64 ) ) -> V_66 ,
. V_52 . V_67 = F_32 ,
} ;
struct V_19 * V_20 ;
T_3 V_68 = 0 ;
if ( ! V_65 || ! F_39 ( V_65 -> V_69 ) ) {
V_21 = - V_70 ;
goto V_71;
}
if ( ! V_65 -> V_72 ) {
V_21 = - V_73 ;
goto V_71;
}
V_20 = F_40 ( NULL , V_65 , V_65 , NULL , 0 , 0 ,
V_74 , V_65 ) ;
if ( F_19 ( V_20 ) ) {
V_21 = F_41 ( V_20 ) ;
goto V_71;
}
V_20 -> V_75 = F_42 ( V_65 ) -> V_76 ;
F_43 ( V_65 ) ;
V_21 = F_44 ( V_65 , & V_68 , V_20 , & V_59 . V_52 ) ;
F_45 ( V_65 ) ;
F_46 ( V_20 ) ;
if ( ! V_21 && ! V_59 . V_63 )
V_21 = - V_77 ;
V_71:
return V_21 ;
}
static struct V_32 * F_47 ( struct V_9 * V_10 , struct V_12 * V_12 ,
int V_78 , int V_79 )
{
struct V_44 * V_45 = (struct V_44 * ) V_12 ;
if ( V_79 != V_50 )
return F_11 ( - V_80 ) ;
return F_17 ( V_10 , & V_45 -> V_48 , & V_45 -> V_49 ) ;
}
static struct V_32 * F_48 ( struct V_9 * V_10 , struct V_12 * V_12 ,
int V_78 , int V_79 )
{
struct V_44 * V_45 = (struct V_44 * ) V_12 ;
if ( V_79 != V_50 )
return F_11 ( - V_80 ) ;
return F_17 ( V_10 , & V_45 -> V_49 , NULL ) ;
}
int F_49 ( struct V_8 * V_65 , struct V_11 * V_81 )
{
struct V_15 * V_16 = NULL ;
struct V_13 * V_14 ;
struct V_82 * V_83 ;
static const char V_84 [] = L_9 ;
struct V_19 * V_20 ;
int V_21 ;
int V_85 ;
F_50 ( V_65 && F_39 ( V_65 -> V_69 ) ) ;
V_14 = F_4 ( V_65 -> V_46 ) ;
F_7 ( V_22 , L_10 V_23 L_2 ,
F_29 ( V_65 -> V_46 , NULL , 0 ) ,
F_8 ( F_30 ( V_65 ) ) ) ;
V_21 = F_10 ( V_14 , & V_85 ) ;
if ( V_21 != 0 )
return V_21 ;
V_20 = F_40 ( NULL , V_65 , NULL , V_84 ,
strlen ( V_84 ) , V_85 ,
V_74 , NULL ) ;
if ( F_19 ( V_20 ) )
return F_41 ( V_20 ) ;
V_21 = F_51 ( V_14 -> V_31 , V_20 , & V_16 ) ;
F_46 ( V_20 ) ;
if ( V_21 ) {
F_52 ( L_11 V_23 L_12 ,
F_29 ( V_65 -> V_46 , NULL , 0 ) ,
F_8 ( F_30 ( V_65 ) ) , V_21 ) ;
return V_21 ;
}
V_83 = F_53 ( & V_16 -> V_86 , & V_87 ) ;
if ( V_83 -> V_88 & V_89 ) {
F_7 ( V_22 , L_13 V_23 L_14 V_23 L_6 ,
F_8 ( F_30 ( V_65 ) ) , F_8 ( & V_83 -> V_90 ) ) ;
* V_81 = V_83 -> V_90 ;
}
F_16 ( V_16 ) ;
return 0 ;
}
static struct V_32 * F_54 ( struct V_32 * V_91 )
{
struct V_11 V_81 = { 0 } ;
struct V_32 * V_32 ;
int V_21 ;
V_21 = F_49 ( V_91 -> F_38 , & V_81 ) ;
if ( V_21 )
return F_11 ( V_21 ) ;
V_32 = F_17 ( V_91 -> F_38 -> V_46 , & V_81 , NULL ) ;
return V_32 ;
}
