static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = NULL ;
int V_9 ;
if ( F_2 ( V_2 , sizeof( struct V_10 ) ) < 0 )
return - V_11 ;
F_3 (pcidev) {
if ( V_8 -> V_12 != V_13 )
continue;
for ( V_9 = 0 ; V_9 < V_14 ; V_9 ++ ) {
if ( V_15 [ V_9 ] . V_16 !=
V_8 -> V_17 )
continue;
if ( V_4 -> V_18 [ 0 ] || V_4 -> V_18 [ 1 ] ) {
if ( V_8 -> V_19 -> V_20 != V_4 -> V_18 [ 0 ] ||
F_4 ( V_8 -> V_21 ) != V_4 -> V_18 [ 1 ] ) {
continue;
}
}
V_22 -> V_7 = V_8 ;
V_2 -> V_23 = V_15 + V_9 ;
goto V_24;
}
}
F_5 ( V_2 -> V_25 , L_1 ) ;
return - V_26 ;
V_24:
F_6 ( V_2 -> V_25 , L_2 ,
V_15 [ V_9 ] . V_27 , V_8 -> V_19 -> V_20 ,
F_4 ( V_8 -> V_21 ) ) ;
switch ( V_28 -> V_16 ) {
case 0x56 :
break;
default:
F_6 ( V_2 -> V_25 , L_3
L_4 ) ;
}
if ( F_7 ( V_8 , L_5 ) ) {
F_5 ( V_2 -> V_25 , L_6 ) ;
return - V_26 ;
}
V_22 -> V_29 = F_8 ( V_22 -> V_7 , 0 ) ;
V_22 -> V_30 = F_8 ( V_22 -> V_7 , 1 ) ;
V_22 -> V_31 = F_8 ( V_22 -> V_7 , 2 ) ;
V_22 -> V_32 = F_8 ( V_22 -> V_7 , 3 ) ;
V_22 -> V_33 = F_8 ( V_22 -> V_7 , 4 ) ;
F_6 ( V_2 -> V_25 , L_7 , V_22 -> V_29 ) ;
F_6 ( V_2 -> V_25 , L_8 , V_22 -> V_30 ) ;
F_6 ( V_2 -> V_25 , L_9 , V_22 -> V_31 ) ;
F_6 ( V_2 -> V_25 , L_10 , V_22 -> V_32 ) ;
F_6 ( V_2 -> V_25 , L_11 , V_22 -> V_33 ) ;
V_2 -> V_34 = V_28 -> V_27 ;
if ( F_9 ( V_2 , 3 ) < 0 )
return - V_11 ;
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
F_10 ( V_2 , V_6 , NULL , V_22 -> V_33 ) ;
else
V_6 -> type = V_57 ;
return 1 ;
}
static void F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_58 )
F_12 ( V_2 -> V_58 , V_2 ) ;
if ( V_22 ) {
if ( V_22 -> V_7 ) {
if ( V_22 -> V_29 )
F_13 ( V_22 -> V_7 ) ;
F_14 ( V_22 -> V_7 ) ;
}
}
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
if ( ( F_16 ( V_22 -> V_32 + 2 ) & 0x20 ) == 0 )
V_69 = V_28 -> V_70 ;
else
V_69 = V_28 -> V_41 ;
if ( V_66 > ( V_69 - 1 ) )
return - V_71 ;
V_64 = F_16 ( V_22 -> V_32 + 5 ) ;
if ( ( V_64 & 0x03 ) > 0 ) {
V_64 = V_64 & 0xfd ;
F_17 ( V_64 , V_22 -> V_32 + 5 ) ;
}
F_17 ( 0x01 , V_22 -> V_32 + 6 ) ;
F_17 ( 0x00 , V_22 -> V_32 + 7 ) ;
V_68 = V_66 | ( V_66 << 4 ) ;
F_17 ( V_68 , V_22 -> V_32 + 0 ) ;
for ( V_62 = 0 ; V_62 < V_60 -> V_62 ; V_62 ++ ) {
F_18 ( 0 , V_22 -> V_31 + 0 ) ;
#define F_19 1000
for ( V_63 = 0 ; V_63 < F_19 ; V_63 ++ ) {
V_65 = F_16 ( V_22 -> V_32 + 2 ) & 0x80 ;
if ( ! V_65 )
break;
}
if ( V_63 == F_19 ) {
F_20 ( L_12 ) ;
return - V_71 ;
}
V_64 = F_21 ( V_22 -> V_31 + 0 ) ;
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
F_18 ( V_61 [ V_63 ] & 0x0FFF , V_22 -> V_31 + V_72 ) ;
break;
case 1 :
F_18 ( V_61 [ V_63 ] & 0x0FFF , V_22 -> V_31 + V_73 ) ;
break;
default:
return - 1 ;
}
V_22 -> V_74 [ V_66 ] = V_61 [ V_63 ] ;
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
V_61 [ V_63 ] = V_22 -> V_74 [ V_66 ] ;
return V_63 ;
}
static int T_1 F_22 ( struct V_7 * V_2 ,
const struct V_75 * V_76 )
{
return F_23 ( V_2 , & V_77 ) ;
}
static void T_2 F_24 ( struct V_7 * V_2 )
{
F_25 ( V_2 ) ;
}
