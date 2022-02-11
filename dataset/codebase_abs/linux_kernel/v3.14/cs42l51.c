static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 + 1 ;
struct V_5 * V_5 = F_2 ( V_2 -> V_6 ) ;
T_2 V_7 ;
V_7 = F_3 ( V_5 ,
V_8 | 0x80 , V_9 , V_3 ) ;
if ( V_7 != V_9 ) {
F_4 ( & V_5 -> V_6 ,
L_1 ,
V_5 -> V_10 , V_7 , V_9 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_5 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
unsigned long V_16 = F_7 ( V_2 , V_17 ) & 3 ;
switch ( V_16 ) {
default:
case 0 :
V_15 -> V_16 . integer . V_16 [ 0 ] = 0 ;
break;
case 1 :
case 2 :
V_15 -> V_16 . integer . V_16 [ 0 ] = 1 ;
break;
case 3 :
V_15 -> V_16 . integer . V_16 [ 0 ] = 2 ;
break;
}
return 0 ;
}
static int F_8 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
unsigned char V_18 ;
switch ( V_15 -> V_16 . integer . V_16 [ 0 ] ) {
default:
case 0 :
V_18 = V_19 ;
break;
case 1 :
V_18 = V_20 ;
break;
case 2 :
V_18 = V_21 ;
break;
}
F_9 ( V_2 , V_17 , V_18 ) ;
return 1 ;
}
static int F_10 ( struct V_22 * V_23 ,
struct V_12 * V_13 , int V_24 )
{
switch ( V_24 ) {
case V_25 :
F_11 ( V_23 -> V_2 , V_26 ,
V_27 ,
V_27 ) ;
break;
default:
case V_28 :
F_11 ( V_23 -> V_2 , V_26 ,
V_27 , 0 ) ;
break;
}
return 0 ;
}
static int F_12 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_32 * V_33 = F_13 ( V_2 ) ;
switch ( V_31 & V_34 ) {
case V_35 :
case V_36 :
case V_37 :
V_33 -> V_38 = V_31 & V_34 ;
break;
default:
F_4 ( V_2 -> V_6 , L_2 ) ;
return - V_39 ;
}
switch ( V_31 & V_40 ) {
case V_41 :
V_33 -> V_42 = V_43 ;
break;
case V_44 :
V_33 -> V_42 = V_45 ;
break;
default:
F_4 ( V_2 -> V_6 , L_3 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_14 ( struct V_29 * V_30 ,
int V_46 , unsigned int V_47 , int V_48 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_32 * V_33 = F_13 ( V_2 ) ;
V_33 -> V_49 = V_47 ;
return 0 ;
}
static int F_15 ( struct V_50 * V_51 ,
struct V_52 * V_53 ,
struct V_29 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_32 * V_33 = F_13 ( V_2 ) ;
int V_55 ;
unsigned int V_56 ;
unsigned int V_57 ;
unsigned int V_58 ;
struct V_59 * V_60 = NULL ;
int V_61 = 0 ;
int V_62 , V_63 , V_64 ;
switch ( V_33 -> V_42 ) {
case V_43 :
return - V_39 ;
case V_65 :
V_60 = V_66 ;
V_61 = F_16 ( V_66 ) ;
break;
case V_45 :
V_60 = V_67 ;
V_61 = F_16 ( V_67 ) ;
break;
}
V_57 = F_17 ( V_53 ) ;
V_58 = V_33 -> V_49 / V_57 ;
for ( V_56 = 0 ; V_56 < V_61 ; V_56 ++ ) {
if ( V_60 [ V_56 ] . V_58 == V_58 )
break;
}
if ( V_56 == V_61 ) {
F_4 ( V_2 -> V_6 , L_4 ) ;
return - V_39 ;
}
V_62 = F_7 ( V_2 , V_68 ) ;
V_63 = F_7 ( V_2 , V_69 ) ;
V_62 &= ~ ( V_70 | V_71
| F_18 ( 7 ) ) ;
V_63 &= ~ ( F_19 ( 3 )
| V_72 ) ;
switch ( V_33 -> V_42 ) {
case V_43 :
V_62 |= V_70 ;
V_63 |= F_19 ( V_60 [ V_56 ] . V_73 ) ;
break;
case V_65 :
V_63 |= F_19 ( V_60 [ V_56 ] . V_73 ) ;
break;
case V_45 :
V_63 |= V_74 ;
break;
}
switch ( V_33 -> V_38 ) {
case V_35 :
V_62 |= V_71 ;
V_62 |= F_18 ( V_75 ) ;
break;
case V_36 :
V_62 |= F_18 ( V_76 ) ;
break;
case V_37 :
switch ( F_20 ( V_53 ) ) {
case 16 :
V_64 = V_77 ;
break;
case 18 :
V_64 = V_78 ;
break;
case 20 :
V_64 = V_79 ;
break;
case 24 :
V_64 = V_80 ;
break;
default:
F_4 ( V_2 -> V_6 , L_5 ) ;
return - V_39 ;
}
V_62 |= F_18 ( V_64 ) ;
break;
default:
F_4 ( V_2 -> V_6 , L_5 ) ;
return - V_39 ;
}
if ( V_60 [ V_56 ] . V_49 )
V_63 |= V_72 ;
V_55 = F_9 ( V_2 , V_68 , V_62 ) ;
if ( V_55 < 0 )
return V_55 ;
V_55 = F_9 ( V_2 , V_69 , V_63 ) ;
if ( V_55 < 0 )
return V_55 ;
return 0 ;
}
static int F_21 ( struct V_29 * V_54 , int V_81 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
int V_82 ;
int V_83 = V_84 | V_85 ;
V_82 = F_7 ( V_2 , V_86 ) ;
if ( V_81 )
V_82 |= V_83 ;
else
V_82 &= ~ V_83 ;
return F_9 ( V_2 , V_86 , V_82 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_13 ( V_2 ) ;
int V_55 , V_82 ;
V_55 = F_1 ( V_2 ) ;
if ( V_55 < 0 ) {
F_4 ( V_2 -> V_6 , L_6 ) ;
return V_55 ;
}
V_55 = F_23 ( V_2 , 8 , 8 , V_33 -> V_87 ) ;
if ( V_55 < 0 ) {
F_4 ( V_2 -> V_6 , L_7 , V_55 ) ;
return V_55 ;
}
V_82 = F_24 ( 1 )
| V_88 | F_25 ( 0 ) ;
V_55 = F_9 ( V_2 , V_89 , V_82 ) ;
if ( V_55 < 0 )
return V_55 ;
return 0 ;
}
static int F_26 ( struct V_5 * V_5 ,
const struct V_90 * V_91 )
{
struct V_32 * V_33 ;
int V_55 ;
V_55 = F_27 ( V_5 , V_92 ) ;
if ( V_55 < 0 ) {
F_4 ( & V_5 -> V_6 , L_8 ) ;
goto error;
}
if ( ( V_55 != F_28 ( V_93 , V_94 ) ) &&
( V_55 != F_28 ( V_93 , V_95 ) ) ) {
F_4 ( & V_5 -> V_6 , L_9 ) ;
V_55 = - V_96 ;
goto error;
}
F_29 ( & V_5 -> V_6 , L_10 ,
V_55 & 7 ) ;
V_33 = F_30 ( & V_5 -> V_6 , sizeof( struct V_32 ) ,
V_97 ) ;
if ( ! V_33 ) {
F_4 ( & V_5 -> V_6 , L_11 ) ;
return - V_98 ;
}
F_31 ( V_5 , V_33 ) ;
V_33 -> V_87 = V_99 ;
V_55 = F_32 ( & V_5 -> V_6 ,
& V_100 , & V_101 , 1 ) ;
error:
return V_55 ;
}
static int F_33 ( struct V_5 * V_102 )
{
F_34 ( & V_102 -> V_6 ) ;
return 0 ;
}
