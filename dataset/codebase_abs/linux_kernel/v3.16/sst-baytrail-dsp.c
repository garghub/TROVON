static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 V_12 ;
struct V_13 V_14 ;
int V_15 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_16 = V_6 -> type ;
V_14 . V_17 = V_6 -> V_18 ;
V_14 . V_19 . type = V_20 ;
V_14 . V_19 . V_21 = V_22 ;
V_14 . V_23 . type = V_20 ;
V_14 . V_23 . V_21 = V_24 ;
V_10 = F_2 ( V_4 , & V_14 , NULL ) ;
if ( V_10 == NULL )
return - V_25 ;
V_8 = ( void * ) V_6 + sizeof( * V_6 ) ;
for ( V_15 = 0 ; V_15 < V_6 -> V_26 ; V_15 ++ ) {
if ( V_8 -> V_27 <= 0 ) {
F_3 ( V_2 -> V_28 , L_1 , V_15 ) ;
return - V_29 ;
}
switch ( V_8 -> type ) {
case V_30 :
V_12 . V_31 = V_8 -> V_32 +
V_2 -> V_33 . V_34 ;
V_12 . type = V_35 ;
break;
case V_36 :
V_12 . V_31 = V_8 -> V_32 +
V_2 -> V_33 . V_37 ;
V_12 . type = V_20 ;
break;
case V_38 :
V_12 . V_31 = V_8 -> V_32 +
( V_2 -> V_33 . V_39 - V_2 -> V_33 . V_40 ) ;
V_12 . type = V_41 ;
break;
default:
F_3 ( V_2 -> V_28 , L_2 ,
V_8 -> type , V_15 ) ;
return - V_29 ;
}
V_12 . V_27 = V_8 -> V_27 ;
V_12 . V_21 = V_42 ;
V_12 . V_43 = ( void * ) V_8 + sizeof( * V_8 ) ;
F_4 ( V_10 , & V_12 ) ;
V_8 = ( void * ) V_8 + sizeof( * V_8 ) + V_8 -> V_27 ;
}
return 0 ;
}
static int F_5 ( struct V_3 * V_3 )
{
struct V_44 * V_45 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = V_3 -> V_2 ;
int V_46 , V_15 ;
V_45 = (struct V_44 * ) V_3 -> V_47 ;
if ( ( strncmp ( V_45 -> V_48 , V_49 , 4 ) != 0 ) ||
( V_3 -> V_27 != V_45 -> V_50 + sizeof( * V_45 ) ) ) {
F_3 ( V_2 -> V_28 , L_3 ) ;
return - V_29 ;
}
F_6 ( V_2 -> V_28 ,
L_4 ,
V_45 -> V_48 , V_45 -> V_50 , V_45 -> V_51 ,
V_45 -> V_52 , sizeof( * V_45 ) ) ;
V_6 = ( void * ) V_3 -> V_47 + sizeof( * V_45 ) ;
for ( V_15 = 0 ; V_15 < V_45 -> V_51 ; V_15 ++ ) {
V_46 = F_1 ( V_2 , V_3 , V_6 ) ;
if ( V_46 < 0 ) {
F_3 ( V_2 -> V_28 , L_5 , V_15 ) ;
return V_46 ;
}
V_6 = ( void * ) V_6 + sizeof( * V_6 ) + V_6 -> V_53 ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_54 )
{
int V_55 ;
T_1 V_56 ;
for ( V_55 = 0 ; V_55 <= 0xF0 ; V_55 += 8 ) {
V_56 = F_8 ( V_54 , V_55 ) ;
if ( V_56 )
F_6 ( V_54 -> V_28 , L_6 ,
V_55 , V_56 ) ;
}
for ( V_55 = 0x00 ; V_55 <= 0xff ; V_55 += 4 ) {
V_56 = F_9 ( V_54 -> V_33 . V_57 + V_55 ) ;
if ( V_56 )
F_6 ( V_54 -> V_28 , L_7 ,
V_55 , ( V_58 ) V_56 ) ;
}
}
static T_2 F_10 ( int V_59 , void * V_60 )
{
struct V_1 * V_54 = (struct V_1 * ) V_60 ;
T_1 V_61 ;
T_2 V_46 = V_62 ;
F_11 ( & V_54 -> V_63 ) ;
V_61 = F_8 ( V_54 , V_64 ) ;
if ( V_61 & V_65 ) {
F_12 ( V_54 , V_66 ,
V_67 , 0 ) ;
V_46 = V_68 ;
}
if ( V_61 & V_69 ) {
F_12 ( V_54 , V_70 ,
V_71 ,
V_71 ) ;
V_46 = V_68 ;
}
F_13 ( & V_54 -> V_63 ) ;
return V_46 ;
}
static void F_14 ( struct V_1 * V_54 )
{
int V_72 = 10 ;
F_15 ( V_54 -> V_33 . V_40 + V_73 ,
& V_54 -> V_74 -> V_75 , sizeof( V_58 ) ) ;
F_16 ( V_54 , V_76 , V_77 , 0x0 ) ;
while ( V_72 -- ) {
if ( ! ( F_17 ( V_54 , V_76 ) &
V_78 ) )
break;
F_18 ( 100 ) ;
}
if ( V_72 < 0 ) {
F_3 ( V_54 -> V_28 , L_8 ) ;
F_7 ( V_54 ) ;
}
}
static void F_19 ( struct V_1 * V_54 )
{
F_16 ( V_54 , V_76 ,
V_79 | V_80 | V_77 ,
V_79 | V_80 | V_77 ) ;
F_20 ( 10 ) ;
F_16 ( V_54 , V_76 , V_79 , 0 ) ;
}
static int F_21 ( struct V_1 * V_54 , struct V_81 * V_74 )
{
V_54 -> V_33 . V_82 = V_74 -> V_82 ;
V_54 -> V_33 . V_40 = F_22 ( V_74 -> V_82 , V_74 -> V_83 ) ;
if ( ! V_54 -> V_33 . V_40 )
return - V_84 ;
V_54 -> V_33 . V_57 = F_22 ( V_74 -> V_85 , V_74 -> V_86 ) ;
if ( ! V_54 -> V_33 . V_57 ) {
F_23 ( V_54 -> V_33 . V_40 ) ;
return - V_84 ;
}
V_54 -> V_33 . V_39 = F_22 ( V_74 -> V_75 , V_74 -> V_87 ) ;
if ( ! V_54 -> V_33 . V_39 ) {
F_23 ( V_54 -> V_33 . V_57 ) ;
F_23 ( V_54 -> V_33 . V_40 ) ;
return - V_84 ;
}
V_54 -> V_33 . V_88 = V_54 -> V_33 . V_40 + V_54 -> V_33 . V_89 ;
F_24 ( V_54 , V_73 + 0x204 ,
V_90 ,
V_73 ,
V_90 ) ;
V_54 -> V_59 = V_74 -> V_59 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_54 , struct V_81 * V_74 )
{
const struct V_91 * V_92 ;
struct V_93 * V_28 ;
int V_46 = - V_84 , V_55 , V_94 , V_95 ;
V_58 V_31 , V_27 ;
V_28 = V_54 -> V_28 ;
switch ( V_54 -> V_16 ) {
case V_96 :
V_92 = V_97 ;
V_95 = F_26 ( V_97 ) ;
V_54 -> V_33 . V_34 = V_98 ;
V_54 -> V_33 . V_37 = V_99 ;
V_54 -> V_33 . V_89 = V_100 ;
break;
default:
F_3 ( V_28 , L_9 ) ;
return V_46 ;
}
V_46 = F_21 ( V_54 , V_74 ) ;
if ( V_46 < 0 ) {
F_3 ( V_28 , L_10 ) ;
return V_46 ;
}
V_46 = F_27 ( V_54 -> V_101 , F_28 ( 32 ) ) ;
if ( V_46 )
return V_46 ;
F_16 ( V_54 , V_70 , 0x3 , 0x0 ) ;
F_16 ( V_54 , V_102 , 0x3 , 0x0 ) ;
for ( V_55 = 0 ; V_55 < V_95 ; V_55 ++ ) {
V_31 = V_92 [ V_55 ] . V_103 ;
V_27 = ( V_92 [ V_55 ] . V_104 - V_92 [ V_55 ] . V_103 ) / V_92 [ V_55 ] . V_26 ;
for ( V_94 = 0 ; V_94 < V_92 [ V_55 ] . V_26 ; V_94 ++ ) {
F_29 ( V_54 , V_31 , V_27 ,
V_92 [ V_55 ] . type , NULL , V_94 , V_54 ) ;
V_31 += V_27 ;
}
}
return 0 ;
}
static void F_30 ( struct V_1 * V_54 )
{
F_31 ( V_54 ) ;
F_23 ( V_54 -> V_33 . V_40 ) ;
F_23 ( V_54 -> V_33 . V_57 ) ;
F_23 ( V_54 -> V_33 . V_39 ) ;
}
