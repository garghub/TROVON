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
struct V_43 * V_44 = V_2 -> V_45 ;
V_3 [ 0 ] = V_44 -> V_46 [ F_19 ( V_38 -> V_42 ) ] ;
return 1 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_37 * V_38 , unsigned int * V_3 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
F_8 ( V_2 , V_47 ) ;
F_4 ( V_2 , F_19 ( V_38 -> V_42 ) ) ;
F_6 ( V_2 , V_3 [ 0 ] ) ;
V_44 -> V_46 [ F_19 ( V_38 -> V_42 ) ] = V_3 [ 0 ] ;
return 1 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_37 * V_38 , unsigned int * V_3 )
{
int V_48 = 0 ;
if ( V_36 == & V_2 -> V_49 [ 3 ] )
V_48 = 1 ;
if ( V_3 [ 0 ] ) {
V_36 -> V_50 &= ~ V_3 [ 0 ] ;
V_36 -> V_50 |= ( V_3 [ 0 ] & V_3 [ 1 ] ) ;
F_8 ( V_2 , V_51 ) ;
F_4 ( V_2 , V_48 ) ;
F_4 ( V_2 , V_36 -> V_50 ) ;
}
F_8 ( V_2 , V_52 ) ;
F_4 ( V_2 , V_48 ) ;
F_1 ( V_2 , V_3 + 1 ) ;
return V_38 -> V_41 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_37 * V_38 , unsigned int * V_3 )
{
int V_48 = 0 ;
if ( V_36 == & V_2 -> V_49 [ 3 ] )
V_48 = 1 ;
switch ( V_3 [ 0 ] ) {
case V_53 :
V_36 -> V_54 = 0xff ;
F_8 ( V_2 , V_55 ) ;
break;
case V_56 :
V_36 -> V_54 = 0 ;
F_8 ( V_2 , V_57 ) ;
break;
case V_58 :
V_3 [ 1 ] = V_36 -> V_54 ? V_59 : V_60 ;
return V_38 -> V_41 ;
default:
return - V_61 ;
}
F_4 ( V_2 , V_48 ) ;
return 1 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
const struct V_64 * V_65 = F_25 ( V_2 ) ;
struct V_43 * V_44 ;
struct V_35 * V_36 ;
int V_20 , type ;
int V_16 = 0 ;
int V_66 ;
V_16 = F_26 ( V_2 , V_63 -> V_67 [ 0 ] , V_68 ) ;
if ( V_16 )
return V_16 ;
V_20 = F_10 ( V_2 ) ;
if ( ! V_20 )
V_20 = F_10 ( V_2 ) ;
for ( type = 0 ; type < F_27 ( V_69 ) ; type ++ ) {
if ( V_69 [ type ] . V_70 == V_20 )
goto V_71;
}
F_9 ( L_14 ,
V_20 ) ;
type = 0 ;
V_71:
V_2 -> V_72 = V_69 + type ;
V_65 = F_25 ( V_2 ) ;
V_66 = F_13 ( V_2 ) ;
V_16 = F_28 ( V_2 , 4 ) ;
if ( V_16 )
goto V_73;
V_44 = F_29 ( sizeof( * V_44 ) , V_74 ) ;
if ( ! V_44 )
return - V_75 ;
V_2 -> V_45 = V_44 ;
V_2 -> V_76 = V_65 -> V_77 ;
V_36 = & V_2 -> V_49 [ 0 ] ;
V_36 -> type = V_78 ;
V_36 -> V_79 = V_80 | V_81 ;
#if 1
V_36 -> V_82 = V_66 ;
#else
if ( V_63 -> V_67 [ 2 ] )
V_36 -> V_82 = V_65 -> V_83 ;
else
V_36 -> V_82 = V_65 -> V_83 / 2 ;
#endif
V_36 -> V_84 = ( 1 << V_65 -> V_85 ) - 1 ;
V_36 -> V_86 = F_15 ( V_65 -> V_87 , V_63 -> V_67 [ 3 ] ) ;
V_36 -> V_88 = F_17 ;
V_36 = & V_2 -> V_49 [ 1 ] ;
V_36 -> type = V_89 ;
V_36 -> V_79 = V_90 ;
V_36 -> V_82 = 2 ;
V_36 -> V_84 = ( 1 << V_65 -> V_91 ) - 1 ;
V_36 -> V_92 = V_44 -> V_93 ;
V_44 -> V_93 [ 0 ] = F_14 ( V_63 -> V_67 [ 4 ] ) ;
V_44 -> V_93 [ 1 ] = F_14 ( V_63 -> V_67 [ 5 ] ) ;
V_36 -> V_88 = F_20 ;
V_36 -> V_94 = F_21 ;
V_36 = & V_2 -> V_49 [ 2 ] ;
V_36 -> type = V_95 ;
V_36 -> V_79 = V_80 | V_90 ;
V_36 -> V_82 = 8 ;
V_36 -> V_84 = 1 ;
V_36 -> V_86 = & V_96 ;
V_36 -> V_97 = F_22 ;
V_36 -> V_98 = F_23 ;
V_36 = & V_2 -> V_49 [ 3 ] ;
V_36 -> type = V_95 ;
V_36 -> V_79 = V_80 | V_90 ;
V_36 -> V_82 = 8 ;
V_36 -> V_84 = 1 ;
V_36 -> V_86 = & V_96 ;
V_36 -> V_97 = F_22 ;
V_36 -> V_98 = F_23 ;
V_16 = 0 ;
V_73:
return V_16 ;
}
