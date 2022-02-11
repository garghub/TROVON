static bool F_1 ( int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_3 [ V_2 ] . V_4 ; V_2 ++ ) ;
return V_1 >= 0 && V_1 < V_2 ;
}
int F_2 ( struct V_5 * V_6 , int V_1 )
{
if ( ! F_1 ( V_1 ) ) {
F_3 ( L_1 , V_1 ) ;
return - V_7 ;
}
if ( V_6 -> V_8 -> V_9 & V_10 ) {
F_3 ( L_2 ,
V_6 -> V_8 -> V_11 ) ;
return - V_12 ;
}
if ( F_4 ( V_6 ) ) {
F_3 ( L_3 ,
V_6 -> V_8 -> V_11 ) ;
return - V_12 ;
}
if ( F_5 ( V_1 ) && V_6 -> V_13 . V_14 ) {
F_6 ( L_4 ,
V_6 -> V_8 -> V_11 , V_3 [ V_1 ] . V_4 ) ;
V_6 -> V_13 . V_14 = 0 ;
V_6 -> V_13 . V_15 = V_16 ;
F_6 ( L_5 ,
V_6 -> V_8 -> V_11 , V_6 -> V_13 . V_15 ) ;
}
V_6 -> V_13 . V_17 = V_18 ;
V_6 -> V_13 . V_1 = V_1 ;
return 0 ;
}
static struct V_19 * F_7 ( struct V_5 * V_6 ,
struct V_20 * V_20 )
{
return F_8 ( V_6 -> V_13 . V_1 ) && V_20 ? V_20 -> V_8 : NULL ;
}
struct V_19 * F_9 ( struct V_5 * V_6 )
{
struct V_20 * V_20 = F_10 ( V_6 -> V_21 ) ;
return F_7 ( V_6 , V_20 ) ;
}
struct V_19 * F_11 ( struct V_5 * V_6 )
{
return F_7 ( V_6 , V_6 -> V_21 ) ;
}
int F_12 ( struct V_5 * V_6 ,
struct V_19 * V_22 )
{
int V_23 = 0 ;
if ( V_22 ) {
if ( ! F_13 ( V_22 ) ) {
F_3 ( L_6 ,
V_22 -> V_11 ) ;
return - V_7 ;
}
if ( V_6 -> V_8 != F_14 ( V_22 ) ) {
F_3 ( L_7 ,
V_6 -> V_8 -> V_11 , V_22 -> V_11 ) ;
return - V_7 ;
}
}
if ( ! F_8 ( V_6 -> V_13 . V_1 ) ) {
F_3 ( L_8 ,
V_6 -> V_8 -> V_11 , V_6 -> V_8 -> V_11 , V_6 -> V_13 . V_1 ) ;
return - V_7 ;
}
F_15 () ;
F_16 ( & V_6 -> V_24 ) ;
F_17 ( & V_6 -> V_25 ) ;
if ( ! V_22 ) {
F_6 ( L_9 ,
V_6 -> V_8 -> V_11 ) ;
F_18 ( V_6 -> V_21 , NULL ) ;
F_19 ( V_6 ) ;
} else {
struct V_20 * V_26 = V_6 -> V_21 ;
struct V_20 * V_27 = F_20 ( V_22 ) ;
F_21 ( ! V_27 ) ;
if ( V_27 == V_26 ) {
F_6 ( L_10 ,
V_6 -> V_8 -> V_11 , V_27 -> V_8 -> V_11 ) ;
} else {
if ( V_26 && ( V_27 -> V_28 == V_29 ) &&
F_22 ( V_27 -> V_8 ) ) {
F_6 ( L_11 ,
V_6 -> V_8 -> V_11 , V_27 -> V_8 -> V_11 ) ;
F_23 ( V_6 , V_27 ) ;
} else {
F_3 ( L_12 ,
V_6 -> V_8 -> V_11 , V_27 -> V_8 -> V_11 ,
V_27 -> V_8 -> V_11 ) ;
V_23 = - V_7 ;
}
}
}
F_24 ( & V_6 -> V_25 ) ;
F_25 ( & V_6 -> V_24 ) ;
F_26 () ;
return V_23 ;
}
