static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 , V_8 , V_9 ;
for ( V_7 = 0 ; V_7 < V_10 && V_6 -> V_11 [ V_7 ] ; V_7 ++ ) {
V_8 = F_4 ( V_6 -> V_11 [ V_7 ] ) ;
if ( V_8 )
goto V_12;
}
for ( V_9 = 0 ; V_9 < V_6 -> V_13 ; V_9 ++ ) {
V_8 = F_5 ( V_6 -> V_14 [ V_9 ] ) ;
if ( V_8 )
goto V_15;
V_8 = F_6 ( V_6 -> V_14 [ V_9 ] ) ;
if ( V_8 ) {
F_7 ( V_6 -> V_14 [ V_9 ] ) ;
goto V_15;
}
}
return 0 ;
V_15:
while ( -- V_9 >= 0 ) {
F_8 ( V_6 -> V_14 [ V_9 ] ) ;
F_7 ( V_6 -> V_14 [ V_9 ] ) ;
}
V_12:
while ( -- V_7 >= 0 )
F_9 ( V_6 -> V_11 [ V_7 ] ) ;
return V_8 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 , V_9 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_13 ; V_9 ++ ) {
F_8 ( V_6 -> V_14 [ V_9 ] ) ;
F_7 ( V_6 -> V_14 [ V_9 ] ) ;
}
for ( V_7 = V_10 - 1 ; V_7 >= 0 ; V_7 -- )
if ( V_6 -> V_11 [ V_7 ] )
F_9 ( V_6 -> V_11 [ V_7 ] ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_16 * V_17 ;
struct V_18 * V_19 = F_12 ( & V_2 -> V_2 ) ;
struct V_5 * V_6 ;
struct V_20 * V_21 ;
int V_22 , V_23 , V_9 , V_7 = 0 ;
if ( F_13 () )
return - V_24 ;
if ( ! V_19 )
V_19 = & V_25 ;
V_22 = F_14 ( & V_2 -> V_2 , F_15 ( 32 ) ) ;
if ( V_22 )
return V_22 ;
V_23 = F_16 ( V_2 , 0 ) ;
if ( V_23 < 0 ) {
F_17 ( & V_2 -> V_2 , L_1 ) ;
return V_23 ;
}
V_4 = F_18 ( & V_26 , & V_2 -> V_2 ,
F_19 ( & V_2 -> V_2 ) ) ;
if ( ! V_4 )
return - V_27 ;
F_20 ( V_2 , V_4 ) ;
V_2 -> V_2 . V_28 = V_19 ;
V_6 = F_3 ( V_4 ) ;
V_21 = F_21 ( V_4 ) ;
if ( V_19 == & V_25 && V_2 -> V_2 . V_29 ) {
if ( F_22 ( V_2 -> V_2 . V_29 , L_2 ) )
V_21 -> V_30 |= V_31 ;
if ( F_22 ( V_2 -> V_2 . V_29 , L_3 ) )
V_21 -> V_30 |= V_32 ;
if ( F_22 ( V_2 -> V_2 . V_29 , L_4 ) )
V_21 -> V_30 |= V_31 | V_32 ;
if ( F_22 ( V_2 -> V_2 . V_29 , L_5 ) )
V_21 -> V_30 |= V_33 ;
F_23 ( V_2 -> V_2 . V_29 , L_6 ,
& V_21 -> V_34 ) ;
V_6 -> V_13 = F_24 ( V_2 -> V_2 . V_29 ,
L_7 , L_8 ) ;
if ( V_6 -> V_13 > 0 ) {
V_6 -> V_14 = F_25 ( & V_2 -> V_2 , V_6 -> V_13 ,
sizeof( struct V_35 * ) , V_36 ) ;
if ( ! V_6 -> V_14 )
return - V_27 ;
} else
V_6 -> V_13 = 0 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_13 ; V_9 ++ ) {
V_6 -> V_14 [ V_9 ] = F_26 (
& V_2 -> V_2 , V_2 -> V_2 . V_29 , V_9 ) ;
if ( F_27 ( V_6 -> V_14 [ V_9 ] ) ) {
V_22 = F_28 ( V_6 -> V_14 [ V_9 ] ) ;
goto V_37;
}
}
for ( V_7 = 0 ; V_7 < V_10 ; V_7 ++ ) {
V_6 -> V_11 [ V_7 ] = F_29 ( V_2 -> V_2 . V_29 , V_7 ) ;
if ( F_27 ( V_6 -> V_11 [ V_7 ] ) ) {
V_22 = F_28 ( V_6 -> V_11 [ V_7 ] ) ;
if ( V_22 == - V_38 )
goto V_39;
V_6 -> V_11 [ V_7 ] = NULL ;
break;
}
}
}
V_6 -> V_40 = F_30 ( & V_2 -> V_2 , NULL ) ;
if ( F_27 ( V_6 -> V_40 ) ) {
V_22 = F_28 ( V_6 -> V_40 ) ;
if ( V_22 == - V_38 )
goto V_39;
V_6 -> V_40 = NULL ;
} else {
V_22 = F_31 ( V_6 -> V_40 ) ;
if ( V_22 )
goto V_39;
}
if ( V_19 -> V_41 )
V_21 -> V_30 |= V_32 ;
if ( V_19 -> V_42 )
V_21 -> V_30 |= V_31 ;
if ( V_19 -> V_43 )
V_21 -> V_30 |= V_33 ;
if ( V_19 -> V_34 )
V_21 -> V_34 = V_19 -> V_34 ;
#ifndef F_32
if ( V_21 -> V_30 & V_31 ) {
F_17 ( & V_2 -> V_2 ,
L_9 ) ;
V_22 = - V_44 ;
goto V_45;
}
#endif
#ifndef F_33
if ( V_21 -> V_30 & V_32 ) {
F_17 ( & V_2 -> V_2 ,
L_10 ) ;
V_22 = - V_44 ;
goto V_45;
}
#endif
if ( V_19 -> V_46 ) {
V_22 = V_19 -> V_46 ( V_2 ) ;
if ( V_22 < 0 )
goto V_45;
}
V_17 = F_34 ( V_2 , V_47 , 0 ) ;
V_4 -> V_48 = F_35 ( & V_2 -> V_2 , V_17 ) ;
if ( F_27 ( V_4 -> V_48 ) ) {
V_22 = F_28 ( V_4 -> V_48 ) ;
goto V_49;
}
V_4 -> V_50 = V_17 -> V_51 ;
V_4 -> V_52 = F_36 ( V_17 ) ;
V_22 = F_37 ( V_4 , V_23 , V_53 ) ;
if ( V_22 )
goto V_49;
F_38 ( V_4 -> V_54 . V_55 ) ;
F_20 ( V_2 , V_4 ) ;
return V_22 ;
V_49:
if ( V_19 -> V_56 )
V_19 -> V_56 ( V_2 ) ;
V_45:
if ( V_6 -> V_40 )
F_39 ( V_6 -> V_40 ) ;
V_39:
while ( -- V_7 >= 0 )
F_40 ( V_6 -> V_11 [ V_7 ] ) ;
V_37:
if ( V_19 == & V_25 )
V_2 -> V_2 . V_28 = NULL ;
F_41 ( V_4 ) ;
return V_22 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_18 * V_19 = F_12 ( & V_2 -> V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
F_43 ( V_4 ) ;
if ( V_19 -> V_56 )
V_19 -> V_56 ( V_2 ) ;
if ( V_6 -> V_40 )
F_39 ( V_6 -> V_40 ) ;
for ( V_7 = 0 ; V_7 < V_10 && V_6 -> V_11 [ V_7 ] ; V_7 ++ )
F_40 ( V_6 -> V_11 [ V_7 ] ) ;
F_41 ( V_4 ) ;
if ( V_19 == & V_25 )
V_2 -> V_2 . V_28 = NULL ;
return 0 ;
}
static int F_44 ( struct V_57 * V_2 )
{
struct V_3 * V_4 = F_45 ( V_2 ) ;
struct V_18 * V_19 = V_2 -> V_28 ;
struct V_1 * V_58 =
F_46 ( V_2 , struct V_1 , V_2 ) ;
bool V_59 = F_47 ( V_2 ) ;
int V_8 ;
V_8 = F_48 ( V_4 , V_59 ) ;
if ( V_8 )
return V_8 ;
if ( V_19 -> V_60 )
V_19 -> V_60 ( V_58 ) ;
return V_8 ;
}
static int F_49 ( struct V_57 * V_2 )
{
struct V_3 * V_4 = F_45 ( V_2 ) ;
struct V_18 * V_19 = F_12 ( V_2 ) ;
struct V_1 * V_58 =
F_46 ( V_2 , struct V_1 , V_2 ) ;
if ( V_19 -> V_46 ) {
int V_22 = V_19 -> V_46 ( V_58 ) ;
if ( V_22 < 0 )
return V_22 ;
}
F_50 ( V_4 , false ) ;
return 0 ;
}
static int T_1 F_51 ( void )
{
if ( F_13 () )
return - V_24 ;
F_52 ( L_11 V_61 L_12 , V_62 ) ;
F_53 ( & V_26 , & V_63 ) ;
return F_54 ( & V_64 ) ;
}
static void T_2 F_55 ( void )
{
F_56 ( & V_64 ) ;
}
