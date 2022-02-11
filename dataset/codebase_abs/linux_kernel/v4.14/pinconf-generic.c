static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 ,
unsigned V_6 ,
const struct V_7 * V_8 ,
int V_9 , int * V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
unsigned long V_12 ;
int V_13 ;
V_12 = F_2 ( V_8 [ V_11 ] . V_14 , 0 ) ;
if ( V_5 )
V_13 = F_3 ( F_4 ( V_2 -> V_15 ) ,
V_5 , & V_12 ) ;
else
V_13 = F_5 ( V_2 , V_6 , & V_12 ) ;
if ( V_13 == - V_16 || V_13 == - V_17 )
continue;
if ( V_13 ) {
F_6 ( V_4 , L_1 , V_11 ) ;
continue;
}
if ( * V_10 )
F_7 ( V_4 , L_2 ) ;
* V_10 = 1 ;
F_7 ( V_4 , V_8 [ V_11 ] . V_18 ) ;
if ( V_8 [ V_11 ] . V_19 ) {
F_6 ( V_4 , L_3 ,
F_8 ( V_12 ) ) ;
if ( V_8 [ V_11 ] . V_20 )
F_6 ( V_4 , L_4 , V_8 [ V_11 ] . V_20 ) ;
else
F_7 ( V_4 , L_5 ) ;
}
}
}
void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , unsigned V_6 )
{
const struct V_21 * V_22 = V_2 -> V_23 -> V_24 ;
int V_10 = 0 ;
if ( ! V_22 -> V_25 )
return;
F_1 ( V_2 , V_4 , V_5 , V_6 , V_26 ,
F_10 ( V_26 ) , & V_10 ) ;
if ( V_2 -> V_23 -> V_27 &&
V_2 -> V_23 -> V_28 )
F_1 ( V_2 , V_4 , V_5 , V_6 ,
V_2 -> V_23 -> V_28 ,
V_2 -> V_23 -> V_27 ,
& V_10 ) ;
}
void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned long V_12 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_10 ( V_26 ) ; V_11 ++ ) {
if ( F_12 ( V_12 ) != V_26 [ V_11 ] . V_14 )
continue;
F_6 ( V_4 , L_6 , V_26 [ V_11 ] . V_18 ,
F_8 ( V_12 ) ) ;
}
if ( ! V_2 -> V_23 -> V_27 ||
! V_2 -> V_23 -> V_28 )
return;
for ( V_11 = 0 ; V_11 < V_2 -> V_23 -> V_27 ; V_11 ++ ) {
if ( F_12 ( V_12 ) !=
V_2 -> V_23 -> V_28 [ V_11 ] . V_14 )
continue;
F_6 ( V_4 , L_6 ,
V_2 -> V_23 -> V_28 [ V_11 ] . V_18 ,
F_8 ( V_12 ) ) ;
}
}
static void F_13 ( struct V_29 * V_30 ,
const struct V_31 * V_32 ,
unsigned int V_33 , unsigned long * V_34 ,
unsigned int * V_35 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_33 ; V_11 ++ ) {
T_1 V_36 ;
int V_13 ;
const struct V_31 * V_37 = & V_32 [ V_11 ] ;
V_13 = F_14 ( V_30 , V_37 -> V_38 , & V_36 ) ;
if ( V_13 == - V_16 )
continue;
if ( V_13 )
V_36 = V_37 -> V_39 ;
F_15 ( L_7 , V_37 -> V_38 , V_36 ) ;
V_34 [ * V_35 ] = F_2 ( V_37 -> V_14 , V_36 ) ;
( * V_35 ) ++ ;
}
}
int F_16 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
unsigned long * * V_40 ,
unsigned int * V_41 )
{
unsigned long * V_34 ;
unsigned int V_42 , V_35 = 0 ;
int V_13 ;
if ( ! V_30 )
return - V_16 ;
V_42 = F_10 ( V_43 ) ;
if ( V_2 )
V_42 += V_2 -> V_23 -> V_27 ;
V_34 = F_17 ( V_42 , sizeof( * V_34 ) , V_44 ) ;
if ( ! V_34 )
return - V_45 ;
F_13 ( V_30 , V_43 , F_10 ( V_43 ) , V_34 , & V_35 ) ;
if ( V_2 && V_2 -> V_23 -> V_27 &&
V_2 -> V_23 -> V_46 )
F_13 ( V_30 , V_2 -> V_23 -> V_46 ,
V_2 -> V_23 -> V_27 , V_34 , & V_35 ) ;
V_13 = 0 ;
if ( V_35 == 0 ) {
* V_40 = NULL ;
* V_41 = 0 ;
goto V_47;
}
* V_40 = F_18 ( V_34 , V_35 * sizeof( unsigned long ) , V_44 ) ;
if ( ! * V_40 ) {
V_13 = - V_45 ;
goto V_47;
}
* V_41 = V_35 ;
V_47:
F_19 ( V_34 ) ;
return V_13 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_29 * V_30 , struct V_48 * * V_49 ,
unsigned * V_50 , unsigned * V_51 ,
enum V_52 type )
{
int V_13 ;
const char * V_53 ;
struct V_54 * V_15 = V_2 -> V_15 ;
unsigned long * V_40 = NULL ;
unsigned V_55 = 0 ;
unsigned V_56 , V_57 ;
struct V_38 * V_58 ;
const char * V_59 ;
const char * V_60 = L_8 ;
V_13 = F_21 ( V_30 , L_8 ) ;
if ( V_13 < 0 ) {
V_13 = F_21 ( V_30 , L_9 ) ;
if ( V_13 < 0 )
return 0 ;
if ( type == V_61 )
type = V_62 ;
V_60 = L_9 ;
} else {
if ( type == V_61 )
type = V_63 ;
}
V_57 = V_13 ;
V_13 = F_22 ( V_30 , L_10 , & V_53 ) ;
if ( V_13 < 0 ) {
if ( V_13 != - V_16 )
F_23 ( V_15 , L_11 ,
V_30 ) ;
V_53 = NULL ;
}
V_13 = F_16 ( V_30 , V_2 , & V_40 ,
& V_55 ) ;
if ( V_13 < 0 ) {
F_23 ( V_15 , L_12 , V_30 ) ;
return V_13 ;
}
V_56 = 0 ;
if ( V_53 != NULL )
V_56 ++ ;
if ( V_55 )
V_56 ++ ;
V_56 *= V_57 ;
V_13 = F_24 ( V_2 , V_49 , V_50 ,
V_51 , V_56 ) ;
if ( V_13 < 0 )
goto exit;
F_25 (np, subnode_target_type, prop, group) {
if ( V_53 ) {
V_13 = F_26 ( V_2 , V_49 ,
V_50 , V_51 , V_59 ,
V_53 ) ;
if ( V_13 < 0 )
goto exit;
}
if ( V_55 ) {
V_13 = F_27 ( V_2 , V_49 ,
V_50 , V_51 , V_59 , V_40 ,
V_55 , type ) ;
if ( V_13 < 0 )
goto exit;
}
}
V_13 = 0 ;
exit:
F_19 ( V_40 ) ;
return V_13 ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_29 * V_64 , struct V_48 * * V_49 ,
unsigned * V_51 , enum V_52 type )
{
unsigned V_50 ;
struct V_29 * V_30 ;
int V_13 ;
V_50 = 0 ;
* V_49 = NULL ;
* V_51 = 0 ;
V_13 = F_20 ( V_2 , V_64 , V_49 ,
& V_50 , V_51 , type ) ;
if ( V_13 < 0 )
goto exit;
F_29 (np_config, np) {
V_13 = F_20 ( V_2 , V_30 , V_49 ,
& V_50 , V_51 , type ) ;
if ( V_13 < 0 )
goto exit;
}
return 0 ;
exit:
F_30 ( V_2 , * V_49 , * V_51 ) ;
return V_13 ;
}
void F_31 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
unsigned V_51 )
{
F_30 ( V_2 , V_49 , V_51 ) ;
}
