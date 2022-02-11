static int F_1 ( struct V_1 * V_2 , int * V_3 )
{
int V_4 = 0 ;
int V_5 = V_6 ;
do {
V_4 = F_2 ( V_2 -> V_7 + V_8 ) ;
if ( V_4 & ( V_9 | V_10 ) )
return V_4 ;
if ( V_4 & V_11 ) {
* V_3 = F_2 ( V_2 -> V_7 + V_12 ) ;
return 0 ;
}
} while ( -- V_5 > 0 );
return - V_13 ;
}
static int F_3 ( struct V_1 * V_2 , int * V_3 )
{
int V_14 , V_15 ;
int V_16 ;
V_16 = F_1 ( V_2 , & V_14 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_1 ( V_2 , & V_15 ) ;
if ( V_16 )
return V_16 ;
* V_3 = ( V_15 << 8 ) + V_14 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 = 0 ;
int V_5 = V_6 ;
do {
V_4 = F_2 ( V_2 -> V_7 + V_8 ) ;
if ( V_4 & V_9 )
return V_4 ;
if ( ! ( V_4 & V_17 ) ) {
F_5 ( V_3 & 0xff , V_2 -> V_7 + V_12 ) ;
return 0 ;
}
#if 0
if (stat & DT_S_READY) {
printk
("dt2801: ready flag set (bad!) in dt2801_writedata()\n");
return -EIO;
}
#endif
} while ( -- V_5 > 0 );
return - V_13 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_16 ;
V_16 = F_4 ( V_2 , V_3 & 0xff ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_4 ( V_2 , ( V_3 >> 8 ) ) ;
if ( V_16 < 0 )
return V_16 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_5 = V_6 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_7 + V_8 ) ;
if ( V_4 & V_10 )
return 0 ;
do {
V_4 = F_2 ( V_2 -> V_7 + V_8 ) ;
if ( V_4 & V_9 )
return V_4 ;
if ( V_4 & V_10 )
return 0 ;
} while ( -- V_5 > 0 );
return - V_13 ;
}
static int F_8 ( struct V_1 * V_2 , int V_18 )
{
int V_4 ;
F_7 ( V_2 ) ;
V_4 = F_2 ( V_2 -> V_7 + V_8 ) ;
if ( V_4 & V_9 ) {
F_9
( L_1 ) ;
}
if ( ! ( V_4 & V_10 ) )
F_9 ( L_2 ) ;
F_5 ( V_18 , V_2 -> V_7 + V_19 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_20 = 0 ;
unsigned int V_4 ;
int V_5 ;
F_11 ( L_3 ) ;
F_11 ( L_4 , F_2 ( V_2 -> V_7 ) ,
F_2 ( V_2 -> V_7 + 1 ) ) ;
F_2 ( V_2 -> V_7 + V_12 ) ;
F_2 ( V_2 -> V_7 + V_12 ) ;
F_2 ( V_2 -> V_7 + V_12 ) ;
F_2 ( V_2 -> V_7 + V_12 ) ;
F_11 ( L_5 ) ;
F_5 ( V_21 , V_2 -> V_7 + V_19 ) ;
F_12 ( 100 ) ;
V_5 = 10000 ;
do {
V_4 = F_2 ( V_2 -> V_7 + V_8 ) ;
if ( V_4 & V_10 )
break;
} while ( V_5 -- );
if ( ! V_5 )
F_9 ( L_6 , V_4 ) ;
F_11 ( L_7 ) ;
F_5 ( V_22 , V_2 -> V_7 + V_19 ) ;
F_12 ( 100 ) ;
V_5 = 10000 ;
do {
V_4 = F_2 ( V_2 -> V_7 + V_8 ) ;
if ( V_4 & V_10 )
break;
} while ( V_5 -- );
if ( ! V_5 )
F_9 ( L_8 , V_4 ) ;
F_11 ( L_9 ) ;
F_1 ( V_2 , & V_20 ) ;
F_11 ( L_10 , V_20 ) ;
return V_20 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_23 ;
int V_4 ;
int V_3 ;
for ( V_23 = 0 ; V_23 < 16 ; V_23 ++ ) {
V_4 = F_8 ( V_2 , V_24 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_23 ) ;
V_4 = F_3 ( V_2 , & V_3 ) ;
if ( V_4 )
break;
}
F_10 ( V_2 ) ;
F_10 ( V_2 ) ;
return V_23 ;
}
static const struct V_25 * F_14 ( int V_26 )
{
if ( V_26 < 0 || V_26 >= 5 )
return & V_27 ;
return V_28 [ V_26 ] ;
}
static const struct V_25 * F_15 ( int type , int V_26 )
{
switch ( type ) {
case 0 :
return ( V_26 ) ?
& V_29 :
& V_30 ;
case 1 :
return ( V_26 ) ? & V_31 : & V_32 ;
case 2 :
return & V_33 ;
}
return & V_27 ;
}
static int F_16 ( struct V_1 * V_2 , int V_4 )
{
if ( V_4 < 0 ) {
if ( V_4 == - V_13 )
F_9 ( L_11 ) ;
else
F_9 ( L_12 , V_4 ) ;
return V_4 ;
}
F_9 ( L_13 , V_4 ) ;
F_10 ( V_2 ) ;
F_10 ( V_2 ) ;
return - V_34 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_37 * V_38 , unsigned int * V_3 )
{
int V_39 ;
int V_4 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_38 -> V_41 ; V_40 ++ ) {
V_4 = F_8 ( V_2 , V_24 ) ;
F_4 ( V_2 , F_18 ( V_38 -> V_42 ) ) ;
F_4 ( V_2 , F_19 ( V_38 -> V_42 ) ) ;
V_4 = F_3 ( V_2 , & V_39 ) ;
if ( V_4 != 0 )
return F_16 ( V_2 , V_4 ) ;
V_3 [ V_40 ] = V_39 ;
}
return V_40 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_37 * V_38 , unsigned int * V_3 )
{
V_3 [ 0 ] = V_43 -> V_44 [ F_19 ( V_38 -> V_42 ) ] ;
return 1 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_37 * V_38 , unsigned int * V_3 )
{
F_8 ( V_2 , V_45 ) ;
F_4 ( V_2 , F_19 ( V_38 -> V_42 ) ) ;
F_6 ( V_2 , V_3 [ 0 ] ) ;
V_43 -> V_44 [ F_19 ( V_38 -> V_42 ) ] = V_3 [ 0 ] ;
return 1 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_37 * V_38 , unsigned int * V_3 )
{
int V_46 = 0 ;
if ( V_36 == V_2 -> V_47 + 4 )
V_46 = 1 ;
if ( V_38 -> V_41 != 2 )
return - V_48 ;
if ( V_3 [ 0 ] ) {
V_36 -> V_49 &= ~ V_3 [ 0 ] ;
V_36 -> V_49 |= ( V_3 [ 0 ] & V_3 [ 1 ] ) ;
F_8 ( V_2 , V_50 ) ;
F_4 ( V_2 , V_46 ) ;
F_4 ( V_2 , V_36 -> V_49 ) ;
}
F_8 ( V_2 , V_51 ) ;
F_4 ( V_2 , V_46 ) ;
F_1 ( V_2 , V_3 + 1 ) ;
return 2 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_37 * V_38 , unsigned int * V_3 )
{
int V_46 = 0 ;
if ( V_36 == V_2 -> V_47 + 4 )
V_46 = 1 ;
switch ( V_3 [ 0 ] ) {
case V_52 :
V_36 -> V_53 = 0xff ;
F_8 ( V_2 , V_54 ) ;
break;
case V_55 :
V_36 -> V_53 = 0 ;
F_8 ( V_2 , V_56 ) ;
break;
case V_57 :
V_3 [ 1 ] = V_36 -> V_53 ? V_58 : V_59 ;
return V_38 -> V_41 ;
default:
return - V_48 ;
}
F_4 ( V_2 , V_46 ) ;
return 1 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_35 * V_36 ;
unsigned long V_7 ;
int V_20 , type ;
int V_16 = 0 ;
int V_62 ;
V_7 = V_61 -> V_63 [ 0 ] ;
if ( ! F_25 ( V_7 , V_64 , L_14 ) ) {
F_26 ( V_2 , L_15 ) ;
return - V_34 ;
}
V_2 -> V_7 = V_7 ;
V_20 = F_10 ( V_2 ) ;
if ( ! V_20 )
V_20 = F_10 ( V_2 ) ;
for ( type = 0 ; type < F_27 ( V_65 ) ; type ++ ) {
if ( V_65 [ type ] . V_66 == V_20 )
goto V_67;
}
F_9 ( L_16 ,
V_20 ) ;
type = 0 ;
V_67:
V_2 -> V_68 = V_65 + type ;
F_9 ( L_17 , V_69 . V_70 , V_7 ) ;
V_62 = F_13 ( V_2 ) ;
F_9 ( L_18 , V_62 ) ;
V_16 = F_28 ( V_2 , 4 ) ;
if ( V_16 < 0 )
goto V_71;
V_16 = F_29 ( V_2 , sizeof( struct V_72 ) ) ;
if ( V_16 < 0 )
goto V_71;
V_2 -> V_73 = V_69 . V_70 ;
V_36 = V_2 -> V_47 + 0 ;
V_36 -> type = V_74 ;
V_36 -> V_75 = V_76 | V_77 ;
#if 1
V_36 -> V_78 = V_62 ;
#else
if ( V_61 -> V_63 [ 2 ] )
V_36 -> V_78 = V_69 . V_79 ;
else
V_36 -> V_78 = V_69 . V_79 / 2 ;
#endif
V_36 -> V_80 = ( 1 << V_69 . V_81 ) - 1 ;
V_36 -> V_82 = F_15 ( V_69 . V_83 , V_61 -> V_63 [ 3 ] ) ;
V_36 -> V_84 = F_17 ;
V_36 ++ ;
V_36 -> type = V_85 ;
V_36 -> V_75 = V_86 ;
V_36 -> V_78 = 2 ;
V_36 -> V_80 = ( 1 << V_69 . V_87 ) - 1 ;
V_36 -> V_88 = V_43 -> V_89 ;
V_43 -> V_89 [ 0 ] = F_14 ( V_61 -> V_63 [ 4 ] ) ;
V_43 -> V_89 [ 1 ] = F_14 ( V_61 -> V_63 [ 5 ] ) ;
V_36 -> V_84 = F_20 ;
V_36 -> V_90 = F_21 ;
V_36 ++ ;
V_36 -> type = V_91 ;
V_36 -> V_75 = V_76 | V_86 ;
V_36 -> V_78 = 8 ;
V_36 -> V_80 = 1 ;
V_36 -> V_82 = & V_92 ;
V_36 -> V_93 = F_22 ;
V_36 -> V_94 = F_23 ;
V_36 ++ ;
V_36 -> type = V_91 ;
V_36 -> V_75 = V_76 | V_86 ;
V_36 -> V_78 = 8 ;
V_36 -> V_80 = 1 ;
V_36 -> V_82 = & V_92 ;
V_36 -> V_93 = F_22 ;
V_36 -> V_94 = F_23 ;
V_16 = 0 ;
V_71:
F_9 ( L_19 ) ;
return V_16 ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 )
F_31 ( V_2 -> V_7 , V_64 ) ;
}
