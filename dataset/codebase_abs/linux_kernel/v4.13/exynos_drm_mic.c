static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 ;
unsigned int V_5 ;
V_4 = F_2 ( V_2 -> V_6 , V_7 , & V_5 ) ;
if ( V_4 ) {
F_3 ( L_1 ) ;
return;
}
if ( V_3 ) {
if ( V_2 -> V_8 )
V_5 |= V_9 ;
else
V_5 |= V_10 ;
V_5 |= V_11 ;
} else
V_5 &= ~ ( V_10 | V_9 | V_11 ) ;
V_4 = F_4 ( V_2 -> V_6 , V_7 , V_5 ) ;
if ( V_4 )
F_3 ( L_1 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned int V_12 = 100 ;
int V_4 ;
F_6 ( V_13 , V_2 -> V_14 + V_15 ) ;
while ( V_12 -- > 0 ) {
V_4 = F_7 ( V_2 -> V_14 + V_15 ) ;
if ( ! ( V_4 & V_13 ) )
return 0 ;
F_8 ( 10 ) ;
}
return - V_16 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_17 V_18 = V_2 -> V_18 ;
T_1 V_14 ;
V_14 = F_10 ( V_18 . V_19 ) +
F_11 ( V_18 . V_19 + V_18 . V_20 +
V_18 . V_21 + V_18 . V_22 ) ;
F_6 ( V_14 , V_2 -> V_14 + V_23 ) ;
V_14 = F_12 ( V_18 . V_21 ) +
F_13 ( V_18 . V_22 ) ;
F_6 ( V_14 , V_2 -> V_14 + V_24 ) ;
V_14 = F_10 ( V_18 . V_25 ) +
F_11 ( V_18 . V_25 + V_18 . V_26 +
V_18 . V_27 + V_18 . V_28 ) ;
F_6 ( V_14 , V_2 -> V_14 + V_29 ) ;
V_14 = F_12 ( V_18 . V_27 ) +
F_13 ( V_18 . V_28 ) ;
F_6 ( V_14 , V_2 -> V_14 + V_30 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_18 ;
T_1 V_14 ;
V_14 = F_15 ( V_18 -> V_26 ) +
F_16 ( V_18 -> V_20 ) ;
F_6 ( V_14 , V_2 -> V_14 + V_31 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_17 V_18 = V_2 -> V_18 ;
T_1 V_14 , V_32 ;
F_18 ( L_2 , V_18 . V_26 , V_18 . V_20 ) ;
V_32 = ( ( V_18 . V_26 >> 2 ) << 1 ) + ( V_18 . V_20 % 4 ) ;
V_14 = F_19 ( V_32 ) ;
F_6 ( V_14 , V_2 -> V_14 + V_33 ) ;
if ( ! V_2 -> V_8 ) {
V_14 = F_20 ( V_18 . V_25 ) +
F_21 ( V_18 . V_25 + V_32 +
V_18 . V_27 + V_18 . V_28 ) ;
F_6 ( V_14 , V_2 -> V_14 + V_34 ) ;
V_14 = F_22 ( V_18 . V_27 ) +
F_21 ( V_18 . V_28 ) ;
F_6 ( V_14 , V_2 -> V_14 + V_35 ) ;
}
}
static void F_23 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_14 = F_7 ( V_2 -> V_14 + V_15 ) ;
if ( V_3 ) {
V_14 &= ~ ( V_36 | V_37 | V_38 ) ;
V_14 |= ( V_39 | V_40 | V_41 ) ;
V_14 &= ~ V_42 ;
if ( V_2 -> V_8 )
V_14 |= V_42 ;
} else {
V_14 &= ~ V_39 ;
}
V_14 |= V_43 ;
F_6 ( V_14 , V_2 -> V_14 + V_15 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_4 = 0 , V_44 , V_45 ;
struct V_46 * V_47 ;
struct V_46 * V_48 [ 3 ] ;
for ( V_44 = 0 , V_45 = 0 ; V_44 < V_49 ; V_44 ++ ) {
V_47 = F_25 ( V_2 -> V_50 -> V_51 , V_44 , 0 ) ;
if ( ! V_47 ) {
V_4 = - V_52 ;
goto exit;
}
V_48 [ V_45 ++ ] = V_47 ;
if ( V_44 == V_53 &&
F_26 ( V_47 , L_3 ) )
V_2 -> V_8 = 1 ;
}
exit:
while ( -- V_45 > - 1 )
F_27 ( V_48 [ V_45 ] ) ;
return V_4 ;
}
static void F_28 ( struct V_54 * V_55 ) { }
static void F_29 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = V_55 -> V_56 ;
F_30 ( & V_57 ) ;
if ( ! V_2 -> V_58 )
goto V_59;
F_1 ( V_2 , 0 ) ;
F_31 ( V_2 -> V_50 ) ;
V_2 -> V_58 = 0 ;
V_59:
F_32 ( & V_57 ) ;
}
static void F_33 ( struct V_54 * V_55 ,
struct V_60 * V_61 ,
struct V_60 * V_62 )
{
struct V_1 * V_2 = V_55 -> V_56 ;
F_30 ( & V_57 ) ;
F_34 ( V_61 , & V_2 -> V_18 ) ;
F_32 ( & V_57 ) ;
}
static void F_35 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = V_55 -> V_56 ;
int V_4 ;
F_30 ( & V_57 ) ;
if ( V_2 -> V_58 )
goto V_63;
V_4 = F_36 ( V_2 -> V_50 ) ;
if ( V_4 < 0 )
goto V_63;
F_1 ( V_2 , 1 ) ;
V_4 = F_5 ( V_2 ) ;
if ( V_4 ) {
F_3 ( L_4 ) ;
goto V_64;
}
if ( ! V_2 -> V_8 )
F_9 ( V_2 ) ;
F_14 ( V_2 ) ;
F_17 ( V_2 ) ;
F_23 ( V_2 , 1 ) ;
V_2 -> V_58 = 1 ;
F_32 ( & V_57 ) ;
return;
V_64:
F_31 ( V_2 -> V_50 ) ;
V_63:
F_32 ( & V_57 ) ;
}
static void F_37 ( struct V_54 * V_55 ) { }
static int F_38 ( struct V_65 * V_50 , struct V_65 * V_66 ,
void * V_67 )
{
struct V_1 * V_2 = F_39 ( V_50 ) ;
V_2 -> V_55 . V_56 = V_2 ;
return 0 ;
}
static void F_40 ( struct V_65 * V_50 , struct V_65 * V_66 ,
void * V_67 )
{
struct V_1 * V_2 = F_39 ( V_50 ) ;
F_30 ( & V_57 ) ;
if ( ! V_2 -> V_58 )
goto V_59;
F_31 ( V_2 -> V_50 ) ;
V_59:
F_32 ( & V_57 ) ;
}
static int F_41 ( struct V_65 * V_50 )
{
struct V_1 * V_2 = F_39 ( V_50 ) ;
int V_44 ;
for ( V_44 = V_68 - 1 ; V_44 > - 1 ; V_44 -- )
F_42 ( V_2 -> V_69 [ V_44 ] ) ;
return 0 ;
}
static int F_43 ( struct V_65 * V_50 )
{
struct V_1 * V_2 = F_39 ( V_50 ) ;
int V_4 , V_44 ;
for ( V_44 = 0 ; V_44 < V_68 ; V_44 ++ ) {
V_4 = F_44 ( V_2 -> V_69 [ V_44 ] ) ;
if ( V_4 < 0 ) {
F_3 ( L_5 ,
V_70 [ V_44 ] ) ;
while ( -- V_44 > - 1 )
F_42 ( V_2 -> V_69 [ V_44 ] ) ;
return V_4 ;
}
}
return 0 ;
}
static int F_45 ( struct V_71 * V_72 )
{
struct V_65 * V_50 = & V_72 -> V_50 ;
struct V_1 * V_2 ;
struct V_73 V_74 ;
int V_4 , V_44 ;
V_2 = F_46 ( V_50 , sizeof( * V_2 ) , V_75 ) ;
if ( ! V_2 ) {
F_3 ( L_6 ) ;
V_4 = - V_76 ;
goto V_77;
}
V_2 -> V_50 = V_50 ;
V_4 = F_24 ( V_2 ) ;
if ( V_4 )
goto V_77;
V_4 = F_47 ( V_50 -> V_51 , 0 , & V_74 ) ;
if ( V_4 ) {
F_3 ( L_7 ) ;
goto V_77;
}
V_2 -> V_14 = F_48 ( V_50 , V_74 . V_78 , F_49 ( & V_74 ) ) ;
if ( ! V_2 -> V_14 ) {
F_3 ( L_8 ) ;
V_4 = - V_76 ;
goto V_77;
}
V_2 -> V_6 = F_50 ( V_50 -> V_51 ,
L_9 ) ;
if ( F_51 ( V_2 -> V_6 ) ) {
F_3 ( L_10 ) ;
V_4 = F_52 ( V_2 -> V_6 ) ;
goto V_77;
}
for ( V_44 = 0 ; V_44 < V_68 ; V_44 ++ ) {
V_2 -> V_69 [ V_44 ] = F_53 ( V_50 , V_70 [ V_44 ] ) ;
if ( F_51 ( V_2 -> V_69 [ V_44 ] ) ) {
F_3 ( L_11 ,
V_70 [ V_44 ] ) ;
V_4 = F_52 ( V_2 -> V_69 [ V_44 ] ) ;
goto V_77;
}
}
F_54 ( V_72 , V_2 ) ;
V_2 -> V_55 . V_79 = & V_80 ;
V_2 -> V_55 . V_51 = V_50 -> V_51 ;
V_4 = F_55 ( & V_2 -> V_55 ) ;
if ( V_4 ) {
F_3 ( L_12 ) ;
return V_4 ;
}
F_56 ( V_50 ) ;
V_4 = F_57 ( V_50 , & V_81 ) ;
if ( V_4 )
goto V_82;
F_58 ( L_13 ) ;
return 0 ;
V_82:
F_59 ( V_50 ) ;
V_77:
return V_4 ;
}
static int F_60 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_61 ( V_72 ) ;
F_62 ( & V_72 -> V_50 , & V_81 ) ;
F_59 ( & V_72 -> V_50 ) ;
F_63 ( & V_2 -> V_55 ) ;
return 0 ;
}
