static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_7 ;
V_7 = F_3 ( V_6 , V_8 ) ;
F_4 ( V_7 , V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_7 ;
int V_9 ;
V_9 = F_6 ( V_4 , & V_7 ) ;
if ( V_9 == 0 )
F_7 ( V_6 , V_8 , V_7 ) ;
return V_9 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_9 ( & V_6 -> V_12 ) ;
F_4 ( V_6 -> V_13 , & V_11 -> time ) ;
V_11 -> V_14 = F_3 ( V_6 , V_15 ) & F_10 ( V_16 ) ? 1 : 0 ;
V_11 -> V_17 = F_3 ( V_6 , V_18 ) & F_10 ( V_19 ) ? 1 : 0 ;
F_11 ( & V_6 -> V_12 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_20 ;
unsigned long V_21 ;
int V_9 ;
V_20 = F_3 ( V_6 , V_8 ) ;
V_9 = F_6 ( & V_11 -> time , & V_21 ) ;
if ( V_9 )
return V_9 ;
if ( V_21 < V_20 )
return - V_22 ;
F_9 ( & V_6 -> V_12 ) ;
V_6 -> V_13 = V_21 ;
F_7 ( V_6 , V_23 , V_6 -> V_13 ) ;
if ( V_11 -> V_14 )
F_7 ( V_6 , V_24 , F_3 ( V_6 , V_24 )
| F_10 ( V_25 ) ) ;
else
F_7 ( V_6 , V_24 , F_3 ( V_6 , V_24 )
& ~ F_10 ( V_25 ) ) ;
F_11 ( & V_6 -> V_12 ) ;
return V_9 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_9 = 0 ;
F_9 ( & V_6 -> V_12 ) ;
if( V_14 ) {
if ( F_3 ( V_6 , V_8 ) > V_6 -> V_13 ) {
V_9 = - V_22 ;
goto V_26;
}
F_7 ( V_6 , V_24 , F_3 ( V_6 , V_24 )
| F_10 ( V_25 ) ) ;
F_7 ( V_6 , V_27 , F_10 ( V_28 ) ) ;
F_7 ( V_6 , V_29 , F_10 ( V_30 ) ) ;
} else {
F_7 ( V_6 , V_24 , F_3 ( V_6 , V_24 )
& ~ F_10 ( V_25 ) ) ;
F_7 ( V_6 , V_31 , F_10 ( V_32 ) ) ;
F_7 ( V_6 , V_27 , F_10 ( V_28 ) ) ;
}
V_26:
F_11 ( & V_6 -> V_12 ) ;
return V_9 ;
}
static T_1 F_14 ( int V_33 , void * V_34 )
{
struct V_5 * V_6 = (struct V_5 * ) V_34 ;
unsigned long V_35 = F_3 ( V_6 , V_18 ) ;
unsigned long V_36 = 0 ;
int V_9 = V_37 ;
F_15 ( & V_6 -> V_12 ) ;
if ( V_35 & F_10 ( V_19 ) ) {
F_7 ( V_6 , V_27 , F_10 ( V_28 ) ) ;
F_7 ( V_6 , V_31 , F_10 ( V_32 ) ) ;
F_7 ( V_6 , V_24 , F_3 ( V_6 , V_24 )
& ~ F_10 ( V_25 ) ) ;
F_7 ( V_6 , V_8 , V_6 -> V_13 ) ;
V_36 = V_38 | V_39 ;
F_16 ( V_6 -> V_6 , 1 , V_36 ) ;
V_9 = V_40 ;
}
F_17 ( & V_6 -> V_12 ) ;
return V_9 ;
}
static int T_2 F_18 ( struct V_41 * V_42 )
{
struct V_43 * V_44 ;
struct V_5 * V_6 ;
int V_33 ;
int V_9 ;
V_6 = F_19 ( sizeof( struct V_5 ) , V_45 ) ;
if ( ! V_6 ) {
F_20 ( & V_42 -> V_2 , L_1 ) ;
return - V_46 ;
}
V_44 = F_21 ( V_42 , V_47 , 0 ) ;
if ( ! V_44 ) {
F_20 ( & V_42 -> V_2 , L_2 ) ;
V_9 = - V_48 ;
goto V_26;
}
V_33 = F_22 ( V_42 , 0 ) ;
if ( V_33 <= 0 ) {
F_20 ( & V_42 -> V_2 , L_3 ) ;
V_9 = - V_48 ;
goto V_26;
}
V_6 -> V_33 = V_33 ;
V_6 -> V_44 = F_23 ( V_44 -> V_49 , F_24 ( V_44 ) ) ;
if ( ! V_6 -> V_44 ) {
V_9 = - V_46 ;
F_20 ( & V_42 -> V_2 , L_4 ) ;
goto V_26;
}
F_25 ( & V_6 -> V_12 ) ;
if ( ! ( F_3 ( V_6 , V_24 ) & F_10 ( V_50 ) ) ) {
F_7 ( V_6 , V_24 , F_10 ( V_51 ) ) ;
F_7 ( V_6 , V_31 , F_10 ( V_32 ) ) ;
F_7 ( V_6 , V_24 , F_26 ( V_52 , 0xe )
| F_10 ( V_50 ) ) ;
}
V_9 = F_27 ( V_33 , F_14 , V_53 , L_5 , V_6 ) ;
if ( V_9 ) {
F_20 ( & V_42 -> V_2 , L_6 , V_33 ) ;
goto V_54;
}
F_28 ( V_42 , V_6 ) ;
V_6 -> V_6 = F_29 ( V_42 -> V_55 , & V_42 -> V_2 ,
& V_56 , V_57 ) ;
if ( F_30 ( V_6 -> V_6 ) ) {
F_20 ( & V_42 -> V_2 , L_7 ) ;
V_9 = F_31 ( V_6 -> V_6 ) ;
goto V_58;
}
F_32 ( & V_42 -> V_2 , 1 ) ;
F_33 ( & V_42 -> V_2 , L_8 ,
( unsigned long ) V_6 -> V_44 , V_6 -> V_33 ) ;
return 0 ;
V_58:
F_28 ( V_42 , NULL ) ;
F_34 ( V_33 , V_6 ) ;
V_54:
F_35 ( V_6 -> V_44 ) ;
V_26:
F_36 ( V_6 ) ;
return V_9 ;
}
static int T_3 F_37 ( struct V_41 * V_42 )
{
struct V_5 * V_6 = F_38 ( V_42 ) ;
F_32 ( & V_42 -> V_2 , 0 ) ;
F_34 ( V_6 -> V_33 , V_6 ) ;
F_35 ( V_6 -> V_44 ) ;
F_39 ( V_6 -> V_6 ) ;
F_36 ( V_6 ) ;
F_28 ( V_42 , NULL ) ;
return 0 ;
}
static int T_2 F_40 ( void )
{
return F_41 ( & V_59 , F_18 ) ;
}
static void T_3 F_42 ( void )
{
F_43 ( & V_59 ) ;
}
