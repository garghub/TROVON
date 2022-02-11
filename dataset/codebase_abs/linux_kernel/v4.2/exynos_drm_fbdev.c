static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_13 ;
unsigned long V_14 ;
int V_15 ;
V_4 -> V_16 |= V_17 | V_18 | V_19 ;
V_14 = V_4 -> V_20 - V_4 -> V_21 ;
if ( V_14 > V_13 -> V_22 )
return - V_23 ;
V_15 = F_3 ( V_6 -> V_24 -> V_24 , V_4 , V_13 -> V_25 ,
V_13 -> V_26 , V_13 -> V_22 , & V_13 -> V_27 ) ;
if ( V_15 < 0 ) {
F_4 ( L_1 ) ;
return V_15 ;
}
return 0 ;
}
static int F_5 ( struct V_5 * V_6 ,
struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_32 = V_6 -> V_33 ;
struct V_12 * V_13 ;
unsigned int V_22 = V_31 -> V_34 * V_31 -> V_35 * ( V_31 -> V_36 >> 3 ) ;
unsigned int V_37 ;
unsigned long V_38 ;
F_6 ( V_32 , V_31 -> V_39 [ 0 ] , V_31 -> V_40 ) ;
F_7 ( V_32 , V_6 , V_29 -> V_41 , V_29 -> V_42 ) ;
V_13 = F_8 ( V_31 , 0 ) ;
if ( ! V_13 ) {
F_9 ( L_2 ) ;
return - V_43 ;
}
V_37 = V_13 -> V_22 >> V_44 ;
V_13 -> V_45 = ( void V_46 * ) F_10 ( V_13 -> V_25 ,
V_37 , V_47 ,
F_11 ( V_48 ) ) ;
if ( ! V_13 -> V_45 ) {
F_4 ( L_3 ) ;
return - V_49 ;
}
F_12 ( V_31 , 1 ) ;
V_38 = V_32 -> V_50 . V_51 * ( V_31 -> V_36 >> 3 ) ;
V_38 += V_32 -> V_50 . V_52 * V_31 -> V_39 [ 0 ] ;
V_32 -> V_53 = V_13 -> V_45 + V_38 ;
V_32 -> V_54 = V_22 ;
V_32 -> V_55 . V_56 = V_22 ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 ,
struct V_28 * V_29 )
{
struct V_8 * V_57 = F_2 ( V_6 ) ;
struct V_10 * V_11 ;
struct V_58 * V_24 = V_6 -> V_24 ;
struct V_1 * V_32 ;
struct V_59 V_60 = { 0 } ;
struct V_61 * V_62 = V_24 -> V_63 ;
unsigned long V_22 ;
int V_15 ;
F_9 ( L_4 ,
V_29 -> V_64 , V_29 -> V_65 ,
V_29 -> V_66 ) ;
V_60 . V_34 = V_29 -> V_64 ;
V_60 . V_35 = V_29 -> V_65 ;
V_60 . V_39 [ 0 ] = V_29 -> V_64 * ( V_29 -> V_66 >> 3 ) ;
V_60 . V_67 = F_14 ( V_29 -> V_66 ,
V_29 -> V_68 ) ;
F_15 ( & V_24 -> V_69 ) ;
V_32 = F_16 ( 0 , & V_62 -> V_24 ) ;
if ( ! V_32 ) {
F_4 ( L_5 ) ;
V_15 = - V_70 ;
goto V_71;
}
V_22 = V_60 . V_39 [ 0 ] * V_60 . V_35 ;
V_11 = F_17 ( V_24 , V_72 , V_22 ) ;
if ( F_18 ( V_11 ) && F_19 ( V_24 ) ) {
F_20 ( & V_62 -> V_24 , L_6 ) ;
V_11 = F_17 ( V_24 , V_73 ,
V_22 ) ;
}
if ( F_18 ( V_11 ) ) {
V_15 = F_21 ( V_11 ) ;
goto V_74;
}
V_57 -> V_11 = V_11 ;
V_6 -> V_31 = F_22 ( V_24 , & V_60 ,
& V_11 -> V_75 ) ;
if ( F_18 ( V_6 -> V_31 ) ) {
F_4 ( L_7 ) ;
V_15 = F_21 ( V_6 -> V_31 ) ;
goto V_76;
}
V_6 -> V_33 = V_32 ;
V_32 -> V_7 = V_6 ;
V_32 -> V_77 = V_78 ;
V_32 -> V_79 = & V_80 ;
V_15 = F_23 ( & V_32 -> V_81 , 256 , 0 ) ;
if ( V_15 ) {
F_4 ( L_8 ) ;
goto V_82;
}
V_15 = F_5 ( V_6 , V_29 , V_6 -> V_31 ) ;
if ( V_15 < 0 )
goto V_83;
F_24 ( & V_24 -> V_69 ) ;
return V_15 ;
V_83:
F_25 ( & V_32 -> V_81 ) ;
V_82:
F_26 ( V_6 -> V_31 ) ;
V_76:
F_27 ( V_11 ) ;
V_74:
F_28 ( V_32 ) ;
V_71:
F_24 ( & V_24 -> V_69 ) ;
return V_15 ;
}
static bool F_29 ( struct V_58 * V_24 )
{
struct V_84 * V_85 ;
bool V_15 = false ;
F_15 ( & V_24 -> V_86 . V_87 ) ;
F_30 (connector, &dev->mode_config.connector_list, head) {
if ( V_85 -> V_88 != V_89 )
continue;
V_15 = true ;
break;
}
F_24 ( & V_24 -> V_86 . V_87 ) ;
return V_15 ;
}
int F_31 ( struct V_58 * V_24 )
{
struct V_8 * V_33 ;
struct V_90 * V_91 = V_24 -> V_92 ;
struct V_5 * V_6 ;
unsigned int V_93 ;
int V_15 ;
if ( ! V_24 -> V_86 . V_93 || ! V_24 -> V_86 . V_94 )
return 0 ;
if ( ! F_29 ( V_24 ) )
return 0 ;
V_33 = F_32 ( sizeof( * V_33 ) , V_95 ) ;
if ( ! V_33 )
return - V_70 ;
V_91 -> V_96 = V_6 = & V_33 -> V_5 ;
F_33 ( V_24 , V_6 , & V_97 ) ;
V_93 = V_24 -> V_86 . V_93 ;
V_15 = F_34 ( V_24 , V_6 , V_93 , V_98 ) ;
if ( V_15 < 0 ) {
F_4 ( L_9 ) ;
goto V_99;
}
V_15 = F_35 ( V_6 ) ;
if ( V_15 < 0 ) {
F_4 ( L_10 ) ;
goto V_100;
}
V_15 = F_36 ( V_6 , V_101 ) ;
if ( V_15 < 0 ) {
F_4 ( L_11 ) ;
goto V_100;
}
return 0 ;
V_100:
F_37 ( V_6 ) ;
V_99:
V_91 -> V_96 = NULL ;
F_38 ( V_33 ) ;
return V_15 ;
}
static void F_39 ( struct V_58 * V_24 ,
struct V_5 * V_96 )
{
struct V_8 * V_9 = F_2 ( V_96 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_30 * V_31 ;
if ( V_11 -> V_13 -> V_45 )
F_40 ( V_11 -> V_13 -> V_45 ) ;
if ( V_96 -> V_31 && V_96 -> V_31 -> V_102 ) {
V_31 = V_96 -> V_31 ;
if ( V_31 ) {
F_41 ( V_31 ) ;
F_42 ( V_31 ) ;
}
}
if ( V_96 -> V_33 ) {
struct V_1 * V_2 ;
int V_15 ;
V_2 = V_96 -> V_33 ;
V_15 = F_43 ( V_2 ) ;
if ( V_15 < 0 )
F_9 ( L_12 ) ;
if ( V_2 -> V_81 . V_103 )
F_25 ( & V_2 -> V_81 ) ;
F_28 ( V_2 ) ;
}
F_37 ( V_96 ) ;
}
void F_44 ( struct V_58 * V_24 )
{
struct V_90 * V_91 = V_24 -> V_92 ;
struct V_8 * V_33 ;
if ( ! V_91 || ! V_91 -> V_96 )
return;
V_33 = F_2 ( V_91 -> V_96 ) ;
F_39 ( V_24 , V_91 -> V_96 ) ;
F_38 ( V_33 ) ;
V_91 -> V_96 = NULL ;
}
void F_45 ( struct V_58 * V_24 )
{
struct V_90 * V_91 = V_24 -> V_92 ;
if ( ! V_91 || ! V_91 -> V_96 )
return;
F_46 ( V_91 -> V_96 ) ;
}
