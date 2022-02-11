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
V_15 = F_4 ( V_16 , V_17 ,
V_12 ++ , & V_2 -> V_7 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_4 ( V_16 , V_17 ,
V_12 ++ , & V_2 -> V_8 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_4 ( V_16 , V_17 ,
V_12 ++ , & V_2 -> V_3 ) ;
if ( V_15 )
return V_15 ;
return F_4 ( V_16 , V_17 ,
V_12 ++ , & V_2 -> V_5 ) ;
}
static int F_5 ( struct V_9 * V_10 , T_1 V_11 ,
struct V_1 * V_2 , bool V_18 )
{
unsigned long V_19 ;
T_1 V_12 = V_11 * V_13 + V_10 -> V_14 ;
int V_15 ;
F_6 ( V_19 ) ;
V_15 = F_7 ( V_16 , V_20 , V_12 ++ ,
V_2 -> V_7 ) ;
if ( V_15 )
goto V_21;
V_15 = F_7 ( V_16 , V_20 ,
V_12 ++ , V_2 -> V_8 ) ;
if ( V_15 )
goto V_21;
V_15 = F_7 ( V_16 , V_20 ,
V_12 ++ , V_2 -> V_3 ) ;
if ( V_15 )
goto V_21;
V_15 = F_7 ( V_16 , V_20 ,
V_12 ++ , V_2 -> V_5 ) ;
if ( V_15 )
goto V_21;
if ( V_18 ) {
V_2 -> V_7 |= V_22 ;
V_15 = F_7 ( V_16 , V_20 ,
V_12 - V_13 , V_2 -> V_7 ) ;
if ( V_15 )
goto V_21;
}
F_8 ( V_19 ) ;
return 0 ;
V_21:
F_8 ( V_19 ) ;
F_9 ( V_15 , L_1 ,
F_2 ( V_2 -> V_7 ) , F_2 ( V_2 -> V_8 ) + V_23 ) ;
return V_15 ;
}
static int F_10 ( struct V_24 * V_25 , void * V_26 )
{
T_2 V_27 ;
T_2 V_28 ;
int V_29 ;
struct V_9 * V_10 = V_25 -> V_30 ;
struct V_1 V_2 ;
T_3 V_31 ;
int V_15 = - V_32 ;
F_11 ( & V_10 -> V_18 ) ;
for ( V_29 = 0 ; V_29 < V_10 -> V_33 ; V_29 ++ ) {
V_15 = F_3 ( V_10 , V_29 , & V_2 ) ;
if ( V_15 )
break;
if ( F_1 ( & V_2 ) ) {
V_27 = F_2 ( V_2 . V_7 ) ;
V_28 = F_2 ( V_2 . V_8 ) + V_23 ;
} else {
V_27 = 0 ;
V_28 = 0 ;
}
V_31 = V_28 - V_27 ;
F_12 ( V_25 , L_2
L_3 , V_29 ,
& V_27 , & V_28 , V_31 , V_2 . V_3 , V_2 . V_5 ,
F_1 ( & V_2 ) ? L_4 : L_5 ,
V_2 . V_7 & V_22 ? L_6 : L_7 ) ;
}
F_13 ( & V_10 -> V_18 ) ;
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
static void F_19 ( struct V_9 * V_10 )
{
F_20 ( V_10 -> V_35 ) ;
}
static int F_21 ( T_2 V_27 , T_3 V_31 )
{
if ( ( V_27 & V_23 ) || ( V_31 & V_23 ) ) {
F_22 ( L_9 ,
& V_27 , V_31 ) ;
return - V_40 ;
}
if ( V_31 == 0 )
return - V_40 ;
return 0 ;
}
static inline T_3 F_23 ( T_3 V_31 )
{
return V_31 - V_41 ;
}
static inline int F_24 ( T_2 V_42 , struct V_1 * V_2 )
{
return V_42 >= F_2 ( V_2 -> V_7 ) && V_42 <= F_2 ( V_2 -> V_8 ) ;
}
int F_25 ( T_2 V_27 , T_3 V_31 ,
unsigned int V_3 , unsigned int V_5 , bool V_18 )
{
T_2 V_28 ;
unsigned int V_29 ;
struct V_9 * V_10 = & V_43 ;
struct V_1 V_2 ;
T_3 V_44 ;
int V_12 ;
int V_15 ;
if ( F_26 ( V_10 -> V_45 == false , L_10 ) )
return - V_32 ;
V_15 = F_21 ( V_27 , V_31 ) ;
if ( V_15 )
return V_15 ;
V_44 = F_23 ( V_31 ) ;
V_28 = V_27 + V_44 ;
V_2 . V_7 = F_27 ( V_27 ) ;
V_2 . V_8 = F_27 ( V_28 ) ;
V_2 . V_3 = V_3 ;
V_2 . V_5 = V_5 ;
if ( ! F_1 ( & V_2 ) )
return - V_46 ;
F_11 ( & V_10 -> V_18 ) ;
V_12 = - 1 ;
for ( V_29 = 0 ; V_29 < V_10 -> V_33 ; V_29 ++ ) {
V_15 = F_3 ( V_10 , V_29 , & V_2 ) ;
if ( V_15 )
goto V_21;
V_15 = - V_40 ;
if ( F_1 ( & V_2 ) ) {
if ( F_24 ( V_27 , & V_2 ) )
goto V_21;
if ( F_24 ( V_28 , & V_2 ) )
goto V_21;
} else {
V_12 = V_29 ;
}
}
if ( V_12 == - 1 ) {
V_15 = - V_47 ;
goto V_21;
}
F_28 ( L_11 ,
V_12 , & V_27 , & V_28 , V_44 , V_3 , V_5 ) ;
V_2 . V_7 = F_27 ( V_27 ) ;
V_2 . V_8 = F_27 ( V_28 ) ;
V_2 . V_3 = V_3 ;
V_2 . V_5 = V_5 ;
V_15 = F_5 ( V_10 , V_12 , & V_2 , V_18 ) ;
if ( V_15 < 0 ) {
V_2 . V_7 = 0 ;
V_2 . V_8 = 0 ;
V_2 . V_3 = V_4 ;
V_2 . V_5 = V_6 ;
F_5 ( V_10 , V_12 , & V_2 , false ) ;
}
V_21:
F_13 ( & V_10 -> V_18 ) ;
return V_15 ;
}
static int F_29 ( int V_12 , T_2 V_27 , T_3 V_31 )
{
T_2 V_28 ;
bool V_48 = false ;
unsigned int V_29 ;
struct V_9 * V_10 = & V_43 ;
struct V_1 V_2 ;
T_3 V_44 ;
int V_15 = 0 ;
if ( F_26 ( V_10 -> V_45 == false , L_10 ) )
return - V_32 ;
if ( V_12 == - 1 ) {
V_15 = F_21 ( V_27 , V_31 ) ;
if ( V_15 )
return V_15 ;
}
V_44 = F_23 ( V_31 ) ;
V_28 = V_27 + V_44 ;
F_11 ( & V_10 -> V_18 ) ;
if ( V_12 >= 0 ) {
V_15 = F_3 ( V_10 , V_12 , & V_2 ) ;
if ( V_15 )
goto V_21;
if ( ! F_1 ( & V_2 ) || V_2 . V_7 & V_22 ) {
V_15 = - V_32 ;
goto V_21;
}
V_48 = true ;
} else {
for ( V_29 = 0 ; V_29 < V_10 -> V_33 ; V_29 ++ ) {
V_15 = F_3 ( V_10 , V_29 , & V_2 ) ;
if ( V_15 )
goto V_21;
if ( ! F_1 ( & V_2 ) || V_2 . V_7 & V_22 )
continue;
if ( ( F_2 ( V_2 . V_7 ) == V_27 ) &&
( F_2 ( V_2 . V_8 ) == V_28 ) ) {
V_48 = true ;
V_12 = V_29 ;
break;
}
}
}
if ( ! V_48 ) {
V_15 = - V_32 ;
goto V_21;
}
F_28 ( L_12 , V_12 , & V_27 , & V_28 , V_44 ) ;
V_2 . V_7 = 0 ;
V_2 . V_8 = 0 ;
V_2 . V_3 = V_4 ;
V_2 . V_5 = V_6 ;
V_15 = F_5 ( V_10 , V_12 , & V_2 , false ) ;
V_21:
F_13 ( & V_10 -> V_18 ) ;
return V_15 ;
}
int F_30 ( T_2 V_27 , T_3 V_31 )
{
return F_29 ( - 1 , V_27 , V_31 ) ;
}
static inline int F_31 ( int V_12 )
{
return F_29 ( V_12 , 0 , 0 ) ;
}
static void T_4 F_32 ( struct V_9 * V_10 )
{
T_2 V_27 = F_33 ( & V_49 ) ;
T_3 V_31 = F_33 ( & V_50 ) - V_27 ;
int V_29 ;
int V_15 ;
for ( V_29 = 0 ; V_29 < V_10 -> V_33 ; V_29 ++ )
F_31 ( V_29 ) ;
V_15 = F_25 ( V_27 , V_31 , V_51 , V_51 , true ) ;
if ( V_15 < 0 ) {
F_22 ( L_13 ,
& V_49 , & V_50 ) ;
} else {
F_34 ( L_14 ,
V_31 / 1024 , & V_49 , & V_50 ) ;
}
}
static int T_4 F_35 ( void )
{
struct V_9 * V_10 = & V_43 ;
int V_15 ;
if ( ! F_36 ( V_52 ) || ! F_37 () )
return - V_32 ;
V_10 -> V_33 = V_53 ;
V_10 -> V_14 = V_54 ;
V_10 -> V_45 = true ;
F_38 ( & V_10 -> V_18 ) ;
V_15 = F_16 ( V_10 ) ;
if ( V_15 != 0 )
F_39 ( L_15 ) ;
F_32 ( V_10 ) ;
return 0 ;
}
static void T_5 F_40 ( void )
{
F_19 ( & V_43 ) ;
}
