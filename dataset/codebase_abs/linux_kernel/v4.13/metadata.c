static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
V_7 = & V_5 -> V_8 . V_9 ;
if ( ! F_2 ( V_7 -> V_10 , V_7 -> V_11 , V_12 *
V_13 -
V_13 + 1 ) )
return - V_14 ;
memcpy ( & V_7 -> V_15 [ V_7 -> V_10 ] , & V_3 , V_13 ) ;
V_7 -> V_10 = ( V_7 -> V_10 + V_13 ) %
( V_12 * V_13 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_16 , V_17 ;
struct V_6 * V_7 ;
V_7 = & V_5 -> V_8 . V_9 ;
V_16 = V_12 ;
if ( V_5 -> V_8 . V_18 > 0 ) {
* V_3 = V_5 -> V_8 . V_18 - 1 ;
V_5 -> V_8 . V_18 -- ;
return 0 ;
}
if ( V_7 -> V_10 == V_7 -> V_11 ) {
* V_3 = V_16 ;
return - V_19 ;
}
memcpy ( & V_17 , & V_7 -> V_15 [ V_7 -> V_11 ] , V_13 ) ;
* V_3 = V_17 ;
memcpy ( & V_7 -> V_15 [ V_7 -> V_11 ] , & V_16 , V_13 ) ;
V_7 -> V_11 = ( V_7 -> V_11 + V_13 ) %
( V_12 * V_13 ) ;
return 0 ;
}
struct V_20 *
F_4 ( struct V_1 * V_2 , unsigned long V_21 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_20 * V_22 ;
F_5 (priv->flow_table, flower_entry, link,
tc_flower_cookie)
if ( V_22 -> V_21 == V_21 )
return V_22 ;
return NULL ;
}
static void
F_6 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_20 * V_25 ;
unsigned long V_26 ;
V_26 = F_7 ( V_24 -> V_27 ) ;
F_8 () ;
V_25 = F_4 ( V_2 , V_26 ) ;
if ( ! V_25 )
goto V_28;
if ( V_25 -> V_29 . V_30 != V_24 -> V_31 )
goto V_28;
F_9 ( & V_25 -> V_32 ) ;
V_25 -> V_24 . V_33 += F_10 ( V_24 -> V_34 ) ;
V_25 -> V_24 . V_35 += F_7 ( V_24 -> V_36 ) ;
V_25 -> V_24 . V_37 = V_38 ;
F_11 ( & V_25 -> V_32 ) ;
V_28:
F_12 () ;
}
void F_13 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
unsigned int V_41 = V_40 -> V_42 - V_43 ;
struct V_23 * V_44 ;
unsigned char * V_45 ;
int V_46 ;
V_45 = F_14 ( V_40 ) ;
V_44 = (struct V_23 * ) V_45 ;
for ( V_46 = 0 ; V_46 < V_41 / sizeof( * V_44 ) ; V_46 ++ )
F_6 ( V_2 , V_44 + V_46 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_47 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_48 V_49 ;
V_7 = & V_5 -> V_50 . V_51 ;
if ( F_2 ( V_7 -> V_10 , V_7 -> V_11 , V_52 ) == 0 )
return - V_14 ;
memcpy ( & V_7 -> V_15 [ V_7 -> V_10 ] , & V_47 , V_53 ) ;
V_7 -> V_10 = ( V_7 -> V_10 + V_53 ) %
( V_52 * V_53 ) ;
F_16 ( & V_49 ) ;
V_5 -> V_50 . V_54 [ V_47 ] = V_49 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_2 * V_47 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 V_55 , V_49 ;
struct V_6 * V_7 ;
T_2 V_56 , V_57 ;
V_7 = & V_5 -> V_50 . V_51 ;
V_57 = V_52 - 1 ;
if ( V_5 -> V_50 . V_58 > 0 ) {
* V_47 = V_5 -> V_50 . V_58 ;
V_5 -> V_50 . V_58 -- ;
return 0 ;
}
if ( V_7 -> V_10 == V_7 -> V_11 )
goto V_59;
memcpy ( & V_56 , & V_7 -> V_15 [ V_7 -> V_11 ] , V_53 ) ;
* V_47 = V_56 ;
F_16 ( & V_49 ) ;
V_55 = F_18 ( V_49 , V_5 -> V_50 . V_54 [ * V_47 ] ) ;
if ( F_19 ( & V_55 ) < V_60 )
goto V_59;
memcpy ( & V_7 -> V_15 [ V_7 -> V_11 ] , & V_57 , V_53 ) ;
V_7 -> V_11 = ( V_7 -> V_11 + V_53 ) %
( V_52 * V_53 ) ;
return 0 ;
V_59:
* V_47 = V_57 ;
return - V_19 ;
}
static int
F_20 ( struct V_1 * V_2 , char * V_61 , T_1 V_62 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_63 * V_64 ;
unsigned long V_65 ;
T_2 V_47 ;
if ( F_17 ( V_2 , & V_47 ) )
return - V_19 ;
V_64 = F_21 ( sizeof( * V_64 ) , V_66 ) ;
if ( ! V_64 ) {
F_15 ( V_2 , V_47 ) ;
return - V_67 ;
}
F_22 ( & V_64 -> V_68 ) ;
V_64 -> V_47 = V_47 ;
V_65 = F_23 ( V_61 , V_62 , V_5 -> V_69 ) ;
V_64 -> V_65 = V_65 ;
V_64 -> V_70 = 1 ;
F_24 ( V_5 -> V_71 , & V_64 -> V_68 , V_65 ) ;
return V_47 ;
}
static struct V_63 *
F_25 ( struct V_1 * V_2 , char * V_61 , T_1 V_62 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_63 * V_64 ;
unsigned long V_65 ;
V_65 = F_23 ( V_61 , V_62 , V_5 -> V_69 ) ;
F_26 (priv->mask_table, mask_entry, link, hash_key)
if ( V_64 -> V_65 == V_65 )
return V_64 ;
return NULL ;
}
static int
F_27 ( struct V_1 * V_2 , char * V_61 , T_1 V_62 )
{
struct V_63 * V_64 ;
V_64 = F_25 ( V_2 , V_61 , V_62 ) ;
if ( ! V_64 )
return - V_19 ;
V_64 -> V_70 ++ ;
return V_64 -> V_47 ;
}
static bool
F_28 ( struct V_1 * V_2 , char * V_61 , T_1 V_62 ,
T_2 * V_72 , T_2 * V_47 )
{
int V_73 ;
V_73 = F_27 ( V_2 , V_61 , V_62 ) ;
if ( V_73 < 0 ) {
V_73 = F_20 ( V_2 , V_61 , V_62 ) ;
if ( V_73 < 0 )
return false ;
* V_72 |= V_74 ;
}
* V_47 = V_73 ;
return true ;
}
static bool
F_29 ( struct V_1 * V_2 , char * V_61 , T_1 V_62 ,
T_2 * V_72 , T_2 * V_47 )
{
struct V_63 * V_64 ;
V_64 = F_25 ( V_2 , V_61 , V_62 ) ;
if ( ! V_64 )
return false ;
* V_47 = V_64 -> V_47 ;
V_64 -> V_70 -- ;
if ( ! V_64 -> V_70 ) {
F_30 ( & V_64 -> V_68 ) ;
F_15 ( V_2 , * V_47 ) ;
F_31 ( V_64 ) ;
if ( V_72 )
* V_72 |= V_75 ;
}
return true ;
}
int F_32 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
struct V_20 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_20 * V_78 ;
T_2 V_79 ;
T_1 V_80 ;
if ( F_3 ( V_2 , & V_80 ) )
return - V_19 ;
V_25 -> V_29 . V_30 = F_33 ( V_80 ) ;
V_25 -> V_29 . V_81 = F_34 ( V_77 -> V_82 ) ;
V_79 = 0 ;
if ( ! F_28 ( V_2 , V_25 -> V_61 ,
V_25 -> V_29 . V_62 ,
& V_25 -> V_29 . V_83 , & V_79 ) ) {
if ( F_1 ( V_2 , V_80 ) )
return - V_84 ;
return - V_19 ;
}
V_25 -> V_29 . V_85 = F_34 ( V_5 -> V_86 ) ;
V_5 -> V_86 ++ ;
V_25 -> V_87 [ V_88 ] = V_79 ;
V_25 -> V_24 . V_33 = 0 ;
V_25 -> V_24 . V_35 = 0 ;
V_25 -> V_24 . V_37 = V_38 ;
V_78 = F_4 ( V_2 , V_77 -> V_82 ) ;
if ( V_78 ) {
if ( F_1 ( V_2 , V_80 ) )
return - V_84 ;
if ( ! F_29 ( V_2 , V_25 -> V_61 ,
V_25 -> V_29 . V_62 ,
NULL , & V_79 ) )
return - V_84 ;
return - V_89 ;
}
return 0 ;
}
int F_35 ( struct V_1 * V_2 ,
struct V_20 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_79 = 0 ;
T_1 V_90 ;
F_29 ( V_2 , V_25 -> V_61 ,
V_25 -> V_29 . V_62 , & V_25 -> V_29 . V_83 ,
& V_79 ) ;
V_25 -> V_29 . V_85 = F_34 ( V_5 -> V_86 ) ;
V_5 -> V_86 ++ ;
V_25 -> V_87 [ V_88 ] = V_79 ;
V_90 = F_10 ( V_25 -> V_29 . V_30 ) ;
return F_1 ( V_2 , V_90 ) ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_37 ( V_5 -> V_71 ) ;
F_37 ( V_5 -> V_91 ) ;
F_38 ( & V_5 -> V_69 , sizeof( V_5 -> V_69 ) ) ;
V_5 -> V_50 . V_51 . V_15 =
F_39 ( V_52 ,
V_53 , V_66 ) ;
if ( ! V_5 -> V_50 . V_51 . V_15 )
return - V_67 ;
V_5 -> V_50 . V_58 = V_52 - 1 ;
V_5 -> V_50 . V_54 =
F_39 ( V_52 ,
sizeof( * V_5 -> V_50 . V_54 ) , V_66 ) ;
if ( ! V_5 -> V_50 . V_54 )
goto V_92;
V_5 -> V_8 . V_9 . V_15 =
F_40 ( V_12 * V_13 ) ;
if ( ! V_5 -> V_8 . V_9 . V_15 )
goto V_93;
V_5 -> V_8 . V_18 = V_94 ;
return 0 ;
V_93:
F_31 ( V_5 -> V_50 . V_54 ) ;
V_92:
F_31 ( V_5 -> V_50 . V_51 . V_15 ) ;
return - V_67 ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_5 )
return;
F_31 ( V_5 -> V_50 . V_51 . V_15 ) ;
F_31 ( V_5 -> V_50 . V_54 ) ;
F_42 ( V_5 -> V_8 . V_9 . V_15 ) ;
}
