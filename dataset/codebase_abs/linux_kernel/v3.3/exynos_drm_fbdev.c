static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_10 * V_11 ;
unsigned int V_12 = V_4 -> V_13 * V_4 -> V_14 * ( V_4 -> V_15 >> 3 ) ;
unsigned long V_16 ;
F_2 ( L_1 , __FILE__ ) ;
F_3 ( V_6 , V_4 -> V_17 [ 0 ] , V_4 -> V_18 ) ;
F_4 ( V_6 , V_2 , V_4 -> V_13 , V_4 -> V_14 ) ;
V_11 = F_5 ( V_4 , 0 ) ;
if ( ! V_11 ) {
F_6 ( L_2 ) ;
return - V_19 ;
}
V_16 = V_6 -> V_20 . V_21 * ( V_4 -> V_15 >> 3 ) ;
V_16 += V_6 -> V_20 . V_22 * V_4 -> V_17 [ 0 ] ;
V_9 -> V_23 . V_24 = ( V_25 ) V_11 -> V_26 ;
V_6 -> V_27 = V_11 -> V_28 + V_16 ;
V_6 -> V_29 . V_30 = ( unsigned long ) ( V_11 -> V_26 + V_16 ) ;
V_6 -> V_31 = V_12 ;
V_6 -> V_29 . V_32 = V_12 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = F_8 ( V_2 ) ;
struct V_37 * V_38 ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_5 * V_6 ;
struct V_39 V_40 = { 0 } ;
struct V_41 * V_42 = V_9 -> V_43 ;
unsigned long V_12 ;
int V_44 ;
F_2 ( L_1 , __FILE__ ) ;
F_2 ( L_3 ,
V_34 -> V_45 , V_34 -> V_46 ,
V_34 -> V_47 ) ;
V_40 . V_13 = V_34 -> V_45 ;
V_40 . V_14 = V_34 -> V_46 ;
V_40 . V_17 [ 0 ] = V_34 -> V_45 * ( V_34 -> V_47 >> 3 ) ;
V_40 . V_48 = F_9 ( V_34 -> V_47 ,
V_34 -> V_49 ) ;
F_10 ( & V_9 -> V_50 ) ;
V_6 = F_11 ( 0 , & V_42 -> V_9 ) ;
if ( ! V_6 ) {
F_12 ( L_4 ) ;
V_44 = - V_51 ;
goto V_52;
}
V_12 = V_40 . V_17 [ 0 ] * V_40 . V_14 ;
V_38 = F_13 ( V_9 , V_12 ) ;
if ( F_14 ( V_38 ) ) {
V_44 = F_15 ( V_38 ) ;
goto V_52;
}
V_36 -> V_38 = V_38 ;
V_2 -> V_4 = F_16 ( V_9 , & V_40 ,
& V_38 -> V_53 ) ;
if ( F_17 ( V_2 -> V_4 ) ) {
F_12 ( L_5 ) ;
V_44 = F_15 ( V_2 -> V_4 ) ;
goto V_52;
}
V_2 -> V_7 = V_6 ;
V_6 -> V_54 = V_2 ;
V_6 -> V_55 = V_56 ;
V_6 -> V_57 = & V_58 ;
V_44 = F_18 ( & V_6 -> V_59 , 256 , 0 ) ;
if ( V_44 ) {
F_12 ( L_6 ) ;
goto V_52;
}
V_44 = F_1 ( V_2 , V_2 -> V_4 ) ;
if ( V_44 < 0 ) {
F_19 ( & V_6 -> V_59 ) ;
goto V_52;
}
V_52:
F_20 ( & V_9 -> V_50 ) ;
return V_44 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_44 = 0 ;
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_2 -> V_4 ) {
V_44 = F_7 ( V_2 , V_34 ) ;
if ( V_44 < 0 ) {
F_12 ( L_7 ) ;
return V_44 ;
}
V_44 = 1 ;
}
return V_44 ;
}
int F_22 ( struct V_8 * V_9 )
{
struct V_35 * V_7 ;
struct V_60 * V_61 = V_9 -> V_62 ;
struct V_1 * V_2 ;
unsigned int V_63 ;
int V_44 ;
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_9 -> V_23 . V_63 || ! V_9 -> V_23 . V_64 )
return 0 ;
V_7 = F_23 ( sizeof( * V_7 ) , V_65 ) ;
if ( ! V_7 ) {
F_12 ( L_8 ) ;
return - V_51 ;
}
V_61 -> V_66 = V_2 = & V_7 -> V_1 ;
V_2 -> V_67 = & V_68 ;
V_63 = V_9 -> V_23 . V_63 ;
V_44 = F_24 ( V_9 , V_2 , V_63 , V_69 ) ;
if ( V_44 < 0 ) {
F_12 ( L_9 ) ;
goto V_70;
}
V_44 = F_25 ( V_2 ) ;
if ( V_44 < 0 ) {
F_12 ( L_10 ) ;
goto V_71;
}
V_44 = F_26 ( V_2 , V_72 ) ;
if ( V_44 < 0 ) {
F_12 ( L_11 ) ;
goto V_71;
}
return 0 ;
V_71:
F_27 ( V_2 ) ;
V_70:
V_61 -> V_66 = NULL ;
F_28 ( V_7 ) ;
return V_44 ;
}
static void F_29 ( struct V_8 * V_9 ,
struct V_1 * V_66 )
{
struct V_3 * V_4 ;
if ( V_66 -> V_4 && V_66 -> V_4 -> V_67 ) {
V_4 = V_66 -> V_4 ;
if ( V_4 && V_4 -> V_67 -> V_73 )
V_4 -> V_67 -> V_73 ( V_4 ) ;
}
if ( V_66 -> V_7 ) {
struct V_5 * V_74 ;
int V_44 ;
V_74 = V_66 -> V_7 ;
V_44 = F_30 ( V_74 ) ;
if ( V_44 < 0 )
F_2 ( L_12 ) ;
if ( V_74 -> V_59 . V_75 )
F_19 ( & V_74 -> V_59 ) ;
F_31 ( V_74 ) ;
}
F_27 ( V_66 ) ;
}
void F_32 ( struct V_8 * V_9 )
{
struct V_60 * V_61 = V_9 -> V_62 ;
struct V_35 * V_7 ;
if ( ! V_61 || ! V_61 -> V_66 )
return;
V_7 = F_8 ( V_61 -> V_66 ) ;
if ( V_7 -> V_38 )
F_33 ( V_7 -> V_38 ) ;
F_29 ( V_9 , V_61 -> V_66 ) ;
F_28 ( V_7 ) ;
V_61 -> V_66 = NULL ;
}
void F_34 ( struct V_8 * V_9 )
{
struct V_60 * V_61 = V_9 -> V_62 ;
if ( ! V_61 || ! V_61 -> V_66 )
return;
F_35 ( V_61 -> V_66 ) ;
}
int F_36 ( struct V_8 * V_9 )
{
struct V_60 * V_61 = V_9 -> V_62 ;
struct V_1 * V_66 ;
int V_44 ;
if ( ! V_61 )
return - V_76 ;
if ( ! V_9 -> V_23 . V_64 ) {
F_32 ( V_9 ) ;
return 0 ;
}
V_66 = V_61 -> V_66 ;
if ( V_66 ) {
struct V_77 V_78 ;
F_37 ( & V_78 ) ;
if ( ! F_38 ( & V_66 -> V_79 ) )
F_39 ( & V_66 -> V_79 ,
& V_78 ) ;
F_27 ( V_66 ) ;
V_44 = F_24 ( V_9 , V_66 ,
V_9 -> V_23 . V_63 , V_69 ) ;
if ( V_44 < 0 ) {
F_12 ( L_13 ) ;
return V_44 ;
}
if ( ! F_38 ( & V_78 ) )
F_40 ( & V_78 , & V_66 -> V_79 ) ;
V_44 = F_25 ( V_66 ) ;
if ( V_44 < 0 ) {
F_12 ( L_14 ) ;
goto V_80;
}
V_44 = F_26 ( V_66 , V_72 ) ;
if ( V_44 < 0 ) {
F_12 ( L_11 ) ;
goto V_80;
}
} else {
V_44 = F_22 ( V_9 ) ;
}
return V_44 ;
V_80:
if ( V_66 )
F_27 ( V_66 ) ;
return V_44 ;
}
