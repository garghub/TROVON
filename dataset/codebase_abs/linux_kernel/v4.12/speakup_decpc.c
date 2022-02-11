static int F_1 ( void )
{
V_1 = F_2 ( V_2 . V_3 ) |
( F_2 ( V_2 . V_3 + 1 ) << 8 ) ;
return V_1 ;
}
static void F_3 ( T_1 V_4 )
{
F_4 ( V_4 & 0xFF , V_2 . V_3 ) ;
F_4 ( ( V_4 >> 8 ) & 0xFF , V_2 . V_3 + 1 ) ;
}
static int F_5 ( int V_5 )
{
int V_6 = 100 ;
while ( -- V_6 > 0 ) {
if ( ( F_1 () & V_5 ) == V_5 )
return 1 ;
F_6 ( 50 ) ;
}
return 0 ;
}
static int F_7 ( void )
{
int V_6 = 100 , V_7 = V_8 ;
if ( ! F_5 ( V_9 ) )
return 0 ;
while ( -- V_6 > 0 ) {
if ( ( F_1 () & V_10 ) == V_7 )
return 1 ;
F_6 ( 50 ) ;
}
V_8 = F_1 () & V_10 ;
return 1 ;
}
static int F_8 ( T_1 V_4 )
{
int V_6 = 10 ;
if ( ! F_5 ( V_11 ) )
return - 1 ;
F_4 ( 0 , V_2 . V_3 + 2 ) ;
F_4 ( 0 , V_2 . V_3 + 3 ) ;
F_1 () ;
F_3 ( V_12 | V_4 ) ;
F_4 ( 0 , V_2 . V_3 + 6 ) ;
while ( F_1 () & V_11 ) {
F_6 ( 20 ) ;
if ( -- V_6 == 0 )
break;
}
F_3 ( V_13 ) ;
return 0 ;
}
static void F_9 ( struct V_14 * V_15 )
{
int V_6 = 10 ;
if ( V_16 )
return;
V_16 = 4 ;
V_17 = 0 ;
while ( F_8 ( V_18 ) ) {
if ( -- V_6 == 0 )
break;
F_6 ( 50 ) ;
}
for ( V_6 = 0 ; V_6 < 10 ; V_6 ++ ) {
if ( F_5 ( V_9 ) )
break;
F_6 ( 50 ) ;
}
F_4 ( V_19 , V_2 . V_3 + 4 ) ;
F_4 ( 0 , V_2 . V_3 + 4 ) ;
F_6 ( 100 ) ;
for ( V_6 = 0 ; V_6 < 10 ; V_6 ++ ) {
if ( ! ( F_1 () & V_20 ) )
break;
F_6 ( 50 ) ;
}
V_8 = F_1 () & V_10 ;
V_8 ^= V_10 ;
V_16 = 0 ;
}
static int F_10 ( char V_21 )
{
if ( ! F_7 () )
return - 1 ;
if ( ! ( V_1 & V_22 ) )
return - 2 ;
F_4 ( V_23 , V_2 . V_3 + 4 ) ;
F_4 ( V_21 , V_2 . V_3 + 4 ) ;
V_8 ^= V_10 ;
return 0 ;
}
static int F_11 ( void )
{
int V_24 = 0 ;
if ( F_1 () == 0xffff ) {
V_24 = - 1 ;
goto V_25;
}
F_3 ( V_26 ) ;
if ( ! F_5 ( V_11 ) )
V_24 = - 2 ;
else if ( V_1 & 0x8000 )
return 0 ;
else if ( V_1 == 0x0dec )
F_12 ( L_1 ,
V_2 . V_3 ) ;
V_24 = - 3 ;
V_25: F_13 ( V_2 . V_3 , V_27 ) ;
V_2 . V_3 = 0 ;
return V_24 ;
}
static void F_14 ( struct V_14 * V_15 )
{
T_2 V_21 ;
static T_2 V_28 ;
unsigned long V_29 ;
unsigned long V_30 ;
struct V_31 * V_32 ;
struct V_31 * V_33 ;
int V_34 ;
int V_35 ;
V_32 = F_15 ( V_36 ) ;
V_33 = F_15 ( V_37 ) ;
F_16 ( & V_2 . V_38 , V_29 ) ;
V_34 = V_32 -> V_39 . V_40 . V_41 ;
F_17 ( & V_2 . V_38 , V_29 ) ;
V_30 = V_42 + V_34 ;
while ( ! F_18 () ) {
F_16 ( & V_2 . V_38 , V_29 ) ;
if ( V_2 . V_43 ) {
V_2 . V_43 = 0 ;
F_17 ( & V_2 . V_38 , V_29 ) ;
V_15 -> V_44 ( V_15 ) ;
continue;
}
F_19 () ;
if ( F_20 () ) {
F_17 ( & V_2 . V_38 , V_29 ) ;
break;
}
V_21 = F_21 () ;
F_22 ( V_45 ) ;
V_35 = V_33 -> V_39 . V_40 . V_41 ;
F_17 ( & V_2 . V_38 , V_29 ) ;
if ( V_21 == '\n' )
V_21 = 0x0D ;
if ( F_10 ( V_21 ) ) {
F_23 ( F_24 ( V_35 ) ) ;
continue;
}
F_22 ( V_46 ) ;
F_16 ( & V_2 . V_38 , V_29 ) ;
F_25 () ;
F_17 ( & V_2 . V_38 , V_29 ) ;
if ( V_21 == '[' ) {
V_17 = 1 ;
} else if ( V_21 == ']' ) {
V_17 = 0 ;
} else if ( V_21 <= V_47 ) {
if ( ! V_17 && strchr ( L_2 , V_28 ) )
F_10 ( V_48 ) ;
if ( F_26 ( V_42 , V_30 ) ) {
if ( ! V_17 )
F_10 ( V_48 ) ;
F_16 ( & V_2 . V_38 ,
V_29 ) ;
V_34 = V_32 -> V_39 . V_40 . V_41 ;
V_35 = V_33 -> V_39 . V_40 . V_41 ;
F_17 ( & V_2 . V_38 ,
V_29 ) ;
F_23 ( F_24
( V_35 ) ) ;
V_30 = V_42 + V_34 ;
}
}
V_28 = V_21 ;
V_21 = 0 ;
}
if ( ! V_17 )
F_10 ( V_48 ) ;
}
static const char * F_27 ( struct V_14 * V_15 , const char * V_49 )
{
T_2 V_21 ;
while ( ( V_21 = * V_49 ) ) {
if ( V_21 == '\n' )
V_21 = V_48 ;
if ( F_10 ( V_21 ) )
return V_49 ;
V_49 ++ ;
}
return NULL ;
}
static int F_28 ( struct V_14 * V_15 )
{
int V_50 = 0 , V_51 = 0 ;
F_29 ( L_3 , V_15 -> V_52 ) ;
for ( V_50 = 0 ; V_53 [ V_50 ] ; V_50 ++ ) {
if ( F_30 ( V_53 [ V_50 ] , V_27 ) ) {
F_12 ( L_4 ,
V_53 [ V_50 ] , V_27 ) ;
continue;
}
V_2 . V_3 = V_53 [ V_50 ] ;
V_51 = F_11 () ;
if ( V_51 == 0 )
break;
}
if ( V_51 ) {
F_29 ( L_5 , V_15 -> V_52 ) ;
return - V_54 ;
}
F_29 ( L_6 , V_15 -> V_52 ,
V_2 . V_3 , V_2 . V_3 + 7 ,
V_15 -> V_55 ) ;
V_15 -> V_56 = 1 ;
return 0 ;
}
static void F_31 ( void )
{
F_32 () ;
if ( V_2 . V_3 )
F_13 ( V_2 . V_3 , V_27 ) ;
V_2 . V_3 = 0 ;
}
