static inline T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_6 , T_1 V_5 )
{
T_1 V_7 ;
unsigned long V_8 ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
V_7 = F_1 ( V_2 , V_3 ) ;
V_7 = ( V_7 & ~ V_6 ) | ( V_5 & V_6 ) ;
F_3 ( V_2 , V_3 , V_7 ) ;
F_7 ( & V_2 -> V_9 , V_8 ) ;
}
static int F_8 ( struct V_10 * V_11 , unsigned V_12 )
{
struct V_1 * V_1 = F_9 ( V_11 ) ;
int V_6 = F_10 ( V_12 ) ;
int V_5 = V_13 << V_12 ;
F_5 ( V_1 , V_14 , V_6 , V_5 ) ;
return 0 ;
}
static int F_11 ( struct V_10 * V_11 , unsigned V_12 )
{
struct V_1 * V_1 = F_9 ( V_11 ) ;
int V_5 ;
V_5 = F_1 ( V_1 , V_15 ) ;
if ( V_5 & F_10 ( V_12 ) )
return 1 ;
else
return 0 ;
}
static void F_12 ( struct V_10 * V_11 , unsigned V_12 , int V_16 )
{
struct V_1 * V_1 = F_9 ( V_11 ) ;
int V_6 = F_10 ( V_12 ) ;
int V_5 = V_16 << V_12 ;
F_5 ( V_1 , V_15 , V_6 , V_5 ) ;
}
static int F_13 ( struct V_10 * V_11 ,
unsigned V_12 , int V_16 )
{
struct V_1 * V_1 = F_9 ( V_11 ) ;
int V_6 = F_10 ( V_12 ) ;
int V_5 = V_17 << V_12 ;
F_12 ( V_11 , V_12 , V_16 ) ;
F_5 ( V_1 , V_14 , V_6 , V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_10 * V_11 , unsigned V_12 )
{
struct V_1 * V_1 = F_9 ( V_11 ) ;
return F_15 ( V_1 -> V_18 , V_12 ) ;
}
static int F_16 ( struct V_19 * V_20 , unsigned int type )
{
if ( ( type & V_21 ) != V_22 ) {
F_17 ( L_1 ) ;
return - V_23 ;
}
F_18 ( V_20 , type ) ;
return V_24 ;
}
static T_2 F_19 ( int V_25 , void * V_20 )
{
struct V_1 * V_1 = V_20 ;
T_1 V_7 = F_1 ( V_1 , V_26 ) ;
T_1 V_27 = F_1 ( V_1 , V_28 ) ;
const unsigned long V_29 = V_7 & V_27 ;
int V_30 ;
F_20 (i, &bits, 32 )
F_21 ( F_22 ( V_1 -> V_18 , V_30 ) ) ;
return V_31 ;
}
static int F_23 ( struct V_32 * V_33 )
{
struct V_1 * V_1 ;
struct V_34 * V_35 ;
struct V_36 * V_37 = V_33 -> V_38 . V_39 ;
int V_40 = - V_41 ;
T_1 V_42 ;
if ( ! V_37 )
return - V_23 ;
if ( F_24 ( V_37 , L_2 , & V_42 ) )
return - V_23 ;
V_1 = F_25 ( & V_33 -> V_38 , sizeof( * V_1 ) , V_43 ) ;
if ( V_1 == NULL )
return - V_44 ;
F_26 ( & V_1 -> V_9 ) ;
V_35 = F_27 ( V_33 , V_45 , 0 ) ;
V_1 -> V_4 = F_28 ( & V_33 -> V_38 , V_35 ) ;
if ( F_29 ( V_1 -> V_4 ) )
return F_30 ( V_1 -> V_4 ) ;
V_1 -> V_46 . V_47 = F_31 ( V_37 ) ;
V_1 -> V_46 . V_48 = & V_33 -> V_38 ;
V_1 -> V_46 . V_49 = V_50 ;
V_1 -> V_46 . V_51 = F_8 ;
V_1 -> V_46 . V_52 = F_11 ;
V_1 -> V_46 . V_53 = F_13 ;
V_1 -> V_46 . V_54 = F_12 ;
V_1 -> V_46 . V_55 = V_56 ;
V_1 -> V_46 . free = V_57 ;
V_1 -> V_46 . V_4 = - 1 ;
V_1 -> V_46 . V_42 = V_42 ;
V_1 -> V_46 . V_58 = false ;
V_40 = F_32 ( & V_1 -> V_46 , V_1 ) ;
if ( V_40 < 0 ) {
F_33 ( & V_33 -> V_38 , L_3 ) ;
goto V_59;
}
F_34 ( V_33 , V_1 ) ;
if ( F_35 ( V_37 , L_4 , NULL ) ) {
struct V_60 * V_46 ;
V_40 = F_36 ( V_33 , 0 ) ;
if ( V_40 < 0 ) {
F_33 ( & V_33 -> V_38 , L_5 ) ;
goto V_61;
}
V_1 -> V_46 . V_62 = F_14 ;
V_1 -> V_25 = V_40 ;
V_40 = F_37 ( & V_33 -> V_38 , V_40 , F_19 ,
V_63 | V_64 ,
F_38 ( & V_33 -> V_38 ) , V_1 ) ;
if ( V_40 != 0 )
goto V_65;
V_1 -> V_18 = F_39 ( V_37 ,
V_1 -> V_46 . V_42 ,
& V_66 , NULL ) ;
if ( ! V_1 -> V_18 ) {
V_40 = - V_44 ;
goto V_67;
}
V_40 = F_40 ( V_1 -> V_18 ,
V_1 -> V_46 . V_42 , 1 , V_1 -> V_46 . V_47 ,
V_68 , V_69 , V_70 ,
V_71 ) ;
if ( V_40 )
goto V_67;
V_46 = V_1 -> V_18 -> V_46 -> V_46 [ 0 ] ;
V_46 -> V_72 = V_1 -> V_4 ;
V_46 -> V_73 [ 0 ] . type = V_22 ;
V_46 -> V_73 [ 0 ] . V_11 . V_74 = V_75 ;
V_46 -> V_73 [ 0 ] . V_11 . V_76 = V_77 ;
V_46 -> V_73 [ 0 ] . V_11 . V_78 = V_79 ;
V_46 -> V_73 [ 0 ] . V_11 . V_80 = F_16 ;
V_46 -> V_73 [ 0 ] . V_81 . V_82 = V_26 ;
V_46 -> V_73 [ 0 ] . V_81 . V_6 = V_28 ;
}
return 0 ;
V_67:
V_65:
V_61:
F_41 ( & V_1 -> V_46 ) ;
V_59:
V_83:
return V_40 ;
}
static int F_42 ( struct V_32 * V_33 )
{
struct V_1 * V_1 = F_43 ( V_33 ) ;
if ( V_1 -> V_46 . V_62 ) {
F_44 ( V_1 -> V_18 -> V_46 -> V_46 [ 0 ] ,
F_10 ( V_1 -> V_46 . V_42 ) - 1 , 0 , 0 ) ;
F_45 ( V_1 -> V_18 -> V_46 ) ;
F_46 ( V_1 -> V_18 ) ;
}
F_41 ( & V_1 -> V_46 ) ;
return 0 ;
}
