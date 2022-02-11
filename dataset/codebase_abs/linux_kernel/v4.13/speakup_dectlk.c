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
static unsigned char F_3 ( struct V_3 * V_4 )
{
T_1 V_5 ;
V_5 = V_6 ;
V_6 = 0 ;
return V_5 ;
}
static void F_4 ( T_1 V_7 )
{
static int V_8 = - 1 ;
if ( V_7 == 0x01 ) {
unsigned long V_9 ;
F_5 ( & V_10 , V_9 ) ;
V_11 = 0 ;
F_6 ( & V_12 ) ;
F_7 ( & V_10 , V_9 ) ;
} else if ( V_7 == 0x13 ) {
V_1 = 1 ;
} else if ( V_7 == 0x11 ) {
V_1 = 0 ;
} else if ( F_2 ( & V_7 ) ) {
if ( V_8 == - 1 )
V_8 = V_7 ;
else
V_8 = V_8 * 10 + V_7 ;
} else if ( ( V_7 > 31 ) && ( V_7 < 127 ) ) {
if ( V_8 != - 1 )
V_6 = ( T_1 ) V_8 ;
V_8 = - 1 ;
}
}
static void F_8 ( struct V_3 * V_4 )
{
int V_13 = 0 ;
static T_1 V_2 ;
static T_1 V_14 = '\0' ;
unsigned long V_9 ;
unsigned long V_15 ;
unsigned long V_16 = F_9 ( 4000 ) ;
F_10 ( V_17 ) ;
struct V_18 * V_19 ;
struct V_18 * V_20 ;
int V_21 ;
int V_22 ;
V_19 = F_11 ( V_23 ) ;
V_20 = F_11 ( V_24 ) ;
F_5 ( & V_25 . V_26 , V_9 ) ;
V_21 = V_19 -> V_27 . V_28 . V_29 ;
F_7 ( & V_25 . V_26 , V_9 ) ;
V_15 = V_30 + V_21 ;
while ( ! F_12 () ) {
F_5 ( & V_10 , V_9 ) ;
while ( V_11 && V_16 ) {
F_13 ( & V_12 , & V_17 , V_31 ) ;
F_7 ( & V_10 , V_9 ) ;
V_16 = F_14 ( V_16 ) ;
F_5 ( & V_10 , V_9 ) ;
}
F_15 ( & V_12 , & V_17 ) ;
V_11 = 0 ;
F_7 ( & V_10 , V_9 ) ;
F_5 ( & V_25 . V_26 , V_9 ) ;
if ( V_25 . V_32 ) {
V_25 . V_32 = 0 ;
F_7 ( & V_25 . V_26 , V_9 ) ;
V_4 -> V_12 ( V_4 ) ;
continue;
}
F_16 () ;
if ( F_17 () ) {
F_7 ( & V_25 . V_26 , V_9 ) ;
break;
}
V_2 = F_18 () ;
F_19 ( V_31 ) ;
V_22 = V_20 -> V_27 . V_28 . V_29 ;
V_13 = F_1 () ;
F_7 ( & V_25 . V_26 , V_9 ) ;
if ( V_2 == '\n' )
V_2 = 0x0D ;
if ( V_13 || ! V_4 -> V_33 -> V_34 ( V_4 , V_2 ) ) {
F_14 ( F_9 ( V_22 ) ) ;
continue;
}
F_19 ( V_35 ) ;
F_5 ( & V_25 . V_26 , V_9 ) ;
F_20 () ;
F_7 ( & V_25 . V_26 , V_9 ) ;
if ( V_2 == '[' ) {
V_36 = 1 ;
} else if ( V_2 == ']' ) {
V_36 = 0 ;
} else if ( V_2 <= V_37 ) {
if ( ! V_36 && strchr ( L_1 , V_14 ) )
V_4 -> V_33 -> V_34 ( V_4 , V_38 ) ;
if ( F_21 ( V_30 , V_15 ) ) {
if ( ! V_36 )
V_4 -> V_33 -> V_34 ( V_4 , V_38 ) ;
F_5 ( & V_25 . V_26 ,
V_9 ) ;
V_21 = V_19 -> V_27 . V_28 . V_29 ;
V_22 = V_20 -> V_27 . V_28 . V_29 ;
F_7 ( & V_25 . V_26 ,
V_9 ) ;
F_14 ( F_9
( V_22 ) ) ;
V_15 = V_30 + V_21 ;
}
}
V_14 = V_2 ;
}
if ( ! V_36 )
V_4 -> V_33 -> V_34 ( V_4 , V_38 ) ;
}
static void F_22 ( struct V_3 * V_4 )
{
if ( V_36 )
V_4 -> V_33 -> V_34 ( V_4 , ']' ) ;
V_36 = 0 ;
V_11 = 1 ;
V_4 -> V_33 -> V_39 () ;
V_4 -> V_33 -> V_34 ( V_4 , V_40 ) ;
}
