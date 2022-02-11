static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & ( F_2 ( V_5 ) ) ;
struct V_9 * V_10 ;
T_1 V_11 ;
if ( V_5 -> V_12 . V_13 != V_14 )
return 0 ;
F_3 ( V_2 , L_1
L_2 ) ;
F_4 ( & ( F_2 ( V_5 ) . V_15 ) ) ;
V_11 = V_8 -> V_16 ;
for (; V_11 != V_17 ; V_11 = V_10 -> V_18 ) {
V_10 = & ( V_8 -> V_19 [ V_11 ] ) ;
F_3 ( V_2 , L_3 ,
& V_10 -> V_20 ,
& V_10 -> V_21 ,
& V_10 -> V_22 ,
V_10 -> V_23 -> V_24 -> V_25 ) ;
}
F_5 ( & ( F_2 ( V_5 ) . V_15 ) ) ;
return 0 ;
}
static int F_6 ( struct V_26 * V_26 , struct V_27 * V_27 )
{
return F_7 ( V_27 , F_1 , V_26 -> V_28 ) ;
}
void F_8 ( struct V_4 * V_5 )
{
if ( ! V_29 )
return;
V_5 -> V_30 =
F_9 ( V_5 -> V_24 -> V_25 , V_29 ) ;
if ( ! V_5 -> V_30 ) {
F_10 ( L_4 ,
V_5 -> V_24 -> V_25 ) ;
return;
}
F_11 ( L_5 , 0400 , V_5 -> V_30 ,
V_5 , & V_31 ) ;
}
void F_12 ( struct V_4 * V_5 )
{
if ( ! V_29 )
return;
F_13 ( V_5 -> V_30 ) ;
}
void F_14 ( struct V_4 * V_5 )
{
struct V_32 * V_33 ;
if ( ! V_29 )
return;
V_33 = F_15 ( V_29 , V_5 -> V_30 ,
V_29 , V_5 -> V_24 -> V_25 ) ;
if ( V_33 ) {
V_5 -> V_30 = V_33 ;
} else {
F_10 ( L_6
L_7 ,
V_5 -> V_24 -> V_25 ) ;
F_12 ( V_5 ) ;
}
}
void F_16 ( void )
{
V_29 = F_9 ( L_8 , NULL ) ;
if ( ! V_29 ) {
F_10 ( L_9
L_10 ) ;
}
}
void F_17 ( void )
{
F_13 ( V_29 ) ;
V_29 = NULL ;
}
void F_8 ( struct V_4 * V_5 )
{
}
void F_12 ( struct V_4 * V_5 )
{
}
void F_14 ( struct V_4 * V_5 )
{
}
void F_16 ( void )
{
}
void F_17 ( void )
{
}
