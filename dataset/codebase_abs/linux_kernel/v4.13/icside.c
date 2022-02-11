static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( 0 , V_5 -> V_7 + V_8 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_4 ( V_5 -> V_7 + V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void T_1 * V_9 = V_5 -> V_7 ;
V_5 -> V_10 = 1 ;
switch ( V_5 -> V_11 ) {
case 0 :
F_2 ( 0 , V_9 + V_12 ) ;
F_4 ( V_9 + V_13 ) ;
break;
case 1 :
F_2 ( 0 , V_9 + V_13 ) ;
F_4 ( V_9 + V_12 ) ;
break;
}
}
static void F_6 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
V_5 -> V_10 = 0 ;
F_4 ( V_5 -> V_7 + V_12 ) ;
F_4 ( V_5 -> V_7 + V_13 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return F_4 ( V_5 -> V_7 + V_14 ) & 1 ||
F_4 ( V_5 -> V_7 + V_15 ) & 1 ;
}
static void F_8 ( T_2 * V_16 , int V_17 )
{
T_3 * V_18 = V_16 -> V_18 ;
struct V_1 * V_2 = F_9 ( V_18 -> V_19 ) ;
struct V_4 * V_5 = F_10 ( V_2 ) ;
unsigned long V_20 ;
F_11 ( V_20 ) ;
V_5 -> V_11 = V_18 -> V_11 ;
if ( V_5 -> V_10 && ! V_17 ) {
switch ( V_18 -> V_11 ) {
case 0 :
F_2 ( 0 , V_5 -> V_7 + V_12 ) ;
F_4 ( V_5 -> V_7 + V_13 ) ;
break;
case 1 :
F_2 ( 0 , V_5 -> V_7 + V_13 ) ;
F_4 ( V_5 -> V_7 + V_12 ) ;
break;
}
} else {
F_4 ( V_5 -> V_7 + V_13 ) ;
F_4 ( V_5 -> V_7 + V_12 ) ;
}
F_12 ( V_20 ) ;
}
static void F_13 ( T_3 * V_18 , T_2 * V_16 )
{
unsigned long V_21 = 0 ;
int V_22 = 0 ;
const T_4 V_23 = V_16 -> V_24 ;
switch ( V_23 ) {
case V_25 :
V_21 = 250 ;
V_22 = 1 ;
break;
case V_26 :
V_21 = 250 ;
V_22 = 1 ;
break;
case V_27 :
V_21 = 480 ;
break;
case V_28 :
case V_29 :
case V_30 :
V_21 = 480 ;
break;
}
if ( V_22 && V_16 -> V_31 [ V_32 ] > V_21 )
V_21 = V_16 -> V_31 [ V_32 ] ;
F_14 ( V_16 , ( void * ) V_21 ) ;
F_15 ( V_33 L_1 ,
V_16 -> V_34 , F_16 ( V_23 ) ,
2000 / ( V_21 ? V_21 : ( unsigned long ) - 1 ) ) ;
}
static void F_17 ( T_2 * V_16 , int V_35 )
{
}
static int F_18 ( T_2 * V_16 )
{
T_3 * V_18 = V_16 -> V_18 ;
struct V_1 * V_2 = F_9 ( V_18 -> V_19 ) ;
F_19 ( V_2 -> V_36 ) ;
return F_20 ( V_2 -> V_36 ) != 0 ;
}
static void F_21 ( T_2 * V_16 )
{
T_3 * V_18 = V_16 -> V_18 ;
struct V_1 * V_2 = F_9 ( V_18 -> V_19 ) ;
F_22 ( F_23 ( V_2 -> V_36 ) ) ;
F_24 ( V_2 -> V_36 ) ;
}
static int F_25 ( T_2 * V_16 , struct V_37 * V_38 )
{
T_3 * V_18 = V_16 -> V_18 ;
struct V_1 * V_2 = F_9 ( V_18 -> V_19 ) ;
struct V_4 * V_5 = F_10 ( V_2 ) ;
unsigned int V_24 ;
if ( V_38 -> V_39 & V_40 )
V_24 = V_41 ;
else
V_24 = V_42 ;
F_22 ( F_23 ( V_2 -> V_36 ) ) ;
F_8 ( V_16 , 0 ) ;
F_2 ( V_5 -> V_43 | V_18 -> V_11 , V_5 -> V_44 ) ;
F_26 ( V_2 -> V_36 , ( unsigned long ) F_27 ( V_16 ) ) ;
F_28 ( V_2 -> V_36 , V_18 -> V_45 , V_38 -> V_46 ) ;
F_29 ( V_2 -> V_36 , V_24 ) ;
return 0 ;
}
static int F_30 ( T_2 * V_16 )
{
T_3 * V_18 = V_16 -> V_18 ;
struct V_1 * V_2 = F_9 ( V_18 -> V_19 ) ;
struct V_4 * V_5 = F_10 ( V_2 ) ;
return F_4 ( V_5 -> V_7 +
( V_18 -> V_11 ?
V_15 :
V_14 ) ) & 1 ;
}
static int F_31 ( T_3 * V_18 , const struct V_47 * V_48 )
{
V_18 -> V_49 = NULL ;
V_18 -> V_50 = 0 ;
return 0 ;
}
static int F_32 ( T_3 * V_18 , const struct V_47 * V_48 )
{
return - V_51 ;
}
static void F_33 ( struct V_52 * V_53 , void T_1 * V_9 ,
struct V_54 * V_55 , struct V_1 * V_2 )
{
unsigned long V_56 = ( unsigned long ) V_9 + V_55 -> V_57 ;
V_53 -> V_58 . V_59 = V_56 ;
V_53 -> V_58 . V_60 = V_56 + ( 1 << V_55 -> V_61 ) ;
V_53 -> V_58 . V_62 = V_56 + ( 2 << V_55 -> V_61 ) ;
V_53 -> V_58 . V_63 = V_56 + ( 3 << V_55 -> V_61 ) ;
V_53 -> V_58 . V_64 = V_56 + ( 4 << V_55 -> V_61 ) ;
V_53 -> V_58 . V_65 = V_56 + ( 5 << V_55 -> V_61 ) ;
V_53 -> V_58 . V_66 = V_56 + ( 6 << V_55 -> V_61 ) ;
V_53 -> V_58 . V_67 = V_56 + ( 7 << V_55 -> V_61 ) ;
V_53 -> V_58 . V_68 = ( unsigned long ) V_9 + V_55 -> V_69 ;
V_53 -> V_70 = V_2 -> V_70 ;
V_53 -> V_19 = & V_2 -> V_19 ;
}
static int F_34 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
void T_1 * V_9 ;
struct V_71 * V_72 ;
struct V_52 V_53 , * V_73 [] = { & V_53 } ;
int V_74 ;
V_9 = F_35 ( V_2 , V_75 , 0 , 0 ) ;
if ( ! V_9 )
return - V_76 ;
V_5 -> V_7 = V_9 ;
V_2 -> V_77 = V_9 + V_78 ;
V_2 -> V_79 = 1 ;
F_36 ( V_2 , & V_80 , V_5 ) ;
F_3 ( V_2 , 0 ) ;
F_33 ( & V_53 , V_9 , & V_81 , V_2 ) ;
V_72 = F_37 ( & V_82 , V_73 , 1 ) ;
if ( V_72 == NULL )
return - V_83 ;
V_5 -> V_72 = V_72 ;
F_38 ( V_2 , V_5 ) ;
V_74 = F_39 ( V_72 , & V_82 , V_73 ) ;
if ( V_74 )
goto V_84;
return 0 ;
V_84:
F_40 ( V_72 ) ;
F_38 ( V_2 , NULL ) ;
return V_74 ;
}
static int F_41 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
void T_1 * V_44 , * V_85 ;
struct V_71 * V_72 ;
unsigned int V_43 = 0 ;
int V_74 ;
struct V_52 V_53 [ 2 ] , * V_73 [] = { & V_53 [ 0 ] , & V_53 [ 1 ] } ;
struct V_47 V_48 = V_86 ;
V_44 = F_35 ( V_2 , V_87 , 0 , 0 ) ;
if ( ! V_44 ) {
V_74 = - V_76 ;
goto V_88;
}
V_85 = V_44 ;
if ( F_42 ( V_2 , V_89 ) ) {
V_85 = F_35 ( V_2 , V_89 , 0 , 0 ) ;
if ( ! V_85 ) {
V_74 = - V_76 ;
goto V_88;
}
V_43 = 1 << 5 ;
}
F_2 ( V_43 , V_44 ) ;
F_36 ( V_2 , & V_90 , V_5 ) ;
V_5 -> V_7 = V_85 ;
V_5 -> V_44 = V_44 ;
V_5 -> V_43 = V_43 ;
F_6 ( V_2 , 0 ) ;
F_33 ( & V_53 [ 0 ] , V_85 , & V_91 , V_2 ) ;
F_33 ( & V_53 [ 1 ] , V_85 , & V_92 , V_2 ) ;
V_72 = F_37 ( & V_48 , V_73 , 2 ) ;
if ( V_72 == NULL )
return - V_83 ;
V_5 -> V_72 = V_72 ;
F_38 ( V_2 , V_5 ) ;
#ifdef F_43
if ( V_2 -> V_36 != V_93 && ! F_44 ( V_2 -> V_36 , V_94 ) ) {
V_48 . V_95 = F_31 ;
V_48 . V_96 = & V_97 ;
V_48 . V_98 = & V_99 ;
}
#endif
V_74 = F_39 ( V_72 , & V_48 , V_73 ) ;
if ( V_74 )
goto V_84;
return 0 ;
V_84:
F_40 ( V_72 ) ;
if ( V_48 . V_98 )
F_45 ( V_2 -> V_36 ) ;
F_38 ( V_2 , NULL ) ;
V_88:
return V_74 ;
}
static int F_46 ( struct V_1 * V_2 , const struct V_100 * V_31 )
{
struct V_4 * V_5 ;
void T_1 * V_101 ;
int V_74 ;
V_74 = F_47 ( V_2 ) ;
if ( V_74 )
goto V_88;
V_5 = F_48 ( sizeof( struct V_4 ) , V_102 ) ;
if ( ! V_5 ) {
V_74 = - V_76 ;
goto V_103;
}
V_5 -> type = V_104 ;
V_101 = F_35 ( V_2 , V_87 , 0 , 0 ) ;
if ( V_101 ) {
unsigned int type ;
type = F_4 ( V_101 + V_105 ) & 1 ;
type |= ( F_4 ( V_101 + V_105 + 4 ) & 1 ) << 1 ;
type |= ( F_4 ( V_101 + V_105 + 8 ) & 1 ) << 2 ;
type |= ( F_4 ( V_101 + V_105 + 12 ) & 1 ) << 3 ;
F_49 ( V_2 , V_101 ) ;
V_5 -> type = type ;
}
switch ( V_5 -> type ) {
case V_106 :
F_50 ( & V_2 -> V_19 , L_2 ) ;
V_74 = - V_83 ;
break;
case V_107 :
F_50 ( & V_2 -> V_19 , L_3 ) ;
V_74 = - V_83 ;
break;
case V_108 :
V_74 = F_34 ( V_5 , V_2 ) ;
break;
case V_109 :
V_74 = F_41 ( V_5 , V_2 ) ;
break;
default:
F_50 ( & V_2 -> V_19 , L_4 ) ;
V_74 = - V_83 ;
break;
}
if ( V_74 == 0 )
goto V_88;
F_51 ( V_5 ) ;
V_103:
F_52 ( V_2 ) ;
V_88:
return V_74 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_10 ( V_2 ) ;
switch ( V_5 -> type ) {
case V_108 :
F_3 ( V_2 , 0 ) ;
break;
case V_109 :
if ( V_2 -> V_36 != V_93 )
F_45 ( V_2 -> V_36 ) ;
F_6 ( V_2 , 0 ) ;
F_2 ( 0 , V_5 -> V_44 ) ;
break;
}
F_38 ( V_2 , NULL ) ;
F_51 ( V_5 ) ;
F_52 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_10 ( V_2 ) ;
unsigned long V_20 ;
F_11 ( V_20 ) ;
V_2 -> V_110 -> V_111 ( V_2 , 0 ) ;
F_12 ( V_20 ) ;
if ( V_5 -> V_44 )
F_2 ( 0 , V_5 -> V_44 ) ;
}
static int T_5 F_55 ( void )
{
return F_56 ( & V_112 ) ;
}
static void T_6 F_57 ( void )
{
F_58 ( & V_112 ) ;
}
