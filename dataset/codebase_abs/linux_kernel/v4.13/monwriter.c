static int F_1 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
struct V_5 V_6 ;
int V_7 ;
strncpy ( V_6 . V_8 , L_1 , 7 ) ;
V_6 . V_9 = V_2 -> V_10 ;
V_6 . V_11 = V_2 -> V_12 ;
V_6 . V_13 = V_2 -> V_14 ;
V_6 . V_15 = V_2 -> V_16 ;
V_6 . V_17 = V_2 -> V_18 ;
V_7 = F_2 ( & V_6 , V_4 , ( void * ) V_3 , V_2 -> V_19 ) ;
if ( V_7 <= 0 )
return V_7 ;
F_3 ( L_2 , V_7 ) ;
if ( V_7 == 5 )
return - V_20 ;
return - V_21 ;
}
static struct V_22 * F_4 ( struct V_23 * V_24 ,
struct V_1 * V_25 )
{
struct V_22 * V_26 , * V_27 ;
F_5 (entry, next, &monpriv->list, list)
if ( ( V_26 -> V_28 . V_29 == V_25 -> V_29 ||
V_25 -> V_29 == V_30 ) &&
V_26 -> V_28 . V_10 == V_25 -> V_10 &&
V_26 -> V_28 . V_12 == V_25 -> V_12 &&
V_26 -> V_28 . V_14 == V_25 -> V_14 &&
V_26 -> V_28 . V_16 == V_25 -> V_16 &&
V_26 -> V_28 . V_18 == V_25 -> V_18 )
return V_26 ;
return NULL ;
}
static int F_6 ( struct V_23 * V_24 )
{
struct V_1 * V_25 = & V_24 -> V_28 ;
struct V_22 * V_31 ;
int V_7 = 0 ;
if ( V_25 -> V_19 > V_32 ||
V_25 -> V_29 > V_33 ||
V_25 -> V_34 != sizeof( struct V_1 ) )
return - V_21 ;
V_31 = NULL ;
if ( V_25 -> V_29 != V_35 )
V_31 = F_4 ( V_24 , V_25 ) ;
if ( V_31 ) {
if ( V_25 -> V_29 == V_30 ) {
V_25 -> V_19 = V_31 -> V_28 . V_19 ;
V_7 = F_1 ( V_25 , V_31 -> V_36 ,
V_37 ) ;
F_7 ( & V_31 -> V_38 ) ;
V_39 -- ;
F_8 ( V_31 -> V_36 ) ;
F_8 ( V_31 ) ;
V_31 = NULL ;
}
} else if ( V_25 -> V_29 != V_30 ) {
if ( V_39 >= V_40 )
return - V_41 ;
V_31 = F_9 ( sizeof( struct V_22 ) , V_42 ) ;
if ( ! V_31 )
return - V_43 ;
V_31 -> V_36 = F_9 ( V_25 -> V_19 ,
V_42 | V_44 ) ;
if ( ! V_31 -> V_36 ) {
F_8 ( V_31 ) ;
return - V_43 ;
}
V_31 -> V_28 = * V_25 ;
F_10 ( & V_31 -> V_38 , & V_24 -> V_38 ) ;
if ( V_25 -> V_29 != V_35 )
V_39 ++ ;
}
V_24 -> V_45 = V_31 ;
return V_7 ;
}
static int F_11 ( struct V_23 * V_24 )
{
struct V_1 * V_25 = & V_24 -> V_28 ;
struct V_22 * V_31 = V_24 -> V_45 ;
int V_7 = 0 ;
switch ( V_25 -> V_29 ) {
case V_46 :
if ( ! V_31 -> V_47 ) {
V_7 = F_1 ( V_25 , V_31 -> V_36 ,
V_48 ) ;
V_31 -> V_47 = 1 ;
}
break;
case V_33 :
if ( ! V_31 -> V_47 ) {
V_7 = F_1 ( V_25 , V_31 -> V_36 ,
V_49 ) ;
V_31 -> V_47 = 1 ;
}
break;
case V_35 :
V_7 = F_1 ( V_25 , V_31 -> V_36 ,
V_50 ) ;
F_7 ( & V_24 -> V_45 -> V_38 ) ;
F_8 ( V_24 -> V_45 -> V_36 ) ;
F_8 ( V_24 -> V_45 ) ;
V_24 -> V_45 = NULL ;
break;
default:
F_12 () ;
}
return V_7 ;
}
static int F_13 ( struct V_51 * V_51 , struct V_52 * V_53 )
{
struct V_23 * V_24 ;
V_24 = F_9 ( sizeof( struct V_23 ) , V_42 ) ;
if ( ! V_24 )
return - V_43 ;
F_14 ( & V_24 -> V_38 ) ;
V_24 -> V_54 = sizeof( V_24 -> V_28 ) ;
F_15 ( & V_24 -> V_55 ) ;
V_53 -> V_56 = V_24 ;
F_10 ( & V_24 -> V_57 , & V_58 ) ;
return F_16 ( V_51 , V_53 ) ;
}
static int F_17 ( struct V_51 * V_51 , struct V_52 * V_53 )
{
struct V_23 * V_24 = V_53 -> V_56 ;
struct V_22 * V_26 , * V_27 ;
F_5 (entry, next, &monpriv->list, list) {
if ( V_26 -> V_28 . V_29 != V_35 )
F_1 ( & V_26 -> V_28 , V_26 -> V_36 ,
V_37 ) ;
V_39 -- ;
F_7 ( & V_26 -> V_38 ) ;
F_8 ( V_26 -> V_36 ) ;
F_8 ( V_26 ) ;
}
F_7 ( & V_24 -> V_57 ) ;
F_8 ( V_24 ) ;
return 0 ;
}
static T_1 F_18 ( struct V_52 * V_53 , const char T_2 * V_36 ,
T_3 V_59 , T_4 * V_60 )
{
struct V_23 * V_24 = V_53 -> V_56 ;
T_3 V_61 , V_62 ;
void * V_63 ;
int V_7 ;
F_19 ( & V_24 -> V_55 ) ;
for ( V_62 = 0 ; V_62 < V_59 ; ) {
if ( V_24 -> V_54 ) {
V_61 = F_20 ( V_59 - V_62 , V_24 -> V_54 ) ;
V_63 = ( char * ) & V_24 -> V_28 +
sizeof( V_24 -> V_28 ) - V_24 -> V_54 ;
if ( F_21 ( V_63 , V_36 + V_62 , V_61 ) ) {
V_7 = - V_64 ;
goto V_65;
}
V_24 -> V_54 -= V_61 ;
V_62 += V_61 ;
if ( V_24 -> V_54 > 0 )
continue;
V_7 = F_6 ( V_24 ) ;
if ( V_7 )
goto V_65;
V_24 -> V_66 = V_24 -> V_45 ?
V_24 -> V_45 -> V_28 . V_19 : 0 ;
}
if ( V_24 -> V_66 ) {
V_61 = F_20 ( V_59 - V_62 , V_24 -> V_66 ) ;
V_63 = V_24 -> V_45 -> V_36 +
V_24 -> V_28 . V_19 - V_24 -> V_66 ;
if ( F_21 ( V_63 , V_36 + V_62 , V_61 ) ) {
V_7 = - V_64 ;
goto V_65;
}
V_24 -> V_66 -= V_61 ;
V_62 += V_61 ;
if ( V_24 -> V_66 > 0 )
continue;
V_7 = F_11 ( V_24 ) ;
if ( V_7 )
goto V_65;
}
V_24 -> V_54 = sizeof( V_24 -> V_28 ) ;
}
F_22 ( & V_24 -> V_55 ) ;
return V_62 ;
V_65:
V_24 -> V_66 = 0 ;
V_24 -> V_54 = sizeof( struct V_1 ) ;
F_22 ( & V_24 -> V_55 ) ;
return V_7 ;
}
static int F_23 ( struct V_67 * V_68 )
{
struct V_23 * V_24 ;
struct V_22 * V_31 ;
F_24 (monpriv, &mon_priv_list, priv_list) {
F_24 (monbuf, &monpriv->list, list) {
if ( V_31 -> V_28 . V_29 != V_35 )
F_1 ( & V_31 -> V_28 , V_31 -> V_36 ,
V_37 ) ;
}
}
return 0 ;
}
static int F_25 ( struct V_67 * V_68 )
{
struct V_23 * V_24 ;
struct V_22 * V_31 ;
F_24 (monpriv, &mon_priv_list, priv_list) {
F_24 (monbuf, &monpriv->list, list) {
if ( V_31 -> V_28 . V_29 == V_46 )
F_1 ( & V_31 -> V_28 , V_31 -> V_36 ,
V_48 ) ;
if ( V_31 -> V_28 . V_29 == V_33 )
F_1 ( & V_31 -> V_28 , V_31 -> V_36 ,
V_49 ) ;
}
}
return 0 ;
}
static int F_26 ( struct V_67 * V_68 )
{
return F_25 ( V_68 ) ;
}
static int T_5 F_27 ( void )
{
int V_7 ;
if ( ! V_69 )
return - V_70 ;
V_7 = F_28 ( & V_71 ) ;
if ( V_7 )
return V_7 ;
V_72 = F_29 ( L_3 , - 1 , NULL ,
0 ) ;
if ( F_30 ( V_72 ) ) {
V_7 = F_31 ( V_72 ) ;
goto V_73;
}
V_7 = F_32 ( & V_74 ) ;
if ( V_7 )
goto V_75;
return 0 ;
V_75:
F_33 ( V_72 ) ;
V_73:
F_34 ( & V_71 ) ;
return V_7 ;
}
static void T_6 F_35 ( void )
{
F_36 ( & V_74 ) ;
F_33 ( V_72 ) ;
F_34 ( & V_71 ) ;
}
