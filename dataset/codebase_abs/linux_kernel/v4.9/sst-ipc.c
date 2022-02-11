static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = NULL ;
if ( ! F_2 ( & V_3 -> V_5 ) ) {
V_4 = F_3 ( & V_3 -> V_5 , struct V_1 ,
V_6 ) ;
F_4 ( & V_4 -> V_6 ) ;
}
return V_4 ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_1 * V_4 , void * V_7 )
{
unsigned long V_8 ;
int V_9 ;
V_9 = F_6 ( V_4 -> V_10 , V_4 -> V_11 ,
F_7 ( V_12 ) ) ;
F_8 ( & V_3 -> V_13 -> V_14 , V_8 ) ;
if ( V_9 == 0 ) {
if ( V_3 -> V_15 . V_16 != NULL )
V_3 -> V_15 . V_16 ( V_3 , L_1 ) ;
F_4 ( & V_4 -> V_6 ) ;
V_9 = - V_17 ;
} else {
if ( V_4 -> V_18 )
memcpy ( V_7 , V_4 -> V_7 , V_4 -> V_18 ) ;
V_9 = V_4 -> V_19 ;
}
F_9 ( & V_4 -> V_6 , & V_3 -> V_5 ) ;
F_10 ( & V_3 -> V_13 -> V_14 , V_8 ) ;
return V_9 ;
}
static int F_11 ( struct V_2 * V_3 , T_1 V_20 ,
void * V_21 , T_2 V_22 , void * V_7 ,
T_2 V_23 , int V_24 )
{
struct V_1 * V_4 ;
unsigned long V_8 ;
F_8 ( & V_3 -> V_13 -> V_14 , V_8 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL ) {
F_10 ( & V_3 -> V_13 -> V_14 , V_8 ) ;
return - V_25 ;
}
V_4 -> V_20 = V_20 ;
V_4 -> V_26 = V_22 ;
V_4 -> V_18 = V_23 ;
V_4 -> V_24 = V_24 ;
V_4 -> V_19 = 0 ;
V_4 -> V_27 = false ;
V_4 -> V_11 = false ;
if ( ( V_22 ) && ( V_3 -> V_15 . V_28 != NULL ) )
V_3 -> V_15 . V_28 ( V_4 , V_21 , V_22 ) ;
F_9 ( & V_4 -> V_6 , & V_3 -> V_29 ) ;
F_10 ( & V_3 -> V_13 -> V_14 , V_8 ) ;
F_12 ( & V_3 -> V_30 , & V_3 -> V_31 ) ;
if ( V_24 )
return F_5 ( V_3 , V_4 , V_7 ) ;
else
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
int V_32 ;
V_3 -> V_4 = F_14 ( sizeof( struct V_1 ) *
V_33 , V_34 ) ;
if ( V_3 -> V_4 == NULL )
return - V_35 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
V_3 -> V_4 [ V_32 ] . V_21 = F_14 ( V_3 -> V_36 , V_34 ) ;
if ( V_3 -> V_4 [ V_32 ] . V_21 == NULL )
goto V_37;
V_3 -> V_4 [ V_32 ] . V_7 = F_14 ( V_3 -> V_38 , V_34 ) ;
if ( V_3 -> V_4 [ V_32 ] . V_7 == NULL ) {
F_15 ( V_3 -> V_4 [ V_32 ] . V_21 ) ;
goto V_37;
}
F_16 ( & V_3 -> V_4 [ V_32 ] . V_10 ) ;
F_17 ( & V_3 -> V_4 [ V_32 ] . V_6 , & V_3 -> V_5 ) ;
}
return 0 ;
V_37:
while ( V_32 > 0 ) {
F_15 ( V_3 -> V_4 [ V_32 - 1 ] . V_21 ) ;
F_15 ( V_3 -> V_4 [ V_32 - 1 ] . V_7 ) ;
-- V_32 ;
}
F_15 ( V_3 -> V_4 ) ;
return - V_35 ;
}
static void F_18 ( struct V_39 * V_40 )
{
struct V_2 * V_3 =
F_19 ( V_40 , struct V_2 , V_31 ) ;
struct V_1 * V_4 ;
unsigned long V_8 ;
F_8 ( & V_3 -> V_13 -> V_14 , V_8 ) ;
if ( F_2 ( & V_3 -> V_29 ) || V_3 -> V_27 ) {
F_10 ( & V_3 -> V_13 -> V_14 , V_8 ) ;
return;
}
if ( V_3 -> V_15 . V_41 && V_3 -> V_15 . V_41 ( V_3 -> V_13 ) ) {
F_20 ( V_3 -> V_42 , L_2 ) ;
F_10 ( & V_3 -> V_13 -> V_14 , V_8 ) ;
return;
}
V_4 = F_3 ( & V_3 -> V_29 , struct V_1 , V_6 ) ;
F_21 ( & V_4 -> V_6 , & V_3 -> V_43 ) ;
if ( V_3 -> V_15 . V_44 != NULL )
V_3 -> V_15 . V_44 ( V_3 , V_4 ) ;
F_10 ( & V_3 -> V_13 -> V_14 , V_8 ) ;
}
int F_22 ( struct V_2 * V_3 , T_1 V_20 ,
void * V_21 , T_2 V_22 , void * V_7 , T_2 V_23 )
{
return F_11 ( V_3 , V_20 , V_21 , V_22 ,
V_7 , V_23 , 1 ) ;
}
int F_23 ( struct V_2 * V_3 , T_1 V_20 ,
void * V_21 , T_2 V_22 )
{
return F_11 ( V_3 , V_20 , V_21 , V_22 ,
NULL , 0 , 0 ) ;
}
struct V_1 * F_24 ( struct V_2 * V_3 ,
T_1 V_20 )
{
struct V_1 * V_4 ;
T_1 V_45 ;
if ( V_3 -> V_15 . V_46 != NULL )
V_20 = V_3 -> V_15 . V_46 ( V_20 , & V_45 ) ;
if ( F_2 ( & V_3 -> V_43 ) ) {
F_25 ( V_3 -> V_42 , L_3 ,
V_20 ) ;
return NULL ;
}
F_26 (msg, &ipc->rx_list, list) {
if ( ( V_4 -> V_20 & V_45 ) == V_20 )
return V_4 ;
}
return NULL ;
}
void F_27 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
V_4 -> V_11 = true ;
if ( ! V_4 -> V_24 )
F_9 ( & V_4 -> V_6 , & V_3 -> V_5 ) ;
else
F_28 ( & V_4 -> V_10 ) ;
}
void F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_47 ;
unsigned long V_8 ;
int V_48 = 0 , V_49 = 0 ;
F_8 ( & V_3 -> V_13 -> V_14 , V_8 ) ;
F_30 (msg, tmp, &ipc->tx_list, list) {
F_21 ( & V_4 -> V_6 , & V_3 -> V_5 ) ;
V_48 ++ ;
}
F_30 (msg, tmp, &ipc->rx_list, list) {
F_21 ( & V_4 -> V_6 , & V_3 -> V_5 ) ;
V_49 ++ ;
}
F_10 ( & V_3 -> V_13 -> V_14 , V_8 ) ;
if ( V_48 || V_49 )
F_25 ( V_3 -> V_42 , L_4 ,
V_48 , V_49 ) ;
}
int F_31 ( struct V_2 * V_3 )
{
int V_9 ;
F_32 ( & V_3 -> V_29 ) ;
F_32 ( & V_3 -> V_43 ) ;
F_32 ( & V_3 -> V_5 ) ;
F_16 ( & V_3 -> V_50 ) ;
V_9 = F_13 ( V_3 ) ;
if ( V_9 < 0 )
return - V_35 ;
F_33 ( & V_3 -> V_30 ) ;
V_3 -> V_51 = F_34 ( V_52 ,
& V_3 -> V_30 , L_5 ,
F_35 ( V_3 -> V_42 ) ) ;
if ( F_36 ( V_3 -> V_51 ) ) {
F_25 ( V_3 -> V_42 , L_6 ) ;
V_9 = F_37 ( V_3 -> V_51 ) ;
F_15 ( V_3 -> V_4 ) ;
return V_9 ;
}
F_38 ( & V_3 -> V_31 , F_18 ) ;
return 0 ;
}
void F_39 ( struct V_2 * V_3 )
{
int V_32 ;
if ( V_3 -> V_51 )
F_40 ( V_3 -> V_51 ) ;
if ( V_3 -> V_4 ) {
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
F_15 ( V_3 -> V_4 [ V_32 ] . V_21 ) ;
F_15 ( V_3 -> V_4 [ V_32 ] . V_7 ) ;
}
F_15 ( V_3 -> V_4 ) ;
}
}
