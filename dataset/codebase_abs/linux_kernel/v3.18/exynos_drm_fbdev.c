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
V_30 -> V_50 = V_13 -> V_40 + V_36 ;
V_30 -> V_51 = V_22 ;
V_30 -> V_52 . V_53 = V_22 ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 ,
struct V_54 * V_55 )
{
struct V_8 * V_56 = F_2 ( V_6 ) ;
struct V_10 * V_11 ;
struct V_32 * V_24 = V_6 -> V_24 ;
struct V_1 * V_30 ;
struct V_57 V_58 = { 0 } ;
struct V_59 * V_60 = V_24 -> V_61 ;
unsigned long V_22 ;
int V_15 ;
F_9 ( L_4 ,
V_55 -> V_62 , V_55 -> V_63 ,
V_55 -> V_64 ) ;
V_58 . V_33 = V_55 -> V_62 ;
V_58 . V_34 = V_55 -> V_63 ;
V_58 . V_37 [ 0 ] = V_55 -> V_62 * ( V_55 -> V_64 >> 3 ) ;
V_58 . V_65 = F_16 ( V_55 -> V_64 ,
V_55 -> V_66 ) ;
F_17 ( & V_24 -> V_67 ) ;
V_30 = F_18 ( 0 , & V_60 -> V_24 ) ;
if ( ! V_30 ) {
F_4 ( L_5 ) ;
V_15 = - V_68 ;
goto V_69;
}
V_22 = V_58 . V_37 [ 0 ] * V_58 . V_34 ;
V_11 = F_19 ( V_24 , V_70 , V_22 ) ;
if ( F_20 ( V_11 ) && F_10 ( V_24 ) ) {
F_21 ( & V_60 -> V_24 , L_6 ) ;
V_11 = F_19 ( V_24 , V_71 ,
V_22 ) ;
}
if ( F_20 ( V_11 ) ) {
V_15 = F_22 ( V_11 ) ;
goto V_72;
}
V_56 -> V_11 = V_11 ;
V_6 -> V_29 = F_23 ( V_24 , & V_58 ,
& V_11 -> V_73 ) ;
if ( F_20 ( V_6 -> V_29 ) ) {
F_4 ( L_7 ) ;
V_15 = F_22 ( V_6 -> V_29 ) ;
goto V_74;
}
V_6 -> V_31 = V_30 ;
V_30 -> V_7 = V_6 ;
V_30 -> V_75 = V_76 ;
V_30 -> V_77 = & V_78 ;
V_15 = F_24 ( & V_30 -> V_79 , 256 , 0 ) ;
if ( V_15 ) {
F_4 ( L_8 ) ;
goto V_80;
}
V_15 = F_5 ( V_6 , V_6 -> V_29 ) ;
if ( V_15 < 0 )
goto V_81;
F_25 ( & V_24 -> V_67 ) ;
return V_15 ;
V_81:
F_26 ( & V_30 -> V_79 ) ;
V_80:
F_27 ( V_6 -> V_29 ) ;
V_74:
F_28 ( V_11 ) ;
V_72:
F_29 ( V_30 ) ;
V_69:
F_25 ( & V_24 -> V_67 ) ;
return V_15 ;
}
static bool F_30 ( struct V_32 * V_24 )
{
struct V_82 * V_83 ;
bool V_15 = false ;
F_17 ( & V_24 -> V_84 . V_85 ) ;
F_31 (connector, &dev->mode_config.connector_list, head) {
if ( V_83 -> V_86 != V_87 )
continue;
V_15 = true ;
break;
}
F_25 ( & V_24 -> V_84 . V_85 ) ;
return V_15 ;
}
int F_32 ( struct V_32 * V_24 )
{
struct V_8 * V_31 ;
struct V_88 * V_89 = V_24 -> V_90 ;
struct V_5 * V_6 ;
unsigned int V_91 ;
int V_15 ;
if ( ! V_24 -> V_84 . V_91 || ! V_24 -> V_84 . V_92 )
return 0 ;
if ( ! F_30 ( V_24 ) )
return 0 ;
V_31 = F_33 ( sizeof( * V_31 ) , V_93 ) ;
if ( ! V_31 )
return - V_68 ;
V_89 -> V_94 = V_6 = & V_31 -> V_5 ;
F_34 ( V_24 , V_6 , & V_95 ) ;
V_91 = V_24 -> V_84 . V_91 ;
V_15 = F_35 ( V_24 , V_6 , V_91 , V_96 ) ;
if ( V_15 < 0 ) {
F_4 ( L_9 ) ;
goto V_97;
}
V_15 = F_36 ( V_6 ) ;
if ( V_15 < 0 ) {
F_4 ( L_10 ) ;
goto V_98;
}
F_37 ( V_24 ) ;
V_15 = F_38 ( V_6 , V_99 ) ;
if ( V_15 < 0 ) {
F_4 ( L_11 ) ;
goto V_98;
}
return 0 ;
V_98:
F_39 ( V_6 ) ;
V_97:
V_89 -> V_94 = NULL ;
F_40 ( V_31 ) ;
return V_15 ;
}
static void F_41 ( struct V_32 * V_24 ,
struct V_5 * V_94 )
{
struct V_8 * V_9 = F_2 ( V_94 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_28 * V_29 ;
if ( F_10 ( V_24 ) && V_11 -> V_13 -> V_40 )
F_42 ( V_11 -> V_13 -> V_40 ) ;
if ( V_94 -> V_29 && V_94 -> V_29 -> V_100 ) {
V_29 = V_94 -> V_29 ;
if ( V_29 ) {
F_43 ( V_29 ) ;
F_44 ( V_29 ) ;
}
}
if ( V_94 -> V_31 ) {
struct V_1 * V_2 ;
int V_15 ;
V_2 = V_94 -> V_31 ;
V_15 = F_45 ( V_2 ) ;
if ( V_15 < 0 )
F_9 ( L_12 ) ;
if ( V_2 -> V_79 . V_101 )
F_26 ( & V_2 -> V_79 ) ;
F_29 ( V_2 ) ;
}
F_39 ( V_94 ) ;
}
void F_46 ( struct V_32 * V_24 )
{
struct V_88 * V_89 = V_24 -> V_90 ;
struct V_8 * V_31 ;
if ( ! V_89 || ! V_89 -> V_94 )
return;
V_31 = F_2 ( V_89 -> V_94 ) ;
F_41 ( V_24 , V_89 -> V_94 ) ;
F_40 ( V_31 ) ;
V_89 -> V_94 = NULL ;
}
void F_47 ( struct V_32 * V_24 )
{
struct V_88 * V_89 = V_24 -> V_90 ;
if ( ! V_89 || ! V_89 -> V_94 )
return;
F_48 ( V_89 -> V_94 ) ;
}
