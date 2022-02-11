static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 V_16 = {} ;
struct V_17 * V_18 ;
struct V_19 * V_19 = & V_6 -> V_20 -> V_6 ;
int V_21 , V_22 ;
if ( V_4 -> V_23 == 24 )
V_4 -> V_23 = 32 ;
V_16 . V_24 = V_4 -> V_25 ;
V_16 . V_26 = V_4 -> V_27 ;
V_16 . V_28 [ 0 ] = F_2 ( V_16 . V_24 * ( ( V_4 -> V_23 + 7 ) /
8 ) , 64 ) ;
V_16 . V_29 = F_3 ( V_4 -> V_23 ,
V_4 -> V_30 ) ;
V_21 = V_16 . V_28 [ 0 ] * V_16 . V_26 ;
V_21 = F_2 ( V_21 , V_31 ) ;
V_18 = F_4 ( V_6 , V_21 ) ;
if ( ! V_18 ) {
F_5 ( L_1 ) ;
V_22 = - V_32 ;
goto V_33;
}
F_6 ( & V_6 -> V_34 ) ;
V_22 = F_7 ( V_6 , V_18 , NULL ) ;
if ( V_22 ) {
F_5 ( L_2 , V_22 ) ;
goto V_35;
}
V_12 = F_8 ( 0 , V_19 ) ;
if ( ! V_12 ) {
V_22 = - V_32 ;
goto V_36;
}
V_12 -> V_37 = V_2 ;
V_22 = F_9 ( V_6 , & V_2 -> V_38 , & V_16 , V_18 ) ;
if ( V_22 )
goto V_36;
V_14 = & V_2 -> V_38 . V_39 ;
V_2 -> V_7 . V_14 = V_14 ;
V_2 -> V_7 . V_40 = V_12 ;
strcpy ( V_12 -> V_41 . V_42 , L_3 ) ;
V_12 -> V_43 = V_44 | V_45 ;
V_12 -> V_46 = & V_47 ;
V_22 = F_10 ( & V_12 -> V_48 , 256 , 0 ) ;
if ( V_22 ) {
V_22 = - V_32 ;
goto V_36;
}
V_12 -> V_49 = F_11 ( 1 ) ;
if ( ! V_12 -> V_49 ) {
V_22 = - V_32 ;
goto V_36;
}
V_12 -> V_49 -> V_50 [ 0 ] . V_39 = V_6 -> V_51 . V_52 ;
V_12 -> V_49 -> V_50 [ 0 ] . V_21 =
V_9 -> V_53 . V_54 -> V_55 << V_56 ;
V_12 -> V_41 . V_57 = V_6 -> V_51 . V_52 + V_18 -> V_58 ;
V_12 -> V_41 . V_59 = V_21 ;
V_12 -> V_60 =
F_12 ( V_9 -> V_53 . V_61 + V_18 -> V_58 ,
V_21 ) ;
if ( ! V_12 -> V_60 ) {
V_22 = - V_62 ;
goto V_36;
}
V_12 -> V_63 = V_21 ;
F_13 ( V_12 , V_14 -> V_28 [ 0 ] , V_14 -> V_64 ) ;
F_14 ( V_12 , & V_2 -> V_7 , V_4 -> V_65 , V_4 -> V_66 ) ;
F_15 ( L_4 ,
V_14 -> V_24 , V_14 -> V_26 ,
V_18 -> V_58 , V_18 ) ;
F_16 ( & V_6 -> V_34 ) ;
F_17 ( V_6 -> V_20 , V_12 ) ;
return 0 ;
V_36:
F_18 ( V_18 ) ;
V_35:
F_19 ( & V_18 -> V_39 ) ;
F_16 ( & V_6 -> V_34 ) ;
V_33:
return V_22 ;
}
static int F_20 ( struct V_67 * V_7 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 ;
int V_68 = 0 ;
int V_22 ;
if ( ! V_7 -> V_14 ) {
V_22 = F_1 ( V_2 , V_4 ) ;
if ( V_22 )
return V_22 ;
V_68 = 1 ;
}
return V_68 ;
}
static void F_21 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_69 * V_38 = & V_2 -> V_38 ;
if ( V_2 -> V_7 . V_40 ) {
V_12 = V_2 -> V_7 . V_40 ;
F_22 ( V_12 ) ;
F_23 ( V_12 -> V_60 ) ;
if ( V_12 -> V_48 . V_70 )
F_24 ( & V_12 -> V_48 ) ;
F_25 ( V_12 ) ;
}
F_26 ( & V_2 -> V_7 ) ;
F_27 ( & V_38 -> V_39 ) ;
if ( V_38 -> V_18 ) {
F_28 ( & V_38 -> V_18 -> V_39 ) ;
V_38 -> V_18 = NULL ;
}
}
int F_29 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
T_1 * V_9 = V_6 -> V_10 ;
int V_22 ;
V_2 = F_30 ( sizeof( struct V_1 ) , V_71 ) ;
if ( ! V_2 )
return - V_32 ;
V_9 -> V_40 = V_2 ;
V_2 -> V_7 . V_72 = & V_73 ;
V_22 = F_31 ( V_6 , & V_2 -> V_7 ,
V_9 -> V_74 ,
V_75 ) ;
if ( V_22 ) {
F_32 ( V_2 ) ;
return V_22 ;
}
F_33 ( & V_2 -> V_7 ) ;
F_34 ( & V_2 -> V_7 , 32 ) ;
return 0 ;
}
void F_35 ( struct V_5 * V_6 )
{
T_1 * V_9 = V_6 -> V_10 ;
if ( ! V_9 -> V_40 )
return;
F_21 ( V_6 , V_9 -> V_40 ) ;
F_32 ( V_9 -> V_40 ) ;
V_9 -> V_40 = NULL ;
}
void F_36 ( struct V_5 * V_6 , int V_76 )
{
T_1 * V_9 = V_6 -> V_10 ;
if ( ! V_9 -> V_40 )
return;
F_37 ( V_9 -> V_40 -> V_7 . V_40 , V_76 ) ;
}
void F_38 ( struct V_5 * V_6 )
{
T_1 * V_9 = V_6 -> V_10 ;
F_39 ( & V_9 -> V_40 -> V_7 ) ;
}
void F_40 ( struct V_5 * V_6 )
{
int V_22 ;
T_1 * V_9 = V_6 -> V_10 ;
struct V_77 * V_78 = & V_6 -> V_51 ;
struct V_79 * V_80 ;
F_6 ( & V_6 -> V_51 . V_81 ) ;
V_22 = F_41 ( & V_9 -> V_40 -> V_7 ) ;
if ( V_22 )
F_42 ( L_5 ) ;
F_43 (plane, &config->plane_list, head)
V_80 -> V_72 -> V_82 ( V_80 ) ;
F_16 ( & V_6 -> V_51 . V_81 ) ;
}
