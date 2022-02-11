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
F_4 ( V_2 -> V_6 , V_7 , V_5 ) ;
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
static struct V_44 * F_24 ( struct V_44 * V_45 , int V_14 )
{
struct V_44 * V_46 = NULL , * V_47 = NULL ;
V_46 = F_25 ( V_45 , V_14 , - 1 ) ;
if ( ! V_46 ) {
F_3 ( L_3 ,
V_45 -> V_48 ) ;
goto exit;
}
V_47 = F_26 ( V_46 ) ;
if ( ! V_47 ) {
F_3 ( L_4 ,
V_45 -> V_48 ) ;
goto exit;
}
exit:
F_27 ( V_46 ) ;
return V_47 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_4 = 0 , V_49 , V_50 ;
struct V_44 * V_47 ;
struct V_44 * V_51 [ 3 ] ;
for ( V_49 = 0 , V_50 = 0 ; V_49 < V_52 ; V_49 ++ ) {
V_47 = F_24 ( V_2 -> V_53 -> V_54 , V_49 ) ;
if ( ! V_47 ) {
V_4 = - V_55 ;
goto exit;
}
V_51 [ V_50 ++ ] = V_47 ;
switch ( V_49 ) {
case V_56 :
if ( F_29 ( V_47 ,
L_5 ) )
V_2 -> V_8 = 1 ;
break;
case V_57 :
V_47 = F_24 ( V_47 , 1 ) ;
if ( ! V_47 ) {
V_4 = - V_55 ;
goto exit;
}
V_51 [ V_50 ++ ] = V_47 ;
V_4 = F_30 ( V_47 ,
& V_2 -> V_18 , 0 ) ;
if ( V_4 ) {
F_3 ( L_6 ) ;
goto exit;
}
break;
default:
F_3 ( L_7 ) ;
break;
}
}
exit:
while ( -- V_50 > - 1 )
F_27 ( V_51 [ V_50 ] ) ;
return V_4 ;
}
static void F_31 ( struct V_58 * V_59 ) { }
static void F_32 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
int V_49 ;
F_33 ( & V_61 ) ;
if ( ! V_2 -> V_62 )
goto V_63;
F_1 ( V_2 , 0 ) ;
for ( V_49 = V_64 - 1 ; V_49 > - 1 ; V_49 -- )
F_34 ( V_2 -> V_65 [ V_49 ] ) ;
V_2 -> V_62 = 0 ;
V_63:
F_35 ( & V_61 ) ;
}
static void F_36 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_60 ;
int V_4 , V_49 ;
F_33 ( & V_61 ) ;
if ( V_2 -> V_62 )
goto V_66;
for ( V_49 = 0 ; V_49 < V_64 ; V_49 ++ ) {
V_4 = F_37 ( V_2 -> V_65 [ V_49 ] ) ;
if ( V_4 < 0 ) {
F_3 ( L_8 ,
V_67 [ V_49 ] ) ;
goto V_68;
}
}
F_1 ( V_2 , 1 ) ;
V_4 = F_5 ( V_2 ) ;
if ( V_4 ) {
F_3 ( L_9 ) ;
goto V_68;
}
if ( ! V_2 -> V_8 )
F_9 ( V_2 ) ;
F_14 ( V_2 ) ;
F_17 ( V_2 ) ;
F_23 ( V_2 , 1 ) ;
V_2 -> V_62 = 1 ;
F_35 ( & V_61 ) ;
return;
V_68:
while ( -- V_49 > - 1 )
F_34 ( V_2 -> V_65 [ V_49 ] ) ;
V_66:
F_35 ( & V_61 ) ;
}
static void F_38 ( struct V_58 * V_59 ) { }
static int F_39 ( struct V_69 * V_53 , struct V_69 * V_70 ,
void * V_71 )
{
struct V_1 * V_2 = F_40 ( V_53 ) ;
int V_4 ;
V_2 -> V_59 . V_72 = & V_73 ;
V_2 -> V_59 . V_54 = V_53 -> V_54 ;
V_2 -> V_59 . V_60 = V_2 ;
V_4 = F_41 ( & V_2 -> V_59 ) ;
if ( V_4 )
F_3 ( L_10 ) ;
return V_4 ;
}
static void F_42 ( struct V_69 * V_53 , struct V_69 * V_70 ,
void * V_71 )
{
struct V_1 * V_2 = F_40 ( V_53 ) ;
int V_49 ;
F_33 ( & V_61 ) ;
if ( ! V_2 -> V_62 )
goto V_63;
for ( V_49 = V_64 - 1 ; V_49 > - 1 ; V_49 -- )
F_34 ( V_2 -> V_65 [ V_49 ] ) ;
V_63:
F_35 ( & V_61 ) ;
F_43 ( & V_2 -> V_59 ) ;
}
static int F_44 ( struct V_74 * V_75 )
{
struct V_69 * V_53 = & V_75 -> V_53 ;
struct V_1 * V_2 ;
struct V_76 V_77 ;
int V_4 , V_49 ;
V_2 = F_45 ( V_53 , sizeof( * V_2 ) , V_78 ) ;
if ( ! V_2 ) {
F_3 ( L_11 ) ;
V_4 = - V_79 ;
goto V_80;
}
V_2 -> V_53 = V_53 ;
V_4 = F_28 ( V_2 ) ;
if ( V_4 )
goto V_80;
V_4 = F_46 ( V_53 -> V_54 , 0 , & V_77 ) ;
if ( V_4 ) {
F_3 ( L_12 ) ;
goto V_80;
}
V_2 -> V_14 = F_47 ( V_53 , V_77 . V_81 , F_48 ( & V_77 ) ) ;
if ( ! V_2 -> V_14 ) {
F_3 ( L_13 ) ;
V_4 = - V_79 ;
goto V_80;
}
V_2 -> V_6 = F_49 ( V_53 -> V_54 ,
L_14 ) ;
if ( F_50 ( V_2 -> V_6 ) ) {
F_3 ( L_15 ) ;
goto V_80;
}
for ( V_49 = 0 ; V_49 < V_64 ; V_49 ++ ) {
V_2 -> V_65 [ V_49 ] = F_51 ( V_53 , V_67 [ V_49 ] ) ;
if ( F_50 ( V_2 -> V_65 [ V_49 ] ) ) {
F_3 ( L_16 ,
V_67 [ V_49 ] ) ;
V_4 = F_52 ( V_2 -> V_65 [ V_49 ] ) ;
goto V_80;
}
}
F_53 ( V_75 , V_2 ) ;
F_54 ( L_17 ) ;
return F_55 ( V_53 , & V_82 ) ;
V_80:
return V_4 ;
}
static int F_56 ( struct V_74 * V_75 )
{
F_57 ( & V_75 -> V_53 , & V_82 ) ;
return 0 ;
}
