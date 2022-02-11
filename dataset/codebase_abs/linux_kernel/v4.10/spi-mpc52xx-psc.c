static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_8 = ( V_4 && V_4 -> V_8 )
? V_4 -> V_8 : V_2 -> V_9 ;
V_6 -> V_10 = ( V_4 && V_4 -> V_10 )
? V_4 -> V_10 : V_2 -> V_10 ;
V_6 -> V_10 = ( ( V_6 -> V_10 + 7 ) / 8 ) * 8 ;
return 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_11 * V_12 = F_3 ( V_2 -> V_13 ) ;
struct V_14 T_1 * V_15 = V_12 -> V_15 ;
T_2 V_16 ;
T_3 V_17 ;
V_16 = F_4 ( & V_15 -> V_16 ) ;
if ( V_2 -> V_18 & V_19 )
V_16 |= 0x00001000 ;
else
V_16 &= ~ 0x00001000 ;
if ( V_2 -> V_18 & V_20 )
V_16 |= 0x00002000 ;
else
V_16 &= ~ 0x00002000 ;
if ( V_2 -> V_18 & V_21 )
V_16 |= 0x10000000 ;
else
V_16 &= ~ 0x10000000 ;
F_5 ( & V_15 -> V_16 , V_16 ) ;
V_17 = F_6 ( ( T_3 T_1 * ) & V_15 -> V_17 ) ;
V_17 &= 0xFF00 ;
if ( V_6 -> V_8 )
V_17 |= ( V_22 / V_6 -> V_8 - 1 ) & 0xFF ;
else
V_17 |= ( V_22 / 1000000 - 1 ) & 0xFF ;
F_7 ( ( T_3 T_1 * ) & V_15 -> V_17 , V_17 ) ;
V_12 -> V_10 = V_6 -> V_10 ;
if ( V_12 -> V_23 )
V_12 -> V_23 ( V_2 , ( V_2 -> V_18 & V_24 ) ? 1 : 0 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_3 ( V_2 -> V_13 ) ;
if ( V_12 -> V_23 )
V_12 -> V_23 ( V_2 , ( V_2 -> V_18 & V_24 ) ? 0 : 1 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_12 = F_3 ( V_2 -> V_13 ) ;
struct V_14 T_1 * V_15 = V_12 -> V_15 ;
struct V_25 T_1 * V_26 = V_12 -> V_26 ;
unsigned V_27 = 0 ;
unsigned V_28 = 0 ;
unsigned char * V_29 = ( unsigned char * ) V_4 -> V_29 ;
unsigned char * V_30 = ( unsigned char * ) V_4 -> V_30 ;
unsigned V_31 ;
unsigned V_32 = V_33 ;
unsigned V_34 ;
int V_35 = 0 ;
if ( ! V_4 -> V_30 && ! V_4 -> V_29 && V_4 -> V_36 )
return - V_37 ;
F_10 ( & V_15 -> V_38 , V_39 | V_40 ) ;
while ( V_27 < V_4 -> V_36 ) {
if ( V_4 -> V_36 - V_27 > V_33 ) {
V_31 = V_41 ;
V_35 = 0 ;
} else {
V_32 = V_4 -> V_36 - V_28 ;
V_31 = V_33 - ( V_4 -> V_36 - V_27 ) ;
V_35 = 1 ;
}
F_11 ( & V_2 -> V_42 , L_1 , V_32 ) ;
for (; V_32 ; V_28 ++ , V_32 -- ) {
if ( V_32 == 1 && V_35 )
F_10 ( & V_15 -> V_43 , 0x01 ) ;
if ( V_30 )
F_10 ( & V_15 -> V_44 , V_30 [ V_28 ] ) ;
else
F_10 ( & V_15 -> V_44 , 0 ) ;
}
F_10 ( & V_15 -> V_38 , V_45 ) ;
if ( V_4 -> V_36 - V_27 == 1 ) {
F_10 ( & V_15 -> V_18 , 0 ) ;
} else {
F_10 ( & V_15 -> V_18 , V_46 ) ;
F_7 ( & V_26 -> V_31 , V_31 ) ;
}
F_7 ( & V_15 -> V_47 , V_48 ) ;
F_12 ( & V_12 -> V_49 ) ;
V_34 = F_6 ( & V_26 -> V_50 ) ;
F_11 ( & V_2 -> V_42 , L_2 , V_34 ) ;
V_32 = V_34 ;
if ( V_29 ) {
for (; V_34 ; V_27 ++ , V_34 -- )
V_29 [ V_27 ] = F_13 ( & V_15 -> V_44 ) ;
} else {
for (; V_34 ; V_27 ++ , V_34 -- )
F_13 ( & V_15 -> V_44 ) ;
}
}
F_10 ( & V_15 -> V_38 , V_51 | V_52 ) ;
return 0 ;
}
static void F_14 ( struct V_53 * V_54 )
{
struct V_11 * V_12 =
F_15 ( V_54 , struct V_11 , V_54 ) ;
F_16 ( & V_12 -> V_55 ) ;
V_12 -> V_56 = 1 ;
while ( ! F_17 ( & V_12 -> V_57 ) ) {
struct V_58 * V_59 ;
struct V_1 * V_2 ;
struct V_3 * V_4 = NULL ;
unsigned V_60 ;
int V_61 ;
V_59 = F_15 ( V_12 -> V_57 . V_62 , struct V_58 , V_57 ) ;
F_18 ( & V_59 -> V_57 ) ;
F_19 ( & V_12 -> V_55 ) ;
V_2 = V_59 -> V_2 ;
V_60 = 1 ;
V_61 = 0 ;
F_20 (t, &m->transfers, transfer_list) {
if ( V_4 -> V_10 || V_4 -> V_8 ) {
V_61 = F_1 ( V_2 , V_4 ) ;
if ( V_61 < 0 )
break;
}
if ( V_60 )
F_2 ( V_2 ) ;
V_60 = V_4 -> V_60 ;
V_61 = F_9 ( V_2 , V_4 ) ;
if ( V_61 )
break;
V_59 -> V_63 += V_4 -> V_36 ;
if ( V_4 -> V_64 )
F_21 ( V_4 -> V_64 ) ;
if ( V_60 )
F_8 ( V_2 ) ;
}
V_59 -> V_61 = V_61 ;
if ( V_59 -> V_65 )
V_59 -> V_65 ( V_59 -> V_66 ) ;
if ( V_61 || ! V_60 )
F_8 ( V_2 ) ;
F_1 ( V_2 , NULL ) ;
F_16 ( & V_12 -> V_55 ) ;
}
V_12 -> V_56 = 0 ;
F_19 ( & V_12 -> V_55 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_3 ( V_2 -> V_13 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_67 ;
if ( V_2 -> V_10 % 8 )
return - V_37 ;
if ( ! V_6 ) {
V_6 = F_23 ( sizeof *V_6 , V_68 ) ;
if ( ! V_6 )
return - V_69 ;
V_2 -> V_7 = V_6 ;
}
V_6 -> V_10 = V_2 -> V_10 ;
V_6 -> V_8 = V_2 -> V_9 ;
F_24 ( & V_12 -> V_55 , V_67 ) ;
if ( ! V_12 -> V_56 )
F_8 ( V_2 ) ;
F_25 ( & V_12 -> V_55 , V_67 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_11 * V_12 = F_3 ( V_2 -> V_13 ) ;
unsigned long V_67 ;
V_59 -> V_63 = 0 ;
V_59 -> V_61 = - V_70 ;
F_24 ( & V_12 -> V_55 , V_67 ) ;
F_27 ( & V_59 -> V_57 , & V_12 -> V_57 ) ;
F_28 ( & V_12 -> V_54 ) ;
F_25 ( & V_12 -> V_55 , V_67 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 -> V_7 ) ;
}
static int F_31 ( int V_71 , struct V_11 * V_12 )
{
struct V_14 T_1 * V_15 = V_12 -> V_15 ;
struct V_25 T_1 * V_26 = V_12 -> V_26 ;
T_2 V_72 ;
int V_73 ;
V_72 = ( V_12 -> V_74 ? V_12 -> V_74 : 512000000 ) / V_22 ;
V_73 = F_32 ( V_71 , V_72 ) ;
if ( V_73 )
return V_73 ;
F_10 ( & V_15 -> V_38 , V_75 ) ;
F_10 ( & V_15 -> V_38 , V_76 ) ;
F_10 ( & V_15 -> V_38 , V_51 | V_52 ) ;
F_7 ( & V_15 -> V_47 , 0 ) ;
F_10 ( & V_15 -> V_38 , V_45 ) ;
F_10 ( & V_26 -> V_77 , 0 ) ;
F_10 ( & V_15 -> V_18 , V_46 ) ;
F_5 ( & V_15 -> V_16 , 0x0180C800 ) ;
F_7 ( ( T_3 T_1 * ) & V_15 -> V_17 , 0x070F ) ;
F_10 ( & V_15 -> V_78 , 0x00 ) ;
F_10 ( & V_15 -> V_79 , 0x84 ) ;
V_12 -> V_10 = 8 ;
return 0 ;
}
static T_4 F_33 ( int V_80 , void * V_81 )
{
struct V_11 * V_12 = (struct V_11 * ) V_81 ;
struct V_14 T_1 * V_15 = V_12 -> V_15 ;
if ( F_6 ( & V_15 -> V_82 ) & V_48 ) {
F_7 ( & V_15 -> V_47 , 0 ) ;
V_65 ( & V_12 -> V_49 ) ;
return V_83 ;
}
return V_84 ;
}
static int F_34 ( struct V_85 * V_42 , T_2 V_86 ,
T_2 V_87 , unsigned int V_80 , T_5 V_88 )
{
struct V_89 * V_90 = F_35 ( V_42 ) ;
struct V_11 * V_12 ;
struct V_91 * V_13 ;
int V_73 ;
V_13 = F_36 ( V_42 , sizeof *V_12 ) ;
if ( V_13 == NULL )
return - V_69 ;
F_37 ( V_42 , V_13 ) ;
V_12 = F_3 ( V_13 ) ;
V_13 -> V_92 = V_20 | V_19 | V_24 | V_21 ;
V_12 -> V_80 = V_80 ;
if ( V_90 == NULL ) {
F_38 ( V_42 ,
L_3 ) ;
V_12 -> V_23 = NULL ;
V_12 -> V_74 = 0 ;
V_13 -> V_88 = V_88 ;
V_13 -> V_93 = 255 ;
} else {
V_12 -> V_23 = V_90 -> V_23 ;
V_12 -> V_74 = V_90 -> V_74 ;
V_13 -> V_88 = V_90 -> V_88 ;
V_13 -> V_93 = V_90 -> V_94 ;
}
V_13 -> V_95 = F_22 ;
V_13 -> V_96 = F_26 ;
V_13 -> V_97 = F_29 ;
V_13 -> V_42 . V_98 = V_42 -> V_98 ;
V_12 -> V_15 = F_39 ( V_86 , V_87 ) ;
if ( ! V_12 -> V_15 ) {
F_40 ( V_42 , L_4 ) ;
V_73 = - V_99 ;
goto V_100;
}
V_12 -> V_26 = ( ( void T_1 * ) V_12 -> V_15 ) + sizeof( struct V_14 ) ;
V_73 = F_41 ( V_12 -> V_80 , F_33 , 0 , L_5 ,
V_12 ) ;
if ( V_73 )
goto V_100;
V_73 = F_31 ( V_13 -> V_88 , V_12 ) ;
if ( V_73 < 0 ) {
F_40 ( V_42 , L_6 ) ;
goto V_101;
}
F_42 ( & V_12 -> V_55 ) ;
F_43 ( & V_12 -> V_49 ) ;
F_44 ( & V_12 -> V_54 , F_14 ) ;
F_45 ( & V_12 -> V_57 ) ;
V_73 = F_46 ( V_13 ) ;
if ( V_73 < 0 )
goto V_101;
return V_73 ;
V_101:
V_101 ( V_12 -> V_80 , V_12 ) ;
V_100:
if ( V_12 -> V_15 )
F_47 ( V_12 -> V_15 ) ;
F_48 ( V_13 ) ;
return V_73 ;
}
static int F_49 ( struct V_102 * V_103 )
{
const T_2 * V_104 ;
T_6 V_105 , V_106 ;
T_5 V_107 = - 1 ;
V_104 = F_50 ( V_103 -> V_42 . V_98 , 0 , & V_106 , NULL ) ;
if ( ! V_104 ) {
F_40 ( & V_103 -> V_42 , L_7 ) ;
return - V_37 ;
}
V_105 = F_51 ( V_103 -> V_42 . V_98 , V_104 ) ;
if ( V_103 -> V_42 . V_108 == NULL ) {
const T_2 * V_109 ;
V_109 = F_52 ( V_103 -> V_42 . V_98 , L_8 , NULL ) ;
if ( ! V_109 || * V_109 > 5 ) {
F_40 ( & V_103 -> V_42 , L_9 ) ;
return - V_37 ;
}
V_107 = * V_109 + 1 ;
}
return F_34 ( & V_103 -> V_42 , ( T_2 ) V_105 , ( T_2 ) V_106 ,
F_53 ( V_103 -> V_42 . V_98 , 0 ) , V_107 ) ;
}
static int F_54 ( struct V_102 * V_103 )
{
struct V_91 * V_13 = F_55 ( F_56 ( V_103 ) ) ;
struct V_11 * V_12 = F_3 ( V_13 ) ;
F_57 ( & V_12 -> V_54 ) ;
F_58 ( V_13 ) ;
V_101 ( V_12 -> V_80 , V_12 ) ;
if ( V_12 -> V_15 )
F_47 ( V_12 -> V_15 ) ;
F_48 ( V_13 ) ;
return 0 ;
}
