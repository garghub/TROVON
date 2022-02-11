static bool F_1 ( const struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 )
{
const T_1 * V_6 ;
T_1 V_7 [ 8 ] ;
V_6 = F_2 ( V_2 , V_3 + F_3 ( struct V_8 , V_9 ) ,
sizeof( V_7 ) , V_7 ) ;
if ( V_6 == NULL )
return false ;
memcpy ( V_5 -> V_10 . V_11 . V_12 , V_6 , sizeof( V_5 -> V_10 . V_11 . V_12 ) ) ;
memcpy ( V_5 -> V_13 . V_11 . V_12 , V_6 + 4 , sizeof( V_5 -> V_13 . V_11 . V_12 ) ) ;
return true ;
}
static bool F_4 ( struct V_4 * V_5 ,
const struct V_4 * V_14 )
{
memcpy ( V_5 -> V_10 . V_11 . V_12 , V_14 -> V_13 . V_11 . V_12 , sizeof( V_5 -> V_10 . V_11 . V_12 ) ) ;
memcpy ( V_5 -> V_13 . V_11 . V_12 , V_14 -> V_10 . V_11 . V_12 , sizeof( V_5 -> V_13 . V_11 . V_12 ) ) ;
return true ;
}
static int F_5 ( struct V_15 * V_16 ,
const struct V_4 * V_5 )
{
return F_6 ( V_16 , L_1 ,
V_5 -> V_10 . V_11 . V_12 , V_5 -> V_13 . V_11 . V_12 ) ;
}
static int F_7 ( const struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_17 , T_2 * V_18 )
{
unsigned int V_19 = V_3 + sizeof( struct V_8 ) ;
T_3 V_20 ;
int V_21 ;
T_4 V_22 ;
if ( F_8 ( V_2 , V_3 + F_3 ( struct V_8 , V_22 ) ,
& V_22 , sizeof( V_22 ) ) != 0 ) {
F_9 ( L_2 ) ;
return - V_23 ;
}
V_21 = F_10 ( V_2 , V_19 , & V_22 , & V_20 ) ;
if ( V_21 < 0 || ( V_20 & F_11 ( ~ 0x7 ) ) != 0 ) {
F_9 ( L_3 ) ;
return - V_23 ;
}
* V_17 = V_21 ;
* V_18 = V_22 ;
return V_23 ;
}
static unsigned int F_12 ( unsigned int V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 ,
int (* F_13)( struct V_1 * ) )
{
struct V_28 * V_29 ;
const struct V_30 * V_31 ;
const struct V_32 * V_33 ;
enum V_34 V_35 ;
unsigned int V_36 ;
T_3 V_20 ;
int V_21 ;
T_4 V_22 ;
V_29 = F_14 ( V_2 , & V_35 ) ;
if ( ! V_29 || V_35 == V_37 )
return V_23 ;
V_31 = F_15 ( V_29 ) ;
if ( ! V_31 )
return V_23 ;
V_33 = F_16 ( V_31 -> V_33 ) ;
if ( ! V_33 )
return V_23 ;
V_22 = F_17 ( V_2 ) -> V_22 ;
V_21 = F_10 ( V_2 , sizeof( struct V_8 ) , & V_22 ,
& V_20 ) ;
if ( V_21 < 0 || ( V_20 & F_11 ( ~ 0x7 ) ) != 0 ) {
F_9 ( L_4 ) ;
return V_23 ;
}
V_36 = V_33 -> V_31 ( V_2 , V_21 , V_29 , V_35 ) ;
if ( V_36 != V_23 && ( V_36 & V_38 ) != V_39 ) {
F_18 ( V_40 , V_24 , V_2 , V_26 , V_27 , NULL ,
L_5 , V_33 -> V_41 ) ;
}
return V_36 ;
}
static unsigned int F_19 ( unsigned int V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 ,
int (* F_13)( struct V_1 * ) )
{
struct V_28 * V_29 ;
enum V_34 V_35 ;
unsigned char V_42 = F_17 ( V_2 ) -> V_22 ;
int V_21 ;
T_3 V_20 ;
V_29 = F_14 ( V_2 , & V_35 ) ;
if ( ! V_29 || V_35 == V_37 )
goto V_27;
V_21 = F_10 ( V_2 , sizeof( struct V_8 ) , & V_42 ,
& V_20 ) ;
if ( V_21 < 0 || ( V_20 & F_11 ( ~ 0x7 ) ) != 0 ) {
F_9 ( L_4 ) ;
goto V_27;
}
if ( F_20 ( V_43 , & V_29 -> V_44 ) &&
! F_21 ( V_2 ) ) {
F_22 (nf_nat_seq_adjust_hook) V_45 ;
V_45 = F_16 ( V_46 ) ;
if ( ! V_45 ||
! V_45 ( V_2 , V_29 , V_35 , V_21 ) ) {
F_23 ( F_24 ( V_29 ) , V_47 ) ;
return V_48 ;
}
}
V_27:
return F_25 ( V_2 ) ;
}
static unsigned int F_26 ( struct V_49 * V_49 ,
unsigned int V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 ,
int (* F_13)( struct V_1 * ) )
{
struct V_1 * V_50 = V_2 -> V_51 ;
const struct V_30 * V_31 ;
struct V_28 * V_29 ;
enum V_34 V_35 ;
if ( V_50 ) {
if ( ! V_50 -> V_52 ) {
unsigned int V_36 ;
V_36 = F_27 ( V_49 , V_53 , V_24 , V_50 ) ;
if ( V_36 != V_23 )
return V_36 ;
}
V_29 = F_14 ( V_50 , & V_35 ) ;
if ( V_29 != NULL && ! F_28 ( V_29 ) ) {
V_31 = F_15 ( V_29 ) ;
if ( ( V_31 && V_31 -> V_33 ) || ! F_29 ( V_29 ) ) {
F_30 ( V_2 ) ;
F_31 ( V_40 , V_24 , V_50 ,
(struct V_25 * ) V_26 ,
(struct V_25 * ) V_27 ,
F_13 , V_54 + 1 ) ;
return F_32 ( - V_55 ) ;
}
}
F_33 ( V_50 -> V_52 ) ;
V_2 -> V_52 = V_50 -> V_52 ;
V_2 -> V_56 = V_50 -> V_56 ;
return V_23 ;
}
return F_27 ( V_49 , V_53 , V_24 , V_2 ) ;
}
static unsigned int F_34 ( unsigned int V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 ,
int (* F_13)( struct V_1 * ) )
{
return F_26 ( F_35 ( V_26 ) , V_24 , V_2 , V_26 , V_27 , F_13 ) ;
}
static unsigned int F_36 ( unsigned int V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 ,
int (* F_13)( struct V_1 * ) )
{
if ( V_2 -> V_57 < sizeof( struct V_8 ) ) {
F_37 ( L_6 ) ;
return V_23 ;
}
return F_26 ( F_35 ( V_27 ) , V_24 , V_2 , V_26 , V_27 , F_13 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
if ( F_39 ( V_2 , V_58 , sizeof( T_1 ) * 4 ,
& V_5 -> V_10 . V_11 . V_12 ) ||
F_39 ( V_2 , V_59 , sizeof( T_1 ) * 4 ,
& V_5 -> V_13 . V_11 . V_12 ) )
goto V_60;
return 0 ;
V_60:
return - 1 ;
}
static int F_40 ( struct V_61 * V_62 [] ,
struct V_4 * V_63 )
{
if ( ! V_62 [ V_58 ] || ! V_62 [ V_59 ] )
return - V_64 ;
memcpy ( & V_63 -> V_10 . V_11 . V_12 , F_41 ( V_62 [ V_58 ] ) ,
sizeof( T_1 ) * 4 ) ;
memcpy ( & V_63 -> V_13 . V_11 . V_12 , F_41 ( V_62 [ V_59 ] ) ,
sizeof( T_1 ) * 4 ) ;
return 0 ;
}
static int F_42 ( void )
{
return F_43 ( V_65 , V_66 + 1 ) ;
}
static int F_44 ( struct V_49 * V_49 )
{
int V_36 = 0 ;
V_36 = F_45 ( V_49 ,
& V_67 ) ;
if ( V_36 < 0 ) {
F_46 ( V_68 L_7 ) ;
goto V_27;
}
V_36 = F_45 ( V_49 ,
& V_69 ) ;
if ( V_36 < 0 ) {
F_46 ( V_68 L_8 ) ;
goto V_70;
}
V_36 = F_45 ( V_49 ,
& V_71 ) ;
if ( V_36 < 0 ) {
F_46 ( V_68 L_9 ) ;
goto V_72;
}
V_36 = F_47 ( V_49 ,
& V_73 ) ;
if ( V_36 < 0 ) {
F_46 ( V_68 L_10 ) ;
goto V_74;
}
return 0 ;
V_74:
F_48 ( V_49 ,
& V_71 ) ;
V_72:
F_48 ( V_49 ,
& V_69 ) ;
V_70:
F_48 ( V_49 ,
& V_67 ) ;
V_27:
return V_36 ;
}
static void F_49 ( struct V_49 * V_49 )
{
F_50 ( V_49 ,
& V_73 ) ;
F_48 ( V_49 ,
& V_71 ) ;
F_48 ( V_49 ,
& V_69 ) ;
F_48 ( V_49 ,
& V_67 ) ;
}
static int T_5 F_51 ( void )
{
int V_36 = 0 ;
F_52 () ;
F_53 () ;
V_36 = F_54 ( & V_75 ) ;
if ( V_36 < 0 )
goto V_76;
V_36 = F_55 ( V_77 ,
F_56 ( V_77 ) ) ;
if ( V_36 < 0 ) {
F_57 ( L_11
L_12 ) ;
goto V_78;
}
return V_36 ;
V_78:
F_58 ( & V_75 ) ;
V_76:
return V_36 ;
}
static void T_6 F_59 ( void )
{
F_60 () ;
F_61 ( V_77 , F_56 ( V_77 ) ) ;
F_58 ( & V_75 ) ;
}
