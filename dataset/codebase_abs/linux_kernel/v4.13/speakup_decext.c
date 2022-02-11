static void F_1 ( T_1 V_1 )
{
V_2 = V_1 ;
}
static inline bool F_2 ( void )
{
return V_2 == 0x13 ;
}
static void F_3 ( struct V_3 * V_4 )
{
T_1 V_1 ;
static T_1 V_5 = '\0' ;
unsigned long V_6 ;
unsigned long V_7 ;
struct V_8 * V_9 ;
struct V_8 * V_10 ;
int V_11 = 0 ;
int V_12 = 0 ;
V_9 = F_4 ( V_13 ) ;
V_10 = F_4 ( V_14 ) ;
F_5 ( & V_15 . V_16 , V_6 ) ;
V_11 = V_9 -> V_17 . V_18 . V_19 ;
F_6 ( & V_15 . V_16 , V_6 ) ;
V_7 = V_20 + V_11 ;
while ( ! F_7 () ) {
F_5 ( & V_15 . V_16 , V_6 ) ;
if ( V_15 . V_21 ) {
V_15 . V_21 = 0 ;
F_6 ( & V_15 . V_16 , V_6 ) ;
V_4 -> V_22 ( V_4 ) ;
continue;
}
F_8 () ;
if ( F_9 () ) {
F_6 ( & V_15 . V_16 , V_6 ) ;
break;
}
V_1 = F_10 () ;
F_11 ( V_23 ) ;
V_12 = V_10 -> V_17 . V_18 . V_19 ;
F_6 ( & V_15 . V_16 , V_6 ) ;
if ( V_1 == '\n' )
V_1 = 0x0D ;
if ( F_2 () || ! V_4 -> V_24 -> V_25 ( V_4 , V_1 ) ) {
F_12 ( F_13 ( V_12 ) ) ;
continue;
}
F_11 ( V_26 ) ;
F_5 ( & V_15 . V_16 , V_6 ) ;
F_14 () ;
F_6 ( & V_15 . V_16 , V_6 ) ;
if ( V_1 == '[' ) {
V_27 = 1 ;
} else if ( V_1 == ']' ) {
V_27 = 0 ;
} else if ( V_1 <= V_28 ) {
if ( ! V_27 && strchr ( L_1 , V_5 ) )
V_4 -> V_24 -> V_25 ( V_4 , V_29 ) ;
if ( F_15 ( V_20 , V_7 ) ) {
if ( ! V_27 )
V_4 -> V_24 -> V_25 ( V_4 , V_29 ) ;
F_5 ( & V_15 . V_16 ,
V_6 ) ;
V_11 = V_9 -> V_17 . V_18 . V_19 ;
V_12 = V_10 -> V_17 . V_18 . V_19 ;
F_6 ( & V_15 . V_16 ,
V_6 ) ;
F_12 ( F_13
( V_12 ) ) ;
V_7 = V_20 + V_11 ;
}
}
V_5 = V_1 ;
}
if ( ! V_27 )
V_4 -> V_24 -> V_25 ( V_4 , V_29 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
V_27 = 0 ;
V_4 -> V_24 -> V_30 () ;
V_4 -> V_31 ( V_4 , L_2 ) ;
}
