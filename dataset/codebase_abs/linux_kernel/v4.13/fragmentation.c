static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
F_2 (entry, node, head, list) {
F_3 ( & V_5 -> V_8 ) ;
if ( V_3 )
F_4 ( V_5 -> V_9 ) ;
else
F_5 ( V_5 -> V_9 ) ;
F_6 ( V_5 ) ;
}
}
void F_7 ( struct V_10 * V_11 ,
bool (* F_8)( struct V_12 * ) )
{
struct V_12 * V_13 ;
T_1 V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_13 = & V_11 -> V_16 [ V_14 ] ;
F_9 ( & V_13 -> V_17 ) ;
if ( ! F_8 || F_8 ( V_13 ) ) {
F_1 ( & V_13 -> V_18 , true ) ;
V_13 -> V_19 = 0 ;
}
F_10 ( & V_13 -> V_17 ) ;
}
}
static int F_11 ( void )
{
int V_20 = V_21 ;
V_20 -= sizeof( struct V_22 ) ;
V_20 *= V_23 ;
return V_20 ;
}
static bool F_12 ( struct V_12 * V_13 ,
T_2 V_24 )
{
F_13 ( & V_13 -> V_17 ) ;
if ( V_13 -> V_24 == V_24 )
return false ;
if ( ! F_14 ( & V_13 -> V_18 ) )
F_1 ( & V_13 -> V_18 , true ) ;
V_13 -> V_19 = 0 ;
V_13 -> V_24 = V_24 ;
return true ;
}
static bool F_15 ( struct V_10 * V_11 ,
struct V_25 * V_9 ,
struct V_1 * V_26 )
{
struct V_12 * V_13 ;
struct V_4 * V_27 = NULL , * V_28 ;
struct V_4 * V_29 = NULL ;
struct V_22 * V_30 ;
T_1 V_31 ;
T_2 V_24 , V_32 = sizeof( struct V_22 ) ;
bool V_33 = false ;
if ( F_16 ( V_9 ) < 0 )
goto V_34;
V_30 = (struct V_22 * ) V_9 -> V_35 ;
V_24 = F_17 ( V_30 -> V_24 ) ;
V_31 = V_24 % V_15 ;
V_27 = F_18 ( sizeof( * V_27 ) , V_36 ) ;
if ( ! V_27 )
goto V_34;
V_27 -> V_9 = V_9 ;
V_27 -> V_37 = V_30 -> V_37 ;
V_13 = & V_11 -> V_16 [ V_31 ] ;
F_9 ( & V_13 -> V_17 ) ;
if ( F_12 ( V_13 , V_24 ) ) {
F_19 ( & V_27 -> V_8 , & V_13 -> V_18 ) ;
V_13 -> V_19 = V_9 -> V_38 - V_32 ;
V_13 -> V_39 = V_40 ;
V_13 -> V_41 = F_17 ( V_30 -> V_41 ) ;
V_33 = true ;
goto V_42;
}
F_20 (frag_entry_curr, &chain->fragment_list, list) {
if ( V_28 -> V_37 == V_27 -> V_37 )
goto V_43;
if ( V_28 -> V_37 < V_27 -> V_37 ) {
F_21 ( & V_27 -> V_8 ,
& V_28 -> V_8 ) ;
V_13 -> V_19 += V_9 -> V_38 - V_32 ;
V_13 -> V_39 = V_40 ;
V_33 = true ;
goto V_42;
}
V_29 = V_28 ;
}
if ( F_22 ( V_29 ) ) {
F_23 ( & V_27 -> V_8 , & V_29 -> V_8 ) ;
V_13 -> V_19 += V_9 -> V_38 - V_32 ;
V_13 -> V_39 = V_40 ;
V_33 = true ;
}
V_42:
if ( V_13 -> V_19 > F_11 () ||
V_13 -> V_41 != F_17 ( V_30 -> V_41 ) ||
V_13 -> V_41 > F_11 () ) {
F_1 ( & V_13 -> V_18 , true ) ;
V_13 -> V_19 = 0 ;
} else if ( F_17 ( V_30 -> V_41 ) == V_13 -> V_19 ) {
F_24 ( & V_13 -> V_18 , V_26 ) ;
V_13 -> V_19 = 0 ;
}
V_43:
F_10 ( & V_13 -> V_17 ) ;
V_34:
if ( ! V_33 ) {
F_6 ( V_27 ) ;
F_4 ( V_9 ) ;
}
return V_33 ;
}
static struct V_25 *
F_25 ( struct V_1 * V_13 )
{
struct V_22 * V_44 ;
struct V_4 * V_5 ;
struct V_25 * V_45 ;
int V_19 , V_32 = sizeof( struct V_22 ) ;
bool V_3 = false ;
V_5 = F_26 ( V_13 -> V_46 , struct V_4 , V_8 ) ;
F_3 ( & V_5 -> V_8 ) ;
V_45 = V_5 -> V_9 ;
F_6 ( V_5 ) ;
V_44 = (struct V_22 * ) V_45 -> V_35 ;
V_19 = F_17 ( V_44 -> V_41 ) ;
if ( F_27 ( V_45 , 0 , V_19 - V_45 -> V_38 , V_36 ) < 0 ) {
F_4 ( V_45 ) ;
V_45 = NULL ;
V_3 = true ;
goto free;
}
F_28 ( V_45 , V_32 ) ;
memmove ( V_45 -> V_35 - V_47 , F_29 ( V_45 ) , V_47 ) ;
F_30 ( V_45 , - V_47 ) ;
F_31 ( V_45 ) ;
F_32 ( V_45 ) ;
F_20 (entry, chain, list) {
V_19 = V_5 -> V_9 -> V_38 - V_32 ;
F_33 ( V_45 , V_5 -> V_9 -> V_35 + V_32 , V_19 ) ;
}
free:
F_1 ( V_13 , V_3 ) ;
return V_45 ;
}
bool F_34 ( struct V_25 * * V_9 ,
struct V_10 * V_48 )
{
struct V_25 * V_45 = NULL ;
struct V_1 V_2 = V_49 ;
bool V_33 = false ;
if ( ! F_15 ( V_48 , * V_9 , & V_2 ) )
goto V_50;
if ( F_14 ( & V_2 ) )
goto V_42;
V_45 = F_25 ( & V_2 ) ;
if ( ! V_45 )
goto V_50;
V_42:
V_33 = true ;
V_50:
* V_9 = V_45 ;
return V_33 ;
}
bool F_35 ( struct V_25 * V_9 ,
struct V_51 * V_52 ,
struct V_10 * V_48 )
{
struct V_53 * V_54 = F_36 ( V_52 -> V_55 ) ;
struct V_10 * V_56 ;
struct V_57 * V_58 = NULL ;
struct V_22 * V_44 ;
T_2 V_41 ;
bool V_33 = false ;
V_44 = (struct V_22 * ) V_9 -> V_35 ;
V_56 = F_37 ( V_54 , V_44 -> V_59 ) ;
if ( ! V_56 )
goto V_42;
V_58 = F_38 ( V_54 , V_56 , V_52 ) ;
if ( ! V_58 )
goto V_42;
V_41 = F_17 ( V_44 -> V_41 ) ;
if ( V_41 > V_58 -> V_60 -> V_61 -> V_62 ) {
F_39 ( V_54 , V_63 ) ;
F_40 ( V_54 , V_64 ,
V_9 -> V_38 + V_47 ) ;
V_44 -> V_65 -- ;
F_41 ( V_9 , V_58 ) ;
V_33 = true ;
}
V_42:
if ( V_56 )
F_42 ( V_56 ) ;
if ( V_58 )
F_43 ( V_58 ) ;
return V_33 ;
}
static struct V_25 * F_44 ( struct V_25 * V_9 ,
struct V_22 * V_66 ,
unsigned int V_67 )
{
struct V_25 * V_68 ;
unsigned int V_69 = sizeof( * V_66 ) ;
unsigned int V_62 = V_67 + V_69 ;
V_68 = F_45 ( NULL , V_62 + V_47 ) ;
if ( ! V_68 )
goto V_34;
V_68 -> V_70 = V_9 -> V_70 ;
F_46 ( V_68 , V_69 + V_47 ) ;
F_47 ( V_9 , V_68 , V_9 -> V_38 - V_67 ) ;
F_48 ( V_68 , V_69 ) ;
memcpy ( V_68 -> V_35 , V_66 , V_69 ) ;
V_34:
return V_68 ;
}
int F_49 ( struct V_25 * V_9 ,
struct V_10 * V_11 ,
struct V_57 * V_58 )
{
struct V_53 * V_54 ;
struct V_51 * V_71 = NULL ;
struct V_22 V_72 ;
struct V_25 * V_68 ;
unsigned int V_62 = V_58 -> V_60 -> V_61 -> V_62 ;
unsigned int V_69 = sizeof( V_72 ) ;
unsigned int V_73 , V_74 ;
int V_33 ;
V_62 = F_50 (unsigned int, mtu, BATADV_FRAG_MAX_FRAG_SIZE) ;
V_73 = V_62 - V_69 ;
if ( V_9 -> V_38 == 0 || V_73 == 0 )
return - V_75 ;
V_74 = ( V_9 -> V_38 - 1 ) / V_73 + 1 ;
V_73 = ( V_9 -> V_38 - 1 ) / V_74 + 1 ;
if ( V_74 > V_23 ) {
V_33 = - V_76 ;
goto V_77;
}
V_54 = V_11 -> V_54 ;
V_71 = F_51 ( V_54 ) ;
if ( ! V_71 ) {
V_33 = - V_75 ;
goto V_77;
}
V_72 . V_78 = V_79 ;
V_72 . V_80 = V_81 ;
V_72 . V_65 = V_82 ;
V_72 . V_24 = F_52 ( F_53 ( & V_54 -> V_83 ) ) ;
V_72 . V_84 = 0 ;
V_72 . V_37 = 0 ;
V_72 . V_41 = F_52 ( V_9 -> V_38 ) ;
if ( V_9 -> V_70 >= 256 && V_9 -> V_70 <= 263 )
V_72 . V_70 = V_9 -> V_70 - 256 ;
F_54 ( V_72 . V_85 , V_71 -> V_61 -> V_86 ) ;
F_54 ( V_72 . V_59 , V_11 -> V_85 ) ;
while ( V_9 -> V_38 > V_73 ) {
if ( F_55 ( V_72 . V_37 == V_23 - 1 ) ) {
V_33 = - V_75 ;
goto V_87;
}
V_68 = F_44 ( V_9 , & V_72 ,
V_73 ) ;
if ( ! V_68 ) {
V_33 = - V_88 ;
goto V_87;
}
F_39 ( V_54 , V_89 ) ;
F_40 ( V_54 , V_90 ,
V_68 -> V_38 + V_47 ) ;
V_33 = F_41 ( V_68 , V_58 ) ;
if ( V_33 != V_91 ) {
V_33 = V_92 ;
goto V_87;
}
V_72 . V_37 ++ ;
}
if ( F_56 ( V_9 , V_69 ) < 0 ||
F_27 ( V_9 , V_69 + V_47 , 0 , V_36 ) < 0 ) {
V_33 = - V_88 ;
goto V_87;
}
memcpy ( V_9 -> V_35 , & V_72 , V_69 ) ;
F_39 ( V_54 , V_89 ) ;
F_40 ( V_54 , V_90 ,
V_9 -> V_38 + V_47 ) ;
V_33 = F_41 ( V_9 , V_58 ) ;
V_9 = NULL ;
V_87:
F_57 ( V_71 ) ;
V_77:
F_4 ( V_9 ) ;
return V_33 ;
}
