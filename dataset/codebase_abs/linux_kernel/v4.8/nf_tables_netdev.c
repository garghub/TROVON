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
if ( V_8 -> V_12 < 5 || V_8 -> V_13 != 4 )
return;
V_10 = F_5 ( V_8 -> V_14 ) ;
V_11 = V_8 -> V_12 * 4 ;
if ( V_4 -> V_10 < V_10 )
return;
else if ( V_10 < V_11 )
return;
V_2 -> V_15 = V_8 -> V_16 ;
V_2 -> V_17 . V_11 = V_11 ;
V_2 -> V_17 . V_18 = F_5 ( V_8 -> V_19 ) & V_20 ;
}
static inline void
F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
#if F_7 ( V_21 )
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
V_26 = F_5 ( V_23 -> V_27 ) ;
if ( V_26 + sizeof( * V_23 ) > V_4 -> V_10 )
return;
V_25 = F_8 ( V_2 -> V_4 , & V_11 , - 1 , & V_19 , NULL ) ;
if ( V_25 < 0 )
return;
V_2 -> V_15 = V_25 ;
V_2 -> V_17 . V_11 = V_11 ;
V_2 -> V_17 . V_18 = V_19 ;
#endif
}
static inline void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
F_2 ( V_2 , V_4 , V_6 ) ;
F_6 ( V_2 , V_4 , V_6 ) ;
}
static unsigned int
F_10 ( void * V_28 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_1 V_2 ;
switch ( V_4 -> V_16 ) {
case F_11 ( V_29 ) :
F_1 ( & V_2 , V_4 , V_6 ) ;
break;
case F_11 ( V_30 ) :
F_9 ( & V_2 , V_4 , V_6 ) ;
break;
default:
F_2 ( & V_2 , V_4 , V_6 ) ;
break;
}
return F_12 ( & V_2 , V_28 ) ;
}
static int F_13 ( struct V_31 * V_31 )
{
V_31 -> V_32 . V_33 = F_14 ( sizeof( struct V_34 ) , V_35 ) ;
if ( V_31 -> V_32 . V_33 == NULL )
return - V_36 ;
memcpy ( V_31 -> V_32 . V_33 , & V_37 , sizeof( V_37 ) ) ;
if ( F_15 ( V_31 , V_31 -> V_32 . V_33 ) < 0 )
goto V_38;
return 0 ;
V_38:
F_16 ( V_31 -> V_32 . V_33 ) ;
return - V_36 ;
}
static void F_17 ( struct V_31 * V_31 )
{
F_18 ( V_31 , V_31 -> V_32 . V_33 ) ;
F_16 ( V_31 -> V_32 . V_33 ) ;
}
static void F_19 ( unsigned long V_39 , struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_44 ( V_43 -> V_46 ) ;
switch ( V_39 ) {
case V_47 :
if ( strcmp ( V_45 -> V_48 , V_41 -> V_49 ) != 0 )
return;
F_20 ( V_43 ) ;
break;
case V_50 :
if ( V_41 -> V_51 != V_45 -> V_52 [ 0 ] . V_41 -> V_51 )
return;
strncpy ( V_45 -> V_48 , V_41 -> V_49 , V_53 ) ;
break;
}
}
static int F_21 ( struct V_54 * V_55 ,
unsigned long V_39 , void * V_56 )
{
struct V_40 * V_41 = F_22 ( V_56 ) ;
struct V_34 * V_57 ;
struct V_58 * V_59 ;
struct V_60 * V_46 , * V_61 ;
struct V_42 V_43 = {
. V_31 = F_23 ( V_41 ) ,
} ;
if ( V_39 != V_47 &&
V_39 != V_50 )
return V_62 ;
F_24 ( V_63 ) ;
F_25 (afi, &dev_net(dev)->nft.af_info, list) {
V_43 . V_57 = V_57 ;
if ( V_57 -> V_64 != V_65 )
continue;
F_25 (table, &afi->tables, list) {
V_43 . V_59 = V_59 ;
F_26 (chain, nr, &table->chains, list) {
if ( ! ( V_46 -> V_66 & V_67 ) )
continue;
V_43 . V_46 = V_46 ;
F_19 ( V_39 , V_41 , & V_43 ) ;
}
}
}
F_27 ( V_63 ) ;
return V_62 ;
}
static int T_2 F_28 ( void )
{
int V_68 ;
F_29 ( & V_69 ) ;
V_68 = F_30 ( & V_70 ) ;
if ( V_68 < 0 ) {
F_31 ( & V_69 ) ;
return V_68 ;
}
F_32 ( & V_71 ) ;
return 0 ;
}
static void T_3 F_33 ( void )
{
F_34 ( & V_71 ) ;
F_35 ( & V_70 ) ;
F_31 ( & V_69 ) ;
}
