static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_9 ;
struct V_10 * V_11 ;
if ( ! V_7 )
return - V_12 ;
* V_5 = F_2 ( V_7 ) ;
V_4 -> V_13 = F_3 ( V_7 ) ;
V_4 -> V_14 = F_4 ( V_7 , L_1 ) ;
if ( V_4 -> V_14 < 0 )
V_4 -> V_14 = 0 ;
V_4 -> V_15 = F_5 ( & V_2 -> V_8 ,
sizeof( * V_4 -> V_15 ) ,
V_16 ) ;
V_11 = F_5 ( & V_2 -> V_8 , sizeof( * V_11 ) , V_16 ) ;
if ( ! V_11 )
return - V_17 ;
V_4 -> V_11 = V_11 ;
F_6 ( V_7 , L_2 , & V_11 -> V_18 ) ;
if ( F_6 ( V_7 , L_3 , & V_11 -> V_19 ) == 0 )
V_11 -> V_20 = true ;
return 0 ;
}
static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * * V_5 )
{
return - V_21 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_22 ;
int V_23 , V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_8 = & V_2 -> V_8 ;
void T_1 * V_28 ;
struct V_29 * V_30 = NULL ;
struct V_3 * V_31 = NULL ;
const char * V_5 = NULL ;
struct V_32 * V_33 = F_8 ( V_2 ) ;
struct V_6 * V_34 = V_8 -> V_9 ;
V_26 = F_9 ( V_2 , V_35 , 0 ) ;
if ( ! V_26 )
goto V_36;
V_28 = F_10 ( V_8 , V_26 ) ;
if ( F_11 ( V_28 ) )
return F_12 ( V_28 ) ;
if ( V_2 -> V_8 . V_9 ) {
V_31 = F_5 ( & V_2 -> V_8 ,
sizeof( struct V_3 ) ,
V_16 ) ;
if ( ! V_31 )
return - V_17 ;
V_22 = F_1 ( V_2 , V_31 , & V_5 ) ;
if ( V_22 ) {
F_13 ( L_4 , V_37 ) ;
return V_22 ;
}
}
if ( V_5 )
F_14 ( V_30 -> V_8 -> V_38 , V_5 ) ;
V_30 = F_15 ( & ( V_2 -> V_8 ) , V_31 , V_28 ) ;
if ( ! V_30 ) {
F_13 ( L_5 , V_37 ) ;
goto V_36;
}
V_30 -> V_39 = F_16 ( V_34 , 0 ) ;
if ( V_30 -> V_39 <= 0 ) {
F_17 ( V_8 , L_6 ) ;
goto V_40;
}
for ( V_23 = 0 , V_24 = 1 ; V_23 < V_41 ; V_23 ++ ) {
V_30 -> V_42 [ V_23 ] -> V_43 = F_16 ( V_34 , V_24 ++ ) ;
if ( V_30 -> V_42 [ V_23 ] -> V_43 <= 0 ) {
F_17 ( V_8 , L_7 ) ;
goto V_44;
}
}
for ( V_23 = 0 ; V_23 < V_45 ; V_23 ++ ) {
V_30 -> V_46 [ V_23 ] -> V_43 = F_16 ( V_34 , V_24 ++ ) ;
if ( V_30 -> V_46 [ V_23 ] -> V_43 <= 0 ) {
F_17 ( V_8 , L_8 ) ;
goto V_47;
}
}
V_30 -> V_48 = F_16 ( V_34 , V_24 ) ;
if ( V_30 -> V_48 <= 0 ) {
F_17 ( V_8 , L_9 ) ;
goto V_47;
}
F_18 ( V_2 , V_30 -> V_8 ) ;
F_19 ( L_10 ) ;
return 0 ;
V_47:
while ( -- V_23 )
F_20 ( V_30 -> V_46 [ V_23 ] -> V_43 ) ;
V_23 = V_41 ;
V_44:
while ( -- V_23 )
F_20 ( V_30 -> V_42 [ V_23 ] -> V_43 ) ;
F_20 ( V_30 -> V_39 ) ;
V_40:
F_21 ( V_33 ) ;
V_36:
return - V_12 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_8 ( V_2 ) ;
int V_22 = F_21 ( V_33 ) ;
return V_22 ;
}
static int F_23 ( struct V_27 * V_8 )
{
struct V_32 * V_33 = F_24 ( V_8 ) ;
return F_25 ( V_33 ) ;
}
static int F_26 ( struct V_27 * V_8 )
{
struct V_32 * V_33 = F_24 ( V_8 ) ;
return F_27 ( V_33 ) ;
}
static int F_28 ( struct V_27 * V_8 )
{
struct V_32 * V_33 = F_24 ( V_8 ) ;
return F_29 ( V_33 ) ;
}
static int F_30 ( struct V_27 * V_8 )
{
struct V_32 * V_33 = F_24 ( V_8 ) ;
return F_31 ( V_33 ) ;
}
int F_32 ( void )
{
int V_49 ;
V_49 = F_33 ( & V_50 ) ;
if ( V_49 )
F_13 ( L_11 ) ;
return V_49 ;
}
void F_34 ( void )
{
F_35 ( & V_50 ) ;
}
