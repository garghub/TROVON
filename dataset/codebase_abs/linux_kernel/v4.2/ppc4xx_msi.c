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
F_9 (entry, &dev->msi_list, list) {
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
F_6 ( & V_2 -> V_2 , L_6 ) ;
F_9 (entry, &dev->msi_list, list) {
if ( V_17 -> V_30 == V_23 )
continue;
F_14 ( V_17 -> V_30 , NULL ) ;
F_13 ( & V_4 -> V_6 ,
F_17 ( V_17 -> V_30 ) , 1 ) ;
F_18 ( V_17 -> V_30 ) ;
}
}
static int F_19 ( struct V_1 * V_2 ,
struct V_31 V_32 , struct V_3 * V_33 )
{
const T_1 * V_4 ;
const T_1 * V_34 ;
const T_1 * V_35 ;
T_2 V_36 ;
void * V_37 ;
V_35 = F_20 ( V_2 -> V_2 . V_8 , L_7 , NULL ) ;
if ( ! V_35 )
return - 1 ;
F_21 ( V_38 , * V_35 , F_22 ( V_32 . V_39 ) ) ;
F_21 ( V_38 , * V_35 + 1 , F_23 ( V_32 . V_39 ) ) ;
V_33 -> V_22 = F_24 ( NULL , L_8 ) ;
if ( ! V_33 -> V_22 )
return - V_40 ;
V_33 -> V_41 = F_25 ( V_33 -> V_22 , 0 ) ;
if ( ! V_33 -> V_41 ) {
F_12 ( & V_2 -> V_2 , L_9 ) ;
return - V_12 ;
}
F_6 ( & V_2 -> V_2 , L_10 ,
( T_1 ) ( V_33 -> V_41 + V_42 ) , ( T_1 ) ( V_33 -> V_41 ) ) ;
V_37 = F_26 ( & V_2 -> V_2 , 64 , & V_36 , V_21 ) ;
if ( ! V_37 )
return - V_12 ;
V_33 -> V_26 = F_22 ( V_36 ) ;
V_33 -> V_28 = F_23 ( V_36 & 0xffffffff ) ;
F_6 ( & V_2 -> V_2 , L_11 ,
V_33 -> V_26 , V_33 -> V_28 ) ;
F_27 ( V_33 -> V_41 + V_42 , V_33 -> V_26 ) ;
F_27 ( V_33 -> V_41 + V_43 , V_33 -> V_28 ) ;
V_4 = F_20 ( V_2 -> V_2 . V_8 , L_12 , NULL ) ;
if ( ! V_4 )
return - 1 ;
V_34 = F_20 ( V_2 -> V_2 . V_8 , L_13 , NULL ) ;
if ( ! V_34 )
return - 1 ;
F_27 ( V_33 -> V_41 + V_44 , * V_4 ) ;
F_27 ( V_33 -> V_41 + V_45 , * V_34 ) ;
F_28 ( & V_2 -> V_2 , 64 , V_37 , V_36 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_33 = V_2 -> V_2 . V_46 ;
int V_47 ;
int V_13 ;
for ( V_47 = 0 ; V_47 < V_7 ; V_47 ++ ) {
V_13 = V_33 -> V_20 [ V_47 ] ;
if ( V_13 != V_23 )
F_18 ( V_13 ) ;
}
if ( V_33 -> V_6 . V_6 )
F_4 ( & V_33 -> V_6 ) ;
F_30 ( V_33 -> V_41 ) ;
F_31 ( V_33 -> V_22 ) ;
F_32 ( V_33 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_33 ;
struct V_31 V_32 ;
int V_5 = 0 ;
struct V_48 * V_49 ;
F_6 ( & V_2 -> V_2 , L_14 ) ;
V_33 = F_34 ( sizeof( struct V_3 ) , V_21 ) ;
if ( ! V_33 ) {
F_12 ( & V_2 -> V_2 , L_15 ) ;
return - V_12 ;
}
V_2 -> V_2 . V_46 = V_33 ;
V_5 = F_35 ( V_2 -> V_2 . V_8 , 0 , & V_32 ) ;
if ( V_5 ) {
F_12 ( & V_2 -> V_2 , L_16 ,
V_2 -> V_2 . V_8 -> V_50 ) ;
goto V_51;
}
V_7 = F_36 ( V_2 -> V_2 . V_8 ) ;
if ( ! V_7 )
return - V_40 ;
if ( F_19 ( V_2 , V_32 , V_33 ) )
goto V_51;
V_5 = F_1 ( V_2 , V_33 ) ;
if ( V_5 ) {
F_12 ( & V_2 -> V_2 , L_17 ) ;
goto V_51;
}
V_3 = * V_33 ;
F_9 (phb, &hose_list, list_node) {
V_49 -> V_52 . V_53 = F_5 ;
V_49 -> V_52 . V_54 = F_16 ;
}
return V_5 ;
V_51:
F_29 ( V_2 ) ;
return V_5 ;
}
static T_3 int F_37 ( void )
{
return F_38 ( & V_55 ) ;
}
