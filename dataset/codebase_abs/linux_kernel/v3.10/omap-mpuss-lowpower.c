static inline void F_1 ( unsigned int V_1 , T_1 V_2 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_1 ) ;
F_3 ( V_2 , V_4 -> V_6 ) ;
}
static void F_4 ( unsigned int V_1 , unsigned int V_7 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_1 ) ;
T_1 V_8 ;
switch ( V_7 ) {
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
F_3 ( V_8 , V_4 -> V_16 ) ;
}
static inline void F_5 ( void )
{
T_1 V_17 ;
V_17 = F_6 ( V_18 ,
V_19 , V_20 ) ;
F_7 ( V_17 , V_18 ,
V_19 , V_20 ) ;
}
static inline void F_8 ( unsigned int V_1 )
{
T_1 V_17 ;
if ( V_1 ) {
V_17 = F_9 ( V_21 ,
V_22 ) ;
F_10 ( V_17 , V_21 ,
V_22 ) ;
} else {
V_17 = F_9 ( V_23 ,
V_24 ) ;
F_10 ( V_17 , V_23 ,
V_24 ) ;
}
}
static void F_11 ( unsigned int V_1 , unsigned int V_25 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_1 ) ;
F_3 ( V_25 , V_4 -> V_26 ) ;
}
static void F_12 ( void )
{
T_1 V_27 ;
void T_2 * V_28 = F_13 () ;
V_27 = F_14 ( V_28 + V_29 ) ;
F_3 ( V_27 , V_30 + V_31 ) ;
V_27 = F_14 ( V_28 + V_32 ) ;
F_3 ( V_27 , V_30 + V_33 ) ;
}
static void F_12 ( void )
{}
int F_15 ( unsigned int V_34 , unsigned int V_35 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_34 ) ;
unsigned int V_25 = 0 ;
unsigned int V_36 ;
if ( F_16 () == V_37 )
return - V_38 ;
switch ( V_35 ) {
case V_13 :
case V_14 :
V_25 = 0 ;
break;
case V_11 :
V_25 = 1 ;
break;
case V_9 :
default:
F_17 ( 1 ) ;
return - V_38 ;
}
F_18 ( NULL ) ;
F_5 () ;
if ( ( F_19 ( V_39 ) == V_9 ) &&
( F_20 ( V_39 ) == V_11 ) )
V_25 = 2 ;
F_8 ( V_34 ) ;
F_21 ( V_4 -> V_40 , V_35 ) ;
F_1 ( V_34 , F_22 ( V_41 ) ) ;
F_4 ( V_34 , V_35 ) ;
F_11 ( V_34 , V_25 ) ;
F_23 ( V_25 , V_42 ) ;
V_36 = F_24 () ;
F_21 ( V_4 -> V_40 , V_13 ) ;
F_25 ( NULL ) ;
return 0 ;
}
int T_3 F_26 ( unsigned int V_34 , unsigned int V_35 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_34 ) ;
unsigned int V_7 = 0 ;
if ( F_16 () == V_37 )
return - V_38 ;
if ( V_35 == V_11 )
V_7 = 1 ;
F_27 ( V_4 -> V_40 ) ;
F_21 ( V_4 -> V_40 , V_35 ) ;
F_1 ( V_34 , F_22 ( V_4 -> V_43 ) ) ;
F_4 ( V_34 , V_35 ) ;
V_42 ( V_7 ) ;
F_21 ( V_4 -> V_40 , V_13 ) ;
return 0 ;
}
int T_4 F_28 ( void )
{
struct V_3 * V_4 ;
if ( F_16 () == V_37 ) {
F_29 ( 1 , L_1 ) ;
return - V_44 ;
}
V_30 = F_30 () ;
V_4 = & F_2 ( V_5 , 0x0 ) ;
V_4 -> V_16 = V_30 + V_45 ;
V_4 -> V_6 = V_30 + V_46 ;
V_4 -> V_26 = V_30 + V_47 ;
V_4 -> V_40 = F_31 ( L_2 ) ;
if ( ! V_4 -> V_40 ) {
F_32 ( L_3 ) ;
return - V_44 ;
}
F_27 ( V_4 -> V_40 ) ;
F_8 ( 0 ) ;
F_21 ( V_4 -> V_40 , V_13 ) ;
V_4 = & F_2 ( V_5 , 0x1 ) ;
V_4 -> V_16 = V_30 + V_48 ;
V_4 -> V_6 = V_30 + V_49 ;
V_4 -> V_26 = V_30 + V_50 ;
if ( F_33 () )
V_4 -> V_43 = V_51 ;
else
V_4 -> V_43 = V_52 ;
V_4 -> V_40 = F_31 ( L_4 ) ;
if ( ! V_4 -> V_40 ) {
F_32 ( L_5 ) ;
return - V_44 ;
}
F_27 ( V_4 -> V_40 ) ;
F_8 ( 1 ) ;
F_21 ( V_4 -> V_40 , V_13 ) ;
V_39 = F_31 ( L_6 ) ;
if ( ! V_39 ) {
F_32 ( L_7 ) ;
return - V_44 ;
}
F_27 ( V_39 ) ;
F_5 () ;
if ( F_34 () != V_53 )
F_3 ( 1 , V_30 + V_54 ) ;
else
F_3 ( 0 , V_30 + V_54 ) ;
F_12 () ;
return 0 ;
}
