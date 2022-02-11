static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_5 -> V_7 [ V_8 ] - ( V_3 / 8 ) ;
T_1 V_9 = 1 << ( V_3 % 8 ) ;
int V_10 ;
V_10 = F_3 ( V_5 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
return ! ! ( V_10 & V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 , int V_11 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_12 = V_11 ? V_13 : V_14 ;
T_1 V_6 = V_5 -> V_7 [ V_12 ] - ( V_3 / 8 ) ;
T_1 V_9 = 1 << ( V_3 % 8 ) ;
if ( V_5 -> V_7 [ V_13 ] == V_5 -> V_7 [ V_14 ] )
F_5 ( V_5 , V_6 , V_9 , V_11 ? V_9 : 0 ) ;
else
F_6 ( V_5 , V_6 , V_9 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_5 -> V_7 [ V_15 ] - ( V_3 / 8 ) ;
T_1 V_9 = 1 << ( V_3 % 8 ) ;
int V_10 ;
V_10 = F_3 ( V_5 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
return ! ( V_10 & V_9 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_3 , int V_11 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_5 -> V_7 [ V_15 ] - ( V_3 / 8 ) ;
T_1 V_9 = 1 << ( V_3 % 8 ) ;
F_4 ( V_2 , V_3 , V_11 ) ;
return F_5 ( V_5 , V_6 , V_9 , V_9 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_5 -> V_7 [ V_15 ] - ( V_3 / 8 ) ;
T_1 V_9 = 1 << ( V_3 % 8 ) ;
return F_5 ( V_5 , V_6 , V_9 , 0 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
if ( V_4 -> V_16 & ( 1 << V_3 ) )
return - V_17 ;
return F_11 ( V_5 , 1 << V_3 , V_18 ) ;
}
static int F_12 ( struct V_19 * V_20 , unsigned int type )
{
struct V_1 * V_21 = F_13 ( V_20 ) ;
struct V_4 * V_4 = F_2 ( V_21 ) ;
int V_3 = V_20 -> V_22 ;
int V_23 = V_3 / 8 ;
int V_9 = 1 << ( V_3 % 8 ) ;
if ( type & V_24 || type & V_25 )
return - V_17 ;
if ( V_4 -> V_5 -> V_26 == V_27 )
return 0 ;
if ( type & V_28 )
V_4 -> V_7 [ V_29 ] [ V_23 ] |= V_9 ;
else
V_4 -> V_7 [ V_29 ] [ V_23 ] &= ~ V_9 ;
if ( type & V_30 )
V_4 -> V_7 [ V_31 ] [ V_23 ] |= V_9 ;
else
V_4 -> V_7 [ V_31 ] [ V_23 ] &= ~ V_9 ;
return 0 ;
}
static void F_14 ( struct V_19 * V_20 )
{
struct V_1 * V_21 = F_13 ( V_20 ) ;
struct V_4 * V_4 = F_2 ( V_21 ) ;
F_15 ( & V_4 -> V_32 ) ;
}
static void F_16 ( struct V_19 * V_20 )
{
struct V_1 * V_21 = F_13 ( V_20 ) ;
struct V_4 * V_4 = F_2 ( V_21 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_33 = F_17 ( V_5 -> V_34 , 8 ) ;
static const T_1 V_35 [] = {
[ V_29 ] = V_36 ,
[ V_31 ] = V_37 ,
[ V_38 ] = V_39 ,
} ;
int V_40 , V_41 ;
for ( V_40 = 0 ; V_40 < V_42 ; V_40 ++ ) {
if ( ( V_5 -> V_26 == V_27 ) &&
( V_40 != V_38 ) )
continue;
for ( V_41 = 0 ; V_41 < V_33 ; V_41 ++ ) {
T_1 V_43 = V_4 -> V_44 [ V_40 ] [ V_41 ] ;
T_1 V_45 = V_4 -> V_7 [ V_40 ] [ V_41 ] ;
if ( V_45 == V_43 )
continue;
V_4 -> V_44 [ V_40 ] [ V_41 ] = V_45 ;
F_6 ( V_5 , V_5 -> V_7 [ V_35 [ V_40 ] ] - V_41 , V_45 ) ;
}
}
F_18 ( & V_4 -> V_32 ) ;
}
static void F_19 ( struct V_19 * V_20 )
{
struct V_1 * V_21 = F_13 ( V_20 ) ;
struct V_4 * V_4 = F_2 ( V_21 ) ;
int V_3 = V_20 -> V_22 ;
int V_23 = V_3 / 8 ;
int V_9 = 1 << ( V_3 % 8 ) ;
V_4 -> V_7 [ V_38 ] [ V_23 ] &= ~ V_9 ;
}
static void F_20 ( struct V_19 * V_20 )
{
struct V_1 * V_21 = F_13 ( V_20 ) ;
struct V_4 * V_4 = F_2 ( V_21 ) ;
int V_3 = V_20 -> V_22 ;
int V_23 = V_3 / 8 ;
int V_9 = 1 << ( V_3 % 8 ) ;
V_4 -> V_7 [ V_38 ] [ V_23 ] |= V_9 ;
}
static void F_21 ( struct V_46 * V_47 ,
struct V_1 * V_21 ,
unsigned V_3 , unsigned V_48 )
{
struct V_4 * V_4 = F_2 ( V_21 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
const char * V_49 = F_22 ( V_21 , V_3 ) ;
int V_33 = F_17 ( V_5 -> V_34 , 8 ) ;
bool V_11 = ! ! F_1 ( V_21 , V_3 ) ;
T_1 V_50 = V_5 -> V_7 [ V_15 ] - ( V_3 / 8 ) ;
T_1 V_9 = 1 << ( V_3 % 8 ) ;
int V_10 ;
T_1 V_51 ;
V_10 = F_3 ( V_5 , V_50 ) ;
if ( V_10 < 0 )
return;
V_51 = ! ! ( V_10 & V_9 ) ;
if ( V_51 ) {
F_23 ( V_47 , L_1 ,
V_48 , V_49 ? : L_2 ,
V_11 ? L_3 : L_4 ) ;
} else {
T_1 V_52 = V_5 -> V_7 [ V_53 ] + V_33 - 1 - ( V_3 / 8 ) ;
T_1 V_54 = V_5 -> V_7 [ V_36 ] - ( V_3 / 8 ) ;
T_1 V_55 = V_5 -> V_7 [ V_37 ] - ( V_3 / 8 ) ;
T_1 V_56 = V_5 -> V_7 [ V_39 ] - ( V_3 / 8 ) ;
bool V_57 ;
bool V_58 ;
bool V_59 ;
bool V_60 ;
V_10 = F_3 ( V_5 , V_52 ) ;
if ( V_10 < 0 )
return;
V_57 = ! ! ( V_10 & V_9 ) ;
V_10 = F_3 ( V_5 , V_54 ) ;
if ( V_10 < 0 )
return;
V_58 = ! ! ( V_10 & V_9 ) ;
V_10 = F_3 ( V_5 , V_55 ) ;
if ( V_10 < 0 )
return;
V_59 = ! ! ( V_10 & V_9 ) ;
V_10 = F_3 ( V_5 , V_56 ) ;
if ( V_10 < 0 )
return;
V_60 = ! ! ( V_10 & V_9 ) ;
F_23 ( V_47 , L_5 ,
V_48 , V_49 ? : L_2 ,
V_11 ? L_3 : L_4 ,
V_57 ? L_6 : L_7 ,
V_60 ? L_8 : L_9 ,
V_58 ? L_10 : L_9 ,
V_59 ? L_11 : L_9 ) ;
}
}
static void F_24 ( struct V_46 * V_47 , struct V_1 * V_21 )
{
unsigned V_40 ;
unsigned V_48 = V_21 -> V_61 ;
for ( V_40 = 0 ; V_40 < V_21 -> V_62 ; V_40 ++ , V_48 ++ ) {
F_21 ( V_47 , V_21 , V_40 , V_48 ) ;
F_23 ( V_47 , L_12 ) ;
}
}
static T_2 F_25 ( int V_63 , void * V_64 )
{
struct V_4 * V_4 = V_64 ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_65 = V_5 -> V_7 [ V_66 ] ;
int V_33 = F_17 ( V_5 -> V_34 , 8 ) ;
T_1 V_67 [ V_33 ] ;
int V_10 ;
int V_40 ;
V_10 = F_26 ( V_5 , V_65 , V_33 , V_67 ) ;
if ( V_10 < 0 )
return V_68 ;
for ( V_40 = 0 ; V_40 < V_33 ; V_40 ++ ) {
int V_69 = V_33 - V_40 - 1 ;
unsigned int V_70 = V_4 -> V_7 [ V_38 ] [ V_69 ] ;
unsigned int V_71 = V_67 [ V_40 ] ;
V_71 &= V_70 ;
if ( ! V_71 )
continue;
while ( V_71 ) {
int V_72 = F_27 ( V_71 ) ;
int line = V_69 * 8 + V_72 ;
int V_73 = F_28 ( V_4 -> V_2 . V_74 ,
line ) ;
F_29 ( V_73 ) ;
V_71 &= ~ ( 1 << V_72 ) ;
}
F_6 ( V_5 , V_65 + V_40 , V_67 [ V_40 ] ) ;
if ( V_5 -> V_26 != V_27 )
F_6 ( V_5 , V_5 -> V_7 [ V_53 ]
+ V_40 , V_67 [ V_40 ] ) ;
}
return V_75 ;
}
static int F_30 ( struct V_76 * V_77 )
{
struct V_5 * V_5 = F_31 ( V_77 -> V_64 . V_78 ) ;
struct V_79 * V_80 = V_77 -> V_64 . V_81 ;
struct V_4 * V_4 ;
int V_10 ;
int V_63 = 0 ;
V_63 = F_32 ( V_77 , 0 ) ;
V_4 = F_33 ( sizeof( struct V_4 ) , V_82 ) ;
if ( ! V_4 )
return - V_83 ;
F_34 ( & V_4 -> V_32 ) ;
V_4 -> V_64 = & V_77 -> V_64 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_2 = V_84 ;
V_4 -> V_2 . V_62 = V_5 -> V_34 ;
V_4 -> V_2 . V_78 = & V_77 -> V_64 ;
V_4 -> V_2 . V_81 = V_80 ;
V_4 -> V_2 . V_61 = - 1 ;
if ( F_35 ( V_85 ) )
V_4 -> V_2 . V_86 = F_24 ;
F_36 ( V_80 , L_13 ,
& V_4 -> V_16 ) ;
if ( V_63 < 0 )
F_37 ( & V_77 -> V_64 ,
L_14
L_15 ) ;
V_10 = F_38 ( V_5 , V_18 ) ;
if ( V_10 )
goto V_87;
V_10 = F_39 ( & V_4 -> V_2 , V_4 ) ;
if ( V_10 ) {
F_40 ( & V_77 -> V_64 , L_16 , V_10 ) ;
goto V_88;
}
if ( V_63 > 0 ) {
V_10 = F_41 ( & V_77 -> V_64 , V_63 , NULL ,
F_25 , V_89 ,
L_17 , V_4 ) ;
if ( V_10 ) {
F_40 ( & V_77 -> V_64 , L_18 , V_10 ) ;
goto V_88;
}
V_10 = F_42 ( & V_4 -> V_2 ,
& V_90 ,
0 ,
V_91 ,
V_92 ) ;
if ( V_10 ) {
F_40 ( & V_77 -> V_64 ,
L_19 ) ;
goto V_88;
}
F_43 ( & V_4 -> V_2 ,
& V_90 ,
V_63 ,
NULL ) ;
}
F_44 ( V_77 , V_4 ) ;
return 0 ;
V_88:
F_45 ( V_5 , V_18 ) ;
F_46 ( & V_4 -> V_2 ) ;
V_87:
F_47 ( V_4 ) ;
return V_10 ;
}
static int T_3 F_48 ( void )
{
return F_49 ( & V_93 ) ;
}
