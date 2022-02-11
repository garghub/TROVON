static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_3 = sizeof( struct V_4 ) ;
V_3 += V_8 * sizeof( struct V_9 ) ;
V_3 += sizeof( struct V_6 ) ;
V_2 -> V_10 = F_2 ( V_3 , V_11 ) ;
F_3 ( V_2 -> V_10 , 0 , 0 , & V_12 ,
0 , V_13 ) ;
V_7 = F_4 ( V_2 -> V_10 , V_14 , sizeof( struct V_4 ) ) ;
V_5 = F_5 ( V_7 ) ;
memset ( V_5 , 0 , V_3 ) ;
F_6 ( & V_2 -> V_15 , V_8 ) ;
}
static void F_7 ( struct V_16 * V_17 )
{
struct V_18 * V_10 ;
struct V_1 * V_2 = & F_8 ( V_19 ) ;
V_10 = V_2 -> V_10 ;
F_1 ( V_2 ) ;
F_9 ( V_10 , 0 , V_20 , V_11 ) ;
}
static void F_10 ( unsigned long V_17 )
{
struct V_1 * V_2 = & F_8 ( V_19 ) ;
F_11 ( & V_2 -> V_21 ) ;
}
static void F_12 ( struct V_18 * V_10 , void * V_22 )
{
struct V_4 * V_5 ;
struct V_23 * V_24 ;
struct V_6 * V_7 ;
int V_25 ;
struct V_1 * V_2 = & F_8 ( V_19 ) ;
if ( ! F_13 ( & V_2 -> V_15 , - 1 , 0 ) ) {
goto V_26;
}
V_24 = (struct V_23 * ) V_2 -> V_10 -> V_2 ;
V_7 = F_14 ( F_15 ( V_24 ) ) ;
V_5 = F_5 ( V_7 ) ;
for ( V_25 = 0 ; V_25 < V_5 -> V_27 ; V_25 ++ ) {
if ( ! memcmp ( & V_22 , V_5 -> V_28 [ V_25 ] . V_29 , sizeof( void * ) ) ) {
V_5 -> V_28 [ V_25 ] . V_30 ++ ;
goto V_26;
}
}
F_16 ( V_2 -> V_10 , sizeof( struct V_9 ) ) ;
V_7 -> V_31 += F_17 ( sizeof( struct V_9 ) ) ;
memcpy ( V_5 -> V_28 [ V_5 -> V_27 ] . V_29 , & V_22 , sizeof( void * ) ) ;
V_5 -> V_28 [ V_5 -> V_27 ] . V_30 = 1 ;
V_5 -> V_27 ++ ;
if ( ! F_18 ( & V_2 -> V_32 ) ) {
V_2 -> V_32 . V_33 = V_34 + V_35 * V_36 ;
F_19 ( & V_2 -> V_32 , F_20 () ) ;
}
V_26:
return;
}
static void F_21 ( void * V_37 , struct V_18 * V_10 , void * V_22 )
{
F_12 ( V_10 , V_22 ) ;
}
static void F_22 ( void * V_37 , struct V_38 * V_39 )
{
struct V_40 * V_41 ;
if ( ! V_39 -> V_42 )
return;
F_23 () ;
F_24 (new_stat, &hw_stats_list, list) {
if ( ( V_41 -> V_42 == V_39 -> V_42 ) &&
( F_25 ( V_34 , V_41 -> V_43 + V_44 ) ) &&
( V_39 -> V_42 -> V_45 . V_46 != V_41 -> V_47 ) ) {
F_12 ( NULL , NULL ) ;
V_41 -> V_47 = V_39 -> V_42 -> V_45 . V_46 ;
V_41 -> V_43 = V_34 ;
break;
}
}
F_26 () ;
}
static int F_27 ( int V_48 )
{
int V_49 = 0 ;
struct V_40 * V_41 = NULL ;
struct V_40 * V_50 ;
F_28 ( & V_51 ) ;
if ( V_48 == V_52 ) {
V_49 = - V_53 ;
goto V_54;
}
switch ( V_48 ) {
case V_55 :
V_49 |= F_29 ( F_21 , NULL ) ;
V_49 |= F_30 ( F_22 , NULL ) ;
break;
case V_56 :
V_49 |= F_31 ( F_21 , NULL ) ;
V_49 |= F_32 ( F_22 , NULL ) ;
F_33 () ;
F_34 (new_stat, temp, &hw_stats_list, list) {
if ( V_41 -> V_42 == NULL ) {
F_35 ( & V_41 -> V_57 ) ;
F_36 ( V_41 , V_58 ) ;
}
}
break;
default:
V_49 = 1 ;
break;
}
if ( ! V_49 )
V_52 = V_48 ;
else
V_49 = - V_59 ;
V_54:
F_37 ( & V_51 ) ;
return V_49 ;
}
static int F_38 ( struct V_18 * V_10 ,
struct V_60 * V_61 )
{
return - V_62 ;
}
static int F_39 ( struct V_18 * V_10 ,
struct V_60 * V_61 )
{
switch ( V_61 -> V_63 -> V_64 ) {
case V_65 :
return F_27 ( V_55 ) ;
break;
case V_66 :
return F_27 ( V_56 ) ;
break;
}
return - V_62 ;
}
static int F_40 ( struct V_67 * V_68 ,
unsigned long V_69 , void * V_70 )
{
struct V_71 * V_42 = V_70 ;
struct V_40 * V_41 = NULL ;
struct V_40 * V_72 ;
switch ( V_69 ) {
case V_73 :
V_41 = F_41 ( sizeof( struct V_40 ) , V_11 ) ;
if ( ! V_41 )
goto V_26;
V_41 -> V_42 = V_42 ;
V_41 -> V_43 = V_34 ;
F_28 ( & V_51 ) ;
F_42 ( & V_41 -> V_57 , & V_74 ) ;
F_37 ( & V_51 ) ;
break;
case V_75 :
F_28 ( & V_51 ) ;
F_34 (new_stat, tmp, &hw_stats_list, list) {
if ( V_41 -> V_42 == V_42 ) {
V_41 -> V_42 = NULL ;
if ( V_52 == V_56 ) {
F_35 ( & V_41 -> V_57 ) ;
F_36 ( V_41 , V_58 ) ;
break;
}
}
}
F_37 ( & V_51 ) ;
break;
}
V_26:
return V_76 ;
}
static int T_2 F_43 ( void )
{
struct V_1 * V_2 ;
int V_77 , V_49 ;
F_44 ( V_78 L_1 ) ;
if ( sizeof( void * ) > 8 ) {
F_44 ( V_79 L_2 ) ;
return - V_80 ;
}
V_49 = F_45 ( & V_12 ,
V_81 ,
F_46 ( V_81 ) ) ;
if ( V_49 ) {
F_44 ( V_79 L_3 ) ;
return V_49 ;
}
V_49 = F_47 ( & V_82 ) ;
if ( V_49 < 0 ) {
F_44 ( V_83 L_4 ) ;
goto V_84;
}
V_49 = 0 ;
F_48 (cpu) {
V_2 = & F_49 ( V_19 , V_77 ) ;
F_1 ( V_2 ) ;
F_50 ( & V_2 -> V_21 , F_7 ) ;
F_51 ( & V_2 -> V_32 ) ;
V_2 -> V_32 . V_2 = V_77 ;
V_2 -> V_32 . V_85 = F_10 ;
}
goto V_26;
V_84:
F_52 ( & V_12 ) ;
V_26:
return V_49 ;
}
