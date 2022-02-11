void F_1 ( unsigned int V_1 )
{
int V_2 = 1000000 ;
F_2 ( F_3 ( V_3 ) & ~ V_1 , V_3 ) ;
do {} while ( -- V_2 && ( F_3 ( V_4 ) & V_1 ) );
if ( ! V_2 )
F_4 ( L_1 ) ;
}
void F_5 ( unsigned int V_1 )
{
F_2 ( F_3 ( V_3 ) | V_1 , V_3 ) ;
}
static int F_6 ( struct V_5 * V_5 )
{
F_7 ( F_8 ( V_6 ) | V_5 -> V_7 , V_6 ) ;
return 0 ;
}
static void F_9 ( struct V_5 * V_5 )
{
F_7 ( F_8 ( V_6 ) & ~ V_5 -> V_7 , V_6 ) ;
}
static int F_10 ( struct V_5 * V_5 )
{
int V_8 = 1000000 ;
F_2 ( F_3 ( F_11 ( V_5 -> V_1 ) ) & ~ V_5 -> V_7 ,
F_11 ( V_5 -> V_1 ) ) ;
do {} while ( -- V_8 && ( F_3 ( F_12 ( V_5 -> V_1 ) ) & V_5 -> V_7 ) );
if ( ! V_8 )
F_4 ( L_1 ) ;
return 0 ;
}
static void F_13 ( struct V_5 * V_5 )
{
F_2 ( F_3 ( F_11 ( V_5 -> V_1 ) ) | V_5 -> V_7 ,
F_11 ( V_5 -> V_1 ) ) ;
}
static int F_14 ( struct V_5 * V_5 )
{
unsigned int V_9 = F_8 ( V_6 ) ;
if ( F_15 ( L_2 ) ||
F_15 ( L_3 ) ) {
V_9 &= ~ 0x1f00000 ;
if ( V_5 -> V_10 == V_11 )
V_9 |= 0xe00000 ;
else
V_9 |= 0x700000 ;
} else {
V_9 &= ~ 0xf00000 ;
if ( V_5 -> V_10 == V_11 )
V_9 |= 0x800000 ;
else
V_9 |= 0x400000 ;
}
F_7 ( V_9 , V_6 ) ;
F_10 ( V_5 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_5 )
{
F_7 ( F_8 ( V_6 ) & ~ ( 1 << 16 ) , V_6 ) ;
F_7 ( ( 1 << 30 ) , V_12 ) ;
return 0 ;
}
static void F_17 ( struct V_5 * V_5 )
{
F_7 ( F_8 ( V_6 ) | ( 1 << 16 ) , V_6 ) ;
F_7 ( ( 1 << 31 ) | ( 1 << 30 ) , V_12 ) ;
}
static int F_18 ( struct V_5 * V_5 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
if ( V_5 -> V_14 [ V_13 ] == V_5 -> V_10 ) {
int V_15 = 14 - ( 2 * V_5 -> V_1 ) ;
int V_16 = 7 - V_5 -> V_1 ;
unsigned int V_9 = F_8 ( V_6 ) ;
V_9 &= ~ ( 3 << V_15 ) ;
V_9 |= V_13 << V_15 ;
V_9 |= V_16 ;
F_7 ( V_9 , V_6 ) ;
return 0 ;
}
}
return - 1 ;
}
static void F_19 ( const char * V_17 , const char * V_18 ,
unsigned int V_1 , unsigned int V_7 )
{
struct V_5 * V_5 = F_20 ( sizeof( struct V_5 ) , V_19 ) ;
V_5 -> V_20 . V_21 = V_17 ;
V_5 -> V_20 . V_22 = V_18 ;
V_5 -> V_20 . V_5 = V_5 ;
V_5 -> V_16 = F_10 ;
V_5 -> V_23 = F_13 ;
V_5 -> V_1 = V_1 ;
V_5 -> V_7 = V_7 ;
F_21 ( & V_5 -> V_20 ) ;
}
static void F_22 ( const char * V_17 , const char * V_18 ,
unsigned int V_7 )
{
struct V_5 * V_5 = F_20 ( sizeof( struct V_5 ) , V_19 ) ;
V_5 -> V_20 . V_21 = V_17 ;
V_5 -> V_20 . V_22 = V_18 ;
V_5 -> V_20 . V_5 = V_5 ;
V_5 -> V_16 = F_6 ;
V_5 -> V_23 = F_9 ;
V_5 -> V_7 = V_7 ;
F_21 ( & V_5 -> V_20 ) ;
}
static void F_23 ( void )
{
struct V_5 * V_5 = F_20 ( sizeof( struct V_5 ) , V_19 ) ;
struct V_5 * V_24 = F_20 ( sizeof( struct V_5 ) , V_19 ) ;
V_5 -> V_20 . V_21 = L_4 ;
V_5 -> V_20 . V_22 = NULL ;
V_5 -> V_20 . V_5 = V_5 ;
V_5 -> V_10 = V_11 ;
V_5 -> V_14 = V_25 ;
V_5 -> V_16 = F_14 ;
V_5 -> V_23 = F_13 ;
V_5 -> V_1 = 0 ;
V_5 -> V_7 = V_26 ;
F_21 ( & V_5 -> V_20 ) ;
V_24 -> V_20 . V_21 = L_4 ;
V_24 -> V_20 . V_22 = L_5 ;
V_24 -> V_20 . V_5 = V_24 ;
V_24 -> V_16 = F_16 ;
V_24 -> V_23 = F_17 ;
F_21 ( & V_24 -> V_20 ) ;
}
static void F_24 ( void )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
struct V_5 * V_5 ;
char * V_27 ;
V_27 = F_20 ( sizeof( L_6 ) , V_19 ) ;
sprintf ( V_27 , L_7 , V_13 ) ;
V_5 = F_20 ( sizeof( struct V_5 ) , V_19 ) ;
V_5 -> V_20 . V_21 = L_8 ;
V_5 -> V_20 . V_22 = V_27 ;
V_5 -> V_20 . V_5 = V_5 ;
V_5 -> V_10 = 0 ;
V_5 -> V_14 = V_28 [ V_13 ] ;
V_5 -> V_16 = F_18 ;
V_5 -> V_1 = V_13 ;
F_21 ( & V_5 -> V_20 ) ;
}
}
void T_1 F_25 ( void )
{
struct V_29 V_30 , V_31 , V_32 ;
struct V_33 * V_34 =
F_26 ( NULL , NULL , L_9 ) ;
struct V_33 * V_35 =
F_26 ( NULL , NULL , L_10 ) ;
struct V_33 * V_36 =
F_26 ( NULL , NULL , L_11 ) ;
if ( ! V_34 || ! V_35 || ! V_36 )
F_4 ( L_12 ) ;
if ( F_27 ( V_34 , 0 , & V_30 ) ||
F_27 ( V_35 , 0 , & V_31 ) ||
F_27 ( V_36 , 0 , & V_32 ) )
F_4 ( L_13 ) ;
if ( ( F_28 ( V_30 . V_37 , F_29 ( & V_30 ) ,
V_30 . V_27 ) < 0 ) ||
( F_28 ( V_31 . V_37 , F_29 ( & V_31 ) ,
V_31 . V_27 ) < 0 ) ||
( F_28 ( V_32 . V_37 , F_29 ( & V_32 ) ,
V_32 . V_27 ) < 0 ) )
F_30 ( L_14 ) ;
V_38 = F_31 ( V_30 . V_37 , F_29 ( & V_30 ) ) ;
V_39 = F_31 ( V_31 . V_37 ,
F_29 ( & V_31 ) ) ;
V_40 = F_31 ( V_32 . V_37 ,
F_29 ( & V_32 ) ) ;
if ( ! V_38 || ! V_39 || ! V_40 )
F_4 ( L_15 ) ;
F_32 ( F_33 ( V_41 ) & ~ V_42 , V_41 ) ;
F_19 ( L_16 , NULL , 0 , V_43 ) ;
F_19 ( L_17 , NULL , 0 , V_44 ) ;
F_19 ( L_18 , NULL , 0 , V_45 ) ;
F_19 ( L_19 , NULL , 0 , V_46 ) ;
F_19 ( L_20 , NULL , 0 , V_47 ) ;
F_19 ( L_21 , NULL , 0 , V_48 ) ;
F_19 ( L_22 , NULL , 0 , V_49 ) ;
F_24 () ;
if ( F_15 ( L_3 ) ) {
V_6 = V_50 ;
V_12 = V_51 ;
} else {
F_19 ( L_23 , NULL , 0 , V_52 ) ;
}
if ( ! F_15 ( L_24 ) ) {
F_19 ( L_25 , NULL , 0 , V_53 ) ;
F_23 () ;
}
if ( F_15 ( L_24 ) ) {
if ( F_8 ( V_54 ) & ( 1 << 5 ) )
F_34 ( V_55 , V_56 ,
V_56 , V_55 ) ;
else
F_34 ( V_56 , V_56 ,
V_56 , V_56 ) ;
F_22 ( L_23 , L_26 , V_57 ) ,
F_19 ( L_23 , L_27 , 0 , V_58 ) ;
} else if ( F_15 ( L_3 ) ) {
F_34 ( F_35 () , F_36 () ,
F_36 () , F_37 () ) ;
F_19 ( L_28 , L_29 , 1 , V_59 ) ;
F_19 ( L_28 , L_30 , 0 , V_60 ) ;
F_19 ( L_28 , L_31 , 1 , V_61 ) ;
F_19 ( L_28 , L_32 , 1 , V_62 ) ;
F_19 ( L_28 , L_33 , 1 , V_63 ) ;
F_19 ( L_28 , L_34 , 0 , V_64 | V_65 ) ;
F_19 ( L_35 , NULL , 0 ,
V_66 | V_67 | V_68 |
V_69 | V_70 | V_71 |
V_72 | V_73 ) ;
F_19 ( L_36 , L_37 , 0 , V_74 ) ;
} else if ( F_15 ( L_2 ) ) {
F_34 ( F_38 () , F_39 () ,
F_39 () , V_75 ) ;
F_19 ( L_23 , L_38 , 0 , V_66 ) ;
} else {
F_34 ( F_40 () , F_41 () ,
F_41 () , F_42 () ) ;
}
}
