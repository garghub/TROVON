static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 ,
unsigned V_6 ,
const struct V_7 * V_8 ,
int V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
unsigned long V_11 ;
int V_12 ;
V_11 = F_2 ( V_8 [ V_10 ] . V_13 , 0 ) ;
if ( V_5 )
V_12 = F_3 ( F_4 ( V_2 -> V_14 ) ,
V_5 , & V_11 ) ;
else
V_12 = F_5 ( V_2 , V_6 , & V_11 ) ;
if ( V_12 == - V_15 || V_12 == - V_16 )
continue;
if ( V_12 ) {
F_6 ( V_4 , L_1 , V_10 ) ;
continue;
}
F_7 ( V_4 , L_2 ) ;
F_7 ( V_4 , V_8 [ V_10 ] . V_17 ) ;
if ( V_8 [ V_10 ] . V_18 ) {
F_6 ( V_4 , L_3 ,
F_8 ( V_11 ) ) ;
if ( V_8 [ V_10 ] . V_19 )
F_6 ( V_4 , L_4 , V_8 [ V_10 ] . V_19 ) ;
else
F_7 ( V_4 , L_5 ) ;
}
}
}
void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , unsigned V_6 )
{
const struct V_20 * V_21 = V_2 -> V_22 -> V_23 ;
if ( ! V_21 -> V_24 )
return;
F_1 ( V_2 , V_4 , V_5 , V_6 , V_25 ,
F_10 ( V_25 ) ) ;
if ( V_2 -> V_22 -> V_26 &&
V_2 -> V_22 -> V_27 )
F_1 ( V_2 , V_4 , V_5 , V_6 ,
V_2 -> V_22 -> V_27 ,
V_2 -> V_22 -> V_26 ) ;
}
void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned long V_11 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < F_10 ( V_25 ) ; V_10 ++ ) {
if ( F_12 ( V_11 ) != V_25 [ V_10 ] . V_13 )
continue;
F_6 ( V_4 , L_6 , V_25 [ V_10 ] . V_17 ,
F_8 ( V_11 ) ) ;
}
if ( ! V_2 -> V_22 -> V_26 ||
! V_2 -> V_22 -> V_27 )
return;
for ( V_10 = 0 ; V_10 < V_2 -> V_22 -> V_26 ; V_10 ++ ) {
if ( F_12 ( V_11 ) !=
V_2 -> V_22 -> V_27 [ V_10 ] . V_13 )
continue;
F_6 ( V_4 , L_6 ,
V_2 -> V_22 -> V_27 [ V_10 ] . V_17 ,
F_8 ( V_11 ) ) ;
}
}
static void F_13 ( struct V_28 * V_29 ,
const struct V_30 * V_31 ,
unsigned int V_32 , unsigned long * V_33 ,
unsigned int * V_34 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_32 ; V_10 ++ ) {
T_1 V_35 ;
int V_12 ;
const struct V_30 * V_36 = & V_31 [ V_10 ] ;
V_12 = F_14 ( V_29 , V_36 -> V_37 , & V_35 ) ;
if ( V_12 == - V_15 )
continue;
if ( V_12 )
V_35 = V_36 -> V_38 ;
F_15 ( L_7 , V_36 -> V_37 , V_35 ) ;
V_33 [ * V_34 ] = F_2 ( V_36 -> V_13 , V_35 ) ;
( * V_34 ) ++ ;
}
}
int F_16 ( struct V_28 * V_29 ,
struct V_1 * V_2 ,
unsigned long * * V_39 ,
unsigned int * V_40 )
{
unsigned long * V_33 ;
unsigned int V_41 , V_34 = 0 ;
int V_12 ;
if ( ! V_29 )
return - V_15 ;
V_41 = F_10 ( V_42 ) ;
if ( V_2 )
V_41 += V_2 -> V_22 -> V_26 ;
V_33 = F_17 ( V_41 , sizeof( * V_33 ) , V_43 ) ;
if ( ! V_33 )
return - V_44 ;
F_13 ( V_29 , V_42 , F_10 ( V_42 ) , V_33 , & V_34 ) ;
if ( V_2 && V_2 -> V_22 -> V_26 &&
V_2 -> V_22 -> V_45 )
F_13 ( V_29 , V_2 -> V_22 -> V_45 ,
V_2 -> V_22 -> V_26 , V_33 , & V_34 ) ;
V_12 = 0 ;
if ( V_34 == 0 ) {
* V_39 = NULL ;
* V_40 = 0 ;
goto V_46;
}
* V_39 = F_18 ( V_33 , V_34 * sizeof( unsigned long ) , V_43 ) ;
if ( ! * V_39 ) {
V_12 = - V_44 ;
goto V_46;
}
* V_40 = V_34 ;
V_46:
F_19 ( V_33 ) ;
return V_12 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_28 * V_29 , struct V_47 * * V_48 ,
unsigned * V_49 , unsigned * V_50 ,
enum V_51 type )
{
int V_12 ;
const char * V_52 ;
struct V_53 * V_14 = V_2 -> V_14 ;
unsigned long * V_39 = NULL ;
unsigned V_54 = 0 ;
unsigned V_55 ;
struct V_37 * V_56 ;
const char * V_57 ;
const char * V_58 = L_8 ;
V_12 = F_21 ( V_29 , L_9 , & V_52 ) ;
if ( V_12 < 0 ) {
if ( V_12 != - V_15 )
F_22 ( V_14 , L_10 ) ;
V_52 = NULL ;
}
V_12 = F_16 ( V_29 , V_2 , & V_39 ,
& V_54 ) ;
if ( V_12 < 0 ) {
F_22 ( V_14 , L_11 ) ;
return V_12 ;
}
V_55 = 0 ;
if ( V_52 != NULL )
V_55 ++ ;
if ( V_54 )
V_55 ++ ;
V_12 = F_23 ( V_29 , L_8 ) ;
if ( V_12 < 0 ) {
V_12 = F_23 ( V_29 , L_12 ) ;
if ( V_12 < 0 ) {
F_22 ( V_14 , L_13 ) ;
goto exit;
}
if ( type == V_59 )
type = V_60 ;
V_58 = L_12 ;
} else {
if ( type == V_59 )
type = V_61 ;
}
V_55 *= V_12 ;
V_12 = F_24 ( V_2 , V_48 , V_49 ,
V_50 , V_55 ) ;
if ( V_12 < 0 )
goto exit;
F_25 (np, subnode_target_type, prop, group) {
if ( V_52 ) {
V_12 = F_26 ( V_2 , V_48 ,
V_49 , V_50 , V_57 ,
V_52 ) ;
if ( V_12 < 0 )
goto exit;
}
if ( V_54 ) {
V_12 = F_27 ( V_2 , V_48 ,
V_49 , V_50 , V_57 , V_39 ,
V_54 , type ) ;
if ( V_12 < 0 )
goto exit;
}
}
V_12 = 0 ;
exit:
F_19 ( V_39 ) ;
return V_12 ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_28 * V_62 , struct V_47 * * V_48 ,
unsigned * V_50 , enum V_51 type )
{
unsigned V_49 ;
struct V_28 * V_29 ;
int V_12 ;
V_49 = 0 ;
* V_48 = NULL ;
* V_50 = 0 ;
F_29 (np_config, np) {
V_12 = F_20 ( V_2 , V_29 , V_48 ,
& V_49 , V_50 , type ) ;
if ( V_12 < 0 ) {
F_30 ( V_2 , * V_48 , * V_50 ) ;
return V_12 ;
}
}
return 0 ;
}
