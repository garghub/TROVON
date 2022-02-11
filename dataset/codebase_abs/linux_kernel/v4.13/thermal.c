static int
F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
* V_3 = V_4 ;
return 0 ;
}
static int
F_2 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( & V_6 -> V_8 ) ;
* V_3 = V_6 -> V_9 . V_10 ;
F_4 ( & V_6 -> V_8 ) ;
return 0 ;
}
static int
F_5 ( struct V_1 * V_2 ,
unsigned long V_10 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_10 > V_4 ) {
F_6 ( V_6 , L_1 ,
V_10 , V_4 ) ;
return - V_11 ;
}
F_3 ( & V_6 -> V_8 ) ;
V_6 -> V_9 . V_10 = V_10 ;
F_7 ( V_6 ) ;
F_4 ( & V_6 -> V_8 ) ;
return 0 ;
}
static T_1 F_8 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_5 * V_6 = F_9 ( V_13 ) ;
int V_17 , V_18 ;
unsigned long V_19 ;
F_3 ( & V_6 -> V_8 ) ;
if ( V_6 -> V_3 != V_20 ) {
V_17 = - V_21 ;
goto V_22;
}
F_10 ( & V_6 -> V_9 . V_23 ) ;
V_17 = F_11 ( V_6 ) ;
if ( V_17 ) {
F_6 ( V_6 , L_2 , V_17 ) ;
goto V_22;
}
if ( F_12 ( V_24 , & V_6 -> V_25 ) ) {
V_17 = - V_26 ;
goto V_22;
}
V_19 = F_13 ( & V_6 -> V_9 . V_23 ,
V_27 ) ;
if ( ! V_19 ) {
F_6 ( V_6 , L_3 ) ;
V_17 = - V_28 ;
goto V_22;
}
F_14 ( & V_6 -> V_29 ) ;
V_18 = V_6 -> V_9 . V_18 ;
F_15 ( & V_6 -> V_29 ) ;
V_17 = snprintf ( V_16 , V_30 , L_4 , V_18 * 1000 ) ;
V_22:
F_4 ( & V_6 -> V_8 ) ;
return V_17 ;
}
void F_16 ( struct V_5 * V_6 , int V_18 )
{
F_14 ( & V_6 -> V_29 ) ;
V_6 -> V_9 . V_18 = V_18 ;
F_15 ( & V_6 -> V_29 ) ;
F_17 ( & V_6 -> V_9 . V_23 ) ;
}
void F_7 ( struct V_5 * V_6 )
{
T_2 V_31 , V_32 , V_33 ;
int V_17 ;
F_18 ( & V_6 -> V_8 ) ;
if ( ! V_6 -> V_34 . V_35 -> V_36 )
return;
if ( V_6 -> V_3 != V_20 )
return;
V_31 = V_6 -> V_9 . V_37 ;
V_32 = ( V_31 * V_6 -> V_9 . V_10 ) / 100 ;
V_33 = V_32 ? 1 : 0 ;
V_17 = F_19 ( V_6 , V_31 , V_32 ,
V_38 ,
V_33 ) ;
if ( V_17 ) {
F_6 ( V_6 , L_5 ,
V_31 , V_32 , V_33 , V_17 ) ;
}
}
int F_20 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_12 * V_39 ;
int V_17 ;
V_2 = F_21 ( L_6 , V_6 ,
& V_40 ) ;
if ( F_22 ( V_2 ) ) {
F_23 ( V_6 , L_7 ,
F_24 ( V_2 ) ) ;
return - V_11 ;
}
V_17 = F_25 ( & V_6 -> V_13 -> V_41 , & V_2 -> V_12 . V_41 ,
L_8 ) ;
if ( V_17 ) {
F_23 ( V_6 , L_9 ) ;
goto V_42;
}
V_6 -> V_9 . V_2 = V_2 ;
V_6 -> V_9 . V_37 = V_43 ;
if ( ! ( V_6 -> V_34 . V_35 -> V_44 ) )
return 0 ;
if ( ! F_26 ( V_45 ) )
return 0 ;
V_39 = F_27 ( V_6 -> V_13 ,
L_10 , V_6 ,
V_46 ) ;
if ( F_22 ( V_39 ) ) {
F_23 ( V_6 , L_11 ,
F_24 ( V_39 ) ) ;
V_17 = - V_11 ;
goto V_47;
}
return 0 ;
V_47:
F_28 ( & V_6 -> V_13 -> V_41 , L_8 ) ;
V_42:
F_29 ( V_2 ) ;
return V_17 ;
}
void F_30 ( struct V_5 * V_6 )
{
F_28 ( & V_6 -> V_13 -> V_41 , L_8 ) ;
F_29 ( V_6 -> V_9 . V_2 ) ;
}
