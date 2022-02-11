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
if ( ! V_24 ) {
if ( V_17 -> V_22 < V_38 )
V_12 -> V_39 = 0x00100000 | V_4 -> V_40 ;
else
V_12 -> V_39 = 0x01000000 | V_4 -> V_40 ;
} else {
T_1 V_41 = V_5 -> V_42 ;
if ( V_17 -> V_22 >= V_43 )
V_41 >>= 4 ;
V_12 -> V_39 = ( ( V_4 -> V_40 / 4 ) << 4 ) | V_41 ;
}
}
return 0 ;
}
static struct V_1 *
F_12 ( struct V_10 * V_11 ,
struct V_7 * V_8 ,
struct V_13 * V_14 )
{
struct V_3 * V_44 ;
struct V_45 * V_6 ;
int V_20 ;
V_6 = F_13 ( V_11 , V_8 , V_14 -> V_9 ) ;
if ( ! V_6 )
return F_14 ( - V_46 ) ;
V_44 = F_15 ( sizeof( struct V_3 ) , V_47 ) ;
if ( ! V_44 )
return F_14 ( - V_48 ) ;
V_20 = F_7 ( V_11 , V_44 , V_14 , F_16 ( V_6 ) ) ;
if ( V_20 ) {
F_17 ( V_6 ) ;
return F_14 ( V_20 ) ;
}
return & V_44 -> V_19 ;
}
int
F_18 ( struct V_10 * V_11 , int V_49 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
if ( V_17 -> V_22 >= V_23 )
F_19 ( V_11 , V_50 , 0 ,
F_20 ( V_49 ) ) ;
else
F_21 ( V_11 , V_49 , V_51 ,
V_52 ) ;
return 0 ;
}
void
F_22 ( struct V_10 * V_11 , int V_49 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
if ( V_17 -> V_22 >= V_23 )
F_19 ( V_11 , V_50 ,
F_20 ( V_49 ) , 0 ) ;
else
F_21 ( V_11 , V_49 , V_51 , 0 ) ;
}
static int
F_23 ( struct V_15 * V_53 ,
struct V_15 * V_54 )
{
int V_20 ;
V_20 = F_24 ( V_54 , V_55 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_25 ( & V_54 -> V_56 , false , false , false , 0 ) ;
if ( V_20 )
goto V_57;
V_20 = F_25 ( & V_53 -> V_56 , false , false , false , 0 ) ;
if ( V_20 )
goto V_58;
return 0 ;
V_58:
F_26 ( & V_54 -> V_56 ) ;
V_57:
F_27 ( V_54 ) ;
return V_20 ;
}
static void
F_28 ( struct V_15 * V_53 ,
struct V_15 * V_54 ,
struct V_59 * V_60 )
{
F_29 ( V_54 , V_60 ) ;
F_26 ( & V_54 -> V_56 ) ;
F_29 ( V_53 , V_60 ) ;
F_26 ( & V_53 -> V_56 ) ;
F_27 ( V_53 ) ;
}
static int
F_30 ( struct V_61 * V_62 ,
struct V_15 * V_53 ,
struct V_15 * V_54 ,
struct V_63 * V_64 ,
struct V_59 * * V_65 )
{
struct V_16 * V_17 = V_62 -> V_11 -> V_18 ;
struct V_10 * V_11 = V_62 -> V_11 ;
unsigned long V_66 ;
int V_20 ;
F_31 ( & V_11 -> V_67 , V_66 ) ;
F_32 ( & V_64 -> V_68 , & V_62 -> V_69 . V_70 ) ;
F_33 ( & V_11 -> V_67 , V_66 ) ;
V_20 = F_34 ( V_53 -> V_56 . V_71 , V_62 ) ;
if ( V_20 )
goto V_57;
V_20 = F_35 ( V_62 , 2 ) ;
if ( V_20 )
goto V_57;
if ( V_17 -> V_22 < V_43 )
F_36 ( V_62 , V_72 , V_73 , 1 ) ;
else
F_37 ( V_62 , 2 , V_74 , 0x0500 , 1 ) ;
F_38 ( V_62 , 0 ) ;
F_39 ( V_62 ) ;
V_20 = F_40 ( V_62 , V_65 , true ) ;
if ( V_20 )
goto V_57;
return 0 ;
V_57:
F_31 ( & V_11 -> V_67 , V_66 ) ;
F_41 ( & V_64 -> V_68 ) ;
F_33 ( & V_11 -> V_67 , V_66 ) ;
return V_20 ;
}
int
F_42 ( struct V_75 * V_49 , struct V_1 * V_4 ,
struct V_76 * V_77 )
{
struct V_10 * V_11 = V_49 -> V_11 ;
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_15 * V_53 = V_3 ( V_49 -> V_4 ) -> V_5 ;
struct V_15 * V_54 = V_3 ( V_4 ) -> V_5 ;
struct V_63 * V_64 ;
struct V_61 * V_62 ;
struct V_59 * V_60 ;
int V_20 ;
if ( ! V_17 -> V_78 )
return - V_79 ;
V_64 = F_15 ( sizeof( * V_64 ) , V_47 ) ;
if ( ! V_64 )
return - V_48 ;
V_20 = F_23 ( V_53 , V_54 ) ;
if ( V_20 )
goto V_80;
* V_64 = (struct V_63 )
{ { } , V_77 , F_43 ( V_49 ) -> V_81 ,
V_4 -> V_82 , V_4 -> V_40 , V_49 -> V_83 , V_49 -> V_84 ,
V_54 -> V_56 . V_85 } ;
V_62 = F_44 ( V_54 -> V_56 . V_71 ) ;
if ( ! V_62 )
V_62 = F_45 ( V_17 -> V_78 ) ;
F_46 ( & V_62 -> V_86 ) ;
if ( V_17 -> V_22 >= V_23 ) {
V_20 = F_47 ( V_49 , V_4 , V_62 ) ;
if ( V_20 ) {
F_48 ( & V_62 ) ;
goto V_58;
}
}
V_20 = F_30 ( V_62 , V_53 , V_54 , V_64 , & V_60 ) ;
F_48 ( & V_62 ) ;
if ( V_20 )
goto V_58;
V_49 -> V_4 = V_4 ;
F_28 ( V_53 , V_54 , V_60 ) ;
F_49 ( & V_60 ) ;
return 0 ;
V_58:
F_28 ( V_53 , V_54 , NULL ) ;
V_80:
F_4 ( V_64 ) ;
return V_20 ;
}
int
F_50 ( struct V_61 * V_62 ,
struct V_63 * V_87 )
{
struct V_10 * V_11 = V_62 -> V_11 ;
struct V_63 * V_64 ;
unsigned long V_66 ;
F_31 ( & V_11 -> V_67 , V_66 ) ;
if ( F_51 ( & V_62 -> V_69 . V_70 ) ) {
F_11 ( V_11 , L_2 , V_62 -> V_88 ) ;
F_33 ( & V_11 -> V_67 , V_66 ) ;
return - V_36 ;
}
V_64 = F_52 ( & V_62 -> V_69 . V_70 ,
struct V_63 , V_68 ) ;
if ( V_64 -> V_77 ) {
struct V_76 * V_89 = V_64 -> V_77 ;
struct V_90 V_91 ;
F_53 ( & V_91 ) ;
V_89 -> V_77 . V_92 = 0 ;
V_89 -> V_77 . V_93 = V_91 . V_93 ;
V_89 -> V_77 . V_94 = V_91 . V_94 ;
F_32 ( & V_89 -> V_19 . V_95 , & V_89 -> V_19 . V_8 -> V_96 ) ;
F_54 ( & V_89 -> V_19 . V_8 -> V_97 ) ;
}
F_41 ( & V_64 -> V_68 ) ;
if ( V_87 )
* V_87 = * V_64 ;
F_4 ( V_64 ) ;
F_33 ( & V_11 -> V_67 , V_66 ) ;
return 0 ;
}
int
F_55 ( struct V_7 * V_8 , struct V_10 * V_11 ,
struct V_98 * args )
{
struct V_15 * V_56 ;
int V_20 ;
args -> V_40 = F_56 ( args -> V_99 * ( args -> V_100 / 8 ) , 256 ) ;
args -> V_101 = args -> V_40 * args -> V_102 ;
args -> V_101 = F_56 ( args -> V_101 , V_103 ) ;
V_20 = F_57 ( V_11 , args -> V_101 , 0 , V_55 , 0 , 0 , & V_56 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_6 ( V_8 , V_56 -> V_6 , & args -> V_9 ) ;
F_2 ( V_56 -> V_6 ) ;
return V_20 ;
}
int
F_58 ( struct V_7 * V_8 , struct V_10 * V_11 ,
T_2 V_9 )
{
return F_59 ( V_8 , V_9 ) ;
}
int
F_60 ( struct V_7 * V_8 ,
struct V_10 * V_11 ,
T_2 V_9 , T_3 * V_104 )
{
struct V_45 * V_6 ;
V_6 = F_13 ( V_11 , V_8 , V_9 ) ;
if ( V_6 ) {
struct V_15 * V_56 = V_6 -> V_105 ;
* V_104 = V_56 -> V_56 . V_106 ;
F_2 ( V_6 ) ;
return 0 ;
}
return - V_46 ;
}
