static void F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_3 + V_1 ) ;
}
static T_1 F_3 ( T_1 V_1 )
{
return F_4 ( V_3 + V_1 ) ;
}
void F_5 ( void )
{
int V_4 ;
V_5 . V_6 =
F_3 ( V_7 ) ;
V_5 . V_8 =
F_3 ( V_9 ) ;
V_5 . V_10 =
F_3 ( V_11 ) ;
V_5 . V_12 =
F_3 ( V_13 ) ;
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ )
V_5 . V_15 [ V_4 ] =
F_3 ( ( V_16 + 0x4 * V_4 ) ) ;
for ( V_4 = 0 ; V_4 < V_17 ; V_4 ++ )
V_5 . V_18 [ V_4 ] =
F_3 ( V_19 + ( 0x20 * V_4 ) ) ;
}
void F_6 ( void )
{
int V_4 ;
F_1 ( V_7 , V_5 . V_6 ) ;
F_1 ( V_9 , V_5 . V_8 ) ;
F_1 ( V_11 , V_5 . V_10 ) ;
F_1 ( V_13 , V_5 . V_12 ) ;
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ )
F_1 ( V_16 + 0x4 * V_4 ,
V_5 . V_15 [ V_4 ] ) ;
for ( V_4 = 0 ; V_4 < V_17 ; V_4 ++ )
F_1 ( V_19 + 0x20 * V_4 ,
V_5 . V_18 [ V_4 ] ) ;
}
void F_7 ( void )
{
F_1 ( V_7 , 0 ) ;
F_1 ( V_11 , V_20 ) ;
}
void F_8 ( void )
{
F_1 ( V_7 , 1 ) ;
F_1 ( V_11 , 0 ) ;
}
static void F_9 ( struct V_21 * V_22 )
{
F_1 ( V_23 , 0x1 ) ;
}
static void F_10 ( struct V_21 * V_22 )
{
F_11 ( V_22 ) ;
F_9 ( V_22 ) ;
}
static void T_2 F_12 ( void )
{
unsigned long V_24 ;
V_24 = F_3 ( V_25 ) & 0xff ;
F_13 ( L_1 ,
V_3 , V_24 >> 4 , V_24 & 0xf , V_14 ) ;
V_24 = F_3 ( V_7 ) ;
V_24 |= 1 << 1 ;
F_1 ( V_7 , V_24 ) ;
while ( ! ( F_3 ( V_26 ) & 0x1 ) )
;
F_1 ( V_7 , 1 << 0 ) ;
}
int F_14 ( void )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_27 ; V_4 ++ )
if ( F_3 ( V_28 + ( 0x20 * V_4 ) ) )
return 1 ;
return 0 ;
}
void F_15 ( void )
{
F_9 ( NULL ) ;
}
static int T_2 F_16 ( struct V_29 * V_22 , void T_3 * V_30 )
{
int V_31 ;
int V_4 ;
V_31 = F_17 ( V_22 , 32 , 1 , L_2 ,
V_32 , V_33 | V_34 ,
V_35 , 0 ) ;
if ( V_31 ) {
F_18 ( L_3 ) ;
return V_31 ;
}
for ( V_4 = 0 ; V_4 < V_27 ; V_4 ++ ) {
struct V_36 * V_37 ;
struct V_38 * V_39 ;
V_37 = F_19 ( V_22 , 32 * V_4 ) ;
V_37 -> V_40 = V_30 ;
V_39 = V_37 -> V_41 ;
V_39 -> type = V_42 ;
V_39 -> V_43 = V_32 ;
V_39 -> V_44 . V_45 = F_10 ;
V_39 -> V_44 . V_46 = F_11 ;
V_39 -> V_44 . V_47 = V_48 ;
V_39 -> V_44 . V_49 |= V_50 ;
V_39 -> V_51 . V_52 = V_53 + 32 * V_4 ;
V_39 -> V_51 . V_54 = V_55 + 32 * V_4 ;
}
return 0 ;
}
static void T_2 F_20 ( void T_3 * V_30 ,
unsigned int V_56 , unsigned int V_57 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 ;
V_37 = F_21 ( L_2 , 1 , V_56 , V_30 ,
V_32 ) ;
V_39 = V_37 -> V_41 ;
V_39 -> V_44 . V_45 = F_10 ;
V_39 -> V_44 . V_46 = F_11 ;
V_39 -> V_44 . V_47 = V_48 ;
V_39 -> V_44 . V_49 |= V_50 ;
V_39 -> V_51 . V_52 = V_53 ;
V_39 -> V_51 . V_54 = V_55 ;
F_22 ( V_37 , F_23 ( V_57 ) , V_58 ,
V_33 | V_34 , 0 ) ;
}
static int T_2 F_24 ( struct V_59 * V_60 )
{
int V_31 ;
V_3 = F_25 ( V_60 , 0 ) ;
if ( F_26 ( ! V_3 ) )
return - V_61 ;
V_62 = F_27 ( V_60 , V_14 ,
& V_63 , NULL ) ;
F_12 () ;
V_31 = F_16 ( V_62 , V_3 ) ;
if ( V_31 < 0 )
F_28 ( V_62 ) ;
return V_31 ;
}
static int T_2 F_29 ( T_1 V_30 , struct V_59 * V_60 )
{
int V_64 , V_65 ;
V_3 = F_30 ( V_30 , V_66 ) ;
if ( F_26 ( ! V_3 ) )
return - V_61 ;
V_65 = F_31 ( - 1 , 0 , V_14 , 0 ) ;
if ( V_65 < 0 ) {
F_18 ( L_4 ) ;
V_65 = 0 ;
}
V_62 = F_32 ( V_60 , V_14 , V_65 , 0 ,
& V_67 , NULL ) ;
F_12 () ;
for ( V_64 = 0 ; V_64 < V_14 ; V_64 += 32 )
F_20 ( V_3 + V_64 , V_64 + V_65 , 32 ) ;
return 0 ;
}
static void T_2 F_33 ( void )
{
T_1 V_1 ;
V_1 = F_3 ( V_9 ) ;
V_1 |= V_68 ;
F_1 ( V_9 , V_1 ) ;
}
static int T_2 F_34 ( T_1 V_30 , struct V_59 * V_60 )
{
int V_31 ;
if ( F_35 ( V_60 , L_5 ) ||
F_35 ( V_60 , L_6 ) ) {
struct V_69 V_70 ;
if ( F_36 ( V_60 , 0 , & V_70 ) )
return - V_61 ;
V_30 = V_70 . V_71 ;
V_31 = F_29 ( V_30 , V_60 ) ;
} else if ( V_60 ) {
V_31 = F_24 ( V_60 ) ;
} else {
V_31 = F_29 ( V_30 , NULL ) ;
}
if ( V_31 == 0 )
F_33 () ;
return V_31 ;
}
static T_4 void T_5
F_37 ( struct V_72 * V_51 )
{
T_1 V_73 = 0 ;
int V_74 = 0 ;
int V_4 ;
do {
for ( V_4 = 0 ; V_4 < V_27 ; V_4 ++ ) {
V_73 = F_3 ( V_28 + ( 0x20 * V_4 ) ) ;
if ( V_73 )
goto V_75;
}
V_75:
if ( ! V_73 )
break;
V_73 = F_3 ( V_76 ) ;
V_73 &= V_77 ;
if ( V_73 ) {
F_38 ( V_62 , V_73 , V_51 ) ;
V_74 = 1 ;
}
} while ( V_73 );
if ( ! V_74 )
F_9 ( NULL ) ;
}
void T_2 F_39 ( void )
{
V_14 = 96 ;
V_27 = 3 ;
F_34 ( V_78 , NULL ) ;
F_40 ( F_37 ) ;
}
void T_2 F_41 ( void )
{
V_14 = 96 ;
V_27 = 3 ;
F_34 ( V_79 , NULL ) ;
F_40 ( F_37 ) ;
}
void T_2 F_42 ( void )
{
V_14 = 96 ;
V_27 = 4 ;
F_34 ( V_79 , NULL ) ;
F_40 ( F_37 ) ;
}
static int T_2 F_43 ( struct V_59 * V_60 ,
struct V_59 * V_80 )
{
int V_31 ;
V_27 = 3 ;
V_14 = 96 ;
if ( F_26 ( ! V_60 ) )
return - V_81 ;
if ( F_35 ( V_60 , L_7 ) ) {
V_14 = 128 ;
V_27 = 4 ;
}
V_31 = F_34 ( - 1 , F_44 ( V_60 ) ) ;
if ( V_31 < 0 )
return V_31 ;
F_40 ( F_37 ) ;
return 0 ;
}
