static struct V_1 * F_1 ( struct V_2 * V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_1 * V_9 ;
unsigned long V_10 ;
V_4 = sizeof( struct V_5 ) ;
V_4 += V_11 * sizeof( struct V_12 ) ;
V_4 += sizeof( struct V_7 ) ;
V_9 = F_2 ( V_4 , V_13 ) ;
if ( V_9 ) {
F_3 ( V_9 , 0 , 0 , & V_14 ,
0 , V_15 ) ;
V_8 = F_4 ( V_9 , V_16 ,
sizeof( struct V_5 ) ) ;
V_6 = F_5 ( V_8 ) ;
memset ( V_6 , 0 , V_4 ) ;
} else {
F_6 ( & V_3 -> V_17 , V_18 + V_19 / 10 ) ;
}
F_7 ( & V_3 -> V_20 , V_10 ) ;
F_8 ( V_3 -> V_9 , V_9 ) ;
F_9 ( & V_3 -> V_20 , V_10 ) ;
return V_9 ;
}
static void F_10 ( struct V_21 * V_22 )
{
struct V_1 * V_9 ;
struct V_2 * V_3 ;
V_3 = F_11 ( V_22 , struct V_2 , V_23 ) ;
V_9 = F_1 ( V_3 ) ;
if ( V_9 )
F_12 ( V_9 , 0 , V_24 , V_13 ) ;
}
static void F_13 ( unsigned long V_25 )
{
struct V_2 * V_3 = (struct V_2 * ) V_25 ;
F_14 ( & V_3 -> V_23 ) ;
}
static void F_15 ( struct V_1 * V_9 , void * V_26 )
{
struct V_5 * V_6 ;
struct V_27 * V_28 ;
struct V_7 * V_8 ;
int V_29 ;
struct V_1 * V_30 ;
struct V_2 * V_3 ;
unsigned long V_10 ;
F_16 ( V_10 ) ;
V_3 = & F_17 ( V_31 ) ;
F_18 ( & V_3 -> V_20 ) ;
V_30 = V_3 -> V_9 ;
if ( ! V_30 )
goto V_32;
V_28 = (struct V_27 * ) V_30 -> V_3 ;
V_8 = F_19 ( F_20 ( V_28 ) ) ;
V_6 = F_5 ( V_8 ) ;
for ( V_29 = 0 ; V_29 < V_6 -> V_33 ; V_29 ++ ) {
if ( ! memcmp ( & V_26 , V_6 -> V_34 [ V_29 ] . V_35 , sizeof( void * ) ) ) {
V_6 -> V_34 [ V_29 ] . V_36 ++ ;
goto V_32;
}
}
if ( V_6 -> V_33 == V_11 )
goto V_32;
F_21 ( V_30 , sizeof( struct V_12 ) ) ;
V_8 -> V_37 += F_22 ( sizeof( struct V_12 ) ) ;
memcpy ( V_6 -> V_34 [ V_6 -> V_33 ] . V_35 , & V_26 , sizeof( void * ) ) ;
V_6 -> V_34 [ V_6 -> V_33 ] . V_36 = 1 ;
V_6 -> V_33 ++ ;
if ( ! F_23 ( & V_3 -> V_17 ) ) {
V_3 -> V_17 . V_38 = V_18 + V_39 * V_19 ;
F_24 ( & V_3 -> V_17 ) ;
}
V_32:
F_9 ( & V_3 -> V_20 , V_10 ) ;
}
static void F_25 ( void * V_40 , struct V_1 * V_9 , void * V_26 )
{
F_15 ( V_9 , V_26 ) ;
}
static void F_26 ( void * V_40 , struct V_41 * V_42 )
{
struct V_43 * V_44 ;
if ( ! V_42 -> V_45 )
return;
F_27 () ;
F_28 (new_stat, &hw_stats_list, list) {
if ( ( V_44 -> V_45 == V_42 -> V_45 ) &&
( F_29 ( V_18 , V_44 -> V_46 + V_47 ) ) &&
( V_42 -> V_45 -> V_48 . V_49 != V_44 -> V_50 ) ) {
F_15 ( NULL , NULL ) ;
V_44 -> V_50 = V_42 -> V_45 -> V_48 . V_49 ;
V_44 -> V_46 = V_18 ;
break;
}
}
F_30 () ;
}
static int F_31 ( int V_51 )
{
int V_52 = 0 ;
struct V_43 * V_44 = NULL ;
struct V_43 * V_53 ;
F_32 ( & V_54 ) ;
if ( V_51 == V_55 ) {
V_52 = - V_56 ;
goto V_57;
}
switch ( V_51 ) {
case V_58 :
if ( ! F_33 ( V_59 ) ) {
V_52 = - V_60 ;
break;
}
V_52 |= F_34 ( F_25 , NULL ) ;
V_52 |= F_35 ( F_26 , NULL ) ;
break;
case V_61 :
V_52 |= F_36 ( F_25 , NULL ) ;
V_52 |= F_37 ( F_26 , NULL ) ;
F_38 () ;
F_39 (new_stat, temp, &hw_stats_list, list) {
if ( V_44 -> V_45 == NULL ) {
F_40 ( & V_44 -> V_62 ) ;
F_41 ( V_44 , V_63 ) ;
}
}
F_42 ( V_59 ) ;
break;
default:
V_52 = 1 ;
break;
}
if ( ! V_52 )
V_55 = V_51 ;
else
V_52 = - V_64 ;
V_57:
F_43 ( & V_54 ) ;
return V_52 ;
}
static int F_44 ( struct V_1 * V_9 ,
struct V_65 * V_66 )
{
return - V_67 ;
}
static int F_45 ( struct V_1 * V_9 ,
struct V_65 * V_66 )
{
switch ( V_66 -> V_68 -> V_69 ) {
case V_70 :
return F_31 ( V_58 ) ;
break;
case V_71 :
return F_31 ( V_61 ) ;
break;
}
return - V_67 ;
}
static int F_46 ( struct V_72 * V_73 ,
unsigned long V_74 , void * V_75 )
{
struct V_76 * V_45 = F_47 ( V_75 ) ;
struct V_43 * V_44 = NULL ;
struct V_43 * V_77 ;
switch ( V_74 ) {
case V_78 :
V_44 = F_48 ( sizeof( struct V_43 ) , V_13 ) ;
if ( ! V_44 )
goto V_32;
V_44 -> V_45 = V_45 ;
V_44 -> V_46 = V_18 ;
F_32 ( & V_54 ) ;
F_49 ( & V_44 -> V_62 , & V_79 ) ;
F_43 ( & V_54 ) ;
break;
case V_80 :
F_32 ( & V_54 ) ;
F_39 (new_stat, tmp, &hw_stats_list, list) {
if ( V_44 -> V_45 == V_45 ) {
V_44 -> V_45 = NULL ;
if ( V_55 == V_61 ) {
F_40 ( & V_44 -> V_62 ) ;
F_41 ( V_44 , V_63 ) ;
break;
}
}
}
F_43 ( & V_54 ) ;
break;
}
V_32:
return V_81 ;
}
static int T_2 F_50 ( void )
{
struct V_2 * V_3 ;
int V_82 , V_52 ;
F_51 ( L_1 ) ;
if ( sizeof( void * ) > 8 ) {
F_52 ( L_2 ) ;
return - V_83 ;
}
V_52 = F_53 ( & V_14 ,
V_84 ,
F_54 ( V_84 ) ) ;
if ( V_52 ) {
F_52 ( L_3 ) ;
return V_52 ;
}
V_52 = F_55 ( & V_85 ) ;
if ( V_52 < 0 ) {
F_56 ( L_4 ) ;
goto V_86;
}
V_52 = 0 ;
F_57 (cpu) {
V_3 = & F_58 ( V_31 , V_82 ) ;
F_59 ( & V_3 -> V_23 , F_10 ) ;
F_60 ( & V_3 -> V_17 ) ;
V_3 -> V_17 . V_3 = ( unsigned long ) V_3 ;
V_3 -> V_17 . V_87 = F_13 ;
F_61 ( & V_3 -> V_20 ) ;
F_1 ( V_3 ) ;
}
goto V_32;
V_86:
F_62 ( & V_14 ) ;
V_32:
return V_52 ;
}
static void F_63 ( void )
{
struct V_2 * V_3 ;
int V_82 ;
F_64 ( F_65 ( & V_85 ) ) ;
F_57 (cpu) {
V_3 = & F_58 ( V_31 , V_82 ) ;
F_66 ( & V_3 -> V_17 ) ;
F_67 ( & V_3 -> V_23 ) ;
F_68 ( V_3 -> V_9 ) ;
}
F_64 ( F_62 ( & V_14 ) ) ;
}
