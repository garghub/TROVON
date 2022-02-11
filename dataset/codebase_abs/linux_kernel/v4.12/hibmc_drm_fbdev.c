static int F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * * V_6 )
{
struct V_5 * V_7 ;
struct V_8 * V_9 = V_2 -> V_9 ;
T_1 V_10 ;
int V_11 = 0 ;
V_10 = V_4 -> V_12 [ 0 ] * V_4 -> V_13 ;
V_11 = F_2 ( V_9 , V_10 , true , & V_7 ) ;
if ( V_11 )
return V_11 ;
* V_6 = V_7 ;
return V_11 ;
}
static int F_3 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 =
F_4 ( V_15 , struct V_18 , V_15 ) ;
struct V_1 * V_2 = V_15 -> V_9 -> V_20 ;
struct V_21 * V_22 ;
struct V_3 V_4 ;
struct V_5 * V_7 = NULL ;
int V_11 = 0 ;
int V_23 ;
T_2 V_10 ;
unsigned int V_24 ;
struct V_25 * V_26 = NULL ;
F_5 ( L_1 ,
V_17 -> V_27 , V_17 -> V_28 ,
V_17 -> V_29 ) ;
V_17 -> V_30 = 32 ;
V_24 = F_6 ( V_17 -> V_29 , 8 ) ;
V_4 . V_31 = V_17 -> V_27 ;
V_4 . V_13 = V_17 -> V_28 ;
V_4 . V_12 [ 0 ] = V_4 . V_31 * V_24 ;
V_4 . V_32 = F_7 ( V_17 -> V_29 ,
V_17 -> V_30 ) ;
V_10 = F_8 ( V_4 . V_12 [ 0 ] * V_4 . V_13 ) ;
V_11 = F_1 ( V_2 , & V_4 , & V_7 ) ;
if ( V_11 ) {
F_9 ( L_2 , V_11 ) ;
return - V_33 ;
}
V_26 = F_10 ( V_7 ) ;
V_11 = F_11 ( & V_26 -> V_26 , true , false , NULL ) ;
if ( V_11 ) {
F_9 ( L_3 , V_11 ) ;
goto V_34;
}
V_11 = F_12 ( V_26 , V_35 , NULL ) ;
if ( V_11 ) {
F_9 ( L_4 , V_11 ) ;
goto V_36;
}
V_11 = F_13 ( & V_26 -> V_26 , 0 , V_26 -> V_26 . V_37 , & V_26 -> V_38 ) ;
if ( V_11 ) {
F_9 ( L_5 , V_11 ) ;
goto V_39;
}
F_14 ( & V_26 -> V_26 ) ;
V_22 = F_15 ( V_15 ) ;
if ( F_16 ( V_22 ) ) {
V_11 = F_17 ( V_22 ) ;
F_9 ( L_6 , V_11 ) ;
goto V_40;
}
V_22 -> V_41 = V_19 ;
V_19 -> V_42 = F_18 ( V_2 -> V_9 , & V_4 , V_7 ) ;
if ( F_16 ( V_19 -> V_42 ) ) {
V_11 = F_17 ( V_19 -> V_42 ) ;
F_9 ( L_7 , V_11 ) ;
goto V_40;
}
V_2 -> V_43 -> V_10 = V_10 ;
V_19 -> V_15 . V_42 = & V_19 -> V_42 -> V_42 ;
strcpy ( V_22 -> V_44 . V_45 , L_8 ) ;
V_22 -> V_46 = V_47 ;
V_22 -> V_48 = & V_49 ;
F_19 ( V_22 , V_19 -> V_42 -> V_42 . V_12 [ 0 ] ,
V_19 -> V_42 -> V_42 . V_50 -> V_51 ) ;
F_20 ( V_22 , & V_2 -> V_43 -> V_15 , V_17 -> V_52 ,
V_17 -> V_53 ) ;
V_22 -> V_54 = V_26 -> V_38 . V_55 ;
V_22 -> V_56 = V_10 ;
V_22 -> V_44 . V_57 = V_26 -> V_26 . V_58 . V_59 . V_60 + V_26 -> V_26 . V_58 . V_59 . V_61 ;
V_22 -> V_44 . V_62 = V_10 ;
return 0 ;
V_40:
V_23 = F_11 ( & V_26 -> V_26 , true , false , NULL ) ;
if ( V_23 ) {
F_9 ( L_9 , V_23 ) ;
goto V_34;
}
F_21 ( & V_26 -> V_38 ) ;
V_39:
F_22 ( V_26 ) ;
V_36:
F_14 ( & V_26 -> V_26 ) ;
V_34:
F_23 ( V_7 ) ;
return V_11 ;
}
static void F_24 ( struct V_18 * V_43 )
{
struct V_63 * V_64 = V_43 -> V_42 ;
struct V_14 * V_65 = & V_43 -> V_15 ;
F_25 ( V_65 ) ;
F_26 ( V_65 ) ;
if ( V_64 )
F_27 ( & V_64 -> V_42 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_11 ;
struct V_66 * V_67 ;
struct V_68 * V_44 ;
struct V_18 * V_69 ;
V_69 = F_29 ( V_2 -> V_9 -> V_9 , sizeof( * V_69 ) , V_70 ) ;
if ( ! V_69 ) {
F_9 ( L_10 ) ;
return - V_33 ;
}
V_2 -> V_43 = V_69 ;
F_30 ( V_2 -> V_9 , & V_69 -> V_15 ,
& V_71 ) ;
V_11 = F_31 ( V_2 -> V_9 , & V_69 -> V_15 , 1 ) ;
if ( V_11 ) {
F_9 ( L_11 , V_11 ) ;
return V_11 ;
}
V_11 = F_32 ( & V_69 -> V_15 ) ;
if ( V_11 ) {
F_9 ( L_12 , V_11 ) ;
goto V_72;
}
V_11 = F_33 ( & V_69 -> V_15 , 16 ) ;
if ( V_11 ) {
F_9 ( L_13 , V_11 ) ;
goto V_72;
}
V_67 = & V_69 -> V_15 . V_43 -> V_67 ;
V_44 = & V_69 -> V_15 . V_43 -> V_44 ;
F_5 ( L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22 , V_67 -> V_73 , V_67 -> V_74 , V_67 -> V_75 ,
V_67 -> V_76 , V_67 -> V_77 , V_67 -> V_78 ,
V_67 -> V_79 ) ;
F_5 ( L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_30
L_31
L_32
L_33
L_34
L_22 , V_44 -> V_57 , V_44 -> V_62 , V_44 -> type ,
V_44 -> V_80 , V_44 -> V_81 , V_44 -> V_82 ,
V_44 -> V_83 , V_44 -> V_84 , V_44 -> V_85 ,
V_44 -> V_86 , V_44 -> V_87 ) ;
return 0 ;
V_72:
F_26 ( & V_69 -> V_15 ) ;
return V_11 ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_43 )
return;
F_24 ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
}
