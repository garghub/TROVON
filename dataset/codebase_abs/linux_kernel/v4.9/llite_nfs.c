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
int V_21 ;
V_21 = F_27 ( V_34 ) ;
if ( V_21 < 0 ) {
F_28 ( V_34 ) ;
V_34 = F_11 ( V_21 ) ;
} else {
struct V_40 * V_41 = F_29 ( V_34 ) ;
V_41 -> V_42 = 1 ;
}
}
return V_34 ;
}
static int F_30 ( struct V_8 * V_8 , T_1 * V_43 , int * V_44 ,
struct V_8 * V_33 )
{
int V_45 = sizeof( struct V_46 ) / 4 ;
struct V_46 * V_47 = ( void * ) V_43 ;
F_7 ( V_22 , L_7 V_23 L_8 ,
F_31 ( V_8 -> V_48 , NULL , 0 ) ,
F_8 ( F_32 ( V_8 ) ) , * V_44 , V_45 ) ;
if ( * V_44 < V_45 ) {
* V_44 = V_45 ;
return V_49 ;
}
V_47 -> V_50 = * F_32 ( V_8 ) ;
if ( V_33 )
V_47 -> V_51 = * F_32 ( V_33 ) ;
else
F_33 ( & V_47 -> V_51 ) ;
* V_44 = V_45 ;
return V_52 ;
}
static int F_34 ( struct V_53 * V_54 , const char * V_1 ,
int V_55 , T_4 V_18 , T_5 V_56 ,
unsigned type )
{
struct V_57 * V_58 = F_35 ( V_1 , struct V_57 , V_59 ) ;
struct V_60 * V_61 =
F_36 ( V_54 , struct V_60 , V_54 ) ;
struct V_11 V_12 ;
F_37 ( & V_12 , & V_58 -> V_62 ) ;
if ( F_38 ( & V_12 , & V_61 -> V_63 ) ) {
memcpy ( V_61 -> V_64 , V_1 , V_55 ) ;
V_61 -> V_64 [ V_55 ] = 0 ;
V_61 -> V_65 = 1 ;
}
return V_61 -> V_65 ;
}
static int F_39 ( struct V_32 * V_32 , char * V_1 ,
struct V_32 * V_66 )
{
struct V_8 * V_67 = F_40 ( V_32 ) ;
int V_21 ;
struct V_60 V_61 = {
. V_64 = V_1 ,
. V_63 = F_24 ( F_40 ( V_66 ) ) -> V_68 ,
. V_54 . V_69 = F_34 ,
} ;
struct V_19 * V_20 ;
T_3 V_70 = 0 ;
if ( ! V_67 || ! F_41 ( V_67 -> V_71 ) ) {
V_21 = - V_72 ;
goto V_73;
}
if ( ! V_67 -> V_74 ) {
V_21 = - V_75 ;
goto V_73;
}
V_20 = F_42 ( NULL , V_67 , V_67 , NULL , 0 , 0 ,
V_76 , V_67 ) ;
if ( F_19 ( V_20 ) ) {
V_21 = F_43 ( V_20 ) ;
goto V_73;
}
V_20 -> V_77 = F_44 ( V_67 ) -> V_78 ;
F_45 ( V_67 ) ;
V_21 = F_46 ( V_67 , & V_70 , V_20 , & V_61 . V_54 ) ;
F_47 ( V_67 ) ;
F_48 ( V_20 ) ;
if ( ! V_21 && ! V_61 . V_65 )
V_21 = - V_79 ;
V_73:
return V_21 ;
}
static struct V_32 * F_49 ( struct V_9 * V_10 , struct V_12 * V_12 ,
int V_80 , int V_81 )
{
struct V_46 * V_47 = (struct V_46 * ) V_12 ;
if ( V_81 != V_52 )
return F_11 ( - V_82 ) ;
return F_17 ( V_10 , & V_47 -> V_50 , & V_47 -> V_51 ) ;
}
static struct V_32 * F_50 ( struct V_9 * V_10 , struct V_12 * V_12 ,
int V_80 , int V_81 )
{
struct V_46 * V_47 = (struct V_46 * ) V_12 ;
if ( V_81 != V_52 )
return F_11 ( - V_82 ) ;
return F_17 ( V_10 , & V_47 -> V_51 , NULL ) ;
}
int F_51 ( struct V_8 * V_67 , struct V_11 * V_83 )
{
struct V_15 * V_16 = NULL ;
struct V_13 * V_14 ;
struct V_84 * V_85 ;
static const char V_86 [] = L_9 ;
struct V_19 * V_20 ;
int V_21 ;
int V_87 ;
F_52 ( V_67 && F_41 ( V_67 -> V_71 ) ) ;
V_14 = F_4 ( V_67 -> V_48 ) ;
F_7 ( V_22 , L_10 V_23 L_2 ,
F_31 ( V_67 -> V_48 , NULL , 0 ) ,
F_8 ( F_32 ( V_67 ) ) ) ;
V_21 = F_10 ( V_14 , & V_87 ) ;
if ( V_21 != 0 )
return V_21 ;
V_20 = F_42 ( NULL , V_67 , NULL , V_86 ,
strlen ( V_86 ) , V_87 ,
V_76 , NULL ) ;
if ( F_19 ( V_20 ) )
return F_43 ( V_20 ) ;
V_21 = F_53 ( V_14 -> V_31 , V_20 , & V_16 ) ;
F_48 ( V_20 ) ;
if ( V_21 ) {
F_54 ( L_11 V_23 L_12 ,
F_31 ( V_67 -> V_48 , NULL , 0 ) ,
F_8 ( F_32 ( V_67 ) ) , V_21 ) ;
return V_21 ;
}
V_85 = F_55 ( & V_16 -> V_88 , & V_89 ) ;
if ( V_85 -> V_90 & V_91 ) {
F_7 ( V_22 , L_13 V_23 L_14 V_23 L_6 ,
F_8 ( F_32 ( V_67 ) ) , F_8 ( & V_85 -> V_92 ) ) ;
* V_83 = V_85 -> V_92 ;
}
F_16 ( V_16 ) ;
return 0 ;
}
static struct V_32 * F_56 ( struct V_32 * V_93 )
{
struct V_11 V_83 = { 0 } ;
struct V_32 * V_32 ;
int V_21 ;
V_21 = F_51 ( V_93 -> F_40 , & V_83 ) ;
if ( V_21 )
return F_11 ( V_21 ) ;
V_32 = F_17 ( V_93 -> F_40 -> V_48 , & V_83 , NULL ) ;
return V_32 ;
}
