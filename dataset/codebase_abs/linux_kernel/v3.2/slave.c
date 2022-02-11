static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_8 & ( 1 << V_3 ) )
return V_6 -> V_9 -> V_10 ( V_6 , V_3 , V_4 ) ;
return 0xffff ;
}
static int F_2 ( struct V_1 * V_2 , int V_3 , int V_4 , T_1 V_11 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_8 & ( 1 << V_3 ) )
return V_6 -> V_9 -> V_12 ( V_6 , V_3 , V_4 , V_11 ) ;
return 0 ;
}
void F_3 ( struct V_5 * V_6 )
{
V_6 -> V_13 -> V_7 = ( void * ) V_6 ;
V_6 -> V_13 -> V_14 = L_1 ;
V_6 -> V_13 -> V_15 = F_1 ;
V_6 -> V_13 -> V_16 = F_2 ;
snprintf ( V_6 -> V_13 -> V_17 , V_18 , L_2 ,
V_6 -> V_19 -> V_17 , V_6 -> V_20 -> V_21 ) ;
V_6 -> V_13 -> V_22 = & V_6 -> V_19 -> V_23 ;
}
static int F_4 ( struct V_24 * V_23 )
{
struct V_25 * V_26 = F_5 ( V_23 ) ;
V_23 -> V_27 = V_26 -> V_22 -> V_28 -> V_29 -> V_30 ;
return 0 ;
}
static int F_6 ( struct V_24 * V_23 )
{
struct V_25 * V_26 = F_5 ( V_23 ) ;
struct V_24 * V_31 = V_26 -> V_22 -> V_28 -> V_29 ;
int V_32 ;
if ( ! ( V_31 -> V_33 & V_34 ) )
return - V_35 ;
if ( F_7 ( V_23 -> V_36 , V_31 -> V_36 ) ) {
V_32 = F_8 ( V_31 , V_23 -> V_36 ) ;
if ( V_32 < 0 )
goto V_37;
}
if ( V_23 -> V_33 & V_38 ) {
V_32 = F_9 ( V_31 , 1 ) ;
if ( V_32 < 0 )
goto V_39;
}
if ( V_23 -> V_33 & V_40 ) {
V_32 = F_10 ( V_31 , 1 ) ;
if ( V_32 < 0 )
goto V_41;
}
return 0 ;
V_41:
if ( V_23 -> V_33 & V_38 )
F_9 ( V_31 , - 1 ) ;
V_39:
if ( F_7 ( V_23 -> V_36 , V_31 -> V_36 ) )
F_11 ( V_31 , V_23 -> V_36 ) ;
V_37:
return V_32 ;
}
static int F_12 ( struct V_24 * V_23 )
{
struct V_25 * V_26 = F_5 ( V_23 ) ;
struct V_24 * V_31 = V_26 -> V_22 -> V_28 -> V_29 ;
F_13 ( V_31 , V_23 ) ;
F_14 ( V_31 , V_23 ) ;
if ( V_23 -> V_33 & V_38 )
F_9 ( V_31 , - 1 ) ;
if ( V_23 -> V_33 & V_40 )
F_10 ( V_31 , - 1 ) ;
if ( F_7 ( V_23 -> V_36 , V_31 -> V_36 ) )
F_11 ( V_31 , V_23 -> V_36 ) ;
return 0 ;
}
static void F_15 ( struct V_24 * V_23 , int V_42 )
{
struct V_25 * V_26 = F_5 ( V_23 ) ;
struct V_24 * V_31 = V_26 -> V_22 -> V_28 -> V_29 ;
if ( V_42 & V_38 )
F_9 ( V_31 , V_23 -> V_33 & V_38 ? 1 : - 1 ) ;
if ( V_42 & V_40 )
F_10 ( V_31 , V_23 -> V_33 & V_40 ? 1 : - 1 ) ;
}
static void F_16 ( struct V_24 * V_23 )
{
struct V_25 * V_26 = F_5 ( V_23 ) ;
struct V_24 * V_31 = V_26 -> V_22 -> V_28 -> V_29 ;
F_17 ( V_31 , V_23 ) ;
F_18 ( V_31 , V_23 ) ;
}
static int F_19 ( struct V_24 * V_23 , void * V_43 )
{
struct V_25 * V_26 = F_5 ( V_23 ) ;
struct V_24 * V_31 = V_26 -> V_22 -> V_28 -> V_29 ;
struct V_44 * V_3 = V_43 ;
int V_32 ;
if ( ! F_20 ( V_3 -> V_45 ) )
return - V_46 ;
if ( ! ( V_23 -> V_33 & V_34 ) )
goto V_37;
if ( F_7 ( V_3 -> V_45 , V_31 -> V_36 ) ) {
V_32 = F_8 ( V_31 , V_3 -> V_45 ) ;
if ( V_32 < 0 )
return V_32 ;
}
if ( F_7 ( V_23 -> V_36 , V_31 -> V_36 ) )
F_11 ( V_31 , V_23 -> V_36 ) ;
V_37:
memcpy ( V_23 -> V_36 , V_3 -> V_45 , V_47 ) ;
return 0 ;
}
static int F_21 ( struct V_24 * V_23 , struct V_48 * V_49 , int V_50 )
{
struct V_25 * V_26 = F_5 ( V_23 ) ;
if ( V_26 -> V_51 != NULL )
return F_22 ( V_26 -> V_51 , V_49 , V_50 ) ;
return - V_52 ;
}
static int
F_23 ( struct V_24 * V_23 , struct V_53 * V_50 )
{
struct V_25 * V_26 = F_5 ( V_23 ) ;
int V_32 ;
V_32 = - V_52 ;
if ( V_26 -> V_51 != NULL ) {
V_32 = F_24 ( V_26 -> V_51 ) ;
if ( V_32 == 0 )
V_32 = F_25 ( V_26 -> V_51 , V_50 ) ;
}
return V_32 ;
}
static int
F_26 ( struct V_24 * V_23 , struct V_53 * V_50 )
{
struct V_25 * V_26 = F_5 ( V_23 ) ;
if ( V_26 -> V_51 != NULL )
return F_27 ( V_26 -> V_51 , V_50 ) ;
return - V_52 ;
}
static void F_28 ( struct V_24 * V_23 ,
struct V_54 * V_55 )
{
strncpy ( V_55 -> V_56 , L_3 , 32 ) ;
strncpy ( V_55 -> V_57 , V_58 , 32 ) ;
strncpy ( V_55 -> V_59 , L_4 , 32 ) ;
strncpy ( V_55 -> V_60 , L_5 , 32 ) ;
}
static int F_29 ( struct V_24 * V_23 )
{
struct V_25 * V_26 = F_5 ( V_23 ) ;
if ( V_26 -> V_51 != NULL )
return F_30 ( V_26 -> V_51 ) ;
return - V_52 ;
}
static T_2 F_31 ( struct V_24 * V_23 )
{
struct V_25 * V_26 = F_5 ( V_23 ) ;
if ( V_26 -> V_51 != NULL ) {
F_32 ( V_26 -> V_51 ) ;
return V_26 -> V_51 -> V_61 ;
}
return - V_52 ;
}
static void F_33 ( struct V_24 * V_23 ,
T_3 V_62 , T_4 * V_63 )
{
struct V_25 * V_26 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_26 -> V_22 ;
if ( V_62 == V_64 ) {
int V_65 = V_66 ;
strncpy ( V_63 , L_6 , V_65 ) ;
strncpy ( V_63 + V_65 , L_7 , V_65 ) ;
strncpy ( V_63 + 2 * V_65 , L_8 , V_65 ) ;
strncpy ( V_63 + 3 * V_65 , L_9 , V_65 ) ;
if ( V_6 -> V_9 -> V_67 != NULL )
V_6 -> V_9 -> V_67 ( V_6 , V_26 -> V_68 , V_63 + 4 * V_65 ) ;
}
}
static void F_34 ( struct V_24 * V_23 ,
struct V_69 * V_70 ,
T_5 * V_63 )
{
struct V_25 * V_26 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_26 -> V_22 ;
V_63 [ 0 ] = V_26 -> V_23 -> V_70 . V_71 ;
V_63 [ 1 ] = V_26 -> V_23 -> V_70 . V_72 ;
V_63 [ 2 ] = V_26 -> V_23 -> V_70 . V_73 ;
V_63 [ 3 ] = V_26 -> V_23 -> V_70 . V_74 ;
if ( V_6 -> V_9 -> V_75 != NULL )
V_6 -> V_9 -> V_75 ( V_6 , V_26 -> V_68 , V_63 + 4 ) ;
}
static int F_35 ( struct V_24 * V_23 , int V_76 )
{
struct V_25 * V_26 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_26 -> V_22 ;
if ( V_76 == V_64 ) {
int V_77 ;
V_77 = 4 ;
if ( V_6 -> V_9 -> V_78 != NULL )
V_77 += V_6 -> V_9 -> V_78 ( V_6 ) ;
return V_77 ;
}
return - V_52 ;
}
struct V_24 *
F_36 ( struct V_5 * V_6 , struct V_79 * V_22 ,
int V_68 , char * V_14 )
{
struct V_24 * V_31 = V_6 -> V_28 -> V_29 ;
struct V_24 * V_80 ;
struct V_25 * V_26 ;
int V_81 ;
V_80 = F_37 ( sizeof( struct V_25 ) ,
V_14 , V_82 ) ;
if ( V_80 == NULL )
return V_80 ;
V_80 -> V_83 = V_31 -> V_84 ;
F_38 ( V_80 , & V_85 ) ;
memcpy ( V_80 -> V_36 , V_31 -> V_36 , V_47 ) ;
V_80 -> V_86 = 0 ;
switch ( V_6 -> V_28 -> V_87 ) {
#ifdef F_39
case F_40 ( V_88 ) :
V_80 -> V_89 = & V_90 ;
break;
#endif
#ifdef F_41
case F_40 ( V_91 ) :
V_80 -> V_89 = & V_92 ;
break;
#endif
#ifdef F_42
case F_40 ( V_93 ) :
V_80 -> V_89 = & V_94 ;
break;
#endif
default:
F_43 () ;
}
F_44 ( V_80 , V_22 ) ;
V_80 -> V_84 = V_31 -> V_84 ;
V_26 = F_5 ( V_80 ) ;
V_26 -> V_23 = V_80 ;
V_26 -> V_22 = V_6 ;
V_26 -> V_68 = V_68 ;
V_26 -> V_51 = V_6 -> V_13 -> V_95 [ V_68 ] ;
V_81 = F_45 ( V_80 ) ;
if ( V_81 ) {
F_46 ( V_96 L_10 ,
V_31 -> V_14 , V_81 , V_80 -> V_14 ) ;
F_47 ( V_80 ) ;
return NULL ;
}
F_48 ( V_80 ) ;
if ( V_26 -> V_51 != NULL ) {
F_49 ( V_80 , F_50 ( & V_26 -> V_51 -> V_23 ) ,
0 , V_97 ) ;
V_26 -> V_51 -> V_98 = V_99 ;
V_26 -> V_51 -> V_100 = 0 ;
V_26 -> V_51 -> V_101 = 0 ;
V_26 -> V_51 -> V_102 = V_26 -> V_51 -> V_103 | V_104 ;
F_51 ( V_26 -> V_51 ) ;
}
return V_80 ;
}
