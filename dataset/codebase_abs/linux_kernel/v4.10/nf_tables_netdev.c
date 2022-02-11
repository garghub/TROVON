static unsigned int
F_1 ( void * V_1 , struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_6 V_7 ;
switch ( V_3 -> V_8 ) {
case F_2 ( V_9 ) :
F_3 ( & V_7 , V_3 , V_5 ) ;
break;
case F_2 ( V_10 ) :
F_4 ( & V_7 , V_3 , V_5 ) ;
break;
default:
F_5 ( & V_7 , V_3 , V_5 ) ;
break;
}
return F_6 ( & V_7 , V_1 ) ;
}
static int F_7 ( struct V_11 * V_11 )
{
V_11 -> V_12 . V_13 = F_8 ( sizeof( struct V_14 ) , V_15 ) ;
if ( V_11 -> V_12 . V_13 == NULL )
return - V_16 ;
memcpy ( V_11 -> V_12 . V_13 , & V_17 , sizeof( V_17 ) ) ;
if ( F_9 ( V_11 , V_11 -> V_12 . V_13 ) < 0 )
goto V_18;
return 0 ;
V_18:
F_10 ( V_11 -> V_12 . V_13 ) ;
return - V_16 ;
}
static void F_11 ( struct V_11 * V_11 )
{
F_12 ( V_11 , V_11 -> V_12 . V_13 ) ;
F_10 ( V_11 -> V_12 . V_13 ) ;
}
static void F_13 ( unsigned long V_19 , struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = V_24 ( V_23 -> V_26 ) ;
switch ( V_19 ) {
case V_27 :
if ( strcmp ( V_25 -> V_28 , V_21 -> V_29 ) != 0 )
return;
F_14 ( V_23 ) ;
break;
case V_30 :
if ( V_21 -> V_31 != V_25 -> V_32 [ 0 ] . V_21 -> V_31 )
return;
strncpy ( V_25 -> V_28 , V_21 -> V_29 , V_33 ) ;
break;
}
}
static int F_15 ( struct V_34 * V_35 ,
unsigned long V_19 , void * V_36 )
{
struct V_20 * V_21 = F_16 ( V_36 ) ;
struct V_14 * V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_26 , * V_41 ;
struct V_22 V_23 = {
. V_11 = F_17 ( V_21 ) ,
} ;
if ( V_19 != V_27 &&
V_19 != V_30 )
return V_42 ;
F_18 ( V_43 ) ;
F_19 (afi, &dev_net(dev)->nft.af_info, list) {
V_23 . V_37 = V_37 ;
if ( V_37 -> V_44 != V_45 )
continue;
F_19 (table, &afi->tables, list) {
V_23 . V_39 = V_39 ;
F_20 (chain, nr, &table->chains, list) {
if ( ! ( V_26 -> V_46 & V_47 ) )
continue;
V_23 . V_26 = V_26 ;
F_13 ( V_19 , V_21 , & V_23 ) ;
}
}
}
F_21 ( V_43 ) ;
return V_42 ;
}
static int T_1 F_22 ( void )
{
int V_48 ;
V_48 = F_23 ( & V_49 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_24 ( & V_50 ) ;
if ( V_48 )
goto V_51;
V_48 = F_25 ( & V_52 ) ;
if ( V_48 )
goto V_53;
return 0 ;
V_53:
F_26 ( & V_50 ) ;
V_51:
F_27 ( & V_49 ) ;
return V_48 ;
}
static void T_2 F_28 ( void )
{
F_29 ( & V_52 ) ;
F_26 ( & V_50 ) ;
F_27 ( & V_49 ) ;
}
