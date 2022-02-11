static inline void F_1 ( void )
{
F_2 ( 1000 , 2000 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_3 = V_3 ;
F_4 ( V_2 -> V_4 , V_5 + V_2 -> V_6 ,
V_3 ) ;
}
static int F_5 ( struct V_7 * V_4 )
{
int V_8 ;
T_1 V_9 = V_10 ;
V_8 = F_4 ( V_4 , V_11 , V_12 ) ;
if ( V_8 )
return V_8 ;
F_2 ( 1000 , 2000 ) ;
if ( V_4 -> V_13 -> V_14 != V_15 )
V_9 |= V_16 ;
V_8 = F_4 ( V_4 , V_17 , V_9 ) ;
if ( V_8 )
return V_8 ;
return F_6 ( V_4 , V_18 ,
V_19 , V_4 -> V_13 -> V_20 ) ;
}
static void F_7 ( struct V_7 * V_4 )
{
enum V_21 V_22 = V_4 -> V_23 ;
T_1 V_24 [] = {
[ V_25 ] = V_26 ,
[ V_27 ] = V_28 ,
[ V_29 ] = V_30 ,
} ;
T_1 V_9 [] = {
[ V_25 ] = V_31 ,
[ V_27 ] = V_32 ,
[ V_29 ] = V_33 ,
} ;
T_1 V_34 [] = {
[ V_25 ] = V_35 ,
[ V_27 ] = V_36 ,
[ V_29 ] = V_37 ,
} ;
F_6 ( V_4 , V_38 , V_24 [ V_22 ] , V_9 [ V_22 ] ) ;
F_1 () ;
F_4 ( V_4 , V_39 , V_34 [ V_22 ] ) ;
}
static void F_8 ( struct V_7 * V_4 )
{
F_4 ( V_4 , V_38 , 0 ) ;
F_1 () ;
}
static void F_9 ( struct V_7 * V_4 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ )
F_4 ( V_4 , V_42 + V_40 , 0 ) ;
}
static void F_10 ( struct V_7 * V_4 , bool V_43 )
{
int V_8 ;
T_1 V_44 ;
T_1 V_45 ;
if ( ! V_43 ) {
F_8 ( V_4 ) ;
F_9 ( V_4 ) ;
return;
}
V_8 = F_11 ( V_4 , V_38 , & V_44 ) ;
if ( V_8 )
return;
V_8 = F_11 ( V_4 , V_11 , & V_45 ) ;
if ( V_8 )
return;
if ( F_12 ( V_44 ) ) {
V_44 = ( V_44 & ~ V_26 ) | V_46 ;
V_45 = ( V_45 & ~ V_47 ) | V_46 ;
}
if ( F_13 ( V_44 ) ) {
V_44 = ( V_44 & ~ V_28 ) | V_48 ;
V_45 = ( V_45 & ~ V_49 ) | V_48 ;
}
if ( F_14 ( V_44 ) ) {
V_44 = ( V_44 & ~ V_30 ) | V_50 ;
V_45 = ( V_45 & ~ V_51 ) | V_50 ;
}
F_4 ( V_4 , V_38 , V_44 ) ;
F_1 () ;
F_6 ( V_4 , V_11 , V_52 , V_45 ) ;
}
static int F_15 ( struct V_7 * V_4 ,
const T_1 * V_53 , T_2 V_54 )
{
T_1 V_55 [ V_56 ] = { 0 } ;
unsigned V_57 ;
char V_58 [ 3 ] ;
int V_59 ;
int V_60 ;
int V_61 = 0 ;
int V_8 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_56 ; V_40 ++ )
F_4 ( V_4 , V_62 + V_40 , 0 ) ;
V_40 = 0 ;
while ( ( V_61 < V_54 - 1 ) && ( V_40 < V_56 ) ) {
V_8 = sscanf ( V_53 + V_61 , L_1 , V_58 , & V_60 ) ;
if ( V_8 != 1 )
goto V_63;
V_8 = sscanf ( V_58 , L_2 , & V_57 ) ;
if ( V_8 != 1 )
goto V_63;
V_55 [ V_40 ] = ( T_1 ) V_57 ;
V_61 += V_60 ;
V_40 ++ ;
}
if ( V_40 % 2 )
goto V_63;
V_59 = V_40 ;
for ( V_40 = 0 ; V_40 < V_59 ; V_40 ++ )
F_4 ( V_4 , V_62 + V_40 , V_55 [ V_40 ] ) ;
return 0 ;
V_63:
F_16 ( & V_4 -> V_64 -> V_65 , L_3 ) ;
return - V_66 ;
}
static void F_17 ( struct V_7 * V_4 )
{
const struct V_67 * V_68 = V_4 -> V_68 ;
if ( V_68 -> V_54 > V_56 ) {
F_16 ( & V_4 -> V_64 -> V_65 , L_4 ,
V_68 -> V_54 ) ;
return;
}
F_7 ( V_4 ) ;
F_15 ( V_4 , V_68 -> V_53 , V_68 -> V_54 ) ;
}
static void F_18 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_19 ( V_70 , struct V_1 ,
V_71 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
F_20 ( & V_4 -> V_72 ) ;
F_4 ( V_4 , V_42 + V_2 -> V_6 ,
V_2 -> V_73 ) ;
F_21 ( & V_4 -> V_72 ) ;
}
static int F_22 ( struct V_74 * V_75 ,
const struct V_76 * V_77 )
{
int V_8 ;
struct V_7 * V_4 ;
struct V_1 * V_2 ;
struct V_78 * V_13 ;
struct V_79 * V_80 = V_75 -> V_65 . V_81 ;
if ( ! F_23 ( & V_75 -> V_65 ) ) {
if ( V_80 ) {
V_8 = F_24 ( & V_75 -> V_65 , V_80 ) ;
if ( V_8 < 0 )
return V_8 ;
} else {
F_16 ( & V_75 -> V_65 , L_5 ) ;
return - V_66 ;
}
}
V_13 = F_23 ( & V_75 -> V_65 ) ;
V_4 = F_25 ( & V_75 -> V_65 , sizeof( * V_4 ) , V_82 ) ;
if ( ! V_4 )
return - V_83 ;
V_2 = F_25 ( & V_75 -> V_65 ,
sizeof( * V_2 ) * V_13 -> V_84 , V_82 ) ;
if ( ! V_2 )
return - V_83 ;
V_4 -> V_64 = V_75 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_85 = & V_86 ;
F_26 ( & V_4 -> V_72 ) ;
F_27 ( V_75 , V_2 ) ;
V_8 = F_28 ( V_4 ) ;
if ( V_8 )
goto V_87;
F_29 ( & V_75 -> V_65 , L_6 , V_77 -> V_88 ) ;
V_8 = F_30 ( V_2 , V_4 ) ;
if ( V_8 )
goto V_89;
V_8 = F_31 ( V_4 ) ;
if ( V_8 ) {
F_16 ( & V_75 -> V_65 , L_7 ) ;
goto V_90;
}
return 0 ;
V_90:
F_32 ( V_2 , V_4 ) ;
V_89:
F_33 ( V_4 ) ;
V_87:
return V_8 ;
}
static int F_34 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_35 ( V_75 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
F_8 ( V_4 ) ;
F_36 ( V_4 ) ;
F_32 ( V_2 , V_4 ) ;
F_33 ( V_4 ) ;
return 0 ;
}
