static T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_7 ;
V_7 . V_8 = F_2 ( V_5 -> V_9 + V_3 ) ;
if ( V_10 != V_3 || V_11 != V_7 . V_8 ) {
V_10 = V_3 ; V_11 = V_7 . V_8 ;
F_3 ( L_1 , V_3 , V_7 . V_8 ) ;
}
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_2 V_3 , T_1 V_7 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_12 != V_3 || V_13 != V_7 . V_8 ) {
V_12 = V_3 ; V_13 = V_7 . V_8 ;
F_3 ( L_2 , V_3 , V_7 . V_8 ) ;
}
F_5 ( V_7 . V_8 , V_5 -> V_9 + V_3 ) ;
return 0 ;
}
static void F_6 ( struct V_14 * V_15 )
{
struct V_4 * V_5 =
F_7 ( V_15 , struct V_4 , V_16 . V_15 ) ;
struct V_1 * V_2 = V_5 -> V_17 ;
if ( V_2 -> V_18 ) {
if ( V_5 -> V_19 == V_5 -> V_20 ) {
F_8 ( L_3 ) ;
if ( V_5 -> V_21 ++ == 3 ) {
struct V_22 * V_23 ;
F_9 ( L_4 ) ;
F_10 ( & V_2 -> V_24 . V_25 ) ;
F_11 (feed, &fc->demux.feed_list,
list_head) {
F_12 ( V_2 , V_23 , 0 ) ;
}
F_11 (feed, &fc->demux.feed_list,
list_head) {
F_12 ( V_2 , V_23 , 1 ) ;
}
F_13 ( & V_2 -> V_24 . V_25 ) ;
V_5 -> V_21 = 0 ;
}
} else {
V_5 -> V_21 = 0 ;
V_5 -> V_20 = V_5 -> V_19 ;
}
}
F_14 ( & V_5 -> V_16 ,
F_15 ( V_26 < 100 ? 100 : V_26 ) ) ;
}
static T_3 F_16 ( int V_27 , void * V_28 )
{
struct V_4 * V_5 = V_28 ;
struct V_1 * V_2 = V_5 -> V_17 ;
unsigned long V_29 ;
T_1 V_7 ;
T_3 V_30 = V_31 ;
F_17 ( & V_5 -> V_32 , V_29 ) ;
V_7 = V_2 -> V_33 ( V_2 , V_34 ) ;
if ( V_7 . V_34 . V_35 )
F_8 ( L_5 ) ;
if ( V_7 . V_34 . V_36 )
F_8 ( L_6 ) ;
if ( V_7 . V_34 . V_37 )
F_8 ( L_7 ) ;
if ( V_7 . V_34 . V_38 )
F_8 ( L_8 ) ;
if ( ( V_5 -> V_19 % 1000 ) == 0 )
F_8 ( L_9 , V_5 -> V_19 ) ;
if ( V_7 . V_34 . V_39 == 1 ) {
if ( V_5 -> V_40 == 0 )
F_18 ( V_5 -> V_17 ,
V_5 -> V_41 [ 0 ] . V_42 ,
V_5 -> V_41 [ 0 ] . V_43 / 188 ) ;
else
F_18 ( V_5 -> V_17 ,
V_5 -> V_41 [ 0 ] . V_44 ,
V_5 -> V_41 [ 0 ] . V_43 / 188 ) ;
F_19 ( L_10 , ! V_5 -> V_40 ) ;
V_5 -> V_40 = ! V_5 -> V_40 ;
} else if ( V_7 . V_34 . V_45 == 1 ) {
T_4 V_46 =
V_2 -> V_33 ( V_2 , V_47 ) . V_48 . V_49 << 2 ;
T_5 V_50 = V_46 - V_5 -> V_41 [ 0 ] . V_51 ;
F_19 ( L_11
L_12 ,
F_20 ( V_52 - V_5 -> V_53 ) ,
V_7 . V_8 , ( unsigned long long ) V_46 , V_50 ,
V_5 -> V_54 ) ;
V_5 -> V_53 = V_52 ;
if ( V_50 < V_5 -> V_54 ) {
F_19 ( L_13 ,
( V_5 -> V_41 [ 0 ] . V_43 * 2 - 1 ) -
V_5 -> V_54 ) ;
F_21 ( V_5 -> V_17 ,
V_5 -> V_41 [ 0 ] . V_42 +
V_5 -> V_54 ,
( V_5 -> V_41 [ 0 ] . V_43 * 2 ) -
V_5 -> V_54 ) ;
V_5 -> V_54 = 0 ;
}
if ( V_50 > V_5 -> V_54 ) {
F_19 ( L_14 ,
V_50 - V_5 -> V_54 ) ;
F_21 ( V_5 -> V_17 ,
V_5 -> V_41 [ 0 ] . V_42 +
V_5 -> V_54 ,
V_50 - V_5 -> V_54 ) ;
}
F_19 ( L_15 ) ;
V_5 -> V_54 = V_50 ;
V_5 -> V_19 ++ ;
} else {
F_19 ( L_16
L_17 , V_7 . V_8 ) ;
V_30 = V_55 ;
}
F_22 ( & V_5 -> V_32 , V_29 ) ;
return V_30 ;
}
static int F_23 ( struct V_1 * V_2 , int V_56 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_56 ) {
F_24 ( V_2 , & V_5 -> V_41 [ 0 ] , V_57 ) ;
F_24 ( V_2 , & V_5 -> V_41 [ 1 ] , V_58 ) ;
F_25 ( V_2 , V_57 , 0 ) ;
F_26 ( V_2 , V_57 ,
V_59 | V_60 , 1 ) ;
F_19 ( L_18 ) ;
V_5 -> V_54 = 0 ;
F_27 ( V_2 , V_57 , 1 ) ;
F_19 ( L_19 ) ;
V_5 -> V_20 = V_5 -> V_19 ;
} else {
F_27 ( V_2 , V_57 , 0 ) ;
F_19 ( L_20 ) ;
F_26 ( V_2 , V_57 ,
V_59 | V_60 , 0 ) ;
F_19 ( L_21 ) ;
}
return 0 ;
}
static int F_28 ( struct V_4 * V_5 )
{
int V_30 ;
V_30 = F_29 ( V_5 -> V_61 , & V_5 -> V_41 [ 0 ] ,
V_62 ) ;
if ( V_30 != 0 )
return V_30 ;
V_30 = F_29 ( V_5 -> V_61 , & V_5 -> V_41 [ 1 ] ,
V_63 ) ;
if ( V_30 != 0 ) {
F_30 ( & V_5 -> V_41 [ 0 ] ) ;
return V_30 ;
}
F_31 ( V_5 -> V_17 , V_64 |
V_65 , V_66 ) ;
F_31 ( V_5 -> V_17 , V_67 |
V_68 , V_69 ) ;
V_5 -> V_70 |= V_71 ;
return V_30 ;
}
static void F_32 ( struct V_4 * V_5 )
{
if ( V_5 -> V_70 & V_71 ) {
F_30 ( & V_5 -> V_41 [ 0 ] ) ;
F_30 ( & V_5 -> V_41 [ 1 ] ) ;
}
V_5 -> V_70 &= ~ V_71 ;
}
static int F_33 ( struct V_4 * V_5 )
{
int V_30 ;
F_34 ( L_22 , V_5 -> V_61 -> V_72 ) ;
if ( ( V_30 = F_35 ( V_5 -> V_61 ) ) != 0 )
return V_30 ;
F_36 ( V_5 -> V_61 ) ;
if ( ( V_30 = F_37 ( V_5 -> V_61 , V_73 ) ) != 0 )
goto V_74;
V_5 -> V_9 = F_38 ( V_5 -> V_61 , 0 , 0x800 ) ;
if ( ! V_5 -> V_9 ) {
F_39 ( L_23 ) ;
V_30 = - V_75 ;
goto V_76;
}
F_40 ( V_5 -> V_61 , V_5 ) ;
F_41 ( & V_5 -> V_32 ) ;
if ( ( V_30 = F_42 ( V_5 -> V_61 -> V_27 , F_16 ,
V_77 , V_73 , V_5 ) ) != 0 )
goto V_78;
V_5 -> V_70 |= V_79 ;
return V_30 ;
V_78:
F_43 ( V_5 -> V_61 , V_5 -> V_9 ) ;
F_40 ( V_5 -> V_61 , NULL ) ;
V_76:
F_44 ( V_5 -> V_61 ) ;
V_74:
F_45 ( V_5 -> V_61 ) ;
return V_30 ;
}
static void F_46 ( struct V_4 * V_5 )
{
if ( V_5 -> V_70 & V_79 ) {
F_47 ( V_5 -> V_61 -> V_27 , V_5 ) ;
F_43 ( V_5 -> V_61 , V_5 -> V_9 ) ;
F_40 ( V_5 -> V_61 , NULL ) ;
F_44 ( V_5 -> V_61 ) ;
F_45 ( V_5 -> V_61 ) ;
}
V_5 -> V_70 &= ~ V_79 ;
}
static int F_48 ( struct V_80 * V_61 ,
const struct V_81 * V_82 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_30 = - V_83 ;
if ( ( V_2 = F_49 ( sizeof( struct V_4 ) ) ) == NULL ) {
F_39 ( L_24 ) ;
return - V_83 ;
}
V_5 = V_2 -> V_6 ;
V_5 -> V_17 = V_2 ;
V_2 -> V_33 = F_1 ;
V_2 -> V_84 = F_4 ;
V_2 -> V_85 = V_86 ;
V_2 -> V_87 = V_88 ;
V_2 -> V_89 = F_23 ;
if ( V_90 )
F_34 ( L_25 ) ;
else
F_34 ( L_26 ) ;
V_2 -> V_91 = V_90 ;
V_2 -> V_92 = V_93 ;
V_2 -> V_94 = & V_61 -> V_94 ;
V_2 -> V_95 = V_96 ;
V_5 -> V_61 = V_61 ;
if ( ( V_30 = F_33 ( V_5 ) ) != 0 )
goto V_97;
if ( ( V_30 = F_50 ( V_2 ) ) != 0 )
goto V_98;
if ( ( V_30 = F_28 ( V_5 ) ) != 0 )
goto V_99;
F_51 ( & V_5 -> V_16 , F_6 ) ;
if ( V_26 > 0 )
F_14 ( & V_5 -> V_16 ,
F_15 ( V_26 < 100 ?
100 :
V_26 ) ) ;
return V_30 ;
V_99:
F_52 ( V_2 ) ;
V_98:
F_46 ( V_5 ) ;
V_97:
F_53 ( V_2 ) ;
return V_30 ;
}
static void F_54 ( struct V_80 * V_61 )
{
struct V_4 * V_5 = F_55 ( V_61 ) ;
if ( V_26 > 0 )
F_56 ( & V_5 -> V_16 ) ;
F_32 ( V_5 ) ;
F_52 ( V_5 -> V_17 ) ;
F_46 ( V_5 ) ;
F_53 ( V_5 -> V_17 ) ;
}
static int T_6 F_57 ( void )
{
return F_58 ( & V_100 ) ;
}
static void T_7 F_59 ( void )
{
F_60 ( & V_100 ) ;
}
