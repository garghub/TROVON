static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 = V_5 ;
V_3 = F_2 ( V_2 -> V_6 , V_7 ,
V_2 -> V_8 , & V_4 , 1 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_2 ( V_2 -> V_6 , V_9 ,
V_2 -> V_8 , & V_4 , 1 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned long V_10 )
{
T_1 V_4 = F_4 ( V_10 , 1000 ) ;
return F_2 ( V_2 -> V_6 , V_7 ,
V_2 -> V_8 , & V_4 , 1 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned long V_10 )
{
T_1 V_4 = F_4 ( V_10 , 1000 ) ;
return F_2 ( V_2 -> V_6 , V_9 ,
V_2 -> V_8 , & V_4 , 1 ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long * V_11 , unsigned long * V_12 )
{
* V_11 = V_10 ;
if ( V_2 -> V_13 )
* V_12 = 0 ;
else
* V_12 = * V_11 ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_8 ( V_15 ) ;
struct V_1 * V_16 = V_2 -> V_16 ;
unsigned long V_17 = 0 , V_18 = 0 ;
unsigned long V_19 = 0 , V_20 = 0 ;
unsigned long V_21 , V_22 ;
int V_3 = 0 ;
F_9 ( & V_23 ) ;
if ( ! V_2 -> V_10 )
goto V_24;
F_6 ( V_2 , V_2 -> V_10 , & V_17 , & V_18 ) ;
if ( V_16 -> V_25 )
F_6 ( V_16 , V_16 -> V_10 ,
& V_19 , & V_20 ) ;
V_21 = F_10 ( V_17 , V_19 ) ;
if ( V_2 -> V_26 )
V_21 = ! ! V_21 ;
V_3 = F_3 ( V_2 , V_21 ) ;
if ( V_3 )
goto V_24;
V_22 = F_10 ( V_18 , V_20 ) ;
if ( V_2 -> V_26 )
V_22 = ! ! V_22 ;
V_3 = F_5 ( V_2 , V_22 ) ;
if ( V_3 )
V_3 = F_3 ( V_2 , V_19 ) ;
V_24:
if ( ! V_3 )
V_2 -> V_25 = true ;
F_11 ( & V_23 ) ;
return V_3 ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_8 ( V_15 ) ;
struct V_1 * V_16 = V_2 -> V_16 ;
unsigned long V_19 = 0 , V_20 = 0 ;
unsigned long V_21 , V_22 ;
int V_3 ;
F_9 ( & V_23 ) ;
if ( ! V_2 -> V_10 )
goto V_24;
if ( V_16 -> V_25 )
F_6 ( V_16 , V_16 -> V_10 , & V_19 ,
& V_20 ) ;
V_21 = V_2 -> V_26 ? ! ! V_19 : V_19 ;
V_3 = F_3 ( V_2 , V_21 ) ;
if ( V_3 )
goto V_24;
V_22 = V_2 -> V_26 ? ! ! V_20 : V_20 ;
V_3 = F_5 ( V_2 , V_22 ) ;
if ( V_3 )
goto V_24;
V_2 -> V_25 = false ;
V_24:
F_11 ( & V_23 ) ;
}
static int F_13 ( struct V_14 * V_15 ,
unsigned long V_10 , unsigned long V_27 )
{
struct V_1 * V_2 = F_8 ( V_15 ) ;
struct V_1 * V_16 = V_2 -> V_16 ;
unsigned long V_21 , V_22 ;
unsigned long V_17 = 0 , V_18 = 0 ;
unsigned long V_19 = 0 , V_20 = 0 ;
int V_3 = 0 ;
F_9 ( & V_23 ) ;
if ( ! V_2 -> V_25 )
goto V_24;
F_6 ( V_2 , V_10 , & V_17 , & V_18 ) ;
if ( V_16 -> V_25 )
F_6 ( V_16 , V_16 -> V_10 ,
& V_19 , & V_20 ) ;
V_21 = F_10 ( V_17 , V_19 ) ;
V_3 = F_3 ( V_2 , V_21 ) ;
if ( V_3 )
goto V_24;
V_22 = F_10 ( V_18 , V_20 ) ;
V_3 = F_5 ( V_2 , V_22 ) ;
if ( V_3 )
goto V_24;
V_2 -> V_10 = V_10 ;
V_24:
F_11 ( & V_23 ) ;
return V_3 ;
}
static long F_14 ( struct V_14 * V_15 , unsigned long V_10 ,
unsigned long * V_27 )
{
return V_10 ;
}
static unsigned long F_15 ( struct V_14 * V_15 ,
unsigned long V_27 )
{
struct V_1 * V_2 = F_8 ( V_15 ) ;
return V_2 -> V_10 ;
}
static struct V_14 * F_16 ( struct V_28 * V_29 ,
void * V_30 )
{
struct V_31 * V_32 = V_30 ;
unsigned int V_33 = V_29 -> args [ 0 ] ;
if ( V_33 >= V_32 -> V_34 ) {
F_17 ( L_1 , V_35 , V_33 ) ;
return F_18 ( - V_36 ) ;
}
return V_32 -> V_37 [ V_33 ] ? & V_32 -> V_37 [ V_33 ] -> V_15 : F_18 ( - V_38 ) ;
}
static int F_19 ( struct V_39 * V_40 )
{
struct V_31 * V_32 ;
int V_3 ;
T_2 V_34 , V_41 ;
struct V_42 * V_6 ;
struct V_1 * * V_43 ;
const struct V_44 * V_45 ;
V_6 = F_20 ( V_40 -> V_46 . V_47 ) ;
if ( ! V_6 ) {
F_21 ( & V_40 -> V_46 , L_2 ) ;
return - V_48 ;
}
V_45 = F_22 ( & V_40 -> V_46 ) ;
if ( ! V_45 )
return - V_36 ;
V_43 = V_45 -> V_37 ;
V_34 = V_45 -> V_34 ;
V_32 = F_23 ( & V_40 -> V_46 , sizeof( * V_32 ) , V_49 ) ;
if ( ! V_32 )
return - V_50 ;
V_32 -> V_37 = V_43 ;
V_32 -> V_34 = V_34 ;
for ( V_41 = 0 ; V_41 < V_34 ; V_41 ++ ) {
if ( ! V_43 [ V_41 ] )
continue;
V_43 [ V_41 ] -> V_6 = V_6 ;
V_3 = F_1 ( V_43 [ V_41 ] ) ;
if ( V_3 )
goto V_51;
}
for ( V_41 = 0 ; V_41 < V_34 ; V_41 ++ ) {
if ( ! V_43 [ V_41 ] )
continue;
V_3 = F_24 ( & V_40 -> V_46 , & V_43 [ V_41 ] -> V_15 ) ;
if ( V_3 )
goto V_51;
}
V_3 = F_25 ( V_40 -> V_46 . V_52 , F_16 ,
V_32 ) ;
if ( V_3 )
goto V_51;
return 0 ;
V_51:
F_21 ( & V_40 -> V_46 , L_3 , V_3 ) ;
return V_3 ;
}
static int F_26 ( struct V_39 * V_40 )
{
F_27 ( V_40 -> V_46 . V_52 ) ;
return 0 ;
}
static int T_3 F_28 ( void )
{
return F_29 ( & V_53 ) ;
}
static void T_4 F_30 ( void )
{
F_31 ( & V_53 ) ;
}
