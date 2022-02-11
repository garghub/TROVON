static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_4 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_7 ) ;
}
static T_1 F_3 ( struct V_8 * V_9 ,
struct V_10 * V_4 ,
char * V_5 )
{
return F_4 ( true , V_5 , & V_11 ) ;
}
static int F_5 ( struct V_12 * V_13 )
{
unsigned long V_14 ;
int V_15 , V_16 , V_17 , V_18 ;
int V_19 = V_13 -> V_19 ;
int V_20 = V_13 -> V_21 ;
F_6 ( & V_13 -> V_22 , V_14 ) ;
for ( V_16 = 0 , V_15 = 0 ; V_16 < V_19 ; V_16 ++ ) {
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ ) {
V_15 = V_16 + ( V_16 * 3 ) + V_17 ;
if ( V_13 -> V_23 & ( 1ULL << V_15 ) ) {
continue;
} else {
V_13 -> V_23 |= ( 1ULL << V_15 ) ;
V_18 = ( ( V_24 ) ( ( V_24 ) V_16 << 8 ) | ( V_25 ) ( V_17 ) ) ;
goto V_26;
}
}
}
V_18 = - V_27 ;
V_26:
F_7 ( & V_13 -> V_22 , V_14 ) ;
return V_18 ;
}
static int F_8 ( struct V_12 * V_13 ,
V_25 V_16 , V_25 V_17 )
{
unsigned long V_14 ;
int V_19 , V_20 ;
int V_15 = 0 ;
V_19 = V_13 -> V_19 ;
V_20 = V_13 -> V_21 ;
if ( ( V_16 > V_19 ) || ( V_17 > V_20 ) )
return - V_28 ;
V_15 = V_16 + V_17 + ( V_16 * 3 ) ;
F_6 ( & V_13 -> V_22 , V_14 ) ;
V_13 -> V_23 &= ~ ( 1ULL << V_15 ) ;
F_7 ( & V_13 -> V_22 , V_14 ) ;
return 0 ;
}
static int F_9 ( struct V_29 * V_7 )
{
struct V_30 * V_31 = & V_7 -> V_32 ;
struct V_12 * V_13 ;
T_2 V_33 , V_34 ;
if ( V_7 -> V_4 . type != V_7 -> V_35 -> type )
return - V_36 ;
if ( F_10 ( V_7 ) || V_7 -> V_37 & V_38 )
return - V_28 ;
if ( V_7 -> V_4 . V_39 || V_7 -> V_4 . V_40 ||
V_7 -> V_4 . V_41 || V_7 -> V_4 . V_42 )
return - V_28 ;
if ( V_7 -> V_43 < 0 )
return - V_28 ;
V_13 = & V_44 ;
if ( V_7 -> V_35 != & V_13 -> V_35 )
return - V_36 ;
if ( V_13 ) {
V_33 = V_7 -> V_4 . V_33 ;
V_34 = V_7 -> V_4 . V_34 ;
} else {
return - V_28 ;
}
V_13 -> V_19 =
F_11 ( V_45 ) ;
V_13 -> V_21 =
F_12 ( V_45 ) ;
if ( ( V_13 -> V_19 == 0 ) || ( V_13 -> V_21 == 0 ) )
return - V_28 ;
V_31 -> V_33 = V_33 ;
V_31 -> V_46 . V_33 = V_34 ;
return 0 ;
}
static void F_13 ( struct V_29 * V_47 )
{
V_25 V_48 = F_14 ( V_47 ) ;
V_24 V_49 = F_15 ( V_47 ) ;
T_2 V_50 = 0ULL ;
V_50 = V_48 ;
F_16 ( V_49 ,
F_17 ( V_47 ) , F_18 ( V_47 ) ,
V_51 , & V_50 , true ) ;
V_50 = 0ULL | V_49 | ( F_19 ( V_47 ) << 32 ) ;
if ( V_50 )
V_50 |= ( 1UL << 31 ) ;
F_16 ( V_49 ,
F_17 ( V_47 ) , F_18 ( V_47 ) ,
V_52 , & V_50 , true ) ;
V_50 = 0ULL | F_20 ( V_47 ) | ( F_21 ( V_47 ) << 32 ) ;
if ( V_50 )
V_50 |= ( 1UL << 31 ) ;
F_16 ( V_49 ,
F_17 ( V_47 ) , F_18 ( V_47 ) ,
V_53 , & V_50 , true ) ;
V_50 = 0ULL | F_22 ( V_47 ) | ( F_23 ( V_47 ) << 32 ) ;
if ( V_50 )
V_50 |= ( 1UL << 31 ) ;
F_16 ( V_49 ,
F_17 ( V_47 ) , F_18 ( V_47 ) ,
V_54 , & V_50 , true ) ;
}
static void F_24 ( struct V_29 * V_7 )
{
T_2 V_50 = 0ULL ;
F_16 ( F_15 ( V_7 ) ,
F_17 ( V_7 ) , F_18 ( V_7 ) ,
V_51 , & V_50 , true ) ;
}
static void F_25 ( struct V_29 * V_7 , int V_14 )
{
struct V_30 * V_31 = & V_7 -> V_32 ;
F_26 ( L_2 ) ;
if ( F_27 ( ! ( V_31 -> V_55 & V_56 ) ) )
return;
F_27 ( ! ( V_31 -> V_55 & V_57 ) ) ;
V_31 -> V_55 = 0 ;
if ( V_14 & V_58 ) {
T_2 V_59 = F_28 ( & V_31 -> V_60 ) ;
F_16 ( F_15 ( V_7 ) ,
F_17 ( V_7 ) , F_18 ( V_7 ) ,
V_61 , & V_59 , true ) ;
}
F_13 ( V_7 ) ;
F_29 ( V_7 ) ;
}
static void F_30 ( struct V_29 * V_7 )
{
T_2 V_62 = 0ULL ;
T_2 V_59 = 0ULL ;
T_2 V_63 = 0ULL ;
struct V_30 * V_31 = & V_7 -> V_32 ;
F_26 ( L_3 ) ;
F_16 ( F_15 ( V_7 ) ,
F_17 ( V_7 ) , F_18 ( V_7 ) ,
V_61 , & V_62 , false ) ;
V_62 &= 0xFFFFFFFFFFFFULL ;
V_59 = F_28 ( & V_31 -> V_60 ) ;
if ( F_31 ( & V_31 -> V_60 , V_59 ,
V_62 ) != V_59 )
return;
V_63 = ( V_62 << V_64 ) - ( V_59 << V_64 ) ;
V_63 >>= V_64 ;
F_32 ( V_63 , & V_7 -> V_62 ) ;
}
static void F_33 ( struct V_29 * V_7 , int V_14 )
{
struct V_30 * V_31 = & V_7 -> V_32 ;
T_2 V_33 ;
F_26 ( L_4 ) ;
if ( V_31 -> V_55 & V_57 )
return;
F_24 ( V_7 ) ;
F_27 ( V_31 -> V_55 & V_56 ) ;
V_31 -> V_55 |= V_56 ;
if ( V_31 -> V_55 & V_57 )
return;
V_33 = V_31 -> V_33 ;
F_30 ( V_7 ) ;
V_31 -> V_55 |= V_57 ;
}
static int F_34 ( struct V_29 * V_7 , int V_14 )
{
int V_18 ;
struct V_12 * V_13 =
F_2 ( V_7 -> V_35 , struct V_12 , V_35 ) ;
F_26 ( L_5 ) ;
V_7 -> V_32 . V_55 = V_57 | V_56 ;
V_18 = F_5 ( V_13 ) ;
if ( V_18 != - V_27 )
V_7 -> V_32 . V_46 . V_50 = ( V_24 ) V_18 ;
else
return V_18 ;
if ( V_14 & V_65 )
F_25 ( V_7 , V_58 ) ;
return 0 ;
}
static void F_35 ( struct V_29 * V_7 , int V_14 )
{
struct V_12 * V_13 =
F_2 ( V_7 -> V_35 , struct V_12 , V_35 ) ;
F_26 ( L_6 ) ;
F_33 ( V_7 , V_66 ) ;
F_8 ( V_13 ,
F_17 ( V_7 ) ,
F_18 ( V_7 ) ) ;
F_29 ( V_7 ) ;
}
static T_3 int F_36 ( struct V_12 * V_13 )
{
struct V_67 * * V_68 ;
struct V_69 * V_70 ;
int V_71 = 0 , V_72 ;
while ( V_73 [ V_71 ] . V_4 . V_4 . V_74 )
V_71 ++ ;
V_70 = F_37 ( sizeof( struct V_67 * )
* ( V_71 + 1 ) + sizeof( * V_70 ) , V_75 ) ;
if ( ! V_70 )
return - V_76 ;
V_68 = (struct V_67 * * ) ( V_70 + 1 ) ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ )
V_68 [ V_72 ] = & V_73 [ V_72 ] . V_4 . V_4 ;
V_70 -> V_74 = L_7 ;
V_70 -> V_68 = V_68 ;
V_13 -> V_77 = V_70 ;
return 0 ;
}
static T_3 void F_38 ( void )
{
if ( V_44 . V_77 != NULL ) {
F_39 ( V_44 . V_77 ) ;
V_44 . V_77 = NULL ;
}
}
static T_3 int F_40 (
struct V_12 * V_13 , char * V_74 )
{
int V_78 ;
F_41 ( & V_13 -> V_22 ) ;
V_13 -> V_79 = & V_80 ;
F_42 ( 0 , & V_11 ) ;
V_13 -> V_81 = & V_82 ;
if ( F_36 ( V_13 ) != 0 )
F_43 ( L_8 ) ;
V_13 -> V_83 = NULL ;
V_13 -> V_35 . V_84 = V_13 -> V_84 ;
V_78 = F_44 ( & V_13 -> V_35 , V_74 , - 1 ) ;
if ( V_78 ) {
F_43 ( L_9 ) ;
F_38 () ;
} else {
F_45 ( L_10 ,
F_11 ( V_45 ) ,
F_12 ( V_45 ) ) ;
}
return V_78 ;
}
static T_3 int F_46 ( void )
{
if ( ! F_47 () )
return - V_85 ;
F_40 ( & V_44 , L_11 ) ;
return 0 ;
}
