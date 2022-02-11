static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 , int * V_4 )
{
int V_5 = 0 ;
int V_6 = V_7 ;
do {
V_5 = F_6 ( V_3 -> V_8 + V_9 ) ;
if ( V_5 & ( V_10 | V_11 ) )
return V_5 ;
if ( V_5 & V_12 ) {
* V_4 = F_6 ( V_3 -> V_8 + V_13 ) ;
return 0 ;
}
} while ( -- V_6 > 0 );
return - V_14 ;
}
static int F_7 ( struct V_2 * V_3 , int * V_4 )
{
int V_15 , V_16 ;
int V_17 ;
V_17 = F_5 ( V_3 , & V_15 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_5 ( V_3 , & V_16 ) ;
if ( V_17 )
return V_17 ;
* V_4 = ( V_16 << 8 ) + V_15 ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , unsigned int V_4 )
{
int V_5 = 0 ;
int V_6 = V_7 ;
do {
V_5 = F_6 ( V_3 -> V_8 + V_9 ) ;
if ( V_5 & V_10 )
return V_5 ;
if ( ! ( V_5 & V_18 ) ) {
F_9 ( V_4 & 0xff , V_3 -> V_8 + V_13 ) ;
return 0 ;
}
#if 0
if (stat & DT_S_READY) {
printk
("dt2801: ready flag set (bad!) in dt2801_writedata()\n");
return -EIO;
}
#endif
} while ( -- V_6 > 0 );
return - V_14 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned int V_4 )
{
int V_17 ;
V_17 = F_8 ( V_3 , V_4 & 0xff ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_8 ( V_3 , ( V_4 >> 8 ) ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 )
{
int V_6 = V_7 ;
int V_5 ;
V_5 = F_6 ( V_3 -> V_8 + V_9 ) ;
if ( V_5 & V_11 )
return 0 ;
do {
V_5 = F_6 ( V_3 -> V_8 + V_9 ) ;
if ( V_5 & V_10 )
return V_5 ;
if ( V_5 & V_11 )
return 0 ;
} while ( -- V_6 > 0 );
return - V_14 ;
}
static int F_12 ( struct V_2 * V_3 , int V_19 )
{
int V_5 ;
F_11 ( V_3 ) ;
V_5 = F_6 ( V_3 -> V_8 + V_9 ) ;
if ( V_5 & V_10 ) {
F_13
( L_1 ) ;
}
if ( ! ( V_5 & V_11 ) )
F_13 ( L_2 ) ;
F_9 ( V_19 , V_3 -> V_8 + V_20 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
int V_21 = 0 ;
unsigned int V_5 ;
int V_6 ;
F_15 ( L_3 ) ;
F_15 ( L_4 , F_6 ( V_3 -> V_8 ) ,
F_6 ( V_3 -> V_8 + 1 ) ) ;
F_6 ( V_3 -> V_8 + V_13 ) ;
F_6 ( V_3 -> V_8 + V_13 ) ;
F_6 ( V_3 -> V_8 + V_13 ) ;
F_6 ( V_3 -> V_8 + V_13 ) ;
F_15 ( L_5 ) ;
F_9 ( V_22 , V_3 -> V_8 + V_20 ) ;
F_16 ( 100 ) ;
V_6 = 10000 ;
do {
V_5 = F_6 ( V_3 -> V_8 + V_9 ) ;
if ( V_5 & V_11 )
break;
} while ( V_6 -- );
if ( ! V_6 )
F_13 ( L_6 , V_5 ) ;
F_15 ( L_7 ) ;
F_9 ( V_23 , V_3 -> V_8 + V_20 ) ;
F_16 ( 100 ) ;
V_6 = 10000 ;
do {
V_5 = F_6 ( V_3 -> V_8 + V_9 ) ;
if ( V_5 & V_11 )
break;
} while ( V_6 -- );
if ( ! V_6 )
F_13 ( L_8 , V_5 ) ;
F_15 ( L_9 ) ;
F_5 ( V_3 , & V_21 ) ;
F_15 ( L_10 , V_21 ) ;
return V_21 ;
}
static int F_17 ( struct V_2 * V_3 )
{
int V_24 ;
int V_5 ;
int V_4 ;
for ( V_24 = 0 ; V_24 < 16 ; V_24 ++ ) {
V_5 = F_12 ( V_3 , V_25 ) ;
F_8 ( V_3 , 0 ) ;
F_8 ( V_3 , V_24 ) ;
V_5 = F_7 ( V_3 , & V_4 ) ;
if ( V_5 )
break;
}
F_14 ( V_3 ) ;
F_14 ( V_3 ) ;
return V_24 ;
}
static const struct V_26 * F_18 ( int V_27 )
{
if ( V_27 < 0 || V_27 >= 5 )
return & V_28 ;
return V_29 [ V_27 ] ;
}
static const struct V_26 * F_19 ( int type , int V_27 )
{
switch ( type ) {
case 0 :
return ( V_27 ) ?
& V_30 :
& V_31 ;
case 1 :
return ( V_27 ) ? & V_32 : & V_33 ;
case 2 :
return & V_34 ;
}
return & V_28 ;
}
static int F_20 ( struct V_2 * V_3 , struct V_35 * V_36 )
{
struct V_37 * V_38 ;
unsigned long V_8 ;
int V_21 , type ;
int V_17 = 0 ;
int V_39 ;
V_8 = V_36 -> V_40 [ 0 ] ;
if ( ! F_21 ( V_8 , V_41 , L_11 ) ) {
F_22 ( V_3 , L_12 ) ;
return - V_42 ;
}
V_3 -> V_8 = V_8 ;
V_21 = F_14 ( V_3 ) ;
if ( ! V_21 )
V_21 = F_14 ( V_3 ) ;
for ( type = 0 ; type < F_23 ( V_43 ) ; type ++ ) {
if ( V_43 [ type ] . V_44 == V_21 )
goto V_45;
}
F_13 ( L_13 ,
V_21 ) ;
type = 0 ;
V_45:
V_3 -> V_46 = V_43 + type ;
F_13 ( L_14 , V_47 . V_48 , V_8 ) ;
V_39 = F_17 ( V_3 ) ;
F_13 ( L_15 , V_39 ) ;
V_17 = F_24 ( V_3 , 4 ) ;
if ( V_17 < 0 )
goto V_49;
V_17 = F_25 ( V_3 , sizeof( struct V_50 ) ) ;
if ( V_17 < 0 )
goto V_49;
V_3 -> V_51 = V_47 . V_48 ;
V_38 = V_3 -> V_52 + 0 ;
V_38 -> type = V_53 ;
V_38 -> V_54 = V_55 | V_56 ;
#if 1
V_38 -> V_57 = V_39 ;
#else
if ( V_36 -> V_40 [ 2 ] )
V_38 -> V_57 = V_47 . V_58 ;
else
V_38 -> V_57 = V_47 . V_58 / 2 ;
#endif
V_38 -> V_59 = ( 1 << V_47 . V_60 ) - 1 ;
V_38 -> V_61 = F_19 ( V_47 . V_62 , V_36 -> V_40 [ 3 ] ) ;
V_38 -> V_63 = V_64 ;
V_38 ++ ;
V_38 -> type = V_65 ;
V_38 -> V_54 = V_66 ;
V_38 -> V_57 = 2 ;
V_38 -> V_59 = ( 1 << V_47 . V_67 ) - 1 ;
V_38 -> V_68 = V_69 -> V_70 ;
V_69 -> V_70 [ 0 ] = F_18 ( V_36 -> V_40 [ 4 ] ) ;
V_69 -> V_70 [ 1 ] = F_18 ( V_36 -> V_40 [ 5 ] ) ;
V_38 -> V_63 = V_71 ;
V_38 -> V_72 = V_73 ;
V_38 ++ ;
V_38 -> type = V_74 ;
V_38 -> V_54 = V_55 | V_66 ;
V_38 -> V_57 = 8 ;
V_38 -> V_59 = 1 ;
V_38 -> V_61 = & V_75 ;
V_38 -> V_76 = V_77 ;
V_38 -> V_78 = V_79 ;
V_38 ++ ;
V_38 -> type = V_74 ;
V_38 -> V_54 = V_55 | V_66 ;
V_38 -> V_57 = 8 ;
V_38 -> V_59 = 1 ;
V_38 -> V_61 = & V_75 ;
V_38 -> V_76 = V_77 ;
V_38 -> V_78 = V_79 ;
V_17 = 0 ;
V_49:
F_13 ( L_16 ) ;
return V_17 ;
}
static int F_26 ( struct V_2 * V_3 )
{
if ( V_3 -> V_8 )
F_27 ( V_3 -> V_8 , V_41 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , int V_5 )
{
if ( V_5 < 0 ) {
if ( V_5 == - V_14 )
F_13 ( L_17 ) ;
else
F_13 ( L_18 , V_5 ) ;
return V_5 ;
}
F_13 ( L_19 , V_5 ) ;
F_14 ( V_3 ) ;
F_14 ( V_3 ) ;
return - V_42 ;
}
static int V_64 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_80 * V_81 , unsigned int * V_4 )
{
int V_82 ;
int V_5 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_81 -> V_84 ; V_83 ++ ) {
V_5 = F_12 ( V_3 , V_25 ) ;
F_8 ( V_3 , F_29 ( V_81 -> V_85 ) ) ;
F_8 ( V_3 , F_30 ( V_81 -> V_85 ) ) ;
V_5 = F_7 ( V_3 , & V_82 ) ;
if ( V_5 != 0 )
return F_28 ( V_3 , V_5 ) ;
V_4 [ V_83 ] = V_82 ;
}
return V_83 ;
}
static int V_71 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_80 * V_81 , unsigned int * V_4 )
{
V_4 [ 0 ] = V_69 -> V_86 [ F_30 ( V_81 -> V_85 ) ] ;
return 1 ;
}
static int V_73 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_80 * V_81 , unsigned int * V_4 )
{
F_12 ( V_3 , V_87 ) ;
F_8 ( V_3 , F_30 ( V_81 -> V_85 ) ) ;
F_10 ( V_3 , V_4 [ 0 ] ) ;
V_69 -> V_86 [ F_30 ( V_81 -> V_85 ) ] = V_4 [ 0 ] ;
return 1 ;
}
static int V_77 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_80 * V_81 , unsigned int * V_4 )
{
int V_88 = 0 ;
if ( V_38 == V_3 -> V_52 + 4 )
V_88 = 1 ;
if ( V_81 -> V_84 != 2 )
return - V_89 ;
if ( V_4 [ 0 ] ) {
V_38 -> V_90 &= ~ V_4 [ 0 ] ;
V_38 -> V_90 |= ( V_4 [ 0 ] & V_4 [ 1 ] ) ;
F_12 ( V_3 , V_91 ) ;
F_8 ( V_3 , V_88 ) ;
F_8 ( V_3 , V_38 -> V_90 ) ;
}
F_12 ( V_3 , V_92 ) ;
F_8 ( V_3 , V_88 ) ;
F_5 ( V_3 , V_4 + 1 ) ;
return 2 ;
}
static int V_79 ( struct V_2 * V_3 ,
struct V_37 * V_38 ,
struct V_80 * V_81 , unsigned int * V_4 )
{
int V_88 = 0 ;
if ( V_38 == V_3 -> V_52 + 4 )
V_88 = 1 ;
switch ( V_4 [ 0 ] ) {
case V_93 :
V_38 -> V_94 = 0xff ;
F_12 ( V_3 , V_95 ) ;
break;
case V_96 :
V_38 -> V_94 = 0 ;
F_12 ( V_3 , V_97 ) ;
break;
case V_98 :
V_4 [ 1 ] = V_38 -> V_94 ? V_99 : V_100 ;
return V_81 -> V_84 ;
default:
return - V_89 ;
}
F_8 ( V_3 , V_88 ) ;
return 1 ;
}
