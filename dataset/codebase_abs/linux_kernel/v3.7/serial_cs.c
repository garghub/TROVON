static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 . V_6 = 14745600 ;
}
static int F_2 ( struct V_1 * V_2 )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_3 ( V_2 , 0x800 , & V_7 ) ;
if ( V_8 )
goto V_9;
V_8 = F_4 ( V_2 , 0x800 , V_7 | 1 ) ;
if ( V_8 )
goto V_9;
return 0 ;
V_9:
return - V_10 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
if ( V_12 -> V_14 > 1 )
V_12 -> V_14 = 1 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
if ( V_12 -> V_15 )
F_7 ( 12 , V_12 -> V_15 + 1 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned int V_16 = V_12 -> V_15 ;
F_7 ( 0xA , V_16 + 1 ) ;
F_9 ( 100 ) ;
F_7 ( 0xE , V_16 + 1 ) ;
F_9 ( 300 ) ;
F_7 ( 0xC , V_16 + 1 ) ;
F_9 ( 100 ) ;
F_7 ( 0xE , V_16 + 1 ) ;
F_9 ( 200 ) ;
F_7 ( 0xF , V_16 + 1 ) ;
F_9 ( 100 ) ;
F_7 ( 0xE , V_16 + 1 ) ;
F_9 ( 100 ) ;
F_7 ( 0xC , V_16 + 1 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
if ( V_12 -> V_14 )
V_2 -> V_17 |= V_18 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
int V_19 ;
F_12 ( & V_2 -> V_20 , L_1 ) ;
for ( V_19 = 0 ; V_19 < V_12 -> V_21 ; V_19 ++ )
F_13 ( V_12 -> line [ V_19 ] ) ;
if ( ! V_12 -> V_22 )
F_14 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_12 -> V_21 ; V_19 ++ )
F_16 ( V_12 -> line [ V_19 ] ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_12 -> V_21 ; V_19 ++ )
F_18 ( V_12 -> line [ V_19 ] ) ;
if ( V_12 -> V_23 && V_12 -> V_23 -> V_24 )
V_12 -> V_23 -> V_24 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
F_12 ( & V_2 -> V_20 , L_2 ) ;
V_12 = F_20 ( sizeof ( * V_12 ) , V_25 ) ;
if ( ! V_12 )
return - V_26 ;
V_12 -> V_27 = V_2 ;
V_2 -> V_13 = V_12 ;
V_2 -> V_17 |= V_28 | V_29 ;
if ( V_30 )
V_2 -> V_17 |= V_31 ;
return F_21 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
F_12 ( & V_2 -> V_20 , L_3 ) ;
F_11 ( V_2 ) ;
F_23 ( V_12 ) ;
}
static int F_24 ( struct V_1 * V_32 , struct V_11 * V_12 ,
unsigned int V_33 , int V_34 )
{
struct V_3 V_4 ;
int line ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_5 . V_33 = V_33 ;
V_4 . V_5 . V_34 = V_34 ;
V_4 . V_5 . V_35 = V_36 | V_37 | V_38 ;
V_4 . V_5 . V_6 = 1843200 ;
V_4 . V_5 . V_20 = & V_32 -> V_20 ;
if ( V_39 )
V_4 . V_5 . V_35 |= V_40 ;
if ( V_12 -> V_23 && V_12 -> V_23 -> V_41 )
V_12 -> V_23 -> V_41 ( V_32 , & V_4 ) ;
line = F_25 ( & V_4 ) ;
if ( line < 0 ) {
F_26 ( L_4 ,
( unsigned long ) V_33 , V_34 ) ;
return - V_42 ;
}
V_12 -> line [ V_12 -> V_21 ] = line ;
V_12 -> V_21 ++ ;
return 0 ;
}
static int F_27 ( struct V_1 * V_27 )
{
unsigned int V_5 = 0 ;
struct V_11 * V_12 = V_27 -> V_13 ;
if ( ( V_27 -> V_43 [ 1 ] -> V_44 != 0 ) &&
( F_28 ( V_27 -> V_43 [ 1 ] ) == 8 ) ) {
V_5 = V_27 -> V_43 [ 1 ] -> V_45 ;
V_12 -> V_22 = 1 ;
} else if ( ( V_12 -> V_46 == V_47 ) &&
( F_28 ( V_27 -> V_43 [ 0 ] ) == 0x40 ) ) {
V_5 = V_27 -> V_43 [ 0 ] -> V_45 + 0x28 ;
V_12 -> V_22 = 1 ;
}
if ( V_12 -> V_22 )
return F_24 ( V_27 , V_12 , V_5 , V_27 -> V_34 ) ;
F_29 ( & V_27 -> V_20 , L_5 ) ;
return - V_10 ;
}
static int F_30 ( struct V_1 * V_27 , void * V_48 )
{
static const int V_49 [ 2 ] = { 8 , 16 } ;
int * V_50 = V_48 ;
if ( V_27 -> V_43 [ 0 ] -> V_45 == 0 )
return - V_10 ;
if ( ( * V_50 & 0x1 ) == 0 )
V_27 -> V_51 = 16 ;
if ( V_27 -> V_43 [ 0 ] -> V_44 != V_49 [ ( * V_50 >> 1 ) ] )
return - V_10 ;
V_27 -> V_43 [ 0 ] -> V_44 = 8 ;
V_27 -> V_43 [ 0 ] -> V_35 &= ~ V_52 ;
V_27 -> V_43 [ 0 ] -> V_35 |= V_53 ;
return F_31 ( V_27 ) ;
}
static int F_32 ( struct V_1 * V_27 ,
void * V_48 )
{
static const unsigned int V_54 [ 5 ] = { 0x3f8 , 0x2f8 , 0x3e8 , 0x2e8 , 0x0 } ;
int V_55 ;
if ( V_27 -> V_51 > 3 )
return - V_10 ;
V_27 -> V_43 [ 0 ] -> V_35 &= ~ V_52 ;
V_27 -> V_43 [ 0 ] -> V_35 |= V_53 ;
V_27 -> V_43 [ 0 ] -> V_44 = 8 ;
for ( V_55 = 0 ; V_55 < 5 ; V_55 ++ ) {
V_27 -> V_43 [ 0 ] -> V_45 = V_54 [ V_55 ] ;
V_27 -> V_51 = V_54 [ V_55 ] ? 16 : 3 ;
if ( ! F_31 ( V_27 ) )
return 0 ;
}
return - V_10 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
int V_19 = - V_10 , V_50 ;
V_2 -> V_17 |= V_56 ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ )
if ( ! F_34 ( V_2 , F_30 , & V_50 ) )
goto V_57;
if ( ! F_34 ( V_2 , F_32 , NULL ) )
goto V_57;
F_29 ( & V_2 -> V_20 , L_5 ) ;
return - 1 ;
V_57:
if ( V_12 -> V_14 && ( V_12 -> V_46 == V_58 ) )
V_2 -> V_59 &= ~ ( 0x08 ) ;
if ( V_12 -> V_23 && V_12 -> V_23 -> V_60 )
V_12 -> V_23 -> V_60 ( V_2 ) ;
V_19 = F_35 ( V_2 ) ;
if ( V_19 != 0 )
return - 1 ;
return F_24 ( V_2 , V_12 , V_2 -> V_43 [ 0 ] -> V_45 , V_2 -> V_34 ) ;
}
static int F_36 ( struct V_1 * V_27 , void * V_48 )
{
int * V_14 = V_48 ;
if ( V_27 -> V_43 [ 1 ] -> V_44 )
return - V_42 ;
if ( V_27 -> V_43 [ 0 ] -> V_44 <= 8 )
return - V_42 ;
V_27 -> V_43 [ 0 ] -> V_35 &= ~ V_52 ;
V_27 -> V_43 [ 0 ] -> V_35 |= V_53 ;
V_27 -> V_43 [ 0 ] -> V_44 = * V_14 * 8 ;
if ( F_31 ( V_27 ) )
return - V_10 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_27 ,
void * V_48 )
{
int * V_61 = V_48 ;
if ( ! V_27 -> V_43 [ 0 ] -> V_44 || ! V_27 -> V_43 [ 1 ] -> V_44 ||
V_27 -> V_43 [ 0 ] -> V_45 + 8 != V_27 -> V_43 [ 1 ] -> V_45 )
return - V_10 ;
V_27 -> V_43 [ 0 ] -> V_44 = V_27 -> V_43 [ 1 ] -> V_44 = 8 ;
V_27 -> V_43 [ 0 ] -> V_35 &= ~ V_52 ;
V_27 -> V_43 [ 0 ] -> V_35 |= V_53 ;
if ( F_31 ( V_27 ) )
return - V_10 ;
* V_61 = V_27 -> V_43 [ 0 ] -> V_45 + 8 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
int V_19 , V_61 = 0 ;
if ( ! F_34 ( V_2 , F_36 , & V_12 -> V_14 ) )
V_61 = V_2 -> V_43 [ 0 ] -> V_45 + 8 ;
else {
V_12 -> V_14 = 2 ;
if ( F_34 ( V_2 , F_37 ,
& V_61 ) ) {
F_29 ( & V_2 -> V_20 , L_6
L_7 ) ;
return - V_10 ;
}
}
if ( ! V_2 -> V_34 )
F_29 ( & V_2 -> V_20 , L_8 ) ;
if ( V_12 -> V_23 && V_12 -> V_23 -> V_60 )
V_12 -> V_23 -> V_60 ( V_2 ) ;
V_19 = F_35 ( V_2 ) ;
if ( V_19 != 0 )
return - V_10 ;
if ( V_12 -> V_46 == V_62 || ( V_12 -> V_46 == V_63 &&
V_12 -> V_64 == V_65 ) ) {
int V_66 ;
if ( V_2 -> V_59 == 1 ||
V_2 -> V_59 == 3 ) {
V_66 = F_24 ( V_2 , V_12 , V_61 ,
V_2 -> V_34 ) ;
V_61 = V_2 -> V_43 [ 0 ] -> V_45 ;
} else {
V_66 = F_24 ( V_2 , V_12 , V_2 -> V_43 [ 0 ] -> V_45 ,
V_2 -> V_34 ) ;
}
V_12 -> V_15 = V_61 ;
if ( V_12 -> V_23 && V_12 -> V_23 -> V_24 )
V_12 -> V_23 -> V_24 ( V_2 ) ;
return 0 ;
}
F_24 ( V_2 , V_12 , V_2 -> V_43 [ 0 ] -> V_45 , V_2 -> V_34 ) ;
for ( V_19 = 0 ; V_19 < V_12 -> V_14 - 1 ; V_19 ++ )
F_24 ( V_2 , V_12 , V_61 + ( 8 * V_19 ) ,
V_2 -> V_34 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_27 , void * V_48 )
{
struct V_11 * V_12 = V_27 -> V_13 ;
if ( ! V_27 -> V_43 [ 0 ] -> V_44 )
return - V_42 ;
if ( ( ! V_27 -> V_43 [ 1 ] -> V_44 ) && ( V_27 -> V_43 [ 0 ] -> V_44 % 8 == 0 ) )
V_12 -> V_14 = V_27 -> V_43 [ 0 ] -> V_44 >> 3 ;
if ( ( V_27 -> V_43 [ 1 ] -> V_44 ) && ( V_27 -> V_43 [ 0 ] -> V_44 == 8 )
&& ( V_27 -> V_43 [ 1 ] -> V_44 == 8 ) )
V_12 -> V_14 = 2 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
int V_19 ;
F_12 ( & V_2 -> V_20 , L_9 ) ;
V_12 -> V_14 = ( V_2 -> V_67 -> V_68 > 1 ) ;
V_12 -> V_46 = V_2 -> V_69 ;
V_12 -> V_64 = V_2 -> V_70 ;
for ( V_19 = 0 ; V_19 < F_40 ( V_71 ) ; V_19 ++ )
if ( ( V_71 [ V_19 ] . V_46 == ~ 0 ||
V_71 [ V_19 ] . V_46 == V_12 -> V_46 ) &&
( V_71 [ V_19 ] . V_64 == ~ 0 ||
V_71 [ V_19 ] . V_64 == V_12 -> V_64 ) ) {
V_12 -> V_23 = & V_71 [ V_19 ] ;
break;
}
if ( ( V_12 -> V_14 == 0 ) &&
( V_2 -> V_72 ) &&
( V_2 -> V_67 -> V_73 == 0 ) &&
( ( V_2 -> V_74 == V_75 ) ||
( V_2 -> V_74 == V_76 ) ) )
F_34 ( V_2 , F_39 , V_12 ) ;
if ( V_12 -> V_23 && V_12 -> V_23 -> V_14 != - 1 )
V_12 -> V_14 = V_12 -> V_23 -> V_14 ;
F_41 ( & V_2 -> V_20 ,
L_10 ,
V_2 -> V_69 , V_2 -> V_70 ,
V_2 -> V_67 -> V_73 , V_12 -> V_14 , V_12 -> V_23 ) ;
if ( V_2 -> V_67 -> V_73 )
V_19 = F_27 ( V_2 ) ;
else if ( V_12 -> V_14 > 1 )
V_19 = F_38 ( V_2 ) ;
else
V_19 = F_33 ( V_2 ) ;
if ( V_19 || V_12 -> V_21 == 0 )
goto V_9;
if ( V_12 -> V_23 && V_12 -> V_23 -> V_77 )
if ( V_12 -> V_23 -> V_77 ( V_2 ) )
goto V_9;
return 0 ;
V_9:
F_29 ( & V_2 -> V_20 , L_11 ) ;
F_11 ( V_2 ) ;
return - V_10 ;
}
static int T_2 F_42 ( void )
{
return F_43 ( & V_78 ) ;
}
static void T_3 F_44 ( void )
{
F_45 ( & V_78 ) ;
}
