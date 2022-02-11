static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 =
& V_6 -> V_9 [ V_10 ] ;
F_2 ( 1 , L_1 , V_11 ) ;
F_3 ( V_12 , 0x11 ) ;
F_4 ( V_2 -> V_6 , V_8 , V_4 -> V_13 ,
V_4 -> V_14 . V_15 ) ;
F_5 ( V_16 , V_4 -> V_13 ) ;
F_5 ( V_17 , 1 ) ;
F_5 ( V_18 , V_19 ) ;
F_6 ( & V_2 -> V_20 , 0 ) ;
F_2 ( 1 , L_2
L_3 , V_4 -> V_13 , F_7 ( V_8 -> V_21 + 12 ) >> 1 ,
V_2 -> V_22 , V_4 -> V_13 * V_2 -> V_22 ) ;
F_5 ( V_23 , V_24 | V_25 |
V_26 ) ;
F_5 ( V_27 , ~ 0 ) ;
F_8 ( V_28 , V_2 -> V_6 -> V_29 | V_30 ) ;
F_8 ( V_31 , ( 1 << 5 ) ) ;
F_8 ( V_12 , 0x11 ) ;
if ( V_32 )
F_9 ( V_2 -> V_6 , V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_2 ( 1 , L_4 ) ;
F_3 ( V_12 , 0x11 ) ;
F_3 ( V_28 , V_30 ) ;
F_3 ( V_23 , V_24 | V_25 |
V_26 ) ;
if ( V_32 )
F_9 ( V_2 -> V_6 ,
& V_6 -> V_9 [ V_10 ] ) ;
return 0 ;
}
int F_11 ( struct V_5 * V_6 , T_1 V_33 , T_1 V_34 )
{
struct V_1 * V_2 = V_6 -> V_35 ;
if ( 0 == ( V_33 & V_34 ) )
return 0 ;
F_5 ( V_27 , V_33 ) ;
if ( V_33 & V_24 ) {
F_12 ( V_36 L_5 ,
V_6 -> V_37 ) ;
F_3 ( V_12 , 0x11 ) ;
F_9 ( V_6 ,
& V_6 -> V_9 [ V_10 ] ) ;
}
if ( V_33 & V_25 ) {
F_2 ( 1 , L_6 ) ;
F_5 ( V_18 , V_19 ) ;
return 1 ;
}
if ( V_33 & V_26 ) {
F_6 ( & V_2 -> V_20 , F_7 ( V_38 ) ) ;
F_13 ( V_2 -> V_39 ) ;
}
return 1 ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_15 ( ! V_2 -> V_40 ) ;
F_2 ( 2 , L_7 ) ;
F_16 ( & V_2 -> V_41 -> V_6 , V_2 -> V_42 ) ;
F_17 ( V_2 -> V_42 ) ;
F_18 ( V_2 -> V_41 , & V_2 -> V_4 -> V_14 ) ;
F_19 ( V_2 -> V_4 ) ;
V_2 -> V_42 = NULL ;
V_2 -> V_40 = 0 ;
return 0 ;
}
static int F_20 ( struct V_43 * V_39 )
{
struct V_1 * V_2 = F_21 ( V_39 ) ;
struct V_44 * V_45 = V_39 -> V_45 ;
int V_46 ;
if ( ! V_2 ) {
F_12 ( V_47 L_8
L_9 ) ;
return - V_48 ;
}
V_46 = F_22 ( V_45 , 0 ,
V_49 ) ;
if ( V_46 < 0 )
goto V_50;
V_2 -> V_39 = V_39 ;
V_45 -> V_51 = V_52 ;
if ( V_2 -> V_6 -> V_9 [ V_10 ] . V_53 !=
V_54 ) {
unsigned int V_13 = V_2 -> V_6 ->
V_9 [ V_10 ] . V_53 / 4 ;
V_13 &= ~ 7 ;
V_45 -> V_51 . V_55 = V_13 ;
V_45 -> V_51 . V_56 = V_13 ;
}
return 0 ;
V_50:
F_2 ( 1 , L_10 ) ;
return V_46 ;
}
static int F_23 ( struct V_43 * V_39 )
{
return 0 ;
}
static int F_24 ( struct V_43 * V_39 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_21 ( V_39 ) ;
struct V_59 * V_15 ;
struct V_3 * V_4 ;
int V_60 ;
if ( V_39 -> V_45 -> V_61 ) {
F_14 ( V_2 ) ;
V_39 -> V_45 -> V_61 = NULL ;
}
V_2 -> V_62 = F_25 ( V_58 ) ;
V_2 -> V_22 = F_26 ( V_58 ) ;
V_2 -> V_40 = V_2 -> V_62 * F_26 ( V_58 ) ;
F_15 ( ! V_2 -> V_40 ) ;
F_15 ( V_2 -> V_22 & ( V_2 -> V_22 - 1 ) ) ;
V_4 = F_27 ( sizeof( * V_4 ) , V_63 ) ;
if ( NULL == V_4 )
return - V_64 ;
V_4 -> V_13 = V_2 -> V_62 ;
V_15 = & V_4 -> V_15 ;
F_28 ( V_15 ) ;
V_60 = F_29 ( V_15 , V_65 ,
( F_30 ( V_2 -> V_40 ) >> V_66 ) ) ;
if ( V_60 < 0 )
goto error;
V_60 = F_31 ( & V_2 -> V_41 -> V_6 , V_15 ) ;
if ( V_60 < 0 )
goto error;
V_60 = F_32 ( V_2 -> V_41 , & V_4 -> V_14 , V_15 -> V_67 ,
V_2 -> V_62 , V_2 -> V_22 , 1 ) ;
if ( V_60 < 0 )
goto error;
V_4 -> V_14 . V_68 [ 0 ] = F_33 ( V_69 | V_70 | V_71 ) ;
V_4 -> V_14 . V_68 [ 1 ] = F_33 ( V_4 -> V_14 . V_15 ) ;
V_4 -> V_14 . V_68 [ 2 ] = F_33 ( 0 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_42 = V_15 ;
V_39 -> V_45 -> V_61 = V_2 -> V_42 -> V_72 ;
V_39 -> V_45 -> V_73 = V_2 -> V_40 ;
V_39 -> V_45 -> V_74 = 0 ;
return 0 ;
error:
F_19 ( V_4 ) ;
return V_60 ;
}
static int F_34 ( struct V_43 * V_39 )
{
struct V_1 * V_2 = F_21 ( V_39 ) ;
if ( V_39 -> V_45 -> V_61 ) {
F_14 ( V_2 ) ;
V_39 -> V_45 -> V_61 = NULL ;
}
return 0 ;
}
static int F_35 ( struct V_43 * V_39 )
{
return 0 ;
}
static int F_36 ( struct V_43 * V_39 ,
int V_75 )
{
struct V_1 * V_2 = F_21 ( V_39 ) ;
int V_46 ;
F_37 ( & V_2 -> V_76 ) ;
switch ( V_75 ) {
case V_77 :
V_46 = F_1 ( V_2 ) ;
break;
case V_78 :
V_46 = F_10 ( V_2 ) ;
break;
default:
V_46 = - V_79 ;
break;
}
F_38 ( & V_2 -> V_76 ) ;
return V_46 ;
}
static T_2 F_39 (
struct V_43 * V_39 )
{
struct V_1 * V_2 = F_21 ( V_39 ) ;
struct V_44 * V_45 = V_39 -> V_45 ;
T_3 V_20 ;
V_20 = F_40 ( & V_2 -> V_20 ) ;
return V_45 -> V_62 * ( V_20 & ( V_45 -> V_80 - 1 ) ) ;
}
static struct V_81 * F_41 ( struct V_43 * V_39 ,
unsigned long V_82 )
{
void * V_83 = V_39 -> V_45 -> V_61 + V_82 ;
return F_42 ( V_83 ) ;
}
static int F_43 ( struct V_1 * V_2 , int V_84 ,
char * V_37 )
{
int V_46 ;
struct V_85 * V_86 ;
V_46 = F_44 ( V_2 -> V_87 , V_37 , V_84 , 0 , 1 , & V_86 ) ;
if ( V_46 < 0 )
return V_46 ;
V_86 -> V_88 = V_2 ;
strcpy ( V_86 -> V_37 , V_37 ) ;
F_45 ( V_86 , V_89 , & V_90 ) ;
return 0 ;
}
struct V_1 * F_46 ( struct V_5 * V_6 )
{
struct V_91 * V_87 ;
struct V_1 * V_2 ;
int V_46 ;
if ( V_92 )
return NULL ;
if ( V_6 -> V_9 [ V_10 ] . V_21 == 0 ) {
F_12 ( V_36 L_11
L_12 , V_11 ) ;
return NULL ;
}
V_46 = F_47 ( & V_6 -> V_41 -> V_6 ,
V_93 , V_94 ,
V_95 , sizeof( struct V_1 ) , & V_87 ) ;
if ( V_46 < 0 )
goto error;
V_2 = (struct V_1 * ) V_87 -> V_88 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_41 = V_6 -> V_41 ;
V_2 -> V_87 = V_87 ;
F_48 ( & V_2 -> V_76 ) ;
V_46 = F_43 ( V_2 , 0 , L_13 ) ;
if ( V_46 < 0 )
goto error;
strcpy ( V_87 -> V_96 , L_14 ) ;
sprintf ( V_87 -> V_97 , L_15 ) ;
sprintf ( V_87 -> V_98 , L_16 , V_87 -> V_97 , V_6 -> V_37 ) ;
V_46 = F_49 ( V_87 ) ;
if ( V_46 < 0 )
goto error;
F_2 ( 0 , L_17 ) ;
return V_2 ;
error:
F_50 ( V_87 ) ;
F_12 ( V_47 L_18
L_19 , V_11 ) ;
return NULL ;
}
void F_51 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_35 ;
F_50 ( V_2 -> V_87 ) ;
}
