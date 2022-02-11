static int T_1 F_1 ( void )
{
F_2 ( V_1 L_1 ) ;
return F_3 ( & V_2 ) ;
}
static void T_2 F_4 ( void )
{
F_2 ( V_1 L_2 ) ;
F_5 ( & V_2 ) ;
}
static int F_6 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
F_7 ( & V_6 -> V_8 ) ;
if ( V_6 -> V_9 >= 0 )
F_8 ( V_6 -> V_9 , ( void * ) V_6 ) ;
if ( V_6 -> V_10 )
F_9 ( V_6 -> V_10 ) ;
F_10 ( V_6 -> V_11 ) ;
F_11 ( V_6 -> V_11 ) ;
F_12 ( V_6 ) ;
return 0 ;
}
static int T_3 F_13 ( struct V_12 * V_13 ,
struct V_14 * V_11 , struct V_5 * * V_15 )
{
struct V_5 * V_6 ;
int V_16 ;
static struct V_17 V_18 = {
. V_19 = F_6 ,
} ;
* V_15 = NULL ;
V_16 = F_14 ( V_11 ) ;
if ( V_16 < 0 )
return V_16 ;
F_15 ( V_11 ) ;
if ( ( F_16 ( V_11 , F_17 ( 32 ) ) < 0 ) ||
( F_18 ( V_11 , F_17 ( 32 ) ) < 0 ) ) {
F_19 ( V_20 L_3 ) ;
F_11 ( V_11 ) ;
return - V_21 ;
}
V_6 = F_20 ( sizeof( * V_6 ) , V_22 ) ;
if ( V_6 == NULL ) {
F_11 ( V_11 ) ;
return - V_23 ;
}
V_6 -> V_13 = V_13 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_9 = - 1 ;
V_16 = F_21 ( V_11 , L_4 ) ;
if ( V_16 < 0 ) {
F_11 ( V_11 ) ;
F_12 ( V_6 ) ;
return V_16 ;
}
V_6 -> V_24 = F_22 ( V_11 , 0 ) ;
V_6 -> V_10 =
F_23 ( V_6 -> V_24 ,
F_24 ( V_11 , 0 ) ) ;
if ( V_6 -> V_10 == NULL ) {
F_19 ( V_20 L_5 ) ;
F_10 ( V_11 ) ;
F_11 ( V_11 ) ;
F_12 ( V_6 ) ;
return - V_23 ;
}
F_25 ( & V_6 -> V_8 , V_6 -> V_10 ) ;
if ( F_26 ( V_11 -> V_9 , V_25 ,
V_26 , L_4 , V_6 ) ) {
F_19 ( V_20 L_6 , V_11 -> V_9 ) ;
F_9 ( V_6 -> V_10 ) ;
F_10 ( V_6 -> V_11 ) ;
F_11 ( V_6 -> V_11 ) ;
F_12 ( V_6 ) ;
return - V_27 ;
}
V_6 -> V_9 = V_11 -> V_9 ;
V_16 = F_27 ( V_13 , V_28 , V_6 , & V_18 ) ;
if ( V_16 < 0 ) {
F_8 ( V_6 -> V_9 , ( void * ) V_6 ) ;
F_9 ( V_6 -> V_10 ) ;
F_10 ( V_6 -> V_11 ) ;
F_11 ( V_6 -> V_11 ) ;
F_12 ( V_6 ) ;
return V_16 ;
}
F_28 ( V_13 , & V_11 -> V_29 ) ;
* V_15 = V_6 ;
F_19 ( V_30
L_7
L_8 ) ;
return 0 ;
}
static int T_3 F_29 ( struct V_14 * V_11 ,
const struct V_31 * V_32 )
{
static int V_29 ;
struct V_12 * V_13 ;
struct V_5 * V_6 ;
int V_16 ;
if ( V_29 >= V_33 )
return - V_34 ;
if ( ! V_35 [ V_29 ] ) {
V_29 ++ ;
return - V_36 ;
}
V_16 = F_30 ( V_37 [ V_29 ] , V_38 [ V_29 ] , V_39 , 0 , & V_13 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_13 ( V_13 , V_11 , & V_6 ) ;
if ( V_16 < 0 ) {
F_31 ( V_13 ) ;
return V_16 ;
}
F_32 ( & V_6 -> V_40 ) ;
F_33 ( & V_6 -> V_41 ) ;
strcpy ( V_13 -> V_2 , L_9 ) ;
strcpy ( V_13 -> V_42 , L_4 ) ;
sprintf ( V_13 -> V_43 , L_10 ,
V_13 -> V_42 , V_6 -> V_9 ) ;
F_34 ( V_6 ) ;
V_16 = F_35 ( V_13 ) ;
if ( V_16 < 0 ) {
F_31 ( V_13 ) ;
return V_16 ;
}
F_36 ( V_11 , V_13 ) ;
V_29 ++ ;
return 0 ;
}
static void T_4 F_37 ( struct V_14 * V_11 )
{
F_31 ( F_38 ( V_11 ) ) ;
F_36 ( V_11 , NULL ) ;
}
static int F_39 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = V_45 -> V_47 ;
F_2 ( V_1 L_11 ) ;
V_47 -> V_48 = V_49 ;
return 0 ;
}
static int F_40 ( struct V_44 * V_45 )
{
return 0 ;
}
static int F_41 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = V_45 -> V_47 ;
F_2 ( V_1 L_12 ) ;
V_47 -> V_48 = V_50 ;
return 0 ;
}
static int F_42 ( struct V_44 * V_45 )
{
return 0 ;
}
static int F_43 ( struct V_44 * V_45 ,
struct V_51 * V_52 )
{
return F_44 ( V_45 ,
F_45 ( V_52 ) ) ;
}
static int F_46 ( struct V_44 * V_45 )
{
return F_47 ( V_45 ) ;
}
static int F_48 ( struct V_44 * V_45 )
{
struct V_53 * V_54 = F_49 ( V_45 ) ;
struct V_5 * V_6 = V_54 -> V_6 ;
struct V_46 * V_47 = V_45 -> V_47 ;
unsigned long V_55 , V_56 ;
F_50 ( & V_6 -> V_40 ) ;
V_55 = F_51 ( V_45 ) ;
V_56 = F_52 ( V_45 ) ;
F_53 ( & V_6 -> V_8 ,
V_54 -> V_57 ,
V_47 -> V_58 , V_55 ,
V_56 ) ;
F_54 ( V_54 -> V_57 ,
( V_59 )
V_60 ,
( void * ) V_45 ) ;
F_55 ( & V_6 -> V_40 ) ;
return 0 ;
}
static int F_56 ( struct V_44 * V_45 )
{
struct V_53 * V_54 = F_49 ( V_45 ) ;
struct V_5 * V_6 = V_54 -> V_6 ;
struct V_46 * V_47 = V_45 -> V_47 ;
unsigned long V_55 , V_56 ;
F_50 ( & V_6 -> V_40 ) ;
V_55 = F_51 ( V_45 ) ;
V_56 = F_52 ( V_45 ) ;
F_57 ( & V_6 -> V_8 ,
V_54 -> V_57 ,
V_47 -> V_58 , V_55 ,
V_56 ) ;
F_58 ( V_54 -> V_57 ,
( V_59 )
V_60 ,
( void * ) V_45 ) ;
F_55 ( & V_6 -> V_40 ) ;
return 0 ;
}
static int F_59 ( struct V_44 * V_45 ,
int V_61 )
{
int V_62 = 0 ;
struct V_53 * V_54 = F_49 ( V_45 ) ;
struct V_5 * V_6 = V_54 -> V_6 ;
F_60 ( & V_6 -> V_41 ) ;
switch ( V_61 ) {
case V_63 :
F_61 ( & V_6 -> V_8 ,
V_54 ->
V_57 ) ;
break;
case V_64 :
F_62 ( & V_6 -> V_8 ,
V_54 ->
V_57 ) ;
break;
default:
V_62 = - V_65 ;
}
F_63 ( & V_6 -> V_41 ) ;
return V_62 ;
}
static int F_64 ( struct V_44 * V_45 ,
int V_61 )
{
int V_62 = 0 ;
struct V_53 * V_54 = F_49 ( V_45 ) ;
struct V_5 * V_6 = V_54 -> V_6 ;
F_60 ( & V_6 -> V_41 ) ;
switch ( V_61 ) {
case V_63 :
F_65 ( & V_6 -> V_8 ,
V_54 ->
V_57 ) ;
break;
case V_64 :
F_66 ( & V_6 -> V_8 ,
V_54 ->
V_57 ) ;
break;
default:
V_62 = - V_65 ;
}
F_63 ( & V_6 -> V_41 ) ;
return V_62 ;
}
static T_5 F_67 ( struct V_44
* V_45 )
{
struct V_53 * V_54 = F_49 ( V_45 ) ;
struct V_5 * V_6 = V_54 -> V_6 ;
unsigned int V_66 ;
struct V_46 * V_47 = V_45 -> V_47 ;
V_66 =
F_68 ( & V_6 -> V_8 ,
V_54 -> V_57 ,
V_47 -> V_67 ,
V_47 -> V_56 ) ;
return F_69 ( V_45 -> V_47 , V_66 ) ;
}
static T_5 F_70 ( struct V_44
* V_45 )
{
struct V_53 * V_54 = F_49 ( V_45 ) ;
struct V_5 * V_6 = V_54 -> V_6 ;
unsigned int V_66 ;
struct V_46 * V_47 = V_45 -> V_47 ;
V_66 =
F_71 ( & V_6 -> V_8 ,
V_54 -> V_57 ,
V_47 -> V_67 ,
V_47 -> V_56 ) ;
return F_69 ( V_45 -> V_47 , V_66 ) ;
}
static int T_3 F_34 ( struct V_5 * V_6 )
{
struct V_68 * V_69 ;
struct V_68 * V_70 ;
struct V_68 * V_71 ;
struct V_53 * V_54 ;
int V_16 = 0 ;
V_16 = F_72 ( V_6 -> V_13 , L_13 , 0 , 1 , 0 ,
& V_69 ) ;
if ( V_16 < 0 ) {
F_19 ( V_20 L_14 , V_16 ) ;
return V_16 ;
}
V_54 = & V_6 -> V_72 [ V_73 ] ;
strcpy ( V_69 -> V_74 , L_15 ) ;
V_69 -> V_75 = V_54 ;
F_73 ( V_69 , V_76 ,
& V_77 ) ;
V_54 -> V_78 = V_69 ;
V_54 -> V_6 = V_6 ;
V_54 -> V_57 = V_73 ;
V_16 = F_74 ( V_69 ,
V_79 ,
F_75
( V_6 -> V_11 ) ,
64 * 1024 , 64 * 1024 ) ;
if ( V_16 )
F_19 ( V_20 L_16
L_17 , V_16 ) ;
V_16 = F_72 ( V_6 -> V_13 , L_18 , 1 , 1 , 0 ,
& V_70 ) ;
if ( V_16 < 0 ) {
F_19 ( V_20 L_14 , V_16 ) ;
return V_16 ;
}
V_54 = & V_6 -> V_72 [ V_80 ] ;
strcpy ( V_70 -> V_74 , L_19 ) ;
V_70 -> V_75 = V_54 ;
F_73 ( V_70 , V_76 ,
& V_77 ) ;
V_54 -> V_78 = V_70 ;
V_54 -> V_6 = V_6 ;
V_54 -> V_57 = V_80 ;
V_16 = F_74 ( V_70 ,
V_79 ,
F_75
( V_6 -> V_11 ) ,
64 * 1024 , 64 * 1024 ) ;
if ( V_16 )
F_19 ( V_20
L_20
L_21 , V_16 ) ;
V_16 = F_72 ( V_6 -> V_13 , L_22 , 2 , 0 , 1 ,
& V_71 ) ;
if ( V_16 < 0 ) {
F_19 ( V_20 L_14 , V_16 ) ;
return V_16 ;
}
V_54 = & V_6 -> V_81 [ V_82 ] ;
strcpy ( V_71 -> V_74 , L_23 ) ;
V_71 -> V_75 = V_54 ;
F_73 ( V_71 , V_83 ,
& V_84 ) ;
V_54 -> V_78 = V_71 ;
V_54 -> V_6 = V_6 ;
V_54 -> V_57 = V_82 ;
V_16 = F_74 ( V_71 ,
V_79 ,
F_75
( V_6 -> V_11 ) ,
64 * 1024 , 64 * 1024 ) ;
if ( V_16 )
F_19 ( V_20
L_20
L_21 , V_16 ) ;
V_16 = F_76 ( V_6 -> V_13 , F_77 ( & V_85 , V_6 ) ) ;
if ( V_16 < 0 ) {
F_19 ( V_20 L_24 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_78 ( struct V_86 * V_87 ,
struct V_88 * V_89 )
{
static char * V_90 [ 2 ] = {
L_25 , L_26
} ;
V_89 -> type = V_91 ;
V_89 -> V_92 = 1 ;
V_89 -> V_93 . V_94 . V_95 = 2 ;
if ( V_89 -> V_93 . V_94 . V_96 >= V_89 -> V_93 . V_94 . V_95 ) {
V_89 -> V_93 . V_94 . V_96 =
V_89 -> V_93 . V_94 . V_95 - 1 ;
}
strcpy ( V_89 -> V_93 . V_94 . V_74 ,
V_90 [ V_89 -> V_93 . V_94 . V_96 ] ) ;
return 0 ;
}
static int F_79 ( struct V_86 * V_87 ,
struct V_97
* V_98 )
{
struct V_5 * V_6 = F_80 ( V_87 ) ;
if ( F_81 ( & V_6 -> V_8 ) )
V_98 -> V_93 . V_94 . V_96 [ 0 ] = V_99 ;
else
V_98 -> V_93 . V_94 . V_96 [ 0 ] = V_100 ;
return 0 ;
}
static int F_82 ( struct V_86 * V_87 ,
struct V_97
* V_98 )
{
struct V_5 * V_6 = F_80 ( V_87 ) ;
int V_101 = 0 ;
int V_102 =
F_81 ( & V_6 -> V_8 ) ;
if ( ( ( V_98 -> V_93 . integer . V_93 [ 0 ] == V_99 )
&& ! V_102 )
|| ( ( V_98 -> V_93 . integer . V_93 [ 0 ] == V_100 )
&& V_102 ) ) {
F_83 ( & V_6 -> V_8 , ! V_102 ) ;
V_101 = 1 ;
}
return V_101 ;
}
