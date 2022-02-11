static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
unsigned long V_4 ;
unsigned long V_5 ;
struct V_6 * V_7 ;
struct V_6 * V_8 ;
struct V_6 * V_9 ;
int V_10 = 0 ;
int V_11 = 0 ;
int V_12 = 0 ;
V_7 = F_2 ( V_13 ) ;
V_8 = F_2 ( V_14 ) ;
V_9 = F_2 ( V_15 ) ;
F_3 ( V_4 ) ;
V_12 = V_7 -> V_16 . V_17 . V_18 ;
F_4 ( V_4 ) ;
V_5 = V_19 + V_12 ;
while ( ! F_5 () ) {
F_3 ( V_4 ) ;
V_12 = V_7 -> V_16 . V_17 . V_18 ;
V_10 = V_9 -> V_16 . V_17 . V_18 ;
V_11 = V_8 -> V_16 . V_17 . V_18 ;
if ( V_20 . V_21 ) {
V_20 . V_21 = 0 ;
F_4 ( V_4 ) ;
V_2 -> V_22 ( V_2 ) ;
continue;
}
if ( F_6 () ) {
F_4 ( V_4 ) ;
break;
}
V_3 = F_7 () ;
F_8 ( V_23 ) ;
V_10 = V_9 -> V_16 . V_17 . V_18 ;
F_4 ( V_4 ) ;
if ( ! F_9 ( V_3 ) ) {
F_10 ( V_24 , V_20 . V_25 + V_26 ) ;
F_10 ( V_24 | V_27 ,
V_20 . V_25 + V_26 ) ;
F_11 ( F_12 ( V_10 ) ) ;
continue;
}
if ( ( V_19 >= V_5 ) && ( V_3 == V_28 ) ) {
F_3 ( V_4 ) ;
V_12 = V_7 -> V_16 . V_17 . V_18 ;
V_10 = V_9 -> V_16 . V_17 . V_18 ;
V_11 = V_8 -> V_16 . V_17 . V_18 ;
F_4 ( V_4 ) ;
if ( F_9 ( V_2 -> V_29 ) )
F_11 ( F_12
( V_11 ) ) ;
else
F_11 ( F_12
( V_10 ) ) ;
V_5 = V_19 + V_12 ;
}
F_8 ( V_30 ) ;
F_3 ( V_4 ) ;
F_13 () ;
F_4 ( V_4 ) ;
}
F_9 ( V_31 ) ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_32 ) ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_32 ) ;
}
