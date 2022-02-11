static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_7 * V_8 = F_3 ( & V_4 -> V_9 ) ;
struct V_10 * V_11 = F_4 ( V_2 ) ;
int V_12 ;
V_2 -> V_13 = V_8 -> V_13 ;
V_11 -> V_14 = V_8 -> V_14 ;
if ( V_8 -> V_15 ) {
V_12 = V_8 -> V_15 ( V_2 ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_11 -> V_16 = V_2 -> V_17 + V_8 -> V_18 ;
V_12 = F_5 ( V_2 ) ;
if ( V_12 )
return V_12 ;
if ( V_8 -> V_19 )
V_11 -> V_20 = 0 ;
return 0 ;
}
static int F_6 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_21 * V_22 = F_8 ( V_2 ) ;
int V_23 , V_24 ;
for ( V_23 = 0 ; V_23 < V_25 && V_22 -> V_26 [ V_23 ] ; V_23 ++ ) {
V_24 = F_9 ( V_22 -> V_26 [ V_23 ] ) ;
if ( V_24 )
goto V_27;
}
if ( V_22 -> V_28 ) {
V_24 = F_10 ( V_22 -> V_28 ) ;
if ( V_24 )
goto V_27;
V_24 = F_11 ( V_22 -> V_28 ) ;
if ( V_24 )
goto V_29;
}
return 0 ;
V_29:
F_12 ( V_22 -> V_28 ) ;
V_27:
while ( -- V_23 >= 0 )
F_13 ( V_22 -> V_26 [ V_23 ] ) ;
return V_24 ;
}
static void F_14 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_21 * V_22 = F_8 ( V_2 ) ;
int V_23 ;
if ( V_22 -> V_28 ) {
F_15 ( V_22 -> V_28 ) ;
F_12 ( V_22 -> V_28 ) ;
}
for ( V_23 = V_25 - 1 ; V_23 >= 0 ; V_23 -- )
if ( V_22 -> V_26 [ V_23 ] )
F_13 ( V_22 -> V_26 [ V_23 ] ) ;
}
static int F_16 ( struct V_3 * V_9 )
{
struct V_1 * V_2 ;
struct V_30 * V_31 ;
struct V_7 * V_8 = F_3 ( & V_9 -> V_9 ) ;
struct V_21 * V_22 ;
struct V_10 * V_11 ;
int V_32 , V_33 , V_23 = 0 ;
if ( F_17 () )
return - V_34 ;
if ( ! V_8 )
V_8 = & V_35 ;
V_32 = F_18 ( & V_9 -> V_9 , F_19 ( 32 ) ) ;
if ( V_32 )
return V_32 ;
V_33 = F_20 ( V_9 , 0 ) ;
if ( V_33 < 0 ) {
F_21 ( & V_9 -> V_9 , L_1 ) ;
return V_33 ;
}
V_31 = F_22 ( V_9 , V_36 , 0 ) ;
if ( ! V_31 ) {
F_21 ( & V_9 -> V_9 , L_2 ) ;
return - V_37 ;
}
V_2 = F_23 ( & V_38 , & V_9 -> V_9 ,
F_24 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 )
return - V_39 ;
F_25 ( V_9 , V_2 ) ;
V_9 -> V_9 . V_40 = V_8 ;
V_22 = F_8 ( V_2 ) ;
V_11 = F_4 ( V_2 ) ;
if ( V_8 == & V_35 && V_9 -> V_9 . V_41 ) {
if ( F_26 ( V_9 -> V_9 . V_41 , L_3 ) )
V_11 -> V_42 = 1 ;
if ( F_26 ( V_9 -> V_9 . V_41 , L_4 ) )
V_11 -> V_43 = 1 ;
if ( F_26 ( V_9 -> V_9 . V_41 , L_5 ) )
V_11 -> V_42 = V_11 -> V_43 = 1 ;
V_22 -> V_28 = F_27 ( & V_9 -> V_9 , L_6 ) ;
if ( F_28 ( V_22 -> V_28 ) ) {
V_32 = F_29 ( V_22 -> V_28 ) ;
if ( V_32 == - V_44 )
goto V_45;
V_22 -> V_28 = NULL ;
}
for ( V_23 = 0 ; V_23 < V_25 ; V_23 ++ ) {
V_22 -> V_26 [ V_23 ] = F_30 ( V_9 -> V_9 . V_41 , V_23 ) ;
if ( F_28 ( V_22 -> V_26 [ V_23 ] ) ) {
V_32 = F_29 ( V_22 -> V_26 [ V_23 ] ) ;
if ( V_32 == - V_44 )
goto V_46;
V_22 -> V_26 [ V_23 ] = NULL ;
break;
}
}
}
if ( V_8 -> V_43 )
V_11 -> V_43 = 1 ;
if ( V_8 -> V_42 )
V_11 -> V_42 = 1 ;
#ifndef F_31
if ( V_11 -> V_42 ) {
F_21 ( & V_9 -> V_9 ,
L_7 ) ;
V_32 = - V_47 ;
goto V_46;
}
#endif
#ifndef F_32
if ( V_11 -> V_43 ) {
F_21 ( & V_9 -> V_9 ,
L_8 ) ;
V_32 = - V_47 ;
goto V_46;
}
#endif
if ( V_8 -> V_48 ) {
V_32 = V_8 -> V_48 ( V_9 ) ;
if ( V_32 < 0 )
goto V_46;
}
V_2 -> V_49 = V_31 -> V_50 ;
V_2 -> V_51 = F_33 ( V_31 ) ;
V_2 -> V_17 = F_34 ( & V_9 -> V_9 , V_31 ) ;
if ( F_28 ( V_2 -> V_17 ) ) {
V_32 = F_29 ( V_2 -> V_17 ) ;
goto V_52;
}
V_32 = F_35 ( V_2 , V_33 , V_53 ) ;
if ( V_32 )
goto V_52;
F_36 ( V_2 -> V_5 . V_6 ) ;
F_25 ( V_9 , V_2 ) ;
return V_32 ;
V_52:
if ( V_8 -> V_54 )
V_8 -> V_54 ( V_9 ) ;
V_46:
while ( -- V_23 >= 0 )
F_37 ( V_22 -> V_26 [ V_23 ] ) ;
V_45:
if ( V_8 == & V_35 )
V_9 -> V_9 . V_40 = NULL ;
F_38 ( V_2 ) ;
return V_32 ;
}
static int F_39 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( & V_9 -> V_9 ) ;
struct V_21 * V_22 = F_8 ( V_2 ) ;
int V_23 ;
F_40 ( V_2 ) ;
if ( V_8 -> V_54 )
V_8 -> V_54 ( V_9 ) ;
for ( V_23 = 0 ; V_23 < V_25 && V_22 -> V_26 [ V_23 ] ; V_23 ++ )
F_37 ( V_22 -> V_26 [ V_23 ] ) ;
F_38 ( V_2 ) ;
if ( V_8 == & V_35 )
V_9 -> V_9 . V_40 = NULL ;
return 0 ;
}
static int F_41 ( struct V_55 * V_9 )
{
struct V_1 * V_2 = F_42 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 =
F_43 ( V_9 , struct V_3 , V_9 ) ;
bool V_56 = F_44 ( V_9 ) ;
int V_24 ;
V_24 = F_45 ( V_2 , V_56 ) ;
if ( V_24 )
return V_24 ;
if ( V_8 -> V_57 )
V_8 -> V_57 ( V_4 ) ;
return V_24 ;
}
static int F_46 ( struct V_55 * V_9 )
{
struct V_1 * V_2 = F_42 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 =
F_43 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_48 ) {
int V_32 = V_8 -> V_48 ( V_4 ) ;
if ( V_32 < 0 )
return V_32 ;
}
F_47 ( V_2 , false ) ;
return 0 ;
}
static int T_1 F_48 ( void )
{
if ( F_17 () )
return - V_34 ;
F_49 ( L_9 V_58 L_10 , V_59 ) ;
F_50 ( & V_38 , & V_60 ) ;
return F_51 ( & V_61 ) ;
}
static void T_2 F_52 ( void )
{
F_53 ( & V_61 ) ;
}
