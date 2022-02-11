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
static inline struct V_1 * F_8 ( struct V_10 * V_11 )
{
return F_9 ( V_11 , struct V_1 , V_12 ) ;
}
static int F_10 ( struct V_10 * V_11 , unsigned V_13 )
{
struct V_1 * V_1 = F_8 ( V_11 ) ;
int V_6 = F_11 ( V_13 ) ;
int V_5 = V_14 << V_13 ;
F_5 ( V_1 , V_15 , V_6 , V_5 ) ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 , unsigned V_13 )
{
struct V_1 * V_1 = F_8 ( V_11 ) ;
int V_5 ;
V_5 = F_1 ( V_1 , V_16 ) ;
if ( V_5 & F_11 ( V_13 ) )
return 1 ;
else
return 0 ;
}
static void F_13 ( struct V_10 * V_11 , unsigned V_13 , int V_17 )
{
struct V_1 * V_1 = F_8 ( V_11 ) ;
int V_6 = F_11 ( V_13 ) ;
int V_5 = V_17 << V_13 ;
F_5 ( V_1 , V_16 , V_6 , V_5 ) ;
}
static int F_14 ( struct V_10 * V_11 ,
unsigned V_13 , int V_17 )
{
struct V_1 * V_1 = F_8 ( V_11 ) ;
int V_6 = F_11 ( V_13 ) ;
int V_5 = V_18 << V_13 ;
F_13 ( V_11 , V_13 , V_17 ) ;
F_5 ( V_1 , V_15 , V_6 , V_5 ) ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 , unsigned V_13 )
{
return F_16 ( V_11 -> V_4 + V_13 ) ;
}
static void F_17 ( struct V_10 * V_11 , unsigned V_13 )
{
F_18 ( V_11 -> V_4 + V_13 ) ;
}
static int F_19 ( struct V_10 * V_11 , unsigned V_13 )
{
struct V_1 * V_1 = F_8 ( V_11 ) ;
return F_20 ( V_1 -> V_19 , V_13 ) ;
}
static int F_21 ( struct V_20 * V_21 , unsigned int type )
{
if ( ( type & V_22 ) != V_23 ) {
F_22 ( L_1 ) ;
return - V_24 ;
}
F_23 ( V_21 , type ) ;
return V_25 ;
}
static T_2 F_24 ( int V_26 , void * V_21 )
{
struct V_1 * V_1 = V_21 ;
T_1 V_7 = F_1 ( V_1 , V_27 ) ;
T_1 V_28 = F_1 ( V_1 , V_29 ) ;
const unsigned long V_30 = V_7 & V_28 ;
int V_31 ;
F_25 (i, &bits, 32 )
F_26 ( F_27 ( V_1 -> V_19 , V_31 ) ) ;
return V_32 ;
}
static int F_28 ( struct V_33 * V_34 )
{
struct V_1 * V_1 ;
struct V_35 * V_36 ;
struct V_37 * V_38 = V_34 -> V_39 . V_40 ;
int V_41 = - V_42 ;
T_1 V_43 ;
if ( ! V_38 )
return - V_24 ;
if ( F_29 ( V_38 , L_2 , & V_43 ) )
return - V_24 ;
V_1 = F_30 ( & V_34 -> V_39 , sizeof( * V_1 ) , V_44 ) ;
if ( V_1 == NULL )
return - V_45 ;
F_31 ( & V_1 -> V_9 ) ;
V_36 = F_32 ( V_34 , V_46 , 0 ) ;
V_1 -> V_4 = F_33 ( & V_34 -> V_39 , V_36 ) ;
if ( F_34 ( V_1 -> V_4 ) )
return F_35 ( V_1 -> V_4 ) ;
V_1 -> V_12 . V_47 = F_36 ( V_38 ) ;
V_1 -> V_12 . V_39 = & V_34 -> V_39 ;
V_1 -> V_12 . V_48 = V_49 ;
V_1 -> V_12 . V_50 = F_10 ;
V_1 -> V_12 . V_51 = F_12 ;
V_1 -> V_12 . V_52 = F_14 ;
V_1 -> V_12 . V_53 = F_13 ;
V_1 -> V_12 . V_54 = F_15 ;
V_1 -> V_12 . free = F_17 ;
V_1 -> V_12 . V_4 = - 1 ;
V_1 -> V_12 . V_43 = V_43 ;
V_1 -> V_12 . V_55 = false ;
V_41 = F_37 ( & V_1 -> V_12 ) ;
if ( V_41 < 0 ) {
F_38 ( & V_34 -> V_39 , L_3 ) ;
goto V_56;
}
F_39 ( V_34 , V_1 ) ;
if ( F_40 ( V_38 , L_4 , NULL ) ) {
struct V_57 * V_12 ;
V_41 = F_41 ( V_34 , 0 ) ;
if ( V_41 < 0 ) {
F_38 ( & V_34 -> V_39 , L_5 ) ;
goto V_58;
}
V_1 -> V_12 . V_59 = F_19 ;
V_1 -> V_26 = V_41 ;
V_41 = F_42 ( & V_34 -> V_39 , V_41 , F_24 ,
V_60 | V_61 ,
F_43 ( & V_34 -> V_39 ) , V_1 ) ;
if ( V_41 != 0 )
goto V_62;
V_1 -> V_19 = F_44 ( V_38 ,
V_1 -> V_12 . V_43 ,
& V_63 , NULL ) ;
if ( ! V_1 -> V_19 ) {
V_41 = - V_45 ;
goto V_64;
}
V_41 = F_45 ( V_1 -> V_19 ,
V_1 -> V_12 . V_43 , 1 , V_1 -> V_12 . V_47 ,
V_65 , V_66 , V_67 ,
V_68 ) ;
if ( V_41 )
goto V_64;
V_12 = V_1 -> V_19 -> V_12 -> V_12 [ 0 ] ;
V_12 -> V_69 = V_1 -> V_4 ;
V_12 -> V_70 [ 0 ] . type = V_23 ;
V_12 -> V_70 [ 0 ] . V_11 . V_71 = V_72 ;
V_12 -> V_70 [ 0 ] . V_11 . V_73 = V_74 ;
V_12 -> V_70 [ 0 ] . V_11 . V_75 = V_76 ;
V_12 -> V_70 [ 0 ] . V_11 . V_77 = F_21 ;
V_12 -> V_70 [ 0 ] . V_78 . V_79 = V_27 ;
V_12 -> V_70 [ 0 ] . V_78 . V_6 = V_29 ;
}
return 0 ;
V_64:
V_62:
V_58:
F_46 ( & V_1 -> V_12 ) ;
V_56:
V_80:
return V_41 ;
}
static int F_47 ( struct V_33 * V_34 )
{
struct V_1 * V_1 = F_48 ( V_34 ) ;
if ( V_1 -> V_12 . V_59 ) {
F_49 ( V_1 -> V_19 -> V_12 -> V_12 [ 0 ] ,
F_11 ( V_1 -> V_12 . V_43 ) - 1 , 0 , 0 ) ;
F_50 ( V_1 -> V_19 -> V_12 ) ;
F_51 ( V_1 -> V_19 ) ;
F_52 ( V_1 -> V_26 , V_1 ) ;
}
F_46 ( & V_1 -> V_12 ) ;
return 0 ;
}
