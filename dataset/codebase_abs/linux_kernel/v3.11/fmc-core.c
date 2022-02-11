static int F_1 ( unsigned long V_1 , const char * V_2 )
{
if ( F_2 ( V_1 ) != V_3 ) {
F_3 ( L_1 ,
V_4 , V_2 , F_2 ( V_1 ) , V_3 ) ;
return - V_5 ;
}
if ( F_4 ( V_1 ) != V_6 )
F_5 ( L_2 ,
V_4 , V_2 , F_4 ( V_1 ) , V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
F_7 ( V_10 , L_3 , L_4 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_9 ( V_8 -> V_13 ) ;
struct V_14 * V_15 = F_10 ( V_8 ) ;
return V_12 -> V_16 ( V_15 ) ;
}
static int F_11 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_9 ( V_8 -> V_13 ) ;
struct V_14 * V_15 = F_10 ( V_8 ) ;
return V_12 -> remove ( V_15 ) ;
}
static void F_12 ( struct V_7 * V_8 )
{
}
static void F_13 ( struct V_7 * V_8 )
{
struct V_14 * V_17 = F_14 ( V_8 , struct V_14 , V_8 ) ;
F_15 ( V_17 ) ;
}
static T_1 F_16 ( struct V_18 * V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 ,
char * V_23 , T_2 V_24 , T_3 V_25 )
{
struct V_7 * V_8 ;
struct V_14 * V_17 ;
int V_26 ;
V_8 = F_14 ( V_20 , struct V_7 , V_20 ) ;
V_17 = F_14 ( V_8 , struct V_14 , V_8 ) ;
V_26 = V_17 -> V_27 ;
if ( V_24 > V_26 )
return - V_28 ;
if ( V_24 == V_26 )
return 0 ;
if ( V_24 + V_25 > V_26 )
V_25 = V_26 - V_24 ;
memcpy ( V_23 , V_17 -> V_29 + V_24 , V_25 ) ;
return V_25 ;
}
int F_17 ( struct V_11 * V_30 )
{
if ( F_1 ( V_30 -> V_1 , V_30 -> V_13 . V_2 ) )
return - V_5 ;
V_30 -> V_13 . V_31 = & V_32 ;
return F_18 ( & V_30 -> V_13 ) ;
}
void F_19 ( struct V_11 * V_30 )
{
F_20 ( & V_30 -> V_13 ) ;
}
int F_21 ( struct V_14 * * V_33 , int V_34 )
{
struct V_14 * V_17 , * * V_35 ;
T_4 V_36 ;
int V_37 , V_38 = 0 ;
if ( V_34 < 1 )
return 0 ;
if ( F_1 ( V_33 [ 0 ] -> V_1 , V_33 [ 0 ] -> V_39 ) )
return - V_5 ;
V_35 = F_22 ( V_33 , V_34 * sizeof( * V_33 ) , V_40 ) ;
if ( ! V_35 )
return - V_41 ;
for ( V_37 = 0 ; V_37 < V_34 ; V_37 ++ ) {
V_17 = V_35 [ V_37 ] ;
if ( ! V_17 -> V_42 ) {
F_3 ( L_5 ,
V_4 , V_37 ) ;
V_38 = - V_5 ;
break;
}
if ( V_17 -> V_43 == V_44 ) {
F_23 ( V_17 -> V_42 , L_6 ,
V_17 -> V_45 ) ;
continue;
}
if ( ! V_17 -> V_29 ) {
F_24 ( V_17 -> V_42 , L_7 ,
V_17 -> V_45 ) ;
V_38 = - V_5 ;
}
if ( ! V_17 -> V_46 ) {
F_24 ( V_17 -> V_42 , L_8 ,
V_17 -> V_45 ) ;
V_38 = - V_5 ;
}
if ( ! V_17 -> V_39 || ! V_17 -> V_47 ||
! V_17 -> V_36 ) {
F_24 ( V_17 -> V_42 ,
L_9
L_10 , V_37 ) ;
V_38 = - V_5 ;
}
if ( V_38 )
break;
}
if ( V_38 ) {
F_15 ( V_35 ) ;
return V_38 ;
}
for ( V_37 = 0 ; V_37 < V_34 ; V_37 ++ ) {
V_17 = V_35 [ V_37 ] ;
if ( V_17 -> V_43 == V_44 )
continue;
V_17 -> V_48 = V_34 ;
V_17 -> V_35 = V_35 ;
F_25 ( & V_17 -> V_8 ) ;
V_17 -> V_8 . V_49 = F_13 ;
V_17 -> V_8 . V_50 = V_17 -> V_42 ;
F_26 ( V_17 ) ;
V_17 -> V_8 . V_31 = & V_32 ;
V_36 = V_17 -> V_36 ;
if ( ! V_17 -> V_51 )
F_27 ( & V_17 -> V_8 , L_11 , V_36 ) ;
else
F_27 ( & V_17 -> V_8 , L_12 , V_17 -> V_51 ,
V_36 ) ;
V_38 = F_28 ( & V_17 -> V_8 ) ;
if ( V_38 < 0 ) {
F_24 ( V_17 -> V_42 , L_13
L_14 , V_17 -> V_45 , V_17 -> V_8 . V_20 . V_2 ) ;
goto V_52;
}
V_38 = F_29 ( & V_17 -> V_8 . V_20 , & V_53 ) ;
if ( V_38 < 0 ) {
F_24 ( & V_17 -> V_8 , L_15 ) ;
goto V_54;
}
F_30 ( V_17 ) ;
F_31 ( V_17 ) ;
}
return 0 ;
V_54:
F_32 ( & V_17 -> V_8 ) ;
V_52:
F_33 ( V_17 ) ;
F_34 ( & V_17 -> V_8 ) ;
F_15 ( V_35 ) ;
for ( V_37 -- ; V_37 >= 0 ; V_37 -- ) {
F_35 ( & V_33 [ V_37 ] -> V_8 . V_20 , & V_53 ) ;
F_32 ( & V_33 [ V_37 ] -> V_8 ) ;
F_33 ( V_33 [ V_37 ] ) ;
F_34 ( & V_33 [ V_37 ] -> V_8 ) ;
}
return V_38 ;
}
int F_36 ( struct V_14 * V_17 )
{
return F_21 ( & V_17 , 1 ) ;
}
void F_37 ( struct V_14 * * V_33 , int V_34 )
{
int V_37 ;
if ( V_34 < 1 )
return;
F_15 ( V_33 [ 0 ] -> V_35 ) ;
for ( V_37 = 0 ; V_37 < V_34 ; V_37 ++ ) {
if ( V_33 [ V_37 ] -> V_43 == V_44 )
continue;
F_35 ( & V_33 [ V_37 ] -> V_8 . V_20 , & V_53 ) ;
F_32 ( & V_33 [ V_37 ] -> V_8 ) ;
F_33 ( V_33 [ V_37 ] ) ;
F_34 ( & V_33 [ V_37 ] -> V_8 ) ;
}
}
void F_38 ( struct V_14 * V_17 )
{
F_37 ( & V_17 , 1 ) ;
}
static int F_39 ( void )
{
return F_40 ( & V_32 ) ;
}
static void F_41 ( void )
{
F_42 ( & V_32 ) ;
}
