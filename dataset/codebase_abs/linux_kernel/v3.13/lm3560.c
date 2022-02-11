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
if ( V_16 == true )
V_3 = F_2 ( V_2 -> V_7 ,
V_8 , 0x08 , 0x08 ) ;
else
V_3 = F_2 ( V_2 -> V_7 ,
V_8 , 0x08 , 0x00 ) ;
} else {
if ( V_16 == true )
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
F_10 ( & V_2 -> V_26 ) ;
if ( V_25 -> V_27 == V_28 ) {
int V_3 ;
T_2 V_29 = 0 ;
unsigned int V_30 ;
V_3 = F_11 ( V_2 -> V_7 , V_31 , & V_30 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 & V_32 )
V_29 |= V_33 ;
if ( V_3 & V_34 )
V_29 |= V_35 ;
if ( V_3 & V_36 )
V_29 |= V_37 ;
V_25 -> V_38 . V_39 = V_29 ;
return 0 ;
}
F_12 ( & V_2 -> V_26 ) ;
return - V_4 ;
}
static int F_13 ( struct V_24 * V_25 , enum V_14 V_15 )
{
struct V_1 * V_2 = F_9 ( V_25 , V_15 ) ;
T_1 V_40 ;
int V_3 = - V_4 ;
F_10 ( & V_2 -> V_26 ) ;
switch ( V_25 -> V_27 ) {
case V_41 :
V_2 -> V_5 = V_25 -> V_39 ;
if ( V_2 -> V_5 != V_12 )
V_3 = F_1 ( V_2 ) ;
break;
case V_42 :
V_3 = F_2 ( V_2 -> V_7 ,
V_43 , 0x04 , ( V_25 -> V_39 ) << 2 ) ;
if ( V_3 < 0 )
goto V_44;
break;
case V_45 :
if ( V_2 -> V_5 != V_12 )
return - V_46 ;
V_2 -> V_5 = V_12 ;
V_3 = F_1 ( V_2 ) ;
break;
case V_47 :
if ( V_2 -> V_5 != V_12 )
return - V_46 ;
V_2 -> V_5 = V_6 ;
V_3 = F_1 ( V_2 ) ;
break;
case V_48 :
V_40 = F_14 ( V_25 -> V_39 ) ;
V_3 = F_2 ( V_2 -> V_7 ,
V_49 , 0x1f , V_40 ) ;
break;
case V_50 :
V_3 = F_6 ( V_2 , V_15 , V_25 -> V_39 ) ;
break;
case V_51 :
V_3 = F_4 ( V_2 , V_15 , V_25 -> V_39 ) ;
break;
}
F_12 ( & V_2 -> V_26 ) ;
V_44:
return V_3 ;
}
static int F_15 ( struct V_24 * V_25 )
{
return F_8 ( V_25 , V_52 ) ;
}
static int F_16 ( struct V_24 * V_25 )
{
return F_13 ( V_25 , V_52 ) ;
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
T_3 V_53 = V_2 -> V_54 -> V_53 [ V_15 ] ;
T_3 V_55 = V_2 -> V_54 -> V_55 [ V_15 ] ;
struct V_56 * V_57 = & V_2 -> V_58 [ V_15 ] ;
const struct V_59 * V_60 = & V_61 [ V_15 ] ;
F_20 ( V_57 , 8 ) ;
F_21 ( V_57 , V_60 , V_41 ,
V_10 , ~ 0x7 ,
V_6 ) ;
V_2 -> V_5 = V_6 ;
F_21 ( V_57 , V_60 , V_42 ,
0x1 , ~ 0x3 , V_62 ) ;
F_22 ( V_57 , V_60 , V_45 , 0 , 0 , 0 , 0 ) ;
F_22 ( V_57 , V_60 , V_47 , 0 , 0 , 0 , 0 ) ;
F_22 ( V_57 , V_60 , V_48 ,
V_63 ,
V_2 -> V_54 -> V_64 ,
V_65 ,
V_2 -> V_54 -> V_64 ) ;
F_22 ( V_57 , V_60 , V_50 ,
V_22 , V_53 ,
V_66 , V_53 ) ;
F_22 ( V_57 , V_60 , V_51 ,
V_20 , V_55 ,
V_67 , V_55 ) ;
V_29 = F_22 ( V_57 , V_60 , V_28 , 0 ,
V_68
| V_35
| V_33
| V_37 , 0 , 0 ) ;
if ( V_29 != NULL )
V_29 -> V_69 |= V_70 ;
if ( V_57 -> error )
return V_57 -> error ;
V_2 -> V_71 [ V_15 ] . V_72 = V_57 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
enum V_14 V_15 , char * V_73 )
{
struct V_74 * V_75 = F_24 ( V_2 -> V_76 ) ;
int V_3 ;
F_25 ( & V_2 -> V_71 [ V_15 ] , V_75 , & V_77 ) ;
V_2 -> V_71 [ V_15 ] . V_69 |= V_78 ;
strcpy ( V_2 -> V_71 [ V_15 ] . V_79 , V_73 ) ;
V_3 = F_19 ( V_2 , V_15 ) ;
if ( V_3 )
goto V_44;
V_3 = F_26 ( & V_2 -> V_71 [ V_15 ] . V_80 , 0 , NULL , 0 ) ;
if ( V_3 < 0 )
goto V_44;
V_2 -> V_71 [ V_15 ] . V_80 . type = V_81 ;
return V_3 ;
V_44:
F_27 ( & V_2 -> V_58 [ V_15 ] ) ;
return V_3 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_30 ;
V_3 = F_2 ( V_2 -> V_7 ,
V_49 , 0x60 , V_2 -> V_54 -> V_82 ) ;
if ( V_3 < 0 )
return V_3 ;
V_2 -> V_5 = V_6 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_11 ( V_2 -> V_7 , V_31 , & V_30 ) ;
return V_3 ;
}
static int F_29 ( struct V_74 * V_75 ,
const struct V_83 * V_84 )
{
struct V_1 * V_2 ;
struct V_85 * V_54 = F_30 ( & V_75 -> V_76 ) ;
int V_3 ;
V_2 = F_31 ( & V_75 -> V_76 , sizeof( * V_2 ) , V_86 ) ;
if ( V_2 == NULL )
return - V_87 ;
V_2 -> V_7 = F_32 ( V_75 , & V_88 ) ;
if ( F_33 ( V_2 -> V_7 ) ) {
V_3 = F_34 ( V_2 -> V_7 ) ;
return V_3 ;
}
if ( V_54 == NULL ) {
V_54 =
F_35 ( sizeof( struct V_85 ) , V_86 ) ;
if ( V_54 == NULL )
return - V_89 ;
V_54 -> V_82 = V_90 ;
V_54 -> V_64 = V_91 ;
V_54 -> V_53 [ V_17 ] = V_92 ;
V_54 -> V_55 [ V_17 ] = V_93 ;
V_54 -> V_53 [ V_52 ] = V_92 ;
V_54 -> V_55 [ V_52 ] = V_93 ;
}
V_2 -> V_54 = V_54 ;
V_2 -> V_76 = & V_75 -> V_76 ;
F_36 ( & V_2 -> V_26 ) ;
V_3 = F_23 ( V_2 , V_17 , L_1 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_23 ( V_2 , V_52 , L_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_28 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_37 ( struct V_74 * V_75 )
{
struct V_94 * V_95 = F_38 ( V_75 ) ;
struct V_1 * V_2 = F_39 ( V_95 , struct V_1 ,
V_71 [ V_96 ] ) ;
unsigned int V_97 ;
for ( V_97 = V_17 ; V_97 < V_96 ; V_97 ++ ) {
F_40 ( & V_2 -> V_71 [ V_97 ] ) ;
F_27 ( & V_2 -> V_58 [ V_97 ] ) ;
F_41 ( & V_2 -> V_71 [ V_97 ] . V_80 ) ;
}
return 0 ;
}
