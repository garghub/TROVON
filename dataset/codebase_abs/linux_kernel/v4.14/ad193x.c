static inline bool F_1 ( const struct V_1 * V_2 )
{
switch ( V_2 -> type ) {
case V_3 :
case V_4 :
return false ;
default:
break;
}
return true ;
}
static int F_2 ( struct V_5 * V_6 , int V_7 )
{
struct V_1 * V_2 = F_3 ( V_6 -> V_8 ) ;
if ( V_7 )
F_4 ( V_2 -> V_9 , V_10 ,
V_11 ,
V_11 ) ;
else
F_4 ( V_2 -> V_9 , V_10 ,
V_11 , 0 ) ;
return 0 ;
}
static int F_5 ( struct V_5 * V_6 , unsigned int V_12 ,
unsigned int V_13 , int V_14 , int V_15 )
{
struct V_1 * V_2 = F_3 ( V_6 -> V_8 ) ;
unsigned int V_16 ;
switch ( V_14 ) {
case 2 :
V_16 = V_17 ;
break;
case 4 :
V_16 = V_18 ;
break;
case 8 :
V_16 = V_19 ;
break;
case 16 :
V_16 = V_20 ;
break;
default:
return - V_21 ;
}
F_4 ( V_2 -> V_9 , V_22 ,
V_23 , V_16 << V_24 ) ;
if ( F_1 ( V_2 ) )
F_4 ( V_2 -> V_9 , V_25 ,
V_26 ,
V_16 << V_27 ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_28 ,
unsigned int V_29 )
{
struct V_1 * V_2 = F_3 ( V_28 -> V_8 ) ;
unsigned int V_30 = 0 ;
unsigned int V_31 = 0 ;
unsigned int V_32 = 0 ;
switch ( V_29 & V_33 ) {
case V_34 :
V_30 |= V_35 ;
break;
case V_36 :
V_30 |= V_37 ;
break;
default:
if ( F_1 ( V_2 ) )
return - V_21 ;
break;
}
switch ( V_29 & V_38 ) {
case V_39 :
break;
case V_40 :
V_31 |= V_41 ;
V_32 |= V_42 ;
break;
case V_43 :
V_31 |= V_44 ;
V_32 |= V_45 ;
break;
case V_46 :
V_31 |= V_41 ;
V_31 |= V_44 ;
V_32 |= V_42 ;
V_32 |= V_45 ;
break;
default:
return - V_21 ;
}
switch ( V_29 & V_47 ) {
case V_48 :
V_31 |= V_49 ;
V_31 |= V_50 ;
V_32 |= V_51 ;
V_32 |= V_52 ;
break;
case V_53 :
V_31 |= V_49 ;
V_32 |= V_51 ;
break;
case V_54 :
V_31 |= V_50 ;
V_32 |= V_52 ;
break;
case V_55 :
break;
default:
return - V_21 ;
}
if ( F_1 ( V_2 ) ) {
F_4 ( V_2 -> V_9 , V_56 ,
V_57 , V_30 ) ;
F_4 ( V_2 -> V_9 , V_25 ,
V_58 , V_31 ) ;
}
F_4 ( V_2 -> V_9 , V_22 ,
V_59 , V_32 ) ;
return 0 ;
}
static int F_7 ( struct V_5 * V_28 ,
int V_60 , unsigned int V_61 , int V_62 )
{
struct V_63 * V_8 = V_28 -> V_8 ;
struct V_1 * V_2 = F_3 ( V_8 ) ;
switch ( V_61 ) {
case 12288000 :
case 18432000 :
case 24576000 :
case 36864000 :
V_2 -> V_64 = V_61 ;
return 0 ;
}
return - V_21 ;
}
static int F_8 ( struct V_65 * V_66 ,
struct V_67 * V_68 ,
struct V_5 * V_6 )
{
int V_69 = 0 , V_70 = 0 ;
struct V_63 * V_8 = V_6 -> V_8 ;
struct V_1 * V_2 = F_3 ( V_8 ) ;
switch ( F_9 ( V_68 ) ) {
case 16 :
V_69 = 3 ;
break;
case 20 :
V_69 = 1 ;
break;
case 24 :
case 32 :
V_69 = 0 ;
break;
}
switch ( V_2 -> V_64 ) {
case 12288000 :
V_70 = V_71 ;
break;
case 18432000 :
V_70 = V_72 ;
break;
case 24576000 :
V_70 = V_73 ;
break;
case 36864000 :
V_70 = V_74 ;
break;
}
F_4 ( V_2 -> V_9 , V_75 ,
V_76 , V_70 ) ;
F_4 ( V_2 -> V_9 , V_10 ,
V_77 ,
V_69 << V_78 ) ;
if ( F_1 ( V_2 ) )
F_4 ( V_2 -> V_9 , V_56 ,
V_79 , V_69 ) ;
return 0 ;
}
static int F_10 ( struct V_63 * V_8 )
{
struct V_1 * V_2 = F_3 ( V_8 ) ;
struct V_80 * V_81 = F_11 ( V_8 ) ;
int V_82 , V_83 ;
F_12 ( V_2 -> V_9 , V_84 , 0x0 ) ;
F_12 ( V_2 -> V_9 , V_10 , 0x1A ) ;
F_12 ( V_2 -> V_9 , V_85 , 0x40 ) ;
if ( F_1 ( V_2 ) ) {
F_12 ( V_2 -> V_9 , V_86 , 0x3 ) ;
F_12 ( V_2 -> V_9 , V_56 , 0x43 ) ;
}
F_12 ( V_2 -> V_9 , V_75 , 0x99 ) ;
F_12 ( V_2 -> V_9 , V_87 , 0x04 ) ;
if ( F_1 ( V_2 ) ) {
V_82 = F_13 ( V_88 ) ;
V_83 = F_14 ( V_8 ,
V_88 ,
V_82 ) ;
if ( V_83 )
return V_83 ;
V_82 = F_13 ( V_89 ) ;
V_83 = F_15 ( V_81 ,
V_89 ,
V_82 ) ;
if ( V_83 )
return V_83 ;
V_82 = F_13 ( V_90 ) ;
V_83 = F_16 ( V_81 ,
V_90 ,
V_82 ) ;
if ( V_83 )
return V_83 ;
}
return 0 ;
}
int F_17 ( struct V_91 * V_92 , struct V_9 * V_9 ,
enum V_93 type )
{
struct V_1 * V_2 ;
if ( F_18 ( V_9 ) )
return F_19 ( V_9 ) ;
V_2 = F_20 ( V_92 , sizeof( * V_2 ) , V_94 ) ;
if ( V_2 == NULL )
return - V_95 ;
V_2 -> V_9 = V_9 ;
V_2 -> type = type ;
F_21 ( V_92 , V_2 ) ;
return F_22 ( V_92 , & V_96 ,
& V_97 , 1 ) ;
}
