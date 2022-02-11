static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & ( F_2 ( V_5 ) ) ;
struct V_9 * V_10 ;
T_1 V_11 ;
if ( F_3 ( V_5 ) != V_12 )
return 0 ;
F_4 ( V_2 , L_1
L_2 ) ;
F_5 ( & ( F_2 ( V_5 ) . V_13 ) ) ;
V_11 = V_8 -> V_14 ;
for (; V_11 != V_15 ;
V_11 = V_10 -> V_16 ) {
V_10 = & ( V_8 -> V_17 [ V_11 ] ) ;
F_4 ( V_2 , L_3 ,
& V_10 -> V_18 ,
& V_10 -> V_19 ,
& V_10 -> V_20 ,
V_10 -> V_21 -> V_22 -> V_23 ) ;
}
F_6 ( & ( F_2 ( V_5 ) . V_13 ) ) ;
return 0 ;
}
static int F_7 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
return F_8 ( V_25 , F_1 , V_24 -> V_26 ) ;
}
void F_9 ( struct V_4 * V_5 )
{
if ( ! V_27 )
return;
V_5 -> V_28 =
F_10 ( V_5 -> V_22 -> V_23 , V_27 ) ;
if ( ! V_5 -> V_28 ) {
F_11 ( V_5 -> V_22 , L_4 ) ;
return;
}
F_12 ( L_5 , 0400 , V_5 -> V_28 ,
V_5 , & V_29 ) ;
}
void F_13 ( struct V_4 * V_5 )
{
if ( ! V_27 )
return;
F_14 ( V_5 -> V_28 ) ;
}
void F_15 ( struct V_4 * V_5 )
{
struct V_30 * V_31 ;
if ( ! V_27 )
return;
V_31 = F_16 ( V_27 , V_5 -> V_28 ,
V_27 , V_5 -> V_22 -> V_23 ) ;
if ( V_31 ) {
V_5 -> V_28 = V_31 ;
} else {
F_11 ( V_5 -> V_22 , L_6 ) ;
F_13 ( V_5 ) ;
}
}
void F_17 ( void )
{
V_27 = F_10 ( L_7 , NULL ) ;
if ( ! V_27 ) {
F_18 ( L_8 ) ;
}
}
void F_19 ( void )
{
F_14 ( V_27 ) ;
V_27 = NULL ;
}
void F_9 ( struct V_4 * V_5 )
{
}
void F_13 ( struct V_4 * V_5 )
{
}
void F_15 ( struct V_4 * V_5 )
{
}
void F_17 ( void )
{
}
void F_19 ( void )
{
}
