static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 , * V_6 ;
const struct V_7 * V_8 ;
const struct V_9 * V_10 ;
struct V_11 * V_12 ;
const T_1 * V_13 , * V_14 ;
T_2 V_15 ;
F_2 ( V_2 , L_1 ) ;
F_2 ( V_2 , L_2 ) ;
F_3 (sram_dev->of_node, sram_node) {
V_13 = F_4 ( V_5 , 0 , NULL , NULL ) ;
F_5 ( V_2 , L_3 ,
F_6 ( * V_13 ) ) ;
F_3 (sram_node, section_node) {
V_10 = F_7 ( V_16 , V_6 ) ;
if ( ! V_10 )
continue;
V_8 = V_10 -> V_3 ;
V_14 = F_4 ( V_6 , 0 ,
NULL , NULL ) ;
F_5 ( V_2 , L_4 ,
F_6 ( * V_14 ) ,
V_8 -> V_17 ) ;
V_15 = F_8 ( V_18 + V_8 -> V_19 ) ;
V_15 >>= V_8 -> V_20 ;
V_15 &= F_9 ( V_8 -> V_21 - 1 , 0 ) ;
for ( V_12 = V_8 -> V_12 ; V_12 -> V_12 ; V_12 ++ ) {
F_5 ( V_2 , L_5 , V_12 -> V_12 ,
V_12 -> V_22 == V_15 ?
'*' : ' ' ) ;
}
}
F_2 ( V_2 , L_6 ) ;
}
return 0 ;
}
static int F_10 ( struct V_23 * V_23 , struct V_24 * V_24 )
{
return F_11 ( V_24 , F_1 , V_23 -> V_25 ) ;
}
static inline struct V_26 * F_12 ( const struct V_7 * V_3 )
{
return F_13 ( V_3 , struct V_26 , V_3 ) ;
}
static const struct V_7 * F_14 ( struct V_4 * V_27 ,
unsigned int * V_28 )
{
const struct V_9 * V_10 ;
const struct V_7 * V_3 ;
struct V_11 * V_12 ;
struct V_29 args ;
T_3 V_15 ;
int V_30 ;
V_30 = F_15 ( V_27 , L_7 , 1 , 0 ,
& args ) ;
if ( V_30 )
return F_16 ( V_30 ) ;
if ( ! F_17 ( args . V_31 ) ) {
V_30 = - V_32 ;
goto V_33;
}
V_15 = args . args [ 0 ] ;
V_10 = F_7 ( V_16 , args . V_31 ) ;
if ( ! V_10 ) {
V_30 = - V_34 ;
goto V_33;
}
V_3 = V_10 -> V_3 ;
if ( ! V_3 ) {
V_30 = - V_34 ;
goto V_33;
} ;
for ( V_12 = V_3 -> V_12 ; V_12 -> V_12 ; V_12 ++ ) {
if ( V_15 == V_12 -> V_15 ) {
if ( V_28 )
* V_28 = V_12 -> V_22 ;
break;
}
}
if ( ! V_12 -> V_12 ) {
V_30 = - V_34 ;
goto V_33;
}
F_18 ( args . V_31 ) ;
return V_10 -> V_3 ;
V_33:
F_18 ( args . V_31 ) ;
return F_16 ( V_30 ) ;
}
int F_19 ( struct V_35 * V_36 )
{
const struct V_7 * V_8 ;
struct V_26 * V_37 ;
unsigned int V_35 ;
T_2 V_15 , V_38 ;
if ( F_20 ( V_18 ) )
return F_21 ( V_18 ) ;
if ( ! V_18 )
return - V_39 ;
if ( ! V_36 || ! V_36 -> V_40 )
return - V_34 ;
V_8 = F_14 ( V_36 -> V_40 , & V_35 ) ;
if ( F_20 ( V_8 ) )
return F_21 ( V_8 ) ;
V_37 = F_12 ( V_8 ) ;
F_22 ( & V_41 ) ;
if ( V_37 -> V_42 ) {
F_23 ( & V_41 ) ;
return - V_32 ;
}
V_38 = F_9 ( V_8 -> V_20 + V_8 -> V_21 - 1 ,
V_8 -> V_20 ) ;
V_15 = F_8 ( V_18 + V_8 -> V_19 ) ;
V_15 &= ~ V_38 ;
F_24 ( V_15 | ( ( V_35 << V_8 -> V_20 ) & V_38 ) ,
V_18 + V_8 -> V_19 ) ;
F_23 ( & V_41 ) ;
return 0 ;
}
int F_25 ( struct V_35 * V_36 )
{
const struct V_7 * V_8 ;
struct V_26 * V_37 ;
if ( ! V_36 || ! V_36 -> V_40 )
return - V_34 ;
V_8 = F_14 ( V_36 -> V_40 , NULL ) ;
if ( F_20 ( V_8 ) )
return - V_34 ;
V_37 = F_12 ( V_8 ) ;
F_22 ( & V_41 ) ;
V_37 -> V_42 = false ;
F_23 ( & V_41 ) ;
return 0 ;
}
static int F_26 ( struct V_43 * V_44 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
V_49 = & V_44 -> V_36 ;
V_46 = F_27 ( V_44 , V_50 , 0 ) ;
V_18 = F_28 ( & V_44 -> V_36 , V_46 ) ;
if ( F_20 ( V_18 ) )
return F_21 ( V_18 ) ;
F_29 ( V_44 -> V_36 . V_40 , NULL , NULL , & V_44 -> V_36 ) ;
V_48 = F_30 ( L_8 , V_51 , NULL , NULL ,
& V_52 ) ;
if ( ! V_48 )
return - V_53 ;
return 0 ;
}
