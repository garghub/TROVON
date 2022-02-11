static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = NULL ;
int V_9 ;
F_2 ( L_1 , V_2 -> V_10 ) ;
if ( F_3 ( V_2 , sizeof( struct V_11 ) ) < 0 )
return - V_12 ;
F_2 ( L_2 ) ;
F_4 (pcidev) {
if ( V_8 -> V_13 != V_14 )
continue;
for ( V_9 = 0 ; V_9 < V_15 ; V_9 ++ ) {
if ( V_16 [ V_9 ] . V_17 !=
V_8 -> V_18 )
continue;
if ( V_4 -> V_19 [ 0 ] || V_4 -> V_19 [ 1 ] ) {
if ( V_8 -> V_20 -> V_21 != V_4 -> V_19 [ 0 ] ||
F_5 ( V_8 -> V_22 ) != V_4 -> V_19 [ 1 ] ) {
continue;
}
}
V_23 -> V_7 = V_8 ;
V_2 -> V_24 = V_16 + V_9 ;
goto V_25;
}
}
F_2 ( L_3
L_4 ) ;
return - V_26 ;
V_25:
F_2 ( L_5 , V_16 [ V_9 ] . V_27 ,
V_8 -> V_20 -> V_21 , F_5 ( V_8 -> V_22 ) ) ;
switch ( V_28 -> V_17 ) {
case 0x56 :
break;
default:
F_2 ( L_6
L_7 ) ;
}
if ( F_6 ( V_8 , L_8 ) ) {
F_2 ( L_9 ) ;
return - V_26 ;
}
V_23 -> V_29 = F_7 ( V_23 -> V_7 , 0 ) ;
V_23 -> V_30 = F_7 ( V_23 -> V_7 , 1 ) ;
V_23 -> V_31 = F_7 ( V_23 -> V_7 , 2 ) ;
V_23 -> V_32 = F_7 ( V_23 -> V_7 , 3 ) ;
V_23 -> V_33 = F_7 ( V_23 -> V_7 , 4 ) ;
#ifdef F_8
F_2 ( L_10 , V_23 -> V_29 ) ;
F_2 ( L_11 , V_23 -> V_30 ) ;
F_2 ( L_12 , V_23 -> V_31 ) ;
F_2 ( L_13 , V_23 -> V_32 ) ;
F_2 ( L_14 , V_23 -> V_33 ) ;
#endif
V_2 -> V_34 = V_28 -> V_27 ;
if ( F_9 ( V_2 , 3 ) < 0 )
return - V_12 ;
V_6 = V_2 -> V_35 + 0 ;
V_6 -> type = V_36 ;
V_6 -> V_37 = V_38 | V_39 ;
V_6 -> V_40 = V_28 -> V_41 ;
V_6 -> V_42 = ( 1 << V_28 -> V_43 ) - 1 ;
V_6 -> V_44 = & V_45 ;
V_6 -> V_46 = 1 ;
V_6 -> V_47 = V_48 ;
V_6 = V_2 -> V_35 + 1 ;
V_6 -> type = V_49 ;
V_6 -> V_37 = V_50 ;
V_6 -> V_40 = V_28 -> V_51 ;
V_6 -> V_42 = 1 << V_28 -> V_52 ;
V_6 -> V_44 = & V_45 ;
V_6 -> V_53 = & V_54 ;
V_6 -> V_47 = & V_55 ;
V_6 = V_2 -> V_35 + 2 ;
if ( V_28 -> V_56 )
F_10 ( V_2 , V_6 , NULL , V_23 -> V_33 ) ;
else
V_6 -> type = V_57 ;
F_2 ( L_15 ) ;
return 1 ;
}
static int F_11 ( struct V_1 * V_2 )
{
#ifdef F_8
if ( V_23 ) {
F_2 ( L_10 , V_23 -> V_29 ) ;
F_2 ( L_11 , V_23 -> V_30 ) ;
F_2 ( L_12 , V_23 -> V_31 ) ;
F_2 ( L_13 , V_23 -> V_32 ) ;
F_2 ( L_14 , V_23 -> V_33 ) ;
}
#endif
F_2 ( L_16 , V_2 -> V_10 ) ;
if ( V_2 -> V_58 )
F_12 ( V_2 -> V_58 , V_2 ) ;
if ( V_23 ) {
if ( V_23 -> V_7 ) {
if ( V_23 -> V_29 )
F_13 ( V_23 -> V_7 ) ;
F_14 ( V_23 -> V_7 ) ;
}
}
return 0 ;
}
static int V_48 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_59 * V_60 , unsigned int * V_61 )
{
int V_62 , V_63 ;
unsigned int V_64 ;
unsigned int V_65 ;
int V_66 = F_15 ( V_60 -> V_67 ) ;
unsigned short V_68 ;
int V_69 ;
if ( ( F_16 ( V_23 -> V_32 + 2 ) & 0x20 ) == 0 )
V_69 = V_28 -> V_70 ;
else
V_69 = V_28 -> V_41 ;
if ( V_66 > ( V_69 - 1 ) )
return - V_71 ;
V_64 = F_16 ( V_23 -> V_32 + 5 ) ;
if ( ( V_64 & 0x03 ) > 0 ) {
V_64 = V_64 & 0xfd ;
F_17 ( V_64 , V_23 -> V_32 + 5 ) ;
}
F_17 ( 0x01 , V_23 -> V_32 + 6 ) ;
F_17 ( 0x00 , V_23 -> V_32 + 7 ) ;
V_68 = V_66 | ( V_66 << 4 ) ;
F_17 ( V_68 , V_23 -> V_32 + 0 ) ;
for ( V_62 = 0 ; V_62 < V_60 -> V_62 ; V_62 ++ ) {
F_18 ( 0 , V_23 -> V_31 + 0 ) ;
#define F_19 1000
for ( V_63 = 0 ; V_63 < F_19 ; V_63 ++ ) {
V_65 = F_16 ( V_23 -> V_32 + 2 ) & 0x80 ;
if ( ! V_65 )
break;
}
if ( V_63 == F_19 ) {
F_2 ( L_17 ) ;
return - V_71 ;
}
V_64 = F_20 ( V_23 -> V_31 + 0 ) ;
V_61 [ V_62 ] = V_64 ;
}
return V_62 ;
}
static int V_54 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_59 * V_60 , unsigned int * V_61 )
{
int V_63 ;
int V_66 = F_15 ( V_60 -> V_67 ) ;
for ( V_63 = 0 ; V_63 < V_60 -> V_62 ; V_63 ++ ) {
switch ( V_66 ) {
case 0 :
F_18 ( V_61 [ V_63 ] & 0x0FFF , V_23 -> V_31 + V_72 ) ;
break;
case 1 :
F_18 ( V_61 [ V_63 ] & 0x0FFF , V_23 -> V_31 + V_73 ) ;
break;
default:
return - 1 ;
}
V_23 -> V_74 [ V_66 ] = V_61 [ V_63 ] ;
}
return V_63 ;
}
static int V_55 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_59 * V_60 , unsigned int * V_61 )
{
int V_63 ;
int V_66 = F_15 ( V_60 -> V_67 ) ;
for ( V_63 = 0 ; V_63 < V_60 -> V_62 ; V_63 ++ )
V_61 [ V_63 ] = V_23 -> V_74 [ V_66 ] ;
return V_63 ;
}
static int T_1 F_21 ( struct V_7 * V_2 ,
const struct V_75
* V_76 )
{
return F_22 ( V_2 , V_77 . V_78 ) ;
}
static void T_2 F_23 ( struct V_7 * V_2 )
{
F_24 ( V_2 ) ;
}
static int T_3 F_25 ( void )
{
int V_79 ;
V_79 = F_26 ( & V_77 ) ;
if ( V_79 < 0 )
return V_79 ;
V_80 . V_27 =
( char * ) V_77 . V_78 ;
return F_27 ( & V_80 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_80 ) ;
F_30 ( & V_77 ) ;
}
