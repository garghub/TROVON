static void F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
V_4 = V_6 [ V_5 ] ;
V_4 -> V_7 ( V_2 ) ;
}
}
static int F_3 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
int V_5 , V_8 = - V_9 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
V_4 = V_6 [ V_5 ] ;
V_8 = V_4 -> V_10 ( V_2 ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static int F_4 ( struct V_11 * V_12 )
{
int V_8 = - V_13 , V_5 ;
const struct V_3 * V_4 ;
T_1 type = F_5 ( V_12 -> V_14 ) ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
V_4 = V_6 [ V_5 ] ;
if ( type != V_4 -> type )
continue;
V_8 = V_4 -> V_15 ( V_12 ) ;
break;
}
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_11 * V_16 )
{
struct V_11 * V_12 , * V_17 ;
unsigned long V_18 ;
int V_8 = 0 , V_19 ;
F_7 ( & V_2 -> V_20 , V_18 ) ;
if ( V_16 )
V_8 = F_8 ( & V_2 -> V_21 , V_16 ) ;
if ( V_2 -> V_16 ) {
F_9 ( & V_2 -> V_20 , V_18 ) ;
return V_8 ;
}
V_17 = F_10 ( & V_2 -> V_21 ) ;
V_12 = F_11 ( & V_2 -> V_21 ) ;
if ( V_12 )
V_2 -> V_16 = V_12 ;
F_9 ( & V_2 -> V_20 , V_18 ) ;
if ( ! V_12 )
return V_8 ;
if ( V_17 ) {
F_12 ( & V_2 -> V_20 ) ;
V_17 -> V_22 ( V_17 , - V_23 ) ;
F_13 ( & V_2 -> V_20 ) ;
}
V_19 = F_4 ( V_12 ) ;
if ( V_19 ) {
V_2 -> V_24 = V_19 ;
F_14 ( & V_2 -> V_25 ) ;
}
return V_8 ;
}
static void F_15 ( unsigned long V_26 )
{
struct V_1 * V_2 = (struct V_1 * ) V_26 ;
struct V_11 * V_16 ;
unsigned long V_18 ;
F_7 ( & V_2 -> V_20 , V_18 ) ;
V_16 = V_2 -> V_16 ;
V_2 -> V_16 = NULL ;
F_9 ( & V_2 -> V_20 , V_18 ) ;
if ( V_16 )
V_16 -> V_22 ( V_16 , V_2 -> V_24 ) ;
F_6 ( V_2 , NULL ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_11 * V_16 )
{
return F_6 ( V_2 , V_16 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_8 )
{
V_2 -> V_24 = V_8 ;
F_14 ( & V_2 -> V_25 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_1 V_27 , V_28 , V_29 ;
F_19 ( V_2 , & V_27 , & V_28 , & V_29 ) ;
if ( V_27 != V_30 || V_28 == 0 )
return - V_9 ;
V_2 -> V_31 = V_32 ;
V_2 -> V_33 = 1 ;
F_20 ( V_2 -> V_34 , L_1 ,
V_27 , V_28 , V_29 ) ;
return 0 ;
}
static int F_21 ( struct V_35 * V_36 )
{
struct V_37 * V_34 = & V_36 -> V_34 ;
struct V_1 * V_2 ;
struct V_38 * V_39 ;
int V_8 ;
V_2 = F_22 ( V_34 , sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return - V_41 ;
V_2 -> V_34 = V_34 ;
F_23 ( V_36 , V_2 ) ;
V_39 = F_24 ( V_36 , V_42 , 0 ) ;
V_2 -> V_43 = F_25 ( & V_36 -> V_34 , V_39 ) ;
if ( F_26 ( V_2 -> V_43 ) )
return F_27 ( V_2 -> V_43 ) ;
V_8 = F_28 ( V_34 , F_29 ( 32 ) ) ;
if ( V_8 < 0 )
return V_8 ;
V_2 -> V_44 = F_30 ( V_2 -> V_34 , L_2 ) ;
if ( F_26 ( V_2 -> V_44 ) )
return F_27 ( V_2 -> V_44 ) ;
V_2 -> V_45 = F_30 ( V_2 -> V_34 , L_3 ) ;
if ( F_26 ( V_2 -> V_45 ) )
return F_27 ( V_2 -> V_45 ) ;
V_2 -> V_46 = F_30 ( V_2 -> V_34 , L_4 ) ;
if ( F_26 ( V_2 -> V_46 ) )
return F_27 ( V_2 -> V_46 ) ;
V_8 = F_31 ( V_2 -> V_44 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_31 ( V_2 -> V_45 ) ;
if ( V_8 )
goto V_47;
V_8 = F_31 ( V_2 -> V_46 ) ;
if ( V_8 )
goto V_48;
V_8 = F_32 ( V_2 -> V_34 , & V_2 -> V_49 ) ;
if ( V_8 )
goto V_50;
V_8 = F_18 ( V_2 ) ;
if ( V_8 )
goto V_50;
F_33 ( & V_2 -> V_20 ) ;
F_34 ( & V_2 -> V_25 , F_15 ,
( unsigned long ) V_2 ) ;
F_35 ( & V_2 -> V_21 , V_51 ) ;
V_2 -> V_52 = F_16 ;
V_2 -> V_53 = F_17 ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 )
goto V_54;
return 0 ;
V_54:
F_36 ( & V_2 -> V_49 ) ;
V_50:
F_37 ( V_2 -> V_46 ) ;
V_48:
F_37 ( V_2 -> V_45 ) ;
V_47:
F_37 ( V_2 -> V_44 ) ;
return V_8 ;
}
static int F_38 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_39 ( V_36 ) ;
F_40 ( & V_2 -> V_25 ) ;
F_1 ( V_2 ) ;
F_36 ( & V_2 -> V_49 ) ;
F_37 ( V_2 -> V_46 ) ;
F_37 ( V_2 -> V_45 ) ;
F_37 ( V_2 -> V_44 ) ;
return 0 ;
}
