static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_5 -> V_9 = F_2 ( V_3 << V_10 ) ;
if ( NULL == V_5 -> V_9 ) {
F_3 ( 1 , L_1 , V_3 ) ;
return - V_11 ;
}
F_3 ( 1 , L_2 ,
( unsigned long ) V_5 -> V_9 ,
V_3 << V_10 ) ;
memset ( V_5 -> V_9 , 0 , V_3 << V_10 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_12 = F_4 ( V_5 -> V_3 * sizeof( * V_5 -> V_12 ) ) ;
if ( NULL == V_5 -> V_12 )
goto V_13;
F_5 ( V_5 -> V_12 , V_5 -> V_3 ) ;
for ( V_8 = 0 ; V_8 < V_5 -> V_3 ; V_8 ++ ) {
V_7 = F_6 ( V_5 -> V_9 + V_8 * V_14 ) ;
if ( NULL == V_7 )
goto V_15;
F_7 ( & V_5 -> V_12 [ V_8 ] , V_7 , V_14 , 0 ) ;
}
return 0 ;
V_15:
F_8 ( V_5 -> V_12 ) ;
V_5 -> V_12 = NULL ;
V_13:
F_8 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
return - V_11 ;
}
static int F_9 ( struct V_1 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_5 ;
V_5 -> V_17 = F_10 ( & V_16 -> V_18 -> V_16 , V_5 -> V_12 ,
V_5 -> V_3 , V_19 ) ;
if ( 0 == V_5 -> V_17 ) {
F_11 ( L_3 , V_20 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_5 ;
if ( ! V_5 -> V_17 )
return 0 ;
F_13 ( & V_16 -> V_18 -> V_16 , V_5 -> V_12 , V_5 -> V_17 , V_19 ) ;
V_5 -> V_17 = 0 ;
return 0 ;
}
static int F_14 ( struct V_4 * V_5 )
{
F_8 ( V_5 -> V_12 ) ;
V_5 -> V_12 = NULL ;
F_8 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_21 * V_16 = V_2 -> V_16 ;
struct V_22 * V_23 =
& V_16 -> V_24 [ V_25 ] ;
F_3 ( 1 , L_4 , V_20 ) ;
F_16 ( V_26 , 0x11 ) ;
F_17 ( V_2 -> V_16 , V_23 , V_5 -> V_27 ,
V_5 -> V_28 . V_29 ) ;
F_18 ( V_30 , V_5 -> V_27 ) ;
F_18 ( V_31 , 1 ) ;
F_18 ( V_32 , V_33 ) ;
F_19 ( & V_2 -> V_34 , 0 ) ;
F_3 ( 1 , L_5 ,
V_5 -> V_27 , F_20 ( V_23 -> V_35 + 12 ) >> 1 ,
V_2 -> V_36 , V_5 -> V_27 * V_2 -> V_36 ) ;
F_18 ( V_37 , V_38 | V_39 |
V_40 ) ;
F_18 ( V_41 , ~ 0 ) ;
F_21 ( V_42 , V_2 -> V_16 -> V_43 | V_44 ) ;
F_21 ( V_45 , ( 1 << 5 ) ) ;
F_21 ( V_26 , 0x11 ) ;
if ( V_46 )
F_22 ( V_2 -> V_16 , V_23 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_21 * V_16 = V_2 -> V_16 ;
F_3 ( 1 , L_6 ) ;
F_16 ( V_26 , 0x11 ) ;
F_16 ( V_42 , V_44 ) ;
F_16 ( V_37 , V_38 | V_39 |
V_40 ) ;
if ( V_46 )
F_22 ( V_2 -> V_16 ,
& V_16 -> V_24 [ V_25 ] ) ;
return 0 ;
}
int F_24 ( struct V_21 * V_16 , T_1 V_47 , T_1 V_48 )
{
struct V_1 * V_2 = V_16 -> V_49 ;
if ( 0 == ( V_47 & V_48 ) )
return 0 ;
F_18 ( V_41 , V_47 ) ;
if ( V_47 & V_38 ) {
F_11 ( L_7 ,
V_16 -> V_50 ) ;
F_16 ( V_26 , 0x11 ) ;
F_22 ( V_16 ,
& V_16 -> V_24 [ V_25 ] ) ;
}
if ( V_47 & V_39 ) {
F_3 ( 1 , L_8 ) ;
F_18 ( V_32 , V_33 ) ;
return 1 ;
}
if ( V_47 & V_40 ) {
F_19 ( & V_2 -> V_34 , F_20 ( V_51 ) ) ;
F_25 ( V_2 -> V_52 ) ;
}
return 1 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_53 * V_28 ;
F_27 ( ! V_2 -> V_54 ) ;
F_3 ( 2 , L_9 ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 -> V_5 ) ;
V_28 = & V_2 -> V_5 -> V_28 ;
F_28 ( V_2 -> V_18 , V_28 -> V_55 , V_28 -> V_56 , V_28 -> V_29 ) ;
F_29 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_2 -> V_54 = 0 ;
return 0 ;
}
static int F_30 ( struct V_57 * V_52 )
{
struct V_1 * V_2 = F_31 ( V_52 ) ;
struct V_58 * V_59 = V_52 -> V_59 ;
int V_60 ;
if ( ! V_2 ) {
F_32 ( L_10 ) ;
return - V_61 ;
}
V_60 = F_33 ( V_59 , 0 ,
V_62 ) ;
if ( V_60 < 0 )
goto V_63;
V_2 -> V_52 = V_52 ;
V_59 -> V_64 = V_65 ;
if ( V_2 -> V_16 -> V_24 [ V_25 ] . V_66 !=
V_67 ) {
unsigned int V_27 = V_2 -> V_16 ->
V_24 [ V_25 ] . V_66 / 4 ;
V_27 &= ~ 7 ;
V_59 -> V_64 . V_68 = V_27 ;
V_59 -> V_64 . V_69 = V_27 ;
}
return 0 ;
V_63:
F_3 ( 1 , L_11 ) ;
return V_60 ;
}
static int F_34 ( struct V_57 * V_52 )
{
return 0 ;
}
static int F_35 ( struct V_57 * V_52 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = F_31 ( V_52 ) ;
struct V_4 * V_5 ;
int V_72 ;
if ( V_52 -> V_59 -> V_73 ) {
F_26 ( V_2 ) ;
V_52 -> V_59 -> V_73 = NULL ;
}
V_2 -> V_74 = F_36 ( V_71 ) ;
V_2 -> V_36 = F_37 ( V_71 ) ;
V_2 -> V_54 = V_2 -> V_74 * F_37 ( V_71 ) ;
F_27 ( ! V_2 -> V_54 ) ;
F_27 ( V_2 -> V_36 & ( V_2 -> V_36 - 1 ) ) ;
V_5 = F_38 ( sizeof( * V_5 ) , V_75 ) ;
if ( NULL == V_5 )
return - V_11 ;
V_5 -> V_27 = V_2 -> V_74 ;
V_2 -> V_5 = V_5 ;
V_72 = F_1 ( V_2 ,
( F_39 ( V_2 -> V_54 ) >> V_10 ) ) ;
if ( V_72 < 0 )
goto error;
V_72 = F_9 ( V_2 ) ;
if ( V_72 < 0 )
goto error;
V_72 = F_40 ( V_2 -> V_18 , & V_5 -> V_28 , V_5 -> V_12 ,
V_2 -> V_74 , V_2 -> V_36 , 1 ) ;
if ( V_72 < 0 )
goto error;
V_5 -> V_28 . V_76 [ 0 ] = F_41 ( V_77 | V_78 | V_79 ) ;
V_5 -> V_28 . V_76 [ 1 ] = F_41 ( V_5 -> V_28 . V_29 ) ;
V_5 -> V_28 . V_76 [ 2 ] = F_41 ( 0 ) ;
V_52 -> V_59 -> V_73 = V_2 -> V_5 -> V_9 ;
V_52 -> V_59 -> V_80 = V_2 -> V_54 ;
V_52 -> V_59 -> V_81 = 0 ;
return 0 ;
error:
F_29 ( V_5 ) ;
V_2 -> V_5 = NULL ;
return V_72 ;
}
static int F_42 ( struct V_57 * V_52 )
{
struct V_1 * V_2 = F_31 ( V_52 ) ;
if ( V_52 -> V_59 -> V_73 ) {
F_26 ( V_2 ) ;
V_52 -> V_59 -> V_73 = NULL ;
}
return 0 ;
}
static int F_43 ( struct V_57 * V_52 )
{
return 0 ;
}
static int F_44 ( struct V_57 * V_52 ,
int V_82 )
{
struct V_1 * V_2 = F_31 ( V_52 ) ;
int V_60 ;
F_45 ( & V_2 -> V_83 ) ;
switch ( V_82 ) {
case V_84 :
V_60 = F_15 ( V_2 ) ;
break;
case V_85 :
V_60 = F_23 ( V_2 ) ;
break;
default:
V_60 = - V_86 ;
break;
}
F_46 ( & V_2 -> V_83 ) ;
return V_60 ;
}
static T_2 F_47 (
struct V_57 * V_52 )
{
struct V_1 * V_2 = F_31 ( V_52 ) ;
struct V_58 * V_59 = V_52 -> V_59 ;
T_3 V_34 ;
V_34 = F_48 ( & V_2 -> V_34 ) ;
return V_59 -> V_74 * ( V_34 & ( V_59 -> V_87 - 1 ) ) ;
}
static struct V_6 * F_49 ( struct V_57 * V_52 ,
unsigned long V_88 )
{
void * V_89 = V_52 -> V_59 -> V_73 + V_88 ;
return F_6 ( V_89 ) ;
}
static int F_50 ( struct V_1 * V_2 , int V_90 ,
char * V_50 )
{
int V_60 ;
struct V_91 * V_92 ;
V_60 = F_51 ( V_2 -> V_93 , V_50 , V_90 , 0 , 1 , & V_92 ) ;
if ( V_60 < 0 )
return V_60 ;
V_92 -> V_94 = V_2 ;
strcpy ( V_92 -> V_50 , V_50 ) ;
F_52 ( V_92 , V_95 , & V_96 ) ;
return 0 ;
}
struct V_1 * F_53 ( struct V_21 * V_16 )
{
struct V_97 * V_93 ;
struct V_1 * V_2 ;
int V_60 ;
if ( V_98 )
return NULL ;
if ( V_16 -> V_24 [ V_25 ] . V_35 == 0 ) {
F_11 ( L_12 ,
V_20 ) ;
return NULL ;
}
V_60 = F_54 ( & V_16 -> V_18 -> V_16 ,
V_99 , V_100 ,
V_101 , sizeof( struct V_1 ) , & V_93 ) ;
if ( V_60 < 0 )
goto error;
V_2 = (struct V_1 * ) V_93 -> V_94 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_18 = V_16 -> V_18 ;
V_2 -> V_93 = V_93 ;
F_55 ( & V_2 -> V_83 ) ;
V_60 = F_50 ( V_2 , 0 , L_13 ) ;
if ( V_60 < 0 )
goto error;
strcpy ( V_93 -> V_102 , L_14 ) ;
sprintf ( V_93 -> V_103 , L_15 ) ;
sprintf ( V_93 -> V_104 , L_16 , V_93 -> V_103 , V_16 -> V_50 ) ;
V_60 = F_56 ( V_93 ) ;
if ( V_60 < 0 )
goto error;
F_3 ( 0 , L_17 ) ;
return V_2 ;
error:
F_57 ( V_93 ) ;
F_32 ( L_18 ,
V_20 ) ;
return NULL ;
}
void F_58 ( struct V_21 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_49 ;
F_57 ( V_2 -> V_93 ) ;
}
