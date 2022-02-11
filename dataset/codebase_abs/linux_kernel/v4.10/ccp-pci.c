static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_9 V_9 [ V_10 ] ;
unsigned int V_11 = sizeof( V_3 -> V_12 [ 0 ] . V_13 ) - 1 ;
int V_14 , V_15 ;
for ( V_14 = 0 ; V_14 < F_3 ( V_9 ) ; V_14 ++ )
V_9 [ V_14 ] . V_16 = V_14 ;
V_15 = F_4 ( V_8 , V_9 , 1 , V_14 ) ;
if ( V_15 < 0 )
return V_15 ;
V_3 -> V_17 = V_15 ;
for ( V_14 = 0 ; V_14 < V_3 -> V_17 ; V_14 ++ ) {
snprintf ( V_3 -> V_12 [ V_14 ] . V_13 , V_11 , L_1 ,
V_2 -> V_13 , V_14 ) ;
V_3 -> V_12 [ V_14 ] . V_18 = V_9 [ V_14 ] . V_18 ;
V_15 = F_5 ( V_3 -> V_12 [ V_14 ] . V_18 ,
V_2 -> V_19 -> V_20 -> V_21 ,
0 , V_3 -> V_12 [ V_14 ] . V_13 , V_6 ) ;
if ( V_15 ) {
F_6 ( V_6 , L_2 ,
V_15 ) ;
goto V_22;
}
}
return 0 ;
V_22:
while ( V_14 -- )
F_7 ( V_3 -> V_12 [ V_14 ] . V_18 , V_6 ) ;
F_8 ( V_8 ) ;
V_3 -> V_17 = 0 ;
return V_15 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
int V_15 ;
V_15 = F_10 ( V_8 ) ;
if ( V_15 )
return V_15 ;
V_2 -> V_23 = V_8 -> V_23 ;
V_15 = F_5 ( V_2 -> V_23 , V_2 -> V_19 -> V_20 -> V_21 , 0 ,
V_2 -> V_13 , V_6 ) ;
if ( V_15 ) {
F_6 ( V_6 , L_3 , V_15 ) ;
goto V_24;
}
return 0 ;
V_24:
F_11 ( V_8 ) ;
return V_15 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_15 ;
V_15 = F_1 ( V_2 ) ;
if ( ! V_15 )
return 0 ;
F_6 ( V_6 , L_4 , V_15 ) ;
V_15 = F_9 ( V_2 ) ;
if ( ! V_15 )
return 0 ;
F_6 ( V_6 , L_5 , V_15 ) ;
return V_15 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
if ( V_3 -> V_17 ) {
while ( V_3 -> V_17 -- )
F_7 ( V_3 -> V_12 [ V_3 -> V_17 ] . V_18 ,
V_6 ) ;
F_8 ( V_8 ) ;
} else if ( V_2 -> V_23 ) {
F_7 ( V_2 -> V_23 , V_6 ) ;
F_11 ( V_8 ) ;
}
V_2 -> V_23 = 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
T_1 V_25 ;
unsigned long V_26 ;
V_26 = F_15 ( V_8 , V_2 -> V_19 -> V_27 ) ;
V_25 = F_16 ( V_8 , V_2 -> V_19 -> V_27 ) ;
if ( ( V_26 & V_28 ) &&
( V_25 >= ( V_2 -> V_19 -> V_29 + 0x800 ) ) )
return V_2 -> V_19 -> V_27 ;
return - V_30 ;
}
static int F_17 ( struct V_7 * V_8 , const struct V_31 * V_32 )
{
struct V_1 * V_2 ;
struct V_3 * V_3 ;
struct V_5 * V_6 = & V_8 -> V_6 ;
unsigned int V_27 ;
int V_15 ;
V_15 = - V_33 ;
V_2 = F_18 ( V_6 ) ;
if ( ! V_2 )
goto V_34;
V_3 = F_19 ( V_6 , sizeof( * V_3 ) , V_35 ) ;
if ( ! V_3 )
goto V_34;
V_2 -> V_4 = V_3 ;
V_2 -> V_19 = (struct V_36 * ) V_32 -> V_37 ;
if ( ! V_2 -> V_19 || ! V_2 -> V_19 -> V_38 ) {
V_15 = - V_39 ;
F_20 ( V_6 , L_6 ) ;
goto V_34;
}
V_2 -> V_40 = F_12 ;
V_2 -> F_7 = F_13 ;
V_15 = F_21 ( V_8 , L_7 ) ;
if ( V_15 ) {
F_20 ( V_6 , L_8 , V_15 ) ;
goto V_34;
}
V_15 = F_22 ( V_8 ) ;
if ( V_15 ) {
F_20 ( V_6 , L_9 , V_15 ) ;
goto V_41;
}
F_23 ( V_8 ) ;
V_15 = F_14 ( V_2 ) ;
if ( V_15 < 0 )
goto V_42;
V_27 = V_15 ;
V_15 = - V_30 ;
V_2 -> V_43 = F_24 ( V_8 , V_27 , 0 ) ;
if ( ! V_2 -> V_43 ) {
F_20 ( V_6 , L_10 ) ;
goto V_42;
}
V_2 -> V_44 = V_2 -> V_43 + V_2 -> V_19 -> V_29 ;
V_15 = F_25 ( V_6 , F_26 ( 48 ) ) ;
if ( V_15 ) {
V_15 = F_25 ( V_6 , F_26 ( 32 ) ) ;
if ( V_15 ) {
F_20 ( V_6 , L_11 ,
V_15 ) ;
goto V_45;
}
}
F_27 ( V_6 , V_2 ) ;
if ( V_2 -> V_19 -> V_46 )
V_2 -> V_19 -> V_46 ( V_2 ) ;
V_15 = V_2 -> V_19 -> V_20 -> V_47 ( V_2 ) ;
if ( V_15 )
goto V_45;
F_6 ( V_6 , L_12 ) ;
return 0 ;
V_45:
F_28 ( V_8 , V_2 -> V_43 ) ;
V_42:
F_29 ( V_8 ) ;
V_41:
F_30 ( V_8 ) ;
V_34:
F_6 ( V_6 , L_13 ) ;
return V_15 ;
}
static void F_31 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_1 * V_2 = F_32 ( V_6 ) ;
if ( ! V_2 )
return;
V_2 -> V_19 -> V_20 -> V_48 ( V_2 ) ;
F_28 ( V_8 , V_2 -> V_43 ) ;
F_29 ( V_8 ) ;
F_30 ( V_8 ) ;
F_6 ( V_6 , L_14 ) ;
}
static int F_33 ( struct V_7 * V_8 , T_2 V_49 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_1 * V_2 = F_32 ( V_6 ) ;
unsigned long V_50 ;
unsigned int V_51 ;
F_34 ( & V_2 -> V_52 , V_50 ) ;
V_2 -> V_53 = 1 ;
for ( V_51 = 0 ; V_51 < V_2 -> V_54 ; V_51 ++ )
F_35 ( V_2 -> V_55 [ V_51 ] . V_56 ) ;
F_36 ( & V_2 -> V_52 , V_50 ) ;
while ( ! F_37 ( V_2 ) )
F_38 ( V_2 -> V_57 ,
F_37 ( V_2 ) ) ;
return 0 ;
}
static int F_39 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_1 * V_2 = F_32 ( V_6 ) ;
unsigned long V_50 ;
unsigned int V_51 ;
F_34 ( & V_2 -> V_52 , V_50 ) ;
V_2 -> V_53 = 0 ;
for ( V_51 = 0 ; V_51 < V_2 -> V_54 ; V_51 ++ ) {
V_2 -> V_55 [ V_51 ] . V_58 = 0 ;
F_35 ( V_2 -> V_55 [ V_51 ] . V_56 ) ;
}
F_36 ( & V_2 -> V_52 , V_50 ) ;
return 0 ;
}
int F_40 ( void )
{
return F_41 ( & V_59 ) ;
}
void F_42 ( void )
{
F_43 ( & V_59 ) ;
}
