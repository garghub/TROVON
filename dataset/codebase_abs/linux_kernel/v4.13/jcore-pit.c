static T_1 T_2 F_1 ( void )
{
T_3 V_1 , V_2 , V_3 ;
T_4 void * V_4 = V_5 ;
V_1 = F_2 ( V_4 + V_6 ) ;
do {
V_3 = V_1 ;
V_2 = F_2 ( V_4 + V_7 ) ;
V_1 = F_2 ( V_4 + V_6 ) ;
} while ( V_3 != V_1 );
return V_1 * V_8 + V_2 ;
}
static T_2 F_3 ( struct V_9 * V_10 )
{
return F_1 () ;
}
static int F_4 ( struct V_11 * V_12 )
{
F_5 ( 0 , V_12 -> V_4 + V_13 ) ;
return 0 ;
}
static int F_6 ( unsigned long V_14 , struct V_11 * V_12 )
{
F_4 ( V_12 ) ;
F_5 ( V_14 , V_12 -> V_4 + V_15 ) ;
F_5 ( V_12 -> V_16 , V_12 -> V_4 + V_13 ) ;
return 0 ;
}
static int F_7 ( struct V_17 * V_18 )
{
struct V_11 * V_12 = F_8 ( V_18 , struct V_11 , V_18 ) ;
return F_4 ( V_12 ) ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_11 * V_12 = F_8 ( V_18 , struct V_11 , V_18 ) ;
return F_4 ( V_12 ) ;
}
static int F_10 ( struct V_17 * V_18 )
{
struct V_11 * V_12 = F_8 ( V_18 , struct V_11 , V_18 ) ;
return F_6 ( V_12 -> V_19 , V_12 ) ;
}
static int F_11 ( unsigned long V_14 ,
struct V_17 * V_18 )
{
struct V_11 * V_12 = F_8 ( V_18 , struct V_11 , V_18 ) ;
return F_6 ( V_14 , V_12 ) ;
}
static int F_12 ( unsigned V_20 )
{
struct V_11 * V_12 = F_13 ( V_21 ) ;
unsigned V_22 , V_23 ;
F_14 ( L_1 , V_20 ) ;
V_22 = F_2 ( V_12 -> V_4 + V_24 ) ;
V_23 = F_15 ( V_8 , V_22 ) ;
V_12 -> V_19 = F_15 ( V_8 , V_25 * V_22 ) ;
F_16 ( & V_12 -> V_18 , V_23 , 1 , V_26 ) ;
return 0 ;
}
static T_5 F_17 ( int V_27 , void * V_28 )
{
struct V_11 * V_12 = F_13 ( V_28 ) ;
if ( F_18 ( & V_12 -> V_18 ) )
F_4 ( V_12 ) ;
V_12 -> V_18 . V_29 ( & V_12 -> V_18 ) ;
return V_30 ;
}
static int T_6 F_19 ( struct V_31 * V_32 )
{
int V_33 ;
unsigned V_34 , V_20 ;
unsigned long V_35 ;
T_3 V_36 , V_16 ;
V_5 = F_20 ( V_32 , 0 ) ;
if ( ! V_5 ) {
F_21 ( L_2 ) ;
return - V_37 ;
}
V_34 = F_22 ( V_32 , 0 ) ;
if ( ! V_34 ) {
F_21 ( L_3 ) ;
return - V_37 ;
}
F_14 ( L_4 ,
V_5 , V_34 ) ;
V_33 = F_23 ( V_5 , L_5 ,
V_8 , 400 , 32 ,
F_3 ) ;
if ( V_33 ) {
F_21 ( L_6 , V_33 ) ;
return V_33 ;
}
F_24 ( F_1 , 32 , V_8 ) ;
V_21 = F_25 ( struct V_11 ) ;
if ( ! V_21 ) {
F_21 ( L_7 ) ;
return - V_38 ;
}
V_33 = F_26 ( V_34 , F_17 ,
V_39 | V_40 ,
L_8 , V_21 ) ;
if ( V_33 ) {
F_21 ( L_9 , V_33 ) ;
F_27 ( V_21 ) ;
return V_33 ;
}
V_35 = F_28 ( V_34 ) -> V_35 ;
V_36 = ( V_35 >> 2 ) & V_41 ;
V_16 = ( 1U << V_42 )
| ( V_35 << V_43 )
| ( V_36 << V_44 ) ;
F_29 (cpu) {
struct V_11 * V_12 = F_30 ( V_21 , V_20 ) ;
V_12 -> V_4 = F_20 ( V_32 , V_20 ) ;
if ( ! V_12 -> V_4 ) {
F_21 ( L_10 , V_20 ) ;
continue;
}
V_12 -> V_18 . V_45 = L_8 ;
V_12 -> V_18 . V_46 = V_47
| V_48
| V_49 ;
V_12 -> V_18 . V_50 = F_31 ( V_20 ) ;
V_12 -> V_18 . V_51 = 400 ;
V_12 -> V_18 . V_27 = V_34 ;
V_12 -> V_18 . V_52 = F_7 ;
V_12 -> V_18 . V_53 = F_10 ;
V_12 -> V_18 . V_54 = F_9 ;
V_12 -> V_18 . V_55 = F_11 ;
V_12 -> V_16 = V_16 ;
}
F_32 ( V_56 ,
L_11 ,
F_12 , NULL ) ;
return 0 ;
}
