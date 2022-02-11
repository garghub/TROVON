static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 V_12 ;
int V_13 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_14 = V_6 -> type ;
V_12 . V_15 = V_6 -> V_16 ;
V_10 = F_2 ( V_4 , & V_12 , NULL ) ;
if ( V_10 == NULL )
return - V_17 ;
V_8 = ( void * ) V_6 + sizeof( * V_6 ) ;
for ( V_13 = 0 ; V_13 < V_6 -> V_18 ; V_13 ++ ) {
if ( V_8 -> V_19 <= 0 ) {
F_3 ( V_2 -> V_20 , L_1 , V_13 ) ;
return - V_21 ;
}
switch ( V_8 -> type ) {
case V_22 :
V_10 -> V_23 = V_8 -> V_24 +
V_2 -> V_25 . V_26 ;
V_10 -> type = V_27 ;
break;
case V_28 :
V_10 -> V_23 = V_8 -> V_24 +
V_2 -> V_25 . V_29 ;
V_10 -> type = V_30 ;
break;
case V_31 :
V_10 -> V_23 = V_8 -> V_24 +
( V_2 -> V_25 . V_32 - V_2 -> V_25 . V_33 ) ;
V_10 -> type = V_34 ;
break;
default:
F_3 ( V_2 -> V_20 , L_2 ,
V_8 -> type , V_13 ) ;
return - V_21 ;
}
V_10 -> V_19 = V_8 -> V_19 ;
V_10 -> V_35 = ( void * ) V_8 + sizeof( * V_8 ) ;
F_4 ( V_10 ) ;
V_8 = ( void * ) V_8 + sizeof( * V_8 ) + V_8 -> V_19 ;
}
return 0 ;
}
static int F_5 ( struct V_3 * V_3 )
{
struct V_36 * V_37 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = V_3 -> V_2 ;
int V_38 , V_13 ;
V_37 = (struct V_36 * ) V_3 -> V_39 ;
if ( ( strncmp ( V_37 -> V_40 , V_41 , 4 ) != 0 ) ||
( V_3 -> V_19 != V_37 -> V_42 + sizeof( * V_37 ) ) ) {
F_3 ( V_2 -> V_20 , L_3 ) ;
return - V_21 ;
}
F_6 ( V_2 -> V_20 ,
L_4 ,
V_37 -> V_40 , V_37 -> V_42 , V_37 -> V_43 ,
V_37 -> V_44 , sizeof( * V_37 ) ) ;
V_6 = ( void * ) V_3 -> V_39 + sizeof( * V_37 ) ;
for ( V_13 = 0 ; V_13 < V_37 -> V_43 ; V_13 ++ ) {
V_38 = F_1 ( V_2 , V_3 , V_6 ) ;
if ( V_38 < 0 ) {
F_3 ( V_2 -> V_20 , L_5 , V_13 ) ;
return V_38 ;
}
V_6 = ( void * ) V_6 + sizeof( * V_6 ) + V_6 -> V_45 ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_46 )
{
int V_47 ;
T_1 V_48 ;
for ( V_47 = 0 ; V_47 <= 0xF0 ; V_47 += 8 ) {
V_48 = F_8 ( V_46 , V_47 ) ;
if ( V_48 )
F_6 ( V_46 -> V_20 , L_6 ,
V_47 , V_48 ) ;
}
for ( V_47 = 0x00 ; V_47 <= 0xff ; V_47 += 4 ) {
V_48 = F_9 ( V_46 -> V_25 . V_49 + V_47 ) ;
if ( V_48 )
F_6 ( V_46 -> V_20 , L_7 ,
V_47 , ( V_50 ) V_48 ) ;
}
}
static T_2 F_10 ( int V_51 , void * V_52 )
{
struct V_1 * V_46 = (struct V_1 * ) V_52 ;
T_1 V_53 ;
T_2 V_38 = V_54 ;
F_11 ( & V_46 -> V_55 ) ;
V_53 = F_8 ( V_46 , V_56 ) ;
if ( V_53 & V_57 ) {
F_12 ( V_46 , V_58 ,
V_59 , 0 ) ;
V_38 = V_60 ;
}
if ( V_53 & V_61 ) {
F_12 ( V_46 , V_62 ,
V_63 ,
V_63 ) ;
V_38 = V_60 ;
}
F_13 ( & V_46 -> V_55 ) ;
return V_38 ;
}
static void F_14 ( struct V_1 * V_46 )
{
int V_64 = 10 ;
F_15 ( V_46 -> V_25 . V_33 + V_65 ,
& V_46 -> V_66 -> V_67 , sizeof( V_50 ) ) ;
F_16 ( V_46 , V_68 , V_69 , 0x0 ) ;
while ( V_64 -- ) {
if ( ! ( F_17 ( V_46 , V_68 ) &
V_70 ) )
break;
F_18 ( 100 ) ;
}
if ( V_64 < 0 ) {
F_3 ( V_46 -> V_20 , L_8 ) ;
F_7 ( V_46 ) ;
}
}
static void F_19 ( struct V_1 * V_46 )
{
F_16 ( V_46 , V_68 ,
V_71 | V_72 | V_69 ,
V_71 | V_72 | V_69 ) ;
F_20 ( 10 ) ;
F_16 ( V_46 , V_68 , V_71 , 0 ) ;
}
static int F_21 ( struct V_1 * V_46 , struct V_73 * V_66 )
{
V_46 -> V_25 . V_74 = V_66 -> V_74 ;
V_46 -> V_25 . V_33 = F_22 ( V_66 -> V_74 , V_66 -> V_75 ) ;
if ( ! V_46 -> V_25 . V_33 )
return - V_76 ;
V_46 -> V_25 . V_49 = F_22 ( V_66 -> V_77 , V_66 -> V_78 ) ;
if ( ! V_46 -> V_25 . V_49 ) {
F_23 ( V_46 -> V_25 . V_33 ) ;
return - V_76 ;
}
V_46 -> V_25 . V_32 = F_22 ( V_66 -> V_67 , V_66 -> V_79 ) ;
if ( ! V_46 -> V_25 . V_32 ) {
F_23 ( V_46 -> V_25 . V_49 ) ;
F_23 ( V_46 -> V_25 . V_33 ) ;
return - V_76 ;
}
V_46 -> V_25 . V_80 = V_46 -> V_25 . V_33 + V_46 -> V_25 . V_81 ;
F_24 ( V_46 , V_65 + 0x204 ,
V_82 ,
V_65 ,
V_82 ) ;
V_46 -> V_51 = V_66 -> V_51 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_46 , struct V_73 * V_66 )
{
const struct V_83 * V_84 ;
struct V_85 * V_20 ;
int V_38 = - V_76 , V_47 , V_86 , V_87 ;
V_50 V_23 , V_19 ;
V_20 = V_46 -> V_20 ;
switch ( V_46 -> V_14 ) {
case V_88 :
V_84 = V_89 ;
V_87 = F_26 ( V_89 ) ;
V_46 -> V_25 . V_26 = V_90 ;
V_46 -> V_25 . V_29 = V_91 ;
V_46 -> V_25 . V_81 = V_92 ;
break;
default:
F_3 ( V_20 , L_9 ) ;
return V_38 ;
}
V_38 = F_21 ( V_46 , V_66 ) ;
if ( V_38 < 0 ) {
F_3 ( V_20 , L_10 ) ;
return V_38 ;
}
V_38 = F_27 ( V_46 -> V_93 , F_28 ( 32 ) ) ;
if ( V_38 )
return V_38 ;
F_16 ( V_46 , V_62 , 0x3 , 0x0 ) ;
F_16 ( V_46 , V_94 , 0x3 , 0x0 ) ;
for ( V_47 = 0 ; V_47 < V_87 ; V_47 ++ ) {
V_23 = V_84 [ V_47 ] . V_95 ;
V_19 = ( V_84 [ V_47 ] . V_96 - V_84 [ V_47 ] . V_95 ) / V_84 [ V_47 ] . V_18 ;
for ( V_86 = 0 ; V_86 < V_84 [ V_47 ] . V_18 ; V_86 ++ ) {
F_29 ( V_46 , V_23 , V_19 ,
V_84 [ V_47 ] . type , NULL , V_86 , V_46 ) ;
V_23 += V_19 ;
}
}
return 0 ;
}
static void F_30 ( struct V_1 * V_46 )
{
F_31 ( V_46 ) ;
F_23 ( V_46 -> V_25 . V_33 ) ;
F_23 ( V_46 -> V_25 . V_49 ) ;
F_23 ( V_46 -> V_25 . V_32 ) ;
}
