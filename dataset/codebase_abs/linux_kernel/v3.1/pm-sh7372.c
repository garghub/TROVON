static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = 1 << V_4 -> V_6 ;
if ( F_3 ( V_7 ) & V_5 ) {
unsigned int V_8 ;
F_4 ( V_5 , V_9 ) ;
for ( V_8 = V_10 ; V_8 ; V_8 -- ) {
if ( ! ( F_3 ( V_9 ) & V_5 ) )
break;
F_5 () ;
}
}
F_6 ( L_1 ,
V_5 , F_3 ( V_7 ) ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = 1 << V_4 -> V_6 ;
unsigned int V_8 ;
int V_11 = 0 ;
if ( F_3 ( V_7 ) & V_5 )
goto V_12;
F_4 ( V_5 , V_13 ) ;
for ( V_8 = 2 * V_10 ; V_8 ; V_8 -- ) {
if ( ! ( F_3 ( V_13 ) & V_5 ) )
goto V_12;
if ( V_8 > V_10 )
F_8 ( V_14 ) ;
else
F_5 () ;
}
if ( F_3 ( V_13 ) & V_5 )
V_11 = - V_15 ;
V_12:
F_6 ( L_2 ,
V_5 , F_3 ( V_7 ) ) ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_11 = F_7 ( V_2 ) ;
F_10 ( & V_16 . V_2 ) ;
return V_11 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_11 = F_1 ( V_2 ) ;
F_12 ( & V_16 . V_2 ) ;
return V_11 ;
}
static int F_13 ( struct V_1 * V_2 )
{
if ( ! ( F_3 ( V_7 ) & ( 1 << V_17 . V_6 ) ) )
return F_1 ( V_2 ) ;
return - V_18 ;
}
static bool F_14 ( struct V_19 * V_20 )
{
return true ;
}
void F_15 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
F_16 ( V_2 , NULL , false ) ;
V_2 -> V_21 = V_22 ;
V_2 -> V_23 = V_24 ;
V_2 -> V_25 = F_14 ;
if ( V_4 == & V_16 ) {
V_2 -> V_26 = F_13 ;
V_2 -> V_27 = F_7 ;
} else if ( V_4 == & V_17 ) {
V_2 -> V_26 = F_11 ;
V_2 -> V_27 = F_9 ;
} else {
V_2 -> V_26 = F_1 ;
V_2 -> V_27 = F_7 ;
}
V_2 -> V_27 ( & V_4 -> V_2 ) ;
}
void F_17 ( struct V_3 * V_4 ,
struct V_28 * V_29 )
{
struct V_19 * V_20 = & V_29 -> V_20 ;
if ( ! V_20 -> V_30 . V_31 ) {
F_18 ( V_20 ) ;
F_19 ( V_20 , NULL ) ;
}
F_20 ( & V_4 -> V_2 , V_20 ) ;
}
static void F_21 ( void )
{
void T_1 * V_32 = ( void T_1 * ) V_33 ;
F_4 ( 0 , V_34 ) ;
F_4 ( F_22 ( V_35 ) , V_36 ) ;
F_4 ( 0x10 , V_37 ) ;
F_4 ( 0 , V_32 + 0x3c ) ;
F_23 () ;
F_24 () ;
if ( F_3 ( V_32 + 0x3c ) ) {
F_4 ( F_3 ( V_32 + 0x40 ) ,
F_25 ( F_3 ( V_32 + 0x3c ) ) ) ;
F_26 () ;
F_27 ( F_3 ( V_32 + 0x38 ) ) ;
}
F_4 ( 0 , V_37 ) ;
F_4 ( 0 , V_36 ) ;
}
static void F_28 ( struct V_38 * V_20 )
{
struct V_39 * V_40 ;
int V_41 = V_20 -> V_42 ;
V_40 = & V_20 -> V_43 [ V_41 ] ;
snprintf ( V_40 -> V_44 , V_45 , L_3 ) ;
strncpy ( V_40 -> V_46 , L_4 , V_47 ) ;
V_40 -> V_48 = 10 ;
V_40 -> V_49 = 20 + 10 ;
V_40 -> V_50 = 1 ;
V_40 -> V_51 = 0 ;
V_40 -> V_51 |= V_52 ;
V_53 [ V_41 ] = F_21 ;
V_20 -> V_42 = V_41 + 1 ;
}
static void F_29 ( void )
{
V_54 = F_28 ;
}
static void F_29 ( void ) {}
static int F_30 ( T_2 V_55 )
{
F_21 () ;
return 0 ;
}
static void F_31 ( void )
{
V_56 . V_57 = F_30 ;
}
static void F_31 ( void ) {}
void T_3 F_32 ( void )
{
F_4 ( 0x0000a500 , V_58 ) ;
F_4 ( 0x0000a501 , V_58 ) ;
F_4 ( 0x00000000 , V_59 ) ;
F_31 () ;
F_29 () ;
}
