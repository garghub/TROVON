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
V_6 -> V_19 , V_6 -> V_20 -> V_21 ) ;
V_6 -> V_13 -> V_22 = & V_6 -> V_23 -> V_24 ;
}
static int F_4 ( struct V_25 * V_24 )
{
struct V_26 * V_27 = F_5 ( V_24 ) ;
V_24 -> V_28 = V_27 -> V_22 -> V_29 -> V_30 -> V_31 ;
return 0 ;
}
static int F_6 ( struct V_25 * V_24 )
{
struct V_26 * V_27 = F_5 ( V_24 ) ;
struct V_25 * V_32 = V_27 -> V_22 -> V_29 -> V_30 ;
int V_33 ;
if ( ! ( V_32 -> V_34 & V_35 ) )
return - V_36 ;
if ( ! F_7 ( V_24 -> V_37 , V_32 -> V_37 ) ) {
V_33 = F_8 ( V_32 , V_24 -> V_37 ) ;
if ( V_33 < 0 )
goto V_38;
}
if ( V_24 -> V_34 & V_39 ) {
V_33 = F_9 ( V_32 , 1 ) ;
if ( V_33 < 0 )
goto V_40;
}
if ( V_24 -> V_34 & V_41 ) {
V_33 = F_10 ( V_32 , 1 ) ;
if ( V_33 < 0 )
goto V_42;
}
return 0 ;
V_42:
if ( V_24 -> V_34 & V_39 )
F_9 ( V_32 , - 1 ) ;
V_40:
if ( ! F_7 ( V_24 -> V_37 , V_32 -> V_37 ) )
F_11 ( V_32 , V_24 -> V_37 ) ;
V_38:
return V_33 ;
}
static int F_12 ( struct V_25 * V_24 )
{
struct V_26 * V_27 = F_5 ( V_24 ) ;
struct V_25 * V_32 = V_27 -> V_22 -> V_29 -> V_30 ;
F_13 ( V_32 , V_24 ) ;
F_14 ( V_32 , V_24 ) ;
if ( V_24 -> V_34 & V_39 )
F_9 ( V_32 , - 1 ) ;
if ( V_24 -> V_34 & V_41 )
F_10 ( V_32 , - 1 ) ;
if ( ! F_7 ( V_24 -> V_37 , V_32 -> V_37 ) )
F_11 ( V_32 , V_24 -> V_37 ) ;
return 0 ;
}
static void F_15 ( struct V_25 * V_24 , int V_43 )
{
struct V_26 * V_27 = F_5 ( V_24 ) ;
struct V_25 * V_32 = V_27 -> V_22 -> V_29 -> V_30 ;
if ( V_43 & V_39 )
F_9 ( V_32 , V_24 -> V_34 & V_39 ? 1 : - 1 ) ;
if ( V_43 & V_41 )
F_10 ( V_32 , V_24 -> V_34 & V_41 ? 1 : - 1 ) ;
}
static void F_16 ( struct V_25 * V_24 )
{
struct V_26 * V_27 = F_5 ( V_24 ) ;
struct V_25 * V_32 = V_27 -> V_22 -> V_29 -> V_30 ;
F_17 ( V_32 , V_24 ) ;
F_18 ( V_32 , V_24 ) ;
}
static int F_19 ( struct V_25 * V_24 , void * V_44 )
{
struct V_26 * V_27 = F_5 ( V_24 ) ;
struct V_25 * V_32 = V_27 -> V_22 -> V_29 -> V_30 ;
struct V_45 * V_3 = V_44 ;
int V_33 ;
if ( ! F_20 ( V_3 -> V_46 ) )
return - V_47 ;
if ( ! ( V_24 -> V_34 & V_35 ) )
goto V_38;
if ( ! F_7 ( V_3 -> V_46 , V_32 -> V_37 ) ) {
V_33 = F_8 ( V_32 , V_3 -> V_46 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( ! F_7 ( V_24 -> V_37 , V_32 -> V_37 ) )
F_11 ( V_32 , V_24 -> V_37 ) ;
V_38:
F_21 ( V_24 -> V_37 , V_3 -> V_46 ) ;
return 0 ;
}
static int F_22 ( struct V_25 * V_24 , struct V_48 * V_49 , int V_50 )
{
struct V_26 * V_27 = F_5 ( V_24 ) ;
if ( V_27 -> V_51 != NULL )
return F_23 ( V_27 -> V_51 , V_49 , V_50 ) ;
return - V_52 ;
}
static int
F_24 ( struct V_25 * V_24 , struct V_53 * V_50 )
{
struct V_26 * V_27 = F_5 ( V_24 ) ;
int V_33 ;
V_33 = - V_52 ;
if ( V_27 -> V_51 != NULL ) {
V_33 = F_25 ( V_27 -> V_51 ) ;
if ( V_33 == 0 )
V_33 = F_26 ( V_27 -> V_51 , V_50 ) ;
}
return V_33 ;
}
static int
F_27 ( struct V_25 * V_24 , struct V_53 * V_50 )
{
struct V_26 * V_27 = F_5 ( V_24 ) ;
if ( V_27 -> V_51 != NULL )
return F_28 ( V_27 -> V_51 , V_50 ) ;
return - V_52 ;
}
static void F_29 ( struct V_25 * V_24 ,
struct V_54 * V_55 )
{
F_30 ( V_55 -> V_56 , L_3 , sizeof( V_55 -> V_56 ) ) ;
F_30 ( V_55 -> V_57 , V_58 , sizeof( V_55 -> V_57 ) ) ;
F_30 ( V_55 -> V_59 , L_4 , sizeof( V_55 -> V_59 ) ) ;
F_30 ( V_55 -> V_60 , L_5 , sizeof( V_55 -> V_60 ) ) ;
}
static int F_31 ( struct V_25 * V_24 )
{
struct V_26 * V_27 = F_5 ( V_24 ) ;
if ( V_27 -> V_51 != NULL )
return F_32 ( V_27 -> V_51 ) ;
return - V_52 ;
}
static T_2 F_33 ( struct V_25 * V_24 )
{
struct V_26 * V_27 = F_5 ( V_24 ) ;
if ( V_27 -> V_51 != NULL ) {
F_34 ( V_27 -> V_51 ) ;
return V_27 -> V_51 -> V_61 ;
}
return - V_52 ;
}
static void F_35 ( struct V_25 * V_24 ,
T_3 V_62 , T_4 * V_63 )
{
struct V_26 * V_27 = F_5 ( V_24 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_62 == V_64 ) {
int V_65 = V_66 ;
strncpy ( V_63 , L_6 , V_65 ) ;
strncpy ( V_63 + V_65 , L_7 , V_65 ) ;
strncpy ( V_63 + 2 * V_65 , L_8 , V_65 ) ;
strncpy ( V_63 + 3 * V_65 , L_9 , V_65 ) ;
if ( V_6 -> V_9 -> V_67 != NULL )
V_6 -> V_9 -> V_67 ( V_6 , V_27 -> V_68 , V_63 + 4 * V_65 ) ;
}
}
static void F_36 ( struct V_25 * V_24 ,
struct V_69 * V_70 ,
T_5 * V_63 )
{
struct V_26 * V_27 = F_5 ( V_24 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
V_63 [ 0 ] = V_27 -> V_24 -> V_70 . V_71 ;
V_63 [ 1 ] = V_27 -> V_24 -> V_70 . V_72 ;
V_63 [ 2 ] = V_27 -> V_24 -> V_70 . V_73 ;
V_63 [ 3 ] = V_27 -> V_24 -> V_70 . V_74 ;
if ( V_6 -> V_9 -> V_75 != NULL )
V_6 -> V_9 -> V_75 ( V_6 , V_27 -> V_68 , V_63 + 4 ) ;
}
static int F_37 ( struct V_25 * V_24 , int V_76 )
{
struct V_26 * V_27 = F_5 ( V_24 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_76 == V_64 ) {
int V_77 ;
V_77 = 4 ;
if ( V_6 -> V_9 -> V_78 != NULL )
V_77 += V_6 -> V_9 -> V_78 ( V_6 ) ;
return V_77 ;
}
return - V_52 ;
}
struct V_25 *
F_38 ( struct V_5 * V_6 , struct V_79 * V_22 ,
int V_68 , char * V_14 )
{
struct V_25 * V_32 = V_6 -> V_29 -> V_30 ;
struct V_25 * V_80 ;
struct V_26 * V_27 ;
int V_81 ;
V_80 = F_39 ( sizeof( struct V_26 ) , V_14 ,
V_82 , V_83 ) ;
if ( V_80 == NULL )
return V_80 ;
V_80 -> V_84 = V_32 -> V_85 ;
V_80 -> V_86 = & V_87 ;
F_40 ( V_80 , V_32 ) ;
V_80 -> V_88 = 0 ;
switch ( V_6 -> V_29 -> V_89 ) {
#ifdef F_41
case F_42 ( V_90 ) :
V_80 -> V_91 = & V_92 ;
break;
#endif
#ifdef F_43
case F_42 ( V_93 ) :
V_80 -> V_91 = & V_94 ;
break;
#endif
#ifdef F_44
case F_42 ( V_95 ) :
V_80 -> V_91 = & V_96 ;
break;
#endif
default:
F_45 () ;
}
F_46 ( V_80 , V_22 ) ;
V_80 -> V_85 = V_32 -> V_85 ;
V_27 = F_5 ( V_80 ) ;
V_27 -> V_24 = V_80 ;
V_27 -> V_22 = V_6 ;
V_27 -> V_68 = V_68 ;
V_27 -> V_51 = V_6 -> V_13 -> V_97 [ V_68 ] ;
V_81 = F_47 ( V_80 ) ;
if ( V_81 ) {
F_48 ( V_98 L_10 ,
V_32 -> V_14 , V_81 , V_80 -> V_14 ) ;
F_49 ( V_80 ) ;
return NULL ;
}
F_50 ( V_80 ) ;
if ( V_27 -> V_51 != NULL ) {
F_51 ( V_80 , F_52 ( & V_27 -> V_51 -> V_24 ) ,
V_99 ) ;
V_27 -> V_51 -> V_100 = V_101 ;
V_27 -> V_51 -> V_102 = 0 ;
V_27 -> V_51 -> V_103 = 0 ;
V_27 -> V_51 -> V_104 = V_27 -> V_51 -> V_105 | V_106 ;
F_53 ( V_27 -> V_51 ) ;
}
return V_80 ;
}
