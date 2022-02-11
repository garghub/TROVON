static inline void
F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
struct V_9 * V_10 , V_11 ;
T_1 V_12 , V_13 ;
F_2 ( V_2 , V_4 , V_6 , V_8 ) ;
V_10 = F_3 ( V_6 , F_4 ( V_6 ) , sizeof( * V_10 ) ,
& V_11 ) ;
if ( ! V_10 )
return;
V_10 = F_5 ( V_6 ) ;
if ( V_10 -> V_14 < 5 || V_10 -> V_15 != 4 )
return;
V_12 = F_6 ( V_10 -> V_16 ) ;
V_13 = V_10 -> V_14 * 4 ;
if ( V_6 -> V_12 < V_12 )
return;
else if ( V_12 < V_13 )
return;
V_2 -> V_17 = V_10 -> V_18 ;
V_2 -> V_19 . V_13 = V_13 ;
V_2 -> V_19 . V_20 = F_6 ( V_10 -> V_21 ) & V_22 ;
}
static inline void
F_7 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
#if F_8 ( V_23 )
struct V_24 * V_25 , V_26 ;
unsigned int V_13 = 0 ;
unsigned short V_21 ;
int V_27 ;
T_1 V_28 ;
V_25 = F_3 ( V_6 , F_4 ( V_6 ) , sizeof( * V_25 ) ,
& V_26 ) ;
if ( ! V_25 )
return;
if ( V_25 -> V_15 != 6 )
return;
V_28 = F_6 ( V_25 -> V_29 ) ;
if ( V_28 + sizeof( * V_25 ) > V_6 -> V_12 )
return;
V_27 = F_9 ( V_2 -> V_6 , & V_13 , - 1 , & V_21 , NULL ) ;
if ( V_27 < 0 )
return;
V_2 -> V_17 = V_27 ;
V_2 -> V_19 . V_13 = V_13 ;
V_2 -> V_19 . V_20 = V_21 ;
#endif
}
static inline void F_10 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
F_2 ( V_2 , V_4 , V_6 , V_8 ) ;
F_7 ( V_2 , V_4 , V_6 , V_8 ) ;
}
static unsigned int
F_11 ( const struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
struct V_1 V_2 ;
switch ( F_12 ( V_6 ) -> V_30 ) {
case F_13 ( V_31 ) :
F_1 ( & V_2 , V_4 , V_6 , V_8 ) ;
break;
case F_13 ( V_32 ) :
F_10 ( & V_2 , V_4 , V_6 , V_8 ) ;
break;
default:
F_2 ( & V_2 , V_4 , V_6 , V_8 ) ;
break;
}
return F_14 ( & V_2 , V_4 ) ;
}
static int F_15 ( struct V_33 * V_33 )
{
V_33 -> V_34 . V_35 = F_16 ( sizeof( struct V_36 ) , V_37 ) ;
if ( V_33 -> V_34 . V_35 == NULL )
return - V_38 ;
memcpy ( V_33 -> V_34 . V_35 , & V_39 , sizeof( V_39 ) ) ;
if ( F_17 ( V_33 , V_33 -> V_34 . V_35 ) < 0 )
goto V_40;
return 0 ;
V_40:
F_18 ( V_33 -> V_34 . V_35 ) ;
return - V_38 ;
}
static void F_19 ( struct V_33 * V_33 )
{
F_20 ( V_33 -> V_34 . V_35 ) ;
F_18 ( V_33 -> V_34 . V_35 ) ;
}
static void F_21 ( unsigned long V_41 , struct V_36 * V_42 ,
struct V_43 * V_44 , struct V_45 * V_46 ,
struct V_47 * V_48 )
{
switch ( V_41 ) {
case V_49 :
if ( strcmp ( V_48 -> V_50 , V_44 -> V_51 ) != 0 )
return;
F_22 ( ! ( V_48 -> V_52 & V_53 ) ) ;
F_23 ( V_44 ) ;
V_48 -> V_4 [ 0 ] . V_44 = V_44 ;
V_48 -> V_52 &= ~ V_53 ;
if ( ! ( V_46 -> V_52 & V_54 ) )
F_24 ( V_48 , V_42 -> V_55 ) ;
break;
case V_56 :
if ( strcmp ( V_48 -> V_50 , V_44 -> V_51 ) != 0 )
return;
F_22 ( V_48 -> V_52 & V_53 ) ;
if ( ! ( V_46 -> V_52 & V_54 ) )
F_25 ( V_48 , V_42 -> V_55 ) ;
F_26 ( V_48 -> V_4 [ 0 ] . V_44 ) ;
V_48 -> V_4 [ 0 ] . V_44 = NULL ;
V_48 -> V_52 |= V_53 ;
break;
case V_57 :
if ( V_44 -> V_58 != V_48 -> V_4 [ 0 ] . V_44 -> V_58 )
return;
strncpy ( V_48 -> V_50 , V_44 -> V_51 , V_59 ) ;
break;
}
}
static int F_27 ( struct V_60 * V_61 ,
unsigned long V_41 , void * V_62 )
{
struct V_43 * V_44 = F_28 ( V_62 ) ;
struct V_36 * V_42 ;
struct V_45 * V_46 ;
struct V_63 * V_64 ;
F_29 ( V_65 ) ;
F_30 (afi, &dev_net(dev)->nft.af_info, list) {
if ( V_42 -> V_66 != V_67 )
continue;
F_30 (table, &afi->tables, list) {
F_30 (chain, &table->chains, list) {
if ( ! ( V_64 -> V_52 & V_68 ) )
continue;
F_21 ( V_41 , V_42 , V_44 , V_46 ,
V_47 ( V_64 ) ) ;
}
}
}
F_31 ( V_65 ) ;
return V_69 ;
}
static int T_2 F_32 ( void )
{
int V_70 ;
F_33 ( & V_71 ) ;
V_70 = F_34 ( & V_72 ) ;
if ( V_70 < 0 )
F_35 ( & V_71 ) ;
F_36 ( & V_73 ) ;
return V_70 ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_73 ) ;
F_39 ( & V_72 ) ;
F_35 ( & V_71 ) ;
}
