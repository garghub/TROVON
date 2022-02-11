static int F_1 ( struct V_1 * V_2 , void T_1 * V_3 ,
struct V_4 * V_5 , int V_6 )
{
int V_7 ;
T_2 V_8 , V_9 , V_10 ;
T_3 V_11 , V_12 ;
void T_1 * V_13 ;
void T_1 * V_14 , * V_15 , * V_16 ;
void T_1 * V_17 , * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
char * V_23 , * V_24 = L_1 ;
char * V_25 ;
char V_26 [ 30 ] = { 0 } ;
char V_27 [ 60 ] = { 0 } ;
F_2 ( V_6 > V_28 ) ;
if ( V_6 < V_5 -> V_29 ) {
V_20 = & V_5 -> V_30 [ V_6 ] ;
V_23 = V_20 -> V_31 ;
V_13 = V_3 + V_20 -> V_32 ;
} else {
V_23 = V_33 ;
}
if ( V_23 == V_33 )
return - V_34 ;
V_14 = V_13 + V_35 ;
V_15 = V_13 + V_36 ;
V_8 = F_3 ( V_14 ) ;
switch ( V_8 & V_37 ) {
case V_38 :
V_25 = L_2 ;
snprintf ( V_26 , sizeof( V_26 ) ,
L_3 ,
F_3 ( V_15 ) ) ;
V_16 = V_13 + V_39 ;
V_17 = V_13 + V_40 ;
V_18 = V_13 + V_41 ;
break;
case V_37 :
V_25 = L_4 ;
V_16 = V_13 +
V_42 ;
V_17 = V_13 + V_43 ;
V_18 = V_13 + V_44 ;
break;
default:
return 0 ;
}
V_10 = ( F_3 ( V_16 ) &
V_2 -> V_45 ) >> F_4 ( V_2 -> V_45 ) ;
for ( V_7 = 0 , V_22 = V_2 -> V_46 ; V_7 < V_2 -> V_47 ;
V_7 ++ , V_22 ++ ) {
if ( V_10 == V_22 -> V_48 ) {
V_24 = V_22 -> V_31 ;
break;
}
}
V_11 = F_3 ( V_17 ) & 0x7 ;
V_12 = F_3 ( V_18 ) & 0xF ;
snprintf ( V_27 , sizeof( V_27 ) ,
L_5 ,
( V_12 & F_5 ( 0 ) ) ? L_6 : L_7 ,
( V_12 & F_5 ( 1 ) ) ? L_8 : L_9 ,
( V_12 & F_5 ( 3 ) ) ? L_10 : L_11 ) ;
F_6 ( true ,
L_12 ,
F_7 ( V_2 -> V_49 ) ,
V_25 ,
V_24 , V_23 ,
V_50 [ V_11 ] ,
V_26 , V_27 ) ;
V_9 = V_8 | V_51 ;
F_8 ( V_9 , V_14 ) ;
return 0 ;
}
static T_4 F_9 ( int V_52 , void * V_53 )
{
struct V_1 * V_2 = V_53 ;
int V_54 , V_55 , V_56 ;
int V_6 = 0 ;
T_2 V_57 , V_58 ;
void T_1 * V_3 , * V_59 ;
struct V_4 * V_5 ;
V_54 = V_52 == V_2 -> V_60 ? V_61 : V_62 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_63 ; V_55 ++ ) {
V_3 = V_2 -> V_64 [ V_55 ] ;
V_5 = V_2 -> V_65 [ V_55 ] ;
V_57 = F_3 ( V_3 + V_5 -> V_32 +
V_66 + ( V_54 << 3 ) ) ;
V_57 &= ~ ( V_54 ? V_5 -> V_67 :
V_5 -> V_68 ) ;
if ( V_57 ) {
V_6 = F_4 ( V_57 ) ;
V_56 = F_1 ( V_2 , V_3 , V_5 , V_6 ) ;
if ( V_56 ) {
F_10 ( V_2 -> V_49 ,
L_13 ,
V_54 ? L_14 : L_15 ,
V_6 , V_55 , L_16 ) ;
V_59 = V_3 + V_5 -> V_32 +
V_69 + ( V_54 << 3 ) ;
V_58 = F_3 ( V_59 ) ;
V_58 &= ~ ( 1 << V_6 ) ;
F_8 ( V_58 , V_59 ) ;
if ( V_54 )
V_5 -> V_67 |= 1 << V_6 ;
else
V_5 -> V_68 |= 1 << V_6 ;
}
return V_70 ;
}
}
F_10 ( V_2 -> V_49 , L_17 ,
V_54 ? L_14 : L_15 ) ;
return V_71 ;
}
static int F_11 ( struct V_72 * V_73 )
{
const struct V_74 * V_75 ;
static struct V_1 * V_2 ;
int V_56 , V_55 , V_76 ;
V_75 = F_12 ( V_77 , & V_73 -> V_49 ) ;
if ( ! V_75 ) {
F_10 ( & V_73 -> V_49 , L_18 ) ;
return - V_78 ;
}
V_2 = F_13 ( & V_73 -> V_49 , sizeof( * V_2 ) , V_79 ) ;
if ( ! V_2 )
return - V_80 ;
memcpy ( V_2 , V_75 -> V_81 , sizeof( * V_2 ) ) ;
V_2 -> V_49 = & V_73 -> V_49 ;
F_14 ( V_73 , V_2 ) ;
for ( V_55 = 0 , V_76 = 0 ; V_55 < V_2 -> V_63 ; V_55 ++ ) {
struct V_82 * V_83 ;
if ( V_2 -> V_64 [ V_55 ] == V_84 ) {
F_2 ( V_55 == 0 ) ;
V_2 -> V_64 [ V_55 ] = V_2 -> V_64 [ V_55 - 1 ] ;
continue;
}
V_83 = F_15 ( V_73 , V_85 , V_76 ) ;
V_2 -> V_64 [ V_55 ] = F_16 ( & V_73 -> V_49 , V_83 ) ;
if ( F_17 ( V_2 -> V_64 [ V_55 ] ) ) {
F_10 ( V_2 -> V_49 , L_19 , V_55 ) ;
return F_18 ( V_2 -> V_64 [ V_55 ] ) ;
}
V_76 ++ ;
}
V_2 -> V_86 = F_19 ( V_73 , 0 ) ;
V_56 = F_20 ( V_2 -> V_49 , V_2 -> V_86 , F_9 ,
0x0 , L_20 , V_2 ) ;
if ( V_56 ) {
F_10 ( V_2 -> V_49 , L_21 ,
V_2 -> V_86 ) ;
return V_56 ;
}
V_2 -> V_60 = F_19 ( V_73 , 1 ) ;
V_56 = F_20 ( V_2 -> V_49 , V_2 -> V_60 , F_9 ,
0x0 , L_22 , V_2 ) ;
if ( V_56 )
F_10 ( V_2 -> V_49 , L_21 , V_2 -> V_60 ) ;
return V_56 ;
}
static int F_21 ( struct V_87 * V_49 )
{
struct V_1 * V_2 = F_22 ( V_49 ) ;
int V_55 ;
struct V_4 * V_5 ;
void T_1 * V_3 , * V_88 = NULL ;
T_2 V_58 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_63 ; V_55 ++ ) {
V_3 = V_2 -> V_64 [ V_55 ] ;
V_5 = V_2 -> V_65 [ V_55 ] ;
if ( ! V_5 -> V_67 && ! V_5 -> V_68 )
continue;
V_88 = V_3 + V_5 -> V_32 + V_69 +
( V_61 << 3 ) ;
V_58 = F_3 ( V_88 ) ;
V_58 &= ~ ( V_5 -> V_67 ) ;
F_8 ( V_58 , V_88 ) ;
V_88 = V_3 + V_5 -> V_32 + V_69 +
( V_62 << 3 ) ;
V_58 = F_3 ( V_88 ) ;
V_58 &= ~ ( V_5 -> V_68 ) ;
F_8 ( V_58 , V_88 ) ;
}
if ( V_88 )
( void ) F_23 ( V_88 ) ;
return 0 ;
}
static int T_5 F_24 ( void )
{
return F_25 ( & V_89 ) ;
}
static void T_6 F_26 ( void )
{
F_27 ( & V_89 ) ;
}
