static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_7 ) ;
unsigned V_8 ;
for ( V_8 = 0 ; V_8 < F_3 ( V_4 ) ; V_8 ++ ) {
struct V_9 * V_10 = F_4 ( V_6 , V_4 , V_8 ) ;
struct V_11 * V_12 = F_5 ( V_6 , V_4 , V_8 ) ;
if ( F_6 ( V_12 ) < V_10 -> V_13 )
return true ;
}
return false ;
}
static void F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_2 ( V_15 , struct V_16 , V_18 . V_15 ) ;
F_8 ( V_17 ) ;
}
static void F_9 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_2 ( V_15 , struct V_16 , V_18 . V_15 ) ;
struct V_19 * V_19 = & V_17 -> V_19 . V_19 ;
struct V_20 * V_21 ;
int V_8 ;
F_10 (bv, bio, i)
F_11 ( V_21 -> V_22 ) ;
if ( V_17 -> V_18 . V_23 . V_24 )
F_12 ( & V_17 -> V_25 -> V_26 ) ;
F_13 ( & V_17 -> V_18 . V_23 . V_6 -> V_7 , V_17 -> V_25 ) ;
F_14 ( & V_17 -> V_18 . V_23 . V_6 -> V_27 ) ;
F_15 ( & V_17 -> V_18 . V_23 . V_6 -> V_28 ) ;
F_16 ( V_15 , F_7 ) ;
}
static void F_17 ( struct V_19 * V_19 , int error )
{
struct V_16 * V_17 = F_2 ( V_19 -> V_29 ,
struct V_16 , V_18 . V_15 ) ;
if ( error )
V_17 -> V_18 . error = error ;
F_18 ( V_17 -> V_18 . V_23 . V_6 , V_19 , error , L_1 ) ;
}
static void F_19 ( struct V_16 * V_17 )
{
struct V_19 * V_19 = & V_17 -> V_19 . V_19 ;
F_20 ( V_19 ) ;
F_21 ( V_19 ) ;
F_22 ( V_19 , F_23 ( V_30 , 0 ) ) ;
V_19 -> V_31 = F_24 ( & V_17 -> V_25 -> V_26 ) << 9 ;
V_19 -> V_32 = F_25 ( F_24 ( & V_17 -> V_25 -> V_26 ) ,
V_33 ) ;
V_19 -> V_29 = & V_17 -> V_18 . V_15 ;
V_19 -> V_34 = V_19 -> V_35 ;
F_26 ( V_19 , NULL ) ;
}
static void F_27 ( struct V_14 * V_15 )
{
struct V_36 * V_18 = F_2 ( V_15 , struct V_36 , V_15 ) ;
struct V_16 * V_17 = F_2 ( V_18 , struct V_16 , V_18 ) ;
if ( ! V_18 -> error ) {
F_19 ( V_17 ) ;
V_17 -> V_19 . V_19 . V_37 = F_28 ( & V_17 -> V_25 -> V_26 ) ;
V_18 -> V_23 . V_38 = - 1 ;
V_18 -> V_23 . V_39 = 1 ;
V_18 -> V_23 . V_40 = & V_17 -> V_19 . V_19 ;
V_18 -> V_41 = F_29 ( & V_17 -> V_25 -> V_26 ) ;
V_18 -> V_23 . V_42 = F_30 ( & V_17 -> V_25 -> V_26 ) ;
V_18 -> V_23 . type = V_43 ;
F_31 ( & V_18 -> V_23 . V_44 , & V_17 -> V_25 -> V_26 ) ;
F_32 ( & V_18 -> V_23 . V_15 , V_15 ) ;
F_33 ( & V_18 -> V_23 . V_15 ) ;
}
F_34 ( V_15 , F_9 , NULL ) ;
}
static void F_35 ( struct V_14 * V_15 )
{
struct V_36 * V_18 = F_2 ( V_15 , struct V_36 , V_15 ) ;
struct V_16 * V_17 = F_2 ( V_18 , struct V_16 , V_18 ) ;
struct V_19 * V_19 = & V_17 -> V_19 . V_19 ;
F_36 ( V_19 , V_18 -> V_23 . V_6 , & V_17 -> V_25 -> V_26 , 0 ) ;
F_34 ( V_15 , F_27 , V_45 ) ;
}
static void F_37 ( struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_15 , struct V_5 , V_46 ) ;
struct V_47 * V_25 ;
struct V_16 * V_17 ;
struct V_19 * V_19 ;
while ( ! F_38 ( V_48 , & V_6 -> V_49 ) ) {
V_25 = F_39 ( V_6 , & V_6 -> V_7 ,
& V_50 , F_1 ) ;
if ( ! V_25 )
break;
V_17 = F_40 ( sizeof( struct V_16 ) + sizeof( struct V_20 )
* F_25 ( F_24 ( & V_25 -> V_26 ) , V_33 ) ,
V_51 ) ;
if ( ! V_17 )
goto V_52;
V_25 -> V_53 = V_17 ;
V_17 -> V_25 = V_25 ;
V_17 -> V_18 . V_23 . V_54 = F_41 ( & V_25 -> V_26 ) ;
V_17 -> V_18 . V_23 . V_6 = V_6 ;
F_19 ( V_17 ) ;
V_19 = & V_17 -> V_19 . V_19 ;
V_19 -> V_55 = V_56 ;
V_19 -> V_57 = F_17 ;
if ( F_42 ( V_19 , V_51 ) )
goto V_52;
F_43 ( & V_25 -> V_26 ) ;
F_44 ( & V_17 -> V_18 . V_15 , F_35 , NULL , & V_6 -> V_58 . V_15 ) ;
if ( F_45 ( & V_6 -> V_27 ) >= 64 ) {
F_46 ( & V_6 -> V_28 , V_15 ,
F_47 ( & V_6 -> V_27 ) < 64 ) ;
F_34 ( V_15 , F_37 , V_45 ) ;
}
}
if ( 0 ) {
V_52: if ( ! F_48 ( V_25 -> V_53 ) )
F_8 ( V_25 -> V_53 ) ;
F_13 ( & V_6 -> V_7 , V_25 ) ;
}
F_49 ( V_15 ) ;
}
static bool F_50 ( struct V_11 * V_59 , struct V_11 * V_60 )
{
return F_6 ( V_59 ) < F_6 ( V_60 ) ;
}
static unsigned F_51 ( struct V_9 * V_10 )
{
return F_6 ( F_52 ( & V_10 -> V_61 ) ) ;
}
void F_53 ( struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_15 , struct V_5 , V_58 . V_15 ) ;
struct V_9 * V_10 ;
struct V_11 * V_62 ;
unsigned V_8 ;
if ( ! V_6 -> V_63 )
F_49 ( V_15 ) ;
F_54 ( & V_6 -> V_64 ) ;
F_55 (ca, c, i) {
unsigned V_65 = 0 ;
unsigned V_66 = V_10 -> V_67 . V_68 *
F_56 ( F_57 ( & V_10 -> free ) , V_10 -> free . V_69 / 2 ) ;
V_10 -> V_61 . V_70 = 0 ;
F_58 (b, ca) {
if ( ! F_6 ( V_62 ) )
continue;
if ( ! F_59 ( & V_10 -> V_61 ) ) {
V_65 += F_6 ( V_62 ) ;
F_60 ( & V_10 -> V_61 , V_62 , F_50 ) ;
} else if ( F_50 ( V_62 , F_52 ( & V_10 -> V_61 ) ) ) {
V_65 -= F_51 ( V_10 ) ;
V_65 += F_6 ( V_62 ) ;
V_10 -> V_61 . V_71 [ 0 ] = V_62 ;
F_61 ( & V_10 -> V_61 , 0 , F_50 ) ;
}
}
while ( V_65 > V_66 ) {
F_62 ( & V_10 -> V_61 , V_62 , F_50 ) ;
V_65 -= F_6 ( V_62 ) ;
}
V_10 -> V_13 = F_51 ( V_10 ) ;
F_63 ( L_2 , V_10 -> V_13 ) ;
}
F_64 ( & V_6 -> V_64 ) ;
V_6 -> V_7 . V_72 = V_73 ;
F_32 ( & V_6 -> V_46 , V_15 ) ;
F_37 ( & V_6 -> V_46 ) ;
F_49 ( V_15 ) ;
}
void F_65 ( struct V_5 * V_6 )
{
F_66 ( & V_6 -> V_7 ) ;
}
