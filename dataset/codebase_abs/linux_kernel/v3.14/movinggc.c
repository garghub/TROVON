static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_7 ) ;
unsigned V_8 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_4 ) ; V_8 ++ ) {
struct V_9 * V_10 = F_4 ( V_6 , V_4 , V_8 ) ;
if ( F_5 ( V_10 ) )
return true ;
}
return false ;
}
static void F_6 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_2 ( V_12 , struct V_13 , V_12 ) ;
F_7 ( V_14 ) ;
}
static void F_8 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_2 ( V_12 , struct V_13 , V_12 ) ;
struct V_15 * V_15 = & V_14 -> V_15 . V_15 ;
struct V_16 * V_17 ;
int V_8 ;
F_9 (bv, bio, i)
F_10 ( V_17 -> V_18 ) ;
if ( V_14 -> V_19 . V_20 )
F_11 ( & V_14 -> V_21 -> V_22 ) ;
F_12 ( & V_14 -> V_19 . V_6 -> V_7 , V_14 -> V_21 ) ;
F_13 ( & V_14 -> V_19 . V_6 -> V_23 ) ;
F_14 ( V_12 , F_6 ) ;
}
static void F_15 ( struct V_15 * V_15 , int error )
{
struct V_24 * V_25 = F_2 ( V_15 , struct V_24 , V_15 ) ;
struct V_13 * V_14 = F_2 ( V_15 -> V_26 ,
struct V_13 , V_12 ) ;
if ( error )
V_14 -> V_19 . error = error ;
else if ( ! F_16 ( & V_25 -> V_22 ) &&
F_17 ( V_14 -> V_19 . V_6 , & V_25 -> V_22 , 0 ) ) {
V_14 -> V_19 . error = - V_27 ;
}
F_18 ( V_14 -> V_19 . V_6 , V_15 , error , L_1 ) ;
}
static void F_19 ( struct V_13 * V_14 )
{
struct V_15 * V_15 = & V_14 -> V_15 . V_15 ;
F_20 ( V_15 ) ;
F_21 ( V_15 ) ;
F_22 ( V_15 , F_23 ( V_28 , 0 ) ) ;
V_15 -> V_29 . V_30 = F_24 ( & V_14 -> V_21 -> V_22 ) << 9 ;
V_15 -> V_31 = F_25 ( F_24 ( & V_14 -> V_21 -> V_22 ) ,
V_32 ) ;
V_15 -> V_26 = & V_14 -> V_12 ;
V_15 -> V_33 = V_15 -> V_34 ;
F_26 ( V_15 , NULL ) ;
}
static void F_27 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_2 ( V_12 , struct V_13 , V_12 ) ;
struct V_35 * V_19 = & V_14 -> V_19 ;
if ( ! V_19 -> error ) {
F_19 ( V_14 ) ;
V_14 -> V_15 . V_15 . V_29 . V_36 = F_28 ( & V_14 -> V_21 -> V_22 ) ;
V_19 -> V_37 = 1 ;
V_19 -> V_15 = & V_14 -> V_15 . V_15 ;
V_19 -> V_38 = F_16 ( & V_14 -> V_21 -> V_22 ) ;
V_19 -> V_39 = F_29 ( & V_14 -> V_21 -> V_22 ) ;
F_30 ( & V_19 -> V_40 , & V_14 -> V_21 -> V_22 ) ;
V_19 -> V_41 = true ;
F_31 ( & V_19 -> V_12 , V_42 , NULL , V_12 ) ;
}
F_32 ( V_12 , F_8 , V_43 ) ;
}
static void F_33 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_2 ( V_12 , struct V_13 , V_12 ) ;
struct V_15 * V_15 = & V_14 -> V_15 . V_15 ;
F_34 ( V_15 , V_14 -> V_19 . V_6 , & V_14 -> V_21 -> V_22 , 0 ) ;
F_32 ( V_12 , F_27 , V_43 ) ;
}
static void F_35 ( struct V_5 * V_6 )
{
struct V_44 * V_21 ;
struct V_13 * V_14 ;
struct V_15 * V_15 ;
struct V_11 V_12 ;
F_36 ( & V_12 ) ;
while ( ! F_37 ( V_45 , & V_6 -> V_46 ) ) {
V_21 = F_38 ( V_6 , & V_6 -> V_7 ,
& V_47 , F_1 ) ;
if ( ! V_21 )
break;
if ( F_17 ( V_6 , & V_21 -> V_22 , 0 ) ) {
F_12 ( & V_6 -> V_7 , V_21 ) ;
continue;
}
V_14 = F_39 ( sizeof( struct V_13 ) + sizeof( struct V_16 )
* F_25 ( F_24 ( & V_21 -> V_22 ) , V_32 ) ,
V_48 ) ;
if ( ! V_14 )
goto V_49;
V_21 -> V_50 = V_14 ;
V_14 -> V_21 = V_21 ;
V_14 -> V_19 . V_51 = F_40 ( & V_21 -> V_22 ) ;
V_14 -> V_19 . V_6 = V_6 ;
F_19 ( V_14 ) ;
V_15 = & V_14 -> V_15 . V_15 ;
V_15 -> V_52 = V_53 ;
V_15 -> V_54 = F_15 ;
if ( F_41 ( V_15 , V_48 ) )
goto V_49;
F_42 ( & V_21 -> V_22 ) ;
F_43 ( & V_6 -> V_23 ) ;
F_31 ( & V_14 -> V_12 , F_33 , NULL , & V_12 ) ;
}
if ( 0 ) {
V_49: if ( ! F_44 ( V_21 -> V_50 ) )
F_7 ( V_21 -> V_50 ) ;
F_12 ( & V_6 -> V_7 , V_21 ) ;
}
F_45 ( & V_12 ) ;
}
static bool F_46 ( struct V_9 * V_55 , struct V_9 * V_56 )
{
return F_47 ( V_55 ) < F_47 ( V_56 ) ;
}
static unsigned F_48 ( struct V_57 * V_58 )
{
struct V_9 * V_25 ;
return ( V_25 = F_49 ( & V_58 -> V_59 ) ) ? F_47 ( V_25 ) : 0 ;
}
void F_50 ( struct V_5 * V_6 )
{
struct V_57 * V_58 ;
struct V_9 * V_25 ;
unsigned V_8 ;
if ( ! V_6 -> V_60 )
return;
F_51 ( & V_6 -> V_61 ) ;
F_52 (ca, c, i) {
unsigned V_62 = 0 ;
unsigned V_63 = V_58 -> V_64 . V_65 *
F_53 ( & V_58 -> free [ V_66 ] ) ;
V_58 -> V_59 . V_67 = 0 ;
F_54 (b, ca) {
if ( ! F_47 ( V_25 ) )
continue;
if ( ! F_55 ( & V_58 -> V_59 ) ) {
V_62 += F_47 ( V_25 ) ;
F_56 ( & V_58 -> V_59 , V_25 , F_46 ) ;
} else if ( F_46 ( V_25 , F_49 ( & V_58 -> V_59 ) ) ) {
V_62 -= F_48 ( V_58 ) ;
V_62 += F_47 ( V_25 ) ;
V_58 -> V_59 . V_68 [ 0 ] = V_25 ;
F_57 ( & V_58 -> V_59 , 0 , F_46 ) ;
}
}
while ( V_62 > V_63 ) {
F_58 ( & V_58 -> V_59 , V_25 , F_46 ) ;
V_62 -= F_47 ( V_25 ) ;
}
while ( F_58 ( & V_58 -> V_59 , V_25 , F_46 ) )
F_59 ( V_25 , 1 ) ;
}
F_60 ( & V_6 -> V_61 ) ;
V_6 -> V_7 . V_69 = V_70 ;
F_35 ( V_6 ) ;
}
void F_61 ( struct V_5 * V_6 )
{
F_62 ( & V_6 -> V_7 ) ;
F_63 ( & V_6 -> V_23 , 64 ) ;
}
