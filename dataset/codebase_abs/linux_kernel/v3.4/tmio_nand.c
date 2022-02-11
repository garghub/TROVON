static void F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_4 & V_10 ) {
T_1 V_11 ;
if ( V_4 & V_12 ) {
V_11 = V_13 ;
if ( V_4 & V_14 )
V_11 |= V_15 ;
else
V_11 &= ~ V_15 ;
if ( V_4 & V_16 )
V_11 |= V_17 ;
else
V_11 &= ~ V_17 ;
} else {
V_11 = V_18 ;
}
F_3 ( V_11 , V_6 -> V_19 + V_20 ) ;
V_6 -> V_21 = 0 ;
}
if ( V_3 != V_22 )
F_3 ( V_3 , V_8 -> V_23 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return ! ( F_5 ( V_6 -> V_19 + V_24 ) & V_25 ) ;
}
static T_2 F_6 ( int V_26 , void * V_27 )
{
struct V_5 * V_6 = V_27 ;
struct V_7 * V_7 = & V_6 -> V_8 ;
F_3 ( 0x00 , V_6 -> V_19 + V_28 ) ;
if ( F_7 ( ! F_8 ( & V_7 -> V_29 -> V_30 ) ) )
F_9 ( & V_6 -> V_31 -> V_31 , L_1 ) ;
F_10 ( & V_7 -> V_29 -> V_30 ) ;
return V_32 ;
}
static int
F_11 ( struct V_1 * V_2 , struct V_7 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
long V_33 ;
F_3 ( 0x0f , V_6 -> V_19 + V_34 ) ;
F_3 ( 0x81 , V_6 -> V_19 + V_28 ) ;
V_33 = F_12 ( V_7 -> V_29 -> V_30 ,
F_4 ( V_2 ) ,
F_13 ( V_7 -> V_35 == V_36 ? 400 : 20 ) ) ;
if ( F_7 ( ! F_4 ( V_2 ) ) ) {
F_3 ( 0x00 , V_6 -> V_19 + V_28 ) ;
F_9 ( & V_6 -> V_31 -> V_31 , L_2 ,
V_7 -> V_35 == V_36 ? L_3 : L_4 ,
V_7 -> V_35 == V_36 ? 400 : 20 ) ;
} else if ( F_7 ( ! V_33 ) ) {
F_3 ( 0x00 , V_6 -> V_19 + V_28 ) ;
F_9 ( & V_6 -> V_31 -> V_31 , L_5 ) ;
}
V_7 -> V_37 ( V_2 , V_38 , - 1 , - 1 ) ;
return V_7 -> V_39 ( V_2 ) ;
}
static T_3 F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_40 ;
if ( V_6 -> V_21 -- )
return V_6 -> V_41 ;
V_40 = F_15 ( V_6 -> V_19 + V_42 ) ;
V_6 -> V_41 = V_40 >> 8 ;
return V_40 ;
}
static void
F_16 ( struct V_1 * V_2 , const T_3 * V_43 , int V_44 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_17 ( V_6 -> V_19 + V_42 , V_43 , V_44 >> 1 ) ;
}
static void F_18 ( struct V_1 * V_2 , T_3 * V_43 , int V_44 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_19 ( V_6 -> V_19 + V_42 , V_43 , V_44 >> 1 ) ;
}
static int
F_20 ( struct V_1 * V_2 , const T_3 * V_43 , int V_44 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 * V_45 = ( T_4 * ) V_43 ;
for ( V_44 >>= 1 ; V_44 ; V_44 -- )
if ( * ( V_45 ++ ) != F_15 ( V_6 -> V_19 + V_42 ) )
return - V_46 ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , int V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_47 , V_6 -> V_19 + V_20 ) ;
F_5 ( V_6 -> V_19 + V_42 ) ;
F_3 ( V_48 , V_6 -> V_19 + V_20 ) ;
}
static int F_22 ( struct V_1 * V_2 , const T_3 * V_49 ,
T_3 * V_50 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_51 ;
F_3 ( V_52 , V_6 -> V_19 + V_20 ) ;
V_51 = F_15 ( V_6 -> V_19 + V_42 ) ;
V_50 [ 1 ] = V_51 ;
V_50 [ 0 ] = V_51 >> 8 ;
V_51 = F_15 ( V_6 -> V_19 + V_42 ) ;
V_50 [ 2 ] = V_51 ;
V_50 [ 4 ] = V_51 >> 8 ;
V_51 = F_15 ( V_6 -> V_19 + V_42 ) ;
V_50 [ 3 ] = V_51 ;
V_50 [ 5 ] = V_51 >> 8 ;
F_3 ( V_13 , V_6 -> V_19 + V_20 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , unsigned char * V_43 ,
unsigned char * V_53 , unsigned char * V_54 )
{
int V_55 , V_56 ;
V_55 = F_24 ( V_43 , V_53 , V_54 , 256 ) ;
if ( V_55 < 0 )
return V_55 ;
V_56 = F_24 ( V_43 + 256 , V_53 + 3 , V_54 + 3 , 256 ) ;
if ( V_56 < 0 )
return V_56 ;
return V_55 + V_56 ;
}
static int F_25 ( struct V_57 * V_31 , struct V_5 * V_6 )
{
const struct V_58 * V_59 = F_26 ( V_31 ) ;
int V_60 ;
if ( V_59 -> V_61 ) {
V_60 = V_59 -> V_61 ( V_31 ) ;
if ( V_60 )
return V_60 ;
}
F_3 ( 0x81 , V_6 -> V_62 + V_63 ) ;
F_27 ( V_6 -> V_64 , V_6 -> V_62 + V_65 ) ;
F_27 ( V_6 -> V_64 >> 16 , V_6 -> V_62 + V_65 + 2 ) ;
F_3 ( 0x02 , V_6 -> V_62 + V_66 ) ;
F_3 ( 0x02 , V_6 -> V_62 + V_67 ) ;
F_3 ( 0x02 , V_6 -> V_62 + V_68 ) ;
F_3 ( 0x0f , V_6 -> V_19 + V_34 ) ;
F_3 ( V_69 , V_6 -> V_19 + V_20 ) ;
F_3 ( V_70 , V_6 -> V_19 + V_20 ) ;
F_3 ( V_71 , V_6 -> V_19 + V_42 ) ;
F_3 ( V_18 , V_6 -> V_19 + V_20 ) ;
F_28 ( 5 ) ;
return 0 ;
}
static void F_29 ( struct V_57 * V_31 , struct V_5 * V_6 )
{
const struct V_58 * V_59 = F_26 ( V_31 ) ;
F_3 ( V_72 , V_6 -> V_19 + V_20 ) ;
if ( V_59 -> V_73 )
V_59 -> V_73 ( V_31 ) ;
}
static int F_30 ( struct V_57 * V_31 )
{
struct V_74 * V_40 = V_31 -> V_31 . V_75 ;
struct V_76 * V_19 = F_31 ( V_31 ,
V_77 , 0 ) ;
struct V_76 * V_62 = F_31 ( V_31 ,
V_77 , 1 ) ;
int V_26 = F_32 ( V_31 , 0 ) ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_7 * V_7 ;
int V_78 ;
if ( V_40 == NULL )
F_9 ( & V_31 -> V_31 , L_6 ) ;
V_6 = F_33 ( sizeof *V_6 , V_79 ) ;
if ( ! V_6 ) {
V_78 = - V_80 ;
goto V_81;
}
V_6 -> V_31 = V_31 ;
F_34 ( V_31 , V_6 ) ;
V_2 = & V_6 -> V_2 ;
V_7 = & V_6 -> V_8 ;
V_2 -> V_9 = V_7 ;
V_2 -> V_82 = L_7 ;
V_6 -> V_62 = F_35 ( V_62 -> V_83 , F_36 ( V_62 ) ) ;
if ( ! V_6 -> V_62 ) {
V_78 = - V_84 ;
goto V_85;
}
V_6 -> V_64 = V_19 -> V_83 & 0xfffff ;
V_6 -> V_19 = F_35 ( V_19 -> V_83 , F_36 ( V_19 ) ) ;
if ( ! V_6 -> V_19 ) {
V_78 = - V_84 ;
goto V_86;
}
V_78 = F_25 ( V_31 , V_6 ) ;
if ( V_78 )
goto V_87;
V_7 -> V_88 = V_6 -> V_19 ;
V_7 -> V_23 = V_6 -> V_19 ;
V_7 -> V_89 = F_1 ;
V_7 -> V_90 = F_4 ;
V_7 -> V_39 = F_14 ;
V_7 -> V_91 = F_16 ;
V_7 -> V_92 = F_18 ;
V_7 -> V_93 = F_20 ;
V_7 -> V_51 . V_11 = V_94 ;
V_7 -> V_51 . V_95 = 512 ;
V_7 -> V_51 . V_96 = 6 ;
V_7 -> V_51 . V_97 = 2 ;
V_7 -> V_51 . V_98 = F_21 ;
V_7 -> V_51 . V_99 = F_22 ;
V_7 -> V_51 . V_100 = F_23 ;
if ( V_40 )
V_7 -> V_101 = V_40 -> V_101 ;
V_7 -> V_102 = 15 ;
V_78 = F_37 ( V_26 , & F_6 ,
V_103 , F_38 ( & V_31 -> V_31 ) , V_6 ) ;
if ( V_78 ) {
F_39 ( & V_31 -> V_31 , L_8 , V_78 ) ;
goto V_104;
}
V_6 -> V_26 = V_26 ;
V_7 -> V_105 = F_11 ;
if ( F_40 ( V_2 , 1 ) ) {
V_78 = - V_106 ;
goto V_107;
}
V_78 = F_41 ( V_2 , NULL , NULL ,
V_40 ? V_40 -> V_108 : NULL ,
V_40 ? V_40 -> V_109 : 0 ) ;
if ( ! V_78 )
return V_78 ;
F_42 ( V_2 ) ;
V_107:
if ( V_6 -> V_26 )
F_43 ( V_6 -> V_26 , V_6 ) ;
V_104:
F_29 ( V_31 , V_6 ) ;
V_87:
F_44 ( V_6 -> V_19 ) ;
V_86:
F_44 ( V_6 -> V_62 ) ;
V_85:
F_45 ( V_6 ) ;
V_81:
return V_78 ;
}
static int F_46 ( struct V_57 * V_31 )
{
struct V_5 * V_6 = F_47 ( V_31 ) ;
F_42 ( & V_6 -> V_2 ) ;
if ( V_6 -> V_26 )
F_43 ( V_6 -> V_26 , V_6 ) ;
F_29 ( V_31 , V_6 ) ;
F_44 ( V_6 -> V_19 ) ;
F_44 ( V_6 -> V_62 ) ;
F_45 ( V_6 ) ;
return 0 ;
}
static int F_48 ( struct V_57 * V_31 , T_5 V_35 )
{
const struct V_58 * V_59 = F_26 ( V_31 ) ;
if ( V_59 -> V_110 )
V_59 -> V_110 ( V_31 ) ;
F_29 ( V_31 , F_47 ( V_31 ) ) ;
return 0 ;
}
static int F_49 ( struct V_57 * V_31 )
{
const struct V_58 * V_59 = F_26 ( V_31 ) ;
F_25 ( V_31 , F_47 ( V_31 ) ) ;
if ( V_59 -> V_111 )
V_59 -> V_111 ( V_31 ) ;
return 0 ;
}
