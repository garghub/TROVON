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
return NULL ;
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
if ( ! V_17 ) {
V_35 = - V_43 ;
goto V_42;
}
F_18 ( V_22 , V_17 , V_41 . V_44 , V_41 . V_45 ) ;
V_23 -- ;
V_27 ++ ;
}
V_35 = F_17 ( V_22 -> V_46 , V_30 ,
sizeof( * V_30 ) * V_24 ) ;
if ( V_35 )
goto V_42;
while ( V_24 -- ) {
struct V_47 * V_48 = & V_22 -> V_46 [ V_24 ] ;
struct V_10 * V_41 , * V_49 ;
V_41 = F_9 ( V_5 , V_12 , ( T_1 ) V_48 -> V_41 ) ;
V_49 = F_9 ( V_5 , V_12 , ( T_1 ) V_48 -> V_49 ) ;
V_48 -> V_41 = V_41 ;
V_48 -> V_49 = V_49 ;
if ( ! V_48 -> V_49 || ! V_48 -> V_41 ) {
V_35 = - V_43 ;
goto V_42;
}
}
V_35 = F_17 ( V_22 -> V_50 , V_32 ,
sizeof( * V_32 ) * V_25 ) ;
if ( V_35 )
goto V_42;
V_35 = F_17 ( & V_34 , ( void * T_2 ) ( V_28 ) args -> V_51 ,
sizeof( V_34 ) ) ;
if ( V_35 )
goto V_42;
V_22 -> V_52 = V_34 . V_53 ;
V_22 -> V_54 = V_34 . V_55 ;
V_22 -> V_56 = 10000 ;
V_22 -> V_57 = V_58 ;
if ( args -> V_56 && args -> V_56 < 10000 )
V_22 -> V_56 = args -> V_56 ;
V_35 = F_19 ( V_22 , V_7 -> V_3 -> V_59 ) ;
if ( V_35 )
goto V_42;
V_35 = F_20 ( V_22 ) ;
if ( V_35 )
goto V_60;
args -> V_61 = V_22 -> V_62 ;
F_21 ( V_22 ) ;
return 0 ;
V_60:
F_22 ( V_22 ) ;
V_42:
F_21 ( V_22 ) ;
return V_35 ;
}
static void F_23 ( struct V_63 * V_59 , struct V_1 * V_1 )
{
const T_1 V_64 [] = { 0x1a , 0x1b , 0x26 , 0x2b , 0x2c , 0x2d , 0x31 ,
0x32 , 0x48 , 0x49 , 0x4a , 0x4b , 0x4c } ;
unsigned long * V_65 ;
int V_66 ;
V_65 = F_24 ( V_59 , F_25 ( 256 , V_67 ) ,
V_68 ) ;
for ( V_66 = 0 ; V_66 < F_26 ( V_64 ) ; ++ V_66 ) {
T_1 V_69 = V_64 [ V_66 ] ;
V_65 [ F_27 ( V_69 ) ] |= F_28 ( V_69 ) ;
}
V_1 -> V_70 = V_65 ;
}
static int V_58 ( struct V_63 * V_59 , T_1 V_39 , T_1 V_69 )
{
struct V_1 * V_1 = F_29 ( V_59 ) ;
switch ( V_39 ) {
case V_71 :
return V_69 == 0x2b ;
case V_72 :
case V_73 :
V_69 &= 0xff ;
if ( V_1 -> V_70 [ F_27 ( V_69 ) ] & F_28 ( V_69 ) )
return 1 ;
default:
return 0 ;
}
}
static int F_30 ( struct V_74 * V_75 )
{
struct V_63 * V_59 = & V_75 -> V_59 ;
struct V_76 * V_77 = F_31 ( V_59 -> V_78 ) ;
int V_35 ;
struct V_1 * V_1 = NULL ;
struct V_79 * * V_51 ;
V_1 = F_24 ( V_59 , sizeof( * V_1 ) , V_68 ) ;
if ( ! V_1 )
return - V_9 ;
V_51 = F_24 ( V_59 , sizeof( * V_51 ) , V_68 ) ;
if ( ! V_51 )
return - V_9 ;
V_1 -> V_80 = F_32 ( V_59 , NULL ) ;
if ( F_33 ( V_1 -> V_80 ) ) {
F_34 ( V_59 , L_1 ) ;
return F_35 ( V_1 -> V_80 ) ;
}
V_35 = F_36 ( V_1 -> V_80 ) ;
if ( V_35 ) {
F_34 ( V_59 , L_2 ) ;
return V_35 ;
}
V_1 -> V_8 = F_37 ( V_59 ) ;
if ( ! V_1 -> V_8 )
return - V_9 ;
* V_51 = F_38 ( V_59 , false ) ;
if ( ! ( * V_51 ) ) {
F_39 ( V_1 -> V_8 ) ;
return - V_9 ;
}
V_1 -> V_3 . V_81 = & V_82 ;
V_1 -> V_3 . V_59 = V_59 ;
V_1 -> V_3 . V_39 = V_72 ;
V_1 -> V_3 . V_51 = V_51 ;
V_1 -> V_3 . V_36 = 1 ;
V_35 = F_40 ( V_77 , & V_1 -> V_3 ) ;
if ( V_35 < 0 ) {
F_34 ( V_59 , L_3 , V_35 ) ;
return V_35 ;
}
F_23 ( V_59 , V_1 ) ;
F_41 ( V_75 , V_1 ) ;
return 0 ;
}
static int T_3 F_42 ( struct V_74 * V_75 )
{
struct V_76 * V_77 = F_31 ( V_75 -> V_59 . V_78 ) ;
struct V_1 * V_1 = F_43 ( V_75 ) ;
unsigned int V_66 ;
int V_35 ;
V_35 = F_44 ( V_77 , & V_1 -> V_3 ) ;
if ( V_35 < 0 ) {
F_34 ( & V_75 -> V_59 , L_4 , V_35 ) ;
return V_35 ;
}
for ( V_66 = 0 ; V_66 < V_1 -> V_3 . V_36 ; V_66 ++ )
F_45 ( V_1 -> V_3 . V_51 [ V_66 ] ) ;
F_39 ( V_1 -> V_8 ) ;
F_46 ( V_1 -> V_80 ) ;
return 0 ;
}
