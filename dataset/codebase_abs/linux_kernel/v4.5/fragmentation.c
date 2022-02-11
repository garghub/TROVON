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
F_8 ( & V_12 -> V_16 ) ;
if ( ! F_7 || F_7 ( V_12 ) ) {
F_1 ( & V_12 -> V_2 ) ;
V_12 -> V_17 = 0 ;
}
F_9 ( & V_12 -> V_16 ) ;
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
F_12 ( & V_12 -> V_16 ) ;
if ( V_12 -> V_22 == V_22 )
return false ;
if ( ! F_13 ( & V_12 -> V_2 ) )
F_1 ( & V_12 -> V_2 ) ;
V_12 -> V_17 = 0 ;
V_12 -> V_22 = V_22 ;
return true ;
}
static bool F_14 ( struct V_9 * V_10 ,
struct V_23 * V_8 ,
struct V_1 * V_24 )
{
struct V_11 * V_12 ;
struct V_3 * V_25 = NULL , * V_26 ;
struct V_3 * V_27 = NULL ;
struct V_20 * V_28 ;
T_1 V_29 ;
T_2 V_22 , V_30 = sizeof( struct V_20 ) ;
bool V_31 = false ;
if ( F_15 ( V_8 ) < 0 )
goto V_32;
V_28 = (struct V_20 * ) V_8 -> V_33 ;
V_22 = F_16 ( V_28 -> V_22 ) ;
V_29 = V_22 % V_14 ;
V_25 = F_17 ( sizeof( * V_25 ) , V_34 ) ;
if ( ! V_25 )
goto V_32;
V_25 -> V_8 = V_8 ;
V_25 -> V_35 = V_28 -> V_35 ;
V_12 = & V_10 -> V_15 [ V_29 ] ;
F_8 ( & V_12 -> V_16 ) ;
if ( F_11 ( V_12 , V_22 ) ) {
F_18 ( & V_25 -> V_7 , & V_12 -> V_2 ) ;
V_12 -> V_17 = V_8 -> V_36 - V_30 ;
V_12 -> V_37 = V_38 ;
V_12 -> V_39 = F_16 ( V_28 -> V_39 ) ;
V_31 = true ;
goto V_40;
}
F_19 (frag_entry_curr, &chain->head, list) {
if ( V_26 -> V_35 == V_25 -> V_35 )
goto V_41;
if ( V_26 -> V_35 < V_25 -> V_35 ) {
F_20 ( & V_25 -> V_7 ,
& V_26 -> V_7 ) ;
V_12 -> V_17 += V_8 -> V_36 - V_30 ;
V_12 -> V_37 = V_38 ;
V_31 = true ;
goto V_40;
}
V_27 = V_26 ;
}
if ( F_21 ( V_27 ) ) {
F_22 ( & V_25 -> V_7 , & V_27 -> V_7 ) ;
V_12 -> V_17 += V_8 -> V_36 - V_30 ;
V_12 -> V_37 = V_38 ;
V_31 = true ;
}
V_40:
if ( V_12 -> V_17 > F_10 () ||
V_12 -> V_39 != F_16 ( V_28 -> V_39 ) ||
V_12 -> V_39 > F_10 () ) {
F_1 ( & V_12 -> V_2 ) ;
V_12 -> V_17 = 0 ;
} else if ( F_16 ( V_28 -> V_39 ) == V_12 -> V_17 ) {
F_23 ( & V_12 -> V_2 , V_24 ) ;
V_12 -> V_17 = 0 ;
}
V_41:
F_9 ( & V_12 -> V_16 ) ;
V_32:
if ( ! V_31 )
F_5 ( V_25 ) ;
return V_31 ;
}
static struct V_23 *
F_24 ( struct V_1 * V_12 )
{
struct V_20 * V_42 ;
struct V_3 * V_4 ;
struct V_23 * V_43 = NULL ;
int V_17 , V_30 = sizeof( struct V_20 ) ;
V_4 = F_25 ( V_12 -> V_44 , struct V_3 , V_7 ) ;
F_3 ( & V_4 -> V_7 ) ;
V_43 = V_4 -> V_8 ;
F_5 ( V_4 ) ;
V_42 = (struct V_20 * ) V_43 -> V_33 ;
V_17 = F_16 ( V_42 -> V_39 ) ;
if ( F_26 ( V_43 , 0 , V_17 - V_43 -> V_36 , V_34 ) < 0 ) {
F_4 ( V_43 ) ;
V_43 = NULL ;
goto free;
}
F_27 ( V_43 , V_30 ) ;
memmove ( V_43 -> V_33 - V_45 , F_28 ( V_43 ) , V_45 ) ;
F_29 ( V_43 , - V_45 ) ;
F_30 ( V_43 ) ;
F_31 ( V_43 ) ;
F_19 (entry, chain, list) {
V_17 = V_4 -> V_8 -> V_36 - V_30 ;
memcpy ( F_32 ( V_43 , V_17 ) , V_4 -> V_8 -> V_33 + V_30 ,
V_17 ) ;
}
free:
F_1 ( V_12 ) ;
return V_43 ;
}
bool F_33 ( struct V_23 * * V_8 ,
struct V_9 * V_46 )
{
struct V_23 * V_43 = NULL ;
struct V_1 V_2 = V_47 ;
bool V_31 = false ;
if ( ! F_14 ( V_46 , * V_8 , & V_2 ) )
goto V_48;
if ( F_13 ( & V_2 ) )
goto V_40;
V_43 = F_24 ( & V_2 ) ;
if ( ! V_43 )
goto V_48;
V_40:
* V_8 = V_43 ;
V_31 = true ;
V_48:
return V_31 ;
}
bool F_34 ( struct V_23 * V_8 ,
struct V_49 * V_50 ,
struct V_9 * V_46 )
{
struct V_51 * V_52 = F_35 ( V_50 -> V_53 ) ;
struct V_9 * V_54 = NULL ;
struct V_55 * V_56 = NULL ;
struct V_20 * V_42 ;
T_2 V_39 ;
bool V_31 = false ;
V_42 = (struct V_20 * ) V_8 -> V_33 ;
V_54 = F_36 ( V_52 , V_42 -> V_57 ) ;
if ( ! V_54 )
goto V_40;
V_56 = F_37 ( V_52 , V_54 , V_50 ) ;
if ( ! V_56 )
goto V_40;
V_39 = F_16 ( V_42 -> V_39 ) ;
if ( V_39 > V_56 -> V_58 -> V_59 -> V_60 ) {
F_38 ( V_52 , V_61 ) ;
F_39 ( V_52 , V_62 ,
V_8 -> V_36 + V_45 ) ;
V_42 -> V_63 -- ;
F_40 ( V_8 , V_56 -> V_58 ,
V_56 -> V_64 ) ;
V_31 = true ;
}
V_40:
if ( V_54 )
F_41 ( V_54 ) ;
if ( V_56 )
F_42 ( V_56 ) ;
return V_31 ;
}
static struct V_23 * F_43 ( struct V_23 * V_8 ,
struct V_20 * V_65 ,
unsigned int V_60 )
{
struct V_23 * V_66 ;
unsigned V_67 = sizeof( * V_65 ) ;
unsigned V_68 = V_60 - V_67 ;
V_66 = F_44 ( NULL , V_60 + V_45 ) ;
if ( ! V_66 )
goto V_32;
V_8 -> V_69 = V_70 ;
F_45 ( V_66 , V_67 + V_45 ) ;
F_46 ( V_8 , V_66 , V_8 -> V_36 - V_68 ) ;
F_47 ( V_66 , V_67 ) ;
memcpy ( V_66 -> V_33 , V_65 , V_67 ) ;
V_32:
return V_66 ;
}
bool F_48 ( struct V_23 * V_8 ,
struct V_9 * V_10 ,
struct V_55 * V_56 )
{
struct V_51 * V_52 ;
struct V_49 * V_71 = NULL ;
struct V_20 V_72 ;
struct V_23 * V_66 ;
unsigned V_60 = V_56 -> V_58 -> V_59 -> V_60 ;
unsigned V_67 = sizeof( V_72 ) ;
unsigned V_73 , V_74 ;
bool V_31 = false ;
V_60 = F_49 ( unsigned , V_60 , V_19 ) ;
V_73 = V_60 - V_67 ;
V_74 = V_73 * V_21 ;
if ( V_8 -> V_36 > V_74 )
goto V_48;
V_52 = V_10 -> V_52 ;
V_71 = F_50 ( V_52 ) ;
if ( ! V_71 )
goto V_48;
V_72 . V_75 = V_76 ;
V_72 . V_77 = V_78 ;
V_72 . V_63 = V_79 ;
V_72 . V_22 = F_51 ( F_52 ( & V_52 -> V_80 ) ) ;
V_72 . V_81 = 0 ;
V_72 . V_35 = 0 ;
V_72 . V_39 = F_51 ( V_8 -> V_36 ) ;
F_53 ( V_72 . V_82 , V_71 -> V_59 -> V_83 ) ;
F_53 ( V_72 . V_57 , V_10 -> V_82 ) ;
while ( V_8 -> V_36 > V_73 ) {
V_66 = F_43 ( V_8 , & V_72 , V_60 ) ;
if ( ! V_66 )
goto V_48;
F_38 ( V_52 , V_84 ) ;
F_39 ( V_52 , V_85 ,
V_66 -> V_36 + V_45 ) ;
F_40 ( V_66 , V_56 -> V_58 ,
V_56 -> V_64 ) ;
V_72 . V_35 ++ ;
if ( V_72 . V_35 == V_21 - 1 )
goto V_48;
}
if ( F_54 ( V_8 , V_67 ) < 0 ||
F_26 ( V_8 , V_67 + V_45 , 0 , V_34 ) < 0 )
goto V_48;
memcpy ( V_8 -> V_33 , & V_72 , V_67 ) ;
F_38 ( V_52 , V_84 ) ;
F_39 ( V_52 , V_85 ,
V_8 -> V_36 + V_45 ) ;
F_40 ( V_8 , V_56 -> V_58 , V_56 -> V_64 ) ;
V_31 = true ;
V_48:
if ( V_71 )
F_55 ( V_71 ) ;
return V_31 ;
}
