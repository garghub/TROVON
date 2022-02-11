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
F_7 ( V_4 , 1 ) ;
V_16 = V_6 -> V_20 . V_21 * ( V_4 -> V_15 >> 3 ) ;
V_16 += V_6 -> V_20 . V_22 * V_4 -> V_17 [ 0 ] ;
V_9 -> V_23 . V_24 = ( V_25 ) V_11 -> V_26 ;
V_6 -> V_27 = V_11 -> V_28 + V_16 ;
V_6 -> V_29 . V_30 = ( unsigned long ) ( F_8 ( V_11 -> V_31 [ 0 ] ) +
V_16 ) ;
V_6 -> V_32 = V_12 ;
V_6 -> V_29 . V_33 = V_12 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_36 * V_37 = F_10 ( V_2 ) ;
struct V_38 * V_39 ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_5 * V_6 ;
struct V_40 V_41 = { 0 } ;
struct V_42 * V_43 = V_9 -> V_44 ;
unsigned long V_12 ;
int V_45 ;
F_2 ( L_1 , __FILE__ ) ;
F_2 ( L_3 ,
V_35 -> V_46 , V_35 -> V_47 ,
V_35 -> V_48 ) ;
V_41 . V_13 = V_35 -> V_46 ;
V_41 . V_14 = V_35 -> V_47 ;
V_41 . V_17 [ 0 ] = V_35 -> V_46 * ( V_35 -> V_48 >> 3 ) ;
V_41 . V_49 = F_11 ( V_35 -> V_48 ,
V_35 -> V_50 ) ;
F_12 ( & V_9 -> V_51 ) ;
V_6 = F_13 ( 0 , & V_43 -> V_9 ) ;
if ( ! V_6 ) {
F_14 ( L_4 ) ;
V_45 = - V_52 ;
goto V_53;
}
V_12 = V_41 . V_17 [ 0 ] * V_41 . V_14 ;
V_39 = F_15 ( V_9 , 0 , V_12 ) ;
if ( F_16 ( V_39 ) ) {
V_45 = F_17 ( V_39 ) ;
goto V_53;
}
V_37 -> V_39 = V_39 ;
V_2 -> V_4 = F_18 ( V_9 , & V_41 ,
& V_39 -> V_54 ) ;
if ( F_19 ( V_2 -> V_4 ) ) {
F_14 ( L_5 ) ;
V_45 = F_17 ( V_2 -> V_4 ) ;
goto V_53;
}
V_2 -> V_7 = V_6 ;
V_6 -> V_55 = V_2 ;
V_6 -> V_56 = V_57 ;
V_6 -> V_58 = & V_59 ;
V_45 = F_20 ( & V_6 -> V_60 , 256 , 0 ) ;
if ( V_45 ) {
F_14 ( L_6 ) ;
goto V_53;
}
V_45 = F_1 ( V_2 , V_2 -> V_4 ) ;
if ( V_45 < 0 ) {
F_21 ( & V_6 -> V_60 ) ;
goto V_53;
}
V_53:
F_22 ( & V_9 -> V_51 ) ;
return V_45 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
int V_45 = 0 ;
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_2 -> V_4 ) {
V_45 = F_9 ( V_2 , V_35 ) ;
if ( V_45 < 0 ) {
F_14 ( L_7 ) ;
return V_45 ;
}
V_45 = 1 ;
}
return V_45 ;
}
int F_24 ( struct V_8 * V_9 )
{
struct V_36 * V_7 ;
struct V_61 * V_62 = V_9 -> V_63 ;
struct V_1 * V_2 ;
unsigned int V_64 ;
int V_45 ;
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_9 -> V_23 . V_64 || ! V_9 -> V_23 . V_65 )
return 0 ;
V_7 = F_25 ( sizeof( * V_7 ) , V_66 ) ;
if ( ! V_7 ) {
F_14 ( L_8 ) ;
return - V_52 ;
}
V_62 -> V_67 = V_2 = & V_7 -> V_1 ;
V_2 -> V_68 = & V_69 ;
V_64 = V_9 -> V_23 . V_64 ;
V_45 = F_26 ( V_9 , V_2 , V_64 , V_70 ) ;
if ( V_45 < 0 ) {
F_14 ( L_9 ) ;
goto V_71;
}
V_45 = F_27 ( V_2 ) ;
if ( V_45 < 0 ) {
F_14 ( L_10 ) ;
goto V_72;
}
V_45 = F_28 ( V_2 , V_73 ) ;
if ( V_45 < 0 ) {
F_14 ( L_11 ) ;
goto V_72;
}
return 0 ;
V_72:
F_29 ( V_2 ) ;
V_71:
V_62 -> V_67 = NULL ;
F_30 ( V_7 ) ;
return V_45 ;
}
static void F_31 ( struct V_8 * V_9 ,
struct V_1 * V_67 )
{
struct V_3 * V_4 ;
if ( V_67 -> V_4 && V_67 -> V_4 -> V_68 ) {
V_4 = V_67 -> V_4 ;
if ( V_4 )
F_32 ( V_4 ) ;
}
if ( V_67 -> V_7 ) {
struct V_5 * V_74 ;
int V_45 ;
V_74 = V_67 -> V_7 ;
V_45 = F_33 ( V_74 ) ;
if ( V_45 < 0 )
F_2 ( L_12 ) ;
if ( V_74 -> V_60 . V_75 )
F_21 ( & V_74 -> V_60 ) ;
F_34 ( V_74 ) ;
}
F_29 ( V_67 ) ;
}
void F_35 ( struct V_8 * V_9 )
{
struct V_61 * V_62 = V_9 -> V_63 ;
struct V_36 * V_7 ;
if ( ! V_62 || ! V_62 -> V_67 )
return;
V_7 = F_10 ( V_62 -> V_67 ) ;
if ( V_7 -> V_39 )
F_36 ( V_7 -> V_39 ) ;
F_31 ( V_9 , V_62 -> V_67 ) ;
F_30 ( V_7 ) ;
V_62 -> V_67 = NULL ;
}
void F_37 ( struct V_8 * V_9 )
{
struct V_61 * V_62 = V_9 -> V_63 ;
if ( ! V_62 || ! V_62 -> V_67 )
return;
F_38 ( V_62 -> V_67 ) ;
}
