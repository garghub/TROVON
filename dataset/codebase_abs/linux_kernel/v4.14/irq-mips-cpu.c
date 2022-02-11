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
F_15 ( ! F_16 ( F_17 () , V_7 ) ) ;
V_5 = F_8 () ;
F_18 ( F_19 ( & V_9 [ V_7 ] ) ) ;
F_20 ( F_21 () | ( V_6 << V_4 ) ) ;
F_10 ( V_5 ) ;
F_22 ( V_8 ) ;
}
T_2 void __weak F_23 ( void )
{
unsigned long V_10 = F_24 () & F_25 () & V_11 ;
unsigned int V_12 ;
int V_13 ;
if ( ! V_10 ) {
F_26 () ;
return;
}
V_10 >>= V_14 ;
while ( V_10 ) {
V_13 = F_27 ( V_10 ) - 1 ;
if ( F_28 ( V_15 ) && V_13 < 2 )
V_12 = F_29 ( V_16 , V_13 ) ;
else
V_12 = F_29 ( V_17 , V_13 ) ;
F_30 ( V_12 ) ;
V_10 &= ~ F_31 ( V_13 ) ;
}
}
static int F_32 ( struct V_17 * V_2 , unsigned int V_13 ,
T_1 V_18 )
{
struct V_19 * V_20 ;
if ( V_18 < 2 && V_21 ) {
V_20 = & V_22 ;
} else {
V_20 = & V_23 ;
}
if ( V_24 )
F_33 ( V_18 , F_23 ) ;
F_34 ( V_13 , V_20 , V_25 ) ;
return 0 ;
}
static int F_35 ( struct V_17 * V_26 , unsigned int V_12 ,
unsigned int V_27 , void * V_28 )
{
struct V_29 * V_30 = V_26 -> V_31 ;
unsigned int V_32 , V_4 ;
int V_33 ;
for ( V_32 = 0 ; V_32 < V_27 ; V_32 ++ ) {
V_4 = F_36 ( V_30 -> V_34 , 2 ) ;
if ( V_4 == 2 )
return - V_35 ;
F_37 ( V_30 -> V_34 , V_4 , 1 ) ;
V_33 = F_38 ( V_26 , V_12 + V_32 , V_4 ,
& V_22 ,
NULL ) ;
if ( V_33 )
return V_33 ;
V_33 = F_39 ( V_12 + V_32 , V_36 ) ;
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static int F_40 ( struct V_17 * V_2 , struct V_37 * V_38 ,
enum V_39 V_40 )
{
bool V_41 ;
switch ( V_40 ) {
case V_42 :
V_41 = V_2 -> V_40 == V_40 ;
return ( ! V_38 || ( F_41 ( V_2 -> V_43 ) == V_38 ) ) && V_41 ;
default:
return 0 ;
}
}
static void F_42 ( struct V_37 * V_44 )
{
struct V_29 * V_45 ;
V_45 = F_43 ( sizeof( * V_45 ) , V_46 ) ;
V_16 = F_44 ( V_17 ,
V_47 ,
2 , V_44 ,
& V_48 ,
V_45 ) ;
if ( ! V_16 )
F_45 ( L_1 ) ;
F_46 ( V_16 , V_42 ) ;
}
static inline void F_42 ( struct V_37 * V_44 ) {}
static void T_3 F_47 ( struct V_37 * V_44 )
{
F_5 ( V_11 ) ;
F_9 ( V_49 ) ;
V_17 = F_48 ( V_44 , 8 , V_50 , 0 ,
& V_51 ,
NULL ) ;
if ( ! V_17 )
F_45 ( L_2 ) ;
if ( V_21 )
F_42 ( V_44 ) ;
}
void T_3 F_49 ( void )
{
F_47 ( NULL ) ;
}
int T_3 F_50 ( struct V_37 * V_44 ,
struct V_37 * V_52 )
{
F_47 ( V_44 ) ;
return 0 ;
}
