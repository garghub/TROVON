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
static void F_24 ( struct V_44 * V_45 ) { }
static void F_25 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_46 ;
F_26 ( & V_47 ) ;
if ( ! V_2 -> V_48 )
goto V_49;
F_1 ( V_2 , 0 ) ;
F_27 ( V_2 -> V_50 ) ;
V_2 -> V_48 = 0 ;
V_49:
F_28 ( & V_47 ) ;
}
static void F_29 ( struct V_44 * V_45 ,
struct V_51 * V_52 ,
struct V_51 * V_53 )
{
struct V_1 * V_2 = V_45 -> V_46 ;
F_26 ( & V_47 ) ;
F_30 ( V_52 , & V_2 -> V_18 ) ;
V_2 -> V_8 = F_31 ( V_45 -> V_54 -> V_55 ) -> V_8 ;
F_28 ( & V_47 ) ;
}
static void F_32 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_46 ;
int V_4 ;
F_26 ( & V_47 ) ;
if ( V_2 -> V_48 )
goto V_56;
V_4 = F_33 ( V_2 -> V_50 ) ;
if ( V_4 < 0 )
goto V_56;
F_1 ( V_2 , 1 ) ;
V_4 = F_5 ( V_2 ) ;
if ( V_4 ) {
F_3 ( L_3 ) ;
goto V_57;
}
if ( ! V_2 -> V_8 )
F_9 ( V_2 ) ;
F_14 ( V_2 ) ;
F_17 ( V_2 ) ;
F_23 ( V_2 , 1 ) ;
V_2 -> V_48 = 1 ;
F_28 ( & V_47 ) ;
return;
V_57:
F_27 ( V_2 -> V_50 ) ;
V_56:
F_28 ( & V_47 ) ;
}
static void F_34 ( struct V_44 * V_45 ) { }
static int F_35 ( struct V_58 * V_50 , struct V_58 * V_59 ,
void * V_60 )
{
struct V_1 * V_2 = F_36 ( V_50 ) ;
V_2 -> V_45 . V_46 = V_2 ;
return 0 ;
}
static void F_37 ( struct V_58 * V_50 , struct V_58 * V_59 ,
void * V_60 )
{
struct V_1 * V_2 = F_36 ( V_50 ) ;
F_26 ( & V_47 ) ;
if ( ! V_2 -> V_48 )
goto V_49;
F_27 ( V_2 -> V_50 ) ;
V_49:
F_28 ( & V_47 ) ;
}
static int F_38 ( struct V_58 * V_50 )
{
struct V_1 * V_2 = F_36 ( V_50 ) ;
int V_61 ;
for ( V_61 = V_62 - 1 ; V_61 > - 1 ; V_61 -- )
F_39 ( V_2 -> V_63 [ V_61 ] ) ;
return 0 ;
}
static int F_40 ( struct V_58 * V_50 )
{
struct V_1 * V_2 = F_36 ( V_50 ) ;
int V_4 , V_61 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
V_4 = F_41 ( V_2 -> V_63 [ V_61 ] ) ;
if ( V_4 < 0 ) {
F_3 ( L_4 ,
V_64 [ V_61 ] ) ;
while ( -- V_61 > - 1 )
F_39 ( V_2 -> V_63 [ V_61 ] ) ;
return V_4 ;
}
}
return 0 ;
}
static int F_42 ( struct V_65 * V_66 )
{
struct V_58 * V_50 = & V_66 -> V_50 ;
struct V_1 * V_2 ;
struct V_67 V_68 ;
int V_4 , V_61 ;
V_2 = F_43 ( V_50 , sizeof( * V_2 ) , V_69 ) ;
if ( ! V_2 ) {
F_3 ( L_5 ) ;
V_4 = - V_70 ;
goto V_71;
}
V_2 -> V_50 = V_50 ;
V_4 = F_44 ( V_50 -> V_72 , 0 , & V_68 ) ;
if ( V_4 ) {
F_3 ( L_6 ) ;
goto V_71;
}
V_2 -> V_14 = F_45 ( V_50 , V_68 . V_73 , F_46 ( & V_68 ) ) ;
if ( ! V_2 -> V_14 ) {
F_3 ( L_7 ) ;
V_4 = - V_70 ;
goto V_71;
}
V_2 -> V_6 = F_47 ( V_50 -> V_72 ,
L_8 ) ;
if ( F_48 ( V_2 -> V_6 ) ) {
F_3 ( L_9 ) ;
V_4 = F_49 ( V_2 -> V_6 ) ;
goto V_71;
}
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
V_2 -> V_63 [ V_61 ] = F_50 ( V_50 , V_64 [ V_61 ] ) ;
if ( F_48 ( V_2 -> V_63 [ V_61 ] ) ) {
F_3 ( L_10 ,
V_64 [ V_61 ] ) ;
V_4 = F_49 ( V_2 -> V_63 [ V_61 ] ) ;
goto V_71;
}
}
F_51 ( V_66 , V_2 ) ;
V_2 -> V_45 . V_74 = & V_75 ;
V_2 -> V_45 . V_72 = V_50 -> V_72 ;
V_4 = F_52 ( & V_2 -> V_45 ) ;
if ( V_4 ) {
F_3 ( L_11 ) ;
return V_4 ;
}
F_53 ( V_50 ) ;
V_4 = F_54 ( V_50 , & V_76 ) ;
if ( V_4 )
goto V_77;
F_55 ( L_12 ) ;
return 0 ;
V_77:
F_56 ( V_50 ) ;
V_71:
return V_4 ;
}
static int F_57 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_58 ( V_66 ) ;
F_59 ( & V_66 -> V_50 , & V_76 ) ;
F_56 ( & V_66 -> V_50 ) ;
F_60 ( & V_2 -> V_45 ) ;
return 0 ;
}
