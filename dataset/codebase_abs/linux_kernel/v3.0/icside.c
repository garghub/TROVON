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
unsigned long V_21 ;
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
F_15 ( L_1 , V_16 -> V_33 ,
F_16 ( V_23 ) ,
2000 / ( unsigned long ) F_17 ( V_16 ) ) ;
}
static void F_18 ( T_2 * V_16 , int V_34 )
{
}
static int F_19 ( T_2 * V_16 )
{
T_3 * V_18 = V_16 -> V_18 ;
struct V_1 * V_2 = F_9 ( V_18 -> V_19 ) ;
F_20 ( V_2 -> V_35 ) ;
return F_21 ( V_2 -> V_35 ) != 0 ;
}
static void F_22 ( T_2 * V_16 )
{
T_3 * V_18 = V_16 -> V_18 ;
struct V_1 * V_2 = F_9 ( V_18 -> V_19 ) ;
F_23 ( F_24 ( V_2 -> V_35 ) ) ;
F_25 ( V_2 -> V_35 ) ;
}
static int F_26 ( T_2 * V_16 , struct V_36 * V_37 )
{
T_3 * V_18 = V_16 -> V_18 ;
struct V_1 * V_2 = F_9 ( V_18 -> V_19 ) ;
struct V_4 * V_5 = F_10 ( V_2 ) ;
unsigned int V_24 ;
if ( V_37 -> V_38 & V_39 )
V_24 = V_40 ;
else
V_24 = V_41 ;
F_23 ( F_24 ( V_2 -> V_35 ) ) ;
F_8 ( V_16 , 0 ) ;
F_2 ( V_5 -> V_42 | V_18 -> V_11 , V_5 -> V_43 ) ;
F_27 ( V_2 -> V_35 , ( unsigned long ) F_17 ( V_16 ) ) ;
F_28 ( V_2 -> V_35 , V_18 -> V_44 , V_37 -> V_45 ) ;
F_29 ( V_2 -> V_35 , V_24 ) ;
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
static int F_31 ( T_3 * V_18 , const struct V_46 * V_47 )
{
V_18 -> V_48 = NULL ;
V_18 -> V_49 = 0 ;
return 0 ;
}
static int F_32 ( T_3 * V_18 , const struct V_46 * V_47 )
{
return - V_50 ;
}
static void F_33 ( struct V_51 * V_52 , void T_1 * V_9 ,
struct V_53 * V_54 , struct V_1 * V_2 )
{
unsigned long V_55 = ( unsigned long ) V_9 + V_54 -> V_56 ;
V_52 -> V_57 . V_58 = V_55 ;
V_52 -> V_57 . V_59 = V_55 + ( 1 << V_54 -> V_60 ) ;
V_52 -> V_57 . V_61 = V_55 + ( 2 << V_54 -> V_60 ) ;
V_52 -> V_57 . V_62 = V_55 + ( 3 << V_54 -> V_60 ) ;
V_52 -> V_57 . V_63 = V_55 + ( 4 << V_54 -> V_60 ) ;
V_52 -> V_57 . V_64 = V_55 + ( 5 << V_54 -> V_60 ) ;
V_52 -> V_57 . V_65 = V_55 + ( 6 << V_54 -> V_60 ) ;
V_52 -> V_57 . V_66 = V_55 + ( 7 << V_54 -> V_60 ) ;
V_52 -> V_57 . V_67 = ( unsigned long ) V_9 + V_54 -> V_68 ;
V_52 -> V_69 = V_2 -> V_69 ;
V_52 -> V_19 = & V_2 -> V_19 ;
}
static int T_5
F_34 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
void T_1 * V_9 ;
struct V_70 * V_71 ;
struct V_51 V_52 , * V_72 [] = { & V_52 } ;
int V_73 ;
V_9 = F_35 ( V_2 , V_74 , 0 , 0 ) ;
if ( ! V_9 )
return - V_75 ;
V_5 -> V_7 = V_9 ;
V_2 -> V_76 = V_9 + V_77 ;
V_2 -> V_78 = 1 ;
F_36 ( V_2 , & V_79 , V_5 ) ;
F_3 ( V_2 , 0 ) ;
F_33 ( & V_52 , V_9 , & V_80 , V_2 ) ;
V_71 = F_37 ( & V_81 , V_72 , 1 ) ;
if ( V_71 == NULL )
return - V_82 ;
V_5 -> V_71 = V_71 ;
F_38 ( V_2 , V_5 ) ;
V_73 = F_39 ( V_71 , & V_81 , V_72 ) ;
if ( V_73 )
goto V_83;
return 0 ;
V_83:
F_40 ( V_71 ) ;
F_38 ( V_2 , NULL ) ;
return V_73 ;
}
static int T_5
F_41 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
void T_1 * V_43 , * V_84 ;
struct V_70 * V_71 ;
unsigned int V_42 = 0 ;
int V_73 ;
struct V_51 V_52 [ 2 ] , * V_72 [] = { & V_52 [ 0 ] , & V_52 [ 1 ] } ;
struct V_46 V_47 = V_85 ;
V_43 = F_35 ( V_2 , V_86 , 0 , 0 ) ;
if ( ! V_43 ) {
V_73 = - V_75 ;
goto V_87;
}
V_84 = V_43 ;
if ( F_42 ( V_2 , V_88 ) ) {
V_84 = F_35 ( V_2 , V_88 , 0 , 0 ) ;
if ( ! V_84 ) {
V_73 = - V_75 ;
goto V_87;
}
V_42 = 1 << 5 ;
}
F_2 ( V_42 , V_43 ) ;
F_36 ( V_2 , & V_89 , V_5 ) ;
V_5 -> V_7 = V_84 ;
V_5 -> V_43 = V_43 ;
V_5 -> V_42 = V_42 ;
F_6 ( V_2 , 0 ) ;
F_33 ( & V_52 [ 0 ] , V_84 , & V_90 , V_2 ) ;
F_33 ( & V_52 [ 1 ] , V_84 , & V_91 , V_2 ) ;
V_71 = F_37 ( & V_47 , V_72 , 2 ) ;
if ( V_71 == NULL )
return - V_82 ;
V_5 -> V_71 = V_71 ;
F_38 ( V_2 , V_5 ) ;
if ( V_2 -> V_35 != V_92 && ! F_43 ( V_2 -> V_35 , V_93 ) ) {
V_47 . V_94 = F_31 ;
V_47 . V_95 = & V_96 ;
V_47 . V_97 = NULL ;
}
V_73 = F_39 ( V_71 , & V_47 , V_72 ) ;
if ( V_73 )
goto V_83;
return 0 ;
V_83:
F_40 ( V_71 ) ;
if ( V_47 . V_97 )
F_44 ( V_2 -> V_35 ) ;
F_38 ( V_2 , NULL ) ;
V_87:
return V_73 ;
}
static int T_5
F_45 ( struct V_1 * V_2 , const struct V_98 * V_31 )
{
struct V_4 * V_5 ;
void T_1 * V_99 ;
int V_73 ;
V_73 = F_46 ( V_2 ) ;
if ( V_73 )
goto V_87;
V_5 = F_47 ( sizeof( struct V_4 ) , V_100 ) ;
if ( ! V_5 ) {
V_73 = - V_75 ;
goto V_101;
}
V_5 -> type = V_102 ;
V_99 = F_35 ( V_2 , V_86 , 0 , 0 ) ;
if ( V_99 ) {
unsigned int type ;
type = F_4 ( V_99 + V_103 ) & 1 ;
type |= ( F_4 ( V_99 + V_103 + 4 ) & 1 ) << 1 ;
type |= ( F_4 ( V_99 + V_103 + 8 ) & 1 ) << 2 ;
type |= ( F_4 ( V_99 + V_103 + 12 ) & 1 ) << 3 ;
F_48 ( V_2 , V_99 ) ;
V_5 -> type = type ;
}
switch ( V_5 -> type ) {
case V_104 :
F_49 ( & V_2 -> V_19 , L_2 ) ;
V_73 = - V_82 ;
break;
case V_105 :
F_49 ( & V_2 -> V_19 , L_3 ) ;
V_73 = - V_82 ;
break;
case V_106 :
V_73 = F_34 ( V_5 , V_2 ) ;
break;
case V_107 :
V_73 = F_41 ( V_5 , V_2 ) ;
break;
default:
F_49 ( & V_2 -> V_19 , L_4 ) ;
V_73 = - V_82 ;
break;
}
if ( V_73 == 0 )
goto V_87;
F_50 ( V_5 ) ;
V_101:
F_51 ( V_2 ) ;
V_87:
return V_73 ;
}
static void T_6 F_52 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_10 ( V_2 ) ;
switch ( V_5 -> type ) {
case V_106 :
F_3 ( V_2 , 0 ) ;
break;
case V_107 :
if ( V_2 -> V_35 != V_92 )
F_44 ( V_2 -> V_35 ) ;
F_6 ( V_2 , 0 ) ;
F_2 ( 0 , V_5 -> V_43 ) ;
break;
}
F_38 ( V_2 , NULL ) ;
F_50 ( V_5 ) ;
F_51 ( V_2 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_10 ( V_2 ) ;
unsigned long V_20 ;
F_11 ( V_20 ) ;
V_2 -> V_108 -> V_109 ( V_2 , 0 ) ;
F_12 ( V_20 ) ;
if ( V_5 -> V_43 )
F_2 ( 0 , V_5 -> V_43 ) ;
}
static int T_7 F_54 ( void )
{
return F_55 ( & V_110 ) ;
}
static void T_8 F_56 ( void )
{
F_57 ( & V_110 ) ;
}
