static inline bool F_1 ( void )
{
return F_2 ( V_1 ) & V_2 ;
}
static inline bool F_3 ( void )
{
return F_2 ( V_3 . V_4 + V_5 ) == 'F' ;
}
static const char * F_4 ( struct V_6 * V_7 , const char * V_8 )
{
T_1 V_9 ;
while ( ( V_9 = * V_8 ) ) {
int V_10 = V_11 ;
if ( V_9 == '\n' )
V_9 = V_12 ;
if ( F_3 () )
return V_8 ;
while ( F_1 () ) {
if ( ! -- V_10 )
return V_8 ;
F_5 ( 1 ) ;
}
F_6 ( V_9 , V_3 . V_4 ) ;
V_8 ++ ;
}
return NULL ;
}
static void F_7 ( struct V_6 * V_7 )
{
T_1 V_9 ;
unsigned long V_13 ;
unsigned long V_14 ;
int V_10 ;
int V_15 ;
int V_16 ;
int V_17 ;
struct V_18 * V_19 ;
struct V_18 * V_20 ;
struct V_18 * V_21 ;
V_21 = F_8 ( V_22 ) ;
V_19 = F_8 ( V_23 ) ;
V_20 = F_8 ( V_24 ) ;
F_9 ( & V_3 . V_25 , V_13 ) ;
V_16 = V_21 -> V_26 . V_27 . V_28 ;
F_10 ( & V_3 . V_25 , V_13 ) ;
V_14 = V_29 + V_16 ;
while ( ! F_11 () ) {
F_9 ( & V_3 . V_25 , V_13 ) ;
if ( V_3 . V_30 ) {
V_3 . V_30 = 0 ;
F_10 ( & V_3 . V_25 , V_13 ) ;
V_7 -> V_31 ( V_7 ) ;
continue;
}
F_12 () ;
if ( F_13 () ) {
F_10 ( & V_3 . V_25 , V_13 ) ;
break;
}
F_14 ( V_32 ) ;
V_17 = V_20 -> V_26 . V_27 . V_28 ;
F_10 ( & V_3 . V_25 , V_13 ) ;
if ( F_3 () ) {
F_15 ( F_16 ( V_17 ) ) ;
continue;
}
F_14 ( V_33 ) ;
V_10 = V_11 ;
while ( F_1 () ) {
if ( ! -- V_10 )
break;
F_5 ( 1 ) ;
}
F_9 ( & V_3 . V_25 , V_13 ) ;
V_9 = F_17 () ;
F_10 ( & V_3 . V_25 , V_13 ) ;
if ( V_9 == '\n' )
V_9 = V_12 ;
F_6 ( V_9 , V_3 . V_4 ) ;
if ( F_18 ( V_29 , V_14 ) && V_9 == V_34 ) {
V_10 = V_11 ;
while ( F_1 () ) {
if ( ! -- V_10 )
break;
F_5 ( 1 ) ;
}
F_6 ( V_12 , V_3 . V_4 ) ;
F_9 ( & V_3 . V_25 , V_13 ) ;
V_16 = V_21 -> V_26 . V_27 . V_28 ;
V_15 = V_19 -> V_26 . V_27 . V_28 ;
F_10 ( & V_3 . V_25 , V_13 ) ;
F_15 ( F_16 ( V_15 ) ) ;
V_14 = V_29 + V_16 ;
}
}
V_10 = V_11 ;
while ( F_1 () ) {
if ( ! -- V_10 )
break;
F_5 ( 1 ) ;
}
F_6 ( V_12 , V_3 . V_4 ) ;
}
static void F_19 ( struct V_6 * V_7 )
{
F_6 ( V_35 , V_3 . V_4 ) ;
}
static int F_20 ( struct V_6 * V_7 )
{
unsigned int V_36 = 0 ;
int V_37 = 0 ;
F_21 ( L_1 , V_7 -> V_38 ) ;
if ( V_39 ) {
V_3 . V_4 = V_39 ;
F_21 ( L_2 ,
V_3 . V_4 ) ;
if ( F_22 ( V_3 . V_4 - 1 ,
V_40 ) ) {
F_23 ( L_3 ) ;
return - V_41 ;
}
V_36 = F_24 ( V_3 . V_4 - 1 ) ;
V_1 = V_3 . V_4 - 1 ;
} else {
for ( V_37 = 0 ; V_42 [ V_37 ] ; V_37 ++ ) {
if ( F_22 ( V_42 [ V_37 ] ,
V_40 ) ) {
F_23
( L_4 ,
V_42 [ V_37 ] , V_40 ) ;
continue;
}
V_36 = F_24 ( V_42 [ V_37 ] ) & 0xfffc ;
if ( V_36 == 0x53fc ) {
V_1 = V_42 [ V_37 ] ;
V_3 . V_4 = V_1 + 1 ;
break;
}
}
}
V_36 &= 0xfffc ;
if ( V_36 != 0x53fc ) {
F_21 ( L_5 , V_7 -> V_38 ) ;
F_25 ( V_1 , V_40 ) ;
V_1 = 0 ;
return - V_43 ;
}
F_21 ( L_6 , V_7 -> V_38 ,
V_1 , V_1 + V_40 - 1 ,
V_7 -> V_44 ) ;
V_7 -> V_45 = 1 ;
return 0 ;
}
static void F_26 ( void )
{
F_27 () ;
if ( V_3 . V_4 )
F_25 ( V_3 . V_4 - 1 , V_40 ) ;
V_3 . V_4 = 0 ;
}
