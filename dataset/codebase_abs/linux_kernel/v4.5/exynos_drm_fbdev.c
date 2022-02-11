static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
unsigned long V_12 ;
int V_13 ;
V_4 -> V_14 |= V_15 | V_16 | V_17 ;
V_12 = V_4 -> V_18 - V_4 -> V_19 ;
if ( V_12 > V_11 -> V_20 )
return - V_21 ;
V_13 = F_3 ( V_6 -> V_22 -> V_22 , V_4 , V_11 -> V_23 ,
V_11 -> V_24 , V_11 -> V_20 ,
& V_11 -> V_25 ) ;
if ( V_13 < 0 ) {
F_4 ( L_1 ) ;
return V_13 ;
}
return 0 ;
}
static int F_5 ( struct V_5 * V_6 ,
struct V_26 * V_27 ,
struct V_10 * V_11 )
{
struct V_1 * V_28 ;
struct V_29 * V_30 = V_6 -> V_30 ;
unsigned int V_20 = V_30 -> V_31 * V_30 -> V_32 * ( V_30 -> V_33 >> 3 ) ;
unsigned int V_34 ;
unsigned long V_35 ;
V_28 = F_6 ( V_6 ) ;
if ( F_7 ( V_28 ) ) {
F_4 ( L_2 ) ;
return F_8 ( V_28 ) ;
}
V_28 -> V_7 = V_6 ;
V_28 -> V_36 = V_37 ;
V_28 -> V_38 = & V_39 ;
F_9 ( V_28 , V_30 -> V_40 [ 0 ] , V_30 -> V_41 ) ;
F_10 ( V_28 , V_6 , V_27 -> V_42 , V_27 -> V_43 ) ;
V_34 = V_11 -> V_20 >> V_44 ;
V_11 -> V_45 = ( void V_46 * ) F_11 ( V_11 -> V_47 , V_34 ,
V_48 , F_12 ( V_49 ) ) ;
if ( ! V_11 -> V_45 ) {
F_4 ( L_3 ) ;
F_13 ( V_6 ) ;
return - V_50 ;
}
V_35 = V_28 -> V_51 . V_52 * ( V_30 -> V_33 >> 3 ) ;
V_35 += V_28 -> V_51 . V_53 * V_30 -> V_40 [ 0 ] ;
V_28 -> V_54 = V_11 -> V_45 + V_35 ;
V_28 -> V_55 = V_20 ;
V_28 -> V_56 . V_57 = V_20 ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 ,
struct V_26 * V_27 )
{
struct V_8 * V_58 = F_2 ( V_6 ) ;
struct V_10 * V_11 ;
struct V_59 * V_22 = V_6 -> V_22 ;
struct V_60 V_61 = { 0 } ;
struct V_62 * V_63 = V_22 -> V_64 ;
unsigned long V_20 ;
int V_13 ;
F_15 ( L_4 ,
V_27 -> V_65 , V_27 -> V_66 ,
V_27 -> V_67 ) ;
V_61 . V_31 = V_27 -> V_65 ;
V_61 . V_32 = V_27 -> V_66 ;
V_61 . V_40 [ 0 ] = V_27 -> V_65 * ( V_27 -> V_67 >> 3 ) ;
V_61 . V_68 = F_16 ( V_27 -> V_67 ,
V_27 -> V_69 ) ;
F_17 ( & V_22 -> V_70 ) ;
V_20 = V_61 . V_40 [ 0 ] * V_61 . V_32 ;
V_11 = F_18 ( V_22 , V_71 , V_20 ) ;
if ( F_7 ( V_11 ) && F_19 ( V_22 ) ) {
F_20 ( & V_63 -> V_22 , L_5 ) ;
V_11 = F_18 ( V_22 , V_72 ,
V_20 ) ;
}
if ( F_7 ( V_11 ) ) {
V_13 = F_8 ( V_11 ) ;
goto V_73;
}
V_58 -> V_11 = V_11 ;
V_6 -> V_30 =
F_21 ( V_22 , & V_61 , & V_11 , 1 ) ;
if ( F_7 ( V_6 -> V_30 ) ) {
F_4 ( L_6 ) ;
V_13 = F_8 ( V_6 -> V_30 ) ;
goto V_74;
}
V_13 = F_5 ( V_6 , V_27 , V_11 ) ;
if ( V_13 < 0 )
goto V_75;
F_22 ( & V_22 -> V_70 ) ;
return V_13 ;
V_75:
F_23 ( V_6 -> V_30 ) ;
V_74:
F_24 ( V_11 ) ;
V_73:
F_22 ( & V_22 -> V_70 ) ;
return V_13 ;
}
static bool F_25 ( struct V_59 * V_22 )
{
struct V_76 * V_77 ;
bool V_13 = false ;
F_17 ( & V_22 -> V_78 . V_79 ) ;
F_26 (connector, &dev->mode_config.connector_list, head) {
if ( V_77 -> V_80 != V_81 )
continue;
V_13 = true ;
break;
}
F_22 ( & V_22 -> V_78 . V_79 ) ;
return V_13 ;
}
int F_27 ( struct V_59 * V_22 )
{
struct V_8 * V_82 ;
struct V_83 * V_84 = V_22 -> V_85 ;
struct V_5 * V_6 ;
unsigned int V_86 ;
int V_13 ;
if ( ! V_22 -> V_78 . V_86 || ! V_22 -> V_78 . V_87 )
return 0 ;
if ( ! F_25 ( V_22 ) )
return 0 ;
V_82 = F_28 ( sizeof( * V_82 ) , V_88 ) ;
if ( ! V_82 )
return - V_89 ;
V_84 -> V_90 = V_6 = & V_82 -> V_5 ;
F_29 ( V_22 , V_6 , & V_91 ) ;
V_86 = V_22 -> V_78 . V_86 ;
V_13 = F_30 ( V_22 , V_6 , V_86 , V_92 ) ;
if ( V_13 < 0 ) {
F_4 ( L_7 ) ;
goto V_93;
}
V_13 = F_31 ( V_6 ) ;
if ( V_13 < 0 ) {
F_4 ( L_8 ) ;
goto V_94;
}
V_13 = F_32 ( V_6 , V_95 ) ;
if ( V_13 < 0 ) {
F_4 ( L_9 ) ;
goto V_94;
}
return 0 ;
V_94:
F_33 ( V_6 ) ;
V_93:
V_84 -> V_90 = NULL ;
F_34 ( V_82 ) ;
return V_13 ;
}
static void F_35 ( struct V_59 * V_22 ,
struct V_5 * V_90 )
{
struct V_8 * V_9 = F_2 ( V_90 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_29 * V_30 ;
if ( V_11 -> V_45 )
F_36 ( V_11 -> V_45 ) ;
if ( V_90 -> V_30 && V_90 -> V_30 -> V_96 ) {
V_30 = V_90 -> V_30 ;
if ( V_30 ) {
F_37 ( V_30 ) ;
F_38 ( V_30 ) ;
}
}
F_39 ( V_90 ) ;
F_13 ( V_90 ) ;
F_33 ( V_90 ) ;
}
void F_40 ( struct V_59 * V_22 )
{
struct V_83 * V_84 = V_22 -> V_85 ;
struct V_8 * V_82 ;
if ( ! V_84 || ! V_84 -> V_90 )
return;
V_82 = F_2 ( V_84 -> V_90 ) ;
F_35 ( V_22 , V_84 -> V_90 ) ;
F_34 ( V_82 ) ;
V_84 -> V_90 = NULL ;
}
void F_41 ( struct V_59 * V_22 )
{
struct V_83 * V_84 = V_22 -> V_85 ;
if ( ! V_84 || ! V_84 -> V_90 )
return;
F_42 ( V_84 -> V_90 ) ;
}
