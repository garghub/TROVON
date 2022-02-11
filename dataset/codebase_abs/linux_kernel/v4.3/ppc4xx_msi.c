static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( & V_4 -> V_6 , V_7 ,
V_2 -> V_2 . V_8 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_3 ( & V_4 -> V_6 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_4 -> V_6 ) ;
return V_5 ;
}
return 0 ;
}
static int F_5 ( struct V_9 * V_2 , int V_10 , int type )
{
int V_11 = - V_12 ;
unsigned int V_13 ;
struct V_14 V_15 ;
struct V_16 * V_17 ;
struct V_3 * V_4 = & V_3 ;
F_6 ( & V_2 -> V_2 , L_1 ,
V_18 , V_10 , type ) ;
if ( type == V_19 )
F_7 ( L_2 ) ;
V_4 -> V_20 = F_8 ( ( V_7 ) * sizeof( int ) , V_21 ) ;
if ( ! V_4 -> V_20 )
return - V_12 ;
F_9 (entry, dev) {
V_11 = F_10 ( & V_4 -> V_6 , 1 ) ;
if ( V_11 >= 0 )
break;
if ( V_11 < 0 ) {
F_7 ( L_3 ,
V_18 ) ;
}
V_13 = F_11 ( V_4 -> V_22 , V_11 ) ;
if ( V_13 == V_23 ) {
F_12 ( & V_2 -> V_2 , L_4 , V_18 ) ;
F_13 ( & V_4 -> V_6 , V_11 , 1 ) ;
return - V_24 ;
}
F_6 ( & V_2 -> V_2 , L_5 , V_18 , V_13 ) ;
V_15 . V_25 = V_4 -> V_26 ;
V_15 . V_27 = V_4 -> V_28 ;
F_14 ( V_13 , V_17 ) ;
V_15 . V_29 = V_11 ;
F_15 ( V_13 , & V_15 ) ;
}
return 0 ;
}
void F_16 ( struct V_9 * V_2 )
{
struct V_16 * V_17 ;
struct V_3 * V_4 = & V_3 ;
T_1 V_30 ;
F_6 ( & V_2 -> V_2 , L_6 ) ;
F_9 (entry, dev) {
if ( V_17 -> V_31 == V_23 )
continue;
V_30 = F_17 ( V_17 -> V_31 ) ;
F_14 ( V_17 -> V_31 , NULL ) ;
F_18 ( V_17 -> V_31 ) ;
F_13 ( & V_4 -> V_6 , V_30 , 1 ) ;
}
}
static int F_19 ( struct V_1 * V_2 ,
struct V_32 V_33 , struct V_3 * V_34 )
{
const T_2 * V_4 ;
const T_2 * V_35 ;
const T_2 * V_36 ;
T_3 V_37 ;
void * V_38 ;
V_36 = F_20 ( V_2 -> V_2 . V_8 , L_7 , NULL ) ;
if ( ! V_36 )
return - 1 ;
F_21 ( V_39 , * V_36 , F_22 ( V_33 . V_40 ) ) ;
F_21 ( V_39 , * V_36 + 1 , F_23 ( V_33 . V_40 ) ) ;
V_34 -> V_22 = F_24 ( NULL , L_8 ) ;
if ( ! V_34 -> V_22 )
return - V_41 ;
V_34 -> V_42 = F_25 ( V_34 -> V_22 , 0 ) ;
if ( ! V_34 -> V_42 ) {
F_12 ( & V_2 -> V_2 , L_9 ) ;
return - V_12 ;
}
F_6 ( & V_2 -> V_2 , L_10 ,
( T_2 ) ( V_34 -> V_42 + V_43 ) , ( T_2 ) ( V_34 -> V_42 ) ) ;
V_38 = F_26 ( & V_2 -> V_2 , 64 , & V_37 , V_21 ) ;
if ( ! V_38 )
return - V_12 ;
V_34 -> V_26 = F_22 ( V_37 ) ;
V_34 -> V_28 = F_23 ( V_37 & 0xffffffff ) ;
F_6 ( & V_2 -> V_2 , L_11 ,
V_34 -> V_26 , V_34 -> V_28 ) ;
F_27 ( V_34 -> V_42 + V_43 , V_34 -> V_26 ) ;
F_27 ( V_34 -> V_42 + V_44 , V_34 -> V_28 ) ;
V_4 = F_20 ( V_2 -> V_2 . V_8 , L_12 , NULL ) ;
if ( ! V_4 )
return - 1 ;
V_35 = F_20 ( V_2 -> V_2 . V_8 , L_13 , NULL ) ;
if ( ! V_35 )
return - 1 ;
F_27 ( V_34 -> V_42 + V_45 , * V_4 ) ;
F_27 ( V_34 -> V_42 + V_46 , * V_35 ) ;
F_28 ( & V_2 -> V_2 , 64 , V_38 , V_37 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_34 = V_2 -> V_2 . V_47 ;
int V_48 ;
int V_13 ;
for ( V_48 = 0 ; V_48 < V_7 ; V_48 ++ ) {
V_13 = V_34 -> V_20 [ V_48 ] ;
if ( V_13 != V_23 )
F_18 ( V_13 ) ;
}
if ( V_34 -> V_6 . V_6 )
F_4 ( & V_34 -> V_6 ) ;
F_30 ( V_34 -> V_42 ) ;
F_31 ( V_34 -> V_22 ) ;
F_32 ( V_34 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_34 ;
struct V_32 V_33 ;
int V_5 = 0 ;
struct V_49 * V_50 ;
F_6 ( & V_2 -> V_2 , L_14 ) ;
V_34 = F_34 ( sizeof( struct V_3 ) , V_21 ) ;
if ( ! V_34 ) {
F_12 ( & V_2 -> V_2 , L_15 ) ;
return - V_12 ;
}
V_2 -> V_2 . V_47 = V_34 ;
V_5 = F_35 ( V_2 -> V_2 . V_8 , 0 , & V_33 ) ;
if ( V_5 ) {
F_12 ( & V_2 -> V_2 , L_16 ,
V_2 -> V_2 . V_8 -> V_51 ) ;
goto V_52;
}
V_7 = F_36 ( V_2 -> V_2 . V_8 ) ;
if ( ! V_7 )
return - V_41 ;
if ( F_19 ( V_2 , V_33 , V_34 ) )
goto V_52;
V_5 = F_1 ( V_2 , V_34 ) ;
if ( V_5 ) {
F_12 ( & V_2 -> V_2 , L_17 ) ;
goto V_52;
}
V_3 = * V_34 ;
F_37 (phb, &hose_list, list_node) {
V_50 -> V_53 . V_54 = F_5 ;
V_50 -> V_53 . V_55 = F_16 ;
}
return V_5 ;
V_52:
F_29 ( V_2 ) ;
return V_5 ;
}
static T_4 int F_38 ( void )
{
return F_39 ( & V_56 ) ;
}
