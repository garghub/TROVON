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
static int F_10 ( T_1 V_15 , T_1 * V_16 )
{
switch ( V_15 ) {
case V_17 :
* V_16 = V_18 ;
break;
case V_19 :
* V_16 = V_20 ;
break;
case V_21 :
* V_16 = V_22 ;
break;
default:
return - V_23 ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 ,
int V_11 , struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_27 ;
struct V_28 * V_29 = V_27 -> V_29 ;
F_2 ( L_5 , V_11 ) ;
if ( V_25 -> type == V_30 ) {
F_2 ( L_6 ,
V_27 -> V_31 , V_27 -> V_32 ) ;
F_3 ( V_2 -> V_4 , V_33 ,
F_12 ( V_27 -> V_31 ,
V_27 -> V_32 ) ) ;
}
F_2 ( L_7 , V_29 -> V_34 [ 0 ] * 8 ) ;
F_3 ( V_2 -> V_4 , F_13 ( V_11 ) ,
V_29 -> V_34 [ 0 ] * 8 ) ;
F_2 ( L_8 ,
V_27 -> V_31 , V_27 -> V_32 ) ;
F_3 ( V_2 -> V_4 , F_14 ( V_11 ) ,
F_15 ( V_27 -> V_31 ,
V_27 -> V_32 ) ) ;
F_2 ( L_9 ,
V_27 -> V_35 , V_27 -> V_36 ) ;
F_3 ( V_2 -> V_4 , F_16 ( V_11 ) ,
F_17 ( V_27 -> V_35 ,
V_27 -> V_36 ) ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 ,
int V_11 , struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_27 ;
struct V_28 * V_29 = V_27 -> V_29 ;
bool V_37 = false ;
T_1 V_13 ;
int V_38 ;
if ( V_25 -> V_27 -> V_39 )
V_37 = V_25 -> V_27 -> V_39 -> V_27 -> V_40 . V_41
& V_42 ;
F_6 ( V_2 -> V_4 , V_14 ,
V_43 ,
V_37 ? V_43 : 0 ) ;
F_2 ( L_10 ,
V_37 ? L_11 : L_12 ) ;
V_38 = F_10 ( V_29 -> V_44 , & V_13 ) ;
if ( V_38 ) {
F_2 ( L_13 ) ;
return V_13 ;
}
F_6 ( V_2 -> V_4 , F_19 ( V_11 ) ,
V_45 , V_13 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
int V_11 , struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_27 ;
struct V_28 * V_29 = V_27 -> V_29 ;
struct V_46 * V_47 ;
T_1 V_48 , V_49 ;
T_2 V_50 ;
int V_51 ;
V_47 = F_21 ( V_29 , 0 ) ;
F_2 ( L_14 , & V_47 -> V_50 ) ;
V_51 = F_22 ( V_29 -> V_44 , 0 ) ;
V_50 = V_47 -> V_50 + V_29 -> V_52 [ 0 ] ;
V_50 += ( V_27 -> V_53 >> 16 ) * V_51 ;
V_50 += ( V_27 -> V_54 >> 16 ) * V_29 -> V_34 [ 0 ] ;
F_2 ( L_15 , & V_50 ) ;
V_48 = V_50 << 3 ;
F_2 ( L_16 , V_48 ) ;
F_3 ( V_2 -> V_4 , F_23 ( V_11 ) ,
V_48 ) ;
V_49 = V_50 >> 29 ;
F_2 ( L_17 , V_49 ) ;
F_6 ( V_2 -> V_4 , V_55 ,
F_24 ( V_11 ) ,
F_25 ( V_11 , V_49 ) ) ;
return 0 ;
}
static int F_26 ( struct V_56 * V_57 , struct V_56 * V_58 ,
void * V_59 )
{
struct V_60 * V_61 = F_27 ( V_57 ) ;
struct V_62 * V_63 = V_59 ;
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
void T_3 * V_4 ;
int V_3 , V_38 ;
V_2 = F_28 ( V_57 , sizeof( * V_2 ) , V_69 ) ;
if ( ! V_2 )
return - V_70 ;
F_29 ( V_57 , V_2 ) ;
V_65 -> V_2 = V_2 ;
V_68 = F_30 ( V_61 , V_71 , 0 ) ;
V_4 = F_31 ( V_57 , V_68 ) ;
if ( F_32 ( V_4 ) ) {
F_33 ( V_57 , L_18 ) ;
return F_34 ( V_4 ) ;
}
V_2 -> V_4 = F_35 ( V_57 , V_4 ,
& V_72 ) ;
if ( F_32 ( V_2 -> V_4 ) ) {
F_33 ( V_57 , L_19 ) ;
return F_34 ( V_2 -> V_4 ) ;
}
V_2 -> V_73 = F_36 ( V_57 , NULL ) ;
if ( F_32 ( V_2 -> V_73 ) ) {
F_33 ( V_57 , L_20 ) ;
return F_34 ( V_2 -> V_73 ) ;
}
V_38 = F_37 ( V_2 -> V_73 ) ;
if ( V_38 ) {
F_33 ( V_57 , L_21 ) ;
return V_38 ;
}
V_2 -> V_74 = F_38 ( V_57 , L_22 ) ;
if ( F_32 ( V_2 -> V_74 ) ) {
F_33 ( V_57 , L_23 ) ;
V_38 = F_34 ( V_2 -> V_74 ) ;
goto V_75;
}
F_39 ( V_2 -> V_74 ) ;
V_2 -> V_76 = F_38 ( V_57 , L_24 ) ;
if ( F_32 ( V_2 -> V_76 ) ) {
F_33 ( V_57 , L_25 ) ;
V_38 = F_34 ( V_2 -> V_76 ) ;
goto V_77;
}
F_39 ( V_2 -> V_76 ) ;
V_2 -> V_78 = F_38 ( V_57 , L_26 ) ;
if ( F_32 ( V_2 -> V_78 ) ) {
F_33 ( V_57 , L_27 ) ;
V_38 = F_34 ( V_2 -> V_78 ) ;
goto V_79;
}
F_39 ( V_2 -> V_78 ) ;
for ( V_3 = 0x800 ; V_3 < 0x1000 ; V_3 += 4 )
F_3 ( V_2 -> V_4 , V_3 , 0 ) ;
F_3 ( V_2 -> V_4 , V_8 ,
V_9 ) ;
F_3 ( V_2 -> V_4 , V_14 ,
V_80 |
V_81 ) ;
return 0 ;
V_79:
F_40 ( V_2 -> V_76 ) ;
V_77:
F_40 ( V_2 -> V_74 ) ;
V_75:
F_41 ( V_2 -> V_73 ) ;
return V_38 ;
}
static void F_42 ( struct V_56 * V_57 , struct V_56 * V_58 ,
void * V_59 )
{
struct V_1 * V_2 = F_43 ( V_57 ) ;
F_40 ( V_2 -> V_78 ) ;
F_40 ( V_2 -> V_76 ) ;
F_40 ( V_2 -> V_74 ) ;
F_41 ( V_2 -> V_73 ) ;
}
static int F_44 ( struct V_60 * V_61 )
{
return F_45 ( & V_61 -> V_57 , & V_82 ) ;
}
static int F_46 ( struct V_60 * V_61 )
{
F_47 ( & V_61 -> V_57 , & V_82 ) ;
return 0 ;
}
