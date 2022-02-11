static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_12 = V_9 -> V_12 ;
unsigned int V_13 ;
if ( V_4 -> V_14 || V_4 -> V_15 ) {
V_13 = V_4 -> V_16 | V_17 ;
if ( V_9 -> type & V_18 )
V_13 |= V_19 ;
V_13 |= V_9 -> V_20 << V_21 ;
} else {
V_13 = 0 ;
}
F_3 ( V_13 , V_12 -> V_22 + F_4 ( V_6 -> V_23 ) ) ;
if ( V_6 -> V_23 == V_24 || V_6 -> V_23 == V_25 ) {
F_3 ( V_13 ,
V_12 -> V_22 + F_4 ( V_24 ) ) ;
F_3 ( V_13 ,
V_12 -> V_22 + F_4 ( V_25 ) ) ;
}
}
static int
F_5 ( struct V_26 * V_6 , struct V_27 * V_28 ,
unsigned long * V_23 , unsigned int * type )
{
struct V_11 * V_12 = V_6 -> V_29 ;
unsigned int V_20 ;
if ( F_6 ( V_28 -> V_30 < 3 ) ) {
F_7 ( V_12 -> V_31 , L_1 ,
V_28 -> V_30 ) ;
return - V_32 ;
}
V_20 = V_28 -> V_33 [ 0 ] ;
if ( V_20 != V_34 && V_20 != V_35 &&
V_20 != V_36 && V_20 != V_37 ) {
F_7 ( V_12 -> V_31 , L_2 , V_20 ) ;
return - V_32 ;
}
* V_23 = V_28 -> V_33 [ 1 ] ;
if ( * V_23 >= V_38 ) {
F_7 ( V_12 -> V_31 , L_3 , * V_23 ) ;
return - V_32 ;
}
* type = V_28 -> V_33 [ 2 ] & V_39 ;
return 0 ;
}
static int
F_8 ( struct V_26 * V_40 , unsigned int V_41 ,
unsigned int V_42 , void * args )
{
int V_43 ;
unsigned long V_23 ;
struct V_27 * V_28 = args ;
struct V_11 * V_12 = F_9 ( V_40 ) ;
struct V_8 * V_9 ;
V_9 = F_10 ( sizeof( * V_9 ) , V_44 ) ;
if ( ! V_9 )
return - V_45 ;
V_43 = F_5 ( V_40 , V_28 , & V_23 ,
& V_9 -> type ) ;
if ( V_43 ) {
F_7 ( V_12 -> V_31 , L_4 ) ;
goto V_46;
}
V_9 -> V_20 = V_28 -> V_33 [ 0 ] ;
V_9 -> V_12 = V_12 ;
V_43 = F_11 ( V_40 , V_41 , V_42 ) ;
if ( V_43 ) {
F_7 ( V_12 -> V_31 , L_5 ) ;
goto V_46;
}
V_43 = F_12 ( V_41 , V_47 , false ) ;
if ( V_43 )
goto V_48;
V_43 = F_13 ( V_40 , V_41 , V_23 ,
& V_12 -> V_49 , V_9 ) ;
if ( V_43 ) {
F_7 ( V_12 -> V_31 , L_6 ) ;
goto V_48;
}
return 0 ;
V_48:
F_14 ( V_40 , V_41 , V_42 ) ;
V_46:
F_15 ( V_9 ) ;
return V_43 ;
}
static void
F_16 ( struct V_26 * V_40 , unsigned int V_41 ,
unsigned int V_42 )
{
struct V_5 * V_6 = F_2 ( V_41 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_15 ( V_9 ) ;
F_14 ( V_40 , V_41 , V_42 ) ;
}
static int F_17 ( struct V_50 * V_51 )
{
struct V_11 * V_12 ;
struct V_52 * V_53 = V_51 -> V_31 . V_54 ;
struct V_52 * V_55 ;
struct V_56 * V_57 ;
T_1 V_58 , V_59 ;
T_2 V_60 , V_13 ;
int V_61 ;
V_12 = F_18 ( & V_51 -> V_31 , sizeof( struct V_11 ) ,
V_44 ) ;
if ( ! V_12 )
return - V_45 ;
V_12 -> V_31 = & V_51 -> V_31 ;
V_57 = F_19 ( V_51 , V_62 , 0 ) ;
V_12 -> V_22 = F_20 ( & V_51 -> V_31 , V_57 ) ;
if ( F_21 ( V_12 -> V_22 ) ) {
F_7 ( & V_51 -> V_31 , L_7 ) ;
return F_22 ( V_12 -> V_22 ) ;
}
V_12 -> V_49 . V_63 = F_23 ( & V_51 -> V_31 , V_44 ,
L_8 ,
( unsigned int ) V_57 -> V_64 ) ;
if ( ! V_12 -> V_49 . V_63 )
return - V_45 ;
V_12 -> V_49 . V_65 = V_66 ;
V_12 -> V_49 . V_67 = V_68 ;
V_12 -> V_49 . V_69 = V_70 ;
V_12 -> V_49 . V_71 = V_72 ;
#ifdef F_24
V_12 -> V_49 . V_73 = V_74 ;
#endif
V_51 -> V_31 . V_75 = F_25 ( & V_51 -> V_31 , V_53 ,
V_76 ) ;
if ( ! V_51 -> V_31 . V_75 )
return - V_77 ;
V_55 = F_26 ( V_51 -> V_31 . V_75 ) ;
if ( ! V_55 )
return - V_78 ;
V_61 = F_27 ( V_55 , & V_58 , & V_59 ) ;
if ( V_61 )
return V_61 ;
F_3 ( F_28 ( V_58 ) , V_12 -> V_22 + V_79 ) ;
F_3 ( F_29 ( V_58 ) , V_12 -> V_22 + V_80 ) ;
F_3 ( F_28 ( V_59 ) , V_12 -> V_22 + V_81 ) ;
F_3 ( F_29 ( V_59 ) , V_12 -> V_22 + V_82 ) ;
for ( V_60 = 0 ; V_60 < V_38 ; V_60 ++ ) {
V_13 = F_30 ( V_12 -> V_22 + F_4 ( V_60 ) ) ;
if ( ( V_13 >> V_21 ) == V_34 )
F_3 ( 0x0 , V_12 -> V_22 + F_4 ( V_60 ) ) ;
}
V_12 -> V_40 =
F_31 ( & V_51 -> V_31 , V_38 ,
F_1 ,
& V_83 , V_12 ) ;
if ( ! V_12 -> V_40 ) {
F_7 ( & V_51 -> V_31 , L_9 ) ;
return - V_45 ;
}
return 0 ;
}
