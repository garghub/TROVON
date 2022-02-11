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
F_8 ( V_2 -> V_5 -> V_13 , L_4 , V_3 ) ;
return V_23 ;
}
static void F_9 ( struct V_4 * V_5 )
{
int V_7 ;
T_1 V_6 ;
if ( ! V_5 -> V_26 [ V_27 ] . V_28 )
return;
V_6 = V_29 | ( V_29 << 16 ) ;
V_7 = F_3 ( V_5 -> V_10 , V_30 , V_6 ) ;
if ( V_7 < 0 )
F_10 ( V_5 -> V_13 , L_5 ) ;
}
static void F_11 ( struct V_4 * V_5 )
{
int V_7 ;
T_1 V_6 ;
if ( ! V_5 -> V_26 [ V_31 ] . V_28 )
return;
V_6 = V_32 | ( V_32 << 16 ) ;
V_7 = F_3 ( V_5 -> V_10 , V_33 , V_6 ) ;
if ( V_7 < 0 )
F_10 ( V_5 -> V_13 , L_6 ) ;
}
static void F_12 ( struct V_4 * V_5 )
{
int V_7 ;
T_1 V_6 ;
if ( ! V_5 -> V_26 [ V_34 ] . V_28 )
return;
V_6 = V_35 | ( V_35 << 16 ) ;
V_7 = F_3 ( V_5 -> V_10 , V_36 , V_6 ) ;
if ( V_7 < 0 )
F_10 ( V_5 -> V_13 , L_5 ) ;
}
static void F_13 ( struct V_4 * V_5 )
{
int V_7 ;
T_1 V_6 ;
if ( ! V_5 -> V_26 [ V_37 ] . V_28 )
return;
V_6 = V_38 | ( V_38 << 16 ) ;
V_7 = F_3 ( V_5 -> V_10 , V_39 , V_6 ) ;
if ( V_7 < 0 )
F_10 ( V_5 -> V_13 , L_7 ) ;
}
static int F_14 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_13 . V_44 ;
const struct V_45 * V_46 ;
struct V_4 * V_5 ;
struct V_47 * V_48 ;
int V_49 , V_7 = 0 ;
if ( ! V_43 )
return - V_50 ;
V_5 = F_15 ( & V_41 -> V_13 , sizeof( * V_5 ) , V_51 ) ;
if ( ! V_5 )
return - V_52 ;
V_5 -> V_13 = & V_41 -> V_13 ;
F_16 ( V_41 , V_5 ) ;
V_46 = F_17 ( V_53 , V_43 ) ;
V_5 -> V_11 = (struct V_54 * ) V_46 -> V_17 ;
V_48 = V_41 -> V_13 . V_48 ;
if ( V_48 && V_48 -> V_44 ) {
V_5 -> V_10 = F_18 ( V_48 -> V_44 ) ;
} else {
F_8 ( & V_41 -> V_13 , L_8 ) ;
V_5 -> V_10 = F_19 ( V_43 , L_9 ) ;
}
if ( F_20 ( V_5 -> V_10 ) ) {
F_4 ( & V_41 -> V_13 , L_10 ) ;
return F_21 ( V_5 -> V_10 ) ;
}
for ( V_49 = 0 ; V_49 < V_55 ; V_49 ++ ) {
const char * V_56 = V_5 -> V_11 -> V_57 [ V_49 ] ;
struct V_1 * V_2 = & V_5 -> V_26 [ V_49 ] ;
struct V_58 * V_28 ;
int V_3 ;
if ( ! V_56 )
continue;
V_28 = F_22 ( V_5 -> V_13 , V_56 ) ;
if ( F_20 ( V_28 ) ) {
V_7 = F_21 ( V_28 ) ;
if ( V_7 == - V_50 )
continue;
else if ( V_7 != - V_59 )
F_4 ( V_5 -> V_13 , L_11 ,
V_56 ) ;
goto V_60;
}
V_3 = F_23 ( V_28 ) ;
if ( V_3 < 0 ) {
F_4 ( V_5 -> V_13 , L_12 ,
V_56 ) ;
goto V_60;
}
if ( V_3 > V_24 ) {
F_24 ( V_5 -> V_13 ,
L_13 ,
V_3 ) ;
V_7 = - V_61 ;
goto V_60;
}
V_2 -> V_9 = V_49 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_15 . V_62 = F_5 ;
V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_7 ) {
V_2 -> V_28 = NULL ;
goto V_60;
}
V_7 = F_25 ( V_28 , & V_2 -> V_15 ) ;
if ( V_7 ) {
F_4 ( & V_41 -> V_13 ,
L_14 ) ;
V_2 -> V_28 = NULL ;
goto V_60;
}
}
if ( V_5 -> V_11 -> V_63 )
V_5 -> V_11 -> V_63 ( V_5 ) ;
return 0 ;
V_60:
for ( V_49 = V_55 - 1 ; V_49 >= 0 ; V_49 -- ) {
struct V_1 * V_64 = & V_5 -> V_26 [ V_49 ] ;
if ( V_64 -> V_28 )
F_26 ( V_64 -> V_28 ,
& V_64 -> V_15 ) ;
}
return V_7 ;
}
static int F_27 ( struct V_40 * V_41 )
{
struct V_4 * V_5 = F_28 ( V_41 ) ;
int V_49 ;
for ( V_49 = V_55 - 1 ; V_49 >= 0 ; V_49 -- ) {
struct V_1 * V_64 = & V_5 -> V_26 [ V_49 ] ;
if ( V_64 -> V_28 )
F_26 ( V_64 -> V_28 ,
& V_64 -> V_15 ) ;
}
return 0 ;
}
