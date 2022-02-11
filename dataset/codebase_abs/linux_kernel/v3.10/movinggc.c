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
struct V_20 * V_21 = F_10 ( V_19 , V_19 -> V_22 ) ;
while ( V_21 -- != V_19 -> V_23 )
F_11 ( V_21 -> V_24 ) ;
F_12 ( L_1 , V_17 -> V_18 . V_25 . V_26
? L_2 : L_3 ,
F_13 ( & V_17 -> V_27 -> V_28 ) ) ;
F_14 ( & V_17 -> V_18 . V_25 . V_6 -> V_7 , V_17 -> V_27 ) ;
F_15 ( & V_17 -> V_18 . V_25 . V_6 -> V_29 ) ;
F_16 ( & V_17 -> V_18 . V_25 . V_6 -> V_30 ) ;
F_17 ( V_15 , F_7 ) ;
}
static void F_18 ( struct V_19 * V_19 , int error )
{
struct V_16 * V_17 = F_2 ( V_19 -> V_31 ,
struct V_16 , V_18 . V_15 ) ;
if ( error )
V_17 -> V_18 . error = error ;
F_19 ( V_17 -> V_18 . V_25 . V_6 , V_19 , error , L_4 ) ;
}
static void F_20 ( struct V_16 * V_17 )
{
struct V_19 * V_19 = & V_17 -> V_19 . V_19 ;
F_21 ( V_19 ) ;
F_22 ( V_19 ) ;
F_23 ( V_19 , F_24 ( V_32 , 0 ) ) ;
V_19 -> V_33 = F_25 ( & V_17 -> V_27 -> V_28 ) << 9 ;
V_19 -> V_34 = F_26 ( F_25 ( & V_17 -> V_27 -> V_28 ) ,
V_35 ) ;
V_19 -> V_31 = & V_17 -> V_18 . V_15 ;
V_19 -> V_23 = V_19 -> V_36 ;
F_27 ( V_19 , NULL ) ;
}
static void F_28 ( struct V_14 * V_15 )
{
struct V_37 * V_18 = F_2 ( V_15 , struct V_37 , V_15 ) ;
struct V_16 * V_17 = F_2 ( V_18 , struct V_16 , V_18 ) ;
if ( ! V_18 -> error ) {
F_29 ( & V_17 -> V_19 . V_19 ) ;
F_20 ( V_17 ) ;
V_17 -> V_19 . V_19 . V_38 = F_30 ( & V_17 -> V_27 -> V_28 ) ;
V_18 -> V_25 . V_39 = - 1 ;
V_18 -> V_25 . V_40 = 1 ;
V_18 -> V_25 . V_41 = & V_17 -> V_19 . V_19 ;
V_18 -> V_42 = F_31 ( & V_17 -> V_27 -> V_28 ) ;
V_18 -> V_25 . V_43 = F_32 ( & V_17 -> V_27 -> V_28 ) ;
V_18 -> V_25 . type = V_44 ;
F_33 ( & V_18 -> V_25 . V_45 , & V_17 -> V_27 -> V_28 ) ;
F_34 ( & V_18 -> V_25 . V_15 , V_15 ) ;
F_35 ( & V_18 -> V_25 . V_15 ) ;
}
F_36 ( V_15 , F_9 , NULL ) ;
}
static void F_37 ( struct V_14 * V_15 )
{
struct V_37 * V_18 = F_2 ( V_15 , struct V_37 , V_15 ) ;
struct V_16 * V_17 = F_2 ( V_18 , struct V_16 , V_18 ) ;
struct V_19 * V_19 = & V_17 -> V_19 . V_19 ;
F_38 ( V_19 ) ;
F_39 ( V_19 , V_18 -> V_25 . V_6 , & V_17 -> V_27 -> V_28 , 0 ) ;
F_36 ( V_15 , F_28 , V_46 ) ;
}
static void F_40 ( struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_15 , struct V_5 , V_47 ) ;
struct V_48 * V_27 ;
struct V_16 * V_17 ;
struct V_19 * V_19 ;
while ( ! F_41 ( V_49 , & V_6 -> V_50 ) ) {
V_27 = F_42 ( V_6 , & V_6 -> V_7 , & V_51 ) ;
if ( ! V_27 )
break;
V_17 = F_43 ( sizeof( struct V_16 ) + sizeof( struct V_20 )
* F_26 ( F_25 ( & V_27 -> V_28 ) , V_35 ) ,
V_52 ) ;
if ( ! V_17 )
goto V_53;
V_27 -> V_54 = V_17 ;
V_17 -> V_27 = V_27 ;
V_17 -> V_18 . V_25 . V_55 = F_44 ( & V_27 -> V_28 ) ;
V_17 -> V_18 . V_25 . V_6 = V_6 ;
F_20 ( V_17 ) ;
V_19 = & V_17 -> V_19 . V_19 ;
V_19 -> V_56 = V_57 ;
V_19 -> V_58 = F_18 ;
if ( F_45 ( V_19 , V_52 ) )
goto V_53;
F_12 ( L_5 , F_13 ( & V_27 -> V_28 ) ) ;
F_46 ( & V_17 -> V_18 . V_15 , F_37 , NULL , & V_6 -> V_59 . V_15 ) ;
if ( F_47 ( & V_6 -> V_29 ) >= 64 ) {
F_48 ( & V_6 -> V_30 , V_15 ,
F_49 ( & V_6 -> V_29 ) < 64 ) ;
F_36 ( V_15 , F_40 , V_46 ) ;
}
}
if ( 0 ) {
V_53: if ( ! F_50 ( V_27 -> V_54 ) )
F_8 ( V_27 -> V_54 ) ;
F_14 ( & V_6 -> V_7 , V_27 ) ;
}
F_51 ( V_15 ) ;
}
static bool F_52 ( struct V_11 * V_60 , struct V_11 * V_61 )
{
return F_6 ( V_60 ) < F_6 ( V_61 ) ;
}
static unsigned F_53 ( struct V_9 * V_10 )
{
return F_6 ( F_54 ( & V_10 -> V_62 ) ) ;
}
void F_55 ( struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_15 , struct V_5 , V_59 . V_15 ) ;
struct V_9 * V_10 ;
struct V_11 * V_63 ;
unsigned V_8 ;
if ( ! V_6 -> V_64 )
F_51 ( V_15 ) ;
F_56 ( & V_6 -> V_65 ) ;
F_57 (ca, c, i) {
unsigned V_66 = 0 ;
unsigned V_67 = V_10 -> V_68 . V_69 *
F_58 ( F_59 ( & V_10 -> free ) , V_10 -> free . V_70 / 2 ) ;
V_10 -> V_62 . V_71 = 0 ;
F_60 (b, ca) {
if ( ! F_6 ( V_63 ) )
continue;
if ( ! F_61 ( & V_10 -> V_62 ) ) {
V_66 += F_6 ( V_63 ) ;
F_62 ( & V_10 -> V_62 , V_63 , F_52 ) ;
} else if ( F_52 ( V_63 , F_54 ( & V_10 -> V_62 ) ) ) {
V_66 -= F_53 ( V_10 ) ;
V_66 += F_6 ( V_63 ) ;
V_10 -> V_62 . V_72 [ 0 ] = V_63 ;
F_63 ( & V_10 -> V_62 , 0 , F_52 ) ;
}
}
while ( V_66 > V_67 ) {
F_64 ( & V_10 -> V_62 , V_63 , F_52 ) ;
V_66 -= F_6 ( V_63 ) ;
}
V_10 -> V_13 = F_53 ( V_10 ) ;
F_12 ( L_6 , V_10 -> V_13 ) ;
}
F_65 ( & V_6 -> V_65 ) ;
V_6 -> V_7 . V_73 = V_74 ;
F_34 ( & V_6 -> V_47 , V_15 ) ;
F_40 ( & V_6 -> V_47 ) ;
F_51 ( V_15 ) ;
}
void F_66 ( struct V_5 * V_6 )
{
F_67 ( & V_6 -> V_7 , F_1 ) ;
}
