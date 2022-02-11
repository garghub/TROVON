static void F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_3 ( V_2 ) ;
T_2 V_5 = 1 << V_3 ;
F_4 ( V_4 + V_6 , V_5 ) ;
F_5 ( V_4 + V_7 , V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_3 ( V_2 ) ;
F_5 ( V_4 + V_7 , 1 << V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_3 ( V_2 ) ;
F_4 ( V_4 + V_6 , 1 << V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_3 ( V_2 ) ;
F_9 ( V_4 + V_6 , 1 << V_3 ) ;
}
static int F_10 ( struct V_8 * V_9 , unsigned int V_10 ,
T_3 V_11 )
{
F_11 ( V_10 , V_9 -> V_12 ) ;
F_12 ( V_10 , V_13 ) ;
F_13 ( V_10 , & V_14 , V_15 ) ;
return 0 ;
}
static unsigned int F_14 ( struct V_8 * V_9 )
{
void T_1 * V_4 = V_9 -> V_12 ;
int V_3 ;
T_2 V_16 ;
V_16 = F_15 ( V_4 + V_7 ) &
F_15 ( V_4 + V_6 ) ;
if ( V_16 == 0 )
return V_17 ;
V_3 = F_16 ( V_16 ) ;
return F_17 ( V_9 , V_3 ) ;
}
static void F_18 ( unsigned int V_18 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = F_19 ( V_20 ) ;
struct V_8 * V_8 = F_20 ( V_18 ) ;
unsigned int V_10 ;
F_21 ( & V_20 -> V_23 ) ;
V_22 -> V_24 ( & V_20 -> V_1 ) ;
F_22 ( & V_20 -> V_23 ) ;
V_10 = F_14 ( V_8 ) ;
if ( V_10 != V_17 )
F_23 ( V_10 ) ;
else
F_24 ( L_1 ) ;
F_21 ( & V_20 -> V_23 ) ;
V_22 -> V_25 ( & V_20 -> V_1 ) ;
if ( ! F_25 ( & V_20 -> V_1 ) && V_22 -> V_26 )
V_22 -> V_26 ( & V_20 -> V_1 ) ;
F_22 ( & V_20 -> V_23 ) ;
}
static void F_26 ( void T_1 * V_4 )
{
F_5 ( V_4 + V_6 , 0 ) ;
F_5 ( V_4 + V_7 , 0xffffffff ) ;
}
struct V_8 * F_27 ( struct V_27 * V_28 )
{
struct V_8 * V_8 ;
struct V_29 V_30 ;
void T_1 * V_4 ;
int V_31 ;
V_31 = F_28 ( V_28 , 0 , & V_30 ) ;
if ( V_31 ) {
F_24 ( L_2 ) ;
return NULL ;
}
V_4 = F_29 ( V_30 . V_32 , F_30 ( & V_30 ) ) ;
if ( ! V_4 ) {
F_24 ( L_3 ) ;
return NULL ;
}
F_31 ( L_4 , V_30 . V_32 , V_4 ) ;
F_26 ( V_4 ) ;
V_8 = F_32 ( V_28 , V_33 ,
& V_34 , V_4 ) ;
if ( ! V_8 ) {
F_24 ( L_5 ) ;
F_33 ( V_4 ) ;
return NULL ;
}
return V_8 ;
}
unsigned int F_34 ( void )
{
return F_14 ( V_35 ) ;
}
void F_35 ( void )
{
struct V_8 * V_36 ;
struct V_27 * V_28 ;
const T_2 * V_37 ;
int V_18 ;
F_36 (np, NULL, L_6 ) {
V_37 = F_37 ( V_28 , L_7 , NULL ) ;
if ( V_37 ) {
V_36 = F_27 ( V_28 ) ;
F_38 ( ! V_36 ) ;
V_18 = F_39 ( V_28 , 0 ) ;
F_40 ( V_18 , V_36 ) ;
F_41 ( V_18 ,
F_18 ) ;
V_35 = V_36 ;
break;
}
}
}
void F_42 ( void )
{
void T_1 * V_4 = V_35 -> V_12 ;
F_26 ( V_4 ) ;
}
