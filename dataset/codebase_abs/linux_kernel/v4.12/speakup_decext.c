static inline T_1 F_1 ( void )
{
T_1 V_1 = F_2 ( V_2 . V_3 + V_4 ) & V_5 ;
if ( V_1 )
V_6 = F_2 ( V_2 . V_3 + V_7 ) ;
return V_6 ;
}
static inline bool F_3 ( void )
{
return F_1 () == 0x13 ;
}
static void F_4 ( struct V_8 * V_9 )
{
T_1 V_10 ;
static T_1 V_11 = '\0' ;
unsigned long V_12 ;
unsigned long V_13 ;
struct V_14 * V_15 ;
struct V_14 * V_16 ;
int V_17 = 0 ;
int V_18 = 0 ;
V_15 = F_5 ( V_19 ) ;
V_16 = F_5 ( V_20 ) ;
F_6 ( & V_2 . V_21 , V_12 ) ;
V_17 = V_15 -> V_22 . V_23 . V_24 ;
F_7 ( & V_2 . V_21 , V_12 ) ;
V_13 = V_25 + V_17 ;
while ( ! F_8 () ) {
F_6 ( & V_2 . V_21 , V_12 ) ;
if ( V_2 . V_26 ) {
V_2 . V_26 = 0 ;
F_7 ( & V_2 . V_21 , V_12 ) ;
V_9 -> V_27 ( V_9 ) ;
continue;
}
F_9 () ;
if ( F_10 () ) {
F_7 ( & V_2 . V_21 , V_12 ) ;
break;
}
V_10 = F_11 () ;
F_12 ( V_28 ) ;
V_18 = V_16 -> V_22 . V_23 . V_24 ;
F_7 ( & V_2 . V_21 , V_12 ) ;
if ( V_10 == '\n' )
V_10 = 0x0D ;
if ( F_3 () || ! V_9 -> V_29 -> V_30 ( V_9 , V_10 ) ) {
F_13 ( F_14 ( V_18 ) ) ;
continue;
}
F_12 ( V_31 ) ;
F_6 ( & V_2 . V_21 , V_12 ) ;
F_15 () ;
F_7 ( & V_2 . V_21 , V_12 ) ;
if ( V_10 == '[' ) {
V_32 = 1 ;
} else if ( V_10 == ']' ) {
V_32 = 0 ;
} else if ( V_10 <= V_33 ) {
if ( ! V_32 && strchr ( L_1 , V_11 ) )
V_9 -> V_29 -> V_30 ( V_9 , V_34 ) ;
if ( F_16 ( V_25 , V_13 ) ) {
if ( ! V_32 )
V_9 -> V_29 -> V_30 ( V_9 , V_34 ) ;
F_6 ( & V_2 . V_21 ,
V_12 ) ;
V_17 = V_15 -> V_22 . V_23 . V_24 ;
V_18 = V_16 -> V_22 . V_23 . V_24 ;
F_7 ( & V_2 . V_21 ,
V_12 ) ;
F_13 ( F_14
( V_18 ) ) ;
V_13 = V_25 + V_17 ;
}
}
V_11 = V_10 ;
}
if ( ! V_32 )
V_9 -> V_29 -> V_30 ( V_9 , V_34 ) ;
}
static void F_17 ( struct V_8 * V_9 )
{
V_32 = 0 ;
V_9 -> V_35 ( V_9 , L_2 ) ;
}
