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
F_8 ( & V_14 -> V_35 ) ;
V_12 = F_9 ( & V_9 ) ;
if ( F_10 ( V_12 ) ) {
V_4 = F_11 ( V_12 ) ;
F_12 ( L_4 ) ;
goto V_36;
}
F_5 ( V_11 ) ;
F_13 ( & V_12 -> V_6 ) ;
F_14 ( & V_12 -> V_6 ) ;
F_15 ( & V_12 -> V_6 ) ;
return V_12 ;
V_36:
F_5 ( V_11 ) ;
F_5 ( V_14 ) ;
return F_3 ( V_4 ) ;
}
static void F_16 ( struct V_2 * V_3 )
{
F_17 ( V_3 -> V_19 . V_12 ) ;
}
static void F_18 ( struct V_37 * V_38 )
{
}
static void F_19 ( struct V_37 * V_38 )
{
}
static int F_20 ( struct V_2 * V_3 )
{
int V_20 = V_3 -> V_19 . V_20 ;
F_21 ( ! F_22 ( V_3 ) ) ;
F_23 ( V_20 ,
& V_39 ,
V_40 ,
L_5 ) ;
return F_24 ( V_20 , V_3 ) ;
}
static bool F_25 ( struct V_2 * V_3 )
{
int V_41 = false ;
if ( F_26 ( V_3 ) || F_27 ( V_3 ) ) {
static const struct V_42 V_43 [] = {
{ F_28 (PCI_VENDOR_ID_INTEL, 0x0f04 ) } ,
{ F_28 (PCI_VENDOR_ID_INTEL, 0x2284 ) } ,
{}
} ;
if ( ! F_29 ( V_43 ) ) {
F_30 ( L_6 , L_7 ) ;
V_41 = true ;
}
}
return V_41 ;
}
static int F_31 ( struct V_2 * V_3 )
{
int V_4 ;
V_3 -> V_19 . V_20 = F_32 ( 0 ) ;
if ( V_3 -> V_19 . V_20 < 0 ) {
F_12 ( L_8 ,
V_3 -> V_19 . V_20 ) ;
V_4 = V_3 -> V_19 . V_20 ;
goto V_36;
}
F_33 ( L_9 , V_3 -> V_19 . V_20 ) ;
V_4 = F_20 ( V_3 ) ;
if ( V_4 ) {
F_12 ( L_10 ,
V_4 ) ;
goto V_44;
}
V_3 -> V_19 . V_12 = F_1 ( V_3 ) ;
if ( F_10 ( V_3 -> V_19 . V_12 ) ) {
V_4 = F_11 ( V_3 -> V_19 . V_12 ) ;
F_12 ( L_11 ,
V_4 ) ;
goto V_44;
}
F_34 ( V_45 , V_46 ) ;
return 0 ;
V_44:
F_35 ( V_3 -> V_19 . V_20 ) ;
V_36:
V_3 -> V_19 . V_20 = - 1 ;
V_3 -> V_19 . V_12 = NULL ;
return V_4 ;
}
void F_36 ( struct V_2 * V_3 )
{
int V_4 ;
if ( ! F_37 ( V_3 ) )
return;
V_4 = F_38 ( V_3 -> V_19 . V_20 ) ;
if ( V_4 )
F_39 ( L_12 ,
V_4 ) ;
}
int F_40 ( struct V_2 * V_3 )
{
int V_4 = - V_47 ;
if ( F_25 ( V_3 ) ) {
V_4 = F_31 ( V_3 ) ;
if ( V_4 < 0 )
F_12 ( L_13 ) ;
}
return V_4 ;
}
void F_41 ( struct V_2 * V_3 )
{
struct V_48 * V_49 ;
if ( ! F_37 ( V_3 ) )
return;
V_49 = F_42 ( V_3 -> V_19 . V_20 ) ;
F_16 ( V_3 ) ;
F_35 ( V_3 -> V_19 . V_20 ) ;
}
void F_43 ( struct V_2 * V_3 ,
void * V_50 , int V_51 , int V_52 , int V_53 ,
bool V_54 , int V_55 )
{
unsigned long V_56 ;
struct V_13 * V_14 = NULL ;
T_1 V_57 ;
if ( ! F_37 ( V_3 ) )
return;
V_14 = F_44 (
& ( V_3 -> V_19 . V_12 -> V_6 ) ) ;
F_45 ( & V_14 -> V_35 , V_56 ) ;
V_57 = F_46 ( F_47 ( V_51 ) ) ;
if ( V_50 != NULL ) {
memcpy ( V_14 -> V_50 . V_58 , V_50 ,
V_59 ) ;
V_14 -> V_50 . V_60 = V_51 ;
V_14 -> V_50 . V_61 = V_52 ;
V_14 -> V_62 = true ;
V_14 -> V_54 = V_54 ;
if ( V_53 )
V_14 -> V_63 = V_53 ;
if ( V_55 )
V_14 -> V_55 = V_55 ;
F_34 ( F_47 ( V_51 ) ,
V_57 & ~ V_64 ) ;
} else {
memset ( V_14 -> V_50 . V_58 , 0 ,
V_59 ) ;
V_14 -> V_62 = false ;
V_14 -> V_54 = false ;
F_34 ( F_47 ( V_51 ) ,
V_57 | V_64 ) ;
}
if ( V_14 -> V_65 )
V_14 -> V_65 ( V_3 -> V_19 . V_12 ) ;
else
V_14 -> V_66 = true ;
F_48 ( & V_14 -> V_35 ,
V_56 ) ;
}
