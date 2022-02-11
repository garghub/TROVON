static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , 0 ) ;
}
static int F_3 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
if ( V_9 -> V_10 )
F_5 ( V_5 -> V_11 , 0 ,
V_12 ,
V_9 -> V_13 ) ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
T_1 V_16 = F_7 ( V_2 , V_17 ) & 0x1FC ;
int V_18 ;
if ( ! V_9 -> V_10 ) {
F_8 ( V_2 -> V_19 ,
L_1 ) ;
return - V_20 ;
}
for ( V_18 = 0 ; V_18 < V_9 -> V_13 -> V_21 ; V_18 ++ ) {
if ( V_9 -> V_13 -> V_22 [ V_18 ] == F_9 ( V_15 ) )
break;
}
if ( V_18 == V_9 -> V_13 -> V_21 ) {
F_8 ( V_2 -> V_19 , L_2 ,
F_9 ( V_15 ) , V_9 -> V_10 ) ;
return - V_20 ;
}
switch ( F_10 ( V_15 ) ) {
case 16 :
break;
case 20 :
V_16 |= 0x0001 ;
break;
case 24 :
V_16 |= 0x0002 ;
break;
case 32 :
V_16 |= 0x0003 ;
break;
default:
F_11 ( V_2 -> V_19 , L_3 ,
F_10 ( V_15 ) ) ;
return - V_20 ;
}
F_11 ( V_2 -> V_19 , L_4 ,
F_10 ( V_15 ) , F_9 ( V_15 ) ) ;
F_2 ( V_2 , V_17 , V_16 ) ;
return 0 ;
}
static int F_12 ( struct V_6 * V_23 ,
int V_24 , unsigned int V_25 , int V_26 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
F_11 ( V_2 -> V_19 , L_5 , V_25 ) ;
switch ( V_25 ) {
case 0 :
V_9 -> V_13 = NULL ;
break;
case 11289600 :
V_9 -> V_13 = & V_27 ;
break;
case 12288000 :
V_9 -> V_13 = & V_28 ;
break;
case 16384000 :
V_9 -> V_13 = & V_29 ;
break;
case 16934400 :
V_9 -> V_13 = & V_30 ;
break;
case 18432000 :
V_9 -> V_13 = & V_31 ;
break;
case 22579200 :
case 33868800 :
V_9 -> V_13 = & V_32 ;
break;
case 24576000 :
V_9 -> V_13 = & V_33 ;
break;
case 36864000 :
V_9 -> V_13 = & V_34 ;
break;
default:
return - V_20 ;
}
V_9 -> V_10 = V_25 ;
return 0 ;
}
static int F_13 ( struct V_6 * V_23 ,
unsigned int V_35 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
T_1 V_16 = F_7 ( V_2 , V_17 ) & 0x1C3 ;
switch ( V_35 & V_36 ) {
case V_37 :
break;
default:
return - V_20 ;
}
switch ( V_35 & V_38 ) {
case V_39 :
V_16 |= 0x0008 ;
break;
case V_40 :
break;
case V_41 :
V_16 |= 0x0004 ;
break;
case V_42 :
V_16 |= 0x000C ;
break;
case V_43 :
V_16 |= 0x001C ;
break;
default:
return - V_20 ;
}
switch ( V_35 & V_44 ) {
case V_45 :
break;
case V_46 :
V_16 |= 0x0010 ;
break;
case V_47 :
V_16 |= 0x0020 ;
break;
case V_48 :
V_16 |= 0x0030 ;
break;
default:
return - V_20 ;
}
F_11 ( V_2 -> V_19 , L_6 ,
V_35 & V_38 ,
( ( V_35 & V_44 ) ) ) ;
F_2 ( V_2 , V_17 , V_16 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
switch ( V_9 -> V_49 . V_50 ) {
case V_51 :
case V_52 :
case V_53 :
case V_54 :
F_17 ( V_2 , V_55 ,
V_56 ,
V_9 -> V_49 . V_50 << V_57 ) ;
break;
default:
return - V_20 ;
}
F_17 ( V_2 , V_58 ,
V_59 , V_59 ) ;
F_17 ( V_2 , V_60 ,
V_61 , V_61 ) ;
F_17 ( V_2 , V_62 ,
V_63 , V_63 ) ;
F_17 ( V_2 , V_64 ,
V_65 , V_65 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
switch ( V_9 -> V_49 . V_50 ) {
case V_51 :
case V_52 :
F_19 ( V_2 ,
V_66 ,
F_20 ( V_66 ) ) ;
break;
case V_53 :
F_19 ( V_2 ,
V_67 ,
F_20 ( V_67 ) ) ;
break;
case V_54 :
F_19 ( V_2 ,
V_68 ,
F_20 ( V_68 ) ) ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_69 = 0 ;
V_69 = F_22 ( F_20 ( V_9 -> V_70 ) ,
V_9 -> V_70 ) ;
if ( V_69 != 0 ) {
F_8 ( V_2 -> V_19 , L_7 , V_69 ) ;
goto V_71;
}
V_69 = F_1 ( V_2 ) ;
if ( V_69 < 0 ) {
F_8 ( V_2 -> V_19 , L_8 ) ;
goto V_72;
}
V_69 = F_16 ( V_2 ) ;
if ( V_69 < 0 ) {
F_8 ( V_2 -> V_19 , L_9 ) ;
goto V_72;
}
V_69 = F_18 ( V_2 ) ;
if ( V_69 < 0 ) {
F_8 ( V_2 -> V_19 , L_10 ) ;
goto V_72;
}
F_11 ( V_2 -> V_19 , L_11 ) ;
return V_69 ;
V_72:
F_23 ( F_20 ( V_9 -> V_70 ) , V_9 -> V_70 ) ;
V_71:
return V_69 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
F_23 ( F_20 ( V_9 -> V_70 ) , V_9 -> V_70 ) ;
return 0 ;
}
static int F_25 ( struct V_73 * V_19 , struct V_8 * V_9 )
{
const struct V_74 * V_49 = F_26 ( V_19 ) ;
T_2 V_50 ;
if ( V_19 -> V_75 ) {
if ( F_27 ( V_19 -> V_75 , L_12 , & V_50 )
>= 0 )
V_9 -> V_49 . V_50 = V_50 ;
} else {
if ( V_49 != NULL )
memcpy ( & V_9 -> V_49 , V_49 , sizeof( V_9 -> V_49 ) ) ;
}
return 0 ;
}
static int F_28 ( struct V_76 * V_77 ,
const struct V_78 * V_79 )
{
struct V_8 * V_9 ;
int V_69 , V_18 ;
V_9 = F_29 ( & V_77 -> V_19 , sizeof( struct V_8 ) ,
V_80 ) ;
if ( V_9 == NULL )
return - V_81 ;
for ( V_18 = 0 ; V_18 < F_20 ( V_9 -> V_70 ) ; V_18 ++ )
V_9 -> V_70 [ V_18 ] . V_82 = V_83 [ V_18 ] ;
V_69 = F_30 ( & V_77 -> V_19 , F_20 ( V_9 -> V_70 ) ,
V_9 -> V_70 ) ;
if ( V_69 != 0 ) {
F_8 ( & V_77 -> V_19 , L_13 , V_69 ) ;
return V_69 ;
}
V_9 -> V_84 = F_31 ( V_77 , & V_85 ) ;
if ( F_32 ( V_9 -> V_84 ) ) {
V_69 = F_33 ( V_9 -> V_84 ) ;
F_8 ( & V_77 -> V_19 , L_14 , V_69 ) ;
return V_69 ;
}
V_69 = F_25 ( & V_77 -> V_19 , V_9 ) ;
if ( V_69 != 0 ) {
F_8 ( & V_77 -> V_19 , L_15 , V_69 ) ;
return V_69 ;
}
F_34 ( V_77 , V_9 ) ;
V_69 = F_35 ( & V_77 -> V_19 ,
& V_86 , & V_87 , 1 ) ;
return V_69 ;
}
static int F_36 ( struct V_76 * V_88 )
{
F_37 ( & V_88 -> V_19 ) ;
return 0 ;
}
static int F_38 ( struct V_89 * V_90 )
{
struct V_8 * V_9 ;
int V_69 , V_18 ;
V_9 = F_29 ( & V_90 -> V_19 , sizeof( struct V_8 ) ,
V_80 ) ;
if ( V_9 == NULL )
return - V_81 ;
for ( V_18 = 0 ; V_18 < F_20 ( V_9 -> V_70 ) ; V_18 ++ )
V_9 -> V_70 [ V_18 ] . V_82 = V_83 [ V_18 ] ;
V_69 = F_30 ( & V_90 -> V_19 , F_20 ( V_9 -> V_70 ) ,
V_9 -> V_70 ) ;
if ( V_69 != 0 ) {
F_8 ( & V_90 -> V_19 , L_13 , V_69 ) ;
return V_69 ;
}
V_9 -> V_84 = F_39 ( V_90 , & V_85 ) ;
if ( F_32 ( V_9 -> V_84 ) ) {
V_69 = F_33 ( V_9 -> V_84 ) ;
F_8 ( & V_90 -> V_19 , L_14 , V_69 ) ;
return V_69 ;
}
V_69 = F_25 ( & V_90 -> V_19 , V_9 ) ;
if ( V_69 != 0 ) {
F_8 ( & V_90 -> V_19 , L_15 , V_69 ) ;
return V_69 ;
}
F_40 ( V_90 , V_9 ) ;
V_69 = F_35 ( & V_90 -> V_19 ,
& V_86 , & V_87 , 1 ) ;
return V_69 ;
}
static int F_41 ( struct V_89 * V_90 )
{
F_37 ( & V_90 -> V_19 ) ;
return 0 ;
}
static int T_3 F_42 ( void )
{
int V_69 = 0 ;
#if F_43 ( V_91 )
V_69 = F_44 ( & V_92 ) ;
if ( V_69 != 0 )
F_45 ( L_16 , V_69 ) ;
#endif
#if F_46 ( V_93 )
V_69 = F_47 ( & V_94 ) ;
if ( V_69 != 0 ) {
F_48 ( V_95 L_17 ,
V_69 ) ;
}
#endif
return V_69 ;
}
static void T_4 F_49 ( void )
{
#if F_46 ( V_93 )
F_50 ( & V_94 ) ;
#endif
#if F_43 ( V_91 )
F_51 ( & V_92 ) ;
#endif
}
