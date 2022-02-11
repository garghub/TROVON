int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_3 = 0 , V_4 ;
do {
V_4 = F_2 ( V_1 -> V_5 , V_2 ) ;
} while ( V_4 < 0 && V_3 ++ < V_6 );
return V_4 ;
}
int F_3 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_7 )
{
int V_3 = 0 , V_4 ;
do {
V_4 = F_4 ( V_1 -> V_5 , V_2 , V_7 ) ;
} while ( V_4 < 0 && V_3 ++ < V_6 );
return V_4 ;
}
int F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_8 , T_1 * V_9 )
{
int V_3 = 0 , V_4 ;
do {
V_4 = F_6 ( V_1 -> V_5 ,
V_2 , V_8 , V_9 ) ;
} while ( V_4 < 0 && V_3 ++ < V_6 );
return V_4 ;
}
static void F_7 ( struct V_1 * V_1 )
{
struct V_10 * V_11 = V_1 -> V_11 ;
T_1 V_12 [ V_13 ] ;
T_1 V_14 , V_15 ;
int V_16 , V_4 ;
V_4 = F_5 ( V_1 , V_17 ,
V_13 , V_12 ) ;
if ( V_4 != V_13 ) {
F_8 ( & V_1 -> V_5 -> V_18 ,
L_1 , V_4 ) ;
return;
}
for ( V_16 = 0 ; V_16 < V_13 && V_12 [ V_16 ] ; V_16 ++ ) {
V_15 = V_12 [ V_16 ] & 0x80 ;
V_14 = V_12 [ V_16 ] & 0x7f ;
F_9 ( V_11 , V_19 , V_20 , V_14 ) ;
F_10 ( V_11 , V_1 -> V_21 [ V_14 ] , V_15 ) ;
}
F_11 ( V_11 ) ;
}
static T_2 F_12 ( int V_22 , void * V_23 )
{
struct V_1 * V_1 = V_23 ;
T_1 V_24 = F_1 ( V_1 , V_25 ) ;
if ( ! V_24 )
return V_26 ;
if ( V_24 & V_27 ) {
T_1 V_28 = F_1 ( V_1 , V_29 ) ;
if ( V_28 & ( V_30 | V_31 ) ) {
T_1 V_32 [ V_13 ] ;
F_5 ( V_1 , V_17 ,
V_13 , V_32 ) ;
}
F_8 ( & V_1 -> V_5 -> V_18 , L_2 , V_28 ) ;
}
if ( V_24 & V_33 )
F_7 ( V_1 ) ;
return V_34 ;
}
static int F_13 ( struct V_35 * V_5 ,
const struct V_36 * V_37 )
{
const struct V_38 * V_39 = V_5 -> V_18 . V_40 ;
struct V_1 * V_1 ;
struct V_10 * V_11 ;
int V_28 , V_41 ;
if ( ! V_39 )
return - V_42 ;
V_41 = V_39 -> V_41 ? : 500 ;
if ( V_41 / 3 <= V_39 -> V_43 / 3 ) {
F_8 ( & V_5 -> V_18 , L_3 ) ;
return - V_42 ;
}
V_1 = F_14 ( sizeof( * V_1 ) , V_44 ) ;
V_11 = F_15 () ;
if ( ! V_1 || ! V_11 ) {
V_28 = - V_45 ;
goto V_46;
}
V_1 -> V_5 = V_5 ;
V_1 -> V_11 = V_11 ;
V_11 -> V_47 = V_5 -> V_47 ;
V_11 -> V_18 . V_48 = & V_5 -> V_18 ;
V_11 -> V_37 . V_49 = V_50 ;
F_16 ( V_11 , V_19 , V_20 ) ;
V_28 = F_17 ( V_39 -> V_51 , NULL ,
V_52 , V_53 ,
V_1 -> V_21 , V_11 ) ;
if ( V_28 )
goto V_46;
if ( V_39 -> V_43 ) {
V_28 = F_3 ( V_1 , V_54 ,
V_39 -> V_43 / 3 ) ;
if ( V_28 )
F_18 ( & V_5 -> V_18 , L_4 ) ;
}
if ( V_39 -> V_41 ) {
V_28 = F_3 ( V_1 , V_55 ,
V_39 -> V_41 / 3 ) ;
if ( V_28 )
F_18 ( & V_5 -> V_18 , L_5 ) ;
}
V_28 = F_19 ( V_5 -> V_22 , NULL , F_12 ,
V_56 | V_57 ,
L_6 , V_1 ) ;
if ( V_28 )
goto V_46;
V_28 = F_20 ( V_11 ) ;
if ( V_28 )
goto V_58;
F_21 ( V_5 , V_1 ) ;
return 0 ;
V_58:
V_58 ( V_5 -> V_22 , V_1 ) ;
V_46:
F_22 ( V_11 ) ;
F_23 ( V_1 ) ;
return V_28 ;
}
static int F_24 ( struct V_35 * V_5 )
{
struct V_1 * V_1 = F_25 ( V_5 ) ;
V_58 ( V_5 -> V_22 , V_1 ) ;
F_26 ( V_1 -> V_11 ) ;
F_23 ( V_1 ) ;
return 0 ;
}
