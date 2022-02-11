static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = * (struct V_4 * * ) V_3 ;
F_2 ( V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 , void * V_3 , void * V_6 )
{
struct V_4 * * V_5 = V_3 ;
return * V_5 == V_6 ;
}
void F_4 ( struct V_4 * V_5 )
{
if ( ! V_5 || F_5 ( V_5 ) )
return;
F_6 ( V_5 -> V_7 -> V_8 ) ;
F_7 ( & V_5 -> V_2 ) ;
}
struct V_4 * F_8 ( const char * V_9 )
{
int V_10 = - V_11 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_12 V_13 ;
F_9 ( & V_13 , V_14 , NULL , NULL ) ;
while ( ( V_2 = F_10 ( & V_13 ) ) ) {
if ( strcmp ( V_9 , F_11 ( V_2 ) ) )
continue;
V_5 = F_12 ( V_2 ) ;
if ( ! F_13 ( V_5 -> V_7 -> V_8 ) ) {
V_10 = - V_11 ;
goto V_15;
}
F_14 ( & V_13 ) ;
F_15 ( & V_5 -> V_2 ) ;
return V_5 ;
}
V_15:
F_14 ( & V_13 ) ;
return F_16 ( V_10 ) ;
}
void F_17 ( struct V_4 * V_5 )
{
unsigned long V_16 ;
if ( F_5 ( V_5 ) || ! V_5 -> V_7 -> V_17 )
return;
F_18 ( & V_5 -> V_18 , V_16 ) ;
V_5 -> V_7 -> V_17 ( V_5 ) ;
F_19 ( & V_5 -> V_18 , V_16 ) ;
}
int F_20 ( struct V_4 * V_5 )
{
int V_10 ;
unsigned long V_16 ;
if ( F_5 ( V_5 ) )
return - V_11 ;
if ( ! V_5 -> V_7 -> V_19 )
return 0 ;
F_18 ( & V_5 -> V_18 , V_16 ) ;
V_10 = V_5 -> V_7 -> V_19 ( V_5 ) ;
F_19 ( & V_5 -> V_18 , V_16 ) ;
return V_10 ;
}
int F_21 ( struct V_4 * V_5 , enum V_20 type ,
T_1 V_21 )
{
int V_10 ;
unsigned long V_16 ;
if ( F_5 ( V_5 ) )
return - V_11 ;
if ( ! V_5 -> V_7 -> V_22 )
return 0 ;
F_18 ( & V_5 -> V_18 , V_16 ) ;
V_10 = V_5 -> V_7 -> V_22 ( V_5 , type , V_21 ) ;
F_19 ( & V_5 -> V_18 , V_16 ) ;
return V_10 ;
}
int F_22 ( struct V_4 * V_5 )
{
int V_23 ;
unsigned long V_16 ;
if ( F_5 ( V_5 ) )
return 0 ;
if ( ! V_5 -> V_7 -> V_24 )
return 0 ;
F_18 ( & V_5 -> V_18 , V_16 ) ;
V_23 = V_5 -> V_7 -> V_24 ( V_5 ) ;
F_19 ( & V_5 -> V_18 , V_16 ) ;
if ( V_23 < 0 )
return 0 ;
V_23 = 1 << V_23 ;
return V_23 ;
}
int F_23 ( struct V_4 * V_5 , T_1 V_25 )
{
int V_10 ;
T_1 V_26 ;
unsigned long V_16 ;
if ( F_5 ( V_5 ) )
return - V_11 ;
if ( ! V_5 -> V_7 -> V_27 )
return 0 ;
V_26 = F_24 ( V_25 ) ;
F_18 ( & V_5 -> V_18 , V_16 ) ;
V_10 = V_5 -> V_7 -> V_27 ( V_5 , V_26 ) ;
F_19 ( & V_5 -> V_18 , V_16 ) ;
return V_10 ;
}
void F_25 ( struct V_4 * V_5 , T_2 V_28 )
{
unsigned long V_16 ;
if ( F_5 ( V_5 ) )
return;
if ( ! V_5 -> V_7 -> V_29 )
return;
F_18 ( & V_5 -> V_18 , V_16 ) ;
V_5 -> V_7 -> V_29 ( V_5 , V_28 ) ;
F_19 ( & V_5 -> V_18 , V_16 ) ;
}
int F_26 ( struct V_4 * V_5 , T_2 V_28 ,
T_3 V_30 , T_4 V_31 )
{
int V_10 ;
unsigned long V_16 ;
if ( F_5 ( V_5 ) )
return - V_11 ;
if ( ! V_5 -> V_7 -> V_32 )
return 0 ;
F_18 ( & V_5 -> V_18 , V_16 ) ;
V_10 = V_5 -> V_7 -> V_32 ( V_5 , V_28 , V_30 , V_31 ) ;
F_19 ( & V_5 -> V_18 , V_16 ) ;
return V_10 ;
}
void F_27 ( struct V_4 * V_5 , int V_33 )
{
unsigned long V_16 ;
if ( F_5 ( V_5 ) )
return;
if ( ! V_5 -> V_7 -> V_34 )
return;
F_18 ( & V_5 -> V_18 , V_16 ) ;
V_5 -> V_7 -> V_34 ( V_5 , V_33 ) ;
F_19 ( & V_5 -> V_18 , V_16 ) ;
}
int F_28 ( struct V_4 * V_5 , enum V_35 V_33 ,
T_5 V_36 , T_4 V_31 , int V_16 )
{
int V_10 ;
unsigned long V_37 ;
if ( F_5 ( V_5 ) )
return - V_11 ;
if ( ! V_5 -> V_7 -> V_38 )
return 0 ;
F_18 ( & V_5 -> V_18 , V_37 ) ;
V_10 = V_5 -> V_7 -> V_38 ( V_5 , V_33 , V_36 , V_31 , V_16 ) ;
F_19 ( & V_5 -> V_18 , V_37 ) ;
return V_10 ;
}
int F_29 ( struct V_4 * V_5 , struct V_39 * V_40 )
{
int V_10 ;
unsigned long V_16 ;
if ( F_5 ( V_5 ) )
return - V_11 ;
if ( ! V_5 -> V_7 -> V_41 )
return 0 ;
F_18 ( & V_5 -> V_18 , V_16 ) ;
V_10 = V_5 -> V_7 -> V_41 ( V_5 , V_40 ) ;
F_19 ( & V_5 -> V_18 , V_16 ) ;
return V_10 ;
}
int F_30 ( struct V_4 * V_5 , struct V_42 * V_43 )
{
unsigned long V_16 ;
struct V_1 * V_2 = V_5 -> V_2 . V_44 ;
if ( V_43 -> V_5 )
return - V_45 ;
if ( F_5 ( V_5 ) )
return - V_11 ;
if ( V_43 -> V_46 > V_5 -> V_47 - 1 )
return - V_11 ;
V_43 -> V_5 = V_5 ;
if ( V_2 -> V_48 ) {
F_31 ( & V_43 -> V_2 , V_2 -> V_48 ) ;
} else {
F_32 ( & V_43 -> V_2 , V_5 -> V_2 . V_49 ) ;
V_43 -> V_2 . V_50 = V_5 -> V_2 . V_50 ;
}
F_18 ( & V_5 -> V_18 , V_16 ) ;
F_33 ( & V_43 -> V_51 , & V_5 -> V_42 ) ;
F_19 ( & V_5 -> V_18 , V_16 ) ;
return 0 ;
}
void F_34 ( struct V_4 * V_5 , struct V_42 * V_43 )
{
unsigned long V_16 ;
if ( ! V_5 || F_5 ( V_5 ) )
return;
F_18 ( & V_5 -> V_18 , V_16 ) ;
F_35 ( & V_43 -> V_51 ) ;
F_19 ( & V_5 -> V_18 , V_16 ) ;
}
void F_36 ( struct V_4 * V_5 )
{
unsigned long V_16 ;
struct V_42 * V_43 ;
if ( ! V_5 || F_5 ( V_5 ) )
return;
F_18 ( & V_5 -> V_18 , V_16 ) ;
F_37 (epf, &epc->pci_epf, list)
F_38 ( V_43 ) ;
F_19 ( & V_5 -> V_18 , V_16 ) ;
}
void F_2 ( struct V_4 * V_5 )
{
F_39 ( V_5 -> V_52 ) ;
F_40 ( & V_5 -> V_2 ) ;
F_41 ( V_5 ) ;
}
void F_42 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
int V_53 ;
V_53 = F_43 ( V_2 , F_1 , F_3 ,
V_5 ) ;
F_44 ( V_2 , V_53 , L_1 ) ;
}
struct V_4 *
F_45 ( struct V_1 * V_2 , const struct V_54 * V_7 ,
struct V_55 * V_8 )
{
int V_10 ;
struct V_4 * V_5 ;
if ( F_46 ( ! V_2 ) ) {
V_10 = - V_11 ;
goto V_56;
}
V_5 = F_47 ( sizeof( * V_5 ) , V_57 ) ;
if ( ! V_5 ) {
V_10 = - V_58 ;
goto V_56;
}
F_48 ( & V_5 -> V_18 ) ;
F_49 ( & V_5 -> V_42 ) ;
F_50 ( & V_5 -> V_2 ) ;
F_32 ( & V_5 -> V_2 , V_2 -> V_49 ) ;
V_5 -> V_2 . V_59 = V_14 ;
V_5 -> V_2 . V_50 = V_2 -> V_50 ;
V_5 -> V_2 . V_44 = V_2 ;
V_5 -> V_7 = V_7 ;
V_10 = F_51 ( & V_5 -> V_2 , L_2 , F_11 ( V_2 ) ) ;
if ( V_10 )
goto V_60;
V_10 = F_52 ( & V_5 -> V_2 ) ;
if ( V_10 )
goto V_60;
V_5 -> V_52 = F_53 ( F_11 ( V_2 ) ) ;
return V_5 ;
V_60:
F_7 ( & V_5 -> V_2 ) ;
F_41 ( V_5 ) ;
V_56:
return F_16 ( V_10 ) ;
}
struct V_4 *
F_54 ( struct V_1 * V_2 , const struct V_54 * V_7 ,
struct V_55 * V_8 )
{
struct V_4 * * V_61 , * V_5 ;
V_61 = F_55 ( F_1 , sizeof( * V_61 ) , V_57 ) ;
if ( ! V_61 )
return F_16 ( - V_58 ) ;
V_5 = F_45 ( V_2 , V_7 , V_8 ) ;
if ( ! F_5 ( V_5 ) ) {
* V_61 = V_5 ;
F_56 ( V_2 , V_61 ) ;
} else {
F_57 ( V_61 ) ;
}
return V_5 ;
}
static int T_6 F_58 ( void )
{
V_14 = F_59 ( V_62 , L_3 ) ;
if ( F_5 ( V_14 ) ) {
F_60 ( L_4 ,
F_61 ( V_14 ) ) ;
return F_61 ( V_14 ) ;
}
return 0 ;
}
static void T_7 F_62 ( void )
{
F_63 ( V_14 ) ;
}
