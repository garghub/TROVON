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
static void F_11 ( struct V_3 * V_3 )
{
V_3 -> V_18 = F_12 ( V_3 -> V_18 , V_19 , V_20 ) ;
F_13 ( ( V_3 -> V_18 / 800 ) * 800 , V_3 , F_1 ) ;
}
static int F_14 ( struct V_21 * V_21 , void * V_22 ,
struct V_23 * V_24 )
{
F_15 ( V_24 -> V_25 , L_1 , sizeof( V_24 -> V_25 ) ) ;
F_15 ( V_24 -> V_26 , L_2 , sizeof( V_24 -> V_26 ) ) ;
F_15 ( V_24 -> V_27 , L_3 , sizeof( V_24 -> V_27 ) ) ;
V_24 -> V_28 = V_29 | V_30 ;
V_24 -> V_31 = V_24 -> V_28 | V_32 ;
return 0 ;
}
static int F_16 ( struct V_21 * V_21 , void * V_22 ,
struct V_33 * V_24 )
{
struct V_3 * V_3 = F_17 ( V_21 ) ;
if ( V_24 -> V_34 > 0 )
return - V_35 ;
F_15 ( V_24 -> V_36 , L_4 , sizeof( V_24 -> V_36 ) ) ;
V_24 -> type = V_37 ;
V_24 -> V_38 = V_19 ;
V_24 -> V_39 = V_20 ;
V_24 -> V_40 = V_41 | V_42 ;
V_24 -> V_43 = V_44 | V_45 ;
V_24 -> V_46 = V_47 ;
V_24 -> signal = F_8 ( V_3 ) ;
return 0 ;
}
static int F_18 ( struct V_21 * V_21 , void * V_22 ,
const struct V_33 * V_24 )
{
return V_24 -> V_34 ? - V_35 : 0 ;
}
static int F_19 ( struct V_21 * V_21 , void * V_22 ,
const struct V_48 * V_49 )
{
struct V_3 * V_3 = F_17 ( V_21 ) ;
if ( V_49 -> V_50 != 0 || V_49 -> type != V_37 )
return - V_35 ;
V_3 -> V_18 = V_49 -> V_51 ;
F_11 ( V_3 ) ;
return 0 ;
}
static int F_20 ( struct V_21 * V_21 , void * V_22 ,
struct V_48 * V_49 )
{
struct V_3 * V_3 = F_17 ( V_21 ) ;
if ( V_49 -> V_50 != 0 )
return - V_35 ;
V_49 -> type = V_37 ;
V_49 -> V_51 = V_3 -> V_18 ;
return 0 ;
}
static int F_21 ( struct V_52 * V_53 )
{
struct V_3 * V_3 = F_22 ( V_53 -> V_54 , struct V_3 , V_55 ) ;
switch ( V_53 -> V_56 ) {
case V_57 :
if ( V_53 -> V_16 )
F_5 ( V_3 ) ;
else
F_7 ( V_3 ) ;
V_3 -> V_6 = V_53 -> V_16 ;
return 0 ;
}
return - V_35 ;
}
static int T_2 F_23 ( void )
{
int V_58 = 0 ;
while ( V_59 [ V_58 ] . V_60 != 0 && V_61 == NULL ) {
V_61 = F_24 ( NULL , V_59 [ V_58 ] . V_62 ,
V_59 [ V_58 ] . V_63 , NULL ) ;
V_58 ++ ;
}
if ( ! V_61 )
return - V_64 ;
if ( F_25 ( V_61 ) < 0 )
return - V_65 ;
if ( F_26 ( V_61 ) < 0 ) {
F_27 ( V_66 L_5 ) ;
F_28 ( V_61 ) ;
return - V_67 ;
}
if ( ! F_29 ( V_61 , 0 ) ) {
F_28 ( V_61 ) ;
return - V_64 ;
}
V_58 = F_30 ( V_61 , 0 ) ;
F_27 ( V_68 L_6 , V_58 ) ;
return V_58 ;
}
static int T_2 F_31 ( void )
{
struct V_3 * V_3 = & V_69 ;
struct V_70 * V_71 = & V_3 -> V_71 ;
struct V_72 * V_55 = & V_3 -> V_55 ;
int V_17 , V_58 ;
int V_73 [] = { 0 , 0x284 , 0x384 } ;
if ( V_15 < 0 ) {
for ( V_58 = 0 ; V_58 < F_32 ( V_73 ) ; V_58 ++ ) {
V_15 = V_73 [ V_58 ] ;
if ( V_15 == 0 ) {
V_15 = F_23 () ;
if ( V_15 < 0 )
continue;
V_74 = true ;
}
if ( ! F_33 ( V_15 , 2 , L_1 ) ) {
if ( V_74 )
F_28 ( V_61 ) ;
V_15 = - 1 ;
continue;
}
if ( V_74 ||
( ( F_10 ( V_15 ) & 0xf9 ) == 0xf9 && ( F_10 ( V_15 ) & 0x4 ) == 0 ) )
break;
F_34 ( V_15 , 2 ) ;
V_15 = - 1 ;
}
} else {
if ( ! F_33 ( V_15 , 2 , L_1 ) ) {
F_27 ( V_66 L_7 , V_15 ) ;
return - V_75 ;
}
if ( F_10 ( V_15 ) == 0xff ) {
F_27 ( V_66 L_8 , V_15 ) ;
F_34 ( V_15 , 2 ) ;
return - V_64 ;
}
}
if ( V_15 < 0 ) {
F_27 ( V_66 L_9 ) ;
return - V_64 ;
}
F_15 ( V_71 -> V_36 , L_10 , sizeof( V_71 -> V_36 ) ) ;
V_3 -> V_15 = V_15 ;
V_17 = F_35 ( NULL , V_71 ) ;
if ( V_17 < 0 ) {
F_34 ( V_3 -> V_15 , 2 ) ;
if ( V_74 )
F_28 ( V_61 ) ;
F_36 ( V_71 , L_11 ) ;
return V_17 ;
}
F_37 ( V_55 , 1 ) ;
F_38 ( V_55 , & V_76 ,
V_57 , 0 , 1 , 1 , 1 ) ;
V_71 -> V_77 = V_55 ;
if ( V_55 -> error ) {
V_17 = V_55 -> error ;
F_36 ( V_71 , L_12 ) ;
F_39 ( V_55 ) ;
F_40 ( V_71 ) ;
return V_17 ;
}
F_15 ( V_3 -> V_78 . V_36 , V_71 -> V_36 , sizeof( V_3 -> V_78 . V_36 ) ) ;
V_3 -> V_78 . V_71 = V_71 ;
V_3 -> V_78 . V_79 = & V_80 ;
V_3 -> V_78 . V_81 = & V_82 ;
V_3 -> V_78 . V_83 = V_84 ;
F_41 ( & V_3 -> V_78 , V_3 ) ;
F_42 ( & V_3 -> V_14 ) ;
V_3 -> V_6 = true ;
V_3 -> V_18 = V_19 ;
F_11 ( V_3 ) ;
if ( F_43 ( & V_3 -> V_78 , V_85 , V_86 ) < 0 ) {
F_39 ( V_55 ) ;
F_40 ( V_71 ) ;
F_34 ( V_3 -> V_15 , 2 ) ;
if ( V_74 )
F_28 ( V_61 ) ;
return - V_35 ;
}
F_44 ( V_71 , L_13 , V_3 -> V_15 ) ;
return 0 ;
}
static void T_3 F_45 ( void )
{
struct V_3 * V_3 = & V_69 ;
F_39 ( & V_3 -> V_55 ) ;
F_46 ( & V_3 -> V_78 ) ;
F_40 ( & V_3 -> V_71 ) ;
F_34 ( V_3 -> V_15 , 2 ) ;
if ( V_61 && V_74 )
F_28 ( V_61 ) ;
}
