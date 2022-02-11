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
V_24 ) ;
F_14 ( V_17 , V_23 ,
V_24 ) ;
}
}
static void F_15 ( unsigned int V_2 , unsigned int V_25 )
{
struct V_4 * V_5 = & F_6 ( V_6 , V_2 ) ;
F_7 ( V_25 , V_5 -> V_26 ) ;
}
static void T_2 F_16 ( void )
{
F_7 ( V_27 . V_28 ,
V_29 + V_30 ) ;
F_7 ( V_27 . V_31 ,
V_29 + V_32 ) ;
}
static void T_2 F_16 ( void )
{}
int F_17 ( unsigned int V_33 , unsigned int V_34 )
{
struct V_4 * V_5 = & F_6 ( V_6 , V_33 ) ;
unsigned int V_25 = 0 ;
unsigned int V_35 ;
if ( F_18 () == V_36 )
return - V_37 ;
switch ( V_34 ) {
case V_13 :
case V_14 :
V_25 = 0 ;
break;
case V_11 :
V_25 = 1 ;
break;
case V_9 :
default:
F_19 ( 1 ) ;
return - V_37 ;
}
F_20 ( NULL ) ;
F_9 () ;
if ( ( F_21 ( V_38 ) == V_9 ) &&
( F_22 ( V_38 ) == V_11 ) )
V_25 = 2 ;
F_12 ( V_33 ) ;
F_23 ( V_5 -> V_39 , V_34 ) ;
F_5 ( V_33 , F_24 ( V_40 . V_41 ) ) ;
V_40 . V_42 ( V_33 , V_34 ) ;
F_15 ( V_33 , V_25 ) ;
if ( V_25 )
F_25 ( V_25 , V_40 . V_43 ) ;
else
V_40 . V_43 ( V_25 ) ;
if ( F_26 ( V_44 ) && V_33 )
F_27 () ;
V_35 = F_28 () ;
F_23 ( V_5 -> V_39 , V_13 ) ;
F_29 ( NULL ) ;
return 0 ;
}
int F_30 ( unsigned int V_33 , unsigned int V_34 )
{
struct V_4 * V_5 = & F_6 ( V_6 , V_33 ) ;
unsigned int V_1 = 0 ;
if ( F_18 () == V_36 )
return - V_37 ;
if ( V_34 == V_11 )
V_1 = 1 ;
F_31 ( V_5 -> V_39 ) ;
F_23 ( V_5 -> V_39 , V_34 ) ;
F_5 ( V_33 , F_24 ( V_5 -> V_45 ) ) ;
V_40 . V_42 ( V_33 , V_34 ) ;
V_40 . V_43 ( V_1 ) ;
F_23 ( V_5 -> V_39 , V_13 ) ;
return 0 ;
}
int T_2 F_32 ( void )
{
struct V_4 * V_5 ;
if ( F_18 () == V_36 ) {
F_33 ( 1 , L_1 ) ;
return - V_46 ;
}
V_29 = F_34 () ;
V_5 = & F_6 ( V_6 , 0x0 ) ;
V_5 -> V_16 = V_29 + V_47 ;
V_5 -> V_7 = V_29 + V_48 ;
V_5 -> V_26 = V_29 + V_49 ;
V_5 -> V_39 = F_35 ( L_2 ) ;
if ( ! V_5 -> V_39 ) {
F_36 ( L_3 ) ;
return - V_46 ;
}
F_31 ( V_5 -> V_39 ) ;
F_12 ( 0 ) ;
F_23 ( V_5 -> V_39 , V_13 ) ;
V_5 = & F_6 ( V_6 , 0x1 ) ;
V_5 -> V_16 = V_29 + V_50 ;
V_5 -> V_7 = V_29 + V_51 ;
V_5 -> V_26 = V_29 + V_52 ;
if ( F_37 () )
V_5 -> V_45 = V_53 ;
else
V_5 -> V_45 = V_54 ;
V_5 -> V_39 = F_35 ( L_4 ) ;
if ( ! V_5 -> V_39 ) {
F_36 ( L_5 ) ;
return - V_46 ;
}
F_31 ( V_5 -> V_39 ) ;
F_12 ( 1 ) ;
F_23 ( V_5 -> V_39 , V_13 ) ;
V_38 = F_35 ( L_6 ) ;
if ( ! V_38 ) {
F_36 ( L_7 ) ;
return - V_46 ;
}
F_31 ( V_38 ) ;
F_9 () ;
if ( F_38 () != V_55 )
F_7 ( 1 , V_29 + V_56 ) ;
else
F_7 ( 0 , V_29 + V_56 ) ;
F_16 () ;
if ( F_39 () ) {
V_40 . V_43 = V_57 ;
V_40 . V_41 = V_58 ;
V_40 . V_42 = F_8 ;
}
return 0 ;
}
