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
F_12 ( & V_14 , V_9 , 0 ,
0 , V_13 ) ;
}
static void F_13 ( unsigned long V_24 )
{
struct V_2 * V_3 = (struct V_2 * ) V_24 ;
F_14 ( & V_3 -> V_23 ) ;
}
static void F_15 ( struct V_1 * V_9 , void * V_25 )
{
struct V_5 * V_6 ;
struct V_26 * V_27 ;
struct V_7 * V_8 ;
int V_28 ;
struct V_1 * V_29 ;
struct V_2 * V_3 ;
unsigned long V_10 ;
F_16 ( V_10 ) ;
V_3 = & F_17 ( V_30 ) ;
F_18 ( & V_3 -> V_20 ) ;
V_29 = V_3 -> V_9 ;
if ( ! V_29 )
goto V_31;
V_27 = (struct V_26 * ) V_29 -> V_3 ;
V_8 = F_19 ( F_20 ( V_27 ) ) ;
V_6 = F_5 ( V_8 ) ;
for ( V_28 = 0 ; V_28 < V_6 -> V_32 ; V_28 ++ ) {
if ( ! memcmp ( & V_25 , V_6 -> V_33 [ V_28 ] . V_34 , sizeof( void * ) ) ) {
V_6 -> V_33 [ V_28 ] . V_35 ++ ;
goto V_31;
}
}
if ( V_6 -> V_32 == V_11 )
goto V_31;
F_21 ( V_29 , sizeof( struct V_12 ) ) ;
V_8 -> V_36 += F_22 ( sizeof( struct V_12 ) ) ;
memcpy ( V_6 -> V_33 [ V_6 -> V_32 ] . V_34 , & V_25 , sizeof( void * ) ) ;
V_6 -> V_33 [ V_6 -> V_32 ] . V_35 = 1 ;
V_6 -> V_32 ++ ;
if ( ! F_23 ( & V_3 -> V_17 ) ) {
V_3 -> V_17 . V_37 = V_18 + V_38 * V_19 ;
F_24 ( & V_3 -> V_17 ) ;
}
V_31:
F_9 ( & V_3 -> V_20 , V_10 ) ;
}
static void F_25 ( void * V_39 , struct V_1 * V_9 , void * V_25 )
{
F_15 ( V_9 , V_25 ) ;
}
static void F_26 ( void * V_39 , struct V_40 * V_41 )
{
struct V_42 * V_43 ;
if ( ! V_41 -> V_44 )
return;
F_27 () ;
F_28 (new_stat, &hw_stats_list, list) {
if ( ( V_43 -> V_44 == V_41 -> V_44 ) &&
( F_29 ( V_18 , V_43 -> V_45 + V_46 ) ) &&
( V_41 -> V_44 -> V_47 . V_48 != V_43 -> V_49 ) ) {
F_15 ( NULL , NULL ) ;
V_43 -> V_49 = V_41 -> V_44 -> V_47 . V_48 ;
V_43 -> V_45 = V_18 ;
break;
}
}
F_30 () ;
}
static int F_31 ( int V_50 )
{
int V_51 = 0 ;
struct V_42 * V_43 = NULL ;
struct V_42 * V_52 ;
F_32 ( & V_53 ) ;
if ( V_50 == V_54 ) {
V_51 = - V_55 ;
goto V_56;
}
switch ( V_50 ) {
case V_57 :
if ( ! F_33 ( V_58 ) ) {
V_51 = - V_59 ;
break;
}
V_51 |= F_34 ( F_25 , NULL ) ;
V_51 |= F_35 ( F_26 , NULL ) ;
break;
case V_60 :
V_51 |= F_36 ( F_25 , NULL ) ;
V_51 |= F_37 ( F_26 , NULL ) ;
F_38 () ;
F_39 (new_stat, temp, &hw_stats_list, list) {
if ( V_43 -> V_44 == NULL ) {
F_40 ( & V_43 -> V_61 ) ;
F_41 ( V_43 , V_62 ) ;
}
}
F_42 ( V_58 ) ;
break;
default:
V_51 = 1 ;
break;
}
if ( ! V_51 )
V_54 = V_50 ;
else
V_51 = - V_63 ;
V_56:
F_43 ( & V_53 ) ;
return V_51 ;
}
static int F_44 ( struct V_1 * V_9 ,
struct V_64 * V_65 )
{
return - V_66 ;
}
static int F_45 ( struct V_1 * V_9 ,
struct V_64 * V_65 )
{
switch ( V_65 -> V_67 -> V_68 ) {
case V_69 :
return F_31 ( V_57 ) ;
case V_70 :
return F_31 ( V_60 ) ;
}
return - V_66 ;
}
static int F_46 ( struct V_71 * V_72 ,
unsigned long V_73 , void * V_74 )
{
struct V_75 * V_44 = F_47 ( V_74 ) ;
struct V_42 * V_43 = NULL ;
struct V_42 * V_76 ;
switch ( V_73 ) {
case V_77 :
V_43 = F_48 ( sizeof( struct V_42 ) , V_13 ) ;
if ( ! V_43 )
goto V_31;
V_43 -> V_44 = V_44 ;
V_43 -> V_45 = V_18 ;
F_32 ( & V_53 ) ;
F_49 ( & V_43 -> V_61 , & V_78 ) ;
F_43 ( & V_53 ) ;
break;
case V_79 :
F_32 ( & V_53 ) ;
F_39 (new_stat, tmp, &hw_stats_list, list) {
if ( V_43 -> V_44 == V_44 ) {
V_43 -> V_44 = NULL ;
if ( V_54 == V_60 ) {
F_40 ( & V_43 -> V_61 ) ;
F_41 ( V_43 , V_62 ) ;
break;
}
}
}
F_43 ( & V_53 ) ;
break;
}
V_31:
return V_80 ;
}
static int T_2 F_50 ( void )
{
struct V_2 * V_3 ;
int V_81 , V_51 ;
F_51 ( L_1 ) ;
if ( sizeof( void * ) > 8 ) {
F_52 ( L_2 ) ;
return - V_82 ;
}
V_51 = F_53 ( & V_14 ,
V_83 , V_84 ) ;
if ( V_51 ) {
F_52 ( L_3 ) ;
return V_51 ;
}
F_54 ( V_14 . V_85 != V_86 ) ;
V_51 = F_55 ( & V_87 ) ;
if ( V_51 < 0 ) {
F_56 ( L_4 ) ;
goto V_88;
}
V_51 = 0 ;
F_57 (cpu) {
V_3 = & F_58 ( V_30 , V_81 ) ;
F_59 ( & V_3 -> V_23 , F_10 ) ;
F_60 ( & V_3 -> V_17 ) ;
V_3 -> V_17 . V_3 = ( unsigned long ) V_3 ;
V_3 -> V_17 . V_89 = F_13 ;
F_61 ( & V_3 -> V_20 ) ;
F_1 ( V_3 ) ;
}
goto V_31;
V_88:
F_62 ( & V_14 ) ;
V_31:
return V_51 ;
}
static void F_63 ( void )
{
struct V_2 * V_3 ;
int V_81 ;
F_64 ( F_65 ( & V_87 ) ) ;
F_57 (cpu) {
V_3 = & F_58 ( V_30 , V_81 ) ;
F_66 ( & V_3 -> V_17 ) ;
F_67 ( & V_3 -> V_23 ) ;
F_68 ( V_3 -> V_9 ) ;
}
F_64 ( F_62 ( & V_14 ) ) ;
}
