int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 ,
unsigned V_8 )
{
int V_9 ;
V_9 = F_2 ( V_2 , & V_2 -> V_10 , & V_5 -> V_11 , V_8 , 256 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_12 , L_1 , V_9 ) ;
return V_9 ;
}
F_4 ( & V_5 -> V_13 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_14 = NULL ;
V_5 -> V_15 = F_5 ( V_5 -> V_11 ) ;
V_5 -> V_7 = V_7 ;
if ( V_7 ) {
V_5 -> V_16 = V_5 -> V_11 -> V_17 + V_18 ;
} else {
V_5 -> V_16 = F_6 ( V_5 -> V_11 ) ;
}
V_5 -> V_19 = false ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
F_8 ( V_2 , & V_5 -> V_13 , V_5 -> V_14 ) ;
F_9 ( V_2 , & V_5 -> V_11 , V_5 -> V_14 ) ;
F_10 ( & V_5 -> V_14 ) ;
}
int F_11 ( struct V_1 * V_2 , struct V_4 * V_5 ,
struct V_4 * V_20 , bool V_21 )
{
struct V_22 * V_3 = & V_2 -> V_3 [ V_5 -> V_3 ] ;
int V_9 = 0 ;
if ( ! V_5 -> V_23 || ! V_3 -> V_24 ) {
F_3 ( V_2 -> V_12 , L_2 ) ;
return - V_25 ;
}
V_9 = F_12 ( V_2 , V_3 , 64 + V_26 * 8 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_12 , L_3 , V_9 ) ;
return V_9 ;
}
if ( V_5 -> V_7 ) {
struct V_27 * V_28 ;
V_28 = F_13 ( V_2 , V_5 -> V_7 , V_5 -> V_3 ) ;
F_14 ( & V_5 -> V_13 , V_28 ) ;
}
V_9 = F_15 ( V_2 , & V_5 -> V_13 , V_5 -> V_3 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_12 , L_4 , V_9 ) ;
F_16 ( V_2 , V_3 ) ;
return V_9 ;
}
if ( V_5 -> V_7 )
F_17 ( V_2 , V_5 -> V_7 , V_5 -> V_3 ,
V_5 -> V_13 . V_29 ) ;
if ( V_20 ) {
F_18 ( V_2 , V_20 -> V_3 , V_20 ) ;
F_8 ( V_2 , & V_20 -> V_13 , NULL ) ;
}
F_18 ( V_2 , V_5 -> V_3 , V_5 ) ;
V_9 = F_19 ( V_2 , & V_5 -> V_14 , V_5 -> V_3 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_12 , L_5 , V_9 ) ;
F_16 ( V_2 , V_3 ) ;
return V_9 ;
}
if ( V_20 ) {
V_20 -> V_14 = F_20 ( V_5 -> V_14 ) ;
}
if ( V_5 -> V_7 )
F_21 ( V_2 , V_5 -> V_7 , V_5 -> V_14 ) ;
F_22 ( V_2 , V_3 , V_21 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
int V_9 ;
if ( V_2 -> V_30 ) {
return 0 ;
}
if ( V_2 -> V_31 >= V_32 ) {
V_9 = F_24 ( V_2 , & V_2 -> V_10 ,
V_33 * 64 * 1024 ,
V_34 ,
V_35 ,
V_36 ) ;
} else {
V_9 = F_24 ( V_2 , & V_2 -> V_10 ,
V_33 * 64 * 1024 ,
V_34 ,
V_35 , 0 ) ;
}
if ( V_9 ) {
return V_9 ;
}
V_9 = F_25 ( V_2 , & V_2 -> V_10 ) ;
if ( V_9 ) {
return V_9 ;
}
V_2 -> V_30 = true ;
if ( F_26 ( V_2 ) ) {
F_3 ( V_2 -> V_12 , L_6 ) ;
}
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_30 ) {
F_28 ( V_2 , & V_2 -> V_10 ) ;
F_29 ( V_2 , & V_2 -> V_10 ) ;
V_2 -> V_30 = false ;
}
}
int F_30 ( struct V_1 * V_2 )
{
unsigned V_37 ;
int V_9 ;
for ( V_37 = 0 ; V_37 < V_38 ; ++ V_37 ) {
struct V_22 * V_3 = & V_2 -> V_3 [ V_37 ] ;
if ( ! V_3 -> V_24 )
continue;
V_9 = F_31 ( V_2 , V_37 , V_3 ) ;
if ( V_9 ) {
F_32 ( V_2 , V_37 ) ;
V_3 -> V_24 = false ;
V_2 -> V_39 = false ;
if ( V_37 == V_40 ) {
F_33 ( L_7 , V_9 ) ;
V_2 -> V_41 = false ;
return V_9 ;
} else {
F_33 ( L_8 , V_37 , V_9 ) ;
}
}
}
return 0 ;
}
static int F_34 ( struct V_42 * V_43 , void * V_44 )
{
struct V_45 * V_46 = (struct V_45 * ) V_43 -> V_47 ;
struct V_48 * V_12 = V_46 -> V_49 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_50 ;
F_35 ( & V_2 -> V_10 , V_43 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
#if F_36 ( V_51 )
return F_37 ( V_2 , V_52 , 1 ) ;
#else
return 0 ;
#endif
}
