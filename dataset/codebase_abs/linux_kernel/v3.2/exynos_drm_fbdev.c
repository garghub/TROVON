static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
switch ( V_4 -> V_5 ) {
case 32 :
case 24 :
case 18 :
case 16 :
case 12 :
V_2 -> V_6 . V_7 = V_8 ;
break;
case 1 :
V_2 -> V_6 . V_7 = V_9 ;
break;
default:
V_2 -> V_6 . V_7 = V_10 ;
break;
}
V_2 -> V_6 . V_11 = ( V_4 -> V_12 * V_4 -> V_5 ) / 8 ;
return F_2 ( V_2 ) ;
}
static int F_3 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_17 = V_14 -> V_18 ;
struct V_19 * V_20 = V_14 -> V_20 ;
struct V_21 * V_22 = F_4 ( V_14 ) ;
struct V_23 * V_24 ;
unsigned int V_25 = V_16 -> V_26 * V_16 -> V_27 * ( V_16 -> V_5 >> 3 ) ;
unsigned long V_28 ;
F_5 ( L_1 , __FILE__ ) ;
V_22 -> V_16 = V_16 ;
F_6 ( V_17 , V_16 -> V_29 , V_16 -> V_30 ) ;
F_7 ( V_17 , V_14 , V_16 -> V_26 , V_16 -> V_27 ) ;
V_24 = F_8 ( V_16 ) ;
if ( ! V_24 ) {
F_9 ( L_2 ) ;
return - V_31 ;
}
V_28 = V_17 -> V_4 . V_32 * ( V_16 -> V_5 >> 3 ) ;
V_28 += V_17 -> V_4 . V_33 * V_16 -> V_29 ;
V_20 -> V_34 . V_35 = ( V_36 ) V_24 -> V_37 ;
V_17 -> V_38 = V_24 -> V_39 + V_28 ;
V_17 -> V_6 . V_40 = ( unsigned long ) ( V_24 -> V_37 + V_28 ) ;
V_17 -> V_41 = V_25 ;
V_17 -> V_6 . V_42 = V_25 ;
return 0 ;
}
static int F_10 ( struct V_13 * V_14 ,
struct V_43 * V_44 )
{
struct V_21 * V_45 = F_4 ( V_14 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
struct V_1 * V_17 ;
struct V_46 V_47 = { 0 } ;
struct V_48 * V_49 = V_20 -> V_50 ;
int V_51 ;
F_5 ( L_1 , __FILE__ ) ;
F_5 ( L_3 ,
V_44 -> V_52 , V_44 -> V_53 ,
V_44 -> V_54 ) ;
V_47 . V_26 = V_44 -> V_52 ;
V_47 . V_27 = V_44 -> V_53 ;
V_47 . V_55 = V_44 -> V_54 ;
V_47 . V_30 = V_44 -> V_56 ;
F_11 ( & V_20 -> V_57 ) ;
V_17 = F_12 ( 0 , & V_49 -> V_20 ) ;
if ( ! V_17 ) {
F_13 ( L_4 ) ;
V_51 = - V_58 ;
goto V_59;
}
V_45 -> V_16 = F_14 ( V_20 , NULL , & V_47 ) ;
if ( F_15 ( V_45 -> V_16 ) ) {
F_13 ( L_5 ) ;
V_51 = F_16 ( V_45 -> V_16 ) ;
goto V_59;
}
V_14 -> V_16 = V_45 -> V_16 ;
V_14 -> V_18 = V_17 ;
V_17 -> V_60 = V_14 ;
V_17 -> V_61 = V_62 ;
V_17 -> V_63 = & V_64 ;
V_51 = F_17 ( & V_17 -> V_65 , 256 , 0 ) ;
if ( V_51 ) {
F_13 ( L_6 ) ;
goto V_59;
}
V_51 = F_3 ( V_14 , V_14 -> V_16 ) ;
if ( V_51 < 0 )
F_18 ( & V_17 -> V_65 ) ;
V_59:
F_19 ( & V_20 -> V_57 ) ;
return V_51 ;
}
static bool
F_20 ( struct V_15 * V_16 ,
struct V_43 * V_44 )
{
if ( V_16 -> V_26 != V_44 -> V_52 )
return false ;
if ( V_16 -> V_27 != V_44 -> V_53 )
return false ;
if ( V_16 -> V_5 != V_44 -> V_54 )
return false ;
if ( V_16 -> V_30 != V_44 -> V_56 )
return false ;
return true ;
}
static int F_21 ( struct V_13 * V_14 ,
struct V_43 * V_44 )
{
struct V_19 * V_20 = V_14 -> V_20 ;
struct V_21 * V_45 = F_4 ( V_14 ) ;
struct V_15 * V_16 = V_45 -> V_16 ;
struct V_46 V_47 = { 0 } ;
F_5 ( L_1 , __FILE__ ) ;
if ( V_14 -> V_16 != V_16 ) {
F_13 ( L_7 ) ;
return - V_66 ;
}
if ( F_20 ( V_16 , V_44 ) )
return 0 ;
V_47 . V_26 = V_44 -> V_52 ;
V_47 . V_27 = V_44 -> V_53 ;
V_47 . V_55 = V_44 -> V_54 ;
V_47 . V_30 = V_44 -> V_56 ;
if ( V_16 -> V_67 -> V_68 )
V_16 -> V_67 -> V_68 ( V_16 ) ;
V_45 -> V_16 = F_14 ( V_20 , NULL , & V_47 ) ;
if ( F_22 ( V_45 -> V_16 ) ) {
F_13 ( L_8 ) ;
return F_16 ( V_45 -> V_16 ) ;
}
V_14 -> V_16 = V_45 -> V_16 ;
return F_3 ( V_14 , V_14 -> V_16 ) ;
}
static int F_23 ( struct V_13 * V_14 ,
struct V_43 * V_44 )
{
int V_51 = 0 ;
F_5 ( L_1 , __FILE__ ) ;
if ( ! V_14 -> V_16 ) {
V_51 = F_10 ( V_14 , V_44 ) ;
if ( V_51 < 0 ) {
F_13 ( L_9 ) ;
return V_51 ;
}
V_51 = 1 ;
} else {
V_51 = F_21 ( V_14 , V_44 ) ;
if ( V_51 < 0 ) {
F_13 ( L_10 ) ;
return V_51 ;
}
}
return V_51 ;
}
int F_24 ( struct V_19 * V_20 )
{
struct V_21 * V_18 ;
struct V_69 * V_70 = V_20 -> V_71 ;
struct V_13 * V_14 ;
unsigned int V_72 ;
int V_51 ;
F_5 ( L_1 , __FILE__ ) ;
if ( ! V_20 -> V_34 . V_72 || ! V_20 -> V_34 . V_73 )
return 0 ;
V_18 = F_25 ( sizeof( * V_18 ) , V_74 ) ;
if ( ! V_18 ) {
F_13 ( L_11 ) ;
return - V_58 ;
}
V_70 -> V_75 = V_14 = & V_18 -> V_13 ;
V_14 -> V_67 = & V_76 ;
V_72 = V_20 -> V_34 . V_72 ;
V_51 = F_26 ( V_20 , V_14 , V_72 , V_77 ) ;
if ( V_51 < 0 ) {
F_13 ( L_12 ) ;
goto V_78;
}
V_51 = F_27 ( V_14 ) ;
if ( V_51 < 0 ) {
F_13 ( L_13 ) ;
goto V_79;
}
V_51 = F_28 ( V_14 , V_80 ) ;
if ( V_51 < 0 ) {
F_13 ( L_14 ) ;
goto V_79;
}
return 0 ;
V_79:
F_29 ( V_14 ) ;
V_78:
V_70 -> V_75 = NULL ;
F_30 ( V_18 ) ;
return V_51 ;
}
static void F_31 ( struct V_19 * V_20 ,
struct V_13 * V_75 )
{
struct V_15 * V_16 ;
if ( V_75 -> V_16 && V_75 -> V_16 -> V_67 ) {
V_16 = V_75 -> V_16 ;
if ( V_16 && V_16 -> V_67 -> V_68 )
V_16 -> V_67 -> V_68 ( V_16 ) ;
}
if ( V_75 -> V_18 ) {
struct V_1 * V_2 ;
int V_51 ;
V_2 = V_75 -> V_18 ;
V_51 = F_32 ( V_2 ) ;
if ( V_51 < 0 )
F_5 ( L_15 ) ;
if ( V_2 -> V_65 . V_81 )
F_18 ( & V_2 -> V_65 ) ;
F_33 ( V_2 ) ;
}
F_29 ( V_75 ) ;
}
void F_34 ( struct V_19 * V_20 )
{
struct V_69 * V_70 = V_20 -> V_71 ;
struct V_21 * V_18 ;
if ( ! V_70 || ! V_70 -> V_75 )
return;
V_18 = F_4 ( V_70 -> V_75 ) ;
F_31 ( V_20 , V_70 -> V_75 ) ;
F_30 ( V_18 ) ;
V_70 -> V_75 = NULL ;
}
void F_35 ( struct V_19 * V_20 )
{
struct V_69 * V_70 = V_20 -> V_71 ;
if ( ! V_70 || ! V_70 -> V_75 )
return;
F_36 ( V_70 -> V_75 ) ;
}
int F_37 ( struct V_19 * V_20 )
{
struct V_69 * V_70 = V_20 -> V_71 ;
struct V_13 * V_75 ;
int V_51 ;
if ( ! V_70 )
return - V_66 ;
if ( ! V_20 -> V_34 . V_73 ) {
F_34 ( V_20 ) ;
return 0 ;
}
V_75 = V_70 -> V_75 ;
if ( V_75 ) {
struct V_82 V_83 ;
F_38 ( & V_83 ) ;
if ( ! F_39 ( & V_75 -> V_84 ) )
F_40 ( & V_75 -> V_84 ,
& V_83 ) ;
F_29 ( V_75 ) ;
V_51 = F_26 ( V_20 , V_75 ,
V_20 -> V_34 . V_72 , V_77 ) ;
if ( V_51 < 0 ) {
F_13 ( L_16 ) ;
return V_51 ;
}
if ( ! F_39 ( & V_83 ) )
F_41 ( & V_83 , & V_75 -> V_84 ) ;
V_51 = F_27 ( V_75 ) ;
if ( V_51 < 0 ) {
F_13 ( L_17 ) ;
goto V_85;
}
V_51 = F_28 ( V_75 , V_80 ) ;
if ( V_51 < 0 ) {
F_13 ( L_14 ) ;
goto V_85;
}
} else {
V_51 = F_24 ( V_20 ) ;
}
return V_51 ;
V_85:
if ( V_75 )
F_29 ( V_75 ) ;
return V_51 ;
}
