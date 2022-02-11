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
V_17 = F_5 ( V_11 ) ;
if ( ! V_17 ) {
F_6 ( L_1 ) ;
return - V_20 ;
}
V_6 -> V_21 = V_17 -> V_21 ;
V_6 -> V_22 = V_17 -> V_23 ;
F_7 ( L_2 ,
( unsigned long ) V_6 -> V_22 ,
( unsigned long ) V_6 -> V_21 ) ;
V_18 = F_8 ( ( V_13 -> V_24 - V_15 -> V_25 ) , V_15 -> V_26 ) ;
V_19 = F_8 ( ( V_13 -> V_27 - V_15 -> V_28 ) , V_15 -> V_29 ) ;
V_6 -> V_30 = V_15 -> V_30 ;
V_6 -> V_31 = V_15 -> V_31 ;
V_6 -> V_32 = V_11 -> V_33 ;
V_6 -> V_34 = V_11 -> V_35 ;
V_6 -> V_36 = V_11 -> V_37 ;
V_6 -> V_38 = V_11 -> V_38 ;
V_6 -> V_25 = V_15 -> V_25 ;
V_6 -> V_28 = V_15 -> V_28 ;
V_6 -> V_39 = V_18 ;
V_6 -> V_40 = V_19 ;
V_6 -> V_41 = V_13 -> V_24 ;
V_6 -> V_42 = V_13 -> V_27 ;
V_6 -> V_43 = V_13 -> V_44 ;
V_6 -> V_45 = V_13 -> V_46 ;
F_7 ( L_3 ,
V_6 -> V_25 , V_6 -> V_28 ,
V_6 -> V_39 , V_6 -> V_40 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_14 V_15 ;
struct V_12 * V_13 = & V_2 -> V_13 ;
struct V_10 * V_11 = V_2 -> V_11 ;
if ( ! V_13 || ! V_11 )
return - V_47 ;
V_4 = F_2 ( V_2 ) ;
V_6 = & V_4 -> V_6 ;
memset ( & V_15 , 0 , sizeof( struct V_14 ) ) ;
V_15 . V_30 = V_2 -> V_48 ;
V_15 . V_31 = V_2 -> V_49 ;
V_15 . V_25 = 0 ;
V_15 . V_28 = 0 ;
V_15 . V_26 = V_11 -> V_33 - V_2 -> V_48 ;
V_15 . V_29 = V_11 -> V_35 - V_2 -> V_49 ;
return F_4 ( V_6 , V_2 -> V_11 , V_13 , & V_15 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_7 ( L_4 , V_2 -> V_50 . V_51 , V_13 ) ;
switch ( V_13 ) {
case V_52 :
F_3 ( V_2 , & V_4 -> V_8 ,
V_9 ) ;
break;
case V_53 :
case V_54 :
case V_55 :
F_3 ( V_2 , NULL ,
V_56 ) ;
break;
default:
F_7 ( L_5 , V_13 ) ;
break;
}
}
static void F_11 ( struct V_1 * V_2 )
{
F_7 ( L_6 , __FILE__ ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_7 ( L_6 , __FILE__ ) ;
F_3 ( V_2 , & V_4 -> V_8 ,
V_9 ) ;
}
static bool
F_13 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_12 * V_57 )
{
F_7 ( L_6 , __FILE__ ) ;
return true ;
}
static int
F_14 ( struct V_1 * V_2 , struct V_12 * V_13 ,
struct V_12 * V_57 , int V_48 , int V_49 ,
struct V_10 * V_58 )
{
F_7 ( L_6 , __FILE__ ) ;
V_13 = V_57 ;
return F_9 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_48 , int V_49 ,
struct V_10 * V_58 )
{
int V_59 ;
F_7 ( L_6 , __FILE__ ) ;
V_59 = F_9 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_1 ( V_2 ) ;
return V_59 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_7 ( L_6 , __FILE__ ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_60 * V_61 )
{
struct V_62 * V_63 = V_2 -> V_63 ;
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 * V_58 = V_2 -> V_11 ;
int V_59 = - V_47 ;
F_7 ( L_6 , __FILE__ ) ;
F_18 ( & V_63 -> V_67 ) ;
if ( V_61 ) {
V_61 -> V_8 = V_4 -> V_8 ;
F_19 ( & V_61 -> V_50 . V_68 ,
& V_65 -> V_69 ) ;
V_59 = F_20 ( V_63 , V_4 -> V_8 ) ;
if ( V_59 ) {
F_21 ( L_7 ) ;
F_22 ( & V_61 -> V_50 . V_68 ) ;
goto V_70;
}
V_2 -> V_11 = V_11 ;
V_59 = F_9 ( V_2 ) ;
if ( V_59 ) {
V_2 -> V_11 = V_58 ;
F_23 ( V_63 , V_4 -> V_8 ) ;
F_22 ( & V_61 -> V_50 . V_68 ) ;
goto V_70;
}
F_1 ( V_2 ) ;
}
V_70:
F_24 ( & V_63 -> V_67 ) ;
return V_59 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_64 * V_71 = V_2 -> V_63 -> V_66 ;
F_7 ( L_6 , __FILE__ ) ;
V_71 -> V_2 [ V_4 -> V_8 ] = NULL ;
F_26 ( V_2 ) ;
F_27 ( V_4 ) ;
}
struct V_5 * F_28 ( struct V_62 * V_63 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return & V_4 -> V_6 ;
}
int F_29 ( struct V_62 * V_63 , unsigned int V_72 )
{
struct V_3 * V_4 ;
struct V_64 * V_71 = V_63 -> V_66 ;
struct V_1 * V_2 ;
F_7 ( L_6 , __FILE__ ) ;
V_4 = F_30 ( sizeof( * V_4 ) , V_73 ) ;
if ( ! V_4 ) {
F_31 ( L_8 ) ;
return - V_74 ;
}
V_4 -> V_8 = V_72 ;
V_2 = & V_4 -> V_1 ;
V_71 -> V_2 [ V_72 ] = V_2 ;
F_32 ( V_63 , V_2 , & V_75 ) ;
F_33 ( V_2 , & V_76 ) ;
return 0 ;
}
int F_34 ( struct V_62 * V_63 , int V_2 )
{
struct V_64 * V_71 = V_63 -> V_66 ;
F_7 ( L_6 , __FILE__ ) ;
F_3 ( V_71 -> V_2 [ V_2 ] , & V_2 ,
V_77 ) ;
return 0 ;
}
void F_35 ( struct V_62 * V_63 , int V_2 )
{
struct V_64 * V_71 = V_63 -> V_66 ;
F_7 ( L_6 , __FILE__ ) ;
F_3 ( V_71 -> V_2 [ V_2 ] , & V_2 ,
V_78 ) ;
}
