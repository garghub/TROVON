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
static int F_7 ( const struct V_1 * V_2 , int V_17 ,
T_2 * V_18 , int V_19 )
{
T_2 V_20 = * V_18 ;
while ( F_8 ( V_20 ) ) {
struct V_21 V_22 ;
int V_23 ;
if ( V_19 < ( int ) sizeof( struct V_21 ) )
return - 1 ;
if ( V_20 == V_24 )
break;
if ( V_20 == V_25 )
break;
if ( F_9 ( V_2 , V_17 , & V_22 , sizeof( V_22 ) ) )
F_10 () ;
if ( V_20 == V_26 )
V_23 = ( V_22 . V_23 + 2 ) << 2 ;
else
V_23 = F_11 ( & V_22 ) ;
V_20 = V_22 . V_20 ;
V_19 -= V_23 ;
V_17 += V_23 ;
}
* V_18 = V_20 ;
return V_17 ;
}
static int F_12 ( const struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_27 , T_3 * V_28 )
{
unsigned int V_29 = V_3 + sizeof( struct V_8 ) ;
unsigned char V_30 ;
int V_31 ;
if ( F_9 ( V_2 , V_3 + F_3 ( struct V_8 , V_20 ) ,
& V_30 , sizeof( V_30 ) ) != 0 ) {
F_13 ( L_2 ) ;
return - V_32 ;
}
V_31 = F_7 ( V_2 , V_29 , & V_30 , V_2 -> V_19 - V_29 ) ;
if ( ( V_31 < 0 ) || ( V_31 > V_2 -> V_19 ) ) {
F_13 ( L_3 ) ;
return - V_32 ;
}
* V_27 = V_31 ;
* V_28 = V_30 ;
return V_32 ;
}
static unsigned int F_14 ( unsigned int V_33 ,
struct V_1 * V_2 ,
const struct V_34 * V_35 ,
const struct V_34 * V_36 ,
int (* F_15)( struct V_1 * ) )
{
struct V_37 * V_38 ;
const struct V_39 * V_40 ;
const struct V_41 * V_42 ;
enum V_43 V_44 ;
unsigned int V_45 , V_31 ;
unsigned int V_29 = ( T_2 * ) ( F_16 ( V_2 ) + 1 ) - V_2 -> V_46 ;
unsigned char V_30 = F_16 ( V_2 ) -> V_20 ;
V_38 = F_17 ( V_2 , & V_44 ) ;
if ( ! V_38 || V_44 == V_47 )
return V_32 ;
V_40 = F_18 ( V_38 ) ;
if ( ! V_40 )
return V_32 ;
V_42 = F_19 ( V_40 -> V_42 ) ;
if ( ! V_42 )
return V_32 ;
V_31 = F_7 ( V_2 , V_29 , & V_30 ,
V_2 -> V_19 - V_29 ) ;
if ( V_31 > V_2 -> V_19 || V_30 == V_25 ) {
F_13 ( L_4 ) ;
return V_32 ;
}
V_45 = V_42 -> V_40 ( V_2 , V_31 , V_38 , V_44 ) ;
if ( V_45 != V_32 && ( V_45 & V_48 ) != V_49 ) {
F_20 ( V_50 , V_33 , V_2 , V_35 , V_36 , NULL ,
L_5 , V_42 -> V_51 ) ;
}
return V_45 ;
}
static unsigned int F_21 ( unsigned int V_33 ,
struct V_1 * V_2 ,
const struct V_34 * V_35 ,
const struct V_34 * V_36 ,
int (* F_15)( struct V_1 * ) )
{
return F_22 ( V_2 ) ;
}
static unsigned int F_23 ( struct V_52 * V_52 ,
unsigned int V_33 ,
struct V_1 * V_2 ,
int (* F_15)( struct V_1 * ) )
{
struct V_1 * V_53 = V_2 -> V_54 ;
if ( V_53 ) {
if ( ! V_53 -> V_55 ) {
unsigned int V_45 ;
V_45 = F_24 ( V_52 , V_56 , V_33 , V_53 ) ;
if ( V_45 != V_32 )
return V_45 ;
}
F_25 ( V_53 -> V_55 ) ;
V_2 -> V_55 = V_53 -> V_55 ;
V_2 -> V_57 = V_53 -> V_57 ;
return V_32 ;
}
return F_24 ( V_52 , V_56 , V_33 , V_2 ) ;
}
static unsigned int F_26 ( unsigned int V_33 ,
struct V_1 * V_2 ,
const struct V_34 * V_35 ,
const struct V_34 * V_36 ,
int (* F_15)( struct V_1 * ) )
{
return F_23 ( F_27 ( V_35 ) , V_33 , V_2 , F_15 ) ;
}
static unsigned int F_28 ( unsigned int V_33 ,
struct V_1 * V_2 ,
const struct V_34 * V_35 ,
const struct V_34 * V_36 ,
int (* F_15)( struct V_1 * ) )
{
if ( V_2 -> V_19 < sizeof( struct V_8 ) ) {
F_29 ( L_6 ) ;
return V_32 ;
}
return F_23 ( F_27 ( V_36 ) , V_33 , V_2 , F_15 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
if ( F_31 ( V_2 , V_58 , sizeof( T_1 ) * 4 ,
& V_5 -> V_10 . V_11 . V_12 ) ||
F_31 ( V_2 , V_59 , sizeof( T_1 ) * 4 ,
& V_5 -> V_13 . V_11 . V_12 ) )
goto V_60;
return 0 ;
V_60:
return - 1 ;
}
static int F_32 ( struct V_61 * V_62 [] ,
struct V_4 * V_63 )
{
if ( ! V_62 [ V_58 ] || ! V_62 [ V_59 ] )
return - V_64 ;
memcpy ( & V_63 -> V_10 . V_11 . V_12 , F_33 ( V_62 [ V_58 ] ) ,
sizeof( T_1 ) * 4 ) ;
memcpy ( & V_63 -> V_13 . V_11 . V_12 , F_33 ( V_62 [ V_59 ] ) ,
sizeof( T_1 ) * 4 ) ;
return 0 ;
}
static int F_34 ( void )
{
return F_35 ( V_65 , V_66 + 1 ) ;
}
static int F_36 ( struct V_52 * V_52 )
{
int V_45 = 0 ;
V_45 = F_37 ( V_52 ,
& V_67 ) ;
if ( V_45 < 0 ) {
F_38 ( V_68 L_7 ) ;
goto V_36;
}
V_45 = F_37 ( V_52 ,
& V_69 ) ;
if ( V_45 < 0 ) {
F_38 ( V_68 L_8 ) ;
goto V_70;
}
V_45 = F_37 ( V_52 ,
& V_71 ) ;
if ( V_45 < 0 ) {
F_38 ( V_68 L_9 ) ;
goto V_72;
}
V_45 = F_39 ( V_52 ,
& V_73 ) ;
if ( V_45 < 0 ) {
F_38 ( V_68 L_10 ) ;
goto V_74;
}
return 0 ;
V_74:
F_40 ( V_52 ,
& V_71 ) ;
V_72:
F_40 ( V_52 ,
& V_69 ) ;
V_70:
F_40 ( V_52 ,
& V_67 ) ;
V_36:
return V_45 ;
}
static void F_41 ( struct V_52 * V_52 )
{
F_42 ( V_52 ,
& V_73 ) ;
F_40 ( V_52 ,
& V_71 ) ;
F_40 ( V_52 ,
& V_69 ) ;
F_40 ( V_52 ,
& V_67 ) ;
}
static int T_4 F_43 ( void )
{
int V_45 = 0 ;
F_44 () ;
F_45 () ;
V_45 = F_46 ( & V_75 ) ;
if ( V_45 < 0 )
goto V_76;
V_45 = F_47 ( V_77 ,
F_48 ( V_77 ) ) ;
if ( V_45 < 0 ) {
F_49 ( L_11
L_12 ) ;
goto V_78;
}
return V_45 ;
V_78:
F_50 ( & V_75 ) ;
V_76:
return V_45 ;
}
static void T_5 F_51 ( void )
{
F_52 () ;
F_53 ( V_77 , F_48 ( V_77 ) ) ;
F_50 ( & V_75 ) ;
}
