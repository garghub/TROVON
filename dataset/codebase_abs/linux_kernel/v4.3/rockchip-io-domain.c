static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 ;
int V_7 ;
V_6 = ( V_3 > V_8 ) ? 0 : 1 ;
V_6 <<= V_2 -> V_9 ;
V_6 |= ( F_2 ( V_2 -> V_9 ) << 16 ) ;
V_7 = F_3 ( V_5 -> V_10 , V_5 -> V_11 -> V_12 , V_6 ) ;
if ( V_7 )
F_4 ( V_5 -> V_13 , L_1 ) ;
return V_7 ;
}
static int F_5 ( struct V_14 * V_15 ,
unsigned long V_16 ,
void * V_17 )
{
struct V_1 * V_2 =
F_6 ( V_15 , struct V_1 , V_15 ) ;
int V_3 ;
int V_7 ;
if ( V_16 & V_18 ) {
struct V_19 * V_20 = V_17 ;
V_3 = F_7 (unsigned long, pvc_data->old_uV, pvc_data->max_uV) ;
} else if ( V_16 & ( V_21 |
V_22 ) ) {
V_3 = ( unsigned long ) V_17 ;
} else {
return V_23 ;
}
F_8 ( V_2 -> V_5 -> V_13 , L_2 , V_3 ) ;
if ( V_3 > V_24 ) {
F_4 ( V_2 -> V_5 -> V_13 , L_3 , V_3 ) ;
if ( V_16 == V_18 )
return V_25 ;
}
V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_7 && V_16 == V_18 )
return V_25 ;
F_9 ( V_2 -> V_5 -> V_13 , L_4 , V_3 ) ;
return V_23 ;
}
static void F_10 ( struct V_4 * V_5 )
{
int V_7 ;
T_1 V_6 ;
if ( ! V_5 -> V_26 [ V_27 ] . V_28 )
return;
V_6 = V_29 | ( V_29 << 16 ) ;
V_7 = F_3 ( V_5 -> V_10 , V_30 , V_6 ) ;
if ( V_7 < 0 )
F_11 ( V_5 -> V_13 , L_5 ) ;
}
static void F_12 ( struct V_4 * V_5 )
{
int V_7 ;
T_1 V_6 ;
if ( ! V_5 -> V_26 [ V_31 ] . V_28 )
return;
V_6 = V_32 | ( V_32 << 16 ) ;
V_7 = F_3 ( V_5 -> V_10 , V_33 , V_6 ) ;
if ( V_7 < 0 )
F_11 ( V_5 -> V_13 , L_5 ) ;
}
static int F_13 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_35 -> V_13 . V_38 ;
const struct V_39 * V_40 ;
struct V_4 * V_5 ;
int V_41 , V_7 = 0 ;
if ( ! V_37 )
return - V_42 ;
V_5 = F_14 ( & V_35 -> V_13 , sizeof( * V_5 ) , V_43 ) ;
if ( ! V_5 )
return - V_44 ;
V_5 -> V_13 = & V_35 -> V_13 ;
F_15 ( V_35 , V_5 ) ;
V_40 = F_16 ( V_45 , V_37 ) ;
V_5 -> V_11 = (struct V_46 * ) V_40 -> V_17 ;
V_5 -> V_10 = F_17 ( V_37 , L_6 ) ;
if ( F_18 ( V_5 -> V_10 ) ) {
F_4 ( & V_35 -> V_13 , L_7 ) ;
return F_19 ( V_5 -> V_10 ) ;
}
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ ) {
const char * V_48 = V_5 -> V_11 -> V_49 [ V_41 ] ;
struct V_1 * V_2 = & V_5 -> V_26 [ V_41 ] ;
struct V_50 * V_28 ;
int V_3 ;
if ( ! V_48 )
continue;
V_28 = F_20 ( V_5 -> V_13 , V_48 ) ;
if ( F_18 ( V_28 ) ) {
V_7 = F_19 ( V_28 ) ;
if ( V_7 == - V_42 )
continue;
else if ( V_7 != - V_51 )
F_4 ( V_5 -> V_13 , L_8 ,
V_48 ) ;
goto V_52;
}
V_3 = F_21 ( V_28 ) ;
if ( V_3 < 0 ) {
F_4 ( V_5 -> V_13 , L_9 ,
V_48 ) ;
goto V_52;
}
if ( V_3 > V_24 ) {
F_22 ( V_5 -> V_13 ,
L_10 ,
V_3 ) ;
V_7 = - V_53 ;
goto V_52;
}
V_2 -> V_9 = V_41 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_15 . V_54 = F_5 ;
V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_7 ) {
V_2 -> V_28 = NULL ;
goto V_52;
}
V_7 = F_23 ( V_28 , & V_2 -> V_15 ) ;
if ( V_7 ) {
F_4 ( & V_35 -> V_13 ,
L_11 ) ;
V_2 -> V_28 = NULL ;
goto V_52;
}
}
if ( V_5 -> V_11 -> V_55 )
V_5 -> V_11 -> V_55 ( V_5 ) ;
return 0 ;
V_52:
for ( V_41 = V_47 - 1 ; V_41 >= 0 ; V_41 -- ) {
struct V_1 * V_56 = & V_5 -> V_26 [ V_41 ] ;
if ( V_56 -> V_28 )
F_24 ( V_56 -> V_28 ,
& V_56 -> V_15 ) ;
}
return V_7 ;
}
static int F_25 ( struct V_34 * V_35 )
{
struct V_4 * V_5 = F_26 ( V_35 ) ;
int V_41 ;
for ( V_41 = V_47 - 1 ; V_41 >= 0 ; V_41 -- ) {
struct V_1 * V_56 = & V_5 -> V_26 [ V_41 ] ;
if ( V_56 -> V_28 )
F_24 ( V_56 -> V_28 ,
& V_56 -> V_15 ) ;
}
return 0 ;
}
