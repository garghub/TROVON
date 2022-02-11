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
V_13 = F_3 ( F_4 ( V_6 -> V_22 ) , V_4 , V_11 -> V_23 ,
V_11 -> V_24 , V_11 -> V_20 ,
V_11 -> V_25 ) ;
if ( V_13 < 0 ) {
F_5 ( L_1 ) ;
return V_13 ;
}
return 0 ;
}
static int F_6 ( struct V_5 * V_6 ,
struct V_26 * V_27 ,
struct V_10 * V_11 )
{
struct V_1 * V_28 ;
struct V_29 * V_30 = V_6 -> V_30 ;
unsigned int V_20 = V_30 -> V_31 * V_30 -> V_32 * V_30 -> V_33 -> V_34 [ 0 ] ;
unsigned int V_35 ;
unsigned long V_36 ;
V_28 = F_7 ( V_6 ) ;
if ( F_8 ( V_28 ) ) {
F_5 ( L_2 ) ;
return F_9 ( V_28 ) ;
}
V_28 -> V_7 = V_6 ;
V_28 -> V_37 = V_38 ;
V_28 -> V_39 = & V_40 ;
F_10 ( V_28 , V_30 -> V_41 [ 0 ] , V_30 -> V_33 -> V_42 ) ;
F_11 ( V_28 , V_6 , V_27 -> V_43 , V_27 -> V_44 ) ;
V_35 = V_11 -> V_20 >> V_45 ;
V_11 -> V_46 = ( void V_47 * ) F_12 ( V_11 -> V_48 , V_35 ,
V_49 , F_13 ( V_50 ) ) ;
if ( ! V_11 -> V_46 ) {
F_5 ( L_3 ) ;
F_14 ( V_6 ) ;
return - V_51 ;
}
V_36 = V_28 -> V_52 . V_53 * V_30 -> V_33 -> V_34 [ 0 ] ;
V_36 += V_28 -> V_52 . V_54 * V_30 -> V_41 [ 0 ] ;
V_28 -> V_55 = V_11 -> V_46 + V_36 ;
V_28 -> V_56 = V_20 ;
V_28 -> V_57 . V_58 = V_20 ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 ,
struct V_26 * V_27 )
{
struct V_8 * V_59 = F_2 ( V_6 ) ;
struct V_10 * V_11 ;
struct V_60 * V_22 = V_6 -> V_22 ;
struct V_61 V_62 = { 0 } ;
struct V_63 * V_64 = V_22 -> V_65 ;
unsigned long V_20 ;
int V_13 ;
F_16 ( L_4 ,
V_27 -> V_66 , V_27 -> V_67 ,
V_27 -> V_68 ) ;
V_62 . V_31 = V_27 -> V_66 ;
V_62 . V_32 = V_27 -> V_67 ;
V_62 . V_41 [ 0 ] = V_27 -> V_66 * ( V_27 -> V_68 >> 3 ) ;
V_62 . V_69 = F_17 ( V_27 -> V_68 ,
V_27 -> V_70 ) ;
V_20 = V_62 . V_41 [ 0 ] * V_62 . V_32 ;
V_11 = F_18 ( V_22 , V_71 , V_20 ) ;
if ( F_8 ( V_11 ) && F_19 ( V_22 ) ) {
F_20 ( & V_64 -> V_22 , L_5 ) ;
V_11 = F_18 ( V_22 , V_72 ,
V_20 ) ;
}
if ( F_8 ( V_11 ) )
return F_9 ( V_11 ) ;
V_59 -> V_11 = V_11 ;
V_6 -> V_30 =
F_21 ( V_22 , & V_62 , & V_11 , 1 ) ;
if ( F_8 ( V_6 -> V_30 ) ) {
F_5 ( L_6 ) ;
V_13 = F_9 ( V_6 -> V_30 ) ;
goto V_73;
}
V_13 = F_6 ( V_6 , V_27 , V_11 ) ;
if ( V_13 < 0 )
goto V_74;
return V_13 ;
V_74:
F_22 ( V_6 -> V_30 ) ;
V_73:
F_23 ( V_11 ) ;
return V_13 ;
}
static bool F_24 ( struct V_60 * V_22 )
{
struct V_75 * V_76 ;
bool V_13 = false ;
F_25 ( & V_22 -> V_77 . V_78 ) ;
F_26 (connector, &dev->mode_config.connector_list, head) {
if ( V_76 -> V_79 != V_80 )
continue;
V_13 = true ;
break;
}
F_27 ( & V_22 -> V_77 . V_78 ) ;
return V_13 ;
}
int F_28 ( struct V_60 * V_22 )
{
struct V_8 * V_81 ;
struct V_82 * V_83 = V_22 -> V_84 ;
struct V_5 * V_6 ;
int V_13 ;
if ( ! V_22 -> V_77 . V_85 || ! V_22 -> V_77 . V_86 )
return 0 ;
if ( ! F_24 ( V_22 ) )
return 0 ;
V_81 = F_29 ( sizeof( * V_81 ) , V_87 ) ;
if ( ! V_81 )
return - V_88 ;
V_83 -> V_89 = V_6 = & V_81 -> V_5 ;
F_30 ( V_22 , V_6 , & V_90 ) ;
V_13 = F_31 ( V_22 , V_6 , V_91 ) ;
if ( V_13 < 0 ) {
F_5 ( L_7 ) ;
goto V_92;
}
V_13 = F_32 ( V_6 ) ;
if ( V_13 < 0 ) {
F_5 ( L_8 ) ;
goto V_93;
}
V_13 = F_33 ( V_6 , V_94 ) ;
if ( V_13 < 0 ) {
F_5 ( L_9 ) ;
goto V_93;
}
return 0 ;
V_93:
F_34 ( V_6 ) ;
V_92:
V_83 -> V_89 = NULL ;
F_35 ( V_81 ) ;
return V_13 ;
}
static void F_36 ( struct V_60 * V_22 ,
struct V_5 * V_89 )
{
struct V_8 * V_9 = F_2 ( V_89 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_29 * V_30 ;
F_37 ( V_11 -> V_46 ) ;
if ( V_89 -> V_30 && V_89 -> V_30 -> V_95 ) {
V_30 = V_89 -> V_30 ;
if ( V_30 )
F_38 ( V_30 ) ;
}
F_39 ( V_89 ) ;
F_14 ( V_89 ) ;
F_34 ( V_89 ) ;
}
void F_40 ( struct V_60 * V_22 )
{
struct V_82 * V_83 = V_22 -> V_84 ;
struct V_8 * V_81 ;
if ( ! V_83 || ! V_83 -> V_89 )
return;
V_81 = F_2 ( V_83 -> V_89 ) ;
F_36 ( V_22 , V_83 -> V_89 ) ;
F_35 ( V_81 ) ;
V_83 -> V_89 = NULL ;
}
void F_41 ( struct V_60 * V_22 )
{
struct V_82 * V_83 = V_22 -> V_84 ;
if ( ! V_83 || ! V_83 -> V_89 )
return;
F_42 ( V_83 -> V_89 ) ;
}
void F_43 ( struct V_60 * V_22 )
{
struct V_82 * V_83 = V_22 -> V_84 ;
struct V_5 * V_89 = V_83 -> V_89 ;
if ( V_89 )
F_44 ( V_89 ) ;
else
F_28 ( V_22 ) ;
}
