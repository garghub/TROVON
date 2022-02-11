static inline int F_1 ( struct V_1 * V_2 )
{
return ! ( V_2 -> V_3 == V_4 &&
V_2 -> V_5 == V_6 &&
F_2 ( V_2 -> V_7 ) == 0 &&
F_2 ( V_2 -> V_8 ) == 0 ) ;
}
static int F_3 ( struct V_9 * V_10 , T_1 V_11 , struct V_1 * V_2 )
{
T_1 V_12 = V_11 * V_13 + V_10 -> V_14 ;
int V_15 ;
V_15 = F_4 ( V_16 , V_17 , V_12 ++ , & V_2 -> V_7 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_4 ( V_16 , V_17 , V_12 ++ , & V_2 -> V_8 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_4 ( V_16 , V_17 , V_12 ++ , & V_2 -> V_3 ) ;
if ( V_15 )
return V_15 ;
return F_4 ( V_16 , V_17 , V_12 ++ , & V_2 -> V_5 ) ;
}
static int F_5 ( struct V_9 * V_10 , T_1 V_11 , struct V_1 * V_2 )
{
unsigned long V_18 ;
T_1 V_12 = V_11 * V_13 + V_10 -> V_14 ;
int V_15 ;
F_6 ( V_18 ) ;
V_15 = F_7 ( V_16 , V_19 , V_12 ++ , V_2 -> V_7 ) ;
if ( V_15 )
goto V_20;
V_15 = F_7 ( V_16 , V_19 , V_12 ++ , V_2 -> V_8 ) ;
if ( V_15 )
goto V_20;
V_15 = F_7 ( V_16 , V_19 , V_12 ++ , V_2 -> V_3 ) ;
if ( V_15 )
goto V_20;
V_15 = F_7 ( V_16 , V_19 , V_12 ++ , V_2 -> V_5 ) ;
if ( V_15 )
goto V_20;
F_8 ( V_18 ) ;
return 0 ;
V_20:
F_8 ( V_18 ) ;
F_9 ( V_15 , L_1 ,
F_2 ( V_2 -> V_7 ) , F_2 ( V_2 -> V_8 ) + V_21 ) ;
return V_15 ;
}
static int F_10 ( struct V_22 * V_23 , void * V_24 )
{
T_2 V_25 ;
T_2 V_26 ;
int V_27 ;
struct V_9 * V_10 = V_23 -> V_28 ;
struct V_1 V_2 ;
T_3 V_29 ;
int V_15 = - V_30 ;
F_11 ( & V_10 -> V_31 ) ;
for ( V_27 = 0 ; V_27 < V_10 -> V_32 ; V_27 ++ ) {
V_15 = F_3 ( V_10 , V_27 , & V_2 ) ;
if ( V_15 )
break;
if ( F_1 ( & V_2 ) ) {
V_25 = F_2 ( V_2 . V_7 ) ;
V_26 = F_2 ( V_2 . V_8 ) + V_21 ;
V_29 = V_26 - V_25 + 1 ;
} else {
V_25 = 0 ;
V_26 = 0 ;
V_29 = 0 ;
}
F_12 ( V_23 , L_2
L_3 , V_27 ,
& V_25 , & V_26 , V_29 , V_2 . V_3 , V_2 . V_5 ,
F_1 ( & V_2 ) ? L_4 : L_5 ,
V_2 . V_7 & V_33 ? L_6 : L_7 ) ;
}
F_13 ( & V_10 -> V_31 ) ;
return V_15 ;
}
static int F_14 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
return F_15 ( V_35 , F_10 , V_34 -> V_36 ) ;
}
static int F_16 ( struct V_9 * V_10 )
{
V_10 -> V_35 = F_17 ( L_8 , V_37 | V_38 , NULL ,
V_10 , & V_39 ) ;
return F_18 ( V_10 -> V_35 ) ;
}
static int F_19 ( T_2 V_25 , T_3 V_29 )
{
if ( ( V_25 & V_21 ) || ( V_29 & V_21 ) ) {
F_20 ( L_9 ,
& V_25 , V_29 ) ;
return - V_40 ;
}
if ( V_29 == 0 )
return - V_40 ;
return 0 ;
}
static inline T_3 F_21 ( T_3 V_29 )
{
return V_29 - V_41 ;
}
static inline int F_22 ( T_2 V_42 , struct V_1 * V_2 )
{
return V_42 >= F_2 ( V_2 -> V_7 ) && V_42 <= F_2 ( V_2 -> V_8 ) ;
}
int F_23 ( T_2 V_25 , T_3 V_29 ,
unsigned int V_3 , unsigned int V_5 )
{
T_2 V_26 ;
unsigned int V_27 ;
struct V_9 * V_10 = & V_43 ;
struct V_1 V_2 ;
T_3 V_44 ;
int V_12 ;
int V_15 ;
if ( F_24 ( V_10 -> V_45 == false , L_10 ) )
return - V_30 ;
V_15 = F_19 ( V_25 , V_29 ) ;
if ( V_15 )
return V_15 ;
V_44 = F_21 ( V_29 ) ;
V_26 = V_25 + V_44 ;
V_2 . V_7 = F_25 ( V_25 ) ;
V_2 . V_8 = F_25 ( V_26 ) ;
V_2 . V_3 = V_3 ;
V_2 . V_5 = V_5 ;
if ( ! F_1 ( & V_2 ) )
return - V_46 ;
F_11 ( & V_10 -> V_31 ) ;
V_12 = - 1 ;
for ( V_27 = 0 ; V_27 < V_10 -> V_32 ; V_27 ++ ) {
V_15 = F_3 ( V_10 , V_27 , & V_2 ) ;
if ( V_15 )
goto V_20;
V_15 = - V_40 ;
if ( F_1 ( & V_2 ) ) {
if ( F_22 ( V_25 , & V_2 ) )
goto V_20;
if ( F_22 ( V_26 , & V_2 ) )
goto V_20;
} else {
V_12 = V_27 ;
}
}
if ( V_12 == - 1 ) {
V_15 = - V_47 ;
goto V_20;
}
F_26 ( L_11 ,
V_12 , & V_25 , & V_26 , V_44 , V_3 , V_5 ) ;
V_2 . V_7 = F_25 ( V_25 ) ;
V_2 . V_8 = F_25 ( V_26 ) ;
V_2 . V_3 = V_3 ;
V_2 . V_5 = V_5 ;
V_15 = F_5 ( V_10 , V_12 , & V_2 ) ;
if ( V_15 < 0 ) {
V_2 . V_7 = 0 ;
V_2 . V_8 = 0 ;
V_2 . V_3 = V_4 ;
V_2 . V_5 = V_6 ;
F_5 ( V_10 , V_12 , & V_2 ) ;
}
V_20:
F_13 ( & V_10 -> V_31 ) ;
return V_15 ;
}
static int F_27 ( int V_12 , T_2 V_25 , T_3 V_29 )
{
T_2 V_26 ;
bool V_48 = false ;
unsigned int V_27 ;
struct V_9 * V_10 = & V_43 ;
struct V_1 V_2 ;
T_3 V_44 ;
int V_15 = 0 ;
if ( F_24 ( V_10 -> V_45 == false , L_10 ) )
return - V_30 ;
if ( V_12 == - 1 ) {
V_15 = F_19 ( V_25 , V_29 ) ;
if ( V_15 )
return V_15 ;
}
V_44 = F_21 ( V_29 ) ;
V_26 = V_25 + V_44 ;
F_11 ( & V_10 -> V_31 ) ;
if ( V_12 >= 0 ) {
V_15 = F_3 ( V_10 , V_12 , & V_2 ) ;
if ( V_15 )
goto V_20;
if ( ! F_1 ( & V_2 ) || V_2 . V_7 & V_33 ) {
V_15 = - V_30 ;
goto V_20;
}
V_48 = true ;
} else {
for ( V_27 = 0 ; V_27 < V_10 -> V_32 ; V_27 ++ ) {
V_15 = F_3 ( V_10 , V_27 , & V_2 ) ;
if ( V_15 )
goto V_20;
if ( ! F_1 ( & V_2 ) || V_2 . V_7 & V_33 )
continue;
if ( ( F_2 ( V_2 . V_7 ) == V_25 ) &&
( F_2 ( V_2 . V_8 ) == V_26 ) ) {
V_48 = true ;
V_12 = V_27 ;
break;
}
}
}
if ( ! V_48 ) {
V_15 = - V_30 ;
goto V_20;
}
F_26 ( L_12 , V_12 , & V_25 , & V_26 , V_44 ) ;
V_2 . V_7 = 0 ;
V_2 . V_8 = 0 ;
V_2 . V_3 = V_4 ;
V_2 . V_5 = V_6 ;
V_15 = F_5 ( V_10 , V_12 , & V_2 ) ;
V_20:
F_13 ( & V_10 -> V_31 ) ;
return V_15 ;
}
int F_28 ( T_2 V_25 , T_3 V_29 )
{
return F_27 ( - 1 , V_25 , V_29 ) ;
}
static inline int F_29 ( int V_12 )
{
return F_27 ( V_12 , 0 , 0 ) ;
}
static void T_4 F_30 ( struct V_9 * V_10 )
{
T_2 V_25 = F_31 ( & V_49 ) ;
T_3 V_29 = F_31 ( & V_50 ) - V_25 ;
unsigned long V_51 , V_26 ;
int V_27 ;
int V_15 ;
for ( V_27 = 0 ; V_27 < V_10 -> V_32 ; V_27 ++ )
F_29 ( V_27 ) ;
V_51 = ( unsigned long ) V_49 ;
V_26 = ( unsigned long ) V_50 - 1 ;
V_15 = F_23 ( V_25 , V_29 , V_52 , V_52 ) ;
if ( V_15 < 0 ) {
F_20 ( L_13 ,
V_29 / 1024 , V_51 , V_26 ) ;
} else {
F_32 ( L_14 ,
V_29 / 1024 , V_51 , V_26 ) ;
}
}
static int T_4 F_33 ( void )
{
struct V_9 * V_10 = & V_43 ;
int V_15 ;
if ( ! F_34 ( V_53 ) || ! F_35 () )
return - V_30 ;
V_10 -> V_32 = V_54 ;
V_10 -> V_14 = V_55 ;
V_10 -> V_45 = true ;
F_36 ( & V_10 -> V_31 ) ;
V_15 = F_16 ( V_10 ) ;
if ( V_15 != 0 )
F_37 ( L_15 ) ;
F_30 ( V_10 ) ;
return 0 ;
}
