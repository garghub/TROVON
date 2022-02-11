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
V_15 &= V_8 -> V_21 ;
for ( V_12 = V_8 -> V_12 ; V_12 -> V_12 ; V_12 ++ ) {
F_5 ( V_2 , L_5 , V_12 -> V_12 ,
V_12 -> V_15 == V_15 ? '*' : ' ' ) ;
}
}
F_2 ( V_2 , L_6 ) ;
}
return 0 ;
}
static int F_9 ( struct V_22 * V_22 , struct V_23 * V_23 )
{
return F_10 ( V_23 , F_1 , V_22 -> V_24 ) ;
}
static inline struct V_25 * F_11 ( const struct V_7 * V_3 )
{
return F_12 ( V_3 , struct V_25 , V_3 ) ;
}
static const struct V_7 * F_13 ( struct V_4 * V_26 ,
unsigned int * V_27 )
{
const struct V_9 * V_10 ;
struct V_28 args ;
int V_29 ;
V_29 = F_14 ( V_26 , L_7 , 1 , 0 ,
& args ) ;
if ( V_29 )
return F_15 ( V_29 ) ;
if ( ! F_16 ( args . V_30 ) ) {
V_29 = - V_31 ;
goto V_32;
}
if ( V_27 )
* V_27 = args . args [ 0 ] ;
V_10 = F_7 ( V_16 , args . V_30 ) ;
if ( ! V_10 ) {
V_29 = - V_33 ;
goto V_32;
}
F_17 ( args . V_30 ) ;
return V_10 -> V_3 ;
V_32:
F_17 ( args . V_30 ) ;
return F_15 ( V_29 ) ;
}
int F_18 ( struct V_34 * V_35 )
{
const struct V_7 * V_8 ;
struct V_25 * V_36 ;
unsigned int V_34 ;
T_2 V_15 , V_37 ;
if ( F_19 ( V_18 ) )
return - V_38 ;
if ( ! V_35 || ! V_35 -> V_39 )
return - V_33 ;
V_8 = F_13 ( V_35 -> V_39 , & V_34 ) ;
if ( F_19 ( V_8 ) )
return F_20 ( V_8 ) ;
V_36 = F_11 ( V_8 ) ;
F_21 ( & V_40 ) ;
if ( V_36 -> V_41 ) {
F_22 ( & V_40 ) ;
return - V_31 ;
}
V_37 = F_23 ( V_8 -> V_20 + V_8 -> V_21 , V_8 -> V_20 ) ;
V_15 = F_8 ( V_18 + V_8 -> V_19 ) ;
V_15 &= ~ V_37 ;
F_24 ( V_15 | ( ( V_34 << V_8 -> V_20 ) & V_37 ) ,
V_18 + V_8 -> V_19 ) ;
F_22 ( & V_40 ) ;
return 0 ;
}
int F_25 ( struct V_34 * V_35 )
{
const struct V_7 * V_8 ;
struct V_25 * V_36 ;
if ( ! V_35 || ! V_35 -> V_39 )
return - V_33 ;
V_8 = F_13 ( V_35 -> V_39 , NULL ) ;
if ( F_19 ( V_8 ) )
return - V_33 ;
V_36 = F_11 ( V_8 ) ;
F_21 ( & V_40 ) ;
V_36 -> V_41 = false ;
F_22 ( & V_40 ) ;
return 0 ;
}
static int F_26 ( struct V_42 * V_43 )
{
struct V_44 * V_45 ;
struct V_46 * V_47 ;
V_48 = & V_43 -> V_35 ;
V_45 = F_27 ( V_43 , V_49 , 0 ) ;
V_18 = F_28 ( & V_43 -> V_35 , V_45 ) ;
if ( F_19 ( V_18 ) )
return F_20 ( V_18 ) ;
F_29 ( V_43 -> V_35 . V_39 , NULL , NULL , & V_43 -> V_35 ) ;
V_47 = F_30 ( L_8 , V_50 , NULL , NULL ,
& V_51 ) ;
if ( ! V_47 )
return - V_52 ;
return 0 ;
}
