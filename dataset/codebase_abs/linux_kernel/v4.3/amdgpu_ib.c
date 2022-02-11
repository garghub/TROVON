int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_10 ;
if ( V_5 ) {
V_10 = F_2 ( V_9 , & V_9 -> V_11 ,
& V_7 -> V_12 , V_5 , 256 ) ;
if ( V_10 ) {
F_3 ( V_9 -> V_13 , L_1 , V_10 ) ;
return V_10 ;
}
V_7 -> V_14 = F_4 ( V_7 -> V_12 ) ;
if ( ! V_4 )
V_7 -> V_15 = F_5 ( V_7 -> V_12 ) ;
}
F_6 ( & V_7 -> V_16 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_4 = V_4 ;
return 0 ;
}
void F_7 ( struct V_8 * V_9 , struct V_6 * V_7 )
{
F_8 ( V_9 , & V_7 -> V_16 , & V_7 -> V_17 -> V_18 ) ;
F_9 ( V_9 , & V_7 -> V_12 , & V_7 -> V_17 -> V_18 ) ;
F_10 ( & V_7 -> V_17 ) ;
}
int F_11 ( struct V_8 * V_9 , unsigned V_19 ,
struct V_6 * V_20 , void * V_21 )
{
struct V_6 * V_7 = & V_20 [ 0 ] ;
struct V_1 * V_2 ;
struct V_22 * V_23 , * V_24 ;
struct V_3 * V_4 ;
unsigned V_25 ;
int V_10 = 0 ;
if ( V_19 == 0 )
return - V_26 ;
V_2 = V_20 -> V_2 ;
V_23 = V_20 -> V_23 ;
V_4 = V_20 -> V_4 ;
if ( ! V_2 -> V_27 ) {
F_3 ( V_9 -> V_13 , L_2 ) ;
return - V_26 ;
}
V_10 = F_12 ( & V_20 -> V_16 ) ;
if ( V_10 ) {
F_3 ( V_9 -> V_13 , L_3 , V_10 ) ;
return V_10 ;
}
V_10 = F_13 ( V_2 , ( 256 + V_28 * 8 ) * V_19 ) ;
if ( V_10 ) {
F_3 ( V_9 -> V_13 , L_4 , V_10 ) ;
return V_10 ;
}
if ( V_4 ) {
V_10 = F_14 ( V_20 -> V_4 , V_20 -> V_2 , & V_20 -> V_16 ) ;
if ( V_10 ) {
F_15 ( V_2 ) ;
return V_10 ;
}
}
V_10 = F_16 ( & V_20 -> V_16 , V_2 ) ;
if ( V_10 ) {
F_15 ( V_2 ) ;
F_3 ( V_9 -> V_13 , L_5 , V_10 ) ;
return V_10 ;
}
if ( V_4 ) {
F_17 ( V_2 , V_4 , V_7 -> V_16 . V_29 ) ;
if ( V_2 -> V_30 -> V_31 )
F_18 ( V_2 , V_7 -> V_4 -> V_32 [ V_2 -> V_33 ] . V_34 ,
V_7 -> V_35 , V_7 -> V_36 ,
V_7 -> V_37 , V_7 -> V_38 ,
V_7 -> V_39 , V_7 -> V_40 ) ;
if ( V_2 -> V_30 -> V_41 )
F_19 ( V_2 ) ;
}
V_24 = V_2 -> V_42 ;
for ( V_25 = 0 ; V_25 < V_19 ; ++ V_25 ) {
V_7 = & V_20 [ V_25 ] ;
if ( V_7 -> V_2 != V_2 || V_7 -> V_23 != V_23 || V_7 -> V_4 != V_4 ) {
V_2 -> V_42 = V_24 ;
F_15 ( V_2 ) ;
return - V_26 ;
}
F_20 ( V_2 , V_7 ) ;
V_2 -> V_42 = V_23 ;
}
V_10 = F_21 ( V_2 , V_21 , & V_7 -> V_17 ) ;
if ( V_10 ) {
F_3 ( V_9 -> V_13 , L_6 , V_10 ) ;
V_2 -> V_42 = V_24 ;
F_15 ( V_2 ) ;
return V_10 ;
}
if ( ! V_43 && V_7 -> V_23 )
V_7 -> V_44 = F_22 ( V_7 -> V_23 , V_2 ,
& V_7 -> V_17 -> V_18 ) ;
if ( V_7 -> V_45 ) {
T_1 V_46 = F_23 ( V_7 -> V_45 -> V_47 ) ;
V_46 += V_7 -> V_45 -> V_48 ;
F_24 ( V_2 , V_46 , V_7 -> V_44 ,
V_49 ) ;
}
if ( V_7 -> V_4 )
F_25 ( V_9 , V_7 -> V_4 , V_7 -> V_17 ) ;
F_26 ( V_2 ) ;
return 0 ;
}
int F_27 ( struct V_8 * V_9 )
{
int V_10 ;
if ( V_9 -> V_50 ) {
return 0 ;
}
V_10 = F_28 ( V_9 , & V_9 -> V_11 ,
V_51 * 64 * 1024 ,
V_52 ,
V_53 ) ;
if ( V_10 ) {
return V_10 ;
}
V_10 = F_29 ( V_9 , & V_9 -> V_11 ) ;
if ( V_10 ) {
return V_10 ;
}
V_9 -> V_50 = true ;
if ( F_30 ( V_9 ) ) {
F_3 ( V_9 -> V_13 , L_7 ) ;
}
return 0 ;
}
void F_31 ( struct V_8 * V_9 )
{
if ( V_9 -> V_50 ) {
F_32 ( V_9 , & V_9 -> V_11 ) ;
F_33 ( V_9 , & V_9 -> V_11 ) ;
V_9 -> V_50 = false ;
}
}
int F_34 ( struct V_8 * V_9 )
{
unsigned V_25 ;
int V_10 ;
for ( V_25 = 0 ; V_25 < V_54 ; ++ V_25 ) {
struct V_1 * V_2 = V_9 -> V_55 [ V_25 ] ;
if ( ! V_2 || ! V_2 -> V_27 )
continue;
V_10 = F_35 ( V_2 ) ;
if ( V_10 ) {
V_2 -> V_27 = false ;
V_9 -> V_56 = false ;
if ( V_2 == & V_9 -> V_57 . V_58 [ 0 ] ) {
F_36 ( L_8 , V_10 ) ;
V_9 -> V_59 = false ;
return V_10 ;
} else {
F_36 ( L_9 , V_25 , V_10 ) ;
}
}
}
return 0 ;
}
static int F_37 ( struct V_60 * V_61 , void * V_62 )
{
struct V_63 * V_64 = (struct V_63 * ) V_61 -> V_65 ;
struct V_66 * V_13 = V_64 -> V_67 -> V_13 ;
struct V_8 * V_9 = V_13 -> V_68 ;
F_38 ( & V_9 -> V_11 , V_61 ) ;
return 0 ;
}
static int F_30 ( struct V_8 * V_9 )
{
#if F_39 ( V_69 )
return F_40 ( V_9 , V_70 , 1 ) ;
#else
return 0 ;
#endif
}
