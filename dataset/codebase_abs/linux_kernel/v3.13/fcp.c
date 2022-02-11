int F_1 ( struct V_1 * V_2 ,
const void * V_3 , unsigned int V_4 ,
void * V_5 , unsigned int V_6 ,
unsigned int V_7 )
{
struct V_8 V_9 ;
int V_10 , V_11 , V_12 = 0 ;
V_9 . V_2 = V_2 ;
V_9 . V_13 = V_5 ;
V_9 . V_6 = V_6 ;
V_9 . V_7 = V_7 ;
V_9 . V_14 = V_15 ;
F_2 ( & V_9 . V_16 ) ;
F_3 ( & V_17 ) ;
F_4 ( & V_9 . V_18 , & V_19 ) ;
F_5 ( & V_17 ) ;
for (; ; ) {
V_10 = V_4 == 4 ? V_20
: V_21 ;
V_11 = F_6 ( V_9 . V_2 , V_10 ,
V_22 + V_23 ,
( void * ) V_3 , V_4 , 0 ) ;
if ( V_11 < 0 )
break;
F_7 ( V_9 . V_16 , V_9 . V_14 != V_15 ,
F_8 ( V_24 ) ) ;
if ( V_9 . V_14 == V_25 ) {
V_11 = V_9 . V_6 ;
break;
} else if ( V_9 . V_14 == V_26 ) {
F_9 ( V_27 ) ;
} else if ( ++ V_12 >= V_28 ) {
F_10 ( & V_9 . V_2 -> V_29 , L_1 ) ;
V_11 = - V_30 ;
break;
}
}
F_3 ( & V_17 ) ;
F_11 ( & V_9 . V_18 ) ;
F_5 ( & V_17 ) ;
return V_11 ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_3 ( & V_17 ) ;
F_13 (t, &transactions, list) {
if ( V_9 -> V_2 == V_2 &&
V_9 -> V_14 == V_15 ) {
V_9 -> V_14 = V_26 ;
F_14 ( & V_9 -> V_16 ) ;
}
}
F_5 ( & V_17 ) ;
}
static bool F_15 ( struct V_8 * V_31 ,
const void * V_5 , T_1 V_32 )
{
const T_2 * V_33 , * V_34 ;
unsigned int V_35 , V_36 ;
V_33 = V_5 ;
V_34 = V_31 -> V_13 ;
V_35 = V_31 -> V_7 ;
for ( V_36 = 0 ; ; ++ V_36 ) {
if ( ( V_35 & 1 ) && V_33 [ V_36 ] != V_34 [ V_36 ] )
return false ;
V_35 >>= 1 ;
if ( ! V_35 )
return true ;
if ( -- V_32 == 0 )
return false ;
}
}
static void F_16 ( struct V_37 * V_38 , struct V_39 * V_40 ,
int V_10 , int V_41 , int V_42 ,
int V_43 , unsigned long long V_44 ,
void * V_45 , T_1 V_32 , void * V_46 )
{
struct V_8 * V_9 ;
unsigned long V_47 ;
if ( V_32 < 1 || ( * ( const T_2 * ) V_45 & 0xf0 ) != V_48 )
return;
F_17 ( & V_17 , V_47 ) ;
F_13 (t, &transactions, list) {
struct V_49 * V_29 = F_18 ( V_9 -> V_2 ) ;
if ( V_29 -> V_38 != V_38 ||
V_29 -> V_43 != V_43 )
continue;
F_19 () ;
if ( V_29 -> V_50 != V_42 )
continue;
if ( V_9 -> V_14 == V_15 &&
F_15 ( V_9 , V_45 , V_32 ) ) {
V_9 -> V_14 = V_25 ;
V_9 -> V_6 = F_20 ( ( unsigned int ) V_32 ,
V_9 -> V_6 ) ;
memcpy ( V_9 -> V_13 , V_45 , V_9 -> V_6 ) ;
F_14 ( & V_9 -> V_16 ) ;
}
}
F_21 ( & V_17 , V_47 ) ;
}
static int T_3 F_22 ( void )
{
static const struct V_51 V_52 = {
. V_53 = V_22 + V_54 ,
. V_55 = V_22 + V_56 ,
} ;
F_23 ( & V_57 ,
& V_52 ) ;
return 0 ;
}
static void T_4 F_24 ( void )
{
F_25 ( ! F_26 ( & V_19 ) ) ;
F_27 ( & V_57 ) ;
}
