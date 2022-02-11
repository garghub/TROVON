static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
return 0 ;
}
static int F_4 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_7 -> V_8 = F_6 ( V_1 -> V_8 ) ;
if ( ! V_7 -> V_8 )
return - V_9 ;
return 0 ;
}
static void F_7 ( struct V_6 * V_7 )
{
F_8 ( V_7 -> V_8 ) ;
}
static struct V_10 * F_9 ( struct V_4 * V_5 ,
struct V_11 * V_12 ,
T_1 V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
V_15 = F_10 ( V_5 , V_12 , V_13 ) ;
if ( ! V_15 )
return 0 ;
F_11 ( & V_5 -> V_18 ) ;
F_12 ( V_15 ) ;
F_13 ( & V_5 -> V_18 ) ;
V_17 = F_14 ( V_15 ) ;
return & V_17 -> V_19 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_20 * args , struct V_4 * V_5 ,
struct V_11 * V_12 )
{
struct V_21 * V_22 ;
unsigned int V_23 = args -> V_23 ;
unsigned int V_24 = args -> V_24 ;
unsigned int V_25 = args -> V_25 ;
struct V_26 T_2 * V_27 =
( void * T_2 ) ( V_28 ) args -> V_27 ;
struct V_29 T_2 * V_30 =
( void * T_2 ) ( V_28 ) args -> V_30 ;
struct V_31 T_2 * V_32 =
( void * T_2 ) ( V_28 ) args -> V_32 ;
struct V_33 V_34 ;
int V_35 ;
if ( args -> V_36 != 1 )
return - V_37 ;
V_22 = F_16 ( V_7 -> V_8 , args -> V_23 ,
args -> V_24 , args -> V_25 ) ;
if ( ! V_22 )
return - V_9 ;
V_22 -> V_24 = args -> V_24 ;
V_22 -> V_38 = args -> V_25 ;
V_22 -> V_3 = ( T_1 ) args -> V_7 ;
V_22 -> V_39 = V_7 -> V_3 -> V_39 ;
V_22 -> V_40 = true ;
while ( V_23 ) {
struct V_26 V_41 ;
struct V_10 * V_17 ;
V_35 = F_17 ( & V_41 , V_27 , sizeof( V_41 ) ) ;
if ( V_35 )
goto V_42;
V_17 = F_9 ( V_5 , V_12 , V_41 . V_13 ) ;
if ( ! V_17 )
goto V_42;
F_18 ( V_22 , V_17 , V_41 . V_43 , V_41 . V_44 ) ;
V_23 -- ;
V_27 ++ ;
}
V_35 = F_17 ( V_22 -> V_45 , V_30 ,
sizeof( * V_30 ) * V_24 ) ;
if ( V_35 )
goto V_42;
while ( V_24 -- ) {
struct V_46 * V_47 = & V_22 -> V_45 [ V_24 ] ;
struct V_10 * V_41 , * V_48 ;
V_41 = F_9 ( V_5 , V_12 , ( T_1 ) V_47 -> V_41 ) ;
V_48 = F_9 ( V_5 , V_12 , ( T_1 ) V_47 -> V_48 ) ;
V_47 -> V_41 = V_41 ;
V_47 -> V_48 = V_48 ;
if ( ! V_47 -> V_48 || ! V_47 -> V_41 )
goto V_42;
}
V_35 = F_17 ( V_22 -> V_49 , V_32 ,
sizeof( * V_32 ) * V_25 ) ;
if ( V_35 )
goto V_42;
V_35 = F_17 ( & V_34 , ( void * T_2 ) ( V_28 ) args -> V_50 ,
sizeof( V_34 ) ) ;
if ( V_35 )
goto V_42;
V_22 -> V_51 = V_34 . V_52 ;
V_22 -> V_53 = V_34 . V_54 ;
V_22 -> V_55 = 10000 ;
V_22 -> V_56 = V_57 ;
if ( args -> V_55 && args -> V_55 < 10000 )
V_22 -> V_55 = args -> V_55 ;
V_35 = F_19 ( V_22 , V_7 -> V_3 -> V_58 ) ;
if ( V_35 )
goto V_42;
V_35 = F_20 ( V_22 ) ;
if ( V_35 )
goto V_59;
args -> V_60 = V_22 -> V_61 ;
F_21 ( V_22 ) ;
return 0 ;
V_59:
F_22 ( V_22 ) ;
V_42:
F_21 ( V_22 ) ;
return V_35 ;
}
static void F_23 ( struct V_62 * V_58 , struct V_1 * V_1 )
{
const T_1 V_63 [] = { 0x1a , 0x1b , 0x26 , 0x2b , 0x2c , 0x2d , 0x31 ,
0x32 , 0x48 , 0x49 , 0x4a , 0x4b , 0x4c } ;
unsigned long * V_64 ;
int V_65 ;
V_64 = F_24 ( V_58 , F_25 ( 256 , V_66 ) ,
V_67 ) ;
for ( V_65 = 0 ; V_65 < F_26 ( V_63 ) ; ++ V_65 ) {
T_1 V_68 = V_63 [ V_65 ] ;
V_64 [ F_27 ( V_68 ) ] |= F_28 ( V_68 ) ;
}
V_1 -> V_69 = V_64 ;
}
static int V_57 ( struct V_62 * V_58 , T_1 V_39 , T_1 V_68 )
{
struct V_1 * V_1 = F_29 ( V_58 ) ;
switch ( V_39 ) {
case V_70 :
return V_68 == 0x2b ;
case V_71 :
case V_72 :
V_68 &= 0xff ;
if ( V_1 -> V_69 [ F_27 ( V_68 ) ] & F_28 ( V_68 ) )
return 1 ;
default:
return 0 ;
}
}
static int F_30 ( struct V_73 * V_74 )
{
struct V_62 * V_58 = & V_74 -> V_58 ;
struct V_75 * V_76 = F_31 ( V_58 -> V_77 ) ;
int V_35 ;
struct V_1 * V_1 = NULL ;
struct V_78 * * V_50 ;
V_1 = F_24 ( V_58 , sizeof( * V_1 ) , V_67 ) ;
if ( ! V_1 )
return - V_9 ;
V_50 = F_24 ( V_58 , sizeof( * V_50 ) , V_67 ) ;
if ( ! V_50 )
return - V_9 ;
V_1 -> V_79 = F_32 ( V_58 , NULL ) ;
if ( F_33 ( V_1 -> V_79 ) ) {
F_34 ( V_58 , L_1 ) ;
return F_35 ( V_1 -> V_79 ) ;
}
V_35 = F_36 ( V_1 -> V_79 ) ;
if ( V_35 ) {
F_34 ( V_58 , L_2 ) ;
return V_35 ;
}
V_1 -> V_8 = F_37 ( V_58 ) ;
if ( ! V_1 -> V_8 )
return - V_9 ;
* V_50 = F_38 ( V_58 , 0 ) ;
if ( ! ( * V_50 ) ) {
F_39 ( V_1 -> V_8 ) ;
return - V_9 ;
}
V_1 -> V_3 . V_80 = & V_81 ;
V_1 -> V_3 . V_58 = V_58 ;
V_1 -> V_3 . V_39 = V_71 ;
V_1 -> V_3 . V_50 = V_50 ;
V_1 -> V_3 . V_36 = 1 ;
V_35 = F_40 ( V_76 , & V_1 -> V_3 ) ;
if ( V_35 < 0 ) {
F_34 ( V_58 , L_3 , V_35 ) ;
return V_35 ;
}
F_23 ( V_58 , V_1 ) ;
F_41 ( V_74 , V_1 ) ;
return 0 ;
}
static int T_3 F_42 ( struct V_73 * V_74 )
{
struct V_75 * V_76 = F_31 ( V_74 -> V_58 . V_77 ) ;
struct V_1 * V_1 = F_43 ( V_74 ) ;
unsigned int V_65 ;
int V_35 ;
V_35 = F_44 ( V_76 , & V_1 -> V_3 ) ;
if ( V_35 < 0 ) {
F_34 ( & V_74 -> V_58 , L_4 , V_35 ) ;
return V_35 ;
}
for ( V_65 = 0 ; V_65 < V_1 -> V_3 . V_36 ; V_65 ++ )
F_45 ( V_1 -> V_3 . V_50 [ V_65 ] ) ;
F_39 ( V_1 -> V_8 ) ;
F_46 ( V_1 -> V_79 ) ;
return 0 ;
}
