static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
if ( ! V_9 -> V_10 )
goto V_11;
if ( F_7 ( ! V_9 -> V_12 ) )
F_8 ( V_9 -> V_2 -> V_13 , L_1 ,
V_9 -> V_14 ) ;
F_9 ( V_9 -> V_2 -> V_13 ) ;
F_1 ( V_9 -> V_2 , F_10 ( V_9 -> V_14 ) ,
V_9 -> V_15 - 1 ) ;
F_1 ( V_9 -> V_2 , F_11 ( V_9 -> V_14 ) , V_16 ) ;
V_11:
V_9 -> V_17 = true ;
return 0 ;
}
static void F_12 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
if ( ! V_9 -> V_10 )
goto V_11;
F_1 ( V_9 -> V_2 , F_11 ( V_9 -> V_14 ) , 0 ) ;
F_13 ( V_9 -> V_2 -> V_13 ) ;
V_11:
V_9 -> V_17 = false ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
return V_9 -> V_17 ;
}
static unsigned long F_15 ( struct V_6 * V_7 ,
unsigned long V_18 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
return V_18 / V_9 -> V_15 ;
}
static long F_16 ( struct V_6 * V_7 , unsigned long V_19 ,
unsigned long * V_18 )
{
unsigned V_15 ;
V_15 = ( * V_18 + V_19 / 2 ) / V_19 ;
if ( V_15 > V_20 + 1 )
V_15 = V_20 + 1 ;
return * V_18 / V_15 ;
}
static int F_17 ( struct V_6 * V_7 , unsigned long V_19 ,
unsigned long V_18 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
T_1 V_15 ;
V_15 = ( ( V_18 + V_19 / 2 ) / V_19 ) - 1 ;
if ( V_15 > V_20 )
V_15 = V_20 ;
V_9 -> V_15 = V_15 + 1 ;
return 0 ;
}
static void T_2 F_18 ( struct V_21 * V_22 )
{
struct V_8 * V_6 = NULL ;
struct V_23 V_24 = { 0 } ;
const char * * V_25 = NULL ;
struct V_26 * V_26 ;
V_6 = F_19 ( sizeof( * V_6 ) , V_27 ) ;
if ( ! V_6 ) {
F_20 ( L_2 , V_28 ) ;
return;
}
V_6 -> V_7 . V_24 = & V_24 ;
V_6 -> V_15 = 1 ;
V_24 . V_29 = V_22 -> V_29 ;
V_24 . V_30 = & V_31 ;
V_24 . V_32 = V_33 ;
V_24 . V_34 = F_21 ( V_22 ) ;
if ( V_24 . V_34 != 1 ) {
F_20 ( L_3 , V_28 ,
V_22 -> V_29 ) ;
goto V_35;
}
V_25 = F_19 ( sizeof( char * ) , V_27 ) ;
if ( ! V_25 )
goto V_35;
V_25 [ 0 ] = F_22 ( V_22 , 0 ) ;
V_24 . V_25 = V_25 ;
V_26 = F_23 ( NULL , & V_6 -> V_7 ) ;
if ( ! F_24 ( V_26 ) ) {
F_25 ( V_22 , V_36 , V_26 ) ;
return;
}
V_35:
F_26 ( V_25 ) ;
F_26 ( V_6 ) ;
}
static int F_27 ( struct V_37 * V_38 )
{
struct V_21 * V_22 = V_38 -> V_13 . V_39 ;
struct V_1 * V_2 ;
int V_40 ;
int V_41 = 0 ;
if ( ! V_22 )
return - V_42 ;
V_2 = F_28 ( & V_38 -> V_13 , sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return - V_43 ;
V_2 -> V_5 = F_29 ( V_22 , 0 ) ;
V_2 -> V_13 = & V_38 -> V_13 ;
F_30 ( V_2 -> V_13 ) ;
F_9 ( V_2 -> V_13 ) ;
F_1 ( V_2 , F_31 ( 0 ) , V_44 ) ;
for ( V_40 = 0 ; V_40 < V_45 ; V_40 ++ ) {
struct V_21 * V_46 ;
char V_47 [ 5 ] ;
struct V_8 * V_9 ;
struct V_48 V_49 ;
struct V_26 * V_26 ;
int V_50 ;
V_50 = F_32 ( V_22 , L_4 ,
NULL , V_40 , & V_49 ) ;
if ( V_50 ) {
F_20 ( L_5 , V_28 ,
V_40 ) ;
return - V_51 ;
}
V_26 = F_33 ( & V_49 ) ;
V_9 = F_6 ( F_34 ( V_26 ) ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_14 = V_40 ;
snprintf ( V_47 , sizeof( V_47 ) , L_6 , V_40 ) ;
V_46 = F_35 ( V_22 , V_47 ) ;
if ( V_46 ) {
V_41 = F_36 ( V_46 , L_7 ,
& V_9 -> V_52 ) ;
V_41 |= F_36 ( V_46 , L_8 ,
& V_9 -> V_53 ) ;
if ( ! V_41 ) {
V_9 -> V_12 = true ;
F_1 ( V_2 , F_37 ( V_40 ) ,
V_9 -> V_52 ) ;
F_1 ( V_2 , F_38 ( V_40 ) ,
V_9 -> V_53 ) ;
}
}
V_9 -> V_10 = true ;
if ( V_9 -> V_17 )
F_5 ( F_34 ( V_26 ) ) ;
}
F_13 ( V_2 -> V_13 ) ;
return V_41 ;
}
static int F_39 ( struct V_37 * V_38 )
{
F_40 ( & V_38 -> V_13 ) ;
return 0 ;
}
