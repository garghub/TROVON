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
else
V_7 -> V_15 = 0 ;
} else {
V_7 -> V_12 = NULL ;
V_7 -> V_14 = NULL ;
V_7 -> V_15 = 0 ;
}
F_6 ( & V_7 -> V_16 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_17 = NULL ;
V_7 -> V_18 = NULL ;
V_7 -> V_4 = V_4 ;
V_7 -> V_19 = 0 ;
V_7 -> V_20 = 0 ;
V_7 -> V_21 = 0 ;
V_7 -> V_22 = 0 ;
V_7 -> V_23 = 0 ;
V_7 -> V_24 = 0 ;
V_7 -> V_25 = 0 ;
return 0 ;
}
void F_7 ( struct V_8 * V_9 , struct V_6 * V_7 )
{
F_8 ( V_9 , & V_7 -> V_16 , V_7 -> V_17 ) ;
F_9 ( V_9 , & V_7 -> V_12 , V_7 -> V_17 ) ;
F_10 ( & V_7 -> V_17 ) ;
}
int F_11 ( struct V_8 * V_9 , unsigned V_26 ,
struct V_6 * V_27 , void * V_28 )
{
struct V_6 * V_7 = & V_27 [ 0 ] ;
struct V_1 * V_2 ;
struct V_29 * V_30 , * V_31 ;
struct V_3 * V_4 ;
unsigned V_32 ;
int V_10 = 0 ;
if ( V_26 == 0 )
return - V_33 ;
V_2 = V_27 -> V_2 ;
V_30 = V_27 -> V_30 ;
V_4 = V_27 -> V_4 ;
if ( ! V_2 -> V_34 ) {
F_3 ( V_9 -> V_13 , L_2 ) ;
return - V_33 ;
}
V_10 = F_12 ( V_2 , ( 256 + V_35 * 8 ) * V_26 ) ;
if ( V_10 ) {
F_3 ( V_9 -> V_13 , L_3 , V_10 ) ;
return V_10 ;
}
if ( V_4 ) {
struct V_36 * V_37 = NULL ;
V_37 = F_13 ( V_27 -> V_2 , V_27 -> V_4 ) ;
F_14 ( & V_27 -> V_16 , V_37 ) ;
}
V_10 = F_15 ( & V_27 -> V_16 , V_2 ) ;
if ( V_10 ) {
F_16 ( V_2 ) ;
F_3 ( V_9 -> V_13 , L_4 , V_10 ) ;
return V_10 ;
}
if ( V_4 ) {
F_17 ( V_2 , V_4 , V_7 -> V_16 . V_38 ) ;
if ( V_2 -> V_39 -> V_40 )
F_18 ( V_2 , V_7 -> V_4 -> V_41 [ V_2 -> V_42 ] . V_43 ,
V_7 -> V_19 , V_7 -> V_20 ,
V_7 -> V_21 , V_7 -> V_22 ,
V_7 -> V_23 , V_7 -> V_24 ) ;
if ( V_2 -> V_39 -> V_44 )
F_19 ( V_2 ) ;
}
V_31 = V_2 -> V_45 ;
for ( V_32 = 0 ; V_32 < V_26 ; ++ V_32 ) {
V_7 = & V_27 [ V_32 ] ;
if ( V_7 -> V_2 != V_2 || V_7 -> V_30 != V_30 || V_7 -> V_4 != V_4 ) {
V_2 -> V_45 = V_31 ;
F_16 ( V_2 ) ;
return - V_33 ;
}
F_20 ( V_2 , V_7 ) ;
V_2 -> V_45 = V_30 ;
}
V_10 = F_21 ( V_2 , V_28 , & V_7 -> V_17 ) ;
if ( V_10 ) {
F_3 ( V_9 -> V_13 , L_5 , V_10 ) ;
V_2 -> V_45 = V_31 ;
F_16 ( V_2 ) ;
return V_10 ;
}
if ( V_7 -> V_18 ) {
T_1 V_46 = F_22 ( V_7 -> V_18 -> V_47 ) ;
V_46 += V_7 -> V_18 -> V_48 ;
F_23 ( V_2 , V_46 , V_7 -> V_17 -> V_49 ,
V_50 ) ;
}
if ( V_7 -> V_4 )
F_24 ( V_9 , V_7 -> V_4 , V_7 -> V_17 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
int F_26 ( struct V_8 * V_9 )
{
int V_10 ;
if ( V_9 -> V_51 ) {
return 0 ;
}
V_10 = F_27 ( V_9 , & V_9 -> V_11 ,
V_52 * 64 * 1024 ,
V_53 ,
V_54 ) ;
if ( V_10 ) {
return V_10 ;
}
V_10 = F_28 ( V_9 , & V_9 -> V_11 ) ;
if ( V_10 ) {
return V_10 ;
}
V_9 -> V_51 = true ;
if ( F_29 ( V_9 ) ) {
F_3 ( V_9 -> V_13 , L_6 ) ;
}
return 0 ;
}
void F_30 ( struct V_8 * V_9 )
{
if ( V_9 -> V_51 ) {
F_31 ( V_9 , & V_9 -> V_11 ) ;
F_32 ( V_9 , & V_9 -> V_11 ) ;
V_9 -> V_51 = false ;
}
}
int F_33 ( struct V_8 * V_9 )
{
unsigned V_32 ;
int V_10 ;
for ( V_32 = 0 ; V_32 < V_55 ; ++ V_32 ) {
struct V_1 * V_2 = V_9 -> V_56 [ V_32 ] ;
if ( ! V_2 || ! V_2 -> V_34 )
continue;
V_10 = F_34 ( V_2 ) ;
if ( V_10 ) {
V_2 -> V_34 = false ;
V_9 -> V_57 = false ;
if ( V_2 == & V_9 -> V_58 . V_59 [ 0 ] ) {
F_35 ( L_7 , V_10 ) ;
V_9 -> V_60 = false ;
return V_10 ;
} else {
F_35 ( L_8 , V_32 , V_10 ) ;
}
}
}
return 0 ;
}
static int F_36 ( struct V_61 * V_62 , void * V_63 )
{
struct V_64 * V_65 = (struct V_64 * ) V_62 -> V_66 ;
struct V_67 * V_13 = V_65 -> V_68 -> V_13 ;
struct V_8 * V_9 = V_13 -> V_69 ;
F_37 ( & V_9 -> V_11 , V_62 ) ;
return 0 ;
}
static int F_29 ( struct V_8 * V_9 )
{
#if F_38 ( V_70 )
return F_39 ( V_9 , V_71 , 1 ) ;
#else
return 0 ;
#endif
}
