static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
F_3 ( V_2 , V_6 ,
V_7 ) ;
F_3 ( V_2 , & V_4 -> V_8 ,
V_9 ) ;
}
int F_4 ( struct V_5 * V_6 ,
struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 ;
unsigned int V_18 ;
unsigned int V_19 ;
int V_20 = F_5 ( V_11 -> V_21 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ ) {
V_17 = F_6 ( V_11 , V_22 ) ;
if ( ! V_17 ) {
F_7 ( L_1 ) ;
return - V_23 ;
}
V_6 -> V_24 [ V_22 ] = V_17 -> V_24 ;
V_6 -> V_25 [ V_22 ] = V_17 -> V_26 ;
F_8 ( L_2 ,
V_22 , ( unsigned long ) V_6 -> V_25 [ V_22 ] ,
( unsigned long ) V_6 -> V_24 [ V_22 ] ) ;
}
V_18 = F_9 ( ( V_13 -> V_27 - V_15 -> V_28 ) , V_15 -> V_29 ) ;
V_19 = F_9 ( ( V_13 -> V_30 - V_15 -> V_31 ) , V_15 -> V_32 ) ;
V_6 -> V_33 = V_15 -> V_33 ;
V_6 -> V_34 = V_15 -> V_34 ;
V_6 -> V_35 = V_11 -> V_36 ;
V_6 -> V_37 = V_11 -> V_38 ;
V_6 -> V_39 = V_11 -> V_40 ;
V_6 -> V_41 = V_11 -> V_42 [ 0 ] ;
V_6 -> V_21 = V_11 -> V_21 ;
V_6 -> V_28 = V_15 -> V_28 ;
V_6 -> V_31 = V_15 -> V_31 ;
V_6 -> V_43 = V_18 ;
V_6 -> V_44 = V_19 ;
V_6 -> V_45 = V_13 -> V_27 ;
V_6 -> V_46 = V_13 -> V_30 ;
V_6 -> V_47 = V_13 -> V_48 ;
V_6 -> V_49 = V_13 -> V_50 ;
F_8 ( L_3 ,
V_6 -> V_28 , V_6 -> V_31 ,
V_6 -> V_43 , V_6 -> V_44 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_14 V_15 ;
struct V_12 * V_13 = & V_2 -> V_13 ;
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! V_13 || ! V_11 )
return - V_51 ;
V_4 = F_2 ( V_2 ) ;
V_6 = & V_4 -> V_6 ;
memset ( & V_15 , 0 , sizeof( struct V_14 ) ) ;
V_15 . V_33 = V_2 -> V_52 ;
V_15 . V_34 = V_2 -> V_53 ;
V_15 . V_28 = 0 ;
V_15 . V_31 = 0 ;
V_15 . V_29 = V_11 -> V_36 - V_2 -> V_52 ;
V_15 . V_32 = V_11 -> V_38 - V_2 -> V_53 ;
return F_4 ( V_6 , V_2 -> V_11 , V_13 , & V_15 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_13 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_8 ( L_4 , V_2 -> V_56 . V_57 , V_13 ) ;
if ( V_4 -> V_58 == V_13 ) {
F_8 ( L_5 ) ;
return;
}
F_12 ( & V_55 -> V_59 ) ;
switch ( V_13 ) {
case V_60 :
F_3 ( V_2 , & V_13 ,
V_61 ) ;
V_4 -> V_58 = V_13 ;
break;
case V_62 :
case V_63 :
case V_64 :
F_3 ( V_2 , & V_13 ,
V_61 ) ;
V_4 -> V_58 = V_13 ;
break;
default:
F_13 ( L_6 , V_13 ) ;
break;
}
F_14 ( & V_55 -> V_59 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_8 ( L_7 , __FILE__ ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_8 ( L_7 , __FILE__ ) ;
if ( V_4 -> V_58 != V_60 ) {
int V_13 = V_60 ;
F_11 ( V_2 , V_13 ) ;
F_3 ( V_2 , & V_13 ,
V_65 ) ;
}
F_3 ( V_2 , & V_4 -> V_8 ,
V_9 ) ;
}
static bool
F_17 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_12 * V_66 )
{
F_8 ( L_7 , __FILE__ ) ;
return true ;
}
static int
F_18 ( struct V_1 * V_2 , struct V_12 * V_13 ,
struct V_12 * V_66 , int V_52 , int V_53 ,
struct V_10 * V_67 )
{
F_8 ( L_7 , __FILE__ ) ;
V_13 = V_66 ;
return F_10 ( V_2 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_52 , int V_53 ,
struct V_10 * V_67 )
{
int V_68 ;
F_8 ( L_7 , __FILE__ ) ;
V_68 = F_10 ( V_2 ) ;
if ( V_68 )
return V_68 ;
F_1 ( V_2 ) ;
return V_68 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_8 ( L_7 , __FILE__ ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_69 * V_70 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_71 * V_72 = V_55 -> V_73 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 * V_67 = V_2 -> V_11 ;
int V_68 = - V_51 ;
F_8 ( L_7 , __FILE__ ) ;
F_12 ( & V_55 -> V_59 ) ;
if ( V_70 ) {
V_70 -> V_8 = V_4 -> V_8 ;
V_68 = F_22 ( V_55 , V_4 -> V_8 ) ;
if ( V_68 ) {
F_23 ( L_8 ) ;
F_24 ( & V_70 -> V_56 . V_74 ) ;
goto V_75;
}
F_25 ( & V_70 -> V_56 . V_74 ,
& V_72 -> V_76 ) ;
V_2 -> V_11 = V_11 ;
V_68 = F_10 ( V_2 ) ;
if ( V_68 ) {
V_2 -> V_11 = V_67 ;
F_26 ( V_55 , V_4 -> V_8 ) ;
F_24 ( & V_70 -> V_56 . V_74 ) ;
goto V_75;
}
F_1 ( V_2 ) ;
}
V_75:
F_14 ( & V_55 -> V_59 ) ;
return V_68 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_71 * V_77 = V_2 -> V_55 -> V_73 ;
F_8 ( L_7 , __FILE__ ) ;
V_77 -> V_2 [ V_4 -> V_8 ] = NULL ;
F_28 ( V_2 ) ;
F_29 ( V_4 ) ;
}
struct V_5 * F_30 ( struct V_54 * V_55 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return & V_4 -> V_6 ;
}
int F_31 ( struct V_54 * V_55 , unsigned int V_20 )
{
struct V_3 * V_4 ;
struct V_71 * V_77 = V_55 -> V_73 ;
struct V_1 * V_2 ;
F_8 ( L_7 , __FILE__ ) ;
V_4 = F_32 ( sizeof( * V_4 ) , V_78 ) ;
if ( ! V_4 ) {
F_13 ( L_9 ) ;
return - V_79 ;
}
V_4 -> V_8 = V_20 ;
V_4 -> V_58 = V_64 ;
V_4 -> V_6 . V_80 = V_81 ;
V_2 = & V_4 -> V_1 ;
V_77 -> V_2 [ V_20 ] = V_2 ;
F_33 ( V_55 , V_2 , & V_82 ) ;
F_34 ( V_2 , & V_83 ) ;
return 0 ;
}
int F_35 ( struct V_54 * V_55 , int V_2 )
{
struct V_71 * V_77 = V_55 -> V_73 ;
struct V_3 * V_4 =
F_2 ( V_77 -> V_2 [ V_2 ] ) ;
F_8 ( L_7 , __FILE__ ) ;
if ( V_4 -> V_58 != V_60 )
return - V_84 ;
F_3 ( V_77 -> V_2 [ V_2 ] , & V_2 ,
V_85 ) ;
return 0 ;
}
void F_36 ( struct V_54 * V_55 , int V_2 )
{
struct V_71 * V_77 = V_55 -> V_73 ;
struct V_3 * V_4 =
F_2 ( V_77 -> V_2 [ V_2 ] ) ;
F_8 ( L_7 , __FILE__ ) ;
if ( V_4 -> V_58 != V_60 )
return;
F_3 ( V_77 -> V_2 [ V_2 ] , & V_2 ,
V_86 ) ;
}
