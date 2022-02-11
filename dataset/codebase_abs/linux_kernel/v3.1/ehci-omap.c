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
struct V_7 * V_8 = F_6 ( & V_5 -> V_9 ) ;
unsigned long V_10 = V_11 + F_7 ( 1000 ) ;
unsigned V_2 = 0 ;
V_2 = V_12
| ( F_8 ( V_13 ) << V_14 )
| ( 2 << V_15 )
| ( ( V_6 + 1 ) << V_16 )
| ( 1 << V_17 ) ;
F_1 ( V_8 -> V_18 , V_19 , V_2 ) ;
while ( ( F_3 ( V_8 -> V_18 , V_19 )
& ( 1 << V_17 ) ) ) {
F_9 () ;
if ( F_10 ( V_11 , V_10 ) ) {
F_11 ( & V_5 -> V_9 , L_1 ) ;
break;
}
}
}
static void F_12 (
struct V_20 * V_21 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( V_21 -> V_24 [ V_22 ] ) {
F_13 ( V_21 -> V_24 [ V_22 ] ) ;
F_14 ( V_21 -> V_24 [ V_22 ] ) ;
}
}
}
static int F_15 ( struct V_4 * V_5 )
{
struct V_25 * V_9 = & V_5 -> V_9 ;
struct V_20 * V_21 = V_9 -> V_26 ;
struct V_27 * V_28 ;
struct V_7 * V_8 ;
void T_1 * V_18 ;
struct V_29 * V_30 ;
int V_31 = - V_32 ;
int V_33 ;
int V_22 ;
char V_34 [ 7 ] ;
if ( F_16 () )
return - V_32 ;
if ( ! V_9 -> V_35 ) {
F_17 ( V_9 , L_2 ) ;
return - V_32 ;
}
V_33 = F_18 ( V_5 , L_3 ) ;
if ( V_33 < 0 ) {
F_17 ( V_9 , L_4 ) ;
return - V_32 ;
}
V_28 = F_19 ( V_5 ,
V_36 , L_5 ) ;
if ( ! V_28 ) {
F_17 ( V_9 , L_6 ) ;
return - V_32 ;
}
V_18 = F_20 ( V_28 -> V_37 , F_21 ( V_28 ) ) ;
if ( ! V_18 ) {
F_17 ( V_9 , L_7 ) ;
return - V_38 ;
}
V_8 = F_22 ( & V_39 , V_9 ,
F_23 ( V_9 ) ) ;
if ( ! V_8 ) {
F_17 ( V_9 , L_8 , V_31 ) ;
V_31 = - V_38 ;
goto V_40;
}
V_8 -> V_41 = V_28 -> V_37 ;
V_8 -> V_42 = F_21 ( V_28 ) ;
V_8 -> V_18 = V_18 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
if ( V_21 -> V_43 [ V_22 ] != V_44 ) {
V_21 -> V_24 [ V_22 ] = NULL ;
continue;
}
snprintf ( V_34 , sizeof( V_34 ) , L_9 , V_22 ) ;
V_21 -> V_24 [ V_22 ] = F_24 ( V_9 , V_34 ) ;
if ( F_25 ( V_21 -> V_24 [ V_22 ] ) ) {
V_21 -> V_24 [ V_22 ] = NULL ;
F_11 ( V_9 ,
L_10 , V_22 ) ;
} else {
F_26 ( V_21 -> V_24 [ V_22 ] ) ;
}
}
V_31 = F_27 ( V_9 ) ;
if ( V_31 ) {
F_17 ( V_9 , L_11 , V_31 ) ;
goto V_45;
}
F_1 ( V_18 , V_46 ,
V_47 ) ;
if ( V_21 -> V_43 [ 0 ] == V_44 )
F_5 ( V_5 , 0 ) ;
if ( V_21 -> V_43 [ 1 ] == V_44 )
F_5 ( V_5 , 1 ) ;
V_30 = F_28 ( V_8 ) ;
V_30 -> V_48 = 0x20 ;
V_30 -> V_49 = V_8 -> V_18 ;
V_30 -> V_18 = V_8 -> V_18
+ F_29 ( V_50 , F_30 ( & V_30 -> V_49 -> V_51 ) ) ;
F_31 ( V_30 , L_12 ) ;
F_32 ( V_30 , L_12 ) ;
V_30 -> V_52 = F_30 ( & V_30 -> V_49 -> V_52 ) ;
V_31 = F_33 ( V_8 , V_33 , V_53 | V_54 ) ;
if ( V_31 ) {
F_17 ( V_9 , L_13 , V_31 ) ;
goto V_55;
}
F_34 ( V_30 , 1 ) ;
return 0 ;
V_55:
F_35 ( V_9 ) ;
V_45:
F_12 ( V_21 ) ;
F_36 ( V_8 ) ;
V_40:
F_37 ( V_18 ) ;
return V_31 ;
}
static int F_38 ( struct V_4 * V_5 )
{
struct V_25 * V_9 = & V_5 -> V_9 ;
struct V_7 * V_8 = F_6 ( V_9 ) ;
F_39 ( V_8 ) ;
F_35 ( V_9 ) ;
F_12 ( V_9 -> V_26 ) ;
F_37 ( V_8 -> V_18 ) ;
F_36 ( V_8 ) ;
return 0 ;
}
static void F_40 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_6 ( & V_5 -> V_9 ) ;
if ( V_8 -> V_56 -> V_57 )
V_8 -> V_56 -> V_57 ( V_8 ) ;
}
