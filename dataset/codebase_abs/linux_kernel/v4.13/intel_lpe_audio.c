static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
int V_4 ;
struct V_5 * V_6 = & V_3 -> V_7 ;
struct V_8 V_9 = {} ;
struct V_10 * V_11 ;
struct V_1 * V_12 ;
struct V_13 * V_14 ;
V_14 = F_2 ( sizeof( * V_14 ) , V_15 ) ;
if ( ! V_14 )
return F_3 ( - V_16 ) ;
V_11 = F_4 ( 2 , sizeof( * V_11 ) , V_15 ) ;
if ( ! V_11 ) {
F_5 ( V_14 ) ;
return F_3 ( - V_16 ) ;
}
V_11 [ 0 ] . V_17 = V_11 [ 0 ] . V_18 = V_3 -> V_19 . V_20 ;
V_11 [ 0 ] . V_21 = V_22 ;
V_11 [ 0 ] . V_23 = L_1 ;
V_11 [ 1 ] . V_17 = F_6 ( V_6 -> V_24 , 0 ) +
V_25 ;
V_11 [ 1 ] . V_18 = F_6 ( V_6 -> V_24 , 0 ) +
V_25 + V_26 - 1 ;
V_11 [ 1 ] . V_21 = V_27 ;
V_11 [ 1 ] . V_23 = L_2 ;
V_9 . V_28 = V_6 -> V_6 ;
V_9 . V_23 = L_3 ;
V_9 . V_29 = - 1 ;
V_9 . V_30 = V_11 ;
V_9 . V_31 = 2 ;
V_9 . V_32 = V_14 ;
V_9 . V_33 = sizeof( * V_14 ) ;
V_9 . V_34 = F_7 ( 32 ) ;
V_14 -> V_35 = F_8 ( V_3 ) -> V_35 ;
V_14 -> V_36 = F_9 ( V_3 ) ? 3 : 2 ;
V_14 -> V_37 [ 0 ] . V_38 = - 1 ;
V_14 -> V_37 [ 1 ] . V_38 = - 1 ;
V_14 -> V_37 [ 2 ] . V_38 = - 1 ;
F_10 ( & V_14 -> V_39 ) ;
V_12 = F_11 ( & V_9 ) ;
if ( F_12 ( V_12 ) ) {
V_4 = F_13 ( V_12 ) ;
F_14 ( L_4 ) ;
goto V_40;
}
F_5 ( V_11 ) ;
F_15 ( & V_12 -> V_6 ) ;
F_16 ( & V_12 -> V_6 ) ;
F_17 ( & V_12 -> V_6 ) ;
return V_12 ;
V_40:
F_5 ( V_11 ) ;
F_5 ( V_14 ) ;
return F_3 ( V_4 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
F_19 ( V_3 -> V_19 . V_12 ) ;
}
static void F_20 ( struct V_41 * V_42 )
{
}
static void F_21 ( struct V_41 * V_42 )
{
}
static int F_22 ( struct V_2 * V_3 )
{
int V_20 = V_3 -> V_19 . V_20 ;
F_23 ( ! F_24 ( V_3 ) ) ;
F_25 ( V_20 ,
& V_43 ,
V_44 ,
L_5 ) ;
return F_26 ( V_20 , V_3 ) ;
}
static bool F_27 ( struct V_2 * V_3 )
{
int V_45 = false ;
if ( F_28 ( V_3 ) || F_9 ( V_3 ) ) {
static const struct V_46 V_47 [] = {
{ F_29 (PCI_VENDOR_ID_INTEL, 0x0f04 ) } ,
{ F_29 (PCI_VENDOR_ID_INTEL, 0x2284 ) } ,
{}
} ;
if ( ! F_30 ( V_47 ) ) {
F_31 ( L_6 , L_7 ) ;
V_45 = true ;
}
}
return V_45 ;
}
static int F_32 ( struct V_2 * V_3 )
{
int V_4 ;
V_3 -> V_19 . V_20 = F_33 ( 0 ) ;
if ( V_3 -> V_19 . V_20 < 0 ) {
F_14 ( L_8 ,
V_3 -> V_19 . V_20 ) ;
V_4 = V_3 -> V_19 . V_20 ;
goto V_40;
}
F_34 ( L_9 , V_3 -> V_19 . V_20 ) ;
V_4 = F_22 ( V_3 ) ;
if ( V_4 ) {
F_14 ( L_10 ,
V_4 ) ;
goto V_48;
}
V_3 -> V_19 . V_12 = F_1 ( V_3 ) ;
if ( F_12 ( V_3 -> V_19 . V_12 ) ) {
V_4 = F_13 ( V_3 -> V_19 . V_12 ) ;
F_14 ( L_11 ,
V_4 ) ;
goto V_48;
}
F_35 ( V_49 , V_50 ) ;
return 0 ;
V_48:
F_36 ( V_3 -> V_19 . V_20 ) ;
V_40:
V_3 -> V_19 . V_20 = - 1 ;
V_3 -> V_19 . V_12 = NULL ;
return V_4 ;
}
void F_37 ( struct V_2 * V_3 )
{
int V_4 ;
if ( ! F_38 ( V_3 ) )
return;
V_4 = F_39 ( V_3 -> V_19 . V_20 ) ;
if ( V_4 )
F_40 ( L_12 ,
V_4 ) ;
}
int F_41 ( struct V_2 * V_3 )
{
int V_4 = - V_51 ;
if ( F_27 ( V_3 ) ) {
V_4 = F_32 ( V_3 ) ;
if ( V_4 < 0 )
F_14 ( L_13 ) ;
}
return V_4 ;
}
void F_42 ( struct V_2 * V_3 )
{
struct V_52 * V_53 ;
if ( ! F_38 ( V_3 ) )
return;
V_53 = F_43 ( V_3 -> V_19 . V_20 ) ;
F_18 ( V_3 ) ;
F_36 ( V_3 -> V_19 . V_20 ) ;
}
void F_44 ( struct V_2 * V_3 ,
enum V_38 V_38 , enum V_37 V_37 ,
const void * V_54 , int V_55 , bool V_56 )
{
unsigned long V_57 ;
struct V_13 * V_14 ;
struct V_58 * V_59 ;
T_1 V_60 ;
if ( ! F_38 ( V_3 ) )
return;
V_14 = F_45 ( & V_3 -> V_19 . V_12 -> V_6 ) ;
V_59 = & V_14 -> V_37 [ V_37 - V_61 ] ;
F_46 ( & V_14 -> V_39 , V_57 ) ;
V_60 = F_47 ( F_48 ( V_37 ) ) ;
if ( V_54 != NULL ) {
memcpy ( V_59 -> V_54 , V_54 , V_62 ) ;
V_59 -> V_38 = V_38 ;
V_59 -> V_55 = V_55 ;
V_59 -> V_56 = V_56 ;
F_35 ( F_48 ( V_37 ) ,
V_60 & ~ V_63 ) ;
} else {
memset ( V_59 -> V_54 , 0 , V_62 ) ;
V_59 -> V_38 = - 1 ;
V_59 -> V_55 = 0 ;
V_59 -> V_56 = false ;
F_35 ( F_48 ( V_37 ) ,
V_60 | V_63 ) ;
}
if ( V_14 -> V_64 )
V_14 -> V_64 ( V_3 -> V_19 . V_12 , V_37 - V_61 ) ;
F_49 ( & V_14 -> V_39 , V_57 ) ;
}
