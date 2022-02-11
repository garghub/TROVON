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
static T_1 F_17 ( struct V_18 * V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 ,
char * V_23 , T_2 V_24 , T_3 V_25 )
{
struct V_7 * V_8 ;
struct V_14 * V_17 ;
V_8 = F_14 ( V_20 , struct V_7 , V_20 ) ;
V_17 = F_14 ( V_8 , struct V_14 , V_8 ) ;
return V_17 -> V_30 -> V_31 ( V_17 , V_24 , V_23 , V_25 ) ;
}
int F_18 ( struct V_11 * V_32 )
{
if ( F_1 ( V_32 -> V_1 , V_32 -> V_13 . V_2 ) )
return - V_5 ;
V_32 -> V_13 . V_33 = & V_34 ;
return F_19 ( & V_32 -> V_13 ) ;
}
void F_20 ( struct V_11 * V_32 )
{
F_21 ( & V_32 -> V_13 ) ;
}
int F_22 ( struct V_14 * * V_35 , int V_36 )
{
struct V_14 * V_17 , * * V_37 ;
T_4 V_38 ;
int V_39 , V_40 = 0 ;
if ( V_36 < 1 )
return 0 ;
if ( F_1 ( V_35 [ 0 ] -> V_1 , V_35 [ 0 ] -> V_41 ) )
return - V_5 ;
V_37 = F_23 ( V_35 , V_36 * sizeof( * V_35 ) , V_42 ) ;
if ( ! V_37 )
return - V_43 ;
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
V_17 = V_37 [ V_39 ] ;
if ( ! V_17 -> V_44 ) {
F_3 ( L_5 ,
V_4 , V_39 ) ;
V_40 = - V_5 ;
break;
}
if ( V_17 -> V_45 & V_46 ) {
F_24 ( V_17 -> V_44 , L_6 ,
V_17 -> V_47 ) ;
continue;
}
if ( ! V_17 -> V_29 ) {
F_25 ( V_17 -> V_44 , L_7 ,
V_17 -> V_47 ) ;
V_40 = - V_5 ;
}
if ( ! V_17 -> V_48 ) {
F_25 ( V_17 -> V_44 , L_8 ,
V_17 -> V_47 ) ;
V_40 = - V_5 ;
}
if ( ! V_17 -> V_41 || ! V_17 -> V_49 ||
! V_17 -> V_38 ) {
F_25 ( V_17 -> V_44 ,
L_9
L_10 , V_39 ) ;
V_40 = - V_5 ;
}
if ( V_40 )
break;
}
if ( V_40 ) {
F_15 ( V_37 ) ;
return V_40 ;
}
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
V_17 = V_37 [ V_39 ] ;
V_17 -> V_50 = V_36 ;
V_17 -> V_37 = V_37 ;
F_26 ( & V_17 -> V_8 ) ;
V_17 -> V_8 . V_51 = F_13 ;
V_17 -> V_8 . V_52 = V_17 -> V_44 ;
F_27 ( V_17 ) ;
V_17 -> V_8 . V_33 = & V_34 ;
V_38 = V_17 -> V_38 ;
if ( ! V_17 -> V_53 )
F_28 ( & V_17 -> V_8 , L_11 , V_38 ) ;
else
F_28 ( & V_17 -> V_8 , L_12 , V_17 -> V_53 ,
V_38 ) ;
V_40 = F_29 ( & V_17 -> V_8 ) ;
if ( V_40 < 0 ) {
F_25 ( V_17 -> V_44 , L_13
L_14 , V_17 -> V_47 , V_17 -> V_8 . V_20 . V_2 ) ;
goto V_54;
}
V_40 = F_30 ( & V_17 -> V_8 . V_20 , & V_55 ) ;
if ( V_40 < 0 ) {
F_25 ( & V_17 -> V_8 , L_15 ) ;
goto V_56;
}
F_31 ( V_17 ) ;
F_32 ( V_17 ) ;
}
return 0 ;
V_56:
F_33 ( & V_17 -> V_8 ) ;
V_54:
F_34 ( V_17 ) ;
F_35 ( & V_17 -> V_8 ) ;
F_15 ( V_37 ) ;
for ( V_39 -- ; V_39 >= 0 ; V_39 -- ) {
F_36 ( & V_35 [ V_39 ] -> V_8 . V_20 , & V_55 ) ;
F_33 ( & V_35 [ V_39 ] -> V_8 ) ;
F_34 ( V_35 [ V_39 ] ) ;
F_35 ( & V_35 [ V_39 ] -> V_8 ) ;
}
return V_40 ;
}
int F_37 ( struct V_14 * V_17 )
{
return F_22 ( & V_17 , 1 ) ;
}
void F_38 ( struct V_14 * * V_35 , int V_36 )
{
int V_39 ;
if ( V_36 < 1 )
return;
F_15 ( V_35 [ 0 ] -> V_37 ) ;
for ( V_39 = 0 ; V_39 < V_36 ; V_39 ++ ) {
F_36 ( & V_35 [ V_39 ] -> V_8 . V_20 , & V_55 ) ;
F_33 ( & V_35 [ V_39 ] -> V_8 ) ;
F_34 ( V_35 [ V_39 ] ) ;
F_35 ( & V_35 [ V_39 ] -> V_8 ) ;
}
}
void F_39 ( struct V_14 * V_17 )
{
F_38 ( & V_17 , 1 ) ;
}
static int F_40 ( void )
{
return F_41 ( & V_34 ) ;
}
static void F_42 ( void )
{
F_43 ( & V_34 ) ;
}
