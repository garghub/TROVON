static void F_1 ( T_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 = V_5 -> V_7 -> V_6 ;
V_3 -> V_8 = V_1 [ V_9 ] & V_6 ;
V_3 -> V_10 = V_1 [ V_11 ] & V_6 ;
if ( V_5 -> V_12 ) {
V_3 -> V_13 = V_1 [ V_14 ] & 0x1f ;
} else {
V_3 -> V_13 = V_1 [ V_14 ] & 0x0f ;
if ( V_1 [ V_14 ] & V_15 )
V_3 -> V_13 += 12 ;
}
V_3 -> V_16 = F_2 ( V_1 [ V_17 ] & V_6 ) - 1 ;
V_3 -> V_18 = V_1 [ V_19 ] & 0x1f ;
V_3 -> V_20 = ( V_1 [ V_21 ] & 0x0f ) - 1 ;
V_3 -> V_22 = V_1 [ V_23 ] & V_6 ;
V_3 -> V_24 = 0 ;
V_3 -> V_25 = 0 ;
if ( ! V_5 -> V_7 -> V_26 )
V_3 -> V_22 += 100 ;
}
static int F_3 ( struct V_2 * V_3 , T_1 * V_1 ,
struct V_4 * V_5 )
{
V_1 [ V_9 ] = V_3 -> V_8 ;
V_1 [ V_11 ] = V_3 -> V_10 ;
V_1 [ V_14 ] = V_3 -> V_13 ;
V_1 [ V_17 ] = 1 << V_3 -> V_16 ;
V_1 [ V_19 ] = V_3 -> V_18 ;
V_1 [ V_21 ] = V_3 -> V_20 + 1 ;
if ( V_5 -> V_7 -> V_26 ) {
V_1 [ V_23 ] = V_3 -> V_22 ;
return 0 ;
}
V_1 [ V_23 ] = V_3 -> V_22 > 100 ? ( V_3 -> V_22 - 100 ) : 0 ;
if ( V_3 -> V_22 < 100 ) {
F_4 ( V_5 -> V_27 , L_1 ,
1900 + V_3 -> V_22 ) ;
return - V_28 ;
}
return 0 ;
}
static int F_5 ( struct V_4 * V_5 ,
enum V_29 V_30 )
{
int V_31 ;
unsigned int V_1 ;
unsigned long V_32 = V_5 -> V_7 -> V_32 ;
if ( V_30 == V_33 )
V_1 = 1 << V_34 ;
else
V_1 = 1 << V_35 ;
V_31 = F_6 ( V_5 -> V_36 ,
V_5 -> V_7 -> V_37 [ V_38 ] ,
V_1 , V_1 ) ;
if ( V_31 < 0 )
F_4 ( V_5 -> V_27 , L_2 ,
V_31 , V_1 ) ;
else {
F_7 ( V_32 , V_32 * 2 ) ;
}
return V_31 ;
}
static int F_8 ( struct V_39 * V_27 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_9 ( V_27 ) ;
T_1 V_1 [ V_40 ] ;
int V_31 ;
F_10 ( & V_5 -> V_41 ) ;
V_31 = F_5 ( V_5 , V_42 ) ;
if ( V_31 < 0 )
goto V_43;
V_31 = F_11 ( V_5 -> V_36 ,
V_5 -> V_7 -> V_37 [ V_44 ] ,
V_1 , F_12 ( V_1 ) ) ;
if ( V_31 < 0 ) {
F_4 ( V_5 -> V_27 , L_3 , V_31 ) ;
goto V_43;
}
F_1 ( V_1 , V_3 , V_5 ) ;
V_31 = F_13 ( V_3 ) ;
V_43:
F_14 ( & V_5 -> V_41 ) ;
return V_31 ;
}
static int F_15 ( struct V_39 * V_27 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_9 ( V_27 ) ;
T_1 V_1 [ V_40 ] ;
int V_31 ;
V_31 = F_3 ( V_3 , V_1 , V_5 ) ;
if ( V_31 < 0 )
return V_31 ;
F_10 ( & V_5 -> V_41 ) ;
V_31 = F_16 ( V_5 -> V_36 ,
V_5 -> V_7 -> V_37 [ V_44 ] ,
V_1 , F_12 ( V_1 ) ) ;
if ( V_31 < 0 ) {
F_4 ( V_5 -> V_27 , L_4 , V_31 ) ;
goto V_43;
}
V_31 = F_5 ( V_5 , V_33 ) ;
V_43:
F_14 ( & V_5 -> V_41 ) ;
return V_31 ;
}
static int F_17 ( struct V_39 * V_27 , struct V_45 * V_46 )
{
struct V_4 * V_5 = F_9 ( V_27 ) ;
T_1 V_1 [ V_40 ] ;
unsigned int V_47 ;
const unsigned int * V_37 = V_5 -> V_7 -> V_37 ;
int V_48 , V_31 ;
F_10 ( & V_5 -> V_41 ) ;
V_31 = F_5 ( V_5 , V_42 ) ;
if ( V_31 < 0 )
goto V_43;
V_31 = F_11 ( V_5 -> V_36 , V_37 [ V_49 ] ,
V_1 , F_12 ( V_1 ) ) ;
if ( V_31 < 0 ) {
F_4 ( V_5 -> V_27 , L_5 , V_31 ) ;
goto V_43;
}
F_1 ( V_1 , & V_46 -> time , V_5 ) ;
V_46 -> V_50 = 0 ;
if ( V_5 -> V_7 -> V_26 ) {
if ( V_37 [ V_51 ] == V_52 ) {
V_31 = - V_28 ;
F_4 ( V_5 -> V_27 ,
L_6 , V_31 ) ;
goto V_43;
}
V_31 = F_18 ( V_5 -> V_36 , V_37 [ V_51 ] , & V_47 ) ;
if ( V_31 < 0 ) {
F_4 ( V_5 -> V_27 ,
L_7 , V_31 ) ;
goto V_43;
}
if ( V_47 )
V_46 -> V_50 = 1 ;
} else {
for ( V_48 = 0 ; V_48 < F_12 ( V_1 ) ; V_48 ++ ) {
if ( V_1 [ V_48 ] & V_53 ) {
V_46 -> V_50 = 1 ;
break;
}
}
}
V_46 -> V_54 = 0 ;
if ( V_5 -> V_7 -> V_55 == V_56 )
goto V_43;
V_31 = F_18 ( V_5 -> V_57 ,
V_5 -> V_7 -> V_55 , & V_47 ) ;
if ( V_31 < 0 ) {
F_4 ( V_5 -> V_27 ,
L_8 , V_31 ) ;
goto V_43;
}
if ( V_47 & ( 1 << 4 ) )
V_46 -> V_54 = 1 ;
V_43:
F_14 ( & V_5 -> V_41 ) ;
return V_31 ;
}
static int F_19 ( struct V_4 * V_5 )
{
T_1 V_1 [ V_40 ] ;
int V_31 , V_48 ;
struct V_2 V_3 ;
const unsigned int * V_37 = V_5 -> V_7 -> V_37 ;
if ( ! F_20 ( & V_5 -> V_41 ) )
F_21 ( V_5 -> V_27 , L_9 , V_58 ) ;
V_31 = F_5 ( V_5 , V_42 ) ;
if ( V_31 < 0 )
goto V_43;
if ( V_5 -> V_7 -> V_26 ) {
if ( V_37 [ V_51 ] == V_52 ) {
V_31 = - V_28 ;
F_4 ( V_5 -> V_27 ,
L_6 , V_31 ) ;
goto V_43;
}
V_31 = F_22 ( V_5 -> V_36 , V_37 [ V_51 ] , 0 ) ;
} else {
V_31 = F_11 ( V_5 -> V_36 , V_37 [ V_49 ] ,
V_1 , F_12 ( V_1 ) ) ;
if ( V_31 < 0 ) {
F_4 ( V_5 -> V_27 , L_5 , V_31 ) ;
goto V_43;
}
F_1 ( V_1 , & V_3 , V_5 ) ;
for ( V_48 = 0 ; V_48 < F_12 ( V_1 ) ; V_48 ++ )
V_1 [ V_48 ] &= ~ V_53 ;
V_31 = F_16 ( V_5 -> V_36 , V_37 [ V_49 ] ,
V_1 , F_12 ( V_1 ) ) ;
}
if ( V_31 < 0 ) {
F_4 ( V_5 -> V_27 , L_10 , V_31 ) ;
goto V_43;
}
V_31 = F_5 ( V_5 , V_33 ) ;
V_43:
return V_31 ;
}
static int F_23 ( struct V_4 * V_5 )
{
T_1 V_1 [ V_40 ] ;
int V_31 ;
struct V_2 V_3 ;
const unsigned int * V_37 = V_5 -> V_7 -> V_37 ;
if ( ! F_20 ( & V_5 -> V_41 ) )
F_21 ( V_5 -> V_27 , L_9 , V_58 ) ;
V_31 = F_5 ( V_5 , V_42 ) ;
if ( V_31 < 0 )
goto V_43;
if ( V_5 -> V_7 -> V_26 ) {
V_31 = F_22 ( V_5 -> V_36 , V_37 [ V_51 ] ,
V_59 ) ;
} else {
V_31 = F_11 ( V_5 -> V_36 , V_37 [ V_49 ] ,
V_1 , F_12 ( V_1 ) ) ;
if ( V_31 < 0 ) {
F_4 ( V_5 -> V_27 , L_5 , V_31 ) ;
goto V_43;
}
F_1 ( V_1 , & V_3 , V_5 ) ;
V_1 [ V_9 ] |= ( 1 << V_60 ) ;
V_1 [ V_11 ] |= ( 1 << V_60 ) ;
V_1 [ V_14 ] |= ( 1 << V_60 ) ;
V_1 [ V_17 ] &= ~ V_53 ;
if ( V_1 [ V_21 ] & 0xf )
V_1 [ V_21 ] |= ( 1 << V_60 ) ;
if ( V_1 [ V_23 ] & V_5 -> V_7 -> V_6 )
V_1 [ V_23 ] |= ( 1 << V_60 ) ;
if ( V_1 [ V_19 ] & 0x1f )
V_1 [ V_19 ] |= ( 1 << V_60 ) ;
V_31 = F_16 ( V_5 -> V_36 , V_37 [ V_49 ] ,
V_1 , F_12 ( V_1 ) ) ;
}
if ( V_31 < 0 ) {
F_4 ( V_5 -> V_27 , L_10 , V_31 ) ;
goto V_43;
}
V_31 = F_5 ( V_5 , V_33 ) ;
V_43:
return V_31 ;
}
static int F_24 ( struct V_39 * V_27 , struct V_45 * V_46 )
{
struct V_4 * V_5 = F_9 ( V_27 ) ;
T_1 V_1 [ V_40 ] ;
int V_31 ;
V_31 = F_3 ( & V_46 -> time , V_1 , V_5 ) ;
if ( V_31 < 0 )
return V_31 ;
F_10 ( & V_5 -> V_41 ) ;
V_31 = F_19 ( V_5 ) ;
if ( V_31 < 0 )
goto V_43;
V_31 = F_16 ( V_5 -> V_36 ,
V_5 -> V_7 -> V_37 [ V_49 ] ,
V_1 , F_12 ( V_1 ) ) ;
if ( V_31 < 0 ) {
F_4 ( V_5 -> V_27 , L_10 , V_31 ) ;
goto V_43;
}
V_31 = F_5 ( V_5 , V_33 ) ;
if ( V_31 < 0 )
goto V_43;
if ( V_46 -> V_50 )
V_31 = F_23 ( V_5 ) ;
V_43:
F_14 ( & V_5 -> V_41 ) ;
return V_31 ;
}
static int F_25 ( struct V_39 * V_27 ,
unsigned int V_50 )
{
struct V_4 * V_5 = F_9 ( V_27 ) ;
int V_31 ;
F_10 ( & V_5 -> V_41 ) ;
if ( V_50 )
V_31 = F_23 ( V_5 ) ;
else
V_31 = F_19 ( V_5 ) ;
F_14 ( & V_5 -> V_41 ) ;
return V_31 ;
}
static T_2 F_26 ( int V_61 , void * V_1 )
{
struct V_4 * V_5 = V_1 ;
F_27 ( V_5 -> V_27 , L_11 , V_61 ) ;
F_28 ( V_5 -> V_62 , 1 , V_63 | V_64 ) ;
return V_65 ;
}
static int F_29 ( struct V_4 * V_5 )
{
T_1 V_1 [ 2 ] ;
int V_31 ;
V_1 [ 0 ] = ( 1 << V_66 ) | ( 1 << V_67 ) ;
V_1 [ 1 ] = ( 0 << V_66 ) | ( 1 << V_67 ) ;
V_5 -> V_12 = 1 ;
V_31 = F_16 ( V_5 -> V_36 ,
V_5 -> V_7 -> V_37 [ V_68 ] ,
V_1 , F_12 ( V_1 ) ) ;
if ( V_31 < 0 ) {
F_4 ( V_5 -> V_27 , L_12 , V_31 ) ;
return V_31 ;
}
V_31 = F_5 ( V_5 , V_33 ) ;
return V_31 ;
}
static int F_30 ( struct V_4 * V_5 )
{
struct V_39 * V_69 = V_5 -> V_27 -> V_69 ;
struct V_70 * V_71 = F_31 ( V_69 ) ;
int V_31 ;
if ( V_5 -> V_7 -> V_72 ) {
struct V_73 * V_74 = F_32 ( V_5 -> V_27 ) ;
V_5 -> V_75 = F_33 ( V_74 , 0 ) ;
if ( V_5 -> V_75 < 0 ) {
F_4 ( V_5 -> V_27 , L_13 ,
V_5 -> V_75 ) ;
return V_5 -> V_75 ;
}
} else {
V_5 -> V_75 = V_71 -> V_61 ;
}
V_5 -> V_57 = F_34 ( V_69 , NULL ) ;
if ( ! V_5 -> V_57 ) {
F_4 ( V_5 -> V_27 , L_14 ) ;
return - V_76 ;
}
if ( V_5 -> V_7 -> V_77 == V_78 ) {
V_5 -> V_36 = V_5 -> V_57 ;
goto V_79;
}
V_5 -> V_80 = F_35 ( V_71 -> V_81 ,
V_5 -> V_7 -> V_77 ) ;
if ( ! V_5 -> V_80 ) {
F_4 ( V_5 -> V_27 , L_15 ) ;
return - V_76 ;
}
V_5 -> V_36 = F_36 ( V_5 -> V_80 ,
& V_82 ) ;
if ( F_37 ( V_5 -> V_36 ) ) {
V_31 = F_38 ( V_5 -> V_36 ) ;
F_4 ( V_5 -> V_27 , L_16 , V_31 ) ;
goto V_83;
}
V_79:
V_31 = F_39 ( V_5 -> V_36 , V_5 -> V_75 ,
V_84 | V_85 |
V_86 , 0 , V_5 -> V_7 -> V_87 ,
& V_5 -> V_88 ) ;
if ( V_31 < 0 ) {
F_4 ( V_5 -> V_27 , L_17 , V_31 ) ;
goto V_83;
}
return 0 ;
V_83:
if ( V_5 -> V_80 )
F_40 ( V_5 -> V_80 ) ;
return V_31 ;
}
static int F_41 ( struct V_73 * V_74 )
{
struct V_4 * V_5 ;
const struct V_89 * V_90 = F_42 ( V_74 ) ;
int V_31 ;
V_5 = F_43 ( & V_74 -> V_27 , sizeof( struct V_4 ) ,
V_91 ) ;
if ( ! V_5 )
return - V_92 ;
F_44 ( & V_5 -> V_41 ) ;
V_5 -> V_27 = & V_74 -> V_27 ;
V_5 -> V_7 = ( const struct V_93 * )
V_90 -> V_94 ;
V_31 = F_30 ( V_5 ) ;
if ( V_31 < 0 )
return V_31 ;
F_45 ( V_74 , V_5 ) ;
V_31 = F_29 ( V_5 ) ;
if ( V_31 < 0 ) {
F_4 ( & V_74 -> V_27 , L_18 , V_31 ) ;
goto V_95;
}
F_46 ( & V_74 -> V_27 , 1 ) ;
V_5 -> V_62 = F_47 ( & V_74 -> V_27 , V_90 -> V_96 ,
& V_97 , V_98 ) ;
if ( F_37 ( V_5 -> V_62 ) ) {
V_31 = F_38 ( V_5 -> V_62 ) ;
F_4 ( & V_74 -> V_27 , L_19 , V_31 ) ;
if ( V_31 == 0 )
V_31 = - V_28 ;
goto V_95;
}
V_5 -> V_99 = F_48 ( V_5 -> V_88 ,
V_100 ) ;
if ( V_5 -> V_99 <= 0 ) {
V_31 = - V_101 ;
goto V_95;
}
V_31 = F_49 ( V_5 -> V_99 , NULL , F_26 , 0 ,
L_20 , V_5 ) ;
if ( V_31 < 0 ) {
F_4 ( & V_74 -> V_27 , L_21 ,
V_5 -> V_99 , V_31 ) ;
goto V_95;
}
return 0 ;
V_95:
F_50 ( V_5 -> V_75 , V_5 -> V_88 ) ;
if ( V_5 -> V_80 )
F_40 ( V_5 -> V_80 ) ;
return V_31 ;
}
static int F_51 ( struct V_73 * V_74 )
{
struct V_4 * V_5 = F_52 ( V_74 ) ;
F_53 ( V_5 -> V_99 , V_5 ) ;
F_50 ( V_5 -> V_75 , V_5 -> V_88 ) ;
if ( V_5 -> V_80 )
F_40 ( V_5 -> V_80 ) ;
return 0 ;
}
static int F_54 ( struct V_39 * V_27 )
{
if ( F_55 ( V_27 ) ) {
struct V_4 * V_5 = F_9 ( V_27 ) ;
return F_56 ( V_5 -> V_99 ) ;
}
return 0 ;
}
static int F_57 ( struct V_39 * V_27 )
{
if ( F_55 ( V_27 ) ) {
struct V_4 * V_5 = F_9 ( V_27 ) ;
return F_58 ( V_5 -> V_99 ) ;
}
return 0 ;
}
