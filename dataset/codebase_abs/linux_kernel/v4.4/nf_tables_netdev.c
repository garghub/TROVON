static inline void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 , V_9 ;
T_1 V_10 , V_11 ;
F_2 ( V_2 , V_4 , V_6 ) ;
V_8 = F_3 ( V_4 , F_4 ( V_4 ) , sizeof( * V_8 ) ,
& V_9 ) ;
if ( ! V_8 )
return;
V_8 = F_5 ( V_4 ) ;
if ( V_8 -> V_12 < 5 || V_8 -> V_13 != 4 )
return;
V_10 = F_6 ( V_8 -> V_14 ) ;
V_11 = V_8 -> V_12 * 4 ;
if ( V_4 -> V_10 < V_10 )
return;
else if ( V_10 < V_11 )
return;
V_2 -> V_15 = V_8 -> V_16 ;
V_2 -> V_17 . V_11 = V_11 ;
V_2 -> V_17 . V_18 = F_6 ( V_8 -> V_19 ) & V_20 ;
}
static inline void
F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
#if F_8 ( V_21 )
struct V_22 * V_23 , V_24 ;
unsigned int V_11 = 0 ;
unsigned short V_19 ;
int V_25 ;
T_1 V_26 ;
V_23 = F_3 ( V_4 , F_4 ( V_4 ) , sizeof( * V_23 ) ,
& V_24 ) ;
if ( ! V_23 )
return;
if ( V_23 -> V_13 != 6 )
return;
V_26 = F_6 ( V_23 -> V_27 ) ;
if ( V_26 + sizeof( * V_23 ) > V_4 -> V_10 )
return;
V_25 = F_9 ( V_2 -> V_4 , & V_11 , - 1 , & V_19 , NULL ) ;
if ( V_25 < 0 )
return;
V_2 -> V_15 = V_25 ;
V_2 -> V_17 . V_11 = V_11 ;
V_2 -> V_17 . V_18 = V_19 ;
#endif
}
static inline void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
F_2 ( V_2 , V_4 , V_6 ) ;
F_7 ( V_2 , V_4 , V_6 ) ;
}
static unsigned int
F_11 ( void * V_28 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_1 V_2 ;
switch ( V_4 -> V_16 ) {
case F_12 ( V_29 ) :
F_1 ( & V_2 , V_4 , V_6 ) ;
break;
case F_12 ( V_30 ) :
F_10 ( & V_2 , V_4 , V_6 ) ;
break;
default:
F_2 ( & V_2 , V_4 , V_6 ) ;
break;
}
return F_13 ( & V_2 , V_28 ) ;
}
static int F_14 ( struct V_31 * V_31 )
{
V_31 -> V_32 . V_33 = F_15 ( sizeof( struct V_34 ) , V_35 ) ;
if ( V_31 -> V_32 . V_33 == NULL )
return - V_36 ;
memcpy ( V_31 -> V_32 . V_33 , & V_37 , sizeof( V_37 ) ) ;
if ( F_16 ( V_31 , V_31 -> V_32 . V_33 ) < 0 )
goto V_38;
return 0 ;
V_38:
F_17 ( V_31 -> V_32 . V_33 ) ;
return - V_36 ;
}
static void F_18 ( struct V_31 * V_31 )
{
F_19 ( V_31 -> V_32 . V_33 ) ;
F_17 ( V_31 -> V_32 . V_33 ) ;
}
static void F_20 ( unsigned long V_39 , struct V_34 * V_40 ,
struct V_41 * V_42 , struct V_43 * V_44 ,
struct V_45 * V_46 )
{
switch ( V_39 ) {
case V_47 :
if ( strcmp ( V_46 -> V_48 , V_42 -> V_49 ) != 0 )
return;
F_21 ( ! ( V_46 -> V_50 & V_51 ) ) ;
F_22 ( V_42 ) ;
V_46 -> V_52 [ 0 ] . V_42 = V_42 ;
V_46 -> V_50 &= ~ V_51 ;
if ( ! ( V_44 -> V_50 & V_53 ) )
F_23 ( V_46 , V_40 -> V_54 ) ;
break;
case V_55 :
if ( strcmp ( V_46 -> V_48 , V_42 -> V_49 ) != 0 )
return;
F_21 ( V_46 -> V_50 & V_51 ) ;
if ( ! ( V_44 -> V_50 & V_53 ) )
F_24 ( V_46 , V_40 -> V_54 ) ;
F_25 ( V_46 -> V_52 [ 0 ] . V_42 ) ;
V_46 -> V_52 [ 0 ] . V_42 = NULL ;
V_46 -> V_50 |= V_51 ;
break;
case V_56 :
if ( V_42 -> V_57 != V_46 -> V_52 [ 0 ] . V_42 -> V_57 )
return;
strncpy ( V_46 -> V_48 , V_42 -> V_49 , V_58 ) ;
break;
}
}
static int F_26 ( struct V_59 * V_60 ,
unsigned long V_39 , void * V_61 )
{
struct V_41 * V_42 = F_27 ( V_61 ) ;
struct V_34 * V_40 ;
struct V_43 * V_44 ;
struct V_62 * V_63 ;
F_28 ( V_64 ) ;
F_29 (afi, &dev_net(dev)->nft.af_info, list) {
if ( V_40 -> V_65 != V_66 )
continue;
F_29 (table, &afi->tables, list) {
F_29 (chain, &table->chains, list) {
if ( ! ( V_63 -> V_50 & V_67 ) )
continue;
F_20 ( V_39 , V_40 , V_42 , V_44 ,
V_45 ( V_63 ) ) ;
}
}
}
F_30 ( V_64 ) ;
return V_68 ;
}
static int T_2 F_31 ( void )
{
int V_69 ;
F_32 ( & V_70 ) ;
V_69 = F_33 ( & V_71 ) ;
if ( V_69 < 0 )
F_34 ( & V_70 ) ;
F_35 ( & V_72 ) ;
return V_69 ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_72 ) ;
F_38 ( & V_71 ) ;
F_34 ( & V_70 ) ;
}
