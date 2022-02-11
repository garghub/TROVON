static void F_1 ( int V_1 , const struct V_2 * V_3 ,
const char * V_4 , const struct V_5 * V_6 ,
const char * V_7 , const int line )
{
struct V_8 * V_9 = V_8 ( V_6 -> V_10 . V_11 ) ;
F_2 ( V_1 , L_1 ,
V_4 , V_6 , V_3 , V_9 -> V_12 , V_7 , line ) ;
}
void F_3 ( struct V_5 * V_6 , struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
V_14 -> V_19 = V_6 ;
F_4 ( & V_14 -> V_20 , & V_6 -> V_21 ) ;
V_14 -> V_22 = V_16 ;
V_14 -> V_23 = V_18 ;
}
void F_5 ( const struct V_2 * V_3 , struct V_5 * V_6 )
{
F_6 ( V_24 , V_3 , L_2 , V_6 ) ;
while ( ! F_7 ( & V_6 -> V_21 ) ) {
struct V_13 * V_14 ;
V_14 = F_8 ( V_6 -> V_21 . V_25 ,
struct V_13 , V_20 ) ;
F_9 ( V_6 -> V_21 . V_25 ) ;
V_14 -> V_23 -> V_26 ( V_3 , V_14 ) ;
}
F_10 ( V_6 , 0x5a , sizeof( * V_6 ) ) ;
}
int F_11 ( const struct V_2 * V_3 , struct V_5 * V_6 ,
const struct V_27 * V_28 )
{
struct V_15 * V_16 = V_6 -> V_10 . V_11 ;
struct V_15 * V_29 ;
int V_30 = 0 ;
F_12 ( V_16 ) ;
F_13 ( & V_6 -> V_21 ) ;
F_14 (scan, &obj->co_lu.lo_header->loh_layers,
co_lu.lo_linkage) {
V_30 = V_29 -> V_31 -> V_32 ( V_3 , V_29 , V_6 , V_28 ) ;
if ( V_30 != 0 ) {
F_5 ( V_3 , V_6 ) ;
break;
}
}
return V_30 ;
}
const struct V_13 * F_15 ( const struct V_5 * V_6 ,
const struct V_33 * V_34 )
{
const struct V_13 * V_14 ;
F_14 (slice, &lock->cll_layers, cls_linkage) {
if ( V_14 -> V_22 -> V_35 . V_36 -> V_37 == V_34 )
return V_14 ;
}
return NULL ;
}
void F_16 ( const struct V_2 * V_3 , struct V_5 * V_6 )
{
const struct V_13 * V_14 ;
F_6 ( V_24 , V_3 , L_3 , V_6 ) ;
F_17 (slice, &lock->cll_layers, cls_linkage) {
if ( V_14 -> V_23 -> V_38 )
V_14 -> V_23 -> V_38 ( V_3 , V_14 ) ;
}
}
int F_18 ( const struct V_2 * V_3 , struct V_27 * V_28 ,
struct V_5 * V_6 , struct V_39 * V_40 )
{
const struct V_13 * V_14 ;
int V_41 = - V_42 ;
F_14 (slice, &lock->cll_layers, cls_linkage) {
if ( ! V_14 -> V_23 -> V_43 )
continue;
V_41 = V_14 -> V_23 -> V_43 ( V_3 , V_14 , V_28 , V_40 ) ;
if ( V_41 != 0 )
break;
}
return V_41 ;
}
int F_19 ( const struct V_2 * V_3 , struct V_27 * V_28 ,
struct V_5 * V_6 )
{
struct V_39 * V_40 = NULL ;
T_1 V_44 = V_6 -> V_10 . V_45 ;
int V_41 ;
V_41 = F_11 ( V_3 , V_6 , V_28 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( ( V_44 & V_46 ) && ! ( V_44 & V_47 ) ) {
V_40 = & F_20 ( V_3 ) -> V_48 ;
F_21 ( V_40 , 1 , V_49 ) ;
}
V_41 = F_18 ( V_3 , V_28 , V_6 , V_40 ) ;
if ( V_40 ) {
int V_50 ;
F_22 ( V_3 , V_40 , 0 ) ;
V_50 = F_23 ( V_3 , V_40 , 0 ) ;
if ( V_50 < 0 && V_41 == 0 )
V_41 = V_50 ;
}
if ( V_41 < 0 )
F_24 ( V_3 , V_6 ) ;
return V_41 ;
}
void F_24 ( const struct V_2 * V_3 , struct V_5 * V_6 )
{
F_6 ( V_24 , V_3 , L_4 , V_6 ) ;
F_16 ( V_3 , V_6 ) ;
F_5 ( V_3 , V_6 ) ;
}
const char * F_25 ( const enum V_51 V_52 )
{
static const char * V_53 [] = {
[ V_54 ] = L_5 ,
[ V_55 ] = L_6 ,
[ V_56 ] = L_7
} ;
if ( 0 <= V_52 && V_52 < F_26 ( V_53 ) )
return V_53 [ V_52 ] ;
else
return L_8 ;
}
void F_27 ( const struct V_2 * V_3 , void * V_57 ,
T_2 V_58 ,
const struct V_59 * V_60 )
{
const struct V_61 * V_62 ;
V_62 = F_28 ( & V_60 -> V_11 -> V_35 ) ;
(* V_58)( V_3 , V_57 , V_63 L_9 V_64 , F_29 ( V_60 ) , F_30 ( V_62 ) ) ;
}
void F_31 ( const struct V_2 * V_3 , void * V_57 ,
T_2 V_58 , const struct V_5 * V_6 )
{
const struct V_13 * V_14 ;
(* V_58)( V_3 , V_57 , L_10 , V_6 ) ;
F_27 ( V_3 , V_57 , V_58 , & V_6 -> V_10 ) ;
(* V_58)( V_3 , V_57 , L_11 ) ;
F_14 (slice, &lock->cll_layers, cls_linkage) {
(* V_58)( V_3 , V_57 , L_12 ,
V_14 -> V_22 -> V_35 . V_36 -> V_37 -> V_65 ,
V_14 ) ;
if ( V_14 -> V_23 -> V_66 )
V_14 -> V_23 -> V_66 ( V_3 , V_57 , V_58 , V_14 ) ;
(* V_58)( V_3 , V_57 , L_13 ) ;
}
(* V_58)( V_3 , V_57 , L_14 , V_6 ) ;
}
