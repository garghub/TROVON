static inline int F_1 ( void )
{
return V_1 ;
}
static int F_2 ( T_1 * V_2 )
{
if ( ( * V_2 >= '0' ) && ( * V_2 <= '9' ) ) {
* V_2 = * V_2 - '0' ;
return 1 ;
}
return 0 ;
}
static unsigned char F_3 ( void )
{
T_1 V_3 ;
V_3 = V_4 ;
V_4 = 0 ;
return V_3 ;
}
static void F_4 ( T_1 V_5 )
{
static int V_6 = - 1 ;
if ( V_5 == 0x01 ) {
unsigned long V_7 ;
F_5 ( & V_8 , V_7 ) ;
V_9 = 0 ;
F_6 ( & V_10 ) ;
F_7 ( & V_8 , V_7 ) ;
} else if ( V_5 == 0x13 ) {
V_1 = 1 ;
} else if ( V_5 == 0x11 ) {
V_1 = 0 ;
} else if ( F_2 ( & V_5 ) ) {
if ( V_6 == - 1 )
V_6 = V_5 ;
else
V_6 = V_6 * 10 + V_5 ;
} else if ( ( V_5 > 31 ) && ( V_5 < 127 ) ) {
if ( V_6 != - 1 )
V_4 = ( T_1 ) V_6 ;
V_6 = - 1 ;
}
}
static void F_8 ( struct V_11 * V_12 )
{
int V_13 = 0 ;
static T_1 V_2 ;
static T_1 V_14 = '\0' ;
unsigned long V_7 ;
unsigned long V_15 ;
unsigned long V_16 = F_9 ( 4000 ) ;
F_10 ( V_17 ) ;
struct V_18 * V_19 ;
struct V_18 * V_20 ;
int V_21 ;
int V_22 ;
V_19 = F_11 ( V_23 ) ;
V_20 = F_11 ( V_24 ) ;
F_12 ( V_7 ) ;
V_21 = V_19 -> V_25 . V_26 . V_27 ;
F_13 ( V_7 ) ;
V_15 = V_28 + V_21 ;
while ( ! F_14 () ) {
F_5 ( & V_8 , V_7 ) ;
while ( V_9 && V_16 ) {
F_15 ( & V_10 , & V_17 , V_29 ) ;
F_7 ( & V_8 , V_7 ) ;
V_16 = F_16 ( V_16 ) ;
F_5 ( & V_8 , V_7 ) ;
}
F_17 ( & V_10 , & V_17 ) ;
V_9 = 0 ;
F_7 ( & V_8 , V_7 ) ;
F_12 ( V_7 ) ;
if ( V_30 . V_31 ) {
V_30 . V_31 = 0 ;
F_13 ( V_7 ) ;
V_12 -> V_10 ( V_12 ) ;
continue;
}
if ( F_18 () ) {
F_13 ( V_7 ) ;
break;
}
V_2 = F_19 () ;
F_20 ( V_29 ) ;
V_22 = V_20 -> V_25 . V_26 . V_27 ;
V_13 = F_1 () ;
F_13 ( V_7 ) ;
if ( V_2 == '\n' )
V_2 = 0x0D ;
if ( V_13 || ! F_21 ( V_2 ) ) {
F_16 ( F_9 ( V_22 ) ) ;
continue;
}
F_20 ( V_32 ) ;
F_12 ( V_7 ) ;
F_22 () ;
F_13 ( V_7 ) ;
if ( V_2 == '[' )
V_33 = 1 ;
else if ( V_2 == ']' )
V_33 = 0 ;
else if ( V_2 <= V_34 ) {
if ( ! V_33 && strchr ( L_1 , V_14 ) )
F_21 ( V_35 ) ;
if ( V_28 >= V_15 ) {
if ( ! V_33 )
F_21 ( V_35 ) ;
F_12 ( V_7 ) ;
V_21 = V_19 -> V_25 . V_26 . V_27 ;
V_22 = V_20 -> V_25 . V_26 . V_27 ;
F_13 ( V_7 ) ;
F_16 ( F_9
( V_22 ) ) ;
V_15 = V_28 + V_21 ;
}
}
V_14 = V_2 ;
}
if ( ! V_33 )
F_21 ( V_35 ) ;
}
static void F_23 ( struct V_11 * V_12 )
{
if ( V_33 ) {
F_21 ( ']' ) ;
}
V_33 = 0 ;
V_9 = 1 ;
F_21 ( V_36 ) ;
}
static int T_2 F_24 ( void )
{
return F_25 ( & V_37 ) ;
}
static void T_3 F_26 ( void )
{
F_27 ( & V_37 ) ;
}
