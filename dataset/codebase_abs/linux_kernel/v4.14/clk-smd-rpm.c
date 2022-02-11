static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 V_5 = {
. V_6 = F_2 ( V_2 -> V_7 ) ,
. V_8 = F_2 ( sizeof( V_9 ) ) ,
. V_10 = F_2 ( V_2 -> V_11 ? 1 : V_12 ) ,
} ;
V_3 = F_3 ( V_2 -> V_13 , V_14 ,
V_2 -> V_15 , V_2 -> V_16 , & V_5 ,
sizeof( V_5 ) ) ;
if ( V_3 )
return V_3 ;
V_3 = F_3 ( V_2 -> V_13 , V_17 ,
V_2 -> V_15 , V_2 -> V_16 , & V_5 ,
sizeof( V_5 ) ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned long V_18 )
{
struct V_4 V_5 = {
. V_6 = F_2 ( V_2 -> V_7 ) ,
. V_8 = F_2 ( sizeof( V_9 ) ) ,
. V_10 = F_2 ( F_5 ( V_18 , 1000 ) ) ,
} ;
return F_3 ( V_2 -> V_13 , V_14 ,
V_2 -> V_15 , V_2 -> V_16 , & V_5 ,
sizeof( V_5 ) ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned long V_18 )
{
struct V_4 V_5 = {
. V_6 = F_2 ( V_2 -> V_7 ) ,
. V_8 = F_2 ( sizeof( V_9 ) ) ,
. V_10 = F_2 ( F_5 ( V_18 , 1000 ) ) ,
} ;
return F_3 ( V_2 -> V_13 , V_17 ,
V_2 -> V_15 , V_2 -> V_16 , & V_5 ,
sizeof( V_5 ) ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned long V_18 ,
unsigned long * V_19 , unsigned long * V_20 )
{
* V_19 = V_18 ;
if ( V_2 -> V_21 )
* V_20 = 0 ;
else
* V_20 = * V_19 ;
}
static int F_8 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
struct V_1 * V_24 = V_2 -> V_24 ;
unsigned long V_25 = 0 , V_26 = 0 ;
unsigned long V_27 = 0 , V_28 = 0 ;
unsigned long V_29 , V_30 ;
int V_3 = 0 ;
F_10 ( & V_31 ) ;
if ( ! V_2 -> V_18 )
goto V_32;
F_7 ( V_2 , V_2 -> V_18 , & V_25 , & V_26 ) ;
if ( V_24 -> V_33 )
F_7 ( V_24 , V_24 -> V_18 ,
& V_27 , & V_28 ) ;
V_29 = F_11 ( V_25 , V_27 ) ;
if ( V_2 -> V_11 )
V_29 = ! ! V_29 ;
V_3 = F_4 ( V_2 , V_29 ) ;
if ( V_3 )
goto V_32;
V_30 = F_11 ( V_26 , V_28 ) ;
if ( V_2 -> V_11 )
V_30 = ! ! V_30 ;
V_3 = F_6 ( V_2 , V_30 ) ;
if ( V_3 )
V_3 = F_4 ( V_2 , V_27 ) ;
V_32:
if ( ! V_3 )
V_2 -> V_33 = true ;
F_12 ( & V_31 ) ;
return V_3 ;
}
static void F_13 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
struct V_1 * V_24 = V_2 -> V_24 ;
unsigned long V_27 = 0 , V_28 = 0 ;
unsigned long V_29 , V_30 ;
int V_3 ;
F_10 ( & V_31 ) ;
if ( ! V_2 -> V_18 )
goto V_32;
if ( V_24 -> V_33 )
F_7 ( V_24 , V_24 -> V_18 , & V_27 ,
& V_28 ) ;
V_29 = V_2 -> V_11 ? ! ! V_27 : V_27 ;
V_3 = F_4 ( V_2 , V_29 ) ;
if ( V_3 )
goto V_32;
V_30 = V_2 -> V_11 ? ! ! V_28 : V_28 ;
V_3 = F_6 ( V_2 , V_30 ) ;
if ( V_3 )
goto V_32;
V_2 -> V_33 = false ;
V_32:
F_12 ( & V_31 ) ;
}
static int F_14 ( struct V_22 * V_23 , unsigned long V_18 ,
unsigned long V_34 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
struct V_1 * V_24 = V_2 -> V_24 ;
unsigned long V_29 , V_30 ;
unsigned long V_25 = 0 , V_26 = 0 ;
unsigned long V_27 = 0 , V_28 = 0 ;
int V_3 = 0 ;
F_10 ( & V_31 ) ;
if ( ! V_2 -> V_33 )
goto V_32;
F_7 ( V_2 , V_18 , & V_25 , & V_26 ) ;
if ( V_24 -> V_33 )
F_7 ( V_24 , V_24 -> V_18 ,
& V_27 , & V_28 ) ;
V_29 = F_11 ( V_25 , V_27 ) ;
V_3 = F_4 ( V_2 , V_29 ) ;
if ( V_3 )
goto V_32;
V_30 = F_11 ( V_26 , V_28 ) ;
V_3 = F_6 ( V_2 , V_30 ) ;
if ( V_3 )
goto V_32;
V_2 -> V_18 = V_18 ;
V_32:
F_12 ( & V_31 ) ;
return V_3 ;
}
static long F_15 ( struct V_22 * V_23 , unsigned long V_18 ,
unsigned long * V_34 )
{
return V_18 ;
}
static unsigned long F_16 ( struct V_22 * V_23 ,
unsigned long V_34 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
return V_2 -> V_18 ;
}
static int F_17 ( struct V_35 * V_13 )
{
int V_3 ;
struct V_4 V_5 = {
. V_6 = F_2 ( V_36 ) ,
. V_8 = F_2 ( sizeof( V_9 ) ) ,
. V_10 = F_2 ( 1 ) ,
} ;
V_3 = F_3 ( V_13 , V_17 ,
V_37 ,
V_38 , & V_5 , sizeof( V_5 ) ) ;
if ( V_3 ) {
F_18 ( L_1 ) ;
return V_3 ;
}
V_3 = F_3 ( V_13 , V_14 ,
V_37 ,
V_38 , & V_5 , sizeof( V_5 ) ) ;
if ( V_3 ) {
F_18 ( L_2 ) ;
return V_3 ;
}
F_19 ( L_3 , V_39 ) ;
return 0 ;
}
static struct V_22 * F_20 ( struct V_40 * V_41 ,
void * V_42 )
{
struct V_43 * V_44 = V_42 ;
unsigned int V_45 = V_41 -> args [ 0 ] ;
if ( V_45 >= V_44 -> V_46 ) {
F_18 ( L_4 , V_39 , V_45 ) ;
return F_21 ( - V_47 ) ;
}
return V_44 -> V_48 [ V_45 ] ? & V_44 -> V_48 [ V_45 ] -> V_23 : F_21 ( - V_49 ) ;
}
static int F_22 ( struct V_50 * V_51 )
{
struct V_43 * V_44 ;
int V_3 ;
T_1 V_46 , V_52 ;
struct V_35 * V_13 ;
struct V_1 * * V_53 ;
const struct V_54 * V_55 ;
V_13 = F_23 ( V_51 -> V_56 . V_57 ) ;
if ( ! V_13 ) {
F_24 ( & V_51 -> V_56 , L_5 ) ;
return - V_58 ;
}
V_55 = F_25 ( & V_51 -> V_56 ) ;
if ( ! V_55 )
return - V_47 ;
V_53 = V_55 -> V_48 ;
V_46 = V_55 -> V_46 ;
V_44 = F_26 ( & V_51 -> V_56 , sizeof( * V_44 ) , V_59 ) ;
if ( ! V_44 )
return - V_60 ;
V_44 -> V_48 = V_53 ;
V_44 -> V_46 = V_46 ;
for ( V_52 = 0 ; V_52 < V_46 ; V_52 ++ ) {
if ( ! V_53 [ V_52 ] )
continue;
V_53 [ V_52 ] -> V_13 = V_13 ;
V_3 = F_1 ( V_53 [ V_52 ] ) ;
if ( V_3 )
goto V_61;
}
V_3 = F_17 ( V_13 ) ;
if ( V_3 )
goto V_61;
for ( V_52 = 0 ; V_52 < V_46 ; V_52 ++ ) {
if ( ! V_53 [ V_52 ] )
continue;
V_3 = F_27 ( & V_51 -> V_56 , & V_53 [ V_52 ] -> V_23 ) ;
if ( V_3 )
goto V_61;
}
V_3 = F_28 ( V_51 -> V_56 . V_62 , F_20 ,
V_44 ) ;
if ( V_3 )
goto V_61;
return 0 ;
V_61:
F_24 ( & V_51 -> V_56 , L_6 , V_3 ) ;
return V_3 ;
}
static int F_29 ( struct V_50 * V_51 )
{
F_30 ( V_51 -> V_56 . V_62 ) ;
return 0 ;
}
static int T_2 F_31 ( void )
{
return F_32 ( & V_63 ) ;
}
static void T_3 F_33 ( void )
{
F_34 ( & V_63 ) ;
}
