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
return V_12 ;
V_36:
F_5 ( V_11 ) ;
F_5 ( V_14 ) ;
return F_3 ( V_4 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
F_14 ( V_3 -> V_19 . V_12 ) ;
F_5 ( V_3 -> V_19 . V_12 -> V_6 . V_34 ) ;
}
static void F_15 ( struct V_37 * V_38 )
{
struct V_2 * V_3 = V_38 -> V_39 ;
unsigned long V_40 ;
T_1 V_41 = ( V_42 |
V_43 ) ;
if ( F_16 ( V_3 ) )
V_41 |= V_44 ;
F_17 ( & V_3 -> V_45 , V_40 ) ;
V_3 -> V_46 &= ~ V_41 ;
F_18 ( V_47 , V_41 ) ;
F_18 ( V_47 , V_41 ) ;
F_18 ( V_48 , V_3 -> V_46 ) ;
F_19 ( V_48 ) ;
F_20 ( & V_3 -> V_45 , V_40 ) ;
}
static void F_21 ( struct V_37 * V_38 )
{
struct V_2 * V_3 = V_38 -> V_39 ;
unsigned long V_40 ;
T_1 V_41 = ( V_42 |
V_43 ) ;
if ( F_16 ( V_3 ) )
V_41 |= V_44 ;
F_17 ( & V_3 -> V_45 , V_40 ) ;
V_3 -> V_46 |= V_41 ;
F_18 ( V_48 , V_3 -> V_46 ) ;
F_18 ( V_47 , V_41 ) ;
F_18 ( V_47 , V_41 ) ;
F_19 ( V_47 ) ;
F_20 ( & V_3 -> V_45 , V_40 ) ;
}
static int F_22 ( struct V_2 * V_3 )
{
int V_20 = V_3 -> V_19 . V_20 ;
F_23 ( ! F_24 ( V_3 ) ) ;
F_25 ( V_20 ,
& V_49 ,
V_50 ,
L_5 ) ;
return F_26 ( V_20 , V_3 ) ;
}
static bool F_27 ( struct V_2 * V_3 )
{
int V_51 = false ;
if ( F_28 ( V_3 ) || F_16 ( V_3 ) ) {
static const struct V_52 V_53 [] = {
{ F_29 (PCI_VENDOR_ID_INTEL, 0x0f04 ) } ,
{ F_29 (PCI_VENDOR_ID_INTEL, 0x2284 ) } ,
{}
} ;
if ( ! F_30 ( V_53 ) ) {
F_31 ( L_6 , L_7 ) ;
V_51 = true ;
}
}
return V_51 ;
}
static int F_32 ( struct V_2 * V_3 )
{
int V_4 ;
V_3 -> V_19 . V_20 = F_33 ( 0 ) ;
if ( V_3 -> V_19 . V_20 < 0 ) {
F_12 ( L_8 ,
V_3 -> V_19 . V_20 ) ;
V_4 = V_3 -> V_19 . V_20 ;
goto V_36;
}
F_34 ( L_9 , V_3 -> V_19 . V_20 ) ;
V_4 = F_22 ( V_3 ) ;
if ( V_4 ) {
F_12 ( L_10 ,
V_4 ) ;
goto V_54;
}
V_3 -> V_19 . V_12 = F_1 ( V_3 ) ;
if ( F_10 ( V_3 -> V_19 . V_12 ) ) {
V_4 = F_11 ( V_3 -> V_19 . V_12 ) ;
F_12 ( L_11 ,
V_4 ) ;
goto V_54;
}
F_18 ( V_55 , V_56 ) ;
return 0 ;
V_54:
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
int V_4 = - V_57 ;
if ( F_27 ( V_3 ) ) {
V_4 = F_32 ( V_3 ) ;
if ( V_4 < 0 )
F_12 ( L_13 ) ;
}
return V_4 ;
}
void F_41 ( struct V_2 * V_3 )
{
struct V_58 * V_59 ;
if ( ! F_37 ( V_3 ) )
return;
V_59 = F_42 ( V_3 -> V_19 . V_20 ) ;
F_21 ( & V_59 -> V_37 ) ;
F_13 ( V_3 ) ;
F_35 ( V_3 -> V_19 . V_20 ) ;
}
void F_43 ( struct V_2 * V_3 ,
void * V_60 , int V_61 , int V_62 , int V_63 ,
bool V_64 , int V_65 )
{
unsigned long V_66 ;
struct V_13 * V_14 = NULL ;
T_1 V_67 ;
if ( ! F_37 ( V_3 ) )
return;
V_14 = F_44 (
& ( V_3 -> V_19 . V_12 -> V_6 ) ) ;
F_17 ( & V_14 -> V_35 , V_66 ) ;
V_67 = F_45 ( F_46 ( V_61 ) ) ;
if ( V_60 != NULL ) {
memcpy ( V_14 -> V_60 . V_68 , V_60 ,
V_69 ) ;
V_14 -> V_60 . V_70 = V_61 ;
V_14 -> V_60 . V_71 = V_62 ;
V_14 -> V_72 = true ;
V_14 -> V_64 = V_64 ;
if ( V_63 )
V_14 -> V_73 = V_63 ;
if ( V_65 )
V_14 -> V_65 = V_65 ;
F_18 ( F_46 ( V_61 ) ,
V_67 & ~ V_74 ) ;
} else {
memset ( V_14 -> V_60 . V_68 , 0 ,
V_69 ) ;
V_14 -> V_72 = false ;
V_14 -> V_64 = false ;
F_18 ( F_46 ( V_61 ) ,
V_67 | V_74 ) ;
}
if ( V_14 -> V_75 )
V_14 -> V_75 ( V_3 -> V_19 . V_12 ) ;
else
V_14 -> V_76 = true ;
F_20 ( & V_14 -> V_35 ,
V_66 ) ;
}
