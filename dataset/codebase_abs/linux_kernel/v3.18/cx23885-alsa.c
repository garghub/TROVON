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
F_3 ( 1 , L_5
L_6 , V_5 -> V_27 , F_20 ( V_23 -> V_35 + 12 ) >> 1 ,
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
F_3 ( 1 , L_7 ) ;
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
F_25 ( V_50 L_8 ,
V_16 -> V_51 ) ;
F_16 ( V_26 , 0x11 ) ;
F_22 ( V_16 ,
& V_16 -> V_24 [ V_25 ] ) ;
}
if ( V_47 & V_39 ) {
F_3 ( 1 , L_9 ) ;
F_18 ( V_32 , V_33 ) ;
return 1 ;
}
if ( V_47 & V_40 ) {
F_19 ( & V_2 -> V_34 , F_20 ( V_52 ) ) ;
F_26 ( V_2 -> V_53 ) ;
}
return 1 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_54 * V_28 ;
F_28 ( ! V_2 -> V_55 ) ;
F_3 ( 2 , L_10 ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 -> V_5 ) ;
V_28 = & V_2 -> V_5 -> V_28 ;
F_29 ( V_2 -> V_18 , V_28 -> V_56 , V_28 -> V_57 , V_28 -> V_29 ) ;
F_30 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_2 -> V_55 = 0 ;
return 0 ;
}
static int F_31 ( struct V_58 * V_53 )
{
struct V_1 * V_2 = F_32 ( V_53 ) ;
struct V_59 * V_60 = V_53 -> V_60 ;
int V_61 ;
if ( ! V_2 ) {
F_25 ( V_62 L_11
L_12 ) ;
return - V_63 ;
}
V_61 = F_33 ( V_60 , 0 ,
V_64 ) ;
if ( V_61 < 0 )
goto V_65;
V_2 -> V_53 = V_53 ;
V_60 -> V_66 = V_67 ;
if ( V_2 -> V_16 -> V_24 [ V_25 ] . V_68 !=
V_69 ) {
unsigned int V_27 = V_2 -> V_16 ->
V_24 [ V_25 ] . V_68 / 4 ;
V_27 &= ~ 7 ;
V_60 -> V_66 . V_70 = V_27 ;
V_60 -> V_66 . V_71 = V_27 ;
}
return 0 ;
V_65:
F_3 ( 1 , L_13 ) ;
return V_61 ;
}
static int F_34 ( struct V_58 * V_53 )
{
return 0 ;
}
static int F_35 ( struct V_58 * V_53 ,
struct V_72 * V_73 )
{
struct V_1 * V_2 = F_32 ( V_53 ) ;
struct V_4 * V_5 ;
int V_74 ;
if ( V_53 -> V_60 -> V_75 ) {
F_27 ( V_2 ) ;
V_53 -> V_60 -> V_75 = NULL ;
}
V_2 -> V_76 = F_36 ( V_73 ) ;
V_2 -> V_36 = F_37 ( V_73 ) ;
V_2 -> V_55 = V_2 -> V_76 * F_37 ( V_73 ) ;
F_28 ( ! V_2 -> V_55 ) ;
F_28 ( V_2 -> V_36 & ( V_2 -> V_36 - 1 ) ) ;
V_5 = F_38 ( sizeof( * V_5 ) , V_77 ) ;
if ( NULL == V_5 )
return - V_11 ;
V_5 -> V_27 = V_2 -> V_76 ;
V_2 -> V_5 = V_5 ;
V_74 = F_1 ( V_2 ,
( F_39 ( V_2 -> V_55 ) >> V_10 ) ) ;
if ( V_74 < 0 )
goto error;
V_74 = F_9 ( V_2 ) ;
if ( V_74 < 0 )
goto error;
V_74 = F_40 ( V_2 -> V_18 , & V_5 -> V_28 , V_5 -> V_12 ,
V_2 -> V_76 , V_2 -> V_36 , 1 ) ;
if ( V_74 < 0 )
goto error;
V_5 -> V_28 . V_78 [ 0 ] = F_41 ( V_79 | V_80 | V_81 ) ;
V_5 -> V_28 . V_78 [ 1 ] = F_41 ( V_5 -> V_28 . V_29 ) ;
V_5 -> V_28 . V_78 [ 2 ] = F_41 ( 0 ) ;
V_53 -> V_60 -> V_75 = V_2 -> V_5 -> V_9 ;
V_53 -> V_60 -> V_82 = V_2 -> V_55 ;
V_53 -> V_60 -> V_83 = 0 ;
return 0 ;
error:
F_30 ( V_5 ) ;
V_2 -> V_5 = NULL ;
return V_74 ;
}
static int F_42 ( struct V_58 * V_53 )
{
struct V_1 * V_2 = F_32 ( V_53 ) ;
if ( V_53 -> V_60 -> V_75 ) {
F_27 ( V_2 ) ;
V_53 -> V_60 -> V_75 = NULL ;
}
return 0 ;
}
static int F_43 ( struct V_58 * V_53 )
{
return 0 ;
}
static int F_44 ( struct V_58 * V_53 ,
int V_84 )
{
struct V_1 * V_2 = F_32 ( V_53 ) ;
int V_61 ;
F_45 ( & V_2 -> V_85 ) ;
switch ( V_84 ) {
case V_86 :
V_61 = F_15 ( V_2 ) ;
break;
case V_87 :
V_61 = F_23 ( V_2 ) ;
break;
default:
V_61 = - V_88 ;
break;
}
F_46 ( & V_2 -> V_85 ) ;
return V_61 ;
}
static T_2 F_47 (
struct V_58 * V_53 )
{
struct V_1 * V_2 = F_32 ( V_53 ) ;
struct V_59 * V_60 = V_53 -> V_60 ;
T_3 V_34 ;
V_34 = F_48 ( & V_2 -> V_34 ) ;
return V_60 -> V_76 * ( V_34 & ( V_60 -> V_89 - 1 ) ) ;
}
static struct V_6 * F_49 ( struct V_58 * V_53 ,
unsigned long V_90 )
{
void * V_91 = V_53 -> V_60 -> V_75 + V_90 ;
return F_6 ( V_91 ) ;
}
static int F_50 ( struct V_1 * V_2 , int V_92 ,
char * V_51 )
{
int V_61 ;
struct V_93 * V_94 ;
V_61 = F_51 ( V_2 -> V_95 , V_51 , V_92 , 0 , 1 , & V_94 ) ;
if ( V_61 < 0 )
return V_61 ;
V_94 -> V_96 = V_2 ;
strcpy ( V_94 -> V_51 , V_51 ) ;
F_52 ( V_94 , V_97 , & V_98 ) ;
return 0 ;
}
struct V_1 * F_53 ( struct V_21 * V_16 )
{
struct V_99 * V_95 ;
struct V_1 * V_2 ;
int V_61 ;
if ( V_100 )
return NULL ;
if ( V_16 -> V_24 [ V_25 ] . V_35 == 0 ) {
F_25 ( V_50 L_14
L_15 , V_20 ) ;
return NULL ;
}
V_61 = F_54 ( & V_16 -> V_18 -> V_16 ,
V_101 , V_102 ,
V_103 , sizeof( struct V_1 ) , & V_95 ) ;
if ( V_61 < 0 )
goto error;
V_2 = (struct V_1 * ) V_95 -> V_96 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_18 = V_16 -> V_18 ;
V_2 -> V_95 = V_95 ;
F_55 ( & V_2 -> V_85 ) ;
V_61 = F_50 ( V_2 , 0 , L_16 ) ;
if ( V_61 < 0 )
goto error;
strcpy ( V_95 -> V_104 , L_17 ) ;
sprintf ( V_95 -> V_105 , L_18 ) ;
sprintf ( V_95 -> V_106 , L_19 , V_95 -> V_105 , V_16 -> V_51 ) ;
V_61 = F_56 ( V_95 ) ;
if ( V_61 < 0 )
goto error;
F_3 ( 0 , L_20 ) ;
return V_2 ;
error:
F_57 ( V_95 ) ;
F_25 ( V_62 L_21
L_22 , V_20 ) ;
return NULL ;
}
void F_58 ( struct V_21 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_49 ;
F_57 ( V_2 -> V_95 ) ;
}
