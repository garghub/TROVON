static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_7 ) ;
unsigned V_8 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_4 ) ; V_8 ++ )
if ( F_4 ( V_6 , V_4 , V_8 ) &&
F_5 ( F_6 ( V_6 , V_4 , V_8 ) ) )
return true ;
return false ;
}
static void F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_2 ( V_10 , struct V_11 , V_10 ) ;
F_8 ( V_12 ) ;
}
static void F_9 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_2 ( V_10 , struct V_11 , V_10 ) ;
struct V_13 * V_13 = & V_12 -> V_13 . V_13 ;
F_10 ( V_13 ) ;
if ( V_12 -> V_14 . V_15 )
F_11 ( & V_12 -> V_16 -> V_17 ) ;
F_12 ( & V_12 -> V_14 . V_6 -> V_7 , V_12 -> V_16 ) ;
F_13 ( & V_12 -> V_14 . V_6 -> V_18 ) ;
F_14 ( V_10 , F_7 ) ;
}
static void F_15 ( struct V_13 * V_13 )
{
struct V_19 * V_20 = F_2 ( V_13 , struct V_19 , V_13 ) ;
struct V_11 * V_12 = F_2 ( V_13 -> V_21 ,
struct V_11 , V_10 ) ;
if ( V_13 -> V_22 )
V_12 -> V_14 . error = V_13 -> V_22 ;
else if ( ! F_16 ( & V_20 -> V_17 ) &&
F_17 ( V_12 -> V_14 . V_6 , & V_20 -> V_17 , 0 ) ) {
V_12 -> V_14 . error = - V_23 ;
}
F_18 ( V_12 -> V_14 . V_6 , V_13 , V_13 -> V_22 , L_1 ) ;
}
static void F_19 ( struct V_11 * V_12 )
{
struct V_13 * V_13 = & V_12 -> V_13 . V_13 ;
F_20 ( V_13 ) ;
F_21 ( V_13 ) ;
F_22 ( V_13 , F_23 ( V_24 , 0 ) ) ;
V_13 -> V_25 . V_26 = F_24 ( & V_12 -> V_16 -> V_17 ) << 9 ;
V_13 -> V_27 = F_25 ( F_24 ( & V_12 -> V_16 -> V_17 ) ,
V_28 ) ;
V_13 -> V_21 = & V_12 -> V_10 ;
V_13 -> V_29 = V_13 -> V_30 ;
F_26 ( V_13 , NULL ) ;
}
static void F_27 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_2 ( V_10 , struct V_11 , V_10 ) ;
struct V_31 * V_14 = & V_12 -> V_14 ;
if ( ! V_14 -> error ) {
F_19 ( V_12 ) ;
V_12 -> V_13 . V_13 . V_25 . V_32 = F_28 ( & V_12 -> V_16 -> V_17 ) ;
V_14 -> V_33 = 1 ;
V_14 -> V_13 = & V_12 -> V_13 . V_13 ;
V_14 -> V_34 = F_16 ( & V_12 -> V_16 -> V_17 ) ;
V_14 -> V_35 = F_29 ( & V_12 -> V_16 -> V_17 ) ;
F_30 ( & V_14 -> V_36 , & V_12 -> V_16 -> V_17 ) ;
V_14 -> V_37 = true ;
F_31 ( & V_14 -> V_10 , V_38 , NULL , V_10 ) ;
}
F_32 ( V_10 , F_9 , V_14 -> V_39 ) ;
}
static void F_33 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_2 ( V_10 , struct V_11 , V_10 ) ;
struct V_13 * V_13 = & V_12 -> V_13 . V_13 ;
F_34 ( V_13 , V_12 -> V_14 . V_6 , & V_12 -> V_16 -> V_17 , 0 ) ;
F_32 ( V_10 , F_27 , V_12 -> V_14 . V_39 ) ;
}
static void F_35 ( struct V_5 * V_6 )
{
struct V_40 * V_16 ;
struct V_11 * V_12 ;
struct V_13 * V_13 ;
struct V_9 V_10 ;
F_36 ( & V_10 ) ;
while ( ! F_37 ( V_41 , & V_6 -> V_42 ) ) {
V_16 = F_38 ( V_6 , & V_6 -> V_7 ,
& V_43 , F_1 ) ;
if ( ! V_16 )
break;
if ( F_17 ( V_6 , & V_16 -> V_17 , 0 ) ) {
F_12 ( & V_6 -> V_7 , V_16 ) ;
continue;
}
V_12 = F_39 ( sizeof( struct V_11 ) + sizeof( struct V_44 )
* F_25 ( F_24 ( & V_16 -> V_17 ) , V_28 ) ,
V_45 ) ;
if ( ! V_12 )
goto V_46;
V_16 -> V_47 = V_12 ;
V_12 -> V_16 = V_16 ;
V_12 -> V_14 . V_48 = F_40 ( & V_16 -> V_17 ) ;
V_12 -> V_14 . V_6 = V_6 ;
V_12 -> V_14 . V_39 = V_6 -> V_49 ;
F_19 ( V_12 ) ;
V_13 = & V_12 -> V_13 . V_13 ;
F_41 ( V_13 , V_50 , 0 ) ;
V_13 -> V_51 = F_15 ;
if ( F_42 ( V_13 , V_45 ) )
goto V_46;
F_43 ( & V_16 -> V_17 ) ;
F_44 ( & V_6 -> V_18 ) ;
F_31 ( & V_12 -> V_10 , F_33 , NULL , & V_10 ) ;
}
if ( 0 ) {
V_46: if ( ! F_45 ( V_16 -> V_47 ) )
F_8 ( V_16 -> V_47 ) ;
F_12 ( & V_6 -> V_7 , V_16 ) ;
}
F_46 ( & V_10 ) ;
}
static bool F_47 ( struct V_52 * V_53 , struct V_52 * V_54 )
{
return F_48 ( V_53 ) < F_48 ( V_54 ) ;
}
static unsigned F_49 ( struct V_55 * V_56 )
{
struct V_52 * V_20 ;
return ( V_20 = F_50 ( & V_56 -> V_57 ) ) ? F_48 ( V_20 ) : 0 ;
}
void F_51 ( struct V_5 * V_6 )
{
struct V_55 * V_56 ;
struct V_52 * V_20 ;
unsigned V_8 ;
if ( ! V_6 -> V_58 )
return;
F_52 ( & V_6 -> V_59 ) ;
F_53 (ca, c, i) {
unsigned V_60 = 0 ;
unsigned V_61 = V_56 -> V_62 . V_63 *
F_54 ( & V_56 -> free [ V_64 ] ) ;
V_56 -> V_57 . V_65 = 0 ;
F_55 (b, ca) {
if ( F_56 ( V_20 ) == V_66 ||
! F_48 ( V_20 ) ||
F_48 ( V_20 ) == V_56 -> V_62 . V_63 ||
F_57 ( & V_20 -> V_67 ) )
continue;
if ( ! F_58 ( & V_56 -> V_57 ) ) {
V_60 += F_48 ( V_20 ) ;
F_59 ( & V_56 -> V_57 , V_20 , F_47 ) ;
} else if ( F_47 ( V_20 , F_50 ( & V_56 -> V_57 ) ) ) {
V_60 -= F_49 ( V_56 ) ;
V_60 += F_48 ( V_20 ) ;
V_56 -> V_57 . V_68 [ 0 ] = V_20 ;
F_60 ( & V_56 -> V_57 , 0 , F_47 ) ;
}
}
while ( V_60 > V_61 ) {
F_61 ( & V_56 -> V_57 , V_20 , F_47 ) ;
V_60 -= F_48 ( V_20 ) ;
}
while ( F_61 ( & V_56 -> V_57 , V_20 , F_47 ) )
F_62 ( V_20 , 1 ) ;
}
F_63 ( & V_6 -> V_59 ) ;
V_6 -> V_7 . V_69 = V_70 ;
F_35 ( V_6 ) ;
}
void F_64 ( struct V_5 * V_6 )
{
F_65 ( & V_6 -> V_7 ) ;
F_66 ( & V_6 -> V_18 , 64 ) ;
}
