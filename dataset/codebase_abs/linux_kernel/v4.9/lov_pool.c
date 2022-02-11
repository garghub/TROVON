static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , L_1 , V_2 ) ;
F_3 ( & V_2 -> V_4 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_3 , L_1 , V_2 ) ;
if ( F_5 ( & V_2 -> V_4 ) ) {
F_6 ( F_7 ( & V_2 -> V_5 ) ) ;
F_6 ( F_8 ( & V_2 -> V_6 ) ) ;
F_6 ( ! V_2 -> V_7 ) ;
F_9 ( & V_2 -> V_8 ) ;
F_10 ( V_2 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
F_2 ( V_3 , L_1 , V_2 ) ;
F_6 ( F_12 ( & V_2 -> V_4 ) > 1 ) ;
F_13 ( & V_2 -> V_4 ) ;
}
static T_1 F_14 ( struct V_9 * V_10 , const void * V_11 , unsigned V_12 )
{
int V_13 ;
T_1 V_14 ;
char * V_15 ;
V_14 = 0 ;
V_15 = ( char * ) V_11 ;
for ( V_13 = 0 ; V_13 < V_16 ; V_13 ++ ) {
if ( V_15 [ V_13 ] == '\0' )
break;
V_14 = ( V_14 << 4 ) ^ ( V_14 >> 28 ) ^ V_15 [ V_13 ] ;
}
return ( V_14 % V_12 ) ;
}
static void * F_15 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_18 , struct V_1 , V_5 ) ;
return V_2 -> V_19 ;
}
static int F_17 ( const void * V_11 , struct V_17 * V_20 )
{
char * V_19 ;
struct V_1 * V_2 ;
V_19 = ( char * ) V_11 ;
V_2 = F_16 ( V_20 , struct V_1 , V_5 ) ;
return ! strncmp ( V_19 , V_2 -> V_19 , V_16 ) ;
}
static void * F_18 ( struct V_17 * V_18 )
{
return F_16 ( V_18 , struct V_1 , V_5 ) ;
}
static void F_19 ( struct V_9 * V_21 , struct V_17 * V_18 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_18 , struct V_1 , V_5 ) ;
F_1 ( V_2 ) ;
}
static void F_20 ( struct V_9 * V_21 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_18 , struct V_1 , V_5 ) ;
F_11 ( V_2 ) ;
}
static void * F_21 ( struct V_22 * V_23 , void * V_24 , T_2 * V_25 )
{
struct V_26 * V_27 = (struct V_26 * ) V_23 -> V_28 ;
int V_29 ;
F_22 ( V_27 -> V_30 == V_31 , L_2 , V_27 -> V_30 ) ;
if ( * V_25 >= F_23 ( V_27 -> V_2 ) )
return NULL ;
V_29 = V_27 -> V_32 ;
F_24 ( & F_25 ( V_27 -> V_2 ) ) ;
V_27 -> V_32 ++ ;
if ( V_27 -> V_32 == F_23 ( V_27 -> V_2 ) ) {
V_27 -> V_32 = V_29 ;
F_26 ( & F_25 ( V_27 -> V_2 ) ) ;
return NULL ;
}
F_26 ( & F_25 ( V_27 -> V_2 ) ) ;
( * V_25 ) ++ ;
return V_27 ;
}
static void * F_27 ( struct V_22 * V_23 , T_2 * V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_23 -> V_28 ;
struct V_26 * V_27 ;
F_1 ( V_2 ) ;
if ( ( F_23 ( V_2 ) == 0 ) ||
( * V_25 >= F_23 ( V_2 ) ) ) {
F_4 ( V_2 ) ;
return NULL ;
}
V_27 = F_28 ( sizeof( * V_27 ) , V_33 ) ;
if ( ! V_27 )
return F_29 ( - V_34 ) ;
V_27 -> V_30 = V_31 ;
V_27 -> V_2 = V_2 ;
V_27 -> V_32 = 0 ;
V_23 -> V_28 = V_27 ;
if ( * V_25 > 0 ) {
T_2 V_13 ;
void * V_35 ;
V_13 = 0 ;
do {
V_35 = F_21 ( V_23 , & V_27 , & V_13 ) ;
} while ( ( V_13 < * V_25 ) && V_35 );
return V_35 ;
}
return V_27 ;
}
static void F_30 ( struct V_22 * V_23 , void * V_24 )
{
struct V_26 * V_27 = (struct V_26 * ) V_23 -> V_28 ;
if ( ( V_27 ) && ( V_27 -> V_30 == V_31 ) ) {
V_23 -> V_28 = V_27 -> V_2 ;
F_4 ( V_27 -> V_2 ) ;
F_10 ( V_27 ) ;
}
}
static int F_31 ( struct V_22 * V_23 , void * V_24 )
{
struct V_26 * V_27 = (struct V_26 * ) V_24 ;
struct V_36 * V_37 ;
F_22 ( V_27 -> V_30 == V_31 , L_2 , V_27 -> V_30 ) ;
F_6 ( V_27 -> V_2 ) ;
F_6 ( V_27 -> V_32 <= F_23 ( V_27 -> V_2 ) ) ;
F_24 ( & F_25 ( V_27 -> V_2 ) ) ;
V_37 = F_32 ( V_27 -> V_2 , V_27 -> V_32 ) ;
F_26 ( & F_25 ( V_27 -> V_2 ) ) ;
if ( V_37 )
F_33 ( V_23 , L_3 , F_34 ( & V_37 -> V_38 ) ) ;
return 0 ;
}
static int F_35 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
int V_41 ;
V_41 = F_36 ( V_40 , & V_42 ) ;
if ( ! V_41 ) {
struct V_22 * V_23 = V_40 -> V_43 ;
V_23 -> V_28 = V_39 -> V_44 ;
}
return V_41 ;
}
int F_37 ( struct V_45 * V_46 , unsigned int V_47 )
{
if ( V_47 == 0 )
V_47 = V_48 ;
V_46 -> V_49 = NULL ;
V_46 -> V_50 = 0 ;
F_38 ( & V_46 -> V_51 ) ;
V_46 -> V_52 = V_47 ;
V_46 -> V_49 = F_39 ( V_46 -> V_52 , sizeof( V_46 -> V_49 [ 0 ] ) , V_33 ) ;
if ( ! V_46 -> V_49 ) {
V_46 -> V_52 = 0 ;
return - V_34 ;
}
return 0 ;
}
int F_40 ( struct V_45 * V_46 , unsigned int V_53 )
{
T_1 * V_54 ;
int V_55 ;
F_6 ( V_53 != 0 ) ;
if ( V_46 -> V_50 < V_46 -> V_52 )
return 0 ;
V_55 = F_41 ( V_53 , 2 * V_46 -> V_52 ) ;
V_54 = F_39 ( V_55 , sizeof( V_46 -> V_49 [ 0 ] ) , V_33 ) ;
if ( ! V_54 )
return - V_34 ;
memcpy ( V_54 , V_46 -> V_49 , V_46 -> V_52 * sizeof( V_46 -> V_49 [ 0 ] ) ) ;
F_10 ( V_46 -> V_49 ) ;
V_46 -> V_49 = V_54 ;
V_46 -> V_52 = V_55 ;
return 0 ;
}
int F_42 ( struct V_45 * V_46 , T_1 V_32 , unsigned int V_53 )
{
int V_41 = 0 , V_13 ;
F_43 ( & V_46 -> V_51 ) ;
V_41 = F_40 ( V_46 , V_53 ) ;
if ( V_41 )
goto V_56;
for ( V_13 = 0 ; V_13 < V_46 -> V_50 ; V_13 ++ ) {
if ( V_46 -> V_49 [ V_13 ] == V_32 ) {
V_41 = - V_57 ;
goto V_56;
}
}
V_46 -> V_49 [ V_46 -> V_50 ] = V_32 ;
V_46 -> V_50 ++ ;
V_56:
F_44 ( & V_46 -> V_51 ) ;
return V_41 ;
}
int F_45 ( struct V_45 * V_46 , T_1 V_32 )
{
int V_13 ;
F_43 ( & V_46 -> V_51 ) ;
for ( V_13 = 0 ; V_13 < V_46 -> V_50 ; V_13 ++ ) {
if ( V_46 -> V_49 [ V_13 ] == V_32 ) {
memmove ( & V_46 -> V_49 [ V_13 ] , & V_46 -> V_49 [ V_13 + 1 ] ,
( V_46 -> V_50 - V_13 - 1 ) * sizeof( V_46 -> V_49 [ 0 ] ) ) ;
V_46 -> V_50 -- ;
F_44 ( & V_46 -> V_51 ) ;
return 0 ;
}
}
F_44 ( & V_46 -> V_51 ) ;
return - V_58 ;
}
int F_9 ( struct V_45 * V_46 )
{
if ( V_46 -> V_52 == 0 )
return 0 ;
F_43 ( & V_46 -> V_51 ) ;
F_10 ( V_46 -> V_49 ) ;
V_46 -> V_49 = NULL ;
V_46 -> V_50 = 0 ;
V_46 -> V_52 = 0 ;
F_44 ( & V_46 -> V_51 ) ;
return 0 ;
}
int F_46 ( struct V_59 * V_60 , char * V_15 )
{
struct V_61 * V_62 ;
struct V_1 * V_63 ;
int V_41 ;
V_62 = & V_60 -> V_64 . V_62 ;
if ( strlen ( V_15 ) > V_16 )
return - V_65 ;
V_63 = F_28 ( sizeof( * V_63 ) , V_33 ) ;
if ( ! V_63 )
return - V_34 ;
F_47 ( V_63 -> V_19 , V_15 , sizeof( V_63 -> V_19 ) ) ;
V_63 -> V_66 = V_60 ;
F_48 ( & V_63 -> V_4 , 1 ) ;
V_41 = F_37 ( & V_63 -> V_8 , 0 ) ;
if ( V_41 )
goto V_67;
F_49 ( & V_63 -> V_5 ) ;
F_1 ( V_63 ) ;
V_63 -> V_7 = F_50 (
V_62 -> V_68 ,
V_15 , V_63 ,
& V_69 ) ;
if ( F_51 ( V_63 -> V_7 ) ) {
F_52 ( L_4 V_70 L_5 ,
V_15 ) ;
V_63 -> V_7 = NULL ;
F_4 ( V_63 ) ;
}
F_2 ( V_3 , L_6 ,
V_63 , V_63 -> V_7 ) ;
F_53 ( & V_60 -> V_71 ) ;
F_54 ( & V_63 -> V_6 , & V_62 -> V_72 ) ;
V_62 -> V_73 ++ ;
F_55 ( & V_60 -> V_71 ) ;
V_41 = F_56 ( V_62 -> V_74 , V_15 ,
& V_63 -> V_5 ) ;
if ( V_41 ) {
V_41 = - V_57 ;
goto V_67;
}
F_2 ( V_75 , V_70 L_7 ,
V_15 , V_62 -> V_73 ) ;
return 0 ;
V_67:
F_53 ( & V_60 -> V_71 ) ;
F_57 ( & V_63 -> V_6 ) ;
V_62 -> V_73 -- ;
F_55 ( & V_60 -> V_71 ) ;
F_58 ( & V_63 -> V_7 ) ;
F_9 ( & V_63 -> V_8 ) ;
F_10 ( V_63 ) ;
return V_41 ;
}
int F_59 ( struct V_59 * V_60 , char * V_15 )
{
struct V_61 * V_62 ;
struct V_1 * V_2 ;
V_62 = & V_60 -> V_64 . V_62 ;
V_2 = F_60 ( V_62 -> V_74 , V_15 ) ;
if ( ! V_2 )
return - V_76 ;
if ( ! F_51 ( V_2 -> V_7 ) ) {
F_2 ( V_3 , L_8 , V_2 -> V_7 ) ;
F_58 ( & V_2 -> V_7 ) ;
F_4 ( V_2 ) ;
}
F_53 ( & V_60 -> V_71 ) ;
F_57 ( & V_2 -> V_6 ) ;
V_62 -> V_73 -- ;
F_55 ( & V_60 -> V_71 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
int F_61 ( struct V_59 * V_60 , char * V_15 , char * V_77 )
{
struct V_78 V_79 ;
struct V_61 * V_62 ;
struct V_1 * V_2 ;
unsigned int V_80 ;
int V_41 ;
V_62 = & V_60 -> V_64 . V_62 ;
V_2 = F_62 ( V_62 -> V_74 , V_15 ) ;
if ( ! V_2 )
return - V_76 ;
F_63 ( & V_79 , V_77 ) ;
F_64 ( V_60 ) ;
for ( V_80 = 0 ; V_80 < V_62 -> V_81 . V_82 ; V_80 ++ ) {
if ( ! V_62 -> V_83 [ V_80 ] )
continue;
if ( F_65 ( & V_79 ,
& V_62 -> V_83 [ V_80 ] -> V_38 ) )
break;
}
if ( V_80 == V_62 -> V_81 . V_82 ) {
V_41 = - V_58 ;
goto V_56;
}
V_41 = F_42 ( & V_2 -> V_8 , V_80 , V_62 -> V_84 ) ;
if ( V_41 )
goto V_56;
F_2 ( V_75 , L_9 V_70 L_10 ,
V_77 , V_15 , F_23 ( V_2 ) ) ;
V_56:
F_66 ( V_60 ) ;
F_4 ( V_2 ) ;
return V_41 ;
}
int F_67 ( struct V_59 * V_60 , char * V_15 , char * V_77 )
{
struct V_78 V_79 ;
struct V_61 * V_62 ;
struct V_1 * V_2 ;
unsigned int V_80 ;
int V_41 = 0 ;
V_62 = & V_60 -> V_64 . V_62 ;
V_2 = F_62 ( V_62 -> V_74 , V_15 ) ;
if ( ! V_2 )
return - V_76 ;
F_63 ( & V_79 , V_77 ) ;
F_64 ( V_60 ) ;
for ( V_80 = 0 ; V_80 < V_62 -> V_81 . V_82 ; V_80 ++ ) {
if ( ! V_62 -> V_83 [ V_80 ] )
continue;
if ( F_65 ( & V_79 ,
& V_62 -> V_83 [ V_80 ] -> V_38 ) )
break;
}
if ( V_80 == V_62 -> V_81 . V_82 ) {
V_41 = - V_58 ;
goto V_56;
}
F_45 ( & V_2 -> V_8 , V_80 ) ;
F_2 ( V_75 , L_11 V_70 L_5 , V_77 ,
V_15 ) ;
V_56:
F_66 ( V_60 ) ;
F_4 ( V_2 ) ;
return V_41 ;
}
