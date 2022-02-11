static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
F_2 (entry, node, head, list) {
F_3 ( & V_4 -> V_7 ) ;
F_4 ( V_4 -> V_8 ) ;
F_5 ( V_4 ) ;
}
}
void F_6 ( struct V_9 * V_10 ,
bool (* F_7)( struct V_11 * ) )
{
struct V_11 * V_12 ;
T_1 V_13 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
V_12 = & V_10 -> V_15 [ V_13 ] ;
F_8 ( & V_10 -> V_15 [ V_13 ] . V_16 ) ;
if ( ! F_7 || F_7 ( V_12 ) ) {
F_1 ( & V_10 -> V_15 [ V_13 ] . V_2 ) ;
V_10 -> V_15 [ V_13 ] . V_17 = 0 ;
}
F_9 ( & V_10 -> V_15 [ V_13 ] . V_16 ) ;
}
}
static int F_10 ( void )
{
int V_18 = V_19 ;
V_18 -= sizeof( struct V_20 ) ;
V_18 *= V_21 ;
return V_18 ;
}
static bool F_11 ( struct V_11 * V_12 ,
T_2 V_22 )
{
if ( V_12 -> V_22 == V_22 )
return false ;
if ( ! F_12 ( & V_12 -> V_2 ) )
F_1 ( & V_12 -> V_2 ) ;
V_12 -> V_17 = 0 ;
V_12 -> V_22 = V_22 ;
return true ;
}
static bool F_13 ( struct V_9 * V_10 ,
struct V_23 * V_8 ,
struct V_1 * V_24 )
{
struct V_11 * V_12 ;
struct V_3 * V_25 = NULL , * V_26 ;
struct V_20 * V_27 ;
T_1 V_28 ;
T_2 V_22 , V_29 = sizeof( struct V_20 ) ;
bool V_30 = false ;
if ( F_14 ( V_8 ) < 0 )
goto V_31;
V_27 = (struct V_20 * ) V_8 -> V_32 ;
V_22 = F_15 ( V_27 -> V_22 ) ;
V_28 = V_22 % V_14 ;
V_25 = F_16 ( sizeof( * V_25 ) , V_33 ) ;
if ( ! V_25 )
goto V_31;
V_25 -> V_8 = V_8 ;
V_25 -> V_34 = V_27 -> V_34 ;
V_12 = & V_10 -> V_15 [ V_28 ] ;
F_8 ( & V_12 -> V_16 ) ;
if ( F_11 ( V_12 , V_22 ) ) {
F_17 ( & V_25 -> V_7 , & V_12 -> V_2 ) ;
V_12 -> V_17 = V_8 -> V_35 - V_29 ;
V_12 -> V_36 = V_37 ;
V_30 = true ;
goto V_38;
}
F_18 (frag_entry_curr, &chain->head, list) {
if ( V_26 -> V_34 == V_25 -> V_34 )
goto V_39;
if ( V_26 -> V_34 < V_25 -> V_34 ) {
F_19 ( & V_25 -> V_7 ,
& V_26 -> V_7 ) ;
V_12 -> V_17 += V_8 -> V_35 - V_29 ;
V_12 -> V_36 = V_37 ;
V_30 = true ;
goto V_38;
}
}
if ( F_20 ( V_26 ) ) {
F_21 ( & V_26 -> V_7 , & V_25 -> V_7 ) ;
V_12 -> V_17 += V_8 -> V_35 - V_29 ;
V_12 -> V_36 = V_37 ;
V_30 = true ;
}
V_38:
if ( V_12 -> V_17 > F_10 () ||
F_15 ( V_27 -> V_40 ) > F_10 () ) {
F_1 ( & V_12 -> V_2 ) ;
V_12 -> V_17 = 0 ;
} else if ( F_15 ( V_27 -> V_40 ) == V_12 -> V_17 ) {
F_22 ( & V_12 -> V_2 , V_24 ) ;
V_12 -> V_17 = 0 ;
}
V_39:
F_9 ( & V_12 -> V_16 ) ;
V_31:
if ( ! V_30 )
F_5 ( V_25 ) ;
return V_30 ;
}
static struct V_23 *
F_23 ( struct V_1 * V_12 , struct V_23 * V_8 )
{
struct V_20 * V_41 ;
struct V_3 * V_4 ;
struct V_23 * V_42 = NULL ;
int V_17 , V_29 = sizeof( struct V_20 ) ;
V_41 = (struct V_20 * ) V_8 -> V_32 ;
V_17 = F_15 ( V_41 -> V_40 ) ;
if ( V_17 > F_10 () )
goto free;
V_4 = F_24 ( V_12 -> V_43 , struct V_3 , V_7 ) ;
F_3 ( & V_4 -> V_7 ) ;
V_42 = V_4 -> V_8 ;
F_5 ( V_4 ) ;
if ( F_25 ( V_42 , 0 , V_17 - V_8 -> V_35 , V_33 ) < 0 ) {
F_4 ( V_42 ) ;
V_42 = NULL ;
goto free;
}
F_26 ( V_42 , V_29 ) ;
memmove ( V_42 -> V_32 - V_44 , F_27 ( V_42 ) , V_44 ) ;
F_28 ( V_42 , - V_44 ) ;
F_29 ( V_42 ) ;
F_30 ( V_42 ) ;
F_18 (entry, chain, list) {
V_17 = V_4 -> V_8 -> V_35 - V_29 ;
memcpy ( F_31 ( V_42 , V_17 ) , V_4 -> V_8 -> V_32 + V_29 ,
V_17 ) ;
}
free:
F_1 ( V_12 ) ;
return V_42 ;
}
bool F_32 ( struct V_23 * * V_8 ,
struct V_9 * V_45 )
{
struct V_23 * V_42 = NULL ;
struct V_1 V_2 = V_46 ;
bool V_30 = false ;
if ( ! F_13 ( V_45 , * V_8 , & V_2 ) )
goto V_47;
if ( F_12 ( & V_2 ) )
goto V_38;
V_42 = F_23 ( & V_2 , * V_8 ) ;
if ( ! V_42 )
goto V_47;
V_38:
* V_8 = V_42 ;
V_30 = true ;
V_47:
return V_30 ;
}
bool F_33 ( struct V_23 * V_8 ,
struct V_48 * V_49 ,
struct V_9 * V_45 )
{
struct V_50 * V_51 = F_34 ( V_49 -> V_52 ) ;
struct V_9 * V_53 = NULL ;
struct V_54 * V_55 = NULL ;
struct V_20 * V_41 ;
T_2 V_40 ;
bool V_30 = false ;
V_41 = (struct V_20 * ) V_8 -> V_32 ;
V_53 = F_35 ( V_51 , V_41 -> V_56 ) ;
if ( ! V_53 )
goto V_38;
V_55 = F_36 ( V_51 , V_53 , V_49 ) ;
if ( ! V_55 )
goto V_38;
V_40 = F_15 ( V_41 -> V_40 ) ;
if ( V_40 > V_55 -> V_57 -> V_58 -> V_59 ) {
F_37 ( V_51 , V_60 ) ;
F_38 ( V_51 , V_61 ,
V_8 -> V_35 + V_44 ) ;
V_41 -> V_62 -- ;
F_39 ( V_8 , V_55 -> V_57 ,
V_55 -> V_63 ) ;
V_30 = true ;
}
V_38:
if ( V_53 )
F_40 ( V_53 ) ;
if ( V_55 )
F_41 ( V_55 ) ;
return V_30 ;
}
static struct V_23 * F_42 ( struct V_23 * V_8 ,
struct V_20 * V_64 ,
unsigned int V_59 )
{
struct V_23 * V_65 ;
unsigned V_66 = sizeof( * V_64 ) ;
unsigned V_67 = V_59 - V_66 ;
V_65 = F_43 ( NULL , V_59 + V_44 ) ;
if ( ! V_65 )
goto V_31;
V_8 -> V_68 = V_69 ;
F_44 ( V_65 , V_66 + V_44 ) ;
F_45 ( V_8 , V_65 , V_8 -> V_35 - V_67 ) ;
F_46 ( V_65 , V_66 ) ;
memcpy ( V_65 -> V_32 , V_64 , V_66 ) ;
V_31:
return V_65 ;
}
bool F_47 ( struct V_23 * V_8 ,
struct V_9 * V_10 ,
struct V_54 * V_55 )
{
struct V_50 * V_51 ;
struct V_48 * V_70 ;
struct V_20 V_71 ;
struct V_23 * V_65 ;
unsigned V_59 = V_55 -> V_57 -> V_58 -> V_59 ;
unsigned V_66 = sizeof( V_71 ) ;
unsigned V_72 , V_73 ;
V_59 = F_48 ( unsigned , V_59 , V_19 ) ;
V_72 = ( V_59 - V_66 - V_44 ) ;
V_73 = V_72 * V_21 ;
if ( V_8 -> V_35 > V_73 )
goto V_47;
V_51 = V_10 -> V_51 ;
V_70 = F_49 ( V_51 ) ;
if ( ! V_70 )
goto V_47;
V_71 . V_74 = V_75 ;
V_71 . V_76 = V_77 ;
V_71 . V_62 = V_78 ;
V_71 . V_22 = F_50 ( F_51 ( & V_51 -> V_79 ) ) ;
V_71 . V_80 = 0 ;
V_71 . V_34 = 0 ;
V_71 . V_40 = F_50 ( V_8 -> V_35 ) ;
memcpy ( V_71 . V_81 , V_70 -> V_58 -> V_82 , V_83 ) ;
memcpy ( V_71 . V_56 , V_10 -> V_81 , V_83 ) ;
while ( V_8 -> V_35 > V_72 ) {
V_65 = F_42 ( V_8 , & V_71 , V_59 ) ;
if ( ! V_65 )
goto V_47;
F_37 ( V_51 , V_84 ) ;
F_38 ( V_51 , V_85 ,
V_65 -> V_35 + V_44 ) ;
F_39 ( V_65 , V_55 -> V_57 ,
V_55 -> V_63 ) ;
V_71 . V_34 ++ ;
if ( V_71 . V_34 == V_21 - 1 )
goto V_47;
}
if ( F_52 ( V_8 , V_66 ) < 0 ||
F_25 ( V_8 , V_66 + V_44 , 0 , V_33 ) < 0 )
goto V_47;
memcpy ( V_8 -> V_32 , & V_71 , V_66 ) ;
F_37 ( V_51 , V_84 ) ;
F_38 ( V_51 , V_85 ,
V_8 -> V_35 + V_44 ) ;
F_39 ( V_8 , V_55 -> V_57 , V_55 -> V_63 ) ;
return true ;
V_47:
return false ;
}
