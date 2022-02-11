static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = 14745600 ;
}
static int F_2 ( struct V_1 * V_2 )
{
T_1 V_6 ;
int V_7 ;
V_7 = F_3 ( V_2 , 0x800 , & V_6 ) ;
if ( V_7 )
goto V_8;
V_7 = F_4 ( V_2 , 0x800 , V_6 | 1 ) ;
if ( V_7 )
goto V_8;
return 0 ;
V_8:
return - V_9 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
if ( V_11 -> V_13 > 1 )
V_11 -> V_13 = 1 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
if ( V_11 -> V_14 )
F_7 ( 12 , V_11 -> V_14 + 1 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_15 = V_11 -> V_14 ;
F_7 ( 0xA , V_15 + 1 ) ;
F_9 ( 100 ) ;
F_7 ( 0xE , V_15 + 1 ) ;
F_9 ( 300 ) ;
F_7 ( 0xC , V_15 + 1 ) ;
F_9 ( 100 ) ;
F_7 ( 0xE , V_15 + 1 ) ;
F_9 ( 200 ) ;
F_7 ( 0xF , V_15 + 1 ) ;
F_9 ( 100 ) ;
F_7 ( 0xE , V_15 + 1 ) ;
F_9 ( 100 ) ;
F_7 ( 0xC , V_15 + 1 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
if ( V_11 -> V_13 )
V_2 -> V_16 |= V_17 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_18 ;
F_12 ( & V_2 -> V_19 , L_1 ) ;
for ( V_18 = 0 ; V_18 < V_11 -> V_20 ; V_18 ++ )
F_13 ( V_11 -> line [ V_18 ] ) ;
if ( ! V_11 -> V_21 )
F_14 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_11 -> V_20 ; V_18 ++ )
F_16 ( V_11 -> line [ V_18 ] ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_11 -> V_20 ; V_18 ++ )
F_18 ( V_11 -> line [ V_18 ] ) ;
if ( V_11 -> V_22 && V_11 -> V_22 -> V_23 )
V_11 -> V_22 -> V_23 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_12 ( & V_2 -> V_19 , L_2 ) ;
V_11 = F_20 ( sizeof ( * V_11 ) , V_24 ) ;
if ( ! V_11 )
return - V_25 ;
V_11 -> V_26 = V_2 ;
V_2 -> V_12 = V_11 ;
V_2 -> V_16 |= V_27 ;
if ( V_28 )
V_2 -> V_16 |= V_29 ;
return F_21 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
F_12 ( & V_2 -> V_19 , L_3 ) ;
F_11 ( V_2 ) ;
F_23 ( V_11 ) ;
}
static int F_24 ( struct V_1 * V_30 , struct V_10 * V_11 ,
unsigned int V_31 , int V_32 )
{
struct V_3 V_4 ;
int line ;
memset ( & V_4 , 0 , sizeof ( struct V_3 ) ) ;
V_4 . V_31 = V_31 ;
V_4 . V_32 = V_32 ;
V_4 . V_33 = V_34 | V_35 | V_36 ;
V_4 . V_5 = 1843200 ;
V_4 . V_19 = & V_30 -> V_19 ;
if ( V_37 )
V_4 . V_33 |= V_38 ;
if ( V_11 -> V_22 && V_11 -> V_22 -> V_39 )
V_11 -> V_22 -> V_39 ( V_30 , & V_4 ) ;
line = F_25 ( & V_4 ) ;
if ( line < 0 ) {
F_26 ( V_40 L_4
L_5 , ( V_41 ) V_31 , V_32 ) ;
return - V_42 ;
}
V_11 -> line [ V_11 -> V_20 ] = line ;
V_11 -> V_20 ++ ;
return 0 ;
}
static int F_27 ( struct V_1 * V_26 )
{
unsigned int V_4 = 0 ;
struct V_10 * V_11 = V_26 -> V_12 ;
if ( ( V_26 -> V_43 [ 1 ] -> V_44 != 0 ) &&
( F_28 ( V_26 -> V_43 [ 1 ] ) == 8 ) ) {
V_4 = V_26 -> V_43 [ 1 ] -> V_45 ;
V_11 -> V_21 = 1 ;
} else if ( ( V_11 -> V_46 == V_47 ) &&
( F_28 ( V_26 -> V_43 [ 0 ] ) == 0x40 ) ) {
V_4 = V_26 -> V_43 [ 0 ] -> V_45 + 0x28 ;
V_11 -> V_21 = 1 ;
}
if ( V_11 -> V_21 )
return F_24 ( V_26 , V_11 , V_4 , V_26 -> V_32 ) ;
F_29 ( & V_26 -> V_19 , L_6 ) ;
return - V_9 ;
}
static int F_30 ( struct V_1 * V_26 , void * V_48 )
{
static const int V_49 [ 2 ] = { 8 , 16 } ;
int * V_50 = V_48 ;
if ( V_26 -> V_43 [ 0 ] -> V_45 == 0 )
return - V_9 ;
if ( ( * V_50 & 0x1 ) == 0 )
V_26 -> V_51 = 16 ;
if ( V_26 -> V_43 [ 0 ] -> V_44 != V_49 [ ( * V_50 >> 1 ) ] )
return - V_9 ;
V_26 -> V_43 [ 0 ] -> V_44 = 8 ;
V_26 -> V_43 [ 0 ] -> V_33 &= ~ V_52 ;
V_26 -> V_43 [ 0 ] -> V_33 |= V_53 ;
return F_31 ( V_26 ) ;
}
static int F_32 ( struct V_1 * V_26 ,
void * V_48 )
{
static const unsigned int V_54 [ 5 ] = { 0x3f8 , 0x2f8 , 0x3e8 , 0x2e8 , 0x0 } ;
int V_55 ;
if ( V_26 -> V_51 > 3 )
return - V_9 ;
V_26 -> V_43 [ 0 ] -> V_33 &= ~ V_52 ;
V_26 -> V_43 [ 0 ] -> V_33 |= V_53 ;
V_26 -> V_43 [ 0 ] -> V_44 = 8 ;
for ( V_55 = 0 ; V_55 < 5 ; V_55 ++ ) {
V_26 -> V_43 [ 0 ] -> V_45 = V_54 [ V_55 ] ;
V_26 -> V_51 = V_54 [ V_55 ] ? 16 : 3 ;
if ( ! F_31 ( V_26 ) )
return 0 ;
}
return - V_9 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_18 = - V_9 , V_50 ;
V_2 -> V_16 |= V_56 | V_57 ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ )
if ( ! F_34 ( V_2 , F_30 , & V_50 ) )
goto V_58;
if ( ! F_34 ( V_2 , F_32 , NULL ) )
goto V_58;
F_29 ( & V_2 -> V_19 , L_6 ) ;
return - 1 ;
V_58:
if ( V_11 -> V_13 && ( V_11 -> V_46 == V_59 ) )
V_2 -> V_60 &= ~ ( 0x08 ) ;
if ( V_11 -> V_22 && V_11 -> V_22 -> V_61 )
V_11 -> V_22 -> V_61 ( V_2 ) ;
V_18 = F_35 ( V_2 ) ;
if ( V_18 != 0 )
return - 1 ;
return F_24 ( V_2 , V_11 , V_2 -> V_43 [ 0 ] -> V_45 , V_2 -> V_32 ) ;
}
static int F_36 ( struct V_1 * V_26 , void * V_48 )
{
int * V_13 = V_48 ;
if ( V_26 -> V_43 [ 1 ] -> V_44 )
return - V_42 ;
if ( V_26 -> V_43 [ 0 ] -> V_44 <= 8 )
return - V_42 ;
V_26 -> V_43 [ 0 ] -> V_33 &= ~ V_52 ;
V_26 -> V_43 [ 0 ] -> V_33 |= V_53 ;
V_26 -> V_43 [ 0 ] -> V_44 = * V_13 * 8 ;
if ( F_31 ( V_26 ) )
return - V_9 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_26 ,
void * V_48 )
{
int * V_62 = V_48 ;
if ( ! V_26 -> V_43 [ 0 ] -> V_44 || ! V_26 -> V_43 [ 1 ] -> V_44 )
return - V_9 ;
V_26 -> V_43 [ 0 ] -> V_44 = V_26 -> V_43 [ 1 ] -> V_44 = 8 ;
V_26 -> V_43 [ 0 ] -> V_33 &= ~ V_52 ;
V_26 -> V_43 [ 0 ] -> V_33 |= V_53 ;
if ( F_31 ( V_26 ) )
return - V_9 ;
* V_62 = V_26 -> V_43 [ 0 ] -> V_45 + 8 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_18 , V_62 = 0 ;
V_2 -> V_16 |= V_57 ;
if ( ! F_34 ( V_2 , F_36 , & V_11 -> V_13 ) )
V_62 = V_2 -> V_43 [ 0 ] -> V_45 + 8 ;
else {
V_11 -> V_13 = 2 ;
if ( F_34 ( V_2 , F_37 ,
& V_62 ) ) {
F_29 ( & V_2 -> V_19 , L_7
L_8 ) ;
return - V_9 ;
}
}
if ( ! V_2 -> V_32 )
F_29 ( & V_2 -> V_19 , L_9 ) ;
if ( V_11 -> V_22 && V_11 -> V_22 -> V_61 )
V_11 -> V_22 -> V_61 ( V_2 ) ;
V_18 = F_35 ( V_2 ) ;
if ( V_18 != 0 )
return - V_9 ;
if ( V_11 -> V_46 == V_63 || ( V_11 -> V_46 == V_64 &&
V_11 -> V_65 == V_66 ) ) {
int V_67 ;
if ( V_2 -> V_60 == 1 ||
V_2 -> V_60 == 3 ) {
V_67 = F_24 ( V_2 , V_11 , V_62 ,
V_2 -> V_32 ) ;
V_62 = V_2 -> V_43 [ 0 ] -> V_45 ;
} else {
V_67 = F_24 ( V_2 , V_11 , V_2 -> V_43 [ 0 ] -> V_45 ,
V_2 -> V_32 ) ;
}
V_11 -> V_14 = V_62 ;
if ( V_11 -> V_22 && V_11 -> V_22 -> V_23 )
V_11 -> V_22 -> V_23 ( V_2 ) ;
return 0 ;
}
F_24 ( V_2 , V_11 , V_2 -> V_43 [ 0 ] -> V_45 , V_2 -> V_32 ) ;
for ( V_18 = 0 ; V_18 < V_11 -> V_13 - 1 ; V_18 ++ )
F_24 ( V_2 , V_11 , V_62 + ( 8 * V_18 ) ,
V_2 -> V_32 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_26 , void * V_48 )
{
struct V_10 * V_11 = V_26 -> V_12 ;
if ( ! V_26 -> V_43 [ 0 ] -> V_44 )
return - V_42 ;
if ( ( ! V_26 -> V_43 [ 1 ] -> V_44 ) && ( V_26 -> V_43 [ 0 ] -> V_44 % 8 == 0 ) )
V_11 -> V_13 = V_26 -> V_43 [ 0 ] -> V_44 >> 3 ;
if ( ( V_26 -> V_43 [ 1 ] -> V_44 ) && ( V_26 -> V_43 [ 0 ] -> V_44 == 8 )
&& ( V_26 -> V_43 [ 1 ] -> V_44 == 8 ) )
V_11 -> V_13 = 2 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_18 ;
F_12 ( & V_2 -> V_19 , L_10 ) ;
V_11 -> V_13 = ( V_2 -> V_68 -> V_69 > 1 ) ;
V_11 -> V_46 = V_2 -> V_70 ;
V_11 -> V_65 = V_2 -> V_71 ;
for ( V_18 = 0 ; V_18 < F_40 ( V_72 ) ; V_18 ++ )
if ( ( V_72 [ V_18 ] . V_46 == ~ 0 ||
V_72 [ V_18 ] . V_46 == V_11 -> V_46 ) &&
( V_72 [ V_18 ] . V_65 == ~ 0 ||
V_72 [ V_18 ] . V_65 == V_11 -> V_65 ) ) {
V_11 -> V_22 = & V_72 [ V_18 ] ;
break;
}
if ( ( V_11 -> V_13 == 0 ) &&
( V_2 -> V_73 ) &&
( V_2 -> V_68 -> V_74 == 0 ) &&
( ( V_2 -> V_75 == V_76 ) ||
( V_2 -> V_75 == V_77 ) ) )
F_34 ( V_2 , F_39 , V_11 ) ;
if ( V_11 -> V_22 && V_11 -> V_22 -> V_13 != - 1 )
V_11 -> V_13 = V_11 -> V_22 -> V_13 ;
F_41 ( & V_2 -> V_19 ,
L_11 ,
V_2 -> V_70 , V_2 -> V_71 ,
V_2 -> V_68 -> V_74 , V_11 -> V_13 , V_11 -> V_22 ) ;
if ( V_2 -> V_68 -> V_74 )
V_18 = F_27 ( V_2 ) ;
else if ( V_11 -> V_13 > 1 )
V_18 = F_38 ( V_2 ) ;
else
V_18 = F_33 ( V_2 ) ;
if ( V_18 || V_11 -> V_20 == 0 )
goto V_8;
if ( V_11 -> V_22 && V_11 -> V_22 -> V_78 )
if ( V_11 -> V_22 -> V_78 ( V_2 ) )
goto V_8;
return 0 ;
V_8:
F_29 ( & V_2 -> V_19 , L_12 ) ;
F_11 ( V_2 ) ;
return - V_9 ;
}
static int T_2 F_42 ( void )
{
return F_43 ( & V_79 ) ;
}
static void T_3 F_44 ( void )
{
F_45 ( & V_79 ) ;
}
