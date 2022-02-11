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
static int F_12 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_13 . V_35 ;
const struct V_36 * V_37 ;
struct V_4 * V_5 ;
int V_38 , V_7 = 0 ;
if ( ! V_34 )
return - V_39 ;
V_5 = F_13 ( & V_32 -> V_13 , sizeof( * V_5 ) , V_40 ) ;
if ( ! V_5 )
return - V_41 ;
V_5 -> V_13 = & V_32 -> V_13 ;
F_14 ( V_32 , V_5 ) ;
V_37 = F_15 ( V_42 , V_34 ) ;
V_5 -> V_11 = (struct V_43 * ) V_37 -> V_17 ;
V_5 -> V_10 = F_16 ( V_34 , L_6 ) ;
if ( F_17 ( V_5 -> V_10 ) ) {
F_4 ( & V_32 -> V_13 , L_7 ) ;
return F_18 ( V_5 -> V_10 ) ;
}
for ( V_38 = 0 ; V_38 < V_44 ; V_38 ++ ) {
const char * V_45 = V_5 -> V_11 -> V_46 [ V_38 ] ;
struct V_1 * V_2 = & V_5 -> V_26 [ V_38 ] ;
struct V_47 * V_28 ;
int V_3 ;
if ( ! V_45 )
continue;
V_28 = F_19 ( V_5 -> V_13 , V_45 ) ;
if ( F_17 ( V_28 ) ) {
V_7 = F_18 ( V_28 ) ;
if ( V_7 == - V_39 )
continue;
else if ( V_7 != - V_48 )
F_4 ( V_5 -> V_13 , L_8 ,
V_45 ) ;
goto V_49;
}
V_3 = F_20 ( V_28 ) ;
if ( V_3 < 0 ) {
F_4 ( V_5 -> V_13 , L_9 ,
V_45 ) ;
goto V_49;
}
if ( V_3 > V_24 ) {
F_21 ( V_5 -> V_13 ,
L_10 ,
V_3 ) ;
V_7 = - V_50 ;
goto V_49;
}
V_2 -> V_9 = V_38 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_15 . V_51 = F_5 ;
V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_7 ) {
V_2 -> V_28 = NULL ;
goto V_49;
}
V_7 = F_22 ( V_28 , & V_2 -> V_15 ) ;
if ( V_7 ) {
F_4 ( & V_32 -> V_13 ,
L_11 ) ;
V_2 -> V_28 = NULL ;
goto V_49;
}
}
if ( V_5 -> V_11 -> V_52 )
V_5 -> V_11 -> V_52 ( V_5 ) ;
return 0 ;
V_49:
for ( V_38 = V_44 - 1 ; V_38 >= 0 ; V_38 -- ) {
struct V_1 * V_53 = & V_5 -> V_26 [ V_38 ] ;
if ( V_53 -> V_28 )
F_23 ( V_53 -> V_28 ,
& V_53 -> V_15 ) ;
}
return V_7 ;
}
static int F_24 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_25 ( V_32 ) ;
int V_38 ;
for ( V_38 = V_44 - 1 ; V_38 >= 0 ; V_38 -- ) {
struct V_1 * V_53 = & V_5 -> V_26 [ V_38 ] ;
if ( V_53 -> V_28 )
F_23 ( V_53 -> V_28 ,
& V_53 -> V_15 ) ;
}
return 0 ;
}
