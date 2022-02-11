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
static int F_12 ( struct V_4 * V_5 )
{
struct V_20 * V_9 = & V_5 -> V_9 ;
struct V_21 * V_22 = V_9 -> V_23 ;
struct V_24 * V_25 ;
struct V_7 * V_8 ;
void T_1 * V_18 ;
struct V_26 * V_27 ;
int V_28 = - V_29 ;
int V_30 ;
int V_31 ;
char V_32 [ 7 ] ;
if ( F_13 () )
return - V_29 ;
if ( ! V_9 -> V_33 ) {
F_14 ( V_9 , L_2 ) ;
return - V_29 ;
}
V_30 = F_15 ( V_5 , L_3 ) ;
if ( V_30 < 0 ) {
F_14 ( V_9 , L_4 ) ;
return - V_29 ;
}
V_25 = F_16 ( V_5 ,
V_34 , L_5 ) ;
if ( ! V_25 ) {
F_14 ( V_9 , L_6 ) ;
return - V_29 ;
}
V_18 = F_17 ( V_25 -> V_35 , F_18 ( V_25 ) ) ;
if ( ! V_18 ) {
F_14 ( V_9 , L_7 ) ;
return - V_36 ;
}
V_8 = F_19 ( & V_37 , V_9 ,
F_20 ( V_9 ) ) ;
if ( ! V_8 ) {
F_14 ( V_9 , L_8 , V_28 ) ;
V_28 = - V_36 ;
goto V_38;
}
V_8 -> V_39 = V_25 -> V_35 ;
V_8 -> V_40 = F_18 ( V_25 ) ;
V_8 -> V_18 = V_18 ;
for ( V_31 = 0 ; V_31 < V_41 ; V_31 ++ ) {
if ( V_22 -> V_42 [ V_31 ] != V_43 ) {
V_22 -> V_44 [ V_31 ] = NULL ;
continue;
}
snprintf ( V_32 , sizeof( V_32 ) , L_9 , V_31 ) ;
V_22 -> V_44 [ V_31 ] = F_21 ( V_9 , V_32 ) ;
if ( F_22 ( V_22 -> V_44 [ V_31 ] ) ) {
V_22 -> V_44 [ V_31 ] = NULL ;
F_11 ( V_9 ,
L_10 , V_31 ) ;
} else {
F_23 ( V_22 -> V_44 [ V_31 ] ) ;
}
}
V_28 = F_24 ( V_9 ) ;
if ( V_28 ) {
F_14 ( V_9 , L_11 , V_28 ) ;
goto V_45;
}
F_1 ( V_18 , V_46 ,
V_47 ) ;
if ( V_22 -> V_42 [ 0 ] == V_43 )
F_5 ( V_5 , 0 ) ;
if ( V_22 -> V_42 [ 1 ] == V_43 )
F_5 ( V_5 , 1 ) ;
V_27 = F_25 ( V_8 ) ;
V_27 -> V_48 = 0x20 ;
V_27 -> V_49 = V_8 -> V_18 ;
V_27 -> V_18 = V_8 -> V_18
+ F_26 ( V_50 , F_27 ( & V_27 -> V_49 -> V_51 ) ) ;
F_28 ( V_27 , L_12 ) ;
F_29 ( V_27 , L_12 ) ;
V_27 -> V_52 = F_27 ( & V_27 -> V_49 -> V_52 ) ;
V_28 = F_30 ( V_8 , V_30 , V_53 | V_54 ) ;
if ( V_28 ) {
F_14 ( V_9 , L_13 , V_28 ) ;
goto V_55;
}
F_31 ( V_27 , 1 ) ;
return 0 ;
V_55:
F_32 ( V_9 ) ;
V_45:
F_33 ( V_8 ) ;
V_38:
return V_28 ;
}
static int F_34 ( struct V_4 * V_5 )
{
struct V_20 * V_9 = & V_5 -> V_9 ;
struct V_7 * V_8 = F_6 ( V_9 ) ;
F_35 ( V_8 ) ;
F_32 ( V_9 ) ;
F_33 ( V_8 ) ;
return 0 ;
}
static void F_36 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_6 ( & V_5 -> V_9 ) ;
if ( V_8 -> V_56 -> V_57 )
V_8 -> V_56 -> V_57 ( V_8 ) ;
}
