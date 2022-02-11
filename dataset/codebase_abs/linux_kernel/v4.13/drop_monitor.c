static struct V_1 * F_1 ( struct V_2 * V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_1 * V_9 ;
unsigned long V_10 ;
void * V_11 ;
V_4 = sizeof( struct V_5 ) ;
V_4 += V_12 * sizeof( struct V_13 ) ;
V_4 += sizeof( struct V_7 ) ;
V_9 = F_2 ( V_4 , V_14 ) ;
if ( ! V_9 )
goto V_15;
V_11 = F_3 ( V_9 , 0 , 0 , & V_16 ,
0 , V_17 ) ;
if ( ! V_11 ) {
F_4 ( V_9 ) ;
V_9 = NULL ;
goto V_15;
}
V_8 = F_5 ( V_9 , V_18 ,
sizeof( struct V_5 ) ) ;
if ( ! V_8 ) {
F_4 ( V_9 ) ;
V_9 = NULL ;
goto V_15;
}
V_6 = F_6 ( V_8 ) ;
memset ( V_6 , 0 , V_4 ) ;
goto V_19;
V_15:
F_7 ( & V_3 -> V_20 , V_21 + V_22 / 10 ) ;
V_19:
F_8 ( & V_3 -> V_23 , V_10 ) ;
F_9 ( V_3 -> V_9 , V_9 ) ;
F_10 ( & V_3 -> V_23 , V_10 ) ;
if ( V_9 ) {
struct V_24 * V_25 = (struct V_24 * ) V_9 -> V_3 ;
struct V_26 * V_27 = (struct V_26 * ) F_11 ( V_25 ) ;
F_12 ( V_9 , F_13 ( V_27 ) ) ;
}
return V_9 ;
}
static void F_14 ( struct V_28 * V_29 )
{
struct V_1 * V_9 ;
struct V_2 * V_3 ;
V_3 = F_15 ( V_29 , struct V_2 , V_30 ) ;
V_9 = F_1 ( V_3 ) ;
if ( V_9 )
F_16 ( & V_16 , V_9 , 0 ,
0 , V_14 ) ;
}
static void F_17 ( unsigned long V_31 )
{
struct V_2 * V_3 = (struct V_2 * ) V_31 ;
F_18 ( & V_3 -> V_30 ) ;
}
static void F_19 ( struct V_1 * V_9 , void * V_32 )
{
struct V_5 * V_6 ;
struct V_24 * V_25 ;
struct V_7 * V_8 ;
int V_33 ;
struct V_1 * V_34 ;
struct V_2 * V_3 ;
unsigned long V_10 ;
F_20 ( V_10 ) ;
V_3 = F_21 ( & V_35 ) ;
F_22 ( & V_3 -> V_23 ) ;
V_34 = V_3 -> V_9 ;
if ( ! V_34 )
goto V_19;
V_25 = (struct V_24 * ) V_34 -> V_3 ;
V_8 = F_13 ( F_11 ( V_25 ) ) ;
V_6 = F_6 ( V_8 ) ;
for ( V_33 = 0 ; V_33 < V_6 -> V_36 ; V_33 ++ ) {
if ( ! memcmp ( & V_32 , V_6 -> V_37 [ V_33 ] . V_38 , sizeof( void * ) ) ) {
V_6 -> V_37 [ V_33 ] . V_39 ++ ;
goto V_19;
}
}
if ( V_6 -> V_36 == V_12 )
goto V_19;
F_23 ( V_34 , sizeof( struct V_13 ) ) ;
V_8 -> V_40 += F_24 ( sizeof( struct V_13 ) ) ;
memcpy ( V_6 -> V_37 [ V_6 -> V_36 ] . V_38 , & V_32 , sizeof( void * ) ) ;
V_6 -> V_37 [ V_6 -> V_36 ] . V_39 = 1 ;
V_6 -> V_36 ++ ;
if ( ! F_25 ( & V_3 -> V_20 ) ) {
V_3 -> V_20 . V_41 = V_21 + V_42 * V_22 ;
F_26 ( & V_3 -> V_20 ) ;
}
V_19:
F_10 ( & V_3 -> V_23 , V_10 ) ;
}
static void F_27 ( void * V_43 , struct V_1 * V_9 , void * V_32 )
{
F_19 ( V_9 , V_32 ) ;
}
static void F_28 ( void * V_43 , struct V_44 * V_45 ,
int V_29 , int V_46 )
{
struct V_47 * V_48 ;
if ( ! V_45 -> V_49 )
return;
F_29 () ;
F_30 (new_stat, &hw_stats_list, list) {
if ( ( V_48 -> V_49 == V_45 -> V_49 ) &&
( F_31 ( V_21 , V_48 -> V_50 + V_51 ) ) &&
( V_45 -> V_49 -> V_52 . V_53 != V_48 -> V_54 ) ) {
F_19 ( NULL , NULL ) ;
V_48 -> V_54 = V_45 -> V_49 -> V_52 . V_53 ;
V_48 -> V_50 = V_21 ;
break;
}
}
F_32 () ;
}
static int F_33 ( int V_55 )
{
int V_56 = 0 ;
struct V_47 * V_48 = NULL ;
struct V_47 * V_57 ;
F_34 ( & V_58 ) ;
if ( V_55 == V_59 ) {
V_56 = - V_60 ;
goto V_61;
}
switch ( V_55 ) {
case V_62 :
if ( ! F_35 ( V_63 ) ) {
V_56 = - V_64 ;
break;
}
V_56 |= F_36 ( F_27 , NULL ) ;
V_56 |= F_37 ( F_28 , NULL ) ;
break;
case V_65 :
V_56 |= F_38 ( F_27 , NULL ) ;
V_56 |= F_39 ( F_28 , NULL ) ;
F_40 () ;
F_41 (new_stat, temp, &hw_stats_list, list) {
if ( V_48 -> V_49 == NULL ) {
F_42 ( & V_48 -> V_66 ) ;
F_43 ( V_48 , V_67 ) ;
}
}
F_44 ( V_63 ) ;
break;
default:
V_56 = 1 ;
break;
}
if ( ! V_56 )
V_59 = V_55 ;
else
V_56 = - V_68 ;
V_61:
F_45 ( & V_58 ) ;
return V_56 ;
}
static int F_46 ( struct V_1 * V_9 ,
struct V_69 * V_70 )
{
return - V_71 ;
}
static int F_47 ( struct V_1 * V_9 ,
struct V_69 * V_70 )
{
switch ( V_70 -> V_72 -> V_73 ) {
case V_74 :
return F_33 ( V_62 ) ;
case V_75 :
return F_33 ( V_65 ) ;
}
return - V_71 ;
}
static int F_48 ( struct V_76 * V_77 ,
unsigned long V_78 , void * V_79 )
{
struct V_80 * V_49 = F_49 ( V_79 ) ;
struct V_47 * V_48 = NULL ;
struct V_47 * V_81 ;
switch ( V_78 ) {
case V_82 :
V_48 = F_50 ( sizeof( struct V_47 ) , V_14 ) ;
if ( ! V_48 )
goto V_19;
V_48 -> V_49 = V_49 ;
V_48 -> V_50 = V_21 ;
F_34 ( & V_58 ) ;
F_51 ( & V_48 -> V_66 , & V_83 ) ;
F_45 ( & V_58 ) ;
break;
case V_84 :
F_34 ( & V_58 ) ;
F_41 (new_stat, tmp, &hw_stats_list, list) {
if ( V_48 -> V_49 == V_49 ) {
V_48 -> V_49 = NULL ;
if ( V_59 == V_65 ) {
F_42 ( & V_48 -> V_66 ) ;
F_43 ( V_48 , V_67 ) ;
break;
}
}
}
F_45 ( & V_58 ) ;
break;
}
V_19:
return V_85 ;
}
static int T_2 F_52 ( void )
{
struct V_2 * V_3 ;
int V_86 , V_56 ;
F_53 ( L_1 ) ;
if ( sizeof( void * ) > 8 ) {
F_54 ( L_2 ) ;
return - V_87 ;
}
V_56 = F_55 ( & V_16 ) ;
if ( V_56 ) {
F_54 ( L_3 ) ;
return V_56 ;
}
F_56 ( V_16 . V_88 != V_89 ) ;
V_56 = F_57 ( & V_90 ) ;
if ( V_56 < 0 ) {
F_58 ( L_4 ) ;
goto V_91;
}
V_56 = 0 ;
F_59 (cpu) {
V_3 = & F_60 ( V_35 , V_86 ) ;
F_61 ( & V_3 -> V_30 , F_14 ) ;
F_62 ( & V_3 -> V_20 , F_17 ,
( unsigned long ) V_3 ) ;
F_63 ( & V_3 -> V_23 ) ;
F_1 ( V_3 ) ;
}
goto V_19;
V_91:
F_64 ( & V_16 ) ;
V_19:
return V_56 ;
}
static void F_65 ( void )
{
struct V_2 * V_3 ;
int V_86 ;
F_66 ( F_67 ( & V_90 ) ) ;
F_59 (cpu) {
V_3 = & F_60 ( V_35 , V_86 ) ;
F_68 ( & V_3 -> V_20 ) ;
F_69 ( & V_3 -> V_30 ) ;
F_70 ( V_3 -> V_9 ) ;
}
F_66 ( F_64 ( & V_16 ) ) ;
}
