static inline void F_1 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
}
static inline T_2 F_3 ( void T_1 * V_1 , T_2 V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
static void F_5 ( struct V_4 * V_5 , T_3 V_6 )
{
unsigned long V_7 = V_8 + F_6 ( 1000 ) ;
unsigned V_2 = 0 ;
V_2 = V_9
| ( F_7 ( V_10 ) << V_11 )
| ( 2 << V_12 )
| ( ( V_6 + 1 ) << V_13 )
| ( 1 << V_14 ) ;
F_1 ( V_5 -> V_15 , V_16 , V_2 ) ;
while ( ( F_3 ( V_5 -> V_15 , V_16 )
& ( 1 << V_14 ) ) ) {
F_8 () ;
if ( F_9 ( V_8 , V_7 ) ) {
F_10 ( V_5 -> V_17 . V_18 ,
L_1 ) ;
break;
}
}
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_19 * V_20 = F_12 ( V_5 ) ;
int V_21 ;
struct V_22 * V_23 ;
V_23 = V_5 -> V_17 . V_18 -> V_24 ;
if ( V_23 -> V_25 ) {
if ( F_13 ( V_23 -> V_26 [ 0 ] ) )
F_14 ( V_23 -> V_26 [ 0 ] , 0 ) ;
if ( F_13 ( V_23 -> V_26 [ 1 ] ) )
F_14 ( V_23 -> V_26 [ 1 ] , 0 ) ;
F_15 ( 10 ) ;
}
if ( V_23 -> V_27 [ 0 ] == V_28 )
F_5 ( V_5 , 0 ) ;
if ( V_23 -> V_27 [ 1 ] == V_28 )
F_5 ( V_5 , 1 ) ;
V_20 -> V_29 = V_5 -> V_15 ;
V_21 = F_16 ( V_5 ) ;
if ( V_23 -> V_25 ) {
F_15 ( 10 ) ;
if ( F_13 ( V_23 -> V_26 [ 0 ] ) )
F_14 ( V_23 -> V_26 [ 0 ] , 1 ) ;
if ( F_13 ( V_23 -> V_26 [ 1 ] ) )
F_14 ( V_23 -> V_26 [ 1 ] , 1 ) ;
}
return V_21 ;
}
static void F_17 (
struct V_22 * V_23 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
if ( V_23 -> V_32 [ V_30 ] ) {
F_18 ( V_23 -> V_32 [ V_30 ] ) ;
F_19 ( V_23 -> V_32 [ V_30 ] ) ;
}
}
}
static int F_20 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = & V_34 -> V_36 ;
struct V_22 * V_23 = V_36 -> V_24 ;
struct V_37 * V_38 ;
struct V_4 * V_5 ;
void T_1 * V_15 ;
int V_39 = - V_40 ;
int V_41 ;
int V_30 ;
char V_42 [ 7 ] ;
if ( F_21 () )
return - V_40 ;
if ( ! V_36 -> V_43 ) {
F_22 ( V_36 , L_2 ) ;
return - V_40 ;
}
V_41 = F_23 ( V_34 , L_3 ) ;
if ( V_41 < 0 ) {
F_22 ( V_36 , L_4 ) ;
return - V_40 ;
}
V_38 = F_24 ( V_34 ,
V_44 , L_5 ) ;
if ( ! V_38 ) {
F_22 ( V_36 , L_6 ) ;
return - V_40 ;
}
V_15 = F_25 ( V_38 -> V_45 , F_26 ( V_38 ) ) ;
if ( ! V_15 ) {
F_22 ( V_36 , L_7 ) ;
return - V_46 ;
}
V_5 = F_27 ( & V_47 , V_36 ,
F_28 ( V_36 ) ) ;
if ( ! V_5 ) {
F_22 ( V_36 , L_8 , V_39 ) ;
V_39 = - V_46 ;
goto V_48;
}
V_5 -> V_49 = V_38 -> V_45 ;
V_5 -> V_50 = F_26 ( V_38 ) ;
V_5 -> V_15 = V_15 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
if ( V_23 -> V_27 [ V_30 ] != V_28 ) {
V_23 -> V_32 [ V_30 ] = NULL ;
continue;
}
snprintf ( V_42 , sizeof( V_42 ) , L_9 , V_30 ) ;
V_23 -> V_32 [ V_30 ] = F_29 ( V_36 , V_42 ) ;
if ( F_30 ( V_23 -> V_32 [ V_30 ] ) ) {
V_23 -> V_32 [ V_30 ] = NULL ;
F_10 ( V_36 ,
L_10 , V_30 ) ;
} else {
F_31 ( V_23 -> V_32 [ V_30 ] ) ;
}
}
F_32 ( V_36 ) ;
F_33 ( V_36 ) ;
F_1 ( V_15 , V_51 ,
V_52 ) ;
V_39 = F_34 ( V_5 , V_41 , V_53 ) ;
if ( V_39 ) {
F_22 ( V_36 , L_11 , V_39 ) ;
goto V_54;
}
return 0 ;
V_54:
F_17 ( V_23 ) ;
F_35 ( V_36 ) ;
F_36 ( V_5 ) ;
V_48:
F_37 ( V_15 ) ;
return V_39 ;
}
static int F_38 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = & V_34 -> V_36 ;
struct V_4 * V_5 = F_39 ( V_36 ) ;
F_40 ( V_5 ) ;
F_17 ( V_36 -> V_24 ) ;
F_37 ( V_5 -> V_15 ) ;
F_36 ( V_5 ) ;
F_35 ( V_36 ) ;
F_41 ( V_36 ) ;
return 0 ;
}
static void F_42 ( struct V_33 * V_34 )
{
struct V_4 * V_5 = F_39 ( & V_34 -> V_36 ) ;
if ( V_5 -> V_55 -> V_56 )
V_5 -> V_55 -> V_56 ( V_5 ) ;
}
