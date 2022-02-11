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
return V_35 ;
}
static int F_31 ( struct V_8 * V_8 , T_1 * V_43 , int * V_44 ,
struct V_8 * V_34 )
{
int V_45 = sizeof( struct V_46 ) / 4 ;
struct V_46 * V_47 = ( void * ) V_43 ;
F_10 ( V_24 , L_7 V_25 L_8 ,
F_32 ( V_8 -> V_48 , NULL , 0 ) ,
F_11 ( F_33 ( V_8 ) ) , * V_44 , V_45 ) ;
if ( * V_44 < V_45 ) {
* V_44 = V_45 ;
return V_49 ;
}
V_47 -> V_50 = * F_33 ( V_8 ) ;
if ( V_34 )
V_47 -> V_51 = * F_33 ( V_34 ) ;
else
F_34 ( & V_47 -> V_51 ) ;
* V_44 = V_45 ;
return V_52 ;
}
static int F_35 ( struct V_53 * V_54 , const char * V_1 ,
int V_55 , T_4 V_20 , T_5 V_56 ,
unsigned type )
{
struct V_57 * V_58 = F_36 ( V_1 , struct V_57 , V_59 ) ;
struct V_60 * V_61 =
F_37 ( V_54 , struct V_60 , V_54 ) ;
struct V_13 V_14 ;
F_38 ( & V_14 , & V_58 -> V_62 ) ;
if ( F_4 ( & V_14 , & V_61 -> V_63 ) ) {
memcpy ( V_61 -> V_64 , V_1 , V_55 ) ;
V_61 -> V_64 [ V_55 ] = 0 ;
V_61 -> V_65 = 1 ;
}
return V_61 -> V_65 ;
}
static int F_39 ( struct V_33 * V_33 , char * V_1 ,
struct V_33 * V_66 )
{
struct V_8 * V_67 = F_40 ( V_33 ) ;
int V_23 ;
struct V_60 V_61 = {
. V_64 = V_1 ,
. V_63 = F_5 ( F_40 ( V_66 ) ) -> V_10 ,
. V_54 . V_68 = F_35 ,
} ;
if ( ! V_67 || ! F_41 ( V_67 -> V_37 ) ) {
V_23 = - V_69 ;
goto V_70;
}
if ( ! V_67 -> V_71 ) {
V_23 = - V_72 ;
goto V_70;
}
F_42 ( V_67 ) ;
V_23 = F_43 ( V_67 , & V_61 . V_54 ) ;
F_44 ( V_67 ) ;
if ( ! V_23 && ! V_61 . V_65 )
V_23 = - V_73 ;
V_70:
return V_23 ;
}
static struct V_33 * F_45 ( struct V_11 * V_12 , struct V_14 * V_14 ,
int V_74 , int V_75 )
{
struct V_46 * V_47 = (struct V_46 * ) V_14 ;
if ( V_75 != V_52 )
return F_14 ( - V_76 ) ;
return F_20 ( V_12 , & V_47 -> V_50 , & V_47 -> V_51 ) ;
}
static struct V_33 * F_46 ( struct V_11 * V_12 , struct V_14 * V_14 ,
int V_74 , int V_75 )
{
struct V_46 * V_47 = (struct V_46 * ) V_14 ;
if ( V_75 != V_52 )
return F_14 ( - V_76 ) ;
return F_20 ( V_12 , & V_47 -> V_51 , NULL ) ;
}
static struct V_33 * F_47 ( struct V_33 * V_77 )
{
struct V_17 * V_18 = NULL ;
struct V_8 * V_67 = F_40 ( V_77 ) ;
struct V_15 * V_16 ;
struct V_33 * V_35 = NULL ;
struct V_78 * V_79 ;
static char V_80 [] = L_9 ;
struct V_21 * V_22 ;
int V_23 ;
int V_81 ;
F_48 ( V_67 && F_41 ( V_67 -> V_37 ) ) ;
V_16 = F_7 ( V_67 -> V_48 ) ;
F_10 ( V_24 , L_10 V_25 L_2 ,
F_32 ( V_67 -> V_48 , NULL , 0 ) ,
F_11 ( F_33 ( V_67 ) ) ) ;
V_23 = F_13 ( V_16 , & V_81 ) ;
if ( V_23 != 0 )
return F_14 ( V_23 ) ;
V_22 = F_49 ( NULL , V_67 , NULL , V_80 ,
strlen ( V_80 ) , V_81 ,
V_82 , NULL ) ;
if ( F_22 ( V_22 ) )
return ( void * ) V_22 ;
V_23 = F_50 ( V_16 -> V_32 , V_22 , & V_18 ) ;
F_51 ( V_22 ) ;
if ( V_23 ) {
F_52 ( L_11 V_25 L_12 ,
F_32 ( V_67 -> V_48 , NULL , 0 ) ,
F_11 ( F_33 ( V_67 ) ) , V_23 ) ;
return F_14 ( V_23 ) ;
}
V_79 = F_53 ( & V_18 -> V_83 , & V_84 ) ;
if ( V_79 -> V_85 & V_86 ) {
F_10 ( V_24 , L_13 V_25 L_14 V_25 L_6 ,
F_11 ( F_33 ( V_67 ) ) , F_11 ( & V_79 -> V_87 ) ) ;
}
V_35 = F_20 ( V_67 -> V_48 , & V_79 -> V_87 , NULL ) ;
F_19 ( V_18 ) ;
return V_35 ;
}
