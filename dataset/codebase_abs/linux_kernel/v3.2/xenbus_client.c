const char * F_1 ( enum V_1 V_2 )
{
static const char * const V_3 [] = {
[ V_4 ] = L_1 ,
[ V_5 ] = L_2 ,
[ V_6 ] = L_3 ,
[ V_7 ] = L_4 ,
[ V_8 ] = L_5 ,
[ V_9 ] = L_6 ,
[ V_10 ] = L_7 ,
[ V_11 ] = L_8 ,
[ V_12 ] = L_9 ,
} ;
return ( V_2 < F_2 ( V_3 ) ) ? V_3 [ V_2 ] : L_10 ;
}
int F_3 ( struct V_13 * V_14 , const char * V_15 ,
struct V_16 * V_17 ,
void (* F_4)( struct V_16 * ,
const char * * , unsigned int ) )
{
int V_18 ;
V_17 -> V_19 = V_15 ;
V_17 -> F_4 = F_4 ;
V_18 = F_5 ( V_17 ) ;
if ( V_18 ) {
V_17 -> V_19 = NULL ;
V_17 -> F_4 = NULL ;
F_6 ( V_14 , V_18 , L_11 , V_15 ) ;
}
return V_18 ;
}
int F_7 ( struct V_13 * V_14 ,
struct V_16 * V_17 ,
void (* F_4)( struct V_16 * ,
const char * * , unsigned int ) ,
const char * V_20 , ... )
{
int V_18 ;
T_1 V_21 ;
char * V_15 ;
va_start ( V_21 , V_20 ) ;
V_15 = F_8 ( V_22 | V_23 , V_20 , V_21 ) ;
va_end ( V_21 ) ;
if ( ! V_15 ) {
F_6 ( V_14 , - V_24 , L_12 ) ;
return - V_24 ;
}
V_18 = F_3 ( V_14 , V_15 , V_17 , F_4 ) ;
if ( V_18 )
F_9 ( V_15 ) ;
return V_18 ;
}
static int
F_10 ( struct V_13 * V_14 ,
enum V_1 V_2 , int V_25 )
{
struct V_26 V_27 ;
int V_28 ;
int V_18 , abort ;
if ( V_2 == V_14 -> V_2 )
return 0 ;
V_29:
abort = 1 ;
V_18 = F_11 ( & V_27 ) ;
if ( V_18 ) {
F_12 ( V_14 , V_25 , V_18 , L_13 ) ;
return 0 ;
}
V_18 = F_13 ( V_27 , V_14 -> V_30 , L_14 , L_15 , & V_28 ) ;
if ( V_18 != 1 )
goto abort;
V_18 = F_14 ( V_27 , V_14 -> V_30 , L_14 , L_15 , V_2 ) ;
if ( V_18 ) {
F_12 ( V_14 , V_25 , V_18 , L_16 ) ;
goto abort;
}
abort = 0 ;
abort:
V_18 = F_15 ( V_27 , abort ) ;
if ( V_18 ) {
if ( V_18 == - V_31 && ! abort )
goto V_29;
F_12 ( V_14 , V_25 , V_18 , L_17 ) ;
} else
V_14 -> V_2 = V_2 ;
return 0 ;
}
int F_16 ( struct V_13 * V_14 , enum V_1 V_2 )
{
return F_10 ( V_14 , V_2 , 0 ) ;
}
int F_17 ( struct V_13 * V_14 )
{
F_16 ( V_14 , V_10 ) ;
F_18 ( & V_14 -> V_32 ) ;
return 0 ;
}
static char * F_19 ( struct V_13 * V_14 )
{
return F_20 ( V_33 , L_18 , V_14 -> V_30 ) ;
}
static void F_21 ( struct V_13 * V_14 , int V_18 ,
const char * V_34 , T_1 V_21 )
{
int V_35 ;
unsigned int V_36 ;
char * V_37 = NULL ;
char * V_38 = NULL ;
#define F_22 4096
V_37 = F_23 ( F_22 , V_33 ) ;
if ( V_37 == NULL )
goto V_39;
V_36 = sprintf ( V_37 , L_19 , - V_18 ) ;
V_35 = vsnprintf ( V_37 + V_36 , F_22 - V_36 , V_34 , V_21 ) ;
F_24 ( V_36 + V_35 > F_22 - 1 ) ;
F_25 ( & V_14 -> V_14 , L_20 , V_37 ) ;
V_38 = F_19 ( V_14 ) ;
if ( V_38 == NULL ) {
F_25 ( & V_14 -> V_14 , L_21 ,
V_14 -> V_30 , V_37 ) ;
goto V_39;
}
if ( F_26 ( V_40 , V_38 , L_22 , V_37 ) != 0 ) {
F_25 ( & V_14 -> V_14 , L_21 ,
V_14 -> V_30 , V_37 ) ;
goto V_39;
}
V_39:
F_9 ( V_37 ) ;
F_9 ( V_38 ) ;
}
void F_27 ( struct V_13 * V_14 , int V_18 , const char * V_34 , ... )
{
T_1 V_21 ;
va_start ( V_21 , V_34 ) ;
F_21 ( V_14 , V_18 , V_34 , V_21 ) ;
va_end ( V_21 ) ;
}
void F_6 ( struct V_13 * V_14 , int V_18 , const char * V_34 , ... )
{
T_1 V_21 ;
va_start ( V_21 , V_34 ) ;
F_21 ( V_14 , V_18 , V_34 , V_21 ) ;
va_end ( V_21 ) ;
F_16 ( V_14 , V_9 ) ;
}
static void F_12 ( struct V_13 * V_14 , int V_25 , int V_18 ,
const char * V_34 , ... )
{
T_1 V_21 ;
va_start ( V_21 , V_34 ) ;
F_21 ( V_14 , V_18 , V_34 , V_21 ) ;
va_end ( V_21 ) ;
if ( ! V_25 )
F_10 ( V_14 , V_9 , 1 ) ;
}
int F_28 ( struct V_13 * V_14 , unsigned long V_41 )
{
int V_18 = F_29 ( V_14 -> V_42 , V_41 , 0 ) ;
if ( V_18 < 0 )
F_6 ( V_14 , V_18 , L_23 ) ;
return V_18 ;
}
int F_30 ( struct V_13 * V_14 , int * V_43 )
{
struct V_44 V_45 ;
int V_18 ;
V_45 . V_46 = V_47 ;
V_45 . V_48 = V_14 -> V_42 ;
V_18 = F_31 ( V_49 ,
& V_45 ) ;
if ( V_18 )
F_6 ( V_14 , V_18 , L_24 ) ;
else
* V_43 = V_45 . V_43 ;
return V_18 ;
}
int F_32 ( struct V_13 * V_14 , int V_50 , int * V_43 )
{
struct V_51 V_52 ;
int V_18 ;
V_52 . V_48 = V_14 -> V_42 ;
V_52 . V_50 = V_50 ;
V_18 = F_31 ( V_53 ,
& V_52 ) ;
if ( V_18 )
F_6 ( V_14 , V_18 ,
L_25 ,
V_50 , V_14 -> V_42 ) ;
else
* V_43 = V_52 . V_54 ;
return V_18 ;
}
int F_33 ( struct V_13 * V_14 , int V_43 )
{
struct V_55 V_56 ;
int V_18 ;
V_56 . V_43 = V_43 ;
V_18 = F_31 ( V_57 , & V_56 ) ;
if ( V_18 )
F_27 ( V_14 , V_18 , L_26 , V_43 ) ;
return V_18 ;
}
int F_34 ( struct V_13 * V_14 , int V_58 , void * * V_59 )
{
struct V_60 V_61 = {
. V_62 = V_63 | V_64 ,
. V_65 = V_58 ,
. V_46 = V_14 -> V_42 ,
} ;
struct V_66 * V_67 ;
T_2 * V_68 ;
* V_59 = NULL ;
V_67 = F_35 ( V_69 , & V_68 ) ;
if ( ! V_67 )
return - V_24 ;
V_61 . V_70 = F_36 ( V_68 ) . V_71 ;
if ( F_37 ( V_72 , & V_61 , 1 ) )
F_38 () ;
if ( V_61 . V_73 != V_74 ) {
F_39 ( V_67 ) ;
F_6 ( V_14 , V_61 . V_73 ,
L_27 ,
V_58 , V_14 -> V_42 ) ;
return V_61 . V_73 ;
}
V_67 -> V_75 = ( unsigned long ) V_61 . V_76 ;
* V_59 = V_67 -> V_77 ;
return 0 ;
}
int F_40 ( struct V_13 * V_14 , int V_58 ,
T_3 * V_76 , void * V_59 )
{
struct V_60 V_61 = {
. V_70 = ( unsigned long ) V_59 ,
. V_62 = V_63 ,
. V_65 = V_58 ,
. V_46 = V_14 -> V_42 ,
} ;
if ( F_37 ( V_72 , & V_61 , 1 ) )
F_38 () ;
if ( V_61 . V_73 != V_74 ) {
F_6 ( V_14 , V_61 . V_73 ,
L_27 ,
V_58 , V_14 -> V_42 ) ;
} else
* V_76 = V_61 . V_76 ;
return V_61 . V_73 ;
}
int F_41 ( struct V_13 * V_14 , void * V_59 )
{
struct V_66 * V_67 ;
struct V_78 V_61 = {
. V_70 = ( unsigned long ) V_59 ,
} ;
unsigned int V_79 ;
F_42 ( & V_80 ) ;
for ( V_67 = V_81 ; V_67 != NULL ; V_67 = V_67 -> V_82 ) {
if ( V_67 -> V_77 == V_59 )
break;
}
F_43 ( & V_80 ) ;
if ( ! V_67 ) {
F_27 ( V_14 , - V_83 ,
L_28 , V_59 ) ;
return V_84 ;
}
V_61 . V_76 = ( T_3 ) V_67 -> V_75 ;
V_61 . V_70 = F_36 (
F_44 ( ( unsigned long ) V_59 , & V_79 ) ) . V_71 ;
if ( F_37 ( V_85 , & V_61 , 1 ) )
F_38 () ;
if ( V_61 . V_73 == V_74 )
F_39 ( V_67 ) ;
else
F_27 ( V_14 , V_61 . V_73 ,
L_29 ,
( V_86 ) V_67 -> V_75 , V_61 . V_73 ) ;
return V_61 . V_73 ;
}
int F_45 ( struct V_13 * V_14 ,
T_3 V_76 , void * V_59 )
{
struct V_78 V_61 = {
. V_70 = ( unsigned long ) V_59 ,
. V_76 = V_76 ,
} ;
if ( F_37 ( V_85 , & V_61 , 1 ) )
F_38 () ;
if ( V_61 . V_73 != V_74 )
F_27 ( V_14 , V_61 . V_73 ,
L_29 ,
V_76 , V_61 . V_73 ) ;
return V_61 . V_73 ;
}
enum V_1 F_46 ( const char * V_15 )
{
enum V_1 V_87 ;
int V_18 = F_47 ( V_40 , V_15 , L_14 , L_15 , & V_87 , NULL ) ;
if ( V_18 )
V_87 = V_4 ;
return V_87 ;
}
