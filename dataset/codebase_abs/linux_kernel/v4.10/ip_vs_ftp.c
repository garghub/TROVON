static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 |= V_6 ;
return 0 ;
}
static int
F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return 0 ;
}
static int F_3 ( char * V_7 , char * V_8 ,
const char * V_9 , T_1 V_10 ,
char V_11 , char V_12 ,
T_2 * V_13 , T_3 * V_14 ,
char * * V_15 , char * * V_16 )
{
char * V_17 , V_18 ;
unsigned char V_19 [ 6 ] ;
int V_20 = 0 ;
if ( V_8 - V_7 < V_10 ) {
if ( strncasecmp ( V_7 , V_9 , V_8 - V_7 ) == 0 )
return - 1 ;
else
return 0 ;
}
if ( strncasecmp ( V_7 , V_9 , V_10 ) != 0 ) {
return 0 ;
}
V_17 = V_7 + V_10 ;
if ( V_11 ) {
int V_21 = 0 ;
for (; ; V_17 ++ ) {
if ( V_17 == V_8 )
return - 1 ;
if ( ! V_21 ) {
if ( * V_17 == V_11 )
V_21 = 1 ;
} else if ( * V_17 != V_11 ) {
break;
}
}
}
for ( V_7 = V_17 ; ; V_7 ++ ) {
if ( V_7 == V_8 )
return - 1 ;
if ( * V_7 == V_12 )
break;
}
* V_16 = V_7 ;
memset ( V_19 , 0 , sizeof( V_19 ) ) ;
for ( V_7 = V_17 ; ; V_7 ++ ) {
V_18 = * V_7 ;
if ( V_18 == V_12 )
break;
if ( V_18 >= '0' && V_18 <= '9' ) {
V_19 [ V_20 ] = V_19 [ V_20 ] * 10 + V_18 - '0' ;
} else if ( V_18 == ',' && V_20 < 5 ) {
V_20 ++ ;
} else {
return - 1 ;
}
}
if ( V_20 != 5 )
return - 1 ;
* V_15 = V_17 ;
* V_13 = F_4 ( ( T_2 * ) V_19 ) ;
* V_14 = F_4 ( ( T_3 * ) ( V_19 + 4 ) ) ;
return 1 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_22 * V_23 , int * V_24 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
char * V_7 , * V_8 ;
char * V_15 , * V_16 ;
union V_29 V_30 ;
T_3 V_14 ;
struct V_3 * V_31 ;
char V_32 [ 24 ] ;
unsigned int V_33 ;
int V_34 = 0 ;
enum V_35 V_36 ;
struct V_37 * V_38 ;
* V_24 = 0 ;
#ifdef F_6
if ( V_4 -> V_39 == V_40 )
return 1 ;
#endif
if ( V_4 -> V_41 != V_42 )
return 1 ;
if ( ! F_7 ( V_23 , V_23 -> V_43 ) )
return 0 ;
if ( V_4 -> V_44 == & V_45 ) {
V_26 = F_8 ( V_23 ) ;
V_28 = (struct V_27 * ) & ( ( ( char * ) V_26 ) [ V_26 -> V_46 * 4 ] ) ;
V_7 = ( char * ) V_28 + ( V_28 -> V_47 << 2 ) ;
V_8 = F_9 ( V_23 ) ;
if ( F_3 ( V_7 , V_8 ,
V_48 ,
sizeof( V_48 ) - 1 ,
'(' , ')' ,
& V_30 . V_49 , & V_14 ,
& V_15 , & V_16 ) != 1 )
return 1 ;
F_10 ( 7 , L_1 ,
& V_30 . V_49 , F_11 ( V_14 ) , & V_4 -> V_50 . V_49 , 0 ) ;
{
struct V_51 V_19 ;
F_12 ( V_4 -> V_52 , V_53 ,
V_26 -> V_54 , & V_30 , V_14 ,
& V_4 -> V_50 , 0 , & V_19 ) ;
V_31 = F_13 ( & V_19 ) ;
}
if ( ! V_31 ) {
struct V_51 V_19 ;
F_12 ( V_4 -> V_52 ,
V_53 , V_55 , & V_4 -> V_50 ,
0 , & V_4 -> V_56 , V_14 , & V_19 ) ;
V_31 = F_14 ( & V_19 , V_53 , & V_30 , V_14 ,
V_57 |
V_6 ,
V_4 -> V_58 , V_23 -> V_59 ) ;
if ( ! V_31 )
return 0 ;
F_15 ( V_31 , V_4 ) ;
}
V_30 . V_49 = V_31 -> V_56 . V_49 ;
V_14 = V_31 -> V_60 ;
snprintf ( V_32 , sizeof( V_32 ) , L_2 ,
( ( unsigned char * ) & V_30 . V_49 ) [ 0 ] ,
( ( unsigned char * ) & V_30 . V_49 ) [ 1 ] ,
( ( unsigned char * ) & V_30 . V_49 ) [ 2 ] ,
( ( unsigned char * ) & V_30 . V_49 ) [ 3 ] ,
F_11 ( V_14 ) >> 8 ,
F_11 ( V_14 ) & 0xFF ) ;
V_33 = strlen ( V_32 ) ;
V_38 = F_16 ( V_23 , & V_36 ) ;
if ( V_38 && ! F_17 ( V_38 ) && F_18 ( V_38 ) ) {
F_19 () ;
V_34 = F_20 ( V_23 , V_38 , V_36 ,
V_26 -> V_46 * 4 ,
V_15 - V_7 , V_16 - V_15 ,
V_32 , V_33 ) ;
F_21 () ;
if ( V_34 ) {
F_22 ( V_23 , V_38 , V_31 ,
V_55 , 0 , 0 ) ;
if ( V_23 -> V_61 == V_62 )
V_23 -> V_61 = V_63 ;
V_34 = 1 ;
}
}
V_4 -> V_44 = NULL ;
F_23 ( V_31 ) ;
F_24 ( V_31 ) ;
return V_34 ;
}
return 1 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_22 * V_23 , int * V_24 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
char * V_7 , * V_64 , * V_8 ;
char * V_15 , * V_16 ;
union V_29 V_65 ;
T_3 V_14 ;
struct V_3 * V_31 ;
* V_24 = 0 ;
#ifdef F_6
if ( V_4 -> V_39 == V_40 )
return 1 ;
#endif
if ( V_4 -> V_41 != V_42 )
return 1 ;
if ( ! F_7 ( V_23 , V_23 -> V_43 ) )
return 0 ;
V_26 = F_8 ( V_23 ) ;
V_28 = (struct V_27 * ) & ( ( ( char * ) V_26 ) [ V_26 -> V_46 * 4 ] ) ;
V_7 = V_64 = ( char * ) V_28 + ( V_28 -> V_47 << 2 ) ;
V_8 = F_9 ( V_23 ) ;
while ( V_7 <= V_8 - 6 ) {
if ( strncasecmp ( V_7 , L_3 , 6 ) == 0 ) {
F_10 ( 7 , L_4 ,
V_7 - V_64 ,
V_8 - V_64 ) ;
V_4 -> V_44 = & V_45 ;
return 1 ;
}
V_7 ++ ;
}
if ( F_3 ( V_64 , V_8 ,
V_66 , sizeof( V_66 ) - 1 ,
' ' , '\r' , & V_65 . V_49 , & V_14 ,
& V_15 , & V_16 ) != 1 )
return 1 ;
F_10 ( 7 , L_5 , & V_65 . V_49 , F_11 ( V_14 ) ) ;
V_4 -> V_44 = NULL ;
F_10 ( 7 , L_6 ,
F_26 ( V_26 -> V_54 ) ,
& V_65 . V_49 , F_11 ( V_14 ) , & V_4 -> V_56 . V_49 , 0 ) ;
{
struct V_51 V_19 ;
F_12 ( V_4 -> V_52 , V_53 ,
V_26 -> V_54 , & V_65 , V_14 , & V_4 -> V_56 ,
F_27 ( F_11 ( V_4 -> V_60 ) - 1 ) , & V_19 ) ;
V_31 = F_28 ( & V_19 ) ;
if ( ! V_31 ) {
V_31 = F_14 ( & V_19 , V_53 , & V_4 -> V_67 ,
F_27 ( F_11 ( V_4 -> V_68 ) - 1 ) ,
V_6 , V_4 -> V_58 ,
V_23 -> V_59 ) ;
if ( ! V_31 )
return 0 ;
F_15 ( V_31 , V_4 ) ;
}
}
F_23 ( V_31 ) ;
F_24 ( V_31 ) ;
return 1 ;
}
static int T_4 F_29 ( struct V_69 * V_69 )
{
int V_20 , V_34 ;
struct V_1 * V_2 ;
struct V_70 * V_52 = F_30 ( V_69 ) ;
if ( ! V_52 )
return - V_71 ;
V_2 = F_31 ( V_52 , & V_72 ) ;
if ( F_32 ( V_2 ) )
return F_33 ( V_2 ) ;
for ( V_20 = 0 ; V_20 < V_73 ; V_20 ++ ) {
if ( ! V_74 [ V_20 ] )
continue;
V_34 = F_34 ( V_52 , V_2 , V_2 -> V_54 , V_74 [ V_20 ] ) ;
if ( V_34 )
goto V_75;
F_35 ( L_7 ,
V_2 -> V_76 , V_20 , V_74 [ V_20 ] ) ;
}
return 0 ;
V_75:
F_36 ( V_52 , & V_72 ) ;
return V_34 ;
}
static void F_37 ( struct V_69 * V_69 )
{
struct V_70 * V_52 = F_30 ( V_69 ) ;
if ( ! V_52 )
return;
F_36 ( V_52 , & V_72 ) ;
}
static int T_5 F_38 ( void )
{
int V_77 ;
V_77 = F_39 ( & V_78 ) ;
return V_77 ;
}
static void T_6 F_40 ( void )
{
F_41 ( & V_78 ) ;
}
