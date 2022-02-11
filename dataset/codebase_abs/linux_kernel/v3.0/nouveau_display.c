static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
if ( V_4 -> V_5 )
F_2 ( V_4 -> V_5 -> V_6 ) ;
F_3 ( V_2 ) ;
F_4 ( V_4 ) ;
}
static int
F_5 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
return F_6 ( V_8 , V_4 -> V_5 -> V_6 , V_9 ) ;
}
int
F_7 ( struct V_10 * V_11 ,
struct V_3 * V_12 ,
struct V_13 * V_14 ,
struct V_15 * V_5 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_1 * V_4 = & V_12 -> V_19 ;
int V_20 ;
V_20 = F_8 ( V_11 , V_4 , & V_21 ) ;
if ( V_20 ) {
return V_20 ;
}
F_9 ( V_4 , V_14 ) ;
V_12 -> V_5 = V_5 ;
if ( V_17 -> V_22 >= V_23 ) {
T_1 V_24 = F_10 ( V_5 ) ;
if ( V_24 == 0x7a00 ||
V_24 == 0xfe00 )
V_12 -> V_25 = V_26 ;
else
if ( V_24 == 0x7000 )
V_12 -> V_25 = V_27 ;
else
V_12 -> V_25 = V_28 ;
switch ( V_4 -> V_29 ) {
case 8 : V_12 -> V_30 = V_31 ; break;
case 15 : V_12 -> V_30 = V_32 ; break;
case 16 : V_12 -> V_30 = V_33 ; break;
case 24 :
case 32 : V_12 -> V_30 = V_34 ; break;
case 30 : V_12 -> V_30 = V_35 ; break;
default:
F_11 ( V_11 , L_1 , V_4 -> V_29 ) ;
return - V_36 ;
}
if ( V_17 -> V_37 == 0x50 )
V_12 -> V_30 |= ( V_24 << 8 ) ;
if ( ! V_24 )
V_12 -> V_38 = 0x00100000 | V_4 -> V_39 ;
else {
T_1 V_40 = V_5 -> V_41 ;
if ( V_17 -> V_22 >= V_42 )
V_40 >>= 4 ;
V_12 -> V_38 = ( ( V_4 -> V_39 / 4 ) << 4 ) | V_40 ;
}
}
return 0 ;
}
static struct V_1 *
F_12 ( struct V_10 * V_11 ,
struct V_7 * V_8 ,
struct V_13 * V_14 )
{
struct V_3 * V_43 ;
struct V_44 * V_6 ;
int V_20 ;
V_6 = F_13 ( V_11 , V_8 , V_14 -> V_9 ) ;
if ( ! V_6 )
return F_14 ( - V_45 ) ;
V_43 = F_15 ( sizeof( struct V_3 ) , V_46 ) ;
if ( ! V_43 )
return F_14 ( - V_47 ) ;
V_20 = F_7 ( V_11 , V_43 , V_14 , F_16 ( V_6 ) ) ;
if ( V_20 ) {
F_17 ( V_6 ) ;
return F_14 ( V_20 ) ;
}
return & V_43 -> V_19 ;
}
int
F_18 ( struct V_10 * V_11 , int V_48 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
if ( V_17 -> V_22 >= V_23 )
F_19 ( V_11 , V_49 , 0 ,
F_20 ( V_48 ) ) ;
else
F_21 ( V_11 , V_48 , V_50 ,
V_51 ) ;
return 0 ;
}
void
F_22 ( struct V_10 * V_11 , int V_48 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
if ( V_17 -> V_22 >= V_23 )
F_19 ( V_11 , V_49 ,
F_20 ( V_48 ) , 0 ) ;
else
F_21 ( V_11 , V_48 , V_50 , 0 ) ;
}
static int
F_23 ( struct V_15 * V_52 ,
struct V_15 * V_53 )
{
int V_20 ;
V_20 = F_24 ( V_53 , V_54 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_25 ( & V_53 -> V_55 , false , false , false , 0 ) ;
if ( V_20 )
goto V_56;
V_20 = F_25 ( & V_52 -> V_55 , false , false , false , 0 ) ;
if ( V_20 )
goto V_57;
return 0 ;
V_57:
F_26 ( & V_53 -> V_55 ) ;
V_56:
F_27 ( V_53 ) ;
return V_20 ;
}
static void
F_28 ( struct V_15 * V_52 ,
struct V_15 * V_53 ,
struct V_58 * V_59 )
{
F_29 ( V_53 , V_59 ) ;
F_26 ( & V_53 -> V_55 ) ;
F_29 ( V_52 , V_59 ) ;
F_26 ( & V_52 -> V_55 ) ;
F_27 ( V_52 ) ;
}
static int
F_30 ( struct V_60 * V_61 ,
struct V_15 * V_52 ,
struct V_15 * V_53 ,
struct V_62 * V_63 ,
struct V_58 * * V_64 )
{
struct V_16 * V_17 = V_61 -> V_11 -> V_18 ;
struct V_10 * V_11 = V_61 -> V_11 ;
unsigned long V_65 ;
int V_20 ;
F_31 ( & V_11 -> V_66 , V_65 ) ;
F_32 ( & V_63 -> V_67 , & V_61 -> V_68 . V_69 ) ;
F_33 ( & V_11 -> V_66 , V_65 ) ;
V_20 = F_34 ( V_52 -> V_55 . V_70 , V_61 ) ;
if ( V_20 )
goto V_56;
V_20 = F_35 ( V_61 , 2 ) ;
if ( V_20 )
goto V_56;
if ( V_17 -> V_22 < V_42 )
F_36 ( V_61 , V_71 , V_72 , 1 ) ;
else
F_37 ( V_61 , 2 , V_73 , 0x0500 , 1 ) ;
F_38 ( V_61 , 0 ) ;
F_39 ( V_61 ) ;
V_20 = F_40 ( V_61 , V_64 , true ) ;
if ( V_20 )
goto V_56;
return 0 ;
V_56:
F_31 ( & V_11 -> V_66 , V_65 ) ;
F_41 ( & V_63 -> V_67 ) ;
F_33 ( & V_11 -> V_66 , V_65 ) ;
return V_20 ;
}
int
F_42 ( struct V_74 * V_48 , struct V_1 * V_4 ,
struct V_75 * V_76 )
{
struct V_10 * V_11 = V_48 -> V_11 ;
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_15 * V_52 = V_3 ( V_48 -> V_4 ) -> V_5 ;
struct V_15 * V_53 = V_3 ( V_4 ) -> V_5 ;
struct V_62 * V_63 ;
struct V_60 * V_61 ;
struct V_58 * V_59 ;
int V_20 ;
if ( ! V_17 -> V_77 )
return - V_78 ;
V_63 = F_15 ( sizeof( * V_63 ) , V_46 ) ;
if ( ! V_63 )
return - V_47 ;
V_20 = F_23 ( V_52 , V_53 ) ;
if ( V_20 )
goto V_79;
* V_63 = (struct V_62 )
{ { } , V_76 , F_43 ( V_48 ) -> V_80 ,
V_4 -> V_81 , V_4 -> V_39 , V_48 -> V_82 , V_48 -> V_83 ,
V_53 -> V_55 . V_84 } ;
V_61 = F_44 ( V_53 -> V_55 . V_70 ) ;
if ( ! V_61 )
V_61 = F_45 ( V_17 -> V_77 ) ;
F_46 ( & V_61 -> V_85 ) ;
if ( V_17 -> V_22 >= V_23 ) {
V_20 = F_47 ( V_48 , V_4 , V_61 ) ;
if ( V_20 ) {
F_48 ( & V_61 ) ;
goto V_57;
}
}
V_20 = F_30 ( V_61 , V_52 , V_53 , V_63 , & V_59 ) ;
F_48 ( & V_61 ) ;
if ( V_20 )
goto V_57;
V_48 -> V_4 = V_4 ;
F_28 ( V_52 , V_53 , V_59 ) ;
F_49 ( & V_59 ) ;
return 0 ;
V_57:
F_28 ( V_52 , V_53 , NULL ) ;
V_79:
F_4 ( V_63 ) ;
return V_20 ;
}
int
F_50 ( struct V_60 * V_61 ,
struct V_62 * V_86 )
{
struct V_10 * V_11 = V_61 -> V_11 ;
struct V_62 * V_63 ;
unsigned long V_65 ;
F_31 ( & V_11 -> V_66 , V_65 ) ;
if ( F_51 ( & V_61 -> V_68 . V_69 ) ) {
F_11 ( V_11 , L_2 , V_61 -> V_87 ) ;
F_33 ( & V_11 -> V_66 , V_65 ) ;
return - V_36 ;
}
V_63 = F_52 ( & V_61 -> V_68 . V_69 ,
struct V_62 , V_67 ) ;
if ( V_63 -> V_76 ) {
struct V_75 * V_88 = V_63 -> V_76 ;
struct V_89 V_90 ;
F_53 ( & V_90 ) ;
V_88 -> V_76 . V_91 = 0 ;
V_88 -> V_76 . V_92 = V_90 . V_92 ;
V_88 -> V_76 . V_93 = V_90 . V_93 ;
F_32 ( & V_88 -> V_19 . V_94 , & V_88 -> V_19 . V_8 -> V_95 ) ;
F_54 ( & V_88 -> V_19 . V_8 -> V_96 ) ;
}
F_41 ( & V_63 -> V_67 ) ;
if ( V_86 )
* V_86 = * V_63 ;
F_4 ( V_63 ) ;
F_33 ( & V_11 -> V_66 , V_65 ) ;
return 0 ;
}
