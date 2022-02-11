static void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
int V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_12 , V_13 ;
int V_14 = V_2 -> V_15 . V_16 . V_17 -> V_18 [ 0 ] ;
int V_19 = - V_20 ;
bool V_21 = false ;
bool V_22 = false ;
int V_23 , V_24 ;
unsigned long V_25 ;
V_9 = V_2 -> V_15 . V_9 ;
V_11 = F_2 ( V_9 ) ;
if ( F_3 () )
V_19 = F_4 ( V_11 , true ) ;
if ( V_19 ) {
if ( V_19 != - V_20 )
return;
V_22 = true ;
}
V_23 = V_3 + V_5 - 1 ;
V_24 = V_4 + V_6 - 1 ;
F_5 ( & V_2 -> V_26 , V_25 ) ;
if ( V_2 -> y1 < V_4 )
V_4 = V_2 -> y1 ;
if ( V_2 -> V_24 > V_24 )
V_24 = V_2 -> V_24 ;
if ( V_2 -> V_27 < V_3 )
V_3 = V_2 -> V_27 ;
if ( V_2 -> V_23 > V_23 )
V_23 = V_2 -> V_23 ;
if ( V_22 ) {
V_2 -> V_27 = V_3 ;
V_2 -> V_23 = V_23 ;
V_2 -> y1 = V_4 ;
V_2 -> V_24 = V_24 ;
F_6 ( & V_2 -> V_26 , V_25 ) ;
return;
}
V_2 -> V_27 = V_2 -> y1 = V_28 ;
V_2 -> V_23 = V_2 -> V_24 = 0 ;
F_6 ( & V_2 -> V_26 , V_25 ) ;
if ( ! V_11 -> V_29 . V_30 ) {
V_19 = F_7 ( & V_11 -> V_11 , 0 , V_11 -> V_11 . V_31 , & V_11 -> V_29 ) ;
if ( V_19 ) {
F_8 ( L_1 ) ;
F_9 ( V_11 ) ;
return;
}
V_21 = true ;
}
for ( V_7 = V_4 ; V_7 <= V_24 ; V_7 ++ ) {
V_12 = V_13 = V_7 * V_2 -> V_15 . V_16 . V_32 [ 0 ] + ( V_3 * V_14 ) ;
F_10 ( V_11 -> V_29 . V_30 + V_12 , V_2 -> V_33 + V_12 , ( V_23 - V_3 + 1 ) * V_14 ) ;
}
if ( V_21 )
F_11 ( & V_11 -> V_29 ) ;
F_9 ( V_11 ) ;
}
static void F_12 ( struct V_34 * V_35 ,
const struct V_36 * V_37 )
{
struct V_1 * V_2 = V_35 -> V_38 ;
F_13 ( V_35 , V_37 ) ;
F_1 ( V_2 , V_37 -> V_39 , V_37 -> V_40 , V_37 -> V_5 ,
V_37 -> V_6 ) ;
}
static void F_14 ( struct V_34 * V_35 ,
const struct V_41 * V_42 )
{
struct V_1 * V_2 = V_35 -> V_38 ;
F_15 ( V_35 , V_42 ) ;
F_1 ( V_2 , V_42 -> V_39 , V_42 -> V_40 , V_42 -> V_5 ,
V_42 -> V_6 ) ;
}
static void F_16 ( struct V_34 * V_35 ,
const struct V_43 * V_44 )
{
struct V_1 * V_2 = V_35 -> V_38 ;
F_17 ( V_35 , V_44 ) ;
F_1 ( V_2 , V_44 -> V_39 , V_44 -> V_40 , V_44 -> V_5 ,
V_44 -> V_6 ) ;
}
static int F_18 ( struct V_1 * V_45 ,
const struct V_46 * V_47 ,
struct V_8 * * V_48 )
{
struct V_49 * V_50 = V_45 -> V_51 . V_50 ;
T_1 V_52 ;
struct V_8 * V_53 ;
int V_19 = 0 ;
V_52 = V_47 -> V_32 [ 0 ] * V_47 -> V_6 ;
V_19 = F_19 ( V_50 , V_52 , true , & V_53 ) ;
if ( V_19 )
return V_19 ;
* V_48 = V_53 ;
return V_19 ;
}
static int F_20 ( struct V_54 * V_51 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 =
F_21 ( V_51 , struct V_1 , V_51 ) ;
struct V_49 * V_50 = V_2 -> V_51 . V_50 ;
struct V_46 V_47 ;
struct V_57 * V_58 = V_50 -> V_59 ;
struct V_34 * V_35 ;
struct V_60 * V_61 ;
struct V_8 * V_53 = NULL ;
int V_19 ;
void * V_33 ;
int V_52 ;
V_47 . V_5 = V_56 -> V_62 ;
V_47 . V_6 = V_56 -> V_63 ;
V_47 . V_32 [ 0 ] = V_47 . V_5 * ( ( V_56 -> V_64 + 7 ) / 8 ) ;
V_47 . V_65 = F_22 ( V_56 -> V_64 ,
V_56 -> V_66 ) ;
V_52 = V_47 . V_32 [ 0 ] * V_47 . V_6 ;
V_19 = F_18 ( V_2 , & V_47 , & V_53 ) ;
if ( V_19 ) {
F_8 ( L_2 , V_19 ) ;
return V_19 ;
}
V_33 = F_23 ( V_52 ) ;
if ( ! V_33 ) {
V_19 = - V_67 ;
goto V_68;
}
V_35 = F_24 ( V_51 ) ;
if ( F_25 ( V_35 ) ) {
V_19 = F_26 ( V_35 ) ;
goto V_69;
}
V_35 -> V_38 = V_2 ;
V_19 = F_27 ( V_50 , & V_2 -> V_15 , & V_47 , V_53 ) ;
if ( V_19 )
goto V_70;
V_2 -> V_33 = V_33 ;
V_2 -> V_52 = V_52 ;
V_61 = & V_2 -> V_15 . V_16 ;
V_2 -> V_51 . V_61 = V_61 ;
strcpy ( V_35 -> V_71 . V_72 , L_3 ) ;
V_35 -> V_25 = V_73 | V_74 ;
V_35 -> V_75 = & V_76 ;
V_35 -> V_77 -> V_78 [ 0 ] . V_16 = V_58 -> V_50 -> V_79 . V_80 ;
V_35 -> V_77 -> V_78 [ 0 ] . V_52 = V_58 -> V_81 . V_82 ;
F_28 ( V_35 , V_61 -> V_32 [ 0 ] , V_61 -> V_17 -> V_83 ) ;
F_29 ( V_35 , & V_2 -> V_51 , V_56 -> V_84 ,
V_56 -> V_85 ) ;
V_35 -> V_86 = V_33 ;
V_35 -> V_87 = V_52 ;
V_35 -> V_88 . V_25 = V_89 ;
F_30 ( L_4 ,
V_61 -> V_5 , V_61 -> V_6 ) ;
return 0 ;
V_70:
F_31 ( V_51 ) ;
V_69:
F_32 ( V_33 ) ;
V_68:
F_33 ( V_53 ) ;
return V_19 ;
}
static int F_34 ( struct V_49 * V_50 ,
struct V_1 * V_2 )
{
struct V_90 * V_15 = & V_2 -> V_15 ;
F_35 ( & V_2 -> V_51 ) ;
F_31 ( & V_2 -> V_51 ) ;
if ( V_15 -> V_9 ) {
F_33 ( V_15 -> V_9 ) ;
V_15 -> V_9 = NULL ;
}
F_36 ( & V_2 -> V_51 ) ;
F_32 ( V_2 -> V_33 ) ;
F_37 ( & V_15 -> V_16 ) ;
F_38 ( & V_15 -> V_16 ) ;
return 0 ;
}
int F_39 ( struct V_57 * V_58 )
{
struct V_1 * V_2 ;
int V_19 ;
int V_91 = 32 ;
if ( F_40 ( V_58 ) && V_58 -> V_81 . V_82 < ( 2048 * 1024 ) )
V_91 = 16 ;
V_2 = F_41 ( V_58 -> V_50 -> V_50 , sizeof( struct V_1 ) , V_92 ) ;
if ( ! V_2 )
return - V_67 ;
V_58 -> V_2 = V_2 ;
F_42 ( & V_2 -> V_26 ) ;
F_43 ( V_58 -> V_50 , & V_2 -> V_51 , & V_93 ) ;
V_19 = F_44 ( V_58 -> V_50 , & V_2 -> V_51 ,
V_94 ) ;
if ( V_19 )
goto V_95;
V_19 = F_45 ( & V_2 -> V_51 ) ;
if ( V_19 )
goto V_96;
F_46 ( V_58 -> V_50 ) ;
V_19 = F_47 ( & V_2 -> V_51 , V_91 ) ;
if ( V_19 )
goto V_96;
return 0 ;
V_96:
F_36 ( & V_2 -> V_51 ) ;
V_95:
V_58 -> V_2 = NULL ;
return V_19 ;
}
void F_48 ( struct V_57 * V_58 )
{
if ( ! V_58 -> V_2 )
return;
F_34 ( V_58 -> V_50 , V_58 -> V_2 ) ;
}
