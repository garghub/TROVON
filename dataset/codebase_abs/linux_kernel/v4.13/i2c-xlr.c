static inline void F_1 ( T_1 T_2 * V_1 , unsigned int V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
}
static inline T_1 F_3 ( T_1 T_2 * V_1 , unsigned int V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 , T_1 V_6 )
{
return ( V_6 & V_7 ) == V_5 -> V_8 -> V_9 ;
}
static int F_6 ( struct V_4 * V_5 )
{
return ! F_5 ( V_5 , F_3 ( V_5 -> V_10 , V_11 ) ) ;
}
static int F_7 ( struct V_4 * V_5 , unsigned long V_12 )
{
int V_6 ;
int V_13 ;
V_13 = F_8 ( V_5 -> V_14 , F_6 ( V_5 ) ,
F_9 ( V_12 ) ) ;
if ( ! V_13 )
return - V_15 ;
V_6 = F_3 ( V_5 -> V_10 , V_11 ) ;
return V_6 & V_16 ? - V_17 : 0 ;
}
static void F_10 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_18 * V_19 = V_5 -> V_19 ;
if ( V_6 & V_20 )
F_1 ( V_5 -> V_10 , V_21 ,
V_19 -> V_22 [ V_5 -> V_23 ++ ] ) ;
}
static void F_11 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_18 * V_19 = V_5 -> V_19 ;
if ( V_6 & V_24 )
V_19 -> V_22 [ V_5 -> V_23 ++ ] =
F_3 ( V_5 -> V_10 , V_25 ) ;
}
static T_3 F_12 ( int V_26 , void * V_27 )
{
struct V_4 * V_5 = V_27 ;
struct V_18 * V_19 = V_5 -> V_19 ;
T_1 V_28 , V_6 ;
V_28 = F_3 ( V_5 -> V_10 , V_29 ) ;
if ( ! V_28 )
return V_30 ;
F_1 ( V_5 -> V_10 , V_29 , V_28 ) ;
if ( ! V_19 )
return V_31 ;
V_6 = F_3 ( V_5 -> V_10 , V_11 ) ;
if ( V_5 -> V_23 < V_19 -> V_32 ) {
if ( V_19 -> V_33 & V_34 )
F_11 ( V_5 , V_6 ) ;
else
F_10 ( V_5 , V_6 ) ;
}
if ( ! F_5 ( V_5 , V_6 ) )
F_13 ( & V_5 -> V_14 ) ;
return V_31 ;
}
static int F_14 ( struct V_4 * V_5 , T_4 V_32 ,
T_5 * V_22 , T_4 V_35 )
{
struct V_36 * V_37 = & V_5 -> V_37 ;
unsigned long V_12 , V_38 , V_39 ;
T_1 V_40 ;
int V_23 , V_41 ;
T_5 V_42 ;
T_1 V_43 ;
if ( ! V_32 )
return - V_44 ;
V_42 = V_22 [ 0 ] ;
F_1 ( V_5 -> V_10 , V_45 , V_42 ) ;
F_1 ( V_5 -> V_10 , V_46 , V_35 ) ;
F_1 ( V_5 -> V_10 , V_47 ,
V_48 | V_5 -> V_8 -> V_49 ) ;
V_12 = F_9 ( V_50 ) ;
V_38 = V_51 + V_12 ;
V_41 = 0 ;
if ( V_32 == 1 ) {
F_1 ( V_5 -> V_10 , V_52 , V_32 - 1 ) ;
V_43 = V_53 ;
V_23 = 1 ;
} else {
F_1 ( V_5 -> V_10 , V_52 , V_32 - 2 ) ;
F_1 ( V_5 -> V_10 , V_21 , V_22 [ 1 ] ) ;
V_43 = V_54 ;
V_23 = 2 ;
}
V_5 -> V_23 = V_23 ;
V_55:
F_1 ( V_5 -> V_10 , V_56 , V_43 ) ;
if ( V_5 -> V_26 > 0 )
return F_7 ( V_5 , V_50 * V_32 ) ;
while ( ! V_41 ) {
V_39 = V_51 ;
V_40 = F_3 ( V_5 -> V_10 , V_11 ) ;
if ( ( V_40 & V_20 ) && V_23 < V_32 ) {
F_1 ( V_5 -> V_10 , V_21 , V_22 [ V_23 ++ ] ) ;
V_38 = V_51 + V_12 ;
}
V_41 = F_15 ( V_39 , V_38 ) ;
if ( V_40 & V_57 ) {
if ( V_41 )
break;
goto V_55;
}
if ( V_40 & V_16 )
return - V_17 ;
if ( ! F_5 ( V_5 , V_40 ) && V_23 >= V_32 )
return 0 ;
}
F_16 ( & V_37 -> V_58 , L_1 ) ;
return - V_15 ;
}
static int F_17 ( struct V_4 * V_5 , T_4 V_32 , T_5 * V_22 , T_4 V_35 )
{
struct V_36 * V_37 = & V_5 -> V_37 ;
T_1 V_40 ;
unsigned long V_12 , V_38 , V_39 ;
int V_59 , V_41 ;
if ( ! V_32 )
return - V_44 ;
F_1 ( V_5 -> V_10 , V_47 ,
V_60 | V_5 -> V_8 -> V_49 ) ;
F_1 ( V_5 -> V_10 , V_52 , V_32 - 1 ) ;
F_1 ( V_5 -> V_10 , V_46 , V_35 ) ;
V_5 -> V_23 = 0 ;
V_12 = F_9 ( V_50 ) ;
V_38 = V_51 + V_12 ;
V_41 = 0 ;
V_59 = 0 ;
V_55:
F_1 ( V_5 -> V_10 , V_56 , V_61 ) ;
if ( V_5 -> V_26 > 0 )
return F_7 ( V_5 , V_50 * V_32 ) ;
while ( ! V_41 ) {
V_39 = V_51 ;
V_40 = F_3 ( V_5 -> V_10 , V_11 ) ;
if ( V_40 & V_24 ) {
if ( V_59 >= V_32 )
return - V_17 ;
V_22 [ V_59 ++ ] =
F_3 ( V_5 -> V_10 , V_25 ) ;
V_38 = V_51 + V_12 ;
}
V_41 = F_15 ( V_39 , V_38 ) ;
if ( V_40 & V_57 ) {
if ( V_41 )
break;
goto V_55;
}
if ( V_40 & V_16 )
return - V_17 ;
if ( ! F_5 ( V_5 , V_40 ) )
return 0 ;
}
F_16 ( & V_37 -> V_58 , L_2 ) ;
return - V_15 ;
}
static int F_18 ( struct V_36 * V_37 ,
struct V_18 * V_62 , int V_63 )
{
struct V_18 * V_19 ;
int V_64 ;
int V_65 = 0 ;
struct V_4 * V_5 = F_19 ( V_37 ) ;
V_65 = F_20 ( V_5 -> V_66 ) ;
if ( V_65 )
return V_65 ;
if ( V_5 -> V_26 )
F_1 ( V_5 -> V_10 , V_67 , 0xf ) ;
for ( V_64 = 0 ; V_65 == 0 && V_64 < V_63 ; V_64 ++ ) {
V_19 = & V_62 [ V_64 ] ;
V_5 -> V_19 = V_19 ;
if ( V_19 -> V_33 & V_34 )
V_65 = F_17 ( V_5 , V_19 -> V_32 , & V_19 -> V_22 [ 0 ] ,
V_19 -> V_35 ) ;
else
V_65 = F_14 ( V_5 , V_19 -> V_32 , & V_19 -> V_22 [ 0 ] ,
V_19 -> V_35 ) ;
}
if ( V_5 -> V_26 )
F_1 ( V_5 -> V_10 , V_67 , 0 ) ;
F_21 ( V_5 -> V_66 ) ;
V_5 -> V_19 = NULL ;
return ( V_65 != 0 ) ? V_65 : V_63 ;
}
static T_1 F_22 ( struct V_36 * V_37 )
{
return ( V_68 & ~ V_69 ) | V_70 ;
}
static int F_23 ( struct V_71 * V_72 )
{
const struct V_73 * V_74 ;
struct V_4 * V_5 ;
struct V_75 * V_76 ;
struct V_66 * V_66 ;
unsigned long V_77 ;
unsigned long V_78 ;
T_1 V_79 ;
int V_26 ;
int V_65 ;
V_5 = F_24 ( & V_72 -> V_58 , sizeof( * V_5 ) , V_80 ) ;
if ( ! V_5 )
return - V_81 ;
V_74 = F_25 ( V_82 , & V_72 -> V_58 ) ;
if ( V_74 )
V_5 -> V_8 = V_74 -> V_83 ;
else
V_5 -> V_8 = & V_84 ;
V_76 = F_26 ( V_72 , V_85 , 0 ) ;
V_5 -> V_10 = F_27 ( & V_72 -> V_58 , V_76 ) ;
if ( F_28 ( V_5 -> V_10 ) )
return F_29 ( V_5 -> V_10 ) ;
V_26 = F_30 ( V_72 , 0 ) ;
if ( V_26 > 0 && ( V_5 -> V_8 -> V_33 & V_86 ) ) {
V_5 -> V_26 = V_26 ;
F_1 ( V_5 -> V_10 , V_67 , 0 ) ;
F_1 ( V_5 -> V_10 , V_29 , 0xf ) ;
V_65 = F_31 ( & V_72 -> V_58 , V_5 -> V_26 , F_12 ,
V_87 , F_32 ( & V_72 -> V_58 ) ,
V_5 ) ;
if ( V_65 )
return V_65 ;
F_33 ( & V_5 -> V_14 ) ;
}
if ( F_34 ( V_72 -> V_58 . V_88 , L_3 ,
& V_79 ) )
V_79 = 100000 ;
V_66 = F_35 ( & V_72 -> V_58 , NULL ) ;
if ( ! F_28 ( V_66 ) ) {
V_65 = F_36 ( V_66 ) ;
if ( V_65 )
return V_65 ;
V_77 = F_37 ( V_66 ) ;
V_78 = F_38 ( V_77 , 2 * V_79 ) ;
F_1 ( V_5 -> V_10 , V_89 , V_78 ) ;
F_21 ( V_66 ) ;
V_5 -> V_66 = V_66 ;
}
V_5 -> V_37 . V_58 . V_90 = & V_72 -> V_58 ;
V_5 -> V_37 . V_58 . V_88 = V_72 -> V_58 . V_88 ;
V_5 -> V_37 . V_91 = V_92 ;
V_5 -> V_37 . V_93 = V_5 ;
V_5 -> V_37 . V_94 = & V_95 ;
V_5 -> V_37 . V_96 = V_72 -> V_97 ;
V_5 -> V_37 . V_98 = V_99 ;
snprintf ( V_5 -> V_37 . V_100 , sizeof( V_5 -> V_37 . V_100 ) , L_4 ) ;
F_39 ( & V_5 -> V_37 , V_5 ) ;
V_65 = F_40 ( & V_5 -> V_37 ) ;
if ( V_65 < 0 )
return V_65 ;
F_41 ( V_72 , V_5 ) ;
F_42 ( & V_5 -> V_37 . V_58 , L_5 ) ;
return 0 ;
}
static int F_43 ( struct V_71 * V_72 )
{
struct V_4 * V_5 ;
V_5 = F_44 ( V_72 ) ;
F_45 ( & V_5 -> V_37 ) ;
F_46 ( V_5 -> V_66 ) ;
return 0 ;
}
