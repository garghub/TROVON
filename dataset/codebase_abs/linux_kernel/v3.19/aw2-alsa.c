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
F_14 ( V_11 -> V_18 , L_1 ) ;
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
F_14 ( V_11 -> V_18 , L_3 ) ;
F_5 ( V_9 ) ;
F_6 ( V_9 ) ;
F_7 ( V_4 ) ;
return - V_21 ;
}
F_20 ( & V_4 -> V_6 , V_4 -> V_8 ) ;
if ( F_21 ( V_9 -> V_7 , V_23 ,
V_24 , V_25 , V_4 ) ) {
F_14 ( V_11 -> V_18 , L_4 , V_9 -> V_7 ) ;
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
* V_13 = V_4 ;
F_23 ( V_11 -> V_18 ,
L_5 ) ;
return 0 ;
}
static int F_24 ( struct V_12 * V_9 ,
const struct V_28 * V_29 )
{
static int V_18 ;
struct V_10 * V_11 ;
struct V_3 * V_4 ;
int V_14 ;
if ( V_18 >= V_30 )
return - V_31 ;
if ( ! V_32 [ V_18 ] ) {
V_18 ++ ;
return - V_33 ;
}
V_14 = F_25 ( & V_9 -> V_18 , V_34 [ V_18 ] , V_35 [ V_18 ] , V_36 ,
0 , & V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_8 ( V_11 , V_9 , & V_4 ) ;
if ( V_14 < 0 ) {
F_26 ( V_11 ) ;
return V_14 ;
}
F_27 ( & V_4 -> V_37 ) ;
F_28 ( & V_4 -> V_38 ) ;
strcpy ( V_11 -> V_39 , L_6 ) ;
strcpy ( V_11 -> V_40 , L_2 ) ;
sprintf ( V_11 -> V_41 , L_7 ,
V_11 -> V_40 , V_4 -> V_7 ) ;
F_29 ( V_4 ) ;
V_14 = F_30 ( V_11 ) ;
if ( V_14 < 0 ) {
F_26 ( V_11 ) ;
return V_14 ;
}
F_31 ( V_9 , V_11 ) ;
V_18 ++ ;
return 0 ;
}
static void F_32 ( struct V_12 * V_9 )
{
F_26 ( F_33 ( V_9 ) ) ;
}
static int F_34 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_45 ;
F_35 ( V_43 -> V_46 -> V_11 -> V_18 , L_8 ) ;
V_45 -> V_47 = V_48 ;
return 0 ;
}
static int F_36 ( struct V_42 * V_43 )
{
return 0 ;
}
static int F_37 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_45 ;
F_35 ( V_43 -> V_46 -> V_11 -> V_18 , L_9 ) ;
V_45 -> V_47 = V_49 ;
return 0 ;
}
static int F_38 ( struct V_42 * V_43 )
{
return 0 ;
}
static int F_39 ( struct V_42 * V_43 ,
struct V_50 * V_51 )
{
return F_40 ( V_43 ,
F_41 ( V_51 ) ) ;
}
static int F_42 ( struct V_42 * V_43 )
{
return F_43 ( V_43 ) ;
}
static int F_44 ( struct V_42 * V_43 )
{
struct V_52 * V_53 = F_45 ( V_43 ) ;
struct V_3 * V_4 = V_53 -> V_4 ;
struct V_44 * V_45 = V_43 -> V_45 ;
unsigned long V_54 , V_55 ;
F_46 ( & V_4 -> V_37 ) ;
V_54 = F_47 ( V_43 ) ;
V_55 = F_48 ( V_43 ) ;
F_49 ( & V_4 -> V_6 ,
V_53 -> V_56 ,
V_45 -> V_57 , V_54 ,
V_55 ) ;
F_50 ( V_53 -> V_56 ,
( V_58 )
V_59 ,
( void * ) V_43 ) ;
F_51 ( & V_4 -> V_37 ) ;
return 0 ;
}
static int F_52 ( struct V_42 * V_43 )
{
struct V_52 * V_53 = F_45 ( V_43 ) ;
struct V_3 * V_4 = V_53 -> V_4 ;
struct V_44 * V_45 = V_43 -> V_45 ;
unsigned long V_54 , V_55 ;
F_46 ( & V_4 -> V_37 ) ;
V_54 = F_47 ( V_43 ) ;
V_55 = F_48 ( V_43 ) ;
F_53 ( & V_4 -> V_6 ,
V_53 -> V_56 ,
V_45 -> V_57 , V_54 ,
V_55 ) ;
F_54 ( V_53 -> V_56 ,
( V_58 )
V_59 ,
( void * ) V_43 ) ;
F_51 ( & V_4 -> V_37 ) ;
return 0 ;
}
static int F_55 ( struct V_42 * V_43 ,
int V_60 )
{
int V_61 = 0 ;
struct V_52 * V_53 = F_45 ( V_43 ) ;
struct V_3 * V_4 = V_53 -> V_4 ;
F_56 ( & V_4 -> V_38 ) ;
switch ( V_60 ) {
case V_62 :
F_57 ( & V_4 -> V_6 ,
V_53 ->
V_56 ) ;
break;
case V_63 :
F_58 ( & V_4 -> V_6 ,
V_53 ->
V_56 ) ;
break;
default:
V_61 = - V_64 ;
}
F_59 ( & V_4 -> V_38 ) ;
return V_61 ;
}
static int F_60 ( struct V_42 * V_43 ,
int V_60 )
{
int V_61 = 0 ;
struct V_52 * V_53 = F_45 ( V_43 ) ;
struct V_3 * V_4 = V_53 -> V_4 ;
F_56 ( & V_4 -> V_38 ) ;
switch ( V_60 ) {
case V_62 :
F_61 ( & V_4 -> V_6 ,
V_53 ->
V_56 ) ;
break;
case V_63 :
F_62 ( & V_4 -> V_6 ,
V_53 ->
V_56 ) ;
break;
default:
V_61 = - V_64 ;
}
F_59 ( & V_4 -> V_38 ) ;
return V_61 ;
}
static T_1 F_63 ( struct V_42
* V_43 )
{
struct V_52 * V_53 = F_45 ( V_43 ) ;
struct V_3 * V_4 = V_53 -> V_4 ;
unsigned int V_65 ;
struct V_44 * V_45 = V_43 -> V_45 ;
V_65 =
F_64 ( & V_4 -> V_6 ,
V_53 -> V_56 ,
V_45 -> V_66 ,
V_45 -> V_55 ) ;
return F_65 ( V_43 -> V_45 , V_65 ) ;
}
static T_1 F_66 ( struct V_42
* V_43 )
{
struct V_52 * V_53 = F_45 ( V_43 ) ;
struct V_3 * V_4 = V_53 -> V_4 ;
unsigned int V_65 ;
struct V_44 * V_45 = V_43 -> V_45 ;
V_65 =
F_67 ( & V_4 -> V_6 ,
V_53 -> V_56 ,
V_45 -> V_66 ,
V_45 -> V_55 ) ;
return F_65 ( V_43 -> V_45 , V_65 ) ;
}
static int F_29 ( struct V_3 * V_4 )
{
struct V_67 * V_68 ;
struct V_67 * V_69 ;
struct V_67 * V_70 ;
struct V_52 * V_53 ;
int V_14 = 0 ;
V_14 = F_68 ( V_4 -> V_11 , L_10 , 0 , 1 , 0 ,
& V_68 ) ;
if ( V_14 < 0 ) {
F_14 ( V_4 -> V_11 -> V_18 , L_11 , V_14 ) ;
return V_14 ;
}
V_53 = & V_4 -> V_71 [ V_72 ] ;
strcpy ( V_68 -> V_73 , L_12 ) ;
V_68 -> V_74 = V_53 ;
F_69 ( V_68 , V_75 ,
& V_76 ) ;
V_53 -> V_46 = V_68 ;
V_53 -> V_4 = V_4 ;
V_53 -> V_56 = V_72 ;
V_14 = F_70 ( V_68 ,
V_77 ,
F_71
( V_4 -> V_9 ) ,
64 * 1024 , 64 * 1024 ) ;
if ( V_14 )
F_14 ( V_4 -> V_11 -> V_18 ,
L_13 ,
V_14 ) ;
V_14 = F_68 ( V_4 -> V_11 , L_14 , 1 , 1 , 0 ,
& V_69 ) ;
if ( V_14 < 0 ) {
F_14 ( V_4 -> V_11 -> V_18 , L_11 , V_14 ) ;
return V_14 ;
}
V_53 = & V_4 -> V_71 [ V_78 ] ;
strcpy ( V_69 -> V_73 , L_15 ) ;
V_69 -> V_74 = V_53 ;
F_69 ( V_69 , V_75 ,
& V_76 ) ;
V_53 -> V_46 = V_69 ;
V_53 -> V_4 = V_4 ;
V_53 -> V_56 = V_78 ;
V_14 = F_70 ( V_69 ,
V_77 ,
F_71
( V_4 -> V_9 ) ,
64 * 1024 , 64 * 1024 ) ;
if ( V_14 )
F_14 ( V_4 -> V_11 -> V_18 ,
L_13 ,
V_14 ) ;
V_14 = F_68 ( V_4 -> V_11 , L_16 , 2 , 0 , 1 ,
& V_70 ) ;
if ( V_14 < 0 ) {
F_14 ( V_4 -> V_11 -> V_18 , L_11 , V_14 ) ;
return V_14 ;
}
V_53 = & V_4 -> V_79 [ V_80 ] ;
strcpy ( V_70 -> V_73 , L_17 ) ;
V_70 -> V_74 = V_53 ;
F_69 ( V_70 , V_81 ,
& V_82 ) ;
V_53 -> V_46 = V_70 ;
V_53 -> V_4 = V_4 ;
V_53 -> V_56 = V_80 ;
V_14 = F_70 ( V_70 ,
V_77 ,
F_71
( V_4 -> V_9 ) ,
64 * 1024 , 64 * 1024 ) ;
if ( V_14 )
F_14 ( V_4 -> V_11 -> V_18 ,
L_13 ,
V_14 ) ;
V_14 = F_72 ( V_4 -> V_11 , F_73 ( & V_83 , V_4 ) ) ;
if ( V_14 < 0 ) {
F_14 ( V_4 -> V_11 -> V_18 , L_18 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_74 ( struct V_84 * V_85 ,
struct V_86 * V_87 )
{
static const char * const V_88 [ 2 ] = {
L_19 , L_20
} ;
return F_75 ( V_87 , 1 , 2 , V_88 ) ;
}
static int F_76 ( struct V_84 * V_85 ,
struct V_89
* V_90 )
{
struct V_3 * V_4 = F_77 ( V_85 ) ;
if ( F_78 ( & V_4 -> V_6 ) )
V_90 -> V_91 . V_92 . V_93 [ 0 ] = V_94 ;
else
V_90 -> V_91 . V_92 . V_93 [ 0 ] = V_95 ;
return 0 ;
}
static int F_79 ( struct V_84 * V_85 ,
struct V_89
* V_90 )
{
struct V_3 * V_4 = F_77 ( V_85 ) ;
int V_96 = 0 ;
int V_97 =
F_78 ( & V_4 -> V_6 ) ;
if ( ( ( V_90 -> V_91 . integer . V_91 [ 0 ] == V_94 )
&& ! V_97 )
|| ( ( V_90 -> V_91 . integer . V_91 [ 0 ] == V_95 )
&& V_97 ) ) {
F_80 ( & V_4 -> V_6 , ! V_97 ) ;
V_96 = 1 ;
}
return V_96 ;
}
