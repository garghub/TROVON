void F_1 ( unsigned int V_1 )
{
int V_2 = 1000000 ;
F_2 ( & V_3 ) ;
F_3 ( F_4 ( V_4 ) & ~ V_1 , V_4 ) ;
do {} while ( -- V_2 && ( F_4 ( V_5 ) & V_1 ) );
F_5 ( & V_3 ) ;
if ( ! V_2 )
F_6 ( L_1 ) ;
}
void F_7 ( unsigned int V_1 )
{
int V_2 = 1000000 ;
F_2 ( & V_3 ) ;
F_3 ( F_4 ( V_4 ) | V_1 , V_4 ) ;
do {} while ( -- V_2 && ( ! ( F_4 ( V_5 ) & V_1 ) ) );
F_5 ( & V_3 ) ;
if ( ! V_2 )
F_8 ( L_2 ) ;
}
static int F_9 ( struct V_6 * V_6 )
{
F_10 ( F_11 ( V_7 ) | V_6 -> V_8 , V_7 ) ;
return 0 ;
}
static void F_12 ( struct V_6 * V_6 )
{
F_10 ( F_11 ( V_7 ) & ~ V_6 -> V_8 , V_7 ) ;
}
static int F_13 ( struct V_6 * V_6 )
{
int V_2 = 1000000 ;
if ( F_14 ( L_3 )
|| F_14 ( L_4 ) ) {
F_3 ( V_6 -> V_8 , F_15 ( V_6 -> V_1 ) ) ;
do {} while ( -- V_2 &&
( ! ( F_4 ( F_16 ( V_6 -> V_1 ) ) & V_6 -> V_8 ) ) );
} else {
F_2 ( & V_3 ) ;
F_3 ( F_4 ( F_17 ( V_6 -> V_1 ) ) & ~ V_6 -> V_8 ,
F_17 ( V_6 -> V_1 ) ) ;
do {} while ( -- V_2 &&
( F_4 ( F_18 ( V_6 -> V_1 ) ) & V_6 -> V_8 ) );
F_5 ( & V_3 ) ;
}
if ( ! V_2 )
F_6 ( L_1 ) ;
return 0 ;
}
static void F_19 ( struct V_6 * V_6 )
{
int V_2 = 1000000 ;
if ( F_14 ( L_3 )
|| F_14 ( L_4 ) ) {
F_3 ( V_6 -> V_8 , F_20 ( V_6 -> V_1 ) ) ;
do {} while ( -- V_2 &&
( F_4 ( F_16 ( V_6 -> V_1 ) ) & V_6 -> V_8 ) );
} else {
F_2 ( & V_3 ) ;
F_3 ( F_4 ( F_17 ( V_6 -> V_1 ) ) | V_6 -> V_8 ,
F_17 ( V_6 -> V_1 ) ) ;
do {} while ( -- V_2 &&
( ! ( F_4 ( F_18 ( V_6 -> V_1 ) ) & V_6 -> V_8 ) ) );
F_5 ( & V_3 ) ;
}
if ( ! V_2 )
F_8 ( L_2 ) ;
}
static int F_21 ( struct V_6 * V_6 )
{
unsigned int V_9 = F_11 ( V_7 ) ;
if ( F_14 ( L_5 ) ||
F_14 ( L_6 ) ) {
V_9 &= ~ 0x1f00000 ;
if ( V_6 -> V_10 == V_11 )
V_9 |= 0xe00000 ;
else
V_9 |= 0x700000 ;
} else {
V_9 &= ~ 0xf00000 ;
if ( V_6 -> V_10 == V_11 )
V_9 |= 0x800000 ;
else
V_9 |= 0x400000 ;
}
F_10 ( V_9 , V_7 ) ;
F_13 ( V_6 ) ;
return 0 ;
}
static int F_22 ( struct V_6 * V_6 )
{
F_10 ( F_11 ( V_7 ) & ~ ( 1 << 16 ) , V_7 ) ;
F_10 ( ( 1 << 30 ) , V_12 ) ;
return 0 ;
}
static void F_23 ( struct V_6 * V_6 )
{
F_10 ( F_11 ( V_7 ) | ( 1 << 16 ) , V_7 ) ;
F_10 ( ( 1 << 31 ) | ( 1 << 30 ) , V_12 ) ;
}
static int F_24 ( struct V_6 * V_6 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
if ( V_6 -> V_14 [ V_13 ] == V_6 -> V_10 ) {
int V_15 = 14 - ( 2 * V_6 -> V_1 ) ;
int V_16 = 7 - V_6 -> V_1 ;
unsigned int V_9 = F_11 ( V_7 ) ;
V_9 &= ~ ( 3 << V_15 ) ;
V_9 |= V_13 << V_15 ;
V_9 |= V_16 ;
F_10 ( V_9 , V_7 ) ;
return 0 ;
}
}
return - 1 ;
}
static void F_25 ( const char * V_17 , const char * V_18 , bool V_19 ,
unsigned int V_1 , unsigned int V_8 )
{
struct V_6 * V_6 = F_26 ( sizeof( struct V_6 ) , V_20 ) ;
V_6 -> V_21 . V_22 = V_17 ;
V_6 -> V_21 . V_23 = V_18 ;
V_6 -> V_21 . V_6 = V_6 ;
V_6 -> V_16 = F_13 ;
V_6 -> V_24 = F_19 ;
V_6 -> V_1 = V_1 ;
V_6 -> V_8 = V_8 ;
if ( V_19 ) {
F_19 ( V_6 ) ;
}
F_27 ( & V_6 -> V_21 ) ;
}
static void F_28 ( const char * V_17 , const char * V_18 ,
unsigned int V_8 )
{
struct V_6 * V_6 = F_26 ( sizeof( struct V_6 ) , V_20 ) ;
V_6 -> V_21 . V_22 = V_17 ;
V_6 -> V_21 . V_23 = V_18 ;
V_6 -> V_21 . V_6 = V_6 ;
V_6 -> V_16 = F_9 ;
V_6 -> V_24 = F_12 ;
V_6 -> V_8 = V_8 ;
F_27 ( & V_6 -> V_21 ) ;
}
static void F_29 ( void )
{
struct V_6 * V_6 = F_26 ( sizeof( struct V_6 ) , V_20 ) ;
struct V_6 * V_25 = F_26 ( sizeof( struct V_6 ) , V_20 ) ;
V_6 -> V_21 . V_22 = L_7 ;
V_6 -> V_21 . V_23 = NULL ;
V_6 -> V_21 . V_6 = V_6 ;
V_6 -> V_10 = V_11 ;
V_6 -> V_14 = V_26 ;
V_6 -> V_16 = F_21 ;
V_6 -> V_24 = F_19 ;
V_6 -> V_1 = 0 ;
V_6 -> V_8 = V_27 ;
F_27 ( & V_6 -> V_21 ) ;
V_25 -> V_21 . V_22 = L_7 ;
V_25 -> V_21 . V_23 = L_8 ;
V_25 -> V_21 . V_6 = V_25 ;
V_25 -> V_16 = F_22 ;
V_25 -> V_24 = F_23 ;
F_27 ( & V_25 -> V_21 ) ;
}
static void F_30 ( void )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
struct V_6 * V_6 ;
char * V_28 ;
V_28 = F_26 ( sizeof( L_9 ) , V_20 ) ;
sprintf ( V_28 , L_10 , V_13 ) ;
V_6 = F_26 ( sizeof( struct V_6 ) , V_20 ) ;
V_6 -> V_21 . V_22 = L_11 ;
V_6 -> V_21 . V_23 = V_28 ;
V_6 -> V_21 . V_6 = V_6 ;
V_6 -> V_10 = 0 ;
V_6 -> V_14 = V_29 [ V_13 ] ;
V_6 -> V_16 = F_24 ;
V_6 -> V_1 = V_13 ;
F_27 ( & V_6 -> V_21 ) ;
}
}
void T_1 F_31 ( void )
{
struct V_30 V_31 , V_32 , V_33 ;
struct V_34 * V_35 =
F_32 ( NULL , NULL , L_12 ) ;
struct V_34 * V_36 =
F_32 ( NULL , NULL , L_13 ) ;
struct V_34 * V_37 =
F_32 ( NULL , NULL , L_14 ) ;
if ( ! V_35 || ! V_36 || ! V_37 )
F_6 ( L_15 ) ;
if ( F_33 ( V_35 , 0 , & V_31 ) ||
F_33 ( V_36 , 0 , & V_32 ) ||
F_33 ( V_37 , 0 , & V_33 ) )
F_6 ( L_16 ) ;
if ( ! F_34 ( V_31 . V_38 , F_35 ( & V_31 ) ,
V_31 . V_28 ) ||
! F_34 ( V_32 . V_38 , F_35 ( & V_32 ) ,
V_32 . V_28 ) ||
! F_34 ( V_33 . V_38 , F_35 ( & V_33 ) ,
V_33 . V_28 ) )
F_36 ( L_17 ) ;
V_39 = F_37 ( V_31 . V_38 , F_35 ( & V_31 ) ) ;
V_40 = F_37 ( V_32 . V_38 ,
F_35 ( & V_32 ) ) ;
V_41 = F_37 ( V_33 . V_38 ,
F_35 ( & V_33 ) ) ;
if ( ! V_39 || ! V_40 || ! V_41 )
F_6 ( L_18 ) ;
F_38 ( F_39 ( V_42 ) & ~ V_43 , V_42 ) ;
F_25 ( L_19 , NULL , 0 , 0 , V_44 ) ;
F_25 ( L_20 , NULL , 0 , 0 , V_45 ) ;
F_25 ( L_21 , NULL , 1 , 0 , V_46 ) ;
F_25 ( L_22 , NULL , 1 , 0 , V_47 ) ;
F_25 ( L_23 , NULL , 1 , 0 , V_48 ) ;
F_25 ( L_24 , NULL , 1 , 0 , V_49 ) ;
F_25 ( L_25 , NULL , 0 , 0 , V_50 ) ;
F_30 () ;
if ( F_14 ( L_6 ) ) {
V_7 = V_51 ;
V_12 = V_52 ;
} else {
F_25 ( L_26 , NULL , 1 , 0 , V_53 ) ;
}
if ( ! F_14 ( L_27 ) ) {
F_25 ( L_28 , NULL , 0 , 0 , V_54 ) ;
F_29 () ;
}
if ( F_14 ( L_4 ) ||
F_14 ( L_3 ) ) {
F_25 ( L_29 , L_30 , 1 , 2 , V_55 ) ;
F_25 ( L_31 , L_30 , 1 , 2 , V_56 ) ;
F_25 ( L_32 , L_30 , 1 , 2 , V_57 ) ;
F_25 ( L_32 , L_33 , 1 , 1 , V_58 ) ;
F_25 ( L_32 , L_34 , 1 , 1 , V_59 ) ;
F_25 ( L_32 , L_35 , 1 , 1 , V_60 ) ;
F_25 ( L_36 , L_30 , 1 , 2 , V_61 ) ;
F_25 ( L_36 , L_33 , 1 , 1 , V_62 ) ;
F_25 ( L_36 , L_34 , 1 , 1 , V_63 ) ;
F_25 ( L_36 , L_35 , 1 , 1 , V_64 ) ;
}
if ( F_14 ( L_27 ) ) {
if ( F_11 ( V_65 ) & ( 1 << 5 ) )
F_40 ( V_66 , V_67 ,
V_67 , V_66 ) ;
else
F_40 ( V_67 , V_67 ,
V_67 , V_67 ) ;
F_25 ( L_37 , L_38 , 1 , 0 , V_68 ) ;
F_25 ( L_29 , L_30 , 1 , 0 , V_69 ) ;
F_25 ( L_26 , L_39 , 1 , 0 , V_53 ) ;
F_28 ( L_26 , L_40 , V_70 ) ;
F_25 ( L_26 , L_41 , 1 , 0 , V_71 ) ;
F_25 ( L_42 , NULL , 1 , 0 , V_72 ) ;
F_25 ( L_43 , L_44 , 1 , 0 , V_73 ) ;
} else if ( F_14 ( L_4 ) ) {
F_40 ( F_41 () , F_42 () ,
F_42 () , F_43 () ) ;
F_25 ( L_37 , L_38 , 1 , 0 , V_68 ) ;
F_25 ( L_45 , L_38 , 1 , 0 , V_74 ) ;
F_25 ( L_46 , L_30 , 1 , 2 , V_75 ) ;
F_25 ( L_46 , L_33 , 1 , 1 , V_76 ) ;
F_25 ( L_46 , L_34 , 1 , 1 , V_77 ) ;
F_25 ( L_46 , L_35 , 1 , 1 , V_78 ) ;
F_25 ( L_47 , NULL , 0 , 0 , V_79 | V_80 ) ;
F_25 ( L_48 , L_49 , 1 , 0 , V_81 ) ;
F_25 ( L_50 , NULL , 1 , 0 , V_82 ) ;
} else if ( F_14 ( L_3 ) ) {
F_40 ( F_44 () , F_45 () ,
F_45 () , F_46 () ) ;
F_25 ( L_37 , L_38 , 1 , 0 , V_68 ) ;
F_25 ( L_45 , L_38 , 1 , 0 , V_74 ) ;
F_25 ( L_47 , NULL , 0 , 0 , V_79 |
V_80 | V_83 ) ;
F_25 ( L_48 , L_49 , 1 , 0 , V_81 ) ;
F_25 ( L_51 , NULL , 1 , 0 , V_84 ) ;
F_25 ( L_52 , NULL , 1 , 0 , V_84 ) ;
F_25 ( L_50 , NULL , 1 , 0 , V_82 ) ;
F_25 ( L_43 , L_53 , 1 , 2 , V_85 ) ;
F_25 ( L_43 , L_44 , 1 , 0 , V_73 ) ;
} else if ( F_14 ( L_6 ) ) {
F_40 ( F_47 () , F_48 () ,
F_48 () , F_49 () ) ;
F_25 ( L_29 , L_30 , 1 , 0 , V_69 ) ;
F_25 ( L_37 , L_38 , 1 , 0 , V_68 | V_86 ) ;
F_25 ( L_31 , L_30 , 1 , 0 , V_87 ) ;
F_25 ( L_45 , L_38 , 1 , 0 , V_74 | V_86 ) ;
F_25 ( L_32 , L_30 , 1 , 1 , V_88 ) ;
F_25 ( L_32 , L_54 , 1 , 0 , V_89 ) ;
F_25 ( L_32 , L_33 , 1 , 1 , V_58 ) ;
F_25 ( L_32 , L_34 , 1 , 1 , V_59 ) ;
F_25 ( L_32 , L_35 , 1 , 1 , V_60 ) ;
F_25 ( NULL , L_55 , 1 , 0 , V_86 | V_90 ) ;
F_25 ( L_48 , L_49 , 1 , 0 , V_81 ) ;
F_25 ( L_47 , NULL , 0 , 0 ,
V_79 | V_91 | V_92 |
V_93 | V_83 | V_94 |
V_95 | V_96 ) ;
F_25 ( L_51 , NULL , 0 , 0 , V_84 ) ;
F_25 ( L_52 , NULL , 0 , 0 , V_84 ) ;
F_25 ( L_42 , NULL , 1 , 0 , V_97 ) ;
F_25 ( L_50 , NULL , 1 , 0 , V_82 ) ;
F_25 ( L_43 , L_44 , 1 , 0 , V_73 ) ;
} else if ( F_14 ( L_5 ) ) {
F_40 ( F_50 () , F_51 () ,
F_51 () , V_98 ) ;
F_25 ( L_29 , L_30 , 1 , 0 , V_69 ) ;
F_25 ( L_37 , L_38 , 1 , 0 , V_68 ) ;
F_25 ( L_31 , L_30 , 1 , 0 , V_87 ) ;
F_25 ( L_45 , L_38 , 1 , 0 , V_74 ) ;
F_25 ( L_26 , L_56 , 1 , 0 , V_79 ) ;
F_25 ( L_42 , NULL , 1 , 0 , V_97 ) ;
F_25 ( L_50 , NULL , 1 , 0 , V_82 ) ;
F_25 ( L_43 , L_44 , 1 , 0 , V_73 ) ;
F_25 ( L_20 , NULL , 1 , 0 , V_45 ) ;
} else {
F_40 ( F_52 () , F_53 () ,
F_53 () , F_54 () ) ;
F_25 ( L_29 , L_57 , 1 , 0 , V_68 ) ;
F_25 ( L_29 , L_30 , 1 , 0 , V_69 ) ;
F_25 ( L_42 , NULL , 1 , 0 , V_97 ) ;
F_25 ( L_50 , NULL , 1 , 0 , V_82 ) ;
F_25 ( L_43 , L_44 , 1 , 0 , V_73 ) ;
F_25 ( L_20 , NULL , 1 , 0 , V_45 ) ;
}
}
