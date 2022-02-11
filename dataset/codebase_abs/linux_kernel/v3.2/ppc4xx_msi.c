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
F_6 (entry, &dev->msi_list, list) {
V_11 = F_7 ( & V_4 -> V_6 , 1 ) ;
if ( V_11 >= 0 )
break;
if ( V_11 < 0 ) {
F_8 ( L_1 ,
V_18 ) ;
}
V_13 = F_9 ( V_4 -> V_19 , V_11 ) ;
if ( V_13 == V_20 ) {
F_10 ( & V_2 -> V_2 , L_2 , V_18 ) ;
F_11 ( & V_4 -> V_6 , V_11 , 1 ) ;
return - V_21 ;
}
F_12 ( & V_2 -> V_2 , L_3 , V_18 , V_13 ) ;
V_15 . V_22 = V_4 -> V_23 ;
V_15 . V_24 = V_4 -> V_25 ;
F_13 ( V_13 , V_17 ) ;
V_15 . V_26 = V_11 ;
F_14 ( V_13 , & V_15 ) ;
}
return 0 ;
}
void F_15 ( struct V_9 * V_2 )
{
struct V_16 * V_17 ;
struct V_3 * V_4 = & V_3 ;
F_12 ( & V_2 -> V_2 , L_4 ) ;
F_6 (entry, &dev->msi_list, list) {
if ( V_17 -> V_27 == V_20 )
continue;
F_13 ( V_17 -> V_27 , NULL ) ;
F_11 ( & V_4 -> V_6 ,
F_16 ( V_17 -> V_27 ) , 1 ) ;
F_17 ( V_17 -> V_27 ) ;
}
}
static int F_18 ( struct V_9 * V_28 , int V_10 , int type )
{
F_12 ( & V_28 -> V_2 , L_5 ,
V_18 , V_10 , type ) ;
if ( type == V_29 )
F_8 ( L_6 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_30 V_31 , struct V_3 * V_32 )
{
const T_1 * V_4 ;
const T_1 * V_33 ;
const T_1 * V_34 ;
T_2 V_35 ;
void * V_36 ;
V_34 = F_20 ( V_2 -> V_2 . V_8 , L_7 , NULL ) ;
if ( ! V_34 )
return - 1 ;
F_21 ( V_34 , ( V_37 ) V_31 . V_38 >> 32 ) ;
F_21 ( V_34 + 1 , V_31 . V_38 & 0xFFFFFFFF ) ;
V_32 -> V_19 = F_22 ( NULL , L_8 ) ;
if ( V_32 -> V_19 )
return - V_39 ;
V_32 -> V_40 = F_23 ( V_32 -> V_19 , 0 ) ;
if ( ! V_32 -> V_40 ) {
F_10 ( & V_2 -> V_2 , L_9 ) ;
return - V_12 ;
}
F_12 ( & V_2 -> V_2 , L_10 ,
( T_1 ) ( V_32 -> V_40 + V_41 ) , ( T_1 ) ( V_32 -> V_40 ) ) ;
V_36 = F_24 ( & V_2 -> V_2 , 64 , & V_35 , V_42 ) ;
V_32 -> V_23 = 0x0 ;
V_32 -> V_25 = ( T_1 ) V_35 ;
F_12 ( & V_2 -> V_2 , L_11 , V_32 -> V_25 ) ;
F_25 ( V_32 -> V_40 + V_41 , V_32 -> V_23 ) ;
F_25 ( V_32 -> V_40 + V_43 , V_32 -> V_25 ) ;
V_4 = F_20 ( V_2 -> V_2 . V_8 , L_12 , NULL ) ;
if ( ! V_4 )
return - 1 ;
V_33 = F_20 ( V_2 -> V_2 . V_8 , L_13 , NULL ) ;
if ( ! V_33 )
return - 1 ;
F_25 ( V_32 -> V_40 + V_44 , * V_4 ) ;
F_25 ( V_32 -> V_40 + V_45 , * V_33 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_32 = V_2 -> V_2 . V_46 ;
int V_47 ;
int V_13 ;
for ( V_47 = 0 ; V_47 < V_7 ; V_47 ++ ) {
V_13 = V_32 -> V_48 [ V_47 ] ;
if ( V_13 != V_20 )
F_17 ( V_13 ) ;
}
if ( V_32 -> V_6 . V_6 )
F_4 ( & V_32 -> V_6 ) ;
F_27 ( V_32 -> V_40 ) ;
F_28 ( V_32 -> V_19 ) ;
F_29 ( V_32 ) ;
return 0 ;
}
static int T_3 F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_32 ;
struct V_30 V_31 ;
int V_5 = 0 ;
V_32 = & V_3 ;
F_12 ( & V_2 -> V_2 , L_14 ) ;
V_32 = F_31 ( sizeof( struct V_3 ) , V_42 ) ;
if ( ! V_32 ) {
F_10 ( & V_2 -> V_2 , L_15 ) ;
return - V_12 ;
}
V_2 -> V_2 . V_46 = V_32 ;
V_5 = F_32 ( V_2 -> V_2 . V_8 , 0 , & V_31 ) ;
if ( V_5 ) {
F_10 ( & V_2 -> V_2 , L_16 ,
V_2 -> V_2 . V_8 -> V_49 ) ;
goto V_50;
}
if ( F_19 ( V_2 , V_31 , V_32 ) )
goto V_50;
V_5 = F_1 ( V_2 , V_32 ) ;
if ( V_5 ) {
F_10 ( & V_2 -> V_2 , L_17 ) ;
goto V_50;
}
V_51 . V_52 = F_5 ;
V_51 . V_53 = F_15 ;
V_51 . V_54 = F_18 ;
return V_5 ;
V_50:
F_26 ( V_2 ) ;
return V_5 ;
}
static T_4 int F_33 ( void )
{
return F_34 ( & V_55 ) ;
}
