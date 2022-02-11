int
F_1 ( struct V_1 * V_2 , T_1 V_3 , bool V_4 )
{
struct V_5 * V_6 = ( void * ) V_2 ;
bool V_7 = true ;
T_2 V_8 [ 2 ] , V_9 [ 3 ] ;
T_1 V_10 ;
int V_11 , V_12 ;
V_11 = F_2 ( V_6 -> V_2 . V_13 , V_14 , V_8 , 2 ) ;
if ( V_11 ) {
F_3 ( L_1 ) ;
goto V_15;
}
V_10 = V_8 [ 0 ] * 27000 * ( V_8 [ 1 ] & V_16 ) ;
V_10 = ( V_10 * 8 ) / 10 ;
V_3 = ( V_3 + 9 ) / 10 ;
if ( V_10 < V_3 ) {
F_3 ( L_2 ) ;
goto V_15;
}
V_11 = F_2 ( V_6 -> V_2 . V_13 , V_17 , V_9 , 3 ) ;
if ( V_11 ) {
F_3 ( L_3 ) ;
goto V_15;
}
if ( V_9 [ 2 ] & V_18 ) {
for ( V_12 = 0 ; V_12 < ( V_8 [ 1 ] & V_16 ) ; V_12 ++ ) {
T_2 V_19 = ( V_9 [ V_12 >> 1 ] >> ( ( V_12 & 1 ) * 4 ) ) & 0x0f ;
if ( ! ( V_19 & V_20 ) ||
! ( V_19 & V_21 ) ||
! ( V_19 & V_22 ) ) {
F_3 ( L_4 , V_19 ) ;
goto V_15;
}
}
V_7 = false ;
} else {
F_3 ( L_5 ) ;
}
V_15:
if ( V_7 || ! F_4 ( & V_6 -> V_23 . V_15 ) ) {
if ( V_6 -> V_24 [ V_25 ] == 0x00 ) {
V_6 -> V_24 [ V_26 ] =
V_6 -> V_2 . V_27 . V_28 . V_29 ;
V_6 -> V_24 [ V_30 ] =
V_6 -> V_2 . V_27 . V_28 . V_31 ;
}
F_5 ( & V_6 -> V_23 . V_15 , 0 ) ;
F_6 ( & V_6 -> V_23 . V_32 ) ;
} else {
F_7 ( V_6 -> V_33 ) ;
}
if ( V_4 ) {
if ( ! F_8 ( V_6 -> V_23 . V_4 ,
F_4 ( & V_6 -> V_23 . V_15 ) ,
F_9 ( 2000 ) ) )
V_11 = - V_34 ;
}
return V_11 ;
}
static void
F_10 ( struct V_5 * V_6 , bool V_35 )
{
struct V_36 * V_37 = V_6 -> V_2 . V_13 ;
if ( V_35 ) {
if ( ! V_6 -> V_35 ) {
F_11 ( V_37 ) -> F_12 ( V_37 , 0 ) ;
F_3 ( L_6 ) ;
V_6 -> V_35 = true ;
}
F_1 ( & V_6 -> V_2 , 0 , true ) ;
} else {
if ( V_6 -> V_35 ) {
F_11 ( V_37 ) -> F_13 ( V_37 ) ;
F_3 ( L_7 ) ;
V_6 -> V_35 = false ;
}
F_5 ( & V_6 -> V_23 . V_15 , 0 ) ;
}
}
static void
F_14 ( struct V_5 * V_6 )
{
struct V_36 * V_37 = V_6 -> V_2 . V_13 ;
int V_11 = F_11 ( V_37 ) -> F_12 ( V_37 , 0 ) ;
if ( V_11 == 0 ) {
V_11 = F_2 ( V_6 -> V_2 . V_13 , V_25 ,
V_6 -> V_24 , sizeof( V_6 -> V_24 ) ) ;
F_10 ( V_6 , V_11 == 0 ) ;
F_11 ( V_37 ) -> F_13 ( V_37 ) ;
}
}
static void
F_15 ( struct V_38 * V_32 )
{
struct V_5 * V_6 = F_16 ( V_32 , F_17 ( * V_6 ) , V_32 ) ;
struct V_39 * V_40 = V_39 ( V_6 ) ;
int type = F_18 ( & V_6 -> V_41 , 0 ) ;
T_1 V_42 = 0 ;
if ( type & ( V_43 | V_44 ) ) {
F_14 ( V_6 ) ;
if ( type & V_44 )
V_42 |= V_45 ;
if ( type & V_43 )
V_42 |= V_46 ;
F_7 ( V_6 -> V_2 . V_47 -> V_48 . V_49 ) ;
}
if ( type & V_50 ) {
F_1 ( & V_6 -> V_2 , 0 , true ) ;
V_42 |= V_51 ;
}
F_19 ( V_40 -> V_48 , V_42 , V_6 -> V_2 . V_27 . V_52 ) ;
}
static int
F_20 ( void * V_53 , T_1 type , int V_54 )
{
struct V_5 * V_6 = V_53 ;
F_3 ( L_8 , type ) ;
F_21 ( type , & V_6 -> V_41 ) ;
F_6 ( & V_6 -> V_32 ) ;
return V_55 ;
}
int
F_22 ( struct V_56 * V_57 , bool V_58 )
{
struct V_5 * V_6 = ( void * ) V_57 ;
F_23 ( V_6 -> V_33 ) ;
F_10 ( V_6 , false ) ;
return F_24 ( & V_6 -> V_2 , V_58 ) ;
}
int
F_25 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = ( void * ) V_57 ;
F_14 ( V_6 ) ;
return F_26 ( & V_6 -> V_2 ) ;
}
void
F_27 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = ( void * ) V_57 ;
F_28 ( NULL , & V_6 -> V_33 ) ;
F_29 ( & V_6 -> V_2 ) ;
}
int
F_30 ( struct V_56 * V_59 ,
struct V_56 * V_60 ,
struct V_61 * V_62 ,
struct V_63 * V_27 , int V_54 ,
int V_64 , void * * V_65 )
{
struct V_66 * V_67 = V_66 ( V_59 ) ;
struct F_11 * V_68 = F_11 ( V_59 ) ;
struct V_5 * V_6 ;
T_2 V_69 , V_70 , V_71 ;
T_1 V_53 ;
int V_11 ;
V_11 = F_31 ( V_59 , V_60 , V_62 , V_27 , V_54 ,
V_64 , V_65 ) ;
V_6 = * V_65 ;
if ( V_11 )
return V_11 ;
F_28 ( NULL , & V_6 -> V_2 . V_47 -> V_48 . V_49 ) ;
if ( ! V_6 -> V_2 . V_13 ) {
F_32 ( L_9 ) ;
return - V_72 ;
}
V_53 = F_33 ( V_67 , V_6 -> V_2 . V_27 . V_73 ,
V_6 -> V_2 . V_27 . V_74 , & V_6 -> V_75 ,
& V_69 , & V_70 , & V_71 , & V_6 -> V_27 ) ;
if ( ! V_53 ) {
F_32 ( L_10 ) ;
return - V_72 ;
}
F_3 ( L_11 , V_6 -> V_75 , V_69 , V_70 , V_71 ) ;
F_34 ( & V_6 -> V_23 . V_32 , V_76 ) ;
F_35 ( & V_6 -> V_23 . V_4 ) ;
F_5 ( & V_6 -> V_23 . V_15 , 0 ) ;
V_11 = F_36 ( V_68 -> V_77 , V_50 , V_6 -> V_2 . V_13 -> V_54 ,
F_20 , V_6 , & V_6 -> V_33 ) ;
if ( V_11 ) {
F_32 ( L_12 , V_11 ) ;
return V_11 ;
}
F_34 ( & V_6 -> V_32 , F_15 ) ;
V_11 = F_36 ( V_68 -> V_77 , V_43 | V_44 ,
V_6 -> V_2 . V_13 -> V_54 ,
F_20 , V_6 ,
& V_6 -> V_2 . V_47 -> V_48 . V_49 ) ;
if ( V_11 ) {
F_32 ( L_13 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
int
F_37 ( struct V_56 * V_59 ,
struct V_56 * V_60 ,
struct V_61 * V_62 , void * V_27 , T_1 V_54 ,
struct V_56 * * V_65 )
{
struct V_5 * V_6 ;
int V_11 ;
V_11 = F_38 ( V_59 , V_60 , V_62 , V_27 , V_54 , & V_6 ) ;
* V_65 = F_39 ( V_6 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
