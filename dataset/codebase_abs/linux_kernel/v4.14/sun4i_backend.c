static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_1 ) ;
F_3 ( V_2 -> V_4 , V_5 ,
V_6 ) ;
for ( V_3 = 0 ; V_3 < 12 ; V_3 ++ )
F_3 ( V_2 -> V_4 , F_4 ( V_3 ) ,
V_7 [ V_3 ] ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( L_2 ) ;
F_6 ( V_2 -> V_4 , V_5 ,
V_6 , 0 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_2 ( L_3 ) ;
F_3 ( V_2 -> V_4 , V_8 ,
V_9 |
V_10 ) ;
}
void F_8 ( struct V_11 * V_12 ,
int V_13 , bool V_14 )
{
T_1 V_15 ;
F_2 ( L_4 , V_14 ? L_5 : L_6 ,
V_13 ) ;
if ( V_14 )
V_15 = F_9 ( V_13 ) ;
else
V_15 = 0 ;
F_6 ( V_12 -> V_2 . V_4 , V_16 ,
F_9 ( V_13 ) , V_15 ) ;
}
static int F_10 ( struct V_17 * V_18 ,
T_1 V_19 , T_1 * V_20 )
{
if ( ( V_18 -> type == V_21 ) &&
( V_19 == V_22 ) )
V_19 = V_23 ;
switch ( V_19 ) {
case V_22 :
* V_20 = V_24 ;
break;
case V_25 :
* V_20 = V_26 ;
break;
case V_27 :
* V_20 = V_28 ;
break;
case V_29 :
* V_20 = V_30 ;
break;
case V_31 :
* V_20 = V_32 ;
break;
case V_23 :
* V_20 = V_33 ;
break;
case V_34 :
* V_20 = V_35 ;
break;
case V_36 :
* V_20 = V_37 ;
break;
default:
return - V_38 ;
}
return 0 ;
}
int F_11 ( struct V_11 * V_12 ,
int V_13 , struct V_17 * V_18 )
{
struct V_39 * V_40 = V_18 -> V_40 ;
struct V_41 * V_42 = V_40 -> V_42 ;
F_2 ( L_7 , V_13 ) ;
if ( V_18 -> type == V_21 ) {
F_2 ( L_8 ,
V_40 -> V_43 , V_40 -> V_44 ) ;
F_3 ( V_12 -> V_2 . V_4 , V_45 ,
F_12 ( V_40 -> V_43 ,
V_40 -> V_44 ) ) ;
}
F_2 ( L_9 , V_42 -> V_46 [ 0 ] * 8 ) ;
F_3 ( V_12 -> V_2 . V_4 ,
F_13 ( V_13 ) ,
V_42 -> V_46 [ 0 ] * 8 ) ;
F_2 ( L_10 ,
V_40 -> V_43 , V_40 -> V_44 ) ;
F_3 ( V_12 -> V_2 . V_4 , F_14 ( V_13 ) ,
F_15 ( V_40 -> V_43 ,
V_40 -> V_44 ) ) ;
F_2 ( L_11 ,
V_40 -> V_47 , V_40 -> V_48 ) ;
F_3 ( V_12 -> V_2 . V_4 , F_16 ( V_13 ) ,
F_17 ( V_40 -> V_47 ,
V_40 -> V_48 ) ) ;
return 0 ;
}
int F_18 ( struct V_11 * V_12 ,
int V_13 , struct V_17 * V_18 )
{
struct V_39 * V_40 = V_18 -> V_40 ;
struct V_41 * V_42 = V_40 -> V_42 ;
bool V_49 = false ;
T_1 V_15 ;
int V_50 ;
if ( V_18 -> V_40 -> V_51 )
V_49 = V_18 -> V_40 -> V_51 -> V_40 -> V_52 . V_53
& V_54 ;
F_6 ( V_12 -> V_2 . V_4 , V_16 ,
V_55 ,
V_49 ? V_55 : 0 ) ;
F_2 ( L_12 ,
V_49 ? L_13 : L_14 ) ;
V_50 = F_10 ( V_18 , V_42 -> V_19 -> V_19 ,
& V_15 ) ;
if ( V_50 ) {
F_2 ( L_15 ) ;
return V_50 ;
}
F_6 ( V_12 -> V_2 . V_4 ,
F_19 ( V_13 ) ,
V_56 , V_15 ) ;
return 0 ;
}
int F_20 ( struct V_11 * V_12 ,
int V_13 , struct V_17 * V_18 )
{
struct V_39 * V_40 = V_18 -> V_40 ;
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_57 * V_58 ;
T_1 V_59 , V_60 ;
T_2 V_61 ;
int V_62 ;
V_58 = F_21 ( V_42 , 0 ) ;
F_2 ( L_16 , & V_58 -> V_61 ) ;
V_62 = V_42 -> V_19 -> V_63 [ 0 ] ;
V_61 = V_58 -> V_61 + V_42 -> V_64 [ 0 ] ;
V_61 += ( V_40 -> V_65 >> 16 ) * V_62 ;
V_61 += ( V_40 -> V_66 >> 16 ) * V_42 -> V_46 [ 0 ] ;
F_2 ( L_17 , & V_61 ) ;
V_59 = V_61 << 3 ;
F_2 ( L_18 , V_59 ) ;
F_3 ( V_12 -> V_2 . V_4 ,
F_22 ( V_13 ) ,
V_59 ) ;
V_60 = V_61 >> 29 ;
F_2 ( L_19 , V_60 ) ;
F_6 ( V_12 -> V_2 . V_4 , V_67 ,
F_23 ( V_13 ) ,
F_24 ( V_13 , V_60 ) ) ;
return 0 ;
}
static int F_25 ( struct V_68 * V_69 ) {
struct V_11 * V_12 = F_26 ( V_69 ) ;
int V_50 ;
V_12 -> V_70 = F_27 ( V_69 , L_20 ) ;
if ( F_28 ( V_12 -> V_70 ) ) {
F_29 ( V_69 , L_21 ) ;
return F_30 ( V_12 -> V_70 ) ;
}
V_50 = F_31 ( V_12 -> V_70 ) ;
if ( V_50 ) {
F_29 ( V_69 , L_22 ) ;
return V_50 ;
}
V_12 -> V_71 = F_32 ( V_69 , L_20 ) ;
if ( F_28 ( V_12 -> V_71 ) ) {
F_29 ( V_69 , L_23 ) ;
V_50 = F_30 ( V_12 -> V_71 ) ;
goto V_72;
}
V_50 = F_33 ( V_12 -> V_71 ) ;
if ( V_50 ) {
F_29 ( V_69 , L_24 ) ;
return V_50 ;
}
return 0 ;
V_72:
F_34 ( V_12 -> V_70 ) ;
return V_50 ;
}
static int F_35 ( struct V_68 * V_69 ) {
struct V_11 * V_12 = F_26 ( V_69 ) ;
F_36 ( V_12 -> V_71 ) ;
F_34 ( V_12 -> V_70 ) ;
return 0 ;
}
static int F_37 ( struct V_73 * V_74 )
{
struct V_73 * V_75 , * V_76 ;
int V_50 = - V_38 ;
V_75 = F_38 ( V_74 , 0 ) ;
if ( ! V_75 )
return - V_38 ;
F_39 (port, ep) {
struct V_73 * V_77 ;
T_1 V_78 ;
V_77 = F_40 ( V_76 ) ;
if ( ! V_77 )
continue;
V_50 = F_41 ( V_77 , L_25 , & V_78 ) ;
if ( V_50 )
continue;
V_50 = V_78 ;
}
F_42 ( V_75 ) ;
return V_50 ;
}
static int F_43 ( struct V_68 * V_69 , struct V_68 * V_79 ,
void * V_80 )
{
struct V_81 * V_82 = F_44 ( V_69 ) ;
struct V_83 * V_84 = V_80 ;
struct V_85 * V_86 = V_84 -> V_87 ;
struct V_11 * V_12 ;
struct V_88 * V_89 ;
void T_3 * V_4 ;
int V_3 , V_50 ;
V_12 = F_45 ( V_69 , sizeof( * V_12 ) , V_90 ) ;
if ( ! V_12 )
return - V_91 ;
F_46 ( V_69 , V_12 ) ;
V_12 -> V_2 . V_74 = V_69 -> V_92 ;
V_12 -> V_2 . V_93 = & V_94 ;
V_12 -> V_2 . V_95 = F_37 ( V_69 -> V_92 ) ;
if ( V_12 -> V_2 . V_95 < 0 )
return V_12 -> V_2 . V_95 ;
V_89 = F_47 ( V_82 , V_96 , 0 ) ;
V_4 = F_48 ( V_69 , V_89 ) ;
if ( F_28 ( V_4 ) )
return F_30 ( V_4 ) ;
V_12 -> V_2 . V_4 = F_49 ( V_69 , V_4 ,
& V_97 ) ;
if ( F_28 ( V_12 -> V_2 . V_4 ) ) {
F_29 ( V_69 , L_26 ) ;
return F_30 ( V_12 -> V_2 . V_4 ) ;
}
V_12 -> V_98 = F_27 ( V_69 , NULL ) ;
if ( F_28 ( V_12 -> V_98 ) ) {
F_29 ( V_69 , L_27 ) ;
return F_30 ( V_12 -> V_98 ) ;
}
V_50 = F_31 ( V_12 -> V_98 ) ;
if ( V_50 ) {
F_29 ( V_69 , L_28 ) ;
return V_50 ;
}
V_12 -> V_99 = F_32 ( V_69 , L_29 ) ;
if ( F_28 ( V_12 -> V_99 ) ) {
F_29 ( V_69 , L_30 ) ;
V_50 = F_30 ( V_12 -> V_99 ) ;
goto V_72;
}
F_33 ( V_12 -> V_99 ) ;
V_12 -> V_100 = F_32 ( V_69 , L_31 ) ;
if ( F_28 ( V_12 -> V_100 ) ) {
F_29 ( V_69 , L_32 ) ;
V_50 = F_30 ( V_12 -> V_100 ) ;
goto V_101;
}
F_33 ( V_12 -> V_100 ) ;
V_12 -> V_102 = F_32 ( V_69 , L_33 ) ;
if ( F_28 ( V_12 -> V_102 ) ) {
F_29 ( V_69 , L_34 ) ;
V_50 = F_30 ( V_12 -> V_102 ) ;
goto V_103;
}
F_33 ( V_12 -> V_102 ) ;
if ( F_50 ( V_69 -> V_92 ,
L_35 ) ) {
V_50 = F_25 ( V_69 ) ;
if ( V_50 ) {
F_29 ( V_69 , L_36 ) ;
goto V_104;
}
}
F_51 ( & V_12 -> V_2 . V_105 , & V_86 -> V_106 ) ;
for ( V_3 = 0x800 ; V_3 < 0x1000 ; V_3 += 4 )
F_3 ( V_12 -> V_2 . V_4 , V_3 , 0 ) ;
F_3 ( V_12 -> V_2 . V_4 , V_8 ,
V_9 ) ;
F_3 ( V_12 -> V_2 . V_4 , V_16 ,
V_107 |
V_108 ) ;
return 0 ;
V_104:
F_36 ( V_12 -> V_102 ) ;
V_103:
F_36 ( V_12 -> V_100 ) ;
V_101:
F_36 ( V_12 -> V_99 ) ;
V_72:
F_34 ( V_12 -> V_98 ) ;
return V_50 ;
}
static void F_52 ( struct V_68 * V_69 , struct V_68 * V_79 ,
void * V_80 )
{
struct V_11 * V_12 = F_26 ( V_69 ) ;
F_53 ( & V_12 -> V_2 . V_105 ) ;
if ( F_50 ( V_69 -> V_92 ,
L_35 ) )
F_35 ( V_69 ) ;
F_36 ( V_12 -> V_102 ) ;
F_36 ( V_12 -> V_100 ) ;
F_36 ( V_12 -> V_99 ) ;
F_34 ( V_12 -> V_98 ) ;
}
static int F_54 ( struct V_81 * V_82 )
{
return F_55 ( & V_82 -> V_69 , & V_109 ) ;
}
static int F_56 ( struct V_81 * V_82 )
{
F_57 ( & V_82 -> V_69 , & V_109 ) ;
return 0 ;
}
