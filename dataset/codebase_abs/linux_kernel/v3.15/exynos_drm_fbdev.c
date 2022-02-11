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
struct V_28 * V_29 )
{
struct V_1 * V_30 = V_6 -> V_31 ;
struct V_32 * V_24 = V_6 -> V_24 ;
struct V_12 * V_13 ;
unsigned int V_22 = V_29 -> V_33 * V_29 -> V_34 * ( V_29 -> V_35 >> 3 ) ;
unsigned long V_36 ;
F_6 ( V_30 , V_29 -> V_37 [ 0 ] , V_29 -> V_38 ) ;
F_7 ( V_30 , V_6 , V_29 -> V_33 , V_29 -> V_34 ) ;
V_13 = F_8 ( V_29 , 0 ) ;
if ( ! V_13 ) {
F_9 ( L_2 ) ;
return - V_39 ;
}
if ( ! V_13 -> V_40 ) {
if ( F_10 ( V_24 ) ) {
unsigned int V_41 = V_13 -> V_22 >> V_42 ;
V_13 -> V_40 = ( void V_43 * ) F_11 ( V_13 -> V_25 ,
V_41 , V_44 ,
F_12 ( V_45 ) ) ;
} else {
T_1 V_26 = V_13 -> V_26 ;
if ( V_26 )
V_13 -> V_40 = ( void V_43 * ) F_13 ( V_26 ) ;
else
V_13 -> V_40 = ( void V_43 * ) NULL ;
}
if ( ! V_13 -> V_40 ) {
F_4 ( L_3 ) ;
return - V_46 ;
}
}
F_14 ( V_29 , 1 ) ;
V_36 = V_30 -> V_47 . V_48 * ( V_29 -> V_35 >> 3 ) ;
V_36 += V_30 -> V_47 . V_49 * V_29 -> V_37 [ 0 ] ;
V_24 -> V_50 . V_51 = ( V_52 ) V_13 -> V_26 ;
V_30 -> V_53 = V_13 -> V_40 + V_36 ;
if ( F_10 ( V_24 ) )
V_30 -> V_54 . V_55 = ( unsigned long )
( F_15 ( F_16 ( V_13 -> V_56 -> V_57 ) ) + V_36 ) ;
else
V_30 -> V_54 . V_55 = ( unsigned long ) V_13 -> V_26 ;
V_30 -> V_58 = V_22 ;
V_30 -> V_54 . V_59 = V_22 ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 ,
struct V_60 * V_61 )
{
struct V_8 * V_62 = F_2 ( V_6 ) ;
struct V_10 * V_11 ;
struct V_32 * V_24 = V_6 -> V_24 ;
struct V_1 * V_30 ;
struct V_63 V_64 = { 0 } ;
struct V_65 * V_66 = V_24 -> V_67 ;
unsigned long V_22 ;
int V_15 ;
F_9 ( L_4 ,
V_61 -> V_68 , V_61 -> V_69 ,
V_61 -> V_70 ) ;
V_64 . V_33 = V_61 -> V_68 ;
V_64 . V_34 = V_61 -> V_69 ;
V_64 . V_37 [ 0 ] = V_61 -> V_68 * ( V_61 -> V_70 >> 3 ) ;
V_64 . V_71 = F_18 ( V_61 -> V_70 ,
V_61 -> V_72 ) ;
F_19 ( & V_24 -> V_73 ) ;
V_30 = F_20 ( 0 , & V_66 -> V_24 ) ;
if ( ! V_30 ) {
F_4 ( L_5 ) ;
V_15 = - V_74 ;
goto V_75;
}
V_22 = V_64 . V_37 [ 0 ] * V_64 . V_34 ;
V_11 = F_21 ( V_24 , V_76 , V_22 ) ;
if ( F_22 ( V_11 ) && F_10 ( V_24 ) ) {
F_23 ( & V_66 -> V_24 , L_6 ) ;
V_11 = F_21 ( V_24 , V_77 ,
V_22 ) ;
}
if ( F_22 ( V_11 ) ) {
V_15 = F_24 ( V_11 ) ;
goto V_78;
}
V_62 -> V_11 = V_11 ;
V_6 -> V_29 = F_25 ( V_24 , & V_64 ,
& V_11 -> V_79 ) ;
if ( F_22 ( V_6 -> V_29 ) ) {
F_4 ( L_7 ) ;
V_15 = F_24 ( V_6 -> V_29 ) ;
goto V_80;
}
V_6 -> V_31 = V_30 ;
V_30 -> V_7 = V_6 ;
V_30 -> V_81 = V_82 ;
V_30 -> V_83 = & V_84 ;
V_15 = F_26 ( & V_30 -> V_85 , 256 , 0 ) ;
if ( V_15 ) {
F_4 ( L_8 ) ;
goto V_86;
}
V_15 = F_5 ( V_6 , V_6 -> V_29 ) ;
if ( V_15 < 0 )
goto V_87;
F_27 ( & V_24 -> V_73 ) ;
return V_15 ;
V_87:
F_28 ( & V_30 -> V_85 ) ;
V_86:
F_29 ( V_6 -> V_29 ) ;
V_80:
F_30 ( V_11 ) ;
V_78:
F_31 ( V_30 ) ;
V_75:
F_27 ( & V_24 -> V_73 ) ;
return V_15 ;
}
bool F_32 ( struct V_32 * V_24 )
{
struct V_88 * V_89 ;
bool V_15 = false ;
F_19 ( & V_24 -> V_50 . V_90 ) ;
F_33 (connector, &dev->mode_config.connector_list, head) {
if ( V_89 -> V_91 != V_92 )
continue;
V_15 = true ;
break;
}
F_27 ( & V_24 -> V_50 . V_90 ) ;
return V_15 ;
}
int F_34 ( struct V_32 * V_24 )
{
struct V_8 * V_31 ;
struct V_93 * V_94 = V_24 -> V_95 ;
struct V_5 * V_6 ;
unsigned int V_96 ;
int V_15 ;
if ( ! V_24 -> V_50 . V_96 || ! V_24 -> V_50 . V_97 )
return 0 ;
if ( ! F_32 ( V_24 ) )
return 0 ;
V_31 = F_35 ( sizeof( * V_31 ) , V_98 ) ;
if ( ! V_31 )
return - V_74 ;
V_94 -> V_99 = V_6 = & V_31 -> V_5 ;
V_6 -> V_100 = & V_101 ;
V_96 = V_24 -> V_50 . V_96 ;
V_15 = F_36 ( V_24 , V_6 , V_96 , V_102 ) ;
if ( V_15 < 0 ) {
F_4 ( L_9 ) ;
goto V_103;
}
V_15 = F_37 ( V_6 ) ;
if ( V_15 < 0 ) {
F_4 ( L_10 ) ;
goto V_104;
}
F_38 ( V_24 ) ;
V_15 = F_39 ( V_6 , V_105 ) ;
if ( V_15 < 0 ) {
F_4 ( L_11 ) ;
goto V_104;
}
return 0 ;
V_104:
F_40 ( V_6 ) ;
V_103:
V_94 -> V_99 = NULL ;
F_41 ( V_31 ) ;
return V_15 ;
}
static void F_42 ( struct V_32 * V_24 ,
struct V_5 * V_99 )
{
struct V_8 * V_9 = F_2 ( V_99 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_28 * V_29 ;
if ( F_10 ( V_24 ) && V_11 -> V_13 -> V_40 )
F_43 ( V_11 -> V_13 -> V_40 ) ;
if ( V_99 -> V_29 && V_99 -> V_29 -> V_100 ) {
V_29 = V_99 -> V_29 ;
if ( V_29 ) {
F_44 ( V_29 ) ;
F_45 ( V_29 ) ;
}
}
if ( V_99 -> V_31 ) {
struct V_1 * V_2 ;
int V_15 ;
V_2 = V_99 -> V_31 ;
V_15 = F_46 ( V_2 ) ;
if ( V_15 < 0 )
F_9 ( L_12 ) ;
if ( V_2 -> V_85 . V_106 )
F_28 ( & V_2 -> V_85 ) ;
F_31 ( V_2 ) ;
}
F_40 ( V_99 ) ;
}
void F_47 ( struct V_32 * V_24 )
{
struct V_93 * V_94 = V_24 -> V_95 ;
struct V_8 * V_31 ;
if ( ! V_94 || ! V_94 -> V_99 )
return;
V_31 = F_2 ( V_94 -> V_99 ) ;
if ( V_31 -> V_11 )
F_30 ( V_31 -> V_11 ) ;
F_42 ( V_24 , V_94 -> V_99 ) ;
F_41 ( V_31 ) ;
V_94 -> V_99 = NULL ;
}
void F_48 ( struct V_32 * V_24 )
{
struct V_93 * V_94 = V_24 -> V_95 ;
if ( ! V_94 || ! V_94 -> V_99 )
return;
F_49 ( V_24 ) ;
F_50 ( V_94 -> V_99 ) ;
F_51 ( V_24 ) ;
}
