void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned V_5 )
{
const struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
int V_10 ;
if ( ! V_7 -> V_11 )
return;
for ( V_10 = 0 ; V_10 < F_2 ( V_12 ) ; V_10 ++ ) {
unsigned long V_13 ;
int V_14 ;
V_13 = F_3 ( V_12 [ V_10 ] . V_15 , 0 ) ;
V_14 = F_4 ( V_2 , V_5 , & V_13 ) ;
if ( V_14 == - V_16 || V_14 == - V_17 )
continue;
if ( V_14 ) {
F_5 ( V_4 , L_1 , V_10 ) ;
continue;
}
F_6 ( V_4 , L_2 ) ;
F_6 ( V_4 , V_12 [ V_10 ] . V_18 ) ;
if ( V_12 [ V_10 ] . V_19 ) {
F_5 ( V_4 , L_3 ,
F_7 ( V_13 ) ) ;
if ( V_12 [ V_10 ] . V_20 )
F_5 ( V_4 , L_4 , V_12 [ V_10 ] . V_20 ) ;
else
F_6 ( V_4 , L_5 ) ;
}
}
}
void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_21 )
{
const struct V_6 * V_7 = V_2 -> V_8 -> V_9 ;
int V_10 ;
if ( ! V_7 -> V_11 )
return;
for ( V_10 = 0 ; V_10 < F_2 ( V_12 ) ; V_10 ++ ) {
unsigned long V_13 ;
int V_14 ;
V_13 = F_3 ( V_12 [ V_10 ] . V_15 , 0 ) ;
V_14 = F_9 ( F_10 ( V_2 -> V_22 ) , V_21 ,
& V_13 ) ;
if ( V_14 == - V_16 || V_14 == - V_17 )
continue;
if ( V_14 ) {
F_5 ( V_4 , L_1 , V_10 ) ;
continue;
}
F_6 ( V_4 , L_2 ) ;
F_6 ( V_4 , V_12 [ V_10 ] . V_18 ) ;
if ( V_12 [ V_10 ] . V_19 ) {
F_5 ( V_4 , L_3 ,
F_7 ( V_13 ) ) ;
if ( V_12 [ V_10 ] . V_20 )
F_5 ( V_4 , L_4 , V_12 [ V_10 ] . V_20 ) ;
else
F_6 ( V_4 , L_5 ) ;
}
}
}
void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned long V_13 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < F_2 ( V_12 ) ; V_10 ++ ) {
if ( F_12 ( V_13 ) != V_12 [ V_10 ] . V_15 )
continue;
F_5 ( V_4 , L_6 , V_12 [ V_10 ] . V_18 ,
F_7 ( V_13 ) ) ;
}
}
int F_13 ( struct V_23 * V_24 ,
unsigned long * * V_25 ,
unsigned int * V_26 )
{
unsigned long * V_27 ;
unsigned int V_28 = 0 ;
int V_14 ;
int V_10 ;
T_1 V_29 ;
if ( ! V_24 )
return - V_16 ;
V_27 = F_14 ( sizeof( * V_27 ) * F_2 ( V_30 ) , V_31 ) ;
if ( ! V_27 )
return - V_32 ;
for ( V_10 = 0 ; V_10 < F_2 ( V_30 ) ; V_10 ++ ) {
const struct V_33 * V_34 = & V_30 [ V_10 ] ;
V_14 = F_15 ( V_24 , V_34 -> V_35 , & V_29 ) ;
if ( V_14 == - V_16 )
continue;
if ( V_14 )
V_29 = V_34 -> V_36 ;
F_16 ( L_7 , V_34 -> V_35 , V_29 ) ;
V_27 [ V_28 ] = F_3 ( V_34 -> V_15 , V_29 ) ;
V_28 ++ ;
}
V_14 = 0 ;
if ( V_28 == 0 ) {
* V_25 = NULL ;
* V_26 = 0 ;
goto V_37;
}
* V_25 = F_17 ( V_27 , V_28 * sizeof( unsigned long ) , V_31 ) ;
if ( ! * V_25 ) {
V_14 = - V_32 ;
goto V_37;
}
* V_26 = V_28 ;
V_37:
F_18 ( V_27 ) ;
return V_14 ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_23 * V_24 , struct V_38 * * V_39 ,
unsigned * V_40 , unsigned * V_41 ,
enum V_42 type )
{
int V_14 ;
const char * V_43 ;
struct V_44 * V_22 = V_2 -> V_22 ;
unsigned long * V_25 = NULL ;
unsigned V_45 = 0 ;
unsigned V_46 ;
struct V_35 * V_47 ;
const char * V_48 ;
V_14 = F_20 ( V_24 , L_8 , & V_43 ) ;
if ( V_14 < 0 ) {
if ( V_14 != - V_16 )
F_21 ( V_22 , L_9 ) ;
V_43 = NULL ;
}
V_14 = F_13 ( V_24 , & V_25 , & V_45 ) ;
if ( V_14 < 0 ) {
F_21 ( V_22 , L_10 ) ;
return V_14 ;
}
V_46 = 0 ;
if ( V_43 != NULL )
V_46 ++ ;
if ( V_45 )
V_46 ++ ;
V_14 = F_22 ( V_24 , L_11 ) ;
if ( V_14 < 0 ) {
F_21 ( V_22 , L_12 ) ;
goto exit;
}
V_46 *= V_14 ;
V_14 = F_23 ( V_2 , V_39 , V_40 ,
V_41 , V_46 ) ;
if ( V_14 < 0 )
goto exit;
F_24 (np, L_11 , prop, group) {
if ( V_43 ) {
V_14 = F_25 ( V_2 , V_39 ,
V_40 , V_41 , V_48 ,
V_43 ) ;
if ( V_14 < 0 )
goto exit;
}
if ( V_45 ) {
V_14 = F_26 ( V_2 , V_39 ,
V_40 , V_41 , V_48 , V_25 ,
V_45 , type ) ;
if ( V_14 < 0 )
goto exit;
}
}
V_14 = 0 ;
exit:
F_18 ( V_25 ) ;
return V_14 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_23 * V_49 , struct V_38 * * V_39 ,
unsigned * V_41 , enum V_42 type )
{
unsigned V_40 ;
struct V_23 * V_24 ;
int V_14 ;
V_40 = 0 ;
* V_39 = NULL ;
* V_41 = 0 ;
F_28 (np_config, np) {
V_14 = F_19 ( V_2 , V_24 , V_39 ,
& V_40 , V_41 , type ) ;
if ( V_14 < 0 ) {
F_29 ( V_2 , * V_39 , * V_41 ) ;
return V_14 ;
}
}
return 0 ;
}
