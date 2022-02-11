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
struct V_14 * V_15 ;
int V_8 ;
F_10 (bv, bio, i)
F_11 ( V_15 -> V_16 ) ;
if ( V_12 -> V_17 . V_18 )
F_12 ( & V_12 -> V_19 -> V_20 ) ;
F_13 ( & V_12 -> V_17 . V_6 -> V_7 , V_12 -> V_19 ) ;
F_14 ( & V_12 -> V_17 . V_6 -> V_21 ) ;
F_15 ( V_10 , F_7 ) ;
}
static void F_16 ( struct V_13 * V_13 )
{
struct V_22 * V_23 = F_2 ( V_13 , struct V_22 , V_13 ) ;
struct V_11 * V_12 = F_2 ( V_13 -> V_24 ,
struct V_11 , V_10 ) ;
if ( V_13 -> V_25 )
V_12 -> V_17 . error = V_13 -> V_25 ;
else if ( ! F_17 ( & V_23 -> V_20 ) &&
F_18 ( V_12 -> V_17 . V_6 , & V_23 -> V_20 , 0 ) ) {
V_12 -> V_17 . error = - V_26 ;
}
F_19 ( V_12 -> V_17 . V_6 , V_13 , V_13 -> V_25 , L_1 ) ;
}
static void F_20 ( struct V_11 * V_12 )
{
struct V_13 * V_13 = & V_12 -> V_13 . V_13 ;
F_21 ( V_13 ) ;
F_22 ( V_13 ) ;
F_23 ( V_13 , F_24 ( V_27 , 0 ) ) ;
V_13 -> V_28 . V_29 = F_25 ( & V_12 -> V_19 -> V_20 ) << 9 ;
V_13 -> V_30 = F_26 ( F_25 ( & V_12 -> V_19 -> V_20 ) ,
V_31 ) ;
V_13 -> V_24 = & V_12 -> V_10 ;
V_13 -> V_32 = V_13 -> V_33 ;
F_27 ( V_13 , NULL ) ;
}
static void F_28 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_2 ( V_10 , struct V_11 , V_10 ) ;
struct V_34 * V_17 = & V_12 -> V_17 ;
if ( ! V_17 -> error ) {
F_20 ( V_12 ) ;
V_12 -> V_13 . V_13 . V_28 . V_35 = F_29 ( & V_12 -> V_19 -> V_20 ) ;
V_17 -> V_36 = 1 ;
V_17 -> V_13 = & V_12 -> V_13 . V_13 ;
V_17 -> V_37 = F_17 ( & V_12 -> V_19 -> V_20 ) ;
V_17 -> V_38 = F_30 ( & V_12 -> V_19 -> V_20 ) ;
F_31 ( & V_17 -> V_39 , & V_12 -> V_19 -> V_20 ) ;
V_17 -> V_40 = true ;
F_32 ( & V_17 -> V_10 , V_41 , NULL , V_10 ) ;
}
F_33 ( V_10 , F_9 , V_17 -> V_42 ) ;
}
static void F_34 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_2 ( V_10 , struct V_11 , V_10 ) ;
struct V_13 * V_13 = & V_12 -> V_13 . V_13 ;
F_35 ( V_13 , V_12 -> V_17 . V_6 , & V_12 -> V_19 -> V_20 , 0 ) ;
F_33 ( V_10 , F_28 , V_12 -> V_17 . V_42 ) ;
}
static void F_36 ( struct V_5 * V_6 )
{
struct V_43 * V_19 ;
struct V_11 * V_12 ;
struct V_13 * V_13 ;
struct V_9 V_10 ;
F_37 ( & V_10 ) ;
while ( ! F_38 ( V_44 , & V_6 -> V_45 ) ) {
V_19 = F_39 ( V_6 , & V_6 -> V_7 ,
& V_46 , F_1 ) ;
if ( ! V_19 )
break;
if ( F_18 ( V_6 , & V_19 -> V_20 , 0 ) ) {
F_13 ( & V_6 -> V_7 , V_19 ) ;
continue;
}
V_12 = F_40 ( sizeof( struct V_11 ) + sizeof( struct V_14 )
* F_26 ( F_25 ( & V_19 -> V_20 ) , V_31 ) ,
V_47 ) ;
if ( ! V_12 )
goto V_48;
V_19 -> V_49 = V_12 ;
V_12 -> V_19 = V_19 ;
V_12 -> V_17 . V_50 = F_41 ( & V_19 -> V_20 ) ;
V_12 -> V_17 . V_6 = V_6 ;
V_12 -> V_17 . V_42 = V_6 -> V_51 ;
F_20 ( V_12 ) ;
V_13 = & V_12 -> V_13 . V_13 ;
V_13 -> V_52 = V_53 ;
V_13 -> V_54 = F_16 ;
if ( F_42 ( V_13 , V_47 ) )
goto V_48;
F_43 ( & V_19 -> V_20 ) ;
F_44 ( & V_6 -> V_21 ) ;
F_32 ( & V_12 -> V_10 , F_34 , NULL , & V_10 ) ;
}
if ( 0 ) {
V_48: if ( ! F_45 ( V_19 -> V_49 ) )
F_8 ( V_19 -> V_49 ) ;
F_13 ( & V_6 -> V_7 , V_19 ) ;
}
F_46 ( & V_10 ) ;
}
static bool F_47 ( struct V_55 * V_56 , struct V_55 * V_57 )
{
return F_48 ( V_56 ) < F_48 ( V_57 ) ;
}
static unsigned F_49 ( struct V_58 * V_59 )
{
struct V_55 * V_23 ;
return ( V_23 = F_50 ( & V_59 -> V_60 ) ) ? F_48 ( V_23 ) : 0 ;
}
void F_51 ( struct V_5 * V_6 )
{
struct V_58 * V_59 ;
struct V_55 * V_23 ;
unsigned V_8 ;
if ( ! V_6 -> V_61 )
return;
F_52 ( & V_6 -> V_62 ) ;
F_53 (ca, c, i) {
unsigned V_63 = 0 ;
unsigned V_64 = V_59 -> V_65 . V_66 *
F_54 ( & V_59 -> free [ V_67 ] ) ;
V_59 -> V_60 . V_68 = 0 ;
F_55 (b, ca) {
if ( F_56 ( V_23 ) == V_69 ||
! F_48 ( V_23 ) ||
F_48 ( V_23 ) == V_59 -> V_65 . V_66 ||
F_57 ( & V_23 -> V_70 ) )
continue;
if ( ! F_58 ( & V_59 -> V_60 ) ) {
V_63 += F_48 ( V_23 ) ;
F_59 ( & V_59 -> V_60 , V_23 , F_47 ) ;
} else if ( F_47 ( V_23 , F_50 ( & V_59 -> V_60 ) ) ) {
V_63 -= F_49 ( V_59 ) ;
V_63 += F_48 ( V_23 ) ;
V_59 -> V_60 . V_71 [ 0 ] = V_23 ;
F_60 ( & V_59 -> V_60 , 0 , F_47 ) ;
}
}
while ( V_63 > V_64 ) {
F_61 ( & V_59 -> V_60 , V_23 , F_47 ) ;
V_63 -= F_48 ( V_23 ) ;
}
while ( F_61 ( & V_59 -> V_60 , V_23 , F_47 ) )
F_62 ( V_23 , 1 ) ;
}
F_63 ( & V_6 -> V_62 ) ;
V_6 -> V_7 . V_72 = V_73 ;
F_36 ( V_6 ) ;
}
void F_64 ( struct V_5 * V_6 )
{
F_65 ( & V_6 -> V_7 ) ;
F_66 ( & V_6 -> V_21 , 64 ) ;
}
