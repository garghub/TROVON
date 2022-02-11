static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 -> V_4 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
T_1 V_4 = F_3 ( V_2 ) ;
F_1 ( V_2 , V_4 & ~ ( 1 << V_2 -> V_5 ) ) ;
}
struct V_1 * F_6 ( unsigned int V_6 )
{
unsigned long V_7 ;
struct V_1 * V_2 ;
V_2 = F_7 ( - V_8 ) ;
if ( V_6 >= V_9 )
return F_7 ( - V_10 ) ;
F_8 ( & V_11 , V_7 ) ;
V_2 = V_12 [ V_6 ] ;
if ( V_2 -> V_13 == V_14 )
V_2 -> V_13 = V_15 ;
F_9 ( & V_11 , V_7 ) ;
return V_2 ;
}
void F_10 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
F_8 ( & V_2 -> V_16 , V_7 ) ;
V_2 -> V_13 = V_14 ;
F_5 ( V_2 ) ;
F_9 ( & V_2 -> V_16 , V_7 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
T_1 V_4 ;
F_8 ( & V_2 -> V_16 , V_7 ) ;
V_4 = F_3 ( V_2 ) ;
F_1 ( V_2 , V_4 | ( 1 << V_2 -> V_5 ) ) ;
F_9 ( & V_2 -> V_16 , V_7 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
F_8 ( & V_2 -> V_16 , V_7 ) ;
F_5 ( V_2 ) ;
F_9 ( & V_2 -> V_16 , V_7 ) ;
}
static unsigned int F_13 ( void )
{
unsigned int V_17 ;
struct V_18 * V_19 ;
V_17 = 0 ;
V_19 = F_14 ( NULL , L_1 ) ;
if ( V_19 ) {
char V_20 [ 32 ] ;
for (; ; ) {
snprintf ( V_20 , sizeof( V_20 ) , L_2 , V_17 ) ;
if ( ! F_15 ( V_19 , V_20 , NULL ) )
break;
V_17 += 1 ;
}
}
return V_17 ;
}
static unsigned int F_16 ( void )
{
return F_13 () * V_21 ;
}
static int F_17 ( struct V_18 * V_22 )
{
struct V_18 * V_19 ;
unsigned int V_23 , V_24 ;
char V_20 [ 64 ] ;
V_24 = F_13 () ;
V_19 = F_14 ( NULL , L_1 ) ;
if ( ! V_19 )
return - 1 ;
for ( V_23 = 0 ; V_23 < V_24 ; ++ V_23 ) {
struct V_25 * V_26 ;
snprintf ( V_20 , sizeof( V_20 ) , L_2 , V_23 ) ;
V_26 = F_15 ( V_19 , V_20 , NULL ) ;
if ( V_22 == F_18 ( V_26 -> V_3 ) )
break;
}
return V_23 == V_24 ? - 1 : V_23 ;
}
static int F_19 ( struct V_27 * V_28 )
{
void T_2 * V_29 ;
int V_30 ;
struct V_31 V_32 ;
unsigned int V_33 ;
unsigned int V_34 ;
struct V_18 * V_35 = V_28 -> V_28 . V_36 ;
unsigned int V_37 ;
const unsigned int * V_26 ;
if ( ! V_35 ) {
F_20 ( & V_28 -> V_28 , L_3 ) ;
return - V_38 ;
}
if ( ! V_12 ) {
V_9 = F_16 () ;
F_21 ( & V_28 -> V_28 , L_4 ,
V_9 ) ;
V_12 = F_22 ( sizeof( struct V_1 ) * V_9 ,
V_39 ) ;
if ( ! V_12 ) {
F_20 ( & V_28 -> V_28 ,
L_5 ) ;
return - V_40 ;
}
}
F_21 ( & V_28 -> V_28 , L_6 , V_35 -> V_41 ) ;
F_23 ( V_35 , 0 , & V_32 ) ;
V_29 = F_24 ( V_32 . V_42 , V_32 . V_43 - V_32 . V_42 ) ;
if ( ! V_29 ) {
F_20 ( & V_28 -> V_28 , L_7 ) ;
return - V_38 ;
}
V_30 = F_17 ( V_35 ) ;
if ( V_30 < 0 ) {
F_20 ( & V_28 -> V_28 ,
L_8 ) ;
return - V_10 ;
}
F_21 ( & V_28 -> V_28 , L_9 ,
V_30 ) ;
V_26 = F_25 ( V_35 , L_10 , NULL ) ;
V_37 = ( V_26 ) ? * V_26 : 0xF ;
for ( V_33 = 0 , V_34 = 0 ; V_33 < V_21 ; ++ V_33 ) {
struct V_1 * V_2 ;
unsigned int V_44 ;
V_2 = F_22 ( sizeof( struct V_1 ) , V_39 ) ;
if ( ! V_2 ) {
F_20 ( & V_28 -> V_28 , L_11 ) ;
return - V_40 ;
}
V_44 = V_30 * V_21 + V_33 ;
V_2 -> V_45 = V_29 + V_33 * V_46 ;
V_2 -> V_4 = ( T_1 * ) ( ( V_47 * ) V_2 -> V_45 + V_48 ) ;
V_2 -> V_13 = V_14 ;
V_2 -> V_5 = V_33 ;
F_26 ( & V_2 -> V_16 ) ;
if ( V_37 & ( 1 << V_33 ) ) {
V_2 -> V_49 = F_27 ( V_35 , V_34 ) ;
if ( V_2 -> V_49 == V_50 ) {
F_20 ( & V_28 -> V_28 ,
L_12 ) ;
F_28 ( V_2 ) ;
return - V_38 ;
}
V_34 += 1 ;
} else {
V_2 -> V_49 = V_50 ;
}
V_12 [ V_44 ] = V_2 ;
F_12 ( V_2 ) ;
F_21 ( & V_28 -> V_28 , L_13 ,
V_44 , V_2 -> V_49 ) ;
}
return 0 ;
}
static T_3 int F_29 ( void )
{
return F_30 ( & V_51 ) ;
}
