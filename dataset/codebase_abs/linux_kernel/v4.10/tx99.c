static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
F_5 ( V_4 ) ;
F_6 ( V_4 ) ;
F_7 ( V_2 -> V_8 ) ;
F_8 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
V_2 -> V_10 = false ;
F_9 ( V_2 -> V_5 ) ;
F_10 ( V_7 , V_11 , L_1 ) ;
}
static struct V_12 * F_11 ( struct V_1 * V_2 )
{
static T_1 V_13 [] = { 0xff , 0x87 , 0xb8 , 0x59 , 0xb7 , 0xa1 , 0xcc , 0x24 ,
0x57 , 0x5e , 0x4b , 0x9c , 0x0e , 0xe9 , 0xea , 0x50 ,
0x2a , 0xbe , 0xb4 , 0x1b , 0xb6 , 0xb0 , 0x5d , 0xf1 ,
0xe6 , 0x9a , 0xe3 , 0x45 , 0xfd , 0x2c , 0x53 , 0x18 ,
0x0c , 0xca , 0xc9 , 0xfb , 0x49 , 0x37 , 0xe5 , 0xa8 ,
0x51 , 0x3b , 0x2f , 0x61 , 0xaa , 0x72 , 0x18 , 0x84 ,
0x02 , 0x23 , 0x23 , 0xab , 0x63 , 0x89 , 0x51 , 0xb3 ,
0xe7 , 0x8b , 0x72 , 0x90 , 0x4c , 0xe8 , 0xfb , 0xc0 } ;
T_2 V_14 = 1200 ;
struct V_15 * V_16 ;
struct V_17 * V_8 = V_2 -> V_8 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_12 * V_22 ;
struct V_23 * V_24 ;
if ( ! V_2 -> V_25 )
return NULL ;
V_24 = (struct V_23 * ) V_2 -> V_25 -> V_26 ;
V_22 = F_12 ( V_14 , V_27 ) ;
if ( ! V_22 )
return NULL ;
F_13 ( V_22 , V_14 ) ;
memset ( V_22 -> V_28 , 0 , V_14 ) ;
V_19 = (struct V_18 * ) V_22 -> V_28 ;
V_19 -> V_29 = F_14 ( V_30 ) ;
V_19 -> V_31 = 0 ;
memcpy ( V_19 -> V_32 , V_8 -> V_33 -> V_34 , V_35 ) ;
memcpy ( V_19 -> V_36 , V_8 -> V_33 -> V_34 , V_35 ) ;
memcpy ( V_19 -> V_37 , V_8 -> V_33 -> V_34 , V_35 ) ;
V_19 -> V_38 |= F_14 ( V_24 -> V_39 ) ;
V_21 = F_15 ( V_22 ) ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_16 = & V_21 -> V_40 . V_41 [ 0 ] ;
V_21 -> V_42 = V_2 -> V_43 -> V_44 . V_45 -> V_42 ;
V_21 -> V_46 = V_47 ;
V_21 -> V_40 . V_48 = V_2 -> V_25 ;
V_16 -> V_49 = 1 ;
if ( V_4 -> V_50 && F_16 ( V_4 -> V_50 ) ) {
V_16 -> V_46 |= V_51 ;
if ( F_17 ( V_4 -> V_50 ) )
V_16 -> V_46 |= V_52 ;
}
memcpy ( V_22 -> V_28 + sizeof( * V_19 ) , V_13 , sizeof( V_13 ) ) ;
return V_22 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 , NULL ) ;
F_20 ( V_2 ) ;
F_1 ( V_2 ) ;
F_21 ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_17 * V_8 = V_2 -> V_8 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_53 V_54 ;
int V_55 ;
if ( F_23 ( V_56 , & V_7 -> V_57 ) ) {
F_24 ( V_7 ,
L_2 ) ;
return - V_58 ;
}
V_2 -> V_9 = F_11 ( V_2 ) ;
if ( ! V_2 -> V_9 )
return - V_59 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_60 = V_2 -> V_61 . V_62 [ V_63 ] ;
F_19 ( V_2 , NULL ) ;
F_20 ( V_2 ) ;
F_25 ( V_4 ) ;
F_3 ( V_2 ) ;
F_26 ( V_2 ) ;
V_2 -> V_10 = true ;
F_27 ( V_8 ) ;
if ( V_2 -> V_64 == V_65 + 1 )
V_2 -> V_64 = V_65 ;
F_28 ( V_4 , V_2 -> V_64 ) ;
V_55 = F_29 ( V_2 , V_2 -> V_9 , & V_54 ) ;
if ( V_55 ) {
F_10 ( V_7 , V_11 , L_3 ) ;
return V_55 ;
}
F_10 ( V_7 , V_11 , L_4 ,
V_2 -> V_64 ,
V_2 -> V_64 / 2 ) ;
return 0 ;
}
static T_3 F_30 ( struct V_66 * V_66 , char T_4 * V_67 ,
T_5 V_49 , T_6 * V_68 )
{
struct V_1 * V_2 = V_66 -> V_69 ;
char V_70 [ 3 ] ;
unsigned int V_14 ;
V_14 = sprintf ( V_70 , L_5 , V_2 -> V_10 ) ;
return F_31 ( V_67 , V_49 , V_68 , V_70 , V_14 ) ;
}
static T_3 F_32 ( struct V_66 * V_66 , const char T_4 * V_67 ,
T_5 V_49 , T_6 * V_68 )
{
struct V_1 * V_2 = V_66 -> V_69 ;
struct V_6 * V_7 = F_2 ( V_2 -> V_5 ) ;
char V_70 [ 32 ] ;
bool V_71 ;
T_3 V_14 ;
int V_55 ;
if ( V_2 -> V_43 -> V_72 > 1 )
return - V_73 ;
V_14 = F_33 ( V_49 , sizeof( V_70 ) - 1 ) ;
if ( F_34 ( V_70 , V_67 , V_14 ) )
return - V_74 ;
if ( F_35 ( V_70 , & V_71 ) )
return - V_58 ;
if ( V_71 == V_2 -> V_10 ) {
if ( ! V_71 )
return V_49 ;
F_10 ( V_7 , V_11 , L_6 ) ;
F_18 ( V_2 ) ;
}
if ( ! V_71 ) {
F_18 ( V_2 ) ;
return V_49 ;
}
V_55 = F_22 ( V_2 ) ;
if ( V_55 )
return V_55 ;
return V_49 ;
}
static T_3 F_36 ( struct V_66 * V_66 ,
char T_4 * V_67 ,
T_5 V_49 , T_6 * V_68 )
{
struct V_1 * V_2 = V_66 -> V_69 ;
char V_70 [ 32 ] ;
unsigned int V_14 ;
V_14 = sprintf ( V_70 , L_7 ,
V_2 -> V_64 ,
V_2 -> V_64 / 2 ) ;
return F_31 ( V_67 , V_49 , V_68 , V_70 , V_14 ) ;
}
static T_3 F_37 ( struct V_66 * V_66 ,
const char T_4 * V_67 ,
T_5 V_49 , T_6 * V_68 )
{
struct V_1 * V_2 = V_66 -> V_69 ;
int V_55 ;
T_1 V_75 ;
V_55 = F_38 ( V_67 , V_49 , 0 , & V_75 ) ;
if ( V_55 )
return V_55 ;
if ( V_75 > V_65 )
return - V_58 ;
V_2 -> V_64 = V_75 ;
F_20 ( V_2 ) ;
F_28 ( V_2 -> V_5 , V_2 -> V_64 ) ;
F_21 ( V_2 ) ;
return V_49 ;
}
void F_39 ( struct V_1 * V_2 )
{
if ( ! F_40 ( V_2 -> V_5 ) )
return;
F_41 ( L_8 , V_76 | V_77 ,
V_2 -> V_78 . V_79 , V_2 ,
& V_80 ) ;
F_41 ( L_9 , V_76 | V_77 ,
V_2 -> V_78 . V_79 , V_2 ,
& V_81 ) ;
}
