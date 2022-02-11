static int F_1 ( void * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_1 ;
int V_6 ;
T_1 V_7 ;
T_1 V_8 = V_3 ;
switch ( V_2 ) {
case V_9 :
case V_10 :
V_7 = V_11 ;
V_8 |= ( V_2 - V_9 ) << 7 ;
break;
case V_12 :
case V_13 :
case V_14 :
case V_15 :
V_7 = V_16 ;
V_8 |= ( V_2 - V_12 ) << 6 ;
break;
case V_17 :
V_7 = V_18 ;
break;
default:
V_7 = ( V_2 | V_19 ) ;
V_6 = F_2 ( & V_5 -> V_20 ,
V_16 , & V_7 , 1 ) ;
if ( V_6 != 1 )
return - V_21 ;
V_7 = V_16 ;
V_8 = ( V_3 | V_22 ) ;
break;
}
V_6 = F_2 ( & V_5 -> V_20 ,
V_7 , & V_8 , 1 ) ;
if ( V_6 != 1 )
return - V_21 ;
return 0 ;
}
static inline void F_3 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_4 ( V_24 ) ;
unsigned int V_27 = 1 << 6 ;
F_5 ( V_26 -> V_28 , V_9 , V_27 , V_27 ) ;
F_6 ( 1 ) ;
F_5 ( V_26 -> V_28 , V_9 , V_27 , 0 ) ;
}
static int F_7 ( struct V_29 * V_30 , int V_31 )
{
struct V_25 * V_26 = F_4 ( V_30 -> V_24 ) ;
unsigned int V_27 = 1 << 2 ;
unsigned int V_32 ;
F_8 ( L_1 , V_33 , V_31 ) ;
if ( V_31 )
V_32 = V_27 ;
else
V_32 = 0 ;
return F_5 ( V_26 -> V_28 , V_14 , V_27 , V_32 ) ;
}
static int F_9 ( struct V_34 * V_35 ,
struct V_29 * V_30 )
{
struct V_23 * V_24 = V_30 -> V_24 ;
struct V_25 * V_26 = F_4 ( V_24 ) ;
struct V_36 * V_37 ;
if ( V_26 -> V_38 ) {
V_37 = V_26 -> V_38 -> V_39 ;
F_8 ( L_2 , V_33 ,
V_37 -> V_40 ,
V_37 -> V_41 ) ;
F_10 ( V_35 -> V_39 ,
V_42 ,
V_37 -> V_41 ,
V_37 -> V_41 ) ;
F_10 ( V_35 -> V_39 ,
V_43 ,
V_37 -> V_40 ,
V_37 -> V_40 ) ;
V_26 -> V_44 = V_35 ;
} else
V_26 -> V_38 = V_35 ;
return 0 ;
}
static void F_11 ( struct V_34 * V_35 ,
struct V_29 * V_30 )
{
struct V_23 * V_24 = V_30 -> V_24 ;
struct V_25 * V_26 = F_4 ( V_24 ) ;
if ( V_26 -> V_38 == V_35 )
V_26 -> V_38 = V_26 -> V_44 ;
V_26 -> V_44 = NULL ;
}
static int F_12 ( struct V_34 * V_35 ,
struct V_45 * V_46 ,
struct V_29 * V_30 )
{
struct V_23 * V_24 = V_30 -> V_24 ;
struct V_25 * V_26 = F_4 ( V_24 ) ;
unsigned int V_47 = 0 ;
if ( V_35 == V_26 -> V_44 ) {
F_8 ( L_3 ,
V_33 ) ;
return 0 ;
}
F_8 ( L_4 , V_33 ,
V_26 -> V_48 , F_13 ( V_46 ) ) ;
switch ( V_26 -> V_48 / F_13 ( V_46 ) ) {
case 512 :
break;
case 384 :
V_47 |= ( 1 << 4 ) ;
break;
case 256 :
V_47 |= ( 1 << 5 ) ;
break;
default:
F_14 ( V_49 L_5 , V_33 ) ;
return - V_50 ;
}
F_8 ( L_6 , V_33 ,
V_26 -> V_51 , F_15 ( V_46 ) ) ;
switch ( V_26 -> V_51 & V_52 ) {
case V_53 :
break;
case V_54 :
switch ( F_16 ( V_46 ) ) {
case 16 :
V_47 |= ( 1 << 1 ) ;
break;
case 18 :
V_47 |= ( 1 << 2 ) ;
break;
case 20 :
V_47 |= ( ( 1 << 2 ) | ( 1 << 1 ) ) ;
break;
default:
F_14 ( V_49 L_7 ,
V_33 ) ;
return - V_50 ;
}
break;
case V_55 :
V_47 |= ( 1 << 3 ) ;
break;
default:
F_14 ( V_49 L_8 , V_33 ) ;
return - V_50 ;
}
return F_5 ( V_26 -> V_28 , V_9 ,
V_56 | V_57 , V_47 ) ;
}
static int F_17 ( struct V_29 * V_58 ,
int V_59 , unsigned int V_60 , int V_61 )
{
struct V_23 * V_24 = V_58 -> V_24 ;
struct V_25 * V_26 = F_4 ( V_24 ) ;
F_8 ( L_9 , V_33 ,
V_59 , V_60 , V_61 ) ;
if ( ( V_60 >= ( 256 * 8000 ) ) && ( V_60 <= ( 512 * 48000 ) ) ) {
V_26 -> V_48 = V_60 ;
return 0 ;
}
F_14 ( V_49 L_10 , V_33 ) ;
return - V_50 ;
}
static int F_18 ( struct V_29 * V_58 ,
unsigned int V_62 )
{
struct V_23 * V_24 = V_58 -> V_24 ;
struct V_25 * V_26 = F_4 ( V_24 ) ;
F_8 ( L_11 , V_33 , V_62 ) ;
if ( ( V_62 & V_63 ) != V_64 ) {
F_14 ( V_49 L_12 , V_33 ) ;
return - V_50 ;
}
if ( ( V_62 & V_65 ) != V_66 ) {
F_14 ( V_49 L_13 , V_33 ) ;
return - V_50 ;
}
V_26 -> V_51 = V_62 ;
return 0 ;
}
static int F_19 ( struct V_23 * V_24 ,
enum V_67 V_68 )
{
struct V_25 * V_26 = F_4 ( V_24 ) ;
struct V_4 * V_5 = V_26 -> V_5 ;
F_8 ( L_14 , V_33 , V_68 ) ;
switch ( V_68 ) {
case V_69 :
break;
case V_70 :
if ( V_5 -> V_71 ) {
V_5 -> V_71 ( 1 ) ;
F_20 ( V_26 -> V_28 ) ;
}
break;
case V_72 :
break;
case V_73 :
if ( V_5 -> V_71 ) {
V_5 -> V_71 ( 0 ) ;
F_21 ( V_26 -> V_28 ) ;
}
break;
}
return 0 ;
}
static int F_22 ( struct V_23 * V_24 )
{
struct V_74 * V_75 = F_23 ( V_24 ) ;
struct V_25 * V_26 = F_4 ( V_24 ) ;
struct V_4 * V_5 = V_26 -> V_5 ;
const struct V_76 * V_77 ;
unsigned V_78 ;
int V_6 ;
F_14 ( V_79 L_15 ) ;
switch ( V_5 -> V_80 ) {
case V_81 :
case V_82 :
case V_83 :
case V_84 :
break;
default:
F_14 ( V_49 L_16
L_17 ,
V_5 -> V_80 ) ;
return - V_50 ;
}
if ( V_5 -> V_71 )
V_5 -> V_71 ( 1 ) ;
F_3 ( V_24 ) ;
if ( V_5 -> V_80 == V_82 ) {
V_77 = V_85 ;
V_78 = F_24 ( V_85 ) ;
} else {
V_77 = V_86 ;
V_78 = F_24 ( V_86 ) ;
}
V_6 = F_25 ( V_75 , V_77 , V_78 ) ;
if ( V_6 ) {
F_14 ( V_49 L_18 ,
V_33 , V_6 ) ;
return V_6 ;
}
switch ( V_5 -> V_80 ) {
case V_81 :
case V_83 :
V_6 = F_26 ( V_24 , V_87 ,
F_24 ( V_87 ) ) ;
break;
case V_82 :
V_6 = F_26 ( V_24 , V_88 ,
F_24 ( V_88 ) ) ;
break;
case V_84 :
V_6 = F_26 ( V_24 , V_89 ,
F_24 ( V_89 ) ) ;
break;
default:
F_14 ( V_49 L_19 ,
V_33 , V_5 -> V_80 ) ;
return - V_50 ;
}
if ( V_6 < 0 ) {
F_14 ( V_49 L_20 ) ;
return V_6 ;
}
return 0 ;
}
static int F_27 ( struct V_90 * V_91 )
{
struct V_4 * V_5 = V_91 -> V_92 . V_93 ;
struct V_25 * V_26 ;
if ( ! V_5 ) {
F_28 ( & V_91 -> V_92 , L_21 ) ;
return - V_94 ;
}
V_26 = F_29 ( & V_91 -> V_92 , sizeof( * V_26 ) , V_95 ) ;
if ( ! V_26 )
return - V_96 ;
V_26 -> V_5 = V_5 ;
F_30 ( V_91 , V_26 ) ;
V_26 -> V_28 = F_31 ( & V_91 -> V_92 , NULL , V_5 ,
& V_97 ) ;
if ( F_32 ( V_26 -> V_28 ) )
return F_33 ( V_26 -> V_28 ) ;
return F_34 ( & V_91 -> V_92 ,
& V_98 , & V_99 , 1 ) ;
}
static int F_35 ( struct V_90 * V_91 )
{
F_36 ( & V_91 -> V_92 ) ;
return 0 ;
}
