static int F_1 ( unsigned long V_1 )
{
F_2 () ;
return 0 ;
}
static void F_3 ( void )
{}
static void F_4 ( unsigned int V_2 , unsigned int V_1 )
{}
static inline void F_5 ( unsigned int V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & F_6 ( V_6 , V_2 ) ;
if ( V_5 -> V_7 )
F_7 ( V_3 , V_5 -> V_7 ) ;
}
static void F_8 ( unsigned int V_2 , unsigned int V_1 )
{
struct V_4 * V_5 = & F_6 ( V_6 , V_2 ) ;
T_1 V_8 ;
switch ( V_1 ) {
case V_9 :
V_8 = V_10 ;
break;
case V_11 :
V_8 = V_12 ;
break;
case V_13 :
case V_14 :
default:
V_8 = V_15 ;
break;
}
if ( V_5 -> V_16 )
F_7 ( V_8 , V_5 -> V_16 ) ;
}
static inline void F_9 ( void )
{
T_1 V_17 ;
V_17 = F_10 ( V_18 ,
V_19 , V_20 ) ;
F_11 ( V_17 , V_18 ,
V_19 , V_20 ) ;
}
static inline void F_12 ( unsigned int V_2 )
{
T_1 V_17 ;
if ( V_2 ) {
V_17 = F_13 ( V_21 ,
V_22 ) ;
F_14 ( V_17 , V_21 ,
V_22 ) ;
} else {
V_17 = F_13 ( V_23 ,
V_22 ) ;
F_14 ( V_17 , V_23 ,
V_22 ) ;
}
}
static void F_15 ( unsigned int V_2 , unsigned int V_24 )
{
struct V_4 * V_5 = & F_6 ( V_6 , V_2 ) ;
if ( V_5 -> V_25 )
F_7 ( V_24 , V_5 -> V_25 ) ;
}
static void T_2 F_16 ( void )
{
void T_3 * V_26 = F_17 () ;
if ( V_26 && V_27 ) {
F_7 ( V_28 . V_29 ,
V_27 + V_30 ) ;
F_7 ( V_28 . V_31 ,
V_27 + V_32 ) ;
}
}
static void T_2 F_16 ( void )
{}
int F_18 ( unsigned int V_33 , unsigned int V_34 )
{
struct V_4 * V_5 = & F_6 ( V_6 , V_33 ) ;
unsigned int V_24 = 0 , V_35 = V_9 ;
unsigned int V_36 ;
if ( F_19 () == V_37 )
return - V_38 ;
switch ( V_34 ) {
case V_13 :
case V_14 :
V_24 = 0 ;
break;
case V_11 :
V_35 = V_11 ;
V_24 = 1 ;
break;
case V_9 :
if ( F_20 ( V_39 ) ) {
V_24 = 0 ;
break;
}
default:
F_21 ( 1 ) ;
return - V_38 ;
}
F_22 ( NULL ) ;
F_9 () ;
if ( ( F_23 ( V_40 ) == V_9 ) &&
( F_24 ( V_40 ) == V_11 ) )
V_24 = 2 ;
F_12 ( V_33 ) ;
F_25 ( V_5 -> V_41 , V_34 ) ;
F_26 ( V_5 -> V_41 , V_35 ) ;
F_5 ( V_33 , F_27 ( V_42 . V_43 ) ) ;
V_42 . V_44 ( V_33 , V_34 ) ;
F_15 ( V_33 , V_24 ) ;
if ( V_24 )
F_28 ( V_24 , V_42 . V_45 ) ;
else
V_42 . V_45 ( V_24 ) ;
if ( F_20 ( V_46 ) && V_33 )
F_29 () ;
V_36 = F_30 () ;
F_25 ( V_5 -> V_41 , V_13 ) ;
F_31 ( NULL ) ;
return 0 ;
}
int F_32 ( unsigned int V_33 , unsigned int V_34 )
{
struct V_4 * V_5 = & F_6 ( V_6 , V_33 ) ;
unsigned int V_1 = 0 ;
if ( F_19 () == V_37 )
return - V_38 ;
V_34 = F_33 ( V_5 -> V_41 ,
false , V_34 ) ;
if ( V_34 == V_11 )
V_1 = 1 ;
F_34 ( V_5 -> V_41 ) ;
F_25 ( V_5 -> V_41 , V_34 ) ;
F_5 ( V_33 , F_27 ( V_42 . V_47 ) ) ;
V_42 . V_44 ( V_33 , V_34 ) ;
V_42 . V_45 ( V_1 ) ;
F_25 ( V_5 -> V_41 , V_13 ) ;
return 0 ;
}
static void F_35 ( void )
{
T_1 V_17 ;
V_17 = F_13 ( V_48 ,
V_49 ) ;
V_17 |= F_36 ( 24 ) | F_36 ( 25 ) ;
F_14 ( V_17 , V_48 ,
V_49 ) ;
}
int T_2 F_37 ( void )
{
struct V_4 * V_5 ;
if ( F_19 () == V_37 ) {
F_38 ( 1 , L_1 ) ;
return - V_50 ;
}
if ( F_39 () )
V_27 = F_40 () ;
V_5 = & F_6 ( V_6 , 0x0 ) ;
if ( V_27 ) {
V_5 -> V_16 = V_27 + V_51 ;
V_5 -> V_7 = V_27 +
V_52 ;
V_5 -> V_25 = V_27 + V_53 ;
}
V_5 -> V_41 = F_41 ( L_2 ) ;
if ( ! V_5 -> V_41 ) {
F_42 ( L_3 ) ;
return - V_50 ;
}
F_34 ( V_5 -> V_41 ) ;
F_12 ( 0 ) ;
F_25 ( V_5 -> V_41 , V_13 ) ;
V_5 = & F_6 ( V_6 , 0x1 ) ;
if ( V_27 ) {
V_5 -> V_16 = V_27 + V_54 ;
V_5 -> V_7 = V_27 +
V_55 ;
V_5 -> V_25 = V_27 + V_56 ;
}
V_5 -> V_41 = F_41 ( L_4 ) ;
if ( ! V_5 -> V_41 ) {
F_42 ( L_5 ) ;
return - V_50 ;
}
F_34 ( V_5 -> V_41 ) ;
F_12 ( 1 ) ;
F_25 ( V_5 -> V_41 , V_13 ) ;
V_40 = F_41 ( L_6 ) ;
if ( ! V_40 ) {
F_42 ( L_7 ) ;
return - V_50 ;
}
F_34 ( V_40 ) ;
F_9 () ;
if ( V_27 ) {
F_7 ( ( F_43 () != V_57 ) ? 1 : 0 ,
V_27 + V_58 ) ;
F_16 () ;
}
if ( F_39 () ) {
V_42 . V_45 = V_59 ;
V_42 . V_43 = V_60 ;
V_42 . V_44 = F_8 ;
V_42 . V_47 = V_61 ;
V_22 = V_62 ;
} else if ( F_44 () || F_45 () ) {
V_22 = V_63 ;
F_35 () ;
}
if ( F_46 () )
V_42 . V_47 = V_64 ;
return 0 ;
}
