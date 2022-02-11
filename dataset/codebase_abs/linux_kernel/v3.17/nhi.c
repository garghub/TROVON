static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 ;
if ( ! V_2 -> V_5 )
V_3 += V_2 -> V_6 -> V_7 ;
return V_3 ;
}
static void F_2 ( struct V_1 * V_2 , bool V_8 )
{
int V_9 = V_10 + F_1 ( V_2 ) / 32 ;
int V_3 = F_1 ( V_2 ) & 31 ;
int V_11 = 1 << V_3 ;
T_1 V_12 , V_13 ;
V_12 = F_3 ( V_2 -> V_6 -> V_14 + V_9 ) ;
if ( V_8 )
V_13 = V_12 | V_11 ;
else
V_13 = V_12 & ~ V_11 ;
F_4 ( & V_2 -> V_6 -> V_15 -> V_16 ,
L_1 ,
V_8 ? L_2 : L_3 , V_9 , V_3 , V_12 , V_13 ) ;
if ( V_13 == V_12 )
F_5 ( & V_2 -> V_6 -> V_15 -> V_16 ,
L_4 ,
F_6 ( V_2 ) , V_2 -> V_4 ,
V_8 ? L_5 : L_6 ) ;
F_7 ( V_13 , V_2 -> V_6 -> V_14 + V_9 ) ;
}
static void F_8 ( struct V_17 * V_6 )
{
int V_18 = 0 ;
for ( V_18 = 0 ; V_18 < F_9 ( V_6 ) ; V_18 ++ )
F_7 ( 0 , V_6 -> V_14 + V_10 + 4 * V_18 ) ;
for ( V_18 = 0 ; V_18 < F_10 ( V_6 ) ; V_18 ++ )
F_3 ( V_6 -> V_14 + V_19 + 4 * V_18 ) ;
}
static void T_2 * F_11 ( struct V_1 * V_2 )
{
void T_2 * V_20 = V_2 -> V_6 -> V_14 ;
V_20 += V_2 -> V_5 ? V_21 : V_22 ;
V_20 += V_2 -> V_4 * 16 ;
return V_20 ;
}
static void T_2 * F_12 ( struct V_1 * V_2 )
{
void T_2 * V_20 = V_2 -> V_6 -> V_14 ;
V_20 += V_2 -> V_5 ? V_23 : V_24 ;
V_20 += V_2 -> V_4 * 32 ;
return V_20 ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_25 , T_1 V_26 )
{
F_14 ( V_25 , F_11 ( V_2 ) + V_26 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_25 , T_1 V_26 )
{
F_7 ( V_25 , F_11 ( V_2 ) + V_26 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_3 V_25 , T_1 V_26 )
{
F_7 ( V_25 , F_11 ( V_2 ) + V_26 ) ;
F_7 ( V_25 >> 32 , F_11 ( V_2 ) + V_26 + 4 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_25 , T_1 V_26 )
{
F_7 ( V_25 , F_12 ( V_2 ) + V_26 ) ;
}
static bool F_18 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_27 + 1 ) % V_2 -> V_28 ) == V_2 -> V_29 ;
}
static bool F_19 ( struct V_1 * V_2 )
{
return V_2 -> V_27 == V_2 -> V_29 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_30 * V_31 , * V_32 ;
struct V_33 * V_34 ;
F_21 (frame, n, &ring->queue, list) {
if ( F_18 ( V_2 ) )
break;
F_22 ( & V_31 -> V_35 , & V_2 -> V_36 ) ;
V_34 = & V_2 -> V_37 [ V_2 -> V_27 ] ;
V_34 -> V_38 = V_31 -> V_39 ;
V_34 -> time = 0 ;
V_34 -> V_40 = V_41 | V_42 ;
if ( V_2 -> V_5 ) {
V_34 -> V_43 = V_31 -> V_28 ;
V_34 -> V_44 = V_31 -> V_44 ;
V_34 -> V_45 = V_31 -> V_45 ;
}
V_2 -> V_27 = ( V_2 -> V_27 + 1 ) % V_2 -> V_28 ;
F_13 ( V_2 , V_2 -> V_27 , V_2 -> V_5 ? 10 : 8 ) ;
}
}
static void F_23 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_24 ( V_47 , F_25 ( * V_2 ) , V_47 ) ;
struct V_30 * V_31 ;
bool V_48 = false ;
F_26 ( V_49 ) ;
F_27 ( & V_2 -> V_50 ) ;
if ( ! V_2 -> V_51 ) {
F_28 ( & V_2 -> V_36 , & V_49 ) ;
F_28 ( & V_2 -> V_52 , & V_49 ) ;
V_48 = true ;
goto V_53;
}
while ( ! F_19 ( V_2 ) ) {
if ( ! ( V_2 -> V_37 [ V_2 -> V_29 ] . V_40
& V_54 ) )
break;
V_31 = F_29 ( & V_2 -> V_36 , F_25 ( * V_31 ) ,
V_35 ) ;
F_22 ( & V_31 -> V_35 , & V_49 ) ;
if ( ! V_2 -> V_5 ) {
V_31 -> V_28 = V_2 -> V_37 [ V_2 -> V_29 ] . V_43 ;
V_31 -> V_44 = V_2 -> V_37 [ V_2 -> V_29 ] . V_44 ;
V_31 -> V_45 = V_2 -> V_37 [ V_2 -> V_29 ] . V_45 ;
V_31 -> V_40 = V_2 -> V_37 [ V_2 -> V_29 ] . V_40 ;
if ( V_31 -> V_45 != 0 )
F_5 ( & V_2 -> V_6 -> V_15 -> V_16 ,
L_7 ,
F_6 ( V_2 ) , V_2 -> V_4 ,
V_31 -> V_45 ) ;
if ( V_31 -> V_40 != 0xa )
F_5 ( & V_2 -> V_6 -> V_15 -> V_16 ,
L_8 ,
F_6 ( V_2 ) , V_2 -> V_4 ,
V_31 -> V_40 ) ;
}
V_2 -> V_29 = ( V_2 -> V_29 + 1 ) % V_2 -> V_28 ;
}
F_20 ( V_2 ) ;
V_53:
F_30 ( & V_2 -> V_50 ) ;
while ( ! F_31 ( & V_49 ) ) {
V_31 = F_29 ( & V_49 , F_25 ( * V_31 ) , V_35 ) ;
F_32 ( & V_31 -> V_35 ) ;
V_31 -> V_55 ( V_2 , V_31 , V_48 ) ;
}
}
int F_33 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
int V_56 = 0 ;
F_27 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_51 ) {
F_34 ( & V_31 -> V_35 , & V_2 -> V_52 ) ;
F_20 ( V_2 ) ;
} else {
V_56 = - V_57 ;
}
F_30 ( & V_2 -> V_50 ) ;
return V_56 ;
}
static struct V_1 * F_35 ( struct V_17 * V_6 , T_1 V_4 , int V_28 ,
bool V_58 )
{
struct V_1 * V_2 = NULL ;
F_4 ( & V_6 -> V_15 -> V_16 , L_9 ,
V_58 ? L_10 : L_11 , V_4 , V_28 ) ;
F_27 ( & V_6 -> V_50 ) ;
if ( V_4 >= V_6 -> V_7 ) {
F_5 ( & V_6 -> V_15 -> V_16 , L_12 , V_4 ) ;
goto V_59;
}
if ( V_58 && V_6 -> V_60 [ V_4 ] ) {
F_5 ( & V_6 -> V_15 -> V_16 , L_13 , V_4 ) ;
goto V_59;
} else if ( ! V_58 && V_6 -> V_61 [ V_4 ] ) {
F_5 ( & V_6 -> V_15 -> V_16 , L_14 , V_4 ) ;
goto V_59;
}
V_2 = F_36 ( sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
goto V_59;
F_37 ( & V_2 -> V_50 ) ;
F_38 ( & V_2 -> V_52 ) ;
F_38 ( & V_2 -> V_36 ) ;
F_39 ( & V_2 -> V_47 , F_23 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_58 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_27 = 0 ;
V_2 -> V_29 = 0 ;
V_2 -> V_51 = false ;
V_2 -> V_37 = F_40 ( & V_2 -> V_6 -> V_15 -> V_16 ,
V_28 * sizeof( * V_2 -> V_37 ) ,
& V_2 -> V_63 , V_62 | V_64 ) ;
if ( ! V_2 -> V_37 )
goto V_59;
if ( V_58 )
V_6 -> V_60 [ V_4 ] = V_2 ;
else
V_6 -> V_61 [ V_4 ] = V_2 ;
F_30 ( & V_6 -> V_50 ) ;
return V_2 ;
V_59:
if ( V_2 )
F_41 ( & V_2 -> V_50 ) ;
F_42 ( V_2 ) ;
F_30 ( & V_6 -> V_50 ) ;
return NULL ;
}
struct V_1 * F_43 ( struct V_17 * V_6 , int V_4 , int V_28 )
{
return F_35 ( V_6 , V_4 , V_28 , true ) ;
}
struct V_1 * F_44 ( struct V_17 * V_6 , int V_4 , int V_28 )
{
return F_35 ( V_6 , V_4 , V_28 , false ) ;
}
void F_45 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_6 -> V_50 ) ;
F_27 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_51 ) {
F_5 ( & V_2 -> V_6 -> V_15 -> V_16 , L_15 ) ;
goto V_59;
}
F_4 ( & V_2 -> V_6 -> V_15 -> V_16 , L_16 ,
F_6 ( V_2 ) , V_2 -> V_4 ) ;
F_16 ( V_2 , V_2 -> V_63 , 0 ) ;
if ( V_2 -> V_5 ) {
F_15 ( V_2 , V_2 -> V_28 , 12 ) ;
F_17 ( V_2 , 0 , 4 ) ;
F_17 ( V_2 ,
V_65 | V_66 , 0 ) ;
} else {
F_15 ( V_2 ,
( V_67 << 16 ) | V_2 -> V_28 , 12 ) ;
F_17 ( V_2 , 0xffffffff , 4 ) ;
F_17 ( V_2 ,
V_65 | V_66 , 0 ) ;
}
F_2 ( V_2 , true ) ;
V_2 -> V_51 = true ;
V_59:
F_30 ( & V_2 -> V_50 ) ;
F_30 ( & V_2 -> V_6 -> V_50 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_6 -> V_50 ) ;
F_27 ( & V_2 -> V_50 ) ;
F_4 ( & V_2 -> V_6 -> V_15 -> V_16 , L_17 ,
F_6 ( V_2 ) , V_2 -> V_4 ) ;
if ( ! V_2 -> V_51 ) {
F_5 ( & V_2 -> V_6 -> V_15 -> V_16 , L_18 ,
F_6 ( V_2 ) , V_2 -> V_4 ) ;
goto V_59;
}
F_2 ( V_2 , false ) ;
F_17 ( V_2 , 0 , 0 ) ;
F_16 ( V_2 , 0 , 0 ) ;
F_13 ( V_2 , 0 , V_2 -> V_5 ? 10 : 8 ) ;
F_15 ( V_2 , 0 , 12 ) ;
V_2 -> V_27 = 0 ;
V_2 -> V_29 = 0 ;
V_2 -> V_51 = false ;
V_59:
F_30 ( & V_2 -> V_50 ) ;
F_30 ( & V_2 -> V_6 -> V_50 ) ;
F_47 ( & V_2 -> V_47 ) ;
F_48 ( & V_2 -> V_47 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_6 -> V_50 ) ;
if ( V_2 -> V_5 )
V_2 -> V_6 -> V_60 [ V_2 -> V_4 ] = NULL ;
else
V_2 -> V_6 -> V_61 [ V_2 -> V_4 ] = NULL ;
if ( V_2 -> V_51 ) {
F_5 ( & V_2 -> V_6 -> V_15 -> V_16 , L_19 ,
F_6 ( V_2 ) , V_2 -> V_4 ) ;
}
F_50 ( & V_2 -> V_6 -> V_15 -> V_16 ,
V_2 -> V_28 * sizeof( * V_2 -> V_37 ) ,
V_2 -> V_37 , V_2 -> V_63 ) ;
V_2 -> V_37 = NULL ;
V_2 -> V_63 = 0 ;
F_4 ( & V_2 -> V_6 -> V_15 -> V_16 ,
L_20 ,
F_6 ( V_2 ) ,
V_2 -> V_4 ) ;
F_30 ( & V_2 -> V_6 -> V_50 ) ;
F_48 ( & V_2 -> V_47 ) ;
F_41 ( & V_2 -> V_50 ) ;
F_42 ( V_2 ) ;
}
static void F_51 ( struct V_46 * V_47 )
{
struct V_17 * V_6 = F_24 ( V_47 , F_25 ( * V_6 ) , V_68 ) ;
int V_25 = 0 ;
int V_3 ;
int V_4 = - 1 ;
int type = 0 ;
struct V_1 * V_2 ;
F_27 ( & V_6 -> V_50 ) ;
for ( V_3 = 0 ; V_3 < 3 * V_6 -> V_7 ; V_3 ++ ) {
if ( V_3 % 32 == 0 )
V_25 = F_3 ( V_6 -> V_14
+ V_19
+ 4 * ( V_3 / 32 ) ) ;
if ( ++ V_4 == V_6 -> V_7 ) {
V_4 = 0 ;
type ++ ;
}
if ( ( V_25 & ( 1 << ( V_3 % 32 ) ) ) == 0 )
continue;
if ( type == 2 ) {
F_52 ( & V_6 -> V_15 -> V_16 ,
L_21 ,
V_4 ) ;
continue;
}
if ( type == 0 )
V_2 = V_6 -> V_60 [ V_4 ] ;
else
V_2 = V_6 -> V_61 [ V_4 ] ;
if ( V_2 == NULL ) {
F_52 ( & V_6 -> V_15 -> V_16 ,
L_22 ,
type ? L_11 : L_10 ,
V_4 ) ;
continue;
}
F_47 ( & V_2 -> V_47 ) ;
}
F_30 ( & V_6 -> V_50 ) ;
}
static T_4 F_53 ( int V_69 , void * V_70 )
{
struct V_17 * V_6 = V_70 ;
F_47 ( & V_6 -> V_68 ) ;
return V_71 ;
}
static int F_54 ( struct V_72 * V_16 )
{
struct V_73 * V_15 = F_55 ( V_16 ) ;
struct V_74 * V_74 = F_56 ( V_15 ) ;
F_57 ( V_74 ) ;
return 0 ;
}
static int F_58 ( struct V_72 * V_16 )
{
struct V_73 * V_15 = F_55 ( V_16 ) ;
struct V_74 * V_74 = F_56 ( V_15 ) ;
F_59 ( V_74 ) ;
return 0 ;
}
static void F_60 ( struct V_17 * V_6 )
{
int V_18 ;
F_4 ( & V_6 -> V_15 -> V_16 , L_23 ) ;
for ( V_18 = 0 ; V_18 < V_6 -> V_7 ; V_18 ++ ) {
if ( V_6 -> V_60 [ V_18 ] )
F_5 ( & V_6 -> V_15 -> V_16 ,
L_24 , V_18 ) ;
if ( V_6 -> V_61 [ V_18 ] )
F_5 ( & V_6 -> V_15 -> V_16 ,
L_25 , V_18 ) ;
}
F_8 ( V_6 ) ;
F_61 ( & V_6 -> V_15 -> V_16 , V_6 -> V_15 -> V_69 , V_6 ) ;
F_48 ( & V_6 -> V_68 ) ;
F_41 ( & V_6 -> V_50 ) ;
}
static int F_62 ( struct V_73 * V_15 , const struct V_75 * V_76 )
{
struct V_17 * V_6 ;
struct V_74 * V_74 ;
int V_77 ;
V_77 = F_63 ( V_15 ) ;
if ( V_77 ) {
F_64 ( & V_15 -> V_16 , L_26 ) ;
return V_77 ;
}
V_77 = F_65 ( V_15 ) ;
if ( V_77 ) {
F_64 ( & V_15 -> V_16 , L_27 ) ;
return V_77 ;
}
V_77 = F_66 ( V_15 , 1 << 0 , L_28 ) ;
if ( V_77 ) {
F_64 ( & V_15 -> V_16 , L_29 ) ;
return V_77 ;
}
V_6 = F_67 ( & V_15 -> V_16 , sizeof( * V_6 ) , V_62 ) ;
if ( ! V_6 )
return - V_78 ;
V_6 -> V_15 = V_15 ;
V_6 -> V_14 = F_68 ( V_15 ) [ 0 ] ;
V_6 -> V_7 = F_3 ( V_6 -> V_14 + V_79 ) & 0x3ff ;
if ( V_6 -> V_7 != 12 )
F_52 ( & V_15 -> V_16 , L_30 ,
V_6 -> V_7 ) ;
F_39 ( & V_6 -> V_68 , F_51 ) ;
V_6 -> V_60 = F_69 ( & V_15 -> V_16 , V_6 -> V_7 ,
sizeof( * V_6 -> V_60 ) , V_62 ) ;
V_6 -> V_61 = F_69 ( & V_15 -> V_16 , V_6 -> V_7 ,
sizeof( * V_6 -> V_61 ) , V_62 ) ;
if ( ! V_6 -> V_60 || ! V_6 -> V_61 )
return - V_78 ;
F_8 ( V_6 ) ;
V_77 = F_70 ( & V_15 -> V_16 , V_15 -> V_69 , F_53 ,
V_80 ,
L_28 , V_6 ) ;
if ( V_77 ) {
F_64 ( & V_15 -> V_16 , L_31 ) ;
return V_77 ;
}
F_37 ( & V_6 -> V_50 ) ;
F_71 ( V_15 ) ;
F_7 ( 3906250 / 10000 , V_6 -> V_14 + 0x38c00 ) ;
F_4 ( & V_6 -> V_15 -> V_16 , L_32 ) ;
V_74 = F_72 ( V_6 ) ;
if ( ! V_74 ) {
F_60 ( V_6 ) ;
return - V_81 ;
}
F_73 ( V_15 , V_74 ) ;
return 0 ;
}
static void F_74 ( struct V_73 * V_15 )
{
struct V_74 * V_74 = F_56 ( V_15 ) ;
struct V_17 * V_6 = V_74 -> V_6 ;
F_75 ( V_74 ) ;
F_60 ( V_6 ) ;
}
static int T_5 F_76 ( void )
{
if ( ! F_77 ( V_82 , L_33 ) )
return - V_83 ;
return F_78 ( & V_84 ) ;
}
static void T_6 F_79 ( void )
{
F_80 ( & V_84 ) ;
}
