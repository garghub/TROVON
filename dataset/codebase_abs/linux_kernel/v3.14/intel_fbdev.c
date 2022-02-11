static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 V_10 = {} ;
struct V_11 * V_12 ;
int V_13 , V_14 ;
if ( V_4 -> V_15 == 24 )
V_4 -> V_15 = 32 ;
V_10 . V_16 = V_4 -> V_17 ;
V_10 . V_18 = V_4 -> V_19 ;
V_10 . V_20 [ 0 ] = F_3 ( V_10 . V_16 *
F_4 ( V_4 -> V_15 , 8 ) , 64 ) ;
V_10 . V_21 = F_5 ( V_4 -> V_15 ,
V_4 -> V_22 ) ;
V_13 = V_10 . V_20 [ 0 ] * V_10 . V_18 ;
V_13 = F_3 ( V_13 , V_23 ) ;
V_12 = F_6 ( V_8 , V_13 ) ;
if ( V_12 == NULL )
V_12 = F_7 ( V_8 , V_13 ) ;
if ( ! V_12 ) {
F_8 ( L_1 ) ;
V_14 = - V_24 ;
goto V_25;
}
V_14 = F_9 ( V_8 , V_12 , NULL ) ;
if ( V_14 ) {
F_8 ( L_2 , V_14 ) ;
goto V_26;
}
V_14 = F_10 ( V_8 , & V_6 -> V_27 , & V_10 , V_12 ) ;
if ( V_14 )
goto V_28;
return 0 ;
V_28:
F_11 ( V_12 ) ;
V_26:
F_12 ( & V_12 -> V_29 ) ;
V_25:
return V_14 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_30 * V_31 = & V_6 -> V_27 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_32 * V_33 = V_8 -> V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
struct V_11 * V_12 ;
int V_13 , V_14 ;
F_14 ( & V_8 -> V_39 ) ;
if ( ! V_31 -> V_12 ) {
F_15 ( L_3 ) ;
V_14 = F_1 ( V_2 , V_4 ) ;
if ( V_14 )
goto V_40;
} else {
F_15 ( L_4 ) ;
V_4 -> V_41 = V_31 -> V_29 . V_16 ;
V_4 -> V_42 = V_31 -> V_29 . V_18 ;
}
V_12 = V_31 -> V_12 ;
V_13 = V_12 -> V_29 . V_13 ;
V_36 = F_16 ( 0 , & V_8 -> V_43 -> V_8 ) ;
if ( ! V_36 ) {
V_14 = - V_24 ;
goto V_28;
}
V_36 -> V_44 = V_2 ;
V_38 = & V_6 -> V_27 . V_29 ;
V_6 -> V_2 . V_38 = V_38 ;
V_6 -> V_2 . V_45 = V_36 ;
strcpy ( V_36 -> V_46 . V_47 , L_5 ) ;
V_36 -> V_48 = V_49 | V_50 ;
V_36 -> V_51 = & V_52 ;
V_14 = F_17 ( & V_36 -> V_53 , 256 , 0 ) ;
if ( V_14 ) {
V_14 = - V_24 ;
goto V_28;
}
V_36 -> V_54 = F_18 ( 1 ) ;
if ( ! V_36 -> V_54 ) {
V_14 = - V_24 ;
goto V_28;
}
V_36 -> V_54 -> V_55 [ 0 ] . V_29 = V_8 -> V_56 . V_57 ;
V_36 -> V_54 -> V_55 [ 0 ] . V_13 = V_33 -> V_58 . V_59 ;
V_36 -> V_46 . V_60 = V_8 -> V_56 . V_57 + F_19 ( V_12 ) ;
V_36 -> V_46 . V_61 = V_13 ;
V_36 -> V_62 =
F_20 ( V_33 -> V_58 . V_63 + F_19 ( V_12 ) ,
V_13 ) ;
if ( ! V_36 -> V_62 ) {
V_14 = - V_64 ;
goto V_28;
}
V_36 -> V_65 = V_13 ;
V_36 -> V_66 = true ;
F_21 ( V_36 , V_38 -> V_20 [ 0 ] , V_38 -> V_67 ) ;
F_22 ( V_36 , & V_6 -> V_2 , V_4 -> V_41 , V_4 -> V_42 ) ;
if ( V_6 -> V_27 . V_12 -> V_68 )
F_23 ( V_36 -> V_62 , 0 , V_36 -> V_65 ) ;
F_15 ( L_6 ,
V_38 -> V_16 , V_38 -> V_18 ,
F_19 ( V_12 ) , V_12 ) ;
F_24 ( & V_8 -> V_39 ) ;
F_25 ( V_8 -> V_43 , V_36 ) ;
return 0 ;
V_28:
F_11 ( V_12 ) ;
F_12 ( & V_12 -> V_29 ) ;
V_40:
F_24 ( & V_8 -> V_39 ) ;
return V_14 ;
}
static void F_26 ( struct V_69 * V_70 , T_1 V_71 , T_1 V_72 ,
T_1 V_73 , int V_74 )
{
struct V_75 * V_75 = F_27 ( V_70 ) ;
V_75 -> V_76 [ V_74 ] = V_71 >> 8 ;
V_75 -> V_77 [ V_74 ] = V_72 >> 8 ;
V_75 -> V_78 [ V_74 ] = V_73 >> 8 ;
}
static void F_28 ( struct V_69 * V_70 , T_1 * V_71 , T_1 * V_72 ,
T_1 * V_73 , int V_74 )
{
struct V_75 * V_75 = F_27 ( V_70 ) ;
* V_71 = V_75 -> V_76 [ V_74 ] << 8 ;
* V_72 = V_75 -> V_77 [ V_74 ] << 8 ;
* V_73 = V_75 -> V_78 [ V_74 ] << 8 ;
}
static void F_29 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
if ( V_6 -> V_2 . V_45 ) {
struct V_35 * V_36 = V_6 -> V_2 . V_45 ;
F_30 ( V_36 ) ;
F_31 ( V_36 -> V_62 ) ;
if ( V_36 -> V_53 . V_79 )
F_32 ( & V_36 -> V_53 ) ;
F_33 ( V_36 ) ;
}
F_34 ( & V_6 -> V_2 ) ;
F_35 ( & V_6 -> V_27 . V_29 ) ;
F_36 ( & V_6 -> V_27 ) ;
}
int F_37 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
struct V_32 * V_33 = V_8 -> V_34 ;
int V_14 ;
V_6 = F_38 ( sizeof( * V_6 ) , V_80 ) ;
if ( ! V_6 )
return - V_24 ;
V_33 -> V_45 = V_6 ;
V_6 -> V_2 . V_81 = & V_82 ;
V_14 = F_39 ( V_8 , & V_6 -> V_2 ,
F_40 ( V_8 ) -> V_83 ,
4 ) ;
if ( V_14 ) {
F_41 ( V_6 ) ;
return V_14 ;
}
F_42 ( & V_6 -> V_2 ) ;
return 0 ;
}
void F_43 ( struct V_7 * V_8 )
{
struct V_32 * V_33 = V_8 -> V_34 ;
F_44 ( & V_33 -> V_45 -> V_2 , 32 ) ;
}
void F_45 ( struct V_7 * V_8 )
{
struct V_32 * V_33 = V_8 -> V_34 ;
if ( ! V_33 -> V_45 )
return;
F_29 ( V_8 , V_33 -> V_45 ) ;
F_41 ( V_33 -> V_45 ) ;
V_33 -> V_45 = NULL ;
}
void F_46 ( struct V_7 * V_8 , int V_84 )
{
struct V_32 * V_33 = V_8 -> V_34 ;
struct V_5 * V_6 = V_33 -> V_45 ;
struct V_35 * V_36 ;
if ( ! V_6 )
return;
V_36 = V_6 -> V_2 . V_45 ;
if ( V_84 == V_85 && V_6 -> V_27 . V_12 -> V_68 )
F_23 ( V_36 -> V_62 , 0 , V_36 -> V_65 ) ;
F_47 ( V_36 , V_84 ) ;
}
void F_48 ( struct V_7 * V_8 )
{
struct V_32 * V_33 = V_8 -> V_34 ;
F_49 ( & V_33 -> V_45 -> V_2 ) ;
}
void F_50 ( struct V_7 * V_8 )
{
int V_14 ;
struct V_32 * V_33 = V_8 -> V_34 ;
if ( F_40 ( V_8 ) -> V_83 == 0 )
return;
F_51 ( V_8 ) ;
V_14 = F_52 ( & V_33 -> V_45 -> V_2 ) ;
if ( V_14 )
F_53 ( L_7 ) ;
F_54 ( V_8 ) ;
}
