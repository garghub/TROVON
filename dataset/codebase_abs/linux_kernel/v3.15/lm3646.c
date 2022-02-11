static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
switch ( V_4 ) {
case V_5 :
return F_2 ( V_2 -> V_6 ,
V_7 , V_2 -> V_8 | V_9 ) ;
case V_10 :
return F_2 ( V_2 -> V_6 ,
V_7 , V_2 -> V_8 | V_11 ) ;
case V_12 :
return F_2 ( V_2 -> V_6 ,
V_7 , V_2 -> V_8 | V_13 ) ;
}
return - V_14 ;
}
static int F_3 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
unsigned int V_17 ;
int V_18 ;
if ( V_16 -> V_19 != V_20 )
return - V_14 ;
V_18 = F_5 ( V_2 -> V_6 , V_21 , & V_17 ) ;
if ( V_18 < 0 )
return V_18 ;
V_16 -> V_22 = 0 ;
if ( V_17 & V_23 )
V_16 -> V_22 |= V_24 ;
if ( V_17 & V_25 )
V_16 -> V_22 |= V_26 ;
if ( V_17 & V_27 )
V_16 -> V_22 |= V_28 ;
if ( V_17 & V_29 )
V_16 -> V_22 |= V_30 ;
if ( V_17 & V_31 )
V_16 -> V_22 |= V_32 ;
if ( V_17 & V_33 )
V_16 -> V_22 |= V_34 ;
if ( V_17 & V_35 )
V_16 -> V_22 |= V_36 ;
if ( V_17 & V_37 )
V_16 -> V_22 |= V_38 ;
return 0 ;
}
static int F_6 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_16 ) ;
unsigned int V_17 ;
int V_18 = - V_14 ;
switch ( V_16 -> V_19 ) {
case V_39 :
if ( V_16 -> V_22 != V_12 )
return F_1 ( V_2 , V_16 -> V_22 ) ;
return F_1 ( V_2 , V_5 ) ;
case V_40 :
return F_7 ( V_2 -> V_6 ,
V_41 , V_42 ,
( V_16 -> V_22 ) << 7 ) ;
case V_43 :
V_18 = F_5 ( V_2 -> V_6 , V_7 , & V_17 ) ;
if ( V_18 < 0 || ( ( V_17 & V_44 ) != V_9 ) )
return V_18 ;
return F_1 ( V_2 , V_12 ) ;
case V_45 :
V_18 = F_5 ( V_2 -> V_6 , V_7 , & V_17 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( ( V_17 & V_44 ) == V_13 )
return F_1 ( V_2 ,
V_5 ) ;
return V_18 ;
case V_46 :
return F_7 ( V_2 -> V_6 ,
V_47 , V_48 ,
F_8
( V_16 -> V_22 ) ) ;
case V_49 :
return F_7 ( V_2 -> V_6 ,
V_50 , V_51 ,
F_9
( V_16 -> V_22 ) ) ;
case V_52 :
return F_7 ( V_2 -> V_6 ,
V_53 , V_54 ,
F_10
( V_16 -> V_22 ) << 4 ) ;
}
return - V_14 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_15 * V_55 ;
struct V_56 * V_57 = & V_2 -> V_58 ;
const struct V_59 * V_60 = & V_61 ;
F_12 ( V_57 , 8 ) ;
F_13 ( V_57 , V_60 , V_39 ,
V_10 , ~ 0x7 ,
V_5 ) ;
F_13 ( V_57 , V_60 , V_40 ,
0x1 , ~ 0x3 , V_62 ) ;
F_14 ( V_57 , V_60 , V_43 , 0 , 0 , 0 , 0 ) ;
F_14 ( V_57 , V_60 , V_45 , 0 , 0 , 0 , 0 ) ;
F_14 ( V_57 , V_60 , V_46 ,
V_63 ,
V_64 ,
V_65 , V_2 -> V_66 -> V_67 ) ;
F_14 ( V_57 , V_60 , V_49 ,
V_68 ,
V_69 ,
V_70 ,
V_69 ) ;
F_14 ( V_57 , V_60 , V_52 ,
V_71 ,
V_72 ,
V_73 ,
V_72 ) ;
V_55 = F_14 ( V_57 , V_60 , V_20 , 0 ,
V_38
| V_34
| V_26
| V_24 , 0 , 0 ) ;
if ( V_55 != NULL )
V_55 -> V_74 |= V_75 ;
if ( V_57 -> error )
return V_57 -> error ;
V_2 -> V_76 . V_77 = V_57 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = F_16 ( V_2 -> V_80 ) ;
int V_18 ;
F_17 ( & V_2 -> V_76 , V_79 , & V_81 ) ;
V_2 -> V_76 . V_74 |= V_82 ;
strcpy ( V_2 -> V_76 . V_83 , V_84 ) ;
V_18 = F_11 ( V_2 ) ;
if ( V_18 )
goto V_85;
V_18 = F_18 ( & V_2 -> V_76 . V_86 , 0 , NULL , 0 ) ;
if ( V_18 < 0 )
goto V_85;
V_2 -> V_76 . V_86 . type = V_87 ;
return V_18 ;
V_85:
F_19 ( & V_2 -> V_58 ) ;
return V_18 ;
}
static int F_20 ( struct V_1 * V_2 )
{
unsigned int V_17 ;
int V_18 ;
V_18 = F_5 ( V_2 -> V_6 , V_7 , & V_17 ) ;
if ( V_18 < 0 )
return V_18 ;
V_2 -> V_8 = V_17 & 0xfc ;
V_18 = F_1 ( V_2 , V_5 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_7 ( V_2 -> V_6 ,
V_88 , 0x7F ,
F_21
( V_2 -> V_66 -> V_89 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_7 ( V_2 -> V_6 ,
V_90 , 0x7F ,
F_22
( V_2 -> V_66 -> V_91 ) ) ;
if ( V_18 < 0 )
return V_18 ;
return F_5 ( V_2 -> V_6 , V_21 , & V_17 ) ;
}
static int F_23 ( struct V_78 * V_79 ,
const struct V_92 * V_93 )
{
struct V_1 * V_2 ;
struct V_94 * V_66 = F_24 ( & V_79 -> V_80 ) ;
int V_18 ;
V_2 = F_25 ( & V_79 -> V_80 , sizeof( * V_2 ) , V_95 ) ;
if ( V_2 == NULL )
return - V_96 ;
V_2 -> V_6 = F_26 ( V_79 , & V_97 ) ;
if ( F_27 ( V_2 -> V_6 ) )
return F_28 ( V_2 -> V_6 ) ;
if ( V_66 == NULL ) {
V_66 = F_25 ( & V_79 -> V_80 ,
sizeof( struct V_94 ) ,
V_95 ) ;
if ( V_66 == NULL )
return - V_96 ;
V_66 -> V_67 = V_64 ;
V_66 -> V_91 = V_98 ;
V_66 -> V_89 = V_99 ;
}
V_2 -> V_66 = V_66 ;
V_2 -> V_80 = & V_79 -> V_80 ;
V_18 = F_15 ( V_2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_20 ( V_2 ) ;
if ( V_18 < 0 )
return V_18 ;
F_29 ( V_79 , V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_31 ( V_79 ) ;
F_32 ( & V_2 -> V_76 ) ;
F_19 ( & V_2 -> V_58 ) ;
F_33 ( & V_2 -> V_76 . V_86 ) ;
return 0 ;
}
