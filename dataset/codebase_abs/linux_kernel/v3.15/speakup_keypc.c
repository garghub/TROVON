static inline bool F_1 ( void )
{
return ( F_2 ( V_1 + V_2 ) & 0x10 ) != 0 ;
}
static inline bool F_3 ( void )
{
return ( F_2 ( V_1 + V_2 ) & 0x80 ) == 0 ;
}
static char * F_4 ( void )
{
int V_3 , V_4 , V_5 , V_6 ;
V_3 = F_2 ( V_1 ) ;
V_4 = F_2 ( V_1 + 1 ) ;
V_5 = F_2 ( V_1 + 2 ) ;
V_6 = F_2 ( V_1 + 3 ) ;
F_5 ( L_1 , V_3 , V_4 , V_5 , V_6 ) ;
return NULL ;
}
static const char * F_6 ( struct V_7 * V_8 , const char * V_9 )
{
T_1 V_10 ;
int V_11 ;
while ( ( V_10 = * V_9 ) ) {
if ( V_10 == '\n' )
V_10 = V_12 ;
if ( F_3 () )
return V_9 ;
V_11 = 1000 ;
while ( F_1 () )
if ( -- V_11 <= 0 )
return F_4 () ;
F_7 ( V_10 , V_1 ) ;
F_8 ( 70 ) ;
V_9 ++ ;
}
return NULL ;
}
static void F_9 ( struct V_7 * V_8 )
{
T_1 V_10 ;
int V_11 ;
unsigned long V_13 ;
unsigned long V_14 ;
struct V_15 * V_16 ;
struct V_15 * V_17 ;
struct V_15 * V_18 ;
int V_19 ;
int V_20 ;
int V_21 ;
V_16 = F_10 ( V_22 ) ;
V_17 = F_10 ( V_23 ) ;
V_18 = F_10 ( V_24 ) ;
F_11 ( & V_25 . V_26 , V_13 ) ;
V_21 = V_16 -> V_27 . V_28 . V_29 ;
F_12 ( & V_25 . V_26 , V_13 ) ;
V_14 = V_30 + V_21 ;
while ( ! F_13 () ) {
F_11 ( & V_25 . V_26 , V_13 ) ;
if ( V_25 . V_31 ) {
V_25 . V_31 = 0 ;
F_12 ( & V_25 . V_26 , V_13 ) ;
V_8 -> V_32 ( V_8 ) ;
continue;
}
if ( F_14 () ) {
F_12 ( & V_25 . V_26 , V_13 ) ;
break;
}
F_15 ( V_33 ) ;
V_20 = V_18 -> V_27 . V_28 . V_29 ;
F_12 ( & V_25 . V_26 , V_13 ) ;
if ( F_3 () ) {
F_16 ( F_17 ( V_20 ) ) ;
continue;
}
F_15 ( V_34 ) ;
V_11 = 1000 ;
while ( F_1 () )
if ( -- V_11 <= 0 )
break;
if ( V_11 <= 0 ) {
F_4 () ;
break;
}
F_11 ( & V_25 . V_26 , V_13 ) ;
V_10 = F_18 () ;
F_12 ( & V_25 . V_26 , V_13 ) ;
if ( V_10 == '\n' )
V_10 = V_12 ;
F_7 ( V_10 , V_1 ) ;
V_35 ;
if ( ( V_30 >= V_14 ) && ( V_10 == V_36 ) ) {
V_11 = 1000 ;
while ( F_1 () )
if ( -- V_11 <= 0 )
break;
if ( V_11 <= 0 ) {
F_4 () ;
break;
}
F_7 ( V_12 , V_1 ) ;
F_11 ( & V_25 . V_26 , V_13 ) ;
V_21 = V_16 -> V_27 . V_28 . V_29 ;
V_19 = V_17 -> V_27 . V_28 . V_29 ;
F_12 ( & V_25 . V_26 , V_13 ) ;
F_16 ( F_17 ( V_19 ) ) ;
V_14 = V_30 + V_21 ;
}
}
V_11 = 1000 ;
while ( F_1 () )
if ( -- V_11 <= 0 )
break;
if ( V_11 <= 0 )
F_4 () ;
else
F_7 ( V_12 , V_1 ) ;
}
static void F_19 ( struct V_7 * V_8 )
{
F_7 ( V_37 , V_1 ) ;
}
static int F_20 ( struct V_7 * V_8 )
{
unsigned int V_38 = 0 ;
int V_39 = 0 ;
F_21 ( L_2 , V_8 -> V_40 ) ;
if ( V_41 ) {
V_1 = V_41 ;
F_21 ( L_3 ,
V_1 ) ;
if ( F_22 ( V_1 - 1 , V_42 ) ) {
F_5 ( L_4 ) ;
return - V_43 ;
}
V_38 = F_23 ( V_1 ) ;
} else {
for ( V_39 = 0 ; V_44 [ V_39 ] ; V_39 ++ ) {
if ( F_22 ( V_44 [ V_39 ] ,
V_42 ) ) {
F_5
( L_5 ,
V_44 [ V_39 ] , V_42 ) ;
continue;
}
V_38 = F_23 ( V_44 [ V_39 ] ) ;
if ( V_38 == 0x80 ) {
V_1 = V_44 [ V_39 ] ;
break;
}
}
}
if ( V_38 != 0x80 ) {
F_21 ( L_6 , V_8 -> V_40 ) ;
F_24 ( V_1 , V_42 ) ;
V_1 = 0 ;
return - V_45 ;
}
F_21 ( L_7 , V_8 -> V_40 ,
V_1 , V_1 + V_42 - 1 ,
V_8 -> V_46 ) ;
V_8 -> V_47 = 1 ;
return 0 ;
}
static void F_25 ( void )
{
if ( V_1 )
F_24 ( V_1 , V_42 ) ;
V_1 = 0 ;
}
static int T_2 F_26 ( void )
{
return F_27 ( & V_48 ) ;
}
static void T_3 F_28 ( void )
{
F_29 ( & V_48 ) ;
}
