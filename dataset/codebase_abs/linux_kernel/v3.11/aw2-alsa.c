static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_7 >= 0 )
F_3 ( V_4 -> V_7 , ( void * ) V_4 ) ;
if ( V_4 -> V_8 )
F_4 ( V_4 -> V_8 ) ;
F_5 ( V_4 -> V_9 ) ;
F_6 ( V_4 -> V_9 ) ;
F_7 ( V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_10 * V_11 ,
struct V_12 * V_9 , struct V_3 * * V_13 )
{
struct V_3 * V_4 ;
int V_14 ;
static struct V_15 V_16 = {
. V_17 = F_1 ,
} ;
* V_13 = NULL ;
V_14 = F_9 ( V_9 ) ;
if ( V_14 < 0 )
return V_14 ;
F_10 ( V_9 ) ;
if ( ( F_11 ( V_9 , F_12 ( 32 ) ) < 0 ) ||
( F_13 ( V_9 , F_12 ( 32 ) ) < 0 ) ) {
F_14 ( V_18 L_1 ) ;
F_6 ( V_9 ) ;
return - V_19 ;
}
V_4 = F_15 ( sizeof( * V_4 ) , V_20 ) ;
if ( V_4 == NULL ) {
F_6 ( V_9 ) ;
return - V_21 ;
}
V_4 -> V_11 = V_11 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_7 = - 1 ;
V_14 = F_16 ( V_9 , L_2 ) ;
if ( V_14 < 0 ) {
F_6 ( V_9 ) ;
F_7 ( V_4 ) ;
return V_14 ;
}
V_4 -> V_22 = F_17 ( V_9 , 0 ) ;
V_4 -> V_8 =
F_18 ( V_4 -> V_22 ,
F_19 ( V_9 , 0 ) ) ;
if ( V_4 -> V_8 == NULL ) {
F_14 ( V_18 L_3 ) ;
F_5 ( V_9 ) ;
F_6 ( V_9 ) ;
F_7 ( V_4 ) ;
return - V_21 ;
}
F_20 ( & V_4 -> V_6 , V_4 -> V_8 ) ;
if ( F_21 ( V_9 -> V_7 , V_23 ,
V_24 , V_25 , V_4 ) ) {
F_14 ( V_18 L_4 , V_9 -> V_7 ) ;
F_4 ( V_4 -> V_8 ) ;
F_5 ( V_4 -> V_9 ) ;
F_6 ( V_4 -> V_9 ) ;
F_7 ( V_4 ) ;
return - V_26 ;
}
V_4 -> V_7 = V_9 -> V_7 ;
V_14 = F_22 ( V_11 , V_27 , V_4 , & V_16 ) ;
if ( V_14 < 0 ) {
F_3 ( V_4 -> V_7 , ( void * ) V_4 ) ;
F_4 ( V_4 -> V_8 ) ;
F_5 ( V_4 -> V_9 ) ;
F_6 ( V_4 -> V_9 ) ;
F_7 ( V_4 ) ;
return V_14 ;
}
F_23 ( V_11 , & V_9 -> V_28 ) ;
* V_13 = V_4 ;
F_14 ( V_29
L_5
L_6 ) ;
return 0 ;
}
static int F_24 ( struct V_12 * V_9 ,
const struct V_30 * V_31 )
{
static int V_28 ;
struct V_10 * V_11 ;
struct V_3 * V_4 ;
int V_14 ;
if ( V_28 >= V_32 )
return - V_33 ;
if ( ! V_34 [ V_28 ] ) {
V_28 ++ ;
return - V_35 ;
}
V_14 = F_25 ( V_36 [ V_28 ] , V_37 [ V_28 ] , V_38 , 0 , & V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_8 ( V_11 , V_9 , & V_4 ) ;
if ( V_14 < 0 ) {
F_26 ( V_11 ) ;
return V_14 ;
}
F_27 ( & V_4 -> V_39 ) ;
F_28 ( & V_4 -> V_40 ) ;
strcpy ( V_11 -> V_41 , L_7 ) ;
strcpy ( V_11 -> V_42 , L_2 ) ;
sprintf ( V_11 -> V_43 , L_8 ,
V_11 -> V_42 , V_4 -> V_7 ) ;
F_29 ( V_4 ) ;
V_14 = F_30 ( V_11 ) ;
if ( V_14 < 0 ) {
F_26 ( V_11 ) ;
return V_14 ;
}
F_31 ( V_9 , V_11 ) ;
V_28 ++ ;
return 0 ;
}
static void F_32 ( struct V_12 * V_9 )
{
F_26 ( F_33 ( V_9 ) ) ;
}
static int F_34 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = V_45 -> V_47 ;
F_35 ( V_48 L_9 ) ;
V_47 -> V_49 = V_50 ;
return 0 ;
}
static int F_36 ( struct V_44 * V_45 )
{
return 0 ;
}
static int F_37 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = V_45 -> V_47 ;
F_35 ( V_48 L_10 ) ;
V_47 -> V_49 = V_51 ;
return 0 ;
}
static int F_38 ( struct V_44 * V_45 )
{
return 0 ;
}
static int F_39 ( struct V_44 * V_45 ,
struct V_52 * V_53 )
{
return F_40 ( V_45 ,
F_41 ( V_53 ) ) ;
}
static int F_42 ( struct V_44 * V_45 )
{
return F_43 ( V_45 ) ;
}
static int F_44 ( struct V_44 * V_45 )
{
struct V_54 * V_55 = F_45 ( V_45 ) ;
struct V_3 * V_4 = V_55 -> V_4 ;
struct V_46 * V_47 = V_45 -> V_47 ;
unsigned long V_56 , V_57 ;
F_46 ( & V_4 -> V_39 ) ;
V_56 = F_47 ( V_45 ) ;
V_57 = F_48 ( V_45 ) ;
F_49 ( & V_4 -> V_6 ,
V_55 -> V_58 ,
V_47 -> V_59 , V_56 ,
V_57 ) ;
F_50 ( V_55 -> V_58 ,
( V_60 )
V_61 ,
( void * ) V_45 ) ;
F_51 ( & V_4 -> V_39 ) ;
return 0 ;
}
static int F_52 ( struct V_44 * V_45 )
{
struct V_54 * V_55 = F_45 ( V_45 ) ;
struct V_3 * V_4 = V_55 -> V_4 ;
struct V_46 * V_47 = V_45 -> V_47 ;
unsigned long V_56 , V_57 ;
F_46 ( & V_4 -> V_39 ) ;
V_56 = F_47 ( V_45 ) ;
V_57 = F_48 ( V_45 ) ;
F_53 ( & V_4 -> V_6 ,
V_55 -> V_58 ,
V_47 -> V_59 , V_56 ,
V_57 ) ;
F_54 ( V_55 -> V_58 ,
( V_60 )
V_61 ,
( void * ) V_45 ) ;
F_51 ( & V_4 -> V_39 ) ;
return 0 ;
}
static int F_55 ( struct V_44 * V_45 ,
int V_62 )
{
int V_63 = 0 ;
struct V_54 * V_55 = F_45 ( V_45 ) ;
struct V_3 * V_4 = V_55 -> V_4 ;
F_56 ( & V_4 -> V_40 ) ;
switch ( V_62 ) {
case V_64 :
F_57 ( & V_4 -> V_6 ,
V_55 ->
V_58 ) ;
break;
case V_65 :
F_58 ( & V_4 -> V_6 ,
V_55 ->
V_58 ) ;
break;
default:
V_63 = - V_66 ;
}
F_59 ( & V_4 -> V_40 ) ;
return V_63 ;
}
static int F_60 ( struct V_44 * V_45 ,
int V_62 )
{
int V_63 = 0 ;
struct V_54 * V_55 = F_45 ( V_45 ) ;
struct V_3 * V_4 = V_55 -> V_4 ;
F_56 ( & V_4 -> V_40 ) ;
switch ( V_62 ) {
case V_64 :
F_61 ( & V_4 -> V_6 ,
V_55 ->
V_58 ) ;
break;
case V_65 :
F_62 ( & V_4 -> V_6 ,
V_55 ->
V_58 ) ;
break;
default:
V_63 = - V_66 ;
}
F_59 ( & V_4 -> V_40 ) ;
return V_63 ;
}
static T_1 F_63 ( struct V_44
* V_45 )
{
struct V_54 * V_55 = F_45 ( V_45 ) ;
struct V_3 * V_4 = V_55 -> V_4 ;
unsigned int V_67 ;
struct V_46 * V_47 = V_45 -> V_47 ;
V_67 =
F_64 ( & V_4 -> V_6 ,
V_55 -> V_58 ,
V_47 -> V_68 ,
V_47 -> V_57 ) ;
return F_65 ( V_45 -> V_47 , V_67 ) ;
}
static T_1 F_66 ( struct V_44
* V_45 )
{
struct V_54 * V_55 = F_45 ( V_45 ) ;
struct V_3 * V_4 = V_55 -> V_4 ;
unsigned int V_67 ;
struct V_46 * V_47 = V_45 -> V_47 ;
V_67 =
F_67 ( & V_4 -> V_6 ,
V_55 -> V_58 ,
V_47 -> V_68 ,
V_47 -> V_57 ) ;
return F_65 ( V_45 -> V_47 , V_67 ) ;
}
static int F_29 ( struct V_3 * V_4 )
{
struct V_69 * V_70 ;
struct V_69 * V_71 ;
struct V_69 * V_72 ;
struct V_54 * V_55 ;
int V_14 = 0 ;
V_14 = F_68 ( V_4 -> V_11 , L_11 , 0 , 1 , 0 ,
& V_70 ) ;
if ( V_14 < 0 ) {
F_14 ( V_18 L_12 , V_14 ) ;
return V_14 ;
}
V_55 = & V_4 -> V_73 [ V_74 ] ;
strcpy ( V_70 -> V_75 , L_13 ) ;
V_70 -> V_76 = V_55 ;
F_69 ( V_70 , V_77 ,
& V_78 ) ;
V_55 -> V_79 = V_70 ;
V_55 -> V_4 = V_4 ;
V_55 -> V_58 = V_74 ;
V_14 = F_70 ( V_70 ,
V_80 ,
F_71
( V_4 -> V_9 ) ,
64 * 1024 , 64 * 1024 ) ;
if ( V_14 )
F_14 ( V_18 L_14
L_15 , V_14 ) ;
V_14 = F_68 ( V_4 -> V_11 , L_16 , 1 , 1 , 0 ,
& V_71 ) ;
if ( V_14 < 0 ) {
F_14 ( V_18 L_12 , V_14 ) ;
return V_14 ;
}
V_55 = & V_4 -> V_73 [ V_81 ] ;
strcpy ( V_71 -> V_75 , L_17 ) ;
V_71 -> V_76 = V_55 ;
F_69 ( V_71 , V_77 ,
& V_78 ) ;
V_55 -> V_79 = V_71 ;
V_55 -> V_4 = V_4 ;
V_55 -> V_58 = V_81 ;
V_14 = F_70 ( V_71 ,
V_80 ,
F_71
( V_4 -> V_9 ) ,
64 * 1024 , 64 * 1024 ) ;
if ( V_14 )
F_14 ( V_18
L_18
L_19 , V_14 ) ;
V_14 = F_68 ( V_4 -> V_11 , L_20 , 2 , 0 , 1 ,
& V_72 ) ;
if ( V_14 < 0 ) {
F_14 ( V_18 L_12 , V_14 ) ;
return V_14 ;
}
V_55 = & V_4 -> V_82 [ V_83 ] ;
strcpy ( V_72 -> V_75 , L_21 ) ;
V_72 -> V_76 = V_55 ;
F_69 ( V_72 , V_84 ,
& V_85 ) ;
V_55 -> V_79 = V_72 ;
V_55 -> V_4 = V_4 ;
V_55 -> V_58 = V_83 ;
V_14 = F_70 ( V_72 ,
V_80 ,
F_71
( V_4 -> V_9 ) ,
64 * 1024 , 64 * 1024 ) ;
if ( V_14 )
F_14 ( V_18
L_18
L_19 , V_14 ) ;
V_14 = F_72 ( V_4 -> V_11 , F_73 ( & V_86 , V_4 ) ) ;
if ( V_14 < 0 ) {
F_14 ( V_18 L_22 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_74 ( struct V_87 * V_88 ,
struct V_89 * V_90 )
{
static char * V_91 [ 2 ] = {
L_23 , L_24
} ;
V_90 -> type = V_92 ;
V_90 -> V_93 = 1 ;
V_90 -> V_94 . V_95 . V_96 = 2 ;
if ( V_90 -> V_94 . V_95 . V_97 >= V_90 -> V_94 . V_95 . V_96 ) {
V_90 -> V_94 . V_95 . V_97 =
V_90 -> V_94 . V_95 . V_96 - 1 ;
}
strcpy ( V_90 -> V_94 . V_95 . V_75 ,
V_91 [ V_90 -> V_94 . V_95 . V_97 ] ) ;
return 0 ;
}
static int F_75 ( struct V_87 * V_88 ,
struct V_98
* V_99 )
{
struct V_3 * V_4 = F_76 ( V_88 ) ;
if ( F_77 ( & V_4 -> V_6 ) )
V_99 -> V_94 . V_95 . V_97 [ 0 ] = V_100 ;
else
V_99 -> V_94 . V_95 . V_97 [ 0 ] = V_101 ;
return 0 ;
}
static int F_78 ( struct V_87 * V_88 ,
struct V_98
* V_99 )
{
struct V_3 * V_4 = F_76 ( V_88 ) ;
int V_102 = 0 ;
int V_103 =
F_77 ( & V_4 -> V_6 ) ;
if ( ( ( V_99 -> V_94 . integer . V_94 [ 0 ] == V_100 )
&& ! V_103 )
|| ( ( V_99 -> V_94 . integer . V_94 [ 0 ] == V_101 )
&& V_103 ) ) {
F_79 ( & V_4 -> V_6 , ! V_103 ) ;
V_102 = 1 ;
}
return V_102 ;
}
