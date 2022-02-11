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
int V_11 = F_4 ( V_5 , V_12 - 2 , & V_13 ) ;
V_5 [ V_11 ++ ] = '\n' ;
V_5 [ V_11 ] = '\0' ;
return V_11 ;
}
static int F_5 ( struct V_14 * V_15 )
{
unsigned long V_16 ;
int V_17 , V_18 , V_19 , V_20 ;
int V_21 = V_15 -> V_21 ;
int V_22 = V_15 -> V_23 ;
F_6 ( & V_15 -> V_24 , V_16 ) ;
for ( V_18 = 0 , V_17 = 0 ; V_18 < V_21 ; V_18 ++ ) {
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ ) {
V_17 = V_18 + ( V_18 * 3 ) + V_19 ;
if ( V_15 -> V_25 & ( 1ULL << V_17 ) ) {
continue;
} else {
V_15 -> V_25 |= ( 1ULL << V_17 ) ;
V_20 = ( ( V_26 ) ( ( V_26 ) V_18 << 8 ) | ( V_27 ) ( V_19 ) ) ;
goto V_28;
}
}
}
V_20 = - V_29 ;
V_28:
F_7 ( & V_15 -> V_24 , V_16 ) ;
return V_20 ;
}
static int F_8 ( struct V_14 * V_15 ,
V_27 V_18 , V_27 V_19 )
{
unsigned long V_16 ;
int V_21 , V_22 ;
int V_17 = 0 ;
V_21 = V_15 -> V_21 ;
V_22 = V_15 -> V_23 ;
if ( ( V_18 > V_21 ) || ( V_19 > V_22 ) )
return - V_30 ;
V_17 = V_18 + V_19 + ( V_18 * 3 ) ;
F_6 ( & V_15 -> V_24 , V_16 ) ;
V_15 -> V_25 &= ~ ( 1ULL << V_17 ) ;
F_7 ( & V_15 -> V_24 , V_16 ) ;
return 0 ;
}
static int F_9 ( struct V_31 * V_7 )
{
struct V_32 * V_33 = & V_7 -> V_34 ;
struct V_14 * V_15 ;
T_2 V_35 , V_36 ;
if ( V_7 -> V_4 . type != V_7 -> V_37 -> type )
return - V_38 ;
if ( F_10 ( V_7 ) || V_7 -> V_39 & V_40 )
return - V_30 ;
if ( V_7 -> V_4 . V_41 || V_7 -> V_4 . V_42 ||
V_7 -> V_4 . V_43 || V_7 -> V_4 . V_44 )
return - V_30 ;
if ( V_7 -> V_45 < 0 )
return - V_30 ;
V_15 = & V_46 ;
if ( V_7 -> V_37 != & V_15 -> V_37 )
return - V_38 ;
if ( V_15 ) {
V_35 = V_7 -> V_4 . V_35 ;
V_36 = V_7 -> V_4 . V_36 ;
} else {
return - V_30 ;
}
V_15 -> V_21 =
F_11 ( V_47 ) ;
V_15 -> V_23 =
F_12 ( V_47 ) ;
if ( ( V_15 -> V_21 == 0 ) || ( V_15 -> V_23 == 0 ) )
return - V_30 ;
V_33 -> V_35 = V_35 ;
V_33 -> V_48 . V_35 = V_36 ;
return 0 ;
}
static void F_13 ( struct V_31 * V_49 )
{
V_27 V_50 = F_14 ( V_49 ) ;
V_26 V_51 = F_15 ( V_49 ) ;
T_2 V_52 = 0ULL ;
V_52 = V_50 ;
F_16 ( V_51 ,
F_17 ( V_49 ) , F_18 ( V_49 ) ,
V_53 , & V_52 , true ) ;
V_52 = 0ULL | V_51 | ( F_19 ( V_49 ) << 32 ) ;
if ( V_52 )
V_52 |= ( 1UL << 31 ) ;
F_16 ( V_51 ,
F_17 ( V_49 ) , F_18 ( V_49 ) ,
V_54 , & V_52 , true ) ;
V_52 = 0ULL | F_20 ( V_49 ) | ( F_21 ( V_49 ) << 32 ) ;
if ( V_52 )
V_52 |= ( 1UL << 31 ) ;
F_16 ( V_51 ,
F_17 ( V_49 ) , F_18 ( V_49 ) ,
V_55 , & V_52 , true ) ;
V_52 = 0ULL | F_22 ( V_49 ) | ( F_23 ( V_49 ) << 32 ) ;
if ( V_52 )
V_52 |= ( 1UL << 31 ) ;
F_16 ( V_51 ,
F_17 ( V_49 ) , F_18 ( V_49 ) ,
V_56 , & V_52 , true ) ;
}
static void F_24 ( struct V_31 * V_7 )
{
T_2 V_52 = 0ULL ;
F_16 ( F_15 ( V_7 ) ,
F_17 ( V_7 ) , F_18 ( V_7 ) ,
V_53 , & V_52 , true ) ;
}
static void F_25 ( struct V_31 * V_7 , int V_16 )
{
struct V_32 * V_33 = & V_7 -> V_34 ;
F_26 ( L_2 ) ;
if ( F_27 ( ! ( V_33 -> V_57 & V_58 ) ) )
return;
F_27 ( ! ( V_33 -> V_57 & V_59 ) ) ;
V_33 -> V_57 = 0 ;
if ( V_16 & V_60 ) {
T_2 V_61 = F_28 ( & V_33 -> V_62 ) ;
F_16 ( F_15 ( V_7 ) ,
F_17 ( V_7 ) , F_18 ( V_7 ) ,
V_63 , & V_61 , true ) ;
}
F_13 ( V_7 ) ;
F_29 ( V_7 ) ;
}
static void F_30 ( struct V_31 * V_7 )
{
T_2 V_64 = 0ULL ;
T_2 V_61 = 0ULL ;
T_2 V_65 = 0ULL ;
struct V_32 * V_33 = & V_7 -> V_34 ;
F_26 ( L_3 ) ;
F_16 ( F_15 ( V_7 ) ,
F_17 ( V_7 ) , F_18 ( V_7 ) ,
V_63 , & V_64 , false ) ;
V_64 &= 0xFFFFFFFFFFFFULL ;
V_61 = F_28 ( & V_33 -> V_62 ) ;
if ( F_31 ( & V_33 -> V_62 , V_61 ,
V_64 ) != V_61 )
return;
V_65 = ( V_64 << V_66 ) - ( V_61 << V_66 ) ;
V_65 >>= V_66 ;
F_32 ( V_65 , & V_7 -> V_64 ) ;
}
static void F_33 ( struct V_31 * V_7 , int V_16 )
{
struct V_32 * V_33 = & V_7 -> V_34 ;
T_2 V_35 ;
F_26 ( L_4 ) ;
if ( V_33 -> V_57 & V_59 )
return;
F_24 ( V_7 ) ;
F_27 ( V_33 -> V_57 & V_58 ) ;
V_33 -> V_57 |= V_58 ;
if ( V_33 -> V_57 & V_59 )
return;
V_35 = V_33 -> V_35 ;
F_30 ( V_7 ) ;
V_33 -> V_57 |= V_59 ;
}
static int F_34 ( struct V_31 * V_7 , int V_16 )
{
int V_20 ;
struct V_14 * V_15 =
F_2 ( V_7 -> V_37 , struct V_14 , V_37 ) ;
F_26 ( L_5 ) ;
V_7 -> V_34 . V_57 = V_59 | V_58 ;
V_20 = F_5 ( V_15 ) ;
if ( V_20 != - V_29 )
V_7 -> V_34 . V_48 . V_52 = ( V_26 ) V_20 ;
else
return V_20 ;
if ( V_16 & V_67 )
F_25 ( V_7 , V_60 ) ;
return 0 ;
}
static void F_35 ( struct V_31 * V_7 , int V_16 )
{
struct V_14 * V_15 =
F_2 ( V_7 -> V_37 , struct V_14 , V_37 ) ;
F_26 ( L_6 ) ;
F_33 ( V_7 , V_68 ) ;
F_8 ( V_15 ,
F_17 ( V_7 ) ,
F_18 ( V_7 ) ) ;
F_29 ( V_7 ) ;
}
static T_3 int F_36 ( struct V_14 * V_15 )
{
struct V_69 * * V_70 ;
struct V_71 * V_72 ;
int V_73 = 0 , V_74 ;
while ( V_75 [ V_73 ] . V_4 . V_4 . V_76 )
V_73 ++ ;
V_72 = F_37 ( sizeof( struct V_69 * )
* ( V_73 + 1 ) + sizeof( * V_72 ) , V_77 ) ;
if ( ! V_72 )
return - V_78 ;
V_70 = (struct V_69 * * ) ( V_72 + 1 ) ;
for ( V_74 = 0 ; V_74 < V_73 ; V_74 ++ )
V_70 [ V_74 ] = & V_75 [ V_74 ] . V_4 . V_4 ;
V_72 -> V_76 = L_7 ;
V_72 -> V_70 = V_70 ;
V_15 -> V_79 = V_72 ;
return 0 ;
}
static T_3 void F_38 ( void )
{
if ( V_46 . V_79 != NULL ) {
F_39 ( V_46 . V_79 ) ;
V_46 . V_79 = NULL ;
}
}
static T_3 int F_40 (
struct V_14 * V_15 , char * V_76 )
{
int V_80 ;
F_41 ( & V_15 -> V_24 ) ;
V_15 -> V_81 = & V_82 ;
F_42 ( 0 , & V_13 ) ;
V_15 -> V_83 = & V_84 ;
if ( F_36 ( V_15 ) != 0 )
F_43 ( L_8 ) ;
V_15 -> V_85 = NULL ;
V_15 -> V_37 . V_86 = V_15 -> V_86 ;
V_80 = F_44 ( & V_15 -> V_37 , V_76 , - 1 ) ;
if ( V_80 ) {
F_43 ( L_9 ) ;
F_38 () ;
} else {
F_45 ( L_10 ,
F_11 ( V_47 ) ,
F_12 ( V_47 ) ) ;
}
return V_80 ;
}
static T_3 int F_46 ( void )
{
if ( ! F_47 () )
return - V_87 ;
F_40 ( & V_46 , L_11 ) ;
return 0 ;
}
