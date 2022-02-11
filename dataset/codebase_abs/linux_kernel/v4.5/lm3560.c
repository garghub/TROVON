static int F_1 ( struct V_1 * V_2 )
{
int V_3 = - V_4 ;
switch ( V_2 -> V_5 ) {
case V_6 :
V_3 = F_2 ( V_2 -> V_7 ,
V_8 , 0x03 , V_9 ) ;
break;
case V_10 :
V_3 = F_2 ( V_2 -> V_7 ,
V_8 , 0x03 , V_11 ) ;
break;
case V_12 :
V_3 = F_2 ( V_2 -> V_7 ,
V_8 , 0x03 , V_13 ) ;
break;
}
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 ,
enum V_14 V_15 , bool V_16 )
{
int V_3 ;
if ( V_15 == V_17 ) {
if ( V_16 )
V_3 = F_2 ( V_2 -> V_7 ,
V_8 , 0x08 , 0x08 ) ;
else
V_3 = F_2 ( V_2 -> V_7 ,
V_8 , 0x08 , 0x00 ) ;
} else {
if ( V_16 )
V_3 = F_2 ( V_2 -> V_7 ,
V_8 , 0x10 , 0x10 ) ;
else
V_3 = F_2 ( V_2 -> V_7 ,
V_8 , 0x10 , 0x00 ) ;
}
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 ,
enum V_14 V_15 , unsigned int V_18 )
{
int V_3 ;
T_1 V_19 ;
if ( V_18 < V_20 )
return F_3 ( V_2 , V_15 , false ) ;
else
V_3 = F_3 ( V_2 , V_15 , true ) ;
V_19 = F_5 ( V_18 ) ;
if ( V_15 == V_17 )
V_3 = F_2 ( V_2 -> V_7 ,
V_21 , 0x07 , V_19 ) ;
else
V_3 = F_2 ( V_2 -> V_7 ,
V_21 , 0x38 , V_19 << 3 ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_2 ,
enum V_14 V_15 , unsigned int V_18 )
{
int V_3 ;
T_1 V_19 ;
if ( V_18 < V_22 )
return F_3 ( V_2 , V_15 , false ) ;
else
V_3 = F_3 ( V_2 , V_15 , true ) ;
V_19 = F_7 ( V_18 ) ;
if ( V_15 == V_17 )
V_3 = F_2 ( V_2 -> V_7 ,
V_23 , 0x0f , V_19 ) ;
else
V_3 = F_2 ( V_2 -> V_7 ,
V_23 , 0xf0 , V_19 << 4 ) ;
return V_3 ;
}
static int F_8 ( struct V_24 * V_25 , enum V_14 V_15 )
{
struct V_1 * V_2 = F_9 ( V_25 , V_15 ) ;
int V_3 = - V_4 ;
F_10 ( & V_2 -> V_26 ) ;
if ( V_25 -> V_27 == V_28 ) {
T_2 V_29 = 0 ;
unsigned int V_30 ;
V_3 = F_11 ( V_2 -> V_7 , V_31 , & V_30 ) ;
if ( V_3 < 0 )
goto V_32;
if ( V_30 & V_33 )
V_29 |= V_34 ;
if ( V_30 & V_35 )
V_29 |= V_36 ;
if ( V_30 & V_37 )
V_29 |= V_38 ;
V_25 -> V_39 . V_40 = V_29 ;
}
V_32:
F_12 ( & V_2 -> V_26 ) ;
return V_3 ;
}
static int F_13 ( struct V_24 * V_25 , enum V_14 V_15 )
{
struct V_1 * V_2 = F_9 ( V_25 , V_15 ) ;
T_1 V_41 ;
int V_3 = - V_4 ;
F_10 ( & V_2 -> V_26 ) ;
switch ( V_25 -> V_27 ) {
case V_42 :
V_2 -> V_5 = V_25 -> V_40 ;
if ( V_2 -> V_5 != V_12 )
V_3 = F_1 ( V_2 ) ;
break;
case V_43 :
V_3 = F_2 ( V_2 -> V_7 ,
V_44 , 0x04 , ( V_25 -> V_40 ) << 2 ) ;
if ( V_3 < 0 )
goto V_45;
break;
case V_46 :
if ( V_2 -> V_5 != V_12 ) {
V_3 = - V_47 ;
goto V_45;
}
V_2 -> V_5 = V_12 ;
V_3 = F_1 ( V_2 ) ;
break;
case V_48 :
if ( V_2 -> V_5 != V_12 ) {
V_3 = - V_47 ;
goto V_45;
}
V_2 -> V_5 = V_6 ;
V_3 = F_1 ( V_2 ) ;
break;
case V_49 :
V_41 = F_14 ( V_25 -> V_40 ) ;
V_3 = F_2 ( V_2 -> V_7 ,
V_50 , 0x1f , V_41 ) ;
break;
case V_51 :
V_3 = F_6 ( V_2 , V_15 , V_25 -> V_40 ) ;
break;
case V_52 :
V_3 = F_4 ( V_2 , V_15 , V_25 -> V_40 ) ;
break;
}
V_45:
F_12 ( & V_2 -> V_26 ) ;
return V_3 ;
}
static int F_15 ( struct V_24 * V_25 )
{
return F_8 ( V_25 , V_53 ) ;
}
static int F_16 ( struct V_24 * V_25 )
{
return F_13 ( V_25 , V_53 ) ;
}
static int F_17 ( struct V_24 * V_25 )
{
return F_8 ( V_25 , V_17 ) ;
}
static int F_18 ( struct V_24 * V_25 )
{
return F_13 ( V_25 , V_17 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
enum V_14 V_15 )
{
struct V_24 * V_29 ;
T_3 V_54 = V_2 -> V_55 -> V_54 [ V_15 ] ;
T_3 V_56 = V_2 -> V_55 -> V_56 [ V_15 ] ;
struct V_57 * V_58 = & V_2 -> V_59 [ V_15 ] ;
const struct V_60 * V_61 = & V_62 [ V_15 ] ;
F_20 ( V_58 , 8 ) ;
F_21 ( V_58 , V_61 , V_42 ,
V_10 , ~ 0x7 ,
V_6 ) ;
V_2 -> V_5 = V_6 ;
F_21 ( V_58 , V_61 , V_43 ,
0x1 , ~ 0x3 , V_63 ) ;
F_22 ( V_58 , V_61 , V_46 , 0 , 0 , 0 , 0 ) ;
F_22 ( V_58 , V_61 , V_48 , 0 , 0 , 0 , 0 ) ;
F_22 ( V_58 , V_61 , V_49 ,
V_64 ,
V_2 -> V_55 -> V_65 ,
V_66 ,
V_2 -> V_55 -> V_65 ) ;
F_22 ( V_58 , V_61 , V_51 ,
V_22 , V_54 ,
V_67 , V_54 ) ;
F_22 ( V_58 , V_61 , V_52 ,
V_20 , V_56 ,
V_68 , V_56 ) ;
V_29 = F_22 ( V_58 , V_61 , V_28 , 0 ,
V_69
| V_36
| V_34
| V_38 , 0 , 0 ) ;
if ( V_29 != NULL )
V_29 -> V_70 |= V_71 ;
if ( V_58 -> error )
return V_58 -> error ;
V_2 -> V_72 [ V_15 ] . V_73 = V_58 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
enum V_14 V_15 , char * V_74 )
{
struct V_75 * V_76 = F_24 ( V_2 -> V_77 ) ;
int V_3 ;
F_25 ( & V_2 -> V_72 [ V_15 ] , V_76 , & V_78 ) ;
V_2 -> V_72 [ V_15 ] . V_70 |= V_79 ;
strcpy ( V_2 -> V_72 [ V_15 ] . V_80 , V_74 ) ;
V_3 = F_19 ( V_2 , V_15 ) ;
if ( V_3 )
goto V_45;
V_3 = F_26 ( & V_2 -> V_72 [ V_15 ] . V_81 , 0 , NULL ) ;
if ( V_3 < 0 )
goto V_45;
V_2 -> V_72 [ V_15 ] . V_81 . V_82 = V_83 ;
return V_3 ;
V_45:
F_27 ( & V_2 -> V_59 [ V_15 ] ) ;
return V_3 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_30 ;
V_3 = F_2 ( V_2 -> V_7 ,
V_50 , 0x60 , V_2 -> V_55 -> V_84 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_5 = V_6 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_11 ( V_2 -> V_7 , V_31 , & V_30 ) ;
return V_3 ;
}
static int F_29 ( struct V_75 * V_76 ,
const struct V_85 * V_86 )
{
struct V_1 * V_2 ;
struct V_87 * V_55 = F_30 ( & V_76 -> V_77 ) ;
int V_3 ;
V_2 = F_31 ( & V_76 -> V_77 , sizeof( * V_2 ) , V_88 ) ;
if ( V_2 == NULL )
return - V_89 ;
V_2 -> V_7 = F_32 ( V_76 , & V_90 ) ;
if ( F_33 ( V_2 -> V_7 ) ) {
V_3 = F_34 ( V_2 -> V_7 ) ;
return V_3 ;
}
if ( V_55 == NULL ) {
V_55 = F_31 ( & V_76 -> V_77 , sizeof( * V_55 ) , V_88 ) ;
if ( V_55 == NULL )
return - V_91 ;
V_55 -> V_84 = V_92 ;
V_55 -> V_65 = V_93 ;
V_55 -> V_54 [ V_17 ] = V_94 ;
V_55 -> V_56 [ V_17 ] = V_95 ;
V_55 -> V_54 [ V_53 ] = V_94 ;
V_55 -> V_56 [ V_53 ] = V_95 ;
}
V_2 -> V_55 = V_55 ;
V_2 -> V_77 = & V_76 -> V_77 ;
F_35 ( & V_2 -> V_26 ) ;
V_3 = F_23 ( V_2 , V_17 , L_1 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_23 ( V_2 , V_53 , L_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_28 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
F_36 ( V_76 , V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_38 ( V_76 ) ;
unsigned int V_96 ;
for ( V_96 = V_17 ; V_96 < V_97 ; V_96 ++ ) {
F_39 ( & V_2 -> V_72 [ V_96 ] ) ;
F_27 ( & V_2 -> V_59 [ V_96 ] ) ;
F_40 ( & V_2 -> V_72 [ V_96 ] . V_81 ) ;
}
return 0 ;
}
