static void F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_3 = V_1 ;
T_1 V_4 = V_5 ;
if ( ! V_3 -> V_6 )
V_4 |= V_7 ;
if ( V_2 & V_8 )
V_4 |= V_9 ;
if ( V_2 & V_10 )
V_4 |= V_11 ;
if ( V_2 & V_12 )
V_4 |= V_13 ;
F_2 ( & V_3 -> V_14 ) ;
F_3 ( V_4 , V_3 -> V_15 ) ;
F_4 ( & V_3 -> V_14 ) ;
}
static inline void F_5 ( struct V_3 * V_3 )
{
F_2 ( & V_3 -> V_14 ) ;
F_6 ( 0x00 , V_3 -> V_15 ) ;
F_4 ( & V_3 -> V_14 ) ;
}
static inline void F_7 ( struct V_3 * V_3 )
{
F_2 ( & V_3 -> V_14 ) ;
F_6 ( 0x08 , V_3 -> V_15 ) ;
F_4 ( & V_3 -> V_14 ) ;
}
static inline int F_8 ( struct V_3 * V_3 )
{
int V_16 ;
int V_17 ;
F_2 ( & V_3 -> V_14 ) ;
V_16 = V_3 -> V_6 ? 0x00 : 0x08 ;
F_6 ( V_16 , V_3 -> V_15 ) ;
F_6 ( V_16 | 0x10 , V_3 -> V_15 ) ;
F_9 ( 143 ) ;
V_17 = ( int ) F_10 ( V_3 -> V_15 + 1 ) ;
F_6 ( V_16 , V_3 -> V_15 ) ;
F_4 ( & V_3 -> V_14 ) ;
return ( V_17 & 2 ) ? 0 : 0xFFFF ;
}
static int F_11 ( struct V_18 * V_18 , void * V_19 ,
struct V_20 * V_21 )
{
F_12 ( V_21 -> V_22 , L_1 , sizeof( V_21 -> V_22 ) ) ;
F_12 ( V_21 -> V_23 , L_2 , sizeof( V_21 -> V_23 ) ) ;
F_12 ( V_21 -> V_24 , L_3 , sizeof( V_21 -> V_24 ) ) ;
V_21 -> V_25 = V_26 | V_27 ;
return 0 ;
}
static int F_13 ( struct V_18 * V_18 , void * V_19 ,
struct V_28 * V_21 )
{
struct V_3 * V_3 = F_14 ( V_18 ) ;
if ( V_21 -> V_29 > 0 )
return - V_30 ;
F_12 ( V_21 -> V_31 , L_4 , sizeof( V_21 -> V_31 ) ) ;
V_21 -> type = V_32 ;
V_21 -> V_33 = V_34 ;
V_21 -> V_35 = V_36 ;
V_21 -> V_37 = V_38 | V_39 ;
V_21 -> V_40 = V_41 | V_42 ;
V_21 -> V_43 = V_44 ;
V_21 -> signal = F_8 ( V_3 ) ;
return 0 ;
}
static int F_15 ( struct V_18 * V_18 , void * V_19 ,
const struct V_28 * V_21 )
{
return V_21 -> V_29 ? - V_30 : 0 ;
}
static int F_16 ( struct V_18 * V_18 , void * V_19 ,
const struct V_45 * V_46 )
{
struct V_3 * V_3 = F_14 ( V_18 ) ;
if ( V_46 -> V_47 != 0 || V_46 -> type != V_32 )
return - V_30 ;
if ( V_46 -> V_48 < V_34 ||
V_46 -> V_48 > V_36 )
return - V_30 ;
F_17 ( ( V_46 -> V_48 / 800 ) * 800 , V_3 , F_1 ) ;
return 0 ;
}
static int F_18 ( struct V_18 * V_18 , void * V_19 ,
struct V_45 * V_46 )
{
struct V_3 * V_3 = F_14 ( V_18 ) ;
if ( V_46 -> V_47 != 0 )
return - V_30 ;
V_46 -> type = V_32 ;
V_46 -> V_48 = V_3 -> V_49 ;
return 0 ;
}
static int F_19 ( struct V_18 * V_18 , void * V_19 ,
struct V_50 * V_51 )
{
switch ( V_51 -> V_52 ) {
case V_53 :
return F_20 ( V_51 , 0 , 1 , 1 , 1 ) ;
}
return - V_30 ;
}
static int F_21 ( struct V_18 * V_18 , void * V_19 ,
struct V_54 * V_55 )
{
struct V_3 * V_3 = F_14 ( V_18 ) ;
switch ( V_55 -> V_52 ) {
case V_53 :
V_55 -> V_56 = V_3 -> V_6 ;
return 0 ;
}
return - V_30 ;
}
static int F_22 ( struct V_18 * V_18 , void * V_19 ,
struct V_54 * V_55 )
{
struct V_3 * V_3 = F_14 ( V_18 ) ;
switch ( V_55 -> V_52 ) {
case V_53 :
if ( V_55 -> V_56 )
F_5 ( V_3 ) ;
else
F_7 ( V_3 ) ;
V_3 -> V_6 = V_55 -> V_56 ;
return 0 ;
}
return - V_30 ;
}
static int F_23 ( struct V_18 * V_57 , void * V_19 , unsigned int * V_58 )
{
* V_58 = 0 ;
return 0 ;
}
static int F_24 ( struct V_18 * V_57 , void * V_19 , unsigned int V_58 )
{
return V_58 ? - V_30 : 0 ;
}
static int F_25 ( struct V_18 * V_18 , void * V_19 ,
struct V_59 * V_60 )
{
V_60 -> V_29 = 0 ;
F_12 ( V_60 -> V_31 , L_5 , sizeof( V_60 -> V_31 ) ) ;
V_60 -> V_40 = V_61 ;
return 0 ;
}
static int F_26 ( struct V_18 * V_18 , void * V_19 ,
const struct V_59 * V_60 )
{
return V_60 -> V_29 ? - V_30 : 0 ;
}
static int T_2 F_27 ( void )
{
int V_58 = 0 ;
while ( V_62 [ V_58 ] . V_63 != 0 && V_64 == NULL ) {
V_64 = F_28 ( NULL , V_62 [ V_58 ] . V_65 ,
V_62 [ V_58 ] . V_66 , NULL ) ;
V_58 ++ ;
}
if ( ! V_64 )
return - V_67 ;
if ( F_29 ( V_64 ) < 0 )
return - V_68 ;
if ( F_30 ( V_64 ) < 0 ) {
F_31 ( V_69 L_6 ) ;
F_32 ( V_64 ) ;
return - V_70 ;
}
if ( ! F_33 ( V_64 , 0 ) ) {
F_32 ( V_64 ) ;
return - V_67 ;
}
V_58 = F_34 ( V_64 , 0 ) ;
F_31 ( V_71 L_7 , V_58 ) ;
return V_58 ;
}
static int T_2 F_35 ( void )
{
struct V_3 * V_3 = & V_72 ;
struct V_73 * V_74 = & V_3 -> V_74 ;
int V_17 , V_58 ;
int V_75 [] = { 0 , 0x284 , 0x384 } ;
if ( V_15 < 0 ) {
for ( V_58 = 0 ; V_58 < F_36 ( V_75 ) ; V_58 ++ ) {
V_15 = V_75 [ V_58 ] ;
if ( V_15 == 0 ) {
V_15 = F_27 () ;
if ( V_15 < 0 )
continue;
V_76 = 1 ;
}
if ( ! F_37 ( V_15 , 2 , L_1 ) ) {
if ( V_76 )
F_32 ( V_64 ) ;
V_15 = - 1 ;
continue;
}
if ( V_76 ||
( ( F_10 ( V_15 ) & 0xf9 ) == 0xf9 && ( F_10 ( V_15 ) & 0x4 ) == 0 ) )
break;
F_38 ( V_15 , 2 ) ;
V_15 = - 1 ;
}
} else {
if ( ! F_37 ( V_15 , 2 , L_1 ) ) {
F_31 ( V_69 L_8 , V_15 ) ;
return - V_77 ;
}
if ( F_10 ( V_15 ) == 0xff ) {
F_31 ( V_69 L_9 , V_15 ) ;
F_38 ( V_15 , 2 ) ;
return - V_67 ;
}
}
if ( V_15 < 0 ) {
F_31 ( V_69 L_10 ) ;
return - V_67 ;
}
F_12 ( V_74 -> V_31 , L_11 , sizeof( V_74 -> V_31 ) ) ;
V_3 -> V_15 = V_15 ;
V_17 = F_39 ( NULL , V_74 ) ;
if ( V_17 < 0 ) {
F_38 ( V_3 -> V_15 , 2 ) ;
if ( V_76 )
F_32 ( V_64 ) ;
F_40 ( V_74 , L_12 ) ;
return V_17 ;
}
F_12 ( V_3 -> V_78 . V_31 , V_74 -> V_31 , sizeof( V_3 -> V_78 . V_31 ) ) ;
V_3 -> V_78 . V_74 = V_74 ;
V_3 -> V_78 . V_79 = & V_80 ;
V_3 -> V_78 . V_81 = & V_82 ;
V_3 -> V_78 . V_83 = V_84 ;
F_41 ( & V_3 -> V_78 , V_3 ) ;
F_42 ( & V_3 -> V_14 ) ;
F_5 ( V_3 ) ;
if ( F_43 ( & V_3 -> V_78 , V_85 , V_86 ) < 0 ) {
F_44 ( V_74 ) ;
F_38 ( V_3 -> V_15 , 2 ) ;
if ( V_76 )
F_32 ( V_64 ) ;
return - V_30 ;
}
F_45 ( V_74 , L_13 , V_3 -> V_15 ) ;
return 0 ;
}
static void T_3 F_46 ( void )
{
struct V_3 * V_3 = & V_72 ;
F_47 ( & V_3 -> V_78 ) ;
F_44 ( & V_3 -> V_74 ) ;
F_38 ( V_3 -> V_15 , 2 ) ;
if ( V_64 && V_76 )
F_32 ( V_64 ) ;
}
