T_1 void __weak F_1 ( void )
{
unsigned int V_1 , V_2 ;
V_2 = F_2 ( V_3 + V_4 ) & 0xFF ;
V_1 = F_3 ( V_5 , V_2 ) ;
F_4 ( V_1 ) ;
}
static struct V_6 * F_5 ( struct V_7 * V_8 )
{
return (struct V_6 * ) V_8 -> V_9 -> V_10 ;
}
static int F_6 ( int V_11 , T_2 type )
{
switch ( type ) {
case V_12 :
F_7 ( F_8 ( V_11 ) , V_3 + F_9 ( V_13 ) ) ;
break;
case V_14 :
F_7 ( F_8 ( V_11 ) , V_3 + F_10 ( V_13 ) ) ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_11 ( struct V_7 * V_8 ,
unsigned int V_16 )
{
struct V_6 * V_17 = F_5 ( V_8 ) ;
int V_18 ;
int V_19 ;
if ( ! ( V_16 & V_20 ) )
return - V_21 ;
for ( V_19 = 0 ; V_19 < F_12 ( V_17 -> V_22 ) ; V_19 ++ ) {
if ( V_17 -> V_22 [ V_19 ] == V_8 -> V_2 ) {
V_18 = F_6 ( V_19 + 1 , V_16 ) ;
if ( V_18 )
return V_18 ;
}
}
F_13 ( V_8 , V_16 ) ;
return V_23 ;
}
static void F_14 ( int V_1 , int V_24 )
{
F_7 ( V_24 , V_3 + V_25 + V_1 * 4 ) ;
}
static void F_15 ( int V_1 , int V_26 )
{
T_2 V_27 , V_28 ;
V_27 = V_1 / 4 ;
V_28 = ( V_1 % 4 ) * 8 ;
F_7 ( V_29 << V_28 ,
V_3 + F_10 ( V_30 + V_27 * 0x10 ) ) ;
F_7 ( V_26 << V_28 ,
V_3 + F_9 ( V_30 + V_27 * 0x10 ) ) ;
}
static int F_16 ( struct V_31 * V_32 , unsigned int V_33 ,
T_3 V_34 )
{
struct V_6 * V_17 = V_32 -> V_10 ;
struct V_7 * V_8 ;
int V_18 ;
T_2 V_35 , V_36 ;
T_2 V_27 , V_37 ;
V_18 = F_17 ( V_32 , V_33 , V_34 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 -> V_38 [ V_34 ] & V_39 ) {
V_8 = F_18 ( V_32 , V_33 ) ;
F_13 ( V_8 , V_17 -> V_38 [ V_34 ] ) ;
F_19 ( V_8 , V_17 -> V_38 [ V_34 ] ) ;
}
F_20 ( V_34 , V_27 , V_37 ) ;
V_35 = F_10 ( V_40 + V_27 * 0x10 ) ;
V_36 = F_10 ( V_41 + V_27 * 0x10 ) ;
F_7 ( V_37 , V_3 + V_35 ) ;
F_7 ( V_37 , V_3 + V_36 ) ;
F_15 ( V_34 , F_21 ( 2 , 0 ) ) ;
return V_18 ;
}
int F_22 ( struct V_31 * V_32 , struct V_42 * V_43 ,
const T_2 * V_44 , unsigned int V_45 ,
T_3 * V_46 , unsigned int * V_47 )
{
struct V_6 * V_17 = V_32 -> V_10 ;
if ( F_23 ( V_45 < 2 ) )
return - V_15 ;
if ( F_23 ( V_44 [ 0 ] >= V_48 ) )
return - V_15 ;
* V_46 = V_44 [ 0 ] ;
* V_47 = V_44 [ 1 ] & V_39 ;
V_17 -> V_38 [ V_44 [ 0 ] ] = V_44 [ 1 ] & V_39 ;
return 0 ;
}
static void T_4 F_24 ( struct V_31 * V_9 )
{
struct V_42 * V_49 = F_25 ( V_9 ) ;
struct V_6 * V_17 = V_9 -> V_10 ;
struct V_50 * V_51 ;
const T_5 * V_52 ;
T_2 V_2 ;
int V_19 = 0 ;
const char * V_53 = L_1 ;
F_26 (node, pname, prop, p, hwirq) {
if ( V_19 >= F_12 ( V_17 -> V_22 ) ) {
F_27 ( L_2 ,
F_12 ( V_17 -> V_22 ) ) ;
break;
}
V_17 -> V_22 [ V_19 ] = V_2 ;
V_19 ++ ;
}
}
static int T_4 F_28 ( struct V_42 * V_49 ,
struct V_42 * V_54 )
{
struct V_55 * V_56 ;
struct V_6 * V_17 ;
unsigned int V_57 = V_58 | V_59 | V_60 ;
int V_61 , V_18 ;
int V_19 ;
V_61 = F_29 ( V_48 , 32 ) ;
V_3 = F_30 ( V_49 , 0 ) ;
if ( ! V_3 )
return - V_62 ;
V_17 = F_31 ( V_61 , sizeof( * V_17 ) , V_63 ) ;
if ( ! V_17 ) {
V_18 = - V_62 ;
goto V_64;
}
V_5 = F_32 ( V_49 , V_61 * 32 ,
& V_65 ,
V_17 ) ;
if ( ! V_5 ) {
V_18 = - V_62 ;
goto V_66;
}
V_18 = F_33 ( V_5 , 32 , 2 ,
L_3 , V_67 ,
V_57 , 0 , 0 ) ;
if ( V_18 )
goto V_68;
V_69 = & F_14 ;
for ( V_19 = 0 ; V_19 < V_61 ; V_19 ++ ) {
T_2 V_36 = F_10 ( V_41 + ( V_19 * 0x10 ) ) ;
T_2 V_70 = V_40 + ( V_19 * 0x10 ) ;
V_56 = F_34 ( V_5 , V_19 * 32 ) ;
V_56 -> V_71 = V_3 ;
V_56 -> V_72 = 0 ;
V_56 -> V_73 [ 0 ] . type = V_74 ;
V_56 -> V_73 [ 0 ] . V_75 = V_76 ;
V_56 -> V_73 [ 0 ] . V_77 . V_78 = V_36 ;
V_56 -> V_73 [ 0 ] . V_77 . V_37 = V_70 ;
V_56 -> V_73 [ 0 ] . V_79 . V_80 = L_3 ;
V_56 -> V_73 [ 0 ] . V_79 . V_81 = V_82 ;
V_56 -> V_73 [ 0 ] . V_79 . V_83 = V_84 ;
V_56 -> V_73 [ 0 ] . V_79 . V_85 = V_86 ;
V_56 -> V_73 [ 0 ] . V_79 . V_87 = V_88 ;
V_56 -> V_73 [ 1 ] . type = V_20 ;
V_56 -> V_73 [ 1 ] . V_75 = V_89 ;
V_56 -> V_73 [ 1 ] . V_77 . V_78 = V_36 ;
V_56 -> V_73 [ 1 ] . V_77 . V_37 = V_70 ;
V_56 -> V_73 [ 1 ] . V_79 . V_80 = L_4 ;
V_56 -> V_73 [ 1 ] . V_79 . V_90 = V_82 ;
V_56 -> V_73 [ 1 ] . V_79 . V_83 = V_84 ;
V_56 -> V_73 [ 1 ] . V_79 . V_85 = V_86 ;
V_56 -> V_73 [ 1 ] . V_79 . V_91 = F_11 ;
V_56 -> V_73 [ 1 ] . V_79 . V_87 = V_88 ;
V_56 -> V_92 = & V_17 [ V_19 ] ;
}
F_35 ( V_5 ) ;
F_24 ( V_5 ) ;
return 0 ;
V_68:
F_36 ( V_5 ) ;
V_66:
F_37 ( V_17 ) ;
V_64:
F_38 ( V_3 ) ;
return V_18 ;
}
