static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_8 * V_10 = F_2 ( V_2 -> V_9 , 1 ) ;
V_3 = sizeof( struct V_4 ) ;
V_3 += V_11 * sizeof( struct V_12 ) ;
V_3 += sizeof( struct V_6 ) ;
V_9 = F_3 ( V_3 , V_13 ) ;
if ( V_9 ) {
F_4 ( V_9 , 0 , 0 , & V_14 ,
0 , V_15 ) ;
V_7 = F_5 ( V_9 , V_16 ,
sizeof( struct V_4 ) ) ;
V_5 = F_6 ( V_7 ) ;
memset ( V_5 , 0 , V_3 ) ;
} else
F_7 ( V_2 -> V_17 , & V_2 -> V_18 ) ;
if ( V_9 != V_10 ) {
F_8 ( V_2 -> V_9 , V_9 ) ;
F_9 () ;
F_10 ( & V_2 -> V_19 , V_11 ) ;
}
}
static void F_11 ( struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 = & F_12 ( V_22 ) ;
F_13 ( V_2 -> V_17 != F_14 () ) ;
V_9 = F_2 ( V_2 -> V_9 , 1 ) ;
F_1 ( V_2 ) ;
if ( V_9 )
F_15 ( V_9 , 0 , V_23 , V_13 ) ;
F_16 ( V_22 ) ;
}
static void F_17 ( unsigned long V_21 )
{
struct V_1 * V_2 = & F_12 ( V_22 ) ;
F_7 ( F_14 () , & V_2 -> V_18 ) ;
F_16 ( V_22 ) ;
}
static void F_18 ( struct V_8 * V_9 , void * V_24 )
{
struct V_4 * V_5 ;
struct V_25 * V_26 ;
struct V_6 * V_7 ;
int V_27 ;
struct V_8 * V_28 ;
struct V_1 * V_2 = & F_12 ( V_22 ) ;
F_19 () ;
V_28 = F_20 ( V_2 -> V_9 ) ;
if ( ! V_28 )
goto V_29;
if ( ! F_21 ( & V_2 -> V_19 , - 1 , 0 ) ) {
goto V_29;
}
V_26 = (struct V_25 * ) V_28 -> V_2 ;
V_7 = F_22 ( F_23 ( V_26 ) ) ;
V_5 = F_6 ( V_7 ) ;
for ( V_27 = 0 ; V_27 < V_5 -> V_30 ; V_27 ++ ) {
if ( ! memcmp ( & V_24 , V_5 -> V_31 [ V_27 ] . V_32 , sizeof( void * ) ) ) {
V_5 -> V_31 [ V_27 ] . V_33 ++ ;
F_24 ( & V_2 -> V_19 ) ;
goto V_29;
}
}
F_25 ( V_28 , sizeof( struct V_12 ) ) ;
V_7 -> V_34 += F_26 ( sizeof( struct V_12 ) ) ;
memcpy ( V_5 -> V_31 [ V_5 -> V_30 ] . V_32 , & V_24 , sizeof( void * ) ) ;
V_5 -> V_31 [ V_5 -> V_30 ] . V_33 = 1 ;
V_5 -> V_30 ++ ;
if ( ! F_27 ( & V_2 -> V_35 ) ) {
V_2 -> V_35 . V_36 = V_37 + V_38 * V_39 ;
F_28 ( & V_2 -> V_35 , F_14 () ) ;
}
V_29:
F_29 () ;
F_16 ( V_22 ) ;
return;
}
static void F_30 ( void * V_40 , struct V_8 * V_9 , void * V_24 )
{
F_18 ( V_9 , V_24 ) ;
}
static void F_31 ( void * V_40 , struct V_41 * V_42 )
{
struct V_43 * V_44 ;
if ( ! V_42 -> V_45 )
return;
F_19 () ;
F_32 (new_stat, &hw_stats_list, list) {
if ( ( V_44 -> V_45 == V_42 -> V_45 ) &&
( F_33 ( V_37 , V_44 -> V_46 + V_47 ) ) &&
( V_42 -> V_45 -> V_48 . V_49 != V_44 -> V_50 ) ) {
F_18 ( NULL , NULL ) ;
V_44 -> V_50 = V_42 -> V_45 -> V_48 . V_49 ;
V_44 -> V_46 = V_37 ;
break;
}
}
F_29 () ;
}
static int F_34 ( int V_51 )
{
int V_52 = 0 ;
struct V_43 * V_44 = NULL ;
struct V_43 * V_53 ;
F_35 ( & V_54 ) ;
if ( V_51 == V_55 ) {
V_52 = - V_56 ;
goto V_57;
}
switch ( V_51 ) {
case V_58 :
V_52 |= F_36 ( F_30 , NULL ) ;
V_52 |= F_37 ( F_31 , NULL ) ;
break;
case V_59 :
V_52 |= F_38 ( F_30 , NULL ) ;
V_52 |= F_39 ( F_31 , NULL ) ;
F_40 () ;
F_41 (new_stat, temp, &hw_stats_list, list) {
if ( V_44 -> V_45 == NULL ) {
F_42 ( & V_44 -> V_60 ) ;
F_43 ( V_44 , V_61 ) ;
}
}
break;
default:
V_52 = 1 ;
break;
}
if ( ! V_52 )
V_55 = V_51 ;
else
V_52 = - V_62 ;
V_57:
F_44 ( & V_54 ) ;
return V_52 ;
}
static int F_45 ( struct V_8 * V_9 ,
struct V_63 * V_64 )
{
return - V_65 ;
}
static int F_46 ( struct V_8 * V_9 ,
struct V_63 * V_64 )
{
switch ( V_64 -> V_66 -> V_67 ) {
case V_68 :
return F_34 ( V_58 ) ;
break;
case V_69 :
return F_34 ( V_59 ) ;
break;
}
return - V_65 ;
}
static int F_47 ( struct V_70 * V_71 ,
unsigned long V_72 , void * V_73 )
{
struct V_74 * V_45 = V_73 ;
struct V_43 * V_44 = NULL ;
struct V_43 * V_75 ;
switch ( V_72 ) {
case V_76 :
V_44 = F_48 ( sizeof( struct V_43 ) , V_13 ) ;
if ( ! V_44 )
goto V_29;
V_44 -> V_45 = V_45 ;
V_44 -> V_46 = V_37 ;
F_35 ( & V_54 ) ;
F_49 ( & V_44 -> V_60 , & V_77 ) ;
F_44 ( & V_54 ) ;
break;
case V_78 :
F_35 ( & V_54 ) ;
F_41 (new_stat, tmp, &hw_stats_list, list) {
if ( V_44 -> V_45 == V_45 ) {
V_44 -> V_45 = NULL ;
if ( V_55 == V_59 ) {
F_42 ( & V_44 -> V_60 ) ;
F_43 ( V_44 , V_61 ) ;
break;
}
}
}
F_44 ( & V_54 ) ;
break;
}
V_29:
return V_79 ;
}
static int T_2 F_50 ( void )
{
struct V_1 * V_2 ;
int V_17 , V_52 ;
F_51 ( V_80 L_1 ) ;
if ( sizeof( void * ) > 8 ) {
F_51 ( V_81 L_2 ) ;
return - V_82 ;
}
V_52 = F_52 ( & V_14 ,
V_83 ,
F_53 ( V_83 ) ) ;
if ( V_52 ) {
F_51 ( V_81 L_3 ) ;
return V_52 ;
}
V_52 = F_54 ( & V_84 ) ;
if ( V_52 < 0 ) {
F_51 ( V_85 L_4 ) ;
goto V_86;
}
V_52 = 0 ;
F_55 (cpu) {
V_2 = & F_56 ( V_22 , V_17 ) ;
V_2 -> V_17 = V_17 ;
F_57 ( & V_2 -> V_18 , F_11 ) ;
F_58 ( & V_2 -> V_35 ) ;
V_2 -> V_35 . V_2 = V_17 ;
V_2 -> V_35 . V_87 = F_17 ;
F_1 ( V_2 ) ;
}
goto V_29;
V_86:
F_59 ( & V_14 ) ;
V_29:
return V_52 ;
}
