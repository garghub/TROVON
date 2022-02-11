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
V_2 = F_22 ( & V_36 , & V_9 -> V_9 ,
F_23 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 )
return - V_37 ;
F_24 ( V_9 , V_2 ) ;
V_9 -> V_9 . V_38 = V_8 ;
V_22 = F_8 ( V_2 ) ;
V_11 = F_4 ( V_2 ) ;
if ( V_8 == & V_35 && V_9 -> V_9 . V_39 ) {
if ( F_25 ( V_9 -> V_9 . V_39 , L_2 ) )
V_11 -> V_40 = 1 ;
if ( F_25 ( V_9 -> V_9 . V_39 , L_3 ) )
V_11 -> V_41 = 1 ;
if ( F_25 ( V_9 -> V_9 . V_39 , L_4 ) )
V_11 -> V_40 = V_11 -> V_41 = 1 ;
V_22 -> V_28 = F_26 ( & V_9 -> V_9 , L_5 ) ;
if ( F_27 ( V_22 -> V_28 ) ) {
V_32 = F_28 ( V_22 -> V_28 ) ;
if ( V_32 == - V_42 )
goto V_43;
V_22 -> V_28 = NULL ;
}
for ( V_23 = 0 ; V_23 < V_25 ; V_23 ++ ) {
V_22 -> V_26 [ V_23 ] = F_29 ( V_9 -> V_9 . V_39 , V_23 ) ;
if ( F_27 ( V_22 -> V_26 [ V_23 ] ) ) {
V_32 = F_28 ( V_22 -> V_26 [ V_23 ] ) ;
if ( V_32 == - V_42 )
goto V_44;
V_22 -> V_26 [ V_23 ] = NULL ;
break;
}
}
}
V_22 -> V_45 = F_30 ( & V_9 -> V_9 , NULL ) ;
if ( F_27 ( V_22 -> V_45 ) ) {
V_32 = F_28 ( V_22 -> V_45 ) ;
if ( V_32 == - V_42 )
goto V_44;
V_22 -> V_45 = NULL ;
} else {
V_32 = F_31 ( V_22 -> V_45 ) ;
if ( V_32 )
goto V_44;
}
if ( V_8 -> V_41 )
V_11 -> V_41 = 1 ;
if ( V_8 -> V_40 )
V_11 -> V_40 = 1 ;
#ifndef F_32
if ( V_11 -> V_40 ) {
F_21 ( & V_9 -> V_9 ,
L_6 ) ;
V_32 = - V_46 ;
goto V_47;
}
#endif
#ifndef F_33
if ( V_11 -> V_41 ) {
F_21 ( & V_9 -> V_9 ,
L_7 ) ;
V_32 = - V_46 ;
goto V_47;
}
#endif
if ( V_8 -> V_48 ) {
V_32 = V_8 -> V_48 ( V_9 ) ;
if ( V_32 < 0 )
goto V_47;
}
V_31 = F_34 ( V_9 , V_49 , 0 ) ;
V_2 -> V_17 = F_35 ( & V_9 -> V_9 , V_31 ) ;
if ( F_27 ( V_2 -> V_17 ) ) {
V_32 = F_28 ( V_2 -> V_17 ) ;
goto V_50;
}
V_2 -> V_51 = V_31 -> V_52 ;
V_2 -> V_53 = F_36 ( V_31 ) ;
V_32 = F_37 ( V_2 , V_33 , V_54 ) ;
if ( V_32 )
goto V_50;
F_38 ( V_2 -> V_5 . V_6 ) ;
F_24 ( V_9 , V_2 ) ;
return V_32 ;
V_50:
if ( V_8 -> V_55 )
V_8 -> V_55 ( V_9 ) ;
V_47:
if ( V_22 -> V_45 )
F_39 ( V_22 -> V_45 ) ;
V_44:
while ( -- V_23 >= 0 )
F_40 ( V_22 -> V_26 [ V_23 ] ) ;
V_43:
if ( V_8 == & V_35 )
V_9 -> V_9 . V_38 = NULL ;
F_41 ( V_2 ) ;
return V_32 ;
}
static int F_42 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( & V_9 -> V_9 ) ;
struct V_21 * V_22 = F_8 ( V_2 ) ;
int V_23 ;
F_43 ( V_2 ) ;
if ( V_8 -> V_55 )
V_8 -> V_55 ( V_9 ) ;
if ( V_22 -> V_45 )
F_39 ( V_22 -> V_45 ) ;
for ( V_23 = 0 ; V_23 < V_25 && V_22 -> V_26 [ V_23 ] ; V_23 ++ )
F_40 ( V_22 -> V_26 [ V_23 ] ) ;
F_41 ( V_2 ) ;
if ( V_8 == & V_35 )
V_9 -> V_9 . V_38 = NULL ;
return 0 ;
}
static int F_44 ( struct V_56 * V_9 )
{
struct V_1 * V_2 = F_45 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 =
F_46 ( V_9 , struct V_3 , V_9 ) ;
bool V_57 = F_47 ( V_9 ) ;
int V_24 ;
V_24 = F_48 ( V_2 , V_57 ) ;
if ( V_24 )
return V_24 ;
if ( V_8 -> V_58 )
V_8 -> V_58 ( V_4 ) ;
return V_24 ;
}
static int F_49 ( struct V_56 * V_9 )
{
struct V_1 * V_2 = F_45 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 =
F_46 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_48 ) {
int V_32 = V_8 -> V_48 ( V_4 ) ;
if ( V_32 < 0 )
return V_32 ;
}
F_50 ( V_2 , false ) ;
return 0 ;
}
static int T_1 F_51 ( void )
{
if ( F_17 () )
return - V_34 ;
F_52 ( L_8 V_59 L_9 , V_60 ) ;
F_53 ( & V_36 , & V_61 ) ;
return F_54 ( & V_62 ) ;
}
static void T_2 F_55 ( void )
{
F_56 ( & V_62 ) ;
}
