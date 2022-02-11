static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
int V_6 = - V_7 ;
if ( V_2 -> V_8 -> V_9 ) {
struct V_10 V_11 ;
char V_12 [ 1 ] ;
V_11 . V_13 = V_4 -> V_13 ;
V_11 . V_14 = 0 ;
V_11 . V_15 = 1 ;
V_12 [ 0 ] = V_5 ;
V_11 . V_12 = V_12 ;
V_6 = F_2 ( V_2 , & V_11 , 1 ) ;
if ( V_6 >= 0 && V_6 != 1 )
V_6 = - V_16 ;
} else {
union V_17 V_18 ;
V_6 = V_2 -> V_8 -> V_19 ( V_2 , V_4 -> V_13 ,
V_4 -> V_14 ,
V_20 ,
V_5 , V_21 , & V_18 ) ;
}
return V_6 ;
}
static int F_3 ( struct V_22 * V_23 , T_2 V_24 )
{
struct V_25 * V_18 = F_4 ( V_23 ) ;
struct V_3 * V_4 = V_18 -> V_4 ;
const struct V_26 * V_27 = V_18 -> V_27 ;
T_1 V_28 ;
int V_6 = 0 ;
if ( V_27 -> V_29 == V_30 )
V_28 = V_24 | V_27 -> V_31 ;
else
V_28 = 1 << V_24 ;
if ( V_18 -> V_32 != V_28 ) {
V_6 = F_1 ( V_23 -> V_33 , V_4 , V_28 ) ;
V_18 -> V_32 = V_6 < 0 ? 0 : V_28 ;
}
return V_6 ;
}
static int F_5 ( struct V_22 * V_23 , T_2 V_24 )
{
struct V_25 * V_18 = F_4 ( V_23 ) ;
struct V_3 * V_4 = V_18 -> V_4 ;
if ( ! ( V_18 -> V_34 & ( 1 << V_24 ) ) )
return 0 ;
V_18 -> V_32 = 0 ;
return F_1 ( V_23 -> V_33 , V_4 , V_18 -> V_32 ) ;
}
static T_3 F_6 ( int V_35 , void * V_36 )
{
struct V_25 * V_18 = V_36 ;
unsigned int V_37 ;
int V_6 , V_38 , V_39 = 0 ;
V_6 = F_7 ( V_18 -> V_4 ) ;
if ( V_6 < 0 )
return V_40 ;
for ( V_38 = 0 ; V_38 < V_18 -> V_27 -> V_41 ; V_38 ++ ) {
if ( V_6 & F_8 ( V_42 + V_38 ) ) {
V_37 = F_9 ( V_18 -> V_35 , V_38 ) ;
F_10 ( V_37 ) ;
V_39 ++ ;
}
}
return V_39 ? V_43 : V_40 ;
}
static void F_11 ( struct V_44 * V_45 )
{
struct V_25 * V_18 = F_12 ( V_45 ) ;
unsigned int V_46 = V_45 -> V_47 ;
unsigned long V_14 ;
F_13 ( & V_18 -> V_48 , V_14 ) ;
V_18 -> V_49 &= ~ F_8 ( V_46 ) ;
if ( ! V_18 -> V_49 )
F_14 ( V_18 -> V_4 -> V_35 ) ;
F_15 ( & V_18 -> V_48 , V_14 ) ;
}
static void F_16 ( struct V_44 * V_45 )
{
struct V_25 * V_18 = F_12 ( V_45 ) ;
unsigned int V_46 = V_45 -> V_47 ;
unsigned long V_14 ;
F_13 ( & V_18 -> V_48 , V_14 ) ;
if ( ! V_18 -> V_49 )
F_17 ( V_18 -> V_4 -> V_35 ) ;
V_18 -> V_49 |= F_8 ( V_46 ) ;
F_15 ( & V_18 -> V_48 , V_14 ) ;
}
static int F_18 ( struct V_44 * V_45 , unsigned int type )
{
if ( ( type & V_50 ) != V_51 )
return - V_52 ;
return 0 ;
}
static int F_19 ( struct V_22 * V_23 )
{
struct V_25 * V_18 = F_4 ( V_23 ) ;
struct V_3 * V_4 = V_18 -> V_4 ;
int V_53 , V_54 , V_35 ;
if ( ! V_18 -> V_27 -> V_55 || V_4 -> V_35 <= 0 )
return 0 ;
F_20 ( & V_18 -> V_48 ) ;
V_18 -> V_35 = F_21 ( V_4 -> V_56 . V_57 ,
V_18 -> V_27 -> V_41 ,
& V_58 , V_18 ) ;
if ( ! V_18 -> V_35 )
return - V_7 ;
for ( V_53 = 0 ; V_53 < V_18 -> V_27 -> V_41 ; V_53 ++ ) {
V_35 = F_22 ( V_18 -> V_35 , V_53 ) ;
F_23 ( V_35 , V_18 ) ;
F_24 ( V_35 , & V_59 ,
V_60 ) ;
}
V_54 = F_25 ( & V_4 -> V_56 , V_18 -> V_4 -> V_35 , NULL ,
F_6 ,
V_61 | V_62 ,
L_1 , V_18 ) ;
if ( V_54 )
goto V_63;
F_14 ( V_18 -> V_4 -> V_35 ) ;
return 0 ;
V_63:
for ( V_53 = 0 ; V_53 < V_18 -> V_27 -> V_41 ; V_53 ++ ) {
V_35 = F_26 ( V_18 -> V_35 , V_53 ) ;
F_27 ( V_35 ) ;
}
F_28 ( V_18 -> V_35 ) ;
return V_54 ;
}
static int F_29 ( struct V_3 * V_4 ,
const struct V_64 * V_65 )
{
struct V_1 * V_2 = F_30 ( V_4 -> V_56 . V_33 ) ;
struct V_66 * V_67 = F_31 ( & V_4 -> V_56 ) ;
struct V_68 * V_57 = V_4 -> V_56 . V_57 ;
bool V_69 ;
struct V_70 * V_71 ;
int V_72 , V_73 , V_74 ;
struct V_22 * V_23 ;
struct V_25 * V_18 ;
const struct V_75 * V_76 ;
int V_6 ;
if ( ! F_32 ( V_2 , V_77 ) )
return - V_7 ;
V_23 = F_33 ( V_2 , & V_4 -> V_56 ,
V_78 , sizeof( * V_18 ) , 0 ,
F_3 , F_5 ) ;
if ( ! V_23 )
return - V_79 ;
V_18 = F_4 ( V_23 ) ;
F_34 ( V_4 , V_23 ) ;
V_18 -> V_4 = V_4 ;
V_71 = F_35 ( & V_4 -> V_56 , L_2 , V_80 ) ;
if ( F_36 ( V_71 ) )
return F_37 ( V_71 ) ;
if ( F_38 ( V_4 , 0 ) < 0 ) {
F_39 ( & V_4 -> V_56 , L_3 ) ;
return - V_7 ;
}
V_76 = F_40 ( F_41 ( V_81 ) , & V_4 -> V_56 ) ;
if ( V_76 )
V_18 -> V_27 = F_42 ( & V_4 -> V_56 ) ;
else
V_18 -> V_27 = & V_82 [ V_65 -> V_83 ] ;
V_18 -> V_32 = 0 ;
V_69 = V_57 &&
F_43 ( V_57 , L_4 ) ;
V_6 = F_19 ( V_23 ) ;
if ( V_6 )
goto V_84;
for ( V_72 = 0 ; V_72 < V_18 -> V_27 -> V_41 ; V_72 ++ ) {
bool V_85 = false ;
V_73 = 0 ;
V_74 = 0 ;
if ( V_67 ) {
if ( V_72 < V_67 -> V_86 ) {
V_73 = V_67 -> V_87 [ V_72 ] . V_88 ;
V_74 = V_67 -> V_87 [ V_72 ] . V_74 ;
} else
break;
V_85 = V_67 -> V_87 [ V_72 ] . V_89 ;
}
V_18 -> V_34 |= ( V_85 ||
V_69 ) << V_72 ;
V_6 = F_44 ( V_23 , V_73 , V_72 , V_74 ) ;
if ( V_6 ) {
F_45 ( & V_4 -> V_56 ,
L_5
L_6 , V_72 , V_73 ) ;
goto V_84;
}
}
F_46 ( & V_4 -> V_56 ,
L_7 ,
V_72 , V_18 -> V_27 -> V_29 == V_30
? L_8 : L_9 , V_4 -> V_90 ) ;
return 0 ;
V_84:
F_47 ( V_23 ) ;
return V_6 ;
}
static int F_48 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = F_49 ( V_4 ) ;
struct V_25 * V_18 = F_4 ( V_23 ) ;
int V_53 , V_35 ;
if ( V_18 -> V_35 ) {
for ( V_53 = 0 ; V_53 < V_18 -> V_27 -> V_41 ; V_53 ++ ) {
V_35 = F_26 ( V_18 -> V_35 , V_53 ) ;
F_27 ( V_35 ) ;
}
F_28 ( V_18 -> V_35 ) ;
}
F_47 ( V_23 ) ;
return 0 ;
}
static int F_50 ( struct V_91 * V_56 )
{
struct V_3 * V_4 = F_51 ( V_56 ) ;
struct V_22 * V_23 = F_49 ( V_4 ) ;
struct V_25 * V_18 = F_4 ( V_23 ) ;
V_18 -> V_32 = 0 ;
return F_38 ( V_4 , 0 ) ;
}
