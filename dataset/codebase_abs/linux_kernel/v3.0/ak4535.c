static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_6 )
return - 1 ;
return V_4 [ V_3 ] ;
}
static inline void F_2 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_7 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_6 )
return;
V_4 [ V_3 ] = V_7 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_7 )
{
T_2 V_8 [ 2 ] ;
V_8 [ 0 ] = V_3 & 0xff ;
V_8 [ 1 ] = V_7 & 0xff ;
F_2 ( V_2 , V_3 , V_7 ) ;
if ( V_2 -> V_9 ( V_2 -> V_10 , V_8 , 2 ) == 2 )
return 0 ;
else
return - V_11 ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_5 ;
int V_12 , V_13 = 0 ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ )
V_13 |= F_3 ( V_2 , V_12 , V_4 [ V_12 ] ) ;
return V_13 ;
}
static int F_5 ( struct V_14 * V_15 ,
int V_16 , unsigned int V_17 , int V_18 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_19 * V_20 = F_6 ( V_2 ) ;
V_20 -> V_21 = V_17 ;
return 0 ;
}
static int F_7 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
struct V_14 * V_26 )
{
struct V_27 * V_28 = V_23 -> V_29 ;
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_19 * V_20 = F_6 ( V_2 ) ;
T_2 V_30 = F_1 ( V_2 , V_31 ) & ~ ( 0x3 << 5 ) ;
int V_32 = F_8 ( V_25 ) , V_33 = 256 ;
if ( V_32 )
V_33 = V_20 -> V_21 / V_32 ;
switch ( V_33 ) {
case 1024 :
V_30 |= ( 0x2 << 5 ) ;
break;
case 512 :
V_30 |= ( 0x1 << 5 ) ;
break;
case 256 :
break;
}
F_3 ( V_2 , V_31 , V_30 ) ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 ,
unsigned int V_34 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
T_2 V_35 = 0 ;
switch ( V_34 & V_36 ) {
case V_37 :
V_35 = 0x0002 ;
break;
case V_38 :
V_35 = 0x0001 ;
break;
default:
return - V_39 ;
}
V_35 |= 0x4 ;
F_3 ( V_2 , V_40 , V_35 ) ;
return 0 ;
}
static int F_10 ( struct V_14 * V_26 , int V_41 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
T_1 V_42 = F_1 ( V_2 , V_43 ) ;
if ( ! V_41 )
F_3 ( V_2 , V_43 , V_42 & ~ 0x20 ) ;
else
F_3 ( V_2 , V_43 , V_42 | 0x20 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
enum V_44 V_45 )
{
T_1 V_12 , V_42 ;
switch ( V_45 ) {
case V_46 :
V_42 = F_1 ( V_2 , V_43 ) ;
F_3 ( V_2 , V_43 , V_42 & ~ 0x20 ) ;
break;
case V_47 :
V_42 = F_1 ( V_2 , V_43 ) ;
F_3 ( V_2 , V_43 , V_42 | 0x20 ) ;
break;
case V_48 :
V_12 = F_1 ( V_2 , V_49 ) ;
F_3 ( V_2 , V_49 , V_12 | 0x80 ) ;
V_12 = F_1 ( V_2 , V_50 ) ;
F_3 ( V_2 , V_50 , V_12 & ( ~ 0x80 ) ) ;
break;
case V_51 :
V_12 = F_1 ( V_2 , V_49 ) ;
F_3 ( V_2 , V_49 , V_12 & ( ~ 0x80 ) ) ;
break;
}
V_2 -> V_52 . V_53 = V_45 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_3 V_54 )
{
F_11 ( V_2 , V_51 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
F_11 ( V_2 , V_48 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_6 ( V_2 ) ;
F_15 ( V_55 L_1 , V_56 ) ;
V_2 -> V_10 = V_20 -> V_10 ;
F_11 ( V_2 , V_48 ) ;
F_16 ( V_2 , V_57 ,
F_17 ( V_57 ) ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_51 ) ;
return 0 ;
}
static T_4 int F_19 ( struct V_58 * V_59 ,
const struct V_60 * V_61 )
{
struct V_19 * V_20 ;
int V_62 ;
V_20 = F_20 ( sizeof( struct V_19 ) , V_63 ) ;
if ( V_20 == NULL )
return - V_64 ;
F_21 ( V_59 , V_20 ) ;
V_20 -> V_10 = V_59 ;
V_20 -> V_65 = V_66 ;
V_62 = F_22 ( & V_59 -> V_67 ,
& V_68 , & V_69 , 1 ) ;
if ( V_62 < 0 )
F_23 ( V_20 ) ;
return V_62 ;
}
static T_5 int F_24 ( struct V_58 * V_70 )
{
F_25 ( & V_70 -> V_67 ) ;
F_23 ( F_26 ( V_70 ) ) ;
return 0 ;
}
static int T_6 F_27 ( void )
{
int V_62 = 0 ;
#if F_28 ( V_71 ) || F_28 ( V_72 )
V_62 = F_29 ( & V_73 ) ;
if ( V_62 != 0 ) {
F_15 ( V_74 L_2 ,
V_62 ) ;
}
#endif
return V_62 ;
}
static void T_7 F_30 ( void )
{
#if F_28 ( V_71 ) || F_28 ( V_72 )
F_31 ( & V_73 ) ;
#endif
}
