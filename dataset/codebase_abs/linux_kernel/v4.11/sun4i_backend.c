void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_1 ) ;
F_3 ( V_2 -> V_4 , V_5 ,
V_6 ) ;
for ( V_3 = 0 ; V_3 < 12 ; V_3 ++ )
F_3 ( V_2 -> V_4 , F_4 ( V_3 ) ,
V_7 [ V_3 ] ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_2 ( L_2 ) ;
F_6 ( V_2 -> V_4 , V_5 ,
V_6 , 0 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_2 ( L_3 ) ;
F_3 ( V_2 -> V_4 , V_8 ,
V_9 |
V_10 ) ;
}
void F_8 ( struct V_1 * V_2 ,
int V_11 , bool V_12 )
{
T_1 V_13 ;
F_2 ( L_4 , V_11 ) ;
if ( V_12 )
V_13 = F_9 ( V_11 ) ;
else
V_13 = 0 ;
F_6 ( V_2 -> V_4 , V_14 ,
F_9 ( V_11 ) , V_13 ) ;
}
static int F_10 ( struct V_15 * V_16 ,
T_1 V_17 , T_1 * V_18 )
{
if ( ( V_16 -> type == V_19 ) &&
( V_17 == V_20 ) )
V_17 = V_21 ;
switch ( V_17 ) {
case V_20 :
* V_18 = V_22 ;
break;
case V_23 :
* V_18 = V_24 ;
break;
case V_25 :
* V_18 = V_26 ;
break;
case V_27 :
* V_18 = V_28 ;
break;
case V_29 :
* V_18 = V_30 ;
break;
case V_21 :
* V_18 = V_31 ;
break;
case V_32 :
* V_18 = V_33 ;
break;
case V_34 :
* V_18 = V_35 ;
break;
default:
return - V_36 ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 ,
int V_11 , struct V_15 * V_16 )
{
struct V_37 * V_38 = V_16 -> V_38 ;
struct V_39 * V_40 = V_38 -> V_40 ;
F_2 ( L_5 , V_11 ) ;
if ( V_16 -> type == V_19 ) {
F_2 ( L_6 ,
V_38 -> V_41 , V_38 -> V_42 ) ;
F_3 ( V_2 -> V_4 , V_43 ,
F_12 ( V_38 -> V_41 ,
V_38 -> V_42 ) ) ;
}
F_2 ( L_7 , V_40 -> V_44 [ 0 ] * 8 ) ;
F_3 ( V_2 -> V_4 , F_13 ( V_11 ) ,
V_40 -> V_44 [ 0 ] * 8 ) ;
F_2 ( L_8 ,
V_38 -> V_41 , V_38 -> V_42 ) ;
F_3 ( V_2 -> V_4 , F_14 ( V_11 ) ,
F_15 ( V_38 -> V_41 ,
V_38 -> V_42 ) ) ;
F_2 ( L_9 ,
V_38 -> V_45 , V_38 -> V_46 ) ;
F_3 ( V_2 -> V_4 , F_16 ( V_11 ) ,
F_17 ( V_38 -> V_45 ,
V_38 -> V_46 ) ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 ,
int V_11 , struct V_15 * V_16 )
{
struct V_37 * V_38 = V_16 -> V_38 ;
struct V_39 * V_40 = V_38 -> V_40 ;
bool V_47 = false ;
T_1 V_13 ;
int V_48 ;
if ( V_16 -> V_38 -> V_49 )
V_47 = V_16 -> V_38 -> V_49 -> V_38 -> V_50 . V_51
& V_52 ;
F_6 ( V_2 -> V_4 , V_14 ,
V_53 ,
V_47 ? V_53 : 0 ) ;
F_2 ( L_10 ,
V_47 ? L_11 : L_12 ) ;
V_48 = F_10 ( V_16 , V_40 -> V_17 -> V_17 ,
& V_13 ) ;
if ( V_48 ) {
F_2 ( L_13 ) ;
return V_48 ;
}
F_6 ( V_2 -> V_4 , F_19 ( V_11 ) ,
V_54 , V_13 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
int V_11 , struct V_15 * V_16 )
{
struct V_37 * V_38 = V_16 -> V_38 ;
struct V_39 * V_40 = V_38 -> V_40 ;
struct V_55 * V_56 ;
T_1 V_57 , V_58 ;
T_2 V_59 ;
int V_60 ;
V_56 = F_21 ( V_40 , 0 ) ;
F_2 ( L_14 , & V_56 -> V_59 ) ;
V_60 = V_40 -> V_17 -> V_61 [ 0 ] ;
V_59 = V_56 -> V_59 + V_40 -> V_62 [ 0 ] ;
V_59 += ( V_38 -> V_63 >> 16 ) * V_60 ;
V_59 += ( V_38 -> V_64 >> 16 ) * V_40 -> V_44 [ 0 ] ;
F_2 ( L_15 , & V_59 ) ;
V_57 = V_59 << 3 ;
F_2 ( L_16 , V_57 ) ;
F_3 ( V_2 -> V_4 , F_22 ( V_11 ) ,
V_57 ) ;
V_58 = V_59 >> 29 ;
F_2 ( L_17 , V_58 ) ;
F_6 ( V_2 -> V_4 , V_65 ,
F_23 ( V_11 ) ,
F_24 ( V_11 , V_58 ) ) ;
return 0 ;
}
static int F_25 ( struct V_66 * V_67 ) {
struct V_1 * V_2 = F_26 ( V_67 ) ;
int V_48 ;
V_2 -> V_68 = F_27 ( V_67 , L_18 ) ;
if ( F_28 ( V_2 -> V_68 ) ) {
F_29 ( V_67 , L_19 ) ;
return F_30 ( V_2 -> V_68 ) ;
}
V_48 = F_31 ( V_2 -> V_68 ) ;
if ( V_48 ) {
F_29 ( V_67 , L_20 ) ;
return V_48 ;
}
V_2 -> V_69 = F_32 ( V_67 , L_18 ) ;
if ( F_28 ( V_2 -> V_69 ) ) {
F_29 ( V_67 , L_21 ) ;
V_48 = F_30 ( V_2 -> V_69 ) ;
goto V_70;
}
V_48 = F_33 ( V_2 -> V_69 ) ;
if ( V_48 ) {
F_29 ( V_67 , L_22 ) ;
return V_48 ;
}
return 0 ;
V_70:
F_34 ( V_2 -> V_68 ) ;
return V_48 ;
}
static int F_35 ( struct V_66 * V_67 ) {
struct V_1 * V_2 = F_26 ( V_67 ) ;
F_36 ( V_2 -> V_69 ) ;
F_34 ( V_2 -> V_68 ) ;
return 0 ;
}
static int F_37 ( struct V_66 * V_67 , struct V_66 * V_71 ,
void * V_72 )
{
struct V_73 * V_74 = F_38 ( V_67 ) ;
struct V_75 * V_76 = V_72 ;
struct V_77 * V_78 = V_76 -> V_79 ;
struct V_1 * V_2 ;
struct V_80 * V_81 ;
void T_3 * V_4 ;
int V_3 , V_48 ;
V_2 = F_39 ( V_67 , sizeof( * V_2 ) , V_82 ) ;
if ( ! V_2 )
return - V_83 ;
F_40 ( V_67 , V_2 ) ;
V_78 -> V_2 = V_2 ;
V_81 = F_41 ( V_74 , V_84 , 0 ) ;
V_4 = F_42 ( V_67 , V_81 ) ;
if ( F_28 ( V_4 ) )
return F_30 ( V_4 ) ;
V_2 -> V_4 = F_43 ( V_67 , V_4 ,
& V_85 ) ;
if ( F_28 ( V_2 -> V_4 ) ) {
F_29 ( V_67 , L_23 ) ;
return F_30 ( V_2 -> V_4 ) ;
}
V_2 -> V_86 = F_27 ( V_67 , NULL ) ;
if ( F_28 ( V_2 -> V_86 ) ) {
F_29 ( V_67 , L_24 ) ;
return F_30 ( V_2 -> V_86 ) ;
}
V_48 = F_31 ( V_2 -> V_86 ) ;
if ( V_48 ) {
F_29 ( V_67 , L_25 ) ;
return V_48 ;
}
V_2 -> V_87 = F_32 ( V_67 , L_26 ) ;
if ( F_28 ( V_2 -> V_87 ) ) {
F_29 ( V_67 , L_27 ) ;
V_48 = F_30 ( V_2 -> V_87 ) ;
goto V_70;
}
F_33 ( V_2 -> V_87 ) ;
V_2 -> V_88 = F_32 ( V_67 , L_28 ) ;
if ( F_28 ( V_2 -> V_88 ) ) {
F_29 ( V_67 , L_29 ) ;
V_48 = F_30 ( V_2 -> V_88 ) ;
goto V_89;
}
F_33 ( V_2 -> V_88 ) ;
V_2 -> V_90 = F_32 ( V_67 , L_30 ) ;
if ( F_28 ( V_2 -> V_90 ) ) {
F_29 ( V_67 , L_31 ) ;
V_48 = F_30 ( V_2 -> V_90 ) ;
goto V_91;
}
F_33 ( V_2 -> V_90 ) ;
if ( F_44 ( V_67 -> V_92 ,
L_32 ) ) {
V_48 = F_25 ( V_67 ) ;
if ( V_48 ) {
F_29 ( V_67 , L_33 ) ;
goto V_93;
}
}
for ( V_3 = 0x800 ; V_3 < 0x1000 ; V_3 += 4 )
F_3 ( V_2 -> V_4 , V_3 , 0 ) ;
F_3 ( V_2 -> V_4 , V_8 ,
V_9 ) ;
F_3 ( V_2 -> V_4 , V_14 ,
V_94 |
V_95 ) ;
return 0 ;
V_93:
F_36 ( V_2 -> V_90 ) ;
V_91:
F_36 ( V_2 -> V_88 ) ;
V_89:
F_36 ( V_2 -> V_87 ) ;
V_70:
F_34 ( V_2 -> V_86 ) ;
return V_48 ;
}
static void F_45 ( struct V_66 * V_67 , struct V_66 * V_71 ,
void * V_72 )
{
struct V_1 * V_2 = F_26 ( V_67 ) ;
if ( F_44 ( V_67 -> V_92 ,
L_32 ) )
F_35 ( V_67 ) ;
F_36 ( V_2 -> V_90 ) ;
F_36 ( V_2 -> V_88 ) ;
F_36 ( V_2 -> V_87 ) ;
F_34 ( V_2 -> V_86 ) ;
}
static int F_46 ( struct V_73 * V_74 )
{
return F_47 ( & V_74 -> V_67 , & V_96 ) ;
}
static int F_48 ( struct V_73 * V_74 )
{
F_49 ( & V_74 -> V_67 , & V_96 ) ;
return 0 ;
}
