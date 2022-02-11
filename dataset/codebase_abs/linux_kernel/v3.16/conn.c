static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , F_3 ( * V_4 ) , V_5 . V_6 ) ;
struct V_7 * V_8 = V_7 ( V_4 ) ;
struct V_9 * V_10 = V_9 ( V_4 ) ;
T_1 V_11 = V_12 ;
if ( V_10 -> V_13 ( V_10 , 0 , V_14 , V_4 -> V_5 . V_15 -> V_16 ) )
V_11 = V_17 ;
F_4 ( V_8 -> V_5 , V_11 , V_4 -> V_16 ) ;
F_5 ( V_4 -> V_5 . V_15 ) ;
}
static int
F_6 ( void * V_18 , T_1 type , int V_16 )
{
struct V_3 * V_4 = V_18 ;
F_7 ( L_1 , type ) ;
F_8 ( & V_4 -> V_5 . V_6 ) ;
return V_19 ;
}
int
F_9 ( struct V_20 * V_21 , bool V_22 )
{
struct V_3 * V_4 = ( void * ) V_21 ;
if ( V_4 -> V_5 . V_15 )
F_10 ( V_4 -> V_5 . V_15 ) ;
return F_11 ( & V_4 -> V_23 , V_22 ) ;
}
int
F_12 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = ( void * ) V_21 ;
int V_24 = F_13 ( & V_4 -> V_23 ) ;
if ( V_24 == 0 ) {
if ( V_4 -> V_5 . V_15 )
F_5 ( V_4 -> V_5 . V_15 ) ;
}
return V_24 ;
}
void
F_14 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = ( void * ) V_21 ;
F_15 ( NULL , & V_4 -> V_5 . V_15 ) ;
F_16 ( & V_4 -> V_23 ) ;
}
int
F_17 ( struct V_20 * V_25 ,
struct V_20 * V_26 ,
struct V_27 * V_28 ,
struct V_29 * V_30 , int V_16 ,
int V_31 , void * * V_32 )
{
static const T_2 V_5 [] = { 0x07 , 0x08 , 0x51 , 0x52 , 0x5e , 0x5f , 0x60 } ;
struct V_9 * V_10 = V_9 ( V_25 ) ;
struct V_7 * V_8 = ( void * ) V_26 ;
struct V_3 * V_4 ;
struct V_33 * V_34 ;
struct V_35 V_36 ;
int V_24 ;
F_18 (outp, &disp->outp, head) {
if ( V_34 -> V_4 && V_34 -> V_4 -> V_16 == V_16 ) {
F_19 ( & F_20 ( V_34 -> V_4 ) -> V_37 ) ;
* V_32 = V_34 -> V_4 ;
return 1 ;
}
}
V_24 = F_21 ( V_25 , V_26 , V_28 , 0 , V_31 , V_32 ) ;
V_4 = * V_32 ;
if ( V_24 )
return V_24 ;
V_4 -> V_30 = * V_30 ;
V_4 -> V_16 = V_16 ;
F_7 ( L_2 ,
V_30 -> type , V_30 -> V_38 , V_30 -> V_5 , V_30 -> V_39 ,
V_30 -> V_40 , V_30 -> V_41 , V_30 -> V_42 ) ;
if ( ( V_30 -> V_5 = F_22 ( V_30 -> V_5 ) ) ) {
if ( -- V_30 -> V_5 >= F_23 ( V_5 ) ) {
F_24 ( L_3 , V_30 -> V_5 ) ;
goto V_43;
}
V_30 -> V_5 = V_5 [ V_30 -> V_5 ] ;
V_24 = V_10 -> V_44 ( V_10 , 0 , V_30 -> V_5 , V_14 , & V_36 ) ;
if ( V_24 ) {
F_24 ( L_4 , V_30 -> V_5 , V_24 ) ;
goto V_43;
}
V_24 = F_25 ( V_10 -> V_45 , V_46 ,
V_36 . line , F_6 ,
V_4 , & V_4 -> V_5 . V_15 ) ;
if ( V_24 ) {
F_24 ( L_5 , V_30 -> V_5 , V_24 ) ;
} else {
F_7 ( L_6 , V_30 -> V_5 ) ;
}
}
V_43:
F_26 ( & V_4 -> V_5 . V_6 , F_1 ) ;
return 0 ;
}
int
F_27 ( struct V_20 * V_25 ,
struct V_20 * V_26 ,
struct V_27 * V_28 , void * V_30 , T_1 V_16 ,
struct V_20 * * V_32 )
{
struct V_3 * V_4 ;
int V_24 ;
V_24 = F_28 ( V_25 , V_26 , V_28 , V_30 , V_16 , & V_4 ) ;
* V_32 = F_20 ( V_4 ) ;
if ( V_24 )
return V_24 ;
return 0 ;
}
