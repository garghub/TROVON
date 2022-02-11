static inline int F_1 ( int V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_2 == V_2 && V_4 [ V_3 ] . V_1 == V_1 )
return V_3 ;
}
F_3 ( V_5 L_1 ,
V_1 , V_2 ) ;
return - V_6 ;
}
static int F_4 ( struct V_7 * V_8 ,
int V_9 , unsigned int V_10 , int V_11 )
{
struct V_12 * V_13 = V_8 -> V_13 ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
switch ( V_10 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
V_15 -> V_16 = V_10 ;
return 0 ;
}
return - V_6 ;
}
static int F_6 ( struct V_7 * V_8 ,
unsigned int V_17 )
{
struct V_12 * V_13 = V_8 -> V_13 ;
T_1 V_18 = 0 ;
switch ( V_17 & V_19 ) {
case V_20 :
V_18 = 0x0040 ;
break;
case V_21 :
break;
default:
return - V_6 ;
}
switch ( V_17 & V_22 ) {
case V_23 :
V_18 |= 0x0002 ;
break;
case V_24 :
break;
case V_25 :
V_18 |= 0x0001 ;
break;
case V_26 :
V_18 |= 0x0003 ;
break;
case V_27 :
V_18 |= 0x0013 ;
break;
default:
return - V_6 ;
}
switch ( V_17 & V_28 ) {
case V_29 :
break;
case V_30 :
V_18 |= 0x0090 ;
break;
case V_31 :
V_18 |= 0x0080 ;
break;
case V_32 :
V_18 |= 0x0010 ;
break;
default:
return - V_6 ;
}
F_7 ( V_13 , V_33 , V_18 ) ;
return 0 ;
}
static int F_8 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_7 * V_38 )
{
struct V_12 * V_13 = V_38 -> V_13 ;
struct V_14 * V_15 = F_5 ( V_13 ) ;
T_1 V_18 = F_9 ( V_13 , V_33 ) & 0x1f3 ;
T_1 V_39 = F_9 ( V_13 , V_40 ) & 0x1c0 ;
int V_41 = F_1 ( V_15 -> V_16 , F_10 ( V_37 ) ) ;
switch ( F_11 ( V_37 ) ) {
case 16 :
break;
case 20 :
V_18 |= 0x0004 ;
break;
case 24 :
V_18 |= 0x0008 ;
break;
case 32 :
V_18 |= 0x000c ;
break;
}
F_7 ( V_13 , V_33 , V_18 ) ;
if ( V_41 >= 0 )
F_7 ( V_13 , V_40 , V_39 |
( V_4 [ V_41 ] . V_42 << 1 ) | V_4 [ V_41 ] . V_43 ) ;
return 0 ;
}
static int F_12 ( struct V_7 * V_38 , int V_44 )
{
struct V_12 * V_13 = V_38 -> V_13 ;
T_1 V_45 = F_9 ( V_13 , V_46 ) & 0xfff7 ;
if ( V_44 )
F_7 ( V_13 , V_46 , V_45 | 0x8 ) ;
else
F_7 ( V_13 , V_46 , V_45 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_13 ,
enum V_47 V_48 )
{
T_1 V_49 = F_9 ( V_13 , V_50 ) & 0xfe3e ;
switch ( V_48 ) {
case V_51 :
F_7 ( V_13 , V_50 , V_49 | 0x00c0 ) ;
break;
case V_52 :
break;
case V_53 :
if ( V_13 -> V_54 . V_55 == V_56 ) {
F_14 ( V_13 ) ;
F_7 ( V_13 , V_50 , V_49 | 0x01c1 ) ;
F_15 ( 1000 ) ;
}
F_7 ( V_13 , V_50 , V_49 | 0x0141 ) ;
break;
case V_56 :
F_7 ( V_13 , V_50 , 0x0001 ) ;
break;
}
V_13 -> V_54 . V_55 = V_48 ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 )
{
int V_57 ;
V_57 = F_17 ( V_13 ) ;
if ( V_57 < 0 ) {
F_3 ( V_5 L_2 , V_57 ) ;
return V_57 ;
}
F_18 ( V_13 , V_58 , 0x0100 , 0x0100 ) ;
F_18 ( V_13 , V_59 , 0x0100 , 0x0100 ) ;
F_18 ( V_13 , V_60 , 0x0100 , 0x0100 ) ;
F_18 ( V_13 , V_61 , 0x0100 , 0x0100 ) ;
F_18 ( V_13 , V_62 , 0x0100 , 0x0100 ) ;
F_18 ( V_13 , V_63 , 0x0100 , 0x0100 ) ;
F_18 ( V_13 , V_64 , 0x0100 , 0x0100 ) ;
F_18 ( V_13 , V_65 , 0x0100 , 0x0100 ) ;
return V_57 ;
}
static int F_19 ( struct V_66 * V_67 )
{
struct V_14 * V_15 ;
struct V_68 * V_68 ;
int V_57 ;
V_15 = F_20 ( & V_67 -> V_69 , sizeof( struct V_14 ) ,
V_70 ) ;
if ( V_15 == NULL )
return - V_71 ;
V_68 = F_21 ( V_67 , & V_72 ) ;
if ( F_22 ( V_68 ) )
return F_23 ( V_68 ) ;
F_24 ( V_67 , V_15 ) ;
V_57 = F_25 ( & V_67 -> V_69 ,
& V_73 , & V_74 , 1 ) ;
return V_57 ;
}
static int F_26 ( struct V_66 * V_67 )
{
F_27 ( & V_67 -> V_69 ) ;
return 0 ;
}
static int F_28 ( struct V_75 * V_76 ,
const struct V_77 * V_78 )
{
struct V_14 * V_15 ;
struct V_68 * V_68 ;
int V_57 ;
V_15 = F_20 ( & V_76 -> V_69 , sizeof( struct V_14 ) ,
V_70 ) ;
if ( V_15 == NULL )
return - V_71 ;
F_29 ( V_76 , V_15 ) ;
V_68 = F_30 ( V_76 , & V_72 ) ;
if ( F_22 ( V_68 ) )
return F_23 ( V_68 ) ;
V_57 = F_25 ( & V_76 -> V_69 ,
& V_73 , & V_74 , 1 ) ;
return V_57 ;
}
static int F_31 ( struct V_75 * V_79 )
{
F_27 ( & V_79 -> V_69 ) ;
return 0 ;
}
static int T_2 F_32 ( void )
{
int V_57 = 0 ;
#if F_33 ( V_80 )
V_57 = F_34 ( & V_81 ) ;
if ( V_57 != 0 ) {
F_3 ( V_5 L_3 ,
V_57 ) ;
}
#endif
#if F_35 ( V_82 )
V_57 = F_36 ( & V_83 ) ;
if ( V_57 != 0 ) {
F_3 ( V_5 L_4 ,
V_57 ) ;
}
#endif
return V_57 ;
}
static void T_3 F_37 ( void )
{
#if F_33 ( V_80 )
F_38 ( & V_81 ) ;
#endif
#if F_35 ( V_82 )
F_39 ( & V_83 ) ;
#endif
}
