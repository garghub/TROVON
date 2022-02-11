static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 << V_2 -> V_4 ) ;
F_3 () ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_3 << V_2 -> V_4 ) ;
F_6 () ;
}
static unsigned int F_7 ( struct V_1 * V_2 )
{
unsigned int V_5 = F_8 () ;
F_9 ( V_6 << V_2 -> V_4 ) ;
F_10 ( V_5 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_5 = F_8 () ;
F_9 ( V_6 << V_2 -> V_4 ) ;
F_10 ( V_5 ) ;
F_4 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_7 )
{
T_1 V_4 = F_13 ( V_2 ) ;
unsigned long V_8 ;
int V_5 ;
F_14 ( V_8 ) ;
F_15 ( V_9 [ V_7 ] . V_10 != V_11 . V_10 ) ;
V_5 = F_8 () ;
F_16 ( F_17 ( & V_9 [ V_7 ] ) ) ;
F_18 ( F_19 () | ( V_6 << V_4 ) ) ;
F_10 ( V_5 ) ;
F_20 ( V_8 ) ;
}
T_2 void __weak F_21 ( void )
{
unsigned long V_12 = F_22 () & F_23 () & V_13 ;
unsigned int V_14 ;
int V_15 ;
if ( ! V_12 ) {
F_24 () ;
return;
}
V_12 >>= V_16 ;
while ( V_12 ) {
V_15 = F_25 ( V_12 ) - 1 ;
if ( F_26 ( V_17 ) && V_15 < 2 )
V_14 = F_27 ( V_18 , V_15 ) ;
else
V_14 = F_27 ( V_19 , V_15 ) ;
F_28 ( V_14 ) ;
V_12 &= ~ F_29 ( V_15 ) ;
}
}
static int F_30 ( struct V_19 * V_2 , unsigned int V_15 ,
T_1 V_20 )
{
struct V_21 * V_22 ;
if ( V_20 < 2 && V_23 ) {
V_22 = & V_24 ;
} else {
V_22 = & V_25 ;
}
if ( V_26 )
F_31 ( V_20 , F_21 ) ;
F_32 ( V_15 , V_22 , V_27 ) ;
return 0 ;
}
static int F_33 ( struct V_19 * V_28 , unsigned int V_14 ,
unsigned int V_29 , void * V_30 )
{
struct V_31 * V_32 = V_28 -> V_33 ;
unsigned int V_34 , V_4 ;
int V_35 ;
for ( V_34 = 0 ; V_34 < V_29 ; V_34 ++ ) {
V_4 = F_34 ( V_32 -> V_36 , 2 ) ;
if ( V_4 == 2 )
return - V_37 ;
F_35 ( V_32 -> V_36 , V_4 , 1 ) ;
V_35 = F_36 ( V_28 , V_14 + V_34 , V_4 ,
& V_24 ,
NULL ) ;
if ( V_35 )
return V_35 ;
V_35 = F_37 ( V_14 + V_34 , V_38 ) ;
if ( V_35 )
return V_35 ;
}
return 0 ;
}
static int F_38 ( struct V_19 * V_2 , struct V_39 * V_40 ,
enum V_41 V_42 )
{
bool V_43 ;
switch ( V_42 ) {
case V_44 :
V_43 = V_2 -> V_42 == V_42 ;
return ( ! V_40 || ( F_39 ( V_2 -> V_45 ) == V_40 ) ) && V_43 ;
default:
return 0 ;
}
}
static void F_40 ( struct V_39 * V_46 )
{
struct V_31 * V_47 ;
V_47 = F_41 ( sizeof( * V_47 ) , V_48 ) ;
V_18 = F_42 ( V_19 ,
V_49 ,
2 , V_46 ,
& V_50 ,
V_47 ) ;
if ( ! V_18 )
F_43 ( L_1 ) ;
F_44 ( V_18 , V_44 ) ;
}
static inline void F_40 ( struct V_39 * V_46 ) {}
static void T_3 F_45 ( struct V_39 * V_46 )
{
F_5 ( V_13 ) ;
F_9 ( V_51 ) ;
V_19 = F_46 ( V_46 , 8 , V_52 , 0 ,
& V_53 ,
NULL ) ;
if ( ! V_19 )
F_43 ( L_2 ) ;
if ( V_23 )
F_40 ( V_46 ) ;
}
void T_3 F_47 ( void )
{
F_45 ( NULL ) ;
}
int T_3 F_48 ( struct V_39 * V_46 ,
struct V_39 * V_54 )
{
F_45 ( V_46 ) ;
return 0 ;
}
